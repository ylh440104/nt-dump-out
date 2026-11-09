
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



===== __report_rangecheckfailure @ 140001020 =====

void __report_rangecheckfailure(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(8);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __GSHandlerCheck @ 140001030 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140001054 =====

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



===== __cpu_features_init @ 1400010d0 =====

/* WARNING: Removing unreachable block (ram,0x00014000113a) */
/* WARNING: Removing unreachable block (ram,0x0001400010e9) */
/* WARNING: Removing unreachable block (ram,0x0001400010da) */

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



===== ext_ms_win_ntos_ksr_l1_1_5_KsrPersistMemory @ 1400011a0 =====

undefined8 ext_ms_win_ntos_ksr_l1_1_5_KsrPersistMemory(void)

{
  return 0xc00000bb;
}



===== McGenControlCallbackV2 @ 1400011b0 =====

void McGenControlCallbackV2
               (undefined8 param_1,int param_2,undefined1 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,longlong param_7)

{
  uint *puVar1;
  ulonglong uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  if (param_7 != 0) {
    if (param_2 == 0) {
      *(undefined4 *)(param_7 + 0x24) = 0;
      *(undefined1 *)(param_7 + 0x28) = 0;
      *(undefined8 *)(param_7 + 0x10) = 0;
      *(undefined8 *)(param_7 + 0x18) = 0;
      if (*(ushort *)(param_7 + 0x2a) != 0) {
        iVar4 = *(ushort *)(param_7 + 0x2a) - 1;
        memset(*(void **)(param_7 + 0x30),0,
               (longlong)(((int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5) + 1) << 2);
      }
    }
    else if (param_2 == 1) {
      *(undefined1 *)(param_7 + 0x28) = param_3;
      uVar7 = 0;
      *(undefined8 *)(param_7 + 0x18) = param_5;
      *(undefined8 *)(param_7 + 0x10) = param_4;
      *(undefined4 *)(param_7 + 0x24) = 1;
      if (*(short *)(param_7 + 0x2a) != 0) {
        do {
          uVar2 = *(ulonglong *)(*(longlong *)(param_7 + 0x38) + uVar7 * 8);
          if (((*(byte *)(param_7 + 0x28) < *(byte *)(uVar7 + *(longlong *)(param_7 + 0x40))) &&
              (*(byte *)(param_7 + 0x28) != 0)) ||
             ((uVar2 != 0 &&
              (((*(ulonglong *)(param_7 + 0x10) & uVar2) == 0 ||
               ((*(ulonglong *)(param_7 + 0x18) & uVar2) != *(ulonglong *)(param_7 + 0x18))))))) {
            bVar3 = false;
          }
          else {
            bVar3 = true;
          }
          uVar5 = 1 << ((byte)uVar7 & 0x1f);
          puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (uVar7 >> 5) * 4);
          uVar6 = *puVar1;
          if (bVar3) {
            uVar5 = uVar5 | uVar6;
          }
          else {
            uVar5 = ~uVar5 & uVar6;
          }
          *puVar1 = uVar5;
          uVar6 = (int)uVar7 + 1;
          uVar7 = (ulonglong)uVar6;
        } while (uVar6 < *(ushort *)(param_7 + 0x2a));
      }
    }
  }
  return;
}



===== McGenEventRegister_EtwRegister @ 1400012c0 =====

void McGenEventRegister_EtwRegister(void)

{
  if (EhStorTcgDrv_Context == 0) {
    EtwRegister(&EhStorTcgDrv,McGenControlCallbackV2,&EhStorTcgDrv_Context,&EhStorTcgDrv_Context);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 140001300 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (EhStorTcgDrv_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    EhStorTcgDrv_Context = 0;
  }
  return uVar1;
}



===== WPP_SF_D @ 140001334 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WppClassicProviderCallback @ 140001380 =====

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



===== wil_details_RecordCachedUsage @ 1400013b4 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140001510 =====

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



===== DefaultQueueEvtDeviceControl @ 1400015a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DefaultQueueEvtDeviceControl
               (undefined8 param_1,undefined *param_2,undefined8 param_3,undefined8 param_4,
               uint param_5)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined *puVar5;
  undefined *puVar6;
  char *pcVar7;
  undefined1 uVar8;
  
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  puVar6 = PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar3);
  if ((*(uint *)(lVar4 + 0x1860) & 1) != 0) {
LAB_140001bfd:
    ForwardRequestToLocalIoTarget(param_2);
    return;
  }
  if (param_5 < 0x2dd491) {
    if (param_5 == 0x2dd490) {
      if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) != 0) {
        McTemplateK0siiii_EtwWriteTransfer
                  (0x2dd490,&IoctlCreateBandStart,puVar6,"IoctlCreateBandStart",0,0);
      }
      IoctlCreateBand(uVar3,param_2);
      if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) == 0) {
        return;
      }
      pcVar7 = "IoctlCreateBandStop";
      uVar8 = 0;
      puVar5 = &IoctlCreateBandStop;
    }
    else {
      if (((param_5 == 0x2d1400) || (param_5 == 0x2d1410)) || (param_5 == 0x2d1424))
      goto LAB_140001bfd;
      if (param_5 == 0x2d1480) {
        if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) != 0) {
          McTemplateK0siiii_EtwWriteTransfer
                    (0x2dd490,&IoctlQueryCapsStart,puVar6,"IoctlQueryCapsStart",0,0);
        }
        uVar1 = IoctlQueryCapabilities(uVar3,(longlong)param_2);
        uVar8 = (undefined1)uVar1;
        if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) == 0) {
          return;
        }
        pcVar7 = "IoctlQueryCapsStop";
        puVar5 = &IoctlQueryCapsStop;
      }
      else if (param_5 == 0x2d148c) {
        if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) != 0) {
          McTemplateK0siiii_EtwWriteTransfer
                    (0x2dd490,&IoctlEnumBandsStart,puVar6,"IoctlEnumBandsStart",0,0);
        }
        IoctlEnumerateBands(uVar3,param_2);
        if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) == 0) {
          return;
        }
        pcVar7 = "IoctlEnumBandsStop";
        uVar8 = 0;
        puVar5 = &IoctlEnumBandsStop;
      }
      else if (param_5 == 0x2d149c) {
        if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) != 0) {
          McTemplateK0siiii_EtwWriteTransfer
                    (0x2dd490,&IoctlGetBandMetadataStart,puVar6,"IoctlGetBandMetadataStart",0,0);
        }
        IoctlGetBandMetadata(uVar3,param_2);
        if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) == 0) {
          return;
        }
        pcVar7 = "IoctlGetBandMetadataStop";
        uVar8 = 0;
        puVar5 = &IoctlGetBandMetadataStop;
      }
      else if (param_5 == 0x2dd484) {
        if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) != 0) {
          McTemplateK0siiii_EtwWriteTransfer
                    (0x2dd490,&IoctlActivateStart,puVar6,"IoctlActivateStart",0,0);
        }
        puVar6 = (undefined *)CONCAT71((int7)((ulonglong)puVar6 >> 8),1);
        uVar1 = IoctlActivateRevertLockingSp(uVar3,param_2,'\x01');
        uVar8 = (undefined1)uVar1;
        if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) == 0) {
          return;
        }
        pcVar7 = "IoctlActivateStop";
        puVar5 = &IoctlActivateStop;
      }
      else {
        if (param_5 != 0x2dd488) goto LAB_1400018cd;
        if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) != 0) {
          McTemplateK0siiii_EtwWriteTransfer
                    (0x2dd490,&IoctlRevertStart,puVar6,"IoctlRevertStart",0,0);
        }
        puVar6 = (undefined *)0x0;
        uVar1 = IoctlActivateRevertLockingSp(uVar3,param_2,'\0');
        uVar8 = (undefined1)uVar1;
        if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) == 0) {
          return;
        }
        pcVar7 = "IoctlRevertStop";
        puVar5 = &IoctlRevertStop;
      }
    }
  }
  else if (param_5 == 0x2dd494) {
    if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) != 0) {
      McTemplateK0siiii_EtwWriteTransfer
                (0x2dd490,&IoctlSetBandLocStart,puVar6,"IoctlSetBandLocStart",0,0);
    }
    IoctlSetBandLocation(uVar3,param_2);
    if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) == 0) {
      return;
    }
    pcVar7 = "IoctlSetBandLocStop";
    uVar8 = 0;
    puVar5 = &IoctlSetBandLocStop;
  }
  else if (param_5 == 0x2dd498) {
    if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) != 0) {
      McTemplateK0siiii_EtwWriteTransfer
                (0x2dd490,&IoctlSetBandSecStart,puVar6,"IoctlSetBandSecStart",0,0);
    }
    IoctlSetBandSecurity(uVar3,param_2);
    if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) == 0) {
      return;
    }
    pcVar7 = "IoctlSetBandSecStop";
    uVar8 = 0;
    puVar5 = &IoctlSetBandSecStop;
  }
  else if (param_5 == 0x2dd4a0) {
    if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) != 0) {
      McTemplateK0siiii_EtwWriteTransfer
                (0x2dd490,&IoctlSetBandMetadataStart,puVar6,"IoctlSetBandMetadataStart",0,0);
    }
    IoctlSetBandMetadata(uVar3,param_2);
    if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) == 0) {
      return;
    }
    pcVar7 = "IoctlSetBandMetadataStop";
    uVar8 = 0;
    puVar5 = &IoctlSetBandMetadataStop;
  }
  else if (param_5 == 0x2dd4a4) {
    if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) != 0) {
      McTemplateK0siiii_EtwWriteTransfer(0x2dd490,&IoctlDelBandStart,puVar6,"IoctlDelBandStart",0,0)
      ;
    }
    IoctlDeleteBand(uVar3,param_2);
    if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) == 0) {
      return;
    }
    pcVar7 = "IoctlDelBandStop";
    uVar8 = 0;
    puVar5 = &IoctlDelBandStop;
  }
  else if (param_5 == 0x2dd4a8) {
    if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) != 0) {
      McTemplateK0siiii_EtwWriteTransfer
                (0x2dd490,&IoctlEraseBandStart,puVar6,"IoctlEraseBandStart",0,0);
    }
    IoctlEraseBand(uVar3,param_2);
    if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) == 0) {
      return;
    }
    pcVar7 = "IoctlEraseBandStop";
    uVar8 = 0;
    puVar5 = &IoctlEraseBandStop;
  }
  else if (param_5 == 0x2dd4ac) {
    if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) != 0) {
      McTemplateK0siiii_EtwWriteTransfer(0x2dd490,&IoctlSetSidStart,puVar6,"IoctlSetSidStart",0,0);
    }
    IoctlSetSid(uVar3,param_2);
    if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) == 0) {
      return;
    }
    pcVar7 = "IoctlSetSidStop";
    uVar8 = 0;
    puVar5 = &IoctlSetSidStop;
  }
  else {
    if (param_5 != 0x2dd4b0) {
      if (param_5 == 0x46c800) {
        if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) != 0) {
          McTemplateK0siiii_EtwWriteTransfer
                    (0x2dd490,&IoctlRelinquishStart,puVar6,"IoctlRelinquishStart",0,0);
        }
        iVar2 = IoctlRelinquishSilo(uVar3,param_2);
        if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) != 0) {
          param_2 = &IoctlRelinquishStop;
          McTemplateK0siiii_EtwWriteTransfer
                    (uVar3,&IoctlRelinquishStop,puVar6,"IoctlRelinquishStop",0,0);
        }
        if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 2) == 0) {
          return;
        }
        McTemplateK0sdddd_EtwWriteTransfer(uVar3,param_2,puVar6,"Relinquish",(char)iVar2,0);
        return;
      }
LAB_1400018cd:
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc0000010);
      return;
    }
    if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) != 0) {
      McTemplateK0siiii_EtwWriteTransfer
                (0x2dd490,&IoctlEraseAllBandsStart,puVar6,"IoctlEraseAllBandsStart",0,0);
    }
    IoctlEraseAllBands(uVar3,param_2);
    if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) == 0) {
      return;
    }
    pcVar7 = "IoctlEraseAllBandsStop";
    uVar8 = 0;
    puVar5 = &IoctlEraseAllBandsStop;
  }
  McTemplateK0siiii_EtwWriteTransfer(uVar3,puVar5,puVar6,pcVar7,uVar8,0);
  return;
}



===== DefaultQueueEvtInternalDeviceControl @ 140001c20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DefaultQueueEvtInternalDeviceControl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               int param_5)

{
  undefined8 uVar1;
  longlong lVar2;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar1,PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018)
  ;
  if ((*(uint *)(lVar2 + 0x1860) & 1) == 0) {
    if (param_5 == 0x2dd448) {
      IoctlPerformAuthentication(uVar1,param_2);
    }
    else {
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc0000010);
    }
  }
  else {
    ForwardRequestToLocalIoTarget(param_2);
  }
  return;
}



===== DeviceEvtBugcheckHandler @ 140001ce0 =====

void DeviceEvtBugcheckHandler(longlong param_1,uint param_2)

{
  if (((0x1b67 < param_2) && (param_1 != 0)) && (param_2 == 0x1b68)) {
    EraseBandKeyTable(param_1,'\x01');
  }
  return;
}



===== DeviceEvtD0Entry @ 140001d10 =====

undefined8 DeviceEvtD0Entry(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 2) != 0) {
    McTemplateK0sdddd_EtwWriteTransfer(param_1,param_2,param_3,"D0Entry",0,(char)param_2);
  }
  return 0;
}



===== DeviceEvtD0Exit @ 140001d40 =====

undefined8 DeviceEvtD0Exit(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 2) != 0) {
    McTemplateK0sdddd_EtwWriteTransfer(param_1,param_2,param_3,"D0Exit",0,(char)param_2);
  }
  return 0;
}



===== DeviceEvtWdmPnpIrpPreprocess @ 140001d70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 DeviceEvtWdmPnpIrpPreprocess(undefined8 param_1,longlong param_2)

{
  int iVar1;
  longlong *plVar2;
  undefined8 uVar3;
  undefined8 local_res10;
  undefined8 local_58;
  code *pcStack_50;
  ulonglong local_48;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined *local_10;
  
  local_res10 = 0;
  local_10 = (undefined *)((ulonglong)local_10 & 0xffffffff00000000);
  local_48 = local_48 & 0xffffffff00000000;
  local_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  local_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  local_58 = 0;
  pcStack_50 = (code *)0x0;
  if ((**(char **)(param_2 + 0xb8) == '\x1b') && ((*(char **)(param_2 + 0xb8))[1] == '\0')) {
    uStack_2c = 0;
    uStack_18 = 0;
    local_10 = PTR__WDF_PNP_IRP_WORKITEM_CONTEXT_TYPE_INFO_140019090;
    pcStack_50 = DevicePreprocessStartIrp;
    uStack_3c = 0;
    uStack_38 = 0;
    uStack_34 = 0;
    local_30 = 0;
    local_40 = 0x38;
    uStack_28 = 0x100000001;
    local_58 = 0x18;
    local_48 = 1;
    local_20 = param_1;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0xbd8))
                      (WdfDriverGlobals,&local_58,&local_40,&local_res10);
    if (-1 < iVar1) {
      plVar2 = (longlong *)
               (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,local_res10,
                          PTR__WDF_PNP_IRP_WORKITEM_CONTEXT_TYPE_INFO_140019090);
      *plVar2 = param_2;
      (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,local_res10);
      return 0x103;
    }
  }
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,param_1,param_2);
  return uVar3;
}



===== DeviceEvtWdmPowerIrpPreprocess @ 140001ee0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DeviceEvtWdmPowerIrpPreprocess(undefined8 param_1,longlong param_2)

{
  (**(code **)(WdfFunctions_01015 + 0xc20))(WdfDriverGlobals,param_1);
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,param_1,param_2);
  return;
}



===== ForwardRequestToLocalIoTarget @ 140001f4c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 ForwardRequestToLocalIoTarget(undefined8 param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined1 auStack_58 [48];
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  uVar2 = 0;
  local_20 = 0;
  local_28 = 0x10;
  local_24 = 8;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals);
  cVar1 = (**(code **)(WdfFunctions_01015 + 0x7e8))(WdfDriverGlobals,param_1,uVar3,&local_28);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_1);
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,uVar2);
  }
  return uVar2;
}



===== GetSectorSize @ 140002024 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GetSectorSize(undefined8 param_1,undefined4 *param_2)

{
  int iVar1;
  longlong lVar2;
  ulonglong local_res10 [3];
  undefined8 local_18;
  undefined1 local_10 [8];
  
  local_res10[0] = 0;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  local_18 = 0;
  *param_2 = 0;
  iVar1 = IssueSyncIoctl(*(undefined8 *)(lVar2 + 0x1870),*(undefined8 **)(lVar2 + 0x1878),'\0',
                         0x2d1418,0,0,(longlong)&local_18,8,local_res10);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
               &WPP_4e134a1eefcb3ea5ae96fc03a980aa94_Traceguids,iVar1);
    }
  }
  else if ((local_res10[0] < 8) ||
          ((undefined1 *)((longlong)local_res10 + ((local_18 & 0xffffffff) - 0x28)) < local_10)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                &WPP_4e134a1eefcb3ea5ae96fc03a980aa94_Traceguids,(int)local_18,8);
    }
    iVar1 = -0x3fffff1b;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
               &WPP_4e134a1eefcb3ea5ae96fc03a980aa94_Traceguids,local_18._4_4_);
    }
    *param_2 = local_18._4_4_;
  }
  return iVar1;
}



===== IssueSyncIoctl @ 140002190 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int IssueSyncIoctl(undefined8 param_1,undefined8 *param_2,char param_3,undefined4 param_4,
                  longlong param_5,undefined4 param_6,longlong param_7,undefined4 param_8,
                  undefined8 *param_9)

{
  char cVar1;
  int iVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined1 auStack_d8 [32];
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined4 local_88;
  undefined8 local_80;
  undefined8 local_70;
  undefined4 local_68;
  undefined8 local_64;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_d8;
  local_58 = 0;
  uStack_50 = 0;
  local_80 = 0;
  local_88 = param_4;
  (**(code **)(WdfFunctions_01015 + 0x9c8))(WdfDriverGlobals,*param_2,0);
  local_64 = 0;
  local_5c = 0;
  local_70 = 0x18;
  local_68 = 0;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x7c8))(WdfDriverGlobals,param_2[1],&local_70);
  if (-1 < iVar2) {
    if (param_5 != 0) {
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x618))(WdfDriverGlobals,param_2[2],param_5,param_6)
      ;
      if (iVar2 < 0) goto LAB_1400023a6;
    }
    if (param_7 != 0) {
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x618))(WdfDriverGlobals,param_2[3],param_7,param_8)
      ;
    }
    if (-1 < iVar2) {
      if (param_3 == '\0') {
        if (param_7 == 0) {
          local_a8 = 0;
        }
        else {
          local_a8 = param_2[3];
        }
        if (param_5 == 0) {
          local_b8 = 0;
        }
        else {
          local_b8 = param_2[2];
        }
        pcVar3 = *(code **)(WdfFunctions_01015 + 0x5d8);
      }
      else {
        if (param_7 == 0) {
          local_a8 = 0;
        }
        else {
          local_a8 = param_2[3];
        }
        if (param_5 == 0) {
          local_b8 = 0;
        }
        else {
          local_b8 = param_2[2];
        }
        pcVar3 = *(code **)(WdfFunctions_01015 + 0x5e8);
      }
      local_a0 = 0;
      local_b0 = 0;
      iVar2 = (*pcVar3)(WdfDriverGlobals,param_1,param_2[1],local_88);
      if (-1 < iVar2) {
        uStack_50 = 0;
        local_58 = 0x200000010;
        cVar1 = (**(code **)(WdfFunctions_01015 + 0x7e8))
                          (WdfDriverGlobals,param_2[1],param_1,&local_58);
        if (cVar1 != '\0') {
          iVar2 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_2[1]);
          uVar4 = (**(code **)(WdfFunctions_01015 + 0x8a0))(WdfDriverGlobals,param_2[1]);
          goto LAB_1400023aa;
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                  &WPP_4e134a1eefcb3ea5ae96fc03a980aa94_Traceguids);
        }
        iVar2 = -0x3ffffe7d;
      }
    }
  }
LAB_1400023a6:
  uVar4 = local_80;
LAB_1400023aa:
  (**(code **)(WdfFunctions_01015 + 0x9d0))(WdfDriverGlobals,*param_2);
  if (param_9 != (undefined8 *)0x0) {
    *param_9 = uVar4;
  }
  return iVar2;
}



===== McGenEventWrite_EtwWriteTransfer @ 140002448 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_140019038;
  uVar2 = 0;
  if (DAT_140019038 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_140019038;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(EhStorTcgDrv_Context,param_2,0,0,param_4,param_5);
  return;
}



===== McTemplateK0sdddd_EtwWriteTransfer @ 1400024ac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0sdddd_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
               undefined1 param_5,undefined1 param_6)

{
  longlong lVar1;
  undefined1 auStackY_b8 [32];
  undefined4 local_88 [2];
  undefined4 local_80 [2];
  undefined8 local_78 [2];
  char *local_68;
  int local_60;
  undefined4 local_5c;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_80[0] = 0;
  local_88[0] = 0;
  if (param_4 == (char *)0x0) {
    local_60 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != '\0');
    local_60 = (int)lVar1 + 1;
  }
  local_5c = 0;
  local_58 = &param_5;
  local_50 = 4;
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  local_40 = 4;
  local_48 = &param_6;
  local_38 = local_88;
  local_30 = 4;
  local_28 = local_80;
  local_20 = 4;
  local_68 = param_4;
  McGenEventWrite_EtwWriteTransfer("NULL",&Information,param_3,6,local_78);
  return;
}



===== McTemplateK0siiii_EtwWriteTransfer @ 14000257c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0siiii_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
               undefined1 param_5,undefined1 param_6)

{
  longlong lVar1;
  undefined1 auStackY_b8 [32];
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78 [2];
  char *local_68;
  int local_60;
  undefined4 local_5c;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined8 *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_80 = 0;
  local_88 = 0;
  if (param_4 == (char *)0x0) {
    local_60 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != '\0');
    local_60 = (int)lVar1 + 1;
  }
  local_5c = 0;
  local_58 = &param_5;
  local_50 = 8;
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  local_48 = &param_6;
  local_38 = &local_88;
  local_40 = 8;
  local_28 = &local_80;
  local_30 = 8;
  local_20 = 8;
  local_68 = param_4;
  McGenEventWrite_EtwWriteTransfer("NULL",param_2,0,6,local_78);
  return;
}



===== WPP_SF_ @ 140002648 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_dd @ 140002674 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,0);
  return;
}



===== EraseBandKey @ 1400026c4 =====

void EraseBandKey(longlong param_1,ulonglong param_2,char param_3)

{
  byte bVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined1 *puVar4;
  
  uVar3 = param_2 & 0xffffffff;
  if (param_3 == '\0') {
    memset(*(void **)(*(longlong *)(param_1 + 0x1900) + uVar3 * 8),0,
           (ulonglong)(*(int *)(*(longlong *)(param_1 + 0x18e8) + 0x14) + 4));
    **(undefined4 **)(*(longlong *)(param_1 + 0x1900) + uVar3 * 8) = 0xffffffff;
  }
  else {
    bVar1 = KeGetCurrentIrql();
    if (bVar1 < 2) {
      bVar1 = KfRaiseIrql(2);
    }
    puVar4 = *(undefined1 **)(*(longlong *)(param_1 + 0x1900) + uVar3 * 8);
    for (uVar2 = (ulonglong)(*(int *)(*(longlong *)(param_1 + 0x18e8) + 0x14) + 4); uVar2 != 0;
        uVar2 = uVar2 - 1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    **(undefined4 **)(*(longlong *)(param_1 + 0x1900) + uVar3 * 8) = 0xffffffff;
    KeSweepLocalCaches();
    if (bVar1 < 2) {
      KeLowerIrql(bVar1);
    }
  }
  return;
}



===== EraseBandKeyTable @ 140002794 =====

void EraseBandKeyTable(longlong param_1,char param_2)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  
  uVar2 = 0;
  if ((*(longlong *)(param_1 + 0x1900) != 0) &&
     (uVar3 = *(int *)(param_1 + 0x18f8) * 8, *(int *)(param_1 + 0x18f8) != 0)) {
    do {
      *(ulonglong *)(*(longlong *)(param_1 + 0x1900) + uVar2 * 8) =
           (ulonglong)uVar3 + *(longlong *)(param_1 + 0x1900);
      EraseBandKey(param_1,uVar2,param_2);
      uVar1 = (int)uVar2 + 1;
      uVar2 = (ulonglong)uVar1;
      uVar3 = uVar3 + (*(int *)(*(longlong *)(param_1 + 0x18e8) + 0x14) + 7U & 0xfffffffc);
    } while (uVar1 < *(uint *)(param_1 + 0x18f8));
  }
  return;
}



===== FindBandTableEntry @ 140002824 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint FindBandTableEntry(undefined8 param_1,uint param_2,longlong param_3,longlong param_4,
                       uint param_5,char param_6,uint *param_7)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  ulonglong uVar9;
  longlong lVar10;
  
  uVar8 = 0;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  uVar5 = 0xffffffff;
  lVar10 = *(longlong *)(lVar3 + 0x18e8);
  *param_7 = 0xffffffff;
  uVar2 = *(uint *)(lVar10 + 0x18);
  if (param_2 < uVar2) {
    if (param_4 == 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x99,
                 &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,param_2);
      }
      uVar5 = param_2;
      goto LAB_140002b09;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x98,
              &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids);
    }
  }
  else {
    if (param_2 == 0xffffffff) {
      if (param_3 == 0x7fffffffffffffff) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x9a,
                  &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids);
        }
        *param_7 = 0;
        return 0;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x9b,(ulonglong)uVar2,param_3);
      }
      uVar9 = (ulonglong)param_5;
      if (param_3 % (longlong)uVar9 != 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_Pd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x9c,
                    &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,param_3,(char)param_5);
        }
        return 0xc000000d;
      }
      lVar10 = 0xffffffff;
      uVar2 = LoadBandTableEntries(param_1,0,-1,param_6);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      uVar7 = 1;
      uVar6 = 1;
      uVar8 = *(uint *)(*(longlong *)(lVar3 + 0x18e8) + 0x18);
      if (1 < uVar8) {
        lVar1 = *(longlong *)(lVar3 + 0x18f0);
        do {
          uVar6 = (uint)uVar7;
          lVar4 = uVar7 * 0x78;
          if ((((*(int *)(lVar4 + lVar1) != -1) &&
               (lVar10 = *(longlong *)(lVar4 + 0x10 + lVar1), lVar10 == param_3 / (longlong)uVar9))
              && (lVar4 = *(longlong *)(lVar4 + 0x18 + lVar1), lVar4 != 0)) &&
             ((param_4 / (longlong)uVar9 == 0 || (param_4 / (longlong)uVar9 == lVar4)))) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_dii(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x9d,lVar10,uVar6,(char)lVar10,
                         (char)lVar4 + -1 + (char)lVar10);
            }
            *param_7 = uVar6;
            break;
          }
          uVar6 = uVar6 + 1;
          uVar7 = (ulonglong)uVar6;
        } while (uVar6 < uVar8);
      }
      if (uVar6 != *(uint *)(*(longlong *)(lVar3 + 0x18e8) + 0x18)) {
        return uVar2;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x9e,lVar10,param_3 / (longlong)uVar9);
      }
      uVar8 = 0xc0000225;
      goto LAB_140002b09;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_ddi(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x9f,
                 &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,param_2,(char)uVar2,(char)param_3)
      ;
    }
  }
  uVar8 = 0xc000000d;
LAB_140002b09:
  *param_7 = uVar5;
  return uVar8;
}



===== IoctlActivateRevertLockingSp @ 140002b34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint IoctlActivateRevertLockingSp(undefined8 param_1,undefined8 param_2,char param_3)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  int *piVar5;
  undefined2 uVar6;
  uint *puVar7;
  uint uVar8;
  undefined1 auStackY_a8 [32];
  undefined1 uVar9;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  ulonglong local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_78 = 0;
  local_50 = 0;
  puVar7 = (uint *)0x0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x858))(WdfDriverGlobals,param_2,&local_78);
  if ((int)uVar3 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x82,
               &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar3);
    }
    goto LAB_140002eab;
  }
  piVar5 = (int *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_78,0);
  local_50 = 0;
  uStack_68 = 0;
  local_70 = 0x28;
  local_60 = 0;
  uStack_58 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_70);
  if (local_60 < 0xc) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140002ca0;
    uVar6 = 0x83;
    uVar9 = 0xc;
LAB_140002c90:
    WPP_SF_Pd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
              &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,local_60,uVar9);
    goto LAB_140002ca0;
  }
  if (*piVar5 != 0xc) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x84,
                &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,*piVar5,0xc);
    }
LAB_140002cec:
    uVar3 = 0xc000000d;
    goto LAB_140002eab;
  }
  uVar3 = piVar5[2];
  if (uVar3 != 0) {
    uVar8 = uVar3 + 4;
    if (local_60 < uVar8) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar6 = 0x85;
LAB_140002d2b:
        uVar9 = (undefined1)uVar8;
        goto LAB_140002c90;
      }
    }
    else {
      uVar8 = *(int *)((ulonglong)uVar3 + (longlong)piVar5) + 4 + uVar3;
      if (uVar8 <= local_60) goto LAB_140002d70;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar6 = 0x86;
        goto LAB_140002d2b;
      }
    }
LAB_140002ca0:
    uVar3 = 0xc0000206;
    goto LAB_140002eab;
  }
LAB_140002d70:
  if ((piVar5[2] != 0) &&
     (puVar7 = (uint *)((ulonglong)(uint)piVar5[2] + (longlong)piVar5), puVar7 != (uint *)0x0)) {
    uVar3 = *puVar7;
    uVar8 = *(uint *)(*(longlong *)(lVar4 + 0x18e8) + 0x10);
    puVar1 = (uint *)(*(longlong *)(lVar4 + 0x18e8) + 0x14);
    if ((uVar3 < uVar8) || (*puVar1 < uVar3)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x87,
                   &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar3,(char)uVar8,(char)*puVar1)
        ;
      }
      goto LAB_140002cec;
    }
  }
  uVar3 = *(uint *)(*(longlong *)(lVar4 + 0x18e8) + 4);
  if (param_3 == '\0') {
    if ((uVar3 & 1) != 0) goto LAB_140002e97;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar6 = 0x89;
      goto LAB_140002e80;
    }
  }
  else {
    if ((uVar3 & 1) == 0) {
      if ((piVar5[1] & 2U) == 0) {
        iVar2 = ReadGroupPolicyActivation();
        if (iVar2 == 1) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (2 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8a,
                    &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids);
          }
          uVar3 = 0xc00000bb;
          goto LAB_140002eab;
        }
      }
LAB_140002e97:
      uVar3 = BmActivateRevertLockingSp(param_1,puVar7,(byte)piVar5[1],param_3);
      goto LAB_140002eab;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar6 = 0x88;
LAB_140002e80:
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
              &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids);
    }
  }
  uVar3 = 0xc0000184;
LAB_140002eab:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar3);
  return uVar3;
}



===== IoctlCreateBand @ 140002ef0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint IoctlCreateBand(undefined8 param_1,undefined8 param_2)

{
  int *piVar1;
  longlong *plVar2;
  undefined8 uVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  int *piVar7;
  undefined2 uVar8;
  longlong lVar9;
  uint uVar10;
  undefined8 *puVar11;
  undefined8 uVar12;
  longlong lVar13;
  longlong lVar14;
  ulonglong uVar15;
  uint *_Src;
  int *piVar16;
  undefined1 auStackY_158 [32];
  char cVar17;
  uint local_110 [2];
  undefined4 *local_108;
  undefined8 local_100;
  longlong local_f8;
  undefined8 local_f0;
  uint local_e8;
  undefined4 uStack_e4;
  undefined8 uStack_e0;
  longlong lStack_d8;
  longlong lStack_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  ulonglong uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 *local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_158;
  local_48 = 0;
  local_100 = 0;
  uStack_e4 = 0;
  piVar16 = (int *)0x0;
  local_68 = 0;
  uStack_60 = 0;
  _Src = (uint *)0x0;
  local_58 = (undefined8 *)0x0;
  uStack_50 = 0;
  local_f0 = param_1;
  memset(&local_e8,0,0x74);
  local_108 = (undefined4 *)0x0;
  local_110[0] = 0;
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  local_f8 = lVar6;
  uVar5 = (**(code **)(WdfFunctions_01015 + 0x858))(WdfDriverGlobals,param_2,&local_100);
  if ((int)uVar5 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
               &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar5);
    }
    goto LAB_1400038b8;
  }
  piVar7 = (int *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_100,0);
  puVar11 = &local_68;
  local_48 = 0;
  uStack_60 = 0;
  local_68 = 0x28;
  local_58 = (undefined8 *)0x0;
  uStack_50 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2);
  if (local_58 < (undefined8 *)0x14) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000309d;
    uVar8 = 0x1f;
    cVar17 = '\x14';
LAB_14000308d:
    WPP_SF_Pd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
              &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,local_58,cVar17);
  }
  else {
    if (*piVar7 != 0x14) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                  &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,*piVar7,0x14);
      }
      goto LAB_1400030e7;
    }
    uVar5 = piVar7[2];
    if (local_58 < (undefined8 *)((ulonglong)uVar5 + 0x38)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar8 = 0x21;
LAB_14000311e:
        cVar17 = (char)uVar5 + '8';
        goto LAB_14000308d;
      }
    }
    else {
      uVar5 = piVar7[3];
      if ((uVar5 == 0) || ((undefined8 *)((ulonglong)uVar5 + 0x38) <= local_58)) {
        uVar5 = piVar7[4];
        if (uVar5 == 0) {
LAB_1400031e0:
          uVar5 = piVar7[3];
          piVar1 = (int *)((longlong)piVar7 + (ulonglong)(uint)piVar7[2]);
          if (uVar5 != 0) {
            piVar16 = (int *)((longlong)piVar7 + (ulonglong)uVar5);
          }
          if (piVar7[4] != 0) {
            _Src = (uint *)((longlong)piVar7 + (ulonglong)(uint)piVar7[4]);
          }
          if ((uint)piVar7[2] < 0x14) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar8 = 0x25;
LAB_140003228:
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                      &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids);
            }
          }
          else {
            iVar4 = *piVar1;
            if (iVar4 == 0x38) {
              lVar13 = *(longlong *)(piVar1 + 2);
              if (lVar13 < 0) {
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                  uVar8 = 0x27;
LAB_1400032b0:
                  WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,puVar11,lVar13);
                }
              }
              else {
                lVar13 = *(longlong *)(piVar1 + 4);
                if (lVar13 < 1) {
                  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                    uVar8 = 0x28;
                    goto LAB_1400032b0;
                  }
                }
                else if (uVar5 - 1 < 0x13) {
                  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                    uVar8 = 0x29;
                    goto LAB_140003228;
                  }
                }
                else if (piVar16 == (int *)0x0) {
LAB_140003402:
                  if (_Src != (uint *)0x0) {
                    lVar6 = *(longlong *)(lVar6 + 0x18e8);
                    uVar5 = *_Src;
                    if ((uVar5 < *(uint *)(lVar6 + 0x10)) || (*(uint *)(lVar6 + 0x14) < uVar5)) {
                      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                        WPP_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
                                   &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar5,
                                   (char)*(uint *)(lVar6 + 0x10),(char)*(undefined4 *)(lVar6 + 0x14)
                                  );
                      }
                      goto LAB_1400030e7;
                    }
                  }
                  iVar4 = GetSectorSize(param_1,local_110);
                  if ((iVar4 < 0) || (local_110[0] == 0)) {
                    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
                               &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,iVar4);
                    }
                    uVar5 = 0xc00000e5;
                    goto LAB_1400038b8;
                  }
                  lVar6 = *(longlong *)(piVar1 + 2);
                  if (lVar6 % (longlong)(ulonglong)local_110[0] == 0) {
                    lVar6 = *(longlong *)(piVar1 + 4);
                    if (lVar6 % (longlong)(ulonglong)local_110[0] == 0) {
                      iVar4 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals);
                      if (iVar4 < 0) {
                        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                           (2 < (byte)WPP_GLOBAL_Control[0x29])) {
                          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
                                   &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,iVar4);
                        }
                        local_108 = (undefined4 *)0x0;
                      }
                      uVar5 = LoadBandTableEntries(param_1,0,-1,'\0');
                      uVar3 = local_f0;
                      if (-1 < (int)uVar5) {
                        uVar15 = 1;
                        uVar10 = 1;
                        uVar5 = *(uint *)(*(longlong *)(local_f8 + 0x18e8) + 0x18);
                        if (1 < uVar5) {
                          do {
                            uVar10 = (uint)uVar15;
                            if ((*(int *)(uVar15 * 0x78 + *(longlong *)(local_f8 + 0x18f0)) != -1)
                               && (*(longlong *)
                                    (uVar15 * 0x78 + 0x18 + *(longlong *)(local_f8 + 0x18f0)) == 0))
                            break;
                            uVar10 = uVar10 + 1;
                            uVar15 = (ulonglong)uVar10;
                          } while (uVar10 < uVar5);
                        }
                        if (uVar10 < *(uint *)(*(longlong *)(local_f8 + 0x18e8) + 0x18)) {
                          uStack_e0 = *(undefined8 *)piVar1;
                          uStack_c8 = *(undefined8 *)(piVar1 + 6);
                          local_c0 = *(undefined8 *)(piVar1 + 8);
                          uStack_b8 = *(undefined8 *)(piVar1 + 10);
                          local_b0 = *(undefined8 *)(piVar1 + 0xc);
                          if (piVar16 == (int *)0x0) {
                            local_a8 = 0x100000038;
                            uStack_a0._0_4_ = 1;
                            local_98._4_4_ = 0;
                            uStack_90 = 0;
                            local_78 = 0;
                            local_88 = 0;
                            uStack_80 = 0;
                          }
                          else {
                            local_a8 = *(undefined8 *)piVar16;
                            uStack_a0._0_4_ = (uint)*(undefined8 *)(piVar16 + 2);
                            local_98._4_4_ =
                                 (undefined4)((ulonglong)*(undefined8 *)(piVar16 + 4) >> 0x20);
                            uStack_90 = *(undefined8 *)(piVar16 + 6);
                            local_88 = *(undefined8 *)(piVar16 + 8);
                            uStack_80 = *(undefined8 *)(piVar16 + 10);
                            local_78 = *(undefined8 *)(piVar16 + 0xc);
                          }
                          local_98 = CONCAT44(local_98._4_4_,0xffffffff);
                          lStack_d8 = *(longlong *)(piVar1 + 2) / (longlong)(ulonglong)local_110[0];
                          lStack_d0 = *(longlong *)(piVar1 + 4) / (longlong)(ulonglong)local_110[0];
                          uStack_a0 = (ulonglong)(uint)uStack_a0;
                          local_e8 = uVar10;
                          uVar5 = BmUpdateBandTableEntry
                                            (local_f0,uVar10,'\0',_Src != (uint *)0x0,
                                             (longlong)&local_e8,(uint *)0x0,_Src);
                          lVar6 = local_f8;
                          if ((int)uVar5 < 0) {
                            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                              WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
                                        &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar10,
                                        (char)uVar5);
                            }
                          }
                          else {
                            lVar9 = (ulonglong)uVar10 * 0x78;
                            lVar13 = *(longlong *)(local_f8 + 0x18f0);
                            *(undefined8 *)(lVar13 + lVar9) = CONCAT44(uStack_e4,local_e8);
                            ((undefined8 *)(lVar13 + lVar9))[1] = uStack_e0;
                            plVar2 = (longlong *)(lVar13 + 0x10 + lVar9);
                            *plVar2 = lStack_d8;
                            plVar2[1] = lStack_d0;
                            puVar11 = (undefined8 *)(lVar13 + 0x20 + lVar9);
                            *puVar11 = uStack_c8;
                            puVar11[1] = local_c0;
                            puVar11 = (undefined8 *)(lVar13 + 0x30 + lVar9);
                            *puVar11 = uStack_b8;
                            puVar11[1] = local_b0;
                            puVar11 = (undefined8 *)(lVar13 + 0x40 + lVar9);
                            *puVar11 = local_a8;
                            puVar11[1] = uStack_a0;
                            puVar11 = (undefined8 *)(lVar13 + 0x50 + lVar9);
                            *puVar11 = local_98;
                            puVar11[1] = uStack_90;
                            puVar11 = (undefined8 *)(lVar13 + 0x60 + lVar9);
                            *puVar11 = local_88;
                            puVar11[1] = uStack_80;
                            *(undefined8 *)(lVar13 + 0x70 + lVar9) = local_78;
                            if (((_Src == (uint *)0x0) || ((piVar7[1] & 1U) == 0)) ||
                               ((*(int *)(lVar9 + 0x44 + *(longlong *)(local_f8 + 0x18f0)) == 3 &&
                                (*(int *)(lVar9 + 0x48 + *(longlong *)(local_f8 + 0x18f0)) == 3))))
                            {
                              EraseBandKey(local_f8,(ulonglong)uVar10,'\x01');
                            }
                            else {
                              memmove(*(void **)(*(longlong *)(local_f8 + 0x1900) +
                                                (ulonglong)uVar10 * 8),_Src,(ulonglong)(*_Src + 4));
                            }
                            if (local_108 == (undefined4 *)0x0) {
                              uVar12 = 0;
                            }
                            else {
                              uVar12 = 4;
                              *local_108 = *(undefined4 *)(lVar9 + *(longlong *)(lVar6 + 0x18f0));
                            }
                            (**(code **)(WdfFunctions_01015 + 0x898))
                                      (WdfDriverGlobals,param_2,uVar12);
                            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                              lVar6 = *(longlong *)(lVar6 + 0x18f0);
                              lVar14 = (ulonglong)uVar10 * 0x78;
                              lVar13 = *(longlong *)(lVar14 + 0x10 + lVar6);
                              lVar9 = lVar13 + -1 + *(longlong *)(lVar14 + 0x18 + lVar6);
                              WPP_SF_diidd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar9,lVar13,
                                           *(undefined4 *)(lVar14 + lVar6),(char)lVar13,(char)lVar9,
                                           (char)*(undefined4 *)(lVar14 + 0x44 + lVar6),
                                           (char)*(undefined4 *)(lVar14 + 0x48 + lVar6));
                            }
                            uVar5 = UpdateLbaFilterTable(uVar3);
                          }
                        }
                        else {
                          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
                                    &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids);
                          }
                          uVar5 = 0xc000009a;
                        }
                      }
                      goto LAB_1400038b8;
                    }
                    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                      uVar8 = 0x31;
                      goto LAB_1400034c5;
                    }
                  }
                  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                          (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                    uVar8 = 0x30;
LAB_1400034c5:
                    WPP_SF_Pd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                              &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,lVar6,
                              (char)local_110[0]);
                  }
                }
                else {
                  iVar4 = *piVar16;
                  if (iVar4 == 0x38) {
                    iVar4 = piVar16[3];
                    if (iVar4 == 0) {
                      iVar4 = piVar16[1];
                      if (iVar4 - 1U < 3) {
                        iVar4 = piVar16[2];
                        if (iVar4 - 1U < 3) goto LAB_140003402;
                        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                          uVar8 = 0x2d;
                          goto LAB_14000326c;
                        }
                      }
                      else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                              (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                        uVar8 = 0x2c;
                        goto LAB_14000326c;
                      }
                    }
                    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                            (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                      uVar8 = 0x2b;
                      goto LAB_14000326c;
                    }
                  }
                  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                          (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                    uVar8 = 0x2a;
LAB_14000326c:
                    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                             &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,iVar4);
                  }
                }
              }
            }
            else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar8 = 0x26;
              goto LAB_14000326c;
            }
          }
LAB_1400030e7:
          uVar5 = 0xc000000d;
          goto LAB_1400038b8;
        }
        uVar10 = uVar5 + 4;
        if (local_58 < (undefined8 *)(ulonglong)uVar10) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar8 = 0x23;
LAB_14000319b:
            cVar17 = (char)uVar10;
            goto LAB_14000308d;
          }
        }
        else {
          uVar10 = *(int *)((ulonglong)uVar5 + (longlong)piVar7) + 4 + uVar5;
          puVar11 = (undefined8 *)(ulonglong)uVar10;
          if (puVar11 <= local_58) goto LAB_1400031e0;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar8 = 0x24;
            goto LAB_14000319b;
          }
        }
      }
      else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar8 = 0x22;
        goto LAB_14000311e;
      }
    }
  }
LAB_14000309d:
  uVar5 = 0xc0000206;
LAB_1400038b8:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar5);
  return uVar5;
}



===== IoctlDeleteBand @ 140003908 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint IoctlDeleteBand(undefined8 param_1,undefined8 param_2)

{
  uint *puVar1;
  undefined8 *puVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  int *piVar6;
  char *pcVar7;
  longlong lVar8;
  undefined2 uVar9;
  longlong lVar10;
  ulonglong uVar11;
  uint uVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  uint *puVar15;
  undefined1 auStackY_148 [32];
  undefined1 uVar16;
  uint local_108;
  uint local_104;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  ulonglong local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  uint local_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_148;
  local_104 = 0xffffffff;
  local_d0 = 0;
  uStack_c4 = 0;
  local_100 = 0;
  puVar15 = (uint *)0x0;
  local_f0 = 0;
  uStack_e8 = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  local_f8 = param_2;
  memset(&local_c8,0,0x74);
  local_108 = 0;
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x858))(WdfDriverGlobals,param_2,&local_100);
  if ((int)uVar4 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6d,
               &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar4);
    }
    goto LAB_140003e94;
  }
  piVar6 = (int *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_100,0);
  local_d0 = 0;
  uStack_e8 = 0;
  local_f0 = 0x28;
  local_e0 = 0;
  uStack_d8 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,local_f8,&local_f0);
  if (local_e0 < 0x20) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140003aad;
    uVar9 = 0x6e;
    uVar16 = 0x20;
LAB_140003a9d:
    WPP_SF_Pd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
              &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,local_e0,uVar16);
    goto LAB_140003aad;
  }
  if (*piVar6 == 0x20) {
    uVar4 = piVar6[6];
    if (uVar4 != 0) {
      uVar12 = uVar4 + 4;
      if (local_e0 < uVar12) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar9 = 0x70;
LAB_140003b38:
          uVar16 = (undefined1)uVar12;
          goto LAB_140003a9d;
        }
      }
      else {
        uVar12 = *(int *)((ulonglong)uVar4 + (longlong)piVar6) + 4 + uVar4;
        if (uVar12 <= local_e0) goto LAB_140003b7d;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar9 = 0x71;
          goto LAB_140003b38;
        }
      }
LAB_140003aad:
      uVar4 = 0xc0000206;
      goto LAB_140003e94;
    }
LAB_140003b7d:
    if ((piVar6[6] != 0) &&
       (puVar15 = (uint *)((ulonglong)(uint)piVar6[6] + (longlong)piVar6), puVar15 != (uint *)0x0))
    {
      uVar4 = *puVar15;
      uVar12 = *(uint *)(*(longlong *)(lVar5 + 0x18e8) + 0x10);
      puVar1 = (uint *)(*(longlong *)(lVar5 + 0x18e8) + 0x14);
      if ((uVar4 < uVar12) || (*puVar1 < uVar4)) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x72,
                     &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar4,(char)uVar12,
                     (char)*puVar1);
        }
        goto LAB_140003af9;
      }
    }
    iVar3 = GetSectorSize(param_1,&local_108);
    if ((iVar3 < 0) || (local_108 == 0)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x73,
                 &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,iVar3);
      }
      uVar4 = 0xc00000e5;
      goto LAB_140003e94;
    }
    uVar4 = FindBandTableEntry(param_1,piVar6[3],*(longlong *)(piVar6 + 4),0,local_108,'\0',
                               &local_104);
    uVar12 = local_104;
    if ((int)uVar4 < 0) goto LAB_140003e94;
    uVar11 = (ulonglong)local_104;
    uVar4 = LoadBandTableEntries(param_1,local_104,1,'\0');
    if ((int)uVar4 < 0) goto LAB_140003e94;
    if (uVar12 != 0) {
      lVar10 = uVar11 * 0x78;
      if ((*(int *)(*(longlong *)(lVar5 + 0x18f0) + lVar10) == -1) ||
         (*(longlong *)(*(longlong *)(lVar5 + 0x18f0) + 0x18 + lVar10) == 0)) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x75,
                   &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar12);
        }
        uVar4 = 0xc0000225;
      }
      else {
        uVar14 = 0;
        memset(&local_c8,0,0x78);
        uStack_c0 = 0x38;
        local_88 = 0x38;
        local_c8 = uVar12;
        uStack_84 = 1;
        uStack_80 = 1;
        uStack_7c = *(undefined4 *)(*(longlong *)(lVar5 + 0x18f0) + 0x4c + lVar10);
        local_78 = *(undefined4 *)(*(longlong *)(lVar5 + 0x18f0) + 0x50 + lVar10);
        uVar13 = CONCAT71((int7)((ulonglong)uVar14 >> 8),*(byte *)(piVar6 + 1)) & 0xffffffffffffff01
        ;
        uVar4 = BmUpdateBandTableEntry
                          (param_1,uVar12,(char)uVar13,*(byte *)(piVar6 + 1) & 1 ^ 1,
                           (longlong)&local_c8,puVar15,(uint *)0x0);
        if ((int)uVar4 < 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x76,
                      &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar12,(char)uVar4);
          }
        }
        else {
          uVar14 = CONCAT71((int7)(uVar13 >> 8),1);
          lVar10 = *(longlong *)(lVar5 + 0x18f0);
          lVar8 = uVar11 * 0x78;
          *(undefined8 *)(lVar8 + lVar10) = CONCAT44(uStack_c4,local_c8);
          ((undefined8 *)(lVar8 + lVar10))[1] = CONCAT44(uStack_bc,uStack_c0);
          puVar2 = (undefined8 *)(lVar8 + 0x10 + lVar10);
          *puVar2 = local_b8;
          puVar2[1] = uStack_b0;
          puVar2 = (undefined8 *)(lVar8 + 0x20 + lVar10);
          *puVar2 = local_a8;
          puVar2[1] = uStack_a0;
          puVar2 = (undefined8 *)(lVar8 + 0x30 + lVar10);
          *puVar2 = local_98;
          puVar2[1] = uStack_90;
          puVar2 = (undefined8 *)(lVar8 + 0x40 + lVar10);
          *puVar2 = CONCAT44(uStack_84,local_88);
          puVar2[1] = CONCAT44(uStack_7c,uStack_80);
          puVar2 = (undefined8 *)(lVar8 + 0x50 + lVar10);
          *puVar2 = CONCAT44(uStack_74,local_78);
          puVar2[1] = uStack_70;
          puVar2 = (undefined8 *)(lVar8 + 0x60 + lVar10);
          *puVar2 = local_68;
          puVar2[1] = uStack_60;
          *(undefined8 *)(lVar8 + 0x70 + lVar10) = local_58;
          EraseBandKey(lVar5,(ulonglong)uVar12,'\x01');
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            pcVar7 = "erased and deleted";
            if ((piVar6[1] & 1U) == 0) {
              pcVar7 = "deleted";
            }
            WPP_SF_ds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x77,uVar14,uVar12,pcVar7);
          }
          uVar4 = UpdateLbaFilterTable(param_1);
        }
      }
      goto LAB_140003e94;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x74,
              &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids);
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6f,
              &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,*piVar6,0x20);
  }
LAB_140003af9:
  uVar4 = 0xc000000d;
LAB_140003e94:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,local_f8,uVar4);
  return uVar4;
}



===== IoctlEnumerateBands @ 140003ee8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint IoctlEnumerateBands(undefined8 param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  longlong lVar6;
  undefined2 uVar7;
  int iVar8;
  ulonglong uVar9;
  longlong lVar10;
  longlong lVar11;
  uint uVar12;
  uint uVar13;
  int *piVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  void *_Dst;
  undefined4 *puVar17;
  uint uVar18;
  uint uVar19;
  undefined1 auStackY_f8 [32];
  uint local_b0;
  uint local_ac;
  uint local_a8;
  int local_a4;
  int *local_a0;
  uint local_98;
  uint local_94;
  undefined4 *local_88;
  uint local_80;
  longlong local_78;
  char *local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  longlong local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_f8;
  local_b0 = 0xffffffff;
  local_a0 = (int *)0x0;
  local_88 = (undefined4 *)0x0;
  local_a8 = 0;
  lVar11 = (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  local_48 = 0;
  uStack_60 = 0;
  local_68 = 0x28;
  local_58 = 0;
  uStack_50 = 0;
  local_78 = lVar11;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_68);
  if (local_58 != 0x20) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_Pd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,local_58,0x20);
    }
    uVar4 = 0xc0000206;
    goto LAB_1400046ad;
  }
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,0x20,&local_a0);
  if ((int)uVar4 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1400046ad;
    uVar7 = 0x14;
    uVar18 = uVar4;
LAB_140004032:
    uVar4 = uVar18;
LAB_140004035:
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,
             &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar18);
  }
  else {
    if (*local_a0 != 0x20) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                  &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,*local_a0,0x20);
      }
      uVar4 = 0xc000000d;
      goto LAB_1400046ad;
    }
    iVar3 = GetSectorSize(param_1,&local_a8);
    if ((iVar3 < 0) || (local_a8 == 0)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                 &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,iVar3);
      }
      uVar4 = 0xc00000e5;
      goto LAB_1400046ad;
    }
    if ((local_a0[1] & 1U) == 0) {
      uVar4 = FindBandTableEntry(param_1,local_a0[3],*(longlong *)(local_a0 + 4),
                                 *(longlong *)(local_a0 + 6),local_a8,
                                 (byte)((uint)local_a0[1] >> 1) & 1,&local_b0);
      iVar3 = 1;
      if ((int)uVar4 < 0) goto LAB_1400046ad;
      uVar15 = (ulonglong)local_b0;
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids);
      }
      uVar15 = 0;
      iVar3 = *(int *)(*(longlong *)(lVar11 + 0x18e8) + 0x18);
    }
    uVar19 = (uint)uVar15;
    uVar4 = LoadBandTableEntries(param_1,uVar19,iVar3,(byte)((uint)local_a0[1] >> 1) & 1);
    if ((int)uVar4 < 0) goto LAB_1400046ad;
    uVar12 = 0;
    if (uVar19 < uVar19 + iVar3) {
      piVar14 = (int *)(uVar15 * 0x78 + *(longlong *)(lVar11 + 0x18f0));
      uVar9 = uVar15;
      do {
        iVar8 = (int)uVar9;
        if ((*piVar14 == iVar8) && ((*(longlong *)(piVar14 + 6) != 0 || (iVar8 == 0)))) {
          uVar12 = uVar12 + 1;
        }
        uVar9 = (ulonglong)(iVar8 + 1U);
        piVar14 = piVar14 + 0x1e;
      } while (iVar8 + 1U < uVar19 + iVar3);
      if (uVar12 != 0) {
        uVar18 = uVar12 * 0x78 + 0x10;
        if ((local_a0[1] & 2U) != 0) {
          uVar16 = (ulonglong)(uVar19 + iVar3);
          uVar9 = uVar15;
          do {
            while( true ) {
              uVar13 = (uint)uVar9;
              if ((uint)uVar16 <= uVar13) goto LAB_140004264;
              lVar6 = uVar9 * 0x78;
              lVar10 = *(longlong *)(lVar11 + 0x18f0);
              if ((*(uint *)(lVar6 + lVar10) != uVar13) ||
                 ((((*(longlong *)(lVar6 + 0x18 + lVar10) == 0 && (uVar13 != 0)) ||
                   (*(int *)(lVar6 + 0x4c + lVar10) != 2)) ||
                  (pcVar5 = BmConvertAlgorithmIdToOid(*(uint *)(lVar6 + 0x50 + lVar10)),
                  pcVar5 == (char *)0x0)))) break;
              lVar10 = 0x100;
              do {
                if (*pcVar5 == '\0') break;
                pcVar5 = pcVar5 + 1;
                lVar10 = lVar10 + -1;
              } while (lVar10 != 0);
              uVar4 = ~-(uint)(lVar10 != 0) & 0xc000000d;
              if (lVar10 == 0) goto LAB_1400046ad;
              uVar18 = uVar18 + 1 + (-(uint)(lVar10 != 0) & 0x100U - (int)lVar10);
              uVar9 = (ulonglong)((int)uVar9 + 1);
            }
            uVar9 = (ulonglong)((int)uVar9 + 1);
          } while (-1 < (int)uVar4);
        }
LAB_140004264:
        if ((int)uVar4 < 0) goto LAB_1400046ad;
        lVar11 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2);
        if ((*(uint *)(lVar11 + 0x10) & 0x40) != 0) {
          uVar4 = (**(code **)(WdfFunctions_01015 + 0x870))
                            (WdfDriverGlobals,param_2,(ulonglong)uVar18,&local_88);
          if (-1 < (int)uVar4) {
            local_ac = local_a0[1];
            memset(local_88,0,(ulonglong)uVar18);
            uVar16 = 0;
            local_94 = 0;
            *local_88 = 0x10;
            local_88[1] = 0x10;
            local_88[2] = uVar12;
            local_b0 = uVar12 * 0x78 + 0x10;
            uVar9 = (ulonglong)local_b0;
            local_88[3] = 0x78;
            local_80 = uVar19 + iVar3;
            puVar17 = local_88 + 4;
            local_a4 = 0;
            do {
              uVar19 = (uint)uVar16;
              uVar13 = (uint)uVar15;
              if (local_80 <= uVar13) break;
              lVar10 = uVar15 * 0x78;
              lVar11 = *(longlong *)(local_78 + 0x18f0);
              if ((*(uint *)(lVar10 + lVar11) == uVar13) &&
                 ((*(longlong *)(lVar10 + 0x18 + lVar11) != 0 || (uVar13 == 0)))) {
                if (uVar12 < uVar19) {
                  uVar4 = 0xc00000e5;
                  goto LAB_140004579;
                }
                uVar2 = ((undefined8 *)(lVar10 + lVar11))[1];
                *(undefined8 *)(puVar17 + uVar16 * 0x1e) = *(undefined8 *)(lVar10 + lVar11);
                *(undefined8 *)((longlong)(puVar17 + uVar16 * 0x1e) + 8) = uVar2;
                puVar1 = (undefined8 *)(lVar10 + 0x10 + lVar11);
                uVar2 = puVar1[1];
                *(undefined8 *)(puVar17 + uVar16 * 0x1e + 4) = *puVar1;
                *(undefined8 *)((longlong)(puVar17 + uVar16 * 0x1e + 4) + 8) = uVar2;
                puVar1 = (undefined8 *)(lVar10 + 0x20 + lVar11);
                uVar2 = puVar1[1];
                *(undefined8 *)(puVar17 + uVar16 * 0x1e + 8) = *puVar1;
                *(undefined8 *)((longlong)(puVar17 + uVar16 * 0x1e + 8) + 8) = uVar2;
                puVar1 = (undefined8 *)(lVar10 + 0x30 + lVar11);
                uVar2 = puVar1[1];
                *(undefined8 *)(puVar17 + uVar16 * 0x1e + 0xc) = *puVar1;
                *(undefined8 *)((longlong)(puVar17 + uVar16 * 0x1e + 0xc) + 8) = uVar2;
                puVar1 = (undefined8 *)(lVar10 + 0x40 + lVar11);
                uVar2 = puVar1[1];
                *(undefined8 *)(puVar17 + uVar16 * 0x1e + 0x10) = *puVar1;
                *(undefined8 *)((longlong)(puVar17 + uVar16 * 0x1e + 0x10) + 8) = uVar2;
                puVar1 = (undefined8 *)(lVar10 + 0x50 + lVar11);
                uVar2 = puVar1[1];
                *(undefined8 *)(puVar17 + uVar16 * 0x1e + 0x14) = *puVar1;
                *(undefined8 *)((longlong)(puVar17 + uVar16 * 0x1e + 0x14) + 8) = uVar2;
                puVar1 = (undefined8 *)(lVar10 + 0x60 + lVar11);
                uVar2 = puVar1[1];
                *(undefined8 *)(puVar17 + uVar16 * 0x1e + 0x18) = *puVar1;
                *(undefined8 *)((longlong)(puVar17 + uVar16 * 0x1e + 0x18) + 8) = uVar2;
                *(undefined8 *)(puVar17 + uVar16 * 0x1e + 0x1c) =
                     *(undefined8 *)(lVar10 + 0x70 + lVar11);
                if (uVar13 == 0) {
                  *(undefined8 *)(puVar17 + uVar16 * 0x1e + 4) = 0;
                  *(undefined8 *)(puVar17 + uVar16 * 0x1e + 6) = 0x7fffffffffffffff;
                }
                else {
                  *(ulonglong *)(puVar17 + uVar16 * 0x1e + 4) =
                       (ulonglong)local_a8 * *(longlong *)(puVar17 + uVar16 * 0x1e + 4);
                  *(ulonglong *)(puVar17 + uVar16 * 0x1e + 6) =
                       (ulonglong)local_a8 * *(longlong *)(puVar17 + uVar16 * 0x1e + 6);
                }
                *(undefined8 *)(puVar17 + uVar16 * 0x1e + 0x14) = 0;
                if ((local_ac & 2) != 0) {
                  if (*(int *)(uVar15 * 0x78 + 0x4c + *(longlong *)(local_78 + 0x18f0)) == 2) {
                    local_70 = BmConvertAlgorithmIdToOid
                                         (*(uint *)(uVar15 * 0x78 + 0x50 +
                                                   *(longlong *)(local_78 + 0x18f0)));
                    uVar19 = (uint)uVar16;
                    if (local_70 != (char *)0x0) {
                      lVar11 = 0x100;
                      pcVar5 = local_70;
                      do {
                        local_98 = local_ac;
                        if (*pcVar5 == '\0') break;
                        pcVar5 = pcVar5 + 1;
                        lVar11 = lVar11 + -1;
                      } while (lVar11 != 0);
                      uVar15 = -(ulonglong)(lVar11 != 0) & 0x100U - lVar11;
                      uVar4 = ~-(uint)(lVar11 != 0) & 0xc000000d;
                      if ((lVar11 != 0) && (uVar15 < 0x101)) {
                        _Dst = (void *)((uVar9 & 0xffffffff) + (longlong)local_88);
                        local_b0 = (int)uVar9 + 1 + (int)uVar15;
                        if (uVar18 < local_b0) {
                          uVar4 = 0xc00000e5;
                          break;
                        }
                        puVar17[(uVar16 & 0xffffffff) * 0x1e + 0x13] = 1;
                        puVar17[(uVar16 & 0xffffffff) * 0x1e + 0x14] =
                             (((int)_Dst - local_a4) - (int)puVar17) + -0x40;
                        puVar17[(uVar16 & 0xffffffff) * 0x1e + 0x15] = (int)uVar15;
                        memmove(_Dst,local_70,uVar15 + 1);
                        uVar9 = (ulonglong)local_b0;
                        local_ac = local_98;
                        uVar19 = local_94;
                      }
                    }
                  }
                }
                local_94 = uVar19 + 1;
                uVar16 = (ulonglong)local_94;
                local_a4 = local_a4 + 0x78;
              }
              uVar19 = (uint)uVar16;
              uVar15 = (ulonglong)(uVar13 + 1);
            } while (-1 < (int)uVar4);
            if (uVar19 != uVar12) {
LAB_140004579:
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                          &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar19,(char)uVar12);
              }
            }
            uVar19 = local_b0;
            if (((local_b0 != uVar18) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control))
               && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                        &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,local_b0,(char)uVar18);
            }
            if (-1 < (int)uVar4) {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                          &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar18,(char)uVar12);
              }
              (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,uVar19);
            }
            goto LAB_1400046ad;
          }
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1400046ad;
          uVar7 = 0x1a;
          uVar18 = uVar4;
          goto LAB_140004032;
        }
        (**(code **)(WdfFunctions_01015 + 0x898))();
        uVar4 = 0x80000005;
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_1400046ad;
        uVar7 = 0x19;
        uVar4 = 0x80000005;
        goto LAB_140004035;
      }
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
              &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids);
    }
    uVar4 = 0xc0000225;
  }
LAB_1400046ad:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar4);
  return uVar4;
}



===== IoctlEraseAllBands @ 140004700 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint IoctlEraseAllBands(undefined8 param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined8 uVar3;
  bool bVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  longlong lVar8;
  longlong lVar9;
  ulonglong uVar10;
  uint uVar11;
  undefined1 auStackY_118 [32];
  undefined8 local_c8;
  ulonglong uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_118;
  uVar11 = 0;
  local_c8 = (ulonglong)(uint)local_c8;
  memset(&local_c8,0,0x74);
  bVar4 = false;
  lVar8 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  uVar6 = LoadBandTableEntries(param_1,0,-1,'\0');
  if ((-1 < (int)uVar6) && (uVar10 = 1, 1 < *(uint *)(*(longlong *)(lVar8 + 0x18e8) + 0x18))) {
    do {
      uVar6 = (uint)uVar10;
      lVar9 = uVar10 * 0x78;
      lVar2 = *(longlong *)(lVar8 + 0x18f0);
      if ((*(int *)(lVar9 + lVar2) != -1) && (*(longlong *)(lVar9 + 0x18 + lVar2) != 0)) {
        uStack_c0 = ((undefined8 *)(lVar9 + lVar2))[1];
        puVar1 = (undefined8 *)(lVar9 + 0x10 + lVar2);
        local_b8 = *puVar1;
        uStack_b0 = puVar1[1];
        local_78 = CONCAT44((int)((ulonglong)*(undefined8 *)(lVar9 + 0x50 + lVar2) >> 0x20),
                            0xffffffff);
        uStack_70 = 0;
        local_68 = 0;
        local_c8 = CONCAT44((int)((ulonglong)*(undefined8 *)(lVar9 + lVar2) >> 0x20),uVar6);
        uStack_60 = 0;
        local_58 = 0;
        local_88 = CONCAT44(1,(int)*(undefined8 *)(lVar9 + 0x40 + lVar2));
        uStack_80 = 1;
        local_a8 = 0;
        uStack_a0 = 0;
        local_98 = 0;
        uStack_90 = 0;
        uVar7 = BmUpdateBandTableEntry
                          (param_1,uVar6,'\x01','\0',(longlong)&local_c8,(uint *)0x0,(uint *)0x0);
        if ((int)uVar7 < 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x94,
                      &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar6,(char)uVar7);
          }
          if (uVar11 == 0) {
            uVar11 = uVar7;
          }
        }
        else {
          bVar4 = true;
          lVar2 = *(longlong *)(lVar8 + 0x18f0);
          *(ulonglong *)(lVar2 + lVar9) = local_c8;
          ((ulonglong *)(lVar2 + lVar9))[1] = uStack_c0;
          puVar1 = (undefined8 *)(lVar2 + 0x10 + lVar9);
          *puVar1 = local_b8;
          puVar1[1] = uStack_b0;
          puVar1 = (undefined8 *)(lVar2 + 0x20 + lVar9);
          *puVar1 = local_a8;
          puVar1[1] = uStack_a0;
          puVar1 = (undefined8 *)(lVar2 + 0x30 + lVar9);
          *puVar1 = local_98;
          puVar1[1] = uStack_90;
          puVar1 = (undefined8 *)(lVar2 + 0x40 + lVar9);
          *puVar1 = local_88;
          puVar1[1] = uStack_80;
          puVar1 = (undefined8 *)(lVar2 + 0x50 + lVar9);
          *puVar1 = local_78;
          puVar1[1] = uStack_70;
          puVar1 = (undefined8 *)(lVar2 + 0x60 + lVar9);
          *puVar1 = local_68;
          puVar1[1] = uStack_60;
          *(undefined8 *)(lVar2 + 0x70 + lVar9) = local_58;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar3 = *(undefined8 *)(*(longlong *)(lVar8 + 0x18f0) + 0x10 + lVar9);
            cVar5 = (char)uVar3;
            WPP_SF_dii(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x95,uVar3,uVar6,cVar5,
                       (char)*(undefined8 *)(*(longlong *)(lVar8 + 0x18f0) + 0x18 + lVar9) + -1 +
                       cVar5);
          }
        }
      }
      uVar10 = (ulonglong)(uVar6 + 1);
    } while (uVar6 + 1 < *(uint *)(*(longlong *)(lVar8 + 0x18e8) + 0x18));
    if (bVar4) {
      UpdateLbaFilterTable(param_1);
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar11);
  return uVar11;
}



===== IoctlEraseBand @ 1400049b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint IoctlEraseBand(undefined8 param_1,undefined8 param_2)

{
  uint *puVar1;
  undefined8 *puVar2;
  longlong lVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  int *piVar7;
  longlong lVar8;
  undefined2 uVar9;
  uint *_Src;
  uint uVar10;
  ulonglong uVar11;
  undefined1 auStackY_148 [32];
  undefined1 uVar12;
  uint local_108;
  uint local_104;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_e8;
  ulonglong uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 local_68;
  undefined8 uStack_60;
  ulonglong local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_148;
  local_104 = 0xffffffff;
  local_48 = 0;
  local_e8 = (ulonglong)(uint)local_e8;
  local_100 = 0;
  _Src = (uint *)0x0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_f8 = param_2;
  memset(&local_e8,0,0x74);
  local_108 = 0;
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  uVar5 = (**(code **)(WdfFunctions_01015 + 0x858))(WdfDriverGlobals,param_2,&local_100);
  if ((int)uVar5 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x78,
               &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar5);
    }
    goto LAB_140004f44;
  }
  piVar7 = (int *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_100,0);
  local_48 = 0;
  uStack_60 = 0;
  local_68 = 0x28;
  local_58 = 0;
  uStack_50 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,local_f8,&local_68);
  if (local_58 < 0x20) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140004b51;
    uVar9 = 0x79;
    uVar12 = 0x20;
LAB_140004b41:
    WPP_SF_Pd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
              &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,local_58,uVar12);
    goto LAB_140004b51;
  }
  if (*piVar7 == 0x20) {
    uVar5 = piVar7[6];
    if (uVar5 != 0) {
      uVar10 = uVar5 + 4;
      if (local_58 < uVar10) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar9 = 0x7b;
LAB_140004bdc:
          uVar12 = (undefined1)uVar10;
          goto LAB_140004b41;
        }
      }
      else {
        uVar10 = *(int *)((ulonglong)uVar5 + (longlong)piVar7) + 4 + uVar5;
        if (uVar10 <= local_58) goto LAB_140004c21;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar9 = 0x7c;
          goto LAB_140004bdc;
        }
      }
LAB_140004b51:
      uVar5 = 0xc0000206;
      goto LAB_140004f44;
    }
LAB_140004c21:
    if ((piVar7[6] != 0) &&
       (_Src = (uint *)((ulonglong)(uint)piVar7[6] + (longlong)piVar7), _Src != (uint *)0x0)) {
      uVar5 = *_Src;
      uVar10 = *(uint *)(*(longlong *)(lVar6 + 0x18e8) + 0x10);
      puVar1 = (uint *)(*(longlong *)(lVar6 + 0x18e8) + 0x14);
      if ((uVar5 < uVar10) || (*puVar1 < uVar5)) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7d,
                     &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar5,(char)uVar10,
                     (char)*puVar1);
        }
        goto LAB_140004b9d;
      }
    }
    iVar4 = GetSectorSize(param_1,&local_108);
    if ((iVar4 < 0) || (local_108 == 0)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7e,
                &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids);
      }
      uVar5 = 0xc00000e5;
    }
    else {
      uVar5 = FindBandTableEntry(param_1,piVar7[3],*(longlong *)(piVar7 + 4),0,local_108,'\0',
                                 &local_104);
      uVar10 = local_104;
      if (-1 < (int)uVar5) {
        uVar11 = (ulonglong)local_104;
        uVar5 = LoadBandTableEntries(param_1,local_104,1,'\0');
        if (-1 < (int)uVar5) {
          lVar3 = *(longlong *)(lVar6 + 0x18f0);
          if ((*(int *)(uVar11 * 0x78 + lVar3) == -1) ||
             ((*(longlong *)(uVar11 * 0x78 + 0x18 + lVar3) == 0 && (uVar10 != 0)))) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7f,
                       &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar10);
            }
            uVar5 = 0xc0000225;
          }
          else {
            lVar8 = uVar11 * 0x78;
            uStack_e0 = ((undefined8 *)(lVar8 + lVar3))[1];
            puVar2 = (undefined8 *)(lVar8 + 0x10 + lVar3);
            local_d8 = *puVar2;
            uStack_d0 = puVar2[1];
            local_98 = CONCAT44((int)((ulonglong)*(undefined8 *)(lVar8 + 0x50 + lVar3) >> 0x20),
                                0xffffffff);
            local_a8 = CONCAT44(1,(int)*(undefined8 *)(lVar8 + 0x40 + lVar3));
            uStack_a0 = 1;
            local_e8 = CONCAT44((int)((ulonglong)*(undefined8 *)(lVar8 + lVar3) >> 0x20),uVar10);
            uStack_90 = 0;
            local_88 = 0;
            uStack_80 = 0;
            local_78 = 0;
            local_c8 = 0;
            uStack_c0 = 0;
            local_b8 = 0;
            uStack_b0 = 0;
            uVar5 = BmUpdateBandTableEntry
                              (param_1,uVar10,'\x01',_Src != (uint *)0x0,(longlong)&local_e8,
                               (uint *)0x0,_Src);
            if ((int)uVar5 < 0) {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x80,
                          &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar10,(char)uVar5);
              }
            }
            else {
              lVar3 = *(longlong *)(lVar6 + 0x18f0);
              lVar8 = uVar11 * 0x78;
              *(ulonglong *)(lVar8 + lVar3) = local_e8;
              ((ulonglong *)(lVar8 + lVar3))[1] = uStack_e0;
              puVar2 = (undefined8 *)(lVar8 + 0x10 + lVar3);
              *puVar2 = local_d8;
              puVar2[1] = uStack_d0;
              puVar2 = (undefined8 *)(lVar8 + 0x20 + lVar3);
              *puVar2 = local_c8;
              puVar2[1] = uStack_c0;
              puVar2 = (undefined8 *)(lVar8 + 0x30 + lVar3);
              *puVar2 = local_b8;
              puVar2[1] = uStack_b0;
              puVar2 = (undefined8 *)(lVar8 + 0x40 + lVar3);
              *puVar2 = local_a8;
              puVar2[1] = uStack_a0;
              puVar2 = (undefined8 *)(lVar8 + 0x50 + lVar3);
              *puVar2 = local_98;
              puVar2[1] = uStack_90;
              puVar2 = (undefined8 *)(lVar8 + 0x60 + lVar3);
              *puVar2 = local_88;
              puVar2[1] = uStack_80;
              *(undefined8 *)(lVar8 + 0x70 + lVar3) = local_78;
              if ((_Src == (uint *)0x0) || ((piVar7[1] & 1U) == 0)) {
                EraseBandKey(lVar6,(ulonglong)uVar10,'\x01');
              }
              else {
                memmove(*(void **)(*(longlong *)(lVar6 + 0x1900) + uVar11 * 8),_Src,
                        (ulonglong)(*_Src + 4));
              }
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x81,
                         &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar10);
              }
              uVar5 = UpdateLbaFilterTable(param_1);
            }
          }
        }
      }
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7a,
                &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,*piVar7,0x20);
    }
LAB_140004b9d:
    uVar5 = 0xc000000d;
  }
LAB_140004f44:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,local_f8,uVar5);
  return uVar5;
}



===== IoctlGetBandMetadata @ 140004f98 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint IoctlGetBandMetadata(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  uint *puVar6;
  undefined2 uVar7;
  ulonglong uVar8;
  undefined1 auStackY_c8 [32];
  uint local_88;
  uint local_84;
  void *local_80;
  undefined8 local_78;
  undefined8 local_70;
  longlong lStack_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_78 = 0;
  local_88 = 0;
  local_80 = (void *)0x0;
  local_84 = 0xffffffff;
  local_60 = 0;
  local_38 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_70 = 0;
  lStack_68 = 0;
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x858))(WdfDriverGlobals,param_2,&local_78);
  if ((int)uVar4 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1400053e6;
    uVar7 = 0x5b;
LAB_1400051e3:
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,
             &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar4);
  }
  else {
    puVar6 = (uint *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_78,0);
    local_38 = 0;
    uStack_50 = 0;
    local_58 = 0x28;
    local_48 = 0;
    uStack_40 = 0;
    (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_58);
    if (local_48 < 0x18) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_Pd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5c,
                  &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,local_48,0x18);
      }
      uVar4 = 0xc0000206;
      goto LAB_1400053e6;
    }
    if (*puVar6 == 0x18) {
      uVar4 = puVar6[5];
      if ((((uVar4 != 0) && (uVar1 = *(uint *)(lVar5 + 0x1884), uVar4 <= uVar1)) &&
          (puVar6[4] < uVar1)) && (puVar6[4] + uVar4 <= uVar1)) {
        uVar4 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,uVar4,&local_80);
        if (-1 < (int)uVar4) {
          local_60 = *(ulonglong *)(puVar6 + 4);
          local_70 = *(undefined8 *)puVar6;
          lStack_68 = *(longlong *)(puVar6 + 2);
          memset(local_80,0,local_60 >> 0x20);
          iVar3 = GetSectorSize(param_1,&local_88);
          if ((iVar3 < 0) || (local_88 == 0)) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x60,
                       &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,iVar3);
            }
            uVar4 = 0xc00000e5;
          }
          else {
            uVar4 = FindBandTableEntry(param_1,local_70._4_4_,lStack_68,0,local_88,'\0',&local_84);
            uVar1 = local_84;
            if (-1 < (int)uVar4) {
              uVar8 = (ulonglong)local_84;
              uVar4 = LoadBandTableEntries(param_1,local_84,1,'\0');
              if (-1 < (int)uVar4) {
                if ((*(int *)(uVar8 * 0x78 + *(longlong *)(lVar5 + 0x18f0)) == -1) ||
                   ((*(longlong *)(uVar8 * 0x78 + 0x18 + *(longlong *)(lVar5 + 0x18f0)) == 0 &&
                    (uVar1 != 0)))) {
                  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x61,
                             &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar1);
                  }
                  uVar4 = 0xc0000225;
                }
                else {
                  uVar2 = local_60._4_4_;
                  uVar4 = BmGetBandMetadata(param_1,uVar1,(uint)local_60,local_60._4_4_,
                                            (longlong)local_80);
                  if (-1 < (int)uVar4) {
                    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                      WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x62,
                                &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar2,(char)uVar1);
                    }
                    (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,uVar2);
                  }
                }
              }
            }
          }
          goto LAB_1400053e6;
        }
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1400053e6;
        uVar7 = 0x5f;
        goto LAB_1400051e3;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5e,
                   &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,puVar6[4],(char)uVar4,
                   (char)*(undefined4 *)(lVar5 + 0x1884));
      }
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_Pd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5d,
                &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,(ulonglong)*puVar6,0x18);
    }
    uVar4 = 0xc000000d;
  }
LAB_1400053e6:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar4);
  return uVar4;
}



===== IoctlPerformAuthentication @ 140005434 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint IoctlPerformAuthentication(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  uint *local_res18 [2];
  
  local_res18[0] = (uint *)0x0;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,4,local_res18,0);
  if ((int)uVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x96,
               &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar1);
    }
  }
  else {
    uVar1 = PerformAuthentication
                      (param_1,(byte)*local_res18[0] & 1,(byte)(*local_res18[0] >> 1) & 1);
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar1);
  return uVar1;
}



===== IoctlQueryCapabilities @ 140005508 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint IoctlQueryCapabilities(undefined8 param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  longlong lVar6;
  int *piVar7;
  void *pvVar8;
  longlong lVar9;
  undefined2 uVar10;
  uint uVar11;
  ulonglong uVar12;
  undefined8 uVar13;
  int iVar14;
  undefined8 *local_res10;
  
  uVar5 = 0;
  local_res10 = (undefined8 *)0x0;
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  piVar7 = *(int **)(lVar6 + 0x18e8);
  if (piVar7 == (int *)0x0) {
    piVar7 = (int *)ExAllocatePool2(0x40,0x28,0x47536353);
    *(int **)(lVar6 + 0x18e8) = piVar7;
    if (piVar7 != (int *)0x0) goto LAB_1400055bf;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (WPP_GLOBAL_Control[0x29] != '\0')) {
      uVar10 = 10;
      iVar14 = 0x28;
LAB_1400055a5:
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
               &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,iVar14);
    }
LAB_1400055b5:
    uVar5 = 0xc000009a;
  }
  else {
LAB_1400055bf:
    if (*piVar7 == 0) {
      uVar5 = BmQueryDeviceCapabilities(param_1,(undefined8 *)piVar7);
      puVar1 = *(undefined8 **)(lVar6 + 0x18e8);
      if ((int)uVar5 < 0) {
        *puVar1 = 0;
        puVar1[1] = 0;
        puVar1[2] = 0;
        puVar1[3] = 0;
        puVar1[4] = 0;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                   &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar5);
        }
      }
      else {
        *(undefined4 *)puVar1 = 0x28;
        if (((*(uint *)(*(longlong *)(lVar6 + 0x18e8) + 4) & 1) == 0) ||
           (*(int *)(*(longlong *)(lVar6 + 0x18e8) + 0x18) != 0)) goto LAB_14000566d;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                  &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids);
        }
        uVar5 = 0xc0000184;
      }
    }
    else {
LAB_14000566d:
      if (((*(uint *)(*(longlong *)(lVar6 + 0x18e8) + 4) & 1) != 0) &&
         ((uVar11 = *(uint *)(*(longlong *)(lVar6 + 0x18e8) + 0x18), uVar11 != 0 &&
          (*(longlong *)(lVar6 + 0x18f0) == 0)))) {
        pvVar8 = (void *)ExAllocatePool2(0x40,(ulonglong)uVar11 * 0x78,0x47536353);
        *(void **)(lVar6 + 0x18f0) = pvVar8;
        if (pvVar8 == (void *)0x0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (WPP_GLOBAL_Control[0x29] != '\0')) {
            uVar10 = 0xd;
            iVar14 = *(int *)(*(longlong *)(lVar6 + 0x18e8) + 0x18) * 0x78;
            goto LAB_1400055a5;
          }
          goto LAB_1400055b5;
        }
        uVar11 = *(uint *)(*(longlong *)(lVar6 + 0x18e8) + 0x18);
        *(uint *)(lVar6 + 0x18f8) = uVar11;
        memset(pvVar8,0,(ulonglong)uVar11 * 0x78);
        uVar12 = 0;
        if (*(int *)(lVar6 + 0x18f8) != 0) {
          do {
            uVar11 = (int)uVar12 + 1;
            *(undefined4 *)(uVar12 * 0x78 + *(longlong *)(lVar6 + 0x18f0)) = 0xffffffff;
            uVar12 = (ulonglong)uVar11;
          } while (uVar11 < *(uint *)(lVar6 + 0x18f8));
        }
      }
      lVar9 = *(longlong *)(lVar6 + 0x18e8);
      if ((((*(uint *)(lVar9 + 4) & 1) != 0) && (*(int *)(lVar9 + 0x18) != 0)) &&
         (*(longlong *)(lVar6 + 0x1900) == 0)) {
        iVar14 = ((*(int *)(lVar9 + 0x14) + 7U & 0xfffffffc) + 8) * *(int *)(lVar9 + 0x18);
        lVar9 = ExAllocatePool2(0x40,iVar14,0x47536353);
        *(longlong *)(lVar6 + 0x1900) = lVar9;
        if (lVar9 == 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (WPP_GLOBAL_Control[0x29] != '\0')) {
            uVar10 = 0xe;
            goto LAB_1400055a5;
          }
          goto LAB_1400055b5;
        }
        *(int *)(lVar6 + 0x1908) = iVar14;
        EraseBandKeyTable(lVar6,'\x01');
      }
      if ((((*(uint *)(*(longlong *)(lVar6 + 0x18e8) + 4) & 1) != 0) &&
          (iVar14 = *(int *)(*(longlong *)(lVar6 + 0x18e8) + 0x18), iVar14 != 0)) &&
         (*(longlong *)(lVar6 + 0x1910) == 0)) {
        uVar11 = iVar14 * 0x18 + 8;
        pvVar8 = (void *)ExAllocatePool2(0x40,uVar11,0x47536353);
        *(void **)(lVar6 + 0x1910) = pvVar8;
        if (pvVar8 == (void *)0x0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (WPP_GLOBAL_Control[0x29] != '\0')) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                     &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar11);
          }
          uVar5 = 0xc000009a;
        }
        else {
          *(uint *)(lVar6 + 0x1918) = uVar11;
          memset(pvVar8,0,(ulonglong)uVar11);
        }
      }
    }
  }
  if (param_2 == 0) {
    return uVar5;
  }
  lVar9 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2);
  if ((*(uint *)(lVar9 + 0x10) & 0x40) == 0) {
    (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,0x28);
    uVar5 = 0x80000005;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 4)) goto LAB_1400059b6;
    uVar10 = 0x10;
    uVar11 = 0x28;
  }
  else {
    if ((int)uVar5 < 0) goto LAB_1400059b6;
    uVar13 = 0x28;
    uVar5 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0x28,&local_res10,0);
    if (-1 < (int)uVar5) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        lVar9 = *(longlong *)(lVar6 + 0x18e8);
        WPP_SF_qdi(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar9,uVar13,param_1,
                   (char)*(undefined4 *)(lVar9 + 0x18),(char)*(undefined8 *)(lVar9 + 8));
      }
      puVar1 = *(undefined8 **)(lVar6 + 0x18e8);
      uVar13 = puVar1[1];
      *local_res10 = *puVar1;
      local_res10[1] = uVar13;
      uVar2 = *(undefined4 *)((longlong)puVar1 + 0x14);
      uVar3 = *(undefined4 *)(puVar1 + 3);
      uVar4 = *(undefined4 *)((longlong)puVar1 + 0x1c);
      *(undefined4 *)(local_res10 + 2) = *(undefined4 *)(puVar1 + 2);
      *(undefined4 *)((longlong)local_res10 + 0x14) = uVar2;
      *(undefined4 *)(local_res10 + 3) = uVar3;
      *(undefined4 *)((longlong)local_res10 + 0x1c) = uVar4;
      local_res10[4] = puVar1[4];
      (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,0x28);
      goto LAB_1400059b6;
    }
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1400059b6;
    uVar10 = 0x11;
    uVar11 = uVar5;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
           &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar11);
LAB_1400059b6:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar5);
  return uVar5;
}



===== IoctlRelinquishSilo @ 1400059f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int IoctlRelinquishSilo(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  longlong lVar2;
  undefined1 auStackY_98 [32];
  undefined2 local_48 [4];
  undefined4 local_40;
  undefined8 local_3c;
  undefined8 uStack_34;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_98;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  *(uint *)(lVar2 + 0x1860) = *(uint *)(lVar2 + 0x1860) | 1;
  local_40 = 0x14;
  local_3c = 0;
  uStack_34 = 0;
  iVar1 = IssueSyncIoctl(*(undefined8 *)(lVar2 + 0x1870),*(undefined8 **)(lVar2 + 0x1878),'\x01',
                         0x2dd440,(longlong)&local_40,0x14,0,0,(undefined8 *)0x0);
  local_48[0] = 0x100;
  if (-1 < iVar1) {
    iVar1 = IssueSyncIoctl(*(undefined8 *)(lVar2 + 0x1870),*(undefined8 **)(lVar2 + 0x1878),'\0',
                           0x2d1414,(longlong)local_48,2,0,0,(undefined8 *)0x0);
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  return iVar1;
}



===== IoctlSetBandLocation @ 140005b2c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint IoctlSetBandLocation(undefined8 param_1,undefined8 param_2)

{
  uint *puVar1;
  int *piVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  longlong lVar9;
  undefined2 uVar10;
  ulonglong uVar11;
  uint uVar12;
  ulonglong uVar13;
  longlong lVar14;
  longlong lVar15;
  uint *puVar16;
  undefined1 auStackY_148 [32];
  char cVar17;
  uint local_108;
  uint local_104;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  ulonglong local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  uint local_c8;
  undefined4 uStack_c4;
  undefined8 uStack_c0;
  longlong lStack_b8;
  longlong lStack_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_148;
  local_104 = 0xffffffff;
  local_d0 = 0;
  uStack_c4 = 0;
  local_100 = 0;
  puVar16 = (uint *)0x0;
  local_f0 = 0;
  uStack_e8 = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  local_f8 = param_2;
  memset(&local_c8,0,0x74);
  local_108 = 0;
  lVar14 = (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  uVar7 = (**(code **)(WdfFunctions_01015 + 0x858))(WdfDriverGlobals,param_2,&local_100);
  if ((int)uVar7 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
               &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar7);
    }
    goto LAB_140006326;
  }
  piVar8 = (int *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_100,0);
  local_d0 = 0;
  uStack_e8 = 0;
  local_f0 = 0x28;
  local_e0 = 0;
  uStack_d8 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_f0);
  if (local_e0 < 0x18) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar10 = 0x37;
      cVar17 = '\x18';
LAB_140005cbb:
      WPP_SF_Pd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
                &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,local_e0,cVar17);
    }
    goto LAB_140005ccb;
  }
  if (*piVar8 != 0x18) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,
                &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,*piVar8,0x18);
    }
    goto LAB_140005d17;
  }
  if (local_e0 < (ulonglong)(uint)piVar8[5] + 0x38) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      cVar17 = (char)piVar8[5] + '8';
      uVar10 = 0x39;
      goto LAB_140005cbb;
    }
  }
  else {
    uVar7 = piVar8[4];
    uVar13 = 0x18;
    if (uVar7 == 0) {
LAB_140005dd5:
      piVar2 = (int *)((longlong)piVar8 + (ulonglong)(uint)piVar8[5]);
      if (piVar8[4] != 0) {
        puVar16 = (uint *)((longlong)piVar8 + (ulonglong)(uint)piVar8[4]);
      }
      if ((uint)piVar8[5] < 0x18) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
                  &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids);
        }
      }
      else if (*piVar2 == 0x38) {
        lVar15 = *(longlong *)(piVar2 + 2);
        if (lVar15 < 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar10 = 0x3e;
LAB_140005e9a:
            WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,uVar13,lVar15);
          }
        }
        else {
          lVar15 = *(longlong *)(piVar2 + 4);
          if (0 < lVar15) {
            if (puVar16 != (uint *)0x0) {
              uVar7 = *puVar16;
              uVar12 = *(uint *)(*(longlong *)(lVar14 + 0x18e8) + 0x10);
              puVar1 = (uint *)(*(longlong *)(lVar14 + 0x18e8) + 0x14);
              if ((uVar7 < uVar12) || (*puVar1 < uVar7)) {
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                  WPP_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,
                             &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar7,(char)uVar12,
                             (char)*puVar1);
                }
                goto LAB_140005d17;
              }
            }
            iVar6 = GetSectorSize(param_1,&local_108);
            uVar12 = local_108;
            if (-1 < iVar6) {
              uVar13 = (ulonglong)local_108;
              if (local_108 != 0) {
                lVar15 = *(longlong *)(piVar2 + 2);
                if (lVar15 % (longlong)uVar13 != 0) {
                  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                    uVar10 = 0x42;
LAB_140005f9e:
                    WPP_SF_Pd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
                              &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,lVar15,(char)uVar12);
                  }
                  goto LAB_140005d17;
                }
                uVar7 = FindBandTableEntry(param_1,piVar8[1],*(longlong *)(piVar8 + 2),0,local_108,
                                           '\0',&local_104);
                uVar5 = local_104;
                if ((int)uVar7 < 0) goto LAB_140006326;
                uVar11 = (ulonglong)local_104;
                uVar7 = LoadBandTableEntries(param_1,local_104,1,'\0');
                if ((int)uVar7 < 0) goto LAB_140006326;
                if ((*(int *)(uVar11 * 0x78 + *(longlong *)(lVar14 + 0x18f0)) == -1) ||
                   ((*(longlong *)(uVar11 * 0x78 + 0x18 + *(longlong *)(lVar14 + 0x18f0)) == 0 &&
                    (uVar5 != 0)))) {
                  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x43,
                             &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar5);
                  }
                  uVar7 = 0xc0000225;
                  goto LAB_140006326;
                }
                lVar15 = *(longlong *)(piVar2 + 4);
                if (lVar15 % (longlong)uVar13 == 0) {
                  if (uVar5 == 0) goto LAB_140006074;
                }
                else {
                  if (uVar5 != 0) {
                    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                      uVar10 = 0x44;
                      goto LAB_140005f9e;
                    }
                    goto LAB_140005d17;
                  }
LAB_140006074:
                  lVar15 = *(longlong *)(piVar2 + 2);
                  if ((lVar15 != 0) || (*(longlong *)(piVar2 + 4) != 0x7fffffffffffffff)) {
                    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                      WPP_SF_ii(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,
                                &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,lVar15,
                                (char)*(undefined8 *)(piVar2 + 4) + -1 + (char)lVar15);
                    }
                    goto LAB_140005d17;
                  }
                }
                local_c8 = uVar5;
                uStack_c0 = *(undefined8 *)piVar2;
                lVar9 = uVar11 * 0x78;
                uStack_a8 = *(undefined8 *)(piVar2 + 6);
                local_a0 = *(undefined8 *)(piVar2 + 8);
                uStack_98 = *(undefined8 *)(piVar2 + 10);
                local_90 = *(undefined8 *)(piVar2 + 0xc);
                lVar15 = *(longlong *)(lVar14 + 0x18f0);
                puVar3 = (undefined8 *)(lVar15 + 0x40 + lVar9);
                local_88 = *puVar3;
                uStack_80 = puVar3[1];
                puVar3 = (undefined8 *)(lVar15 + 0x50 + lVar9);
                local_78 = *puVar3;
                uStack_70 = puVar3[1];
                puVar3 = (undefined8 *)(lVar15 + 0x60 + lVar9);
                local_68 = *puVar3;
                uStack_60 = puVar3[1];
                local_58 = *(undefined8 *)(lVar15 + 0x70 + lVar9);
                if (uVar5 == 0) {
                  lStack_b8 = *(longlong *)(*(longlong *)(lVar14 + 0x18f0) + 0x10);
                  lStack_b0 = *(longlong *)(*(longlong *)(lVar14 + 0x18f0) + 0x18);
                }
                else {
                  lStack_b8 = *(longlong *)(piVar2 + 2) / (longlong)uVar13;
                  lStack_b0 = *(longlong *)(piVar2 + 4) / (longlong)uVar13;
                }
                if (((puVar16 == (uint *)0x0) &&
                    (puVar1 = *(uint **)(*(longlong *)(lVar14 + 0x1900) + uVar11 * 8),
                    *puVar1 != 0xffffffff)) &&
                   (*(int *)(*(longlong *)(lVar14 + 0x18f0) + 0x48 + uVar11 * 0x78) != 3)) {
                  puVar16 = puVar1;
                }
                uVar7 = BmUpdateBandTableEntry
                                  (param_1,uVar5,'\0','\0',(longlong)&local_c8,puVar16,puVar16);
                if ((int)uVar7 < 0) {
                  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                    WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,
                              &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar5,(char)uVar7);
                  }
                }
                else {
                  lVar15 = *(longlong *)(lVar14 + 0x18f0);
                  lVar9 = uVar11 * 0x78;
                  *(undefined8 *)(lVar9 + lVar15) = CONCAT44(uStack_c4,local_c8);
                  ((undefined8 *)(lVar9 + lVar15))[1] = uStack_c0;
                  plVar4 = (longlong *)(lVar9 + 0x10 + lVar15);
                  *plVar4 = lStack_b8;
                  plVar4[1] = lStack_b0;
                  puVar3 = (undefined8 *)(lVar9 + 0x20 + lVar15);
                  *puVar3 = uStack_a8;
                  puVar3[1] = local_a0;
                  puVar3 = (undefined8 *)(lVar9 + 0x30 + lVar15);
                  *puVar3 = uStack_98;
                  puVar3[1] = local_90;
                  puVar3 = (undefined8 *)(lVar9 + 0x40 + lVar15);
                  *puVar3 = local_88;
                  puVar3[1] = uStack_80;
                  puVar3 = (undefined8 *)(lVar9 + 0x50 + lVar15);
                  *puVar3 = local_78;
                  puVar3[1] = uStack_70;
                  puVar3 = (undefined8 *)(lVar9 + 0x60 + lVar15);
                  *puVar3 = local_68;
                  puVar3[1] = uStack_60;
                  *(undefined8 *)(lVar9 + 0x70 + lVar15) = local_58;
                  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                    lVar15 = *(longlong *)(uVar11 * 0x78 + 0x10 + *(longlong *)(lVar14 + 0x18f0));
                    lVar14 = *(longlong *)(uVar11 * 0x78 + 0x18 + *(longlong *)(lVar14 + 0x18f0)) +
                             -1 + lVar15;
                    WPP_SF_dii(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x47,lVar14,uVar5,
                               (char)lVar15,(char)lVar14);
                  }
                  uVar7 = UpdateLbaFilterTable(param_1);
                }
                goto LAB_140006326;
              }
            }
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x41,
                       &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,iVar6);
            }
            uVar7 = 0xc00000e5;
            goto LAB_140006326;
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar10 = 0x3f;
            goto LAB_140005e9a;
          }
        }
      }
      else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
                 &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,*piVar2);
      }
LAB_140005d17:
      uVar7 = 0xc000000d;
      goto LAB_140006326;
    }
    uVar12 = uVar7 + 4;
    if (local_e0 < uVar12) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar10 = 0x3a;
LAB_140005d90:
        cVar17 = (char)uVar12;
        goto LAB_140005cbb;
      }
    }
    else {
      uVar12 = *(int *)((ulonglong)uVar7 + (longlong)piVar8) + 4 + uVar7;
      uVar13 = (ulonglong)uVar12;
      if (uVar13 <= local_e0) goto LAB_140005dd5;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar10 = 0x3b;
        goto LAB_140005d90;
      }
    }
  }
LAB_140005ccb:
  uVar7 = 0xc0000206;
LAB_140006326:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,local_f8,uVar7);
  return uVar7;
}



===== IoctlSetBandMetadata @ 140006378 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint IoctlSetBandMetadata(undefined8 param_1,undefined8 param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  uint *puVar5;
  undefined8 uVar6;
  undefined2 uVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  undefined1 auStackY_a8 [32];
  undefined1 uVar11;
  uint local_68;
  uint local_64;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_60 = 0;
  local_64 = 0;
  local_68 = 0xffffffff;
  local_38 = 0;
  puVar10 = (uint *)0x0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x858))(WdfDriverGlobals,param_2,&local_60);
  if ((int)uVar3 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),99,
               &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar3);
    }
    goto LAB_1400067ff;
  }
  puVar5 = (uint *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_60,0);
  local_38 = 0;
  uStack_50 = 0;
  local_58 = 0x28;
  local_48 = 0;
  uStack_40 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_58);
  if (local_48 < 0x20) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1400064f3;
    uVar7 = 100;
    uVar11 = 0x20;
LAB_1400064e3:
    WPP_SF_Pd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,
              &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,local_48,uVar11);
LAB_1400064f3:
    uVar3 = 0xc0000206;
  }
  else {
    if (*puVar5 == 0x20) {
      uVar3 = puVar5[5];
      if ((((uVar3 != 0) && (uVar8 = *(uint *)(lVar4 + 0x1884), uVar3 <= uVar8)) &&
          (puVar5[4] < uVar8)) && (puVar5[4] + uVar3 <= uVar8)) {
        uVar8 = puVar5[7];
        if (uVar8 == 0) {
LAB_1400065fb:
          uVar9 = puVar5[6] + uVar3;
          if (uVar9 <= local_48) {
            if ((puVar5[7] != 0) &&
               (puVar10 = (uint *)((ulonglong)puVar5[7] + (longlong)puVar5), puVar10 != (uint *)0x0)
               ) {
              uVar8 = *puVar10;
              uVar3 = *(uint *)(*(longlong *)(lVar4 + 0x18e8) + 0x10);
              puVar1 = (uint *)(*(longlong *)(lVar4 + 0x18e8) + 0x14);
              if ((uVar8 < uVar3) || (*puVar1 < uVar8)) {
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                  uVar11 = (undefined1)*puVar1;
                  uVar7 = 0x6a;
                  uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
                  goto LAB_1400067e5;
                }
                goto LAB_1400067fa;
              }
            }
            iVar2 = GetSectorSize(param_1,&local_64);
            if ((iVar2 < 0) || (local_64 == 0)) {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6b,
                         &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,iVar2);
              }
              uVar3 = 0xc00000e5;
            }
            else {
              uVar3 = FindBandTableEntry(param_1,puVar5[1],*(longlong *)(puVar5 + 2),0,local_64,'\0'
                                         ,&local_68);
              if (-1 < (int)uVar3) {
                uVar3 = LoadBandTableEntries(param_1,local_68,1,'\0');
                if (-1 < (int)uVar3) {
                  if ((*(int *)((ulonglong)local_68 * 0x78 + *(longlong *)(lVar4 + 0x18f0)) == -1)
                     || ((*(longlong *)
                           ((ulonglong)local_68 * 0x78 + 0x18 + *(longlong *)(lVar4 + 0x18f0)) == 0
                         && (local_68 != 0)))) {
                    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6c,
                               &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,local_68);
                    }
                    uVar3 = 0xc0000225;
                  }
                  else {
                    uVar3 = BmSetBandMetadata(param_1,local_68,puVar5[4],puVar5[5],
                                              (ulonglong)puVar5[6] + (longlong)puVar5,puVar10);
                  }
                }
              }
            }
            goto LAB_1400067ff;
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar7 = 0x69;
            goto LAB_1400065b6;
          }
        }
        else {
          uVar9 = uVar8 + 4;
          if (local_48 < uVar9) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar7 = 0x67;
LAB_1400065b6:
              uVar11 = (undefined1)uVar9;
              goto LAB_1400064e3;
            }
          }
          else {
            uVar9 = *(int *)((ulonglong)uVar8 + (longlong)puVar5) + 4 + uVar8;
            if (uVar9 <= local_48) goto LAB_1400065fb;
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar7 = 0x68;
              goto LAB_1400065b6;
            }
          }
        }
        goto LAB_1400064f3;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar11 = (undefined1)*(undefined4 *)(lVar4 + 0x1884);
        uVar7 = 0x66;
        uVar8 = puVar5[4];
        uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
LAB_1400067e5:
        WPP_SF_ddd(uVar6,uVar7,&WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar8,(char)uVar3,
                   uVar11);
      }
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_Pd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x65,
                &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,(ulonglong)*puVar5,0x20);
    }
LAB_1400067fa:
    uVar3 = 0xc000000d;
  }
LAB_1400067ff:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar3);
  return uVar3;
}



===== IoctlSetBandSecurity @ 140006854 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint IoctlSetBandSecurity(undefined8 param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  int *piVar3;
  undefined8 uVar4;
  int iVar5;
  uint uVar6;
  longlong lVar7;
  uint *puVar8;
  uint *puVar9;
  longlong lVar10;
  undefined2 uVar11;
  int *piVar12;
  uint uVar13;
  uint *puVar14;
  uint *_Src;
  ulonglong uVar15;
  undefined1 auStackY_168 [32];
  char cVar16;
  uint local_128 [2];
  int *local_120;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_f8;
  undefined8 uStack_f0;
  ulonglong local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  uint local_c8;
  undefined4 uStack_c4;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_168;
  local_120 = (int *)CONCAT44(local_120._4_4_,0xffffffff);
  local_110 = 0;
  local_d8 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  piVar12 = (int *)0x0;
  puVar14 = (uint *)0x0;
  local_e8 = 0;
  uStack_e0 = 0;
  _Src = (uint *)0x0;
  local_118 = param_1;
  local_108 = param_2;
  memset(&local_c8,0,0x78);
  local_128[0] = 0;
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  uVar6 = (**(code **)(WdfFunctions_01015 + 0x858))(WdfDriverGlobals,param_2,&local_110);
  if ((int)uVar6 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x48,
               &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar6);
    }
    goto LAB_140007092;
  }
  puVar8 = (uint *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_110,0);
  uStack_f0 = 0;
  local_d8 = 0;
  local_e8 = 0;
  uStack_e0 = 0;
  local_f8 = 0x28;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,local_108,&local_f8);
  if (local_e8 < 0x28) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1400069ec;
    uVar11 = 0x49;
    cVar16 = '(';
LAB_1400069dc:
    WPP_SF_Pd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,
              &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,local_e8,cVar16);
    goto LAB_1400069ec;
  }
  if (*puVar8 != 0x28) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_Pd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4a,
                &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,(ulonglong)*puVar8,0x28);
    }
    goto LAB_140006d0e;
  }
  uVar6 = puVar8[8];
  if ((uVar6 != 0) && (local_e8 < (ulonglong)uVar6 + 0x38)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      cVar16 = (char)uVar6 + '8';
      uVar11 = 0x4b;
      goto LAB_1400069dc;
    }
    goto LAB_1400069ec;
  }
  uVar6 = puVar8[6];
  if (uVar6 == 0) {
LAB_140006af6:
    uVar6 = puVar8[7];
    if (uVar6 == 0) {
LAB_140006b6f:
      uVar6 = puVar8[8];
      if (uVar6 != 0) {
        piVar12 = (int *)((longlong)puVar8 + (ulonglong)uVar6);
      }
      if (puVar8[6] != 0) {
        puVar14 = (uint *)((longlong)puVar8 + (ulonglong)puVar8[6]);
      }
      if (puVar8[7] != 0) {
        _Src = (uint *)((longlong)puVar8 + (ulonglong)puVar8[7]);
      }
      if (uVar6 - 1 < 0x27) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x50,
                  &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids);
        }
      }
      else if (piVar12 == (int *)0x0) {
LAB_140006cb2:
        if (puVar14 == (uint *)0x0) {
LAB_140006d18:
          if (_Src != (uint *)0x0) {
            uVar6 = *_Src;
            uVar13 = *(uint *)(*(longlong *)(lVar7 + 0x18e8) + 0x10);
            puVar9 = (uint *)(*(longlong *)(lVar7 + 0x18e8) + 0x14);
            if ((uVar6 < uVar13) || (*puVar9 < uVar6)) {
              if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140006d0e;
              uVar11 = 0x56;
              goto LAB_140006cf3;
            }
          }
          iVar5 = GetSectorSize(param_1,local_128);
          if ((iVar5 < 0) || (local_128[0] == 0)) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x57,
                       &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,iVar5);
            }
            uVar6 = 0xc00000e5;
            goto LAB_140007092;
          }
          uVar6 = FindBandTableEntry(param_1,puVar8[3],*(longlong *)(puVar8 + 4),0,local_128[0],'\0'
                                     ,(uint *)&local_120);
          piVar3 = local_120;
          if ((int)uVar6 < 0) goto LAB_140007092;
          uVar13 = (uint)local_120;
          uVar15 = (ulonglong)local_120 & 0xffffffff;
          uVar6 = LoadBandTableEntries(local_118,(uint)local_120,1,'\0');
          uVar4 = local_118;
          if ((int)uVar6 < 0) goto LAB_140007092;
          if ((*(int *)(uVar15 * 0x78 + *(longlong *)(lVar7 + 0x18f0)) == -1) ||
             ((*(longlong *)(uVar15 * 0x78 + 0x18 + *(longlong *)(lVar7 + 0x18f0)) == 0 &&
              (uVar13 != 0)))) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x58,
                       &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar13);
            }
            uVar6 = 0xc0000225;
            goto LAB_140007092;
          }
          local_120 = piVar12;
          if (piVar12 == (int *)0x0) {
            if (puVar14 != _Src) goto LAB_140006e85;
          }
          else {
            local_c8 = uVar13;
            lVar2 = *(longlong *)(lVar7 + 0x18f0);
            lVar10 = uVar15 * 0x78;
            puVar1 = (undefined8 *)(lVar2 + 8 + lVar10);
            uStack_c0 = *puVar1;
            uStack_b8 = puVar1[1];
            puVar1 = (undefined8 *)(lVar2 + 0x18 + lVar10);
            uStack_b0 = *puVar1;
            uStack_a8 = puVar1[1];
            puVar1 = (undefined8 *)(lVar2 + 0x28 + lVar10);
            local_a0 = *puVar1;
            uStack_98 = puVar1[1];
            local_90 = *(undefined8 *)(lVar2 + 0x38 + lVar10);
            local_88 = *(undefined8 *)piVar12;
            uStack_70 = *(undefined8 *)(piVar12 + 6);
            local_68 = *(undefined8 *)(piVar12 + 8);
            uStack_60 = *(undefined8 *)(piVar12 + 10);
            local_58 = *(undefined8 *)(piVar12 + 0xc);
            uStack_80 = CONCAT44(*(undefined4 *)
                                  (*(longlong *)(lVar7 + 0x18f0) + 0x4c + uVar15 * 0x78),
                                 (int)*(undefined8 *)(piVar12 + 2));
            local_78 = CONCAT44((int)((ulonglong)*(undefined8 *)(piVar12 + 4) >> 0x20),
                                *(undefined4 *)
                                 (*(longlong *)(lVar7 + 0x18f0) + 0x50 + uVar15 * 0x78));
LAB_140006e85:
            uVar6 = BmUpdateBandTableEntry
                              (local_118,uVar13,'\0',puVar14 != _Src,
                               -(ulonglong)(piVar12 != (int *)0x0) & (ulonglong)&local_c8,puVar14,
                               _Src);
            if ((int)uVar6 < 0) {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x59,
                          &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar13,(char)uVar6);
              }
              goto LAB_140007092;
            }
            if (local_120 != (int *)0x0) {
              lVar2 = *(longlong *)(lVar7 + 0x18f0);
              lVar10 = uVar15 * 0x78;
              *(undefined8 *)(lVar10 + lVar2) = CONCAT44(uStack_c4,local_c8);
              ((undefined8 *)(lVar10 + lVar2))[1] = uStack_c0;
              puVar1 = (undefined8 *)(lVar10 + 0x10 + lVar2);
              *puVar1 = uStack_b8;
              puVar1[1] = uStack_b0;
              puVar1 = (undefined8 *)(lVar10 + 0x20 + lVar2);
              *puVar1 = uStack_a8;
              puVar1[1] = local_a0;
              puVar1 = (undefined8 *)(lVar10 + 0x30 + lVar2);
              *puVar1 = uStack_98;
              puVar1[1] = local_90;
              puVar1 = (undefined8 *)(lVar10 + 0x40 + lVar2);
              *puVar1 = local_88;
              puVar1[1] = uStack_80;
              puVar1 = (undefined8 *)(lVar10 + 0x50 + lVar2);
              *puVar1 = local_78;
              puVar1[1] = uStack_70;
              puVar1 = (undefined8 *)(lVar10 + 0x60 + lVar2);
              *puVar1 = local_68;
              puVar1[1] = uStack_60;
              *(undefined8 *)(lVar10 + 0x70 + lVar2) = local_58;
            }
          }
          piVar12 = local_120;
          if ((_Src == (uint *)0x0) || ((puVar8[1] & 1) == 0)) {
LAB_140006fb5:
            EraseBandKey(lVar7,(ulonglong)piVar3 & 0xffffffff,'\x01');
          }
          else {
            if ((*(int *)(*(longlong *)(lVar7 + 0x18f0) + 0x44 + uVar15 * 0x78) == 3) &&
               (*(int *)(*(longlong *)(lVar7 + 0x18f0) + 0x48 + uVar15 * 0x78) == 3))
            goto LAB_140006fb5;
            memmove(*(void **)(*(longlong *)(lVar7 + 0x1900) + uVar15 * 8),_Src,
                    (ulonglong)(*_Src + 4));
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5a,
                       &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar13,
                       (char)*(undefined4 *)(uVar15 * 0x78 + 0x44 + *(longlong *)(lVar7 + 0x18f0)),
                       (char)*(undefined4 *)(uVar15 * 0x78 + 0x48 + *(longlong *)(lVar7 + 0x18f0)));
          }
          if ((-1 < (int)uVar6) && (piVar12 != (int *)0x0)) {
            uVar6 = UpdateLbaFilterTable(uVar4);
          }
          goto LAB_140007092;
        }
        uVar6 = *puVar14;
        uVar13 = *(uint *)(*(longlong *)(lVar7 + 0x18e8) + 0x10);
        puVar9 = (uint *)(*(longlong *)(lVar7 + 0x18e8) + 0x14);
        if ((uVar13 <= uVar6) && (uVar6 <= *puVar9)) goto LAB_140006d18;
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140006d0e;
        uVar11 = 0x55;
LAB_140006cf3:
        WPP_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,
                   &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar6,(char)uVar13,(char)*puVar9
                  );
      }
      else {
        iVar5 = *piVar12;
        if (iVar5 == 0x38) {
          iVar5 = piVar12[3];
          if (iVar5 == 0) {
            iVar5 = piVar12[1];
            if (iVar5 - 1U < 3) {
              iVar5 = piVar12[2];
              if (iVar5 - 1U < 3) goto LAB_140006cb2;
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                uVar11 = 0x54;
                goto LAB_140006ca0;
              }
            }
            else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar11 = 0x53;
              goto LAB_140006ca0;
            }
          }
          else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar11 = 0x52;
            goto LAB_140006ca0;
          }
        }
        else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar11 = 0x51;
LAB_140006ca0:
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,
                   &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,iVar5);
        }
      }
LAB_140006d0e:
      uVar6 = 0xc000000d;
      goto LAB_140007092;
    }
    uVar13 = uVar6 + 4;
    if (local_e8 < uVar13) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar11 = 0x4e;
LAB_140006ab1:
        cVar16 = (char)uVar13;
        goto LAB_1400069dc;
      }
    }
    else {
      uVar13 = *(int *)((ulonglong)uVar6 + (longlong)puVar8) + 4 + uVar6;
      if (uVar13 <= local_e8) goto LAB_140006b6f;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar11 = 0x4f;
        goto LAB_140006ab1;
      }
    }
  }
  else {
    uVar13 = uVar6 + 4;
    if (local_e8 < uVar13) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar11 = 0x4c;
        goto LAB_140006ab1;
      }
    }
    else {
      uVar13 = *(int *)((ulonglong)uVar6 + (longlong)puVar8) + 4 + uVar6;
      if (uVar13 <= local_e8) goto LAB_140006af6;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar11 = 0x4d;
        goto LAB_140006ab1;
      }
    }
  }
LAB_1400069ec:
  uVar6 = 0xc0000206;
LAB_140007092:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,local_108,uVar6);
  return uVar6;
}



===== IoctlSetSid @ 1400070e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint IoctlSetSid(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  longlong lVar2;
  int *piVar3;
  uint *puVar4;
  undefined2 uVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  undefined1 auStackY_98 [32];
  undefined1 uVar9;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  ulonglong local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_98;
  local_68 = 0;
  local_40 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  puVar6 = (uint *)0x0;
  puVar7 = (uint *)0x0;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x858))(WdfDriverGlobals,param_2,&local_68);
  if ((int)uVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8b,
               &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar1);
    }
    goto LAB_140007477;
  }
  piVar3 = (int *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_68,0);
  local_40 = 0;
  uStack_58 = 0;
  local_60 = 0x28;
  local_50 = 0;
  uStack_48 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_60);
  if (local_50 < 0xc) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140007256;
    uVar5 = 0x8c;
    uVar9 = 0xc;
LAB_140007246:
    WPP_SF_Pd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
              &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,local_50,uVar9);
    goto LAB_140007256;
  }
  if (*piVar3 == 0xc) {
    uVar1 = piVar3[1];
    if (uVar1 == 0) {
LAB_140007326:
      uVar1 = piVar3[2];
      if (uVar1 == 0) {
LAB_14000739f:
        if (piVar3[1] != 0) {
          puVar6 = (uint *)((longlong)piVar3 + (ulonglong)(uint)piVar3[1]);
        }
        if (piVar3[2] != 0) {
          puVar7 = (uint *)((longlong)piVar3 + (ulonglong)(uint)piVar3[2]);
        }
        if (puVar6 == (uint *)0x0) {
LAB_14000741d:
          if (puVar7 != (uint *)0x0) {
            uVar1 = *puVar7;
            uVar8 = *(uint *)(*(longlong *)(lVar2 + 0x18e8) + 0x10);
            puVar4 = (uint *)(*(longlong *)(lVar2 + 0x18e8) + 0x14);
            if ((uVar1 < uVar8) || (*puVar4 < uVar1)) {
              if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1400072a2;
              uVar5 = 0x93;
              goto LAB_1400073fd;
            }
          }
          uVar1 = BmSetSid(param_1,puVar6,puVar7);
          goto LAB_140007477;
        }
        uVar1 = *puVar6;
        uVar8 = *(uint *)(*(longlong *)(lVar2 + 0x18e8) + 0x10);
        puVar4 = (uint *)(*(longlong *)(lVar2 + 0x18e8) + 0x14);
        if ((uVar8 <= uVar1) && (uVar1 <= *puVar4)) goto LAB_14000741d;
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1400072a2;
        uVar5 = 0x92;
LAB_1400073fd:
        WPP_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
                   &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar1,(char)uVar8,(char)*puVar4)
        ;
        goto LAB_1400072a2;
      }
      uVar8 = uVar1 + 4;
      if (local_50 < uVar8) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar5 = 0x90;
LAB_1400072e1:
          uVar9 = (undefined1)uVar8;
          goto LAB_140007246;
        }
      }
      else {
        uVar8 = *(int *)((ulonglong)uVar1 + (longlong)piVar3) + 4 + uVar1;
        if (uVar8 <= local_50) goto LAB_14000739f;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar5 = 0x91;
          goto LAB_1400072e1;
        }
      }
    }
    else {
      uVar8 = uVar1 + 4;
      if (local_50 < uVar8) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar5 = 0x8e;
          goto LAB_1400072e1;
        }
      }
      else {
        uVar8 = *(int *)((ulonglong)uVar1 + (longlong)piVar3) + 4 + uVar1;
        if (uVar8 <= local_50) goto LAB_140007326;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar5 = 0x8f;
          goto LAB_1400072e1;
        }
      }
    }
LAB_140007256:
    uVar1 = 0xc0000206;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8d,
                &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,*piVar3,0xc);
    }
LAB_1400072a2:
    uVar1 = 0xc000000d;
  }
LAB_140007477:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar1);
  return uVar1;
}



===== LoadBandTableEntries @ 1400074c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint LoadBandTableEntries(undefined8 param_1,uint param_2,int param_3,char param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  uint uVar6;
  longlong lVar7;
  
  uVar4 = 0;
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  if ((((*(longlong *)(lVar5 + 0x18f0) != 0) ||
       (uVar4 = IoctlQueryCapabilities(param_1,0), -1 < (int)uVar4)) &&
      (uVar1 = *(uint *)(*(longlong *)(lVar5 + 0x18e8) + 0x18), param_2 < uVar1)) && (param_3 == -1)
     ) {
    param_3 = uVar1 - param_2;
  }
  if (-1 < (int)uVar4) {
    uVar1 = param_2 + param_3;
    do {
      if (uVar1 <= param_2) {
        return uVar4;
      }
      uVar6 = *(uint *)(*(longlong *)(lVar5 + 0x18e8) + 0x18);
      if (uVar6 <= param_2) {
        return uVar4;
      }
      while (uVar2 = param_2, param_2 < uVar6) {
        if (((*(int *)((ulonglong)param_2 * 0x78 + *(longlong *)(lVar5 + 0x18f0)) == -1) ||
            ((*(int *)((ulonglong)param_2 * 0x78 + 0x4c + *(longlong *)(lVar5 + 0x18f0)) == 0 &&
             (param_4 == '\x01')))) || (param_2 = param_2 + 1, uVar2 = param_2, uVar1 <= param_2))
        break;
      }
      do {
        uVar3 = uVar2;
        uVar2 = uVar3 + 1;
        if ((uVar1 <= uVar2) || (uVar6 <= uVar2)) break;
      } while ((*(int *)((ulonglong)uVar2 * 0x78 + *(longlong *)(lVar5 + 0x18f0)) == -1) ||
              ((*(int *)((ulonglong)uVar2 * 0x78 + 0x4c + *(longlong *)(lVar5 + 0x18f0)) == 0 &&
               (param_4 != '\0'))));
      if ((param_2 < uVar1) && (param_2 < uVar6)) {
        uVar4 = BmReadBandTableEntries
                          (param_1,param_2,uVar2 - param_2,
                           *(longlong *)(lVar5 + 0x18f0) + (ulonglong)param_2 * 0x78,param_4);
        lVar7 = (ulonglong)param_2 * 0x78;
        for (; param_2 < uVar2; param_2 = param_2 + 1) {
          uVar6 = 0xffffffff;
          if (-1 < (int)uVar4) {
            uVar6 = param_2;
          }
          *(uint *)(lVar7 + *(longlong *)(lVar5 + 0x18f0)) = uVar6;
          *(undefined4 *)(lVar7 + 8 + *(longlong *)(lVar5 + 0x18f0)) = 0x38;
          *(undefined4 *)(lVar7 + 0x40 + *(longlong *)(lVar5 + 0x18f0)) = 0x38;
          lVar7 = lVar7 + 0x78;
        }
      }
      param_2 = uVar3 + 2;
    } while (-1 < (int)uVar4);
  }
  return uVar4;
}



===== McTemplateK0qqd_EtwWriteTransfer @ 140007668 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqd_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined4 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = local_res20;
  local_38 = &param_5;
  local_40 = 4;
  local_28 = &param_6;
  local_30 = 4;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&PerformAuthenticate,param_3,4,local_58);
  return;
}



===== PerformAuthentication @ 1400076e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint PerformAuthentication(undefined8 param_1,char param_2,char param_3)

{
  undefined8 *puVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  uint *puVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  uint uVar10;
  longlong lVar11;
  uint *puVar12;
  char *pcVar13;
  longlong lVar14;
  undefined8 uVar15;
  ulonglong uVar16;
  uint uVar17;
  ulonglong uVar18;
  undefined8 uVar19;
  undefined1 auStackY_108 [32];
  ulonglong local_b8;
  ulonglong uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
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
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_108;
  lVar11 = (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  lVar4 = *(longlong *)(lVar11 + 0x18e8);
  if (lVar4 != 0) {
    local_b8 = (ulonglong)(uint)local_b8;
    memset(&local_b8,0,0x74);
    bVar7 = false;
    bVar6 = true;
    uVar18 = 0;
    bVar8 = true;
    bVar9 = false;
    if (*(int *)(lVar4 + 0x18) != 0) {
      do {
        bVar7 = bVar9;
        bVar6 = bVar8;
        lVar4 = *(longlong *)(lVar11 + 0x18f0);
        uVar17 = (uint)uVar18;
        lVar14 = uVar18 * 0x78;
        if ((*(int *)(lVar14 + lVar4) != -1) &&
           ((*(longlong *)(lVar14 + 0x18 + lVar4) != 0 || (uVar17 == 0)))) {
          iVar2 = *(int *)(lVar14 + 0x44 + lVar4);
          if ((iVar2 == 2) || (iVar3 = *(int *)(lVar14 + 0x48 + lVar4), iVar3 == 2)) {
            local_b8 = *(ulonglong *)(lVar14 + lVar4);
            uStack_b0 = ((ulonglong *)(lVar14 + lVar4))[1];
            puVar1 = (undefined8 *)(lVar14 + 0x10 + lVar4);
            local_a8 = *puVar1;
            uStack_a0 = puVar1[1];
            puVar1 = (undefined8 *)(lVar14 + 0x20 + lVar4);
            local_98 = *puVar1;
            uStack_90 = puVar1[1];
            puVar1 = (undefined8 *)(lVar14 + 0x30 + lVar4);
            local_88 = *puVar1;
            uStack_80 = puVar1[1];
            puVar1 = (undefined8 *)(lVar14 + 0x40 + lVar4);
            uVar15 = *puVar1;
            uVar19 = puVar1[1];
            puVar1 = (undefined8 *)(lVar14 + 0x50 + lVar4);
            local_68 = *puVar1;
            uStack_60 = puVar1[1];
            puVar1 = (undefined8 *)(lVar14 + 0x60 + lVar4);
            local_58 = *puVar1;
            uStack_50 = puVar1[1];
            local_48 = *(undefined8 *)(lVar14 + 0x70 + lVar4);
            local_78 = uVar15;
            uStack_70 = uVar19;
            if (param_2 == '\0') {
              local_78._4_4_ = (undefined4)((ulonglong)uVar15 >> 0x20);
              if (*(int *)(lVar14 + 0x44 + lVar4) == 2) {
                local_78._4_4_ = 3;
              }
              local_78._0_4_ = (undefined4)uVar15;
              uStack_70._0_4_ = (undefined4)uVar19;
              if (*(int *)(lVar14 + 0x48 + lVar4) == 2) {
                uStack_70._0_4_ = 3;
              }
              uStack_70._4_4_ = (undefined4)((ulonglong)uVar19 >> 0x20);
            }
            puVar5 = *(uint **)(*(longlong *)(lVar11 + 0x1900) + uVar18 * 8);
            puVar12 = (uint *)0x0;
            if (*puVar5 != 0xffffffff) {
              puVar12 = puVar5;
            }
            uVar19 = 0;
            uVar15 = param_1;
            uVar16 = uVar18;
            uVar10 = BmUpdateBandTableEntry
                               (param_1,uVar17,'\0','\0',(longlong)&local_b8,puVar12,puVar12);
            if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 2) != 0) {
              McTemplateK0qqd_EtwWriteTransfer(uVar15,uVar16,uVar19,uVar17,param_2,(char)uVar10);
            }
            if ((int)uVar10 < 0) {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xa0,
                          &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,uVar17,(char)uVar10);
              }
              bVar6 = false;
            }
            else {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                pcVar13 = "authenticated";
                if (param_2 == '\0') {
                  pcVar13 = "un-authenticated";
                }
                WPP_SF_ds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xa1,uVar19,uVar17,pcVar13);
              }
              bVar7 = true;
              if (param_3 != '\0') {
                *(undefined4 *)(uVar18 * 0x78 + 0x44 + *(longlong *)(lVar11 + 0x18f0)) =
                     local_78._4_4_;
                *(undefined4 *)(uVar18 * 0x78 + 0x48 + *(longlong *)(lVar11 + 0x18f0)) =
                     (undefined4)uStack_70;
              }
            }
          }
          else if ((iVar2 == 1) || (iVar3 == 1)) {
            bVar7 = true;
          }
        }
        uVar18 = (ulonglong)(uVar17 + 1);
        bVar8 = bVar6;
        bVar9 = bVar7;
      } while (uVar17 + 1 < *(uint *)(*(longlong *)(lVar11 + 0x18e8) + 0x18));
    }
    if (param_2 != '\0') {
      return -(uint)!bVar7 & 0xc0000001;
    }
    if (bVar6) {
      if (param_3 == '\0') {
        return 0;
      }
      EraseBandKeyTable(lVar11,'\x01');
      return 0;
    }
  }
  return 0xc0000001;
}



===== ReadGroupPolicyActivation @ 1400079d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 ReadGroupPolicyActivation(void)

{
  int iVar1;
  undefined4 local_res8 [2];
  longlong local_res10 [3];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8[0] = 0;
  local_res10[0] = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString
            (&local_28,
             L"\\Registry\\Machine\\Software\\Policies\\Microsoft\\Windows\\EnhancedStorageDevices")
  ;
  RtlInitUnicodeString(&local_18,L"TCGSecurityActivationDisabled");
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x728))
                    (WdfDriverGlobals,0,&local_28,0x20019,0,local_res10);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))
                      (WdfDriverGlobals,local_res10[0],&local_18,local_res8);
    if (iVar1 < 0) {
      local_res8[0] = 0;
    }
  }
  if (local_res10[0] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
  }
  return local_res8[0];
}



===== UpdateLbaFilterTable @ 140007abc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int UpdateLbaFilterTable(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  int iVar7;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  **(undefined4 **)(lVar2 + 0x1910) = 0x20;
  *(undefined4 *)(*(longlong *)(lVar2 + 0x1910) + 0x1c) = 0x20;
  *(undefined4 *)(*(longlong *)(lVar2 + 0x1910) + 0x18) = 0x18;
  *(bool *)(*(longlong *)(lVar2 + 0x1910) + 4) = *(int *)(*(longlong *)(lVar2 + 0x18f0) + 0x44) == 3
  ;
  iVar7 = 0;
  *(bool *)(*(longlong *)(lVar2 + 0x1910) + 0xc) =
       *(int *)(*(longlong *)(lVar2 + 0x18f0) + 0x48) == 3;
  uVar6 = 1;
  puVar3 = (undefined8 *)
           ((ulonglong)*(uint *)(*(longlong *)(lVar2 + 0x1910) + 0x1c) +
           *(longlong *)(lVar2 + 0x1910));
  if (1 < *(uint *)(lVar2 + 0x18f8)) {
    do {
      lVar4 = uVar6 * 0x78;
      lVar1 = *(longlong *)(lVar2 + 0x18f0);
      if ((*(int *)(lVar4 + lVar1) != -1) && (*(longlong *)(lVar4 + 0x18 + lVar1) != 0)) {
        *puVar3 = *(undefined8 *)(lVar4 + 0x10 + lVar1);
        puVar3[1] = *(undefined8 *)(*(longlong *)(lVar2 + 0x18f0) + 0x18 + lVar4);
        *(bool *)(puVar3 + 2) = *(int *)(*(longlong *)(lVar2 + 0x18f0) + 0x44 + lVar4) == 3;
        *(bool *)((longlong)puVar3 + 0x11) =
             *(int *)(*(longlong *)(lVar2 + 0x18f0) + 0x48 + lVar4) == 3;
        puVar3 = puVar3 + 3;
        iVar7 = iVar7 + 1;
      }
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < *(uint *)(lVar2 + 0x18f8));
  }
  *(int *)(*(longlong *)(lVar2 + 0x1910) + 0x14) = iVar7;
  iVar7 = IssueSyncIoctl(*(undefined8 *)(lVar2 + 0x1870),*(undefined8 **)(lVar2 + 0x1878),'\x01',
                         0x2dd444,*(longlong *)(lVar2 + 0x1910),
                         (int)puVar3 - *(int *)(lVar2 + 0x1910),0,0,(undefined8 *)0x0);
  if (((iVar7 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x97,
             &WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,iVar7);
  }
  return iVar7;
}



===== WPP_SF_Pd @ 140007c64 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Pd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,4,0);
  return;
}



===== WPP_SF_ddd @ 140007cb8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ddd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_ddi @ 140007d14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ddi(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,8,0);
  return;
}



===== WPP_SF_dii @ 140007d74 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dii(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,param_2,local_res20,4,
             &param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_diidd @ 140007ddc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_diidd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,0x34,local_res20,4,
             &param_5,8,&param_6,8,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_SF_ds @ 140007e64 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ds(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              char *param_5)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 local_res20 [2];
  
  if (param_5 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_5[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_5 == (char *)0x0) {
    param_5 = "NULL";
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,param_2,local_res20,4,
             param_5,lVar2,0);
  return;
}



===== WPP_SF_i @ 140007eec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_i(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,param_2,&local_res20,8,0)
  ;
  return;
}



===== WPP_SF_ii @ 140007f34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ii(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,0);
  return;
}



===== WPP_SF_qdi @ 140007f84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qdi(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_178432d4dc9f3e6ded3f4dc8b58dd0cb_Traceguids,0x12,&local_res20,8,
             &param_5,4,&param_6,8,0);
  return;
}



===== BmActivateRevertLockingSp @ 140007fec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BmActivateRevertLockingSp(undefined8 param_1,uint *param_2,byte param_3,char param_4)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined2 uVar4;
  int *piVar5;
  uint *puVar6;
  char *pcVar7;
  undefined1 auStackY_e8 [32];
  uint local_a8 [10];
  int local_80 [14];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_a8[8] = 0;
  local_a8[0] = 0;
  local_a8[1] = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  local_a8[6] = 0;
  local_a8[7] = 0;
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  uVar1 = TcglibOpenSession(puVar2,1,(undefined8 *)local_80);
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar1;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return uVar1;
    }
    uVar4 = 0x34;
    goto LAB_1400081da;
  }
  if (param_2 == (uint *)0x0) {
    uVar1 = TcglibGetMsid(puVar2,local_80,(undefined8 *)local_a8);
    if (-1 < (int)uVar1) {
      param_2 = local_a8;
      goto LAB_1400080c1;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar4 = 0x35;
      goto LAB_14000814f;
    }
  }
  else {
LAB_1400080c1:
    piVar5 = local_80;
    puVar3 = puVar2;
    puVar6 = param_2;
    if (param_4 == '\0') {
      uVar1 = TcglibRevertLockingSp(puVar2,piVar5,param_2,param_3 & 1);
      if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 2) != 0) {
        pcVar7 = "Revert";
        goto LAB_140008123;
      }
    }
    else {
      uVar1 = TcglibActivateLockingSp(puVar2,piVar5,param_2);
      if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 2) != 0) {
        pcVar7 = "Activate";
LAB_140008123:
        McTemplateK0sdddd_EtwWriteTransfer(puVar3,piVar5,puVar6,pcVar7,(char)uVar1,0);
      }
    }
    if ((((int)uVar1 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar4 = 0x36;
LAB_14000814f:
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
               &WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,uVar1);
    }
  }
  TcglibCloseSession(puVar2,local_80);
  if ((int)uVar1 < 0) {
    return uVar1;
  }
  puVar3 = (undefined8 *)puVar2[0x31d];
  if (puVar3 != (undefined8 *)0x0) {
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
  }
  uVar1 = InitDevice(param_1,'\x01');
  if ((int)uVar1 < 0) {
    return uVar1;
  }
  if (param_4 == '\0') {
    return uVar1;
  }
  uVar1 = TcglibOpenSession(puVar2,2,(undefined8 *)local_80);
  if (-1 < (int)uVar1) {
    uVar1 = TcglibConfigureLockingSp(puVar2,local_80,param_2);
    TcglibCloseSession(puVar2,local_80);
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    if ((param_3 & 1) == 0) {
      return uVar1;
    }
    uVar1 = TcglibSecureDevice(puVar2,param_2,param_2);
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    *(uint *)(puVar2[0x31d] + 4) = *(uint *)(puVar2[0x31d] + 4) | 4;
    return uVar1;
  }
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return uVar1;
  }
  if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
    return uVar1;
  }
  uVar4 = 0x37;
LAB_1400081da:
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
           &WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,uVar1);
  return uVar1;
}



===== BmConvertAlgorithmIdToOid @ 140008268 =====

char * BmConvertAlgorithmIdToOid(uint param_1)

{
  uint uVar1;
  char *pcVar2;
  
  uVar1 = param_1 & 0xffff;
  pcVar2 = "Unknown";
  if (param_1 != 0xffffffff) {
    if (((param_1 >> 0x10 & 1) == 0) || (7 < uVar1)) {
      if (((param_1 >> 0x11 & 1) != 0) && (uVar1 < 8)) {
        pcVar2 = (&Aes256OidTable)[uVar1];
      }
    }
    else {
      pcVar2 = (&Aes128OidTable)[uVar1];
    }
  }
  return pcVar2;
}



===== BmGetBandMetadata @ 1400082b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BmGetBandMetadata(undefined8 param_1,uint param_2,uint param_3,uint param_4,longlong param_5)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined1 auStackY_a8 [32];
  int local_78 [14];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_a8;
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  uVar1 = TcglibOpenSession(puVar2,2,(undefined8 *)local_78);
  if ((int)uVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,
               &WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,uVar1);
    }
  }
  else {
    uVar1 = TcglibStartTransaction(puVar2,local_78);
    if ((int)uVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,
                 &WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,uVar1);
      }
    }
    else {
      uVar1 = TcglibGetBandMetadata(puVar2,local_78,param_2,param_3,param_4,param_5);
      TcglibStopTransaction(puVar2,local_78,uVar1);
    }
    TcglibCloseSession(puVar2,local_78);
  }
  return uVar1;
}



===== BmQueryDeviceCapabilities @ 140008408 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BmQueryDeviceCapabilities(undefined8 param_1,undefined8 *param_2)

{
  uint uVar1;
  undefined8 *_Dst;
  longlong lVar2;
  undefined *puVar3;
  undefined2 uVar4;
  ulonglong uVar5;
  uint uVar6;
  undefined1 auStackY_148 [32];
  uint local_108 [4];
  uint local_f8;
  char local_f4;
  uint local_f0;
  byte local_b8;
  int local_b4;
  uint local_b0;
  undefined *local_a8;
  longlong local_a0;
  char local_98;
  char local_80;
  byte local_7f;
  ushort local_7c;
  char local_7a;
  ushort local_70;
  uint local_6c;
  uint local_68;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_148;
  memset(&local_f8,0,0xa8);
  _Dst = (undefined8 *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018
                   );
  *param_2 = 0;
  param_2[1] = 0;
  local_108[0] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  uVar1 = TcglibpGetProtocolList(param_1,local_108);
  if ((int)uVar1 < 0) {
LAB_1400084cc:
    uVar6 = uVar1;
    if (-1 < (int)uVar1) {
      uVar6 = (uint)local_b8;
      if (((((local_f8 != 0x200) || (local_b8 == 0)) || (local_7f == 0)) || (local_7a != '\0')) ||
         ((local_7c != 0 && (local_7c < local_b0)))) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0xc00000bb;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
          return 0xc00000bb;
        }
        local_68 = (uint)local_7f;
        uVar4 = 0x22;
LAB_1400088a3:
        WPP_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
                   &WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,local_f8,(char)uVar6,
                   (char)local_68);
        return 0xc00000bb;
      }
      if ((local_b4 == 9) && ((local_a0 != 0x80200000000 || (local_98 == '\x01')))) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_Pd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
                    &WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,local_a0,local_98);
        }
        return 0xc0000184;
      }
      local_f8 = (uint)local_70;
      if (((local_6c < (uint)local_70 << 0x11) || (local_6c % local_68 != 0)) ||
         ((local_b4 == 9 && (local_70 < local_b0)))) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0xc00000bb;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
          return 0xc00000bb;
        }
        uVar4 = 0x24;
        uVar6 = local_6c;
        goto LAB_1400088a3;
      }
      *(undefined4 *)(_Dst + 0x310) = 0x200;
      *(uint *)((longlong)_Dst + 0x1884) = local_6c / local_70;
      *(uint *)(_Dst + 0x311) = local_f0;
      uVar6 = 0x10000;
      if (local_f0 < 0x10000) {
        uVar6 = local_f0;
      }
      uVar6 = (uVar6 + 0x21f & 0xfffffe00) + 8;
      if (*(uint *)(_Dst + 0x313) < uVar6) {
        ExFreePoolWithTag(_Dst[0x312],0);
        *(uint *)(_Dst + 0x313) = uVar6;
        lVar2 = ExAllocatePool2(0x40,uVar6,0x47536353);
        _Dst[0x312] = lVar2;
        if (lVar2 == 0) {
          *(undefined4 *)(_Dst + 0x313) = 0;
          uVar1 = 0xc000009a;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (WPP_GLOBAL_Control[0x29] != '\0')) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
                     &WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,uVar6);
          }
        }
      }
      uVar6 = 0x10000;
      if (*(uint *)(_Dst + 0x311) < 0x10000) {
        uVar6 = *(uint *)(_Dst + 0x311);
      }
      uVar6 = uVar6 + 0x21f & 0xfffffe00;
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      if (uVar6 <= *(uint *)(_Dst + 0x31b)) {
LAB_140008773:
        *(undefined4 *)param_2 = 0x28;
        if (local_b4 == 9) {
          *(uint *)((longlong)param_2 + 4) = *(uint *)((longlong)param_2 + 4) | 1;
        }
        if (local_80 != '\0') {
          *(uint *)((longlong)param_2 + 4) = *(uint *)((longlong)param_2 + 4) | 2;
        }
        if (local_f4 != '\0') {
          *(uint *)((longlong)param_2 + 4) = *(uint *)((longlong)param_2 + 4) | 4;
        }
        *(uint *)(param_2 + 3) = local_b0;
        uVar5 = (ulonglong)local_6c % (ulonglong)local_70;
        param_2[1] = local_a8;
        *(uint *)(param_2 + 4) = local_6c / local_70;
        *(undefined4 *)(param_2 + 2) = 0;
        *(undefined4 *)((longlong)param_2 + 0x14) = 0x20;
        *(undefined4 *)((longlong)param_2 + 0x1c) = 0;
        puVar3 = WPP_GLOBAL_Control;
        if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
          if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
            WPP_SF_Didd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,local_a8,
                        *(undefined4 *)((longlong)param_2 + 4),(char)local_a8,0,0x20);
          }
          puVar3 = WPP_GLOBAL_Control;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            local_a8 = &WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids;
            uVar5 = 0x28;
            puVar3 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
            WPP_SF_ddd(puVar3,0x28,&WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,
                       *(undefined4 *)(param_2 + 3),(char)*(undefined4 *)((longlong)param_2 + 0x1c),
                       (char)*(undefined4 *)(param_2 + 4));
          }
        }
        if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 2) == 0) {
          return uVar1;
        }
        McTemplateK0diqq_EtwWriteTransfer
                  (puVar3,uVar5,local_a8,*(undefined4 *)((longlong)param_2 + 4),(char)param_2[1],
                   (char)*(undefined4 *)(param_2 + 3),(char)*(undefined4 *)(param_2 + 4));
        return uVar1;
      }
      ExFreePoolWithTag(_Dst[0x31a],0);
      *(uint *)(_Dst + 0x31b) = uVar6;
      lVar2 = ExAllocatePool2(0x40,uVar6,0x47536353);
      _Dst[0x31a] = lVar2;
      if (lVar2 != 0) goto LAB_140008773;
      *(undefined4 *)(_Dst + 0x31b) = 0;
      uVar1 = 0xc000009a;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc000009a;
      }
      if (WPP_GLOBAL_Control[0x29] == '\0') {
        return 0xc000009a;
      }
      uVar4 = 0x26;
      goto LAB_14000875e;
    }
  }
  else {
    if (((byte)local_108[0] & 7) == 7) {
      memset(_Dst,0,0x1860);
      *_Dst = param_1;
      *(undefined4 *)(_Dst + 3) = 0xffff1200;
      uVar1 = TcglibpGetCapabilities(_Dst,(int *)&local_f8);
      goto LAB_1400084cc;
    }
    uVar6 = 0xc00000bb;
  }
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return uVar6;
  }
  if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
    return uVar6;
  }
  uVar4 = 0x21;
  uVar1 = uVar6;
LAB_14000875e:
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
           &WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,uVar6);
  return uVar1;
}



===== BmReadBandTableEntries @ 1400088f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BmReadBandTableEntries
               (undefined8 param_1,uint param_2,int param_3,longlong param_4,char param_5)

{
  uint uVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined1 auStackY_b8 [32];
  int local_88 [2];
  int local_80 [7];
  int local_64;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_b8;
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  uVar1 = TcglibOpenSession(puVar3,2,(undefined8 *)local_80);
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar1;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return uVar1;
    }
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
             &WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,uVar1);
    return uVar1;
  }
  local_88[0] = param_3;
  if (param_4 == 0) {
    uVar1 = 0xc000000d;
  }
  else {
    iVar2 = param_3;
    uVar1 = TcglibpCheckContext((longlong)puVar3,local_80);
    if (uVar1 == 0) {
      LOCK();
      if (local_64 == 0) {
        local_64 = 1;
        iVar2 = 0;
      }
      else {
        iVar2 = local_64;
      }
      UNLOCK();
      if (iVar2 == 1) {
        uVar1 = 0x80000011;
        goto LAB_140008a64;
      }
      uVar1 = TcglibpGetBandTableEntries(puVar3,(longlong)local_80,param_2,param_5,param_4,local_88)
      ;
      if ((int)uVar1 < 0) {
        uVar1 = TcglibpCheckError(puVar3,local_80,uVar1);
      }
      LOCK();
      local_64 = 0;
      UNLOCK();
      iVar2 = local_88[0];
    }
    if (-1 < (int)uVar1) {
      if (iVar2 != param_3) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
                    &WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,iVar2,(char)param_3);
        }
        uVar1 = 0xc00000e5;
      }
      goto LAB_140008a92;
    }
  }
LAB_140008a64:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
             &WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,uVar1);
  }
LAB_140008a92:
  TcglibCloseSession(puVar3,local_80);
  return uVar1;
}



===== BmSetBandMetadata @ 140008ac4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BmSetBandMetadata(undefined8 param_1,uint param_2,uint param_3,uint param_4,longlong param_5,
                      uint *param_6)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined1 auStackY_b8 [32];
  int local_78 [14];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_b8;
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  uVar1 = TcglibOpenSession(puVar2,2,(undefined8 *)local_78);
  if ((int)uVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
               &WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,uVar1);
    }
  }
  else {
    uVar1 = TcglibStartTransaction(puVar2,local_78);
    if ((int)uVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
                 &WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,uVar1);
      }
    }
    else {
      uVar1 = TcglibSetBandMetadata(puVar2,local_78,param_2,param_3,param_4,param_5,param_6);
      TcglibStopTransaction(puVar2,local_78,uVar1);
    }
    TcglibCloseSession(puVar2,local_78);
  }
  return uVar1;
}



===== BmSetSid @ 140008c2c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BmSetSid(undefined8 param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  undefined8 *puVar3;
  uint *puVar4;
  uint *puVar5;
  undefined1 auStack_b8 [32];
  uint local_98 [10];
  int local_70 [14];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_b8;
  local_98[8] = 0;
  local_98[0] = 0;
  local_98[1] = 0;
  local_98[2] = 0;
  local_98[3] = 0;
  local_98[4] = 0;
  local_98[5] = 0;
  local_98[6] = 0;
  local_98[7] = 0;
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  uVar1 = TcglibOpenSession(puVar3,1,(undefined8 *)local_70);
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar1;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return uVar1;
    }
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,
             &WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,uVar1);
    return uVar1;
  }
  if ((param_2 == (uint *)0x0) || (puVar5 = param_2, param_3 == (uint *)0x0)) {
    uVar1 = TcglibGetMsid(puVar3,local_70,(undefined8 *)local_98);
    if ((int)uVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,
                 &WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,uVar1);
      }
      goto LAB_140008d8a;
    }
    puVar5 = local_98;
    if (param_2 != (uint *)0x0) {
      puVar5 = param_2;
    }
  }
  puVar4 = local_98;
  if (param_3 != (uint *)0x0) {
    puVar4 = param_3;
  }
  uVar1 = TcglibSetSidPin(puVar3,local_70,puVar5,puVar4);
  if (-1 < (int)uVar1) {
    uVar2 = *(uint *)(puVar3[0x31d] + 4);
    if (puVar4 == local_98) {
      uVar2 = uVar2 & 0xfffffffb;
    }
    else {
      uVar2 = uVar2 | 4;
    }
    *(uint *)(puVar3[0x31d] + 4) = uVar2;
  }
LAB_140008d8a:
  TcglibCloseSession(puVar3,local_70);
  return uVar1;
}



===== BmUpdateBandTableEntry @ 140008dc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint BmUpdateBandTableEntry
               (undefined8 param_1,uint param_2,char param_3,char param_4,longlong param_5,
               uint *param_6,uint *param_7)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined2 uVar3;
  undefined1 auStackY_f8 [32];
  int local_80 [14];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_f8;
  puVar2 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  if (param_3 != '\0') {
    param_6 = (uint *)0x0;
  }
  uVar1 = TcglibOpenSession(puVar2,2,(undefined8 *)local_80);
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar1;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return uVar1;
    }
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
             &WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,uVar1);
    return uVar1;
  }
  uVar1 = TcglibStartTransaction(puVar2,local_80);
  if ((int)uVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
               &WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,uVar1);
    }
    goto LAB_140009174;
  }
  if (param_3 == '\x01') {
    uVar1 = TcglibEraseBand(puVar2,local_80,param_2);
    if (-1 < (int)uVar1) {
      if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 2) != 0) {
        McTemplateK0zqzxzxzxzx_EtwWriteTransfer();
      }
      goto LAB_140008f85;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
               &WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,uVar1);
    }
    goto LAB_140009164;
  }
LAB_140008f85:
  if (param_5 == 0) {
LAB_1400090c6:
    if (param_4 == '\x01') {
      uVar1 = TcglibSetBandPin(puVar2,local_80,param_2,param_6,param_7);
      if ((int)uVar1 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar3 = 0x33;
          goto LAB_140009111;
        }
      }
      else if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 2) != 0) {
        McTemplateK0zqzxzxzxzx_EtwWriteTransfer();
      }
    }
  }
  else {
    uVar1 = TcglibSetBandLocation(puVar2,local_80,param_2,param_6,param_5 + 8);
    if ((int)uVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar3 = 0x31;
LAB_140009111:
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
                 &WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,uVar1);
      }
    }
    else {
      if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 2) != 0) {
        McTemplateK0zqzxzxzxzx_EtwWriteTransfer();
      }
      uVar1 = TcglibSetBandSecurity(puVar2,local_80,param_2,param_6,param_5 + 0x40);
      if (-1 < (int)uVar1) {
        if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 2) != 0) {
          McTemplateK0zqzxzxzxzx_EtwWriteTransfer();
        }
        goto LAB_1400090c6;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar3 = 0x32;
        goto LAB_140009111;
      }
    }
  }
LAB_140009164:
  TcglibStopTransaction(puVar2,local_80,uVar1);
LAB_140009174:
  TcglibCloseSession(puVar2,local_80);
  return uVar1;
}



===== InterpretIeee1667StatusCode @ 1400091b8 =====

uint InterpretIeee1667StatusCode(byte param_1)

{
  if (param_1 < 0xfb) {
    if (param_1 != 0xfa) {
      if ((param_1 != 0x81) && (param_1 != 0x82)) {
        if (param_1 == 0x83) {
          return 0xc0000186;
        }
        if ((param_1 != 0xf7) && (param_1 != 0xf8)) {
LAB_140009205:
          return ~-(uint)(param_1 < 0x80) & 0xc0000001;
        }
      }
      return 0xc000000d;
    }
  }
  else if (param_1 != 0xfb) {
    if (param_1 == 0xfc) {
      return 0xc000000d;
    }
    if (param_1 != 0xfd) {
      if (param_1 == 0xfe) {
        return 0xc0000184;
      }
      if (param_1 != 0xff) goto LAB_140009205;
    }
  }
  return 0xc0000186;
}



===== McTemplateK0diqq_EtwWriteTransfer @ 140009228 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0diqq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined4 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = local_res20;
  local_50 = 4;
  local_48 = &param_5;
  local_40 = 8;
  local_38 = &param_6;
  local_30 = 4;
  local_28 = &param_7;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&DeviceCaps,param_3,5,local_68);
  return;
}



===== McTemplateK0sddii_EtwWriteTransfer @ 1400092c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0sddii_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  longlong lVar1;
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  char *local_68;
  int local_60;
  undefined4 local_5c;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  if (param_4 == (char *)0x0) {
    local_60 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != '\0');
    local_60 = (int)lVar1 + 1;
  }
  local_5c = 0;
  local_58 = &param_5;
  local_50 = 4;
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  local_40 = 4;
  local_48 = &param_6;
  local_38 = &param_7;
  local_30 = 8;
  local_28 = &param_8;
  local_20 = 8;
  local_68 = param_4;
  McGenEventWrite_EtwWriteTransfer("NULL",&SiloCmdError,param_3,6,local_78);
  return;
}



===== McTemplateK0siiiid_EtwWriteTransfer @ 140009388 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0siiiid_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  longlong lVar1;
  undefined1 auStackY_b8 [32];
  undefined8 local_88 [2];
  char *local_78;
  int local_70;
  undefined4 local_6c;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  if (param_4 == (char *)0x0) {
    local_70 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != '\0');
    local_70 = (int)lVar1 + 1;
  }
  local_6c = 0;
  local_68 = &param_5;
  local_60 = 8;
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  local_50 = 8;
  local_58 = &param_6;
  local_48 = &param_7;
  local_40 = 8;
  local_38 = &param_8;
  local_28 = &param_9;
  local_30 = 8;
  local_20 = 4;
  local_78 = param_4;
  McGenEventWrite_EtwWriteTransfer("NULL",&TcgCmdError,param_3,7,local_88);
  return;
}



===== McTemplateK0sisiiiii_EtwWriteTransfer @ 140009460 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0sisiiiii_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
               undefined1 param_5,char *param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 auStackY_d8 [32];
  undefined8 local_a8 [2];
  char *local_98;
  int local_90;
  undefined4 local_8c;
  undefined1 *local_88;
  undefined8 local_80;
  char *local_78;
  int local_70;
  undefined4 local_6c;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  lVar1 = -1;
  if (param_4 == (char *)0x0) {
    local_90 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_4[lVar2] != '\0');
    local_90 = (int)lVar2 + 1;
  }
  local_8c = 0;
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  local_80 = 8;
  local_88 = &param_5;
  if (param_6 == (char *)0x0) {
    local_70 = 5;
  }
  else {
    do {
      lVar1 = lVar1 + 1;
    } while (param_6[lVar1] != '\0');
    local_70 = (int)lVar1 + 1;
  }
  local_68 = &param_7;
  local_6c = 0;
  local_78 = param_6;
  if (param_6 == (char *)0x0) {
    local_78 = "NULL";
  }
  local_58 = &param_8;
  local_48 = &param_9;
  local_60 = 8;
  local_38 = &param_10;
  local_50 = 8;
  local_28 = &param_11;
  local_40 = 8;
  local_30 = 8;
  local_20 = 8;
  local_98 = param_4;
  McGenEventWrite_EtwWriteTransfer(local_88,param_2,param_2,9,local_a8);
  return;
}



===== McTemplateK0sxxxx_EtwWriteTransfer @ 140009588 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0sxxxx_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  longlong lVar1;
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  char *local_68;
  int local_60;
  undefined4 local_5c;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  if (param_4 == (char *)0x0) {
    local_60 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != '\0');
    local_60 = (int)lVar1 + 1;
  }
  local_5c = 0;
  local_58 = &param_5;
  local_50 = 8;
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  local_40 = 8;
  local_48 = &param_6;
  local_38 = &param_7;
  local_30 = 8;
  local_28 = &param_8;
  local_20 = 8;
  local_68 = param_4;
  McGenEventWrite_EtwWriteTransfer("NULL",&TcgError,param_3,6,local_78);
  return;
}



===== McTemplateK0zqzxzxzxzx_EtwWriteTransfer @ 140009650 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0zqzxzxzxzx_EtwWriteTransfer(void)

{
  longlong lVar1;
  longlong lVar2;
  wchar_t *in_R9;
  undefined1 uStack0000000000000028;
  wchar_t *in_stack_00000030;
  wchar_t *in_stack_00000040;
  undefined1 uStack0000000000000048;
  wchar_t *in_stack_00000050;
  undefined1 uStack0000000000000058;
  undefined1 auStackY_108 [32];
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8 [2];
  wchar_t *local_b8;
  int local_b0;
  undefined4 local_ac;
  undefined1 *local_a8;
  undefined8 local_a0;
  wchar_t *local_98;
  int local_90;
  undefined4 local_8c;
  undefined8 *local_88;
  undefined8 local_80;
  wchar_t *local_78;
  int local_70;
  undefined4 local_6c;
  undefined1 *local_68;
  undefined8 local_60;
  wchar_t *local_58;
  int local_50;
  undefined4 local_4c;
  undefined1 *local_48;
  undefined8 local_40;
  wchar_t *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_108;
  lVar1 = -1;
  local_d0 = 0;
  local_d8 = 0;
  if (in_R9 == (wchar_t *)0x0) {
    local_b0 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (in_R9[lVar2] != L'\0');
    local_b0 = (int)lVar2 * 2 + 2;
  }
  local_ac = 0;
  if (in_R9 == (wchar_t *)0x0) {
    in_R9 = L"NULL";
  }
  local_a0 = 4;
  local_a8 = &uStack0000000000000028;
  if (in_stack_00000030 == (wchar_t *)0x0) {
    local_90 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (in_stack_00000030[lVar2] != L'\0');
    local_90 = (int)lVar2 * 2 + 2;
  }
  local_88 = &local_d8;
  local_8c = 0;
  if (in_stack_00000030 == (wchar_t *)0x0) {
    in_stack_00000030 = L"NULL";
  }
  local_80 = 8;
  if (in_stack_00000040 == (wchar_t *)0x0) {
    local_70 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (in_stack_00000040[lVar2] != L'\0');
    local_70 = (int)lVar2 * 2 + 2;
  }
  local_68 = &uStack0000000000000048;
  local_6c = 0;
  if (in_stack_00000040 == (wchar_t *)0x0) {
    in_stack_00000040 = L"NULL";
  }
  local_60 = 8;
  if (in_stack_00000050 == (wchar_t *)0x0) {
    local_50 = 10;
  }
  else {
    do {
      lVar1 = lVar1 + 1;
    } while (in_stack_00000050[lVar1] != L'\0');
    local_50 = (int)lVar1 * 2 + 2;
  }
  local_48 = &uStack0000000000000058;
  local_4c = 0;
  local_28 = &local_d0;
  local_40 = 8;
  if (in_stack_00000050 == (wchar_t *)0x0) {
    in_stack_00000050 = L"NULL";
  }
  local_38 = L"NULL";
  local_30 = 10;
  local_20 = 8;
  local_b8 = in_R9;
  local_98 = in_stack_00000030;
  local_78 = in_stack_00000040;
  local_58 = in_stack_00000050;
  McGenEventWrite_EtwWriteTransfer(local_68,&BandOperation,in_stack_00000040,0xb,local_c8);
  return;
}



===== TcglibEalAllocateIfRecvCommand @ 1400097fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint TcglibEalAllocateIfRecvCommand
               (undefined8 param_1,char param_2,short param_3,uint param_4,undefined8 *param_5)

{
  longlong lVar1;
  uint uVar2;
  bool bVar3;
  
  *param_5 = 0;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  if (param_2 == '\0') {
    if (param_3 != 0) {
      return 0xc0000010;
    }
    bVar3 = *(uint *)(lVar1 + 0x18d8) < param_4;
  }
  else {
    if (param_2 != '\x01') {
      return 0xc0000010;
    }
    if (param_3 == 1) {
      return 0xc0000010;
    }
    bVar3 = *(uint *)(lVar1 + 0x18d8) < (param_4 + 0x21f & 0xfffffe00);
  }
  uVar2 = -(uint)bVar3 & 0xc000009a;
  if (-1 < (int)uVar2) {
    LOCK();
    bVar3 = *(int *)(lVar1 + 0x18dc) == 0;
    if (bVar3) {
      *(int *)(lVar1 + 0x18dc) = 1;
    }
    UNLOCK();
    if (bVar3) {
      *param_5 = *(undefined8 *)(lVar1 + 0x18d0);
      *(char *)(lVar1 + 0x18e2) = param_2;
      *(short *)(lVar1 + 0x18e0) = param_3;
      *(undefined4 *)(lVar1 + 0x18e4) = 0;
    }
    else {
      uVar2 = 0xc000009a;
    }
  }
  return uVar2;
}



===== TcglibEalAllocateIfSendCommand @ 1400098ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint TcglibEalAllocateIfSendCommand
               (undefined8 param_1,char param_2,short param_3,int param_4,undefined8 *param_5)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  *param_5 = 0;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if ((param_2 == '\x01') && (param_3 != 1)) {
    uVar2 = (param_4 + 0x21fU & 0xfffffe00) + 8;
    uVar3 = -(uint)(*(uint *)(lVar1 + 0x1898) < uVar2) & 0xc000009a;
    if (uVar2 <= *(uint *)(lVar1 + 0x1898)) {
      LOCK();
      bVar4 = *(int *)(lVar1 + 0x189c) == 0;
      if (bVar4) {
        *(int *)(lVar1 + 0x189c) = 1;
      }
      UNLOCK();
      if (bVar4) {
        *param_5 = *(undefined8 *)(lVar1 + 0x1890);
        *(undefined1 *)(lVar1 + 0x18a2) = 1;
        *(short *)(lVar1 + 0x18a0) = param_3;
      }
      else {
        uVar3 = 0xc000009a;
      }
    }
  }
  else {
    uVar3 = 0xc0000010;
  }
  return uVar3;
}



===== TcglibEalExecuteCommandSync @ 1400099c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint TcglibEalExecuteCommandSync(undefined8 param_1,longlong param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  longlong lVar4;
  undefined8 *puVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  longlong lVar9;
  undefined *puVar10;
  uint uVar11;
  undefined *local_res10;
  
  puVar10 = PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018;
  lVar9 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if (param_2 == *(longlong *)(lVar9 + 0x1890)) {
    bVar1 = *(byte *)(lVar9 + 0x18a2);
    if (((bVar1 == 1) && (*(short *)(lVar9 + 0x18a0) != 1)) && (0x13 < param_3)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,puVar10,1,
                  (char)*(short *)(lVar9 + 0x18a0));
      }
      *(uint *)(lVar9 + 0x1860) = *(uint *)(lVar9 + 0x1860) | 2;
      *(uint *)(lVar9 + 0x18a4) = param_3;
      return 0;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_dDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)bVar1,puVar10,(uint)bVar1,
                 (char)*(undefined2 *)(lVar9 + 0x18a0),(char)param_3);
    }
  }
  else {
    lVar4 = *(longlong *)(lVar9 + 0x18d0);
    if (param_2 == lVar4) {
      bVar1 = *(byte *)(lVar9 + 0x18e2);
      if ((bVar1 == 0) && (*(short *)(lVar9 + 0x18e0) == 0)) {
        *(undefined4 *)(lVar4 + 6) = 0x1000300;
        *(undefined1 *)(lVar4 + 10) = 2;
        *(undefined4 *)(lVar9 + 0x18e4) = 0xb;
        return 0;
      }
      bVar2 = *(byte *)(lVar9 + 0x18a2);
      if (bVar2 == bVar1) {
        sVar3 = *(short *)(lVar9 + 0x18e0);
        if (*(short *)(lVar9 + 0x18a0) == sVar3) {
          if ((bVar1 != 1) || (sVar3 == 1)) {
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return 0xc0000010;
            }
            if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
              return 0xc0000010;
            }
            WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,(ulonglong)bVar2,(uint)bVar2,
                      (char)*(short *)(lVar9 + 0x18a0));
            return 0xc0000010;
          }
          local_res10 = (undefined *)0x0;
          puVar10 = WPP_GLOBAL_Control;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,WPP_GLOBAL_Control,1,
                      (char)sVar3);
          }
          puVar5 = *(undefined8 **)(lVar9 + 0x1890);
          *puVar5 = 0;
          *(uint *)((longlong)puVar5 + 4) = *(int *)(lVar9 + 0x18a4) + 0x21fU & 0xfffffe00;
          if ((*(uint *)(lVar9 + 0x1860) & 2) == 0) {
            *(undefined1 *)((longlong)puVar5 + 1) = 4;
            lVar4 = *(longlong *)(lVar9 + 0x1890);
            *(undefined8 *)(lVar4 + 8) = 0;
            uVar7 = TcglibReverseUInt32(8);
            *(undefined4 *)(lVar4 + 8) = uVar7;
          }
          else {
            *(undefined1 *)((longlong)puVar5 + 1) = 2;
            lVar4 = *(longlong *)(lVar9 + 0x1890);
            *(undefined8 *)(lVar4 + 8) = 0;
            *(undefined8 *)(lVar4 + 0x10) = 0;
            *(undefined8 *)(lVar4 + 0x18) = 0;
            *(undefined8 *)(lVar4 + 0x20) = 0;
            iVar6 = TcglibReverseUInt32(*(undefined4 *)(*(longlong *)(lVar9 + 0x1890) + 0x38));
            uVar7 = TcglibReverseUInt32(iVar6 + 0x14);
            *(undefined4 *)(lVar4 + 0x24) = uVar7;
            uVar7 = TcglibReverseUInt32(iVar6 + 0x34);
            *(undefined4 *)(lVar4 + 8) = uVar7;
            *(uint *)(lVar9 + 0x1860) = *(uint *)(lVar9 + 0x1860) & 0xfffffffd;
          }
          lVar4 = *(longlong *)(lVar9 + 0x18d0);
          if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) != 0) {
            McTemplateK0sisiiiii_EtwWriteTransfer
                      ((ulonglong)*(byte *)((longlong)puVar5 + 1),&ExecuteSiloCmdStart,puVar10,
                       "ExecuteSiloCmdStart",*(byte *)((longlong)puVar5 + 1),
                       *(char **)(lVar9 + 0x18a8),0,0,0,0,0);
          }
          uVar8 = IssueSyncIoctl(*(undefined8 *)(lVar9 + 0x1870),*(undefined8 **)(lVar9 + 0x1878),
                                 '\0',0x2d140c,*(longlong *)(lVar9 + 0x1890),
                                 (*(int *)(lVar9 + 0x18a4) + 0x21fU & 0xfffffe00) + 8,
                                 *(longlong *)(lVar9 + 0x18d0),
                                 *(uint *)(lVar9 + 0x18d8) & 0xfffffe00,&local_res10);
          if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) != 0) {
            McTemplateK0sisiiiii_EtwWriteTransfer
                      (*(undefined8 *)(lVar9 + 0x18b0),&ExecuteSiloCmdStop,
                       (ulonglong)*(byte *)((longlong)puVar5 + 1),"ExecuteSiloCmdStop",
                       *(byte *)((longlong)puVar5 + 1),*(char **)(lVar9 + 0x18a8),
                       *(undefined1 *)(lVar4 + 7),(char)*(undefined8 *)(lVar9 + 0x18b0),
                       (char)*(undefined8 *)(lVar9 + 0x18b8),(char)*(undefined8 *)(lVar9 + 0x18c0),
                       (char)*(undefined8 *)(lVar9 + 0x18c8));
          }
          if ((int)uVar8 < 0) {
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return uVar8;
            }
            if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
              return uVar8;
            }
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                     &WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,uVar8);
            return uVar8;
          }
          if (local_res10 < (undefined *)0x20) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,local_res10,local_res10);
            }
            return 0xc0000186;
          }
          if ((undefined *)(ulonglong)*(uint *)(lVar9 + 0x18d8) < local_res10) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,local_res10,local_res10);
            }
            return 0xc000009a;
          }
          uVar11 = (uint)*(byte *)(lVar4 + 7);
          puVar10 = local_res10;
          uVar8 = InterpretIeee1667StatusCode(*(byte *)(lVar4 + 7));
          if (-1 < (int)uVar8) {
            *(int *)(lVar9 + 0x18e4) = (int)puVar10;
            return uVar8;
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            puVar10 = &WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids;
            WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                      &WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,uVar11,(char)uVar8);
          }
          if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 1) == 0) {
            return uVar8;
          }
          McTemplateK0sddii_EtwWriteTransfer
                    ((ulonglong)*(byte *)(lVar4 + 7),(ulonglong)*(byte *)((longlong)puVar5 + 1),
                     puVar10,*(char **)(lVar9 + 0x18a8),*(byte *)((longlong)puVar5 + 1),
                     *(byte *)(lVar4 + 7),(char)*(undefined8 *)(lVar9 + 0x18b0),
                     (char)*(undefined8 *)(lVar9 + 0x18b8));
          return uVar8;
        }
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_ddDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
                    (ulonglong)*(ushort *)(lVar9 + 0x18e0),(ulonglong)bVar2,(uint)bVar1,bVar2,
                    (char)*(ushort *)(lVar9 + 0x18e0),(char)*(undefined2 *)(lVar9 + 0x18a0));
      }
    }
  }
  return 0xc0000010;
}



===== TcglibEalFreeCommand @ 140009f00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 TcglibEalFreeCommand(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  bool bVar2;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  if (param_2 == *(longlong *)(lVar1 + 0x1890)) {
    LOCK();
    bVar2 = *(int *)(lVar1 + 0x189c) == 1;
    if (bVar2) {
      *(int *)(lVar1 + 0x189c) = 2;
    }
    UNLOCK();
    if (bVar2) {
      *(undefined2 *)(lVar1 + 0x18a0) = 0xffff;
      *(uint *)(lVar1 + 0x1860) = *(uint *)(lVar1 + 0x1860) & 0xfffffffd;
      *(undefined1 *)(lVar1 + 0x18a2) = 0xff;
      memset(*(void **)(lVar1 + 0x1890),0,(ulonglong)*(uint *)(lVar1 + 0x1898));
      LOCK();
      if (*(int *)(lVar1 + 0x189c) == 2) {
        *(int *)(lVar1 + 0x189c) = 0;
      }
      UNLOCK();
      return 0;
    }
  }
  if (param_2 == *(longlong *)(lVar1 + 0x18d0)) {
    LOCK();
    bVar2 = *(int *)(lVar1 + 0x18dc) == 1;
    if (bVar2) {
      *(int *)(lVar1 + 0x18dc) = 2;
    }
    UNLOCK();
    if (bVar2) {
      *(undefined2 *)(lVar1 + 0x18e0) = 0xffff;
      *(undefined1 *)(lVar1 + 0x18e2) = 0xff;
      *(undefined4 *)(lVar1 + 0x18e4) = 0;
      memset(*(void **)(lVar1 + 0x18d0),0,(ulonglong)*(uint *)(lVar1 + 0x18d8));
      LOCK();
      if (*(int *)(lVar1 + 0x18dc) == 2) {
        *(int *)(lVar1 + 0x18dc) = 0;
      }
      UNLOCK();
      return 0;
    }
  }
  return 0xc000000d;
}



===== TcglibEalGetCommandPayload @ 14000a004 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
TcglibEalGetCommandPayload(undefined8 param_1,longlong param_2,longlong *param_3,uint *param_4)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  *param_3 = 0;
  *param_4 = 0;
  if (param_2 == *(longlong *)(lVar2 + 0x1890)) {
    if ((*(char *)(lVar2 + 0x18a2) == '\x01') && (*(short *)(lVar2 + 0x18a0) != 1)) {
      *param_3 = *(longlong *)(lVar2 + 0x1890) + 0x28;
      uVar3 = 0x10000;
      if (*(uint *)(lVar2 + 0x1888) < 0x10000) {
        uVar3 = *(uint *)(lVar2 + 0x1888);
      }
      *param_4 = uVar3;
      return 0;
    }
  }
  else {
    lVar1 = *(longlong *)(lVar2 + 0x18d0);
    if (param_2 != lVar1) {
      return 0xc000000d;
    }
    if (*(char *)(lVar2 + 0x18e2) == '\0') {
      if (*(short *)(lVar2 + 0x18e0) == 0) {
        *param_3 = lVar1;
        uVar3 = *(uint *)(lVar2 + 0x18e4);
LAB_14000a0d7:
        *param_4 = uVar3;
        return 0;
      }
    }
    else if (((*(char *)(lVar2 + 0x18e2) == '\x01') && (*(short *)(lVar2 + 0x18e0) != 1)) &&
            (uVar3 = *(uint *)(lVar2 + 0x18e4), 0x1f < uVar3)) {
      *param_3 = lVar1 + 0x20;
      uVar3 = uVar3 - 0x20;
      goto LAB_14000a0d7;
    }
  }
  return 0xc0000023;
}



===== TcglibEalGetDeviceCapabilities @ 14000a108 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint TcglibEalGetDeviceCapabilities
               (undefined8 param_1,undefined2 *param_2,undefined2 *param_3,longlong *param_4,
               undefined4 *param_5)

{
  longlong lVar1;
  longlong lVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  uint uVar5;
  longlong lVar6;
  undefined8 *puVar7;
  ulonglong _Size;
  undefined8 uVar8;
  undefined *puVar9;
  undefined *puVar10;
  undefined1 uVar11;
  bool bVar12;
  ulonglong local_res20;
  
  local_res20 = 0;
  *param_4 = 0;
  uVar8 = WdfDriverGlobals;
  puVar9 = PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018;
  *param_5 = 0;
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))(uVar8,param_1,puVar9);
  LOCK();
  bVar12 = *(int *)(lVar6 + 0x18dc) == 0;
  if (bVar12) {
    *(int *)(lVar6 + 0x18dc) = 2;
  }
  UNLOCK();
  if (bVar12) {
    _Size = (ulonglong)*(uint *)(lVar6 + 0x18d8);
    memset(*(void **)(lVar6 + 0x18d0),0,_Size);
    lVar1 = *(longlong *)(lVar6 + 0x18d0);
    *(undefined1 *)(lVar1 + 1) = 1;
    *(undefined4 *)(lVar1 + 4) = 0x200;
    lVar2 = *(longlong *)(lVar6 + 0x18d0);
    *(undefined8 *)(lVar2 + 8) = 0;
    uVar4 = TcglibReverseUInt32(8);
    *(undefined4 *)(lVar2 + 8) = uVar4;
    lVar2 = *(longlong *)(lVar6 + 0x18d0);
    if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) != 0) {
      McTemplateK0siiii_EtwWriteTransfer
                (0,&GetSiloCapsStart,_Size,"GetSiloCapsStart",*(undefined1 *)(lVar1 + 1),0);
    }
    puVar7 = *(undefined8 **)(lVar6 + 0x1878);
    uVar8 = 0;
    uVar5 = IssueSyncIoctl(*(undefined8 *)(lVar6 + 0x1870),puVar7,'\0',0x2d140c,lVar1,0x208,
                           *(longlong *)(lVar6 + 0x18d0),*(uint *)(lVar6 + 0x18d8) & 0xfffffe00,
                           &local_res20);
    if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) != 0) {
      puVar7 = (undefined8 *)&GetSiloCapsStop;
      McTemplateK0siiii_EtwWriteTransfer
                ((ulonglong)*(byte *)(lVar2 + 7),&GetSiloCapsStop,uVar8,"GetSiloCapsStop",
                 *(undefined1 *)(lVar1 + 1),*(byte *)(lVar2 + 7));
    }
    uVar11 = 0;
    if ((int)uVar5 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                 &WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,uVar5);
      }
    }
    else if (local_res20 < 0x20) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_Pd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,local_res20,0x20);
      }
      uVar5 = 0xc0000186;
    }
    else {
      puVar9 = (undefined *)(ulonglong)*(byte *)(lVar2 + 7);
      uVar5 = InterpretIeee1667StatusCode(*(byte *)(lVar2 + 7));
      if ((int)uVar5 < 0) {
        puVar10 = puVar9;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          puVar10 = &WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids;
          puVar7 = (undefined8 *)&DAT_0000000c;
          WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                    &WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,(int)puVar9,(char)uVar5);
          uVar11 = 0;
        }
        if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 1) != 0) {
          McTemplateK0sddii_EtwWriteTransfer
                    ((ulonglong)*(byte *)(lVar1 + 1),puVar7,puVar10,"GetSiloCapabilities",
                     *(byte *)(lVar1 + 1),*(undefined1 *)(lVar2 + 7),uVar11,uVar11);
        }
      }
      else {
        uVar4 = *(undefined4 *)(lVar2 + 0x1c);
        *param_4 = lVar2 + 0x20;
        uVar4 = TcglibReverseUInt32(uVar4);
        uVar3 = *(undefined2 *)(lVar2 + 0xc);
        *param_5 = uVar4;
        uVar3 = TcglibReverseUInt16(uVar3);
        *param_2 = uVar3;
        *param_3 = 0;
      }
    }
    LOCK();
    if (*(int *)(lVar6 + 0x18dc) == 2) {
      *(int *)(lVar6 + 0x18dc) = 0;
    }
    UNLOCK();
  }
  else {
    uVar5 = 0xc000009a;
  }
  return uVar5;
}



===== TcglibEalLogCommand @ 14000a3e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
TcglibEalLogCommand(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   undefined8 param_5,undefined8 param_6)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  *(undefined8 *)(lVar1 + 0x18c0) = param_5;
  *(undefined8 *)(lVar1 + 0x18a8) = param_2;
  *(undefined8 *)(lVar1 + 0x18b8) = param_4;
  *(undefined8 *)(lVar1 + 0x18c8) = param_6;
  *(undefined8 *)(lVar1 + 0x18b0) = param_3;
  return 0;
}



===== TcglibEalLogError @ 14000a464 =====

undefined8
TcglibEalLogError(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 param_4,
                 undefined1 param_5,undefined1 param_6)

{
  if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 1) != 0) {
    McTemplateK0sxxxx_EtwWriteTransfer
              (param_1,param_2,param_3,(char *)param_2,(char)param_3,param_4,param_5,param_6);
  }
  return 0xc00000bb;
}



===== TcglibEalReset @ 14000a4a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint TcglibEalReset(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined4 uVar4;
  uint uVar5;
  longlong lVar6;
  ulonglong _Size;
  undefined8 uVar7;
  undefined *puVar8;
  undefined *puVar9;
  bool bVar10;
  ulonglong local_res18;
  
  local_res18 = 0;
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  LOCK();
  bVar10 = *(int *)(lVar6 + 0x18dc) == 0;
  if (bVar10) {
    *(int *)(lVar6 + 0x18dc) = 2;
  }
  UNLOCK();
  if (bVar10) {
    _Size = (ulonglong)*(uint *)(lVar6 + 0x18d8);
    memset(*(void **)(lVar6 + 0x18d0),0,_Size);
    lVar1 = *(longlong *)(lVar6 + 0x18d0);
    *(undefined1 *)(lVar1 + 1) = 3;
    *(undefined4 *)(lVar1 + 4) = 0x200;
    uVar4 = TcglibReverseUInt32(8);
    lVar2 = *(longlong *)(lVar6 + 0x18d0);
    *(undefined4 *)(lVar2 + 8) = uVar4;
    lVar3 = *(longlong *)(lVar6 + 0x18d0);
    if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) != 0) {
      McTemplateK0siiii_EtwWriteTransfer
                (lVar2,&ResetStart,_Size,"ResetStart",*(undefined1 *)(lVar1 + 1),0);
    }
    uVar7 = 0;
    uVar5 = IssueSyncIoctl(*(undefined8 *)(lVar6 + 0x1870),*(undefined8 **)(lVar6 + 0x1878),'\0',
                           0x2d140c,lVar1,0x208,*(longlong *)(lVar6 + 0x18d0),
                           *(uint *)(lVar6 + 0x18d8) & 0xfffffe00,&local_res18);
    if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 8) != 0) {
      McTemplateK0siiii_EtwWriteTransfer
                ((ulonglong)*(byte *)(lVar3 + 7),&ResetStop,uVar7,"ResetStop",
                 *(undefined1 *)(lVar1 + 1),*(byte *)(lVar3 + 7));
    }
    if ((int)uVar5 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                 &WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,uVar5);
      }
    }
    else if (local_res18 < 8) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,uVar7,local_res18);
      }
      uVar5 = 0xc0000186;
    }
    else {
      puVar8 = (undefined *)(ulonglong)*(byte *)(lVar3 + 7);
      uVar5 = InterpretIeee1667StatusCode(*(byte *)(lVar3 + 7));
      if ((int)uVar5 < 0) {
        puVar9 = puVar8;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          puVar9 = &WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids;
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                   &WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,(int)puVar8);
        }
        if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 1) != 0) {
          McTemplateK0sddii_EtwWriteTransfer
                    ((ulonglong)*(byte *)(lVar3 + 7),(ulonglong)*(byte *)(lVar1 + 1),puVar9,"Reset",
                     *(byte *)(lVar1 + 1),*(byte *)(lVar3 + 7),0,0);
        }
      }
    }
    memset(*(void **)(lVar6 + 0x18d0),0,(ulonglong)*(uint *)(lVar6 + 0x18d8));
    LOCK();
    if (*(int *)(lVar6 + 0x18dc) == 2) {
      *(int *)(lVar6 + 0x18dc) = 0;
    }
    UNLOCK();
  }
  else {
    uVar5 = 0xc000009a;
  }
  return uVar5;
}



===== TcglibEalReuseCommand @ 14000a72c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 TcglibEalReuseCommand(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  bool bVar2;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  if (param_2 == *(longlong *)(lVar1 + 0x1890)) {
    LOCK();
    bVar2 = *(int *)(lVar1 + 0x189c) == 1;
    if (bVar2) {
      *(int *)(lVar1 + 0x189c) = 2;
    }
    UNLOCK();
    if (bVar2) {
      *(uint *)(lVar1 + 0x1860) = *(uint *)(lVar1 + 0x1860) & 0xfffffffd;
      memset(*(void **)(lVar1 + 0x1890),0,(ulonglong)*(uint *)(lVar1 + 0x1898));
      LOCK();
      if (*(int *)(lVar1 + 0x189c) == 2) {
        *(int *)(lVar1 + 0x189c) = 1;
      }
      UNLOCK();
      return 0;
    }
  }
  if (param_2 == *(longlong *)(lVar1 + 0x18d0)) {
    LOCK();
    bVar2 = *(int *)(lVar1 + 0x18dc) == 1;
    if (bVar2) {
      *(int *)(lVar1 + 0x18dc) = 2;
    }
    UNLOCK();
    if (bVar2) {
      *(undefined4 *)(lVar1 + 0x18e4) = 0;
      memset(*(void **)(lVar1 + 0x18d0),0,(ulonglong)*(uint *)(lVar1 + 0x18d8));
      LOCK();
      if (*(int *)(lVar1 + 0x18dc) == 2) {
        *(int *)(lVar1 + 0x18dc) = 1;
      }
      UNLOCK();
      return 0;
    }
  }
  return 0xc000000d;
}



===== WPP_SF_Didd @ 14000a820 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Didd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,0x27,local_res20,4,
             &param_5,8,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_P @ 14000a894 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_P(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,param_2,&local_res20,8,0)
  ;
  return;
}



===== WPP_SF_dD @ 14000a8dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,param_2,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_dDd @ 14000a934 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dDd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,0x16,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_ddDD @ 14000a998 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ddDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_c58960e891bb33f1e651eb720f0375bc_Traceguids,0x17,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== InitializeSecurityCommandBuffers @ 14000aa08 =====

int InitializeSecurityCommandBuffers(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = 0x10000;
  if (*(uint *)(param_1 + 0x1888) < 0x10000) {
    uVar2 = *(uint *)(param_1 + 0x1888);
  }
  uVar2 = (uVar2 + 0x21f & 0xfffffe00) + 8;
  if (*(uint *)(param_1 + 0x1898) < uVar2) {
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x1890),0);
    *(uint *)(param_1 + 0x1898) = uVar2;
    lVar1 = ExAllocatePool2(0x40,uVar2,0x47536353);
    *(longlong *)(param_1 + 0x1890) = lVar1;
    if (lVar1 == 0) {
      *(undefined4 *)(param_1 + 0x1898) = 0;
      iVar3 = -0x3fffff66;
    }
  }
  uVar2 = 0x10000;
  if (*(uint *)(param_1 + 0x1888) < 0x10000) {
    uVar2 = *(uint *)(param_1 + 0x1888);
  }
  uVar2 = uVar2 + 0x21f & 0xfffffe00;
  if ((-1 < iVar3) && (*(uint *)(param_1 + 0x18d8) < uVar2)) {
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x18d0),0);
    *(uint *)(param_1 + 0x18d8) = uVar2;
    lVar1 = ExAllocatePool2(0x40,uVar2,0x47536353);
    *(longlong *)(param_1 + 0x18d0) = lVar1;
    if (lVar1 == 0) {
      *(undefined4 *)(param_1 + 0x18d8) = 0;
      iVar3 = -0x3fffff66;
    }
  }
  return iVar3;
}



===== TcgSiloKsrRestoreDeviceContext @ 14000ab20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int TcgSiloKsrRestoreDeviceContext(undefined8 param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  int iVar5;
  undefined8 *_Dst;
  undefined8 *puVar6;
  void *pvVar7;
  longlong lVar8;
  int *_Src;
  void *_Buf1;
  ulonglong uVar9;
  uint uVar10;
  undefined1 uVar11;
  
  _Dst = (undefined8 *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018
                   );
  lVar8 = KsrCachedContext;
  if (_Dst == (undefined8 *)0x0) {
    iVar5 = -0x3fffff45;
  }
  else {
    if (KsrCachedContext != 0) {
      uVar9 = 0;
      uVar3 = *(ulonglong *)(KsrCachedContext + 0x10);
      _Buf1 = (void *)(*(longlong *)(KsrCachedContext + 0x20) + KsrCachedContext);
      if (uVar3 != 0) {
        uVar11 = 1;
LAB_14000ab9a:
        iVar5 = memcmp(_Buf1,(void *)((longlong)_Dst + 0x1962),0x100);
        if (iVar5 != 0) goto code_r0x00014000abb7;
        memmove(_Dst,(void *)((longlong)_Buf1 + 0x200),0x1860);
        *(undefined4 *)(_Dst + 0x310) = *(undefined4 *)((longlong)_Buf1 + 0x1a60);
        *(undefined4 *)((longlong)_Dst + 0x1884) = *(undefined4 *)((longlong)_Buf1 + 0x1a64);
        *(undefined4 *)(_Dst + 0x311) = *(undefined4 *)((longlong)_Buf1 + 0x1a68);
        if (*(longlong *)((longlong)_Buf1 + 0x1a70) == 0) {
LAB_14000ad11:
          if (*(longlong *)((longlong)_Buf1 + 0x1a80) != 0) {
            pvVar7 = (void *)ExAllocatePool2(0x40,(ulonglong)*(uint *)((longlong)_Buf1 + 0x1a78) *
                                                  0x78,0x47536353);
            _Dst[0x31e] = pvVar7;
            if (pvVar7 == (void *)0x0) goto LAB_14000ace5;
            memmove(pvVar7,(void *)(*(longlong *)((longlong)_Buf1 + 0x1a80) + (longlong)_Buf1),
                    (ulonglong)*(uint *)((longlong)_Buf1 + 0x1a78) * 0x78);
            *(undefined4 *)(_Dst + 799) = *(undefined4 *)((longlong)_Buf1 + 0x1a78);
          }
          if (*(longlong *)((longlong)_Buf1 + 0x1a90) != 0) {
            pvVar7 = (void *)ExAllocatePool2(0x40,*(undefined4 *)((longlong)_Buf1 + 0x1a88),
                                             0x47536353);
            _Dst[0x322] = pvVar7;
            if (pvVar7 == (void *)0x0) goto LAB_14000ace5;
            memmove(pvVar7,(void *)(*(longlong *)((longlong)_Buf1 + 0x1a90) + (longlong)_Buf1),
                    (ulonglong)*(uint *)((longlong)_Buf1 + 0x1a88));
            *(undefined4 *)(_Dst + 0x323) = *(undefined4 *)((longlong)_Buf1 + 0x1a88);
          }
          if (*(longlong *)((longlong)_Buf1 + 0x1aa0) != 0) {
            lVar8 = ExAllocatePool2(0x40,*(undefined4 *)((longlong)_Buf1 + 0x1a98),0x47536353);
            _Dst[800] = lVar8;
            if (lVar8 == 0) goto LAB_14000ace5;
            lVar8 = *(longlong *)((longlong)_Buf1 + 0x1aa0) + (longlong)_Buf1;
            if ((_Dst[0x31d] != 0) && (lVar8 != 0)) {
              uVar2 = *(uint *)(_Dst[0x31d] + 0x14);
              EraseBandKeyTable((longlong)_Dst,'\0');
              uVar10 = 0;
              if (*(int *)(_Dst + 799) != 0) {
                do {
                  _Src = (int *)((ulonglong)uVar10 * ((ulonglong)uVar2 + 7 & 0xfffffffffffffffc) +
                                lVar8);
                  **(int **)(_Dst[800] + (ulonglong)uVar10 * 8) = *_Src;
                  if (*_Src != -1) {
                    memmove(*(void **)(_Dst[800] + (ulonglong)uVar10 * 8),_Src,
                            (ulonglong)(*_Src + 4));
                  }
                  uVar10 = uVar10 + 1;
                } while (uVar10 < *(uint *)(_Dst + 799));
              }
            }
            *(undefined4 *)(_Dst + 0x321) = *(undefined4 *)((longlong)_Buf1 + 0x1a98);
          }
          *_Dst = param_1;
          iVar5 = InitializeSecurityCommandBuffers((longlong)_Dst);
          if (-1 < iVar5) goto LAB_14000ac4f;
        }
        else {
          puVar6 = (undefined8 *)ExAllocatePool2(0x40,0x28,0x47536353);
          _Dst[0x31d] = puVar6;
          if (puVar6 != (undefined8 *)0x0) {
            lVar8 = *(longlong *)((longlong)_Buf1 + 0x1a70);
            uVar4 = ((undefined8 *)(lVar8 + (longlong)_Buf1))[1];
            *puVar6 = *(undefined8 *)(lVar8 + (longlong)_Buf1);
            puVar6[1] = uVar4;
            puVar1 = (undefined8 *)(lVar8 + 0x10 + (longlong)_Buf1);
            uVar4 = puVar1[1];
            puVar6[2] = *puVar1;
            puVar6[3] = uVar4;
            puVar6[4] = *(undefined8 *)(lVar8 + 0x20 + (longlong)_Buf1);
            goto LAB_14000ad11;
          }
LAB_14000ace5:
          iVar5 = -0x3fffff66;
        }
        goto LAB_14000abc8;
      }
    }
LAB_14000abc3:
    iVar5 = -0x3fffff40;
  }
LAB_14000abc8:
  if (_Dst[0x31d] != 0) {
    ExFreePoolWithTag(_Dst[0x31d],0);
    _Dst[0x31d] = 0;
  }
  if (_Dst[0x31e] != 0) {
    ExFreePoolWithTag(_Dst[0x31e],0);
    _Dst[0x31e] = 0;
  }
  if (_Dst[800] != 0) {
    ExFreePoolWithTag(_Dst[800],0);
    _Dst[800] = 0;
  }
  if (_Dst[0x322] != 0) {
    ExFreePoolWithTag(_Dst[0x322],0);
    _Dst[0x322] = 0;
  }
  uVar11 = 0;
LAB_14000ac4f:
  *(undefined1 *)((longlong)_Dst + 0x1961) = uVar11;
  return iVar5;
code_r0x00014000abb7:
  _Buf1 = (void *)((longlong)_Buf1 + *(longlong *)(lVar8 + 0x18));
  uVar9 = uVar9 + 1;
  if (uVar3 <= uVar9) goto LAB_14000abc3;
  goto LAB_14000ab9a;
}



===== TcgSiloKsrSaveDeviceContext @ 14000aea0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TcgSiloKsrSaveDeviceContext(undefined8 param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *_Src;
  undefined8 uVar5;
  void *_Src_00;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined4 *_Dst;
  longlong lVar8;
  uint uVar9;
  longlong lVar10;
  
  _Src_00 = (void *)(**(code **)(WdfFunctions_01015 + 0x650))
                              (WdfDriverGlobals,param_1,
                               PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  lVar8 = 2;
  puVar7 = (undefined8 *)((longlong)_Src_00 + 0x1962);
  puVar6 = param_2;
  do {
    uVar5 = puVar7[1];
    *puVar6 = *puVar7;
    puVar6[1] = uVar5;
    uVar5 = puVar7[3];
    puVar6[2] = puVar7[2];
    puVar6[3] = uVar5;
    uVar5 = puVar7[5];
    puVar6[4] = puVar7[4];
    puVar6[5] = uVar5;
    uVar5 = puVar7[7];
    puVar6[6] = puVar7[6];
    puVar6[7] = uVar5;
    uVar5 = puVar7[9];
    puVar6[8] = puVar7[8];
    puVar6[9] = uVar5;
    uVar5 = puVar7[0xb];
    puVar6[10] = puVar7[10];
    puVar6[0xb] = uVar5;
    uVar5 = puVar7[0xd];
    puVar6[0xc] = puVar7[0xc];
    puVar6[0xd] = uVar5;
    puVar1 = puVar7 + 0xe;
    uVar5 = puVar7[0xf];
    puVar7 = puVar7 + 0x10;
    puVar6[0xe] = *puVar1;
    puVar6[0xf] = uVar5;
    lVar8 = lVar8 + -1;
    puVar6 = puVar6 + 0x10;
  } while (lVar8 != 0);
  memmove(param_2 + 0x40,_Src_00,0x1860);
  uVar9 = 0;
  *(undefined4 *)(param_2 + 0x34c) = *(undefined4 *)((longlong)_Src_00 + 0x1880);
  *(undefined4 *)((longlong)param_2 + 0x1a64) = *(undefined4 *)((longlong)_Src_00 + 0x1884);
  *(undefined4 *)(param_2 + 0x34d) = *(undefined4 *)((longlong)_Src_00 + 0x1888);
  puVar7 = *(undefined8 **)((longlong)_Src_00 + 0x18e8);
  if (puVar7 != (undefined8 *)0x0) {
    uVar5 = puVar7[1];
    puVar6 = param_2 + 0x355;
    *puVar6 = *puVar7;
    param_2[0x356] = uVar5;
    uVar5 = puVar7[3];
    param_2[0x357] = puVar7[2];
    param_2[0x358] = uVar5;
    param_2[0x359] = puVar7[4];
    param_2[0x34e] = 0x1aa8;
    if ((*(uint *)(*(longlong *)((longlong)_Src_00 + 0x18e8) + 4) & 1) != 0) {
      if (*(void **)((longlong)_Src_00 + 0x18f0) != (void *)0x0) {
        puVar6 = param_2 + 0x35a;
        memmove(puVar6,*(void **)((longlong)_Src_00 + 0x18f0),
                (ulonglong)*(uint *)((longlong)_Src_00 + 0x18f8) * 0x78);
        *(undefined4 *)(param_2 + 0x34f) = *(undefined4 *)((longlong)_Src_00 + 0x18f8);
        param_2[0x350] = 0x1ad0;
      }
      if (*(void **)((longlong)_Src_00 + 0x1910) != (void *)0x0) {
        puVar6 = puVar6 + (ulonglong)*(uint *)((longlong)_Src_00 + 0x18f8) * 0xf;
        memmove(puVar6,*(void **)((longlong)_Src_00 + 0x1910),
                (ulonglong)*(uint *)((longlong)_Src_00 + 0x1918));
        *(undefined4 *)(param_2 + 0x351) = *(undefined4 *)((longlong)_Src_00 + 0x1918);
        param_2[0x352] = (longlong)puVar6 - (longlong)param_2;
      }
      lVar8 = *(longlong *)((longlong)_Src_00 + 0x1900);
      if (lVar8 != 0) {
        lVar10 = (longlong)puVar6 + (ulonglong)*(uint *)((longlong)_Src_00 + 0x1918);
        if (((*(longlong *)((longlong)_Src_00 + 0x18e8) != 0) && (lVar10 != 0)) &&
           (iVar2 = *(int *)(*(longlong *)((longlong)_Src_00 + 0x18e8) + 0x14),
           *(int *)((longlong)_Src_00 + 0x18f8) != 0)) {
          do {
            _Dst = (undefined4 *)
                   ((ulonglong)uVar9 * ((ulonglong)(iVar2 + 4) + 3 & 0xfffffffffffffffc) + lVar10);
            *_Dst = **(undefined4 **)(lVar8 + (ulonglong)uVar9 * 8);
            _Src = *(int **)(lVar8 + (ulonglong)uVar9 * 8);
            iVar3 = *_Src;
            if (iVar3 != -1) {
              memmove(_Dst,_Src,(ulonglong)(iVar3 + 4));
            }
            uVar9 = uVar9 + 1;
          } while (uVar9 < *(uint *)((longlong)_Src_00 + 0x18f8));
        }
        uVar4 = *(undefined4 *)((longlong)_Src_00 + 0x1908);
        param_2[0x354] = lVar10 - (longlong)param_2;
        *(undefined4 *)(param_2 + 0x353) = uVar4;
      }
    }
  }
  return;
}



===== RtlStringCopyWorkerW @ 14000b0e8 =====

uint RtlStringCopyWorkerW(short *param_1,undefined8 param_2,longlong *param_3,longlong param_4)

{
  short sVar1;
  short *psVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  
  lVar5 = 0;
  lVar4 = param_4 - (longlong)param_1;
  lVar3 = 0x100;
  do {
    if ((lVar3 == -0x7ffffefe) || (sVar1 = *(short *)(lVar4 + (longlong)param_1), sVar1 == 0))
    break;
    *param_1 = sVar1;
    lVar5 = lVar5 + 1;
    param_1 = param_1 + 1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  psVar2 = param_1 + -1;
  if (lVar3 != 0) {
    psVar2 = param_1;
  }
  *psVar2 = 0;
  if (param_3 != (longlong *)0x0) {
    lVar4 = lVar5 + -1;
    if (lVar3 != 0) {
      lVar4 = lVar5;
    }
    *param_3 = lVar4;
  }
  return ~-(uint)(lVar3 != 0) & 0x80000005;
}



===== RtlStringExHandleFillBehindNullW @ 14000b164 =====

undefined8 RtlStringExHandleFillBehindNullW(longlong param_1,ulonglong param_2)

{
  if (2 < param_2) {
    memset((void *)(param_1 + 2),0,param_2 - 2);
  }
  return 0;
}



===== ext_ms_win_ntos_ksr_l1_1_5_KsrFreePersistedMemory @ 14000b190 =====

undefined8 ext_ms_win_ntos_ksr_l1_1_5_KsrFreePersistedMemory(void)

{
  return 0;
}



===== FxStubDriverUnloadCommon @ 14000b19c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  void **ppvVar1;
  void **ppvVar2;
  
  ppvVar1 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_140019198 != &__KMDF_CLASS_BIND_START) {
    ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_140019198 + 0x50);
    while( true ) {
      for (; (ppvVar1 + 1 <= ppvVar2 && (*ppvVar1 == (void *)0x0)); ppvVar1 = ppvVar1 + 1) {
      }
      if (ppvVar1 < ppvVar2) break;
      ppvVar1 = ppvVar2;
LAB_14000b1f5:
      if (ppvVar1 == (void **)0x0) goto LAB_14000b24b;
      if (ppvVar2 <= ppvVar1) goto LAB_14000b263;
      if (ppvVar1[8] == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      else {
        (*ppvVar1[8])(WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      ppvVar1 = (void **)((longlong)ppvVar1 + (ulonglong)*(uint *)ppvVar1);
    }
    if ((ppvVar1 + 10 <= ppvVar2) && (*(uint *)ppvVar1 == 0x50)) goto LAB_14000b1f5;
LAB_14000b24b:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_14000b263:
  WdfVersionUnbind(&DAT_140019460,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 14000b2a0 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 14000b2d4 =====

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
    iVar1 = DriverEntry(0,param_2);
  }
  else {
    _DAT_140019460 = 0x2080000;
    _DAT_140019468 = &DAT_140019240;
    RtlCopyUnicodeString(&DAT_140019460);
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_140019460,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_140019448 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_140019460);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_140019198 != &__KMDF_CLASS_BIND_START) {
          local_1c = 0;
          uStack_18 = 0;
          local_28 = &GUID_WDF_LOADER_INTERFACE_DRIVER_ENTRY_FAILURE;
          local_14 = 0;
          local_20 = 0x18;
          iVar2 = WdfLdrQueryInterface(&local_28);
          if (-1 < iVar2) {
            (*(code *)CONCAT44(local_14,uStack_18))(&WdfBindInfo,WdfDriverGlobals);
          }
        }
      }
      FxStubDriverUnloadCommon();
    }
  }
  return iVar1;
}



===== FxStubDriverUnload @ 14000b460 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_140019448 != (code *)0x0) && (DAT_140019448 != FxStubDriverUnload)) {
    (*DAT_140019448)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 14000b494 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x00014000b4b9) */
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
    if ((void **)0x14001918f < ppvVar2) break;
    if (((&__KMDF_CLASS_BIND_END < ppvVar2 + 10) || (*(uint *)ppvVar2 != 0x50)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_140019198 = (undefined *)ppvVar2;
    if (ppvVar2[7] == (code *)0x0) {
      iVar1 = WdfVersionBindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: VersionBindClass WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,ppvVar2,ppvVar2[1],iVar1);
        return iVar1;
      }
    }
    else {
      iVar1 = (*ppvVar2[7])(WdfVersionBindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: ClientBindClass %p, WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,ppvVar2[7],ppvVar2,ppvVar2[1],iVar1);
        return iVar1;
      }
    }
    ppvVar2 = (void **)((ulonglong)*(uint *)ppvVar2 + (longlong)ppvVar2);
  }
  return iVar1;
}



===== FxStubInitTypes @ 14000b61c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x00014000b639) */
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
    if ((void **)0x1400191af < ppvVar2) break;
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



===== TcglibActivateLockingSp @ 14000b6e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint TcglibActivateLockingSp(undefined8 *param_1,int *param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  int *piVar5;
  undefined1 auStackY_98 [32];
  undefined1 local_58 [8];
  uint local_50 [10];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_98;
  if (*(int *)(param_1 + 4) != 0x200) {
    return 0xc00000bb;
  }
  puVar4 = param_1;
  piVar5 = param_2;
  uVar1 = TcglibpCheckContext((longlong)param_1,param_2);
  if (uVar1 != 0) {
    return uVar1;
  }
  LOCK();
  iVar2 = piVar5[7];
  if (iVar2 == 0) {
    piVar5[7] = 1;
    iVar2 = 0;
  }
  UNLOCK();
  if (iVar2 == 1) {
    return 0x80000011;
  }
  local_50[8] = 0;
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  if (param_3 == (uint *)0x0) {
    uVar1 = TcglibpGetMsid(puVar4,(longlong)piVar5,local_50);
    param_3 = local_50;
    if (-1 < (int)uVar1) goto LAB_14000b76e;
LAB_14000b799:
    uVar1 = TcglibpCheckError(param_1,param_2,uVar1);
    if ((int)uVar1 < 0) goto LAB_14000b7de;
  }
  else {
LAB_14000b76e:
    uVar3 = TcglibpAuthenticateSession(param_1,(longlong)param_2,0x900000006,param_3);
    uVar1 = (uint)uVar3;
    if (((int)uVar1 < 0) ||
       (uVar1 = TcglibpActivateLockingSp(param_1,(longlong)param_2), (int)uVar1 < 0))
    goto LAB_14000b799;
  }
  local_58[0] = 1;
  uVar1 = TcglibpSetTableColumnData(param_1,(longlong)param_2,0x20100030001,8,local_58,1,8);
LAB_14000b7de:
  LOCK();
  param_2[7] = 0;
  UNLOCK();
  return uVar1;
}



===== TcglibCloseSession @ 14000b808 =====

uint TcglibCloseSession(undefined8 *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  
  uVar3 = 0;
  iVar2 = 0;
  LOCK();
  iVar1 = param_2[7];
  if (iVar1 == 0) {
    param_2[7] = 1;
  }
  else {
    iVar2 = iVar1;
  }
  UNLOCK();
  if (iVar2 == 1) {
    return 0x80000011;
  }
  LOCK();
  iVar1 = *param_2;
  *param_2 = 3;
  UNLOCK();
  if (iVar1 == 2) {
    if (((*(longlong *)(param_2 + 10) != 0) || (*(longlong *)(param_2 + 0xc) != 0)) ||
       (uVar3 = TcglibpAllocateRequestResources
                          (*param_1,'\x01',(short)param_2[6],0x800,(longlong *)(param_2 + 10),
                           (longlong *)(param_2 + 0xc)), -1 < (int)uVar3)) {
      uVar4 = TcglibpCloseSession(param_1,(longlong)param_2);
      uVar3 = (uint)uVar4;
      if (-1 < (int)uVar3) goto LAB_14000b8a6;
    }
    uVar3 = TcglibpCheckError(param_1,param_2,uVar3);
  }
LAB_14000b8a6:
  LOCK();
  param_2[7] = 0;
  UNLOCK();
  if (((iVar1 - 1U & 0xfffffffc) == 0) && (iVar1 != 3)) {
    param_1[2] = 0;
    LOCK();
    *(undefined4 *)(param_1 + 1) = 0;
    UNLOCK();
  }
  else {
    uVar3 = 0xc000000d;
  }
  return uVar3;
}



===== TcglibConfigureLockingSp @ 14000b8e8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint TcglibConfigureLockingSp(undefined8 *param_1,int *param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  int *piVar6;
  uint *puVar7;
  undefined1 auStack_48 [32];
  uint local_28 [2];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_48;
  local_28[0] = 0;
  local_28[1] = 0;
  if (*(int *)(param_1 + 4) == 0x200) {
    piVar6 = param_2;
    uVar2 = TcglibpCheckContext((longlong)param_1,param_2);
    if (uVar2 == 0) {
      iVar3 = 0;
      LOCK();
      iVar1 = piVar6[7];
      if (iVar1 == 0) {
        piVar6[7] = 1;
      }
      else {
        iVar3 = iVar1;
      }
      UNLOCK();
      if (iVar3 == 1) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                  &WPP_127317a3aac038578d69cb8ccf054e38_Traceguids);
        }
        uVar2 = 0x80000011;
      }
      else {
        puVar7 = local_28;
        if (param_3 != (uint *)0x0) {
          puVar7 = param_3;
        }
        uVar5 = TcglibpAuthenticateSession(param_1,(longlong)piVar6,0x900010001,puVar7);
        uVar2 = (uint)uVar5;
        if (uVar2 == 0) {
          uVar4 = TcglibpConfigureLockingSp(param_1,(longlong)param_2);
          uVar2 = 0;
          if (uVar4 != 0) {
            uVar2 = TcglibpCheckError(param_1,param_2,uVar4);
          }
        }
        else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                   &WPP_127317a3aac038578d69cb8ccf054e38_Traceguids,uVar2);
        }
        LOCK();
        param_2[7] = 0;
        UNLOCK();
      }
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
               &WPP_127317a3aac038578d69cb8ccf054e38_Traceguids,uVar2);
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
               &WPP_127317a3aac038578d69cb8ccf054e38_Traceguids,*(int *)(param_1 + 4));
    }
    uVar2 = 0xc00000bb;
  }
  return uVar2;
}



===== TcglibEraseBand @ 14000ba84 =====

uint TcglibEraseBand(undefined8 *param_1,int *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = param_2;
  uVar2 = TcglibpCheckContext((longlong)param_1,param_2);
  if ((int)uVar2 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
               &WPP_127317a3aac038578d69cb8ccf054e38_Traceguids,uVar2);
    }
  }
  else {
    iVar3 = 0;
    LOCK();
    iVar1 = piVar4[7];
    if (iVar1 == 0) {
      piVar4[7] = 1;
    }
    else {
      iVar3 = iVar1;
    }
    UNLOCK();
    if (iVar3 == 1) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
                &WPP_127317a3aac038578d69cb8ccf054e38_Traceguids);
      }
      uVar2 = 0x80000011;
    }
    else {
      uVar2 = TcglibpEraseBand(param_1,(longlong)piVar4,param_3);
      if ((int)uVar2 < 0) {
        uVar2 = TcglibpCheckError(param_1,param_2,uVar2);
      }
      LOCK();
      param_2[7] = 0;
      UNLOCK();
    }
  }
  return uVar2;
}



===== TcglibGetBandMetadata @ 14000bb70 =====

uint TcglibGetBandMetadata
               (undefined8 *param_1,int *param_2,uint param_3,uint param_4,uint param_5,
               longlong param_6)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = param_2;
  uVar2 = TcglibpCheckContext((longlong)param_1,param_2);
  if ((int)uVar2 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_127317a3aac038578d69cb8ccf054e38_Traceguids,uVar2);
    }
  }
  else {
    iVar3 = 0;
    LOCK();
    iVar1 = piVar4[7];
    if (iVar1 == 0) {
      piVar4[7] = 1;
    }
    else {
      iVar3 = iVar1;
    }
    UNLOCK();
    if (iVar3 == 1) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
                &WPP_127317a3aac038578d69cb8ccf054e38_Traceguids);
      }
      uVar2 = 0x80000011;
    }
    else {
      uVar2 = TcglibpGetBandMetadata(param_1,(longlong)piVar4,param_3,param_4,param_5,param_6);
      if ((int)uVar2 < 0) {
        uVar2 = TcglibpCheckError(param_1,param_2,uVar2);
      }
      LOCK();
      param_2[7] = 0;
      UNLOCK();
    }
  }
  return uVar2;
}



===== TcglibGetMsid @ 14000bc74 =====

uint TcglibGetMsid(undefined8 *param_1,int *param_2,undefined8 *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  if (param_3 == (undefined8 *)0x0) {
    uVar2 = 0xc000000d;
  }
  else {
    *param_3 = 0;
    param_3[1] = 0;
    param_3[2] = 0;
    param_3[3] = 0;
    *(undefined4 *)(param_3 + 4) = 0;
    piVar4 = param_2;
    uVar2 = TcglibpCheckContext((longlong)param_1,param_2);
    if (-1 < (int)uVar2) {
      iVar3 = 0;
      LOCK();
      iVar1 = piVar4[7];
      if (iVar1 == 0) {
        piVar4[7] = 1;
      }
      else {
        iVar3 = iVar1;
      }
      UNLOCK();
      if (iVar3 == 1) {
        uVar2 = 0x80000011;
      }
      else {
        uVar2 = TcglibpGetMsid(param_1,(longlong)piVar4,(undefined4 *)param_3);
        if ((int)uVar2 < 0) {
          uVar2 = TcglibpCheckError(param_1,param_2,uVar2);
        }
        LOCK();
        param_2[7] = 0;
        UNLOCK();
      }
    }
  }
  return uVar2;
}



===== TcglibOpenSession @ 14000bd04 =====

uint TcglibOpenSession(undefined8 *param_1,int param_2,undefined8 *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  LOCK();
  iVar1 = *(int *)(param_1 + 1);
  if (iVar1 == 0) {
    *(int *)(param_1 + 1) = 1;
  }
  else {
    iVar2 = iVar1;
  }
  UNLOCK();
  if (iVar2 == 1) {
    uVar3 = 0x80000011;
  }
  else {
    uVar3 = TcglibpOpenSessionWithRetry(param_1,param_3,(ulonglong)(param_2 != 1) + 0x20500000001);
    if ((int)uVar3 < 0) {
      LOCK();
      *(undefined4 *)(param_1 + 1) = 0;
      UNLOCK();
    }
  }
  return uVar3;
}



===== TcglibReverseBytes @ 14000bd68 =====

void TcglibReverseBytes(undefined1 *param_1,uint param_2)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  
  uVar4 = 0;
  if (param_2 >> 1 != 0) {
    puVar5 = param_1;
    do {
      uVar1 = *puVar5;
      iVar2 = param_2 - uVar4;
      uVar4 = uVar4 + 1;
      uVar3 = iVar2 - 1;
      *puVar5 = param_1[uVar3];
      puVar5 = puVar5 + 1;
      param_1[uVar3] = uVar1;
    } while (uVar4 < param_2 >> 1);
  }
  return;
}



===== TcglibReverseUInt16 @ 14000bdb0 =====

undefined2 TcglibReverseUInt16(undefined2 param_1)

{
  undefined2 local_res8 [16];
  
  local_res8[0] = param_1;
  TcglibReverseBytes((undefined1 *)local_res8,2);
  return local_res8[0];
}



===== TcglibReverseUInt32 @ 14000bddc =====

undefined4 TcglibReverseUInt32(undefined4 param_1)

{
  undefined4 local_res8 [8];
  
  local_res8[0] = param_1;
  TcglibReverseBytes((undefined1 *)local_res8,4);
  return local_res8[0];
}



===== TcglibRevertLockingSp @ 14000be04 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint TcglibRevertLockingSp(undefined8 *param_1,int *param_2,uint *param_3,char param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  int *piVar5;
  undefined8 uVar6;
  undefined1 auStack_78 [32];
  uint local_58 [10];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_78;
  local_58[8] = 0;
  local_58[0] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  local_58[3] = 0;
  local_58[4] = 0;
  local_58[5] = 0;
  local_58[6] = 0;
  local_58[7] = 0;
  if (*(int *)(param_1 + 4) != 0x200) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_127317a3aac038578d69cb8ccf054e38_Traceguids,*(int *)(param_1 + 4));
    }
    return 0xc00000bb;
  }
  piVar5 = param_2;
  uVar2 = TcglibpCheckContext((longlong)param_1,param_2);
  if (uVar2 != 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar2;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return uVar2;
    }
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_127317a3aac038578d69cb8ccf054e38_Traceguids,uVar2);
    return uVar2;
  }
  iVar3 = 0;
  LOCK();
  iVar1 = piVar5[7];
  if (iVar1 == 0) {
    piVar5[7] = 1;
  }
  else {
    iVar3 = iVar1;
  }
  UNLOCK();
  if (iVar3 == 1) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
              &WPP_127317a3aac038578d69cb8ccf054e38_Traceguids);
    }
    return 0x80000011;
  }
  if (param_3 == (uint *)0x0) {
    uVar2 = TcglibpGetMsid(param_1,(longlong)piVar5,local_58);
    param_3 = local_58;
    if (-1 < (int)uVar2) goto LAB_14000bf2d;
  }
  else {
LAB_14000bf2d:
    if ((param_4 == '\0') || (uVar6 = 0x90001ff01, param_3 == local_58)) {
      uVar6 = 0x900000006;
    }
    uVar4 = TcglibpAuthenticateSession(param_1,(longlong)param_2,uVar6,param_3);
    uVar2 = (uint)uVar4;
    if ((-1 < (int)uVar2) &&
       (uVar2 = TcglibpRevertLockingSp(param_1,(longlong)param_2), -1 < (int)uVar2))
    goto LAB_14000bf85;
  }
  uVar2 = TcglibpCheckError(param_1,param_2,uVar2);
LAB_14000bf85:
  LOCK();
  param_2[7] = 0;
  UNLOCK();
  return uVar2;
}



===== TcglibSecureDevice @ 14000bfac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint TcglibSecureDevice(undefined8 *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  undefined1 auStackY_98 [32];
  undefined8 local_68;
  undefined4 local_60;
  uint local_58 [10];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_98;
  local_68 = 0;
  local_60 = 0;
  local_58[8] = 0;
  local_58[0] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  local_58[3] = 0;
  local_58[4] = 0;
  local_58[5] = 0;
  local_58[6] = 0;
  local_58[7] = 0;
  uVar1 = TcglibpSetAuthorityPin(param_1,0x900000006,param_2,local_58,(longlong)&local_68,'\x01');
  if (-1 < (int)uVar1) {
    uVar1 = TcglibpSetAuthorityPin(param_1,0x900010001,param_3,local_58,0,'\0');
    if ((int)uVar1 < 0) {
      uVar2 = TcglibpSetAuthorityPin(param_1,0x900000006,local_58,param_2,(longlong)&local_68,'\0');
      if ((((int)uVar2 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                 &WPP_127317a3aac038578d69cb8ccf054e38_Traceguids,uVar2);
      }
    }
  }
  return uVar1;
}



===== TcglibSetBandLocation @ 14000c0c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint TcglibSetBandLocation
               (undefined8 *param_1,int *param_2,uint param_3,uint *param_4,longlong param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  int *piVar5;
  uint *puVar6;
  undefined1 auStack_68 [32];
  uint local_48 [2];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_68;
  local_48[0] = 0;
  local_48[1] = 0;
  if (((*(uint *)(param_1 + 6) < param_3) || (param_5 == 0)) ||
     ((param_3 == 0 && ((*(longlong *)(param_5 + 8) != 0 || (*(longlong *)(param_5 + 0x10) != 0)))))
     ) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
              &WPP_127317a3aac038578d69cb8ccf054e38_Traceguids);
    }
    return 0xc000000d;
  }
  piVar5 = param_2;
  uVar2 = TcglibpCheckContext((longlong)param_1,param_2);
  if (uVar2 != 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar2;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return uVar2;
    }
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
             &WPP_127317a3aac038578d69cb8ccf054e38_Traceguids,uVar2);
    return uVar2;
  }
  iVar3 = 0;
  LOCK();
  iVar1 = piVar5[7];
  if (iVar1 == 0) {
    piVar5[7] = 1;
  }
  else {
    iVar3 = iVar1;
  }
  UNLOCK();
  if (iVar3 == 1) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
              &WPP_127317a3aac038578d69cb8ccf054e38_Traceguids);
    }
    return 0x80000011;
  }
  puVar6 = local_48;
  if (param_4 != (uint *)0x0) {
    puVar6 = param_4;
  }
  uVar4 = TcglibpAuthenticateSession
                    (param_1,(longlong)piVar5,(ulonglong)param_3 + 0x900030001,puVar6);
  uVar2 = (uint)uVar4;
  if (((int)uVar2 < 0) ||
     (uVar2 = TcglibpSetBandLocation(param_1,(longlong)param_2,param_3,param_5), (int)uVar2 < 0)) {
    uVar2 = TcglibpCheckError(param_1,param_2,uVar2);
  }
  LOCK();
  param_2[7] = 0;
  UNLOCK();
  return uVar2;
}



===== TcglibSetBandMetadata @ 14000c260 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint TcglibSetBandMetadata
               (undefined8 *param_1,int *param_2,uint param_3,uint param_4,uint param_5,
               longlong param_6,uint *param_7)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  int *piVar5;
  uint *puVar6;
  undefined1 auStackY_78 [32];
  uint local_48 [2];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_78;
  local_48[0] = 0;
  local_48[1] = 0;
  piVar5 = param_2;
  uVar2 = TcglibpCheckContext((longlong)param_1,param_2);
  if ((int)uVar2 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
               &WPP_127317a3aac038578d69cb8ccf054e38_Traceguids,uVar2);
    }
  }
  else {
    iVar3 = 0;
    LOCK();
    iVar1 = piVar5[7];
    if (iVar1 == 0) {
      piVar5[7] = 1;
    }
    else {
      iVar3 = iVar1;
    }
    UNLOCK();
    if (iVar3 == 1) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
                &WPP_127317a3aac038578d69cb8ccf054e38_Traceguids);
      }
      uVar2 = 0x80000011;
    }
    else {
      puVar6 = local_48;
      if (param_7 != (uint *)0x0) {
        puVar6 = param_7;
      }
      uVar4 = TcglibpAuthenticateSession
                        (param_1,(longlong)piVar5,(ulonglong)param_3 + 0x900030001,puVar6);
      uVar2 = (uint)uVar4;
      if (-1 < (int)uVar2) {
        uVar2 = TcglibpSetBandMetadata(param_1,(longlong)param_2,param_3,param_4,param_5,param_6);
        if ((int)uVar2 < 0) {
          uVar2 = TcglibpCheckError(param_1,param_2,uVar2);
        }
      }
      LOCK();
      param_2[7] = 0;
      UNLOCK();
    }
  }
  return uVar2;
}



===== TcglibSetBandPin @ 14000c3b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint TcglibSetBandPin(undefined8 *param_1,int *param_2,uint param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  uint *puVar5;
  int *piVar6;
  ulonglong uVar7;
  undefined1 auStackY_88 [32];
  uint local_48 [2];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48[0] = 0;
  local_48[1] = 0;
  uVar7 = (ulonglong)param_3;
  piVar6 = param_2;
  uVar2 = TcglibpCheckContext((longlong)param_1,param_2);
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar2;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return uVar2;
    }
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
             &WPP_127317a3aac038578d69cb8ccf054e38_Traceguids,uVar2);
    return uVar2;
  }
  iVar3 = 0;
  LOCK();
  iVar1 = piVar6[7];
  if (iVar1 == 0) {
    piVar6[7] = 1;
  }
  else {
    iVar3 = iVar1;
  }
  UNLOCK();
  if (iVar3 == 1) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
              &WPP_127317a3aac038578d69cb8ccf054e38_Traceguids);
    }
    return 0x80000011;
  }
  puVar5 = local_48;
  if (param_4 != (uint *)0x0) {
    puVar5 = param_4;
  }
  uVar4 = TcglibpAuthenticateSession(param_1,(longlong)piVar6,uVar7 + 0x900030001,puVar5);
  uVar2 = (uint)uVar4;
  if (-1 < (int)uVar2) {
    puVar5 = local_48;
    if (param_5 != (uint *)0x0) {
      puVar5 = param_5;
    }
    if (*puVar5 < 0x21) {
      uVar2 = TcglibpSetTableColumnData
                        (param_1,(longlong)param_2,uVar7 + 0xb00030001,3,puVar5 + 1,*puVar5,0xf);
      if (-1 < (int)uVar2) goto LAB_14000c507;
    }
    else {
      uVar2 = 0xc000000d;
    }
  }
  uVar2 = TcglibpCheckError(param_1,param_2,uVar2);
LAB_14000c507:
  LOCK();
  param_2[7] = 0;
  UNLOCK();
  return uVar2;
}



===== TcglibSetBandSecurity @ 14000c530 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint TcglibSetBandSecurity
               (undefined8 *param_1,int *param_2,uint param_3,uint *param_4,longlong param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  int *piVar6;
  uint *puVar7;
  int iVar8;
  undefined1 auStack_68 [32];
  uint local_48 [2];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_68;
  local_48[0] = 0;
  local_48[1] = 0;
  if ((((*(uint *)(param_1 + 6) < param_3) || (param_5 == 0)) ||
      (iVar8 = 1, 2 < *(int *)(param_5 + 4) - 1U)) || (2 < *(int *)(param_5 + 8) - 1U)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
              &WPP_127317a3aac038578d69cb8ccf054e38_Traceguids);
    }
    return 0xc000000d;
  }
  puVar5 = param_1;
  piVar6 = param_2;
  uVar2 = TcglibpCheckContext((longlong)param_1,param_2);
  if (uVar2 != 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar2;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return uVar2;
    }
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
             &WPP_127317a3aac038578d69cb8ccf054e38_Traceguids,uVar2);
    return uVar2;
  }
  iVar3 = 0;
  LOCK();
  iVar1 = piVar6[7];
  if (iVar1 == 0) {
    piVar6[7] = iVar8;
  }
  else {
    iVar3 = iVar1;
  }
  UNLOCK();
  if (iVar3 == iVar8) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
              &WPP_127317a3aac038578d69cb8ccf054e38_Traceguids);
    }
    return 0x80000011;
  }
  puVar7 = local_48;
  if (param_4 != (uint *)0x0) {
    puVar7 = param_4;
  }
  uVar4 = TcglibpAuthenticateSession
                    (puVar5,(longlong)piVar6,(ulonglong)param_3 + 0x900030001,puVar7);
  uVar2 = (uint)uVar4;
  if (((int)uVar2 < 0) ||
     (uVar2 = TcglibpSetBandSecurity(param_1,(longlong)param_2,param_3,param_5), (int)uVar2 < 0)) {
    uVar2 = TcglibpCheckError(param_1,param_2,uVar2);
  }
  LOCK();
  param_2[7] = 0;
  UNLOCK();
  return uVar2;
}



===== TcglibSetSidPin @ 14000c6d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint TcglibSetSidPin(undefined8 *param_1,int *param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  int *piVar4;
  undefined1 auStackY_98 [32];
  uint local_58 [10];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58[8] = 0;
  local_58[0] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  local_58[3] = 0;
  local_58[4] = 0;
  local_58[5] = 0;
  local_58[6] = 0;
  local_58[7] = 0;
  if (param_4 == (uint *)0x0) {
    return 0xc000000d;
  }
  piVar4 = param_2;
  uVar1 = TcglibpCheckContext((longlong)param_1,param_2);
  if (uVar1 != 0) {
    return uVar1;
  }
  LOCK();
  iVar2 = piVar4[7];
  if (iVar2 == 0) {
    piVar4[7] = 1;
    iVar2 = 0;
  }
  UNLOCK();
  if (iVar2 == 1) {
    return 0x80000011;
  }
  if (param_3 == (uint *)0x0) {
    uVar1 = TcglibpGetMsid(param_1,(longlong)piVar4,local_58);
    param_3 = local_58;
    if (-1 < (int)uVar1) goto LAB_14000c757;
  }
  else {
LAB_14000c757:
    uVar3 = TcglibpAuthenticateSession(param_1,(longlong)param_2,0x900000006,param_3);
    uVar1 = (uint)uVar3;
    if (-1 < (int)uVar1) {
      if (*param_4 < 0x21) {
        uVar1 = TcglibpSetTableColumnData
                          (param_1,(longlong)param_2,0xb00000001,3,param_4 + 1,*param_4,0xf);
        if (-1 < (int)uVar1) goto LAB_14000c7c4;
      }
      else {
        uVar1 = 0xc000000d;
      }
    }
  }
  uVar1 = TcglibpCheckError(param_1,param_2,uVar1);
LAB_14000c7c4:
  LOCK();
  param_2[7] = 0;
  UNLOCK();
  return uVar1;
}



===== TcglibStackReset @ 14000c7e8 =====

uint TcglibStackReset(undefined8 *param_1,longlong param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined2 *puVar3;
  longlong lVar4;
  undefined2 uVar5;
  short sVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  uint local_res8 [4];
  longlong local_res18;
  longlong local_res20;
  undefined2 *local_48;
  longlong local_40;
  
  uVar1 = *param_1;
  local_48 = (undefined2 *)0x0;
  local_40 = 0;
  local_res8[0] = 0;
  iVar10 = 4;
  local_res18 = 0;
  local_res20 = 0;
  TcglibpReleaseRequestResources(uVar1,(longlong *)(param_2 + 0x28),(longlong *)(param_2 + 0x30));
  uVar7 = TcglibEalReset(uVar1);
  if (uVar7 == 0xc00000bb) {
    sVar6 = *(short *)(param_2 + 0x18);
    if (sVar6 == 0) {
      sVar6 = *(short *)((longlong)param_1 + 0x1c);
      *(short *)(param_2 + 0x18) = sVar6;
    }
    uVar7 = TcglibpAllocateRequestResources(*param_1,'\x02',sVar6,0x200,&local_res18,&local_res20);
    lVar2 = local_res20;
    if (-1 < (int)uVar7) {
      TcglibEalGetCommandPayload(uVar1,local_res18,(longlong *)&local_48,local_res8);
      if (local_res8[0] < 8) {
        uVar7 = 0xc0000023;
        lVar2 = local_res20;
      }
      else {
        uVar5 = TcglibReverseUInt16(*(undefined2 *)(param_2 + 0x18));
        puVar3 = local_48;
        *local_48 = uVar5;
        uVar8 = TcglibReverseUInt32(2);
        *(undefined4 *)(puVar3 + 2) = uVar8;
        uVar7 = TcglibpExecuteCommand(uVar1,local_res18,local_res8[0],'\0');
        lVar2 = local_res20;
      }
    }
    do {
      if ((int)uVar7 < 0) {
LAB_14000c960:
        if (uVar7 != 0x103) {
          if ((int)uVar7 < 0) goto LAB_14000c9a0;
          break;
        }
      }
      else {
        TcglibEalLogCommand(uVar1,"ResetStack",0,0,0,0);
        uVar7 = TcglibEalExecuteCommandSync(uVar1,lVar2,0);
        if ((int)uVar7 < 0) goto LAB_14000c960;
        TcglibEalGetCommandPayload(uVar1,lVar2,&local_40,local_res8);
        lVar4 = local_40;
        if ((local_res8[0] < 0x10) ||
           (iVar9 = TcglibReverseUInt32(*(undefined4 *)(local_40 + 4)), iVar9 != 2)) {
LAB_14000c991:
          uVar7 = 0xc0000185;
          goto LAB_14000c9a0;
        }
        sVar6 = TcglibReverseUInt16(*(undefined2 *)(lVar4 + 10));
        if (sVar6 == 4) {
          iVar9 = TcglibReverseUInt32(*(undefined4 *)(lVar4 + 0xc));
          uVar7 = -(uint)(iVar9 != 0) & 0xc0000185;
          goto LAB_14000c960;
        }
        if (sVar6 != 0) goto LAB_14000c991;
        uVar7 = 0x103;
        TcglibEalReuseCommand(uVar1,lVar2);
      }
      bVar11 = iVar10 != 0;
      iVar10 = iVar10 + -1;
    } while (bVar11);
    LOCK();
    *(undefined4 *)(param_1 + 1) = 0;
    UNLOCK();
LAB_14000c9a0:
    TcglibpReleaseRequestResources(uVar1,&local_res18,&local_res20);
  }
  return uVar7;
}



===== TcglibStartTransaction @ 14000c9c8 =====

uint TcglibStartTransaction(undefined8 *param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  bool bVar6;
  
  puVar5 = param_1;
  uVar2 = TcglibpCheckContext((longlong)param_1,param_2);
  if (-1 < (int)uVar2) {
    iVar3 = 0;
    LOCK();
    iVar1 = param_2[7];
    if (iVar1 == 0) {
      param_2[7] = 1;
    }
    else {
      iVar3 = iVar1;
    }
    UNLOCK();
    if (iVar3 == 1) {
      uVar2 = 0x80000011;
    }
    else {
      LOCK();
      bVar6 = param_2[8] == 0;
      if (bVar6) {
        param_2[8] = 1;
      }
      UNLOCK();
      if (bVar6) {
        uVar4 = TcglibpTransaction(puVar5,(longlong)param_2,'\x01','\0');
        uVar2 = (uint)uVar4;
        if ((int)uVar2 < 0) {
          uVar2 = TcglibpCheckError(param_1,param_2,uVar2);
          LOCK();
          param_2[8] = 0;
          UNLOCK();
        }
      }
      else {
        uVar2 = 0xc00000e5;
      }
      LOCK();
      param_2[7] = 0;
      UNLOCK();
    }
  }
  return uVar2;
}



===== TcglibStopTransaction @ 14000ca58 =====

ulonglong TcglibStopTransaction(undefined8 *param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  int *piVar5;
  bool bVar6;
  
  uVar4 = 0xc0000203;
  if (param_3 != -0x3ffffdfd) {
    piVar5 = param_2;
    iVar1 = TcglibpCheckContext((longlong)param_1,param_2);
    uVar4 = CONCAT44(extraout_var,iVar1);
    if (-1 < iVar1) {
      iVar2 = 0;
      LOCK();
      iVar1 = piVar5[7];
      if (iVar1 == 0) {
        piVar5[7] = 1;
      }
      else {
        iVar2 = iVar1;
      }
      UNLOCK();
      if (iVar2 == 1) {
        uVar4 = 0x80000011;
      }
      else {
        LOCK();
        bVar6 = piVar5[8] == 1;
        if (bVar6) {
          piVar5[8] = 0;
        }
        UNLOCK();
        if (bVar6) {
          uVar4 = TcglibpTransaction(param_1,(longlong)piVar5,'\0',(byte)((uint)param_3 >> 0x1f));
          if ((int)(uint)uVar4 < 0) {
            uVar3 = TcglibpCheckError(param_1,param_2,(uint)uVar4);
            uVar4 = CONCAT44(extraout_var_00,uVar3);
          }
        }
        else {
          uVar4 = 0xc00000e5;
        }
        LOCK();
        param_2[7] = 0;
        UNLOCK();
      }
    }
  }
  return uVar4;
}



===== TcglibpCheckContext @ 14000cae8 =====

undefined4 TcglibpCheckContext(longlong param_1,int *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xc0000203;
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    uVar1 = 0xc000000d;
  }
  else if ((((*(longlong *)(param_2 + 10) != 0) && (*(longlong *)(param_2 + 0xc) != 0)) &&
           (*(int *)(param_1 + 8) != 0)) &&
          ((param_2 == *(int **)(param_1 + 0x10) && (*param_2 - 1U < 2)))) {
    uVar1 = 0;
  }
  return uVar1;
}



===== TcglibpCheckError @ 14000cb34 =====

uint TcglibpCheckError(undefined8 *param_1,undefined4 *param_2,uint param_3)

{
  if (((param_3 == 0xc00000b5) || (param_3 == 0xc00000ce)) || (param_3 + 0x3ffffe7c < 3)) {
    param_3 = TcglibStackReset(param_1,(longlong)param_2);
    if (-1 < (int)param_3) {
      param_3 = 0xc0000203;
      LOCK();
      *param_2 = 4;
      UNLOCK();
    }
  }
  else if (param_3 == 0xc0000203) {
    LOCK();
    *param_2 = 4;
    UNLOCK();
  }
  return param_3;
}



===== GenGetBandMetadataParams @ 14000cba0 =====

ulonglong GenGetBandMetadataParams
                    (undefined8 param_1,undefined8 param_2,longlong *param_3,ulonglong *param_4)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  
  if (*(uint *)((longlong)param_3 + 0xc) + 1 <= *(uint *)(param_3 + 1)) {
    *(undefined1 *)((ulonglong)*(uint *)((longlong)param_3 + 0xc) + *param_3) = 0xf0;
    *(int *)((longlong)param_3 + 0xc) = *(int *)((longlong)param_3 + 0xc) + 1;
    uVar2 = GenNamedValueInt(param_3,1,*param_4);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    uVar3 = ((int)param_3[1] - *(int *)((longlong)param_3 + 0xc)) - 0xd;
    uVar1 = (uint)param_4[3];
    if (uVar3 <= (uint)param_4[3]) {
      uVar1 = uVar3;
    }
    *(uint *)(param_4 + 3) = uVar1;
    uVar2 = GenNamedValueInt(param_3,2,(*param_4 - 1) + (ulonglong)uVar1);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    if (*(uint *)((longlong)param_3 + 0xc) + 1 <= *(uint *)(param_3 + 1)) {
      *(undefined1 *)((ulonglong)*(uint *)((longlong)param_3 + 0xc) + *param_3) = 0xf1;
      *(int *)((longlong)param_3 + 0xc) = *(int *)((longlong)param_3 + 0xc) + 1;
      return 0;
    }
  }
  return 0xc0000023;
}



===== GenSetBandMetadataParams @ 14000cc40 =====

void GenSetBandMetadataParams
               (undefined8 param_1,undefined8 param_2,longlong *param_3,ulonglong *param_4)

{
  ulonglong uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = GenNamedValueInt(param_3,0,*param_4);
  if (-1 < (int)uVar1) {
    uVar2 = ((int)param_3[1] - *(int *)((longlong)param_3 + 0xc)) - 0xe;
    uVar3 = (uint)param_4[3];
    if (uVar2 <= (uint)param_4[3]) {
      uVar3 = uVar2;
    }
    *(uint *)(param_4 + 3) = uVar3;
    GenNamedValueBytes(param_3,1,(void *)param_4[2],uVar3);
  }
  return;
}



===== ParseBandMetadata @ 14000cca0 =====

undefined8
ParseBandMetadata(undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4)

{
  uint *puVar1;
  uint uVar2;
  longlong lVar3;
  undefined1 uVar4;
  undefined *puVar5;
  undefined8 *_Src;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined1 uVar8;
  undefined *puVar9;
  
  puVar1 = (uint *)(param_3 + 0xc);
  if ((*(int *)(param_3 + 8) == 5) && (*puVar1 == 1)) {
    lVar3 = *(longlong *)(param_3 + 0x10);
    puVar5 = WPP_GLOBAL_Control;
    if (*(int *)(lVar3 + 8) - 0xfU < 3) {
      uVar2 = *(uint *)(param_4 + 0x18);
      if (*(uint *)(lVar3 + 0xc) <= uVar2) {
        memset(*(void **)(param_4 + 0x10),0,(ulonglong)uVar2);
        _Src = (undefined8 *)0x0;
        if ((*(int *)(lVar3 + 8) - 7U < 0xb) &&
           (_Src = (undefined8 *)(lVar3 + 0x10), 8 < *(uint *)(lVar3 + 0xc))) {
          _Src = (undefined8 *)*_Src;
        }
        memmove(*(void **)(param_4 + 0x10),_Src,(ulonglong)*(uint *)(lVar3 + 0xc));
        *(undefined4 *)(param_4 + 0x18) = *(undefined4 *)(lVar3 + 0xc);
        return 0;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        puVar5 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
        WPP_SF_dd(puVar5,0xe,&WPP_049e0c7a54583f65b6c0044bb56b30ca_Traceguids,*(uint *)(lVar3 + 0xc)
                  ,(char)uVar2);
      }
      uVar4 = (undefined1)*(undefined4 *)(param_4 + 0x18);
      uVar6 = 0xc0000023;
      uVar7 = 3;
      uVar8 = (undefined1)*(undefined4 *)(lVar3 + 0xc);
      goto LAB_14000ce20;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      puVar5 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      WPP_SF_D(puVar5,0xd,&WPP_049e0c7a54583f65b6c0044bb56b30ca_Traceguids,*(int *)(lVar3 + 8));
    }
    uVar7 = 2;
    uVar8 = (undefined1)*(undefined4 *)(lVar3 + 8);
    puVar9 = (undefined *)0x0;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                &WPP_049e0c7a54583f65b6c0044bb56b30ca_Traceguids,*(int *)(param_3 + 8),(char)*puVar1
               );
    }
    puVar5 = (undefined *)(ulonglong)*puVar1;
    uVar7 = 1;
    uVar8 = (undefined1)*(undefined4 *)(param_3 + 8);
    puVar9 = puVar5;
  }
  uVar4 = SUB81(puVar9,0);
  uVar6 = 0xc0000185;
LAB_14000ce20:
  TcglibEalLogError(puVar5,"ErrInvalidBandMetadata",uVar7,uVar8,uVar4,0);
  return uVar6;
}



===== ParseBandTableEntry @ 14000ce50 =====

int ParseBandTableEntry(undefined8 param_1,undefined8 param_2,longlong param_3,longlong *param_4)

{
  uint *puVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong lVar6;
  bool bVar7;
  int iVar8;
  undefined4 uVar9;
  undefined8 *_Src;
  undefined *puVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  undefined8 uVar14;
  undefined1 uVar15;
  undefined4 uVar16;
  char local_res18;
  undefined *puVar17;
  char local_58;
  char local_57;
  char local_56;
  uint local_54;
  undefined8 *local_48;
  undefined8 local_40;
  
  iVar12 = 0;
  puVar1 = (uint *)(param_3 + 0xc);
  iVar11 = 1;
  if ((*(int *)(param_3 + 8) == 5) && (*puVar1 == 1)) {
    lVar3 = *(longlong *)(param_3 + 0x10);
    if (*(int *)(lVar3 + 8) == 5) {
      lVar4 = *param_4;
      uVar2 = *(uint *)(lVar3 + 0xc);
      uVar13 = 0;
      local_57 = '\0';
      local_56 = '\0';
      local_58 = '\0';
      *(undefined4 *)(lVar4 + 0x40) = 0x38;
      uVar16 = 3;
      *(undefined4 *)(lVar4 + 8) = 0x38;
      local_48 = *(undefined8 **)(lVar3 + 0x10);
      local_res18 = '\0';
      bVar7 = false;
      local_54 = 0;
      do {
        if (uVar2 <= local_54) break;
        if (((*(int *)(local_48 + 1) == 6) && (*(int *)((longlong)local_48 + 0xc) == 2)) &&
           (plVar5 = (longlong *)local_48[2], plVar5 != (longlong *)0x0)) {
          puVar1 = (uint *)((longlong)plVar5 + 0xc);
          lVar3 = *plVar5;
          if (((int)plVar5[1] - 7U < 8) && (*puVar1 < 5)) {
            lVar6 = plVar5[2];
            if (lVar6 == 2) {
              if ((*(int *)(lVar3 + 8) - 0xfU < 3) && (*(uint *)(lVar3 + 0xc) < 0x21)) {
                lVar6 = plVar5[2];
                *(undefined8 *)(lVar4 + 0x20) = 0;
                *(undefined8 *)(lVar4 + 0x28) = 0;
                _Src = (undefined8 *)0x0;
                uVar13 = uVar13 | 1 << ((byte)lVar6 & 0x1f);
                *(undefined8 *)(lVar4 + 0x30) = 0;
                *(undefined8 *)(lVar4 + 0x38) = 0;
                if ((*(int *)(lVar3 + 8) - 7U < 0xb) &&
                   (_Src = (undefined8 *)(lVar3 + 0x10), 8 < *(uint *)(lVar3 + 0xc))) {
                  _Src = (undefined8 *)*_Src;
                }
                memmove((void *)(lVar4 + 0x20),_Src,(ulonglong)*(uint *)(lVar3 + 0xc));
              }
            }
            else if (lVar6 == 3) {
              if ((*(int *)(lVar3 + 8) - 7U < 8) && (*(uint *)(lVar3 + 0xc) < 9)) {
                uVar13 = uVar13 | 1 << ((byte)plVar5[2] & 0x1f);
                *(undefined8 *)(lVar4 + 0x10) = *(undefined8 *)(lVar3 + 0x10);
              }
            }
            else if (lVar6 == 4) {
              if ((*(int *)(lVar3 + 8) - 7U < 8) && (*(uint *)(lVar3 + 0xc) < 9)) {
                uVar13 = uVar13 | 1 << ((byte)plVar5[2] & 0x1f);
                *(undefined8 *)(lVar4 + 0x18) = *(undefined8 *)(lVar3 + 0x10);
              }
            }
            else if (lVar6 == 5) {
              if ((*(int *)(lVar3 + 8) - 7U < 8) && (*(uint *)(lVar3 + 0xc) < 2)) {
                local_57 = *(char *)(lVar3 + 0x10);
                uVar13 = uVar13 | 1 << ((byte)plVar5[2] & 0x1f);
              }
            }
            else if (lVar6 == 6) {
              if ((*(int *)(lVar3 + 8) - 7U < 8) && (*(uint *)(lVar3 + 0xc) < 2)) {
                local_56 = *(char *)(lVar3 + 0x10);
                uVar13 = uVar13 | 1 << ((byte)plVar5[2] & 0x1f);
              }
            }
            else if (lVar6 == 7) {
              if ((*(int *)(lVar3 + 8) - 7U < 8) && (*(uint *)(lVar3 + 0xc) < 2)) {
                local_58 = *(char *)(lVar3 + 0x10);
                uVar13 = uVar13 | 1 << ((byte)plVar5[2] & 0x1f);
              }
            }
            else if (lVar6 == 8) {
              if ((*(int *)(lVar3 + 8) - 7U < 8) && (*(uint *)(lVar3 + 0xc) < 2)) {
                local_res18 = *(char *)(lVar3 + 0x10);
                uVar13 = uVar13 | 1 << ((byte)plVar5[2] & 0x1f);
              }
            }
            else if (lVar6 == 9) {
              if ((*(int *)(lVar3 + 8) == 5) && (*(int *)(lVar3 + 0xc) != 0)) {
                uVar13 = uVar13 | 1 << ((byte)plVar5[2] & 0x1f);
                bVar7 = true;
              }
            }
            else if (((lVar6 == 10) && (*(int *)(lVar3 + 8) - 0xfU < 3)) &&
                    (*(uint *)(lVar3 + 0xc) < 9)) {
              uVar13 = uVar13 | 1 << ((byte)plVar5[2] & 0x1f);
              local_40 = *(undefined8 *)(lVar3 + 0x10);
              TcglibReverseBytes((undefined1 *)&local_40,8);
              *(undefined8 *)param_4[1] = local_40;
            }
          }
          else {
            puVar10 = WPP_GLOBAL_Control;
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              puVar10 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
              WPP_SF_dd(puVar10,0x12,&WPP_049e0c7a54583f65b6c0044bb56b30ca_Traceguids,(int)plVar5[1]
                        ,(char)*puVar1);
            }
            iVar12 = -0x3ffffe7b;
            TcglibEalLogError(puVar10,"ErrInvalidBandTableEntry",4,(char)plVar5[1],(char)*puVar1,0);
          }
        }
        else {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                      &WPP_049e0c7a54583f65b6c0044bb56b30ca_Traceguids,*(int *)(local_48 + 1),
                      (char)*(undefined4 *)((longlong)local_48 + 0xc));
          }
          iVar12 = -0x3ffffe7b;
          TcglibEalLogError(local_48,"ErrInvalidBandTableEntry",3,
                            (char)*(undefined4 *)(local_48 + 1),
                            (char)*(undefined4 *)((longlong)local_48 + 0xc),0);
        }
        local_54 = local_54 + 1;
        local_48 = (undefined8 *)*local_48;
      } while (-1 < iVar12);
      if ((uVar13 & 0x7f8) == 0x7f8) {
        if (!bVar7) {
          if ((local_57 == '\0') || (uVar9 = 3, local_58 == '\0')) {
            uVar9 = 1;
          }
          *(undefined4 *)(lVar4 + 0x44) = uVar9;
          if ((local_56 == '\0') || (local_res18 == '\0')) {
            uVar16 = 1;
          }
          *(undefined4 *)(lVar4 + 0x48) = uVar16;
          return iVar12;
        }
        if (local_57 == '\0') {
          iVar8 = 1;
        }
        else {
          iVar8 = (local_58 != '\0') + 2;
        }
        *(int *)(lVar4 + 0x44) = iVar8;
        if (local_56 != '\0') {
          iVar11 = (local_res18 != '\0') + 2;
        }
        *(int *)(lVar4 + 0x48) = iVar11;
        return iVar12;
      }
      puVar10 = WPP_GLOBAL_Control;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        puVar10 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
        WPP_SF_D(puVar10,0x13,&WPP_049e0c7a54583f65b6c0044bb56b30ca_Traceguids,uVar13);
      }
      uVar14 = 5;
      uVar15 = (undefined1)uVar13;
      puVar17 = (undefined *)0x0;
    }
    else {
      puVar10 = WPP_GLOBAL_Control;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        puVar10 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
        WPP_SF_dd(puVar10,0x10,&WPP_049e0c7a54583f65b6c0044bb56b30ca_Traceguids,*(int *)(lVar3 + 8),
                  (char)*(undefined4 *)(lVar3 + 0xc));
      }
      uVar14 = 2;
      uVar15 = (undefined1)*(undefined4 *)(lVar3 + 8);
      puVar17 = (undefined *)(ulonglong)*(uint *)(lVar3 + 0xc);
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                &WPP_049e0c7a54583f65b6c0044bb56b30ca_Traceguids,*(int *)(param_3 + 8),(char)*puVar1
               );
    }
    puVar10 = (undefined *)(ulonglong)*puVar1;
    uVar14 = 1;
    uVar15 = (undefined1)*(undefined4 *)(param_3 + 8);
    puVar17 = puVar10;
  }
  TcglibEalLogError(puVar10,"ErrInvalidBandTableEntry",uVar14,uVar15,(char)puVar17,0);
  return -0x3ffffe7b;
}



===== TcglibpEraseBand @ 14000d49c =====

void TcglibpEraseBand(undefined8 *param_1,longlong param_2,uint param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  
  uVar1 = (ulonglong)param_3;
  lVar2 = 0x80200000001;
  if (param_3 == 0) {
    lVar3 = 0x80200000001;
    uVar1 = 0;
  }
  else {
    lVar3 = uVar1 + 0x80200030000;
  }
  TcglibEalLogCommand(*param_1,"EraseBand",lVar3,0x600000803,uVar1,0);
  if (param_3 != 0) {
    lVar2 = uVar1 + 0x80200030000;
  }
  TcglibpCallMethod(param_1,param_2,lVar2,0x600000803,(undefined *)0x0,0,0,0,(undefined *)0x0,0);
  return;
}



===== TcglibpGetBandMetadata @ 14000d574 =====

void TcglibpGetBandMetadata
               (undefined8 *param_1,longlong param_2,uint param_3,uint param_4,uint param_5,
               longlong param_6)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong local_38 [3];
  uint local_20;
  undefined4 local_1c;
  
  local_38[1] = 0;
  local_1c = 0;
  while( true ) {
    local_38[0] = (ulonglong)param_4;
    if (param_5 == 0) {
      return;
    }
    lVar2 = (ulonglong)param_3 + 0x1001 << 0x20;
    local_38[2] = param_6;
    local_20 = param_5;
    TcglibEalLogCommand(*param_1,"GetBandMetadata",lVar2,0x600000016,local_38[0],(ulonglong)param_5)
    ;
    uVar1 = TcglibpCallMethod(param_1,param_2,lVar2,0x600000016,GenGetBandMetadataParams,local_38,0,
                              0,ParseBandMetadata,local_38);
    if ((int)uVar1 < 0) break;
    param_6 = param_6 + (ulonglong)local_20;
    param_4 = param_4 + local_20;
    param_5 = param_5 - local_20;
  }
  return;
}



===== TcglibpGetBandTableEntries @ 14000d690 =====

int TcglibpGetBandTableEntries
              (undefined8 *param_1,longlong param_2,uint param_3,char param_4,longlong param_5,
              int *param_6)

{
  uint *puVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  uint uVar5;
  int iVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint *puVar9;
  ulonglong local_res8;
  longlong local_res10;
  int local_res18;
  char local_res20;
  uint *local_70;
  ulonglong *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 local_50;
  
  iVar6 = 0;
  local_res18 = *param_6;
  if (*(uint *)(param_1 + 6) < local_res18 + param_3) {
    local_res18 = *(uint *)(param_1 + 6) - param_3;
    *param_6 = local_res18;
  }
  uVar3 = local_res18 + param_3;
  local_res10 = param_2;
  local_res20 = param_4;
  uVar5 = param_3;
  if (uVar3 <= param_3) {
LAB_14000d8f6:
    *param_6 = local_res18;
    return iVar6;
  }
  do {
    uVar8 = (ulonglong)uVar5;
    local_50 = 9;
    local_60 = 2;
    local_5c = 10;
    puVar9 = (uint *)((ulonglong)(uVar5 - param_3) * 0x78 + param_5);
    local_68 = &local_res8;
    local_58 = 0;
    local_res8 = 0;
    local_70 = puVar9;
    memset(puVar9 + 1,0,0x74);
    *puVar9 = uVar5;
    if (uVar5 == 0) {
      lVar7 = 0x80200000001;
      uVar8 = 0;
    }
    else {
      lVar7 = uVar8 + 0x80200030000;
    }
    TcglibEalLogCommand(*param_1,"GetBandTableEntry",lVar7,0x600000016,uVar8,0);
    if (uVar5 == 0) {
      lVar7 = 0x80200000001;
    }
    else {
      lVar7 = uVar8 + 0x80200030000;
    }
    uVar4 = TcglibpCallMethod(param_1,param_2,lVar7,0x600000016,GenGetTableColumnParams,&local_60,0,
                              0,ParseBandTableEntry,&local_70);
    uVar2 = local_res8;
    puVar1 = puVar9 + 0x14;
    puVar9[0x13] = 0;
    *puVar1 = 0xffffffff;
    iVar6 = (int)uVar4;
    if (iVar6 < 0) goto LAB_14000d8f6;
    if (local_res20 != '\0') {
      *puVar1 = 0;
      iVar6 = TcglibpGetTableColumnData(param_1,local_res10,local_res8,4,puVar1,4,(undefined4 *)0x0)
      ;
      if (iVar6 < 0) {
LAB_14000d881:
        if (iVar6 < 0) goto LAB_14000d8f6;
      }
      else if ((uVar2 & 0xffffffff00000000) == 0x80500000000) {
        *puVar1 = *puVar1 | 0x10000;
      }
      else {
        if ((uVar2 & 0xffffffff00000000) != 0x80600000000) goto LAB_14000d881;
        *puVar1 = *puVar1 | 0x20000;
      }
      puVar9[0x13] = 2;
    }
    param_2 = local_res10;
    puVar1 = puVar9 + 0x16;
    puVar1[0] = 0;
    puVar1[1] = 0;
    puVar9[0x18] = 0;
    puVar9[0x19] = 0;
    puVar9[0x1a] = 0;
    puVar9[0x1b] = 0;
    puVar9[0x1c] = 0;
    puVar9[0x1d] = 0;
    iVar6 = TcglibpGetTableColumnData
                      (param_1,local_res10,uVar8 + 0x900030001,2,puVar1,0x20,(undefined4 *)0x0);
    if ((iVar6 < 0) || (uVar5 = uVar5 + 1, uVar3 <= uVar5)) goto LAB_14000d8f6;
  } while( true );
}



===== TcglibpSetBandLocation @ 14000d918 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TcglibpSetBandLocation(undefined8 *param_1,longlong param_2,uint param_3,longlong param_4)

{
  longlong lVar1;
  undefined1 auStack_d8 [32];
  uint local_b8 [2];
  undefined8 *local_b0;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined8 local_98;
  undefined4 local_90;
  undefined4 local_8c;
  longlong local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 local_78;
  undefined4 local_70;
  undefined4 local_6c;
  longlong local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_d8;
  local_a4 = 0;
  memset(&local_98,0,0x60);
  local_b0 = &local_98;
  local_b8[0] = 2;
  if (param_3 == 0) {
    local_b8[1] = 2;
    local_a8 = 1;
  }
  else {
    local_b8[1] = 4;
    local_a8 = 3;
  }
  local_98 = 2;
  local_8c = 8;
  local_88 = param_4 + 0x18;
  local_90 = 1;
  local_80 = 0x20;
  local_7c = 0x10;
  if (param_3 == 0) {
    lVar1 = 0x80200000001;
  }
  else {
    local_68 = param_4 + 8;
    local_70 = 1;
    local_50 = 1;
    local_48 = param_4 + 0x10;
    local_78 = 3;
    lVar1 = (ulonglong)param_3 + 0x80200030000;
    local_6c = 8;
    local_60 = 8;
    local_5c = 10;
    local_58 = 4;
    local_4c = 8;
    local_40 = 8;
    local_3c = 10;
  }
  TcglibpSetTableColumns(param_1,param_2,lVar1,local_b8);
  return;
}



===== TcglibpSetBandMetadata @ 14000da34 =====

void TcglibpSetBandMetadata
               (undefined8 *param_1,longlong param_2,uint param_3,uint param_4,uint param_5,
               longlong param_6)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong local_38 [3];
  uint local_20;
  undefined4 local_1c;
  
  local_38[1] = 0;
  local_1c = 0;
  while( true ) {
    local_38[0] = (ulonglong)param_4;
    if (param_5 == 0) {
      return;
    }
    lVar2 = (ulonglong)param_3 + 0x1001 << 0x20;
    local_38[2] = param_6;
    local_20 = param_5;
    TcglibEalLogCommand(*param_1,"SetBandMetadata",lVar2,0x600000017,local_38[0],(ulonglong)param_5)
    ;
    uVar1 = TcglibpCallMethod(param_1,param_2,lVar2,0x600000017,GenSetBandMetadataParams,local_38,0,
                              0,(undefined *)0x0,0);
    if ((int)uVar1 < 0) break;
    param_6 = param_6 + (ulonglong)local_20;
    param_4 = param_4 + local_20;
    param_5 = param_5 - local_20;
  }
  return;
}



===== TcglibpSetBandSecurity @ 14000db44 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TcglibpSetBandSecurity(undefined8 *param_1,longlong param_2,uint param_3,longlong param_4)

{
  int iVar1;
  longlong lVar2;
  undefined1 auStackY_138 [32];
  undefined1 local_f8;
  undefined1 local_f7;
  undefined1 local_f6;
  undefined1 local_f5;
  undefined4 local_f4;
  uint local_f0 [2];
  undefined8 *local_e8;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined8 local_d8;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined1 *local_c8;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined8 local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined1 *local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined8 local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined1 *local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined1 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_138;
  local_dc = 0;
  iVar1 = *(int *)(param_4 + 4);
  local_f8 = 0;
  local_f7 = 0;
  local_f6 = 0;
  local_f5 = 0;
  local_f4 = 0xf10300f0;
  if (iVar1 != 1) {
    if (iVar1 != 2) {
      if (iVar1 != 3) goto LAB_14000dbb2;
      local_f6 = 1;
    }
    local_f8 = 1;
  }
LAB_14000dbb2:
  iVar1 = *(int *)(param_4 + 8);
  if (iVar1 != 1) {
    if (iVar1 != 2) {
      if (iVar1 != 3) goto LAB_14000dbce;
      local_f5 = 1;
    }
    local_f7 = 1;
  }
LAB_14000dbce:
  local_d0 = 1;
  local_f0[0] = 5;
  local_e8 = &local_d8;
  local_c8 = &local_f8;
  local_a8 = &local_f7;
  local_e0 = 5;
  local_88 = &local_f6;
  local_68 = &local_f5;
  local_48 = &local_f4;
  local_d8 = 5;
  local_f0[1] = 9;
  local_cc = 8;
  local_c0 = 1;
  local_bc = 8;
  local_b8 = 6;
  local_b0 = 1;
  local_ac = 8;
  local_a0 = 1;
  local_9c = 8;
  local_98 = 7;
  local_90 = 1;
  local_8c = 8;
  local_80 = 1;
  local_7c = 8;
  local_78 = 8;
  local_70 = 1;
  local_6c = 8;
  local_60 = 1;
  local_5c = 8;
  local_58 = 9;
  local_50 = 1;
  local_4c = 8;
  local_40 = 4;
  local_3c = 1;
  if (param_3 == 0) {
    lVar2 = 0x80200000001;
  }
  else {
    lVar2 = (ulonglong)param_3 + 0x80200030000;
  }
  iVar1 = TcglibpSetTableColumns(param_1,param_2,lVar2,local_f0);
  if (-1 < iVar1) {
    TcglibpSetTableColumnData
              (param_1,param_2,(ulonglong)param_3 + 0x900030001,2,param_4 + 0x18,0x20,0xf);
  }
  return;
}



===== FindNamedToken @ 14000dd18 =====

undefined8 FindNamedToken(longlong *param_1,longlong param_2,longlong *param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  
  puVar4 = *(undefined8 **)(param_2 + 0x10);
  *param_3 = 0;
  do {
    if (puVar4 == (undefined8 *)0x0) {
      return 0;
    }
    if (((*(int *)(puVar4 + 1) != 6) || (*(int *)((longlong)puVar4 + 0xc) != 2)) ||
       (lVar1 = puVar4[2], lVar1 == 0)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                  &WPP_26031245b0af395f80dcd19d8421604d_Traceguids,*(int *)(puVar4 + 1),
                  (char)*(undefined4 *)((longlong)puVar4 + 0xc));
      }
      return 0xc0000185;
    }
    if (((*(int *)((longlong)param_1 + 0xc) - 7U < 8) && (*(uint *)(param_1 + 1) < 9)) &&
       ((*(int *)(lVar1 + 8) - 7U < 8 &&
        ((*(uint *)(lVar1 + 0xc) < 9 && (*param_1 == *(longlong *)(lVar1 + 0x10))))))) {
LAB_14000ddf8:
      *param_3 = lVar1;
    }
    else if ((*(int *)((longlong)param_1 + 0xc) - 0xfU < 3) && (*(int *)(lVar1 + 8) - 0xfU < 3)) {
      if (*(uint *)(param_1 + 1) == *(uint *)(lVar1 + 0xc)) {
        plVar5 = param_1;
        if (8 < *(uint *)(param_1 + 1)) {
          plVar5 = (longlong *)*param_1;
        }
        plVar3 = (longlong *)0x0;
        if ((*(int *)(lVar1 + 8) - 7U < 0xb) &&
           (plVar3 = (longlong *)(lVar1 + 0x10), 8 < *(uint *)(lVar1 + 0xc))) {
          plVar3 = (longlong *)*plVar3;
        }
        uVar2 = RtlCompareMemory(plVar5,plVar3);
        if (uVar2 == *(uint *)(lVar1 + 0xc)) goto LAB_14000ddf8;
      }
    }
    puVar4 = (undefined8 *)*puVar4;
    if (*param_3 != 0) {
      return 0;
    }
  } while( true );
}



===== GenGetTableColumnParams @ 14000de70 =====

ulonglong GenGetTableColumnParams
                    (undefined8 param_1,undefined8 param_2,longlong *param_3,uint *param_4)

{
  ulonglong uVar1;
  
  if (*(uint *)((longlong)param_3 + 0xc) + 1 <= *(uint *)(param_3 + 1)) {
    *(undefined1 *)((ulonglong)*(uint *)((longlong)param_3 + 0xc) + *param_3) = 0xf0;
    *(int *)((longlong)param_3 + 0xc) = *(int *)((longlong)param_3 + 0xc) + 1;
    if ((param_4[1] != 0) && (*param_4 <= param_4[1])) {
      uVar1 = GenNamedValueInt(param_3,3,(ulonglong)*param_4);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar1 = GenNamedValueInt(param_3,4,(ulonglong)param_4[1]);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
    }
    if (*(uint *)((longlong)param_3 + 0xc) + 1 <= *(uint *)(param_3 + 1)) {
      *(undefined1 *)((ulonglong)*(uint *)((longlong)param_3 + 0xc) + *param_3) = 0xf1;
      *(int *)((longlong)param_3 + 0xc) = *(int *)((longlong)param_3 + 0xc) + 1;
      return 0;
    }
  }
  return 0xc0000023;
}



===== GenSetTableColumnParams @ 14000df00 =====

ulonglong GenSetTableColumnParams
                    (undefined8 param_1,undefined8 param_2,longlong *param_3,longlong param_4)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  ulonglong *puVar5;
  uint uVar6;
  ulonglong *puVar7;
  uint uVar8;
  ulonglong local_28 [2];
  
  uVar3 = GenNamedValueListBegin(param_3,1);
  if (-1 < (int)uVar3) {
    for (uVar6 = 0; uVar6 < *(uint *)(param_4 + 0x10); uVar6 = uVar6 + 1) {
      puVar7 = (ulonglong *)((ulonglong)uVar6 * 0x20 + *(longlong *)(param_4 + 8));
      if (*(uint *)(param_3 + 1) < *(uint *)((longlong)param_3 + 0xc) + 1) {
        return 0xc0000023;
      }
      *(undefined1 *)((ulonglong)*(uint *)((longlong)param_3 + 0xc) + *param_3) = 0xf2;
      *(int *)((longlong)param_3 + 0xc) = *(int *)((longlong)param_3 + 0xc) + 1;
      if ((*(int *)((longlong)puVar7 + 0xc) - 7U < 8) && ((uint)puVar7[1] < 9)) {
        uVar3 = GenInteger(param_3,*puVar7);
        uVar2 = (uint)uVar3;
      }
      else {
        puVar5 = puVar7;
        if (8 < (uint)puVar7[1]) {
          puVar5 = (ulonglong *)*puVar7;
        }
        uVar4 = GenDataBytes(param_3,puVar5,(uint)puVar7[1]);
        uVar2 = (uint)uVar4;
      }
      if ((int)uVar2 < 0) {
        return (ulonglong)uVar2;
      }
      iVar1 = *(int *)((longlong)puVar7 + 0x1c);
      if ((iVar1 - 7U < 8) && ((uint)puVar7[3] < 9)) {
        local_28[0] = 0;
        memmove(local_28,(void *)puVar7[2],(ulonglong)(uint)puVar7[3]);
        uVar3 = GenInteger(param_3,local_28[0]);
        uVar2 = (uint)uVar3;
LAB_14000dff5:
        uVar3 = (ulonglong)uVar2;
LAB_14000e062:
        if ((int)uVar3 < 0) {
          return uVar3;
        }
      }
      else {
        if (iVar1 - 0xfU < 3) {
          uVar4 = GenDataBytes(param_3,(void *)puVar7[2],(uint)puVar7[3]);
          uVar2 = (uint)uVar4;
          goto LAB_14000dff5;
        }
        if (iVar1 == 1) {
          uVar2 = (uint)puVar7[3];
          uVar3 = 0;
          uVar8 = *(uint *)((longlong)param_3 + 0xc) + uVar2;
          if (*(uint *)(param_3 + 1) < uVar8) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                        &WPP_7125d21b90f93d8abdbf4e6e2db0cd73_Traceguids,*(uint *)(param_3 + 1),
                        (char)uVar8);
            }
            uVar3 = 0xc0000023;
          }
          else {
            memmove((void *)((ulonglong)*(uint *)((longlong)param_3 + 0xc) + *param_3),
                    (void *)puVar7[2],(ulonglong)uVar2);
            *(int *)((longlong)param_3 + 0xc) = *(int *)((longlong)param_3 + 0xc) + uVar2;
          }
          goto LAB_14000e062;
        }
      }
      if (*(uint *)(param_3 + 1) < *(uint *)((longlong)param_3 + 0xc) + 1) {
        return 0xc0000023;
      }
      *(undefined1 *)((ulonglong)*(uint *)((longlong)param_3 + 0xc) + *param_3) = 0xf3;
      *(int *)((longlong)param_3 + 0xc) = *(int *)((longlong)param_3 + 0xc) + 1;
    }
    uVar3 = GenNamedValueListEnd(param_3);
  }
  return uVar3 & 0xffffffff;
}



===== ParseGetTableColumnData @ 14000e0c0 =====

int ParseGetTableColumnData
              (undefined8 param_1,undefined8 param_2,longlong param_3,undefined4 *param_4)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  longlong lVar4;
  longlong *_Dst;
  undefined *puVar5;
  longlong *plVar6;
  longlong *plVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  longlong *plVar10;
  uint uVar11;
  bool bVar12;
  undefined1 uVar13;
  int local_48;
  longlong *local_40;
  longlong local_38;
  
  iVar3 = 0;
  puVar5 = WPP_GLOBAL_Control;
  if ((*(int *)(param_3 + 8) == 5) && (*(int *)(param_3 + 0xc) == 1)) {
    lVar4 = *(longlong *)(param_3 + 0x10);
    local_38 = lVar4;
    if (*(int *)(lVar4 + 8) == 5) {
      puVar9 = *(undefined8 **)(lVar4 + 0x10);
      local_48 = 0;
      bVar2 = false;
      uVar11 = 0;
      while( true ) {
        if ((puVar9 == (undefined8 *)0x0) || ((uint)param_4[4] <= uVar11)) goto LAB_14000e456;
        plVar10 = (longlong *)((ulonglong)uVar11 * 0x20 + *(longlong *)(param_4 + 2));
        local_40 = (longlong *)0x0;
        uVar13 = (undefined1)uVar11;
        if ((*(int *)(puVar9 + 1) != 6) ||
           ((*(int *)((longlong)puVar9 + 0xc) != 2 ||
            (plVar7 = (longlong *)puVar9[2], plVar7 == (longlong *)0x0)))) break;
        if (*(int *)((longlong)plVar10 + 0xc) == 0) {
          if (!bVar2) {
            uVar1 = *(uint *)(plVar10 + 1);
            if (uVar1 < *(uint *)((longlong)plVar7 + 0xc)) {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                           &WPP_26031245b0af395f80dcd19d8421604d_Traceguids,uVar11,(char)uVar1,
                           (char)*(uint *)((longlong)plVar7 + 0xc));
              }
              TcglibEalLogError((ulonglong)(uint)param_4[1],"ErrInvalidColData",4,(char)*param_4,
                                (char)param_4[1],uVar13);
              iVar3 = -0x3fffffdd;
              plVar7 = (longlong *)0x0;
            }
            else {
              if (uVar1 < 9) {
                *plVar10 = 0;
                plVar6 = (longlong *)0x0;
                if ((int)plVar7[1] - 7U < 0xb) {
                  if (*(uint *)((longlong)plVar7 + 0xc) < 9) {
                    plVar6 = plVar7 + 2;
                  }
                  else {
                    plVar6 = (longlong *)plVar7[2];
                  }
                }
                _Dst = plVar10;
              }
              else {
                memset((void *)*plVar10,0,(ulonglong)uVar1);
                plVar6 = (longlong *)0x0;
                if ((int)plVar7[1] - 7U < 0xb) {
                  if (*(uint *)((longlong)plVar7 + 0xc) < 9) {
                    plVar6 = plVar7 + 2;
                  }
                  else {
                    plVar6 = (longlong *)plVar7[2];
                  }
                }
                _Dst = (longlong *)*plVar10;
              }
              memmove(_Dst,plVar6,(ulonglong)*(uint *)((longlong)plVar7 + 0xc));
              *(undefined4 *)(plVar10 + 1) = *(undefined4 *)((longlong)plVar7 + 0xc);
              *(int *)((longlong)plVar10 + 0xc) = (int)plVar7[1];
              puVar9 = (undefined8 *)*puVar9;
            }
            goto LAB_14000e2d2;
          }
          iVar3 = -0x3ffffff3;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                    &WPP_26031245b0af395f80dcd19d8421604d_Traceguids);
            goto LAB_14000e456;
          }
LAB_14000e391:
          bVar12 = true;
          if (iVar3 < 0) goto LAB_14000e458;
        }
        else {
          bVar2 = true;
          uVar8 = FindNamedToken(plVar10,lVar4,(longlong *)&local_40);
          iVar3 = (int)uVar8;
          plVar7 = local_40;
LAB_14000e2d2:
          if ((iVar3 < 0) || (plVar7 == (longlong *)0x0)) {
            lVar4 = local_38;
            goto LAB_14000e391;
          }
          plVar7 = (longlong *)*plVar7;
          uVar1 = *(uint *)(plVar10 + 3);
          local_40 = plVar7;
          if (uVar1 < *(uint *)((longlong)plVar7 + 0xc)) {
            iVar3 = -0x3fffffdd;
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                         &WPP_26031245b0af395f80dcd19d8421604d_Traceguids,uVar11,(char)uVar1,
                         (char)*(uint *)((longlong)plVar7 + 0xc));
            }
            TcglibEalLogError((ulonglong)(uint)param_4[1],"ErrInvalidColData",5,(char)*param_4,
                              (char)param_4[1],uVar13);
            goto LAB_14000e456;
          }
          memset((void *)plVar10[2],0,(ulonglong)uVar1);
          plVar6 = (longlong *)0x0;
          if ((int)plVar7[1] - 7U < 0xb) {
            if (*(uint *)((longlong)plVar7 + 0xc) < 9) {
              plVar6 = plVar7 + 2;
            }
            else {
              plVar6 = (longlong *)plVar7[2];
            }
          }
          memmove((void *)plVar10[2],plVar6,(ulonglong)*(uint *)((longlong)plVar7 + 0xc));
          local_48 = local_48 + 1;
          *(undefined4 *)(plVar10 + 3) = *(undefined4 *)((longlong)plVar7 + 0xc);
          *(int *)((longlong)plVar10 + 0x1c) = (int)plVar7[1];
          lVar4 = local_38;
        }
        uVar11 = uVar11 + 1;
      }
      puVar5 = WPP_GLOBAL_Control;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        puVar5 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
        WPP_SF_dd(puVar5,0xd,&WPP_26031245b0af395f80dcd19d8421604d_Traceguids,*(int *)(puVar9 + 1),
                  (char)*(undefined4 *)((longlong)puVar9 + 0xc));
      }
      iVar3 = -0x3ffffe7b;
      TcglibEalLogError(puVar5,"ErrInvalidColData",3,(char)*param_4,(char)param_4[1],uVar13);
LAB_14000e456:
      bVar12 = iVar3 < 0;
LAB_14000e458:
      if (bVar12) {
        local_48 = 0;
      }
      param_4[4] = local_48;
      return iVar3;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      puVar5 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      WPP_SF_dd(puVar5,0xc,&WPP_26031245b0af395f80dcd19d8421604d_Traceguids,*(int *)(lVar4 + 8),
                (char)*(undefined4 *)(lVar4 + 0xc));
    }
    uVar8 = 2;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      puVar5 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      WPP_SF_dd(puVar5,0xb,&WPP_26031245b0af395f80dcd19d8421604d_Traceguids,*(int *)(param_3 + 8),
                (char)*(undefined4 *)(param_3 + 0xc));
    }
    uVar8 = 1;
  }
  TcglibEalLogError(puVar5,"ErrInvalidColData",uVar8,(char)*param_4,(char)param_4[1],0);
  return -0x3ffffe7b;
}



===== TcglibpAllocateRequestResources @ 14000e4ec =====

uint TcglibpAllocateRequestResources
               (undefined8 param_1,char param_2,short param_3,uint param_4,longlong *param_5,
               longlong *param_6)

{
  uint uVar1;
  
  *param_5 = 0;
  *param_6 = 0;
  uVar1 = TcglibEalAllocateIfSendCommand(param_1,param_2,param_3,param_4,param_5);
  if ((-1 < (int)uVar1) &&
     (uVar1 = TcglibEalAllocateIfRecvCommand(param_1,param_2,param_3,param_4,param_6),
     -1 < (int)uVar1)) {
    return uVar1;
  }
  if (*param_5 != 0) {
    TcglibEalFreeCommand(param_1,*param_5);
    *param_5 = 0;
  }
  if (*param_6 != 0) {
    TcglibEalFreeCommand(param_1,*param_6);
    *param_6 = 0;
  }
  return uVar1;
}



===== TcglibpCallMethod @ 14000e5a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong TcglibpCallMethod(undefined8 *param_1,longlong param_2,longlong param_3,longlong param_4,
                           undefined *param_5,undefined8 param_6,undefined8 param_7,
                           undefined8 param_8,undefined *param_9,undefined8 param_10)

{
  undefined8 uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  undefined8 *puVar9;
  char *pcVar10;
  undefined8 *puVar11;
  byte local_res8 [8];
  uint local_res10 [2];
  undefined8 *puVar12;
  int local_78 [2];
  undefined8 *local_70;
  longlong local_68;
  longlong local_60;
  longlong local_58;
  longlong local_50;
  undefined8 *local_48;
  uint local_40;
  uint local_3c;
  
  uVar1 = *param_1;
  local_50 = *(longlong *)(param_2 + 0x28);
  local_60 = *(longlong *)(param_2 + 0x30);
  local_70 = (undefined8 *)0x0;
  local_res10[0] = 0;
  TcglibEalGetCommandPayload(uVar1,local_50,(longlong *)&local_70,local_res10);
  local_48 = local_70 + 7;
  local_40 = local_res10[0] - 0x38;
  local_3c = 0;
  if (local_40 == 0) {
LAB_14000e678:
    puVar11 = (undefined8 *)0xc0000023;
    goto LAB_14000e832;
  }
  *(undefined1 *)local_48 = 0xf8;
  uVar5 = 8;
  local_3c = 1;
  local_68 = param_3;
  TcglibReverseBytes((undefined1 *)&local_68,8);
  uVar6 = GenDataBytes((longlong *)&local_48,&local_68,uVar5);
  puVar11 = (undefined8 *)(uVar6 & 0xffffffff);
  if ((int)uVar6 < 0) goto LAB_14000e832;
  uVar5 = 8;
  local_68 = param_4;
  TcglibReverseBytes((undefined1 *)&local_68,8);
  uVar6 = GenDataBytes((longlong *)&local_48,&local_68,uVar5);
  puVar11 = (undefined8 *)(uVar6 & 0xffffffff);
  if ((int)uVar6 < 0) goto LAB_14000e832;
  if (local_40 < local_3c + 1) goto LAB_14000e678;
  *(undefined1 *)((ulonglong)local_3c + (longlong)local_48) = 0xf0;
  local_3c = local_3c + 1;
  if (param_5 != (undefined *)0x0) {
    uVar5 = (*(code *)param_5)(param_1,param_2,&local_48,param_6);
    puVar11 = (undefined8 *)(ulonglong)uVar5;
    if ((int)uVar5 < 0) goto LAB_14000e832;
  }
  uVar6 = GenCallMethodEnd((longlong *)&local_48);
  puVar11 = (undefined8 *)(uVar6 & 0xffffffff);
  if ((int)uVar6 < 0) goto LAB_14000e832;
  uVar3 = 0;
  uVar8 = 0;
  if (param_3 != 0xff) {
    uVar3 = *(undefined4 *)(param_2 + 8);
    uVar8 = *(undefined4 *)(param_2 + 4);
  }
  uVar6 = GenTCGHeaders(local_70,local_res10[0],param_2,local_3c,uVar3,uVar8);
  puVar11 = (undefined8 *)(uVar6 & 0xffffffff);
  if ((int)uVar6 < 0) goto LAB_14000e832;
  iVar4 = TcglibReverseUInt32(*(undefined4 *)(local_70 + 2));
  uVar7 = uVar1;
  uVar5 = TcglibpExecuteCommand(uVar1,local_50,iVar4 + 0x14,'\0');
  puVar11 = (undefined8 *)(longlong)(int)uVar5;
  if ((int)uVar5 < 0) {
    pcVar10 = "TcglibpCallMethod-SEND failed";
  }
  else {
    uVar7 = uVar1;
    uVar5 = TcglibpExecuteCommand(uVar1,local_60,0,'\x01');
    puVar11 = (undefined8 *)(longlong)(int)uVar5;
    if (-1 < (int)uVar5) {
      TcglibEalGetCommandPayload(uVar1,local_60,(longlong *)&local_70,local_res10);
      uVar7 = InitTcgParser((longlong)param_1,(longlong)local_70,(ulonglong)local_res10[0]);
      if ((int)uVar7 != 0) goto LAB_14000e82f;
      local_58 = 0;
      uVar6 = ParseToken(param_1 + 7,param_1 + 9);
      if ((int)uVar6 < 0) {
LAB_14000e868:
        iVar4 = (int)uVar6;
        puVar11 = (undefined8 *)(uVar6 & 0xffffffff);
        if (iVar4 < 0) goto LAB_14000e80d;
        puVar9 = param_1;
        uVar7 = ParseTcgMethodData((longlong)param_1,param_7,param_8,&local_58);
        puVar11 = (undefined8 *)(longlong)(int)uVar7;
        if ((int)uVar7 < 0) {
          uVar2 = 0;
          pcVar10 = "ParseTcgMethodData failed";
          puVar12 = puVar11;
          goto LAB_14000e824;
        }
        if (param_9 != (undefined *)0x0) {
          puVar9 = param_1;
          iVar4 = (*(code *)param_9)(param_1,param_2,local_58,param_10);
          puVar11 = (undefined8 *)(longlong)iVar4;
          if (iVar4 < 0) {
            uVar2 = 0;
            pcVar10 = "TcglibpCallMethod-Parsing data failed";
            puVar12 = puVar11;
            goto LAB_14000e824;
          }
        }
      }
      else {
        local_res8[0] = 0;
        local_78[0] = 0;
        uVar7 = PeekTokenInfo(param_1 + 7,local_res8,local_78);
        if (((int)uVar7 < 0) || (local_res8[0] == 0xf9)) {
          *(int *)((longlong)param_1 + 0x44) = *(int *)((longlong)param_1 + 0x44) + 1;
          uVar6 = ParseTcgPayloadStatus(param_1);
          goto LAB_14000e868;
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                  &WPP_d27db7d0d3983550ea60457830c64ea4_Traceguids);
        }
        puVar11 = (undefined8 *)0xc0000185;
        iVar4 = -0x3ffffe7b;
LAB_14000e80d:
        uVar2 = (undefined1)iVar4;
        puVar9 = (undefined8 *)(ulonglong)*(byte *)(param_1 + 0xb);
        pcVar10 = "ParseTcgReceivedPayload failed";
        puVar12 = puVar9;
LAB_14000e824:
        TcglibEalLogError(puVar9,pcVar10,param_3,(char)param_4,(char)puVar12,uVar2);
      }
LAB_14000e82f:
      LOCK();
      *(undefined4 *)((longlong)param_1 + 0x34) = 0;
      UNLOCK();
      goto LAB_14000e832;
    }
    pcVar10 = "TcglibpCallMethod-RECV failed";
  }
  TcglibEalLogError(uVar7,pcVar10,param_3,(char)param_4,(char)puVar11,0);
LAB_14000e832:
  TcglibpReinitRequestResources(uVar1,local_50,local_60);
  return (ulonglong)puVar11 & 0xffffffff;
}



===== TcglibpExecuteCommand @ 14000e8e8 =====

uint TcglibpExecuteCommand(undefined8 param_1,longlong param_2,uint param_3,char param_4)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  longlong lVar6;
  uint local_res20 [2];
  longlong local_48 [2];
  
  local_res20[0] = 0;
  iVar5 = 10000;
  lVar6 = 1;
LAB_14000e91e:
  do {
    uVar2 = TcglibEalExecuteCommandSync(param_1,param_2,param_3);
    if ((int)uVar2 < 0) {
      if (param_4 == '\0') {
        return uVar2;
      }
      if (uVar2 != 0x80000011) {
        return uVar2;
      }
    }
    else {
      if (param_4 == '\0') {
        return uVar2;
      }
      local_48[0] = 0;
      TcglibEalGetCommandPayload(param_1,param_2,local_48,local_res20);
      lVar1 = local_48[0];
      if (local_res20[0] < 0x14) {
        return 0xc0000185;
      }
      iVar3 = TcglibReverseUInt32(*(undefined4 *)(local_48[0] + 0x10));
      uVar4 = TcglibReverseUInt32(*(undefined4 *)(lVar1 + 8));
      if (iVar3 != 0) {
        return uVar2;
      }
      if (uVar4 == 0) {
        return 0xc0000185;
      }
      if (1 < uVar4) {
        return 0x80000005;
      }
      if (uVar4 != 1) {
        return uVar2;
      }
      uVar2 = 0x80000011;
      iVar5 = iVar5 + -1;
      if (iVar5 != 0) {
        TcglibEalReuseCommand(param_1,param_2);
        local_48[0] = lVar6 * -10000;
        KeDelayExecutionThread(0,0,local_48);
        lVar6 = 5;
        goto LAB_14000e91e;
      }
    }
    if (iVar5 == 0) {
      return uVar2;
    }
  } while( true );
}



===== TcglibpGetTableColumnData @ 14000ea18 =====

void TcglibpGetTableColumnData
               (undefined8 *param_1,longlong param_2,longlong param_3,uint param_4,
               undefined8 param_5,undefined4 param_6,undefined4 *param_7)

{
  uint local_48;
  uint local_44;
  ulonglong *local_40;
  undefined4 local_38;
  undefined4 local_34;
  ulonglong local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined4 local_18;
  undefined4 local_14;
  
  local_34 = 0;
  local_14 = 0;
  local_30 = (ulonglong)param_4;
  local_20 = param_5;
  local_18 = param_6;
  local_40 = &local_30;
  local_28 = 4;
  local_24 = 8;
  local_38 = 1;
  local_48 = param_4;
  local_44 = param_4;
  TcglibpGetTableColumns(param_1,param_2,param_3,&local_48);
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = local_18;
  }
  return;
}



===== TcglibpGetTableColumns @ 14000ea88 =====

void TcglibpGetTableColumns(undefined8 *param_1,longlong param_2,longlong param_3,uint *param_4)

{
  TcglibEalLogCommand(*param_1,"GetTableColumns",param_3,0x600000016,(ulonglong)*param_4,
                      (ulonglong)param_4[1]);
  TcglibpCallMethod(param_1,param_2,param_3,0x600000016,GenGetTableColumnParams,param_4,0,0,
                    ParseGetTableColumnData,param_4);
  return;
}



===== TcglibpReinitRequestResources @ 14000eb3c =====

undefined8 TcglibpReinitRequestResources(undefined8 param_1,longlong param_2,longlong param_3)

{
  undefined8 uVar1;
  
  if ((param_2 == 0) || (param_3 == 0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_26031245b0af395f80dcd19d8421604d_Traceguids);
    }
    uVar1 = 0xc000000d;
  }
  else {
    uVar1 = TcglibEalReuseCommand(param_1,param_2);
    if (-1 < (int)uVar1) {
      uVar1 = TcglibEalReuseCommand(param_1,param_3);
    }
  }
  return uVar1;
}



===== TcglibpReleaseRequestResources @ 14000ebb4 =====

void TcglibpReleaseRequestResources(undefined8 param_1,longlong *param_2,longlong *param_3)

{
  if (*param_2 != 0) {
    TcglibEalFreeCommand(param_1,*param_2);
    *param_2 = 0;
  }
  if (*param_3 != 0) {
    TcglibEalFreeCommand(param_1,*param_3);
    *param_3 = 0;
  }
  return;
}



===== TcglibpSetTableColumnData @ 14000ec08 =====

void TcglibpSetTableColumnData
               (undefined8 *param_1,longlong param_2,longlong param_3,uint param_4,
               undefined8 param_5,undefined4 param_6,undefined4 param_7)

{
  uint local_48;
  uint local_44;
  ulonglong *local_40;
  undefined4 local_38;
  undefined4 local_34;
  ulonglong local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined4 local_18;
  undefined4 local_14;
  
  local_34 = 0;
  local_30 = (ulonglong)param_4;
  local_20 = param_5;
  local_18 = param_6;
  local_14 = param_7;
  local_40 = &local_30;
  local_28 = 4;
  local_24 = 8;
  local_38 = 1;
  local_48 = param_4;
  local_44 = param_4;
  TcglibpSetTableColumns(param_1,param_2,param_3,&local_48);
  return;
}



===== TcglibpSetTableColumns @ 14000ec6c =====

void TcglibpSetTableColumns(undefined8 *param_1,longlong param_2,longlong param_3,uint *param_4)

{
  TcglibEalLogCommand(*param_1,"SetTableColumns",param_3,0x600000017,(ulonglong)*param_4,
                      (ulonglong)param_4[1]);
  TcglibpCallMethod(param_1,param_2,param_3,0x600000017,GenSetTableColumnParams,param_4,0,0,
                    (undefined *)0x0,0);
  return;
}



===== GenActivateParams @ 14000ed20 =====

void GenActivateParams(longlong param_1,undefined8 param_2,longlong *param_3,byte *param_4)

{
  ulonglong uVar1;
  uint uVar2;
  undefined8 local_18 [2];
  
  local_18[0] = 0x80200000000;
  TcglibReverseBytes((undefined1 *)local_18,8);
  uVar1 = GenNamedValueBytes(param_3,0x60000,local_18,8);
  if (((-1 < (int)uVar1) &&
      (uVar1 = GenNamedValueInt(param_3,0x60001,(ulonglong)*param_4), -1 < (int)uVar1)) &&
     (uVar1 = GenNamedValueListBegin(param_3,0x60002), -1 < (int)uVar1)) {
    uVar2 = 0;
    do {
      if (*(uint *)(param_1 + 0x24) <= uVar2) {
        GenNamedValueListEnd(param_3);
        return;
      }
      uVar1 = GenInteger(param_3,(ulonglong)*(uint *)(param_1 + 0x28));
      uVar2 = uVar2 + 1;
    } while (-1 < (int)uVar1);
  }
  return;
}



===== GenSetACEBooleanExpr @ 14000ede0 =====

ulonglong GenSetACEBooleanExpr
                    (undefined8 param_1,undefined8 param_2,longlong *param_3,undefined8 *param_4)

{
  ulonglong uVar1;
  undefined4 local_res20 [2];
  undefined8 local_18 [2];
  
  local_res20[0] = TcglibReverseUInt32(0xc05);
  local_18[0] = *param_4;
  TcglibReverseBytes((undefined1 *)local_18,8);
  uVar1 = GenNamedValueListBegin(param_3,1);
  if ((-1 < (int)uVar1) && (uVar1 = GenNamedValueListBegin(param_3,3), -1 < (int)uVar1)) {
    if (*(uint *)((longlong)param_3 + 0xc) + 1 <= *(uint *)(param_3 + 1)) {
      *(undefined1 *)((ulonglong)*(uint *)((longlong)param_3 + 0xc) + *param_3) = 0xf2;
      *(int *)((longlong)param_3 + 0xc) = *(int *)((longlong)param_3 + 0xc) + 1;
      uVar1 = GenDataBytes(param_3,local_res20,4);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar1 = GenDataBytes(param_3,local_18,8);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      if (*(uint *)((longlong)param_3 + 0xc) + 1 <= *(uint *)(param_3 + 1)) {
        *(undefined1 *)((ulonglong)*(uint *)((longlong)param_3 + 0xc) + *param_3) = 0xf3;
        *(int *)((longlong)param_3 + 0xc) = *(int *)((longlong)param_3 + 0xc) + 1;
        uVar1 = GenNamedValueListEnd(param_3);
        if ((int)uVar1 < 0) {
          return uVar1;
        }
        uVar1 = GenNamedValueListEnd(param_3);
        return uVar1;
      }
    }
    uVar1 = 0xc0000023;
  }
  return uVar1;
}



===== TcglibpActivateLockingSp @ 14000eec4 =====

void TcglibpActivateLockingSp(undefined8 *param_1,longlong param_2)

{
  undefined4 local_18 [4];
  
  local_18[0] = 0;
  TcglibEalLogCommand(*param_1,"ActivateLockingSp",0x20500000002,0x600000203,0,0);
  TcglibpCallMethod(param_1,param_2,0x20500000002,0x600000203,GenActivateParams,local_18,0,0,
                    (undefined *)0x0,0);
  return;
}



===== TcglibpConfigureLockingSp @ 14000ef74 =====

int TcglibpConfigureLockingSp(undefined8 *param_1,longlong param_2)

{
  int iVar1;
  undefined8 *puVar2;
  uint uVar3;
  
  iVar1 = 0;
  uVar3 = 0;
  while( true ) {
    if (*(uint *)(param_1 + 6) <= uVar3) {
      return iVar1;
    }
    puVar2 = param_1;
    iVar1 = TcglibpSetACEBooleanExpr(param_1,param_2,(ulonglong)uVar3 + 0x800043000,0x900000001);
    if (iVar1 < 0) break;
    puVar2 = param_1;
    iVar1 = TcglibpSetACEBooleanExpr
                      (param_1,param_2,(ulonglong)(uVar3 * 2) + 0x80003fc00,0x900000001);
    if ((iVar1 < 0) ||
       (puVar2 = param_1,
       iVar1 = TcglibpSetACEBooleanExpr
                         (param_1,param_2,(ulonglong)(uVar3 * 2) + 0x80003fc01,
                          (ulonglong)uVar3 + 0x900030001), iVar1 < 0)) break;
    uVar3 = uVar3 + 1;
  }
  TcglibEalLogError(puVar2,"TcglibConfigureLockingSp failed",(longlong)iVar1,
                    (char)*(undefined4 *)(param_1 + 6),(char)uVar3,0);
  return iVar1;
}



===== TcglibpRevertLockingSp @ 14000f074 =====

void TcglibpRevertLockingSp(undefined8 *param_1,longlong param_2)

{
  TcglibEalLogCommand(*param_1,"RevertLockingSp",0x20500000001,0x600000202,0,0);
  TcglibpCallMethod(param_1,param_2,0x20500000001,0x600000202,(undefined *)0x0,0,0,0,
                    (undefined *)0x0,0);
  return;
}



===== TcglibpSetACEBooleanExpr @ 14000f114 =====

void TcglibpSetACEBooleanExpr
               (undefined8 *param_1,longlong param_2,longlong param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  TcglibEalLogCommand(*param_1,"SetACEBooleanExpr",param_3,0x600000017,param_4,0);
  TcglibpCallMethod(param_1,param_2,param_3,0x600000017,GenSetACEBooleanExpr,&local_res20,0,0,
                    (undefined *)0x0,0);
  return;
}



===== TcglibpGetCapabilities @ 14000f1b8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint TcglibpGetCapabilities(undefined8 *param_1,int *param_2)

{
  undefined8 uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 uVar4;
  undefined1 auStackY_c8 [32];
  ushort local_88 [2];
  undefined2 local_84 [2];
  uint local_80 [2];
  undefined4 *local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_c8;
  uVar1 = *param_1;
  local_78 = (undefined4 *)0x0;
  local_40 = 0;
  local_80[0] = 0;
  local_88[0] = 0;
  local_84[0] = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  uVar2 = TcglibEalGetDeviceCapabilities(uVar1,local_88,local_84,(longlong *)&local_78,local_80);
  if ((int)uVar2 < 0) {
    uVar3 = 0;
    if (uVar2 != 0xc00000bb) {
      uVar3 = uVar2;
    }
    if ((int)uVar3 < 0) {
      return uVar3;
    }
    (**(code **)(WdfFunctions_01015 + 0x650))
              (WdfDriverGlobals,uVar1,PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
    return 0xc0000010;
  }
  uVar2 = TcglibpParseLevel0Data((longlong)param_1,local_78,local_80[0],param_2);
  if (((local_88[0] != 0) &&
      (*(ushort *)((longlong)param_1 + 0x1c) = local_88[0],
      (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_0ef325dc9a723379ae6740d6b32d6064_Traceguids,(uint)local_88[0]);
  }
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  uVar2 = TcglibpGetTPerProperties(param_1,(longlong)&local_70,(undefined8 *)(param_2 + 2));
  if ((int)uVar2 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
              &WPP_0ef325dc9a723379ae6740d6b32d6064_Traceguids);
    }
    uVar2 = TcglibStackReset(param_1,(longlong)&local_70);
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return uVar2;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return uVar2;
      }
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
               &WPP_0ef325dc9a723379ae6740d6b32d6064_Traceguids,uVar2);
      return uVar2;
    }
    uVar2 = TcglibpGetTPerProperties(param_1,(longlong)&local_70,(undefined8 *)(param_2 + 2));
    if ((int)uVar2 < 0) {
      return uVar2;
    }
  }
  uVar2 = TcglibpOpenSessionWithRetry(param_1,&local_70,0x20500000001);
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  uVar2 = TcglibpGetTableColumnData
                    (param_1,(longlong)&local_70,0x20500000002,6,param_2 + 0x11,4,(undefined4 *)0x0)
  ;
  if (-1 < (int)uVar2) {
    uVar4 = 1;
    *(undefined1 *)(param_2 + 0x10) = 1;
    local_88[0] = local_88[0] & 0xff00;
    uVar2 = TcglibpGetTableColumnData
                      (param_1,(longlong)&local_70,0x900000006,5,local_88,1,(undefined4 *)0x0);
    if (((int)uVar2 < 0) || ((char)local_88[0] != '\0')) {
      if ((char)param_2[0x25] == '\0') goto LAB_14000f3c9;
      if ((*(char *)((longlong)param_2 + 0x95) == '\0') &&
         (*(char *)((longlong)param_2 + 0x96) != '\0')) {
        uVar4 = 0;
      }
    }
    *(undefined1 *)(param_2 + 1) = uVar4;
  }
LAB_14000f3c9:
  TcglibpCloseSession(param_1,(longlong)&local_70);
  if ((((-1 < (int)uVar2) && ((char)param_2[0x10] != '\0')) && (param_2[0x11] == 9)) &&
     (uVar2 = TcglibpOpenSessionWithRetry(param_1,&local_70,0x20500000002), -1 < (int)uVar2)) {
    uVar2 = TcglibpGetLockingInfoTable(param_1,(longlong)&local_70,(longlong)param_2);
    if (-1 < (int)uVar2) {
      uVar2 = TcglibpGetSecretProtection(param_1,(longlong)&local_70,(undefined8 *)(param_2 + 0x14))
      ;
    }
    TcglibpCloseSession(param_1,(longlong)&local_70);
  }
  return uVar2;
}



===== TcglibpGetLockingInfoTable @ 14000f4d4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TcglibpGetLockingInfoTable(undefined8 *param_1,longlong param_2,longlong param_3)

{
  int *piVar1;
  int iVar2;
  undefined1 auStack_168 [32];
  char local_148;
  char local_147 [7];
  uint local_140 [2];
  undefined8 *local_138;
  undefined4 local_130;
  undefined4 local_12c;
  undefined8 local_128;
  undefined4 local_120;
  undefined4 local_11c;
  int *local_118;
  undefined4 local_110;
  undefined4 local_10c;
  undefined8 local_108;
  undefined4 local_100;
  undefined4 local_fc;
  undefined1 *local_f8;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined4 local_dc;
  char *local_d8;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined8 local_c8;
  undefined4 local_c0;
  undefined4 local_bc;
  char *local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined8 local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  longlong local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
  undefined4 local_80;
  undefined4 local_7c;
  longlong local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 local_68;
  undefined4 local_60;
  undefined4 local_5c;
  longlong local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_168;
  local_12c = 0;
  piVar1 = (int *)(param_3 + 0x48);
  local_140[0] = 0;
  local_140[1] = 0;
  local_138 = &local_128;
  local_148 = '\0';
  local_147[0] = '\0';
  local_130 = 7;
  local_c8 = 7;
  local_108 = 0x60000;
  local_11c = 8;
  local_120 = 1;
  local_10c = 10;
  local_fc = 10;
  local_100 = 3;
  local_e0 = 3;
  local_d8 = &local_148;
  local_ec = 0xf;
  local_b8 = local_147;
  local_98 = param_3 + 100;
  local_78 = param_3 + 0x68;
  local_58 = param_3 + 0x70;
  local_dc = 10;
  local_8c = 10;
  local_6c = 0xf;
  local_68 = 10;
  local_4c = 0xf;
  local_128 = 4;
  local_110 = 4;
  local_f0 = 8;
  local_e8 = 0x60001;
  local_d0 = 1;
  local_cc = 8;
  local_c0 = 1;
  local_bc = 8;
  local_b0 = 1;
  local_ac = 8;
  local_a8 = 8;
  local_a0 = 1;
  local_9c = 8;
  local_90 = 4;
  local_88 = 9;
  local_80 = 1;
  local_7c = 8;
  local_70 = 8;
  local_60 = 1;
  local_5c = 8;
  local_50 = 8;
  local_118 = piVar1;
  local_f8 = (undefined1 *)(param_3 + 0x58);
  iVar2 = TcglibpGetTableColumns(param_1,param_2,0x80100000001,local_140);
  if (-1 < iVar2) {
    *piVar1 = *piVar1 + 1;
    *(int *)(param_1 + 6) = *piVar1;
    TcglibReverseBytes((undefined1 *)(param_3 + 0x58),8);
    *(bool *)(param_3 + 0x60) = local_148 == '\x01';
    *(bool *)(param_3 + 0x61) = local_147[0] == '\x01';
  }
  return iVar2;
}



===== TcglibpGetProtocolList @ 14000f690 =====

uint TcglibpGetProtocolList(undefined8 param_1,uint *param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  uint local_res10 [2];
  longlong local_res18;
  longlong local_res20;
  
  local_res20 = 0;
  local_res18 = 0;
  local_res10[0] = 0;
  *param_2 = 0;
  uVar2 = TcglibEalAllocateIfRecvCommand(param_1,'\0',0,0x800,&local_res18);
  if (-1 < (int)uVar2) {
    TcglibEalLogCommand(param_1,"GetProtocolList",0,0,0,0);
    uVar2 = TcglibEalExecuteCommandSync(param_1,local_res18,0);
    if (-1 < (int)uVar2) {
      TcglibEalGetCommandPayload(param_1,local_res18,&local_res20,local_res10);
      if (7 < local_res10[0]) {
        uVar3 = 0;
        uVar4 = (uint)CONCAT11(*(undefined1 *)(local_res20 + 6),*(undefined1 *)(local_res20 + 7));
        if (uVar4 != 0) {
          pcVar5 = (char *)(local_res20 + 8);
          do {
            if ((ulonglong)local_res10[0] < (longlong)(int)(uVar3 + 8) + 1U) break;
            cVar1 = *pcVar5;
            if (cVar1 == '\0') {
              *param_2 = *param_2 | 1;
            }
            else if (cVar1 == '\x01') {
              *param_2 = *param_2 | 2;
            }
            else if (cVar1 == '\x02') {
              *param_2 = *param_2 | 4;
            }
            uVar3 = uVar3 + 1;
            pcVar5 = pcVar5 + 1;
          } while (uVar3 < uVar4);
        }
      }
    }
  }
  if (local_res18 != 0) {
    TcglibEalFreeCommand(param_1,local_res18);
  }
  return uVar2;
}



===== TcglibpParseLevel0Data @ 14000f7ac =====

uint TcglibpParseLevel0Data(longlong param_1,undefined4 *param_2,uint param_3,int *param_4)

{
  undefined4 uVar1;
  byte bVar2;
  byte bVar3;
  short sVar4;
  undefined2 uVar5;
  ushort uVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint uVar11;
  
  bVar2 = 0;
  memset(param_4,0,0xa8);
  if (0x30 < param_3) {
    uVar1 = *param_2;
    iVar7 = TcglibReverseUInt32(uVar1);
    if (iVar7 + 4U <= param_3) {
      iVar7 = TcglibReverseUInt32(uVar1);
      param_3 = iVar7 + 4;
      if (param_3 < 0x31) goto LAB_14000faa6;
    }
    puVar9 = param_2 + 0xc;
    bVar2 = 0;
    for (uVar10 = param_3 - 0x30; 3 < uVar10; uVar10 = uVar10 - uVar11) {
      sVar4 = TcglibReverseUInt16(*(undefined2 *)puVar9);
      bVar3 = *(byte *)((longlong)puVar9 + 3);
      uVar11 = bVar3 + 4;
      if (uVar10 < uVar11) break;
      if (sVar4 == 2) {
        if (bVar3 == 0xc) {
          *(byte *)(param_4 + 0xd) = *(byte *)(puVar9 + 1) & 1;
          *(byte *)((longlong)param_4 + 0x35) = *(byte *)(puVar9 + 1) >> 1 & 1;
          *(byte *)((longlong)param_4 + 0x36) = *(byte *)(puVar9 + 1) >> 2 & 1;
          *(byte *)((longlong)param_4 + 0x37) = *(byte *)(puVar9 + 1) >> 3 & 1;
          *(byte *)(param_4 + 0xe) = *(byte *)(puVar9 + 1) >> 4 & 1;
          *(byte *)((longlong)param_4 + 0x39) = *(byte *)(puVar9 + 1) >> 5 & 1;
        }
      }
      else if (sVar4 == 0x200) {
        if (bVar3 == 0x10) {
          if (*param_4 == 0x200) goto LAB_14000f8b8;
LAB_14000f8cb:
          *param_4 = 0x200;
          bVar2 = 1;
          *(undefined4 *)(param_1 + 0x20) = 0x200;
          uVar5 = TcglibReverseUInt16(*(undefined2 *)(puVar9 + 1));
          *(undefined2 *)(param_1 + 0x1c) = uVar5;
          *(byte *)(param_4 + 0x1e) = ~*(byte *)(puVar9 + 2) & 1;
          if (sVar4 == 0x203) {
            uVar5 = TcglibReverseUInt16(*(undefined2 *)((longlong)puVar9 + 9));
            *(undefined2 *)((longlong)param_4 + 0x7a) = uVar5;
            uVar5 = TcglibReverseUInt16(*(undefined2 *)((longlong)puVar9 + 0xb));
            *(undefined2 *)(param_4 + 0x1f) = uVar5;
            *(undefined1 *)((longlong)param_4 + 0x7e) = *(undefined1 *)((longlong)puVar9 + 0xd);
            *(undefined1 *)((longlong)param_4 + 0x7f) = *(undefined1 *)((longlong)puVar9 + 0xe);
          }
        }
      }
      else {
LAB_14000f8b8:
        if (sVar4 == 0x203) {
          if (bVar3 == 0x10) goto LAB_14000f8cb;
        }
        else if (sVar4 == 0x201) {
          if (bVar3 == 0xc) {
            iVar7 = TcglibReverseUInt32(puVar9[1]);
            param_4[0x20] = iVar7;
            *(byte *)(param_4 + 0x21) = *(byte *)(puVar9 + 2) & 1;
            *(byte *)((longlong)param_4 + 0x85) = *(byte *)(puVar9 + 2) >> 1 & 1;
            bVar3 = *(byte *)(puVar9 + 2);
            *(undefined1 *)((longlong)param_4 + 0x79) = 1;
            *(byte *)((longlong)param_4 + 0x86) = bVar3 >> 2 & 1;
          }
        }
        else if (sVar4 == 0x202) {
          if (bVar3 == 0xc) {
            uVar6 = TcglibReverseUInt16(*(undefined2 *)((longlong)puVar9 + 6));
            *(ushort *)(param_4 + 0x22) = uVar6;
            *(uint *)(param_1 + 0x24) = (uint)uVar6;
            uVar8 = TcglibReverseUInt32(puVar9[2]);
            param_4[0x23] = uVar8;
            *(uint *)(param_1 + 0x28) = uVar8 / *(ushort *)(param_4 + 0x22);
            iVar7 = TcglibReverseUInt32(puVar9[3]);
            param_4[0x24] = iVar7;
          }
        }
        else if (sVar4 == 0x402) {
          if (bVar3 == 0xc) {
            *(undefined1 *)(param_4 + 0x25) = 1;
            *(byte *)((longlong)param_4 + 0x95) = *(byte *)(puVar9 + 1) >> 1 & 1;
            *(byte *)((longlong)param_4 + 0x96) = ~*(byte *)(puVar9 + 1) & 1;
            *(byte *)((longlong)param_4 + 0x97) = *(byte *)((longlong)puVar9 + 5) & 1;
          }
        }
        else if ((sVar4 == 0x403) && (bVar3 == 0x10)) {
          *(undefined1 *)(param_4 + 0x26) = 1;
          if ((*(byte *)((longlong)puVar9 + 2) & 0xf0) < 0x20) {
            bVar3 = 0;
          }
          else {
            bVar3 = *(byte *)(puVar9 + 1) >> 5 & 1;
          }
          *(byte *)((longlong)param_4 + 0x99) = bVar3;
          *(byte *)((longlong)param_4 + 0x9a) = *(byte *)(puVar9 + 1) >> 7;
          *(byte *)((longlong)param_4 + 0x9b) = *(byte *)(puVar9 + 1) >> 6 & 1;
          iVar7 = TcglibReverseUInt32(puVar9[2]);
          param_4[0x27] = iVar7;
          iVar7 = TcglibReverseUInt32(puVar9[3]);
          param_4[0x28] = iVar7;
          iVar7 = TcglibReverseUInt32(puVar9[4]);
          param_4[0x29] = iVar7;
        }
      }
      puVar9 = (undefined4 *)((longlong)puVar9 + (ulonglong)uVar11);
    }
  }
LAB_14000faa6:
  return ~-(uint)bVar2 & 0xc00000bb;
}



===== Feature_3861539130__private_IsEnabledDeviceUsageNoInline @ 14000fad8 =====

ulonglong Feature_3861539130__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_3861539130__private_featureState;
  if ((Feature_3861539130__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3861539130__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3861539130__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3861539130__private_IsEnabledFallback @ 14000fb10 =====

void Feature_3861539130__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== GenRandomParams @ 14000fb30 =====

void GenRandomParams(undefined8 param_1,undefined8 param_2,longlong *param_3,longlong param_4)

{
  GenInteger(param_3,(ulonglong)*(uint *)(param_4 + 8));
  return;
}



===== ParseRandomData @ 14000fb50 =====

undefined4
ParseRandomData(undefined8 param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  uint *puVar1;
  ulonglong uVar2;
  undefined *puVar3;
  char *pcVar4;
  undefined8 *_Src;
  undefined8 uVar5;
  undefined *puVar6;
  
  puVar1 = (uint *)(param_3 + 0xc);
  _Src = (undefined8 *)0x0;
  if ((*(int *)(param_3 + 8) == 5) && (*puVar1 == 1)) {
    param_3 = *(longlong *)(param_3 + 0x10);
    if ((*(int *)(param_3 + 8) - 0xfU < 3) && (*(uint *)(param_3 + 0xc) <= *(uint *)(param_4 + 1)))
    {
      uVar2 = Feature_3861539130__private_IsEnabledDeviceUsageNoInline();
      if (((int)uVar2 == 0) || (*(uint *)(param_3 + 0xc) == *(uint *)(param_4 + 1))) {
        if ((*(int *)(param_3 + 8) - 7U < 0xb) &&
           (_Src = (undefined8 *)(param_3 + 0x10), 8 < *(uint *)(param_3 + 0xc))) {
          _Src = (undefined8 *)*_Src;
        }
        memmove((void *)*param_4,_Src,(ulonglong)*(uint *)(param_4 + 1));
        return 0;
      }
    }
    puVar3 = WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      puVar3 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      WPP_SF_ddd(puVar3,0x14,&WPP_2bd2463ed1cd385ffcc0853d24087de1_Traceguids,
                 *(undefined4 *)(param_4 + 1),(char)*(undefined4 *)(param_3 + 8),
                 (char)*(undefined4 *)(param_3 + 0xc));
    }
    pcVar4 = "ErrInvalidRandomNumber";
    uVar5 = 6;
    puVar6 = (undefined *)(ulonglong)*(uint *)(param_3 + 0xc);
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                &WPP_2bd2463ed1cd385ffcc0853d24087de1_Traceguids,*(int *)(param_3 + 8),(char)*puVar1
               );
    }
    puVar3 = (undefined *)(ulonglong)*puVar1;
    pcVar4 = "ErrInvalidSecretProtection";
    uVar5 = 1;
    puVar6 = puVar3;
  }
  TcglibEalLogError(puVar3,pcVar4,uVar5,(char)*(undefined4 *)(param_3 + 8),(char)puVar6,0);
  return 0xc0000185;
}



===== ParseSecretProtection @ 14000fcd0 =====

undefined8
ParseSecretProtection(undefined8 param_1,undefined8 param_2,longlong param_3,ulonglong *param_4)

{
  uint *puVar1;
  uint uVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  
  puVar1 = (uint *)(param_3 + 0xc);
  *param_4 = 0;
  if ((*(int *)(param_3 + 8) == 5) && (*puVar1 == 1)) {
    lVar3 = *(longlong *)(param_3 + 0x10);
    puVar1 = (uint *)(lVar3 + 0xc);
    puVar6 = WPP_GLOBAL_Control;
    if ((*(int *)(lVar3 + 8) != 5) || (*puVar1 != 1)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        puVar6 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
        WPP_SF_dd(puVar6,0xf,&WPP_2bd2463ed1cd385ffcc0853d24087de1_Traceguids,*(int *)(lVar3 + 8),
                  (char)*puVar1);
      }
      puVar5 = (undefined *)(ulonglong)*puVar1;
      uVar8 = 2;
      uVar10 = 0;
      uVar9 = (undefined1)*(undefined4 *)(lVar3 + 8);
      goto LAB_14000ff3a;
    }
    lVar3 = *(longlong *)(lVar3 + 0x10);
    if (((*(int *)(lVar3 + 8) != 6) || (*(int *)(lVar3 + 0xc) != 2)) ||
       (plVar4 = *(longlong **)(lVar3 + 0x10), plVar4 == (longlong *)0x0)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        puVar6 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
        WPP_SF_dd(puVar6,0x10,&WPP_2bd2463ed1cd385ffcc0853d24087de1_Traceguids,*(int *)(lVar3 + 8),
                  (char)*(undefined4 *)(lVar3 + 0xc));
      }
      puVar5 = (undefined *)(ulonglong)*(uint *)(lVar3 + 0xc);
      uVar8 = 3;
      uVar10 = 0;
      uVar9 = (undefined1)*(undefined4 *)(lVar3 + 8);
      goto LAB_14000ff3a;
    }
    if ((((int)plVar4[1] - 7U < 8) && (*(uint *)((longlong)plVar4 + 0xc) < 5)) && (plVar4[2] == 3))
    {
      lVar3 = *plVar4;
      if (*(int *)(lVar3 + 8) == 5) {
        for (puVar7 = *(undefined8 **)(lVar3 + 0x10); puVar7 != (undefined8 *)0x0;
            puVar7 = (undefined8 *)*puVar7) {
          if (*(int *)(puVar7 + 1) == 8) {
            *param_4 = *param_4 | 1L << ((ulonglong)*(byte *)(puVar7 + 2) & 0x3f);
          }
        }
        return 0;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        puVar6 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
        WPP_SF_dd(puVar6,0x12,&WPP_2bd2463ed1cd385ffcc0853d24087de1_Traceguids,*(int *)(lVar3 + 8),
                  (char)*(undefined4 *)(lVar3 + 0xc));
      }
      uVar8 = 5;
      uVar10 = 0;
      uVar9 = (undefined1)*(undefined4 *)(lVar3 + 8);
      puVar5 = (undefined *)(ulonglong)*(uint *)(lVar3 + 0xc);
      goto LAB_14000ff3a;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_ddi(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                 &WPP_2bd2463ed1cd385ffcc0853d24087de1_Traceguids,(int)plVar4[1],
                 (char)*(undefined4 *)((longlong)plVar4 + 0xc),(char)plVar4[2]);
    }
    uVar10 = (undefined1)plVar4[2];
    uVar8 = 4;
    uVar2 = *(uint *)((longlong)plVar4 + 0xc);
    uVar9 = (undefined1)plVar4[1];
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                &WPP_2bd2463ed1cd385ffcc0853d24087de1_Traceguids,*(int *)(param_3 + 8),(char)*puVar1
               );
    }
    uVar2 = *puVar1;
    uVar8 = 1;
    uVar9 = (undefined1)*(undefined4 *)(param_3 + 8);
    uVar10 = 0;
  }
  puVar6 = (undefined *)(ulonglong)uVar2;
  puVar5 = puVar6;
LAB_14000ff3a:
  TcglibEalLogError(puVar6,"ErrInvalidSecretProtection",uVar8,uVar9,(char)puVar5,uVar10);
  return 0xc0000185;
}



===== TcglibpGenRandom @ 14000ff64 =====

void TcglibpGenRandom(undefined8 *param_1,longlong param_2,void *param_3,uint param_4)

{
  void *local_18;
  uint local_10;
  undefined4 local_c;
  
  local_c = 0;
  memset(param_3,0,(ulonglong)param_4);
  local_18 = param_3;
  local_10 = param_4;
  TcglibEalLogCommand(*param_1,"GenRandom",1,0x600000601,0,0);
  TcglibpCallMethod(param_1,param_2,1,0x600000601,GenRandomParams,&local_18,0,0,ParseRandomData,
                    &local_18);
  return;
}



===== TcglibpGetMsid @ 140010038 =====

void TcglibpGetMsid(undefined8 *param_1,longlong param_2,undefined4 *param_3)

{
  TcglibpGetTableColumnData(param_1,param_2,0xb00008402,3,param_3 + 1,0x20,param_3);
  return;
}



===== TcglibpGetSecretProtection @ 140010074 =====

void TcglibpGetSecretProtection(undefined8 *param_1,longlong param_2,undefined8 *param_3)

{
  int iVar1;
  ulonglong local_res18 [2];
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined4 local_38;
  undefined4 local_34;
  
  *param_3 = 0;
  local_res18[0] = 0;
  iVar1 = TcglibpGetTableColumnData
                    (param_1,param_2,0x80200000001,10,local_res18,8,(undefined4 *)0x0);
  if (-1 < iVar1) {
    local_34 = 0;
    local_40 = 0;
    local_48 = 3;
    local_44 = 3;
    local_38 = 1;
    TcglibReverseBytes((undefined1 *)local_res18,8);
    local_res18[0] = local_res18[0] & 0xffffffff00000000;
    TcglibEalLogCommand(*param_1,"GetSecretProtection",
                        (ulonglong)(local_res18[0] != 0x80500000000) + 0x1d0000001d,0x600000016,0,0)
    ;
    TcglibpCallMethod(param_1,param_2,(ulonglong)(local_res18[0] != 0x80500000000) + 0x1d0000001d,
                      0x600000016,GenGetTableColumnParams,&local_48,0,0,ParseSecretProtection,
                      param_3);
  }
  return;
}



===== TcglibpSetAuthorityPin @ 1400101c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint TcglibpSetAuthorityPin
               (undefined8 *param_1,longlong param_2,uint *param_3,uint *param_4,longlong param_5,
               char param_6)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined1 auStackY_108 [32];
  int local_b8 [6];
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  uint local_80 [10];
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_108;
  local_88 = 0;
  local_b8[0] = 0;
  local_b8[1] = 0;
  local_b8[2] = 0;
  local_b8[3] = 0;
  local_b8[4] = 0;
  local_b8[5] = 0;
  uStack_a0 = 0;
  local_98 = 0;
  uStack_90 = 0;
  if ((param_6 != '\0') && (param_5 == 0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_2bd2463ed1cd385ffcc0853d24087de1_Traceguids);
    }
    return 0xc000000d;
  }
  uVar3 = TcglibOpenSession(param_1,(param_2 != 0x900000006) + 1,(undefined8 *)local_b8);
  if ((int)uVar3 < 0) {
    return uVar3;
  }
  iVar4 = 0;
  LOCK();
  if (uStack_a0._4_4_ == 0) {
    uStack_a0 = CONCAT44(1,(undefined4)uStack_a0);
  }
  else {
    iVar4 = uStack_a0._4_4_;
  }
  UNLOCK();
  if (iVar4 == 1) {
    uVar3 = 0x80000011;
    goto LAB_14001046d;
  }
  bVar2 = false;
  local_80[8] = 0;
  bVar1 = false;
  local_80[0] = 0;
  local_80[1] = 0;
  local_80[2] = 0;
  local_80[3] = 0;
  local_80[4] = 0;
  local_80[5] = 0;
  local_80[6] = 0;
  local_80[7] = 0;
  if (param_5 != 0) {
    if (param_6 == '\0') {
      bVar2 = true;
    }
    else {
      bVar1 = true;
    }
  }
  if ((param_3 == (uint *)0x0) && (param_3 = local_80, param_2 == 0x900000006)) {
    TcglibpGetMsid(param_1,(longlong)local_b8,local_80);
  }
  uVar5 = TcglibpAuthenticateSession(param_1,(longlong)local_b8,param_2,param_3);
  uVar3 = (uint)uVar5;
  if (-1 < (int)uVar3) {
    if (*param_4 == 0) {
      *param_4 = 0x20;
      uVar3 = TcglibpGenRandom(param_1,(longlong)local_b8,param_4 + 1,0x20);
      if ((int)uVar3 < 0) goto LAB_14001046a;
    }
    if (bVar1) {
      uVar3 = TcglibpGetTableColumnData
                        (param_1,(longlong)local_b8,0x20100030001,2,param_5,0xc,(undefined4 *)0x0);
      if ((int)uVar3 < 0) goto LAB_14001046a;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_2bd2463ed1cd385ffcc0853d24087de1_Traceguids);
      }
    }
    if (*param_4 < 0x21) {
      lVar6 = 0xb00000001;
      if (param_2 != 0x900000006) {
        lVar6 = 0xb00010001;
      }
      uVar3 = TcglibpSetTableColumnData(param_1,(longlong)local_b8,lVar6,3,param_4 + 1,*param_4,0xf)
      ;
    }
    else {
      uVar3 = 0xc000000d;
    }
    if (bVar1) {
      if ((int)uVar3 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_2bd2463ed1cd385ffcc0853d24087de1_Traceguids,0xc00000bb);
        }
      }
      else {
LAB_14001043c:
        if (bVar2) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (2 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                    &WPP_2bd2463ed1cd385ffcc0853d24087de1_Traceguids);
          }
          uVar3 = 0;
        }
      }
    }
    else if (-1 < (int)uVar3) goto LAB_14001043c;
  }
LAB_14001046a:
  LOCK();
  uStack_a0 = uStack_a0 & 0xffffffff;
  UNLOCK();
LAB_14001046d:
  TcglibCloseSession(param_1,local_b8);
  return uVar3;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 1400104a4 =====

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
LAB_1400106ad:
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
LAB_14001057f:
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
      if (param_3 == 4) goto LAB_1400106ad;
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
        goto LAB_14001057f;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140010798 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (undefined8 param_1,ulonglong param_2,uint param_3)

{
  bool bVar1;
  undefined7 extraout_var;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  byte bVar5;
  uint local_res18 [4];
  
  uVar4 = (uint)param_2 & 1;
  uVar3 = (ulonglong)param_3;
  if (param_3 != 0) {
    if (param_3 == 1) {
      uVar2 = (uVar4 ^ 1) << 2;
      uVar3 = 0;
      goto LAB_14001085b;
    }
    if (param_3 == 2) {
      uVar2 = (uVar4 ^ 1) * 4 + 1;
      uVar3 = 0;
      goto LAB_14001085b;
    }
    if (param_3 == 3) {
      uVar2 = (uVar4 ^ 1) * 4 + 2;
      uVar3 = 0;
      goto LAB_14001085b;
    }
    if (param_3 == 4) {
      uVar2 = (uVar4 ^ 1) * 4 + 3;
      uVar3 = 0;
      goto LAB_14001085b;
    }
    uVar2 = param_3 - 5;
    uVar3 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      uVar2 = (uVar4 ^ 1) * 2 + 8;
      goto LAB_14001085b;
    }
    if (uVar2 == 1) {
      uVar2 = (uVar4 ^ 1) * 2 + 9;
      goto LAB_14001085b;
    }
    bVar5 = (char)param_3 + 0x9c;
    if (bVar5 < 0x32) {
      uVar2 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar5;
      goto LAB_14001085b;
    }
  }
  uVar2 = 0xff;
LAB_14001085b:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x3c6d4e7,&Feature_3861539130_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 1400108b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (undefined8 param_1,undefined8 param_2,uint param_3)

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
                     (local_50,&Feature_3861539130__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)(0x3c6d4e7,param_3,1,&Feature_3861539130__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)param_3,0x3c6d4e7);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 1400109a0 =====

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
LAB_140010a53:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_140010a81;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_140010a53;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_140010a81:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140010c0c =====

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
  if ((Feature_3861539130__private_featureState & 2) != 0) {
    uVar1 = Feature_3861539130__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_3861539130__private_featureState;
      if (bVar3) {
        Feature_3861539130__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_3861539130__private_featureState;
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



===== wil_details_IsEnabledFallback @ 140010c60 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_3861539130__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_3861539130__private_featureState,(ulonglong)param_1,
                             0x140018630);
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



===== GenAuthenticateParams @ 140010cf0 =====

void GenAuthenticateParams
               (undefined8 param_1,undefined8 param_2,longlong *param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  undefined8 local_res20;
  
  local_res20 = *param_4;
  TcglibReverseBytes((undefined1 *)&local_res20,8);
  uVar1 = GenDataBytes(param_3,&local_res20,8);
  if (-1 < (int)uVar1) {
    GenNamedValueBytes(param_3,0,(uint *)param_4[1] + 1,*(uint *)param_4[1]);
  }
  return;
}



===== GenSetTPerPropertiesParams @ 140010d60 =====

ulonglong GenSetTPerPropertiesParams
                    (undefined8 param_1,undefined8 param_2,longlong *param_3,uint *param_4)

{
  ulonglong uVar1;
  
  uVar1 = GenNamedValueListBegin(param_3,0);
  if ((int)uVar1 < 0) {
    return uVar1;
  }
  if (*(uint *)((longlong)param_3 + 0xc) + 1 <= *(uint *)(param_3 + 1)) {
    *(undefined1 *)((ulonglong)*(uint *)((longlong)param_3 + 0xc) + *param_3) = 0xf2;
    *(int *)((longlong)param_3 + 0xc) = *(int *)((longlong)param_3 + 0xc) + 1;
    uVar1 = GenMediumDataBytes(param_3,"MaxComPacketSize",0x10);
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    uVar1 = GenInteger(param_3,(ulonglong)*param_4);
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    if (*(uint *)((longlong)param_3 + 0xc) + 1 <= *(uint *)(param_3 + 1)) {
      *(undefined1 *)((ulonglong)*(uint *)((longlong)param_3 + 0xc) + *param_3) = 0xf3;
      *(int *)((longlong)param_3 + 0xc) = *(int *)((longlong)param_3 + 0xc) + 1;
      if (*(uint *)((longlong)param_3 + 0xc) + 1 <= *(uint *)(param_3 + 1)) {
        *(undefined1 *)((ulonglong)*(uint *)((longlong)param_3 + 0xc) + *param_3) = 0xf2;
        *(int *)((longlong)param_3 + 0xc) = *(int *)((longlong)param_3 + 0xc) + 1;
        uVar1 = GenMediumDataBytes(param_3,"MaxResponseComPacketSize",0x18);
        if ((int)uVar1 < 0) {
          return uVar1;
        }
        uVar1 = GenInteger(param_3,(ulonglong)*param_4);
        if ((int)uVar1 < 0) {
          return uVar1;
        }
        if (*(uint *)((longlong)param_3 + 0xc) + 1 <= *(uint *)(param_3 + 1)) {
          *(undefined1 *)((ulonglong)*(uint *)((longlong)param_3 + 0xc) + *param_3) = 0xf3;
          *(int *)((longlong)param_3 + 0xc) = *(int *)((longlong)param_3 + 0xc) + 1;
          if (*(uint *)((longlong)param_3 + 0xc) + 1 <= *(uint *)(param_3 + 1)) {
            *(undefined1 *)((ulonglong)*(uint *)((longlong)param_3 + 0xc) + *param_3) = 0xf2;
            *(int *)((longlong)param_3 + 0xc) = *(int *)((longlong)param_3 + 0xc) + 1;
            uVar1 = GenDataBytes(param_3,"MaxPacketSize",0xd);
            if ((int)uVar1 < 0) {
              return uVar1;
            }
            uVar1 = GenInteger(param_3,(ulonglong)*param_4 - 0x14);
            if ((int)uVar1 < 0) {
              return uVar1;
            }
            if (*(uint *)((longlong)param_3 + 0xc) + 1 <= *(uint *)(param_3 + 1)) {
              *(undefined1 *)((ulonglong)*(uint *)((longlong)param_3 + 0xc) + *param_3) = 0xf3;
              *(int *)((longlong)param_3 + 0xc) = *(int *)((longlong)param_3 + 0xc) + 1;
              if (*(uint *)((longlong)param_3 + 0xc) + 1 <= *(uint *)(param_3 + 1)) {
                *(undefined1 *)((ulonglong)*(uint *)((longlong)param_3 + 0xc) + *param_3) = 0xf2;
                *(int *)((longlong)param_3 + 0xc) = *(int *)((longlong)param_3 + 0xc) + 1;
                uVar1 = GenDataBytes(param_3,"MaxIndTokenSize",0xf);
                if ((int)uVar1 < 0) {
                  return uVar1;
                }
                uVar1 = GenInteger(param_3,(ulonglong)*param_4 - 0x38);
                if ((int)uVar1 < 0) {
                  return uVar1;
                }
                if (*(uint *)((longlong)param_3 + 0xc) + 1 <= *(uint *)(param_3 + 1)) {
                  *(undefined1 *)((ulonglong)*(uint *)((longlong)param_3 + 0xc) + *param_3) = 0xf3;
                  *(int *)((longlong)param_3 + 0xc) = *(int *)((longlong)param_3 + 0xc) + 1;
                  uVar1 = GenNamedValueListEnd(param_3);
                  return uVar1;
                }
              }
            }
          }
        }
      }
    }
  }
  return 0xc0000023;
}



===== GenStartSessionParams @ 140010f20 =====

void GenStartSessionParams(undefined8 param_1,longlong param_2,longlong *param_3)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined8 local_res10 [3];
  
  uVar1 = GenInteger(param_3,(ulonglong)*(uint *)(param_2 + 4));
  if (-1 < (int)uVar1) {
    local_res10[0] = *(undefined8 *)(param_2 + 0x10);
    TcglibReverseBytes((undefined1 *)local_res10,8);
    uVar2 = GenDataBytes(param_3,local_res10,8);
    if (-1 < (int)uVar2) {
      GenInteger(param_3,1);
    }
  }
  return;
}



===== ParseBooleanData @ 140010fa0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
ParseBooleanData(undefined8 param_1,undefined8 param_2,longlong param_3,undefined1 *param_4)

{
  uint *puVar1;
  longlong lVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  undefined *puVar6;
  
  if ((*(int *)(param_3 + 8) == 5) && (*(int *)(param_3 + 0xc) == 1)) {
    lVar2 = *(longlong *)(param_3 + 0x10);
    puVar1 = (uint *)(lVar2 + 0xc);
    if ((*(int *)(lVar2 + 8) - 7U < 8) && (*puVar1 < 2)) {
      *param_4 = *(undefined1 *)(lVar2 + 0x10);
      return 0;
    }
    puVar3 = WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      puVar3 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      WPP_SF_dd(puVar3,0xd,&WPP_0fcae427bce03ba20eb03603e1248831_Traceguids,*(int *)(lVar2 + 8),
                (char)*puVar1);
    }
    uVar4 = 2;
    uVar5 = (undefined1)*(undefined4 *)(lVar2 + 8);
    puVar6 = (undefined *)(ulonglong)*puVar1;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                &WPP_0fcae427bce03ba20eb03603e1248831_Traceguids,_DAT_00000008,(char)_DAT_0000000c);
    }
    puVar3 = (undefined *)(ulonglong)_DAT_0000000c;
    uVar4 = 1;
    uVar5 = (undefined1)_DAT_00000008;
    puVar6 = puVar3;
  }
  TcglibEalLogError(puVar3,"ErrInvalidBoolData",uVar4,uVar5,(char)puVar6,0);
  return 0xc0000185;
}



===== ParseSyncSessionData @ 1400110c0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 ParseSyncSessionData(undefined8 *param_1,longlong param_2,longlong param_3)

{
  uint *_Dst;
  longlong lVar1;
  undefined *puVar2;
  undefined8 *_Src;
  undefined8 uVar3;
  undefined1 uVar4;
  undefined *puVar5;
  
  if ((*(int *)(param_3 + 8) == 5) && (1 < *(uint *)(param_3 + 0xc))) {
    lVar1 = **(longlong **)(param_3 + 0x10);
    if (*(uint *)(lVar1 + 0xc) < 5) {
      _Dst = (uint *)(param_2 + 8);
      _Src = (undefined8 *)0x0;
      *_Dst = 0;
      if ((*(int *)(lVar1 + 8) - 7U < 0xb) &&
         (_Src = (undefined8 *)(lVar1 + 0x10), 8 < *(uint *)(lVar1 + 0xc))) {
        _Src = (undefined8 *)*_Src;
      }
      memmove(_Dst,_Src,(ulonglong)*(uint *)(lVar1 + 0xc));
      TcglibEalLogCommand(*param_1,"ParseSyncSessionData",(ulonglong)*_Dst,0,0,0);
      return 0;
    }
    puVar2 = WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      puVar2 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      WPP_SF_D(puVar2,0xb,&WPP_0fcae427bce03ba20eb03603e1248831_Traceguids,*(uint *)(lVar1 + 0xc));
    }
    uVar3 = 2;
    uVar4 = (undefined1)*(undefined4 *)(lVar1 + 0xc);
    puVar5 = (undefined *)0x0;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                &WPP_0fcae427bce03ba20eb03603e1248831_Traceguids,_DAT_00000008,(char)_DAT_0000000c);
    }
    puVar2 = (undefined *)(ulonglong)_DAT_0000000c;
    uVar3 = 1;
    uVar4 = (undefined1)_DAT_00000008;
    puVar5 = puVar2;
  }
  TcglibEalLogError(puVar2,"ErrInvalidSyncData",uVar3,uVar4,(char)puVar5,0);
  return 0xc0000185;
}



===== ParseTPerProperties @ 140011220 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong ParseTPerProperties(longlong param_1,undefined8 param_2,longlong param_3,uint *param_4)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  int iVar5;
  ulonglong uVar6;
  undefined *puVar7;
  undefined2 uVar8;
  longlong *_Src;
  uint uVar9;
  undefined8 uVar10;
  undefined1 uVar11;
  uint uVar12;
  undefined8 *puVar13;
  undefined1 auStackY_a8 [32];
  undefined *puVar14;
  uint local_78;
  uint local_74;
  char local_68 [40];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_74 = 0;
  if ((*(int *)(param_3 + 8) == 5) && (*(int *)(param_3 + 0xc) == 1)) {
    lVar1 = *(longlong *)(param_3 + 0x10);
    if (*(int *)(lVar1 + 8) == 5) {
      local_78 = 0;
      puVar13 = *(undefined8 **)(lVar1 + 0x10);
      if (*(int *)(lVar1 + 0xc) != 0) {
        do {
          if (puVar13 == (undefined8 *)0x0) break;
          if (((*(int *)(puVar13 + 1) == 6) && (*(int *)((longlong)puVar13 + 0xc) == 2)) &&
             (plVar2 = (longlong *)puVar13[2], plVar2 != (longlong *)0x0)) {
            uVar12 = *(uint *)((longlong)plVar2 + 0xc);
            lVar3 = *plVar2;
            if ((uVar12 < 0x21) && (*(uint *)(lVar3 + 0xc) < 5)) {
              _Src = (longlong *)0x0;
              if (((int)plVar2[1] - 7U < 0xb) && (_Src = plVar2 + 2, 8 < uVar12)) {
                _Src = (longlong *)*_Src;
              }
              memmove(local_68,_Src,(ulonglong)uVar12);
              if (0x20 < (ulonglong)*(uint *)((longlong)plVar2 + 0xc)) {
                __report_rangecheckfailure();
                pcVar4 = (code *)swi(3);
                uVar6 = (*pcVar4)();
                return uVar6;
              }
              local_68[*(uint *)((longlong)plVar2 + 0xc)] = '\0';
              iVar5 = _stricmp(local_68,"MaxComPacketSize");
              if (iVar5 == 0) {
                uVar12 = *(uint *)(lVar3 + 0x10);
                *param_4 = uVar12;
                uVar9 = 0x10000;
                if (uVar12 < 0x10000) {
                  uVar9 = uVar12;
                }
                *(uint *)(param_1 + 0x2c) = uVar9;
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                  WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                            &WPP_0fcae427bce03ba20eb03603e1248831_Traceguids,*param_4,(char)uVar9);
                }
              }
              else {
                iVar5 = _stricmp(local_68,"MaxResponseComPacketSize");
                if (iVar5 == 0) {
                  uVar12 = *(uint *)(lVar3 + 0x10);
                  param_4[1] = uVar12;
                  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                             &WPP_0fcae427bce03ba20eb03603e1248831_Traceguids,uVar12);
                  }
                  if ((((*param_4 != 0) && (*param_4 < param_4[1])) &&
                      ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
                     (2 < (byte)WPP_GLOBAL_Control[0x29])) {
                    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                            &WPP_0fcae427bce03ba20eb03603e1248831_Traceguids);
                  }
                }
                else {
                  iVar5 = _stricmp(local_68,"MaxPacketSize");
                  if (iVar5 == 0) {
                    uVar12 = *(uint *)(lVar3 + 0x10);
                    param_4[2] = uVar12;
                    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                      uVar8 = 0x13;
LAB_1400116b5:
                      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                               &WPP_0fcae427bce03ba20eb03603e1248831_Traceguids,uVar12);
                    }
                  }
                  else {
                    iVar5 = _stricmp(local_68,"MaxIndTokenSize");
                    if (iVar5 == 0) {
                      uVar12 = *(uint *)(lVar3 + 0x10);
                      param_4[3] = uVar12;
                      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                        uVar8 = 0x14;
                        goto LAB_1400116b5;
                      }
                    }
                    else {
                      iVar5 = _stricmp(local_68,"MaxPackets");
                      if (iVar5 == 0) {
                        uVar12 = *(uint *)(lVar3 + 0x10);
                        param_4[4] = uVar12;
                        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                          uVar8 = 0x15;
                          goto LAB_1400116b5;
                        }
                      }
                      else {
                        iVar5 = _stricmp(local_68,"MaxSubpackets");
                        if (iVar5 == 0) {
                          uVar12 = *(uint *)(lVar3 + 0x10);
                          param_4[5] = uVar12;
                          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                            uVar8 = 0x16;
                            goto LAB_1400116b5;
                          }
                        }
                        else {
                          iVar5 = _stricmp(local_68,"MaxMethods");
                          if (iVar5 == 0) {
                            uVar12 = *(uint *)(lVar3 + 0x10);
                            param_4[6] = uVar12;
                            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                              uVar8 = 0x17;
                              goto LAB_1400116b5;
                            }
                          }
                          else {
                            iVar5 = _stricmp(local_68,"MaxSessions");
                            if (iVar5 == 0) {
                              uVar12 = *(uint *)(lVar3 + 0x10);
                              param_4[7] = uVar12;
                              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                                 (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                                uVar8 = 0x18;
                                goto LAB_1400116b5;
                              }
                            }
                            else {
                              iVar5 = _stricmp(local_68,"MaxAuthentications");
                              if (iVar5 == 0) {
                                uVar12 = *(uint *)(lVar3 + 0x10);
                                param_4[8] = uVar12;
                                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                                   (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                                  uVar8 = 0x19;
                                  goto LAB_1400116b5;
                                }
                              }
                              else {
                                iVar5 = _stricmp(local_68,"MaxTransactionLimit");
                                if (iVar5 == 0) {
                                  uVar12 = *(uint *)(lVar3 + 0x10);
                                  param_4[9] = uVar12;
                                  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                                     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                                    uVar8 = 0x1a;
                                    goto LAB_1400116b5;
                                  }
                                }
                                else {
                                  iVar5 = _stricmp(local_68,"DefSessionTimeout");
                                  if (iVar5 == 0) {
                                    uVar12 = *(uint *)(lVar3 + 0x10);
                                    param_4[10] = uVar12;
                                    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                                       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                                      uVar8 = 0x1b;
                                      goto LAB_1400116b5;
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
          }
          puVar13 = (undefined8 *)*puVar13;
          local_78 = local_78 + 1;
        } while (local_78 < *(uint *)(lVar1 + 0xc));
      }
      goto LAB_14001174d;
    }
    puVar7 = WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      puVar7 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      WPP_SF_dd(puVar7,0xf,&WPP_0fcae427bce03ba20eb03603e1248831_Traceguids,*(int *)(lVar1 + 8),
                (char)*(undefined4 *)(lVar1 + 0xc));
    }
    uVar10 = 2;
    uVar11 = (undefined1)*(undefined4 *)(lVar1 + 8);
    puVar14 = (undefined *)(ulonglong)*(uint *)(lVar1 + 0xc);
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                &WPP_0fcae427bce03ba20eb03603e1248831_Traceguids,_DAT_00000008,(char)_DAT_0000000c);
    }
    puVar7 = (undefined *)(ulonglong)_DAT_0000000c;
    uVar10 = 1;
    uVar11 = (undefined1)_DAT_00000008;
    puVar14 = puVar7;
  }
  local_74 = 0xc0000185;
  TcglibEalLogError(puVar7,"ErrInvalidTPerProp",uVar10,uVar11,(char)puVar14,0);
LAB_14001174d:
  return (ulonglong)local_74;
}



===== TcglibpAuthenticateSession @ 140011784 =====

ulonglong TcglibpAuthenticateSession
                    (undefined8 *param_1,longlong param_2,undefined8 param_3,uint *param_4)

{
  ulonglong uVar1;
  char local_res20 [8];
  undefined8 local_18;
  uint *local_10;
  
  local_res20[0] = '\0';
  if (*param_4 < 0x21) {
    local_18 = param_3;
    local_10 = param_4;
    TcglibEalLogCommand(*param_1,"AuthenticateSession",1,0x60000001c,param_3,0);
    uVar1 = TcglibpCallMethod(param_1,param_2,1,0x60000001c,GenAuthenticateParams,&local_18,0,0,
                              ParseBooleanData,local_res20);
    if (-1 < (int)uVar1) {
      uVar1 = (ulonglong)(~-(uint)(local_res20[0] != '\0') & 0xc0000022);
    }
  }
  else {
    uVar1 = 0xc000000d;
  }
  return uVar1;
}



===== TcglibpCloseSession @ 140011864 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong TcglibpCloseSession(undefined8 *param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  int iVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  longlong *plVar9;
  char *pcVar10;
  ulonglong uVar11;
  uint local_res8 [2];
  undefined8 *local_res10;
  longlong *local_res18;
  longlong local_res20;
  longlong local_58 [3];
  
  lVar1 = *(longlong *)(param_2 + 0x28);
  lVar2 = *(longlong *)(param_2 + 0x30);
  uVar3 = *param_1;
  local_res10 = (undefined8 *)0x0;
  uVar11 = 0;
  local_res8[0] = 0;
  if ((lVar1 == 0) || (lVar2 == 0)) goto LAB_140011a4f;
  local_res20 = lVar2;
  local_58[0] = lVar1;
  TcglibEalGetCommandPayload(uVar3,lVar1,(longlong *)&local_res10,local_res8);
  puVar4 = local_res10;
  *(undefined1 *)(local_res10 + 7) = 0xfa;
  uVar7 = GenTCGHeaders(local_res10,local_res8[0],param_2,1,*(undefined4 *)(param_2 + 8),
                        *(undefined4 *)(param_2 + 4));
  uVar11 = uVar7 & 0xffffffff;
  if (-1 < (int)uVar7) {
    iVar5 = TcglibReverseUInt32(*(undefined4 *)(puVar4 + 2));
    uVar8 = uVar3;
    uVar6 = TcglibpExecuteCommand(uVar3,lVar1,iVar5 + 0x14,'\0');
    uVar11 = (ulonglong)(int)uVar6;
    if ((int)uVar6 < 0) {
      pcVar10 = "CloseSession-SEND failed";
    }
    else {
      uVar8 = uVar3;
      uVar6 = TcglibpExecuteCommand(uVar3,lVar2,0,'\x01');
      uVar11 = (ulonglong)(int)uVar6;
      if (-1 < (int)uVar6) {
        LOCK();
        _OpenSessionCount = _OpenSessionCount + -1;
        UNLOCK();
        TcglibEalLogCommand(uVar3,"CloseSession success",(ulonglong)*(uint *)(param_2 + 8),0,0,0);
        TcglibEalGetCommandPayload(uVar3,local_res20,(longlong *)&local_res10,local_res8);
        uVar8 = InitTcgParser((longlong)param_1,(longlong)local_res10,(ulonglong)local_res8[0]);
        if ((int)uVar8 == 0) {
          plVar9 = param_1 + 7;
          local_res18 = (longlong *)0x0;
          uVar11 = ParseToken(plVar9,(longlong *)&local_res18);
          iVar5 = (int)uVar11;
          if ((iVar5 < 0) || (plVar9 = local_res18, (int)local_res18[1] == 3)) {
            uVar11 = uVar11 & 0xffffffff;
            if (-1 < iVar5) goto LAB_140011a2c;
          }
          else {
            plVar9 = (longlong *)WPP_GLOBAL_Control;
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              plVar9 = *(longlong **)(WPP_GLOBAL_Control + 0x18);
              WPP_SF_D(plVar9,0x18,&WPP_d27db7d0d3983550ea60457830c64ea4_Traceguids,
                       (int)local_res18[1]);
            }
            uVar11 = 0xc0000185;
            iVar5 = -0x3ffffe7b;
          }
          TcglibEalLogError(plVar9,"CloseSession-ParseTcgEndSession failed",(longlong)iVar5,0,0,0);
        }
LAB_140011a2c:
        LOCK();
        *(undefined4 *)((longlong)param_1 + 0x34) = 0;
        UNLOCK();
        goto LAB_140011a37;
      }
      pcVar10 = "CloseSession-RECV failed";
    }
    TcglibEalLogError(uVar8,pcVar10,uVar11,(char)*(undefined4 *)(param_2 + 8),0,0);
  }
LAB_140011a37:
  TcglibpReleaseRequestResources(uVar3,local_58,&local_res20);
  *(undefined8 *)(param_2 + 0x28) = 0;
  *(undefined8 *)(param_2 + 0x30) = 0;
LAB_140011a4f:
  *(undefined8 *)(param_2 + 4) = 0;
  *(undefined8 *)(param_2 + 0x10) = 0;
  *(undefined2 *)(param_2 + 0x18) = 0;
  return uVar11 & 0xffffffff;
}



===== TcglibpGetTPerProperties @ 140011a78 =====

uint TcglibpGetTPerProperties(undefined8 *param_1,longlong param_2,undefined8 *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  short sVar3;
  
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  param_3[4] = 0;
  *(undefined4 *)(param_3 + 5) = 0;
  sVar3 = *(short *)(param_2 + 0x18);
  if (sVar3 == 0) {
    sVar3 = *(short *)((longlong)param_1 + 0x1c);
    *(short *)(param_2 + 0x18) = sVar3;
  }
  uVar1 = TcglibpAllocateRequestResources
                    (*param_1,'\x01',sVar3,0x800,(longlong *)(param_2 + 0x28),
                     (longlong *)(param_2 + 0x30));
  if (-1 < (int)uVar1) {
    TcglibEalLogCommand(*param_1,"GetTPerProperties",0xff,0xff01,0,0);
    uVar2 = TcglibpCallMethod(param_1,param_2,0xff,0xff01,(undefined *)0x0,0,0xff,0xff01,
                              ParseTPerProperties,param_3);
    uVar1 = (uint)uVar2;
  }
  TcglibpReleaseRequestResources(*param_1,(longlong *)(param_2 + 0x28),(longlong *)(param_2 + 0x30))
  ;
  return uVar1;
}



===== TcglibpOpenSession @ 140011b8c =====

uint TcglibpOpenSession(undefined8 *param_1,longlong param_2)

{
  short *psVar1;
  longlong *plVar2;
  longlong *plVar3;
  uint uVar4;
  ulonglong uVar5;
  short sVar6;
  uint local_res8 [2];
  
  local_res8[0] = *(uint *)((longlong)param_1 + 0x2c);
  psVar1 = (short *)(param_2 + 0x18);
  sVar6 = *psVar1;
  if (sVar6 == 0) {
    sVar6 = *(short *)((longlong)param_1 + 0x1c);
    *psVar1 = sVar6;
  }
  plVar2 = (longlong *)(param_2 + 0x30);
  plVar3 = (longlong *)(param_2 + 0x28);
  uVar4 = TcglibpAllocateRequestResources(*param_1,'\x01',sVar6,0x800,plVar3,plVar2);
  if (-1 < (int)uVar4) {
    TcglibEalLogCommand(*param_1,"SetMaxPacketSize",0xff,0x600000017,(ulonglong)local_res8[0],0);
    uVar5 = TcglibpCallMethod(param_1,param_2,0xff,0xff01,GenSetTPerPropertiesParams,local_res8,0xff
                              ,0xff01,(undefined *)0x0,0);
    uVar4 = (uint)uVar5;
  }
  TcglibpReleaseRequestResources(*param_1,plVar3,plVar2);
  if (-1 < (int)uVar4) {
    sVar6 = *psVar1;
    if (sVar6 == 0) {
      sVar6 = *(short *)((longlong)param_1 + 0x1c);
      *(short *)(param_2 + 0x18) = sVar6;
    }
    uVar4 = TcglibpAllocateRequestResources(*param_1,'\x01',sVar6,0x800,plVar3,plVar2);
    if (-1 < (int)uVar4) {
      TcglibEalLogCommand(*param_1,"OpenSession",0xff,0xff02,*(undefined8 *)(param_2 + 0x10),0);
      uVar5 = TcglibpCallMethod(param_1,param_2,0xff,0xff02,GenStartSessionParams,0,0xff,0xff03,
                                ParseSyncSessionData,0);
      uVar4 = (uint)uVar5;
    }
  }
  if ((int)uVar4 < 0) {
    TcglibpReleaseRequestResources
              (*param_1,(longlong *)(param_2 + 0x28),(longlong *)(param_2 + 0x30));
    *(undefined8 *)(param_2 + 4) = 0;
    *(undefined8 *)(param_2 + 0x10) = 0;
    *(short *)(param_2 + 0x18) = 0;
  }
  else {
    TcglibpReinitRequestResources
              (*param_1,*(longlong *)(param_2 + 0x28),*(longlong *)(param_2 + 0x30));
  }
  return uVar4;
}



===== TcglibpOpenSessionWithRetry @ 140011da4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint TcglibpOpenSessionWithRetry(undefined8 *param_1,undefined8 *param_2,undefined8 param_3)

{
  bool bVar1;
  uint uVar2;
  undefined8 *puVar3;
  
  bVar1 = false;
  do {
    while( true ) {
      *param_2 = 0;
      param_2[1] = 0;
      param_2[2] = 0;
      param_2[3] = 0;
      param_2[4] = 0;
      param_2[5] = 0;
      param_2[6] = 0;
      *(undefined4 *)param_2 = 1;
      *(undefined2 *)(param_2 + 3) = *(undefined2 *)((longlong)param_1 + 0x1c);
      *(undefined4 *)((longlong)param_2 + 4) = *(undefined4 *)(param_1 + 3);
      param_2[2] = param_3;
      param_1[2] = param_2;
      *(undefined4 *)param_2 = 2;
      uVar2 = TcglibpOpenSession(param_1,(longlong)param_2);
      if (-1 < (int)uVar2) {
        LOCK();
        _OpenSessionCount = _OpenSessionCount + 1;
        UNLOCK();
        return uVar2;
      }
      puVar3 = param_1;
      uVar2 = TcglibpCheckError(param_1,(undefined4 *)param_2,uVar2);
      param_1[2] = 0;
      if (uVar2 != 0xc0000203) break;
LAB_140011e62:
      if (bVar1) {
        return uVar2;
      }
      bVar1 = true;
    }
    if (uVar2 == 0x80000011) {
      TcglibEalLogError(puVar3,"TcglibpOpenSession-failed with device busy",param_3,!bVar1,0,0);
      TcglibStackReset(param_1,(longlong)param_2);
      goto LAB_140011e62;
    }
    if (!bVar1) {
      return uVar2;
    }
  } while( true );
}



===== TcglibpTransaction @ 140011ea4 =====

ulonglong TcglibpTransaction(undefined8 *param_1,longlong param_2,char param_3,char param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  int iVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  char *pcVar9;
  uint local_res8 [2];
  undefined8 *local_res10;
  
  lVar1 = *(longlong *)(param_2 + 0x28);
  uVar2 = *param_1;
  lVar3 = *(longlong *)(param_2 + 0x30);
  local_res10 = (undefined8 *)0x0;
  local_res8[0] = 0;
  uVar7 = TcglibEalGetCommandPayload(uVar2,lVar1,(longlong *)&local_res10,local_res8);
  puVar4 = local_res10;
  if (-1 < (int)uVar7) {
    *(char *)(local_res10 + 7) = -4 - (param_3 != '\0');
    *(bool *)((longlong)local_res10 + 0x39) = param_3 == '\0' && param_4 != '\0';
    uVar7 = GenTCGHeaders(local_res10,local_res8[0],param_2,2,*(undefined4 *)(param_2 + 8),
                          *(undefined4 *)(param_2 + 4));
    if (-1 < (int)uVar7) {
      iVar5 = TcglibReverseUInt32(*(undefined4 *)(puVar4 + 2));
      uVar6 = TcglibpExecuteCommand(uVar2,lVar1,iVar5 + 0x14,'\0');
      uVar7 = (ulonglong)uVar6;
      if (-1 < (int)uVar6) {
        pcVar9 = "StartTransaction";
        if (param_3 == '\0') {
          pcVar9 = "EndTransaction";
        }
        TcglibEalLogCommand(uVar2,pcVar9,0,0,0,0);
        uVar6 = TcglibpExecuteCommand(uVar2,lVar3,0,'\x01');
        uVar7 = (ulonglong)uVar6;
        if (-1 < (int)uVar6) {
          TcglibEalGetCommandPayload(uVar2,lVar3,(longlong *)&local_res10,local_res8);
          uVar8 = InitTcgParser((longlong)param_1,(longlong)local_res10,(ulonglong)local_res8[0]);
          if ((int)uVar8 == 0) {
            uVar7 = ParseTcgTransactionStatus((longlong)param_1);
            uVar7 = uVar7 & 0xffffffff;
          }
          LOCK();
          *(undefined4 *)((longlong)param_1 + 0x34) = 0;
          UNLOCK();
        }
      }
      goto LAB_140012016;
    }
  }
  uVar7 = uVar7 & 0xffffffff;
LAB_140012016:
  TcglibpReinitRequestResources(uVar2,lVar1,lVar3);
  return uVar7;
}



===== InitTcgParser @ 140012048 =====

undefined8 InitTcgParser(longlong param_1,longlong param_2,ulonglong param_3)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  undefined2 uVar6;
  ulonglong uVar7;
  bool bVar8;
  
  uVar5 = (uint)param_3;
  LOCK();
  bVar8 = *(int *)(param_1 + 0x34) == 0;
  if (bVar8) {
    *(int *)(param_1 + 0x34) = 1;
  }
  UNLOCK();
  if (!bVar8) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000708;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc0000708;
    }
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_d27db7d0d3983550ea60457830c64ea4_Traceguids);
    return 0xc0000708;
  }
  if (uVar5 < 0x14) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000185;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc0000185;
    }
    uVar6 = 0xb;
    cVar1 = '\x14';
  }
  else {
    uVar7 = param_3;
    uVar4 = TcglibReverseUInt32(*(undefined4 *)(param_2 + 0x10));
    if ((uVar4 < 0x18) || ((param_3 & 0xffffffff) < (ulonglong)uVar4 + 0x14)) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc0000185;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return 0xc0000185;
      }
      cVar1 = (char)param_3 + -0x14;
      uVar6 = 0xc;
      goto LAB_140012266;
    }
    uVar5 = TcglibReverseUInt32(*(undefined4 *)(param_2 + 0x28));
    if ((0xb < uVar5) && ((ulonglong)uVar5 + 0x18 <= (ulonglong)uVar4)) {
      uVar4 = TcglibReverseUInt32(*(undefined4 *)(param_2 + 0x34));
      if ((ulonglong)uVar4 + 0xc <= (ulonglong)uVar5) {
        uVar2 = TcglibReverseUInt16(*(undefined2 *)(param_2 + 4));
        uVar3 = TcglibReverseUInt16(*(undefined2 *)(param_2 + 0x32));
        if ((uVar2 == *(ushort *)(param_1 + 0x1c)) && (uVar3 == 0)) {
          memset((void *)(param_1 + 0x44),0,0x181c);
          *(longlong *)(param_1 + 0x38) = param_2 + 0x38;
          *(uint *)(param_1 + 0x40) = uVar4;
          return 0;
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0xc0000185;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
          return 0xc0000185;
        }
        WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)uVar3,uVar7,(uint)uVar2,
                  (char)uVar3);
        return 0xc0000185;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc0000185;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return 0xc0000185;
      }
      cVar1 = (char)uVar5 + -0xc;
      uVar6 = 0xe;
      goto LAB_140012266;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000185;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc0000185;
    }
    cVar1 = (char)uVar4 + -0x18;
    uVar6 = 0xd;
  }
  uVar4 = uVar5;
LAB_140012266:
  WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
            &WPP_d27db7d0d3983550ea60457830c64ea4_Traceguids,uVar4,cVar1);
  return 0xc0000185;
}



===== ParseMethod @ 1400122a0 =====

undefined8 ParseMethod(longlong *param_1,longlong param_2)

{
  undefined1 uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined2 uVar4;
  longlong *plVar5;
  int iVar6;
  
  *(undefined4 *)(param_2 + 0xc) = 0;
  uVar2 = ParseToken(param_1,(longlong *)(param_2 + 0x10));
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + 1;
  plVar5 = *(longlong **)(param_2 + 0x10);
  iVar6 = (int)plVar5[1];
  if ((iVar6 == 0xf) && (*(int *)((longlong)plVar5 + 0xc) == 8)) {
    uVar2 = ParseToken(param_1,plVar5);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + 1;
    plVar5 = (longlong *)*plVar5;
    iVar6 = (int)plVar5[1];
    if ((iVar6 == 0xf) && (*(int *)((longlong)plVar5 + 0xc) == 8)) {
      uVar2 = ParseToken(param_1,plVar5);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + 1;
      iVar6 = *(int *)(*plVar5 + 8);
      if (iVar6 == 5) {
        return uVar2;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc0000185;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return 0xc0000185;
      }
      uVar1 = (undefined1)*(undefined4 *)(*plVar5 + 0xc);
      uVar4 = 0x21;
      uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      goto LAB_1400123a8;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000185;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc0000185;
    }
    uVar4 = 0x20;
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000185;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc0000185;
    }
    uVar4 = 0x1f;
  }
  uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
  uVar1 = (undefined1)*(undefined4 *)((longlong)plVar5 + 0xc);
LAB_1400123a8:
  WPP_SF_dd(uVar3,uVar4,&WPP_d27db7d0d3983550ea60457830c64ea4_Traceguids,iVar6,uVar1);
  return 0xc0000185;
}



===== ParseNamedData @ 1400123d4 =====

undefined8 ParseNamedData(longlong *param_1,longlong param_2)

{
  longlong *plVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  byte local_res10 [8];
  int local_res18 [2];
  
  *(undefined4 *)(param_2 + 0xc) = 0;
  plVar1 = (longlong *)(param_2 + 0x10);
  uVar2 = ParseToken(param_1,plVar1);
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + 1;
  if (*(int *)(*plVar1 + 8) - 7U < 0xb) {
    uVar2 = ParseToken(param_1,(longlong *)*plVar1);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + 1;
    local_res18[0] = 0;
    local_res10[0] = 0;
    uVar3 = PeekTokenInfo(param_1,local_res10,local_res18);
    if ((int)uVar3 < 0) {
      return uVar3;
    }
    if (local_res10[0] == 0xf3) {
      *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + 1;
      return uVar3;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
                &WPP_d27db7d0d3983550ea60457830c64ea4_Traceguids,(uint)local_res10[0],
                (char)local_res18[0]);
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
             &WPP_d27db7d0d3983550ea60457830c64ea4_Traceguids,*(int *)(*plVar1 + 8));
  }
  return 0xc0000185;
}



===== ParseTcgMethodData @ 1400124e4 =====

undefined8
ParseTcgMethodData(longlong param_1,undefined8 param_2,undefined8 param_3,longlong *param_4)

{
  longlong lVar1;
  undefined2 uVar2;
  longlong *plVar3;
  undefined8 local_res8;
  
  lVar1 = *(longlong *)(param_1 + 0x48);
  if ((*(int *)(lVar1 + 8) != 4) || (*(int *)(lVar1 + 0xc) != 3)) {
LAB_1400125bb:
    if (*(int *)(lVar1 + 8) == 5) {
      if (param_4 == (longlong *)0x0) {
        return 0;
      }
      *param_4 = lVar1;
      return 0;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000185;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc0000185;
    }
    WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
              &WPP_d27db7d0d3983550ea60457830c64ea4_Traceguids,*(int *)(lVar1 + 8),
              (char)*(undefined4 *)(lVar1 + 0xc));
    return 0xc0000185;
  }
  plVar3 = *(longlong **)(lVar1 + 0x10);
  local_res8 = param_2;
  TcglibReverseBytes((undefined1 *)&local_res8,8);
  if (((int)plVar3[1] == 0xf) &&
     ((*(int *)((longlong)plVar3 + 0xc) == 8 &&
      (lVar1 = RtlCompareMemory(plVar3 + 2,&local_res8,8), lVar1 == 8)))) {
    plVar3 = (longlong *)*plVar3;
    local_res8 = param_3;
    TcglibReverseBytes((undefined1 *)&local_res8,8);
    if ((*(int *)(plVar3 + 1) == 0xf) &&
       ((*(int *)((longlong)plVar3 + 0xc) == 8 &&
        (lVar1 = RtlCompareMemory(plVar3 + 2,&local_res8,8), lVar1 == 8)))) {
      lVar1 = *plVar3;
      goto LAB_1400125bb;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000185;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc0000185;
    }
    uVar2 = 0x1a;
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000185;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc0000185;
    }
    uVar2 = 0x19;
  }
  WPP_SF_ii(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
            &WPP_d27db7d0d3983550ea60457830c64ea4_Traceguids,plVar3[2],(char)local_res8);
  return 0xc0000185;
}



===== ParseTcgPayloadStatus @ 140012694 =====

ulonglong ParseTcgPayloadStatus(undefined8 *param_1)

{
  byte bVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined2 uVar4;
  ulonglong uVar5;
  uint uVar6;
  int iVar7;
  undefined8 *puVar8;
  
  uVar3 = ParseToken(param_1 + 7,param_1 + 10);
  uVar5 = uVar3 & 0xffffffff;
  if ((int)uVar3 < 0) {
    return uVar5;
  }
  lVar2 = param_1[10];
  iVar7 = *(int *)(lVar2 + 8);
  if (iVar7 == 5) {
    iVar7 = *(int *)(lVar2 + 0xc);
    if (iVar7 == 3) {
      puVar8 = *(undefined8 **)(lVar2 + 0x10);
      uVar6 = 0;
      do {
        if (2 < uVar6) goto LAB_1400127c7;
        if (puVar8 == (undefined8 *)0x0) break;
        if (*(int *)(puVar8 + 1) == 8) {
          if (uVar6 == 0) {
            bVar1 = *(byte *)(puVar8 + 2);
            *(byte *)(param_1 + 0xb) = bVar1;
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                       &WPP_d27db7d0d3983550ea60457830c64ea4_Traceguids,(uint)bVar1);
            }
          }
        }
        else {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                     &WPP_d27db7d0d3983550ea60457830c64ea4_Traceguids,*(int *)(puVar8 + 1));
          }
          uVar5 = 0xc0000185;
        }
        puVar8 = (undefined8 *)*puVar8;
        uVar6 = uVar6 + 1;
      } while (-1 < (int)uVar5);
      if ((int)uVar5 < 0) {
        return uVar5;
      }
LAB_1400127c7:
      if (*(byte *)(param_1 + 0xb) == 0) {
        return uVar5;
      }
      uVar6 = TcglibpMapStatus(param_1,*(byte *)(param_1 + 0xb));
      uVar3 = (ulonglong)uVar6;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return uVar3;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return uVar3;
      }
      WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                &WPP_d27db7d0d3983550ea60457830c64ea4_Traceguids,(uint)*(byte *)(param_1 + 0xb),
                (char)uVar6);
      return uVar3;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000185;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc0000185;
    }
    uVar4 = 0x12;
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000185;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc0000185;
    }
    uVar4 = 0x11;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
           &WPP_d27db7d0d3983550ea60457830c64ea4_Traceguids,iVar7);
  return 0xc0000185;
}



===== ParseTcgTransactionStatus @ 14001282c =====

ulonglong ParseTcgTransactionStatus(longlong param_1)

{
  ulonglong uVar1;
  longlong local_res8 [4];
  
  local_res8[0] = 0;
  uVar1 = ParseToken((longlong *)(param_1 + 0x38),local_res8);
  if ((int)uVar1 < 0) {
    return uVar1 & 0xffffffff;
  }
  if (*(int *)(local_res8[0] + 8) == 2) {
    uVar1 = ParseToken((longlong *)(param_1 + 0x38),local_res8);
    if ((int)uVar1 < 0) {
      return uVar1 & 0xffffffff;
    }
    if ((*(int *)(local_res8[0] + 8) - 7U < 8) && (*(uint *)(local_res8[0] + 0xc) < 2)) {
      if (*(longlong *)(local_res8[0] + 0x10) == 1) {
        return 0xc000020f;
      }
      return uVar1 & 0xffffffff;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                &WPP_d27db7d0d3983550ea60457830c64ea4_Traceguids,*(int *)(local_res8[0] + 8),
                (char)*(undefined4 *)(local_res8[0] + 0xc));
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
             &WPP_d27db7d0d3983550ea60457830c64ea4_Traceguids,*(int *)(local_res8[0] + 8));
  }
  return 0xc0000185;
}



===== ParseToken @ 140012920 =====

ulonglong ParseToken(longlong *param_1,longlong *param_2)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong *plVar5;
  undefined2 uVar6;
  ulonglong uVar7;
  byte local_res18 [8];
  uint local_res20 [2];
  
  local_res20[0] = 0;
  local_res18[0] = 0;
  while( true ) {
    uVar3 = PeekTokenInfo(param_1,local_res18,(int *)local_res20);
    uVar7 = uVar3 & 0xffffffff;
    if ((int)uVar3 != 0) break;
    if (local_res18[0] != 0xff) goto LAB_14001296f;
    *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + 1;
  }
  if ((int)uVar3 < 0) {
    return uVar7;
  }
LAB_14001296f:
  if (local_res20[0] < 2) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000185;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc0000185;
    }
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
             &WPP_d27db7d0d3983550ea60457830c64ea4_Traceguids,(uint)local_res18[0]);
    return 0xc0000185;
  }
  *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + 1;
  plVar5 = (longlong *)0x0;
  uVar2 = *(uint *)((longlong)param_1 + 0x24);
  if (uVar2 < 0x100) {
    *(uint *)((longlong)param_1 + 0x24) = uVar2 + 1;
    plVar5 = param_1 + (ulonglong)uVar2 * 3 + 5;
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
            &WPP_d27db7d0d3983550ea60457830c64ea4_Traceguids);
    *param_2 = 0;
    return 0xc000009a;
  }
  *param_2 = (longlong)plVar5;
  if (plVar5 == (longlong *)0x0) {
    return 0xc000009a;
  }
  *(uint *)(plVar5 + 1) = local_res20[0];
  if ((int)local_res20[0] < 0xc) {
    if (local_res20[0] == 0xb) goto LAB_140012b68;
    if (local_res20[0] == 4) {
      uVar4 = ParseMethod(param_1,*param_2);
      uVar2 = (uint)uVar4;
      goto LAB_140012b99;
    }
    if (local_res20[0] == 5) {
      lVar1 = *param_2;
      local_res20[0] = 0;
      local_res18[0] = 0;
      *(undefined4 *)(lVar1 + 0xc) = 0;
      plVar5 = (longlong *)(lVar1 + 0x10);
      while( true ) {
        uVar3 = PeekTokenInfo(param_1,local_res18,(int *)local_res20);
        if ((int)uVar3 != 0) break;
        if (local_res18[0] == 0xf1) goto LAB_140012ab9;
        uVar3 = ParseToken(param_1,plVar5);
        if ((int)uVar3 < 0) {
          return uVar3 & 0xffffffff;
        }
        *(int *)(lVar1 + 0xc) = *(int *)(lVar1 + 0xc) + 1;
        plVar5 = (longlong *)*plVar5;
      }
      if ((int)uVar3 < 0) {
        return uVar3 & 0xffffffff;
      }
LAB_140012ab9:
      *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + 1;
      return uVar3 & 0xffffffff;
    }
    if (local_res20[0] == 6) {
      uVar4 = ParseNamedData(param_1,*param_2);
      uVar2 = (uint)uVar4;
      goto LAB_140012b99;
    }
    if ((local_res20[0] == 7) || (local_res20[0] == 8)) {
      *(undefined4 *)(*param_2 + 0xc) = 1;
      *(byte *)(*param_2 + 0x10) = local_res18[0] & 0x3f;
      return uVar7;
    }
    if ((local_res20[0] != 9) && (local_res20[0] != 10)) {
      return uVar7;
    }
LAB_140012a27:
    *(uint *)(*param_2 + 0xc) = local_res18[0] & 0xf;
  }
  else if (local_res20[0] == 0xc) {
LAB_140012b68:
    if (*(uint *)(param_1 + 1) <= *(uint *)((longlong)param_1 + 0xc)) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc0000185;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return 0xc0000185;
      }
      uVar6 = 0x1d;
LAB_140012b56:
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
              &WPP_d27db7d0d3983550ea60457830c64ea4_Traceguids);
      return 0xc0000185;
    }
    *(uint *)(*param_2 + 0xc) =
         (uint)*(byte *)((ulonglong)*(uint *)((longlong)param_1 + 0xc) + *param_1) +
         (local_res18[0] & 7) * 0x100;
    *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + 1;
  }
  else {
    if ((local_res20[0] != 0xd) && (local_res20[0] != 0xe)) {
      if (local_res20[0] == 0xf) goto LAB_140012a27;
      if (local_res20[0] == 0x10) goto LAB_140012b68;
      if (local_res20[0] != 0x11) {
        return uVar7;
      }
    }
    uVar2 = *(uint *)((longlong)param_1 + 0xc);
    if (*(uint *)(param_1 + 1) <= uVar2 + 2) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc0000185;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return 0xc0000185;
      }
      uVar6 = 0x1e;
      goto LAB_140012b56;
    }
    lVar1 = *param_1;
    *(uint *)(*param_2 + 0xc) =
         (uint)CONCAT21(CONCAT11(*(undefined1 *)((ulonglong)uVar2 + lVar1),
                                 *(undefined1 *)((ulonglong)(uVar2 + 1) + lVar1)),
                        *(undefined1 *)((ulonglong)(uVar2 + 2) + lVar1));
    *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + 3;
  }
  uVar4 = ParseTokenData(param_1,*param_2);
  uVar2 = (uint)uVar4;
LAB_140012b99:
  return (ulonglong)uVar2;
}



===== ParseTokenData @ 140012c00 =====

undefined8 ParseTokenData(longlong *param_1,longlong param_2)

{
  longlong *_Dst;
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = 0;
  uVar5 = *(uint *)(param_2 + 0xc);
  if (*(uint *)(param_1 + 1) < uVar5 + *(uint *)((longlong)param_1 + 0xc)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
               &WPP_d27db7d0d3983550ea60457830c64ea4_Traceguids,uVar5);
    }
    uVar3 = 0xc0000185;
  }
  else {
    _Dst = (longlong *)(param_2 + 0x10);
    if (uVar5 < 9) {
      if (*(int *)(param_2 + 8) - 0xfU < 3) {
        *_Dst = 0;
        memmove(_Dst,(void *)((ulonglong)*(uint *)((longlong)param_1 + 0xc) + *param_1),
                (ulonglong)*(uint *)(param_2 + 0xc));
      }
      else {
        *_Dst = 0;
        uVar4 = 0;
        if (uVar5 != 0) {
          do {
            iVar1 = *(int *)((longlong)param_1 + 0xc) - uVar4;
            uVar2 = (ulonglong)uVar4;
            uVar4 = uVar4 + 1;
            *(undefined1 *)(uVar2 + 0x10 + param_2) =
                 *(undefined1 *)((ulonglong)((uVar5 - 1) + iVar1) + *param_1);
            uVar5 = *(uint *)(param_2 + 0xc);
          } while (uVar4 < uVar5);
        }
      }
    }
    else {
      *_Dst = (ulonglong)*(uint *)((longlong)param_1 + 0xc) + *param_1;
    }
    *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + *(int *)(param_2 + 0xc);
  }
  return uVar3;
}



===== PeekTokenInfo @ 140012ce0 =====

undefined8 PeekTokenInfo(longlong *param_1,byte *param_2,int *param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  
  uVar2 = *(uint *)((longlong)param_1 + 0xc);
  uVar4 = 0;
  bVar1 = *(byte *)((ulonglong)uVar2 + *param_1);
  if (uVar2 < *(uint *)(param_1 + 1)) {
    if (param_2 != (byte *)0x0) {
      *param_2 = bVar1;
    }
    if (param_3 != (int *)0x0) {
      if ((byte)(bVar1 + 5) < 2) {
        *param_3 = 2;
      }
      else if (bVar1 == 0xfa) {
        *param_3 = 3;
      }
      else if (bVar1 == 0xf8) {
        *param_3 = 4;
      }
      else if (bVar1 == 0xf0) {
        *param_3 = 5;
      }
      else if (bVar1 == 0xf2) {
        *param_3 = 6;
      }
      else {
        if ((char)bVar1 < '\0') {
          if ((bVar1 & 0xc0) == 0x80) {
            if ((bVar1 & 0x20) != 0) {
              *param_3 = 0xf;
              return 0;
            }
            iVar3 = 10 - (uint)((bVar1 & 10) != 0);
          }
          else if ((bVar1 & 0xe0) == 0xc0) {
            if ((bVar1 & 0x10) != 0) {
              *param_3 = 0x10;
              return 0;
            }
            iVar3 = 0xc - (uint)((bVar1 & 8) != 0);
          }
          else {
            if ((bVar1 & 0xfc) != 0xe0) {
              if ((((byte)(bVar1 + 0x1c) < 0xc) || ((byte)(bVar1 + 0xc) < 4)) ||
                 ((byte)(bVar1 + 3) < 2)) {
                *param_3 = 0;
                return 0;
              }
              *param_3 = 1;
              return 0;
            }
            if ((bVar1 & 2) != 0) {
              *param_3 = 0x11;
              return 0;
            }
            iVar3 = 0xe - (uint)((bVar1 & 1) != 0);
          }
        }
        else {
          iVar3 = 8 - (uint)((bVar1 & 0x40) != 0);
        }
        *param_3 = iVar3;
      }
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
                &WPP_d27db7d0d3983550ea60457830c64ea4_Traceguids,*(uint *)(param_1 + 1),(char)uVar2)
      ;
    }
    uVar4 = 0x8000001a;
  }
  return uVar4;
}



===== TcglibpMapStatus @ 140012e68 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 TcglibpMapStatus(undefined8 *param_1,byte param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  undefined *puVar4;
  
  if (param_2 < 10) {
    if (param_2 != 9) {
      if (param_2 == 0) {
        uVar3 = 0;
        goto LAB_140012f4c;
      }
      if (param_2 == 1) {
        uVar3 = 0xc0000022;
      }
      else if (param_2 == 3) {
        uVar3 = 0xc00000ce;
      }
      else {
        if (param_2 == 4) goto LAB_140012eb1;
        if ((param_2 == 5) || (param_2 == 6)) {
          uVar3 = 0xc0000072;
        }
        else {
          if (param_2 != 7) {
            if (param_2 == 8) goto LAB_140012f12;
            goto LAB_140012eb1;
          }
          uVar3 = 0x80000011;
        }
      }
      goto LAB_140012f17;
    }
LAB_140012f12:
    uVar3 = 0xc000009a;
  }
  else {
    if (param_2 == 10) goto LAB_140012f12;
    if ((param_2 == 0xb) || (param_2 == 0xc)) {
      uVar3 = 0xc000000d;
    }
    else if ((param_2 == 0xf) || (param_2 == 0x10)) {
LAB_140012eb1:
      uVar3 = 0xc0000185;
    }
    else if (param_2 == 0x11) {
      uVar3 = 0xc0000231;
    }
    else {
      if (param_2 != 0x12) goto LAB_140012eb1;
      uVar3 = 0xc0000234;
    }
  }
LAB_140012f17:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
              &WPP_d27db7d0d3983550ea60457830c64ea4_Traceguids,(uint)param_2,(char)uVar3);
  }
LAB_140012f4c:
  uVar2 = *param_1;
  puVar4 = PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  if ((param_2 != 0) && ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 1) != 0)) {
    McTemplateK0siiiid_EtwWriteTransfer
              (*(undefined8 *)(lVar1 + 0x18b0),uVar2,puVar4,*(char **)(lVar1 + 0x18a8),
               (char)*(undefined8 *)(lVar1 + 0x18b0),(char)*(undefined8 *)(lVar1 + 0x18b8),
               (char)*(undefined8 *)(lVar1 + 0x18c0),(char)*(undefined8 *)(lVar1 + 0x18c8),param_2);
  }
  *(undefined8 *)(lVar1 + 0x18a8) = 0;
  *(undefined8 *)(lVar1 + 0x18b0) = 0;
  *(undefined8 *)(lVar1 + 0x18b8) = 0;
  *(undefined8 *)(lVar1 + 0x18c0) = 0;
  *(undefined8 *)(lVar1 + 0x18c8) = 0;
  return uVar3;
}



===== WPP_SF_DD @ 140013004 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_d27db7d0d3983550ea60457830c64ea4_Traceguids,0xf,local_res20,4,
             &param_5,4,0);
  return;
}



===== GenCallMethodEnd @ 14001305c =====

ulonglong GenCallMethodEnd(longlong *param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  if (*(uint *)((longlong)param_1 + 0xc) + 1 <= *(uint *)(param_1 + 1)) {
    *(undefined1 *)((ulonglong)*(uint *)((longlong)param_1 + 0xc) + *param_1) = 0xf1;
    *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + 1;
    uVar2 = (ulonglong)*(uint *)((longlong)param_1 + 0xc);
    if (*(uint *)(param_1 + 1) < *(uint *)((longlong)param_1 + 0xc) + 1) {
      uVar1 = 0xc0000023;
    }
    else {
      *(undefined1 *)(uVar2 + *param_1) = 0xf9;
      *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + 1;
      uVar2 = (ulonglong)*(uint *)((longlong)param_1 + 0xc);
      uVar1 = 0;
    }
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    if ((int)uVar2 + 1U <= *(uint *)(param_1 + 1)) {
      *(undefined1 *)(uVar2 + *param_1) = 0xf0;
      *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + 1;
      uVar2 = GenInteger(param_1,0);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      uVar2 = GenInteger(param_1,0);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      uVar2 = GenInteger(param_1,0);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      if (*(uint *)((longlong)param_1 + 0xc) + 1 <= *(uint *)(param_1 + 1)) {
        *(undefined1 *)((ulonglong)*(uint *)((longlong)param_1 + 0xc) + *param_1) = 0xf1;
        *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + 1;
        return 0;
      }
    }
  }
  return 0xc0000023;
}



===== GenDataBytes @ 140013108 =====

undefined8 GenDataBytes(longlong *param_1,void *param_2,uint param_3)

{
  uint uVar1;
  undefined8 uVar2;
  
  if (param_3 < 0x10) {
    uVar1 = param_3 + 1 + *(uint *)((longlong)param_1 + 0xc);
    uVar2 = 0;
    if (*(uint *)(param_1 + 1) < uVar1) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                  &WPP_7125d21b90f93d8abdbf4e6e2db0cd73_Traceguids,*(uint *)(param_1 + 1),
                  (char)uVar1);
      }
      uVar2 = 0xc0000023;
    }
    else {
      *(char *)((ulonglong)*(uint *)((longlong)param_1 + 0xc) + *param_1) = (char)param_3 + -0x60;
      uVar1 = *(int *)((longlong)param_1 + 0xc) + 1;
      *(uint *)((longlong)param_1 + 0xc) = uVar1;
      if (param_3 != 0) {
        memmove((void *)((ulonglong)uVar1 + *param_1),param_2,(ulonglong)param_3);
        *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + param_3;
      }
    }
  }
  else if (param_3 < 0x800) {
    uVar2 = GenMediumDataBytes(param_1,param_2,param_3);
  }
  else if (param_3 < 0x1000000) {
    uVar2 = GenLongDataBytes(param_1,param_2,param_3,'\0');
  }
  else {
    uVar2 = GenLongDataBytes(param_1,param_2,0xffffff,'\x01');
    if (-1 < (int)uVar2) {
      uVar2 = GenDataBytes(param_1,(void *)((longlong)param_2 + 0xffffff),param_3 - 0xffffff);
    }
  }
  return uVar2;
}



===== GenInteger @ 14001320c =====

ulonglong GenInteger(longlong *param_1,ulonglong param_2)

{
  uint uVar1;
  ulonglong uVar2;
  
  if (param_2 < 0x40) {
    uVar2 = 0;
    uVar1 = *(uint *)((longlong)param_1 + 0xc) + 1;
    if (*(uint *)(param_1 + 1) < uVar1) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                  &WPP_7125d21b90f93d8abdbf4e6e2db0cd73_Traceguids,*(uint *)(param_1 + 1),
                  (char)uVar1);
      }
      uVar2 = 0xc0000023;
    }
    else {
      *(byte *)((ulonglong)*(uint *)((longlong)param_1 + 0xc) + *param_1) = (byte)param_2 & 0x3f;
      *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + 1;
    }
  }
  else {
    uVar2 = GenShortInteger(param_1,param_2);
    uVar2 = uVar2 & 0xffffffff;
  }
  return uVar2;
}



===== GenLongDataBytes @ 14001328c =====

undefined8 GenLongDataBytes(longlong *param_1,void *param_2,uint param_3,char param_4)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  
  uVar4 = 0;
  uVar2 = param_3 + 4 + *(uint *)((longlong)param_1 + 0xc);
  if (*(uint *)(param_1 + 1) < uVar2) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                &WPP_7125d21b90f93d8abdbf4e6e2db0cd73_Traceguids,*(uint *)(param_1 + 1),(char)uVar2)
      ;
    }
    uVar4 = 0xc0000023;
  }
  else {
    *(undefined1 *)((ulonglong)*(uint *)((longlong)param_1 + 0xc) + *param_1) = 0xe2;
    if (param_4 != '\0') {
      pbVar1 = (byte *)((ulonglong)*(uint *)((longlong)param_1 + 0xc) + *param_1);
      *pbVar1 = *pbVar1 | 1;
    }
    *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + 1;
    uVar3 = *(uint *)((longlong)param_1 + 0xc);
    uVar2 = uVar3 + 2;
    uVar5 = (ulonglong)param_3;
    while (uVar3 <= uVar2) {
      *(char *)((ulonglong)uVar2 + *param_1) = (char)uVar5;
      uVar5 = uVar5 >> 8;
      uVar2 = uVar2 - 1;
      uVar3 = *(uint *)((longlong)param_1 + 0xc);
    }
    *(uint *)((longlong)param_1 + 0xc) = uVar3 + 3;
    memmove((void *)((ulonglong)(uVar3 + 3) + *param_1),param_2,(ulonglong)param_3);
    *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + param_3;
  }
  return uVar4;
}



===== GenMediumDataBytes @ 14001335c =====

undefined8 GenMediumDataBytes(longlong *param_1,void *param_2,uint param_3)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  uVar1 = param_3 + 2 + *(uint *)((longlong)param_1 + 0xc);
  if (*(uint *)(param_1 + 1) < uVar1) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                &WPP_7125d21b90f93d8abdbf4e6e2db0cd73_Traceguids,*(uint *)(param_1 + 1),(char)uVar1)
      ;
    }
    uVar2 = 0xc0000023;
  }
  else {
    *(byte *)((ulonglong)*(uint *)((longlong)param_1 + 0xc) + *param_1) =
         ((byte)(param_3 >> 8) & 7) - 0x30;
    *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + 1;
    *(char *)((ulonglong)*(uint *)((longlong)param_1 + 0xc) + *param_1) = (char)param_3;
    *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + 1;
    memmove((void *)((ulonglong)*(uint *)((longlong)param_1 + 0xc) + *param_1),param_2,
            (ulonglong)param_3);
    *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + param_3;
  }
  return uVar2;
}



===== GenNamedValueBytes @ 14001340c =====

ulonglong GenNamedValueBytes(longlong *param_1,ulonglong param_2,void *param_3,uint param_4)

{
  ulonglong uVar1;
  
  if (*(uint *)((longlong)param_1 + 0xc) + 1 <= *(uint *)(param_1 + 1)) {
    *(undefined1 *)((ulonglong)*(uint *)((longlong)param_1 + 0xc) + *param_1) = 0xf2;
    *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + 1;
    uVar1 = GenInteger(param_1,param_2);
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    uVar1 = GenDataBytes(param_1,param_3,param_4);
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    if (*(uint *)((longlong)param_1 + 0xc) + 1 <= *(uint *)(param_1 + 1)) {
      *(undefined1 *)((ulonglong)*(uint *)((longlong)param_1 + 0xc) + *param_1) = 0xf3;
      *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + 1;
      return 0;
    }
  }
  return 0xc0000023;
}



===== GenNamedValueInt @ 14001348c =====

ulonglong GenNamedValueInt(longlong *param_1,ulonglong param_2,ulonglong param_3)

{
  ulonglong uVar1;
  
  if (*(uint *)((longlong)param_1 + 0xc) + 1 <= *(uint *)(param_1 + 1)) {
    *(undefined1 *)((ulonglong)*(uint *)((longlong)param_1 + 0xc) + *param_1) = 0xf2;
    *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + 1;
    uVar1 = GenInteger(param_1,param_2);
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    uVar1 = GenInteger(param_1,param_3);
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    if (*(uint *)((longlong)param_1 + 0xc) + 1 <= *(uint *)(param_1 + 1)) {
      *(undefined1 *)((ulonglong)*(uint *)((longlong)param_1 + 0xc) + *param_1) = 0xf3;
      *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + 1;
      return 0;
    }
  }
  return 0xc0000023;
}



===== GenNamedValueListBegin @ 1400134fc =====

ulonglong GenNamedValueListBegin(longlong *param_1,ulonglong param_2)

{
  ulonglong uVar1;
  
  if (*(uint *)((longlong)param_1 + 0xc) + 1 <= *(uint *)(param_1 + 1)) {
    *(undefined1 *)((ulonglong)*(uint *)((longlong)param_1 + 0xc) + *param_1) = 0xf2;
    *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + 1;
    uVar1 = GenInteger(param_1,param_2);
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    if (*(uint *)((longlong)param_1 + 0xc) + 1 <= *(uint *)(param_1 + 1)) {
      *(undefined1 *)((ulonglong)*(uint *)((longlong)param_1 + 0xc) + *param_1) = 0xf0;
      *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + 1;
      return 0;
    }
  }
  return 0xc0000023;
}



===== GenNamedValueListEnd @ 140013554 =====

undefined8 GenNamedValueListEnd(longlong *param_1)

{
  int iVar1;
  uint uVar2;
  
  if (*(uint *)((longlong)param_1 + 0xc) + 1 <= *(uint *)(param_1 + 1)) {
    *(undefined1 *)((ulonglong)*(uint *)((longlong)param_1 + 0xc) + *param_1) = 0xf1;
    iVar1 = *(int *)((longlong)param_1 + 0xc);
    uVar2 = iVar1 + 1;
    *(uint *)((longlong)param_1 + 0xc) = uVar2;
    if (iVar1 + 2U <= *(uint *)(param_1 + 1)) {
      *(undefined1 *)((ulonglong)uVar2 + *param_1) = 0xf3;
      *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + 1;
      return 0;
    }
  }
  return 0xc0000023;
}



===== GenShortInteger @ 140013594 =====

undefined8 GenShortInteger(longlong *param_1,ulonglong param_2)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  
  uVar5 = 0;
  iVar4 = 0;
  uVar2 = param_2;
  if (param_2 != 0) {
    do {
      uVar2 = uVar2 >> 8;
      iVar4 = iVar4 + 1;
    } while (uVar2 != 0);
    if (iVar4 != 0) goto LAB_1400135c5;
  }
  iVar4 = 1;
LAB_1400135c5:
  uVar1 = *(uint *)((longlong)param_1 + 0xc) + 1 + iVar4;
  if (*(uint *)(param_1 + 1) < uVar1) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_7125d21b90f93d8abdbf4e6e2db0cd73_Traceguids,*(uint *)(param_1 + 1),(char)uVar1)
      ;
    }
    uVar5 = 0xc0000023;
  }
  else {
    *(char *)((ulonglong)*(uint *)((longlong)param_1 + 0xc) + *param_1) = (char)iVar4 + -0x80;
    *(int *)((longlong)param_1 + 0xc) = *(int *)((longlong)param_1 + 0xc) + 1;
    uVar1 = *(uint *)((longlong)param_1 + 0xc);
    uVar3 = (uVar1 - 1) + iVar4;
    while (uVar1 <= uVar3) {
      *(char *)((ulonglong)uVar3 + *param_1) = (char)param_2;
      param_2 = param_2 >> 8;
      uVar3 = uVar3 - 1;
      uVar1 = *(uint *)((longlong)param_1 + 0xc);
    }
    *(uint *)((longlong)param_1 + 0xc) = uVar1 + iVar4;
  }
  return uVar5;
}



===== GenTCGHeaders @ 14001365c =====

undefined8
GenTCGHeaders(undefined8 *param_1,uint param_2,longlong param_3,uint param_4,undefined4 param_5,
             undefined4 param_6)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  
  if ((ulonglong)param_2 < (ulonglong)param_4 + 0x38) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                &WPP_7125d21b90f93d8abdbf4e6e2db0cd73_Traceguids,param_2,(char)param_4 + '8');
    }
    uVar3 = 0xc0000023;
  }
  else {
    *param_1 = 0;
    param_1[1] = 0;
    uVar5 = param_4 + 0x27 & 0xfffffffc;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    uVar1 = TcglibReverseUInt16(*(undefined2 *)(param_3 + 0x18));
    *(undefined2 *)((longlong)param_1 + 4) = uVar1;
    uVar2 = TcglibReverseUInt32(uVar5);
    *(undefined4 *)(param_1 + 2) = uVar2;
    uVar4 = 4;
    *(undefined4 *)((longlong)param_1 + 0x14) = param_5;
    TcglibReverseBytes((undefined1 *)((longlong)param_1 + 0x14),4);
    *(undefined4 *)(param_1 + 3) = param_6;
    TcglibReverseBytes((undefined1 *)(param_1 + 3),uVar4);
    uVar2 = TcglibReverseUInt32(uVar5 - 0x18);
    *(undefined4 *)(param_1 + 5) = uVar2;
    uVar2 = TcglibReverseUInt32(param_4);
    *(undefined4 *)((longlong)param_1 + 0x34) = uVar2;
    uVar3 = 0;
  }
  return uVar3;
}



===== _guard_check_icall @ 140013760 =====

void _guard_check_icall(void)

{
  return;
}



===== __security_check_cookie @ 140013780 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1400137c0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1400137f0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001400137f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140013820 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memset @ 140013880 =====

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



===== __memset_repmovs @ 1400139c0 =====

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



===== __memset_query @ 140013a40 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140013ac0 =====

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



===== __memset_spec_ermsb_repmovsb @ 140013c00 =====

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



===== __memset_spec_plain @ 140013c80 =====

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



===== memcmp @ 140013da0 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_140013de3;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_140013e54;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_140013e50:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140013e54;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_140013e4c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140013e50;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140013e4c;
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
LAB_140013e54:
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
LAB_140013de3:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memmove @ 140013ec0 =====

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



===== DriverEvtUnload @ 14001c010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DriverEvtUnload(undefined8 param_1)

{
  if (KsrCachedContext != 0) {
    ExFreePoolWithTag(KsrCachedContext,0);
    KsrCachedContext = 0;
  }
  if (KsrCallbackHandle != 0) {
    ExUnregisterCallback();
  }
  McGenEventUnregister_EtwUnregister();
  (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,param_1);
  WppCleanupKm();
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



===== WppCleanupKm @ 14001c0d0 =====

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



===== WppInitKm @ 14001c150 =====

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



===== WppLoadTracingSupport @ 14001c1e0 =====

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



===== WppTraceCallback @ 14001c330 =====

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



===== wil_details_EvaluateFeatureDependencies @ 14001c5b8 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  uint uVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  bool bVar5;
  
  puVar4 = (undefined *)0x0;
  ppuVar3 = &wil_details_featureDescriptors_a;
  ppuVar2 = &wil_details_featureDescriptors_a;
  do {
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x00014001c5f3;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_14001c66d:
  while( true ) {
    if (&UNK_140018667 < ppuVar3) {
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
      if (&UNK_140018667 < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x00014001c5f3:
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
      if (&UNK_140018667 < ppuVar2) goto LAB_14001c66d;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_14001c66d;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14001c6a8 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_14001c740;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_14001c740;
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
LAB_14001c740:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14001c790 =====

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
      for (ppuVar2 = &wil_details_featureDescriptors_a; ppuVar2 < &wil_details_featureDescriptors_z;
          ppuVar2 = ppuVar2 + 1) {
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
              if (&UNK_140018667 < ppuVar2) {
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14001c810 =====

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
  for (ppuVar3 = &wil_details_featureDescriptors_a; ppuVar3 < &wil_details_featureDescriptors_z;
      ppuVar3 = ppuVar3 + 1) {
    if (*ppuVar3 != (undefined *)0x0) goto LAB_14001c90d;
  }
LAB_14001c916:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14001c90d:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14001c916;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14001c8de:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14001c8de;
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
    if (&UNK_140018667 < ppuVar3) goto LAB_14001c916;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14001c90d;
}



===== DeviceEvtCleanup @ 14001c940 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DeviceEvtCleanup(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  if (*(longlong *)(lVar1 + 0x18e8) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0x18e8),0);
    *(undefined8 *)(lVar1 + 0x18e8) = 0;
  }
  if (*(longlong *)(lVar1 + 0x18f0) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0x18f0),0);
    *(undefined8 *)(lVar1 + 0x18f0) = 0;
  }
  if (*(longlong *)(lVar1 + 0x1900) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0x1900),0);
    *(undefined8 *)(lVar1 + 0x1900) = 0;
  }
  if (*(longlong *)(lVar1 + 0x1910) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0x1910),0);
    *(undefined8 *)(lVar1 + 0x1910) = 0;
  }
  if (*(longlong *)(lVar1 + 0x1890) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0x1890),0);
    *(undefined8 *)(lVar1 + 0x1890) = 0;
  }
  if (*(longlong *)(lVar1 + 0x18d0) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0x18d0),0);
    *(undefined8 *)(lVar1 + 0x18d0) = 0;
  }
  if (*(char *)(lVar1 + 0x1960) != '\0') {
    KeDeregisterBugCheckCallback(lVar1 + 0x1920);
  }
  return;
}



===== DeviceEvtSelfManagedIoCleanup @ 14001ca70 =====

void DeviceEvtSelfManagedIoCleanup(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 2) != 0) {
    McTemplateK0sdddd_EtwWriteTransfer(param_1,param_2,param_3,"DeviceStop",0,0);
  }
  return;
}



===== DeviceEvtSelfManagedIoInit @ 14001caa0 =====

int DeviceEvtSelfManagedIoInit(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  iVar1 = InitDevice(param_1,'\0');
  if ((Microsoft_Windows_EnhancedStorage_EhStorTcgDrvEnableBits & 2) != 0) {
    McTemplateK0sdddd_EtwWriteTransfer(param_1,uVar2,param_3,"DeviceStart",(char)iVar1,0);
  }
  return iVar1;
}



===== DevicePreprocessStartIrp @ 14001cae0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DevicePreprocessStartIrp(undefined8 param_1)

{
  char *pcVar1;
  longlong *plVar2;
  longlong lVar3;
  int iVar4;
  undefined8 uVar5;
  longlong *plVar6;
  
  uVar5 = (**(code **)(WdfFunctions_01015 + 0xbe8))(WdfDriverGlobals,param_1);
  plVar6 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_PNP_IRP_WORKITEM_CONTEXT_TYPE_INFO_140019090
                     );
  lVar3 = *plVar6;
  pcVar1 = (char *)(lVar3 + 0x43);
  *pcVar1 = *pcVar1 + '\x01';
  plVar2 = (longlong *)(lVar3 + 0xb8);
  *plVar2 = *plVar2 + 0x48;
  iVar4 = (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,uVar5,*plVar6);
  if (iVar4 < 0) {
    *(int *)(*plVar6 + 0x30) = iVar4;
    IofCompleteRequest(*plVar6,0);
  }
  return;
}



===== DriverEvtDeviceAdd @ 14001cb90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong DriverEvtDeviceAdd(undefined8 param_1,undefined8 param_2)

{
  short *psVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  undefined1 uVar4;
  int iVar5;
  uint uVar6;
  void *_Dst;
  ulonglong uVar7;
  undefined8 uVar8;
  longlong lVar9;
  undefined2 uVar10;
  ulonglong *puVar11;
  ulonglong uVar12;
  undefined8 local_res10;
  ulonglong local_res18;
  undefined8 local_res20;
  undefined8 in_stack_fffffffffffffe40;
  undefined4 uVar13;
  ulonglong local_198;
  code *pcStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined *local_168;
  longlong local_160 [6];
  code *local_130;
  undefined4 local_128;
  undefined8 local_124;
  undefined1 local_11b;
  code *local_100;
  code *local_f8;
  undefined4 local_c8 [2];
  code *local_c0;
  code *local_b0;
  code *local_90;
  code *local_80;
  
  uVar13 = (undefined4)((ulonglong)in_stack_fffffffffffffe40 >> 0x20);
  local_198 = (ulonglong)(uint)local_198;
  local_188 = 0;
  local_res20 = 0;
  local_160[1] = 0;
  _Dst = (void *)0x0;
  local_178 = 0;
  uStack_170 = 0;
  local_res10 = param_2;
  memset(local_c8,0,0x90);
  local_80 = DeviceEvtSelfManagedIoInit;
  local_c8[0] = 0x90;
  local_90 = DeviceEvtSelfManagedIoCleanup;
  local_c0 = DeviceEvtD0Entry;
  local_b0 = DeviceEvtD0Exit;
  (**(code **)(WdfFunctions_01015 + 0x1b8))(WdfDriverGlobals,param_2,local_c8);
  local_res18 = CONCAT71(local_res18._1_7_,2);
  iVar5 = (**(code **)(WdfFunctions_01015 + 0x248))
                    (WdfDriverGlobals,local_res10,DeviceEvtWdmPowerIrpPreprocess,0x16,&local_res18,
                     CONCAT44(uVar13,1));
  if (iVar5 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14001cd1d;
    uVar10 = 10;
  }
  else {
    local_res18 = local_res18 & 0xffffffffffffff00;
    iVar5 = (**(code **)(WdfFunctions_01015 + 0x248))
                      (WdfDriverGlobals,local_res10,DeviceEvtWdmPnpIrpPreprocess,0x1b,&local_res18,1
                      );
    if (((-1 < iVar5) || ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control)) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14001cd1d;
    uVar10 = 0xb;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
           &WPP_4e134a1eefcb3ea5ae96fc03a980aa94_Traceguids,iVar5);
LAB_14001cd1d:
  (**(code **)(WdfFunctions_01015 + 0x1c8))(WdfDriverGlobals,local_res10,0);
  (**(code **)(WdfFunctions_01015 + 0x1f8))(WdfDriverGlobals,local_res10);
  local_168 = PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018;
  local_198 = 0x38;
  pcStack_190 = DeviceEvtCleanup;
  local_188 = 0;
  local_178 = 0;
  uStack_170 = 0;
  uStack_180 = 0x300000002;
  uVar6 = (**(code **)(WdfFunctions_01015 + 600))
                    (WdfDriverGlobals,&local_res10,&local_198,&local_res20);
  if ((int)uVar6 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
               &WPP_4e134a1eefcb3ea5ae96fc03a980aa94_Traceguids,uVar6);
    }
  }
  else {
    _Dst = (void *)(**(code **)(WdfFunctions_01015 + 0x650))
                             (WdfDriverGlobals,local_res20,
                              PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
    memset(_Dst,0,0x1b68);
  }
  local_168 = (undefined *)0x0;
  local_188 = 0;
  uStack_180 = 0x100000001;
  pcStack_190 = (code *)0x0;
  local_198 = 0x38;
  uStack_170 = 0;
  local_178 = local_res20;
  if ((int)uVar6 < 0) {
    return (ulonglong)uVar6;
  }
  local_130 = (code *)0x0;
  local_160[2] = 0;
  local_160[3] = 0;
  local_160[4] = 0;
  local_160[5] = 0;
  uVar6 = (**(code **)(WdfFunctions_01015 + 0x418))
                    (WdfDriverGlobals,local_res20,&GUID_PNP_LOCATION_INTERFACE,local_160 + 2,0x28,1,
                     0);
  uVar12 = (ulonglong)uVar6;
  if ((int)uVar6 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar12;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return uVar12;
    }
    uVar10 = 0xd;
  }
  else {
    puVar11 = &local_res18;
    local_res18 = 0;
    uVar6 = (*local_130)(local_160[3]);
    if ((int)uVar6 < 0) {
      return (ulonglong)uVar6;
    }
    psVar1 = (short *)((longlong)_Dst + 0x1962);
    uVar12 = local_res18;
    uVar7 = ext_ms_win_ntos_ksr_l1_1_5_KsrFreePersistedMemory();
    if (((int)uVar7 < 0) ||
       (uVar7 = ext_ms_win_ntos_ksr_l1_1_5_KsrFreePersistedMemory(), (int)uVar7 < 0)) {
      uVar7 = uVar7 & 0xffffffff;
      *psVar1 = 0;
    }
    else {
      local_160[0] = 0;
      uVar6 = RtlStringCopyWorkerW(psVar1,puVar11,local_160,uVar12);
      uVar7 = (ulonglong)uVar6;
      if ((-1 < (int)uVar6) && (1 < 0x100U - local_160[0])) {
        RtlStringExHandleFillBehindNullW
                  ((longlong)(psVar1 + local_160[0]),(0x100U - local_160[0]) * 2);
      }
    }
    if (local_res18 != 0) {
      ExFreePoolWithTag(local_res18,0);
    }
    if ((int)uVar7 < 0) {
      return uVar7;
    }
    uVar8 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,local_res20);
    *(undefined8 *)((longlong)_Dst + 0x1870) = uVar8;
    plVar2 = (longlong *)((longlong)_Dst + 0x1878);
    uVar6 = (**(code **)(WdfFunctions_01015 + 0x600))
                      (WdfDriverGlobals,&local_198,0x200,0x47536353,0x20,local_160 + 1,plVar2);
    uVar12 = (ulonglong)uVar6;
    if ((int)uVar6 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return uVar12;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return uVar12;
      }
      WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                &WPP_4e134a1eefcb3ea5ae96fc03a980aa94_Traceguids,0x20,(char)uVar6);
      return uVar12;
    }
    puVar3 = (undefined8 *)*plVar2;
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    uVar6 = (**(code **)(WdfFunctions_01015 + 0x9c0))(WdfDriverGlobals,&local_198,*plVar2);
    uVar12 = (ulonglong)uVar6;
    if ((int)uVar6 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return uVar12;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return uVar12;
      }
      uVar10 = 0xf;
    }
    else {
      uVar6 = (**(code **)(WdfFunctions_01015 + 0x7b8))
                        (WdfDriverGlobals,&local_198,*(undefined8 *)((longlong)_Dst + 0x1870),
                         *plVar2 + 8);
      uVar12 = (ulonglong)uVar6;
      if ((int)uVar6 < 0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return uVar12;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
          return uVar12;
        }
        uVar10 = 0x10;
      }
      else {
        uVar6 = (**(code **)(WdfFunctions_01015 + 0x608))
                          (WdfDriverGlobals,&local_198,&TempChar,1,*plVar2 + 0x10);
        uVar12 = (ulonglong)uVar6;
        if ((int)uVar6 < 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return uVar12;
          }
          if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
            return uVar12;
          }
          uVar10 = 0x11;
        }
        else {
          uVar6 = (**(code **)(WdfFunctions_01015 + 0x608))
                            (WdfDriverGlobals,&local_198,&TempChar,1,*plVar2 + 0x18);
          uVar12 = (ulonglong)uVar6;
          if ((int)uVar6 < 0) {
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return uVar12;
            }
            if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
              return uVar12;
            }
            uVar10 = 0x12;
          }
          else {
            lVar9 = *plVar2;
            uVar6 = (**(code **)(WdfFunctions_01015 + 0x5e8))
                              (WdfDriverGlobals,*(undefined8 *)((longlong)_Dst + 0x1870),
                               *(undefined8 *)(lVar9 + 8),0x2d140c,*(undefined8 *)(lVar9 + 0x10),0,
                               *(undefined8 *)(lVar9 + 0x18),0);
            uVar12 = (ulonglong)uVar6;
            if ((int)uVar6 < 0) {
              if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                return uVar12;
              }
              if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
                return uVar12;
              }
              uVar10 = 0x13;
            }
            else {
              memset(&local_128,0,0x60);
              local_100 = DefaultQueueEvtDeviceControl;
              local_128 = 0x60;
              local_f8 = DefaultQueueEvtInternalDeviceControl;
              local_11b = 1;
              local_124 = 1;
              uVar6 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                                (WdfDriverGlobals,local_res20,&local_128,0,(longlong)_Dst + 0x1868);
              uVar12 = (ulonglong)uVar6;
              if ((int)uVar6 < 0) {
                if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                  return uVar12;
                }
                if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
                  return uVar12;
                }
                uVar10 = 0x14;
              }
              else {
                *(undefined4 *)((longlong)_Dst + 0x1888) = 0x800;
                *(undefined4 *)((longlong)_Dst + 0x1898) = 0xa08;
                lVar9 = ExAllocatePool2(0x40,0xa08,0x47536353);
                *(longlong *)((longlong)_Dst + 0x1890) = lVar9;
                if (lVar9 == 0) {
                  *(undefined4 *)((longlong)_Dst + 0x1898) = 0;
                  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                    return 0xc000009a;
                  }
                  if (WPP_GLOBAL_Control[0x29] == '\0') {
                    return 0xc000009a;
                  }
                  uVar10 = 0x15;
                }
                else {
                  uVar6 = *(int *)((longlong)_Dst + 0x1888) + 0x21fU & 0xfffffe00;
                  *(uint *)((longlong)_Dst + 0x18d8) = uVar6;
                  lVar9 = ExAllocatePool2(0x40,uVar6,0x47536353);
                  *(longlong *)((longlong)_Dst + 0x18d0) = lVar9;
                  if (lVar9 != 0) {
                    *(undefined1 *)((longlong)_Dst + 0x1958) = 0;
                    uVar4 = KeRegisterBugCheckCallback
                                      ((longlong)_Dst + 0x1920,DeviceEvtBugcheckHandler,_Dst,0x1b68,
                                       "ehstortcgdrv");
                    *(undefined1 *)((longlong)_Dst + 0x1960) = uVar4;
                    return uVar12;
                  }
                  *(undefined4 *)((longlong)_Dst + 0x18d8) = 0;
                  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                    return 0xc000009a;
                  }
                  if (WPP_GLOBAL_Control[0x29] == '\0') {
                    return 0xc000009a;
                  }
                  uVar10 = 0x16;
                }
                uVar12 = 0xc000009a;
                uVar6 = 0;
              }
            }
          }
        }
      }
    }
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
           &WPP_4e134a1eefcb3ea5ae96fc03a980aa94_Traceguids,uVar6);
  return uVar12;
}



===== InitDevice @ 14001d3e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int InitDevice(undefined8 param_1,char param_2)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  undefined1 auStackY_c8 [32];
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
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
  undefined4 local_38;
  undefined4 local_34;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_78 = 0x14;
  local_68 = 0x14;
  local_74 = 3;
  local_64 = 0x2d1480;
  local_60 = 0x2dd484;
  local_5c = 0x2dd488;
  local_58 = 0x2d148c;
  local_54 = 0x2dd490;
  local_50 = 0x2dd494;
  local_4c = 0x2dd498;
  local_48 = 0x2d149c;
  local_44 = 0x2dd4a0;
  local_40 = 0x2dd4a4;
  local_3c = 0x2dd4a8;
  local_38 = 0x2dd4ac;
  local_34 = 0x2dd4b0;
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
  if ((((TcgSiloKsrCallbackObject == 0) || (cVar2 = ExIsSoftBoot(), cVar2 == '\0')) ||
      (param_2 != '\0')) || (iVar3 = TcgSiloKsrRestoreDeviceContext(param_1), iVar3 < 0)) {
    uVar4 = IoctlQueryCapabilities(param_1,0);
    if ((int)uVar4 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                &WPP_4e134a1eefcb3ea5ae96fc03a980aa94_Traceguids);
      }
      *(uint *)(lVar5 + 0x1860) = *(uint *)(lVar5 + 0x1860) | 1;
      return 0;
    }
    bVar1 = false;
    if (((*(uint *)(*(longlong *)(lVar5 + 0x18e8) + 4) & 1) != 0) &&
       (iVar3 = *(int *)(*(longlong *)(lVar5 + 0x18e8) + 0x18), iVar3 != 0)) {
      uVar4 = LoadBandTableEntries(param_1,0,iVar3,'\0');
      bVar1 = false;
      if (-1 < (int)uVar4) {
        bVar1 = true;
      }
    }
  }
  else {
    bVar1 = false;
  }
  if ((*(uint *)(*(longlong *)(lVar5 + 0x18e8) + 4) & 1) == 0) {
    if (*(longlong *)(lVar5 + 0x18f0) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar5 + 0x18f0),0);
      *(undefined8 *)(lVar5 + 0x18f0) = 0;
    }
    if (*(longlong *)(lVar5 + 0x1900) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar5 + 0x1900),0);
      *(undefined8 *)(lVar5 + 0x1900) = 0;
    }
    if (*(longlong *)(lVar5 + 0x1910) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar5 + 0x1910),0);
      *(undefined8 *)(lVar5 + 0x1910) = 0;
    }
    *(undefined4 *)(lVar5 + 0x18f8) = 0;
    bVar1 = false;
    *(undefined4 *)(lVar5 + 0x1908) = 0;
    *(undefined4 *)(lVar5 + 0x1918) = 0;
  }
  local_70 = *(undefined4 *)(*(longlong *)(lVar5 + 0x18e8) + 0x18);
  if ((*(uint *)(*(longlong *)(lVar5 + 0x18e8) + 4) & 1) == 0) {
    local_6c = 2;
    local_74 = 0;
  }
  else {
    local_6c = 0xd;
  }
  iVar3 = IssueSyncIoctl(*(undefined8 *)(lVar5 + 0x1870),*(undefined8 **)(lVar5 + 0x1878),'\x01',
                         0x2dd440,(longlong)&local_78,0x48,0,0,(undefined8 *)0x0);
  if (iVar3 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
               &WPP_4e134a1eefcb3ea5ae96fc03a980aa94_Traceguids,iVar3);
    }
  }
  else if (bVar1) {
    iVar3 = UpdateLbaFilterTable(param_1);
  }
  return iVar3;
}



===== TcgSiloKsrCallback @ 14001d6d0 =====

void TcgSiloKsrCallback(undefined8 param_1,int param_2)

{
  if (param_2 == 0) {
    TcgSiloKsrSaveContext();
  }
  else {
    if (param_2 != 1) {
      if (param_2 != 2) {
        return;
      }
      if (KsrCachedContext != 0) {
        ExFreePoolWithTag(KsrCachedContext,0);
        KsrCachedContext = 0;
      }
    }
    KsrFreePersistedMemory(&GUID_TCG_SILO_KSR_CONTEXT,1);
  }
  return;
}



===== TcgSiloKsrSaveContext @ 14001d72c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int TcgSiloKsrSaveContext(void)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 *puVar5;
  longlong lVar6;
  longlong lVar7;
  uint uVar8;
  uint uVar9;
  undefined8 *puVar10;
  uint uVar11;
  uint local_res8 [2];
  undefined4 local_res10 [2];
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = 0;
  lVar6 = 0;
  local_res8[0] = 0;
  uVar9 = 0;
  local_res10[0] = 0;
  uVar11 = 0;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,*WdfDriverGlobals);
  lVar4 = *(longlong *)(lVar4 + 8);
  if (lVar4 != 0) {
    do {
      uVar2 = (**(code **)(WdfFunctions_01015 + 0xf0))(WdfDriverGlobals,lVar4);
      lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,uVar2,
                         PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
      if ((lVar3 != 0) && (*(longlong *)(lVar3 + 0x18e8) != 0)) {
        uVar11 = uVar11 + 1;
        uVar8 = *(int *)(lVar3 + 0x1908) + 0x3330 +
                *(int *)(lVar3 + 0x18f8) * 0x78 + *(int *)(lVar3 + 0x1918);
        if (uVar8 <= uVar9) {
          uVar8 = uVar9;
        }
        uVar9 = uVar8;
      }
      lVar4 = *(longlong *)(lVar4 + 0x10);
    } while (lVar4 != 0);
    if (uVar11 != 0) {
      lVar4 = MmAllocatePagesForMdlEx
                        (0,0xffffffffffffffff,0,
                         (ulonglong)(uVar9 * uVar11) + 0x1027 & 0xfffffffffffff000,1,0x14);
      if (lVar4 == 0) {
        return -0x3fffff66;
      }
      puVar5 = (undefined4 *)MmMapLockedPagesSpecifyCache(lVar4,0,1,0,0,0x40000020);
      if (puVar5 == (undefined4 *)0x0) {
        iVar1 = -0x3fffff66;
      }
      else {
        KsrMdlToMemoryRuns(lVar4,0,0,local_res8);
        lVar6 = ExAllocatePool2(0x40,(ulonglong)local_res8[0] << 3,0x52534b53);
        if (lVar6 == 0) {
          iVar1 = -0x3fffff66;
        }
        else {
          iVar1 = KsrMdlToMemoryRuns(lVar4,lVar6,local_res8[0],local_res10);
          if ((-1 < iVar1) &&
             (iVar1 = KsrPersistMemory(&GUID_TCG_SILO_KSR_CONTEXT,lVar6,local_res8[0],&local_res18),
             -1 < iVar1)) {
            *(ulonglong *)(puVar5 + 2) = (ulonglong)(uVar9 * uVar11) + 0x28;
            *puVar5 = 0x4b676354;
            puVar5[1] = 0x28;
            *(undefined8 *)(puVar5 + 8) = 0x28;
            puVar10 = (undefined8 *)(puVar5 + 10);
            *(ulonglong *)(puVar5 + 6) = (ulonglong)uVar9;
            *(ulonglong *)(puVar5 + 4) = (ulonglong)uVar11;
            lVar3 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,*WdfDriverGlobals);
            for (lVar3 = *(longlong *)(lVar3 + 8); lVar3 != 0; lVar3 = *(longlong *)(lVar3 + 0x10))
            {
              local_res20 = (**(code **)(WdfFunctions_01015 + 0xf0))(WdfDriverGlobals,lVar3);
              lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                                (WdfDriverGlobals,local_res20,
                                 PTR__WDF_TCG_STORAGE_SILO_EXTENSION_TYPE_INFO_140019018);
              if (lVar7 != 0) {
                TcgSiloKsrSaveDeviceContext(local_res20,puVar10);
                puVar10 = (undefined8 *)((longlong)puVar10 + (ulonglong)uVar9);
              }
            }
          }
        }
        MmUnmapLockedPages(puVar5,lVar4);
      }
      ExFreePoolWithTag(lVar4,0);
      if (lVar6 == 0) {
        return iVar1;
      }
      ExFreePoolWithTag(lVar6,0);
      return iVar1;
    }
  }
  return -0x3ffffff2;
}



===== __security_init_cookie @ 14001e008 =====

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



===== DriverEntry @ 14001e03c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  longlong local_res18 [2];
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  ulonglong local_70;
  code *local_68;
  code *local_60;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 *local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 uStack_28;
  
  local_70 = (ulonglong)(uint)local_70;
  local_res18[1] = 0;
  wil_InitializeFeatureStaging();
  _WPP_MAIN_CB = 0;
  DAT_140019488 = &WPP_ThisDir_CTLGUID_WppCtrlGuid;
  DAT_140019490 = 0;
  _DAT_1400194a0 = 0;
  _DAT_1400194a8 = 1;
  WppLoadTracingSupport();
  _DAT_1400194a0 = 0;
  WppInitKm();
  McGenEventRegister_EtwRegister();
  local_70 = 0x20;
  local_68 = DriverEvtDeviceAdd;
  local_60 = DriverEvtUnload;
  local_58 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))
                    (WdfDriverGlobals,param_1,param_2,0,&local_70,local_res18 + 1);
  if (((iVar1 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_bb7d30cbb9e33959bf25838014b69456_Traceguids,iVar1);
  }
  local_88 = 0;
  local_4c = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_34 = 0;
  iVar2 = KsrGetFirmwareInformation(&local_88);
  if (-1 < iVar2) {
    local_res18[0] = 0;
    KsrEnumeratePersistedMemory
              (&GUID_TCG_SILO_KSR_CONTEXT,TcgSiloKsrEnumeratePersistedMemory,local_res18);
    if (local_res18[0] != 0) {
      iVar2 = TcgSiloKsrRestoreContext(local_res18[0]);
      if (iVar2 < 0) goto LAB_14001e211;
    }
    RtlInitUnicodeString(&local_80,L"\\Callback\\SoftRestart");
    local_40 = &local_80;
    local_50 = 0x30;
    local_48 = 0;
    local_38 = 0x50;
    local_30 = 0;
    uStack_28 = 0;
    iVar2 = ExCreateCallback(&TcgSiloKsrCallbackObject,&local_50,0,1);
    if (-1 < iVar2) {
      KsrCallbackHandle = ExRegisterCallback(TcgSiloKsrCallbackObject,TcgSiloKsrCallback,0);
    }
  }
LAB_14001e211:
  if (iVar1 < 0) {
    McGenEventUnregister_EtwUnregister();
    WppCleanupKm();
    if (g_wil_details_featureChangeNotification != 0) {
      RtlUnregisterFeatureConfigurationChangeNotification();
      g_wil_details_featureChangeNotification = 0;
    }
    if (g_wil_details_featureUsageProvider != 0) {
      RtlUnregisterFeatureUsageProvider();
      g_wil_details_featureUsageProvider = 0;
    }
    g_wil_details_isFeatureStagingInitialized = 0;
  }
  return iVar1;
}



===== wil_InitializeFeatureStaging @ 14001e280 =====

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
    for (ppuVar3 = &wil_details_featureDescriptors_a; ppuVar3 < &wil_details_featureDescriptors_z;
        ppuVar3 = ppuVar3 + 1) {
      if (*ppuVar3 != (undefined *)0x0) goto LAB_14001e307;
    }
LAB_14001e341:
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
LAB_14001e307:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14001e341;
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
    goto LAB_14001e341;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_140018667 < ppuVar3) goto LAB_14001e341;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14001e307;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14001e394 =====

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
  ppuVar4 = &wil_details_featureDescriptors_a;
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
            if (&UNK_140018667 < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_14001e47e;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_14001e47e;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_14001e47e:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_140018667 < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}



===== TcgSiloKsrEnumeratePersistedMemory @ 14001e510 =====

undefined8
TcgSiloKsrEnumeratePersistedMemory(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  *param_3 = param_2;
  return 0;
}



===== TcgSiloKsrRestoreContext @ 14001e520 =====

int TcgSiloKsrRestoreContext(undefined8 param_1)

{
  undefined8 uVar1;
  ulonglong uVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  void *_Src;
  uint uVar7;
  ulonglong uVar8;
  int iVar9;
  ulonglong uVar10;
  ulonglong *puVar11;
  uint local_res10 [2];
  undefined4 local_res18 [2];
  undefined4 uVar13;
  undefined4 *puVar12;
  
  local_res10[0] = 0;
  local_res18[0] = 0;
  KsrClaimPersistedMemory(&GUID_TCG_SILO_KSR_CONTEXT,param_1,0,0,0,local_res10);
  puVar4 = (undefined8 *)ExAllocatePool2(0x40,(ulonglong)local_res10[0] << 3,0x52534b53);
  if (puVar4 == (undefined8 *)0x0) {
    iVar3 = -0x3fffff66;
  }
  else {
    puVar12 = local_res18;
    iVar3 = KsrClaimPersistedMemory
                      (&GUID_TCG_SILO_KSR_CONTEXT,param_1,puVar4,local_res10[0],1,puVar12);
    uVar13 = (undefined4)((ulonglong)puVar12 >> 0x20);
    if (-1 < iVar3) {
      iVar9 = 0;
      if (local_res10[0] != 0) {
        uVar8 = (ulonglong)local_res10[0];
        puVar5 = puVar4;
        do {
          uVar1 = *puVar5;
          puVar5 = puVar5 + 1;
          iVar9 = iVar9 + (uint)((ulonglong)uVar1 >> 0x28);
          uVar8 = uVar8 - 1;
        } while (uVar8 != 0);
      }
      puVar5 = (undefined8 *)ExAllocatePool2(0x40,iVar9 * 8 + 0x30,0x52534b53);
      if (puVar5 == (undefined8 *)0x0) {
        iVar3 = -0x3fffff66;
      }
      else {
        *puVar5 = 0;
        puVar11 = puVar5 + 6;
        puVar5[4] = 0;
        *(undefined4 *)((longlong)puVar5 + 0x2c) = 0;
        *(int *)(puVar5 + 5) = iVar9 << 0xc;
        uVar8 = 0;
        *(short *)(puVar5 + 1) = ((short)iVar9 + 6) * 8;
        *(undefined2 *)((longlong)puVar5 + 10) = 2;
        if (local_res10[0] != 0) {
          do {
            uVar2 = puVar4[uVar8];
            uVar10 = uVar2 >> 0x28;
            uVar6 = uVar2 & 0xffffffffff;
            if ((uint)(uVar2 >> 0x28) != 0) {
              do {
                *puVar11 = uVar6;
                puVar11 = puVar11 + 1;
                uVar6 = uVar6 + 1;
                uVar10 = uVar10 - 1;
              } while (uVar10 != 0);
            }
            uVar7 = (int)uVar8 + 1;
            uVar8 = (ulonglong)uVar7;
          } while (uVar7 < local_res10[0]);
        }
        _Src = (void *)MmMapLockedPagesSpecifyCache(puVar5,0,1,0,0,CONCAT44(uVar13,0x40000020));
        if ((_Src == (void *)0x0) ||
           (KsrCachedContext =
                 (void *)ExAllocatePool2(0x40,*(undefined8 *)((longlong)_Src + 8),0x52534b53),
           KsrCachedContext == (void *)0x0)) {
          iVar3 = -0x3fffff66;
        }
        else {
          memmove(KsrCachedContext,_Src,*(size_t *)((longlong)_Src + 8));
        }
        ExFreePoolWithTag(puVar5,0);
      }
    }
    ExFreePoolWithTag(puVar4,0);
  }
  return iVar3;
}


