
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



===== __C_specific_handler @ 14000101d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000101d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== Feature_1271817531__private_IsEnabledDeviceUsageNoInline @ 140001030 =====

ulonglong Feature_1271817531__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_1271817531__private_featureState;
  if ((Feature_1271817531__private_featureState & 0x10) == 0) {
    uVar1 = Feature_1271817531__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_1271817531__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_1271817531__private_IsEnabledFallback @ 140001068 =====

void Feature_1271817531__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&wil_details_featureDescriptors_a);
  return;
}



===== Feature_3509484856__private_IsEnabledDeviceUsageNoInline @ 140001084 =====

ulonglong Feature_3509484856__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_3509484856__private_featureState;
  if ((Feature_3509484856__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3509484856__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3509484856__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3509484856__private_IsEnabledFallback @ 1400010bc =====

void Feature_3509484856__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_3509484856__private_descriptor);
  return;
}



===== GetIpAddress @ 1400010e0 =====

ulonglong GetIpAddress(int *param_1,uint param_2,undefined4 *param_3,ushort *param_4)

{
  ulonglong uVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  ushort *puVar6;
  
  uVar1 = (ulonglong)param_2;
  bVar2 = 0;
  if (param_2 < 0x16) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      uVar1 = WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                        &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,param_2,0x16);
    }
    uVar1 = uVar1 & 0xffffffffffffff00;
  }
  else {
    uVar3 = 8;
    puVar6 = (ushort *)(param_1 + 1);
    for (iVar4 = 0; iVar4 < *param_1; iVar4 = iVar4 + 1) {
      if ((puVar6[1] == 2) && (0xd < *puVar6)) {
        *param_3 = *(undefined4 *)(puVar6 + 3);
        *param_4 = puVar6[2];
        bVar2 = 1;
        break;
      }
      uVar3 = uVar3 + 4 + (uint)*puVar6;
      if (uVar1 < (ulonglong)uVar3 + 0xe) break;
      puVar6 = (ushort *)((longlong)puVar6 + (ulonglong)*puVar6 + 4);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      pcVar5 = "SUCCEEDED";
      if (bVar2 == 0) {
        pcVar5 = "FAILED";
      }
      WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
               &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,pcVar5);
    }
    uVar1 = (ulonglong)bVar2;
  }
  return uVar1;
}



===== PgmAddMCastReceiveIf @ 14000123c =====

ulonglong PgmAddMCastReceiveIf(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined1 uVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  undefined1 *puVar9;
  longlong *plVar10;
  undefined1 local_res8 [8];
  undefined1 local_res10 [8];
  
  lVar2 = *(longlong *)(param_1 + 0x18);
  plVar3 = *(longlong **)(*(longlong *)(param_2 + 0x30) + 0x18);
  if (*(uint *)(param_2 + 0x10) < 0x90) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
                &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,*(uint *)(param_2 + 0x10),0x90);
    }
    uVar5 = 0xc000000d;
  }
  else {
    uVar4 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
    local_res10[0] = uVar4;
    if ((plVar3 == (longlong *)0x0) || ((int)plVar3[2] != 0x52444441)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,plVar3);
      }
      KeReleaseSpinLock(&DAT_140036808,uVar4);
      uVar5 = 0xc0000008;
    }
    else {
      plVar1 = plVar3 + 0x37;
      local_res8[0] = KeAcquireSpinLockRaiseToDpc(plVar1);
      if (*(int *)(lVar2 + 4) == 0) {
        *(uint *)(plVar3 + 7) = *(uint *)(plVar3 + 7) | 4;
        KeReleaseSpinLock(plVar1,local_res8[0]);
        KeReleaseSpinLock(&DAT_140036808,uVar4);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,
                   &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,*(undefined4 *)(lVar2 + 4));
        }
        uVar5 = 0;
      }
      else {
        *(int *)((longlong)plVar3 + 0x14) = *(int *)((longlong)plVar3 + 0x14) + 1;
        plVar10 = (longlong *)local_res8;
        uVar6 = *(uint *)(lVar2 + 4);
        puVar9 = local_res10;
        uVar6 = uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18;
        uVar7 = (ulonglong)uVar6;
        uVar5 = ReceiverAddMCastIf((longlong)plVar3,uVar6,puVar9,(undefined1 *)plVar10);
        uVar8 = CONCAT71((int7)(uVar7 >> 8),local_res8[0]);
        KeReleaseSpinLock(plVar1,uVar8);
        uVar8 = CONCAT71((int7)((ulonglong)uVar8 >> 8),local_res10[0]);
        KeReleaseSpinLock(&DAT_140036808);
        PgmDereferenceAddress(plVar3,uVar8,puVar9,plVar10);
        if ((int)uVar5 < 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
            WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x41,
                      &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,(int)uVar5,
                      (char)*(undefined4 *)(lVar2 + 4));
          }
        }
        else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,
                   &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,*(undefined4 *)(lVar2 + 4));
        }
        uVar5 = uVar5 & 0xffffffff;
      }
    }
  }
  return uVar5;
}



===== PgmAssociateAddress @ 14000147c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 PgmAssociateAddress(undefined8 param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  code *pcVar5;
  longlong lVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  int iVar10;
  longlong lVar11;
  undefined8 uVar12;
  byte *pbVar13;
  byte *pbVar14;
  longlong lVar15;
  char *pcVar16;
  byte abStack_88 [8];
  undefined1 auStack_80 [24];
  undefined4 local_48;
  undefined2 local_44;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)abStack_88;
  plVar3 = *(longlong **)(*(longlong *)(param_3 + 0x30) + 0x18);
  local_48 = 0;
  local_44 = 0;
  iVar10 = ObReferenceObjectByHandle
                     (*(undefined8 *)(param_3 + 8),1,*(undefined8 *)IoFileObjectType_exref,
                      *(undefined1 *)(param_2 + 0x40));
  if (iVar10 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
               &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,*(undefined8 *)(param_3 + 8));
    }
  }
  else {
    uVar7 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
    lVar6 = lRam0000000000000018;
    if (((plVar3 == (longlong *)0x0) || ((int)plVar3[2] != 0x30534553)) || (plVar3[3] != 0)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,plVar3);
      }
      KeReleaseSpinLock(&DAT_140036808,uVar7);
    }
    else {
      if (((*(longlong *)(lRam0000000000000008 + 8) == DAT_140025d08) && (_DAT_00000020 == 1)) &&
         ((lRam0000000000000018 != 0 && (*(int *)(lRam0000000000000018 + 0x10) == 0x52444441)))) {
        lVar1 = lRam0000000000000018 + 0x1b8;
        uVar8 = KeAcquireSpinLockRaiseToDpc(lVar1);
        plVar2 = plVar3 + 0x2d;
        uVar9 = KeAcquireSpinLockRaiseToDpc(plVar2);
        lVar15 = 0x306d6750;
        if (*(int *)(lVar6 + 0x148) == 0) {
          lVar11 = ExAllocatePool2(0x40,0x3c0);
          pbVar14 = abStack_88;
          plVar3[5] = lVar11;
          if (lVar11 != 0) {
            *(longlong *)(lVar11 + 8) = lVar11;
            *(longlong *)lVar11 = lVar11;
            lVar15 = plVar3[5] + 0xf8;
            *(longlong *)(plVar3[5] + 0x100) = lVar15;
            *(longlong *)lVar15 = lVar15;
            lVar15 = plVar3[5] + 0xd8;
            *(longlong *)(plVar3[5] + 0xe0) = lVar15;
            *(longlong *)lVar15 = lVar15;
            ExInitializeResourceLite(plVar3[5] + 0x2e0);
            lVar11 = 6;
            *(undefined4 *)(plVar3 + 2) = 0x53534553;
            GetRandomData((longlong)&local_48,6);
            lVar15 = lVar6 - (longlong)plVar3;
            pbVar13 = (byte *)(plVar3 + 8);
            do {
              *pbVar13 = pbVar13[(longlong)(abStack_88 + -(longlong)plVar3)] ^
                         pbVar13[lVar15 + 0xa8];
              pbVar13 = pbVar13 + 1;
              lVar11 = lVar11 + -1;
            } while (lVar11 != 0);
            *(int *)((longlong)plVar3 + 0x14) = *(int *)((longlong)plVar3 + 0x14) + 1;
            goto LAB_140001755;
          }
        }
        else {
          lVar11 = ExAllocatePool2();
          pbVar14 = abStack_88;
          plVar3[6] = lVar11;
          if (lVar11 != 0) {
            *(longlong *)(lVar11 + 8) = lVar11;
            *(longlong *)lVar11 = lVar11;
            lVar11 = plVar3[6] + 0x88;
            *(longlong *)(plVar3[6] + 0x90) = lVar11;
            *(longlong *)lVar11 = lVar11;
            lVar11 = plVar3[6] + 200;
            *(longlong *)(plVar3[6] + 0xd0) = lVar11;
            *(longlong *)lVar11 = lVar11;
            lVar11 = plVar3[6] + 0x78;
            *(longlong *)(plVar3[6] + 0x80) = lVar11;
            *(longlong *)lVar11 = lVar11;
            lVar11 = plVar3[6] + 0xb8;
            *(longlong *)(plVar3[6] + 0xc0) = lVar11;
            *(longlong *)lVar11 = lVar11;
            lVar11 = plVar3[6] + 0x98;
            *(longlong *)(plVar3[6] + 0xa0) = lVar11;
            *(longlong *)lVar11 = lVar11;
            lVar11 = plVar3[6] + 0xa8;
            *(longlong *)(plVar3[6] + 0xb0) = lVar11;
            *(longlong *)lVar11 = lVar11;
            *(int *)((longlong)plVar3 + 0x14) = *(int *)((longlong)plVar3 + 0x14) + 1;
            *(undefined4 *)(plVar3 + 2) = 0x52534553;
            *(undefined4 *)(plVar3[6] + 0x28) = *(undefined4 *)(lVar6 + 0x148);
            *(undefined2 *)(plVar3[6] + 0x2c) = *(undefined2 *)(lVar6 + 0x14c);
            *(longlong **)(plVar3[6] + 0x10) = plVar3;
LAB_140001755:
            plVar3[3] = lVar6;
            lVar11 = *plVar3;
            if ((*(longlong **)(lVar11 + 8) == plVar3) &&
               (plVar4 = (longlong *)plVar3[1], (longlong *)*plVar4 == plVar3)) {
              *plVar4 = lVar11;
              *(longlong **)(lVar11 + 8) = plVar4;
              plVar4 = *(longlong **)(lVar6 + 0x20);
              if (*plVar4 == lVar6 + 0x18) {
                plVar3[1] = (longlong)plVar4;
                *plVar3 = lVar6 + 0x18;
                *plVar4 = (longlong)plVar3;
                *(longlong **)(lVar6 + 0x20) = plVar3;
                *(int *)(lVar6 + 0x14) = *(int *)(lVar6 + 0x14) + 1;
                KeReleaseSpinLock(plVar2,CONCAT71((int7)((ulonglong)plVar4 >> 8),uVar9));
                KeReleaseSpinLock(lVar1,uVar8);
                KeReleaseSpinLock(&DAT_140036808,uVar7);
                ObfDereferenceObject(0);
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
                  WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
                            &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,plVar3,(char)lVar6);
                }
                pbVar14 = abStack_88;
                uVar12 = 0;
                goto LAB_140001966;
              }
            }
            pcVar5 = (code *)swi(0x29);
            (*pcVar5)(3);
            pbVar14 = auStack_80;
          }
        }
        *(undefined8 *)(pbVar14 + -8) = 0x140001837;
        KeReleaseSpinLock(plVar2,uVar9);
        *(undefined8 *)(pbVar14 + -8) = 0x140001849;
        KeReleaseSpinLock(lVar1,uVar8);
        *(undefined8 *)(pbVar14 + -8) = 0x14000185f;
        KeReleaseSpinLock(&DAT_140036808,uVar7);
        *(undefined8 *)(pbVar14 + -8) = 0x14000186e;
        ObfDereferenceObject(0);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          uVar12 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
          pcVar16 = "pReceiver";
          if (*(int *)(lVar6 + 0x148) == 0) {
            pcVar16 = "pSender";
          }
          *(longlong **)(pbVar14 + 0x28) = plVar3;
          *(longlong *)(pbVar14 + 0x20) = lVar6;
          *(undefined8 *)(pbVar14 + -8) = 0x1400018b9;
          WPP_SF_sqq(uVar12,"pSender",lVar15,pcVar16,pbVar14[0x20],pbVar14[0x28]);
        }
        uVar12 = 0xc000009a;
        goto LAB_140001966;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,lRam0000000000000018);
      }
      KeReleaseSpinLock(&DAT_140036808,uVar7);
    }
    ObfDereferenceObject(0);
  }
  pbVar14 = abStack_88;
  uVar12 = 0xc0000008;
LAB_140001966:
  *(undefined8 *)(pbVar14 + -8) = 0x140001973;
  return uVar12;
}



===== PgmCleanupAddress @ 140001994 =====

undefined8 PgmCleanupAddress(longlong param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
               &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,param_1,
               (char)*(undefined8 *)(param_1 + 0x40),(char)*(undefined8 *)(param_1 + 0x48));
  }
  uVar1 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x1b8);
  *(undefined4 *)(param_1 + 0x10) = 0x32444441;
  KeReleaseSpinLock(param_1 + 0x1b8,uVar2);
  KeReleaseSpinLock(&DAT_140036808,uVar1);
  return 0;
}



===== PgmCloseAddress @ 140001a5c =====

undefined8 PgmCloseAddress(longlong param_1,longlong param_2,undefined8 param_3,longlong *param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong *plVar8;
  
  plVar1 = *(longlong **)(*(longlong *)(param_2 + 0x30) + 0x18);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
    param_4 = plVar1;
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,plVar1,
              (char)*(undefined4 *)((longlong)plVar1 + 0x14));
  }
  uVar4 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
  uVar5 = KeAcquireSpinLockRaiseToDpc(plVar1 + 0x37);
  lVar7 = *plVar1;
  plVar8 = (longlong *)CONCAT71((int7)((ulonglong)param_4 >> 8),uVar5);
  if ((*(longlong **)(lVar7 + 8) == plVar1) &&
     (plVar2 = (longlong *)plVar1[1], (longlong *)*plVar2 == plVar1)) {
    *plVar2 = lVar7;
    *(longlong **)(lVar7 + 8) = plVar2;
    if ((undefined *)*DAT_1400366d8 == &DAT_1400366d0) {
      *plVar1 = (longlong)&DAT_1400366d0;
      plVar1[1] = (longlong)DAT_1400366d8;
      uVar6 = CONCAT71(0x1400366,uVar5);
      *DAT_1400366d8 = (longlong)plVar1;
      DAT_1400366d8 = plVar1;
      plVar1[6] = param_1;
      KeReleaseSpinLock(plVar1 + 0x37,uVar6);
      uVar6 = CONCAT71((int7)((ulonglong)uVar6 >> 8),uVar4);
      KeReleaseSpinLock(&DAT_140036808);
      PgmDereferenceAddress(plVar1,uVar6,lVar7,plVar8);
      return 0x103;
    }
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  uVar6 = (*pcVar3)();
  return uVar6;
}



===== PgmCreateAddress @ 140001b74 =====

int PgmCreateAddress(ulonglong param_1,ulonglong param_2,longlong *param_3,longlong param_4)

{
  code *pcVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  undefined1 uVar5;
  char cVar6;
  int iVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong *plVar12;
  undefined8 uVar13;
  longlong *plVar14;
  undefined1 *puVar15;
  uint uVar16;
  ulonglong *puVar17;
  char *pcVar18;
  uint uVar19;
  ushort uVar20;
  ulonglong local_res8;
  ulonglong local_res10;
  longlong *local_res18;
  uint local_res20 [2];
  undefined1 auStackY_98 [8];
  undefined1 auStackY_90 [24];
  longlong *local_58;
  longlong *local_50;
  
  uVar19 = 0;
  local_res20[0] = 0;
  local_res8 = param_1 & 0xffffffffffff0000;
  local_58 = (longlong *)0x0;
  local_res10 = param_2 & 0xffffffffffffff00;
  local_res18 = param_3;
  uVar8 = PgmGetUserInfo(param_1,(longlong)param_3,&local_58,(undefined1 *)&local_res10);
  if ((((int)uVar8 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
             &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,(int)uVar8);
  }
  puVar17 = &local_res8;
  uVar9 = GetIpAddress((int *)((ulonglong)*(byte *)(param_4 + 5) + 9 + param_4),
                       (uint)*(ushort *)(param_4 + 6),local_res20,(ushort *)puVar17);
  uVar3 = local_res20[0];
  if ((char)uVar9 == '\0') {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
              &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids);
    }
    iVar7 = -0x3ffffdf9;
  }
  else {
    uVar20 = (ushort)local_res8 >> 8 | (ushort)local_res8 << 8;
    uVar16 = local_res20[0] >> 0x18 | (local_res20[0] & 0xff0000) >> 8 |
             (local_res20[0] & 0xff00) << 8 | local_res20[0] << 0x18;
    local_res20[0] = CONCAT22(local_res20[0]._2_2_,uVar20);
    if (uVar16 == 0) {
      if ((char)local_res10 != '\0') goto LAB_140001cda;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids);
      }
      iVar7 = -0x3fffffde;
    }
    else if ((byte)uVar3 < 0xe0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,uVar16);
      }
      iVar7 = -0x3fffffff;
    }
    else {
LAB_140001cda:
      uVar8 = 0x306d6750;
      plVar10 = (longlong *)ExAllocatePool2(0x40,0x1f0);
      local_50 = plVar10;
      if (plVar10 != (longlong *)0x0) {
        plVar10[1] = (longlong)plVar10;
        *plVar10 = (longlong)plVar10;
        plVar14 = plVar10 + 3;
        plVar10[4] = (longlong)plVar14;
        *plVar14 = (longlong)plVar14;
        plVar14 = plVar10 + 0x27;
        plVar10[0x28] = (longlong)plVar14;
        *plVar14 = (longlong)plVar14;
        uVar9 = Feature_3509484856__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar9 != 0) {
          plVar14 = plVar10 + 0x35;
          plVar10[0x36] = (longlong)plVar14;
          *plVar14 = (longlong)plVar14;
        }
        KeInitializeSpinLock(plVar10 + 0x37);
        *(int *)((longlong)plVar10 + 0x14) = *(int *)((longlong)plVar10 + 0x14) + 1;
        *(undefined4 *)(plVar10 + 2) = 0x52444441;
        lVar11 = PsGetCurrentProcess();
        plVar10[5] = lVar11;
        plVar10[0x1c] = (longlong)local_58;
        uVar9 = Feature_1271817531__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar9 != 0) {
          plVar10[6] = 0;
        }
        plVar14 = plVar10;
        iVar7 = TdiOpenAddressHandle
                          (plVar10 + 9,(longlong)plVar10,uVar8,puVar17,plVar10 + 8,plVar10 + 9,
                           plVar10 + 10);
        if (iVar7 < 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
            WPP_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                      &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,iVar7,(char)plVar10);
          }
          ExFreePoolWithTag(local_58,0);
          goto LAB_140001d39;
        }
        if (uVar16 == 0) {
          iVar7 = TdiOpenAddressHandle
                            (plVar10 + 0xc,0,uVar8,puVar17,plVar10 + 0xb,plVar10 + 0xc,plVar10 + 0xd
                            );
          if (iVar7 < 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
              WPP_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                        &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,iVar7,(char)plVar10);
            }
LAB_140002101:
            PgmDestroyAddress((longlong)plVar10,0,0);
            return iVar7;
          }
          uVar5 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
          puVar15 = auStackY_98;
          plVar10[0x22] = 0x38;
          plVar10[0x21] = 0x2bbfffffa88;
          plVar14 = &PgmDynamicConfig;
          plVar10[0x23] = 10000000;
          plVar10[0x24] = 0x15cc5b;
          *(undefined4 *)(plVar10 + 0x25) = 0xf;
          *(undefined4 *)((longlong)plVar10 + 0xfc) = 0;
          *(undefined1 *)(plVar10 + 0x26) = 1;
          *(undefined4 *)(plVar10 + 0x20) = 0xff;
          if ((undefined8 *)*DAT_1400366a8 != &PgmDynamicConfig) goto LAB_140002190;
        }
        else {
          *(uint *)(plVar10 + 0x29) = uVar16;
          *(ushort *)((longlong)plVar10 + 0x14c) = uVar20;
          plVar10[0x1c] = (longlong)local_58;
          uVar5 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
          puVar15 = auStackY_98;
          param_3 = (longlong *)0x0;
          local_res8 = CONCAT71(local_res8._1_7_,uVar5);
          if ((char)local_res10 == '\0') {
            if ((longlong **)DAT_1400366b0 != &DAT_1400366b0) {
              sVar2 = (ushort)local_res20[0];
              plVar12 = DAT_1400366b0;
              do {
                if ((uVar16 == *(uint *)(plVar12 + 0x29)) &&
                   (sVar2 == *(short *)((longlong)plVar12 + 0x14c))) {
                  uVar5 = KeAcquireSpinLockRaiseToDpc(plVar12 + 0x37);
                  *(int *)((longlong)plVar12 + 0x14) = *(int *)((longlong)plVar12 + 0x14) + 1;
                  uVar13 = CONCAT71((int7)((ulonglong)plVar14 >> 8),uVar5);
                  KeReleaseSpinLock(plVar12 + 0x37,uVar13);
                  uVar13 = CONCAT71((int7)((ulonglong)uVar13 >> 8),(undefined1)local_res8);
                  KeReleaseSpinLock(&DAT_140036808);
                  if (param_3 != (longlong *)0x0) {
                    PgmDereferenceAddress(param_3,uVar13,uVar8,(longlong *)puVar17);
                  }
                  plVar14 = *(longlong **)plVar12[0x1c];
                  cVar6 = RtlEqualSid(*local_58);
                  uVar4 = uVar19 + 1;
                  if (cVar6 == '\0') {
                    uVar4 = uVar19;
                  }
                  uVar19 = uVar4;
                  uVar5 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
                  local_res8 = CONCAT71(local_res8._1_7_,uVar5);
                  uVar9 = Feature_1271817531__private_IsEnabledDeviceUsageNoInline();
                  param_3 = plVar12;
                  if (((int)uVar9 == 0) || (plVar12[6] == 0)) goto LAB_140001f79;
                  uVar19 = 0;
                  plVar12 = DAT_1400366b0;
                }
                else {
LAB_140001f79:
                  plVar12 = (longlong *)*plVar12;
                }
                plVar10 = local_50;
              } while ((longlong **)plVar12 != &DAT_1400366b0);
              if (1 < uVar19) {
                uVar13 = CONCAT71((int7)((ulonglong)plVar14 >> 8),uVar5);
                KeReleaseSpinLock(&DAT_140036808);
                if (param_3 != (longlong *)0x0) {
                  PgmDereferenceAddress(param_3,uVar13,uVar8,(longlong *)puVar17);
                }
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
                  WPP_SF_dDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar13,uVar8,uVar19,
                             (char)(uVar3 >> 0x18),(char)local_res20[0]);
                }
                iVar7 = -0x3fffffde;
                goto LAB_140002101;
              }
            }
            uVar20 = (ushort)local_res20[0];
          }
          if ((longlong **)*DAT_1400366b8 == &DAT_1400366b0) {
            *plVar10 = (longlong)&DAT_1400366b0;
            uVar13 = CONCAT71((int7)((ulonglong)plVar14 >> 8),uVar5);
            plVar10[1] = (longlong)DAT_1400366b8;
            *DAT_1400366b8 = (longlong)plVar10;
            DAT_1400366b8 = plVar10;
            KeReleaseSpinLock(&DAT_140036808);
            if (param_3 != (longlong *)0x0) {
              PgmDereferenceAddress(param_3,uVar13,uVar8,(longlong *)puVar17);
            }
            param_3 = local_res18;
            goto LAB_140002031;
          }
LAB_140002190:
          plVar12 = (longlong *)0x3;
          pcVar1 = (code *)swi(0x29);
          uVar5 = (*pcVar1)();
          puVar15 = auStackY_90;
          DAT_1400366a8 = plVar12;
        }
        *plVar10 = (longlong)plVar14;
        plVar10[1] = (longlong)DAT_1400366a8;
        *DAT_1400366a8 = (longlong)plVar10;
        *(undefined8 *)(puVar15 + -8) = 0x1400021b4;
        DAT_1400366a8 = plVar10;
        KeReleaseSpinLock(&DAT_140036808,uVar5);
LAB_140002031:
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          uVar13 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
          pcVar18 = "Receiver";
          *(uint *)(puVar15 + 0x30) = (uint)uVar20;
          *(uint *)(puVar15 + 0x28) = uVar16;
          if (uVar16 == 0) {
            pcVar18 = "Sender";
          }
          *(longlong **)(puVar15 + 0x20) = plVar10;
          *(undefined8 *)(puVar15 + -8) = 0x140002079;
          WPP_SF_sqDD(uVar13,"Sender",uVar8,pcVar18,puVar15[0x20],puVar15[0x28],puVar15[0x30]);
        }
        *(longlong **)(param_3[6] + 0x18) = plVar10;
        *(undefined8 *)(param_3[6] + 0x20) = 1;
        return 0;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids);
      }
      iVar7 = -0x3fffff66;
    }
  }
  plVar10 = local_58;
LAB_140001d39:
  ExFreePoolWithTag(plVar10,0);
  return iVar7;
}



===== PgmDelMCastReceiveIf @ 1400021c4 =====

uint PgmDelMCastReceiveIf(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  uint uVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  longlong *plVar11;
  undefined2 uVar12;
  undefined1 *puVar13;
  uint uVar14;
  uint *puVar15;
  longlong *plVar16;
  uint uVar17;
  undefined4 local_res8 [2];
  uint local_res10;
  undefined4 local_res14;
  undefined1 auStackY_58 [8];
  undefined1 auStackY_50 [24];
  undefined4 uVar18;
  
  uVar8 = 0;
  lVar1 = *(longlong *)(param_1 + 0x18);
  local_res8[0] = 0;
  plVar2 = *(longlong **)(*(longlong *)(param_2 + 0x30) + 0x18);
  uVar9 = Feature_3509484856__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar9 == 0) {
    uVar8 = PgmDelMCastReceiveIf_old(param_1,param_2);
    return uVar8;
  }
  if (*(uint *)(param_2 + 0x10) < 0x90) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x49,
                &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,*(uint *)(param_2 + 0x10),0x90);
    }
    return 0xc000000d;
  }
  uVar6 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
  puVar13 = auStackY_58;
  if ((plVar2 == (longlong *)0x0) || (puVar13 = auStackY_58, (int)plVar2[2] != 0x52444441)) {
LAB_1400024dc:
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      uVar10 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      *(undefined8 *)(puVar13 + -8) = 0x14000250e;
      WPP_SF_i(uVar10,0x4a,&WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,plVar2);
    }
    *(undefined8 *)(puVar13 + -8) = 0x14000251f;
    KeReleaseSpinLock(&DAT_140036808,uVar6);
    return 0xc0000008;
  }
  if ((int)plVar2[0x29] == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4b,
               &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,plVar2);
    }
    uVar8 = 0xc00000bb;
LAB_140002399:
    KeReleaseSpinLock(&DAT_140036808,uVar6);
    return uVar8;
  }
  uVar17 = *(uint *)(lVar1 + 4);
  uVar14 = uVar17 >> 0x18 | (uVar17 & 0xff0000) >> 8 | (uVar17 & 0xff00) << 8 | uVar17 << 0x18;
  uVar10 = GetIpInterfaceIndexFromAddress(uVar14,local_res8);
  if ((int)uVar10 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4c,
                &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,(int)uVar10,(char)uVar17);
    }
    uVar8 = 0xc0000141;
    goto LAB_140002399;
  }
  plVar16 = plVar2 + 0x37;
  uVar7 = KeAcquireSpinLockRaiseToDpc(plVar16);
  plVar11 = PgmFindReceiverInterface(plVar2 + 0x35,uVar14);
  if (plVar11 == (longlong *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4d,
                &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,*(undefined4 *)(lVar1 + 4),
                (char)local_res8[0]);
    }
    KeReleaseSpinLock(plVar16,uVar7);
    goto LAB_140002399;
  }
  lVar3 = *plVar11;
  if ((*(longlong **)(lVar3 + 8) != plVar11) ||
     (plVar4 = (longlong *)plVar11[1], (longlong *)*plVar4 != plVar11)) {
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(3);
    puVar13 = auStackY_50;
    goto LAB_1400024dc;
  }
  *plVar4 = lVar3;
  *(longlong **)(lVar3 + 8) = plVar4;
  *(short *)((longlong)plVar2 + 0x14e) = *(short *)((longlong)plVar2 + 0x14e) + -1;
  *(int *)((longlong)plVar2 + 0x14) = *(int *)((longlong)plVar2 + 0x14) + 1;
  KeReleaseSpinLock(plVar16,uVar7);
  KeReleaseSpinLock(&DAT_140036808,uVar6);
  uVar8 = *(uint *)(plVar2 + 0x29);
  puVar15 = &local_res10;
  plVar16 = (longlong *)0x8;
  local_res10 = uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 << 0x18;
  local_res14 = *(undefined4 *)(lVar1 + 4);
  uVar8 = PgmSetTcpInfo(plVar2[8],7,puVar15,8);
  if ((int)uVar8 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) goto LAB_1400024b7;
    uVar12 = 0x4f;
    uVar6 = (undefined1)*(undefined4 *)(lVar1 + 4);
    uVar17 = uVar8;
    uVar18 = local_res8[0];
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) goto LAB_1400024b7;
    puVar15 = (uint *)(ulonglong)*(ushort *)((longlong)plVar2 + 0x14c);
    uVar12 = 0x4e;
    uVar6 = (undefined1)*(ushort *)((longlong)plVar2 + 0x14c);
    uVar17 = *(uint *)(plVar2 + 0x29);
    uVar18 = *(undefined4 *)(lVar1 + 4);
  }
  plVar16 = (longlong *)(ulonglong)uVar17;
  WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar12,puVar15,uVar17,uVar6,(char)uVar18);
LAB_1400024b7:
  uVar10 = 0;
  ExFreePoolWithTag(plVar11);
  PgmDereferenceAddress(plVar2,uVar10,puVar15,plVar16);
  return uVar8;
}



===== PgmDelMCastReceiveIf_old @ 140002548 =====

uint PgmDelMCastReceiveIf_old(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  uint uVar5;
  undefined8 uVar6;
  ushort uVar7;
  ushort uVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  longlong *plVar11;
  uint uVar12;
  undefined4 local_res8 [2];
  undefined8 local_res10;
  undefined4 uVar13;
  
  uVar5 = 0;
  lVar1 = *(longlong *)(param_1 + 0x18);
  local_res10 = 0;
  plVar2 = *(longlong **)(*(longlong *)(param_2 + 0x30) + 0x18);
  local_res8[0] = 0;
  if (*(uint *)(param_2 + 0x10) < 0x90) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,
                &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,*(uint *)(param_2 + 0x10),0x90);
    }
    uVar5 = 0xc000000d;
  }
  else {
    uVar3 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
    if ((plVar2 == (longlong *)0x0) || ((int)plVar2[2] != 0x52444441)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x43,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,plVar2);
      }
      KeReleaseSpinLock(&DAT_140036808,uVar3);
      uVar5 = 0xc0000008;
    }
    else {
      if ((int)plVar2[0x29] == 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x44,
                   &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,plVar2);
        }
        uVar5 = 0xc00000bb;
      }
      else {
        uVar12 = *(uint *)(lVar1 + 4);
        uVar6 = GetIpInterfaceIndexFromAddress
                          (uVar12 >> 0x18 | (uVar12 & 0xff0000) >> 8 | (uVar12 & 0xff00) << 8 |
                           uVar12 << 0x18,local_res8);
        if ((int)uVar6 < 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
            WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,
                      &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,(int)uVar6,(char)uVar12);
          }
          uVar5 = 0xc0000141;
        }
        else {
          plVar11 = plVar2 + 0x37;
          uVar4 = KeAcquireSpinLockRaiseToDpc(plVar11);
          uVar12 = *(uint *)(lVar1 + 4);
          uVar7 = 0;
          uVar8 = *(ushort *)((longlong)plVar2 + 0x14e);
          if (uVar8 != 0) {
            do {
              if (*(uint *)((longlong)plVar2 + (ulonglong)uVar7 * 4 + 0x150) ==
                  (uVar12 >> 0x18 | (uVar12 & 0xff0000) >> 8 | (uVar12 & 0xff00) << 8 |
                  uVar12 << 0x18)) {
                uVar8 = uVar8 - 1;
                uVar9 = (ulonglong)uVar8;
                *(ushort *)((longlong)plVar2 + 0x14e) = uVar8;
                if (uVar7 < uVar8) {
                  do {
                    uVar9 = (ulonglong)uVar7;
                    uVar7 = uVar7 + 1;
                    *(undefined4 *)((longlong)plVar2 + uVar9 * 4 + 0x150) =
                         *(undefined4 *)((longlong)plVar2 + uVar9 * 4 + 0x154);
                  } while (uVar7 < *(ushort *)((longlong)plVar2 + 0x14e));
                }
                *(int *)((longlong)plVar2 + 0x14) = *(int *)((longlong)plVar2 + 0x14) + 1;
                KeReleaseSpinLock(plVar11,CONCAT71((int7)(uVar9 >> 8),uVar4));
                KeReleaseSpinLock(&DAT_140036808,uVar3);
                uVar5 = *(uint *)(plVar2 + 0x29);
                puVar10 = &local_res10;
                plVar11 = (longlong *)0x8;
                uVar6 = 7;
                local_res10 = CONCAT44(*(undefined4 *)(lVar1 + 4),
                                       uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 |
                                       (uVar5 & 0xff00) << 8 | uVar5 << 0x18);
                uVar5 = PgmSetTcpInfo(plVar2[8],7,puVar10,8);
                if ((int)uVar5 < 0) {
                  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) goto LAB_140002837;
                  uVar6 = 0x48;
                  uVar3 = (undefined1)*(undefined4 *)(lVar1 + 4);
                  uVar12 = uVar5;
                  uVar13 = local_res8[0];
                }
                else {
                  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) goto LAB_140002837;
                  puVar10 = (undefined8 *)(ulonglong)*(ushort *)((longlong)plVar2 + 0x14c);
                  uVar6 = 0x47;
                  uVar3 = (undefined1)*(ushort *)((longlong)plVar2 + 0x14c);
                  uVar12 = *(uint *)(plVar2 + 0x29);
                  uVar13 = *(undefined4 *)(lVar1 + 4);
                }
                plVar11 = (longlong *)(ulonglong)uVar12;
                WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(short)uVar6,puVar10,uVar12,
                           uVar3,(char)uVar13);
LAB_140002837:
                PgmDereferenceAddress(plVar2,uVar6,puVar10,plVar11);
                return uVar5;
              }
              uVar7 = uVar7 + 1;
            } while (uVar7 < uVar8);
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
            WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,
                      &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,uVar12,(char)local_res8[0]);
          }
          KeReleaseSpinLock(plVar11,uVar4);
        }
      }
      KeReleaseSpinLock(&DAT_140036808,uVar3);
    }
  }
  return uVar5;
}



===== PgmDereferenceAddress @ 1400028a8 =====

void PgmDereferenceAddress
               (longlong *param_1,undefined8 param_2,undefined8 param_3,longlong *param_4)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  char cVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  longlong *plVar11;
  
  plVar11 = param_1 + 0x37;
  uVar6 = KeAcquireSpinLockRaiseToDpc(plVar11);
  piVar1 = (int *)((longlong)param_1 + 0x14);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    KeReleaseSpinLock(plVar11,uVar6);
    uVar6 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
    uVar7 = KeAcquireSpinLockRaiseToDpc(plVar11);
    uVar9 = Feature_1271817531__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar9 == 0) || (*(int *)((longlong)param_1 + 0x14) == 0)) {
      lVar2 = param_1[6];
      param_1[6] = 0;
      lVar3 = *param_1;
      if ((*(longlong **)(lVar3 + 8) != param_1) ||
         (plVar4 = (longlong *)param_1[1], (longlong *)*plVar4 != param_1)) {
        pcVar5 = (code *)swi(0x29);
        (*pcVar5)(3);
        pcVar5 = (code *)swi(3);
        (*pcVar5)();
        return;
      }
      *plVar4 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar4;
      KeReleaseSpinLock(plVar11,uVar7);
      KeReleaseSpinLock(&DAT_140036808);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        param_4 = param_1;
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,param_1);
      }
      cVar8 = KeGetCurrentIrql();
      if (cVar8 == '\0') {
        PgmDestroyAddress((longlong)param_1,0,0);
      }
      else {
        uVar10 = PgmQueueForDelayedExecution(PgmDestroyAddress,param_1,0,param_4,'\0');
        if ((int)uVar10 < 0) {
          ExInterlockedInsertTailList(&DAT_1400366c0,param_1);
        }
      }
      if (lVar2 == 0) {
        return;
      }
      *(undefined8 *)(*(longlong *)(*(longlong *)(lVar2 + 0xb8) + 0x30) + 0x18) = 0;
      PgmIoComplete(lVar2,0,0);
      return;
    }
    KeReleaseSpinLock(plVar11,uVar7);
    plVar11 = (longlong *)&DAT_140036808;
  }
  KeReleaseSpinLock(plVar11,uVar6);
  return;
}



===== PgmDestroyAddress @ 140002a90 =====

void PgmDestroyAddress(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 *puVar4;
  code *pcVar5;
  ulonglong uVar6;
  undefined1 *puVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar6 = Feature_3509484856__private_IsEnabledDeviceUsageNoInline();
  puVar7 = auStack_28;
  if ((int)uVar6 != 0) {
    plVar1 = (longlong *)(param_1 + 0x1a8);
    while (plVar2 = (longlong *)*plVar1, puVar7 = auStack_28, plVar2 != plVar1) {
      if (((longlong *)plVar2[1] != plVar1) ||
         (lVar3 = *plVar2, (longlong *)*(longlong *)(lVar3 + 8) != plVar2)) {
        pcVar5 = (code *)swi(0x29);
        (*pcVar5)(3);
        puVar7 = auStack_20;
        break;
      }
      *plVar1 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar1;
      ExFreePoolWithTag();
    }
  }
  lVar3 = *(longlong *)(param_1 + 0x58);
  if (lVar3 != 0) {
    puVar4 = *(undefined8 **)(param_1 + 0x60);
    *(undefined8 *)(puVar7 + -8) = 0x140002af4;
    CloseAddressHandles(lVar3,puVar4,param_3);
    *(undefined8 *)(param_1 + 0x58) = 0;
  }
  lVar3 = *(longlong *)(param_1 + 0x40);
  if (lVar3 != 0) {
    puVar4 = *(undefined8 **)(param_1 + 0x48);
    *(undefined8 *)(puVar7 + -8) = 0x140002b0b;
    CloseAddressHandles(lVar3,puVar4,param_3);
    *(undefined8 *)(param_1 + 0x40) = 0;
  }
  lVar3 = *(longlong *)(param_1 + 0xe0);
  if (lVar3 != 0) {
    *(undefined8 *)(puVar7 + -8) = 0x140002b25;
    ExFreePoolWithTag(lVar3,0);
    *(undefined8 *)(param_1 + 0xe0) = 0;
  }
  *(undefined8 *)(puVar7 + -8) = 0x140002b3e;
  ExFreePoolWithTag(param_1,0);
  return;
}



===== PgmDisassociateAddress @ 140002b58 =====

undefined8
PgmDisassociateAddress(longlong param_1,longlong param_2,undefined *param_3,longlong *param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined8 uVar10;
  undefined1 *puVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined1 auStackY_58 [8];
  undefined1 auStackY_50 [24];
  
  plVar2 = *(longlong **)(*(longlong *)(param_2 + 0x30) + 0x18);
  uVar7 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
  uVar12 = 0;
  uVar8 = 0;
  plVar1 = plVar2 + 2;
  if (plVar2 != (longlong *)0x0) {
    if ((((int)*plVar1 + 0xadacbaadU & 0xfeffffff) == 0) || ((int)*plVar1 == 0x32534553)) {
      plVar3 = (longlong *)plVar2[3];
      puVar11 = auStackY_58;
      if ((plVar3 != (longlong *)0x0) &&
         (puVar11 = auStackY_58, ((int)plVar3[2] + 0xcdbbbbbfU & 0xdfffffff) == 0)) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          param_3 = &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids;
          param_4 = plVar2;
          WPP_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
                     &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,plVar2,(char)plVar2[10],
                     (char)plVar3);
        }
        uVar8 = KeAcquireSpinLockRaiseToDpc(plVar3 + 0x37);
        uVar9 = KeAcquireSpinLockRaiseToDpc(plVar2 + 0x2d);
        plVar2[3] = 0;
        uVar13 = CONCAT71((int7)((ulonglong)param_3 >> 8),uVar9);
        lVar4 = *plVar2;
        if ((*(longlong **)(lVar4 + 8) == plVar2) &&
           (plVar5 = (longlong *)plVar2[1], (longlong *)*plVar5 == plVar2)) {
          *plVar5 = lVar4;
          *(longlong **)(lVar4 + 8) = plVar5;
          if (((int)*plVar1 + 0xadacbaadU & 0xfeffffff) == 0) {
            if ((undefined *)*DAT_1400366f8 == &DAT_1400366f0) {
              *plVar2 = (longlong)&DAT_1400366f0;
              plVar2[1] = (longlong)DAT_1400366f8;
              *DAT_1400366f8 = (longlong)plVar2;
              DAT_1400366f8 = plVar2;
LAB_140002cd8:
              if ((*(uint *)(plVar2 + 4) & 0x2400) == 0x2400) {
                plVar2[0xd] = param_1;
                uVar12 = 0x103;
              }
              else {
                *(uint *)(plVar2 + 4) = *(uint *)(plVar2 + 4) | 0x2000;
              }
              uVar10 = CONCAT71(0x24,uVar9);
              KeReleaseSpinLock(plVar2 + 0x2d,uVar10);
              uVar10 = CONCAT71((int7)((ulonglong)uVar10 >> 8),uVar8);
              KeReleaseSpinLock(plVar3 + 0x37,uVar10);
              uVar10 = CONCAT71((int7)((ulonglong)uVar10 >> 8),uVar7);
              KeReleaseSpinLock(&DAT_140036808);
              PgmDereferenceSessionCommon(plVar2,uVar10,uVar13,param_4);
              PgmDereferenceAddress(plVar3,uVar10,uVar13,param_4);
              return uVar12;
            }
          }
          else if ((undefined *)*DAT_140036708 == &DAT_140036700) {
            *plVar2 = (longlong)&DAT_140036700;
            plVar2[1] = (longlong)DAT_140036708;
            *DAT_140036708 = (longlong)plVar2;
            DAT_140036708 = plVar2;
            goto LAB_140002cd8;
          }
        }
        pcVar6 = (code *)swi(0x29);
        (*pcVar6)(3);
        puVar11 = auStackY_50;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        uVar12 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        *(longlong **)(puVar11 + 0x20) = plVar3;
        *(undefined8 *)(puVar11 + -8) = 0x140002d8c;
        WPP_SF_qq(uVar12,0x24,&WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,plVar2,puVar11[0x20])
        ;
      }
      goto LAB_140002dcb;
    }
  }
  puVar11 = auStackY_58;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (puVar11 = auStackY_58, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    if (plVar2 != (longlong *)0x0) {
      uVar8 = (undefined1)*plVar1;
    }
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
              &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,plVar2,uVar8);
    puVar11 = auStackY_58;
  }
LAB_140002dcb:
  *(undefined8 *)(puVar11 + -8) = 0x140002ddc;
  KeReleaseSpinLock(&DAT_140036808,uVar7);
  return 0xc0000008;
}



===== PgmFindReceiverInterface @ 140002e0c =====

undefined8 * PgmFindReceiverInterface(undefined8 *param_1,int param_2)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)*param_1;
  while( true ) {
    if (puVar1 == param_1) {
      return (undefined8 *)0x0;
    }
    if (*(int *)(puVar1 + 2) == param_2) break;
    puVar1 = (undefined8 *)*puVar1;
  }
  return puVar1;
}



===== PgmQueryFecInfo @ 140002e28 =====

undefined8 PgmQueryFecInfo(longlong param_1,longlong param_2)

{
  undefined2 *_Dst;
  longlong lVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  
  _Dst = *(undefined2 **)(param_1 + 0x18);
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18);
  if (*(uint *)(param_2 + 8) < 0x90) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x72,
                &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,*(uint *)(param_2 + 8),0x90);
    }
    uVar3 = 0xc000000d;
  }
  else {
    uVar2 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
    if ((lVar1 == 0) || (*(int *)(lVar1 + 0x10) != 0x52444441)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x73,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,lVar1);
      }
      KeReleaseSpinLock(&DAT_140036808,uVar2);
      uVar3 = 0xc0000008;
    }
    else if ((*(int *)(lVar1 + 0x148) == 0) &&
            (*(longlong **)(lVar1 + 0x18) == (longlong *)(lVar1 + 0x18))) {
      memset(_Dst,0,0x90);
      *_Dst = *(undefined2 *)(lVar1 + 300);
      *(undefined1 *)(_Dst + 2) = *(undefined1 *)(lVar1 + 0x130);
      _Dst[1] = *(undefined2 *)(lVar1 + 0x12e);
      *(byte *)((longlong)_Dst + 5) = *(byte *)(lVar1 + 0x131) & 1;
      KeReleaseSpinLock(&DAT_140036808,uVar2);
      uVar3 = 0;
      *(undefined8 *)(param_1 + 0x38) = 0x90;
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x74,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,lVar1);
      }
      KeReleaseSpinLock(&DAT_140036808,uVar2);
      uVar3 = 0xc00000bb;
    }
  }
  return uVar3;
}



===== PgmQueryHighSpeedOptimization @ 140002ff0 =====

undefined8 PgmQueryHighSpeedOptimization(longlong param_1,longlong param_2)

{
  uint *_Dst;
  longlong lVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  
  _Dst = *(uint **)(param_1 + 0x18);
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18);
  if (*(uint *)(param_2 + 8) < 0x90) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x79,
                &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,*(uint *)(param_2 + 8),0x90);
    }
    uVar3 = 0xc000000d;
  }
  else {
    uVar2 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
    if ((lVar1 == 0) || (*(int *)(lVar1 + 0x10) != 0x52444441)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7a,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,lVar1);
      }
      KeReleaseSpinLock(&DAT_140036808,uVar2);
      uVar3 = 0xc0000008;
    }
    else {
      memset(_Dst,0,0x90);
      *_Dst = *(uint *)(lVar1 + 0x38) >> 4 & 1;
      KeReleaseSpinLock(&DAT_140036808,uVar2);
      uVar3 = 0;
      *(undefined8 *)(param_1 + 0x38) = 0x90;
    }
  }
  return uVar3;
}



===== PgmQueryLateJoinerPercentage @ 140003130 =====

undefined8 PgmQueryLateJoinerPercentage(longlong param_1,longlong param_2)

{
  undefined4 *_Dst;
  longlong lVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  
  _Dst = *(undefined4 **)(param_1 + 0x18);
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18);
  if (*(uint *)(param_2 + 8) < 0x90) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x61,
                &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,*(uint *)(param_2 + 8),0x90);
    }
    uVar3 = 0xc000000d;
  }
  else {
    uVar2 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
    if ((lVar1 == 0) || (*(int *)(lVar1 + 0x10) != 0x52444441)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x62,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,lVar1);
      }
      KeReleaseSpinLock(&DAT_140036808,uVar2);
      uVar3 = 0xc0000008;
    }
    else if (*(int *)(lVar1 + 0x148) == 0) {
      memset(_Dst,0,0x90);
      *_Dst = *(undefined4 *)(lVar1 + 0xfc);
      KeReleaseSpinLock(&DAT_140036808,uVar2);
      uVar3 = 0;
      *(undefined8 *)(param_1 + 0x38) = 0x90;
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),99,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,lVar1);
      }
      KeReleaseSpinLock(&DAT_140036808,uVar2);
      uVar3 = 0xc00000bb;
    }
  }
  return uVar3;
}



===== PgmQueryReceiverStats @ 1400032d0 =====

undefined8 PgmQueryReceiverStats(longlong param_1,longlong param_2)

{
  undefined8 *_Dst;
  longlong lVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined8 uVar4;
  
  _Dst = *(undefined8 **)(param_1 + 0x18);
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18);
  if (*(uint *)(param_2 + 8) < 0x90) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x80,
                &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,*(uint *)(param_2 + 8),0x90);
    }
    uVar4 = 0xc000000d;
  }
  else {
    uVar2 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
    if ((((lVar1 == 0) || (*(int *)(lVar1 + 0x10) != 0x52534553)) ||
        (*(longlong *)(lVar1 + 0x30) == 0)) || (*(longlong *)(lVar1 + 0x18) == 0)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x81,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,lVar1);
      }
      KeReleaseSpinLock(&DAT_140036808,uVar2);
      uVar4 = 0xc0000008;
    }
    else {
      uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x168);
      memset(_Dst,0,0x90);
      *_Dst = *(undefined8 *)(*(longlong *)(lVar1 + 0x30) + 0x348);
      _Dst[1] = *(undefined8 *)(*(longlong *)(lVar1 + 0x30) + 0x350);
      _Dst[2] = *(longlong *)(*(longlong *)(lVar1 + 0x30) + 0x368) +
                *(longlong *)(*(longlong *)(lVar1 + 0x30) + 0x360);
      _Dst[3] = *(undefined8 *)(lVar1 + 0xb8);
      _Dst[4] = *(undefined8 *)(lVar1 + 0xc0);
      _Dst[6] = *(undefined8 *)(lVar1 + 0xd0);
      _Dst[5] = *(undefined8 *)(lVar1 + 0xe0);
      _Dst[7] = (ulonglong)*(uint *)(*(longlong *)(lVar1 + 0x30) + 0x30);
      _Dst[8] = (ulonglong)*(uint *)(*(longlong *)(lVar1 + 0x30) + 0x3c);
      _Dst[9] = *(undefined8 *)(*(longlong *)(lVar1 + 0x30) + 0x308);
      _Dst[10] = *(undefined8 *)(*(longlong *)(lVar1 + 0x30) + 0x2f0);
      _Dst[0xb] = *(undefined8 *)(*(longlong *)(lVar1 + 0x30) + 0x2f8);
      _Dst[0xc] = (ulonglong)*(uint *)(*(longlong *)(lVar1 + 0x30) + 0x38);
      _Dst[0xd] = *(undefined8 *)(*(longlong *)(lVar1 + 0x30) + 0x370);
      _Dst[0xe] = *(undefined8 *)(*(longlong *)(lVar1 + 0x30) + 0x378);
      _Dst[0xf] = (ulonglong)*(uint *)(*(longlong *)(lVar1 + 0x30) + 0x104);
      _Dst[0x10] = *(undefined8 *)(*(longlong *)(lVar1 + 0x30) + 0x380);
      uVar4 = *(undefined8 *)(*(longlong *)(lVar1 + 0x30) + 0x388);
      _Dst[0x11] = uVar4;
      KeReleaseSpinLock(lVar1 + 0x168,CONCAT71((int7)((ulonglong)uVar4 >> 8),uVar3));
      KeReleaseSpinLock(&DAT_140036808,uVar2);
      uVar4 = 0;
      *(undefined8 *)(param_1 + 0x38) = 0x90;
    }
  }
  return uVar4;
}



===== PgmQuerySenderStats @ 140003550 =====

undefined8 PgmQuerySenderStats(longlong param_1,longlong param_2)

{
  uint uVar1;
  undefined8 *_Dst;
  longlong lVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined8 uVar5;
  
  _Dst = *(undefined8 **)(param_1 + 0x18);
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18);
  if (*(uint *)(param_2 + 8) < 0x90) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7e,
                &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,*(uint *)(param_2 + 8),0x90);
    }
    uVar5 = 0xc000000d;
  }
  else {
    uVar3 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
    if ((((lVar2 == 0) || (*(int *)(lVar2 + 0x10) != 0x53534553)) ||
        (*(longlong *)(lVar2 + 0x28) == 0)) || (*(longlong *)(lVar2 + 0x18) == 0)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7f,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,lVar2);
      }
      KeReleaseSpinLock(&DAT_140036808,uVar3);
      uVar5 = 0xc0000008;
    }
    else {
      uVar4 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x168);
      memset(_Dst,0,0x90);
      *_Dst = *(undefined8 *)(lVar2 + 0xb8);
      _Dst[1] = *(undefined8 *)(lVar2 + 0xc0);
      _Dst[0xb] = *(undefined8 *)(lVar2 + 0xd0);
      _Dst[10] = *(undefined8 *)(lVar2 + 0xe0);
      _Dst[2] = *(undefined8 *)(*(longlong *)(lVar2 + 0x28) + 0x358);
      _Dst[3] = *(undefined8 *)(*(longlong *)(lVar2 + 0x28) + 0x360);
      _Dst[4] = *(undefined8 *)(*(longlong *)(lVar2 + 0x28) + 0x368);
      _Dst[5] = *(undefined8 *)(*(longlong *)(lVar2 + 0x28) + 0x370);
      _Dst[6] = *(undefined8 *)(*(longlong *)(lVar2 + 0x28) + 0x380);
      _Dst[0xc] = *(undefined8 *)(*(longlong *)(lVar2 + 0x28) + 0x378);
      _Dst[7] = *(undefined8 *)(*(longlong *)(lVar2 + 0x28) + 0x78);
      _Dst[8] = (ulonglong)*(uint *)(*(longlong *)(lVar2 + 0x28) + 0xa0);
      uVar1 = *(uint *)(*(longlong *)(lVar2 + 0x28) + 0x9c);
      _Dst[9] = (ulonglong)uVar1;
      KeReleaseSpinLock(lVar2 + 0x168,CONCAT31((int3)(uVar1 >> 8),uVar4));
      KeReleaseSpinLock(&DAT_140036808,uVar3);
      uVar5 = 0;
      *(undefined8 *)(param_1 + 0x38) = 0x90;
    }
  }
  return uVar5;
}



===== PgmQueryWindowAdvanceMethod @ 140003780 =====

undefined8 PgmQueryWindowAdvanceMethod(longlong param_1,longlong param_2)

{
  int *_Dst;
  longlong lVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  
  _Dst = *(int **)(param_1 + 0x18);
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18);
  if (*(uint *)(param_2 + 8) < 0x90) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x67,
                &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,*(uint *)(param_2 + 8),0x90);
    }
    uVar3 = 0xc000000d;
  }
  else {
    uVar2 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
    if ((lVar1 == 0) || (*(int *)(lVar1 + 0x10) != 0x52444441)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x68,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,lVar1);
      }
      KeReleaseSpinLock(&DAT_140036808,uVar2);
      uVar3 = 0xc0000008;
    }
    else if (*(int *)(lVar1 + 0x148) == 0) {
      memset(_Dst,0,0x90);
      *_Dst = ((*(uint *)(lVar1 + 0x38) & 2) != 0) + 1;
      KeReleaseSpinLock(&DAT_140036808,uVar2);
      uVar3 = 0;
      *(undefined8 *)(param_1 + 0x38) = 0x90;
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x69,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,lVar1);
      }
      KeReleaseSpinLock(&DAT_140036808,uVar2);
      uVar3 = 0xc00000bb;
    }
  }
  return uVar3;
}



===== PgmQueryWindowAdvanceRate @ 140003924 =====

undefined8 PgmQueryWindowAdvanceRate(longlong param_1,longlong param_2)

{
  undefined4 *_Dst;
  longlong lVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  
  _Dst = *(undefined4 **)(param_1 + 0x18);
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18);
  if (*(uint *)(param_2 + 8) < 0x90) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5b,
                &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,*(uint *)(param_2 + 8),0x90);
    }
    uVar3 = 0xc000000d;
  }
  else {
    uVar2 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
    if ((lVar1 == 0) || (*(int *)(lVar1 + 0x10) != 0x52444441)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5c,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,lVar1);
      }
      KeReleaseSpinLock(&DAT_140036808,uVar2);
      uVar3 = 0xc0000008;
    }
    else if (*(int *)(lVar1 + 0x148) == 0) {
      memset(_Dst,0,0x90);
      *_Dst = *(undefined4 *)(lVar1 + 0x128);
      KeReleaseSpinLock(&DAT_140036808,uVar2);
      uVar3 = 0;
      *(undefined8 *)(param_1 + 0x38) = 0x90;
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5d,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,lVar1);
      }
      KeReleaseSpinLock(&DAT_140036808,uVar2);
      uVar3 = 0xc00000bb;
    }
  }
  return uVar3;
}



===== PgmQueryWindowSizeAndSendRate @ 140003ac4 =====

undefined8 PgmQueryWindowSizeAndSendRate(longlong param_1,longlong param_2)

{
  undefined4 *_Dst;
  longlong lVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  
  _Dst = *(undefined4 **)(param_1 + 0x18);
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18);
  if (*(uint *)(param_2 + 8) < 0x90) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x55,
                &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,*(uint *)(param_2 + 8),0x90);
    }
    uVar3 = 0xc000000d;
  }
  else {
    uVar2 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
    if ((lVar1 == 0) || (*(int *)(lVar1 + 0x10) != 0x52444441)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x56,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,lVar1);
      }
      KeReleaseSpinLock(&DAT_140036808,uVar2);
      uVar3 = 0xc0000008;
    }
    else if (*(int *)(lVar1 + 0x148) == 0) {
      memset(_Dst,0,0x90);
      *_Dst = *(undefined4 *)(lVar1 + 0x110);
      _Dst[2] = *(undefined4 *)(lVar1 + 0x118);
      _Dst[1] = *(undefined4 *)(lVar1 + 0x120);
      KeReleaseSpinLock(&DAT_140036808,uVar2);
      uVar3 = 0;
      *(undefined8 *)(param_1 + 0x38) = 0x90;
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x57,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,lVar1);
      }
      KeReleaseSpinLock(&DAT_140036808,uVar2);
      uVar3 = 0xc00000bb;
    }
  }
  return uVar3;
}



===== PgmSetEventHandler @ 140003c74 =====

int PgmSetEventHandler(undefined8 param_1,undefined8 ****param_2,ulonglong *param_3)

{
  uint uVar1;
  code *pcVar2;
  longlong *plVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  int iVar6;
  code *pcVar7;
  code *pcVar8;
  code *pcVar9;
  code *pcVar10;
  code *pcVar11;
  undefined8 uVar12;
  code *pcVar13;
  code *pcVar14;
  ulonglong uVar15;
  ulonglong *puVar16;
  longlong *plVar17;
  ulonglong local_res8;
  undefined8 ****local_res10;
  
  uVar15 = param_3[3];
  pcVar2 = (code *)param_3[2];
  iVar6 = 0;
  plVar3 = *(longlong **)(param_3[6] + 0x18);
  puVar16 = param_3;
  local_res8 = uVar15;
  local_res10 = param_2;
  uVar4 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
  local_res10 = (undefined8 ****)CONCAT71(local_res10._1_7_,uVar4);
  if ((plVar3 == (longlong *)0x0) || ((int)plVar3[2] != 0x52444441)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
               &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,plVar3);
    }
    KeReleaseSpinLock(&DAT_140036808,uVar4);
    return -0x3ffffff8;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
    param_2 = (undefined8 *****)0x0;
    puVar16 = (ulonglong *)&WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids;
    WPP_SF_Dqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,
               &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,(int)param_3[1],(char)pcVar2,
               (char)uVar15);
  }
  uVar15 = -(ulonglong)(pcVar2 != (code *)0x0) & local_res8;
  uVar5 = KeAcquireSpinLockRaiseToDpc(plVar3 + 0x37);
  *(int *)((longlong)plVar3 + 0x14) = *(int *)((longlong)plVar3 + 0x14) + 1;
  pcVar11 = TdiDefaultConnectHandler_exref;
  pcVar10 = TdiDefaultDisconnectHandler_exref;
  pcVar9 = TdiDefaultErrorHandler_exref;
  pcVar8 = TdiDefaultReceiveHandler_exref;
  pcVar7 = TdiDefaultRcvDatagramHandler_exref;
  pcVar13 = TdiDefaultRcvExpeditedHandler_exref;
  pcVar14 = TdiDefaultSendPossibleHandler_exref;
  uVar1 = (uint)param_3[1];
  plVar17 = (longlong *)(ulonglong)uVar1;
  local_res8 = CONCAT71(local_res8._1_7_,uVar5);
  if ((int)uVar1 < 6) {
    if (uVar1 == 5) {
      plVar3[0x19] = uVar15;
      if (pcVar2 != (code *)0x0) {
        pcVar13 = pcVar2;
      }
      plVar3[0x18] = (longlong)pcVar13;
      goto LAB_140003fa5;
    }
    if (uVar1 == 0) {
      if ((int)plVar3[0x29] == 0) {
        KeReleaseSpinLock(plVar3 + 0x37,uVar5);
        KeReleaseSpinLock(&DAT_140036808,uVar4);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,
                   &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,plVar3);
        }
        return -0x3fffffff;
      }
      plVar3[0xf] = uVar15;
      if (pcVar2 != (code *)0x0) {
        pcVar11 = pcVar2;
      }
      plVar3[0xe] = (longlong)pcVar11;
      if (*(short *)((longlong)plVar3 + 0x14e) == 0) {
        if ((undefined8 **)DAT_140036720 != &DAT_140036720) {
          puVar16 = &local_res8;
          param_2 = &local_res10;
          uVar12 = ListenOnAllInterfaces
                             ((longlong)plVar3,(undefined1 *)param_2,(undefined1 *)puVar16);
          iVar6 = (int)uVar12;
          if (iVar6 < 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
              param_2 = (undefined8 *****)0x0;
              puVar16 = (ulonglong *)&WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids;
              plVar17 = plVar3;
              WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,
                        &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,plVar3,(char)uVar12);
            }
          }
          else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  (param_2 = (undefined8 ****)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
                  (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
            param_2 = (undefined8 *****)0x0;
            puVar16 = (ulonglong *)&WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids;
            plVar17 = plVar3;
            WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,
                     &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,plVar3);
          }
          uVar4 = local_res10._0_1_;
        }
        *(uint *)(plVar3 + 7) = *(uint *)(plVar3 + 7) | 0xc;
      }
      goto LAB_140003fa5;
    }
    if (uVar1 == 1) {
      plVar3[0x13] = uVar15;
      if (pcVar2 != (code *)0x0) {
        pcVar10 = pcVar2;
      }
      plVar3[0x12] = (longlong)pcVar10;
      goto LAB_140003fa5;
    }
    if (uVar1 == 2) {
      plVar3[0x15] = uVar15;
      if (pcVar2 != (code *)0x0) {
        pcVar9 = pcVar2;
      }
      plVar3[0x14] = (longlong)pcVar9;
      goto LAB_140003fa5;
    }
    if (uVar1 == 3) {
      plVar3[0x11] = uVar15;
      if (pcVar2 != (code *)0x0) {
        pcVar8 = pcVar2;
      }
      plVar3[0x10] = (longlong)pcVar8;
      goto LAB_140003fa5;
    }
    if (uVar1 == 4) {
      plVar3[0x17] = uVar15;
      if (pcVar2 != (code *)0x0) {
        pcVar7 = pcVar2;
      }
      plVar3[0x16] = (longlong)pcVar7;
      goto LAB_140003fa5;
    }
  }
  else {
    if (uVar1 == 6) {
      plVar3[0x1b] = uVar15;
      if (pcVar2 != (code *)0x0) {
        pcVar14 = pcVar2;
      }
      plVar3[0x1a] = (longlong)pcVar14;
      goto LAB_140003fa5;
    }
    if ((((uVar1 == 7) || (uVar1 == 8)) || (uVar1 == 9)) || (uVar1 == 10)) {
      iVar6 = -0x3fffff45;
      goto LAB_140003fa5;
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    param_2 = (undefined8 *****)0x0;
    puVar16 = (ulonglong *)&WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids;
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
             &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,uVar1);
  }
  iVar6 = -0x3fffffff;
LAB_140003fa5:
  uVar12 = CONCAT71((int7)((ulonglong)param_2 >> 8),(undefined1)local_res8);
  KeReleaseSpinLock(plVar3 + 0x37,uVar12);
  uVar12 = CONCAT71((int7)((ulonglong)uVar12 >> 8),uVar4);
  KeReleaseSpinLock(&DAT_140036808);
  PgmDereferenceAddress(plVar3,uVar12,puVar16,plVar17);
  return iVar6;
}



===== PgmSetFECInfo @ 14000404c =====

undefined8 PgmSetFECInfo(longlong param_1,longlong param_2)

{
  ushort uVar1;
  ushort *puVar2;
  longlong lVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  byte bVar6;
  undefined8 uVar7;
  
  puVar2 = *(ushort **)(param_1 + 0x18);
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18);
  if (*(uint *)(param_2 + 0x10) < 0x90) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6e,
                &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,*(uint *)(param_2 + 0x10),0x90);
    }
    return 0xc000000d;
  }
  uVar4 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
  uVar7 = 0;
  if ((lVar3 == 0) || (*(int *)(lVar3 + 0x10) != 0x52444441)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6f,
               &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,lVar3);
    }
    uVar7 = 0xc0000008;
LAB_140004281:
    KeReleaseSpinLock(&DAT_140036808,uVar4);
    return uVar7;
  }
  if ((*(int *)(lVar3 + 0x148) != 0) || (*(longlong **)(lVar3 + 0x18) != (longlong *)(lVar3 + 0x18))
     ) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x70,
               &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,lVar3);
    }
    uVar7 = 0xc00000bb;
    goto LAB_140004281;
  }
  uVar5 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x1b8);
  if (((puVar2[1] != 0) || (*(char *)((longlong)puVar2 + 5) != '\0')) &&
     (uVar1 = *puVar2, uVar1 != 0)) {
    bVar6 = (byte)puVar2[2];
    if ((((bVar6 != 0) && (uVar1 < 0x100)) && (bVar6 < uVar1)) && ((&gFECLog2)[bVar6] != '\0')) {
      *(ushort *)(lVar3 + 300) = uVar1;
      bVar6 = 0;
      *(char *)(lVar3 + 0x130) = (char)puVar2[2];
      *(undefined1 *)(lVar3 + 0x131) = 0;
      if (puVar2[1] != 0) {
        bVar6 = 2;
        *(ushort *)(lVar3 + 0x12e) = puVar2[1];
        *(undefined1 *)(lVar3 + 0x131) = 2;
      }
      if (*(char *)((longlong)puVar2 + 5) != '\0') {
        *(byte *)(lVar3 + 0x131) = bVar6 | 1;
      }
      goto LAB_1400041da;
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x71,
              &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,(uint)*puVar2,(char)puVar2[2]);
  }
  uVar7 = 0xc000000d;
LAB_1400041da:
  KeReleaseSpinLock(lVar3 + 0x1b8,uVar5);
  KeReleaseSpinLock(&DAT_140036808,uVar4);
  return uVar7;
}



===== PgmSetHighSpeedOptimization @ 1400042bc =====

undefined8 PgmSetHighSpeedOptimization(longlong param_1,longlong param_2)

{
  int *piVar1;
  longlong lVar2;
  uint uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined8 uVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  
  piVar1 = *(int **)(param_1 + 0x18);
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18);
  if (*(uint *)(param_2 + 0x10) < 0x90) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7b,
                &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,*(uint *)(param_2 + 0x10),0x90);
    }
    uVar6 = 0xc000000d;
  }
  else {
    uVar4 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
    if ((lVar2 == 0) || (*(int *)(lVar2 + 0x10) != 0x52444441)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7c,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,lVar2);
      }
      KeReleaseSpinLock(&DAT_140036808,uVar4);
      uVar6 = 0xc0000008;
    }
    else {
      uVar5 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x1b8);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        pcVar9 = "";
        pcVar8 = "";
        if (*piVar1 == 0) {
          pcVar8 = "Not ";
        }
        if ((*(uint *)(lVar2 + 0x38) & 0x10) == 0) {
          pcVar9 = "Not ";
        }
        WPP_SF_ss(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7d,
                  &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,pcVar9,pcVar8);
      }
      uVar7 = *(uint *)(lVar2 + 0x38) & 0xffffffef;
      uVar3 = *(uint *)(lVar2 + 0x38) | 0x10;
      if (*piVar1 == 0) {
        uVar3 = uVar7;
      }
      *(uint *)(lVar2 + 0x38) = uVar3;
      KeReleaseSpinLock(lVar2 + 0x1b8,CONCAT31((int3)(uVar7 >> 8),uVar5));
      KeReleaseSpinLock(&DAT_140036808,uVar4);
      uVar6 = 0;
    }
  }
  return uVar6;
}



===== PgmSetLateJoinerPercentage @ 140004480 =====

undefined8 PgmSetLateJoinerPercentage(longlong param_1,longlong param_2)

{
  uint *puVar1;
  longlong lVar2;
  undefined1 uVar3;
  undefined8 uVar4;
  
  puVar1 = *(uint **)(param_1 + 0x18);
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18);
  if (*(uint *)(param_2 + 0x10) < 0x90) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5e,
                &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,*(uint *)(param_2 + 0x10),0x90);
    }
    uVar4 = 0xc000000d;
  }
  else {
    uVar3 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
    uVar4 = 0;
    if ((lVar2 == 0) || (*(int *)(lVar2 + 0x10) != 0x52444441)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5f,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,lVar2);
      }
      uVar4 = 0xc0000008;
    }
    else {
      if ((*(int *)(lVar2 + 0x148) == 0) &&
         (*(longlong **)(lVar2 + 0x18) == (longlong *)(lVar2 + 0x18))) {
        if (*puVar1 < 0x4c) {
          *(uint *)(lVar2 + 0xfc) = *puVar1;
        }
        else {
          uVar4 = 0xc000000d;
        }
        KeReleaseSpinLock(&DAT_140036808,uVar3);
        return uVar4;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x60,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,lVar2);
      }
      uVar4 = 0xc00000bb;
    }
    KeReleaseSpinLock(&DAT_140036808,uVar3);
  }
  return uVar4;
}



===== PgmSetMCastOutIf @ 140004600 =====

int PgmSetMCastOutIf(longlong param_1,longlong param_2)

{
  uint uVar1;
  uint *puVar2;
  longlong *plVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  int iVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  longlong *plVar9;
  
  uVar8 = 0x90;
  uVar1 = *(uint *)(param_2 + 0x10);
  plVar9 = (longlong *)(ulonglong)uVar1;
  puVar2 = *(uint **)(param_1 + 0x18);
  plVar3 = *(longlong **)(*(longlong *)(param_2 + 0x30) + 0x18);
  if (uVar1 < 0x90) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
                &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,uVar1,0x90);
    }
    iVar6 = -0x3ffffff3;
  }
  else {
    uVar4 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
    if ((plVar3 == (longlong *)0x0) || ((int)plVar3[2] != 0x52444441)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,plVar3);
      }
      KeReleaseSpinLock(&DAT_140036808,uVar4);
      iVar6 = -0x3ffffff8;
    }
    else if ((int)plVar3[0x29] == 0) {
      uVar5 = KeAcquireSpinLockRaiseToDpc(plVar3 + 0x37);
      *(int *)((longlong)plVar3 + 0x14) = *(int *)((longlong)plVar3 + 0x14) + 1;
      KeReleaseSpinLock(plVar3 + 0x37,uVar5);
      KeReleaseSpinLock(&DAT_140036808,uVar4);
      uVar7 = (ulonglong)*puVar2;
      iVar6 = SetSenderMCastOutIf((longlong)plVar3,*puVar2);
      PgmDereferenceAddress(plVar3,uVar7,uVar8,plVar9);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,(int)plVar3[0x1e]);
      }
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,plVar3);
      }
      KeReleaseSpinLock(&DAT_140036808,uVar4);
      iVar6 = -0x3fffff45;
    }
  }
  return iVar6;
}



===== PgmSetMCastTtl @ 1400047f0 =====

undefined8 PgmSetMCastTtl(longlong param_1,longlong param_2)

{
  int iVar1;
  int *piVar2;
  longlong lVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined8 uVar6;
  
  piVar2 = *(int **)(param_1 + 0x18);
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18);
  if (*(uint *)(param_2 + 0x10) < 0x90) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x75,
                &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,*(uint *)(param_2 + 0x10),0x90);
    }
    uVar6 = 0xc000000d;
  }
  else {
    uVar4 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
    uVar6 = 0;
    if ((lVar3 == 0) || (*(int *)(lVar3 + 0x10) != 0x52444441)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x76,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,lVar3);
      }
      KeReleaseSpinLock(&DAT_140036808,uVar4);
      uVar6 = 0xc0000008;
    }
    else if (*(int *)(lVar3 + 0x148) == 0) {
      uVar5 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x1b8);
      iVar1 = *piVar2;
      if (iVar1 - 1U < 0xff) {
        *(int *)(lVar3 + 0x100) = iVar1;
      }
      else {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x78,
                   &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,iVar1);
        }
        uVar6 = 0xc000000d;
      }
      KeReleaseSpinLock(lVar3 + 0x1b8,uVar5);
      KeReleaseSpinLock(&DAT_140036808,uVar4);
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x77,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,lVar3);
      }
      KeReleaseSpinLock(&DAT_140036808,uVar4);
      uVar6 = 0xc00000bb;
    }
  }
  return uVar6;
}



===== PgmSetNextMessageBoundary @ 1400049e4 =====

undefined8 PgmSetNextMessageBoundary(longlong param_1,longlong param_2)

{
  int iVar1;
  int *piVar2;
  longlong lVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined8 uVar6;
  
  piVar2 = *(int **)(param_1 + 0x18);
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18);
  if (*(uint *)(param_2 + 0x10) < 0x90) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6a,
                &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,*(uint *)(param_2 + 0x10),0x90);
    }
    uVar6 = 0xc000000d;
  }
  else {
    uVar4 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
    uVar6 = 0;
    if (((lVar3 == 0) || (*(int *)(lVar3 + 0x10) != 0x53534553)) ||
       (*(longlong *)(lVar3 + 0x18) == 0)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6b,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,lVar3);
      }
      KeReleaseSpinLock(&DAT_140036808,uVar4);
      uVar6 = 0xc0000008;
    }
    else if (*(longlong *)(lVar3 + 0x28) == 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6c,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,lVar3);
      }
      KeReleaseSpinLock(&DAT_140036808,uVar4);
      uVar6 = 0xc00000bb;
    }
    else {
      uVar5 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x168);
      iVar1 = *piVar2;
      if ((iVar1 == 0) || (*(int *)(*(longlong *)(lVar3 + 0x28) + 0xd0) != 0)) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6d,
                   &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,iVar1);
        }
        uVar6 = 0xc000000d;
      }
      else {
        *(int *)(*(longlong *)(lVar3 + 0x28) + 0xd0) = iVar1;
      }
      KeReleaseSpinLock(lVar3 + 0x168,uVar5);
      KeReleaseSpinLock(&DAT_140036808,uVar4);
    }
  }
  return uVar6;
}



===== PgmSetWindowAdvanceMethod @ 140004be4 =====

undefined4 PgmSetWindowAdvanceMethod(longlong param_1,longlong param_2)

{
  int *piVar1;
  longlong lVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  
  piVar1 = *(int **)(param_1 + 0x18);
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18);
  if (*(uint *)(param_2 + 0x10) < 0x90) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),100,
                &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,*(uint *)(param_2 + 0x10),0x90);
    }
    uVar4 = 0xc000000d;
  }
  else {
    uVar3 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
    uVar4 = 0;
    if ((lVar2 == 0) || (*(int *)(lVar2 + 0x10) != 0x52444441)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x65,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,lVar2);
      }
      uVar4 = 0xc0000008;
    }
    else {
      if (*(int *)(lVar2 + 0x148) == 0) {
        if (*piVar1 == 1) {
          *(uint *)(lVar2 + 0x38) = *(uint *)(lVar2 + 0x38) & 0xfffffffd;
        }
        else {
          uVar4 = 0xc000000d;
          if (*piVar1 == 2) {
            uVar4 = 0xc00000bb;
          }
        }
        KeReleaseSpinLock(&DAT_140036808,uVar3);
        return uVar4;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x66,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,lVar2);
      }
      uVar4 = 0xc00000bb;
    }
    KeReleaseSpinLock(&DAT_140036808,uVar3);
  }
  return uVar4;
}



===== PgmSetWindowAdvanceRate @ 140004d60 =====

undefined8 PgmSetWindowAdvanceRate(longlong param_1,longlong param_2)

{
  int *piVar1;
  longlong lVar2;
  undefined1 uVar3;
  undefined8 uVar4;
  
  piVar1 = *(int **)(param_1 + 0x18);
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18);
  if (*(uint *)(param_2 + 0x10) < 0x90) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x58,
                &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,*(uint *)(param_2 + 0x10),0x90);
    }
    uVar4 = 0xc000000d;
  }
  else {
    uVar3 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
    uVar4 = 0;
    if ((lVar2 == 0) || (*(int *)(lVar2 + 0x10) != 0x52444441)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x59,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,lVar2);
      }
      uVar4 = 0xc0000008;
    }
    else {
      if ((*(int *)(lVar2 + 0x148) == 0) &&
         (*(longlong **)(lVar2 + 0x18) == (longlong *)(lVar2 + 0x18))) {
        if (*piVar1 - 1U < 0x19) {
          *(int *)(lVar2 + 0x128) = *piVar1;
        }
        else {
          uVar4 = 0xc000000d;
        }
        KeReleaseSpinLock(&DAT_140036808,uVar3);
        return uVar4;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5a,
                 &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,lVar2);
      }
      uVar4 = 0xc00000bb;
    }
    KeReleaseSpinLock(&DAT_140036808,uVar3);
  }
  return uVar4;
}



===== PgmSetWindowSizeAndSendRate @ 140004ee4 =====

undefined8 PgmSetWindowSizeAndSendRate(longlong param_1,ulonglong param_2)

{
  uint *puVar1;
  longlong lVar2;
  undefined1 auVar3 [16];
  undefined1 uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  
  uVar9 = 0x90;
  puVar1 = *(uint **)(param_1 + 0x18);
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18);
  if (*(uint *)(param_2 + 0x10) < 0x90) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x50,
                &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,*(uint *)(param_2 + 0x10),0x90);
    }
    return 0xc000000d;
  }
  uVar4 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
  if ((lVar2 == 0) || (*(int *)(lVar2 + 0x10) != 0x52444441)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x51,
               &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,lVar2);
    }
    KeReleaseSpinLock(&DAT_140036808,uVar4);
    return 0xc0000008;
  }
  if ((*(int *)(lVar2 + 0x148) != 0) || (*(longlong **)(lVar2 + 0x18) != (longlong *)(lVar2 + 0x18))
     ) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x52,
               &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,lVar2);
    }
    uVar7 = 0xc00000bb;
    goto LAB_14000524c;
  }
  uVar6 = (ulonglong)*puVar1;
  uVar8 = (ulonglong)puVar1[2];
  uVar5 = (ulonglong)puVar1[1];
  if (uVar6 == 0) {
    if ((uVar5 != 0) || (uVar8 != 0)) {
      if ((uVar8 == 0) || (uVar5 == 0)) {
        if ((uVar8 != 0) && (*(uint *)(lVar2 + 0xf8) <= uVar8)) {
          param_2 = (uVar8 * 8) / 7;
          uVar6 = 0x38;
          uVar5 = (uVar8 * 8 - param_2 >> 1) + param_2 >> 5;
          goto LAB_1400050c8;
        }
        uVar9 = *(ulonglong *)(lVar2 + 0x108);
        if (((uVar5 < uVar9) && (9999 < uVar5)) && (*(uint *)(lVar2 + 0xf8) <= uVar5)) {
          auVar3._8_8_ = 0;
          auVar3._0_8_ = uVar9;
          param_2 = SUB168(ZEXT816(0x2492492492492493) * auVar3,8);
          if (uVar5 <= ((uVar9 - param_2 >> 1) + param_2 >> 5) * 8) {
            uVar6 = 0x38;
            uVar8 = uVar5 * 0x38;
            goto LAB_140005153;
          }
          param_2 = uVar9 % (uVar5 * 2);
          uVar6 = uVar9 / (uVar5 * 2) << 3;
          if (uVar6 != 0) goto LAB_14000514c;
          uVar6 = 1;
          uVar8 = uVar5;
          goto LAB_14000516a;
        }
      }
      else {
        uVar6 = (uVar8 * 8) / uVar5;
        param_2 = (uVar8 * 8) % uVar5;
        if (uVar6 != 0) {
LAB_1400050c8:
          if (uVar5 != 0) goto LAB_140005157;
        }
      }
    }
  }
  else {
    if (uVar5 == 0) {
      if (uVar8 == 0) {
        if (uVar6 < 0x1f5) {
          uVar5 = 300000;
        }
        else {
          uVar5 = 30000;
          if (10000 < uVar6) {
            uVar5 = 10000;
          }
        }
        uVar8 = uVar5 * uVar6 >> 3;
      }
      else {
        uVar5 = (uVar8 * 8) / uVar6;
        param_2 = (uVar8 * 8) % uVar6;
      }
      goto LAB_1400050c8;
    }
    if (uVar8 == 0) {
LAB_14000514c:
      uVar8 = uVar5 * uVar6;
LAB_140005153:
      uVar8 = uVar8 >> 3;
LAB_140005157:
      if (uVar8 == 0) goto LAB_14000500c;
    }
LAB_14000516a:
    param_2 = (uVar8 * 8) % uVar5;
    if (((uVar6 == (uVar8 * 8) / uVar5) && (uVar8 <= *(ulonglong *)(lVar2 + 0x108))) &&
       (*(uint *)(lVar2 + 0xf8) <= uVar8)) {
      *(ulonglong *)(lVar2 + 0x110) = uVar6 & 0xffffffff;
      *(ulonglong *)(lVar2 + 0x118) = uVar8 & 0xffffffff;
      *(ulonglong *)(lVar2 + 0x120) = uVar5 & 0xffffffff;
      KeReleaseSpinLock(&DAT_140036808,CONCAT71((int7)(param_2 >> 8),uVar4));
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_qiii(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x54,
                    &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,lVar2,(char)uVar6,(char)uVar8,
                    (char)uVar5);
      }
      return 0;
    }
  }
LAB_14000500c:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_qdddi(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,uVar9,lVar2,(char)*puVar1,
                 (char)puVar1[2],(char)puVar1[1],(char)*(undefined8 *)(lVar2 + 0x108));
  }
  uVar7 = 0xc000000d;
LAB_14000524c:
  KeReleaseSpinLock(&DAT_140036808,uVar4);
  return uVar7;
}



===== ReceiverAddMCastIf @ 1400052d4 =====

ulonglong ReceiverAddMCastIf(longlong param_1,uint param_2,undefined1 *param_3,undefined1 *param_4)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined1 uVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined2 uVar10;
  undefined1 *puVar11;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  undefined4 local_38 [2];
  uint local_30;
  uint local_2c;
  
  local_38[0] = 0;
  uVar7 = Feature_3509484856__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar7 == 0) {
    uVar7 = ReceiverAddMCastIf_old(param_1,param_2,param_3,param_4);
    return uVar7;
  }
  if (*(int *)(param_1 + 0x148) == 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc00000bb;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return 0xc00000bb;
    }
    uVar10 = 0x30;
  }
  else {
    uVar7 = GetIpInterfaceIndexFromAddress(param_2,local_38);
    if ((int)uVar7 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
                  &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,(int)uVar7,(char)param_2);
      }
      return uVar7 & 0xffffffff;
    }
    puVar1 = (undefined8 *)(param_1 + 0x1a8);
    puVar8 = PgmFindReceiverInterface(puVar1,param_2);
    if (puVar8 != (undefined8 *)0x0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
                  &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,param_2,(char)local_38[0]);
      }
      return 0;
    }
    if (*(ushort *)(param_1 + 0x14e) < 0x14) {
      lVar2 = param_1 + 0x1b8;
      KeReleaseSpinLock(lVar2,*param_4);
      KeReleaseSpinLock(&DAT_140036808,*param_3);
      puVar8 = (undefined8 *)ExAllocatePool2(0x40,0x18,0x306d6750);
      if (puVar8 == (undefined8 *)0x0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
                  &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids);
        }
        uVar5 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
        *param_3 = uVar5;
        uVar5 = KeAcquireSpinLockRaiseToDpc(lVar2);
        *param_4 = uVar5;
        return 0xc000009a;
      }
      *(uint *)(puVar8 + 2) = param_2;
      uVar6 = *(uint *)(param_1 + 0x148);
      local_30 = uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18;
      local_2c = param_2 >> 0x18 | (param_2 & 0xff0000) >> 8 | (param_2 & 0xff00) << 8 |
                 param_2 << 0x18;
      uVar6 = PgmSetTcpInfo(*(undefined8 *)(param_1 + 0x40),6,&local_30,8);
      uVar5 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
      *param_3 = uVar5;
      uVar5 = KeAcquireSpinLockRaiseToDpc(lVar2);
      puVar11 = auStack_68;
      *param_4 = uVar5;
      if ((int)uVar6 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
                    &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,uVar6,(char)param_2);
        }
        ExFreePoolWithTag(puVar8,0);
      }
      else {
        puVar9 = *(undefined8 **)(param_1 + 0x1b0);
        if ((undefined8 *)*puVar9 != puVar1) {
          pcVar4 = (code *)swi(0x29);
          puVar9 = (undefined8 *)(*pcVar4)(3);
          puVar11 = auStack_60;
        }
        *puVar8 = puVar1;
        puVar8[1] = puVar9;
        *puVar9 = puVar8;
        *(undefined8 **)(param_1 + 0x1b0) = puVar8;
        *(short *)(param_1 + 0x14e) = *(short *)(param_1 + 0x14e) + 1;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
          *(undefined4 *)(puVar11 + 0x20) = *(undefined4 *)(puVar11 + 0x30);
          *(undefined8 *)(puVar11 + -8) = 0x1400055f9;
          WPP_SF_dD(uVar3,0x36,&WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,param_2,
                    puVar11[0x20]);
        }
      }
      return (ulonglong)uVar6;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc00000bb;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return 0xc00000bb;
    }
    uVar10 = 0x33;
  }
  WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,
           &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,param_1);
  return 0xc00000bb;
}



===== ReceiverAddMCastIf_old @ 140005624 =====

ulonglong ReceiverAddMCastIf_old
                    (longlong param_1,uint param_2,undefined1 *param_3,undefined1 *param_4)

{
  ushort uVar1;
  undefined1 uVar2;
  uint uVar3;
  ulonglong uVar4;
  ushort uVar5;
  undefined2 uVar6;
  uint uVar7;
  uint local_res8 [2];
  undefined8 local_38;
  
  local_38 = 0;
  local_res8[0] = 0;
  if (*(int *)(param_1 + 0x148) == 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc00000bb;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return 0xc00000bb;
    }
    uVar6 = 0x2a;
LAB_140005720:
    WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
             &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,param_1);
    return 0xc00000bb;
  }
  uVar4 = GetIpInterfaceIndexFromAddress(param_2,local_res8);
  if ((int)uVar4 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
                &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,(int)uVar4,(char)param_2);
    }
    return uVar4 & 0xffffffff;
  }
  uVar1 = *(ushort *)(param_1 + 0x14e);
  uVar5 = 0;
  if (uVar1 != 0) {
    do {
      if (*(uint *)(param_1 + 0x150 + (ulonglong)uVar5 * 4) == param_2) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
                    &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,param_2,(char)local_res8[0]);
        }
        return 0;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
  }
  if (0x13 < uVar1) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc00000bb;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return 0xc00000bb;
    }
    uVar6 = 0x2d;
    goto LAB_140005720;
  }
  KeReleaseSpinLock(param_1 + 0x1b8,CONCAT11((char)(uVar1 >> 8),*param_4));
  KeReleaseSpinLock(&DAT_140036808,*param_3);
  uVar3 = *(uint *)(param_1 + 0x148);
  local_38 = CONCAT44(param_2 >> 0x18 | (param_2 & 0xff0000) >> 8 | (param_2 & 0xff00) << 8 |
                      param_2 << 0x18,
                      uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 |
                      uVar3 << 0x18);
  uVar3 = PgmSetTcpInfo(*(undefined8 *)(param_1 + 0x40),6,&local_38,8);
  uVar2 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
  *param_3 = uVar2;
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x1b8);
  *param_4 = uVar2;
  if ((int)uVar3 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) goto LAB_14000587e;
    uVar6 = 0x2e;
    uVar7 = uVar3;
  }
  else {
    *(uint *)(param_1 + 0x150 + (ulonglong)*(ushort *)(param_1 + 0x14e) * 4) = param_2;
    *(short *)(param_1 + 0x14e) = *(short *)(param_1 + 0x14e) + 1;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) goto LAB_14000587e;
    uVar6 = 0x2f;
    uVar7 = param_2;
    param_2 = local_res8[0];
  }
  WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
            &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,uVar7,(char)param_2);
LAB_14000587e:
  return (ulonglong)uVar3;
}



===== SetSenderMCastOutIf @ 1400058a0 =====

int SetSenderMCastOutIf(longlong param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  int iVar3;
  undefined2 uVar4;
  uint uVar5;
  int local_res8 [2];
  uint local_res10 [2];
  undefined4 *local_res18;
  
  local_res18 = (undefined4 *)0x0;
  local_res8[0] = 0x32;
  local_res10[0] = param_2;
  iVar3 = PgmSetTcpInfo(*(undefined8 *)(param_1 + 0x40),3,local_res10,4);
  if (iVar3 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar3;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return iVar3;
    }
    uVar4 = 0xd;
  }
  else {
    iVar3 = PgmSetTcpInfo(*(undefined8 *)(param_1 + 0x58),3,local_res10,4);
    if (-1 < iVar3) {
      iVar3 = PgmQueryTcpInfo(*(undefined8 *)(param_1 + 0x58),0x103,local_res10,4,
                              (longlong *)&local_res18,local_res8);
      puVar1 = local_res18;
      if (iVar3 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                    &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,local_res10[0],(char)iVar3);
        }
      }
      else {
        if ((uint)local_res18[1] < 0x5d) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
            WPP_SF_dDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                       &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,local_res18[1],
                       (char)local_res10[0],0x5c);
          }
          iVar3 = -0x3fffffff;
        }
        else {
          uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x1b8);
          uVar5 = 6;
          if ((uint)puVar1[3] < 6) {
            uVar5 = puVar1[3];
          }
          *(undefined4 *)(param_1 + 0xe8) = 0;
          *(undefined2 *)(param_1 + 0xec) = 0;
          memmove((undefined4 *)(param_1 + 0xe8),puVar1 + 4,(ulonglong)uVar5);
          *(int *)(param_1 + 0xf8) = puVar1[1] + -0x18;
          *(undefined4 *)(param_1 + 0xf4) = *puVar1;
          *(uint *)(param_1 + 0xf0) =
               local_res10[0] >> 0x18 | (local_res10[0] & 0xff0000) >> 8 |
               (local_res10[0] & 0xff00) << 8 | local_res10[0] << 0x18;
          KeReleaseSpinLock(param_1 + 0x1b8,uVar2);
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
            WPP_SF_dDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                       &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,
                       *(undefined4 *)(param_1 + 0xf0),(char)puVar1[1],
                       (char)*(undefined4 *)(param_1 + 0xf8));
          }
        }
        ExFreePoolWithTag(puVar1,0);
      }
      return iVar3;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar3;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return iVar3;
    }
    uVar4 = 0xe;
  }
  WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
            &WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,local_res10[0],(char)iVar3);
  return iVar3;
}



===== WPP_SF_ @ 140005b14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_D @ 140005b40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_dD @ 140005b84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,0);
  return;
}



===== WPP_SF_DDD @ 140005bd4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,param_2,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_dDd @ 140005c38 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dDd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_Dq @ 140005c94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,8,0);
  return;
}



===== WPP_SF_Dqq @ 140005ce8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dqq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_dDD @ 140005d48 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,0x18,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_i @ 140005dac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_i(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,0);
  return;
}



===== WPP_SF_qD @ 140005df0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,4,0);
  return;
}



===== WPP_SF_qd @ 140005e44 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,0x1d,&local_res20,8,
             &param_5,4,0);
  return;
}



===== WPP_SF_qdddi @ 140005ea0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qdddi(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,0x53,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,4,&param_8,8,0);
  return;
}



===== WPP_SF_qiii @ 140005f28 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qiii(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,&param_6,8,&param_7,8,0);
  return;
}



===== WPP_SF_qq @ 140005f90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,0);
  return;
}



===== WPP_SF_qqq @ 140005fe0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_s @ 14000603c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_s(undefined8 param_1,undefined2 param_2,undefined8 param_3,char *param_4)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_4[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,lVar2,0);
  return;
}



===== WPP_SF_sqDD @ 1400060a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sqDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_4[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,0x1a,param_4,lVar2,
             &param_5,8,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_sqq @ 14000614c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sqq(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
               undefined1 param_5,undefined1 param_6)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_4[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fe3513e9b35731d1d5424cf3ba5a7aff_Traceguids,0x21,param_4,lVar2,
             &param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_ss @ 1400061e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ss(undefined8 param_1,undefined2 param_2,undefined8 param_3,char *param_4,char *param_5)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
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
  lVar1 = -1;
  if (param_4 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    do {
      lVar3 = lVar1;
      lVar1 = lVar3 + 1;
    } while (param_4[lVar1] != '\0');
    lVar3 = lVar3 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,lVar3,param_5,lVar2,0);
  return;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 140006284 =====

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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 14000635c =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 140006440 =====

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
LAB_140006598:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_14000658b:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_140006598;
      if (uVar5 == 5) goto LAB_14000658b;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 1400065c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (longlong param_1,undefined8 param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  undefined7 extraout_var;
  uint uVar3;
  int local_res18 [4];
  
  uVar3 = (uint)param_2 & 1;
  local_res18[0] = param_3;
  uVar2 = wil_details_MapReportingKind(param_3,uVar3);
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(param_1,param_2,(ulonglong)uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (*(undefined4 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x10),0,uVar3,local_res18,0
               ,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140006644 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (longlong param_1,undefined8 param_2,ulonglong param_3)

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
              (*(undefined4 *)(param_1 + 0x18),param_3 & 0xffffffff,1,*(undefined8 *)(param_1 + 8));
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_68._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),*(undefined4 *)(param_1 + 0x18));
    uVar1 = (uint6)local_68;
    local_68 = (ulonglong)(uint6)local_68;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_68 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_68);
  }
  return (int)local_38 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140006734 =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140006844 =====

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



===== wil_details_GetCurrentFeatureEnabledState @ 1400068a8 =====

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



===== wil_details_IsEnabledFallback @ 140006a08 =====

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



===== wil_details_MapReportingKind @ 140006a9c =====

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



===== PgmCancelDisconnectIrp @ 140006b40 =====

void PgmCancelDisconnectIrp(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  longlong lVar4;
  
  uVar3 = 0;
  lVar4 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  lVar1 = *(longlong *)(lVar4 + 0x18);
  if ((lVar1 == 0) || ((*(int *)(lVar1 + 0x10) + 0xadacbaadU & 0xfeffffff) != 0)) {
    IoReleaseCancelSpinLock(CONCAT71((int7)((ulonglong)lVar4 >> 8),*(undefined1 *)(param_2 + 0x45)))
    ;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      if (lVar1 != 0) {
        uVar3 = (undefined1)*(undefined8 *)(lVar1 + 0x18);
      }
      WPP_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                 &WPP_ffb0ebbf543c30978a27a610893f40c5_Traceguids,param_2,(char)lVar1,uVar3);
    }
  }
  else {
    uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x168);
    lVar4 = *(longlong *)(lVar1 + 0x60);
    if ((lVar4 == 0) || (lVar4 != param_2)) {
      lVar4 = 0;
    }
    else {
      *(undefined8 *)(lVar1 + 0x60) = 0;
    }
    lVar2 = *(longlong *)(lVar1 + 0x28);
    if (lVar2 != 0) {
      *(undefined8 *)(lVar2 + 0x138) = *(undefined8 *)(lVar2 + 0x128);
    }
    KeReleaseSpinLock(lVar1 + 0x168,CONCAT71((int7)((ulonglong)lVar2 >> 8),uVar3));
    IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                &WPP_ffb0ebbf543c30978a27a610893f40c5_Traceguids,param_2,(char)lVar4);
    }
    if (lVar4 != 0) {
      *(undefined8 *)(param_2 + 0x38) = 0;
      *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
      IofCompleteRequest(param_2,2);
    }
  }
  return;
}



===== PgmCleanupConnection @ 140006cc0 =====

undefined8 PgmCleanupConnection(longlong *param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined8 uVar7;
  longlong lVar8;
  undefined *puVar9;
  longlong *plVar10;
  
  lVar8 = param_2;
  uVar5 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
  plVar1 = param_1 + 0x2d;
  uVar6 = KeAcquireSpinLockRaiseToDpc(plVar1);
  puVar9 = (undefined *)param_1[3];
  plVar10 = (longlong *)0x32534553;
  *(undefined4 *)(param_1 + 2) = 0x32534553;
  if (puVar9 != (undefined *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      plVar10 = param_1;
      WPP_SF_qDqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
                  (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),puVar9,param_1,0x53,(char)puVar9,
                  (char)*(undefined4 *)(puVar9 + 0x10));
    }
    KeReleaseSpinLock(plVar1,uVar6);
    KeReleaseSpinLock(&DAT_140036808,uVar5);
    lVar8 = *(longlong *)(param_2 + 0xb8);
    PgmDisassociateAddress(param_2,lVar8,puVar9,plVar10);
    uVar5 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
    uVar6 = KeAcquireSpinLockRaiseToDpc(plVar1);
  }
  lVar2 = *param_1;
  if ((*(longlong **)(lVar2 + 8) == param_1) &&
     (plVar3 = (longlong *)param_1[1], (longlong *)*plVar3 == param_1)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    if ((undefined *)*DAT_140036708 == &DAT_140036700) {
      *param_1 = (longlong)&DAT_140036700;
      param_1[1] = (longlong)DAT_140036708;
      *DAT_140036708 = (longlong)param_1;
      DAT_140036708 = param_1;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
        puVar9 = &WPP_ffb0ebbf543c30978a27a610893f40c5_Traceguids;
        lVar8 = 0;
        plVar10 = param_1;
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                 &WPP_ffb0ebbf543c30978a27a610893f40c5_Traceguids,param_1);
      }
      param_1[0xb] = param_2;
      if ((*(uint *)(param_1 + 4) >> 9 & 1) != 0) {
        *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x100;
      }
      uVar7 = CONCAT71((int7)((ulonglong)lVar8 >> 8),uVar6);
      KeReleaseSpinLock(plVar1,uVar7);
      uVar7 = CONCAT71((int7)((ulonglong)uVar7 >> 8),uVar5);
      KeReleaseSpinLock(&DAT_140036808);
      PgmDereferenceSessionCommon(param_1,uVar7,puVar9,plVar10);
      return 0x103;
    }
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  uVar7 = (*pcVar4)();
  return uVar7;
}



===== PgmCleanupSession @ 140006ea0 =====

void PgmCleanupSession(longlong param_1)

{
  longlong lVar1;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
             &WPP_ffb0ebbf543c30978a27a610893f40c5_Traceguids,param_1);
  }
  if (((*(uint *)(param_1 + 0x20) & 0x10) != 0) &&
     (*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x50) != 0)) {
    PgmUnmapAndCloseDataFile(param_1);
    *(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x50) = 0;
  }
  KeAcquireSpinLockRaiseToDpc(param_1 + 0x168);
  *(undefined8 *)(param_1 + 0x48) = 0;
  lVar1 = *(longlong *)(param_1 + 0x58);
  if (lVar1 == 0) {
    KeReleaseSpinLock(param_1 + 0x168);
  }
  else {
    *(undefined8 *)(param_1 + 0x58) = 0;
    KeReleaseSpinLock();
    PgmIoComplete(lVar1,0,0);
  }
  return;
}



===== PgmCloseConnection @ 140006f74 =====

undefined8 PgmCloseConnection(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
    WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
             &WPP_ffb0ebbf543c30978a27a610893f40c5_Traceguids,lVar1);
  }
  if (*(longlong *)(lVar1 + 0x48) != 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
               &WPP_ffb0ebbf543c30978a27a610893f40c5_Traceguids,lVar1);
    }
    PgmCleanupSession(lVar1);
  }
  *(undefined8 *)(*(longlong *)(param_2 + 0x30) + 0x18) = 0;
  if (*(char *)(lVar1 + 0xa1) != '\0') {
    DestroyFECContext(lVar1 + 0x70);
  }
  if (*(longlong *)(lVar1 + 0x28) == 0) {
    if (*(longlong *)(lVar1 + 0x30) == 0) goto LAB_140007173;
    if ((*(uint *)(lVar1 + 0x20) & 0x8000) != 0) {
      ExDeleteNPagedLookasideList(*(longlong *)(lVar1 + 0x30) + 0x140);
    }
    if (*(longlong *)(lVar1 + 0x90) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar1 + 0x90),0);
    }
    if (*(char *)(lVar1 + 0xa0) != '\0') {
      ExDeleteNPagedLookasideList(*(longlong *)(lVar1 + 0x30) + 0x1c0);
      if (*(char *)(lVar1 + 0xa1) != '\0') {
        ExDeleteNPagedLookasideList(*(longlong *)(lVar1 + 0x30) + 0x240);
      }
    }
    lVar2 = *(longlong *)(*(longlong *)(lVar1 + 0x30) + 0xd8);
    if (lVar2 != 0) {
      ExFreePoolWithTag(lVar2,0);
      *(undefined8 *)(*(longlong *)(lVar1 + 0x30) + 0xd8) = 0;
    }
    uVar3 = *(undefined8 *)(lVar1 + 0x30);
  }
  else {
    ExDeleteResourceLite(*(longlong *)(lVar1 + 0x28) + 0x2e0);
    lVar2 = *(longlong *)(*(longlong *)(lVar1 + 0x28) + 0x18);
    if (lVar2 != 0) {
      ExFreePoolWithTag(lVar2,0);
    }
    lVar2 = *(longlong *)(*(longlong *)(lVar1 + 0x28) + 0x1a8);
    if (lVar2 != 0) {
      ExFreePoolWithTag(lVar2,0);
    }
    if (*(longlong *)(*(longlong *)(lVar1 + 0x28) + 0x130) != 0) {
      ExDeleteNPagedLookasideList(*(longlong *)(lVar1 + 0x28) + 0x1c0);
      ExDeleteNPagedLookasideList(*(longlong *)(lVar1 + 0x28) + 0x240);
    }
    uVar3 = *(undefined8 *)(lVar1 + 0x28);
  }
  ExFreePoolWithTag(uVar3,0);
LAB_140007173:
  ExFreePoolWithTag(lVar1,0);
  return 0;
}



===== PgmConnect @ 1400071a0 =====

uint PgmConnect(undefined8 param_1,ulonglong param_2,longlong param_3)

{
  byte bVar1;
  undefined8 *puVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 uVar5;
  undefined1 uVar6;
  uint uVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined8 uVar10;
  longlong lVar11;
  ushort uVar12;
  int iVar13;
  ulonglong uVar14;
  longlong *plVar15;
  undefined8 *puVar16;
  longlong *plVar17;
  longlong *plVar18;
  ulonglong *puVar19;
  ulonglong *puVar20;
  uint uVar21;
  undefined4 local_res8;
  undefined4 uStackX_c;
  ulonglong local_res10;
  uint local_res18 [2];
  longlong *local_res20;
  undefined1 uVar22;
  undefined4 in_stack_ffffffffffffff88;
  undefined2 uVar23;
  
  puVar20 = &local_res10;
  puVar19 = (ulonglong *)local_res18;
  local_res18[0] = 0;
  local_res10 = param_2 & 0xffffffffffff0000;
  uVar7 = 0xc000009a;
  uVar21 = *(uint *)(*(longlong *)(param_3 + 0x10) + 0x20);
  uVar14 = (ulonglong)uVar21;
  plVar17 = (longlong *)0x0;
  plVar18 = *(longlong **)(*(longlong *)(param_3 + 0x30) + 0x18);
  _local_res8 = CONCAT44((int)((ulonglong)param_1 >> 0x20),0x494);
  local_res20 = plVar18;
  uVar8 = GetIpAddress(*(int **)(*(longlong *)(param_3 + 0x10) + 0x28),uVar21,(undefined4 *)puVar19,
                       (ushort *)puVar20);
  if ((char)uVar8 == '\0') {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
               &WPP_ffb0ebbf543c30978a27a610893f40c5_Traceguids,plVar18);
    }
    return 0xc0000207;
  }
  uVar5 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
  if ((((plVar18 == (longlong *)0x0) || ((int)plVar18[2] != 0x53534553)) ||
      (plVar17 = (longlong *)plVar18[3], plVar17 == (longlong *)0x0)) ||
     (((int)plVar17[2] != 0x52444441 || ((*(uint *)(plVar17 + 7) & 1) != 0)))) {
    KeReleaseSpinLock(&DAT_140036808,uVar5);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                &WPP_ffb0ebbf543c30978a27a610893f40c5_Traceguids,plVar18,(char)plVar17);
    }
    return 0xc0000008;
  }
  uVar6 = KeAcquireSpinLockRaiseToDpc(plVar17 + 0x37);
  *(int *)((longlong)plVar17 + 0x14) = *(int *)((longlong)plVar17 + 0x14) + 1;
  uVar10 = CONCAT71((int7)(uVar14 >> 8),uVar6);
  KeReleaseSpinLock(plVar17 + 0x37,uVar10);
  uVar6 = KeAcquireSpinLockRaiseToDpc(plVar18 + 0x2d);
  *(int *)((longlong)plVar18 + 0x14) = *(int *)((longlong)plVar18 + 0x14) + 1;
  plVar15 = (longlong *)CONCAT71((int7)((ulonglong)uVar10 >> 8),uVar6);
  KeReleaseSpinLock(plVar18 + 0x2d,plVar15);
  if ((*(uint *)(plVar17 + 7) & 0x10) == 0) {
    KeReleaseSpinLock(&DAT_140036808,uVar5);
    puVar19 = (ulonglong *)&local_res8;
    puVar20 = (ulonglong *)0x4;
    plVar15 = (longlong *)0x5;
    uVar7 = PgmSetTcpInfo(plVar17[0xb],5,puVar19,4);
    if ((int)uVar7 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        puVar19 = (ulonglong *)&WPP_ffb0ebbf543c30978a27a610893f40c5_Traceguids;
        plVar15 = (longlong *)0x16;
        puVar20 = (ulonglong *)(ulonglong)uVar7;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                 &WPP_ffb0ebbf543c30978a27a610893f40c5_Traceguids,uVar7);
      }
      goto LAB_140007356;
    }
    uVar5 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
  }
  uVar23 = (undefined2)((uint)in_stack_ffffffffffffff88 >> 0x10);
  if ((int)plVar17[0x1e] == 0) {
    uVar7 = 0xc0000239;
    puVar16 = &DAT_140036720;
    uVar21 = 0;
    do {
      uVar23 = (undefined2)((uint)in_stack_ffffffffffffff88 >> 0x10);
      puVar16 = (undefined8 *)*puVar16;
      if (puVar16 == &DAT_140036720) break;
      puVar2 = (undefined8 *)puVar16[2];
      if (puVar2 != puVar16 + 2) {
        uVar21 = *(uint *)(puVar2 + 2);
        uVar21 = uVar21 >> 0x18 | (uVar21 & 0xff0000) >> 8 | (uVar21 & 0xff00) << 8 | uVar21 << 0x18
        ;
        KeReleaseSpinLock(&DAT_140036808,uVar5);
        plVar15 = (longlong *)(ulonglong)uVar21;
        uVar7 = SetSenderMCastOutIf((longlong)plVar17,uVar21);
        uVar5 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
      }
      uVar23 = (undefined2)((uint)in_stack_ffffffffffffff88 >> 0x10);
    } while (uVar21 == 0);
    plVar18 = local_res20;
    if ((int)uVar7 < 0) {
      uVar10 = CONCAT71((int7)((ulonglong)plVar15 >> 8),uVar5);
      KeReleaseSpinLock(&DAT_140036808);
      PgmDereferenceSessionCommon(plVar18,uVar10,puVar19,(longlong *)puVar20);
      PgmDereferenceAddress(plVar17,uVar10,puVar19,(longlong *)puVar20);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                 &WPP_ffb0ebbf543c30978a27a610893f40c5_Traceguids,uVar21);
      }
      return 0xc0000001;
    }
  }
  *(uint *)(plVar18[5] + 0x28) =
       local_res18[0] >> 0x18 | (local_res18[0] & 0xff0000) >> 8 | (local_res18[0] & 0xff00) << 8 |
       local_res18[0] << 0x18;
  uVar12 = (ushort)local_res10 >> 8 | (ushort)local_res10 << 8;
  *(ushort *)((longlong)plVar17 + 0xee) = uVar12;
  *(ushort *)(plVar18[5] + 0x30) = uVar12;
  *(int *)(plVar18[5] + 0x2c) = (int)plVar17[0x1e];
  *(undefined2 *)((longlong)plVar18 + 0x9c) = *(undefined2 *)((longlong)plVar17 + 300);
  bVar1 = *(byte *)(plVar17 + 0x26);
  *(byte *)(plVar18 + 0x14) = bVar1;
  uVar6 = (undefined1)local_res18[0];
  uVar22 = (undefined1)local_res10;
  if (*(char *)((longlong)plVar17 + 0x131) == '\0') {
    *(uint *)(plVar18[5] + 0x6c) = (int)plVar17[0x1f] + 0x27U & 0xfffffff8;
    iVar13 = (int)plVar17[0x1f] + -0x38;
  }
  else {
    lVar11 = (ulonglong)bVar1 * 8 + 0x10;
    uVar8 = 0x306d6750;
    lVar9 = ExAllocatePool2(0x40,lVar11);
    *(longlong *)(plVar18[5] + 0x1a8) = lVar9;
    if (lVar9 == 0) {
LAB_14000756c:
      if (*(longlong *)(plVar18[5] + 0x1a8) != 0) {
        lVar11 = 0;
        ExFreePoolWithTag(*(longlong *)(plVar18[5] + 0x1a8),0);
        *(undefined8 *)(plVar18[5] + 0x1a8) = 0;
      }
      uVar10 = CONCAT71((int7)((ulonglong)lVar11 >> 8),uVar5);
      KeReleaseSpinLock(&DAT_140036808);
      PgmDereferenceSessionCommon(plVar18,uVar10,uVar8,(longlong *)puVar20);
      PgmDereferenceAddress(plVar17,uVar10,uVar8,(longlong *)puVar20);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_DqDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,uVar8,uVar7,(char)plVar18,uVar6,
                    uVar22);
      }
      return 0xc000009a;
    }
    uVar8 = (ulonglong)*(ushort *)((longlong)plVar18 + 0x9c);
    lVar11 = 0;
    puVar20 = (ulonglong *)0x0;
    uVar10 = CreateFECContext((uint *)(plVar18 + 0xe),(uint)*(byte *)(plVar18 + 0x14),
                              (uint)*(ushort *)((longlong)plVar18 + 0x9c),'\0');
    uVar7 = (uint)uVar10;
    if ((int)uVar7 < 0) goto LAB_14000756c;
    *(undefined1 *)((longlong)plVar18 + 0xa1) = *(undefined1 *)((longlong)plVar17 + 0x131);
    *(undefined2 *)((longlong)plVar18 + 0x9e) = *(undefined2 *)((longlong)plVar17 + 0x12e);
    *(uint *)(plVar18[5] + 0xc4) = *(uint *)(plVar18[5] + 0xc4) | 0x200;
    *(undefined4 *)(plVar18[5] + 0xb4) = 0xffffffff;
    *(uint *)(plVar18[5] + 0x6c) = (int)plVar17[0x1f] + 0x37U & 0xfffffff8;
    iVar13 = (int)plVar17[0x1f] + -0x46;
  }
  *(int *)(plVar18[5] + 0x70) = iVar13;
  *(short *)((longlong)plVar18 + 0x46) = DAT_140036766;
  DAT_140036766 = DAT_140036766 + 1;
  if (*(short *)((longlong)plVar18 + 0x46) == *(short *)((longlong)plVar17 + 0xee)) {
    *(short *)((longlong)plVar18 + 0x46) = DAT_140036766;
    DAT_140036766 = DAT_140036766 + 1;
  }
  lVar11 = plVar18[5] + 0xf8;
  *(longlong *)(plVar18[5] + 0x100) = lVar11;
  *(longlong *)lVar11 = lVar11;
  lVar11 = plVar18[5] + 0xe8;
  *(longlong *)(plVar18[5] + 0xf0) = lVar11;
  *(longlong *)lVar11 = lVar11;
  lVar11 = plVar18[5] + 0xd8;
  *(longlong *)(plVar18[5] + 0xe0) = lVar11;
  *(longlong *)lVar11 = lVar11;
  local_res10 = CONCAT44(local_res10._4_4_,(int)plVar17[0x20]);
  KeReleaseSpinLock(&DAT_140036808,uVar5);
  KeInitializeEvent(plVar18[5] + 0x2c0,1,0);
  puVar19 = &local_res10;
  puVar20 = (ulonglong *)0x4;
  plVar15 = (longlong *)0x2;
  uVar7 = PgmSetTcpInfo(plVar17[8],2,puVar19,4);
  if ((int)uVar7 < 0) {
LAB_1400077a5:
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) {
        puVar19 = (ulonglong *)&WPP_ffb0ebbf543c30978a27a610893f40c5_Traceguids;
        plVar15 = (longlong *)0x1a;
        puVar20 = (ulonglong *)(ulonglong)uVar7;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                 &WPP_ffb0ebbf543c30978a27a610893f40c5_Traceguids,uVar7);
      }
      if (-1 < (int)uVar7) {
LAB_1400077d5:
        KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
        lVar11 = plVar18[5];
        uVar8 = (ulonglong)(plVar17[0x22] * 0x14) >> 3;
        if (uVar8 < *(uint *)(lVar11 + 0x6c)) {
          *(ulonglong *)(lVar11 + 0x130) =
               (((ulonglong)*(uint *)(plVar17 + 0x1f) - 1) + ((ulonglong)plVar17[0x22] >> 3)) /
               uVar8;
          if (*(longlong *)(plVar18[5] + 0x130) == 0) {
            *(undefined8 *)(plVar18[5] + 0x130) = 1;
          }
        }
        else {
          *(undefined8 *)(lVar11 + 0x130) = 1;
        }
        *(uint *)(plVar18[5] + 0x19c) =
             (uint)(*(int *)(plVar18[5] + 0x130) * (int)plVar17[0x22] * 0x14) >> 3;
        *(undefined4 *)(plVar18[5] + 0x1a0) = *(undefined4 *)(plVar18[5] + 0x19c);
        *(uint *)(plVar18[5] + 0x1a4) = *(uint *)(plVar18[5] + 0x19c) >> 8;
        *(undefined8 *)(plVar18[5] + 0x168) = *(undefined8 *)(plVar18[5] + 0x130);
        *(undefined4 *)(plVar18[5] + 0x198) = *(undefined4 *)(plVar18[5] + 0x19c);
        *(undefined8 *)(plVar18[5] + 0x170) = 0;
        *(undefined8 *)(plVar18[5] + 0x178) = 0x19;
        *(undefined8 *)(plVar18[5] + 0x188) = 0x32;
        *(undefined8 *)(plVar18[5] + 400) = 0x2ee;
        *(undefined8 *)(plVar18[5] + 0x180) = *(undefined8 *)(plVar18[5] + 0x188);
        uVar8 = (ulonglong)*(uint *)(plVar17 + 0x25) * plVar17[0x24];
        auVar3._8_8_ = 0;
        auVar3._0_8_ = uVar8;
        lVar11 = SUB168(ZEXT816(0x47ae147ae147ae15) * auVar3,8);
        *(ulonglong *)(plVar18[5] + 0x148) = (ulonglong)plVar17[0x24] / 0x14;
        *(ulonglong *)(plVar18[5] + 0x140) = ((uVar8 - lVar11 >> 1) + lVar11) / 0x500;
        lVar11 = plVar18[5];
        *(longlong *)(lVar11 + 0x158) =
             *(longlong *)(lVar11 + 0x148) + *(longlong *)(lVar11 + 0x140);
        *(undefined8 *)(plVar18[5] + 0x150) = 3;
        if (*(uint *)((longlong)plVar17 + 0xfc) != 0) {
          uVar8 = (ulonglong)*(uint *)((longlong)plVar17 + 0xfc) * *(longlong *)(plVar18[5] + 0x60);
          auVar4._8_8_ = 0;
          auVar4._0_8_ = uVar8;
          lVar11 = SUB168(ZEXT816(0x47ae147ae147ae15) * auVar4,8);
          *(int *)(plVar18[5] + 0xb0) = (int)((uVar8 - lVar11 >> 1) + lVar11 >> 7);
          *(uint *)(plVar18[5] + 200) = *(uint *)(plVar18[5] + 200) | 8;
          *(int *)(plVar18[5] + 0xcc) = *(int *)(plVar18[5] + 0xcc) + 8;
          *(uint *)(plVar18[5] + 0xc4) = *(uint *)(plVar18[5] + 0xc4) | 8;
        }
        *(uint *)(plVar18 + 4) = *(uint *)(plVar18 + 4) | 0x18;
        *(undefined8 *)(plVar18[5] + 0x88) = 0;
        *(undefined8 *)(plVar18[5] + 0x80) = 0;
        KeReleaseSpinLock(&DAT_140036808);
        ExInitializeNPagedLookasideList
                  (plVar18[5] + 0x1c0,0,0,0x200,*(undefined4 *)(plVar18[5] + 0x6c),0x326d6750,
                   CONCAT22(uVar23,100));
        plVar15 = (longlong *)0x200;
        uVar10 = 0;
        lVar11 = 0;
        ExInitializeNPagedLookasideList(plVar18[5] + 0x240);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          lVar11 = plVar18[5];
          plVar15 = plVar18;
          WPP_SF_qDdddddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar11,uVar10,plVar18,uVar6,
                          (char)plVar17[0x22],(char)plVar17[0x23],(char)plVar17[0x24],
                          (char)*(undefined4 *)(lVar11 + 0x130),
                          (char)*(undefined4 *)(lVar11 + 0x19c),
                          (char)*(undefined4 *)(lVar11 + 0x198));
        }
        PgmDereferenceSessionCommon(plVar18,lVar11,uVar10,plVar15);
        PgmDereferenceAddress(plVar17,lVar11,uVar10,plVar15);
        return 0;
      }
    }
  }
  else {
    puVar20 = (ulonglong *)0x4;
    puVar19 = &local_res10;
    plVar15 = (longlong *)0x2;
    uVar7 = PgmSetTcpInfo(plVar17[0xb],2,puVar19,4);
    if ((int)uVar7 < 0) goto LAB_1400077a5;
    plVar15 = plVar18;
    uVar8 = PgmCreateDataFileAndMapSection((longlong)plVar17,(longlong)plVar18);
    uVar7 = (uint)uVar8;
    if (-1 < (int)uVar7) goto LAB_1400077d5;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      plVar15 = (longlong *)0x19;
      puVar20 = (ulonglong *)(uVar8 & 0xffffffff);
      WPP_SF_DqDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,puVar19,uVar7,(char)plVar18,uVar6,
                  uVar22);
    }
  }
  if (*(char *)((longlong)plVar17 + 0x131) != '\0') {
    DestroyFECContext((longlong)(plVar18 + 0xe));
    plVar15 = (longlong *)0x0;
    ExFreePoolWithTag(*(undefined8 *)(plVar18[5] + 0x1a8));
    *(undefined8 *)(plVar18[5] + 0x1a8) = 0;
  }
LAB_140007356:
  PgmDereferenceSessionCommon(plVar18,plVar15,puVar19,(longlong *)puVar20);
  PgmDereferenceAddress(plVar17,plVar15,puVar19,(longlong *)puVar20);
  return uVar7;
}



===== PgmDereferenceSessionCommon @ 140007b5c =====

void PgmDereferenceSessionCommon
               (longlong *param_1,undefined8 param_2,undefined8 param_3,longlong *param_4)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  char cVar7;
  undefined8 uVar8;
  
  plVar4 = param_1 + 0x2d;
  uVar6 = KeAcquireSpinLockRaiseToDpc(plVar4);
  piVar1 = (int *)((longlong)param_1 + 0x14);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      param_4 = param_1;
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                &WPP_ffb0ebbf543c30978a27a610893f40c5_Traceguids,param_1,(char)param_1[0xb]);
    }
    lVar2 = param_1[0xb];
    if (param_1[6] != 0) {
      CleanupPendingNaks((longlong)param_1,0,1);
    }
    KeReleaseSpinLock(plVar4,uVar6);
    uVar6 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
    lVar3 = *param_1;
    if ((*(longlong **)(lVar3 + 8) != param_1) ||
       (plVar4 = (longlong *)param_1[1], (longlong *)*plVar4 != param_1)) {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
    KeReleaseSpinLock(&DAT_140036808,CONCAT71((int7)((ulonglong)plVar4 >> 8),uVar6));
    cVar7 = KeGetCurrentIrql();
    if (cVar7 == '\0') {
      PgmCleanupSession((longlong)param_1);
    }
    else {
      uVar8 = PgmQueueForDelayedExecution(PgmCleanupSession,param_1,0,param_4,'\0');
      if ((int)uVar8 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                   &WPP_ffb0ebbf543c30978a27a610893f40c5_Traceguids,param_1);
        }
        if (lVar2 != 0) {
          param_1[0xb] = 0;
          PgmIoComplete(lVar2,0,0);
        }
      }
    }
  }
  else {
    KeReleaseSpinLock(plVar4,uVar6);
  }
  return;
}



===== PgmDisconnect @ 140007d0c =====

undefined8 PgmDisconnect(ulonglong param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong *puVar3;
  longlong *****ppppplVar4;
  longlong *****ppppplVar5;
  code *pcVar6;
  longlong ******pppppplVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined8 uVar10;
  char *pcVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  undefined1 uVar15;
  undefined1 uVar14;
  longlong lVar16;
  longlong lVar17;
  ulonglong local_res8;
  longlong ******local_48;
  longlong ******local_40;
  
  uVar13 = 0;
  uVar15 = 0;
  uVar14 = 0;
  local_res8 = param_1 & 0xffffffffffffff00;
  lVar16 = 0;
  lVar1 = *(longlong *)(*(longlong *)(param_3 + 0x30) + 0x18);
  lVar17 = param_3;
  uVar8 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
  if ((((lVar1 == 0) || ((*(int *)(lVar1 + 0x10) + 0xadacbaadU & 0xfeffffff) != 0)) ||
      (lVar16 = *(longlong *)(lVar1 + 0x18), lVar16 == 0)) ||
     (*(int *)(lVar16 + 0x10) != 0x52444441)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                &WPP_ffb0ebbf543c30978a27a610893f40c5_Traceguids,lVar1,(char)lVar16);
    }
    KeReleaseSpinLock(&DAT_140036808,uVar8);
    return 0xc0000008;
  }
  local_40 = (longlong ******)&local_48;
  local_48 = (longlong ******)&local_48;
  IoAcquireCancelSpinLock(&local_res8);
  uVar9 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x168);
  uVar10 = 0;
  if (*(longlong *)(lVar1 + 0x30) == 0) {
    lVar2 = *(longlong *)(lVar1 + 0x28);
    if (lVar2 != 0) {
      if (((*(byte *)(param_3 + 8) & 2) == 0) && ((*(uint *)(lVar1 + 0x20) & 8) == 0)) {
        lVar17 = CONCAT71((int7)((ulonglong)lVar17 >> 8),1);
        uVar10 = PgmCheckSetCancelRoutine(param_2,PgmCancelDisconnectIrp,'\x01');
        if ((int)uVar10 < 0) {
          uVar10 = 0xc0000120;
          goto LAB_140007ed2;
        }
        puVar3 = *(ulonglong **)(param_3 + 0x20);
        if ((puVar3 != (ulonglong *)0x0) &&
           (((int)*puVar3 != -1 || (*(int *)((longlong)puVar3 + 4) != -1)))) {
          uVar12 = -*puVar3;
          uVar13 = uVar12;
          if ((longlong)uVar12 < 0) {
            uVar13 = *puVar3;
          }
          uVar13 = uVar13 / 10000;
          if ((longlong)uVar12 < 0) {
            uVar13 = -uVar13;
          }
          *(longlong *)(*(longlong *)(lVar1 + 0x28) + 0x138) =
               (longlong)uVar13 / 0x14 + *(longlong *)(*(longlong *)(lVar1 + 0x28) + 0x128);
        }
        *(longlong *)(lVar1 + 0x60) = param_2;
        uVar10 = 0x103;
        uVar15 = (char)uVar13;
      }
      else {
        *(undefined8 *)(lVar2 + 0x138) = *(undefined8 *)(lVar2 + 0x128);
      }
    }
  }
  else {
    RemovePendingIrps(lVar1,(longlong)&local_48);
    if ((*(uint *)(lVar1 + 0x20) >> 0xd & 1) == 0) {
      lVar17 = 1;
      *(uint *)(lVar1 + 0x20) = *(uint *)(lVar1 + 0x20) | 0x100;
      CleanupPendingNaks(lVar1,0,1);
    }
  }
  uVar14 = uVar15;
  *(uint *)(lVar1 + 0x20) = *(uint *)(lVar1 + 0x20) | 0x2000;
LAB_140007ed2:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    pcVar11 = "ABORTive";
    if ((*(byte *)(param_3 + 8) & 2) == 0) {
      pcVar11 = "GRACEful";
    }
    WPP_SF_qqqis(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),"GRACEful",lVar17,param_2,(char)lVar1,
                 (char)lVar16,uVar14,pcVar11);
  }
  KeReleaseSpinLock(lVar1 + 0x168,uVar9);
  IoReleaseCancelSpinLock(local_res8 & 0xff);
  KeReleaseSpinLock(&DAT_140036808,uVar8);
  while( true ) {
    pppppplVar7 = local_48;
    if ((longlong *******)local_48 == &local_48) {
      return uVar10;
    }
    ppppplVar4 = *local_48;
    if (((longlong ******)ppppplVar4[1] != local_48) ||
       (ppppplVar5 = local_48[1], (longlong ******)*ppppplVar5 != local_48)) break;
    *ppppplVar5 = (longlong ****)ppppplVar4;
    ppppplVar4[1] = (longlong ****)ppppplVar5;
    PgmCancelCancelRoutine((longlong)(local_48 + -0x15));
    *(undefined4 *)(pppppplVar7 + -0xf) = 0xc0000120;
    IofCompleteRequest(pppppplVar7 + -0x15,2);
  }
  pcVar6 = (code *)swi(0x29);
  (*pcVar6)(3);
  return uVar10;
}



===== PgmSetRcvBufferLength @ 140008034 =====

undefined8 PgmSetRcvBufferLength(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18);
  if (*(uint *)(param_2 + 0x10) < 0x90) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                &WPP_ffb0ebbf543c30978a27a610893f40c5_Traceguids,*(uint *)(param_2 + 0x10),0x90);
    }
    uVar2 = 0xc000000d;
  }
  else if ((lVar1 == 0) || (*(int *)(lVar1 + 0x10) != 0x52534553)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
               &WPP_ffb0ebbf543c30978a27a610893f40c5_Traceguids,lVar1);
    }
    uVar2 = 0xc0000008;
  }
  else {
    *(undefined4 *)(*(longlong *)(lVar1 + 0x30) + 0xf8) = **(undefined4 **)(param_1 + 0x18);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
               &WPP_ffb0ebbf543c30978a27a610893f40c5_Traceguids,
               *(undefined4 *)(*(longlong *)(lVar1 + 0x30) + 0xf8));
    }
    uVar2 = 0;
  }
  return uVar2;
}



===== WPP_SF_DqDD @ 14000812c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DqDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ffb0ebbf543c30978a27a610893f40c5_Traceguids,param_2,local_res20,4,
             &param_5,8,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_qDdddddd @ 1400081a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDdddddd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                    undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                    undefined1 param_9,undefined1 param_10,undefined1 param_11)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ffb0ebbf543c30978a27a610893f40c5_Traceguids,0x1b,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,&param_9,4,&param_10,4,&param_11,4,0);
  return;
}



===== WPP_SF_qDqD @ 14000824c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDqD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ffb0ebbf543c30978a27a610893f40c5_Traceguids,0x10,&local_res20,8,
             &param_5,4,&param_6,8,&param_7,4,0);
  return;
}



===== WPP_SF_qqqis @ 1400082c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqqis(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,char *param_8)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  undefined8 local_res20;
  
  if (param_8 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_8[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  pcVar3 = param_8;
  if (param_8 == (char *)0x0) {
    pcVar3 = "NULL";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ffb0ebbf543c30978a27a610893f40c5_Traceguids,0x1f,&local_res20,8,
             &param_5,8,&param_6,8,&param_7,8,pcVar3,lVar2,0);
  return;
}



===== CleanupInit @ 140008388 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CleanupInit(int param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  undefined8 *puVar7;
  undefined1 *puVar8;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  undefined8 local_18;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_80756061d1e530076809262fec60bbbb_Traceguids,param_1);
  }
  puVar8 = auStack_38;
  if (param_1 != 1) {
    if (param_1 != 2) {
      if ((param_1 != 3) && (param_1 != 4)) {
        if (param_1 != 5) {
          if (param_1 != 6) {
            puVar8 = auStack_38;
            if (param_1 != 7) goto LAB_1400086ad;
            KeClearEvent(&DAT_1400367f0);
            KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
            if (DAT_14003675c == 0) goto LAB_140008485;
            KeReleaseSpinLock(&DAT_140036808);
            local_18 = 0;
            KeWaitForSingleObject(&DAT_1400367f0,0,0,0);
            while( true ) {
              KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
LAB_140008485:
              plVar1 = DAT_140036730;
              if ((longlong **)DAT_140036730 == &DAT_140036730) {
                KeReleaseSpinLock(&DAT_140036808);
                goto LAB_14000853c;
              }
              plVar6 = DAT_140036730 + -4;
              lVar2 = *DAT_140036730;
              plVar3 = (longlong *)DAT_140036730[1];
              if ((*(longlong **)(lVar2 + 8) != DAT_140036730) ||
                 ((longlong *)*plVar3 != DAT_140036730)) break;
              *plVar3 = lVar2;
              *(longlong **)(lVar2 + 8) = plVar3;
              KeReleaseSpinLock(&DAT_140036808);
              pcVar4 = (code *)plVar1[2];
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
                WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                         &WPP_80756061d1e530076809262fec60bbbb_Traceguids,pcVar4);
              }
              (*pcVar4)(plVar1[3],plVar1[4]);
              ExFreePoolWithTag(plVar6,0);
            }
LAB_140008657:
            pcVar4 = (code *)swi(0x29);
            (*pcVar4)(3);
            puVar8 = auStack_30;
            goto LAB_14000865e;
          }
LAB_14000853c:
          TdiDeregisterPnPHandlers(TdiClientHandle);
          while (puVar7 = DAT_140036720, (undefined8 **)DAT_140036720 != &DAT_140036720) {
            puVar5 = (undefined8 *)*DAT_140036720;
            if (((undefined8 **)DAT_140036720[1] != &DAT_140036720) ||
               ((undefined8 *)puVar5[1] != DAT_140036720)) goto LAB_140008657;
            plVar1 = DAT_140036720 + 2;
            DAT_140036720 = puVar5;
            puVar5[1] = &DAT_140036720;
            while (plVar6 = (longlong *)*plVar1, plVar6 != plVar1) {
              lVar2 = *plVar6;
              if (((longlong *)plVar6[1] != plVar1) || (*(longlong **)(lVar2 + 8) != plVar6))
              goto LAB_140008657;
              *plVar1 = lVar2;
              *(longlong **)(lVar2 + 8) = plVar1;
              ExFreePoolWithTag();
            }
            ExFreePoolWithTag(puVar7);
          }
        }
        PgmDereferenceDevice();
      }
      if (pPgmRegistryConfig != 0) {
        if (*(longlong *)(pPgmRegistryConfig + 0x10) != 0) {
          ExFreePoolWithTag(*(longlong *)(pPgmRegistryConfig + 0x10));
          *(undefined8 *)(pPgmRegistryConfig + 0x10) = 0;
        }
        ExFreePoolWithTag();
        pPgmRegistryConfig = 0;
      }
    }
    while (puVar7 = DAT_1400366c0, puVar8 = auStack_38,
          (undefined8 **)DAT_1400366c0 != &DAT_1400366c0) {
      puVar5 = (undefined8 *)*DAT_1400366c0;
      if (((undefined8 **)DAT_1400366c0[1] != &DAT_1400366c0) ||
         ((undefined8 *)puVar5[1] != DAT_1400366c0)) goto LAB_140008657;
      DAT_1400366c0 = puVar5;
      puVar5[1] = &DAT_1400366c0;
      PgmDestroyAddress((longlong)puVar7,0,0);
    }
  }
LAB_14000865e:
  *(undefined8 *)(puVar8 + -8) = 0x14000866c;
  ExDeleteNPagedLookasideList(&DAT_140025dc0);
  *(undefined8 *)(puVar8 + -8) = 0x140008681;
  ExFreePoolWithTag(DAT_140025d18,0);
  if (DAT_140025d20 != 0) {
    DAT_140025da8 = 0;
    *(undefined8 *)(puVar8 + -8) = 0x1400086a0;
    ObfDereferenceObject();
    DAT_140025d20 = 0;
  }
LAB_1400086ad:
  if (PgmSecurityDescriptor != 0) {
    *(undefined8 *)(puVar8 + -8) = 0x1400086c2;
    ExFreePoolWithTag(PgmSecurityDescriptor,0);
    PgmSecurityDescriptor = 0;
  }
  *(undefined8 *)(puVar8 + -8) = 0x1400086d4;
  wil_UninitializeFeatureStaging();
  return;
}



===== CompleteDispatchIrp @ 1400086f4 =====

void CompleteDispatchIrp(longlong param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = param_2;
  PgmCancelCancelRoutine(param_1);
  *(int *)(param_1 + 0x30) = (int)param_2;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
    uVar1 = 0;
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
              &WPP_80756061d1e530076809262fec60bbbb_Traceguids,param_1,(char)param_2);
  }
  IofCompleteRequest(param_1,CONCAT71((int7)((ulonglong)uVar1 >> 8),~-((int)param_2 != 0)) &
                             0xffffffffffffff02);
  return;
}



===== FindEA @ 14000877c =====

uint * FindEA(uint *param_1,char *param_2)

{
  int iVar1;
  
  for (; param_1 != (uint *)0x0; param_1 = (uint *)((longlong)param_1 + (ulonglong)*param_1)) {
    iVar1 = strncmp((char *)(param_1 + 2),param_2,(ulonglong)*(byte *)((longlong)param_1 + 5));
    if (iVar1 == 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
        WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
                 &WPP_80756061d1e530076809262fec60bbbb_Traceguids,param_2);
      }
      return param_1;
    }
    if (*param_1 == 0) break;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
    WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
             &WPP_80756061d1e530076809262fec60bbbb_Traceguids,param_2);
  }
  return (uint *)0x0;
}



===== PgmCancelCancelRoutine @ 140008838 =====

uint PgmCancelCancelRoutine(longlong param_1)

{
  char cVar1;
  undefined1 local_res8 [8];
  
  local_res8[0] = 0;
  IoAcquireCancelSpinLock(local_res8);
  cVar1 = *(char *)(param_1 + 0x44);
  LOCK();
  *(undefined8 *)(param_1 + 0x68) = 0;
  UNLOCK();
  IoReleaseCancelSpinLock(local_res8[0]);
  return -(uint)(cVar1 != '\0') & 0xc0000120;
}



===== PgmCheckSetCancelRoutine @ 14000889c =====

undefined8 PgmCheckSetCancelRoutine(longlong param_1,undefined8 param_2,char param_3)

{
  byte *pbVar1;
  undefined8 uVar2;
  undefined1 local_res18 [16];
  
  local_res18[0] = 0;
  if (param_3 == '\0') {
    IoAcquireCancelSpinLock(local_res18);
  }
  if (*(char *)(param_1 + 0x44) == '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_1 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    LOCK();
    *(undefined8 *)(param_1 + 0x68) = param_2;
    UNLOCK();
    uVar2 = 0;
  }
  else {
    uVar2 = 0xc0000120;
    *(undefined4 *)(param_1 + 0x30) = 0xc0000120;
  }
  if (param_3 == '\0') {
    IoReleaseCancelSpinLock(local_res18[0]);
  }
  return uVar2;
}



===== PgmDispatchCleanup @ 140008920 =====

ulonglong PgmDispatchCleanup(undefined8 param_1,longlong param_2)

{
  undefined1 uVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined2 uVar5;
  ulonglong uVar6;
  longlong lVar7;
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  uVar6 = 0;
  uVar1 = *(undefined1 *)(lVar3 + 3);
  plVar4 = *(longlong **)(*(longlong *)(lVar3 + 0x30) + 0x18);
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0x103;
  *(byte *)(lVar3 + 3) = *(byte *)(lVar3 + 3) | 1;
  lVar7 = *(longlong *)(lVar3 + 0x30);
  iVar2 = *(int *)(lVar7 + 0x20);
  if (iVar2 == 1) {
    uVar6 = PgmCleanupAddress((longlong)plVar4);
    uVar6 = uVar6 & 0xffffffff;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      uVar5 = 0x15;
LAB_140008a58:
      WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,lVar7,plVar4,(char)param_2,
                 (char)uVar6);
    }
  }
  else {
    if (iVar2 != 2) {
      if (iVar2 == 3) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
          WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,lVar7,plVar4,(char)param_2,0);
        }
      }
      else {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          WPP_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                     &WPP_80756061d1e530076809262fec60bbbb_Traceguids,param_2,(char)plVar4,
                     (char)*(undefined8 *)(lVar7 + 0x20));
        }
        uVar6 = 0xc000000d;
      }
      goto LAB_140008a75;
    }
    uVar6 = PgmCleanupConnection(plVar4,param_2);
    uVar6 = uVar6 & 0xffffffff;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      uVar5 = 0x16;
      goto LAB_140008a58;
    }
  }
  if ((int)uVar6 == 0x103) {
    return uVar6;
  }
LAB_140008a75:
  *(undefined1 *)(lVar3 + 3) = uVar1;
  CompleteDispatchIrp(param_2,uVar6);
  return uVar6;
}



===== PgmDispatchClose @ 140008ab0 =====

ulonglong PgmDispatchClose(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  ulonglong uVar7;
  undefined2 uVar8;
  ulonglong uVar9;
  
  lVar4 = *(longlong *)(param_2 + 0xb8);
  uVar9 = 0;
  uVar2 = *(undefined1 *)(lVar4 + 3);
  lVar5 = *(longlong *)(*(longlong *)(lVar4 + 0x30) + 0x18);
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0x103;
  *(byte *)(lVar4 + 3) = *(byte *)(lVar4 + 3) | 1;
  plVar6 = *(longlong **)(lVar4 + 0x30);
  iVar3 = (int)plVar6[4];
  if (iVar3 == 1) {
    uVar7 = PgmCloseAddress(param_2,lVar4,param_3,plVar6);
    uVar9 = uVar7 & 0xffffffff;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      uVar8 = 0x19;
LAB_140008c36:
      WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,param_3,lVar5,(char)param_2,
                 (char)uVar7);
    }
  }
  else {
    if (iVar3 != 2) {
      if (iVar3 == 3) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
          WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,param_3,plVar6[3],(char)param_2
                     ,0);
        }
        piVar1 = (int *)(lVar5 + 0x14);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
            WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                     &WPP_bb24dc9f99d8356a0c4778f616204a55_Traceguids,lVar5);
          }
          ExFreePoolWithTag(lVar5,0);
        }
      }
      else {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          WPP_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                     &WPP_80756061d1e530076809262fec60bbbb_Traceguids,param_2,(char)plVar6[3],
                     (char)plVar6[4]);
        }
        uVar9 = 0xc000000d;
      }
      goto LAB_140008c4f;
    }
    uVar7 = PgmCloseConnection(0,lVar4);
    uVar9 = uVar7 & 0xffffffff;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      uVar8 = 0x1a;
      goto LAB_140008c36;
    }
  }
  if ((int)uVar9 == 0x103) {
    return uVar9;
  }
LAB_140008c4f:
  *(undefined1 *)(lVar4 + 3) = uVar2;
  CompleteDispatchIrp(param_2,uVar9);
  return uVar9;
}



===== PgmDispatchCreate @ 140008c80 =====

ulonglong PgmDispatchCreate(undefined8 param_1,longlong param_2)

{
  undefined1 uVar1;
  longlong *plVar2;
  uint uVar3;
  longlong lVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  undefined8 uVar8;
  undefined2 uVar9;
  char *pcVar10;
  ulonglong uVar11;
  
  plVar2 = *(longlong **)(param_2 + 0xb8);
  uVar11 = 0;
  puVar7 = *(uint **)(param_2 + 0x18);
  uVar1 = *(undefined1 *)((longlong)plVar2 + 3);
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0x103;
  *(byte *)((longlong)plVar2 + 3) = *(byte *)((longlong)plVar2 + 3) | 1;
  if (puVar7 == (uint *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
               &WPP_80756061d1e530076809262fec60bbbb_Traceguids,plVar2[6]);
    }
    lVar4 = ExAllocatePool2(0x40,0x28,0x306d6750);
    if (lVar4 == 0) {
      uVar11 = 0xc000009a;
    }
    else {
      *(longlong *)(lVar4 + 8) = lVar4;
      *(longlong *)lVar4 = lVar4;
      KeInitializeSpinLock(lVar4 + 0x18);
      *(int *)(lVar4 + 0x14) = *(int *)(lVar4 + 0x14) + 1;
      *(undefined4 *)(lVar4 + 0x10) = 0x544e4f43;
      *(longlong *)(plVar2[6] + 0x18) = lVar4;
      *(undefined8 *)(plVar2[6] + 0x20) = 3;
    }
    goto LAB_140008e39;
  }
  pcVar10 = "ConnectionContext";
  puVar6 = puVar7;
  puVar5 = FindEA(puVar7,"ConnectionContext");
  if (puVar5 == (uint *)0x0) {
    pcVar10 = "TransportAddress";
    puVar6 = FindEA(puVar7,"TransportAddress");
    if (puVar6 == (uint *)0x0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                &WPP_80756061d1e530076809262fec60bbbb_Traceguids);
      }
      uVar11 = 0x80000013;
      goto LAB_140008e39;
    }
    uVar3 = PgmCreateAddress((ulonglong)puVar7,(ulonglong)pcVar10,plVar2,(longlong)puVar6);
    uVar11 = (ulonglong)uVar3;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      uVar8 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      uVar9 = 0x13;
      goto LAB_140008de8;
    }
  }
  else {
    uVar11 = PgmCreateConnection(puVar6,pcVar10,(longlong)plVar2,(longlong)puVar5);
    uVar11 = uVar11 & 0xffffffff;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      uVar8 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      uVar9 = 0x12;
LAB_140008de8:
      WPP_SF_qD(uVar8,uVar9,&WPP_80756061d1e530076809262fec60bbbb_Traceguids,param_2,(char)uVar11);
    }
  }
  if ((int)uVar11 == 0x103) {
    return uVar11;
  }
LAB_140008e39:
  *(undefined1 *)((longlong)plVar2 + 3) = uVar1;
  CompleteDispatchIrp(param_2,uVar11);
  return uVar11;
}



===== PgmDispatchDeviceControl @ 140008e70 =====

ulonglong PgmDispatchDeviceControl(longlong param_1,undefined8 ****param_2)

{
  undefined1 uVar1;
  undefined8 ****ppppuVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined8 ****ppppuVar7;
  undefined8 ****ppppuVar8;
  
  ppppuVar2 = (undefined8 ****)param_2[0x17];
  uVar1 = *(undefined1 *)((longlong)ppppuVar2 + 3);
  ppppuVar7 = param_2;
  ppppuVar8 = ppppuVar2;
  iVar3 = TdiMapUserRequest();
  if (iVar3 == 0) {
    uVar5 = PgmDispatchInternalDeviceControl(param_1,param_2,(undefined *)ppppuVar8);
    return uVar5;
  }
  param_2[7] = (undefined8 ***)0x0;
  *(undefined4 *)(param_2 + 6) = 0x103;
  *(byte *)((longlong)param_2[0x17] + 3) = *(byte *)((longlong)param_2[0x17] + 3) | 1;
  uVar4 = *(uint *)(ppppuVar2 + 3);
  if (uVar4 < 0x120029) {
    if (uVar4 == 0x120028) {
      ppppuVar7 = ppppuVar2;
      uVar6 = PgmQueryLateJoinerPercentage((longlong)param_2,(longlong)ppppuVar2);
      uVar4 = (uint)uVar6;
    }
    else if (uVar4 < 0x120015) {
      if (uVar4 == 0x120014) {
        ppppuVar7 = ppppuVar2;
        uVar6 = PgmSetWindowSizeAndSendRate((longlong)param_2,(ulonglong)ppppuVar2);
        uVar4 = (uint)uVar6;
      }
      else if (uVar4 == 0x120000) {
        ppppuVar7 = ppppuVar2;
        uVar4 = PgmSetMCastOutIf((longlong)param_2,(longlong)ppppuVar2);
      }
      else if (uVar4 == 0x120004) {
LAB_140008f41:
        ppppuVar7 = ppppuVar2;
        uVar5 = PgmAddMCastReceiveIf((longlong)param_2,(longlong)ppppuVar2);
        uVar4 = (uint)uVar5;
      }
      else if (uVar4 == 0x120008) {
        ppppuVar7 = ppppuVar2;
        uVar4 = PgmDelMCastReceiveIf((longlong)param_2,(longlong)ppppuVar2);
      }
      else {
        if (uVar4 == 0x12000c) goto LAB_140008f41;
        if (uVar4 != 0x120010) goto LAB_140009085;
        ppppuVar7 = ppppuVar2;
        uVar6 = PgmSetRcvBufferLength((longlong)param_2,(longlong)ppppuVar2);
        uVar4 = (uint)uVar6;
      }
    }
    else if (uVar4 == 0x120018) {
      ppppuVar7 = ppppuVar2;
      uVar6 = PgmQueryWindowSizeAndSendRate((longlong)param_2,(longlong)ppppuVar2);
      uVar4 = (uint)uVar6;
    }
    else if (uVar4 == 0x12001c) {
      ppppuVar7 = ppppuVar2;
      uVar6 = PgmSetWindowAdvanceRate((longlong)param_2,(longlong)ppppuVar2);
      uVar4 = (uint)uVar6;
    }
    else if (uVar4 == 0x120020) {
      ppppuVar7 = ppppuVar2;
      uVar6 = PgmQueryWindowAdvanceRate((longlong)param_2,(longlong)ppppuVar2);
      uVar4 = (uint)uVar6;
    }
    else {
      if (uVar4 != 0x120024) goto LAB_140009085;
      ppppuVar7 = ppppuVar2;
      uVar6 = PgmSetLateJoinerPercentage((longlong)param_2,(longlong)ppppuVar2);
      uVar4 = (uint)uVar6;
    }
  }
  else if (uVar4 < 0x120041) {
    if (uVar4 == 0x120040) {
      ppppuVar7 = ppppuVar2;
      uVar6 = PgmQueryReceiverStats((longlong)param_2,(longlong)ppppuVar2);
      uVar4 = (uint)uVar6;
    }
    else if (uVar4 == 0x12002c) {
      ppppuVar7 = ppppuVar2;
      uVar6 = PgmSetNextMessageBoundary((longlong)param_2,(longlong)ppppuVar2);
      uVar4 = (uint)uVar6;
    }
    else if (uVar4 == 0x120030) {
      ppppuVar7 = ppppuVar2;
      uVar6 = PgmQuerySenderStats((longlong)param_2,(longlong)ppppuVar2);
      uVar4 = (uint)uVar6;
    }
    else if (uVar4 == 0x120034) {
      ppppuVar7 = ppppuVar2;
      uVar6 = PgmSetFECInfo((longlong)param_2,(longlong)ppppuVar2);
      uVar4 = (uint)uVar6;
    }
    else if (uVar4 == 0x120038) {
      ppppuVar7 = ppppuVar2;
      uVar6 = PgmSetMCastTtl((longlong)param_2,(longlong)ppppuVar2);
      uVar4 = (uint)uVar6;
    }
    else {
      if (uVar4 != 0x12003c) goto LAB_140009085;
      ppppuVar7 = ppppuVar2;
      uVar6 = PgmQueryFecInfo((longlong)param_2,(longlong)ppppuVar2);
      uVar4 = (uint)uVar6;
    }
  }
  else if (uVar4 == 0x120044) {
    ppppuVar7 = ppppuVar2;
    uVar4 = PgmSetWindowAdvanceMethod((longlong)param_2,(longlong)ppppuVar2);
  }
  else if (uVar4 == 0x120048) {
    ppppuVar7 = ppppuVar2;
    uVar6 = PgmQueryWindowAdvanceMethod((longlong)param_2,(longlong)ppppuVar2);
    uVar4 = (uint)uVar6;
  }
  else if (uVar4 == 0x12004c) {
    ppppuVar7 = ppppuVar2;
    uVar6 = PgmSetHighSpeedOptimization((longlong)param_2,(longlong)ppppuVar2);
    uVar4 = (uint)uVar6;
  }
  else {
    if (uVar4 != 0x120050) {
LAB_140009085:
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
        ppppuVar8 = (undefined8 ****)&WPP_80756061d1e530076809262fec60bbbb_Traceguids;
        ppppuVar7 = (undefined8 ****)0x1f;
        WPP_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                  &WPP_80756061d1e530076809262fec60bbbb_Traceguids,uVar4,(char)ppppuVar2[6][3]);
      }
      uVar5 = 0xc0000002;
      goto LAB_1400090f5;
    }
    ppppuVar7 = ppppuVar2;
    uVar6 = PgmQueryHighSpeedOptimization((longlong)param_2,(longlong)ppppuVar2);
    uVar4 = (uint)uVar6;
  }
  uVar5 = (ulonglong)uVar4;
LAB_1400090f5:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
    WPP_SF_dqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),ppppuVar7,ppppuVar8,
               *(undefined4 *)(ppppuVar2 + 3),(char)ppppuVar2[6][3],(char)uVar5);
  }
  if ((int)uVar5 != 0x103) {
    *(undefined1 *)((longlong)ppppuVar2 + 3) = uVar1;
    CompleteDispatchIrp((longlong)param_2,uVar5);
  }
  return uVar5;
}



===== PgmDispatchInternalDeviceControl @ 140009160 =====

ulonglong PgmDispatchInternalDeviceControl
                    (longlong param_1,undefined8 ****param_2,undefined *param_3)

{
  undefined1 uVar1;
  byte bVar2;
  undefined8 ***pppuVar3;
  longlong lVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 ****ppppuVar7;
  ulonglong uVar8;
  
  pppuVar3 = param_2[0x17];
  lVar4 = *(longlong *)(param_1 + 0x40);
  uVar1 = *(undefined1 *)((longlong)pppuVar3 + 3);
  ppppuVar7 = param_2;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
    param_3 = &WPP_80756061d1e530076809262fec60bbbb_Traceguids;
    ppppuVar7 = (undefined8 ****)0x1d;
    WPP_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
              &WPP_80756061d1e530076809262fec60bbbb_Traceguids,
              (uint)*(byte *)((longlong)pppuVar3 + 1),(char)pppuVar3[6][3]);
  }
  param_2[7] = (undefined8 ***)0x0;
  *(undefined4 *)(param_2 + 6) = 0x103;
  *(byte *)((longlong)param_2[0x17] + 3) = *(byte *)((longlong)param_2[0x17] + 3) | 1;
  bVar2 = *(byte *)((longlong)pppuVar3 + 1);
  if (bVar2 == 1) {
    uVar6 = PgmAssociateAddress(0,(longlong)param_2,(longlong)pppuVar3);
    uVar5 = (uint)uVar6;
  }
  else if (bVar2 == 2) {
    uVar6 = PgmDisassociateAddress((longlong)param_2,(longlong)pppuVar3,param_3,(longlong *)0x2);
    uVar5 = (uint)uVar6;
  }
  else if (bVar2 == 3) {
    uVar5 = PgmConnect(lVar4,(ulonglong)param_2,(longlong)pppuVar3);
  }
  else if (bVar2 == 6) {
    uVar6 = PgmDisconnect(0,(longlong)param_2,(longlong)pppuVar3);
    uVar5 = (uint)uVar6;
  }
  else if (bVar2 == 7) {
    uVar8 = PgmSendRequestFromClient(lVar4,(longlong *)param_2,(longlong)pppuVar3);
    uVar5 = (uint)uVar8;
  }
  else if (bVar2 == 8) {
    uVar6 = PgmReceive(0,(longlong)param_2,(longlong)pppuVar3);
    uVar5 = (uint)uVar6;
  }
  else if (bVar2 == 0xb) {
    uVar5 = PgmSetEventHandler(0,ppppuVar7,(ulonglong *)pppuVar3);
  }
  else {
    if (bVar2 != 0xc) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
        WPP_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                  &WPP_80756061d1e530076809262fec60bbbb_Traceguids,(uint)bVar2,(char)pppuVar3[6][3])
        ;
      }
      uVar8 = 0xc0000002;
      goto LAB_1400092d3;
    }
    uVar5 = PgmQueryInformation(lVar4,(longlong)param_2,(longlong)pppuVar3);
  }
  uVar8 = (ulonglong)uVar5;
  if (uVar5 == 0x103) {
    return 0x103;
  }
LAB_1400092d3:
  *(undefined1 *)((longlong)pppuVar3 + 3) = uVar1;
  CompleteDispatchIrp((longlong)param_2,uVar8);
  return uVar8;
}



===== PgmIoComplete @ 140009308 =====

void PgmIoComplete(longlong param_1,undefined8 param_2,ulonglong param_3)

{
  undefined8 uVar1;
  ulonglong uVar2;
  
  *(int *)(param_1 + 0x30) = (int)param_2;
  if ((int)param_3 != -1) {
    *(ulonglong *)(param_1 + 0x38) = param_3 & 0xffffffff;
  }
  uVar1 = param_2;
  uVar2 = param_3;
  PgmCancelCancelRoutine(param_1);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
    WPP_SF_qDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar1,uVar2,param_1,(char)param_2,
               (char)param_3);
  }
  IofCompleteRequest(param_1,2);
  return;
}



===== WPP_SF_dqD @ 140009388 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dqD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_80756061d1e530076809262fec60bbbb_Traceguids,0x20,local_res20,4,
             &param_5,8,&param_6,4,0);
  return;
}



===== WPP_SF_qDd @ 1400093f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_80756061d1e530076809262fec60bbbb_Traceguids,0x23,&local_res20,8,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_qqD @ 140009458 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_80756061d1e530076809262fec60bbbb_Traceguids,param_2,&local_res20,8,
             &param_5,8,&param_6,4,0);
  return;
}



===== WppClassicProviderCallback @ 1400094c0 =====

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



===== wil_details_FeatureDescriptors_SkipPadding @ 1400094f4 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_140024dff < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 14000951c =====

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



===== wil_details_RecordFeatureUsageReporting @ 140009670 =====

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



===== AddSelectiveNakToList @ 1400096f4 =====

undefined8 AddSelectiveNakToList(ushort param_1,longlong param_2)

{
  byte bVar1;
  byte bVar2;
  
  if (param_1 < 0x80) {
    bVar2 = '\x01' << ((byte)param_1 & 7);
    bVar1 = *(byte *)((ulonglong)(param_1 >> 3) + 0x40 + param_2);
    if ((bVar2 & bVar1) == 0) {
      *(byte *)((ulonglong)(param_1 >> 3) + 0x40 + param_2) = bVar1 | bVar2;
      return 1;
    }
  }
  return 0;
}



===== AnyMoreNaks @ 140009738 =====

bool AnyMoreNaks(longlong param_1)

{
  if ((*(short *)(param_1 + 0x3a) == 0) && (*(longlong *)(param_1 + 0x40) == 0)) {
    return *(longlong *)(param_1 + 0x48) != 0;
  }
  return true;
}



===== AppendPendingReceiverEntry @ 14000975c =====

void AppendPendingReceiverEntry(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong lVar4;
  
  plVar1 = (longlong *)(param_2 + 0x40);
  lVar4 = ((ulonglong)(*(uint *)(param_2 + 0x10) >> (*(byte *)(param_1 + 0xe6) & 0x1f) & 0xffff) &
          (ulonglong)*(ushort *)(param_1 + 0xe0)) * 0x10 + *(longlong *)(param_1 + 0xd8);
  plVar2 = *(longlong **)(lVar4 + 8);
  if (*plVar2 == lVar4) {
    *(longlong **)(param_2 + 0x48) = plVar2;
    *plVar1 = lVar4;
    *plVar2 = (longlong)plVar1;
    plVar2 = (longlong *)(param_2 + 0x50);
    *(longlong **)(lVar4 + 8) = plVar1;
    plVar1 = *(longlong **)(param_1 + 0xc0);
    if (*plVar1 == param_1 + 0xb8) {
      *plVar2 = param_1 + 0xb8;
      *(longlong **)(param_2 + 0x58) = plVar1;
      *plVar1 = (longlong)plVar2;
      *(longlong **)(param_1 + 0xc0) = plVar2;
      return;
    }
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== DestroyEntry @ 1400097d0 =====

void DestroyEntry(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  
  plVar1 = (longlong *)(param_2 + 0x50);
  lVar2 = *plVar1;
  if ((*(longlong **)(lVar2 + 8) == plVar1) &&
     (plVar3 = *(longlong **)(param_2 + 0x58), (longlong *)*plVar3 == plVar1)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    ExFreeToNPagedLookasideList(param_1 + 0x40);
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;
    return;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== DestroyRDataInfo @ 140009820 =====

void DestroyRDataInfo(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x108);
  ExDeleteNPagedLookasideList(lVar1 + 0x40);
  ExFreePoolWithTag(*(undefined8 *)(lVar1 + 0x38),0);
  ExFreePoolWithTag(lVar1,0);
  *(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x108) = 0;
  return;
}



===== FilterAndAddNaksToList @ 14000988c =====

undefined8 FilterAndAddNaksToList(longlong param_1,longlong param_2)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong *plVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  int iVar10;
  longlong *plVar11;
  longlong lVar12;
  longlong *plVar13;
  longlong *plVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  uint uVar17;
  
  lVar5 = *(longlong *)(param_1 + 0x28);
  bVar1 = *(byte *)(param_1 + 0xa0);
  uVar16 = 0;
  plVar6 = *(longlong **)(lVar5 + 0x108);
  plVar13 = (longlong *)0x0;
  uVar15 = 0;
  uVar17 = *(uint *)(*(longlong *)(param_1 + 0x18) + 0x38) & 0x10;
  uVar3 = *(uint *)(lVar5 + 0x9c);
  do {
    if (*(ushort *)(param_2 + 0xfc) <= (ushort)uVar15) {
      *(short *)(param_2 + 0xfc) = (short)uVar16;
      return 0;
    }
    uVar4 = *(uint *)(param_2 + uVar15 * 4);
    if ((longlong *)*plVar6 != plVar6) {
      plVar14 = (longlong *)
                ((ulonglong)(uVar4 >> ((byte)plVar6[6] & 0x1f) & *(uint *)((longlong)plVar6 + 0x2c))
                 * 0x10 + plVar6[7]);
      plVar11 = plVar14;
      do {
        plVar11 = (longlong *)*plVar11;
        if (plVar11 == plVar14) break;
        plVar7 = plVar11 + -10;
        if (*(uint *)(plVar11 + -8) == uVar4) {
          if (plVar7 != (longlong *)0x0) {
            if (plVar11[-5] == 0) {
              if ((*(byte *)(param_2 + 0xfe) & 1) == 0) {
                uVar2 = *(ushort *)(param_2 + 0x100 + uVar15 * 2);
                if (*(ushort *)((longlong)plVar11 + -0x16) < uVar2) {
                  *(longlong *)(lVar5 + 0x368) =
                       *(longlong *)(lVar5 + 0x368) +
                       ((ulonglong)uVar2 - (ulonglong)*(ushort *)((longlong)plVar11 + -0x16));
                  *(ushort *)((longlong)plVar11 + -0x16) = uVar2;
                }
                goto LAB_140009bab;
              }
              if (*(char *)(param_1 + 0xa1) == '\0') {
                *(undefined1 *)(plVar11 + -2) = 1;
                goto LAB_140009bab;
              }
              if ((*(short *)((longlong)plVar11 + -0x16) != 0) ||
                 (-1 < (int)(uVar4 - (-(uint)bVar1 & uVar3)))) {
                uVar8 = AddSelectiveNakToList
                                  (*(ushort *)(param_2 + 0x100 + uVar15 * 2),(longlong)plVar7);
                if ((char)uVar8 != '\0') {
                  *(longlong *)(lVar5 + 0x368) = *(longlong *)(lVar5 + 0x368) + 1;
                }
                goto LAB_140009bab;
              }
            }
            else if ((plVar11[-6] != 0) && ((ulonglong)plVar11[-5] <= *(ulonglong *)(lVar5 + 0x128))
                    ) {
              *(int *)(lVar5 + 0x94) = *(int *)(lVar5 + 0x94) + 1;
              plVar11[-5] = 0;
              *(undefined2 *)((longlong)plVar11 + -0x16) = 0;
              plVar11[-2] = 0;
              plVar11[-1] = 0;
              if (*(char *)(param_1 + 0xa1) == '\0') {
                *(undefined1 *)(plVar11 + -2) = 1;
LAB_1400099df:
                *(longlong *)(lVar5 + 0x368) = *(longlong *)(lVar5 + 0x368) + 1;
              }
              else {
                uVar2 = *(ushort *)(param_2 + 0x100 + uVar15 * 2);
                if ((*(byte *)(param_2 + 0xfe) & 1) == 0) {
                  *(ushort *)((longlong)plVar11 + -0x16) = uVar2;
                  *(longlong *)(lVar5 + 0x368) = *(longlong *)(lVar5 + 0x368) + (ulonglong)uVar2;
                }
                else {
                  uVar8 = AddSelectiveNakToList(uVar2,(longlong)plVar7);
                  if ((char)uVar8 != '\0') goto LAB_1400099df;
                }
              }
              iVar10 = *(int *)(lVar5 + 0x9c) - *(int *)(lVar5 + 0xa4);
              if (iVar10 < 1) {
                plVar7[3] = 0;
                if (uVar17 != 0) goto LAB_140009a51;
                lVar12 = *(longlong *)(lVar5 + 0x150);
              }
              else {
                uVar9 = ((ulonglong)(uint)((int)plVar7[2] - *(int *)(lVar5 + 0xa4)) *
                        *(longlong *)(lVar5 + 0x150)) / (ulonglong)(iVar10 + 1);
                plVar7[3] = *(longlong *)(lVar5 + 0x128) + uVar9;
                if (uVar17 == 0) {
                  lVar12 = *(longlong *)(lVar5 + 0x150) - uVar9;
                }
                else {
LAB_140009a51:
                  lVar12 = 0;
                }
              }
              plVar7[4] = lVar12;
              goto LAB_140009bab;
            }
            *(longlong *)(lVar5 + 0x370) = *(longlong *)(lVar5 + 0x370) + 1;
            goto LAB_140009bd2;
          }
          break;
        }
      } while ((int)(*(uint *)(plVar11 + -8) - uVar4) < 1);
    }
    plVar7 = InsertEntry(param_1,uVar4,plVar6,plVar13);
    lVar12 = 0;
    if (plVar7 == (longlong *)0x0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                &WPP_418d3fcde53e33810bba05463ad55e60_Traceguids);
      }
      return 0xc000009a;
    }
    plVar7[6] = param_1;
    if (*(char *)(param_1 + 0xa1) == '\0') {
      *(undefined1 *)(plVar7 + 8) = 1;
LAB_140009af6:
      *(longlong *)(lVar5 + 0x368) = *(longlong *)(lVar5 + 0x368) + 1;
    }
    else {
      uVar2 = *(ushort *)(param_2 + 0x100 + uVar15 * 2);
      if ((*(byte *)(param_2 + 0xfe) & 1) != 0) {
        AddSelectiveNakToList(uVar2,(longlong)plVar7);
        goto LAB_140009af6;
      }
      *(ushort *)((longlong)plVar7 + 0x3a) = uVar2;
      *(longlong *)(lVar5 + 0x368) = *(longlong *)(lVar5 + 0x368) + (ulonglong)uVar2;
    }
    iVar10 = *(int *)(lVar5 + 0x9c) - *(int *)(lVar5 + 0xa4);
    *(int *)(lVar5 + 0x94) = *(int *)(lVar5 + 0x94) + 1;
    if (iVar10 < 1) {
      plVar7[3] = lVar12;
      if (uVar17 == 0) {
        lVar12 = *(longlong *)(lVar5 + 0x150);
      }
    }
    else {
      uVar9 = ((ulonglong)(uint)((int)plVar7[2] - *(int *)(lVar5 + 0xa4)) *
              *(longlong *)(lVar5 + 0x150)) / (ulonglong)(iVar10 + 1);
      plVar7[3] = *(longlong *)(lVar5 + 0x128) + uVar9;
      if (uVar17 == 0) {
        lVar12 = *(longlong *)(lVar5 + 0x150) - uVar9;
      }
    }
    plVar7[4] = lVar12;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
               &WPP_418d3fcde53e33810bba05463ad55e60_Traceguids,
               *(undefined4 *)(param_2 + uVar15 * 4));
    }
LAB_140009bab:
    *(undefined4 *)(param_2 + uVar16 * 4) = *(undefined4 *)(param_2 + uVar15 * 4);
    *(undefined2 *)(param_2 + 0x100 + uVar16 * 2) = *(undefined2 *)(param_2 + 0x100 + uVar15 * 2);
    plVar13 = plVar7;
    uVar16 = (ulonglong)(byte)((char)uVar16 + 1);
LAB_140009bd2:
    uVar15 = (ulonglong)(byte)((char)uVar15 + 1);
  } while( true );
}



===== FindFirstEntry @ 140009c3c =====

longlong * FindFirstEntry(longlong param_1,undefined8 *param_2,char param_3)

{
  int iVar1;
  longlong lVar2;
  longlong *plVar3;
  ulonglong uVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong *plVar7;
  
  lVar2 = *(longlong *)(param_1 + 0x28);
  plVar3 = *(longlong **)(lVar2 + 0x108);
  iVar1 = *(int *)(lVar2 + 0x90);
  uVar4 = *(ulonglong *)(lVar2 + 0x128);
  if ((longlong *)*plVar3 != plVar3) {
    if ((param_2 == (undefined8 *)0x0) || (plVar6 = (longlong *)*param_2, plVar6 == (longlong *)0x0)
       ) {
      plVar7 = (longlong *)0x0;
      plVar6 = plVar3;
    }
    else {
      plVar7 = plVar6;
    }
    while (plVar6 = (longlong *)*plVar6, plVar6 != plVar3) {
      if (plVar6[5] == 0) {
        if (((param_3 != '\0') || (iVar1 == 0)) || ((ulonglong)plVar6[3] <= uVar4)) {
          if (param_2 != (undefined8 *)0x0) {
            *param_2 = plVar7;
          }
          return plVar6;
        }
        plVar7 = plVar6;
      }
      else if (((short)plVar6[7] == 0) && ((ulonglong)plVar6[5] < uVar4)) {
        *(undefined2 *)((longlong)plVar6 + 0x3a) = 0;
        plVar6[8] = 0;
        plVar6[9] = 0;
        plVar5 = (longlong *)plVar6[1];
        RemoveEntry((longlong)plVar3,plVar6);
        DestroyEntry((longlong)plVar3,(longlong)plVar6);
        plVar6 = plVar5;
      }
    }
    if (param_2 != (undefined8 *)0x0) {
      *param_2 = 0;
    }
  }
  return (longlong *)0x0;
}



===== FindReceiverEntry @ 140009d30 =====

longlong FindReceiverEntry(longlong param_1,uint param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  
  plVar2 = (longlong *)
           (*(longlong *)(param_1 + 0xd8) +
           ((ulonglong)(param_2 >> (*(byte *)(param_1 + 0xe6) & 0x1f) & 0xffff) &
           (ulonglong)*(ushort *)(param_1 + 0xe0)) * 0x10);
  plVar1 = plVar2;
  while( true ) {
    plVar1 = (longlong *)*plVar1;
    if (plVar1 == plVar2) {
      return 0;
    }
    if (*(uint *)(plVar1 + -6) == param_2) break;
    if (0 < (int)(*(uint *)(plVar1 + -6) - param_2)) {
      return 0;
    }
  }
  return (longlong)(plVar1 + -8);
}



===== GetNextNakIndex @ 140009d84 =====

undefined1 GetNextNakIndex(longlong param_1,char *param_2)

{
  byte bVar1;
  char cVar2;
  ulonglong uVar3;
  
  cVar2 = '\0';
  bVar1 = 0;
  while( true ) {
    if (0xf < bVar1) {
      *param_2 = -0x80;
      return 0;
    }
    uVar3 = (ulonglong)bVar1;
    if (*(char *)(uVar3 + 0x40 + param_1) != '\0') break;
    cVar2 = cVar2 + '\b';
    bVar1 = bVar1 + 1;
  }
  bVar1 = *(byte *)(uVar3 + 0x40 + param_1);
  *(byte *)(uVar3 + 0x40 + param_1) = ~(-bVar1 & bVar1) & bVar1;
  *param_2 = cVar2 + (&gFECLog2)[-bVar1 & bVar1];
  return 1;
}



===== InitRDataInfo @ 140009df4 =====

undefined8 InitRDataInfo(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong lVar6;
  int iVar7;
  uint uVar8;
  ushort uVar9;
  
  lVar1 = *(longlong *)(param_2 + 0x28);
  if (*(longlong *)(lVar1 + 0x108) == 0) {
    lVar3 = ExAllocatePool2(0x40,0x1c0,0x536d6750);
    if (lVar3 == 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_418d3fcde53e33810bba05463ad55e60_Traceguids);
      }
    }
    else {
      *(longlong *)(lVar3 + 8) = lVar3;
      *(longlong *)lVar3 = lVar3;
      *(undefined4 *)(lVar3 + 0x28) = 0x8000;
      *(undefined4 *)(lVar3 + 0x2c) = 0x7fff;
      *(uint *)(lVar3 + 0x30) = (uint)(byte)(&gFECLog2)[*(byte *)(param_2 + 0xa0)];
      lVar4 = ExAllocatePool2(0x40,0x80000,0x736d6750);
      if (lVar4 != 0) {
        iVar7 = (uint)*(byte *)(param_2 + 0xa0) * 8 + 0x70;
        *(int *)(lVar3 + 0x10) = iVar7;
        ExInitializeNPagedLookasideList
                  (lVar3 + 0x40,0,0,0x200,iVar7,0x526d6750,
                   (-(ushort)((*(uint *)(param_1 + 0x38) & 0x10) != 0) & 1000) + 1000);
        uVar8 = 0;
        for (uVar5 = *(ulonglong *)(lVar1 + 0x60); uVar5 != 0; uVar5 = uVar5 >> 1) {
          uVar8 = uVar8 + 1;
        }
        *(undefined4 *)(lVar3 + 0x1c) = 0x20;
        *(undefined4 *)(lVar3 + 0x18) = 0x1f;
        iVar7 = 0;
        if (4 < uVar8) {
          iVar7 = uVar8 - 5;
        }
        *(int *)(lVar3 + 0x14) = iVar7;
        *(longlong *)(lVar3 + 0x38) = lVar4;
        uVar5 = 0;
        if (*(int *)(lVar3 + 0x28) != 0) {
          do {
            uVar9 = (short)uVar5 + 1;
            lVar6 = uVar5 * 0x10 + lVar4;
            *(longlong *)(lVar6 + 8) = lVar6;
            *(longlong *)lVar6 = lVar6;
            uVar5 = (ulonglong)uVar9;
          } while ((uint)uVar9 < *(uint *)(lVar3 + 0x28));
        }
        *(longlong *)(lVar1 + 0x108) = lVar3;
        return 0;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                &WPP_418d3fcde53e33810bba05463ad55e60_Traceguids);
      }
      ExFreePoolWithTag(lVar3,0);
    }
    uVar2 = 0xc000009a;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_418d3fcde53e33810bba05463ad55e60_Traceguids,param_2);
    }
    uVar2 = 0xc0000001;
  }
  return uVar2;
}



===== InitReceiverData @ 14000a024 =====

longlong InitReceiverData(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  
  lVar1 = *(longlong *)(param_1 + 0x30);
  uVar4 = *(uint *)(*(longlong *)(param_1 + 0x18) + 0x38) & 0x10;
  *(ushort *)(lVar1 + 0xe4) = (-(ushort)(uVar4 != 0) & 0x1c00) + 0x400;
  uVar5 = 0;
  *(undefined2 *)(lVar1 + 0xe6) = 0;
  *(uint *)(lVar1 + 0xe0) = (-(uint)(uVar4 != 0) & 0x1c00) + 0x3ff;
  lVar2 = ExAllocatePool2(0x40,(-(uint)(uVar4 != 0) & 0x1c000) + 0x4000,0x526d6750);
  if (lVar2 == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
              &WPP_418d3fcde53e33810bba05463ad55e60_Traceguids);
    }
    lVar2 = 0;
  }
  else {
    for (; (ushort)uVar5 < *(ushort *)(lVar1 + 0xe4); uVar5 = (ulonglong)(ushort)((ushort)uVar5 + 1)
        ) {
      lVar3 = uVar5 * 0x10 + lVar2;
      *(longlong *)(lVar3 + 8) = lVar3;
      *(longlong *)lVar3 = lVar3;
    }
  }
  return lVar2;
}



===== InsertEntry @ 14000a10c =====

longlong * InsertEntry(longlong param_1,uint param_2,longlong *param_3,undefined8 *param_4)

{
  longlong *_Dst;
  ulonglong uVar1;
  longlong *plVar2;
  longlong *plVar3;
  
  _Dst = (longlong *)ExAllocateFromNPagedLookasideList(param_3 + 8);
  if (_Dst == (longlong *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
              &WPP_418d3fcde53e33810bba05463ad55e60_Traceguids);
    }
    _Dst = (longlong *)0x0;
  }
  else {
    memset(_Dst,0,(ulonglong)*(uint *)(param_3 + 2));
    *(uint *)(_Dst + 2) = param_2;
    *(int *)((longlong)param_3 + 0x24) = *(int *)((longlong)param_3 + 0x24) + 1;
    uVar1 = InsertInPendingList(param_1,param_2,param_3,_Dst,param_4);
    if ((param_3[(uVar1 & 0xffffffff) + 0x18] == 0) ||
       ((int)(param_2 - *(int *)(param_3[(uVar1 & 0xffffffff) + 0x18] + 0x10)) < 0)) {
      param_3[(uVar1 & 0xffffffff) + 0x18] = (longlong)_Dst;
    }
    plVar2 = (longlong *)
             ((ulonglong)
              (*(uint *)((longlong)param_3 + 0x2c) & param_2 >> ((byte)param_3[6] & 0x3f)) * 0x10 +
             param_3[7]);
    plVar3 = plVar2;
    do {
      plVar3 = (longlong *)*plVar3;
      if (plVar3 == plVar2) break;
    } while ((int)(*(int *)(plVar3 + -8) - param_2) < 0);
    plVar2 = _Dst + 10;
    *plVar2 = (longlong)plVar3;
    _Dst[0xb] = plVar3[1];
    *(longlong **)plVar3[1] = plVar2;
    plVar3[1] = (longlong)plVar2;
  }
  return _Dst;
}



===== InsertInPendingList @ 14000a228 =====

ulonglong InsertInPendingList(longlong param_1,uint param_2,longlong *param_3,longlong *param_4,
                             undefined8 *param_5)

{
  uint uVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  ulonglong uVar5;
  byte bVar6;
  longlong *plVar7;
  ulonglong uVar8;
  uint uVar9;
  uint uVar10;
  
  lVar2 = *(longlong *)(param_1 + 0x28);
  uVar1 = *(uint *)(param_3 + 3);
  plVar3 = (longlong *)*param_3;
  bVar6 = (byte)*(undefined4 *)((longlong)param_3 + 0x14);
  uVar9 = param_2 >> (bVar6 & 0x1f) & uVar1;
  uVar5 = (ulonglong)uVar9;
  uVar10 = *(int *)(lVar2 + 0x98) - 1U >> (bVar6 & 0x1f) & uVar1;
  if (plVar3 != param_3) {
    if ((((param_5 == (undefined8 *)0x0) ||
         (uVar9 != (*(uint *)(param_5 + 2) >> (bVar6 & 0x1f) & uVar1))) ||
        (plVar7 = (longlong *)*param_5, (longlong *)*param_5 == (longlong *)0x0)) &&
       ((((*(uint *)(param_3 + 4) == uVar10 && (uVar9 == uVar10)) ||
         (plVar7 = (longlong *)param_3[uVar5 + 0x18],
         (longlong *)param_3[uVar5 + 0x18] == (longlong *)0x0)) &&
        ((uVar1 <= *(uint *)(lVar2 + 0x94) || (plVar7 = plVar3, plVar3 == (longlong *)0x0)))))) {
      if (uVar9 != uVar10) {
        uVar8 = 0;
        if (uVar9 <= uVar10) {
          uVar8 = (ulonglong)uVar9;
LAB_14000a364:
          do {
            if (uVar10 < (uint)uVar8) goto LAB_14000a385;
            plVar7 = (longlong *)param_3[uVar8 + 0x18];
            if (plVar7 != (longlong *)0x0) {
              if ((int)(param_2 - (int)plVar7[2]) < 1) goto LAB_14000a322;
              goto LAB_14000a385;
            }
            uVar8 = (ulonglong)((uint)uVar8 + 1);
          } while( true );
        }
        do {
          uVar9 = uVar9 + 1;
          if (*(uint *)((longlong)param_3 + 0x1c) <= uVar9) goto LAB_14000a364;
          plVar7 = (longlong *)param_3[(ulonglong)uVar9 + 0x18];
        } while (plVar7 == (longlong *)0x0);
LAB_14000a322:
        *param_4 = (longlong)plVar7;
        param_4[1] = plVar7[1];
        *(longlong **)plVar7[1] = param_4;
        plVar7[1] = (longlong)param_4;
        return uVar5;
      }
      if ((int)((param_2 - ((uint)(*(int *)(lVar2 + 0x98) - *(int *)(lVar2 + 0xa4)) >> 1)) -
               *(int *)(lVar2 + 0xa4)) < 0) {
        plVar7 = param_3;
        do {
          plVar7 = (longlong *)*plVar7;
          if (plVar7 == param_3) goto LAB_14000a26d;
        } while ((int)(*(int *)(plVar7 + 2) - param_2) < 0);
        goto LAB_14000a322;
      }
LAB_14000a385:
      plVar7 = param_3;
      while (plVar7 = (longlong *)plVar7[1], plVar7 != param_3) {
        if ((int)((int)plVar7[2] - param_2) < 1) {
          param_4[1] = (longlong)plVar7;
          *param_4 = *plVar7;
          *(longlong **)(*plVar7 + 8) = param_4;
          *plVar7 = (longlong)param_4;
          return uVar5;
        }
      }
      if ((longlong *)plVar3[1] == param_3) {
        *param_4 = (longlong)plVar3;
        param_4[1] = (longlong)param_3;
        plVar3[1] = (longlong)param_4;
        *param_3 = (longlong)param_4;
        return uVar5;
      }
      goto LAB_14000a3e3;
    }
    for (; plVar7 != param_3; plVar7 = (longlong *)*plVar7) {
      if (-1 < (int)((int)plVar7[2] - param_2)) goto LAB_14000a322;
    }
  }
LAB_14000a26d:
  plVar3 = (longlong *)param_3[1];
  if ((longlong *)*plVar3 == param_3) {
    *param_4 = (longlong)param_3;
    param_4[1] = (longlong)plVar3;
    *plVar3 = (longlong)param_4;
    param_3[1] = (longlong)param_4;
    return uVar5;
  }
LAB_14000a3e3:
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  uVar5 = (*pcVar4)();
  return uVar5;
}



===== RemoveAllEntries @ 14000a3f0 =====

int RemoveAllEntries(longlong param_1,char param_2)

{
  ulonglong *puVar1;
  int *piVar2;
  longlong *plVar3;
  ulonglong uVar4;
  longlong *plVar5;
  longlong *plVar6;
  int iVar7;
  
  iVar7 = 0;
  plVar3 = *(longlong **)(*(longlong *)(param_1 + 0x28) + 0x108);
  uVar4 = *(ulonglong *)(*(longlong *)(param_1 + 0x28) + 0x128);
  plVar5 = (longlong *)*plVar3;
  while (plVar5 != plVar3) {
    puVar1 = (ulonglong *)(plVar5 + 5);
    if ((param_2 != '\0') || ((plVar6 = plVar5, *puVar1 != 0 && (*puVar1 < uVar4)))) {
      *(undefined2 *)((longlong)plVar5 + 0x3a) = 0;
      plVar5[8] = 0;
      plVar5[9] = 0;
      plVar6 = (longlong *)plVar5[1];
      if ((short)plVar5[7] == 0) {
        if (*puVar1 == 0) {
          iVar7 = iVar7 + 1;
          piVar2 = (int *)(*(longlong *)(param_1 + 0x28) + 0x94);
          *piVar2 = *piVar2 + -1;
        }
        RemoveEntry((longlong)plVar3,plVar5);
        DestroyEntry((longlong)plVar3,(longlong)plVar5);
      }
      else {
        if (*puVar1 == 0) {
          iVar7 = iVar7 + 1;
          piVar2 = (int *)(*(longlong *)(param_1 + 0x28) + 0x94);
          *piVar2 = *piVar2 + -1;
        }
        *puVar1 = uVar4;
        plVar5[4] = 0;
        RemoveEntry((longlong)plVar3,plVar5);
      }
    }
    plVar5 = (longlong *)*plVar6;
  }
  return iVar7;
}



===== RemoveEntry @ 14000a4d8 =====

void RemoveEntry(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  byte bVar4;
  uint uVar5;
  ulonglong uVar6;
  
  bVar4 = (byte)*(undefined4 *)(param_1 + 0x14);
  uVar5 = *(uint *)(param_2 + 2) >> (bVar4 & 0x1f) & *(uint *)(param_1 + 0x18);
  uVar6 = (ulonglong)uVar5;
  if (param_2 == *(longlong **)(param_1 + 0xc0 + uVar6 * 8)) {
    lVar1 = *param_2;
    if ((lVar1 == param_1) ||
       ((*(uint *)(lVar1 + 0x10) >> (bVar4 & 0x1f) & *(uint *)(param_1 + 0x18)) != uVar5)) {
      *(undefined8 *)(param_1 + 0xc0 + uVar6 * 8) = 0;
    }
    else {
      *(longlong *)(param_1 + 0xc0 + uVar6 * 8) = lVar1;
    }
  }
  lVar1 = *param_2;
  if ((*(longlong **)(lVar1 + 8) == param_2) &&
     (plVar2 = (longlong *)param_2[1], (longlong *)*plVar2 == param_2)) {
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    param_2[1] = (longlong)param_2;
    *param_2 = (longlong)param_2;
    return;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== RemovePendingReceiverEntry @ 14000a558 =====

void RemovePendingReceiverEntry(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  
  plVar1 = (longlong *)(param_1 + 0x50);
  lVar2 = *plVar1;
  if ((*(longlong **)(lVar2 + 8) == plVar1) &&
     (plVar3 = *(longlong **)(param_1 + 0x58), (longlong *)*plVar3 == plVar1)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    *(longlong **)(param_1 + 0x58) = plVar1;
    *plVar1 = (longlong)plVar1;
    plVar1 = (longlong *)(param_1 + 0x40);
    lVar2 = *plVar1;
    if ((*(longlong **)(lVar2 + 8) == plVar1) &&
       (plVar3 = *(longlong **)(param_1 + 0x48), (longlong *)*plVar3 == plVar1)) {
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      *(longlong **)(param_1 + 0x48) = plVar1;
      *plVar1 = (longlong)plVar1;
      return;
    }
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== BuildDecodeMatrix @ 14000a5b0 =====

undefined8 BuildDecodeMatrix(longlong param_1,longlong param_2,uint param_3)

{
  byte bVar1;
  undefined8 uVar2;
  byte *pbVar3;
  size_t _Size;
  void *_Dst;
  longlong lVar4;
  
  _Size = (size_t)(int)param_3;
  memset(*(void **)(param_1 + 0x10),0,(longlong)(int)(param_3 * param_3));
  _Dst = *(void **)(param_1 + 0x10);
  lVar4 = 0;
  pbVar3 = (byte *)(param_2 + 0x14);
  do {
    if ((longlong)_Size <= lVar4) {
      uVar2 = InvertMatrix(*(void **)(param_1 + 0x18),*(byte **)(param_1 + 0x10),param_3);
      return uVar2;
    }
    bVar1 = *pbVar3;
    if ((int)(uint)bVar1 < (int)param_3) {
      memset(_Dst,0,_Size);
      *(undefined1 *)(lVar4 + (longlong)_Dst) = 1;
    }
    else {
      if (*(int *)(param_1 + 4) <= (int)(uint)bVar1) {
        return 0xc000000d;
      }
      memmove(_Dst,(void *)((longlong)(int)(bVar1 * param_3) + *(longlong *)(param_1 + 8)),_Size);
    }
    lVar4 = lVar4 + 1;
    pbVar3 = pbVar3 + 0x28;
    _Dst = (void *)((longlong)_Dst + _Size);
  } while( true );
}



===== CreateFECContext @ 14000a66c =====

/* WARNING: Removing unreachable block (ram,0x00014000a794) */

undefined8 CreateFECContext(uint *param_1,uint param_2,uint param_3,char param_4)

{
  byte bVar1;
  longlong lVar2;
  undefined1 *puVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong lVar7;
  size_t _Size;
  int iVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  undefined1 *puVar11;
  int iVar12;
  undefined1 *puVar13;
  
  uVar6 = (ulonglong)param_2;
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  lVar4 = 0;
  uVar9 = 0x306d6750;
  lVar7 = (longlong)(int)(param_2 * param_3);
  lVar5 = 0;
  puVar3 = (undefined1 *)0x0;
  lVar2 = ExAllocatePool2(0x40);
  if (lVar2 != 0) {
    uVar9 = 0x306d6750;
    lVar7 = (longlong)(int)((param_3 + 3) * param_2);
    puVar3 = (undefined1 *)ExAllocatePool2(0x40);
    if (puVar3 != (undefined1 *)0x0) {
      if (param_4 == '\0') {
LAB_14000a80e:
        *param_1 = param_2;
        param_1[1] = param_3;
        *(longlong *)(param_1 + 2) = lVar2;
        *(longlong *)(param_1 + 4) = lVar4;
        *(longlong *)(param_1 + 6) = lVar5;
        *puVar3 = 1;
        if (1 < (int)param_2) {
          memset(puVar3 + 1,0,(longlong)(int)param_2 - 1);
        }
        uVar10 = 0;
        puVar11 = puVar3;
        if (0 < (int)(param_3 - 1)) {
          do {
            puVar11 = puVar11 + (int)param_2;
            iVar8 = (int)uVar10;
            iVar12 = 0;
            if (0 < (int)param_2) {
              puVar13 = puVar11;
              do {
                bVar1 = ModNN(iVar12 * (int)uVar10);
                iVar8 = (int)uVar10;
                iVar12 = iVar12 + 1;
                *puVar13 = (&gFECExp)[bVar1];
                puVar13 = puVar13 + 1;
              } while (iVar12 < (int)param_2);
            }
            uVar10 = (ulonglong)(iVar8 + 1U);
          } while ((int)(iVar8 + 1U) < (int)(param_3 - 1));
        }
        puVar11 = puVar3 + (int)(param_2 * param_3);
        InvertVdm(param_2,(longlong)puVar3,puVar11,(ulonglong)(puVar11 + (int)param_2),
                  puVar11 + (int)(param_2 * 2));
        _Size = (size_t)(int)(param_2 * param_2);
        MatrixMultiply(puVar3 + _Size,puVar3,*(longlong *)(param_1 + 2) + _Size,param_3 - param_2,
                       param_2,param_2);
        memset(*(void **)(param_1 + 2),0,_Size);
        puVar11 = *(undefined1 **)(param_1 + 2);
        if (0 < (int)param_2) {
          do {
            *puVar11 = 1;
            puVar11 = puVar11 + (int)(param_2 + 1);
            uVar6 = uVar6 - 1;
          } while (uVar6 != 0);
        }
        ExFreePoolWithTag(puVar3,0);
        return 0;
      }
      uVar9 = 0x306d6750;
      lVar7 = (longlong)(int)(param_2 * param_2);
      lVar4 = ExAllocatePool2(0x40);
      if (lVar4 != 0) {
        uVar9 = 0x306d6750;
        lVar7 = (longlong)(int)param_2 * 0x14;
        lVar5 = ExAllocatePool2(0x40);
        if (lVar5 != 0) goto LAB_14000a80e;
      }
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_ddqqqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar7,uVar9,param_3,(char)param_2,
                  (char)param_1,(char)lVar2,(char)lVar4,(char)puVar3);
  }
  if (lVar4 != 0) {
    ExFreePoolWithTag(lVar4,0);
  }
  if (puVar3 != (undefined1 *)0x0) {
    ExFreePoolWithTag(puVar3,0);
  }
  if (lVar2 != 0) {
    ExFreePoolWithTag(lVar2,0);
  }
  return 0xc000009a;
}



===== DestroyFECContext @ 14000a924 =====

void DestroyFECContext(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x10) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x10),0);
    *(undefined8 *)(param_1 + 0x10) = 0;
  }
  if (*(longlong *)(param_1 + 0x18) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x18),0);
    *(undefined8 *)(param_1 + 0x18) = 0;
  }
  if (*(longlong *)(param_1 + 8) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 8),0);
    *(undefined8 *)(param_1 + 8) = 0;
  }
  return;
}



===== FECDecode @ 14000a990 =====

undefined8 FECDecode(uint *param_1,undefined8 *param_2,int param_3)

{
  undefined8 *puVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  longlong lVar9;
  longlong lVar10;
  uint uVar11;
  longlong lVar12;
  ulonglong uVar13;
  
  uVar4 = *param_1;
  uVar13 = (ulonglong)uVar4;
  puVar1 = param_2 + 1;
  uVar11 = 0;
  lVar12 = (longlong)(int)uVar4;
  lVar10 = 0;
  puVar8 = puVar1;
  while( true ) {
    while( true ) {
      if (lVar12 <= lVar10) {
        uVar6 = BuildDecodeMatrix((longlong)param_1,(longlong)param_2,*param_1);
        if (-1 < (int)uVar6) {
          if (0 < (int)uVar4) {
            lVar10 = 0;
            do {
              if ((int)(uint)*(byte *)((longlong)param_2 + 0x14) < (int)uVar4) {
                memmove((void *)*param_2,(void *)param_2[1],(longlong)param_3);
              }
              else {
                memset((void *)*param_2,0,(longlong)param_3);
                lVar9 = 0;
                puVar8 = puVar1;
                if (0 < lVar12) {
                  do {
                    MultiplyAndAdd((byte *)*param_2,(undefined1 *)*puVar8,
                                   *(char *)(*(longlong *)(param_1 + 4) + lVar10 + lVar9),param_3);
                    lVar9 = lVar9 + 1;
                    puVar8 = puVar8 + 5;
                  } while (lVar9 < lVar12);
                }
              }
              lVar10 = lVar10 + lVar12;
              param_2 = param_2 + 5;
              uVar13 = uVar13 - 1;
            } while (uVar13 != 0);
          }
          uVar6 = 0;
        }
        return uVar6;
      }
      bVar2 = *(byte *)((longlong)puVar8 + 0xc);
      uVar7 = (ulonglong)bVar2;
      if (((int)(uint)bVar2 < (int)uVar4) && (bVar2 != uVar11)) break;
      uVar11 = uVar11 + 1;
      lVar10 = lVar10 + 1;
      puVar8 = puVar8 + 5;
    }
    bVar3 = *(byte *)((longlong)param_2 + uVar7 * 0x28 + 0x14);
    if ((uint)bVar3 == (uint)bVar2) break;
    *(byte *)((longlong)puVar8 + 0xc) = bVar3;
    uVar6 = param_2[uVar7 * 5 + 1];
    *(byte *)((longlong)param_2 + uVar7 * 0x28 + 0x14) = bVar2;
    uVar5 = *puVar8;
    *puVar8 = uVar6;
    param_2[uVar7 * 5 + 1] = uVar5;
  }
  return 0xc0000001;
}



===== FECEncode @ 14000aaec =====

undefined8
FECEncode(int *param_1,longlong param_2,undefined8 param_3,int param_4,int param_5,byte *param_6)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong lVar5;
  
  iVar1 = *param_1;
  if (param_5 < param_1[1]) {
    if (param_5 < iVar1) {
      memmove(param_6,*(void **)(param_2 + (longlong)param_5 * 8),(longlong)param_4);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
        WPP_SF_dDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                   &WPP_b1821e6972a431908bada29dc83e0a17_Traceguids,param_5,(char)param_1[1],
                   (char)*param_1);
      }
    }
    else {
      memset(param_6,0,(longlong)param_4);
      iVar2 = *param_1;
      lVar5 = 0;
      lVar3 = *(longlong *)(param_1 + 2);
      if (0 < iVar1) {
        do {
          MultiplyAndAdd(param_6,*(undefined1 **)(param_2 + lVar5 * 8),
                         *(char *)(lVar5 + param_5 * iVar2 + lVar3),param_4);
          lVar5 = lVar5 + 1;
        } while (lVar5 < iVar1);
      }
    }
    uVar4 = 0;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                  &WPP_b1821e6972a431908bada29dc83e0a17_Traceguids,param_5,(char)param_1[1],
                  (char)iVar1,(char)iVar1);
    }
    uVar4 = 0xc000000d;
  }
  return uVar4;
}



===== FECInitGlobals @ 14000ac20 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FECInitGlobals(void)

{
  byte bVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  int *piVar7;
  char *pcVar8;
  undefined1 *puVar9;
  uint *puVar10;
  longlong lVar11;
  longlong lVar12;
  
  pcVar8 = "101110001";
  if (((fPrintCopyright != '\0') && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_ss(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_b1821e6972a431908bada29dc83e0a17_Traceguids,FEC_COPYRIGHT_STRING1,
              FEC_COPYRIGHT_STRING2);
  }
  memset(&gFECLog2,0,0x81);
  iVar2 = 0;
  uVar3 = 1;
  do {
    (&gFECLog2)[uVar3] = (char)iVar2;
    iVar2 = iVar2 + 1;
    uVar3 = (ulonglong)(byte)((char)uVar3 * '\x02');
  } while (iVar2 < 8);
  memset(&gFECLog,0,0x400);
  memset(&gFECExp,0,0x1fe);
  iVar2 = 0;
  uVar3 = 1;
  do {
    bVar1 = (byte)uVar3;
    pcVar8[0x2ea8] = bVar1;
    (&gFECLog)[uVar3] = iVar2;
    if (*pcVar8 == '1') {
      DAT_1400262c8 = DAT_1400262c8 ^ bVar1;
    }
    iVar2 = iVar2 + 1;
    pcVar8 = pcVar8 + 1;
    uVar3 = (ulonglong)(byte)(bVar1 * '\x02');
  } while (iVar2 < 8);
  pbVar6 = &DAT_1400262c9;
  iVar2 = 9;
  (&gFECLog)[DAT_1400262c8] = 8;
  do {
    bVar1 = pbVar6[-1] * '\x02';
    if (0x7f < pbVar6[-1]) {
      bVar1 = bVar1 ^ DAT_1400262c8;
    }
    *pbVar6 = bVar1;
    pbVar6 = pbVar6 + 1;
    (&gFECLog)[bVar1] = iVar2;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xff);
  gFECLog = 0xff;
  _gFECInverse = 0x100;
  piVar7 = &DAT_140025ec8;
  puVar5 = &gFECExp;
  puVar9 = &DAT_1400263bf;
  for (lVar4 = 0xff; lVar4 != 0; lVar4 = lVar4 + -1) {
    *puVar9 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar9 = puVar9 + 1;
  }
  puVar5 = &DAT_1400264c2;
  lVar4 = 0xfe;
  do {
    iVar2 = *piVar7;
    piVar7 = piVar7 + 1;
    *puVar5 = (&gFECExp)[0xff - iVar2];
    puVar5 = puVar5 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  lVar12 = 0x100;
  puVar5 = &gFECMultTable;
  lVar4 = 0x100;
  puVar10 = &gFECLog;
  do {
    uVar3 = (ulonglong)*puVar10;
    lVar11 = 0;
    do {
      bVar1 = ModNN((&gFECLog)[lVar11] + (int)uVar3);
      puVar5[lVar11] = (&gFECExp)[bVar1];
      lVar11 = lVar11 + 1;
    } while (lVar11 < lVar12);
    puVar10 = puVar10 + 1;
    puVar5 = puVar5 + lVar12;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  lVar4 = 0;
  puVar5 = &gFECMultTable;
  do {
    *puVar5 = 0;
    puVar5 = puVar5 + lVar12;
    (&gFECMultTable)[lVar4] = 0;
    lVar4 = lVar4 + 1;
  } while ((longlong)puVar5 < 0x1400365c0);
  return 0;
}



===== InvertMatrix @ 14000ae30 =====

undefined8 InvertMatrix(void *param_1,byte *param_2,uint param_3)

{
  uint *puVar1;
  void *_Buf2;
  byte bVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar7;
  uint uVar6;
  int iVar8;
  byte *pbVar9;
  uint uVar10;
  byte *pbVar11;
  uint uVar12;
  uint uVar13;
  ulonglong uVar14;
  size_t sVar15;
  longlong lVar16;
  size_t sVar17;
  int *piVar18;
  int iVar19;
  uint *puVar20;
  size_t _Size;
  uint uVar21;
  
  _Size = (size_t)(int)param_3;
  puVar1 = (uint *)((longlong)param_1 + _Size * 4);
  _Buf2 = (void *)((longlong)param_1 + (longlong)(int)(param_3 * 3) * 4);
  memset(param_1,0,_Size * 0x14);
  uVar21 = 0;
  puVar20 = puVar1;
  do {
    if ((int)param_3 <= (int)uVar21) {
      iVar5 = param_3 - 1;
      piVar18 = (int *)((longlong)param_1 + (longlong)iVar5 * 4);
      while( true ) {
        if (iVar5 < 0) {
          return 0;
        }
        iVar19 = *(int *)(((longlong)puVar1 - (longlong)param_1) + (longlong)piVar18);
        if ((((iVar19 < 0) || ((int)param_3 <= iVar19)) || (iVar8 = *piVar18, iVar8 < 0)) ||
           ((int)param_3 <= iVar8)) break;
        if ((iVar19 != iVar8) && (0 < (int)param_3)) {
          iVar19 = 0;
          uVar14 = (ulonglong)param_3;
          do {
            iVar8 = *(int *)(((longlong)puVar1 - (longlong)param_1) + (longlong)piVar18) + iVar19;
            bVar2 = param_2[iVar8];
            param_2[iVar8] = param_2[*piVar18 + iVar19];
            iVar8 = *piVar18 + iVar19;
            iVar19 = iVar19 + param_3;
            param_2[iVar8] = bVar2;
            uVar14 = uVar14 - 1;
          } while (uVar14 != 0);
        }
        iVar5 = iVar5 + -1;
        piVar18 = piVar18 + -1;
      }
      return 0xc0000001;
    }
    uVar13 = 0xffffffff;
    uVar12 = 0xffffffff;
    if ((*(int *)((longlong)param_1 + ((longlong)(int)(param_3 * 2) * 4 - (longlong)puVar1) +
                 (longlong)puVar20) == 1) || (param_2[(int)((param_3 + 1) * uVar21)] == 0)) {
      sVar17 = 0;
      for (uVar10 = 0; (int)uVar10 < (int)param_3; uVar10 = uVar10 + 1) {
        if (*(int *)((longlong)param_1 + sVar17 * 4 + (longlong)(int)(param_3 * 2) * 4) != 1) {
          sVar15 = 0;
          uVar6 = 0;
          while ((int)uVar6 < (int)param_3) {
            iVar5 = *(int *)((longlong)param_1 + sVar15 * 4 + (longlong)(int)(param_3 * 2) * 4);
            if (1 < iVar5) {
              return 0xc000000d;
            }
            uVar4 = uVar10;
            uVar7 = uVar6;
            if (iVar5 == 0) {
              if (param_2[(int)(uVar10 * param_3 + uVar6)] != 0) {
                sVar15 = _Size;
                sVar17 = _Size;
                uVar4 = param_3;
                uVar7 = param_3;
                uVar12 = uVar10;
                uVar13 = uVar6;
              }
            }
            uVar10 = uVar4;
            sVar15 = sVar15 + 1;
            uVar6 = uVar7 + 1;
          }
        }
        sVar17 = sVar17 + 1;
      }
      if (uVar13 == 0xffffffff) {
        return 0xc0000001;
      }
    }
    else {
      uVar13 = uVar21;
      uVar12 = uVar21;
    }
    piVar18 = (int *)((longlong)param_1 +
                     (longlong)(int)uVar13 * 4 + (longlong)(int)(param_3 * 2) * 4);
    *piVar18 = *piVar18 + 1;
    if ((uVar12 != uVar13) && (0 < (int)param_3)) {
      lVar16 = (longlong)(int)(uVar12 * param_3) - (longlong)(int)(uVar13 * param_3);
      pbVar11 = param_2 + (int)(uVar13 * param_3);
      do {
        bVar2 = pbVar11[lVar16];
        pbVar11[lVar16] = *pbVar11;
        *pbVar11 = bVar2;
        pbVar11 = pbVar11 + 1;
      } while ((longlong)pbVar11 - (longlong)(param_2 + (int)(uVar13 * param_3)) < (longlong)_Size);
    }
    *puVar20 = uVar12;
    *(uint *)(((longlong)param_1 - (longlong)puVar1) + (longlong)puVar20) = uVar13;
    pbVar11 = param_2 + (int)(uVar13 * param_3);
    bVar2 = pbVar11[(int)uVar13];
    if (bVar2 == 0) {
      return 0xc000000d;
    }
    if (bVar2 != 1) {
      uVar3 = (&gFECInverse)[bVar2];
      pbVar11[(int)uVar13] = 1;
      if (0 < (int)param_3) {
        pbVar9 = pbVar11;
        do {
          *pbVar9 = (&gFECMultTable)[CONCAT11(uVar3,*pbVar9)];
          pbVar9 = pbVar9 + 1;
        } while ((longlong)pbVar9 - (longlong)pbVar11 < (longlong)_Size);
      }
    }
    *(undefined1 *)((longlong)(int)uVar13 + (longlong)_Buf2) = 1;
    iVar5 = memcmp(pbVar11,_Buf2,_Size);
    if ((iVar5 != 0) && (uVar12 = 0, 0 < (int)param_3)) {
      pbVar9 = param_2;
      do {
        if (uVar12 != uVar13) {
          bVar2 = pbVar9[(int)uVar13];
          pbVar9[(int)uVar13] = 0;
          MultiplyAndAdd(pbVar9,pbVar11,bVar2,param_3);
        }
        uVar12 = uVar12 + 1;
        pbVar9 = pbVar9 + _Size;
      } while ((int)uVar12 < (int)param_3);
    }
    uVar21 = uVar21 + 1;
    puVar20 = puVar20 + 1;
    *(undefined1 *)((longlong)(int)uVar13 + (longlong)_Buf2) = 0;
  } while( true );
}



===== InvertVdm @ 14000b13c =====

void InvertVdm(int param_1,longlong param_2,undefined1 *param_3,ulonglong param_4,
              undefined1 *param_5)

{
  byte *pbVar1;
  undefined1 uVar2;
  byte bVar3;
  byte bVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  byte *pbVar7;
  ulonglong uVar8;
  longlong lVar9;
  int iVar10;
  longlong lVar11;
  int iVar12;
  longlong lVar13;
  byte bVar14;
  longlong lVar15;
  int iVar16;
  
  lVar15 = (longlong)param_1;
  if (param_1 != 1) {
    if (0 < param_1) {
      puVar6 = (undefined1 *)(param_2 + 1);
      puVar5 = param_5;
      lVar13 = lVar15;
      do {
        puVar5[param_4 - (longlong)param_5] = 0;
        uVar2 = *puVar6;
        puVar6 = puVar6 + lVar15;
        *puVar5 = uVar2;
        puVar5 = puVar5 + 1;
        lVar13 = lVar13 + -1;
      } while (lVar13 != 0);
    }
    *(undefined1 *)(lVar15 + -1 + param_4) = *param_5;
    if (lVar15 < 2) {
      if (param_1 < 1) {
        return;
      }
    }
    else {
      lVar11 = 1;
      lVar13 = lVar15;
      do {
        lVar13 = lVar13 + -1;
        bVar3 = param_5[lVar11];
        if (lVar13 < lVar15 + -1) {
          pbVar7 = (byte *)(lVar13 + param_4);
          lVar9 = (lVar15 + -1) - (lVar15 - lVar11);
          bVar14 = *pbVar7;
          do {
            pbVar1 = pbVar7 + 1;
            *pbVar7 = bVar14 ^ (&gFECMultTable)[CONCAT11(bVar3,*pbVar1)];
            pbVar7 = pbVar7 + 1;
            lVar9 = lVar9 + -1;
            bVar14 = *pbVar1;
          } while (lVar9 != 0);
        }
        pbVar7 = (byte *)(lVar15 + -1 + param_4);
        *pbVar7 = *pbVar7 ^ bVar3;
        lVar11 = lVar11 + 1;
      } while (lVar11 < lVar15);
    }
    iVar12 = 0;
    lVar13 = 0;
    do {
      bVar3 = param_5[lVar13];
      uVar8 = 1;
      param_3[lVar15 + -1] = 1;
      for (pbVar7 = (byte *)((param_4 - 1) + lVar15); -1 < (longlong)(pbVar7 + ~param_4);
          pbVar7 = pbVar7 + -1) {
        bVar14 = (&gFECMultTable)[CONCAT11(bVar3,pbVar7[(longlong)param_3 - param_4])];
        bVar4 = *pbVar7;
        pbVar7[((longlong)param_3 - param_4) + -1] = bVar14 ^ bVar4;
        uVar8 = (ulonglong)
                (byte)(bVar14 ^ bVar4 ^ (&gFECMultTable)[uVar8 + (ulonglong)bVar3 * 0x100]);
      }
      puVar5 = param_3;
      iVar16 = iVar12;
      for (iVar10 = 0; iVar10 < param_1; iVar10 = iVar10 + 1) {
        if (0xff < (uint)uVar8) {
          return;
        }
        uVar2 = *puVar5;
        lVar11 = (longlong)iVar16;
        iVar16 = iVar16 + param_1;
        puVar5 = puVar5 + 1;
        *(undefined1 *)(lVar11 + param_2) = (&gFECMultTable)[CONCAT11((&gFECInverse)[uVar8],uVar2)];
      }
      iVar12 = iVar12 + 1;
      lVar13 = lVar13 + 1;
    } while (lVar13 < lVar15);
  }
  return;
}



===== MatrixMultiply @ 14000b35c =====

void MatrixMultiply(undefined1 *param_1,undefined1 *param_2,longlong param_3,uint param_4,
                   uint param_5,uint param_6)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
  byte bVar7;
  ulonglong uVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  
  if (0 < (int)param_4) {
    lVar6 = param_3 - (longlong)param_2;
    uVar5 = (ulonglong)param_4;
    do {
      if (0 < (int)param_6) {
        puVar3 = param_2;
        uVar4 = (ulonglong)param_6;
        do {
          bVar7 = 0;
          if (0 < (int)param_5) {
            uVar8 = (ulonglong)param_5;
            puVar9 = param_1;
            puVar10 = puVar3;
            do {
              uVar1 = *puVar10;
              puVar10 = puVar10 + (int)param_6;
              uVar2 = *puVar9;
              puVar9 = puVar9 + 1;
              bVar7 = bVar7 ^ (&gFECMultTable)[CONCAT11(uVar2,uVar1)];
              uVar8 = uVar8 - 1;
            } while (uVar8 != 0);
          }
          puVar3[lVar6] = bVar7;
          puVar3 = puVar3 + 1;
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
      }
      param_1 = param_1 + (int)param_5;
      lVar6 = lVar6 + (int)param_6;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  return;
}



===== ModNN @ 14000b420 =====

undefined1 ModNN(int param_1)

{
  for (; 0xfe < param_1; param_1 = (param_1 - 0xffU & 0xff) + ((int)(param_1 - 0xffU) >> 8)) {
  }
  return (char)param_1;
}



===== MultiplyAndAdd @ 14000b444 =====

void MultiplyAndAdd(byte *param_1,undefined1 *param_2,char param_3,int param_4)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  longlong lVar3;
  byte *pbVar4;
  byte *pbVar5;
  
  pbVar4 = param_1 + (param_4 + -0xf);
  if (param_3 != '\0') {
    puVar2 = param_2;
    for (pbVar5 = param_1; pbVar5 < pbVar4; pbVar5 = pbVar5 + 0x10) {
      uVar1 = *puVar2;
      puVar2 = puVar2 + 0x10;
      *pbVar5 = *pbVar5 ^ (&gFECMultTable)[CONCAT11(param_3,uVar1)];
      pbVar5[1] = pbVar5[1] ^
                  (&gFECMultTable)
                  [CONCAT11(param_3,pbVar5[(longlong)(param_2 + (1 - (longlong)param_1))])];
      pbVar5[2] = pbVar5[2] ^
                  (&gFECMultTable)
                  [CONCAT11(param_3,pbVar5[(longlong)(param_2 + (2 - (longlong)param_1))])];
      pbVar5[3] = pbVar5[3] ^
                  (&gFECMultTable)
                  [CONCAT11(param_3,pbVar5[(longlong)(param_2 + (3 - (longlong)param_1))])];
      pbVar5[4] = pbVar5[4] ^
                  (&gFECMultTable)
                  [CONCAT11(param_3,pbVar5[(longlong)(param_2 + (4 - (longlong)param_1))])];
      pbVar5[5] = pbVar5[5] ^
                  (&gFECMultTable)
                  [CONCAT11(param_3,pbVar5[(longlong)(param_2 + (5 - (longlong)param_1))])];
      pbVar5[6] = pbVar5[6] ^
                  (&gFECMultTable)
                  [CONCAT11(param_3,pbVar5[(longlong)(param_2 + (6 - (longlong)param_1))])];
      pbVar5[7] = pbVar5[7] ^
                  (&gFECMultTable)
                  [CONCAT11(param_3,pbVar5[(longlong)(param_2 + (7 - (longlong)param_1))])];
      pbVar5[8] = pbVar5[8] ^
                  (&gFECMultTable)
                  [CONCAT11(param_3,pbVar5[(longlong)(param_2 + (8 - (longlong)param_1))])];
      pbVar5[9] = pbVar5[9] ^
                  (&gFECMultTable)
                  [CONCAT11(param_3,pbVar5[(longlong)(param_2 + (9 - (longlong)param_1))])];
      pbVar5[10] = pbVar5[10] ^
                   (&gFECMultTable)
                   [CONCAT11(param_3,pbVar5[(longlong)(param_2 + (10 - (longlong)param_1))])];
      pbVar5[0xb] = pbVar5[0xb] ^
                    (&gFECMultTable)
                    [CONCAT11(param_3,pbVar5[(longlong)(param_2 + (0xb - (longlong)param_1))])];
      pbVar5[0xc] = pbVar5[0xc] ^
                    (&gFECMultTable)
                    [CONCAT11(param_3,pbVar5[(longlong)(param_2 + (0xc - (longlong)param_1))])];
      pbVar5[0xd] = pbVar5[0xd] ^
                    (&gFECMultTable)
                    [CONCAT11(param_3,pbVar5[(longlong)(param_2 + (0xd - (longlong)param_1))])];
      pbVar5[0xe] = pbVar5[0xe] ^
                    (&gFECMultTable)
                    [CONCAT11(param_3,pbVar5[(longlong)(param_2 + (0xe - (longlong)param_1))])];
      pbVar5[0xf] = pbVar5[0xf] ^
                    (&gFECMultTable)
                    [CONCAT11(param_3,pbVar5[(longlong)(param_2 + (0xf - (longlong)param_1))])];
    }
    if (pbVar5 < pbVar4 + 0xf) {
      lVar3 = (longlong)puVar2 - (longlong)pbVar5;
      do {
        *pbVar5 = *pbVar5 ^ (&gFECMultTable)[CONCAT11(param_3,pbVar5[lVar3])];
        pbVar5 = pbVar5 + 1;
      } while (pbVar5 < pbVar4 + 0xf);
    }
  }
  return;
}



===== WPP_SF_dddd @ 14000b590 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dddd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_ddqqqq @ 14000b5f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ddqqqq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                  undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                  undefined1 param_9)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_b1821e6972a431908bada29dc83e0a17_Traceguids,0xb,local_res20,4,
             &param_5,4,&param_6,8,&param_7,8,&param_8,8,&param_9,8,0);
  return;
}



===== WPP_SF_ZD @ 14000b688 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ZD(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4,
              undefined1 param_5)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  
  if (param_4 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_4;
    if (*param_4 != L'\0') {
      pwVar1 = *(wchar_t **)(param_4 + 4);
      goto LAB_14000b6b5;
    }
  }
  pwVar1 = L"NULL";
LAB_14000b6b5:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,2,pwVar1,wVar2,&param_5,4,0);
  return;
}



===== WPP_SF_Zqi @ 14000b71c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Zqi(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
               undefined1 param_5,undefined1 param_6)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  
  if (param_4 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *param_4;
    if (*param_4 != L'\0') {
      pwVar2 = *(wchar_t **)(param_4 + 4);
      goto LAB_14000b749;
    }
  }
  pwVar2 = L"NULL";
LAB_14000b749:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_0e4477596d4f3af6adc990aa583f3876_Traceguids,0x12,param_4,2,pwVar2,
             wVar1,&param_5,8,&param_6,8,0);
  return;
}



===== Feature_2592016699__private_IsEnabledDeviceUsageNoInline @ 14000b7c8 =====

ulonglong Feature_2592016699__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_2592016699__private_featureState;
  if ((Feature_2592016699__private_featureState & 0x10) == 0) {
    uVar1 = Feature_2592016699__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_2592016699__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_2592016699__private_IsEnabledFallback @ 14000b800 =====

void Feature_2592016699__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_2592016699__private_descriptor);
  return;
}



===== PgmOpenRegistryParameters @ 14000b81c =====

int PgmOpenRegistryParameters(undefined8 param_1,undefined8 *param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 local_res8 [2];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_1c = 0;
  local_res8[0] = 0;
  local_30 = 0;
  local_38 = 0x30;
  local_48 = 0;
  uStack_40 = 0;
  local_20 = 0x240;
  local_18 = 0;
  uStack_10 = 0;
  local_28 = (undefined8 *)param_1;
  iVar1 = ZwCreateKey(param_2,0x20019,&local_38,0,0,0,local_res8);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
               &WPP_50b4bc983f2130f0a63faa089ac2dd69_Traceguids,iVar1);
    }
  }
  else {
    RtlInitUnicodeString(&local_48,L"Parameters");
    local_30 = *param_2;
    local_28 = &local_48;
    local_38 = CONCAT44(local_38._4_4_,0x30);
    local_20 = 0x240;
    local_18 = 0;
    uStack_10 = 0;
    iVar1 = ZwOpenKey(param_3,0x20019,&local_38);
    if (iVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                 &WPP_50b4bc983f2130f0a63faa089ac2dd69_Traceguids,iVar1);
      }
      ZwClose(*param_2);
    }
  }
  return iVar1;
}



===== ReadRegistryDwordValue @ 14000b9a0 =====

int ReadRegistryDwordValue(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  int iVar1;
  longlong lVar2;
  int local_res20 [2];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res20[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18);
  iVar1 = ZwQueryValueKey(param_1,&local_18,1,0,0,local_res20);
  if ((((iVar1 < 0) && (iVar1 != -0x7ffffffb)) && (iVar1 != -0x3fffffdd)) || (local_res20[0] == 0))
  {
    iVar1 = -0x3fffffff;
  }
  else {
    lVar2 = ExAllocatePool2(0x40,local_res20[0],0x526d6750);
    if (lVar2 == 0) {
      iVar1 = -0x3fffff66;
    }
    else {
      iVar1 = ZwQueryValueKey(param_1,&local_18,1,lVar2,local_res20[0],local_res20);
      if (((iVar1 < 0) || (*(int *)(lVar2 + 0xc) != 4)) || (*(int *)(lVar2 + 4) != 4)) {
        ExFreePoolWithTag(lVar2,0);
        iVar1 = -0x3fffffff;
      }
      else {
        *param_3 = *(undefined4 *)((ulonglong)*(uint *)(lVar2 + 8) + lVar2);
        ExFreePoolWithTag(lVar2,0);
      }
    }
  }
  return iVar1;
}



===== ReadRegistryStringValue @ 14000bad4 =====

int ReadRegistryStringValue(undefined8 param_1,ulonglong param_2,undefined8 param_3)

{
  int iVar1;
  void *_Dst;
  ulonglong local_res10;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res10 = param_2 & 0xffffffff00000000;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,L"SenderFileLocation");
  iVar1 = ZwQueryValueKey(param_1,&local_18,1,0,0,&local_res10);
  if (((-1 < iVar1) || (iVar1 == -0x7ffffffb)) || (iVar1 == -0x3fffffdd)) {
    if ((int)local_res10 != 0) {
      _Dst = (void *)ExAllocatePool2(0x40,local_res10 & 0xffffffff,0x526d6750);
      if (_Dst == (void *)0x0) {
        iVar1 = -0x3fffff66;
      }
      else {
        iVar1 = ZwQueryValueKey(param_1,&local_18,1,_Dst,(int)local_res10,&local_res10);
        if ((iVar1 < 0) || (*(uint *)((longlong)_Dst + 0xc) < 2)) {
          ExFreePoolWithTag(_Dst,0);
          iVar1 = -0x3fffffff;
        }
        else {
          memmove(_Dst,(void *)((ulonglong)*(uint *)((longlong)_Dst + 8) + (longlong)_Dst),
                  (ulonglong)*(uint *)((longlong)_Dst + 0xc));
          RtlInitUnicodeString(param_3,_Dst);
        }
      }
      goto LAB_14000bc01;
    }
  }
  iVar1 = -0x3fffffff;
LAB_14000bc01:
  return iVar1;
}



===== WPP_SF_DZ @ 14000bc18 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DZ(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              wchar_t *param_5)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  undefined4 local_res20 [2];
  
  if (param_5 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_5;
    if (*param_5 != L'\0') {
      pwVar1 = *(wchar_t **)(param_5 + 4);
      goto LAB_14000bc52;
    }
  }
  pwVar1 = L"NULL";
LAB_14000bc52:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,param_5,2,pwVar1,wVar2,0);
  return;
}



===== Feature_469915960__private_IsEnabledDeviceUsageNoInline @ 14000bcb4 =====

ulonglong Feature_469915960__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_469915960__private_featureState;
  if ((Feature_469915960__private_featureState & 0x10) == 0) {
    uVar1 = Feature_469915960__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_469915960__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_469915960__private_IsEnabledFallback @ 14000bcec =====

void Feature_469915960__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_469915960__private_descriptor);
  return;
}



===== GetIpInterfaceIndexFromAddress @ 14000bd08 =====

undefined8 GetIpInterfaceIndexFromAddress(int param_1,undefined4 *param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  if (param_1 != 0) {
    puVar1 = &DAT_140036720;
    while (puVar1 = (undefined8 *)*puVar1, puVar1 != &DAT_140036720) {
      puVar2 = puVar1 + 2;
      while (puVar2 = (undefined8 *)*puVar2, puVar2 != puVar1 + 2) {
        if (*(int *)(puVar2 + 2) == param_1) {
          *param_2 = *(undefined4 *)(puVar1 + 4);
          return 0;
        }
      }
    }
  }
  return 0xc0000001;
}



===== GetIpInterfaceInfoForDevice @ 14000bd50 =====

int GetIpInterfaceInfoForDevice(wchar_t *param_1,uint param_2,longlong param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined2 uVar3;
  uint uVar4;
  uint *puVar5;
  longlong lVar6;
  uint local_res10 [4];
  uint local_res20 [2];
  undefined4 *local_28;
  longlong local_20;
  
  local_28 = (undefined4 *)0x0;
  local_20 = 0;
  local_res20[0] = 0x3c;
  local_res10[0] = param_2;
  iVar2 = PgmQueryTcpInfo(*(undefined8 *)(pgPgmDevice + 0x28),0x103,local_res10,4,
                          (longlong *)&local_28,(int *)local_res20);
  puVar1 = local_28;
  if (iVar2 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar2;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return iVar2;
    }
    uVar3 = 10;
  }
  else {
    uVar4 = 6;
    if ((uint)local_28[3] < 6) {
      uVar4 = local_28[3];
    }
    memmove((void *)(param_3 + 0x30),local_28 + 4,(ulonglong)uVar4);
    *(int *)(param_3 + 0x24) = puVar1[1] + -0x18;
    *(undefined4 *)(param_3 + 0x2c) = *puVar1;
    ExFreePoolWithTag(puVar1,0);
    local_res20[0] = 0x48;
    iVar2 = PgmQueryTcpInfo(*(undefined8 *)(pgPgmDevice + 0x28),0x102,(void *)0x0,0,&local_20,
                            (int *)local_res20);
    if (-1 < iVar2) {
      iVar2 = -0x3fffffff;
      lVar6 = (longlong)(int)(local_res20[0] / 0x18);
      if (local_res20[0] / 0x18 != 0) {
        puVar5 = (uint *)(local_20 + 8);
        do {
          if (puVar5[-2] == local_res10[0]) {
            iVar2 = 0;
            *(uint *)(param_3 + 0x20) = puVar5[-1];
            uVar4 = *puVar5;
            *(uint *)(param_3 + 0x28) =
                 uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
          }
          puVar5 = puVar5 + 6;
          lVar6 = lVar6 + -1;
        } while (lVar6 != 0);
      }
      ExFreePoolWithTag(local_20,0);
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar2;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
        return iVar2;
      }
      WPP_SF_ZD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids,param_1,
                (char)*(undefined4 *)(param_3 + 0x20));
      return iVar2;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar2;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return iVar2;
    }
    uVar3 = 0xb;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
           &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids,iVar2);
  return iVar2;
}



===== ListenOnAllInterfaces @ 14000bf44 =====

undefined8 ListenOnAllInterfaces(longlong param_1,undefined1 *param_2,undefined1 *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined8 *puVar3;
  longlong ******pppppplVar4;
  longlong ******pppppplVar5;
  code *pcVar6;
  longlong *******ppppppplVar7;
  undefined1 uVar8;
  int iVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  longlong *******ppppppplVar12;
  undefined8 *puVar13;
  ushort uVar14;
  longlong *******ppppppplVar15;
  undefined8 local_res20;
  longlong *******local_48;
  longlong *******local_40;
  
  local_res20 = 0;
  uVar14 = 0;
  uVar10 = Feature_3509484856__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar10 == 0) {
    uVar11 = ListenOnAllInterfaces_old(param_1,param_2,param_3);
  }
  else {
    local_48 = (longlong *******)&local_48;
    ppppppplVar12 = (longlong *******)&local_48;
    local_40 = ppppppplVar12;
    puVar13 = DAT_140036720;
    if ((undefined8 **)DAT_140036720 != &DAT_140036720) {
      do {
        if (0x13 < uVar14) break;
        puVar3 = (undefined8 *)puVar13[2];
        for (; (puVar3 != puVar13 + 2 && (uVar14 < 0x14)); uVar14 = uVar14 + 1) {
          uVar1 = *(undefined4 *)(puVar3 + 2);
          ppppppplVar12 = (longlong *******)ExAllocatePool2(0x40,0x18,0x306d6750);
          if (ppppppplVar12 == (longlong *******)0x0) {
            KeReleaseSpinLock(param_1 + 0x1b8,*param_3);
            KeReleaseSpinLock(&DAT_140036808,*param_2);
            while( true ) {
              ppppppplVar12 = local_48;
              if ((longlong ********)local_48 == &local_48) {
                uVar8 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
                *param_2 = uVar8;
                uVar8 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x1b8);
                *param_3 = uVar8;
                return 0xc000009a;
              }
              ppppppplVar7 = local_48;
              if (((longlong ********)local_48[1] != &local_48) ||
                 (ppppppplVar15 = (longlong *******)*local_48,
                 (longlong *******)ppppppplVar15[1] != local_48)) break;
              ppppppplVar15[1] = (longlong ******)&local_48;
              local_48 = ppppppplVar15;
              ExFreePoolWithTag(ppppppplVar12,0);
            }
            goto LAB_14000c3d9;
          }
          *(undefined4 *)(ppppppplVar12 + 2) = uVar1;
          ppppppplVar7 = local_48;
          if ((longlong ********)*local_40 != &local_48) goto LAB_14000c3d9;
          ppppppplVar12[1] = (longlong ******)local_40;
          *ppppppplVar12 = (longlong ******)&local_48;
          *local_40 = (longlong ******)ppppppplVar12;
          local_40 = ppppppplVar12;
          puVar3 = (undefined8 *)*puVar3;
        }
        puVar13 = (undefined8 *)*puVar13;
      } while ((undefined8 **)puVar13 != &DAT_140036720);
    }
    ppppppplVar15 = local_48;
    if ((longlong ********)local_48 != &local_48) {
      do {
        ppppppplVar12 = (longlong *******)*ppppppplVar15;
        puVar13 = PgmFindReceiverInterface
                            ((undefined8 *)(param_1 + 0x1a8),*(int *)(ppppppplVar15 + 2));
        if (puVar13 != (undefined8 *)0x0) {
          ppppppplVar7 = local_48;
          if (((longlong *******)ppppppplVar12[1] != ppppppplVar15) ||
             (pppppplVar4 = ppppppplVar15[1], (longlong *******)*pppppplVar4 != ppppppplVar15))
          goto LAB_14000c3d9;
          *pppppplVar4 = (longlong *****)ppppppplVar12;
          ppppppplVar12[1] = pppppplVar4;
          ExFreePoolWithTag(ppppppplVar15,0);
          uVar14 = uVar14 - 1;
        }
        ppppppplVar15 = ppppppplVar12;
      } while ((longlong ********)ppppppplVar12 != &local_48);
      ppppppplVar12 = local_40;
    }
    if (uVar14 != 0) {
      while (0x14 < (uint)*(ushort *)(param_1 + 0x14e) + (uint)uVar14) {
        ppppppplVar7 = local_48;
        if (((longlong ********)*ppppppplVar12 != &local_48) ||
           (ppppppplVar15 = (longlong *******)ppppppplVar12[1],
           (longlong *******)*ppppppplVar15 != ppppppplVar12)) goto LAB_14000c3d9;
        *ppppppplVar15 = (longlong ******)&local_48;
        local_40 = ppppppplVar15;
        ExFreePoolWithTag(ppppppplVar12,0);
        uVar14 = uVar14 - 1;
        if (uVar14 == 0) break;
        ppppppplVar12 = local_40;
      }
    }
    if ((longlong ********)local_48 == &local_48) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                  &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids,param_1,
                  (char)*(undefined2 *)(param_1 + 0x14e));
      }
    }
    else {
      KeReleaseSpinLock(param_1 + 0x1b8,*param_3);
      KeReleaseSpinLock(&DAT_140036808,*param_2);
      uVar2 = *(uint *)(param_1 + 0x148);
      local_res20 = CONCAT44(local_res20._4_4_,
                             uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 |
                             uVar2 << 0x18);
      ppppppplVar12 = local_48;
      if ((longlong ********)local_48 != &local_48) {
        do {
          uVar2 = *(uint *)(ppppppplVar12 + 2);
          ppppppplVar15 = (longlong *******)*ppppppplVar12;
          local_res20 = CONCAT44(uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 |
                                 uVar2 << 0x18,(undefined4)local_res20);
          iVar9 = PgmSetTcpInfo(*(undefined8 *)(param_1 + 0x40),6,&local_res20,8);
          uVar8 = (undefined1)((ulonglong)local_res20 >> 0x20);
          if (iVar9 < 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
              WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                        &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids,param_1,uVar8);
            }
            pppppplVar4 = *ppppppplVar12;
            ppppppplVar7 = local_48;
            if (((longlong *******)pppppplVar4[1] != ppppppplVar12) ||
               (pppppplVar5 = ppppppplVar12[1], (longlong *******)*pppppplVar5 != ppppppplVar12))
            goto LAB_14000c3d9;
            *pppppplVar5 = (longlong *****)pppppplVar4;
            pppppplVar4[1] = (longlong *****)pppppplVar5;
            ExFreePoolWithTag(ppppppplVar12,0);
          }
          else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
            WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                      &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids,param_1,uVar8);
          }
          ppppppplVar12 = ppppppplVar15;
        } while ((longlong ********)ppppppplVar15 != &local_48);
      }
      uVar8 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
      *param_2 = uVar8;
      uVar8 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x1b8);
      *param_3 = uVar8;
      while (ppppppplVar12 = local_48, (longlong ********)local_48 != &local_48) {
        ppppppplVar7 = local_48;
        if (((longlong ********)local_48[1] != &local_48) ||
           (ppppppplVar15 = (longlong *******)*local_48,
           (longlong *******)ppppppplVar15[1] != local_48)) {
LAB_14000c3d9:
          local_48 = ppppppplVar7;
          pcVar6 = (code *)swi(0x29);
          (*pcVar6)(3);
          pcVar6 = (code *)swi(3);
          uVar11 = (*pcVar6)();
          return uVar11;
        }
        ppppppplVar15[1] = (longlong ******)&local_48;
        pppppplVar4 = *(longlong *******)(param_1 + 0x1b0);
        ppppppplVar7 = ppppppplVar15;
        if ((longlong ******)*pppppplVar4 != (longlong ******)(param_1 + 0x1a8)) goto LAB_14000c3d9;
        *local_48 = (longlong ******)(param_1 + 0x1a8);
        local_48 = ppppppplVar15;
        ppppppplVar12[1] = pppppplVar4;
        *pppppplVar4 = (longlong *****)ppppppplVar12;
        *(longlong ********)(param_1 + 0x1b0) = ppppppplVar12;
        *(short *)(param_1 + 0x14e) = *(short *)(param_1 + 0x14e) + 1;
      }
    }
    uVar11 = 0;
  }
  return uVar11;
}



===== ListenOnAllInterfaces_old @ 14000c3e8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 ListenOnAllInterfaces_old(longlong param_1,undefined1 *param_2,undefined1 *param_3)

{
  uint uVar1;
  undefined1 uVar2;
  int iVar3;
  ushort uVar4;
  ulonglong uVar5;
  ushort uVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  ushort uVar10;
  uint *puVar11;
  undefined8 *puVar12;
  uint *puVar13;
  ushort uVar14;
  ulonglong uVar15;
  undefined1 auStack_f8 [32];
  undefined8 local_c8;
  undefined1 *local_b8;
  undefined1 *local_b0;
  uint local_a8 [24];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_f8;
  uVar9 = 0;
  local_c8 = 0;
  uVar15 = 0;
  for (puVar12 = DAT_140036720; (undefined8 **)puVar12 != &DAT_140036720;
      puVar12 = (undefined8 *)*puVar12) {
    uVar8 = uVar15;
    for (puVar7 = (undefined8 *)puVar12[2]; puVar7 != puVar12 + 2; puVar7 = (undefined8 *)*puVar7) {
      uVar10 = (short)uVar8 + 1;
      uVar15 = (ulonglong)uVar10;
      local_a8[uVar8] = *(uint *)(puVar7 + 2);
      if (0x13 < uVar10) goto LAB_14000c46f;
      uVar8 = uVar15;
    }
    uVar15 = uVar8;
  }
LAB_14000c46f:
  iVar3 = (int)uVar15;
  uVar10 = *(ushort *)(param_1 + 0x14e);
  uVar8 = 0;
  if (uVar10 != 0) {
    do {
      uVar4 = 0;
      uVar14 = (ushort)uVar15;
      if (uVar14 != 0) {
        do {
          if (*(uint *)(param_1 + 0x150 + uVar8 * 4) == local_a8[uVar4]) {
            uVar14 = uVar14 - 1;
            uVar15 = (ulonglong)uVar14;
            if (uVar4 < uVar14) {
              puVar11 = local_a8 + (ulonglong)uVar4 + 1;
              puVar13 = local_a8 + uVar4;
              for (uVar5 = (ulonglong)(ushort)(uVar14 - uVar4); uVar5 != 0; uVar5 = uVar5 - 1) {
                *puVar13 = *puVar11;
                puVar11 = puVar11 + 1;
                puVar13 = puVar13 + 1;
              }
            }
            break;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < uVar14);
      }
      iVar3 = (int)uVar15;
      uVar4 = (short)uVar8 + 1;
      uVar8 = (ulonglong)uVar4;
    } while (uVar4 < uVar10);
  }
  local_b8 = param_2;
  local_b0 = param_3;
  if ((ushort)iVar3 == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids,param_1,(char)uVar10);
    }
  }
  else {
    uVar4 = 0x14 - uVar10;
    if (iVar3 + (uint)uVar10 < 0x15) {
      uVar4 = (ushort)iVar3;
    }
    KeReleaseSpinLock(param_1 + 0x1b8,CONCAT71((int7)(uVar8 >> 8),*param_3));
    KeReleaseSpinLock(&DAT_140036808,*param_2);
    uVar1 = *(uint *)(param_1 + 0x148);
    uVar10 = 0;
    local_c8 = CONCAT44(local_c8._4_4_,
                        uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 |
                        uVar1 << 0x18);
    if (uVar4 != 0) {
      do {
        while( true ) {
          uVar1 = local_a8[uVar10];
          local_c8 = CONCAT44(uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 |
                              uVar1 << 0x18,(undefined4)local_c8);
          iVar3 = PgmSetTcpInfo(*(undefined8 *)(param_1 + 0x40),6,&local_c8,8);
          uVar2 = (undefined1)((ulonglong)local_c8 >> 0x20);
          if (-1 < iVar3) break;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
            WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                      &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids,param_1,uVar2);
          }
          uVar4 = uVar4 - 1;
          uVar14 = uVar10;
          if (uVar4 <= uVar10) goto LAB_14000c5ec;
          do {
            uVar6 = uVar14 + 1;
            local_a8[uVar14] = local_a8[(ulonglong)uVar14 + 1];
            uVar14 = uVar6;
          } while (uVar6 < uVar4);
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                    &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids,param_1,uVar2);
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < uVar4);
LAB_14000c5ec:
      param_2 = local_b8;
    }
    uVar2 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
    *param_2 = uVar2;
    uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x1b8);
    *local_b0 = uVar2;
    while (((ushort)uVar9 < uVar4 && (*(ushort *)(param_1 + 0x14e) < 0x15))) {
      *(uint *)(param_1 + 0x150 + (ulonglong)*(ushort *)(param_1 + 0x14e) * 4) = local_a8[uVar9];
      *(short *)(param_1 + 0x14e) = *(short *)(param_1 + 0x14e) + 1;
      uVar9 = (ulonglong)(ushort)((ushort)uVar9 + 1);
    }
  }
  return 0;
}



===== StopListeningOnAllInterfacesExcept @ 14000c6e0 =====

void StopListeningOnAllInterfacesExcept
               (longlong *******param_1,longlong *******param_2,longlong *param_3,
               longlong *******param_4)

{
  longlong **********pppppppppplVar1;
  code *pcVar2;
  longlong ************pppppppppppplVar3;
  undefined1 *puVar4;
  undefined1 uVar5;
  byte bVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  longlong **********pppppppppplVar10;
  longlong ***********ppppppppppplVar11;
  undefined8 uVar12;
  longlong ***********ppppppppppplVar13;
  undefined1 *puVar14;
  undefined **ppuVar15;
  longlong *plVar16;
  uint local_res10;
  uint uStackX_14;
  undefined1 auStackY_68 [8];
  undefined1 auStackY_60 [24];
  longlong ************local_38;
  longlong ************local_30;
  longlong ************local_28;
  longlong ************local_20;
  
  local_res10 = 0;
  uStackX_14 = 0;
  ppppppppppplVar13 = (longlong ***********)param_2;
  uVar8 = Feature_3509484856__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar8 == 0) {
    StopListeningOnAllInterfacesExcept_old
              ((longlong *)param_1,(longlong *)param_2,param_3,(longlong *)param_4);
    return;
  }
  local_30 = (longlong ************)&local_38;
  local_38 = (longlong ************)&local_38;
  local_20 = (longlong ************)&local_28;
  local_28 = (longlong ************)&local_28;
  uVar5 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
  ppuVar15 = (undefined **)(param_1 + 0x37);
  bVar6 = KeAcquireSpinLockRaiseToDpc(ppuVar15);
  puVar14 = auStackY_68;
  uVar8 = (ulonglong)bVar6;
  puVar4 = auStackY_68;
  if (((param_1 != (longlong *******)0x0) &&
      (puVar4 = auStackY_68, *(int *)(param_1 + 2) == 0x52444441)) &&
     (puVar4 = auStackY_68, ((ulonglong)param_1[7] & 8) == 0)) {
    param_4 = param_1 + 0x35;
    while (ppppppppppplVar11 = (longlong ***********)*param_4,
          ppppppppppplVar11 != (longlong ***********)param_4) {
      if ((ppppppppppplVar11[1] != (longlong **********)param_4) ||
         (pppppppppplVar10 = *ppppppppppplVar11,
         (longlong ***********)pppppppppplVar10[1] != ppppppppppplVar11)) goto LAB_14000ca33;
      *param_4 = (longlong ******)pppppppppplVar10;
      ppppppppppplVar13 = (longlong ***********)&local_38;
      pppppppppplVar10[1] = (longlong *********)param_4;
      if (*local_30 != ppppppppppplVar13) goto LAB_14000ca33;
      ppppppppppplVar11[1] = (longlong **********)local_30;
      ppppppppppplVar13 = (longlong ***********)&local_38;
      *ppppppppppplVar11 = (longlong **********)ppppppppppplVar13;
      *local_30 = ppppppppppplVar11;
      local_30 = (longlong ************)ppppppppppplVar11;
    }
    *(undefined2 *)((longlong)param_1 + 0x14e) = 0;
    for (puVar9 = DAT_140036720; (undefined8 **)puVar9 != &DAT_140036720;
        puVar9 = (undefined8 *)*puVar9) {
      if ((int)param_2 == *(int *)(puVar9 + 4)) {
        plVar16 = puVar9 + 2;
        param_3 = (longlong *)*plVar16;
        goto LAB_14000c8ce;
      }
    }
LAB_14000c8d7:
    uVar12 = CONCAT71((int7)((ulonglong)ppppppppppplVar13 >> 8),(char)uVar8);
    KeReleaseSpinLock(ppuVar15,uVar12);
    ppppppppppplVar13 = (longlong ***********)CONCAT71((int7)((ulonglong)uVar12 >> 8),uVar5);
    KeReleaseSpinLock(&DAT_140036808);
    while (bVar6 = (byte)uVar8, local_28 != (longlong ************)&local_28) {
      if ((local_28[1] != (longlong ***********)&local_28) ||
         (ppppppppppplVar11 = *local_28, (longlong ************)ppppppppppplVar11[1] != local_28))
      goto LAB_14000ca33;
      ppppppppppplVar11[1] = (longlong **********)&local_28;
      ppppppppppplVar13 = (longlong ***********)0x0;
      local_28 = (longlong ************)ppppppppppplVar11;
      ExFreePoolWithTag();
    }
    uVar7 = *(uint *)(param_1 + 0x29);
    ppuVar15 = &WPP_GLOBAL_Control;
    local_res10 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18;
    while (pppppppppppplVar3 = local_38, bVar6 = (byte)uVar8,
          local_38 != (longlong ************)&local_38) {
      if ((local_38[1] != (longlong ***********)&local_38) ||
         (ppppppppppplVar11 = *local_38, (longlong ************)ppppppppppplVar11[1] != local_38))
      goto LAB_14000ca33;
      ppppppppppplVar11[1] = (longlong **********)&local_38;
      uVar7 = *(uint *)(local_38 + 2);
      param_4 = (longlong *******)0x8;
      uStackX_14 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18;
      local_38 = (longlong ************)ppppppppppplVar11;
      uVar7 = PgmSetTcpInfo(param_1[8],7,&local_res10,8);
      param_3 = (longlong *)(ulonglong)uVar7;
      if ((int)uVar7 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          param_4 = (longlong *******)(ulonglong)uStackX_14;
          param_3 = (longlong *)&WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids;
          WPP_SF_DqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                     &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids,uStackX_14,(char)param_1,
                     (char)uVar7);
        }
      }
      else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        param_3 = (longlong *)&WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids;
        param_4 = param_1;
        WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                  &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids,param_1,(char)uStackX_14);
      }
      ppppppppppplVar13 = (longlong ***********)0x0;
      ExFreePoolWithTag(pppppppppppplVar3);
    }
    goto LAB_14000ca62;
  }
LAB_14000ca3a:
  puVar14 = puVar4;
  uVar12 = CONCAT71((int7)((ulonglong)ppppppppppplVar13 >> 8),bVar6);
  *(undefined8 *)(puVar14 + -8) = 0x14000ca47;
  KeReleaseSpinLock(ppuVar15,uVar12);
  ppppppppppplVar13 = (longlong ***********)CONCAT71((int7)((ulonglong)uVar12 >> 8),uVar5);
  *(undefined8 *)(puVar14 + -8) = 0x14000ca5d;
  KeReleaseSpinLock(&DAT_140036808);
LAB_14000ca62:
  *(undefined8 *)(puVar14 + -8) = 0x14000ca6a;
  PgmDereferenceAddress((longlong *)param_1,ppppppppppplVar13,param_3,(longlong *)param_4);
  return;
LAB_14000c8ce:
  if (param_3 == plVar16) goto LAB_14000c8d7;
  ppppppppppplVar13 = (longlong ***********)(ulonglong)*(uint *)(param_3 + 2);
  pppppppppplVar10 = (longlong **********)PgmFindReceiverInterface(&local_38,*(uint *)(param_3 + 2))
  ;
  bVar6 = (byte)uVar8;
  if (pppppppppplVar10 != (longlong **********)0x0) {
    pppppppppplVar1 = (longlong **********)*pppppppppplVar10;
    if (((longlong **********)pppppppppplVar1[1] != pppppppppplVar10) ||
       (ppppppppppplVar13 = (longlong ***********)pppppppppplVar10[1],
       *ppppppppppplVar13 != pppppppppplVar10)) goto LAB_14000ca33;
    *ppppppppppplVar13 = pppppppppplVar1;
    pppppppppplVar1[1] = (longlong *********)ppppppppppplVar13;
    pppppppppplVar1 = (longlong **********)param_4[1];
    if (*pppppppppplVar1 != (longlong *********)param_4) goto LAB_14000ca33;
    *pppppppppplVar10 = (longlong *********)param_4;
    pppppppppplVar10[1] = (longlong *********)pppppppppplVar1;
    *pppppppppplVar1 = (longlong *********)pppppppppplVar10;
    param_4[1] = (longlong ******)pppppppppplVar10;
    *(short *)((longlong)param_1 + 0x14e) = *(short *)((longlong)param_1 + 0x14e) + 1;
  }
  while( true ) {
    ppppppppppplVar13 = (longlong ***********)(ulonglong)*(uint *)(param_3 + 2);
    ppppppppppplVar11 =
         (longlong ***********)PgmFindReceiverInterface(&local_38,*(uint *)(param_3 + 2));
    bVar6 = (byte)uVar8;
    if (ppppppppppplVar11 == (longlong ***********)0x0) break;
    pppppppppplVar10 = *ppppppppppplVar11;
    if (((longlong ***********)pppppppppplVar10[1] != ppppppppppplVar11) ||
       (ppppppppppplVar13 = (longlong ***********)ppppppppppplVar11[1],
       (longlong ***********)*ppppppppppplVar13 != ppppppppppplVar11)) goto LAB_14000ca33;
    *ppppppppppplVar13 = pppppppppplVar10;
    pppppppppplVar10[1] = (longlong *********)ppppppppppplVar13;
    ppppppppppplVar13 = (longlong ***********)&local_28;
    if (*local_20 != ppppppppppplVar13) goto LAB_14000ca33;
    ppppppppppplVar11[1] = (longlong **********)local_20;
    *ppppppppppplVar11 = (longlong **********)&local_28;
    *local_20 = ppppppppppplVar11;
    local_20 = (longlong ************)ppppppppppplVar11;
  }
  param_3 = (longlong *)*param_3;
  goto LAB_14000c8ce;
LAB_14000ca33:
  pcVar2 = (code *)swi(0x29);
  (*pcVar2)(3);
  puVar4 = auStackY_60;
  goto LAB_14000ca3a;
}



===== StopListeningOnAllInterfacesExcept_old @ 14000ca8c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void StopListeningOnAllInterfacesExcept_old
               (longlong *param_1,longlong *param_2,longlong *param_3,longlong *param_4)

{
  undefined8 *puVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  uint uVar4;
  undefined8 *puVar5;
  longlong *_Src;
  undefined8 uVar6;
  uint *puVar7;
  ushort uVar8;
  ulonglong uVar9;
  ushort uVar10;
  longlong *plVar11;
  undefined1 auStackY_d8 [32];
  uint local_a8;
  uint uStack_a4;
  uint local_98 [24];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_a8 = 0;
  uStack_a4 = 0;
  _Src = param_2;
  uVar2 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x37);
  if (((param_1 == (longlong *)0x0) || ((int)param_1[2] != 0x52444441)) ||
     ((*(uint *)(param_1 + 7) & 8) != 0)) {
    uVar6 = CONCAT71((int7)((ulonglong)_Src >> 8),uVar3);
    KeReleaseSpinLock(param_1 + 0x37,uVar6);
    uVar6 = CONCAT71((int7)((ulonglong)uVar6 >> 8),uVar2);
    KeReleaseSpinLock(&DAT_140036808);
LAB_14000cd33:
    PgmDereferenceAddress(param_1,uVar6,param_3,param_4);
    return;
  }
  uVar10 = *(ushort *)((longlong)param_1 + 0x14e);
  uVar8 = 0;
  if (uVar10 != 0) {
    _Src = param_1 + 0x2a;
    param_3 = (longlong *)((ulonglong)uVar10 << 2);
    memmove(local_98,_Src,(size_t)param_3);
    do {
      uVar8 = uVar8 + 1;
    } while (uVar8 < uVar10);
  }
  *(undefined2 *)((longlong)param_1 + 0x14e) = 0;
  puVar5 = DAT_140036720;
  while( true ) {
    if ((undefined8 **)puVar5 == &DAT_140036720) goto LAB_14000cc18;
    if ((int)param_2 == *(int *)(puVar5 + 4)) break;
    puVar5 = (undefined8 *)*puVar5;
  }
  puVar1 = (undefined8 *)puVar5[2];
  while ((puVar1 != puVar5 + 2 &&
         ((uVar9 = Feature_469915960__private_IsEnabledDeviceUsageNoInline(), (int)uVar9 == 0 ||
          (*(ushort *)((longlong)param_1 + 0x14e) < 0x14))))) {
    _Src = (longlong *)0x0;
    *(undefined4 *)
     ((longlong)param_1 + (ulonglong)*(ushort *)((longlong)param_1 + 0x14e) * 4 + 0x150) =
         *(undefined4 *)(puVar1 + 2);
    *(short *)((longlong)param_1 + 0x14e) = *(short *)((longlong)param_1 + 0x14e) + 1;
    if (uVar8 != 0) {
      uVar4 = *(uint *)(puVar1 + 2);
      param_4 = (longlong *)(ulonglong)uVar4;
      do {
        while (local_98[(longlong)_Src] == uVar4) {
          uVar8 = uVar8 - 1;
          plVar11 = _Src;
          param_3 = _Src;
          if (uVar8 <= (ushort)_Src) goto LAB_14000cc05;
          do {
            uVar10 = (short)plVar11 + 1;
            param_3 = (longlong *)(ulonglong)uVar10;
            local_98[(longlong)plVar11] = local_98[(longlong)((longlong)plVar11 + 1)];
            plVar11 = param_3;
          } while (uVar10 < uVar8);
        }
        uVar10 = (ushort)_Src + 1;
        _Src = (longlong *)(ulonglong)uVar10;
      } while (uVar10 < uVar8);
    }
LAB_14000cc05:
    puVar1 = (undefined8 *)*puVar1;
  }
LAB_14000cc18:
  uVar6 = CONCAT71((int7)((ulonglong)_Src >> 8),uVar3);
  KeReleaseSpinLock(param_1 + 0x37,uVar6);
  uVar6 = CONCAT71((int7)((ulonglong)uVar6 >> 8),uVar2);
  KeReleaseSpinLock(&DAT_140036808);
  uVar4 = *(uint *)(param_1 + 0x29);
  local_a8 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
  if (uVar8 != 0) {
    puVar7 = local_98;
    uVar9 = (ulonglong)uVar8;
    do {
      uVar4 = *puVar7;
      param_4 = (longlong *)0x8;
      uStack_a4 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
      uVar6 = 7;
      uVar4 = PgmSetTcpInfo(param_1[8],7,&local_a8,8);
      param_3 = (longlong *)(ulonglong)uVar4;
      if ((int)uVar4 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          param_4 = (longlong *)(ulonglong)uStack_a4;
          uVar6 = 0x17;
          param_3 = (longlong *)&WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids;
          WPP_SF_DqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                     &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids,uStack_a4,(char)param_1,
                     (char)uVar4);
        }
      }
      else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        param_3 = (longlong *)&WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids;
        uVar6 = 0x16;
        param_4 = param_1;
        WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                  &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids,param_1,(char)uStack_a4);
      }
      puVar7 = puVar7 + 1;
      uVar9 = uVar9 - 1;
    } while (uVar9 != 0);
  }
  goto LAB_14000cd33;
}



===== StopListeningOnInterface @ 14000cd74 =====

undefined8
StopListeningOnInterface(uint param_1,undefined1 *param_2,undefined *param_3,longlong *param_4)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  longlong *plVar9;
  short sVar10;
  longlong *plVar11;
  longlong *plVar12;
  undefined *puVar13;
  undefined1 local_res18 [8];
  undefined8 local_res20;
  
  local_res20 = 0;
  plVar12 = (longlong *)0x0;
  uVar7 = Feature_3509484856__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar7 == 0) {
    uVar8 = StopListeningOnInterface_old(param_1,param_2,param_3,param_4);
  }
  else {
    plVar11 = DAT_1400366b0;
    local_res20._4_4_ =
         param_1 >> 0x18 | (param_1 & 0xff0000) >> 8 | (param_1 & 0xff00) << 8 | param_1 << 0x18;
    if ((longlong **)DAT_1400366b0 != &DAT_1400366b0) {
      do {
        plVar1 = plVar11 + 0x37;
        local_res18[0] = KeAcquireSpinLockRaiseToDpc(plVar1);
        uVar7 = (ulonglong)*(uint *)(plVar11 + 7);
        param_3 = (undefined *)CONCAT71((int7)((ulonglong)param_3 >> 8),local_res18[0]);
        if ((*(uint *)(plVar11 + 7) & 4) == 0) {
LAB_14000ce05:
          uVar8 = CONCAT71((int7)(uVar7 >> 8),(char)param_3);
          KeReleaseSpinLock(plVar1);
        }
        else {
          uVar7 = (ulonglong)param_1;
          plVar9 = PgmFindReceiverInterface(plVar11 + 0x35,param_1);
          if (plVar9 == (longlong *)0x0) goto LAB_14000ce05;
          lVar2 = *plVar9;
          if ((*(longlong **)(lVar2 + 8) != plVar9) ||
             (plVar3 = (longlong *)plVar9[1], (longlong *)*plVar3 != plVar9)) {
            pcVar4 = (code *)swi(0x29);
            (*pcVar4)(3);
            pcVar4 = (code *)swi(3);
            uVar8 = (*pcVar4)();
            return uVar8;
          }
          *plVar3 = lVar2;
          *(longlong **)(lVar2 + 8) = plVar3;
          *(int *)((longlong)plVar11 + 0x14) = *(int *)((longlong)plVar11 + 0x14) + 1;
          sVar10 = *(short *)((longlong)plVar11 + 0x14e) + -1;
          *(short *)((longlong)plVar11 + 0x14e) = sVar10;
          if ((((*(uint *)(plVar11 + 7) & 4) != 0) && (sVar10 == 0)) &&
             (*(uint *)(plVar11 + 7) = *(uint *)(plVar11 + 7) | 8,
             (undefined8 **)DAT_140036720 != &DAT_140036720)) {
            uVar7 = ListenOnAllInterfaces((longlong)plVar11,param_2,local_res18);
            puVar13 = (undefined *)(uVar7 & 0xffffffff);
            if ((int)uVar7 < 0) {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
                puVar13 = &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids;
                param_4 = plVar11;
                WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                          &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids,plVar11,(char)uVar7);
              }
            }
            else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
              puVar13 = &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids;
              param_4 = plVar11;
              WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                       &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids,plVar11);
            }
            param_3 = (undefined *)CONCAT71((int7)((ulonglong)puVar13 >> 8),local_res18[0]);
          }
          KeReleaseSpinLock(plVar1,(ulonglong)param_3 & 0xff);
          KeReleaseSpinLock(&DAT_140036808);
          uVar8 = 0;
          ExFreePoolWithTag(plVar9);
          if (plVar12 != (longlong *)0x0) {
            PgmDereferenceAddress(plVar12,uVar8,param_3,param_4);
          }
          uVar6 = *(uint *)(plVar11 + 0x29);
          param_4 = (longlong *)0x8;
          local_res20._0_4_ =
               uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18;
          uVar8 = 7;
          uVar6 = PgmSetTcpInfo(plVar11[8],7,&local_res20,8);
          param_3 = (undefined *)(ulonglong)uVar6;
          if ((int)uVar6 < 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
              param_4 = (longlong *)(ulonglong)local_res20._4_4_;
              uVar8 = 0x14;
              param_3 = &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids;
              WPP_SF_DqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                         &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids,local_res20._4_4_,
                         (char)plVar11,(char)uVar6);
            }
          }
          else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
            param_3 = &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids;
            uVar8 = 0x13;
            param_4 = plVar11;
            WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                      &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids,plVar11,
                      (char)local_res20._4_4_);
          }
          uVar5 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
          *param_2 = uVar5;
          plVar12 = plVar11;
        }
        plVar11 = (longlong *)*plVar11;
      } while ((longlong **)plVar11 != &DAT_1400366b0);
      if (plVar12 != (longlong *)0x0) {
        PgmDereferenceAddress(plVar12,uVar8,param_3,param_4);
      }
    }
    uVar8 = 0;
  }
  return uVar8;
}



===== StopListeningOnInterface_old @ 14000d060 =====

undefined8
StopListeningOnInterface_old(uint param_1,undefined1 *param_2,undefined *param_3,longlong *param_4)

{
  undefined1 uVar1;
  uint uVar2;
  ulonglong uVar3;
  ushort uVar4;
  ushort uVar5;
  undefined1 *puVar6;
  undefined8 uVar7;
  longlong *plVar8;
  longlong *plVar9;
  undefined *puVar10;
  undefined1 local_res18 [8];
  uint local_res20;
  uint uStackX_24;
  
  uStackX_24 = param_1 >> 0x18 | (param_1 & 0xff0000) >> 8 | (param_1 & 0xff00) << 8 |
               param_1 << 0x18;
  local_res20 = 0;
  plVar9 = (longlong *)0x0;
  plVar8 = DAT_1400366b0;
  if ((longlong **)DAT_1400366b0 != &DAT_1400366b0) {
    do {
      local_res18[0] = KeAcquireSpinLockRaiseToDpc(plVar8 + 0x37);
      puVar6 = (undefined1 *)(ulonglong)*(uint *)(plVar8 + 7);
      param_3 = (undefined *)CONCAT71((int7)((ulonglong)param_3 >> 8),local_res18[0]);
      if ((*(uint *)(plVar8 + 7) & 4) == 0) {
LAB_14000d2d9:
        uVar7 = CONCAT71((int7)((ulonglong)puVar6 >> 8),local_res18[0]);
        KeReleaseSpinLock(plVar8 + 0x37);
      }
      else {
        uVar4 = *(ushort *)((longlong)plVar8 + 0x14e);
        puVar6 = (undefined1 *)0x0;
        if (uVar4 == 0) goto LAB_14000d2d9;
        param_4 = (longlong *)0x1;
        do {
          if (*(uint *)((longlong)plVar8 + (longlong)puVar6 * 4 + 0x150) == param_1) break;
          uVar5 = (short)puVar6 + 1;
          puVar6 = (undefined1 *)(ulonglong)uVar5;
        } while (uVar5 < uVar4);
        if (uVar4 <= (ushort)puVar6) goto LAB_14000d2d9;
        uVar4 = uVar4 - 1;
        *(ushort *)((longlong)plVar8 + 0x14e) = uVar4;
        for (; (ushort)puVar6 < uVar4;
            puVar6 = (undefined1 *)(ulonglong)(ushort)((ushort)puVar6 + 1)) {
          *(undefined4 *)((longlong)plVar8 + (longlong)puVar6 * 4 + 0x150) =
               *(undefined4 *)((longlong)plVar8 + (longlong)puVar6 * 4 + 0x154);
          uVar4 = *(ushort *)((longlong)plVar8 + 0x14e);
        }
        *(int *)((longlong)plVar8 + 0x14) = *(int *)((longlong)plVar8 + 0x14) + 1;
        if ((((*(uint *)(plVar8 + 7) & 4) != 0) && (uVar4 == 0)) &&
           (*(uint *)(plVar8 + 7) = *(uint *)(plVar8 + 7) | 8,
           (undefined8 **)DAT_140036720 != &DAT_140036720)) {
          puVar6 = param_2;
          uVar3 = ListenOnAllInterfaces((longlong)plVar8,param_2,local_res18);
          puVar10 = (undefined *)(uVar3 & 0xffffffff);
          if ((int)uVar3 < 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
              puVar6 = (undefined1 *)0x0;
              puVar10 = &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids;
              param_4 = plVar8;
              WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                        &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids,plVar8,(char)uVar3);
            }
          }
          else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
            puVar10 = &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids;
            puVar6 = (undefined1 *)0x0;
            param_4 = plVar8;
            WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                     &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids,plVar8);
          }
          param_3 = (undefined *)CONCAT71((int7)((ulonglong)puVar10 >> 8),local_res18[0]);
        }
        uVar7 = CONCAT71((int7)((ulonglong)puVar6 >> 8),(char)param_3);
        KeReleaseSpinLock(plVar8 + 0x37,uVar7);
        uVar7 = CONCAT71((int7)((ulonglong)uVar7 >> 8),*param_2);
        KeReleaseSpinLock(&DAT_140036808);
        if (plVar9 != (longlong *)0x0) {
          PgmDereferenceAddress(plVar9,uVar7,param_3,param_4);
        }
        uVar2 = *(uint *)(plVar8 + 0x29);
        param_4 = (longlong *)0x8;
        local_res20 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 |
                      uVar2 << 0x18;
        uVar7 = 7;
        uVar2 = PgmSetTcpInfo(plVar8[8],7,&local_res20,8);
        param_3 = (undefined *)(ulonglong)uVar2;
        if ((int)uVar2 < 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
            param_4 = (longlong *)(ulonglong)uStackX_24;
            uVar7 = 0x10;
            param_3 = &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids;
            WPP_SF_DqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                       &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids,uStackX_24,(char)plVar8,
                       (char)uVar2);
          }
        }
        else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          param_3 = &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids;
          uVar7 = 0xf;
          param_4 = plVar8;
          WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                    &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids,plVar8,(char)uStackX_24);
        }
        uVar1 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
        *param_2 = uVar1;
        plVar9 = plVar8;
      }
      plVar8 = (longlong *)*plVar8;
    } while ((longlong **)plVar8 != &DAT_1400366b0);
    if (plVar9 != (longlong *)0x0) {
      PgmDereferenceAddress(plVar9,uVar7,param_3,param_4);
    }
  }
  return 0;
}



===== TdiAddressArrival @ 14000d330 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TdiAddressArrival(longlong param_1,wchar_t *param_2,undefined8 param_3,byte *param_4)

{
  byte *pbVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  code *pcVar5;
  undefined4 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  int iVar9;
  longlong *plVar10;
  longlong *plVar11;
  undefined8 *puVar12;
  ulonglong uVar13;
  undefined2 uVar14;
  undefined8 uVar15;
  undefined8 *puVar16;
  longlong *plVar17;
  undefined1 *puVar18;
  undefined *puVar19;
  byte *pbVar20;
  uint uVar21;
  undefined *puVar22;
  byte *pbVar23;
  undefined1 auStackY_c8 [8];
  undefined1 auStackY_c0 [24];
  undefined1 uVar24;
  undefined1 uVar25;
  undefined1 local_88;
  byte local_87 [7];
  wchar_t *local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_c8;
  pbVar23 = (byte *)0x0;
  puVar18 = auStackY_c8;
  if (*(short *)(param_1 + 2) != 2) goto LAB_14000d8c4;
  puVar19 = &DAT_140036808;
  local_80 = param_2;
  uVar7 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
  puVar18 = auStackY_c8;
  if ((pgPgmDevice == 0) || (puVar18 = auStackY_c8, *(int *)(pgPgmDevice + 0xc) != 0x43564544))
  goto LAB_14000d8b3;
  uVar8 = KeAcquireSpinLockRaiseToDpc(pgPgmDevice + 0x60);
  *(int *)(pgPgmDevice + 0x10) = *(int *)(pgPgmDevice + 0x10) + 1;
  KeReleaseSpinLock(pgPgmDevice + 0x60,uVar8);
  KeReleaseSpinLock(&DAT_140036808,uVar7);
  uVar2 = *(uint *)(param_1 + 6);
  uVar4 = uVar2 & 0xff00;
  uVar21 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | uVar4 << 8 | uVar2 << 0x18;
  local_78 = 0;
  uStack_70 = 0;
  local_48 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  iVar9 = GetIpInterfaceInfoForDevice(param_2,uVar2,(longlong)&local_78);
  if (-1 < iVar9) {
    uVar7 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
    uVar13 = local_58;
    iVar9 = (int)local_58;
    puVar19 = (undefined *)(local_58 & 0xffffffff);
    plVar17 = &DAT_140036720;
    do {
      plVar17 = (longlong *)*plVar17;
      uVar6 = (undefined4)uStack_50;
      uVar8 = (undefined1)(uVar4 >> 8);
      uVar24 = (undefined1)((uVar2 & 0xff0000) >> 0x10);
      uVar25 = (undefined1)(uVar2 >> 0x18);
      local_88 = uVar7;
      if (plVar17 == &DAT_140036720) {
        plVar17 = (longlong *)ExAllocatePool2(0x40,0x38,0x306d6750);
        if (plVar17 == (longlong *)0x0) {
          KeReleaseSpinLock(&DAT_140036808,uVar7);
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
            WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
                      &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids,uVar21,(char)uVar13);
          }
          goto LAB_14000d449;
        }
        plVar11 = plVar17 + 2;
        plVar17[3] = (longlong)plVar11;
        *plVar11 = (longlong)plVar11;
        *(undefined4 *)((longlong)plVar17 + 0x2c) = uStack_50._4_4_;
        *(undefined4 *)(plVar17 + 6) = (undefined4)local_48;
        *(undefined2 *)((longlong)plVar17 + 0x34) = local_48._4_2_;
        *(int *)(plVar17 + 4) = iVar9;
        *(uint *)((longlong)plVar17 + 0x24) = local_58._4_4_;
        *(undefined4 *)(plVar17 + 5) = uVar6;
        if (DAT_140036768 < local_58._4_4_) {
          DAT_140036768 = local_58._4_4_;
        }
        if ((undefined8 *)*DAT_140036728 != &DAT_140036720) goto LAB_14000d8ac;
        *plVar17 = (longlong)&DAT_140036720;
        plVar17[1] = (longlong)DAT_140036728;
        *DAT_140036728 = (longlong)plVar17;
        DAT_140036728 = plVar17;
        goto LAB_14000d5c2;
      }
    } while ((int)plVar17[4] != (int)local_58);
    plVar11 = plVar17 + 2;
    plVar10 = plVar11;
    do {
      plVar10 = (longlong *)*plVar10;
      if (plVar10 == plVar11) goto LAB_14000d5c2;
    } while (*(uint *)(plVar10 + 2) != uVar21);
    KeReleaseSpinLock(&DAT_140036808,CONCAT71((int7)((ulonglong)plVar11 >> 8),uVar7));
    PgmDereferenceDevice();
    puVar18 = auStackY_c8;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (puVar18 = auStackY_c8, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) goto LAB_14000d8c4;
    uVar14 = 0x22;
    goto LAB_14000d7bc;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
             &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids,iVar9);
  }
  goto LAB_14000d449;
LAB_14000d5c2:
  puVar22 = (undefined *)0x306d6750;
  puVar12 = (undefined8 *)ExAllocatePool2(0x40);
  plVar11 = plVar17 + 2;
  if (puVar12 != (undefined8 *)0x0) {
    *(uint *)(puVar12 + 2) = uVar21;
    *(undefined4 *)((longlong)puVar12 + 0x14) = uVar6;
    puVar16 = (undefined8 *)plVar17[3];
    if ((longlong *)*puVar16 == plVar11) {
      *puVar12 = plVar11;
      puVar12[1] = puVar16;
      *puVar16 = puVar12;
      plVar17[3] = (longlong)puVar12;
      pbVar20 = DAT_1400366b0;
      if ((byte **)DAT_1400366b0 != &DAT_1400366b0) {
        do {
          pbVar1 = pbVar20 + 0x1b8;
          local_87[0] = KeAcquireSpinLockRaiseToDpc(pbVar1);
          if (((pbVar20 != (byte *)0x0) && (*(int *)(pbVar20 + 0x10) == 0x52444441)) &&
             (puVar16 = (undefined8 *)0x0, ((byte)*(undefined4 *)(pbVar20 + 0x38) & 0xc) == 0xc)) {
            *(int *)(pbVar20 + 0x14) = *(int *)(pbVar20 + 0x14) + 1;
            if (pbVar23 != (byte *)0x0) {
              uVar13 = (ulonglong)local_87[0];
              KeReleaseSpinLock(pbVar1,uVar13);
              uVar15 = CONCAT71((int7)(uVar13 >> 8),uVar7);
              KeReleaseSpinLock(&DAT_140036808);
              PgmDereferenceAddress((longlong *)pbVar23,uVar15,puVar22,(longlong *)param_4);
              local_88 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
              local_87[0] = KeAcquireSpinLockRaiseToDpc(pbVar1);
            }
            param_4 = local_87;
            puVar16 = (undefined8 *)(ulonglong)uVar21;
            uVar13 = ReceiverAddMCastIf((longlong)pbVar20,uVar21,&local_88,param_4);
            puVar22 = (undefined *)(uVar13 & 0xffffffff);
            if ((int)uVar13 < 0) {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
                puVar16 = (undefined8 *)0x0;
                puVar22 = &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids;
                param_4 = pbVar20;
                WPP_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
                           &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids,pbVar20,(char)uVar13,
                           uVar25);
              }
            }
            else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
              puVar22 = &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids;
              puVar16 = (undefined8 *)0x0;
              param_4 = pbVar20;
              WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
                        &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids,pbVar20,uVar25);
            }
            pbVar23 = pbVar20;
            uVar7 = local_88;
          }
          puVar16 = (undefined8 *)CONCAT71((int7)((ulonglong)puVar16 >> 8),local_87[0]);
          KeReleaseSpinLock(pbVar1,puVar16);
          pbVar20 = *(byte **)pbVar20;
        } while ((byte **)pbVar20 != &DAT_1400366b0);
        param_2 = local_80;
      }
      uVar15 = CONCAT71((int7)((ulonglong)puVar16 >> 8),uVar7);
      KeReleaseSpinLock(&DAT_140036808);
      if (pbVar23 != (byte *)0x0) {
        PgmDereferenceAddress((longlong *)pbVar23,uVar15,puVar22,(longlong *)param_4);
      }
      PgmDereferenceDevice();
      puVar18 = auStackY_c8;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (puVar18 = auStackY_c8, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0))
      goto LAB_14000d8c4;
      uVar14 = 0x27;
LAB_14000d7bc:
      WPP_SF_ddddZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar14,(ulonglong)(uVar4 >> 8),
                   uVar2 & 0xff,uVar8,uVar24,uVar25,param_2);
      puVar18 = auStackY_c8;
      goto LAB_14000d8c4;
    }
LAB_14000d8ac:
    uVar7 = SUB81(plVar17,0);
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(3);
    puVar18 = auStackY_c0;
LAB_14000d8b3:
    *(undefined8 *)(puVar18 + -8) = 0x14000d8bf;
    KeReleaseSpinLock(puVar19,uVar7);
    goto LAB_14000d8c4;
  }
  if ((longlong *)*plVar11 == plVar11) {
    lVar3 = *plVar17;
    if ((*(longlong **)(lVar3 + 8) != plVar17) ||
       (plVar11 = (longlong *)plVar17[1], (longlong *)*plVar11 != plVar17)) goto LAB_14000d8ac;
    *plVar11 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar11;
    ExFreePoolWithTag(plVar17,0);
  }
  KeReleaseSpinLock(&DAT_140036808,uVar7);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_ddddZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,(ulonglong)(uVar4 >> 8),
                 uVar2 & 0xff,uVar8,uVar24,uVar25,param_2);
  }
LAB_14000d449:
  PgmDereferenceDevice();
  puVar18 = auStackY_c8;
LAB_14000d8c4:
  *(undefined8 *)(puVar18 + -8) = 0x14000d8d0;
  return;
}



===== TdiAddressDeletion @ 14000d900 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TdiAddressDeletion(longlong param_1,undefined8 param_2,undefined *param_3,longlong *param_4)

{
  uint uVar1;
  longlong *plVar2;
  uint uVar3;
  code *pcVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  longlong *plVar8;
  undefined2 uVar9;
  undefined8 uVar10;
  longlong lVar11;
  undefined1 *puVar12;
  longlong *plVar13;
  undefined1 *puVar14;
  longlong *plVar15;
  longlong *plVar16;
  uint uVar17;
  uint uVar18;
  undefined1 local_res8 [8];
  undefined8 local_res10;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [24];
  undefined4 local_58;
  undefined8 local_50;
  uint local_48;
  undefined8 local_40;
  
  plVar15 = (longlong *)0x0;
  if (*(short *)(param_1 + 2) != 2) {
    return;
  }
  uVar1 = *(uint *)(param_1 + 6);
  uVar18 = uVar1 >> 0x18;
  uVar3 = uVar1 & 0xff0000;
  uVar17 = uVar18 | uVar3 >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  local_res10 = param_2;
  uVar5 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
  puVar14 = auStack_78;
  plVar13 = &DAT_140036720;
  while (plVar13 = (longlong *)*plVar13, local_res8[0] = uVar5, plVar13 != &DAT_140036720) {
    plVar16 = plVar13 + 2;
    plVar8 = plVar16;
    while (plVar8 = (longlong *)*plVar8, plVar8 != plVar16) {
      if (*(uint *)(plVar8 + 2) == uVar17) {
        lVar11 = *plVar8;
        if ((*(longlong **)(lVar11 + 8) != plVar8) ||
           (plVar2 = (longlong *)plVar8[1], (longlong *)*plVar2 != plVar8)) {
LAB_14000dbd2:
          pcVar4 = (code *)swi(0x29);
          (*pcVar4)(3);
          puVar14 = auStack_70;
          goto LAB_14000dbd9;
        }
        *plVar2 = lVar11;
        *(longlong **)(lVar11 + 8) = plVar2;
        ExFreePoolWithTag(plVar8,0);
        if ((longlong *)*plVar16 == plVar16) {
          lVar11 = *plVar13;
          if ((*(longlong **)(lVar11 + 8) != plVar13) ||
             (plVar16 = (longlong *)plVar13[1], (longlong *)*plVar16 != plVar13))
          goto LAB_14000dbd2;
          *plVar16 = lVar11;
          *(longlong **)(lVar11 + 8) = plVar16;
          ExFreePoolWithTag(plVar13,0);
        }
        puVar14 = auStack_78;
        plVar13 = PgmDynamicConfig;
        if ((longlong **)PgmDynamicConfig == &PgmDynamicConfig) goto LAB_14000db57;
        goto LAB_14000d9f4;
      }
    }
  }
LAB_14000dbd9:
  *(undefined8 *)(puVar14 + -8) = 0x14000dbea;
  KeReleaseSpinLock(&DAT_140036808,uVar5);
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return;
  }
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
    return;
  }
  *(undefined8 *)(puVar14 + 0x38) = param_2;
  uVar9 = 0x28;
  *(uint *)(puVar14 + 0x30) = uVar18;
  *(uint *)(puVar14 + 0x28) = uVar3 >> 0x10;
  goto LAB_14000dc2a;
LAB_14000d9f4:
  do {
    plVar16 = plVar13;
    if (*(uint *)(plVar13 + 0x1e) == uVar17) {
      uVar6 = KeAcquireSpinLockRaiseToDpc(plVar13 + 0x37);
      *(uint *)(plVar13 + 7) = *(uint *)(plVar13 + 7) | 1;
      uVar10 = 0x100;
      plVar8 = plVar13 + 3;
      do {
        plVar8 = (longlong *)*plVar8;
        if (plVar8 == plVar13 + 3) goto LAB_14000db25;
      } while (((*(uint *)(plVar8 + 4) & 0x100) != 0) ||
              (*(uint *)(plVar8 + 4) = *(uint *)(plVar8 + 4) | 0x100, plVar13[0x12] == 0));
      *(int *)((longlong)plVar13 + 0x14) = *(int *)((longlong)plVar13 + 0x14) + 1;
      uVar7 = KeAcquireSpinLockRaiseToDpc(plVar8 + 0x2d);
      *(int *)((longlong)plVar8 + 0x14) = *(int *)((longlong)plVar8 + 0x14) + 1;
      uVar10 = CONCAT71((int7)((ulonglong)uVar10 >> 8),uVar7);
      KeReleaseSpinLock(plVar8 + 0x2d,uVar10);
      uVar10 = CONCAT71((int7)((ulonglong)uVar10 >> 8),uVar6);
      KeReleaseSpinLock(plVar13 + 0x37,uVar10);
      uVar10 = CONCAT71((int7)((ulonglong)uVar10 >> 8),uVar5);
      KeReleaseSpinLock(&DAT_140036808);
      if (plVar15 != (longlong *)0x0) {
        PgmDereferenceAddress(plVar15,uVar10,param_3,param_4);
      }
      param_4 = (longlong *)0x0;
      lVar11 = plVar8[10];
      param_3 = (undefined *)0x0;
      local_48 = 2;
      local_50 = 0;
      local_58 = 0;
      (*(code *)plVar13[0x12])(plVar13[0x13]);
      PgmDereferenceSessionCommon(plVar8,lVar11,param_3,param_4);
      uVar5 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
      uVar6 = KeAcquireSpinLockRaiseToDpc(plVar13 + 0x37);
      plVar16 = (longlong *)&PgmDynamicConfig;
      plVar15 = plVar13;
LAB_14000db25:
      KeReleaseSpinLock(plVar13 + 0x37,uVar6);
    }
    plVar13 = (longlong *)*plVar16;
  } while ((longlong **)plVar13 != &PgmDynamicConfig);
  param_2 = local_res10;
  local_res8[0] = uVar5;
LAB_14000db57:
  puVar12 = local_res8;
  StopListeningOnInterface(uVar17,puVar12,param_3,param_4);
  uVar10 = CONCAT71((int7)((ulonglong)puVar12 >> 8),local_res8[0]);
  KeReleaseSpinLock(&DAT_140036808);
  if (plVar15 != (longlong *)0x0) {
    PgmDereferenceAddress(plVar15,uVar10,param_3,param_4);
  }
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return;
  }
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
    return;
  }
  local_40 = param_2;
  uVar9 = 0x29;
  local_48 = uVar18;
  local_50 = CONCAT44(local_50._4_4_,uVar3 >> 0x10);
LAB_14000dc2a:
  uVar10 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
  uVar18 = (uVar1 & 0xff00) >> 8;
  *(uint *)(puVar14 + 0x20) = uVar18;
  *(undefined8 *)(puVar14 + -8) = 0x14000dc47;
  WPP_SF_ddddZ(uVar10,uVar9,(ulonglong)uVar18,uVar1 & 0xff,puVar14[0x20],puVar14[0x28],puVar14[0x30]
               ,*(wchar_t **)(puVar14 + 0x38));
  return;
}



===== TdiBindHandler @ 14000dc70 =====

void TdiBindHandler(int param_1,wchar_t *param_2)

{
  undefined2 uVar1;
  
  if (param_1 == 1) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
      return;
    }
    uVar1 = 0x2a;
  }
  else if (param_1 == 2) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
      return;
    }
    uVar1 = 0x2b;
  }
  else if (param_1 == 4) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
      return;
    }
    uVar1 = 0x2c;
  }
  else {
    if (param_1 != 5) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
        return;
      }
      WPP_SF_DZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
                &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids,param_1,param_2);
      return;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
      return;
    }
    uVar1 = 0x2d;
  }
  WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar1,
           &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids,param_2);
  return;
}



===== TdiPnPPowerHandler @ 14000dd80 =====

undefined8 TdiPnPPowerHandler(wchar_t *param_1,int *param_2,undefined8 param_3)

{
  int iVar1;
  undefined2 uVar2;
  
  iVar1 = *param_2;
  if (iVar1 == 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) == 0) {
      return 0;
    }
    uVar2 = 0x30;
  }
  else if (iVar1 == 1) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) == 0) {
      return 0;
    }
    uVar2 = 0x2f;
  }
  else if (iVar1 == 2) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
      return 0;
    }
    uVar2 = 0x31;
  }
  else if (iVar1 == 3) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
      return 0;
    }
    uVar2 = 0x32;
  }
  else if (iVar1 == 4) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) == 0) {
      return 0;
    }
    uVar2 = 0x33;
  }
  else if (iVar1 == 5) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) == 0) {
      return 0;
    }
    uVar2 = 0x34;
  }
  else {
    if (iVar1 != 7) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
        return 0;
      }
      WPP_SF_dZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),WPP_GLOBAL_Control,param_3,iVar1,param_1)
      ;
      return 0;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) == 0) {
      return 0;
    }
    uVar2 = 0x35;
  }
  WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
           &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids,param_1);
  return 0;
}



===== WPP_SF_DqD @ 14000df28 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DqD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,8,&param_6,4,0);
  return;
}



===== WPP_SF_Z @ 14000df88 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Z(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  
  if (param_4 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_4;
    if (*param_4 != L'\0') {
      pwVar1 = *(wchar_t **)(param_4 + 4);
      goto LAB_14000dfb5;
    }
  }
  pwVar1 = L"NULL";
LAB_14000dfb5:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,2,pwVar1,wVar2,0);
  return;
}



===== WPP_SF_dZ @ 14000e008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dZ(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              wchar_t *param_5)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  undefined4 local_res20 [2];
  
  if (param_5 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *param_5;
    if (*param_5 != L'\0') {
      pwVar2 = *(wchar_t **)(param_5 + 4);
      goto LAB_14000e03e;
    }
  }
  pwVar2 = L"NULL";
LAB_14000e03e:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids,0x36,local_res20,4,
             param_5,2,pwVar2,wVar1,0);
  return;
}



===== WPP_SF_ddddZ @ 14000e0ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ddddZ(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,wchar_t *param_8)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  wchar_t wVar3;
  undefined4 local_res20 [2];
  
  if (param_8 == (wchar_t *)0x0) {
    wVar3 = L'\b';
  }
  else {
    wVar3 = *param_8;
    if (*param_8 != L'\0') {
      pwVar1 = *(wchar_t **)(param_8 + 4);
      goto LAB_14000e0e9;
    }
  }
  pwVar1 = L"NULL";
LAB_14000e0e9:
  pwVar2 = param_8;
  if (param_8 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids,param_2,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,pwVar2,2,pwVar1,wVar3,0);
  return;
}



===== WPP_SF_qdd @ 14000e190 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qdd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,4,&param_6,4,0);
  return;
}



===== Feature_598369595__private_IsEnabledDeviceUsageNoInline @ 14000e1f0 =====

ulonglong Feature_598369595__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_598369595__private_featureState;
  if ((Feature_598369595__private_featureState & 0x10) == 0) {
    uVar1 = Feature_598369595__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_598369595__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_598369595__private_IsEnabledFallback @ 14000e228 =====

void Feature_598369595__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_598369595__private_descriptor);
  return;
}



===== PgmQueryInformation @ 14000e244 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 PgmQueryInformation(longlong param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  undefined4 uVar7;
  undefined1 auStackY_a8 [32];
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  ushort local_5c;
  uint local_5a;
  undefined8 local_56;
  undefined2 local_4e;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_a8;
  iVar1 = *(int *)(param_3 + 8);
  lVar3 = *(longlong *)(*(longlong *)(param_3 + 0x30) + 0x18);
  if (iVar1 == 2) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
              &WPP_95eccc66d59d38e64c76b6c43980f145_Traceguids);
    }
    lVar3 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar3 + -0x10) = QueryProviderCompletion;
    *(undefined8 *)(lVar3 + -8) = 0;
    *(undefined1 *)(lVar3 + -0x45) = 0xe0;
    lVar3 = *(longlong *)(param_2 + 0xb8);
    *(undefined2 *)(lVar3 + -0x48) = 0xc0f;
    *(undefined8 *)(lVar3 + -0x20) = *(undefined8 *)(param_1 + 0x30);
    *(undefined8 *)(lVar3 + -0x18) = *(undefined8 *)(param_1 + 0x38);
    *(undefined4 *)(lVar3 + -0x40) = 2;
    *(undefined8 *)(lVar3 + -0x38) = 0;
    uVar7 = IofCallDriver(*(undefined8 *)(param_1 + 0x30),param_2);
    return uVar7;
  }
  if (iVar1 != 3) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000002;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return 0xc0000002;
    }
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
             &WPP_95eccc66d59d38e64c76b6c43980f145_Traceguids,iVar1);
    return 0xc0000002;
  }
  lVar4 = *(longlong *)(param_2 + 8);
  if (lVar4 == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
               &WPP_95eccc66d59d38e64c76b6c43980f145_Traceguids,param_2);
    }
    return 0xc0000001;
  }
  if (lVar3 != 0) {
    if ((*(int *)(lVar3 + 0x10) + 0xcdbbbbbfU & 0xdfffffff) == 0) {
      local_56 = 0;
      local_68 = 1;
      local_64 = 1;
      local_4e = 0;
      local_60 = 0x2000e;
      uVar2 = *(uint *)(lVar3 + 0x148);
      local_5a = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      local_5c = *(ushort *)(lVar3 + 0x14c) >> 8 | *(ushort *)(lVar3 + 0x14c) << 8;
      uVar7 = TdiCopyBufferToMdl(&local_68,0,0x1a,lVar4);
      *(undefined8 *)(param_2 + 0x38) = 0;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return uVar7;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
        return uVar7;
      }
      WPP_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                 &WPP_95eccc66d59d38e64c76b6c43980f145_Traceguids,lVar3,0,0x1a);
      return uVar7;
    }
    if ((*(int *)(lVar3 + 0x10) + 0xadacbaadU & 0xfeffffff) == 0) {
      lVar5 = *(longlong *)(lVar3 + 0x18);
      if ((lVar5 != 0) && (*(int *)(lVar5 + 0x10) == 0x52444441)) {
        lVar6 = *(longlong *)(param_2 + 0xb8);
        *(longlong *)(param_2 + 8) = lVar4;
        *(code **)(lVar6 + -0x10) = QueryAddressCompletion;
        *(undefined8 *)(lVar6 + -8) = 0;
        *(undefined1 *)(lVar6 + -0x45) = 0xe0;
        lVar4 = *(longlong *)(param_2 + 0xb8);
        *(undefined2 *)(lVar4 + -0x48) = 0xc0f;
        *(undefined8 *)(lVar4 + -0x20) = *(undefined8 *)(lVar5 + 0x50);
        *(undefined8 *)(lVar4 + -0x18) = *(undefined8 *)(lVar5 + 0x48);
        *(undefined4 *)(lVar4 + -0x40) = 3;
        *(undefined8 *)(lVar4 + -0x38) = 0;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
          WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                   &WPP_95eccc66d59d38e64c76b6c43980f145_Traceguids,lVar3);
        }
        IofCallDriver(*(undefined8 *)(param_1 + 0x30),param_2);
        return 0x103;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc0000008;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
        return 0xc0000008;
      }
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                &WPP_95eccc66d59d38e64c76b6c43980f145_Traceguids,lVar3,(char)lVar5);
      return 0xc0000008;
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
             &WPP_95eccc66d59d38e64c76b6c43980f145_Traceguids,lVar3);
  }
  return 0xc0000008;
}



===== QueryAddressCompletion @ 14000e5e0 =====

undefined8 QueryAddressCompletion(undefined8 param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong in_stack_ffffffffffffffe8;
  
  lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x18);
  if (-1 < *(int *)(param_2 + 0x30)) {
    lVar3 = *(longlong *)(param_2 + 8);
    if ((*(byte *)(lVar3 + 10) & 5) == 0) {
      lVar3 = MmMapLockedPagesSpecifyCache
                        (lVar3,0,1,0,in_stack_ffffffffffffffe8 & 0xffffffff00000000,0x40000020);
    }
    else {
      lVar3 = *(longlong *)(lVar3 + 0x18);
    }
    if (lVar3 != 0) {
      if ((lVar2 != 0) &&
         (((iVar1 = *(int *)(lVar2 + 0x10), iVar1 == 0x30534553 || (iVar1 == 0x53534553)) ||
          (iVar1 == 0x52534553)))) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
          WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                    &WPP_95eccc66d59d38e64c76b6c43980f145_Traceguids,*(undefined4 *)(lVar3 + 0xe),
                    (char)*(undefined2 *)(lVar3 + 0xc));
        }
        *(undefined4 *)(lVar2 + 0x38) = *(undefined4 *)(lVar3 + 0xe);
        *(undefined2 *)(lVar2 + 0x3c) = *(undefined2 *)(lVar3 + 0xc);
        return 0;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
        return 0;
      }
      WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_95eccc66d59d38e64c76b6c43980f145_Traceguids,lVar2);
      return 0;
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
              &WPP_95eccc66d59d38e64c76b6c43980f145_Traceguids,*(undefined4 *)(param_2 + 0x30),0);
  }
  return 0;
}



===== QueryProviderCompletion @ 14000e740 =====

undefined8 QueryProviderCompletion(undefined8 param_1,longlong param_2)

{
  byte *pbVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined8 uVar4;
  int iVar5;
  ulonglong in_stack_ffffffffffffffe8;
  
  uVar2 = Feature_598369595__private_IsEnabledDeviceUsageNoInline();
  iVar5 = *(int *)(param_2 + 0x30);
  if ((int)uVar2 == 0) {
LAB_14000e78a:
    if (-1 < iVar5) {
LAB_14000e792:
      lVar3 = *(longlong *)(param_2 + 8);
      if ((*(byte *)(lVar3 + 10) & 5) == 0) {
        lVar3 = MmMapLockedPagesSpecifyCache
                          (lVar3,0,1,0,in_stack_ffffffffffffffe8 & 0xffffffff00000000,0x40000020);
      }
      else {
        lVar3 = *(longlong *)(lVar3 + 0x18);
      }
      if (lVar3 != 0) {
        *(undefined4 *)(lVar3 + 0x10) = 0x12c49;
        *(undefined4 *)(lVar3 + 4) = 0x7fffffff;
        *(undefined4 *)(lVar3 + 0x14) = 1;
        iVar5 = *(uint *)(lVar3 + 0xc) - 0x44;
        if (*(uint *)(lVar3 + 0xc) < 0x45) {
          iVar5 = 0;
        }
        *(int *)(lVar3 + 0xc) = iVar5;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
          WPP_SF_dDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                     &WPP_95eccc66d59d38e64c76b6c43980f145_Traceguids,0x12c49,0xff,(char)iVar5);
        }
        goto LAB_14000e86b;
      }
    }
  }
  else if (iVar5 != 0xfe) {
    if (iVar5 != 0xff) {
      if ((ulonglong)(longlong)iVar5 < 0x25) {
        iVar5 = *(int *)(&`TdiStatusToNtStatus'::__l2::TdiStatusMap + (longlong)iVar5 * 4);
      }
      goto LAB_14000e78a;
    }
    goto LAB_14000e792;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
              &WPP_95eccc66d59d38e64c76b6c43980f145_Traceguids,*(undefined4 *)(param_2 + 0x30),0);
  }
LAB_14000e86b:
  if (*(char *)(param_2 + 0x41) == '\0') {
    uVar4 = 0xc0000016;
  }
  else {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    uVar4 = 0x103;
  }
  return uVar4;
}



===== AdjustNcfRDataResponseTimes @ 14000e8a0 =====

void AdjustNcfRDataResponseTimes(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  uVar4 = DAT_140036750 - *(longlong *)(param_2 + 0x28);
  plVar1 = (longlong *)(*(longlong *)(param_1 + 0x30) + 0x328);
  *plVar1 = *plVar1 + uVar4;
  plVar1 = (longlong *)(*(longlong *)(param_1 + 0x30) + 0x330);
  *plVar1 = *plVar1 + 1;
  lVar2 = *(longlong *)(param_1 + 0x30);
  if (((*(longlong *)(lVar2 + 0x330) != 0) && (*(ulonglong *)(lVar2 + 0x58) < uVar4)) &&
     (uVar3 = *(ulonglong *)(lVar2 + 0x338), *(ulonglong *)(lVar2 + 0x58) != uVar3)) {
    if ((uVar3 == 0) || (uVar4 <= uVar3)) {
      uVar3 = uVar4;
    }
    *(ulonglong *)(lVar2 + 0x58) = uVar3;
    lVar2 = *(longlong *)(param_1 + 0x30);
    *(ulonglong *)(lVar2 + 800) = *(ulonglong *)(lVar2 + 0x328) / *(ulonglong *)(lVar2 + 0x330);
    lVar2 = *(longlong *)(param_1 + 0x30);
    uVar4 = *(longlong *)(lVar2 + 800) * 2;
    uVar3 = (ulonglong)(*(longlong *)(lVar2 + 0x58) + *(longlong *)(lVar2 + 800)) >> 1;
    if (uVar3 <= uVar4) {
      uVar4 = uVar3;
    }
    if (*(ulonglong *)(lVar2 + 0x50) < uVar4) {
      *(ulonglong *)(lVar2 + 0x50) = uVar4;
    }
  }
  return;
}



===== AdjustReceiveBufferLists @ 14000e944 =====

ulonglong AdjustReceiveBufferLists(longlong param_1)

{
  longlong *plVar1;
  int *piVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined8 uVar5;
  longlong lVar6;
  ulonglong uVar7;
  byte bVar8;
  ulonglong uVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  byte *pbVar13;
  uint uVar14;
  int iVar15;
  
  uVar14 = 0;
  iVar15 = 0;
  plVar1 = (longlong *)(*(longlong *)(param_1 + 0x30) + 0x78);
  if ((longlong *)*plVar1 == plVar1) {
    *(undefined8 *)(*(longlong *)(param_1 + 0x30) + 0x70) = DAT_140036750;
  }
  *(uint *)(*(longlong *)(param_1 + 0x30) + 0x38) =
       (uint)*(byte *)(param_1 + 0xa0) + *(int *)(*(longlong *)(param_1 + 0x30) + 0x3c);
  do {
    plVar1 = (longlong *)(*(longlong *)(param_1 + 0x30) + 0x88);
    plVar3 = (longlong *)*plVar1;
    if (plVar3 == plVar1) {
LAB_14000ebae:
      piVar2 = (int *)(*(longlong *)(param_1 + 0x30) + 0x110);
      *piVar2 = *piVar2 + uVar14;
      piVar2 = (int *)(*(longlong *)(param_1 + 0x30) + 0x108);
      *piVar2 = *piVar2 + iVar15;
      piVar2 = (int *)(*(longlong *)(param_1 + 0x30) + 0x10c);
      *piVar2 = *piVar2 - iVar15;
      return (ulonglong)uVar14;
    }
    bVar11 = *(byte *)((longlong)plVar3 + 0x3b);
    pbVar13 = (byte *)((longlong)plVar3 + 0x3f);
    bVar10 = *(byte *)((longlong)plVar3 + 0x3a);
    bVar8 = *(byte *)((longlong)plVar3 + 0x39);
    if (((uint)bVar10 + (uint)bVar11 < (uint)bVar8) && ((uint)*pbVar13 + (uint)bVar10 < (uint)bVar8)
       ) {
      *(undefined4 *)(*(longlong *)(param_1 + 0x30) + 0x38) = *(undefined4 *)(plVar3 + 2);
      goto LAB_14000ebae;
    }
    if (((*pbVar13 != 0) && (bVar11 != 0)) && ((uint)bVar8 <= (uint)*pbVar13 + (uint)bVar10)) {
      bVar10 = bVar10 + bVar11;
      bVar11 = bVar10;
      while ((bVar10 != 0 && (bVar8 = *(byte *)((longlong)plVar3 + 0x3b), bVar8 != 0))) {
        bVar10 = bVar10 - 1;
        uVar7 = (ulonglong)bVar10;
        if (*(byte *)((longlong)plVar3 + 0x3e) <= *(byte *)((longlong)plVar3 + uVar7 * 0x28 + 0x74))
        {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
            WPP_SF_ddddd(*(undefined **)((longlong)WPP_GLOBAL_Control + 0x18),0x27,(ulonglong)bVar8,
                         (uint)bVar10,*pbVar13,*(undefined1 *)((longlong)plVar3 + 0x3a),bVar8,
                         *(undefined1 *)((longlong)plVar3 + 0x39));
          }
          FreeDataBuffer(param_1,plVar3 + uVar7 * 5 + 0xc);
          uVar9 = (ulonglong)bVar11;
          if ((uint)bVar10 != bVar11 - 1) {
            uVar5 = (plVar3 + uVar9 * 5 + 7)[1];
            plVar3[uVar7 * 5 + 0xc] = plVar3[uVar9 * 5 + 7];
            plVar3[uVar7 * 5 + 0xd] = uVar5;
            uVar5 = (plVar3 + uVar9 * 5 + 9)[1];
            plVar3[uVar7 * 5 + 0xe] = plVar3[uVar9 * 5 + 9];
            plVar3[uVar7 * 5 + 0xf] = uVar5;
            plVar3[uVar7 * 5 + 0x10] = plVar3[uVar9 * 5 + 0xb];
          }
          lVar6 = uVar9 - 1;
          bVar11 = bVar11 - 1;
          plVar3[lVar6 * 5 + 0xc] = 0;
          (plVar3 + lVar6 * 5 + 0xc)[1] = 0;
          plVar3[lVar6 * 5 + 0xe] = 0;
          (plVar3 + lVar6 * 5 + 0xe)[1] = 0;
          plVar3[lVar6 * 5 + 0x10] = 0;
          *(char *)((longlong)plVar3 + 0x3b) = *(char *)((longlong)plVar3 + 0x3b) + -1;
          piVar2 = (int *)(*(longlong *)(param_1 + 0x30) + 0x10c);
          *piVar2 = *piVar2 + -1;
          piVar2 = (int *)(*(longlong *)(param_1 + 0x30) + 0x104);
          *piVar2 = *piVar2 + -1;
        }
      }
      bVar10 = *(byte *)((longlong)plVar3 + 0x3e);
      uVar7 = 0;
      bVar8 = 0;
      if (bVar10 != 0) {
        do {
          bVar12 = (char)uVar7 + 1;
          *(byte *)((longlong)plVar3 + uVar7 * 0x28 + 0x75) = bVar10;
          bVar10 = *(byte *)((longlong)plVar3 + 0x3e);
          uVar7 = (ulonglong)bVar12;
          bVar8 = bVar10;
        } while (bVar12 < bVar10);
      }
      bVar10 = 0;
      if (bVar11 != 0) {
        pbVar13 = (byte *)((longlong)plVar3 + 0x74);
        do {
          if (*pbVar13 < bVar8) {
            *(byte *)((longlong)plVar3 + (ulonglong)*pbVar13 * 0x28 + 0x75) = bVar10;
            bVar8 = *(byte *)((longlong)plVar3 + 0x3e);
          }
          bVar10 = bVar10 + 1;
          pbVar13 = pbVar13 + 0x28;
        } while (bVar10 < bVar11);
      }
    }
    lVar6 = *plVar3;
    if (((longlong *)*(longlong *)(lVar6 + 8) != plVar3) ||
       (plVar1 = (longlong *)plVar3[1], (longlong *)*plVar1 != plVar3)) {
LAB_14000ebf1:
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      uVar7 = (*pcVar4)();
      return uVar7;
    }
    *plVar1 = lVar6;
    *(longlong **)(lVar6 + 8) = plVar1;
    lVar6 = *(longlong *)(param_1 + 0x30);
    plVar1 = *(longlong **)(lVar6 + 0x80);
    if (*plVar1 != lVar6 + 0x78) goto LAB_14000ebf1;
    *plVar3 = lVar6 + 0x78;
    uVar14 = uVar14 + 1;
    plVar3[1] = (longlong)plVar1;
    *plVar1 = (longlong)plVar3;
    *(longlong **)(lVar6 + 0x80) = plVar3;
    iVar15 = iVar15 + (uint)*(byte *)((longlong)plVar3 + 0x3a) +
             (uint)*(byte *)((longlong)plVar3 + 0x3b);
  } while( true );
}



===== AllocateDataBuffer @ 14000ec00 =====

longlong AllocateDataBuffer(longlong param_1,longlong *param_2,uint param_3)

{
  int *piVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 0x30);
  if ((*(uint *)(lVar2 + 0x118) < param_3) && (*(int *)(lVar2 + 0x11c) == 0)) {
    if (*(uint *)(lVar2 + 0x114) < param_3) {
      *(uint *)(lVar2 + 0x114) = param_3;
    }
    piVar1 = (int *)(*(longlong *)(param_1 + 0x30) + 0x114);
    *piVar1 = *piVar1 + 100;
    *(undefined4 *)(*(longlong *)(param_1 + 0x30) + 0x118) =
         *(undefined4 *)(*(longlong *)(param_1 + 0x30) + 0x114);
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x8000;
    ExDeleteNPagedLookasideList(*(longlong *)(param_1 + 0x30) + 0x140);
    lVar2 = *(longlong *)(param_1 + 0x30);
    ExInitializeNPagedLookasideList
              (lVar2 + 0x140,0,0,0x200,*(undefined4 *)(lVar2 + 0x118),0x446d6750,
               *(undefined2 *)(lVar2 + 0x120));
  }
  if (((*(uint *)(param_1 + 0x20) >> 0xf & 1) == 0) ||
     (*(uint *)(*(longlong *)(param_1 + 0x30) + 0x118) < param_3)) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffff7fff;
    lVar2 = ExAllocatePool2(0x40,param_3,0x446d6750);
    *param_2 = lVar2;
    if (*(uint *)(*(longlong *)(param_1 + 0x30) + 0x114) < param_3) {
      *(uint *)(*(longlong *)(param_1 + 0x30) + 0x114) = param_3;
    }
  }
  else {
    lVar2 = ExAllocateFromNPagedLookasideList(*(longlong *)(param_1 + 0x30) + 0x140);
    *param_2 = lVar2;
    if (lVar2 != 0) {
      piVar1 = (int *)(*(longlong *)(param_1 + 0x30) + 0x11c);
      *piVar1 = *piVar1 + 1;
      *(uint *)((longlong)param_2 + 0x24) = *(uint *)((longlong)param_2 + 0x24) | 1;
    }
  }
  return *param_2;
}



===== CheckAndAddNakRequests @ 14000ed4c =====

undefined8
CheckAndAddNakRequests(longlong param_1,uint *param_2,undefined8 *param_3,int param_4,char param_5)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 uVar3;
  code *pcVar4;
  uint uVar5;
  uint uVar6;
  longlong lVar7;
  longlong *_Dst;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  longlong lVar11;
  byte bVar12;
  int iVar13;
  undefined1 *puVar14;
  byte bVar15;
  ulonglong uVar16;
  uint uVar17;
  int iVar18;
  undefined1 auStackY_98 [8];
  undefined1 auStackY_90 [24];
  
  uVar10 = *param_2;
  uVar5 = *(byte *)(param_1 + 0xa0) - 1;
  lVar1 = *(longlong *)(param_1 + 0x30);
  uVar17 = ~uVar5 & uVar10;
  lVar7 = DAT_140036750 + 2;
  iVar18 = *(int *)(lVar1 + 0x3c);
  if ((int)(uVar10 - *(int *)(lVar1 + 0x38)) < 0) {
    if (param_3 == (undefined8 *)0x0) {
      return 0;
    }
    *param_3 = 0;
    return 0;
  }
  iVar13 = uVar17 - *(int *)(lVar1 + 0x34);
  if (0 < iVar13 + -5000) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,
                 &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,*(int *)(lVar1 + 0x34),
                 (char)uVar17,(char)iVar13 + '\x01');
    }
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x100;
    return 0xc000009a;
  }
  if ((((0 < (int)((uVar17 - iVar18) + -1000)) && ((*(uint *)(param_1 + 0x20) & 8) == 0)) &&
      ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_dddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x47,
                &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,uVar17 - iVar18,
                (char)*(int *)(lVar1 + 0x38),(char)iVar18,(char)uVar17);
  }
  uVar8 = *(uint *)(*(longlong *)(lVar1 + 0x18) + 0x38) & 0x10;
  uVar6 = (-(uint)(uVar8 != 0) & 0xfffffd44) + 0x2ee;
  uVar8 = GetRandomInteger((-(uint)(uVar8 != 0) & 0xffffffd0) + 0x32,
                           (-(uint)(uVar8 != 0) & 0xffffffb0) + 100);
  puVar14 = auStackY_98;
  _Dst = (longlong *)0x0;
  while ((int)(iVar18 - uVar17) < 0) {
    lVar11 = lVar1 + 0x240;
    if (*(char *)(param_1 + 0xa1) == '\0') {
      lVar11 = lVar1 + 0x1c0;
    }
    _Dst = (longlong *)ExAllocateFromNPagedLookasideList(lVar11);
    if (_Dst == (longlong *)0x0) goto LAB_14000f053;
    memset(_Dst,0,(ulonglong)(uVar5 * 0x28 + 0x88));
    if (*(char *)(param_1 + 0xa1) == '\0') {
      *(undefined1 *)((longlong)_Dst + 0x39) = 1;
      *(undefined1 *)((longlong)_Dst + 0x3e) = 1;
      *(undefined1 *)((longlong)_Dst + 0x75) = 1;
    }
    else {
      bVar12 = *(byte *)(param_1 + 0xa0);
      *(byte *)((longlong)_Dst + 0x39) = bVar12;
      *(byte *)((longlong)_Dst + 0x3e) = bVar12;
      uVar16 = 0;
      if (bVar12 != 0) {
        do {
          bVar15 = (char)uVar16 + 1;
          *(byte *)((longlong)_Dst + uVar16 * 0x28 + 0x75) = bVar12;
          bVar12 = *(byte *)((longlong)_Dst + 0x3e);
          uVar16 = (ulonglong)bVar15;
        } while (bVar15 < bVar12);
      }
    }
    iVar18 = iVar18 + (uint)*(byte *)(param_1 + 0xa0);
    *(int *)(_Dst + 2) = iVar18;
    *(undefined2 *)((longlong)_Dst + 0x36) = *(undefined2 *)(param_1 + 0x9a);
    if (param_4 == 3) {
      lVar11 = *(longlong *)(lVar1 + 0x50) + DAT_140036750;
      _Dst[3] = 0;
      _Dst[4] = lVar11;
      *(undefined1 *)(_Dst + 7) = 0;
    }
    else {
      _Dst[4] = 0;
      if (param_4 == 0) {
        lVar11 = lVar7;
      }
      else {
        if (param_4 == 1) {
          uVar9 = uVar8 / *(byte *)(param_1 + 0xa0);
        }
        else {
          if (param_4 != 2) goto LAB_14000efe5;
          uVar9 = uVar8 / *(byte *)(param_1 + 0xa0) + uVar6;
        }
        lVar11 = (ulonglong)uVar9 / 0x14 + DAT_140036750;
      }
      _Dst[3] = lVar11;
    }
LAB_14000efe5:
    plVar2 = *(longlong **)(lVar1 + 0x90);
    if (*plVar2 != lVar1 + 0x88) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      puVar14 = auStackY_90;
LAB_14000f053:
      *(int *)(lVar1 + 0x40) = *(int *)(lVar1 + 0x40) + *(int *)(puVar14 + 0x40);
      *(int *)(lVar1 + 0x3c) = iVar18;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc000009a;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
        return 0xc000009a;
      }
      uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      *(int *)(puVar14 + 0x20) = iVar18;
      *(undefined8 *)(puVar14 + -8) = 0x14000f09b;
      WPP_SF_dD(uVar3,0x48,&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,
                *(undefined4 *)(puVar14 + 0xa8),puVar14[0x20]);
      return 0xc000009a;
    }
    _Dst[1] = (longlong)plVar2;
    *_Dst = lVar1 + 0x88;
    *plVar2 = (longlong)_Dst;
    *(longlong **)(lVar1 + 0x90) = _Dst;
    AppendPendingReceiverEntry(lVar1,(longlong)_Dst);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x49,
                &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,(int)_Dst[2],(char)iVar18);
    }
  }
  *(int *)(lVar1 + 0x3c) = iVar18;
  if (0 < (int)(uVar10 - *(int *)(lVar1 + 0x40))) {
    if (param_5 == '\0') {
      if (iVar18 - *(int *)(lVar1 + 0x40) < 1) goto LAB_14000f0d0;
      uVar10 = uVar5 + iVar18;
    }
    *(uint *)(lVar1 + 0x40) = uVar10;
  }
LAB_14000f0d0:
  if (_Dst == (longlong *)0x0) {
    if (param_3 == (undefined8 *)0x0) {
      return 0;
    }
    if (*(longlong **)(lVar1 + 0x88) != (longlong *)(lVar1 + 0x88)) {
      _Dst = (longlong *)FindReceiverEntry(lVar1,uVar17);
    }
  }
  else {
    _Dst[3] = (ulonglong)uVar6 / 0x14 + DAT_140036750;
    if (param_3 == (undefined8 *)0x0) {
      return 0;
    }
  }
  *param_3 = _Dst;
  return 0;
}



===== CheckDeferredCleanup @ 14000f130 =====

void CheckDeferredCleanup(longlong param_1)

{
  if ((*(uint *)(param_1 + 0x20) & 0x10400) == 0x10000) {
    CleanupPendingNaks(param_1,0,1);
  }
  return;
}



===== CheckForSessionTimeout @ 14000f15c =====

void CheckForSessionTimeout(longlong param_1,longlong param_2)

{
  uint uVar1;
  
  uVar1 = (int)DAT_140036750 - *(int *)(param_2 + 0x2e0);
  if ((*(uint *)(pPgmRegistryConfig + 0x18) / 0x14 < uVar1) &&
     ((uint)(*(int *)(param_2 + 0x2c4) * 0x20) < uVar1)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,
               &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,uVar1 * 0x14);
    }
  }
  else {
    uVar1 = (int)DAT_140036750 - *(int *)(param_2 + 0x70);
    if (*(longlong **)(param_2 + 0x78) == (longlong *)(param_2 + 0x78)) {
      return;
    }
    if (uVar1 < 0x3a99) {
      return;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,
               &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,(ulonglong)(uVar1 * 0x14));
    }
  }
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x100;
  return;
}



===== CheckIndicateDisconnect @ 14000f238 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

byte CheckIndicateDisconnect
               (longlong param_1,longlong param_2,undefined1 *param_3,undefined1 *param_4,
               char param_5)

{
  uint uVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong ***ppplVar4;
  longlong ***ppplVar5;
  undefined8 uVar6;
  longlong lVar7;
  code *pcVar8;
  longlong ****pppplVar9;
  undefined1 uVar10;
  undefined8 uVar11;
  char *pcVar12;
  byte bVar13;
  undefined1 *puVar14;
  int iVar15;
  longlong lVar16;
  undefined8 uVar17;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [56];
  longlong ****local_38;
  longlong ****local_30;
  
  uVar1 = *(uint *)(param_2 + 0x20);
  bVar13 = (byte)(uVar1 >> 0xd) & 1;
  if ((uVar1 & 0x2400) == 0) {
    lVar2 = *(longlong *)(param_2 + 0x30);
    plVar3 = *(longlong **)(lVar2 + 0x88);
    if (plVar3 == (longlong *)(lVar2 + 0x88)) {
      iVar15 = *(int *)(lVar2 + 0x38);
    }
    else {
      iVar15 = (uint)*(byte *)((longlong)plVar3 + 0x3f) + *(int *)(plVar3 + 2);
    }
    if (((uVar1 & 0x100) != 0) ||
       ((((char)uVar1 < '\0' && (*(longlong **)(lVar2 + 0x78) == (longlong *)(lVar2 + 0x78))) &&
        (-1 < (iVar15 - *(int *)(lVar2 + 0x44)) + -1)))) {
      *(uint *)(param_2 + 0x20) = uVar1 | 0x2400;
      local_30 = (longlong ****)&local_38;
      local_38 = (longlong ****)&local_38;
      RemovePendingIrps(param_2,(longlong)&local_38);
      *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + 1;
      lVar2 = param_2 + 0x168;
      KeReleaseSpinLock(lVar2,*param_4);
      if (param_5 != '\0') {
        KeReleaseSpinLock(param_1 + 0x1b8,*param_3);
      }
      while( true ) {
        pppplVar9 = local_38;
        puVar14 = auStack_78;
        if ((longlong *****)local_38 == &local_38) break;
        PgmCancelCancelRoutine((longlong)(local_38 + -0x15));
        ppplVar4 = *pppplVar9;
        if (((longlong ****)ppplVar4[1] != pppplVar9) ||
           (ppplVar5 = pppplVar9[1], (longlong ****)*ppplVar5 != pppplVar9)) {
          pcVar8 = (code *)swi(0x29);
          (*pcVar8)(3);
          puVar14 = auStack_70;
          break;
        }
        *ppplVar5 = (longlong **)ppplVar4;
        ppplVar4[1] = (longlong **)ppplVar5;
        *(undefined4 *)(pppplVar9 + -0xf) = 0xc0000120;
        IofCompleteRequest(pppplVar9 + -0x15,CONCAT71((int7)((ulonglong)ppplVar4 >> 8),2));
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        uVar11 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        pcVar12 = "TDI_DISCONNECT_RELEASE";
        if ((uVar1 & 0x100) != 0) {
          pcVar12 = "TDI_DISCONNECT_ABORT";
        }
        *(undefined4 *)(puVar14 + 0x38) = *(undefined4 *)(*(longlong *)(param_2 + 0x30) + 0x34);
        uVar6 = *(undefined8 *)(param_2 + 0x50);
        *(int *)(puVar14 + 0x30) = iVar15;
        *(char **)(puVar14 + 0x28) = pcVar12;
        *(undefined8 *)(puVar14 + 0x20) = uVar6;
        *(undefined8 *)(puVar14 + -8) = 0x14000f3f6;
        WPP_SF_qqsdd(uVar11,pcVar12,"TDI_DISCONNECT_ABORT",param_2,puVar14[0x20],
                     *(char **)(puVar14 + 0x28),puVar14[0x30],puVar14[0x38]);
      }
      lVar16 = *(longlong *)(puVar14 + 0x80);
      uVar17 = 0;
      uVar11 = *(undefined8 *)(param_2 + 0x50);
      *(undefined4 *)(puVar14 + 0x30) = *(undefined4 *)(puVar14 + 0x88);
      pcVar8 = *(code **)(lVar16 + 0x90);
      uVar6 = *(undefined8 *)(lVar16 + 0x98);
      *(undefined8 *)(puVar14 + 0x28) = 0;
      *(undefined4 *)(puVar14 + 0x20) = 0;
      *(undefined8 *)(puVar14 + -8) = 0x14000f431;
      (*pcVar8)(uVar6,uVar11,0);
      puVar14[0x20] = 0;
      bVar13 = 1;
      *(undefined8 *)(puVar14 + -8) = 0x14000f44b;
      uVar11 = PgmQueueForDelayedExecution(CleanupPendingNaks,param_2,1,uVar17,puVar14[0x20]);
      if ((int)uVar11 != 0) {
        *(undefined8 *)(puVar14 + -8) = 0x14000f45d;
        CleanupPendingNaks(param_2,1,0);
      }
      lVar16 = lVar16 + 0x1b8;
      if (puVar14[0xa0] != '\0') {
        *(undefined8 *)(puVar14 + -8) = 0x14000f478;
        uVar10 = KeAcquireSpinLockRaiseToDpc(lVar16);
        *param_3 = uVar10;
      }
      *(undefined8 *)(puVar14 + -8) = 0x14000f48a;
      uVar10 = KeAcquireSpinLockRaiseToDpc(lVar2);
      *param_4 = uVar10;
      *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) & 0xfffffbff;
      *(undefined8 *)(puVar14 + -8) = 0x14000f4a0;
      CheckDeferredCleanup(param_2);
      lVar7 = *(longlong *)(param_2 + 0x68);
      if (lVar7 != 0) {
        *(undefined8 *)(param_2 + 0x68) = 0;
        *(undefined8 *)(puVar14 + -8) = 0x14000f4bc;
        KeReleaseSpinLock(lVar2);
        if (puVar14[0xa0] != '\0') {
          *(undefined8 *)(puVar14 + -8) = 0x14000f4d8;
          KeReleaseSpinLock(lVar16);
        }
        *(undefined8 *)(puVar14 + -8) = 0x14000f4ea;
        PgmIoComplete(lVar7,0,0);
        if (puVar14[0xa0] != '\0') {
          *(undefined8 *)(puVar14 + -8) = 0x14000f4fe;
          uVar10 = KeAcquireSpinLockRaiseToDpc(lVar16);
          *param_3 = uVar10;
        }
        *(undefined8 *)(puVar14 + -8) = 0x14000f510;
        uVar10 = KeAcquireSpinLockRaiseToDpc(lVar2);
        *param_4 = uVar10;
      }
    }
  }
  return bVar13;
}



===== CheckIndicatePendedData @ 14000f53c =====

undefined8
CheckIndicatePendedData(longlong param_1,longlong param_2,undefined1 *param_3,undefined1 *param_4)

{
  byte bVar1;
  byte bVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined8 uVar7;
  code *pcVar8;
  int iVar9;
  ulonglong uVar10;
  int iVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  uint uVar14;
  undefined1 auStackY_58 [8];
  undefined1 auStackY_50 [24];
  
  puVar12 = auStackY_58;
  iVar9 = 0;
  lVar3 = *(longlong *)(param_2 + 0x30);
  if ((*(uint *)(param_2 + 0x20) & 0xc00) == 0) {
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) | 0x400;
    while (plVar4 = *(longlong **)(lVar3 + 0x78), puVar13 = auStackY_58,
          plVar4 != (longlong *)(lVar3 + 0x78)) {
      if (*(byte *)((longlong)plVar4 + 0x3b) != 0) {
        if ((uint)*(byte *)((longlong)plVar4 + 0x3b) + (uint)*(byte *)((longlong)plVar4 + 0x3a) ==
            (uint)*(byte *)((longlong)plVar4 + 0x39)) {
          uVar10 = DecodeParityPackets(param_2,(longlong)plVar4);
          iVar9 = (int)uVar10;
          if (-1 < iVar9) goto LAB_14000f5c4;
          puVar12 = auStackY_58;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (puVar12 = auStackY_58, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6a,
                     &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,iVar9);
            puVar12 = auStackY_58;
          }
LAB_14000f670:
          *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) | 0x100;
          puVar13 = puVar12;
        }
        else {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x69,
                    &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids);
          }
          *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) | 0x100;
          puVar13 = auStackY_58;
        }
        break;
      }
LAB_14000f5c4:
      iVar9 = PgmIndicateGroup(param_1,param_2,param_3,param_4,(longlong)plVar4);
      iVar11 = iVar9;
      if (iVar9 < 0) {
LAB_14000f734:
        puVar13 = puVar12;
        if (iVar11 != -0x3ffffde5) goto LAB_14000f670;
        break;
      }
      *(int *)(lVar3 + 0x34) = *(int *)(lVar3 + 0x34) + (uint)*(byte *)((longlong)plVar4 + 0x3e);
      bVar1 = *(byte *)((longlong)plVar4 + 0x3b);
      bVar2 = *(byte *)((longlong)plVar4 + 0x3a);
      *(int *)(lVar3 + 0x110) = *(int *)(lVar3 + 0x110) + -1;
      iVar11 = (uint)bVar1 + (uint)bVar2;
      *(int *)(lVar3 + 0x104) = *(int *)(lVar3 + 0x104) - iVar11;
      *(int *)(lVar3 + 0x108) = *(int *)(lVar3 + 0x108) - iVar11;
      lVar5 = *plVar4;
      if (((longlong *)*(longlong *)(lVar5 + 8) != plVar4) ||
         (plVar6 = (longlong *)plVar4[1], (longlong *)*plVar6 != plVar4)) {
        pcVar8 = (code *)swi(0x29);
        iVar11 = (*pcVar8)(3);
        puVar12 = auStackY_50;
        goto LAB_14000f734;
      }
      *plVar6 = lVar5;
      *(longlong **)(lVar5 + 8) = plVar6;
      FreeNakContext(param_2,(longlong)plVar4);
    }
    uVar14 = *(uint *)(param_2 + 0x20) & 0xfffffbff;
    *(uint *)(param_2 + 0x20) = uVar14;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      uVar7 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      *(uint *)(puVar13 + 0x28) = uVar14;
      *(longlong *)(puVar13 + 0x20) = param_2;
      *(undefined8 *)(puVar13 + -8) = 0x14000f6ed;
      WPP_SF_DqD(uVar7,0x6b,&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,iVar9,puVar13[0x20],
                 puVar13[0x28]);
    }
    *(undefined8 *)(puVar13 + -8) = 0x14000f6f5;
    CheckDeferredCleanup(param_2);
    puVar13[0x20] = 1;
    *(undefined8 *)(puVar13 + -8) = 0x14000f70d;
    CheckIndicateDisconnect(*(longlong *)(puVar13 + 0x60),param_2,param_3,param_4,puVar13[0x20]);
  }
  return 0;
}



===== CheckSendPendingNaks @ 14000f754 =====

/* WARNING: Type propagation algorithm not settling */

void CheckSendPendingNaks(longlong param_1,longlong param_2,longlong param_3,undefined1 *param_4)

{
  ushort uVar1;
  longlong ******pppppplVar2;
  longlong ******pppppplVar3;
  undefined8 uVar4;
  code *pcVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  char cVar10;
  undefined1 uVar11;
  undefined1 uVar12;
  longlong *******ppppppplVar13;
  longlong *******ppppppplVar14;
  ulonglong uVar15;
  char cVar16;
  byte bVar17;
  undefined2 uVar18;
  longlong lVar19;
  undefined1 *puVar20;
  uint uVar21;
  int iVar22;
  char *pcVar23;
  int iVar24;
  byte bVar25;
  longlong *plVar26;
  undefined1 auStackY_b8 [8];
  undefined1 auStackY_b0 [24];
  longlong *******local_60;
  longlong *******local_58;
  int local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  int local_3c;
  
  local_48 = 0;
  local_44 = 0;
  uVar21 = 2;
  bVar25 = 2;
  if ((*(int *)(param_3 + 0x24) == 0) ||
     ((*(uint *)(param_3 + 0x10c) < 3 &&
      (DAT_140036750 <
       (*(ulonglong *)(*(longlong *)(param_2 + 0x30) + 0x60) >> 2) + *(longlong *)(param_3 + 0x68)))
     )) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
      lVar19 = *(longlong *)(param_3 + 0x68) + 2;
      WPP_SF_qDdii(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar19,param_3,param_2,
                   (char)*(int *)(param_3 + 0x24),(char)*(undefined4 *)(param_3 + 0x10c),
                   (char)lVar19,(char)DAT_140036750);
    }
  }
  else {
    local_58 = (longlong *******)&local_60;
    local_60 = (longlong *******)&local_60;
    ppppppplVar13 = (longlong *******)ExAllocatePool2(0x40,0x110,0x356d6750);
    puVar20 = auStackY_b8;
    if (ppppppplVar13 != (longlong *******)0x0) {
      ppppppplVar14 = (longlong *******)ExAllocatePool2(0x40,0x110,0x366d6750);
      puVar20 = auStackY_b8;
      if (ppppppplVar14 != (longlong *******)0x0) {
        *(undefined2 *)((longlong)ppppppplVar14 + 0x10e) = 2;
        *(undefined2 *)((longlong)ppppppplVar13 + 0x10e) = 1;
        if ((longlong ********)*local_58 == &local_60) {
          ppppppplVar14[1] = (longlong ******)local_58;
          *ppppppplVar14 = (longlong ******)&local_60;
          *local_58 = (longlong ******)ppppppplVar14;
          local_58 = ppppppplVar14;
          if ((longlong ********)*ppppppplVar14 == &local_60) {
            ppppppplVar13[1] = (longlong ******)ppppppplVar14;
            *ppppppplVar13 = (longlong ******)&local_60;
            *ppppppplVar14 = (longlong ******)ppppppplVar13;
            local_58 = ppppppplVar13;
            uVar11 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x1b8);
            uVar12 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x168);
            AdjustReceiveBufferLists(param_2);
            uVar21 = *(uint *)(param_1 + 0x38) & 0x10;
            local_3c = (-(uint)(uVar21 != 0) & 0xfffffd44) + 0x2ee;
            local_4c = GetRandomInteger((-(uint)(uVar21 != 0) & 0xffffffd0) + 0x32,
                                        (-(uint)(uVar21 != 0) & 0xffffffb0) + 100);
            bVar9 = false;
            bVar6 = false;
            bVar8 = false;
            bVar7 = false;
            plVar26 = (longlong *)(param_3 + 0xb8);
            do {
              plVar26 = (longlong *)*plVar26;
              if (plVar26 == (longlong *)(*(longlong *)(param_2 + 0x30) + 0xb8)) break;
              bVar25 = *(byte *)((longlong)plVar26 + -0x17);
              iVar24 = *(int *)(plVar26 + -8);
              uVar21 = ((uint)bVar25 - (uint)*(byte *)((longlong)plVar26 + -0x15)) -
                       (uint)*(byte *)((longlong)plVar26 + -0x16);
              if (0 < *(int *)(param_3 + 0x30) - iVar24) {
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
                  WPP_SF_dDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
                             &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,iVar24,
                             (char)*(int *)(param_3 + 0x30),
                             *(undefined1 *)((longlong)plVar26 + -0x14));
                }
                *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) | 0x40;
                break;
              }
              iVar22 = 0;
              if (plVar26[-7] == 0) {
                if ((plVar26[-6] != 0) &&
                   (local_44 = local_44 + uVar21, (ulonglong)plVar26[-6] < DAT_140036750)) {
                  cVar16 = *(char *)((longlong)plVar26 + -0x14);
                  *(char *)((longlong)plVar26 + -0x14) = cVar16 + '\x01';
                  if (cVar16 != '\n') {
                    *(undefined1 *)(plVar26 + -3) = 0;
                    plVar26[-6] = 0;
                    bVar17 = 0;
                    plVar26[-7] = ((ulonglong)local_4c / (ulonglong)uVar21) / 0x14 + DAT_140036750;
                    if (bVar25 == 0) goto LAB_14000fd47;
                    do {
                      uVar15 = (ulonglong)bVar17;
                      bVar17 = bVar17 + 1;
                      *(undefined1 *)((longlong)plVar26 + uVar15 * 0x28 + 0x26) = 0;
                      if (*(byte *)((longlong)plVar26 + -0x17) <= bVar17) goto LAB_14000fd47;
                    } while( true );
                  }
                  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
                    cVar10 = (char)*(undefined4 *)(param_3 + 0x30);
                    cVar16 = (char)*(undefined4 *)(param_3 + 0x3c);
                    WPP_SF_dddddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,0xb,iVar24,cVar10,
                                  cVar16,(cVar16 - cVar10) + '\x01',0xb,
                                  (char)*(undefined4 *)(param_3 + 0x38));
                  }
LAB_14000fe0a:
                  *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) | 0x40;
                  break;
                }
              }
              else {
                local_48 = local_48 + uVar21;
                if ((ulonglong)plVar26[-7] < DAT_140036750) {
                  bVar17 = *(byte *)(plVar26 + -3);
                  cVar16 = bVar17 + 1;
                  *(char *)(plVar26 + -3) = cVar16;
                  if (9 < bVar17) {
                    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
                      uVar21 = (*(int *)(param_3 + 0x3c) - *(int *)(param_3 + 0x30)) + 1;
                      WPP_SF_ddddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,(ulonglong)uVar21
                                   ,iVar24,cVar16,(char)*(int *)(param_3 + 0x30),
                                   (char)*(int *)(param_3 + 0x3c),(char)uVar21);
                    }
                    goto LAB_14000fe0a;
                  }
                  if (((bVar25 < 2) || ((*(byte *)(param_2 + 0xa1) & 1) == 0)) ||
                     ((iVar24 == *(int *)(param_3 + 0x3c) &&
                      ((int)(((*(int *)(param_3 + 0x40) - (uint)*(byte *)(param_2 + 0xa0)) - iVar24)
                            + 1) < 0)))) {
                    local_50 = 0;
                    if (*(char *)(param_2 + 0xa1) == '\0') {
                      *(int *)((longlong)ppppppplVar13 +
                              (ulonglong)*(ushort *)((longlong)ppppppplVar13 + 0x10c) * 4 + 0x10) =
                           iVar24;
                      *(short *)((longlong)ppppppplVar13 + 0x10c) =
                           *(short *)((longlong)ppppppplVar13 + 0x10c) + 1;
                    }
                    else {
                      if (iVar24 == *(int *)(param_3 + 0x3c)) {
                        uVar21 = (*(int *)(param_3 + 0x40) - iVar24) + 1;
                      }
                      else {
                        uVar21 = (uint)bVar25;
                      }
                      uVar15 = (ulonglong)*(byte *)((longlong)plVar26 + -0x11);
                      iVar24 = ((uVar21 - *(byte *)((longlong)plVar26 + -0x15)) -
                               (uint)*(byte *)((longlong)plVar26 + -0x16)) -
                               (uint)*(byte *)((longlong)plVar26 + -0x11);
                      while( true ) {
                        local_40 = (uint)uVar15;
                        if (uVar21 <= (local_40 & 0xff)) break;
                        if (*(byte *)((longlong)plVar26 + -0x12) <=
                            *(byte *)((longlong)plVar26 + (uVar15 & 0xff) * 0x28 + 0x25)) {
                          if (*(char *)((longlong)plVar26 + (uVar15 & 0xff) * 0x28 + 0x26) == '\0')
                          {
                            *(uint *)((longlong)ppppppplVar13 +
                                     (ulonglong)*(ushort *)((longlong)ppppppplVar13 + 0x10c) * 4 +
                                     0x10) = *(int *)(plVar26 + -8) + (local_40 & 0xff);
                            *(short *)((longlong)ppppppplVar13 + 0x10c) =
                                 *(short *)((longlong)ppppppplVar13 + 0x10c) + 1;
                            local_50 = iVar22 + 1;
                            iVar22 = local_50;
                          }
                          if (*(short *)((longlong)ppppppplVar13 + 0x10c) == 0x3f) {
                            ppppppplVar13 = (longlong *******)ExAllocatePool2(0x40,0x110,0x356d6750)
                            ;
                            if (ppppppplVar13 == (longlong *******)0x0) {
                              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
                                WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
                                        &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids);
                              }
                              *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) | 0x100;
                              break;
                            }
                            *(undefined2 *)((longlong)ppppppplVar13 + 0x10e) = 1;
                            if ((longlong ********)*local_58 != &local_60) goto LAB_14000fff2;
                            uVar15 = (ulonglong)local_40;
                            *ppppppplVar13 = (longlong ******)&local_60;
                            ppppppplVar13[1] = (longlong ******)local_58;
                            *local_58 = (longlong ******)ppppppplVar13;
                            local_58 = ppppppplVar13;
                            iVar22 = local_50;
                          }
                          iVar24 = iVar24 + -1;
                          if (iVar24 == 0) break;
                        }
                        uVar15 = CONCAT71((int7)(uVar15 >> 8),(char)uVar15 + '\x01');
                      }
                      bVar9 = bVar8;
                      if (local_50 == 0) {
                        *(char *)(plVar26 + -3) = *(char *)(plVar26 + -3) + -1;
                      }
                    }
                    plVar26[-7] = (ulonglong)(local_4c + local_3c) / 0x14 + DAT_140036750;
                    if (ppppppplVar13 == (longlong *******)0x0) break;
                    if (*(short *)((longlong)ppppppplVar13 + 0x10c) != 0x3f) goto LAB_14000fd47;
                    bVar7 = true;
                    bVar6 = true;
                  }
                  else {
                    *(uint *)((longlong)ppppppplVar14 +
                             (ulonglong)*(ushort *)((longlong)ppppppplVar14 + 0x10c) * 4 + 0x10) =
                         iVar24 + -1 + uVar21;
                    *(short *)((longlong)ppppppplVar14 + 0x10c) =
                         *(short *)((longlong)ppppppplVar14 + 0x10c) + 1;
                    bVar8 = bVar9;
                    if (*(short *)((longlong)ppppppplVar14 + 0x10c) == 0x3f) {
                      bVar8 = true;
                    }
                    plVar26[-7] = (ulonglong)(local_4c / uVar21 + local_3c) / 0x14 + DAT_140036750;
                    bVar6 = bVar7;
                    bVar9 = bVar8;
                  }
                }
              }
LAB_14000fa11:
              uVar21 = 0;
              if (!bVar6) {
                if (bVar9) goto LAB_14000fced;
                goto LAB_14000fda7;
              }
              ppppppplVar13 = (longlong *******)ExAllocatePool2(0x40,0x110,0x356d6750);
              if (ppppppplVar13 != (longlong *******)0x0) {
                *(undefined2 *)((longlong)ppppppplVar13 + 0x10e) = 1;
                if ((longlong ********)*local_58 == &local_60) goto code_r0x00014000fcc8;
                goto LAB_14000fff2;
              }
              bVar6 = bVar7;
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
                uVar18 = 0x35;
LAB_14000fd8b:
                WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar18,
                        &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids);
                bVar6 = bVar7;
              }
LAB_14000fd9b:
              *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) | 0x100;
              bVar7 = bVar6;
              bVar9 = bVar8;
LAB_14000fda7:
            } while ((*(uint *)(param_2 + 0x20) & 0x100) == 0);
            uVar21 = 0;
            *(ulonglong *)(param_3 + 0x370) = (ulonglong)local_48;
            *(ulonglong *)(param_3 + 0x378) = (ulonglong)local_44;
            if ((longlong ********)local_60 != &local_60) {
              *(ulonglong *)(param_3 + 0x68) = DAT_140036750;
            }
            KeReleaseSpinLock(param_2 + 0x168,uVar12);
            KeReleaseSpinLock(param_1 + 0x1b8,uVar11);
            KeReleaseSpinLock(&DAT_140036808,*param_4);
            while( true ) {
              ppppppplVar13 = local_60;
              if ((longlong ********)local_60 == &local_60) {
                uVar11 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
                *param_4 = uVar11;
                return;
              }
              uVar1 = *(ushort *)((longlong)local_60 + 0x10c);
              if ((uVar1 != 0) && ((*(uint *)(param_2 + 0x20) & 0x140) == 0)) {
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
                  pcVar23 = "Parity";
                  if (*(short *)((longlong)local_60 + 0x10e) != 2) {
                    pcVar23 = "Selective";
                  }
                  WPP_SF_sddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)uVar1,
                              "Selective",pcVar23,(char)uVar1,(char)*(undefined4 *)(local_60 + 2),
                              (char)*(undefined4 *)(local_60 + 0x21));
                }
                PgmSendNak(param_2,(longlong)ppppppplVar13);
              }
              pppppplVar2 = *ppppppplVar13;
              if (((longlong *******)pppppplVar2[1] != ppppppplVar13) ||
                 (pppppplVar3 = ppppppplVar13[1], (longlong *******)*pppppplVar3 != ppppppplVar13))
              break;
              *pppppplVar3 = (longlong *****)pppppplVar2;
              pppppplVar2[1] = (longlong *****)pppppplVar3;
              ExFreePoolWithTag(ppppppplVar13,0);
            }
          }
        }
LAB_14000fff2:
        bVar25 = (byte)uVar21;
        pcVar5 = (code *)swi(0x29);
        (*pcVar5)(3);
        puVar20 = auStackY_b0;
      }
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((bVar25 & (byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c)) != 0)) {
      uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      *(undefined8 *)(puVar20 + -8) = 0x140010029;
      WPP_SF_(uVar4,0x30,&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids);
    }
    if (ppppppplVar13 != (longlong *******)0x0) {
      *(undefined8 *)(puVar20 + -8) = 0x14001003a;
      ExFreePoolWithTag(ppppppplVar13,0);
    }
  }
  return;
code_r0x00014000fcc8:
  *ppppppplVar13 = (longlong ******)&local_60;
  ppppppplVar13[1] = (longlong ******)local_58;
  *local_58 = (longlong ******)ppppppplVar13;
  bVar7 = false;
  local_58 = ppppppplVar13;
  bVar6 = false;
  bVar9 = bVar8;
  if (bVar8) {
LAB_14000fced:
    ppppppplVar14 = (longlong *******)ExAllocatePool2(0x40,0x110,0x366d6750);
    if (ppppppplVar14 == (longlong *******)0x0) {
      bVar6 = bVar7;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) goto LAB_14000fd9b;
      uVar18 = 0x36;
      goto LAB_14000fd8b;
    }
    *(undefined2 *)((longlong)ppppppplVar14 + 0x10e) = 2;
    if ((longlong ********)*local_58 != &local_60) goto LAB_14000fff2;
    ppppppplVar14[1] = (longlong ******)local_58;
    *ppppppplVar14 = (longlong ******)&local_60;
    bVar9 = false;
    *local_58 = (longlong ******)ppppppplVar14;
    bVar8 = false;
    local_58 = ppppppplVar14;
LAB_14000fd47:
    bVar6 = bVar7;
  }
  goto LAB_14000fa11;
}



===== CleanupPendingNaks @ 1400100c0 =====

void CleanupPendingNaks(longlong param_1,longlong param_2,longlong param_3)

{
  uint uVar1;
  undefined4 uVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong ****pppplVar5;
  undefined8 uVar6;
  code *pcVar7;
  undefined1 uVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong ****pppplVar12;
  undefined1 *puVar13;
  longlong lVar14;
  longlong *in_R9;
  int iVar15;
  int iVar16;
  undefined1 auStack_88 [8];
  undefined1 auStack_80 [72];
  longlong ****local_38;
  longlong ****local_30;
  longlong ****local_28;
  longlong ****local_20;
  
  local_30 = (longlong ****)&local_38;
  iVar15 = 0;
  iVar16 = 0;
  local_38 = (longlong ****)&local_38;
  uVar8 = 0;
  local_20 = (longlong ****)&local_28;
  local_28 = (longlong ****)&local_28;
  lVar14 = param_3;
  if (param_3 == 0) {
    uVar8 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x168);
  }
  puVar13 = auStack_88;
  uVar1 = *(uint *)(param_1 + 0x20);
  if ((uVar1 >> 10 & 1) == 0) {
    if ((uVar1 & 0x10000) != 0) {
      PgmMoveList((longlong *)(*(longlong *)(param_1 + 0x30) + 0x98),(longlong *)&local_38);
      PgmMoveList((longlong *)(*(longlong *)(param_1 + 0x30) + 0xa8),(longlong *)&local_28);
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffeffff;
    }
    PgmMoveList((longlong *)(*(longlong *)(param_1 + 0x30) + 0x78),(longlong *)&local_38);
    lVar10 = *(longlong *)(param_1 + 0x30);
    pppplVar12 = (longlong ****)&local_28;
  }
  else {
    if ((uVar1 & 0x10000) != 0) goto LAB_1400103a5;
    *(uint *)(param_1 + 0x20) = uVar1 | 0x10000;
    PgmMoveList((longlong *)(*(longlong *)(param_1 + 0x30) + 0x78),
                (longlong *)(*(longlong *)(param_1 + 0x30) + 0x98));
    lVar10 = *(longlong *)(param_1 + 0x30);
    pppplVar12 = (longlong ****)(lVar10 + 0xa8);
  }
  PgmMoveList((longlong *)(lVar10 + 0x88),(longlong *)pppplVar12);
  if (*(longlong *)(*(longlong *)(param_1 + 0x30) + 0xd8) != 0) {
    plVar11 = (longlong *)(*(longlong *)(param_1 + 0x30) + 0xb8);
    while (plVar3 = (longlong *)*plVar11, plVar3 != plVar11) {
      if (((longlong *)plVar3[1] != plVar11) ||
         (lVar10 = *plVar3, (longlong *)*(longlong *)(lVar10 + 8) != plVar3)) goto LAB_1400102be;
      *plVar11 = lVar10;
      *(longlong **)(lVar10 + 8) = plVar11;
      plVar3[1] = (longlong)plVar3;
      *plVar3 = (longlong)plVar3;
      plVar9 = plVar3 + -2;
      lVar14 = *plVar9;
      if ((*(longlong **)(lVar14 + 8) != plVar9) ||
         (plVar4 = (longlong *)plVar3[-1], (longlong *)*plVar4 != plVar9)) goto LAB_1400102be;
      *plVar4 = lVar14;
      *(longlong **)(lVar14 + 8) = plVar4;
      plVar3[-1] = (longlong)plVar9;
      *plVar9 = (longlong)plVar9;
    }
  }
  if (param_3 == 0) {
    KeReleaseSpinLock(param_1 + 0x168,uVar8);
  }
  while (pppplVar12 = local_38, (longlong *****)local_38 != &local_38) {
    if (((longlong *****)local_38[1] != &local_38) ||
       (pppplVar5 = (longlong ****)*local_38, (longlong ****)pppplVar5[1] != local_38))
    goto LAB_1400102be;
    pppplVar5[1] = (longlong ***)&local_38;
    local_38 = pppplVar5;
    FreeNakContext(param_1,(longlong)pppplVar12);
    iVar15 = iVar15 + 1;
  }
  while( true ) {
    pppplVar12 = local_28;
    puVar13 = auStack_88;
    if ((longlong *****)local_28 == &local_28) break;
    if (((longlong *****)local_28[1] != &local_28) ||
       (pppplVar5 = (longlong ****)*local_28, (longlong ****)pppplVar5[1] != local_28))
    goto LAB_1400102be;
    pppplVar5[1] = (longlong ***)&local_28;
    local_28 = pppplVar5;
    FreeNakContext(param_1,(longlong)pppplVar12);
    iVar16 = iVar16 + 1;
  }
LAB_1400102c5:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    lVar10 = *(longlong *)(param_1 + 0x30);
    uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(uint *)(puVar13 + 0x48) = (uint)*(byte *)(param_1 + 0xa0);
    uVar2 = *(undefined4 *)(lVar10 + 0x104);
    *(int *)(puVar13 + 0x40) = iVar16;
    *(undefined4 *)(puVar13 + 0x38) = uVar2;
    uVar2 = *(undefined4 *)(lVar10 + 0x110);
    *(int *)(puVar13 + 0x30) = iVar15;
    *(undefined4 *)(puVar13 + 0x28) = uVar2;
    *(undefined4 *)(puVar13 + 0x20) = *(undefined4 *)(lVar10 + 0x38);
    *(undefined8 *)(puVar13 + -8) = 0x14001031f;
    in_R9 = (longlong *)param_1;
    WPP_SF_qdddddd(uVar6,lVar10,lVar14,param_1,puVar13[0x20],puVar13[0x28],puVar13[0x30],
                   puVar13[0x38],puVar13[0x40],puVar13[0x48]);
  }
  *(undefined4 *)(*(longlong *)(param_1 + 0x30) + 0x110) = 0;
  if (param_3 == 0) {
    *(undefined8 *)(puVar13 + -8) = 0x14001033d;
    uVar8 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x168);
  }
  if ((*(uint *)(param_1 + 0x20) >> 0x10 & 1) == 0) {
    if ((*(uint *)(param_1 + 0x20) >> 0xf & 1) != 0) {
      *(undefined4 *)(*(longlong *)(param_1 + 0x30) + 0x114) = 0;
      lVar14 = *(longlong *)(param_1 + 0x30);
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffff7fff;
      *(undefined8 *)(puVar13 + -8) = 0x140010376;
      ExDeleteNPagedLookasideList(lVar14 + 0x140);
    }
    lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xd8);
    if (lVar14 != 0) {
      *(undefined8 *)(puVar13 + -8) = 0x140010394;
      ExFreePoolWithTag(lVar14,0);
      *(undefined8 *)(*(longlong *)(param_1 + 0x30) + 0xd8) = 0;
    }
  }
LAB_1400103a5:
  if (param_3 == 0) {
    *(undefined8 *)(puVar13 + -8) = 0x1400103bb;
    KeReleaseSpinLock(param_1 + 0x168,uVar8);
    if (param_2 != 0) {
      *(undefined8 *)(puVar13 + -8) = 0x1400103d6;
      PgmDereferenceSessionCommon((longlong *)param_1,0x52534553,0xb,in_R9);
    }
  }
  return;
LAB_1400102be:
  pcVar7 = (code *)swi(0x29);
  (*pcVar7)(3);
  puVar13 = auStack_80;
  goto LAB_1400102c5;
}



===== CoalesceSelectiveNaksIntoGroups @ 1400103fc =====

/* WARNING: Type propagation algorithm not settling */

ulonglong CoalesceSelectiveNaksIntoGroups(longlong param_1,byte param_2)

{
  int *piVar1;
  byte bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  longlong *******ppppppplVar5;
  undefined8 ******ppppppuVar6;
  undefined8 *******pppppppuVar7;
  undefined8 uVar8;
  code *pcVar9;
  longlong ******pppppplVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  longlong *******ppppppplVar13;
  ulonglong uVar14;
  undefined8 ******ppppppuVar15;
  ulonglong uVar16;
  undefined8 *puVar17;
  uint uVar18;
  longlong lVar19;
  byte bVar20;
  uint uVar21;
  undefined1 *puVar22;
  uint uVar23;
  undefined **ppuVar24;
  undefined8 *******pppppppuVar25;
  longlong lVar26;
  ushort uVar27;
  undefined8 *puVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  undefined **_Size;
  undefined **ppuVar33;
  byte local_res10;
  uint local_res18 [2];
  uint local_res20;
  undefined1 auStackY_d8 [8];
  undefined1 auStackY_d0 [24];
  longlong *******local_80;
  longlong *******ppppppplStack_78;
  undefined8 *******local_70;
  undefined8 *******local_68;
  longlong *******local_60;
  longlong *******local_58;
  
  local_80 = (longlong *******)0x0;
  ppppppplStack_78 = (longlong *******)0x0;
  uVar31 = param_2 - 1;
  AdjustReceiveBufferLists(param_1);
  lVar19 = *(longlong *)(param_1 + 0x30);
  uVar23 = 0;
  uVar3 = *(undefined4 *)(lVar19 + 0x40);
  uVar21 = *(uint *)(lVar19 + 0x38) & ~uVar31;
  uVar32 = *(uint *)(lVar19 + 0x3c) & ~uVar31;
  local_res18[0] = (param_2 - 1) + uVar32;
  uVar11 = CheckAndAddNakRequests(param_1,local_res18,(undefined8 *)0x0,1,'\0');
  uVar12 = uVar11 & 0xffffffff;
  if ((int)uVar11 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar12;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return uVar12;
    }
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4e,
             &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,(int)uVar11);
    return uVar12;
  }
  ppuVar24 = (undefined **)0x0;
  *(undefined4 *)(*(longlong *)(param_1 + 0x30) + 0x40) = uVar3;
  _Size = (undefined **)(ulonglong)(uVar31 * 0x28 + 0x88);
  ExInitializeNPagedLookasideList(*(longlong *)(param_1 + 0x30) + 0x240,0,0,0x200);
  lVar19 = *(longlong *)(param_1 + 0x30);
  if (0 < (int)(*(int *)(lVar19 + 0x38) - local_res18[0])) {
    *(uint *)(lVar19 + 0x3c) = uVar32;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      lVar19 = *(longlong *)(param_1 + 0x30);
      WPP_SF_dddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4f,
                  &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,*(undefined4 *)(lVar19 + 0x34),
                  (char)*(undefined4 *)(lVar19 + 0x38),(char)uVar21,
                  (char)*(undefined4 *)(lVar19 + 0x3c));
    }
    return 0;
  }
  uVar18 = *(uint *)(*(longlong *)(lVar19 + 0x18) + 0x38) & 0x10;
  local_res20 = GetRandomInteger((-(uint)(uVar18 != 0) & 0xffffffd0) + 0x32,
                                 (-(uint)(uVar18 != 0) & 0xffffffb0) + 100);
  local_58 = (longlong *******)&local_60;
  local_60 = (longlong *******)&local_60;
  local_68 = &local_70;
  local_70 = &local_70;
  uVar12 = Feature_951217465__private_IsEnabledDeviceUsageNoInline();
  puVar22 = auStackY_d8;
  if ((int)uVar12 != 0) {
    uVar12 = 0;
    local_80 = (longlong *******)&local_80;
    uVar30 = (uVar32 - uVar21) / (uint)param_2 + 1;
    ppppppplStack_78 = (longlong *******)&local_80;
    if (uVar30 != 0) {
LAB_140010613:
      ppppppplVar13 =
           (longlong *******)
           ExAllocateFromNPagedLookasideList(*(longlong *)(param_1 + 0x30) + 0x240);
      if (ppppppplVar13 == (longlong *******)0x0) {
        ppuVar33 = &WPP_GLOBAL_Control;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          ppuVar24 = (undefined **)&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids;
          WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x50,
                    &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,(int)uVar12,(char)uVar30);
        }
        while( true ) {
          if ((longlong ********)local_80 == &local_80) {
            ExDeleteNPagedLookasideList(*(longlong *)(param_1 + 0x30) + 0x240);
            return 0xc000009a;
          }
          if (((longlong ********)local_80[1] != &local_80) ||
             (ppppppplVar13 = (longlong *******)*local_80,
             (longlong *******)ppppppplVar13[1] != local_80)) break;
          ppppppplVar13[1] = (longlong ******)&local_80;
          local_80 = ppppppplVar13;
          ExFreeToNPagedLookasideList(*(longlong *)(param_1 + 0x30) + 0x240);
        }
      }
      else {
        ppuVar24 = _Size;
        memset(ppppppplVar13,0,(size_t)_Size);
        ppuVar33 = _Size;
        if ((longlong ********)*ppppppplStack_78 == &local_80) goto code_r0x000140010654;
      }
      goto LAB_140010bfd;
    }
  }
LAB_140010676:
  uVar12 = uVar11 & 0xffffffff;
  uVar30 = (uint)param_2;
  ppuVar33 = &WPP_GLOBAL_Control;
  if (-1 < (int)(uVar32 - uVar21)) {
    do {
      uVar11 = Feature_951217465__private_IsEnabledDeviceUsageNoInline();
      ppppppplVar13 = local_80;
      if ((int)uVar11 == 0) {
        ppppppplVar13 =
             (longlong *******)
             ExAllocateFromNPagedLookasideList(*(longlong *)(param_1 + 0x30) + 0x240);
        if (ppppppplVar13 == (longlong *******)0x0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
            ppuVar24 = (undefined **)&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids;
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x51,
                    &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids);
          }
          uVar12 = 0xc000009a;
          goto LAB_140010b78;
        }
        memset(ppppppplVar13,0,(size_t)_Size);
      }
      else {
        if (((longlong ********)local_80[1] != &local_80) ||
           (ppppppplVar5 = (longlong *******)*local_80,
           (longlong *******)ppppppplVar5[1] != local_80)) goto LAB_140010bfd;
        ppppppplVar5[1] = (longlong ******)&local_80;
        local_80 = ppppppplVar5;
        memset(ppppppplVar13,0,(size_t)_Size);
        ppppppplVar13[1] = (longlong ******)ppppppplVar13;
        *ppppppplVar13 = (longlong ******)ppppppplVar13;
      }
      *(uint *)(ppppppplVar13 + 2) = uVar32;
      ppppppplVar5 = ppppppplVar13 + 10;
      ppppppplVar13[0xb] = (longlong ******)ppppppplVar5;
      bVar20 = 0;
      *ppppppplVar5 = (longlong ******)ppppppplVar5;
      ppppppplVar5 = ppppppplVar13 + 8;
      ppppppplVar13[9] = (longlong ******)ppppppplVar5;
      *ppppppplVar5 = (longlong ******)ppppppplVar5;
      *(byte *)((longlong)ppppppplVar13 + 0x39) = param_2;
      *(byte *)((longlong)ppppppplVar13 + 0x3e) = param_2;
      uVar27 = *(ushort *)(param_1 + 0x9a);
      uVar11 = (ulonglong)uVar27;
      if (param_2 != 0) {
        uVar29 = uVar30;
        do {
          uVar14 = (ulonglong)bVar20;
          bVar20 = bVar20 + 1;
          *(char *)((longlong)ppppppplVar13 + uVar14 * 0x28 + 0x75) = (char)uVar29;
          uVar29 = (uint)*(byte *)((longlong)ppppppplVar13 + 0x3e);
        } while (bVar20 < *(byte *)((longlong)ppppppplVar13 + 0x3e));
      }
      bVar20 = 0;
      local_res10 = 0;
      uVar29 = local_res18[0] - uVar32;
      while (-1 < (int)uVar29) {
        uVar14 = (ulonglong)uVar29;
        ppuVar24 = (undefined **)(ulonglong)local_res18[0];
        uVar27 = (ushort)uVar11;
        lVar19 = *(longlong *)(param_1 + 0x30);
        ppppppuVar15 = (undefined8 ******)(lVar19 + 0x88);
        if ((undefined8 ******)*ppppppuVar15 == ppppppuVar15) break;
        pppppppuVar25 = *(undefined8 ********)(lVar19 + 0x90);
        if ((*pppppppuVar25 != ppppppuVar15) ||
           (ppppppuVar6 = pppppppuVar25[1], (undefined8 *******)*ppppppuVar6 != pppppppuVar25))
        goto LAB_140010bfd;
        *(undefined8 *******)(lVar19 + 0x90) = ppppppuVar6;
        *ppppppuVar6 = ppppppuVar15;
        if (*(char *)((longlong)pppppppuVar25 + 0x3a) == '\0') {
          RemovePendingReceiverEntry((longlong)pppppppuVar25);
          ppuVar24 = (undefined **)(ulonglong)local_res18[0];
          bVar20 = local_res10;
        }
        if (pppppppuVar25[0xc] != (undefined8 ******)0x0) {
          *(char *)((longlong)ppppppplVar13 + 0x3a) =
               *(char *)((longlong)ppppppplVar13 + 0x3a) + '\x01';
          pppppplVar10 = pppppppuVar25[0xd];
          uVar16 = (ulonglong)bVar20;
          ppppppplVar13[uVar16 * 5 + 0xc] = pppppppuVar25[0xc];
          (ppppppplVar13 + uVar16 * 5 + 0xc)[1] = pppppplVar10;
          pppppplVar10 = pppppppuVar25[0xf];
          ppppppplVar13[uVar16 * 5 + 0xe] = pppppppuVar25[0xe];
          (ppppppplVar13 + uVar16 * 5 + 0xe)[1] = pppppplVar10;
          ppppppplVar13[uVar16 * 5 + 0x10] = pppppppuVar25[0x10];
          *(char *)((longlong)ppppppplVar13 + uVar16 * 0x28 + 0x74) = (char)ppuVar24 - (char)uVar32;
          *(byte *)((longlong)ppppppplVar13 + uVar14 * 0x28 + 0x75) = bVar20;
          bVar20 = bVar20 + 1;
          *(char *)((longlong)pppppppuVar25 + 0x3a) = *(char *)((longlong)pppppppuVar25 + 0x3a) + -1
          ;
          pppppppuVar25[0xc] = (undefined8 ******)0x0;
          *(undefined4 *)((longlong)pppppppuVar25 + 0x84) = 0;
          if (*(ushort *)((longlong)pppppppuVar25 + 0x36) < (ushort)uVar11) {
            uVar11 = (ulonglong)*(ushort *)((longlong)pppppppuVar25 + 0x36);
          }
          bVar2 = *(byte *)((longlong)pppppppuVar25 + 0x3d);
          local_res10 = bVar20;
          if (((bVar2 != 0) && (bVar2 < param_2)) &&
             (*(byte *)((longlong)ppppppplVar13 + 0x39) == param_2)) {
            *(byte *)((longlong)ppppppplVar13 + 0x39) = bVar2;
          }
        }
        uVar27 = (ushort)uVar11;
        if ((undefined8 ********)local_70[1] != &local_70) goto LAB_140010bfd;
        *pppppppuVar25 = local_70;
        pppppppuVar25[1] = &local_70;
        local_70[1] = pppppppuVar25;
        local_res18[0] = (int)ppuVar24 - 1;
        local_70 = pppppppuVar25;
        uVar29 = (int)uVar14 - 1;
      }
      ppuVar24 = (undefined **)0x0;
      *(ushort *)((longlong)ppppppplVar13 + 0x36) = uVar27;
      RemoveRedundantNaks(param_1,(longlong)ppppppplVar13,'\0');
      if (*(byte *)((longlong)ppppppplVar13 + 0x3a) < *(byte *)((longlong)ppppppplVar13 + 0x39)) {
        ppppppplVar13[3] =
             (longlong ******)
             (((ulonglong)local_res20 /
              (ulonglong)
              ((uint)*(byte *)((longlong)ppppppplVar13 + 0x39) -
              (uint)*(byte *)((longlong)ppppppplVar13 + 0x3a))) / 0x14 + DAT_140036750);
      }
      if ((longlong ********)local_60[1] != &local_60) goto LAB_140010bfd;
      *ppppppplVar13 = (longlong ******)local_60;
      ppppppplVar13[1] = (longlong ******)&local_60;
      local_60[1] = (longlong ******)ppppppplVar13;
      uVar32 = uVar32 - uVar30;
      local_60 = ppppppplVar13;
    } while (-1 < (int)(uVar32 - uVar21));
    if ((ppppppplVar13 != (longlong *******)0x0) &&
       (uVar32 = *(uint *)(ppppppplVar13 + 2), uVar32 == uVar21)) {
      if (0 < (int)(*(int *)(*(longlong *)(param_1 + 0x30) + 0x38) - uVar32)) {
        *(char *)((longlong)ppppppplVar13 + 0x3f) =
             *(char *)(*(longlong *)(param_1 + 0x30) + 0x38) - (char)uVar32;
        *(uint *)(*(longlong *)(param_1 + 0x30) + 0x38) = uVar32;
      }
      ppuVar24 = (undefined **)((longlong)ppppppplVar13 + 0x3f);
      while (*(byte *)ppuVar24 != 0) {
        lVar19 = *(longlong *)(param_1 + 0x30);
        ppppppuVar15 = (undefined8 ******)(lVar19 + 0x78);
        if ((undefined8 ******)*ppppppuVar15 == ppppppuVar15) break;
        pppppppuVar25 = *(undefined8 ********)(lVar19 + 0x80);
        uVar32 = uVar21;
        if ((*pppppppuVar25 != ppppppuVar15) ||
           (ppppppuVar6 = pppppppuVar25[1], (undefined8 *******)*ppppppuVar6 != pppppppuVar25))
        goto LAB_140010bfd;
        *(undefined8 *******)(lVar19 + 0x80) = ppppppuVar6;
        *ppppppuVar6 = ppppppuVar15;
        piVar1 = (int *)(*(longlong *)(param_1 + 0x30) + 0x110);
        *piVar1 = *piVar1 + -1;
        piVar1 = (int *)(*(longlong *)(param_1 + 0x30) + 0x108);
        *piVar1 = *piVar1 + -1;
        piVar1 = (int *)(*(longlong *)(param_1 + 0x30) + 0x10c);
        *piVar1 = *piVar1 + 1;
        *(byte *)ppuVar24 = *(byte *)ppuVar24 - 1;
        uVar11 = (ulonglong)*(byte *)((longlong)ppppppplVar13 + 0x3a);
        pppppplVar10 = pppppppuVar25[0xd];
        ppppppplVar13[uVar11 * 5 + 0xc] = pppppppuVar25[0xc];
        (ppppppplVar13 + uVar11 * 5 + 0xc)[1] = pppppplVar10;
        pppppplVar10 = pppppppuVar25[0xf];
        ppppppplVar13[uVar11 * 5 + 0xe] = pppppppuVar25[0xe];
        (ppppppplVar13 + uVar11 * 5 + 0xe)[1] = pppppplVar10;
        ppppppplVar13[uVar11 * 5 + 0x10] = pppppppuVar25[0x10];
        *(byte *)((longlong)ppppppplVar13 +
                 (ulonglong)*(byte *)((longlong)ppppppplVar13 + 0x3a) * 0x28 + 0x74) =
             *(byte *)ppuVar24;
        *(undefined1 *)((longlong)ppppppplVar13 + (ulonglong)*(byte *)ppuVar24 * 0x28 + 0x75) =
             *(undefined1 *)((longlong)ppppppplVar13 + 0x3a);
        *(char *)((longlong)ppppppplVar13 + 0x3a) =
             *(char *)((longlong)ppppppplVar13 + 0x3a) + '\x01';
        if (*(ushort *)((longlong)pppppppuVar25 + 0x36) <
            *(ushort *)((longlong)ppppppplVar13 + 0x36)) {
          *(ushort *)((longlong)ppppppplVar13 + 0x36) = *(ushort *)((longlong)pppppppuVar25 + 0x36);
        }
        bVar20 = *(byte *)((longlong)pppppppuVar25 + 0x3d);
        if (((bVar20 != 0) && (bVar20 < param_2)) &&
           (*(byte *)((longlong)ppppppplVar13 + 0x39) == param_2)) {
          *(byte *)((longlong)ppppppplVar13 + 0x39) = bVar20;
        }
        *(char *)((longlong)pppppppuVar25 + 0x3a) = *(char *)((longlong)pppppppuVar25 + 0x3a) + -1;
        pppppppuVar25[0xc] = (undefined8 ******)0x0;
        *(undefined4 *)((longlong)pppppppuVar25 + 0x84) = 0;
        if ((undefined8 ********)local_70[1] != &local_70) goto LAB_140010bfd;
        *pppppppuVar25 = local_70;
        pppppppuVar25[1] = &local_70;
        local_70[1] = pppppppuVar25;
        local_70 = pppppppuVar25;
      }
      if (-1 < *(int *)(*(longlong *)(param_1 + 0x30) + 0x34) - *(int *)(ppppppplVar13 + 2)) {
        *(int *)(*(longlong *)(param_1 + 0x30) + 0x34) = *(int *)(ppppppplVar13 + 2);
      }
      lVar19 = *(longlong *)(param_1 + 0x30);
      if (0 < *(int *)(lVar19 + 0x30) - *(int *)(lVar19 + 0x38)) {
        *(int *)(lVar19 + 0x30) = *(int *)(lVar19 + 0x38);
      }
      RemoveRedundantNaks(param_1,(longlong)ppppppplVar13,'\0');
      bVar20 = *(byte *)((longlong)ppppppplVar13 + 0x3a);
      ppuVar24 = (undefined **)(ulonglong)bVar20;
      if ((uint)bVar20 + (uint)*(byte *)((longlong)ppppppplVar13 + 0x3f) <
          (uint)*(byte *)((longlong)ppppppplVar13 + 0x39)) {
        ppppppplVar13[3] =
             (longlong ******)
             (((ulonglong)local_res20 /
              (ulonglong)
              (((uint)*(byte *)((longlong)ppppppplVar13 + 0x39) - (uint)bVar20) -
              (uint)*(byte *)((longlong)ppppppplVar13 + 0x3f))) / 0x14 + DAT_140036750);
      }
      else {
        ppppppplVar13[3] = (longlong ******)0x0;
      }
    }
  }
LAB_140010b78:
  if ((longlong ********)local_60 != &local_60) {
    local_60[1] = *(longlong *******)(*(longlong *)(param_1 + 0x30) + 0x90);
    *local_58 = (longlong ******)(*(longlong *)(param_1 + 0x30) + 0x88);
    **(longlong **)(*(longlong *)(param_1 + 0x30) + 0x90) = (longlong)local_60;
    *(longlong ********)(*(longlong *)(param_1 + 0x30) + 0x90) = local_58;
  }
  while (pppppppuVar25 = local_70, uVar32 = uVar21, (undefined8 ********)local_70 != &local_70) {
    if (((undefined8 ********)local_70[1] != &local_70) ||
       (pppppppuVar7 = (undefined8 *******)*local_70,
       (undefined8 *******)pppppppuVar7[1] != local_70)) goto LAB_140010bfd;
    pppppppuVar7[1] = &local_70;
    local_70 = pppppppuVar7;
    FreeNakContext(param_1,(longlong)pppppppuVar25);
  }
LAB_140010c04:
  *(ushort *)(*(longlong *)(param_1 + 0x30) + 0xe6) = (ushort)(byte)(&gFECLog2)[uVar30 & 0xff];
  lVar19 = *(longlong *)(param_1 + 0x30);
  puVar17 = (undefined8 *)(lVar19 + 0x88);
  for (puVar28 = (undefined8 *)*puVar17; puVar28 != puVar17; puVar28 = (undefined8 *)*puVar28) {
    bVar20 = *(byte *)((longlong)puVar28 + 0x39);
    ppuVar24 = (undefined **)(ulonglong)bVar20;
    if (((uint)*(byte *)((longlong)puVar28 + 0x3b) + (uint)*(byte *)((longlong)puVar28 + 0x3a) <
         (uint)bVar20) &&
       ((uint)*(byte *)((longlong)puVar28 + 0x3f) + (uint)*(byte *)((longlong)puVar28 + 0x3a) <
        (uint)bVar20)) {
      *(undefined8 *)(puVar22 + -8) = 0x140010c58;
      AppendPendingReceiverEntry(lVar19,(longlong)puVar28);
    }
    lVar19 = *(longlong *)(param_1 + 0x30);
    puVar17 = (undefined8 *)(lVar19 + 0x88);
  }
  *(undefined8 *)(puVar22 + -8) = 0x140010c73;
  AdjustReceiveBufferLists(param_1);
  lVar19 = *(longlong *)(param_1 + 0x30);
  lVar26 = 0;
  if (*(longlong **)(lVar19 + 0x88) == (longlong *)(lVar19 + 0x88)) {
    if (*(longlong **)(lVar19 + 0x78) != (longlong *)(lVar19 + 0x78)) {
      lVar26 = *(longlong *)(lVar19 + 0x80);
      goto LAB_140010cd9;
    }
  }
  else {
    lVar26 = *(longlong *)(lVar19 + 0x90);
    bVar20 = *(byte *)(lVar26 + 0x39);
    ppuVar24 = (undefined **)(ulonglong)bVar20;
    if (*(byte *)(lVar26 + 0x3a) < bVar20) {
      uVar21 = (uint)bVar20 - (uint)*(byte *)(lVar26 + 0x3a);
      ppuVar24 = (undefined **)(ulonglong)uVar21;
      *(ulonglong *)(lVar26 + 0x18) =
           (ulonglong)(local_res20 / uVar21 + (-(uint)(uVar18 != 0) & 0xfffffd44) + 0x2ee) / 0x14 +
           DAT_140036750;
      lVar19 = *(longlong *)(param_1 + 0x30);
    }
LAB_140010cd9:
    if (lVar26 != 0) {
      *(undefined4 *)(lVar19 + 0x3c) = *(undefined4 *)(lVar26 + 0x10);
      goto LAB_140010cef;
    }
  }
  *(uint *)(lVar19 + 0x3c) = *(uint *)(lVar19 + 0x3c) & ~uVar31;
LAB_140010cef:
  if (((undefined **)WPP_GLOBAL_Control != ppuVar33) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    if (lVar26 != 0) {
      uVar23 = (uint)*(byte *)(lVar26 + 0x3f);
    }
    lVar19 = *(longlong *)(param_1 + 0x30);
    uVar8 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(undefined4 *)(puVar22 + 0x38) = *(undefined4 *)(lVar19 + 0x3c);
    uVar3 = *(undefined4 *)(lVar19 + 0x38);
    uVar4 = *(undefined4 *)(lVar19 + 0x34);
    *(uint *)(puVar22 + 0x30) = uVar32;
    *(uint *)(puVar22 + 0x28) = uVar23;
    *(undefined4 *)(puVar22 + 0x20) = uVar3;
    *(undefined8 *)(puVar22 + -8) = 0x140010d3b;
    WPP_SF_ddddd(uVar8,0x52,ppuVar24,uVar4,puVar22[0x20],puVar22[0x28],puVar22[0x30],puVar22[0x38]);
  }
  return uVar12;
code_r0x000140010654:
  ppppppplVar13[1] = (longlong ******)ppppppplStack_78;
  *ppppppplVar13 = (longlong ******)&local_80;
  uVar29 = (int)uVar12 + 1;
  uVar12 = (ulonglong)uVar29;
  *ppppppplStack_78 = (longlong ******)ppppppplVar13;
  ppppppplStack_78 = ppppppplVar13;
  if (uVar30 <= uVar29) goto LAB_140010676;
  goto LAB_140010613;
LAB_140010bfd:
  pcVar9 = (code *)swi(0x29);
  (*pcVar9)(3);
  puVar22 = auStackY_d0;
  goto LAB_140010c04;
}



===== DecodeParityPackets @ 140010d5c =====

ulonglong DecodeParityPackets(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  char cVar2;
  short sVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  byte bVar8;
  ushort uVar9;
  uint uVar10;
  longlong lVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  void *pvVar14;
  ushort *puVar15;
  ulonglong uVar16;
  ushort uVar17;
  byte bVar18;
  ushort local_res8 [4];
  ushort local_res10;
  ushort local_res18;
  ushort local_48;
  char cStack_46;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  
  local_res10 = *(ushort *)(param_2 + 0x34);
  pvVar14 = *(void **)(param_1 + 0x90);
  local_res18 = local_res10 + 0xe;
  uVar12 = 0;
  bVar8 = *(byte *)(param_1 + 0xa0);
  if (bVar8 != 0) {
    do {
      bVar18 = (byte)uVar12;
      if (bVar18 < *(byte *)(param_2 + 0x39)) {
        uVar9 = *(ushort *)(param_2 + 0x72 + uVar12 * 0x28);
        uVar17 = *(short *)(param_2 + 0x70 + uVar12 * 0x28) - uVar9;
        if (*(byte *)(param_2 + 0x74 + uVar12 * 0x28) < bVar8) {
          uVar16 = Feature_4275546425__private_IsEnabledDeviceUsageNoInline();
          if ((int)uVar16 != 0) {
            local_res8[0] = 0;
            puVar15 = local_res8;
            uVar10 = RtlUShortAdd(uVar17,2,puVar15);
            if (((int)uVar10 < 0) || (*(ushort *)(param_2 + 0x34) < local_res8[0])) {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
                WPP_SF_HH(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x62,puVar15,uVar17,
                          (char)*(undefined2 *)(param_2 + 0x34));
              }
              return 0xc000003e;
            }
          }
          lVar11 = param_2 + uVar12 * 0x28;
          uVar16 = (ulonglong)uVar17;
          memmove(pvVar14,(void *)((ulonglong)*(ushort *)(param_2 + 0x72 + uVar12 * 0x28) +
                                  *(longlong *)(lVar11 + 0x60)),uVar16);
          if ((*(ushort *)(param_2 + 0x36) < local_res18) &&
             (*(ushort *)(param_2 + 0x70 + uVar12 * 0x28) < *(ushort *)(param_2 + 0x34))) {
            uVar16 = (ulonglong)(uint)local_res18;
            lVar11 = ReAllocateDataBuffer(param_1,(longlong *)(lVar11 + 0x60),(uint)local_res18);
            if (lVar11 == 0) {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
                WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),99,
                        &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids);
              }
              return 0xc000009a;
            }
          }
          *(void **)(param_2 + 0x68 + uVar12 * 0x28) = pvVar14;
          uVar9 = *(ushort *)(param_2 + 0x34);
          if (uVar9 < uVar17) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
              WPP_SF_HH(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),100,uVar16,uVar9,(char)uVar17);
            }
            return 0xc0000095;
          }
          memset((void *)((ulonglong)uVar17 + (longlong)pvVar14),0,
                 (ulonglong)(ushort)(uVar9 - uVar17));
          uVar9 = *(ushort *)(param_2 + 0x34);
          cVar2 = *(char *)(param_2 + 0x77 + uVar12 * 0x28);
          if (cVar2 < '\0') {
            uStack_44 = 0;
            uStack_40 = 0;
            uStack_3c = 0;
          }
          else {
            uVar10 = *(uint *)(param_2 + (uVar12 + 3) * 0x28);
            uStack_44 = uVar10 >> 0x18 | (uVar10 & 0xff0000) >> 8 | (uVar10 & 0xff00) << 8 |
                        uVar10 << 0x18;
            uVar10 = *(uint *)(param_2 + 0x7c + uVar12 * 0x28);
            uStack_40 = uVar10 >> 0x18 | (uVar10 & 0xff0000) >> 8 | (uVar10 & 0xff00) << 8 |
                        uVar10 << 0x18;
            uVar10 = *(uint *)(param_2 + 0x80 + uVar12 * 0x28);
            uStack_3c = uVar10 >> 0x18 | (uVar10 & 0xff0000) >> 8 | (uVar10 & 0xff00) << 8 |
                        uVar10 << 0x18;
          }
          *(ulonglong *)((longlong)pvVar14 + ((ulonglong)uVar9 - 2)) =
               CONCAT44(uStack_44,(uint)CONCAT12(cVar2,uVar17 >> 8 | uVar17 * 0x100));
          *(ulonglong *)((longlong)pvVar14 + (ulonglong)uVar9 + 6) = CONCAT44(uStack_3c,uStack_40);
          pvVar14 = (void *)((longlong)pvVar14 + (ulonglong)uVar9 + 0xe);
        }
        else {
          memmove(pvVar14,(void *)((ulonglong)uVar9 + *(longlong *)(param_2 + 0x60 + uVar12 * 0x28))
                  ,(ulonglong)uVar17);
          *(void **)(param_2 + 0x68 + uVar12 * 0x28) = pvVar14;
          uVar9 = *(ushort *)(param_2 + 0x34);
          uVar4 = *(undefined4 *)(param_2 + 0x7c + uVar12 * 0x28);
          uVar5 = *(undefined4 *)(param_2 + 0x80 + uVar12 * 0x28);
          *(ulonglong *)((longlong)pvVar14 + ((ulonglong)uVar9 - 2)) =
               CONCAT44(*(undefined4 *)(param_2 + 0x78 + uVar12 * 0x28),
                        (uint)CONCAT12(*(undefined1 *)(param_2 + 0x77 + uVar12 * 0x28),
                                       *(undefined2 *)((longlong)pvVar14 + ((ulonglong)uVar9 - 2))))
          ;
          *(ulonglong *)((longlong)pvVar14 + (ulonglong)uVar9 + 6) = CONCAT44(uVar5,uVar4);
          pvVar14 = (void *)((longlong)pvVar14 + (ulonglong)uVar9 + 0xe);
        }
      }
      else {
        uVar9 = *(short *)(param_2 + 0x34) + 0xe;
        *(byte *)(param_2 + 0x74 + uVar12 * 0x28) = bVar18;
        *(ushort *)(param_2 + 0x70 + uVar12 * 0x28) = uVar9;
        *(undefined2 *)(param_2 + 0x72 + uVar12 * 0x28) = 0;
        memset(pvVar14,0,(ulonglong)(uint)uVar9);
        *(undefined1 *)((ulonglong)local_res10 + (longlong)pvVar14) = 0x80;
        *(void **)(param_2 + 0x68 + uVar12 * 0x28) = pvVar14;
        pvVar14 = (void *)((longlong)pvVar14 + (ulonglong)uVar9);
        memset(pvVar14,0,(ulonglong)(uint)uVar9);
        *(void **)(param_2 + 0x60 + uVar12 * 0x28) = pvVar14;
        pvVar14 = (void *)((longlong)pvVar14 + (ulonglong)uVar9);
      }
      bVar8 = *(byte *)(param_1 + 0xa0);
      uVar12 = (ulonglong)(byte)(bVar18 + 1);
    } while ((byte)(bVar18 + 1) < bVar8);
  }
  sVar3 = *(short *)(param_2 + 0x34);
  uVar12 = FECDecode((uint *)(param_1 + 0x70),(undefined8 *)(param_2 + 0x60),
                     (uint)(ushort)(sVar3 + 0xe));
  uVar16 = uVar12 & 0xffffffff;
  bVar8 = 0;
  if (*(char *)(param_1 + 0xa0) != '\0') {
    do {
      uVar13 = (ulonglong)bVar8;
      *(undefined8 *)(param_2 + 0x68 + uVar13 * 0x28) = 0;
      if (*(byte *)(param_2 + 0x39) <= bVar8) {
        *(undefined8 *)(param_2 + 0x60 + uVar13 * 0x28) = 0;
      }
      *(byte *)(param_2 + 0x75 + uVar13 * 0x28) = bVar8;
      bVar8 = bVar8 + 1;
    } while (bVar8 < *(byte *)(param_1 + 0xa0));
  }
  if ((int)uVar12 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x66,
               &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,(int)uVar12);
    }
    uVar16 = 0xc0000001;
  }
  else {
    uVar9 = sVar3 - 2;
    *(char *)(param_2 + 0x3a) = *(char *)(param_2 + 0x39);
    *(undefined1 *)(param_2 + 0x3b) = 0;
    bVar8 = 0;
    if (*(char *)(param_2 + 0x39) != '\0') {
      do {
        uVar12 = (ulonglong)bVar8;
        puVar1 = (undefined8 *)(*(longlong *)(param_2 + 0x60 + uVar12 * 0x28) + (ulonglong)uVar9);
        uVar6 = *puVar1;
        uVar7 = puVar1[1];
        local_48 = (ushort)uVar6;
        cStack_46 = (char)((ulonglong)uVar6 >> 0x10);
        uStack_44 = (uint)((ulonglong)uVar6 >> 0x20);
        uStack_40 = (uint)uVar7;
        uStack_3c = (uint)((ulonglong)uVar7 >> 0x20);
        uVar17 = local_48 >> 8 | local_48 << 8;
        *(ushort *)(param_2 + 0x70 + uVar12 * 0x28) = uVar17;
        if (uVar9 < uVar17) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
            WPP_SF_dDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x65,
                       &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,(uint)bVar8,
                       (char)((ulonglong)uVar6 >> 8),(char)uVar9);
          }
          return 0xc0000001;
        }
        *(undefined2 *)(param_2 + 0x72 + uVar12 * 0x28) = 0;
        *(byte *)(param_2 + 0x74 + uVar12 * 0x28) = bVar8;
        if (((*(uint *)(param_2 + 0x30) & 1) == 0) || (cStack_46 < '\0')) {
          *(uint *)(param_2 + 0x78 + uVar12 * 0x28) = (uint)bVar8 + *(int *)(param_2 + 0x10);
          uVar10 = (uint)uVar17;
          *(undefined4 *)(param_2 + 0x7c + uVar12 * 0x28) = 0;
        }
        else {
          *(uint *)(param_2 + 0x78 + uVar12 * 0x28) =
               uStack_44 >> 0x18 | (uStack_44 & 0xff0000) >> 8 | (uStack_44 & 0xff00) << 8 |
               uStack_44 << 0x18;
          *(uint *)(param_2 + 0x7c + uVar12 * 0x28) =
               uStack_40 >> 0x18 | (uStack_40 & 0xff0000) >> 8 | (uStack_40 & 0xff00) << 8 |
               uStack_40 << 0x18;
          uVar10 = uStack_3c >> 0x18 | (uStack_3c & 0xff0000) >> 8 | (uStack_3c & 0xff00) << 8 |
                   uStack_3c << 0x18;
        }
        bVar8 = bVar8 + 1;
        *(uint *)(param_2 + 0x80 + uVar12 * 0x28) = uVar10;
      } while (bVar8 < *(byte *)(param_2 + 0x39));
    }
  }
  return uVar16;
}



===== ExtractNakNcfSequences @ 14001123c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint ExtractNakNcfSequences(longlong param_1,uint param_2,uint *param_3,uint *param_4,byte param_5)

{
  short *psVar1;
  ushort uVar2;
  int iVar3;
  undefined2 uVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  uint uVar8;
  undefined *puVar9;
  char *pcVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  undefined1 auStackY_c8 [32];
  ushort local_84;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStackY_c8;
  uVar14 = ~(param_5 - 1);
  uVar13 = 0;
  memset(param_3,0,0x180);
  *(ushort *)((longlong)param_3 + 0xfe) = ((short)*(char *)(param_1 + 5) >> 0xf & 1U) + 1;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  if (((*(byte *)(param_1 + 5) & 1) == 0) ||
     (iVar3 = ProcessOptions((char *)(param_1 + 0x24),param_2,*(byte *)(param_1 + 4) & 0xf,
                             (longlong)&local_70,(longlong)param_3), -1 < iVar3)) {
    uVar7 = *(uint *)(param_1 + 0x10);
    uVar7 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18;
    *param_3 = uVar7;
    uVar2 = (short)param_3[0x3f] + 1;
    *(ushort *)(param_3 + 0x3f) = uVar2;
    if (param_4 == (uint *)0x0) {
      uVar12 = param_3[(ulonglong)uVar2 - 1] + (uint)param_5;
    }
    else {
      uVar12 = *param_4;
    }
    uVar7 = uVar7 - param_5;
    uVar8 = uVar14 & uVar12;
    uVar6 = 0;
    while( true ) {
      puVar9 = (undefined *)(ulonglong)uVar8;
      uVar5 = (uint)uVar6;
      if ((ushort)param_3[0x3f] <= uVar5) break;
      uVar13 = param_3[uVar6];
      uVar11 = uVar14 & uVar13;
      local_84 = (ushort)(param_5 - 1);
      local_84 = (ushort)uVar13 & local_84;
      param_3[uVar6] = uVar11;
      *(ushort *)((longlong)param_3 + uVar6 * 2 + 0x100) = local_84;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
        WPP_SF_dddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,
                    &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,uVar5,(char)uVar11,(char)uVar13
                    ,(char)local_84);
      }
      puVar9 = (undefined *)(ulonglong)uVar8;
      if ((int)(uVar13 - uVar7) < 1) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0xc000021b;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
          return 0xc000021b;
        }
        uVar4 = 0x40;
LAB_14001150e:
        WPP_SF_dDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
                   &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,uVar5,(char)uVar7,(char)uVar13);
        return 0xc000021b;
      }
      if (*(short *)((longlong)param_3 + 0xfe) == 1) {
        if (-1 < (int)(uVar13 - uVar12)) {
          *(short *)(param_3 + 0x3f) = (short)uVar6;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
            uVar4 = 0x42;
            uVar11 = uVar13;
            uVar8 = uVar12;
LAB_14001146a:
            puVar9 = &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids;
            WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
                      &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,uVar11,(char)uVar8);
          }
          break;
        }
        uVar7 = uVar13;
      }
      else {
        if ((int)(uVar11 - uVar7) < 1) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return 0xc000021b;
          }
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
            return 0xc000021b;
          }
          uVar4 = 0x43;
          goto LAB_14001150e;
        }
        if (-1 < (int)(uVar11 - uVar8)) {
          *(short *)(param_3 + 0x3f) = (short)uVar6;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
            uVar4 = 0x44;
            goto LAB_14001146a;
          }
          break;
        }
        psVar1 = (short *)((longlong)param_3 + uVar6 * 2 + 0x100);
        *psVar1 = *psVar1 + 1;
        uVar7 = uVar11;
      }
      uVar6 = (ulonglong)(uVar5 + 1);
    }
    if ((short)param_3[0x3f] != 0) {
      if (param_4 != (uint *)0x0) {
        *param_4 = uVar7;
      }
      return ~-(uint)((short)param_3[0x3f] != 0) & 0xc0000001;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      pcVar10 = "Parity";
      if (*(short *)((longlong)param_3 + 0xfe) != 2) {
        pcVar10 = "Selective";
      }
      WPP_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),"Selective",puVar9,pcVar10,(char)uVar13);
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,
             &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,iVar3);
  }
  return 0xc000021b;
}



===== Feature_1533700408__private_IsEnabledDeviceUsageNoInline @ 14001158c =====

ulonglong Feature_1533700408__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_1533700408__private_featureState;
  if ((Feature_1533700408__private_featureState & 0x10) == 0) {
    uVar1 = Feature_1533700408__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_1533700408__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_1533700408__private_IsEnabledFallback @ 1400115c4 =====

void Feature_1533700408__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_1533700408__private_descriptor);
  return;
}



===== Feature_3579806010__private_IsEnabledDeviceUsageNoInline @ 1400115e0 =====

ulonglong Feature_3579806010__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_3579806010__private_featureState;
  if ((Feature_3579806010__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3579806010__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3579806010__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3579806010__private_IsEnabledFallback @ 140011618 =====

void Feature_3579806010__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_3579806010__private_descriptor);
  return;
}



===== Feature_4275546425__private_IsEnabledDeviceUsageNoInline @ 140011634 =====

ulonglong Feature_4275546425__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_4275546425__private_featureState;
  if ((Feature_4275546425__private_featureState & 0x10) == 0) {
    uVar1 = Feature_4275546425__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_4275546425__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_4275546425__private_IsEnabledFallback @ 14001166c =====

void Feature_4275546425__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_4275546425__private_descriptor);
  return;
}



===== Feature_951217465__private_IsEnabledDeviceUsageNoInline @ 140011688 =====

ulonglong Feature_951217465__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_951217465__private_featureState;
  if ((Feature_951217465__private_featureState & 0x10) == 0) {
    uVar1 = Feature_951217465__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_951217465__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_951217465__private_IsEnabledFallback @ 1400116c0 =====

void Feature_951217465__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_951217465__private_descriptor);
  return;
}



===== FreeDataBuffer @ 1400116dc =====

void FreeDataBuffer(longlong param_1,longlong *param_2)

{
  int *piVar1;
  longlong lVar2;
  
  lVar2 = *param_2;
  if (lVar2 != 0) {
    if ((*(uint *)((longlong)param_2 + 0x24) & 1) == 0) {
      ExFreePoolWithTag(lVar2,0);
    }
    else {
      ExFreeToNPagedLookasideList(*(longlong *)(param_1 + 0x30) + 0x140,lVar2);
      piVar1 = (int *)(*(longlong *)(param_1 + 0x30) + 0x11c);
      *piVar1 = *piVar1 + -1;
      if ((*piVar1 == 0) && ((*(uint *)(param_1 + 0x20) & 0x8000) == 0)) {
        piVar1 = (int *)(*(longlong *)(param_1 + 0x30) + 0x114);
        *piVar1 = *piVar1 + 100;
        *(undefined4 *)(*(longlong *)(param_1 + 0x30) + 0x118) =
             *(undefined4 *)(*(longlong *)(param_1 + 0x30) + 0x114);
        *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x8000;
        ExDeleteNPagedLookasideList(*(longlong *)(param_1 + 0x30) + 0x140);
        lVar2 = *(longlong *)(param_1 + 0x30);
        ExInitializeNPagedLookasideList
                  (lVar2 + 0x140,0,0,0x200,*(undefined4 *)(lVar2 + 0x118),0x446d6750,
                   *(undefined2 *)(lVar2 + 0x120));
      }
      *(uint *)((longlong)param_2 + 0x24) = *(uint *)((longlong)param_2 + 0x24) & 0xfffffffe;
    }
    *param_2 = 0;
    *(undefined4 *)(param_2 + 2) = 0;
  }
  return;
}



===== FreeNakContext @ 1400117ec =====

void FreeNakContext(longlong param_1,longlong param_2)

{
  longlong lVar1;
  byte bVar2;
  ulonglong uVar3;
  longlong *plVar4;
  
  bVar2 = *(char *)(param_2 + 0x3b) + *(char *)(param_2 + 0x3a);
  if (bVar2 != 0) {
    plVar4 = (longlong *)(param_2 + 0x60);
    uVar3 = (ulonglong)bVar2;
    do {
      FreeDataBuffer(param_1,plVar4);
      plVar4 = plVar4 + 5;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  if (*(byte *)(param_2 + 0x3e) < 2) {
    lVar1 = *(longlong *)(param_1 + 0x30) + 0x1c0;
  }
  else {
    lVar1 = *(longlong *)(param_1 + 0x30) + 0x240;
  }
  ExFreeToNPagedLookasideList(lVar1,param_2);
  return;
}



===== PgmCancelReceiveIrp @ 140011870 =====

void PgmCancelReceiveIrp(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  longlong *plVar6;
  longlong lVar7;
  undefined1 *puVar8;
  undefined1 auStackY_38 [8];
  undefined1 auStackY_30 [24];
  
  uVar5 = 0;
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  lVar2 = *(longlong *)(lVar1 + 0x18);
  if ((lVar2 == 0) || (*(int *)(lVar2 + 0x10) != 0x52534553)) {
    IoReleaseCancelSpinLock(CONCAT71((int7)((ulonglong)lVar1 >> 8),*(undefined1 *)(param_2 + 0x45)))
    ;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      if (lVar2 != 0) {
        uVar5 = (undefined1)*(undefined8 *)(*(longlong *)(lVar2 + 0x30) + 0x18);
      }
      WPP_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xbf,
                 &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,param_2,(char)lVar2,uVar5);
    }
  }
  else {
    lVar1 = lVar2 + 0x168;
    uVar5 = KeAcquireSpinLockRaiseToDpc(lVar1);
    puVar8 = auStackY_38;
    lVar7 = *(longlong *)(lVar2 + 0x30);
    if (param_2 == *(longlong *)(lVar7 + 0xe8)) {
      *(ulonglong *)(param_2 + 0x38) = (ulonglong)*(uint *)(lVar7 + 0xf4);
      *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
      *(undefined4 *)(*(longlong *)(lVar2 + 0x30) + 0xf0) = 0;
      lVar7 = *(longlong *)(lVar2 + 0x30);
      *(undefined4 *)(lVar7 + 0xf4) = 0;
      *(undefined8 *)(*(longlong *)(lVar2 + 0x30) + 0xe8) = 0;
    }
    else {
      plVar6 = (longlong *)(lVar7 + 200);
      do {
        plVar6 = (longlong *)*plVar6;
        if (plVar6 == (longlong *)(lVar7 + 200)) goto LAB_140011986;
      } while (plVar6 != (longlong *)(param_2 + 0xa8));
      lVar7 = *plVar6;
      if (((longlong *)*(longlong *)(lVar7 + 8) != plVar6) ||
         (plVar3 = (longlong *)plVar6[1], (longlong *)*plVar3 != plVar6)) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        puVar8 = auStackY_30;
LAB_140011986:
        *(undefined8 *)(puVar8 + -8) = 0x140011993;
        KeReleaseSpinLock(lVar1,uVar5);
        uVar5 = *(undefined1 *)(param_2 + 0x45);
        *(undefined8 *)(puVar8 + -8) = 0x1400119a2;
        IoReleaseCancelSpinLock(uVar5);
        return;
      }
      *plVar3 = lVar7;
      *(longlong **)(lVar7 + 8) = plVar3;
      *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
      *(undefined8 *)(param_2 + 0x38) = 0;
    }
    KeReleaseSpinLock(lVar1,CONCAT71((int7)((ulonglong)lVar7 >> 8),uVar5));
    IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
    IofCompleteRequest(param_2,2);
  }
  return;
}



===== PgmHandleNewData @ 140011a20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PgmHandleNewData(uint *param_1,ulonglong param_2,longlong param_3,ushort param_4,
                          void *param_5,char param_6,undefined1 *param_7,undefined1 *param_8)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  longlong lVar6;
  longlong *plVar7;
  undefined8 uVar8;
  code *pcVar9;
  longlong *plVar10;
  uint uVar11;
  uint uVar12;
  ulonglong uVar13;
  void *pvVar14;
  byte bVar15;
  undefined2 uVar16;
  uint uVar17;
  uint *puVar18;
  undefined1 *puVar19;
  ulonglong uVar20;
  undefined *puVar21;
  uint uVar22;
  longlong **pplVar23;
  undefined *puVar24;
  undefined8 *puVar25;
  longlong lVar26;
  char cVar27;
  byte bVar28;
  ushort uVar29;
  int iVar30;
  uint uVar31;
  undefined1 auStackY_108 [8];
  undefined1 auStackY_100 [24];
  ushort uVar32;
  uint local_b4;
  ushort local_b0;
  char local_ae;
  uint local_ac;
  uint local_a8;
  uint local_a4;
  longlong *local_a0;
  void *local_98;
  ulonglong local_90;
  undefined1 *local_88;
  undefined1 *local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_108;
  lVar6 = *(longlong *)(param_3 + 0x30);
  pplVar23 = &local_a0;
  local_80 = param_7;
  local_88 = param_8;
  local_b4 = *param_1;
  bVar1 = *(byte *)((longlong)param_5 + 5);
  uVar22 = 1;
  puVar18 = &local_b4;
  local_98 = param_5;
  local_a0 = (longlong *)0x0;
  local_b0 = param_4;
  local_90 = param_2;
  uVar13 = CheckAndAddNakRequests(param_3,puVar18,pplVar23,1,(byte)~bVar1 >> 7);
  plVar10 = local_a0;
  uVar20 = uVar13 & 0xffffffff;
  if (((int)uVar13 < 0) || (local_a0 == (longlong *)0x0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      WPP_SF_dDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar18,pplVar23,local_b4,(char)uVar13,
                 (char)local_a0);
    }
    if ((int)uVar13 < 0) {
LAB_140011b42:
      *(longlong *)(lVar6 + 0x358) = *(longlong *)(lVar6 + 0x358) + 1;
    }
    else {
      *(longlong *)(lVar6 + 0x360) = *(longlong *)(lVar6 + 0x360) + 1;
    }
LAB_140011b49:
    puVar19 = auStackY_108;
    goto LAB_140011b4b;
  }
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if ((*(byte *)((longlong)param_5 + 5) & 1) != 0) {
    puVar25 = &local_78;
    uVar11 = ProcessOptions((char *)((longlong)param_5 + 0x18),param_4 - 0x18,
                            *(byte *)((longlong)param_5 + 4) & 0xf,(longlong)puVar25,0);
    uVar22 = (uint)puVar25;
    uVar20 = (ulonglong)uVar11;
    if ((int)uVar11 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_dDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6d,
                   &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,uVar11,(char)local_b4,
                   (char)*(undefined4 *)(lVar6 + 0x104));
      }
      goto LAB_140011b42;
    }
  }
  uVar2 = *(ushort *)((longlong)param_5 + 0xe);
  uVar29 = uVar2 >> 8 | uVar2 << 8;
  if ((ulonglong)param_4 != (ulonglong)uVar29 + (local_78 >> 0x10 & 0xffff) + 0x18) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      uVar22 = (uint)local_b0;
      WPP_SF_dddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6e,
                  &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,(uint)local_b0,0x18,
                  (char)(local_78 >> 0x10),(char)(uVar2 >> 8));
    }
    goto LAB_140011c5f;
  }
  if ((char)bVar1 < '\0') {
    uVar3 = *(ushort *)((longlong)plVar10 + 0x34);
    if (uVar3 == 0) {
      if (uVar29 < 2) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          uVar16 = 0x70;
          uVar32 = 2;
          uVar3 = uVar29;
          goto LAB_140011c4f;
        }
        goto LAB_140011c5f;
      }
    }
    else if (uVar3 != uVar29) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        uVar16 = 0x6f;
        uVar32 = uVar29;
LAB_140011c4f:
        uVar22 = (uint)uVar3;
        WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar16,
                  &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,(uint)uVar3,(char)uVar32);
      }
LAB_140011c5f:
      uVar20 = 0xc000021b;
    }
  }
  uVar11 = (uint)uVar20;
  if (0xffff < (ulonglong)*(ushort *)((longlong)plVar10 + 0x34) + 0x10) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x71,
               &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,(uint)uVar29);
    }
    goto LAB_140011ee6;
  }
  if ((int)uVar11 < 0) goto LAB_140011b42;
  local_a4 = local_78._2_2_ + 0x18;
  local_ac = 0;
  local_a8 = (uint)uVar29;
  if ((local_78 & 0x80000000000) != 0) {
    if (*(char *)((longlong)plVar10 + 0x3e) == '\x01') {
      *(byte *)((longlong)plVar10 + 0x3d) = uStack_60._5_1_;
      goto LAB_140011d29;
    }
    if (uStack_60._5_1_ < *(byte *)(param_3 + 0xa0)) {
      if (*(byte *)((longlong)plVar10 + 0x39) == *(byte *)(param_3 + 0xa0)) {
        *(byte *)((longlong)plVar10 + 0x39) = uStack_60._5_1_;
        if ((int)plVar10[2] == *(int *)(lVar6 + 0x3c)) {
          *(uint *)(lVar6 + 0x40) = (int)plVar10[2] + (uStack_60._5_1_ - 1);
        }
        RemoveRedundantNaks(param_3,(longlong)plVar10,'\x01');
      }
      else if (*(byte *)((longlong)plVar10 + 0x39) != uStack_60._5_1_) goto LAB_140011ee6;
      goto LAB_140011d29;
    }
LAB_140011ee6:
    uVar20 = 0xc000021b;
    goto LAB_140011b42;
  }
LAB_140011d29:
  if ((local_78 & 0x4000000000) != 0) {
    if ((char)bVar1 < '\0') {
      *(uint *)(lVar6 + 0x44) = (*(byte *)((longlong)plVar10 + 0x39) - 1) + (int)plVar10[2];
    }
    else {
      *(uint *)(lVar6 + 0x44) = local_b4;
    }
    *(uint *)(param_3 + 0x20) = *(uint *)(param_3 + 0x20) | 0x80;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      uVar22 = *(uint *)(lVar6 + 0x44);
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x72,
               &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,uVar22);
    }
    *(char *)((longlong)plVar10 + 0x39) = (*(char *)(lVar6 + 0x44) - (char)plVar10[2]) + '\x01';
    RemoveRedundantNaks(param_3,(longlong)plVar10,'\x01');
    AdjustReceiveBufferLists(param_3);
  }
  pvVar14 = (void *)0x0;
  local_ae = '\0';
  if (*(char *)(param_3 + 0xa1) == '\0') {
    if ((char)bVar1 < '\0') goto LAB_140011ee6;
    uVar31 = (uint)(byte)uVar2 << 8;
    local_a0 = (longlong *)CONCAT44(local_a0._4_4_,uVar31);
    if (((local_b4 != *(uint *)(lVar6 + 0x34)) || ((*(uint *)(param_3 + 0x20) & 0xc00) != 0)) ||
       (*(longlong **)(lVar6 + 0x78) != (longlong *)(lVar6 + 0x78))) goto LAB_14001214b;
    puVar24 = (undefined *)(ulonglong)local_68._4_4_;
    if (((*(uint *)(param_3 + 0x20) & 8) == 0) || (local_68._4_4_ == 0)) {
      uVar22 = *(uint *)(lVar6 + 0x100);
      puVar19 = auStackY_108;
      uVar11 = (uint)uStack_60;
      if ((uVar22 == local_68._4_4_) &&
         ((uVar22 == 0 || (puVar19 = auStackY_108, *(uint *)(lVar6 + 0xfc) == (uint)uStack_60)))) {
        puVar21 = (undefined *)(ulonglong)local_a8;
        goto LAB_140011fa1;
      }
    }
    else {
      uVar11 = local_b4;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
        uVar22 = *(uint *)(*(longlong *)(param_3 + 0x30) + 0x34);
        puVar24 = &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids;
        WPP_SF_dDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x74,
                   &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,uVar22,
                   (char)((ulonglong)local_68 >> 0x20),(char)uStack_60);
      }
      puVar21 = (undefined *)0x0;
      local_a8 = 0;
LAB_140011fa1:
      uVar12 = (uint)puVar21;
      pvVar14 = (void *)0x0;
      lVar26 = *plVar10;
      if (*(longlong **)(lVar26 + 8) == plVar10) {
        plVar7 = (longlong *)plVar10[1];
        if ((longlong *)*plVar7 == plVar10) {
          *plVar7 = lVar26;
          *(longlong **)(lVar26 + 8) = plVar7;
          RemovePendingReceiverEntry((longlong)plVar10);
          uVar22 = *(int *)(lVar6 + 0x34) + 1;
          *(uint *)(lVar6 + 0x34) = uVar22;
          *(uint *)(lVar6 + 0x38) = uVar22;
          uVar17 = uVar12;
          if ((uint)uStack_60 != 0) {
            uVar17 = (uint)uStack_60;
          }
          uVar11 = (uint)uStack_60;
          if ((uVar12 == 0) || (local_68._4_4_ == uVar17)) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
              WPP_SF_dDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x76,
                         &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,uVar22,
                         (char)((ulonglong)local_68 >> 0x20),(char)uStack_60);
              pvVar14 = (void *)0x0;
            }
            uVar20 = (ulonglong)pvVar14 & 0xffffffff;
            local_ac = uVar12;
LAB_1400120eb:
            if ((uint)puVar21 != local_a8) {
              plVar7 = (longlong *)(lVar6 + 0x78);
              local_ae = '\x01';
              lVar26 = *plVar7;
              puVar24 = puVar21;
              if (*(longlong **)(lVar26 + 8) == plVar7) {
                *plVar10 = lVar26;
                plVar10[1] = (longlong)plVar7;
                *(longlong **)(lVar26 + 8) = plVar10;
                *plVar7 = (longlong)plVar10;
                goto LAB_14001214b;
              }
              goto LAB_1400121fb;
            }
          }
          else {
            lVar26 = (ulonglong)local_a4 + (longlong)local_98;
            *(uint *)(param_3 + 0x20) = *(uint *)(param_3 + 0x20) | 0x400;
            uVar12 = PgmIndicateToClient(local_90,param_3,uVar12,lVar26,local_68._4_4_,uVar17,
                                         &local_ac,local_80,local_88);
            uVar22 = (uint)lVar26;
            puVar21 = (undefined *)(ulonglong)local_ac;
            uVar20 = (ulonglong)uVar12;
            *(uint *)(param_3 + 0x20) = *(uint *)(param_3 + 0x20) & 0xfffffbf7;
            *(longlong *)(param_3 + 0xb8) = (longlong)(puVar21 + *(longlong *)(param_3 + 0xb8));
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
              uVar22 = local_b4;
              WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x77,
                        &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,local_b4,(char)uVar12);
              puVar21 = (undefined *)(ulonglong)local_ac;
            }
            if (((uVar12 + 0x80000000 & 0x80000000) != 0) || (uVar12 == 0xc000021b)) {
              pvVar14 = (void *)0x0;
              goto LAB_1400120eb;
            }
            *(uint *)(param_3 + 0x20) = *(uint *)(param_3 + 0x20) | 0x100;
            local_ac = local_a8;
          }
          if ((param_6 == '\x05') && (plVar10[5] != 0)) {
            AdjustNcfRDataResponseTimes(param_3,(longlong)plVar10);
          }
          FreeNakContext(param_3,(longlong)plVar10);
          AdjustReceiveBufferLists(param_3);
          goto LAB_140011b49;
        }
      }
LAB_1400121fb:
      pcVar9 = (code *)swi(0x29);
      (*pcVar9)(3);
      puVar19 = auStackY_100;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      uVar4 = *(undefined4 *)(lVar6 + 0xfc);
      uVar8 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      *(int *)(puVar19 + 0x38) = (int)puVar24;
      *(uint *)(puVar19 + 0x30) = uVar11;
      *(uint *)(puVar19 + 0x28) = uVar22;
      uVar5 = *(undefined4 *)(lVar6 + 0x34);
      *(undefined4 *)(puVar19 + 0x20) = uVar4;
      *(undefined8 *)(puVar19 + -8) = 0x140012241;
      WPP_SF_ddddd(uVar8,0x75,puVar24,uVar5,puVar19[0x20],puVar19[0x28],puVar19[0x30],puVar19[0x38])
      ;
    }
    *(uint *)(param_3 + 0x20) = *(uint *)(param_3 + 0x20) | 0x100;
    uVar20 = 0xc0000001;
    goto LAB_140011b4b;
  }
  iVar30 = *(byte *)(param_3 + 0xa0) - 1;
  bVar28 = (byte)iVar30 & (byte)local_b4;
  uVar31 = CONCAT31((int3)((uint)iVar30 >> 8),bVar28);
  local_a0 = (longlong *)CONCAT44(local_a0._4_4_,uVar31);
  if ((char)bVar1 < '\0') {
    if (((uint)*(byte *)((longlong)plVar10 + 0x3b) + (uint)*(byte *)((longlong)plVar10 + 0x3a) <
         (uint)*(byte *)((longlong)plVar10 + 0x39)) &&
       ((uint)*(byte *)((longlong)plVar10 + 0x3f) + (uint)*(byte *)((longlong)plVar10 + 0x3a) <
        (uint)*(byte *)((longlong)plVar10 + 0x39))) {
      if ((local_78 & 0x40000000000) == 0) goto LAB_140011ea3;
      if (uStack_60._4_1_ == 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x73,
                  &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids);
        }
      }
      else {
        uVar22 = (uint)*(byte *)(param_3 + 0xa0) * (uint)uStack_60._4_1_;
        if (uVar22 < 0x100) {
          uVar11 = uVar31 + uVar22;
          bVar15 = (byte)uVar22;
          bVar28 = (byte)uVar11;
          uVar31 = 0xff;
          if (bVar28 >= bVar15) {
            uVar31 = uVar11 & 0xff;
          }
          uVar11 = -(uint)(bVar28 < bVar15) & 0xc0000095;
          local_a0 = (longlong *)CONCAT44(local_a0._4_4_,uVar31);
          if (bVar15 <= bVar28) goto LAB_140011e9b;
        }
      }
    }
    uVar11 = 0xc000021b;
LAB_140011e41:
    AdjustReceiveBufferLists(param_3);
LAB_140011e4c:
    puVar19 = auStackY_108;
    pvVar14 = (void *)0x0;
    if (uVar11 == 0xc000021b) {
      *(longlong *)(lVar6 + 0x360) = *(longlong *)(lVar6 + 0x360) + 1;
      uVar20 = 0xc000021b;
      goto LAB_140011b4b;
    }
  }
  else {
    if ((*(byte *)((longlong)plVar10 + 0x39) <= bVar28) ||
       (bVar28 < *(byte *)((longlong)plVar10 + 0x3f))) {
      uVar11 = 0xc000021b;
LAB_140011e9b:
      if (uVar11 == 0xc000021b) goto LAB_140011e41;
    }
LAB_140011ea3:
    bVar28 = 0;
    uVar22 = (uint)*(byte *)((longlong)plVar10 + 0x3b) + (uint)*(byte *)((longlong)plVar10 + 0x3a);
    if (uVar22 != 0) {
      do {
        if (*(char *)((longlong)plVar10 + (ulonglong)bVar28 * 0x28 + 0x74) == (char)uVar31) {
          uVar11 = 0xc000021b;
          break;
        }
        bVar28 = bVar28 + 1;
      } while (bVar28 < uVar22);
      goto LAB_140011e4c;
    }
  }
LAB_14001214b:
  if (MaxPacketGroupsPendingClient < *(uint *)(lVar6 + 0x110)) {
    MaxPacketGroupsPendingClient = *(uint *)(lVar6 + 0x110);
  }
  uVar22 = *(uint *)(lVar6 + 0x104);
  if (MaxPacketsBuffered <= uVar22) {
    MaxPacketsBuffered = uVar22;
  }
  if (MaxPacketsPendingIndicate <= *(uint *)(lVar6 + 0x108)) {
    MaxPacketsPendingIndicate = *(uint *)(lVar6 + 0x108);
  }
  if (MaxPacketsPendingNaks <= *(uint *)(lVar6 + 0x10c)) {
    MaxPacketsPendingNaks = *(uint *)(lVar6 + 0x10c);
  }
  if (uVar22 < *(ushort *)(lVar6 + 0x120)) {
    bVar28 = *(char *)((longlong)plVar10 + 0x3a) + *(char *)((longlong)plVar10 + 0x3b);
    if ((char)bVar1 < '\0') {
      uVar13 = (ulonglong)bVar28;
      local_90 = uVar13;
      pvVar14 = (void *)AllocateDataBuffer(param_3,plVar10 + uVar13 * 5 + 0xc,local_b0 + 0xe);
      uVar2 = local_b0;
      if (pvVar14 != (void *)0x0) {
        uVar22 = (uint)local_b0;
        memmove(pvVar14,local_98,(ulonglong)local_b0);
        *(ushort *)(plVar10 + uVar13 * 5 + 0xe) = uVar2;
        *(short *)((longlong)plVar10 + uVar13 * 0x28 + 0x72) = (short)local_a4;
        *(char *)((longlong)plVar10 + uVar13 * 0x28 + 0x74) = (char)uVar31;
        *(undefined1 *)((longlong)plVar10 + uVar13 * 0x28 + 0x77) = uStack_60._6_1_;
        *(undefined4 *)(plVar10 + local_90 * 5 + 0xf) = (undefined4)local_68;
        *(uint *)(plVar10 + uVar13 * 5 + 0x10) = (uint)uStack_60;
        *(uint *)((longlong)plVar10 + uVar13 * 0x28 + 0x7c) = local_ac + local_68._4_4_;
        *(char *)((longlong)plVar10 + 0x3b) = *(char *)((longlong)plVar10 + 0x3b) + '\x01';
        *(longlong *)(param_3 + 0xb8) =
             *(longlong *)(param_3 + 0xb8) + (ulonglong)(uVar22 - local_a4);
        if (*(short *)((longlong)plVar10 + 0x34) == 0) {
          *(ushort *)((longlong)plVar10 + 0x34) = uVar2 - (short)local_a4;
        }
        goto LAB_1400124b7;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        uVar16 = 0x7a;
        goto LAB_1400123df;
      }
    }
    else {
      uVar22 = (uint)*(ushort *)((longlong)plVar10 + 0x36);
      if ((ulonglong)*(ushort *)((longlong)plVar10 + 0x36) < (ulonglong)local_b0 + 0x10) {
        uVar22 = local_b0 + 0x10;
      }
      bVar1 = *(byte *)((longlong)plVar10 + 0x39);
      if (bVar1 <= bVar28) {
        bVar28 = (byte)pvVar14;
        if (bVar1 != 0) {
          do {
            if (*(byte *)((longlong)plVar10 + 0x3e) <=
                *(byte *)((longlong)plVar10 + (ulonglong)bVar28 * 0x28 + 0x74)) {
              pvVar14 = (void *)ReAllocateDataBuffer
                                          (param_3,plVar10 + (ulonglong)bVar28 * 5 + 0xc,uVar22);
              uVar22 = 0;
              break;
            }
            bVar28 = bVar28 + 1;
          } while (bVar28 < bVar1);
        }
        *(char *)((longlong)plVar10 + 0x3b) = *(char *)((longlong)plVar10 + 0x3b) + -1;
      }
      uVar13 = (ulonglong)bVar28;
      if (uVar22 != 0) {
        pvVar14 = (void *)AllocateDataBuffer(param_3,plVar10 + uVar13 * 5 + 0xc,uVar22);
      }
      uVar2 = local_b0;
      if (pvVar14 != (void *)0x0) {
        uVar22 = (uint)local_b0;
        memmove(pvVar14,local_98,(ulonglong)local_b0);
        *(ushort *)(plVar10 + uVar13 * 5 + 0xe) = uVar2;
        *(short *)((longlong)plVar10 + uVar13 * 0x28 + 0x72) = (short)local_ac + (short)local_a4;
        *(char *)((longlong)plVar10 + uVar13 * 0x28 + 0x74) = (char)local_a0;
        *(byte *)((longlong)plVar10 + (ulonglong)((uint)local_a0 & 0xff) * 0x28 + 0x75) = bVar28;
        *(char *)((longlong)plVar10 + 0x3a) = *(char *)((longlong)plVar10 + 0x3a) + '\x01';
        *(longlong *)(param_3 + 0xb8) =
             *(longlong *)(param_3 + 0xb8) + (ulonglong)((uVar22 - local_ac) - local_a4);
        if ((local_78 & 0x100000000) == 0) {
          *(undefined1 *)((longlong)plVar10 + uVar13 * 0x28 + 0x77) = 0x80;
          *(uint *)(plVar10 + uVar13 * 5 + 0xf) = ((uint)local_a0 & 0xff) + (int)plVar10[2];
          *(uint *)((longlong)plVar10 + uVar13 * 0x28 + 0x7c) = local_ac;
          *(uint *)(plVar10 + uVar13 * 5 + 0x10) = uVar2 - local_a4;
        }
        else {
          *(undefined1 *)((longlong)plVar10 + uVar13 * 0x28 + 0x77) = 0;
          *(undefined4 *)(plVar10 + uVar13 * 5 + 0xf) = (undefined4)local_68;
          *(uint *)(plVar10 + uVar13 * 5 + 0x10) = (uint)uStack_60;
          *(uint *)((longlong)plVar10 + uVar13 * 0x28 + 0x7c) = local_ac + local_68._4_4_;
        }
LAB_1400124b7:
        cVar27 = '\0';
        if ((param_6 == '\x05') && (plVar10[5] != 0)) {
          if (((uint)*(byte *)((longlong)plVar10 + 0x39) <=
               (uint)*(byte *)((longlong)plVar10 + 0x3b) + (uint)*(byte *)((longlong)plVar10 + 0x3a)
              ) || ((uint)*(byte *)((longlong)plVar10 + 0x39) <=
                    (uint)*(byte *)((longlong)plVar10 + 0x3f) +
                    (uint)*(byte *)((longlong)plVar10 + 0x3a))) {
            cVar27 = '\0';
            AdjustNcfRDataResponseTimes(param_3,(longlong)plVar10);
          }
        }
        *(uint *)(plVar10 + 6) = *(uint *)(plVar10 + 6) | local_78._4_4_;
        *(int *)(lVar6 + 0x104) = *(int *)(lVar6 + 0x104) + 1;
        if (local_ae == cVar27) {
          *(int *)(lVar6 + 0x10c) = *(int *)(lVar6 + 0x10c) + 1;
          if (((uint)*(byte *)((longlong)plVar10 + 0x39) <=
               (uint)*(byte *)((longlong)plVar10 + 0x3b) + (uint)*(byte *)((longlong)plVar10 + 0x3a)
              ) || ((uint)*(byte *)((longlong)plVar10 + 0x39) <=
                    (uint)*(byte *)((longlong)plVar10 + 0x3f) +
                    (uint)*(byte *)((longlong)plVar10 + 0x3a))) {
            RemovePendingReceiverEntry((longlong)plVar10);
            AdjustReceiveBufferLists(param_3);
          }
        }
        else {
          *(int *)(lVar6 + 0x110) = *(int *)(lVar6 + 0x110) + 1;
          *(int *)(lVar6 + 0x108) = *(int *)(lVar6 + 0x108) + 1;
          *(uint *)(lVar6 + 0x34) = local_b4;
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
          WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7b,
                    &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,local_b4,
                    (char)*(undefined4 *)(lVar6 + 0x104));
        }
        CheckDeferredCleanup(param_3);
        puVar19 = auStackY_108;
        uVar20 = 0;
        goto LAB_140011b4b;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        uVar2 = *(ushort *)((longlong)plVar10 + 0x36);
        uVar16 = 0x79;
LAB_1400123df:
        WPP_SF_dDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar16,
                   &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,local_b4,(char)uVar2,
                   (char)*(undefined4 *)(lVar6 + 0x104));
      }
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_dddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x78,
                &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,*(undefined4 *)(lVar6 + 0x38),
                (char)local_b4,(char)uVar22,(char)*(ushort *)(lVar6 + 0x120));
  }
  puVar19 = auStackY_108;
  *(uint *)(param_3 + 0x20) = *(uint *)(param_3 + 0x20) | 0x100;
  uVar20 = 0xc000009a;
LAB_140011b4b:
  *(undefined8 *)(puVar19 + -8) = 0x140011b57;
  return uVar20;
}



===== PgmIndicateGroup @ 1400125d8 =====

int PgmIndicateGroup(longlong param_1,longlong param_2,undefined1 *param_3,undefined1 *param_4,
                    longlong param_5)

{
  longlong *plVar1;
  int *piVar2;
  short *psVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  undefined2 uVar8;
  byte bVar9;
  uint uVar10;
  undefined *puVar11;
  int iVar12;
  ulonglong uVar13;
  uint uVar14;
  uint uVar15;
  uint local_48 [4];
  
  iVar7 = 0;
  local_48[0] = 0;
  bVar9 = *(byte *)(param_5 + 0x3f);
  puVar11 = param_3;
  do {
    while( true ) {
      if (*(byte *)(param_5 + 0x39) <= bVar9) {
        return iVar7;
      }
      uVar10 = *(uint *)(param_2 + 0x20);
      if ((uVar10 >> 0xd & 1) != 0) {
        return -0x3ffffde5;
      }
      bVar4 = *(byte *)(param_5 + 0x3e);
      bVar5 = *(byte *)(param_5 + 0x75 + (ulonglong)bVar9 * 0x28);
      uVar13 = (ulonglong)bVar5;
      if (bVar4 <= bVar5) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return -0x3ffffde5;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) == 0) {
          return -0x3ffffde5;
        }
        WPP_SF_cc(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)uVar10,
                  CONCAT71((int7)((ulonglong)puVar11 >> 8),bVar4),bVar5,bVar4);
        return -0x3ffffde5;
      }
      if ((uVar10 & 8) == 0) break;
      uVar15 = *(uint *)(param_5 + 0x7c + uVar13 * 0x28);
      puVar11 = (undefined *)(ulonglong)uVar15;
      if (uVar15 == 0) {
        *(uint *)(param_2 + 0x20) = uVar10 & 0xfffffff7;
        goto LAB_1400126eb;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
        puVar11 = &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids;
        WPP_SF_dDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5e,
                   &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,
                   (uint)bVar9 + *(int *)(*(longlong *)(param_2 + 0x30) + 0x34),(char)uVar15,
                   (char)*(undefined4 *)(param_5 + 0x80 + uVar13 * 0x28));
      }
LAB_14001269e:
      *(char *)(param_5 + 0x3f) = *(char *)(param_5 + 0x3f) + '\x01';
LAB_1400127b9:
      bVar9 = bVar9 + 1;
      iVar7 = 0;
    }
    uVar10 = *(uint *)(param_5 + 0x7c + uVar13 * 0x28);
    puVar11 = *(undefined **)(param_2 + 0x30);
    uVar15 = *(uint *)(puVar11 + 0x100);
    if ((uVar15 != uVar10) ||
       ((uVar15 != 0 && (*(int *)(puVar11 + 0xfc) != *(int *)(param_5 + 0x80 + uVar13 * 0x28))))) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3fffffff;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
        return -0x3fffffff;
      }
      iVar7 = *(int *)(param_5 + 0x80 + uVar13 * 0x28);
      uVar8 = 0x5f;
      uVar14 = *(uint *)(puVar11 + 0xfc);
      iVar12 = (uint)bVar9 + *(int *)(puVar11 + 0x34);
      goto LAB_140012846;
    }
LAB_1400126eb:
    uVar6 = (uint)*(ushort *)(param_5 + 0x72 + uVar13 * 0x28);
    uVar14 = *(ushort *)(param_5 + 0x70 + uVar13 * 0x28) - uVar6;
    if (uVar14 == 0) goto LAB_14001269e;
    uVar15 = *(uint *)(param_5 + 0x80 + uVar13 * 0x28);
    iVar7 = *(int *)(param_5 + 0x7c + uVar13 * 0x28);
    uVar10 = uVar15 - iVar7;
    puVar11 = (undefined *)(ulonglong)uVar10;
    if (uVar10 < uVar14) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3fffffff;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
        return -0x3fffffff;
      }
      uVar8 = 0x60;
      iVar12 = (uint)bVar9 + *(int *)(*(longlong *)(param_2 + 0x30) + 0x34);
LAB_140012846:
      WPP_SF_ddddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,puVar11,iVar12,(char)uVar14,
                   (char)uVar15,(char)iVar7,(char)uVar10);
      return -0x3fffffff;
    }
    local_48[0] = 0;
    puVar11 = (undefined *)(ulonglong)uVar14;
    iVar7 = PgmIndicateToClient(param_1,param_2,uVar14,
                                (ulonglong)uVar6 + *(longlong *)(param_5 + 0x60 + uVar13 * 0x28),
                                iVar7,uVar15,local_48,param_3,param_4);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
      puVar11 = &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids;
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x61,
                &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,*(undefined4 *)(param_5 + 0x10),
                (char)iVar7);
    }
    piVar2 = (int *)(param_5 + 0x7c + uVar13 * 0x28);
    *piVar2 = *piVar2 + local_48[0];
    psVar3 = (short *)(param_5 + 0x72 + uVar13 * 0x28);
    *psVar3 = *psVar3 + (short)local_48[0];
    if (local_48[0] == uVar14) {
      *(char *)(param_5 + 0x3f) = *(char *)(param_5 + 0x3f) + '\x01';
      plVar1 = (longlong *)(*(longlong *)(param_2 + 0x30) + 0x300);
      *plVar1 = *plVar1 + 1;
      goto LAB_1400127b9;
    }
    if (iVar7 < 0) {
      return iVar7;
    }
  } while( true );
}



===== PgmIndicateToClient @ 1400128a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PgmIndicateToClient(longlong param_1,longlong param_2,uint param_3,longlong param_4,int param_5,
                       uint param_6,uint *param_7,undefined1 *param_8,undefined1 *param_9)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined8 uVar5;
  code *pcVar6;
  undefined1 uVar7;
  char cVar8;
  int iVar9;
  undefined8 uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  longlong lVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  longlong lVar17;
  uint uVar18;
  int local_res10;
  uint local_res18 [2];
  longlong local_res20;
  undefined1 auStackY_b8 [8];
  undefined1 auStackY_b0 [24];
  longlong *local_60;
  longlong local_58;
  longlong local_50;
  
  local_res18[0] = 0;
  lVar2 = *(longlong *)(param_2 + 0x30);
  local_res20 = param_4;
  if ((*(uint *)(param_2 + 0x20) & 0x2100) != 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x53,
               &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,param_2);
    }
    iVar9 = -0x3ffffde5;
LAB_140012957:
    *param_7 = 0;
    return iVar9;
  }
  if (ConfiguredMaxPacketSize < param_6) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x54,
               &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,param_6);
    }
    iVar9 = -0x3fffffff;
    goto LAB_140012957;
  }
  local_res10 = param_6 - param_5;
  *(uint *)(lVar2 + 0xfc) = param_6;
  *(int *)(lVar2 + 0x100) = param_5;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
    WPP_SF_ddddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x55,(ulonglong)param_6,param_3,
                 (char)param_6,(char)param_5,(char)param_6,(char)param_5);
  }
  puVar16 = auStackY_b8;
  uVar18 = param_3;
  while( true ) {
    if (uVar18 == 0) {
      if (local_res10 == 0) {
        *(undefined4 *)(lVar2 + 0x100) = 0;
        *(undefined4 *)(lVar2 + 0xfc) = 0;
      }
      if (param_3 != 0) {
        *param_7 = param_3;
        *(undefined8 *)(lVar2 + 0x70) = DAT_140036750;
      }
      return 0;
    }
    local_60 = *(longlong **)(lVar2 + 0xe8);
    if (local_60 == (longlong *)0x0) break;
LAB_140012a44:
    uVar11 = *(int *)(lVar2 + 0xf0) - *(int *)(lVar2 + 0xf4);
    uVar12 = uVar18;
    if (uVar11 < uVar18) {
      uVar12 = uVar11;
    }
    local_res18[0] = 0;
    TdiCopyBufferToMdl(param_4,0,uVar12,*(undefined8 *)(*(longlong *)(lVar2 + 0xe8) + 8));
    uVar12 = *(int *)(lVar2 + 0xf4) + local_res18[0];
    *(uint *)(lVar2 + 0xf4) = uVar12;
    *(int *)(lVar2 + 0x100) = *(int *)(lVar2 + 0x100) + local_res18[0];
    local_res10 = local_res10 - local_res18[0];
    local_res20 = param_4 + (ulonglong)local_res18[0];
    uVar18 = uVar18 - local_res18[0];
    if (((local_res18[0] == 0) || (*(uint *)(lVar2 + 0xf0) <= uVar12)) ||
       (param_4 = local_res20, local_res10 == 0)) {
      local_60 = *(longlong **)(lVar2 + 0xe8);
      local_60[7] = (ulonglong)*(uint *)(lVar2 + 0xf4);
      *(uint *)(local_60 + 6) = -(uint)(local_res10 != 0) & 0x80000005;
      *(undefined8 *)(lVar2 + 0xe8) = 0;
      *(undefined4 *)(lVar2 + 0xf4) = 0;
      *(undefined4 *)(lVar2 + 0xf0) = 0;
      KeReleaseSpinLock(param_2 + 0x168,CONCAT31((int3)(uVar12 >> 8),*param_9));
      KeReleaseSpinLock(param_1 + 0x1b8,*param_8);
      PgmCancelCancelRoutine((longlong)local_60);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
        WPP_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x56,
                   &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,local_60,(char)local_60[7],
                   (char)uVar18);
      }
      IofCompleteRequest(local_60,2);
      uVar7 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x1b8);
      *param_8 = uVar7;
      uVar7 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x168);
      *param_9 = uVar7;
      param_4 = local_res20;
    }
  }
  if (*(longlong **)(lVar2 + 200) != (longlong *)(lVar2 + 200)) {
    plVar3 = *(longlong **)(lVar2 + 200);
    local_60 = plVar3 + -0x15;
    lVar17 = *plVar3;
    if ((*(longlong **)(lVar17 + 8) == plVar3) &&
       (plVar4 = (longlong *)plVar3[1], (longlong *)*plVar4 == plVar3)) {
      *plVar4 = lVar17;
      *(longlong **)(lVar17 + 8) = plVar4;
      lVar17 = plVar3[2];
      *(longlong **)(lVar2 + 0xe8) = local_60;
      uVar1 = *(undefined4 *)(lVar17 + 8);
      *(undefined4 *)(lVar2 + 0xf4) = 0;
      *(undefined4 *)(lVar2 + 0xf0) = uVar1;
      goto LAB_140012a44;
    }
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)(3);
    puVar16 = auStackY_b0;
  }
  local_58 = param_2 + 0x168;
  local_60 = (longlong *)0x0;
  local_res18[0] = 0;
  uVar10 = *(undefined8 *)(param_2 + 0x50);
  pcVar6 = *(code **)(param_1 + 0x80);
  uVar5 = *(undefined8 *)(param_1 + 0x88);
  uVar7 = *param_9;
  *(undefined8 *)(puVar16 + -8) = 0x140012c66;
  KeReleaseSpinLock(local_58,uVar7);
  local_50 = param_1 + 0x1b8;
  *(undefined8 *)(puVar16 + -8) = 0x140012c8c;
  KeReleaseSpinLock(local_50);
  *(undefined8 *)(puVar16 + -8) = 0x140012c98;
  cVar8 = KeGetCurrentIrql();
  *(longlong ***)(puVar16 + 0x38) = &local_60;
  *(longlong *)(puVar16 + 0x30) = local_res20;
  *(uint **)(puVar16 + 0x28) = local_res18;
  iVar13 = (-(uint)(cVar8 != '\0') & 0x800) + 0x420;
  *(int *)(puVar16 + 0x20) = local_res10;
  *(undefined8 *)(puVar16 + -8) = 0x140012ce6;
  iVar9 = (*pcVar6)(uVar5,uVar10,iVar13,uVar18);
  lVar17 = local_50;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (uVar12 = *(uint *)(WPP_GLOBAL_Control + 0x2c), (uVar12 & 0x20) != 0)) {
    uVar10 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(longlong **)(puVar16 + 0x40) = local_60;
    *(int *)(puVar16 + 0x38) = local_res10;
    *(uint *)(puVar16 + 0x30) = uVar18;
    *(uint *)(puVar16 + 0x28) = local_res18[0];
    *(int *)(puVar16 + 0x20) = iVar13;
    *(undefined8 *)(puVar16 + -8) = 0x140012d44;
    WPP_SF_DDdddq(uVar10,(ulonglong)uVar12,local_50,iVar9,puVar16[0x20],puVar16[0x28],puVar16[0x30],
                  puVar16[0x38],puVar16[0x40]);
    lVar17 = param_1 + 0x1b8;
  }
  lVar14 = local_50;
  if (uVar18 < local_res18[0]) {
    lVar14 = lVar17;
    local_res18[0] = uVar18;
  }
  local_res20 = local_res20 + (ulonglong)local_res18[0];
  local_res10 = local_res10 - local_res18[0];
  uVar18 = uVar18 - local_res18[0];
  if (iVar9 == -0x3fffffea) {
    local_58 = param_2 + 0x168;
    if (local_60 != (longlong *)0x0) {
      *(undefined8 *)(puVar16 + -8) = 0x140012dba;
      uVar10 = PgmCheckSetCancelRoutine((longlong)local_60,PgmCancelReceiveIrp,'\0');
      if ((int)uVar10 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          uVar10 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
          *(longlong **)(puVar16 + 0x20) = local_60;
          *(undefined8 *)(puVar16 + -8) = 0x140012df6;
          WPP_SF_qq(uVar10,0x58,&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,param_2,
                    puVar16[0x20]);
        }
        *(undefined8 *)(puVar16 + -8) = 0x140012e07;
        PgmIoComplete((longlong)local_60,0xc0000120,0);
        *(undefined8 *)(puVar16 + -8) = 0x140012e19;
        uVar7 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x1b8);
        *param_8 = uVar7;
        *(undefined8 *)(puVar16 + -8) = 0x140012e35;
        uVar7 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x168);
        *param_9 = uVar7;
        *(int *)(lVar2 + 0x100) = *(int *)(lVar2 + 0x100) + local_res18[0];
        goto LAB_140012f3d;
      }
    }
  }
  else {
    lVar14 = local_50;
  }
  *(undefined8 *)(puVar16 + -8) = 0x140012e60;
  uVar7 = KeAcquireSpinLockRaiseToDpc(lVar14);
  *param_8 = uVar7;
  *(undefined8 *)(puVar16 + -8) = 0x140012e79;
  uVar7 = KeAcquireSpinLockRaiseToDpc(local_58);
  *param_9 = uVar7;
  *(int *)(lVar2 + 0x100) = *(int *)(lVar2 + 0x100) + local_res18[0];
  if (*(longlong *)(lVar2 + 0x18) == 0) {
    if (iVar9 == -0x3fffffea) {
      uVar7 = *param_9;
      *(undefined8 *)(puVar16 + -8) = 0x140012eb3;
      KeReleaseSpinLock(local_58,uVar7);
      uVar7 = *param_8;
      *(undefined8 *)(puVar16 + -8) = 0x140012ecb;
      KeReleaseSpinLock(lVar14,uVar7);
      *(undefined8 *)(puVar16 + -8) = 0x140012ee1;
      PgmIoComplete((longlong)local_60,0xc0000120,0);
      *(undefined8 *)(puVar16 + -8) = 0x140012eeb;
      uVar7 = KeAcquireSpinLockRaiseToDpc(lVar14);
      *param_8 = uVar7;
      *(undefined8 *)(puVar16 + -8) = 0x140012f04;
      uVar7 = KeAcquireSpinLockRaiseToDpc(local_58);
      *param_9 = uVar7;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      uVar10 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      *(undefined8 *)(puVar16 + -8) = 0x140012f3d;
      WPP_SF_i(uVar10,0x59,&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,param_2);
    }
LAB_140012f3d:
    if (param_3 - uVar18 != 0) {
      *param_7 = param_3 - uVar18;
      *(undefined8 *)(lVar2 + 0x70) = DAT_140036750;
    }
    return -0x3fffffff;
  }
  if (iVar9 == -0x3fffffea) {
    lVar17 = local_60[0x17];
    local_res18[0] = 0;
    lVar14 = local_60[1];
    uVar12 = uVar18;
    if (*(uint *)(lVar17 + 8) < uVar18) {
      uVar12 = *(uint *)(lVar17 + 8);
    }
    *(uint **)(puVar16 + 0x28) = local_res18;
    puVar15 = (undefined1 *)0x0;
    *(undefined4 *)(puVar16 + 0x20) = *(undefined4 *)(lVar2 + 0xf4);
    *(undefined8 *)(puVar16 + -8) = 0x140012fb0;
    TdiCopyBufferToMdl(local_res20,0,uVar12,lVar14);
    uVar18 = uVar18 - local_res18[0];
    local_res10 = local_res10 - local_res18[0];
    *(int *)(lVar2 + 0x100) = *(int *)(lVar2 + 0x100) + local_res18[0];
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
      puVar15 = (undefined1 *)0x0;
      uVar10 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      *(uint *)(puVar16 + 0x28) = local_res18[0];
      *(undefined4 *)(puVar16 + 0x20) = *(undefined4 *)(lVar17 + 8);
      *(undefined8 *)(puVar16 + -8) = 0x140012fff;
      WPP_SF_qdd(uVar10,0x5a,&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,local_60,puVar16[0x20]
                 ,puVar16[0x28]);
    }
    if (local_res18[0] != 0) {
      uVar12 = *(uint *)(lVar17 + 8);
      puVar15 = (undefined1 *)(ulonglong)uVar12;
      if ((local_res18[0] < uVar12) && (*(int *)(lVar2 + 0xfc) != *(int *)(lVar2 + 0x100))) {
        *(uint *)(lVar2 + 0xf0) = uVar12;
        *(uint *)(lVar2 + 0xf4) = local_res18[0];
        *(longlong **)(lVar2 + 0xe8) = local_60;
        param_9 = puVar15;
        goto LAB_140013048;
      }
    }
    local_60[7] = (ulonglong)local_res18[0];
    *(uint *)(local_60 + 6) =
         -(uint)(*(int *)(lVar2 + 0xfc) != *(int *)(lVar2 + 0x100)) & 0x80000005;
    *(undefined8 *)(lVar2 + 0xf0) = 0;
    uVar10 = CONCAT71((int7)((ulonglong)puVar15 >> 8),*param_9);
    *(undefined8 *)(puVar16 + -8) = 0x1400130f8;
    KeReleaseSpinLock(param_2 + 0x168,uVar10);
    uVar10 = CONCAT71((int7)((ulonglong)uVar10 >> 8),*param_8);
    *(undefined8 *)(puVar16 + -8) = 0x140013118;
    KeReleaseSpinLock(param_1 + 0x1b8,uVar10);
    *(undefined8 *)(puVar16 + -8) = 0x140013126;
    PgmCancelCancelRoutine((longlong)local_60);
    puVar15 = (undefined1 *)CONCAT71((int7)((ulonglong)uVar10 >> 8),2);
    *(undefined8 *)(puVar16 + -8) = 0x140013133;
    IofCompleteRequest(local_60);
    *(undefined8 *)(puVar16 + -8) = 0x14001314a;
    uVar7 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x1b8);
    *param_8 = uVar7;
    *(undefined8 *)(puVar16 + -8) = 0x140013166;
    uVar7 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x168);
    *param_9 = uVar7;
    param_9 = puVar15;
  }
  else {
    if (iVar9 != -0x3ffffde5) goto LAB_14001304b;
    if ((*(longlong *)(lVar2 + 0xe8) == 0) &&
       (*(longlong **)(lVar2 + 200) == (longlong *)(lVar2 + 200))) {
      *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) | 0x800;
      goto LAB_14001304b;
    }
  }
LAB_140013048:
  iVar9 = 0;
LAB_14001304b:
  if (*(int *)(lVar2 + 0xfc) == *(int *)(lVar2 + 0x100)) {
    *(undefined8 *)(lVar2 + 0xfc) = 0;
  }
  if (((iVar9 + 0x80000000U & 0x80000000) == 0) && (iVar9 != -0x3ffffde5)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      uVar10 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      *(undefined8 *)(puVar16 + -8) = 0x1400130ae;
      WPP_SF_D(uVar10,0x5c,&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,iVar9);
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
    uVar10 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(int *)(puVar16 + 0x30) = local_res10;
    *(uint *)(puVar16 + 0x28) = local_res18[0];
    *(longlong *)(puVar16 + 0x20) = param_2;
    *(undefined8 *)(puVar16 + -8) = 0x1400131d7;
    WPP_SF_Dqdd(uVar10,param_9,0,iVar9,puVar16[0x20],puVar16[0x28],puVar16[0x30]);
  }
  if (param_3 - uVar18 != 0) {
    *param_7 = param_3 - uVar18;
    *(undefined8 *)(lVar2 + 0x70) = DAT_140036750;
  }
  return iVar9;
}



===== PgmMoveList @ 1400131fc =====

void PgmMoveList(longlong *param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  
  plVar1 = (longlong *)param_2[1];
  if ((((*(longlong **)(*param_2 + 8) == param_2) && ((longlong *)*plVar1 == param_2)) &&
      (*(longlong **)(*param_1 + 8) == param_1)) && (*(longlong **)param_1[1] == param_1)) {
    *plVar1 = (longlong)param_1;
    param_2[1] = param_1[1];
    *(longlong **)param_1[1] = param_2;
    lVar2 = *param_1;
    param_1[1] = (longlong)plVar1;
    if ((*(longlong **)(lVar2 + 8) == param_1) && ((longlong *)*plVar1 == param_1)) {
      *plVar1 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar1;
      param_1[1] = (longlong)param_1;
      *param_1 = (longlong)param_1;
      return;
    }
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== PgmNewInboundConnection @ 140013264 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
PgmNewInboundConnection
          (longlong param_1,ulonglong param_2,longlong param_3,undefined8 param_4,ushort *param_5,
          int param_6,longlong *param_7,uint param_8)

{
  longlong lVar1;
  byte bVar2;
  ushort uVar3;
  longlong lVar4;
  code *pcVar5;
  longlong lVar6;
  short sVar7;
  uint uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  undefined1 uVar11;
  undefined1 uVar12;
  int iVar13;
  longlong lVar14;
  ulonglong uVar15;
  longlong lVar16;
  undefined8 *puVar17;
  undefined8 uVar18;
  undefined8 *puVar19;
  undefined8 *puVar20;
  undefined1 *puVar21;
  ulonglong uVar22;
  ushort *puVar23;
  char *pcVar24;
  ushort uVar25;
  uint uVar26;
  undefined1 auStackY_f8 [8];
  undefined1 auStackY_f0 [24];
  uint local_a4;
  longlong local_a0;
  uint local_98;
  longlong *local_90;
  undefined8 local_88;
  ushort local_80 [2];
  undefined4 uStack_7c;
  ushort uStack_78;
  ushort uStack_76;
  ushort uStack_74;
  undefined2 uStack_72;
  undefined2 uStack_70;
  undefined2 uStack_6e;
  undefined2 uStack_6c;
  ulonglong local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_f8;
  local_90 = param_7;
  local_88 = 0;
  uStack_7c = 0;
  uStack_76 = 0;
  uStack_74 = 0;
  uStack_72 = 0;
  uStack_70 = 0;
  uStack_6e = 0;
  uStack_6c = 0;
  local_a0 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if ((*(byte *)((longlong)param_5 + 5) & 1) == 0) {
LAB_14001332f:
    local_98 = *(uint *)(param_5 + 8);
    lVar16 = param_1 + 0x1b8;
    uVar26 = local_98 >> 0x18 | (local_98 & 0xff0000) >> 8 | (local_98 & 0xff00) << 8 |
             local_98 << 0x18;
    local_a4 = uVar26;
    uVar9 = KeAcquireSpinLockRaiseToDpc(lVar16);
    lVar4 = *(longlong *)(param_1 + 0x78);
    if (lVar4 == 0) {
      KeReleaseSpinLock();
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xa7,
                 &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,param_1);
      }
    }
    else {
      uStack_7c = *(undefined4 *)(param_3 + 4);
      uStack_70 = (undefined2)*(undefined4 *)(param_3 + 0x10);
      uStack_6e = (undefined2)((uint)*(undefined4 *)(param_3 + 0x10) >> 0x10);
      uStack_6c = *(undefined2 *)(param_3 + 0x14);
      pcVar5 = *(code **)(param_1 + 0x70);
      uStack_76 = (ushort)((uint)*(undefined4 *)(param_3 + 8) >> 0x10);
      uStack_74 = (ushort)*(undefined4 *)(param_3 + 0xc);
      uStack_72 = (undefined2)((uint)*(undefined4 *)(param_3 + 0xc) >> 0x10);
      uStack_78 = *param_5;
      local_80[0] = 1;
      local_80[1] = 0;
      KeReleaseSpinLock(lVar16,uVar9);
      puVar23 = local_80;
      iVar13 = (*pcVar5)(lVar4,0x16,puVar23,0);
      uVar9 = (undefined1)param_1;
      if ((iVar13 == -0x3fffffea) && (local_a0 != 0)) {
        uVar10 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
        uVar11 = KeAcquireSpinLockRaiseToDpc(lVar16);
        lVar4 = *(longlong *)(*(longlong *)(*(longlong *)(local_a0 + 0xb8) + 0x30) + 0x18);
        if (((lVar4 == 0) || (*(int *)(lVar4 + 0x10) != 0x52534553)) ||
           (*(longlong *)(lVar4 + 0x18) != param_1)) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
            if (lVar4 == 0) {
              uVar12 = 0;
            }
            else {
              uVar12 = (undefined1)*(undefined8 *)(lVar4 + 0x18);
            }
            WPP_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xa9,
                       &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,lVar4,uVar12,uVar9);
          }
          KeReleaseSpinLock(param_1 + 0x1b8,uVar11);
          KeReleaseSpinLock(&DAT_140036808,uVar10);
          uVar18 = 0xc00000e5;
LAB_140013cc4:
          PgmIoComplete(local_a0,uVar18,0);
LAB_140013cd5:
          *local_90 = 0;
        }
        else {
          lVar1 = lVar4 + 0x168;
          uVar12 = KeAcquireSpinLockRaiseToDpc(lVar1);
          lVar14 = InitReceiverData(lVar4);
          lVar6 = *(longlong *)(lVar4 + 0x30);
          *(longlong *)(lVar6 + 0xd8) = lVar14;
          if (lVar14 != 0) {
            uVar15 = Feature_4275546425__private_IsEnabledDeviceUsageNoInline();
            uVar8 = DAT_140036768;
            if ((int)uVar15 != 0) {
              if (DAT_140036768 < param_8) {
                DAT_140036768 = param_8;
              }
              if (DAT_140036768 < 0x10000) {
                uVar25 = (ushort)DAT_140036768;
                puVar23 = (ushort *)(lVar4 + 0x9a);
                uVar26 = RtlUShortAdd(uVar25,0xe,puVar23);
                if (-1 < (int)uVar26) {
                  *(ushort *)(lVar4 + 0x98) = uVar25;
                  *(uint *)(*(longlong *)(lVar4 + 0x30) + 0x20) =
                       (uint)(uStack_74 >> 8) | (uStack_74 & 0xff) << 8 | (uStack_76 & 0xff00) << 8
                       | CONCAT22(uStack_74,uStack_76) << 0x18;
                  uVar26 = local_a4;
                  goto LAB_14001368c;
                }
              }
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
                WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xab,puVar23,DAT_140036768);
              }
              *(uint *)(lVar4 + 0x20) = *(uint *)(lVar4 + 0x20) | 0x100;
              DAT_140036768 = uVar8;
              KeReleaseSpinLock(lVar16,uVar12);
              KeReleaseSpinLock(&DAT_140036808,uVar11);
              KeReleaseSpinLock(lVar1,uVar10);
              uVar18 = 0xc000009a;
              goto LAB_140013cc4;
            }
            *(uint *)(*(longlong *)(lVar4 + 0x30) + 0x20) =
                 (uint)(uStack_74 >> 8) | (uStack_74 & 0xff) << 8 | (uStack_76 & 0xff00) << 8 |
                 CONCAT22(uStack_74,uStack_76) << 0x18;
            sVar7 = (short)DAT_140036768;
            *(short *)(lVar4 + 0x98) = sVar7;
            *(short *)(lVar4 + 0x9a) = sVar7 + 0xe;
LAB_14001368c:
            if ((*(uint *)(param_1 + 0x38) & 0x10) == 0) {
              *(undefined2 *)(*(longlong *)(lVar4 + 0x30) + 0x120) = 3000;
              *(undefined8 *)(*(longlong *)(lVar4 + 0x30) + 0x60) = 100;
            }
            else {
              *(undefined2 *)(*(longlong *)(lVar4 + 0x30) + 0x120) = 9000;
              *(undefined8 *)(*(longlong *)(lVar4 + 0x30) + 0x60) = 5;
            }
            *(undefined8 *)(*(longlong *)(lVar4 + 0x30) + 0x50) =
                 *(undefined8 *)(*(longlong *)(lVar4 + 0x30) + 0x60);
            *(undefined1 *)(lVar4 + 0xa0) = 1;
            *(undefined2 *)(*(longlong *)(lVar4 + 0x30) + 0x2e) = 1;
            iVar13 = *(int *)(param_1 + 0x1a4);
            if ((iVar13 != 0) || (*(char *)(param_1 + 0x131) != '\0')) {
              if (iVar13 == 0) {
                iVar13 = *(int *)(*(longlong *)(lVar4 + 0x30) + 0x20);
              }
              *(int *)(*(longlong *)(lVar4 + 0x30) + 0x24) = iVar13;
              if (*(char *)(param_1 + 0x131) != '\0') {
                lVar16 = ExAllocatePool2(0x40,(ulonglong)*(byte *)(param_1 + 0x130) *
                                              (ulonglong)*(ushort *)(lVar4 + 0x9a) * 2);
                *(longlong *)(lVar4 + 0x90) = lVar16;
                if (lVar16 == 0) {
                  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
                    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xac,
                             &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,
                             (uint)*(byte *)(param_1 + 0x130) * (uint)*(ushort *)(lVar4 + 0x9a) * 2)
                    ;
                  }
                  uVar22 = 0xc000009a;
                }
                else {
                  uVar15 = CreateFECContext((uint *)(lVar4 + 0x70),(uint)*(byte *)(param_1 + 0x130),
                                            0xff,'\x01');
                  uVar22 = uVar15 & 0xffffffff;
                  if (-1 < (int)uVar15) {
                    *(undefined1 *)(lVar4 + 0xa0) = *(undefined1 *)(param_1 + 0x130);
                    bVar2 = *(byte *)(param_1 + 0x131);
                    *(byte *)(lVar4 + 0xa1) = bVar2;
                    if ((bVar2 & 1) != 0) {
                      *(undefined2 *)(*(longlong *)(lVar4 + 0x30) + 0x2e) = 2;
                    }
                    ExInitializeNPagedLookasideList(*(longlong *)(lVar4 + 0x30) + 0x240,0,0,0x200);
                    goto LAB_140013919;
                  }
                  ExFreePoolWithTag(*(undefined8 *)(lVar4 + 0x90),0);
                  *(undefined8 *)(lVar4 + 0x90) = 0;
                  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
                    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xad,
                             &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,(int)uVar15);
                  }
                }
                lVar16 = *(longlong *)(*(longlong *)(lVar4 + 0x30) + 0xd8);
                if (lVar16 != 0) {
                  ExFreePoolWithTag(lVar16,0);
                  *(undefined8 *)(*(longlong *)(lVar4 + 0x30) + 0xd8) = 0;
                }
                *(uint *)(lVar4 + 0x20) = *(uint *)(lVar4 + 0x20) | 0x100;
                KeReleaseSpinLock(param_1 + 0x1b8,uVar12);
                KeReleaseSpinLock(&DAT_140036808,uVar11);
                KeReleaseSpinLock(lVar4 + 0x168,uVar10);
                PgmIoComplete(local_a0,uVar22,0);
                uVar18 = 0xc000021b;
                goto LAB_140013cd5;
              }
LAB_140013919:
              *(undefined2 *)(param_1 + 0x130) = 0;
              *(undefined4 *)(param_1 + 0x1a4) = 0;
            }
            uVar25 = *param_5;
            *(undefined4 *)(lVar4 + 0x40) = *(undefined4 *)(param_5 + 4);
            uVar3 = param_5[6];
            *(int *)(lVar4 + 0x14) = *(int *)(lVar4 + 0x14) + 2;
            *(ushort *)(lVar4 + 0x44) = uVar3;
            *(ushort *)(lVar4 + 0x46) = uVar25 >> 8 | uVar25 << 8;
            *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
            *(uint *)(lVar4 + 0x20) = *(uint *)(lVar4 + 0x20) | 0x228;
            *(longlong *)(*(longlong *)(lVar4 + 0x30) + 0x18) = param_1;
            *(uint *)(*(longlong *)(lVar4 + 0x30) + 0x114) = *(ushort *)(lVar4 + 0x98) + 0x10;
            *(undefined4 *)(*(longlong *)(lVar4 + 0x30) + 0x118) =
                 *(undefined4 *)(*(longlong *)(lVar4 + 0x30) + 0x114);
            *(uint *)(lVar4 + 0x20) = *(uint *)(lVar4 + 0x20) | 0x8000;
            ExInitializeNPagedLookasideList(*(longlong *)(lVar4 + 0x30) + 0x140,0,0,0x200);
            ExInitializeNPagedLookasideList(*(longlong *)(lVar4 + 0x30) + 0x1c0,0);
            puVar21 = auStackY_f8;
            local_a4 = uVar26 & -(uint)*(byte *)(lVar4 + 0xa0);
            if ((local_68 & 0x800000000) == 0) {
              *(uint *)(*(longlong *)(lVar4 + 0x30) + 0x34) = local_a4;
            }
            else {
              uVar26 = -(uint)*(byte *)(lVar4 + 0xa0) &
                       (uint)*(byte *)(lVar4 + 0xa0) + uStack_60._4_4_ + -1;
              uStack_60 = CONCAT44(uVar26,(int)uStack_60);
              *(uint *)(*(longlong *)(lVar4 + 0x30) + 0x34) = uVar26;
            }
            *(undefined4 *)(*(longlong *)(lVar4 + 0x30) + 0x38) =
                 *(undefined4 *)(*(longlong *)(lVar4 + 0x30) + 0x34);
            *(undefined4 *)(*(longlong *)(lVar4 + 0x30) + 0x30) =
                 *(undefined4 *)(*(longlong *)(lVar4 + 0x30) + 0x38);
            *(undefined8 *)(*(longlong *)(lVar4 + 0x30) + 0x58) =
                 *(undefined8 *)(*(longlong *)(lVar4 + 0x30) + 0x50);
            puVar20 = &DAT_140036710;
            *(uint *)(*(longlong *)(lVar4 + 0x30) + 0x3c) =
                 *(int *)(*(longlong *)(lVar4 + 0x30) + 0x34) - (uint)*(byte *)(lVar4 + 0xa0) &
                 -(uint)*(byte *)(lVar4 + 0xa0);
            *(int *)(*(longlong *)(lVar4 + 0x30) + 0x40) =
                 *(int *)(*(longlong *)(lVar4 + 0x30) + 0x34) + -1;
            puVar17 = *(undefined8 **)(lVar4 + 0x30);
            puVar19 = DAT_140036718;
            if ((undefined8 *)*DAT_140036718 != &DAT_140036710) {
              puVar19 = (undefined8 *)0x3;
              pcVar5 = (code *)swi(0x29);
              puVar17 = (undefined8 *)(*pcVar5)();
              puVar21 = auStackY_f0;
            }
            *puVar17 = puVar20;
            puVar17[1] = puVar19;
            *puVar19 = puVar17;
            DAT_140036718 = puVar17;
            if ((DAT_140036758 & 2) == 0) {
              DAT_140036750 = 1;
              *(undefined8 *)(*(longlong *)(lVar4 + 0x30) + 0x2e8) = 1;
              DAT_140036758 = DAT_140036758 | 2;
              _DAT_140036748 = _DAT_fffff78000000008;
              DAT_140036740 = 200000;
              *(undefined8 *)(puVar21 + -8) = 0x140013b0b;
              KeInitializeTimer(&DAT_140036770);
              *(undefined8 *)(puVar21 + -8) = 0x140013b28;
              KeInitializeDpc(&DAT_1400367b0,ReceiveTimerTimeout,0);
              *(undefined8 *)(puVar21 + -8) = 0x140013b49;
              KeSetTimer(&DAT_140036770,0xfffffffffffcf2c0);
            }
            else {
              *(undefined8 *)(*(longlong *)(lVar4 + 0x30) + 0x2e8) = DAT_140036750;
            }
            puVar21[0x20] = 1;
            *(undefined8 *)(puVar21 + -8) = 0x140013b79;
            CheckAndAddNakRequests(lVar4,&local_a4,(undefined8 *)0x0,0,puVar21[0x20]);
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
              pcVar24 = "";
              uVar18 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
              if (-1 < *(char *)((longlong)param_5 + 5)) {
                pcVar24 = "non-";
              }
              *(undefined4 *)(puVar21 + 0x40) = *(undefined4 *)(*(longlong *)(lVar4 + 0x30) + 0x34);
              *(char **)(puVar21 + 0x38) = pcVar24;
              *(uint *)(puVar21 + 0x30) = local_a4;
              *(uint *)(puVar21 + 0x28) =
                   local_98 >> 0x18 | (local_98 & 0xff0000) >> 8 | (local_98 & 0xff00) << 8 |
                   local_98 << 0x18;
              *(longlong *)(puVar21 + 0x20) = lVar4;
              *(undefined8 *)(puVar21 + -8) = 0x140013be5;
              WPP_SF_qqddsd(uVar18,0xae,pcVar24,param_1,puVar21[0x20],puVar21[0x28],puVar21[0x30],
                            *(char **)(puVar21 + 0x38),puVar21[0x40]);
            }
            *(undefined8 *)(puVar21 + -8) = 0x140013bf6;
            KeReleaseSpinLock(lVar4 + 0x168,uVar12);
            *(undefined8 *)(puVar21 + -8) = 0x140013c0c;
            KeReleaseSpinLock(param_1 + 0x1b8,uVar11);
            *(undefined8 *)(puVar21 + -8) = 0x140013c22;
            KeReleaseSpinLock(&DAT_140036808);
            *(undefined8 *)(puVar21 + -8) = 0x140013c35;
            PgmIoComplete(local_a0,0,0);
            *local_90 = lVar4;
            uVar18 = 0;
            goto LAB_140013d3e;
          }
          *(uint *)(lVar4 + 0x20) = *(uint *)(lVar4 + 0x20) | 0x100;
          KeReleaseSpinLock(lVar16,CONCAT71((int7)((ulonglong)lVar6 >> 8),uVar12));
          KeReleaseSpinLock(&DAT_140036808,uVar11);
          KeReleaseSpinLock(lVar1,uVar10);
          uVar18 = 0xc000009a;
          PgmIoComplete(local_a0,0xc000009a,0);
          *local_90 = 0;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
            WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xaa,
                      &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,lVar4,uVar9);
          }
        }
        puVar21 = auStackY_f8;
        goto LAB_140013d3e;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
        WPP_SF_Dqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xa8,
                   &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,iVar13,uVar9,
                   (char)*(undefined8 *)(param_1 + 0x70));
      }
      if (local_a0 != 0) {
        PgmIoComplete(local_a0,0xc00000e5,0);
      }
      *param_7 = 0;
    }
  }
  else {
    iVar13 = ProcessOptions((char *)(param_5 + 0xc),param_6 - 0x18,(byte)param_5[2] & 0xf,
                            (longlong)&local_68,0);
    if (-1 < iVar13) goto LAB_14001332f;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xa6,
               &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,iVar13);
    }
  }
  puVar21 = auStackY_f8;
  uVar18 = 0xc000021b;
LAB_140013d3e:
  *(undefined8 *)(puVar21 + -8) = 0x140013d4a;
  return uVar18;
}



===== PgmNewInboundConnectionOld @ 140013d6c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140014744) */
/* WARNING: Removing unreachable block (ram,0x000140013f42) */
/* WARNING: Removing unreachable block (ram,0x000140013f89) */
/* WARNING: Removing unreachable block (ram,0x000140013f96) */
/* WARNING: Removing unreachable block (ram,0x000140014663) */
/* WARNING: Removing unreachable block (ram,0x000140014676) */
/* WARNING: Removing unreachable block (ram,0x000140014683) */
/* WARNING: Removing unreachable block (ram,0x00014001468e) */
/* WARNING: Removing unreachable block (ram,0x000140014688) */
/* WARNING: Removing unreachable block (ram,0x000140014690) */
/* WARNING: Removing unreachable block (ram,0x0001400146b2) */
/* WARNING: Removing unreachable block (ram,0x000140013fa0) */
/* WARNING: Removing unreachable block (ram,0x000140013fd5) */
/* WARNING: Removing unreachable block (ram,0x000140014044) */
/* WARNING: Removing unreachable block (ram,0x000140014051) */
/* WARNING: Removing unreachable block (ram,0x00014001406e) */
/* WARNING: Removing unreachable block (ram,0x000140014076) */
/* WARNING: Removing unreachable block (ram,0x0001400140bd) */
/* WARNING: Removing unreachable block (ram,0x0001400140a6) */
/* WARNING: Removing unreachable block (ram,0x0001400140d2) */
/* WARNING: Removing unreachable block (ram,0x000140014105) */
/* WARNING: Removing unreachable block (ram,0x000140014112) */
/* WARNING: Removing unreachable block (ram,0x00014001411a) */
/* WARNING: Removing unreachable block (ram,0x00014001411d) */
/* WARNING: Removing unreachable block (ram,0x00014001412d) */
/* WARNING: Removing unreachable block (ram,0x0001400141b3) */
/* WARNING: Removing unreachable block (ram,0x0001400142b4) */
/* WARNING: Removing unreachable block (ram,0x0001400142d5) */
/* WARNING: Removing unreachable block (ram,0x0001400142dd) */
/* WARNING: Removing unreachable block (ram,0x0001400141da) */
/* WARNING: Removing unreachable block (ram,0x00014001420a) */
/* WARNING: Removing unreachable block (ram,0x000140014212) */
/* WARNING: Removing unreachable block (ram,0x000140014165) */
/* WARNING: Removing unreachable block (ram,0x000140014178) */
/* WARNING: Removing unreachable block (ram,0x000140014180) */
/* WARNING: Removing unreachable block (ram,0x0001400141ab) */
/* WARNING: Removing unreachable block (ram,0x00014001422a) */
/* WARNING: Removing unreachable block (ram,0x00014001423a) */
/* WARNING: Removing unreachable block (ram,0x000140014254) */
/* WARNING: Removing unreachable block (ram,0x0001400146f1) */
/* WARNING: Removing unreachable block (ram,0x000140014337) */
/* WARNING: Removing unreachable block (ram,0x000140014346) */
/* WARNING: Removing unreachable block (ram,0x00014001445a) */
/* WARNING: Removing unreachable block (ram,0x000140014439) */
/* WARNING: Removing unreachable block (ram,0x000140014462) */
/* WARNING: Removing unreachable block (ram,0x0001400144c3) */
/* WARNING: Removing unreachable block (ram,0x0001400144ca) */
/* WARNING: Removing unreachable block (ram,0x000140014574) */
/* WARNING: Removing unreachable block (ram,0x0001400144ea) */
/* WARNING: Removing unreachable block (ram,0x000140014586) */
/* WARNING: Removing unreachable block (ram,0x0001400145b0) */
/* WARNING: Removing unreachable block (ram,0x0001400145b7) */
/* WARNING: Removing unreachable block (ram,0x0001400145da) */
/* WARNING: Removing unreachable block (ram,0x0001400145de) */
/* WARNING: Removing unreachable block (ram,0x000140014605) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
PgmNewInboundConnectionOld
          (longlong param_1,ulonglong param_2,longlong param_3,undefined8 param_4,ushort *param_5,
          int param_6,longlong *param_7)

{
  longlong lVar1;
  longlong lVar2;
  code *pcVar3;
  undefined1 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined1 auStackY_f8 [32];
  undefined4 local_80;
  undefined4 uStack_7c;
  ushort uStack_78;
  undefined2 uStack_76;
  undefined2 uStack_74;
  undefined2 uStack_72;
  undefined2 uStack_70;
  undefined2 uStack_6e;
  undefined2 uStack_6c;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_f8;
  uStack_7c = 0;
  uStack_76 = 0;
  uStack_74 = 0;
  uStack_72 = 0;
  uStack_70 = 0;
  uStack_6e = 0;
  uStack_6c = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((*(byte *)((longlong)param_5 + 5) & 1) == 0) ||
     (iVar5 = ProcessOptions((char *)(param_5 + 0xc),param_6 - 0x18,(byte)param_5[2] & 0xf,
                             (longlong)&local_68,0), -1 < iVar5)) {
    lVar1 = param_1 + 0x1b8;
    uVar4 = KeAcquireSpinLockRaiseToDpc(lVar1);
    lVar2 = *(longlong *)(param_1 + 0x78);
    if (lVar2 == 0) {
      KeReleaseSpinLock(lVar1);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x9f,
                 &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,param_1);
      }
    }
    else {
      uStack_7c = *(undefined4 *)(param_3 + 4);
      uStack_70 = (undefined2)*(undefined4 *)(param_3 + 0x10);
      uStack_6e = (undefined2)((uint)*(undefined4 *)(param_3 + 0x10) >> 0x10);
      uStack_6c = *(undefined2 *)(param_3 + 0x14);
      pcVar3 = *(code **)(param_1 + 0x70);
      uStack_76 = (undefined2)((uint)*(undefined4 *)(param_3 + 8) >> 0x10);
      uStack_74 = (undefined2)*(undefined4 *)(param_3 + 0xc);
      uStack_72 = (undefined2)((uint)*(undefined4 *)(param_3 + 0xc) >> 0x10);
      uStack_78 = *param_5;
      local_80 = 1;
      KeReleaseSpinLock(lVar1,uVar4);
      uVar6 = (*pcVar3)(lVar2,0x16,&local_80,0);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
        WPP_SF_Dqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xa0,
                   &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,uVar6,(char)param_1,
                   (char)*(undefined8 *)(param_1 + 0x70));
      }
      *param_7 = 0;
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x9e,
             &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,iVar5);
  }
  return 0xc000021b;
}



===== PgmProcessIncomingPacket @ 14001478c =====

ulonglong PgmProcessIncomingPacket
                    (longlong param_1,longlong param_2,undefined8 param_3,int *param_4,uint param_5,
                    longlong param_6,byte param_7)

{
  ulonglong uVar1;
  undefined1 uVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  undefined2 uVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  uint uVar9;
  
  uVar4 = 0;
  if (param_7 == 0) {
    if (param_5 < 0x24) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc000021b;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
        return 0xc000021b;
      }
      uVar6 = 0x96;
      goto LAB_140014b82;
    }
    if ((param_2 == 0) || (*(int *)(param_2 + 0x10) != 0x52534553)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x98,
                 &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,param_2);
      }
      return 0xc000021b;
    }
    puVar8 = (undefined8 *)(ulonglong)param_5;
    *(ulonglong *)(param_2 + 0xc0) = (ulonglong)param_5 + *(longlong *)(param_2 + 0xc0);
    *(longlong *)(param_2 + 200) = *(longlong *)(param_2 + 200) + 1;
    *(undefined8 *)(*(longlong *)(param_2 + 0x30) + 0x2e0) = DAT_140036750;
    uVar4 = ProcessSpmPacket(param_1,param_2,param_5,param_6);
    uVar4 = uVar4 & 0xffffffff;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar4;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
      return uVar4;
    }
    uVar6 = 0x97;
    uVar9 = 0;
    goto LAB_140014883;
  }
  uVar9 = (uint)param_7;
  if ((param_7 - 8 & 0xfd) != 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000021b;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return 0xc000021b;
    }
    WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x99,
              &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,uVar9,(char)param_5);
    return 0xc000021b;
  }
  puVar8 = (undefined8 *)0x24;
  if (param_5 < 0x24) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000021b;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return 0xc000021b;
    }
    uVar6 = 0x9a;
LAB_140014b82:
    WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
              &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,param_5,0x24);
    return 0xc000021b;
  }
  uVar1 = *(ulonglong *)(param_6 + 0x14);
  if (((((short)uVar1 != 0x100) || ((int)(uVar1 >> 0x20) == 0)) ||
      ((short)*(undefined8 *)(param_6 + 0x1c) != 0x100)) ||
     ((int)((ulonglong)*(undefined8 *)(param_6 + 0x1c) >> 0x20) == 0)) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000021b;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return 0xc000021b;
    }
    uVar6 = 0x9b;
    goto LAB_140014b82;
  }
  if (param_7 == 10) {
    if ((param_2 != 0) && (*(int *)(param_2 + 0x10) == 0x52534553)) {
LAB_1400149c7:
      puVar8 = (undefined8 *)(ulonglong)param_5;
      uVar3 = ReceiverProcessNakNcfPacket(param_1,param_2,param_5,param_6,param_7);
      goto LAB_140014a23;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      puVar8 = (undefined8 *)&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids;
      WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x9c,
               &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,param_2);
    }
    uVar4 = 0xc000021b;
  }
  else if (*(longlong *)(param_2 + 0x28) == 0) {
    if (((*param_4 == 1) && ((short)param_4[1] == 0xe)) && (*(short *)((longlong)param_4 + 6) == 2))
    {
      uVar3 = *(uint *)((longlong)param_4 + 10);
      uVar3 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
      if (uVar3 != 0) {
        uVar2 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
        puVar7 = &DAT_140036720;
        while (puVar7 = (undefined8 *)*puVar7, puVar7 != &DAT_140036720) {
          puVar8 = puVar7 + 2;
          puVar5 = puVar8;
          while (puVar5 = (undefined8 *)*puVar5, puVar5 != puVar8) {
            if (*(uint *)(puVar5 + 2) == uVar3) goto LAB_140014b28;
          }
        }
        KeReleaseSpinLock(&DAT_140036808,CONCAT71(0x1400367,uVar2));
        uVar2 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
        puVar8 = &DAT_140036720;
        while (puVar8 = (undefined8 *)*puVar8, puVar8 != &DAT_140036720) {
          puVar7 = puVar8 + 2;
          while (puVar7 = (undefined8 *)*puVar7, puVar7 != puVar8 + 2) {
            if ((*(uint *)(puVar7 + 2) & *(uint *)((longlong)puVar7 + 0x14)) ==
                (*(uint *)((longlong)puVar7 + 0x14) & uVar3)) {
              KeReleaseSpinLock(&DAT_140036808,CONCAT71((int7)((ulonglong)puVar7 >> 8),uVar2));
              goto LAB_1400149c7;
            }
          }
        }
        puVar8 = &DAT_140036720;
LAB_140014b28:
        KeReleaseSpinLock(&DAT_140036808,uVar2);
      }
    }
  }
  else {
    puVar8 = (undefined8 *)(ulonglong)param_5;
    uVar3 = SenderProcessNakPacket(uVar1 >> 0x20,param_2,param_5,param_6);
LAB_140014a23:
    uVar4 = (ulonglong)uVar3;
  }
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return uVar4;
  }
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
    return uVar4;
  }
  uVar6 = 0x9d;
LAB_140014883:
  WPP_SF_DqdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,puVar8,uVar9,(char)param_2,
              (char)param_5,(char)uVar4);
  return uVar4;
}



===== PgmReceive @ 140014bc4 =====

undefined8 PgmReceive(ulonglong param_1,longlong param_2,longlong param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  longlong lVar8;
  longlong *plVar9;
  undefined8 uVar10;
  undefined1 *puVar11;
  longlong *plVar12;
  longlong *plVar13;
  undefined1 *puVar14;
  longlong *plVar15;
  ulonglong local_res8;
  undefined1 auStackY_68 [8];
  undefined1 auStackY_60 [24];
  undefined1 uVar16;
  undefined1 uVar17;
  
  local_res8 = param_1 & 0xffffffffffffff00;
  plVar13 = (longlong *)0x0;
  plVar3 = *(longlong **)(*(longlong *)(param_3 + 0x30) + 0x18);
  uVar5 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
  IoAcquireCancelSpinLock(&local_res8);
  if ((((plVar3 == (longlong *)0x0) || ((int)plVar3[2] != 0x52534553)) ||
      (plVar13 = (longlong *)plVar3[3], plVar13 == (longlong *)0x0)) ||
     ((int)plVar13[2] != 0x52444441)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc0,
                &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,plVar3,(char)plVar13);
    }
    uVar10 = 0xc0000008;
  }
  else {
    uVar17 = SUB81(plVar13,0);
    uVar16 = SUB81(plVar3,0);
    if ((*(uint *)(plVar3 + 4) & 0x2000) == 0) {
      if (*(int *)(param_3 + 8) != 0) {
        plVar1 = plVar13 + 0x37;
        uVar6 = KeAcquireSpinLockRaiseToDpc(plVar1);
        plVar2 = plVar3 + 0x2d;
        uVar7 = KeAcquireSpinLockRaiseToDpc(plVar2);
        uVar10 = PgmCheckSetCancelRoutine(param_2,PgmCancelReceiveIrp,'\x01');
        if ((int)uVar10 < 0) {
          KeReleaseSpinLock(plVar2,uVar7);
          KeReleaseSpinLock(plVar1,uVar6);
          IoReleaseCancelSpinLock(local_res8 & 0xff);
          KeReleaseSpinLock(&DAT_140036808,uVar5);
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
            WPP_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc3,
                       &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,param_2,uVar16,uVar17);
          }
          return 0xc0000120;
        }
        IoReleaseCancelSpinLock(uVar7);
        *(int *)((longlong)plVar13 + 0x14) = *(int *)((longlong)plVar13 + 0x14) + 1;
        *(int *)((longlong)plVar3 + 0x14) = *(int *)((longlong)plVar3 + 0x14) + 1;
        KeReleaseSpinLock(&DAT_140036808,uVar6);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
          WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc4,
                    &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,param_2,uVar16);
        }
        puVar11 = auStackY_68;
        plVar12 = (longlong *)(param_2 + 0xa8);
        lVar8 = plVar3[6] + 200;
        plVar9 = *(longlong **)(plVar3[6] + 0xd0);
        if (*plVar9 != lVar8) {
          plVar9 = (longlong *)0x3;
          pcVar4 = (code *)swi(0x29);
          lVar8 = (*pcVar4)();
          puVar11 = auStackY_60;
        }
        *(longlong **)(param_2 + 0xb0) = plVar9;
        plVar15 = (longlong *)(puVar11 + 0x70);
        *plVar12 = lVar8;
        puVar14 = puVar11 + 0x80;
        *plVar9 = (longlong)plVar12;
        *(longlong **)(lVar8 + 8) = plVar12;
        *(uint *)(plVar3 + 4) = *(uint *)(plVar3 + 4) & 0xfffff7ff;
        *(undefined8 *)(puVar11 + -8) = 0x140014e74;
        plVar9 = plVar3;
        CheckIndicatePendedData((longlong)plVar13,(longlong)plVar3,puVar14,(undefined1 *)plVar15);
        uVar10 = CONCAT71((int7)((ulonglong)plVar9 >> 8),puVar11[0x70]);
        *(undefined8 *)(puVar11 + -8) = 0x140014e82;
        KeReleaseSpinLock(plVar2,uVar10);
        uVar10 = CONCAT71((int7)((ulonglong)uVar10 >> 8),puVar11[0x80]);
        *(undefined8 *)(puVar11 + -8) = 0x140014e98;
        KeReleaseSpinLock(plVar1);
        *(undefined8 *)(puVar11 + -8) = 0x140014ea5;
        PgmDereferenceSessionCommon(plVar3,uVar10,puVar14,plVar15);
        *(undefined8 *)(puVar11 + -8) = 0x140014ead;
        PgmDereferenceAddress(plVar13,uVar10,puVar14,plVar15);
        return 0x103;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc2,
                  &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,plVar3,uVar17);
      }
      uVar10 = 0xc0000001;
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
        WPP_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc1,
                   &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,param_2,uVar16,uVar17);
      }
      uVar10 = 0xc0000120;
    }
  }
  IoReleaseCancelSpinLock(local_res8 & 0xff);
  KeReleaseSpinLock(&DAT_140036808,uVar5);
  *(undefined8 *)(param_2 + 0x38) = 0;
  return uVar10;
}



===== PgmSendNak @ 140014f38 =====

ulonglong PgmSendNak(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  ushort uVar2;
  uint uVar3;
  longlong lVar4;
  undefined1 uVar5;
  int iVar6;
  undefined4 *puVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  ushort uVar10;
  uint uVar11;
  ulonglong *puVar12;
  char *pcVar13;
  
  uVar10 = 0;
  if ((0x3e < (ushort)(*(short *)(param_2 + 0x10c) - 1U)) ||
     (puVar7 = (undefined4 *)ExAllocatePool2(0x40,300,0x326d6750), puVar7 == (undefined4 *)0x0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
              &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids);
    }
    return 0xc000009a;
  }
  puVar12 = (ulonglong *)(puVar7 + 2);
  *puVar7 = 2;
  uVar2 = *(ushort *)(*(longlong *)(param_1 + 0x30) + 0x2c);
  *(ushort *)puVar12 = uVar2 >> 8 | uVar2 << 8;
  *(ushort *)((longlong)puVar7 + 10) =
       *(ushort *)(param_1 + 0x46) >> 8 | *(ushort *)(param_1 + 0x46) << 8;
  *(undefined1 *)(puVar7 + 3) = 8;
  if (*(short *)(param_2 + 0x10e) == 2) {
    *(undefined1 *)((longlong)puVar7 + 0xd) = 0x80;
    plVar1 = (longlong *)(*(longlong *)(param_1 + 0x30) + 0x388);
    *plVar1 = *plVar1 + (ulonglong)*(ushort *)(param_2 + 0x10c);
  }
  else {
    *(undefined1 *)((longlong)puVar7 + 0xd) = 0;
    plVar1 = (longlong *)(*(longlong *)(param_1 + 0x30) + 0x380);
    *plVar1 = *plVar1 + (ulonglong)*(ushort *)(param_2 + 0x10c);
  }
  puVar7[4] = *(undefined4 *)(param_1 + 0x40);
  *(undefined2 *)(puVar7 + 5) = *(undefined2 *)(param_1 + 0x44);
  uVar11 = *(uint *)(param_2 + 0x10);
  *(undefined2 *)(puVar7 + 7) = 0x100;
  puVar7[6] = uVar11 >> 0x18 | (uVar11 & 0xff0000) >> 8 | (uVar11 & 0xff00) << 8 | uVar11 << 0x18;
  uVar11 = *(uint *)(*(longlong *)(param_1 + 0x30) + 0x20);
  puVar7[8] = uVar11 >> 0x18 | (uVar11 & 0xff0000) >> 8 | (uVar11 & 0xff00) << 8 | uVar11 << 0x18;
  *(undefined2 *)(puVar7 + 9) = 0x100;
  uVar11 = *(uint *)(*(longlong *)(param_1 + 0x30) + 0x28);
  puVar7[10] = uVar11 >> 0x18 | (uVar11 & 0xff0000) >> 8 | (uVar11 & 0xff00) << 8 | uVar11 << 0x18;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
             &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,*(undefined4 *)(param_2 + 0x10));
  }
  if (1 < *(ushort *)(param_2 + 0x10c)) {
    *(undefined2 *)(puVar7 + 0xb) = 0x400;
    uVar11 = 1;
    *(undefined1 *)(puVar7 + 0xc) = 2;
    *(char *)((longlong)puVar7 + 0x31) = *(char *)(param_2 + 0x10c) << 2;
    if (1 < *(ushort *)(param_2 + 0x10c)) {
      do {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
                   &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,
                   *(undefined4 *)(param_2 + 0x10 + (ulonglong)uVar11 * 4));
        }
        uVar8 = (ulonglong)uVar11;
        uVar11 = uVar11 + 1;
        uVar3 = *(uint *)(param_2 + 0x10 + uVar8 * 4);
        puVar7[uVar8 + 0xc] =
             uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
      } while (uVar11 < *(ushort *)(param_2 + 0x10c));
    }
    *(byte *)(puVar7 + 0xc) = *(byte *)(puVar7 + 0xc) | 0x80;
    *(byte *)((longlong)puVar7 + 0xd) = *(byte *)((longlong)puVar7 + 0xd) | 3;
    uVar10 = *(byte *)((longlong)puVar7 + 0x31) + 4;
    *(ushort *)((longlong)puVar7 + 0x2e) = uVar10 >> 8 | uVar10 * 0x100;
  }
  uVar10 = uVar10 + 0x24;
  *(undefined2 *)((longlong)puVar7 + 0xe) = 0;
  iVar6 = tcpxsum(0,puVar12,(uint)uVar10);
  *(ushort *)((longlong)puVar7 + 0xe) = ~(ushort)iVar6;
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x168);
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  KeReleaseSpinLock(param_1 + 0x168,uVar5);
  lVar4 = *(longlong *)(param_1 + 0x30);
  TdiSendDatagram(*(undefined8 *)(*(longlong *)(lVar4 + 0x18) + 0x48),
                  *(undefined8 *)(*(longlong *)(lVar4 + 0x18) + 0x50),puVar12,(uint)uVar10,
                  PgmSendNakCompletion,param_1,puVar7,*(uint *)(lVar4 + 0x28),
                  *(ushort *)(lVar4 + 0x2c),'\0');
  lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0x18);
  uVar9 = *(undefined8 *)(lVar4 + 0x50);
  uVar8 = TdiSendDatagram(*(undefined8 *)(lVar4 + 0x48),uVar9,puVar12,(uint)uVar10,
                          PgmSendNakCompletion,param_1,puVar7,
                          *(uint *)(*(longlong *)(param_1 + 0x30) + 0x24),0x71,'\0');
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
    pcVar13 = "PARITY";
    if (*(short *)(param_2 + 0x10e) != 2) {
      pcVar13 = "SELECTIVE";
    }
    WPP_SF_sdddDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,puVar12,pcVar13,
                  (char)*(ushort *)(param_2 + 0x10c),(char)*(undefined4 *)(param_2 + 0x10),
                  (char)*(undefined4 *)(param_2 + 0xc + (ulonglong)*(ushort *)(param_2 + 0x10c) * 4)
                  ,(char)*(undefined4 *)(*(longlong *)(param_1 + 0x30) + 0x20));
  }
  return uVar8 & 0xffffffff;
}



===== PgmSendNakCompletion @ 1400152a0 =====

void PgmSendNakCompletion(longlong *param_1,int *param_2,uint param_3,longlong *param_4)

{
  undefined8 uVar1;
  undefined **ppuVar2;
  longlong *plVar3;
  
  plVar3 = (longlong *)(ulonglong)param_3;
  KeAcquireSpinLockRaiseToDpc(param_1 + 0x2d);
  if ((int)param_3 < 0) {
    ppuVar2 = &WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      ppuVar2 = (undefined **)&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
               &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,param_3);
      param_4 = plVar3;
    }
  }
  else {
    ppuVar2 = &WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      ppuVar2 = (undefined **)&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
              &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids);
    }
  }
  *param_2 = *param_2 + -1;
  if (*param_2 == 0) {
    KeReleaseSpinLock();
    uVar1 = 0;
    ExFreePoolWithTag(param_2);
    PgmDereferenceSessionCommon(param_1,uVar1,ppuVar2,param_4);
  }
  else {
    KeReleaseSpinLock(param_1 + 0x2d);
  }
  return;
}



===== ProcessDataPacket @ 1400153a4 =====

undefined8
ProcessDataPacket(ulonglong param_1,longlong param_2,uint param_3,void *param_4,char param_5)

{
  longlong *plVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  char cVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  uint uVar9;
  undefined1 local_res18 [8];
  char cVar10;
  undefined1 local_38 [4];
  uint local_34 [3];
  
  if (param_3 < 0x18) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7c,
                &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,param_3,0x18);
    }
    uVar7 = 0xc000021b;
  }
  else {
    local_38[0] = KeAcquireSpinLockRaiseToDpc(param_1 + 0x1b8);
    local_res18[0] = KeAcquireSpinLockRaiseToDpc(param_2 + 0x168);
    if ((*(uint *)(param_2 + 0x20) & 0x2100) == 0) {
      uVar2 = *(uint *)((longlong)param_4 + 0x14);
      uVar7 = 0;
      uVar3 = *(uint *)((longlong)param_4 + 0x10);
      uVar9 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      local_34[0] = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
      if (0 < (int)(uVar9 - *(int *)(*(longlong *)(param_2 + 0x30) + 0x30))) {
        *(uint *)(*(longlong *)(param_2 + 0x30) + 0x30) = uVar9;
      }
      lVar5 = *(longlong *)(param_2 + 0x30);
      if (*(int *)(lVar5 + 0x38) - *(int *)(lVar5 + 0x30) < 0) {
        *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) | 0x100;
        iVar4 = *(int *)(lVar5 + 0x3c);
        cVar10 = (char)(uVar3 >> 0x18);
        cVar6 = (char)(uVar2 >> 0x18);
        if ((*(int *)(lVar5 + 0x30) - iVar4) + -1 < 1) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
            WPP_SF_ddddddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7f,
                           &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,
                           *(undefined4 *)(lVar5 + 0x38),
                           (char)*(undefined4 *)(*(longlong *)(lVar5 + 0x88) + 0x10),
                           *(undefined1 *)(*(longlong *)(lVar5 + 0x88) + 0x3c),(char)iVar4,
                           (char)*(int *)(lVar5 + 0x30),cVar10,(cVar10 - cVar6) + '\x01');
          }
        }
        else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_dddddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7e,(ulonglong)uVar9,
                        (local_34[0] - iVar4) + 1,(char)*(undefined4 *)(lVar5 + 0x38),(char)iVar4,
                        cVar6,cVar10,(cVar10 - cVar6) + '\x01');
        }
      }
      else if ((int)(*(int *)(lVar5 + 0x38) - local_34[0]) < 1) {
        if (param_5 == '\x04') {
          UpdateRealTimeWindowInformation(param_2,local_34[0],uVar9);
        }
        uVar8 = PgmHandleNewData(local_34,param_1,param_2,(ushort)param_3,param_4,param_5,local_38,
                                 local_res18);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
          WPP_SF_dDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x81,
                     &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,(int)uVar8,(char)local_34[0],
                     (char)*(undefined4 *)(*(longlong *)(param_2 + 0x30) + 0x34));
        }
        CheckIndicatePendedData(param_1,param_2,local_38,local_res18);
      }
      else {
        *(longlong *)(lVar5 + 0x368) = *(longlong *)(lVar5 + 0x368) + 1;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
          WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x80,
                    &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,local_34[0],
                    (char)*(undefined4 *)(*(longlong *)(param_2 + 0x30) + 0x38));
        }
      }
      CheckIndicateDisconnect(param_1,param_2,local_38,local_res18,'\x01');
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7d,
                &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids);
      }
      uVar7 = 0xc000021b;
      plVar1 = (longlong *)(*(longlong *)(param_2 + 0x30) + 0x358);
      *plVar1 = *plVar1 + 1;
    }
    KeReleaseSpinLock(param_2 + 0x168,local_res18[0]);
    KeReleaseSpinLock(param_1 + 0x1b8,local_38[0]);
  }
  return uVar7;
}



===== ProcessNakOption @ 140015710 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 ProcessNakOption(longlong param_1,longlong param_2)

{
  uint uVar1;
  byte bVar2;
  undefined8 uVar3;
  uint *puVar4;
  ulonglong uVar5;
  byte bVar6;
  undefined1 auStack_138 [32];
  uint local_118 [64];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_138;
  bVar6 = *(byte *)(param_1 + 1);
  if ((byte)(bVar6 - 8) < 0xf5) {
    uVar5 = (longlong)(int)(bVar6 - 4) / 4;
    bVar2 = (byte)uVar5;
    memmove(local_118,(void *)(param_1 + 4),(ulonglong)bVar6 - 4);
    bVar6 = 0;
    if (bVar2 != 0) {
      uVar5 = uVar5 & 0xff;
      puVar4 = local_118;
      do {
        uVar1 = *puVar4;
        *(uint *)((param_2 - (longlong)local_118) + 4 + (longlong)puVar4) =
             uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
        puVar4 = puVar4 + 1;
        uVar5 = uVar5 - 1;
        bVar6 = bVar2;
      } while (uVar5 != 0);
    }
    *(ushort *)(param_2 + 0xfc) = (ushort)bVar6;
    uVar3 = 0;
  }
  else {
    uVar3 = 0xc0000001;
  }
  return uVar3;
}



===== ProcessOptions @ 1400157d4 =====

int ProcessOptions(char *param_1,uint param_2,int param_3,longlong param_4,longlong param_5)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined8 uVar4;
  byte bVar5;
  undefined2 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined1 uVar11;
  undefined4 in_stack_ffffffffffffff78;
  undefined4 in_stack_ffffffffffffff7c;
  undefined1 uVar12;
  ushort local_68;
  uint local_60;
  int local_5c;
  byte *local_58;
  uint local_50;
  
  local_68 = 0;
  uVar10 = 0;
  *(undefined2 *)(param_4 + 2) = 0;
  *(undefined4 *)(param_4 + 4) = 0;
  if (4 < param_2) {
    local_68 = *(ushort *)(param_1 + 2) >> 8 | *(ushort *)(param_1 + 2) << 8;
  }
  uVar12 = (undefined1)local_68;
  if ((((param_2 < 8) || (*param_1 != '\0')) || (param_1[1] != '\x04')) || (param_2 < local_68)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_ddddD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)(byte)param_1[1],
                   (ulonglong)local_68,param_2,
                   CONCAT44(in_stack_ffffffffffffff7c,in_stack_ffffffffffffff78),uVar12,param_1[1],
                   *param_1);
    }
    return -0x3fffffff;
  }
  local_58 = (byte *)(param_1 + 4);
  local_5c = 0;
  local_60 = param_2 - 4;
  iVar3 = 0;
LAB_140015881:
  bVar1 = local_58[1];
  uVar9 = (uint)bVar1;
  if ((local_60 < bVar1) || (bVar1 == 0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                 &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,uVar9,(char)local_60,
                 (char)local_5c);
    }
    goto LAB_140015fab;
  }
  bVar2 = *local_58;
  bVar5 = bVar2 & 0x7f;
  if (bVar5 == 0x7f) {
LAB_140015d08:
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_dDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
                 &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,param_3,bVar2 & 0x7f,bVar1);
    }
    uVar10 = uVar10 | 0x80000000;
  }
  else {
    if (bVar5 < 0xb) {
      if (bVar5 == 10) {
        if (bVar1 == 8) {
          uVar9 = *(uint *)(local_58 + 4);
          if (uVar9 == 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
                       &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,0);
            }
            iVar3 = -0x3fffffff;
          }
          else {
            uVar8 = uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 << 0x18;
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                       &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,uVar8);
            }
            if (0x80 < uVar8) {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
                WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                         &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,uVar8);
              }
              iVar3 = -0x3fffffff;
            }
            *(char *)(param_4 + 0x1d) = (char)(uVar9 >> 0x18);
            uVar10 = uVar10 | 0x800;
          }
          goto LAB_140015d43;
        }
        iVar3 = -0x3fffffff;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return -0x3fffffff;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) {
          uVar6 = 0x22;
          goto LAB_140015a50;
        }
        goto LAB_140015fb2;
      }
      if (bVar5 == 1) {
        if (bVar1 == 0x10) {
          uVar9 = *(uint *)(local_58 + 0xc);
          local_50 = (uint)*(undefined8 *)(local_58 + 4);
          uVar8 = (uint)((ulonglong)*(undefined8 *)(local_58 + 4) >> 0x20);
          if ((local_58[2] & 4) == 0) {
            uVar7 = uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 << 0x18;
            uVar8 = uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 << 0x18;
            uVar11 = (undefined1)(uVar9 >> 0x18);
            if ((uVar7 == 0) || (uVar7 < uVar8)) {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
                WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                          &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,uVar8,uVar11);
              }
              iVar3 = -0x3fffffff;
            }
            else {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
                WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                          &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,uVar8,uVar11);
              }
              uVar10 = uVar10 | 1;
              *(uint *)(param_4 + 0x10) =
                   local_50 >> 0x18 | (local_50 & 0xff0000) >> 8 | (local_50 & 0xff00) << 8 |
                   local_50 << 0x18;
              *(uint *)(param_4 + 0x14) = uVar8;
              *(uint *)(param_4 + 0x18) = uVar7;
            }
          }
          else {
            *(uint *)(param_4 + 0x10) = local_50;
            *(uint *)(param_4 + 0x14) = uVar8;
            uVar10 = uVar10 | 1;
            *(uint *)(param_4 + 0x18) = uVar9;
            *(byte *)(param_4 + 0x1e) = local_58[3];
          }
        }
        else {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
            WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                      &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,uVar9,0x10);
          }
          iVar3 = -0x3fffffff;
        }
        goto LAB_140015d43;
      }
      if (bVar5 != 2) {
        if (bVar5 != 3) {
          if (((bVar5 == 4) || (bVar5 == 5)) || (bVar5 == 7)) goto LAB_140015d08;
          if (bVar5 == 8) {
            if (bVar1 == 8) {
              uVar9 = *(uint *)(local_58 + 4);
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
                WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                          &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,(uint)local_58[3],
                          (char)(uVar9 >> 0x18));
              }
              uVar10 = uVar10 | 0x200;
              *(byte *)(param_4 + 0x1f) = local_58[3];
LAB_14001593e:
              *(char *)(param_4 + 0x1c) = (char)(uVar9 >> 0x18);
              goto LAB_140015d43;
            }
            iVar3 = -0x3fffffff;
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return -0x3fffffff;
            }
            if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) goto LAB_140015fb2;
            uVar6 = 0x1c;
          }
          else {
            if (bVar5 != 9) goto LAB_140015edc;
            if (bVar1 == 8) {
              uVar9 = *(uint *)(local_58 + 4);
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
                WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                         &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,
                         uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 |
                         uVar9 << 0x18);
              }
              uVar10 = uVar10 | 0x400;
              goto LAB_14001593e;
            }
            iVar3 = -0x3fffffff;
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return -0x3fffffff;
            }
            if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) goto LAB_140015fb2;
            uVar6 = 0x1e;
          }
LAB_140015a50:
          uVar11 = 8;
          goto LAB_140015a58;
        }
        if (bVar1 == 8) {
          uVar9 = *(uint *)(local_58 + 4);
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                     &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,
                     uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 << 0x18
                    );
          }
          *(uint *)(param_4 + 0xc) =
               uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 << 0x18;
          uVar10 = uVar10 | 8;
          goto LAB_140015d43;
        }
        iVar3 = -0x3fffffff;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return -0x3fffffff;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) {
          uVar6 = 0x14;
          goto LAB_140015a50;
        }
        goto LAB_140015fb2;
      }
      if (2 < param_3 - 8U) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          WPP_SF_DDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                     &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,param_3,bVar1,(char)param_4);
        }
LAB_140015fab:
        iVar3 = -0x3fffffff;
        goto LAB_140015fb2;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                 &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,(int)(bVar1 - 4) / 4);
      }
      if (param_5 == 0) goto LAB_140015fab;
      uVar4 = ProcessNakOption((longlong)local_58,param_5);
      iVar3 = (int)uVar4;
      if (iVar3 != 0) goto LAB_140015d43;
      uVar10 = uVar10 | 4;
      goto LAB_140015d50;
    }
    if ((bVar5 == 0xb) || (bVar5 == 0xc)) goto LAB_140015d08;
    if (bVar5 == 0xd) {
      if (bVar1 == 4) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                  &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids);
        }
        uVar10 = uVar10 | 0x20;
      }
      else {
        iVar3 = -0x3fffffff;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return -0x3fffffff;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) goto LAB_140015fb2;
        uVar6 = 0x16;
LAB_140015e91:
        uVar11 = 4;
LAB_140015a58:
        iVar3 = -0x3fffffff;
        WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
                  &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,uVar9,uVar11);
      }
    }
    else {
      if (bVar5 != 0xe) {
        if (bVar5 != 0xf) {
          if ((bVar5 != 0x10) && (bVar5 != 0x11)) {
LAB_140015edc:
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
              WPP_SF_dDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
                         &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,param_3,bVar2 & 0x7f,bVar1
                        );
            }
            goto LAB_140015fab;
          }
          goto LAB_140015d08;
        }
        if (bVar1 == 4) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                    &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids);
          }
          uVar10 = uVar10 | 0x80;
          goto LAB_140015d43;
        }
        iVar3 = -0x3fffffff;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return -0x3fffffff;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) {
          uVar6 = 0x1a;
          goto LAB_140015e91;
        }
        goto LAB_140015fb2;
      }
      if (bVar1 != 4) {
        iVar3 = -0x3fffffff;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return -0x3fffffff;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) {
          uVar6 = 0x18;
          goto LAB_140015e91;
        }
        goto LAB_140015fb2;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids);
      }
      uVar10 = uVar10 | 0x40;
    }
  }
LAB_140015d43:
  if (iVar3 < 0) goto LAB_140015fb2;
LAB_140015d50:
  local_5c = local_5c + 1;
  local_60 = local_60 - local_58[1];
  if (((char)*local_58 < '\0') || (local_58 = local_58 + local_58[1], local_60 < 4)) {
    if (local_68 + local_60 == param_2) {
      *(ushort *)(param_4 + 2) = local_68;
      *(uint *)(param_4 + 4) = uVar10;
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_dDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
                   &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,local_60,uVar12,(char)param_2);
      }
      iVar3 = -0x3ffffdfa;
    }
LAB_140015fb2:
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
                &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,local_5c,uVar12);
    }
    return iVar3;
  }
  goto LAB_140015881;
}



===== ProcessReceiveCompletionRoutine @ 140016040 =====

undefined8
ProcessReceiveCompletionRoutine
          (undefined8 param_1,longlong *param_2,ulonglong *param_3,longlong *param_4)

{
  longlong lVar1;
  ulonglong *puVar2;
  ulonglong uVar3;
  undefined **ppuVar4;
  ulonglong *puVar5;
  undefined4 local_res10 [2];
  undefined8 local_res18;
  ulonglong in_stack_ffffffffffffffb8;
  
  lVar1 = param_2[1];
  local_res18 = 0;
  local_res10[0] = 0;
  if ((*(byte *)(lVar1 + 10) & 5) == 0) {
    param_4 = (longlong *)0x0;
    puVar5 = (ulonglong *)0x1;
    puVar2 = (ulonglong *)
             MmMapLockedPagesSpecifyCache
                       (lVar1,0,1,0,in_stack_ffffffffffffffb8 & 0xffffffff00000000,0x40000020);
  }
  else {
    puVar2 = *(ulonglong **)(lVar1 + 0x18);
    puVar5 = param_3;
  }
  if (puVar2 == (ulonglong *)0x0) {
    ppuVar4 = &WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      puVar5 = (ulonglong *)&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids;
      ppuVar4 = (undefined **)0xb0;
      param_4 = param_2;
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb0,
                &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,param_2,(char)param_3);
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      WPP_SF_qqDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
                  (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),puVar5,param_2,(char)param_3,
                  (char)param_2[6],(char)param_2[7]);
    }
    puVar5 = (ulonglong *)param_3[2];
    param_4 = (longlong *)0x0;
    ppuVar4 = (undefined **)(ulonglong)(uint)param_3[1];
    TdiRcvDatagramHandler
              ((ulonglong *)*param_3,(uint)param_3[1],puVar5,(ulonglong *)0x0,0,0x20,
               *(uint *)(param_2 + 7),*(uint *)(param_2 + 7),local_res10,puVar2,&local_res18);
  }
  uVar3 = Feature_3579806010__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 != 0) {
    PgmDereferenceAddress((longlong *)*param_3,ppuVar4,puVar5,param_4);
  }
  IoFreeMdl(param_2[1]);
  param_2[1] = 0;
  IoFreeIrp(param_2);
  ExFreePoolWithTag(param_3,0);
  return 0xc0000016;
}



===== ProcessSpmPacket @ 1400161bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140016547) */

ulonglong ProcessSpmPacket(longlong param_1,longlong param_2,uint param_3,longlong param_4)

{
  int *piVar1;
  longlong lVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  longlong lVar10;
  undefined8 uVar11;
  undefined2 uVar12;
  ushort uVar13;
  longlong *plVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  undefined1 auStackY_e8 [32];
  undefined1 uVar18;
  char cVar19;
  char cVar20;
  byte local_98;
  undefined1 local_97 [7];
  longlong local_90;
  undefined8 local_88;
  longlong local_80;
  longlong local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStackY_e8;
  uVar9 = 0;
  local_88 = CONCAT44(local_88._4_4_,param_3);
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_90 = param_1;
  if ((*(byte *)(param_4 + 5) & 1) != 0) {
    iVar5 = ProcessOptions((char *)(param_4 + 0x24),param_3 - 0x24,*(byte *)(param_4 + 4) & 0xf,
                           (longlong)&local_70,0);
    if (iVar5 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc000021b;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
        return 0xc000021b;
      }
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x82,
               &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,iVar5);
      return 0xc000021b;
    }
    param_3 = (uint)local_88;
  }
  uVar11 = *(undefined8 *)(param_4 + 0x1c);
  uVar13 = *(ushort *)(param_4 + 0xe) >> 8 | *(ushort *)(param_4 + 0xe) << 8;
  uVar8 = (ulonglong)uVar13;
  local_88._4_4_ = (uint)((ulonglong)uVar11 >> 0x20);
  uVar15 = local_88._4_4_;
  uVar18 = (undefined1)((ulonglong)uVar11 >> 0x20);
  if (((uVar13 != 0) || ((ushort)((ushort)uVar11 >> 8 | (ushort)uVar11 << 8) != 1)) ||
     (local_88._4_4_ == 0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      local_88 = uVar11;
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x83,
                &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,(uint)uVar13,uVar18);
    }
    return 0xc000021b;
  }
  uVar17 = *(uint *)(param_4 + 0x10);
  uVar6 = *(uint *)(param_4 + 0x18);
  uVar3 = *(uint *)(param_4 + 0x14);
  local_80 = CONCAT44(local_80._4_4_,
                      uVar17 >> 0x18 | (uVar17 & 0xff0000) >> 8 | (uVar17 & 0xff00) << 8 |
                      uVar17 << 0x18);
  uVar17 = uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18;
  local_88 = CONCAT44(local_88._4_4_,uVar17);
  uVar16 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  if (local_70._2_2_ + 0x24 != param_3) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000021b;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return 0xc000021b;
    }
    WPP_SF_dDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x84,
               &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,param_3,(char)(local_70 >> 0x10),0);
    return 0xc000021b;
  }
  if ((((local_70 & 0x20000000000) != 0) && (uStack_58._7_1_ != '\0')) &&
     ((1 < uStack_58._4_1_ && ((uStack_58._4_1_ & uStack_58._4_1_ - 1) != 0)))) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000021b;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return 0xc000021b;
    }
    WPP_SF_c(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),2,0,uStack_58._4_1_);
    return 0xc000021b;
  }
  lVar2 = local_90 + 0x1b8;
  local_98 = KeAcquireSpinLockRaiseToDpc(lVar2);
  uVar8 = CONCAT71((int7)(uVar8 >> 8),local_98);
  cVar20 = (char)(uVar6 >> 0x18);
  if (param_2 == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
      pcVar7 = "EN";
      if ((local_70 & 0x20000000000) == 0) {
        pcVar7 = "DIS";
      }
      WPP_SF_dDsdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),"DIS",uVar8,(int)local_80,uVar18,
                   pcVar7,(char)(uVar3 >> 0x18),cVar20);
      uVar8 = (ulonglong)local_98;
    }
    *(uint *)(local_90 + 0x1a4) =
         uVar15 >> 0x18 | (uVar15 & 0xff0000) >> 8 | (uVar15 & 0xff00) << 8 | uVar15 << 0x18;
    if ((((local_70 & 0x20000000000) != 0) && (uStack_58._7_1_ != '\0')) && (1 < uStack_58._4_1_)) {
      *(char *)(local_90 + 0x131) = uStack_58._7_1_;
      *(byte *)(local_90 + 0x130) = uStack_58._4_1_;
    }
    KeReleaseSpinLock(local_90 + 0x1b8,uVar8 & 0xff);
    return 0;
  }
  local_78 = param_2 + 0x168;
  local_97[0] = KeAcquireSpinLockRaiseToDpc(local_78);
  uVar6 = (int)DAT_140036750 - *(int *)(*(longlong *)(param_2 + 0x30) + 0x2d8);
  if (uVar6 != 0) {
    *(undefined8 *)(*(longlong *)(param_2 + 0x30) + 0x2d8) = DAT_140036750;
    if (*(uint *)(*(longlong *)(param_2 + 0x30) + 0x2c4) < uVar6) {
      *(uint *)(*(longlong *)(param_2 + 0x30) + 0x2c4) = uVar6;
    }
  }
  piVar1 = (int *)(*(longlong *)(param_2 + 0x30) + 0x48);
  if ((*(int *)(*(longlong *)(param_2 + 0x30) + 0x24) != 0) && ((int)local_80 - *piVar1 < 1)) {
    KeReleaseSpinLock(local_78,CONCAT71((int7)((ulonglong)piVar1 >> 8),local_97[0]));
    KeReleaseSpinLock(lVar2,local_98);
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000021b;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
      return 0xc000021b;
    }
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x87,
            &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids);
    return 0xc000021b;
  }
  *piVar1 = (int)local_80;
  *(uint *)(*(longlong *)(param_2 + 0x30) + 0x24) =
       uVar15 >> 0x18 | (uVar15 & 0xff0000) >> 8 | (uVar15 & 0xff00) << 8 | uVar15 << 0x18;
  UpdateRealTimeWindowInformation(param_2,uVar17,uVar16);
  plVar14 = *(longlong **)(param_2 + 0x30);
  if (0 < (int)(uVar16 - (int)plVar14[6])) {
    *(uint *)(plVar14 + 6) = uVar16;
  }
  lVar2 = *(longlong *)(param_2 + 0x30);
  if (0 < *(int *)(lVar2 + 0x30) - *(int *)(lVar2 + 0x38)) {
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) | 0x100;
    iVar5 = *(int *)(lVar2 + 0x3c);
    cVar19 = (char)*(int *)(lVar2 + 0x30);
    if ((*(int *)(lVar2 + 0x30) - iVar5) + -1 < 1) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        plVar14 = (longlong *)&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids;
        WPP_SF_ddddddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x89,
                       &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,
                       *(undefined4 *)(lVar2 + 0x38),
                       (char)*(undefined4 *)(*(longlong *)(lVar2 + 0x88) + 0x10),
                       *(undefined1 *)(*(longlong *)(lVar2 + 0x88) + 0x3c),(char)iVar5,cVar19,cVar20
                       ,(cVar20 - cVar19) + '\x01');
      }
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_dddddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x88,plVar14,(uVar17 - iVar5) + 1,
                    (char)*(undefined4 *)(lVar2 + 0x38),(char)iVar5,cVar19,cVar20,
                    (cVar20 - cVar19) + '\x01');
    }
  }
  local_80 = 0;
  if (-1 < (int)(uVar17 - *(int *)(*(longlong *)(param_2 + 0x30) + 0x38))) {
    plVar14 = &local_80;
    uVar8 = CheckAndAddNakRequests(param_2,(uint *)&local_88,plVar14,1,'\x01');
    if ((int)uVar8 < 0) {
      KeReleaseSpinLock(local_78,local_97[0]);
      KeReleaseSpinLock(local_90 + 0x1b8,local_98);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8a,
                 &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,(int)uVar8);
      }
      return uVar8 & 0xffffffff;
    }
    uVar17 = (uint)local_88;
  }
  lVar2 = local_80;
  if ((local_70 & 0x10000000000) == 0) {
    if ((char)(local_70 >> 0x20) < '\0') {
      *(uint *)(*(longlong *)(param_2 + 0x30) + 0x44) = uVar17;
      *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) | 0x100;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        uVar12 = 0x8c;
        goto LAB_14001676e;
      }
    }
    else if ((local_70 & 0x4000000000) != 0) {
      *(uint *)(*(longlong *)(param_2 + 0x30) + 0x44) = uVar17;
      *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) | 0x80;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        lVar10 = *(longlong *)(param_2 + 0x30);
        WPP_SF_ddddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8d,plVar14,
                     *(undefined4 *)(lVar10 + 0x44),(char)*(undefined4 *)(lVar10 + 0x34),
                     (char)*(undefined4 *)(lVar10 + 0x38),(char)*(undefined4 *)(lVar10 + 0x40),
                     (char)*(undefined4 *)(lVar10 + 0x3c));
      }
      if (lVar2 != 0) {
        *(char *)(lVar2 + 0x39) = ((char)uVar17 - *(char *)(lVar2 + 0x10)) + '\x01';
        RemoveRedundantNaks(param_2,lVar2,'\x01');
        AdjustReceiveBufferLists(param_2);
      }
    }
  }
  else {
    *(undefined4 *)(*(longlong *)(param_2 + 0x30) + 0x44) =
         *(undefined4 *)(*(longlong *)(param_2 + 0x30) + 0x3c);
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) | 0x100;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      uVar12 = 0x8b;
LAB_14001676e:
      lVar2 = *(longlong *)(param_2 + 0x30);
      WPP_SF_dDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar12,
                 &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,*(undefined4 *)(lVar2 + 0x44),
                 (char)*(undefined4 *)(lVar2 + 0x34),(char)*(undefined4 *)(lVar2 + 0x3c));
    }
  }
  lVar2 = local_90;
  bVar4 = CheckIndicateDisconnect(local_90,param_2,&local_98,local_97,'\x01');
  if (bVar4 != 0) goto LAB_140016ae9;
  if ((local_70 & 0x20000000000) == 0) goto LAB_140016be5;
  if (((*(char *)(param_2 + 0xa0) != '\x01') || (uStack_58._7_1_ == '\0')) || (uStack_58._4_1_ < 2))
  {
LAB_140016b43:
    if ((local_70 & 0x80000000000) != 0) {
      bVar4 = *(byte *)(param_2 + 0xa0);
      uVar15 = (uint)uStack_58._5_1_;
      if ((((uStack_58._5_1_ == 0) || (bVar4 <= uStack_58._5_1_)) ||
          ((int)((uVar17 & -(uint)bVar4) - *(int *)(*(longlong *)(param_2 + 0x30) + 0x38)) < 0)) ||
         ((uVar15 = (uint)uStack_58._5_1_,
          lVar10 = FindReceiverEntry(*(longlong *)(param_2 + 0x30),uVar17 & -(uint)bVar4),
          lVar10 == 0 || (*(byte *)(lVar10 + 0x39) != bVar4)))) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
          WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x94,
                    &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,uVar15,bVar4);
        }
      }
      else {
        *(char *)(lVar10 + 0x39) = (char)uVar15;
        if (*(int *)(lVar10 + 0x10) == *(int *)(*(longlong *)(param_2 + 0x30) + 0x3c)) {
          *(uint *)(*(longlong *)(param_2 + 0x30) + 0x40) =
               *(int *)(lVar10 + 0x10) + (uStack_58._5_1_ - 1);
        }
        RemoveRedundantNaks(param_2,lVar10,'\x01');
      }
    }
LAB_140016be5:
    CheckIndicatePendedData(lVar2,param_2,&local_98,local_97);
    KeReleaseSpinLock(param_2 + 0x168,local_97[0]);
    KeReleaseSpinLock(lVar2 + 0x1b8,local_98);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x95,
                &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,
                *(undefined4 *)(*(longlong *)(param_2 + 0x30) + 0x34),
                (char)*(undefined4 *)(*(longlong *)(param_2 + 0x30) + 0x44));
    }
    return 0;
  }
  uVar9 = Feature_1533700408__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar9 == 0) {
    lVar10 = ExAllocatePool2(0x40,(uint)*(ushort *)(param_2 + 0x9a) * (uint)uStack_58._4_1_ * 2,
                             0x336d6750);
    *(longlong *)(param_2 + 0x90) = lVar10;
    if (lVar10 == 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        uVar12 = 0x91;
LAB_140016a04:
        WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar12,
                  &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,(uint)*(ushort *)(param_2 + 0x9a)
                  ,uStack_58._4_1_);
      }
    }
    else {
      uVar11 = CreateFECContext((uint *)(param_2 + 0x70),(uint)uStack_58._4_1_,0xff,'\x01');
      iVar5 = (int)uVar11;
      if (iVar5 < 0) {
        ExFreePoolWithTag(*(undefined8 *)(param_2 + 0x90),0);
        *(undefined8 *)(param_2 + 0x90) = 0;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          uVar12 = 0x92;
LAB_140016ad5:
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar12,
                   &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,iVar5);
        }
      }
      else {
        uVar9 = CoalesceSelectiveNaksIntoGroups(param_2,uStack_58._4_1_);
        iVar5 = (int)uVar9;
        if (-1 < iVar5) {
LAB_140016b1c:
          *(byte *)(param_2 + 0xa0) = uStack_58._4_1_;
          *(char *)(param_2 + 0xa1) = uStack_58._7_1_;
          if ((uStack_58 & 0x100000000000000) != 0) {
            *(undefined2 *)(*(longlong *)(param_2 + 0x30) + 0x2e) = 2;
          }
          goto LAB_140016b43;
        }
        DestroyFECContext(param_2 + 0x70);
        ExFreePoolWithTag(*(undefined8 *)(param_2 + 0x90),0);
        *(undefined8 *)(param_2 + 0x90) = 0;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          uVar12 = 0x93;
          goto LAB_140016ad5;
        }
      }
    }
  }
  else {
    if ((*(uint *)(param_2 + 0x20) & 0x400) != 0) goto LAB_140016b43;
    lVar10 = ExAllocatePool2(0x40,(uint)*(ushort *)(param_2 + 0x9a) * (uint)uStack_58._4_1_ * 2,
                             0x336d6750);
    *(longlong *)(param_2 + 0x90) = lVar10;
    if (lVar10 == 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        uVar12 = 0x8e;
        goto LAB_140016a04;
      }
    }
    else {
      uVar11 = CreateFECContext((uint *)(param_2 + 0x70),(uint)uStack_58._4_1_,0xff,'\x01');
      iVar5 = (int)uVar11;
      if (iVar5 < 0) {
        ExFreePoolWithTag(*(undefined8 *)(param_2 + 0x90),0);
        *(undefined8 *)(param_2 + 0x90) = 0;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          uVar12 = 0x8f;
          goto LAB_140016ad5;
        }
      }
      else {
        uVar9 = CoalesceSelectiveNaksIntoGroups(param_2,uStack_58._4_1_);
        iVar5 = (int)uVar9;
        if (-1 < iVar5) goto LAB_140016b1c;
        DestroyFECContext(param_2 + 0x70);
        ExFreePoolWithTag(*(undefined8 *)(param_2 + 0x90),0);
        *(undefined8 *)(param_2 + 0x90) = 0;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          uVar12 = 0x90;
          goto LAB_140016ad5;
        }
      }
    }
  }
  uVar9 = 0xc000021b;
LAB_140016ae9:
  KeReleaseSpinLock(param_2 + 0x168,local_97[0]);
  KeReleaseSpinLock(lVar2 + 0x1b8,local_98);
  return uVar9;
}



===== ReAllocateDataBuffer @ 140016cd0 =====

longlong ReAllocateDataBuffer(longlong param_1,longlong *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  
  uVar1 = *(uint *)((longlong)param_2 + 0x24);
  lVar3 = *param_2;
  *(undefined4 *)((longlong)param_2 + 0x24) = 0;
  *param_2 = 0;
  lVar4 = AllocateDataBuffer(param_1,param_2,param_3);
  if (lVar4 == 0) {
    *param_2 = lVar3;
    lVar4 = 0;
    *(uint *)((longlong)param_2 + 0x24) = uVar1;
  }
  else {
    uVar2 = *(uint *)((longlong)param_2 + 0x24);
    lVar4 = *param_2;
    *(uint *)((longlong)param_2 + 0x24) = uVar1;
    *param_2 = lVar3;
    FreeDataBuffer(param_1,param_2);
    uVar5 = uVar1 | 1;
    if ((uVar2 & 1) == 0) {
      uVar5 = uVar1 & 0xfffffffe;
    }
    *(uint *)((longlong)param_2 + 0x24) = uVar5;
    *param_2 = lVar4;
  }
  return lVar4;
}



===== ReceiveTimerTimeout @ 140016d60 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ReceiveTimerTimeout(void)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  code *pcVar4;
  bool bVar5;
  undefined1 uVar6;
  longlong lVar7;
  uint uVar8;
  longlong lVar9;
  ulonglong uVar10;
  longlong *plVar11;
  undefined8 uVar12;
  longlong *plVar13;
  undefined1 *puVar14;
  uint uVar15;
  undefined8 uVar16;
  longlong *plVar17;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [24];
  undefined1 local_28;
  undefined1 local_27 [15];
  
  bVar5 = true;
  local_28 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
  puVar14 = auStack_58;
  lVar7 = _DAT_fffff78000000008 - _DAT_140036748;
  if (DAT_140036740 * 0x100 < lVar7) {
    uVar15 = (uint)(lVar7 / DAT_140036740);
    lVar9 = (lVar7 / DAT_140036740 & 0xffffffffU) * DAT_140036740;
  }
  else {
    lVar9 = 0;
    uVar15 = 0;
    if (lVar7 <= DAT_140036740) goto LAB_140017148;
    do {
      lVar9 = lVar9 + DAT_140036740;
      lVar7 = lVar7 - DAT_140036740;
      uVar15 = uVar15 + 1;
    } while (DAT_140036740 < lVar7);
  }
  puVar14 = auStack_58;
  if (uVar15 != 0) {
    DAT_140036750 = DAT_140036750 + (ulonglong)uVar15;
    _DAT_140036748 = _DAT_140036748 + lVar9;
    plVar13 = (longlong *)&DAT_140036710;
    while (plVar13 = (longlong *)*plVar13, puVar14 = auStack_58,
          (undefined8 **)plVar13 != &DAT_140036710) {
      plVar2 = (longlong *)plVar13[2];
      plVar1 = plVar2 + 0x2d;
      uVar6 = KeAcquireSpinLockRaiseToDpc(plVar1);
      local_27[0] = uVar6;
      CheckForSessionTimeout((longlong)plVar2,(longlong)plVar13);
      uVar8 = *(uint *)(plVar2 + 4);
      if ((uVar8 & 0x140) != 0) {
        uVar8 = uVar8 & 0xfffffdff | 0x100;
        *(uint *)(plVar2 + 4) = uVar8;
      }
      if ((uVar8 >> 9 & 1) == 0) {
        if ((uVar8 >> 10 & 1) == 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
            WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
                      &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,plVar2,(char)plVar13[5]);
          }
          lVar7 = *plVar13;
          plVar3 = (longlong *)plVar13[1];
          if ((*(longlong **)(lVar7 + 8) != plVar13) || ((longlong *)*plVar3 != plVar13)) {
            pcVar4 = (code *)swi(0x29);
            (*pcVar4)(3);
            puVar14 = auStack_50;
            break;
          }
          *plVar3 = lVar7;
          *(longlong **)(lVar7 + 8) = plVar3;
          if ((undefined8 **)DAT_140036710 == &DAT_140036710) {
            bVar5 = false;
            DAT_140036758 = DAT_140036758 & 0xfffffffd;
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
                      &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids);
            }
          }
          KeReleaseSpinLock(&DAT_140036808,uVar6);
          plVar17 = (longlong *)local_27;
          uVar16 = 0;
          plVar11 = plVar2;
          CheckIndicateDisconnect
                    (plVar13[3],(longlong)plVar2,(undefined1 *)0x0,(undefined1 *)plVar17,'\0');
          uVar12 = CONCAT71((int7)((ulonglong)plVar11 >> 8),local_28);
          KeReleaseSpinLock(plVar1);
          PgmDereferenceAddress((longlong *)plVar13[3],uVar12,uVar16,plVar17);
          PgmDereferenceSessionCommon(plVar2,uVar12,uVar16,plVar17);
          if (!bVar5) {
            return;
          }
          local_28 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
          plVar13 = plVar3;
        }
        else {
          KeReleaseSpinLock(plVar1,uVar6);
        }
      }
      else {
        uVar8 = *(int *)((longlong)plVar2 + 0xa4) + uVar15;
        *(uint *)((longlong)plVar2 + 0xa4) = uVar8;
        if ((0xcb < uVar8) && (plVar13[0x5d] != DAT_140036750)) {
          lVar7 = plVar2[0x18];
          uVar10 = (ulonglong)(lVar7 - plVar2[0x16]) >> 9;
          plVar2[0x1c] = (ulonglong)(lVar7 * 8) /
                         (ulonglong)((DAT_140036750 - plVar13[0x5d]) * 0x14);
          plVar2[0x1a] = uVar10;
          if ((ulonglong)plVar2[0x1b] < uVar10) {
            plVar2[0x1b] = uVar10;
          }
          *(undefined4 *)((longlong)plVar2 + 0xa4) = 0;
          plVar2[0x15] = plVar2[0x17];
          plVar2[0x16] = lVar7;
          if (uVar10 != 0) {
            UpdateSampleTimeWindowInformation((longlong)plVar2);
          }
          plVar13[99] = 0;
          plVar13[0x62] = 0;
        }
        if ((longlong *)plVar13[0x17] == plVar13 + 0x17) {
          plVar13[0x6e] = 0;
          plVar13[0x6f] = 0;
          KeReleaseSpinLock();
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
            WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,
                      &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,plVar2,(char)plVar13[5]);
          }
        }
        else {
          KeReleaseSpinLock(plVar1,uVar6);
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
            WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,
                      &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,plVar2,(char)plVar13[5]);
          }
          CheckSendPendingNaks(plVar13[3],(longlong)plVar2,(longlong)plVar13,&local_28);
        }
      }
    }
  }
LAB_140017148:
  *(undefined8 *)(puVar14 + -8) = 0x140017156;
  KeInitializeTimer(&DAT_140036770);
  *(undefined8 *)(puVar14 + -8) = 0x140017173;
  KeInitializeDpc(&DAT_1400367b0,ReceiveTimerTimeout,0);
  *(undefined8 *)(puVar14 + -8) = 0x140017194;
  KeSetTimer(&DAT_140036770,0xfffffffffffcf2c0,&DAT_1400367b0);
  *(undefined8 *)(puVar14 + -8) = 0x1400171ab;
  KeReleaseSpinLock(&DAT_140036808,puVar14[0x30]);
  return;
}



===== ReceiverProcessNakNcfPacket @ 1400171d8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint ReceiverProcessNakNcfPacket
               (longlong param_1,longlong param_2,int param_3,longlong param_4,char param_5)

{
  byte bVar1;
  longlong lVar2;
  bool bVar3;
  bool bVar4;
  undefined1 uVar5;
  uint uVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  char *pcVar12;
  ulonglong uVar13;
  undefined1 auStackY_218 [32];
  uint local_1d4 [3];
  uint local_1c8 [63];
  ushort local_cc;
  ushort local_ca [65];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_218;
  memset(local_1c8,0,0x180);
  lVar7 = param_2 + 0x168;
  uVar5 = KeAcquireSpinLockRaiseToDpc(lVar7);
  if ((*(uint *)(param_2 + 0x20) & 0x2100) == 0) {
    lVar2 = *(longlong *)(param_2 + 0x30);
    uVar6 = ExtractNakNcfSequences
                      (param_4,param_3 - 0x24,local_1c8,(uint *)0x0,*(byte *)(param_2 + 0xa0));
    if ((int)uVar6 < 0) {
      KeReleaseSpinLock(lVar7,uVar5);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4b,
                 &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,uVar6);
      }
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
        WPP_SF_dddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4c,
                    &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,(uint)local_cc,
                    (undefined1)local_1c8[0],(char)local_1d4[(ulonglong)local_cc + 2],
                    (char)*(undefined4 *)(lVar2 + 0x3c));
      }
      bVar4 = true;
      if ((*(ushort *)(lVar2 + 0x2e) == local_ca[0]) || ((param_5 == '\n' && (local_ca[0] == 1)))) {
        uVar6 = *(uint *)(param_1 + 0x38) & 0x10;
        local_1d4[0] = GetRandomInteger((-(uint)(uVar6 != 0) & 0xffffffd0) + 0x32,
                                        (-(uint)(uVar6 != 0) & 0xffffffb0) + 100);
        if ((*(byte *)(param_2 + 0xa1) == 0) || ((*(byte *)(param_2 + 0xa1) & 1) != 0)) {
          bVar4 = false;
        }
        if (((param_5 != '\b') || (!bVar4)) && (local_cc != 0)) {
          uVar11 = 0;
LAB_140017452:
          uVar13 = (ulonglong)uVar11;
          uVar10 = local_1c8[uVar13];
          lVar7 = FindReceiverEntry(lVar2,uVar10);
          if (lVar7 != 0) {
            if ((*(byte *)(param_2 + 0xa1) == 0) || (uVar10 != *(uint *)(lVar2 + 0x3c))) {
              uVar10 = (uint)*(byte *)(lVar7 + 0x39);
            }
            else {
              uVar10 = (*(int *)(lVar2 + 0x40) - *(int *)(lVar7 + 0x10)) + 1;
            }
            uVar9 = ((uVar10 - *(byte *)(lVar7 + 0x3f)) - (uint)*(byte *)(lVar7 + 0x3b)) -
                    (uint)*(byte *)(lVar7 + 0x3a);
            if (uVar9 == 0) goto LAB_1400175eb;
            if (param_5 != '\b') {
              uVar8 = (ulonglong)local_ca[uVar13 + 1];
              if ((*(byte *)(param_2 + 0xa1) & 1) == 0) {
                if (*(byte *)(lVar7 + 0x75 + uVar8 * 0x28) < *(byte *)(lVar7 + 0x3e))
                goto LAB_1400175eb;
                bVar3 = true;
                if (bVar4) {
                  pcVar12 = (char *)(lVar7 + 0x76 + uVar8 * 0x28);
                  *pcVar12 = *pcVar12 + '\x01';
                  for (uVar10 = 0; uVar10 < *(byte *)(lVar7 + 0x39); uVar10 = uVar10 + 1) {
                    if ((*(byte *)(lVar7 + 0x3e) <=
                         *(byte *)(lVar7 + 0x75 + (ulonglong)uVar10 * 0x28)) &&
                       (*(char *)(lVar7 + 0x76 + (ulonglong)uVar10 * 0x28) == '\0'))
                    goto LAB_14001758c;
                  }
                }
                goto LAB_14001758f;
              }
              if (local_ca[0] == 1) {
                bVar3 = true;
                pcVar12 = (char *)(lVar7 + 0x76 + uVar8 * 0x28);
                *pcVar12 = *pcVar12 + '\x01';
                for (uVar9 = 0; uVar9 < uVar10; uVar9 = uVar9 + 1) {
                  if ((*(byte *)(lVar7 + 0x3e) <= *(byte *)(lVar7 + 0x75 + (ulonglong)uVar9 * 0x28))
                     && (*(char *)(lVar7 + 0x76 + (ulonglong)uVar9 * 0x28) == '\0'))
                  goto LAB_14001758c;
                }
                goto LAB_14001758f;
              }
              if (local_ca[uVar13 + 1] < uVar9) goto LAB_1400175eb;
              bVar3 = true;
              if (*(longlong *)(lVar7 + 0x28) == 0) goto LAB_140017595;
              goto LAB_1400175a5;
            }
            if (*(longlong *)(lVar7 + 0x18) != 0) {
              *(ulonglong *)(lVar7 + 0x18) =
                   (ulonglong)((-(uint)(uVar6 != 0) & 0xfffffd44) + 0x2ee + local_1d4[0] / uVar9) /
                   0x14 + DAT_140036750;
              goto LAB_1400175eb;
            }
            goto LAB_1400175ad;
          }
          goto LAB_1400175eb;
        }
LAB_140017608:
        local_1d4[0] = local_1d4[(ulonglong)local_cc + 2] + (uint)local_ca[local_cc];
        if (local_ca[0] == 2) {
          local_1d4[0] = local_1d4[0] - 1;
        }
        CheckAndAddNakRequests(param_2,local_1d4,(undefined8 *)0x0,(param_5 != '\b') + 2,'\x01');
        KeReleaseSpinLock(param_2 + 0x168,uVar5);
      }
      else {
        KeReleaseSpinLock(lVar7,uVar5);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
          pcVar12 = "Non-parity";
          if (*(byte *)(param_2 + 0xa0) < 2) {
            pcVar12 = "Parity";
          }
          WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4d,
                   &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,pcVar12);
        }
      }
      uVar6 = 0;
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4a,
              &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids);
    }
    KeReleaseSpinLock(lVar7,uVar5);
    uVar6 = 0xc000021b;
  }
  return uVar6;
LAB_14001758c:
  bVar3 = false;
LAB_14001758f:
  if (*(longlong *)(lVar7 + 0x28) == 0) {
LAB_140017595:
    *(longlong *)(lVar7 + 0x28) = DAT_140036750;
  }
  if (bVar3) {
LAB_1400175a5:
    *(undefined8 *)(lVar7 + 0x18) = 0;
    *(undefined1 *)(lVar7 + 0x38) = 0;
LAB_1400175ad:
    bVar1 = *(byte *)(lVar7 + 0x3c);
    *(longlong *)(lVar7 + 0x20) = (*(longlong *)(lVar2 + 0x50) << (bVar1 & 0x3f)) + DAT_140036750;
    if ((4 < bVar1) &&
       ((ulonglong)(*(longlong *)(lVar2 + 0x50) << (bVar1 & 0x3f)) < *(ulonglong *)(lVar2 + 0x338)))
    {
      *(ulonglong *)(lVar7 + 0x20) = DAT_140036750 + *(ulonglong *)(lVar2 + 0x338) * 2;
    }
  }
LAB_1400175eb:
  uVar11 = uVar11 + 1;
  if (local_cc <= uVar11) goto LAB_140017608;
  goto LAB_140017452;
}



===== RemovePendingIrps @ 140017698 =====

void RemovePendingIrps(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  longlong *plVar4;
  
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xe8);
  if (lVar2 != 0) {
    *(undefined8 *)(*(longlong *)(param_1 + 0x30) + 0xe8) = 0;
    plVar1 = (longlong *)(lVar2 + 0xa8);
    *(ulonglong *)(lVar2 + 0x38) = (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x30) + 0xf4);
    plVar4 = *(longlong **)(param_2 + 8);
    if (*plVar4 != param_2) goto LAB_14001772b;
    *plVar1 = param_2;
    *(longlong **)(lVar2 + 0xb0) = plVar4;
    *plVar4 = (longlong)plVar1;
    *(longlong **)(param_2 + 8) = plVar1;
  }
  while( true ) {
    plVar4 = (longlong *)(*(longlong *)(param_1 + 0x30) + 200);
    plVar1 = (longlong *)*plVar4;
    if (plVar1 == plVar4) {
      return;
    }
    lVar2 = *plVar1;
    if (((longlong *)*(longlong *)(lVar2 + 8) != plVar1) ||
       (plVar4 = (longlong *)plVar1[1], (longlong *)*plVar4 != plVar1)) break;
    *plVar4 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar4;
    plVar4 = *(longlong **)(param_2 + 8);
    if (*plVar4 != param_2) break;
    *plVar1 = param_2;
    plVar1[1] = (longlong)plVar4;
    *plVar4 = (longlong)plVar1;
    *(longlong **)(param_2 + 8) = plVar1;
    plVar1[-0xe] = 0;
  }
LAB_14001772b:
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  return;
}



===== RemoveRedundantNaks @ 14001773c =====

void RemoveRedundantNaks(longlong param_1,longlong param_2,char param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined1 uVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined1 uVar6;
  byte bVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  byte *pbVar13;
  
  bVar10 = *(char *)(param_2 + 0x3a) + *(char *)(param_2 + 0x3b);
  bVar12 = *(byte *)(param_2 + 0x3e);
  if (*(byte *)(param_2 + 0x39) < bVar12) {
    uVar9 = 0;
    if (bVar12 != 0) {
      do {
        bVar7 = *(byte *)(param_2 + 0x74 + uVar9 * 0x28);
        if (((bVar7 < *(byte *)(param_2 + 0x39)) || (bVar12 <= bVar7)) ||
           (*(byte *)(param_2 + 0x75 + (ulonglong)bVar7 * 0x28) == bVar12)) {
          uVar9 = (ulonglong)(byte)((char)uVar9 + 1);
        }
        else {
          uVar3 = *(undefined1 *)(param_2 + 0x75 + uVar9 * 0x28);
          lVar1 = param_2 + uVar9 * 0x28;
          *(byte *)(param_2 + 0x75 + (ulonglong)bVar7 * 0x28) = bVar12;
          FreeDataBuffer(param_1,(longlong *)(lVar1 + 0x60));
          uVar6 = *(undefined1 *)(param_2 + 0x3e);
          lVar5 = (ulonglong)bVar10 - 1;
          if ((int)uVar9 != bVar10 - 1) {
            puVar2 = (undefined8 *)(param_2 + 0x60 + lVar5 * 0x28);
            uVar4 = puVar2[1];
            uVar6 = *(undefined1 *)(param_2 + 0x75 + lVar5 * 0x28);
            *(undefined8 *)(lVar1 + 0x60) = *puVar2;
            *(undefined8 *)(lVar1 + 0x68) = uVar4;
            puVar2 = (undefined8 *)(param_2 + 0x70 + lVar5 * 0x28);
            uVar4 = puVar2[1];
            *(undefined8 *)(lVar1 + 0x70) = *puVar2;
            *(undefined8 *)(lVar1 + 0x78) = uVar4;
            *(undefined8 *)(lVar1 + 0x80) = *(undefined8 *)(param_2 + 0x80 + lVar5 * 0x28);
          }
          puVar2 = (undefined8 *)(param_2 + 0x60 + lVar5 * 0x28);
          *puVar2 = 0;
          puVar2[1] = 0;
          puVar2 = (undefined8 *)(param_2 + 0x70 + lVar5 * 0x28);
          *puVar2 = 0;
          puVar2[1] = 0;
          *(undefined8 *)(param_2 + 0x80 + lVar5 * 0x28) = 0;
          *(undefined1 *)(param_2 + 0x75 + uVar9 * 0x28) = uVar3;
          if ((int)uVar9 != bVar10 - 1) {
            *(undefined1 *)(param_2 + 0x75 + lVar5 * 0x28) = uVar6;
            bVar12 = *(byte *)(param_2 + 0x74 + uVar9 * 0x28);
            if (bVar12 < *(byte *)(param_2 + 0x3e)) {
              *(char *)(param_2 + 0x75 + (ulonglong)bVar12 * 0x28) = (char)uVar9;
            }
          }
          *(char *)(param_2 + 0x3a) = *(char *)(param_2 + 0x3a) + -1;
          bVar10 = bVar10 - 1;
        }
        bVar12 = *(byte *)(param_2 + 0x3e);
      } while ((byte)uVar9 < bVar12);
    }
    if ((param_3 != '\0') && (uVar9 = 0, bVar10 != 0)) {
      do {
        if (bVar10 <= *(byte *)(param_2 + 0x39)) break;
        if (*(byte *)(param_2 + 0x74 + uVar9 * 0x28) < *(byte *)(param_2 + 0x3e)) {
          uVar9 = (ulonglong)(byte)((char)uVar9 + 1);
        }
        else {
          lVar1 = param_2 + uVar9 * 0x28;
          FreeDataBuffer(param_1,(longlong *)(lVar1 + 0x60));
          uVar8 = (ulonglong)bVar10;
          if ((int)uVar9 != bVar10 - 1) {
            puVar2 = (undefined8 *)(param_2 + 0x38 + uVar8 * 0x28);
            uVar4 = puVar2[1];
            *(undefined8 *)(lVar1 + 0x60) = *puVar2;
            *(undefined8 *)(lVar1 + 0x68) = uVar4;
            puVar2 = (undefined8 *)(param_2 + 0x48 + uVar8 * 0x28);
            uVar4 = puVar2[1];
            *(undefined8 *)(lVar1 + 0x70) = *puVar2;
            *(undefined8 *)(lVar1 + 0x78) = uVar4;
            *(undefined8 *)(lVar1 + 0x80) = *(undefined8 *)(param_2 + 0x58 + uVar8 * 0x28);
          }
          puVar2 = (undefined8 *)(param_2 + 0x38 + uVar8 * 0x28);
          *puVar2 = 0;
          puVar2[1] = 0;
          puVar2 = (undefined8 *)(param_2 + 0x48 + uVar8 * 0x28);
          *puVar2 = 0;
          puVar2[1] = 0;
          *(undefined8 *)(param_2 + 0x58 + uVar8 * 0x28) = 0;
          *(char *)(param_2 + 0x3b) = *(char *)(param_2 + 0x3b) + -1;
          bVar10 = bVar10 - 1;
        }
      } while ((byte)uVar9 < bVar10);
    }
  }
  bVar12 = *(byte *)(param_2 + 0x3e);
  uVar9 = 0;
  bVar7 = 0;
  if (bVar12 != 0) {
    do {
      bVar11 = (char)uVar9 + 1;
      *(byte *)(param_2 + 0x75 + uVar9 * 0x28) = bVar12;
      bVar12 = *(byte *)(param_2 + 0x3e);
      uVar9 = (ulonglong)bVar11;
      bVar7 = bVar12;
    } while (bVar11 < bVar12);
  }
  bVar12 = 0;
  if (bVar10 != 0) {
    pbVar13 = (byte *)(param_2 + 0x74);
    do {
      if (*pbVar13 < bVar7) {
        *(byte *)(param_2 + 0x75 + (ulonglong)*pbVar13 * 0x28) = bVar12;
        bVar7 = *(byte *)(param_2 + 0x3e);
      }
      bVar12 = bVar12 + 1;
      pbVar13 = pbVar13 + 0x28;
    } while (bVar12 < bVar10);
  }
  if (param_3 != '\0') {
    if (((uint)*(byte *)(param_2 + 0x39) <=
         (uint)*(byte *)(param_2 + 0x3b) + (uint)*(byte *)(param_2 + 0x3a)) ||
       ((uint)*(byte *)(param_2 + 0x39) <=
        (uint)*(byte *)(param_2 + 0x3f) + (uint)*(byte *)(param_2 + 0x3a))) {
      RemovePendingReceiverEntry(param_2);
    }
  }
  return;
}



===== RtlUShortAdd @ 1400179a0 =====

uint RtlUShortAdd(ushort param_1,short param_2,ushort *param_3)

{
  ushort uVar1;
  bool bVar2;
  
  uVar1 = param_2 + param_1;
  bVar2 = uVar1 < param_1;
  if (bVar2) {
    uVar1 = 0xffff;
  }
  *param_3 = uVar1;
  return -(uint)bVar2 & 0xc0000095;
}



===== TdiRcvDatagramHandler @ 1400179d0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int TdiRcvDatagramHandler
              (ulonglong *param_1,uint param_2,ulonglong *param_3,ulonglong *param_4,
              longlong param_5,uint param_6,uint param_7,uint param_8,undefined4 *param_9,
              ulonglong *param_10,undefined8 *param_11)

{
  longlong *plVar1;
  byte bVar2;
  ushort uVar3;
  longlong lVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  uint uVar7;
  int iVar8;
  ulonglong uVar9;
  longlong lVar10;
  undefined8 *puVar11;
  longlong lVar12;
  undefined4 *puVar13;
  undefined8 uVar14;
  void *_Dst;
  ushort uVar15;
  undefined4 **ppuVar16;
  undefined7 uVar20;
  undefined4 **ppuVar17;
  ulonglong *puVar18;
  undefined8 uVar19;
  int iVar21;
  uint uVar22;
  undefined4 **_Size;
  uint uVar23;
  byte bVar24;
  undefined4 **ppuVar25;
  undefined4 **local_48;
  undefined8 local_40;
  
  puVar13 = param_9;
  ppuVar16 = (undefined4 **)(ulonglong)param_7;
  local_40 = (undefined4 *)0x0;
  puVar11 = (undefined8 *)0x0;
  *param_9 = 0;
  *param_11 = 0;
  _Size = (undefined4 **)param_3;
  uVar5 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
  uVar9 = Feature_4275546425__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar9 == 0) && (DAT_140036768 < param_7)) {
    DAT_140036768 = param_7;
  }
  if ((param_1 == (ulonglong *)0x0) || ((int)param_1[2] != 0x52444441)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
      WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb1,
               &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,param_1);
    }
    KeReleaseSpinLock(&DAT_140036808,uVar5);
    return -0x3ffffde5;
  }
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x37);
  *(int *)((longlong)param_1 + 0x14) = *(int *)((longlong)param_1 + 0x14) + 1;
  KeReleaseSpinLock(param_1 + 0x37,uVar5);
  KeReleaseSpinLock(&DAT_140036808);
  if ((param_8 == param_7) || ((param_6 & 0x400) != 0)) {
    if ((0x23 < param_7) && (((byte)*param_10 & 0xf0) == 0x40)) {
      uVar23 = (byte)*param_10 & 0xf;
      _Size = (undefined4 **)(ulonglong)uVar23;
      if ((undefined4 **)((ulonglong)(uVar23 * 4) + 0x10) <= ppuVar16) {
        uVar22 = param_7 + uVar23 * -4;
        ppuVar25 = (undefined4 **)((ulonglong)(uVar23 * 4) + (longlong)param_10);
        _Size = (undefined4 **)(ulonglong)uVar22;
        ppuVar16 = ppuVar25;
        uVar7 = tcpxsum(0,(ulonglong *)ppuVar25,uVar22);
        if (uVar7 == 0xffff) {
          bVar2 = *(byte *)((longlong)ppuVar25 + 4);
          uVar7 = bVar2 & 0xffffff0f;
          bVar24 = (byte)uVar7;
          if ((bVar24 < 0xd) && ((0x1304U >> uVar7 & 1) != 0)) {
            uVar3 = *(ushort *)ppuVar25;
            uVar15 = *(ushort *)((longlong)ppuVar25 + 2);
          }
          else {
            uVar3 = *(ushort *)((longlong)ppuVar25 + 2);
            uVar15 = *(ushort *)ppuVar25;
          }
          local_40 = (undefined4 *)CONCAT26(uVar15 >> 8 | uVar15 << 8,*(undefined6 *)(ppuVar25 + 1))
          ;
          uVar15 = uVar3 >> 8 | uVar3 << 8;
          ppuVar16 = (undefined4 **)(ulonglong)uVar15;
          if ((int)param_1[0x29] == 0) {
            uVar3 = *(ushort *)((longlong)param_1 + 0xee);
          }
          else {
            uVar3 = *(ushort *)((longlong)param_1 + 0x14c);
          }
          _Size = (undefined4 **)(ulonglong)uVar3;
          if (uVar3 == uVar15) {
            local_48 = (undefined4 **)0x0;
            param_11._0_1_ = KeAcquireSpinLockRaiseToDpc(param_1 + 0x37);
            puVar13 = local_40;
            ppuVar17 = (undefined4 **)param_1[3];
            if (ppuVar17 != (undefined4 **)(param_1 + 3)) {
              do {
                local_48 = ppuVar17;
                uVar5 = KeAcquireSpinLockRaiseToDpc(ppuVar17 + 0x2d);
                uVar20 = (undefined7)((ulonglong)local_48 >> 8);
                if ((((local_48 != (undefined4 **)0x0) &&
                     ((*(int *)(local_48 + 2) + 0xadacbaadU & 0xfeffffff) == 0)) &&
                    (local_48[8] == puVar13)) &&
                   ((((ulonglong)local_48[4] & 0x2100) == 0 &&
                    (((ulonglong)local_48[4] & 0x30) != 0)))) {
                  if (local_48[6] == (undefined4 *)0x0) {
                    *(int *)((longlong)local_48 + 0x14) = *(int *)((longlong)local_48 + 0x14) + 1;
                  }
                  else {
                    *(int *)((longlong)local_48 + 0x14) = *(int *)((longlong)local_48 + 0x14) + 1;
                    ppuVar16 = local_48;
                    if ((*(char *)((longlong)local_48 + 0xa1) != '\0') &&
                       (*(ushort *)(local_48 + 0x13) < uVar22)) {
                      uVar9 = Feature_4275546425__private_IsEnabledDeviceUsageNoInline();
                      uVar15 = (ushort)uVar22;
                      if ((int)uVar9 != 0) {
                        param_9._0_2_ = 0;
                        if (uVar22 < 0x10000) {
                          ppuVar16 = (undefined4 **)0x0;
                          _Size = &param_9;
                          uVar7 = RtlUShortAdd(uVar15,0xe,(ushort *)_Size);
                          uVar3 = (ushort)param_9;
                          if (-1 < (int)uVar7) {
                            _Size = (undefined4 **)0x336d6750;
                            uVar9 = (ulonglong)
                                    ((uint)*(byte *)(local_48 + 0x14) * (uint)(ushort)param_9 * 2);
                            puVar13 = (undefined4 *)ExAllocatePool2(0x40,uVar9);
                            if (puVar13 != (undefined4 *)0x0) {
                              ppuVar16 = (undefined4 **)0x0;
                              ExFreePoolWithTag(local_48[0x12],0);
                              local_48[0x12] = puVar13;
                              *(ushort *)(local_48 + 0x13) = uVar15;
                              *(ushort *)((longlong)local_48 + 0x9a) = uVar3;
                              goto LAB_140017f44;
                            }
                            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
                              param_4 = (ulonglong *)(ulonglong)(uVar22 + 0xe);
                              uVar9 = 0;
                              _Size = (undefined4 **)
                                      &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids;
                              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb7,
                                       &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,uVar22 + 0xe
                                      );
                            }
                            ppuVar16 = (undefined4 **)CONCAT71((int7)(uVar9 >> 8),uVar5);
                            *(uint *)(local_48 + 4) = *(uint *)(local_48 + 4) | 0x100;
                            KeReleaseSpinLock(local_48 + 0x2d,ppuVar16);
                            local_48 = (undefined4 **)0x0;
                            break;
                          }
                        }
                        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
                          ppuVar16 = (undefined4 **)0x0;
                          param_4 = (ulonglong *)(ulonglong)uVar22;
                          WPP_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb8,_Size,uVar22);
                        }
                        ppuVar16 = (undefined4 **)CONCAT71((int7)((ulonglong)ppuVar16 >> 8),uVar5);
                        *(uint *)(local_48 + 4) = *(uint *)(local_48 + 4) | 0x100;
                        KeReleaseSpinLock(local_48 + 0x2d,ppuVar16);
                        local_48 = (undefined4 **)0x0;
                        break;
                      }
                      _Size = (undefined4 **)0x336d6750;
                      ppuVar16 = (undefined4 **)
                                 ((ulonglong)*(byte *)(local_48 + 0x14) * ((ulonglong)uVar22 + 0xe)
                                 * 2);
                      puVar13 = (undefined4 *)ExAllocatePool2(0x40,ppuVar16);
                      if (puVar13 == (undefined4 *)0x0) {
                        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
                          param_4 = (ulonglong *)(ulonglong)(uVar22 + 0xe);
                          ppuVar16 = (undefined4 **)0x0;
                          _Size = (undefined4 **)&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids;
                          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb9,
                                   &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,uVar22 + 0xe);
                        }
                        local_48 = (undefined4 **)0x0;
                        _DAT_00000020 = _DAT_00000020 | 0x100;
                      }
                      else {
                        ppuVar16 = (undefined4 **)0x0;
                        ExFreePoolWithTag(local_48[0x12],0);
                        local_48[0x12] = puVar13;
                        *(ushort *)(local_48 + 0x13) = uVar15;
                        *(ushort *)((longlong)local_48 + 0x9a) = uVar15 + 0xe;
                      }
                    }
LAB_140017f44:
                    uVar20 = (undefined7)((ulonglong)ppuVar16 >> 8);
                  }
                  ppuVar16 = (undefined4 **)CONCAT71(uVar20,uVar5);
                  KeReleaseSpinLock(local_48 + 0x2d,ppuVar16);
                  break;
                }
                ppuVar16 = (undefined4 **)CONCAT71(uVar20,uVar5);
                KeReleaseSpinLock(local_48 + 0x2d,ppuVar16);
                local_48 = (undefined4 **)0x0;
                ppuVar17 = (undefined4 **)*ppuVar17;
              } while (ppuVar17 != (undefined4 **)(param_1 + 3));
            }
            ppuVar17 = (undefined4 **)CONCAT71((int7)((ulonglong)ppuVar16 >> 8),param_11._0_1_);
            KeReleaseSpinLock(param_1 + 0x37);
            iVar21 = -0x3ffffde5;
            if (local_48 != (undefined4 **)0x0) {
LAB_14001824b:
              if ((((byte)param_1[7] & 0xc) == 0xc) && ((param_6 & 0x1000) != 0)) {
                uVar5 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
                uVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x37);
                *(int *)((longlong)param_1 + 0x14) = *(int *)((longlong)param_1 + 0x14) + 1;
                _Size = (undefined4 **)(ulonglong)*(uint *)(param_5 + 0x14);
                puVar18 = param_1;
                uVar14 = PgmQueueForDelayedExecution
                                   (StopListeningOnAllInterfacesExcept,param_1,_Size,param_4,'\x01')
                ;
                uVar19 = CONCAT71((int7)((ulonglong)puVar18 >> 8),uVar6);
                if ((int)uVar14 == 0) {
                  *(uint *)(param_1 + 7) = (uint)param_1[7] & 0xfffffff7;
                  KeReleaseSpinLock();
                  ppuVar17 = (undefined4 **)CONCAT71((int7)((ulonglong)uVar19 >> 8),uVar5);
                  KeReleaseSpinLock(&DAT_140036808);
                }
                else {
                  KeReleaseSpinLock(param_1 + 0x37,uVar19);
                  ppuVar17 = (undefined4 **)CONCAT71((int7)((ulonglong)uVar19 >> 8),uVar5);
                  KeReleaseSpinLock(&DAT_140036808);
                  PgmDereferenceAddress((longlong *)param_1,ppuVar17,_Size,(longlong *)param_4);
                }
              }
              if ((byte)(bVar24 - 4) < 2) {
                if ((int)param_1[0x29] == 0) {
                  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
                    _Size = (undefined4 **)&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids;
                    ppuVar17 = (undefined4 **)0xbd;
                    param_4 = (ulonglong *)local_48;
                    WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xbd,
                             &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,local_48);
                  }
                  iVar21 = -0x3ffffde5;
                }
                else {
                  if (bVar24 == 4) {
                    plVar1 = (longlong *)(local_48[6] + 0xd2);
                    *plVar1 = *plVar1 + 1;
                  }
                  else {
                    plVar1 = (longlong *)(local_48[6] + 0xd4);
                    *plVar1 = *plVar1 + 1;
                  }
                  _Size = (undefined4 **)(ulonglong)uVar22;
                  *(undefined8 *)(local_48[6] + 0xb8) = DAT_140036750;
                  local_48[0x18] = (undefined4 *)((longlong)local_48[0x18] + (ulonglong)uVar22);
                  local_48[0x19] = (undefined4 *)((longlong)local_48[0x19] + 1);
                  ppuVar17 = local_48;
                  uVar14 = ProcessDataPacket((ulonglong)param_1,(longlong)local_48,uVar22,ppuVar25,
                                             bVar24);
                  iVar21 = (int)uVar14;
                  param_4 = (ulonglong *)ppuVar25;
                }
              }
              else {
                ppuVar17 = local_48;
                uVar9 = PgmProcessIncomingPacket
                                  ((longlong)param_1,(longlong)local_48,_Size,(int *)param_3,uVar22,
                                   (longlong)ppuVar25,bVar24);
                iVar21 = (int)uVar9;
                param_4 = param_3;
              }
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
                param_4 = (ulonglong *)((ulonglong)bVar2 & 0xf);
                WPP_SF_DqddD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),ppuVar17,_Size,(int)param_4,
                             (char)local_48,(char)uVar22,(char)param_8 + (char)uVar23 * -4,
                             (char)iVar21);
              }
              PgmDereferenceSessionCommon((longlong *)local_48,ppuVar17,_Size,(longlong *)param_4);
              PgmDereferenceAddress((longlong *)param_1,ppuVar17,_Size,(longlong *)param_4);
              iVar8 = 0;
              if (iVar21 != 0) {
                iVar8 = -0x3ffffde5;
              }
              return iVar8;
            }
            if ((((int)*param_3 == 1) && (*(short *)((longlong)param_3 + 4) == 0xe)) &&
               (*(short *)((longlong)param_3 + 6) == 2)) {
              if (((int)param_1[0x29] != 0) && (param_1[0xf] != 0)) {
                if (bVar24 == 4) {
                  if (-1 < *(char *)((longlong)ppuVar25 + 5)) {
                    if (uVar22 < 0x18) {
                      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
                        _Size = (undefined4 **)&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids;
                        ppuVar17 = (undefined4 **)0xbb;
                        param_4 = (ulonglong *)(ulonglong)uVar22;
                        WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xbb,
                                  &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,uVar22,0x18);
                      }
                      iVar8 = -0x3ffffde5;
                    }
                    else {
                      uVar9 = Feature_4275546425__private_IsEnabledDeviceUsageNoInline();
                      param_4 = (ulonglong *)(ulonglong)param_6;
                      ppuVar17 = (undefined4 **)(ulonglong)param_2;
                      if ((int)uVar9 == 0) {
                        _Size = (undefined4 **)param_3;
                        uVar14 = PgmNewInboundConnectionOld
                                           ((longlong)param_1,ppuVar17,(longlong)param_3,param_4,
                                            (ushort *)ppuVar25,uVar22,(longlong *)&local_48);
                        iVar8 = (int)uVar14;
                      }
                      else {
                        _Size = (undefined4 **)param_3;
                        uVar14 = PgmNewInboundConnection
                                           ((longlong)param_1,ppuVar17,(longlong)param_3,param_4,
                                            (ushort *)ppuVar25,uVar22,(longlong *)&local_48,param_7)
                        ;
                        iVar8 = (int)uVar14;
                      }
                      if (-1 < iVar8) goto LAB_14001824b;
                    }
                    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
                      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) {
                        _Size = (undefined4 **)&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids;
                        ppuVar17 = (undefined4 **)0xbc;
                        param_4 = param_1;
                        WPP_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xbc,
                                   &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,param_1,4,
                                   (char)iVar8);
                      }
                      if (-1 < iVar8) goto LAB_14001824b;
                    }
                  }
                }
                else if ((bVar24 == 0) && (0x23 < uVar22)) {
                  _Size = (undefined4 **)(ulonglong)uVar22;
                  ppuVar17 = (undefined4 **)0x0;
                  ProcessSpmPacket((longlong)param_1,0,uVar22,(longlong)ppuVar25);
                  param_4 = (ulonglong *)ppuVar25;
                }
              }
            }
            else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
              param_4 = (ulonglong *)(ulonglong)*(ushort *)((longlong)param_3 + 6);
              _Size = (undefined4 **)&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids;
              ppuVar17 = (undefined4 **)0xba;
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xba,
                       &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,
                       (uint)*(ushort *)((longlong)param_3 + 6));
            }
            goto LAB_140017c88;
          }
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) == 0)) goto LAB_140017d34;
          uVar7 = (uint)uVar15;
          ppuVar16 = (undefined4 **)0xb6;
          param_4 = (ulonglong *)_Size;
        }
        else {
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             (ppuVar16 = (undefined4 **)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
             (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) goto LAB_140017d34;
          ppuVar16 = (undefined4 **)0xb5;
          param_4 = (ulonglong *)(ulonglong)*(byte *)((longlong)ppuVar25 + 4);
        }
        _Size = (undefined4 **)&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids;
        WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(short)ppuVar16,
                  &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,(int)param_4,(char)uVar7);
        goto LAB_140017d34;
      }
    }
    ppuVar16 = (undefined4 **)param_10;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      _Size = (undefined4 **)&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids;
      ppuVar16 = (undefined4 **)0xb4;
      uVar23 = (uint)(byte)((byte)*param_10 >> 4);
      param_4 = (ulonglong *)(ulonglong)uVar23;
      WPP_SF_dddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb4,
                  &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,uVar23,(char)param_7,0x2c,
                  (char)*(undefined2 *)((longlong)param_3 + 6));
    }
LAB_140017d34:
    PgmDereferenceAddress((longlong *)param_1,ppuVar16,_Size,(longlong *)param_4);
    return -0x3ffffde5;
  }
  ppuVar17 = (undefined4 **)0x0;
  uVar23 = param_2 + 0x23 + param_8 & 0xfffffffc;
  lVar10 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*pgPgmDevice >> 8),
                                  *(undefined1 *)(*pgPgmDevice + 0x4c)));
  if (lVar10 == 0) {
LAB_140017c42:
    iVar21 = -0x3ffffde5;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      param_4 = (ulonglong *)(ulonglong)uVar23;
      WPP_SF_dqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),ppuVar17,_Size,uVar23,(char)lVar10,
                 (char)puVar11);
    }
  }
  else {
    ppuVar17 = (undefined4 **)(ulonglong)uVar23;
    _Size = (undefined4 **)0x336d6750;
    puVar11 = (undefined8 *)ExAllocatePool2(0x40);
    if (puVar11 == (undefined8 *)0x0) {
LAB_140017c1d:
      IoFreeIrp(lVar10);
      if (puVar11 != (undefined8 *)0x0) {
        ppuVar17 = (undefined4 **)0x0;
        ExFreePoolWithTag(puVar11);
      }
      goto LAB_140017c42;
    }
    param_4 = (ulonglong *)0x0;
    _Size = (undefined4 **)0x0;
    ppuVar17 = (undefined4 **)(ulonglong)param_8;
    lVar12 = IoAllocateMdl(puVar11 + 3);
    if (lVar12 == 0) goto LAB_140017c1d;
    *(longlong *)(lVar10 + 8) = lVar12;
    MmBuildMdlForNonPagedPool(lVar12);
    lVar4 = *(longlong *)(lVar10 + 0xb8);
    _Size = (undefined4 **)(longlong)(int)param_2;
    *(code **)(lVar4 + -0x10) = ProcessReceiveCompletionRoutine;
    *(undefined8 **)(lVar4 + -8) = puVar11;
    *(undefined1 *)(lVar4 + -0x45) = 0xe0;
    lVar4 = *(longlong *)(lVar10 + 0xb8);
    *(undefined2 *)(lVar4 + -0x48) = 0xa0f;
    *(ulonglong *)(lVar4 + -0x20) = param_1[10];
    *(ulonglong *)(lVar4 + -0x18) = param_1[9];
    *(undefined8 *)(lVar4 + -0x38) = 0;
    *(undefined8 *)(lVar4 + -0x30) = 0;
    *(undefined4 *)(lVar4 + -0x28) = 0;
    *(uint *)(lVar4 + -0x40) = param_8;
    *(char *)(lVar10 + 0x43) = *(char *)(lVar10 + 0x43) + -1;
    _Dst = (void *)((ulonglong)param_8 + 0x18 + (longlong)puVar11);
    *(longlong *)(lVar10 + 0xb8) = *(longlong *)(lVar10 + 0xb8) + -0x48;
    *(longlong *)(lVar10 + 8) = lVar12;
    *(uint *)(puVar11 + 1) = param_2;
    puVar11[2] = _Dst;
    *puVar11 = param_1;
    memmove(_Dst,param_3,(size_t)_Size);
    iVar21 = -0x3fffffea;
    *puVar13 = 0;
    *(longlong *)CONCAT71(param_11._1_7_,param_11._0_1_) = lVar10;
    ppuVar17 = (undefined4 **)param_3;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      WPP_SF_ddDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_3,_Size,param_7,(char)param_8,
                  (char)param_6,(char)lVar10);
      ppuVar17 = (undefined4 **)param_3;
      param_4 = (ulonglong *)ppuVar16;
    }
  }
  uVar9 = Feature_3579806010__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar9 != 0) && (iVar21 == -0x3fffffea)) {
    return -0x3fffffea;
  }
LAB_140017c88:
  PgmDereferenceAddress((longlong *)param_1,ppuVar17,_Size,(longlong *)param_4);
  return iVar21;
}



===== UpdateRealTimeWindowInformation @ 140018570 =====

void UpdateRealTimeWindowInformation(longlong param_1,int param_2,int param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  uint uVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x30);
  uVar3 = (param_2 - param_3) + 1;
  uVar2 = (ulonglong)uVar3;
  if (0 < (int)(uVar3 - *(int *)(lVar1 + 0x2f8))) {
    *(ulonglong *)(lVar1 + 0x2f8) = uVar2;
  }
  if (param_3 != 0) {
    if ((*(longlong *)(lVar1 + 0x2f0) == 0) || ((int)(uVar3 - *(int *)(lVar1 + 0x2f0)) < 0)) {
      *(ulonglong *)(lVar1 + 0x2f0) = uVar2;
    }
    *(longlong *)(lVar1 + 0x310) = *(longlong *)(lVar1 + 0x310) + uVar2;
    *(longlong *)(lVar1 + 0x318) = *(longlong *)(lVar1 + 0x318) + 1;
  }
  return;
}



===== UpdateSampleTimeWindowInformation @ 1400185c4 =====

void UpdateSampleTimeWindowInformation(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 auVar3 [16];
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
  
  lVar1 = *(longlong *)(param_1 + 0x30);
  if ((*(longlong *)(param_1 + 0xd8) != 0) && (*(longlong *)(param_1 + 200) != 0)) {
    if (*(ulonglong *)(lVar1 + 0x318) != 0) {
      *(ulonglong *)(lVar1 + 0x308) = *(ulonglong *)(lVar1 + 0x310) / *(ulonglong *)(lVar1 + 0x318);
    }
    lVar2 = *(longlong *)(lVar1 + 0x308);
    lVar6 = lVar2;
    if (lVar2 == 0) {
      lVar6 = *(longlong *)(lVar1 + 0x2f8);
    }
    uVar4 = (ulonglong)(lVar6 * *(longlong *)(param_1 + 0xc0) * 8) /
            (ulonglong)(*(longlong *)(param_1 + 0xd8) * *(longlong *)(param_1 + 200));
    *(ulonglong *)(lVar1 + 0x340) = uVar4;
    auVar3._8_8_ = 0;
    auVar3._0_8_ = uVar4;
    lVar6 = SUB168(ZEXT816(0x47ae147ae147ae15) * auVar3,8);
    *(ulonglong *)(lVar1 + 0x338) = (uVar4 - lVar6 >> 1) + lVar6 >> 7;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
      WPP_SF_qiii(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
                  &WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,param_1,
                  (char)*(undefined8 *)(param_1 + 0xd8),(char)lVar2,(char)uVar4);
    }
    if ((*(ulonglong *)(lVar1 + 0x328) != 0) && (*(ulonglong *)(lVar1 + 0x330) != 0)) {
      *(ulonglong *)(lVar1 + 800) = *(ulonglong *)(lVar1 + 0x328) / *(ulonglong *)(lVar1 + 0x330);
    }
    lVar2 = *(longlong *)(lVar1 + 800);
    if (lVar2 != 0) {
      uVar5 = (ulonglong)(*(longlong *)(lVar1 + 0x58) + lVar2) >> 1;
      uVar4 = lVar2 * 2;
      if (uVar5 <= (ulonglong)(lVar2 * 2)) {
        uVar4 = uVar5;
      }
      uVar5 = *(ulonglong *)(lVar1 + 0x60) / 0x14;
      if (uVar5 < uVar4) {
        uVar5 = uVar4;
      }
      *(ulonglong *)(lVar1 + 0x50) = uVar5;
    }
  }
  return;
}



===== WPP_SF_DDdddq @ 140018724 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDdddq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                  undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                  undefined1 param_9)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,0x57,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,&param_9,8,0);
  return;
}



===== WPP_SF_DDq @ 1400187b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,8,0);
  return;
}



===== WPP_SF_DqdD @ 140018814 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DqdD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,param_2,local_res20,4,
             &param_5,8,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_Dqdd @ 140018888 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dqdd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,0x5b,local_res20,4,
             &param_5,8,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_DqddD @ 1400188fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DqddD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,0xbe,local_res20,4,
             &param_5,8,&param_6,4,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_SF_HH @ 140018984 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_HH(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined2 param_4,
              undefined1 param_5)

{
  undefined2 local_res20 [4];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,param_2,local_res20,2,
             &param_5,2,0);
  return;
}



===== WPP_SF_L @ 1400189dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_L(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_c @ 140018a24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_c(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 param_4)

{
  undefined1 local_res20 [8];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,0x85,local_res20,1,0);
  return;
}



===== WPP_SF_cc @ 140018a70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_cc(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 param_4,
              undefined1 param_5)

{
  undefined1 local_res20 [8];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,0x5d,local_res20,1,
             &param_5,1,0);
  return;
}



===== WPP_SF_dDq @ 140018ac8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dDq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,0x6c,local_res20,4,
             &param_5,4,&param_6,8,0);
  return;
}



===== WPP_SF_dDsdd @ 140018b30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dDsdd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                 undefined1 param_5,char *param_6,undefined1 param_7,undefined1 param_8)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  undefined4 local_res20 [2];
  
  if (param_6 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_6[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  pcVar3 = param_6;
  if (param_6 == (char *)0x0) {
    pcVar3 = "NULL";
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,0x86,local_res20,4,
             &param_5,4,pcVar3,lVar2,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_SF_ddDq @ 140018bfc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ddDq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,0xb2,local_res20,4,
             &param_5,4,&param_6,4,&param_7,8,0);
  return;
}



===== WPP_SF_ddddD @ 140018c70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ddddD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                 undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined4 local_res20 [2];
  undefined4 local_18 [6];
  
  local_18[0] = 8;
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,0xc,local_res20,4,
             local_18,4,&param_6,4,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_SF_ddddd @ 140018cf8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ddddd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,param_2,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_SF_dddddd @ 140018d78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dddddd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                  undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                  undefined1 param_9)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,param_2,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,&param_9,4,0);
  return;
}



===== WPP_SF_ddddddd @ 140018e04 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ddddddd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                   undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                   undefined1 param_9,undefined1 param_10)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,4,&param_7,4,&param_8,4,
             &param_9,4,&param_10,4,0);
  return;
}



===== WPP_SF_dqq @ 140018e98 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dqq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,0xb3,local_res20,4,
             &param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_qDdii @ 140018f00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDdii(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,0x2f,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,8,&param_8,8,0);
  return;
}



===== WPP_SF_qdddddd @ 140018f88 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qdddddd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                   undefined1 param_9,undefined1 param_10)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,10,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,&param_9,4,&param_10,4,0);
  return;
}



===== WPP_SF_qqDd @ 140019024 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqDd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,0xaf,&local_res20,8,
             &param_5,8,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_qqddsd @ 14001909c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqddsd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                  undefined1 param_5,undefined1 param_6,undefined1 param_7,char *param_8,
                  undefined1 param_9)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  undefined8 local_res20;
  
  if (param_8 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_8[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  pcVar3 = param_8;
  if (param_8 == (char *)0x0) {
    pcVar3 = "NULL";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,param_2,&local_res20,8,
             &param_5,8,&param_6,4,&param_7,4,pcVar3,lVar2,&param_9,4,0);
  return;
}



===== WPP_SF_qqsdd @ 140019180 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqsdd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,char *param_6,undefined1 param_7,undefined1 param_8)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  undefined8 local_res20;
  
  if (param_6 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_6[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  pcVar3 = param_6;
  if (param_6 == (char *)0x0) {
    pcVar3 = "NULL";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,0xb,&local_res20,8,
             &param_5,8,pcVar3,lVar2,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_SF_sd @ 140019250 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sd(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
              undefined1 param_5)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_4[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,0x45,param_4,lVar2,
             &param_5,4,0);
  return;
}



===== WPP_SF_sddd @ 1400192d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sddd(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_4[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,0x37,param_4,lVar2,
             &param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_sdddDd @ 14001937c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sdddDd(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
                  undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 local_18 [6];
  
  local_18[0] = 0x71;
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_4[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fcce55beb41336f48788aaec8d483b1a_Traceguids,0x2e,param_4,lVar2,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,local_18,4,0);
  return;
}



===== AdvanceWindow @ 140019458 =====

uint AdvanceWindow(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  byte bVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined8 uVar5;
  code *pcVar6;
  undefined1 auVar7 [16];
  ulonglong uVar8;
  longlong lVar9;
  int iVar10;
  ulonglong uVar11;
  undefined2 uVar12;
  uint uVar13;
  longlong *plVar14;
  undefined1 *puVar15;
  uint uVar16;
  undefined **ppuVar17;
  ulonglong uVar18;
  uint uVar19;
  int iVar20;
  ulonglong uVar21;
  int iVar22;
  uint uVar23;
  longlong *plVar24;
  undefined1 auStackY_88 [8];
  undefined1 auStackY_80 [24];
  undefined1 uVar25;
  
  lVar2 = *(longlong *)(param_1 + 0x28);
  uVar11 = *(ulonglong *)(lVar2 + 0x128);
  uVar18 = *(ulonglong *)(lVar2 + 0x158);
  if (uVar18 < uVar11) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
      WPP_SF_ii(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,param_3,uVar11,(char)uVar18);
    }
    uVar11 = *(ulonglong *)(lVar2 + 0x128);
    uVar18 = *(longlong *)(lVar2 + 0x140) + uVar11;
    *(ulonglong *)(lVar2 + 0x158) = uVar18;
  }
  uVar8 = *(ulonglong *)(lVar2 + 0x148);
  uVar21 = *(ulonglong *)(lVar2 + 0x160);
  uVar18 = (uVar18 - uVar8) - *(longlong *)(lVar2 + 0x140);
  if (uVar18 < uVar21) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
      return 0;
    }
    WPP_SF_ddiii(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,uVar8,
                 *(undefined4 *)(lVar2 + 0xa0),(char)*(undefined4 *)(lVar2 + 0x98) + -1,(char)uVar11
                 ,(char)uVar18,(char)uVar21);
    return 0;
  }
  uVar16 = *(uint *)(lVar2 + 0x98);
  iVar20 = *(int *)(lVar2 + 0xa0);
  uVar19 = -(uint)*(byte *)(param_1 + 0xa0) & uVar16;
  plVar14 = (longlong *)**(longlong **)(lVar2 + 0x108);
  uVar13 = uVar19 - iVar20;
  if (((plVar14 != *(longlong **)(lVar2 + 0x108)) && (plVar14 != (longlong *)0x0)) &&
     ((int)(*(uint *)(plVar14 + 2) - uVar19) < 0)) {
    uVar19 = *(uint *)(plVar14 + 2);
  }
  uVar23 = uVar19 - iVar20;
  if (((*(uint *)(*(longlong *)(lVar2 + 0x20) + 0x38) & 2) == 0) ||
     ((*(uint *)(param_1 + 0x20) & 0x1000) != 0)) {
LAB_1400195b1:
    if (uVar23 != 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
        WPP_SF_iiii(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)uVar13,uVar8,uVar18,
                    (char)uVar21,(char)*(longlong *)(lVar2 + 0x140),(char)uVar8);
      }
      puVar15 = auStackY_88;
      ppuVar17 = (undefined **)0x0;
      uVar13 = 0;
      uVar16 = 0;
      plVar14 = *(longlong **)(lVar2 + 0xd8);
      plVar24 = (longlong *)0x0;
      if (plVar14 == (longlong *)(lVar2 + 0xd8)) {
        plVar24 = *(longlong **)(lVar2 + 0xe8);
        if (((((plVar24 != (longlong *)(lVar2 + 0xe8)) && ((int)plVar24[0x11] == 0)) &&
             (*(int *)((longlong)plVar24 + 0x8c) == 0)) &&
            (((int)plVar24[0x10] != 0 && (*(int *)((longlong)plVar24 + 0x6c) == (int)plVar24[0x10]))
            )) && (uVar11 = uVar18, (ulonglong)plVar24[6] <= uVar18)) {
LAB_1400197b1:
          if (plVar24 != (longlong *)0x0) {
            iVar20 = *(int *)(*(longlong *)(lVar2 + 0x20) + 0xf8);
            lVar9 = *(longlong *)(*(longlong *)(lVar2 + 0x20) + 0x110);
            uVar8 = ((uVar18 - plVar24[6]) * lVar9 * 0x14) / (ulonglong)(uint)(iVar20 * 8);
            iVar10 = (int)plVar24[0xb];
            iVar22 = iVar10 - *(int *)((longlong)plVar24 + 0x5c);
            if (0 < (int)uVar8 + iVar22) {
              uVar8 = (ulonglong)((*(int *)((longlong)plVar24 + 0x5c) - iVar10) + 1);
            }
            if (0 < (int)((iVar10 - uVar19) + (int)uVar8)) {
              uVar19 = uVar19 - iVar10;
              uVar8 = (ulonglong)uVar19;
            }
            iVar10 = iVar10 - *(int *)(lVar2 + 0xa0);
            uVar13 = iVar10 + (int)uVar8;
            if ((int)uVar13 < 1) {
              uVar8 = 0;
            }
            else {
              uVar8 = uVar8 & 0xffffffff;
              if (iVar10 < 0) {
                uVar8 = (ulonglong)uVar13;
              }
            }
            iVar10 = (int)uVar8;
            uVar11 = lVar9 * 0x14;
            uVar16 = uVar16 + iVar10;
            ppuVar17 = (undefined **)(ulonglong)uVar16;
            uVar21 = (ulonglong)(uint)(iVar20 * iVar10 * 8);
            plVar14 = (longlong *)(uVar21 % uVar11);
            uVar11 = plVar24[6] + uVar21 / uVar11;
            if (((int)plVar24[0xd] == 0) && (0 < iVar22 + iVar10)) {
              lVar9 = *plVar24;
              if ((*(longlong **)(lVar9 + 8) != plVar24) ||
                 (plVar3 = (longlong *)plVar24[1], (longlong *)*plVar3 != plVar24)) {
LAB_140019946:
                uVar13 = (uint)uVar8;
                pcVar6 = (code *)swi(0x29);
                (*pcVar6)(3,plVar14);
                puVar15 = auStackY_80;
                goto LAB_14001994d;
              }
              *plVar3 = lVar9;
              *(longlong **)(lVar9 + 8) = plVar3;
              ExFreeToNPagedLookasideList(lVar2 + 0x240,plVar24);
            }
          }
          if (uVar16 != 0) {
            uVar13 = *(uint *)(lVar2 + 0xa0);
            uVar19 = uVar23;
            if (uVar16 <= uVar23) {
              uVar19 = uVar16;
            }
            uVar16 = uVar13 + uVar19;
            ppuVar17 = &WPP_GLOBAL_Control;
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
              WPP_SF_dddddii(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)uVar13,uVar8,
                             *(undefined4 *)(lVar2 + 0x78),(char)uVar19,(char)uVar23,(char)uVar13,
                             (char)uVar16,(char)*(undefined8 *)(lVar2 + 0x160),(char)uVar11);
            }
            uVar18 = Feature_3666842937__private_IsEnabledDeviceUsageNoInline();
            uVar13 = *(uint *)(lVar2 + 0x6c);
            uVar8 = CONCAT44(0,uVar13);
            if ((int)uVar18 == 0) {
              *(int *)(lVar2 + 0x74) = *(int *)(lVar2 + 0x74) + uVar19;
              uVar8 = (ulonglong)(uVar13 * uVar19);
              *(longlong *)(lVar2 + 0x78) = *(longlong *)(lVar2 + 0x78) + uVar8;
              uVar18 = *(longlong *)(lVar2 + 0x88) + uVar8;
              *(ulonglong *)(lVar2 + 0x88) = uVar18;
              if (*(ulonglong *)(lVar2 + 0x58) <= uVar18) {
                *(ulonglong *)(lVar2 + 0x88) = uVar18 - *(ulonglong *)(lVar2 + 0x58);
              }
            }
            else {
              auVar7._8_8_ = 0;
              auVar7._0_8_ = uVar8;
              lVar9 = SUB168(auVar7 * ZEXT416(uVar19),0);
              if (SUB168(auVar7 * ZEXT416(uVar19),8) != 0) {
LAB_14001994d:
                if ((undefined **)WPP_GLOBAL_Control == ppuVar17) {
                  return 0;
                }
                if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
                  return 0;
                }
                uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
                *(uint *)(puVar15 + 0x20) = uVar13;
                *(undefined8 *)(puVar15 + -8) = 0x140019985;
                WPP_SF_dD(uVar5,0x4f,&WPP_2d619c39f4c936783a7b398058864277_Traceguids,uVar19,
                          puVar15[0x20]);
                return 0;
              }
              *(longlong *)(lVar2 + 0x78) = *(longlong *)(lVar2 + 0x78) + lVar9;
              uVar18 = lVar9 + *(longlong *)(lVar2 + 0x88);
              *(int *)(lVar2 + 0x74) = *(int *)(lVar2 + 0x74) + uVar19;
              *(ulonglong *)(lVar2 + 0x88) = uVar18;
              if (*(ulonglong *)(lVar2 + 0x58) <= uVar18) {
                *(ulonglong *)(lVar2 + 0x88) = uVar18 - *(ulonglong *)(lVar2 + 0x58);
              }
            }
            *(uint *)(lVar2 + 0xa0) = uVar16;
            bVar1 = *(byte *)(param_1 + 0xa0);
            *(ulonglong *)(lVar2 + 0x160) = uVar11;
            *(uint *)(lVar2 + 0xa4) = (bVar1 - 1) + uVar16 & -(uint)bVar1;
            lVar9 = *(longlong *)(lVar2 + 0x108);
            *(uint *)(lVar9 + 0x20) =
                 uVar16 >> ((byte)*(undefined4 *)(lVar9 + 0x14) & 0x1f) & *(uint *)(lVar9 + 0x18);
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
              uVar16 = *(int *)(lVar2 + 0x98) - 1;
              WPP_SF_ddi(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)uVar16,uVar8,
                         *(undefined4 *)(lVar2 + 0xa0),(char)uVar16,
                         (char)*(undefined8 *)(lVar2 + 0x128));
            }
            return uVar19;
          }
        }
      }
      else {
        do {
          uVar11 = plVar14[6];
          if ((((int)plVar14[0x11] != 0) || (uVar18 <= uVar11)) ||
             (iVar20 = (int)plVar14[0xb], -1 < (int)(iVar20 - uVar19))) {
            uVar23 = *(uint *)(lVar2 + 0xa0);
            uVar19 = *(uint *)(plVar14 + 0xb);
            if ((int)(uVar23 - uVar19) < 1) {
              uVar23 = uVar19 - uVar23;
            }
            else {
              uVar19 = uVar23;
              uVar23 = uVar13;
            }
            uVar16 = uVar23;
            goto LAB_1400197b1;
          }
          if (-1 < (int)(*(int *)((longlong)plVar14 + 0x5c) - uVar19)) {
            if (*(int *)(lVar2 + 0xa0) - iVar20 < 1) {
              uVar13 = iVar20 - *(int *)(lVar2 + 0xa0);
            }
            plVar24 = plVar14;
            uVar16 = uVar13;
            goto LAB_1400197b1;
          }
          plVar3 = (longlong *)*plVar14;
          if (((longlong *)plVar3[1] != plVar14) ||
             (plVar4 = (longlong *)plVar14[1], (longlong *)*plVar4 != plVar14)) goto LAB_140019946;
          *plVar4 = (longlong)plVar3;
          plVar3[1] = (longlong)plVar4;
          ExFreeToNPagedLookasideList(lVar2 + 0x240);
          plVar14 = plVar3;
        } while (plVar3 != (longlong *)(lVar2 + 0xd8));
      }
      uVar25 = (undefined1)uVar23;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
        return 0;
      }
      uVar21 = *(ulonglong *)(lVar2 + 0x160);
      uVar12 = 0x4d;
      uVar16 = *(uint *)(lVar2 + 0x98);
      iVar20 = *(int *)(lVar2 + 0xa0);
      goto LAB_1400196f6;
    }
  }
  else {
    uVar11 = *(ulonglong *)(lVar2 + 0x60) >> 1;
    if (uVar11 < uVar13) {
      if (uVar13 - uVar23 < uVar11) {
        uVar23 = uVar13 - (int)uVar11;
        uVar19 = iVar20 + uVar23;
      }
      goto LAB_1400195b1;
    }
  }
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return 0;
  }
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
    return 0;
  }
  uVar12 = 0x4b;
  uVar25 = 0;
LAB_1400196f6:
  WPP_SF_ddidii(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar12,(ulonglong)(uVar16 - 1),iVar20,
                (char)(uVar16 - 1),(char)*(undefined8 *)(lVar2 + 0x128),uVar25,(char)uVar18,
                (char)uVar21);
  return 0;
}



===== CheckForTermination @ 140019a44 =====

ulonglong CheckForTermination(longlong *param_1,undefined1 *param_2,undefined8 param_3,
                             longlong *param_4)

{
  uint uVar1;
  undefined4 uVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong ****pppplVar5;
  longlong *plVar6;
  code *pcVar7;
  undefined1 *puVar8;
  undefined1 uVar9;
  longlong *plVar10;
  longlong lVar11;
  undefined2 uVar12;
  longlong ****pppplVar13;
  undefined8 uVar14;
  longlong ****pppplVar15;
  undefined1 *puVar16;
  undefined **ppuVar17;
  int iVar18;
  undefined8 uVar19;
  undefined1 auStackY_48 [8];
  undefined1 auStackY_40 [24];
  longlong ****local_18;
  longlong ****local_10;
  
  if ((param_1 == (longlong *)0x0) || ((int)param_1[2] != 0x32534553)) {
    plVar10 = (longlong *)param_1[5];
    if (((plVar10[4] != 0) && (*(int *)(plVar10[4] + 0x10) == 0x32444441)) ||
       ((*(uint *)(param_1 + 4) & 0x2000) != 0)) goto LAB_140019ac0;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (plVar10 = (longlong *)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
       (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) goto LAB_14001a0be;
    uVar12 = 0x51;
  }
  else {
LAB_140019ac0:
    if ((*(uint *)(param_1 + 4) & 0x1000) == 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x52,
                 &WPP_2d619c39f4c936783a7b398058864277_Traceguids,*(undefined4 *)(param_1[5] + 0xbc)
                );
      }
      lVar11 = param_1[5];
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x1000;
      if (*(longlong **)(lVar11 + 0xf8) == (longlong *)(lVar11 + 0xf8)) {
        if (*(int *)(lVar11 + 0x90) == 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x55,
                    &WPP_2d619c39f4c936783a7b398058864277_Traceguids);
            lVar11 = param_1[5];
          }
          if (((*(uint *)(param_1 + 4) & 0x4000) == 0) && (param_1[0xc] != 0)) {
            *(uint *)(lVar11 + 0xc4) = *(uint *)(lVar11 + 0xc4) & 0xffffff7f;
            *(uint *)(param_1[5] + 0xc4) = *(uint *)(param_1[5] + 0xc4) | 0x40;
          }
          else {
            *(uint *)(lVar11 + 0xc4) = *(uint *)(lVar11 + 0xc4) & 0xffffffbf;
            *(uint *)(param_1[5] + 0xc4) = *(uint *)(param_1[5] + 0xc4) | 0x80;
          }
          plVar10 = *(longlong **)(param_1[5] + 0x178);
          *(longlong **)(param_1[5] + 0x170) = plVar10;
          *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 4;
          goto LAB_14001a0be;
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x54,
                  &WPP_2d619c39f4c936783a7b398058864277_Traceguids);
        }
        plVar10 = (longlong *)param_1[5];
        lVar11 = plVar10[0x1e];
      }
      else {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x53,
                  &WPP_2d619c39f4c936783a7b398058864277_Traceguids);
        }
        plVar10 = (longlong *)param_1[5];
        lVar11 = plVar10[0x20];
      }
      *(undefined1 *)(lVar11 + 0x98) = 1;
      goto LAB_14001a0be;
    }
    lVar11 = param_1[0xc];
    if (lVar11 != 0) {
      lVar3 = param_1[5];
      if (((*(ulonglong *)(lVar3 + 0x138) != 0) &&
          (*(ulonglong *)(lVar3 + 0x138) < *(ulonglong *)(lVar3 + 0x128))) ||
         ((*(longlong **)(lVar3 + 0xf8) == (longlong *)(lVar3 + 0xf8) &&
          ((((*(longlong **)(lVar3 + 0xe8) == (longlong *)(lVar3 + 0xe8) &&
             (plVar10 = FindFirstEntry((longlong)param_1,(undefined8 *)0x0,'\x01'),
             plVar10 == (longlong *)0x0)) &&
            (plVar10 = (longlong *)(param_1[5] + 0xd8), (longlong *)*plVar10 == plVar10)) &&
           ((*(byte *)(param_1 + 4) & 4) == 0 && (*(uint *)(param_1[5] + 0xc4) & 0x1c0) != 0)))))) {
        param_1[0xc] = 0;
        KeReleaseSpinLock(param_1 + 0x2d);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x56,
                   &WPP_2d619c39f4c936783a7b398058864277_Traceguids,lVar11);
        }
        PgmIoComplete(lVar11,0,0);
        plVar10 = (longlong *)KeAcquireSpinLockRaiseToDpc(param_1 + 0x2d);
        *param_2 = (char)plVar10;
        goto LAB_14001a0be;
      }
    }
    if ((int)param_1[2] != 0x32534553) {
      lVar11 = param_1[5];
      plVar10 = *(longlong **)(lVar11 + 0x20);
      if (((plVar10 == (longlong *)0x0) || ((int)plVar10[2] != 0x32444441)) &&
         ((uVar4 = *(ulonglong *)(lVar11 + 0x138), uVar4 == 0 ||
          (*(ulonglong *)(lVar11 + 0x128) < uVar4)))) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (plVar10 = (longlong *)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
           (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
          plVar10 = (longlong *)
                    WPP_SF_qii(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar11,uVar4,param_1,
                               (char)*(undefined8 *)(lVar11 + 0x128),(char)uVar4);
        }
        goto LAB_14001a0be;
      }
    }
    RemoveAllEntries((longlong)param_1,'\x01');
    local_10 = (longlong ****)&local_18;
    uVar19 = 0;
    pppplVar13 = (longlong ****)&local_18;
    local_18 = (longlong ****)&local_18;
    PgmCancelAllSends((longlong)param_1,(longlong)pppplVar13,(longlong *)0x0);
    while( true ) {
      pppplVar15 = local_18;
      puVar16 = auStackY_48;
      if ((longlong *****)local_18 == &local_18) break;
      ppuVar17 = (undefined **)local_18;
      if (((longlong *****)local_18[1] != &local_18) ||
         (pppplVar5 = (longlong ****)*local_18, (longlong ****)pppplVar5[1] != local_18))
      goto LAB_140019fd8;
      uVar14 = CONCAT71((int7)((ulonglong)pppplVar13 >> 8),*param_2);
      pppplVar5[1] = (longlong ***)&local_18;
      local_18 = pppplVar5;
      KeReleaseSpinLock(param_1 + 0x2d);
      if (pppplVar15[4] != (longlong ***)0x0) {
        uVar19 = 0;
        uVar14 = 0xc0000120;
        PgmIoComplete((longlong)pppplVar15[4],0xc0000120,0);
      }
      PgmDereferenceSessionCommon(param_1,uVar14,uVar19,param_4);
      uVar9 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x2d);
      lVar11 = param_1[5];
      *param_2 = uVar9;
      ExFreeToNPagedLookasideList(lVar11 + 0x240,pppplVar15);
      pppplVar13 = pppplVar15;
    }
    lVar11 = param_1[5];
    uVar1 = *(uint *)(lVar11 + 0xc4);
    plVar10 = (longlong *)(ulonglong)uVar1;
    if ((uVar1 & 0x1c0) == 0) {
      if (((*(uint *)(param_1 + 4) >> 0xe & 1) == 0) && (param_1[0xc] != 0)) {
        *(uint *)(lVar11 + 0xc4) = uVar1 & 0xffffff7f;
        plVar10 = (longlong *)param_1[5];
        *(uint *)((longlong)plVar10 + 0xc4) = *(uint *)((longlong)plVar10 + 0xc4) | 0x40;
      }
      else {
        *(uint *)(lVar11 + 0xc4) = uVar1 & 0xffffffbf;
        plVar10 = (longlong *)param_1[5];
        *(uint *)((longlong)plVar10 + 0xc4) = *(uint *)((longlong)plVar10 + 0xc4) | 0x80;
      }
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 4;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (plVar10 = (longlong *)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
         (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) goto LAB_14001a0be;
      uVar12 = 0x58;
    }
    else {
      if ((*(uint *)(param_1 + 4) & 4) == 0) {
        while( true ) {
          lVar11 = param_1[5];
          ppuVar17 = &WPP_GLOBAL_Control;
          plVar10 = (longlong *)(lVar11 + 0xd8);
          plVar6 = (longlong *)*plVar10;
          if (plVar6 == plVar10) break;
          puVar8 = auStackY_48;
          if (*(int *)(plVar6 + 0x11) != 0) goto LAB_140019fdf;
          iVar18 = (*(int *)((longlong)plVar6 + 0x5c) - *(int *)(lVar11 + 0xa0)) + 1;
          *(int *)(lVar11 + 0x74) = *(int *)(lVar11 + 0x74) + iVar18;
          plVar10 = (longlong *)(param_1[5] + 0x78);
          *plVar10 = *plVar10 + (ulonglong)(uint)(iVar18 * *(int *)(param_1[5] + 0x6c));
          plVar10 = (longlong *)(param_1[5] + 0x88);
          *plVar10 = *plVar10 + (ulonglong)(uint)(iVar18 * *(int *)(param_1[5] + 0x6c));
          lVar11 = param_1[5];
          if (*(ulonglong *)(lVar11 + 0x58) <= *(ulonglong *)(lVar11 + 0x88)) {
            *(ulonglong *)(lVar11 + 0x88) =
                 *(ulonglong *)(lVar11 + 0x88) - *(ulonglong *)(lVar11 + 0x58);
          }
          *(int *)(param_1[5] + 0xa0) = *(int *)(param_1[5] + 0xa0) + iVar18;
          lVar11 = *plVar6;
          if (((longlong *)*(longlong *)(lVar11 + 8) != plVar6) ||
             (plVar10 = (longlong *)plVar6[1], (longlong *)*plVar10 != plVar6)) goto LAB_140019fd8;
          *plVar10 = lVar11;
          *(longlong **)(lVar11 + 8) = plVar10;
          ExFreeToNPagedLookasideList(param_1[5] + 0x240);
        }
        goto LAB_14001a007;
      }
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (plVar10 = (longlong *)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
         (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) goto LAB_14001a0be;
      uVar12 = 0x59;
    }
  }
  plVar10 = (longlong *)
            WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar12,
                     &WPP_2d619c39f4c936783a7b398058864277_Traceguids,param_1);
  goto LAB_14001a0be;
LAB_140019fd8:
  pcVar7 = (code *)swi(0x29);
  plVar10 = (longlong *)(*pcVar7)(3);
  puVar8 = auStackY_40;
LAB_140019fdf:
  puVar16 = puVar8;
  if (((undefined **)WPP_GLOBAL_Control != ppuVar17) &&
     (plVar10 = (longlong *)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
     (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
    uVar19 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(undefined8 *)(puVar16 + -8) = 0x14001a007;
    plVar10 = (longlong *)WPP_SF_(uVar19,0x5a,&WPP_2d619c39f4c936783a7b398058864277_Traceguids);
  }
LAB_14001a007:
  if (param_1[0xc] == 0) {
    lVar11 = param_1[5];
    plVar10 = (longlong *)(lVar11 + 0xd8);
    if ((((longlong *)*plVar10 == plVar10) &&
        (plVar10 = (longlong *)(lVar11 + 0xf8), (longlong *)*plVar10 == plVar10)) &&
       (plVar10 = (longlong *)(lVar11 + 0xe8), (longlong *)*plVar10 == plVar10)) {
      plVar10 = *(longlong **)(lVar11 + 0x108);
      if (((longlong *)*plVar10 == plVar10) || ((longlong *)*plVar10 == (longlong *)0x0)) {
        if (((undefined **)WPP_GLOBAL_Control != ppuVar17) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
          uVar19 = *(undefined8 *)(lVar11 + 0x128);
          uVar14 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
          *(undefined8 *)(puVar16 + -8) = 0x14001a07a;
          plVar10 = (longlong *)
                    WPP_SF_i(uVar14,0x5c,&WPP_2d619c39f4c936783a7b398058864277_Traceguids,uVar19);
        }
        return CONCAT71((int7)((ulonglong)plVar10 >> 8),1);
      }
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != ppuVar17) &&
     (plVar10 = (longlong *)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
     (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
    uVar19 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    uVar2 = *(undefined4 *)(param_1[5] + 0xa0);
    *(int *)(puVar16 + 0x20) = *(int *)(param_1[5] + 0x98) + -1;
    *(undefined8 *)(puVar16 + -8) = 0x14001a0be;
    plVar10 = (longlong *)
              WPP_SF_dD(uVar19,0x5b,&WPP_2d619c39f4c936783a7b398058864277_Traceguids,uVar2,
                        puVar16[0x20]);
  }
LAB_14001a0be:
  return (ulonglong)plVar10 & 0xffffffffffffff00;
}



===== Feature_3666842937__private_IsEnabledDeviceUsageNoInline @ 14001a0e4 =====

ulonglong Feature_3666842937__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_3666842937__private_featureState;
  if ((Feature_3666842937__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3666842937__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3666842937__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3666842937__private_IsEnabledFallback @ 14001a11c =====

void Feature_3666842937__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_3666842937__private_descriptor);
  return;
}



===== GetNextPacketOptionsAndData @ 14001a138 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong GetNextPacketOptionsAndData
                    (longlong param_1,longlong param_2,longlong *param_3,undefined1 *param_4,
                    undefined2 *param_5)

{
  uint *puVar1;
  int *piVar2;
  undefined8 uVar3;
  byte bVar4;
  byte bVar5;
  undefined1 uVar6;
  int iVar7;
  uint uVar8;
  longlong lVar9;
  ulonglong uVar10;
  undefined2 uVar11;
  uint uVar12;
  ushort uVar13;
  int iVar14;
  ushort uVar15;
  ulonglong uVar16;
  longlong lVar17;
  byte bVar18;
  ushort uVar19;
  ulonglong *puVar20;
  bool bVar21;
  undefined1 auStackY_138 [32];
  byte local_f8;
  ushort local_f4 [2];
  uint local_f0;
  ulonglong local_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  uint local_c0;
  uint local_bc;
  uint local_b8;
  ulonglong *local_b0;
  ulonglong *local_a8;
  undefined1 *local_a0;
  undefined8 local_98;
  uint uStack_90;
  uint uStack_8c;
  undefined2 *local_88;
  longlong local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_138;
  lVar17 = *(longlong *)(param_1 + 0x28);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = param_5;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_c0 = 0;
  puVar20 = (ulonglong *)(*(longlong *)(lVar17 + 0x50) + *(longlong *)(param_2 + 0x78));
  local_f8 = 0;
  local_b0 = puVar20 + 4;
  *param_3 = (longlong)local_b0;
  local_bc = *(uint *)(lVar17 + 0x70);
  local_f0 = *(uint *)(lVar17 + 0x98);
  local_e8 = CONCAT44(local_e8._4_4_,*(undefined4 *)(lVar17 + 0x6c));
  if (local_bc < *(uint *)(param_2 + 0x68)) {
    local_b8 = local_bc;
  }
  else {
    local_b8 = (uint)*(ushort *)(param_2 + 0x68);
  }
  uVar8 = local_b8;
  local_e0 = 0;
  uStack_d8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_a8 = puVar20;
  local_a0 = param_4;
  local_80 = lVar17;
  if ((*(char *)(param_2 + 0x98) != '\0') && (*(uint *)(param_2 + 0x68) == local_b8)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,
              &WPP_2d619c39f4c936783a7b398058864277_Traceguids);
    }
    uVar12 = *(uint *)(param_2 + 0x3c);
    *(undefined1 *)(param_2 + 0x98) = 0;
    if (uVar12 == 0) {
      *(undefined4 *)(param_2 + 0x40) = 4;
      iVar7 = 4;
    }
    else {
      iVar7 = *(int *)(param_2 + 0x40);
    }
    if (((*(uint *)(param_1 + 0x20) & 0x4000) == 0) && (*(longlong *)(param_1 + 0x60) != 0)) {
      uVar12 = uVar12 | 0x40;
    }
    else {
      uVar12 = uVar12 | 0x80;
    }
    *(uint *)(param_2 + 0x3c) = uVar12;
    *(int *)(param_2 + 0x40) = iVar7 + 4;
  }
  uVar12 = *(uint *)(param_2 + 0x3c);
  uVar19 = (ushort)*(undefined4 *)(param_2 + 0x40);
  local_e0 = CONCAT44(uVar12,(undefined4)local_e0);
  if ((uVar12 & 1) != 0) {
    local_d0 = CONCAT44(*(int *)(param_2 + 0x48) + *(int *)(param_2 + 0x38),
                        *(undefined4 *)(param_2 + 0x60));
    uStack_c8 = CONCAT44(uStack_c8._4_4_,*(undefined4 *)(param_2 + 0x44));
  }
  uVar3 = uStack_c8;
  if ((uVar12 & 8) != 0) {
    iVar14 = local_f0 - *(int *)(lVar17 + 0xb0);
    iVar7 = *(int *)(lVar17 + 0xa4);
    if (0 < iVar14 - *(int *)(lVar17 + 0xa4)) {
      iVar7 = iVar14;
    }
    uStack_d8 = CONCAT44(iVar7,(undefined4)uStack_d8);
  }
  uVar10 = 0;
  if (*(char *)(param_1 + 0xa1) == '\0') goto LAB_14001a3b1;
  bVar18 = *(byte *)(param_1 + 0xa0);
  bVar4 = bVar18 - 1 & (byte)local_f0;
  uVar13 = (ushort)bVar18 - (ushort)bVar4;
  uVar10 = (ulonglong)uVar13;
  bVar5 = uStack_c8._7_1_;
  if (uVar13 == bVar18) {
    bVar5 = bVar18;
  }
  uStack_c8 = CONCAT17(bVar5,(undefined7)uStack_c8);
  if ((*(int *)(lVar17 + 0xbc) == 1) && (1 < uVar13)) {
    *(uint *)(lVar17 + 0xb4) = local_f0;
    if (uVar12 == 0) {
      uVar19 = 4;
    }
    uStack_c8._0_6_ = CONCAT15(bVar4 + 1,(int5)uVar3);
    local_e0 = CONCAT44(uVar12,(undefined4)local_e0) | 0x80000000000;
    uVar19 = uVar19 + 8;
    local_f8 = (char)uVar13 - 1;
    uVar15 = *(ushort *)(param_1 + 0x9e);
    uVar12 = uVar12 | 0x800;
LAB_14001a391:
    *(uint *)(param_2 + 0x8c) = (uint)uVar15;
  }
  else {
    uVar15 = *(ushort *)(param_1 + 0x9e);
    if ((uVar15 != 0) && (uVar13 == 1)) goto LAB_14001a391;
  }
  if ((*(short *)(param_1 + 0x9e) != 0) && (*(byte *)(param_1 + 0xa0) == uVar13)) {
    *(ulonglong **)(lVar17 + 0x110) = puVar20;
  }
LAB_14001a3b1:
  local_f4[0] = *(ushort *)(lVar17 + 0x70);
  KeReleaseSpinLock(param_1 + 0x168,CONCAT71((int7)(uVar10 >> 8),*local_a0));
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(*(longlong *)(param_1 + 0x28) + 0x2e0);
  lVar9 = PsGetCurrentProcess();
  bVar21 = lVar9 != PgmStaticConfig;
  if (bVar21) {
    KeStackAttachProcess();
  }
  memset(local_b0,0,0x44);
  uVar10 = InitDataSpmHeader(param_1,param_2,(ushort *)local_b0,local_f4,uVar12,(longlong)&local_e0,
                             4);
  uVar13 = local_f4[0];
  uVar16 = uVar10 & 0xffffffff;
  if ((int)uVar10 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x41,
               &WPP_2d619c39f4c936783a7b398058864277_Traceguids,(int)uVar10);
    }
  }
  else {
    local_98 = (ulonglong)local_f4[0];
    iVar7 = TdiCopyMdlToBuffer(*(undefined8 *)(*(longlong *)(param_2 + 0x18) + 8),
                               *(undefined4 *)(param_2 + 0x38),(longlong)local_b0 + local_98,0);
    if ((((iVar7 + 0x80000000U & 0x80000000) != 0) || (iVar7 == -0x7ffffffb)) && (local_c0 == uVar8)
       ) {
      uVar15 = (ushort)uVar8 >> 8 | (ushort)uVar8 << 8;
      *(uint *)(local_b0 + 2) =
           local_f0 >> 0x18 | (local_f0 & 0xff0000) >> 8 | (local_f0 & 0xff00) << 8 |
           local_f0 << 0x18;
      uVar12 = uVar13 + uVar8;
      uVar10 = (ulonglong)(uVar12 & 0xffff);
      *(ushort *)((longlong)local_b0 + 0xe) = uVar15;
      uVar11 = (undefined2)uVar12;
      local_e0 = CONCAT62(CONCAT42(local_e0._4_4_,uVar13 - 0x18),uVar11);
      *local_88 = uVar11;
      uVar16 = local_e8 & 0xffffffff;
      local_e8 = local_e8 & 0xffffffff;
      memset((void *)(uVar10 + (longlong)local_b0),0,(uVar16 - uVar10) - 0x20);
      uVar10 = local_e8;
      if (*(char *)(param_1 + 0xa1) != '\0') {
        lVar9 = local_bc + local_98;
        local_98 = CONCAT44((uint)local_d0 >> 0x18 | ((uint)local_d0 & 0xff0000) >> 8 |
                            ((uint)local_d0 & 0xff00) << 8 | (uint)local_d0 << 0x18,(uint)uVar15);
        uStack_90 = local_d0._4_4_ >> 0x18 | (local_d0._4_4_ & 0xff0000) >> 8 |
                    (local_d0._4_4_ & 0xff00) << 8 | local_d0._4_4_ << 0x18;
        uStack_8c = (uint)uStack_c8 >> 0x18 | ((uint)uStack_c8 & 0xff0000) >> 8 |
                    ((uint)uStack_c8 & 0xff00) << 8 | (uint)uStack_c8 << 0x18;
        puVar20 = (ulonglong *)(lVar9 + (longlong)local_b0);
        *puVar20 = local_98;
        puVar20[1] = CONCAT44(uStack_8c,uStack_90);
        if ((local_e0 & 0x100000000) == 0) {
          *(undefined1 *)(lVar9 + 2 + (longlong)local_b0) = 0x80;
        }
      }
      local_f0 = local_f0 + 1;
      *(undefined4 *)local_a8 = (undefined4)local_e0;
      *(uint *)((longlong)local_a8 + 4) = local_e0._4_4_;
      *(undefined4 *)(local_a8 + 1) = (undefined4)uStack_d8;
      *(undefined4 *)((longlong)local_a8 + 0xc) = uStack_d8._4_4_;
      *(uint *)(local_a8 + 2) = (uint)local_d0;
      *(uint *)((longlong)local_a8 + 0x14) = local_d0._4_4_;
      *(uint *)(local_a8 + 3) = (uint)uStack_c8;
      *(undefined4 *)((longlong)local_a8 + 0x1c) = uStack_c8._4_4_;
      if (local_f8 != 0) {
        uVar8 = local_e0._4_4_;
        if ((local_e0 & 0x100000000) != 0) {
          uVar8 = local_e0._4_4_ & 0xfffffffe;
          local_e0 = local_e0 & 0xfffffffeffffffff;
          uVar19 = uVar19 - 0x10;
        }
        uVar12 = uVar8;
        if ((uVar8 >> 0xb & 1) != 0) {
          uVar12 = uVar8 & 0xfffff7ff;
          local_e0 = CONCAT44(uVar8,(undefined4)local_e0) & 0xfffff7ffffffffff;
          uVar19 = uVar19 - 8;
        }
        local_e0._0_4_ = CONCAT22(-(ushort)(uVar12 != 0) & uVar19,(undefined2)local_e0);
        bVar18 = local_f8;
        while( true ) {
          puVar20 = (ulonglong *)((longlong)local_a8 + uVar10);
          *puVar20 = local_e0;
          puVar20[1] = uStack_d8;
          *(uint *)(puVar20 + 2) = (uint)local_d0;
          *(uint *)((longlong)puVar20 + 0x14) = local_d0._4_4_;
          *(uint *)(puVar20 + 3) = (uint)uStack_c8;
          *(undefined4 *)((longlong)puVar20 + 0x1c) = uStack_c8._4_4_;
          local_a8 = puVar20;
          memset(puVar20 + 4,0,uVar10 - 0x20);
          local_f4[0] = (ushort)local_bc;
          InitDataSpmHeader(param_1,param_2,(ushort *)(puVar20 + 4),local_f4,uVar12,
                            (longlong)&local_e0,4);
          *(uint *)(puVar20 + 6) =
               local_f0 >> 0x18 | (local_f0 & 0xff0000) >> 8 | (local_f0 & 0xff00) << 8 |
               local_f0 << 0x18;
          *(ushort *)((longlong)puVar20 + 0x2e) = 0;
          local_f0 = local_f0 + 1;
          *(ushort *)local_a8 = local_f4[0];
          *(ushort *)((longlong)local_a8 + 2) = local_f4[0] - 0x18;
          bVar18 = bVar18 - 1;
          if (bVar18 == 0) break;
          uVar12 = local_e0._4_4_;
        }
        lVar17 = local_80;
        uVar8 = local_b8;
      }
      uVar10 = local_e8;
      if (*(int *)(param_2 + 0x8c) != 0) {
        uVar12 = 0;
        lVar9 = *(longlong *)(lVar17 + 0x110);
        *(undefined4 *)(*(longlong *)(lVar17 + 0x1a8) + 4) = 0;
        *(undefined1 *)(*(longlong *)(lVar17 + 0x1a8) + 1) = 0;
        bVar18 = 0;
        if (*(char *)(param_1 + 0xa0) != '\0') {
          do {
            *(ulonglong *)(*(longlong *)(lVar17 + 0x1a8) + 8 + (ulonglong)uVar12 * 8) =
                 (ulonglong)*(ushort *)(lVar9 + 2) + 0x38 + lVar9;
            puVar1 = (uint *)(*(longlong *)(lVar17 + 0x1a8) + 4);
            *puVar1 = *puVar1 | *(uint *)(lVar9 + 4) & 0x861;
            if ((*(uint *)(lVar9 + 4) & 0x800) != 0) {
              *(undefined1 *)(*(longlong *)(lVar17 + 0x1a8) + 1) = *(undefined1 *)(lVar9 + 0x1d);
            }
            bVar18 = *(byte *)(param_1 + 0xa0);
            lVar9 = lVar9 + local_e8;
            uVar12 = uVar12 + 1;
          } while (uVar12 < bVar18);
        }
        if ((*(uint *)(*(longlong *)(lVar17 + 0x1a8) + 4) & 0x800) == 0) {
          *(byte *)(*(longlong *)(lVar17 + 0x1a8) + 1) = bVar18;
        }
      }
      if (bVar21) {
        KeUnstackDetachProcess(&local_78);
      }
      ExReleaseResourceLite(*(longlong *)(param_1 + 0x28) + 0x2e0);
      KeLeaveCriticalRegion();
      uVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x168);
      *local_a0 = uVar6;
      *(int *)(param_2 + 0x6c) = *(int *)(param_2 + 0x6c) + 1;
      *(longlong *)(param_2 + 0x78) = *(longlong *)(param_2 + 0x78) + uVar10;
      *(int *)(param_2 + 0x38) = *(int *)(param_2 + 0x38) + uVar8;
      piVar2 = (int *)(param_2 + 0x68);
      *piVar2 = *piVar2 - uVar8;
      *(uint *)(param_2 + 0x70) = uVar8;
      if (*piVar2 == 0) {
        *(undefined4 *)(param_2 + 0x5c) = *(undefined4 *)(lVar17 + 0x98);
      }
      *(int *)(lVar17 + 0xbc) = *(int *)(lVar17 + 0xbc) + -1;
      *(longlong *)(lVar17 + 0x78) =
           *(longlong *)(lVar17 + 0x78) - (ulonglong)*(uint *)(lVar17 + 0x6c);
      *(longlong *)(lVar17 + 0x80) =
           *(longlong *)(lVar17 + 0x80) + (ulonglong)*(uint *)(lVar17 + 0x6c);
      *(int *)(lVar17 + 0x9c) = *(int *)(lVar17 + 0x9c) + 1;
      *(int *)(lVar17 + 0x98) = *(int *)(lVar17 + 0x98) + 1;
      *(int *)(lVar17 + 0x74) = *(int *)(lVar17 + 0x74) + -1;
      *(uint *)(lVar17 + 0xb8) = (uint)local_f8;
      for (; local_f8 != 0; local_f8 = local_f8 - 1) {
        uVar10 = (ulonglong)*(uint *)(lVar17 + 0x6c);
        *(longlong *)(lVar17 + 0x78) = *(longlong *)(lVar17 + 0x78) - uVar10;
        *(longlong *)(lVar17 + 0x80) = *(longlong *)(lVar17 + 0x80) + uVar10;
        *(int *)(lVar17 + 0x98) = *(int *)(lVar17 + 0x98) + 1;
        *(int *)(lVar17 + 0x74) = *(int *)(lVar17 + 0x74) + -1;
        *(longlong *)(param_2 + 0x78) = *(longlong *)(param_2 + 0x78) + uVar10;
      }
      if (*(ulonglong *)(lVar17 + 0x58) <= *(ulonglong *)(lVar17 + 0x80)) {
        *(undefined8 *)(lVar17 + 0x80) = 0;
      }
      if (*(ulonglong *)(lVar17 + 0x58) <= *(ulonglong *)(param_2 + 0x78)) {
        *(undefined8 *)(param_2 + 0x78) = 0;
      }
      return 0;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,
                 &WPP_2d619c39f4c936783a7b398058864277_Traceguids,iVar7,(char)local_c0,(char)uVar8);
    }
    uVar16 = 0xc0000001;
  }
  if (bVar21) {
    KeUnstackDetachProcess(&local_78);
  }
  ExReleaseResourceLite(*(longlong *)(param_1 + 0x28) + 0x2e0);
  KeLeaveCriticalRegion();
  uVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x168);
  *local_a0 = uVar6;
  if (((*(uint *)(param_2 + 0x3c) & 0x40) != 0) && (*(uint *)(param_2 + 0x68) == uVar8)) {
    uVar8 = *(uint *)(param_2 + 0x3c) & 0xffffffbf;
    *(undefined1 *)(param_2 + 0x98) = 1;
    *(uint *)(param_2 + 0x3c) = uVar8;
    if (uVar8 == 0) {
      *(undefined4 *)(param_2 + 0x40) = 0;
    }
    else {
      *(int *)(param_2 + 0x40) = *(int *)(param_2 + 0x40) + -4;
    }
  }
  *(undefined4 *)(param_2 + 0x8c) = 0;
  return uVar16;
}



===== InitDataSpmHeader @ 14001a9a8 =====

ulonglong InitDataSpmHeader(longlong param_1,longlong param_2,ushort *param_3,ushort *param_4,
                           uint param_5,longlong param_6,byte param_7)

{
  ushort uVar1;
  ulonglong uVar2;
  undefined2 uVar3;
  uint uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort local_res8 [4];
  
  if ((param_1 == 0) ||
     ((*(int *)(param_1 + 0x10) != 0x53534553 && (*(int *)(param_1 + 0x10) != 0x32534553)))) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
               &WPP_2d619c39f4c936783a7b398058864277_Traceguids,param_1);
    }
    return 0xc0000001;
  }
  uVar1 = *param_4;
  if (uVar1 < 0x10) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                &WPP_2d619c39f4c936783a7b398058864277_Traceguids,(uint)uVar1,0x10);
    }
    return 0xc0000206;
  }
  uVar4 = (uint)param_7;
  *param_3 = *(ushort *)(param_1 + 0x46) >> 8 | *(ushort *)(param_1 + 0x46) << 8;
  *(undefined4 *)(param_3 + 4) = *(undefined4 *)(param_1 + 0x40);
  param_3[6] = *(ushort *)(param_1 + 0x44);
  *(byte *)(param_3 + 2) = param_7;
  *(undefined1 *)((longlong)param_3 + 5) = 0;
  uVar5 = *(ushort *)(*(longlong *)(param_1 + 0x28) + 0x30);
  param_3[1] = uVar5 >> 8 | uVar5 << 8;
  if (param_7 == 0) {
    uVar5 = 0x24;
    if (param_5 != (param_5 & 0x1ebc8)) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc000000d;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
        return 0xc000000d;
      }
      uVar3 = 0x15;
      goto LAB_14001ab6e;
    }
    uVar4 = param_5 & 0x12a00;
  }
  else {
    if (uVar4 == 4) {
      uVar5 = 0x18;
      if (param_5 != (param_5 & 0xc69)) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0xc000000d;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
          return 0xc000000d;
        }
        uVar3 = 0x16;
        goto LAB_14001ab6e;
      }
      goto LAB_14001ab95;
    }
    if (uVar4 != 5) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc000000d;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
        return 0xc000000d;
      }
      uVar3 = 0x18;
      param_5 = uVar4;
LAB_14001ab6e:
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
               &WPP_2d619c39f4c936783a7b398058864277_Traceguids,param_5);
      return 0xc000000d;
    }
    uVar5 = 0x18;
    if (param_5 != (param_5 & 0xc69)) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc000000d;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
        return 0xc000000d;
      }
      uVar3 = 0x17;
      goto LAB_14001ab6e;
    }
    uVar4 = param_5 & 0x800;
  }
  if (uVar4 != 0) {
    *(undefined1 *)((longlong)param_3 + 5) = 2;
  }
LAB_14001ab95:
  if (uVar1 < uVar5) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_DdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)param_7,(ulonglong)uVar1,
                 (uint)uVar1,(char)uVar5,param_7);
    }
    return 0xc0000173;
  }
  uVar6 = 0;
  if (param_5 != 0) {
    local_res8[0] = uVar1 - uVar5;
    uVar2 = InitDataSpmOptions(param_1,param_2,(undefined2 *)((ulonglong)uVar5 + (longlong)param_3),
                               local_res8,param_5,param_6);
    if ((int)uVar2 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                 &WPP_2d619c39f4c936783a7b398058864277_Traceguids,(int)uVar2);
      }
      return uVar2 & 0xffffffff;
    }
    *(byte *)((longlong)param_3 + 5) = *(byte *)((longlong)param_3 + 5) | 1;
    uVar6 = local_res8[0];
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
    WPP_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
               &WPP_2d619c39f4c936783a7b398058864277_Traceguids,param_3,(char)uVar5,(char)uVar6);
  }
  *param_4 = uVar6 + uVar5;
  return 0;
}



===== InitDataSpmOptions @ 14001acfc =====

undefined8
InitDataSpmOptions(longlong param_1,longlong param_2,undefined2 *param_3,ushort *param_4,
                  uint param_5,longlong param_6)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  undefined2 uVar4;
  uint uVar5;
  byte *pbVar6;
  ushort uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  
  uVar1 = *param_4;
  pbVar6 = (byte *)0x0;
  uVar9 = 4;
  if (uVar1 < 4) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000173;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return 0xc0000173;
    }
    uVar4 = 10;
    uVar5 = 4;
    goto LAB_14001b034;
  }
  *param_3 = 0x400;
  if ((param_5 & 0x12000) != 0) {
    return 0xc00000bb;
  }
  if ((param_5 >> 9 & 1) != 0) {
    pbVar6 = (byte *)(param_3 + 2);
    uVar9 = 0xc;
    if (uVar1 < 0xc) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc0000173;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
        return 0xc0000173;
      }
      uVar4 = 0xb;
      uVar5 = 0xc;
      goto LAB_14001b034;
    }
    pbVar6[0] = 8;
    pbVar6[1] = 8;
    *(undefined1 *)((longlong)param_3 + 7) = *(undefined1 *)(param_1 + 0xa1);
    *(uint *)(param_3 + 4) = (uint)*(byte *)(param_6 + 0x1c) << 0x18;
  }
  uVar8 = uVar9;
  if ((param_5 >> 0xb & 1) == 0) {
LAB_14001ae34:
    uVar9 = uVar8;
    if ((param_5 & 0x20) != 0) {
      uVar7 = (short)uVar8 + 4;
      uVar9 = (ulonglong)uVar7;
      pbVar6 = (byte *)(uVar8 + (longlong)param_3);
      if (uVar1 < uVar7) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0xc0000173;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
          return 0xc0000173;
        }
        uVar4 = 0xd;
        goto LAB_14001b030;
      }
      pbVar6[0] = 0xd;
      pbVar6[1] = 4;
      if ((param_2 != 0) && ((*(uint *)(param_2 + 0x3c) & 0x20) != 0)) {
        *(int *)(param_2 + 0x40) = *(int *)(param_2 + 0x40) + -4;
        uVar5 = *(uint *)(param_2 + 0x3c) & 0xffffffdf;
        *(uint *)(param_2 + 0x3c) = uVar5;
        if (uVar5 == 0) {
          *(undefined4 *)(param_2 + 0x40) = 0;
        }
      }
    }
    uVar8 = uVar9;
    if ((param_5 & 0x40) != 0) {
      uVar7 = (short)uVar9 + 4;
      uVar8 = (ulonglong)uVar7;
      pbVar6 = (byte *)(uVar9 + (longlong)param_3);
      if (uVar1 < uVar7) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0xc0000173;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
          return 0xc0000173;
        }
        uVar4 = 0xe;
        goto LAB_14001b030;
      }
      pbVar6[0] = 0xe;
      pbVar6[1] = 4;
    }
    uVar9 = uVar8;
    if ((param_5 & 0x180) != 0) {
      uVar7 = (short)uVar8 + 4;
      uVar9 = (ulonglong)uVar7;
      pbVar6 = (byte *)(uVar8 + (longlong)param_3);
      if (uVar1 < uVar7) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0xc0000173;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
          return 0xc0000173;
        }
        uVar4 = 0xf;
        goto LAB_14001b030;
      }
      pbVar6[0] = 0xf;
      pbVar6[1] = 4;
      if ((param_5 >> 8 & 1) != 0) {
        pbVar6[3] = 0x80;
      }
    }
    uVar8 = uVar9;
    if ((param_5 >> 10 & 1) != 0) {
      uVar7 = (short)uVar9 + 8;
      uVar8 = (ulonglong)uVar7;
      pbVar6 = (byte *)(uVar9 + (longlong)param_3);
      if (uVar1 < uVar7) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0xc0000173;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
          return 0xc0000173;
        }
        uVar4 = 0x10;
        goto LAB_14001b030;
      }
      *(uint *)(pbVar6 + 4) = (uint)*(byte *)(param_6 + 0x1c) << 0x18;
      pbVar6[0] = 9;
      pbVar6[1] = 8;
    }
    if ((param_5 & 1) != 0) {
      *(short *)(param_6 + 10) = (short)uVar8;
      pbVar6 = (byte *)(uVar8 + (longlong)param_3);
      uVar7 = (short)uVar8 + 0x10;
      uVar8 = (ulonglong)uVar7;
      if (uVar1 < uVar7) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0xc0000173;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
          return 0xc0000173;
        }
        uVar4 = 0x11;
        goto LAB_14001b030;
      }
      uVar5 = *(uint *)(param_6 + 0x10);
      uVar2 = *(uint *)(param_6 + 0x14);
      uVar3 = *(uint *)(param_6 + 0x18);
      pbVar6[0] = 1;
      pbVar6[1] = 0x10;
      *(uint *)(pbVar6 + 4) =
           uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
      *(uint *)(pbVar6 + 8) =
           uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      *(uint *)(pbVar6 + 0xc) =
           uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    }
    uVar7 = (ushort)uVar8;
    if ((param_5 & 8) == 0) {
LAB_14001b05e:
      if ((uVar7 != 0) && (param_3[1] = uVar7 >> 8 | uVar7 << 8, pbVar6 != (byte *)0x0)) {
        *pbVar6 = *pbVar6 | 0x80;
      }
      *param_4 = uVar7;
      return 0;
    }
    *(ushort *)(param_6 + 8) = uVar7;
    pbVar6 = (byte *)(uVar8 + (longlong)param_3);
    uVar7 = uVar7 + 8;
    if (uVar7 <= uVar1) {
      uVar5 = *(uint *)(param_6 + 0xc);
      *(uint *)(pbVar6 + 4) =
           uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
      pbVar6[0] = 3;
      pbVar6[1] = 8;
      goto LAB_14001b05e;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000173;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return 0xc0000173;
    }
    uVar4 = 0x12;
  }
  else {
    uVar7 = (short)uVar9 + 8;
    uVar8 = (ulonglong)uVar7;
    pbVar6 = (byte *)(uVar9 + (longlong)param_3);
    if (uVar7 <= uVar1) {
      *(uint *)(pbVar6 + 4) = (uint)*(byte *)(param_6 + 0x1d) << 0x18;
      pbVar6[0] = 10;
      pbVar6[1] = 8;
      goto LAB_14001ae34;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000173;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return 0xc0000173;
    }
    uVar4 = 0xc;
  }
LAB_14001b030:
  uVar5 = (uint)uVar7;
LAB_14001b034:
  WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
            &WPP_2d619c39f4c936783a7b398058864277_Traceguids,uVar5,(char)uVar1);
  return 0xc0000173;
}



===== PgmBuildParityPacket @ 14001b0a0 =====

ulonglong PgmBuildParityPacket
                    (longlong param_1,longlong param_2,byte *param_3,ushort *param_4,ushort *param_5
                    ,byte param_6)

{
  undefined8 *puVar1;
  byte *pbVar2;
  byte bVar3;
  short sVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  ushort uVar8;
  byte bVar9;
  ulonglong uVar10;
  ushort uVar11;
  ulonglong uVar12;
  uint uVar13;
  ushort local_res8 [4];
  longlong local_res10;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  
  local_58 = 0;
  uStack_50 = 0;
  bVar9 = *(byte *)(param_1 + 0xa0);
  local_res8[0] = *param_5;
  *param_5 = 0;
  bVar3 = *(byte *)(param_2 + 0x1f);
  *param_3 = bVar3;
  uVar5 = *(uint *)(param_2 + 0x30);
  uVar13 = *(uint *)(param_3 + 4);
  local_48 = 0;
  uStack_40 = 0;
  if ((uVar13 >> 0xb & 1) != 0) {
    uStack_40 = (ulonglong)param_3[1] << 0x28;
  }
  if (*(byte *)(param_1 + 0xa0) <= bVar3) {
    uVar13 = uVar13 | 0x400;
    *(uint *)(param_3 + 4) = uVar13;
    uStack_40 = (ulonglong)CONCAT31(uStack_40._5_3_,bVar3 / *(byte *)(param_1 + 0xa0)) << 0x20;
  }
  local_res10 = param_2;
  uVar10 = InitDataSpmHeader(param_1,0,param_4,local_res8,uVar13,(longlong)&local_58,param_6);
  uVar8 = local_res8[0];
  if ((int)uVar10 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
               &WPP_2d619c39f4c936783a7b398058864277_Traceguids,(int)uVar10);
    }
  }
  else {
    uVar12 = (ulonglong)local_res8[0];
    uVar10 = FECEncode((int *)(param_1 + 0x70),(longlong)(param_3 + 8),(ulonglong)param_3[1],
                       *(int *)(*(longlong *)(param_1 + 0x28) + 0x70) + 0x10,(uint)*param_3,
                       (byte *)((longlong)param_4 + uVar12));
    if ((int)uVar10 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
                 &WPP_2d619c39f4c936783a7b398058864277_Traceguids,(int)uVar10);
      }
    }
    else {
      *(byte *)((longlong)param_4 + 5) = *(byte *)((longlong)param_4 + 5) | 0xc0;
      if ((*(uint *)(param_3 + 4) & 1) != 0) {
        puVar1 = (undefined8 *)
                 (*(uint *)(*(longlong *)(param_1 + 0x28) + 0x70) + uVar12 + (longlong)param_4);
        uVar6 = *puVar1;
        uVar7 = puVar1[1];
        uStack_64 = (undefined4)((ulonglong)uVar6 >> 0x20);
        uStack_60 = (undefined4)uVar7;
        uStack_5c = (undefined4)((ulonglong)uVar7 >> 0x20);
        if (uStack_50._2_2_ != 0) {
          pbVar2 = (byte *)((ulonglong)uStack_50._2_2_ + 0x1a + (longlong)param_4);
          *pbVar2 = *pbVar2 | 4;
          uVar12 = (ulonglong)uStack_50._2_2_;
          *(char *)(uVar12 + 0x1b + (longlong)param_4) = (char)((ulonglong)uVar6 >> 0x10);
          *(ulonglong *)(uVar12 + 0x1c + (longlong)param_4) = CONCAT44(uStack_60,uStack_64);
          *(undefined4 *)(uVar12 + 0x24 + (longlong)param_4) = uStack_5c;
        }
      }
      sVar4 = *(short *)(*(longlong *)(param_1 + 0x28) + 0x70);
      *(uint *)(param_4 + 8) = uVar5 & 0xffffff | (uVar5 >> 0x18 | (uint)bVar3 & bVar9 - 1) << 0x18;
      uVar11 = sVar4 + 2;
      param_4[7] = uVar11 >> 8 | uVar11 * 0x100;
      *param_3 = *param_3 + 1;
      bVar9 = *param_3;
      if (*(ushort *)(param_1 + 0x9c) <= (ushort)bVar9) {
        bVar9 = *(byte *)(param_1 + 0xa0);
        *param_3 = bVar9;
      }
      *(byte *)(local_res10 + 0x1f) = bVar9;
      *param_5 = uVar8 + 2 + *(short *)(*(longlong *)(param_1 + 0x28) + 0x70);
    }
  }
  return uVar10 & 0xffffffff;
}



===== PgmCancelAllSends @ 14001b2e8 =====

void PgmCancelAllSends(longlong param_1,longlong param_2,longlong *param_3)

{
  int *piVar1;
  longlong *plVar2;
  longlong *plVar3;
  ulonglong uVar4;
  code *pcVar5;
  char cVar6;
  char cVar7;
  longlong *plVar8;
  uint uVar9;
  ulonglong uVar10;
  int iVar11;
  int iVar12;
  longlong *plVar13;
  longlong lVar14;
  int iVar15;
  
  iVar15 = 0;
  while( true ) {
    lVar14 = *(longlong *)(param_1 + 0x28);
    plVar8 = (longlong *)(lVar14 + 0xf8);
    plVar13 = (longlong *)*plVar8;
    if (plVar13 == plVar8) break;
    if (((longlong *)plVar13[1] != plVar8) ||
       (lVar14 = *plVar13, (longlong *)*(longlong *)(lVar14 + 8) != plVar13)) goto LAB_14001b688;
    *plVar8 = lVar14;
    *(longlong **)(lVar14 + 8) = plVar8;
    plVar8 = *(longlong **)(param_2 + 8);
    if (*plVar8 != param_2) goto LAB_14001b688;
    *plVar13 = param_2;
    iVar15 = iVar15 + 1;
    plVar13[1] = (longlong)plVar8;
    *plVar8 = (longlong)plVar13;
    *(longlong **)(param_2 + 8) = plVar13;
    if (plVar13[10] != 0) {
      if (plVar13[4] != 0) {
        *(longlong *)(plVar13[10] + 0x20) = plVar13[4];
        plVar13[4] = 0;
      }
      *(undefined8 *)(plVar13[10] + 0x50) = 0;
      plVar13[10] = 0;
    }
    piVar1 = (int *)(*(longlong *)(param_1 + 0x28) + 0x90);
    *piVar1 = *piVar1 + -1;
    piVar1 = (int *)(*(longlong *)(param_1 + 0x28) + 0xbc);
    *piVar1 = *piVar1 - *(int *)((longlong)plVar13 + 0x4c);
  }
  iVar11 = *(int *)(lVar14 + 0x98);
  plVar8 = (longlong *)**(undefined8 **)(lVar14 + 0xe8);
  plVar13 = param_3;
  if (plVar8 != (longlong *)(lVar14 + 0xe8)) {
    do {
      lVar14 = *plVar8;
      plVar13 = (longlong *)plVar8[1];
      if ((*(longlong **)(lVar14 + 8) != plVar8) || ((longlong *)*plVar13 != plVar8))
      goto LAB_14001b688;
      *plVar13 = lVar14;
      *(longlong **)(lVar14 + 8) = plVar13;
      plVar2 = *(longlong **)(param_2 + 8);
      if (*plVar2 != param_2) goto LAB_14001b688;
      *plVar8 = param_2;
      iVar15 = iVar15 + 1;
      plVar8[1] = (longlong)plVar2;
      *plVar2 = (longlong)plVar8;
      *(longlong **)(param_2 + 8) = plVar8;
      piVar1 = (int *)(*(longlong *)(param_1 + 0x28) + 0x90);
      *piVar1 = *piVar1 + -1;
      piVar1 = (int *)(*(longlong *)(param_1 + 0x28) + 0xbc);
      *piVar1 = *piVar1 - *(int *)((longlong)plVar8 + 0x4c);
      if ((int)plVar8[0xb] - iVar11 < 0) {
        iVar11 = (int)plVar8[0xb];
      }
      if (plVar8[10] != 0) {
        if (plVar8[4] != 0) {
          *(longlong *)(plVar8[10] + 0x20) = plVar8[4];
          plVar8[4] = 0;
        }
        *(undefined8 *)(plVar8[10] + 0x50) = 0;
        plVar8[10] = 0;
      }
      lVar14 = *(longlong *)(param_1 + 0x28);
      plVar8 = (longlong *)*plVar13;
    } while (plVar8 != (longlong *)(lVar14 + 0xe8));
  }
  plVar2 = *(longlong **)(lVar14 + 0xe8);
  if ((plVar2 != (longlong *)(lVar14 + 0xe8)) &&
     (((*(int *)(plVar2 + 0x10) == 0 || (param_3 == (longlong *)0x0)) ||
      ((longlong *)plVar2[3] == param_3)))) {
    lVar14 = *plVar2;
    if (((longlong *)*(longlong *)(lVar14 + 8) != plVar2) ||
       (plVar3 = (longlong *)plVar2[1], (longlong *)*plVar3 != plVar2)) {
LAB_14001b688:
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    *plVar3 = lVar14;
    iVar15 = iVar15 + 1;
    *(longlong **)(lVar14 + 8) = plVar3;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
      WPP_SF_qddddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),plVar8,plVar13,plVar2[3],
                    (char)*(undefined4 *)(plVar2 + 0xd),
                    (char)*(undefined4 *)((longlong)plVar2 + 100),
                    (char)*(undefined4 *)(plVar2 + 0x10),
                    (char)*(undefined4 *)((longlong)plVar2 + 0x6c),
                    (char)*(undefined4 *)(plVar2 + 0x11));
    }
    *(undefined4 *)((longlong)plVar2 + 0x6c) = *(undefined4 *)(plVar2 + 0x10);
    *(undefined4 *)(plVar2 + 0xd) = 0;
    *(undefined4 *)((longlong)plVar2 + 0x8c) = 0;
    piVar1 = (int *)(*(longlong *)(param_1 + 0x28) + 0x90);
    *piVar1 = *piVar1 + -1;
    piVar1 = (int *)(*(longlong *)(param_1 + 0x28) + 0xbc);
    *piVar1 = *piVar1 - *(int *)((longlong)plVar2 + 0x4c);
    if (*(int *)(plVar2 + 0x11) == 0) {
      if (plVar2[10] != 0) {
        if (plVar2[4] != 0) {
          *(longlong *)(plVar2[10] + 0x20) = plVar2[4];
          plVar2[4] = 0;
        }
        *(undefined8 *)(plVar2[10] + 0x50) = 0;
        plVar2[10] = 0;
      }
      plVar8 = *(longlong **)(param_2 + 8);
      if (*plVar8 != param_2) goto LAB_14001b688;
      *plVar2 = param_2;
      plVar2[1] = (longlong)plVar8;
      *plVar8 = (longlong)plVar2;
      *(longlong **)(param_2 + 8) = plVar2;
    }
    else {
      lVar14 = *(longlong *)(param_1 + 0x28);
      plVar8 = *(longlong **)(lVar14 + 0xe0);
      if (*plVar8 != lVar14 + 0xd8) goto LAB_14001b688;
      *plVar2 = lVar14 + 0xd8;
      plVar2[1] = (longlong)plVar8;
      *plVar8 = (longlong)plVar2;
      *(longlong **)(lVar14 + 0xe0) = plVar2;
    }
    *(undefined4 *)((longlong)plVar2 + 0x5c) = *(undefined4 *)(*(longlong *)(param_1 + 0x28) + 0x9c)
    ;
    lVar14 = *(longlong *)(param_1 + 0x28);
    iVar11 = *(int *)(lVar14 + 0x9c) + 1;
  }
  iVar12 = *(int *)(lVar14 + 0x98) - iVar11;
  uVar9 = iVar12 * *(int *)(lVar14 + 0x6c);
  uVar10 = (ulonglong)uVar9;
  if (iVar12 != 0) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x4000;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
      cVar7 = (char)uVar9;
      cVar6 = (char)*(undefined4 *)(lVar14 + 0x80);
      WPP_SF_ddddddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x48,
                     &WPP_2d619c39f4c936783a7b398058864277_Traceguids,iVar15,(char)iVar12,
                     (char)*(undefined4 *)(lVar14 + 0x98),(char)iVar11,cVar7,cVar6,cVar6 - cVar7);
    }
  }
  *(int *)(*(longlong *)(param_1 + 0x28) + 0x98) = iVar11;
  piVar1 = (int *)(*(longlong *)(param_1 + 0x28) + 0x74);
  *piVar1 = *piVar1 + iVar12;
  plVar8 = (longlong *)(*(longlong *)(param_1 + 0x28) + 0x78);
  *plVar8 = *plVar8 + uVar10;
  lVar14 = *(longlong *)(param_1 + 0x28);
  uVar4 = *(ulonglong *)(lVar14 + 0x80);
  if (uVar4 < uVar10) {
    *(ulonglong *)(lVar14 + 0x80) = (*(longlong *)(lVar14 + 0x58) - uVar10) + uVar4;
  }
  else {
    *(ulonglong *)(lVar14 + 0x80) = uVar4 - uVar10;
  }
  return;
}



===== PgmCancelSendIrp @ 14001b6a0 =====

void PgmCancelSendIrp(undefined8 param_1,longlong *param_2,undefined8 param_3,longlong *param_4)

{
  longlong *******ppppppplVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *******ppppppplVar4;
  undefined8 uVar5;
  code *pcVar6;
  undefined1 uVar7;
  longlong *plVar8;
  longlong *******ppppppplVar9;
  longlong *******ppppppplVar10;
  undefined1 *puVar11;
  longlong *plVar12;
  int iVar13;
  undefined1 auStackY_48 [8];
  undefined1 auStackY_40 [24];
  longlong *******local_18;
  longlong *******ppppppplStack_10;
  
  uVar7 = 0;
  plVar3 = *(longlong **)(*(longlong *)(param_2[0x17] + 0x30) + 0x18);
  local_18 = (longlong *******)0x0;
  ppppppplStack_10 = (longlong *******)0x0;
  if ((plVar3 == (longlong *)0x0) || ((int)plVar3[2] != 0x53534553)) {
    IoReleaseCancelSpinLock
              (CONCAT71((int7)((ulonglong)*(longlong *)(param_2[0x17] + 0x30) >> 8),
                        *(undefined1 *)((longlong)param_2 + 0x45)));
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return;
    }
    if (plVar3 != (longlong *)0x0) {
      uVar7 = (undefined1)plVar3[3];
    }
    WPP_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x69,
               &WPP_2d619c39f4c936783a7b398058864277_Traceguids,param_2,(char)plVar3,uVar7);
    return;
  }
  plVar2 = plVar3 + 0x2d;
  uVar7 = KeAcquireSpinLockRaiseToDpc(plVar2);
  plVar12 = (longlong *)(plVar3[5] + 0xf8);
  plVar8 = plVar12;
  while (plVar8 = (longlong *)*plVar8, plVar8 != plVar12) {
    if ((longlong *)plVar8[3] == param_2) goto LAB_14001b73e;
  }
  plVar12 = (longlong *)(plVar3[5] + 0xe8);
  plVar8 = plVar12;
  do {
    plVar8 = (longlong *)*plVar8;
    if (plVar8 == plVar12) {
      KeReleaseSpinLock(plVar2,CONCAT71((int7)((ulonglong)plVar12 >> 8),uVar7));
      IoReleaseCancelSpinLock(*(undefined1 *)((longlong)param_2 + 0x45));
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) == 0) {
        return;
      }
      WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6a,
               &WPP_2d619c39f4c936783a7b398058864277_Traceguids,param_2);
      return;
    }
  } while ((longlong *)plVar8[3] != param_2);
LAB_14001b73e:
  ppppppplStack_10 = (longlong *******)&local_18;
  ppppppplVar9 = (longlong *******)&local_18;
  local_18 = (longlong *******)&local_18;
  plVar12 = param_2;
  PgmCancelAllSends((longlong)plVar3,(longlong)ppppppplVar9,param_2);
  ppppppplVar9 = (longlong *******)CONCAT71((int7)((ulonglong)ppppppplVar9 >> 8),uVar7);
  KeReleaseSpinLock(plVar2);
  IoReleaseCancelSpinLock(*(undefined1 *)((longlong)param_2 + 0x45));
  puVar11 = auStackY_48;
  iVar13 = 0;
  do {
    ppppppplVar10 = local_18;
    if ((longlong ********)local_18 == &local_18) {
LAB_14001b7fb:
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
        uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        *(longlong **)(puVar11 + 0x20) = param_2;
        *(undefined8 *)(puVar11 + -8) = 0x14001b83a;
        WPP_SF_Dq(uVar5,0x6b,&WPP_2d619c39f4c936783a7b398058864277_Traceguids,iVar13,puVar11[0x20]);
      }
      return;
    }
    if (((longlong ********)local_18[1] != &local_18) ||
       (ppppppplVar4 = (longlong *******)*local_18, (longlong *******)ppppppplVar4[1] != local_18))
    {
      pcVar6 = (code *)swi(0x29);
      (*pcVar6)(3);
      puVar11 = auStackY_40;
      goto LAB_14001b7fb;
    }
    ppppppplVar4[1] = (longlong ******)&local_18;
    ppppppplVar1 = local_18 + 4;
    local_18 = ppppppplVar4;
    if (*ppppppplVar1 != (longlong ******)0x0) {
      iVar13 = iVar13 + 1;
      plVar12 = (longlong *)0x0;
      ppppppplVar9 = (longlong *******)0xc0000120;
      PgmIoComplete((longlong)*ppppppplVar1,0xc0000120,0);
    }
    PgmDereferenceSessionCommon(plVar3,ppppppplVar9,plVar12,param_4);
    ExFreeToNPagedLookasideList(plVar3[5] + 0x240);
    ppppppplVar9 = ppppppplVar10;
  } while( true );
}



===== PgmSendNcf @ 14001b90c =====

ulonglong PgmSendNcf(longlong param_1,longlong param_2,int *param_3,uint param_4)

{
  ulonglong *puVar1;
  short *psVar2;
  ushort uVar3;
  longlong lVar4;
  undefined1 uVar5;
  int iVar6;
  ulonglong *puVar7;
  ulonglong uVar8;
  uint uVar9;
  uint *puVar10;
  ushort uVar11;
  ushort *puVar12;
  
  uVar11 = 0;
  puVar7 = (ulonglong *)ExAllocatePool2(0x40,param_4,0x326d6750);
  if (puVar7 == (ulonglong *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
              &WPP_2d619c39f4c936783a7b398058864277_Traceguids);
    }
    uVar8 = 0xc000009a;
  }
  else {
    puVar12 = (ushort *)(param_3 + 0x3f);
    uVar3 = *(ushort *)(*(longlong *)(param_1 + 0x28) + 0x30);
    *(ushort *)((longlong)puVar7 + 2) = uVar3 >> 8 | uVar3 << 8;
    *(ushort *)puVar7 = *(ushort *)(param_1 + 0x46) >> 8 | *(ushort *)(param_1 + 0x46) << 8;
    *(undefined4 *)(puVar7 + 1) = *(undefined4 *)(param_1 + 0x40);
    *(undefined2 *)((longlong)puVar7 + 0xc) = *(undefined2 *)(param_1 + 0x44);
    *(undefined1 *)((longlong)puVar7 + 4) = 10;
    if (*(short *)((longlong)param_3 + 0xfe) == 2) {
      *(undefined1 *)((longlong)puVar7 + 5) = 0x80;
      uVar8 = 0;
      if (*puVar12 != 0) {
        do {
          uVar9 = (int)uVar8 + 1;
          psVar2 = (short *)((longlong)param_3 + uVar8 * 2 + 0x100);
          *psVar2 = *psVar2 + -1;
          uVar8 = (ulonglong)uVar9;
        } while (uVar9 < *puVar12);
      }
    }
    else {
      *(undefined1 *)((longlong)puVar7 + 5) = 0;
    }
    uVar3 = *puVar12;
    *(undefined2 *)((longlong)puVar7 + 0x14) = *(undefined2 *)(param_2 + 0x14);
    *(undefined4 *)(puVar7 + 3) = *(undefined4 *)(param_2 + 0x18);
    *(undefined2 *)((longlong)puVar7 + 0x1c) = *(undefined2 *)(param_2 + 0x1c);
    *(undefined4 *)(puVar7 + 4) = *(undefined4 *)(param_2 + 0x20);
    uVar9 = (uint)*(ushort *)(param_3 + 0x40) + *param_3;
    *(uint *)(puVar7 + 2) =
         uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 * 0x1000000;
    if (1 < uVar3) {
      uVar11 = *puVar12;
      puVar1 = puVar7 + 5;
      *(undefined2 *)((longlong)puVar7 + 0x24) = 0x400;
      *(char *)((longlong)puVar7 + 0x29) = (char)uVar11 << 2;
      *(byte *)puVar1 = 2;
      if (1 < uVar3) {
        puVar12 = (ushort *)((longlong)param_3 + 0x102);
        puVar10 = (uint *)((longlong)puVar7 + 0x2c);
        uVar8 = (ulonglong)(uVar3 - 1);
        do {
          uVar11 = *puVar12;
          puVar12 = puVar12 + 1;
          uVar9 = (uint)uVar11 +
                  *(int *)(((longlong)param_3 - (longlong)puVar1) + (longlong)puVar10);
          *puVar10 = uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 |
                     uVar9 * 0x1000000;
          puVar10 = puVar10 + 1;
          uVar8 = uVar8 - 1;
        } while (uVar8 != 0);
      }
      *(byte *)puVar1 = (byte)*puVar1 | 0x80;
      *(byte *)((longlong)puVar7 + 5) = *(byte *)((longlong)puVar7 + 5) | 3;
      uVar11 = *(byte *)((longlong)puVar7 + 0x29) + 4;
      *(ushort *)((longlong)puVar7 + 0x26) = uVar11 >> 8 | uVar11 * 0x100;
    }
    *(undefined2 *)((longlong)puVar7 + 6) = 0;
    iVar6 = tcpxsum(0,puVar7,param_4);
    *(ushort *)((longlong)puVar7 + 6) = ~(ushort)iVar6;
    uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x168);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    KeReleaseSpinLock(param_1 + 0x168,uVar5);
    lVar4 = *(longlong *)(param_1 + 0x28);
    uVar8 = TdiSendDatagram(*(undefined8 *)(*(longlong *)(lVar4 + 0x20) + 0x60),
                            *(undefined8 *)(*(longlong *)(lVar4 + 0x20) + 0x68),puVar7,
                            (uint)(ushort)(uVar11 + 0x24),PgmSendNcfCompletion,param_1,puVar7,
                            *(uint *)(lVar4 + 0x28),*(ushort *)(lVar4 + 0x30),'\0');
    uVar8 = uVar8 & 0xffffffff;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      WPP_SF_dDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
                 &WPP_2d619c39f4c936783a7b398058864277_Traceguids,param_4,
                 (char)*(undefined4 *)(*(longlong *)(param_1 + 0x28) + 0x28),
                 (char)*(undefined2 *)(*(longlong *)(param_1 + 0x28) + 0x30));
    }
  }
  return uVar8;
}



===== PgmSendNcfCompletion @ 14001bbb0 =====

void PgmSendNcfCompletion(longlong *param_1,ulonglong param_2,uint param_3,longlong *param_4)

{
  undefined1 uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined **ppuVar4;
  longlong *plVar5;
  
  plVar5 = (longlong *)(ulonglong)param_3;
  uVar2 = param_2;
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x2d);
  if ((int)param_3 < 0) {
    ppuVar4 = &WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      ppuVar4 = (undefined **)&WPP_2d619c39f4c936783a7b398058864277_Traceguids;
      uVar2 = 0;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
               &WPP_2d619c39f4c936783a7b398058864277_Traceguids,param_3);
      param_4 = plVar5;
    }
  }
  else {
    ppuVar4 = &WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
       (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      ppuVar4 = (undefined **)&WPP_2d619c39f4c936783a7b398058864277_Traceguids;
      uVar2 = 0;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
              &WPP_2d619c39f4c936783a7b398058864277_Traceguids);
    }
  }
  uVar3 = CONCAT71((int7)(uVar2 >> 8),uVar1);
  KeReleaseSpinLock(param_1 + 0x2d);
  PgmDereferenceSessionCommon(param_1,uVar3,ppuVar4,param_4);
  ExFreePoolWithTag(param_2,0);
  return;
}



===== PgmSendNextOData @ 14001bca0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PgmSendNextOData(longlong param_1,undefined1 *param_2,uint *param_3)

{
  longlong *plVar1;
  undefined4 uVar2;
  uint uVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  undefined1 uVar7;
  int iVar8;
  void *_Dst;
  longlong lVar9;
  ulonglong uVar10;
  longlong *plVar11;
  bool bVar12;
  undefined1 auStackY_e8 [32];
  ushort local_98 [4];
  ulonglong *local_90;
  undefined1 *local_88;
  uint *local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_e8;
  lVar4 = *(longlong *)(param_1 + 0x28);
  *param_3 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_98[0] = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_90 = (ulonglong *)0x0;
  _Dst = (void *)0x0;
  local_58 = 0;
  uStack_50 = 0;
  if (*(uint *)(*(longlong *)(param_1 + 0x28) + 0x74) < (uint)*(byte *)(param_1 + 0xa0)) {
    return 0;
  }
  plVar1 = (longlong *)(lVar4 + 0xe8);
  plVar11 = (longlong *)*plVar1;
  local_88 = param_2;
  local_80 = param_3;
  if (plVar11 == plVar1) {
    plVar11 = *(longlong **)(lVar4 + 0xf8);
    if (plVar11 == (longlong *)(lVar4 + 0xf8)) {
      return 0xc0000001;
    }
    lVar9 = *plVar11;
    if ((*(longlong **)(lVar9 + 8) != plVar11) ||
       (plVar5 = (longlong *)plVar11[1], (longlong *)*plVar5 != plVar11)) goto LAB_14001c1f3;
    *plVar5 = lVar9;
    *(longlong **)(lVar9 + 8) = plVar5;
    plVar5 = *(longlong **)(lVar4 + 0xf0);
    if ((longlong *)*plVar5 != plVar1) goto LAB_14001c1f3;
    *plVar11 = (longlong)plVar1;
    plVar11[1] = (longlong)plVar5;
    *plVar5 = (longlong)plVar11;
    *(longlong **)(lVar4 + 0xf0) = plVar11;
    plVar11[0xf] = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x80);
    uVar2 = *(undefined4 *)(*(longlong *)(param_1 + 0x28) + 0x98);
    *(undefined4 *)(plVar11 + 0xb) = uVar2;
    *(undefined4 *)((longlong)plVar11 + 0x5c) =
         *(undefined4 *)(*(longlong *)(param_1 + 0x28) + 0x98);
    if ((int)plVar11[9] == 0) {
      *(undefined4 *)(plVar11 + 0xc) = uVar2;
      *(undefined4 *)(*(longlong *)(param_1 + 0x28) + 0xa8) = uVar2;
    }
    else {
      *(undefined4 *)(plVar11 + 0xc) = *(undefined4 *)(*(longlong *)(param_1 + 0x28) + 0xa8);
    }
  }
  if (*(int *)((longlong)plVar11 + 0x8c) == 0) {
    if (((int)plVar11[0x10] == 0) &&
       (plVar11[6] = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x128),
       *(char *)(param_1 + 0xa1) != '\0')) {
      *(int *)(lVar4 + 0x9c) = *(int *)(lVar4 + 0x98) + -1;
    }
    uVar10 = GetNextPacketOptionsAndData
                       (param_1,(longlong)plVar11,(longlong *)&local_90,param_2,local_98);
    if ((int)uVar10 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
        return 0;
      }
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x44,
               &WPP_2d619c39f4c936783a7b398058864277_Traceguids,(int)uVar10);
      return 0;
    }
    *(int *)(plVar11 + 0x10) = (int)plVar11[0x10] + 1;
  }
  else {
    local_98[0] = *(ushort *)(lVar4 + 0x6c);
    _Dst = (void *)ExAllocateFromNPagedLookasideList(lVar4 + 0x1c0);
    if (_Dst == (void *)0x0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,
                &WPP_2d619c39f4c936783a7b398058864277_Traceguids);
      }
      return 0xc000009a;
    }
    memset(_Dst,0,(ulonglong)*(uint *)(lVar4 + 0x6c));
    local_90 = (ulonglong *)((longlong)_Dst + 0x20);
    KeReleaseSpinLock(param_1 + 0x168,*param_2);
    lVar9 = PsGetCurrentProcess();
    bVar12 = lVar9 != PgmStaticConfig;
    if (bVar12) {
      KeStackAttachProcess(PgmStaticConfig,&local_78);
    }
    local_98[0] = local_98[0] - 0x20;
    uVar10 = PgmBuildParityPacket
                       (param_1,*(longlong *)(lVar4 + 0x110),*(byte **)(lVar4 + 0x1a8),
                        (ushort *)local_90,local_98,4);
    if (bVar12) {
      KeUnstackDetachProcess(&local_78);
    }
    uVar7 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x168);
    *local_88 = uVar7;
    if ((int)uVar10 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x43,
                 &WPP_2d619c39f4c936783a7b398058864277_Traceguids,(int)uVar10);
      }
      ExFreeToNPagedLookasideList(lVar4 + 0x1c0,_Dst);
      return 0;
    }
    *(int *)((longlong)plVar11 + 0x8c) = *(int *)((longlong)plVar11 + 0x8c) + -1;
    param_2 = local_88;
  }
  if ((((int)plVar11[0x10] != *(int *)((longlong)plVar11 + 0x6c)) ||
      (*(int *)((longlong)plVar11 + 0x8c) != 0)) || ((int)plVar11[0xd] != 0)) {
LAB_14001c0ca:
    *(int *)(plVar11 + 0x11) = (int)plVar11[0x11] + 1;
    KeReleaseSpinLock(param_1 + 0x168,*param_2);
    uVar3 = *(uint *)(lVar4 + 0xa4);
    *(uint *)((longlong)local_90 + 0x14) =
         uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    *(undefined2 *)((longlong)local_90 + 6) = 0;
    iVar8 = tcpxsum(0,local_90,(uint)local_98[0]);
    *(ushort *)((longlong)local_90 + 6) = ~(ushort)iVar8;
    uVar10 = TdiSendDatagram(*(undefined8 *)(*(longlong *)(lVar4 + 0x20) + 0x48),
                             *(undefined8 *)(*(longlong *)(lVar4 + 0x20) + 0x50),local_90,
                             (uint)local_98[0],PgmSendODataCompletion,plVar11,_Dst,
                             *(uint *)(lVar4 + 0x28),*(ushort *)(lVar4 + 0x30),_Dst == (void *)0x0);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      WPP_SF_dddDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)*(uint *)(lVar4 + 0x28),
                   (ulonglong)local_98[0],*(undefined4 *)(lVar4 + 0xa4),
                   (char)*(undefined4 *)(lVar4 + 0x9c),(char)local_98[0],
                   (char)*(uint *)(lVar4 + 0x28),(char)*(undefined2 *)(lVar4 + 0x30));
    }
    uVar7 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x168);
    *param_2 = uVar7;
    plVar1 = (longlong *)(*(longlong *)(param_1 + 0x28) + 0x378);
    *plVar1 = *plVar1 + 1;
    plVar1 = (longlong *)(*(longlong *)(param_1 + 0x28) + 0x348);
    *plVar1 = *plVar1 + 1;
    *local_80 = (uint)local_98[0];
    return uVar10 & 0xffffffff;
  }
  lVar9 = *plVar11;
  if ((*(longlong **)(lVar9 + 8) == plVar11) &&
     (plVar1 = (longlong *)plVar11[1], (longlong *)*plVar1 == plVar11)) {
    *plVar1 = lVar9;
    *(longlong **)(lVar9 + 8) = plVar1;
    plVar1 = *(longlong **)(lVar4 + 0xe0);
    if (*plVar1 == lVar4 + 0xd8) {
      *plVar11 = lVar4 + 0xd8;
      plVar11[1] = (longlong)plVar1;
      *plVar1 = (longlong)plVar11;
      *(longlong **)(lVar4 + 0xe0) = plVar11;
      *(int *)(lVar4 + 0x90) = *(int *)(lVar4 + 0x90) + -1;
      if ((*(uint *)((longlong)plVar11 + 0x3c) & 0x40) != 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,
                  &WPP_2d619c39f4c936783a7b398058864277_Traceguids);
        }
        *(uint *)(lVar4 + 0xc4) = *(uint *)(lVar4 + 0xc4) | 0x40;
        *(undefined8 *)(lVar4 + 0x170) = *(undefined8 *)(lVar4 + 0x178);
        *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 4;
      }
      goto LAB_14001c0ca;
    }
  }
LAB_14001c1f3:
  pcVar6 = (code *)swi(0x29);
  (*pcVar6)(3);
  pcVar6 = (code *)swi(3);
  uVar10 = (*pcVar6)();
  return uVar10;
}



===== PgmSendODataCompletion @ 14001c200 =====

void PgmSendODataCompletion(longlong param_1,ulonglong param_2,undefined *param_3,longlong *param_4)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  longlong *plVar4;
  undefined1 uVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined *puVar8;
  uint uVar9;
  ulonglong uVar10;
  longlong *plVar11;
  
  plVar4 = *(longlong **)(param_1 + 0x28);
  uVar10 = (ulonglong)param_3 & 0xffffffff;
  uVar9 = 0;
  plVar11 = (longlong *)0x0;
  lVar7 = 0;
  uVar6 = param_2;
  puVar8 = param_3;
  uVar5 = KeAcquireSpinLockRaiseToDpc(plVar4 + 0x2d);
  if ((int)param_3 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      puVar8 = &WPP_2d619c39f4c936783a7b398058864277_Traceguids;
      uVar6 = 0;
      param_4 = (longlong *)((ulonglong)param_3 & 0xffffffff);
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,
               &WPP_2d619c39f4c936783a7b398058864277_Traceguids,(int)param_3);
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar6 = (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
       (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      uVar6 = 0;
      puVar8 = &WPP_2d619c39f4c936783a7b398058864277_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,
              &WPP_2d619c39f4c936783a7b398058864277_Traceguids);
    }
    if (param_2 == 0) {
      *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + 1;
    }
  }
  piVar1 = (int *)(param_1 + 0x88);
  *piVar1 = *piVar1 + -1;
  if (((*piVar1 == 0) && (*(int *)(param_1 + 0x8c) == 0)) && (*(int *)(param_1 + 0x68) == 0)) {
    uVar2 = *(uint *)(param_1 + 0x6c);
    uVar6 = (ulonglong)uVar2;
    if (*(uint *)(param_1 + 0x80) == uVar2) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
        param_4 = (longlong *)(ulonglong)*(uint *)(param_1 + 0x10);
        WPP_SF_dqddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,puVar8,
                     *(uint *)(param_1 + 0x10),(char)*(undefined8 *)(param_1 + 0x18),(char)uVar2,
                     (char)*(undefined4 *)(param_1 + 0x58),(char)*(undefined4 *)(param_1 + 0x5c));
      }
      plVar4[0x17] = plVar4[0x17] + (ulonglong)*(uint *)(param_1 + 100);
      plVar11 = *(longlong **)(param_1 + 0x18);
      if (plVar11 != (longlong *)0x0) {
        uVar2 = *(uint *)(param_1 + 0x84);
        puVar8 = (undefined *)(ulonglong)uVar2;
        uVar3 = *(uint *)(param_1 + 0x80);
        param_4 = (longlong *)(ulonglong)uVar3;
        if (uVar2 == uVar3) {
          uVar9 = *(uint *)(param_1 + 100);
          uVar10 = 0;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
            uVar6 = 0;
            param_4 = plVar11;
            WPP_SF_qqqdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,puVar8,plVar11,
                         (char)*(undefined8 *)(param_1 + 0x20),(char)param_1,(char)uVar2,(char)uVar3
                        );
          }
        }
        else {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
            uVar6 = 0;
            param_4 = plVar11;
            WPP_SF_qqqdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,puVar8,plVar11,
                         (char)*(undefined8 *)(param_1 + 0x20),(char)param_1,(char)uVar2,(char)uVar3
                        );
          }
          uVar10 = 0xc0000001;
        }
        *(undefined8 *)(param_1 + 0x18) = 0;
        lVar7 = *(longlong *)(param_1 + 0x20);
      }
      if (*(longlong *)(param_1 + 0x50) != 0) {
        if (lVar7 != 0) {
          *(undefined8 *)(*(longlong *)(param_1 + 0x50) + 0x20) = *(undefined8 *)(param_1 + 0x20);
          *(undefined8 *)(param_1 + 0x20) = 0;
          lVar7 = 0;
        }
        *(undefined8 *)(*(longlong *)(param_1 + 0x50) + 0x50) = 0;
        *(undefined8 *)(param_1 + 0x50) = 0;
      }
    }
  }
  uVar6 = CONCAT71((int7)(uVar6 >> 8),uVar5);
  KeReleaseSpinLock(plVar4 + 0x2d);
  if (param_2 != 0) {
    ExFreeToNPagedLookasideList(plVar4[5] + 0x1c0);
    uVar6 = param_2;
  }
  if (plVar11 != (longlong *)0x0) {
    if (lVar7 != 0) {
      puVar8 = (undefined *)(ulonglong)uVar9;
      PgmIoComplete(lVar7,uVar10,(ulonglong)puVar8);
      uVar6 = uVar10;
    }
    PgmDereferenceSessionCommon(plVar4,uVar6,puVar8,param_4);
  }
  return;
}



===== PgmSendRData @ 14001c48c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PgmSendRData(longlong param_1,longlong *param_2,undefined1 *param_3,uint *param_4)

{
  longlong lVar1;
  undefined1 auVar2 [16];
  ushort *puVar3;
  bool bVar4;
  byte bVar5;
  undefined1 uVar6;
  char cVar7;
  int iVar8;
  ulonglong *_Dst;
  ulonglong uVar9;
  longlong lVar10;
  byte bVar11;
  undefined2 uVar12;
  ulonglong uVar13;
  ushort *puVar14;
  uint uVar15;
  ulonglong uVar16;
  ushort uVar17;
  ulonglong uVar18;
  short sVar19;
  uint uVar20;
  bool bVar21;
  undefined1 auStackY_f8 [32];
  byte local_a7 [3];
  uint local_a4;
  ushort local_a0 [2];
  ushort local_9c;
  uint local_98;
  ushort *local_90;
  undefined1 *local_88;
  ulonglong *local_80;
  uint *local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_f8;
  lVar1 = *(longlong *)(param_1 + 0x28);
  local_a7[0] = 0;
  *param_4 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_88 = param_3;
  local_78 = param_4;
  _Dst = (ulonglong *)ExAllocateFromNPagedLookasideList(lVar1 + 0x1c0);
  local_80 = _Dst;
  if (_Dst == (ulonglong *)0x0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000009a;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return 0xc000009a;
    }
    uVar12 = 0x28;
    goto LAB_14001c534;
  }
  uVar15 = *(uint *)(param_2 + 2);
  local_a0[0] = *(short *)(lVar1 + 0x70) + 0x44;
  local_98 = 1;
  local_a4 = uVar15;
  local_9c = local_a0[0];
  if (*(char *)(param_1 + 0xa1) == '\0') {
    sVar19 = 1;
    *(undefined1 *)(param_2 + 8) = 0;
    bVar4 = false;
    param_2[5] = *(longlong *)(lVar1 + 0x128) + param_2[4];
    *(int *)(lVar1 + 0x94) = *(int *)(lVar1 + 0x94) + -1;
    lVar10 = param_2[4];
LAB_14001c603:
    if (lVar10 == 0) {
      RemoveEntry(*(longlong *)(lVar1 + 0x108),param_2);
    }
  }
  else {
    if (*(short *)((longlong)param_2 + 0x3a) == 0) {
      sVar19 = 1;
      cVar7 = GetNextNakIndex((longlong)param_2,(char *)local_a7);
      if (cVar7 != '\0') {
        local_a4 = uVar15 + local_a7[0];
      }
    }
    else {
      sVar19 = 2;
      *(short *)((longlong)param_2 + 0x3a) = *(short *)((longlong)param_2 + 0x3a) + -1;
    }
    bVar4 = AnyMoreNaks((longlong)param_2);
    if (!bVar4) {
      param_2[5] = *(longlong *)(lVar1 + 0x128) + param_2[4];
      *(int *)(lVar1 + 0x94) = *(int *)(lVar1 + 0x94) + -1;
      lVar10 = param_2[4];
      goto LAB_14001c603;
    }
  }
  uVar9 = Feature_3666842937__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar9 == 0) {
    uVar13 = (ulonglong)((local_a4 - *(int *)(lVar1 + 0xa0)) * *(int *)(lVar1 + 0x6c)) +
             *(longlong *)(lVar1 + 0x88);
    if (*(ulonglong *)(lVar1 + 0x58) <= uVar13) {
      uVar13 = uVar13 - *(ulonglong *)(lVar1 + 0x58);
    }
  }
  else {
    uVar15 = local_a4 - *(int *)(lVar1 + 0xa0);
    if ((int)uVar15 < 0) {
      ExFreeToNPagedLookasideList(lVar1 + 0x1c0,_Dst);
      if ((bVar4 == false) && (param_2[4] == 0)) {
        DestroyEntry(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x108),(longlong)param_2);
      }
      else {
        if (sVar19 == 2) {
          *(short *)((longlong)param_2 + 0x3a) = *(short *)((longlong)param_2 + 0x3a) + 1;
        }
        *(int *)(lVar1 + 0x94) = *(int *)(lVar1 + 0x94) + 1;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc000009a;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
        return 0xc000009a;
      }
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
                &WPP_2d619c39f4c936783a7b398058864277_Traceguids,local_a4,
                (char)*(undefined4 *)(lVar1 + 0xa0));
      return 0xc000009a;
    }
    uVar18 = CONCAT44(0,*(uint *)(lVar1 + 0x6c));
    auVar2._8_8_ = 0;
    auVar2._0_8_ = uVar18;
    auVar2 = auVar2 * ZEXT416(uVar15);
    uVar9 = auVar2._0_8_;
    local_90 = (ushort *)0x0;
    if (auVar2._8_8_ != 0) {
      ExFreeToNPagedLookasideList(lVar1 + 0x1c0,_Dst);
      if ((bVar4 == false) && (param_2[4] == 0)) {
        DestroyEntry(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x108),(longlong)param_2);
      }
      else {
        if (sVar19 == 2) {
          *(short *)((longlong)param_2 + 0x3a) = *(short *)((longlong)param_2 + 0x3a) + 1;
        }
        *(int *)(lVar1 + 0x94) = *(int *)(lVar1 + 0x94) + 1;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc000009a;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
        return 0xc000009a;
      }
      uVar12 = 0x2a;
LAB_14001cd97:
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar12,
               &WPP_2d619c39f4c936783a7b398058864277_Traceguids,0xc0000095);
      return 0xc000009a;
    }
    uVar16 = *(longlong *)(lVar1 + 0x88) + uVar9;
    if (uVar16 < uVar9) {
      ExFreeToNPagedLookasideList(lVar1 + 0x1c0,_Dst);
      if ((bVar4 == false) && (param_2[4] == 0)) {
        DestroyEntry(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x108),(longlong)param_2);
      }
      else {
        if (sVar19 == 2) {
          *(short *)((longlong)param_2 + 0x3a) = *(short *)((longlong)param_2 + 0x3a) + 1;
        }
        *(int *)(lVar1 + 0x94) = *(int *)(lVar1 + 0x94) + 1;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc000009a;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
        return 0xc000009a;
      }
      uVar12 = 0x2b;
      goto LAB_14001cd97;
    }
    uVar9 = *(ulonglong *)(lVar1 + 0x58);
    uVar13 = uVar16 - uVar9;
    if (uVar16 < uVar9) {
      uVar13 = uVar16;
    }
    if (uVar9 < uVar13 + uVar18) {
      ExFreeToNPagedLookasideList(lVar1 + 0x1c0,_Dst);
      if ((bVar4 == false) && (param_2[4] == 0)) {
        DestroyEntry(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x108),(longlong)param_2);
      }
      else {
        if (sVar19 == 2) {
          *(short *)((longlong)param_2 + 0x3a) = *(short *)((longlong)param_2 + 0x3a) + 1;
        }
        *(int *)(lVar1 + 0x94) = *(int *)(lVar1 + 0x94) + 1;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc000009a;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
        return 0xc000009a;
      }
      uVar12 = 0x2c;
LAB_14001c534:
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar12,
              &WPP_2d619c39f4c936783a7b398058864277_Traceguids);
      return 0xc000009a;
    }
  }
  local_90 = (ushort *)(*(longlong *)(lVar1 + 0x50) + uVar13);
  *(short *)(param_2 + 7) = (short)param_2[7] + 1;
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  KeReleaseSpinLock(param_1 + 0x168);
  lVar10 = PsGetCurrentProcess();
  bVar21 = lVar10 != PgmStaticConfig;
  if (bVar21) {
    KeStackAttachProcess();
  }
  puVar3 = local_90;
  if (sVar19 != 1) {
    if (sVar19 != 2) {
      uVar17 = local_9c;
      goto LAB_14001cb9b;
    }
    bVar5 = *(byte *)((longlong)param_2 + 0x61);
    if (*(byte *)((longlong)param_2 + 0x61) == 0) {
      *(undefined4 *)((longlong)param_2 + 100) = 0;
      *(undefined1 *)((longlong)param_2 + 0x61) = 0;
      uVar17 = 0;
      uVar15 = 0;
      bVar5 = 0;
      bVar11 = 0;
      puVar14 = local_90;
      if (*(char *)(param_1 + 0xa0) != '\0') {
        do {
          param_2[(ulonglong)uVar17 + 0xd] = (ulonglong)puVar14[1] + 0x38 + (longlong)puVar14;
          uVar15 = *(uint *)(puVar14 + 2) & 0x861 | *(uint *)((longlong)param_2 + 100);
          *(uint *)((longlong)param_2 + 100) = uVar15;
          if ((*(uint *)(puVar14 + 2) & 0x800) != 0) {
            *(undefined1 *)((longlong)param_2 + 0x61) = *(undefined1 *)((longlong)puVar14 + 0x1d);
          }
          uVar17 = uVar17 + 1;
          bVar11 = *(byte *)(param_1 + 0xa0);
          puVar14 = (ushort *)((longlong)puVar14 + (ulonglong)*(uint *)(lVar1 + 0x6c));
        } while (uVar17 < bVar11);
        bVar5 = *(byte *)((longlong)param_2 + 0x61);
      }
      if ((uVar15 >> 0xb & 1) == 0) {
        *(byte *)((longlong)param_2 + 0x61) = bVar11;
        bVar5 = bVar11;
      }
    }
    if (bVar5 != 1) {
      memset(_Dst,0,(ulonglong)local_9c);
      uVar9 = PgmBuildParityPacket
                        (param_1,(longlong)puVar3,(byte *)(param_2 + 0xc),(ushort *)_Dst,local_a0,5)
      ;
      if ((int)uVar9 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
                   &WPP_2d619c39f4c936783a7b398058864277_Traceguids,(int)uVar9);
        }
        if (bVar21) {
          KeUnstackDetachProcess(&local_70);
        }
        uVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x168);
        *local_88 = uVar6;
        ExFreeToNPagedLookasideList(lVar1 + 0x1c0,_Dst);
        if ((bVar4 == false) && (param_2[4] == 0)) {
          DestroyEntry(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x108),(longlong)param_2);
        }
        else {
          *(short *)(param_2 + 7) = (short)param_2[7] + -1;
          *(short *)((longlong)param_2 + 0x3a) = *(short *)((longlong)param_2 + 0x3a) + 1;
          *(int *)(lVar1 + 0x94) = *(int *)(lVar1 + 0x94) + 1;
        }
        return uVar9 & 0xffffffff;
      }
      uVar17 = local_a0[0];
      goto LAB_14001cb9b;
    }
    if (bVar4 != false) {
      uVar15 = *(ushort *)((longlong)param_2 + 0x3a) + 1;
      *(undefined2 *)((longlong)param_2 + 0x3a) = 0;
      local_98 = uVar15;
      cVar7 = GetNextNakIndex((longlong)param_2,(char *)local_a7);
      if (cVar7 != '\0') {
        do {
          uVar15 = uVar15 + 1;
          cVar7 = GetNextNakIndex((longlong)param_2,(char *)local_a7);
        } while (cVar7 != '\0');
        _Dst = local_80;
        local_98 = uVar15;
      }
      bVar4 = false;
      param_2[5] = *(longlong *)(lVar1 + 0x128) + param_2[4];
      *(int *)(lVar1 + 0x94) = *(int *)(lVar1 + 0x94) + -1;
      if (param_2[4] == 0) {
        RemoveEntry(*(longlong *)(lVar1 + 0x108),param_2);
      }
    }
  }
  puVar3 = local_90;
  uVar9 = Feature_3666842937__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar9 == 0) {
LAB_14001ca9a:
    uVar17 = *puVar3;
    uVar9 = Feature_3666842937__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar9 == 0) || (uVar15 = *(uint *)(lVar1 + 0x6c), uVar17 + 0x20 <= uVar15)) {
      memmove(_Dst,local_90 + 0x10,(ulonglong)uVar17);
LAB_14001cb9b:
      if (bVar21) {
        KeUnstackDetachProcess();
      }
      uVar15 = *(uint *)(lVar1 + 0xa4);
      *(uint *)((longlong)_Dst + 0x14) =
           uVar15 >> 0x18 | (uVar15 & 0xff0000) >> 8 | (uVar15 & 0xff00) << 8 | uVar15 << 0x18;
      *(undefined1 *)((longlong)_Dst + 4) = 5;
      *(undefined2 *)((longlong)_Dst + 6) = 0;
      iVar8 = tcpxsum(0,_Dst,(uint)uVar17);
      *(ushort *)((longlong)_Dst + 6) = ~(ushort)iVar8;
      uVar9 = TdiSendDatagram(*(undefined8 *)(*(longlong *)(lVar1 + 0x20) + 0x60),
                              *(undefined8 *)(*(longlong *)(lVar1 + 0x20) + 0x68),_Dst,(uint)uVar17,
                              PgmSendRDataCompletion,param_2,_Dst,*(uint *)(lVar1 + 0x28),
                              *(ushort *)(lVar1 + 0x30),'\0');
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
        WPP_SF_ddDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)*(uint *)(lVar1 + 0x28),
                    _Dst,local_a4,(char)uVar17,(char)*(uint *)(lVar1 + 0x28),
                    (char)*(undefined2 *)(lVar1 + 0x30));
      }
      uVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x168);
      *local_88 = uVar6;
      *(longlong *)(lVar1 + 0x368) = *(longlong *)(lVar1 + 0x368) - (ulonglong)local_98;
      *(longlong *)(lVar1 + 0x380) = *(longlong *)(lVar1 + 0x380) + 1;
      *(longlong *)(lVar1 + 0x350) = *(longlong *)(lVar1 + 0x350) + 1;
      *local_78 = (uint)uVar17;
      return uVar9 & 0xffffffff;
    }
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) goto LAB_14001caf8;
    uVar20 = (uint)uVar17;
    uVar12 = 0x2f;
  }
  else {
    uVar15 = *(uint *)(puVar3 + 0x18);
    uVar15 = uVar15 >> 0x18 | (uVar15 & 0xff0000) >> 8 | (uVar15 & 0xff00) << 8 | uVar15 << 0x18;
    if (local_a4 == uVar15) goto LAB_14001ca9a;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) goto LAB_14001caf8;
    uVar12 = 0x2e;
    uVar20 = local_a4;
  }
  WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar12,
            &WPP_2d619c39f4c936783a7b398058864277_Traceguids,uVar20,(char)uVar15);
LAB_14001caf8:
  if (bVar21) {
    KeUnstackDetachProcess(&local_70);
  }
  uVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x168);
  *local_88 = uVar6;
  ExFreeToNPagedLookasideList(lVar1 + 0x1c0,_Dst);
  if ((bVar4 == false) && (param_2[4] == 0)) {
    DestroyEntry(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x108),(longlong)param_2);
  }
  else {
    *(short *)(param_2 + 7) = (short)param_2[7] + -1;
    *(int *)(lVar1 + 0x94) = *(int *)(lVar1 + 0x94) + 1;
  }
  return 0xc0000001;
}



===== PgmSendRDataCompletion @ 14001cde0 =====

void PgmSendRDataCompletion(longlong param_1,longlong param_2,undefined *param_3,longlong *param_4)

{
  short *psVar1;
  longlong *plVar2;
  undefined1 uVar3;
  bool bVar4;
  longlong lVar5;
  int iVar6;
  undefined *puVar7;
  
  plVar2 = *(longlong **)(param_1 + 0x30);
  iVar6 = (int)param_3;
  lVar5 = param_2;
  puVar7 = param_3;
  if (((iVar6 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    param_4 = (longlong *)((ulonglong)param_3 & 0xffffffff);
    puVar7 = &WPP_2d619c39f4c936783a7b398058864277_Traceguids;
    lVar5 = 0;
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
             &WPP_2d619c39f4c936783a7b398058864277_Traceguids,iVar6);
  }
  uVar3 = KeAcquireSpinLockRaiseToDpc(plVar2 + 0x2d);
  psVar1 = (short *)(param_1 + 0x38);
  *psVar1 = *psVar1 + -1;
  if (*psVar1 == 0) {
    bVar4 = AnyMoreNaks(param_1);
    if (!bVar4) {
      if (*(longlong *)(param_1 + 0x20) == 0) {
        DestroyEntry(*(longlong *)(plVar2[5] + 0x108),param_1);
        lVar5 = param_1;
      }
      else {
        if (*(longlong *)(param_1 + 0x28) == 0) {
          *(int *)(plVar2[5] + 0x94) = *(int *)(plVar2[5] + 0x94) + -1;
        }
        *(longlong *)(param_1 + 0x28) =
             *(longlong *)(plVar2[5] + 0x128) + *(longlong *)(param_1 + 0x20);
      }
    }
  }
  lVar5 = CONCAT71((int7)((ulonglong)lVar5 >> 8),uVar3);
  KeReleaseSpinLock(plVar2 + 0x2d);
  if (param_2 != 0) {
    lVar5 = param_2;
    ExFreeToNPagedLookasideList(plVar2[5] + 0x1c0);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
    puVar7 = &WPP_2d619c39f4c936783a7b398058864277_Traceguids;
    lVar5 = 0x22;
    param_4 = (longlong *)((ulonglong)param_3 & 0xffffffff);
    WPP_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
              &WPP_2d619c39f4c936783a7b398058864277_Traceguids,iVar6,(char)param_2);
  }
  PgmDereferenceSessionCommon(plVar2,lVar5,puVar7,param_4);
  return;
}



===== PgmSendRequestFromClient @ 14001cf40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong PgmSendRequestFromClient(undefined8 param_1,longlong *param_2,longlong param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined1 uVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  undefined8 uVar11;
  undefined2 uVar12;
  code *pcVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  longlong lVar16;
  undefined8 uVar17;
  longlong *plVar18;
  ulonglong uVar19;
  bool bVar20;
  undefined1 auStackY_d8 [8];
  undefined1 auStackY_d0 [24];
  undefined1 local_98;
  undefined1 local_97;
  undefined1 local_96;
  undefined1 local_95;
  char local_94;
  undefined8 local_90;
  uint local_88;
  longlong local_80;
  longlong *local_78;
  longlong local_70;
  longlong local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_d8;
  uVar19 = 0;
  plVar1 = *(longlong **)(*(longlong *)(param_3 + 0x30) + 0x18);
  lVar16 = 0;
  local_60 = 0;
  uStack_58 = 0;
  plVar9 = (longlong *)0x0;
  local_88 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_80 = param_3;
  local_78 = param_2;
  uVar4 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
  puVar14 = auStackY_d8;
  puVar15 = auStackY_d8;
  if (((plVar1 != (longlong *)0x0) && (puVar15 = auStackY_d8, (int)plVar1[2] == 0x53534553)) &&
     (lVar16 = plVar1[3], puVar15 = auStackY_d8, local_68 = lVar16, lVar16 != 0)) {
    lVar2 = plVar1[5];
    if (((*(longlong *)(lVar2 + 0x130) == 0) || (*(int *)(lVar16 + 0x10) != 0x52444441)) ||
       ((*(uint *)(plVar1 + 4) & 0x6000) != 0)) {
      puVar15 = auStackY_d8;
    }
    else {
      if ((*(uint *)(lVar16 + 0x38) & 1) == 0) {
        if (*(int *)(lVar2 + 0x28) == 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
            WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6d,
                     &WPP_2d619c39f4c936783a7b398058864277_Traceguids,plVar1);
          }
          uVar19 = 0xc0000207;
        }
        else if (*(int *)(param_3 + 8) == 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
            WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6e,
                      &WPP_2d619c39f4c936783a7b398058864277_Traceguids,param_2,(char)plVar1);
          }
        }
        else {
          local_70 = lVar16 + 0x1b8;
          local_97 = KeAcquireSpinLockRaiseToDpc(local_70);
          local_90 = plVar1 + 0x2d;
          local_96 = KeAcquireSpinLockRaiseToDpc(local_90);
          plVar8 = (longlong *)ExAllocateFromNPagedLookasideList(lVar2 + 0x240);
          if (plVar8 != (longlong *)0x0) {
            if (((*(int *)(lVar2 + 0xd0) != 0) &&
                (local_88 = *(int *)(lVar2 + 0xd0) - *(int *)(lVar2 + 0xd4), local_88 != 0)) &&
               (local_88 < *(uint *)(param_3 + 8))) {
              plVar9 = (longlong *)ExAllocateFromNPagedLookasideList(lVar2 + 0x240);
              if (plVar9 == (longlong *)0x0) {
                ExFreeToNPagedLookasideList(lVar2 + 0x240,plVar8);
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
                  uVar12 = 0x70;
                  goto LAB_14001d1a7;
                }
                goto LAB_14001d1b7;
              }
            }
            memset(plVar8 + 2,0,0x90);
            plVar8[1] = (longlong)plVar8;
            *plVar8 = (longlong)plVar8;
            if (plVar9 != (longlong *)0x0) {
              memset(plVar9 + 2,0,0x90);
              plVar9[1] = (longlong)plVar9;
              *plVar9 = (longlong)plVar9;
            }
            *(int *)((longlong)plVar1 + 0x14) = *(int *)((longlong)plVar1 + 0x14) + 1;
            local_90 = (longlong *)(CONCAT44(local_90._4_4_,(int)plVar1[4]) & 0xffffffff00000008);
            KeReleaseSpinLock(plVar1 + 0x2d,local_96);
            KeReleaseSpinLock(lVar16 + 0x1b8,local_97);
            KeReleaseSpinLock(&DAT_140036808);
            cVar5 = KeGetCurrentIrql();
            if (cVar5 == '\0') {
              local_94 = '\x01';
              KeEnterCriticalRegion();
              ExAcquireResourceExclusiveLite(lVar2 + 0x2e0);
            }
            else {
              local_94 = '\0';
            }
            if ((int)local_90 == 0) {
              local_95 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
              IoAcquireCancelSpinLock(&local_97);
              local_98 = KeAcquireSpinLockRaiseToDpc(lVar16 + 0x1b8);
              local_96 = KeAcquireSpinLockRaiseToDpc(plVar1 + 0x2d);
            }
            else {
              lVar10 = PsGetCurrentProcess();
              bVar20 = lVar10 != PgmStaticConfig;
              if (bVar20) {
                KeStackAttachProcess(PgmStaticConfig,&local_60);
              }
              plVar18 = (longlong *)0x0;
              uVar11 = 0;
              iVar6 = PsCreateSystemThread(lVar2 + 0x2d8,0x1fffff);
              local_90 = (longlong *)CONCAT44(local_90._4_4_,iVar6);
              if (iVar6 < 0) {
                if (bVar20) {
                  KeUnstackDetachProcess(&local_60);
                }
                if (local_94 != '\0') {
                  ExReleaseResourceLite(lVar2 + 0x2e0);
                  KeLeaveCriticalRegion();
                }
                ExFreeToNPagedLookasideList(lVar2 + 0x240);
                if (plVar9 != (longlong *)0x0) {
                  ExFreeToNPagedLookasideList(lVar2 + 0x240);
                  plVar8 = plVar9;
                }
                PgmDereferenceSessionCommon(plVar1,plVar8,uVar11,plVar18);
                plVar1 = local_90;
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
                  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x71,
                           &WPP_2d619c39f4c936783a7b398058864277_Traceguids,(int)local_90);
                }
                puVar15 = auStackY_d8;
                uVar19 = (ulonglong)plVar1 & 0xffffffff;
                goto LAB_14001da56;
              }
              ZwClose(*(undefined8 *)(lVar2 + 0x2d8));
              if (bVar20) {
                KeUnstackDetachProcess(&local_60);
              }
              local_95 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
              IoAcquireCancelSpinLock(&local_97);
              local_98 = KeAcquireSpinLockRaiseToDpc(lVar16 + 0x1b8);
              local_96 = KeAcquireSpinLockRaiseToDpc(plVar1 + 0x2d);
              *(uint *)(plVar1 + 4) = *(uint *)(plVar1 + 4) & 0xfffffff7;
              *(undefined4 *)(lVar2 + 0x9c) = 0xffffffff;
              *(longlong *)(lVar2 + 0x20) = lVar16;
              *(uint *)((longlong)plVar8 + 0x3c) = *(uint *)((longlong)plVar8 + 0x3c) | 0x20;
              *(int *)(plVar8 + 8) = (int)plVar8[8] + 4;
              *(int *)((longlong)plVar1 + 0x14) = *(int *)((longlong)plVar1 + 0x14) + 1;
              *(int *)(lVar16 + 0x14) = *(int *)(lVar16 + 0x14) + 1;
              *(undefined8 *)(lVar2 + 0x118) = _DAT_fffff78000000008;
              *(undefined8 *)(lVar2 + 0x120) = 200000;
              *(undefined8 *)(lVar2 + 0x128) = 1;
              KeInitializeTimer(plVar1 + 0x1d);
              KeInitializeDpc(plVar1 + 0x25,SendSessionTimeout,plVar1);
              KeSetTimer(plVar1 + 0x1d,0xfffffffffffcf2c0,plVar1 + 0x25);
              lVar16 = local_68;
            }
            plVar8[3] = (longlong)local_78;
            plVar8[4] = (longlong)local_78;
            plVar8[5] = (longlong)plVar1;
            *(undefined4 *)(plVar8 + 7) = 0;
            *(undefined4 *)(plVar8 + 2) = *(undefined4 *)(lVar2 + 0x68);
            *(int *)(lVar2 + 0x68) = *(int *)(lVar2 + 0x68) + 1;
            *(undefined4 *)((longlong)plVar8 + 0x74) = *(undefined4 *)(lVar2 + 0x70);
            *(uint *)((longlong)plVar8 + 0x3c) =
                 *(uint *)((longlong)plVar8 + 0x3c) | *(uint *)(lVar2 + 200);
            *(int *)(plVar8 + 8) = (int)plVar8[8] + *(int *)(lVar2 + 0xcc);
            plVar8[0x12] = -1;
            if (*(int *)(lVar2 + 0xd0) == 0) {
              *(undefined4 *)((longlong)plVar8 + 0x44) = *(undefined4 *)(local_80 + 8);
              *(undefined4 *)((longlong)plVar8 + 100) = *(undefined4 *)(local_80 + 8);
            }
            else {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
                WPP_SF_dddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x72,
                            &WPP_2d619c39f4c936783a7b398058864277_Traceguids,(int)plVar8[2],
                            (char)*(int *)(lVar2 + 0xd0),(char)*(undefined4 *)(lVar2 + 0xd4),
                            (char)*(undefined4 *)(local_80 + 8));
              }
              *(undefined4 *)((longlong)plVar8 + 0x44) = *(undefined4 *)(lVar2 + 0xd0);
              *(undefined4 *)(plVar8 + 9) = *(undefined4 *)(lVar2 + 0xd4);
              if (plVar9 == (longlong *)0x0) {
                *(undefined4 *)((longlong)plVar8 + 100) = *(undefined4 *)(local_80 + 8);
              }
              else {
                *(uint *)((longlong)plVar8 + 100) = local_88;
                plVar8[4] = 0;
                plVar9[5] = (longlong)plVar1;
                plVar9[3] = (longlong)local_78;
                plVar9[4] = (longlong)local_78;
                *(undefined4 *)(plVar9 + 2) = *(undefined4 *)(lVar2 + 0x68);
                *(int *)(lVar2 + 0x68) = *(int *)(lVar2 + 0x68) + 1;
                *(undefined4 *)((longlong)plVar9 + 0x74) = *(undefined4 *)(lVar2 + 0x70);
                *(uint *)((longlong)plVar9 + 0x3c) =
                     *(uint *)((longlong)plVar9 + 0x3c) | *(uint *)(lVar2 + 200);
                *(int *)(plVar9 + 8) = (int)plVar9[8] + *(int *)(lVar2 + 0xcc);
                plVar9[0x12] = -1;
                iVar6 = *(int *)(local_80 + 8) - local_88;
                *(uint *)(plVar9 + 7) = local_88;
                *(int *)((longlong)plVar9 + 0x44) = iVar6;
                *(int *)((longlong)plVar9 + 100) = iVar6;
              }
              *(int *)(lVar2 + 0xd4) = *(int *)(lVar2 + 0xd4) + *(int *)((longlong)plVar8 + 100);
              if (*(int *)(lVar2 + 0xd4) == *(int *)(lVar2 + 0xd0)) {
                *(undefined8 *)(lVar2 + 0xd0) = 0;
              }
            }
            if ((*(uint *)((longlong)plVar8 + 0x74) < *(uint *)((longlong)plVar8 + 0x44)) ||
               (*(uint *)((longlong)plVar8 + 100) < *(uint *)((longlong)plVar8 + 0x44))) {
              *(uint *)((longlong)plVar8 + 0x3c) = *(uint *)((longlong)plVar8 + 0x3c) | 1;
              *(int *)(plVar8 + 8) = (int)plVar8[8] + 0x10;
              uVar7 = ((*(uint *)((longlong)plVar8 + 100) - 1) + *(uint *)(lVar2 + 0x70)) /
                      *(uint *)(lVar2 + 0x70);
            }
            else {
              uVar7 = 1;
            }
            *(uint *)((longlong)plVar8 + 0x4c) = uVar7;
            *(int *)(lVar2 + 0xbc) = *(int *)(lVar2 + 0xbc) + uVar7;
            if (*(int *)((longlong)plVar8 + 0x3c) != 0) {
              *(int *)(plVar8 + 8) = (int)plVar8[8] + 4;
            }
            lVar10 = lVar2 + 0xf8;
            *(undefined4 *)(plVar8 + 0xd) = *(undefined4 *)((longlong)plVar8 + 100);
            plVar18 = *(longlong **)(lVar2 + 0x100);
            if (*plVar18 == lVar10) {
              *plVar8 = lVar10;
              plVar8[1] = (longlong)plVar18;
              *plVar18 = (longlong)plVar8;
              *(longlong **)(lVar2 + 0x100) = plVar8;
              *(int *)(lVar2 + 0x90) = *(int *)(lVar2 + 0x90) + 1;
              if (plVar9 != (longlong *)0x0) {
                plVar9[10] = (longlong)plVar8;
                plVar8[10] = (longlong)plVar9;
                *(int *)((longlong)plVar1 + 0x14) = *(int *)((longlong)plVar1 + 0x14) + 1;
                if (*(uint *)((longlong)plVar8 + 0x74) < *(uint *)((longlong)plVar9 + 0x44)) {
                  *(uint *)((longlong)plVar9 + 0x3c) = *(uint *)((longlong)plVar9 + 0x3c) | 1;
                  *(int *)(plVar9 + 8) = (int)plVar9[8] + 0x10;
                  uVar7 = (*(int *)((longlong)plVar9 + 100) + -1 + *(uint *)(lVar2 + 0x70)) /
                          *(uint *)(lVar2 + 0x70);
                }
                else {
                  uVar7 = 1;
                }
                *(uint *)((longlong)plVar9 + 0x4c) = uVar7;
                *(int *)(lVar2 + 0xbc) = *(int *)(lVar2 + 0xbc) + uVar7;
                if (*(int *)((longlong)plVar9 + 0x3c) != 0) {
                  *(int *)(plVar9 + 8) = (int)plVar9[8] + 4;
                }
                *(undefined4 *)(plVar9 + 0xd) = *(undefined4 *)((longlong)plVar9 + 100);
                plVar18 = *(longlong **)(lVar2 + 0x100);
                if (*plVar18 != lVar10) goto LAB_14001d9f3;
                *plVar9 = lVar10;
                plVar9[1] = (longlong)plVar18;
                *plVar18 = (longlong)plVar9;
                *(longlong **)(lVar2 + 0x100) = plVar9;
                *(int *)(lVar2 + 0x90) = *(int *)(lVar2 + 0x90) + 1;
              }
              uVar17 = CONCAT71((int7)((ulonglong)lVar10 >> 8),1);
              pcVar13 = PgmCancelSendIrp;
              plVar18 = local_78;
              uVar11 = PgmCheckSetCancelRoutine((longlong)local_78,PgmCancelSendIrp,'\x01');
              if (-1 < (int)uVar11) {
                IoReleaseCancelSpinLock(local_96);
                uVar11 = CONCAT71((int7)((ulonglong)pcVar13 >> 8),local_98);
                KeReleaseSpinLock(lVar16 + 0x1b8,uVar11);
                uVar11 = CONCAT71((int7)((ulonglong)uVar11 >> 8),local_97);
                KeReleaseSpinLock(&DAT_140036808,uVar11);
                if (*(uint *)(lVar16 + 0xf8) <= *(uint *)(lVar2 + 0x198)) {
                  uVar17 = 0;
                  uVar11 = 0;
                  KeSetEvent(lVar2 + 0x2c0,0);
                }
                uVar11 = CONCAT71((int7)((ulonglong)uVar11 >> 8),local_95);
                KeReleaseSpinLock(plVar1 + 0x2d);
                if (local_94 != '\0') {
                  ExReleaseResourceLite(lVar2 + 0x2e0);
                  KeLeaveCriticalRegion();
                }
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
                  WPP_SF_dqqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,uVar17,
                              (int)plVar8[2],(char)local_78,(char)plVar8,(char)plVar9);
                }
                puVar15 = auStackY_d8;
                uVar19 = 0x103;
                goto LAB_14001da56;
              }
              *(uint *)(plVar1 + 4) = *(uint *)(plVar1 + 4) | 0x4000;
              *(int *)(lVar2 + 0x90) = *(int *)(lVar2 + 0x90) + -1;
              *(int *)(lVar2 + 0xbc) = *(int *)(lVar2 + 0xbc) - *(int *)((longlong)plVar8 + 0x4c);
              lVar10 = *plVar8;
              if ((*(longlong **)(lVar10 + 8) == plVar8) &&
                 (plVar3 = (longlong *)plVar8[1], (longlong *)*plVar3 == plVar8)) {
                *plVar3 = lVar10;
                *(longlong **)(lVar10 + 8) = plVar3;
                ExFreeToNPagedLookasideList(lVar2 + 0x240,plVar8);
                if (plVar9 != (longlong *)0x0) {
                  *(int *)(lVar2 + 0x90) = *(int *)(lVar2 + 0x90) + -1;
                  *(int *)(lVar2 + 0xbc) =
                       *(int *)(lVar2 + 0xbc) - *(int *)((longlong)plVar9 + 0x4c);
                  lVar10 = *plVar9;
                  if ((*(longlong **)(lVar10 + 8) != plVar9) ||
                     (plVar8 = (longlong *)plVar9[1], (longlong *)*plVar8 != plVar9))
                  goto LAB_14001d9f3;
                  *plVar8 = lVar10;
                  *(longlong **)(lVar10 + 8) = plVar8;
                  plVar8 = plVar9;
                  ExFreeToNPagedLookasideList(lVar2 + 0x240,plVar9);
                }
                uVar11 = CONCAT71((int7)((ulonglong)plVar8 >> 8),local_96);
                KeReleaseSpinLock(plVar1 + 0x2d,uVar11);
                uVar11 = CONCAT71((int7)((ulonglong)uVar11 >> 8),local_98);
                KeReleaseSpinLock(lVar16 + 0x1b8,uVar11);
                IoReleaseCancelSpinLock(local_97);
                uVar11 = CONCAT71((int7)((ulonglong)uVar11 >> 8),local_95);
                KeReleaseSpinLock(&DAT_140036808);
                PgmDereferenceSessionCommon(plVar1,uVar11,uVar17,plVar18);
                if (plVar9 != (longlong *)0x0) {
                  PgmDereferenceSessionCommon(plVar1,uVar11,uVar17,plVar18);
                }
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
                  WPP_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x73,
                             &WPP_2d619c39f4c936783a7b398058864277_Traceguids,local_78,(char)plVar1,
                             (char)lVar16);
                }
                puVar15 = auStackY_d8;
                uVar19 = 0xc0000120;
                goto LAB_14001da56;
              }
            }
LAB_14001d9f3:
            pcVar13 = (code *)swi(0x29);
            (*pcVar13)(3);
            puVar14 = auStackY_d0;
            goto LAB_14001d9fa;
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
            uVar12 = 0x6f;
LAB_14001d1a7:
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar12,
                    &WPP_2d619c39f4c936783a7b398058864277_Traceguids);
          }
LAB_14001d1b7:
          KeReleaseSpinLock(local_90,local_96);
          KeReleaseSpinLock(local_70,local_97);
          uVar19 = 0xc000009a;
        }
        KeReleaseSpinLock(&DAT_140036808,uVar4);
        puVar15 = auStackY_d8;
        goto LAB_14001da56;
      }
LAB_14001d9fa:
      uVar4 = puVar14[0x40];
      puVar15 = puVar14;
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    uVar11 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(longlong *)(puVar15 + 0x20) = lVar16;
    *(undefined8 *)(puVar15 + -8) = 0x14001da3b;
    WPP_SF_qq(uVar11,0x6c,&WPP_2d619c39f4c936783a7b398058864277_Traceguids,plVar1,puVar15[0x20]);
  }
  *(undefined8 *)(puVar15 + -8) = 0x14001da4c;
  KeReleaseSpinLock(&DAT_140036808,uVar4);
  uVar19 = 0xc0000008;
LAB_14001da56:
  *(undefined8 *)(puVar15 + -8) = 0x14001da66;
  return uVar19;
}



===== PgmSendSpm @ 14001da8c =====

ulonglong PgmSendSpm(longlong param_1,undefined1 *param_2,uint *param_3)

{
  longlong lVar1;
  ushort uVar2;
  undefined1 uVar3;
  int iVar4;
  ulonglong *puVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  ushort local_res8 [4];
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  lVar1 = *(longlong *)(param_1 + 0x28);
  *param_3 = 0;
  local_res8[0] = *(ushort *)(*(longlong *)(lVar1 + 0x20) + 0xf8);
  puVar5 = (ulonglong *)ExAllocatePool2(0x40,local_res8[0],0x326d6750);
  if (puVar5 == (ulonglong *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
              &WPP_2d619c39f4c936783a7b398058864277_Traceguids);
    }
    uVar6 = 0xc000009a;
  }
  else {
    lVar1 = *(longlong *)(param_1 + 0x28);
    local_48 = 0;
    lStack_40 = 0;
    local_38 = 0;
    uStack_30 = 0;
    uVar10 = *(uint *)(lVar1 + 0xc4);
    if ((uVar10 & 8) != 0) {
      uVar9 = *(int *)(lVar1 + 0x98) - *(int *)(lVar1 + 0xb0);
      uVar8 = *(uint *)(lVar1 + 0xa4);
      if (-1 < (int)(uVar9 - *(uint *)(lVar1 + 0xa4))) {
        uVar8 = uVar9;
      }
      lStack_40 = (ulonglong)uVar8 << 0x20;
    }
    if ((uVar10 >> 9 & 1) != 0) {
      iVar4 = *(int *)(lVar1 + 0xb8);
      uStack_30 = (ulonglong)*(byte *)(param_1 + 0xa0) << 0x20;
      if ((iVar4 != 0) && (*(int *)(lVar1 + 0xb4) == (*(int *)(lVar1 + 0x98) - iVar4) + -1)) {
        uStack_30 = (ulonglong)
                    CONCAT15(*(byte *)(param_1 + 0xa0) - (char)iVar4,(undefined5)uStack_30);
        uVar10 = uVar10 | 0x800;
      }
    }
    uVar7 = InitDataSpmHeader(param_1,0,(ushort *)puVar5,local_res8,uVar10,(longlong)&local_48,0);
    uVar2 = local_res8[0];
    uVar6 = uVar7 & 0xffffffff;
    if ((int)uVar7 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                 &WPP_2d619c39f4c936783a7b398058864277_Traceguids,(int)uVar7);
      }
      ExFreePoolWithTag(puVar5,0);
    }
    else {
      uVar9 = (uint)local_res8[0];
      uVar8 = *(uint *)(*(longlong *)(param_1 + 0x28) + 0xac);
      *(uint *)(*(longlong *)(param_1 + 0x28) + 0xac) = uVar8 + 1;
      *(uint *)(puVar5 + 2) =
           uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 << 0x18;
      uVar8 = *(uint *)(*(longlong *)(param_1 + 0x28) + 0xa4);
      *(uint *)((longlong)puVar5 + 0x14) =
           uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 << 0x18;
      uVar8 = *(int *)(*(longlong *)(param_1 + 0x28) + 0x98) - 1;
      *(undefined2 *)((longlong)puVar5 + 0x1c) = 0x100;
      *(uint *)(puVar5 + 3) =
           uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 * 0x1000000;
      uVar8 = *(uint *)(*(longlong *)(param_1 + 0x28) + 0x2c);
      *(uint *)(puVar5 + 4) =
           uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 << 0x18;
      *(undefined2 *)((longlong)puVar5 + 6) = 0;
      iVar4 = tcpxsum(0,puVar5,uVar9);
      uVar3 = *param_2;
      *(ushort *)((longlong)puVar5 + 6) = ~(ushort)iVar4;
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      KeReleaseSpinLock(param_1 + 0x168,uVar3);
      lVar1 = *(longlong *)(param_1 + 0x28);
      uVar6 = TdiSendDatagram(*(undefined8 *)(*(longlong *)(lVar1 + 0x20) + 0x60),
                              *(undefined8 *)(*(longlong *)(lVar1 + 0x20) + 0x68),puVar5,uVar9,
                              PgmSendSpmCompletion,param_1,puVar5,*(uint *)(lVar1 + 0x28),
                              *(ushort *)(lVar1 + 0x30),'\0');
      uVar6 = uVar6 & 0xffffffff;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
        lVar1 = *(longlong *)(param_1 + 0x28);
        uVar8 = *(int *)(lVar1 + 0x98) - 1;
        WPP_SF_dDdDdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)uVar8,
                      (ulonglong)*(ushort *)(lVar1 + 0x30),(uint)uVar2,
                      (char)*(undefined4 *)(lVar1 + 0x28),(char)*(ushort *)(lVar1 + 0x30),
                      (char)uVar10,(char)*(undefined4 *)(lVar1 + 0xa4),(char)uVar8);
      }
      uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x168);
      *param_2 = uVar3;
      *param_3 = (uint)uVar2;
    }
  }
  return uVar6;
}



===== PgmSendSpmCompletion @ 14001dd80 =====

void PgmSendSpmCompletion(longlong *param_1,ulonglong param_2,uint param_3,longlong *param_4)

{
  undefined1 uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined **ppuVar4;
  longlong *plVar5;
  
  plVar5 = (longlong *)(ulonglong)param_3;
  uVar2 = param_2;
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x2d);
  if ((int)param_3 < 0) {
    ppuVar4 = &WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      ppuVar4 = (undefined **)&WPP_2d619c39f4c936783a7b398058864277_Traceguids;
      uVar2 = 0;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
               &WPP_2d619c39f4c936783a7b398058864277_Traceguids,param_3);
      param_4 = plVar5;
    }
  }
  else {
    ppuVar4 = &WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (uVar2 = (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
       (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      ppuVar4 = (undefined **)&WPP_2d619c39f4c936783a7b398058864277_Traceguids;
      uVar2 = 0;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
              &WPP_2d619c39f4c936783a7b398058864277_Traceguids);
    }
  }
  uVar3 = CONCAT71((int7)(uVar2 >> 8),uVar1);
  KeReleaseSpinLock(param_1 + 0x2d);
  PgmDereferenceSessionCommon(param_1,uVar3,ppuVar4,param_4);
  ExFreePoolWithTag(param_2,0);
  return;
}



===== SendNextPacket @ 14001de70 =====

ulonglong SendNextPacket(longlong *param_1,undefined8 param_2,undefined **param_3,
                        undefined **param_4)

{
  byte bVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined **ppuVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined **ppuVar8;
  byte bVar9;
  undefined1 local_res8 [8];
  uint local_res10 [2];
  undefined *local_res18 [2];
  
  lVar3 = param_1[5];
  local_res10[0] = 0;
  local_res18[0] = (undefined *)0x0;
  bVar1 = *(byte *)(*(longlong *)(lVar3 + 0x20) + 0x38);
  bVar9 = bVar1 & 0x10;
  local_res8[0] = KeAcquireSpinLockRaiseToDpc(param_1 + 0x2d);
  do {
    ppuVar8 = &WPP_GLOBAL_Control;
    if (*(uint *)(lVar3 + 0x198) < *(uint *)(*(longlong *)(lVar3 + 0x20) + 0xf8)) {
LAB_14001e15e:
      if (bVar9 == 0) {
        ppuVar8 = (undefined **)0x0;
        RemoveAllEntries((longlong)param_1,'\0');
      }
      AdvanceWindow((longlong)param_1,ppuVar8,param_3);
      uVar6 = CheckForTermination(param_1,local_res8,param_3,(longlong *)param_4);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
        WPP_SF_iD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
                  (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),param_3,param_1[0x18],(char)uVar6)
        ;
      }
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffffd;
      uVar7 = KeReleaseSpinLock(param_1 + 0x2d,local_res8[0]);
      return CONCAT71((int7)((ulonglong)uVar7 >> 8),(char)uVar6);
    }
    local_res10[0] = 0;
    if ((*(uint *)(param_1 + 4) & 4) == 0) {
      if (*(ulonglong *)(lVar3 + 0x180) <= *(ulonglong *)(lVar3 + 0x170)) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
          param_4 = *(undefined ***)(lVar3 + 0x128);
          WPP_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5e,param_3,param_4,
                    (char)*(undefined4 *)(lVar3 + 0x198));
        }
        param_3 = (undefined **)local_res10;
        PgmSendSpm((longlong)param_1,local_res8,(uint *)param_3);
        *(undefined8 *)(lVar3 + 0x170) = 0;
        uVar4 = *(longlong *)(lVar3 + 0x180) * 2;
        *(ulonglong *)(lVar3 + 0x180) = uVar4;
        if (*(ulonglong *)(lVar3 + 400) < uVar4) {
          *(ulonglong *)(lVar3 + 0x180) = *(ulonglong *)(lVar3 + 400);
        }
        goto LAB_14001dfdf;
      }
LAB_14001dfeb:
      if ((*(int *)(lVar3 + 0x94) != 0) || (*(int *)(lVar3 + 0x90) != 0)) {
        param_3 = (undefined **)
                  (CONCAT71((int7)((ulonglong)param_3 >> 8),bVar1) & 0xffffffffffffff10);
        ppuVar8 = local_res18;
        ppuVar5 = (undefined **)FindFirstEntry((longlong)param_1,ppuVar8,bVar9);
        if (ppuVar5 == (undefined **)0x0) {
          if (*(int *)(lVar3 + 0x90) != 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
              param_4 = *(undefined ***)(lVar3 + 0x128);
              uVar2 = *(uint *)(*(longlong *)(lVar3 + 0x20) + 0xf8);
              WPP_SF_idd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)uVar2,param_3,param_4
                         ,(char)*(undefined4 *)(lVar3 + 0x198),(char)uVar2);
            }
            param_3 = (undefined **)local_res10;
            ppuVar8 = (undefined **)local_res8;
            PgmSendNextOData((longlong)param_1,(undefined1 *)ppuVar8,(uint *)param_3);
          }
        }
        else {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
            WPP_SF_didd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),*(longlong *)(lVar3 + 0x20),
                        param_3,*(undefined4 *)(ppuVar5 + 2),(char)*(undefined8 *)(lVar3 + 0x128),
                        (char)*(undefined4 *)(lVar3 + 0x198),
                        (char)*(undefined4 *)(*(longlong *)(lVar3 + 0x20) + 0xf8));
          }
          param_4 = (undefined **)local_res10;
          param_3 = (undefined **)local_res8;
          PgmSendRData((longlong)param_1,(longlong *)ppuVar5,(undefined1 *)param_3,(uint *)param_4);
          ppuVar8 = ppuVar5;
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
          param_4 = (undefined **)(ulonglong)local_res10[0];
          param_3 = (undefined **)&WPP_2d619c39f4c936783a7b398058864277_Traceguids;
          ppuVar8 = (undefined **)0x61;
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x61,
                   &WPP_2d619c39f4c936783a7b398058864277_Traceguids,local_res10[0]);
        }
        if (local_res10[0] != 0) {
          *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 4;
          *(int *)(lVar3 + 0xc0) = *(int *)(lVar3 + 0xc0) + 1;
          goto LAB_14001e120;
        }
      }
      uVar2 = *(int *)(lVar3 + 0x19c) * 2;
      if (uVar2 < *(uint *)(lVar3 + 0x198)) {
        *(uint *)(lVar3 + 0x198) = uVar2;
      }
      goto LAB_14001e15e;
    }
    if ((*(uint *)(lVar3 + 0xc0) < 0x33) &&
       (*(ulonglong *)(lVar3 + 0x170) < *(ulonglong *)(lVar3 + 0x178))) goto LAB_14001dfeb;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
      param_4 = *(undefined ***)(lVar3 + 0x128);
      WPP_SF_id(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5d,param_3,param_4,
                (char)*(undefined4 *)(lVar3 + 0x198));
    }
    param_3 = (undefined **)local_res10;
    PgmSendSpm((longlong)param_1,local_res8,(uint *)param_3);
    *(undefined8 *)(lVar3 + 0x170) = 0;
    *(undefined8 *)(lVar3 + 0x180) = *(undefined8 *)(lVar3 + 0x188);
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffffb;
LAB_14001dfdf:
    *(undefined4 *)(lVar3 + 0xc0) = 0;
LAB_14001e120:
    param_1[0x18] = param_1[0x18] + (ulonglong)local_res10[0];
    *(int *)(lVar3 + 0x198) = *(int *)(lVar3 + 0x198) - local_res10[0];
  } while( true );
}



===== SendSessionTimeout @ 14001e1e0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SendSessionTimeout(undefined8 param_1,longlong *param_2,undefined *param_3)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined1 uVar4;
  ulonglong uVar5;
  char *pcVar6;
  uint uVar7;
  longlong *plVar8;
  undefined8 uVar9;
  longlong lVar10;
  uint uVar11;
  longlong lVar12;
  longlong *plVar13;
  int iVar14;
  longlong *plVar15;
  
  lVar10 = _DAT_fffff78000000008;
  lVar1 = param_2[5];
  plVar13 = *(longlong **)(lVar1 + 0x20);
  plVar8 = param_2;
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x2d);
  if ((*(uint *)(param_2 + 4) & 1) == 0) {
    lVar10 = lVar10 - *(longlong *)(lVar1 + 0x118);
    lVar2 = *(longlong *)(lVar1 + 0x120);
    lVar12 = 0;
    uVar11 = 0;
    if (lVar2 < lVar10) {
      do {
        lVar12 = lVar12 + lVar2;
        lVar10 = lVar10 - lVar2;
        uVar11 = uVar11 + 1;
      } while (lVar2 < lVar10);
      if (uVar11 != 0) {
        uVar7 = *(int *)((longlong)param_2 + 0xa4) + uVar11;
        *(uint *)((longlong)param_2 + 0xa4) = uVar7;
        if (0xcb < uVar7) {
          lVar10 = *(longlong *)(lVar1 + 0x128);
          lVar2 = param_2[0x18];
          *(undefined4 *)((longlong)param_2 + 0xa4) = 0;
          uVar5 = 0;
          param_2[0x1c] = (ulonglong)(lVar2 * 8) / (ulonglong)(lVar10 * 0x14);
          param_2[0x1a] = (ulonglong)(lVar2 - param_2[0x16]) >> 9;
          param_2[0x15] = param_2[0x17];
          param_2[0x16] = lVar2;
          lVar10 = *(longlong *)(lVar1 + 0x350);
          if (lVar10 == 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x65,
                       &WPP_2d619c39f4c936783a7b398058864277_Traceguids,
                       *(undefined4 *)(lVar1 + 0x348));
            }
          }
          else {
            uVar5 = (ulonglong)(lVar10 * 100) / (ulonglong)(*(longlong *)(lVar1 + 0x348) + lVar10);
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
              WPP_SF_dddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),100,
                          &WPP_2d619c39f4c936783a7b398058864277_Traceguids,
                          *(undefined4 *)(lVar1 + 0x350),(char)*(undefined4 *)(lVar1 + 0x348),
                          (char)uVar5,
                          (char)((ulonglong)(*(longlong *)(lVar1 + 0x380) * 100) /
                                (ulonglong)
                                (*(longlong *)(lVar1 + 0x378) + *(longlong *)(lVar1 + 0x380))));
            }
          }
          if ((*(uint *)(plVar13 + 7) & 0x10) != 0) {
            uVar7 = *(uint *)(lVar1 + 0x19c);
            if (uVar5 < 8) {
              if (uVar7 < *(uint *)(lVar1 + 0x1a0)) {
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
                  WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x67,
                            &WPP_2d619c39f4c936783a7b398058864277_Traceguids,uVar7,
                            (char)*(undefined4 *)(lVar1 + 0x1a4));
                }
                *(int *)(lVar1 + 0x19c) = *(int *)(lVar1 + 0x19c) + *(int *)(lVar1 + 0x1a4);
              }
            }
            else if (*(uint *)(lVar1 + 0x1a4) < uVar7) {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
                WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x66,
                          &WPP_2d619c39f4c936783a7b398058864277_Traceguids,uVar7,
                          (char)*(uint *)(lVar1 + 0x1a4));
              }
              *(int *)(lVar1 + 0x19c) = *(int *)(lVar1 + 0x19c) - *(int *)(lVar1 + 0x1a4);
            }
          }
          *(undefined8 *)(lVar1 + 0x350) = 0;
          *(undefined8 *)(lVar1 + 0x348) = 0;
        }
        *(longlong *)(lVar1 + 0x118) = *(longlong *)(lVar1 + 0x118) + lVar12;
        uVar5 = (ulonglong)uVar11;
        *(longlong *)(lVar1 + 0x128) = *(longlong *)(lVar1 + 0x128) + uVar5;
        if (*(ulonglong *)(lVar1 + 0x170) <= *(ulonglong *)(lVar1 + 0x180)) {
          *(ulonglong *)(lVar1 + 0x170) = *(ulonglong *)(lVar1 + 0x170) + uVar5;
        }
        uVar3 = *(ulonglong *)(lVar1 + 0x168);
        if (uVar5 < uVar3) {
          *(ulonglong *)(lVar1 + 0x168) = uVar3 - uVar5;
        }
        else {
          uVar7 = *(uint *)(lVar1 + 0x19c);
          iVar14 = *(int *)(lVar1 + 0x198) + uVar7;
          *(int *)(lVar1 + 0x198) = iVar14;
          if (uVar5 != uVar3) {
            if (*(ulonglong *)(lVar1 + 0x130) == 1) {
              *(uint *)(lVar1 + 0x198) = (uVar11 - *(int *)(lVar1 + 0x168)) * uVar7 + iVar14;
            }
            else {
              *(int *)(lVar1 + 0x198) =
                   (int)(((ulonglong)uVar7 * (uVar5 - uVar3)) / *(ulonglong *)(lVar1 + 0x130)) +
                   iVar14;
            }
          }
          *(undefined8 *)(lVar1 + 0x168) = *(undefined8 *)(lVar1 + 0x130);
          KeSetEvent(lVar1 + 0x2c0,0,0);
        }
      }
    }
    KeReleaseSpinLock(param_2 + 0x2d,uVar4);
    KeInitializeTimer(param_2 + 0x1d);
    plVar13 = param_2 + 0x25;
    KeInitializeDpc(plVar13,SendSessionTimeout,param_2);
    KeSetTimer(param_2 + 0x1d,0xfffffffffffcf2c0);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      pcVar6 = "";
      if ((*(uint *)(param_2 + 4) & 2) == 0) {
        pcVar6 = "NOT ";
      }
      WPP_SF_iiis(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),"NOT ",plVar13,
                  *(undefined8 *)(lVar1 + 0x128),(char)*(undefined8 *)(lVar1 + 0x168),
                  (char)*(undefined8 *)(lVar1 + 0x170),pcVar6);
    }
  }
  else {
    plVar15 = (longlong *)WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      param_3 = &WPP_2d619c39f4c936783a7b398058864277_Traceguids;
      plVar8 = (longlong *)0x0;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),99,
              &WPP_2d619c39f4c936783a7b398058864277_Traceguids);
    }
    *(undefined8 *)(lVar1 + 0x20) = 0;
    uVar9 = CONCAT71((int7)((ulonglong)plVar8 >> 8),uVar4);
    KeReleaseSpinLock(param_2 + 0x2d);
    PgmDereferenceSessionCommon(param_2,uVar9,param_3,plVar15);
    PgmDereferenceAddress(plVar13,uVar9,param_3,plVar15);
  }
  return;
}



===== SenderProcessNakPacket @ 14001e64c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint SenderProcessNakPacket(undefined8 param_1,longlong param_2,uint param_3,longlong param_4)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  uint uVar4;
  undefined1 uVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined2 uVar8;
  char *pcVar9;
  undefined1 auStackY_218 [32];
  uint local_1d8 [4];
  uint local_1c8 [63];
  ushort local_cc;
  short local_ca;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_218;
  memset(local_1c8,0,0x180);
  lVar1 = param_2 + 0x168;
  uVar5 = KeAcquireSpinLockRaiseToDpc(lVar1);
  local_1d8[0] = *(uint *)(*(longlong *)(param_2 + 0x28) + 0x98);
  uVar6 = ExtractNakNcfSequences
                    (param_4,param_3 - 0x24,local_1c8,local_1d8,*(byte *)(param_2 + 0xa0));
  uVar4 = local_1d8[0];
  if ((int)uVar6 < 0) {
    KeReleaseSpinLock(lVar1,uVar5);
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) goto LAB_14001e8eb;
    uVar8 = 0x35;
LAB_14001e719:
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
             &WPP_2d619c39f4c936783a7b398058864277_Traceguids,uVar6);
  }
  else {
    plVar2 = (longlong *)(*(longlong *)(param_2 + 0x28) + 0x358);
    *plVar2 = *plVar2 + (ulonglong)local_cc;
    lVar3 = *(longlong *)(param_2 + 0x28);
    if (((int)(local_1c8[0] - *(int *)(lVar3 + 0xa4)) < 0) ||
       (-1 < (int)(local_1d8[0] - *(int *)(lVar3 + 0x98)))) {
      *(longlong *)(lVar3 + 0x360) = *(longlong *)(lVar3 + 0x360) + 1;
      KeReleaseSpinLock(lVar1,uVar5);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        lVar1 = *(longlong *)(param_2 + 0x28);
        pcVar9 = "Parity";
        if (local_ca != 2) {
          pcVar9 = "Selective";
        }
        WPP_SF_sdddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar1,WPP_GLOBAL_Control,pcVar9,
                     (char)local_1c8[0],(char)uVar4,(char)*(undefined4 *)(lVar1 + 0xa4),
                     (char)*(undefined4 *)(lVar1 + 0x98) + -1);
      }
    }
    else {
      if ((-1 < *(char *)(param_4 + 5)) || ((*(byte *)(param_2 + 0xa1) & 1) != 0)) {
        uVar7 = FilterAndAddNaksToList(param_2,(longlong)local_1c8);
        uVar6 = (uint)uVar7;
        KeReleaseSpinLock(lVar1,uVar5);
        if (-1 < (int)uVar6) {
          if (local_cc != 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
              WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,
                        &WPP_2d619c39f4c936783a7b398058864277_Traceguids,(uint)local_cc,
                        (undefined1)local_ca);
            }
            PgmSendNcf(param_2,param_4,(int *)local_1c8,param_3);
          }
          return 0;
        }
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) goto LAB_14001e8eb;
        uVar8 = 0x38;
        goto LAB_14001e719;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
                &WPP_2d619c39f4c936783a7b398058864277_Traceguids);
      }
      KeReleaseSpinLock(lVar1,uVar5);
    }
    uVar6 = 0xc000021b;
  }
LAB_14001e8eb:
  return uVar6;
}



===== SenderWorkerThread @ 14001e920 =====

void SenderWorkerThread(longlong *param_1)

{
  undefined1 uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  
  do {
    ppuVar5 = (undefined **)0x0;
    ppuVar4 = (undefined **)0x0;
    uVar3 = 0;
    KeWaitForSingleObject(param_1[5] + 0x2c0);
    uVar2 = SendNextPacket(param_1,uVar3,ppuVar4,ppuVar5);
  } while ((char)uVar2 == '\0');
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x2d);
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 1;
  KeReleaseSpinLock(param_1 + 0x2d,uVar1);
  return;
}



===== WPP_SF_DdD @ 14001e99c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DdD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2d619c39f4c936783a7b398058864277_Traceguids,0x19,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_dDdDdd @ 14001ea00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dDdDdd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                  undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                  undefined1 param_9)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2d619c39f4c936783a7b398058864277_Traceguids,0x20,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,&param_9,4,0);
  return;
}



===== WPP_SF_ddDd @ 14001ea8c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ddDd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2d619c39f4c936783a7b398058864277_Traceguids,0x30,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_dddDd @ 14001eafc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dddDd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2d619c39f4c936783a7b398058864277_Traceguids,0x46,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_SF_dddddii @ 14001eb7c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dddddii(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                   undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                   undefined1 param_9,undefined1 param_10)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2d619c39f4c936783a7b398058864277_Traceguids,0x4e,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,&param_9,8,&param_10,8,0);
  return;
}



===== WPP_SF_ddi @ 14001ec18 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ddi(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2d619c39f4c936783a7b398058864277_Traceguids,0x50,local_res20,4,
             &param_5,4,&param_6,8,0);
  return;
}



===== WPP_SF_ddidii @ 14001ec80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ddidii(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                  undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                  undefined1 param_9)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2d619c39f4c936783a7b398058864277_Traceguids,param_2,local_res20,4,
             &param_5,4,&param_6,8,&param_7,4,&param_8,8,&param_9,8,0);
  return;
}



===== WPP_SF_ddiii @ 14001ed10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ddiii(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2d619c39f4c936783a7b398058864277_Traceguids,0x4a,local_res20,4,
             &param_5,4,&param_6,8,&param_7,8,&param_8,8,0);
  return;
}



===== WPP_SF_didd @ 14001ed94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_didd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2d619c39f4c936783a7b398058864277_Traceguids,0x5f,local_res20,4,
             &param_5,8,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_dqddd @ 14001ee08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dqddd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2d619c39f4c936783a7b398058864277_Traceguids,0x3c,local_res20,4,
             &param_5,8,&param_6,4,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_SF_dqqq @ 14001ee8c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dqqq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2d619c39f4c936783a7b398058864277_Traceguids,0x74,local_res20,4,
             &param_5,8,&param_6,8,&param_7,8,0);
  return;
}



===== WPP_SF_iD @ 14001ef00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_iD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2d619c39f4c936783a7b398058864277_Traceguids,0x62,&local_res20,8,
             &param_5,4,0);
  return;
}



===== WPP_SF_id @ 14001ef5c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_id(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2d619c39f4c936783a7b398058864277_Traceguids,param_2,&local_res20,8,
             &param_5,4,0);
  return;
}



===== WPP_SF_idd @ 14001efb4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_idd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2d619c39f4c936783a7b398058864277_Traceguids,0x60,&local_res20,8,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_ii @ 14001f01c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ii(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2d619c39f4c936783a7b398058864277_Traceguids,0x49,&local_res20,8,
             &param_5,8,0);
  return;
}



===== WPP_SF_iiii @ 14001f074 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_iiii(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2d619c39f4c936783a7b398058864277_Traceguids,0x4c,&local_res20,8,
             &param_5,8,&param_6,8,&param_7,8,0);
  return;
}



===== WPP_SF_iiis @ 14001f0e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_iiis(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,char *param_7)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  undefined8 local_res20;
  
  if (param_7 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_7[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  pcVar3 = param_7;
  if (param_7 == (char *)0x0) {
    pcVar3 = "NULL";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2d619c39f4c936783a7b398058864277_Traceguids,0x68,&local_res20,8,
             &param_5,8,&param_6,8,pcVar3,lVar2,0);
  return;
}



===== WPP_SF_qddddd @ 14001f194 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qddddd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                  undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                  undefined1 param_9)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2d619c39f4c936783a7b398058864277_Traceguids,0x47,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,&param_9,4,0);
  return;
}



===== WPP_SF_qii @ 14001f224 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qii(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2d619c39f4c936783a7b398058864277_Traceguids,0x57,&local_res20,8,
             &param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_qqqdd @ 14001f288 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqqdd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2d619c39f4c936783a7b398058864277_Traceguids,param_2,&local_res20,8,
             &param_5,8,&param_6,8,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_SF_sdddd @ 14001f310 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sdddd(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_4[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2d619c39f4c936783a7b398058864277_Traceguids,0x36,param_4,lVar2,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,0);
  return;
}



===== PgmQueryTcpInfo @ 14001f3d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PgmQueryTcpInfo(undefined8 param_1,undefined4 param_2,void *param_3,uint param_4,
                   longlong *param_5,int *param_6)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined2 uVar4;
  int iVar5;
  undefined *puVar6;
  bool bVar7;
  undefined1 auStackY_148 [32];
  undefined1 uVar8;
  undefined8 local_f8;
  uint local_f0;
  ulonglong local_e8;
  ulonglong uStack_e0;
  undefined8 local_d8;
  longlong *local_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined8 local_84;
  undefined8 uStack_7c;
  undefined4 local_74;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_148;
  lVar3 = 0;
  local_d0 = param_5;
  local_f8 = 0;
  local_c4 = 0;
  local_ac = 0;
  local_e8 = 0;
  uStack_e0 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  iVar5 = 0;
  if ((param_5 != (longlong *)0x0) && (param_6 != (int *)0x0)) {
    iVar5 = 0;
    if (*param_6 != 0) {
      iVar5 = *param_6;
    }
  }
  local_74 = 0;
  local_98 = 0x301;
  local_90 = 0x200;
  local_8c = 0x100;
  local_84 = 0;
  uStack_7c = 0;
  local_f0 = param_4;
  local_d8 = param_1;
  local_88 = param_2;
  if ((param_4 != 0) && (param_3 != (void *)0x0)) {
    memmove((void *)((longlong)&local_84 + 4),param_3,(ulonglong)param_4);
  }
  lVar2 = PsGetCurrentProcess();
  bVar7 = lVar2 != PgmStaticConfig;
  if (bVar7) {
    KeStackAttachProcess(PgmStaticConfig,&local_70);
  }
  local_c8 = 0x30;
  local_c0 = 0;
  local_b0 = 0x240;
  local_b8 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  iVar1 = ZwCreateEvent(&local_f8,0x1f0003,&local_c8,1);
  uVar8 = (undefined1)param_2;
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
                &WPP_bb24dc9f99d8356a0c4778f616204a55_Traceguids,iVar1,uVar8);
    }
    return iVar1;
  }
  do {
    if (lVar3 != 0) {
      ExFreePoolWithTag(lVar3,0);
      lVar3 = 0;
      iVar5 = iVar5 * 2;
    }
    if (iVar5 != 0) {
      puVar6 = (undefined *)0x336d6750;
      lVar3 = ExAllocatePool2(0x40,iVar5);
      if (lVar3 == 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          puVar6 = &WPP_bb24dc9f99d8356a0c4778f616204a55_Traceguids;
          WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
                    &WPP_bb24dc9f99d8356a0c4778f616204a55_Traceguids,iVar5,uVar8);
        }
        iVar1 = -0x3fffff66;
LAB_14001f700:
        ZwClose(local_f8);
        if (bVar7) {
          KeUnstackDetachProcess(&local_70);
        }
        if (iVar1 < 0) {
          if (lVar3 == 0) {
            return -0x3fffffff;
          }
          ExFreePoolWithTag(lVar3,0);
          return -0x3fffffff;
        }
        if (lVar3 != 0) {
          *local_d0 = lVar3;
          *param_6 = (int)uStack_e0;
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return iVar1;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
          return iVar1;
        }
        WPP_SF_Dddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uStack_e0 & 0xffffffff,puVar6,param_2
                    ,(char)local_f0,(char)uStack_e0,(char)iVar5);
        return iVar1;
      }
    }
    local_e8 = local_e8 & 0xffffffff00000000;
    puVar6 = (undefined *)0x0;
    iVar1 = ZwDeviceIoControlFile(local_d8,local_f8,0,0);
    if (iVar1 == 0x103) {
      puVar6 = (undefined *)0x0;
      iVar1 = NtWaitForSingleObject(local_f8);
    }
    if (iVar1 == 0) {
      iVar1 = (int)local_e8;
      if ((((int)local_e8 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        uVar4 = 0x25;
LAB_14001f691:
        puVar6 = &WPP_bb24dc9f99d8356a0c4778f616204a55_Traceguids;
        WPP_SF_dDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
                   &WPP_bb24dc9f99d8356a0c4778f616204a55_Traceguids,iVar1,uVar8,(char)iVar5);
      }
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      uVar4 = 0x26;
      goto LAB_14001f691;
    }
    if ((iVar5 == 0) || ((iVar1 != -0x7ffffffb && (iVar1 != -0x3fffffdd)))) goto LAB_14001f700;
  } while( true );
}



===== PgmSetTcpInfo @ 14001f7bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 PgmSetTcpInfo(undefined8 param_1,undefined4 param_2,void *param_3,ulonglong param_4)

{
  int iVar1;
  undefined4 *puVar2;
  longlong lVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  ulonglong _Size;
  bool bVar6;
  undefined1 auStack_118 [32];
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined8 local_a0;
  undefined8 local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_118;
  local_c8 = 0;
  local_8c = 0;
  _Size = param_4 & 0xffff;
  local_a4 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_c0 = param_1;
  puVar2 = (undefined4 *)ExAllocatePool2(0x40,(int)_Size + 0x1c,0x326d6750);
  if (puVar2 == (undefined4 *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                &WPP_bb24dc9f99d8356a0c4778f616204a55_Traceguids,0x1c,(char)_Size);
    }
    return 0xc000009a;
  }
  puVar2[1] = 0;
  *puVar2 = 0x401;
  puVar2[4] = param_2;
  puVar2[2] = 0x200;
  puVar2[3] = 0x200;
  puVar2[5] = (int)_Size;
  memmove(puVar2 + 6,param_3,_Size);
  lVar3 = PsGetCurrentProcess();
  bVar6 = lVar3 != PgmStaticConfig;
  if (bVar6) {
    KeStackAttachProcess(PgmStaticConfig,&local_78);
  }
  local_a0 = 0;
  local_98 = 0;
  local_a8 = 0x30;
  local_90 = 0x240;
  local_88 = 0;
  uStack_80 = 0;
  iVar1 = ZwCreateEvent(&local_c8,0x1f0003,&local_a8,1);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
                &WPP_bb24dc9f99d8356a0c4778f616204a55_Traceguids,iVar1,(char)param_2);
    }
    goto LAB_14001fa4d;
  }
  iVar1 = ZwDeviceIoControlFile(local_c0,local_c8,0,0);
  if (iVar1 == 0x103) {
    iVar1 = NtWaitForSingleObject(local_c8,0,0);
  }
  if (iVar1 == 0) {
    iVar1 = (int)local_b8;
    if ((((int)local_b8 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      uVar4 = 0x1f;
LAB_14001f9f3:
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
                &WPP_bb24dc9f99d8356a0c4778f616204a55_Traceguids,iVar1,(char)param_2);
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    uVar4 = 0x20;
    goto LAB_14001f9f3;
  }
  ZwClose(local_c8);
LAB_14001fa4d:
  if (bVar6) {
    KeUnstackDetachProcess(&local_78);
  }
  if (iVar1 == 0) {
    uVar5 = 0;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
                &WPP_bb24dc9f99d8356a0c4778f616204a55_Traceguids,param_2,(char)_Size);
    }
  }
  else {
    uVar5 = 0xc0000001;
  }
  ExFreePoolWithTag(puVar2,0);
  return uVar5;
}



===== PgmTdiCompletionRoutine @ 14001fae0 =====

undefined8 PgmTdiCompletionRoutine(undefined1 param_1,undefined1 param_2,undefined8 param_3)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
    WPP_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_bb24dc9f99d8356a0c4778f616204a55_Traceguids,param_3,param_2,param_1);
  }
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== TdiErrorHandler @ 14001fb60 =====

undefined8 TdiErrorHandler(undefined8 param_1,undefined4 param_2)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
             &WPP_bb24dc9f99d8356a0c4778f616204a55_Traceguids,param_2);
  }
  return 0xc000021b;
}



===== TdiSendDatagram @ 14001fba8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
TdiSendDatagram(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined *param_5,undefined8 param_6,undefined8 param_7,uint param_8,ushort param_9,
               char param_10)

{
  undefined1 uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  char *pcVar6;
  
  lVar3 = 0;
  lVar2 = ExAllocateFromNPagedLookasideList(&DAT_140025dc0);
  if (((lVar2 == 0) ||
      (lVar3 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*pgPgmDevice >> 8),
                                      *(undefined1 *)(*pgPgmDevice + 0x4c)),0), lVar3 == 0)) ||
     (lVar4 = IoAllocateMdl(param_3,param_4,0,0,0), lVar4 == 0)) {
    if (lVar2 != 0) {
      ExFreeToNPagedLookasideList(&DAT_140025dc0,lVar2);
    }
    if (lVar3 != 0) {
      IoFreeIrp(lVar3);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
               &WPP_bb24dc9f99d8356a0c4778f616204a55_Traceguids,0x68);
    }
    if (param_5 == (undefined *)0x0) {
      return 0xc000009a;
    }
    (*(code *)param_5)(param_6,param_7,0xc000009a);
  }
  else {
    if (param_10 == '\0') {
      MmBuildMdlForNonPagedPool(lVar4);
    }
    else {
      MmProbeAndLockPages(lVar4,0,0);
    }
    *(bool *)(lVar2 + 0x60) = param_10 != '\0';
    *(longlong *)(lVar3 + 8) = lVar4;
    *(undefined4 *)(lVar2 + 0x30) = 1;
    *(undefined4 *)(lVar2 + 0x34) = 0x2000e;
    *(uint *)(lVar2 + 0x3a) =
         param_8 >> 0x18 | (param_8 & 0xff0000) >> 8 | (param_8 & 0xff00) << 8 | param_8 << 0x18;
    *(ushort *)(lVar2 + 0x38) = param_9 >> 8 | param_9 << 8;
    *(undefined4 *)(lVar2 + 0x20) = 0x16;
    *(undefined4 **)(lVar2 + 0x28) = (undefined4 *)(lVar2 + 0x30);
    *(undefined **)(lVar2 + 0x48) = param_5;
    *(undefined8 *)(lVar2 + 0x50) = param_6;
    *(undefined8 *)(lVar2 + 0x58) = param_7;
    lVar4 = *(longlong *)(lVar3 + 0xb8);
    *(code **)(lVar4 + -0x10) = TdiSendDatagramCompletion;
    *(longlong *)(lVar4 + -8) = lVar2;
    *(undefined1 *)(lVar4 + -0x45) = 0xe0;
    lVar4 = *(longlong *)(lVar3 + 0xb8);
    *(undefined2 *)(lVar4 + -0x48) = 0x90f;
    *(undefined8 *)(lVar4 + -0x20) = param_2;
    *(undefined8 *)(lVar4 + -0x18) = param_1;
    *(undefined4 *)(lVar4 + -0x40) = param_4;
    *(longlong *)(lVar4 + -0x38) = lVar2;
    uVar1 = IofCallDriver(param_2,lVar3);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      uVar5 = (ulonglong)CONCAT31((int3)(*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 8),(char)param_8) &
              0xfffffffffffffff0;
      pcVar6 = "MCast";
      if ((char)uVar5 != -0x20) {
        pcVar6 = "Unicast";
      }
      WPP_SF_sDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,(ulonglong)param_9,pcVar6,
                  (char)param_8,(char)param_9,uVar1);
    }
  }
  return 0x103;
}



===== TdiSendDatagramCompletion @ 14001fee0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 TdiSendDatagramCompletion(undefined8 param_1,longlong param_2,longlong param_3)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
    WPP_SF_DDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
               &WPP_bb24dc9f99d8356a0c4778f616204a55_Traceguids,*(undefined4 *)(param_2 + 0x30),
               (char)*(undefined4 *)(param_2 + 0x38),(char)param_2);
  }
  (**(code **)(param_3 + 0x48))
            (*(undefined8 *)(param_3 + 0x50),*(undefined8 *)(param_3 + 0x58),
             *(undefined4 *)(param_2 + 0x30));
  if (*(char *)(param_3 + 0x60) != '\0') {
    MmUnlockPages(*(undefined8 *)(param_2 + 8));
  }
  ExFreeToNPagedLookasideList(&DAT_140025dc0,param_3);
  IoFreeMdl(*(undefined8 *)(param_2 + 8));
  IoFreeIrp(param_2);
  return 0xc0000016;
}



===== TdiSetEventHandler @ 14001ffa8 =====

int TdiSetEventHandler(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
                      undefined8 param_5)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  lVar2 = IoGetRelatedDeviceObject(param_2);
  lVar2 = IoAllocateIrp(*(undefined1 *)(lVar2 + 0x4c),0);
  if (lVar2 == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      lVar2 = IoGetRelatedDeviceObject(param_2);
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_bb24dc9f99d8356a0c4778f616204a55_Traceguids,(int)*(char *)(lVar2 + 0x4c));
    }
    iVar1 = -0x3fffff66;
  }
  else {
    lVar4 = *(longlong *)(lVar2 + 0xb8);
    uVar5 = 0;
    *(undefined8 *)(lVar4 + -0x10) = 0;
    *(undefined8 *)(lVar4 + -8) = 0;
    *(undefined1 *)(lVar4 + -0x45) = 0;
    lVar4 = *(longlong *)(lVar2 + 0xb8);
    *(undefined2 *)(lVar4 + -0x48) = 0xb0f;
    *(undefined8 *)(lVar4 + -0x20) = param_1;
    *(undefined8 *)(lVar4 + -0x18) = param_2;
    *(undefined4 *)(lVar4 + -0x40) = param_3;
    *(undefined8 *)(lVar4 + -0x38) = param_4;
    *(undefined8 *)(lVar4 + -0x30) = param_5;
    KeInitializeEvent(&local_28,0);
    lVar4 = *(longlong *)(lVar2 + 0xb8);
    *(code **)(lVar4 + -0x10) = PgmTdiCompletionRoutine;
    *(undefined8 **)(lVar4 + -8) = &local_28;
    *(undefined1 *)(lVar4 + -0x45) = 0xe0;
    uVar3 = IoGetRelatedDeviceObject(param_2);
    lVar4 = lVar2;
    iVar1 = IofCallDriver(uVar3);
    if (iVar1 == 0x103) {
      uVar5 = 0;
      lVar4 = 0;
      iVar1 = KeWaitForSingleObject(&local_28,0,0,0,0);
      if (-1 < iVar1) {
        iVar1 = *(int *)(lVar2 + 0x30);
      }
    }
    IoFreeIrp(lVar2);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      WPP_SF_ddq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar4,uVar5,iVar1,(char)param_3,
                 (char)param_4);
    }
  }
  return iVar1;
}



===== WPP_SF_Dddd @ 14002017c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dddd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_bb24dc9f99d8356a0c4778f616204a55_Traceguids,0x27,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_ddq @ 1400201ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ddq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_bb24dc9f99d8356a0c4778f616204a55_Traceguids,0xc,local_res20,4,
             &param_5,4,&param_6,8,0);
  return;
}



===== WPP_SF_qDq @ 140020254 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_bb24dc9f99d8356a0c4778f616204a55_Traceguids,0x16,&local_res20,8,
             &param_5,4,&param_6,8,0);
  return;
}



===== WPP_SF_sDDD @ 1400202bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sDDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_4[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_bb24dc9f99d8356a0c4778f616204a55_Traceguids,0x1d,param_4,lVar2,
             &param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== GetRandomData @ 140020364 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void GetRandomData(longlong param_1,ulonglong param_2)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong *plVar7;
  longlong local_res18 [2];
  
  uVar6 = param_2 & 0xffffffff;
  cVar1 = KeGetCurrentIrql();
  if (((cVar1 == '\0') && (uVar3 = PgmFipsInitialize(), (char)uVar3 != '\0')) &&
     (iVar2 = (*DAT_140025d68)(param_1), iVar2 != 0)) {
    return;
  }
  do {
    plVar7 = local_res18;
    local_res18[0] = _DAT_fffff78000000014 >> 4;
    uVar4 = 0;
    do {
      uVar5 = (int)uVar6 - 1;
      uVar6 = (ulonglong)uVar5;
      *(char *)(uVar6 + param_1) = (char)*plVar7;
      if (uVar5 == 0) {
        return;
      }
      uVar4 = uVar4 + 1;
      plVar7 = (longlong *)((longlong)plVar7 + 1);
    } while (uVar4 < 4);
  } while( true );
}



===== GetRandomInteger @ 1400203e8 =====

uint GetRandomInteger(uint param_1,uint param_2)

{
  uint local_res8 [2];
  
  local_res8[0] = 0;
  if (param_1 < param_2) {
    GetRandomData((longlong)local_res8,4);
    param_1 = param_1 + local_res8[0] % ((param_2 - param_1) + 1);
  }
  return param_1;
}



===== PgmExecuteWorker @ 140020440 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PgmExecuteWorker(longlong param_1)

{
  undefined1 uVar1;
  
  (**(code **)(param_1 + 0x30))
            (*(undefined8 *)(param_1 + 0x38),*(undefined8 *)(param_1 + 0x40),
             *(undefined8 *)(param_1 + 0x48));
  ExFreePoolWithTag(param_1,0);
  uVar1 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
  DAT_14003675c = DAT_14003675c + -1;
  if ((DAT_14003675c == 0) && ((DAT_140036758 & 1) != 0)) {
    KeReleaseSpinLock(&DAT_140036808,uVar1);
    KeSetEvent(&DAT_1400367f0,0,0);
    return;
  }
  KeReleaseSpinLock(&DAT_140036808,uVar1);
  return;
}



===== PgmQueueForDelayedExecution @ 1400204e4 =====

undefined8
PgmQueueForDelayedExecution
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,char param_5)

{
  code *pcVar1;
  undefined1 uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar2 = 0;
  uVar5 = 0xc000009a;
  if (param_5 == '\0') {
    uVar2 = KeAcquireSpinLockRaiseToDpc(&DAT_140036808);
  }
  puVar3 = (undefined8 *)ExAllocatePool2(0x40,0x50,0x326d6750);
  puVar6 = auStack_28;
  puVar7 = auStack_28;
  if (puVar3 != (undefined8 *)0x0) {
    puVar4 = puVar3 + 4;
    puVar3[5] = puVar4;
    *puVar4 = puVar4;
    puVar3[9] = 0;
    puVar3[7] = param_2;
    puVar3[8] = param_3;
    puVar3[6] = param_1;
    if ((DAT_140036758 & 1) == 0) {
      DAT_14003675c = DAT_14003675c + 1;
      *puVar3 = 0;
      puVar3[2] = PgmExecuteWorker;
      puVar3[3] = puVar3;
      ExQueueWorkItem(puVar3,1);
      puVar6 = auStack_28;
    }
    else {
      puVar3 = &DAT_140036730;
      if ((undefined8 *)*DAT_140036738 != &DAT_140036730) {
        puVar3 = (undefined8 *)0x3;
        pcVar1 = (code *)swi(0x29);
        DAT_140036738 = (undefined8 *)(*pcVar1)();
        puVar6 = auStack_20;
      }
      *puVar4 = puVar3;
      puVar4[1] = DAT_140036738;
      *DAT_140036738 = puVar4;
      DAT_140036738 = puVar4;
    }
    uVar5 = 0;
    puVar7 = puVar6;
  }
  if (puVar7[0x50] == '\0') {
    *(undefined8 *)(puVar7 + -8) = 0x1400205e4;
    KeReleaseSpinLock(&DAT_140036808,uVar2);
  }
  return uVar5;
}



===== _guard_check_icall @ 140020620 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140020638 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14002065c =====

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



===== __cpu_features_init @ 1400206d0 =====

/* WARNING: Removing unreachable block (ram,0x00014002073a) */
/* WARNING: Removing unreachable block (ram,0x0001400206e9) */
/* WARNING: Removing unreachable block (ram,0x0001400206da) */

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



===== tcpxsum @ 1400207a0 =====

int tcpxsum(ushort param_1,ulonglong *param_2,uint param_3)

{
  ulonglong uVar1;
  ushort uVar2;
  ulonglong uVar3;
  uint uVar4;
  ulonglong uVar5;
  uint uVar6;
  uint uVar7;
  ulonglong *puVar8;
  bool bVar9;
  bool bVar10;
  
  uVar3 = 0;
  if (param_3 == 0) goto LAB_1400208d1;
  puVar8 = param_2;
  if (((ulonglong)param_2 & 1) == 0) {
LAB_1400207d8:
    uVar4 = param_3 >> 1;
    uVar5 = (ulonglong)uVar4;
    if (((param_3 & 1) == 0) ||
       (uVar3 = CONCAT71((int7)(uVar3 >> 8),(char)*(ushort *)((longlong)puVar8 + uVar5 * 2)),
       uVar4 != 0)) {
joined_r0x0001400207ea:
      if (((ulonglong)puVar8 & 6) != 0) goto LAB_1400207ec;
      if (uVar4 >> 2 != 0) {
        uVar7 = uVar4 >> 6;
        bVar9 = false;
        uVar6 = uVar4 >> 2 & 0xf;
        if (uVar6 == 0) goto LAB_140020840;
        puVar8 = puVar8 + ((ulonglong)uVar6 - 0x10);
        bVar10 = 0xfffffffe < uVar7;
        uVar7 = uVar7 + 1;
        switch(uVar6) {
        case 2:
          goto switchD_140020836_caseD_2;
        case 3:
          goto switchD_140020836_caseD_3;
        case 4:
          goto switchD_140020836_caseD_4;
        case 5:
          goto switchD_140020836_caseD_5;
        case 6:
          goto switchD_140020836_caseD_6;
        case 7:
          goto switchD_140020836_caseD_7;
        case 8:
          goto switchD_140020836_caseD_8;
        case 9:
          goto switchD_140020836_caseD_9;
        case 10:
          goto switchD_140020836_caseD_a;
        case 0xb:
          goto switchD_140020836_caseD_b;
        case 0xc:
          goto switchD_140020836_caseD_c;
        case 0xd:
          goto switchD_140020836_caseD_d;
        case 0xe:
          goto switchD_140020836_caseD_e;
        case 0xf:
          goto switchD_140020836_caseD_f;
        }
        while( true ) {
          uVar5 = uVar3 + puVar8[0xf];
          bVar9 = CARRY8(uVar3,puVar8[0xf]) || CARRY8(uVar5,(ulonglong)bVar10);
          uVar3 = uVar5 + bVar10;
          puVar8 = puVar8 + 0x10;
          uVar7 = uVar7 - 1;
          if (uVar7 == 0) break;
LAB_140020840:
          bVar10 = CARRY8(uVar3,*puVar8) || CARRY8(uVar3 + *puVar8,(ulonglong)bVar9);
          uVar3 = uVar3 + *puVar8 + (ulonglong)bVar9;
switchD_140020836_caseD_f:
          uVar5 = (ulonglong)bVar10;
          uVar1 = uVar3 + puVar8[1];
          bVar10 = CARRY8(uVar3,puVar8[1]) || CARRY8(uVar1,uVar5);
          uVar3 = uVar1 + uVar5;
switchD_140020836_caseD_e:
          uVar5 = (ulonglong)bVar10;
          uVar1 = uVar3 + puVar8[2];
          bVar10 = CARRY8(uVar3,puVar8[2]) || CARRY8(uVar1,uVar5);
          uVar3 = uVar1 + uVar5;
switchD_140020836_caseD_d:
          uVar5 = (ulonglong)bVar10;
          uVar1 = uVar3 + puVar8[3];
          bVar10 = CARRY8(uVar3,puVar8[3]) || CARRY8(uVar1,uVar5);
          uVar3 = uVar1 + uVar5;
switchD_140020836_caseD_c:
          uVar5 = (ulonglong)bVar10;
          uVar1 = uVar3 + puVar8[4];
          bVar10 = CARRY8(uVar3,puVar8[4]) || CARRY8(uVar1,uVar5);
          uVar3 = uVar1 + uVar5;
switchD_140020836_caseD_b:
          uVar5 = (ulonglong)bVar10;
          uVar1 = uVar3 + puVar8[5];
          bVar10 = CARRY8(uVar3,puVar8[5]) || CARRY8(uVar1,uVar5);
          uVar3 = uVar1 + uVar5;
switchD_140020836_caseD_a:
          uVar5 = (ulonglong)bVar10;
          uVar1 = uVar3 + puVar8[6];
          bVar10 = CARRY8(uVar3,puVar8[6]) || CARRY8(uVar1,uVar5);
          uVar3 = uVar1 + uVar5;
switchD_140020836_caseD_9:
          uVar5 = (ulonglong)bVar10;
          uVar1 = uVar3 + puVar8[7];
          bVar10 = CARRY8(uVar3,puVar8[7]) || CARRY8(uVar1,uVar5);
          uVar3 = uVar1 + uVar5;
switchD_140020836_caseD_8:
          uVar5 = (ulonglong)bVar10;
          uVar1 = uVar3 + puVar8[8];
          bVar10 = CARRY8(uVar3,puVar8[8]) || CARRY8(uVar1,uVar5);
          uVar3 = uVar1 + uVar5;
switchD_140020836_caseD_7:
          uVar5 = (ulonglong)bVar10;
          uVar1 = uVar3 + puVar8[9];
          bVar10 = CARRY8(uVar3,puVar8[9]) || CARRY8(uVar1,uVar5);
          uVar3 = uVar1 + uVar5;
switchD_140020836_caseD_6:
          uVar5 = (ulonglong)bVar10;
          uVar1 = uVar3 + puVar8[10];
          bVar10 = CARRY8(uVar3,puVar8[10]) || CARRY8(uVar1,uVar5);
          uVar3 = uVar1 + uVar5;
switchD_140020836_caseD_5:
          uVar5 = (ulonglong)bVar10;
          uVar1 = uVar3 + puVar8[0xb];
          bVar10 = CARRY8(uVar3,puVar8[0xb]) || CARRY8(uVar1,uVar5);
          uVar3 = uVar1 + uVar5;
switchD_140020836_caseD_4:
          uVar5 = (ulonglong)bVar10;
          uVar1 = uVar3 + puVar8[0xc];
          bVar10 = CARRY8(uVar3,puVar8[0xc]) || CARRY8(uVar1,uVar5);
          uVar3 = uVar1 + uVar5;
switchD_140020836_caseD_3:
          uVar5 = (ulonglong)bVar10;
          uVar1 = uVar3 + puVar8[0xd];
          bVar10 = CARRY8(uVar3,puVar8[0xd]) || CARRY8(uVar1,uVar5);
          uVar3 = uVar1 + uVar5;
switchD_140020836_caseD_2:
          uVar5 = (ulonglong)bVar10;
          uVar1 = uVar3 + puVar8[0xe];
          bVar10 = CARRY8(uVar3,puVar8[0xe]) || CARRY8(uVar1,uVar5);
          uVar3 = uVar1 + uVar5;
        }
        uVar3 = uVar3 + bVar9;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        uVar3 = CONCAT62((int6)(uVar3 >> 0x10),
                         (ushort)uVar3 + (ushort)*puVar8 +
                         (ushort)CARRY2((ushort)uVar3,(ushort)*puVar8));
        puVar8 = (ulonglong *)((longlong)puVar8 + 2);
      }
    }
  }
  else {
    uVar3 = (ulonglong)(byte)*param_2 << 8;
    puVar8 = (ulonglong *)((longlong)param_2 + 1);
    param_3 = param_3 - 1;
    if (param_3 != 0) goto LAB_1400207d8;
  }
LAB_1400208af:
  uVar4 = (uint)(uVar3 + (uVar3 >> 0x20 | uVar3 << 0x20) >> 0x20);
  uVar4 = uVar4 + (uVar4 >> 0x10 | uVar4 << 0x10);
  uVar3 = (ulonglong)(uVar4 >> 0x10);
  if (((ulonglong)param_2 & 1) != 0) {
    uVar2 = (ushort)(uVar4 >> 0x10);
    uVar3 = (ulonglong)(ushort)(uVar2 >> 8 | uVar2 << 8);
  }
LAB_1400208d1:
  return (uint)(ushort)((ushort)uVar3 + param_1) + (uint)CARRY2((ushort)uVar3,param_1);
LAB_1400207ec:
  uVar3 = (ulonglong)
          ((int)CONCAT62((int6)(uVar3 >> 0x10),(ushort)uVar3 + (ushort)*puVar8) +
          (uint)CARRY2((ushort)uVar3,(ushort)*puVar8));
  puVar8 = (ulonglong *)((longlong)puVar8 + 2);
  uVar4 = (int)uVar5 - 1;
  uVar5 = (ulonglong)uVar4;
  if (uVar4 == 0) goto LAB_1400208af;
  goto joined_r0x0001400207ea;
}



===== __security_check_cookie @ 1400208f0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140020930 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140020960 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140020960. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140020990 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 1400209e0 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_140020a23;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_140020a94;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_140020a90:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140020a94;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_140020a8c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140020a90;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140020a8c;
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
LAB_140020a94:
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
LAB_140020a23:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memmove @ 140020b00 =====

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



===== memset @ 140020e00 =====

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



===== __memset_repmovs @ 140020f40 =====

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



===== __memset_query @ 140020fc0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140021040 =====

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



===== __memset_spec_ermsb_repmovsb @ 140021180 =====

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



===== __memset_spec_plain @ 140021200 =====

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



===== wil_RtlStagingConfig_QueryFeatureState @ 14003b008 =====

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



===== PgmCreateConnection @ 14003b0d4 =====

undefined8
PgmCreateConnection(undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4)

{
  undefined8 uVar1;
  longlong lVar2;
  
  if (*(ushort *)(param_4 + 6) < 8) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                &WPP_ffb0ebbf543c30978a27a610893f40c5_Traceguids,(uint)*(ushort *)(param_4 + 6),8);
    }
    uVar1 = 0xc0000207;
  }
  else {
    lVar2 = ExAllocatePool2(0x40,0x1a8,0x306d6750);
    if (lVar2 == 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                 &WPP_ffb0ebbf543c30978a27a610893f40c5_Traceguids,0x1a8);
      }
      uVar1 = 0xc000009a;
    }
    else {
      *(longlong *)(lVar2 + 8) = lVar2;
      *(longlong *)lVar2 = lVar2;
      KeInitializeSpinLock(lVar2 + 0x168);
      *(int *)(lVar2 + 0x14) = *(int *)(lVar2 + 0x14) + 1;
      *(undefined4 *)(lVar2 + 0x10) = 0x30534553;
      uVar1 = PsGetCurrentProcess();
      *(undefined8 *)(lVar2 + 0x48) = uVar1;
      *(undefined8 *)(lVar2 + 0x50) =
           *(undefined8 *)((ulonglong)*(byte *)(param_4 + 5) + 9 + param_4);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                  &WPP_ffb0ebbf543c30978a27a610893f40c5_Traceguids,lVar2,
                  (char)*(undefined8 *)((ulonglong)*(byte *)(param_4 + 5) + 9 + param_4));
      }
      ExInterlockedInsertTailList(&DAT_1400366f0,lVar2,&DAT_140036808);
      *(longlong *)(*(longlong *)(param_3 + 0x30) + 0x18) = lVar2;
      *(undefined8 *)(*(longlong *)(param_3 + 0x30) + 0x20) = 2;
      uVar1 = 0;
    }
  }
  return uVar1;
}



===== PgmUnload @ 14003b270 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PgmUnload(void)

{
  undefined *puVar1;
  
  DAT_140036758 = DAT_140036758 | 1;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
            &WPP_80756061d1e530076809262fec60bbbb_Traceguids);
  }
  CleanupInit(7);
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



===== WppInitKm @ 14003b328 =====

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



===== WppLoadTracingSupport @ 14003b3b8 =====

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



===== WppTraceCallback @ 14003b500 =====

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



===== wil_UninitializeFeatureStaging @ 14003b788 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 14003b7e0 =====

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
      goto LAB_14003b83d;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_14003b83d;
    }
  }
  uVar1 = 0x206;
LAB_14003b83d:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 14003b848 =====

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



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14003b900 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 14003b938 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_14003b9ba;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_14003b9ba;
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
LAB_14003b9ba:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14003ba10 =====

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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14003ba70 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14003ba8c =====

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



===== BuildPgmDataFileName @ 14003bb40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 BuildPgmDataFileName(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  uint uVar4;
  wchar_t *pwVar5;
  ushort uVar6;
  undefined1 auStack_68 [32];
  ushort local_48 [4];
  undefined8 local_40;
  undefined1 *puStack_38;
  undefined1 local_30 [24];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_40 = 0;
  puStack_38 = (undefined1 *)0x0;
  if ((*(uint *)(pPgmRegistryConfig + 4) & 1) == 0) {
    uVar6 = 0x15;
  }
  else {
    uVar6 = *(ushort *)(pPgmRegistryConfig + 8) >> 1;
  }
  uVar6 = uVar6 + 0xe;
  lVar2 = ExAllocatePool2(0x40,(ulonglong)uVar6 * 2,0x326d6750);
  *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x18) = lVar2;
  lVar1 = pPgmRegistryConfig;
  if (lVar2 == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_0e4477596d4f3af6adc990aa583f3876_Traceguids,(uint)uVar6);
    }
    uVar3 = 0xc000009a;
  }
  else {
    *(ushort *)(*(longlong *)(param_1 + 0x28) + 0x12) = uVar6 * 2;
    *(undefined2 *)(*(longlong *)(param_1 + 0x28) + 0x10) = 0;
    if ((*(uint *)(lVar1 + 4) & 1) == 0) {
      pwVar5 = L"\\SystemRoot\\System32";
    }
    else {
      pwVar5 = *(wchar_t **)(lVar1 + 0x10);
    }
    RtlAppendUnicodeToString(*(longlong *)(param_1 + 0x28) + 0x10,pwVar5);
    RtlAppendUnicodeToString(*(longlong *)(param_1 + 0x28) + 0x10,L"\\T");
    local_40._0_4_ = CONCAT22(0x14,(undefined2)local_40);
    puStack_38 = local_30;
    uVar4 = (uint)*(ushort *)(param_1 + 0x46) + (*(ushort *)(param_1 + 0x46) / 100) * -100;
    local_48[0] = (ushort)uVar4;
    if (local_48[0] < 10) {
      RtlAppendUnicodeToString(*(longlong *)(param_1 + 0x28) + 0x10,L"0");
      uVar4 = (uint)local_48[0];
    }
    RtlIntegerToUnicodeString(uVar4 & 0xffff,10,&local_40);
    RtlAppendUnicodeStringToString(*(longlong *)(param_1 + 0x28) + 0x10,&local_40);
    GetRandomData((longlong)local_48,2);
    RtlIntegerToUnicodeString(local_48[0],10,&local_40);
    RtlAppendUnicodeStringToString(*(longlong *)(param_1 + 0x28) + 0x10,&local_40);
    RtlAppendUnicodeToString(*(longlong *)(param_1 + 0x28) + 0x10,L".PGM");
    uVar3 = 0;
  }
  return uVar3;
}



===== PgmCreateDataFileAndMapSection @ 14003bd4c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PgmCreateDataFileAndMapSection(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined2 uVar6;
  longlong lVar7;
  bool bVar8;
  undefined1 auStackY_118 [32];
  longlong local_b8 [8];
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_118;
  local_b8[1] = 0;
  local_b8[2] = 0;
  local_b8[3] = 0;
  local_b8[4] = 0;
  local_b8[5] = 0;
  local_b8[6] = local_b8[6] & 0xffffffff00000000;
  local_70 = 0;
  uStack_68 = 0;
  local_78 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  lVar2 = PsGetCurrentProcess();
  bVar8 = lVar2 != PgmStaticConfig;
  if (bVar8) {
    KeStackAttachProcess();
  }
  uVar3 = BuildPgmDataFileName(param_2);
  uVar4 = uVar3 & 0xffffffff;
  if ((int)uVar3 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_0e4477596d4f3af6adc990aa583f3876_Traceguids,(int)uVar3);
    }
LAB_14003be2d:
    if (bVar8) {
      KeUnstackDetachProcess(&local_60);
    }
    return uVar4;
  }
  lVar2 = *(longlong *)(param_2 + 0x18);
  uVar3 = *(ulonglong *)(lVar2 + 0x118) / (ulonglong)*(uint *)(lVar2 + 0xf8);
  if (*(byte *)(param_2 + 0xa0) < 2) {
    lVar7 = -(uVar3 >> 2);
  }
  else {
    lVar7 = (ulonglong)*(byte *)(param_2 + 0xa0) - 1;
  }
  uVar3 = uVar3 * 2 + lVar7;
  if (0x7fffffff < uVar3) {
    uVar3 = 0x7fffffff;
    uVar4 = (ulonglong)*(uint *)(lVar2 + 0xf8) * 0x3fffffff;
    if (uVar4 < *(ulonglong *)(lVar2 + 0x118)) {
      *(ulonglong *)(lVar2 + 0x118) = uVar4;
      lVar2 = *(longlong *)(param_2 + 0x18);
      *(ulonglong *)(lVar2 + 0x120) =
           (ulonglong)(*(longlong *)(lVar2 + 0x118) << 3) / *(ulonglong *)(lVar2 + 0x110);
    }
  }
  uVar1 = *(uint *)(*(longlong *)(param_2 + 0x28) + 0x6c);
  uVar3 = uVar1 * uVar3;
  uVar3 = uVar3 - uVar3 % (ulonglong)(uVar1 * *(byte *)(param_2 + 0xa0));
  *(ulonglong *)(*(longlong *)(param_2 + 0x28) + 0x58) = uVar3;
  *(ulonglong *)(*(longlong *)(param_2 + 0x28) + 0x60) =
       uVar3 / *(uint *)(*(longlong *)(param_2 + 0x28) + 0x6c);
  local_b8[7] = uVar3;
  uVar5 = InitRDataInfo(param_1,param_2);
  uVar4 = uVar5 & 0xffffffff;
  if ((int)uVar5 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
               &WPP_0e4477596d4f3af6adc990aa583f3876_Traceguids,(int)uVar5);
    }
    ExFreePoolWithTag(*(undefined8 *)(*(longlong *)(param_2 + 0x28) + 0x18),0);
    *(undefined8 *)(*(longlong *)(param_2 + 0x28) + 0x18) = 0;
    goto LAB_14003be2d;
  }
  local_b8[0] = 0;
  uVar1 = PgmBuildAdminSecurityDescriptor(local_b8);
  lVar2 = local_b8[0];
  if ((int)uVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_0e4477596d4f3af6adc990aa583f3876_Traceguids,uVar1);
    }
    goto LAB_14003c242;
  }
  local_b8[3] = *(longlong *)(param_2 + 0x28) + 0x10;
  local_b8[1] = 0x30;
  local_b8[4] = 0x240;
  local_b8[2] = 0;
  local_b8[5] = local_b8[0];
  local_b8[6] = 0;
  uVar1 = ZwCreateFile(*(longlong *)(param_2 + 0x28) + 0x38,0x10003,local_b8 + 1,&local_70);
  if ((int)uVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) goto LAB_14003c242;
    uVar6 = 0xe;
  }
  else {
    local_b8[1] = 0x30;
    local_b8[4] = 0x240;
    local_b8[2] = 0;
    local_b8[3] = 0;
    local_b8[5] = 0;
    local_b8[6] = 0;
    uVar1 = ZwCreateSection(*(longlong *)(param_2 + 0x28) + 0x40,0xf0007,local_b8 + 1,local_b8 + 7);
    if ((int)uVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) goto LAB_14003c242;
      uVar6 = 0xf;
    }
    else {
      lVar7 = *(longlong *)(param_2 + 0x28);
      local_b8[0] = 0;
      uVar1 = ObReferenceObjectByHandle(*(undefined8 *)(lVar7 + 0x40),0,0,0);
      *(longlong *)(lVar7 + 0x48) = local_b8[0];
      if ((int)uVar1 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                    &WPP_0e4477596d4f3af6adc990aa583f3876_Traceguids,
                    *(undefined8 *)(*(longlong *)(param_2 + 0x28) + 0x40),(char)uVar1);
        }
        goto LAB_14003c242;
      }
      lVar7 = *(longlong *)(param_2 + 0x28) + 0x50;
      uVar1 = ZwMapViewOfSection(*(undefined8 *)(*(longlong *)(param_2 + 0x28) + 0x40),
                                 0xffffffffffffffff,lVar7,0);
      if (-1 < (int)uVar1) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_Zqi(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),WPP_GLOBAL_Control,lVar7,
                     (wchar_t *)(*(longlong *)(param_2 + 0x28) + 0x10),
                     (char)*(undefined8 *)(*(longlong *)(param_2 + 0x28) + 0x50),(char)uVar3);
        }
        *(undefined8 *)(*(longlong *)(param_2 + 0x28) + 0x78) =
             *(undefined8 *)(*(longlong *)(param_2 + 0x28) + 0x58);
        *(undefined4 *)(*(longlong *)(param_2 + 0x28) + 0x74) =
             *(undefined4 *)(*(longlong *)(param_2 + 0x28) + 0x60);
        *(undefined8 *)(*(longlong *)(param_2 + 0x28) + 0x88) = 0;
        *(undefined8 *)(*(longlong *)(param_2 + 0x28) + 0x80) = 0;
        ObfReferenceObject(*(undefined8 *)(param_2 + 0x48));
        if (bVar8) {
          KeUnstackDetachProcess(&local_60);
        }
        ExFreePoolWithTag(lVar2,0);
        return 0;
      }
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) goto LAB_14003c242;
      uVar6 = 0x11;
    }
  }
  WPP_SF_ZD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
            &WPP_0e4477596d4f3af6adc990aa583f3876_Traceguids,
            (wchar_t *)(*(longlong *)(param_2 + 0x28) + 0x10),(char)uVar1);
LAB_14003c242:
  if (*(longlong *)(*(longlong *)(param_2 + 0x28) + 0x48) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(*(longlong *)(param_2 + 0x28) + 0x48) = 0;
  }
  if (*(longlong *)(*(longlong *)(param_2 + 0x28) + 0x40) != 0) {
    ZwClose();
    *(undefined8 *)(*(longlong *)(param_2 + 0x28) + 0x40) = 0;
  }
  if (*(longlong *)(*(longlong *)(param_2 + 0x28) + 0x38) != 0) {
    ZwClose();
    *(undefined8 *)(*(longlong *)(param_2 + 0x28) + 0x38) = 0;
  }
  if (lVar2 != 0) {
    ExFreePoolWithTag(lVar2,0);
  }
  if (bVar8) {
    KeUnstackDetachProcess(&local_60);
  }
  ExFreePoolWithTag(*(undefined8 *)(*(longlong *)(param_2 + 0x28) + 0x18),0);
  *(undefined8 *)(*(longlong *)(param_2 + 0x28) + 0x18) = 0;
  DestroyRDataInfo(param_2);
  return (ulonglong)uVar1;
}



===== PgmUnmapAndCloseDataFile @ 14003c3d8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 PgmUnmapAndCloseDataFile(longlong param_1)

{
  longlong lVar1;
  bool bVar2;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  DestroyRDataInfo(param_1);
  lVar1 = PsGetCurrentProcess();
  bVar2 = lVar1 != PgmStaticConfig;
  if (bVar2) {
    KeStackAttachProcess(PgmStaticConfig,&local_48);
  }
  ZwUnmapViewOfSection(0xffffffffffffffff,*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x50));
  ObfDereferenceObject(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x48));
  *(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x48) = 0;
  ZwClose(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x40));
  *(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x40) = 0;
  ZwClose(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x38));
  if (bVar2) {
    KeUnstackDetachProcess(&local_48);
  }
  ObfDereferenceObject(*(undefined8 *)(param_1 + 0x48));
  *(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x50) = 0;
  *(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x48) = 0;
  *(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x40) = 0;
  *(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x38) = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
             &WPP_0e4477596d4f3af6adc990aa583f3876_Traceguids,param_1);
  }
  return 0;
}



===== InitDynamicPgmConfig @ 14003c540 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 InitDynamicPgmConfig(void)

{
  memset(&PgmDynamicConfig,0,0x170);
  DAT_1400366a8 = &PgmDynamicConfig;
  DAT_1400366b8 = &DAT_1400366b0;
  DAT_1400366b0 = &DAT_1400366b0;
  PgmDynamicConfig = &PgmDynamicConfig;
  _DAT_1400366c8 = &DAT_1400366c0;
  DAT_1400366c0 = &DAT_1400366c0;
  DAT_1400366d8 = &DAT_1400366d0;
  _DAT_1400366d0 = &DAT_1400366d0;
  DAT_140036718 = &DAT_140036710;
  DAT_140036710 = &DAT_140036710;
  _DAT_1400366e8 = &DAT_1400366e0;
  _DAT_1400366e0 = &DAT_1400366e0;
  DAT_1400366f8 = &DAT_1400366f0;
  _DAT_1400366f0 = &DAT_1400366f0;
  DAT_140036708 = &DAT_140036700;
  _DAT_140036700 = &DAT_140036700;
  DAT_140036728 = &DAT_140036720;
  DAT_140036720 = &DAT_140036720;
  DAT_140036738 = &DAT_140036730;
  DAT_140036730 = &DAT_140036730;
  DAT_140036750 = 1;
  GetRandomData(0x140036766,2);
  DAT_140036766 = DAT_140036766 % 0x4651 + 2000;
  KeInitializeSpinLock(&DAT_140036808);
  KeInitializeEvent(&DAT_1400367f0,0,1);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
            &WPP_50b4bc983f2130f0a63faa089ac2dd69_Traceguids);
  }
  return 0;
}



===== InitPgm @ 14003c6d8 =====

ulonglong InitPgm(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  ulonglong uVar2;
  int iVar3;
  ulonglong uVar4;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  uVar2 = InitStaticPgmConfig(param_1,param_2);
  uVar4 = uVar2 & 0xffffffff;
  if ((int)uVar2 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
               &WPP_50b4bc983f2130f0a63faa089ac2dd69_Traceguids,(int)uVar2);
    }
  }
  else {
    uVar2 = InitDynamicPgmConfig();
    uVar4 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                 &WPP_50b4bc983f2130f0a63faa089ac2dd69_Traceguids,(int)uVar2);
      }
      iVar3 = 1;
    }
    else {
      uVar2 = PgmReadRegistryParameters(param_2,local_res18);
      uVar4 = uVar2 & 0xffffffff;
      if ((int)uVar2 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                   &WPP_50b4bc983f2130f0a63faa089ac2dd69_Traceguids,(int)uVar2);
        }
        iVar3 = 2;
      }
      else {
        pPgmRegistryConfig = local_res18[0];
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                  &WPP_50b4bc983f2130f0a63faa089ac2dd69_Traceguids);
        }
        uVar1 = PgmCreateDevice();
        uVar4 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return uVar4;
          }
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
            return uVar4;
          }
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
                  &WPP_50b4bc983f2130f0a63faa089ac2dd69_Traceguids);
          return uVar4;
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
                   &WPP_50b4bc983f2130f0a63faa089ac2dd69_Traceguids,uVar1);
        }
        iVar3 = 4;
      }
    }
    CleanupInit(iVar3);
  }
  return uVar4;
}



===== InitStaticPgmConfig @ 14003c888 =====

ulonglong InitStaticPgmConfig(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  memset(&PgmStaticConfig,0,0x140);
  uVar1 = PgmFipsInitialize();
  if ((((char)uVar1 == '\0') && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
            &WPP_50b4bc983f2130f0a63faa089ac2dd69_Traceguids);
  }
  PgmStaticConfig = PsGetCurrentProcess();
  DAT_140025d12 = *(ushort *)(param_2 + 2);
  DAT_140025d08 = param_1;
  DAT_140025d18 = ExAllocatePool2(0x40,*(undefined2 *)(param_2 + 2),0x306d6750);
  if (DAT_140025d18 == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
               &WPP_50b4bc983f2130f0a63faa089ac2dd69_Traceguids,(uint)DAT_140025d12);
    }
    if (DAT_140025d20 != 0) {
      DAT_140025da8 = 0;
      ObfDereferenceObject();
      DAT_140025d20 = 0;
    }
    uVar3 = 0xc000009a;
  }
  else {
    RtlCopyUnicodeString(&DAT_140025d10,param_2);
    ExInitializeNPagedLookasideList(&DAT_140025dc0,0,0,0x200,0x68,0x326d6750,100);
    uVar2 = FECInitGlobals();
    uVar3 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      ExDeleteNPagedLookasideList(&DAT_140025dc0);
      ExFreePoolWithTag(DAT_140025d18,0);
      if (DAT_140025d20 != 0) {
        DAT_140025da8 = 0;
        ObfDereferenceObject();
        DAT_140025d20 = 0;
      }
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
               &WPP_50b4bc983f2130f0a63faa089ac2dd69_Traceguids,(int)uVar2);
    }
  }
  return uVar3;
}



===== PgmCreateDevice @ 14003ca84 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PgmCreateDevice(void)

{
  ushort *puVar1;
  longlong *_Dst;
  int iVar2;
  ulonglong uVar3;
  undefined1 auStackY_88 [32];
  wchar_t local_48 [8];
  undefined8 local_38;
  undefined1 *puStack_30;
  undefined1 local_28 [24];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48[0] = L'\0';
  local_48[1] = L'\0';
  local_48[2] = L'\0';
  local_48[3] = L'\0';
  local_48[4] = L'\0';
  local_48[5] = L'\0';
  local_48[6] = L'\0';
  local_48[7] = L'\0';
  local_38 = 0;
  puStack_30 = (undefined1 *)0x0;
  RtlInitUnicodeString(local_48,L"\\Device\\Pgm");
  iVar2 = IoCreateDevice(DAT_140025d08,0x9e,local_48,0x12);
  if (iVar2 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_DZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                &WPP_50b4bc983f2130f0a63faa089ac2dd69_Traceguids,iVar2,local_48);
    }
    pgPgmDevice = (longlong *)0x0;
    return iVar2;
  }
  _Dst = *(longlong **)(pPgmDeviceObject + 0x40);
  memset(_Dst,0,0x9e);
  KeInitializeSpinLock(_Dst + 0xc);
  *(int *)(_Dst + 2) = (int)_Dst[2] + 1;
  puVar1 = (ushort *)(_Dst + 3);
  *(undefined4 *)((longlong)_Dst + 0xc) = 0x43564544;
  *_Dst = pPgmDeviceObject;
  _Dst[4] = (longlong)(_Dst + 0xe);
  *puVar1 = 0;
  *(undefined2 *)((longlong)_Dst + 0x1a) = 0x26;
  RtlAppendUnicodeToString(puVar1,L"\\Device\\RawIp");
  *(undefined2 *)(_Dst[4] + (ulonglong)(*puVar1 >> 1) * 2) = 0x5c;
  puStack_30 = local_28;
  *puVar1 = *puVar1 + 2;
  local_38._0_4_ = CONCAT22(0x14,(undefined2)local_38);
  RtlIntegerToUnicodeString(0x71,10,&local_38);
  RtlAppendUnicodeStringToString(puVar1,&local_38);
  KeInitializeEvent(_Dst + 9,0,0);
  iVar2 = PgmTdiOpenControl((longlong)_Dst);
  if (iVar2 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
               &WPP_50b4bc983f2130f0a63faa089ac2dd69_Traceguids,iVar2);
    }
  }
  else {
    *(char *)(pPgmDeviceObject + 0x4c) = *(char *)(_Dst[6] + 0x4c) + '\x01';
    uVar3 = Feature_2592016699__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar3 == 0) || (iVar2 = TdiRegisterDeviceObject(local_48,_Dst + 8), -1 < iVar2)) {
      *(uint *)(pPgmDeviceObject + 0x30) = *(uint *)(pPgmDeviceObject + 0x30) & 0xffffff7f;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        pgPgmDevice = _Dst;
        return iVar2;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
        pgPgmDevice = _Dst;
        return iVar2;
      }
      pgPgmDevice = _Dst;
      WPP_SF_DZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                &WPP_50b4bc983f2130f0a63faa089ac2dd69_Traceguids,iVar2,local_48);
      return iVar2;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
               &WPP_50b4bc983f2130f0a63faa089ac2dd69_Traceguids,iVar2);
    }
    ObfDereferenceObject(_Dst[7]);
    ZwClose(_Dst[5]);
    _Dst[7] = 0;
    _Dst[5] = 0;
  }
  IoDeleteDevice(pPgmDeviceObject);
  return iVar2;
}



===== PgmDereferenceDevice @ 14003cd90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PgmDereferenceDevice(void)

{
  int *piVar1;
  undefined8 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  bool bVar6;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  puVar2 = pgPgmDevice;
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  piVar1 = (int *)(pgPgmDevice + 2);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    if (puVar2[8] != 0) {
      uVar4 = Feature_2592016699__private_IsEnabledDeviceUsageNoInline();
      if (((((int)uVar4 != 0) &&
           (uVar3 = TdiDeregisterDeviceObject(puVar2[8]), (uVar3 & 0xc0000000) == 0xc0000000)) &&
          ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                 &WPP_50b4bc983f2130f0a63faa089ac2dd69_Traceguids,uVar3);
      }
      puVar2[8] = 0;
    }
    if (puVar2[5] != 0) {
      lVar5 = PsGetCurrentProcess();
      bVar6 = lVar5 != PgmStaticConfig;
      if (bVar6) {
        KeStackAttachProcess(PgmStaticConfig,&local_48);
      }
      ObfDereferenceObject(puVar2[7]);
      ZwClose(puVar2[5]);
      puVar2[7] = 0;
      puVar2[5] = 0;
      if (bVar6) {
        KeUnstackDetachProcess(&local_48);
      }
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
               &WPP_50b4bc983f2130f0a63faa089ac2dd69_Traceguids,pgPgmDevice);
    }
    IoDeleteDevice(*puVar2);
    pgPgmDevice = (undefined8 *)0x0;
  }
  return;
}



===== PgmFipsInitialize @ 14003cf1c =====

ulonglong PgmFipsInitialize(void)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 local_res8 [4];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_res8[0] = 0;
  uVar4 = 0;
  local_18 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (DAT_140025da8 == '\0') {
    RtlInitUnicodeString(&local_48,L"\\Device\\KsecDD");
    uVar2 = IoGetDeviceObjectPointer(&local_48,0x1f01ff,&DAT_140025d20,local_res8);
    if ((int)uVar2 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
        uVar2 = WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                         &WPP_50b4bc983f2130f0a63faa089ac2dd69_Traceguids,(int)uVar2);
      }
    }
    else {
      KeInitializeEvent(&local_28,1);
      lVar3 = IoBuildDeviceIoControlRequest
                        (0x390024,local_res8[0],0,0,&DAT_140025d28,0x80,0,&local_28,&local_38);
      if (lVar3 == 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_50b4bc983f2130f0a63faa089ac2dd69_Traceguids);
        }
      }
      else {
        uVar4 = IofCallDriver(local_res8[0],lVar3);
        iVar1 = (int)uVar4;
        if ((int)uVar4 == 0x103) {
          uVar4 = KeWaitForSingleObject(&local_28,0,0,0,0);
          iVar1 = (int)uVar4;
          if (iVar1 == 0) {
            iVar1 = (int)local_38;
            goto LAB_14003d0bf;
          }
        }
        else {
LAB_14003d0bf:
          if (iVar1 == 0) {
            DAT_140025da8 = '\x01';
            goto LAB_14003d0ff;
          }
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_50b4bc983f2130f0a63faa089ac2dd69_Traceguids,iVar1);
        }
      }
      uVar2 = ObfDereferenceObject(DAT_140025d20);
    }
    DAT_140025d20 = 0;
    uVar2 = uVar2 & 0xffffffffffffff00;
  }
  else {
LAB_14003d0ff:
    uVar2 = CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
  }
  return uVar2;
}



===== PgmReadRegistryParameters @ 14003d114 =====

undefined8 PgmReadRegistryParameters(undefined8 param_1,longlong *param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res20 = 0;
  local_res18 = 0;
  lVar2 = ExAllocatePool2(0x40,0x20,0x306d6750);
  if (lVar2 == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
               &WPP_50b4bc983f2130f0a63faa089ac2dd69_Traceguids,0x20);
    }
    uVar3 = 0xc000009a;
  }
  else {
    *param_2 = lVar2;
    puVar4 = &local_res20;
    iVar1 = PgmOpenRegistryParameters(param_1,puVar4,&local_res18);
    if (iVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                 &WPP_50b4bc983f2130f0a63faa089ac2dd69_Traceguids,iVar1);
      }
    }
    else {
      iVar1 = ReadRegistryStringValue(local_res18,(ulonglong)puVar4,lVar2 + 8);
      if (-1 < iVar1) {
        *(uint *)(lVar2 + 4) = *(uint *)(lVar2 + 4) | 1;
      }
      iVar1 = ReadRegistryDwordValue(local_res18,L"MaxSPMInterval",(undefined4 *)(lVar2 + 0x18));
      if (iVar1 < 0) {
        *(undefined4 *)(lVar2 + 0x18) = 300000;
      }
      else if (7200000 < *(uint *)(lVar2 + 0x18)) {
        *(undefined4 *)(lVar2 + 0x18) = 7200000;
      }
      iVar1 = ReadRegistryDwordValue(local_res18,L"MaxPacketSize",&ConfiguredMaxPacketSize);
      if (-1 < iVar1) {
        uVar5 = (ulonglong)ConfiguredMaxPacketSize * 0x400;
        if (0xffffffff < uVar5) {
          uVar5 = 0xffff;
        }
        ConfiguredMaxPacketSize = (uint)uVar5;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                   &WPP_50b4bc983f2130f0a63faa089ac2dd69_Traceguids,ConfiguredMaxPacketSize);
        }
      }
      ZwClose(local_res18);
      ZwClose(local_res20);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                &WPP_50b4bc983f2130f0a63faa089ac2dd69_Traceguids);
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}



===== SetTdiHandlers @ 14003d304 =====

int SetTdiHandlers(void)

{
  int iVar1;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined2 local_48;
  undefined4 local_46;
  undefined2 local_42;
  undefined8 *local_40;
  code *local_38;
  code *local_30;
  undefined8 local_28;
  code *local_20;
  code *local_18;
  
  local_46 = 0;
  local_42 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_28 = 0;
  RtlInitUnicodeString(&local_58,L"Pgm");
  local_46 = 0;
  local_58._0_4_ = CONCAT22(8,(undefined2)local_58);
  local_40 = &local_58;
  local_42 = 0;
  local_28 = 0;
  local_20 = TdiAddressArrival;
  local_48 = 2;
  local_18 = TdiAddressDeletion;
  local_30 = TdiBindHandler;
  local_38 = TdiPnPPowerHandler;
  iVar1 = TdiRegisterPnPHandlers(&local_48,0x38,&TdiClientHandle);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
               &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids,iVar1);
    }
  }
  else {
    TdiEnumerateAddresses(TdiClientHandle);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,
              &WPP_791a6c6e56613b57eca01dfd1623efe8_Traceguids);
    }
  }
  return iVar1;
}



===== PgmBuildAdminSecurityDescriptor @ 14003d440 =====

int PgmBuildAdminSecurityDescriptor(longlong *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  void *_Src;
  longlong lVar7;
  uint uVar8;
  undefined4 local_res10 [2];
  
  local_res10[0] = 0x10000000;
  uVar6 = IoGetFileObjectGenericMapping();
  RtlMapGenericMask(local_res10,uVar6);
  lVar7 = *(longlong *)SeExports_exref;
  uVar6 = *(undefined8 *)(lVar7 + 0x188);
  uVar1 = *(undefined8 *)(lVar7 + 0x110);
  uVar2 = *(undefined8 *)(lVar7 + 0x180);
  iVar3 = RtlLengthSid(uVar6);
  iVar4 = RtlLengthSid(uVar2);
  iVar5 = RtlLengthSid(uVar1);
  uVar8 = iVar3 + iVar4 + iVar5 + 0x20;
  _Src = (void *)ExAllocatePool2(0x40,uVar8,0x536d6750);
  if (_Src == (void *)0x0) {
    iVar3 = -0x3fffff66;
  }
  else {
    iVar3 = RtlCreateAcl(_Src,uVar8,2);
    if ((((-1 < iVar3) && (iVar3 = RtlAddAccessAllowedAce(_Src,2,local_res10[0],uVar1), -1 < iVar3))
        && (iVar3 = RtlAddAccessAllowedAce(_Src,2,local_res10[0],uVar2), -1 < iVar3)) &&
       (iVar3 = RtlAddAccessAllowedAce(_Src,2,local_res10[0],uVar6), -1 < iVar3)) {
      lVar7 = ExAllocatePool2(0x40,(ulonglong)uVar8 + 0x28,0x536d6750);
      if (lVar7 != 0) {
        memmove((void *)(lVar7 + 0x28),_Src,(ulonglong)uVar8);
        ExFreePoolWithTag(_Src,0);
        iVar3 = RtlCreateSecurityDescriptor(lVar7,1);
        if ((iVar3 < 0) || (iVar3 = RtlSetDaclSecurityDescriptor(lVar7,1,lVar7 + 0x28,0), iVar3 < 0)
           ) {
          ExFreePoolWithTag(lVar7,0);
          return iVar3;
        }
        *param_1 = lVar7;
        return 0;
      }
      iVar3 = -0x3fffff66;
    }
    ExFreePoolWithTag(_Src,0);
  }
  return iVar3;
}



===== PgmGetUserInfo @ 14003d660 =====

undefined8
PgmGetUserInfo(undefined8 param_1,longlong param_2,undefined8 param_3,undefined1 *param_4)

{
  longlong lVar1;
  undefined1 uVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 local_res8;
  undefined4 local_res10 [2];
  
  local_res10[0] = 0;
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 8) + 8);
  lVar5 = *(longlong *)(lVar1 + 0x20);
  if ((lVar5 != 0) || (lVar5 = *(longlong *)(lVar1 + 0x30), lVar5 != 0)) {
    local_res8 = param_1;
    iVar3 = SeQueryInformationToken(lVar5,1);
    local_res8 = CONCAT44(local_res8._4_4_,iVar3);
    if (-1 < iVar3) {
      *param_4 = 0;
      uVar4 = IoGetFileObjectGenericMapping();
      uVar2 = SeAccessCheck(PgmSecurityDescriptor,lVar1 + 0x20,0,3,0,0,uVar4,1,local_res10,
                            &local_res8);
      *param_4 = uVar2;
      return 0;
    }
  }
  return 0xc0000001;
}



===== CloseAddressHandles @ 14003d720 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 CloseAddressHandles(longlong param_1,undefined8 *param_2,undefined8 param_3)

{
  undefined1 uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  bool bVar4;
  undefined1 auStackY_88 [32];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_88;
  local_58 = 0;
  uStack_50 = 0;
  uVar1 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  puVar3 = param_2;
  lVar2 = PsGetCurrentProcess();
  bVar4 = lVar2 != PgmStaticConfig;
  if (bVar4) {
    puVar3 = &local_58;
    KeStackAttachProcess();
  }
  if (param_2 != (undefined8 *)0x0) {
    ObfDereferenceObject(param_2);
  }
  if (param_1 != 0) {
    uVar1 = ZwClose(param_1);
  }
  if (bVar4) {
    KeUnstackDetachProcess(&local_58);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
    WPP_SF_qDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar3,param_3,param_1,uVar1,(char)param_2
              );
  }
  return 0;
}



===== PgmTdiOpenControl @ 14003d820 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PgmTdiOpenControl(longlong param_1)

{
  undefined8 *puVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  bool bVar5;
  undefined1 auStack_108 [32];
  undefined8 *local_e8;
  undefined8 local_e0;
  undefined4 local_d8;
  undefined4 local_d0;
  undefined4 local_c8;
  undefined8 local_c0;
  undefined4 local_b8;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
  wchar_t *local_80;
  undefined4 local_78;
  undefined4 local_74;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_108;
  local_8c = 0;
  local_74 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  lVar3 = PsGetCurrentProcess();
  bVar5 = lVar3 != PgmStaticConfig;
  if (bVar5) {
    KeStackAttachProcess(PgmStaticConfig,&local_60);
  }
  local_b8 = 0;
  puVar1 = (undefined8 *)(param_1 + 0x28);
  local_c0 = 0;
  local_c8 = 0;
  local_d0 = 2;
  local_d8 = 0;
  local_e0 = CONCAT44(local_e0._4_4_,0x80);
  local_e8 = (undefined8 *)0x0;
  local_90 = 0x30;
  local_88 = 0;
  local_78 = 0x200;
  local_70 = 0;
  uStack_68 = 0;
  local_80 = (wchar_t *)(param_1 + 0x18);
  iVar2 = ZwCreateFile(puVar1,0xc0000000,&local_90,&local_a0);
  if ((iVar2 < 0) || (iVar2 = (int)local_a0, (int)local_a0 < 0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
               &WPP_bb24dc9f99d8356a0c4778f616204a55_Traceguids,iVar2);
    }
  }
  else {
    local_e8 = &local_a8;
    local_e0 = 0;
    local_a8 = 0;
    iVar2 = ObReferenceObjectByHandle(*puVar1,0,0,0);
    *(undefined8 *)(param_1 + 0x38) = local_a8;
    if (iVar2 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                 &WPP_bb24dc9f99d8356a0c4778f616204a55_Traceguids,iVar2);
      }
      ZwClose(*puVar1);
    }
  }
  if (bVar5) {
    KeUnstackDetachProcess(&local_60);
  }
  if (iVar2 < 0) {
    *puVar1 = 0;
    *(undefined8 *)(param_1 + 0x38) = 0;
  }
  else {
    uVar4 = IoGetRelatedDeviceObject(*(undefined8 *)(param_1 + 0x38));
    *(undefined8 *)(param_1 + 0x30) = uVar4;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
      WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
               &WPP_bb24dc9f99d8356a0c4778f616204a55_Traceguids,(wchar_t *)(param_1 + 0x18));
    }
  }
  return iVar2;
}



===== TdiOpenAddressHandle @ 14003da7c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TdiOpenAddressHandle
              (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
              undefined8 *param_5,longlong *param_6,undefined8 *param_7)

{
  longlong lVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *_Src;
  longlong lVar4;
  undefined8 uVar5;
  undefined2 uVar6;
  longlong lVar7;
  bool bVar8;
  undefined1 auStackY_148 [32];
  undefined8 local_e8;
  undefined4 local_e0 [2];
  longlong local_d8;
  undefined8 *local_d0;
  longlong *local_c8;
  undefined8 *local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined8 local_a0;
  longlong local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined2 local_78;
  undefined4 uStack_76;
  undefined2 uStack_72;
  undefined4 uStack_70;
  undefined2 uStack_6c;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  lVar1 = pgPgmDevice;
  local_38 = __security_cookie ^ (ulonglong)auStackY_148;
  local_d0 = param_5;
  local_c8 = param_6;
  local_c0 = param_7;
  local_d8 = pgPgmDevice;
  uStack_72 = 0;
  uStack_70 = 0;
  uStack_6c = 0;
  lVar7 = 0;
  local_a4 = 0;
  local_8c = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_e8 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_e0[0] = 1;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  puVar3 = (undefined4 *)ExAllocatePool2(0x40,0x36,0x316d6750);
  if (puVar3 == (undefined4 *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
               &WPP_bb24dc9f99d8356a0c4778f616204a55_Traceguids,0x36);
    }
    return -0x3fffff66;
  }
  _Src = (undefined4 *)ExAllocatePool2(0x40,0x1a,0x326d6750);
  if (_Src == (undefined4 *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
               &WPP_bb24dc9f99d8356a0c4778f616204a55_Traceguids,0x1a);
    }
    ExFreePoolWithTag(puVar3,0);
    return -0x3fffff66;
  }
  *puVar3 = 0;
  puVar3[1] = 0x191000;
  memmove(puVar3 + 2,"TransportAddress",0x11);
  uStack_76 = 0;
  local_78 = 0x7100;
  uStack_72 = 0;
  uStack_70 = 0;
  uStack_6c = 0;
  *(undefined8 *)(_Src + 2) = 0x7100;
  _Src[4] = 0;
  *(undefined2 *)(_Src + 5) = 0;
  _Src[1] = 0x2000e;
  *_Src = 1;
  memmove((void *)((ulonglong)*(byte *)((longlong)puVar3 + 5) + 9 + (longlong)puVar3),_Src,0x19);
  lVar4 = PsGetCurrentProcess();
  bVar8 = lVar4 != PgmStaticConfig;
  if (bVar8) {
    KeStackAttachProcess(PgmStaticConfig,&local_68);
  }
  local_a0 = 0;
  local_98 = lVar1 + 0x18;
  local_a8 = 0x30;
  local_90 = 0x240;
  local_88 = 0;
  uStack_80 = 0;
  iVar2 = ZwCreateFile(&local_e8,0xc0100000,&local_a8,&local_b8);
  ExFreePoolWithTag(_Src,0);
  ExFreePoolWithTag(puVar3,0);
  if ((iVar2 < 0) || (iVar2 = (int)local_b8, (int)local_b8 < 0)) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_14003df71;
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) {
      WPP_SF_DZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                &WPP_bb24dc9f99d8356a0c4778f616204a55_Traceguids,iVar2,(wchar_t *)(local_d8 + 0x18))
      ;
    }
    if (iVar2 < 0) goto LAB_14003df71;
LAB_14003de4d:
    uVar5 = IoGetRelatedDeviceObject(lVar7);
    if (param_2 == 0) {
LAB_14003df1c:
      *local_d0 = local_e8;
      *local_c8 = lVar7;
      *local_c0 = uVar5;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
        WPP_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                   &WPP_bb24dc9f99d8356a0c4778f616204a55_Traceguids,local_e8,(char)lVar7,(char)uVar5
                  );
      }
      goto LAB_14003df71;
    }
    iVar2 = TdiSetEventHandler(uVar5,lVar7,2,TdiErrorHandler,param_2);
    if (iVar2 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                 &WPP_bb24dc9f99d8356a0c4778f616204a55_Traceguids,iVar2);
      }
    }
    else {
      iVar2 = TdiSetEventHandler(uVar5,lVar7,4,TdiRcvDatagramHandler,param_2);
      if (iVar2 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          uVar6 = 0x13;
LAB_14003df01:
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
                   &WPP_bb24dc9f99d8356a0c4778f616204a55_Traceguids,iVar2);
        }
      }
      else {
        iVar2 = PgmSetTcpInfo(local_e8,0x1b,local_e0,4);
        if (-1 < iVar2) goto LAB_14003df1c;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          uVar6 = 0x12;
          goto LAB_14003df01;
        }
      }
      if (-1 < iVar2) goto LAB_14003df1c;
    }
    ObfDereferenceObject(lVar7);
  }
  else {
    local_d8 = 0;
    iVar2 = ObReferenceObjectByHandle(local_e8,0,0,0);
    lVar7 = local_d8;
    if (-1 < iVar2) goto LAB_14003de4d;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
               &WPP_bb24dc9f99d8356a0c4778f616204a55_Traceguids,iVar2);
    }
  }
  ZwClose(local_e8);
LAB_14003df71:
  if (bVar8) {
    KeUnstackDetachProcess(&local_68);
    return iVar2;
  }
  return iVar2;
}



===== entry @ 14003e010 =====

void entry(longlong param_1,longlong param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 14003e044 =====

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



===== DriverEntry @ 14003e078 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DriverEntry(longlong param_1,longlong param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined2 uVar3;
  
  wil_InitializeFeatureStaging();
  _DAT_140036688 = 1;
  _WPP_MAIN_CB = 0;
  DAT_140036668 = &WPP_ThisDir_CTLGUID_CtlGuid;
  DAT_140036670 = 0;
  _DAT_140036680 = 0;
  WppLoadTracingSupport();
  _DAT_140036680 = 0;
  WppInitKm();
  uVar2 = InitPgm(param_1,param_2);
  if ((int)uVar2 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_80756061d1e530076809262fec60bbbb_Traceguids,(int)uVar2);
    }
    wil_UninitializeFeatureStaging();
    return uVar2 & 0xffffffff;
  }
  *(code **)(param_1 + 0x70) = PgmDispatchCreate;
  *(code **)(param_1 + 0xe0) = PgmDispatchDeviceControl;
  *(code **)(param_1 + 0xe8) = PgmDispatchInternalDeviceControl;
  *(code **)(param_1 + 0x100) = PgmDispatchCleanup;
  *(code **)(param_1 + 0x80) = PgmDispatchClose;
  *(code **)(param_1 + 0x68) = PgmUnload;
  uVar1 = SetTdiHandlers();
  uVar2 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) goto LAB_14003e1ab;
    uVar3 = 0xb;
  }
  else {
    uVar1 = PgmBuildAdminSecurityDescriptor(&PgmSecurityDescriptor);
    uVar2 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return uVar2;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0) {
        return uVar2;
      }
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
              &WPP_80756061d1e530076809262fec60bbbb_Traceguids);
      return uVar2;
    }
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) goto LAB_14003e1ab;
    uVar3 = 0xc;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
           &WPP_80756061d1e530076809262fec60bbbb_Traceguids,(int)uVar2);
LAB_14003e1ab:
  CleanupInit(5);
  return uVar2;
}



===== wil_InitializeFeatureStaging @ 14003e234 =====

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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14003e324 =====

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


