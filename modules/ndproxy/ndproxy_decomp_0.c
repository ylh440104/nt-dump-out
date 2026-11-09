
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



===== _wcsnicmp @ 14000101d =====

int __cdecl _wcsnicmp(wchar_t *_Str1,wchar_t *_Str2,size_t _MaxCount)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000101d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _wcsnicmp(_Str1,_Str2,_MaxCount);
  return iVar1;
}



===== Feature_2616427835__private_IsEnabledDeviceUsageNoInline @ 140001030 =====

ulonglong Feature_2616427835__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_2616427835__private_featureState;
  if ((Feature_2616427835__private_featureState & 0x10) == 0) {
    uVar1 = Feature_2616427835__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_2616427835__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_2616427835__private_IsEnabledFallback @ 140001068 =====

void Feature_2616427835__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== PxClCloseAfComplete @ 140001080 =====

void PxClCloseAfComplete(undefined1 param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  
  plVar1 = (longlong *)param_2[4];
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
              &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids,param_2,param_1);
  }
  uVar5 = KeAcquireSpinLockRaiseToDpc(plVar1 + 0x4e);
  *(undefined1 *)(plVar1 + 0x4f) = uVar5;
  lVar2 = *param_2;
  if ((*(longlong **)(lVar2 + 8) != param_2) ||
     (plVar3 = (longlong *)param_2[1], (longlong *)*plVar3 != param_2)) {
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  *plVar3 = lVar2;
  *(longlong **)(lVar2 + 8) = plVar3;
  plVar3 = plVar1 + 3;
  *(int *)plVar3 = (int)*plVar3 + -1;
  if ((int)*plVar3 == 0) {
    KeReleaseSpinLock();
    PxFreeAdapter(plVar1);
  }
  else {
    KeReleaseSpinLock(plVar1 + 0x4e,(char)plVar1[0x4f]);
  }
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x17);
  lVar2 = param_2[0xd];
  *(undefined4 *)(param_2 + 2) = 0;
  param_2[0xd] = 0;
  *(undefined1 *)(param_2 + 0x18) = uVar5;
  KeReleaseSpinLock(param_2 + 0x17,uVar5);
  if (lVar2 != 0) {
    uVar5 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x88);
    *(undefined1 *)(lVar2 + 0x90) = uVar5;
    MarkProviderOffline(lVar2);
    KeReleaseSpinLock(lVar2 + 0x88,*(undefined1 *)(lVar2 + 0x90));
  }
  if ((char)param_2[0x19] != '\0') {
    NdisClNotifyCloseAddressFamilyComplete(param_2[3],0);
  }
  PxFreeClAf(param_2);
  return;
}



===== PxClNotifyCloseAf @ 140001200 =====

ulonglong PxClNotifyCloseAf(longlong *param_1,undefined8 param_2,undefined *param_3)

{
  int *piVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  code *pcVar10;
  undefined1 uVar11;
  uint uVar12;
  int iVar13;
  ulonglong uVar14;
  undefined8 uVar15;
  bool bVar16;
  
  uVar12 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
            &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids);
  }
  plVar2 = param_1 + 0x17;
  uVar11 = KeAcquireSpinLockRaiseToDpc(plVar2);
  *(undefined1 *)(param_1 + 0x18) = uVar11;
  *(int *)((longlong)param_1 + 0x14) = *(int *)((longlong)param_1 + 0x14) + 1;
  KeReleaseSpinLock(plVar2,uVar11);
  lVar4 = param_1[4];
  *(undefined1 *)(param_1 + 0x19) = 1;
  lVar3 = lVar4 + 0x270;
  uVar11 = KeAcquireSpinLockRaiseToDpc(lVar3);
  *(undefined1 *)(lVar4 + 0x278) = uVar11;
  lVar5 = *param_1;
  if ((*(longlong **)(lVar5 + 8) == param_1) &&
     (plVar6 = (longlong *)param_1[1], (longlong *)*plVar6 == param_1)) {
    *plVar6 = lVar5;
    *(longlong **)(lVar5 + 8) = plVar6;
    plVar6 = *(longlong **)(lVar4 + 0x40);
    if (*plVar6 == lVar4 + 0x38) {
      param_1[1] = (longlong)plVar6;
      *param_1 = lVar4 + 0x38;
      *plVar6 = (longlong)param_1;
      *(longlong **)(lVar4 + 0x40) = param_1;
      KeReleaseSpinLock(lVar3,*(undefined1 *)(lVar4 + 0x278));
      uVar11 = KeAcquireSpinLockRaiseToDpc(plVar2);
      lVar5 = param_1[0xd];
      *(undefined1 *)(param_1 + 0x18) = uVar11;
      *(undefined4 *)(param_1 + 2) = 1;
      KeReleaseSpinLock(plVar2,uVar11);
      if (lVar5 != 0) {
        uVar11 = KeAcquireSpinLockRaiseToDpc(lVar5 + 0x88);
        *(undefined1 *)(lVar5 + 0x90) = uVar11;
        MarkProviderOffline(lVar5);
        KeReleaseSpinLock(lVar5 + 0x88,*(undefined1 *)(lVar5 + 0x90));
      }
      uVar11 = KeAcquireSpinLockRaiseToDpc(plVar2);
      plVar6 = param_1 + 9;
      while( true ) {
        *(undefined1 *)(param_1 + 0x18) = uVar11;
        plVar7 = (longlong *)*plVar6;
        if (plVar7 == plVar6) break;
        if (((longlong *)plVar7[1] != plVar6) ||
           (lVar5 = *plVar7, (longlong *)*(longlong *)(lVar5 + 8) != plVar7)) goto LAB_1400016e1;
        *plVar6 = lVar5;
        *(longlong **)(lVar5 + 8) = plVar6;
        plVar9 = param_1 + 0xb;
        lVar5 = *plVar9;
        if (*(longlong **)(lVar5 + 8) != plVar9) goto LAB_1400016e1;
        plVar7[1] = (longlong)plVar9;
        *plVar7 = lVar5;
        *(longlong **)(lVar5 + 8) = plVar7;
        *plVar9 = (longlong)plVar7;
        *(undefined1 *)(plVar7 + 6) = 0;
        KeReleaseSpinLock(plVar2);
        uVar11 = KeAcquireSpinLockRaiseToDpc(plVar7 + 4);
        *(uint *)((longlong)plVar7 + -0x1bc) = *(uint *)((longlong)plVar7 + -0x1bc) | 0x20;
        uVar15 = 0;
        *(undefined1 *)(plVar7 + 5) = uVar11;
        PxVcCleanup((longlong)(plVar7 + -0x3c),(longlong *)0x0,param_3);
        piVar1 = (int *)((longlong)plVar7 + -0x1c4);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          DoDerefVcWork(plVar7 + -0x3c,uVar15,param_3);
        }
        else {
          KeReleaseSpinLock(plVar7 + 4,*(undefined1 *)(plVar7 + 5));
        }
        uVar11 = KeAcquireSpinLockRaiseToDpc(plVar2);
      }
      plVar6 = param_1 + 5;
      plVar7 = (longlong *)*plVar6;
      while (plVar9 = plVar7, plVar9 != plVar6) {
        LOCK();
        bVar16 = (int)plVar9[2] == 3;
        if (bVar16) {
          *(int *)(plVar9 + 2) = 1;
        }
        UNLOCK();
        plVar7 = (longlong *)*plVar9;
        if (bVar16) {
          if (((longlong *)plVar7[1] != plVar9) ||
             (plVar8 = (longlong *)plVar9[1], (longlong *)*plVar8 != plVar9)) goto LAB_1400016e1;
          *plVar8 = (longlong)plVar7;
          plVar7[1] = (longlong)plVar8;
          plVar7 = (longlong *)param_1[8];
          if ((longlong *)*plVar7 != param_1 + 7) goto LAB_1400016e1;
          plVar9[1] = (longlong)plVar7;
          *plVar9 = (longlong)(param_1 + 7);
          *plVar7 = (longlong)plVar9;
          param_1[8] = (longlong)plVar9;
          KeReleaseSpinLock(plVar2,(char)param_1[0x18]);
          ClearSapWithTapiLine((longlong)plVar9);
          uVar12 = NdisClDeregisterSap(plVar9[7]);
          if (uVar12 != 0x103) {
            PxClDeregisterSapComplete((char)uVar12,plVar9);
          }
          uVar11 = KeAcquireSpinLockRaiseToDpc(plVar2);
          *(undefined1 *)(param_1 + 0x18) = uVar11;
          plVar7 = (longlong *)*plVar6;
        }
      }
      piVar1 = (int *)((longlong)param_1 + 0x14);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        DoDerefClAfWork(param_1);
      }
      else {
        KeReleaseSpinLock(plVar2,(char)param_1[0x18]);
      }
      uVar11 = KeAcquireSpinLockRaiseToDpc(lVar3);
      plVar6 = (longlong *)(lVar4 + 0x50);
      while( true ) {
        *(undefined1 *)(lVar4 + 0x278) = uVar11;
        plVar7 = (longlong *)*plVar6;
        if (plVar7 == plVar6) {
          KeReleaseSpinLock(lVar3,uVar11);
          if ((uVar12 != 0) && (uVar12 != 0x103)) {
            uVar12 = 0;
          }
          uVar11 = KeAcquireSpinLockRaiseToDpc(plVar2);
          piVar1 = (int *)((longlong)param_1 + 0x14);
          *piVar1 = *piVar1 + -1;
          *(undefined1 *)(param_1 + 0x18) = uVar11;
          if (*piVar1 == 0) {
            DoDerefClAfWork(param_1);
          }
          else {
            KeReleaseSpinLock(plVar2,uVar11);
          }
          return (ulonglong)uVar12;
        }
        if (((longlong *)plVar7[1] != plVar6) ||
           (lVar5 = *plVar7, *(longlong **)(lVar5 + 8) != plVar7)) break;
        *plVar6 = lVar5;
        *(longlong **)(lVar5 + 8) = plVar6;
        plVar9 = *(longlong **)(lVar4 + 0x68);
        if (*plVar9 != lVar4 + 0x60) break;
        plVar7[1] = (longlong)plVar9;
        *plVar7 = lVar4 + 0x60;
        *plVar9 = (longlong)plVar7;
        *(longlong **)(lVar4 + 0x68) = plVar7;
        KeReleaseSpinLock(lVar3,*(undefined1 *)(lVar4 + 0x278));
        uVar11 = KeAcquireSpinLockRaiseToDpc(plVar7 + 0xb);
        *(undefined1 *)(plVar7 + 0xc) = uVar11;
        *(int *)((longlong)plVar7 + 0x14) = *(int *)((longlong)plVar7 + 0x14) + 1;
        *(undefined4 *)(plVar7 + 2) = 1;
        KeReleaseSpinLock(plVar7 + 0xb,uVar11);
        uVar11 = KeAcquireSpinLockRaiseToDpc(plVar2);
        *(undefined1 *)(param_1 + 0x18) = uVar11;
        *(int *)((longlong)param_1 + 0x14) = *(int *)((longlong)param_1 + 0x14) + 1;
        KeReleaseSpinLock(plVar2,uVar11);
        plVar7[0x11] = (longlong)param_1;
        iVar13 = NdisCmNotifyCloseAddressFamily(plVar7[3]);
        if (iVar13 == 0x103) {
          uVar12 = 0x103;
        }
        else {
          PxCmNotifyCloseAfComplete((longlong)plVar7);
        }
        uVar11 = KeAcquireSpinLockRaiseToDpc(lVar3);
      }
    }
  }
LAB_1400016e1:
  pcVar10 = (code *)swi(0x29);
  (*pcVar10)(3);
  pcVar10 = (code *)swi(3);
  uVar14 = (*pcVar10)();
  return uVar14;
}



===== PxClOidRequest @ 1400016f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 PxClOidRequest(longlong param_1,ulonglong param_2,undefined *param_3,undefined8 *param_4)

{
  longlong *plVar1;
  int *piVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  undefined1 uVar7;
  int iVar8;
  longlong **pplVar9;
  undefined8 uVar10;
  longlong *plVar11;
  longlong *plVar12;
  undefined *puVar13;
  undefined1 auStack_1a8 [32];
  longlong *local_178;
  undefined8 *local_170;
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
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
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
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined1 local_70 [40];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_1a8;
  local_178 = (longlong *)0x0;
  pplVar9 = &local_178;
  local_170 = param_4;
  GetVcFromCtx(param_2,(longlong *)pplVar9);
  plVar11 = local_178;
  lVar4 = *(longlong *)(param_1 + 0x20);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids;
    pplVar9 = (longlong **)0x0;
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
              &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids,param_1,(char)local_178);
  }
  if (plVar11 == (longlong *)0x0) {
    puVar13 = (undefined *)0x0;
  }
  else {
    puVar13 = (undefined *)plVar11[8];
  }
  lVar3 = lVar4 + 0x270;
  uVar7 = KeAcquireSpinLockRaiseToDpc(lVar3);
  puVar6 = local_170;
  plVar1 = (longlong *)(lVar4 + 0x50);
  *(undefined1 *)(lVar4 + 0x278) = uVar7;
  plVar12 = (longlong *)*plVar1;
  if (plVar12 != plVar1) {
    do {
      uVar10 = 0;
      param_3 = (undefined *)0x118;
      memset(&local_168,0,0x118);
      plVar5 = (longlong *)*plVar12;
      plVar11 = plVar12 + 0xb;
      uVar7 = KeAcquireSpinLockRaiseToDpc(plVar11);
      pplVar9 = (longlong **)CONCAT71((int7)((ulonglong)uVar10 >> 8),uVar7);
      *(undefined1 *)(plVar12 + 0xc) = uVar7;
      if ((int)plVar12[2] == 3) {
        *(int *)((longlong)plVar12 + 0x14) = *(int *)((longlong)plVar12 + 0x14) + 1;
        KeReleaseSpinLock(plVar11);
        memset(&local_168,0,0x118);
        local_168 = *puVar6;
        uStack_160 = puVar6[1];
        local_158 = puVar6[2];
        uStack_150 = puVar6[3];
        local_148 = puVar6[4];
        uStack_140 = puVar6[5];
        local_138 = puVar6[6];
        uStack_130 = puVar6[7];
        local_128 = puVar6[8];
        uStack_120 = puVar6[9];
        local_118 = puVar6[10];
        uStack_110 = puVar6[0xb];
        local_108 = puVar6[0xc];
        uStack_100 = puVar6[0xd];
        local_f8 = puVar6[0xe];
        uStack_f0 = puVar6[0xf];
        local_e8 = puVar6[0x10];
        uStack_e0 = puVar6[0x11];
        local_d8 = puVar6[0x12];
        uStack_d0 = puVar6[0x13];
        local_c8 = puVar6[0x14];
        uStack_c0 = puVar6[0x15];
        local_b8 = puVar6[0x16];
        uStack_b0 = puVar6[0x17];
        local_a8 = puVar6[0x18];
        uStack_a0 = puVar6[0x19];
        local_98 = *(undefined4 *)(puVar6 + 0x1a);
        uStack_94 = *(undefined4 *)((longlong)puVar6 + 0xd4);
        uStack_90 = *(undefined4 *)(puVar6 + 0x1b);
        uStack_8c = *(undefined4 *)((longlong)puVar6 + 0xdc);
        local_88 = *(undefined4 *)(puVar6 + 0x1c);
        uStack_84 = *(undefined4 *)((longlong)puVar6 + 0xe4);
        uStack_80 = *(undefined4 *)(puVar6 + 0x1d);
        uStack_7c = *(undefined4 *)((longlong)puVar6 + 0xec);
        KeReleaseSpinLock(lVar3,*(undefined1 *)(lVar4 + 0x278));
        NdisInitializeEvent(local_70);
        pplVar9 = (longlong **)plVar12[3];
        param_3 = puVar13;
        iVar8 = NdisCoOidRequest(*(undefined8 *)(lVar4 + 0x48),pplVar9,puVar13,0);
        if (iVar8 == 0x103) {
          pplVar9 = (longlong **)0x0;
          NdisWaitEvent(local_70);
        }
        uVar7 = KeAcquireSpinLockRaiseToDpc(lVar3);
        *(undefined1 *)(lVar4 + 0x278) = uVar7;
        uVar7 = KeAcquireSpinLockRaiseToDpc(plVar11);
        piVar2 = (int *)((longlong)plVar12 + 0x14);
        *piVar2 = *piVar2 + -1;
        *(undefined1 *)(plVar12 + 0xc) = uVar7;
        if (*piVar2 == 0) {
          DoDerefCmAfWork((longlong)plVar12);
        }
        else {
          pplVar9 = (longlong **)CONCAT71((int7)((ulonglong)pplVar9 >> 8),uVar7);
          KeReleaseSpinLock(plVar11);
        }
      }
      else {
        KeReleaseSpinLock();
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          param_3 = &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids;
          pplVar9 = (longlong **)0x0;
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                   &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids,(int)plVar5[2]);
        }
      }
      plVar12 = plVar5;
    } while (plVar5 != plVar1);
    plVar11 = local_178;
  }
  uVar10 = CONCAT71((int7)((ulonglong)pplVar9 >> 8),*(undefined1 *)(lVar4 + 0x278));
  KeReleaseSpinLock(lVar3);
  if (plVar11 != (longlong *)0x0) {
    uVar7 = KeAcquireSpinLockRaiseToDpc(plVar11 + 0x40);
    *(undefined1 *)(plVar11 + 0x41) = uVar7;
    piVar2 = (int *)((longlong)plVar11 + 0x1c);
    *piVar2 = *piVar2 + -1;
    if (*piVar2 == 0) {
      DoDerefVcWork(plVar11,uVar10,param_3);
    }
    else {
      KeReleaseSpinLock(plVar11 + 0x40,uVar7);
    }
  }
  return 0;
}



===== PxClOidRequestComplete @ 140001a30 =====

void PxClOidRequestComplete
               (undefined8 param_1,ulonglong param_2,undefined8 param_3,longlong param_4,
               undefined4 param_5)

{
  int *piVar1;
  longlong *plVar2;
  undefined1 uVar3;
  longlong **pplVar4;
  longlong *local_res8;
  
  local_res8 = (longlong *)0x0;
  pplVar4 = &local_res8;
  GetVcFromCtx(param_2,(longlong *)pplVar4);
  plVar2 = local_res8;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qqDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pplVar4,param_3,param_1,(char)local_res8,
                (char)*(undefined4 *)(param_4 + 0x20),(char)param_5);
  }
  if ((*(uint *)(param_4 + 0xf0) & 1) == 0) {
    *(undefined4 *)(param_4 + 0x110) = param_5;
    NdisSetEvent(param_4 + 0xf8);
  }
  else {
    pplVar4 = (longlong **)0x0;
    *(uint *)(param_4 + 0xf0) = *(uint *)(param_4 + 0xf0) & 0xfffffffe;
    ExFreePoolWithTag(param_4);
  }
  if (plVar2 != (longlong *)0x0) {
    uVar3 = KeAcquireSpinLockRaiseToDpc(plVar2 + 0x40);
    *(undefined1 *)(plVar2 + 0x41) = uVar3;
    piVar1 = (int *)((longlong)plVar2 + 0x1c);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      DoDerefVcWork(plVar2,pplVar4,param_3);
    }
    else {
      KeReleaseSpinLock(plVar2 + 0x40,uVar3);
    }
  }
  return;
}



===== PxClOpenAfCompleteEx @ 140001b40 =====

void PxClOpenAfCompleteEx(longlong param_1,undefined8 param_2,undefined4 param_3)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
              &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids,param_1,(char)param_3);
  }
  *(undefined8 *)(param_1 + 0x18) = param_2;
  *(undefined4 *)(param_1 + 0xb0) = param_3;
  NdisSetEvent(param_1 + 0x98);
  return;
}



===== WPP_SF_ @ 140001bc4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_D @ 140001bf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_q @ 140001c34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,0);
  return;
}



===== WPP_SF_qL @ 140001c78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qL(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,4,0);
  return;
}



===== WPP_SF_qDDD @ 140001ccc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_qPPD @ 140001d38 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qPPD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  undefined4 local_18 [6];
  
  local_18[0] = 0;
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids,0x23,&local_res20,8,
             &param_5,8,&param_6,8,local_18,4,0);
  return;
}



===== WPP_SF_qq @ 140001db4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,0);
  return;
}



===== WPP_SF_qqDd @ 140001e04 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqDd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids,0x14,&local_res20,8,
             &param_5,8,&param_6,4,&param_7,4,0);
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 140001e78 =====

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
LAB_140002081:
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
LAB_140001f53:
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
      if (param_3 == 4) goto LAB_140002081;
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
        goto LAB_140001f53;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 14000216c =====

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
      goto LAB_14000222f;
    }
    if (param_3 == 2) {
      uVar2 = (uVar4 ^ 1) * 4 + 1;
      uVar3 = 0;
      goto LAB_14000222f;
    }
    if (param_3 == 3) {
      uVar2 = (uVar4 ^ 1) * 4 + 2;
      uVar3 = 0;
      goto LAB_14000222f;
    }
    if (param_3 == 4) {
      uVar2 = (uVar4 ^ 1) * 4 + 3;
      uVar3 = 0;
      goto LAB_14000222f;
    }
    uVar2 = param_3 - 5;
    uVar3 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      uVar2 = (uVar4 ^ 1) * 2 + 8;
      goto LAB_14000222f;
    }
    if (uVar2 == 1) {
      uVar2 = (uVar4 ^ 1) * 2 + 9;
      goto LAB_14000222f;
    }
    bVar5 = (char)param_3 + 0x9c;
    if (bVar5 < 0x32) {
      uVar2 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar5;
      goto LAB_14000222f;
    }
  }
  uVar2 = 0xff;
LAB_14000222f:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x3bda2b8,&Feature_2616427835_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140002288 =====

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
                     (local_50,&Feature_2616427835__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)(0x3bda2b8,param_3,1,&Feature_2616427835__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)param_3,0x3bda2b8);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140002374 =====

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
LAB_140002427:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_140002455;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_140002427;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_140002455:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 1400025e0 =====

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
  if ((Feature_2616427835__private_featureState & 2) != 0) {
    uVar1 = Feature_2616427835__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_2616427835__private_featureState;
      if (bVar3) {
        Feature_2616427835__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_2616427835__private_featureState;
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



===== wil_details_IsEnabledFallback @ 140002634 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_2616427835__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_2616427835__private_featureState,(ulonglong)param_1,
                             0x14000c650);
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



===== _guard_check_icall @ 1400026d0 =====

void _guard_check_icall(void)

{
  return;
}



===== PxPnPCancelRemove @ 1400026e0 =====

undefined8 PxPnPCancelRemove(void)

{
  return 0;
}



===== PxCmCloseAf @ 1400026f0 =====

undefined8 PxCmCloseAf(longlong *param_1)

{
  int *piVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  undefined8 uVar7;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
             &WPP_c7e600acf35c333e1969f852caaf3ce1_Traceguids,param_1);
  }
  plVar2 = (longlong *)param_1[4];
  uVar6 = KeAcquireSpinLockRaiseToDpc(plVar2 + 0x4e);
  *(undefined1 *)(plVar2 + 0x4f) = uVar6;
  lVar3 = *param_1;
  if ((*(longlong **)(lVar3 + 8) != param_1) ||
     (plVar4 = (longlong *)param_1[1], (longlong *)*plVar4 != param_1)) {
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(3);
    pcVar5 = (code *)swi(3);
    uVar7 = (*pcVar5)();
    return uVar7;
  }
  *plVar4 = lVar3;
  *(longlong **)(lVar3 + 8) = plVar4;
  plVar4 = plVar2 + 3;
  *(int *)plVar4 = (int)*plVar4 + -1;
  if ((int)*plVar4 == 0) {
    KeReleaseSpinLock();
    PxFreeAdapter(plVar2);
  }
  else {
    KeReleaseSpinLock(plVar2 + 0x4e,(char)plVar2[0x4f]);
  }
  uVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xb);
  *(undefined4 *)(param_1 + 2) = 0;
  piVar1 = (int *)((longlong)param_1 + 0x14);
  *piVar1 = *piVar1 + -1;
  *(undefined1 *)(param_1 + 0xc) = uVar6;
  param_1[1] = (longlong)param_1;
  *param_1 = (longlong)param_1;
  if (*piVar1 == 0) {
    DoDerefCmAfWork((longlong)param_1);
  }
  else {
    KeReleaseSpinLock(param_1 + 0xb,uVar6);
  }
  return 0x103;
}



===== PxCmCreateVc @ 140002810 =====

undefined8 PxCmCreateVc(void)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (WPP_GLOBAL_Control[0x29] != '\0')) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_c7e600acf35c333e1969f852caaf3ce1_Traceguids);
  }
  return 0xc0000001;
}



===== PxCmDeRegisterSap @ 140002860 =====

undefined8 PxCmDeRegisterSap(longlong *param_1)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  undefined8 uVar7;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
             &WPP_c7e600acf35c333e1969f852caaf3ce1_Traceguids,param_1);
  }
  lVar2 = param_1[4];
  LOCK();
  *(undefined4 *)(param_1 + 2) = 0;
  UNLOCK();
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x58);
  *(undefined1 *)(lVar2 + 0x60) = uVar6;
  lVar3 = *param_1;
  if ((*(longlong **)(lVar3 + 8) != param_1) ||
     (plVar4 = (longlong *)param_1[1], (longlong *)*plVar4 != param_1)) {
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(3);
    pcVar5 = (code *)swi(3);
    uVar7 = (*pcVar5)();
    return uVar7;
  }
  *plVar4 = lVar3;
  *(longlong **)(lVar3 + 8) = plVar4;
  piVar1 = (int *)(lVar2 + 0x14);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    DoDerefCmAfWork(lVar2);
  }
  else {
    KeReleaseSpinLock(lVar2 + 0x58,*(undefined1 *)(lVar2 + 0x60));
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
             &WPP_8294867e35d63e705b52ce50c02b6694_Traceguids,param_1);
  }
  param_1[6] = 0;
  ExFreePoolWithTag(param_1,0);
  return 0;
}



===== PxCmDeleteVc @ 140002970 =====

undefined8 PxCmDeleteVc(void)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (WPP_GLOBAL_Control[0x29] != '\0')) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
            &WPP_c7e600acf35c333e1969f852caaf3ce1_Traceguids);
  }
  return 0xc0000001;
}



===== PxCmNotifyCloseAfComplete @ 1400029c0 =====

void PxCmNotifyCloseAfComplete(longlong param_1)

{
  int *piVar1;
  longlong *plVar2;
  undefined1 uVar3;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
             &WPP_c7e600acf35c333e1969f852caaf3ce1_Traceguids,0);
  }
  plVar2 = *(longlong **)(param_1 + 0x88);
  if (plVar2 == (longlong *)0x0) {
    *(undefined4 *)(param_1 + 0x80) = 0;
    NdisSetEvent(param_1 + 0x68);
  }
  else {
    uVar3 = KeAcquireSpinLockRaiseToDpc(plVar2 + 0x17);
    piVar1 = (int *)((longlong)plVar2 + 0x14);
    *piVar1 = *piVar1 + -1;
    *(undefined1 *)(plVar2 + 0x18) = uVar3;
    if (*piVar1 == 0) {
      DoDerefClAfWork(plVar2);
    }
    else {
      KeReleaseSpinLock(plVar2 + 0x17,uVar3);
    }
    uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x58);
    piVar1 = (int *)(param_1 + 0x14);
    *piVar1 = *piVar1 + -1;
    *(undefined1 *)(param_1 + 0x60) = uVar3;
    if (*piVar1 == 0) {
      DoDerefCmAfWork(param_1);
    }
    else {
      KeReleaseSpinLock(param_1 + 0x58,uVar3);
    }
  }
  return;
}



===== PxCmOidRequestComplete @ 140002ac0 =====

void PxCmOidRequestComplete
               (longlong param_1,undefined1 param_2,undefined8 param_3,longlong param_4,
               undefined4 param_5)

{
  int *piVar1;
  undefined1 uVar2;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
              &WPP_c7e600acf35c333e1969f852caaf3ce1_Traceguids,param_1,param_2);
  }
  if ((*(uint *)(param_4 + 0xf0) & 1) == 0) {
    *(undefined4 *)(param_4 + 0x110) = param_5;
    NdisSetEvent(param_4 + 0xf8);
  }
  else {
    *(uint *)(param_4 + 0xf0) = *(uint *)(param_4 + 0xf0) & 0xfffffffe;
    ExFreePoolWithTag(param_4,0);
    uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x58);
    piVar1 = (int *)(param_1 + 0x14);
    *piVar1 = *piVar1 + -1;
    *(undefined1 *)(param_1 + 0x60) = uVar2;
    if (*piVar1 == 0) {
      DoDerefCmAfWork(param_1);
    }
    else {
      KeReleaseSpinLock(param_1 + 0x58,uVar2);
    }
  }
  return;
}



===== PxCmOpenAf @ 140002ba0 =====

undefined8 PxCmOpenAf(longlong param_1,int *param_2,longlong param_3,longlong *param_4)

{
  longlong lVar1;
  code *pcVar2;
  undefined1 uVar3;
  undefined8 uVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong *plVar7;
  undefined1 *puVar8;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [40];
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
             &WPP_c7e600acf35c333e1969f852caaf3ce1_Traceguids,*param_2);
  }
  if (*param_2 == 0x800) {
    lVar1 = param_1 + 0x260;
    uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
    *(undefined1 *)(param_1 + 0x268) = uVar3;
    if (*(int *)(param_1 + 4) == 3) {
      KeReleaseSpinLock(lVar1,uVar3);
      plVar5 = (longlong *)PxAllocateCmAf((undefined8 *)param_2);
      if (plVar5 == (longlong *)0x0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                  &WPP_c7e600acf35c333e1969f852caaf3ce1_Traceguids);
        }
        uVar4 = 0xc000009a;
      }
      else {
        plVar5[3] = param_3;
        *(undefined4 *)(plVar5 + 2) = 3;
        plVar5[4] = param_1 + -0x10;
        NdisInitializeEvent(plVar5 + 0xd);
        uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
        puVar8 = auStack_48;
        *(undefined1 *)(param_1 + 0x268) = uVar3;
        lVar6 = param_1 + 0x40;
        plVar7 = *(longlong **)(param_1 + 0x48);
        if (*plVar7 != lVar6) {
          pcVar2 = (code *)swi(0x29);
          lVar6 = (*pcVar2)(3);
          puVar8 = auStack_40;
        }
        *plVar5 = lVar6;
        plVar5[1] = (longlong)plVar7;
        *plVar7 = (longlong)plVar5;
        *(longlong **)(lVar6 + 8) = plVar5;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
        uVar3 = *(undefined1 *)(param_1 + 0x268);
        *(undefined8 *)(puVar8 + -8) = 0x140002d27;
        KeReleaseSpinLock(lVar1,uVar3);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
          *(longlong *)(puVar8 + 0x20) = param_3;
          *(undefined8 *)(puVar8 + -8) = 0x140002d5b;
          WPP_SF_qq(uVar4,0xf,&WPP_c7e600acf35c333e1969f852caaf3ce1_Traceguids,plVar5,puVar8[0x20]);
        }
        *param_4 = (longlong)plVar5;
        uVar4 = 0;
      }
    }
    else {
      KeReleaseSpinLock();
      uVar4 = 0xc0010002;
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_c7e600acf35c333e1969f852caaf3ce1_Traceguids,*param_2);
    }
    uVar4 = 0xc0010004;
  }
  return uVar4;
}



===== PxCmRegisterSap @ 140002d80 =====

undefined8 PxCmRegisterSap(longlong param_1,void *param_2,longlong param_3,longlong *param_4)

{
  longlong lVar1;
  code *pcVar2;
  undefined1 uVar3;
  undefined8 uVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong *plVar7;
  undefined1 *puVar8;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_c7e600acf35c333e1969f852caaf3ce1_Traceguids,param_1);
  }
  lVar1 = param_1 + 0x58;
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
  *(undefined1 *)(param_1 + 0x60) = uVar3;
  if (*(int *)(param_1 + 0x10) == 3) {
    lVar6 = *(longlong *)(param_1 + 0x20);
    KeReleaseSpinLock(lVar1,uVar3);
    uVar3 = KeAcquireSpinLockRaiseToDpc(lVar6 + 0x270);
    *(undefined1 *)(lVar6 + 0x278) = uVar3;
    if (*(int *)(lVar6 + 0x14) == 3) {
      KeReleaseSpinLock(lVar6 + 0x270,uVar3);
      plVar5 = (longlong *)PxAllocateCmSap(param_2);
      if (plVar5 == (longlong *)0x0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (2 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                   &WPP_c7e600acf35c333e1969f852caaf3ce1_Traceguids,param_2);
        }
        uVar4 = 0xc000009a;
      }
      else {
        uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
        puVar8 = auStack_38;
        *(undefined1 *)(param_1 + 0x60) = uVar3;
        lVar6 = param_1 + 0x28;
        plVar5[5] = param_3;
        plVar5[4] = param_1;
        plVar7 = *(longlong **)(param_1 + 0x30);
        if (*plVar7 != lVar6) {
          pcVar2 = (code *)swi(0x29);
          lVar6 = (*pcVar2)(3);
          puVar8 = auStack_30;
        }
        *plVar5 = lVar6;
        plVar5[1] = (longlong)plVar7;
        *plVar7 = (longlong)plVar5;
        *(longlong **)(lVar6 + 8) = plVar5;
        uVar3 = *(undefined1 *)(param_1 + 0x60);
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
        *(undefined8 *)(puVar8 + -8) = 0x140002f2d;
        KeReleaseSpinLock(lVar1,uVar3);
        uVar4 = 0;
        *param_4 = (longlong)plVar5;
      }
    }
    else {
      KeReleaseSpinLock();
      uVar4 = 0xc0010002;
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_c7e600acf35c333e1969f852caaf3ce1_Traceguids,*(int *)(param_1 + 0x10));
    }
    KeReleaseSpinLock(lVar1,*(undefined1 *)(param_1 + 0x60));
    uVar4 = 0xc0000001;
  }
  return uVar4;
}



===== PxCoBindAdapterEx @ 140002f60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PxCoBindAdapterEx(undefined8 param_1,undefined8 param_2,ulonglong param_3)

{
  longlong *plVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  ushort uVar9;
  ushort uVar10;
  undefined4 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  wchar_t *_Src;
  void *_Src_00;
  code *pcVar14;
  bool bVar15;
  undefined1 uVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  longlong *plVar20;
  longlong lVar21;
  uint uVar22;
  longlong *plVar23;
  uint *puVar24;
  longlong lVar25;
  undefined1 *puVar26;
  ushort *puVar27;
  longlong lVar28;
  undefined1 auStack_318 [8];
  undefined1 auStack_310 [104];
  undefined4 local_2a8;
  undefined4 local_2a4;
  undefined4 local_2a0;
  undefined8 local_298;
  ushort *puStack_290;
  uint *local_288;
  undefined8 uStack_280;
  undefined1 *local_278;
  undefined1 *puStack_270;
  undefined8 local_268;
  ushort *local_260;
  undefined8 local_258;
  undefined8 local_250;
  undefined8 uStack_248;
  undefined8 local_238;
  undefined8 local_230;
  undefined4 local_218;
  undefined1 *local_210;
  undefined4 local_208;
  undefined1 local_140 [24];
  int local_128;
  wchar_t *local_118 [4];
  wchar_t *local_f8;
  wchar_t *local_f0;
  wchar_t *local_e8;
  wchar_t *local_e0;
  wchar_t *local_d8;
  wchar_t *local_d0;
  wchar_t *local_c8;
  wchar_t *local_c0;
  wchar_t *local_b8;
  wchar_t *local_b0;
  wchar_t *local_a8;
  wchar_t *local_a0;
  uint local_98 [20];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_318;
  local_2a0 = 0;
  local_2a8 = 0;
  puVar27 = *(ushort **)(param_3 + 0x10);
  local_268 = 0;
  local_298 = 0;
  puStack_290 = (ushort *)0x0;
  local_2a4 = 0x8100888e;
  local_288 = (uint *)0x0;
  uStack_280 = 0;
  local_278 = (undefined1 *)0x0;
  puStack_270 = (undefined1 *)0x0;
  local_260 = puVar27;
  local_258 = param_2;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,param_3,*(wchar_t **)(puVar27 + 4));
  }
  NdisWaitEvent(DeviceExtension + 0x40,0);
  uVar16 = KeAcquireSpinLockRaiseToDpc(DeviceExtension + 0x58);
  puVar26 = auStack_318;
  plVar20 = (longlong *)(DeviceExtension + 0x20);
  *(undefined1 *)(DeviceExtension + 0x60) = uVar16;
  plVar23 = (longlong *)*plVar20;
  bVar15 = false;
  if (plVar23 != plVar20) {
    uVar9 = *puVar27;
    do {
      if ((uVar9 == *(ushort *)(plVar23 + 0x16)) &&
         (param_3 = (ulonglong)uVar9,
         iVar17 = memcmp(*(void **)(puVar27 + 4),(void *)plVar23[0x17],(ulonglong)uVar9),
         iVar17 == 0)) {
        bVar15 = true;
        break;
      }
      plVar23 = (longlong *)*plVar23;
      bVar15 = false;
    } while (plVar23 != plVar20);
  }
  KeReleaseSpinLock(DeviceExtension + 0x58,uVar16);
  if (bVar15) {
    iVar17 = 0x10003;
    puVar26 = auStack_318;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (puVar26 = auStack_318, 2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,param_3,*(wchar_t **)(puVar27 + 4));
      puVar26 = auStack_318;
    }
    goto LAB_1400038c2;
  }
  uVar22 = puVar27[1] + 0x280;
  if ((uVar22 < puVar27[1]) ||
     (plVar20 = (longlong *)ExAllocatePool2(0x40,uVar22,0x335850), plVar20 == (longlong *)0x0)) {
    iVar17 = -0x3fffff66;
    goto LAB_1400038c2;
  }
  *(undefined4 *)((longlong)plVar20 + 0x14) = 2;
  *(undefined4 *)(plVar20 + 2) = 0x20206d43;
  KeInitializeSpinLock(plVar20 + 0x4e);
  lVar28 = DeviceExtension;
  plVar23 = plVar20 + 10;
  plVar20[0xb] = (longlong)plVar23;
  plVar1 = plVar20 + 5;
  *plVar23 = (longlong)plVar23;
  plVar23 = plVar20 + 0xc;
  plVar20[6] = (longlong)plVar1;
  *plVar1 = (longlong)plVar1;
  plVar1 = plVar20 + 7;
  plVar20[0xd] = (longlong)plVar23;
  *plVar23 = (longlong)plVar23;
  plVar20[8] = (longlong)plVar1;
  *plVar1 = (longlong)plVar1;
  uVar16 = KeAcquireSpinLockRaiseToDpc(lVar28 + 0x58);
  lVar25 = DeviceExtension;
  *(undefined1 *)(lVar28 + 0x60) = uVar16;
  lVar21 = lVar25 + 0x20;
  plVar23 = *(longlong **)(lVar25 + 0x28);
  puVar26 = auStack_318;
  if (*plVar23 != lVar21) {
    plVar23 = (longlong *)0x3;
    pcVar14 = (code *)swi(0x29);
    lVar21 = (*pcVar14)();
    puVar26 = auStack_310;
  }
  plVar20[1] = (longlong)plVar23;
  *plVar20 = lVar21;
  *plVar23 = (longlong)plVar20;
  *(longlong **)(lVar21 + 8) = plVar20;
  uVar16 = *(undefined1 *)(lVar28 + 0x60);
  *(undefined8 *)(puVar26 + -8) = 0x1400031a6;
  KeReleaseSpinLock(lVar25 + 0x58,uVar16);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar12 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(undefined8 *)(puVar26 + -8) = 0x1400031d5;
    WPP_SF_q(uVar12,10,&WPP_8294867e35d63e705b52ce50c02b6694_Traceguids,plVar20);
  }
  iVar19 = 1;
  uVar22 = (uint)(*puVar27 >> 1);
  if (uVar22 != 0) {
    lVar21 = *(longlong *)(puVar27 + 4);
    do {
      if (*(short *)(lVar21 + (ulonglong)uVar22 * 2) == 0x7b) {
        local_250 = 0;
        uStack_248 = 0;
        *(undefined8 *)(puVar26 + -8) = 0x140003211;
        RtlInitUnicodeString(&local_250,lVar21 + (ulonglong)uVar22 * 2);
        *(undefined8 *)(puVar26 + -8) = 0x140003229;
        RtlGUIDFromString(&local_250,plVar20 + 0x13);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          bVar2 = *(byte *)((longlong)plVar20 + 0xa6);
          bVar3 = *(byte *)((longlong)plVar20 + 0xa5);
          bVar4 = *(byte *)((longlong)plVar20 + 0xa4);
          bVar5 = *(byte *)((longlong)plVar20 + 0xa3);
          bVar6 = *(byte *)((longlong)plVar20 + 0xa2);
          bVar7 = *(byte *)((longlong)plVar20 + 0xa1);
          bVar8 = *(byte *)(plVar20 + 0x14);
          uVar9 = *(ushort *)((longlong)plVar20 + 0x9e);
          uVar10 = *(ushort *)((longlong)plVar20 + 0x9c);
          uVar12 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
          *(uint *)(puVar26 + 0x68) = (uint)*(byte *)((longlong)plVar20 + 0xa7);
          *(uint *)(puVar26 + 0x60) = (uint)bVar2;
          *(uint *)(puVar26 + 0x58) = (uint)bVar3;
          lVar21 = plVar20[0x13];
          *(uint *)(puVar26 + 0x50) = (uint)bVar4;
          *(uint *)(puVar26 + 0x48) = (uint)bVar5;
          *(uint *)(puVar26 + 0x40) = (uint)bVar6;
          *(uint *)(puVar26 + 0x38) = (uint)bVar7;
          *(uint *)(puVar26 + 0x30) = (uint)bVar8;
          *(uint *)(puVar26 + 0x28) = (uint)uVar9;
          *(uint *)(puVar26 + 0x20) = (uint)uVar10;
          *(undefined8 *)(puVar26 + -8) = 0x1400032ed;
          WPP_SF_DDDDDDDDDDD(uVar12,0x14,&WPP_cf979805fba431836a82e04c99ce8a90_Traceguids,
                             (int)lVar21,puVar26[0x20],puVar26[0x28],puVar26[0x30],puVar26[0x38],
                             puVar26[0x40],puVar26[0x48],puVar26[0x50],puVar26[0x58],puVar26[0x60],
                             puVar26[0x68]);
          puVar27 = local_260;
        }
        break;
      }
      uVar22 = uVar22 - 1;
    } while (uVar22 != 0);
  }
  *(undefined8 *)(puVar26 + -8) = 0x140003300;
  NdisInitializeEvent(plVar20 + 0x45);
  *(undefined8 *)(puVar26 + -8) = 0x140003314;
  NdisInitializeEvent(plVar20 + 0x41);
  *(undefined8 *)(puVar26 + -8) = 0x140003328;
  NdisInitializeEvent(plVar20 + 0x49);
  uVar12 = local_258;
  *(undefined4 *)(plVar20 + 0x4d) = 0;
  puVar24 = local_98;
  uVar22 = 0;
  do {
    uVar18 = uVar22 + 4;
    *puVar24 = uVar22;
    puVar24[1] = uVar22 + 1;
    puVar24[2] = uVar22 + 2;
    puVar24[3] = uVar22 + 3;
    puVar24 = puVar24 + 4;
    uVar22 = uVar18;
  } while (uVar18 < 0x14);
  local_288 = local_98;
  local_278 = puVar26 + 0x78;
  puStack_270 = puVar26 + 0x74;
  uStack_280 = CONCAT44(uStack_280._4_4_,0x14);
  local_268 = CONCAT44(local_268._4_4_,2);
  *(undefined4 *)(puVar26 + 0x70) = 0x380187;
  uVar11 = *(undefined4 *)(puVar26 + 0x70);
  local_298 = CONCAT44(local_298._4_4_,uVar11);
  uVar13 = *(undefined8 *)(DeviceExtension + 0x18);
  *(longlong **)(puVar26 + 0x20) = plVar20 + 4;
  *(undefined8 *)(puVar26 + -8) = 0x1400033c8;
  puStack_290 = puVar27;
  iVar17 = NdisOpenAdapterEx(uVar13,plVar20,&local_298,local_258);
  if (iVar17 == 0x103) {
    *(undefined8 *)(puVar26 + -8) = 0x1400033e7;
    NdisWaitEvent(plVar20 + 0x41,0);
    iVar17 = (int)plVar20[0x44];
  }
  if (iVar17 == 0) {
    plVar23 = plVar20 + 0x4e;
    *(undefined8 *)(puVar26 + -8) = 0x14000344f;
    uVar16 = KeAcquireSpinLockRaiseToDpc(plVar23);
    *(int *)(plVar20 + 3) = (int)plVar20[3] + 1;
    *(undefined1 *)(plVar20 + 0x4f) = uVar16;
    *(undefined8 *)(puVar26 + -8) = 0x14000346d;
    KeReleaseSpinLock(plVar23,uVar16);
    iVar19 = 2;
    *(undefined8 *)(puVar26 + -8) = 0x140003489;
    NdisInitializeEvent(plVar20 + 0x41);
    local_288 = local_98;
    local_298 = CONCAT44(local_298._4_4_,uVar11);
    local_278 = puVar26 + 0x78;
    puStack_270 = puVar26 + 0x74;
    uStack_280 = CONCAT44(uStack_280._4_4_,0x14);
    local_268 = CONCAT44(local_268._4_4_,2);
    uVar13 = *(undefined8 *)(DeviceExtension + 0x18);
    *(longlong **)(puVar26 + 0x20) = plVar20 + 9;
    *(undefined8 *)(puVar26 + -8) = 0x1400034e4;
    puStack_290 = puVar27;
    iVar17 = NdisOpenAdapterEx(uVar13,plVar20 + 2,&local_298,uVar12);
    if (iVar17 == 0x103) {
      *(undefined8 *)(puVar26 + -8) = 0x140003503;
      NdisWaitEvent(plVar20 + 0x41,0);
      iVar17 = (int)plVar20[0x44];
    }
    if (iVar17 != 0) {
      *(undefined4 *)(plVar20 + 0x15) = 0xffffffff;
      plVar20[9] = 0;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar12 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        *(undefined8 *)(puVar26 + -8) = 0x140003553;
        WPP_SF_D(uVar12,0x16,&WPP_cf979805fba431836a82e04c99ce8a90_Traceguids,iVar17);
      }
      goto LAB_140003553;
    }
    *(undefined8 *)(puVar26 + -8) = 0x14000356b;
    uVar16 = KeAcquireSpinLockRaiseToDpc(plVar23);
    *(int *)(plVar20 + 3) = (int)plVar20[3] + 1;
    iVar19 = 3;
    *(undefined1 *)(plVar20 + 0x4f) = uVar16;
    *(undefined4 *)((longlong)plVar20 + 0x14) = 3;
    *(uint *)(plVar20 + 0x15) = local_98[*(uint *)(puVar26 + 0x78)];
    *(undefined8 *)(puVar26 + -8) = 0x1400035a8;
    KeReleaseSpinLock(plVar23);
    uVar22 = 0;
    *(undefined4 *)(puVar26 + 0x70) = 0;
    *(undefined8 *)(puVar26 + -8) = 0x1400035c5;
    memset(&local_238,0,0x118);
    local_118[0] = L"GENERIC";
    local_118[1] = L"X25";
    local_118[2] = L"ISDN";
    local_118[3] = L"SERIAL";
    local_f8 = L"FRAMERELAY";
    local_f0 = L"ATM";
    local_e8 = L"SONET";
    local_e0 = L"SW56";
    local_d8 = L"PPTP VPN";
    local_d0 = L"L2TP VPN";
    local_c8 = L"IRDA";
    local_c0 = L"PARALLEL";
    local_b8 = L"PPPOE";
    local_b0 = L"SSTP";
    local_a8 = L"AGILE VPN";
    local_a0 = L"GRE";
    iVar17 = (int)plVar20[0x15];
    if (iVar17 == 3) {
LAB_1400036c4:
      *(undefined8 *)(puVar26 + -8) = 0x1400036d2;
      NdisInitializeEvent(local_140);
      *(undefined8 *)(puVar26 + -8) = 0x1400036e8;
      memset(&local_238,0,0xf0);
      lVar21 = plVar20[4];
      local_210 = puVar26 + 0x70;
      local_238 = 0xf00196;
      local_230 = 0;
      local_218 = 0x4010105;
      local_208 = 4;
      *(undefined8 *)(puVar26 + -8) = 0x14000371b;
      iVar17 = NdisOidRequest(lVar21,&local_238);
      if (iVar17 == 0x103) {
        *(undefined8 *)(puVar26 + -8) = 0x140003737;
        NdisWaitEvent(local_140,0);
        iVar17 = local_128;
      }
      if (iVar17 == 0) {
        uVar22 = *(uint *)(puVar26 + 0x70);
      }
      else {
        uVar22 = 0;
        *(undefined4 *)(puVar26 + 0x70) = 0;
      }
      if (0xf < uVar22) {
        uVar22 = 0;
LAB_140003762:
        *(uint *)(puVar26 + 0x70) = uVar22;
      }
    }
    else {
      if (iVar17 == 8) {
        uVar22 = 5;
        goto LAB_140003762;
      }
      if (iVar17 == 0xc) goto LAB_1400036c4;
    }
    *(uint *)((longlong)plVar20 + 0xac) = uVar22;
    lVar21 = -1;
    lVar28 = -1;
    _Src = local_118[(int)uVar22];
    do {
      lVar28 = lVar28 + 1;
    } while (_Src[lVar28] != L'\0');
    *(undefined8 *)(puVar26 + -8) = 0x14000379d;
    memmove((void *)((longlong)plVar20 + 0xc4),_Src,lVar28 * 2);
    do {
      lVar21 = lVar21 + 1;
    } while (_Src[lVar21] != L'\0');
    *(int *)(plVar20 + 0x18) = (int)lVar21 * 2;
    iVar17 = 0;
    *(ushort *)((longlong)plVar20 + 0xb2) = puVar27[1];
    *(ushort *)(plVar20 + 0x16) = *puVar27;
    plVar20[0x17] = (longlong)(plVar20 + 0x50);
    uVar9 = *puVar27;
    _Src_00 = *(void **)(puVar27 + 4);
    *(undefined8 *)(puVar26 + -8) = 0x1400037ea;
    memmove(plVar20 + 0x50,_Src_00,(ulonglong)uVar9);
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar12 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      *(undefined8 *)(puVar26 + -8) = 0x140003429;
      WPP_SF_D(uVar12,0x15,&WPP_cf979805fba431836a82e04c99ce8a90_Traceguids,iVar17);
    }
    *(undefined4 *)(plVar20 + 0x15) = 0xffffffff;
    plVar20[4] = 0;
LAB_140003553:
    *(undefined4 *)((longlong)plVar20 + 0x14) = 1;
  }
  *(undefined4 *)(plVar20 + 0x48) = 0;
  *(undefined8 *)(puVar26 + -8) = 0x140003801;
  NdisSetEvent(plVar20 + 0x45);
  if (iVar17 != 0) {
    if (iVar19 != 1) {
      if (iVar19 != 2) {
        if (iVar19 != 3) goto LAB_1400038c2;
        *(int *)(plVar20 + 3) = (int)plVar20[3] + -1;
      }
      *(undefined8 *)(puVar26 + -8) = 0x14000383f;
      NdisInitializeEvent(plVar20 + 0x39);
      lVar21 = plVar20[4];
      *(undefined8 *)(puVar26 + -8) = 0x140003850;
      iVar19 = NdisCloseAdapterEx(lVar21);
      if (iVar19 == 0x103) {
        *(undefined8 *)(puVar26 + -8) = 0x140003868;
        NdisWaitEvent(plVar20 + 0x39,0);
      }
      *(undefined8 *)(puVar26 + -8) = 0x14000387f;
      uVar16 = KeAcquireSpinLockRaiseToDpc(plVar20 + 0x4e);
      plVar23 = plVar20 + 3;
      *(int *)plVar23 = (int)*plVar23 + -1;
      *(undefined1 *)(plVar20 + 0x4f) = uVar16;
      if ((int)*plVar23 != 0) {
        *(undefined8 *)(puVar26 + -8) = 0x1400038b6;
        KeReleaseSpinLock(plVar20 + 0x4e,uVar16);
        goto LAB_1400038c2;
      }
      *(undefined8 *)(puVar26 + -8) = 0x1400038a0;
      KeReleaseSpinLock();
    }
    *(undefined8 *)(puVar26 + -8) = 0x1400038ad;
    PxFreeAdapter(plVar20);
  }
LAB_1400038c2:
  *(undefined8 *)(puVar26 + -8) = 0x1400038d3;
  return iVar17;
}



===== PxCoNotifyAfRegistration @ 140003900 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PxCoNotifyAfRegistration(longlong *param_1,int *param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined8 uVar5;
  code *pcVar6;
  longlong lVar7;
  undefined1 uVar8;
  int iVar9;
  uint uVar10;
  undefined8 *puVar11;
  uint uVar12;
  undefined2 uVar13;
  int *piVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined **ppuVar17;
  longlong *plVar18;
  longlong *plVar19;
  bool bVar20;
  undefined1 auStackY_88 [8];
  undefined1 auStackY_80 [24];
  undefined4 local_58;
  undefined4 uStack_54;
  int local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_88;
  ppuVar17 = &WPP_GLOBAL_Control;
  plVar18 = (longlong *)&WPP_cf979805fba431836a82e04c99ce8a90_Traceguids;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
            &WPP_cf979805fba431836a82e04c99ce8a90_Traceguids);
  }
  if (*param_2 == 0x800) {
    puVar16 = auStackY_88;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (puVar16 = auStackY_88, (byte)WPP_GLOBAL_Control[0x29] < 5)) goto LAB_140004035;
    uVar13 = 0x1e;
  }
  else if (*param_2 == 0x801) {
    if ((int)*param_1 != 0x20206d43) {
      plVar1 = param_1 + 0x4e;
      uVar8 = KeAcquireSpinLockRaiseToDpc(plVar1);
      *(int *)(param_1 + 3) = (int)param_1[3] + 1;
      *(undefined1 *)(param_1 + 0x4f) = uVar8;
      KeReleaseSpinLock(plVar1,uVar8);
      NdisWaitEvent(param_1 + 0x45,0);
      uVar8 = KeAcquireSpinLockRaiseToDpc(plVar1);
      puVar15 = auStackY_88;
      *(undefined1 *)(param_1 + 0x4f) = uVar8;
      uVar10 = *(uint *)((longlong)param_1 + 0x14);
      if (uVar10 < 2) {
LAB_140003fda:
        puVar16 = puVar15;
        if (((undefined **)WPP_GLOBAL_Control != ppuVar17) && (WPP_GLOBAL_Control[0x29] != '\0')) {
          uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
          *(uint *)(puVar15 + 0x20) = uVar10;
          *(undefined8 *)(puVar15 + -8) = 0x140004004;
          WPP_SF_qL(uVar5,0x21,plVar18,param_1,puVar15[0x20]);
        }
      }
      else {
        plVar4 = param_1 + 5;
        plVar18 = (longlong *)*plVar4;
        if (plVar18 != plVar4) {
          do {
            if (*(int *)((longlong)plVar18 + 0x8c) == *param_2) {
              puVar16 = auStackY_88;
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (puVar16 = auStackY_88, WPP_GLOBAL_Control[0x29] != '\0')) {
                WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
                          &WPP_cf979805fba431836a82e04c99ce8a90_Traceguids,param_1,
                          (char)*(int *)((longlong)plVar18 + 0x8c));
                puVar16 = auStackY_88;
              }
              goto LAB_140004004;
            }
            plVar18 = (longlong *)*plVar18;
          } while (plVar18 != plVar4);
        }
        if (*param_2 == 0x801) {
          plVar18 = (longlong *)ExAllocatePool2(0x40,0xd0,0x685850);
          if (plVar18 != (longlong *)0x0) {
            plVar2 = plVar18 + 0x13;
            NdisInitializeEvent(plVar2);
            plVar3 = plVar18 + 0x17;
            KeInitializeSpinLock(plVar3);
            *(undefined8 *)((longlong)plVar18 + 0x8c) = *(undefined8 *)param_2;
            *(int *)((longlong)plVar18 + 0x94) = param_2[2];
            plVar19 = plVar18 + 5;
            plVar18[6] = (longlong)plVar19;
            *plVar19 = (longlong)plVar19;
            plVar19 = plVar18 + 7;
            plVar18[8] = (longlong)plVar19;
            *plVar19 = (longlong)plVar19;
            plVar19 = plVar18 + 9;
            plVar18[10] = (longlong)plVar19;
            *plVar19 = (longlong)plVar19;
            plVar19 = plVar18 + 0xb;
            plVar18[0xc] = (longlong)plVar19;
            *plVar19 = (longlong)plVar19;
            plVar18[0xe] = (longlong)PxAfTapiTranslateTapiCallParams;
            plVar18[0xf] = (longlong)PxAfTapiTranslateNdisCallParams;
            plVar18[0x10] = (longlong)PxAfTapiTranslateTapiSap;
            *(undefined4 *)(plVar18 + 2) = 2;
            *(undefined4 *)((longlong)plVar18 + 0x14) = 1;
            plVar18[4] = (longlong)param_1;
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                       &WPP_8294867e35d63e705b52ce50c02b6694_Traceguids,plVar18);
            }
            if ((int)param_1[0x4d] == 0) {
              NdisInitializeEvent(param_1 + 0x49);
            }
            *(int *)(param_1 + 0x4d) = (int)param_1[0x4d] + 1;
            KeReleaseSpinLock(plVar1,(char)param_1[0x4f]);
            NdisInitializeEvent(plVar2);
            piVar14 = param_2;
            plVar19 = plVar18;
            iVar9 = NdisClOpenAddressFamilyEx(param_1[4],param_2,plVar18,plVar18 + 3);
            if (iVar9 == 0x103) {
              piVar14 = (int *)0x0;
              NdisWaitEvent(plVar2);
              iVar9 = (int)plVar18[0x16];
            }
            uVar8 = KeAcquireSpinLockRaiseToDpc(plVar1);
            *(undefined1 *)(param_1 + 0x4f) = uVar8;
            if (iVar9 == 0) {
              uVar8 = KeAcquireSpinLockRaiseToDpc(plVar3);
              *(undefined4 *)(plVar18 + 2) = 3;
              *(undefined1 *)(plVar18 + 0x18) = uVar8;
              KeReleaseSpinLock(plVar3,uVar8);
              puVar11 = (undefined8 *)param_1[6];
              ppuVar17 = (undefined **)0x0;
              if ((longlong *)*puVar11 != plVar4) goto LAB_140003fd3;
              *plVar18 = (longlong)plVar4;
              plVar18[1] = (longlong)puVar11;
              *puVar11 = plVar18;
              param_1[6] = (longlong)plVar18;
              bVar20 = (*(uint *)((longlong)param_1 + 0x1c) & 2) == 0;
              if (bVar20) {
                *(uint *)((longlong)param_1 + 0x1c) = *(uint *)((longlong)param_1 + 0x1c) | 1;
              }
              *(int *)(param_1 + 3) = (int)param_1[3] + 1;
              KeReleaseSpinLock(plVar1,(char)param_1[0x4f]);
              if (bVar20) {
                local_50 = param_2[2];
                _local_58 = CONCAT44((int)((ulonglong)*(undefined8 *)param_2 >> 0x20),0x800);
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (4 < (byte)WPP_GLOBAL_Control[0x29])) {
                  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
                          &WPP_cf979805fba431836a82e04c99ce8a90_Traceguids);
                }
                uVar10 = NdisCmRegisterAddressFamilyEx(param_1[9],&local_58);
                ppuVar17 = (undefined **)(ulonglong)uVar10;
                uVar8 = KeAcquireSpinLockRaiseToDpc(plVar1);
                uVar12 = *(uint *)((longlong)param_1 + 0x1c) & 0xfffffffe;
                *(undefined1 *)(param_1 + 0x4f) = uVar8;
                *(uint *)((longlong)param_1 + 0x1c) = uVar12;
                if (uVar10 == 0) {
                  *(uint *)((longlong)param_1 + 0x1c) = uVar12 | 2;
                  KeReleaseSpinLock(plVar1,uVar8);
                  goto LAB_140003edc;
                }
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (WPP_GLOBAL_Control[0x29] != '\0')) {
                  WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
                            &WPP_cf979805fba431836a82e04c99ce8a90_Traceguids,param_1[9],(char)uVar10
                           );
                }
                lVar7 = *plVar18;
                if ((*(longlong **)(lVar7 + 8) != plVar18) ||
                   (plVar4 = (longlong *)plVar18[1], (longlong *)*plVar4 != plVar18)) {
LAB_140003fd3:
                  pcVar6 = (code *)swi(0x29);
                  uVar10 = (*pcVar6)(3);
                  puVar15 = auStackY_80;
                  goto LAB_140003fda;
                }
                *plVar4 = lVar7;
                *(longlong **)(lVar7 + 8) = plVar4;
                plVar4 = (longlong *)param_1[8];
                if ((longlong *)*plVar4 != param_1 + 7) goto LAB_140003fd3;
                *plVar18 = (longlong)(param_1 + 7);
                plVar18[1] = (longlong)plVar4;
                *plVar4 = (longlong)plVar18;
                param_1[8] = (longlong)plVar18;
                KeReleaseSpinLock(plVar1,CONCAT71((int7)((ulonglong)plVar4 >> 8),(char)param_1[0x4f]
                                                 ));
                uVar8 = KeAcquireSpinLockRaiseToDpc(plVar3);
                *(undefined4 *)(plVar18 + 2) = 1;
                *(undefined1 *)(plVar18 + 0x18) = uVar8;
                KeReleaseSpinLock(plVar3,uVar8);
                iVar9 = NdisClCloseAddressFamily(plVar18[3]);
                if (iVar9 != 0x103) {
                  PxClCloseAfComplete((char)iVar9,plVar18);
                }
              }
              else {
LAB_140003edc:
                uVar8 = KeAcquireSpinLockRaiseToDpc(plVar3);
                *(int *)((longlong)plVar18 + 0x14) = *(int *)((longlong)plVar18 + 0x14) + 1;
                *(undefined1 *)(plVar18 + 0x18) = uVar8;
                KeReleaseSpinLock(plVar3,uVar8);
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8a,
                          &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
                }
                puVar11 = AllocateTapiProvider((longlong)param_1,(longlong)plVar18);
                if (((puVar11 == (undefined8 *)0x0) &&
                    ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
                   (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8b,
                          &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
                }
                uVar8 = KeAcquireSpinLockRaiseToDpc(plVar3);
                piVar14 = (int *)((longlong)plVar18 + 0x14);
                *piVar14 = *piVar14 + -1;
                *(undefined1 *)(plVar18 + 0x18) = uVar8;
                if (*piVar14 == 0) {
                  DoDerefClAfWork(plVar18);
                }
                else {
                  KeReleaseSpinLock(plVar3,uVar8);
                }
              }
              uVar8 = KeAcquireSpinLockRaiseToDpc(plVar1);
              *(undefined1 *)(param_1 + 0x4f) = uVar8;
            }
            else {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (2 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_DqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),piVar14,plVar19,*param_2,
                           (char)param_1,(char)iVar9);
              }
              PxFreeClAf(plVar18);
            }
            plVar18 = param_1 + 0x4d;
            *(int *)plVar18 = (int)*plVar18 + -1;
            puVar16 = auStackY_88;
            if ((int)*plVar18 == 0) {
              *(undefined4 *)(param_1 + 0x4c) = 0;
              NdisSetEvent(param_1 + 0x49);
              puVar16 = auStackY_88;
            }
            goto LAB_140004004;
          }
        }
        else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                  &WPP_8294867e35d63e705b52ce50c02b6694_Traceguids);
        }
        puVar16 = auStackY_88;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (puVar16 = auStackY_88, 2 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
                  &WPP_cf979805fba431836a82e04c99ce8a90_Traceguids);
          puVar16 = auStackY_88;
        }
      }
LAB_140004004:
      plVar18 = param_1 + 3;
      *(int *)plVar18 = (int)*plVar18 + -1;
      lVar7 = param_1[0x4f];
      if ((int)*plVar18 == 0) {
        *(undefined8 *)(puVar16 + -8) = 0x14000401a;
        KeReleaseSpinLock();
        *(undefined8 *)(puVar16 + -8) = 0x140004027;
        PxFreeAdapter(param_1);
      }
      else {
        *(undefined8 *)(puVar16 + -8) = 0x140004030;
        KeReleaseSpinLock(plVar1,(char)lVar7);
      }
      goto LAB_140004035;
    }
    puVar16 = auStackY_88;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (puVar16 = auStackY_88, (byte)WPP_GLOBAL_Control[0x29] < 5)) goto LAB_140004035;
    uVar13 = 0x20;
  }
  else {
    puVar16 = auStackY_88;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (puVar16 = auStackY_88, (byte)WPP_GLOBAL_Control[0x29] < 5)) goto LAB_140004035;
    uVar13 = 0x1f;
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar13,
          &WPP_cf979805fba431836a82e04c99ce8a90_Traceguids);
  puVar16 = auStackY_88;
LAB_140004035:
  *(undefined8 *)(puVar16 + -8) = 0x140004042;
  return;
}



===== PxCoOidRequestComplete @ 140004070 =====

void PxCoOidRequestComplete(int *param_1,longlong param_2,undefined4 param_3)

{
  int *piVar1;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    piVar1 = param_1 + -4;
    if (*param_1 != 0x20206d43) {
      piVar1 = param_1;
    }
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
             &WPP_cf979805fba431836a82e04c99ce8a90_Traceguids,piVar1);
  }
  *(undefined4 *)(param_2 + 0x110) = param_3;
  NdisSetEvent(param_2 + 0xf8);
  return;
}



===== PxCoReceiveNetBufferLists @ 1400040f0 =====

void PxCoReceiveNetBufferLists
               (int *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,byte param_5)

{
  int *piVar1;
  
  if ((param_5 & 2) == 0) {
    piVar1 = param_1 + -4;
    if (*param_1 != 0x20206d43) {
      piVar1 = param_1;
    }
    NdisReturnNetBufferLists(*(undefined8 *)(piVar1 + 8),param_3,0);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
            &WPP_cf979805fba431836a82e04c99ce8a90_Traceguids);
  }
  return;
}



===== PxCoSendNetBufferListsComplete @ 140004160 =====

void PxCoSendNetBufferListsComplete(void)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
            &WPP_cf979805fba431836a82e04c99ce8a90_Traceguids);
  }
  return;
}



===== PxCoStatusEx @ 1400041a0 =====

void PxCoStatusEx(undefined8 param_1,ulonglong param_2,undefined *param_3)

{
  int *piVar1;
  longlong *plVar2;
  undefined1 uVar3;
  longlong **pplVar4;
  undefined *puVar5;
  longlong *local_res20;
  
  local_res20 = (longlong *)0x0;
  puVar5 = param_3;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar5 = &WPP_cf979805fba431836a82e04c99ce8a90_Traceguids;
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
              &WPP_cf979805fba431836a82e04c99ce8a90_Traceguids,param_1,
              (char)*(undefined4 *)(param_3 + 0x14));
  }
  pplVar4 = &local_res20;
  GetVcFromCtx(param_2,(longlong *)pplVar4);
  plVar2 = local_res20;
  if (local_res20 != (longlong *)0x0) {
    if ((*(int *)(param_3 + 0x14) != 0x40010016) && (*(int *)(param_3 + 0x14) == 0x40010020)) {
      puVar5 = (undefined *)(ulonglong)*(uint *)(param_3 + 0x38);
      pplVar4 = *(longlong ***)(param_3 + 0x30);
      PxHandleReceivedDigit(local_res20,(ushort *)pplVar4,*(uint *)(param_3 + 0x38));
    }
    uVar3 = KeAcquireSpinLockRaiseToDpc(plVar2 + 0x40);
    *(undefined1 *)(plVar2 + 0x41) = uVar3;
    piVar1 = (int *)((longlong)plVar2 + 0x1c);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      DoDerefVcWork(plVar2,pplVar4,puVar5);
    }
    else {
      KeReleaseSpinLock(plVar2 + 0x40,uVar3);
    }
  }
  return;
}



===== PxCoUnbindAdapterEx @ 140004280 =====

undefined8 PxCoUnbindAdapterEx(longlong param_1,longlong *param_2,undefined *param_3)

{
  int *piVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong *plVar6;
  undefined8 *puVar7;
  code *pcVar8;
  undefined1 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined2 uVar13;
  undefined8 uVar14;
  longlong *plVar15;
  longlong *plVar16;
  undefined1 *puVar17;
  longlong *plVar18;
  int iVar19;
  longlong *unaff_R12;
  longlong *plVar20;
  bool bVar21;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  
  plVar18 = param_2 + -2;
  if ((int)*param_2 != 0x20206d43) {
    plVar18 = param_2;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_cf979805fba431836a82e04c99ce8a90_Traceguids;
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
              &WPP_cf979805fba431836a82e04c99ce8a90_Traceguids,plVar18,(char)param_1);
  }
  NdisWaitEvent(plVar18 + 0x45,0);
  plVar2 = plVar18 + 0x4e;
  uVar9 = KeAcquireSpinLockRaiseToDpc(plVar2);
  puVar17 = auStack_68;
  plVar18[0xe] = param_1;
  *(undefined4 *)((longlong)plVar18 + 0x14) = 1;
  while (*(undefined1 *)(plVar18 + 0x4f) = uVar9, (int)plVar18[0x4d] != 0) {
    KeReleaseSpinLock(plVar2,uVar9);
    NdisWaitEvent(plVar18 + 0x49,0);
    uVar9 = KeAcquireSpinLockRaiseToDpc(plVar2);
  }
LAB_140004364:
  plVar20 = (longlong *)0xffffffff;
  iVar12 = -1;
  iVar10 = -1;
  plVar5 = plVar18 + 5;
  plVar3 = (longlong *)*plVar5;
  if (plVar3 != plVar5) {
    if ((longlong *)plVar3[1] == plVar5) {
      lVar4 = *plVar3;
      if (*(longlong **)(lVar4 + 8) == plVar3) {
        *plVar5 = lVar4;
        *(longlong **)(lVar4 + 8) = plVar5;
        plVar5 = (longlong *)plVar18[8];
        if ((longlong *)*plVar5 == plVar18 + 7) {
          plVar3[1] = (longlong)plVar5;
          *plVar3 = (longlong)(plVar18 + 7);
          *plVar5 = (longlong)plVar3;
          plVar18[8] = (longlong)plVar3;
          KeReleaseSpinLock(plVar2,(char)plVar18[0x4f]);
          plVar5 = plVar3 + 0x17;
          uVar9 = KeAcquireSpinLockRaiseToDpc(plVar5);
          lVar4 = plVar3[0xd];
          *(undefined1 *)(plVar3 + 0x18) = uVar9;
          *(undefined4 *)(plVar3 + 2) = 1;
          KeReleaseSpinLock(plVar5,uVar9);
          if (lVar4 != 0) {
            uVar9 = KeAcquireSpinLockRaiseToDpc(lVar4 + 0x88);
            *(undefined1 *)(lVar4 + 0x90) = uVar9;
            MarkProviderOffline(lVar4);
            KeReleaseSpinLock(lVar4 + 0x88,*(undefined1 *)(lVar4 + 0x90));
          }
          uVar9 = KeAcquireSpinLockRaiseToDpc(plVar5);
          unaff_R12 = plVar3 + 0xb;
          do {
            *(undefined1 *)(plVar3 + 0x18) = uVar9;
            plVar15 = (longlong *)*unaff_R12;
            while( true ) {
              if (plVar15 == unaff_R12) {
                plVar15 = plVar3 + 9;
                goto LAB_140004533;
              }
              plVar16 = plVar15 + -0x3c;
              plVar20 = plVar15 + 4;
              KeAcquireSpinLockAtDpcLevel(plVar20);
              if ((*(uint *)((longlong)plVar15 + -0x1bc) & 0x1804) == 0) break;
              plVar15 = (longlong *)*plVar15;
              KeReleaseSpinLockFromDpcLevel();
            }
            *(uint *)((longlong)plVar15 + -0x1bc) = *(uint *)((longlong)plVar15 + -0x1bc) | 0x1000;
            KeReleaseSpinLockFromDpcLevel(plVar20);
            KeReleaseSpinLock(plVar5);
            uVar9 = KeAcquireSpinLockRaiseToDpc(plVar20);
            uVar14 = 0;
            *(undefined1 *)(plVar15 + 5) = uVar9;
            PxVcCleanup((longlong)plVar16,(longlong *)0x0,param_3);
            PxTapiCompleteAllIrps((longlong)plVar16);
            piVar1 = (int *)((longlong)plVar15 + -0x1c4);
            *piVar1 = *piVar1 + -1;
            if (*piVar1 == 0) {
              DoDerefVcWork(plVar16,uVar14,param_3);
            }
            else {
              KeReleaseSpinLock(plVar20,(char)plVar15[5]);
            }
            uVar9 = KeAcquireSpinLockRaiseToDpc(plVar5);
          } while( true );
        }
      }
    }
    goto LAB_14000482a;
  }
  plVar5 = plVar18 + 10;
  unaff_R12 = (longlong *)0x103;
  iVar19 = 0x103;
  while (plVar20 = (longlong *)*plVar5, plVar20 != plVar5) {
    if ((longlong *)plVar20[1] != plVar5) goto LAB_14000482a;
    lVar4 = *plVar20;
    if (*(longlong **)(lVar4 + 8) != plVar20) goto LAB_14000482a;
    *plVar5 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar5;
    plVar3 = (longlong *)plVar18[0xd];
    if ((longlong *)*plVar3 != plVar18 + 0xc) goto LAB_14000482a;
    plVar20[1] = (longlong)plVar3;
    *plVar20 = (longlong)(plVar18 + 0xc);
    *plVar3 = (longlong)plVar20;
    plVar18[0xd] = (longlong)plVar20;
    KeReleaseSpinLock(plVar2,(char)plVar18[0x4f]);
    plVar3 = plVar20 + 0xb;
    uVar9 = KeAcquireSpinLockRaiseToDpc(plVar3);
    *(int *)((longlong)plVar20 + 0x14) = *(int *)((longlong)plVar20 + 0x14) + 1;
    *(undefined1 *)(plVar20 + 0xc) = uVar9;
    *(undefined4 *)(plVar20 + 2) = 1;
    KeReleaseSpinLock(plVar3,uVar9);
    iVar11 = NdisCmNotifyCloseAddressFamily(plVar20[3]);
    if (iVar11 == 0x103) {
      NdisWaitEvent(plVar20 + 0xd,0);
    }
    uVar9 = KeAcquireSpinLockRaiseToDpc(plVar3);
    piVar1 = (int *)((longlong)plVar20 + 0x14);
    *piVar1 = *piVar1 + -1;
    *(undefined1 *)(plVar20 + 0xc) = uVar9;
    if (*piVar1 == 0) {
      DoDerefCmAfWork((longlong)plVar20);
    }
    else {
      KeReleaseSpinLock(plVar3,uVar9);
    }
    uVar9 = KeAcquireSpinLockRaiseToDpc(plVar2);
    *(undefined1 *)(plVar18 + 0x4f) = uVar9;
  }
LAB_140004831:
  *(undefined8 *)(puVar17 + -8) = 0x14000483d;
  KeReleaseSpinLock(plVar2,uVar9);
  if (*(int *)(puVar17 + 0x70) == 0x20206d43) {
    *(undefined8 *)(puVar17 + -8) = 0x1400048b9;
    NdisInitializeEvent(plVar18 + 0x3d);
    lVar4 = plVar18[9];
    *(undefined8 *)(puVar17 + -8) = 0x1400048c9;
    iVar12 = NdisCloseAdapterEx(lVar4);
    if (iVar12 == iVar19) {
      *(undefined8 *)(puVar17 + -8) = 0x1400048df;
      NdisWaitEvent(plVar18 + 0x3d,0);
    }
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 5)) goto LAB_140004915;
    uVar13 = 0x1a;
  }
  else {
    *(undefined8 *)(puVar17 + -8) = 0x14000485d;
    NdisInitializeEvent(plVar18 + 0x39);
    lVar4 = plVar18[4];
    *(undefined8 *)(puVar17 + -8) = 0x14000486d;
    iVar12 = NdisCloseAdapterEx(lVar4);
    if (iVar12 == iVar19) {
      *(undefined8 *)(puVar17 + -8) = 0x140004883;
      NdisWaitEvent(plVar18 + 0x39,0);
    }
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 5)) goto LAB_140004915;
    uVar13 = 0x19;
  }
  uVar14 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
  *(undefined8 *)(puVar17 + -8) = 0x140004915;
  WPP_SF_q(uVar14,uVar13,&WPP_cf979805fba431836a82e04c99ce8a90_Traceguids,plVar18);
LAB_140004915:
  *(undefined8 *)(puVar17 + -8) = 0x14000491f;
  uVar9 = KeAcquireSpinLockRaiseToDpc(plVar2);
  plVar5 = plVar18 + 3;
  *(int *)plVar5 = (int)*plVar5 + iVar10;
  *(undefined1 *)(plVar18 + 0x4f) = uVar9;
  if ((int)*plVar5 == 0) {
    *(undefined8 *)(puVar17 + -8) = 0x14000493c;
    KeReleaseSpinLock();
    *(undefined8 *)(puVar17 + -8) = 0x140004949;
    PxFreeAdapter(plVar18);
  }
  else {
    *(undefined8 *)(puVar17 + -8) = 0x140004952;
    KeReleaseSpinLock(plVar2,uVar9);
  }
  return 0;
LAB_140004533:
  iVar12 = (int)plVar20;
  plVar16 = (longlong *)*plVar15;
  if (plVar16 == plVar15) goto LAB_14000460b;
  if ((longlong *)plVar16[1] != plVar15) goto LAB_14000482a;
  lVar4 = *plVar16;
  if (*(longlong **)(lVar4 + 8) != plVar16) goto LAB_14000482a;
  *plVar15 = lVar4;
  *(longlong **)(lVar4 + 8) = plVar15;
  lVar4 = *unaff_R12;
  if (*(longlong **)(lVar4 + 8) != unaff_R12) goto LAB_14000482a;
  *plVar16 = lVar4;
  plVar16[1] = (longlong)unaff_R12;
  *(longlong **)(lVar4 + 8) = plVar16;
  *unaff_R12 = (longlong)plVar16;
  *(undefined1 *)(plVar16 + 6) = 0;
  KeReleaseSpinLock(plVar5);
  plVar20 = plVar16 + 4;
  uVar9 = KeAcquireSpinLockRaiseToDpc(plVar20);
  *(uint *)((longlong)plVar16 + -0x1bc) = *(uint *)((longlong)plVar16 + -0x1bc) | 0x10;
  uVar14 = 0;
  *(undefined1 *)(plVar16 + 5) = uVar9;
  PxVcCleanup((longlong)(plVar16 + -0x3c),(longlong *)0x0,param_3);
  piVar1 = (int *)((longlong)plVar16 + -0x1c4);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    DoDerefVcWork(plVar16 + -0x3c,uVar14,param_3);
  }
  else {
    KeReleaseSpinLock(plVar20,(char)plVar16[5]);
  }
  uVar9 = KeAcquireSpinLockRaiseToDpc(plVar5);
  *(undefined1 *)(plVar3 + 0x18) = uVar9;
  goto LAB_140004533;
LAB_14000460b:
  plVar20 = plVar3 + 5;
  if ((longlong *)*plVar20 != plVar20) {
    iVar12 = 1;
    plVar15 = (longlong *)*plVar20;
    do {
      LOCK();
      bVar21 = (int)plVar15[2] == 3;
      if (bVar21) {
        *(int *)(plVar15 + 2) = 1;
      }
      UNLOCK();
      plVar16 = (longlong *)*plVar15;
      if (bVar21) {
        if ((longlong *)plVar16[1] != plVar15) goto LAB_14000482a;
        plVar6 = (longlong *)plVar15[1];
        if ((longlong *)*plVar6 != plVar15) goto LAB_14000482a;
        *plVar6 = (longlong)plVar16;
        plVar16[1] = (longlong)plVar6;
        puVar7 = (undefined8 *)plVar3[8];
        if ((longlong *)*puVar7 != plVar3 + 7) goto LAB_14000482a;
        plVar15[1] = (longlong)puVar7;
        *plVar15 = (longlong)(plVar3 + 7);
        *puVar7 = plVar15;
        plVar3[8] = (longlong)plVar15;
        KeReleaseSpinLock(plVar5,(char)plVar3[0x18]);
        ClearSapWithTapiLine((longlong)plVar15);
        iVar10 = NdisClDeregisterSap(plVar15[7]);
        if (iVar10 != 0x103) {
          PxClDeregisterSapComplete((char)iVar10,plVar15);
        }
        uVar9 = KeAcquireSpinLockRaiseToDpc(plVar5);
        plVar16 = (longlong *)*plVar20;
        *(undefined1 *)(plVar3 + 0x18) = uVar9;
      }
      plVar15 = plVar16;
    } while (plVar16 != plVar20);
  }
  piVar1 = (int *)((longlong)plVar3 + 0x14);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    DoDerefClAfWork(plVar3);
  }
  else {
    KeReleaseSpinLock(plVar5,(char)plVar3[0x18]);
  }
  uVar9 = KeAcquireSpinLockRaiseToDpc(plVar2);
  *(undefined1 *)(plVar18 + 0x4f) = uVar9;
  goto LAB_140004364;
LAB_14000482a:
  iVar10 = iVar12;
  iVar19 = (int)unaff_R12;
  pcVar8 = (code *)swi(0x29);
  uVar9 = (*pcVar8)(3);
  puVar17 = auStack_60;
  goto LAB_140004831;
}



===== PxPnPReconfigure @ 140004978 =====

undefined8 PxPnPReconfigure(void)

{
  return 0xc00000bb;
}



===== PxPnPSetPower @ 140004988 =====

undefined8 PxPnPSetPower(undefined8 param_1,longlong param_2)

{
  if (**(int **)(param_2 + 8) == 1) {
    return 0;
  }
  return 0xc00000bb;
}



===== PxReceiveNetBufferLists @ 1400049b0 =====

void PxReceiveNetBufferLists(void)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
            &WPP_cf979805fba431836a82e04c99ce8a90_Traceguids);
  }
  return;
}



===== PxSendNetBufferListsComplete @ 1400049f0 =====

void PxSendNetBufferListsComplete(void)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
            &WPP_cf979805fba431836a82e04c99ce8a90_Traceguids);
  }
  return;
}



===== PxSetOptionsHandler @ 140004a30 =====

int PxSetOptionsHandler(undefined8 param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 local_178;
  undefined4 local_174;
  code *local_170;
  code *local_168;
  code *local_160;
  code *local_158;
  undefined4 local_148;
  undefined4 local_144;
  code *local_140;
  code *local_138;
  code *local_130;
  code *local_128;
  code *local_120;
  code *local_118;
  code *local_110;
  code *local_108;
  code *local_100;
  code *local_f8;
  code *local_f0;
  code *local_e8;
  code *local_e0;
  code *local_d8;
  code *local_d0;
  code *local_c8;
  code *local_c0;
  undefined4 local_b8;
  undefined4 local_b4;
  code *local_b0;
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
  code *local_30;
  code *local_28;
  code *local_20;
  
  local_174 = 0;
  local_b4 = 0;
  local_144 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_cf979805fba431836a82e04c99ce8a90_Traceguids);
  }
  DAT_14000d7c8 = NdisAllocateRWLock(param_1);
  if (DAT_14000d7c8 == 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3fffffff;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
      return -0x3fffffff;
    }
    uVar2 = 0xb;
  }
  else {
    DAT_14000d7b8 = &DAT_14000d7b0;
    DAT_14000d7a4 = 500;
    DAT_14000d7b0 = &DAT_14000d7b0;
    DAT_14000d7c0 = ExAllocatePool2(0x40,4000,0x325850);
    if (DAT_14000d7c0 == 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3fffffff;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
        return -0x3fffffff;
      }
      uVar2 = 0xc;
    }
    else {
      DAT_14000d7f8 = NdisAllocateRWLock(param_1);
      if (DAT_14000d7f8 == 0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return -0x3fffffff;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
          return -0x3fffffff;
        }
        uVar2 = 0xd;
      }
      else {
        DAT_14000d7e4 = 500;
        DAT_14000d7f0 = ExAllocatePool2(0x40,4000,0x6c5850);
        if (DAT_14000d7f0 != 0) {
          local_178 = 0x280190;
          local_168 = PxCoNotifyAfRegistration;
          local_170 = PxCoStatusEx;
          local_160 = PxCoReceiveNetBufferLists;
          local_158 = PxCoSendNetBufferListsComplete;
          iVar1 = NdisSetOptionalHandlers(param_1,&local_178);
          if (iVar1 == 0) {
            local_b8 = 0xa001a6;
            local_b0 = PxClCreateVc;
            local_a8 = PxClDeleteVc;
            local_a0 = PxClOidRequest;
            local_98 = PxClOidRequestComplete;
            local_90 = PxClOpenAfCompleteEx;
            local_88 = PxClCloseAfComplete;
            local_80 = PxClRegisterSapComplete;
            local_78 = PxClDeregisterSapComplete;
            local_70 = PxClMakeCallComplete;
            local_68 = PxClIncomingDropParty;
            local_60 = PxClCloseCallComplete;
            local_58 = PxClIncomingDropParty;
            local_50 = PxClIncomingDropParty;
            local_48 = PxClIncomingCall;
            local_40 = PxClIncomingDropParty;
            local_38 = PxClIncomingCloseCall;
            local_30 = PxClIncomingDropParty;
            local_28 = PxClCallConnected;
            local_20 = PxClNotifyCloseAf;
            iVar1 = NdisSetOptionalHandlers(param_1,&local_b8);
            if (iVar1 == 0) {
              local_148 = 0x9001a5;
              local_140 = PxCmCreateVc;
              local_138 = PxCmDeleteVc;
              local_130 = PxCmOpenAf;
              local_128 = PxCmCloseAf;
              local_120 = PxCmRegisterSap;
              local_118 = PxCmDeRegisterSap;
              local_110 = PxPnPCancelRemove;
              local_108 = PxCmCloseCall;
              local_100 = PxCmIncomingCallComplete;
              local_f8 = PxPnPCancelRemove;
              local_f0 = PxPnPCancelRemove;
              local_e8 = _guard_check_icall;
              local_e0 = _guard_check_icall;
              local_d8 = PxPnPCancelRemove;
              local_d0 = PxPnPCancelRemove;
              local_c8 = PxCmOidRequestComplete;
              local_c0 = PxCmNotifyCloseAfComplete;
              iVar1 = NdisSetOptionalHandlers(param_1,&local_148);
              if (iVar1 == 0) {
                return 0;
              }
              if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                return iVar1;
              }
              if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
                return iVar1;
              }
              uVar2 = 0x11;
            }
            else {
              if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                return iVar1;
              }
              if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
                return iVar1;
              }
              uVar2 = 0x10;
            }
          }
          else {
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return iVar1;
            }
            if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
              return iVar1;
            }
            uVar2 = 0xf;
          }
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
                   &WPP_cf979805fba431836a82e04c99ce8a90_Traceguids,iVar1);
          return iVar1;
        }
        DAT_14000d7f0 = 0;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          DAT_14000d7f0 = 0;
          return -0x3fffffff;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
          DAT_14000d7f0 = 0;
          return -0x3fffffff;
        }
        uVar2 = 0xe;
      }
    }
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
          &WPP_cf979805fba431836a82e04c99ce8a90_Traceguids);
  return -0x3fffffff;
}



===== WPP_SF_DDDDDDDDDDD @ 140004eb8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDDDDDDDDDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                       undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                       undefined1 param_9,undefined1 param_10,undefined1 param_11,
                       undefined1 param_12,undefined1 param_13,undefined1 param_14)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,4,&param_7,4,&param_8,4,
             &param_9,4,&param_10,4,&param_11,4,&param_12,4,&param_13,4,&param_14,4,0);
  return;
}



===== WPP_SF_DqD @ 140004f88 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DqD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_cf979805fba431836a82e04c99ce8a90_Traceguids,0x24,local_res20,4,
             &param_5,8,&param_6,4,0);
  return;
}



===== WPP_SF_S @ 140004ff0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_S(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4)

{
  longlong lVar1;
  
  if (param_4 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_cf979805fba431836a82e04c99ce8a90_Traceguids,param_2,param_4,lVar1,0);
  return;
}



===== WPP_SF_dD @ 140005064 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_cf979805fba431836a82e04c99ce8a90_Traceguids,0x27,local_res20,4,
             &param_5,4,0);
  return;
}



===== PxIOCleanup @ 1400050c0 =====

undefined8 PxIOCleanup(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  bool bVar6;
  undefined1 uVar7;
  longlong **pplVar8;
  ulonglong uVar9;
  int iVar10;
  undefined8 uVar11;
  undefined2 local_res10;
  undefined1 local_res12;
  longlong *local_res18 [2];
  
  local_res18[0] = (longlong *)0x0;
  uVar9 = 0;
  local_res10 = 0;
  local_res12 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
            &WPP_49acb68b66733a55de6af06c8932e04d_Traceguids);
  }
  uVar11 = 0;
  NdisAcquireRWLockRead(DAT_14000d7c8,&local_res10);
  iVar10 = VcTable;
  while ((VcTable != 0 && (iVar10 != 0))) {
    NdisReleaseRWLock(DAT_14000d7c8,&local_res10);
    pplVar8 = local_res18;
    bVar6 = IsVcValid(uVar9,(longlong *)pplVar8);
    plVar5 = local_res18[0];
    uVar9 = (ulonglong)((int)uVar9 + 1);
    if (bVar6) {
      plVar2 = local_res18[0] + 0x40;
      uVar7 = KeAcquireSpinLockRaiseToDpc(plVar2);
      *(undefined1 *)(plVar5 + 0x41) = uVar7;
      if ((*(uint *)((longlong)plVar5 + 0x24) & 0x1804) == 0) {
        pplVar8 = (longlong **)0x0;
        *(uint *)((longlong)plVar5 + 0x24) = *(uint *)((longlong)plVar5 + 0x24) | 0x800;
        PxVcCleanup((longlong)plVar5,(longlong *)0x0,uVar11);
        PxTapiCompleteAllIrps((longlong)plVar5);
        *(int *)((longlong)plVar5 + 0x1c) = *(int *)((longlong)plVar5 + 0x1c) + -1;
      }
      piVar1 = (int *)((longlong)plVar5 + 0x1c);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        DoDerefVcWork(plVar5,pplVar8,uVar11);
      }
      else {
        KeReleaseSpinLock(plVar2,(char)plVar5[0x41]);
      }
      iVar10 = iVar10 + -1;
    }
    uVar11 = 0;
    NdisAcquireRWLockRead(DAT_14000d7c8,&local_res10);
  }
  NdisReleaseRWLock(DAT_14000d7c8,&local_res10);
  DAT_14000d788 = KeAcquireSpinLockRaiseToDpc(&DAT_14000d780);
  lVar4 = DAT_14000d778;
  if ((DAT_14000d778 != 0) && (*(longlong *)(DAT_14000d778 + 0xc0) == *(longlong *)(param_2 + 0xc0))
     ) {
    LOCK();
    lVar3 = *(longlong *)(DAT_14000d778 + 0x68);
    *(longlong *)(DAT_14000d778 + 0x68) = 0;
    UNLOCK();
    if (lVar3 != 0) {
      DAT_14000d778 = 0;
      *(undefined8 *)(lVar4 + 0x38) = 0;
      *(undefined4 *)(lVar4 + 0x30) = 0xc0000120;
      KeReleaseSpinLock(&DAT_14000d780,DAT_14000d788);
      IofCompleteRequest(lVar4,0);
      DAT_14000d788 = KeAcquireSpinLockRaiseToDpc(&DAT_14000d780);
    }
  }
  KeReleaseSpinLock(&DAT_14000d780,DAT_14000d788);
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
            &WPP_49acb68b66733a55de6af06c8932e04d_Traceguids);
  }
  return 0;
}



===== PxIOClose @ 140005320 =====

undefined8 PxIOClose(undefined8 param_1,longlong param_2)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
            &WPP_49acb68b66733a55de6af06c8932e04d_Traceguids);
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== PxIOCreate @ 140005380 =====

undefined8 PxIOCreate(undefined8 param_1,longlong param_2)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
             &WPP_49acb68b66733a55de6af06c8932e04d_Traceguids,param_2);
  }
  if (g_fPagesLocked == '\0') {
    MmLockPagableDataSection(PxVcCleanup);
    g_fPagesLocked = '\x01';
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== PxIODispatch @ 140005410 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PxIODispatch(longlong param_1,longlong param_2,undefined8 param_3)

{
  byte *pbVar1;
  int iVar2;
  char *pcVar3;
  uint *puVar4;
  longlong lVar5;
  bool bVar6;
  undefined1 uVar7;
  undefined2 uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  undefined8 *puVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  ulonglong local_res10;
  
  iVar10 = 0;
  uVar15 = 0;
  pcVar3 = *(char **)(param_2 + 0xb8);
  puVar4 = *(uint **)(param_2 + 0x18);
  uVar12 = *(uint *)(pcVar3 + 0x10);
  uVar9 = *(uint *)(pcVar3 + 8);
  uVar16 = (ulonglong)uVar9;
  if ((*pcVar3 != '\x0e') || (param_1 != *(longlong *)(DeviceExtension + 0x10))) {
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
    IofCompleteRequest(param_2,0);
    return -0x3fffff45;
  }
  iVar2 = *(int *)(pcVar3 + 0x18);
  if (iVar2 == -0x7000dc40) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
               &WPP_49acb68b66733a55de6af06c8932e04d_Traceguids,param_2);
    }
    if ((uVar12 < 8) || (uVar9 < 4)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar8 = 0x10;
        goto LAB_140005d29;
      }
      goto LAB_140005d35;
    }
    DAT_14000d850 = KeAcquireSpinLockRaiseToDpc(&DAT_14000d848);
    *puVar4 = DAT_14000d838;
    TspCB = 0;
    for (puVar13 = DAT_14000d828; (undefined8 **)puVar13 != &DAT_14000d828;
        puVar13 = (undefined8 *)*puVar13) {
      uVar7 = KeAcquireSpinLockRaiseToDpc(puVar13 + 0x11);
      *(undefined1 *)(puVar13 + 0x12) = uVar7;
      if (*(int *)(puVar13 + 2) == 0) {
        MarkProviderConnected((longlong)puVar13);
      }
      KeReleaseSpinLock(puVar13 + 0x11,*(undefined1 *)(puVar13 + 0x12));
    }
LAB_140005553:
    uVar15 = 4;
LAB_140005559:
    KeReleaseSpinLock(&DAT_14000d848,DAT_14000d850);
    uVar16 = uVar15;
  }
  else if (iVar2 == -0x7000dc3c) {
    DAT_14000d850 = KeAcquireSpinLockRaiseToDpc(&DAT_14000d848);
    TspCB = 3;
    for (puVar13 = DAT_14000d828; (undefined8 **)puVar13 != &DAT_14000d828;
        puVar13 = (undefined8 *)*puVar13) {
      uVar7 = KeAcquireSpinLockRaiseToDpc(puVar13 + 0x11);
      *(undefined1 *)(puVar13 + 0x12) = uVar7;
      if (*(int *)(puVar13 + 2) == 0) {
        MarkProviderDisconnected((longlong)puVar13);
      }
      KeReleaseSpinLock(puVar13 + 0x11,*(undefined1 *)(puVar13 + 0x12));
    }
    KeReleaseSpinLock(&DAT_14000d848,DAT_14000d850);
    uVar16 = 0;
  }
  else if ((iVar2 + 0x7000dc38U & 0xfffffffb) == 0) {
    if ((uVar12 < 0x38) || (uVar9 < 0x38)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_LL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                  &WPP_49acb68b66733a55de6af06c8932e04d_Traceguids,uVar12,0x38);
      }
      iVar10 = -0x3ffffffc;
      uVar16 = uVar15;
    }
    else {
      uVar15 = 0x38;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_qDdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_1,param_3,param_2,
                    (char)puVar4[8],(char)puVar4[9],(char)puVar4[0xc]);
      }
      iVar2 = puVar4[8] + 0xf8fcfeff;
      if ((iVar2 < 0) || (uVar14 = (ulonglong)iVar2, 0x23 < uVar14)) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (2 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_Dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_1,param_3,puVar4[8],(char)iVar2
                   );
        }
        puVar4[7] = 0xc001201d;
        uVar16 = uVar15;
      }
      else {
        uVar9 = puVar4[10];
        uVar11 = *(uint *)(&DAT_14000d004 + uVar14 * 0x10);
        if (uVar9 < uVar11) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (2 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar8 = 0x14;
LAB_1400059e0:
            WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,param_3,uVar9,(char)uVar11);
          }
        }
        else {
          uVar11 = uVar12 - 0x30;
          if (uVar9 <= uVar11) {
            DAT_14000d850 = KeAcquireSpinLockRaiseToDpc(&DAT_14000d848);
            if (TspCB == 0) {
              DAT_14000d83c = DAT_14000d83c + 1;
              if (DAT_14000d83c == 0xffffffff) {
                DAT_14000d83c = 0x80000001;
              }
              puVar4[6] = DAT_14000d83c;
              *(longlong *)(puVar4 + 4) = param_2;
              KeReleaseSpinLock(&DAT_14000d848,DAT_14000d850);
              pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
              *pbVar1 = *pbVar1 | 1;
              uVar12 = (*(code *)(&PTR_PxTapiAccept_14000d008)[uVar14 * 2])(puVar4);
              if (uVar12 == 0x103) {
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (4 < (byte)WPP_GLOBAL_Control[0x29])) {
                  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                          &WPP_49acb68b66733a55de6af06c8932e04d_Traceguids);
                }
                return 0x103;
              }
              uVar9 = puVar4[10];
              puVar4[7] = uVar12;
              LOCK();
              *(undefined8 *)(param_2 + 0x68) = 0;
              UNLOCK();
              if ((ulonglong)uVar9 + 0x38 <= uVar16) {
                uVar16 = (ulonglong)(uVar9 + 0x38);
              }
            }
            else {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (2 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                        &WPP_49acb68b66733a55de6af06c8932e04d_Traceguids);
              }
              KeReleaseSpinLock(&DAT_14000d848,DAT_14000d850);
              puVar4[7] = 0x1001;
              uVar16 = uVar15;
            }
            goto LAB_140005d3a;
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (2 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar8 = 0x15;
            goto LAB_1400059e0;
          }
        }
        puVar4[7] = 0xc0012019;
        uVar16 = uVar15;
      }
    }
  }
  else if (iVar2 == -0x7000dc30) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
              &WPP_49acb68b66733a55de6af06c8932e04d_Traceguids);
    }
    if (uVar12 < 0xc) {
      iVar10 = -0x3fffffdd;
      uVar15 = 4;
      uVar16 = uVar15;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar8 = 0x19;
LAB_1400054ed:
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                &WPP_49acb68b66733a55de6af06c8932e04d_Traceguids);
        uVar16 = uVar15;
      }
    }
    else if (uVar16 - 0xb < (ulonglong)*puVar4) {
      iVar10 = -0x3fffffdd;
      uVar15 = 4;
      uVar16 = uVar15;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar8 = 0x1a;
        goto LAB_1400054ed;
      }
    }
    else {
      DAT_14000d788 = KeAcquireSpinLockRaiseToDpc(&DAT_14000d780);
      if (DAT_14000d770 == 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                  &WPP_49acb68b66733a55de6af06c8932e04d_Traceguids);
        }
        if (DAT_14000d778 == 0) {
          LOCK();
          *(code **)(param_2 + 0x68) = PxCancelGetEvents;
          UNLOCK();
          pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
          *pbVar1 = *pbVar1 | 1;
          *(undefined8 *)(param_2 + 0x38) = 0;
          iVar10 = 0x103;
          *(undefined4 *)(param_2 + 0x30) = 0x103;
          uVar16 = uVar15;
          DAT_14000d778 = param_2;
        }
        else {
          iVar10 = -0x3fffffff;
          uVar16 = 4;
        }
      }
      else {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_LL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                    &WPP_49acb68b66733a55de6af06c8932e04d_Traceguids,DAT_14000d770,(char)*puVar4);
        }
        uVar15 = GetLineEvents((longlong)(puVar4 + 2),*puVar4);
        puVar4[1] = (uint)uVar15;
        if ((uVar15 & 0xffffffff) + 0xb <= uVar16) {
          uVar16 = (ulonglong)((uint)uVar15 + 0xb);
        }
      }
      KeReleaseSpinLock(&DAT_14000d780,DAT_14000d788);
      if (iVar10 == 0x103) goto LAB_140005d61;
    }
  }
  else if (iVar2 == -0x7000dc2c) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                &WPP_49acb68b66733a55de6af06c8932e04d_Traceguids,param_2,(char)uVar12);
    }
    if (uVar12 < 4) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar8 = 0x1e;
LAB_140005d29:
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                &WPP_49acb68b66733a55de6af06c8932e04d_Traceguids);
      }
      goto LAB_140005d35;
    }
    DAT_14000d850 = KeAcquireSpinLockRaiseToDpc(&DAT_14000d848);
    if (TspCB != 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                &WPP_49acb68b66733a55de6af06c8932e04d_Traceguids);
      }
      iVar10 = -0x3fffffff;
      goto LAB_140005559;
    }
    uVar12 = *puVar4;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
               &WPP_49acb68b66733a55de6af06c8932e04d_Traceguids,uVar12);
    }
    KeReleaseSpinLock(&DAT_14000d848,DAT_14000d850);
    local_res10 = local_res10 & 0xffffffffff000000;
    NdisAcquireRWLockRead(DAT_14000d7f8,&local_res10,0);
    uVar9 = 0;
    if (DAT_14000d7e4 != 0) {
      do {
        lVar5 = *(longlong *)(DAT_14000d7f0 + (ulonglong)uVar9 * 8);
        if (lVar5 != 0) {
          *(uint *)(lVar5 + 0x20) = uVar12;
          uVar12 = uVar12 + 1;
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < DAT_14000d7e4);
    }
    NdisReleaseRWLock(DAT_14000d7f8,&local_res10);
    uVar16 = uVar15;
  }
  else if (iVar2 == -0x7000dc28) {
    local_res10 = 0;
    if (uVar12 < 8) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar8 = 0x21;
        goto LAB_140005d29;
      }
      goto LAB_140005d35;
    }
    bVar6 = IsTapiLineValid(*puVar4,(longlong *)&local_res10);
    uVar16 = local_res10;
    if (bVar6) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
                  &WPP_49acb68b66733a55de6af06c8932e04d_Traceguids,local_res10,(char)puVar4[1]);
      }
      *(uint *)(uVar16 + 0x20) = puVar4[1];
      uVar16 = uVar15;
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
                 &WPP_49acb68b66733a55de6af06c8932e04d_Traceguids,*puVar4);
      }
      iVar10 = -0x3ffffff3;
      uVar16 = uVar15;
    }
  }
  else if (iVar2 == -0x7000dc24) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
               &WPP_49acb68b66733a55de6af06c8932e04d_Traceguids,param_2);
    }
    if ((7 < uVar12) && (3 < uVar9)) {
      DAT_14000d850 = KeAcquireSpinLockRaiseToDpc(&DAT_14000d848);
      *puVar4 = DAT_14000d838;
      goto LAB_140005553;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar8 = 0x25;
      goto LAB_140005d29;
    }
LAB_140005d35:
    iVar10 = -0x3fffffdd;
    uVar16 = uVar15;
  }
  else {
    iVar10 = -0x3ffffff3;
    uVar16 = uVar15;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar8 = 0x26;
      goto LAB_1400054ed;
    }
  }
LAB_140005d3a:
  *(ulonglong *)(param_2 + 0x38) = uVar16;
  *(int *)(param_2 + 0x30) = iVar10;
  pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
  *pbVar1 = *pbVar1 & 0xfe;
  IofCompleteRequest(param_2,0);
LAB_140005d61:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
              &WPP_49acb68b66733a55de6af06c8932e04d_Traceguids,param_2,(char)iVar10);
  }
  return iVar10;
}



===== PxUnload @ 140005de0 =====

void PxUnload(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined1 uVar5;
  undefined1 *puVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
            &WPP_49acb68b66733a55de6af06c8932e04d_Traceguids);
  }
  if ((DeviceExtension != 0) && (*(longlong *)(DeviceExtension + 0x18) != 0)) {
    NdisDeregisterProtocolDriver();
    *(undefined8 *)(DeviceExtension + 0x18) = 0;
  }
  DAT_14000d788 = KeAcquireSpinLockRaiseToDpc(&DAT_14000d780);
  puVar6 = auStack_28;
  while ((undefined8 **)TspEventList != &TspEventList) {
    if (((undefined8 **)TspEventList[1] != &TspEventList) ||
       (puVar1 = (undefined8 *)*TspEventList, (undefined8 *)puVar1[1] != TspEventList))
    goto LAB_140005fc7;
    TspEventList = puVar1;
    puVar1[1] = &TspEventList;
    ExFreeToNPagedLookasideList(&ProviderEventLookaside);
  }
  KeReleaseSpinLock(&DAT_14000d780,CONCAT71(0x14000d7,DAT_14000d788));
  ExDeleteNPagedLookasideList(&ProviderEventLookaside);
  ExDeleteNPagedLookasideList(&VcLookaside);
  if (*(longlong *)(DeviceExtension + 0x10) != 0) {
    IoDeleteDevice();
  }
  if (DAT_14000d7c8 != 0) {
    NdisFreeRWLock();
    DAT_14000d7c8 = 0;
  }
  if (DAT_14000d7c0 != 0) {
    ExFreePoolWithTag(DAT_14000d7c0,0);
    DAT_14000d7c0 = 0;
  }
  uVar5 = KeAcquireSpinLockRaiseToDpc(&DAT_14000d848);
  while( true ) {
    puVar1 = DAT_14000d828;
    DAT_14000d850 = uVar5;
    if ((undefined8 **)DAT_14000d828 == &DAT_14000d828) break;
    if (((undefined8 **)DAT_14000d828[1] != &DAT_14000d828) ||
       (puVar2 = (undefined8 *)*DAT_14000d828, (undefined8 *)puVar2[1] != DAT_14000d828))
    goto LAB_140005fc7;
    DAT_14000d828 = puVar2;
    puVar2[1] = &DAT_14000d828;
    KeReleaseSpinLock(&DAT_14000d848,DAT_14000d850);
    FreeTapiProvider((longlong)puVar1);
    uVar5 = KeAcquireSpinLockRaiseToDpc(&DAT_14000d848);
  }
LAB_140005fce:
  *(undefined8 *)(puVar6 + -8) = 0x140005fde;
  KeReleaseSpinLock(&DAT_14000d848,uVar5);
  if (DAT_14000d7f8 != 0) {
    *(undefined8 *)(puVar6 + -8) = 0x140005ff6;
    NdisFreeRWLock();
    DAT_14000d7f8 = 0;
  }
  if (DAT_14000d7f0 != 0) {
    *(undefined8 *)(puVar6 + -8) = 0x140006018;
    ExFreePoolWithTag(DAT_14000d7f0,0);
    DAT_14000d7f0 = 0;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(undefined8 *)(puVar6 + -8) = 0x14000604c;
    WPP_SF_(uVar3,0xc,&WPP_49acb68b66733a55de6af06c8932e04d_Traceguids);
  }
  *(undefined8 *)(puVar6 + -8) = 0x140006051;
  WppCleanupKm();
  if (g_wil_details_featureChangeNotification != 0) {
    *(undefined8 *)(puVar6 + -8) = 0x140006064;
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    *(undefined8 *)(puVar6 + -8) = 0x140006084;
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
  return;
LAB_140005fc7:
  pcVar4 = (code *)swi(0x29);
  uVar5 = (*pcVar4)(3);
  puVar6 = auStack_20;
  goto LAB_140005fce;
}



===== WPP_SF_LL @ 1400060b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_LL(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,0);
  return;
}



===== WPP_SF_Dd @ 140006100 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_49acb68b66733a55de6af06c8932e04d_Traceguids,0x13,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_dd @ 140006158 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_49acb68b66733a55de6af06c8932e04d_Traceguids,param_2,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_qDdD @ 1400061b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDdD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_49acb68b66733a55de6af06c8932e04d_Traceguids,0x12,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WppClassicProviderCallback @ 140006230 =====

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



===== wil_details_RecordCachedUsage @ 140006264 =====

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



===== wil_details_RecordFeatureUsageReporting @ 1400063c0 =====

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



===== AllocateTapiAddr @ 140006444 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong AllocateTapiAddr(longlong param_1,longlong param_2,int param_3)

{
  longlong lVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  longlong lVar6;
  void *_Dst;
  undefined8 uVar7;
  ulonglong _Size;
  undefined1 auStackY_188 [32];
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_138;
  undefined4 *local_130;
  int local_128;
  int local_120;
  undefined1 local_60 [24];
  int local_48;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_188;
  lVar6 = *(longlong *)(param_1 + 0x18);
  lVar1 = *(longlong *)(param_1 + 0x20);
  memset(&local_158,0,0x118);
  puVar5 = (undefined4 *)ExAllocatePool2(0x40,0x1000,0x635850);
  if (puVar5 == (undefined4 *)0x0) {
    return 0;
  }
  *puVar5 = *(undefined4 *)(param_2 + 0x34);
  puVar5[1] = param_3;
  puVar5[3] = 0xff4;
  if (*(char *)(param_1 + 100) == '\0') {
    puVar5[5] = 0xe4;
    puVar5[4] = 0xe4;
    puVar5[3] = 0xe4;
    puVar5[0x18] = 1000;
  }
  else if (((*(uint *)(param_2 + 0x24) & 1) == 0) && (param_3 != 0)) {
    puVar2 = *(uint **)(*(longlong *)(param_2 + 0x60) + 0x28);
    if (0xff4 < *puVar2) {
      ExFreePoolWithTag(puVar5,0);
      uVar3 = *puVar2;
      puVar5 = (undefined4 *)ExAllocatePool2(0x40,uVar3 + 0xc,0x635850);
      if (puVar5 == (undefined4 *)0x0) {
        return 0;
      }
      *puVar5 = *(undefined4 *)(param_2 + 0x34);
      puVar5[1] = param_3;
      puVar5[3] = uVar3;
    }
    memmove(puVar5 + 3,puVar2,(ulonglong)puVar2[2]);
  }
  else {
    local_150 = 0;
    local_14c = 0;
    local_158 = 0xf00196;
    NdisInitializeEvent(local_60);
    local_154 = 0;
    local_138 = 0xfe001003;
    local_128 = 0x1000;
    local_130 = puVar5;
    iVar4 = NdisCoOidRequest(*(undefined8 *)(lVar6 + 0x20),*(undefined8 *)(lVar1 + 0x18),0,0);
    if (iVar4 == 0x103) {
      NdisWaitEvent(local_60,0);
      iVar4 = local_48;
    }
    if (iVar4 == -0x3ffeffec) {
      ExFreePoolWithTag(puVar5,0);
      puVar5 = (undefined4 *)ExAllocatePool2(0x40,local_120,0x635850);
      if (puVar5 == (undefined4 *)0x0) {
        return 0;
      }
      *puVar5 = *(undefined4 *)(param_2 + 0x34);
      puVar5[1] = param_3;
      puVar5[3] = local_120 + -0xc;
      memset(&local_158,0,0x118);
      local_150 = 0;
      local_14c = 0;
      local_158 = 0xf00196;
      NdisInitializeEvent(local_60);
      local_154 = 0;
      local_138 = 0xfe001003;
      local_128 = local_120;
      local_130 = puVar5;
      iVar4 = NdisCoOidRequest(*(undefined8 *)(lVar6 + 0x20),*(undefined8 *)(lVar1 + 0x18),0,0);
      if (iVar4 == 0x103) {
        NdisWaitEvent(local_60,0);
        iVar4 = local_48;
      }
    }
    if (iVar4 != 0) goto LAB_1400067be;
  }
  uVar3 = puVar5[5];
  if (uVar3 < 0xe4) {
    puVar5[5] = 0xe4;
    uVar3 = 0xe4;
  }
  lVar6 = ExAllocatePool2(0x40,uVar3 + 0x88,0x645850);
  if (lVar6 != 0) {
    _Dst = (void *)(lVar6 + 0x40U & 0xfffffffffffffff8);
    *(void **)(lVar6 + 0x28) = _Dst;
    *(ulonglong *)(lVar6 + 0x30) =
         (ulonglong)(uint)puVar5[5] + 8 + (longlong)_Dst & 0xfffffffffffffff8;
    _Size = (ulonglong)(uint)puVar5[5];
    memmove(_Dst,puVar5 + 3,_Size);
    puVar2 = *(uint **)(lVar6 + 0x28);
    if (*puVar2 < puVar2[2]) {
      *puVar2 = puVar2[2];
    }
    uVar3 = *(uint *)(param_2 + 0x20);
    uVar7 = 0;
    puVar2[0x11] = 0;
    puVar2[0x13] = 0;
    puVar2[3] = uVar3;
    puVar2[8] = 1;
    puVar2[9] = 0x20;
    puVar2[10] = 0x1c;
    puVar2[0x10] = 0x4347;
    puVar2[0x12] = 8;
    puVar2[0x14] = 0x61;
    *(longlong *)(lVar6 + 0x18) = param_2;
    *(int *)(lVar6 + 0x20) = param_3;
    ExFreePoolWithTag(puVar5);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qdq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,_Size,lVar6,
                 (char)*(undefined4 *)(lVar6 + 0x20),(char)param_2);
    }
    return lVar6;
  }
LAB_1400067be:
  ExFreePoolWithTag(puVar5,0);
  return 0;
}



===== AllocateTapiLine @ 140006800 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong AllocateTapiLine(longlong param_1,int param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint *_Src;
  undefined4 *puVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  longlong *plVar13;
  longlong lVar14;
  ulonglong uVar15;
  longlong *plVar16;
  void *_Dst;
  undefined1 *puVar17;
  undefined1 *puVar18;
  uint *_Dst_00;
  uint uVar19;
  undefined1 auStack_198 [8];
  undefined1 auStack_190 [24];
  longlong local_160;
  undefined4 local_158;
  undefined4 local_154;
  undefined8 local_150;
  undefined4 local_138;
  longlong *local_130;
  uint local_128;
  uint local_120;
  undefined1 local_60 [24];
  int local_48;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_198;
  lVar14 = *(longlong *)(param_1 + 0x18);
  lVar2 = *(longlong *)(param_1 + 0x20);
  local_160 = lVar14;
  memset(&local_158,0,0x118);
  plVar13 = (longlong *)ExAllocatePool2(0x40,0x1000,0x615850);
  if (plVar13 != (longlong *)0x0) {
    *(int *)plVar13 = param_2;
    _Dst_00 = (uint *)(plVar13 + 1);
    *_Dst_00 = 0xff8;
    if (*(char *)(param_1 + 100) == '\0') {
      *(int *)((longlong)plVar13 + 4) = 0;
      *(int *)(plVar13 + 2) = 0x124;
      *(int *)((longlong)plVar13 + 0xc) = 0x124;
      *_Dst_00 = 0x124;
      *(int *)(plVar13 + 6) = 1;
      *(int *)((longlong)plVar13 + 0x34) = 1;
      *(int *)(plVar13 + 7) = 1;
      *(int *)((longlong)plVar13 + 0x3c) = 9;
      *(int *)((longlong)plVar13 + 0x44) = 0x100;
      *(int *)((longlong)plVar13 + 0x7c) = 1000;
      local_150 = 0;
      local_160 = 0;
      local_158 = 0xf00196;
      NdisInitializeEvent(local_60);
      local_154 = 0;
      local_130 = &local_160;
      local_138 = 0x10107;
      local_128 = 8;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x90,
                   &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,
                   *(undefined4 *)(DeviceExtension + 0x30));
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x91,
                  &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
        }
      }
      iVar10 = NdisCoOidRequest(*(undefined8 *)(lVar14 + 0x20),*(undefined8 *)(lVar2 + 0x18),0,0);
      if (iVar10 == 0x103) {
        NdisWaitEvent(local_60,0);
        iVar10 = local_48;
      }
      iVar11 = 0x1f400;
      if (iVar10 == 0) {
        iVar11 = (int)local_160;
      }
      *(int *)(plVar13 + 8) = iVar11;
LAB_140006bb8:
      if (((ulonglong)*(uint *)(plVar13 + 7) * 8 < 0x100000000) &&
         (uVar12 = (int)((ulonglong)*(uint *)(plVar13 + 7) * 8) + 0xec, 0xeb < uVar12)) {
        uVar19 = *(uint *)(plVar13 + 2);
        if (uVar19 < 0x124) {
          *(int *)(plVar13 + 2) = 0x124;
          uVar19 = 0x124;
        }
        if ((uVar12 <= uVar19 + uVar12) &&
           (lVar14 = ExAllocatePool2(0x40,uVar19 + uVar12,0x625850), lVar14 != 0)) {
          _Dst = (void *)(lVar14 + 0x90U & 0xfffffffffffffff8);
          *(void **)(lVar14 + 0x48) = _Dst;
          uVar15 = (ulonglong)uVar19 + 8 + (longlong)_Dst & 0xfffffffffffffff8;
          *(ulonglong *)(lVar14 + 0x50) = uVar15;
          *(ulonglong *)(lVar14 + 0x70) = uVar15 + 0x50;
          memmove(_Dst,plVar13 + 1,(ulonglong)*(uint *)(plVar13 + 2));
          lVar1 = lVar14 + 0x60;
          puVar3 = *(undefined4 **)(lVar14 + 0x48);
          puVar3[7] = *(int *)(param_1 + 0x68) + param_2;
          puVar3[0xb] = 1;
          puVar3[0x1e] = 1;
          puVar3[0x20] = 0x10006cc;
          puVar3[0x1c] = 0x20;
          uVar6 = *(undefined4 *)(param_1 + 0x68);
          uVar7 = *(undefined4 *)(param_1 + 0x6c);
          uVar8 = *(undefined4 *)(param_1 + 0x70);
          uVar9 = *(undefined4 *)(param_1 + 0x74);
          puVar3[1] = puVar3[2];
          *puVar3 = puVar3[2];
          puVar3[0x3f] = uVar6;
          puVar3[0x40] = uVar7;
          puVar3[0x41] = uVar8;
          puVar3[0x42] = uVar9;
          *(int *)(lVar14 + 0x34) = param_2;
          *(longlong *)(lVar14 + 0x18) = param_1;
          *(uint *)(lVar14 + 0x24) = *(uint *)(lVar14 + 0x24) | *(uint *)((longlong)plVar13 + 4);
          *(undefined4 *)(*(longlong *)(lVar14 + 0x50) + 8) = 0x4c;
          *(undefined4 *)(*(longlong *)(lVar14 + 0x50) + 4) = 0x4c;
          **(undefined4 **)(lVar14 + 0x50) = 0x4c;
          *(longlong *)(lVar14 + 0x38) = lVar2;
          *(undefined4 *)(lVar14 + 0x10) = 1;
          *(longlong *)(lVar14 + 0x68) = lVar1;
          *(longlong *)lVar1 = lVar1;
          KeInitializeSpinLock(lVar14 + 0x78);
          *(undefined4 *)(lVar14 + 0x5c) = *(undefined4 *)(*(longlong *)(lVar14 + 0x48) + 0x30);
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x92,
                      &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,lVar14,
                      (char)*(undefined4 *)(lVar14 + 0x34));
          }
          puVar17 = auStack_198;
          uVar15 = 0;
          puVar18 = auStack_198;
          if (*(int *)(*(longlong *)(lVar14 + 0x48) + 0x30) != 0) {
            do {
              plVar16 = (longlong *)AllocateTapiAddr(param_1,lVar14,(int)uVar15);
              if (plVar16 == (longlong *)0x0) {
LAB_140006d80:
                *(undefined8 *)(puVar17 + -8) = 0x140006d88;
                FreeTapiLine(lVar14);
                lVar14 = 0;
                puVar18 = puVar17;
                break;
              }
              *(longlong **)(*(longlong *)(lVar14 + 0x70) + uVar15 * 8) = plVar16;
              plVar4 = *(longlong **)(lVar14 + 0x68);
              if (*plVar4 != lVar1) {
                pcVar5 = (code *)swi(0x29);
                (*pcVar5)(3);
                puVar17 = auStack_190;
                goto LAB_140006d80;
              }
              *plVar16 = lVar1;
              uVar12 = (int)uVar15 + 1;
              uVar15 = (ulonglong)uVar12;
              plVar16[1] = (longlong)plVar4;
              *plVar4 = (longlong)plVar16;
              *(longlong **)(lVar14 + 0x68) = plVar16;
              *(int *)(lVar14 + 0x58) = *(int *)(lVar14 + 0x58) + 1;
              puVar18 = auStack_198;
            } while (uVar12 < *(uint *)(*(longlong *)(lVar14 + 0x48) + 0x30));
          }
          *(undefined8 *)(puVar18 + -8) = 0x140006d96;
          ExFreePoolWithTag(plVar13,0);
          goto LAB_140006db3;
        }
      }
    }
    else {
      if (((*(uint *)(param_1 + 0x5c) & 1) == 0) && (param_2 != 0)) {
        _Src = *(uint **)(*(longlong *)(param_1 + 0x38) + 0x48);
        if (0xff8 < *_Src) {
          ExFreePoolWithTag(plVar13,0);
          uVar12 = *_Src;
          plVar13 = (longlong *)ExAllocatePool2(0x40,uVar12 + 8,0x615850);
          if (plVar13 == (longlong *)0x0) goto LAB_140006db1;
          _Dst_00 = (uint *)(plVar13 + 1);
          *(int *)plVar13 = param_2;
          *_Dst_00 = uVar12;
        }
        memmove(_Dst_00,_Src,(ulonglong)_Src[2]);
        goto LAB_140006bb8;
      }
      local_150 = 0;
      local_158 = 0xf00196;
      NdisInitializeEvent(local_60);
      local_154 = 0;
      local_138 = 0xfe001002;
      local_128 = 0x1000;
      local_130 = plVar13;
      iVar10 = NdisCoOidRequest(*(undefined8 *)(lVar14 + 0x20),*(undefined8 *)(lVar2 + 0x18),0,0);
      if (iVar10 == 0x103) {
        NdisWaitEvent(local_60,0);
        iVar10 = local_48;
      }
      if (iVar10 == -0x3ffeffec) {
        uVar12 = *(uint *)((longlong)plVar13 + 0xc);
        if (*(uint *)((longlong)plVar13 + 0xc) <= local_120) {
          uVar12 = local_120;
        }
        ExFreePoolWithTag(plVar13,0);
        plVar13 = (longlong *)ExAllocatePool2(0x40,uVar12,0x615850);
        if (plVar13 == (longlong *)0x0) goto LAB_140006db1;
        *(int *)plVar13 = param_2;
        *(uint *)(plVar13 + 1) = uVar12 - 8;
        memset(&local_158,0,0x118);
        local_150 = 0;
        local_158 = 0xf00196;
        NdisInitializeEvent(local_60);
        local_154 = 0;
        local_138 = 0xfe001002;
        local_130 = plVar13;
        local_128 = uVar12;
        iVar10 = NdisCoOidRequest(*(undefined8 *)(local_160 + 0x20),*(undefined8 *)(lVar2 + 0x18),0,
                                  0);
        if (iVar10 == 0x103) {
          NdisWaitEvent(local_60,0);
          iVar10 = local_48;
        }
      }
      if (iVar10 == 0) goto LAB_140006bb8;
    }
    ExFreePoolWithTag(plVar13,0);
  }
LAB_140006db1:
  puVar18 = auStack_198;
  lVar14 = 0;
LAB_140006db3:
  *(undefined8 *)(puVar18 + -8) = 0x140006dbf;
  return lVar14;
}



===== AllocateTapiProvider @ 140006de8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 * AllocateTapiProvider(longlong param_1,longlong param_2)

{
  longlong lVar1;
  uint *puVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  longlong lVar6;
  undefined8 *puVar7;
  code *pcVar8;
  undefined8 uVar9;
  undefined1 uVar10;
  int iVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  void *_Dst;
  undefined8 *puVar14;
  uint uVar15;
  uint uVar16;
  undefined8 *puVar17;
  undefined1 auStackY_238 [32];
  undefined2 local_1c8;
  undefined1 local_1c6;
  longlong local_1c0;
  longlong local_1b8;
  undefined4 local_1b0;
  int iStack_1ac;
  uint local_1a8;
  longlong local_1a0 [7];
  undefined4 local_168;
  undefined4 local_164;
  undefined8 local_160;
  undefined4 local_148;
  undefined4 *local_140;
  undefined4 local_138;
  undefined1 local_70 [24];
  int local_58;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_238;
  uVar10 = 1;
  local_1c0 = param_1;
  local_1b8 = param_2;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8c,
            &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
  }
  memset(&local_168,0,0x118);
  local_168 = 0xf00196;
  local_1b0 = 0;
  iStack_1ac = 0;
  local_1a8 = 0;
  local_160 = 0;
  NdisInitializeEvent(local_70);
  local_140 = &local_1b0;
  local_164 = 0;
  local_148 = 0xfe001001;
  local_138 = 0xc;
  iVar11 = NdisCoOidRequest(*(undefined8 *)(param_1 + 0x20),*(undefined8 *)(param_2 + 0x18),0,0);
  if (iVar11 == 0x103) {
    NdisWaitEvent(local_70,0);
    iVar11 = local_58;
  }
  if (iVar11 != 0) {
    puVar14 = (undefined8 *)0x0;
    if (iVar11 != -0x3fffff45) goto LAB_1400070f0;
    local_1b0 = 0x30000;
    iStack_1ac = 1;
    local_1a8 = 0;
    uVar10 = 0;
  }
  puVar12 = (undefined8 *)ExAllocatePool2(0x40,iStack_1ac * 8 + 0xa0,0x395850);
  puVar14 = puVar12;
  if (puVar12 != (undefined8 *)0x0) {
    KeInitializeSpinLock(puVar12 + 0x11);
    *(undefined4 *)(puVar12 + 2) = 1;
    puVar12[3] = param_1;
    puVar12[4] = param_2;
    *(int *)(puVar12 + 9) = iStack_1ac;
    uVar9 = *(undefined8 *)(param_1 + 0xa0);
    puVar12[0xd] = *(undefined8 *)(param_1 + 0x98);
    puVar12[0xe] = uVar9;
    puVar12[0xf] = *(undefined8 *)(param_2 + 0x8c);
    *(undefined4 *)(puVar12 + 0x10) = *(undefined4 *)(param_2 + 0x94);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_DDDDDDDDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8d,
                         &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,
                         *(undefined4 *)(puVar12 + 0xd),
                         (char)*(undefined2 *)((longlong)puVar12 + 0x6c),
                         (char)*(undefined2 *)((longlong)puVar12 + 0x6e),
                         *(undefined1 *)(puVar12 + 0xe),*(undefined1 *)((longlong)puVar12 + 0x71),
                         *(undefined1 *)((longlong)puVar12 + 0x72),
                         *(undefined1 *)((longlong)puVar12 + 0x73),
                         *(undefined1 *)((longlong)puVar12 + 0x74),
                         *(undefined1 *)((longlong)puVar12 + 0x75),
                         *(undefined1 *)((longlong)puVar12 + 0x76),
                         *(undefined1 *)((longlong)puVar12 + 0x77));
      param_2 = local_1b8;
      param_1 = local_1c0;
    }
    puVar14 = (undefined8 *)0x0;
    *(undefined1 *)((longlong)puVar12 + 100) = uVar10;
    puVar7 = puVar12 + 7;
    *(uint *)((longlong)puVar12 + 0x5c) = *(uint *)((longlong)puVar12 + 0x5c) | local_1a8;
    *(undefined4 *)(puVar12 + 0xc) = local_1b0;
    puVar17 = puVar12 + 5;
    puVar12[6] = puVar17;
    *puVar17 = puVar17;
    puVar12[8] = puVar7;
    *puVar7 = puVar7;
    puVar17 = puVar14;
    if (*(int *)(puVar12 + 9) != 0) {
      do {
        puVar13 = (undefined8 *)AllocateTapiLine((longlong)puVar12,(int)puVar17);
        if (puVar13 == (undefined8 *)0x0) {
          FreeTapiProvider((longlong)puVar12);
          goto LAB_1400070f0;
        }
        puVar4 = (undefined8 *)puVar12[8];
        if ((undefined8 *)*puVar4 != puVar7) goto LAB_140007675;
        *puVar13 = puVar7;
        uVar16 = (int)puVar17 + 1;
        puVar17 = (undefined8 *)(ulonglong)uVar16;
        puVar13[1] = puVar4;
        *puVar4 = puVar13;
        puVar12[8] = puVar13;
      } while (uVar16 < *(uint *)(puVar12 + 9));
    }
    DAT_14000d850 = KeAcquireSpinLockRaiseToDpc(&DAT_14000d848);
    for (puVar14 = DAT_14000d828; (undefined8 **)puVar14 != &DAT_14000d828;
        puVar14 = (undefined8 *)*puVar14) {
      if ((((*(int *)(puVar14 + 2) == 1) && (puVar14[0xd] == puVar12[0xd])) &&
          (puVar14[0xe] == puVar12[0xe])) && (*(int *)(param_2 + 0x8c) == *(int *)(puVar14 + 0xf)))
      {
        if (*(int *)(puVar14 + 9) == *(int *)(puVar12 + 9)) {
          FreeTapiProvider((longlong)puVar12);
          puVar12 = puVar14;
        }
        lVar6 = local_1c0;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_DDDDDDDDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8e,
                             &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,
                             *(undefined4 *)(local_1c0 + 0x98),(char)*(undefined2 *)(param_1 + 0x9c)
                             ,(char)*(undefined2 *)(param_1 + 0x9e),*(undefined1 *)(param_1 + 0xa0),
                             *(undefined1 *)(param_1 + 0xa1),*(undefined1 *)(param_1 + 0xa2),
                             *(undefined1 *)(param_1 + 0xa3),*(undefined1 *)(param_1 + 0xa4),
                             *(undefined1 *)(param_1 + 0xa5),*(undefined1 *)(param_1 + 0xa6),
                             *(undefined1 *)(param_1 + 0xa7));
          param_2 = local_1b8;
          param_1 = lVar6;
        }
        if ((undefined8 **)puVar14 != &DAT_14000d828) goto LAB_14000729a;
        break;
      }
    }
    if ((undefined8 **)*DAT_14000d830 != &DAT_14000d828) {
LAB_140007675:
      pcVar8 = (code *)swi(0x29);
      (*pcVar8)(3);
      pcVar8 = (code *)swi(3);
      puVar14 = (undefined8 *)(*pcVar8)();
      return puVar14;
    }
    *puVar12 = &DAT_14000d828;
    puVar12[1] = DAT_14000d830;
    *DAT_14000d830 = puVar12;
    DAT_14000d838 = DAT_14000d838 + *(int *)(puVar12 + 9);
    DAT_14000d830 = puVar12;
LAB_14000729a:
    if (TspCB == 0) {
      *(undefined4 *)(puVar12 + 2) = 0;
    }
    KeReleaseSpinLock(&DAT_14000d848,DAT_14000d850);
    puVar14 = puVar12 + 0x11;
    uVar10 = KeAcquireSpinLockRaiseToDpc(puVar14);
    *(undefined1 *)(puVar12 + 0x12) = uVar10;
    plVar3 = puVar12 + 7;
    *(undefined8 **)(param_2 + 0x68) = puVar12;
    puVar12[4] = param_2;
    puVar12[3] = param_1;
    while (plVar5 = (longlong *)*plVar3, plVar5 != plVar3) {
      if (((longlong *)plVar5[1] != plVar3) ||
         (lVar6 = *plVar5, *(longlong **)(lVar6 + 8) != plVar5)) goto LAB_140007675;
      *plVar3 = lVar6;
      *(longlong **)(lVar6 + 8) = plVar3;
      puVar7 = (undefined8 *)puVar12[6];
      if ((undefined8 *)*puVar7 != puVar12 + 5) goto LAB_140007675;
      *plVar5 = (longlong)(puVar12 + 5);
      plVar5[1] = (longlong)puVar7;
      *puVar7 = plVar5;
      puVar12[6] = plVar5;
      local_1c8 = 0;
      local_1c6 = 0;
      NdisAcquireRWLockWrite(DAT_14000d7f8,&local_1c8,0);
      if (LineTable == DAT_14000d7e4) {
        _Dst = (void *)ExAllocatePool2(0x40,((DAT_14000d7e4 >> 1) + DAT_14000d7e4) * 8);
        if (_Dst != (void *)0x0) {
          memmove(_Dst,DAT_14000d7f0,(ulonglong)DAT_14000d7e4 << 3);
          ExFreePoolWithTag(DAT_14000d7f0,0);
          DAT_14000d7e4 = DAT_14000d7e4 + (DAT_14000d7e4 >> 1);
          DAT_14000d7f0 = _Dst;
          goto LAB_14000740d;
        }
        NdisReleaseRWLock(DAT_14000d7f8,&local_1c8);
LAB_1400073b8:
        FreeTapiLine((longlong)plVar5);
      }
      else {
LAB_14000740d:
        uVar15 = DAT_14000d7e8;
        uVar16 = DAT_14000d7e4;
        do {
          if (*(longlong *)((longlong)DAT_14000d7f0 + (ulonglong)uVar15 * 8) == 0) {
            *(uint *)((longlong)plVar5 + 0x24) = *(uint *)((longlong)plVar5 + 0x24) | 1;
            *(uint *)(plVar5 + 6) = uVar15;
            *(longlong **)((longlong)DAT_14000d7f0 + (ulonglong)uVar15 * 8) = plVar5;
            LineTable = LineTable + 1;
            DAT_14000d7e8 = (DAT_14000d7e8 + 1) % DAT_14000d7e4;
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x9a,
                        &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,plVar5,(char)plVar5[6]);
            }
            break;
          }
          uVar15 = (uVar15 + 1) % DAT_14000d7e4;
          uVar16 = uVar16 - 1;
        } while (uVar16 != 0);
        NdisReleaseRWLock(DAT_14000d7f8,&local_1c8);
        if (uVar16 == 0) goto LAB_1400073b8;
        KeReleaseSpinLock(puVar14,*(undefined1 *)(puVar12 + 0x12));
        local_1a0[0] = plVar5[5];
        local_1a0[4] = (longlong)*(uint *)(plVar5 + 6);
        local_1a0[2] = 0x13;
        local_1a0[1] = 0;
        local_1a0[3] = 0;
        local_1a0[5] = 0;
        PxIndicateStatus(local_1a0);
        uVar10 = KeAcquireSpinLockRaiseToDpc(puVar14);
        *(undefined1 *)(puVar12 + 0x12) = uVar10;
      }
    }
    local_1c8 = 0;
    local_1c6 = 0;
    *(undefined4 *)(puVar12 + 2) = 0;
    KeReleaseSpinLock(puVar14,*(undefined1 *)(puVar12 + 0x12));
    NdisAcquireRWLockRead(DAT_14000d7f8,&local_1c8,0);
    uVar16 = 0;
    if (DAT_14000d7e4 != 0) {
      do {
        lVar6 = *(longlong *)((longlong)DAT_14000d7f0 + (ulonglong)uVar16 * 8);
        if (lVar6 != 0) {
          lVar1 = lVar6 + 0x78;
          uVar10 = KeAcquireSpinLockRaiseToDpc(lVar1);
          *(undefined1 *)(lVar6 + 0x80) = uVar10;
          if (*(undefined8 **)(lVar6 + 0x18) == puVar12) {
            puVar2 = (uint *)(*(longlong *)(lVar6 + 0x50) + 0x38);
            *puVar2 = *puVar2 | 4;
            *(undefined8 *)(lVar6 + 0x38) = puVar12[4];
            if (*(int *)(*(longlong *)(lVar6 + 0x50) + 0xc) != 0) {
              KeReleaseSpinLock(lVar1,*(undefined1 *)(lVar6 + 0x80));
              local_1a0[0] = *(longlong *)(lVar6 + 0x28);
              local_1a0[2] = 3;
              local_1a0[1] = 0;
              local_1a0[3] = 0;
              local_1a0[4] = 0;
              local_1a0[5] = 0;
              PxIndicateStatus(local_1a0);
              uVar10 = KeAcquireSpinLockRaiseToDpc(lVar1);
              *(undefined1 *)(lVar6 + 0x80) = uVar10;
            }
          }
          KeReleaseSpinLock(lVar1,*(undefined1 *)(lVar6 + 0x80));
        }
        uVar16 = uVar16 + 1;
      } while (uVar16 < DAT_14000d7e4);
    }
    NdisReleaseRWLock(DAT_14000d7f8,&local_1c8);
    uVar10 = KeAcquireSpinLockRaiseToDpc(puVar14);
    *(undefined1 *)(puVar12 + 0x12) = uVar10;
    KeReleaseSpinLock(puVar14,uVar10);
    puVar14 = puVar12;
  }
LAB_1400070f0:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8f,
             &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,puVar14);
  }
  return puVar14;
}



===== ClearSapWithTapiLine @ 140007684 =====

void ClearSapWithTapiLine(longlong param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined2 local_res10;
  undefined1 local_res12;
  
  local_res10 = 0;
  local_res12 = 0;
  NdisAcquireRWLockRead(DAT_14000d7f8,&local_res10,0);
  uVar4 = 0;
  if (DAT_14000d7e4 != 0) {
    do {
      lVar1 = *(longlong *)(DAT_14000d7f0 + uVar4 * 8);
      if (lVar1 != 0) {
        uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x78);
        *(undefined1 *)(lVar1 + 0x80) = uVar2;
        if (*(longlong *)(lVar1 + 0x40) == param_1) {
          *(undefined8 *)(lVar1 + 0x40) = 0;
        }
        KeReleaseSpinLock(lVar1 + 0x78,uVar2);
      }
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar3;
    } while (uVar3 < DAT_14000d7e4);
  }
  NdisReleaseRWLock(DAT_14000d7f8,&local_res10);
  return;
}



===== FreeTapiLine @ 14000774c =====

void FreeTapiLine(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  uint uVar5;
  ulonglong uVar6;
  
  uVar6 = 0;
  if (*(int *)(*(longlong *)(param_1 + 0x48) + 0x30) != 0) {
    do {
      plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x70) + uVar6 * 8);
      if (plVar1 != (longlong *)0x0) {
        lVar2 = *plVar1;
        if ((*(longlong **)(lVar2 + 8) != plVar1) ||
           (plVar3 = (longlong *)plVar1[1], (longlong *)*plVar3 != plVar1)) {
          pcVar4 = (code *)swi(0x29);
          (*pcVar4)(3);
          pcVar4 = (code *)swi(3);
          (*pcVar4)();
          return;
        }
        *plVar3 = lVar2;
        *(longlong **)(lVar2 + 8) = plVar3;
        *(undefined8 *)(*(longlong *)(param_1 + 0x70) + uVar6 * 8) = 0;
        *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + -1;
        ExFreePoolWithTag(plVar1,0);
      }
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < *(uint *)(*(longlong *)(param_1 + 0x48) + 0x30));
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== FreeTapiProvider @ 1400077dc =====

void FreeTapiProvider(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  undefined1 *puVar5;
  undefined2 local_res8;
  undefined1 local_resa;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  puVar5 = auStack_38;
  plVar1 = (longlong *)(param_1 + 0x38);
  while (plVar2 = (longlong *)*plVar1, plVar2 != plVar1) {
    if (((longlong *)plVar2[1] != plVar1) ||
       (lVar3 = *plVar2, (longlong *)*(longlong *)(lVar3 + 8) != plVar2)) goto LAB_140007905;
    *plVar1 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar1;
    FreeTapiLine((longlong)plVar2);
  }
  plVar1 = (longlong *)(param_1 + 0x28);
  while (plVar2 = (longlong *)*plVar1, plVar2 != plVar1) {
    if (((longlong *)plVar2[1] != plVar1) ||
       (lVar3 = *plVar2, (longlong *)*(longlong *)(lVar3 + 8) != plVar2)) goto LAB_140007905;
    *plVar1 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar1;
    if ((*(uint *)((longlong)plVar2 + 0x24) & 1) != 0) {
      local_res8 = 0;
      local_resa = 0;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x9c,
                  &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,plVar2,
                  (char)*(undefined4 *)(plVar2 + 6));
      }
      NdisAcquireRWLockWrite(DAT_14000d7f8,&local_res8,0);
      *(undefined8 *)(DAT_14000d7f0 + (ulonglong)*(uint *)(plVar2 + 6) * 8) = 0;
      *(uint *)((longlong)plVar2 + 0x24) = *(uint *)((longlong)plVar2 + 0x24) & 0xfffffffe;
      LineTable = LineTable + -1;
      if (*(uint *)(plVar2 + 6) < DAT_14000d7e8) {
        DAT_14000d7e8 = *(uint *)(plVar2 + 6);
      }
      NdisReleaseRWLock(DAT_14000d7f8,&local_res8);
    }
    FreeTapiLine((longlong)plVar2);
  }
LAB_14000790c:
  *(undefined8 *)(puVar5 + -8) = 0x140007918;
  ExFreePoolWithTag(param_1,0);
  return;
LAB_140007905:
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  puVar5 = auStack_30;
  goto LAB_14000790c;
}



===== GetVcFromCtx @ 140007934 =====

void GetVcFromCtx(ulonglong param_1,longlong *param_2)

{
  longlong lVar1;
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  lVar1 = 0;
  NdisAcquireRWLockRead(DAT_14000d7c8,&local_res8,0);
  if ((param_1 < DAT_14000d7a4) && (lVar1 = *(longlong *)(DAT_14000d7c0 + param_1 * 8), lVar1 != 0))
  {
    KeAcquireSpinLockAtDpcLevel(lVar1 + 0x200);
    if ((*(uint *)(lVar1 + 0x20) & 2) == 0) {
      KeReleaseSpinLockFromDpcLevel(lVar1 + 0x200);
      lVar1 = 0;
    }
    else {
      *(int *)(lVar1 + 0x1c) = *(int *)(lVar1 + 0x1c) + 1;
      KeReleaseSpinLockFromDpcLevel();
    }
  }
  NdisReleaseRWLock(DAT_14000d7c8,&local_res8);
  *param_2 = lVar1;
  return;
}



===== InsertVcInClAfList @ 140007a00 =====

void InsertVcInClAfList(longlong param_1)

{
  longlong lVar1;
  code *pcVar2;
  undefined1 uVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong *plVar6;
  undefined1 *puVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  lVar1 = *(longlong *)(param_1 + 0x38);
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0xb8);
  puVar7 = auStack_28;
  *(int *)(lVar1 + 0x14) = *(int *)(lVar1 + 0x14) + 1;
  *(undefined1 *)(lVar1 + 0xc0) = uVar3;
  lVar4 = lVar1 + 0x48;
  *(undefined1 *)(param_1 + 0x210) = 1;
  plVar6 = (longlong *)(param_1 + 0x1e0);
  plVar5 = *(longlong **)(lVar1 + 0x50);
  if (*plVar5 != lVar4) {
    plVar5 = (longlong *)0x3;
    pcVar2 = (code *)swi(0x29);
    lVar4 = (*pcVar2)();
    puVar7 = auStack_20;
  }
  *(longlong **)(param_1 + 0x1e8) = plVar5;
  *plVar6 = lVar4;
  *plVar5 = (longlong)plVar6;
  *(longlong **)(lVar4 + 8) = plVar6;
  uVar3 = *(undefined1 *)(lVar1 + 0xc0);
  *(undefined8 *)(puVar7 + -8) = 0x140007a78;
  KeReleaseSpinLock(lVar1 + 0xb8,uVar3);
  return;
}



===== MarkProviderOffline @ 140007a94 =====

void MarkProviderOffline(longlong param_1)

{
  uint *puVar1;
  longlong lVar2;
  undefined1 uVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined2 local_res8;
  undefined1 local_resa;
  
  *(undefined4 *)(param_1 + 0x10) = 1;
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(undefined8 *)(param_1 + 0x18) = 0;
  local_res8 = 0;
  local_resa = 0;
  NdisAcquireRWLockRead(DAT_14000d7f8,&local_res8,0);
  uVar5 = 0;
  if (DAT_14000d7e4 != 0) {
    do {
      lVar2 = *(longlong *)(DAT_14000d7f0 + uVar5 * 8);
      if (lVar2 != 0) {
        uVar3 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x78);
        *(undefined1 *)(lVar2 + 0x80) = uVar3;
        if (*(longlong *)(lVar2 + 0x18) == param_1) {
          puVar1 = (uint *)(*(longlong *)(lVar2 + 0x50) + 0x38);
          *puVar1 = *puVar1 & 0xfffffffb;
          *(undefined8 *)(lVar2 + 0x38) = 0;
          uVar3 = *(undefined1 *)(lVar2 + 0x80);
        }
        KeReleaseSpinLock(lVar2 + 0x78,uVar3);
      }
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar4;
    } while (uVar4 < DAT_14000d7e4);
  }
  NdisReleaseRWLock(DAT_14000d7f8,&local_res8);
  return;
}



===== PxIndicateStatus @ 140007b7c =====

void PxIndicateStatus(undefined8 *param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined1 *puVar8;
  undefined8 uVar9;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [40];
  
  DAT_14000d850 = KeAcquireSpinLockRaiseToDpc(&DAT_14000d848);
  if (TspCB == 0) {
    KeReleaseSpinLock(&DAT_14000d848,DAT_14000d850);
    DAT_14000d788 = KeAcquireSpinLockRaiseToDpc(&DAT_14000d780);
    lVar5 = DAT_14000d778;
    puVar8 = auStack_38;
    DAT_14000d778 = 0;
    if (lVar5 == 0) {
      puVar6 = (undefined8 *)ExAllocateFromNPagedLookasideList(&ProviderEventLookaside);
      puVar8 = auStack_38;
      if (puVar6 != (undefined8 *)0x0) {
        memmove(puVar6 + 2,param_1,0x30);
        puVar8 = auStack_38;
        puVar7 = &TspEventList;
        if ((undefined8 *)*DAT_14000d768 != &TspEventList) {
          puVar7 = (undefined8 *)0x3;
          pcVar4 = (code *)swi(0x29);
          DAT_14000d768 = (undefined8 *)(*pcVar4)();
          puVar8 = auStack_30;
        }
        puVar6[1] = DAT_14000d768;
        *puVar6 = puVar7;
        *DAT_14000d768 = puVar6;
        DAT_14000d770 = DAT_14000d770 + 1;
        DAT_14000d768 = puVar6;
        if (DAT_14000d774 < DAT_14000d770) {
          DAT_14000d774 = DAT_14000d770;
        }
      }
    }
    *(undefined8 *)(puVar8 + -8) = 0x140007cbd;
    KeReleaseSpinLock(&DAT_14000d780,DAT_14000d788);
    if (lVar5 != 0) {
      uVar9 = 0x30;
      LOCK();
      *(undefined8 *)(lVar5 + 0x68) = 0;
      UNLOCK();
      lVar1 = *(longlong *)(lVar5 + 0x18);
      *(undefined4 *)(lVar5 + 0x30) = 0;
      *(undefined8 *)(lVar5 + 0x38) = 0x3b;
      *(undefined8 *)(puVar8 + -8) = 0x140007cf3;
      puVar6 = param_1;
      memmove((void *)(lVar1 + 8),param_1,0x30);
      *(undefined4 *)(lVar1 + 4) = 0x30;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (4 < (byte)WPP_GLOBAL_Control[0x29]) {
          uVar2 = *param_1;
          uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
          *(undefined4 *)(puVar8 + 0x28) = *(undefined4 *)(param_1 + 2);
          *(undefined8 *)(puVar8 + 0x20) = param_1[1];
          *(undefined8 *)(puVar8 + -8) = 0x140007d2f;
          WPP_SF_PPL(uVar3,puVar6,uVar9,uVar2,puVar8[0x20],puVar8[0x28]);
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar2 = param_1[3];
          uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
          *(undefined8 *)(puVar8 + 0x28) = param_1[5];
          *(undefined8 *)(puVar8 + 0x20) = param_1[4];
          *(undefined8 *)(puVar8 + -8) = 0x140007d60;
          WPP_SF_PPP(uVar3,puVar6,uVar9,uVar2,puVar8[0x20],puVar8[0x28]);
        }
      }
      *(undefined8 *)(puVar8 + -8) = 0x140007d6c;
      IofCompleteRequest(lVar5,2);
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x87,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
    KeReleaseSpinLock(&DAT_14000d848,DAT_14000d850);
  }
  return;
}



===== RemoveVcFromClAfList @ 140007d88 =====

void RemoveVcFromClAfList(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  
  lVar2 = *(longlong *)(param_1 + 0x38);
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0xb8);
  *(undefined1 *)(lVar2 + 0xc0) = uVar6;
  if (*(char *)(param_1 + 0x210) == '\0') {
LAB_140007e08:
    KeReleaseSpinLock(lVar2 + 0xb8,*(undefined1 *)(lVar2 + 0xc0));
    return;
  }
  plVar1 = (longlong *)(param_1 + 0x1e0);
  *(undefined1 *)(param_1 + 0x210) = 0;
  lVar3 = *plVar1;
  if ((*(longlong **)(lVar3 + 8) == plVar1) &&
     (plVar4 = *(longlong **)(param_1 + 0x1e8), (longlong *)*plVar4 == plVar1)) {
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
    plVar4 = *(longlong **)(lVar2 + 0x60);
    if (*plVar4 == lVar2 + 0x58) {
      *plVar1 = lVar2 + 0x58;
      *(longlong **)(param_1 + 0x1e8) = plVar4;
      *plVar4 = (longlong)plVar1;
      *(longlong **)(lVar2 + 0x60) = plVar1;
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;
      goto LAB_140007e08;
    }
  }
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}



===== WPP_SF_P @ 140007e3c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_P(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,param_2,&local_res20,8,0)
  ;
  return;
}



===== WPP_SF_PPL @ 140007e84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_PPL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,0x88,&local_res20,8,
             &param_5,8,&param_6,4,0);
  return;
}



===== WPP_SF_PPP @ 140007eec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_PPP(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,0x89,&local_res20,8,
             &param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_ddd @ 140007f50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ddd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,0x1a,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_qLL @ 140007fb4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qLL(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,param_2,&local_res20,8,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_qLLLL @ 14000801c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qLLLL(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,param_2,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_SF_qP @ 1400080a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qP(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,param_2,&local_res20,8,
             &param_5,8,0);
  return;
}



===== WPP_SF_qS @ 1400080f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qS(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              wchar_t *param_5)

{
  longlong lVar1;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_5[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"NULL";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,0xf,&local_res20,8,
             param_5,lVar1,0);
  return;
}



===== WPP_SF_qSD @ 140008190 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qSD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               wchar_t *param_5,undefined1 param_6)

{
  longlong lVar1;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_5[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"NULL";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,0x25,&local_res20,8,
             param_5,lVar1,&param_6,4,0);
  return;
}



===== WPP_SF_qdd @ 140008240 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qdd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,0x19,&local_res20,8,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_qdq @ 1400082a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qdq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,0x93,&local_res20,8,
             &param_5,4,&param_6,8,0);
  return;
}



===== WPP_SF_qqL @ 140008310 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,99,&local_res20,8,
             &param_5,8,&param_6,4,0);
  return;
}



===== WPP_SF_qs @ 140008378 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qs(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              char *param_5)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 local_res20;
  
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
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,0xe,&local_res20,8,
             param_5,lVar2,0);
  return;
}



===== DoDerefClAfWork @ 140008400 =====

void DoDerefClAfWork(longlong *param_1)

{
  int iVar1;
  
  KeReleaseSpinLock(param_1 + 0x17,(char)param_1[0x18]);
  iVar1 = NdisClCloseAddressFamily(param_1[3]);
  if (iVar1 != 0x103) {
    PxClCloseAfComplete((char)iVar1,param_1);
  }
  return;
}



===== DoDerefCmAfWork @ 140008450 =====

void DoDerefCmAfWork(longlong param_1)

{
  KeReleaseSpinLock(param_1 + 0x58,*(undefined1 *)(param_1 + 0x60));
  NdisCmCloseAddressFamilyComplete(0,*(undefined8 *)(param_1 + 0x18));
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
             &WPP_8294867e35d63e705b52ce50c02b6694_Traceguids,param_1);
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== PxAllocateCmAf @ 1400084d0 =====

longlong PxAllocateCmAf(undefined8 *param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar2 = ExAllocatePool2(0x40,0x90,0x675850);
  if (lVar2 != 0) {
    KeInitializeSpinLock(lVar2 + 0x58);
    *(undefined8 *)(lVar2 + 0x48) = *param_1;
    *(undefined4 *)(lVar2 + 0x50) = *(undefined4 *)(param_1 + 1);
    lVar1 = lVar2 + 0x28;
    *(longlong *)(lVar2 + 0x30) = lVar1;
    *(longlong *)lVar1 = lVar1;
    lVar1 = lVar2 + 0x38;
    *(longlong *)(lVar2 + 0x40) = lVar1;
    *(longlong *)lVar1 = lVar1;
    *(undefined4 *)(lVar2 + 0x14) = 1;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
               &WPP_8294867e35d63e705b52ce50c02b6694_Traceguids,lVar2);
    }
  }
  return lVar2;
}



===== PxAllocateCmSap @ 140008584 =====

longlong PxAllocateCmSap(void *param_1)

{
  longlong lVar1;
  void *_Dst;
  uint uVar2;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_8294867e35d63e705b52ce50c02b6694_Traceguids,param_1);
  }
  uVar2 = *(uint *)((longlong)param_1 + 4) + 0x4c;
  if (*(uint *)((longlong)param_1 + 4) <= uVar2) {
    lVar1 = ExAllocatePool2(0x40,uVar2,0x355850);
    if (lVar1 != 0) {
      LOCK();
      *(undefined4 *)(lVar1 + 0x10) = 3;
      UNLOCK();
      _Dst = (void *)(lVar1 + 0x40U & 0xfffffffffffffff8);
      *(void **)(lVar1 + 0x30) = _Dst;
      memmove(_Dst,param_1,(ulonglong)*(uint *)((longlong)param_1 + 4) + 0xb);
      return lVar1;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_8294867e35d63e705b52ce50c02b6694_Traceguids,uVar2);
    }
  }
  return 0;
}



===== PxFreeAdapter @ 140008668 =====

void PxFreeAdapter(longlong *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong lVar4;
  undefined1 uVar5;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_8294867e35d63e705b52ce50c02b6694_Traceguids,param_1);
  }
  lVar4 = DeviceExtension;
  *(undefined4 *)((longlong)param_1 + 0x14) = 0;
  uVar5 = KeAcquireSpinLockRaiseToDpc(lVar4 + 0x58);
  *(undefined1 *)(lVar4 + 0x60) = uVar5;
  lVar1 = *param_1;
  if ((*(longlong **)(lVar1 + 8) == param_1) &&
     (plVar2 = (longlong *)param_1[1], (longlong *)*plVar2 == param_1)) {
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    KeReleaseSpinLock(DeviceExtension + 0x58,*(undefined1 *)(lVar4 + 0x60));
    ExFreePoolWithTag(param_1,0);
    return;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== PxFreeClAf @ 140008724 =====

void PxFreeClAf(undefined8 param_1)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
             &WPP_8294867e35d63e705b52ce50c02b6694_Traceguids,param_1);
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== PxFreeClSap @ 14000877c =====

void PxFreeClSap(longlong param_1)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
             &WPP_8294867e35d63e705b52ce50c02b6694_Traceguids,param_1);
  }
  *(undefined8 *)(param_1 + 0x40) = 0;
  ExFreePoolWithTag(param_1,0);
  return;
}



===== WPP_SF_dq @ 1400087dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_8294867e35d63e705b52ce50c02b6694_Traceguids,param_2,local_res20,4,
             &param_5,8,0);
  return;
}



===== WPP_SF_qLLL @ 140008834 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qLLL(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_8294867e35d63e705b52ce50c02b6694_Traceguids,param_2,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_qLqLL @ 1400088a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qLqLL(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_8294867e35d63e705b52ce50c02b6694_Traceguids,param_2,&local_res20,8,
             &param_5,4,&param_6,8,&param_7,4,&param_8,4,0);
  return;
}



===== WdmlibRtlInitUnicodeStringEx @ 14000892c =====

undefined8 WdmlibRtlInitUnicodeStringEx(short *param_1,longlong param_2)

{
  short sVar1;
  ulonglong uVar2;
  short sVar3;
  
  sVar3 = 0;
  if (param_2 == 0) {
    param_2 = 0;
    sVar1 = 0;
  }
  else {
    uVar2 = 0xffffffffffffffff;
    do {
      uVar2 = uVar2 + 1;
    } while (*(short *)(param_2 + uVar2 * 2) != 0);
    if (0x7ffe < uVar2) {
      return 0xc0000106;
    }
    sVar1 = (short)uVar2 * 2;
    sVar3 = sVar1 + 2;
  }
  *param_1 = sVar1;
  param_1[1] = sVar3;
  *(longlong *)(param_1 + 4) = param_2;
  return 0;
}



===== __GSHandlerCheck @ 140008988 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1400089ac =====

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



===== __cpu_features_init @ 140008a20 =====

/* WARNING: Removing unreachable block (ram,0x000140008a8a) */
/* WARNING: Removing unreachable block (ram,0x000140008a39) */
/* WARNING: Removing unreachable block (ram,0x000140008a2a) */

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



===== __security_check_cookie @ 140008af0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140008b30 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140008b60 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140008b60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140008b90 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 140008be0 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_140008c23;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_140008c94;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_140008c90:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140008c94;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_140008c8c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140008c90;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140008c8c;
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
LAB_140008c94:
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
LAB_140008c23:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memmove @ 140008d00 =====

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



===== memset @ 140009000 =====

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



===== __memset_repmovs @ 140009140 =====

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



===== __memset_query @ 1400091c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140009240 =====

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



===== __memset_spec_ermsb_repmovsb @ 140009380 =====

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



===== __memset_spec_plain @ 140009400 =====

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



===== PxClIncomingDropParty @ 140011010 =====

void PxClIncomingDropParty(void)

{
  return;
}



===== PxClCallConnected @ 140011020 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PxClCallConnected(ulonglong param_1,undefined8 param_2,undefined *param_3)

{
  int *piVar1;
  longlong *plVar2;
  uint uVar3;
  longlong *plVar4;
  undefined1 uVar5;
  longlong **pplVar6;
  undefined1 auStackY_88 [32];
  longlong *local_48;
  undefined8 local_40;
  longlong local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 local_20;
  ulonglong local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = (longlong *)0x0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
             &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids,param_1);
  }
  pplVar6 = &local_48;
  GetVcFromCtx(param_1,(longlong *)pplVar6);
  plVar4 = local_48;
  if (local_48 == (longlong *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
               &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids,param_1);
    }
  }
  else {
    plVar2 = local_48 + 0x40;
    uVar5 = KeAcquireSpinLockRaiseToDpc(plVar2);
    *(undefined1 *)(plVar4 + 0x41) = uVar5;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      pplVar6 = (longlong **)0x29;
      param_3 = &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids;
      WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
                &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids,plVar4,(char)plVar4[2]);
    }
    if ((int)plVar4[2] == 4) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        param_3 = &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids;
        WPP_SF_qDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
                    &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids,plVar4,0,0,
                    (char)*(undefined4 *)(plVar4[0x26] + 0x20));
      }
      local_2c = 0;
      local_20 = 0;
      local_30 = 2;
      local_40 = *(undefined8 *)(plVar4[0x20] + 0x28);
      local_38 = plVar4[0x22];
      local_28 = 0x100;
      uVar3 = *(uint *)(plVar4[0x26] + 0x20);
      local_18 = (ulonglong)uVar3;
      *(undefined4 *)((longlong)plVar4 + 0x124) = 0x100;
      *(undefined4 *)(plVar4 + 0x25) = 0;
      pplVar6 = (longlong **)(ulonglong)CONCAT31((int3)(uVar3 >> 8),(char)plVar4[0x41]);
      KeReleaseSpinLock(plVar2);
      PxIndicateStatus(&local_40);
      uVar5 = KeAcquireSpinLockRaiseToDpc(plVar2);
      *(undefined1 *)(plVar4 + 0x41) = uVar5;
    }
    piVar1 = (int *)((longlong)plVar4 + 0x1c);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      DoDerefVcWork(plVar4,pplVar6,param_3);
    }
    else {
      KeReleaseSpinLock(plVar4 + 0x40,(char)plVar4[0x41]);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
              &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids);
    }
  }
  return;
}



===== PxClCloseCallComplete @ 140011270 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PxClCloseCallComplete(int param_1,ulonglong param_2,undefined *param_3)

{
  int *piVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined1 uVar4;
  uint uVar5;
  longlong **pplVar6;
  undefined1 auStackY_88 [32];
  longlong *local_48;
  undefined8 local_40;
  longlong local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 local_20;
  ulonglong local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = (longlong *)0x0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids;
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
              &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids,param_2,(char)param_1);
  }
  pplVar6 = &local_48;
  GetVcFromCtx(param_2,(longlong *)pplVar6);
  plVar3 = local_48;
  if (local_48 == (longlong *)0x0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
      return;
    }
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
             &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids,param_2);
    return;
  }
  plVar2 = local_48 + 0x40;
  uVar4 = KeAcquireSpinLockRaiseToDpc(plVar2);
  *(undefined1 *)(plVar3 + 0x41) = uVar4;
  if (param_1 != 0) {
    *(uint *)(plVar3 + 4) = *(uint *)(plVar3 + 4) | 8;
    *(uint *)((longlong)plVar3 + 0x24) = *(uint *)((longlong)plVar3 + 0x24) | 0x400;
    goto LAB_140011464;
  }
  *(uint *)((longlong)plVar3 + 0x24) = *(uint *)((longlong)plVar3 + 0x24) | 0x200;
  uVar5 = *(uint *)(plVar3 + 4);
  if ((uVar5 & 0x100) != 0) goto LAB_140011464;
  if ((char)uVar5 < '\0') {
    uVar5 = uVar5 & 0xffffff7f | 0x100;
LAB_14001137b:
    *(uint *)(plVar3 + 4) = uVar5;
  }
  else if ((uVar5 & 0x20) != 0) {
    uVar5 = uVar5 & 0xffffffdf | 0x40;
    goto LAB_14001137b;
  }
  *(int *)((longlong)plVar3 + 0x14) = (int)plVar3[2];
  *(undefined4 *)(plVar3 + 2) = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids;
    pplVar6 = (longlong **)0x0;
    WPP_SF_qDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids,plVar3,0,0,
                (char)*(undefined4 *)(plVar3[0x26] + 0x20));
  }
  local_2c = 0;
  local_20 = 0;
  local_30 = 2;
  local_40 = *(undefined8 *)(plVar3[0x20] + 0x28);
  local_38 = plVar3[0x22];
  local_28 = 0x4000;
  local_18 = (ulonglong)*(uint *)(plVar3[0x26] + 0x20);
  *(undefined4 *)((longlong)plVar3 + 0x124) = 0x4000;
  *(undefined4 *)(plVar3 + 0x25) = 0;
  pplVar6 = (longlong **)CONCAT71((int7)((ulonglong)pplVar6 >> 8),(char)plVar3[0x41]);
  KeReleaseSpinLock(plVar2);
  PxIndicateStatus(&local_40);
  uVar4 = KeAcquireSpinLockRaiseToDpc(plVar2);
  *(undefined1 *)(plVar3 + 0x41) = uVar4;
  if ((*(uint *)(plVar3 + 4) & 0x10) != 0) {
    PxTapiCompleteDropIrps((longlong)plVar3);
  }
  *(int *)((longlong)plVar3 + 0x1c) = *(int *)((longlong)plVar3 + 0x1c) + -1;
LAB_140011464:
  piVar1 = (int *)((longlong)plVar3 + 0x1c);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    DoDerefVcWork(plVar3,pplVar6,param_3);
  }
  else {
    KeReleaseSpinLock(plVar2,(char)plVar3[0x41]);
  }
  return;
}



===== PxClCreateVc @ 1400114c0 =====

undefined8 PxClCreateVc(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  undefined1 uVar2;
  bool bVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids,param_1);
  }
  lVar1 = param_1 + 0xb8;
  uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1);
  *(undefined1 *)(param_1 + 0xc0) = uVar2;
  if (*(int *)(param_1 + 0x10) == 3) {
    puVar4 = PxAllocateVc(param_1);
    if (puVar4 != (undefined8 *)0x0) {
      puVar4[5] = param_2;
      KeReleaseSpinLock(lVar1,*(undefined1 *)(param_1 + 0xc0));
      bVar3 = InsertVcInTable(puVar4);
      if (bVar3) {
        InsertVcInClAfList((longlong)puVar4);
        *param_3 = puVar4[0x23];
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                  &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids);
        }
        return 0;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids);
      }
      PxFreeVc((longlong)puVar4);
      return 0xc000009a;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
              &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids);
    }
    uVar5 = 0xc000009a;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids,param_1,
                (char)*(int *)(param_1 + 0x10));
    }
    uVar5 = 0xc0000001;
  }
  KeReleaseSpinLock(lVar1,*(undefined1 *)(param_1 + 0xc0));
  return uVar5;
}



===== PxClDeleteVc @ 140011680 =====

undefined8 PxClDeleteVc(ulonglong param_1,undefined8 param_2,undefined *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined1 uVar3;
  int iVar4;
  undefined8 uVar5;
  longlong **pplVar6;
  longlong *local_res10;
  
  local_res10 = (longlong *)0x0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
            &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids);
  }
  pplVar6 = &local_res10;
  GetVcFromCtx(param_1,(longlong *)pplVar6);
  plVar2 = local_res10;
  if (local_res10 == (longlong *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
               &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids,param_1);
    }
    uVar5 = 0xc0000001;
  }
  else {
    plVar1 = local_res10 + 0x40;
    uVar3 = KeAcquireSpinLockRaiseToDpc(plVar1);
    *(undefined1 *)(plVar2 + 0x41) = uVar3;
    RemoveVcFromClAfList((longlong)plVar2);
    iVar4 = *(int *)((longlong)plVar2 + 0x1c) + -2;
    *(int *)((longlong)plVar2 + 0x1c) = iVar4;
    if (iVar4 == 0) {
      DoDerefVcWork(plVar2,pplVar6,param_3);
    }
    else {
      KeReleaseSpinLock(plVar1,(char)plVar2[0x41]);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
               &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids,0);
    }
    uVar5 = 0;
  }
  return uVar5;
}



===== PxClDeregisterSapComplete @ 1400117a0 =====

void PxClDeregisterSapComplete(undefined1 param_1,longlong *param_2)

{
  int *piVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  
  plVar2 = (longlong *)param_2[4];
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
              &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids,param_2,param_1);
  }
  uVar6 = KeAcquireSpinLockRaiseToDpc(plVar2 + 0x17);
  *(undefined1 *)(plVar2 + 0x18) = uVar6;
  lVar3 = *param_2;
  if ((*(longlong **)(lVar3 + 8) != param_2) ||
     (plVar4 = (longlong *)param_2[1], (longlong *)*plVar4 != param_2)) {
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(3);
    pcVar5 = (code *)swi(3);
    (*pcVar5)();
    return;
  }
  *plVar4 = lVar3;
  *(longlong **)(lVar3 + 8) = plVar4;
  piVar1 = (int *)((longlong)plVar2 + 0x14);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    DoDerefClAfWork(plVar2);
  }
  else {
    KeReleaseSpinLock(plVar2 + 0x17,(char)plVar2[0x18]);
  }
  LOCK();
  *(undefined4 *)(param_2 + 2) = 0;
  UNLOCK();
  PxFreeClSap((longlong)param_2);
  return;
}



===== PxClIncomingCall @ 140011880 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PxClIncomingCall(longlong param_1,ulonglong param_2,undefined *param_3)

{
  int *piVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong *plVar5;
  undefined1 uVar6;
  int iVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined8 uVar10;
  undefined *puVar11;
  undefined1 auStackY_b8 [32];
  longlong *local_78;
  undefined8 local_70;
  longlong local_68;
  undefined4 local_60;
  undefined4 local_5c;
  longlong local_58;
  longlong local_50;
  ulonglong local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_78 = (longlong *)0x0;
  puVar11 = param_3;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar11 = &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids;
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
              &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids,param_1,(char)param_2);
  }
  if (*(int *)(param_1 + 0x10) == 3) {
    lVar9 = *(longlong *)(param_1 + 0x20);
    GetVcFromCtx(param_2,(longlong *)&local_78);
    plVar4 = local_78;
    if (local_78 != (longlong *)0x0) {
      uVar8 = Feature_2616427835__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar8 != 0) {
        *(undefined4 *)((longlong)plVar4 + 0x214) = 0;
        if ((((plVar4[0xb] != 0) && (*(int *)(plVar4[0xb] + 0xac) == 0xd)) &&
            (param_3 != (undefined *)0x0)) &&
           ((lVar3 = *(longlong *)(param_3 + 0x10), lVar3 != 0 && (0x1f < *(uint *)(lVar3 + 0x14))))
           ) {
          *(undefined4 *)((longlong)plVar4 + 0x214) = *(undefined4 *)(lVar3 + 0x18);
          *(undefined4 *)(lVar3 + 0x18) = 0;
        }
      }
      iVar7 = (**(code **)(lVar9 + 0x78))(plVar4);
      if (iVar7 == 0) {
        plVar2 = plVar4 + 0x40;
        uVar6 = KeAcquireSpinLockRaiseToDpc(plVar2);
        plVar5 = local_78;
        *(undefined1 *)(plVar4 + 0x41) = uVar6;
        LOCK();
        UNLOCK();
        lVar9 = (longlong)DAT_14000d824;
        DAT_14000d824 = DAT_14000d824 + 2;
        plVar4[0x22] = lVar9;
        *(int *)((longlong)local_78 + 0x1c) = *(int *)((longlong)local_78 + 0x1c) + 2;
        *(int *)((longlong)local_78 + 0x14) = (int)local_78[2];
        *(undefined4 *)(local_78 + 2) = 2;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          param_3 = (undefined *)0x21;
          WPP_SF_qLqLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,puVar11,local_78,
                       (char)local_78[4],(char)local_78[5],
                       (char)*(undefined4 *)((longlong)local_78 + 0x124),(char)local_78[0x25]);
        }
        if ((*(uint *)(plVar5 + 4) & 4) == 0) {
          *(int *)((longlong)plVar5 + 0x1c) = *(int *)((longlong)plVar5 + 0x1c) + 1;
          param_3 = (undefined *)0xea60;
          *(uint *)(plVar5 + 4) = *(uint *)(plVar5 + 4) | 4;
          NdisSetTimer(plVar5 + 0x28);
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_qPPD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_3,puVar11,plVar5,
                      (char)plVar5[0x23],(char)plVar4[0x22]);
        }
        uVar10 = CONCAT71((int7)((ulonglong)param_3 >> 8),(char)plVar4[0x41]);
        local_5c = 0;
        local_48 = 0;
        local_70 = *(undefined8 *)(plVar5[0x20] + 0x28);
        local_58 = plVar5[0x23];
        local_68 = plVar4[0x22];
        local_60 = 500;
        local_50 = local_68;
        KeReleaseSpinLock(plVar2,uVar10);
        PxIndicateStatus(&local_70);
        uVar6 = KeAcquireSpinLockRaiseToDpc(plVar2);
        *(undefined1 *)(plVar4 + 0x41) = uVar6;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar10 = 0;
          puVar11 = &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids;
          WPP_SF_qDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
                      &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids,plVar5,2,0,
                      (char)*(undefined4 *)(plVar5[0x26] + 0x20));
        }
        local_5c = 0;
        local_50 = 0;
        local_60 = 2;
        local_70 = *(undefined8 *)(plVar5[0x20] + 0x28);
        local_68 = plVar4[0x22];
        local_58 = 2;
        local_48 = (ulonglong)*(uint *)(plVar5[0x26] + 0x20);
        *(undefined4 *)((longlong)plVar5 + 0x124) = 2;
        *(undefined4 *)(plVar5 + 0x25) = 0;
        uVar10 = CONCAT71((int7)((ulonglong)uVar10 >> 8),(char)plVar4[0x41]);
        KeReleaseSpinLock(plVar2);
        PxIndicateStatus(&local_70);
        uVar6 = KeAcquireSpinLockRaiseToDpc(plVar2);
        *(undefined1 *)(plVar4 + 0x41) = uVar6;
        piVar1 = (int *)((longlong)plVar5 + 0x1c);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          DoDerefVcWork(plVar5,uVar10,puVar11);
        }
        else {
          KeReleaseSpinLock(plVar2,(char)plVar4[0x41]);
        }
        return 0x103;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar7;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
        return iVar7;
      }
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
               &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids,param_2);
      return iVar7;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
               &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids,param_2);
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
              &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids,param_1,
              (char)*(int *)(param_1 + 0x10));
  }
  return -0x3fffffff;
}



===== PxClIncomingCloseCall @ 140011c50 =====

void PxClIncomingCloseCall(undefined8 param_1,ulonglong param_2,undefined *param_3)

{
  int *piVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined1 uVar4;
  undefined8 uVar5;
  longlong *local_18 [2];
  
  local_18[0] = (longlong *)0x0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
             &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids,param_2);
  }
  GetVcFromCtx(param_2,(longlong *)local_18);
  plVar3 = local_18[0];
  if (local_18[0] == (longlong *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
               &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids,param_2);
    }
  }
  else {
    plVar2 = local_18[0] + 0x40;
    uVar4 = KeAcquireSpinLockRaiseToDpc(plVar2);
    *(undefined1 *)(plVar3 + 0x41) = uVar4;
    uVar5 = 8;
    *(uint *)((longlong)plVar3 + 0x24) = *(uint *)((longlong)plVar3 + 0x24) | 1;
    PxVcCleanup((longlong)plVar3,(longlong *)&DAT_00000008,param_3);
    piVar1 = (int *)((longlong)plVar3 + 0x1c);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      DoDerefVcWork(plVar3,uVar5,param_3);
    }
    else {
      KeReleaseSpinLock(plVar2,(char)plVar3[0x41]);
    }
  }
  return;
}



===== PxClMakeCallComplete @ 140011d50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PxClMakeCallComplete(uint param_1,ulonglong param_2,undefined *param_3)

{
  int *piVar1;
  longlong *plVar2;
  int iVar3;
  longlong *plVar4;
  undefined1 uVar5;
  uint uVar6;
  longlong **pplVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  undefined1 auStackY_a8 [32];
  longlong *local_68;
  undefined8 local_60;
  longlong local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  ulonglong local_40;
  ulonglong local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_68 = (longlong *)0x0;
  uVar9 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids;
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
              &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids,param_2,(char)param_1);
  }
  pplVar7 = &local_68;
  GetVcFromCtx(param_2,(longlong *)pplVar7);
  plVar4 = local_68;
  if (local_68 == (longlong *)0x0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
      return;
    }
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
             &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids,param_2);
    return;
  }
  plVar2 = local_68 + 0x40;
  uVar5 = KeAcquireSpinLockRaiseToDpc(plVar2);
  *(undefined1 *)(plVar4 + 0x41) = uVar5;
  uVar8 = 0x100;
  uVar6 = *(uint *)(plVar4 + 4);
  if ((uVar6 & 0x100) != 0) goto LAB_140011fd0;
  if ((char)uVar6 < '\0') {
    uVar6 = uVar6 & 0xffffff7f | 0x100;
    *(uint *)(plVar4 + 4) = uVar6;
  }
  if (param_1 == 0) {
    iVar3 = (int)plVar4[2];
    if (iVar3 != 3) {
      *(int *)((longlong)plVar4 + 0x14) = iVar3;
      uVar9 = 0x100;
      *(undefined4 *)(plVar4 + 2) = 4;
    }
    else {
      *(uint *)(plVar4 + 4) = uVar6 & 0xfffffeff;
      PxCloseCallWithCm((longlong)plVar4,pplVar7,param_3);
    }
    uVar8 = 0;
    if (iVar3 != 3) goto LAB_140011ef8;
  }
  else {
    uVar9 = 0x4000;
    if ((int)param_1 < -0x3ffedfdb) {
      if (param_1 == 0xc0012024) {
        uVar8 = 0x10;
      }
      else if ((int)param_1 < -0x3ffeffd6) {
        if (param_1 != 0xc0010029) {
          if (param_1 != 0xc0000001) {
            if (param_1 == 0xc000009a) {
LAB_14001206c:
              uVar8 = 0x200;
              goto LAB_140011eeb;
            }
            if (param_1 == 0xc0010021) goto LAB_1400120f7;
            if (param_1 == 0xc0010022) goto LAB_140012076;
            if (param_1 == 0xc0010024) goto LAB_140011ee6;
          }
LAB_1400120b0:
          uVar8 = 2;
          if (*(int *)(plVar4[0xb] + 0xac) == 0xd) {
            if (param_1 == 0x80070079) {
LAB_140012080:
              uVar8 = 0x40;
            }
            else if (param_1 == 0xc0000241) {
              uVar8 = 0x80000;
            }
            else {
              if (param_1 == 0x79) goto LAB_140012080;
              if ((param_1 & 0xffff0000) == 0) {
                param_1 = param_1 | 0x80070000;
              }
              uVar8 = (ulonglong)param_1;
            }
          }
        }
      }
      else {
        if (param_1 != 0xc0012020) {
          if (param_1 != 0xc0012021) {
            if (param_1 == 0xc0012022) goto LAB_140012101;
            if (param_1 == 0xc0012023) {
              uVar8 = 8;
              goto LAB_140011eeb;
            }
          }
          goto LAB_1400120b0;
        }
        uVar8 = 1;
      }
    }
    else if ((int)param_1 < -0x3ffedfd5) {
      if (param_1 == 0xc001202a) {
        uVar8 = 0x400;
      }
      else if (param_1 == 0xc0012025) {
LAB_1400120f7:
        uVar8 = 0x20;
      }
      else {
        if (param_1 == 0xc0012026) goto LAB_140012080;
        if (param_1 == 0xc0012027) {
LAB_140012076:
          uVar8 = 0x80;
        }
        else if (param_1 != 0xc0012028) {
          if (param_1 == 0xc0012029) goto LAB_14001206c;
          goto LAB_1400120b0;
        }
      }
    }
    else if (param_1 == 0xc001202b) {
LAB_140011ee6:
      uVar8 = 0x800;
    }
    else {
      if (param_1 != 0x10003) {
        if (param_1 != 0x10007) goto LAB_1400120b0;
        goto LAB_1400120f7;
      }
LAB_140012101:
      uVar8 = 4;
    }
LAB_140011eeb:
    *(int *)((longlong)plVar4 + 0x1c) = *(int *)((longlong)plVar4 + 0x1c) + -1;
    *(int *)((longlong)plVar4 + 0x14) = (int)plVar4[2];
    *(undefined4 *)(plVar4 + 2) = 0;
LAB_140011ef8:
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      param_3 = &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids;
      WPP_SF_qDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                  &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids,plVar4,0,(char)uVar8,
                  (char)*(undefined4 *)(plVar4[0x26] + 0x20));
    }
    local_4c = 0;
    local_50 = 2;
    local_60 = *(undefined8 *)(plVar4[0x20] + 0x28);
    local_58 = plVar4[0x22];
    uVar6 = *(uint *)(plVar4[0x26] + 0x20);
    local_38 = (ulonglong)uVar6;
    *(int *)((longlong)plVar4 + 0x124) = (int)uVar9;
    *(int *)(plVar4 + 0x25) = (int)uVar8;
    pplVar7 = (longlong **)(ulonglong)CONCAT31((int3)(uVar6 >> 8),(char)plVar4[0x41]);
    local_48 = uVar9;
    local_40 = uVar8;
    KeReleaseSpinLock(plVar2);
    PxIndicateStatus(&local_60);
    uVar5 = KeAcquireSpinLockRaiseToDpc(plVar2);
    *(undefined1 *)(plVar4 + 0x41) = uVar5;
  }
  if ((*(uint *)(plVar4 + 4) & 0x10) != 0) {
    PxTapiCompleteDropIrps((longlong)plVar4);
  }
LAB_140011fd0:
  piVar1 = (int *)((longlong)plVar4 + 0x1c);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    DoDerefVcWork(plVar4,pplVar7,param_3);
  }
  else {
    KeReleaseSpinLock(plVar4 + 0x40,(char)plVar4[0x41]);
  }
  return;
}



===== PxClRegisterSapComplete @ 140012160 =====

void PxClRegisterSapComplete(int param_1,longlong *param_2,undefined8 param_3,longlong param_4)

{
  int *piVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  code *pcVar7;
  undefined1 uVar8;
  int iVar9;
  undefined1 *puVar10;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  
  plVar3 = (longlong *)param_2[4];
  lVar4 = param_2[5];
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
              &WPP_c0fe5ccf6f593c5f746039039b260d88_Traceguids,param_2,(char)param_1);
  }
  puVar10 = auStack_48;
  plVar2 = plVar3 + 0x17;
  if (param_1 != 0) {
    LOCK();
    *(undefined4 *)(param_2 + 2) = 0;
    UNLOCK();
    uVar8 = KeAcquireSpinLockRaiseToDpc(plVar2);
    *(undefined1 *)(plVar3 + 0x18) = uVar8;
    lVar5 = *param_2;
    if ((*(longlong **)(lVar5 + 8) == param_2) &&
       (plVar6 = (longlong *)param_2[1], (longlong *)*plVar6 == param_2)) {
      *plVar6 = lVar5;
      *(longlong **)(lVar5 + 8) = plVar6;
      if (plVar3 != (longlong *)0x0) {
        piVar1 = (int *)((longlong)plVar3 + 0x14);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          DoDerefClAfWork(plVar3);
        }
        else {
          KeReleaseSpinLock(plVar2,(char)plVar3[0x18]);
        }
      }
      *(undefined8 *)(lVar4 + 0x40) = 0;
      PxFreeClSap((longlong)param_2);
      return;
    }
    pcVar7 = (code *)swi(0x29);
    (*pcVar7)(3);
    puVar10 = auStack_40;
  }
  param_2[7] = param_4;
  *(undefined8 *)(puVar10 + -8) = 0x140012249;
  uVar8 = KeAcquireSpinLockRaiseToDpc();
  *(undefined1 *)(plVar3 + 0x18) = uVar8;
  if ((int)plVar3[2] == 3) {
    *(undefined8 *)(puVar10 + -8) = 0x1400122a1;
    KeReleaseSpinLock(plVar2,uVar8);
    *(undefined8 *)(puVar10 + -8) = 0x1400122b4;
    uVar8 = KeAcquireSpinLockRaiseToDpc(lVar4 + 0x78);
    lVar5 = *(longlong *)(lVar4 + 0x50);
    *(undefined1 *)(lVar4 + 0x80) = uVar8;
    if (*(int *)(lVar5 + 0xc) != 0) {
      *(undefined8 *)(puVar10 + -8) = 0x1400122d6;
      KeReleaseSpinLock(lVar4 + 0x78,CONCAT71((int7)((ulonglong)lVar5 >> 8),uVar8));
      LOCK();
      *(undefined4 *)(param_2 + 2) = 3;
      UNLOCK();
      return;
    }
  }
  *(undefined8 *)(puVar10 + -8) = 0x14001226a;
  KeReleaseSpinLock();
  LOCK();
  *(undefined4 *)(param_2 + 2) = 1;
  UNLOCK();
  lVar4 = param_2[7];
  *(undefined8 *)(puVar10 + -8) = 0x140012282;
  iVar9 = NdisClDeregisterSap(lVar4);
  if (iVar9 != 0x103) {
    *(undefined8 *)(puVar10 + -8) = 0x140012298;
    PxClDeregisterSapComplete((char)iVar9,param_2);
  }
  return;
}



===== PxCmCloseCall @ 140012300 =====

undefined8 PxCmCloseCall(ulonglong param_1)

{
  int *piVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined1 uVar5;
  int iVar6;
  undefined8 uVar7;
  longlong lVar8;
  longlong *local_18 [2];
  
  local_18[0] = (longlong *)0x0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
             &WPP_c7e600acf35c333e1969f852caaf3ce1_Traceguids,param_1);
  }
  GetVcFromCtx(param_1,(longlong *)local_18);
  plVar4 = local_18[0];
  if (local_18[0] == (longlong *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
               &WPP_c7e600acf35c333e1969f852caaf3ce1_Traceguids,param_1);
    }
    uVar7 = 0;
  }
  else {
    plVar2 = local_18[0] + 0x40;
    uVar5 = KeAcquireSpinLockRaiseToDpc(plVar2);
    *(undefined1 *)(plVar4 + 0x41) = uVar5;
    *(undefined4 *)(plVar4 + 3) = 0;
    *(uint *)((longlong)plVar4 + 0x24) = *(uint *)((longlong)plVar4 + 0x24) | 0x80;
    KeReleaseSpinLock(plVar2,uVar5);
    lVar8 = plVar4[8];
    uVar7 = 0;
    NdisCmCloseCallComplete(0);
    uVar5 = KeAcquireSpinLockRaiseToDpc(plVar2);
    *(undefined1 *)(plVar4 + 0x41) = uVar5;
    if ((*(uint *)(plVar4 + 4) & 8) != 0) {
      PxCloseCallWithCm((longlong)plVar4,lVar8,uVar7);
    }
    lVar3 = plVar4[10];
    iVar6 = *(int *)((longlong)plVar4 + 0x1c) + -2;
    *(int *)((longlong)plVar4 + 0x1c) = iVar6;
    if (iVar6 == 0) {
      DoDerefVcWork(plVar4,lVar8,uVar7);
    }
    else {
      KeReleaseSpinLock(plVar2,(char)plVar4[0x41]);
    }
    uVar5 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x58);
    piVar1 = (int *)(lVar3 + 0x14);
    *piVar1 = *piVar1 + -1;
    *(undefined1 *)(lVar3 + 0x60) = uVar5;
    if (*piVar1 == 0) {
      DoDerefCmAfWork(lVar3);
    }
    else {
      KeReleaseSpinLock(lVar3 + 0x58,uVar5);
    }
    uVar7 = 0x103;
  }
  return uVar7;
}



===== PxCmIncomingCallComplete @ 140012480 =====

void PxCmIncomingCallComplete(undefined4 param_1,ulonglong param_2,undefined *param_3)

{
  int *piVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined1 uVar4;
  longlong **pplVar5;
  longlong *local_res20;
  
  local_res20 = (longlong *)0x0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_c7e600acf35c333e1969f852caaf3ce1_Traceguids;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
             &WPP_c7e600acf35c333e1969f852caaf3ce1_Traceguids,param_2);
  }
  pplVar5 = &local_res20;
  GetVcFromCtx(param_2,(longlong *)pplVar5);
  plVar3 = local_res20;
  if (local_res20 == (longlong *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
               &WPP_c7e600acf35c333e1969f852caaf3ce1_Traceguids,param_2);
    }
  }
  else {
    plVar2 = local_res20 + 0x40;
    uVar4 = KeAcquireSpinLockRaiseToDpc(plVar2);
    *(undefined1 *)(plVar3 + 0x41) = uVar4;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      param_3 = &WPP_c7e600acf35c333e1969f852caaf3ce1_Traceguids;
      pplVar5 = (longlong **)0x19;
      WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                &WPP_c7e600acf35c333e1969f852caaf3ce1_Traceguids,plVar3,(char)param_1);
    }
    *(undefined4 *)(plVar3 + 0x3b) = param_1;
    NdisSetEvent(plVar3 + 0x38);
    piVar1 = (int *)((longlong)plVar3 + 0x1c);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      DoDerefVcWork(plVar3,pplVar5,param_3);
    }
    else {
      KeReleaseSpinLock(plVar2,(char)plVar3[0x41]);
    }
  }
  return;
}



===== PxDigitTimerRoutine @ 1400125c0 =====

void PxDigitTimerRoutine(undefined8 param_1,longlong *param_2,ulonglong param_3)

{
  longlong *plVar1;
  int *piVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined1 uVar5;
  longlong lVar6;
  undefined8 uVar7;
  uint uVar8;
  
  plVar3 = param_2 + 0x40;
  uVar5 = KeAcquireSpinLockRaiseToDpc(plVar3);
  lVar6 = param_2[0xe];
  *(undefined1 *)(param_2 + 0x41) = uVar5;
  if (lVar6 != 0) {
    LOCK();
    plVar1 = (longlong *)(*(longlong *)(lVar6 + 0x10) + 0x68);
    lVar4 = *plVar1;
    *plVar1 = 0;
    UNLOCK();
    if (lVar4 != 0) {
      param_2[0xe] = 0;
      uVar8 = (-(uint)(*(int *)(lVar6 + 0x58) != 0) & 4) + 4;
      param_3 = (ulonglong)uVar8;
      PxTerminateDigitDetection((longlong)param_2,lVar6,uVar8);
    }
  }
  uVar7 = CONCAT71((int7)((ulonglong)lVar6 >> 8),(char)param_2[0x41]);
  KeReleaseSpinLock(plVar3);
  uVar5 = KeAcquireSpinLockRaiseToDpc(plVar3);
  piVar2 = (int *)((longlong)param_2 + 0x1c);
  *piVar2 = *piVar2 + -1;
  *(undefined1 *)(param_2 + 0x41) = uVar5;
  if (*piVar2 == 0) {
    DoDerefVcWork(param_2,uVar7,param_3);
  }
  else {
    KeReleaseSpinLock(plVar3,uVar5);
  }
  return;
}



===== PxGetMillisecondTickCount @ 14001267c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int PxGetMillisecondTickCount(void)

{
  longlong lVar1;
  int iVar2;
  
  lVar1 = _DAT_fffff78000000320;
  iVar2 = KeQueryTimeIncrement();
  return (int)(lVar1 / 10000) * iVar2;
}



===== PxHandleReceivedDigit @ 1400126cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PxHandleReceivedDigit(longlong *param_1,ushort *param_2,uint param_3)

{
  int *piVar1;
  longlong *plVar2;
  longlong lVar3;
  ushort uVar4;
  longlong lVar5;
  undefined1 uVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  undefined1 auStack_88 [32];
  char local_68 [8];
  undefined8 local_60;
  longlong local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong local_48;
  ulonglong local_40;
  ulonglong local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_88;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
            &WPP_cf979805fba431836a82e04c99ce8a90_Traceguids);
  }
  local_68[0] = '\0';
  if (param_3 < 2) goto LAB_1400129a1;
  plVar2 = param_1 + 0x40;
  uVar6 = KeAcquireSpinLockRaiseToDpc(plVar2);
  *(undefined1 *)(param_1 + 0x41) = uVar6;
  if (*(uint *)(param_1 + 0x1f) != 0) {
    local_4c = 0;
    local_50 = 9;
    local_60 = *(undefined8 *)(param_1[0x20] + 0x28);
    local_58 = param_1[0x22];
    local_48 = (ulonglong)*param_2;
    local_40 = (ulonglong)*(uint *)(param_1 + 0x1f);
    uVar7 = PxGetMillisecondTickCount();
    local_38 = (ulonglong)uVar7;
    KeReleaseSpinLock(plVar2,(char)param_1[0x41]);
    PxIndicateStatus(&local_60);
    goto LAB_1400129a1;
  }
  if (param_1[0xe] != 0) {
    NdisCancelTimer(param_1 + 0xf,local_68);
    uVar9 = param_1[0xe];
    lVar5 = *(longlong *)(uVar9 + 0x10);
    LOCK();
    lVar3 = *(longlong *)(lVar5 + 0x68);
    *(longlong *)(lVar5 + 0x68) = 0;
    UNLOCK();
    if (lVar3 == 0) {
      uVar6 = (undefined1)param_1[0x41];
    }
    else {
      param_1[0xe] = 0;
      *(ushort *)(*(uint *)(uVar9 + 0x50) + uVar9 + 0x30 + (ulonglong)*(uint *)(uVar9 + 0x58) * 2) =
           *param_2;
      *(int *)(uVar9 + 0x58) = *(int *)(uVar9 + 0x58) + 1;
      uVar4 = *param_2;
      uVar11 = (ulonglong)*(uint *)(uVar9 + 0x58);
      if (uVar4 < 0x37) {
        if (uVar4 == 0x36) {
          uVar8 = 6;
        }
        else if (uVar4 == 0x23) {
          uVar8 = 0xf;
        }
        else if (uVar4 == 0x2a) {
          uVar8 = 0xe;
        }
        else if (uVar4 == 0x30) {
          uVar8 = 0;
        }
        else if (uVar4 == 0x31) {
          uVar8 = 1;
        }
        else if (uVar4 == 0x32) {
          uVar8 = 2;
        }
        else if (uVar4 == 0x33) {
          uVar8 = 3;
        }
        else if (uVar4 == 0x34) {
          uVar8 = 4;
        }
        else {
          if (uVar4 != 0x35) goto LAB_1400128bb;
          uVar8 = 5;
        }
      }
      else if (uVar4 == 0x37) {
        uVar8 = 7;
      }
      else if (uVar4 == 0x38) {
        uVar8 = 8;
      }
      else if (uVar4 == 0x39) {
        uVar8 = 9;
      }
      else if (uVar4 == 0x41) {
        uVar8 = 10;
      }
      else if (uVar4 == 0x42) {
        uVar8 = 0xb;
      }
      else if (uVar4 == 0x43) {
        uVar8 = 0xc;
      }
      else if (uVar4 == 0x44) {
        uVar8 = 0xd;
      }
      else {
LAB_1400128bb:
        uVar8 = 0x10;
      }
      if (*(char *)(lVar5 + 0x44) == '\0') {
        if ((*(uint *)(uVar9 + 100) >> (int)uVar8 & 1) != 0) {
          uVar11 = 2;
          goto LAB_140012914;
        }
        if (*(uint *)(uVar9 + 0x58) == *(uint *)(uVar9 + 0x54)) {
          uVar11 = 1;
          goto LAB_140012914;
        }
        param_1[0xe] = uVar9;
        if (*(int *)(uVar9 + 0x6c) != 0) {
          *(int *)((longlong)param_1 + 0x1c) = *(int *)((longlong)param_1 + 0x1c) + 1;
          uVar8 = (ulonglong)*(uint *)(uVar9 + 0x6c);
          NdisSetTimer(param_1 + 0xf,uVar8);
        }
        LOCK();
        *(code **)(lVar5 + 0x68) = PxCancelSetQuery;
        UNLOCK();
      }
      else {
        uVar11 = 0x10;
LAB_140012914:
        PxTerminateDigitDetection((longlong)param_1,uVar9,(int)uVar11);
        uVar8 = uVar9;
      }
      uVar10 = CONCAT71((int7)(uVar8 >> 8),(char)param_1[0x41]);
      KeReleaseSpinLock(plVar2);
      if (local_68[0] == '\0') goto LAB_1400129a1;
      uVar6 = KeAcquireSpinLockRaiseToDpc(plVar2);
      piVar1 = (int *)((longlong)param_1 + 0x1c);
      *piVar1 = *piVar1 + -1;
      *(undefined1 *)(param_1 + 0x41) = uVar6;
      if (*piVar1 == 0) {
        DoDerefVcWork(param_1,uVar10,uVar11);
        goto LAB_1400129a1;
      }
    }
  }
  KeReleaseSpinLock(plVar2,uVar6);
LAB_1400129a1:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
            &WPP_cf979805fba431836a82e04c99ce8a90_Traceguids);
  }
  return;
}



===== PxStopDigitReporting @ 1400129f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PxStopDigitReporting(longlong param_1)

{
  ulonglong uVar1;
  undefined1 auStack_178 [32];
  undefined4 *local_158;
  undefined4 local_148 [4];
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_118;
  undefined4 *local_110;
  undefined4 local_108;
  undefined1 local_40 [24];
  uint local_28;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_178;
  local_148[0] = 0;
  memset(&local_138,0,0x118);
  local_130 = 0;
  local_12c = 0;
  local_138 = 0xf00196;
  NdisInitializeEvent(local_40);
  local_110 = local_148;
  local_158 = &local_138;
  local_134 = 1;
  local_118 = 0xfe001009;
  local_108 = 4;
  uVar1 = NdisCoOidRequest(*(undefined8 *)(*(longlong *)(param_1 + 0x58) + 0x20),
                           *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 0x18),
                           *(undefined8 *)(param_1 + 0x28),0);
  if ((int)uVar1 == 0x103) {
    NdisWaitEvent(local_40,0);
    uVar1 = (ulonglong)local_28;
  }
  return uVar1;
}



===== PxTerminateDigitDetection @ 140012adc =====

void PxTerminateDigitDetection(longlong param_1,longlong param_2,undefined4 param_3)

{
  longlong lVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  uint uVar6;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
            &WPP_cf979805fba431836a82e04c99ce8a90_Traceguids);
  }
  lVar1 = *(longlong *)(param_2 + 0x10);
  iVar3 = PxGetMillisecondTickCount();
  uVar4 = *(uint *)(param_2 + 0x50);
  *(undefined4 *)(param_2 + 0x60) = param_3;
  *(int *)(param_2 + 0x5c) = iVar3;
  uVar6 = *(uint *)(param_2 + 0x58) + uVar4;
  if (((uVar6 < uVar4) || (*(uint *)(param_2 + 0x28) <= uVar6)) || (uVar4 < 0x40)) {
    *(undefined4 *)(lVar1 + 0x30) = 0xc0012019;
    uVar4 = *(uint *)(param_2 + 0x28);
  }
  else {
    *(undefined2 *)((ulonglong)uVar4 + param_2 + 0x30 + (ulonglong)*(uint *)(param_2 + 0x58) * 2) =
         0;
    *(undefined4 *)(lVar1 + 0x30) = 0;
    uVar4 = *(uint *)(param_2 + 0x28);
  }
  *(ulonglong *)(lVar1 + 0x38) = (ulonglong)(uVar4 - 1) + 0x38;
  IofCompleteRequest(lVar1,0);
  KeReleaseSpinLock(param_1 + 0x200,*(undefined1 *)(param_1 + 0x208));
  uVar5 = PxStopDigitReporting(param_1);
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x200);
  *(undefined1 *)(param_1 + 0x208) = uVar2;
  if ((int)uVar5 != 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if (1 < (byte)WPP_GLOBAL_Control[0x29]) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
               &WPP_cf979805fba431836a82e04c99ce8a90_Traceguids,(int)uVar5);
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
            &WPP_cf979805fba431836a82e04c99ce8a90_Traceguids);
  }
  return;
}



===== PxCancelGetEvents @ 140012c50 =====

void PxCancelGetEvents(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
             &WPP_49acb68b66733a55de6af06c8932e04d_Traceguids,param_2);
  }
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  DAT_14000d788 = KeAcquireSpinLockRaiseToDpc(&DAT_14000d780);
  lVar1 = DAT_14000d778;
  DAT_14000d778 = 0;
  KeReleaseSpinLock(&DAT_14000d780,DAT_14000d788);
  if (lVar1 != 0) {
    LOCK();
    *(undefined8 *)(lVar1 + 0x68) = 0;
    UNLOCK();
    *(undefined8 *)(lVar1 + 0x38) = 0;
    *(undefined4 *)(lVar1 + 0x30) = 0xc0000120;
    IofCompleteRequest(lVar1,0);
  }
  return;
}



===== PxCancelSetQuery @ 140012d10 =====

void PxCancelSetQuery(undefined8 param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  code *pcVar4;
  bool bVar5;
  undefined8 *puVar6;
  undefined1 uVar7;
  undefined8 *puVar8;
  longlong lVar9;
  undefined2 local_res10;
  undefined1 local_res12;
  
  bVar5 = false;
  local_res10 = 0;
  lVar9 = 0;
  local_res12 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
             &WPP_49acb68b66733a55de6af06c8932e04d_Traceguids,param_2);
  }
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  NdisAcquireRWLockRead(DAT_14000d7c8,&local_res10,0);
  for (puVar8 = DAT_14000d7b0; (undefined8 **)puVar8 != &DAT_14000d7b0;
      puVar8 = (undefined8 *)*puVar8) {
    uVar7 = KeAcquireSpinLockRaiseToDpc(puVar8 + 0x40);
    puVar1 = puVar8 + 0xc;
    *(undefined1 *)(puVar8 + 0x41) = uVar7;
    puVar2 = (undefined8 *)*puVar1;
    do {
      puVar6 = puVar2;
      if (puVar6 == puVar1) goto LAB_140012e05;
      lVar9 = puVar6[2];
      puVar2 = (undefined8 *)*puVar6;
    } while (*(char *)(lVar9 + 0x44) == '\0');
    bVar5 = true;
    if (((undefined8 *)puVar2[1] != puVar6) ||
       (puVar3 = (undefined8 *)puVar6[1], (undefined8 *)*puVar3 != puVar6)) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    *puVar3 = puVar2;
    puVar2[1] = puVar3;
LAB_140012e05:
    if ((undefined8 *)*puVar1 == puVar1) {
      *(uint *)(puVar8 + 4) = *(uint *)(puVar8 + 4) & 0xffffffef;
    }
    if (((!bVar5) && (puVar8[0xe] != 0)) &&
       (lVar9 = *(longlong *)(puVar8[0xe] + 0x10), *(char *)(lVar9 + 0x44) != '\0')) {
      puVar8[0xe] = 0;
      bVar5 = true;
    }
    KeReleaseSpinLock(puVar8 + 0x40,*(undefined1 *)(puVar8 + 0x41));
    if (bVar5) break;
  }
  NdisReleaseRWLock(DAT_14000d7c8,&local_res10);
  if (bVar5) {
    LOCK();
    *(undefined8 *)(lVar9 + 0x68) = 0;
    UNLOCK();
    *(undefined8 *)(lVar9 + 0x38) = 0;
    *(undefined4 *)(lVar9 + 0x30) = 0xc0000120;
    IofCompleteRequest(lVar9,0);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
             &WPP_49acb68b66733a55de6af06c8932e04d_Traceguids,param_2);
  }
  return;
}



===== AllocateTapiCallInfo @ 140012ee4 =====

undefined8 AllocateTapiCallInfo(longlong param_1,void *param_2)

{
  undefined4 *_Dst;
  undefined8 uVar1;
  uint *puVar2;
  undefined4 uVar3;
  
  if (*(longlong *)(param_1 + 0x130) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x130),0);
  }
  puVar2 = (uint *)((longlong)param_2 + 8);
  if (param_2 == (void *)0x0) {
    uVar3 = 0x400;
    puVar2 = (uint *)&DAT_00000008;
  }
  else {
    uVar3 = *(undefined4 *)((longlong)param_2 + 8);
  }
  _Dst = (undefined4 *)ExAllocatePool2(0x40,uVar3,0x665850);
  *(undefined4 **)(param_1 + 0x130) = _Dst;
  if (_Dst == (undefined4 *)0x0) {
    uVar1 = 0xc000009a;
  }
  else {
    *(undefined4 *)(param_1 + 0x120) = 0;
    if (param_2 == (void *)0x0) {
      *_Dst = uVar3;
      *(undefined4 *)(*(longlong *)(param_1 + 0x130) + 4) = uVar3;
      *(undefined4 *)(*(longlong *)(param_1 + 0x130) + 8) = 0x158;
    }
    else {
      memmove(_Dst,param_2,(ulonglong)*puVar2);
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== GetLineEvents @ 140012fb8 =====

ulonglong GetLineEvents(longlong param_1,uint param_2)

{
  undefined8 *_Src;
  undefined8 *puVar1;
  code *pcVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  
  uVar4 = 0;
  while( true ) {
    puVar3 = TspEventList;
    if ((undefined8 **)TspEventList == &TspEventList) {
      return uVar4;
    }
    if (param_2 < 0x30) break;
    if (((undefined8 **)TspEventList[1] != &TspEventList) ||
       (puVar1 = (undefined8 *)*TspEventList, (undefined8 *)puVar1[1] != TspEventList)) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      return uVar4;
    }
    _Src = TspEventList + 2;
    TspEventList = puVar1;
    puVar1[1] = &TspEventList;
    DAT_14000d770 = DAT_14000d770 + -1;
    memmove((void *)(uVar4 + param_1),_Src,0x30);
    uVar4 = (ulonglong)((int)uVar4 + 0x30);
    param_2 = param_2 - 0x30;
    ExFreeToNPagedLookasideList(&ProviderEventLookaside,puVar3);
  }
  return uVar4;
}



===== InsertVcInTable @ 140013070 =====

bool InsertVcInTable(undefined8 *param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  void *_Dst;
  undefined8 *puVar3;
  ulonglong uVar4;
  undefined1 *puVar5;
  int iVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined2 local_res10;
  undefined1 local_res12;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [40];
  
  local_res10 = 0;
  local_res12 = 0;
  NdisAcquireRWLockWrite(DAT_14000d7c8,&local_res10,0);
  if (VcTable == DAT_14000d7a4) {
    _Dst = (void *)ExAllocatePool2(0x40,((DAT_14000d7a4 >> 1) + DAT_14000d7a4) * 8,0x325850);
    if (_Dst == (void *)0x0) {
      NdisReleaseRWLock(DAT_14000d7c8,&local_res10);
      return false;
    }
    memmove(_Dst,DAT_14000d7c0,(ulonglong)DAT_14000d7a4 << 3);
    ExFreePoolWithTag(DAT_14000d7c0,0);
    DAT_14000d7a4 = DAT_14000d7a4 + (DAT_14000d7a4 >> 1);
    DAT_14000d7c0 = _Dst;
  }
  uVar8 = (ulonglong)DAT_14000d7a4;
  puVar5 = auStack_48;
  uVar4 = (ulonglong)DAT_14000d7a8;
  uVar7 = uVar8;
  do {
    iVar6 = (int)uVar7;
    if (*(longlong *)((longlong)DAT_14000d7c0 + uVar4 * 8) == 0) {
      KeAcquireSpinLockAtDpcLevel(param_1 + 0x40);
      puVar5 = auStack_48;
      param_1[0x23] = uVar4;
      puVar3 = &DAT_14000d7b0;
      *(undefined8 **)((longlong)DAT_14000d7c0 + uVar4 * 8) = param_1;
      if ((undefined8 *)*DAT_14000d7b8 != &DAT_14000d7b0) {
        puVar3 = (undefined8 *)0x3;
        pcVar2 = (code *)swi(0x29);
        DAT_14000d7b8 = (undefined8 *)(*pcVar2)();
        puVar5 = auStack_40;
      }
      *param_1 = puVar3;
      param_1[1] = DAT_14000d7b8;
      *DAT_14000d7b8 = param_1;
      VcTable = VcTable + 1;
      DAT_14000d7a8 = (DAT_14000d7a8 + 1) % DAT_14000d7a4;
      DAT_14000d7b8 = param_1;
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 2;
      *(undefined8 *)(puVar5 + -8) = 0x140013203;
      KeReleaseSpinLockFromDpcLevel(param_1 + 0x40);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar1 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        *(undefined8 *)(puVar5 + 0x20) = param_1[0x23];
        *(undefined8 *)(puVar5 + -8) = 0x140013237;
        WPP_SF_qP(uVar1,0x94,uVar8,param_1,puVar5[0x20]);
      }
      goto LAB_140013237;
    }
    uVar4 = (ulonglong)((int)uVar4 + 1) % uVar8;
    uVar7 = (ulonglong)(iVar6 - 1U);
  } while (iVar6 - 1U != 0);
  iVar6 = 0;
LAB_140013237:
  *(undefined8 *)(puVar5 + -8) = 0x14001324a;
  NdisReleaseRWLock(DAT_14000d7c8,puVar5 + 0x58);
  if (((iVar6 == 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar1 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(undefined8 *)(puVar5 + -8) = 0x14001327d;
    WPP_SF_q(uVar1,0x95,&WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,param_1);
  }
  return iVar6 != 0;
}



===== IsTapiDeviceValid @ 14001329c =====

bool IsTapiDeviceValid(int param_1,longlong *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong *plVar3;
  uint uVar4;
  undefined2 local_res10;
  undefined1 local_res12;
  
  local_res10 = 0;
  local_res12 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x97,
             &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,param_1);
  }
  uVar2 = DAT_14000d7f8;
  *param_2 = 0;
  NdisAcquireRWLockRead(uVar2,&local_res10,0);
  uVar4 = 0;
  if (DAT_14000d7e4 != 0) {
    plVar3 = DAT_14000d7f0;
    do {
      lVar1 = *plVar3;
      if ((lVar1 != 0) && (*(int *)(lVar1 + 0x20) == param_1)) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x98,
                   &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,*(int *)(lVar1 + 0x20));
        }
        *param_2 = lVar1;
        KeAcquireSpinLockAtDpcLevel(lVar1 + 0x78);
        *(int *)(lVar1 + 0x10) = *(int *)(lVar1 + 0x10) + 1;
        KeReleaseSpinLockFromDpcLevel(lVar1 + 0x78);
        break;
      }
      uVar4 = uVar4 + 1;
      plVar3 = plVar3 + 1;
    } while (uVar4 < DAT_14000d7e4);
  }
  NdisReleaseRWLock(DAT_14000d7f8,&local_res10);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x99,
            &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
  }
  return *param_2 != 0;
}



===== IsTapiLineValid @ 1400133f4 =====

bool IsTapiLineValid(int param_1,longlong *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  uint uVar3;
  undefined2 local_res10;
  undefined1 local_res12;
  
  *param_2 = 0;
  local_res10 = 0;
  local_res12 = 0;
  NdisAcquireRWLockRead(DAT_14000d7f8,&local_res10);
  uVar3 = 0;
  if (DAT_14000d7e4 != 0) {
    plVar2 = DAT_14000d7f0;
    do {
      lVar1 = *plVar2;
      if ((lVar1 != 0) && (*(int *)(lVar1 + 0x30) == param_1)) {
        *param_2 = lVar1;
        KeAcquireSpinLockAtDpcLevel(lVar1 + 0x78);
        *(int *)(lVar1 + 0x10) = *(int *)(lVar1 + 0x10) + 1;
        KeReleaseSpinLockFromDpcLevel(lVar1 + 0x78);
        break;
      }
      uVar3 = uVar3 + 1;
      plVar2 = plVar2 + 1;
    } while (uVar3 < DAT_14000d7e4);
  }
  NdisReleaseRWLock(DAT_14000d7f8,&local_res10);
  return *param_2 != 0;
}



===== IsVcValid @ 1400134bc =====

bool IsVcValid(ulonglong param_1,longlong *param_2)

{
  longlong lVar1;
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  lVar1 = 0;
  NdisAcquireRWLockRead(DAT_14000d7c8,&local_res8,0);
  if ((param_1 < DAT_14000d7a4) && (lVar1 = *(longlong *)(DAT_14000d7c0 + param_1 * 8), lVar1 != 0))
  {
    KeAcquireSpinLockAtDpcLevel(lVar1 + 0x200);
    if ((*(uint *)(lVar1 + 0x20) & 2) == 0) {
      KeReleaseSpinLockFromDpcLevel(lVar1 + 0x200);
      lVar1 = 0;
    }
    else {
      *(int *)(lVar1 + 0x1c) = *(int *)(lVar1 + 0x1c) + 1;
      KeReleaseSpinLockFromDpcLevel();
    }
  }
  NdisReleaseRWLock(DAT_14000d7c8,&local_res8);
  *param_2 = lVar1;
  return lVar1 != 0;
}



===== MarkProviderConnected @ 140013590 =====

void MarkProviderConnected(longlong param_1)

{
  uint *puVar1;
  longlong lVar2;
  undefined1 uVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined2 local_res10;
  undefined1 local_res12;
  
  local_res10 = 0;
  local_res12 = 0;
  NdisAcquireRWLockRead(DAT_14000d7f8,&local_res10,0);
  uVar5 = 0;
  if (DAT_14000d7e4 != 0) {
    do {
      lVar2 = *(longlong *)(DAT_14000d7f0 + uVar5 * 8);
      if (lVar2 != 0) {
        uVar3 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x78);
        *(undefined1 *)(lVar2 + 0x80) = uVar3;
        if (*(longlong *)(lVar2 + 0x18) == param_1) {
          puVar1 = (uint *)(*(longlong *)(lVar2 + 0x50) + 0x38);
          *puVar1 = *puVar1 | 1;
        }
        KeReleaseSpinLock(lVar2 + 0x78,*(undefined1 *)(lVar2 + 0x80));
      }
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar4;
    } while (uVar4 < DAT_14000d7e4);
  }
  NdisReleaseRWLock(DAT_14000d7f8,&local_res10);
  return;
}



===== MarkProviderDisconnected @ 140013660 =====

void MarkProviderDisconnected(longlong param_1)

{
  uint *puVar1;
  longlong lVar2;
  undefined1 uVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined2 local_res10;
  undefined1 local_res12;
  
  local_res10 = 0;
  local_res12 = 0;
  NdisAcquireRWLockRead(DAT_14000d7f8,&local_res10,0);
  uVar5 = 0;
  if (DAT_14000d7e4 != 0) {
    do {
      lVar2 = *(longlong *)(DAT_14000d7f0 + uVar5 * 8);
      if (lVar2 != 0) {
        uVar3 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x78);
        *(undefined1 *)(lVar2 + 0x80) = uVar3;
        if (*(longlong *)(lVar2 + 0x18) == param_1) {
          puVar1 = (uint *)(*(longlong *)(lVar2 + 0x50) + 0x38);
          *puVar1 = *puVar1 & 0xfffffffe;
        }
        KeReleaseSpinLock(lVar2 + 0x78,*(undefined1 *)(lVar2 + 0x80));
      }
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar4;
    } while (uVar4 < DAT_14000d7e4);
  }
  NdisReleaseRWLock(DAT_14000d7f8,&local_res10);
  return;
}



===== PxTapiAccept @ 140013730 =====

undefined8 PxTapiAccept(void)

{
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
  }
  return 0xc0012016;
}



===== PxTapiAnswer @ 1400137a0 =====

undefined8 PxTapiAnswer(longlong param_1,undefined8 param_2,undefined *param_3)

{
  int *piVar1;
  longlong *plVar2;
  longlong *plVar3;
  bool bVar4;
  undefined1 uVar5;
  undefined8 uVar6;
  longlong **pplVar7;
  longlong lVar8;
  longlong *local_res8;
  
  local_res8 = (longlong *)0x0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
            &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
  }
  pplVar7 = &local_res8;
  bVar4 = IsVcValid(*(ulonglong *)(param_1 + 0x38),(longlong *)pplVar7);
  plVar3 = local_res8;
  if (bVar4) {
    plVar2 = local_res8 + 0x40;
    uVar5 = KeAcquireSpinLockRaiseToDpc(plVar2);
    *(undefined1 *)(plVar3 + 0x41) = uVar5;
    if ((int)plVar3[2] == 2) {
      if ((*(uint *)(plVar3 + 4) & 4) != 0) {
        PxStopIncomingCallTimeout((longlong)plVar3,pplVar7,param_3);
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
      }
      *(int *)((longlong)plVar3 + 0x14) = (int)plVar3[2];
      *(undefined4 *)(plVar3 + 2) = 4;
      KeReleaseSpinLock(plVar2,(char)plVar3[0x41]);
      param_3 = (undefined *)plVar3[0x27];
      lVar8 = plVar3[5];
      NdisClIncomingCallComplete(0);
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (WPP_GLOBAL_Control[0x29] != '\0')) {
        pplVar7 = (longlong **)0x0;
        WPP_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,param_3,plVar3,(char)plVar3[4],
                   (char)*(undefined4 *)((longlong)plVar3 + 0x124));
      }
      lVar8 = CONCAT71((int7)((ulonglong)pplVar7 >> 8),(char)plVar3[0x41]);
      KeReleaseSpinLock(plVar2);
    }
    uVar5 = KeAcquireSpinLockRaiseToDpc(plVar2);
    *(undefined1 *)(plVar3 + 0x41) = uVar5;
    piVar1 = (int *)((longlong)plVar3 + 0x1c);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      DoDerefVcWork(plVar3,lVar8,param_3);
    }
    else {
      KeReleaseSpinLock(plVar2,uVar5);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
    uVar6 = 0;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,param_3,
               *(undefined8 *)(param_1 + 0x38));
    }
    uVar6 = 0xc001200d;
  }
  return uVar6;
}



===== PxTapiClose @ 140013980 =====

undefined8 PxTapiClose(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  int *piVar2;
  undefined1 *puVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong lVar7;
  longlong *plVar8;
  undefined8 *puVar9;
  code *pcVar10;
  bool bVar11;
  undefined1 uVar12;
  int iVar13;
  longlong lVar14;
  undefined1 *puVar15;
  longlong local_res8;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  
  local_res8 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,param_3,*(undefined8 *)(param_1 + 0x38)
            );
  }
  bVar11 = IsTapiLineValid(*(int *)(param_1 + 0x38),&local_res8);
  lVar14 = local_res8;
  if (!bVar11) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,param_3,
               *(undefined8 *)(param_1 + 0x38));
    }
    return 0x1002;
  }
  lVar1 = local_res8 + 0x78;
  puVar3 = (undefined1 *)(local_res8 + 0x80);
  uVar12 = KeAcquireSpinLockRaiseToDpc();
  puVar15 = auStack_48;
  *puVar3 = uVar12;
  piVar2 = (int *)(*(longlong *)(lVar14 + 0x50) + 0xc);
  *piVar2 = *piVar2 + -1;
  if (*(int *)(*(longlong *)(lVar14 + 0x50) + 0xc) != 0) {
    piVar2 = (int *)(lVar14 + 0x10);
    *piVar2 = *piVar2 + -1;
    iVar13 = *piVar2;
    goto LAB_140013b7d;
  }
  plVar5 = *(longlong **)(lVar14 + 0x38);
  plVar6 = *(longlong **)(lVar14 + 0x40);
  *(undefined8 *)(lVar14 + 0x40) = 0;
  *(undefined4 *)(*(longlong *)(lVar14 + 0x50) + 0x10) = 0;
  KeReleaseSpinLock(lVar1,*puVar3);
  puVar15 = auStack_48;
  if (plVar5 != (longlong *)0x0) {
    plVar4 = plVar5 + 0x17;
    uVar12 = KeAcquireSpinLockRaiseToDpc(plVar4);
    *(undefined1 *)(plVar5 + 0x18) = uVar12;
    *(int *)((longlong)plVar5 + 0x14) = *(int *)((longlong)plVar5 + 0x14) + 1;
    if ((plVar6 == (longlong *)0x0) || ((int)plVar6[2] != 3)) {
LAB_140013b41:
      puVar15 = auStack_48;
      piVar2 = (int *)((longlong)plVar5 + 0x14);
      *piVar2 = *piVar2 + -1;
      if (*piVar2 == 0) {
        DoDerefClAfWork(plVar5);
        puVar15 = auStack_48;
        goto LAB_140013b67;
      }
    }
    else {
      lVar7 = *plVar6;
      if ((*(longlong **)(lVar7 + 8) == plVar6) &&
         (plVar8 = (longlong *)plVar6[1], (longlong *)*plVar8 == plVar6)) {
        *plVar8 = lVar7;
        *(longlong **)(lVar7 + 8) = plVar8;
        puVar9 = (undefined8 *)plVar5[8];
        if ((longlong *)*puVar9 == plVar5 + 7) {
          plVar6[1] = (longlong)puVar9;
          *plVar6 = (longlong)(plVar5 + 7);
          *puVar9 = plVar6;
          plVar5[8] = (longlong)plVar6;
          KeReleaseSpinLock(plVar4,(char)plVar5[0x18]);
          LOCK();
          *(undefined4 *)(plVar6 + 2) = 1;
          UNLOCK();
          iVar13 = NdisClDeregisterSap(plVar6[7]);
          if (iVar13 != 0x103) {
            PxClDeregisterSapComplete((char)iVar13,plVar6);
          }
          uVar12 = KeAcquireSpinLockRaiseToDpc(plVar4);
          *(undefined1 *)(plVar5 + 0x18) = uVar12;
          lVar14 = local_res8;
          goto LAB_140013b41;
        }
      }
      pcVar10 = (code *)swi(0x29);
      (*pcVar10)(3,uVar12);
      puVar15 = auStack_40;
    }
    *(undefined8 *)(puVar15 + -8) = 0x140013b62;
    KeReleaseSpinLock(plVar4);
  }
LAB_140013b67:
  *(undefined8 *)(puVar15 + -8) = 0x140013b71;
  uVar12 = KeAcquireSpinLockRaiseToDpc(lVar1);
  *puVar3 = uVar12;
  piVar2 = (int *)(lVar14 + 0x10);
  *piVar2 = *piVar2 + -1;
  iVar13 = *piVar2;
LAB_140013b7d:
  uVar12 = *puVar3;
  if (iVar13 == 0) {
    *(undefined8 *)(puVar15 + -8) = 0x140013b8c;
    KeReleaseSpinLock();
    *(undefined8 *)(puVar15 + -8) = 0x140013b99;
    FreeTapiLine(lVar14);
  }
  else {
    *(undefined8 *)(puVar15 + -8) = 0x140013ba2;
    KeReleaseSpinLock(lVar1,uVar12);
  }
  return 0;
}



===== PxTapiCloseCall @ 140013bd0 =====

undefined8 PxTapiCloseCall(longlong param_1,undefined8 param_2,undefined *param_3)

{
  int *piVar1;
  uint uVar2;
  longlong *plVar3;
  bool bVar4;
  undefined1 uVar5;
  undefined8 uVar6;
  longlong **pplVar7;
  longlong *local_res8;
  
  local_res8 = (longlong *)0x0;
  pplVar7 = &local_res8;
  bVar4 = IsVcValid(*(ulonglong *)(param_1 + 0x38),(longlong *)pplVar7);
  plVar3 = local_res8;
  if (bVar4) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      param_3 = &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids;
      pplVar7 = (longlong **)0x2b;
      WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
                &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,local_res8,(char)local_res8[2]);
    }
    uVar5 = KeAcquireSpinLockRaiseToDpc(plVar3 + 0x40);
    *(undefined1 *)(plVar3 + 0x41) = uVar5;
    uVar2 = *(uint *)((longlong)plVar3 + 0x24);
    *(uint *)((longlong)plVar3 + 0x24) = uVar2 | 4;
    if ((uVar2 & 0x1004) != 0x1000) {
      pplVar7 = (longlong **)0x0;
      PxVcCleanup((longlong)plVar3,(longlong *)0x0,param_3);
      PxTapiCompleteAllIrps((longlong)plVar3);
      *(int *)((longlong)plVar3 + 0x1c) = *(int *)((longlong)plVar3 + 0x1c) + -1;
    }
    piVar1 = (int *)((longlong)plVar3 + 0x1c);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      DoDerefVcWork(plVar3,pplVar7,param_3);
    }
    else {
      KeReleaseSpinLock(plVar3 + 0x40,(char)plVar3[0x41]);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
    uVar6 = 0;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,param_3,
               *(undefined8 *)(param_1 + 0x38));
    }
    uVar6 = 0xc001200d;
  }
  return uVar6;
}



===== PxTapiCompleteAllIrps @ 140013d18 =====

void PxTapiCompleteAllIrps(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uVar4;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x84,
             &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,param_1);
  }
  if ((*(uint *)(param_1 + 0x20) & 0x10) != 0) {
    PxTapiCompleteDropIrps(param_1);
  }
  lVar2 = *(longlong *)(param_1 + 0x70);
  if (lVar2 != 0) {
    *(undefined8 *)(param_1 + 0x70) = 0;
    KeReleaseSpinLock(param_1 + 0x200,*(undefined1 *)(param_1 + 0x208));
    lVar3 = *(longlong *)(lVar2 + 0x10);
    LOCK();
    *(undefined8 *)(lVar3 + 0x68) = 0;
    UNLOCK();
    iVar1 = *(int *)(lVar2 + 0x28);
    *(undefined4 *)(lVar3 + 0x30) = 0;
    *(ulonglong *)(lVar3 + 0x38) = (ulonglong)(iVar1 - 1) + 0x38;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x85,
                &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,lVar3,
                (char)*(undefined4 *)(lVar2 + 0x20));
    }
    IofCompleteRequest(lVar3,0);
    uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x200);
    *(undefined1 *)(param_1 + 0x208) = uVar4;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x86,
            &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
  }
  return;
}



===== PxTapiCompleteDropIrps @ 140013e60 =====

void PxTapiCompleteDropIrps(longlong param_1)

{
  longlong *plVar1;
  int iVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 uVar5;
  code *pcVar6;
  undefined1 uVar7;
  undefined1 *puVar8;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x81,
             &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,param_1);
  }
  puVar8 = auStack_48;
  plVar1 = (longlong *)(param_1 + 0x60);
  do {
    plVar3 = (longlong *)*plVar1;
    if (plVar3 == plVar1) {
LAB_140013f7d:
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        *(undefined8 *)(puVar8 + -8) = 0x140013fa4;
        WPP_SF_(uVar5,0x83,&WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
      }
      return;
    }
    if (((longlong *)plVar3[1] != plVar1) ||
       (lVar4 = *plVar3, (longlong *)*(longlong *)(lVar4 + 8) != plVar3)) {
      pcVar6 = (code *)swi(0x29);
      (*pcVar6)(3);
      puVar8 = auStack_40;
      goto LAB_140013f7d;
    }
    *plVar1 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar1;
    if ((longlong *)*plVar1 == plVar1) {
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffffef;
    }
    KeReleaseSpinLock(param_1 + 0x200,*(undefined1 *)(param_1 + 0x208));
    lVar4 = plVar3[2];
    LOCK();
    *(undefined8 *)(lVar4 + 0x68) = 0;
    UNLOCK();
    iVar2 = *(int *)(plVar3 + 5);
    *(undefined4 *)(lVar4 + 0x30) = 0;
    *(ulonglong *)(lVar4 + 0x38) = (ulonglong)(iVar2 - 1) + 0x38;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x82,
                &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,lVar4,
                (char)*(undefined4 *)(plVar3 + 4));
    }
    IofCompleteRequest(lVar4,0);
    uVar7 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x200);
    *(undefined1 *)(param_1 + 0x208) = uVar7;
  } while( true );
}



===== PxTapiConditionalMediaDetection @ 140013fd0 =====

undefined8 PxTapiConditionalMediaDetection(void)

{
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
  }
  return 0;
}



===== PxTapiConfigDialog @ 140014040 =====

undefined8 PxTapiConfigDialog(void)

{
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
  }
  return 0;
}



===== PxTapiDevSpecific @ 1400140b0 =====

undefined8 PxTapiDevSpecific(void)

{
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
  }
  return 0;
}



===== PxTapiDial @ 140014120 =====

undefined8 PxTapiDial(void)

{
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
  }
  return 0xc0012016;
}



===== PxTapiDrop @ 140014190 =====

int PxTapiDrop(longlong *param_1,undefined8 param_2,undefined *param_3)

{
  int *piVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  longlong *plVar5;
  bool bVar6;
  undefined1 uVar7;
  int iVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong **pplVar11;
  undefined8 uVar12;
  undefined1 *puVar13;
  longlong *plVar14;
  longlong *local_res8;
  undefined1 auStackY_58 [8];
  undefined1 auStackY_50 [24];
  
  local_res8 = (longlong *)0x0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
            &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
  }
  pplVar11 = &local_res8;
  bVar6 = IsVcValid(param_1[7],(longlong *)pplVar11);
  plVar5 = local_res8;
  if (bVar6) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      pplVar11 = (longlong **)0x37;
      WPP_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,param_3,local_res8,
                 (char)local_res8[2],(char)*(undefined4 *)((longlong)local_res8 + 0x124));
    }
    plVar2 = plVar5 + 0x40;
    uVar7 = KeAcquireSpinLockRaiseToDpc(plVar2);
    plVar14 = local_res8;
    puVar13 = auStackY_58;
    *(undefined1 *)(plVar5 + 0x41) = uVar7;
    if ((*(uint *)((longlong)plVar5 + 0x24) & 2) == 0) {
      lVar3 = param_1[2];
      LOCK();
      *(code **)(lVar3 + 0x68) = PxCancelSetQuery;
      UNLOCK();
      plVar9 = local_res8 + 0xc;
      plVar10 = (longlong *)local_res8[0xd];
      if ((longlong *)*plVar10 != plVar9) {
        plVar10 = (longlong *)0x3;
        pcVar4 = (code *)swi(0x29);
        plVar9 = (longlong *)(*pcVar4)();
        puVar13 = auStackY_50;
      }
      param_1[1] = (longlong)plVar10;
      uVar12 = 0x10;
      *param_1 = (longlong)plVar9;
      *plVar10 = (longlong)param_1;
      plVar9[1] = (longlong)param_1;
      *(uint *)((longlong)plVar5 + 0x24) = *(uint *)((longlong)plVar5 + 0x24) | 2;
      *(undefined8 *)(puVar13 + -8) = 0x1400142eb;
      iVar8 = PxVcCleanup((longlong)plVar14,(longlong *)0x10,param_3);
      if (iVar8 != 0x103) {
        LOCK();
        *(undefined8 *)(lVar3 + 0x68) = 0;
        UNLOCK();
        plVar14 = *(longlong **)(puVar13 + 0x60);
      }
      piVar1 = (int *)((longlong)plVar14 + 0x1c);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        *(undefined8 *)(puVar13 + -8) = 0x14001430b;
        DoDerefVcWork(plVar14,uVar12,param_3);
      }
      else {
        lVar3 = plVar5[0x41];
        *(undefined8 *)(puVar13 + -8) = 0x14001431d;
        KeReleaseSpinLock(plVar2,(char)lVar3);
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar12 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        *(undefined8 *)(puVar13 + -8) = 0x140014349;
        WPP_SF_(uVar12,0x38,&WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
      }
    }
    else {
      piVar1 = (int *)((longlong)plVar5 + 0x1c);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        DoDerefVcWork(plVar5,pplVar11,param_3);
      }
      else {
        KeReleaseSpinLock(plVar2,(char)plVar5[0x41]);
      }
      iVar8 = 0;
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,param_3,param_1[7]);
    }
    iVar8 = -0x3ffedff3;
  }
  return iVar8;
}



===== PxTapiGatherDigits @ 140014370 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PxTapiGatherDigits(longlong param_1,undefined8 param_2,undefined *param_3)

{
  longlong *plVar1;
  int *piVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong lVar5;
  bool bVar6;
  undefined1 uVar7;
  int iVar8;
  longlong **pplVar9;
  undefined7 uVar10;
  longlong *plVar11;
  undefined1 auStack_198 [32];
  undefined4 *local_178;
  longlong *local_168 [2];
  undefined4 local_158;
  undefined4 local_154;
  undefined8 local_150;
  undefined4 local_138;
  longlong local_130;
  undefined4 local_128;
  undefined1 local_60 [24];
  int local_48;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_198;
  iVar8 = 0;
  local_168[0] = (longlong *)0x0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x78,
            &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
  }
  pplVar9 = local_168;
  bVar6 = IsVcValid(*(ulonglong *)(param_1 + 0x38),(longlong *)pplVar9);
  plVar11 = local_168[0];
  if (!bVar6) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      param_3 = &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids;
      pplVar9 = (longlong **)0x79;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x79,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
    iVar8 = 0x1002;
LAB_140014416:
    plVar11 = local_168[0];
  }
  else {
    plVar3 = local_168[0] + 0x40;
    uVar7 = KeAcquireSpinLockRaiseToDpc(plVar3);
    plVar4 = plVar11 + 0x41;
    *(undefined1 *)plVar4 = uVar7;
    uVar10 = (undefined7)((ulonglong)pplVar9 >> 8);
    if ((int)plVar11[0x1f] == 0) {
      plVar1 = plVar11 + 0xe;
      if (*plVar1 == 0) {
        if (*(longlong *)(param_1 + 0x48) != 0) {
          lVar5 = *(longlong *)(param_1 + 0x10);
          LOCK();
          *(code **)(lVar5 + 0x68) = PxCancelSetQuery;
          UNLOCK();
          *plVar1 = param_1;
          KeReleaseSpinLock(plVar3,CONCAT71(uVar10,(char)*plVar4));
          plVar11 = local_168[0];
          NdisInitializeTimer(local_168[0] + 0xf,PxDigitTimerRoutine,local_168[0]);
          memset(&local_158,0,0x118);
          local_158 = 0xf00196;
          local_150 = 0;
          NdisInitializeEvent(local_60);
          local_154 = 1;
          local_130 = param_1 + 0x44;
          local_138 = 0xfe001008;
          local_178 = &local_158;
          local_128 = 4;
          param_3 = (undefined *)plVar11[5];
          pplVar9 = *(longlong ***)(plVar11[7] + 0x18);
          iVar8 = NdisCoOidRequest(*(undefined8 *)(plVar11[0xb] + 0x20),pplVar9,param_3,0);
          if (iVar8 == 0x103) {
            pplVar9 = (longlong **)0x0;
            NdisWaitEvent(local_60);
            iVar8 = local_48;
          }
          if (iVar8 == 0) {
            if (*(int *)(param_1 + 0x68) != 0) {
              uVar7 = KeAcquireSpinLockRaiseToDpc(plVar3);
              *(undefined1 *)plVar4 = uVar7;
              *(int *)((longlong)plVar11 + 0x1c) = *(int *)((longlong)plVar11 + 0x1c) + 1;
              KeReleaseSpinLock(plVar3,(char)*plVar4);
              pplVar9 = (longlong **)(ulonglong)*(uint *)(param_1 + 0x68);
              NdisSetTimer(plVar11 + 0xf);
            }
            iVar8 = 0x103;
            goto LAB_140014645;
          }
          uVar7 = KeAcquireSpinLockRaiseToDpc(plVar3);
          *(undefined1 *)plVar4 = uVar7;
          *plVar1 = 0;
          LOCK();
          *(undefined8 *)(lVar5 + 0x68) = 0;
          UNLOCK();
          pplVar9 = (longlong **)CONCAT71((int7)((ulonglong)pplVar9 >> 8),(char)*plVar4);
          KeReleaseSpinLock(plVar3);
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (2 < (byte)WPP_GLOBAL_Control[0x29])) {
            param_3 = &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids;
            pplVar9 = (longlong **)0x7a;
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7a,
                    &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
          }
          goto LAB_140014416;
        }
      }
      else if (*(longlong *)(param_1 + 0x48) == 0) {
        param_3 = (undefined *)0x10;
        *plVar1 = 0;
        PxTerminateDigitDetection((longlong)plVar11,param_1,0x10);
        pplVar9 = (longlong **)CONCAT71((int7)((ulonglong)param_1 >> 8),(char)*plVar4);
        KeReleaseSpinLock(plVar3);
        goto LAB_140014645;
      }
    }
    pplVar9 = (longlong **)CONCAT71(uVar10,uVar7);
    KeReleaseSpinLock(plVar3);
    iVar8 = -0x3fffffff;
  }
LAB_140014645:
  if (plVar11 != (longlong *)0x0) {
    uVar7 = KeAcquireSpinLockRaiseToDpc(plVar11 + 0x40);
    *(undefined1 *)(plVar11 + 0x41) = uVar7;
    piVar2 = (int *)((longlong)plVar11 + 0x1c);
    *piVar2 = *piVar2 + -1;
    if (*piVar2 == 0) {
      DoDerefVcWork(plVar11,pplVar9,param_3);
    }
    else {
      KeReleaseSpinLock(plVar11 + 0x40,uVar7);
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7b,
             &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,iVar8);
  }
  return iVar8;
}



===== PxTapiGetAddressCaps @ 1400146f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 PxTapiGetAddressCaps(longlong param_1)

{
  uint *_Dst;
  longlong lVar1;
  int *piVar2;
  longlong lVar3;
  void *_Src;
  bool bVar4;
  undefined1 uVar5;
  uint uVar6;
  undefined8 uVar7;
  longlong lVar8;
  uint uVar9;
  uint uVar10;
  undefined1 auStack_478 [32];
  longlong local_448;
  void *local_440;
  undefined1 local_438 [1024];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_478;
  uVar7 = 0;
  local_448 = 0;
  bVar4 = IsTapiDeviceValid(*(int *)(param_1 + 0x24),&local_448);
  lVar8 = local_448;
  if (!bVar4) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,
               &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,*(undefined4 *)(param_1 + 0x24));
    }
    return 0x1002;
  }
  _Dst = (uint *)(param_1 + 0x40);
  if ((ulonglong)*(uint *)(param_1 + 0x28) - 0x10 < (ulonglong)*_Dst) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_LL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,
                &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,*_Dst,
                (char)*(uint *)(param_1 + 0x28));
    }
    lVar8 = local_448;
    if (local_448 != 0) {
      lVar1 = local_448 + 0x78;
      uVar5 = KeAcquireSpinLockRaiseToDpc(lVar1);
      *(undefined1 *)(lVar8 + 0x80) = uVar5;
      piVar2 = (int *)(lVar8 + 0x10);
      *piVar2 = *piVar2 + -1;
      if (*piVar2 == 0) {
        KeReleaseSpinLock();
        FreeTapiLine(lVar8);
      }
      else {
        KeReleaseSpinLock(lVar1,uVar5);
      }
    }
    return 0xc0012019;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,local_448,
              (char)*(undefined4 *)(param_1 + 0x24));
  }
  uVar5 = KeAcquireSpinLockRaiseToDpc(lVar8 + 0x78);
  lVar1 = local_448;
  *(undefined1 *)(lVar8 + 0x80) = uVar5;
  if ((*(uint *)(param_1 + 0x38) < *(uint *)(lVar8 + 0x58)) &&
     (lVar3 = *(longlong *)
               (*(longlong *)(local_448 + 0x70) + (ulonglong)*(uint *)(param_1 + 0x38) * 8),
     lVar8 = local_448, lVar3 != 0)) {
    _Src = *(void **)(lVar3 + 0x28);
    local_448 = CONCAT44(local_448._4_4_,0x400);
    local_440 = _Src;
    memset(local_438,0,0x400);
    lVar8 = *(longlong *)(*(longlong *)(lVar1 + 0x18) + 0x18);
    uVar10 = 0x400;
    if (lVar8 != 0) {
      GetAllDevClasses(lVar8,local_438,(uint *)&local_448);
      uVar10 = (uint)local_448;
    }
    uVar9 = *_Dst;
    uVar6 = uVar9;
    if (*(uint *)((longlong)_Src + 8) <= uVar9) {
      uVar6 = *(uint *)((longlong)_Src + 8);
    }
    memmove(_Dst,_Src,(ulonglong)uVar6);
    *_Dst = uVar9;
    *(uint *)(param_1 + 0x48) = uVar6;
    *(uint *)(param_1 + 0x44) = uVar10 + *(int *)((longlong)local_440 + 8);
    uVar9 = uVar9 - uVar6;
    lVar8 = lVar1;
    if ((uVar9 != 0) && (uVar10 != 0)) {
      if (uVar10 < uVar9) {
        uVar9 = uVar10;
      }
      memmove((void *)((longlong)_Dst + (ulonglong)uVar6),local_438,(ulonglong)uVar9);
      *(uint *)(param_1 + 0x104) = uVar9;
      *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + uVar9;
      *(int *)(param_1 + 0x108) = (int)(void *)((longlong)_Dst + (ulonglong)uVar6) - (int)_Dst;
    }
  }
  else {
    uVar7 = 0xc001200a;
  }
  piVar2 = (int *)(lVar8 + 0x10);
  *piVar2 = *piVar2 + -1;
  if (*piVar2 == 0) {
    KeReleaseSpinLock();
    FreeTapiLine(lVar8);
  }
  else {
    KeReleaseSpinLock(lVar8 + 0x78,*(undefined1 *)(lVar8 + 0x80));
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
            &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
  }
  return uVar7;
}



===== PxTapiGetAddressID @ 1400149f0 =====

undefined8 PxTapiGetAddressID(longlong param_1,undefined8 param_2,undefined *param_3)

{
  longlong lVar1;
  int *piVar2;
  longlong lVar3;
  bool bVar4;
  undefined1 uVar5;
  undefined8 uVar6;
  longlong local_res8;
  
  local_res8 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
            &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
  }
  bVar4 = IsTapiLineValid(*(int *)(param_1 + 0x38),&local_res8);
  lVar3 = local_res8;
  if (bVar4) {
    lVar1 = local_res8 + 0x78;
    uVar5 = KeAcquireSpinLockRaiseToDpc(lVar1);
    *(undefined1 *)(lVar3 + 0x80) = uVar5;
    *(undefined4 *)(param_1 + 0x40) = 0;
    piVar2 = (int *)(lVar3 + 0x10);
    *piVar2 = *piVar2 + -1;
    if (*piVar2 == 0) {
      KeReleaseSpinLock();
      FreeTapiLine(lVar3);
    }
    else {
      KeReleaseSpinLock(lVar1,*(undefined1 *)(lVar3 + 0x80));
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
    uVar6 = 0;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,param_3,
               *(undefined8 *)(param_1 + 0x38));
    }
    uVar6 = 0x1002;
  }
  return uVar6;
}



===== PxTapiGetAddressStatus @ 140014b10 =====

undefined8 PxTapiGetAddressStatus(void)

{
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x41,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
  }
  return 0xc0012016;
}



===== PxTapiGetCallAddressID @ 140014b80 =====

undefined8 PxTapiGetCallAddressID(longlong param_1,undefined8 param_2,undefined *param_3)

{
  int *piVar1;
  uint uVar2;
  longlong *plVar3;
  bool bVar4;
  undefined1 uVar5;
  undefined8 uVar6;
  longlong *local_res8;
  
  local_res8 = (longlong *)0x0;
  bVar4 = IsVcValid(*(ulonglong *)(param_1 + 0x38),(longlong *)&local_res8);
  plVar3 = local_res8;
  if (bVar4) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      param_3 = &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids;
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x43,
               &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,local_res8);
    }
    uVar5 = KeAcquireSpinLockRaiseToDpc(plVar3 + 0x40);
    *(undefined1 *)(plVar3 + 0x41) = uVar5;
    uVar2 = *(uint *)(plVar3[0x21] + 0x20);
    *(uint *)(param_1 + 0x40) = uVar2;
    piVar1 = (int *)((longlong)plVar3 + 0x1c);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      DoDerefVcWork(plVar3,(ulonglong)uVar2,param_3);
    }
    else {
      KeReleaseSpinLock(plVar3 + 0x40,CONCAT31((int3)(uVar2 >> 8),(char)plVar3[0x41]));
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x44,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
    uVar6 = 0;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,param_3,
               *(undefined8 *)(param_1 + 0x38));
    }
    uVar6 = 0xc001200d;
  }
  return uVar6;
}



===== PxTapiGetCallInfo @ 140014cb0 =====

undefined8 PxTapiGetCallInfo(longlong param_1,undefined8 param_2,undefined *param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  longlong *plVar3;
  undefined4 uVar4;
  int iVar5;
  longlong lVar6;
  longlong lVar7;
  longlong *plVar8;
  bool bVar9;
  undefined1 uVar10;
  undefined8 uVar11;
  uint uVar12;
  longlong **_Src;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  longlong *local_res8;
  
  local_res8 = (longlong *)0x0;
  puVar1 = (undefined4 *)(param_1 + 0x40);
  _Src = &local_res8;
  uVar13 = 0;
  bVar9 = IsVcValid(*(ulonglong *)(param_1 + 0x38),(longlong *)_Src);
  plVar8 = local_res8;
  if (bVar9) {
    plVar3 = local_res8 + 0x40;
    uVar10 = KeAcquireSpinLockRaiseToDpc(plVar3);
    *(undefined1 *)(plVar8 + 0x41) = uVar10;
    lVar6 = plVar8[0x26];
    uVar15 = *(int *)(param_1 + 0x28) - 0x168;
    lVar7 = plVar8[0x20];
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      _Src = (longlong **)0x46;
      WPP_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,param_3,plVar8,(char)*puVar1,
                 (char)*(undefined4 *)(lVar6 + 8));
    }
    *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(lVar6 + 8);
    *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(lVar7 + 0x20);
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(lVar6 + 0x14);
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(lVar6 + 0x18);
    *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(lVar6 + 0x1c);
    *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(lVar6 + 0x20);
    *(undefined4 *)(param_1 + 100) = *(undefined4 *)(lVar6 + 0x24);
    *(undefined8 *)(param_1 + 0x68) = 0;
    *(undefined4 *)(param_1 + 0x70) = 0;
    *(undefined8 *)(param_1 + 0x80) = 0;
    *(undefined8 *)(param_1 + 0x88) = 0;
    uVar4 = *(undefined4 *)(lVar6 + 0x54);
    *(undefined4 *)(param_1 + 0xa8) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x94) = uVar4;
    *(undefined4 *)(param_1 + 0x98) = 0;
    *(undefined4 *)(param_1 + 0xa4) = 0;
    uVar12 = *(uint *)(lVar6 + 0x70);
    if (uVar12 == 0) {
      *(undefined8 *)(param_1 + 0xac) = 0x40;
      *(undefined4 *)(param_1 + 0xb4) = 0;
    }
    else {
      uVar14 = uVar12 + *(uint *)(lVar6 + 0x74);
      _Src = (longlong **)(ulonglong)uVar14;
      if (((*(uint *)(lVar6 + 0x74) <= uVar14) && (uVar12 <= uVar15)) &&
         (uVar14 <= *(uint *)(lVar6 + 8))) {
        *(uint *)(param_1 + 0xb0) = uVar12;
        *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(lVar6 + 0x6c);
        *(undefined4 *)(param_1 + 0xb4) = 0x158;
        param_3 = (undefined *)(ulonglong)*(uint *)(lVar6 + 0x70);
        _Src = (longlong **)((ulonglong)*(uint *)(lVar6 + 0x74) + lVar6);
        memmove((void *)(param_1 + 0x198),_Src,(size_t)param_3);
        uVar13 = *(uint *)(lVar6 + 0x70);
        *(uint *)(plVar8 + 0x24) = *(uint *)(plVar8 + 0x24) | 0x8000;
      }
    }
    *(undefined8 *)(param_1 + 0xb8) = 0;
    iVar5 = *(int *)(lVar6 + 0x84);
    if (iVar5 == 0) {
      *(undefined8 *)(param_1 + 0xc0) = 0x40;
      *(undefined4 *)(param_1 + 200) = 0;
    }
    else {
      uVar12 = iVar5 + uVar13;
      _Src = (longlong **)(ulonglong)uVar12;
      if (uVar13 <= uVar12) {
        uVar14 = iVar5 + *(uint *)(lVar6 + 0x88);
        param_3 = (undefined *)(ulonglong)uVar14;
        if (((*(uint *)(lVar6 + 0x88) <= uVar14) && (uVar12 <= uVar15)) &&
           (uVar14 <= *(uint *)(lVar6 + 8))) {
          *(undefined4 *)(param_1 + 0xc0) = *(undefined4 *)(lVar6 + 0x80);
          *(undefined4 *)(param_1 + 0xc4) = *(undefined4 *)(lVar6 + 0x84);
          *(uint *)(param_1 + 200) = uVar13 + 0x158;
          param_3 = (undefined *)(ulonglong)*(uint *)(lVar6 + 0x84);
          _Src = (longlong **)((ulonglong)*(uint *)(lVar6 + 0x88) + lVar6);
          memmove((void *)((ulonglong)(uVar13 + 0x158) + (longlong)puVar1),_Src,(size_t)param_3);
          uVar13 = uVar13 + *(int *)(lVar6 + 0x84);
          *(uint *)(plVar8 + 0x24) = *(uint *)(plVar8 + 0x24) | 0x10000;
        }
      }
    }
    *(undefined8 *)(param_1 + 0xcc) = 0;
    *(undefined4 *)(param_1 + 0x74) = 0xc383;
    uVar12 = *(uint *)(plVar8 + 4);
    *(undefined8 *)(param_1 + 0x94) = 0x800;
    *(undefined8 *)(param_1 + 0xd4) = 0x40;
    *(undefined8 *)(param_1 + 0xdc) = 0;
    *(undefined4 *)(param_1 + 0xe4) = 0;
    *(undefined8 *)(param_1 + 0xe8) = 0x40;
    *(undefined8 *)(param_1 + 0xf0) = 0;
    *(uint *)(param_1 + 0x90) = (-(uint)((uVar12 & 1) != 0) & 3) + 1;
    *(undefined4 *)(param_1 + 0xf8) = 0;
    *(undefined8 *)(param_1 + 0xfc) = 0x40;
    *(undefined8 *)(param_1 + 0x104) = 0;
    *(undefined4 *)(param_1 + 0x10c) = 0;
    *(undefined8 *)(param_1 + 0x130) = 0;
    *(undefined8 *)(param_1 + 0x138) = 0;
    *(undefined8 *)(param_1 + 0x140) = 0;
    *(undefined8 *)(param_1 + 0x148) = 0;
    *(undefined8 *)(param_1 + 0x150) = 0;
    *(undefined8 *)(param_1 + 0x158) = 0;
    *(undefined8 *)(param_1 + 0x160) = 0;
    if (*(int *)(lVar6 + 0x120) != 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        param_3 = &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids;
        WPP_SF_LL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x47,
                  &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,*(int *)(lVar6 + 0x120),
                  (char)*(undefined4 *)(lVar6 + 0x124));
      }
      uVar12 = *(uint *)(lVar6 + 0x120);
      _Src = (longlong **)(ulonglong)uVar12;
      if ((((uVar13 <= uVar12 + uVar13) &&
           (uVar14 = uVar12 + *(uint *)(lVar6 + 0x124), *(uint *)(lVar6 + 0x124) <= uVar14)) &&
          (uVar12 + uVar13 <= uVar15)) && (uVar14 <= *(uint *)(lVar6 + 8))) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x48,
                  &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
        }
        *(undefined4 *)(param_1 + 0x160) = *(undefined4 *)(lVar6 + 0x120);
        *(uint *)(param_1 + 0x164) = uVar13 + 0x158;
        param_3 = (undefined *)(ulonglong)*(uint *)(lVar6 + 0x120);
        _Src = (longlong **)((ulonglong)*(uint *)(lVar6 + 0x124) + lVar6);
        memmove((void *)((ulonglong)(uVar13 + 0x158) + (longlong)puVar1),_Src,(size_t)param_3);
        uVar13 = uVar13 + *(int *)(lVar6 + 0x120);
        *(uint *)(plVar8 + 0x24) = *(uint *)(plVar8 + 0x24) | 2;
      }
    }
    *(uint *)(param_1 + 0x48) = uVar13 + 0x158;
    piVar2 = (int *)((longlong)plVar8 + 0x1c);
    *piVar2 = *piVar2 + -1;
    if (*piVar2 == 0) {
      DoDerefVcWork(plVar8,_Src,param_3);
    }
    else {
      KeReleaseSpinLock(plVar3,(char)plVar8[0x41]);
    }
    uVar11 = 0;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,param_3,
               *(undefined8 *)(param_1 + 0x38));
    }
    uVar11 = 0xc001200d;
  }
  return uVar11;
}



===== PxTapiGetCallStatus @ 1400150a0 =====

undefined8 PxTapiGetCallStatus(longlong param_1,undefined8 param_2,undefined *param_3)

{
  int *piVar1;
  int iVar2;
  longlong *plVar3;
  bool bVar4;
  undefined1 uVar5;
  undefined4 uVar6;
  longlong **pplVar7;
  longlong *local_res8;
  
  local_res8 = (longlong *)0x0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x49,
            &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
  }
  pplVar7 = &local_res8;
  bVar4 = IsVcValid(*(ulonglong *)(param_1 + 0x38),(longlong *)pplVar7);
  plVar3 = local_res8;
  if (!bVar4) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4a,param_3,
               *(undefined8 *)(param_1 + 0x38));
    }
    return 0xc001200d;
  }
  uVar5 = KeAcquireSpinLockRaiseToDpc(local_res8 + 0x40);
  *(undefined1 *)(plVar3 + 0x41) = uVar5;
  *(undefined4 *)(param_1 + 0x48) = 0x24;
  *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)((longlong)plVar3 + 0x124);
  iVar2 = *(int *)((longlong)plVar3 + 0x124);
  if (iVar2 == 1) {
LAB_1400151a5:
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  else if (iVar2 == 2) {
    *(undefined4 *)(param_1 + 0x58) = 4;
  }
  else {
    if (iVar2 == 0x40) {
      uVar6 = 8;
      goto LAB_1400151ab;
    }
    pplVar7 = (longlong **)0x40;
    if (iVar2 != 0x80) {
      if (iVar2 != 0x100) {
        if (iVar2 == 0x4000) {
          uVar6 = 0x20;
          if ((int)plVar3[0x25] != 0x11) {
            uVar6 = 0x40;
          }
          goto LAB_1400151ab;
        }
        goto LAB_1400151a5;
      }
      *(undefined4 *)(param_1 + 0x58) = 0x80;
    }
  }
  uVar6 = 0;
LAB_1400151ab:
  *(undefined4 *)(param_1 + 0x50) = uVar6;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    pplVar7 = (longlong **)0x4b;
    WPP_SF_qLLLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4b,param_3,plVar3,(char)plVar3[4],
                 (char)*(undefined4 *)(param_1 + 0x4c),(char)*(undefined4 *)(param_1 + 0x50),
                 (char)*(undefined4 *)(param_1 + 0x58));
  }
  if (plVar3 != (longlong *)0x0) {
    piVar1 = (int *)((longlong)plVar3 + 0x1c);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      DoDerefVcWork(plVar3,pplVar7,param_3);
    }
    else {
      KeReleaseSpinLock(plVar3 + 0x40,(char)plVar3[0x41]);
    }
  }
  return 0;
}



===== PxTapiGetDevCaps @ 140015240 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 PxTapiGetDevCaps(longlong param_1)

{
  uint *_Dst;
  longlong lVar1;
  int *piVar2;
  longlong lVar3;
  bool bVar4;
  undefined1 uVar5;
  ulonglong uVar6;
  wchar_t *pwVar7;
  undefined8 uVar8;
  int iVar9;
  uint uVar10;
  void *pvVar11;
  uint uVar12;
  longlong lVar13;
  ulonglong uVar14;
  uint *puVar15;
  uint uVar16;
  uint uVar17;
  undefined1 auStackY_698 [32];
  uint local_668;
  uint local_664;
  longlong local_660;
  undefined8 local_658;
  ulonglong local_650;
  longlong local_648;
  wchar_t local_638 [4];
  undefined4 uStack_630;
  undefined2 uStack_62c;
  undefined1 auStack_62a [242];
  wchar_t local_538 [128];
  wchar_t local_438 [512];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_698;
  local_660 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
            &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
  }
  bVar4 = IsTapiDeviceValid(*(int *)(param_1 + 0x34),&local_660);
  lVar3 = local_660;
  if (!bVar4) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
               &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,*(undefined4 *)(param_1 + 0x34));
    }
    return 0x1002;
  }
  _Dst = (uint *)(param_1 + 0x3c);
  if ((ulonglong)*(uint *)(param_1 + 0x28) - 0xc < (ulonglong)*_Dst) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_LL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,*_Dst,
                (char)*(uint *)(param_1 + 0x28));
    }
    lVar3 = local_660;
    if (local_660 != 0) {
      lVar1 = local_660 + 0x78;
      uVar5 = KeAcquireSpinLockRaiseToDpc(lVar1);
      *(undefined1 *)(lVar3 + 0x80) = uVar5;
      piVar2 = (int *)(lVar3 + 0x10);
      *piVar2 = *piVar2 + -1;
      if (*piVar2 == 0) {
        KeReleaseSpinLock();
        FreeTapiLine(lVar3);
      }
      else {
        KeReleaseSpinLock(lVar1,uVar5);
      }
    }
    return 0xc0012019;
  }
  uVar5 = KeAcquireSpinLockRaiseToDpc(local_660 + 0x78);
  local_658 = (ulonglong)local_658._4_4_ << 0x20;
  *(undefined1 *)(lVar3 + 0x80) = uVar5;
  memset(local_538,0,0x100);
  lVar1 = *(longlong *)(lVar3 + 0x48);
  local_664 = 0;
  iVar9 = *(int *)(lVar1 + 8);
  lVar13 = *(longlong *)(*(longlong *)(lVar3 + 0x18) + 0x18);
  if (*(int *)(lVar1 + 0xc) == 0) {
    iVar9 = iVar9 + 0x10;
    builtin_wcsncpy(local_538,L"NDPROXY",7);
    local_664 = 0x10;
  }
  local_648 = lVar13;
  if ((((*(int *)(lVar1 + 0x20) == 0) && (lVar13 != 0)) && (*(uint *)(lVar13 + 0xc0) != 0)) &&
     ((ulonglong)*(uint *)(lVar13 + 0xc0) + 0xe < 0x101)) {
    memset(local_638,0,0x100);
    pvVar11 = (void *)(lVar13 + 0xc4);
    memmove(local_638,pvVar11,(ulonglong)*(uint *)(lVar13 + 0xc0));
    uVar6 = (ulonglong)*(uint *)(lVar13 + 0xc0);
    builtin_wcsncpy((wchar_t *)((longlong)local_638 + uVar6),L" - L",4);
    *(undefined4 *)((longlong)local_638 + uVar6 + 8) = 0x6e0069;
    *(undefined2 *)(auStack_62a + (uVar6 - 2)) = 0x65;
    IntegerToWChar(*(uint *)(lVar3 + 0x34),pvVar11,auStack_62a + uVar6);
    uVar16 = ((int)(auStack_62a + uVar6) - (int)local_638) + 10;
    local_658 = (ulonglong)uVar16;
    iVar9 = iVar9 + uVar16;
  }
  puVar15 = (uint *)0x400;
  local_668 = 0x400;
  pwVar7 = (wchar_t *)0x0;
  memset(local_438,0,0x400);
  uVar16 = 0x400;
  if (lVar13 != 0) {
    puVar15 = &local_668;
    pwVar7 = local_438;
    GetAllDevClasses(lVar13,pwVar7,puVar15);
    uVar16 = local_668;
  }
  local_668 = iVar9 + uVar16;
  uVar12 = *(uint *)(*(longlong *)(lVar3 + 0x48) + 8);
  uVar17 = *_Dst;
  local_660 = CONCAT44(local_660._4_4_,uVar17);
  uVar10 = uVar17;
  if (uVar12 <= uVar17) {
    uVar10 = uVar12;
  }
  uVar17 = uVar17 - uVar10;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pwVar7,puVar15,lVar3,
               (char)*(undefined4 *)(param_1 + 0x34),(char)uVar10);
  }
  pwVar7 = *(wchar_t **)(lVar3 + 0x48);
  local_650 = (ulonglong)uVar10;
  uVar6 = (ulonglong)uVar10;
  memmove(_Dst,pwVar7,uVar6);
  *(uint *)(param_1 + 0x40) = local_668;
  *_Dst = (uint)local_660;
  *(uint *)(param_1 + 0x44) = uVar10;
  if (0 < (int)uVar17) {
    iVar9 = (int)_Dst;
    if (*(int *)(param_1 + 0x48) == 0) {
      pwVar7 = local_538;
      pvVar11 = (void *)(local_650 + (longlong)_Dst);
      uVar12 = uVar17;
      if ((int)local_664 < (int)uVar17) {
        uVar12 = local_664;
      }
      uVar6 = (ulonglong)uVar12;
      memmove(pvVar11,pwVar7,uVar6);
      *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + uVar12;
      *(int *)(param_1 + 0x4c) = (int)pvVar11 - iVar9;
      uVar17 = uVar17 - uVar12;
      uVar10 = *(uint *)(param_1 + 0x44);
      *(uint *)(param_1 + 0x48) = uVar12;
      lVar13 = local_648;
    }
    if (0 < (int)uVar17) {
      if (((*(int *)(param_1 + 0x5c) == 0) && (lVar13 != 0)) && (*(int *)(lVar13 + 0xc0) != 0)) {
        pwVar7 = local_638;
        uVar14 = (ulonglong)uVar10;
        uVar12 = (uint)local_658;
        if ((int)uVar17 <= (int)(uint)local_658) {
          uVar12 = uVar17;
        }
        uVar6 = (ulonglong)uVar12;
        memmove((void *)(uVar14 + (longlong)_Dst),pwVar7,uVar6);
        *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + uVar12;
        uVar10 = *(uint *)(param_1 + 0x44);
        uVar17 = uVar17 - uVar12;
        *(uint *)(param_1 + 0x5c) = uVar12;
        *(int *)(param_1 + 0x60) = (int)(void *)(uVar14 + (longlong)_Dst) - iVar9;
        if ((int)uVar17 < 1) goto LAB_140015634;
      }
      if (uVar16 != 0) {
        pwVar7 = local_438;
        if ((int)uVar16 < (int)uVar17) {
          uVar17 = uVar16;
        }
        uVar6 = (ulonglong)uVar17;
        memmove((void *)((ulonglong)uVar10 + (longlong)_Dst),pwVar7,uVar6);
        *(uint *)(param_1 + 0x130) = uVar17;
        *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + uVar17;
        *(int *)(param_1 + 0x134) = (int)(void *)((ulonglong)uVar10 + (longlong)_Dst) - iVar9;
      }
    }
  }
LAB_140015634:
  piVar2 = (int *)(lVar3 + 0x10);
  *piVar2 = *piVar2 + -1;
  uVar8 = CONCAT71((int7)((ulonglong)pwVar7 >> 8),*(undefined1 *)(lVar3 + 0x80));
  if (*piVar2 == 0) {
    KeReleaseSpinLock();
    FreeTapiLine(lVar3);
  }
  else {
    KeReleaseSpinLock(lVar3 + 0x78);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,uVar6,
               *(undefined4 *)(param_1 + 0x44),(char)*(undefined4 *)(param_1 + 0x40),(char)*_Dst);
  }
  return 0;
}



===== PxTapiGetDevConfig @ 1400156e0 =====

undefined8 PxTapiGetDevConfig(void)

{
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4c,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4d,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
  }
  return 0xc0012016;
}



===== PxTapiGetExtensionID @ 140015750 =====

undefined8 PxTapiGetExtensionID(void)

{
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4e,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4f,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
  }
  return 0xc0012016;
}



===== PxTapiGetLineDevStatus @ 1400157c0 =====

undefined8 PxTapiGetLineDevStatus(longlong param_1,undefined8 param_2,undefined *param_3)

{
  longlong lVar1;
  int *piVar2;
  undefined4 uVar3;
  longlong lVar4;
  bool bVar5;
  undefined1 uVar6;
  undefined8 uVar7;
  longlong local_res8;
  
  local_res8 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x50,
            &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
  }
  bVar5 = IsTapiLineValid(*(int *)(param_1 + 0x38),&local_res8);
  lVar4 = local_res8;
  if (bVar5) {
    lVar1 = local_res8 + 0x78;
    uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
    *(undefined1 *)(lVar4 + 0x80) = uVar6;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x52,param_3,lVar4,
                (char)*(undefined8 *)(param_1 + 0x38));
    }
    *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(*(longlong *)(lVar4 + 0x50) + 0x10);
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(*(longlong *)(lVar4 + 0x50) + 0x14);
    uVar3 = *(undefined4 *)(*(longlong *)(lVar4 + 0x50) + 0x38);
    *(undefined4 *)(param_1 + 0x78) = uVar3;
    piVar2 = (int *)(lVar4 + 0x10);
    *piVar2 = *piVar2 + -1;
    if (*piVar2 == 0) {
      KeReleaseSpinLock();
      FreeTapiLine(lVar4);
    }
    else {
      KeReleaseSpinLock(lVar1,CONCAT31((int3)((uint)uVar3 >> 8),*(undefined1 *)(lVar4 + 0x80)));
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x53,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
    uVar7 = 0;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x51,param_3,
               *(undefined8 *)(param_1 + 0x38));
    }
    uVar7 = 0x1002;
  }
  return uVar7;
}



===== PxTapiLineGetID @ 140015930 =====

int PxTapiLineGetID(longlong param_1)

{
  int *piVar1;
  longlong *plVar2;
  longlong **pplVar3;
  uint uVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong lVar7;
  longlong lVar8;
  bool bVar9;
  undefined1 uVar10;
  char cVar11;
  int iVar12;
  undefined8 uVar13;
  longlong **pplVar14;
  undefined **ppuVar15;
  uint uVar16;
  longlong *plVar17;
  longlong local_res8;
  longlong **local_res10;
  longlong *local_res18;
  longlong local_res20;
  longlong local_48 [2];
  
  uVar4 = *(uint *)(param_1 + 0x58);
  pplVar14 = (longlong **)(param_1 + 0x5c);
  uVar16 = *(int *)(param_1 + 0x54) + uVar4;
  plVar17 = (longlong *)(ulonglong)uVar16;
  local_res18 = (longlong *)0x0;
  local_res8 = 0;
  local_res20 = 0;
  local_48[0] = 0;
  if (((uVar16 < uVar4) || (*(uint *)(param_1 + 0x28) < uVar16)) ||
     (*(uint *)(param_1 + 0x28) < *(uint *)pplVar14)) {
    iVar12 = -0x3ffedfe7;
  }
  else {
    pplVar3 = (longlong **)(param_1 + 0x30 + (ulonglong)uVar4);
    local_res10 = pplVar14;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,plVar17,
               *(undefined8 *)(param_1 + 0x48));
    }
    if (*(int *)(param_1 + 0x50) == 4) {
      ppuVar15 = (undefined **)&local_res18;
      bVar9 = IsVcValid(*(ulonglong *)(param_1 + 0x48),(longlong *)ppuVar15);
      plVar6 = local_res18;
      if (bVar9) {
        plVar2 = local_res18 + 0x40;
        uVar10 = KeAcquireSpinLockRaiseToDpc(plVar2);
        *(undefined1 *)(plVar6 + 0x41) = uVar10;
        if (plVar6[8] == 0) {
          if ((int)plVar6[2] == 4) {
            lVar5 = plVar6[0xb];
            plVar17 = &local_res20;
            ppuVar15 = (undefined **)pplVar3;
            cVar11 = PxAfAndSapFromDevClass(lVar5,(wchar_t *)pplVar3,plVar17,local_48);
            lVar8 = local_48[0];
            lVar7 = local_res20;
            if (cVar11 == '\0') {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (2 < (byte)WPP_GLOBAL_Control[0x29])) {
                plVar17 = (longlong *)&WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids;
                ppuVar15 = (undefined **)0x24;
                WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
                        &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
              }
              iVar12 = -0x3fffffff;
            }
            else {
              *(undefined4 *)(plVar6 + 3) = 1;
              plVar6[10] = local_res20;
              plVar6[9] = local_48[0];
              local_res8 = plVar6[5];
              KeReleaseSpinLock(plVar2,(char)plVar6[0x41]);
              plVar17 = (longlong *)plVar6[0x23];
              iVar12 = NdisCoCreateVc(*(undefined8 *)(lVar5 + 0x48),*(undefined8 *)(lVar7 + 0x18),
                                      plVar17,&local_res8);
              if (iVar12 == 0) {
                uVar10 = KeAcquireSpinLockRaiseToDpc(plVar2);
                *(undefined1 *)(plVar6 + 0x41) = uVar10;
                plVar6[8] = local_res8;
                *(int *)((longlong)plVar6 + 0x1c) = *(int *)((longlong)plVar6 + 0x1c) + 1;
                KeReleaseSpinLock(plVar2,(char)plVar6[0x41]);
                plVar17 = (longlong *)plVar6[0x27];
                ppuVar15 = (undefined **)plVar6[8];
                iVar12 = NdisCmDispatchIncomingCall(*(undefined8 *)(lVar8 + 0x28));
                if (iVar12 == 0x103) {
                  ppuVar15 = (undefined **)0x0;
                  NdisWaitEvent(plVar6 + 0x38);
                  iVar12 = (int)plVar6[0x3b];
                }
                if (iVar12 == 0) {
                  NdisCmDispatchCallConnected(plVar6[8]);
                  uVar10 = KeAcquireSpinLockRaiseToDpc(plVar2);
                  *(undefined1 *)(plVar6 + 0x41) = uVar10;
                  if ((int)plVar6[3] == 1) {
                    *(undefined4 *)(plVar6 + 3) = 3;
                  }
                }
                else {
                  ppuVar15 = &WPP_GLOBAL_Control;
                  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     (2 < (byte)WPP_GLOBAL_Control[0x29])) {
                    plVar17 = (longlong *)&WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids;
                    ppuVar15 = (undefined **)0x26;
                    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
                              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,plVar6,(char)iVar12);
                  }
                  uVar10 = KeAcquireSpinLockRaiseToDpc(lVar7 + 0x58);
                  *(undefined1 *)(lVar7 + 0x60) = uVar10;
                  piVar1 = (int *)(lVar7 + 0x14);
                  *piVar1 = *piVar1 + -1;
                  if (*piVar1 == 0) {
                    DoDerefCmAfWork(lVar7);
                  }
                  else {
                    ppuVar15 = (undefined **)CONCAT71((int7)((ulonglong)ppuVar15 >> 8),uVar10);
                    KeReleaseSpinLock(lVar7 + 0x58);
                  }
                  uVar10 = KeAcquireSpinLockRaiseToDpc(plVar2);
                  *(undefined1 *)(plVar6 + 0x41) = uVar10;
                  *(undefined4 *)(plVar6 + 3) = 0;
                  *(int *)((longlong)plVar6 + 0x1c) = *(int *)((longlong)plVar6 + 0x1c) + -1;
                }
              }
              else {
                ppuVar15 = &WPP_GLOBAL_Control;
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (2 < (byte)WPP_GLOBAL_Control[0x29])) {
                  WPP_SF_qSD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),&WPP_GLOBAL_Control,plVar17,
                             lVar7,(wchar_t *)pplVar3,(char)iVar12);
                }
                iVar12 = -0x3fffffff;
                uVar10 = KeAcquireSpinLockRaiseToDpc(lVar7 + 0x58);
                *(undefined1 *)(lVar7 + 0x60) = uVar10;
                piVar1 = (int *)(lVar7 + 0x14);
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                  DoDerefCmAfWork(lVar7);
                }
                else {
                  ppuVar15 = (undefined **)CONCAT71((int7)((ulonglong)ppuVar15 >> 8),uVar10);
                  KeReleaseSpinLock(lVar7 + 0x58);
                }
                uVar10 = KeAcquireSpinLockRaiseToDpc(plVar2);
                *(undefined1 *)(plVar6 + 0x41) = uVar10;
                *(undefined4 *)(plVar6 + 3) = 0;
              }
              pplVar14 = local_res10;
            }
          }
          else {
            iVar12 = -0x3ffedff1;
          }
        }
        else {
          iVar12 = 0;
        }
        if ((int)plVar6[2] == 4) {
          if (iVar12 == 0) {
            iVar12 = NdisCoGetTapiCallId(plVar6[8]);
            ppuVar15 = (undefined **)pplVar14;
          }
        }
        else {
          uVar13 = PxCloseCallWithCl((longlong)plVar6,ppuVar15,plVar17);
          if (((int)uVar13 != 0x103) && ((*(uint *)(plVar6 + 4) & 8) != 0)) {
            PxCloseCallWithCm((longlong)plVar6,ppuVar15,plVar17);
          }
          iVar12 = -0x3fffffff;
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          plVar17 = (longlong *)&WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids;
          ppuVar15 = (undefined **)0x27;
          WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
                    &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,plVar6,(char)iVar12);
        }
        piVar1 = (int *)((longlong)plVar6 + 0x1c);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          DoDerefVcWork(plVar6,ppuVar15,plVar17);
        }
        else {
          KeReleaseSpinLock(plVar2,(char)plVar6[0x41]);
        }
      }
      else {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (2 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,plVar17,
                   *(undefined8 *)(param_1 + 0x48));
        }
        iVar12 = -0x3ffedff3;
      }
    }
    else {
      iVar12 = -0x3fffffff;
    }
  }
  return iVar12;
}



===== PxTapiMakeCall @ 140015d70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 PxTapiMakeCall(longlong param_1,undefined8 param_2,undefined *param_3)

{
  int *piVar1;
  longlong *plVar2;
  longlong lVar3;
  short *psVar4;
  bool bVar5;
  undefined1 uVar6;
  int iVar7;
  uint uVar8;
  short *psVar9;
  undefined8 uVar10;
  longlong lVar11;
  ulonglong uVar12;
  undefined2 uVar13;
  longlong *plVar14;
  undefined4 uVar15;
  longlong lVar16;
  longlong lVar17;
  undefined *puVar18;
  longlong *plVar19;
  undefined4 local_res8;
  undefined1 auStackY_c8 [32];
  longlong local_88;
  longlong local_80;
  longlong local_78;
  longlong local_70;
  undefined8 local_68;
  longlong local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  ulonglong local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_c8;
  uVar15 = 0;
  local_88 = 0;
  local_80 = 0;
  local_70 = param_1;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
  }
  if (*(uint *)(param_1 + 0x54) < 0xe0) {
    return local_res8;
  }
  if (*(uint *)(param_1 + 0x28) <= *(uint *)(param_1 + 0x54)) {
    return local_res8;
  }
  plVar14 = &local_88;
  bVar5 = IsTapiLineValid(*(int *)(param_1 + 0x38),plVar14);
  lVar16 = local_88;
  if (!bVar5) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return local_res8;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 3) {
      return local_res8;
    }
    WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,param_3,*(undefined8 *)(param_1 + 0x38))
    ;
    return local_res8;
  }
  lVar11 = local_88 + 0x78;
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar11);
  *(undefined1 *)(lVar16 + 0x80) = uVar6;
  if ((*(uint *)(*(longlong *)(lVar16 + 0x50) + 0x38) & 4) == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
    KeReleaseSpinLock(lVar11,*(undefined1 *)(lVar16 + 0x80));
    uVar15 = 0x1003;
    goto LAB_140015f64;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    plVar14 = (longlong *)0xd;
    WPP_SF_qP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,&WPP_GLOBAL_Control,lVar16,
              (char)*(undefined8 *)(param_1 + 0x38));
  }
  if (*(int *)(param_1 + 0x74) == 1) {
    plVar19 = (longlong *)0x0;
    if (*(uint *)(param_1 + 0x78) < *(uint *)(lVar16 + 0x58)) {
      plVar19 = *(longlong **)
                 (*(longlong *)(local_88 + 0x70) + (ulonglong)*(uint *)(param_1 + 0x78) * 8);
      lVar16 = local_88;
    }
    lVar17 = lVar16;
    if (plVar19 != (longlong *)0x0) {
LAB_140015fd8:
      uVar8 = *(uint *)(param_1 + 0x54);
      lVar11 = *(longlong *)(lVar17 + 0x38);
      local_78 = *(longlong *)(*(longlong *)(lVar17 + 0x18) + 0x18);
      psVar4 = (short *)((ulonglong)uVar8 + param_1 + 0x30);
      lVar16 = lVar17;
      if (*(int *)(local_78 + 0xac) == 0xc) {
        if (psVar4 != (short *)0x0) {
          uVar12 = (ulonglong)(*(int *)(param_1 + 0x28) - uVar8);
          if ((uVar12 < 0x80000000) && (psVar9 = psVar4, uVar12 != 0)) {
            do {
              if ((char)*psVar9 == '\0') break;
              psVar9 = (short *)((longlong)psVar9 + 1);
              uVar12 = uVar12 - 1;
            } while (uVar12 != 0);
            if (uVar12 != 0) goto LAB_14001604a;
          }
LAB_14001602a:
          KeReleaseSpinLock(lVar17 + 0x78,*(undefined1 *)(lVar17 + 0x80));
          uVar15 = 0xc0012019;
          goto LAB_140015f64;
        }
LAB_14001604a:
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_qs(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),plVar14,&WPP_GLOBAL_Control,psVar4,
                    (char *)psVar4);
        }
      }
      else {
        if (psVar4 != (short *)0x0) {
          psVar9 = psVar4;
          for (uVar12 = (ulonglong)(*(int *)(param_1 + 0x28) - uVar8 >> 1); uVar12 != 0;
              uVar12 = uVar12 - 1) {
            if (*psVar9 == 0) goto LAB_140016093;
            psVar9 = psVar9 + 1;
          }
          goto LAB_14001602a;
        }
LAB_140016093:
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_qS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),plVar14,&WPP_GLOBAL_Control,psVar4,
                    psVar4);
        }
      }
      KeReleaseSpinLock(lVar17 + 0x78,*(undefined1 *)(lVar17 + 0x80));
      lVar3 = lVar11 + 0xb8;
      uVar6 = KeAcquireSpinLockRaiseToDpc(lVar3);
      *(undefined1 *)(lVar11 + 0xc0) = uVar6;
      plVar14 = PxAllocateVc(lVar11);
      if (plVar14 == (longlong *)0x0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (2 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                  &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
        }
        KeReleaseSpinLock(lVar3,*(undefined1 *)(lVar11 + 0xc0));
      }
      else {
        KeReleaseSpinLock(lVar3);
        uVar10 = AllocateTapiCallInfo((longlong)plVar14,(void *)0x0);
        lVar16 = local_88;
        if ((int)uVar10 == 0) {
          plVar14[0x20] = lVar17;
          plVar14[0x21] = (longlong)plVar19;
          LOCK();
          *(int *)((longlong)plVar19 + 0x24) = *(int *)((longlong)plVar19 + 0x24) + 1;
          UNLOCK();
          LOCK();
          piVar1 = (int *)(*(longlong *)(local_88 + 0x50) + 0x14);
          *piVar1 = *piVar1 + 1;
          UNLOCK();
          plVar14[0x22] = *(longlong *)(param_1 + 0x40);
          *(undefined4 *)(plVar14[0x26] + 0x10) = *(undefined4 *)(local_88 + 0x34);
          *(int *)(plVar14[0x26] + 0x14) = (int)plVar19[4];
          *(undefined4 *)(plVar14[0x26] + 0x50) = 1;
          *(undefined4 *)(plVar14[0x26] + 0x18) = *(undefined4 *)(param_1 + 0x60);
          *(undefined4 *)(plVar14[0x26] + 0x20) = *(undefined4 *)(param_1 + 0x6c);
          if (*(int *)(param_1 + 0x68) == 0) {
            *(undefined4 *)(plVar14[0x26] + 0x1c) =
                 *(undefined4 *)(*(longlong *)(local_88 + 0x48) + 0x38);
          }
          else {
            *(int *)(plVar14[0x26] + 0x1c) = *(int *)(param_1 + 0x68);
          }
          bVar5 = InsertVcInTable(plVar14);
          if (bVar5) {
            plVar2 = plVar14 + 5;
            *(longlong *)(param_1 + 0x48) = plVar14[0x23];
            lVar17 = plVar14[0x23];
            uVar10 = *(undefined8 *)(lVar11 + 0x18);
            iVar7 = NdisCoCreateVc(*(undefined8 *)(local_78 + 0x20),uVar10,lVar17,plVar2);
            if (iVar7 == 0) {
              puVar18 = (undefined *)(ulonglong)*(uint *)(plVar19 + 4);
              uVar12 = (ulonglong)*(uint *)(lVar16 + 0x34);
              iVar7 = (**(code **)(lVar11 + 0x70))(plVar14,uVar12,puVar18,1);
              if (iVar7 == 0) {
                plVar19 = plVar14 + 0x40;
                uVar6 = KeAcquireSpinLockRaiseToDpc(plVar19);
                *(undefined1 *)(plVar14 + 0x41) = uVar6;
                InsertVcInClAfList((longlong)plVar14);
                *(uint *)(plVar14 + 4) = *(uint *)(plVar14 + 4) | 1;
                *(int *)((longlong)plVar14 + 0x1c) = *(int *)((longlong)plVar14 + 0x1c) + 1;
                plVar14[0x27] = local_80;
                *(int *)((longlong)plVar14 + 0x14) = (int)plVar14[2];
                *(undefined4 *)(plVar14 + 2) = 1;
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (4 < (byte)WPP_GLOBAL_Control[0x29])) {
                  WPP_SF_qDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,plVar14,0,0,
                              (char)*(undefined4 *)(plVar14[0x26] + 0x20));
                }
                local_58 = 2;
                local_50 = 0x200;
                local_48 = 0;
                local_68 = *(undefined8 *)(plVar14[0x20] + 0x28);
                local_60 = plVar14[0x22];
                uVar8 = *(uint *)(plVar14[0x26] + 0x20);
                local_40 = (ulonglong)uVar8;
                *(undefined8 *)((longlong)plVar14 + 0x124) = 0x200;
                KeReleaseSpinLock(plVar19,CONCAT31((int3)(uVar8 >> 8),(char)plVar14[0x41]));
                PxIndicateStatus(&local_68);
                uVar6 = KeAcquireSpinLockRaiseToDpc(plVar19);
                *(undefined1 *)(plVar14 + 0x41) = uVar6;
                KeReleaseSpinLock(plVar19,uVar6);
                uVar8 = NdisClMakeCall(*plVar2,plVar14[0x27],0,0);
                if (uVar8 != 0x103) {
                  PxClMakeCallComplete(uVar8,plVar14[0x23],(undefined *)0x0);
                }
              }
              else {
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (2 < (byte)WPP_GLOBAL_Control[0x29])) {
                  puVar18 = &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids;
                  uVar12 = 0x13;
                  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                           &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,iVar7);
                }
                NdisCoDeleteVc(*plVar2);
                RemoveVcFromTable(plVar14,uVar12,puVar18);
                PxFreeVc((longlong)plVar14);
                uVar15 = 0xc001200e;
              }
            }
            else {
              RemoveVcFromTable(plVar14,uVar10,lVar17);
              PxFreeVc((longlong)plVar14);
              uVar15 = 0xc0012002;
            }
            goto LAB_140015f64;
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (2 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar13 = 0x12;
            goto LAB_140016184;
          }
        }
        else {
          lVar16 = lVar17;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (2 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar13 = 0x11;
LAB_140016184:
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar13,
                    &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
          }
        }
        PxFreeVc((longlong)plVar14);
      }
      uVar15 = 0xc0012018;
      goto LAB_140015f64;
    }
    lVar11 = lVar16 + 0x78;
  }
  else {
    plVar14 = (longlong *)(lVar16 + 0x60);
    for (plVar19 = (longlong *)*plVar14; plVar19 != plVar14; plVar19 = (longlong *)*plVar19) {
      if (*(uint *)((longlong)plVar19 + 0x24) < *(uint *)(plVar19[5] + 0x54)) {
        lVar17 = lVar16;
        if (plVar19 != (longlong *)0x0) goto LAB_140015fd8;
        break;
      }
    }
  }
  uVar15 = 0x1002;
  KeReleaseSpinLock(lVar11,*(undefined1 *)(lVar16 + 0x80));
LAB_140015f64:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
             &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,uVar15);
  }
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar16 + 0x78);
  *(undefined1 *)(lVar16 + 0x80) = uVar6;
  piVar1 = (int *)(lVar16 + 0x10);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    KeReleaseSpinLock();
    FreeTapiLine(lVar16);
  }
  else {
    KeReleaseSpinLock(lVar16 + 0x78,uVar6);
  }
  return local_res8;
}



===== PxTapiMonitorDigits @ 1400164f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PxTapiMonitorDigits(longlong param_1,undefined8 param_2,undefined *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  bool bVar3;
  undefined1 uVar4;
  uint uVar5;
  longlong **pplVar6;
  undefined7 uVar7;
  ulonglong uVar8;
  int *piVar9;
  undefined1 auStack_188 [32];
  undefined4 *local_168;
  longlong *local_158 [2];
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_128;
  int *local_120;
  undefined4 local_118;
  undefined1 local_50 [24];
  uint local_38;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_188;
  local_158[0] = (longlong *)0x0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7c,
            &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
  }
  pplVar6 = local_158;
  bVar3 = IsVcValid(*(ulonglong *)(param_1 + 0x30),(longlong *)pplVar6);
  plVar2 = local_158[0];
  if (!bVar3) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      pplVar6 = (longlong **)0x7d;
      param_3 = &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7d,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
    uVar8 = 0x1002;
    goto LAB_140016777;
  }
  plVar1 = local_158[0] + 0x40;
  uVar4 = KeAcquireSpinLockRaiseToDpc(plVar1);
  *(undefined1 *)(plVar2 + 0x41) = uVar4;
  uVar7 = (undefined7)((ulonglong)pplVar6 >> 8);
  if (plVar2[0xe] == 0) {
    piVar9 = (int *)(param_1 + 0x38);
    if ((int)plVar2[0x1f] == 0) {
      *(int *)(plVar2 + 0x1f) = *piVar9;
      pplVar6 = (longlong **)CONCAT71(uVar7,(char)plVar2[0x41]);
      KeReleaseSpinLock(plVar1);
      if (*piVar9 != 0) {
        memset(&local_148,0,0x118);
        local_140 = 0;
        local_13c = 0;
        local_148 = 0xf00196;
        NdisInitializeEvent(local_50);
        local_144 = 1;
        local_168 = &local_148;
        local_128 = 0xfe001008;
        local_118 = 4;
        param_3 = (undefined *)plVar2[5];
        pplVar6 = *(longlong ***)(plVar2[7] + 0x18);
        local_120 = piVar9;
        uVar5 = NdisCoOidRequest(*(undefined8 *)(plVar2[0xb] + 0x20),pplVar6,param_3,0);
        if (uVar5 == 0x103) {
          pplVar6 = (longlong **)0x0;
          NdisWaitEvent(local_50);
          uVar5 = local_38;
        }
        uVar8 = (ulonglong)uVar5;
        if (uVar5 == 0) goto LAB_140016777;
        uVar4 = KeAcquireSpinLockRaiseToDpc(plVar1);
        *(undefined1 *)(plVar2 + 0x41) = uVar4;
        pplVar6 = (longlong **)CONCAT71((int7)((ulonglong)pplVar6 >> 8),uVar4);
        *(undefined4 *)(plVar2 + 0x1f) = 0;
        KeReleaseSpinLock(plVar1);
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 3)) goto LAB_140016777;
        pplVar6 = (longlong **)0x7f;
        goto LAB_14001676b;
      }
    }
    else {
      pplVar6 = (longlong **)CONCAT71(uVar7,uVar4);
      KeReleaseSpinLock();
      if (*piVar9 == 0) {
        uVar8 = PxStopDigitReporting((longlong)plVar2);
        uVar5 = (uint)uVar8;
        uVar8 = uVar8 & 0xffffffff;
        if (uVar5 == 0) {
          uVar4 = KeAcquireSpinLockRaiseToDpc(plVar1);
          *(undefined1 *)(plVar2 + 0x41) = uVar4;
          pplVar6 = (longlong **)CONCAT71((int7)((ulonglong)pplVar6 >> 8),uVar4);
          *(undefined4 *)(plVar2 + 0x1f) = 0;
          KeReleaseSpinLock(plVar1);
          goto LAB_140016777;
        }
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 3)) goto LAB_140016777;
        pplVar6 = (longlong **)0x7e;
LAB_14001676b:
        param_3 = &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(short)pplVar6,
                 &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,uVar5);
        goto LAB_140016777;
      }
    }
  }
  else {
    pplVar6 = (longlong **)CONCAT71(uVar7,uVar4);
    KeReleaseSpinLock();
  }
  uVar8 = 0xc0000001;
LAB_140016777:
  if (plVar2 != (longlong *)0x0) {
    uVar4 = KeAcquireSpinLockRaiseToDpc(plVar2 + 0x40);
    *(undefined1 *)(plVar2 + 0x41) = uVar4;
    piVar9 = (int *)((longlong)plVar2 + 0x1c);
    *piVar9 = *piVar9 + -1;
    if (*piVar9 == 0) {
      DoDerefVcWork(plVar2,pplVar6,param_3);
    }
    else {
      KeReleaseSpinLock(plVar2 + 0x40,uVar4);
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x80,
             &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,(int)uVar8);
  }
  return uVar8;
}



===== PxTapiNegotiateExtVersion @ 140016820 =====

undefined8 PxTapiNegotiateExtVersion(longlong param_1)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x54,
            &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
  }
  *(undefined4 *)(param_1 + 0x40) = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x55,
            &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
  }
  return 0xc0012016;
}



===== PxTapiOpen @ 1400168a0 =====

undefined8 PxTapiOpen(longlong param_1)

{
  longlong lVar1;
  int *piVar2;
  longlong lVar3;
  longlong lVar4;
  bool bVar5;
  undefined1 uVar6;
  undefined8 uVar7;
  int iVar8;
  longlong local_res8;
  
  local_res8 = 0;
  iVar8 = 10;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6c,
            &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
  }
  bVar5 = IsTapiDeviceValid(*(int *)(param_1 + 0x34),&local_res8);
  if (bVar5) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6e,
               &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,*(undefined4 *)(param_1 + 0x34));
    }
    lVar4 = local_res8;
    lVar1 = local_res8 + 0x78;
    while( true ) {
      uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
      *(undefined1 *)(lVar4 + 0x80) = uVar6;
      if ((*(uint *)(*(longlong *)(lVar4 + 0x50) + 0x38) & 4) != 0) break;
      if (iVar8 == 0) {
        piVar2 = (int *)(lVar4 + 0x10);
        *piVar2 = *piVar2 + -1;
        if (*piVar2 == 0) {
          KeReleaseSpinLock();
          FreeTapiLine(lVar4);
        }
        else {
          KeReleaseSpinLock(lVar1,*(undefined1 *)(lVar4 + 0x80));
        }
        return 0x1003;
      }
      KeReleaseSpinLock(lVar1,uVar6);
      NdisMSleep(500000);
      iVar8 = iVar8 + -1;
    }
    *(undefined8 *)(lVar4 + 0x28) = *(undefined8 *)(param_1 + 0x38);
    piVar2 = (int *)(*(longlong *)(lVar4 + 0x50) + 0xc);
    *piVar2 = *piVar2 + 1;
    *(ulonglong *)(param_1 + 0x40) = (ulonglong)*(uint *)(lVar4 + 0x30);
    lVar3 = *(longlong *)(*(longlong *)(lVar4 + 0x18) + 0x18);
    memmove((void *)(param_1 + 0x48),(void *)(lVar3 + 0x98),0x10);
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(lVar3 + 0xac);
    piVar2 = (int *)(lVar4 + 0x10);
    *piVar2 = *piVar2 + -1;
    if (*piVar2 == 0) {
      KeReleaseSpinLock();
      FreeTapiLine(lVar4);
    }
    else {
      KeReleaseSpinLock(lVar1,*(undefined1 *)(lVar4 + 0x80));
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6f,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
    uVar7 = 0;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6d,
               &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids,*(undefined4 *)(param_1 + 0x34));
    }
    uVar7 = 0x1002;
  }
  return uVar7;
}



===== PxTapiProviderInit @ 140016aa0 =====

undefined8 PxTapiProviderInit(void)

{
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x70,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x71,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
  }
  return 0;
}



===== PxTapiProviderShutdown @ 140016b10 =====

undefined8 PxTapiProviderShutdown(void)

{
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x72,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x73,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
  }
  return 0;
}



===== PxTapiSecureCall @ 140016b80 =====

undefined8 PxTapiSecureCall(void)

{
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x74,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x75,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
  }
  return 0xc0012016;
}



===== PxTapiSelectExtVersion @ 140016bf0 =====

undefined8 PxTapiSelectExtVersion(void)

{
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x76,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x77,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
  }
  return 0;
}



===== PxTapiSendUserUserInfo @ 140016c60 =====

undefined8 PxTapiSendUserUserInfo(void)

{
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x56,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x57,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
  }
  return 0xc0012016;
}



===== PxTapiSetAppSpecific @ 140016cd0 =====

undefined8 PxTapiSetAppSpecific(longlong param_1,undefined8 param_2,undefined *param_3)

{
  int *piVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  bool bVar5;
  undefined1 uVar6;
  undefined8 uVar7;
  longlong *local_res8;
  
  local_res8 = (longlong *)0x0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x58,
            &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
  }
  bVar5 = IsVcValid(*(ulonglong *)(param_1 + 0x38),(longlong *)&local_res8);
  plVar4 = local_res8;
  if (bVar5) {
    plVar2 = local_res8 + 0x40;
    uVar6 = KeAcquireSpinLockRaiseToDpc(plVar2);
    *(undefined1 *)(plVar4 + 0x41) = uVar6;
    lVar3 = plVar4[0x26];
    *(undefined4 *)(lVar3 + 0x24) = *(undefined4 *)(param_1 + 0x40);
    piVar1 = (int *)((longlong)plVar4 + 0x1c);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      DoDerefVcWork(plVar4,lVar3,param_3);
    }
    else {
      KeReleaseSpinLock(plVar2,CONCAT71((int7)((ulonglong)lVar3 >> 8),(char)plVar4[0x41]));
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5a,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
    uVar7 = 0;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x59,param_3,
               *(undefined8 *)(param_1 + 0x38));
    }
    uVar7 = 0xc001200d;
  }
  return uVar7;
}



===== PxTapiSetCallParams @ 140016df0 =====

undefined8 PxTapiSetCallParams(void)

{
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5b,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5c,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
  }
  return 0xc0012016;
}



===== PxTapiSetDefaultMediaDetection @ 140016e60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 PxTapiSetDefaultMediaDetection(longlong param_1,undefined8 param_2,undefined *param_3)

{
  longlong *plVar1;
  int *piVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined8 uVar6;
  code *pcVar7;
  bool bVar8;
  undefined1 uVar9;
  int iVar10;
  longlong *plVar11;
  longlong *plVar12;
  undefined8 *puVar13;
  longlong *plVar14;
  undefined2 uVar15;
  uint uVar16;
  longlong *plVar17;
  undefined1 *puVar18;
  longlong lVar19;
  longlong *local_res8;
  undefined1 auStackY_58 [8];
  undefined1 auStackY_50 [24];
  
  local_res8 = (longlong *)0x0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5d,
            &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
  }
  bVar8 = IsTapiLineValid(*(int *)(param_1 + 0x38),(longlong *)&local_res8);
  plVar17 = local_res8;
  if (!bVar8) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5e,param_3,
               *(undefined8 *)(param_1 + 0x38));
    }
    return 0x1002;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5f,param_3,local_res8,
              (char)*(undefined8 *)(param_1 + 0x38));
  }
  plVar1 = plVar17 + 0xf;
  plVar3 = plVar17 + 0x10;
  uVar9 = KeAcquireSpinLockRaiseToDpc(plVar1);
  *(undefined1 *)plVar3 = uVar9;
  lVar19 = plVar17[10];
  if ((*(uint *)(lVar19 + 0x38) & 4) == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar15 = 0x60;
LAB_140016f68:
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar15,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
LAB_140016f78:
    puVar18 = auStackY_58;
    uVar9 = (undefined1)*plVar3;
    plVar14 = plVar1;
  }
  else {
    uVar16 = *(uint *)(param_1 + 0x40);
    if ((*(uint *)(plVar17[9] + 0x3c) & uVar16) != uVar16) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar15 = 0x61;
        goto LAB_140016f68;
      }
      goto LAB_140016f78;
    }
    if ((uVar16 & ~*(uint *)(lVar19 + 0x10)) == 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar15 = 0x62;
        goto LAB_140016f68;
      }
      goto LAB_140016f78;
    }
    uVar16 = uVar16 | *(uint *)(lVar19 + 0x10);
    *(uint *)(lVar19 + 0x10) = uVar16;
    plVar4 = (longlong *)plVar17[7];
    plVar11 = (longlong *)plVar17[8];
    plVar17[8] = 0;
    KeReleaseSpinLock(plVar1,CONCAT31((int3)(uVar16 >> 8),(char)*plVar3));
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)*(uint *)(plVar17[10] + 0x10)
                 ,lVar19,plVar17,(char)plVar4,(char)*(uint *)(plVar17[10] + 0x10));
    }
    plVar14 = plVar4 + 0x17;
    uVar9 = KeAcquireSpinLockRaiseToDpc(plVar14);
    *(int *)((longlong)plVar4 + 0x14) = *(int *)((longlong)plVar4 + 0x14) + 1;
    *(undefined1 *)(plVar4 + 0x18) = uVar9;
    if (plVar11 == (longlong *)0x0) {
      KeReleaseSpinLock(plVar14,uVar9);
LAB_1400170e3:
      plVar11 = (longlong *)(*(code *)plVar4[0x10])(plVar4,plVar17);
      puVar18 = auStackY_58;
      if (plVar11 != (longlong *)0x0) {
        uVar9 = KeAcquireSpinLockRaiseToDpc(plVar14);
        puVar18 = auStackY_58;
        *(undefined1 *)(plVar4 + 0x18) = uVar9;
        plVar12 = plVar4 + 5;
        puVar13 = (undefined8 *)plVar4[6];
        if ((longlong *)*puVar13 != plVar12) goto LAB_140017123;
        goto LAB_14001712a;
      }
    }
    else {
      lVar19 = *plVar11;
      if ((*(longlong **)(lVar19 + 8) == plVar11) &&
         (plVar12 = (longlong *)plVar11[1], (longlong *)*plVar12 == plVar11)) {
        *plVar12 = lVar19;
        *(longlong **)(lVar19 + 8) = plVar12;
        puVar13 = (undefined8 *)plVar4[8];
        if ((longlong *)*puVar13 == plVar4 + 7) {
          plVar11[1] = (longlong)puVar13;
          *plVar11 = (longlong)(plVar4 + 7);
          *puVar13 = plVar11;
          plVar4[8] = (longlong)plVar11;
          KeReleaseSpinLock(plVar14,(char)plVar4[0x18]);
          LOCK();
          *(undefined4 *)(plVar11 + 2) = 1;
          UNLOCK();
          iVar10 = NdisClDeregisterSap(plVar11[7]);
          if (iVar10 != 0x103) {
            PxClDeregisterSapComplete((char)iVar10,plVar11);
          }
          plVar17 = local_res8;
          goto LAB_1400170e3;
        }
      }
LAB_140017123:
      puVar13 = (undefined8 *)0x3;
      pcVar7 = (code *)swi(0x29);
      plVar12 = (longlong *)(*pcVar7)();
      puVar18 = auStackY_50;
LAB_14001712a:
      plVar11[1] = (longlong)puVar13;
      *plVar11 = (longlong)plVar12;
      *puVar13 = plVar11;
      plVar12[1] = (longlong)plVar11;
      lVar19 = plVar4[0x18];
      *(int *)((longlong)plVar4 + 0x14) = *(int *)((longlong)plVar4 + 0x14) + 1;
      *(undefined8 *)(puVar18 + -8) = 0x14001714b;
      KeReleaseSpinLock(plVar14,(char)lVar19);
      lVar19 = plVar11[8];
      lVar5 = plVar4[3];
      *(undefined8 *)(puVar18 + -8) = 0x140017166;
      iVar10 = NdisClRegisterSap(lVar5,plVar11,lVar19,plVar11 + 7);
      if (iVar10 != 0x103) {
        lVar19 = plVar11[7];
        lVar5 = plVar11[8];
        *(undefined8 *)(puVar18 + -8) = 0x140017184;
        PxClRegisterSapComplete(iVar10,plVar11,lVar5,lVar19);
      }
    }
    *(undefined8 *)(puVar18 + -8) = 0x14001718e;
    uVar9 = KeAcquireSpinLockRaiseToDpc(plVar14);
    piVar2 = (int *)((longlong)plVar4 + 0x14);
    *piVar2 = *piVar2 + -1;
    *(undefined1 *)(plVar4 + 0x18) = uVar9;
    if (*piVar2 == 0) {
      *(undefined8 *)(puVar18 + -8) = 0x1400171a7;
      DoDerefClAfWork(plVar4);
      goto LAB_1400171ba;
    }
  }
  *(undefined8 *)(puVar18 + -8) = 0x1400171b5;
  KeReleaseSpinLock(plVar14,uVar9);
LAB_1400171ba:
  *(undefined8 *)(puVar18 + -8) = 0x1400171c4;
  uVar9 = KeAcquireSpinLockRaiseToDpc(plVar1);
  *(undefined1 *)plVar3 = uVar9;
  plVar4 = plVar17 + 2;
  *(int *)plVar4 = (int)*plVar4 + -1;
  lVar19 = *plVar3;
  if ((int)*plVar4 == 0) {
    *(undefined8 *)(puVar18 + -8) = 0x1400171df;
    KeReleaseSpinLock();
    *(undefined8 *)(puVar18 + -8) = 0x1400171ec;
    FreeTapiLine((longlong)plVar17);
  }
  else {
    *(undefined8 *)(puVar18 + -8) = 0x1400171f5;
    KeReleaseSpinLock(plVar1,(char)lVar19);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(undefined8 *)(puVar18 + -8) = 0x140017221;
    WPP_SF_(uVar6,100,&WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
  }
  return 0;
}



===== PxTapiSetDevConfig @ 140017250 =====

undefined8 PxTapiSetDevConfig(void)

{
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x65,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x66,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
  }
  return 0xc0012016;
}



===== PxTapiSetMediaMode @ 1400172c0 =====

undefined8 PxTapiSetMediaMode(longlong param_1,undefined8 param_2,undefined *param_3)

{
  int *piVar1;
  longlong *plVar2;
  uint uVar3;
  longlong *plVar4;
  bool bVar5;
  undefined1 uVar6;
  undefined8 uVar7;
  longlong *local_res8;
  
  uVar7 = 0;
  local_res8 = (longlong *)0x0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x67,
            &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
  }
  bVar5 = IsVcValid(*(ulonglong *)(param_1 + 0x38),(longlong *)&local_res8);
  plVar4 = local_res8;
  if (bVar5) {
    plVar2 = local_res8 + 0x40;
    uVar6 = KeAcquireSpinLockRaiseToDpc(plVar2);
    *(undefined1 *)(plVar4 + 0x41) = uVar6;
    uVar3 = *(uint *)(param_1 + 0x40);
    if ((*(uint *)(*(longlong *)(*(longlong *)(plVar4[0x21] + 0x18) + 0x48) + 0x3c) & uVar3) == 0) {
      uVar7 = 0xc0012013;
    }
    else {
      *(uint *)(plVar4[0x26] + 0x20) = uVar3;
    }
    piVar1 = (int *)((longlong)plVar4 + 0x1c);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      DoDerefVcWork(plVar4,(ulonglong)uVar3,param_3);
    }
    else {
      KeReleaseSpinLock(plVar2,CONCAT31((int3)(uVar3 >> 8),(char)plVar4[0x41]));
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x69,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_P(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x68,param_3,
               *(undefined8 *)(param_1 + 0x38));
    }
    uVar7 = 0xc001200d;
  }
  return uVar7;
}



===== PxTapiSetStatusMessages @ 140017400 =====

undefined8 PxTapiSetStatusMessages(void)

{
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (3 < (byte)WPP_GLOBAL_Control[0x29]) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6a,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6b,
              &WPP_5e8f30bd7c243761a4b4ea8e1b4ee1ba_Traceguids);
    }
  }
  return 0xc0012016;
}



===== PxVcCleanup @ 140017470 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 PxVcCleanup(longlong param_1,longlong *param_2,undefined8 param_3)

{
  uint uVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  undefined1 *puVar5;
  undefined1 uVar6;
  undefined8 uVar7;
  longlong *plVar8;
  undefined8 uVar9;
  uint uVar10;
  undefined1 *puVar11;
  undefined4 uVar12;
  ulonglong uVar13;
  undefined1 auStackY_88 [8];
  undefined1 auStackY_80 [24];
  undefined8 local_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 local_28;
  ulonglong local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  uVar12 = 0x4000d240;
  uVar10 = (uint)param_2;
  plVar8 = param_2;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    plVar8 = (longlong *)0x9d;
    WPP_SF_qLLLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x9d,param_3,param_1,
                 (char)*(undefined4 *)(param_1 + 0x10),(char)*(undefined4 *)(param_1 + 0x18),
                 (char)param_2,(char)*(undefined4 *)(param_1 + 0x20));
  }
  uVar1 = *(uint *)(param_1 + 0x10);
  uVar13 = (ulonglong)uVar1;
  if (uVar1 == 0) {
    uVar12 = 0;
LAB_140017744:
    if (((ulonglong)param_2 & 0x10) == 0) goto LAB_140017578;
    plVar8 = *(longlong **)(param_1 + 0x68);
    if ((*plVar8 == param_1 + 0x60) &&
       (plVar2 = (longlong *)plVar8[1], (longlong *)*plVar2 == plVar8)) {
      *(longlong **)(param_1 + 0x68) = plVar2;
      *plVar2 = param_1 + 0x60;
      goto LAB_140017578;
    }
LAB_14001776f:
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
    puVar5 = auStackY_80;
  }
  else {
    if (uVar1 == 1) {
      *(undefined4 *)(param_1 + 0x14) = 1;
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | uVar10 | 0x88;
      *(undefined4 *)(param_1 + 0x10) = 3;
      PxCloseCallWithCm(param_1,plVar8,1);
LAB_140017738:
      uVar12 = 0x103;
    }
    else if (uVar1 == 2) {
      if (((ulonglong)param_2 & 0x10) != 0) {
        plVar8 = *(longlong **)(param_1 + 0x68);
        if ((*plVar8 != param_1 + 0x60) ||
           (plVar2 = (longlong *)plVar8[1], (longlong *)*plVar2 != plVar8)) goto LAB_14001776f;
        *(longlong **)(param_1 + 0x68) = plVar2;
        uVar10 = uVar10 & 0xffffffef;
        *plVar2 = param_1 + 0x60;
      }
      uVar10 = uVar10 | *(uint *)(param_1 + 0x20);
      *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x10);
      *(uint *)(param_1 + 0x20) = uVar10 | 0x20;
      *(uint *)(param_1 + 0x10) = -(uint)((uVar10 & 8) != 0) & 3;
      if ((uVar10 & 4) != 0) {
        PxStopIncomingCallTimeout(param_1,plVar8,2);
      }
      lVar3 = param_1 + 0x200;
      KeReleaseSpinLock(lVar3,*(undefined1 *)(param_1 + 0x208));
      uVar7 = *(undefined8 *)(param_1 + 0x138);
      uVar9 = *(undefined8 *)(param_1 + 0x28);
      NdisClIncomingCallComplete(0xc0000001,uVar9);
      uVar6 = KeAcquireSpinLockRaiseToDpc(lVar3);
      *(undefined1 *)(param_1 + 0x208) = uVar6;
      if ((*(uint *)(param_1 + 0x20) & 8) == 0) {
        local_34 = 0;
        local_28 = 0;
        local_38 = 2;
        local_48 = *(undefined8 *)(*(longlong *)(param_1 + 0x100) + 0x28);
        local_40 = *(undefined8 *)(param_1 + 0x110);
        local_30 = 0x4000;
        local_20 = (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x130) + 0x20);
        *(undefined4 *)(param_1 + 0x128) = 0;
        *(undefined4 *)(param_1 + 0x124) = 0x4000;
        KeReleaseSpinLock(lVar3);
        PxIndicateStatus(&local_48);
        uVar6 = KeAcquireSpinLockRaiseToDpc(lVar3);
        *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;
        *(undefined1 *)(param_1 + 0x208) = uVar6;
      }
      else {
        PxCloseCallWithCm(param_1,CONCAT71((int7)((ulonglong)uVar9 >> 8),uVar6),uVar7);
      }
      uVar12 = 0;
    }
    else {
      if (uVar1 == 3) {
        *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | uVar10;
        goto LAB_140017738;
      }
      if (uVar1 != 4) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (WPP_GLOBAL_Control[0x29] != '\0')) {
          WPP_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x9e,uVar13,param_1,(char)uVar1,
                     (char)*(undefined4 *)(param_1 + 0x124));
        }
        uVar12 = 0xc0000001;
        goto LAB_140017744;
      }
      uVar12 = 0x103;
      if ((*(uint *)(param_1 + 0x20) & 0x10) == 0) {
        *(undefined4 *)(param_1 + 0x14) = 4;
        *(undefined4 *)(param_1 + 0x10) = 3;
        *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | uVar10 | 8;
        uVar7 = PxCloseCallWithCl(param_1,plVar8,4);
        if ((int)uVar7 != 0x103) {
          PxCloseCallWithCm(param_1,plVar8,uVar13);
        }
      }
    }
LAB_140017578:
    puVar11 = auStackY_88;
    puVar5 = auStackY_88;
    if (*(int *)(param_1 + 0xf8) != 0) {
      KeReleaseSpinLock(param_1 + 0x200,*(undefined1 *)(param_1 + 0x208));
      PxStopDigitReporting(param_1);
      uVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x200);
      *(undefined4 *)(param_1 + 0xf8) = 0;
      *(undefined1 *)(param_1 + 0x208) = uVar6;
      goto LAB_140017792;
    }
  }
  puVar11 = puVar5;
  lVar3 = *(longlong *)(param_1 + 0x70);
  if (lVar3 != 0) {
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined8 *)(puVar11 + -8) = 0x140017792;
    PxTerminateDigitDetection(param_1,lVar3,0x10);
  }
LAB_140017792:
  *(undefined8 *)(puVar11 + -8) = 0x14001779a;
  RemoveVcFromClAfList(param_1);
  *(undefined8 *)(puVar11 + -8) = 0x1400177a9;
  return uVar12;
}



===== RemoveVcFromTable @ 1400177c8 =====

void RemoveVcFromTable(longlong *param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qP(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x96,param_3,param_1,(char)param_1[0x23]);
  }
  NdisAcquireRWLockWrite(DAT_14000d7c8,&local_res8,0);
  *(undefined8 *)(DAT_14000d7c0 + param_1[0x23] * 8) = 0;
  VcTable = VcTable + -1;
  KeAcquireSpinLockAtDpcLevel(param_1 + 0x40);
  lVar1 = *param_1;
  if ((*(longlong **)(lVar1 + 8) == param_1) &&
     (plVar2 = (longlong *)param_1[1], (longlong *)*plVar2 == param_1)) {
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    KeReleaseSpinLockFromDpcLevel(param_1 + 0x40);
    NdisReleaseRWLock(DAT_14000d7c8,&local_res8);
    return;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== DoDerefVcWork @ 1400178bc =====

void DoDerefVcWork(longlong *param_1,undefined8 param_2,undefined8 param_3)

{
  int *piVar1;
  longlong *plVar2;
  uint uVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong lVar6;
  longlong *plVar7;
  code *pcVar8;
  undefined1 uVar9;
  undefined8 uVar10;
  
  uVar3 = *(uint *)(param_1 + 4);
  plVar4 = (longlong *)param_1[7];
  uVar10 = CONCAT71((int7)((ulonglong)param_2 >> 8),(char)param_1[0x41]);
  if ((uVar3 & 2) == 0) {
    KeReleaseSpinLock(param_1 + 0x40);
  }
  else {
    lVar5 = param_1[8];
    lVar6 = param_1[5];
    param_1[8] = 0;
    param_1[5] = 0;
    *(uint *)(param_1 + 4) = uVar3 & 0xfffffffd;
    KeReleaseSpinLock();
    if (lVar5 != 0) {
      NdisCoDeleteVc(lVar5);
    }
    if (((uVar3 & 1) != 0) && (lVar6 != 0)) {
      NdisCoDeleteVc(lVar6);
    }
    RemoveVcFromTable(param_1,uVar10,param_3);
  }
  uVar9 = KeAcquireSpinLockRaiseToDpc(plVar4 + 0x17);
  *(undefined1 *)(plVar4 + 0x18) = uVar9;
  plVar2 = param_1 + 0x3c;
  lVar5 = *plVar2;
  if ((*(longlong **)(lVar5 + 8) != plVar2) ||
     (plVar7 = (longlong *)param_1[0x3d], (longlong *)*plVar7 != plVar2)) {
    pcVar8 = (code *)swi(0x29);
    (*pcVar8)(3);
    pcVar8 = (code *)swi(3);
    (*pcVar8)();
    return;
  }
  *plVar7 = lVar5;
  *(longlong **)(lVar5 + 8) = plVar7;
  piVar1 = (int *)((longlong)plVar4 + 0x14);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    DoDerefClAfWork(plVar4);
  }
  else {
    KeReleaseSpinLock(plVar4 + 0x17,CONCAT71((int7)((ulonglong)lVar5 >> 8),(char)plVar4[0x18]));
  }
  PxFreeVc((longlong)param_1);
  return;
}



===== GetAllDevClasses @ 1400179f0 =====

void GetAllDevClasses(longlong param_1,void *param_2,uint *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined1 uVar3;
  uint uVar4;
  longlong *plVar5;
  uint uVar6;
  longlong *plVar7;
  ulonglong _Size;
  uint uVar8;
  void *local_res10;
  
  uVar6 = 0;
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x270);
  *(undefined1 *)(param_1 + 0x278) = uVar3;
  plVar5 = *(longlong **)(param_1 + 0x50);
  uVar8 = *param_3;
  if (plVar5 != (longlong *)(param_1 + 0x50)) {
    local_res10 = param_2;
    do {
      uVar3 = KeAcquireSpinLockRaiseToDpc(plVar5 + 0xb);
      plVar1 = plVar5 + 5;
      *(undefined1 *)(plVar5 + 0xc) = uVar3;
      plVar7 = (longlong *)*plVar1;
      if (plVar7 != plVar1) {
        do {
          _Size = (ulonglong)*(uint *)(plVar7[6] + 4);
          if ((ulonglong)uVar8 < _Size + 2) break;
          memmove(local_res10,(void *)(plVar7[6] + 8),_Size);
          plVar2 = plVar7 + 6;
          plVar7 = (longlong *)*plVar7;
          uVar4 = *(int *)(*plVar2 + 4) + 2;
          uVar6 = uVar6 + uVar4;
          local_res10 = (void *)((longlong)local_res10 + (ulonglong)uVar4);
          uVar8 = uVar8 - uVar4;
        } while (plVar7 != plVar1);
      }
      KeReleaseSpinLock(plVar5 + 0xb,(char)plVar5[0xc]);
      plVar5 = (longlong *)*plVar5;
    } while (plVar5 != (longlong *)(param_1 + 0x50));
  }
  KeReleaseSpinLock(param_1 + 0x270,*(undefined1 *)(param_1 + 0x278));
  *param_3 = uVar6;
  return;
}



===== IntegerToWChar @ 140017b08 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 IntegerToWChar(uint param_1,undefined8 param_2,void *param_3)

{
  ulonglong uVar1;
  uint uVar2;
  undefined2 *_Src;
  undefined1 auStack_b8 [32];
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined2 local_3a;
  undefined2 local_38 [8];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_b8;
  local_98 = 0x310030;
  local_38[0] = 0;
  local_94 = 0x330032;
  local_90 = 0x350034;
  local_8c = 0x370036;
  _Src = local_38;
  local_88 = 0x390038;
  local_84 = 0x420041;
  local_80 = 0x440043;
  local_7c = 0x460045;
  do {
    _Src = _Src + -1;
    uVar2 = param_1 / 10;
    *_Src = local_38[(ulonglong)(param_1 % 10) - 0x30];
    param_1 = uVar2;
  } while (uVar2 != 0);
  uVar2 = (uint)((longlong)local_38 - (longlong)_Src >> 1);
  if ((int)uVar2 < 4) {
    uVar1 = (ulonglong)(4 - uVar2);
    uVar2 = 4;
    do {
      _Src = _Src + -1;
      *_Src = 0x30;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  else if (4 < (int)uVar2) {
    return 0x80000005;
  }
  memmove(param_3,_Src,(ulonglong)uVar2 * 2);
  if ((int)uVar2 < 4) {
    *(undefined2 *)((ulonglong)uVar2 * 2 + (longlong)param_3) = 0;
  }
  return 0;
}



===== PxAfAndSapFromDevClass @ 140017c24 =====

char PxAfAndSapFromDevClass
               (longlong param_1,wchar_t *param_2,undefined8 *param_3,undefined8 *param_4)

{
  undefined8 *puVar1;
  undefined1 uVar2;
  int iVar3;
  char cVar4;
  undefined8 *puVar5;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x270);
  *param_3 = 0;
  puVar1 = *(undefined8 **)(param_1 + 0x50);
  cVar4 = '\0';
  *param_4 = 0;
  *(undefined1 *)(param_1 + 0x278) = uVar2;
  for (; puVar1 != (undefined8 *)(param_1 + 0x50); puVar1 = (undefined8 *)*puVar1) {
    uVar2 = KeAcquireSpinLockRaiseToDpc(puVar1 + 0xb);
    *(undefined1 *)(puVar1 + 0xc) = uVar2;
    for (puVar5 = (undefined8 *)puVar1[5]; puVar5 != puVar1 + 5; puVar5 = (undefined8 *)*puVar5) {
      iVar3 = _wcsnicmp((wchar_t *)(puVar5[6] + 8),param_2,
                        (ulonglong)(*(uint *)(puVar5[6] + 4) >> 1));
      if (iVar3 == 0) {
        *(int *)((longlong)puVar1 + 0x14) = *(int *)((longlong)puVar1 + 0x14) + 1;
        cVar4 = '\x01';
        *param_3 = puVar1;
        *param_4 = puVar5;
        break;
      }
    }
    KeReleaseSpinLock(puVar1 + 0xb,*(undefined1 *)(puVar1 + 0xc));
    if (cVar4 != '\0') break;
  }
  KeReleaseSpinLock(param_1 + 0x270,*(undefined1 *)(param_1 + 0x278));
  return cVar4;
}



===== PxAfTapiTranslateNdisCallParams @ 140017d50 =====

ulonglong PxAfTapiTranslateNdisCallParams(longlong param_1,undefined4 *param_2)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  undefined4 *puVar5;
  ulonglong uVar6;
  uint uVar7;
  undefined2 uVar8;
  uint uVar9;
  undefined8 *puVar10;
  ulonglong uVar11;
  undefined8 *puVar12;
  longlong lVar13;
  undefined8 *puVar14;
  longlong lVar15;
  undefined4 uVar16;
  uint uVar17;
  
  uVar17 = 0;
  puVar2 = *(undefined8 **)(*(longlong *)(param_1 + 0x38) + 0x68);
  uVar7 = 0x18;
  if (*(longlong *)(param_2 + 2) == 0) {
LAB_140017dbd:
    uVar9 = uVar7;
    if (*(longlong *)(param_2 + 4) != 0) {
      iVar1 = *(int *)(*(longlong *)(param_2 + 4) + 0x14);
      if (iVar1 + 0x20U < 0x20) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (2 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar8 = 0x20;
          goto LAB_140017ef5;
        }
      }
      else {
        uVar9 = (iVar1 + 0x23U & 0xfffffffc) + uVar7;
        if (uVar7 <= uVar9) goto LAB_140017de6;
      }
      goto LAB_140017f05;
    }
LAB_140017de6:
    puVar5 = (undefined4 *)ExAllocatePool2(0x40,uVar9,0x375850);
    if (puVar5 != (undefined4 *)0x0) {
      puVar12 = (undefined8 *)(puVar5 + 6);
      *puVar5 = *param_2;
      if (*(longlong *)(param_2 + 2) != 0) {
        *(undefined8 **)(puVar5 + 2) = puVar12;
        puVar10 = *(undefined8 **)(param_2 + 2);
        uVar3 = puVar10[1];
        *puVar12 = *puVar10;
        *(undefined8 *)(puVar5 + 8) = uVar3;
        uVar3 = puVar10[3];
        *(undefined8 *)(puVar5 + 10) = puVar10[2];
        *(undefined8 *)(puVar5 + 0xc) = uVar3;
        uVar3 = puVar10[5];
        *(undefined8 *)(puVar5 + 0xe) = puVar10[4];
        *(undefined8 *)(puVar5 + 0x10) = uVar3;
        uVar3 = puVar10[7];
        *(undefined8 *)(puVar5 + 0x12) = puVar10[6];
        *(undefined8 *)(puVar5 + 0x14) = uVar3;
        *(undefined8 *)(puVar5 + 0x16) = puVar10[8];
        puVar5[0x18] = *(undefined4 *)(puVar10 + 9);
        memmove(puVar5 + 0x18,(void *)(*(longlong *)(param_2 + 2) + 0x48),
                (ulonglong)*(uint *)(*(longlong *)(param_2 + 2) + 0x44));
        puVar12 = (undefined8 *)((longlong)puVar12 + (ulonglong)uVar17);
      }
      if (*(longlong *)(param_2 + 4) != 0) {
        *(undefined8 **)(puVar5 + 4) = puVar12;
        puVar10 = *(undefined8 **)(param_2 + 4);
        uVar3 = puVar10[1];
        *puVar12 = *puVar10;
        puVar12[1] = uVar3;
        uVar3 = puVar10[3];
        puVar12[2] = puVar10[2];
        puVar12[3] = uVar3;
        memmove((void *)(*(longlong *)(puVar5 + 4) + 0x18),
                (void *)(*(longlong *)(param_2 + 4) + 0x18),
                (ulonglong)*(uint *)(*(longlong *)(param_2 + 4) + 0x14));
      }
    }
  }
  else {
    iVar1 = *(int *)(*(longlong *)(param_2 + 2) + 0x44);
    if (iVar1 + 0x4cU < 0x4c) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar8 = 0x1f;
LAB_140017ef5:
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                &WPP_8294867e35d63e705b52ce50c02b6694_Traceguids);
      }
    }
    else {
      uVar17 = iVar1 + 0x4fU & 0xfffffffc;
      uVar7 = uVar17 + 0x18;
      if (0x17 < uVar7) goto LAB_140017dbd;
    }
LAB_140017f05:
    puVar5 = (undefined4 *)0x0;
  }
  *(undefined4 **)(param_1 + 0x138) = puVar5;
  if (puVar5 == (undefined4 *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
              &WPP_8294867e35d63e705b52ce50c02b6694_Traceguids);
    }
    goto LAB_140017ed4;
  }
  lVar13 = *(longlong *)(param_2 + 4);
  if ((lVar13 == 0) || (*(uint *)(lVar13 + 0x14) < 0x20)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
               &WPP_8294867e35d63e705b52ce50c02b6694_Traceguids,param_2);
    }
  }
  else {
    lVar15 = lVar13 + 0x18;
    if (0x157 < *(ushort *)(lVar13 + 0x28)) {
      lVar15 = *(longlong *)(lVar13 + 0x30) + lVar15;
      iVar1 = *(int *)(lVar15 + 0x20);
      uVar4 = KeAcquireSpinLockRaiseToDpc(puVar2 + 0x11);
      puVar12 = puVar2 + 5;
      *(undefined1 *)(puVar2 + 0x12) = uVar4;
      puVar10 = (undefined8 *)*puVar12;
      while ((puVar10 != puVar12 &&
             ((*(int *)((longlong)puVar10 + 0x34) != iVar1 || (*(int *)(puVar10[10] + 0xc) == 0)))))
      {
        puVar10 = (undefined8 *)*puVar10;
      }
      puVar14 = (undefined8 *)0x0;
      if (puVar10 != puVar12) {
        puVar14 = puVar10;
      }
      KeReleaseSpinLock(puVar2 + 0x11,CONCAT71((int7)((ulonglong)puVar10 >> 8),uVar4));
      if (puVar14 == (undefined8 *)0x0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (2 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar16 = *(undefined4 *)(lVar15 + 0x20);
          uVar8 = 0x1c;
          puVar14 = puVar2;
LAB_14001800e:
          WPP_SF_dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,puVar12,uVar16,(char)puVar14);
        }
      }
      else {
        uVar4 = KeAcquireSpinLockRaiseToDpc(puVar14 + 0xf);
        *(undefined1 *)(puVar14 + 0x10) = uVar4;
        lVar13 = 0;
        if (*(uint *)(lVar15 + 0x24) < *(uint *)(puVar14 + 0xb)) {
          lVar13 = *(longlong *)(puVar14[0xe] + (ulonglong)*(uint *)(lVar15 + 0x24) * 8);
        }
        KeReleaseSpinLock(puVar14 + 0xf,*(undefined1 *)(puVar14 + 0x10));
        if (lVar13 != 0) {
          uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x200);
          *(undefined1 *)(param_1 + 0x208) = uVar4;
          uVar6 = AllocateTapiCallInfo(param_1,(void *)(lVar15 + 0x10));
          uVar11 = uVar6 & 0xffffffff;
          if ((int)uVar6 == 0) {
            *(undefined8 **)(param_1 + 0x100) = puVar14;
            *(longlong *)(param_1 + 0x108) = lVar13;
            LOCK();
            *(int *)(lVar13 + 0x24) = *(int *)(lVar13 + 0x24) + 1;
            UNLOCK();
            LOCK();
            *(int *)(puVar14[10] + 0x14) = *(int *)(puVar14[10] + 0x14) + 1;
            UNLOCK();
            *(undefined4 *)(*(longlong *)(param_1 + 0x130) + 0x10) =
                 *(undefined4 *)((longlong)puVar14 + 0x34);
            *(undefined4 *)(*(longlong *)(param_1 + 0x130) + 0x14) = *(undefined4 *)(lVar13 + 0x20);
            *(undefined4 *)(*(longlong *)(param_1 + 0x130) + 0x50) = 0x80;
          }
          KeReleaseSpinLock(param_1 + 0x200,*(undefined1 *)(param_1 + 0x208));
          goto LAB_140018146;
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (2 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar16 = *(undefined4 *)(lVar15 + 0x24);
          uVar8 = 0x1d;
          goto LAB_14001800e;
        }
      }
LAB_140017ed4:
      uVar11 = 0xc000009a;
      goto LAB_140018146;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (WPP_GLOBAL_Control[0x29] != '\0')) {
      WPP_SF_dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,lVar15,
                (uint)*(ushort *)(lVar13 + 0x28),(char)lVar15);
    }
  }
  uVar11 = 0xc0010015;
LAB_140018146:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
             &WPP_8294867e35d63e705b52ce50c02b6694_Traceguids,(int)uVar11);
  }
  return uVar11;
}



===== PxAfTapiTranslateTapiCallParams @ 1400181a0 =====

undefined4
PxAfTapiTranslateTapiCallParams
          (undefined8 param_1,uint param_2,uint param_3,uint param_4,longlong param_5,int param_6,
          undefined8 *param_7)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  ulonglong *puVar5;
  undefined2 uVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  undefined8 *puVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  
  uVar11 = 0;
  uVar12 = 0;
  *param_7 = 0;
  uVar13 = *(uint *)(param_5 + 0x20);
  if (uVar13 + 0xfc < 0xfc) {
    uVar11 = 0x80000005;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0x80000005;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 5) goto LAB_1400183cb;
    uVar6 = 0x15;
  }
  else {
    puVar5 = &PxTapiCallParamList;
    uVar7 = 0;
    uVar9 = uVar13 + 0xfc;
    do {
      if ((ulonglong)(param_6 - 0x2c) < *puVar5) goto LAB_140018395;
      uVar12 = uVar12 + *(int *)(*puVar5 + 0x2c + param_5) + 8;
      uVar2 = uVar12 + uVar9;
      if (uVar2 < uVar9) {
        uVar11 = 0x80000005;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0x80000005;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 5) goto LAB_1400183cb;
        uVar6 = 0x16;
        uVar13 = uVar12;
        goto LAB_1400183bb;
      }
      uVar7 = uVar7 + 1;
      puVar5 = puVar5 + 2;
      uVar9 = uVar2;
    } while (uVar7 < 8);
    if (uVar2 <= uVar2 + 0x94) {
      puVar4 = (undefined4 *)ExAllocatePool2(0x40,uVar2 + 0x94,0x375850);
      if (puVar4 == (undefined4 *)0x0) {
LAB_140018395:
        uVar11 = 0xc000009a;
      }
      else {
        *puVar4 = 0;
        puVar8 = (uint *)((ulonglong)(puVar4 + 8) & 0xfffffffffffffff8);
        *(uint **)(puVar4 + 2) = puVar8;
        *(uint **)(puVar4 + 4) = puVar8 + 0x14;
        uVar12 = *(uint *)(param_5 + 0x38) >> 3;
        puVar8[10] = uVar12;
        puVar1 = puVar8 + 0x1a;
        puVar8[2] = uVar12;
        puVar8[8] = uVar12;
        *puVar8 = uVar12;
        puVar8[1] = 0x1000;
        puVar8[9] = 0x1000;
        puVar8[6] = 0x1000;
        puVar8[0xe] = 0x1000;
        puVar8[0x14] = 0xc;
        puVar8[0x15] = 0;
        puVar8[0x16] = 0x2000;
        puVar8[0x18] = 0;
        puVar8[0x19] = uVar2;
        *puVar1 = param_2;
        puVar8[0x1b] = param_3;
        puVar8[0x1c] = param_4;
        *(short *)((longlong)puVar8 + 0x7a) = (short)uVar13;
        *(short *)(puVar8 + 0x1e) = (short)uVar13;
        puVar8[0x20] = 0x28;
        puVar8[0x21] = 0;
        memmove(puVar8 + 0x28,(void *)((ulonglong)*(uint *)(param_5 + 0x24) + param_5),
                (ulonglong)uVar13);
        puVar10 = (undefined8 *)((ulonglong)uVar13 + 0x40 + (longlong)puVar1 & 0xfffffffffffffff8);
        *(longlong *)(puVar8 + 0x24) = (longlong)puVar10 + (-0x20 - (longlong)puVar1);
        iVar3 = PxCopyLineCallParams((undefined8 *)(param_5 + 0x2c),puVar10);
        *(uint *)((longlong)puVar10 + 0x1c) = param_3;
        *(undefined4 *)(puVar10 + 3) = 1;
        *(short *)((longlong)puVar8 + 0x8a) = (short)iVar3;
        *(short *)(puVar8 + 0x22) = (short)iVar3;
        *param_7 = puVar4;
      }
      goto LAB_1400183cb;
    }
    uVar11 = 0x80000005;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0x80000005;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 5) goto LAB_1400183cb;
    uVar6 = 0x17;
    uVar13 = 0x94;
  }
LAB_1400183bb:
  uVar11 = 0x80000005;
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
           &WPP_8294867e35d63e705b52ce50c02b6694_Traceguids,uVar13);
LAB_1400183cb:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
              &WPP_8294867e35d63e705b52ce50c02b6694_Traceguids,*param_7,(char)uVar11);
  }
  return uVar11;
}



===== PxAfTapiTranslateTapiSap @ 140018420 =====

longlong PxAfTapiTranslateTapiSap(undefined8 param_1,longlong param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  longlong lVar3;
  undefined4 *puVar4;
  
  lVar3 = ExAllocatePool2(0x40,0x68,0x345850);
  if (lVar3 != 0) {
    puVar4 = (undefined4 *)(lVar3 + 0x50U & 0xfffffffffffffff8);
    uVar1 = *(undefined4 *)(*(longlong *)(param_2 + 0x50) + 0x10);
    *puVar4 = 0x8000;
    puVar4[1] = 0xc;
    uVar2 = *(undefined4 *)(param_2 + 0x34);
    puVar4[3] = 0xffffffff;
    puVar4[2] = uVar2;
    puVar4[4] = uVar1;
    *(undefined4 **)(lVar3 + 0x40) = puVar4;
    LOCK();
    *(undefined4 *)(lVar3 + 0x10) = 2;
    UNLOCK();
    *(undefined8 *)(lVar3 + 0x20) = param_1;
    *(undefined4 *)(lVar3 + 0x30) = uVar1;
    *(longlong *)(param_2 + 0x40) = lVar3;
    *(longlong *)(lVar3 + 0x28) = param_2;
  }
  return lVar3;
}



===== PxAllocateVc @ 1400184b4 =====

void * PxAllocateVc(longlong param_1)

{
  longlong lVar1;
  void *_Dst;
  
  _Dst = (void *)ExAllocateFromNPagedLookasideList(&VcLookaside);
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,0x218);
    KeInitializeSpinLock((longlong)_Dst + 0x200);
    NdisInitializeTimer((longlong)_Dst + 0x140,PxIncomingCallTimeout,_Dst);
    NdisInitializeEvent((longlong)_Dst + 0x1c0);
    *(undefined4 *)((longlong)_Dst + 0x14) = 0;
    lVar1 = (longlong)_Dst + 0x60;
    *(undefined4 *)((longlong)_Dst + 0x10) = 0;
    *(longlong *)((longlong)_Dst + 0x68) = lVar1;
    *(longlong *)lVar1 = lVar1;
    *(undefined4 *)((longlong)_Dst + 0x1c) = 1;
    *(longlong *)((longlong)_Dst + 0x38) = param_1;
    *(undefined8 *)((longlong)_Dst + 0x58) = *(undefined8 *)(param_1 + 0x20);
  }
  return _Dst;
}



===== PxCloseCallWithCl @ 14001856c =====

undefined8 PxCloseCallWithCl(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 uVar1;
  undefined8 uVar2;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qLLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,param_3,param_1,
                (char)*(undefined4 *)(param_1 + 0x10),(char)*(undefined4 *)(param_1 + 0x18),
                (char)*(undefined4 *)(param_1 + 0x20));
  }
  uVar2 = 0x103;
  if (*(int *)(param_1 + 0x18) == 0) {
    uVar2 = 0;
  }
  else if (*(int *)(param_1 + 0x18) == 3) {
    *(undefined4 *)(param_1 + 0x18) = 2;
    KeReleaseSpinLock(param_1 + 0x200,*(undefined1 *)(param_1 + 0x208));
    NdisCmDispatchIncomingCloseCall(0,*(undefined8 *)(param_1 + 0x40),0,0);
    uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x200);
    *(undefined1 *)(param_1 + 0x208) = uVar1;
  }
  return uVar2;
}



===== PxCloseCallWithCm @ 14001863c =====

void PxCloseCallWithCm(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  bool bVar1;
  undefined1 uVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  int *piVar6;
  undefined8 uVar7;
  int local_res8 [2];
  
  local_res8[0] = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qLLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,param_3,param_1,
                (char)*(undefined4 *)(param_1 + 0x10),(char)*(undefined4 *)(param_1 + 0x18),
                (char)*(undefined4 *)(param_1 + 0x20));
  }
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffff7;
  *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) | 0x100;
  KeReleaseSpinLock(param_1 + 0x200,*(undefined1 *)(param_1 + 0x208));
  uVar4 = Feature_2616427835__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar4 == 0) {
    uVar5 = *(undefined8 *)(param_1 + 0x28);
    uVar7 = 0;
    piVar6 = (int *)0x0;
  }
  else {
    if (((*(longlong *)(param_1 + 0x58) == 0) ||
        (*(int *)(*(longlong *)(param_1 + 0x58) + 0xac) != 0xd)) ||
       (local_res8[0] = *(int *)(param_1 + 0x214), local_res8[0] == 0)) {
      bVar1 = false;
      local_res8[0] = 0;
    }
    else {
      bVar1 = true;
    }
    uVar5 = *(undefined8 *)(param_1 + 0x28);
    if (bVar1) {
      uVar7 = 4;
      piVar6 = local_res8;
    }
    else {
      uVar7 = 0;
      piVar6 = (int *)0x0;
    }
  }
  iVar3 = NdisClCloseCall(uVar5,0,piVar6,uVar7);
  if (iVar3 != 0x103) {
    PxClCloseCallComplete(iVar3,*(ulonglong *)(param_1 + 0x118),(undefined *)0x0);
  }
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x200);
  *(undefined1 *)(param_1 + 0x208) = uVar2;
  return;
}



===== PxCopyLineCallParams @ 14001875c =====

int PxCopyLineCallParams(undefined8 *param_1,undefined8 *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  uint uVar4;
  int iVar5;
  void *_Dst;
  ulonglong uVar6;
  longlong *plVar7;
  int iVar8;
  
  uVar3 = param_1[1];
  _Dst = (void *)((longlong)param_2 + 0xbcU & 0xfffffffffffffff8);
  plVar7 = &DAT_14000d318;
  *param_2 = *param_1;
  param_2[1] = uVar3;
  uVar3 = param_1[3];
  iVar8 = ((uint)((longlong)param_2 + 0xbcU) & 0xfffffff8) - (int)param_2;
  param_2[2] = param_1[2];
  param_2[3] = uVar3;
  uVar3 = param_1[5];
  param_2[4] = param_1[4];
  param_2[5] = uVar3;
  uVar3 = param_1[7];
  param_2[6] = param_1[6];
  param_2[7] = uVar3;
  uVar3 = param_1[9];
  param_2[8] = param_1[8];
  param_2[9] = uVar3;
  uVar3 = param_1[0xb];
  param_2[10] = param_1[10];
  param_2[0xb] = uVar3;
  uVar3 = param_1[0xd];
  param_2[0xc] = param_1[0xc];
  param_2[0xd] = uVar3;
  uVar3 = param_1[0xf];
  uVar4 = 0;
  param_2[0xe] = param_1[0xe];
  param_2[0xf] = uVar3;
  uVar3 = param_1[0x11];
  param_2[0x10] = param_1[0x10];
  param_2[0x11] = uVar3;
  uVar3 = param_1[0x13];
  param_2[0x12] = param_1[0x12];
  param_2[0x13] = uVar3;
  uVar3 = param_1[0x15];
  param_2[0x14] = param_1[0x14];
  param_2[0x15] = uVar3;
  *(undefined4 *)(param_2 + 0x16) = *(undefined4 *)(param_1 + 0x16);
  do {
    uVar1 = *(uint *)((longlong)param_1 + plVar7[-1]);
    if (uVar1 != 0) {
      iVar5 = (int)_Dst;
      uVar2 = *(uint *)(*plVar7 + (longlong)param_1);
      *(int *)(*plVar7 + (longlong)param_2) = iVar5 - (int)param_2;
      memmove(_Dst,(void *)((ulonglong)uVar2 + (longlong)param_1),(ulonglong)uVar1);
      uVar6 = (longlong)_Dst + (ulonglong)uVar1 + 8;
      _Dst = (void *)(uVar6 & 0xfffffffffffffff8);
      iVar8 = iVar8 + (((uint)uVar6 & 0xfffffff8) - iVar5);
    }
    uVar4 = uVar4 + 1;
    plVar7 = plVar7 + 2;
  } while (uVar4 < 8);
  return iVar8;
}



===== PxFreeVc @ 140018878 =====

void PxFreeVc(longlong param_1)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (*(longlong *)(param_1 + 0x130) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x130),0);
    *(undefined8 *)(param_1 + 0x130) = 0;
  }
  if (*(longlong *)(param_1 + 0x138) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x138),0);
    *(undefined8 *)(param_1 + 0x138) = 0;
  }
  lVar2 = *(longlong *)(param_1 + 0x108);
  lVar3 = *(longlong *)(param_1 + 0x100);
  *(undefined8 *)(param_1 + 0x108) = 0;
  *(undefined8 *)(param_1 + 0x100) = 0;
  if (lVar2 != 0) {
    LOCK();
    piVar1 = (int *)(lVar2 + 0x24);
    *piVar1 = *piVar1 + -1;
    UNLOCK();
  }
  if (lVar3 != 0) {
    LOCK();
    piVar1 = (int *)(*(longlong *)(lVar3 + 0x50) + 0x14);
    *piVar1 = *piVar1 + -1;
    UNLOCK();
  }
  ExFreeToNPagedLookasideList(&VcLookaside,param_1);
  return;
}



===== PxIncomingCallTimeout @ 140018920 =====

void PxIncomingCallTimeout(undefined8 param_1,longlong *param_2,undefined8 param_3)

{
  int *piVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x40);
  *(undefined1 *)(param_2 + 0x41) = uVar2;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qLqLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,param_3,param_2,(char)param_2[4],
                 (char)param_2[5],(char)*(undefined4 *)((longlong)param_2 + 0x124),
                 (char)param_2[0x25]);
  }
  *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) & 0xfffffffb;
  uVar3 = 0;
  *(uint *)((longlong)param_2 + 0x24) = *(uint *)((longlong)param_2 + 0x24) | 0x40;
  PxVcCleanup((longlong)param_2,(longlong *)0x0,param_3);
  piVar1 = (int *)((longlong)param_2 + 0x1c);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    DoDerefVcWork(param_2,uVar3,param_3);
  }
  else {
    KeReleaseSpinLock(param_2 + 0x40,(char)param_2[0x41]);
  }
  return;
}



===== PxStopIncomingCallTimeout @ 1400189e0 =====

void PxStopIncomingCallTimeout(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  char local_res8 [32];
  
  local_res8[0] = '\0';
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qLqLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,param_3,param_1,
                 (char)*(undefined4 *)(param_1 + 0x20),(char)*(undefined8 *)(param_1 + 0x28),
                 (char)*(undefined4 *)(param_1 + 0x124),(char)*(undefined4 *)(param_1 + 0x128));
  }
  NdisCancelTimer(param_1 + 0x140,local_res8);
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffffb;
  if (local_res8[0] != '\0') {
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;
  }
  return;
}



===== PxCoCloseAdapterCompleteEx @ 140019010 =====

void PxCoCloseAdapterCompleteEx(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_1;
  piVar2 = param_1 + -4;
  if (iVar1 != 0x20206d43) {
    piVar2 = param_1;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
             &WPP_cf979805fba431836a82e04c99ce8a90_Traceguids,piVar2);
  }
  if (iVar1 == 0x20206d43) {
    piVar2[0x80] = 0;
    piVar2 = piVar2 + 0x7a;
  }
  else {
    piVar2[0x78] = 0;
    piVar2 = piVar2 + 0x72;
  }
  NdisSetEvent(piVar2);
  return;
}



===== PxCoNetPnPEvent @ 1400190a0 =====

undefined4 PxCoNetPnPEvent(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = (int *)(param_2 + 8);
  uVar1 = 0;
  iVar4 = *piVar3;
  if (iVar4 == 0) {
    uVar2 = PxPnPSetPower(0,(longlong)piVar3);
    uVar1 = (undefined4)uVar2;
  }
  else if (iVar4 == 1) {
    uVar2 = PxPnPCancelRemove();
    uVar1 = (undefined4)uVar2;
  }
  else if (iVar4 == 2) {
    uVar2 = PxPnPCancelRemove();
    uVar1 = (undefined4)uVar2;
  }
  else if (iVar4 == 3) {
    uVar2 = PxPnPCancelRemove();
    uVar1 = (undefined4)uVar2;
  }
  else if (iVar4 == 4) {
    uVar2 = PxPnPReconfigure();
    uVar1 = (undefined4)uVar2;
  }
  else if ((iVar4 == 5) || (((iVar4 != 8 && (iVar4 != 9)) && (iVar4 != 0x10)))) {
    uVar1 = 0xc00000bb;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),piVar3,param_3,iVar4,(char)uVar1);
  }
  return uVar1;
}



===== PxCoOpenAdaperCompleteEx @ 140019140 =====

void PxCoOpenAdaperCompleteEx(int *param_1,int param_2)

{
  int *piVar1;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
              &WPP_cf979805fba431836a82e04c99ce8a90_Traceguids,param_1,(char)param_2);
  }
  piVar1 = param_1 + -4;
  if (*param_1 != 0x20206d43) {
    piVar1 = param_1;
  }
  piVar1[0x88] = param_2;
  NdisSetEvent(piVar1 + 0x82);
  return;
}



===== WppCleanupKm @ 1400191c0 =====

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



===== WppInitKm @ 140019240 =====

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



===== WppLoadTracingSupport @ 1400192d0 =====

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



===== WppTraceCallback @ 140019420 =====

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



===== wil_details_EvaluateFeatureDependencies @ 1400196a8 =====

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
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x0001400196e3;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_14001975d:
  while( true ) {
    if (&UNK_14000c687 < ppuVar3) {
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
      if (&UNK_14000c687 < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x0001400196e3:
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
      if (&UNK_14000c687 < ppuVar2) goto LAB_14001975d;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_14001975d;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140019798 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_140019830;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_140019830;
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
LAB_140019830:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140019880 =====

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
              if (&UNK_14000c687 < ppuVar2) {
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140019900 =====

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
    if (*ppuVar3 != (undefined *)0x0) goto LAB_1400199fd;
  }
LAB_140019a06:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_1400199fd:
  if (ppuVar3 == (undefined **)0x0) goto LAB_140019a06;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_1400199ce:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_1400199ce;
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
    if (&UNK_14000c687 < ppuVar3) goto LAB_140019a06;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_1400199fd;
}



===== WdmlibIoCreateDeviceSecure @ 140019a2c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WdmlibIoCreateDeviceSecure(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 in_stack_00000048;
  undefined8 local_18;
  undefined8 uStack_10;
  
  if (WdmlibInitialized == '\0') {
    local_18 = 0;
    uStack_10 = 0;
    RtlInitUnicodeString(&local_18,L"IoCreateDeviceSecure");
    PfnIoCreateDeviceSecure = (code *)MmGetSystemRoutineAddress(&local_18);
    if (PfnIoCreateDeviceSecure == (code *)0x0) {
      PfnIoCreateDeviceSecure = IoDevObjCreateDeviceSecure;
    }
    RtlInitUnicodeString(&local_18,L"IoValidateDeviceIoControlAccess");
    MmGetSystemRoutineAddress(&local_18);
    WdmlibInitialized = '\x01';
  }
  (*PfnIoCreateDeviceSecure)(param_1,0x68,param_3,0x12,0x100,0,&SDDL_SYS_ALL,0,in_stack_00000048);
  return;
}



===== IoDevObjCreateDeviceSecure @ 140019b20 =====

ulonglong IoDevObjCreateDeviceSecure
                    (ulonglong param_1,ulonglong param_2,longlong param_3,undefined4 param_4,
                    undefined4 param_5,undefined1 param_6,ushort *param_7,undefined4 *param_8,
                    undefined8 *param_9)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  longlong local_res18;
  undefined4 local_res20;
  undefined8 local_68;
  longlong lStack_60;
  undefined8 local_58;
  undefined8 local_50;
  longlong local_48;
  undefined8 local_40;
  
  puVar2 = param_9;
  local_res18 = 0;
  local_58 = 0;
  *param_9 = 0;
  param_9 = (undefined8 *)0x0;
  local_68 = 0;
  lStack_60 = 0;
  if ((param_3 == 0) && (-1 < (char)param_5)) {
    return 0xc000000d;
  }
  uVar5 = param_2;
  local_res20 = param_4;
  if ((param_8 != (undefined4 *)0x0) &&
     (uVar5 = param_1,
     uVar4 = PpRegStateReadCreateClassCreationSettings(param_8,param_1,(uint *)&local_68),
     (int)uVar4 < 0)) {
    return uVar4;
  }
  uVar6 = (uint)local_68;
  if ((local_68 & 2) == 0) {
    uVar5 = SeSddlSecurityDescriptorFromSDDL(param_7,uVar5,&local_res18);
    uVar4 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) goto LAB_140019c80;
    uVar6 = 2;
    local_68 = CONCAT44(local_68._4_4_,2);
    lStack_60 = local_res18;
    if (param_8 != (undefined4 *)0x0) {
      local_50 = 2;
      local_40 = 0;
      local_48 = local_res18;
      uVar5 = PpRegStateUpdateStackCreationSettings(param_8,(longlong)&local_50);
      uVar4 = uVar5 & 0xffffffff;
      if ((int)uVar5 < 0) goto LAB_140019c80;
    }
  }
  uVar1 = local_res20;
  if ((uVar6 & 1) != 0) {
    uVar1 = local_68._4_4_;
  }
  if ((uVar6 & 4) != 0) {
    param_5 = (undefined4)local_58;
  }
  if ((uVar6 & 8) != 0) {
    param_6 = local_58._4_1_;
  }
  uVar3 = IoCreateDevice(param_1,param_2 & 0xffffffff,param_3,uVar1,param_5,param_6,&param_9);
  uVar4 = (ulonglong)uVar3;
  if (-1 < (int)uVar3) {
    uVar5 = IopDevObjApplyPostCreationSettings(param_9,(uint *)&local_68);
    uVar4 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) {
      IoDeleteDevice(param_9);
    }
    else {
      *puVar2 = param_9;
    }
  }
LAB_140019c80:
  if ((uVar6 & 2) != 0) {
    ExFreePoolWithTag(lStack_60,0);
  }
  return uVar4;
}



===== IopDevObjApplyPostCreationSettings @ 140019cb4 =====

ulonglong IopDevObjApplyPostCreationSettings(undefined8 param_1,uint *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  undefined1 local_res10 [8];
  uint local_res18 [2];
  undefined8 local_res20;
  
  local_res18[0] = 0;
  local_res20 = 0;
  local_res10[0] = 0;
  if ((*param_2 & 2) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = SeUtilSecurityInfoFromSecurityDescriptor
                      (*(undefined8 *)(param_2 + 2),local_res10,local_res18);
    if (-1 < (int)uVar2) {
      uVar3 = -(uint)((local_res18[0] & 3) != 0) & 0x80000;
      uVar1 = uVar3 | 0x40000;
      if ((local_res18[0] & 4) == 0) {
        uVar1 = uVar3;
      }
      uVar3 = uVar1 | 0x1000000;
      if ((local_res18[0] & 8) == 0) {
        uVar3 = uVar1;
      }
      uVar2 = ObOpenObjectByPointer
                        (param_1,0x200,0,uVar3,*(undefined8 *)IoDeviceObjectType_exref,0,
                         &local_res20);
      if (-1 < (int)uVar2) {
        uVar1 = ZwSetSecurityObject(local_res20,local_res18[0],*(undefined8 *)(param_2 + 2));
        uVar2 = (ulonglong)uVar1;
        ZwClose(local_res20);
      }
    }
  }
  return uVar2;
}



===== SeSddlSecurityDescriptorFromSDDL @ 140019da4 =====

ulonglong SeSddlSecurityDescriptorFromSDDL(ushort *param_1,undefined8 param_2,longlong *param_3)

{
  ushort uVar1;
  ulonglong uVar2;
  short *_Dst;
  void *_Src;
  
  uVar2 = (ulonglong)*param_1 + 2;
  if (param_1[1] == uVar2) {
    uVar1 = *param_1 >> 1;
    if ((*(short **)(param_1 + 4))[uVar1] == 0) {
      uVar2 = SepSddlSecurityDescriptorFromSDDLString(*(short **)(param_1 + 4),(uint)uVar1,param_3);
      return uVar2;
    }
  }
  _Dst = (short *)ExAllocatePoolWithTag(1,uVar2,0x73546553);
  if (_Dst == (short *)0x0) {
    *param_3 = 0;
    uVar2 = 0xc000009a;
  }
  else {
    memset(_Dst,0,(ulonglong)*param_1 + 2);
    _Src = *(void **)(param_1 + 4);
    memmove(_Dst,_Src,(ulonglong)*param_1);
    _Dst[*param_1 >> 1] = 0;
    uVar2 = SepSddlSecurityDescriptorFromSDDLString(_Dst,(uint)_Src,param_3);
    uVar2 = uVar2 & 0xffffffff;
    ExFreePoolWithTag(_Dst,0);
  }
  return uVar2;
}



===== SepSddlAddAceToAcl @ 140019e84 =====

undefined8
SepSddlAddAceToAcl(longlong *param_1,uint *param_2,undefined8 param_3,undefined8 param_4,
                  undefined4 param_5,int param_6,undefined8 param_7)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  void *_Dst;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  
  pvVar2 = (void *)*param_1;
  uVar1 = *param_2;
  iVar3 = RtlLengthSid(param_7);
  uVar6 = iVar3 + 8 + uVar1;
  _Dst = pvVar2;
  if (*(ushort *)((longlong)pvVar2 + 2) < uVar6) {
    uVar5 = (iVar3 + 8) * param_6 + uVar1;
    _Dst = (void *)ExAllocatePoolWithTag(1,uVar5,0x6c416553);
    if (_Dst == (void *)0x0) {
      return 0xc000009a;
    }
    memset(_Dst,0,(ulonglong)uVar5);
    memmove(_Dst,(void *)*param_1,(ulonglong)uVar1);
    *(short *)((longlong)_Dst + 2) = (short)uVar5;
    ExFreePoolWithTag(pvVar2,0);
    *param_1 = (longlong)_Dst;
  }
  *param_2 = uVar6;
  uVar4 = RtlAddAccessAllowedAce(_Dst,2,param_5,param_7);
  return uVar4;
}



===== SepSddlDaclFromSDDLString @ 140019f84 =====

int SepSddlDaclFromSDDLString
              (short *param_1,undefined8 param_2,undefined4 *param_3,longlong *param_4)

{
  int iVar1;
  longlong lVar2;
  short *psVar3;
  undefined4 uVar4;
  longlong local_res8;
  short *local_res18 [2];
  
  local_res8 = 0;
  local_res18[0] = (short *)0x0;
  *param_4 = 0;
  *param_3 = 0;
  for (; *param_1 == 0x20; param_1 = param_1 + 1) {
  }
  if ((*param_1 != 0x44) || (param_1[1] != 0x3a)) {
    return -0x3ffffff3;
  }
  uVar4 = 0x1008;
  if (param_1[2] != 0x50) {
    uVar4 = 8;
  }
  lVar2 = 4;
  if (param_1[2] != 0x50) {
    lVar2 = 2;
  }
  iVar1 = SepSddlGetAclForString
                    ((wchar_t *)(lVar2 + (longlong)(param_1 + 1)),&local_res8,local_res18);
  if (iVar1 == 0) {
    for (psVar3 = local_res18[0]; *psVar3 == 0x20; psVar3 = psVar3 + 1) {
    }
    if (*psVar3 == 0) {
      *param_4 = local_res8;
      *param_3 = uVar4;
      return 0;
    }
    iVar1 = -0x3ffffff3;
  }
  if (local_res8 != 0) {
    ExFreePoolWithTag(local_res8,0);
  }
  return iVar1;
}



===== SepSddlGetAclForString @ 14001a070 =====

int SepSddlGetAclForString(wchar_t *param_1,longlong *param_2,undefined8 *param_3)

{
  bool bVar1;
  bool bVar2;
  wchar_t wVar3;
  int iVar4;
  int iVar5;
  wchar_t *pwVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined2 *_Dst;
  undefined8 uVar9;
  wchar_t *pwVar10;
  ulonglong uVar11;
  short *psVar12;
  short **ppsVar13;
  undefined8 uVar14;
  uint uVar15;
  uint uVar16;
  undefined **ppuVar17;
  short *local_res8;
  uint local_res10;
  uint local_res18;
  uint local_res20 [2];
  wchar_t *local_58;
  longlong local_50 [2];
  
  *param_2 = 0;
  local_50[0] = 0;
  iVar5 = 0;
  uVar16 = 0;
  pwVar6 = wcschr(param_1,L':');
  *param_3 = pwVar6;
  if (pwVar6 == param_1) {
    return -0x3ffffff3;
  }
  if (pwVar6 == (wchar_t *)0x0) {
    lVar7 = -1;
    do {
      lVar7 = lVar7 + 1;
    } while (param_1[lVar7] != L'\0');
    pwVar6 = param_1 + lVar7;
  }
  else {
    pwVar6 = pwVar6 + -1;
  }
  *param_3 = pwVar6;
  bVar2 = false;
  bVar1 = false;
  uVar14 = 1;
  for (pwVar10 = param_1; pwVar10 < pwVar6; pwVar10 = pwVar10 + 1) {
    if (*pwVar10 == L';') {
      uVar16 = uVar16 + 1;
    }
    else {
      bVar1 = bVar2;
      if (*pwVar10 != L' ') {
        bVar2 = true;
        bVar1 = true;
      }
    }
  }
  local_res18 = uVar16 / 5;
  if ((uVar16 != local_res18 * 5) || ((uVar16 == 0 && (bVar1)))) {
    iVar5 = -0x3ffffff3;
  }
  else {
    if (local_res18 == 0) {
      puVar8 = (undefined8 *)ExAllocatePoolWithTag(1,8);
      *param_2 = (longlong)puVar8;
      if (puVar8 != (undefined8 *)0x0) {
        *puVar8 = 0x80002;
        return 0;
      }
    }
    else {
      uVar16 = local_res18 * 0x30 + 8;
      if (0xffff < uVar16) {
        uVar16 = 0xffff;
      }
      _Dst = (undefined2 *)ExAllocatePoolWithTag(1,uVar16,0x6c416553);
      *param_2 = (longlong)_Dst;
      if (_Dst != (undefined2 *)0x0) {
        local_res20[0] = 8;
        memset(_Dst,0,(ulonglong)uVar16);
        *_Dst = 2;
        _Dst[1] = (short)uVar16;
        *(undefined4 *)(_Dst + 2) = 0;
        local_res10 = 0;
        uVar16 = local_res18;
        uVar15 = 8;
        if (local_res18 != 0) {
          do {
            uVar15 = 0;
            local_res8 = (short *)((ulonglong)local_res8 & 0xffffffff00000000);
            for (; *param_1 == L' '; param_1 = param_1 + 1) {
            }
            if (*param_1 == L'(') {
              do {
                param_1 = param_1 + 1;
              } while (*param_1 == L' ');
            }
            iVar4 = _wcsnicmp(param_1,L"A",1);
            if (iVar4 != 0) {
LAB_14001a3fd:
              iVar5 = -0x3ffffff3;
LAB_14001a3ff:
              lVar7 = *param_2;
              goto LAB_14001a3e5;
            }
            for (pwVar6 = param_1 + 2; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
            }
            if (*pwVar6 != L';') goto LAB_14001a3fd;
            do {
              pwVar6 = pwVar6 + 1;
              wVar3 = *pwVar6;
            } while (wVar3 == L' ');
            if (wVar3 != L';') {
              do {
                uVar11 = 0;
                while (wVar3 == L' ') {
                  pwVar6 = pwVar6 + 1;
                  wVar3 = *pwVar6;
                }
                ppuVar17 = &PTR_u_RC_14000d250;
                do {
                  iVar4 = _wcsnicmp(pwVar6,(wchar_t *)*ppuVar17,(ulonglong)*(uint *)(ppuVar17 + 1));
                  if (iVar4 == 0) {
                    uVar15 = (uint)local_res8 |
                             *(uint *)((longlong)&DAT_14000d258 + uVar11 * 0x10 + 4);
                    local_res8 = (short *)CONCAT44(local_res8._4_4_,uVar15);
                    local_58 = pwVar6 + *(uint *)(&DAT_14000d258 + uVar11 * 2);
                    goto LAB_14001a2ef;
                  }
                  uVar16 = (int)uVar11 + 1;
                  uVar11 = (ulonglong)uVar16;
                  ppuVar17 = ppuVar17 + 2;
                } while (uVar16 < 8);
                local_58 = pwVar6;
                SepSddlParseWideStringUlong((ushort *)pwVar6,&local_58,(uint *)&local_res8);
                if (local_58 == pwVar6) goto LAB_14001a3fd;
                uVar15 = (uint)local_res8;
LAB_14001a2ef:
                wVar3 = *local_58;
                pwVar6 = local_58;
              } while (wVar3 != L';');
              uVar16 = local_res18;
            }
            pwVar6 = pwVar6 + 1;
            if (iVar5 != 0) goto LAB_14001a3ff;
            lVar7 = 2;
            do {
              for (; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
              }
              if (*pwVar6 != L';') {
                iVar5 = -0x3ffffff3;
              }
              pwVar6 = pwVar6 + 1;
              lVar7 = lVar7 + -1;
            } while (lVar7 != 0);
            if (iVar5 != 0) goto LAB_14001a3ff;
            for (; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
            }
            local_res8 = (short *)0x0;
            ppsVar13 = &local_res8;
            uVar9 = SepSddlGetSidForString(pwVar6,local_50,(longlong *)ppsVar13);
            iVar5 = (int)uVar9;
            if (iVar5 != 0) break;
            psVar12 = local_res8;
            if (local_res8 == (short *)0x0) {
LAB_14001a36d:
              iVar5 = -0x3fffff89;
              goto LAB_14001a3ff;
            }
            for (; *psVar12 == 0x20; psVar12 = psVar12 + 1) {
            }
            if (*psVar12 != 0x29) goto LAB_14001a36d;
            param_1 = psVar12 + 1;
            if (local_50[0] != 0) {
              uVar9 = SepSddlAddAceToAcl(param_2,local_res20,ppsVar13,uVar14,uVar15,
                                         uVar16 - local_res10,local_50[0]);
              iVar5 = (int)uVar9;
              if (iVar5 != 0) goto LAB_14001a3ff;
            }
            if (*param_1 == L'(') {
              param_1 = psVar12 + 2;
            }
            local_res10 = local_res10 + 1;
          } while (local_res10 < uVar16);
          uVar15 = local_res20[0];
        }
        lVar7 = *param_2;
        if (iVar5 == 0) {
          *(short *)(lVar7 + 2) = (short)uVar15;
          return 0;
        }
LAB_14001a3e5:
        ExFreePoolWithTag(lVar7,0);
        *param_2 = 0;
        return iVar5;
      }
    }
    iVar5 = -0x3fffff66;
  }
  return iVar5;
}



===== SepSddlGetSidForString @ 14001a42c =====

undefined8 SepSddlGetSidForString(wchar_t *param_1,undefined8 *param_2,longlong *param_3)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint *puVar5;
  uint uVar6;
  ulonglong uVar7;
  
  uVar4 = 0;
  puVar5 = &DAT_14000d3a4;
  uVar7 = 0;
  do {
    iVar2 = _wcsnicmp(param_1,(wchar_t *)(&DAT_14000d39c + uVar7 * 0x18),(ulonglong)*puVar5);
    if (iVar2 == 0) {
      iVar2 = *(int *)(&DAT_14000d398 + uVar7 * 0x18);
      uVar6 = (&DAT_14000d3a4)[uVar7 * 6];
      *param_3 = (longlong)(param_1 + uVar6);
      if (iVar2 == 1) {
        cVar1 = IoIsWdmVersionAvailable(1,CONCAT71((int7)((ulonglong)(param_1 + uVar6) >> 8),0x20));
        if (cVar1 != '\0') goto LAB_14001a4bc;
      }
      else {
LAB_14001a4bc:
        uVar4 = *(undefined8 *)
                 (*(longlong *)(&DAT_14000d390 + uVar7 * 0x18) + *(longlong *)SeExports_exref);
      }
      uVar3 = 0;
      goto LAB_14001a4d1;
    }
    uVar6 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
    puVar5 = puVar5 + 6;
  } while (uVar6 < 0xe);
  uVar3 = 0xc0000073;
LAB_14001a4d1:
  *param_2 = uVar4;
  return uVar3;
}



===== SepSddlParseWideStringUlong @ 14001a4f8 =====

undefined8 SepSddlParseWideStringUlong(ushort *param_1,undefined8 *param_2,uint *param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  short sVar5;
  uint uVar6;
  int iVar7;
  ushort *puVar8;
  
  uVar1 = *param_1;
  uVar6 = (uint)uVar1;
  *param_3 = 0;
  *param_2 = param_1;
  if (uVar1 == 0x30) {
    if ((param_1[1] - 0x58 & 0xffdf) != 0) {
LAB_14001a57b:
      iVar7 = 10;
      uVar4 = 0;
      puVar8 = param_1;
      goto LAB_14001a559;
    }
    param_1 = param_1 + 2;
    uVar6 = (uint)*param_1;
  }
  else if ((ushort)(uVar1 - 0x30) < 10) goto LAB_14001a57b;
  iVar7 = 0x10;
  puVar8 = param_1;
  uVar4 = 0;
  if ((short)uVar6 == 0) {
    return 0;
  }
LAB_14001a559:
  do {
    sVar5 = (short)uVar6;
    if ((ushort)(sVar5 - 0x30U) < 10) {
      iVar2 = uVar6 - 0x30;
    }
    else {
      if (iVar7 != 0x10) break;
      if ((ushort)(sVar5 - 0x41U) < 6) {
        iVar2 = uVar6 - 0x37;
      }
      else {
        if (5 < (ushort)(sVar5 - 0x61U)) break;
        iVar2 = uVar6 - 0x57;
      }
    }
    uVar3 = iVar7 * uVar4 + iVar2;
    if (uVar3 < uVar4) {
      return 0;
    }
    param_1 = param_1 + 1;
    uVar6 = (uint)*param_1;
    uVar4 = uVar3;
  } while (*param_1 != 0);
  if (param_1 == puVar8) {
    return 0;
  }
  *param_2 = param_1;
  *param_3 = uVar4;
  return 1;
}



===== SepSddlSecurityDescriptorFromSDDLString @ 14001a604 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong SepSddlSecurityDescriptorFromSDDLString(short *param_1,uint param_2,longlong *param_3)

{
  ushort uVar1;
  uint uVar2;
  code *pcVar3;
  ulonglong uVar4;
  void *_Dst;
  wchar_t *pwVar5;
  uint local_res10 [4];
  undefined4 local_res20 [2];
  longlong local_58 [3];
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  
  pwVar5 = L"SeConvertStringSecurityDescriptorToSecurityDescriptor";
  local_58[1] = 0;
  local_58[2] = 0;
  local_res10[0] = param_2;
  RtlInitUnicodeString(local_58 + 1);
  pcVar3 = (code *)MmGetSystemRoutineAddress(local_58 + 1);
  if (pcVar3 != (code *)0x0) {
    uVar4 = (*pcVar3)(param_1,1,param_3);
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    *(ushort *)(*param_3 + 2) = *(ushort *)(*param_3 + 2) | 8;
    return uVar4;
  }
  local_res20[0] = 0;
  local_res10[0] = 0;
  local_58[0] = 0;
  _Dst = (void *)0x0;
  *param_3 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_20 = 0;
  local_30 = 0;
  uStack_28 = 0;
  uVar2 = SepSddlDaclFromSDDLString(param_1,pwVar5,local_res20,local_58);
  if (-1 < (int)uVar2) {
    RtlCreateSecurityDescriptor(&local_40,1);
    RtlSetDaclSecurityDescriptor(&local_40,1,local_58[0],0);
    uVar1 = local_40._2_2_ | (ushort)local_res20[0];
    local_40._0_4_ = CONCAT22(uVar1,(undefined2)local_40);
    RtlAbsoluteToSelfRelativeSD(&local_40,0,local_res10);
    _Dst = (void *)ExAllocatePoolWithTag(1,local_res10[0],0x64536553);
    if (_Dst == (void *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      memset(_Dst,0,(ulonglong)local_res10[0]);
      uVar2 = RtlAbsoluteToSelfRelativeSD(&local_40,_Dst,local_res10);
      if (-1 < (int)uVar2) {
        ExFreePoolWithTag(local_58[0],0);
        *param_3 = (longlong)_Dst;
        goto LAB_14001a749;
      }
    }
  }
  if (local_58[0] != 0) {
    ExFreePoolWithTag(local_58[0],0);
  }
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
LAB_14001a749:
  return (ulonglong)uVar2;
}



===== PiRegStateOpenClassKey @ 14001a7a8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PiRegStateOpenClassKey
                    (undefined4 *param_1,undefined8 param_2,int param_3,undefined4 *param_4,
                    undefined8 *param_5)

{
  undefined8 uVar1;
  uint uVar2;
  ulonglong uVar3;
  wchar_t *pwVar4;
  undefined4 uVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_b8;
  int local_b4;
  undefined8 local_b0;
  undefined8 local_a8 [2];
  wchar_t local_98 [38];
  undefined2 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  local_b0 = 0;
  local_a8[0] = 0;
  *param_5 = 0;
  local_b8 = 0;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  local_b4 = param_3;
  uVar3 = CmRegUtilOpenExistingWstrKey(0,0x14000b690,0x20019,&local_b0);
  if (-1 < (int)uVar3) {
    uVar5 = *param_1;
    pwVar4 = L"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}";
    _snwprintf(local_98,0x27,L"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}");
    uVar1 = local_b0;
    local_4c = 0;
    if (local_b4 == 0) {
      uVar2 = CmRegUtilOpenExistingWstrKey(local_b0,(longlong)local_98,0xf003f,local_a8);
      uVar5 = 2;
    }
    else {
      uVar3 = CmRegUtilCreateWstrKey(local_b0,(longlong)local_98,pwVar4,uVar5,0,&local_b8,local_a8);
      uVar2 = (uint)uVar3;
      uVar5 = local_b8;
    }
    uVar3 = (ulonglong)uVar2;
    ZwClose(uVar1);
    if ((-1 < (int)uVar2) && (*param_5 = local_a8[0], param_4 != (undefined4 *)0x0)) {
      *param_4 = uVar5;
    }
  }
  return uVar3;
}



===== PiRegStateReadStackCreationSettingsFromKey @ 14001a944 =====

ulonglong PiRegStateReadStackCreationSettingsFromKey
                    (undefined8 param_1,uint *param_2,uint *param_3,undefined8 param_4)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  char local_res10 [8];
  uint local_res18 [2];
  longlong local_res20;
  longlong local_58;
  ushort local_50 [12];
  
  param_2[0] = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  local_res20 = 0;
  local_res18[0] = 0;
  local_res10[0] = '\0';
  local_58 = 0;
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  uVar2 = WdmlibRtlInitUnicodeStringEx((short *)local_50,0x14000b610);
  uVar1 = (uint)uVar2;
  lVar4 = 0;
  if (((int)uVar1 < 0) ||
     (uVar1 = CmRegUtilUcValueGetFullBuffer(param_1,local_50,param_3,param_4,&local_58),
     lVar4 = local_58, (int)uVar1 < 0)) {
    uVar5 = (ulonglong)uVar1;
    if (uVar1 == 0xc0000034) {
      uVar5 = 0;
    }
  }
  else {
    param_3 = (uint *)0x1;
    uVar1 = SeCaptureSecurityDescriptor
                      ((ulonglong)*(uint *)(local_58 + 8) + local_58,0,1,1,&local_res20);
    uVar5 = (ulonglong)uVar1;
  }
  if (lVar4 != 0) {
    ExFreePoolWithTag(lVar4,0);
  }
  if (-1 < (int)uVar5) {
    if (local_res20 != 0) {
      param_3 = local_res18;
      uVar3 = SeUtilSecurityInfoFromSecurityDescriptor(local_res20,local_res10,param_3);
      uVar5 = uVar3 & 0xffffffff;
      if ((int)uVar3 < 0) goto LAB_14001aac3;
      if (local_res10[0] == '\0') {
        *param_2 = *param_2 | 2;
        *(longlong *)(param_2 + 2) = local_res20;
      }
      else {
        ExFreePoolWithTag(local_res20,0);
      }
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x14000b628,param_3,param_2 + 1);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_14001aac3;
    }
    else {
      *param_2 = *param_2 | 1;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x14000b640,param_3,param_2 + 4);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_14001aac3;
    }
    else {
      *param_2 = *param_2 | 4;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x14000b670,param_3,param_2 + 5);
    uVar5 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      *param_2 = *param_2 | 8;
      return uVar5;
    }
    if ((int)uVar3 == -0x3fffffcc) {
      return 0;
    }
  }
LAB_14001aac3:
  if (*(longlong *)(param_2 + 2) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 2),0);
  }
  param_2[0] = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  return uVar5;
}



===== PpRegStateReadCreateClassCreationSettings @ 14001ab08 =====

ulonglong PpRegStateReadCreateClassCreationSettings
                    (undefined4 *param_1,longlong param_2,uint *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  uint *puVar5;
  undefined8 *puVar6;
  ushort *puVar7;
  int local_res18 [2];
  undefined8 local_res20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  *param_3 = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  param_3[1] = 0;
  param_3[4] = 0;
  param_3[5] = 0;
  local_res18[0] = 0;
  local_res20 = 0;
  local_18 = 0;
  uVar2 = PiRegStateOpenClassKey(param_1,param_2,1,local_res18,&local_res20);
  uVar4 = local_res20;
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  if (local_res18[0] == 2) {
    puVar6 = &local_18;
    puVar5 = (uint *)0x20019;
    uVar1 = CmRegUtilOpenExistingWstrKey(local_res20,0x14000b5b0,0x20019,puVar6);
    ZwClose(local_res20);
    if ((int)uVar1 < 0) {
      if (uVar1 == 0xc0000034) {
        return 0;
      }
      return (ulonglong)uVar1;
    }
    uVar2 = PiRegStateReadStackCreationSettingsFromKey(local_18,param_3,puVar5,puVar6);
    uVar2 = uVar2 & 0xffffffff;
    uVar4 = local_18;
  }
  else {
    puVar7 = (ushort *)(*(longlong *)(param_2 + 0x30) + 0x18);
    if (puVar7 == (ushort *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      local_18 = 0;
      uStack_10 = 0;
      uVar3 = WdmlibRtlInitUnicodeStringEx((short *)&local_18,0x14000b5c8);
      uVar2 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        uVar1 = CmRegUtilUcValueSetUcString(uVar4,&local_18,puVar7);
        uVar2 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          local_res18[0] = 0x31;
          uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x14000b5d8,(longlong)local_res18);
          uVar2 = (ulonglong)uVar1;
          if (-1 < (int)uVar1) {
            uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x14000b5f8,(longlong)local_res18);
            uVar2 = (ulonglong)uVar1;
          }
        }
      }
    }
  }
  ZwClose(uVar4);
  return uVar2;
}



===== PpRegStateUpdateStackCreationSettings @ 14001ac6c =====

ulonglong PpRegStateUpdateStackCreationSettings(undefined4 *param_1,longlong param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined *puVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined *local_res18;
  undefined8 local_res20;
  undefined8 local_38;
  short local_30 [12];
  
  uVar8 = 0;
  local_res18 = (undefined *)0x0;
  uVar7 = 0;
  local_38 = 0;
  local_res20 = 0;
  uVar4 = PiRegStateOpenClassKey(param_1,param_2,0,(undefined4 *)0x0,&local_res20);
  uVar2 = (undefined4)uVar8;
  if (-1 < (int)uVar4) {
    puVar6 = &PiRegStateSysAllInherittedSecurityDescriptor;
    if (PiRegStateDiscriptor == 0) {
      uVar8 = CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
      uVar2 = (undefined4)uVar8;
      uVar7 = 1;
      iVar1 = SeCaptureSecurityDescriptor
                        (&PiRegStateSysAllInherittedSecurityDescriptor,0,1,uVar8,&local_res18);
      if (iVar1 < 0) {
        PiRegStateDiscriptor = 2;
      }
      else {
        PiRegStateDiscriptor = 1;
        ExFreePoolWithTag(local_res18,0);
      }
    }
    if (PiRegStateDiscriptor != 1) {
      puVar6 = (undefined *)0x0;
    }
    local_res18 = puVar6;
    uVar5 = CmRegUtilCreateWstrKey
                      (local_res20,0x14000b5b0,uVar7,uVar2,puVar6,(undefined4 *)0x0,&local_38);
    uVar4 = uVar5 & 0xffffffff;
    ZwClose(local_res20);
    if (-1 < (int)uVar5) {
      uVar2 = RtlLengthSecurityDescriptor(*(undefined8 *)(param_2 + 8));
      uVar7 = *(undefined8 *)(param_2 + 8);
      local_30[0] = 0;
      local_30[1] = 0;
      local_30[2] = 0;
      local_30[3] = 0;
      local_30[4] = 0;
      local_30[5] = 0;
      local_30[6] = 0;
      local_30[7] = 0;
      uVar5 = WdmlibRtlInitUnicodeStringEx(local_30,0x14000b610);
      uVar4 = uVar5 & 0xffffffff;
      if (-1 < (int)uVar5) {
        uVar3 = ZwSetValueKey(local_38,local_30,0,3,uVar7,uVar2);
        uVar4 = (ulonglong)uVar3;
      }
      ZwClose(local_38);
    }
  }
  return uVar4;
}



===== SeUtilSecurityInfoFromSecurityDescriptor @ 14001add4 =====

undefined8
SeUtilSecurityInfoFromSecurityDescriptor(undefined8 param_1,undefined1 *param_2,uint *param_3)

{
  undefined8 uVar1;
  uint uVar2;
  undefined1 local_res10 [8];
  char local_res20 [8];
  longlong local_28 [2];
  
  local_28[0] = 0;
  local_28[1] = 0;
  *param_3 = 0;
  *param_2 = 0;
  local_res10[0] = 0;
  local_res20[0] = '\0';
  uVar1 = RtlGetOwnerSecurityDescriptor(param_1,local_28,local_res10);
  if (-1 < (int)uVar1) {
    uVar2 = (uint)(local_28[0] != 0);
    uVar1 = RtlGetGroupSecurityDescriptor(param_1,local_28,local_res10);
    if (-1 < (int)uVar1) {
      if (local_28[0] != 0) {
        uVar2 = uVar2 | 2;
      }
      uVar1 = RtlGetSaclSecurityDescriptor(param_1,local_res20,local_28 + 1,local_res10);
      if (-1 < (int)uVar1) {
        if (local_res20[0] != '\0') {
          uVar2 = uVar2 | 8;
        }
        uVar1 = RtlGetDaclSecurityDescriptor(param_1,local_res20,local_28 + 1,local_res10);
        if (-1 < (int)uVar1) {
          if (local_res20[0] != '\0') {
            uVar2 = uVar2 | 4;
          }
          *param_2 = local_res10[0];
          uVar1 = 0;
          *param_3 = uVar2;
        }
      }
    }
  }
  return uVar1;
}



===== CmRegUtilCreateWstrKey @ 14001aed0 =====

ulonglong CmRegUtilCreateWstrKey
                    (undefined8 param_1,longlong param_2,undefined8 param_3,undefined4 param_4,
                    undefined8 param_5,undefined4 *param_6,undefined8 *param_7)

{
  uint uVar1;
  ulonglong uVar2;
  undefined4 local_res20 [2];
  undefined8 local_58;
  short local_50 [8];
  undefined8 local_40;
  undefined8 local_38;
  short *local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined8 local_18;
  
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  local_res20[0] = param_4;
  uVar2 = WdmlibRtlInitUnicodeStringEx(local_50,param_2);
  if (-1 < (int)uVar2) {
    local_24 = 0;
    local_30 = local_50;
    local_res20[0] = 0;
    local_58 = 0;
    local_18 = 0;
    local_20 = param_5;
    local_40 = 0x30;
    local_28 = 0x240;
    local_38 = param_1;
    uVar1 = ZwCreateKey(&local_58,0xf003f,&local_40,0,0,0,local_res20);
    uVar2 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      local_58 = 0;
      local_res20[0] = 0;
    }
    *param_7 = local_58;
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = local_res20[0];
    }
  }
  return uVar2;
}



===== CmRegUtilOpenExistingWstrKey @ 14001afa0 =====

void CmRegUtilOpenExistingWstrKey
               (undefined8 param_1,longlong param_2,uint param_3,undefined8 *param_4)

{
  int iVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 local_58;
  short local_50 [8];
  undefined8 local_40;
  undefined8 local_38;
  short *local_30;
  undefined4 local_28;
  undefined4 local_24;
  
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  uVar3 = (ulonglong)param_3;
  uVar2 = WdmlibRtlInitUnicodeStringEx(local_50,param_2);
  if (-1 < (int)uVar2) {
    local_24 = 0;
    local_30 = local_50;
    local_58 = 0;
    *param_4 = 0;
    local_40 = 0x30;
    local_28 = 0x240;
    local_38 = param_1;
    iVar1 = ZwOpenKey(&local_58,uVar3 & 0xffffffff,&local_40);
    if (-1 < iVar1) {
      *param_4 = local_58;
    }
  }
  return;
}



===== CmRegUtilUcValueGetFullBuffer @ 14001b034 =====

int CmRegUtilUcValueGetFullBuffer
              (undefined8 param_1,ushort *param_2,undefined8 param_3,undefined8 param_4,
              undefined8 *param_5)

{
  int iVar1;
  void *_Dst;
  uint uVar2;
  uint local_res20 [2];
  
  local_res20[0] = 0;
  uVar2 = *param_2 + 0x1f & 0xfffffff8;
  *param_5 = 0;
  _Dst = (void *)ExAllocatePoolWithTag(0x200,uVar2,0x62527050);
  if (_Dst == (void *)0x0) {
    return -0x3fffff66;
  }
  memset(_Dst,0,(ulonglong)uVar2);
  iVar1 = ZwQueryValueKey(param_1,param_2,1,_Dst,uVar2,local_res20);
  if (iVar1 < 0) {
    ExFreePoolWithTag(_Dst,0);
    if ((iVar1 != -0x7ffffffb) && (iVar1 != -0x3fffffdd)) {
      return iVar1;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,local_res20[0],0x62527050);
    if (_Dst == (void *)0x0) {
      return -0x3fffff66;
    }
    memset(_Dst,0,(ulonglong)local_res20[0]);
    iVar1 = ZwQueryValueKey(param_1,param_2,1,_Dst,local_res20[0],local_res20);
    if (iVar1 < 0) goto LAB_14001b16c;
  }
  if (*(int *)((longlong)_Dst + 4) == 3) {
    *param_5 = _Dst;
    return 0;
  }
  iVar1 = -0x3fffffdc;
LAB_14001b16c:
  ExFreePoolWithTag(_Dst,0);
  return iVar1;
}



===== CmRegUtilUcValueSetUcString @ 14001b1b0 =====

undefined4 CmRegUtilUcValueSetUcString(undefined8 param_1,undefined8 param_2,ushort *param_3)

{
  size_t _Size;
  ushort uVar1;
  undefined4 uVar2;
  ushort local_28;
  short local_26;
  undefined4 local_24;
  void *local_20;
  
  uVar1 = *param_3;
  local_24 = 0;
  if ((ulonglong)param_3[1] - (ulonglong)uVar1 < 2) {
    _Size = (ulonglong)uVar1 + 2;
    local_26 = uVar1 + 2;
    local_20 = (void *)ExAllocatePoolWithTag(1,_Size,0x63557050);
    if (local_20 == (void *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      memset(local_20,0,_Size);
      local_28 = *param_3;
      memmove(local_20,*(void **)(param_3 + 4),(ulonglong)local_28);
      *(undefined2 *)((longlong)local_20 + (ulonglong)(local_28 >> 1) * 2) = 0;
      uVar2 = ZwSetValueKey(param_1,param_2,0,1,local_20,local_28 + 2);
      RtlFreeUnicodeString(&local_28);
    }
  }
  else {
    *(undefined2 *)(*(longlong *)(param_3 + 4) + (ulonglong)(uVar1 >> 1) * 2) = 0;
    uVar2 = ZwSetValueKey(param_1,param_2,0,1,*(undefined8 *)(param_3 + 4),*param_3 + 2);
  }
  return uVar2;
}



===== CmRegUtilWstrValueGetDword @ 14001b2fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
CmRegUtilWstrValueGetDword
          (undefined8 param_1,longlong param_2,undefined8 param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 *local_40;
  undefined4 local_38 [2];
  short local_30 [8];
  undefined1 local_20 [4];
  int local_1c;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  local_30[4] = 0;
  local_30[5] = 0;
  local_30[6] = 0;
  local_30[7] = 0;
  uVar1 = WdmlibRtlInitUnicodeStringEx(local_30,param_2);
  uVar2 = 0;
  if (-1 < (int)uVar1) {
    local_40 = local_38;
    local_38[0] = 0;
    local_48 = 0x10;
    uVar1 = ZwQueryValueKey(param_1,local_30,2,local_20);
    if (-1 < (int)uVar1) {
      if (local_1c == 4) {
        uVar2 = local_14;
      }
      else {
        uVar1 = 0xc0000024;
      }
    }
    *param_4 = uVar2;
  }
  return uVar1;
}



===== CmRegUtilWstrValueSetWstrString @ 14001b3a0 =====

void CmRegUtilWstrValueSetWstrString(undefined8 param_1,longlong param_2,longlong param_3)

{
  undefined8 uVar1;
  ushort local_28 [8];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = 0;
  uVar1 = WdmlibRtlInitUnicodeStringEx((short *)local_28,param_3);
  if (-1 < (int)uVar1) {
    uVar1 = WdmlibRtlInitUnicodeStringEx((short *)&local_18,param_2);
    if (-1 < (int)uVar1) {
      CmRegUtilUcValueSetUcString(param_1,&local_18,local_28);
    }
  }
  return;
}



===== entry @ 14001c010 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 14001c044 =====

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



===== GetConfigDword @ 14001c078 =====

void GetConfigDword(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  int local_res20 [2];
  longlong local_28 [4];
  
  local_res20[0] = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  RtlInitUnicodeString(local_28 + 1);
  NdisReadConfiguration(local_res20,local_28,param_1,local_28 + 1,0);
  if (local_res20[0] == 0) {
    *param_3 = *(undefined4 *)(local_28[0] + 8);
  }
  return;
}



===== GetRegistryParameters @ 14001c0f8 =====

void GetRegistryParameters(undefined8 param_1)

{
  int local_res8 [2];
  undefined8 local_res10;
  longlong local_res18 [2];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 local_28;
  
  local_res18[0] = 0;
  local_res10 = 0;
  local_34 = 0;
  local_28 = 0;
  local_48 = 0;
  uStack_40 = 0;
  RtlInitUnicodeString(&local_48,L"Parameters");
  local_38 = 0x1801a9;
  local_30 = param_1;
  local_res8[0] = NdisOpenConfigurationEx(&local_38,local_res18);
  if (local_res8[0] == 0) {
    NdisOpenConfigurationKeyByName(local_res8,local_res18[0],&local_48,&local_res10);
    if (-1 < local_res8[0]) {
      local_res8[0] = GetConfigDword(local_res10,L"TxRate",(undefined4 *)(DeviceExtension + 0x34));
      if (local_res8[0] < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                   &WPP_e20899a35fcb3761bec7dbafe28681f5_Traceguids,local_res8[0]);
        }
      }
      else {
        *(uint *)(DeviceExtension + 0x30) = *(uint *)(DeviceExtension + 0x30) | 1;
      }
      local_res8[0] = GetConfigDword(local_res10,L"RxRate",(undefined4 *)(DeviceExtension + 0x38));
      if (local_res8[0] < 0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_14001c2e0;
        if (4 < (byte)WPP_GLOBAL_Control[0x29]) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                   &WPP_e20899a35fcb3761bec7dbafe28681f5_Traceguids,local_res8[0]);
        }
      }
      else {
        *(uint *)(DeviceExtension + 0x30) = *(uint *)(DeviceExtension + 0x30) | 2;
      }
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (4 < (byte)WPP_GLOBAL_Control[0x29]) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                   &WPP_e20899a35fcb3761bec7dbafe28681f5_Traceguids,
                   *(undefined4 *)(DeviceExtension + 0x34));
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                   &WPP_e20899a35fcb3761bec7dbafe28681f5_Traceguids,
                   *(undefined4 *)(DeviceExtension + 0x38));
        }
      }
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_e20899a35fcb3761bec7dbafe28681f5_Traceguids,local_res8[0]);
    }
    local_res8[0] = -0x3fffffff;
  }
LAB_14001c2e0:
  if (local_res18[0] != 0) {
    NdisCloseConfiguration();
  }
  return;
}



===== InitNDISProxy @ 14001c304 =====

ulonglong InitNDISProxy(void)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined1 local_78 [16];
  code *local_68;
  code *local_60;
  code *local_58;
  code *local_50;
  code *local_48;
  code *local_40;
  code *local_30;
  code *local_20;
  code *local_18;
  
  memset(&local_88,0,0x80);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_e20899a35fcb3761bec7dbafe28681f5_Traceguids);
  }
  local_88 = 0x800295;
  local_68 = PxSetOptionsHandler;
  local_84 = 0x11e06;
  local_60 = PxCoBindAdapterEx;
  local_80 = 0xc0000000;
  local_58 = PxCoUnbindAdapterEx;
  local_50 = PxCoOpenAdaperCompleteEx;
  local_48 = PxCoCloseAdapterCompleteEx;
  local_40 = PxCoNetPnPEvent;
  local_30 = PxCoOidRequestComplete;
  local_20 = PxReceiveNetBufferLists;
  local_18 = PxSendNetBufferListsComplete;
  RtlInitUnicodeString(local_78,L"NDProxy");
  NdisInitializeEvent(DeviceExtension + 0x40);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
            &WPP_e20899a35fcb3761bec7dbafe28681f5_Traceguids);
  }
  uVar1 = NdisRegisterProtocolDriver(0,&local_88,DeviceExtension + 0x18);
  if ((int)uVar1 == 0) {
    GetRegistryParameters(*(undefined8 *)(DeviceExtension + 0x18));
    uVar2 = NdisSetEvent(DeviceExtension + 0x40);
    uVar1 = CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar1 = WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                      &WPP_e20899a35fcb3761bec7dbafe28681f5_Traceguids);
    }
    uVar1 = uVar1 & 0xffffffffffffff00;
  }
  return uVar1;
}



===== DriverEntry @ 14001c4b8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DriverEntry(longlong param_1)

{
  void *pvVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  wchar_t *pwVar6;
  undefined8 local_18;
  undefined8 uStack_10;
  
  uVar3 = 0;
  _DAT_14000d748 = 1;
  local_18 = 0;
  uStack_10 = 0;
  _WPP_MAIN_CB = 0;
  DAT_14000d728 = &WPP_ThisDir_CTLGUID_NdProxyWpp;
  DAT_14000d730 = 0;
  _DAT_14000d740 = 0;
  WppLoadTracingSupport();
  _DAT_14000d740 = 0;
  WppInitKm();
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_49acb68b66733a55de6af06c8932e04d_Traceguids);
  }
  wil_InitializeFeatureStaging();
  ExInitializeNPagedLookasideList(&ProviderEventLookaside,0,0,0x200,0x40,0x315850,0);
  ExInitializeNPagedLookasideList(&VcLookaside,0,0,0x200,0x218,0x695850,0);
  pwVar6 = L"\\Device\\NDProxy";
  _TspCB = 0;
  DAT_14000d828 = (undefined8 *)0x0;
  _DAT_14000d850 = 0;
  DAT_14000d830 = (undefined8 *)0x0;
  _DAT_14000d838 = 0;
  _DAT_14000d840 = 0;
  _DAT_14000d848 = 0;
  TspEventList = (undefined8 *)0x0;
  DAT_14000d768 = (undefined8 *)0x0;
  _DAT_14000d770 = 0;
  DAT_14000d778 = 0;
  _DAT_14000d780 = 0;
  _DAT_14000d788 = 0;
  _VcTable = 0;
  _DAT_14000d7a8 = 0;
  DAT_14000d7b0 = 0;
  DAT_14000d7b8 = 0;
  DAT_14000d7c0 = 0;
  DAT_14000d7c8 = 0;
  _LineTable = 0;
  _DAT_14000d7e8 = 0;
  DAT_14000d7f0 = 0;
  DAT_14000d7f8 = 0;
  RtlInitUnicodeString(&local_18);
  iVar2 = WdmlibIoCreateDeviceSecure(param_1,pwVar6,&local_18);
  pvVar1 = pvRam0000000000000040;
  if (iVar2 < 0) {
    if (g_wil_details_featureChangeNotification != 0) {
      RtlUnregisterFeatureConfigurationChangeNotification();
      g_wil_details_featureChangeNotification = 0;
    }
    if (g_wil_details_featureUsageProvider != 0) {
      RtlUnregisterFeatureUsageProvider();
      g_wil_details_featureUsageProvider = 0;
    }
    g_wil_details_isFeatureStagingInitialized = 0;
    uVar3 = 0xc0000001;
  }
  else {
    DeviceExtension = pvRam0000000000000040;
    memset(pvRam0000000000000040,0,0x68);
    *(longlong *)((longlong)pvVar1 + 8) = param_1;
    KeInitializeSpinLock((longlong)pvVar1 + 0x58);
    lVar4 = (longlong)DeviceExtension + 0x20;
    *(longlong *)((longlong)DeviceExtension + 0x28) = lVar4;
    *(longlong *)lVar4 = lVar4;
    KeInitializeSpinLock(&DAT_14000d848);
    DAT_14000d830 = &DAT_14000d828;
    DAT_14000d828 = &DAT_14000d828;
    _DAT_14000d838 = _DAT_14000d838 & 0xffffffff00000000;
    _TspCB = 0x100000001;
    KeInitializeSpinLock(&DAT_14000d780);
    pvVar1 = DeviceExtension;
    DAT_14000d768 = &TspEventList;
    TspEventList = &TspEventList;
    *(undefined8 *)((longlong)DeviceExtension + 0x10) = 0;
    *(code **)(param_1 + 0x68) = PxUnload;
    *(code **)(param_1 + 0x70) = PxIOCreate;
    *(code **)(param_1 + 0x80) = PxIOClose;
    *(code **)(param_1 + 0xe0) = PxIODispatch;
    *(code **)(param_1 + 0x100) = PxIOCleanup;
    *(undefined8 *)(param_1 + 0x50) = 0;
    uRam0000000000000030 = uRam0000000000000030 | 0x10;
    *(undefined8 *)((longlong)pvVar1 + 0x10) = 0;
    uVar5 = InitNDISProxy();
    if ((char)uVar5 == '\0') {
      uVar3 = 0xc0000001;
      PxUnload();
    }
  }
  return uVar3;
}



===== wil_InitializeFeatureStaging @ 14001c7e0 =====

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
      if (*ppuVar3 != (undefined *)0x0) goto LAB_14001c867;
    }
LAB_14001c8a1:
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
LAB_14001c867:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14001c8a1;
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
    goto LAB_14001c8a1;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_14000c687 < ppuVar3) goto LAB_14001c8a1;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14001c867;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14001c8f4 =====

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
            if (&UNK_14000c687 < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_14001c9de;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_14001c9de;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_14001c9de:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_14000c687 < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


