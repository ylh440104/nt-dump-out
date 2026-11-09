
===== __report_gsfailure @ 140001010 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __cpu_features_init @ 140001030 =====

/* WARNING: Removing unreachable block (ram,0x00014000109a) */
/* WARNING: Removing unreachable block (ram,0x000140001049) */
/* WARNING: Removing unreachable block (ram,0x00014000103a) */

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



===== CrashVpciEstablishCommunication @ 1400010f8 =====

ulonglong CrashVpciEstablishCommunication(longlong param_1)

{
  ulonglong uVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint local_res10 [2];
  undefined4 local_res18;
  undefined4 local_res1c;
  ulonglong local_res20;
  
  local_res20 = 0;
  DbgPrintEx(0x98,0,"vpci [%s:%u] Early Restore: Establish Communication\n",
             "CrashVpciEstablishCommunication",0x1b8);
  uVar2 = 0;
  puVar3 = &DAT_14000d6d8;
  do {
    local_res1c = *puVar3;
    local_res18 = 0x42490013;
    local_res10[0] = 8;
    DbgPrintEx(0x98,0,"vpci [%s:%u] (crash) Send VpciMsgQueryProtocolVersion\n",
               "CrashVpciEstablishCommunication",0x1c1);
    uVar1 = CrashVpciSendPacketSync
                      (param_1,(longlong)&local_res18,8,(longlong)&local_res20,local_res10);
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    if (local_res10[0] < 8) {
      return 0xc0000001;
    }
    if ((int)local_res20 != -0x3fffffa7) {
      return local_res20 & 0xffffffff;
    }
    uVar2 = uVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (uVar2 < 6);
  return local_res20 & 0xffffffff;
}



===== CrashVpciFdoD0Entry @ 1400011d8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong CrashVpciFdoD0Entry(longlong param_1)

{
  code *pcVar1;
  ulonglong uVar2;
  undefined1 *puVar3;
  undefined1 auStackY_98 [8];
  undefined1 auStackY_90 [24];
  uint local_68 [2];
  undefined8 local_60;
  ulonglong local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = 0;
  local_60 = 0;
  local_68[1] = 0;
  local_20 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  DbgPrintEx(0x98,0,"vpci [%s:%u] Early Restore: D0Entry MmioStart: %llx\n","CrashVpciFdoD0Entry");
  local_4c = 0;
  local_50 = 0x42490007;
  local_48 = *(undefined8 *)(*(longlong *)(param_1 + 0x30) + 0xb8);
  DbgPrintEx(0x98,0,"vpci [%s:%u] (crash) Send VpciMsgFdoD0Entry\n","CrashVpciFdoD0Entry");
  uVar2 = CrashVpciSendPacket(param_1,(longlong)&local_50,0x10);
  puVar3 = auStackY_98;
  if (-1 < (int)uVar2) {
    local_68[0] = 0x28;
    uVar2 = CrashVpciReceivePacket
                      (param_1,local_68 + 1,(longlong)&local_60,(longlong)&local_40,local_68);
    puVar3 = auStackY_98;
    if (-1 < (int)uVar2) {
      puVar3 = auStackY_98;
      if (((int)local_40 != 0x42490000) && (puVar3 = auStackY_98, (int)local_40 != 0x42490019)) {
        pcVar1 = (code *)swi(0x29);
        (*pcVar1)(0x3a);
        puVar3 = auStackY_90;
      }
      local_68[0] = 8;
      *(uint **)(puVar3 + 0x20) = local_68;
      *(undefined8 *)(puVar3 + -8) = 0x14000130b;
      uVar2 = CrashVpciReceivePacket
                        (param_1,local_68 + 1,(longlong)&local_60,(longlong)&local_58,
                         *(uint **)(puVar3 + 0x20));
      if ((-1 < (int)uVar2) && (uVar2 = local_58 & 0xffffffff, local_68[0] < 4)) {
        uVar2 = 0xc0000001;
      }
    }
  }
  *(undefined8 *)(puVar3 + -8) = 0x14000132a;
  return uVar2;
}



===== CrashVpciInitialize @ 140001344 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong CrashVpciInitialize(longlong *param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  char cVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  lVar1 = *param_1;
  uVar4 = 0;
  puVar2 = *(undefined8 **)(*(longlong *)(lVar1 + 0x30) + 0x40);
  if (puVar2 == (undefined8 *)0x0) {
    uVar4 = 0xc0000001;
  }
  else {
    DbgPrintEx(0x98,0,"vpci [%s:%u] >> CrashVpciInitialize\n","CrashVpciInitialize",0x2d6);
    (*(code *)puVar2[5])(*puVar2);
    cVar3 = (*(code *)puVar2[1])(*puVar2);
    if (cVar3 != '\0') {
      uVar5 = CrashVpciEstablishCommunication(lVar1);
      uVar4 = uVar5 & 0xffffffff;
      if (-1 < (int)uVar5) {
        uVar5 = CrashVpciFdoD0Entry(lVar1);
        uVar4 = uVar5 & 0xffffffff;
        if (-1 < (int)uVar5) {
          uVar4 = CrashVpciPrepareHardware(param_1);
          uVar4 = uVar4 & 0xffffffff;
        }
      }
    }
    DbgPrintEx(0x98,0,"vpci [%s:%u] << CrashVpciInitialize\n","CrashVpciInitialize",0x2f3);
  }
  return uVar4;
}



===== CrashVpciMarkMemory @ 14000142c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 CrashVpciMarkMemory(longlong *param_1,undefined8 *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  lVar1 = *param_1;
  uVar2 = *param_2;
  puVar3 = *(undefined8 **)(*(longlong *)(lVar1 + 0x30) + 0x40);
  (*(code *)param_2[1])(uVar2,param_1,8,0x69637056);
  (*(code *)param_2[1])(uVar2,param_1[2],(int)param_1[1],0x69637056);
  (*(code *)param_2[1])(uVar2,lVar1,8,0x69637056);
  (*(code *)param_2[1])(uVar2,*(undefined8 *)(lVar1 + 0x110),8,0x69637056);
  (*(code *)param_2[1])(uVar2,*(undefined8 *)(lVar1 + 0x100),8,0x69637056);
  (*(code *)param_2[1])(uVar2,puVar3,8,0x69637056);
  (*(code *)param_2[1])(uVar2,*(undefined8 *)(lVar1 + 0x30),8,0x69637056);
  (*(code *)param_2[1])(uVar2,puVar3[2],0,0x69637056);
  (*(code *)param_2[1])(uVar2,puVar3[3],0,0x69637056);
  (*(code *)param_2[1])(uVar2,puVar3[1],0,0x69637056);
  (*(code *)param_2[1])(uVar2,puVar3[5],0,0x69637056);
  (*(code *)puVar3[4])(*puVar3);
  return 0;
}



===== CrashVpciNotificationHandler @ 1400015a0 =====

void CrashVpciNotificationHandler(longlong *param_1,int param_2,int *param_3)

{
  char *pcVar1;
  undefined4 uVar2;
  
  if ((param_1 != (longlong *)0x0) && (*param_1 != 0)) {
    if (*(int *)(*param_1 + 0x318) == 0) {
      uVar2 = 0x389;
      pcVar1 = "vpci [%s:%u] Exiting: not on hiberpath\n";
    }
    else {
      if (param_2 != 0) {
        if (param_2 == 1) {
          DbgPrintEx(0x98,0,"vpci [%s:%u] PoSstHiberMarkMemoryNotification\n",
                     "CrashVpciNotificationHandler",0x390);
          CrashVpciMarkMemory(param_1,(undefined8 *)param_3);
          return;
        }
        if (param_2 != 2) {
          return;
        }
        DbgPrintEx(0x98,0,"vpci [%s:%u] PoSstEarlyRestoreNotification\n",
                   "CrashVpciNotificationHandler",0x398);
        if (*param_3 == 5) {
          CrashVpciInitialize(param_1);
          return;
        }
        DbgPrintEx(0x98,0,
                   "vpci [%s:%u] PoSstEarlyRestoreNotification: Got callback for unexpected power state %d\n"
                   ,"CrashVpciNotificationHandler",0x3a3,*param_3);
        return;
      }
      uVar2 = 0x394;
      pcVar1 = "vpci [%s:%u] PoSstHiberDiscardMemoryNotification\n";
    }
    DbgPrintEx(0x98,0,pcVar1,"CrashVpciNotificationHandler",uVar2);
  }
  return;
}



===== CrashVpciPrepareHardware @ 1400016d8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong CrashVpciPrepareHardware(undefined8 *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  longlong lVar4;
  uint *puVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined1 auStackY_78 [32];
  uint local_48 [2];
  undefined8 local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_78;
  puVar3 = (undefined4 *)*param_1;
  local_40 = 0;
  DbgPrintEx(0x98,0,"vpci [%s:%u] Early Restore: Prepare Hardware\n","CrashVpciPrepareHardware");
  lVar4 = *(longlong *)(puVar3 + 0x44);
  uVar1 = puVar3[0x46];
  DbgPrintEx(0x98,0,"vpci [%s:%u] TranslatePacket: Slot %d\n","CrashVpciPrepareHardware");
  local_48[0] = *(uint *)(param_1 + 1);
  puVar5 = (uint *)param_1[2];
  DbgPrintEx(0x98,0,"vpci [%s:%u] (crash) Send translatePacket (VpciMsgAssignedResourcesXxx)\n",
             "CrashVpciPrepareHardware");
  uVar6 = CrashVpciSendPacketSync((longlong)puVar3,lVar4,uVar1,(longlong)puVar5,local_48);
  uVar7 = uVar6 & 0xffffffff;
  if (-1 < (int)uVar6) {
    if (local_48[0] < 4) {
      uVar7 = 0xc0000001;
    }
    else {
      uVar2 = *puVar5;
      uVar7 = (ulonglong)uVar2;
      if (-1 < (int)uVar2) {
        local_38 = 0x42490004;
        local_30 = 1;
        local_34 = *puVar3;
        local_48[0] = 8;
        DbgPrintEx(0x98,0,"vpci [%s:%u] (crash) Send VpciMsgDevicePowerStateChange\n",
                   "CrashVpciPrepareHardware");
        uVar6 = CrashVpciSendPacketSync
                          ((longlong)puVar3,(longlong)&local_38,0xc,(longlong)&local_40,local_48);
        uVar7 = uVar6 & 0xffffffff;
        if (-1 < (int)uVar6) {
          if (local_48[0] < 4) {
            local_40._0_4_ = 0xc0000001;
          }
          uVar7 = (ulonglong)(uint)local_40;
        }
      }
    }
  }
  return uVar7;
}



===== CrashVpciReceivePacket @ 140001880 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
CrashVpciReceivePacket
          (longlong param_1,undefined8 param_2,longlong param_3,longlong param_4,uint *param_5)

{
  undefined8 *puVar1;
  uint *puVar2;
  char cVar3;
  undefined8 uVar4;
  uint uVar5;
  
  puVar2 = param_5;
  uVar4 = 0;
  uVar5 = 0;
  puVar1 = *(undefined8 **)(*(longlong *)(param_1 + 0x30) + 0x40);
  if (((param_5 == (uint *)0x0) || (param_4 == 0)) || (param_3 == 0)) {
    uVar4 = 0xc000000d;
  }
  else {
    while( true ) {
      param_5._0_4_ = *puVar2;
      cVar3 = (*(code *)puVar1[3])(*puVar1,param_2,param_3,param_4,&param_5);
      if (cVar3 != '\0') break;
      if (19999 < uVar5) {
        uVar4 = 0xc0000001;
        goto LAB_14000192d;
      }
      uVar5 = uVar5 + 1;
      KeStallExecutionProcessor(0x32);
    }
    if (*puVar2 < (uint)param_5) {
      uVar4 = 0x80000005;
    }
    else {
      *puVar2 = (uint)param_5;
    }
  }
LAB_14000192d:
  return uVar4;
}



===== CrashVpciSendPacket @ 140001954 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 CrashVpciSendPacket(longlong param_1,longlong param_2,undefined4 param_3)

{
  undefined8 *puVar1;
  char cVar2;
  undefined8 uVar3;
  uint uVar4;
  
  uVar3 = 0;
  uVar4 = 0;
  puVar1 = *(undefined8 **)(*(longlong *)(param_1 + 0x30) + 0x40);
  if (param_2 == 0) {
    uVar3 = 0xc000000d;
  }
  else {
    while (cVar2 = (*(code *)puVar1[2])(*puVar1,2,1,param_2,param_3,0,0), cVar2 == '\0') {
      if (19999 < uVar4) {
        uVar3 = 0xc00000b5;
        break;
      }
      uVar4 = uVar4 + 1;
      KeStallExecutionProcessor(0x32);
    }
  }
  return uVar3;
}



===== CrashVpciSendPacketSync @ 1400019fc =====

ulonglong CrashVpciSendPacketSync
                    (longlong param_1,longlong param_2,undefined4 param_3,longlong param_4,
                    uint *param_5)

{
  code *pcVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint local_res8 [2];
  int local_18 [2];
  longlong local_10;
  
  local_18[0] = 0;
  local_10 = 0;
  uVar2 = CrashVpciSendPacket(param_1,param_2,param_3);
  uVar3 = uVar2 & 0xffffffff;
  if (-1 < (int)uVar2) {
    do {
      local_res8[0] = *param_5;
      uVar2 = CrashVpciReceivePacket(param_1,local_18,(longlong)&local_10,param_4,local_res8);
      uVar3 = uVar2 & 0xffffffff;
      if ((int)uVar2 < 0) goto LAB_140001a82;
      if (local_10 == 1) {
        if (local_18[0] != 3) {
          pcVar1 = (code *)swi(0x29);
          (*pcVar1)(0x3a);
        }
        *param_5 = local_res8[0];
        goto LAB_140001a82;
      }
    } while (3 < local_res8[0]);
    uVar3 = 0xc0000001;
  }
LAB_140001a82:
  return uVar3 & 0xffffffff;
}



===== VscProxyHandleIoctlRescanBus @ 140001aa0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VscProxyHandleIoctlRescanBus(void)

{
  longlong lVar1;
  undefined8 *puVar2;
  
  lVar1 = (**(code **)(WdfFunctions_01033 + 0x650))
                    (WdfDriverGlobals,VpciCtrlDev,
                     PTR__WDF_VPCI_VSC_CTRL_DEVICE_DATA_TYPE_INFO_140010018);
  for (puVar2 = *(undefined8 **)(lVar1 + 0x10); puVar2 != (undefined8 *)(lVar1 + 0x10);
      puVar2 = (undefined8 *)*puVar2) {
    FdoReportDeviceProxyPrefixChanged((longlong)puVar2);
  }
  return;
}



===== WPP_RECORDER_SF_ @ 140001b00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                     undefined8 param_5)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,0);
  return;
}



===== WPP_RECORDER_SF_S @ 140001bd8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_S(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,wchar_t *param_6)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  
  lVar4 = -1;
  uVar5 = (ulonglong)(param_3 >> 0x10);
  lVar3 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar5 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[uVar5 * 0x50 + 0x29])) {
    if (param_6 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (param_6[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = param_6;
    if (param_6 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar5 * 0x50 + 0x18),0x2b,param_5,param_4,pwVar2
               ,lVar1,0);
  }
  if (param_6 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (param_6[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"NULL";
  }
  WppAutoLogTrace(param_1,2,param_3,param_5,param_4,param_6,lVar3,0);
  return;
}



===== WPP_RECORDER_SF_Sd @ 140001d34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Sd(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,wchar_t *param_6,undefined1 param_7)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  
  lVar4 = -1;
  uVar5 = (ulonglong)(param_3 >> 0x10);
  lVar3 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar5 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[uVar5 * 0x50 + 0x29])) {
    if (param_6 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (param_6[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = param_6;
    if (param_6 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar5 * 0x50 + 0x18),0x2b,param_5,param_4,pwVar2
               ,lVar1,&param_7,4,0);
  }
  if (param_6 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (param_6[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"NULL";
  }
  WppAutoLogTrace(param_1,2,param_3,param_5,param_4,param_6,lVar3,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_d @ 140001ec0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_d(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,4,0);
  return;
}



===== WPP_RECORDER_SF_dd @ 140001fbc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dd(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,4,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,2,param_3,param_5,param_4,&param_6,4,&param_7,4,0);
  return;
}



===== Feature_VpciVscBootDiskHibernation__private_IsEnabledDeviceUsageNoInline @ 1400020e8 =====

ulonglong Feature_VpciVscBootDiskHibernation__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)(uint)Feature_VpciVscBootDiskHibernation__private_featureState;
  if (((uint)Feature_VpciVscBootDiskHibernation__private_featureState & 0x10) == 0) {
    uVar1 = Feature_VpciVscBootDiskHibernation__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)((uint)Feature_VpciVscBootDiskHibernation__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_VpciVscBootDiskHibernation__private_IsEnabledFallback @ 140002120 =====

void Feature_VpciVscBootDiskHibernation__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_VpciVscBootDiskHibernation__private_descriptor);
  return;
}



===== WPP_RECORDER_SF_D @ 14000213c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_D(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,4,0);
  }
  WppAutoLogTrace(param_1,2,param_3,param_5,param_4,&param_6,4,0);
  return;
}



===== WPP_RECORDER_SF_qd @ 140002230 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qd(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,4,0);
  return;
}



===== WppClassicProviderCallback @ 140002360 =====

void WppClassicProviderCallback
               (undefined8 param_1,byte param_2,undefined8 *param_3,longlong param_4)

{
  undefined8 uVar1;
  
  if (param_2 < 2) {
    if (param_2 == 0) {
      *(undefined1 *)(param_4 + 0x29) = 0;
      *(undefined4 *)(param_4 + 0x2c) = 0;
      *(undefined8 *)(param_4 + 0x18) = 0;
    }
    else {
      *(undefined4 *)(param_4 + 0x2c) = *(undefined4 *)((longlong)param_3 + 4);
      *(undefined1 *)(param_4 + 0x29) = *(undefined1 *)((longlong)param_3 + 2);
      uVar1 = *param_3;
      *(undefined8 *)(param_4 + 0x18) = uVar1;
      imp_WppRecorderReplay
                (WPP_GLOBAL_Control,uVar1,*(undefined4 *)((longlong)param_3 + 4),
                 *(undefined1 *)((longlong)param_3 + 2));
    }
  }
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 1400023bc =====

uint * wil_details_FeatureReporting_RecordUsageInCache
                 (uint *param_1,uint *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  if (param_3 == 0) {
LAB_1400025c5:
    uVar6 = *param_2;
    do {
      uVar4 = uVar6;
      param_1[1] = 0;
      uVar6 = uVar4 | 1;
      if ((uVar4 >> 0xe & 1) != (uint)(param_3 == 4)) {
        uVar3 = uVar4 >> 5 & 0x1ff;
        if (uVar3 != 0) {
          param_1[1] = uVar3;
          param_1[2] = ~-(uint)(param_3 != 0) & 4;
          uVar6 = uVar4 & 0xffffc01f | 1;
        }
        uVar3 = 0;
        if (param_3 == 4) {
          uVar3 = 0x4000;
        }
        uVar6 = uVar3 | uVar6 & 0xffffbfff;
      }
      uVar5 = uVar6 >> 5 & 0x1ff;
      uVar3 = uVar5 + 1;
      if ((0x1ff < uVar3) || (uVar3 < uVar5)) {
        uVar3 = 1;
        param_1[2] = param_3;
        param_1[1] = uVar5;
      }
      LOCK();
      uVar5 = *param_2;
      if (uVar4 == uVar5) {
        *param_2 = (uVar3 << 5 ^ uVar6) & 0x3fe0 ^ uVar6;
        uVar6 = uVar4;
      }
      else {
        uVar6 = uVar5;
      }
      UNLOCK();
    } while (uVar4 != uVar5);
    *param_1 = ~uVar4 & 1;
  }
  else {
    if (param_3 != 1) {
      if ((param_3 == 2) || (param_3 == 3)) {
LAB_140002497:
        uVar6 = 0;
        if (param_3 == 2) {
          uVar6 = 2;
        }
        else if (param_3 == 3) {
          uVar6 = 8;
        }
        else if (param_3 == 6) {
          uVar6 = 4;
        }
        else if (param_3 == 7) {
          uVar6 = 0x10;
        }
        uVar3 = 1;
        uVar4 = *param_2;
        do {
          uVar2 = uVar4;
          uVar4 = uVar6 | uVar2;
          param_1[4] = (uint)(uVar4 == uVar2);
          uVar5 = uVar4 | 1;
          if (uVar4 == uVar2) {
            uVar5 = uVar4;
          }
          LOCK();
          uVar1 = *param_2;
          if (uVar2 == uVar1) {
            *param_2 = uVar5;
            uVar4 = uVar2;
          }
          else {
            uVar4 = uVar1;
          }
          UNLOCK();
        } while (uVar2 != uVar1);
        if (((uVar5 & 1) == 0) || ((uVar2 & 1) != 0)) {
          uVar3 = 0;
        }
        *param_1 = uVar3;
        return param_1;
      }
      if (param_3 == 4) goto LAB_1400025c5;
      if (param_3 != 5) {
        if ((param_3 != 6) && (param_3 != 7)) {
          uVar6 = param_3 - 0x140;
          if ((int)uVar6 < 0x40) {
            uVar4 = param_2[1];
            do {
              if (((uVar4 & 0x10) == 0) || ((uVar4 >> 5 & 0x3f) != uVar6)) {
                uVar3 = 0;
              }
              else {
                uVar3 = 1;
              }
              param_1[4] = uVar3;
              LOCK();
              uVar3 = param_2[1];
              bVar7 = uVar4 == uVar3;
              if (bVar7) {
                param_2[1] = (uVar6 * 0x20 ^ uVar4) & 0x7e0 ^ uVar4 | 0x10;
              }
              else {
                uVar4 = uVar3;
              }
              UNLOCK();
            } while (!bVar7);
            if (param_1[4] != 0) {
              return param_1;
            }
          }
          param_1[2] = param_3;
          param_1[1] = 1;
          param_1[3] = param_4;
          return param_1;
        }
        goto LAB_140002497;
      }
    }
    uVar6 = *param_2;
    do {
      uVar4 = uVar6;
      param_1[1] = 0;
      uVar6 = uVar4 | 1;
      if ((uVar4 >> 0x16 & 1) != (uint)(param_3 == 5)) {
        uVar3 = uVar4 >> 0xf & 0x7f;
        if (uVar3 != 0) {
          param_1[1] = uVar3;
          uVar3 = 5;
          if (param_3 != 1) {
            uVar3 = 1;
          }
          uVar6 = uVar4 & 0xffc07fff | 1;
          param_1[2] = uVar3;
        }
        uVar3 = 0;
        if (param_3 == 5) {
          uVar3 = 0x400000;
        }
        uVar6 = uVar3 | uVar6 & 0xffbfffff;
      }
      uVar5 = uVar6 >> 0xf & 0x7f;
      uVar3 = uVar5 + 1;
      if ((0x7f < uVar3) || (uVar3 < uVar5)) {
        uVar3 = 1;
        param_1[2] = param_3;
        param_1[1] = uVar5;
      }
      LOCK();
      uVar5 = *param_2;
      if (uVar4 == uVar5) {
        *param_2 = (uVar3 << 0xf ^ uVar6) & 0x3f8000 ^ uVar6;
        uVar6 = uVar4;
      }
      else {
        uVar6 = uVar5;
      }
      UNLOCK();
    } while (uVar4 != uVar5);
    *param_1 = ~uVar4 & 1;
  }
  param_1[4] = 0;
  return param_1;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 1400026b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (longlong param_1,ulonglong param_2,int param_3)

{
  bool bVar1;
  undefined7 extraout_var;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  int local_res18 [4];
  
  uVar2 = (uint)param_2 & 1;
  if (param_3 != 0) {
    if (param_3 == 1) {
      uVar3 = (uVar2 ^ 1) << 2;
      goto LAB_140002781;
    }
    if (param_3 == 2) {
      uVar3 = (uVar2 ^ 1) * 4 + 1;
      goto LAB_140002781;
    }
    if (param_3 == 3) {
      uVar3 = (uVar2 ^ 1) * 4 + 2;
      goto LAB_140002781;
    }
    if (param_3 == 4) {
      uVar3 = (uVar2 ^ 1) * 4 + 3;
      goto LAB_140002781;
    }
    if (param_3 == 5) {
      uVar3 = (uVar2 ^ 1) * 2 + 8;
      goto LAB_140002781;
    }
    if (param_3 == 6) {
      uVar3 = (uVar2 ^ 1) * 2 + 9;
      goto LAB_140002781;
    }
    bVar4 = (char)param_3 + 0x9c;
    if (bVar4 < 0x32) {
      uVar3 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar4;
      goto LAB_140002781;
    }
  }
  uVar3 = 0xff;
LAB_140002781:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(param_1,param_2,uVar3);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (*(undefined4 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x10),0,uVar2,local_res18,0
               ,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 1400027d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (longlong param_1,undefined8 param_2,uint param_3)

{
  uint6 uVar1;
  uint *puVar2;
  undefined1 auStack_98 [32];
  uint *local_78;
  undefined8 local_68;
  uint local_60 [6];
  uint local_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_98;
  puVar2 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_60,*(uint **)(param_1 + 8),param_3,(uint)((ulonglong)param_2 >> 0x20));
  local_48 = *puVar2;
  uStack_44 = puVar2[1];
  uStack_40 = puVar2[2];
  uStack_3c = puVar2[3];
  local_38 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_78 = &local_48;
    (*g_wil_details_recordFeatureUsage)
              (*(undefined4 *)(param_1 + 0x18),param_3,1,*(undefined8 *)(param_1 + 8));
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_68._0_6_ = CONCAT24((short)param_3,*(undefined4 *)(param_1 + 0x18));
    uVar1 = (uint6)local_68;
    local_68 = (ulonglong)(uint6)local_68;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_68 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_68);
  }
  return (int)local_38 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 1400028c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                    (uint *param_1,ulonglong param_2,longlong param_3)

{
  undefined8 *puVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  longlong *plVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  undefined1 auStack_a8 [32];
  undefined8 local_88;
  ulonglong local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined4 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_a8;
  iVar3 = 0;
  local_88 = param_2;
  if (g_wil_details_ensureSubscribedToFeatureConfigurationChanges != (code *)0x0) {
    iVar3 = (*g_wil_details_ensureSubscribedToFeatureConfigurationChanges)();
  }
  local_70 = 0;
  uStack_68 = 0;
  local_78 = 0;
  bVar2 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  iVar4 = RtlQueryFeatureConfiguration
                    (*(undefined4 *)(param_3 + 0x18),1 < (byte)(*(char *)(param_3 + 0x1c) - 2U),
                     &local_78,&local_58);
  if (iVar4 == 0) {
    bVar2 = 1;
    uVar8 = local_58._4_4_ >> 7 & 1;
    local_70 = CONCAT44(local_70._4_4_,local_58._4_4_ >> 4) & 0xffffffff00000003;
    uVar5 = local_58._4_4_ >> 6 & 1;
    uVar11 = local_58._4_4_ >> 4 & 3;
LAB_14000297b:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_1400029a9;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_14000297b;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_1400029a9:
  uVar6 = -(uint)bVar2 & uVar11 & 3;
  if (uVar6 == 0) {
    uVar9 = -(uint)(*(char *)(param_3 + 0x1f) != '\0') & 0x40;
  }
  else {
    uVar9 = 0;
    if (uVar11 == 2) {
      uVar9 = 0x40;
    }
  }
  uVar11 = uVar9 >> 6 ^ (uVar9 | uVar6 << 7 | uVar8 | uVar5);
  if ((uVar9 != 0) && (plVar10 = *(longlong **)(param_3 + 0x20), plVar10 != (longlong *)0x0)) {
    do {
      puVar1 = (undefined8 *)*plVar10;
      if (puVar1 == (undefined8 *)0x0) break;
      if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
         (*(char *)((longlong)puVar1 + 0x1d) == '\0')) {
        uVar8 = *(uint *)*puVar1;
        local_80 = (ulonglong)uVar8;
        if ((uVar8 & 2) == 0) {
          uVar7 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            ((uint *)*puVar1,local_80,(longlong)puVar1);
          uVar8 = (uint)uVar7;
        }
        uVar5 = uVar11 & 0xfffffffe;
        uVar11 = (uint)((uVar8 & uVar11 & 1) != 0);
      }
      else {
        if (((uVar11 & 1) == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
        }
        else {
          uVar5 = 1;
        }
        uVar11 = uVar11 & 0xfffffffe;
      }
      uVar11 = uVar11 | uVar5;
      plVar10 = plVar10 + 1;
    } while ((uVar11 & 1) != 0);
  }
  bVar12 = *(char *)(param_3 + 0x1c) == '\0';
  uVar7 = param_2 & 0xffffffff;
  while( true ) {
    uVar5 = (uint)uVar7;
    local_88 = CONCAT44(local_88._4_4_,uVar5);
    if ((!bVar12 || iVar3 != 0) && (local_88 = CONCAT44(local_88._4_4_,uVar5), (uVar7 & 2) == 0)) {
      uVar8 = (uVar11 ^ uVar5) & 0x9c1 ^ uVar5;
      uVar5 = uVar8 | 2;
      local_88 = CONCAT44(local_88._4_4_,uVar8) | 2;
    }
    if ((param_2 & 4) == 0) {
      uVar8 = (uVar5 ^ uVar11) & 0x400 ^ uVar5;
      uVar5 = uVar8 | 4;
      local_88 = CONCAT44(local_88._4_4_,uVar8) | 4;
    }
    uVar7 = param_2 & 0xffffffff;
    LOCK();
    uVar8 = *param_1;
    bVar13 = (uint)param_2 == uVar8;
    if (bVar13) {
      *param_1 = uVar5;
    }
    else {
      uVar7 = (ulonglong)uVar8;
    }
    UNLOCK();
    if (bVar13) break;
    param_2 = uVar7;
  }
  if (((param_2 & 4) == 0) &&
     (g_wil_details_subscribeFeatureStateCacheToConfigurationChanges != (code *)0x0)) {
    (*g_wil_details_subscribeFeatureStateCacheToConfigurationChanges)
              (param_1,*(undefined1 *)(param_3 + 0x1c),iVar3);
  }
  if (bVar12 && iVar3 == 0) {
    local_88 = CONCAT44(local_88._4_4_,(uVar11 ^ uVar5) & 0x9c1 ^ uVar5);
  }
  return local_88;
}



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140002b34 =====

void wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath
               (uint param_1,int param_2,undefined8 *param_3)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  puVar2 = (uint *)*param_3;
  if (param_2 == 3) {
    uVar4 = 0x10;
  }
  else {
    if (param_2 != 4) {
      return;
    }
    uVar4 = 0x20;
  }
  if ((*(char *)((longlong)param_3 + 0x1e) == '\0') && (*(char *)((longlong)param_3 + 0x1d) == '\0')
     ) {
    uVar3 = *puVar2;
    if ((uVar3 & 2) != 0) {
      while ((uVar3 & 1) == (param_1 & 1)) {
        LOCK();
        uVar1 = *puVar2;
        bVar5 = uVar3 == uVar1;
        if (bVar5) {
          *puVar2 = uVar4 | uVar3;
        }
        else {
          uVar3 = uVar1;
        }
        UNLOCK();
        if (bVar5) {
          return;
        }
        if ((uVar3 & 2) == 0) {
          return;
        }
      }
    }
  }
  else {
    LOCK();
    *puVar2 = *puVar2 | uVar4;
    UNLOCK();
  }
  return;
}



===== wil_details_IsEnabledFallback @ 140002b98 =====

uint wil_details_IsEnabledFallback(ulonglong param_1,int param_2,undefined8 *param_3)

{
  ulonglong local_res8;
  
  local_res8 = param_1 & 0xffffffff;
  if ((param_1 & 2) == 0) {
    local_res8 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                           ((uint *)*param_3,param_1,(longlong)param_3);
    param_1 = local_res8 & 0xffffffff;
  }
  if ((param_2 != 0) &&
     (wil_details_FeatureReporting_ReportUsageToService((longlong)param_3,local_res8,param_2),
     param_2 - 3U < 2)) {
    wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath((uint)local_res8,param_2,param_3);
  }
  return (uint)param_1 & 1;
}



===== wil_details_RecordCachedUsage @ 140002c2c =====

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



===== wil_details_RecordFeatureUsageReporting @ 140002d80 =====

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



===== FdoDeviceDestroy @ 140002e10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FdoDeviceDestroy(undefined8 param_1)

{
  undefined1 uVar1;
  
  uVar1 = (**(code **)(WdfFunctions_01033 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_VPCI_FDO_CONTEXT_TYPE_INFO_140010040);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xb,
                       &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar1,
                       (char)SystemReserved1[0xf]);
  }
  return;
}



===== FdoInvalidateBlockIndicate @ 140002e90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FdoInvalidateBlockIndicate(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uVar4;
  int iVar5;
  undefined8 *puVar6;
  longlong local_res10;
  longlong *local_res18 [2];
  
  local_res18[0] = (longlong *)0x0;
  local_res10 = 0;
  (**(code **)(WdfFunctions_01033 + 0x668))
            (WdfDriverGlobals,param_1,0x434b4c42,0x829,"onecore\\vm\\dv\\vpci\\vsc\\sys\\fdo.c");
  lVar1 = param_2 + 0x168;
  uVar4 = KeAcquireSpinLockRaiseToDpc(lVar1);
  lVar3 = *(longlong *)(param_2 + 0x170);
  if (lVar3 != 0) {
    iVar5 = (**(code **)(WdfFunctions_01033 + 0x4f0))
                      (WdfDriverGlobals,*(undefined8 *)(param_2 + 0x158),&local_res10);
    if (-1 < iVar5) {
      *(undefined8 *)(param_2 + 0x170) = 0;
      KeReleaseSpinLock(lVar1,uVar4);
      iVar5 = (**(code **)(WdfFunctions_01033 + 0x870))
                        (WdfDriverGlobals,local_res10,8,local_res18,0);
      if (-1 < iVar5) {
        LOCK();
        lVar2 = *(longlong *)(param_2 + 0x160);
        *(longlong *)(param_2 + 0x160) = 0;
        UNLOCK();
        *local_res18[0] = lVar2;
        if (lVar2 != 0) {
          (**(code **)(WdfFunctions_01033 + 0x898))(WdfDriverGlobals,local_res10,8);
          puVar6 = (undefined8 *)
                   (**(code **)(WdfFunctions_01033 + 0x650))
                             (WdfDriverGlobals,lVar3,
                              PTR__WDF_VPCI_WORKITEM_CONTEXT_TYPE_INFO_140010090);
          *puVar6 = param_1;
          puVar6[1] = param_2;
          puVar6[2] = local_res10;
          (**(code **)(WdfFunctions_01033 + 0xbe0))(WdfDriverGlobals,lVar3);
          return;
        }
      }
      goto LAB_140003035;
    }
  }
  KeReleaseSpinLock(lVar1,uVar4);
LAB_140003035:
  uVar4 = KeAcquireSpinLockRaiseToDpc(lVar1);
  if (lVar3 != 0) {
    *(longlong *)(param_2 + 0x170) = lVar3;
  }
  if ((local_res10 != 0) &&
     (iVar5 = (**(code **)(WdfFunctions_01033 + 0x8d8))(WdfDriverGlobals), iVar5 < 0)) {
    (**(code **)(WdfFunctions_01033 + 0x838))(WdfDriverGlobals,local_res10,iVar5);
  }
  KeReleaseSpinLock(lVar1,uVar4);
  (**(code **)(WdfFunctions_01033 + 0x670))
            (WdfDriverGlobals,param_1,0x434b4c42,0x88a,"onecore\\vm\\dv\\vpci\\vsc\\sys\\fdo.c");
  return;
}



===== FdoInvalidateBlockWorker @ 140003100 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FdoInvalidateBlockWorker(undefined8 param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined1 uVar3;
  undefined8 *puVar4;
  
  puVar4 = (undefined8 *)
           (**(code **)(WdfFunctions_01033 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_VPCI_WORKITEM_CONTEXT_TYPE_INFO_140010090);
  uVar1 = *puVar4;
  lVar2 = puVar4[1];
  (**(code **)(WdfFunctions_01033 + 0x838))(WdfDriverGlobals,puVar4[2],0);
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x168);
  *(undefined8 *)(lVar2 + 0x170) = param_1;
  KeReleaseSpinLock(lVar2 + 0x168,uVar3);
  FdoInvalidateBlockIndicate(uVar1,lVar2);
  (**(code **)(WdfFunctions_01033 + 0x670))
            (WdfDriverGlobals,uVar1,0x434b4c42,0x8c1,"onecore\\vm\\dv\\vpci\\vsc\\sys\\fdo.c");
  return;
}



===== FdoProtocolCommunication @ 1400031f0 =====

ulonglong FdoProtocolCommunication(longlong param_1)

{
  undefined4 uVar1;
  int iVar2;
  ulonglong uVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined2 uVar6;
  undefined4 *puVar7;
  uint local_res10 [2];
  undefined8 local_res18;
  ulonglong local_res20;
  undefined1 uVar8;
  undefined1 uVar9;
  
  local_res18 = 0;
  local_res20 = 0;
  local_res10[0] = 0;
  uVar3 = Feature_VpciVscRelaxedInterruptLimit__private_IsEnabledDeviceUsageNoInline();
  uVar8 = (undefined1)param_1;
  if ((int)uVar3 == 0) {
LAB_1400033b3:
    uVar5 = 0;
    puVar7 = &DAT_14000d6d8;
    do {
      local_res18 = CONCAT44(*puVar7,0x42490013);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x18,
                           &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar8,(char)*puVar7);
      }
      local_res10[0] = 8;
      uVar3 = VmbChannelSendSynchronousRequest
                        (*(undefined8 *)(param_1 + 0x28),&local_res18,8,0,1,&local_res20,local_res10
                         ,0);
      iVar2 = (int)uVar3;
      uVar3 = uVar3 & 0xffffffff;
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar6 = 0x19;
          goto LAB_1400034e0;
        }
        break;
      }
      if (local_res10[0] < 8) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140003338;
        uVar6 = 0x1a;
        goto LAB_140003311;
      }
      iVar2 = (int)local_res20;
      uVar3 = local_res20 & 0xffffffff;
      if (-1 < iVar2) {
        uVar1 = (&DAT_14000d6d8)[uVar5];
        *(undefined4 *)(param_1 + 0x18) = uVar1;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar6 = 0x1b;
          uVar9 = (undefined1)uVar1;
          goto LAB_140003369;
        }
        break;
      }
      if (iVar2 != -0x3fffffa7) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar6 = 0x1c;
          uVar4 = 1;
          goto LAB_1400034e9;
        }
        break;
      }
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar4;
      puVar7 = puVar7 + 1;
    } while (uVar4 < 6);
  }
  else {
    local_res18 = 0x1000642490013;
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x12,
                         &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids),
       (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x13,
                         &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar8,
                         (char)((ulonglong)local_res18 >> 0x20));
    }
    local_res10[0] = 8;
    uVar3 = VmbChannelSendSynchronousRequest
                      (*(undefined8 *)(param_1 + 0x28),&local_res18,8,0,1,&local_res20,local_res10,0
                      );
    iVar2 = (int)uVar3;
    uVar3 = uVar3 & 0xffffffff;
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140003507;
      uVar6 = 0x14;
LAB_1400034e0:
      uVar4 = 2;
LAB_1400034e9:
      uVar9 = (undefined1)iVar2;
    }
    else {
      if (local_res10[0] < 8) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar6 = 0x15;
LAB_140003311:
          WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar6,
                             &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar8,
                             (char)local_res10[0]);
        }
LAB_140003338:
        uVar3 = 0xc0000001;
        goto LAB_140003507;
      }
      uVar3 = local_res20;
      if (-1 < (int)local_res20) {
        *(undefined4 *)(param_1 + 0x18) = 0x10006;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar6 = 0x16;
          uVar9 = 6;
LAB_140003369:
          WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,uVar6,
                             &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar8,uVar9);
        }
        goto LAB_140003507;
      }
      if ((int)local_res20 == -0x3fffffa7) goto LAB_1400033b3;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140003507;
      uVar6 = 0x17;
      uVar9 = (undefined1)local_res20;
      uVar4 = 1;
    }
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar4,uVar6,
                       &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar8,uVar9);
  }
LAB_140003507:
  return uVar3 & 0xffffffff;
}



===== FdoReadConfig @ 140003520 =====

void FdoReadConfig(longlong param_1,undefined4 param_2,undefined4 *param_3,ulonglong param_4,
                  uint param_5)

{
  byte bVar1;
  undefined1 uVar2;
  undefined4 *puVar3;
  ulonglong uVar4;
  uint uVar5;
  
  uVar4 = param_4 & 0xffffffff;
  uVar2 = KfRaiseIrql(0xf);
  KeAcquireSpinLockAtDpcLevel(param_1 + 0x70);
  puVar3 = *(undefined4 **)(param_1 + 0xb0);
  if (puVar3 == (undefined4 *)0x0) {
    memset(param_3,0xff,(ulonglong)param_5);
  }
  else {
    *puVar3 = param_2;
    puVar3 = (undefined4 *)(uVar4 + 0x1000 + (longlong)puVar3);
    LOCK();
    UNLOCK();
    for (; param_5 != 0; param_5 = param_5 - uVar5) {
      bVar1 = (&PCIDeref)[(ulonglong)(param_5 & 3) + (ulonglong)((uint)uVar4 & 3) * 4];
      uVar5 = (uint)bVar1;
      if (bVar1 == 0) {
        uVar5 = 4;
        *param_3 = *puVar3;
      }
      else if (bVar1 == 1) {
        *(undefined1 *)param_3 = *(undefined1 *)puVar3;
      }
      else if (bVar1 == 2) {
        *(undefined2 *)param_3 = *(undefined2 *)puVar3;
      }
      uVar4 = (ulonglong)((uint)uVar4 + uVar5);
      param_3 = (undefined4 *)((longlong)param_3 + (ulonglong)uVar5);
      puVar3 = (undefined4 *)((longlong)puVar3 + (ulonglong)uVar5);
    }
  }
  KeReleaseSpinLockFromDpcLevel(param_1 + 0x70);
  KeLowerIrql(uVar2);
  return;
}



===== FdoWriteConfig @ 140003638 =====

void FdoWriteConfig(longlong param_1,undefined4 param_2,undefined4 *param_3,ulonglong param_4,
                   uint param_5)

{
  byte bVar1;
  undefined1 uVar2;
  undefined4 *puVar3;
  ulonglong uVar4;
  uint uVar5;
  
  uVar4 = param_4 & 0xffffffff;
  uVar2 = KfRaiseIrql(0xf);
  KeAcquireSpinLockAtDpcLevel(param_1 + 0x70);
  puVar3 = *(undefined4 **)(param_1 + 0xb0);
  if (puVar3 != (undefined4 *)0x0) {
    *puVar3 = param_2;
    puVar3 = (undefined4 *)(uVar4 + 0x1000 + (longlong)puVar3);
    LOCK();
    UNLOCK();
    for (; param_5 != 0; param_5 = param_5 - uVar5) {
      bVar1 = (&PCIDeref)[(ulonglong)(param_5 & 3) + (ulonglong)((uint)uVar4 & 3) * 4];
      uVar5 = (uint)bVar1;
      if (bVar1 == 0) {
        uVar5 = 4;
        *puVar3 = *param_3;
LAB_1400036e6:
        LOCK();
        UNLOCK();
      }
      else {
        if (bVar1 == 1) {
          *(undefined1 *)puVar3 = *(undefined1 *)param_3;
          goto LAB_1400036e6;
        }
        if (bVar1 == 2) {
          *(undefined2 *)puVar3 = *(undefined2 *)param_3;
          goto LAB_1400036e6;
        }
      }
      uVar4 = (ulonglong)((uint)uVar4 + uVar5);
      param_3 = (undefined4 *)((longlong)param_3 + (ulonglong)uVar5);
      puVar3 = (undefined4 *)((longlong)puVar3 + (ulonglong)uVar5);
    }
  }
  KeReleaseSpinLockFromDpcLevel(param_1 + 0x70);
  KeLowerIrql(uVar2);
  return;
}



===== Feature_VpciVscRelaxedInterruptLimit__private_IsEnabledDeviceUsageNoInline @ 140003744 =====

ulonglong Feature_VpciVscRelaxedInterruptLimit__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_VpciVscRelaxedInterruptLimit__private_featureState;
  if ((Feature_VpciVscRelaxedInterruptLimit__private_featureState & 0x10) == 0) {
    uVar1 = Feature_VpciVscRelaxedInterruptLimit__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_VpciVscRelaxedInterruptLimit__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_VpciVscRelaxedInterruptLimit__private_IsEnabledFallback @ 14000377c =====

void Feature_VpciVscRelaxedInterruptLimit__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_VpciVscRelaxedInterruptLimit__private_descriptor);
  return;
}



===== GetCompletionStatus @ 140003798 =====

int GetCompletionStatus(int param_1,int *param_2,undefined8 param_3)

{
  undefined2 uVar1;
  undefined1 unaff_retaddr;
  undefined8 in_stack_ffffffffffffffd8;
  
  if (param_1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return param_1;
    }
    uVar1 = 0x4d;
  }
  else {
    if ((uint)param_3 < 4) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,2,0x4e,
                           &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,(char)param_3,
                           unaff_retaddr);
      }
      return -0x3fffffff;
    }
    param_1 = *param_2;
    if (-1 < param_1) {
      return param_1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return param_1;
    }
    uVar1 = 0x4f;
  }
  WPP_RECORDER_SF_dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,uVar1,
                     in_stack_ffffffffffffffd8,(char)param_1,unaff_retaddr);
  return param_1;
}



===== VpciAddResourceRequirements @ 140003870 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int VpciAddResourceRequirements(undefined8 param_1,undefined8 param_2)

{
  undefined1 uVar1;
  int iVar2;
  undefined2 uVar3;
  undefined1 auStackY_88 [32];
  undefined8 local_48;
  undefined2 local_40;
  undefined1 local_3e;
  undefined1 local_3d;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 uStack_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_88;
  local_3d = 0;
  local_3a = 0;
  local_48 = 0;
  iVar2 = (**(code **)(WdfFunctions_01033 + 0x930))(WdfDriverGlobals,param_2,0,&local_48);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar2;
    }
    uVar1 = (**(code **)(WdfFunctions_01033 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_VPCI_FDO_CONTEXT_TYPE_INFO_140010040);
    uVar3 = 0x4a;
  }
  else {
    iVar2 = (**(code **)(WdfFunctions_01033 + 0x900))(WdfDriverGlobals,param_2,local_48);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar2;
      }
      uVar1 = (**(code **)(WdfFunctions_01033 + 0x650))
                        (WdfDriverGlobals,param_1,PTR__WDF_VPCI_FDO_CONTEXT_TYPE_INFO_140010040);
      uVar3 = 0x4b;
    }
    else {
      local_34 = 0x2000;
      local_38 = 0x2000;
      local_40 = 0x300;
      local_3e = 1;
      local_3c = 0;
      local_30 = 0;
      uStack_28 = 0xffffffffffffffff;
      iVar2 = (**(code **)(WdfFunctions_01033 + 0x938))(WdfDriverGlobals,local_48,&local_40);
      if (-1 < iVar2) {
        return 0;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar2;
      }
      uVar1 = (**(code **)(WdfFunctions_01033 + 0x650))
                        (WdfDriverGlobals,param_1,PTR__WDF_VPCI_FDO_CONTEXT_TYPE_INFO_140010040);
      uVar3 = 0x4c;
    }
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar3,
                     &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar1,(char)iVar2);
  return iVar2;
}



===== VpciChannelClosed @ 140003a70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void VpciChannelClosed(undefined8 param_1)

{
  undefined1 uVar1;
  undefined1 auStackY_78 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  local_20 = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar1 = VmbChannelGetPointer();
    WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x21,
                       &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,(char)param_1,uVar1);
  }
  FdoReportDevices(param_1,(longlong)&local_38,0x1c);
  return;
}



===== VpciCompletionBufferCreate @ 140003b18 =====

uint * VpciCompletionBufferCreate(int param_1)

{
  uint *puVar1;
  ulonglong uVar2;
  uint uVar3;
  
  uVar3 = param_1 + 7U & 0xfffffff8;
  uVar2 = (ulonglong)(uVar3 + 0x10);
  puVar1 = (uint *)ExAllocatePool2(0x40,uVar2,0x69637056);
  if (puVar1 == (uint *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,1,0x68,
                        &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,(char)param_1);
    }
    puVar1 = (uint *)0x0;
  }
  else {
    *puVar1 = uVar3;
  }
  return puVar1;
}



===== VpciD0Entry @ 140003ba0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong VpciD0Entry(undefined8 param_1,undefined1 param_2)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  byte bVar5;
  ulonglong uVar6;
  undefined2 uVar7;
  undefined1 auStackY_98 [32];
  undefined1 uVar8;
  int local_50 [4];
  undefined8 local_40;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  int local_24;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_98;
  local_50[0] = 0;
  local_50[1] = 0;
  lVar3 = (**(code **)(WdfFunctions_01033 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_VPCI_FDO_CONTEXT_TYPE_INFO_140010040);
  uVar8 = (undefined1)lVar3;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x50,
                       &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar8,param_2);
  }
  if ((*(char *)(lVar3 + 0x68) != '\0') &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x51,
                      &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar8);
  }
  uVar1 = VmbChannelEnable(*(undefined8 *)(lVar3 + 0x28));
  uVar6 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x52,
                        &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,(char)uVar1);
    }
  }
  else {
    VmbChannelGetInterfaceInstance(*(undefined8 *)(lVar3 + 0x28),lVar3 + 0x30);
    local_28 = 5;
    local_38 = 0xc8ebdfb0;
    uStack_34 = 0x11d0b510;
    uStack_30 = 0xa000e580;
    uStack_2c = 0xe34225c9;
    local_24 = (uint)*(ushort *)(lVar3 + 0x34) << 8;
    (**(code **)(WdfFunctions_01033 + 0x2a8))(WdfDriverGlobals,param_1,&local_38);
    uVar4 = FdoProtocolCommunication(lVar3);
    uVar6 = uVar4 & 0xffffffff;
    if ((int)uVar4 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar6;
      }
      uVar7 = 0x53;
      bVar5 = 2;
      uVar1 = 1;
    }
    else {
      local_50[3] = 0;
      local_50[2] = 0x42490007;
      local_40 = *(undefined8 *)(lVar3 + 0xb8);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x54,
                          &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar8);
      }
      iVar2 = VmbChannelSendSynchronousRequest(*(undefined8 *)(lVar3 + 0x28),local_50 + 2,0x10);
      uVar1 = GetCompletionStatus(iVar2,local_50,8);
      uVar6 = (ulonglong)uVar1;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar6;
      }
      uVar7 = 0x55;
      uVar1 = 6;
      bVar5 = 4;
    }
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar5,uVar1,uVar7,
                       &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar8,(char)uVar6);
  }
  return uVar6;
}



===== VpciEvtChannelProcessPacket @ 140003e40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VpciEvtChannelProcessPacket(undefined8 param_1,undefined8 param_2,int *param_3,uint param_4)

{
  int iVar1;
  char cVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined4 local_38 [4];
  
  puVar3 = (undefined8 *)VmbChannelGetPointer();
  uVar5 = *puVar3;
  lVar4 = (**(code **)(WdfFunctions_01033 + 0x650))
                    (WdfDriverGlobals,uVar5,PTR__WDF_VPCI_FDO_CONTEXT_TYPE_INFO_140010040);
  cVar2 = KeGetCurrentIrql();
  uVar6 = (undefined1)lVar4;
  uVar7 = (undefined1)param_2;
  if (cVar2 != '\0') {
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,6,0x1d,
                         &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar6,uVar7);
    }
    VmbChannelPacketDeferToPassive(param_2);
    return;
  }
  if (param_4 < 4) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0x1e,
                         &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar6,(char)param_4);
    }
    local_38[0] = 0xc0000023;
    goto LAB_140004040;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qLqq
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,6,0x1f,
               &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar6,(char)*param_3,uVar7,
               (char)SystemReserved1[0xf]);
  }
  iVar1 = *param_3;
  if (iVar1 == 0x42490000) {
    FdoReportDevices(param_1,(longlong)param_3,param_4);
  }
  else {
    if (iVar1 == 0x4249000b) {
      uVar5 = 5;
    }
    else if (iVar1 == 0x4249000c) {
      uVar5 = 6;
    }
    else {
      if (iVar1 != 0x4249000d) {
        if (iVar1 == 0x42490012) {
          if (0xf < param_4) {
            FdoInvalidateBlockMessage(param_1,(longlong)param_3);
          }
        }
        else {
          if ((iVar1 != 0x42490019) || (*(uint *)(lVar4 + 0x18) < 0x10003)) {
            local_38[0] = 0xc00000bb;
            goto LAB_140004040;
          }
          FdoReportDevices2(param_1,(longlong)param_3,param_4);
        }
        goto LAB_14000403b;
      }
      uVar5 = 7;
    }
    FdoSimplePdoMessage(param_1,uVar5,(longlong)param_3,param_4);
  }
LAB_14000403b:
  local_38[0] = 0;
LAB_140004040:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x20,
                       &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar6,uVar7);
  }
  VmbChannelPacketComplete(param_2,local_38,4);
  return;
}



===== VpciPacketCreate @ 1400040b4 =====

longlong VpciPacketCreate(undefined8 param_1,int param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint *puVar3;
  
  lVar1 = VmbPacketAllocate();
  if (lVar1 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x66,
                       &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids);
    }
  }
  else {
    lVar2 = ExAllocatePool2(0x40,0x20,0x69637056);
    if (lVar2 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x67,
                         &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids);
      }
    }
    else {
      if (param_2 == 0) {
        puVar3 = (uint *)0x0;
LAB_1400041a7:
        *(uint **)(lVar2 + 0x18) = puVar3;
        VmbPacketSetPointer(lVar1,lVar2);
        return lVar1;
      }
      puVar3 = VpciCompletionBufferCreate(param_2);
      if (puVar3 != (uint *)0x0) goto LAB_1400041a7;
      ExFreePoolWithTag(lVar2,0x69637056);
    }
    VmbPacketFree(lVar1);
  }
  return 0;
}



===== VpciPacketDestroy @ 1400041d8 =====

void VpciPacketDestroy(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = VmbPacketGetPointer();
  if (*(longlong *)(lVar1 + 0x18) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0x18),0x69637056);
    *(undefined8 *)(lVar1 + 0x18) = 0;
  }
  ExFreePoolWithTag(lVar1,0x69637056);
  VmbPacketSetPointer(param_1,0);
  VmbPacketFree(param_1);
  return;
}



===== VpciReleaseHardware @ 140004260 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 VpciReleaseHardware(undefined8 param_1)

{
  undefined8 uVar1;
  undefined1 uVar2;
  longlong lVar3;
  
  lVar3 = (**(code **)(WdfFunctions_01033 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_VPCI_FDO_CONTEXT_TYPE_INFO_140010040);
  if (*(longlong *)(lVar3 + 0xb0) != 0) {
    uVar2 = KfRaiseIrql(0xf);
    KeAcquireSpinLockAtDpcLevel(lVar3 + 0x70);
    uVar1 = *(undefined8 *)(lVar3 + 0xb0);
    *(undefined8 *)(lVar3 + 0xb0) = 0;
    KeReleaseSpinLockFromDpcLevel(lVar3 + 0x70);
    KeLowerIrql(uVar2);
    MmUnmapIoSpace(uVar1,0x2000);
  }
  return 0;
}



===== VpciSetAcs @ 140004330 =====

undefined8 VpciSetAcs(void)

{
  return 0;
}



===== VpciSelfManagedIoInit @ 140004340 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 VpciSelfManagedIoInit(undefined8 param_1)

{
  undefined1 uVar1;
  
  uVar1 = (**(code **)(WdfFunctions_01033 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_VPCI_FDO_CONTEXT_TYPE_INFO_140010040);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x5d,
                      &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar1);
  }
  return 0;
}



===== VpciSelfManagedIoRestart @ 1400043c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 VpciSelfManagedIoRestart(undefined8 param_1)

{
  undefined1 uVar1;
  
  uVar1 = (**(code **)(WdfFunctions_01033 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_VPCI_FDO_CONTEXT_TYPE_INFO_140010040);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x5e,
                      &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar1);
  }
  return 0;
}



===== VpciSelfManagedIoSuspend @ 140004440 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 VpciSelfManagedIoSuspend(undefined8 param_1)

{
  undefined1 uVar1;
  
  uVar1 = (**(code **)(WdfFunctions_01033 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_VPCI_FDO_CONTEXT_TYPE_INFO_140010040);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x5f,
                      &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar1);
  }
  return 0;
}



===== WPP_RECORDER_SF_DD @ 1400044b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,param_4,&param_6,4,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,2,2,&WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,param_4,&param_6,4,
                  &param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_Dq @ 140004584 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Dq(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,4,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,2,param_3,param_5,param_4,&param_6,4,&param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_dq @ 1400046b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,param_4,&param_6,4,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,2,2,&WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,param_4,&param_6,4,
                  &param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_q @ 140004784 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_q(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,0);
  return;
}



===== WPP_RECORDER_SF_qDD @ 140004880 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDD(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,4,&param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qDDd @ 1400049d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDDd
               (undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,undefined8 param_5,
               undefined1 param_6,undefined1 param_7,undefined1 param_8,undefined1 param_9)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,4,&param_8,4,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,4,&param_8,4,&param_9,
                  4,0);
  return;
}



===== WPP_RECORDER_SF_qL @ 140004b44 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qL(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,8,&param_7,4
               ,0);
  }
  WppAutoLogTrace(param_1,param_2,2,param_5,param_4,&param_6,8,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_qLD @ 140004c24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,0x48,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,5,2,&WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,0x48,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_qLqq @ 140004d18 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLqq
               (undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,4,&param_8,8,&param_9,8,0);
  }
  WppAutoLogTrace(param_1,4,param_3,param_5,param_4,&param_6,8,&param_7,4,&param_8,8,&param_9,8,0);
  return;
}



===== WPP_RECORDER_SF_qdd @ 140004e98 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qdd(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,4,&param_8,4,0);
  }
  WppAutoLogTrace(param_1,2,param_3,param_5,param_4,&param_6,8,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qdq @ 140004ff0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qdq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,8,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,param_4,&param_6,8,
                  &param_7,4,&param_8,8,0);
  return;
}



===== WPP_RECORDER_SF_qq @ 1400050e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qq(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_qqq @ 140005210 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqq(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,8,&param_8,8,0);
  }
  WppAutoLogTrace(param_1,4,param_3,param_5,param_4,&param_6,8,&param_7,8,&param_8,8,0);
  return;
}



===== WPP_RECORDER_SF_qqqq @ 140005360 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqqq
               (undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,undefined8 param_5,
               undefined1 param_6,undefined1 param_7,undefined1 param_8,undefined1 param_9)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,8,&param_8,8,&param_9,8,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,8,&param_8,8,&param_9,
                  8,0);
  return;
}



===== VpciGetTableEntry @ 1400054d0 =====

undefined8 VpciGetTableEntry(longlong param_1,uint param_2,uint *param_3,byte *param_4)

{
  uint uVar1;
  
  if ((*(char *)(param_1 + 0x12f) == '\0') && (param_2 < *(uint *)(param_1 + 0x148))) {
    uVar1 = *(uint *)(*(longlong *)(param_1 + 0x150) + (ulonglong)param_2 * 4);
    *param_3 = uVar1 & 0x7fffffff;
    *param_4 = (byte)(uVar1 >> 0x1f);
    return 0;
  }
  return 0xc000000d;
}



===== VpciGetTableSize @ 140005510 =====

undefined8 VpciGetTableSize(longlong param_1,undefined4 *param_2)

{
  if (*(char *)(param_1 + 0x12f) == '\0') {
    *param_2 = *(undefined4 *)(param_1 + 0x148);
    return 0;
  }
  return 0xc000000d;
}



===== VpciMaskTableEntry @ 140005540 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 VpciMaskTableEntry(longlong param_1,uint param_2)

{
  uint *puVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined8 *puVar6;
  undefined8 local_28;
  ulonglong uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)&local_28;
  local_28 = 0;
  uStack_20 = 0;
  if ((*(char *)(param_1 + 0x12f) == '\0') && (param_2 < *(uint *)(param_1 + 0x148))) {
    puVar1 = (uint *)(*(longlong *)(param_1 + 0x150) + (ulonglong)param_2 * 4);
    *puVar1 = *puVar1 | 0x80000000;
    puVar4 = (undefined4 *)(*(longlong *)(param_1 + 0x138) + (ulonglong)param_2 * 0x10);
    puVar5 = puVar4;
    puVar6 = &local_28;
    for (lVar3 = 4; lVar3 != 0; lVar3 = lVar3 + -1) {
      *(undefined4 *)puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = (undefined8 *)((longlong)puVar6 + 4);
    }
    uStack_20 = uStack_20 | 0x100000000;
    puVar6 = &local_28;
    for (lVar3 = 4; lVar3 != 0; lVar3 = lVar3 + -1) {
      *puVar4 = *(undefined4 *)puVar6;
      puVar6 = (undefined8 *)((longlong)puVar6 + 4);
      puVar4 = puVar4 + 1;
    }
    LOCK();
    UNLOCK();
    uVar2 = 0;
  }
  else {
    uVar2 = 0xc000000d;
  }
  return uVar2;
}



===== VpciSetTableEntry @ 1400055e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 VpciSetTableEntry(longlong param_1,uint param_2,uint param_3)

{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined4 *puVar5;
  undefined8 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined8 local_38;
  undefined4 local_30;
  uint local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)&local_38;
  local_2c = 0;
  if (((*(char *)(param_1 + 0x12f) == '\0') && (param_2 < *(uint *)(param_1 + 0x148))) &&
     (param_3 < *(uint *)(param_1 + 0x1f8))) {
    uVar4 = (ulonglong)param_2;
    uVar7 = *(uint *)(*(longlong *)(param_1 + 0x150) + uVar4 * 4) & 0x80000000;
    *(uint *)(*(longlong *)(param_1 + 0x150) + uVar4 * 4) = param_3 | uVar7;
    puVar8 = (undefined4 *)(*(longlong *)(param_1 + 0x138) + uVar4 * 0x10);
    puVar5 = puVar8;
    puVar6 = &local_38;
    for (lVar3 = 4; uVar1 = local_2c, lVar3 != 0; lVar3 = lVar3 + -1) {
      *(undefined4 *)puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = (undefined8 *)((longlong)puVar6 + 4);
    }
    local_38 = *(undefined8 *)(*(longlong *)(param_1 + 0x140) + (ulonglong)param_3 * 0x10);
    local_30 = *(undefined4 *)(*(longlong *)(param_1 + 0x140) + 8 + (ulonglong)param_3 * 0x10);
    if (uVar7 == 0) {
      local_2c = local_2c | 1;
      puVar6 = &local_38;
      puVar5 = puVar8;
      for (lVar3 = 4; lVar3 != 0; lVar3 = lVar3 + -1) {
        *puVar5 = *(undefined4 *)puVar6;
        puVar6 = (undefined8 *)((longlong)puVar6 + 4);
        puVar5 = puVar5 + 1;
      }
      LOCK();
      UNLOCK();
      local_2c = uVar1 & 0xfffffffe;
    }
    puVar6 = &local_38;
    for (lVar3 = 4; lVar3 != 0; lVar3 = lVar3 + -1) {
      *puVar8 = *(undefined4 *)puVar6;
      puVar6 = (undefined8 *)((longlong)puVar6 + 4);
      puVar8 = puVar8 + 1;
    }
    LOCK();
    UNLOCK();
    uVar2 = 0;
  }
  else {
    uVar2 = 0xc000000d;
  }
  return uVar2;
}



===== VpciUnmaskTableEntry @ 1400056e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 VpciUnmaskTableEntry(longlong param_1,uint param_2)

{
  uint *puVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined8 *puVar6;
  undefined8 local_28;
  ulonglong uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)&local_28;
  local_28 = 0;
  uStack_20 = 0;
  if ((*(char *)(param_1 + 0x12f) == '\0') && (param_2 < *(uint *)(param_1 + 0x148))) {
    puVar1 = (uint *)(*(longlong *)(param_1 + 0x150) + (ulonglong)param_2 * 4);
    *puVar1 = *puVar1 & 0x7fffffff;
    puVar4 = (undefined4 *)(*(longlong *)(param_1 + 0x138) + (ulonglong)param_2 * 0x10);
    puVar5 = puVar4;
    puVar6 = &local_28;
    for (lVar3 = 4; lVar3 != 0; lVar3 = lVar3 + -1) {
      *(undefined4 *)puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = (undefined8 *)((longlong)puVar6 + 4);
    }
    uStack_20 = uStack_20 & 0xfffffffeffffffff;
    puVar6 = &local_28;
    for (lVar3 = 4; lVar3 != 0; lVar3 = lVar3 + -1) {
      *puVar4 = *(undefined4 *)puVar6;
      puVar6 = (undefined8 *)((longlong)puVar6 + 4);
      puVar4 = puVar4 + 1;
    }
    LOCK();
    UNLOCK();
    uVar2 = 0;
  }
  else {
    uVar2 = 0xc000000d;
  }
  return uVar2;
}



===== AssignedResourcesCompletion @ 140005780 =====

void AssignedResourcesCompletion(undefined8 param_1,int param_2,int *param_3,uint param_4)

{
  longlong lVar1;
  int iVar2;
  longlong *plVar3;
  undefined8 in_stack_ffffffffffffffd8;
  
  plVar3 = (longlong *)VmbPacketGetPointer();
  lVar1 = *plVar3;
  iVar2 = GetCompletionStatus(param_2,param_3,(ulonglong)param_4);
  *(int *)(lVar1 + 0x1d0) = iVar2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x72,
                        in_stack_ffffffffffffffd8,(char)*(undefined8 *)(lVar1 + 0x30),(char)lVar1,
                        (char)iVar2);
  }
  *(uint *)(plVar3 + 2) = param_4;
  memmove((void *)(plVar3[3] + 8),param_3,(ulonglong)param_4);
  IoQueueWorkItem(*(undefined8 *)(lVar1 + 0x1d8),PdoAssignedResourcesWorkItem,1,lVar1);
  return;
}



===== Feature_CvmDmaBouncing__private_IsEnabledDeviceUsageNoInline @ 140005860 =====

ulonglong Feature_CvmDmaBouncing__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_CvmDmaBouncing__private_featureState;
  if ((Feature_CvmDmaBouncing__private_featureState & 0x10) == 0) {
    uVar1 = Feature_CvmDmaBouncing__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_CvmDmaBouncing__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_CvmDmaBouncing__private_IsEnabledFallback @ 140005898 =====

void Feature_CvmDmaBouncing__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_CvmDmaBouncing__private_descriptor);
  return;
}



===== Feature_VpciInterruptTargetFix__private_IsEnabledDeviceUsageNoInline @ 1400058b4 =====

ulonglong Feature_VpciInterruptTargetFix__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_VpciInterruptTargetFix__private_featureState;
  if ((Feature_VpciInterruptTargetFix__private_featureState & 0x10) == 0) {
    uVar1 = Feature_VpciInterruptTargetFix__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_VpciInterruptTargetFix__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_VpciInterruptTargetFix__private_IsEnabledFallback @ 1400058ec =====

void Feature_VpciInterruptTargetFix__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_VpciInterruptTargetFix__private_descriptor)
  ;
  return;
}



===== PdoAssignResources @ 140005908 =====

uint PdoAssignResources(uint *param_1)

{
  uint uVar1;
  longlong lVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined2 uVar6;
  
  lVar2 = VmbPacketGetPointer(*(undefined8 *)(param_1 + 0x40));
  uVar3 = PdoRunStateMachine((int *)param_1,2);
  if ((char)uVar3 == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x73,
                        &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_1);
    }
    return 0xc0000184;
  }
  KeWaitForSingleObject(param_1 + 0x6e,0,0,0,0);
  uVar1 = param_1[0x74];
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar1;
    }
    uVar6 = 0x74;
  }
  else {
    lVar2 = *(longlong *)(lVar2 + 0x18);
    if (*(uint *)(*(longlong *)(param_1 + 0xc) + 0x18) < 0x10002) {
      uVar4 = (ulonglong)*(uint *)(lVar2 + 0x88);
      while ((int)uVar4 != 0) {
        uVar4 = (ulonglong)((int)uVar4 - 1);
        *(undefined2 *)(lVar2 + 0x90 + uVar4 * 0x48) = *(undefined2 *)(lVar2 + 0x90 + uVar4 * 0x10);
        *(undefined2 *)(lVar2 + 0x92 + uVar4 * 0x48) = *(undefined2 *)(lVar2 + 0x92 + uVar4 * 0x10);
        *(undefined4 *)(lVar2 + 0x94 + uVar4 * 0x48) = *(undefined4 *)(lVar2 + 0x94 + uVar4 * 0x10);
        *(undefined8 *)(lVar2 + 0x98 + uVar4 * 0x48) = *(undefined8 *)(lVar2 + 0x98 + uVar4 * 0x10);
      }
    }
    uVar4 = Feature_VpciVscBootDiskHibernation__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar4 != 0) && ((char)param_1[0xd0] != '\0')) {
      if (param_1[0xc6] != 0) {
        return uVar1;
      }
      if (param_1[0xc5] != 0) {
        return uVar1;
      }
    }
    uVar4 = Feature_VpciVscRelaxedInterruptLimit__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 == 0) {
      lVar5 = 0;
    }
    else {
      lVar5 = *(longlong *)(param_1 + 0x48);
    }
    uVar4 = Feature_VpciVscRelaxedInterruptLimit__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = param_1[0x4a];
    }
    uVar4 = PdoUpdateInterruptTranslations(param_1,*(int *)(lVar2 + 0x88),lVar2 + 0x90,uVar1,lVar5);
    uVar1 = (uint)uVar4;
    if (-1 < (int)uVar1) {
      return uVar1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar1;
    }
    uVar6 = 0x75;
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar6,
                     &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_1,(char)uVar1);
  return uVar1;
}



===== PdoCheckReadWriteQueue @ 140005b10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdoCheckReadWriteQueue(undefined4 *param_1)

{
  undefined4 *puVar1;
  longlong lVar2;
  undefined1 uVar3;
  ushort uVar4;
  int iVar5;
  undefined1 auStackY_88 [32];
  undefined8 local_58;
  ulonglong local_50 [3];
  undefined8 uStack_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_88;
  puVar1 = param_1 + 100;
  local_58 = 0;
  local_50[0] = 0;
  local_50[1] = 0;
  local_30 = 0;
  local_50[2] = 0;
  uStack_38 = 0;
  do {
    uVar3 = KeAcquireSpinLockRaiseToDpc(puVar1);
    lVar2 = *(longlong *)(param_1 + 0x62);
    if (lVar2 == 0) {
LAB_140005cdf:
      KeReleaseSpinLock(puVar1,uVar3);
      return;
    }
    iVar5 = (**(code **)(WdfFunctions_01033 + 0x4f0))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x5e),&local_58);
    if (iVar5 < 0) {
      if ((iVar5 != -0x7fffffe6) &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x21,
                          &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)iVar5);
      }
      goto LAB_140005cdf;
    }
    *(undefined8 *)(param_1 + 0x62) = 0;
    KeReleaseSpinLock(puVar1,uVar3);
    local_50[1] = 0;
    local_30 = 0;
    local_50[2] = 0;
    uStack_38 = 0;
    if (WdfClientVersionHigherThanFramework == '\0') {
      uVar4 = 0x28;
    }
    else if (WdfStructureCount < 0x34) {
      uVar4 = 0xffff;
    }
    else {
      uVar4 = *(ushort *)(WdfStructures + 0x198);
    }
    local_50[0] = (ulonglong)uVar4;
    (**(code **)(WdfFunctions_01033 + 0x850))(WdfDriverGlobals,local_58,local_50);
    if ((int)uStack_38 == 0x2ac00f) {
      iVar5 = PdoIoctlWriteBlock(param_1,local_58,lVar2);
    }
    else {
      iVar5 = PdoIoctlReadBlock(param_1,local_58,lVar2);
    }
    if (iVar5 == 0x103) {
      return;
    }
    (**(code **)(WdfFunctions_01033 + 0x838))(WdfDriverGlobals,local_58,iVar5);
    uVar3 = KeAcquireSpinLockRaiseToDpc(puVar1);
    *(longlong *)(param_1 + 0x62) = lVar2;
    KeReleaseSpinLock(puVar1,uVar3);
  } while( true );
}



===== PdoCompleteSelfSentPnpIrp @ 140005d20 =====

undefined8 PdoCompleteSelfSentPnpIrp(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  IoQueueWorkItem(*(undefined8 *)(param_3 + 0x210),PdoSelfSentIrpCompletionWorkItem,1,param_3);
  return 0xc0000016;
}



===== PdoCompleteSyncIrp @ 140005d60 =====

undefined8 PdoCompleteSyncIrp(undefined8 param_1,longlong param_2)

{
  *(undefined8 *)(*(longlong *)(param_2 + 0x48) + 8) = *(undefined8 *)(param_2 + 0x38);
  **(undefined4 **)(param_2 + 0x48) = *(undefined4 *)(param_2 + 0x30);
  KeSetEvent(*(undefined8 *)(param_2 + 0x50),0,0);
  return 0xc0000016;
}



===== PdoContextCleanup @ 140005db0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdoContextCleanup(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01033 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qLqq
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,2,0x22,
               &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)lVar1,
               (char)*(undefined4 *)(lVar1 + 0x28),(char)*(undefined8 *)(lVar1 + 0x30),
               (char)SystemReserved1[0xf]);
  }
  if (*(longlong *)(lVar1 + 0x1f0) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0x1f0),0);
    *(undefined8 *)(lVar1 + 0x1f0) = 0;
  }
  if (*(longlong *)(lVar1 + 0xf8) != 0) {
    VpciPacketDestroy(*(longlong *)(lVar1 + 0xf8));
    *(undefined8 *)(lVar1 + 0xf8) = 0;
  }
  if (*(longlong *)(lVar1 + 0x100) != 0) {
    VpciPacketDestroy(*(longlong *)(lVar1 + 0x100));
    *(undefined8 *)(lVar1 + 0x100) = 0;
  }
  if (*(longlong *)(lVar1 + 0x180) != 0) {
    VpciPacketDestroy(*(longlong *)(lVar1 + 0x180));
    *(undefined8 *)(lVar1 + 0x180) = 0;
  }
  if (*(longlong *)(lVar1 + 0xf0) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0xf0),0x69637056);
    *(undefined8 *)(lVar1 + 0xf0) = 0;
  }
  if (*(longlong *)(lVar1 + 0xe8) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0xe8),0x69637056);
    *(undefined8 *)(lVar1 + 0xe8) = 0;
  }
  return;
}



===== PdoContextDestroy @ 140005f00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdoContextDestroy(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01033 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,2,0x23,
                        &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)lVar1,
                        (char)*(undefined8 *)(lVar1 + 0x30),(char)SystemReserved1[0xf]);
  }
  if (*(longlong *)(lVar1 + 0x198) != 0) {
    IoFreeIrp();
    *(undefined8 *)(lVar1 + 0x198) = 0;
  }
  if (*(longlong *)(lVar1 + 0x1d8) != 0) {
    IoFreeWorkItem();
    *(undefined8 *)(lVar1 + 0x1d8) = 0;
  }
  if (*(longlong *)(lVar1 + 0x210) != 0) {
    IoFreeWorkItem();
    *(undefined8 *)(lVar1 + 0x210) = 0;
  }
  if (*(longlong *)(lVar1 + 0x1e0) != 0) {
    IoFreeWorkItem();
    *(undefined8 *)(lVar1 + 0x1e0) = 0;
  }
  return;
}



===== PdoD0Entry @ 140006010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint PdoD0Entry(undefined8 param_1)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong lVar6;
  byte bVar7;
  undefined2 uVar8;
  
  puVar3 = (uint *)(**(code **)(WdfFunctions_01033 + 0x650))
                             (WdfDriverGlobals,param_1,PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8
                             );
  iVar1 = (**(code **)(WdfFunctions_01033 + 0xc20))(WdfDriverGlobals,param_1);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qDDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  if (iVar1 == 3) {
    if (puVar3[10] == 9) {
      puVar3[10] = 10;
    }
    uVar4 = Feature_VpciVscBootDiskHibernation__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar4 != 0) && (puVar3[0xc6] != 0)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x94,
                          &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)puVar3);
      }
      uVar5 = (**(code **)(WdfFunctions_01033 + 0x650))
                        (WdfDriverGlobals,*(undefined8 *)(puVar3 + 0x42),
                         PTR__WDF_VPCI_PDO_PACKET_CONTEXT_TYPE_INFO_140010068);
      *(undefined8 *)(puVar3 + 0x44) = uVar5;
    }
  }
  puVar3[0x38] = 1;
  if ((puVar3[10] == 9) || (uVar2 = PdoAssignResources(puVar3), -1 < (int)uVar2)) {
    puVar3[0x74] = 0x103;
    KeClearEvent(puVar3 + 0x6e);
    PdoSendPowerMessage(puVar3);
    KeWaitForSingleObject(puVar3 + 0x6e,0,0,0,0);
    uVar2 = puVar3[0x74];
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar2;
      }
      uVar8 = 0x96;
    }
    else {
      lVar6 = VmbPacketGetPointer(*(undefined8 *)(puVar3 + 0x40));
      uVar2 = PdoProgramInterrupts
                        (puVar3,*(uint *)(*(longlong *)(lVar6 + 0x18) + 0x88),
                         *(longlong *)(lVar6 + 0x18) + 0x90);
      if (-1 < (int)uVar2) {
        uVar4 = Feature_VpciVscBootDiskHibernation__private_IsEnabledDeviceUsageNoInline();
        if (((int)uVar4 != 0) && (iVar1 == 3)) {
          *(undefined1 *)(puVar3 + 0xd0) = 0;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return uVar2;
        }
        uVar8 = 0x98;
        bVar7 = 4;
        goto LAB_140006244;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar2;
      }
      uVar8 = 0x97;
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar2;
    }
    uVar8 = 0x95;
  }
  bVar7 = 2;
LAB_140006244:
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar7,2,uVar8,
                     &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)puVar3,(char)uVar2);
  return uVar2;
}



===== PdoDeactivateDevice @ 140006288 =====

int PdoDeactivateDevice(undefined4 *param_1,undefined1 *param_2,undefined1 *param_3)

{
  int iVar1;
  
  iVar1 = param_1[0x38];
  *param_2 = 0;
  *param_3 = 0;
  if (iVar1 == 1) {
    PdoDisableInterrupts(param_1);
    *param_3 = 1;
    iVar1 = PdoSendSynchronousPowerPacket(param_1,4);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0xd3,
                         &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_1,(char)iVar1)
      ;
      goto LAB_14000632c;
    }
    PdoFreeMsixMetadata((longlong)param_1);
    *param_2 = 1;
  }
  iVar1 = 0;
LAB_14000632c:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qDDd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0xd4,
               &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_1,*param_2,*param_3,
               (char)iVar1);
  }
  return iVar1;
}



===== PdoDisableInterrupts @ 140006394 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PdoDisableInterrupts(undefined4 *param_1)

{
  longlong *plVar1;
  undefined1 auStackY_68 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_68;
  plVar1 = (longlong *)(param_1 + 0xc);
  local_20 = 0;
  local_18 = 0;
  local_28 = 0;
  local_38 = 0;
  uStack_30 = 0;
  if (*(byte *)((longlong)param_1 + 0x12d) != 0) {
    FdoReadConfig(*plVar1,*param_1,(undefined4 *)((longlong)&local_38 + 2),
                  (ulonglong)(*(byte *)((longlong)param_1 + 0x12d) + 2),2);
    local_38 = local_38 & 0xfffffffffffeffff;
    FdoWriteConfig(*plVar1,*param_1,(undefined4 *)((longlong)&local_38 + 2),
                   (ulonglong)(*(byte *)((longlong)param_1 + 0x12d) + 2),2);
  }
  if (*(byte *)((longlong)param_1 + 0x12e) != 0) {
    FdoReadConfig(*plVar1,*param_1,(undefined4 *)((longlong)&local_20 + 2),
                  (ulonglong)(*(byte *)((longlong)param_1 + 0x12e) + 2),2);
    local_20 = local_20 & 0xffffffff7fffffff;
    FdoWriteConfig(*plVar1,*param_1,(undefined4 *)((longlong)&local_20 + 2),
                   (ulonglong)(*(byte *)((longlong)param_1 + 0x12e) + 2),2);
  }
  return;
}



===== PdoEnableInterrupts @ 140006490 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PdoEnableInterrupts(undefined4 *param_1)

{
  byte bVar1;
  undefined8 *puVar2;
  undefined1 auStackY_68 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_68;
  local_20 = 0;
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  if (*(char *)((longlong)param_1 + 0x12f) == '\0') {
    if (*(byte *)((longlong)param_1 + 0x12e) == 0) {
      return;
    }
    FdoReadConfig(*(longlong *)(param_1 + 0xc),*param_1,(undefined4 *)((longlong)&local_20 + 2),
                  (ulonglong)(*(byte *)((longlong)param_1 + 0x12e) + 2),2);
    bVar1 = *(byte *)((longlong)param_1 + 0x12e);
    puVar2 = &local_20;
    local_20 = local_20 | 0x80000000;
  }
  else {
    FdoReadConfig(*(longlong *)(param_1 + 0xc),*param_1,(undefined4 *)((longlong)&local_38 + 2),
                  (ulonglong)(*(byte *)((longlong)param_1 + 0x12d) + 2),2);
    local_38 = local_38 | 0x10000;
    puVar2 = &local_38;
    bVar1 = *(byte *)((longlong)param_1 + 0x12d);
  }
  FdoWriteConfig(*(longlong *)(param_1 + 0xc),*param_1,(undefined4 *)((longlong)puVar2 + 2),
                 (ulonglong)(bVar1 + 2),2);
  return;
}



===== PdoFreeMsixMetadata @ 140006570 =====

void PdoFreeMsixMetadata(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x138) != 0) {
    MmUnmapIoSpace(*(longlong *)(param_1 + 0x138),(ulonglong)*(uint *)(param_1 + 0x148) << 4);
    *(undefined8 *)(param_1 + 0x138) = 0;
    *(undefined4 *)(param_1 + 0x148) = 0;
  }
  if (*(longlong *)(param_1 + 0x150) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x150),0x69637056);
    *(undefined8 *)(param_1 + 0x150) = 0;
  }
  if (*(longlong *)(param_1 + 0x140) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x140),0x69637056);
    *(undefined8 *)(param_1 + 0x140) = 0;
  }
  return;
}



===== PdoGetVMBusUniqueLocationString @ 140006604 =====

uint PdoGetVMBusUniqueLocationString
               (longlong param_1,uint *param_2,undefined8 param_3,wchar_t *param_4,
               undefined1 *param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined2 uVar5;
  longlong lVar6;
  wchar_t *pwVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined8 local_38 [2];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  local_28 = 0;
  uStack_20 = 0;
  RtlInitUnicodeString(&local_18);
  uVar4 = 0;
  RtlInitUnicodeString(&local_28);
  if (param_4 == (wchar_t *)0x0) {
    uVar1 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,1,0xcf,
                          &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_1,0xc0,0xc0);
    }
    goto LAB_140006834;
  }
  uVar1 = RtlStringFromGUID(&GUID_VPCI_VSP_CHANNEL_TYPE,&local_28);
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140006834;
    uVar5 = 0xd0;
  }
  else {
    uVar1 = RtlStringFromGUID(param_1 + 0x30,&local_18);
    if ((int)uVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140006834;
      uVar5 = 0xd1;
    }
    else {
      uVar3 = *param_2 & 0x1f;
      uVar2 = *param_2 >> 5 & 7;
      puVar9 = &local_18;
      puVar8 = &local_28;
      pwVar7 = L"VMBUS(%wZ#%wZ)#VPCI(%.2X%.2X)";
      uVar1 = RtlStringCchPrintfExW
                        (param_4,0x60,(undefined8 *)0x0,(ulonglong *)0x0,0x200,
                         L"VMBUS(%wZ#%wZ)#VPCI(%.2X%.2X)",(char)puVar8);
      if (-1 < (int)uVar1) {
        lVar6 = 0;
        uVar4 = 0;
        KeWaitForSingleObject(&VpciGlobalLock,0,0,0,0,pwVar7,puVar8,puVar9,uVar3,uVar2);
        uVar1 = VscGetDeviceProxyPrefix(param_4,uVar4,local_38,lVar6);
        KeSetEvent(&VpciGlobalLock,0,0);
        if (uVar1 == 0xc0000225) {
          uVar1 = 0;
          *param_5 = 0;
        }
        else if (-1 < (int)uVar1) {
          *param_5 = 1;
        }
        goto LAB_140006834;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140006834;
      uVar5 = 0xd2;
    }
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar5,
                     &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_1,(char)uVar1);
LAB_140006834:
  RtlFreeUnicodeString(&local_28);
  RtlFreeUnicodeString(&local_18);
  return uVar1;
}



===== PdoIoctlReadBlock @ 14000687c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PdoIoctlReadBlock(undefined4 *param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  undefined2 uVar4;
  undefined1 auStackY_88 [32];
  undefined4 uVar6;
  undefined8 uVar5;
  undefined1 uVar7;
  undefined4 *local_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_88;
  local_40 = 0;
  local_48 = (undefined4 *)0x0;
  iVar2 = (**(code **)(WdfFunctions_01033 + 0x868))(WdfDriverGlobals,param_2,8,&local_48);
  uVar7 = SUB81(param_1,0);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar2;
    }
    uVar4 = 0x13;
  }
  else {
    uVar1 = local_48[1];
    if (0x80 < uVar1) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x14,
                           &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar7,(char)uVar1);
      }
      return -0x3ffffdfa;
    }
    uVar6 = 0;
    iVar2 = (**(code **)(WdfFunctions_01033 + 0x870))(WdfDriverGlobals,param_2,uVar1,&local_40);
    if (-1 < iVar2) {
      lVar3 = VmbPacketGetPointer(param_3);
      *(undefined8 *)(lVar3 + 8) = param_2;
      local_38 = 0x42490009;
      local_2c = local_48[1];
      local_34 = *local_48;
      local_30 = *param_1;
      VmbPacketSetCompletionRoutine(param_3,PdoReadBlockCompletion);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar6 = 1;
        WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x16,
                           &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,
                           (char)*(undefined8 *)(param_1 + 0xc),uVar7);
      }
      uVar5 = CONCAT44(uVar6,1);
      iVar2 = VmbPacketSend(param_3,&local_38,0x10);
      if (-1 < iVar2) {
        return 0x103;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar2;
      }
      WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0x17,uVar5,
                          (char)*(undefined8 *)(param_1 + 0xc),uVar7,(char)iVar2);
      return iVar2;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar2;
    }
    uVar4 = 0x15;
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar4,
                     &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar7,(char)iVar2);
  return iVar2;
}



===== PdoIoctlWriteBlock @ 140006af4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PdoIoctlWriteBlock(undefined4 *param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  longlong lVar2;
  undefined1 auStackY_118 [32];
  undefined4 uVar4;
  undefined8 uVar3;
  undefined1 uVar5;
  undefined4 *local_d8 [2];
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined1 local_b8 [144];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_118;
  local_d8[0] = (undefined4 *)0x0;
  uVar4 = 0;
  iVar1 = (**(code **)(WdfFunctions_01033 + 0x868))(WdfDriverGlobals,param_2,0xc,local_d8);
  uVar5 = SUB81(param_1,0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x1d,
                         &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar5,(char)iVar1);
    }
  }
  else {
    if (0x80 < (uint)local_d8[0][1]) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x1e,
                           &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar5,
                           (char)local_d8[0][1]);
      }
      return -0x3ffffdfa;
    }
    lVar2 = VmbPacketGetPointer(param_3);
    *(undefined8 *)(lVar2 + 8) = param_2;
    iVar1 = local_d8[0][1];
    local_c8 = 0x4249000a;
    local_bc = local_d8[0][1];
    local_c4 = *local_d8[0];
    local_c0 = *param_1;
    memmove(local_b8,local_d8[0] + 2,(ulonglong)(uint)local_d8[0][1]);
    VmbPacketSetCompletionRoutine(param_3,PdoWriteBlockCompletion);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar4 = 1;
      WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x1f,
                         &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,
                         (char)*(undefined8 *)(param_1 + 0xc),uVar5);
    }
    uVar3 = CONCAT44(uVar4,1);
    iVar1 = VmbPacketSend(param_3,&local_c8,iVar1 + 0x14,0);
    if (-1 < iVar1) {
      return 0x103;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x20,uVar3,
                          (char)*(undefined8 *)(param_1 + 0xc),uVar5,(char)iVar1);
    }
  }
  return iVar1;
}



===== PdoPowerStateCompletion @ 140006d40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdoPowerStateCompletion(undefined8 param_1,int param_2,int *param_3,ulonglong param_4)

{
  longlong lVar1;
  int iVar2;
  longlong *plVar3;
  undefined8 in_stack_ffffffffffffffd8;
  
  plVar3 = (longlong *)VmbPacketGetPointer();
  lVar1 = *plVar3;
  iVar2 = GetCompletionStatus(param_2,param_3,param_4 & 0xffffffff);
  *(int *)(lVar1 + 0x1d0) = iVar2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0xa4,
                        in_stack_ffffffffffffffd8,(char)*(undefined8 *)(lVar1 + 0x30),(char)lVar1,
                        (char)iVar2);
  }
  KeSetEvent(lVar1 + 0x1b8,0,0);
  (**(code **)(WdfFunctions_01033 + 0x670))
            (WdfDriverGlobals,*(undefined8 *)(lVar1 + 8),0xffffffffdead0001,0x1f89,
             "onecore\\vm\\dv\\vpci\\vsc\\sys\\pdo.c");
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xe,0xa5,
                      &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)lVar1);
  }
  *(undefined4 *)(plVar3 + 2) = 0;
  return;
}



===== PdoPreprocessPnp @ 140006e80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint PdoPreprocessPnp(undefined8 param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  char cVar3;
  uint uVar4;
  int *piVar5;
  
  piVar5 = (int *)(**(code **)(WdfFunctions_01033 + 0x650))
                            (WdfDriverGlobals,param_1,PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8)
  ;
  puVar1 = *(undefined8 **)(param_2 + 0xb8);
  cVar3 = *(char *)((longlong)puVar1 + 1);
  if (cVar3 == '\0') {
    if (*(char *)((longlong)piVar5 + 0x342) != '\0') {
      puVar1[-9] = *puVar1;
      puVar1[-8] = puVar1[1];
      puVar1[-7] = puVar1[2];
      puVar1[-6] = puVar1[3];
      *(undefined4 *)(puVar1 + -5) = *(undefined4 *)(puVar1 + 4);
      *(undefined4 *)((longlong)puVar1 + -0x24) = *(undefined4 *)((longlong)puVar1 + 0x24);
      *(undefined4 *)(puVar1 + -4) = *(undefined4 *)(puVar1 + 5);
      *(undefined4 *)((longlong)puVar1 + -0x1c) = *(undefined4 *)((longlong)puVar1 + 0x2c);
      puVar1[-3] = puVar1[6];
      *(undefined1 *)((longlong)puVar1 + -0x45) = 0;
      lVar2 = *(longlong *)(param_2 + 0xb8);
      *(undefined8 *)(lVar2 + -8) = 0;
      *(code **)(lVar2 + -0x10) = PdoStartIrpCompletionRoutine;
      *(undefined1 *)(lVar2 + -0x45) = 0x40;
      goto LAB_140006f88;
    }
LAB_140006f7a:
    *(undefined8 **)(param_2 + 0xb8) = puVar1 + 9;
  }
  else {
    if (cVar3 == '\x03') {
      PdoRunStateMachine(piVar5,8);
    }
    else {
      if (cVar3 != '\a') {
        if ((cVar3 == '\x0f') || (cVar3 == '\x10')) {
          uVar4 = PdoPreprocessReadWriteConfig(param_1,param_2);
          return uVar4;
        }
        goto LAB_140006f7a;
      }
      if (((*(int *)(puVar1 + 1) == 0) && ((char)piVar5[0x87] != '\0')) &&
         (cVar3 = PnpBlockerBroadcastBlockingIsReady((longlong)piVar5,param_2), cVar3 != '\0')) {
        return 0x103;
      }
    }
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  }
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
LAB_140006f88:
  uVar4 = (**(code **)(WdfFunctions_01033 + 0x110))(WdfDriverGlobals,param_1,param_2);
  return uVar4;
}



===== PdoPreprocessPower @ 140006fc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 PdoPreprocessPower(undefined8 param_1,longlong param_2)

{
  byte *pbVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  lVar3 = (**(code **)(WdfFunctions_01033 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  if ((((*(char *)(lVar2 + 1) == '\x02') &&
       (*(int *)(*(longlong *)(lVar3 + 0x30) + 0x18) == 0x10000)) && (*(int *)(lVar2 + 0x10) == 0))
     && (*(int *)(lVar2 + 0x18) == 6)) {
    *(longlong *)(lVar3 + 0x1e8) = param_2;
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    IoQueueWorkItem(*(undefined8 *)(lVar3 + 0x1e0),PdoPowerWorkItem,1,lVar3);
    uVar4 = 0x103;
  }
  else {
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = lVar2 + 0x48;
    uVar4 = (**(code **)(WdfFunctions_01033 + 0x110))(WdfDriverGlobals,param_1,param_2);
  }
  return uVar4;
}



===== PdoProgramInterrupts @ 14000709c =====

int PdoProgramInterrupts(undefined4 *param_1,uint param_2,ulonglong param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  PdoDisableInterrupts(param_1);
  if (param_2 == 0) {
    return 0;
  }
  if ((uint)param_1[0x7e] < param_2) {
    param_2 = param_1[0x7e];
  }
  if (*(char *)((longlong)param_1 + 0x12f) == '\0') {
    if (*(char *)((longlong)param_1 + 0x12e) == '\0') {
      return 0;
    }
    uVar2 = PdoProgramMsiXInterrupt(param_1,param_2,param_3);
    iVar1 = (int)uVar2;
  }
  else {
    uVar2 = PdoProgramMsiInterrupt(param_1,param_2,param_3);
    iVar1 = (int)uVar2;
  }
  if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x86,
                       &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_1,(char)iVar1);
  }
  return iVar1;
}



===== PdoProgramMsiInterrupt @ 140007164 =====

undefined8 PdoProgramMsiInterrupt(undefined4 *param_1,uint param_2,ulonglong param_3)

{
  undefined8 uVar1;
  byte bVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined4 *puVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  undefined4 uStackX_c;
  undefined8 local_38;
  undefined1 auStack_30 [8];
  undefined8 local_28 [2];
  
  local_28[0] = 0;
  local_38 = 0;
  auStack_30 = (undefined1  [8])0x0;
  FdoReadConfig(*(longlong *)(param_1 + 0xc),*param_1,(undefined4 *)((longlong)&local_38 + 2),
                (ulonglong)(*(byte *)((longlong)param_1 + 0x12d) + 2),2);
  if ((local_38 & 0xe0000) != 0) {
    for (uVar4 = param_3 + ((ulonglong)param_2 - 1) * 0x48; param_3 <= uVar4; uVar4 = uVar4 - 0x48)
    {
      if (1 < *(ushort *)(uVar4 + 2)) goto LAB_1400071dd;
    }
  }
  uVar4 = param_3;
LAB_1400071dd:
  uVar1 = *(undefined8 *)(uVar4 + 8);
  local_38 = CONCAT44((int)uVar1,(undefined4)local_38);
  FdoWriteConfig(*(longlong *)(param_1 + 0xc),*param_1,(undefined4 *)((longlong)&local_38 + 4),
                 (ulonglong)(*(byte *)((longlong)param_1 + 0x12d) + 4),4);
  puVar5 = (undefined4 *)auStack_30;
  uVar7 = (ulonglong)(*(byte *)((longlong)param_1 + 0x12d) + 8);
  if ((local_38 & 0x800000) == 0) {
    auStack_30._0_2_ = *(undefined2 *)(uVar4 + 4);
  }
  else {
    uStackX_c = (undefined4)((ulonglong)uVar1 >> 0x20);
    auStack_30._0_4_ = uStackX_c;
    FdoWriteConfig(*(longlong *)(param_1 + 0xc),*param_1,puVar5,uVar7,4);
    puVar5 = (undefined4 *)(auStack_30 + 4);
    auStack_30._4_2_ = *(undefined2 *)(uVar4 + 4);
    uVar7 = (ulonglong)(*(byte *)((longlong)param_1 + 0x12d) + 0xc);
  }
  FdoWriteConfig(*(longlong *)(param_1 + 0xc),*param_1,puVar5,uVar7,2);
  if ((local_38 & 0x1000000) != 0) {
    uVar3 = ~((1 << (*(byte *)(uVar4 + 2) & 0x1f)) - 1U);
    if ((local_38 & 0x800000) == 0) {
      auStack_30._4_4_ = uVar3;
      puVar6 = (undefined8 *)(auStack_30 + 4);
      uVar3 = *(byte *)((longlong)param_1 + 0x12d) + 0xc;
    }
    else {
      local_28[0] = CONCAT44(local_28[0]._4_4_,uVar3);
      puVar6 = local_28;
      uVar3 = *(byte *)((longlong)param_1 + 0x12d) + 0x10;
    }
    FdoWriteConfig(*(longlong *)(param_1 + 0xc),*param_1,(undefined4 *)puVar6,(ulonglong)uVar3,4);
  }
  bVar2 = RtlFindMostSignificantBit(*(undefined2 *)(uVar4 + 2));
  if (bVar2 == 0xff) {
    uVar4 = Feature_CvmDmaBouncing__private_IsEnabledDeviceUsageNoInline();
    bVar2 = 0;
    if ((int)uVar4 != 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x8e,
                          &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_1);
      }
      return 0xc000000d;
    }
  }
  local_38 = CONCAT44(local_38._4_4_,
                      CONCAT22((ushort)(bVar2 & 7) << 4 | local_38._2_2_ & 0xff8f,
                               (undefined2)local_38)) | 0x10000;
  FdoWriteConfig(*(longlong *)(param_1 + 0xc),*param_1,(undefined4 *)((longlong)&local_38 + 2),
                 (ulonglong)(*(byte *)((longlong)param_1 + 0x12d) + 2),2);
  return 0;
}



===== PdoProgramMsiXInterrupt @ 140007380 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 PdoProgramMsiXInterrupt(undefined4 *param_1,uint param_2,longlong param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined4 *puVar4;
  undefined8 *puVar5;
  undefined4 *puVar6;
  undefined2 uVar7;
  ulonglong uVar8;
  uint uVar9;
  ushort *puVar10;
  undefined8 uVar11;
  uint uVar12;
  undefined1 local_c8 [32];
  uint local_88;
  ulonglong local_80;
  undefined8 local_68;
  undefined4 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)local_c8;
  local_68 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_60 = 0;
  FdoReadConfig(*(longlong *)(param_1 + 0xc),*param_1,(undefined4 *)((longlong)&local_68 + 4),
                (ulonglong)(*(byte *)((longlong)param_1 + 0x12e) + 4),4);
  FdoReadConfig(*(longlong *)(param_1 + 0xc),*param_1,(undefined4 *)((longlong)&local_68 + 2),
                (ulonglong)(*(byte *)((longlong)param_1 + 0x12e) + 2),2);
  uVar12 = param_1[0x7e];
  uVar9 = (local_68._2_2_ & 0x7ff) + 1;
  uVar8 = (ulonglong)(local_68._4_4_ & 7);
  if ((local_68._4_4_ & 7) < 6) {
    if (((*(char *)(param_1 + uVar8 * 5 + 0x1a) - 3U & 0xfb) == 0) &&
       (uVar9 * 0x10 <= (uint)param_1[uVar8 * 5 + 0x1d])) {
      uVar1 = Feature_VpciVscBootDiskHibernation__private_IsEnabledDeviceUsageNoInline();
      if ((((int)uVar1 != 0) && (*(char *)(param_1 + 0xd0) != '\0')) && (param_1[0xc6] != 0)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x91,
                            &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_1);
        }
        PdoFreeMsixMetadata((longlong)param_1);
      }
      lVar2 = ExAllocatePool2(0x40,(ulonglong)uVar9 << 2,0x69637056);
      *(longlong *)(param_1 + 0x54) = lVar2;
      if (lVar2 != 0) {
        lVar2 = ExAllocatePool2(0x40,(ulonglong)uVar12 << 4,0x69637056);
        *(longlong *)(param_1 + 0x50) = lVar2;
        if ((lVar2 != 0) &&
           (lVar2 = MmMapIoSpaceEx((local_68 >> 0x20 & 0xfffffff8) +
                                   *(longlong *)(param_1 + uVar8 * 5 + 0x1b),uVar9 * 0x10,0x204),
           lVar2 != 0)) {
          *(longlong *)(param_1 + 0x4e) = lVar2;
          uVar8 = 0;
          uVar12 = 0;
          param_1[0x52] = uVar9;
          if (param_2 != 0) {
            local_80 = (ulonglong)param_2;
            puVar10 = (ushort *)(param_3 + 2);
            do {
              local_88 = 0;
              uVar1 = uVar8;
              if (*puVar10 != 0) {
                do {
                  RtlSetVolatileMemory(&local_58,0,0x10);
                  local_58 = *(undefined8 *)(puVar10 + 3);
                  uVar12 = (uint)uVar1;
                  uStack_50 = CONCAT44(uStack_50._4_4_,*(int *)(puVar10 + 1) + local_88) &
                              0xfffffffeffffffff;
                  if (uVar12 < uVar9) {
                    puVar5 = &local_58;
                    puVar4 = (undefined4 *)(lVar2 + uVar1 * 0x10);
                    for (lVar3 = 4; lVar3 != 0; lVar3 = lVar3 + -1) {
                      *puVar4 = *(undefined4 *)puVar5;
                      puVar5 = (undefined8 *)((longlong)puVar5 + 4);
                      puVar4 = puVar4 + 1;
                    }
                    LOCK();
                    UNLOCK();
                    *(uint *)(*(longlong *)(param_1 + 0x54) + uVar1 * 4) = uVar12;
                  }
                  local_88 = local_88 + 1;
                  uVar8 = (ulonglong)(uVar12 + 1);
                  puVar5 = (undefined8 *)(*(longlong *)(param_1 + 0x50) + uVar1 * 0x10);
                  *puVar5 = local_58;
                  puVar5[1] = uStack_50;
                  uVar1 = uVar8;
                } while (local_88 < *puVar10);
              }
              uVar12 = (uint)uVar8;
              puVar10 = puVar10 + 0x24;
              local_80 = local_80 - 1;
            } while (local_80 != 0);
          }
          if (uVar12 < uVar9) {
            RtlSetVolatileMemory(&local_58,0,0x10);
            local_58 = *(undefined8 *)(param_3 + 8);
            lVar3 = (ulonglong)uVar12 * 4;
            puVar4 = (undefined4 *)((ulonglong)uVar12 * 0x10 + lVar2);
            uStack_50 = CONCAT44(uStack_50._4_4_,*(undefined4 *)(param_3 + 4)) & 0xfffffffeffffffff;
            uVar8 = (ulonglong)(uVar9 - uVar12);
            do {
              puVar5 = &local_58;
              puVar6 = puVar4;
              for (lVar2 = 4; lVar2 != 0; lVar2 = lVar2 + -1) {
                *puVar6 = *(undefined4 *)puVar5;
                puVar5 = (undefined8 *)((longlong)puVar5 + 4);
                puVar6 = puVar6 + 1;
              }
              LOCK();
              UNLOCK();
              puVar4 = puVar4 + 4;
              *(undefined4 *)(lVar3 + *(longlong *)(param_1 + 0x54)) = 0;
              lVar3 = lVar3 + 4;
              uVar8 = uVar8 - 1;
            } while (uVar8 != 0);
          }
          FdoReadConfig(*(longlong *)(param_1 + 0xc),*param_1,
                        (undefined4 *)((longlong)&local_68 + 2),
                        (ulonglong)(*(byte *)((longlong)param_1 + 0x12e) + 2),2);
          local_68 = local_68 | 0x80000000;
          FdoWriteConfig(*(longlong *)(param_1 + 0xc),*param_1,
                         (undefined4 *)((longlong)&local_68 + 2),
                         (ulonglong)(*(byte *)((longlong)param_1 + 0x12e) + 2),2);
          return 0;
        }
      }
      uVar11 = 0xc000009a;
      goto LAB_14000773c;
    }
    uVar11 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000773c;
    uVar7 = 0x90;
  }
  else {
    uVar11 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000773c;
    uVar7 = 0x8f;
  }
  uVar11 = 0xc000000d;
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar7,
                     &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_1,0xd);
LAB_14000773c:
  PdoFreeMsixMetadata((longlong)param_1);
  return uVar11;
}



===== PdoReactivateDevice @ 140007778 =====

int PdoReactivateDevice(undefined4 *param_1,char param_2,char param_3)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  undefined2 uVar4;
  
  if (param_2 == '\0') {
    if (param_3 != '\0') {
      PdoEnableInterrupts(param_1);
    }
LAB_140007846:
    iVar1 = 0;
  }
  else {
    iVar1 = PdoSendSynchronousPowerPacket(param_1,1);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      uVar4 = 0xd5;
      uVar3 = 6;
    }
    else {
      lVar2 = VmbPacketGetPointer(*(undefined8 *)(param_1 + 0x40));
      iVar1 = PdoProgramInterrupts
                        (param_1,*(uint *)(*(longlong *)(lVar2 + 0x18) + 0x88),
                         *(longlong *)(lVar2 + 0x18) + 0x90);
      if (-1 < iVar1) goto LAB_140007846;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      uVar3 = 2;
      uVar4 = 0xd6;
    }
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar3,uVar4,
                       &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_1,(char)iVar1);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0xd7,
                       &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_1,(char)iVar1);
  }
  return iVar1;
}



===== PdoReadBlockCompletion @ 1400078a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdoReadBlockCompletion(undefined8 param_1,int param_2,int *param_3,uint param_4)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  undefined8 *puVar4;
  uint uVar5;
  undefined2 uVar6;
  longlong local_res8;
  void *local_38 [2];
  
  local_res8 = 0;
  local_38[0] = (void *)0x0;
  puVar4 = (undefined8 *)VmbPacketGetPointer();
  puVar1 = (undefined4 *)*puVar4;
  uVar3 = SUB81(puVar1,0);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0xc,
                       &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,
                       (char)*(undefined8 *)(puVar1 + 0xc),uVar3);
  }
  uVar2 = puVar4[1];
  if (param_2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140007af2;
    uVar6 = 0xd;
    uVar5 = 6;
  }
  else {
    if (param_4 < 8) {
      param_2 = -0x3ffffe7a;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140007af2;
      uVar6 = 0xe;
      uVar5 = param_4;
LAB_140007999:
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar6,
                         &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar3,(char)uVar5);
      goto LAB_140007af2;
    }
    param_2 = *param_3;
    if (param_2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140007af2;
      uVar6 = 0xf;
    }
    else {
      param_2 = (**(code **)(WdfFunctions_01033 + 0x868))(WdfDriverGlobals,uVar2,8,&local_res8,0);
      if (param_2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140007af2;
        uVar6 = 0x10;
      }
      else {
        param_2 = (**(code **)(WdfFunctions_01033 + 0x870))(WdfDriverGlobals,uVar2,0,local_38,0);
        if (-1 < param_2) {
          uVar5 = *(uint *)(local_res8 + 4);
          if (uVar5 <= param_4 - 4) {
            memmove(local_38[0],param_3 + 1,(ulonglong)uVar5);
            (**(code **)(WdfFunctions_01033 + 0x898))
                      (WdfDriverGlobals,uVar2,*(undefined4 *)(local_res8 + 4));
            param_2 = 0;
            goto LAB_140007af2;
          }
          param_2 = -0x3ffffdfa;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140007af2;
          uVar6 = 0x12;
          goto LAB_140007999;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140007af2;
        uVar6 = 0x11;
      }
    }
    uVar5 = 2;
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar5,uVar6,
                     &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar3,(char)param_2);
LAB_140007af2:
  *(undefined4 *)(puVar4 + 2) = 0;
  (**(code **)(WdfFunctions_01033 + 0x838))(WdfDriverGlobals,uVar2,param_2);
  uVar3 = KeAcquireSpinLockRaiseToDpc(puVar1 + 100);
  *(undefined8 *)(puVar1 + 0x62) = param_1;
  KeReleaseSpinLock(puVar1 + 100,uVar3);
  PdoCheckReadWriteQueue(puVar1);
  return;
}



===== PdoSelfManagedIoFlush @ 140007b80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdoSelfManagedIoFlush(undefined8 param_1)

{
  undefined1 uVar1;
  
  uVar1 = (**(code **)(WdfFunctions_01033 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x76,
                      &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar1);
  }
  return;
}



===== PdoSelfManagedIoInit @ 140007c00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 PdoSelfManagedIoInit(undefined8 param_1)

{
  undefined1 uVar1;
  
  uVar1 = (**(code **)(WdfFunctions_01033 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x77,
                      &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar1);
  }
  return 0;
}



===== PdoSelfManagedIoRestart @ 140007c80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 PdoSelfManagedIoRestart(undefined8 param_1)

{
  undefined1 uVar1;
  
  uVar1 = (**(code **)(WdfFunctions_01033 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x78,
                      &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar1);
  }
  return 0;
}



===== PdoSelfManagedIoSuspend @ 140007d00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 PdoSelfManagedIoSuspend(undefined8 param_1)

{
  undefined1 uVar1;
  
  uVar1 = (**(code **)(WdfFunctions_01033 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x79,
                      &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar1);
  }
  return 0;
}



===== PdoSendAssignedResourcesMessage @ 140007d74 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdoSendAssignedResourcesMessage(int *param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  uint uVar6;
  undefined8 uVar7;
  char *pcVar8;
  undefined1 uVar9;
  
  piVar3 = PdoFormatAssignedResourcesMessage(param_1);
  uVar4 = Feature_VpciVscRelaxedInterruptLimit__private_IsEnabledDeviceUsageNoInline();
  uVar1 = param_1[0x46];
  if ((int)uVar4 == 0) {
    uVar6 = uVar1;
  }
  else {
    uVar6 = 0x9ae8;
    if (uVar1 < 0x9ae8) {
      uVar6 = uVar1;
    }
  }
  VmbPacketSetCompletionRoutine(*(undefined8 *)(param_1 + 0x40),AssignedResourcesCompletion);
  uVar9 = SUB81(param_1,0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xe,0x9d,
                       &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar9,
                       (char)SystemReserved1[0xf]);
  }
  uVar5 = *(undefined8 *)(param_1 + 2);
  pcVar8 = "onecore\\vm\\dv\\vpci\\vsc\\sys\\pdo.c";
  uVar7 = 0xffffffffdead0002;
  (**(code **)(WdfFunctions_01033 + 0x668))(WdfDriverGlobals,uVar5,0xffffffffdead0002,0x1ebd);
  uVar4 = Feature_VpciVscRelaxedInterruptLimit__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar4 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      pcVar8 = &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids;
      WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x9f,
                         &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,
                         (char)*(undefined8 *)(param_1 + 0xc),uVar9);
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,uVar7,0x9e,pcVar8,
                        (char)*(undefined8 *)(param_1 + 0xc),uVar9,(char)piVar3[0x20]);
  }
  uVar5 = CONCAT44((int)((ulonglong)pcVar8 >> 0x20),1);
  iVar2 = VmbPacketSend(*(undefined8 *)(param_1 + 0x40),piVar3,uVar6,0);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0xa0,uVar5,
                          (char)*(undefined8 *)(param_1 + 0xc),uVar9,(char)iVar2);
    }
    param_1[0x74] = iVar2;
    IoQueueWorkItem(*(undefined8 *)(param_1 + 0x76),PdoAssignedResourcesWorkItem,1,param_1);
  }
  return;
}



===== PdoSendSynchronousPowerPacket @ 140007f8c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PdoSendSynchronousPowerPacket(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 auStack_78 [32];
  undefined4 local_58;
  int *local_50;
  uint *local_48;
  undefined8 local_40;
  uint local_38 [2];
  int local_30 [4];
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  local_30[3] = *param_1;
  local_40 = 0;
  local_30[0] = 0;
  local_30[1] = 0;
  local_48 = local_38;
  local_50 = local_30;
  local_38[0] = 8;
  local_30[2] = 0x42490004;
  local_58 = 1;
  local_20 = param_2;
  iVar1 = VmbChannelSendSynchronousRequest
                    (*(undefined8 *)(*(longlong *)(param_1 + 0xc) + 0x28),local_30 + 2,0xc);
  GetCompletionStatus(iVar1,local_30,(ulonglong)local_38[0]);
  return;
}



===== PdoSendSynchronousResetPacket @ 140008028 =====

void PdoSendSynchronousResetPacket(undefined4 *param_1)

{
  int iVar1;
  uint local_res8 [2];
  undefined4 local_res10;
  undefined4 local_res14;
  int local_res18 [4];
  
  local_res14 = *param_1;
  local_res18[0] = 0;
  local_res18[1] = 0;
  local_res8[0] = 8;
  local_res10 = 0x4249001c;
  iVar1 = VmbChannelSendSynchronousRequest
                    (*(undefined8 *)(*(longlong *)(param_1 + 0xc) + 0x28),&local_res10,8,0,1,
                     local_res18,local_res8,0);
  GetCompletionStatus(iVar1,local_res18,(ulonglong)local_res8[0]);
  return;
}



===== PdoUpdateInterruptTranslations @ 1400080a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PdoUpdateInterruptTranslations
                    (uint *param_1,int param_2,undefined8 param_3,int param_4,longlong param_5)

{
  undefined8 *puVar1;
  uint uVar2;
  ushort uVar3;
  code *pcVar4;
  uint uVar5;
  undefined4 uVar6;
  uint *_Dst;
  ulonglong uVar7;
  ulonglong uVar8;
  longlong lVar9;
  uint uVar10;
  ulonglong uVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  uint *puVar14;
  undefined2 uVar15;
  int iVar16;
  ulonglong *puVar17;
  char cVar18;
  uint uVar19;
  undefined8 uVar20;
  uint uVar21;
  undefined8 uStackY_180;
  undefined1 auStackY_178 [32];
  undefined1 auStack_14d [5];
  uint local_134;
  undefined4 local_130;
  longlong local_128;
  uint *local_120;
  uint *local_118;
  int local_110;
  uint uStack_10c;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  uint local_98 [24];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_178;
  local_98[1] = 0;
  local_110 = param_2;
  local_108 = param_3;
  memset(local_98,0,0x5c);
  local_a8 = 0;
  uStack_a0 = 0;
  memset(&local_f8,0,0x50);
  uVar5 = 0;
  _Dst = (uint *)0x0;
  cVar18 = '\0';
  uStack_10c = 0;
  local_118 = (uint *)0x0;
  local_120 = (uint *)0x0;
  uVar20 = (**(code **)(WdfFunctions_01033 + 0x108))(WdfDriverGlobals);
  local_100 = uVar20;
  if (*(char *)((longlong)param_1 + 0x342) != '\0') {
    uVar5 = HviGetPartitionIsolationType();
    if ((uVar5 == 2) || (uVar5 == 3)) {
      _Dst = (uint *)ExAllocatePool2(0x40,0x220,0x69637056);
      puVar12 = auStackY_178;
      if (_Dst == (uint *)0x0) {
        uVar11 = 0xc000009a;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x87,
                             &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_1,0x9a);
          puVar12 = auStackY_178;
        }
        goto LAB_14000875b;
      }
      local_118 = _Dst + 2;
    }
  }
  puVar12 = auStackY_178;
  uVar7 = Feature_VpciVscRelaxedInterruptLimit__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar7 != 0) {
    param_2 = param_2 + param_4;
    local_110 = param_2;
    RtlSetVolatileMemory(&local_f8,0,0x50);
  }
  uVar19 = 0;
  if (param_2 == 0) {
    local_98[0] = 0;
    puVar14 = local_98;
LAB_1400086aa:
    *(uint **)(puVar12 + 0x30) = puVar14;
    *(uint *)(puVar12 + 0x28) = uVar19 * 0x58 + 8;
    *(undefined4 *)(puVar12 + 0x20) = 0x1003;
    *(undefined8 *)(puVar12 + -8) = 0x1400086d8;
    uVar5 = IoSetDevicePropertyData(uVar20,&INTERRUPT_CONNECTION_DATA_PKEY,0);
    uVar11 = (ulonglong)uVar5;
    if ((int)uVar5 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        *(uint *)(puVar12 + 0x30) = uVar5;
        *(uint **)(puVar12 + 0x28) = param_1;
        *(undefined **)(puVar12 + 0x20) = &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids;
        uVar20 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
        *(undefined8 *)(puVar12 + -8) = 0x14000872a;
        WPP_RECORDER_SF_qd(uVar20,2,2,0x8d,*(undefined8 *)(puVar12 + 0x20),puVar12[0x28],
                           puVar12[0x30]);
      }
    }
    else {
      uVar11 = 0;
    }
    if (cVar18 != '\0') {
LAB_140008734:
      *(undefined8 *)(puVar12 + -8) = 0x140008740;
      ExFreePoolWithTag(puVar14,0);
    }
  }
  else {
    uVar7 = GetInterruptConnectionData(uVar20,&local_120);
    puVar14 = local_120;
    puVar12 = auStackY_178;
    uVar11 = uVar7 & 0xffffffff;
    if (-1 < (int)uVar7) {
      uVar20 = 1;
      uVar10 = 0;
      uVar21 = 0;
      uVar19 = 0;
      puVar13 = auStackY_178;
      if (*local_120 != 0) {
        do {
          uVar7 = (ulonglong)uVar10;
          if (puVar14[uVar7 * 0x16 + 2] == 3) {
            if (*(uint *)(puVar12 + 0x68) <= uVar21) {
              uVar11 = 0xc000000d;
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar15 = 0x89;
                goto LAB_140008670;
              }
              goto LAB_140008734;
            }
            *(undefined8 *)(puVar12 + -8) = 0x1400082c2;
            uVar11 = Feature_VpciVscRelaxedInterruptLimit__private_IsEnabledDeviceUsageNoInline();
            if (((int)uVar11 != 0) && (*(int *)(puVar12 + 0x40) == 0)) {
              *(undefined8 *)(puVar12 + -8) = 0x1400082e5;
              RtlSetVolatileMemory(&local_f8,0,0x50);
              if (uVar21 < 0x1ee) {
                lVar9 = *(longlong *)(puVar12 + 0x70);
                uVar11 = (ulonglong)uVar21;
                uStack_f0 = *(undefined8 *)(lVar9 + 8 + uVar11 * 0x48);
                local_f8 = CONCAT44(*(undefined4 *)(lVar9 + 4 + uVar11 * 0x48),
                                    CONCAT22(*(undefined2 *)(lVar9 + 2 + uVar11 * 0x48),
                                             (undefined2)local_f8));
              }
              else {
                uVar11 = (ulonglong)(uVar21 - 0x1ee);
                puVar1 = (undefined8 *)(param_5 + uVar11 * 0x50);
                local_f8 = *puVar1;
                uStack_f0 = puVar1[1];
                puVar1 = (undefined8 *)(param_5 + 0x10 + uVar11 * 0x50);
                local_e8 = *puVar1;
                uStack_e0 = puVar1[1];
                puVar1 = (undefined8 *)(param_5 + 0x20 + uVar11 * 0x50);
                local_d8 = *puVar1;
                uStack_d0 = puVar1[1];
                puVar1 = (undefined8 *)(param_5 + 0x30 + uVar11 * 0x50);
                local_c8 = *puVar1;
                uStack_c0 = puVar1[1];
                puVar1 = (undefined8 *)(param_5 + 0x40 + uVar11 * 0x50);
                local_b8 = *puVar1;
                uStack_b0 = puVar1[1];
              }
            }
            *(undefined8 *)(puVar12 + -8) = 0x14000835b;
            uVar11 = Feature_CvmDmaBouncing__private_IsEnabledDeviceUsageNoInline();
            if ((int)uVar11 != 0) {
              *(undefined8 *)(puVar12 + -8) = 0x14000836b;
              uVar11 = Feature_VpciVscRelaxedInterruptLimit__private_IsEnabledDeviceUsageNoInline();
              if ((int)uVar11 == 0) {
                lVar9 = *(longlong *)(puVar12 + 0x70);
                if (*(short *)(lVar9 + 2 + (ulonglong)uVar21 * 0x48) != 0) goto LAB_1400083ba;
                uVar11 = 0xc000000d;
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar15 = 0x8b;
LAB_140008670:
                  uVar11 = 0xc000000d;
                  *(undefined4 *)(puVar12 + 0x30) = 0xc000000d;
LAB_140008674:
                  *(uint **)(puVar12 + 0x28) = param_1;
                  *(undefined **)(puVar12 + 0x20) = &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids
                  ;
                  uVar20 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
                  *(undefined8 *)(puVar12 + -8) = 0x14000869e;
                  WPP_RECORDER_SF_qd(uVar20,2,2,uVar15,*(undefined8 *)(puVar12 + 0x20),puVar12[0x28]
                                     ,puVar12[0x30]);
                }
              }
              else {
                if (local_f8._2_2_ != 0) goto LAB_1400083b5;
                uVar11 = 0xc000000d;
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar15 = 0x8a;
                  goto LAB_140008670;
                }
              }
              goto LAB_140008734;
            }
            *(undefined8 *)(puVar12 + -8) = 0x140008364;
            Feature_VpciVscRelaxedInterruptLimit__private_IsEnabledDeviceUsageNoInline();
LAB_1400083b5:
            lVar9 = *(longlong *)(puVar12 + 0x70);
LAB_1400083ba:
            puVar14[uVar7 * 0x16 + 0xc] = puVar14[uVar7 * 0x16 + 0xc] | 0x80000000;
            *(undefined8 *)(puVar12 + -8) = 0x1400083c5;
            uVar11 = Feature_VpciVscRelaxedInterruptLimit__private_IsEnabledDeviceUsageNoInline();
            if ((int)uVar11 == 0) {
              puVar14[uVar7 * 0x16 + 0xe] = *(uint *)(lVar9 + 8 + (ulonglong)uVar21 * 0x48);
              uVar3 = *(ushort *)(lVar9 + 4 + (ulonglong)uVar21 * 0x48);
            }
            else {
              puVar14[uVar7 * 0x16 + 0xe] = (uint)uStack_f0;
              uVar3 = local_f8._4_2_;
            }
            iVar16 = *(int *)(puVar12 + 0x40);
            uVar20 = *(undefined8 *)(puVar12 + 0x50);
            puVar14[uVar7 * 0x16 + 0x16] = (uint)uVar3 + iVar16;
            *(int *)(puVar12 + 0x40) = iVar16 + 1;
            uVar19 = (uint)uVar20;
            if (uVar5 - 2 <= uVar19) {
              *(undefined8 *)(puVar12 + -8) = 0x140008420;
              RtlSetVolatileMemory(_Dst,0,0x10);
              *(undefined8 *)(puVar12 + -8) = 0x14000842e;
              RtlSetVolatileMemory(&local_a8,0,0x10);
              *(undefined8 *)(puVar12 + -8) = 0x140008440;
              RtlSetVolatileMemory(*(void **)(puVar12 + 0x60),0,0x210);
              lVar9 = *(longlong *)(puVar12 + 0x50);
              iVar16 = 0;
              *(undefined4 *)(puVar12 + 0x44) = 0;
              uVar11 = 0;
              do {
                uVar19 = (uint)uVar11;
                if ((*(ulonglong *)(puVar14 + uVar7 * 0x16 + 8) >> (uVar11 & 0x3f) & 1) == 0) {
                  puVar17 = *(ulonglong **)(puVar12 + 0x60);
LAB_140008513:
                  uVar8 = 0;
                }
                else {
                  *(undefined8 *)(puVar12 + -8) = 0x14000846a;
                  uVar8 = Feature_VpciInterruptTargetFix__private_IsEnabledDeviceUsageNoInline();
                  if ((int)uVar8 == 0) {
                    uVar8 = (ulonglong)(uVar19 >> 6);
                    uVar10 = uVar19;
LAB_140008478:
                    puVar17 = *(ulonglong **)(puVar12 + 0x60);
                    lVar9 = *(longlong *)(puVar12 + 0x50);
                    uVar2 = *(uint *)(puVar12 + 0x44);
                    puVar17[uVar8 + 2] = puVar17[uVar8 + 2] | 1L << (uVar10 & 0x3f);
                    iVar16 = (uint)uVar8 + 1;
                    if ((uint)uVar8 < uVar2) {
                      iVar16 = *(int *)(puVar12 + 0x44);
                    }
                    *(int *)(puVar12 + 0x44) = iVar16;
                    goto LAB_140008513;
                  }
                  *(undefined8 *)(puVar12 + -8) = 0x1400084ba;
                  RtlSetVolatileMemory(puVar12 + 0x48,0,4);
                  *(short *)(puVar12 + 0x48) = (short)puVar14[uVar7 * 0x16 + 10];
                  puVar12[0x4a] = (char)uVar11;
                  *(undefined8 *)(puVar12 + -8) = 0x1400084d9;
                  iVar16 = WinHvProcessorNumberToVpIndex
                                     (*(undefined4 *)(puVar12 + 0x48),puVar12 + 0x6c);
                  uVar8 = 0;
                  if (-1 < iVar16) {
                    uVar10 = *(uint *)(puVar12 + 0x6c);
                    uVar8 = (ulonglong)(uVar10 >> 6);
                    if (uVar10 >> 6 < 0x40) goto LAB_140008478;
                    pcVar4 = (code *)swi(0x29);
                    (*pcVar4)(8);
                    puVar12 = puVar12 + 8;
                  }
                  lVar9 = *(longlong *)(puVar12 + 0x50);
                  iVar16 = *(int *)(puVar12 + 0x44);
                  puVar17 = *(ulonglong **)(puVar12 + 0x60);
                }
                uVar19 = uVar19 + (int)lVar9;
                uVar11 = (ulonglong)uVar19;
              } while (uVar19 < 0x40);
              local_a8 = CONCAT44(local_a8._4_4_,(int)lVar9);
              uStack_a0 = CONCAT44(puVar14[uVar7 * 0x16 + 0x16],puVar14[uVar7 * 0x16 + 0xe]);
              _Dst[1] = _Dst[1] | 2;
              *_Dst = puVar14[uVar7 * 0x16 + 3];
              *puVar17 = uVar8;
              if (iVar16 == 0x40) {
                uVar7 = 0xffffffffffffffff;
              }
              else {
                uVar7 = (lVar9 << ((byte)iVar16 & 0x3f)) - lVar9;
              }
              puVar17[1] = uVar7;
              iVar16 = iVar16 * 8 + 0x18;
              *(undefined8 *)(puVar12 + -8) = 0x140008571;
              uVar19 = PdoGetLogicalDeviceId(param_1);
              *(int *)(puVar12 + 0x20) = iVar16;
              *(undefined8 *)(puVar12 + -8) = 0x14000858b;
              uVar19 = WinHvRetargetDeviceInterrupt(0xffffffffffffffff,uVar19,&local_a8);
              uVar11 = (ulonglong)uVar19;
              if ((int)uVar19 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar15 = 0x8c;
                  *(uint *)(puVar12 + 0x30) = uVar19;
                  goto LAB_140008674;
                }
                goto LAB_140008734;
              }
              uVar19 = (uint)*(undefined8 *)(puVar12 + 0x50);
            }
            *(undefined8 *)(puVar12 + -8) = 0x1400085a0;
            uVar7 = Feature_VpciVscRelaxedInterruptLimit__private_IsEnabledDeviceUsageNoInline();
            if ((int)uVar7 == 0) {
              if (*(uint *)(puVar12 + 0x40) ==
                  (uint)*(ushort *)(*(longlong *)(puVar12 + 0x70) + 2 + (ulonglong)uVar21 * 0x48)) {
                uVar21 = uVar21 + uVar19;
                *(undefined4 *)(puVar12 + 0x40) = 0;
              }
            }
            else {
              uVar19 = uVar21 + 1;
              if (*(uint *)(puVar12 + 0x40) != (uint)local_f8._2_2_) {
                uVar19 = uVar21;
              }
              uVar21 = uVar19;
              uVar6 = 0;
              if (*(uint *)(puVar12 + 0x40) != (uint)local_f8._2_2_) {
                uVar6 = *(undefined4 *)(puVar12 + 0x40);
              }
              *(undefined4 *)(puVar12 + 0x40) = uVar6;
            }
          }
          uVar20 = *(undefined8 *)(puVar12 + 0x50);
          uVar19 = *puVar14;
          uVar10 = *(int *)(puVar12 + 0x4c) + (int)uVar20;
          *(uint *)(puVar12 + 0x4c) = uVar10;
          puVar13 = puVar12;
        } while (uVar10 < uVar19);
      }
      cVar18 = (char)uVar20;
      uVar20 = *(undefined8 *)(puVar13 + 0x78);
      puVar12 = puVar13;
      goto LAB_1400086aa;
    }
    puVar12 = auStackY_178;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x88,
                         &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_1,(char)uVar7)
      ;
      puVar12 = auStackY_178;
    }
  }
  if (_Dst != (uint *)0x0) {
    *(undefined8 *)(puVar12 + -8) = 0x140008756;
    ExFreePoolWithTag(_Dst,0);
  }
LAB_14000875b:
  *(undefined8 *)(puVar12 + -8) = 0x140008769;
  return uVar11;
}



===== PdoWriteBlockCompletion @ 1400087a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdoWriteBlockCompletion(undefined8 param_1,int param_2,int *param_3,uint param_4)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  undefined8 *puVar4;
  undefined2 uVar5;
  longlong local_res8;
  
  local_res8 = 0;
  puVar4 = (undefined8 *)VmbPacketGetPointer();
  puVar1 = (undefined4 *)*puVar4;
  uVar3 = SUB81(puVar1,0);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x18,
                       &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,
                       (char)*(undefined8 *)(puVar1 + 0xc),uVar3);
  }
  uVar2 = puVar4[1];
  if (param_2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140008953;
    uVar5 = 0x19;
  }
  else {
    if (param_4 < 4) {
      param_2 = -0x3ffffe7a;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x1a,
                           &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar3,(char)param_4);
      }
      goto LAB_140008953;
    }
    param_2 = *param_3;
    if (param_2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140008953;
      uVar5 = 0x1b;
    }
    else {
      param_2 = (**(code **)(WdfFunctions_01033 + 0x868))(WdfDriverGlobals,uVar2,0xc,&local_res8,0);
      if (-1 < param_2) {
        (**(code **)(WdfFunctions_01033 + 0x898))
                  (WdfDriverGlobals,uVar2,*(undefined4 *)(local_res8 + 4));
        param_2 = 0;
        goto LAB_140008953;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140008953;
      uVar5 = 0x1c;
    }
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar5,
                     &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar3,(char)param_2);
LAB_140008953:
  *(undefined4 *)(puVar4 + 2) = 0;
  (**(code **)(WdfFunctions_01033 + 0x838))(WdfDriverGlobals,uVar2,param_2);
  uVar3 = KeAcquireSpinLockRaiseToDpc(puVar1 + 100);
  *(undefined8 *)(puVar1 + 0x62) = param_1;
  KeReleaseSpinLock(puVar1 + 100,uVar3);
  PdoCheckReadWriteQueue(puVar1);
  return;
}



===== PnpBlockerAnnounceBlockingIsReadyWorker @ 1400089e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PnpBlockerAnnounceBlockingIsReadyWorker(undefined8 param_1)

{
  int *piVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  lVar2 = (**(code **)(WdfFunctions_01033 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_VPCI_WORKITEM_CONTEXT_TYPE_INFO_140010090);
  piVar1 = *(int **)(lVar2 + 8);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0xc9,
                      &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)piVar1);
  }
  uVar3 = PdoRunStateMachine(piVar1,9);
  if ((char)uVar3 == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0xca,
                        &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)piVar1);
    }
    PnpBlockerStopBlocking((longlong)piVar1);
  }
  return;
}



===== RtlStringCchPrintfExW @ 140008ac0 =====

int RtlStringCchPrintfExW
              (wchar_t *param_1,ulonglong param_2,undefined8 *param_3,ulonglong *param_4,
              uint param_5,wchar_t *param_6,char param_7)

{
  int iVar1;
  ulonglong uVar2;
  int iVar3;
  ulonglong uVar4;
  wchar_t *pwVar5;
  
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
  uVar4 = param_2;
  pwVar5 = param_1;
  if ((param_5 & 0xffffe000) == 0) {
    if (param_2 == 0) {
      if (*param_6 == L'\0') goto LAB_140008be2;
      iVar3 = (-(uint)(param_1 != (wchar_t *)0x0) & 0xbffffff8) + 0xc000000d;
    }
    else {
      uVar2 = param_2 - 1;
      iVar1 = _vsnwprintf(param_1,uVar2,param_6,&param_7);
      if (iVar1 < 0) {
LAB_140008c58:
        iVar3 = -0x7ffffffb;
LAB_140008c5d:
        param_1[uVar2] = L'\0';
      }
      else {
        uVar4 = (ulonglong)iVar1;
        if (uVar2 < uVar4) goto LAB_140008c58;
        if (uVar4 == uVar2) goto LAB_140008c5d;
        uVar2 = uVar4;
      }
      uVar4 = param_2 - uVar2;
      pwVar5 = param_1 + uVar2;
      if (-1 < iVar3) {
        if ((((param_5 >> 9 & 1) != 0) && (1 < uVar4)) && (2 < uVar4 * 2)) {
          memset(pwVar5 + 1,param_5 & 0xff,uVar4 * 2 - 2);
        }
        goto LAB_140008be2;
      }
    }
  }
  else {
    iVar3 = -0x3ffffff3;
    if (param_2 != 0) {
      *param_1 = L'\0';
    }
  }
  if (((param_5 & 0x1c00) != 0) && (param_2 != 0)) {
    uVar2 = param_2 & 0x7fffffffffffffff;
    if ((uVar2 != 0) && ((param_5 >> 0xc & 1) != 0)) {
      *param_1 = L'\0';
      uVar4 = uVar2;
      pwVar5 = param_1;
    }
    if ((param_5 >> 10 & 1) == 0) {
LAB_140008bb5:
      if (uVar2 == 0) goto LAB_140008bca;
    }
    else {
      memset(param_1,param_5 & 0xff,param_2 * 2);
      if ((char)param_5 == '\0') {
        uVar4 = uVar2;
        pwVar5 = param_1;
        goto LAB_140008bb5;
      }
      if (uVar2 == 0) goto LAB_140008bca;
      uVar4 = 1;
      pwVar5 = param_1 + (param_2 - 1);
      *pwVar5 = L'\0';
    }
    if ((param_5 >> 0xb & 1) != 0) {
      *param_1 = L'\0';
      uVar4 = uVar2;
      pwVar5 = param_1;
    }
  }
LAB_140008bca:
  if (((iVar3 + 0x80000000U & 0x80000000) == 0) && (iVar3 != -0x7ffffffb)) {
    return iVar3;
  }
LAB_140008be2:
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = pwVar5;
  }
  if (param_4 != (ulonglong *)0x0) {
    *param_4 = uVar4;
  }
  return iVar3;
}



===== RtlStringCchPrintfW @ 140008cf0 =====

undefined8
RtlStringCchPrintfW(wchar_t *param_1,longlong param_2,wchar_t *param_3,undefined8 param_4)

{
  ulonglong _Count;
  int iVar1;
  undefined8 uVar2;
  undefined8 local_res20;
  
  if (param_2 - 1U < 0x7fffffff) {
    _Count = param_2 - 1;
    uVar2 = 0;
    local_res20 = param_4;
    iVar1 = _vsnwprintf(param_1,_Count,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      uVar2 = 0x80000005;
    }
    else if ((longlong)iVar1 != _Count) {
      return 0;
    }
    param_1[_Count] = L'\0';
  }
  else {
    uVar2 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = L'\0';
    }
  }
  return uVar2;
}



===== RtlUnicodeStringPrintf @ 140008d6c =====

undefined8
RtlUnicodeStringPrintf(ushort *param_1,wchar_t *param_2,undefined8 param_3,undefined8 param_4)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ulonglong _Count;
  undefined8 local_res18;
  undefined8 local_res20;
  
  uVar1 = *param_1;
  if ((((((uVar1 & 1) == 0) && (uVar2 = param_1[1], (uVar2 & 1) == 0)) && (uVar1 <= uVar2)) &&
      (uVar2 != 0xffff)) &&
     ((uVar5 = 0, *(longlong *)(param_1 + 4) != 0 || ((uVar1 == 0 && (uVar2 == 0)))))) {
    _Count = (ulonglong)(param_1[1] >> 1);
    local_res18 = param_3;
    local_res20 = param_4;
    iVar3 = _vsnwprintf(*(wchar_t **)(param_1 + 4),_Count,param_2,(va_list)&local_res18);
    if ((iVar3 < 0) || (uVar4 = (longlong)iVar3, _Count < (ulonglong)(longlong)iVar3)) {
      uVar5 = 0x80000005;
      uVar4 = _Count;
    }
    *param_1 = (short)uVar4 * 2;
  }
  else {
    uVar5 = 0xc000000d;
  }
  return uVar5;
}



===== _guard_check_icall @ 140008e10 =====

void _guard_check_icall(void)

{
  return;
}



===== VpciDeviceListIdentificationDescriptionCompare @ 140008e20 =====

ulonglong VpciDeviceListIdentificationDescriptionCompare
                    (undefined8 param_1,longlong param_2,longlong param_3)

{
  ulonglong uVar1;
  
  uVar1 = *(ulonglong *)(param_2 + 0xc);
  if (((uVar1 == *(ulonglong *)(param_3 + 0xc)) &&
      (uVar1 = (ulonglong)*(uint *)(param_2 + 0x14),
      *(uint *)(param_2 + 0x14) == *(uint *)(param_3 + 0x14))) &&
     (uVar1 = (ulonglong)*(uint *)(param_3 + 8), *(uint *)(param_2 + 8) == *(uint *)(param_3 + 8)))
  {
    return (ulonglong)
           CONCAT31((int3)((uint)*(int *)(param_3 + 4) >> 8),
                    *(int *)(param_2 + 4) == *(int *)(param_3 + 4));
  }
  return uVar1 & 0xffffffffffffff00;
}



===== VpciDeviceListIdentificationDescriptionDuplicate @ 140008e60 =====

undefined8
VpciDeviceListIdentificationDescriptionDuplicate
          (undefined8 param_1,longlong param_2,longlong param_3)

{
  undefined8 uVar1;
  
  *(undefined8 *)(param_3 + 0xc) = *(undefined8 *)(param_2 + 0xc);
  *(undefined4 *)(param_3 + 0x14) = *(undefined4 *)(param_2 + 0x14);
  *(undefined4 *)(param_3 + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_3 + 8) = *(undefined4 *)(param_2 + 8);
  *(undefined2 *)(param_3 + 0x1a) = *(undefined2 *)(param_2 + 0x1a);
  *(undefined1 *)(param_3 + 0x18) = *(undefined1 *)(param_2 + 0x18);
  uVar1 = *(undefined8 *)(param_2 + 0x24);
  *(undefined8 *)(param_3 + 0x1c) = *(undefined8 *)(param_2 + 0x1c);
  *(undefined8 *)(param_3 + 0x24) = uVar1;
  uVar1 = *(undefined8 *)(param_2 + 0x34);
  *(undefined8 *)(param_3 + 0x2c) = *(undefined8 *)(param_2 + 0x2c);
  *(undefined8 *)(param_3 + 0x34) = uVar1;
  uVar1 = *(undefined8 *)(param_2 + 0x44);
  *(undefined8 *)(param_3 + 0x3c) = *(undefined8 *)(param_2 + 0x3c);
  *(undefined8 *)(param_3 + 0x44) = uVar1;
  uVar1 = *(undefined8 *)(param_2 + 0x54);
  *(undefined8 *)(param_3 + 0x4c) = *(undefined8 *)(param_2 + 0x4c);
  *(undefined8 *)(param_3 + 0x54) = uVar1;
  uVar1 = *(undefined8 *)(param_2 + 100);
  *(undefined8 *)(param_3 + 0x5c) = *(undefined8 *)(param_2 + 0x5c);
  *(undefined8 *)(param_3 + 100) = uVar1;
  uVar1 = *(undefined8 *)(param_2 + 0x74);
  *(undefined8 *)(param_3 + 0x6c) = *(undefined8 *)(param_2 + 0x6c);
  *(undefined8 *)(param_3 + 0x74) = uVar1;
  uVar1 = *(undefined8 *)(param_2 + 0x84);
  *(undefined8 *)(param_3 + 0x7c) = *(undefined8 *)(param_2 + 0x7c);
  *(undefined8 *)(param_3 + 0x84) = uVar1;
  uVar1 = *(undefined8 *)(param_2 + 0x94);
  *(undefined8 *)(param_3 + 0x8c) = *(undefined8 *)(param_2 + 0x8c);
  *(undefined8 *)(param_3 + 0x94) = uVar1;
  uVar1 = *(undefined8 *)(param_2 + 0xa4);
  *(undefined8 *)(param_3 + 0x9c) = *(undefined8 *)(param_2 + 0x9c);
  *(undefined8 *)(param_3 + 0xa4) = uVar1;
  uVar1 = *(undefined8 *)(param_2 + 0xb4);
  *(undefined8 *)(param_3 + 0xac) = *(undefined8 *)(param_2 + 0xac);
  *(undefined8 *)(param_3 + 0xb4) = uVar1;
  uVar1 = *(undefined8 *)(param_2 + 0xc4);
  *(undefined8 *)(param_3 + 0xbc) = *(undefined8 *)(param_2 + 0xbc);
  *(undefined8 *)(param_3 + 0xc4) = uVar1;
  uVar1 = *(undefined8 *)(param_2 + 0xd4);
  *(undefined8 *)(param_3 + 0xcc) = *(undefined8 *)(param_2 + 0xcc);
  *(undefined8 *)(param_3 + 0xd4) = uVar1;
  *(undefined1 *)(param_3 + 0xdc) = *(undefined1 *)(param_2 + 0xdc);
  return 0;
}



===== VpciGetBusData @ 140008f20 =====

ulonglong VpciGetBusData(undefined4 *param_1,undefined8 param_2,undefined4 *param_3,uint param_4,
                        uint param_5)

{
  longlong lVar1;
  byte bVar2;
  ulonglong _Size;
  undefined4 *puVar3;
  undefined4 *_Src;
  ulonglong uVar4;
  
  _Size = (ulonglong)param_5;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_qDqDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  lVar1 = *(longlong *)(param_1 + 0xc);
  if ((param_5 < 0x1001) && (param_4 + param_5 < 0x1001)) {
    bVar2 = KeGetCurrentIrql();
    if (bVar2 < 2) {
      KeAcquireGuardedMutex(lVar1 + 0x78);
      _Src = (undefined4 *)(lVar1 + 0xc0);
    }
    else {
      _Src = param_3;
    }
    FdoReadConfig(lVar1,*param_1,_Src,(ulonglong)param_4,param_5);
    if (param_5 != 0) {
      puVar3 = _Src;
      uVar4 = _Size;
      do {
        if (param_4 - 0x10 < 0x18) {
          *(undefined1 *)puVar3 =
               *(undefined1 *)((ulonglong)(param_4 - 0x10) + 0x38 + (longlong)param_1);
        }
        param_4 = param_4 + 1;
        puVar3 = (undefined4 *)((longlong)puVar3 + 1);
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    }
    if (bVar2 < 2) {
      memmove(param_3,_Src,_Size);
      KeReleaseGuardedMutex(lVar1 + 0x78);
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0xb7,
                        &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_1);
    }
    memset(param_3,0xff,_Size);
    _Size = 0;
  }
  return _Size;
}



===== VpciInternalIoControl @ 1400090b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VpciInternalIoControl
               (undefined8 param_1,undefined8 param_2,ulonglong param_3,undefined8 param_4,
               int param_5)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  longlong *local_18 [2];
  
  local_18[0] = (longlong *)0x0;
  uVar3 = (**(code **)(WdfFunctions_01033 + 0x4e8))(WdfDriverGlobals,param_1);
  puVar4 = (undefined4 *)
           (**(code **)(WdfFunctions_01033 + 0x650))
                     (WdfDriverGlobals,uVar3,PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8);
  if (param_5 == 0x2ac007) {
    if (param_3 < 8) {
      iVar2 = -0x3fffffdd;
      goto LAB_1400091f9;
    }
    iVar2 = (**(code **)(WdfFunctions_01033 + 0x870))(WdfDriverGlobals,param_2,8,local_18,0);
    if (-1 < iVar2) {
      LOCK();
      lVar1 = *(longlong *)(puVar4 + 0x58);
      *(longlong *)(puVar4 + 0x58) = 0;
      UNLOCK();
      *local_18[0] = lVar1;
      if (lVar1 != 0) {
        (**(code **)(WdfFunctions_01033 + 0x898))(WdfDriverGlobals,param_2,8);
        iVar2 = 0;
        goto LAB_1400091f9;
      }
      iVar2 = (**(code **)(WdfFunctions_01033 + 0x8c8))
                        (WdfDriverGlobals,param_2,*(undefined8 *)(puVar4 + 0x56));
      if (-1 < iVar2) {
        return;
      }
    }
  }
  else {
    if ((param_5 != 0x2ac00b) && (param_5 != 0x2ac00f)) {
      iVar2 = -0x3ffffff0;
      goto LAB_1400091f9;
    }
    iVar2 = (**(code **)(WdfFunctions_01033 + 0x8c8))
                      (WdfDriverGlobals,param_2,*(undefined8 *)(puVar4 + 0x5e));
    if (-1 < iVar2) {
      PdoCheckReadWriteQueue(puVar4);
      return;
    }
  }
  if (iVar2 == 0x103) {
    return;
  }
LAB_1400091f9:
  (**(code **)(WdfFunctions_01033 + 0x838))(WdfDriverGlobals,param_2,iVar2);
  return;
}



===== VpciSetBusData @ 140009250 =====

ulonglong VpciSetBusData(undefined4 *param_1,undefined8 param_2,undefined4 *param_3,uint param_4,
                        uint param_5)

{
  uint uVar1;
  longlong lVar2;
  byte bVar3;
  ulonglong _Size;
  uint uVar4;
  ulonglong uVar5;
  undefined4 *puVar6;
  
  _Size = (ulonglong)param_5;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_qdqdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  lVar2 = *(longlong *)(param_1 + 0xc);
  if ((param_5 < 0x1001) && (param_4 + param_5 < 0x1001)) {
    bVar3 = KeGetCurrentIrql();
    if (bVar3 < 2) {
      KeAcquireGuardedMutex(lVar2 + 0x78);
      memmove((undefined4 *)(lVar2 + 0xc0),param_3,_Size);
      param_3 = (undefined4 *)(lVar2 + 0xc0);
    }
    if (param_5 != 0) {
      uVar5 = _Size;
      puVar6 = param_3;
      uVar4 = param_4;
      do {
        uVar1 = uVar4 - 0x10;
        if (uVar1 < 0x18) {
          *(undefined1 *)((ulonglong)uVar1 + 0x38 + (longlong)param_1) = *(undefined1 *)puVar6;
          param_1[(ulonglong)(uVar1 & 3) + 0xe] =
               param_1[(ulonglong)(uVar1 & 3) + 0xe] & param_1[(ulonglong)(uVar1 & 3) + 0x14];
        }
        uVar4 = uVar4 + 1;
        puVar6 = (undefined4 *)((longlong)puVar6 + 1);
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
    FdoWriteConfig(lVar2,*param_1,param_3,(ulonglong)param_4,param_5);
    if (bVar3 < 2) {
      KeReleaseGuardedMutex(lVar2 + 0x78);
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0xb9,
                        &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_1);
    }
    _Size = 0;
  }
  return _Size;
}



===== VpciTranslateBusAddress @ 1400093e0 =====

ulonglong VpciTranslateBusAddress(void)

{
  undefined **ppuVar1;
  
  ppuVar1 = &WPP_RECORDER_INITIALIZED;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    ppuVar1 = (undefined **)WPP_RECORDER_SF_qidqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  return (ulonglong)ppuVar1 & 0xffffffffffffff00;
}



===== WPP_RECORDER_SF_DDq @ 14000943c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DDq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,0x3c,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,8,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,0x3c,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,8,0);
  return;
}



===== WPP_RECORDER_SF_Dd @ 140009530 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Dd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,0x82,&uStack0000000000000030,4,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,2,2,&WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,0x82,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_qDDdq @ 140009600 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDDdq
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,4,&param_9,4,&param_10,8,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,param_4,&param_6,8,
                  &param_7,4,&param_8,4,&param_9,4,&param_10,8,0);
  return;
}



===== WPP_RECORDER_SF_qDDq @ 14000973c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDDq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,0x93,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,8,0);
  }
  WppAutoLogTrace(param_1,4,2,&WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,0x93,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,8,0);
  return;
}



===== WPP_RECORDER_SF_qDqDD @ 140009854 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDqDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,0xb6,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,8,&uStack0000000000000048,4,
               &uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,5,5,&WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,0xb6,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,8,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_qLL @ 140009994 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,0xbd,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,5,2,&WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,0xbd,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_qLLLqq @ 140009a8c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLLLqq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,0xbc,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,8,&uStack0000000000000058,8,0);
  }
  WppAutoLogTrace(param_1,4,2,&WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,0xbc,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,8,&uStack0000000000000058,8,0);
  return;
}



===== WPP_RECORDER_SF_qLl @ 140009be4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLl(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,0xc2,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,5,2,&WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,0xc2,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_qdqdd @ 140009cdc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qdqdd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,0xb8,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,8,&uStack0000000000000048,4,
               &uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,5,5,&WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,0xb8,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,8,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_qidqq @ 140009e1c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qidqq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,0xba,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,8,
               &uStack0000000000000050,8,0);
  }
  WppAutoLogTrace(param_1,5,5,&WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,0xba,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,8,&uStack0000000000000050,8,0);
  return;
}



===== WPP_RECORDER_SF_ql @ 140009f5c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ql(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,0xcc,&uStack0000000000000030,8,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,5,2,&WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,0xcc,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_qqD @ 14000a030 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,4,6,&WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,param_4,&param_6,8,
                  &param_7,8,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qqd @ 14000a128 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqd(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,
               &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,&WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,param_4,
                  &param_6,8,&param_7,8,&param_8,4,0);
  return;
}



===== VscCheckDeviceProxyPrefixChanged @ 14000a278 =====

uint VscCheckDeviceProxyPrefixChanged
               (longlong param_1,undefined1 *param_2,undefined8 param_3,longlong param_4)

{
  uint uVar1;
  undefined1 uVar2;
  undefined8 local_18 [2];
  
  uVar1 = VscGetDeviceProxyPrefix((wchar_t *)(param_1 + 0x24c),param_2,local_18,param_4);
  uVar2 = 0;
  if ((int)uVar1 < 0) {
    if (uVar1 != 0xc0000225) {
      return uVar1;
    }
    if (*(char *)(param_1 + 0x30c) == '\0') goto LAB_14000a2be;
  }
  else if (*(char *)(param_1 + 0x30c) != '\0') goto LAB_14000a2be;
  uVar2 = 1;
LAB_14000a2be:
  *param_2 = uVar2;
  return 0;
}



===== VscGetDeviceProxyPrefix @ 14000a2d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint VscGetDeviceProxyPrefix
               (wchar_t *param_1,undefined8 param_2,undefined8 *param_3,longlong param_4)

{
  undefined8 *puVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  longlong local_res20;
  
  local_res20 = param_4;
  uVar3 = VscProxyCheckDeviceLocationPath((longlong)param_1,0xc0,0x60);
  if ((char)uVar3 != '\0') {
    if (param_3 != (undefined8 *)0x0) {
      puVar4 = (undefined8 *)
               (**(code **)(WdfFunctions_01033 + 0x650))
                         (WdfDriverGlobals,VpciCtrlDev,
                          PTR__WDF_VPCI_VSC_CTRL_DEVICE_DATA_TYPE_INFO_140010018);
      puVar1 = (undefined8 *)*puVar4;
      do {
        if (puVar1 == puVar4) {
          return 0xc0000225;
        }
        if ((wchar_t *)puVar1[5] != (wchar_t *)0x0) {
          local_res20 = 0;
          uVar2 = VscProxyIsSubString((wchar_t *)puVar1[5],puVar1[4],param_1,param_4,&local_res20);
          if ((int)uVar2 < 0) {
            return uVar2;
          }
          if (local_res20 != 0) {
            *param_3 = puVar1[2];
            *(undefined4 *)(param_3 + 1) = *(undefined4 *)(puVar1 + 3);
            return 0;
          }
        }
        puVar1 = (undefined8 *)*puVar1;
      } while( true );
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x23,
                       &WPP_910e8a1cc1ab306ac66fc329452f92cd_Traceguids);
    }
  }
  return 0xc000000d;
}



===== VscProxyCheckDeviceLocationPath @ 14000a3f4 =====

ulonglong VscProxyCheckDeviceLocationPath(longlong param_1,ulonglong param_2,uint param_3)

{
  undefined **ppuVar1;
  
  if (((param_2 & 1) == 0) && ((ulonglong)param_3 <= param_2 >> 1)) {
    if (*(short *)(param_1 + -2 + (param_2 >> 1) * 2) == 0) {
      return CONCAT71((uint7)(uint3)(param_3 >> 8),1);
    }
    ppuVar1 = &WPP_RECORDER_INITIALIZED;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      ppuVar1 = (undefined **)
                WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x20,
                                 &WPP_910e8a1cc1ab306ac66fc329452f92cd_Traceguids);
    }
  }
  else {
    ppuVar1 = &WPP_RECORDER_INITIALIZED;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      ppuVar1 = (undefined **)
                WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,2,0x1f,
                                   &WPP_910e8a1cc1ab306ac66fc329452f92cd_Traceguids,(char)param_2,
                                   (char)param_3 * '\x02');
    }
  }
  return (ulonglong)ppuVar1 & 0xffffffffffffff00;
}



===== VscProxyIsSubString @ 14000a4a4 =====

uint VscProxyIsSubString(wchar_t *param_1,ulonglong param_2,wchar_t *param_3,undefined8 param_4,
                        undefined8 *param_5)

{
  ulonglong uVar1;
  ulonglong uVar2;
  wchar_t *pwVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined2 uVar7;
  
  *param_5 = 0;
  if ((((param_1 == (wchar_t *)0x0) || (param_3 == (wchar_t *)0x0)) ||
      (uVar2 = VscProxyCheckDeviceLocationPath((longlong)param_1,param_2,1), (char)uVar2 == '\0'))
     || (uVar2 = VscProxyCheckDeviceLocationPath((longlong)param_3,0xc0,1), (char)uVar2 == '\0')) {
    return 0xc000000d;
  }
  lVar4 = 0x60;
  pwVar3 = param_3;
  do {
    if (*pwVar3 == L'\0') break;
    pwVar3 = pwVar3 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  uVar5 = ~-(uint)(lVar4 != 0) & 0xc000000d;
  uVar2 = -(ulonglong)(lVar4 != 0) & 0x60U - lVar4;
  if (lVar4 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    uVar7 = 0x1d;
    uVar5 = 0xc000000d;
  }
  else {
    lVar4 = (param_2 >> 1) - 1;
    if (uVar2 == 0) {
      return uVar5;
    }
    if (lVar4 == 0) {
      return uVar5;
    }
    while( true ) {
      if (*param_1 == L'\0') {
        param_1 = param_1 + 1;
        if (lVar4 == 0) {
          return uVar5;
        }
        lVar4 = lVar4 + -1;
        if (*param_1 == L'\0') {
          return uVar5;
        }
      }
      uVar6 = lVar4 + 1;
      uVar1 = uVar6;
      pwVar3 = param_1;
      if (0x7fffffff < uVar6) break;
      for (; (uVar1 != 0 && (*pwVar3 != L'\0')); pwVar3 = pwVar3 + 1) {
        uVar1 = uVar1 - 1;
      }
      uVar5 = ~-(uint)(uVar1 != 0) & 0xc000000d;
      if (uVar1 == 0) goto LAB_14000a64e;
      uVar6 = uVar6 - uVar1;
      lVar4 = lVar4 - uVar6;
      if (uVar2 <= uVar6) {
        pwVar3 = wcsstr(param_1,param_3);
        *param_5 = pwVar3;
        if (pwVar3 != (wchar_t *)0x0) {
          return uVar5;
        }
      }
      param_1 = param_1 + uVar6;
    }
    uVar5 = 0xc000000d;
LAB_14000a64e:
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar5;
    }
    uVar7 = 0x1e;
  }
  WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar7,
                    &WPP_910e8a1cc1ab306ac66fc329452f92cd_Traceguids,(char)uVar5);
  return uVar5;
}



===== WPP_RECORDER_SF_SS @ 14000a69c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_SS(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,wchar_t *param_6,wchar_t *param_7)

{
  longlong lVar1;
  longlong lVar2;
  wchar_t *pwVar3;
  longlong lVar4;
  longlong lVar5;
  wchar_t *pwVar6;
  
  lVar5 = -1;
  lVar4 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (param_7 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (param_7[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar6 = param_7;
    if (param_7 == (wchar_t *)0x0) {
      pwVar6 = L"NULL";
    }
    if (param_6 == (wchar_t *)0x0) {
      lVar2 = 10;
    }
    else {
      lVar2 = -1;
      do {
        lVar2 = lVar2 + 1;
      } while (param_6[lVar2] != L'\0');
      lVar2 = lVar2 * 2 + 2;
    }
    pwVar3 = param_6;
    if (param_6 == (wchar_t *)0x0) {
      pwVar3 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_910e8a1cc1ab306ac66fc329452f92cd_Traceguids,param_4,pwVar3,lVar2,pwVar6,lVar1,0)
    ;
  }
  if (param_7 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_7[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_7 == (wchar_t *)0x0) {
    param_7 = L"NULL";
  }
  if (param_6 != (wchar_t *)0x0) {
    do {
      lVar5 = lVar5 + 1;
    } while (param_6[lVar5] != L'\0');
    lVar4 = lVar5 * 2 + 2;
  }
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"NULL";
  }
  WppAutoLogTrace(param_1,2,1,&WPP_910e8a1cc1ab306ac66fc329452f92cd_Traceguids,param_4,param_6,lVar4
                  ,param_7,lVar1,0);
  return;
}



===== VpciDeviceResetHandler @ 14000a840 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int VpciDeviceResetHandler(undefined4 *param_1,int param_2,undefined8 param_3,uint *param_4)

{
  int iVar1;
  undefined8 local_res8;
  undefined1 uVar2;
  
  local_res8 = 0;
  uVar2 = SUB81(param_1,0);
  if (param_2 == 0) {
    if ((0x10004 < *(uint *)(*(longlong *)(param_1 + 0xc) + 0x18)) ||
       (*(char *)((longlong)param_1 + 0x341) != '\0')) {
      KeQueryPerformanceCounter(0);
      iVar1 = PdoAttemptFunctionLevelDeviceReset(param_1);
      KeQueryPerformanceCounter(&local_res8);
      if ((param_4 != (uint *)0x0) && (0x17 < *param_4)) {
        (**(code **)(param_4 + 2))(iVar1,*(undefined8 *)(param_4 + 4));
      }
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar1;
        }
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0xd,
                           &WPP_079066883c61371324bd973f6b7fcbe6_Traceguids,uVar2,(char)iVar1);
        return iVar1;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      WPP_RECORDER_SF_qIId(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      return iVar1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xc,
                        &WPP_079066883c61371324bd973f6b7fcbe6_Traceguids,uVar2);
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xb,
                       &WPP_079066883c61371324bd973f6b7fcbe6_Traceguids,uVar2,(char)param_2);
  }
  return -0x3fffff45;
}



===== WPP_RECORDER_SF_qIId @ 14000aa20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qIId(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_079066883c61371324bd973f6b7fcbe6_Traceguids,0xe,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,8,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,4,2,&WPP_079066883c61371324bd973f6b7fcbe6_Traceguids,0xe,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,8,
                  &uStack0000000000000048,4,0);
  return;
}



===== VscQueryRegistryPreferredResetMechanism @ 14000ab34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 VscQueryRegistryPreferredResetMechanism(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_a8 [32];
  int *local_88;
  undefined8 local_80;
  undefined8 local_78;
  int local_68 [2];
  undefined8 local_60;
  undefined8 local_58;
  wchar_t *local_50;
  wchar_t local_48 [28];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_a8;
  local_88 = (int *)&local_60;
  local_60 = 0;
  local_68[0] = 0;
  uVar2 = 1;
  builtin_wcsncpy(local_48,L"PreferredPdoResetMechanism",0x1b);
  local_50 = local_48;
  local_58 = 0x360034;
  iVar1 = (**(code **)(WdfFunctions_01033 + 0x3b8))(WdfDriverGlobals,*WdfDriverGlobals,0x80000000,0)
  ;
  if (-1 < iVar1) {
    local_88 = local_68;
    local_78 = 0;
    local_80 = 0;
    iVar1 = (**(code **)(WdfFunctions_01033 + 0x758))(WdfDriverGlobals,local_60,&local_58,4);
    if ((-1 < iVar1) && (local_68[0] == 1)) {
      uVar2 = 0;
    }
    (**(code **)(WdfFunctions_01033 + 0x738))(WdfDriverGlobals,local_60);
  }
  return uVar2;
}



===== FxStubDriverUnloadCommon @ 14000ac68 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  void **ppvVar1;
  void **ppvVar2;
  
  ppvVar1 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_140010638 != &__KMDF_CLASS_BIND_START) {
    ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_140010638 + 0x50);
    if (*(int *)PTR___KMDF_CLASS_BIND_START_140010638 == 0x78) {
      ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_140010638 + 0x78);
    }
    while( true ) {
      for (; (ppvVar1 + 1 <= ppvVar2 && (*ppvVar1 == (void *)0x0)); ppvVar1 = ppvVar1 + 1) {
      }
      if (ppvVar1 < ppvVar2) break;
      ppvVar1 = ppvVar2;
LAB_14000acd8:
      if (ppvVar1 == (void **)0x0) goto LAB_14000ad31;
      if (ppvVar2 <= ppvVar1) goto LAB_14000ad49;
      if (ppvVar1[8] == (code *)0x0) {
        WdfVersionUnbindClass(&DAT_1400100e0,WdfDriverGlobals,ppvVar1);
      }
      else {
        (*ppvVar1[8])(WdfVersionUnbindClass_exref,&DAT_1400100e0,WdfDriverGlobals,ppvVar1);
      }
      ppvVar1 = (void **)((longlong)ppvVar1 + (ulonglong)*(uint *)ppvVar1);
    }
    if (((ppvVar1 + 10 <= ppvVar2) && (*(uint *)ppvVar1 == 0x50)) ||
       ((ppvVar1 + 0xf <= ppvVar2 && (*(uint *)ppvVar1 == 0x78)))) goto LAB_14000acd8;
LAB_14000ad31:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_14000ad49:
  WdfVersionUnbind(&DAT_1400109c0,&DAT_1400100e0,WdfDriverGlobals);
  return;
}



===== entry @ 14000ad80 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 14000adb4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FxDriverEntryWorker(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  _WDF_BIND_INFO *p_Var3;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  if (param_1 == (_WDF_BIND_INFO *)0x0) {
    iVar1 = DriverEntry((undefined8 *)0x0,param_2);
  }
  else {
    _DAT_1400109c0 = 0x2080000;
    _DAT_1400109c8 = &DAT_1400107b0;
    RtlCopyUnicodeString(&DAT_1400109c0);
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_1400109c0,&DAT_1400100e0,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry((undefined8 *)param_1,param_2);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_1400109b8 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_1400109c0);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_140010638 != &__KMDF_CLASS_BIND_START) {
          local_1c = 0;
          uStack_18 = 0;
          local_28 = &GUID_WDF_LOADER_INTERFACE_DRIVER_ENTRY_FAILURE;
          local_14 = 0;
          local_20 = 0x18;
          iVar2 = WdfLdrQueryInterface(&local_28);
          if (-1 < iVar2) {
            (*(code *)CONCAT44(local_14,uStack_18))(&DAT_1400100e0,WdfDriverGlobals);
          }
        }
      }
      FxStubDriverUnloadCommon();
    }
  }
  return iVar1;
}



===== FxStubDriverUnload @ 14000af40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_1400109b8 != (code *)0x0) && (DAT_1400109b8 != FxStubDriverUnload)) {
    (*DAT_1400109b8)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 14000af74 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x00014000af99) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  int iVar1;
  void **ppvVar2;
  
  iVar1 = 0;
  ppvVar2 = &__KMDF_CLASS_BIND_END;
  while( true ) {
    for (; (ppvVar2 + 1 < (void **)((longlong)&__KMDF_CLASS_BIND_END + 1) &&
           (*ppvVar2 == (void *)0x0)); ppvVar2 = ppvVar2 + 1) {
    }
    if ((void **)0x14001062f < ppvVar2) break;
    if ((((&__KMDF_CLASS_BIND_END < ppvVar2 + 10) || (*(uint *)ppvVar2 != 0x50)) &&
        ((&__KMDF_CLASS_BIND_END < ppvVar2 + 0xf || (*(uint *)ppvVar2 != 0x78)))) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_140010638 = (undefined *)ppvVar2;
    if (ppvVar2[7] == (code *)0x0) {
      iVar1 = WdfVersionBindClass(&DAT_1400100e0,WdfDriverGlobals,ppvVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: VersionBindClass WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,ppvVar2,ppvVar2[1],iVar1);
        return iVar1;
      }
    }
    else {
      iVar1 = (*ppvVar2[7])(WdfVersionBindClass_exref,&DAT_1400100e0,WdfDriverGlobals,ppvVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: ClientBindClass %p, WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,ppvVar2[7],ppvVar2,ppvVar2[1],iVar1);
        return iVar1;
      }
    }
    ppvVar2 = (void **)((longlong)ppvVar2 + (ulonglong)*(uint *)ppvVar2);
  }
  return iVar1;
}



===== FxStubInitTypes @ 14000b108 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x00014000b125) */
/* long __cdecl FxStubInitTypes(void) */

long __cdecl FxStubInitTypes(void)

{
  void *pvVar1;
  void **ppvVar2;
  
  ppvVar2 = &__KMDF_TYPE_INIT_END;
  while( true ) {
    for (; (ppvVar2 + 1 < (void **)((longlong)&__KMDF_TYPE_INIT_END + 1) &&
           (*ppvVar2 == (void *)0x0)); ppvVar2 = ppvVar2 + 1) {
    }
    if ((void **)0x14001064f < ppvVar2) break;
    if (((&__KMDF_TYPE_INIT_END < ppvVar2 + 5) || (*(uint *)ppvVar2 != 0x28)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextObjectContextTypeInfo failed\n");
      return -0x3fffff85;
    }
    if (ppvVar2[4] != (code *)0x0) {
      pvVar1 = (void *)(*ppvVar2[4])();
      ppvVar2[3] = pvVar1;
    }
    ppvVar2 = (void **)((ulonglong)*(uint *)ppvVar2 + (longlong)ppvVar2);
  }
  return 0;
}



===== PciGetLengthFromBar @ 14000b1d0 =====

ulonglong PciGetLengthFromBar(int param_1,uint param_2)

{
  ulonglong uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar2 = (-(uint)((param_2 & 1) != 0) & 0xc) - 0x10 & param_2;
  uVar3 = (ulonglong)uVar2;
  if (param_1 == 0) {
    uVar1 = (ulonglong)-uVar2;
  }
  else {
    uVar3 = CONCAT44(param_1,uVar2);
    uVar1 = -uVar3;
  }
  if ((uVar1 & uVar1 - 1) != 0) {
    for (uVar1 = 4; (uVar3 | uVar1) != uVar3; uVar1 = uVar1 * 2) {
    }
  }
  return uVar1;
}



===== HviGetPartitionIsolationType @ 14000b22c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014000b27b) */
/* WARNING: Removing unreachable block (ram,0x00014000b259) */

uint HviGetPartitionIsolationType(void)

{
  longlong lVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  uStack_20 = 0;
  uVar2 = HviIsHypervisorMicrosoftCompatible();
  if (((char)uVar2 == '\0') || (lVar1 = cpuid(0x40000003), (*(uint *)(lVar1 + 4) & 0x400000) == 0))
  {
    uVar3 = 0;
  }
  else {
    lVar1 = cpuid(0x4000000c);
    uVar3 = *(uint *)(lVar1 + 4) & 0xf;
  }
  return uVar3;
}



===== HviGetSharedGpaBoundary @ 14000b2a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014000b2ef) */
/* WARNING: Removing unreachable block (ram,0x00014000b2cd) */

longlong HviGetSharedGpaBoundary(void)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  uStack_20 = 0;
  uVar2 = HviIsHypervisorMicrosoftCompatible();
  if (((char)uVar2 != '\0') && (lVar1 = cpuid(0x40000003), (*(uint *)(lVar1 + 4) & 0x400000) != 0))
  {
    lVar1 = cpuid(0x4000000c);
    if ((*(uint *)(lVar1 + 4) & 0x20) != 0) {
      return 1L << ((byte)(*(uint *)(lVar1 + 4) >> 6) & 0x3f);
    }
  }
  return 0;
}



===== HviIsAnyHypervisorPresent @ 14000b324 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014000b358) */
/* WARNING: Removing unreachable block (ram,0x00014000b347) */

undefined8 HviIsAnyHypervisorPresent(void)

{
  uint *puVar1;
  ulonglong uVar2;
  undefined1 uVar3;
  
  puVar1 = (uint *)cpuid_Version_info(1);
  uVar2 = (ulonglong)*puVar1;
  uVar3 = 0;
  if ((int)puVar1[3] < 0) {
    puVar1 = (uint *)cpuid(0x40000001);
    uVar2 = (ulonglong)*puVar1;
    uVar3 = 0;
    if (*puVar1 != 0x766e6258) {
      uVar3 = 1;
    }
  }
  return CONCAT71((int7)(uVar2 >> 8),uVar3);
}



===== HviIsHypervisorMicrosoftCompatible @ 14000b380 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014000b3ad) */

undefined4 HviIsHypervisorMicrosoftCompatible(void)

{
  int *piVar1;
  undefined8 uVar2;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  uStack_20 = 0;
  uVar2 = HviIsAnyHypervisorPresent();
  if ((char)uVar2 == '\0') {
  }
  else {
    piVar1 = (int *)cpuid(0x40000001);
    local_28._0_4_ = *piVar1;
  }
  return CONCAT31((int3)((uint)(int)local_28 >> 8),(int)local_28 == 0x31237648);
}



===== __GSHandlerCheck @ 14000b3e8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000b40c =====

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



===== __security_check_cookie @ 14000b480 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== RtlCopyVolatileMemory @ 14000b4b0 =====

void * __cdecl RtlCopyVolatileMemory(void *_Dst,void *_Src,size_t _Size)

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



===== RtlMoveVolatileMemory @ 14000b4c0 =====

void * __cdecl RtlMoveVolatileMemory(void *_Dst,void *_Src,size_t _Size)

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



===== RtlSetVolatileMemory @ 14000b4d0 =====

void * __cdecl RtlSetVolatileMemory(void *_Dst,int _Val,size_t _Size)

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



===== _guard_dispatch_icall @ 14000b500 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 14000b530 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014000b530. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 14000b560 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 14000b5c0 =====

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



===== memset @ 14000b8c0 =====

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



===== __memset_repmovs @ 14000ba00 =====

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



===== __memset_query @ 14000ba80 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 14000bb00 =====

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



===== __memset_spec_ermsb_repmovsb @ 14000bc40 =====

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



===== __memset_spec_plain @ 14000bcc0 =====

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



===== memset$thunk$772440563353939046 @ 14000c020 =====

void * __cdecl memset_thunk_772440563353939046(void *_Dst,int _Val,size_t _Size)

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



===== VpciCreateControlDevice @ 140014008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int VpciCreateControlDevice(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined2 uVar4;
  undefined1 auStackY_178 [32];
  longlong local_148 [2];
  wchar_t *local_138;
  undefined8 local_130;
  wchar_t *local_128;
  ulonglong local_120 [6];
  undefined *local_f0;
  undefined8 local_e8;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined1 local_cb;
  code *local_b0;
  wchar_t local_78 [28];
  wchar_t local_40 [16];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_178;
  local_e8 = 0;
  local_f0 = (undefined *)((ulonglong)local_f0 & 0xffffffff00000000);
  local_120[0] = 0;
  local_120[1] = 0;
  local_120[2] = 0;
  local_120[3] = 0;
  local_120[4] = 0;
  local_120[5] = 0;
  memset(&local_d8,0,0x60);
  KeWaitForSingleObject(&VpciGlobalLock,0,0,0);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,10,
                     &WPP_d4229ffb816639c2bfc88a981e2c5ec6_Traceguids);
  }
  local_148[0] = (**(code **)(WdfFunctions_01033 + 200))
                           (WdfDriverGlobals,param_1,&SDDL_DEVOBJ_SYS_ALL_ADM_ALL);
  if (local_148[0] == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xb,
                       &WPP_d4229ffb816639c2bfc88a981e2c5ec6_Traceguids);
    }
    iVar1 = -0x3fffff66;
  }
  else {
    local_138 = local_40;
    builtin_wcsncpy(local_78,L"\\DosDevices\\Global\\VPCIVSC",0x1b);
    builtin_wcsncpy(local_40,L"\\Device\\VPCIVSC",0x10);
    local_148[1] = 0x20001e;
    local_130 = 0x360034;
    local_128 = local_78;
    iVar1 = (**(code **)(WdfFunctions_01033 + 0x218))(WdfDriverGlobals,local_148[0],local_148 + 1);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar4 = 0xc;
LAB_14001439c:
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar4,
                          &WPP_d4229ffb816639c2bfc88a981e2c5ec6_Traceguids,(char)iVar1);
      }
    }
    else {
      local_120[1] = 0;
      local_120[2] = 0;
      local_120[4] = 0;
      local_120[5] = 0;
      if (WdfClientVersionHigherThanFramework == '\0') {
        local_120[0] = 0x38;
      }
      else if (WdfStructureCount < 0x27) {
        local_120[0] = 0xffffffff;
      }
      else {
        local_120[0] = (ulonglong)*(uint *)(WdfStructures + 0x130);
      }
      local_f0 = PTR__WDF_VPCI_VSC_CTRL_DEVICE_DATA_TYPE_INFO_140010018;
      local_120[3] = 0x100000001;
      iVar1 = (**(code **)(WdfFunctions_01033 + 600))
                        (WdfDriverGlobals,local_148,local_120,&VpciCtrlDev);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar4 = 0xd;
          goto LAB_14001439c;
        }
      }
      else {
        local_148[0] = 0;
        lVar2 = (**(code **)(WdfFunctions_01033 + 0x650))
                          (WdfDriverGlobals,VpciCtrlDev,
                           PTR__WDF_VPCI_VSC_CTRL_DEVICE_DATA_TYPE_INFO_140010018);
        *(longlong *)(lVar2 + 8) = lVar2;
        *(longlong *)lVar2 = lVar2;
        lVar3 = lVar2 + 0x10;
        *(longlong *)(lVar2 + 0x18) = lVar3;
        *(longlong *)lVar3 = lVar3;
        if (WdfClientVersionHigherThanFramework == '\0') {
          local_d8 = 0x60;
        }
        else if (WdfStructureCount < 0x22) {
          local_d8 = 0xffffffff;
        }
        else {
          local_d8 = *(undefined4 *)(WdfStructures + 0x108);
        }
        local_d0 = 0;
        local_b0 = VpciCtrlDevEvtIoDeviceControl;
        local_cb = 1;
        local_d4 = 1;
        iVar1 = (**(code **)(WdfFunctions_01033 + 0x4c0))(WdfDriverGlobals,VpciCtrlDev,&local_d8,0);
        if (iVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar4 = 0xe;
            goto LAB_14001439c;
          }
        }
        else {
          iVar1 = (**(code **)(WdfFunctions_01033 + 0x280))(WdfDriverGlobals,VpciCtrlDev,&local_130)
          ;
          if (iVar1 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar4 = 0xf;
              goto LAB_14001439c;
            }
          }
          else {
            iVar1 = VscProxyInitialize();
            if (-1 < iVar1) {
              (**(code **)(WdfFunctions_01033 + 0xd8))(WdfDriverGlobals,VpciCtrlDev);
              goto LAB_14001442e;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar4 = 0x10;
              goto LAB_14001439c;
            }
          }
        }
      }
    }
  }
  if (local_148[0] != 0) {
    (**(code **)(WdfFunctions_01033 + 0x1b0))(WdfDriverGlobals);
    local_148[0] = 0;
  }
  if (VpciCtrlDev != 0) {
    KeSetEvent(&VpciGlobalLock,0,0);
    VpciDestroyControlDevice();
    return iVar1;
  }
LAB_14001442e:
  KeSetEvent(&VpciGlobalLock,0,0);
  return iVar1;
}



===== VpciCtrlDevEvtIoDeviceControl @ 140014480 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VpciCtrlDevEvtIoDeviceControl
               (undefined8 param_1,longlong param_2,undefined8 param_3,ulonglong param_4,
               uint param_5)

{
  int iVar1;
  ulonglong uVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  
  KeWaitForSingleObject(&VpciGlobalLock,0,0,0,0);
  if (param_5 < 0x220015) {
    if (param_5 == 0x220014) {
      cVar4 = '\0';
    }
    else {
      if (param_5 == 0x220000) {
        cVar4 = '\0';
        goto LAB_140014553;
      }
      if (param_5 == 0x220004) {
        cVar4 = '\0';
        goto LAB_140014507;
      }
      if (param_5 != 0x220008) {
        if (param_5 == 0x22000c) {
          cVar4 = '\0';
          goto LAB_1400144ed;
        }
        if (param_5 != 0x220010) goto LAB_140014531;
        cVar4 = '\0';
        goto LAB_1400144e0;
      }
      cVar4 = '\x01';
    }
    iVar1 = VscProxyHandleIoctlClearDeviceProxyPath(param_2,param_4,cVar4);
  }
  else {
    if (param_5 == 0x220018) {
      cVar4 = '\x01';
LAB_140014553:
      cVar5 = '\x01';
      cVar3 = '\x01';
    }
    else if (param_5 == 0x22001c) {
      cVar4 = '\x01';
LAB_140014507:
      cVar5 = '\0';
      cVar3 = '\x01';
    }
    else {
      if (param_5 == 0x220020) {
        cVar4 = '\x01';
LAB_1400144ed:
        cVar5 = '\x01';
      }
      else {
        if (param_5 != 0x220024) {
LAB_140014531:
          iVar1 = -0x3ffffffe;
          goto LAB_140014567;
        }
        cVar4 = '\x01';
LAB_1400144e0:
        cVar5 = '\0';
      }
      cVar3 = '\0';
    }
    uVar2 = VscProxyHandleIoctlAddRemoveDeviceProxyPath(param_2,param_4,cVar3,cVar5,cVar4);
    iVar1 = (int)uVar2;
  }
LAB_140014567:
  (**(code **)(WdfFunctions_01033 + 0x848))(WdfDriverGlobals,param_2,iVar1,0);
  KeSetEvent(&VpciGlobalLock,0,0);
  return;
}



===== VpciDestroyControlDevice @ 1400145b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VpciDestroyControlDevice(void)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  longlong *plVar4;
  undefined1 *puVar5;
  undefined1 auStackY_38 [8];
  undefined1 auStackY_30 [24];
  
  KeWaitForSingleObject(&VpciGlobalLock,0,0,0);
  puVar5 = auStackY_38;
  if (VpciCtrlDev != 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x11,
                       &WPP_d4229ffb816639c2bfc88a981e2c5ec6_Traceguids);
    }
    plVar4 = (longlong *)
             (**(code **)(WdfFunctions_01033 + 0x650))
                       (WdfDriverGlobals,VpciCtrlDev,
                        PTR__WDF_VPCI_VSC_CTRL_DEVICE_DATA_TYPE_INFO_140010018);
    puVar5 = auStackY_38;
    while (plVar1 = (longlong *)*plVar4, plVar1 != plVar4) {
      if (((longlong *)plVar1[1] != plVar4) ||
         (lVar2 = *plVar1, (longlong *)*(longlong *)(lVar2 + 8) != plVar1)) {
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        puVar5 = auStackY_30;
        break;
      }
      *plVar4 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar4;
      if (plVar1[5] != 0) {
        ExFreePoolWithTag(plVar1[5],0x69637056);
        plVar1[5] = 0;
      }
      ExFreePoolWithTag(plVar1,0x69637056);
    }
    pcVar3 = *(code **)(WdfFunctions_01033 + 0x680);
    *(undefined8 *)(puVar5 + -8) = 0x1400146cb;
    (*pcVar3)(WdfDriverGlobals,VpciCtrlDev);
    VpciCtrlDev = 0;
  }
  *(undefined8 *)(puVar5 + -8) = 0x1400146e6;
  KeSetEvent(&VpciGlobalLock,0,0);
  return;
}



===== VpciLinkUnlinkFdoContext @ 140014700 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VpciLinkUnlinkFdoContext(longlong *param_1,char param_2)

{
  longlong *plVar1;
  code *pcVar2;
  longlong lVar3;
  
  lVar3 = (**(code **)(WdfFunctions_01033 + 0x650))
                    (WdfDriverGlobals,VpciCtrlDev,
                     PTR__WDF_VPCI_VSC_CTRL_DEVICE_DATA_TYPE_INFO_140010018);
  KeWaitForSingleObject(&VpciGlobalLock,0,0,0,0);
  if (param_2 == '\0') {
    lVar3 = *param_1;
    if ((*(longlong **)(lVar3 + 8) != param_1) ||
       (plVar1 = (longlong *)param_1[1], (longlong *)*plVar1 != param_1)) goto LAB_1400147c3;
    *plVar1 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar1;
  }
  else {
    plVar1 = *(longlong **)(lVar3 + 0x18);
    if (*plVar1 != lVar3 + 0x10) {
LAB_1400147c3:
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    *param_1 = lVar3 + 0x10;
    param_1[1] = (longlong)plVar1;
    *plVar1 = (longlong)param_1;
    *(longlong **)(lVar3 + 0x18) = param_1;
  }
  KeSetEvent(&VpciGlobalLock,0,0);
  return;
}



===== VscProxyHandleIoctlAddRemoveDeviceProxyPath @ 1400147d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong VscProxyHandleIoctlAddRemoveDeviceProxyPath
                    (longlong param_1,ulonglong param_2,char param_3,char param_4,char param_5)

{
  char cVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  wchar_t *pwVar6;
  longlong lVar7;
  ulonglong uVar8;
  wchar_t *pwVar9;
  wchar_t *pwVar10;
  uint uVar11;
  undefined *puVar12;
  wchar_t *pwVar13;
  undefined2 uVar14;
  uint **ppuVar15;
  int iVar16;
  uint *local_38;
  uint *local_30;
  longlong local_28 [2];
  
  local_30 = (uint *)0x0;
  local_38 = (uint *)0x0;
  local_28[0] = 0;
  lVar7 = param_1;
  if (param_3 == '\0') {
    if (0x13 < param_2) {
      ppuVar15 = &local_30;
      uVar11 = (**(code **)(WdfFunctions_01033 + 0x868))(WdfDriverGlobals,param_1,0x14,ppuVar15,0);
      uVar8 = (ulonglong)uVar11;
      if ((int)uVar11 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return uVar8;
        }
        uVar14 = 0x16;
        goto LAB_14001489f;
      }
      uVar11 = local_30[4];
      uVar8 = (ulonglong)uVar11;
      if (uVar8 <= param_2 - 0x14) {
        uVar3 = (ulonglong)*local_30;
        pwVar10 = (wchar_t *)(local_30 + 1);
        pwVar9 = (wchar_t *)(local_30 + 5);
        goto LAB_1400149e5;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc000000d;
      }
      uVar14 = 0x17;
      goto LAB_1400148f7;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    uVar14 = 0x15;
  }
  else {
    if (3 < param_2) {
      ppuVar15 = &local_38;
      uVar11 = (**(code **)(WdfFunctions_01033 + 0x868))(WdfDriverGlobals);
      uVar8 = (ulonglong)uVar11;
      if ((int)uVar11 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return uVar8;
        }
        uVar14 = 0x13;
LAB_14001489f:
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar14,
                          &WPP_d4229ffb816639c2bfc88a981e2c5ec6_Traceguids,(char)uVar8);
        return uVar8;
      }
      uVar11 = *local_38;
      uVar8 = (ulonglong)uVar11;
      if (uVar8 <= param_2 - 4) {
        pwVar10 = (wchar_t *)0x0;
        pwVar9 = (wchar_t *)(local_38 + 1);
        uVar3 = 0;
LAB_1400149e5:
        uVar2 = VscProxyCheckDeviceLocationPath((longlong)pwVar9,uVar8,0x60);
        if ((char)uVar2 == '\0') {
          return 0xc000000d;
        }
        if ((pwVar10 != (wchar_t *)0x0) &&
           (uVar3 = VscProxyCheckDeviceCustomPrefix((longlong)pwVar10,uVar3), (char)uVar3 == '\0'))
        {
          return 0xc000000d;
        }
        uVar3 = VscProxyGetDevice(pwVar9,uVar8,local_28);
        iVar16 = (int)uVar3;
        uVar3 = uVar3 & 0xffffffff;
        if (iVar16 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return uVar3;
          }
          uVar14 = 0x18;
          uVar11 = 2;
        }
        else {
          lVar7 = local_28[0];
          puVar12 = PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8;
          lVar4 = (**(code **)(WdfFunctions_01033 + 0x650))
                            (WdfDriverGlobals,local_28[0],
                             PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8);
          if (((param_4 != '\0') && (*(int *)(lVar4 + 0x28) != 10)) &&
             (cVar1 = (**(code **)(WdfFunctions_01033 + 0x8c0))(WdfDriverGlobals), lVar7 = param_1,
             cVar1 != '\0')) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,2,0x19,
                                &WPP_d4229ffb816639c2bfc88a981e2c5ec6_Traceguids,pwVar9);
            }
            return 0xc0000184;
          }
          uVar8 = CONCAT71((int7)((ulonglong)lVar7 >> 8),param_5);
          pwVar9 = (wchar_t *)(lVar4 + 0x24c);
          pwVar13 = (wchar_t *)CONCAT71((int7)((ulonglong)puVar12 >> 8),1);
          pwVar6 = DefaultPrefixPcip;
          if (pwVar10 != (wchar_t *)0x0) {
            pwVar6 = pwVar10;
          }
          puVar5 = VscGetOrCreateProxy(pwVar6,param_5,'\x01');
          if (puVar5 != (undefined8 *)0x0) {
            if (param_4 == '\0') {
              uVar11 = VscProxyRemoveDevicePath((longlong)puVar5,pwVar9,pwVar13,ppuVar15);
            }
            else {
              uVar11 = VscProxyAddDevicePath((longlong)puVar5,pwVar9,pwVar13,ppuVar15);
            }
            if ((int)uVar11 < 0) {
              return (ulonglong)uVar11;
            }
            uVar11 = VscProxyWriteDevicePathsToRegistry((longlong)puVar5);
            if ((int)uVar11 < 0) {
              return (ulonglong)uVar11;
            }
            VscProxyHandleIoctlRescanBus();
            return (ulonglong)uVar11;
          }
          uVar3 = 0xc000009a;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return 0xc000009a;
          }
          iVar16 = -0x3fffff66;
          uVar14 = 0x1a;
          uVar11 = 1;
        }
        WPP_RECORDER_SF_Sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,uVar11,uVar14,
                           &WPP_d4229ffb816639c2bfc88a981e2c5ec6_Traceguids,pwVar9,(char)iVar16);
        return uVar3;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc000000d;
      }
      uVar14 = 0x14;
LAB_1400148f7:
      WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar7,2,uVar14,
                         &WPP_d4229ffb816639c2bfc88a981e2c5ec6_Traceguids,(char)param_2,(char)uVar11
                        );
      return 0xc000000d;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000000d;
    }
    uVar14 = 0x12;
  }
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar14,
                   &WPP_d4229ffb816639c2bfc88a981e2c5ec6_Traceguids);
  return 0xc000000d;
}



===== VscProxyHandleIoctlClearDeviceProxyPath @ 140014bb8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int VscProxyHandleIoctlClearDeviceProxyPath(undefined8 param_1,ulonglong param_2,char param_3)

{
  bool bVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  wchar_t *pwVar7;
  undefined2 uVar8;
  uint *local_res20;
  
  local_res20 = (uint *)0x0;
  bVar1 = false;
  if (param_3 == '\0') {
    if (param_2 < 0x10) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x1b,
                         &WPP_d4229ffb816639c2bfc88a981e2c5ec6_Traceguids);
      }
      return -0x3ffffff3;
    }
    iVar2 = (**(code **)(WdfFunctions_01033 + 0x868))(WdfDriverGlobals,param_1,0x10,&local_res20,0);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar2;
      }
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x1c,
                        &WPP_d4229ffb816639c2bfc88a981e2c5ec6_Traceguids,(char)iVar2);
      return iVar2;
    }
    pwVar7 = (wchar_t *)(local_res20 + 1);
    if (pwVar7 == (wchar_t *)0x0) goto LAB_140014cbb;
    uVar3 = VscProxyCheckDeviceCustomPrefix((longlong)pwVar7,(ulonglong)*local_res20);
    if ((char)uVar3 == '\0') {
      return -0x3ffffff3;
    }
  }
  else {
LAB_140014cbb:
    pwVar7 = DefaultPrefixPcip;
  }
  uVar6 = 0;
  puVar4 = VscGetOrCreateProxy(pwVar7,'\0','\0');
  uVar6 = CONCAT71((int7)((ulonglong)uVar6 >> 8),1);
  puVar5 = VscGetOrCreateProxy(pwVar7,'\x01','\0');
  if (puVar4 == (undefined8 *)0x0) {
    if (puVar5 == (undefined8 *)0x0) {
      iVar2 = -0x3ffffff3;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3ffffff3;
      }
      uVar8 = 0x1d;
      goto LAB_140014d08;
    }
LAB_140014d36:
    if (((undefined2 *)puVar5[5] != (undefined2 *)0x0) && (puVar5[4] != 0)) {
      *(undefined2 *)puVar5[5] = 0;
      bVar1 = true;
      puVar5[4] = 2;
    }
    if (puVar4 == (undefined8 *)0x0) goto LAB_140014d9e;
  }
  else if (puVar5 != (undefined8 *)0x0) goto LAB_140014d36;
  if (((undefined2 *)puVar4[5] != (undefined2 *)0x0) && (puVar4[4] != 0)) {
    *(undefined2 *)puVar4[5] = 0;
    puVar4[4] = 2;
    bVar1 = true;
    iVar2 = VscProxyWriteDevicePathsToRegistry((longlong)puVar4);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar2;
      }
      uVar8 = 0x1e;
LAB_140014d08:
      WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,1,uVar8,
                        &WPP_d4229ffb816639c2bfc88a981e2c5ec6_Traceguids,pwVar7);
      return iVar2;
    }
  }
LAB_140014d9e:
  if (bVar1) {
    VscProxyHandleIoctlRescanBus();
  }
  return 0;
}



===== VpciDriverUnload @ 140014dd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VpciDriverUnload(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (PowerCallbackRegistrationHandle != 0) {
    ExUnregisterCallback();
  }
  if (PowerCallbackObj != 0) {
    ObfDereferenceObject();
  }
  if (VpciKsrNotificationEntry != 0) {
    iVar1 = IoUnregisterPlugPlayNotificationEx();
    if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,1,0xe,
                        &WPP_22a9fd12f6cd35a16fbcc6041c1a0b1b_Traceguids,(char)iVar1);
    }
    VpciKsrNotificationEntry = 0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xf,
                     &WPP_22a9fd12f6cd35a16fbcc6041c1a0b1b_Traceguids);
  }
  uVar2 = (**(code **)(WdfFunctions_01033 + 0x3b0))(WdfDriverGlobals,param_1);
  WppCleanupKm(uVar2);
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



===== VpciKsrPnpNotificationCallback @ 140014f30 =====

ulonglong VpciKsrPnpNotificationCallback(short *param_1)

{
  ulonglong uVar1;
  
  if ((*param_1 == 1) && (0x13 < (ushort)param_1[1])) {
    uVar1 = 0;
    KeWaitForSingleObject(&VpciGlobalLock,0,0,0,0);
    if ((*(longlong *)(param_1 + 2) == 0x4f76a85cde373def) &&
       (*(longlong *)(param_1 + 6) == 0xfd18bea6bf9bf8c)) {
      uVar1 = VpciKsrPrepare();
      uVar1 = uVar1 & 0xffffffff;
    }
    KeSetEvent(&VpciGlobalLock,0,0);
  }
  else {
    uVar1 = 0xc00000bb;
  }
  return uVar1;
}



===== VpciKsrPrepare @ 140014fc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 VpciKsrPrepare(void)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  bool bVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  longlong lVar7;
  undefined1 auStackY_1a8 [32];
  longlong local_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  ulonglong local_138;
  undefined4 *puStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  ulonglong local_118;
  undefined4 local_108;
  undefined1 local_104 [220];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_1a8;
  local_168 = 0;
  local_118 = local_118 & 0xffffffff00000000;
  local_140 = 0;
  local_138 = 0;
  puStack_130 = (undefined4 *)0x0;
  local_128 = 0;
  uStack_120 = 0;
  local_160 = 0;
  uStack_158 = 0;
  local_150 = 0;
  uStack_148 = 0;
  memset(&local_108,0,0xe0);
  if (VpciCtrlDev != 0) {
    bVar3 = false;
    lVar5 = (**(code **)(WdfFunctions_01033 + 0x650))
                      (WdfDriverGlobals,VpciCtrlDev,
                       PTR__WDF_VPCI_VSC_CTRL_DEVICE_DATA_TYPE_INFO_140010018);
    for (puVar2 = *(undefined8 **)(lVar5 + 0x10); puVar2 != (undefined8 *)(lVar5 + 0x10);
        puVar2 = (undefined8 *)*puVar2) {
      (**(code **)(WdfFunctions_01033 + 0x9c8))(WdfDriverGlobals,puVar2[4],0);
      uVar6 = (**(code **)(WdfFunctions_01033 + 0x420))(WdfDriverGlobals,puVar2[2]);
      uStack_158 = 0;
      local_140 = 0;
      local_150 = 0;
      uStack_148 = 0;
      if (WdfClientVersionHigherThanFramework == '\0') {
        uVar1 = 0x28;
      }
      else if (WdfStructureCount < 4) {
        uVar1 = 0xffffffff;
      }
      else {
        uVar1 = *(undefined4 *)(WdfStructures + 0x18);
      }
      local_160 = CONCAT44(5,uVar1);
      (**(code **)(WdfFunctions_01033 + 0x30))(WdfDriverGlobals,uVar6,&local_160);
      do {
        local_168 = 0;
        memset(local_104,0,0xdc);
        local_108 = 0xe0;
        local_118 = 0;
        local_128 = 0;
        uStack_120 = 0;
        if (WdfClientVersionHigherThanFramework == '\0') {
          local_138 = 0x28;
        }
        else if (WdfStructureCount < 5) {
          local_138 = 0xffffffff;
        }
        else {
          local_138 = (ulonglong)*(uint *)(WdfStructures + 0x20);
        }
        puStack_130 = &local_108;
        iVar4 = (**(code **)(WdfFunctions_01033 + 0x38))
                          (WdfDriverGlobals,uVar6,&local_160,&local_168);
        if (iVar4 < 0) {
          if ((iVar4 != -0x7fffffe6) &&
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x10,
                               &WPP_22a9fd12f6cd35a16fbcc6041c1a0b1b_Traceguids,(char)puVar2,
                               (char)iVar4);
          }
          goto LAB_140015242;
        }
      } while ((local_168 == 0) ||
              (lVar7 = (**(code **)(WdfFunctions_01033 + 0x650))
                                 (WdfDriverGlobals,local_168,
                                  PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8),
              *(int *)(lVar7 + 0x328) == 0));
      bVar3 = true;
LAB_140015242:
      (**(code **)(WdfFunctions_01033 + 0x40))(WdfDriverGlobals,uVar6);
      (**(code **)(WdfFunctions_01033 + 0x9d0))(WdfDriverGlobals,puVar2[4]);
      if (bVar3) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,0x11,
                           &WPP_22a9fd12f6cd35a16fbcc6041c1a0b1b_Traceguids);
        }
        return 0xc00000bb;
      }
    }
  }
  return 0;
}



===== VpciPowerStateCallback @ 140015300 =====

void VpciPowerStateCallback(undefined8 param_1,int param_2,int param_3)

{
  if (param_2 == 3) {
    if (param_3 == 0) {
      SleepPageLock = MmLockPagableDataSection(VpciPowerStateCallback);
      SleepPageLockValid = '\x01';
    }
    else if ((param_3 == 1) && (SleepPageLockValid != '\0')) {
      MmUnlockPagableImageSection(SleepPageLock);
      SleepPageLock = 0;
      SleepPageLockValid = '\0';
    }
  }
  return;
}



===== WppCleanupKm @ 140015370 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppCleanupKm(undefined8 param_1)

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
    WppAutoLogStop(WPP_GLOBAL_Control,param_1);
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
    WPP_RECORDER_INITIALIZED = (undefined *)&WPP_RECORDER_INITIALIZED;
  }
  return;
}



===== WppInitKm @ 140015420 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppInitKm(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined *puVar2;
  
  if (WPP_GLOBAL_Control != &WPP_MAIN_CB) {
    WPP_GLOBAL_Control = &WPP_MAIN_CB;
    if (WPPTraceSuite == 4) {
      puVar2 = &WPP_MAIN_CB;
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
    WppAutoLogStart(WPP_GLOBAL_Control,param_1,param_2);
    WPP_RECORDER_INITIALIZED = &WPP_MAIN_CB;
  }
  return;
}



===== WppLoadTracingSupport @ 1400154fc =====

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



===== WppTraceCallback @ 140015640 =====

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



===== wil_details_EvaluateFeatureDependencies @ 1400158c8 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  uint uVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  bool bVar5;
  
  puVar4 = (undefined *)0x0;
  ppuVar3 = &Feature_VpciInterruptTargetFix__private_descriptor;
  ppuVar2 = &Feature_VpciInterruptTargetFix__private_descriptor;
  do {
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x000140015903;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_14001597d:
  while( true ) {
    if (&UNK_14000f9ff < ppuVar3) {
      return;
    }
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  do {
    if (ppuVar3 == (undefined **)0x0) {
      return;
    }
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*ppuVar3,(longlong)ppuVar3);
    ppuVar3 = ppuVar3 + 7;
    while( true ) {
      if (&UNK_14000f9ff < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x000140015903:
  while (ppuVar2 != (undefined **)0x0) {
    uVar1 = *(uint *)*ppuVar2;
    if ((uVar1 >> 9 & 1) != 0) {
      if ((uVar1 & 0x180) == 0) {
        bVar5 = *(char *)((longlong)ppuVar2 + 0x1f) != '\0';
      }
      else {
        bVar5 = (uVar1 & 0x180) == 0x100;
      }
      LOCK();
      *(uint *)*ppuVar2 = *(uint *)*ppuVar2 ^ uVar1 & 0x40 ^ (uint)bVar5 << 6;
      UNLOCK();
    }
    ppuVar2 = ppuVar2 + 7;
    while( true ) {
      if (&UNK_14000f9ff < ppuVar2) goto LAB_14001597d;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_14001597d;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 1400159b8 =====

uint wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
               (uint *param_1,longlong param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  longlong *plVar5;
  uint uVar6;
  bool bVar7;
  
  uVar6 = *param_1;
  if ((uVar6 >> 9 & 1) == 0) {
    uVar3 = uVar6;
  }
  else {
    uVar4 = uVar6 >> 6 & 1;
    if ((uVar4 != 0) && (plVar5 = *(longlong **)(param_2 + 0x20), plVar5 != (longlong *)0x0)) {
      do {
        while( true ) {
          puVar1 = (undefined8 *)*plVar5;
          if (puVar1 == (undefined8 *)0x0) goto LAB_140015a50;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_140015a50;
          }
          uVar4 = 1;
          plVar5 = plVar5 + 1;
        }
        uVar2 = wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
                          ((uint *)*puVar1,(longlong)puVar1);
        if ((uVar4 == 0) || ((uVar2 & 1) == 0)) {
          uVar4 = 0;
        }
        else {
          uVar4 = 1;
        }
        plVar5 = plVar5 + 1;
      } while (uVar4 != 0);
    }
LAB_140015a50:
    do {
      uVar2 = uVar6 & 0xffffffce;
      if ((uVar6 & 1) == uVar4) {
        uVar2 = uVar6 & 0xfffffffe;
      }
      uVar3 = uVar2 & 0xfffffdff | uVar4;
      LOCK();
      uVar2 = *param_1;
      bVar7 = uVar6 == uVar2;
      if (bVar7) {
        *param_1 = uVar3;
      }
      else {
        uVar6 = uVar2;
      }
      UNLOCK();
    } while (!bVar7);
  }
  return uVar3;
}



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140015aa0 =====

void wil_details_OnFeatureUsageProviderFlushNotification(int param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  iVar1 = g_wil_details_featureUsageCached;
  if (param_1 == 1) {
    LOCK();
    g_wil_details_featureUsageCached = 0;
    UNLOCK();
    if (iVar1 != 0) {
      for (ppuVar2 = &Feature_VpciInterruptTargetFix__private_descriptor;
          ppuVar2 < &wil_details_featureDescriptors_z; ppuVar2 = ppuVar2 + 1) {
        if (*ppuVar2 != (undefined *)0x0) {
          do {
            if (ppuVar2 == (undefined **)0x0) {
              return;
            }
            if ((*(uint *)ppuVar2[1] & 1) != 0) {
              wil_details_RecordCachedUsage(*(undefined4 *)(ppuVar2 + 3),(uint *)ppuVar2[1]);
            }
            ppuVar2 = ppuVar2 + 7;
            while( true ) {
              if (&UNK_14000f9ff < ppuVar2) {
                return;
              }
              if (*ppuVar2 != (undefined *)0x0) break;
              ppuVar2 = ppuVar2 + 1;
            }
          } while( true );
        }
      }
    }
  }
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140015b20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  int iVar1;
  uint uVar2;
  undefined **ppuVar3;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  for (ppuVar3 = &Feature_VpciInterruptTargetFix__private_descriptor;
      ppuVar3 < &wil_details_featureDescriptors_z; ppuVar3 = ppuVar3 + 1) {
    if (*ppuVar3 != (undefined *)0x0) goto LAB_140015c1d;
  }
LAB_140015c26:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_140015c1d:
  if (ppuVar3 == (undefined **)0x0) goto LAB_140015c26;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_140015bee:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_140015bee;
        uVar2 = local_20._4_4_ & 0x80;
      }
      uVar2 = uVar2 << 3 | 0x206;
    }
    LOCK();
    *(uint *)*ppuVar3 = *(uint *)*ppuVar3 ^ (*(uint *)*ppuVar3 ^ uVar2) & 0xf80;
    UNLOCK();
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_14000f9ff < ppuVar3) goto LAB_140015c26;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_140015c1d;
}



===== FdoCreateVmbusChannel @ 140015c4c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int FdoCreateVmbusChannel(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  int unaff_EBX;
  undefined2 uVar4;
  longlong local_res8;
  undefined8 local_38;
  undefined8 uStack_30;
  code *local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = (code *)0x0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  uVar2 = (**(code **)(WdfFunctions_01033 + 0xf8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x10))
  ;
  iVar1 = VmbChannelAllocate(uVar2,0,&local_res8);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140015db6;
    uVar4 = 0x22;
  }
  else {
    VmbChannelInitSetMaximumPacketSize(local_res8,0x9ae8);
    VmbClientChannelInitSetRingBufferPageCount(local_res8,0x10,0x10);
    uStack_30 = 0;
    uStack_10 = 0;
    uStack_20 = 0;
    local_18 = 0;
    local_28 = VpciChannelClosed;
    local_38 = 0x3000000001;
    VmbChannelInitSetStateChangeCallbacks(local_res8,&local_38);
    VmbChannelInitSetProcessPacketCallbacks(local_res8,VpciEvtChannelProcessPacket,0);
    puVar3 = (undefined8 *)ExAllocatePool2(0x40,8,0x69637056);
    if (puVar3 != (undefined8 *)0x0) {
      *puVar3 = *(undefined8 *)(param_1 + 0x10);
      VmbChannelSetPointer(local_res8);
      *(longlong *)(param_1 + 0x28) = local_res8;
      return unaff_EBX;
    }
    iVar1 = -0x3fffff66;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140015db6;
    uVar4 = 0x23;
  }
  WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar4,
                    &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,(char)iVar1);
LAB_140015db6:
  if (local_res8 != 0) {
    VmbChannelCleanup();
  }
  return unaff_EBX;
}



===== FdoDestroyVmbusChannel @ 140015e0c =====

void FdoDestroyVmbusChannel(longlong param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = *(undefined8 *)(param_1 + 0x28);
  uVar2 = VmbChannelGetPointer(uVar1);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,2,0x24,
                        &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,(char)param_1,(char)uVar1,
                        (char)uVar2);
  }
  VmbChannelDisable(uVar1);
  ExFreePoolWithTag(uVar2,0x69637056);
  VmbChannelCleanup(uVar1);
  *(undefined8 *)(param_1 + 0x28) = 0;
  return;
}



===== FdoDeviceAdd @ 140015ed0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int FdoDeviceAdd(undefined8 param_1,undefined8 param_2)

{
  int extraout_EAX;
  int iVar1;
  ulonglong uVar2;
  longlong *plVar3;
  ulonglong *puVar4;
  int iVar5;
  undefined2 uVar6;
  bool bVar7;
  undefined8 local_res10;
  ulonglong *local_res18 [2];
  ulonglong local_188;
  code *pcStack_180;
  code *local_178;
  undefined8 uStack_170;
  ulonglong *local_168;
  undefined8 uStack_160;
  undefined *local_158;
  undefined4 local_150;
  undefined4 local_14c;
  code *local_148;
  undefined8 local_140;
  code *local_138;
  undefined4 local_128;
  undefined4 local_124;
  code *local_118;
  code *local_100;
  code *local_f8;
  code *local_f0;
  undefined4 local_c8;
  undefined4 local_c4;
  code *local_c0;
  code *local_b0;
  code *local_a0;
  code *local_98;
  code *local_88;
  code *local_80;
  code *local_78;
  code *local_70;
  code *local_40;
  
  local_14c = 0;
  local_c4 = 0;
  local_188 = (ulonglong)(uint)local_188;
  local_168 = (ulonglong *)0x0;
  uStack_160 = 0;
  local_res18[0] = (ulonglong *)0x0;
  local_res10 = param_2;
  (**(code **)(WdfFunctions_01033 + 0x210))(WdfDriverGlobals,param_2,0x2a);
  (**(code **)(WdfFunctions_01033 + 0x1e8))(WdfDriverGlobals,local_res10,3);
  local_14c = 0;
  local_140 = 0;
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_150 = 0x20;
  }
  else if (WdfStructureCount < 0x1c) {
    local_150 = 0xffffffff;
  }
  else {
    local_150 = *(undefined4 *)(WdfStructures + 0xd8);
  }
  local_148 = VpciAddResourceRequirements;
  local_138 = VpciSetAcs;
  (**(code **)(WdfFunctions_01033 + 0x400))(WdfDriverGlobals,local_res10,&local_150);
  memset(&local_c8,0,0x90);
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_c8 = 0x90;
  }
  else if (WdfStructureCount < 0x2a) {
    local_c8 = 0xffffffff;
  }
  else {
    local_c8 = *(undefined4 *)(WdfStructures + 0x148);
  }
  local_a0 = VpciPrepareHardware;
  local_98 = VpciReleaseHardware;
  local_c0 = VpciD0Entry;
  local_b0 = VpciD0Exit;
  local_88 = VpciSelfManagedIoFlush;
  uVar2 = Feature_VpciVscBootDiskHibernation__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 != 0) {
    local_80 = VpciSelfManagedIoInit;
    local_70 = VpciSelfManagedIoRestart;
    local_78 = VpciSelfManagedIoSuspend;
    local_40 = VpciDeviceUsageNotificationEx;
  }
  (**(code **)(WdfFunctions_01033 + 0x1b8))(WdfDriverGlobals,local_res10,&local_c8);
  (**(code **)(WdfFunctions_01033 + 0x1f8))(WdfDriverGlobals);
  memset(&local_128,0,0x60);
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_128 = 0x60;
  }
  else if (WdfStructureCount < 3) {
    local_128 = 0xffffffff;
  }
  else {
    local_128 = *(undefined4 *)(WdfStructures + 0x10);
  }
  local_118 = PdoCreate;
  local_124 = 0xe0;
  local_100 = VpciDeviceListIdentificationDescriptionDuplicate;
  local_f0 = VpciDeviceListIdentificationDescriptionCompare;
  local_f8 = _guard_check_icall;
  (**(code **)(WdfFunctions_01033 + 0x410))(WdfDriverGlobals,local_res10,&local_128,0);
  local_168 = (ulonglong *)0x0;
  uStack_160 = 0;
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_188 = 0x38;
  }
  else if (WdfStructureCount < 0x27) {
    local_188 = 0xffffffff;
  }
  else {
    local_188 = (ulonglong)*(uint *)(WdfStructures + 0x130);
  }
  local_158 = PTR__WDF_VPCI_FDO_CONTEXT_TYPE_INFO_140010040;
  pcStack_180 = FdoDeviceCleanup;
  uStack_170 = 0x100000002;
  local_178 = FdoDeviceDestroy;
  iVar5 = (**(code **)(WdfFunctions_01033 + 600))
                    (WdfDriverGlobals,&local_res10,&local_188,local_res18);
  if (iVar5 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xc,
                        &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,(char)iVar5);
    }
    return iVar5;
  }
  plVar3 = (longlong *)
           (**(code **)(WdfFunctions_01033 + 0x650))
                     (WdfDriverGlobals,local_res18[0],PTR__WDF_VPCI_FDO_CONTEXT_TYPE_INFO_140010040)
  ;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xd,
                      &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,(char)plVar3);
  }
  plVar3[2] = (longlong)local_res18[0];
  *(undefined1 *)((longlong)plVar3 + 0x1c) = 1;
  pcStack_180 = (code *)0x0;
  local_158 = (undefined *)0x0;
  local_178 = (code *)0x0;
  uStack_160 = 0;
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_188 = 0x38;
  }
  else if (WdfStructureCount < 0x27) {
    local_188 = 0xffffffff;
  }
  else {
    local_188 = (ulonglong)*(uint *)(WdfStructures + 0x130);
  }
  puVar4 = &local_188;
  local_168 = local_res18[0];
  uStack_170 = 0x100000001;
  iVar5 = (**(code **)(WdfFunctions_01033 + 0x9c0))(WdfDriverGlobals,puVar4,plVar3 + 4);
  if (iVar5 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar5;
    }
    uVar6 = 0xe;
LAB_14001635e:
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar6,
                       &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,(char)plVar3,(char)iVar5);
    return iVar5;
  }
  iVar5 = FdoCreateVmbusChannel((longlong)plVar3);
  plVar3 = (longlong *)CONCAT44((int)((ulonglong)plVar3 >> 0x20),iVar5);
  if (extraout_EAX < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return extraout_EAX;
    }
    uVar6 = 0xf;
    iVar5 = extraout_EAX;
    goto LAB_14001635e;
  }
  uVar2 = Feature_VpciVscBootDiskHibernation__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar2 == 0) || (iVar1 = FdoRegisterVmbusCrashInterface((longlong)plVar3), -1 < iVar1)) {
    KeInitializeSpinLock(plVar3 + 0xe);
    KeInitializeGuardedMutex(plVar3 + 0xf);
    puVar4 = local_res18[0];
    iVar1 = (**(code **)(WdfFunctions_01033 + 0x268))
                      (WdfDriverGlobals,local_res18[0],&GUID_DEVINTERFACE_VPCI,0);
    if (-1 < iVar1) {
      (**(code **)(WdfFunctions_01033 + 0x188))(WdfDriverGlobals,local_res18[0],1,1);
      (**(code **)(WdfFunctions_01033 + 0x188))(WdfDriverGlobals,local_res18[0],2,1);
      (**(code **)(WdfFunctions_01033 + 0x188))(WdfDriverGlobals,local_res18[0],3,1);
      puVar4 = local_res18[0];
      (**(code **)(WdfFunctions_01033 + 0x188))(WdfDriverGlobals,local_res18[0],6,1);
      LOCK();
      iVar5 = VpciFdoCount + 1;
      UNLOCK();
      bVar7 = VpciFdoCount != 0;
      VpciFdoCount = iVar5;
      if ((bVar7) || (iVar1 = VpciCreateControlDevice(param_1), -1 < iVar1)) {
        VpciLinkUnlinkFdoContext(plVar3,'\x01');
        return 0;
      }
      LOCK();
      VpciFdoCount = VpciFdoCount + -1;
      UNLOCK();
      goto LAB_14001652f;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001652f;
    uVar6 = 0x11;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001652f;
    uVar6 = 0x10;
  }
  puVar4 = (ulonglong *)CONCAT71((int7)((ulonglong)puVar4 >> 8),2);
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar6,
                     &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,(char)iVar5,(char)iVar1);
LAB_14001652f:
  if (plVar3[5] != 0) {
    FdoDestroyVmbusChannel((longlong)plVar3,puVar4);
  }
  uVar2 = Feature_VpciVscBootDiskHibernation__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 == 0) {
    return iVar1;
  }
  if (plVar3[8] == 0) {
    return iVar1;
  }
  ExFreePoolWithTag(plVar3[8],0x69637056);
  plVar3[8] = 0;
  return iVar1;
}



===== FdoDeviceCleanup @ 1400165a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FdoDeviceCleanup(undefined8 param_1)

{
  int iVar1;
  longlong *plVar2;
  ulonglong uVar3;
  bool bVar4;
  
  plVar2 = (longlong *)
           (**(code **)(WdfFunctions_01033 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_VPCI_FDO_CONTEXT_TYPE_INFO_140010040);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    param_1 = CONCAT71((int7)((ulonglong)param_1 >> 8),4);
    WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,10,
                       &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,(char)plVar2,
                       (char)SystemReserved1[0xf]);
  }
  if (plVar2[5] != 0) {
    FdoDestroyVmbusChannel((longlong)plVar2,param_1);
  }
  uVar3 = Feature_VpciVscBootDiskHibernation__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar3 != 0) && (plVar2[8] != 0)) {
    ExFreePoolWithTag();
    plVar2[8] = 0;
  }
  VpciLinkUnlinkFdoContext(plVar2,'\0');
  LOCK();
  iVar1 = VpciFdoCount + -1;
  UNLOCK();
  bVar4 = VpciFdoCount == 1;
  VpciFdoCount = iVar1;
  if (bVar4) {
    VpciDestroyControlDevice();
  }
  return;
}



===== FdoEjectPdo @ 14001667c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FdoEjectPdo(longlong param_1,longlong param_2)

{
  void *pvVar1;
  undefined1 uVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined1 auStackY_1b8 [32];
  undefined1 uVar6;
  longlong local_178;
  ulonglong local_170;
  undefined4 *puStack_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined4 local_148;
  undefined4 local_144;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined4 local_118;
  undefined1 local_114 [220];
  ulonglong local_38;
  
  pvVar1 = SystemReserved1[0xf];
  local_38 = __security_cookie ^ (ulonglong)auStackY_1b8;
  local_170 = (ulonglong)(uint)local_170;
  uVar6 = (undefined1)param_1;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    lVar5 = param_2;
    uVar2 = (**(code **)(WdfFunctions_01033 + 0x650))
                      (WdfDriverGlobals,param_2,PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8);
    WPP_RECORDER_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar5,2,99,
                        &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar6,uVar2,(char)pvVar1);
  }
  uVar4 = (**(code **)(WdfFunctions_01033 + 0x420))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x10));
  local_140 = 0;
  uStack_138 = 0;
  local_130 = 0;
  uStack_128 = 0;
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_148 = 0x28;
  }
  else if (WdfStructureCount < 4) {
    local_148 = 0xffffffff;
  }
  else {
    local_148 = *(undefined4 *)(WdfStructures + 0x18);
  }
  local_144 = 7;
  (**(code **)(WdfFunctions_01033 + 0x30))(WdfDriverGlobals,uVar4,&local_148);
  while( true ) {
    local_178 = 0;
    memset(local_114,0,0xdc);
    local_118 = 0xe0;
    local_150 = 0;
    local_160 = 0;
    uStack_158 = 0;
    if (WdfClientVersionHigherThanFramework == '\0') {
      local_170 = 0x28;
    }
    else if (WdfStructureCount < 5) {
      local_170 = 0xffffffff;
    }
    else {
      local_170 = (ulonglong)*(uint *)(WdfStructures + 0x20);
    }
    puStack_168 = &local_118;
    iVar3 = (**(code **)(WdfFunctions_01033 + 0x38))(WdfDriverGlobals,uVar4,&local_148,&local_178);
    if (iVar3 < 0) break;
    if (local_178 == param_2) {
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x65,
                           &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar6,(char)param_2);
      }
      (**(code **)(WdfFunctions_01033 + 0x60))(WdfDriverGlobals,uVar4,&local_118);
LAB_1400168f4:
      (**(code **)(WdfFunctions_01033 + 0x40))(WdfDriverGlobals,uVar4,&local_148);
      return;
    }
  }
  if ((iVar3 != -0x7fffffe6) &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,100,
                       &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar6,(char)iVar3);
  }
  goto LAB_1400168f4;
}



===== FdoInvalidateBlockMessage @ 140016948 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FdoInvalidateBlockMessage(undefined8 param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  longlong lVar3;
  
  puVar1 = (undefined8 *)VmbChannelGetPointer();
  lVar2 = (**(code **)(WdfFunctions_01033 + 0x650))
                    (WdfDriverGlobals,*puVar1,PTR__WDF_VPCI_FDO_CONTEXT_TYPE_INFO_140010040);
  lVar3 = FdoReferenceChildBySlot(lVar2,*(int *)(param_2 + 4),0x434b4c42);
  if (lVar3 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0x49,
                        &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,(char)lVar2);
    }
  }
  else {
    lVar2 = (**(code **)(WdfFunctions_01033 + 0x650))
                      (WdfDriverGlobals,lVar3,PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8);
    LOCK();
    *(ulonglong *)(lVar2 + 0x160) = *(ulonglong *)(lVar2 + 0x160) | *(ulonglong *)(param_2 + 8);
    UNLOCK();
    FdoInvalidateBlockIndicate(lVar3,lVar2);
    (**(code **)(WdfFunctions_01033 + 0x670))
              (WdfDriverGlobals,lVar3,0x434b4c42,0x7fb,"onecore\\vm\\dv\\vpci\\vsc\\sys\\fdo.c");
  }
  return;
}



===== FdoReferenceChildBySlot @ 140016a70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong FdoReferenceChildBySlot(longlong param_1,int param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStackY_1b8 [32];
  undefined1 uVar3;
  longlong local_178;
  ulonglong local_170;
  undefined4 *puStack_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined4 local_148;
  undefined4 local_144;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined4 local_118;
  int local_114 [55];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_1b8;
  local_170 = (ulonglong)(uint)local_170;
  uVar2 = (**(code **)(WdfFunctions_01033 + 0x420))
                    (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x10));
  local_140 = 0;
  uStack_138 = 0;
  local_130 = 0;
  uStack_128 = 0;
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_148 = 0x28;
  }
  else if (WdfStructureCount < 4) {
    local_148 = 0xffffffff;
  }
  else {
    local_148 = *(undefined4 *)(WdfStructures + 0x18);
  }
  local_144 = 7;
  (**(code **)(WdfFunctions_01033 + 0x30))(WdfDriverGlobals,uVar2,&local_148);
  while( true ) {
    local_178 = 0;
    memset(local_114,0,0xdc);
    local_118 = 0xe0;
    local_150 = 0;
    local_160 = 0;
    uStack_158 = 0;
    if (WdfClientVersionHigherThanFramework == '\0') {
      local_170 = 0x28;
    }
    else if (WdfStructureCount < 5) {
      local_170 = 0xffffffff;
    }
    else {
      local_170 = (ulonglong)*(uint *)(WdfStructures + 0x20);
    }
    puStack_168 = &local_118;
    iVar1 = (**(code **)(WdfFunctions_01033 + 0x38))(WdfDriverGlobals,uVar2,&local_148,&local_178);
    uVar3 = (undefined1)param_1;
    if (iVar1 < 0) break;
    if (local_178 != 0) {
      if ((int)uStack_158 == 1) {
        if (local_114[0] == param_2) {
          if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
             (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
            WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x62,
                               &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar3,
                               (char)local_178);
          }
          (**(code **)(WdfFunctions_01033 + 0x668))(WdfDriverGlobals,local_178,param_3,0xc88);
          (**(code **)(WdfFunctions_01033 + 0x40))(WdfDriverGlobals,uVar2,&local_148);
          return local_178;
        }
      }
      else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x61,
                           &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar3,(char)uStack_158);
      }
    }
  }
  if ((iVar1 != -0x7fffffe6) &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x60,
                       &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar3,(char)iVar1);
  }
  (**(code **)(WdfFunctions_01033 + 0x40))(WdfDriverGlobals,uVar2,&local_148);
  return 0;
}



===== FdoRegisterVmbusCrashInterface @ 140016d7c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int FdoRegisterVmbusCrashInterface(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  if (*(longlong *)(param_1 + 0x40) == 0) {
    uVar2 = (**(code **)(WdfFunctions_01033 + 0x150))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x10));
    lVar3 = ExAllocatePool2(0x40,0x30,0x69637056);
    if (lVar3 == 0) {
      iVar1 = -0x3fffff66;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x6f,
                           &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,(char)param_1,
                           (char)SystemReserved1[0xf]);
      }
    }
    else {
      iVar1 = (**(code **)(WdfFunctions_01033 + 0x5d0))(WdfDriverGlobals,uVar2,0,0x3ec080);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x70,
                           &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids);
        }
        ExFreePoolWithTag(lVar3,0x69637056);
      }
      else {
        *(longlong *)(param_1 + 0x40) = lVar3;
      }
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x6e,
                         &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,(char)param_1,
                         (char)SystemReserved1[0xf]);
    }
    iVar1 = -0x3fffffff;
  }
  return iVar1;
}



===== FdoReportDeviceProxyPrefixChanged @ 140016ff8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FdoReportDeviceProxyPrefixChanged(longlong param_1)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  undefined *puVar8;
  longlong *plVar9;
  undefined1 auStackY_298 [32];
  undefined1 uVar10;
  char local_258 [8];
  longlong local_250;
  ulonglong local_248;
  undefined4 *puStack_240;
  undefined8 local_238;
  undefined8 uStack_230;
  ulonglong local_228;
  undefined8 local_220;
  undefined8 uStack_218;
  undefined8 local_210;
  undefined8 uStack_208;
  undefined8 local_200;
  undefined4 local_1f8;
  undefined4 local_1f4;
  undefined4 local_1f0;
  undefined8 local_1ec;
  undefined4 local_1e4;
  undefined1 local_1e0;
  undefined2 local_1de;
  undefined8 local_1dc;
  undefined8 uStack_1d4;
  undefined8 local_1cc;
  undefined8 uStack_1c4;
  undefined8 local_1bc;
  undefined8 uStack_1b4;
  undefined8 local_1ac;
  undefined8 uStack_1a4;
  undefined8 local_19c;
  undefined8 uStack_194;
  undefined8 local_18c;
  undefined8 uStack_184;
  undefined8 local_17c;
  undefined8 uStack_174;
  undefined8 local_16c;
  undefined8 uStack_164;
  undefined8 local_15c;
  undefined8 uStack_154;
  undefined8 local_14c;
  undefined8 uStack_144;
  undefined4 local_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 local_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  char local_11c;
  undefined4 local_118;
  undefined1 local_114 [220];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_298;
  local_228 = local_228 & 0xffffffff00000000;
  local_248 = 0;
  puStack_240 = (undefined4 *)0x0;
  local_238 = 0;
  uStack_230 = 0;
  memset(&local_118,0,0xe0);
  local_250 = 0;
  local_200 = 0;
  local_220 = 0;
  uStack_218 = 0;
  local_210 = 0;
  uStack_208 = 0;
  memset(&local_1f8,0,0xe0);
  uVar10 = (undefined1)param_1;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x69,
                      &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar10);
  }
  (**(code **)(WdfFunctions_01033 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20),0);
  if (*(char *)(param_1 + 0x1c) != '\0') {
    uVar5 = (**(code **)(WdfFunctions_01033 + 0x420))
                      (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x10));
    uStack_218 = 0;
    local_210 = 0;
    uStack_208 = 0;
    local_200 = 0;
    if (WdfClientVersionHigherThanFramework == '\0') {
      uVar1 = 0x28;
    }
    else if (WdfStructureCount < 4) {
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = *(undefined4 *)(WdfStructures + 0x18);
    }
    local_220 = CONCAT44(5,uVar1);
    (**(code **)(WdfFunctions_01033 + 0x30))(WdfDriverGlobals,uVar5,&local_220);
    while( true ) {
      local_250 = 0;
      memset(local_114,0,0xdc);
      local_118 = 0xe0;
      local_228 = 0;
      local_238 = 0;
      uStack_230 = 0;
      if (WdfClientVersionHigherThanFramework == '\0') {
        local_248 = 0x28;
      }
      else if (WdfStructureCount < 5) {
        local_248 = 0xffffffff;
      }
      else {
        local_248 = (ulonglong)*(uint *)(WdfStructures + 0x20);
      }
      puStack_240 = &local_118;
      plVar9 = &local_250;
      iVar3 = (**(code **)(WdfFunctions_01033 + 0x38))(WdfDriverGlobals,uVar5,&local_220);
      if (iVar3 < 0) break;
      if (local_250 != 0) {
        puVar8 = PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8;
        puVar6 = (undefined4 *)(**(code **)(WdfFunctions_01033 + 0x650))(WdfDriverGlobals);
        local_258[0] = '\0';
        uVar4 = VscCheckDeviceProxyPrefixChanged((longlong)puVar6,local_258,puVar8,(longlong)plVar9)
        ;
        if (((int)uVar4 < 0) &&
           ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x6b,
                             &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar10,(char)uVar4);
        }
        cVar2 = local_258[0];
        if (((local_258[0] != '\0') &&
            (iVar3 = (**(code **)(WdfFunctions_01033 + 0x50))(WdfDriverGlobals,uVar5,puStack_240),
            iVar3 < 0)) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x6c,
                             &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar10,(char)iVar3);
        }
        memset(&local_1f4,0,0xdc);
        local_1f8 = 0xe0;
        local_1f4 = *puVar6;
        local_1ec = *(undefined8 *)(puVar6 + 4);
        local_1e4 = puVar6[6];
        local_1f0 = puVar6[7];
        local_1de = *(undefined2 *)((longlong)puVar6 + 0x24a);
        local_1e0 = *(undefined1 *)((longlong)puVar6 + 0x249);
        local_1dc = *(undefined8 *)(puVar6 + 0x93);
        uStack_1d4 = *(undefined8 *)(puVar6 + 0x95);
        local_1cc = *(undefined8 *)(puVar6 + 0x97);
        uStack_1c4 = *(undefined8 *)(puVar6 + 0x99);
        local_1bc = *(undefined8 *)(puVar6 + 0x9b);
        uStack_1b4 = *(undefined8 *)(puVar6 + 0x9d);
        local_1ac = *(undefined8 *)(puVar6 + 0x9f);
        uStack_1a4 = *(undefined8 *)(puVar6 + 0xa1);
        local_19c = *(undefined8 *)(puVar6 + 0xa3);
        uStack_194 = *(undefined8 *)(puVar6 + 0xa5);
        local_18c = *(undefined8 *)(puVar6 + 0xa7);
        uStack_184 = *(undefined8 *)(puVar6 + 0xa9);
        local_17c = *(undefined8 *)(puVar6 + 0xab);
        uStack_174 = *(undefined8 *)(puVar6 + 0xad);
        local_16c = *(undefined8 *)(puVar6 + 0xaf);
        uStack_164 = *(undefined8 *)(puVar6 + 0xb1);
        local_15c = *(undefined8 *)(puVar6 + 0xb3);
        uStack_154 = *(undefined8 *)(puVar6 + 0xb5);
        local_14c = *(undefined8 *)(puVar6 + 0xb7);
        uStack_144 = *(undefined8 *)(puVar6 + 0xb9);
        local_13c = puVar6[0xbb];
        uStack_138 = puVar6[0xbc];
        uStack_134 = puVar6[0xbd];
        uStack_130 = puVar6[0xbe];
        local_12c = puVar6[0xbf];
        uStack_128 = puVar6[0xc0];
        uStack_124 = puVar6[0xc1];
        uStack_120 = puVar6[0xc2];
        local_11c = *(char *)(puVar6 + 0xc3);
        if (cVar2 != '\0') {
          local_11c = local_11c == '\0';
        }
        uVar7 = (**(code **)(WdfFunctions_01033 + 0x420))
                          (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x10));
        iVar3 = (**(code **)(WdfFunctions_01033 + 0x48))(WdfDriverGlobals,uVar7,&local_1f8,0);
        if ((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x6d,
                            &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,(char)iVar3);
        }
      }
    }
    if ((iVar3 != -0x7fffffe6) &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x6a,
                         &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar10,(char)iVar3);
    }
    (**(code **)(WdfFunctions_01033 + 0x40))(WdfDriverGlobals,uVar5,&local_220);
  }
  (**(code **)(WdfFunctions_01033 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20));
  return 0;
}



===== FdoReportDevices @ 140017518 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FdoReportDevices(undefined8 param_1,longlong param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 uVar3;
  int iVar4;
  undefined8 *puVar5;
  longlong lVar6;
  longlong lVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  int *piVar10;
  uint uVar11;
  byte bVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined *puVar15;
  undefined2 uVar16;
  bool bVar17;
  undefined1 unaff_retaddr;
  undefined1 auStackY_1e8 [32];
  undefined8 in_stack_fffffffffffffe38;
  undefined1 uVar18;
  longlong local_198;
  undefined8 local_190;
  uint local_188;
  ulonglong local_180;
  undefined4 *puStack_178;
  undefined8 local_170;
  undefined8 uStack_168;
  ulonglong local_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined4 local_128;
  uint local_124;
  undefined4 local_120;
  undefined8 local_11c;
  undefined4 local_114;
  undefined8 local_10c;
  undefined8 uStack_104;
  undefined8 local_fc;
  undefined8 uStack_f4;
  undefined8 local_ec;
  undefined8 uStack_e4;
  undefined8 local_dc;
  undefined8 uStack_d4;
  undefined8 local_cc;
  undefined8 uStack_c4;
  undefined8 local_bc;
  undefined8 uStack_b4;
  undefined8 local_ac;
  undefined8 uStack_a4;
  undefined8 local_9c;
  undefined8 uStack_94;
  undefined8 local_8c;
  undefined8 uStack_84;
  undefined8 local_7c;
  undefined8 uStack_74;
  undefined4 local_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 local_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined1 local_4c [4];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1e8;
  local_198 = 0;
  local_160 = local_160 & 0xffffffff00000000;
  local_138 = 0;
  uVar13 = 0;
  uVar14 = 0xe0;
  local_180 = 0;
  puStack_178 = (undefined4 *)0x0;
  local_170 = 0;
  uStack_168 = 0;
  local_158 = 0;
  uStack_150 = 0;
  local_148 = 0;
  uStack_140 = 0;
  memset(&local_128,0,0xe0);
  if (param_3 < 8) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar16 = 0x25;
LAB_1400175a7:
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar13,2,uVar16,
                      &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,(char)param_3);
  }
  else {
    uVar11 = *(uint *)(param_2 + 4);
    uVar13 = 0xffffffff;
    if ((ulonglong)uVar11 * 0x14 < 0x100000000) {
      uVar2 = (uint)((ulonglong)uVar11 * 0x14);
      uVar11 = uVar2 + 8;
      if (uVar11 < uVar2) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return;
        }
        uVar16 = 0x27;
        goto LAB_1400175a7;
      }
      if (uVar11 <= param_3) {
        puVar5 = (undefined8 *)VmbChannelGetPointer(param_1);
        lVar6 = (**(code **)(WdfFunctions_01033 + 0x650))
                          (WdfDriverGlobals,*puVar5,PTR__WDF_VPCI_FDO_CONTEXT_TYPE_INFO_140010040);
        uVar18 = (undefined1)lVar6;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qqqq
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x29,
                     &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar18,(char)puVar5,
                     unaff_retaddr,(char)SystemReserved1[0xf]);
        }
        (**(code **)(WdfFunctions_01033 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x20),0);
        if (*(char *)(lVar6 + 0x1c) != '\0') {
          uVar13 = (**(code **)(WdfFunctions_01033 + 0x420))
                             (WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x10));
          uStack_150 = 0;
          local_148 = 0;
          uStack_140 = 0;
          local_138 = 0;
          if (WdfClientVersionHigherThanFramework == '\0') {
            uVar1 = 0x28;
          }
          else if (WdfStructureCount < 4) {
            uVar1 = 0xffffffff;
          }
          else {
            uVar1 = *(undefined4 *)(WdfStructures + 0x18);
          }
          local_158 = CONCAT44(5,uVar1);
          local_190 = uVar13;
          (**(code **)(WdfFunctions_01033 + 0x30))(WdfDriverGlobals,uVar13,&local_158);
LAB_140017769:
          local_198 = 0;
          memset(&local_124,0,0xdc);
          local_128 = 0xe0;
          local_160 = 0;
          local_170 = 0;
          uStack_168 = 0;
          if (WdfClientVersionHigherThanFramework == '\0') {
            local_180 = 0x28;
          }
          else if (WdfStructureCount < 5) {
            local_180 = 0xffffffff;
          }
          else {
            local_180 = (ulonglong)*(uint *)(WdfStructures + 0x20);
          }
          puStack_178 = &local_128;
          iVar4 = (**(code **)(WdfFunctions_01033 + 0x38))
                            (WdfDriverGlobals,uVar13,&local_158,&local_198);
          if (-1 < iVar4) {
            if (local_198 == 0) {
LAB_1400178f1:
              lVar7 = local_198;
              if ((int)uStack_168 == 3) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar3 = 3;
                  uVar16 = 0x2e;
                  bVar12 = 2;
                  lVar7 = lVar6;
                  goto LAB_14001789f;
                }
              }
              else {
                local_188 = *(uint *)(param_2 + 4);
                uVar8 = 0;
                if (local_188 != 0) {
                  do {
                    uVar9 = VpciDeviceListIdentificationDescriptionCompare
                                      (local_190,(longlong)&local_128,(longlong)puStack_178);
                    if ((char)uVar9 != '\0') {
                      *(undefined4 *)(param_2 + 8 + uVar8 * 0x14) = 0xffffffff;
                      uVar13 = local_190;
                      goto LAB_140017769;
                    }
                    uVar11 = (int)uVar8 + 1;
                    uVar8 = (ulonglong)uVar11;
                  } while (uVar11 < local_188);
                }
                if (lVar7 != 0) {
                  piVar10 = (int *)(**(code **)(WdfFunctions_01033 + 0x650))
                                             (WdfDriverGlobals,lVar7,
                                              PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8);
                  LOCK();
                  bVar17 = piVar10[0x8a] == 0;
                  if (bVar17) {
                    piVar10[0x8a] = 1;
                  }
                  UNLOCK();
                  if (bVar17) {
                    PdoRunStateMachine(piVar10,4);
                  }
                  lVar7 = local_198;
                }
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  if (lVar7 == 0) {
                    uVar3 = 0;
                  }
                  else {
                    uVar3 = (**(code **)(WdfFunctions_01033 + 0x650))
                                      (WdfDriverGlobals,lVar7,
                                       PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8);
                  }
                  WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x2f,
                                     &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar18,uVar3);
                }
                uVar13 = local_190;
                iVar4 = (**(code **)(WdfFunctions_01033 + 0x50))
                                  (WdfDriverGlobals,local_190,puStack_178);
                if ((iVar4 < 0) &&
                   ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x30,
                                     &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar18,
                                     (char)iVar4);
                }
              }
            }
            else {
              puVar15 = PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8;
              lVar7 = (**(code **)(WdfFunctions_01033 + 0x650))(WdfDriverGlobals);
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar15,0x2b,
                                   &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,(char)lVar7,
                                   (char)*(undefined4 *)(lVar7 + 0x28));
              }
              if (*(int *)(lVar7 + 0xe0) == 4) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar16 = 0x2c;
                  uVar3 = 4;
                  goto LAB_140017898;
                }
              }
              else {
                uVar8 = Feature_VpciVscBootDiskHibernation__private_IsEnabledDeviceUsageNoInline();
                if (((int)uVar8 == 0) || (*(int *)(lVar7 + 0xe0) != 6)) goto LAB_1400178f1;
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar16 = 0x2d;
                  uVar3 = 6;
LAB_140017898:
                  bVar12 = 4;
LAB_14001789f:
                  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar12,2,uVar16,
                                     &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,(char)lVar7,
                                     uVar3);
                }
              }
            }
            goto LAB_140017769;
          }
          if ((iVar4 != -0x7fffffe6) &&
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x2a,
                               &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar18,(char)iVar4);
          }
          uVar8 = 0;
          if (*(int *)(param_2 + 4) != 0) {
            do {
              uVar13 = 0xd4;
              memset(&local_11c,0,0xd4);
              local_128 = 0xe0;
              local_124 = *(uint *)(param_2 + 0x14 + uVar8 * 0x14);
              local_11c = *(undefined8 *)(param_2 + 8 + uVar8 * 0x14);
              local_114 = *(undefined4 *)(param_2 + 0x10 + uVar8 * 0x14);
              local_120 = *(undefined4 *)(param_2 + 0x18 + uVar8 * 0x14);
              if (((short)local_11c != -1) || ((short)((ulonglong)local_11c >> 0x10) != -1)) {
                uVar9 = Feature_VpciVscBootDiskHibernation__private_IsEnabledDeviceUsageNoInline();
                if ((int)uVar9 == 0) {
                  uVar11 = PdoGetVMBusUniqueLocationString
                                     (lVar6,&local_124,uVar13,(wchar_t *)&local_10c,local_4c);
                  if (-1 < (int)uVar11) goto LAB_140017cb6;
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    uVar16 = 0x33;
LAB_140017df5:
                    WPP_RECORDER_SF_qDDd
                              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar16,
                               &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar18,
                               (byte)local_124 & 0x1f,(byte)(local_124 >> 5) & 7,(char)uVar11);
                  }
                }
                else if ((*(char *)(lVar6 + 0x68) == '\0') || (*(int *)(lVar6 + 0x50) == 0)) {
                  uVar11 = PdoGetVMBusUniqueLocationString
                                     (lVar6,&local_124,uVar13,(wchar_t *)&local_10c,local_4c);
                  if (-1 < (int)uVar11) goto LAB_140017cb6;
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    uVar16 = 0x32;
                    goto LAB_140017df5;
                  }
                }
                else {
                  local_198 = FdoReferenceChildBySlot(lVar6,local_124,0x48494252);
                  if (local_198 == 0) {
                    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                      WPP_RECORDER_SF_qDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x31,
                                          &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar18,
                                          (byte)local_124 & 0x1f,(byte)(local_124 >> 5) & 7);
                    }
                  }
                  else {
                    lVar7 = (**(code **)(WdfFunctions_01033 + 0x650))
                                      (WdfDriverGlobals,local_198,
                                       PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8);
                    local_10c = *(undefined8 *)(lVar7 + 0x24c);
                    uStack_104 = *(undefined8 *)(lVar7 + 0x254);
                    local_fc = *(undefined8 *)(lVar7 + 0x25c);
                    uStack_f4 = *(undefined8 *)(lVar7 + 0x264);
                    local_ec = *(undefined8 *)(lVar7 + 0x26c);
                    uStack_e4 = *(undefined8 *)(lVar7 + 0x274);
                    local_dc = *(undefined8 *)(lVar7 + 0x27c);
                    uStack_d4 = *(undefined8 *)(lVar7 + 0x284);
                    local_cc = *(undefined8 *)(lVar7 + 0x28c);
                    uStack_c4 = *(undefined8 *)(lVar7 + 0x294);
                    local_bc = *(undefined8 *)(lVar7 + 0x29c);
                    uStack_b4 = *(undefined8 *)(lVar7 + 0x2a4);
                    local_ac = *(undefined8 *)(lVar7 + 0x2ac);
                    uStack_a4 = *(undefined8 *)(lVar7 + 0x2b4);
                    local_9c = *(undefined8 *)(lVar7 + 700);
                    uStack_94 = *(undefined8 *)(lVar7 + 0x2c4);
                    local_8c = *(undefined8 *)(lVar7 + 0x2cc);
                    uStack_84 = *(undefined8 *)(lVar7 + 0x2d4);
                    local_7c = *(undefined8 *)(lVar7 + 0x2dc);
                    uStack_74 = *(undefined8 *)(lVar7 + 0x2e4);
                    local_6c = *(undefined4 *)(lVar7 + 0x2ec);
                    uStack_68 = *(undefined4 *)(lVar7 + 0x2f0);
                    uStack_64 = *(undefined4 *)(lVar7 + 0x2f4);
                    uStack_60 = *(undefined4 *)(lVar7 + 0x2f8);
                    local_5c = *(undefined4 *)(lVar7 + 0x2fc);
                    uStack_58 = *(undefined4 *)(lVar7 + 0x300);
                    uStack_54 = *(undefined4 *)(lVar7 + 0x304);
                    uStack_50 = *(undefined4 *)(lVar7 + 0x308);
                    local_4c[0] = *(undefined1 *)(lVar7 + 0x30c);
                    (**(code **)(WdfFunctions_01033 + 0x670))
                              (WdfDriverGlobals,local_198,0x48494252,0x5c5);
LAB_140017cb6:
                    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                      WPP_RECORDER_SF_qDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x34,
                                          &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar18,
                                          (byte)local_124 & 0x1f,(byte)(local_124 >> 5) & 7);
                    }
                    uVar13 = (**(code **)(WdfFunctions_01033 + 0x420))
                                       (WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x10));
                    iVar4 = (**(code **)(WdfFunctions_01033 + 0x48))
                                      (WdfDriverGlobals,uVar13,&local_128,0);
                    if ((iVar4 < 0) &&
                       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x35,
                                        &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,(char)iVar4
                                       );
                    }
                  }
                }
              }
              uVar11 = (int)uVar8 + 1;
              uVar8 = (ulonglong)uVar11;
            } while (uVar11 < *(uint *)(param_2 + 4));
            uVar13 = local_190;
          }
          (**(code **)(WdfFunctions_01033 + 0x40))(WdfDriverGlobals,uVar13,&local_158);
        }
        (**(code **)(WdfFunctions_01033 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x20));
        return;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return;
      }
      uVar16 = 0x28;
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return;
      }
      uVar16 = 0x26;
    }
    WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0xffffffff,uVar14,uVar16,
                       in_stack_fffffffffffffe38,(char)param_3,(char)uVar11);
  }
  return;
}



===== FdoReportDevices2 @ 140017eb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FdoReportDevices2(undefined8 param_1,longlong param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  undefined8 *puVar6;
  longlong lVar7;
  ulonglong uVar8;
  int *piVar9;
  ulonglong uVar10;
  longlong lVar11;
  byte bVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined *puVar15;
  undefined2 uVar16;
  bool bVar17;
  undefined1 unaff_retaddr;
  undefined1 auStackY_1e8 [32];
  undefined8 in_stack_fffffffffffffe38;
  undefined1 uVar18;
  longlong local_198;
  undefined8 local_190;
  uint local_188;
  ulonglong local_180;
  undefined4 *puStack_178;
  undefined8 local_170;
  undefined8 uStack_168;
  ulonglong local_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined4 local_128;
  uint local_124;
  undefined4 local_120;
  undefined8 local_11c;
  undefined4 local_114;
  byte local_110;
  undefined2 local_10e;
  undefined8 local_10c;
  undefined8 uStack_104;
  undefined8 local_fc;
  undefined8 uStack_f4;
  undefined8 local_ec;
  undefined8 uStack_e4;
  undefined8 local_dc;
  undefined8 uStack_d4;
  undefined8 local_cc;
  undefined8 uStack_c4;
  undefined8 local_bc;
  undefined8 uStack_b4;
  undefined8 local_ac;
  undefined8 uStack_a4;
  undefined8 local_9c;
  undefined8 uStack_94;
  undefined8 local_8c;
  undefined8 uStack_84;
  undefined8 local_7c;
  undefined8 uStack_74;
  undefined4 local_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 local_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined1 local_4c [4];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1e8;
  local_198 = 0;
  local_160 = local_160 & 0xffffffff00000000;
  local_138 = 0;
  uVar13 = 0;
  uVar14 = 0xe0;
  local_180 = 0;
  puStack_178 = (undefined4 *)0x0;
  local_170 = 0;
  uStack_168 = 0;
  local_158 = 0;
  uStack_150 = 0;
  local_148 = 0;
  uStack_140 = 0;
  memset(&local_128,0,0xe0);
  if (param_3 < 8) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar16 = 0x36;
LAB_140017f3f:
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar13,2,uVar16,
                      &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,(char)param_3);
  }
  else {
    uVar4 = *(uint *)(param_2 + 4);
    uVar13 = 0xffffffff;
    if ((ulonglong)uVar4 * 0x1c < 0x100000000) {
      uVar2 = (uint)((ulonglong)uVar4 * 0x1c);
      uVar4 = uVar2 + 8;
      if (uVar4 < uVar2) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return;
        }
        uVar16 = 0x38;
        goto LAB_140017f3f;
      }
      if (uVar4 <= param_3) {
        puVar6 = (undefined8 *)VmbChannelGetPointer(param_1);
        lVar7 = (**(code **)(WdfFunctions_01033 + 0x650))
                          (WdfDriverGlobals,*puVar6,PTR__WDF_VPCI_FDO_CONTEXT_TYPE_INFO_140010040);
        uVar18 = (undefined1)lVar7;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qqqq
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x3a,
                     &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar18,(char)puVar6,
                     unaff_retaddr,(char)SystemReserved1[0xf]);
        }
        (**(code **)(WdfFunctions_01033 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x20),0);
        if (*(char *)(lVar7 + 0x1c) != '\0') {
          uVar13 = (**(code **)(WdfFunctions_01033 + 0x420))
                             (WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x10));
          uStack_150 = 0;
          local_148 = 0;
          uStack_140 = 0;
          local_138 = 0;
          if (WdfClientVersionHigherThanFramework == '\0') {
            uVar1 = 0x28;
          }
          else if (WdfStructureCount < 4) {
            uVar1 = 0xffffffff;
          }
          else {
            uVar1 = *(undefined4 *)(WdfStructures + 0x18);
          }
          local_158 = CONCAT44(5,uVar1);
          local_190 = uVar13;
          (**(code **)(WdfFunctions_01033 + 0x30))(WdfDriverGlobals,uVar13,&local_158);
LAB_1400180fd:
          local_198 = 0;
          memset(&local_124,0,0xdc);
          local_128 = 0xe0;
          local_160 = 0;
          local_170 = 0;
          uStack_168 = 0;
          if (WdfClientVersionHigherThanFramework == '\0') {
            local_180 = 0x28;
          }
          else if (WdfStructureCount < 5) {
            local_180 = 0xffffffff;
          }
          else {
            local_180 = (ulonglong)*(uint *)(WdfStructures + 0x20);
          }
          puStack_178 = &local_128;
          iVar5 = (**(code **)(WdfFunctions_01033 + 0x38))
                            (WdfDriverGlobals,uVar13,&local_158,&local_198);
          if (-1 < iVar5) {
            if (local_198 == 0) {
LAB_140018285:
              lVar11 = local_198;
              if ((int)uStack_168 == 3) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar3 = 3;
                  uVar16 = 0x3f;
                  bVar12 = 2;
                  lVar11 = lVar7;
                  goto LAB_140018233;
                }
              }
              else {
                local_188 = *(uint *)(param_2 + 4);
                uVar4 = 0;
                if (local_188 != 0) {
                  do {
                    uVar8 = VpciDeviceListIdentificationDescriptionCompare
                                      (local_190,(longlong)&local_128,(longlong)puStack_178);
                    if ((char)uVar8 != '\0') {
                      *(undefined4 *)((ulonglong)uVar4 * 0x1c + 8 + param_2) = 0xffffffff;
                      uVar13 = local_190;
                      goto LAB_1400180fd;
                    }
                    uVar4 = uVar4 + 1;
                  } while (uVar4 < local_188);
                }
                if (lVar11 != 0) {
                  piVar9 = (int *)(**(code **)(WdfFunctions_01033 + 0x650))
                                            (WdfDriverGlobals,lVar11,
                                             PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8);
                  LOCK();
                  bVar17 = piVar9[0x8a] == 0;
                  if (bVar17) {
                    piVar9[0x8a] = 1;
                  }
                  UNLOCK();
                  if (bVar17) {
                    PdoRunStateMachine(piVar9,4);
                  }
                  lVar11 = local_198;
                }
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  if (lVar11 == 0) {
                    uVar3 = 0;
                  }
                  else {
                    uVar3 = (**(code **)(WdfFunctions_01033 + 0x650))
                                      (WdfDriverGlobals,lVar11,
                                       PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8);
                  }
                  WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x40,
                                     &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar18,uVar3);
                }
                uVar13 = local_190;
                iVar5 = (**(code **)(WdfFunctions_01033 + 0x50))
                                  (WdfDriverGlobals,local_190,puStack_178);
                if ((iVar5 < 0) &&
                   ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x41,
                                     &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar18,
                                     (char)iVar5);
                }
              }
            }
            else {
              puVar15 = PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8;
              lVar11 = (**(code **)(WdfFunctions_01033 + 0x650))(WdfDriverGlobals);
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar15,0x3c,
                                   &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,(char)lVar11,
                                   (char)*(undefined4 *)(lVar11 + 0x28));
              }
              if (*(int *)(lVar11 + 0xe0) == 4) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar16 = 0x3d;
                  uVar3 = 4;
                  goto LAB_14001822c;
                }
              }
              else {
                uVar8 = Feature_VpciVscBootDiskHibernation__private_IsEnabledDeviceUsageNoInline();
                if (((int)uVar8 == 0) || (*(int *)(lVar11 + 0xe0) != 6)) goto LAB_140018285;
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar16 = 0x3e;
                  uVar3 = 6;
LAB_14001822c:
                  bVar12 = 4;
LAB_140018233:
                  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar12,2,uVar16,
                                     &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,(char)lVar11,
                                     uVar3);
                }
              }
            }
            goto LAB_1400180fd;
          }
          if ((iVar5 != -0x7fffffe6) &&
             ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
            WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x3b,
                               &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar18,(char)iVar5);
          }
          uVar8 = 0;
          if (*(int *)(param_2 + 4) != 0) {
            do {
              uVar13 = 0xe0;
              memset(&local_128,0,0xe0);
              lVar11 = uVar8 * 0x1c;
              local_128 = 0xe0;
              local_124 = *(uint *)(lVar11 + 0x14 + param_2);
              local_11c = *(undefined8 *)(lVar11 + 8 + param_2);
              local_114 = *(undefined4 *)(lVar11 + 0x10 + param_2);
              local_120 = *(undefined4 *)(lVar11 + 0x18 + param_2);
              local_10e = *(undefined2 *)(lVar11 + 0x20 + param_2);
              local_110 = *(byte *)(lVar11 + 0x1c + param_2) & 1;
              if (((short)local_11c != -1) || ((short)((ulonglong)local_11c >> 0x10) != -1)) {
                uVar10 = Feature_VpciVscBootDiskHibernation__private_IsEnabledDeviceUsageNoInline();
                if ((int)uVar10 == 0) {
                  uVar4 = PdoGetVMBusUniqueLocationString
                                    (lVar7,&local_124,uVar13,(wchar_t *)&local_10c,local_4c);
                  if (-1 < (int)uVar4) goto LAB_140018664;
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    uVar16 = 0x44;
LAB_1400187a2:
                    WPP_RECORDER_SF_qDDd
                              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar16,
                               &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar18,
                               (byte)local_124 & 0x1f,(byte)(local_124 >> 5) & 7,(char)uVar4);
                  }
                }
                else if ((*(char *)(lVar7 + 0x68) == '\0') || (*(int *)(lVar7 + 0x50) == 0)) {
                  uVar4 = PdoGetVMBusUniqueLocationString
                                    (lVar7,&local_124,uVar13,(wchar_t *)&local_10c,local_4c);
                  if (-1 < (int)uVar4) goto LAB_140018664;
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    uVar16 = 0x43;
                    goto LAB_1400187a2;
                  }
                }
                else {
                  local_198 = FdoReferenceChildBySlot(lVar7,local_124,0x48494252);
                  if (local_198 == 0) {
                    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                      WPP_RECORDER_SF_qDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x42,
                                          &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar18,
                                          (byte)local_124 & 0x1f,(byte)(local_124 >> 5) & 7);
                    }
                  }
                  else {
                    lVar11 = (**(code **)(WdfFunctions_01033 + 0x650))
                                       (WdfDriverGlobals,local_198,
                                        PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8);
                    local_10c = *(undefined8 *)(lVar11 + 0x24c);
                    uStack_104 = *(undefined8 *)(lVar11 + 0x254);
                    local_fc = *(undefined8 *)(lVar11 + 0x25c);
                    uStack_f4 = *(undefined8 *)(lVar11 + 0x264);
                    local_ec = *(undefined8 *)(lVar11 + 0x26c);
                    uStack_e4 = *(undefined8 *)(lVar11 + 0x274);
                    local_dc = *(undefined8 *)(lVar11 + 0x27c);
                    uStack_d4 = *(undefined8 *)(lVar11 + 0x284);
                    local_cc = *(undefined8 *)(lVar11 + 0x28c);
                    uStack_c4 = *(undefined8 *)(lVar11 + 0x294);
                    local_bc = *(undefined8 *)(lVar11 + 0x29c);
                    uStack_b4 = *(undefined8 *)(lVar11 + 0x2a4);
                    local_ac = *(undefined8 *)(lVar11 + 0x2ac);
                    uStack_a4 = *(undefined8 *)(lVar11 + 0x2b4);
                    local_9c = *(undefined8 *)(lVar11 + 700);
                    uStack_94 = *(undefined8 *)(lVar11 + 0x2c4);
                    local_8c = *(undefined8 *)(lVar11 + 0x2cc);
                    uStack_84 = *(undefined8 *)(lVar11 + 0x2d4);
                    local_7c = *(undefined8 *)(lVar11 + 0x2dc);
                    uStack_74 = *(undefined8 *)(lVar11 + 0x2e4);
                    local_6c = *(undefined4 *)(lVar11 + 0x2ec);
                    uStack_68 = *(undefined4 *)(lVar11 + 0x2f0);
                    uStack_64 = *(undefined4 *)(lVar11 + 0x2f4);
                    uStack_60 = *(undefined4 *)(lVar11 + 0x2f8);
                    local_5c = *(undefined4 *)(lVar11 + 0x2fc);
                    uStack_58 = *(undefined4 *)(lVar11 + 0x300);
                    uStack_54 = *(undefined4 *)(lVar11 + 0x304);
                    uStack_50 = *(undefined4 *)(lVar11 + 0x308);
                    local_4c[0] = *(undefined1 *)(lVar11 + 0x30c);
                    (**(code **)(WdfFunctions_01033 + 0x670))
                              (WdfDriverGlobals,local_198,0x48494252,0x72f);
LAB_140018664:
                    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                      WPP_RECORDER_SF_qDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x45,
                                          &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar18,
                                          (byte)local_124 & 0x1f,(byte)(local_124 >> 5) & 7);
                    }
                    uVar13 = (**(code **)(WdfFunctions_01033 + 0x420))
                                       (WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x10));
                    iVar5 = (**(code **)(WdfFunctions_01033 + 0x48))
                                      (WdfDriverGlobals,uVar13,&local_128,0);
                    if ((iVar5 < 0) &&
                       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x46,
                                        &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,(char)iVar5
                                       );
                    }
                  }
                }
              }
              uVar4 = (int)uVar8 + 1;
              uVar8 = (ulonglong)uVar4;
            } while (uVar4 < *(uint *)(param_2 + 4));
            uVar13 = local_190;
          }
          (**(code **)(WdfFunctions_01033 + 0x40))(WdfDriverGlobals,uVar13,&local_158);
        }
        (**(code **)(WdfFunctions_01033 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x20));
        return;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return;
      }
      uVar16 = 0x39;
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return;
      }
      uVar16 = 0x37;
    }
    WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),0xffffffff,uVar14,uVar16,
                       in_stack_fffffffffffffe38,(char)param_3,(char)uVar4);
  }
  return;
}



===== FdoSimplePdoMessage @ 14001885c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FdoSimplePdoMessage(undefined8 param_1,undefined8 param_2,longlong param_3,uint param_4)

{
  undefined8 *puVar1;
  longlong lVar2;
  int *piVar3;
  
  if (param_4 < 8) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,2,0x47,
                        &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,(char)param_4);
    }
  }
  else {
    puVar1 = (undefined8 *)VmbChannelGetPointer();
    lVar2 = (**(code **)(WdfFunctions_01033 + 0x650))
                      (WdfDriverGlobals,*puVar1,PTR__WDF_VPCI_FDO_CONTEXT_TYPE_INFO_140010040);
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_qLD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    lVar2 = FdoReferenceChildBySlot(lVar2,*(int *)(param_3 + 4),0x4653504d);
    if (lVar2 != 0) {
      piVar3 = (int *)(**(code **)(WdfFunctions_01033 + 0x650))
                                (WdfDriverGlobals,lVar2,
                                 PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8);
      PdoRunStateMachine(piVar3,(int)param_2);
      (**(code **)(WdfFunctions_01033 + 0x670))
                (WdfDriverGlobals,lVar2,0x4653504d,0x7b4,"onecore\\vm\\dv\\vpci\\vsc\\sys\\fdo.c");
    }
  }
  return;
}



===== VpciD0Exit @ 1400189d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int VpciD0Exit(undefined8 param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined2 uVar6;
  uint local_res18 [2];
  undefined4 local_res20 [2];
  undefined1 uVar7;
  int local_28 [4];
  
  iVar2 = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  lVar3 = (**(code **)(WdfFunctions_01033 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_VPCI_FDO_CONTEXT_TYPE_INFO_140010040);
  uVar4 = Feature_VpciVscBootDiskHibernation__private_IsEnabledDeviceUsageNoInline();
  uVar7 = (undefined1)lVar3;
  if ((((int)uVar4 == 0) || (*(int *)(lVar3 + 0x50) == 0)) || (param_2 != 6)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x58,
                        &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar7);
    }
    local_res20[0] = 0x42490008;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x59,
                        &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar7);
    }
    local_res18[0] = 8;
    iVar2 = VmbChannelSendSynchronousRequest
                      (*(undefined8 *)(lVar3 + 0x28),local_res20,4,0,1,local_28,local_res18,0);
    iVar2 = GetCompletionStatus(iVar2,local_28,(ulonglong)local_res18[0]);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x5a,
                         &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar7,(char)iVar2);
    }
    param_1 = 0;
    RtlSetVolatileMemory((void *)(lVar3 + 0x30),0,0x10);
    uVar5 = *(undefined8 *)(lVar3 + 0x28);
    uVar1 = VmbChannelGetPointer(uVar5);
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140018bfb;
    uVar6 = 0x5b;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      param_1 = CONCAT71((int7)((ulonglong)param_1 >> 8),4);
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x56,
                        &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar7);
    }
    uVar5 = *(undefined8 *)(lVar3 + 0x28);
    *(undefined1 *)(lVar3 + 0x68) = 1;
    uVar1 = VmbChannelGetPointer(uVar5);
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140018bfb;
    uVar6 = 0x57;
  }
  WPP_RECORDER_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,6,uVar6,
                      &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar7,(char)uVar5,uVar1);
LAB_140018bfb:
  VmbChannelDisable(uVar5);
  return iVar2;
}



===== VpciDeviceUsageNotificationEx @ 140018c30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong VpciDeviceUsageNotificationEx(undefined8 param_1,uint param_2,char param_3)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined *puVar5;
  undefined8 uVar6;
  undefined2 uVar7;
  int *piVar8;
  int local_res20 [2];
  undefined8 in_stack_ffffffffffffffb8;
  undefined1 uVar9;
  undefined1 uVar10;
  
  local_res20[0] = 0;
  puVar5 = PTR__WDF_VPCI_FDO_CONTEXT_TYPE_INFO_140010040;
  lVar2 = (**(code **)(WdfFunctions_01033 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_VPCI_FDO_CONTEXT_TYPE_INFO_140010040);
  uVar6 = CONCAT71((int7)((ulonglong)puVar5 >> 8),param_3);
  uVar4 = (ulonglong)param_2;
  piVar8 = (int *)(lVar2 + 0x48);
  uVar3 = VpciUpdateDeviceUsageNotificationCount((longlong)piVar8,param_2,param_3,local_res20);
  uVar9 = (undefined1)lVar2;
  uVar10 = (undefined1)param_2;
  if ((int)uVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,1,0x71,
                          &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar9,uVar10,(char)uVar3)
      ;
    }
    return uVar3 & 0xffffffff;
  }
  if (param_3 == '\x01') {
    if ((local_res20[0] != 1) ||
       ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)) goto LAB_140018d51;
    uVar7 = 0x72;
  }
  else {
    if (((param_3 != '\0') || (local_res20[0] != 0)) ||
       ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)) goto LAB_140018d51;
    uVar7 = 0x73;
  }
  WPP_RECORDER_SF_qdq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,uVar6,uVar7,
                      in_stack_ffffffffffffffb8,uVar9,uVar10,(char)SystemReserved1[0xf]);
LAB_140018d51:
  uVar3 = Feature_VpciVscBootDiskHibernation__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar3 == 0) && (((param_2 == 1 || (param_2 == 2)) || (param_2 == 3)))) {
    lVar2 = (**(code **)(WdfFunctions_01033 + 0xf8))(WdfDriverGlobals,param_1);
    if (param_3 == '\x01') {
      if ((local_res20[0] == 1) && ((*(uint *)(lVar2 + 0x30) & 0x2000) != 0)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x74,
                             &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar9,uVar10);
        }
        *(uint *)(lVar2 + 0x30) = *(uint *)(lVar2 + 0x30) & 0xffffdfff;
      }
    }
    else if ((param_3 == '\0') && (local_res20[0] == 0)) {
      uVar1 = 0;
      do {
        if (*piVar8 != 0) {
          return 0;
        }
        uVar1 = uVar1 + 1;
        piVar8 = piVar8 + 1;
      } while (uVar1 < 4);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x75,
                          &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,uVar9);
      }
      *(uint *)(lVar2 + 0x30) = *(uint *)(lVar2 + 0x30) | 0x2000;
    }
  }
  return 0;
}



===== VpciPrepareHardware @ 140018e80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 VpciPrepareHardware(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  longlong lVar2;
  undefined8 uVar3;
  char *pcVar4;
  longlong lVar5;
  uint uVar6;
  
  lVar2 = (**(code **)(WdfFunctions_01033 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_VPCI_FDO_CONTEXT_TYPE_INFO_140010040);
  uVar1 = (**(code **)(WdfFunctions_01033 + 0x980))(WdfDriverGlobals,param_3);
  if (*(longlong *)(lVar2 + 0x28) == 0) {
    uVar3 = 0xc0000184;
  }
  else {
    uVar6 = 0;
    if (uVar1 != 0) {
      do {
        pcVar4 = (char *)(**(code **)(WdfFunctions_01033 + 0x988))(WdfDriverGlobals,param_3,uVar6);
        if ((*pcVar4 == '\x03') && (*(int *)(pcVar4 + 0xc) == 0x2000)) {
          uVar3 = *(undefined8 *)(pcVar4 + 4);
          *(undefined8 *)(lVar2 + 0xb8) = uVar3;
          lVar5 = MmMapIoSpaceEx(uVar3,0x2000,0x204);
          *(longlong *)(lVar2 + 0xb0) = lVar5;
          if (lVar5 == 0) {
            return 0xc000009a;
          }
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar1);
    }
    uVar3 = 0;
  }
  return uVar3;
}



===== VpciSelfManagedIoFlush @ 140018f80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void VpciSelfManagedIoFlush(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  int *piVar4;
  undefined1 auStackY_188 [32];
  undefined8 local_158;
  ulonglong local_150;
  undefined4 *puStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined4 local_128;
  undefined4 local_124;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined4 local_f8;
  undefined1 local_f4 [220];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_188;
  local_150 = (ulonglong)(uint)local_150;
  lVar2 = (**(code **)(WdfFunctions_01033 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_VPCI_FDO_CONTEXT_TYPE_INFO_140010040);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x5c,
                      &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,(char)lVar2);
  }
  (**(code **)(WdfFunctions_01033 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x20),0);
  *(undefined1 *)(lVar2 + 0x1c) = 0;
  uVar3 = (**(code **)(WdfFunctions_01033 + 0x420))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x10));
  local_120 = 0;
  uStack_118 = 0;
  local_110 = 0;
  uStack_108 = 0;
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_128 = 0x28;
  }
  else if (WdfStructureCount < 4) {
    local_128 = 0xffffffff;
  }
  else {
    local_128 = *(undefined4 *)(WdfStructures + 0x18);
  }
  local_124 = 1;
  (**(code **)(WdfFunctions_01033 + 0x30))(WdfDriverGlobals,uVar3,&local_128);
  while( true ) {
    local_158 = 0;
    memset(local_f4,0,0xdc);
    local_f8 = 0xe0;
    local_130 = 0;
    local_140 = 0;
    uStack_138 = 0;
    if (WdfClientVersionHigherThanFramework == '\0') {
      local_150 = 0x28;
    }
    else if (WdfStructureCount < 5) {
      local_150 = 0xffffffff;
    }
    else {
      local_150 = (ulonglong)*(uint *)(WdfStructures + 0x20);
    }
    puStack_148 = &local_f8;
    iVar1 = (**(code **)(WdfFunctions_01033 + 0x38))(WdfDriverGlobals,uVar3,&local_128,&local_158);
    if (iVar1 < 0) break;
    if ((int)uStack_138 == 1) {
      piVar4 = (int *)(**(code **)(WdfFunctions_01033 + 0x650))
                                (WdfDriverGlobals,local_158,
                                 PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8);
      if (piVar4[10] != 0x3e) {
        PdoRunStateMachine(piVar4,4);
      }
    }
  }
  (**(code **)(WdfFunctions_01033 + 0x40))(WdfDriverGlobals,uVar3,&local_128);
  (**(code **)(WdfFunctions_01033 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(lVar2 + 0x20));
  return;
}



===== VpciUpdateDeviceUsageNotificationCount @ 140019210 =====

undefined8
VpciUpdateDeviceUsageNotificationCount(longlong param_1,uint param_2,char param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  undefined2 uVar4;
  ulonglong uVar5;
  
  if (param_2 - 1 < 7) {
    uVar5 = (ulonglong)param_2;
    if (param_3 == '\0') {
      if (*(int *)(param_1 + uVar5 * 4) == 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar4 = 0x77;
          goto LAB_14001927a;
        }
        goto LAB_1400192a2;
      }
      LOCK();
      piVar1 = (int *)(param_1 + uVar5 * 4);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      iVar2 = iVar2 + -1;
    }
    else {
      LOCK();
      piVar1 = (int *)(param_1 + uVar5 * 4);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      iVar2 = iVar2 + 1;
    }
    *param_4 = iVar2;
    uVar3 = 0;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar4 = 0x76;
LAB_14001927a:
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar4,
                        &WPP_e47b2c05c6183114812e6faf30839a58_Traceguids,(char)param_2);
    }
LAB_1400192a2:
    uVar3 = 0xc000000d;
  }
  return uVar3;
}



===== GetInterruptConnectionData @ 1400192b4 =====

ulonglong GetInterruptConnectionData(undefined8 param_1,undefined8 *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  int *piVar3;
  uint local_res10 [2];
  undefined4 local_res18 [2];
  ulonglong in_stack_ffffffffffffffd8;
  ulonglong uVar4;
  undefined4 uVar5;
  
  *param_2 = 0;
  local_res10[0] = 0;
  local_res18[0] = 0;
  uVar4 = in_stack_ffffffffffffffd8 & 0xffffffff00000000;
  uVar2 = IoGetDevicePropertyData
                    (param_1,&INTERRUPT_CONNECTION_DATA_PKEY,0,0,uVar4,0,local_res10,local_res18);
  uVar5 = (undefined4)(uVar4 >> 0x20);
  if ((int)uVar2 == -0x3fffffdd) {
    if (local_res10[0] < 0x60) {
      uVar2 = 0xc000000d;
    }
    else {
      piVar3 = (int *)ExAllocatePool2(0x40,local_res10[0],0x69637056);
      if (piVar3 == (int *)0x0) {
        uVar2 = 0xc000009a;
      }
      else {
        uVar1 = IoGetDevicePropertyData
                          (param_1,&INTERRUPT_CONNECTION_DATA_PKEY,0,0,
                           CONCAT44(uVar5,local_res10[0]),piVar3,local_res10,local_res18);
        uVar2 = (ulonglong)uVar1;
        if ((int)uVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0xbe,
                              &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)uVar1);
          }
        }
        else {
          if (*piVar3 * 0x58 + 8U <= local_res10[0]) {
            *param_2 = piVar3;
            return 0;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0xbf,
                              &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)uVar1);
          }
          uVar2 = 0xc000003e;
        }
        ExFreePoolWithTag(piVar3,0);
      }
    }
  }
  return uVar2;
}



===== GetMessagePolicy @ 140019460 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int GetMessagePolicy(undefined8 param_1,uint param_2,ulonglong param_3)

{
  byte bVar1;
  short sVar2;
  bool bVar3;
  uint6 uVar4;
  uint6 uVar5;
  char cVar6;
  ushort uVar7;
  int iVar8;
  uint uVar9;
  wchar_t *pwVar10;
  longlong lVar11;
  longlong lVar12;
  ushort uVar13;
  uint uVar14;
  ushort uVar15;
  undefined8 uVar16;
  int local_res8;
  undefined1 auStackY_108 [32];
  undefined8 uVar17;
  ushort local_c8 [4];
  undefined8 local_c0;
  undefined4 local_b8 [2];
  undefined8 local_b0;
  wchar_t *pwStack_a8;
  undefined4 local_a0;
  uint local_9c;
  uint local_98;
  undefined8 local_90;
  longlong local_88;
  undefined4 local_80 [2];
  undefined8 local_78;
  undefined8 local_70;
  wchar_t *pwStack_68;
  longlong local_60;
  undefined8 uStack_58;
  wchar_t local_50 [8];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_108;
  uVar14 = 0;
  local_88 = 0;
  local_90 = 0;
  local_70 = 0;
  pwStack_68 = (wchar_t *)0x0;
  local_78 = 0;
  bVar3 = false;
  local_80[0] = 0;
  local_b8[0] = 0;
  local_a0 = 0;
  local_98 = 0;
  local_9c = 0;
  local_c0 = param_3;
  lVar12 = (**(code **)(WdfFunctions_01033 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8);
  bVar1 = *(byte *)(lVar12 + 0x130);
  if ((bVar1 != 5) && (bVar1 != 0)) {
    *(ushort *)(param_3 + 0x10) = (ushort)bVar1;
    return local_res8;
  }
  uVar16 = 0x20019;
  uVar17 = 0;
  local_60 = lVar12;
  iVar8 = (**(code **)(WdfFunctions_01033 + 0x180))(WdfDriverGlobals,param_1,1);
  if (iVar8 < 0) {
    return local_res8;
  }
  uVar9 = PdoGetRegistryValue(L"DevicePolicy",L"Interrupt Management\\Affinity Policy",local_88,
                              uVar16,uVar17,local_b8,local_80);
  if ((int)uVar9 < 0) {
LAB_1400195be:
    uVar13 = 1;
  }
  else {
    uVar13 = (ushort)(byte)local_b8[0];
    if (5 < (byte)local_b8[0]) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x5d,
                         &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids);
      }
      goto LAB_1400195be;
    }
  }
  pwVar10 = L"Interrupt Management\\MessageSignaledInterruptProperties\\Range";
  local_b0 = 0;
  pwStack_a8 = (wchar_t *)0x0;
  lVar11 = 0x7fff;
  do {
    if (*pwVar10 == L'\0') {
      pwStack_a8 = L"Interrupt Management\\MessageSignaledInterruptProperties\\Range";
      sVar2 = (0x7fff - (short)lVar11) * 2;
      local_b0._0_4_ = CONCAT22(sVar2 + 2,sVar2);
      local_b0 = (ulonglong)(uint)local_b0;
      break;
    }
    pwVar10 = pwVar10 + 1;
    lVar11 = lVar11 + -1;
  } while (lVar11 != 0);
  iVar8 = (**(code **)(WdfFunctions_01033 + 0x728))(WdfDriverGlobals,local_88,&local_b0,0x20019);
  uVar7 = uVar13;
  if (-1 < iVar8) {
    do {
      RtlStringCchPrintfW(local_50,5,L"%d",(ulonglong)uVar14);
      pwVar10 = local_50;
      local_70 = 0;
      pwStack_68 = (wchar_t *)0x0;
      lVar12 = 0x7fff;
      do {
        if (*pwVar10 == L'\0') {
          sVar2 = (0x7fff - (short)lVar12) * 2;
          local_70 = (ulonglong)CONCAT22(sVar2 + 2,sVar2);
          pwStack_68 = local_50;
          break;
        }
        pwVar10 = pwVar10 + 1;
        lVar12 = lVar12 + -1;
      } while (lVar12 != 0);
      iVar8 = (**(code **)(WdfFunctions_01033 + 0x728))(WdfDriverGlobals,local_78,&local_70,0x20019)
      ;
      if (iVar8 < 0) goto LAB_140019920;
      pwVar10 = L"StartingMessage";
      local_b0 = 0;
      pwStack_a8 = (wchar_t *)0x0;
      lVar12 = 0x7fff;
      do {
        if (*pwVar10 == L'\0') {
          pwStack_a8 = L"StartingMessage";
          sVar2 = (0x7fff - (short)lVar12) * 2;
          local_b0._0_4_ = CONCAT22(sVar2 + 2,sVar2);
          local_b0 = (ulonglong)(uint)local_b0;
          break;
        }
        pwVar10 = pwVar10 + 1;
        lVar12 = lVar12 + -1;
      } while (lVar12 != 0);
      iVar8 = (**(code **)(WdfFunctions_01033 + 0x758))(WdfDriverGlobals,local_90,&local_b0,4);
      if (-1 < iVar8) {
        pwVar10 = L"EndingMessage";
        local_b0 = 0;
        pwStack_a8 = (wchar_t *)0x0;
        lVar12 = 0x7fff;
        do {
          if (*pwVar10 == L'\0') {
            pwStack_a8 = L"EndingMessage";
            sVar2 = (0x7fff - (short)lVar12) * 2;
            local_b0._0_4_ = CONCAT22(sVar2 + 2,sVar2);
            local_b0 = (ulonglong)(uint)local_b0;
            break;
          }
          pwVar10 = pwVar10 + 1;
          lVar12 = lVar12 + -1;
        } while (lVar12 != 0);
        iVar8 = (**(code **)(WdfFunctions_01033 + 0x758))(WdfDriverGlobals,local_90,&local_b0,4);
        if (((-1 < iVar8) && (local_9c <= param_2)) && (param_2 <= local_98)) {
          pwVar10 = L"DevicePolicy";
          local_b0 = 0;
          pwStack_a8 = (wchar_t *)0x0;
          lVar12 = 0x7fff;
          bVar3 = true;
          do {
            if (*pwVar10 == L'\0') {
              pwStack_a8 = L"DevicePolicy";
              sVar2 = (0x7fff - (short)lVar12) * 2;
              local_b0._0_4_ = CONCAT22(sVar2 + 2,sVar2);
              local_b0 = (ulonglong)(uint)local_b0;
              break;
            }
            pwVar10 = pwVar10 + 1;
            lVar12 = lVar12 + -1;
          } while (lVar12 != 0);
          iVar8 = (**(code **)(WdfFunctions_01033 + 0x758))(WdfDriverGlobals,local_90,&local_b0,4);
          if (-1 < iVar8) {
            uVar7 = (ushort)(byte)local_b8[0];
            if ((byte)local_b8[0] < 6) goto LAB_1400198ef;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x5e,
                               &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids);
            }
          }
          uVar7 = uVar13;
        }
      }
LAB_1400198ef:
      (**(code **)(WdfFunctions_01033 + 0x738))(WdfDriverGlobals,local_90);
      if ((bVar3) || (uVar14 = uVar14 + 1, 9999 < uVar14)) goto LAB_140019920;
    } while( true );
  }
  *(char *)(lVar12 + 0x130) = (char)uVar13;
LAB_140019948:
  uVar14 = g_MsiNextProc;
  if (uVar7 == 5) {
    local_c0 = CONCAT44(local_c0._4_4_,g_MsiNextProc);
    local_60 = 0;
    uStack_58 = 0;
    KeQueryNodeActiveAffinity(g_MsiNextProc >> 0x10,&local_60,0);
    *(undefined2 *)(param_3 + 0x12) = (undefined2)uStack_58;
    *(undefined2 *)(param_3 + 0x10) = 4;
    cVar6 = RtlFindLeastSignificantBit(local_60);
    uVar15 = local_c0._2_2_ + 1;
    local_c0._0_4_ = CONCAT22(uVar15,(ushort)local_c0);
    *(longlong *)(param_3 + 0x18) = 1L << ((char)uVar14 + cVar6 & 0x3fU);
    uVar7 = KeQueryHighestNodeNumber();
    uVar13 = (ushort)local_c0;
    if (uVar7 < uVar15) {
      uVar13 = (ushort)local_c0 + 1;
      uVar4 = (uint6)(local_c0 >> 0x10);
      local_c0._2_6_ = uVar4 & 0xffffffff0000;
      uVar5 = local_c0._2_6_;
      uVar15 = 0;
      local_c0 = CONCAT62(uVar4,uVar13) & 0xffffffff0000ffff;
      if (*(ushort *)(lVar12 + 0x132) <= uVar13) {
        uVar13 = 0;
        local_c0 = (ulonglong)uVar5 << 0x10;
      }
    }
    local_c8[0] = 0;
    do {
      do {
        KeQueryNodeActiveAffinity(uVar15,0,local_c8);
        if (uVar13 < local_c8[0]) goto LAB_140019a51;
        uVar15 = uVar15 + 1;
        local_c0._0_4_ = CONCAT22(uVar15,(ushort)local_c0);
        uVar7 = KeQueryHighestNodeNumber();
      } while (uVar15 <= uVar7);
      uVar13 = uVar13 + 1;
      uVar4 = (uint6)(local_c0 >> 0x10);
      local_c0._2_6_ = uVar4 & 0xffffffff0000;
      uVar5 = local_c0._2_6_;
      uVar15 = 0;
      local_c0 = CONCAT62(uVar4,uVar13) & 0xffffffff0000ffff;
    } while (uVar13 < *(ushort *)(lVar12 + 0x132));
    local_c0 = (ulonglong)uVar5 << 0x10;
LAB_140019a51:
    g_MsiNextProc = (uint)local_c0;
  }
  else {
    *(ushort *)(param_3 + 0x10) = uVar7;
  }
  if (local_88 != 0) {
    (**(code **)(WdfFunctions_01033 + 0x738))(WdfDriverGlobals);
  }
  return local_res8;
LAB_140019920:
  (**(code **)(WdfFunctions_01033 + 0x738))(WdfDriverGlobals,local_78);
  param_3 = local_c0;
  lVar12 = local_60;
  goto LAB_140019948;
}



===== PdoAppendMsiRequirements @ 140019ab0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PdoAppendMsiRequirements
              (undefined8 param_1,undefined8 param_2,char param_3,uint param_4,char param_5)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  int extraout_EAX;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined2 uVar7;
  undefined1 auStackY_98 [32];
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_98;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (param_3 == '\0') {
    uVar6 = 0;
    if (param_4 != 0) {
      do {
        RtlSetVolatileMemory(&local_68,0,0x20);
        uVar1 = local_68;
        local_68._0_3_ = CONCAT21(0x102,(undefined1)local_68);
        uVar2 = local_68;
        local_68._6_2_ = SUB82(uVar1,6);
        local_68._0_4_ = (undefined4)uVar2;
        local_68._0_6_ = CONCAT24(7,(undefined4)local_68);
        uStack_60 = 0xfffffffefffffffe;
        local_58 = CONCAT44(2,(undefined4)local_58);
        uVar5 = GetMessagePolicy(param_1,uVar6,(ulonglong)&local_68);
        if (extraout_EAX < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return extraout_EAX;
          }
          uVar7 = 0x5f;
          iVar4 = extraout_EAX;
LAB_140019bc6:
          WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar5,uVar7,
                            &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)iVar4);
          return iVar4;
        }
        iVar4 = (**(code **)(WdfFunctions_01033 + 0x938))(WdfDriverGlobals,param_2,&local_68);
        if (iVar4 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return iVar4;
          }
          uVar7 = 0x60;
          goto LAB_140019bc6;
        }
        uVar6 = uVar6 + uVar5;
      } while (uVar6 < param_4);
    }
  }
  else {
    RtlSetVolatileMemory(&local_68,0,0x20);
    uVar1 = local_68;
    uVar3 = (undefined1)local_68;
    local_68 = CONCAT53(local_68._3_5_,0x10200);
    uStack_60 = CONCAT44(0xfffffffe,~param_4);
    local_58 = CONCAT62(local_58._2_6_,1);
    if (param_5 != '\0') {
      uVar3 = 8;
    }
    local_58 = CONCAT44(2,(undefined4)local_58);
    local_68 = CONCAT71(local_68._1_7_,uVar3);
    uVar2 = local_68;
    local_68._6_2_ = SUB82(uVar1,6);
    local_68._0_4_ = (undefined4)uVar2;
    local_68._0_6_ = CONCAT24(7,(undefined4)local_68);
    iVar4 = (**(code **)(WdfFunctions_01033 + 0x938))(WdfDriverGlobals,param_2,&local_68);
    if (iVar4 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x61,
                          &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)iVar4);
      }
      return iVar4;
    }
  }
  return 0;
}



===== PdoAssignedResourcesWorkItem @ 140019cb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PdoAssignedResourcesWorkItem(undefined8 param_1,int *param_2)

{
  undefined8 *puVar1;
  undefined4 *puVar2;
  longlong lVar3;
  int iVar4;
  ulonglong uVar5;
  uint uVar6;
  undefined1 auStackY_138 [32];
  undefined1 uVar7;
  undefined4 local_e8;
  int local_e4;
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
  undefined4 local_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  int local_88 [2];
  undefined2 local_7e;
  undefined4 local_7c;
  undefined8 local_78;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_138;
  memset(local_88,0,0x50);
  memset(&local_e8,0,0x58);
  uVar5 = Feature_VpciVscRelaxedInterruptLimit__private_IsEnabledDeviceUsageNoInline();
  uVar7 = SUB81(param_2,0);
  if ((int)uVar5 != 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x99,
                         &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar7,
                         (char)SystemReserved1[0xf]);
    }
    if (((-1 < param_2[0x74]) && (0x10005 < *(uint *)(*(longlong *)(param_2 + 0xc) + 0x18))) &&
       (param_2[0x4a] != 0)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x9a,
                           &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar7,
                           (char)param_2[0x4a]);
      }
      uVar6 = 0;
      if (param_2[0x4a] != 0) {
        do {
          local_e4 = *param_2;
          local_e8 = 0x4249001b;
          uVar5 = (ulonglong)uVar6;
          lVar3 = *(longlong *)(param_2 + 0x48);
          puVar1 = (undefined8 *)(lVar3 + uVar5 * 0x50);
          local_e0 = *puVar1;
          uStack_d8 = puVar1[1];
          puVar1 = (undefined8 *)(lVar3 + 0x10 + uVar5 * 0x50);
          local_d0 = *puVar1;
          uStack_c8 = puVar1[1];
          puVar1 = (undefined8 *)(lVar3 + 0x20 + uVar5 * 0x50);
          local_c0 = *puVar1;
          uStack_b8 = puVar1[1];
          puVar2 = (undefined4 *)(lVar3 + 0x30 + uVar5 * 0x50);
          local_b0 = *puVar2;
          uStack_ac = puVar2[1];
          uStack_a8 = puVar2[2];
          uStack_a4 = puVar2[3];
          puVar2 = (undefined4 *)(lVar3 + 0x40 + uVar5 * 0x50);
          local_a0 = *puVar2;
          uStack_9c = puVar2[1];
          uStack_98 = puVar2[2];
          uStack_94 = puVar2[3];
          iVar4 = VmbChannelSendSynchronousRequest
                            (*(undefined8 *)(*(longlong *)(param_2 + 0xc) + 0x28),&local_e8,0x58);
          iVar4 = GetCompletionStatus(iVar4,local_88,0x50);
          param_2[0x74] = iVar4;
          if (iVar4 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x9b,
                                 &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar7,(char)iVar4)
              ;
            }
            break;
          }
          uVar6 = uVar6 + 1;
          *(undefined8 *)(*(longlong *)(param_2 + 0x48) + 8 + uVar5 * 0x50) = local_78;
          *(undefined4 *)(*(longlong *)(param_2 + 0x48) + 4 + uVar5 * 0x50) = local_7c;
          *(undefined2 *)(*(longlong *)(param_2 + 0x48) + 2 + uVar5 * 0x50) = local_7e;
        } while (uVar6 < (uint)param_2[0x4a]);
      }
      if (param_2[0x74] < 0) {
        PdoSendReleaseResourcesMessage(param_2);
        RtlSetVolatileMemory(*(void **)(param_2 + 0x48),0,(ulonglong)(uint)param_2[0x4a] * 0x50);
      }
    }
  }
  PdoRunStateMachine(param_2,0xc);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xe,0x9c,
                      &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar7);
  }
  (**(code **)(WdfFunctions_01033 + 0x670))
            (WdfDriverGlobals,*(undefined8 *)(param_2 + 2),0xffffffffdead0002,0x1e88);
  return;
}



===== PdoAttemptFunctionLevelDeviceReset @ 140019fcc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PdoAttemptFunctionLevelDeviceReset(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  uint *puVar4;
  uint uVar5;
  undefined1 auStackY_a8 [32];
  char local_78;
  char local_77 [7];
  uint local_70;
  uint local_6c [5];
  ulonglong auStack_58 [5];
  undefined4 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_30 = 0;
  local_78 = '\0';
  local_77[0] = '\0';
  iVar2 = 0;
  local_6c[3] = 0;
  local_6c[4] = 0;
  auStack_58[0] = 0;
  auStack_58[1] = 0;
  auStack_58[2] = 0;
  auStack_58[3] = 0;
  auStack_58[4] = 0;
  (**(code **)(WdfFunctions_01033 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 8),0);
  if ((*(uint *)(*(longlong *)(param_1 + 0xc) + 0x18) < 0x10005) &&
     (*(char *)((longlong)param_1 + 0x341) == '\0')) {
    iVar1 = -0x3fffff45;
  }
  else {
    iVar1 = PdoDeactivateDevice(param_1,local_77,&local_78);
    if (-1 < iVar1) {
      uVar3 = VscQueryRegistryPreferredResetMechanism();
      local_70 = (uint)uVar3;
      uVar3 = uVar3 & 0xffffffff;
      puVar4 = &local_70;
      uVar5 = 0;
      local_6c[0] = (uint)(local_70 != 1);
      do {
        iVar1 = -0x3fffff45;
        if ((int)uVar3 == 0) {
          if (0x10004 < *(uint *)(*(longlong *)(param_1 + 0xc) + 0x18)) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0xd8,
                                &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_1);
            }
            iVar1 = PdoSendSynchronousResetPacket(param_1);
            if ((-1 < iVar1) || (iVar1 != -0x3fffff45)) break;
          }
        }
        else if (((int)uVar3 == 1) && (*(char *)((longlong)param_1 + 0x341) != '\0')) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0xd9,
                              &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_1);
          }
          FdoReadConfig(*(longlong *)(param_1 + 0xc),*param_1,(undefined4 *)auStack_58,
                        (ulonglong)(*(byte *)(param_1 + 0x4b) + 8),2);
          auStack_58[0] = auStack_58[0] | 0x8000;
          FdoWriteConfig(*(longlong *)(param_1 + 0xc),*param_1,(undefined4 *)auStack_58,
                         (ulonglong)(*(byte *)(param_1 + 0x4b) + 8),2);
          iVar1 = 0;
          break;
        }
        uVar5 = uVar5 + 1;
        puVar4 = puVar4 + 1;
        if (1 < uVar5) break;
        uVar3 = (ulonglong)*puVar4;
      } while( true );
    }
    iVar2 = PdoReactivateDevice(param_1,local_77[0],local_78);
  }
  (**(code **)(WdfFunctions_01033 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 8));
  if ((-1 < iVar1) && (iVar2 < 0)) {
    iVar1 = -0x3ffffe7e;
  }
  return iVar1;
}



===== PdoCreate @ 14001a230 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

uint PdoCreate(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  char cVar4;
  short sVar5;
  ushort uVar6;
  uint uVar7;
  int iVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  uint *puVar11;
  void *_Dst;
  uint *puVar12;
  longlong lVar13;
  longlong lVar14;
  undefined8 uVar15;
  ushort uVar16;
  undefined *puVar17;
  undefined2 uVar18;
  undefined1 auStackY_4f8 [32];
  undefined1 uVar19;
  undefined8 local_4b8;
  undefined2 local_4b0;
  undefined8 local_4a8;
  ushort local_4a0 [8];
  undefined8 local_490;
  undefined8 uStack_488;
  ulonglong local_480;
  undefined8 *puStack_478;
  undefined *local_470;
  undefined8 uStack_468;
  undefined8 local_460;
  undefined8 uStack_458;
  ulonglong local_450;
  code *pcStack_448;
  code *local_440;
  undefined8 uStack_438;
  undefined8 local_430;
  undefined8 uStack_428;
  undefined *local_420;
  undefined8 local_418;
  ulonglong local_410;
  code *pcStack_408;
  undefined8 local_400;
  undefined8 local_3f8;
  wchar_t *local_3f0;
  undefined4 local_3e8;
  undefined8 local_3e4;
  undefined1 local_3db;
  code *local_3b8;
  undefined4 local_398;
  undefined8 local_388;
  undefined8 local_380;
  undefined8 local_378;
  uint *puStack_370;
  code *local_368;
  code *pcStack_360;
  ulonglong local_358;
  undefined8 local_350;
  uint *puStack_348;
  code *local_340;
  code *pcStack_338;
  code *local_330;
  undefined8 local_328;
  uint *puStack_320;
  code *local_318;
  code *pcStack_310;
  code *local_308;
  code *pcStack_300;
  undefined8 local_2f8;
  undefined8 local_2f0;
  undefined8 uStack_2e8;
  undefined8 local_2d8;
  uint *local_2d0;
  code *local_2c8;
  code *local_2c0;
  code *local_2b8;
  code *local_2b0;
  code *local_2a8;
  code *local_2a0;
  undefined8 local_298;
  uint *local_290;
  code *local_288;
  code *local_280;
  code *local_278;
  code *local_270;
  code *local_268;
  code *local_260;
  code *local_258;
  undefined4 local_248;
  undefined4 local_244;
  code *local_240;
  code *local_238;
  code *local_230;
  undefined4 local_208;
  undefined4 local_204;
  code *local_200;
  code *local_1f0;
  code *local_1e0;
  code *local_1d8;
  code *local_1c8;
  code *local_1c0;
  code *local_1b8;
  code *local_1b0;
  code *local_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined4 local_118;
  undefined4 local_110;
  undefined1 local_10c;
  wchar_t local_108 [16];
  undefined2 local_e8 [16];
  undefined2 local_c8 [64];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_4f8;
  local_420 = (undefined *)((ulonglong)local_420 & 0xffffffff00000000);
  local_380 = 0;
  local_450 = 0;
  pcStack_448 = (code *)0x0;
  local_440 = (code *)0x0;
  uStack_438 = 0;
  local_430 = 0;
  uStack_428 = 0;
  local_4a0[0] = 0;
  local_4a0[1] = 0;
  local_4a0[2] = 0;
  local_4a0[3] = 0;
  local_4a0[4] = 0;
  local_4a0[5] = 0;
  local_4a0[6] = 0;
  local_4a0[7] = 0;
  local_490 = 0;
  uStack_488 = 0;
  local_4b8 = param_3;
  memset(&local_2d8,0,0x40);
  local_418 = 0;
  memset(&local_298,0,0x48);
  local_4a8 = 0;
  local_244 = 0;
  local_204 = 0;
  local_178 = 0;
  uStack_170 = 0;
  local_460 = 0;
  local_168 = 0;
  uStack_160 = 0;
  uStack_458 = (ulonglong)uStack_458._4_4_ << 0x20;
  local_158 = 0;
  uStack_150 = 0;
  local_480 = 0;
  puStack_478 = (undefined8 *)0x0;
  local_470 = (undefined *)0x0;
  uStack_468 = 0;
  memset(&local_3e8,0,0x60);
  local_4b0 = (ushort)local_4b0._1_1_ << 8;
  local_2f8 = 0;
  local_358 = 0;
  local_400 = (ulonglong)local_400._4_4_ << 0x20;
  local_330 = (code *)0x0;
  local_118 = 0;
  local_328 = 0;
  puStack_320 = (uint *)0x0;
  local_318 = (code *)0x0;
  pcStack_310 = (code *)0x0;
  local_308 = (code *)0x0;
  pcStack_300 = (code *)0x0;
  local_378 = 0;
  puStack_370 = (uint *)0x0;
  local_368 = (code *)0x0;
  pcStack_360 = (code *)0x0;
  local_410 = 0;
  pcStack_408 = (code *)0x0;
  local_350 = 0;
  puStack_348 = (uint *)0x0;
  local_340 = (code *)0x0;
  pcStack_338 = (code *)0x0;
  local_2f0 = 0;
  uStack_2e8 = 0;
  local_148 = 0;
  uStack_140 = 0;
  local_138 = 0;
  uStack_130 = 0;
  local_128 = 0;
  uStack_120 = 0;
  uVar10 = (**(code **)(WdfFunctions_01033 + 8))(WdfDriverGlobals,param_1);
  local_388 = (**(code **)(WdfFunctions_01033 + 0x650))
                        (WdfDriverGlobals,uVar10,PTR__WDF_VPCI_FDO_CONTEXT_TYPE_INFO_140010040);
  local_c8[0] = 0;
  RtlInitUnicodeString(local_4a0,local_c8);
  local_e8[0] = 0;
  local_4a0[1] = 0x80;
  RtlInitUnicodeString(&local_490,local_e8);
  local_490._0_4_ = CONCAT22(0x14,(undefined2)local_490);
  (**(code **)(WdfFunctions_01033 + 0x210))(WdfDriverGlobals,local_4b8,0x2a);
  (**(code **)(WdfFunctions_01033 + 0x1e8))(WdfDriverGlobals,local_4b8,3);
  memset(&local_248,0,0x40);
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_248 = 0x40;
  }
  else if (WdfStructureCount < 0x29) {
    local_248 = 0xffffffff;
  }
  else {
    local_248 = *(undefined4 *)(WdfStructures + 0x140);
  }
  local_238 = PdoQueryResourceRequirements;
  local_240 = PdoQueryResources;
  local_230 = PdoDeviceEject;
  (**(code **)(WdfFunctions_01033 + 0x698))(WdfDriverGlobals,local_4b8,&local_248);
  memset(&local_208,0,0x90);
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_208 = 0x90;
  }
  else if (WdfStructureCount < 0x2a) {
    local_208 = 0xffffffff;
  }
  else {
    local_208 = *(undefined4 *)(WdfStructures + 0x148);
  }
  local_1e0 = PdoPrepareHardware;
  local_1d8 = PdoReleaseHardware;
  local_200 = PdoD0Entry;
  local_1f0 = PdoD0Exit;
  local_180 = PdoDeviceUsageNotificationEx;
  local_1c8 = PdoSelfManagedIoFlush;
  uVar9 = Feature_VpciVscBootDiskHibernation__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar9 != 0) {
    local_1c0 = PdoSelfManagedIoInit;
    local_1b0 = PdoSelfManagedIoRestart;
    local_1b8 = PdoSelfManagedIoSuspend;
  }
  uVar10 = local_4b8;
  (**(code **)(WdfFunctions_01033 + 0x1b8))(WdfDriverGlobals,local_4b8,&local_208);
  uVar7 = QueryChildEnumerationPrefix
                    ((wchar_t *)(param_2 + 0x1c),uVar10,(longlong)&local_490,
                     (undefined1 *)&local_4b0);
  if ((int)uVar7 < 0) goto LAB_14001c3f8;
  iVar8 = *(int *)(param_2 + 0x14);
  uVar10 = RtlUnicodeStringPrintf
                     (local_4a0,L"%wZ\\VEN_%04X&DEV_%04X&SUBSYS_%08X&REV_%02X",&local_490,
                      (ulonglong)*(ushort *)(param_2 + 0xc));
  uVar7 = (uint)uVar10;
  if ((int)uVar7 < 0) goto LAB_14001c3f8;
  uVar7 = (**(code **)(WdfFunctions_01033 + 0x6a0))(WdfDriverGlobals,local_4b8,local_4a0);
  if ((int)uVar7 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar7;
    }
    uVar18 = 0x25;
  }
  else {
    uVar7 = (**(code **)(WdfFunctions_01033 + 0x6b0))(WdfDriverGlobals,local_4b8,local_4a0);
    if ((int)uVar7 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar7;
      }
      uVar18 = 0x26;
    }
    else {
      uVar10 = RtlUnicodeStringPrintf
                         (local_4a0,L"%wZ\\VEN_%04X&DEV_%04X&SUBSYS_%08X",&local_490,
                          (ulonglong)*(ushort *)(param_2 + 0xc));
      uVar7 = (uint)uVar10;
      if ((int)uVar7 < 0) goto LAB_14001c3f8;
      uVar7 = (**(code **)(WdfFunctions_01033 + 0x6b0))(WdfDriverGlobals,local_4b8,local_4a0);
      if ((int)uVar7 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return uVar7;
        }
        uVar18 = 0x27;
      }
      else if (iVar8 == 0) {
        uVar10 = RtlUnicodeStringPrintf
                           (local_4a0,L"%wZ\\VEN_%04X&DEV_%04X&REV_%02X",&local_490,
                            (ulonglong)*(ushort *)(param_2 + 0xc));
        uVar7 = (uint)uVar10;
        if ((int)uVar7 < 0) goto LAB_14001c3f8;
        uVar7 = (**(code **)(WdfFunctions_01033 + 0x6b0))(WdfDriverGlobals,local_4b8,local_4a0);
        if ((int)uVar7 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return uVar7;
          }
          uVar18 = 0x28;
        }
        else {
          uVar10 = RtlUnicodeStringPrintf
                             (local_4a0,L"%wZ\\VEN_%04X&DEV_%04X",&local_490,
                              (ulonglong)*(ushort *)(param_2 + 0xc));
          uVar7 = (uint)uVar10;
          if ((int)uVar7 < 0) goto LAB_14001c3f8;
          uVar7 = (**(code **)(WdfFunctions_01033 + 0x6b0))(WdfDriverGlobals,local_4b8,local_4a0);
          if (-1 < (int)uVar7) goto LAB_14001a880;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return uVar7;
          }
          uVar18 = 0x29;
        }
      }
      else {
LAB_14001a880:
        uVar10 = RtlUnicodeStringPrintf
                           (local_4a0,L"%wZ\\VEN_%04X&DEV_%04X&CC_%02X%02X%02X",&local_490,
                            (ulonglong)*(ushort *)(param_2 + 0xc));
        uVar7 = (uint)uVar10;
        if ((int)uVar7 < 0) goto LAB_14001c3f8;
        uVar7 = (**(code **)(WdfFunctions_01033 + 0x6b0))(WdfDriverGlobals,local_4b8,local_4a0);
        if ((int)uVar7 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return uVar7;
          }
          uVar18 = 0x2a;
        }
        else {
          uVar10 = RtlUnicodeStringPrintf
                             (local_4a0,L"%wZ\\VEN_%04X&DEV_%04X&CC_%02X%02X",&local_490,
                              (ulonglong)*(ushort *)(param_2 + 0xc));
          uVar7 = (uint)uVar10;
          if ((int)uVar7 < 0) goto LAB_14001c3f8;
          uVar7 = (**(code **)(WdfFunctions_01033 + 0x6b0))(WdfDriverGlobals,local_4b8,local_4a0);
          if ((int)uVar7 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
              return uVar7;
            }
            uVar18 = 0x2b;
          }
          else if (iVar8 == 0) {
LAB_14001aa92:
            uVar10 = RtlUnicodeStringPrintf
                               (local_4a0,L"%wZ\\VEN_%04X&CC_%02X%02X%02X",&local_490,
                                (ulonglong)*(ushort *)(param_2 + 0xc));
            uVar7 = (uint)uVar10;
            if ((int)uVar7 < 0) goto LAB_14001c3f8;
            uVar7 = (**(code **)(WdfFunctions_01033 + 0x6b8))(WdfDriverGlobals,local_4b8,local_4a0);
            if ((int)uVar7 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                return uVar7;
              }
              uVar18 = 0x2e;
            }
            else {
              uVar10 = RtlUnicodeStringPrintf
                                 (local_4a0,L"%wZ\\VEN_%04X&CC_%02X%02X",&local_490,
                                  (ulonglong)*(ushort *)(param_2 + 0xc));
              uVar7 = (uint)uVar10;
              if ((int)uVar7 < 0) goto LAB_14001c3f8;
              uVar7 = (**(code **)(WdfFunctions_01033 + 0x6b8))
                                (WdfDriverGlobals,local_4b8,local_4a0);
              if ((int)uVar7 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                  return uVar7;
                }
                uVar18 = 0x2f;
              }
              else {
                uVar10 = RtlUnicodeStringPrintf
                                   (local_4a0,L"%wZ\\VEN_%04X",&local_490,
                                    (ulonglong)*(ushort *)(param_2 + 0xc));
                uVar7 = (uint)uVar10;
                if ((int)uVar7 < 0) goto LAB_14001c3f8;
                uVar7 = (**(code **)(WdfFunctions_01033 + 0x6b8))
                                  (WdfDriverGlobals,local_4b8,local_4a0);
                if ((int)uVar7 < 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                    return uVar7;
                  }
                  uVar18 = 0x30;
                }
                else {
                  uVar10 = RtlUnicodeStringPrintf
                                     (local_4a0,L"%wZ\\CC_%02X%02X%02X&DT_%01X",&local_490,
                                      (ulonglong)*(byte *)(param_2 + 0x13));
                  uVar7 = (uint)uVar10;
                  if ((int)uVar7 < 0) goto LAB_14001c3f8;
                  uVar7 = (**(code **)(WdfFunctions_01033 + 0x6b8))
                                    (WdfDriverGlobals,local_4b8,local_4a0);
                  if ((int)uVar7 < 0) {
                    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                      return uVar7;
                    }
                    uVar18 = 0x31;
                  }
                  else {
                    uVar10 = RtlUnicodeStringPrintf
                                       (local_4a0,L"%wZ\\CC_%02X%02X%02X",&local_490,
                                        (ulonglong)*(byte *)(param_2 + 0x13));
                    uVar7 = (uint)uVar10;
                    if ((int)uVar7 < 0) goto LAB_14001c3f8;
                    uVar7 = (**(code **)(WdfFunctions_01033 + 0x6b8))
                                      (WdfDriverGlobals,local_4b8,local_4a0);
                    if ((int)uVar7 < 0) {
                      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                        return uVar7;
                      }
                      uVar18 = 0x32;
                    }
                    else {
                      uVar10 = RtlUnicodeStringPrintf
                                         (local_4a0,L"%wZ\\CC_%02X%02X&DT_%01X",&local_490,
                                          (ulonglong)*(byte *)(param_2 + 0x13));
                      uVar7 = (uint)uVar10;
                      if ((int)uVar7 < 0) goto LAB_14001c3f8;
                      uVar7 = (**(code **)(WdfFunctions_01033 + 0x6b8))
                                        (WdfDriverGlobals,local_4b8,local_4a0);
                      if ((int)uVar7 < 0) {
                        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                          return uVar7;
                        }
                        uVar18 = 0x33;
                      }
                      else {
                        uVar10 = RtlUnicodeStringPrintf
                                           (local_4a0,L"%wZ\\CC_%02x%02x",&local_490,
                                            (ulonglong)*(byte *)(param_2 + 0x13));
                        uVar7 = (uint)uVar10;
                        if ((int)uVar7 < 0) goto LAB_14001c3f8;
                        uVar7 = (**(code **)(WdfFunctions_01033 + 0x6b8))
                                          (WdfDriverGlobals,local_4b8,local_4a0);
                        if ((int)uVar7 < 0) {
                          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                            return uVar7;
                          }
                          uVar18 = 0x34;
                        }
                        else {
                          cVar4 = (char)local_4b0;
                          if ((char)local_4b0 != '\0') {
                            RtlInitUnicodeString(&local_2f0,DefaultPrefixPcip);
                            iVar8 = RtlCompareUnicodeString(&local_2f0,&local_490,1);
                            if (iVar8 == 0) {
                              builtin_wcsncpy(local_108,L"PCIP\\Generic",0xd);
                              local_3f0 = local_108;
                              local_3f8 = 0x1a0018;
                              uVar7 = (**(code **)(WdfFunctions_01033 + 0x6b8))
                                                (WdfDriverGlobals,local_4b8,&local_3f8);
                              if ((int)uVar7 < 0) {
                                if ((undefined **)WPP_RECORDER_INITIALIZED ==
                                    &WPP_RECORDER_INITIALIZED) {
                                  return uVar7;
                                }
                                uVar18 = 0x35;
                                goto LAB_14001a6a7;
                              }
                            }
                          }
                          cVar1 = *(char *)(param_2 + 0x13);
                          if (cVar1 == '\x01') {
                            puVar17 = &DeviceTextStorage;
                          }
                          else if (cVar1 == '\x02') {
                            puVar17 = &DeviceTextNetwork;
                          }
                          else if (cVar1 == '\x03') {
                            puVar17 = &DeviceTextDisplay;
                          }
                          else {
                            puVar17 = &DeviceTextDefault;
                          }
                          uVar10 = RtlUnicodeStringPrintf
                                             (local_4a0,L"Virtual PCI Bus Slot %u Serial %u",
                                              (ulonglong)*(uint *)(param_2 + 4),
                                              (ulonglong)*(uint *)(param_2 + 8));
                          uVar7 = (uint)uVar10;
                          if ((int)uVar7 < 0) goto LAB_14001c3f8;
                          uVar7 = (**(code **)(WdfFunctions_01033 + 0x6c0))
                                            (WdfDriverGlobals,local_4b8,puVar17,local_4a0);
                          if ((int)uVar7 < 0) {
                            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                            {
                              return uVar7;
                            }
                            uVar18 = 0x36;
                          }
                          else {
                            (**(code **)(WdfFunctions_01033 + 0x6c8))
                                      (WdfDriverGlobals,local_4b8,0x409);
                            uVar7 = RtlIntegerToUnicodeString
                                              (*(undefined4 *)(param_2 + 4),0x10,local_4a0);
                            if ((int)uVar7 < 0) {
                              if ((undefined **)WPP_RECORDER_INITIALIZED ==
                                  &WPP_RECORDER_INITIALIZED) {
                                return uVar7;
                              }
                              uVar18 = 0x37;
                            }
                            else {
                              uVar7 = (**(code **)(WdfFunctions_01033 + 0x6a8))
                                                (WdfDriverGlobals,local_4b8,local_4a0);
                              if ((int)uVar7 < 0) {
                                if ((undefined **)WPP_RECORDER_INITIALIZED ==
                                    &WPP_RECORDER_INITIALIZED) {
                                  return uVar7;
                                }
                                uVar18 = 0x38;
                              }
                              else {
                                local_110 = 0x307100f;
                                uVar9 = Feature_CvmDmaBouncing__private_IsEnabledDeviceUsageNoInline
                                                  ();
                                if ((int)uVar9 != 0) {
                                  local_10c = 0;
                                }
                                uVar7 = (**(code **)(WdfFunctions_01033 + 0x248))
                                                  (WdfDriverGlobals,local_4b8,PdoPreprocessPnp,0x1b)
                                ;
                                if ((int)uVar7 < 0) {
                                  if ((undefined **)WPP_RECORDER_INITIALIZED ==
                                      &WPP_RECORDER_INITIALIZED) {
                                    return uVar7;
                                  }
                                  uVar18 = 0x39;
                                }
                                else {
                                  local_110 = CONCAT31(local_110._1_3_,2);
                                  uVar7 = (**(code **)(WdfFunctions_01033 + 0x248))
                                                    (WdfDriverGlobals,local_4b8,PdoPreprocessPower,
                                                     0x16);
                                  if ((int)uVar7 < 0) {
                                    if ((undefined **)WPP_RECORDER_INITIALIZED ==
                                        &WPP_RECORDER_INITIALIZED) {
                                      return uVar7;
                                    }
                                    uVar18 = 0x3a;
                                  }
                                  else {
                                    local_430 = 0;
                                    uStack_428 = 0;
                                    if (WdfClientVersionHigherThanFramework == '\0') {
                                      local_450 = 0x38;
                                    }
                                    else if (WdfStructureCount < 0x27) {
                                      local_450 = 0xffffffff;
                                    }
                                    else {
                                      local_450 = (ulonglong)*(uint *)(WdfStructures + 0x130);
                                    }
                                    uStack_438 = 0x100000001;
                                    local_420 = PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8;
                                    pcStack_448 = PdoContextCleanup;
                                    local_440 = PdoContextDestroy;
                                    uVar7 = (**(code **)(WdfFunctions_01033 + 600))
                                                      (WdfDriverGlobals,&local_4b8,&local_450,
                                                       &local_4a8);
                                    if (-1 < (int)uVar7) {
                                      if ((undefined **)WPP_RECORDER_INITIALIZED !=
                                          &WPP_RECORDER_INITIALIZED) {
                                        WPP_RECORDER_SF_DDq(*(undefined8 *)
                                                             (WPP_GLOBAL_Control + 0x40));
                                      }
                                      lVar14 = (**(code **)(WdfFunctions_01033 + 0xf8))
                                                         (WdfDriverGlobals,local_4a8);
                                      uVar15 = local_4a8;
                                      puVar11 = (uint *)(**(code **)(WdfFunctions_01033 + 0x650))
                                                                  (WdfDriverGlobals,local_4a8,
                                                                                                                                      
                                                  PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8);
                                      uVar10 = local_388;
                                      *(undefined8 *)(puVar11 + 2) = local_4a8;
                                      *(undefined8 *)(puVar11 + 4) = *(undefined8 *)(param_2 + 0xc);
                                      puVar11[6] = *(uint *)(param_2 + 0x14);
                                      *puVar11 = *(uint *)(param_2 + 4);
                                      puVar11[7] = *(uint *)(param_2 + 8);
                                      *(undefined2 *)((longlong)puVar11 + 0x24a) =
                                           *(undefined2 *)(param_2 + 0x1a);
                                      uVar19 = *(undefined1 *)(param_2 + 0x18);
                                      *(char *)(puVar11 + 0xc3) = cVar4;
                                      *(undefined1 *)((longlong)puVar11 + 0x342) = 0;
                                      *(undefined1 *)((longlong)puVar11 + 0x249) = uVar19;
                                      *(undefined8 *)(puVar11 + 0xc) = local_388;
                                      uVar9 = Feature_CvmDmaBouncing__private_IsEnabledDeviceUsageNoInline
                                                        ();
                                      uVar19 = SUB81(puVar11,0);
                                      if ((int)uVar9 == 0) {
                                        if ((undefined **)WPP_RECORDER_INITIALIZED !=
                                            &WPP_RECORDER_INITIALIZED) {
                                          uVar15 = CONCAT71((int7)((ulonglong)uVar15 >> 8),4);
                                          WPP_RECORDER_SF_q(*(undefined8 *)
                                                             (WPP_GLOBAL_Control + 0x40),4,2,0x3f,
                                                            &
                                                  WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,
                                                  uVar19);
                                        }
                                      }
                                      else {
                                        uVar7 = HviGetPartitionIsolationType();
                                        if (uVar7 - 2 < 2) {
                                          *(undefined1 *)((longlong)puVar11 + 0x342) = 1;
                                          if ((undefined **)WPP_RECORDER_INITIALIZED !=
                                              &WPP_RECORDER_INITIALIZED) {
                                            uVar18 = 0x3d;
                                            goto LAB_14001b362;
                                          }
                                        }
                                        else if ((undefined **)WPP_RECORDER_INITIALIZED !=
                                                 &WPP_RECORDER_INITIALIZED) {
                                          uVar18 = 0x3e;
LAB_14001b362:
                                          uVar15 = CONCAT71((int7)((ulonglong)uVar15 >> 8),4);
                                          WPP_RECORDER_SF_qd(*(undefined8 *)
                                                              (WPP_GLOBAL_Control + 0x40),4,2,uVar18
                                                             ,&
                                                  WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,
                                                  uVar19,(char)uVar7);
                                        }
                                      }
                                      uVar3 = *(undefined8 *)(param_2 + 0x24);
                                      *(undefined8 *)(puVar11 + 0x93) =
                                           *(undefined8 *)(param_2 + 0x1c);
                                      *(undefined8 *)(puVar11 + 0x95) = uVar3;
                                      uVar3 = *(undefined8 *)(param_2 + 0x34);
                                      *(undefined8 *)(puVar11 + 0x97) =
                                           *(undefined8 *)(param_2 + 0x2c);
                                      *(undefined8 *)(puVar11 + 0x99) = uVar3;
                                      uVar3 = *(undefined8 *)(param_2 + 0x44);
                                      *(undefined8 *)(puVar11 + 0x9b) =
                                           *(undefined8 *)(param_2 + 0x3c);
                                      *(undefined8 *)(puVar11 + 0x9d) = uVar3;
                                      uVar3 = *(undefined8 *)(param_2 + 0x54);
                                      *(undefined8 *)(puVar11 + 0x9f) =
                                           *(undefined8 *)(param_2 + 0x4c);
                                      *(undefined8 *)(puVar11 + 0xa1) = uVar3;
                                      uVar3 = *(undefined8 *)(param_2 + 100);
                                      *(undefined8 *)(puVar11 + 0xa3) =
                                           *(undefined8 *)(param_2 + 0x5c);
                                      *(undefined8 *)(puVar11 + 0xa5) = uVar3;
                                      uVar3 = *(undefined8 *)(param_2 + 0x74);
                                      *(undefined8 *)(puVar11 + 0xa7) =
                                           *(undefined8 *)(param_2 + 0x6c);
                                      *(undefined8 *)(puVar11 + 0xa9) = uVar3;
                                      uVar3 = *(undefined8 *)(param_2 + 0x84);
                                      *(undefined8 *)(puVar11 + 0xab) =
                                           *(undefined8 *)(param_2 + 0x7c);
                                      *(undefined8 *)(puVar11 + 0xad) = uVar3;
                                      uVar3 = *(undefined8 *)(param_2 + 0x94);
                                      *(undefined8 *)(puVar11 + 0xaf) =
                                           *(undefined8 *)(param_2 + 0x8c);
                                      *(undefined8 *)(puVar11 + 0xb1) = uVar3;
                                      uVar3 = *(undefined8 *)(param_2 + 0xa4);
                                      *(undefined8 *)(puVar11 + 0xb3) =
                                           *(undefined8 *)(param_2 + 0x9c);
                                      *(undefined8 *)(puVar11 + 0xb5) = uVar3;
                                      uVar3 = *(undefined8 *)(param_2 + 0xb4);
                                      *(undefined8 *)(puVar11 + 0xb7) =
                                           *(undefined8 *)(param_2 + 0xac);
                                      *(undefined8 *)(puVar11 + 0xb9) = uVar3;
                                      uVar3 = *(undefined8 *)(param_2 + 0xc4);
                                      *(undefined8 *)(puVar11 + 0xbb) =
                                           *(undefined8 *)(param_2 + 0xbc);
                                      *(undefined8 *)(puVar11 + 0xbd) = uVar3;
                                      uVar3 = *(undefined8 *)(param_2 + 0xd4);
                                      *(undefined8 *)(puVar11 + 0xbf) =
                                           *(undefined8 *)(param_2 + 0xcc);
                                      *(undefined8 *)(puVar11 + 0xc1) = uVar3;
                                      if ((undefined **)WPP_RECORDER_INITIALIZED !=
                                          &WPP_RECORDER_INITIALIZED) {
                                        WPP_RECORDER_SF_qqq(*(undefined8 *)
                                                             (WPP_GLOBAL_Control + 0x40),uVar15,2,
                                                            0x40,&
                                                  WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,
                                                  (char)uVar10,uVar19,(char)SystemReserved1[0xf]);
                                      }
                                      uVar7 = PnpBlockerInitRequestor((longlong)puVar11);
                                      if ((int)uVar7 < 0) {
                                        if ((undefined **)WPP_RECORDER_INITIALIZED ==
                                            &WPP_RECORDER_INITIALIZED) {
                                          return uVar7;
                                        }
                                        uVar18 = 0x41;
                                      }
                                      else {
                                        memset(&local_3e8,0,0x60);
                                        if (WdfClientVersionHigherThanFramework == '\0') {
                                          local_3e8 = 0x60;
                                        }
                                        else if (WdfStructureCount < 0x22) {
                                          local_3e8 = 0xffffffff;
                                        }
                                        else {
                                          local_3e8 = *(undefined4 *)(WdfStructures + 0x108);
                                        }
                                        local_398 = 0xffffffff;
                                        local_3b8 = VpciInternalIoControl;
                                        local_3db = 1;
                                        local_3e4 = 2;
                                        uVar7 = (**(code **)(WdfFunctions_01033 + 0x4c0))
                                                          (WdfDriverGlobals,local_4a8,&local_3e8,0);
                                        if ((int)uVar7 < 0) {
                                          if ((undefined **)WPP_RECORDER_INITIALIZED ==
                                              &WPP_RECORDER_INITIALIZED) {
                                            return uVar7;
                                          }
                                          uVar18 = 0x42;
                                        }
                                        else {
                                          memset(&local_3e8,0,0x60);
                                          if (WdfClientVersionHigherThanFramework == '\0') {
                                            local_3e8 = 0x60;
                                          }
                                          else if (WdfStructureCount < 0x22) {
                                            local_3e8 = 0xffffffff;
                                          }
                                          else {
                                            local_3e8 = *(undefined4 *)(WdfStructures + 0x108);
                                          }
                                          local_3e4 = 3;
                                          uVar7 = (**(code **)(WdfFunctions_01033 + 0x4c0))
                                                            (WdfDriverGlobals,local_4a8,&local_3e8,0
                                                            );
                                          if ((int)uVar7 < 0) {
                                            if ((undefined **)WPP_RECORDER_INITIALIZED ==
                                                &WPP_RECORDER_INITIALIZED) {
                                              return uVar7;
                                            }
                                            uVar18 = 0x43;
                                          }
                                          else {
                                            pcStack_448 = (code *)0x0;
                                            local_440 = (code *)0x0;
                                            uStack_428 = 0;
                                            if (WdfClientVersionHigherThanFramework == '\0') {
                                              local_450 = 0x38;
                                            }
                                            else if (WdfStructureCount < 0x27) {
                                              local_450 = 0xffffffff;
                                            }
                                            else {
                                              local_450 = (ulonglong)
                                                          *(uint *)(WdfStructures + 0x130);
                                            }
                                            local_420 = 
                                            PTR__WDF_VPCI_WORKITEM_CONTEXT_TYPE_INFO_140010090;
                                            local_430 = local_4a8;
                                            uStack_438 = 0x100000001;
                                            if (WdfClientVersionHigherThanFramework == '\0') {
                                              local_410 = 0x18;
                                            }
                                            else if (WdfStructureCount < 0x44) {
                                              local_410 = 0xffffffff;
                                            }
                                            else {
                                              local_410 = (ulonglong)
                                                          *(uint *)(WdfStructures + 0x218);
                                            }
                                            pcStack_408 = FdoInvalidateBlockWorker;
                                            local_400 = 1;
                                            uVar7 = (**(code **)(WdfFunctions_01033 + 0xbd8))
                                                              (WdfDriverGlobals,&local_410,
                                                               &local_450,puVar11 + 0x5c);
                                            if ((int)uVar7 < 0) {
                                              if ((undefined **)WPP_RECORDER_INITIALIZED ==
                                                  &WPP_RECORDER_INITIALIZED) {
                                                return uVar7;
                                              }
                                              uVar18 = 0x44;
                                            }
                                            else {
                                              KeInitializeSpinLock(puVar11 + 0x5a);
                                              (**(code **)(WdfFunctions_01033 + 0x188))
                                                        (WdfDriverGlobals,local_4a8,1,1);
                                              (**(code **)(WdfFunctions_01033 + 0x188))
                                                        (WdfDriverGlobals,local_4a8,2,1);
                                              (**(code **)(WdfFunctions_01033 + 0x188))
                                                        (WdfDriverGlobals,local_4a8,3,1);
                                              (**(code **)(WdfFunctions_01033 + 0x188))
                                                        (WdfDriverGlobals,local_4a8,6,1);
                                              uVar10 = PdoScanPciCapabilities(puVar11);
                                              uVar7 = (uint)uVar10;
                                              if ((int)uVar7 < 0) {
                                                if ((undefined **)WPP_RECORDER_INITIALIZED ==
                                                    &WPP_RECORDER_INITIALIZED) {
                                                  return uVar7;
                                                }
                                                uVar18 = 0x45;
                                              }
                                              else {
                                                if (((byte)puVar11[0x4b] != 0) &&
                                                   (FdoReadConfig(*(longlong *)(puVar11 + 0xc),
                                                                  *puVar11,(undefined4 *)
                                                                           ((longlong)&local_148 + 4
                                                                           ),
                                                                  (ulonglong)
                                                                  ((byte)puVar11[0x4b] + 4),4),
                                                   (local_148 & 0x1000000000000000) != 0)) {
                                                  *(undefined1 *)((longlong)puVar11 + 0x341) = 1;
                                                }
                                                local_2c8 = _guard_check_icall;
                                                local_2d8._0_4_ = 0x10040;
                                                local_2c0 = _guard_check_icall;
                                                local_2b8 = VpciTranslateBusAddress;
                                                local_2b0 = VpciGetDmaAdapter;
                                                local_2a8 = VpciSetBusData;
                                                local_2a0 = VpciGetBusData;
                                                uStack_468 = 0;
                                                uStack_458 = 0;
                                                if (WdfClientVersionHigherThanFramework == '\0') {
                                                  local_480 = 0x30;
                                                }
                                                else if (WdfStructureCount < 0x2e) {
                                                  local_480 = 0xffffffff;
                                                }
                                                else {
                                                  local_480 = (ulonglong)
                                                              *(uint *)(WdfStructures + 0x168);
                                                }
                                                puStack_478 = &local_2d8;
                                                local_470 = &GUID_BUS_INTERFACE_STANDARD;
                                                local_460 = 0;
                                                local_2d0 = puVar11;
                                                uVar7 = (**(code **)(WdfFunctions_01033 + 0x720))
                                                                  (WdfDriverGlobals,local_4a8,
                                                                   &local_480);
                                                if ((int)uVar7 < 0) {
                                                  if ((undefined **)WPP_RECORDER_INITIALIZED ==
                                                      &WPP_RECORDER_INITIALIZED) {
                                                    return uVar7;
                                                  }
                                                  uVar18 = 0x46;
                                                }
                                                else {
                                                  uVar7 = VpciInitializeResetInterface(local_4a8);
                                                  if (((int)uVar7 < 0) ||
                                                     (uVar7 = VpciInitializeSecurityInterface
                                                                        (local_4a8), (int)uVar7 < 0)
                                                     ) goto LAB_14001c3f8;
                                                  if (WdfClientVersionHigherThanFramework == '\0') {
                                                    uVar2 = 0x30;
                                                  }
                                                  else if (WdfStructureCount < 0xd) {
                                                    uVar2 = 0xffffffff;
                                                  }
                                                  else {
                                                    uVar2 = *(undefined4 *)(WdfStructures + 0x60);
                                                  }
                                                  local_178 = CONCAT44(2,uVar2);
                                                  local_158 = 0x200000002;
                                                  local_168 = 0x200000002;
                                                  uStack_160 = 0x200000002;
                                                  uStack_150 = CONCAT44(0xffffffff,
                                                                        (*puVar11 & 0x1f) << 0x10 |
                                                                        *puVar11 >> 5 & 7);
                                                  uStack_170 = 0x100000001;
                                                  (**(code **)(WdfFunctions_01033 + 0x298))
                                                            (WdfDriverGlobals,local_4a8,&local_178);
                                                  local_318 = _guard_check_icall;
                                                  local_328 = CONCAT44(local_328._4_4_,0x10038);
                                                  pcStack_310 = _guard_check_icall;
                                                  pcStack_300 = VpciReadConfigBlock;
                                                  local_308 = VpciWriteConfigBlock;
                                                  local_2f8 = CONCAT44(local_2f8._4_4_,
                                                                       *(undefined4 *)(param_2 + 8))
                                                  ;
                                                  uStack_468 = 0;
                                                  uStack_458 = 0;
                                                  if (WdfClientVersionHigherThanFramework == '\0') {
                                                    local_480 = 0x30;
                                                  }
                                                  else if (WdfStructureCount < 0x2e) {
                                                    local_480 = 0xffffffff;
                                                  }
                                                  else {
                                                    local_480 = (ulonglong)
                                                                *(uint *)(WdfStructures + 0x168);
                                                  }
                                                  puStack_478 = &local_328;
                                                  local_470 = &GUID_VPCI_INTERFACE_STANDARD;
                                                  local_460 = 0;
                                                  puStack_320 = puVar11;
                                                  uVar7 = (**(code **)(WdfFunctions_01033 + 0x720))
                                                                    (WdfDriverGlobals,local_4a8,
                                                                     &local_480);
                                                  if ((int)uVar7 < 0) {
                                                    if ((undefined **)WPP_RECORDER_INITIALIZED ==
                                                        &WPP_RECORDER_INITIALIZED) {
                                                      return uVar7;
                                                    }
                                                    uVar18 = 0x47;
                                                  }
                                                  else {
                                                    local_378 = CONCAT44(local_378._4_4_,0x10028);
                                                    local_368 = _guard_check_icall;
                                                    pcStack_360 = _guard_check_icall;
                                                    local_358 = (ulonglong)(*puVar11 >> 5 & 7) |
                                                                (ulonglong)
                                                                *(ushort *)
                                                                 (*(longlong *)(puVar11 + 0xc) +
                                                                 0x34) << 0x10 |
                                                                (ulonglong)
                                                                (*(ushort *)
                                                                  (*(longlong *)(puVar11 + 0xc) +
                                                                  0x36) & 0xfff8);
                                                    uStack_468 = 0;
                                                    uStack_458 = 0;
                                                    if (WdfClientVersionHigherThanFramework == '\0')
                                                    {
                                                      local_480 = 0x30;
                                                    }
                                                    else if (WdfStructureCount < 0x2e) {
                                                      local_480 = 0xffffffff;
                                                    }
                                                    else {
                                                      local_480 = (ulonglong)
                                                                  *(uint *)(WdfStructures + 0x168);
                                                    }
                                                    puStack_478 = &local_378;
                                                    local_470 = &
                                                  GUID_VPCI_INTERNAL_INTERFACE_STANDARD;
                                                  local_460 = 0;
                                                  puStack_370 = puVar11;
                                                  uVar7 = (**(code **)(WdfFunctions_01033 + 0x720))
                                                                    (WdfDriverGlobals,local_4a8,
                                                                     &local_480);
                                                  if ((int)uVar7 < 0) {
                                                    if ((undefined **)WPP_RECORDER_INITIALIZED ==
                                                        &WPP_RECORDER_INITIALIZED) {
                                                      return uVar7;
                                                    }
                                                    uVar18 = 0x48;
                                                  }
                                                  else {
                                                    local_288 = _guard_check_icall;
                                                    local_298._0_4_ = 0x10048;
                                                    local_280 = _guard_check_icall;
                                                    local_278 = VpciSetTableEntry;
                                                    local_270 = VpciMaskTableEntry;
                                                    local_268 = VpciUnmaskTableEntry;
                                                    local_258 = VpciGetTableSize;
                                                    local_260 = VpciGetTableEntry;
                                                    uStack_468 = 0;
                                                    uStack_458 = 0;
                                                    if (WdfClientVersionHigherThanFramework == '\0')
                                                    {
                                                      local_480 = 0x30;
                                                    }
                                                    else if (WdfStructureCount < 0x2e) {
                                                      local_480 = 0xffffffff;
                                                    }
                                                    else {
                                                      local_480 = (ulonglong)
                                                                  *(uint *)(WdfStructures + 0x168);
                                                    }
                                                    puStack_478 = &local_298;
                                                    local_470 = &GUID_MSIX_TABLE_CONFIG_INTERFACE;
                                                    local_460 = 0;
                                                    local_290 = puVar11;
                                                    uVar7 = (**(code **)(WdfFunctions_01033 + 0x720)
                                                            )(WdfDriverGlobals,local_4a8,&local_480)
                                                    ;
                                                    if ((int)uVar7 < 0) {
                                                      if ((undefined **)WPP_RECORDER_INITIALIZED ==
                                                          &WPP_RECORDER_INITIALIZED) {
                                                        return uVar7;
                                                      }
                                                      uVar18 = 0x49;
                                                    }
                                                    else {
                                                      local_340 = _guard_check_icall;
                                                      local_350 = CONCAT44(local_350._4_4_,0x10028);
                                                      pcStack_338 = _guard_check_icall;
                                                      local_330 = VpciGetLocationStrings;
                                                      uStack_468 = 0;
                                                      uStack_458 = 0;
                                                      if (WdfClientVersionHigherThanFramework ==
                                                          '\0') {
                                                        local_480 = 0x30;
                                                      }
                                                      else if (WdfStructureCount < 0x2e) {
                                                        local_480 = 0xffffffff;
                                                      }
                                                      else {
                                                        local_480 = (ulonglong)
                                                                    *(uint *)(WdfStructures + 0x168)
                                                        ;
                                                      }
                                                      puStack_478 = &local_350;
                                                      local_470 = &GUID_PNP_LOCATION_INTERFACE;
                                                      local_460 = 0;
                                                      puStack_348 = puVar11;
                                                      uVar7 = (**(code **)(WdfFunctions_01033 +
                                                                          0x720))(WdfDriverGlobals,
                                                                                  local_4a8,
                                                                                  &local_480);
                                                      if ((int)uVar7 < 0) {
                                                        if ((undefined **)WPP_RECORDER_INITIALIZED
                                                            == &WPP_RECORDER_INITIALIZED) {
                                                          return uVar7;
                                                        }
                                                        uVar18 = 0x4a;
                                                      }
                                                      else {
                                                        uVar10 = PdoCreatePacket((longlong)puVar11,0
                                                                                 ,(longlong *)
                                                                                  (puVar11 + 0x3e));
                                                        uVar7 = (uint)uVar10;
                                                        if ((int)uVar7 < 0) {
                                                          if ((undefined **)WPP_RECORDER_INITIALIZED
                                                              == &WPP_RECORDER_INITIALIZED) {
                                                            return uVar7;
                                                          }
                                                          uVar18 = 0x4b;
                                                        }
                                                        else {
                                                          uVar10 = PdoCreatePacket((longlong)puVar11
                                                                                   ,0x9ae8,(longlong
                                                                                            *)(
                                                  puVar11 + 0x40));
                                                  uVar7 = (uint)uVar10;
                                                  if ((int)uVar7 < 0) {
                                                    if ((undefined **)WPP_RECORDER_INITIALIZED ==
                                                        &WPP_RECORDER_INITIALIZED) {
                                                      return uVar7;
                                                    }
                                                    uVar18 = 0x4c;
                                                  }
                                                  else {
                                                    pcStack_448 = (code *)0x0;
                                                    local_440 = (code *)0x0;
                                                    if (WdfClientVersionHigherThanFramework == '\0')
                                                    {
                                                      local_450 = 0x38;
                                                    }
                                                    else if (WdfStructureCount < 0x27) {
                                                      local_450 = 0xffffffff;
                                                    }
                                                    else {
                                                      local_450 = (ulonglong)
                                                                  *(uint *)(WdfStructures + 0x130);
                                                    }
                                                    local_420 = 
                                                  PTR__WDF_VPCI_PDO_PACKET_CONTEXT_TYPE_INFO_140010068
                                                  ;
                                                  local_430 = local_4a8;
                                                  uStack_438 = 0x100000001;
                                                  uStack_428 = 0x9ae8;
                                                  uVar7 = (**(code **)(WdfFunctions_01033 + 0x678))
                                                                    (WdfDriverGlobals,&local_450,
                                                                     &local_418);
                                                  if ((int)uVar7 < 0) {
                                                    if ((undefined **)WPP_RECORDER_INITIALIZED ==
                                                        &WPP_RECORDER_INITIALIZED) {
                                                      return uVar7;
                                                    }
                                                    uVar18 = 0x4d;
                                                  }
                                                  else {
                                                    _Dst = (void *)(**(code **)(WdfFunctions_01033 +
                                                                               0x650))(
                                                  WdfDriverGlobals,local_418,
                                                  PTR__WDF_VPCI_PDO_PACKET_CONTEXT_TYPE_INFO_140010068
                                                  );
                                                  *(void **)(puVar11 + 0x44) = _Dst;
                                                  RtlSetVolatileMemory(_Dst,0,0x9ae8);
                                                  *(undefined8 *)(puVar11 + 0x42) = local_418;
                                                  uVar10 = PdoCreatePacket((longlong)puVar11,0,
                                                                           (longlong *)
                                                                           (puVar11 + 0x60));
                                                  uVar7 = (uint)uVar10;
                                                  if (-1 < (int)uVar7) {
                                                    *(longlong *)(puVar11 + 0x62) =
                                                         *(longlong *)(puVar11 + 0x60);
                                                    puVar12 = VpciCompletionBufferCreate(16000);
                                                    if (puVar12 == (uint *)0x0) {
                                                      if ((undefined **)WPP_RECORDER_INITIALIZED !=
                                                          &WPP_RECORDER_INITIALIZED) {
                                                        uVar18 = 0x4f;
LAB_14001c03e:
                                                        WPP_RECORDER_SF_q(*(undefined8 *)
                                                                           (WPP_GLOBAL_Control +
                                                                           0x40),2,1,uVar18,
                                                                          &
                                                  WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,
                                                  uVar19);
                                                  }
                                                  }
                                                  else {
                                                    *(uint **)(puVar11 + 0x3c) = puVar12;
                                                    puVar12 = VpciCompletionBufferCreate(0x2720);
                                                    if (puVar12 != (uint *)0x0) {
                                                      *(uint **)(puVar11 + 0x3a) = puVar12;
                                                      memset(&local_3e8,0,0x60);
                                                      if (WdfClientVersionHigherThanFramework ==
                                                          '\0') {
                                                        local_3e8 = 0x60;
                                                      }
                                                      else if (WdfStructureCount < 0x22) {
                                                        local_3e8 = 0xffffffff;
                                                      }
                                                      else {
                                                        local_3e8 = *(undefined4 *)
                                                                     (WdfStructures + 0x108);
                                                      }
                                                      local_3e4 = 3;
                                                      uVar7 = (**(code **)(WdfFunctions_01033 +
                                                                          0x4c0))(WdfDriverGlobals,
                                                                                  local_4a8,
                                                                                  &local_3e8,0);
                                                      if (-1 < (int)uVar7) {
                                                        lVar13 = IoAllocateIrp(*(undefined1 *)
                                                                                (lVar14 + 0x4c),0);
                                                        *(longlong *)(puVar11 + 0x66) = lVar13;
                                                        if (lVar13 == 0) {
                                                          if ((undefined **)WPP_RECORDER_INITIALIZED
                                                              == &WPP_RECORDER_INITIALIZED) {
                                                            return 0xc000009a;
                                                          }
                                                          uVar18 = 0x52;
                                                        }
                                                        else {
                                                          pcStack_448 = (code *)0x0;
                                                          local_420 = (undefined *)0x0;
                                                          local_440 = (code *)0x0;
                                                          uStack_428 = 0;
                                                          if (WdfClientVersionHigherThanFramework ==
                                                              '\0') {
                                                            local_450 = 0x38;
                                                          }
                                                          else if (WdfStructureCount < 0x27) {
                                                            local_450 = 0xffffffff;
                                                          }
                                                          else {
                                                            local_450 = (ulonglong)
                                                                        *(uint *)(WdfStructures +
                                                                                 0x130);
                                                          }
                                                          local_430 = local_4a8;
                                                          uStack_438 = 0x100000001;
                                                          uVar7 = (**(code **)(WdfFunctions_01033 +
                                                                              0x9c0))(
                                                  WdfDriverGlobals,&local_450,puVar11 + 8);
                                                  if ((int)uVar7 < 0) {
                                                    if ((undefined **)WPP_RECORDER_INITIALIZED ==
                                                        &WPP_RECORDER_INITIALIZED) {
                                                      return uVar7;
                                                    }
                                                    uVar18 = 0x53;
                                                    goto LAB_14001b48b;
                                                  }
                                                  lVar13 = IoAllocateWorkItem(lVar14);
                                                  *(longlong *)(puVar11 + 0x76) = lVar13;
                                                  if (lVar13 == 0) {
                                                    if ((undefined **)WPP_RECORDER_INITIALIZED ==
                                                        &WPP_RECORDER_INITIALIZED) {
                                                      return 0xc000009a;
                                                    }
                                                    uVar18 = 0x54;
                                                  }
                                                  else {
                                                    lVar13 = IoAllocateWorkItem(lVar14);
                                                    *(longlong *)(puVar11 + 0x84) = lVar13;
                                                    if (lVar13 == 0) {
                                                      if ((undefined **)WPP_RECORDER_INITIALIZED ==
                                                          &WPP_RECORDER_INITIALIZED) {
                                                        return 0xc000009a;
                                                      }
                                                      uVar18 = 0x55;
                                                    }
                                                    else {
                                                      lVar14 = IoAllocateWorkItem(lVar14);
                                                      *(longlong *)(puVar11 + 0x78) = lVar14;
                                                      if (lVar14 != 0) {
                                                        KeInitializeSpinLock(puVar11 + 100);
                                                        KeInitializeEvent(puVar11 + 0x68,1,1);
                                                        KeInitializeEvent(puVar11 + 0x6e,0,1);
                                                        puVar11[10] = 10;
                                                        KeQueryNodeActiveAffinity
                                                                  (0,0,(longlong)puVar11 + 0x132);
                                                        uVar16 = 1;
                                                        sVar5 = KeQueryHighestNodeNumber();
                                                        if (sVar5 != 0) {
                                                          do {
                                                            local_4b0 = 0;
                                                            KeQueryNodeActiveAffinity
                                                                      (uVar16,0,&local_4b0);
                                                            if (*(ushort *)
                                                                 ((longlong)puVar11 + 0x132) <
                                                                local_4b0) {
                                                              *(ushort *)((longlong)puVar11 + 0x132)
                                                                   = local_4b0;
                                                            }
                                                            uVar16 = uVar16 + 1;
                                                            uVar6 = KeQueryHighestNodeNumber();
                                                          } while (uVar16 <= uVar6);
                                                        }
                                                        return 0;
                                                      }
                                                      if ((undefined **)WPP_RECORDER_INITIALIZED ==
                                                          &WPP_RECORDER_INITIALIZED) {
                                                        return 0xc000009a;
                                                      }
                                                      uVar18 = 0x56;
                                                    }
                                                  }
                                                  }
                                                  uVar7 = 0xc000009a;
                                                  WPP_RECORDER_SF_qd(*(undefined8 *)
                                                                      (WPP_GLOBAL_Control + 0x40),2,
                                                                     1,uVar18,&
                                                  WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,
                                                  uVar19,0x9a);
                                                  goto LAB_14001c3f8;
                                                  }
                                                  if ((undefined **)WPP_RECORDER_INITIALIZED ==
                                                      &WPP_RECORDER_INITIALIZED) {
                                                    return uVar7;
                                                  }
                                                  uVar18 = 0x51;
                                                  goto LAB_14001b48b;
                                                  }
                                                  if ((undefined **)WPP_RECORDER_INITIALIZED !=
                                                      &WPP_RECORDER_INITIALIZED) {
                                                    uVar18 = 0x50;
                                                    goto LAB_14001c03e;
                                                  }
                                                  }
                                                  uVar7 = 0xc000009a;
                                                  goto LAB_14001c3f8;
                                                  }
                                                  if ((undefined **)WPP_RECORDER_INITIALIZED ==
                                                      &WPP_RECORDER_INITIALIZED) {
                                                    return uVar7;
                                                  }
                                                  uVar18 = 0x4e;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
LAB_14001b48b:
                                      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                                                         2,1,uVar18,
                                                         &
                                                  WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,
                                                  uVar19,(char)uVar7);
                                      goto LAB_14001c3f8;
                                    }
                                    if ((undefined **)WPP_RECORDER_INITIALIZED ==
                                        &WPP_RECORDER_INITIALIZED) {
                                      return uVar7;
                                    }
                                    uVar18 = 0x3b;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else {
            uVar10 = RtlUnicodeStringPrintf
                               (local_4a0,L"%wZ\\VEN_%04X&DEV_%04X&REV_%02X",&local_490,
                                (ulonglong)*(ushort *)(param_2 + 0xc));
            uVar7 = (uint)uVar10;
            if ((int)uVar7 < 0) goto LAB_14001c3f8;
            uVar7 = (**(code **)(WdfFunctions_01033 + 0x6b8))(WdfDriverGlobals,local_4b8,local_4a0);
            if ((int)uVar7 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                return uVar7;
              }
              uVar18 = 0x2c;
            }
            else {
              uVar10 = RtlUnicodeStringPrintf
                                 (local_4a0,L"%wZ\\VEN_%04X&DEV_%04X",&local_490,
                                  (ulonglong)*(ushort *)(param_2 + 0xc));
              uVar7 = (uint)uVar10;
              if ((int)uVar7 < 0) goto LAB_14001c3f8;
              uVar7 = (**(code **)(WdfFunctions_01033 + 0x6b8))
                                (WdfDriverGlobals,local_4b8,local_4a0);
              if (-1 < (int)uVar7) goto LAB_14001aa92;
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                return uVar7;
              }
              uVar18 = 0x2d;
            }
          }
        }
      }
    }
  }
LAB_14001a6a7:
  WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar18,
                    &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)uVar7);
LAB_14001c3f8:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x57,
                      &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)uVar7);
  }
  return uVar7;
}



===== PdoCreatePacket @ 14001c458 =====

undefined8 PdoCreatePacket(longlong param_1,int param_2,longlong *param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong *plVar3;
  
  lVar1 = VpciPacketCreate(*(undefined8 *)(*(longlong *)(param_1 + 0x30) + 0x28),param_2);
  if (lVar1 == 0) {
    *param_3 = 0;
    uVar2 = 0xc000009a;
  }
  else {
    plVar3 = (longlong *)VmbPacketGetPointer(lVar1);
    *plVar3 = param_1;
    uVar2 = 0;
    *param_3 = lVar1;
  }
  return uVar2;
}



===== PdoD0Exit @ 14001c4c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 PdoD0Exit(undefined8 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  ulonglong uVar3;
  undefined1 uVar4;
  
  puVar2 = (undefined4 *)
           (**(code **)(WdfFunctions_01033 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8);
  puVar2[0x38] = param_2;
  uVar3 = Feature_VpciVscBootDiskHibernation__private_IsEnabledDeviceUsageNoInline();
  uVar4 = SUB81(puVar2,0);
  if ((((int)uVar3 == 0) || (param_2 != 6)) || (puVar2[0xc6] == 0)) {
    PdoDisableInterrupts(puVar2);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0xa2,
                         &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar4,
                         (char)SystemReserved1[0xf]);
    }
    puVar2[0x74] = 0x103;
    KeClearEvent(puVar2 + 0x6e);
    PdoSendPowerMessage(puVar2);
    KeWaitForSingleObject(puVar2 + 0x6e,0,0,0,0);
    uVar1 = puVar2[0x74];
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0xa3,
                         &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar4,(char)uVar1);
    }
    PdoFreeMsixMetadata((longlong)puVar2);
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0xa1,
                         &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar4,
                         (char)SystemReserved1[0xf]);
    }
    *(undefined1 *)(puVar2 + 0xd0) = 1;
    uVar1 = 0;
  }
  return uVar1;
}



===== PdoDeviceEject @ 14001c670 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PdoDeviceEject(undefined8 param_1)

{
  int iVar1;
  int *piVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  
  piVar2 = (int *)(**(code **)(WdfFunctions_01033 + 0x650))
                            (WdfDriverGlobals,param_1,PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8)
  ;
  uVar4 = SUB81(piVar2,0);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0xb2,
                       &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar4,
                       (char)SystemReserved1[0xf]);
  }
  piVar2[0x74] = 0;
  uVar3 = PdoRunStateMachine(piVar2,1);
  if (((char)uVar3 == '\0') && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
     ) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,0xb3,
                      &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar4);
  }
  KeWaitForSingleObject(piVar2 + 0x6e,0,0,0,0);
  iVar1 = piVar2[0x74];
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0xb4,
                       &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar4,(char)iVar1);
  }
  return iVar1;
}



===== PdoDeviceUsageNotificationEx @ 14001c7c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong PdoDeviceUsageNotificationEx(undefined8 param_1,uint param_2,char param_3)

{
  int iVar1;
  uint *puVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined8 uVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined *puVar8;
  undefined2 uVar9;
  uint *puVar10;
  int local_res20 [2];
  undefined8 in_stack_ffffffffffffffa8;
  undefined1 uVar11;
  undefined1 uVar12;
  
  local_res20[0] = 0;
  puVar8 = PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8;
  puVar2 = (uint *)(**(code **)(WdfFunctions_01033 + 0x650))
                             (WdfDriverGlobals,param_1,PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8
                             );
  uVar5 = CONCAT71((int7)((ulonglong)puVar8 >> 8),param_3);
  uVar7 = (ulonglong)param_2;
  puVar10 = puVar2 + 0xc4;
  uVar3 = VpciUpdateDeviceUsageNotificationCount((longlong)puVar10,param_2,param_3,local_res20);
  uVar11 = SUB81(puVar2,0);
  uVar12 = (undefined1)param_2;
  if ((int)uVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,2,0xda,
                          &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar11,uVar12,(char)uVar3
                         );
    }
    return uVar3 & 0xffffffff;
  }
  if (param_3 == '\x01') {
    if ((local_res20[0] == 1) &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar9 = 0xdb;
LAB_14001c8c1:
      uVar6 = *puVar2 & 0x1f;
      WPP_RECORDER_SF_qDDdq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),(ulonglong)uVar6,uVar5,uVar9,
                 in_stack_ffffffffffffffa8,uVar11,(char)uVar6,(byte)(*puVar2 >> 5) & 7,uVar12,
                 (char)SystemReserved1[0xf]);
    }
  }
  else if (((param_3 == '\0') && (local_res20[0] == 0)) &&
          ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    uVar9 = 0xdc;
    goto LAB_14001c8c1;
  }
  iVar1 = local_res20[0];
  uVar3 = Feature_VpciVscBootDiskHibernation__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    return 0;
  }
  if (param_2 == 1) {
LAB_14001c92c:
    lVar4 = (**(code **)(WdfFunctions_01033 + 0xf8))(WdfDriverGlobals,*(undefined8 *)(puVar2 + 2));
    if (param_3 == '\x01') {
      if ((iVar1 == 1) && ((*(uint *)(lVar4 + 0x30) & 0x2000) != 0)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qDDd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xdf,
                     &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar11,(byte)*puVar2 & 0x1f,
                     (byte)(*puVar2 >> 5) & 7,uVar12);
        }
        *(uint *)(lVar4 + 0x30) = *(uint *)(lVar4 + 0x30) & 0xffffdfff;
      }
    }
    else if ((param_3 == '\0') && (iVar1 == 0)) {
      uVar6 = 0;
      do {
        if (*puVar10 != 0) {
          return 0;
        }
        uVar6 = uVar6 + 1;
        puVar10 = puVar10 + 1;
      } while (uVar6 < 4);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xe0,
                            &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar11,
                            (byte)*puVar2 & 0x1f,(byte)(*puVar2 >> 5) & 7);
      }
      *(uint *)(lVar4 + 0x30) = *(uint *)(lVar4 + 0x30) | 0x2000;
    }
    return 0;
  }
  if (param_2 != 2) {
    if (param_2 != 3) {
      return 0;
    }
    goto LAB_14001c92c;
  }
  if (param_3 == '\x01') {
    if ((iVar1 != 1) || (uVar6 = PdoEnableCrashVpci((longlong)puVar2), -1 < (int)uVar6))
    goto LAB_14001c92c;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001ca24;
    uVar9 = 0xdd;
  }
  else {
    if ((param_3 != '\0') || (iVar1 != 0)) goto LAB_14001c92c;
    uVar5 = PdoDisableCrashVpci((longlong)puVar2);
    uVar6 = (uint)uVar5;
    if (-1 < (int)uVar6) goto LAB_14001c92c;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001ca24;
    uVar9 = 0xde;
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar9,
                     &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar11,(char)uVar6);
LAB_14001ca24:
  return (ulonglong)uVar6;
}



===== PdoDisableCrashVpci @ 14001caf0 =====

undefined8 PdoDisableCrashVpci(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  if (*(longlong *)(param_1 + 0x330) == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xe7,
                        &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_1);
    }
    uVar2 = 0xc0000001;
  }
  else {
    KeWaitForSingleObject(&VpciGlobalLock,0,0,0,0);
    PoUnregisterSstNotificationHandler(*(undefined8 *)(param_1 + 0x330));
    *(undefined8 *)(param_1 + 0x330) = 0;
    if (*(longlong *)(param_1 + 0x338) != 0) {
      lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x338) + 0x10);
      if (lVar1 != 0) {
        if (*(longlong *)(lVar1 + 0x10) != 0) {
          ExFreePoolWithTag(*(longlong *)(lVar1 + 0x10),0x69637056);
        }
        ExFreePoolWithTag(lVar1,0x69637056);
      }
      ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x338),0x69637056);
      *(undefined8 *)(param_1 + 0x338) = 0;
    }
    KeSetEvent(&VpciGlobalLock,0,0);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xe8,
                        &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_1);
    }
    uVar2 = 0;
  }
  return uVar2;
}



===== PdoEnableCrashVpci @ 14001cc5c =====

int PdoEnableCrashVpci(longlong param_1)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  uint uVar6;
  undefined2 uVar7;
  undefined1 uVar8;
  
  uVar8 = (undefined1)param_1;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xe1,
                       &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar8,
                       (char)SystemReserved1[0xf]);
  }
  KeWaitForSingleObject(&VpciGlobalLock,0,0,0,0);
  plVar1 = (longlong *)(param_1 + 0x330);
  if ((*plVar1 == 0) && (*(longlong *)(param_1 + 0x338) == 0)) {
    lVar3 = ExAllocatePool2(0x40,0x9ae8,0x69637056);
    if (lVar3 == 0) {
      iVar2 = -0x3fffff66;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xe3,
                           &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar8,0x9a);
      }
    }
    else {
      plVar4 = (longlong *)ExAllocatePool2(0x40,0x18,0x69637056);
      if (plVar4 == (longlong *)0x0) {
        iVar2 = -0x3fffff66;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar7 = 0xe4;
LAB_14001cda9:
          iVar2 = -0x3fffff66;
          uVar6 = 1;
LAB_14001ce65:
          WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar6,uVar7,
                             &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar8,(char)iVar2);
        }
      }
      else {
        lVar5 = ExAllocatePool2(0x40,0x18,0x69637056);
        *(longlong *)(param_1 + 0x338) = lVar5;
        if (lVar5 != 0) {
          *plVar4 = param_1;
          plVar4[2] = lVar3;
          *(undefined4 *)(plVar4 + 1) = 0x9ae8;
          *(longlong **)(*(longlong *)(param_1 + 0x338) + 0x10) = plVar4;
          **(undefined4 **)(param_1 + 0x338) = 1;
          *(code **)(*(longlong *)(param_1 + 0x338) + 8) = CrashVpciNotificationHandler;
          iVar2 = PoRegisterSstNotificationHandler(*(undefined8 *)(param_1 + 0x338),plVar1);
          if (-1 < iVar2) goto LAB_14001cf22;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14001ce83;
          uVar6 = 2;
          uVar7 = 0xe6;
          goto LAB_14001ce65;
        }
        iVar2 = -0x3fffff66;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar7 = 0xe5;
          goto LAB_14001cda9;
        }
      }
LAB_14001ce83:
      ExFreePoolWithTag(lVar3,0x69637056);
      if (plVar4 != (longlong *)0x0) {
        ExFreePoolWithTag(plVar4,0x69637056);
      }
    }
  }
  else {
    iVar2 = -0x3fffffff;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0xe2,
                        &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar8);
    }
  }
  if (*(longlong *)(param_1 + 0x338) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x338),0x69637056);
    *(undefined8 *)(param_1 + 0x338) = 0;
  }
  if (*plVar1 != 0) {
    PoUnregisterSstNotificationHandler();
    *plVar1 = 0;
  }
LAB_14001cf22:
  KeSetEvent(&VpciGlobalLock,0,0);
  return iVar2;
}



===== PdoFormatAssignedResourcesMessage @ 14001cf64 =====

int * PdoFormatAssignedResourcesMessage(int *param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x44);
  piVar1[1] = *param_1;
  if (*(uint *)(*(longlong *)(param_1 + 0xc) + 0x18) < 0x10004) {
    *piVar1 = (-(uint)(*(uint *)(*(longlong *)(param_1 + 0xc) + 0x18) < 0x10002) & 0xfffffffa) +
              0x42490016;
  }
  else {
    *piVar1 = 0x4249001a;
  }
  return piVar1;
}



===== PdoFreePnpIrp @ 14001cfa8 =====

void PdoFreePnpIrp(longlong param_1)

{
  IoFreeIrp(*(undefined8 *)(param_1 + 0x200));
  *(undefined8 *)(param_1 + 0x200) = 0;
  ObfDereferenceObject(*(undefined8 *)(param_1 + 0x208));
  *(undefined8 *)(param_1 + 0x208) = 0;
  return;
}



===== PdoGetLogicalDeviceId @ 14001cff4 =====

uint PdoGetLogicalDeviceId(uint *param_1)

{
  return (uint)*(ushort *)(*(longlong *)(param_1 + 0xc) + 0x34) << 0x10 |
         *(ushort *)(*(longlong *)(param_1 + 0xc) + 0x36) & 0xfff8 | *param_1 >> 5 & 7;
}



===== PdoGetMessageCount @ 14001d024 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PdoGetMessageCount(undefined4 *param_1,uint *param_2,undefined1 *param_3)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined1 auStackY_a8 [32];
  undefined8 uVar5;
  undefined4 uVar6;
  uint local_68;
  uint local_64;
  longlong local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined4 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_64 = 0;
  local_68 = 0;
  local_60 = 0;
  *param_3 = 0;
  *param_2 = 0;
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_58 = 0;
  uStack_50 = 0;
  uVar3 = (**(code **)(WdfFunctions_01033 + 0x660))(WdfDriverGlobals,param_1);
  uVar4 = 0x20019;
  uVar5 = 0;
  iVar1 = (**(code **)(WdfFunctions_01033 + 0x180))(WdfDriverGlobals,uVar3,1);
  if (-1 < iVar1) {
    uVar6 = (undefined4)((ulonglong)uVar5 >> 0x20);
    if (*(byte *)((longlong)param_1 + 0x12e) == 0) {
      if (*(byte *)((longlong)param_1 + 0x12d) != 0) {
        uVar4 = (ulonglong)(*(byte *)((longlong)param_1 + 0x12d) + 2);
        uVar5 = CONCAT44(uVar6,2);
        FdoReadConfig(*(longlong *)(param_1 + 0xc),*param_1,(undefined4 *)((longlong)&local_58 + 2),
                      uVar4,2);
        uVar2 = 1 << ((byte)(local_58._2_2_ >> 1) & 7);
        *param_2 = uVar2;
        if (0x10 < uVar2) {
          *param_2 = 0x10;
        }
        *param_3 = 1;
      }
    }
    else {
      uVar4 = (ulonglong)(*(byte *)((longlong)param_1 + 0x12e) + 2);
      uVar5 = CONCAT44(uVar6,2);
      FdoReadConfig(*(longlong *)(param_1 + 0xc),*param_1,(undefined4 *)((longlong)&local_40 + 2),
                    uVar4,2);
      *param_3 = 0;
      *param_2 = (local_40._2_2_ & 0x7ff) + 1;
    }
    uVar2 = PdoGetRegistryValue(L"MessageNumberLimit",
                                L"Interrupt Management\\MessageSignaledInterruptProperties",local_60
                                ,uVar4,uVar5,&local_64,&local_68);
    if (-1 < (int)uVar2) {
      if (local_68 < 4) {
        iVar1 = -0x3fffffdd;
        goto LAB_14001d198;
      }
      if (local_64 < *param_2) {
        *param_2 = local_64;
      }
    }
    iVar1 = 0;
  }
LAB_14001d198:
  if (local_60 != 0) {
    (**(code **)(WdfFunctions_01033 + 0x738))(WdfDriverGlobals);
  }
  return iVar1;
}



===== PdoGetRegistryValue @ 14001d1e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint PdoGetRegistryValue(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        ,undefined8 param_5,undefined8 param_6,undefined8 param_7)

{
  uint uVar1;
  int local_res20 [2];
  longlong local_38 [6];
  
  local_res20[0] = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  RtlInitUnicodeString(local_38 + 1);
  uVar1 = (**(code **)(WdfFunctions_01033 + 0x728))
                    (WdfDriverGlobals,param_3,local_38 + 1,0x20019,0,local_38);
  if (-1 < (int)uVar1) {
    RtlInitUnicodeString(local_38 + 3,param_1);
    uVar1 = (**(code **)(WdfFunctions_01033 + 0x758))
                      (WdfDriverGlobals,local_38[0],local_38 + 3,4,param_6,param_7,local_res20);
    if (-1 < (int)uVar1) {
      uVar1 = -(uint)(local_res20[0] != 4) & 0xc0000024;
    }
  }
  if (local_38[0] != 0) {
    (**(code **)(WdfFunctions_01033 + 0x738))(WdfDriverGlobals);
  }
  return uVar1;
}



===== PdoPowerWorkItem @ 14001d310 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdoPowerWorkItem(undefined8 param_1,int *param_2,undefined8 param_3)

{
  char *pcVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,0xbb,
                       &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_2,
                       (char)param_2[10]);
  }
  PdoRunStateMachine(param_2,3);
  lVar3 = *(longlong *)(param_2 + 0x7a);
  pcVar1 = (char *)(lVar3 + 0x43);
  *pcVar1 = *pcVar1 + '\x01';
  plVar2 = (longlong *)(lVar3 + 0xb8);
  *plVar2 = *plVar2 + 0x48;
  uVar4 = (**(code **)(WdfFunctions_01033 + 0x660))(WdfDriverGlobals,param_2);
  (**(code **)(WdfFunctions_01033 + 0x110))(WdfDriverGlobals,uVar4,*(undefined8 *)(param_2 + 0x7a));
  return;
}



===== PdoPrepareHardware @ 14001d3d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PdoPrepareHardware(undefined8 param_1,undefined8 param_2,undefined1 param_3)

{
  undefined4 *puVar1;
  ulonglong *puVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  bool bVar8;
  bool bVar9;
  byte bVar10;
  byte bVar11;
  uint uVar12;
  int iVar13;
  longlong lVar14;
  ulonglong uVar15;
  undefined8 uVar16;
  char *pcVar17;
  longlong lVar18;
  byte *pbVar19;
  int *piVar20;
  ulonglong uVar21;
  ushort *puVar22;
  undefined1 *puVar23;
  uint uVar24;
  uint uVar25;
  uint *puVar26;
  int iVar27;
  uint uVar28;
  undefined2 uVar29;
  undefined1 uVar30;
  ulonglong uVar31;
  uint *puVar32;
  undefined1 *puVar33;
  undefined1 *puVar34;
  undefined *in_stack_ffffffffffffff58;
  uint local_88;
  undefined4 local_78;
  uint local_74;
  uint *local_70;
  ulonglong local_68;
  uint local_60;
  uint local_5c;
  ulonglong local_58;
  ulonglong local_50;
  undefined *puStack_48;
  ulonglong local_40;
  
  local_40 = local_40 & 0xffffffff00000000;
  local_58 = 0;
  local_74 = 0;
  local_78 = 0;
  local_60 = 0;
  local_50 = 0;
  puStack_48 = (undefined *)0x0;
  uVar16 = param_1;
  lVar14 = (**(code **)(WdfFunctions_01033 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8);
  local_70 = (uint *)0x0;
  local_68 = 0;
  uVar30 = (undefined1)lVar14;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    in_stack_ffffffffffffff58 = &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids;
    WPP_RECORDER_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar16,2,0x7a,
                        &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar30,(char)param_2,
                        param_3);
  }
  if (*(char *)(lVar14 + 0x21d) == '\0') {
    uVar15 = PdoSaveRawAndTranslatedResources(lVar14);
    iVar13 = (int)uVar15;
    if (iVar13 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x7b,
                           &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar30,(char)uVar15);
      }
      goto LAB_14001df39;
    }
  }
  uVar28 = 1;
  if (*(char *)(lVar14 + 0x342) != '\0') {
    uVar28 = 1;
    uVar12 = HviGetPartitionIsolationType();
    if (uVar12 - 2 <= uVar28) {
      local_68 = HviGetSharedGpaBoundary();
    }
  }
  uVar25 = 0;
  local_5c = 0;
  iVar27 = 0;
  uVar24 = 0;
  uVar12 = *(uint *)(*(longlong *)(lVar14 + 0x1f0) + 0x10);
  puVar32 = (uint *)0x0;
  if (uVar12 == 0) {
LAB_14001d63e:
    uVar28 = (**(code **)(WdfFunctions_01033 + 0x980))(WdfDriverGlobals);
    *(undefined4 *)(lVar14 + 0x1f8) = 0;
    uVar12 = 0;
    if (uVar28 != 0) {
      do {
        pcVar17 = (char *)(**(code **)(WdfFunctions_01033 + 0x988))(WdfDriverGlobals,param_2,uVar12)
        ;
        if ((*pcVar17 == '\x02') && ((pcVar17[2] & 2U) != 0)) {
          *(int *)(lVar14 + 0x1f8) = *(int *)(lVar14 + 0x1f8) + 1;
        }
        uVar12 = uVar12 + 1;
      } while (uVar12 < uVar28);
    }
    lVar4 = *(longlong *)(lVar14 + 0x110);
    uVar12 = (iVar27 - *(int *)(lVar14 + 0x1f8)) + uVar28;
    uVar15 = Feature_VpciVscRelaxedInterruptLimit__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar15 == 0) {
      if (0x1ee < uVar12) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar29 = 0x80;
LAB_14001d71a:
          uVar25 = uVar12;
LAB_14001d71e:
          WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,uVar29,
                             &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar30,(char)uVar25);
        }
        goto LAB_14001d748;
      }
    }
    else if (0x1ee < uVar12) {
      if (*(uint *)(*(longlong *)(lVar14 + 0x30) + 0x18) < 0x10006) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar29 = 0x7e;
          goto LAB_14001d71a;
        }
      }
      else {
        if (*(longlong *)(lVar14 + 0x120) != 0) {
          ExFreePoolWithTag(*(longlong *)(lVar14 + 0x120),0x69637056);
          *(undefined8 *)(lVar14 + 0x120) = 0;
        }
        uVar25 = uVar12 - 0x1ee;
        lVar18 = ExAllocatePool2(0x40,(ulonglong)uVar25 * 0x50,0x69637056);
        *(longlong *)(lVar14 + 0x120) = lVar18;
        if (lVar18 != 0) goto LAB_14001d7c7;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar29 = 0x7f;
          goto LAB_14001d71e;
        }
      }
LAB_14001d748:
      iVar13 = -0x3fffff66;
      goto LAB_14001df23;
    }
LAB_14001d7c7:
    uVar25 = *(uint *)(*(longlong *)(lVar14 + 0x30) + 0x18);
    if (uVar12 == 0) {
      iVar13 = (-(uint)(uVar25 < 0x10004) & 0xfffffff8) + 0xd8;
    }
    else {
      if (uVar25 < 0x10004) {
        iVar13 = uVar12 * 0x48;
      }
      else {
        iVar13 = uVar12 * 0x50;
      }
      iVar13 = iVar13 + 0x88;
    }
    *(int *)(lVar14 + 0x118) = iVar13;
    local_88 = 0;
    uVar12 = 0;
    if (uVar28 == 0) {
LAB_14001da67:
      uVar15 = (ulonglong)(6 - uVar12);
      puVar23 = (undefined1 *)(lVar4 + ((ulonglong)uVar12 * 5 + 2) * 4);
      puVar33 = puVar23;
      do {
        RtlSetVolatileMemory(puVar33,0,0x14);
        uVar25 = (uint)((ulonglong)in_stack_ffffffffffffff58 >> 0x20);
        puVar33 = puVar33 + 0x14;
        *puVar23 = 0;
        puVar23 = puVar23 + 0x14;
        uVar15 = uVar15 - 1;
      } while (uVar15 != 0);
    }
    else {
      do {
        pbVar19 = (byte *)(**(code **)(WdfFunctions_01033 + 0x988))
                                    (WdfDriverGlobals,param_2,local_88);
        if ((*pbVar19 < 8) && ((0x8bU >> (*pbVar19 & 0x1f) & 1) != 0)) {
          if (uVar12 < 6) {
            piVar20 = (int *)(lVar14 + ((ulonglong)uVar12 + 0x14) * 4);
            do {
              if (*piVar20 != 0) break;
              uVar12 = uVar12 + 1;
              piVar20 = piVar20 + 1;
            } while (uVar12 < 6);
          }
          bVar8 = false;
          bVar9 = bVar8;
          if (uVar12 < 6) {
            uVar5 = *(undefined4 *)(pbVar19 + 4);
            uVar6 = *(undefined4 *)(pbVar19 + 8);
            uVar7 = *(undefined4 *)(pbVar19 + 0xc);
            uVar15 = (ulonglong)uVar12;
            puVar1 = (undefined4 *)(lVar14 + 0x68 + uVar15 * 0x14);
            *puVar1 = *(undefined4 *)pbVar19;
            puVar1[1] = uVar5;
            puVar1[2] = uVar6;
            puVar1[3] = uVar7;
            *(undefined4 *)(lVar14 + 0x78 + uVar15 * 0x14) = *(undefined4 *)(pbVar19 + 0x10);
            if ((*(char *)(lVar14 + 0x342) != '\0') && ((*pbVar19 - 3 & 0xfb) == 0)) {
              puVar2 = (ulonglong *)(lVar14 + 0x6c + uVar15 * 0x14);
              *puVar2 = *puVar2 | local_68;
            }
            uVar25 = *(uint *)(lVar14 + 0x50 + uVar15 * 4);
            if (((uVar25 & 1) == 0) && ((uVar25 & 4) != 0)) {
              bVar9 = true;
            }
            else if ((uVar25 & 1) != 0) goto LAB_14001d8ea;
            if ((uVar25 & 8) != 0) {
              bVar8 = true;
            }
          }
LAB_14001d8ea:
          if (*pbVar19 < 2) {
            if (uVar12 < 6) {
              uVar16 = *(undefined8 *)(pbVar19 + 8);
              uVar15 = (ulonglong)uVar12;
              puVar3 = (undefined8 *)(lVar4 + 8 + uVar15 * 0x14);
              *puVar3 = *(undefined8 *)pbVar19;
              puVar3[1] = uVar16;
              *(undefined4 *)(lVar4 + 0x18 + uVar15 * 0x14) = *(undefined4 *)(pbVar19 + 0x10);
              *(undefined4 *)(lVar14 + 0x38 + uVar15 * 4) = 0;
              if (*(char *)(lVar4 + 8 + uVar15 * 0x14) == '\x01') {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  in_stack_ffffffffffffff58 = &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids;
                  WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,0x81,
                                     &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar30,
                                     (char)param_1);
                }
                *(undefined1 *)(lVar4 + 8 + uVar15 * 0x14) = 0;
              }
              uVar12 = uVar12 + 1;
            }
          }
          else {
            RtlCmDecodeMemIoResource(pbVar19);
            if (*(char *)(lVar14 + 0x342) != '\0') {
              local_58 = local_58 | local_68;
            }
            if (bVar8) {
              local_58 = local_58 | 8;
            }
            if (!bVar9) {
              if (uVar12 < 6) {
                uVar16 = *(undefined8 *)(pbVar19 + 8);
                uVar15 = (ulonglong)uVar12;
                uVar12 = uVar12 + 1;
                puVar3 = (undefined8 *)(lVar4 + 8 + uVar15 * 0x14);
                *puVar3 = *(undefined8 *)pbVar19;
                puVar3[1] = uVar16;
                *(undefined4 *)(lVar4 + 0x18 + uVar15 * 0x14) = *(undefined4 *)(pbVar19 + 0x10);
                *(uint *)(lVar14 + 0x38 + uVar15 * 4) = (uint)local_58;
              }
            }
            else if (uVar12 < 5) {
              uVar15 = (ulonglong)uVar12;
              *(uint *)(lVar14 + 0x38 + uVar15 * 4) = (uint)local_58;
              *(uint *)(lVar14 + 0x38 + uVar15 * 4) = (uint)local_58 | 4;
              *(int *)(lVar14 + 0x38 + (ulonglong)(uVar12 + 1) * 4) = (int)(local_58 >> 0x20);
              uVar16 = *(undefined8 *)(pbVar19 + 8);
              puVar3 = (undefined8 *)(lVar4 + 8 + uVar15 * 0x14);
              *puVar3 = *(undefined8 *)pbVar19;
              puVar3[1] = uVar16;
              *(undefined4 *)(lVar4 + 0x18 + uVar15 * 0x14) = *(undefined4 *)(pbVar19 + 0x10);
              lVar18 = lVar4 + (ulonglong)(uVar12 + 1) * 0x14;
              RtlSetVolatileMemory((void *)(lVar18 + 8),0,0x14);
              *(undefined1 *)(lVar18 + 8) = 0;
              uVar12 = uVar12 + 2;
            }
          }
        }
        uVar25 = (uint)((ulonglong)in_stack_ffffffffffffff58 >> 0x20);
        local_88 = local_88 + 1;
      } while (local_88 < uVar28);
      puVar32 = local_70;
      if (uVar12 < 6) goto LAB_14001da67;
    }
    local_40 = 0;
    if (WdfClientVersionHigherThanFramework == '\0') {
      local_50 = 0x18;
    }
    else if (WdfStructureCount < 0x14) {
      local_50 = 0xffffffff;
    }
    else {
      local_50 = (ulonglong)*(uint *)(WdfStructures + 0x98);
    }
    puStack_48 = &DEVPKEY_Device_Numa_Node;
    if (*(char *)(lVar14 + 0x249) == '\0') {
      iVar13 = (**(code **)(WdfFunctions_01033 + 0xd98))
                         (WdfDriverGlobals,param_1,&local_50,7,(ulonglong)uVar25 << 0x20,0);
      if ((((iVar13 + 0x80000000U & 0x80000000) == 0) && (iVar13 != -0x3fffffcc)) &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,0x83,
                          &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)iVar13);
      }
    }
    else {
      local_60 = (uint)*(ushort *)(lVar14 + 0x24a);
      iVar13 = (**(code **)(WdfFunctions_01033 + 0xd98))(WdfDriverGlobals);
      if (iVar13 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_Dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
        goto LAB_14001df23;
      }
    }
    if (local_5c != 0) {
      uVar28 = *puVar32;
      uVar12 = 0;
      if (uVar28 != 0) {
        puVar26 = puVar32 + 0xc;
        uVar15 = (ulonglong)uVar28;
        uVar25 = uVar12;
        do {
          uVar24 = *puVar26;
          puVar26 = puVar26 + 0x16;
          uVar12 = uVar25 + 1;
          if (-1 < (int)uVar24) {
            uVar12 = uVar25;
          }
          uVar15 = uVar15 - 1;
          uVar25 = uVar12;
        } while (uVar15 != 0);
      }
      if (uVar12 != uVar28) {
        local_70 = (uint *)((ulonglong)local_70 & 0xffffffff00000000);
        uVar28 = 0;
        local_88 = 0;
        uVar15 = 0;
        if (local_5c != 0) {
          do {
            uVar12 = (int)uVar15 + 1;
            local_68 = uVar15 * 0x58;
            if (uVar12 < local_5c) {
              uVar25 = 1;
              while ((uVar21 = (ulonglong)uVar12,
                     *(longlong *)(puVar32 + uVar21 * 0x16 + 8) ==
                     *(longlong *)(puVar32 + uVar15 * 0x16 + 8) &&
                     ((short)puVar32[uVar21 * 0x16 + 10] == (short)puVar32[uVar15 * 0x16 + 10]))) {
                if ((puVar32[uVar21 * 0x16 + 3] != uVar25 + puVar32[uVar15 * 0x16 + 3]) ||
                   ((~uVar25 & puVar32[uVar21 * 0x16 + 3]) != puVar32[uVar15 * 0x16 + 3])) break;
                uVar12 = uVar12 + 1;
                uVar25 = uVar25 + 1;
                if (local_5c <= uVar12) break;
              }
            }
            bVar10 = RtlFindMostSignificantBit(uVar12 - (int)uVar15);
            uVar12 = puVar32[uVar15 * 0x16 + 3];
            bVar11 = 0;
            if (bVar10 != 0xff) {
              bVar11 = bVar10;
            }
            iVar13 = 1 << (bVar11 & 0x1f);
            uVar15 = Feature_VpciVscRelaxedInterruptLimit__private_IsEnabledDeviceUsageNoInline();
            uVar29 = (undefined2)iVar13;
            if ((((int)uVar15 == 0) || (*(uint *)(*(longlong *)(lVar14 + 0x30) + 0x18) < 0x10006))
               || (uVar28 < 0x1ee)) {
              uVar25 = *(uint *)(*(longlong *)(lVar14 + 0x30) + 0x18);
              uVar15 = (ulonglong)uVar28;
              if (0x10003 < uVar25) {
                puVar26 = (uint *)(lVar4 + 0x88 + uVar15 * 0x50);
                goto LAB_14001dd0d;
              }
              puVar26 = (uint *)0x0;
              uVar30 = (undefined1)uVar12;
              if (0x10001 < uVar25) {
                puVar33 = (undefined1 *)(lVar4 + (uVar15 * 9 + 0x11) * 8);
                *puVar33 = uVar30;
                puVar23 = puVar33 + 6;
                *(undefined2 *)(puVar33 + 2) = uVar29;
                goto LAB_14001dd76;
              }
              puVar33 = (undefined1 *)0x0;
              puVar34 = (undefined1 *)(lVar4 + 0x88 + uVar15 * 0x10);
              *puVar34 = uVar30;
              *(undefined2 *)(puVar34 + 2) = uVar29;
              *(undefined4 *)(puVar34 + 4) = 0;
            }
            else {
              puVar26 = (uint *)((ulonglong)(uVar28 - 0x1ee) * 0x50 + *(longlong *)(lVar14 + 0x120))
              ;
LAB_14001dd0d:
              puVar23 = (undefined1 *)((longlong)puVar26 + 10);
              *puVar26 = uVar12;
              puVar33 = (undefined1 *)0x0;
              *(undefined2 *)((longlong)puVar26 + 6) = uVar29;
LAB_14001dd76:
              puVar34 = (undefined1 *)0x0;
              RtlSetVolatileMemory(puVar23,0,0x40);
            }
            uVar31 = 0;
            uVar21 = 0;
            uVar15 = local_68;
            do {
              if ((*(ulonglong *)(uVar15 + 0x20 + (longlong)puVar32) >> (uVar21 & 0x3f) & 1) != 0) {
                RtlSetVolatileMemory(&local_78,0,4);
                local_78._0_3_ =
                     CONCAT12((char)uVar21,*(undefined2 *)(local_68 + 0x28 + (longlong)puVar32));
                iVar27 = WinHvProcessorNumberToVpIndex(local_78,&local_74);
                if (-1 < iVar27) {
                  uVar28 = *(uint *)(*(longlong *)(lVar14 + 0x30) + 0x18);
                  if (uVar28 < 0x10004) {
                    if (uVar28 < 0x10002) {
                      *(ulonglong *)(puVar34 + 8) =
                           *(ulonglong *)(puVar34 + 8) | 1L << ((ulonglong)local_74 & 0x3f);
                    }
                    else {
                      *(undefined2 *)(puVar33 + uVar31 * 2 + 6) = (undefined2)local_74;
                    }
                  }
                  else {
                    *(undefined2 *)((longlong)puVar26 + uVar31 * 2 + 10) = (undefined2)local_74;
                  }
                  uVar31 = (ulonglong)(ushort)((short)uVar31 + 1);
                }
                uVar15 = local_68;
              }
              uVar28 = (int)uVar21 + 1;
              uVar21 = (ulonglong)uVar28;
            } while (uVar28 < 0x40);
            uVar28 = *(uint *)(*(longlong *)(lVar14 + 0x30) + 0x18);
            if (uVar28 < 0x10004) {
              if (0x10001 < uVar28) {
                *(short *)(puVar33 + 4) = (short)uVar31;
              }
            }
            else {
              *(short *)(puVar26 + 2) = (short)uVar31;
            }
            bVar11 = (byte)((uint)*(undefined4 *)(uVar15 + 0x3c + (longlong)puVar32) >> 8) & 7;
            if (puVar26 == (uint *)0x0) {
              if (puVar33 == (undefined1 *)0x0) {
                if (puVar34 == (undefined1 *)0x0) {
                  iVar13 = -0x3ffffe7d;
                  goto LAB_14001df23;
                }
                puVar34[1] = bVar11;
              }
              else {
                puVar33[1] = bVar11;
              }
            }
            else {
              *(byte *)(puVar26 + 1) = bVar11;
            }
            if (1 < bVar11) {
              iVar13 = -0x3ffffff3;
              goto LAB_14001df23;
            }
            uVar28 = (int)local_70 + 1;
            local_88 = local_88 + iVar13;
            uVar15 = (ulonglong)local_88;
            local_70 = (uint *)CONCAT44(local_70._4_4_,uVar28);
          } while (local_88 < local_5c);
        }
        uVar15 = Feature_VpciVscRelaxedInterruptLimit__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar15 == 0) {
          *(uint *)(lVar4 + 0x80) = uVar28;
        }
        else {
          uVar12 = 0x1ee;
          if (uVar28 < 0x1ee) {
            uVar12 = uVar28;
          }
          *(uint *)(lVar4 + 0x80) = uVar12;
          *(uint *)(lVar14 + 0x128) = uVar28 - uVar12;
        }
      }
    }
    iVar13 = 0;
  }
  else {
    puVar22 = (ushort *)(*(longlong *)(lVar14 + 0x1f0) + 0x1a);
    do {
      if ((char)puVar22[-3] == '\x02') {
        if ((puVar22[-2] & 2) == 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x7c,
                              &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar30);
          }
          iVar13 = -0x3ffffff3;
          goto LAB_14001df39;
        }
        local_5c = uVar25 + *puVar22;
        iVar27 = iVar27 + uVar28;
        uVar25 = local_5c;
      }
      uVar24 = uVar24 + uVar28;
      puVar22 = puVar22 + 10;
    } while (uVar24 < uVar12);
    if (uVar25 == 0) goto LAB_14001d63e;
    uVar16 = (**(code **)(WdfFunctions_01033 + 0x108))(WdfDriverGlobals,param_1);
    uVar15 = GetInterruptConnectionData(uVar16,&local_70);
    iVar13 = (int)uVar15;
    if (-1 < iVar13) {
      puVar32 = local_70;
      goto LAB_14001d63e;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x7d,
                         &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar30,(char)uVar15);
    }
    puVar32 = local_70;
  }
LAB_14001df23:
  if (puVar32 != (uint *)0x0) {
    ExFreePoolWithTag(puVar32,0);
  }
LAB_14001df39:
  uVar15 = Feature_VpciVscRelaxedInterruptLimit__private_IsEnabledDeviceUsageNoInline();
  if ((((int)uVar15 != 0) && (iVar13 < 0)) && (*(longlong *)(lVar14 + 0x120) != 0)) {
    ExFreePoolWithTag(*(longlong *)(lVar14 + 0x120),0x69637056);
    *(undefined8 *)(lVar14 + 0x120) = 0;
  }
  return iVar13;
}



===== PdoPreprocessReadWriteConfig @ 14001df90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint PdoPreprocessReadWriteConfig(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  uint uVar2;
  undefined4 *puVar3;
  ulonglong uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  puVar3 = (undefined4 *)
           (**(code **)(WdfFunctions_01033 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8);
  lVar1 = *(longlong *)(param_2 + 0xb8);
  if (*(char *)(lVar1 + 1) == '\x10') {
    uVar4 = VpciSetBusData(puVar3,(ulonglong)*(uint *)(lVar1 + 8),*(undefined4 **)(lVar1 + 0x10),
                           *(uint *)(lVar1 + 0x18),*(uint *)(lVar1 + 0x20));
    uVar2 = (uint)uVar4;
    uVar5 = -(uint)(uVar2 != *(uint *)(lVar1 + 0x20)) & 0xc0000001;
  }
  else {
    uVar4 = VpciGetBusData(puVar3,(ulonglong)*(uint *)(lVar1 + 8),*(undefined4 **)(lVar1 + 0x10),
                           *(uint *)(lVar1 + 0x18),*(uint *)(lVar1 + 0x20));
    uVar2 = (uint)uVar4;
    uVar5 = 0;
    if (uVar2 != *(uint *)(lVar1 + 0x20)) {
      uVar5 = 0xc0000001;
    }
  }
  bVar7 = -1 < (int)uVar5;
  if (bVar7) {
    uVar5 = 0;
  }
  uVar6 = 0;
  if (bVar7) {
    uVar6 = uVar2;
  }
  *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar6;
  *(uint *)(param_2 + 0x30) = uVar5;
  IofCompleteRequest(param_2,0);
  return uVar5;
}



===== PdoQueryResourceRequirements @ 14001e050 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PdoQueryResourceRequirements(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  char cVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  uint uVar11;
  ulonglong uVar12;
  undefined2 uVar13;
  undefined8 uVar14;
  byte bVar15;
  undefined1 auStackY_e8 [32];
  undefined8 uVar16;
  undefined4 uVar17;
  undefined1 uVar18;
  char local_a8;
  byte local_a7;
  undefined8 local_a0;
  uint local_98 [2];
  undefined8 local_90;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_60 = 0;
  uStack_58 = 0;
  local_a0 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_98[0] = 0;
  local_a8 = '\0';
  local_90 = param_1;
  local_70 = param_2;
  puVar8 = (undefined4 *)
           (**(code **)(WdfFunctions_01033 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8);
  local_84 = 0;
  local_78 = 0;
  lVar1 = *(longlong *)(puVar8 + 0xc);
  puVar2 = *(undefined4 **)(puVar8 + 0x3c);
  local_88 = 0;
  uVar9 = (**(code **)(WdfFunctions_01033 + 0x660))(WdfDriverGlobals,puVar8);
  bVar15 = 1;
  uVar14 = 0x20019;
  uVar16 = 0;
  iVar7 = (**(code **)(WdfFunctions_01033 + 0x180))(WdfDriverGlobals,uVar9,1);
  if (-1 < iVar7) {
    PdoGetRegistryValue(L"IoNotRequired",L"e5b3b5ac-9725-4f78-963f-03dfb1d828c7",local_78,uVar14,
                        uVar16,&local_84,&local_88);
    (**(code **)(WdfFunctions_01033 + 0x738))(WdfDriverGlobals,local_78);
  }
  uVar17 = (undefined4)((ulonglong)uVar16 >> 0x20);
  local_68 = 0x42490005;
  local_64 = *puVar8;
  uVar18 = SUB81(puVar8,0);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar17 = 1;
    WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x62,
                       &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,
                       (char)*(undefined8 *)(puVar8 + 0xc),uVar18);
  }
  local_80 = *puVar2;
  uVar9 = CONCAT44(uVar17,1);
  iVar7 = VmbChannelSendSynchronousRequest(*(undefined8 *)(lVar1 + 0x28),&local_68,8);
  if (iVar7 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar7;
    }
    WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,99,uVar9,
                        (char)*(undefined8 *)(puVar8 + 0xc),uVar18,(char)iVar7);
    return iVar7;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,100,
                       &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,
                       (char)*(undefined8 *)(puVar8 + 0xc),uVar18);
  }
  iVar7 = puVar2[2];
  if (iVar7 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar7;
    }
    uVar13 = 0x65;
  }
  else {
    iVar7 = PdoGetMessageCount(puVar8,local_98,&local_a8);
    uVar5 = local_98[0];
    if (iVar7 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar7;
      }
      uVar13 = 0x66;
    }
    else {
      *(char *)((longlong)puVar8 + 0x12f) = local_a8;
      uVar17 = puVar2[4];
      uVar3 = puVar2[5];
      uVar4 = puVar2[6];
      puVar8[0x14] = puVar2[3];
      puVar8[0x15] = uVar17;
      puVar8[0x16] = uVar3;
      puVar8[0x17] = uVar4;
      *(undefined8 *)(puVar8 + 0x18) = *(undefined8 *)(puVar2 + 7);
      if ((local_a8 == '\0') && (bVar15 = 1, 1 < local_98[0])) {
        bVar15 = 2;
      }
      local_a7 = 0;
      while (iVar7 = (**(code **)(WdfFunctions_01033 + 0x930))(WdfDriverGlobals,param_2,0,&local_a0)
            , -1 < iVar7) {
        uVar12 = 0;
        do {
          uVar11 = puVar2[uVar12 + 3];
          if (uVar11 != 0) {
            RtlSetVolatileMemory(&local_60,0,0x20);
            if ((uVar11 & 1) == 0) {
              iVar7 = 0;
              if (((byte)uVar11 & 6) == 4) {
                if ((int)uVar12 == 5) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x69,
                                      &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar18);
                  }
                  return -0x3ffffff3;
                }
                uVar12 = (ulonglong)((int)uVar12 + 1);
                iVar7 = puVar2[uVar12 + 3];
              }
              uVar10 = PciGetLengthFromBar(iVar7,uVar11);
              uVar9 = local_60;
              local_60._0_3_ = CONCAT21(0x103,(byte)local_60);
              uVar14 = local_60;
              local_60._6_2_ = SUB82(uVar9,6);
              local_60._0_4_ = (undefined4)uVar14;
              local_60._0_6_ = CONCAT24(0x80,(undefined4)local_60);
              if ((uVar11 & 8) != 0) {
                local_60._0_6_ = CONCAT24(0x84,(undefined4)local_60);
              }
              iVar7 = RtlIoEncodeMemIoResource
                                (&local_60,3,uVar10,uVar10 + 0xfff & 0xfffffffffffff000);
              if (iVar7 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                  return iVar7;
                }
                uVar13 = 0x6a;
LAB_14001e3c8:
                WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar13,
                                   &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar18,
                                   (char)iVar7);
                return iVar7;
              }
              iVar7 = (**(code **)(WdfFunctions_01033 + 0x938))(WdfDriverGlobals,local_a0,&local_60)
              ;
              if (iVar7 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                  return iVar7;
                }
                uVar13 = 0x6b;
                goto LAB_14001e3c8;
              }
              RtlSetVolatileMemory(&local_60,0,0x20);
              local_60._0_3_ = CONCAT21(0x181,(byte)local_60);
              uStack_58 = CONCAT44((int)uVar12,1);
              iVar7 = (**(code **)(WdfFunctions_01033 + 0x938))(WdfDriverGlobals);
              if (iVar7 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                  return iVar7;
                }
                uVar13 = 0x6c;
                goto LAB_14001e3c8;
              }
            }
            else {
              local_60._0_2_ = (ushort)(byte)local_60;
              iVar7 = (**(code **)(WdfFunctions_01033 + 0x938))(WdfDriverGlobals);
              if (iVar7 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                  return iVar7;
                }
                uVar13 = 0x68;
                goto LAB_14001e3c8;
              }
            }
          }
          uVar11 = (int)uVar12 + 1;
          uVar12 = (ulonglong)uVar11;
        } while (uVar11 < 6);
        if (uVar5 != 0) {
          if ((bVar15 == 2) && (local_a7 == 0)) {
            if ((local_a8 == '\0') &&
               ((1 < uVar5 &&
                (iVar7 = PdoAppendMsiRequirements(local_90,local_a0,'\0',uVar5,'\0'), iVar7 < 0))))
            {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                return iVar7;
              }
              uVar13 = 0x6d;
              goto LAB_14001e7be;
            }
          }
          else if (local_a8 == '\0') {
            iVar7 = PdoAppendMsiRequirements(local_90,local_a0,'\0',1,'\0');
            if (iVar7 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                return iVar7;
              }
              uVar13 = 0x70;
              goto LAB_14001e7be;
            }
          }
          else {
            if (uVar5 < 2) {
              cVar6 = '\0';
            }
            else {
              iVar7 = PdoAppendMsiRequirements(local_90,local_a0,'\x01',uVar5,'\0');
              if (iVar7 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                  return iVar7;
                }
                uVar13 = 0x6e;
                goto LAB_14001e7be;
              }
              cVar6 = '\x01';
            }
            iVar7 = PdoAppendMsiRequirements(local_90,local_a0,'\x01',1,cVar6);
            if (iVar7 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                return iVar7;
              }
              uVar13 = 0x6f;
              goto LAB_14001e7be;
            }
          }
        }
        iVar7 = (**(code **)(WdfFunctions_01033 + 0x900))(WdfDriverGlobals,local_70);
        if (iVar7 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return iVar7;
          }
          uVar13 = 0x71;
          goto LAB_14001e7be;
        }
        local_a7 = local_a7 + 1;
        if (bVar15 <= local_a7) {
          (**(code **)(WdfFunctions_01033 + 0x8f8))(WdfDriverGlobals,local_70,5);
          (**(code **)(WdfFunctions_01033 + 0x8f0))(WdfDriverGlobals,local_70,*puVar8);
          return 0;
        }
        param_2 = local_70;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar7;
      }
      uVar13 = 0x67;
    }
  }
LAB_14001e7be:
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar13,
                     &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar18,(char)iVar7);
  return iVar7;
}



===== PdoQueryResources @ 14001e820 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint PdoQueryResources(undefined8 param_1,undefined8 param_2)

{
  uint *puVar1;
  longlong lVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  undefined2 uVar10;
  undefined1 auStackY_a8 [32];
  undefined8 in_stack_ffffffffffffff78;
  undefined4 uVar12;
  undefined8 uVar11;
  undefined1 uVar13;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined4 local_40;
  ulonglong local_38;
  
  uVar12 = (undefined4)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);
  local_38 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_48 = 0;
  local_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  puVar6 = (undefined4 *)
           (**(code **)(WdfFunctions_01033 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8);
  lVar2 = *(longlong *)(puVar6 + 0xc);
  puVar3 = *(uint **)(puVar6 + 0x3a);
  if (puVar6[0x38] - 4 < 2) {
    return 0;
  }
  local_60 = 0x42490006;
  local_5c = *puVar6;
  uVar13 = SUB81(puVar6,0);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar12 = 1;
    WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0x58,
                       &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,
                       (char)*(undefined8 *)(puVar6 + 0xc),uVar13);
  }
  uVar5 = *puVar3;
  puVar7 = &local_60;
  uVar9 = 0x24;
  uVar11 = CONCAT44(uVar12,1);
  uVar4 = VmbChannelSendSynchronousRequest(*(undefined8 *)(lVar2 + 0x28));
  if ((int)uVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar4;
    }
    uVar10 = 0x59;
  }
  else {
    if (0x1b < uVar5) {
      puVar1 = puVar3 + 3;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar7,uVar9,0x5b,uVar11,
                            (char)*(undefined8 *)(puVar6 + 0xc),uVar13,(char)*puVar1);
      }
      if (*puVar1 == 0) {
        return 0;
      }
      uVar8 = 0;
      if (*puVar1 == 0) {
        return 0;
      }
      do {
        uVar5 = (**(code **)(WdfFunctions_01033 + 0x970))
                          (WdfDriverGlobals,param_2,puVar3 + 2 + uVar8 * 5 + 2);
        if ((int)uVar5 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return uVar5;
          }
          WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x5c,
                             &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar13,(char)uVar5);
          return uVar5;
        }
        uVar4 = (int)uVar8 + 1;
        uVar8 = (ulonglong)uVar4;
      } while (uVar4 < *puVar1);
      return uVar5;
    }
    uVar4 = puVar3[2];
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar4;
    }
    uVar10 = 0x5a;
  }
  WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,uVar10,uVar11,
                      (char)*(undefined8 *)(puVar6 + 0xc),uVar13,(char)uVar4);
  return uVar4;
}



===== PdoReleaseHardware @ 14001eaa0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 PdoReleaseHardware(undefined8 param_1,undefined1 param_2)

{
  int *piVar1;
  ulonglong uVar2;
  
  piVar1 = (int *)(**(code **)(WdfFunctions_01033 + 0x650))
                            (WdfDriverGlobals,param_1,PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8)
  ;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x85,
                       &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)piVar1,param_2);
  }
  PdoRunStateMachine(piVar1,3);
  uVar2 = Feature_VpciVscRelaxedInterruptLimit__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar2 != 0) && (*(longlong *)(piVar1 + 0x48) != 0)) {
    ExFreePoolWithTag(*(longlong *)(piVar1 + 0x48),0x69637056);
    piVar1[0x48] = 0;
    piVar1[0x49] = 0;
  }
  return 0;
}



===== PdoRunStateMachine @ 14001eb68 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong PdoRunStateMachine(int *param_1,int param_2)

{
  int *piVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  longlong lVar4;
  char cVar5;
  int iVar6;
  
  (**(code **)(WdfFunctions_01033 + 0x9c8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 8),0);
  piVar1 = &DAT_1400101d4;
  iVar6 = 0x3f;
  lVar4 = 0x58;
  do {
    if ((piVar1[-1] == param_1[10]) && (*piVar1 == param_2)) {
      iVar6 = piVar1[1];
    }
    piVar1 = piVar1 + 3;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qLLLqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  if (iVar6 == 0x3f) {
    uVar2 = (**(code **)(WdfFunctions_01033 + 0x9d0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 8))
    ;
    return uVar2 & 0xffffffffffffff00;
  }
LAB_14001ec4e:
  param_1[10] = iVar6;
  if (iVar6 < 0x1e) {
    if (iVar6 == 0x1d) {
      iVar6 = param_1[0x74];
      KeSetEvent(param_1 + 0x6e);
      iVar6 = (iVar6 >> 0x1f & 1U) + 9;
      goto LAB_14001eeaf;
    }
    if (iVar6 < 0x10) {
      if (iVar6 == 0xf) {
        FdoEjectPdo(*(longlong *)(param_1 + 0xc),*(longlong *)(param_1 + 2));
        goto LAB_14001f0d5;
      }
      if (iVar6 < 8) {
        if (iVar6 == 7) {
LAB_14001f06d:
          cVar5 = '\x04';
          goto LAB_14001f020;
        }
        if (iVar6 == 2) {
          cVar5 = '\x05';
          goto LAB_14001f020;
        }
        if (iVar6 == 3) {
          PdoSendQueryStopFailed(param_1);
          goto LAB_14001ed2b;
        }
        if (iVar6 == 4) {
          uVar3 = (**(code **)(WdfFunctions_01033 + 0xf8))(WdfDriverGlobals);
          lVar4 = IoGetAttachedDeviceReference(uVar3);
          *(longlong *)(param_1 + 0x82) = lVar4;
          lVar4 = IoAllocateIrp(*(undefined1 *)(lVar4 + 0x4c));
          *(longlong *)(param_1 + 0x80) = lVar4;
          iVar6 = 3 - (uint)(lVar4 != 0);
          goto LAB_14001eeaf;
        }
        if (iVar6 == 5) {
          PnpBlockerStopBlocking((longlong)param_1);
          goto LAB_14001efd9;
        }
        if (iVar6 != 6) goto LAB_14001f0d5;
        PnpBlockerStopBlocking((longlong)param_1);
        PdoSendQueryStopFailed(param_1);
        iVar6 = 0x29;
      }
      else {
        if (iVar6 == 0xb) {
          param_1[0x74] = 0;
LAB_14001ed82:
          KeSetEvent(param_1 + 0x6e);
          goto LAB_14001efd9;
        }
        if (iVar6 == 0xc) {
          param_1[0x74] = 0x103;
          KeClearEvent(param_1 + 0x6e);
          goto LAB_14001f0d5;
        }
        if (iVar6 == 0xd) {
          PdoSendEjectionComplete(param_1,0);
          iVar6 = 0xc;
        }
        else {
          if (iVar6 != 0xe) goto LAB_14001f0d5;
          FdoEjectPdo(*(longlong *)(param_1 + 0xc),*(longlong *)(param_1 + 2));
          iVar6 = 0x11;
        }
      }
      goto LAB_14001efdb;
    }
    if (iVar6 == 0x10) {
      PnpBlockerStopBlocking((longlong)param_1);
      PdoFreePnpIrp((longlong)param_1);
      iVar6 = 0xf;
      goto LAB_14001efdb;
    }
    if (iVar6 == 0x12) {
      iVar6 = (*(int *)(*(longlong *)(param_1 + 0x80) + 0x30) >> 0x1f & 0x19U) + 7;
    }
    else {
      if (iVar6 == 0x13) {
        PdoSendEjectionComplete(param_1,0xc0000001);
LAB_14001ee4f:
        iVar6 = 9;
        goto LAB_14001efdb;
      }
      if (iVar6 == 0x14) {
        PdoSendEjectionComplete(param_1,0xc0000001);
        goto LAB_14001ee3b;
      }
      if (iVar6 == 0x16) {
        iVar6 = param_1[0x74];
        KeSetEvent(param_1 + 0x6e);
        iVar6 = (iVar6 >> 0x1f) + 0xf;
        goto LAB_14001eeaf;
      }
      if (iVar6 != 0x17) {
        if ((iVar6 == 0x1a) || (iVar6 == 0x1b)) {
          param_1[0x74] = -0x3fffffff;
          goto LAB_14001ed82;
        }
        if (iVar6 == 0x1c) {
          PnpBlockerStartBlocking((longlong)param_1);
        }
        goto LAB_14001f0d5;
      }
      iVar6 = param_1[0x74];
      KeSetEvent(param_1 + 0x6e);
      iVar6 = (iVar6 >> 0x1f & 0xffffffeeU) + 0x1c;
    }
LAB_14001eeaf:
    if (iVar6 == 0x3f) goto LAB_14001f0d5;
  }
  else {
    if (0x2f < iVar6) {
      if (iVar6 == 0x30) {
        PnpBlockerStopBlocking((longlong)param_1);
        PdoFreePnpIrp((longlong)param_1);
LAB_14001efd9:
        iVar6 = 0x3e;
      }
      else {
        if (iVar6 == 0x31) goto LAB_14001f0b0;
        if (iVar6 != 0x32) {
          if (iVar6 != 0x33) {
            if (iVar6 == 0x34) {
              param_1[0x74] = -0x3fffffff;
              KeSetEvent(param_1 + 0x6e,0,0);
              goto LAB_14001f0d5;
            }
            if (iVar6 == 0x36) {
              KeSetEvent(param_1 + 0x6e);
              goto LAB_14001efb8;
            }
            if (iVar6 == 0x37) {
              PnpBlockerStopBlocking((longlong)param_1);
              goto LAB_14001ee4f;
            }
            if (iVar6 != 0x38) {
              if (iVar6 == 0x3c) goto LAB_14001f07f;
              goto LAB_14001f0d5;
            }
          }
          cVar5 = '\0';
          goto LAB_14001f020;
        }
        PdoSendQueryStopFailed(param_1);
LAB_14001efb8:
        iVar6 = 0x2b;
      }
      goto LAB_14001efdb;
    }
    if (iVar6 == 0x2f) {
      PdoFreePnpIrp((longlong)param_1);
LAB_14001ed2b:
      iVar6 = 0x37;
      goto LAB_14001efdb;
    }
    if (iVar6 == 0x1e) {
LAB_14001f0b0:
      param_1[0x74] = 0x103;
      KeClearEvent(param_1 + 0x6e);
      PdoSendAssignedResourcesMessage(param_1);
      goto LAB_14001f0d5;
    }
    if (iVar6 == 0x1f) {
      cVar5 = '\x06';
LAB_14001f020:
      PdoSelfSendPnpIrp((longlong)param_1,cVar5);
      goto LAB_14001f0d5;
    }
    if (iVar6 == 0x20) {
      PdoSendQueryStopFailed(param_1);
      PdoSelfSendPnpIrp((longlong)param_1,'\x06');
      iVar6 = 0x22;
      goto LAB_14001efdb;
    }
    if ((iVar6 == 0x23) || (iVar6 == 0x24)) goto LAB_14001f06d;
    if ((iVar6 == 0x25) || (iVar6 == 0x28)) {
LAB_14001f07f:
      PdoSendReleaseResourcesMessage(param_1);
LAB_14001f0d5:
      uVar3 = (**(code **)(WdfFunctions_01033 + 0x9d0))
                        (WdfDriverGlobals,*(undefined8 *)(param_1 + 8));
      return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
    }
    if (iVar6 == 0x29) {
      PdoSendReleaseResourcesMessage(param_1);
      goto LAB_14001ee3b;
    }
    if (iVar6 != 0x2a) goto LAB_14001f0d5;
    PdoFreePnpIrp((longlong)param_1);
    PnpBlockerStopBlocking((longlong)param_1);
LAB_14001ee3b:
    iVar6 = 10;
  }
LAB_14001efdb:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  goto LAB_14001ec4e;
}



===== PdoSaveRawAndTranslatedResources @ 14001f118 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong PdoSaveRawAndTranslatedResources(longlong param_1)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined4 *puVar5;
  undefined4 local_res8 [2];
  
  uVar3 = (**(code **)(WdfFunctions_01033 + 0xf8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 8));
  if (*(longlong *)(param_1 + 0x1f0) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x1f0),0);
    *(undefined8 *)(param_1 + 0x1f0) = 0;
  }
  local_res8[0] = 0;
  uVar4 = IoGetDeviceProperty(uVar3,0x15,0,0,local_res8);
  iVar1 = (int)uVar4;
  if (iVar1 < 0) {
    if (iVar1 != -0x3fffffdd) {
      return uVar4;
    }
  }
  else {
    local_res8[0] = 0x28;
  }
  puVar5 = (undefined4 *)ExAllocatePool2(0x40,local_res8[0],0x69637056);
  if (puVar5 == (undefined4 *)0x0) {
    uVar4 = 0xc000009a;
  }
  else {
    if (iVar1 < 0) {
      uVar2 = IoGetDeviceProperty(uVar3,0x15,local_res8[0],puVar5,local_res8);
      if ((int)uVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x92,
                             &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_1,
                             (char)uVar2);
        }
        ExFreePoolWithTag(puVar5,0);
        return (ulonglong)uVar2;
      }
    }
    else {
      *puVar5 = 0;
      puVar5[4] = 0;
    }
    *(undefined4 **)(param_1 + 0x1f0) = puVar5;
    uVar4 = 0;
  }
  return uVar4;
}



===== PdoScanPciCapabilities @ 14001f298 =====

undefined8 PdoScanPciCapabilities(uint *param_1)

{
  undefined8 uVar1;
  ulonglong uVar2;
  byte bVar3;
  byte local_res8 [8];
  undefined2 local_res10;
  ushort local_res18 [8];
  
  local_res8[0] = 0;
  local_res10 = 0;
  local_res18[0] = 0;
  FdoReadConfig(*(longlong *)(param_1 + 0xc),*param_1,(undefined4 *)local_res18,6,2);
  if ((local_res18[0] & 0x10) == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,10,
                        &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_1);
    }
LAB_14001f3e6:
    uVar1 = 0xc0000186;
  }
  else {
    uVar2 = (ulonglong)*param_1;
    FdoReadConfig(*(longlong *)(param_1 + 0xc),*param_1,(undefined4 *)local_res8,0x34,1);
    bVar3 = local_res8[0];
    while (bVar3 != 0) {
      if (((bVar3 < 0x40) || ((bVar3 & 3) != 0)) || (bVar3 == 0xff)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,1,0xb,
                             &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,bVar3,(char)param_1);
        }
        goto LAB_14001f3e6;
      }
      uVar2 = (ulonglong)*param_1;
      FdoReadConfig(*(longlong *)(param_1 + 0xc),*param_1,(undefined4 *)&local_res10,
                    (ulonglong)bVar3,2);
      if ((char)local_res10 == '\x05') {
        *(byte *)((longlong)param_1 + 0x12d) = bVar3;
      }
      else if ((char)local_res10 == '\x10') {
        *(byte *)(param_1 + 0x4b) = bVar3;
      }
      else if ((char)local_res10 == '\x11') {
        *(byte *)((longlong)param_1 + 0x12e) = bVar3;
      }
      bVar3 = local_res10._1_1_;
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== PdoSelfSendIrpSendWorkItem @ 14001f400 =====

void PdoSelfSendIrpSendWorkItem(undefined8 param_1,longlong param_2)

{
  IofCallDriver(*(undefined8 *)(param_2 + 0x208),*(undefined8 *)(param_2 + 0x200));
  return;
}



===== PdoSelfSendPnpIrp @ 14001f42c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdoSelfSendPnpIrp(longlong param_1,char param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x200);
  IoReuseIrp(lVar2,0xc00000bb);
  lVar3 = *(longlong *)(lVar2 + 0xb8);
  *(undefined1 *)(lVar3 + -0x48) = 0x1b;
  *(char *)(lVar3 + -0x47) = param_2;
  *(undefined1 *)(param_1 + 0x21d) = 1;
  if (param_2 == '\0') {
    lVar4 = *(longlong *)(param_1 + 0x1f0);
    *(undefined4 *)(param_1 + 0x218) = 0xd;
    uVar1 = *(uint *)(lVar4 + 0x10);
    *(longlong *)(lVar3 + -0x40) = lVar4;
    *(ulonglong *)(lVar3 + -0x38) = lVar4 + ((ulonglong)uVar1 + 1) * 0x14;
  }
  else if (param_2 == '\x04') {
    *(undefined4 *)(param_1 + 0x218) = 0xe;
  }
  else if (param_2 == '\x05') {
    *(undefined4 *)(param_1 + 0x218) = 10;
  }
  else {
    if (param_2 != '\x06') {
      return;
    }
    *(undefined4 *)(param_1 + 0x218) = 0;
  }
  lVar2 = *(longlong *)(lVar2 + 0xb8);
  *(code **)(lVar2 + -0x10) = PdoCompleteSelfSentPnpIrp;
  *(longlong *)(lVar2 + -8) = param_1;
  *(undefined1 *)(lVar2 + -0x45) = 0xe0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xe,0xab,
                      &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_1);
  }
  (**(code **)(WdfFunctions_01033 + 0x668))
            (WdfDriverGlobals,*(undefined8 *)(param_1 + 8),0xffffffffdead0004,0x20d4,
             "onecore\\vm\\dv\\vpci\\vsc\\sys\\pdo.c");
  IoQueueWorkItem(*(undefined8 *)(param_1 + 0x210),PdoSelfSendIrpSendWorkItem,1,param_1);
  return;
}



===== PdoSelfSentIrpCompletionWorkItem @ 14001f5a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdoSelfSentIrpCompletionWorkItem(undefined8 param_1,int *param_2)

{
  PdoRunStateMachine(param_2,param_2[0x86]);
  *(undefined1 *)((longlong)param_2 + 0x21d) = 0;
  (**(code **)(WdfFunctions_01033 + 0x670))
            (WdfDriverGlobals,*(undefined8 *)(param_2 + 2),0xffffffffdead0004,0x2017,
             "onecore\\vm\\dv\\vpci\\vsc\\sys\\pdo.c");
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0xe,0xaa,
                      &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_2);
  }
  return;
}



===== PdoSendEjectionComplete @ 14001f644 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PdoSendEjectionComplete(undefined4 *param_1,undefined4 param_2)

{
  longlong lVar1;
  int iVar2;
  undefined1 auStackY_68 [32];
  undefined *in_stack_ffffffffffffffb8;
  ulonglong uVar3;
  undefined1 uVar4;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = 0;
  local_20 = 0;
  RtlSetVolatileMemory(&local_28,0,0xc);
  lVar1 = *(longlong *)(param_1 + 0xc);
  local_28 = CONCAT44(*param_1,0x4249000f);
  uVar4 = (undefined1)lVar1;
  local_20 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    in_stack_ffffffffffffffb8 = &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids;
    WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0xac,
                       &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar4,(char)param_1);
  }
  uVar3 = (ulonglong)in_stack_ffffffffffffffb8 & 0xffffffff00000000;
  iVar2 = VmbChannelSendSynchronousRequest(*(undefined8 *)(lVar1 + 0x28),&local_28,0xc);
  if ((iVar2 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0xad,uVar3,uVar4,
                        (char)param_1,(char)iVar2);
  }
  return;
}



===== PdoSendPowerMessage @ 14001f770 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PdoSendPowerMessage(undefined4 *param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStackY_98 [32];
  undefined4 uVar3;
  undefined1 uVar4;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_98;
  local_38 = 4;
  local_34 = 4;
  local_30 = 4;
  local_48 = 0x100000000;
  uStack_40 = 0x300000002;
  if (param_1[0x38] - 1 < 6) {
    local_50 = *(undefined4 *)((longlong)&local_48 + (longlong)(int)param_1[0x38] * 4);
    local_54 = *param_1;
    local_58 = 0x42490004;
    VmbPacketSetCompletionRoutine(*(undefined8 *)(param_1 + 0x3e),PdoPowerStateCompletion);
    uVar4 = SUB81(param_1,0);
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xe,0xa6,
                        &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar4);
    }
    uVar2 = *(undefined8 *)(param_1 + 2);
    uVar3 = 1;
    (**(code **)(WdfFunctions_01033 + 0x668))(WdfDriverGlobals,uVar2,0xffffffffdead0001,0x1fce);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar3 = 1;
      WPP_RECORDER_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,6,0xa7,
                          &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,
                          (char)*(undefined8 *)(param_1 + 0xc),uVar4,(char)SystemReserved1[0xf]);
    }
    uVar2 = CONCAT44(uVar3,1);
    iVar1 = VmbPacketSend(*(undefined8 *)(param_1 + 0x3e),&local_58,0xc);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0xa8,uVar2,
                            (char)*(undefined8 *)(param_1 + 0xc),uVar4,(char)iVar1);
      }
      (**(code **)(WdfFunctions_01033 + 0x670))
                (WdfDriverGlobals,*(undefined8 *)(param_1 + 2),0xffffffffdead0001,0x1fe0);
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,0xe,0xa9,
                          &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar4);
      }
      param_1[0x74] = iVar1;
      KeSetEvent(param_1 + 0x6e,0,0);
    }
  }
  return;
}



===== PdoSendQueryStopFailed @ 14001f9e0 =====

void PdoSendQueryStopFailed(undefined4 *param_1)

{
  longlong lVar1;
  int iVar2;
  undefined8 local_res8;
  undefined *in_stack_ffffffffffffffd8;
  ulonglong uVar3;
  
  local_res8 = 0;
  RtlSetVolatileMemory(&local_res8,0,8);
  lVar1 = *(longlong *)(param_1 + 0xc);
  local_res8 = CONCAT44(*param_1,0x4249000e);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    in_stack_ffffffffffffffd8 = &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids;
    WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0xae,
                       &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)lVar1,(char)param_1);
  }
  uVar3 = (ulonglong)in_stack_ffffffffffffffd8 & 0xffffffff00000000;
  iVar2 = VmbChannelSendSynchronousRequest
                    (*(undefined8 *)(lVar1 + 0x28),&local_res8,8,0,uVar3,0,0,0);
  if ((iVar2 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0xaf,uVar3,
                        (char)*(undefined8 *)(param_1 + 0xc),(char)param_1,(char)iVar2);
  }
  return;
}



===== PdoSendReleaseResourcesMessage @ 14001fae4 =====

void PdoSendReleaseResourcesMessage(undefined4 *param_1)

{
  longlong lVar1;
  int iVar2;
  undefined8 local_res8;
  undefined *in_stack_ffffffffffffffd8;
  ulonglong uVar3;
  undefined1 uVar4;
  
  local_res8 = 0;
  RtlSetVolatileMemory(&local_res8,0,8);
  lVar1 = *(longlong *)(param_1 + 0xc);
  local_res8 = CONCAT44(*param_1,0x42490011);
  uVar4 = (undefined1)lVar1;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    in_stack_ffffffffffffffd8 = &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids;
    WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,6,0xb0,
                       &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,uVar4,(char)param_1);
  }
  uVar3 = (ulonglong)in_stack_ffffffffffffffd8 & 0xffffffff00000000;
  iVar2 = VmbChannelSendSynchronousRequest
                    (*(undefined8 *)(lVar1 + 0x28),&local_res8,8,0,uVar3,0,0,0);
  if ((iVar2 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0xb1,uVar3,uVar4,
                        (char)param_1,(char)iVar2);
  }
  return;
}



===== PdoSendSelfIoControl @ 14001fbe4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PdoSendSelfIoControl
              (undefined4 param_1,longlong param_2,undefined8 param_3,undefined4 param_4,
              undefined8 param_5,undefined4 param_6)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  local_48 = 0;
  uStack_40 = 0;
  KeEnterCriticalRegion();
  KeWaitForSingleObject(param_2 + 0x1a0,0,0,0,0);
  lVar1 = *(longlong *)(param_2 + 0x198);
  IoReuseIrp(lVar1,0xc0000001);
  KeInitializeEvent(&local_38,0,0);
  lVar2 = *(longlong *)(lVar1 + 0xb8);
  *(undefined4 *)(lVar2 + -0x40) = param_6;
  *(undefined1 *)(lVar2 + -0x48) = 0xf;
  *(undefined4 *)(lVar2 + -0x38) = param_4;
  *(undefined4 *)(lVar2 + -0x30) = param_1;
  *(undefined8 *)(lVar1 + 0x70) = param_5;
  *(undefined8 *)(lVar2 + -0x28) = param_3;
  local_48 = CONCAT44(local_48._4_4_,0xc0000183);
  *(undefined8 **)(lVar1 + 0x48) = &local_48;
  *(undefined8 **)(lVar1 + 0x50) = &local_38;
  lVar2 = *(longlong *)(lVar1 + 0xb8);
  *(code **)(lVar2 + -0x10) = PdoCompleteSyncIrp;
  *(longlong *)(lVar2 + -8) = param_2;
  *(undefined1 *)(lVar2 + -0x45) = 0xe0;
  uVar4 = (**(code **)(WdfFunctions_01033 + 0x660))(WdfDriverGlobals,param_2);
  uVar4 = (**(code **)(WdfFunctions_01033 + 0xf8))(WdfDriverGlobals,uVar4);
  iVar3 = IofCallDriver(uVar4,lVar1);
  if (iVar3 == 0x103) {
    KeWaitForSingleObject(&local_38,0,0,0,0);
    iVar3 = (int)local_48;
  }
  KeSetEvent(param_2 + 0x1a0,0,0);
  KeLeaveCriticalRegion();
  return iVar3;
}



===== PdoStartIrpCompletionRoutine @ 14001fda0 =====

ulonglong PdoStartIrpCompletionRoutine(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  char *pcVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined1 *puVar6;
  uint uVar7;
  char *pcVar8;
  ulonglong uVar9;
  ulonglong local_res10;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  uVar9 = 0;
  local_res10 = 0;
  if ((*(longlong *)(lVar1 + 8) != 0) && (*(longlong *)(lVar1 + 0x10) != 0)) {
    uVar4 = HviGetSharedGpaBoundary();
    pcVar2 = *(char **)(lVar1 + 8);
    uVar7 = 0;
    puVar6 = *(undefined1 **)(lVar1 + 0x10);
    if (*(int *)(pcVar2 + 0x10) != 0) {
      pcVar8 = pcVar2;
      do {
        pcVar8 = pcVar8 + 0x14;
        puVar6 = puVar6 + 0x14;
        if ((*pcVar8 - 3U & 0xfb) == 0) {
          uVar5 = RtlCmDecodeMemIoResource(pcVar8,&local_res10);
          uVar3 = RtlCmEncodeMemIoResource(pcVar8,*pcVar8,uVar5,local_res10 | uVar4);
          uVar9 = (ulonglong)uVar3;
          if ((int)uVar3 < 0) break;
          uVar5 = RtlCmDecodeMemIoResource(puVar6,&local_res10);
          uVar3 = RtlCmEncodeMemIoResource(puVar6,*puVar6,uVar5,local_res10 | uVar4);
          uVar9 = (ulonglong)uVar3;
          if ((int)uVar3 < 0) break;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < *(uint *)(pcVar2 + 0x10));
    }
  }
  return uVar9 & 0xffffffff;
}



===== PnpBlockerBroadcastBlockingIsReady @ 14001fea0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 PnpBlockerBroadcastBlockingIsReady(longlong param_1,undefined8 param_2)

{
  undefined1 uVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  uVar2 = 0;
  (**(code **)(WdfFunctions_01033 + 0x9c8))(WdfDriverGlobals,DAT_140010760);
  if (DAT_140010788 == 1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,199,
                         &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_2,
                         (char)param_1);
    }
    *(undefined1 *)(param_1 + 0x21c) = 0;
    for (puVar3 = DAT_140010768; (undefined8 **)puVar3 != &DAT_140010768;
        puVar3 = (undefined8 *)*puVar3) {
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,200,
                          &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)puVar3 + -0x30);
      }
      (**(code **)(WdfFunctions_01033 + 0xbe0))(WdfDriverGlobals,puVar3[2]);
    }
    *(undefined8 *)(param_1 + 0x220) = param_2;
    uVar1 = 1;
    DAT_140010788 = 2;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar2,0xc6,
                         &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_1,
                         (char)DAT_140010788);
    }
    uVar1 = 0;
  }
  (**(code **)(WdfFunctions_01033 + 0x9d0))(WdfDriverGlobals,DAT_140010760);
  return uVar1;
}



===== PnpBlockerInit @ 140020054 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PnpBlockerInit(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(WdfFunctions_01033 + 0x9c0))(WdfDriverGlobals,0,&DAT_140010760);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xc0,
                        &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)iVar1);
    }
  }
  else {
    DAT_140010778 = 0;
    DAT_140010780 = 0;
    DAT_140010770 = &DAT_140010768;
    DAT_140010768 = &DAT_140010768;
    DAT_140010788 = 3;
    PnpBlocker = 1;
  }
  return iVar1;
}



===== PnpBlockerInitRequestor @ 140020108 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PnpBlockerInitRequestor(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  int iVar3;
  undefined8 *puVar4;
  ulonglong local_58;
  code *pcStack_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined8 local_3c;
  undefined8 uStack_34;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined8 local_18;
  undefined *local_10;
  
  local_2c = 0;
  local_18 = 0;
  lVar1 = param_1 + 0x230;
  *(undefined1 *)(param_1 + 0x248) = 0;
  *(longlong *)(param_1 + 0x238) = lVar1;
  *(longlong *)lVar1 = lVar1;
  local_3c = 0;
  uStack_34 = 0;
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_40 = 0x38;
  }
  else if (WdfStructureCount < 0x27) {
    local_40 = 0xffffffff;
  }
  else {
    local_40 = *(undefined4 *)(WdfStructures + 0x130);
  }
  local_10 = PTR__WDF_VPCI_WORKITEM_CONTEXT_TYPE_INFO_140010090;
  local_20 = *(undefined8 *)(param_1 + 8);
  local_28 = 1;
  local_24 = 1;
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_58 = 0x18;
  }
  else if (WdfStructureCount < 0x44) {
    local_58 = 0xffffffff;
  }
  else {
    local_58 = (ulonglong)*(uint *)(WdfStructures + 0x218);
  }
  pcStack_50 = PnpBlockerAnnounceBlockingIsReadyWorker;
  local_48 = 1;
  iVar3 = (**(code **)(WdfFunctions_01033 + 0xbd8))
                    (WdfDriverGlobals,&local_58,&local_40,(undefined8 *)(param_1 + 0x240));
  if (iVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xc1,
                         &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_1,(char)iVar3)
      ;
    }
  }
  else {
    puVar4 = (undefined8 *)
             (**(code **)(WdfFunctions_01033 + 0x650))
                       (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x240),
                        PTR__WDF_VPCI_WORKITEM_CONTEXT_TYPE_INFO_140010090);
    uVar2 = *(undefined8 *)(param_1 + 8);
    puVar4[2] = 0;
    *puVar4 = uVar2;
    puVar4[1] = param_1;
  }
  return iVar3;
}



===== PnpBlockerStartBlocking @ 1400202bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PnpBlockerStartBlocking(longlong param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined1 *puVar6;
  undefined1 auStackY_48 [8];
  undefined1 auStackY_40 [24];
  
  (**(code **)(WdfFunctions_01033 + 0x9c8))(WdfDriverGlobals,DAT_140010760,0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_qLl(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  puVar6 = auStackY_48;
  if (DAT_140010788 != 1) {
    if (DAT_140010788 == 2) {
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0xc4,
                          &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_1);
      }
      (**(code **)(WdfFunctions_01033 + 0xbe0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x240));
    }
    else {
      if (DAT_140010788 != 3) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0xc5,
                            &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)DAT_140010788);
          puVar6 = auStackY_48;
        }
        goto LAB_1400204ad;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0xc3,
                          &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_1);
      }
      uVar2 = (**(code **)(WdfFunctions_01033 + 0xf8))
                        (WdfDriverGlobals,*(undefined8 *)(param_1 + 8));
      *(undefined1 *)(param_1 + 0x21c) = 1;
      IoInvalidateDeviceRelations(uVar2,0);
      DAT_140010788 = 1;
      DAT_140010780 = param_1;
    }
  }
  puVar6 = auStackY_48;
  puVar5 = &DAT_140010768;
  puVar3 = (undefined8 *)(param_1 + 0x230);
  puVar4 = DAT_140010770;
  if ((undefined8 *)*DAT_140010770 != &DAT_140010768) {
    puVar4 = (undefined8 *)0x3;
    pcVar1 = (code *)swi(0x29);
    puVar3 = (undefined8 *)(*pcVar1)();
    puVar6 = auStackY_40;
  }
  *puVar3 = puVar5;
  puVar3[1] = puVar4;
  *puVar4 = puVar3;
  DAT_140010778 = DAT_140010778 + 1;
  DAT_140010770 = puVar3;
  *(undefined1 *)(param_1 + 0x248) = 1;
LAB_1400204ad:
  pcVar1 = *(code **)(WdfFunctions_01033 + 0x9d0);
  *(undefined8 *)(puVar6 + -8) = 0x1400204ce;
  (*pcVar1)(WdfDriverGlobals,DAT_140010760);
  return;
}



===== PnpBlockerStopBlocking @ 1400204e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PnpBlockerStopBlocking(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  
  (**(code **)(WdfFunctions_01033 + 0x9c8))(WdfDriverGlobals,DAT_140010760,0);
  if (*(char *)(param_1 + 0x248) == '\0') {
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0xcb,
                        &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_1);
    }
  }
  else {
    plVar1 = (longlong *)(param_1 + 0x230);
    lVar2 = *plVar1;
    if ((*(longlong **)(lVar2 + 8) != plVar1) ||
       (plVar3 = *(longlong **)(param_1 + 0x238), (longlong *)*plVar3 != plVar1)) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    *(longlong **)(param_1 + 0x238) = plVar1;
    *plVar1 = (longlong)plVar1;
    DAT_140010778 = DAT_140010778 + -1;
    *(undefined1 *)(param_1 + 0x248) = 0;
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_ql(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    if (DAT_140010778 == 0) {
      if (DAT_140010788 == 2) {
        lVar2 = *(longlong *)(DAT_140010780 + 0x220);
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0xcd,
                             &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)lVar2,
                             (char)DAT_140010780);
        }
        *(char *)(lVar2 + 0x43) = *(char *)(lVar2 + 0x43) + '\x01';
        *(longlong *)(lVar2 + 0xb8) = *(longlong *)(lVar2 + 0xb8) + 0x48;
        (**(code **)(WdfFunctions_01033 + 0x110))
                  (WdfDriverGlobals,*(undefined8 *)(DAT_140010780 + 8),lVar2);
        *(undefined8 *)(DAT_140010780 + 0x220) = 0;
      }
      else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0xce,
                          &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)DAT_140010780);
      }
      DAT_140010780 = 0;
      DAT_140010788 = 3;
    }
  }
  (**(code **)(WdfFunctions_01033 + 0x9d0))(WdfDriverGlobals,DAT_140010760);
  return;
}



===== QueryChildEnumerationPrefix @ 140020714 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint QueryChildEnumerationPrefix
               (wchar_t *param_1,undefined8 param_2,longlong param_3,undefined1 *param_4)

{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined1 auStackY_88 [32];
  undefined8 local_58;
  undefined8 *local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30 [2];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_88;
  *param_4 = 0;
  local_48 = 0;
  uStack_40 = 0;
  if (*(ushort *)(param_3 + 2) < 0xc) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x24,
                       &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids);
    }
    uVar1 = 0xc000000d;
  }
  else {
    lVar3 = 0;
    uVar2 = 0;
    KeWaitForSingleObject(&VpciGlobalLock,0,0);
    uVar1 = VscGetDeviceProxyPrefix(param_1,uVar2,local_30,lVar3);
    KeSetEvent(&VpciGlobalLock,0,0);
    if (uVar1 == 0xc0000225) {
      local_58 = 0x80006;
      local_38 = 0x4900430050;
      local_50 = &local_38;
      RtlCopyUnicodeString(param_3,&local_58);
      uVar1 = 0;
    }
    else if (-1 < (int)uVar1) {
      RtlInitUnicodeString(&local_48,local_30);
      RtlCopyUnicodeString(param_3,&local_48);
      *param_4 = 1;
    }
  }
  return uVar1;
}



===== VpciGetDmaAdapter @ 140020870 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 VpciGetDmaAdapter(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = (**(code **)(WdfFunctions_01033 + 0x108))
                    (WdfDriverGlobals,*(undefined8 *)(*(longlong *)(param_1 + 0x30) + 0x10));
  uVar1 = IoGetDmaAdapter(uVar1,param_2,param_3);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_qqqq
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0xb5,
               &WPP_77e2f43fe57a3377fb985a62dd96b99a_Traceguids,(char)param_1,(char)param_2,
               (char)param_3,(char)uVar1);
  }
  return uVar1;
}



===== VpciGetLocationStrings @ 140020940 =====

undefined8 VpciGetLocationStrings(undefined4 *param_1,undefined8 *param_2)

{
  wchar_t *pwVar1;
  undefined8 uVar2;
  
  pwVar1 = (wchar_t *)ExAllocatePool2(0x40);
  if (pwVar1 == (wchar_t *)0x0) {
    uVar2 = 0xc000009a;
  }
  else {
    RtlStringCchPrintfExW
              (pwVar1,0xc,(undefined8 *)0x0,(ulonglong *)0x0,0x200,L"VPCI(%.2X%.2X)",
               (byte)*param_1 & 0x1f);
    uVar2 = 0;
    *param_2 = pwVar1;
  }
  return uVar2;
}



===== VpciReadConfigBlock @ 1400209e0 =====

int VpciReadConfigBlock(longlong param_1,undefined4 param_2,undefined8 param_3,uint param_4)

{
  int iVar1;
  undefined4 local_18;
  uint local_14;
  
  if (param_4 < 0x81) {
    local_18 = param_2;
    local_14 = param_4;
    iVar1 = PdoSendSelfIoControl(0x2ac00b,param_1,&local_18,8,param_3,param_4);
  }
  else {
    iVar1 = -0x3ffffdfa;
  }
  return iVar1;
}



===== VpciWriteConfigBlock @ 140020a30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int VpciWriteConfigBlock(longlong param_1,undefined4 param_2,void *param_3,uint param_4)

{
  int iVar1;
  undefined1 auStackY_d8 [32];
  undefined4 local_a8;
  uint local_a4;
  undefined1 local_a0 [136];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  if (param_4 < 0x81) {
    local_a8 = param_2;
    local_a4 = param_4;
    memmove(local_a0,param_3,(ulonglong)param_4);
    iVar1 = PdoSendSelfIoControl(0x2ac00f,param_1,&local_a8,0x8c,0,0);
  }
  else {
    iVar1 = -0x3ffffdfa;
  }
  return iVar1;
}



===== VscGetOrCreateProxy @ 140020ac0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 * VscGetOrCreateProxy(wchar_t *param_1,char param_2,char param_3)

{
  code *pcVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01033 + 0x650))
                     (WdfDriverGlobals,VpciCtrlDev,
                      PTR__WDF_VPCI_VSC_CTRL_DEVICE_DATA_TYPE_INFO_140010018);
  if (param_1 != (wchar_t *)0x0) {
    for (puVar4 = (undefined8 *)*puVar3; puVar4 != puVar3; puVar4 = (undefined8 *)*puVar4) {
      iVar2 = wcsncmp(param_1,(wchar_t *)(puVar4 + 2),5);
      if ((iVar2 == 0) && (*(char *)((longlong)puVar4 + 0x1c) == param_2)) {
        return puVar4;
      }
    }
    if ((param_3 != '\0') &&
       (puVar4 = (undefined8 *)ExAllocatePool2(0x100,0x30,0x69637056), puVar4 != (undefined8 *)0x0))
    {
      wcsncpy_s((wchar_t *)(puVar4 + 2),6,param_1,6);
      puVar5 = (undefined8 *)puVar3[1];
      if ((undefined8 *)*puVar5 != puVar3) {
        pcVar1 = (code *)swi(0x29);
        puVar5 = (undefined8 *)(*pcVar1)(3);
      }
      *puVar4 = puVar3;
      puVar4[1] = puVar5;
      *puVar5 = puVar4;
      puVar3[1] = puVar4;
      puVar4[5] = 0;
      puVar4[4] = 0;
      *(char *)((longlong)puVar4 + 0x1c) = param_2;
      return puVar4;
    }
  }
  return (undefined8 *)0x0;
}



===== VscProxyAddDevicePath @ 140020be0 =====

uint VscProxyAddDevicePath(longlong param_1,wchar_t *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  uint uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined2 uVar7;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  if (*(wchar_t **)(param_1 + 0x28) == (wchar_t *)0x0) {
    lVar4 = 0xc2;
    puVar3 = (undefined8 *)ExAllocatePool2(0x100,0xc2,0x69637056);
    *(undefined8 **)(param_1 + 0x28) = puVar3;
    if (puVar3 != (undefined8 *)0x0) {
      uVar1 = *(undefined8 *)(param_2 + 4);
      *puVar3 = *(undefined8 *)param_2;
      puVar3[1] = uVar1;
      uVar1 = *(undefined8 *)(param_2 + 0xc);
      puVar3[2] = *(undefined8 *)(param_2 + 8);
      puVar3[3] = uVar1;
      uVar1 = *(undefined8 *)(param_2 + 0x14);
      puVar3[4] = *(undefined8 *)(param_2 + 0x10);
      puVar3[5] = uVar1;
      uVar1 = *(undefined8 *)(param_2 + 0x1c);
      puVar3[6] = *(undefined8 *)(param_2 + 0x18);
      puVar3[7] = uVar1;
      uVar1 = *(undefined8 *)(param_2 + 0x24);
      puVar3[8] = *(undefined8 *)(param_2 + 0x20);
      puVar3[9] = uVar1;
      uVar1 = *(undefined8 *)(param_2 + 0x2c);
      puVar3[10] = *(undefined8 *)(param_2 + 0x28);
      puVar3[0xb] = uVar1;
      uVar1 = *(undefined8 *)(param_2 + 0x34);
      puVar3[0xc] = *(undefined8 *)(param_2 + 0x30);
      puVar3[0xd] = uVar1;
      uVar1 = *(undefined8 *)(param_2 + 0x3c);
      puVar3[0xe] = *(undefined8 *)(param_2 + 0x38);
      puVar3[0xf] = uVar1;
      uVar1 = *(undefined8 *)(param_2 + 0x44);
      puVar3[0x10] = *(undefined8 *)(param_2 + 0x40);
      puVar3[0x11] = uVar1;
      uVar1 = *(undefined8 *)(param_2 + 0x4c);
      puVar3[0x12] = *(undefined8 *)(param_2 + 0x48);
      puVar3[0x13] = uVar1;
      uVar1 = *(undefined8 *)(param_2 + 0x54);
      puVar3[0x14] = *(undefined8 *)(param_2 + 0x50);
      puVar3[0x15] = uVar1;
      uVar1 = *(undefined8 *)(param_2 + 0x5c);
      puVar3[0x16] = *(undefined8 *)(param_2 + 0x58);
      puVar3[0x17] = uVar1;
      *(undefined8 *)(param_1 + 0x20) = 0xc2;
      return 0;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000009a;
    }
    uVar7 = 0x16;
  }
  else {
    uVar5 = *(ulonglong *)(param_1 + 0x20);
    uVar2 = VscProxyIsSubString(*(wchar_t **)(param_1 + 0x28),uVar5,param_2,param_4,local_res18);
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar2;
      }
      WPP_RECORDER_SF_Sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,1,0x17,
                         &WPP_910e8a1cc1ab306ac66fc329452f92cd_Traceguids,param_2,(char)uVar2);
      return uVar2;
    }
    if (local_res18[0] != 0) {
      return 0;
    }
    lVar6 = *(longlong *)(param_1 + 0x20) + 0xc0;
    lVar4 = lVar6;
    puVar3 = (undefined8 *)ExAllocatePool2(0x100,lVar6,0x69637056);
    if (puVar3 != (undefined8 *)0x0) {
      uVar1 = *(undefined8 *)(param_2 + 4);
      *puVar3 = *(undefined8 *)param_2;
      puVar3[1] = uVar1;
      uVar1 = *(undefined8 *)(param_2 + 0xc);
      puVar3[2] = *(undefined8 *)(param_2 + 8);
      puVar3[3] = uVar1;
      uVar1 = *(undefined8 *)(param_2 + 0x14);
      puVar3[4] = *(undefined8 *)(param_2 + 0x10);
      puVar3[5] = uVar1;
      uVar1 = *(undefined8 *)(param_2 + 0x1c);
      puVar3[6] = *(undefined8 *)(param_2 + 0x18);
      puVar3[7] = uVar1;
      uVar1 = *(undefined8 *)(param_2 + 0x24);
      puVar3[8] = *(undefined8 *)(param_2 + 0x20);
      puVar3[9] = uVar1;
      uVar1 = *(undefined8 *)(param_2 + 0x2c);
      puVar3[10] = *(undefined8 *)(param_2 + 0x28);
      puVar3[0xb] = uVar1;
      uVar1 = *(undefined8 *)(param_2 + 0x34);
      puVar3[0xc] = *(undefined8 *)(param_2 + 0x30);
      puVar3[0xd] = uVar1;
      uVar1 = *(undefined8 *)(param_2 + 0x3c);
      puVar3[0xe] = *(undefined8 *)(param_2 + 0x38);
      puVar3[0xf] = uVar1;
      uVar1 = *(undefined8 *)(param_2 + 0x44);
      puVar3[0x10] = *(undefined8 *)(param_2 + 0x40);
      puVar3[0x11] = uVar1;
      uVar1 = *(undefined8 *)(param_2 + 0x4c);
      puVar3[0x12] = *(undefined8 *)(param_2 + 0x48);
      puVar3[0x13] = uVar1;
      uVar1 = *(undefined8 *)(param_2 + 0x54);
      puVar3[0x14] = *(undefined8 *)(param_2 + 0x50);
      puVar3[0x15] = uVar1;
      uVar1 = *(undefined8 *)(param_2 + 0x5c);
      puVar3[0x16] = *(undefined8 *)(param_2 + 0x58);
      puVar3[0x17] = uVar1;
      memmove(puVar3 + 0x18,*(void **)(param_1 + 0x28),*(size_t *)(param_1 + 0x20));
      ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x28),0x69637056);
      *(undefined8 **)(param_1 + 0x28) = puVar3;
      *(longlong *)(param_1 + 0x20) = lVar6;
      return uVar2;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000009a;
    }
    uVar7 = 0x18;
  }
  WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar4,1,uVar7,
                    &WPP_910e8a1cc1ab306ac66fc329452f92cd_Traceguids,param_2);
  return 0xc000009a;
}



===== VscProxyCheckDeviceCustomPrefix @ 140020e58 =====

ulonglong VscProxyCheckDeviceCustomPrefix(longlong param_1,ulonglong param_2)

{
  undefined **ppuVar1;
  
  if ((((param_2 & 1) == 0) && (param_2 >> 1 < 7)) && (param_2 != 0)) {
    if (*(short *)(param_1 + -2 + (param_2 >> 1) * 2) == 0) {
      return CONCAT71((uint7)(param_2 >> 9),1);
    }
    ppuVar1 = &WPP_RECORDER_INITIALIZED;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      ppuVar1 = (undefined **)
                WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x22,
                                 &WPP_910e8a1cc1ab306ac66fc329452f92cd_Traceguids);
    }
  }
  else {
    ppuVar1 = &WPP_RECORDER_INITIALIZED;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      ppuVar1 = (undefined **)
                WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x21,
                                  &WPP_910e8a1cc1ab306ac66fc329452f92cd_Traceguids,(char)param_2);
    }
  }
  return (ulonglong)ppuVar1 & 0xffffffffffffff00;
}



===== VscProxyGetDevice @ 140020f08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 VscProxyGetDevice(wchar_t *param_1,ulonglong param_2,longlong *param_3)

{
  longlong *plVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 uVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong *plVar10;
  undefined1 auStackY_1d8 [32];
  longlong local_198;
  longlong local_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  ulonglong local_160;
  undefined4 *puStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  ulonglong local_140;
  ulonglong local_138;
  longlong *local_130;
  undefined4 local_128;
  undefined1 local_124 [220];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1d8;
  local_198 = 0;
  local_140 = local_140 & 0xffffffff00000000;
  local_168 = 0;
  local_160 = 0;
  puStack_158 = (undefined4 *)0x0;
  local_150 = 0;
  uStack_148 = 0;
  local_188 = 0;
  uStack_180 = 0;
  local_178 = 0;
  uStack_170 = 0;
  local_138 = param_2;
  local_130 = param_3;
  memset(&local_128,0,0xe0);
  *param_3 = 0;
  lVar9 = 0;
  lVar6 = VpciCtrlDev;
  lVar5 = (**(code **)(WdfFunctions_01033 + 0x650))
                    (WdfDriverGlobals,VpciCtrlDev,
                     PTR__WDF_VPCI_VSC_CTRL_DEVICE_DATA_TYPE_INFO_140010018);
  plVar1 = (longlong *)(lVar5 + 0x10);
  plVar8 = (longlong *)*plVar1;
  if (plVar8 != plVar1) {
    do {
      (**(code **)(WdfFunctions_01033 + 0x9c8))(WdfDriverGlobals,plVar8[4],0);
      uVar7 = (**(code **)(WdfFunctions_01033 + 0x420))(WdfDriverGlobals,plVar8[2]);
      uStack_180 = 0;
      local_168 = 0;
      local_178 = 0;
      uStack_170 = 0;
      if (WdfClientVersionHigherThanFramework == '\0') {
        uVar2 = 0x28;
      }
      else if (WdfStructureCount < 4) {
        uVar2 = 0xffffffff;
      }
      else {
        uVar2 = *(undefined4 *)(WdfStructures + 0x18);
      }
      local_188 = CONCAT44(5,uVar2);
      (**(code **)(WdfFunctions_01033 + 0x30))(WdfDriverGlobals,uVar7,&local_188);
      do {
        while( true ) {
          do {
            local_198 = 0;
            memset(local_124,0,0xdc);
            local_128 = 0xe0;
            local_140 = 0;
            local_150 = 0;
            uStack_148 = 0;
            if (WdfClientVersionHigherThanFramework == '\0') {
              local_160 = 0x28;
            }
            else if (WdfStructureCount < 5) {
              local_160 = 0xffffffff;
            }
            else {
              local_160 = (ulonglong)*(uint *)(WdfStructures + 0x20);
            }
            puStack_158 = &local_128;
            plVar10 = &local_198;
            iVar3 = (**(code **)(WdfFunctions_01033 + 0x38))(WdfDriverGlobals,uVar7,&local_188);
            if (iVar3 < 0) {
              if ((iVar3 != -0x7fffffe6) &&
                 ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x13,
                                   &WPP_910e8a1cc1ab306ac66fc329452f92cd_Traceguids,(char)plVar8,
                                   (char)iVar3);
              }
              goto LAB_140021211;
            }
          } while (local_198 == 0);
          lVar6 = (**(code **)(WdfFunctions_01033 + 0x650))
                            (WdfDriverGlobals,local_198,
                             PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8);
          local_190 = 0;
          uVar4 = VscProxyIsSubString(param_1,local_138,(wchar_t *)(lVar6 + 0x24c),plVar10,
                                      &local_190);
          if (-1 < (int)uVar4) break;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x14,
                               &WPP_910e8a1cc1ab306ac66fc329452f92cd_Traceguids,(char)lVar6,
                               (char)uVar4);
          }
        }
      } while (local_190 == 0);
      lVar9 = local_198;
LAB_140021211:
      (**(code **)(WdfFunctions_01033 + 0x40))(WdfDriverGlobals,uVar7);
      lVar6 = plVar8[4];
      (**(code **)(WdfFunctions_01033 + 0x9d0))(WdfDriverGlobals);
    } while ((lVar9 == 0) && (plVar8 = (longlong *)*plVar8, plVar8 != plVar1));
    param_3 = local_130;
  }
  *param_3 = lVar9;
  if (lVar9 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar6,2,0x15,
                        &WPP_910e8a1cc1ab306ac66fc329452f92cd_Traceguids,param_1);
    }
    uVar7 = 0xc000000e;
  }
  else {
    uVar7 = 0;
  }
  return uVar7;
}



===== VscProxyInitialize @ 1400212e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int VscProxyInitialize(void)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  void *_Dst;
  undefined8 *puVar4;
  wchar_t *_Dst_00;
  undefined2 uVar5;
  void *pvVar6;
  int iVar7;
  undefined1 auStackY_c8 [32];
  uint local_88 [2];
  longlong local_80;
  longlong local_78;
  undefined8 local_70;
  undefined8 local_68;
  wchar_t *local_60;
  wchar_t local_58 [8];
  wchar_t local_48 [20];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_88[1] = 0;
  local_70 = 0;
  local_88[0] = 0;
  uVar3 = (**(code **)(WdfFunctions_01033 + 0x138))(WdfDriverGlobals,VpciCtrlDev);
  (**(code **)(WdfFunctions_01033 + 0x650))
            (WdfDriverGlobals,VpciCtrlDev,PTR__WDF_VPCI_VSC_CTRL_DEVICE_DATA_TYPE_INFO_140010018);
  local_78 = 0;
  local_80 = 0;
  _Dst = (void *)0x0;
  iVar2 = (**(code **)(WdfFunctions_01033 + 0xe18))(WdfDriverGlobals,uVar3,0x2001f,0);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140021600;
    uVar5 = 10;
  }
  else {
    builtin_wcsncpy(local_48,L"VirtualizedDevices",0x13);
    local_60 = local_48;
    local_68 = 0x260024;
    iVar2 = (**(code **)(WdfFunctions_01033 + 0x728))(WdfDriverGlobals,local_78,&local_68,0x2001f);
    if (iVar2 < 0) {
      if (((iVar2 == -0x3fffffc6) || (iVar2 == -0x3fffffcc)) || (iVar2 == -0x3ffffddb)) {
        iVar2 = 0;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140021600;
      uVar5 = 0xb;
    }
    else {
      uVar3 = (**(code **)(WdfFunctions_01033 + 0x740))(WdfDriverGlobals,local_80);
      _Dst = (void *)ExAllocatePool2(0x100,0x24,0x69637056);
      if (_Dst != (void *)0x0) {
        iVar7 = 0;
        RtlSetVolatileMemory(_Dst,0,0x24);
        RtlSetVolatileMemory(local_58,0,0xc);
        while( true ) {
          pvVar6 = _Dst;
          iVar2 = ZwEnumerateKey(uVar3,iVar7,0);
          if (iVar2 == -0x7fffffe6) break;
          if (iVar2 != -0x7ffffffb) {
            if (iVar2 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
              goto LAB_140021600;
              uVar5 = 0xd;
              goto LAB_1400213c5;
            }
            uVar1 = *(uint *)((longlong)_Dst + 0xc);
            if ((((uVar1 & 1) == 0) && ((uVar1 & 0xfffffffe) < 0xb)) && (uVar1 != 0)) {
              _Dst_00 = local_58;
              memmove(_Dst_00,(void *)((longlong)_Dst + 0x10),(ulonglong)uVar1);
              iVar2 = VscReadRegistryValue
                                ((ulonglong)_Dst_00,local_58,uVar3,pvVar6,&local_70,local_88);
              if (-1 < iVar2) {
                puVar4 = VscGetOrCreateProxy(local_58,'\0','\x01');
                if (puVar4 == (undefined8 *)0x0) {
                  iVar2 = -0x3fffff66;
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
                  goto LAB_140021600;
                  uVar5 = 0xe;
                  goto LAB_1400214ff;
                }
                puVar4[5] = local_70;
                puVar4[4] = (ulonglong)local_88[0];
              }
            }
          }
          iVar7 = iVar7 + 1;
          RtlSetVolatileMemory(_Dst,0,0x24);
          RtlSetVolatileMemory(local_58,0,0xc);
        }
        iVar2 = 0;
        goto LAB_140021600;
      }
      iVar2 = -0x3fffff66;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140021600;
      uVar5 = 0xc;
LAB_1400214ff:
      iVar2 = -0x3fffff66;
    }
  }
LAB_1400213c5:
  WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar5,
                    &WPP_910e8a1cc1ab306ac66fc329452f92cd_Traceguids,(char)iVar2);
LAB_140021600:
  if (local_80 != 0) {
    (**(code **)(WdfFunctions_01033 + 0x738))(WdfDriverGlobals);
    local_80 = 0;
  }
  if (local_78 != 0) {
    (**(code **)(WdfFunctions_01033 + 0x738))(WdfDriverGlobals);
    local_78 = 0;
  }
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0x69637056);
  }
  return iVar2;
}



===== VscProxyRemoveDevicePath @ 1400216e0 =====

uint VscProxyRemoveDevicePath(longlong param_1,wchar_t *param_2,wchar_t *param_3,undefined8 param_4)

{
  void *_Src;
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  wchar_t *pwVar4;
  undefined2 uVar5;
  void *local_res18;
  void **in_stack_ffffffffffffffd8;
  
  local_res18 = (void *)0x0;
  pwVar4 = param_2;
  if ((*(wchar_t **)(param_1 + 0x28) == (wchar_t *)0x0) ||
     (pwVar4 = *(wchar_t **)(param_1 + 0x20), pwVar4 == (wchar_t *)0x0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc0000225;
    }
    uVar5 = 0x19;
  }
  else {
    in_stack_ffffffffffffffd8 = &local_res18;
    param_3 = param_2;
    uVar3 = VscProxyIsSubString(*(wchar_t **)(param_1 + 0x28),(ulonglong)pwVar4,param_2,param_4,
                                in_stack_ffffffffffffffd8);
    if ((int)uVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar3;
      }
      WPP_RECORDER_SF_Sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pwVar4,1,0x1a,
                         &WPP_910e8a1cc1ab306ac66fc329452f92cd_Traceguids,param_2,(char)uVar3);
      return uVar3;
    }
    if (local_res18 != (void *)0x0) {
      uVar1 = *(ulonglong *)(param_1 + 0x20);
      _Src = (void *)((longlong)local_res18 + 0xc0);
      lVar2 = *(longlong *)(param_1 + 0x28);
      if (_Src < (void *)((uVar1 & 0xfffffffffffffffe) + lVar2)) {
        memmove(local_res18,_Src,uVar1 + ((longlong)_Src - lVar2 >> 1) * -2);
        *(ulonglong *)(param_1 + 0x20) = uVar1 - 0xc0;
        return uVar3;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_SS(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),_Src,lVar2,0x1c,
                           in_stack_ffffffffffffffd8,param_2,(wchar_t *)(param_1 + 0x10));
      }
      return 0xc00000e5;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc0000225;
    }
    uVar5 = 0x1b;
  }
  WPP_RECORDER_SF_SS(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pwVar4,param_3,uVar5,
                     in_stack_ffffffffffffffd8,param_2,(wchar_t *)(param_1 + 0x10));
  return 0xc0000225;
}



===== VscProxyWriteDevicePathsToRegistry @ 140021878 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140021b20) */
/* WARNING: Removing unreachable block (ram,0x000140021af9) */
/* WARNING: Removing unreachable block (ram,0x000140021b47) */

int VscProxyWriteDevicePathsToRegistry(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined2 uVar3;
  undefined1 auStackY_d8 [32];
  undefined8 local_70;
  wchar_t *local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  wchar_t local_40 [20];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_50 = 0;
  uStack_48 = 0;
  local_60 = 0;
  uStack_58 = 0;
  if ((*(longlong *)(param_1 + 0x28) == 0) || (*(char *)(param_1 + 0x1c) != '\0')) {
    return 0;
  }
  uVar2 = (**(code **)(WdfFunctions_01033 + 0x138))(WdfDriverGlobals,VpciCtrlDev);
  iVar1 = (**(code **)(WdfFunctions_01033 + 0xe18))(WdfDriverGlobals,uVar2,0x2001f,0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar3 = 0xf;
  }
  else {
    builtin_wcsncpy(local_40,L"VirtualizedDevices",0x13);
    local_68 = local_40;
    local_70 = 0x260024;
    iVar1 = (**(code **)(WdfFunctions_01033 + 0x730))(WdfDriverGlobals,0,&local_70,0x2001f);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      uVar3 = 0x10;
    }
    else {
      RtlInitUnicodeString(&local_60,param_1 + 0x10);
      iVar1 = (**(code **)(WdfFunctions_01033 + 0x730))(WdfDriverGlobals,0,&local_60,0x2001f);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar1;
        }
        uVar3 = 0x11;
      }
      else {
        RtlInitUnicodeString(&local_50,DevicePathsValueName);
        iVar1 = (**(code **)(WdfFunctions_01033 + 0x788))(WdfDriverGlobals,0,&local_50,7);
        if (-1 < iVar1) {
          return iVar1;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar1;
        }
        uVar3 = 0x12;
      }
    }
  }
  WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar3,
                    &WPP_910e8a1cc1ab306ac66fc329452f92cd_Traceguids,(char)iVar1);
  return iVar1;
}



===== VpciInitializeResetInterface @ 140021b94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int VpciInitializeResetInterface(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 *local_80;
  undefined *local_78;
  undefined8 local_70;
  undefined8 local_68;
  ulonglong local_60;
  undefined4 local_58 [2];
  longlong local_50;
  code *local_48;
  code *local_40;
  code *local_38;
  undefined4 local_30;
  
  local_70 = 0;
  local_60 = local_60 & 0xffffffff00000000;
  local_84 = 0;
  memset(local_58,0,0x50);
  lVar2 = (**(code **)(WdfFunctions_01033 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8);
  if ((*(uint *)(*(longlong *)(lVar2 + 0x30) + 0x18) < 0x10005) &&
     (*(char *)(lVar2 + 0x341) == '\0')) {
    iVar1 = 0;
  }
  else {
    RtlSetVolatileMemory(local_58,0,0x50);
    local_84 = 0;
    local_70 = 0;
    local_60 = 0;
    local_48 = _guard_check_icall;
    local_40 = _guard_check_icall;
    local_38 = VpciDeviceResetHandler;
    local_58[0] = 0x10050;
    local_30 = 1;
    if (WdfClientVersionHigherThanFramework == '\0') {
      local_88 = 0x30;
    }
    else if (WdfStructureCount < 0x2e) {
      local_88 = 0xffffffff;
    }
    else {
      local_88 = *(undefined4 *)(WdfStructures + 0x168);
    }
    local_68 = 0;
    local_80 = local_58;
    local_78 = &GUID_DEVICE_RESET_INTERFACE_STANDARD;
    local_50 = lVar2;
    iVar1 = (**(code **)(WdfFunctions_01033 + 0x720))(WdfDriverGlobals,param_1,&local_88);
    if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,10,
                         &WPP_079066883c61371324bd973f6b7fcbe6_Traceguids,(char)lVar2,(char)iVar1);
    }
  }
  return iVar1;
}



===== VpciInitializeSecurityInterface @ 140021d3c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int VpciInitializeSecurityInterface(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 *local_60;
  undefined *local_58;
  undefined8 local_50;
  undefined8 local_48;
  ulonglong local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  code *local_28;
  code *pcStack_20;
  undefined8 local_18;
  code *pcStack_10;
  
  local_50 = 0;
  local_40 = local_40 & 0xffffffff00000000;
  local_64 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = (code *)0x0;
  pcStack_20 = (code *)0x0;
  local_18 = 0;
  pcStack_10 = (code *)0x0;
  uVar2 = (**(code **)(WdfFunctions_01033 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_VPCI_PDO_CONTEXT_TYPE_INFO_1400100b8);
  RtlSetVolatileMemory(&local_38,0,0x30);
  local_64 = 0;
  local_50 = 0;
  local_40 = 0;
  local_28 = _guard_check_icall;
  pcStack_20 = _guard_check_icall;
  pcStack_10 = VpciSetAcs;
  local_38 = CONCAT44(local_38._4_4_,0x20030);
  local_18 = 0x100000000;
  if (WdfClientVersionHigherThanFramework == '\0') {
    local_68 = 0x30;
  }
  else if (WdfStructureCount < 0x2e) {
    local_68 = 0xffffffff;
  }
  else {
    local_68 = *(undefined4 *)(WdfStructures + 0x168);
  }
  local_48 = 0;
  local_60 = &local_38;
  local_58 = &GUID_PCI_SECURITY_INTERFACE;
  uStack_30 = uVar2;
  iVar1 = (**(code **)(WdfFunctions_01033 + 0x720))(WdfDriverGlobals,param_1,&local_68);
  if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,10,
                       &WPP_51cbb062f1703c1c01a012402ec4f923_Traceguids,(char)uVar2,(char)iVar1);
  }
  return iVar1;
}



===== VscReadRegistryValue @ 140021ed8 =====

int VscReadRegistryValue
              (ulonglong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined8 *param_5,uint *param_6)

{
  undefined8 *puVar1;
  int iVar2;
  longlong lVar3;
  void *_Dst;
  undefined8 *puVar4;
  ulonglong local_res8;
  uint local_res20 [2];
  ulonglong in_stack_ffffffffffffff78;
  undefined4 uVar5;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  
  puVar1 = param_5;
  local_2c = 0;
  lVar3 = 0;
  param_5 = (undefined8 *)0x0;
  *puVar1 = 0;
  local_res20[0] = 0;
  local_res8 = param_1 & 0xffffffff00000000;
  local_44 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  RtlInitUnicodeString(&local_58);
  local_38 = &local_58;
  local_48 = 0x30;
  local_30 = 0x240;
  local_28 = 0;
  uStack_20 = 0;
  local_40 = param_3;
  iVar2 = ZwOpenKey(&param_5,0x20019,&local_48);
  if (-1 < iVar2) {
    RtlInitUnicodeString(&local_68,DevicePathsValueName);
    in_stack_ffffffffffffff78 = in_stack_ffffffffffffff78 & 0xffffffff00000000;
    iVar2 = ZwQueryValueKey(param_5,&local_68,2,0,in_stack_ffffffffffffff78,local_res20);
    uVar5 = (undefined4)(in_stack_ffffffffffffff78 >> 0x20);
    if (iVar2 == -0x3fffffdd) {
      lVar3 = ExAllocatePool2(0x100,local_res20[0],0x69637056);
      if (lVar3 != 0) {
        puVar4 = &local_68;
        iVar2 = ZwQueryValueKey(param_5,puVar4,2,lVar3,CONCAT44(uVar5,local_res20[0]),&local_res8);
        if (iVar2 < 0) goto LAB_140022107;
        if (*(int *)(lVar3 + 4) != 7) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar4,1,0xb,
                               &WPP_08207c71cde43f75e71a944b2bfed129_Traceguids,
                               (char)*(int *)(lVar3 + 4),7);
          }
          iVar2 = -0x3ffffff3;
          goto LAB_140022107;
        }
        local_res20[0] = local_res20[0] - 0xc;
        _Dst = (void *)ExAllocatePool2(0x100,local_res20[0],0x69637056);
        *puVar1 = _Dst;
        if (_Dst != (void *)0x0) {
          memmove(_Dst,(void *)(lVar3 + 0xc),(ulonglong)local_res20[0]);
          if (param_6 != (uint *)0x0) {
            *param_6 = local_res20[0];
          }
          goto LAB_140022107;
        }
      }
      iVar2 = -0x3fffff66;
    }
    else if (-1 < iVar2) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,10,
                         &WPP_08207c71cde43f75e71a944b2bfed129_Traceguids);
      }
      iVar2 = -0x3fffffff;
    }
  }
LAB_140022107:
  if (param_5 != (undefined8 *)0x0) {
    ZwClose();
    param_5 = (undefined8 *)0x0;
  }
  if (lVar3 != 0) {
    ExFreePoolWithTag(lVar3,0x69637056);
  }
  return iVar2;
}



===== __security_init_cookie @ 140023008 =====

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



===== DriverEntry @ 14002303c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined8 *param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  undefined1 auStackY_e8 [32];
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 *local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  ulonglong uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_60 = 0;
  local_80 = 0;
  uStack_78 = 0;
  uStack_58 = uStack_58 & 0xffffffff00000000;
  local_70 = (undefined8 *)0x0;
  uStack_68 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  wil_InitializeFeatureStaging();
  VpciFdoCount = 0;
  DAT_1400109e8 = &WPP_ThisDir_CTLGUID_VpciDriverTraceGuid;
  _WPP_MAIN_CB = 0;
  DAT_1400109f0 = 0;
  _DAT_140010a00 = 0;
  _DAT_140010a08 = 1;
  _DAT_140010a20 = 0;
  _DAT_140010a28 = 0;
  WppLoadTracingSupport();
  _DAT_140010a00 = 0;
  WppInitKm(param_1,param_2);
  uVar3 = Feature_VpciVscBootDiskHibernation__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 != 0) {
    local_40 = CONCAT35(local_40._5_3_,0x100000010);
    uStack_38 = 0x100000001;
    imp_WppRecorderConfigure(WPP_GLOBAL_Control,&local_40);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,10,
                     &WPP_22a9fd12f6cd35a16fbcc6041c1a0b1b_Traceguids);
  }
  KeInitializeEvent(&VpciGlobalLock,1,1);
  puVar4 = param_1;
  iVar2 = (**(code **)(WdfFunctions_01033 + 0x3a0))(WdfDriverGlobals,param_1,param_2,0);
  if (iVar2 < 0) {
    WppCleanupKm(param_1);
  }
  else {
    iVar2 = PnpBlockerInit();
    if (-1 < iVar2) {
      puVar4 = (undefined8 *)0x0;
      iVar2 = IoRegisterPlugPlayNotification(4,0,0,param_1);
      if (iVar2 < 0) {
        if ((iVar2 != -0x3fffff45) && (iVar2 != -0x3ffffffe)) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar4,1,0xc,
                              &WPP_22a9fd12f6cd35a16fbcc6041c1a0b1b_Traceguids,(char)iVar2);
          }
          goto LAB_14002321a;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0xb,
                           &WPP_22a9fd12f6cd35a16fbcc6041c1a0b1b_Traceguids);
        }
        VpciKsrNotificationEntry = 0;
      }
      RtlInitUnicodeString(&local_50,L"\\Callback\\PowerState");
      local_70 = &local_50;
      local_80 = CONCAT44(local_80._4_4_,0x30);
      uStack_78 = 0;
      uStack_68 = CONCAT44(uStack_68._4_4_,0x50);
      puVar4 = &local_80;
      local_60 = 0;
      uStack_58 = 0;
      iVar2 = ExCreateCallback(&PowerCallbackObj,puVar4,0,1);
      if (-1 < iVar2) {
        PowerCallbackRegistrationHandle =
             ExRegisterCallback(PowerCallbackObj,VpciPowerStateCallback,0);
        g_MsiNextProc = 0;
        return iVar2;
      }
    }
  }
LAB_14002321a:
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
  if (VpciKsrNotificationEntry != 0) {
    iVar1 = IoUnregisterPlugPlayNotificationEx();
    if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar4,1,0xd,
                        &WPP_22a9fd12f6cd35a16fbcc6041c1a0b1b_Traceguids,(char)iVar1);
    }
    VpciKsrNotificationEntry = 0;
  }
  return iVar2;
}



===== wil_InitializeFeatureStaging @ 140023428 =====

int wil_InitializeFeatureStaging(void)

{
  bool bVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined8 local_res8;
  
  bVar1 = false;
  if (g_wil_details_isFeatureStagingInitialized == 0) {
    g_wil_details_isFeatureStagingInitialized = 1;
    local_res8 = RtlQueryFeatureConfigurationChangeStamp();
    wil_details_PopulateInitialConfiguredFeatureStates();
    wil_details_EvaluateFeatureDependencies();
    for (ppuVar3 = &Feature_VpciInterruptTargetFix__private_descriptor;
        ppuVar3 < &wil_details_featureDescriptors_z; ppuVar3 = ppuVar3 + 1) {
      if (*ppuVar3 != (undefined *)0x0) goto LAB_1400234af;
    }
LAB_1400234e9:
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
LAB_1400234af:
  if (ppuVar3 == (undefined **)0x0) goto LAB_1400234e9;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    iVar2 = RtlRegisterFeatureConfigurationChangeNotification
                      (wil_details_ReevaluateOnFeatureConfigurationChange,0,&local_res8,
                       &g_wil_details_featureChangeNotification);
    if (iVar2 == 0) {
      bVar1 = true;
    }
    else {
      g_wil_details_featureChangeNotification = 0;
    }
    goto LAB_1400234e9;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_14000f9ff < ppuVar3) goto LAB_1400234e9;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_1400234af;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14002353c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  ulonglong *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined **ppuVar4;
  undefined1 auStack_48 [32];
  ulonglong local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  ppuVar4 = &Feature_VpciInterruptTargetFix__private_descriptor;
  while( true ) {
    if (&wil_details_featureDescriptors_z <= ppuVar4) {
      return;
    }
    if (*ppuVar4 != (undefined *)0x0) break;
    ppuVar4 = ppuVar4 + 1;
  }
  do {
    if (ppuVar4 == (undefined **)0x0) {
      return;
    }
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    if ((*(char *)((longlong)ppuVar4 + 0x1d) == '\0') &&
       (*(char *)((longlong)ppuVar4 + 0x1e) == '\0')) {
      iVar3 = RtlQueryFeatureConfiguration
                        (*(undefined4 *)(ppuVar4 + 3),
                         1 < (byte)(*(char *)((longlong)ppuVar4 + 0x1c) - 2U),&local_28,&local_20);
      if (iVar3 == -0x7fffffde) {
        do {
          puVar2 = (undefined8 *)*ppuVar4;
          ppuVar4 = ppuVar4 + 7;
          *puVar2 = 0x206;
          while( true ) {
            if (&UNK_14000f9ff < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_140023626;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_140023626;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_140023626:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_14000f9ff < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


