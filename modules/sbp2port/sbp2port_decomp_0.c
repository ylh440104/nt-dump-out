
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



===== Feature_4206787897__private_IsEnabledDeviceUsageNoInline @ 140001030 =====

ulonglong Feature_4206787897__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)(uint)Feature_4206787897__private_featureState;
  if (((uint)Feature_4206787897__private_featureState & 0x10) == 0) {
    uVar1 = Feature_4206787897__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)((uint)Feature_4206787897__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_4206787897__private_IsEnabledFallback @ 140001068 =====

void Feature_4206787897__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_4206787897__private_descriptor);
  return;
}



===== RtlStringCbPrintfW @ 140001084 =====

undefined8
RtlStringCbPrintfW(wchar_t *param_1,ulonglong param_2,wchar_t *param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 local_res20;
  
  uVar2 = param_2 >> 1;
  if (uVar2 - 1 < 0x7fffffff) {
    uVar2 = uVar2 - 1;
    uVar3 = 0;
    local_res20 = param_4;
    iVar1 = _vsnwprintf(param_1,uVar2,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (uVar2 < (ulonglong)(longlong)iVar1)) {
      uVar3 = 0x80000005;
    }
    else if ((longlong)iVar1 != uVar2) {
      return 0;
    }
    param_1[uVar2] = L'\0';
  }
  else {
    uVar3 = 0xc000000d;
    if (uVar2 != 0) {
      *param_1 = L'\0';
    }
  }
  return uVar3;
}



===== Sbp2CleanDeviceExtension @ 140001100 =====

ulonglong Sbp2CleanDeviceExtension(longlong param_1,byte param_2,undefined1 param_3)

{
  uint uVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong *plVar5;
  code *pcVar6;
  undefined1 uVar7;
  int iVar8;
  ulonglong uVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong lVar12;
  undefined8 uVar13;
  
  plVar2 = *(longlong **)(param_1 + 0x40);
  if ((int)plVar2[2] == 0x4f445073) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qDd(WPP_GLOBAL_Control[3],0x1f,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,plVar2,
                 (char)*(undefined4 *)((longlong)plVar2 + 0x14),param_2);
    }
    uVar13 = 0x436c6e50;
    lVar11 = *(longlong *)(plVar2[10] + 0x40);
    Sbp2AddLog((longlong)plVar2,1,0x436c6e50,(ulonglong)param_2,lVar11);
    plVar10 = (longlong *)0x0;
    lVar12 = *(longlong *)(lVar11 + 0xa8);
    while (lVar12 != 0) {
      if (lVar12 == param_1) {
        uVar9 = (ulonglong)*(uint *)((longlong)plVar2 + 0x14);
        if ((*(uint *)((longlong)plVar2 + 0x14) & 1) != 0) {
          KeCancelTimer(plVar2 + 0xbe);
          plVar10 = (longlong *)0xc0000240;
          uVar9 = CleanupOrbList(plVar2,-0x3ffffdc0);
        }
        if (plVar2[0x41] != 0) {
          plVar10 = plVar2 + 0x3e;
          uVar9 = FreeAddressRange((longlong)plVar2,(longlong)plVar10);
        }
        if (param_2 != 0) {
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_qDdd(WPP_GLOBAL_Control[3],plVar10,uVar13,plVar2,
                        (char)*(undefined4 *)((longlong)plVar2 + 0x14),param_2,param_3);
          }
          uVar9 = (ulonglong)*(uint *)((longlong)plVar2 + 0x14);
          if ((*(uint *)((longlong)plVar2 + 0x14) & 3) != 0) {
            FreeAddressRange((longlong)plVar2,(longlong)(plVar2 + 0x89));
            FreeAddressRange((longlong)plVar2,(longlong)(plVar2 + 0x90));
            uVar9 = FreeAddressRange((longlong)plVar2,(longlong)(plVar2 + 0x7e));
            LOCK();
            lVar11 = plVar2[0x1a];
            plVar2[0x1a] = 0;
            UNLOCK();
            if (lVar11 != 0) {
              *(undefined4 *)(lVar11 + 0x30) = 0xc000000e;
              IoReleaseRemoveLockEx(plVar2 + 3,lVar11,0x20);
              uVar9 = IofCompleteRequest(lVar11,0);
            }
            LOCK();
            lVar11 = plVar2[0x1b];
            plVar2[0x1b] = 0;
            UNLOCK();
            if (lVar11 != 0) {
              *(undefined4 *)(lVar11 + 0x30) = 0xc000000e;
              IoReleaseRemoveLockEx(plVar2 + 3,lVar11,0x20);
              uVar9 = IofCompleteRequest(lVar11,0);
            }
            LOCK();
            lVar11 = plVar2[0x1c];
            plVar2[0x1c] = 0;
            UNLOCK();
            if (lVar11 != 0) {
              *(undefined4 *)(lVar11 + 0x30) = 0xc000000e;
              IoReleaseRemoveLockEx(plVar2 + 3,lVar11,0x20);
              uVar9 = IofCompleteRequest(lVar11,0);
            }
            if (plVar2[0x30] != 0) {
              IoDeleteSymbolicLink(plVar2 + 0x2f);
              uVar9 = ExFreePoolWithTag(plVar2[0x30],0x6c536253);
              *(undefined2 *)(plVar2 + 0x2f) = 0;
              plVar2[0x30] = 0;
            }
            if ((*(uint *)((longlong)plVar2 + 0x14) & 0x40000) == 0) {
              if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  (uVar9 = (ulonglong)*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c),
                  (*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                uVar9 = WPP_SF_q(WPP_GLOBAL_Control[3],0x21,
                                 &WPP_2907760f3af034d0edbd0569d145b880_Traceguids,plVar2);
              }
            }
            else {
              if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                WPP_SF_q(WPP_GLOBAL_Control[3],0x22,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids
                         ,plVar2);
              }
              *(uint *)((longlong)plVar2 + 0x14) = *(uint *)((longlong)plVar2 + 0x14) & 0xfffffffc;
              FreeAddressRange((longlong)plVar2,(longlong)(plVar2 + 0x46));
              plVar2[0x79] = 0;
              uVar9 = Feature_4206787897__private_IsEnabledDeviceUsageNoInline();
              if ((int)uVar9 != 0) {
                memset(plVar2 + 0xca,0,0x40);
              }
              if (plVar2[0xb4] != 0) {
                lVar11 = 0;
                lVar12 = 8;
                do {
                  lVar3 = plVar2[0xb4];
                  if (*(longlong *)(lVar11 + 0x68 + lVar3) != 0) {
                    *(undefined8 *)(lVar11 + 0x90 + lVar3) = 0;
                    FreeAddressRange((longlong)plVar2,lVar3 + 0x70 + lVar11);
                  }
                  lVar11 = lVar11 + 0x150;
                  lVar12 = lVar12 + -1;
                } while (lVar12 != 0);
                ExFreePoolWithTag(plVar2[0xb4],0x62416253);
                plVar2[0xb4] = 0;
              }
              if (plVar2[0x9b] != 0) {
                while (lVar11 = ExpInterlockedPopEntrySList(plVar2 + 0x98), lVar11 != 0) {
                  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                    WPP_SF_qqq(WPP_GLOBAL_Control[3],0x23,
                               &WPP_2907760f3af034d0edbd0569d145b880_Traceguids,plVar2,(char)lVar11,
                               (char)plVar2[0x9b]);
                  }
                  IoFreeMdl(*(undefined8 *)(lVar11 + 0x10));
                }
                ExFreePoolWithTag(plVar2[0x9b],0x66536253);
                plVar2[0x9b] = 0;
              }
              while (lVar11 = ExpInterlockedPopEntrySList(plVar2 + 0xb0), lVar11 != 0) {
                ExFreePool(*(undefined8 *)(lVar11 + 0x10));
                if (**(short **)(lVar11 + 0x18) == 6) {
                  IoFreeIrp();
                }
                ExFreePoolWithTag(lVar11,0x6b506253);
              }
              uVar7 = KeAcquireSpinLockRaiseToDpc(plVar2 + 0xb2);
              ExDeleteNPagedLookasideList(plVar2 + 0xa0);
              uVar9 = KeReleaseSpinLock(plVar2 + 0xb2,uVar7);
              if (plVar2[0x21] != 0) {
                uVar9 = IoFreeMdl();
                plVar2[0x21] = 0;
              }
              if ((*(uint *)((longlong)plVar2 + 0x14) & 0x400000) == 0) {
                if (*(longlong *)(plVar2[0xb] + 0x50) != 0) {
                  ExFreePool();
                  *(undefined2 *)(plVar2[0xb] + 0x48) = 0;
                  *(undefined8 *)(plVar2[0xb] + 0x50) = 0;
                }
                if (*(longlong *)(plVar2[0xb] + 0x60) != 0) {
                  ExFreePool();
                  *(undefined2 *)(plVar2[0xb] + 0x58) = 0;
                  *(undefined8 *)(plVar2[0xb] + 0x60) = 0;
                }
                uVar9 = plVar2[0xb];
                if (*(longlong *)(uVar9 + 0x70) != 0) {
                  ExFreePoolWithTag(*(longlong *)(uVar9 + 0x70),0x62476253);
                  *(undefined2 *)(plVar2[0xb] + 0x68) = 0;
                  uVar9 = plVar2[0xb];
                  *(undefined8 *)(uVar9 + 0x70) = 0;
                }
              }
            }
          }
        }
        goto LAB_140001b57;
      }
      plVar10 = (longlong *)(ulonglong)((int)plVar10 + 1);
      lVar12 = *(longlong *)((longlong)plVar10 * 0x78 + 0xa8 + lVar11);
    }
    uVar9 = Sbp2AddLog((longlong)plVar2,1,0x436c6e32,(ulonglong)*(uint *)(lVar11 + 0x98),0);
  }
  else {
    uVar1 = *(uint *)((longlong)plVar2 + 0x14);
    uVar9 = (ulonglong)uVar1;
    if ((uVar1 & 0x40000) == 0) {
      *(uint *)((longlong)plVar2 + 0x14) = uVar1 | 0x40000;
      if ((int)plVar2[0x13] != 0) {
        iVar8 = Sbp2EnableBusResetNotification((longlong)plVar2,'\0');
        if ((((iVar8 < 0) && ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_qd(WPP_GLOBAL_Control[3],0x24,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,
                    plVar2,(char)iVar8);
        }
      }
      uVar7 = KeAcquireSpinLockRaiseToDpc(plVar2 + 0x14);
      iVar8 = (int)plVar2[0x13];
      while (iVar8 != 0) {
        uVar1 = iVar8 - 1;
        uVar9 = (ulonglong)uVar1;
        lVar11 = plVar2[uVar9 * 0xf + 0x15];
        if (lVar11 == 0) {
LAB_140001a72:
          uVar9 = (ulonglong)uVar1;
          if (plVar2[uVar9 * 0xf + 0x1f] != 0) {
            ExFreePool();
            plVar2[uVar9 * 0xf + 0x1f] = 0;
            *(undefined2 *)(plVar2 + (uVar9 + 2) * 0xf) = 0;
          }
          if (plVar2[uVar9 * 0xf + 0x21] != 0) {
            ExFreePool();
            plVar2[uVar9 * 0xf + 0x21] = 0;
            *(undefined2 *)(plVar2 + uVar9 * 0xf + 0x20) = 0;
          }
          if (plVar2[uVar9 * 0xf + 0x23] != 0) {
            ExFreePool();
            plVar2[uVar9 * 0xf + 0x23] = 0;
            *(undefined2 *)(plVar2 + uVar9 * 0xf + 0x22) = 0;
          }
        }
        else {
          lVar12 = *(longlong *)(lVar11 + 0x40);
          if (*(int *)(lVar12 + 0x10) != 0x4f445078) {
            *(uint *)(lVar12 + 0x14) = *(uint *)(lVar12 + 0x14) | 0x40000;
            lVar11 = plVar2[uVar9 * 0xf + 0x15];
            plVar10 = plVar2 + 0x14;
            KeReleaseSpinLock(plVar10,uVar7);
            uVar13 = Sbp2CleanDeviceExtension(lVar11,1,0);
            if ((char)uVar13 != '\0') {
              iVar8 = IoAcquireRemoveLockEx(lVar12 + 0x18,0,"",1,0x20);
              if (((iVar8 < 0) && ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
                 (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
                  (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
                WPP_SF_qd(WPP_GLOBAL_Control[3],0x26,
                          &WPP_2907760f3af034d0edbd0569d145b880_Traceguids,lVar11,(char)iVar8);
              }
              uVar7 = KfRaiseIrql(2);
              Sbp2StartNextPacketByKey(lVar11,0);
              KeLowerIrql(uVar7);
              if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                WPP_SF_qq(WPP_GLOBAL_Control[3],0x27,
                          &WPP_2907760f3af034d0edbd0569d145b880_Traceguids,lVar12,(char)lVar11);
              }
              *(undefined4 *)(lVar12 + 0x10) = 0x4f445078;
              *(undefined4 *)(lVar12 + 0x104) = 0xc000000e;
              KeSetEvent(lVar12 + 0x2e8,0,0);
              KeCancelTimer(lVar12 + 0x5f0);
              IoReleaseRemoveLockAndWaitEx(lVar12 + 0x18,0,0x20);
              while (plVar4 = *(longlong **)(lVar12 + 0x630), plVar4 != (longlong *)(lVar12 + 0x630)
                    ) {
                lVar3 = *plVar4;
                if (((longlong *)*(longlong *)(lVar3 + 8) != plVar4) ||
                   (plVar5 = (longlong *)plVar4[1], (longlong *)*plVar5 != plVar4)) {
                  pcVar6 = (code *)swi(0x29);
                  (*pcVar6)(3);
                  pcVar6 = (code *)swi(3);
                  uVar13 = (*pcVar6)();
                  return uVar13;
                }
                *plVar5 = lVar3;
                *(longlong **)(lVar3 + 8) = plVar5;
                ExFreePool();
              }
              uVar7 = KeAcquireSpinLockRaiseToDpc(plVar10);
              plVar2[(ulonglong)uVar1 * 0xf + 0x15] = 0;
              KeReleaseSpinLock(plVar10,CONCAT31((int3)(uVar1 >> 8),uVar7));
              IoDeleteDevice(lVar11);
              if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                WPP_SF_q(WPP_GLOBAL_Control[3],0x28,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids
                         ,lVar12);
              }
            }
            uVar7 = KeAcquireSpinLockRaiseToDpc(plVar10);
            goto LAB_140001a72;
          }
          if (plVar2[uVar9 * 0xf + 0x1f] != 0) {
            ExFreePool();
            plVar2[uVar9 * 0xf + 0x1f] = 0;
            *(undefined2 *)(plVar2 + (uVar9 + 2) * 0xf) = 0;
          }
          if (plVar2[uVar9 * 0xf + 0x21] != 0) {
            ExFreePool();
            *(undefined2 *)(plVar2 + uVar9 * 0xf + 0x20) = 0;
            plVar2[uVar9 * 0xf + 0x21] = 0;
          }
          if (plVar2[uVar9 * 0xf + 0x23] != 0) {
            ExFreePool();
            *(undefined2 *)(plVar2 + uVar9 * 0xf + 0x22) = 0;
            plVar2[uVar9 * 0xf + 0x23] = 0;
          }
          plVar2[(ulonglong)uVar1 * 0xf + 0x15] = 0;
          KeReleaseSpinLock(plVar2 + 0x14);
          IoReleaseRemoveLockAndWaitEx(lVar12 + 0x18);
          IoDeleteDevice(lVar11);
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_q(WPP_GLOBAL_Control[3],0x25,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,
                     lVar12);
          }
          uVar7 = KeAcquireSpinLockRaiseToDpc(plVar2 + 0x14);
        }
        iVar8 = (int)plVar2[0x13] + -1;
        *(int *)(plVar2 + 0x13) = iVar8;
      }
      if (plVar2[0xb5] != 0) {
        DeAllocateIrpAndIrb((longlong)plVar2,plVar2[0xb5]);
        plVar2[0xb5] = 0;
      }
      uVar9 = KeReleaseSpinLock(plVar2 + 0x14,uVar7);
LAB_140001b57:
      return CONCAT71((int7)(uVar9 >> 8),1);
    }
  }
  return uVar9 & 0xffffffffffffff00;
}



===== Sbp2CreateClose @ 140001b80 =====

uint Sbp2CreateClose(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  char *pcVar3;
  undefined1 uVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  undefined8 local_res8;
  
  plVar2 = *(longlong **)(param_1 + 0x40);
  uVar5 = 0;
  pcVar3 = *(char **)(param_2 + 0xb8);
  if ((int)plVar2[2] != 0x4f445073) {
    uVar5 = 0;
    if ((int)plVar2[2] != 0x4f444673) {
      uVar5 = 0xc000000e;
    }
    goto LAB_140001e8b;
  }
  if ((((*(byte *)(plVar2 + 0x22) & 0x1f) - 2 & 0xfb) != 0) ||
     ((*(uint *)((longlong)plVar2 + 0x14) & 2) != 0)) goto LAB_140001e8b;
  uVar5 = IoAcquireRemoveLockEx(plVar2 + 3,0,"",1,0x20);
  if ((int)uVar5 < 0) goto LAB_140001e8b;
  if (*pcVar3 == '\0') {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qd(WPP_GLOBAL_Control[3],0x45,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,plVar2,
                (char)*(undefined4 *)((longlong)plVar2 + 0xf4));
    }
    plVar1 = plVar2 + 0xb5;
    uVar4 = KeAcquireSpinLockRaiseToDpc(plVar1);
    if ((*(uint *)((longlong)plVar2 + 0x14) & 8) != 0) {
      KeReleaseSpinLock(plVar1);
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_q(WPP_GLOBAL_Control[3],0x46,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,plVar2)
        ;
      }
      uVar6 = Sbp2ManagementTransaction(plVar2,0,-1);
      uVar5 = (uint)uVar6;
      if (uVar5 == 0x103) {
        local_res8 = 0xfffffffffd050f80;
        KeWaitForSingleObject(plVar2 + 0x5d,0,0,0,&local_res8);
        uVar4 = KeAcquireSpinLockRaiseToDpc(plVar1);
        uVar5 = *(uint *)((longlong)plVar2 + 0x14);
        KeReleaseSpinLock(plVar1,uVar4);
        uVar5 = -(uint)((uVar5 & 0x208) != 0) & 0xc0000001;
      }
      if (uVar5 != 0) goto LAB_140001e66;
      Sbp2Reset(*plVar2,1);
      uVar4 = KeAcquireSpinLockRaiseToDpc(plVar1);
      *(uint *)((longlong)plVar2 + 0x14) = *(uint *)((longlong)plVar2 + 0x14) & 0xfffffff7;
    }
    KeReleaseSpinLock(plVar1,uVar4);
    LOCK();
    *(int *)((longlong)plVar2 + 0xf4) = *(int *)((longlong)plVar2 + 0xf4) + 1;
    UNLOCK();
  }
  else if (*pcVar3 == '\x02') {
    if (*(int *)((longlong)plVar2 + 0xf4) != 0) {
      LOCK();
      *(int *)((longlong)plVar2 + 0xf4) = *(int *)((longlong)plVar2 + 0xf4) + -1;
      UNLOCK();
    }
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qd(WPP_GLOBAL_Control[3],0x47,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,plVar2,
                (char)*(undefined4 *)((longlong)plVar2 + 0xf4));
    }
    if (((*(uint *)((longlong)plVar2 + 0x14) & 0x40008) == 0) &&
       (*(int *)((longlong)plVar2 + 0xf4) == 0)) {
      if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
          (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
        WPP_SF_q(WPP_GLOBAL_Control[3],0x48,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,plVar2)
        ;
      }
      uVar4 = KeAcquireSpinLockRaiseToDpc(plVar2 + 0xb5);
      uVar7 = *(uint *)((longlong)plVar2 + 0x14) & 0xfffffbff;
      *(uint *)((longlong)plVar2 + 0x14) = uVar7 | 8;
      KeReleaseSpinLock(plVar2 + 0xb5,CONCAT31((int3)(uVar7 >> 8),uVar4));
      Sbp2ManagementTransaction(plVar2,7,-1);
      CleanupOrbList(plVar2,-0x3ffffdc0);
    }
  }
LAB_140001e66:
  IoReleaseRemoveLockEx(plVar2 + 3,0,0x20);
LAB_140001e8b:
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(uint *)(param_2 + 0x30) = uVar5;
  IofCompleteRequest(param_2,0);
  return uVar5;
}



===== Sbp2DeviceManagementTimeoutDpc @ 140001ed0 =====

void Sbp2DeviceManagementTimeoutDpc(longlong *param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong *plVar6;
  byte bVar7;
  undefined2 uVar8;
  uint uVar9;
  short sVar10;
  int iVar11;
  undefined1 uVar12;
  
  if (param_1 != param_2 + 0xb6) {
    if ((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return;
    }
    if (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 4) {
      return;
    }
    WPP_SF_qqq(WPP_GLOBAL_Control[3],0x2b,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,param_2,
               (char)param_1,(char)(param_2 + 0xb6));
    return;
  }
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
     (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qd(WPP_GLOBAL_Control[3],0x2c,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,param_2,
              (char)*(undefined4 *)((longlong)param_2 + 0x14));
  }
  plVar1 = param_2 + 0xb5;
  KeAcquireSpinLockAtDpcLevel(plVar1);
  sVar10 = 0;
  bVar7 = 1;
  Sbp2AddLog((longlong)param_2,1,0x4d674d74,0,0);
  uVar9 = *(uint *)((longlong)param_2 + 0x14);
  if ((uVar9 >> 0x12 & 1) != 0) goto LAB_14000214d;
  uVar12 = (undefined1)uVar9;
  if ((uVar9 >> 8 & 1) != 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((bVar7 & (byte)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x2c)) != 0)) &&
       (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qd(WPP_GLOBAL_Control[3],sVar10 + 0x2d,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids
                ,param_2,uVar12);
    }
    *(uint *)((longlong)param_2 + 0x14) = *(uint *)((longlong)param_2 + 0x14) & 0xffffdaff;
    uVar9 = *(uint *)((longlong)param_2 + 0x14);
    *(undefined4 *)((longlong)param_2 + 0x104) = 0xc00000b5;
    lVar3 = *(longlong *)(param_2[10] + 0x40);
    lVar2 = lVar3 + 0xa0;
    KeAcquireSpinLockAtDpcLevel(lVar2);
    if ((*(uint *)(lVar3 + 0x98) < 2) || ((uVar9 & 8) == 0)) {
      uVar5 = Sbp2QueueManagementWorkItem(param_2,2,0xffffffff);
      if ((int)uVar5 < 0) {
        Sbp2SetDeferLoginTimer((longlong)param_2);
      }
    }
    else {
      uVar5 = 0;
      do {
        plVar6 = *(longlong **)(*(longlong *)(uVar5 * 0x78 + 0xa8 + lVar3) + 0x40);
        if (*plVar6 == *param_2) {
          uVar4 = Sbp2QueueManagementWorkItem(plVar6,2,0xffffffff);
          if ((int)uVar4 < 0) {
LAB_1400020f0:
            Sbp2SetDeferLoginTimer((longlong)plVar6);
          }
        }
        else {
          uVar9 = *(uint *)((longlong)plVar6 + 0x14);
          if (((uVar9 & 1) != 0) && ((uVar9 & 0x542308) == 0)) {
            *(uint *)((longlong)plVar6 + 0x14) = uVar9 | 0x2008;
            KeReleaseSpinLockFromDpcLevel(lVar2);
            CleanupOrbList(plVar6,-0x3ffffdc0);
            KeAcquireSpinLockAtDpcLevel(lVar2);
            uVar4 = Sbp2QueueManagementWorkItem(plVar6,2,0xffffffff);
            if ((int)uVar4 < 0) {
              plVar6 = param_2;
              goto LAB_1400020f0;
            }
          }
        }
        uVar9 = (int)uVar5 + 1;
        uVar5 = (ulonglong)uVar9;
      } while (uVar9 < *(uint *)(lVar3 + 0x98));
    }
    KeReleaseSpinLockFromDpcLevel(lVar2);
    KeSetEvent(param_2 + 0x5d,0,0);
    goto LAB_14000214d;
  }
  if ((uVar9 >> 0xc & 1) != 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qd(WPP_GLOBAL_Control[3],0x2e,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,param_2,
                uVar12);
    }
    uVar5 = Sbp2QueueManagementWorkItem(param_2,2,0xffffffff);
    if ((int)uVar5 < 0) {
      Sbp2SetDeferLoginTimer((longlong)param_2);
    }
    goto LAB_14000214d;
  }
  if ((uVar9 >> 9 & 1) != 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((bVar7 & (byte)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x2c)) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qd(WPP_GLOBAL_Control[3],0x2f,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,param_2,
                uVar12);
    }
    *(undefined4 *)((longlong)param_2 + 0x104) = 0xc00000b5;
    KeReleaseSpinLockFromDpcLevel(plVar1);
    KeSetEvent(param_2 + 0x5d,0,0);
    Sbp2LoginErrorHandler(param_2,0x102,0xac3);
    return;
  }
  if ((uVar9 >> 0xf & 1) != 0) {
    *(uint *)((longlong)param_2 + 0x14) = uVar9 & 0xffff7fff;
    uVar5 = Sbp2QueueManagementWorkItem(param_2,2,0xffffffff);
    if ((int)uVar5 < 0) {
      Sbp2SetDeferLoginTimer((longlong)param_2);
    }
    KeReleaseSpinLockFromDpcLevel(plVar1);
    if (param_2[0x1c] == 0) {
      return;
    }
    Sbp2RestartPendingPowerIrp(param_2);
    return;
  }
  if ((uVar9 >> 0xd & 1) == 0) goto LAB_14000214d;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((bVar7 & (byte)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x2c)) != 0)) &&
     (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qd(WPP_GLOBAL_Control[3],0x30,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,param_2,
              uVar12);
  }
  if ((*(uint *)((longlong)param_2 + 0x14) & 8) == 0) {
    uVar9 = *(uint *)(param_2 + 0xc) >> 1;
    iVar11 = 3;
    if (uVar9 < 5) {
      uVar9 = 5;
    }
    *(uint *)(param_2 + 0xc) = uVar9;
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
       (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      uVar8 = 0x31;
LAB_14000234a:
      WPP_SF_q(WPP_GLOBAL_Control[3],uVar8,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,param_2)
      ;
    }
  }
  else {
    iVar11 = 5;
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
       (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      uVar8 = 0x32;
      goto LAB_14000234a;
    }
  }
  if ((*(uint *)((longlong)param_2 + 0x14) >> 0x19 & 1) == 0) {
    KeReleaseSpinLockFromDpcLevel(plVar1);
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qd(WPP_GLOBAL_Control[3],0x33,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,param_2,
                (char)*(undefined4 *)((longlong)param_2 + 0x14));
    }
    Sbp2Reset(*param_2,iVar11);
    return;
  }
  *(uint *)((longlong)param_2 + 0x14) = *(uint *)((longlong)param_2 + 0x14) & 0xfdffffff;
LAB_14000214d:
  KeReleaseSpinLockFromDpcLevel(plVar1);
  return;
}



===== Sbp2EnableBusResetNotification @ 1400023c8 =====

int Sbp2EnableBusResetNotification(longlong param_1,char param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  longlong lVar5;
  longlong local_res8;
  undefined8 local_res18;
  
  local_res8 = 0;
  iVar3 = 0;
  lVar5 = *(longlong *)(param_1 + 0x5a8);
  if (*(longlong *)(param_1 + 0x5a8) == 0) {
    AllocateIrpAndIrb(param_1,&local_res8);
    if (local_res8 == 0) {
      return -0x3fffff66;
    }
    *(longlong *)(param_1 + 0x5a8) = local_res8;
    lVar5 = local_res8;
  }
  local_res18 = 0xfffffffffe363c80;
  KeWaitForSingleObject(param_1 + 0x60,0,0,0,&local_res18);
  if (param_2 == '\0') {
    if ((*(uint *)(param_1 + 0x14) & 0x40000) == 0) {
      piVar1 = (int *)(param_1 + 0x58);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 != 0) goto LAB_140002506;
    }
    else {
      *(undefined4 *)(param_1 + 0x58) = 0;
    }
  }
  else {
    uVar2 = *(int *)(param_1 + 0x58) + 1;
    *(uint *)(param_1 + 0x58) = uVar2;
    if (1 < uVar2) goto LAB_140002506;
  }
  **(undefined4 **)(lVar5 + 0x10) = 0x1d;
  *(undefined4 *)(*(longlong *)(lVar5 + 0x10) + 4) = 0;
  if (param_2 == '\0') {
    *(undefined4 *)(*(longlong *)(lVar5 + 0x10) + 0x88) = 2;
  }
  else {
    Sbp2GetHostDDIVersion(param_1);
    if (*(ushort *)(param_1 + 0x5b0) < 3) {
      *(undefined4 *)(*(longlong *)(lVar5 + 0x10) + 0x88) = 1;
      pcVar4 = Sbp2BusResetNotification;
    }
    else {
      *(undefined4 *)(*(longlong *)(lVar5 + 0x10) + 0x88) = 5;
      pcVar4 = Sbp2BusResetNotificationEx;
    }
    *(code **)(*(longlong *)(lVar5 + 0x10) + 0x90) = pcVar4;
    *(longlong *)(*(longlong *)(lVar5 + 0x10) + 0x98) = param_1;
  }
  iVar3 = Sbp2SendRequest(param_1,lVar5,(undefined *)0x2);
  if ((iVar3 < 0) && (param_2 != '\0')) {
    *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + -1;
  }
LAB_140002506:
  KeReleaseMutex(param_1 + 0x60,0);
  return iVar3;
}



===== Sbp2FDOPnpDeviceControl @ 140002534 =====

ulonglong Sbp2FDOPnpDeviceControl(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  char cVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 *puVar5;
  uint uVar6;
  int iVar7;
  ulonglong uVar8;
  uint *puVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  plVar3 = *(longlong **)(param_1 + 0x40);
  lVar4 = *(longlong *)(param_2 + 0xb8);
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  plVar1 = plVar3 + 3;
  uVar6 = IoAcquireRemoveLockEx(plVar1,0,"",1,0x20);
  uVar8 = (ulonglong)uVar6;
  if ((int)uVar6 < 0) {
    *(uint *)(param_2 + 0x30) = uVar6;
  }
  else {
    cVar2 = *(char *)(lVar4 + 1);
    if (cVar2 == '\0') {
      KeInitializeEvent(&local_38,1);
      puVar5 = *(undefined8 **)(param_2 + 0xb8);
      puVar5[-9] = *puVar5;
      puVar5[-8] = puVar5[1];
      puVar5[-7] = puVar5[2];
      puVar5[-6] = puVar5[3];
      *(undefined4 *)(puVar5 + -5) = *(undefined4 *)(puVar5 + 4);
      *(undefined4 *)((longlong)puVar5 + -0x24) = *(undefined4 *)((longlong)puVar5 + 0x24);
      *(undefined4 *)(puVar5 + -4) = *(undefined4 *)(puVar5 + 5);
      *(undefined4 *)((longlong)puVar5 + -0x1c) = *(undefined4 *)((longlong)puVar5 + 0x2c);
      puVar5[-3] = puVar5[6];
      *(undefined1 *)((longlong)puVar5 + -0x45) = 0;
      lVar4 = *(longlong *)(param_2 + 0xb8);
      *(code **)(lVar4 + -0x10) = Sbp2FdoRequestCompletionRoutine;
      *(undefined8 **)(lVar4 + -8) = &local_38;
      *(undefined1 *)(lVar4 + -0x45) = 0xe0;
      iVar7 = IofCallDriver(plVar3[1]);
      uVar8 = (ulonglong)*(uint *)(param_2 + 0x30);
      if ((-1 < (int)*(uint *)(param_2 + 0x30)) || (iVar7 == 0x103)) {
        uVar11 = 0;
        uVar10 = 0;
        uVar8 = 0;
        KeWaitForSingleObject(&local_38,0,0,0,0);
        uVar6 = Sbp2StartDevice(param_1,uVar8,uVar10,uVar11);
        uVar8 = (ulonglong)uVar6;
      }
    }
    else {
      if (cVar2 == '\x02') {
        IoReleaseRemoveLockAndWaitEx(plVar1,0,0x20);
        Sbp2CleanDeviceExtension(param_1,1,1);
        puVar5 = *(undefined8 **)(param_2 + 0xb8);
        puVar5[-9] = *puVar5;
        puVar5[-8] = puVar5[1];
        puVar5[-7] = puVar5[2];
        puVar5[-6] = puVar5[3];
        *(undefined4 *)(puVar5 + -5) = *(undefined4 *)(puVar5 + 4);
        *(undefined4 *)((longlong)puVar5 + -0x24) = *(undefined4 *)((longlong)puVar5 + 0x24);
        *(undefined4 *)(puVar5 + -4) = *(undefined4 *)(puVar5 + 5);
        *(undefined4 *)((longlong)puVar5 + -0x1c) = *(undefined4 *)((longlong)puVar5 + 0x2c);
        puVar5[-3] = puVar5[6];
        *(undefined1 *)((longlong)puVar5 + -0x45) = 0;
        uVar6 = IofCallDriver(plVar3[1],param_2);
        IoDetachDevice(plVar3[1]);
        IoDeleteDevice(param_1);
        return (ulonglong)uVar6;
      }
      if (cVar2 != '\a') {
        if (cVar2 == '\t') {
          puVar9 = (uint *)(*(longlong *)(lVar4 + 8) + 4);
          *puVar9 = *puVar9 | 0x200;
        }
        else if (cVar2 == '\x14') {
          *(ulonglong *)(param_2 + 0x38) = *(ulonglong *)(param_2 + 0x38) | 2;
        }
LAB_1400025ca:
        IoReleaseRemoveLockEx(plVar1,0,0x20);
        puVar5 = *(undefined8 **)(param_2 + 0xb8);
        puVar5[-9] = *puVar5;
        puVar5[-8] = puVar5[1];
        puVar5[-7] = puVar5[2];
        puVar5[-6] = puVar5[3];
        *(undefined4 *)(puVar5 + -5) = *(undefined4 *)(puVar5 + 4);
        *(undefined4 *)((longlong)puVar5 + -0x24) = *(undefined4 *)((longlong)puVar5 + 0x24);
        *(undefined4 *)(puVar5 + -4) = *(undefined4 *)(puVar5 + 5);
        *(undefined4 *)((longlong)puVar5 + -0x1c) = *(undefined4 *)((longlong)puVar5 + 0x2c);
        puVar5[-3] = puVar5[6];
        *(undefined1 *)((longlong)puVar5 + -0x45) = 0;
        uVar8 = IofCallDriver(plVar3[1],param_2);
        return uVar8;
      }
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_qd(WPP_GLOBAL_Control[3],0x61,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,plVar3
                  ,(char)*(undefined4 *)(lVar4 + 8));
      }
      if (*(int *)(lVar4 + 8) != 0) goto LAB_1400025ca;
      puVar9 = (uint *)ExAllocatePool2(0x100,0x60,0x72446253);
      if (puVar9 != (uint *)0x0) {
        uVar6 = Sbp2CreateDeviceRelations(plVar3,puVar9);
        *(uint *)(param_2 + 0x30) = uVar6;
        if ((int)uVar6 < 0) {
          ExFreePoolWithTag(puVar9,0x72446253);
          *(undefined8 *)(param_2 + 0x38) = 0;
          IoReleaseRemoveLockEx(plVar1,0,0x20);
          uVar8 = (ulonglong)uVar6;
          goto LAB_140002876;
        }
        *(uint **)(param_2 + 0x38) = puVar9;
        goto LAB_1400025ca;
      }
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_q(WPP_GLOBAL_Control[3],0x62,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,plVar3)
        ;
      }
      *(undefined8 *)(param_2 + 0x38) = 0;
      uVar8 = 0xc000009a;
    }
    *(int *)(param_2 + 0x30) = (int)uVar8;
    IoReleaseRemoveLockEx(plVar1,0,0x20);
  }
LAB_140002876:
  IofCompleteRequest(param_2,0);
  return uVar8;
}



===== Sbp2FdoRequestCompletionRoutine @ 1400028b0 =====

undefined8 Sbp2FdoRequestCompletionRoutine(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== Sbp2HandleApiRequest @ 1400028dc =====

int Sbp2HandleApiRequest(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  int *piVar4;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  iVar3 = IoAcquireRemoveLockEx(param_1 + 0x18,param_2,"",1,0x20);
  if (iVar3 < 0) {
    *(int *)(param_2 + 0x30) = iVar3;
    goto LAB_140002a18;
  }
  if (*(char *)(param_2 + 0x40) == '\0') {
    piVar4 = *(int **)(lVar2 + 8);
LAB_140002941:
    if (piVar4 == (int *)0x0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_q(WPP_GLOBAL_Control[3],0x44,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,param_1
                );
      }
      goto LAB_1400029d7;
    }
    iVar3 = -0x3ffffffe;
    if (*piVar4 != 1) goto LAB_1400029d7;
    if (*(char *)(param_2 + 0x40) == '\0') {
      iVar3 = Sbp2Get1394ConfigInfo
                        (*(longlong *)(*(longlong *)(param_1 + 0x50) + 0x40),(longlong)piVar4);
    }
  }
  else {
    uVar1 = *(uint *)(lVar2 + 0x10);
    piVar4 = *(int **)(param_2 + 0x18);
    if (0x1f < uVar1) goto LAB_140002941;
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qDd(WPP_GLOBAL_Control[3],0x43,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,param_1
                 ,(char)uVar1,0x20);
    }
LAB_1400029d7:
    iVar3 = -0x3ffffff3;
  }
  *(int *)(param_2 + 0x30) = iVar3;
  IoReleaseRemoveLockEx(param_1 + 0x18,param_2,0x20);
LAB_140002a18:
  IofCompleteRequest(param_2,0);
  return iVar3;
}



===== Sbp2InitializeDeviceExtension @ 140002a50 =====

int Sbp2InitializeDeviceExtension
              (longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  int iVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint uVar9;
  longlong lVar10;
  longlong lVar11;
  uint local_res8;
  longlong *local_res10;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  lVar2 = *param_1;
  local_48 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if ((*(uint *)((longlong)param_1 + 0x14) & 0x40000) != 0) {
    return 0;
  }
  CleanupOrbList(param_1,-0x3ffffdc0);
  lVar11 = 0;
  param_1[0x17] = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)((longlong)param_1 + 0x94) = 0;
  iVar3 = Sbp2UpdateNodeInformation(param_1);
  if ((((-1 < iVar3) && (iVar3 = Sbp2GetControllerInfo((longlong)param_1), -1 < iVar3)) &&
      ((param_1[0x8c] != 0 ||
       (iVar3 = AllocateAddressForStatus(lVar2,param_1 + 0x89,'\x02'), -1 < iVar3)))) &&
     (((param_1[0x81] != 0 ||
       (iVar3 = AllocateAddressForStatus(lVar2,param_1 + 0x7e,'\x04'), -1 < iVar3)) &&
      ((param_1[0x93] != 0 ||
       (iVar3 = AllocateAddressForStatus(lVar2,param_1 + 0x90,'\b'), -1 < iVar3)))))) {
    param_1[0x4e] = lVar2;
    param_1[0x56] = lVar2;
    param_1[100] = lVar2;
    param_1[0x6c] = lVar2;
    if (param_1[0x49] == 0) {
      iVar3 = AllocateSingle1394Address(lVar2,0,0x218,param_4,(longlong)(param_1 + 0x46));
      if (iVar3 < 0) {
        return iVar3;
      }
      lVar10 = param_1[0x4c];
      lVar4 = param_1[0x47];
      param_1[0x57] = lVar4;
      param_1[0x65] = lVar4;
      param_1[0x6d] = lVar4;
      param_1[0x55] = lVar10 + 0x20;
      iVar6 = (int)lVar10;
      *(int *)((longlong)param_1 + 700) =
           *(int *)((longlong)param_1 + 700) + ((int)(lVar10 + 0x20) - iVar6);
      param_1[99] = lVar10 + 0x40;
      *(int *)((longlong)param_1 + 0x32c) =
           *(int *)((longlong)param_1 + 0x32c) + ((int)(lVar10 + 0x40) - iVar6);
      param_1[0x6b] = lVar10 + 0x50;
      *(int *)((longlong)param_1 + 0x36c) =
           *(int *)((longlong)param_1 + 0x36c) + ((int)(lVar10 + 0x50) - iVar6);
      param_1[0x74] = lVar4;
      param_1[0x79] = lVar10 + 0x98;
      *(int *)((longlong)param_1 + 0x3a4) =
           *(int *)((longlong)param_1 + 0x3a4) + ((int)(lVar10 + 0x98) - iVar6);
      param_1[0x45] = lVar10;
      param_1[0x4d] = lVar10;
      param_1[0x4f] = lVar4;
      AcquireOrbListLock((longlong)param_1,&local_58,'\0');
      local_res10 = param_1 + 0xca;
      uVar8 = 0;
      local_res8 = 0;
      uVar9 = 0;
      lVar10 = 0;
      do {
        lVar4 = ExpInterlockedPopEntrySList(param_1 + 0x9c);
        if ((lVar4 == 0) || (lVar7 = lVar4 + -0x10, lVar7 == 0)) {
          ReleaseOrbListLock((longlong)param_1,&local_58,'\0');
          return -0x3fffff66;
        }
        *(uint *)(lVar4 + 0x28) = *(uint *)(lVar4 + 0x28) | 2;
        *(longlong *)(lVar4 + -8) = lVar10;
        *(ulonglong *)(lVar4 + 0x30) = uVar8 * 0x30 + param_1[0x45] + 0xa0;
        uVar5 = Feature_4206787897__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar5 == 0) {
          *(longlong *)(lVar11 + 0x98 + param_1[0x45]) = lVar7;
        }
        else {
          *(ulonglong *)(lVar11 + 0x98 + param_1[0x45]) = uVar8;
          *local_res10 = lVar7;
        }
        local_res10 = local_res10 + 1;
        local_res8 = local_res8 + 1;
        iVar6 = *(int *)((longlong)param_1 + 0x3a4) + 8 + uVar9;
        uVar8 = (ulonglong)local_res8;
        uVar9 = uVar9 + 0x30;
        *(int *)(lVar4 + 0x3c) = iVar6;
        lVar11 = lVar11 + 0x30;
        *(short *)(lVar4 + 0x38) = (short)param_1[0x74];
        *(undefined2 *)(lVar4 + 0x3a) = *(undefined2 *)((longlong)param_1 + 0x19a);
        lVar10 = lVar7;
      } while (uVar9 < 0x180);
      do {
        ExpInterlockedPushEntrySList(param_1 + 0x9c,lVar7 + 0x10);
        plVar1 = (longlong *)(lVar7 + 8);
        lVar7 = *plVar1;
        *plVar1 = 0;
      } while (lVar7 != 0);
      ReleaseOrbListLock((longlong)param_1,&local_58,'\0');
    }
    if (param_1[0xb4] == 0) {
      iVar3 = -0x3fffff66;
    }
    else {
      lVar11 = 0;
      lVar10 = 8;
      do {
        lVar4 = lVar10;
        *(undefined2 *)(lVar11 + 0x7a + param_1[0xb4]) = *(undefined2 *)((longlong)param_1 + 0x19a);
        lVar10 = lVar4 + -1;
        lVar11 = lVar11 + 0x150;
      } while (lVar10 != 0);
      *(undefined2 *)((longlong)param_1 + 0x32a) = *(undefined2 *)((longlong)param_1 + 0x19a);
      *(undefined2 *)((longlong)param_1 + 0x36a) = *(undefined2 *)((longlong)param_1 + 0x19a);
      if ((((param_1[0x41] != 0) ||
           (iVar3 = AllocateSingle1394Address
                              (lVar2,(longlong)(param_1 + 0x39),(int)lVar4 + 0x27,param_4,
                               (longlong)(param_1 + 0x3e)), -1 < iVar3)) &&
          ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
          (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
        WPP_SF_q(WPP_GLOBAL_Control[3],0x1e,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,param_1
                );
      }
    }
  }
  return iVar3;
}



===== Sbp2LoginErrorHandler @ 140002e68 =====

void Sbp2LoginErrorHandler(longlong *param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  KeAcquireSpinLockRaiseToDpc(param_1 + 0xb5);
  uVar1 = *(uint *)((longlong)param_1 + 0x14);
  Sbp2AddLog((longlong)param_1,1,0x52737446,(longlong)param_2,(ulonglong)param_3);
  uVar2 = *(uint *)((longlong)param_1 + 0x14);
  uVar3 = uVar2 & 0xfffdf9ff;
  *(uint *)((longlong)param_1 + 0x14) = uVar3;
  if ((*(uint *)(param_1[0xb] + 0x38) & 0x20) == 0) {
    uVar3 = uVar2 & 0xfffdd9ff;
  }
  *(uint *)((longlong)param_1 + 0x14) = uVar3 | 0x100008;
  if ((uVar1 >> 0xd & 1) == 0) {
    KeSetEvent(param_1 + 0x5d,0,0);
  }
  KeReleaseSpinLock(param_1 + 0xb5);
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
     (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qDd(WPP_GLOBAL_Control[3],0x2a,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,param_1,
               (char)uVar1,(char)param_2);
  }
  if ((uVar1 & 2) == 0) {
    if (param_2 != -0x3ffffff2) {
      Sbp2CreateRequestErrorLog(*param_1,0,param_3,param_2);
    }
  }
  else {
    KeSetEvent(param_1 + 0x60,0,0);
  }
  Sbp2StartQueue(param_1);
  IoInvalidateDeviceState(*param_1);
  return;
}



===== Sbp2PnpDeviceControl @ 140002fd0 =====

ulonglong Sbp2PnpDeviceControl(longlong param_1,longlong param_2)

{
  byte bVar1;
  int iVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong lVar5;
  bool bVar6;
  undefined1 uVar7;
  uint uVar8;
  uint *puVar9;
  ulonglong uVar10;
  uint uVar11;
  undefined2 uVar12;
  undefined8 uVar13;
  longlong *plVar14;
  ulonglong uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  short local_38 [4];
  wchar_t *pwStack_30;
  
  plVar3 = *(longlong **)(param_1 + 0x40);
  lVar4 = *(longlong *)(param_2 + 0xb8);
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  pwStack_30 = (wchar_t *)0x0;
  if ((char)*(undefined4 *)(param_1 + 0x30) < '\0') {
LAB_140003ed9:
    *(undefined4 *)(param_2 + 0x30) = 0xc000000e;
    IofCompleteRequest(param_2,0);
    return 0xc000000e;
  }
  if ((int)plVar3[2] == 0x4f444673) {
    uVar15 = Sbp2FDOPnpDeviceControl(param_1,param_2);
    return uVar15;
  }
  if ((int)plVar3[2] != 0x4f445073) goto LAB_140003ed9;
  uVar8 = IoAcquireRemoveLockEx(plVar3 + 3,0,"",1,0x20);
  uVar15 = (ulonglong)uVar8;
  if ((int)uVar8 < 0) {
    *(uint *)(param_2 + 0x30) = uVar8;
    goto LAB_14000351b;
  }
  uVar10 = (ulonglong)*(byte *)(lVar4 + 1);
  uVar16 = 0x506e503e;
  lVar5 = plVar3[0xb];
  Sbp2AddLog((longlong)plVar3,1,0x506e503e,uVar10,0);
  bVar1 = *(byte *)(lVar4 + 1);
  if (bVar1 < 0x88) {
    if (bVar1 == 0x87) {
LAB_1400031d5:
      uVar15 = 0;
      *(undefined4 *)(param_2 + 0x30) = 0;
    }
    else if (bVar1 < 8) {
      if (bVar1 == 7) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_qd(WPP_GLOBAL_Control[3],0x4a,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,
                    plVar3,(char)*(undefined4 *)(lVar4 + 8));
        }
        if (*(int *)(lVar4 + 8) != 4) goto LAB_140003e39;
        puVar9 = *(uint **)(param_2 + 0x38);
        if (puVar9 == (uint *)0x0) {
          puVar9 = (uint *)ExAllocatePool2(0x100,0x10,0x32706253);
          if (puVar9 == (uint *)0x0) {
            uVar15 = 0xc000009a;
            *(undefined4 *)(param_2 + 0x30) = 0xc000009a;
            goto LAB_1400037be;
          }
          *puVar9 = 0;
          uVar15 = 0;
        }
        else {
          uVar15 = (ulonglong)*puVar9;
        }
        *(longlong *)(puVar9 + uVar15 * 2 + 2) = param_1;
        *puVar9 = *puVar9 + 1;
        ObfReferenceObject(param_1);
        *(undefined4 *)(param_2 + 0x30) = 0;
        uVar15 = 0;
        *(uint **)(param_2 + 0x38) = puVar9;
      }
      else if (bVar1 == 0) {
        uVar8 = Sbp2StartDevice(param_1,0,uVar16,uVar10);
        uVar15 = (ulonglong)uVar8;
        *(uint *)(param_2 + 0x30) = uVar8;
      }
      else {
        if (bVar1 == 1) {
          if ((((int)plVar3[0x1d] == 0) && (*(int *)((longlong)plVar3 + 0xec) == 0)) &&
             ((int)plVar3[0x1e] == 0)) {
            uVar7 = KeAcquireSpinLockRaiseToDpc(plVar3 + 0xb5);
            *(uint *)((longlong)plVar3 + 0x14) = *(uint *)((longlong)plVar3 + 0x14) | 0x80000;
            KeReleaseSpinLock(plVar3 + 0xb5,uVar7);
            uVar15 = 0;
          }
          else {
            uVar15 = 0xc0000001;
          }
          goto LAB_140003e1b;
        }
        if (bVar1 != 2) {
          if (bVar1 == 3) {
            uVar7 = KeAcquireSpinLockRaiseToDpc(plVar3 + 0xb5);
            *(uint *)((longlong)plVar3 + 0x14) = *(uint *)((longlong)plVar3 + 0x14) & 0xfff7ffff;
            KeReleaseSpinLock(plVar3 + 0xb5,uVar7);
          }
          else {
            if (bVar1 == 4) {
              Sbp2EnableBusResetNotification(*(longlong *)(plVar3[10] + 0x40),'\0');
              uVar16 = 4;
              PoRegisterDeviceForIdleDetection(param_1,0,0);
              plVar3[0x1f] = 0;
              uVar7 = KeAcquireSpinLockRaiseToDpc(plVar3 + 0xb5);
              uVar8 = *(uint *)((longlong)plVar3 + 0x14);
              if ((uVar8 & 8) == 0) {
                *(uint *)((longlong)plVar3 + 0x14) = uVar8 & 0xfffffbff | 0xc;
                KeReleaseSpinLock();
                lVar4 = *(longlong *)(plVar3[10] + 0x40);
                ExAcquireFastMutex(lVar4 + 0x570);
                Sbp2ManagementTransaction(plVar3,7,-1);
                ExReleaseFastMutex(lVar4 + 0x570);
                uVar17 = 0;
                uVar13 = 0;
                Sbp2CleanDeviceExtension(param_1,0,0);
                Sbp2InitializeDeviceExtension(plVar3,uVar13,uVar17,uVar16);
              }
              else {
                *(uint *)((longlong)plVar3 + 0x14) = uVar8 | 4;
                KeReleaseSpinLock(plVar3 + 0xb5,uVar7);
                KeCancelTimer(plVar3 + 0xbe);
              }
              goto LAB_1400031d5;
            }
            if ((bVar1 != 5) && (bVar1 != 6)) goto LAB_140003e39;
          }
          goto LAB_1400030de;
        }
        uVar15 = 0;
        uVar7 = KeAcquireSpinLockRaiseToDpc(plVar3 + 0xb5);
        uVar8 = *(uint *)((longlong)plVar3 + 0x14);
        *(uint *)((longlong)plVar3 + 0x14) = uVar8 | 4;
        if ((uVar8 & 0x1200) != 0) {
          KeCancelTimer(plVar3 + 0xbe);
          *(uint *)((longlong)plVar3 + 0x14) = *(uint *)((longlong)plVar3 + 0x14) & 0xffffefff;
          KeSetEvent(plVar3 + 0x5d,0);
        }
        uVar8 = *(uint *)((longlong)plVar3 + 0x14);
        if ((uVar8 >> 0x16 & 1) != 0) {
          bVar6 = false;
          uVar8 = 0;
          lVar4 = *(longlong *)(plVar3[10] + 0x40);
          if (*(uint *)(lVar4 + 0x98) != 0) {
            plVar14 = (longlong *)(lVar4 + 0xa8);
            do {
              if (*plVar14 == param_1) {
                bVar6 = true;
                break;
              }
              uVar8 = uVar8 + 1;
              plVar14 = plVar14 + 0xf;
            } while (uVar8 < *(uint *)(lVar4 + 0x98));
          }
          *(undefined4 *)((longlong)plVar3 + 0x104) = 0xc000000e;
          KeSetEvent(plVar3 + 0x5d,0,0);
          KeReleaseSpinLock(plVar3 + 0xb5);
          uVar7 = KfRaiseIrql(2);
          Sbp2StartNextPacketByKey(param_1,0);
          KeLowerIrql(uVar7);
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_qq(WPP_GLOBAL_Control[3],0x5c,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,
                      plVar3,(char)param_1);
          }
          *(undefined4 *)(plVar3 + 2) = 0x4f445078;
          KeCancelTimer(plVar3 + 0xbe);
          if (!bVar6) {
            IoReleaseRemoveLockAndWaitEx(plVar3 + 3,0);
            if (*(longlong *)(plVar3[0xb] + 0x50) != 0) {
              ExFreePool();
              *(undefined2 *)(plVar3[0xb] + 0x48) = 0;
              *(undefined8 *)(plVar3[0xb] + 0x50) = 0;
            }
            if (*(longlong *)(plVar3[0xb] + 0x60) != 0) {
              ExFreePool();
              *(undefined2 *)(plVar3[0xb] + 0x58) = 0;
              *(undefined8 *)(plVar3[0xb] + 0x60) = 0;
            }
            if (*(longlong *)(plVar3[0xb] + 0x70) != 0) {
              ExFreePoolWithTag(*(longlong *)(plVar3[0xb] + 0x70),0x62476253);
              *(undefined2 *)(plVar3[0xb] + 0x68) = 0;
              *(undefined8 *)(plVar3[0xb] + 0x70) = 0;
            }
            uVar7 = KeAcquireSpinLockRaiseToDpc(lVar4 + 0xa0);
            uVar15 = 0;
            plVar14 = (longlong *)(lVar4 + 0xa8);
            while (*plVar14 != 0) {
              if (*plVar14 == param_1) {
                if (plVar14 != (longlong *)0x0) {
                  *plVar14 = 0;
                  if (plVar14[10] != 0) {
                    ExFreePool();
                    *(undefined2 *)(plVar14 + 9) = 0;
                    plVar14[10] = 0;
                  }
                  if (plVar14[0xe] != 0) {
                    ExFreePool();
                    *(undefined2 *)(plVar14 + 0xd) = 0;
                    plVar14[0xe] = 0;
                  }
                  if (plVar14[0xc] != 0) {
                    ExFreePool();
                    *(undefined2 *)(plVar14 + 0xb) = 0;
                    plVar14[0xc] = 0;
                  }
                }
                break;
              }
              uVar15 = (ulonglong)((int)uVar15 + 1);
              plVar14 = (longlong *)(uVar15 * 0x78 + 0xa8 + lVar4);
            }
            KeReleaseSpinLock(lVar4 + 0xa0,uVar7);
            IoDeleteDevice(param_1);
            if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              WPP_SF_qq(WPP_GLOBAL_Control[3],0x5d,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,
                        plVar3,(char)param_1);
            }
          }
          *(undefined4 *)(param_2 + 0x30) = 0;
          uVar15 = 0;
          goto LAB_14000351b;
        }
        if ((uVar8 >> 0x13 & 1) == 0) {
          if ((((uVar8 & 0x140000) == 0) &&
              (*(uint *)((longlong)plVar3 + 0x14) = uVar8 & 0xffffd8ff | 0x40000,
              (undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
             (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
              (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
            WPP_SF_q(WPP_GLOBAL_Control[3],0x5f,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,
                     plVar3);
          }
        }
        else {
          if ((uVar8 & 1) != 0) {
            if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              WPP_SF_q(WPP_GLOBAL_Control[3],0x5e,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,
                       plVar3);
            }
            lVar4 = *(longlong *)(plVar3[10] + 0x40);
            uVar8 = *(uint *)((longlong)plVar3 + 0x14);
            if ((uVar8 >> 0xc & 1) != 0) {
              KeCancelTimer(plVar3 + 0xbe);
              uVar8 = *(uint *)((longlong)plVar3 + 0x14) & 0xffffefff;
              *(uint *)((longlong)plVar3 + 0x14) = uVar8;
            }
            if ((uVar8 >> 10 & 1) != 0) {
              *(uint *)((longlong)plVar3 + 0x14) = uVar8 & 0xfffffbff;
              KeReleaseSpinLock(plVar3 + 0xb5,uVar7);
              ExAcquireFastMutex(lVar4 + 0x570);
              Sbp2ManagementTransaction(plVar3,7,-1);
              ExReleaseFastMutex(lVar4 + 0x570);
              uVar7 = KeAcquireSpinLockRaiseToDpc(plVar3 + 0xb5);
            }
          }
          *(uint *)((longlong)plVar3 + 0x14) = *(uint *)((longlong)plVar3 + 0x14) & 0xfff7ffff | 8;
        }
        *(uint *)((longlong)plVar3 + 0x14) = *(uint *)((longlong)plVar3 + 0x14) & 0xffffffdf;
        KeReleaseSpinLock(plVar3 + 0xb5,uVar7);
        uVar16 = Sbp2CleanDeviceExtension(param_1,1,0);
        if ((((char)uVar16 == '\0') && ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control))
           && (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0 &&
               (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
          WPP_SF_q(WPP_GLOBAL_Control[3],0x60,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,
                   plVar3);
        }
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
    }
    else if (bVar1 == 9) {
      lVar4 = *(longlong *)(lVar4 + 8);
      uVar8 = *(uint *)(lVar4 + 4);
      uVar11 = uVar8 & 0xffffffef;
      *(uint *)(lVar4 + 4) = uVar11 | 0xc0;
      iVar2 = *(int *)(plVar3[0xb] + 0xc);
      if ((iVar2 == 0x10483) || (iVar2 == 0x104d8)) {
        if (((*(ushort *)(plVar3[0xb] + 10) & 0x1f) - 2 & 0xfffffffb) == 0) {
          uVar11 = uVar8 & 0xfffffeef | 0x2c0;
        }
        else {
          uVar11 = uVar11 | 0x1c0;
        }
        *(uint *)(lVar4 + 4) = uVar11;
      }
      *(undefined4 *)(lVar4 + 0x14) = 1;
      uVar15 = 0;
      *(undefined8 *)(lVar4 + 0x18) = 0x400000004;
      *(undefined8 *)(lVar4 + 0x20) = 0x400000004;
      *(undefined8 *)(lVar4 + 0x2c) = 0;
      *(undefined4 *)(lVar4 + 0x34) = 10000;
      *(undefined4 *)(lVar4 + 0x38) = 10000;
      *(undefined4 *)(lVar4 + 0x3c) = 10000;
      *(undefined4 *)(param_2 + 0x30) = 0;
LAB_1400037be:
      *(undefined8 *)(param_2 + 0x38) = 0;
    }
    else {
      if (bVar1 == 0xb) {
        *(uint *)(param_1 + 0x34) =
             *(uint *)(param_1 + 0x34) |
             *(uint *)(*(longlong *)(*(longlong *)(plVar3[10] + 0x40) + 0x40) + 0x34) & 0xc000;
        goto LAB_140003e39;
      }
      if (bVar1 == 0xc) {
        if (*(uint *)(lVar4 + 8) < 2) {
          uVar15 = Sbp2_BuildDeviceText(*(uint *)(lVar4 + 8),lVar5,(undefined4 *)local_38);
          uVar15 = uVar15 & 0xffffffff;
          *(wchar_t **)(param_2 + 0x38) = pwStack_30;
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_qS(WPP_GLOBAL_Control[3],0x4b,pwStack_30,plVar3,pwStack_30);
          }
        }
        else {
LAB_140003dc6:
          uVar15 = 0xc00000bb;
        }
      }
      else if (bVar1 == 0x13) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_(WPP_GLOBAL_Control[3],0x4c,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids);
        }
        *(undefined8 *)(param_2 + 0x38) = 0;
        iVar2 = *(int *)(lVar4 + 8);
        if (iVar2 == 0) {
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_(WPP_GLOBAL_Control[3],0x4d,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids);
          }
          uVar10 = Sbp2_BuildDeviceId(lVar5,local_38);
          uVar15 = uVar10 & 0xffffffff;
          if ((int)uVar10 < 0) {
            if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
               (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              uVar12 = 0x4e;
LAB_140003d75:
              WPP_SF_D(WPP_GLOBAL_Control[3],uVar12,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids
                       ,(int)uVar15);
            }
          }
          else {
            *(wchar_t **)(param_2 + 0x38) = pwStack_30;
            if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
               (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              uVar12 = 0x4f;
LAB_140003db0:
              WPP_SF_S(WPP_GLOBAL_Control[3],uVar12,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids
                       ,pwStack_30);
            }
          }
        }
        else if (iVar2 == 1) {
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_(WPP_GLOBAL_Control[3],0x50,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids);
          }
          uVar8 = Sbp2_BuildHardwareIds(lVar5,local_38);
          uVar15 = (ulonglong)uVar8;
          if ((int)uVar8 < 0) {
            if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
               (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              uVar12 = 0x51;
              goto LAB_140003d75;
            }
          }
          else {
            *(wchar_t **)(param_2 + 0x38) = pwStack_30;
            if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
               (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              uVar12 = 0x52;
              goto LAB_140003db0;
            }
          }
        }
        else if (iVar2 == 2) {
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_(WPP_GLOBAL_Control[3],0x53,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids);
          }
          uVar10 = Sbp2_BuildCompatIds(lVar5,local_38);
          uVar15 = uVar10 & 0xffffffff;
          if ((int)uVar10 < 0) {
            if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              uVar12 = 0x54;
              goto LAB_140003d75;
            }
          }
          else {
            *(wchar_t **)(param_2 + 0x38) = pwStack_30;
            if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              uVar12 = 0x55;
              goto LAB_140003db0;
            }
          }
        }
        else if (iVar2 == 3) {
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_(WPP_GLOBAL_Control[3],0x56,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids);
          }
          uVar10 = Sbp2_BuildInstanceId(lVar5,local_38);
          uVar15 = uVar10 & 0xffffffff;
          if ((int)uVar10 < 0) {
            if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              uVar12 = 0x57;
              goto LAB_140003d75;
            }
          }
          else {
            *(wchar_t **)(param_2 + 0x38) = pwStack_30;
            if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              uVar12 = 0x58;
              goto LAB_140003db0;
            }
          }
        }
        else {
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_qd(WPP_GLOBAL_Control[3],0x59,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,
                      plVar3,(char)iVar2);
          }
          uVar15 = (ulonglong)*(uint *)(param_2 + 0x30);
        }
      }
      else {
        if (bVar1 == 0x14) {
          uVar8 = *(uint *)((longlong)plVar3 + 0x14);
          if ((uVar8 >> 0xd & 1) == 0) {
            if (((uVar8 & 0x140000) != 0) && ((uVar8 & 2) == 0)) {
              uVar7 = KeAcquireSpinLockRaiseToDpc(plVar3 + 0xb5);
              *(uint *)((longlong)plVar3 + 0x14) = *(uint *)((longlong)plVar3 + 0x14) | 0x200000;
              KeReleaseSpinLock(plVar3 + 0xb5,uVar7);
              uVar15 = *(ulonglong *)(param_2 + 0x38) | 4;
              *(ulonglong *)(param_2 + 0x38) = uVar15;
              if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
                  (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
                uVar8 = *(uint *)((longlong)plVar3 + 0x14);
                uVar12 = 0x5b;
                goto LAB_140003a6c;
              }
            }
          }
          else if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                  (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            uVar15 = *(ulonglong *)(param_2 + 0x38);
            uVar12 = 0x5a;
LAB_140003a6c:
            WPP_SF_qqD(WPP_GLOBAL_Control[3],uVar12,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids
                       ,plVar3,(char)uVar15,(char)uVar8);
          }
LAB_1400030de:
          *(undefined4 *)(param_2 + 0x30) = 0;
          uVar15 = 0;
          goto LAB_140003e3c;
        }
        if (bVar1 != 0x16) {
          if (bVar1 == 0x17) {
            bVar6 = false;
            Sbp2AddLog((longlong)plVar3,1,0x53757052,*(longlong *)(plVar3[10] + 0x40),
                       (ulonglong)*(uint *)(*(longlong *)(plVar3[10] + 0x40) + 0x98));
            KeAcquireSpinLockRaiseToDpc(plVar3 + 0xb5);
            uVar8 = *(uint *)((longlong)plVar3 + 0x14);
            if ((uVar8 >> 0x15 & 1) == 0) {
              uVar11 = uVar8 | 0x440004;
              if ((uVar8 & 1) != 0) {
                bVar6 = true;
              }
            }
            else {
              uVar11 = uVar8 | 0x40004;
            }
            *(undefined4 *)((longlong)plVar3 + 0x104) = 0xc0000001;
            *(uint *)((longlong)plVar3 + 0x14) = uVar11 & 0xffdfc8ff;
            KeSetEvent(plVar3 + 0x5d,0);
            KeReleaseSpinLock(plVar3 + 0xb5);
            if (bVar6) {
              Sbp2EnableBusResetNotification(*(longlong *)(plVar3[10] + 0x40),'\0');
            }
            uVar7 = KfRaiseIrql(2);
            LOCK();
            plVar14 = (longlong *)plVar3[0x1b];
            plVar3[0x1b] = 0;
            UNLOCK();
            if (plVar14 != (longlong *)0x0) {
              Sbp2StartIo(*plVar3,plVar14);
            }
            Sbp2StartNextPacketByKey(param_1,0);
            KeLowerIrql(uVar7);
            Sbp2CleanDeviceExtension(param_1,1,0);
            *(undefined4 *)(param_2 + 0x30) = 0;
            goto LAB_140003e3c;
          }
          goto LAB_140003e39;
        }
        if (*(int *)(lVar4 + 0x10) == 1) {
          plVar14 = plVar3 + 0x1d;
        }
        else {
          if (*(int *)(lVar4 + 0x10) != 2) goto LAB_140003dc6;
          plVar14 = (longlong *)((longlong)plVar3 + 0xec);
        }
        if (plVar14 == (longlong *)0x0) goto LAB_140003dc6;
        uVar8 = Sbp2ForwardIrpSynchronous(plVar3[1],param_2);
        uVar15 = (ulonglong)uVar8;
        if (-1 < (int)uVar8) {
          if (*(char *)(lVar4 + 8) == '\0') {
            LOCK();
            *(int *)plVar14 = (int)*plVar14 + -1;
            UNLOCK();
          }
          else {
            LOCK();
            *(int *)plVar14 = (int)*plVar14 + 1;
            UNLOCK();
          }
        }
      }
LAB_140003e1b:
      *(int *)(param_2 + 0x30) = (int)uVar15;
    }
  }
  else {
LAB_140003e39:
    uVar15 = (ulonglong)*(uint *)(param_2 + 0x30);
  }
LAB_140003e3c:
  IoReleaseRemoveLockEx(plVar3 + 3,0,0x20);
LAB_14000351b:
  IofCompleteRequest(param_2,0);
  return uVar15;
}



===== Sbp2PortForwardIrpSynchronousCompletionRoutine @ 140003f20 =====

undefined8
Sbp2PortForwardIrpSynchronousCompletionRoutine
          (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,1);
  return 0xc0000016;
}



===== Sbp2PreAllocateLists @ 140003f4c =====

undefined8 Sbp2PreAllocateLists(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  longlong local_res8;
  
  *(uint *)((longlong)param_1 + 0x14) = *(uint *)((longlong)param_1 + 0x14) | 0xe;
  plVar1 = param_1 + 0xe;
  param_1[0xf] = (longlong)plVar1;
  *plVar1 = (longlong)plVar1;
  InitializeSListHead((PSLIST_HEADER)(param_1 + 0x9c));
  InitializeSListHead((PSLIST_HEADER)(param_1 + 0xb0));
  InitializeSListHead((PSLIST_HEADER)(param_1 + 0x98));
  ExInitializeNPagedLookasideList(param_1 + 0xa0,0,0,0x200,0x38,0x32706253,0);
  KeInitializeSpinLock(param_1 + 0xd);
  KeInitializeSpinLock(param_1 + 0xb5);
  KeInitializeSpinLock(param_1 + 0x9a);
  KeInitializeSpinLock(param_1 + 0xb3);
  KeInitializeSpinLock(param_1 + 0xb2);
  uVar7 = 0;
  do {
    lVar4 = ExAllocatePool2(0x40,0x30);
    local_res8 = lVar4;
    if (lVar4 == 0) goto LAB_1400043e6;
    lVar5 = ExAllocatePool2(0x40,0x298);
    *(longlong *)(lVar4 + 0x10) = lVar5;
    if (lVar5 == 0) {
LAB_1400043d2:
      ExFreePoolWithTag(lVar4,0x6b506253);
      goto LAB_1400043e6;
    }
    lVar5 = IoAllocateIrp(CONCAT71((int7)((ulonglong)param_1[1] >> 8),
                                   *(undefined1 *)(param_1[1] + 0x4c)),0);
    *(longlong *)(lVar4 + 0x18) = lVar5;
    if (lVar5 == 0) {
      ExFreePool(*(undefined8 *)(lVar4 + 0x10));
      goto LAB_1400043d2;
    }
    ExpInterlockedPushEntrySList((PSLIST_HEADER)(param_1 + 0xb0),lVar4);
    uVar7 = uVar7 + 1;
  } while (uVar7 < 8);
  lVar4 = ExAllocatePool2(0x40,0x400);
  param_1[0x9b] = lVar4;
  if (lVar4 != 0) {
    uVar7 = 0;
    lVar4 = 0;
    do {
      lVar6 = param_1[0x9b] + lVar4;
      lVar5 = IoAllocateMdl(lVar6 + 0x20,0x20,0,0,0);
      *(longlong *)(lVar6 + 0x10) = lVar5;
      if (lVar5 == 0) goto LAB_1400043e6;
      MmBuildMdlForNonPagedPool(lVar5);
      ExpInterlockedPushEntrySList((PSLIST_HEADER)(param_1 + 0x98),lVar6);
      uVar7 = uVar7 + 1;
      lVar4 = lVar4 + 0x40;
    } while (uVar7 < 0xf);
    lVar4 = ExAllocatePool2(0x40,0xa80);
    param_1[0xb4] = lVar4;
    if ((lVar4 != 0) &&
       (AllocateIrpAndIrb((longlong)param_1,&local_res8), lVar4 = local_res8, local_res8 != 0)) {
      uVar7 = 0;
      lVar5 = 0;
      do {
        lVar6 = param_1[0xb4];
        *(undefined4 *)(lVar5 + 0x20 + lVar6) = 0xadeaffab;
        KeInitializeDpc(lVar6 + 0xb0 + lVar5,Sbp2RequestTimeoutDpc,param_1);
        KeInitializeTimer(lVar6 + 0xf0 + lVar5);
        **(undefined4 **)(lVar4 + 0x10) = 0x11;
        *(undefined4 *)(*(longlong *)(lVar4 + 0x10) + 0x94) = 0x1000;
        *(undefined4 *)(*(longlong *)(lVar4 + 0x10) + 0xa0) = 0;
        *(undefined4 *)(*(longlong *)(lVar4 + 0x10) + 0x9c) = 1;
        *(undefined4 *)(*(longlong *)(lVar4 + 0x10) + 0x90) = 2;
        *(undefined8 *)(*(longlong *)(lVar4 + 0x10) + 0xa8) = 0;
        *(undefined8 *)(*(longlong *)(lVar4 + 0x10) + 0xb0) = 0;
        *(undefined2 *)(*(longlong *)(lVar4 + 0x10) + 0xb8) = 0;
        *(undefined4 *)(*(longlong *)(lVar4 + 0x10) + 0xbc) = 0;
        *(undefined8 *)(*(longlong *)(lVar4 + 0x10) + 0xc0) = 0;
        *(undefined8 *)(*(longlong *)(lVar4 + 0x10) + 200) = 0;
        *(undefined4 *)(*(longlong *)(lVar4 + 0x10) + 0xd0) = 0;
        *(longlong **)(*(longlong *)(lVar4 + 0x10) + 0xe8) = param_1;
        *(undefined8 *)(*(longlong *)(lVar4 + 0x10) + 0x88) = *(undefined8 *)(lVar5 + 0x90 + lVar6);
        *(undefined4 *)(*(longlong *)(lVar4 + 0x10) + 0x98) = 0x8000;
        *(longlong *)(*(longlong *)(lVar4 + 0x10) + 0xd8) = lVar6 + 0x78 + lVar5;
        iVar3 = Sbp2SendRequest((longlong)param_1,lVar4,(undefined *)0x2);
        if (iVar3 < 0) {
          DeAllocateIrpAndIrb((longlong)param_1,lVar4);
          goto LAB_1400043e6;
        }
        *(undefined8 *)(lVar5 + 0x90 + lVar6) = *(undefined8 *)(*(longlong *)(lVar4 + 0x10) + 0x88);
        lVar2 = *(longlong *)(*(longlong *)(lVar4 + 0x10) + 0x88);
        *(ulonglong *)(lVar5 + 0x68 + lVar6) =
             (ulonglong)*(uint *)(lVar2 + 0x2c) + *(longlong *)(lVar2 + 0x20);
        *(undefined8 *)(lVar5 + 0x88 + lVar6) = *(undefined8 *)(*(longlong *)(lVar4 + 0x10) + 0xe0);
        *(undefined2 *)(lVar5 + 0x7a + lVar6) = *(undefined2 *)((longlong)param_1 + 0x19a);
        *(undefined4 *)(lVar5 + 0x60 + lVar6) = 0x200;
        ExpInterlockedPushEntrySList((PSLIST_HEADER)(param_1 + 0x9c),lVar6 + 0x10 + lVar5);
        uVar7 = uVar7 + 1;
        lVar5 = lVar5 + 0x150;
      } while (uVar7 < 8);
      DeAllocateIrpAndIrb((longlong)param_1,lVar4);
      lVar4 = IoAllocateMdl(param_1 + 0x20,4,0,0,0);
      param_1[0x21] = lVar4;
      if (lVar4 != 0) {
        MmBuildMdlForNonPagedPool(lVar4);
        return 0;
      }
    }
  }
LAB_1400043e6:
  *(uint *)((longlong)param_1 + 0x14) = *(uint *)((longlong)param_1 + 0x14) | 0x40000;
  Sbp2CleanDeviceExtension(*param_1,1,0);
  return 0xc000009a;
}



===== Sbp2RequestTimeoutDpc @ 140004430 =====

void Sbp2RequestTimeoutDpc(longlong *param_1,longlong *param_2)

{
  uint *puVar1;
  longlong *plVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  int iVar6;
  uint uVar7;
  longlong *plVar8;
  undefined1 uVar9;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  iVar6 = -0x3fffff4b;
  AcquireOrbListLock((longlong)param_2,&local_38,'\x01');
  plVar8 = param_2 + 0xe;
  uVar9 = SUB81(param_1,0);
  if ((longlong *)*plVar8 == plVar8) {
    ReleaseOrbListLock((longlong)param_2,&local_38,'\x01');
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qq(WPP_GLOBAL_Control[3],0x34,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,param_2,
                uVar9);
    }
  }
  else {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qq(WPP_GLOBAL_Control[3],0x35,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,param_2,
                uVar9);
    }
    if ((*(uint *)((longlong)param_2 + 0x14) >> 0x12 & 1) == 0) {
      plVar8 = (longlong *)*plVar8;
      if (((*(ushort *)((longlong)param_2 + 0x9a) & 0xc000) == 0x4000) &&
         (puVar1 = (uint *)(plVar8 + 7), ((byte)*puVar1 & 0x21) == 1)) {
        if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
            (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
          WPP_SF_qqD(WPP_GLOBAL_Control[3],0x37,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,
                     param_2,(char)*(undefined8 *)(plVar8[6] + 0x30),
                     (char)*(uint *)((longlong)param_2 + 0x14));
        }
        if (*(char *)(*(longlong *)(plVar8[6] + 0x30) + 0x44) == '\0') {
          *puVar1 = *puVar1 | 0x20;
          KeSetTimer(plVar8 + 0x1e,0xfffffffffd050f80,plVar8 + 0x16);
          iVar6 = Sbp2AccessRegisterEx((longlong)param_2,(uint *)(param_2 + 0x20),0x408,-1);
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_qDd(WPP_GLOBAL_Control[3],0x38,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,
                       param_2,(char)iVar6,(char)*(undefined4 *)((longlong)param_2 + 0x14));
          }
          if (-1 < iVar6) {
LAB_14000475f:
            ReleaseOrbListLock((longlong)param_2,&local_38,'\x01');
            return;
          }
        }
      }
      uVar3 = *(uint *)(plVar8 + 7);
      if ((((uVar3 & 0x20) != 0) &&
          (*(uint *)(plVar8 + 7) = uVar3 & 0xffffffdf,
          (undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
          (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
        WPP_SF_(WPP_GLOBAL_Control[3],0x39,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids);
      }
      do {
        if ((plVar8 + 0x16 == param_1) && (uVar3 = *(uint *)(plVar8 + 7), (uVar3 & 1) != 0)) {
          if ((uVar3 & 2) != 0) {
            if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              WPP_SF_qq(WPP_GLOBAL_Control[3],0x3a,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,
                        *(undefined8 *)(plVar8[6] + 0x30),(char)param_2);
            }
            goto LAB_14000475f;
          }
          *(uint *)(plVar8 + 7) = uVar3 & 0xfffffffe;
          KeCancelTimer(plVar8 + 0x1e);
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            lVar5 = plVar8[6];
            WPP_SF_qqdDD(WPP_GLOBAL_Control[3],(ulonglong)*(byte *)(lVar5 + 0x48),lVar5,param_2,
                         (char)*(undefined8 *)(lVar5 + 0x30),(char)*(undefined4 *)(lVar5 + 0x14),
                         *(byte *)(lVar5 + 0x48),(char)*(undefined4 *)((longlong)param_2 + 0x14));
          }
          Sbp2AddLog((longlong)param_2,0x40,0x494f546f,plVar8[6],plVar8);
          ReleaseOrbListLock((longlong)param_2,&local_38,'\x01');
          CleanupOrbList(param_2,-0x3fffff4b);
          plVar2 = param_2 + 0xb5;
          KeAcquireSpinLockAtDpcLevel(plVar2);
          iVar4 = *(int *)((longlong)param_2 + 0x64c);
          uVar3 = *(uint *)((longlong)param_2 + 0x14);
          uVar7 = iVar4 + 1;
          *(uint *)((longlong)param_2 + 0x64c) = uVar7;
          if ((uVar3 >> 0xd & 1) != 0) {
            KeReleaseSpinLockFromDpcLevel(plVar2);
            Sbp2AddLog((longlong)param_2,0x40,0x494f5431,plVar8[6],plVar8);
            return;
          }
          if (2 < uVar7) {
            *(uint *)((longlong)param_2 + 0x14) = uVar3 | 0x100008;
            if ((uVar3 & 2) != 0) {
              KeSetEvent(param_2 + 0x60,0,0);
            }
            KeReleaseSpinLockFromDpcLevel(plVar2);
            Sbp2CreateRequestErrorLog(*param_2,(longlong)plVar8,0xc12,-0x3fffff4b);
            Sbp2StartQueue(param_2);
            IoInvalidateDeviceState(*param_2);
            return;
          }
          KeReleaseSpinLockFromDpcLevel(plVar2);
          iVar6 = Sbp2UpdateNodeInformation(param_2);
          if ((-1 < iVar6) && (iVar6 = Sbp2Reset(*param_2,iVar4 + 2), -1 < iVar6)) {
            return;
          }
          goto LAB_1400046f2;
        }
        plVar8 = (longlong *)*plVar8;
      } while (plVar8 != (longlong *)param_2[0xf]);
      ReleaseOrbListLock((longlong)param_2,&local_38,'\x01');
      if (iVar6 < 0) {
LAB_1400046f2:
        CleanupOrbList(param_2,iVar6);
      }
      Sbp2RestartPendingPowerIrp(param_2);
    }
    else {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_qq(WPP_GLOBAL_Control[3],0x36,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,
                  param_2,uVar9);
      }
      ReleaseOrbListLock((longlong)param_2,&local_38,'\x01');
      CleanupOrbList(param_2,-0x3fffff40);
    }
  }
  return;
}



===== Sbp2Reset @ 14000491c =====

int Sbp2Reset(longlong param_1,int param_2)

{
  uint *puVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined1 uVar5;
  byte bVar6;
  int iVar7;
  ulonglong uVar8;
  uint uVar9;
  undefined8 *puVar10;
  int iVar11;
  
  plVar3 = *(longlong **)(param_1 + 0x40);
  iVar7 = 0;
  plVar2 = plVar3 + 0xb5;
  iVar11 = 2;
  lVar4 = *(longlong *)(plVar3[10] + 0x40);
  uVar5 = KeAcquireSpinLockRaiseToDpc(plVar2);
  if ((*(uint *)((longlong)plVar3 + 0x14) & 0x40100) == 0) {
    KeReleaseSpinLock(plVar2,uVar5);
    do {
      puVar10 = &WPP_GLOBAL_Control;
      iVar11 = iVar11 + -1;
      Sbp2AddLog((longlong)plVar3,1,0x7273743e,(longlong)param_2,0);
      if (param_2 == 0) {
        if (((WPP_GLOBAL_Control != puVar10) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_q(WPP_GLOBAL_Control[3],0x3d,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,
                   plVar3);
        }
        iVar11 = 0;
      }
      else if (param_2 == 1) {
        if (((WPP_GLOBAL_Control != puVar10) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_q(WPP_GLOBAL_Control[3],0x3e,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,
                   plVar3);
        }
        bVar6 = KeGetCurrentIrql();
        puVar1 = (uint *)(plVar3 + 0x20);
        *puVar1 = 0xf;
        Sbp2AccessRegisterEx((longlong)plVar3,puVar1,(-(ushort)(bVar6 < 2) & 0xfd00) + 0x440,-1);
        iVar7 = Sbp2AccessRegisterEx
                          ((longlong)plVar3,puVar1,(-(ushort)(bVar6 < 2) & 0xfd00) + 0x402,-1);
      }
      else if (param_2 == 2) {
        if (((WPP_GLOBAL_Control != puVar10) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_q(WPP_GLOBAL_Control[3],0x3f,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,
                   plVar3);
        }
        iVar11 = 0;
        uVar5 = KeAcquireSpinLockRaiseToDpc(plVar2);
        *(undefined4 *)(plVar3 + 0x53) = 0xc;
        *(undefined4 *)(plVar3[0x4d] + 0x10) = 0;
        *(ushort *)(plVar3[0x4d] + 0x12) = *(ushort *)(plVar3[0x4d] + 0x12) | 0x8000;
        *(ushort *)(plVar3[0x4d] + 0x12) = *(ushort *)(plVar3[0x4d] + 0x12) | 0xc;
        *(undefined2 *)(plVar3[0x4d] + 0x10) = *(undefined2 *)plVar3[99];
        *(longlong *)(plVar3[0x4d] + 0x18) = plVar3[0x8a];
        uVar9 = *(uint *)(plVar3[0x4d] + 0x18);
        *(uint *)(plVar3[0x4d] + 0x18) =
             uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 << 0x18;
        uVar9 = *(uint *)(plVar3[0x4d] + 0x1c);
        *(uint *)(plVar3[0x4d] + 0x1c) =
             uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 << 0x18;
        uVar9 = *(uint *)(plVar3[0x4d] + 0x10);
        *(uint *)(plVar3[0x4d] + 0x10) =
             uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 << 0x18;
        *(uint *)((longlong)plVar3 + 0x14) = *(uint *)((longlong)plVar3 + 0x14) | 0x2000;
        Sbp2SetManagementTimer((longlong)plVar3,2);
        KeReleaseSpinLock(plVar2,uVar5);
        CleanupOrbList(plVar3,-0x3ffffdc0);
        iVar7 = Sbp2AccessRegisterEx((longlong)plVar3,(uint *)(plVar3 + 0x4f),0x400,-1);
      }
      else {
        if (((WPP_GLOBAL_Control != puVar10) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_q(WPP_GLOBAL_Control[3],0x40,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,
                   plVar3);
        }
        uVar5 = KeAcquireSpinLockRaiseToDpc(plVar2);
        uVar9 = *(uint *)((longlong)plVar3 + 0x14) & 0xffffdbff;
        *(uint *)((longlong)plVar3 + 0x14) = uVar9 | 8;
        if ((*(uint *)(lVar4 + 0x14) & 0x1000000) != 0) {
          *(uint *)((longlong)plVar3 + 0x14) = uVar9 | 0x2000808;
        }
        KeReleaseSpinLock(plVar2,uVar5);
        CleanupOrbList(plVar3,-0x3ffffdc0);
        uVar8 = Sbp2QueueManagementWorkItem(plVar3,4,0xffffffff);
        iVar7 = (int)uVar8;
      }
      Sbp2AddLog((longlong)plVar3,1,0x72737431,(longlong)iVar7,(longlong)iVar11);
      if ((iVar7 != -0x3fedff70) && (iVar7 != -0x3ffffdc0)) {
        if (iVar7 < 0) {
          KeCancelTimer(plVar3 + 0xbe);
          IoInvalidateDeviceState(*plVar3);
        }
        break;
      }
      if (iVar11 == 0) {
        if (2 < param_2) {
          KeAcquireSpinLockRaiseToDpc(plVar2);
          *(uint *)((longlong)plVar3 + 0x14) =
               *(uint *)((longlong)plVar3 + 0x14) & 0xffffdbff | 0x100008;
          KeReleaseSpinLock(plVar2);
          LOCK();
          plVar2 = (longlong *)plVar3[0x1b];
          plVar3[0x1b] = 0;
          UNLOCK();
          if (plVar2 != (longlong *)0x0) {
            Sbp2StartIo(*plVar3,plVar2);
          }
          Sbp2StartNextPacketByKey(*plVar3,0);
        }
        break;
      }
      KeCancelTimer(plVar3 + 0xbe);
      iVar7 = Sbp2UpdateNodeInformation(plVar3);
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_qDd(WPP_GLOBAL_Control[3],0x41,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,
                   plVar3,(char)iVar7,(char)*(undefined4 *)((longlong)plVar3 + 0x19c));
      }
    } while (0 < iVar11);
  }
  else {
    KeReleaseSpinLock();
    iVar7 = -0x3fffff40;
  }
  return iVar7;
}



===== Sbp2StartDevice @ 140004db4 =====

int Sbp2StartDevice(longlong param_1,ulonglong param_2,undefined8 param_3,undefined8 param_4)

{
  uint *puVar1;
  longlong *plVar2;
  byte bVar3;
  bool bVar4;
  int iVar5;
  undefined8 uVar6;
  longlong lVar7;
  byte bVar8;
  uint uVar9;
  wchar_t *pwVar10;
  undefined1 uVar11;
  undefined4 uVar12;
  wchar_t *pwVar13;
  
  plVar2 = *(longlong **)(param_1 + 0x40);
  uVar12 = 0;
  bVar4 = false;
  if ((int)plVar2[2] != 0x4f445073) {
    if ((int)plVar2[2] != 0x4f444673) {
      return -0x3ffffff2;
    }
    *(undefined4 *)(plVar2 + 7) = 0x1ff000;
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qd(WPP_GLOBAL_Control[3],0x1d,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,plVar2,0
               );
    }
    *(undefined4 *)(plVar2 + 10) = 1;
    *(undefined4 *)((longlong)plVar2 + 0x54) = 1;
    *(undefined4 *)((longlong)plVar2 + 0x14) = 1;
    return 0;
  }
  if ((*(uint *)((longlong)plVar2 + 0x14) >> 0x12 & 1) != 0) {
    return -0x3ffffd4a;
  }
  if ((*(uint *)((longlong)plVar2 + 0x14) & 1) == 0) {
    param_2 = plVar2[0xb];
    lVar7 = *(longlong *)(plVar2[10] + 0x40);
    Sbp2ConfigLegacyDevice(param_1,param_2);
    *(undefined4 *)((longlong)plVar2 + 0xc4) = 1;
    *(undefined4 *)(plVar2 + 0x19) = 1;
    *(undefined4 *)(plVar2 + 0xc) = 8;
    if ((*(uint *)(plVar2[0xb] + 0x38) & 0x100) != 0) {
      puVar1 = (uint *)(lVar7 + 0x14);
      *puVar1 = *puVar1 | 0x1000000;
    }
  }
  *(uint *)((longlong)plVar2 + 0x14) = *(uint *)((longlong)plVar2 + 0x14) | 0xe;
  iVar5 = Sbp2InitializeDeviceExtension(plVar2,param_2,param_3,param_4);
  if (iVar5 < 0) {
    uVar12 = 0x3ac;
  }
  else {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qd(WPP_GLOBAL_Control[3],0x11,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,plVar2,
                (char)*(undefined4 *)(plVar2[0xb] + 0xc));
    }
    iVar5 = *(int *)(plVar2[0xb] + 0xc);
    if ((((iVar5 == 0) || (iVar5 == 0x10483)) || (iVar5 == 0x104d8)) &&
       (((*(uint *)((longlong)plVar2 + 0x14) = *(uint *)((longlong)plVar2 + 0x14) | 0x10,
         (undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control &&
         ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
        (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
      WPP_SF_q(WPP_GLOBAL_Control[3],0x12,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,plVar2);
    }
    iVar5 = Sbp2EnableBusResetNotification(*(longlong *)(plVar2[10] + 0x40),'\x01');
    if (iVar5 < 0) {
      *(uint *)((longlong)plVar2 + 0x14) = *(uint *)((longlong)plVar2 + 0x14) & 0xfffffbff | 8;
      CleanupOrbList(plVar2,-0x3ffffdc0);
      uVar12 = 0x3ce;
      goto LAB_1400053a1;
    }
    bVar4 = true;
    KeResetEvent(plVar2 + 0x60);
    iVar5 = Sbp2Issue1394BusReset(plVar2);
    if (iVar5 < 0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_qd(WPP_GLOBAL_Control[3],0x13,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,plVar2
                  ,(char)iVar5);
      }
      uVar6 = IsDeviceGone(plVar2,iVar5);
      if ((char)uVar6 != '\0') {
        uVar12 = 0x3e4;
        goto LAB_1400053a1;
      }
    }
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      lVar7 = plVar2[0xb];
      if (((lVar7 == 0) || (pwVar10 = *(wchar_t **)(lVar7 + 0x60), pwVar10 == (wchar_t *)0x0)) &&
         (pwVar10 = L"Unknown", lVar7 == 0)) {
        uVar11 = 0;
      }
      else {
        uVar11 = (undefined1)*(undefined2 *)(lVar7 + 8);
      }
      uVar9 = (2 << ((byte)*(undefined4 *)(lVar7 + 0x44) & 0x1f)) * 1000 - 1000;
      WPP_SF_qdSdd(WPP_GLOBAL_Control[3],(ulonglong)uVar9,lVar7,plVar2,uVar11,pwVar10,
                   (char)*(undefined4 *)(lVar7 + 0x40),(char)uVar9);
    }
    pwVar13 = (wchar_t *)0x0;
    uVar6 = 0;
    pwVar10 = (wchar_t *)0x0;
    iVar5 = KeWaitForSingleObject(plVar2 + 0x60);
    if (iVar5 == 0) {
      iVar5 = *(int *)((longlong)plVar2 + 0x104);
    }
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      if ((plVar2[0xb] == 0) ||
         (pwVar10 = *(wchar_t **)(plVar2[0xb] + 0x60), pwVar10 == (wchar_t *)0x0)) {
        pwVar10 = L"Unknown";
      }
      pwVar13 = pwVar10;
      WPP_SF_qSDD(WPP_GLOBAL_Control[3],pwVar10,uVar6,plVar2,pwVar10,(char)iVar5,
                  (char)*(undefined4 *)((longlong)plVar2 + 0x14));
    }
    if (((*(uint *)((longlong)plVar2 + 0x14) & 0x400) == 0) ||
       (*(int *)((longlong)plVar2 + 0x104) != 0)) {
      if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
          (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
        if ((plVar2[0xb] == 0) ||
           (pwVar13 = *(wchar_t **)(plVar2[0xb] + 0x60), pwVar13 == (wchar_t *)0x0)) {
          pwVar13 = L"Unknown";
        }
        WPP_SF_qSD(WPP_GLOBAL_Control[3],pwVar10,uVar6,plVar2,pwVar13,(char)iVar5);
      }
      uVar12 = 0x41b;
    }
    else {
      Sbp2AccessRegisterEx((longlong)plVar2,(uint *)(plVar2 + 0x20),0x102,-1);
      Sbp2AccessRegisterEx((longlong)plVar2,(uint *)(plVar2 + 0x20),0x110,-1);
      *(uint *)((longlong)plVar2 + 0x14) = *(uint *)((longlong)plVar2 + 0x14) & 0xfffffff3;
      if (plVar2[0x1f] == 0) {
        lVar7 = PoRegisterDeviceForIdleDetection(param_1,0xffffffff,0xffffffff,4,pwVar13);
        plVar2[0x1f] = lVar7;
      }
      uVar9 = *(uint *)((longlong)plVar2 + 0x14);
      *(uint *)((longlong)plVar2 + 0x14) = uVar9 & 0xfffffffd | 1;
      if ((uVar9 & 0x10) != 0) {
        iVar5 = Sbp2IssueInternalCommand(plVar2,0x12);
        if (iVar5 < 0) {
          if ((iVar5 == -0x3fffff40) || (iVar5 == -0x7fffffef)) {
            if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
                (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
              WPP_SF_qd(WPP_GLOBAL_Control[3],0x18,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,
                        plVar2,(char)iVar5);
            }
            if ((*(uint *)((longlong)plVar2 + 0x14) >> 10 & 1) != 0) {
              *(uint *)((longlong)plVar2 + 0x14) = *(uint *)((longlong)plVar2 + 0x14) & 0xfffffbff;
              Sbp2ManagementTransaction(plVar2,7,-1);
            }
            iVar5 = -0x3ffffe7b;
            uVar12 = 0x46f;
            goto LAB_1400053a1;
          }
          *(uint *)((longlong)plVar2 + 0x14) = *(uint *)((longlong)plVar2 + 0x14) & 0xffffffef;
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_qd(WPP_GLOBAL_Control[3],0x19,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,
                      plVar2,(char)iVar5);
          }
          iVar5 = 0;
        }
        else if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_qDd(WPP_GLOBAL_Control[3],0x17,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,
                     plVar2,(byte)*(undefined2 *)(plVar2[0xb] + 10) & 0x1f,
                     *(byte *)(plVar2 + 0x22) & 0x1f);
        }
      }
      bVar8 = *(byte *)(plVar2 + 0x22);
      bVar3 = (byte)*(undefined2 *)(plVar2[0xb] + 10);
      if ((bVar8 & 0x1f) != (bVar3 & 0x1f)) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_qDd(WPP_GLOBAL_Control[3],0x1a,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,
                     plVar2,bVar8 & 0x1f,bVar3 & 0x1f);
        }
        bVar8 = (*(byte *)(plVar2 + 0x22) ^ *(byte *)(plVar2[0xb] + 10)) & 0x1f ^
                *(byte *)(plVar2 + 0x22);
        *(byte *)(plVar2 + 0x22) = bVar8;
      }
      if (((bVar8 & 0x1f) - 2 & 0xfb) == 0) {
        if (iVar5 < 0) goto LAB_1400053a1;
        *(uint *)((longlong)plVar2 + 0x14) = *(uint *)((longlong)plVar2 + 0x14) & 0xfffffbff | 8;
        CleanupOrbList(plVar2,-0x3ffffdc0);
        Sbp2ManagementTransaction(plVar2,7,-1);
        goto LAB_140005344;
      }
      if ((bVar8 & 0x1f) == 0xe) {
        if (-1 < iVar5) {
          iVar5 = Sbp2IssueInternalCommand(plVar2,0x1a);
          if (-1 < iVar5) goto LAB_140005344;
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_q(WPP_GLOBAL_Control[3],0x1b,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,
                     plVar2);
          }
          uVar12 = 0x4ab;
        }
        goto LAB_1400053a1;
      }
    }
    if (-1 < iVar5) {
LAB_140005344:
      *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xffffdfff;
      return iVar5;
    }
  }
LAB_1400053a1:
  Sbp2CreateRequestErrorLog(param_1,0,uVar12,iVar5);
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
     (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qd(WPP_GLOBAL_Control[3],0x1c,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,plVar2,
              (char)iVar5);
  }
  *(uint *)((longlong)plVar2 + 0x14) = *(uint *)((longlong)plVar2 + 0x14) | 0x100004;
  if (bVar4) {
    Sbp2EnableBusResetNotification(*(longlong *)(plVar2[10] + 0x40),'\0');
  }
  return iVar5;
}



===== Sbp2Unload @ 140005490 =====

void Sbp2Unload(void)

{
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
     (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_(WPP_GLOBAL_Control[3],0x29,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids);
  }
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



===== WPP_SF_ @ 140005524 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_D @ 140005550 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_S @ 140005594 =====

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
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,lVar1,0);
  return;
}



===== WPP_SF_q @ 140005604 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,0);
  return;
}



===== WPP_SF_qd @ 140005648 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,4,0);
  return;
}



===== WPP_SF_qDd @ 14000569c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_qDdd @ 1400056fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDdd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,0x20,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_qS @ 140005770 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qS(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
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
            (param_1,0x2b,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,param_2,&local_res20,8,
             param_5,lVar1,0);
  return;
}



===== WPP_SF_qSD @ 140005804 =====

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
            (param_1,0x2b,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,0x16,&local_res20,8,
             param_5,lVar1,&param_6,4,0);
  return;
}



===== WPP_SF_qSDD @ 1400058b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qSDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                wchar_t *param_5,undefined1 param_6,undefined1 param_7)

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
            (param_1,0x2b,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,0x15,&local_res20,8,
             param_5,lVar1,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_qdSdd @ 140005978 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qdSdd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,wchar_t *param_6,undefined1 param_7,undefined1 param_8)

{
  longlong lVar1;
  wchar_t *pwVar2;
  undefined8 local_res20;
  
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
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,0x14,&local_res20,8,
             &param_5,4,pwVar2,lVar1,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_SF_qq @ 140005a54 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,0);
  return;
}



===== WPP_SF_qqD @ 140005aa4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,&param_6,4,0);
  return;
}



===== WPP_SF_qqdDD @ 140005b04 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqdDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,0x3b,&local_res20,8,
             &param_5,8,&param_6,4,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_SF_qqq @ 140005b88 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,&param_6,8,0);
  return;
}



===== WppClassicProviderCallback @ 140005bf0 =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 140005c24 =====

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
LAB_140005e2d:
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
LAB_140005cff:
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
      if (param_3 == 4) goto LAB_140005e2d;
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
        goto LAB_140005cff;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140005f18 =====

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
      goto LAB_140005fe9;
    }
    if (param_3 == 2) {
      uVar3 = (uVar2 ^ 1) * 4 + 1;
      goto LAB_140005fe9;
    }
    if (param_3 == 3) {
      uVar3 = (uVar2 ^ 1) * 4 + 2;
      goto LAB_140005fe9;
    }
    if (param_3 == 4) {
      uVar3 = (uVar2 ^ 1) * 4 + 3;
      goto LAB_140005fe9;
    }
    if (param_3 == 5) {
      uVar3 = (uVar2 ^ 1) * 2 + 8;
      goto LAB_140005fe9;
    }
    if (param_3 == 6) {
      uVar3 = (uVar2 ^ 1) * 2 + 9;
      goto LAB_140005fe9;
    }
    bVar4 = (char)param_3 + 0x9c;
    if (bVar4 < 0x32) {
      uVar3 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar4;
      goto LAB_140005fe9;
    }
  }
  uVar3 = 0xff;
LAB_140005fe9:
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



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140006040 =====

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



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140006130 =====

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
LAB_1400061e3:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_140006211;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_1400061e3;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_140006211:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 14000639c =====

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



===== wil_details_IsEnabledFallback @ 140006400 =====

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



===== wil_details_RecordCachedUsage @ 140006494 =====

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



===== wil_details_RecordFeatureUsageReporting @ 1400065f0 =====

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



===== Feature_3834274106__private_IsEnabledDeviceUsageNoInline @ 140006674 =====

ulonglong Feature_3834274106__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)(uint)Feature_3834274106__private_featureState;
  if (((uint)Feature_3834274106__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3834274106__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)((uint)Feature_3834274106__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3834274106__private_IsEnabledFallback @ 1400066ac =====

void Feature_3834274106__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_3834274106__private_descriptor);
  return;
}



===== Sbp2AccessRegisterEx @ 1400066c8 =====

int Sbp2AccessRegisterEx(longlong param_1,uint *param_2,ushort param_3,int param_4)

{
  bool bVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  uint uVar5;
  uint *puVar6;
  char cVar7;
  longlong local_res8;
  
  local_res8 = 0;
  bVar1 = false;
  if ((*(uint *)(param_1 + 0x14) & 0x40000) != 0) {
    return -0x3fffff40;
  }
  AllocateIrpAndIrb(param_1,&local_res8);
  lVar2 = local_res8;
  if (local_res8 == 0) {
    return -0x3fffff66;
  }
  cVar7 = (char)param_3;
  if ((cVar7 != '\0') || (param_4 == -1)) {
    param_4 = *(int *)(param_1 + 0x19c);
  }
  *(undefined4 *)(*(longlong *)(local_res8 + 0x10) + 4) = 0;
  if (cVar7 == '\0') {
LAB_140006876:
    if ((param_3 & 0x500) == 0) {
      **(undefined4 **)(local_res8 + 0x10) = 0;
      if ((param_3 & 4) == 0) {
        *(undefined4 *)(*(longlong *)(local_res8 + 0x10) + 0x90) =
             *(undefined4 *)(*(longlong *)(param_1 + 0x58) + 0x24);
      }
      else {
        *(int *)(*(longlong *)(local_res8 + 0x10) + 0x90) =
             *(int *)(*(longlong *)(param_1 + 0x58) + 0x2c) + 8;
      }
      *(undefined2 *)(*(longlong *)(local_res8 + 0x10) + 0x8c) =
           *(undefined2 *)(*(longlong *)(param_1 + 0x58) + 0x28);
      puVar6 = param_2;
    }
    else {
      uVar4 = *(undefined8 *)param_2;
      puVar6 = (uint *)(local_res8 + 0x20);
      *(undefined8 *)puVar6 = uVar4;
      uVar5 = (uint)uVar4;
      *puVar6 = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
      uVar5 = *(uint *)(local_res8 + 0x24);
      *(uint *)(local_res8 + 0x24) =
           uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
      **(undefined4 **)(local_res8 + 0x10) = 1;
      *(undefined2 *)(*(longlong *)(local_res8 + 0x10) + 0x8c) = 0xffff;
      if ((param_3 & 4) == 0) {
        *(uint *)(*(longlong *)(local_res8 + 0x10) + 0x90) =
             *(uint *)(*(longlong *)(param_1 + 0x58) + 0x24) | 0xf0000000;
      }
      else {
        *(uint *)(*(longlong *)(local_res8 + 0x10) + 0x90) =
             *(int *)(*(longlong *)(param_1 + 0x58) + 0x2c) + 8U | 0xf0000000;
      }
    }
    uVar4 = IoAllocateMdl(puVar6,8,0,0,0);
    *(undefined8 *)(*(longlong *)(lVar2 + 0x10) + 0xa0) = uVar4;
    if (*(longlong *)(*(longlong *)(lVar2 + 0x10) + 0xa0) == 0) {
      DeAllocateIrpAndIrb(param_1,lVar2);
      return -0x3fffff66;
    }
    *(undefined4 *)(*(longlong *)(lVar2 + 0x10) + 0x94) = 8;
    bVar1 = true;
    *(undefined4 *)(*(longlong *)(lVar2 + 0x10) + 0x98) = 0;
    *(undefined4 *)(*(longlong *)(lVar2 + 0x10) + 0x9c) = 0;
    *(int *)(*(longlong *)(lVar2 + 0x10) + 0xa8) = param_4;
    MmBuildMdlForNonPagedPool(*(undefined8 *)(*(longlong *)(lVar2 + 0x10) + 0xa0));
    goto LAB_1400069b1;
  }
  if (cVar7 != '\x02') {
    if (cVar7 == '\x04') goto LAB_140006876;
    if ((((cVar7 != '\b') && (cVar7 != '\x10')) && (cVar7 != ' ')) &&
       ((cVar7 != '@' && (cVar7 != -0x80)))) goto LAB_1400069b1;
  }
  **(undefined4 **)(local_res8 + 0x10) = 1;
  *(undefined4 *)(*(longlong *)(local_res8 + 0x10) + 0x9c) = 0;
  *(undefined2 *)(*(longlong *)(local_res8 + 0x10) + 0x8c) = 0xffff;
  if (cVar7 == '\x02') {
    uVar5 = *(int *)(*(longlong *)(param_1 + 0x58) + 0x2c) + 4;
LAB_14000682f:
    *(uint *)(*(longlong *)(local_res8 + 0x10) + 0x90) = uVar5 | 0xf0000000;
  }
  else {
    if (cVar7 == '\b') {
      puVar6 = (uint *)(*(longlong *)(local_res8 + 0x10) + 0x9c);
      *puVar6 = *puVar6 | 2;
      uVar5 = *(int *)(*(longlong *)(param_1 + 0x58) + 0x2c) + 0x10;
      goto LAB_14000682f;
    }
    if (cVar7 == '\x10') {
      uVar5 = *(int *)(*(longlong *)(param_1 + 0x58) + 0x2c) + 0x14;
      goto LAB_14000682f;
    }
    if (cVar7 == ' ') {
      *(undefined4 *)(*(longlong *)(local_res8 + 0x10) + 0x90) = 0xf000000c;
    }
    else {
      if (cVar7 == '@') {
        *(undefined4 *)(*(longlong *)(local_res8 + 0x10) + 0x90) = 0xf0000210;
      }
      else {
        if (cVar7 != -0x80) goto LAB_14000683f;
        *(undefined4 *)(*(longlong *)(local_res8 + 0x10) + 0x90) = 0xf0010020;
      }
      uVar5 = *param_2;
      *param_2 = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
    }
  }
LAB_14000683f:
  *(undefined8 *)(*(longlong *)(local_res8 + 0x10) + 0xa0) = *(undefined8 *)(param_1 + 0x108);
  *(undefined4 *)(*(longlong *)(local_res8 + 0x10) + 0x94) = 4;
  *(undefined4 *)(*(longlong *)(local_res8 + 0x10) + 0x98) = 0;
  *(int *)(*(longlong *)(local_res8 + 0x10) + 0xa8) = param_4;
LAB_1400069b1:
  if ((param_3 >> 10 & 1) == 0) {
    iVar3 = Sbp2SendRequest(param_1,lVar2,(undefined *)0x2);
    if (bVar1) {
      IoFreeMdl(*(undefined8 *)(*(longlong *)(lVar2 + 0x10) + 0xa0));
      *(undefined8 *)(*(longlong *)(lVar2 + 0x10) + 0xa0) = 0;
    }
    if (((-1 < iVar3) && ((param_3 >> 9 & 1) != 0)) && ((param_3 & 0xfb) == 0)) {
      uVar4 = *(undefined8 *)param_2;
      *(undefined8 *)(lVar2 + 0x20) = uVar4;
      uVar5 = (uint)uVar4;
      *(uint *)(lVar2 + 0x20) =
           uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
      uVar5 = *(uint *)(lVar2 + 0x24);
      *(uint *)(lVar2 + 0x24) =
           uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
      *(undefined8 *)param_2 = *(undefined8 *)(lVar2 + 0x20);
    }
  }
  else {
    iVar3 = Sbp2SendRequest(param_1,lVar2,(undefined *)0x1);
    if (-1 < iVar3) {
      return iVar3;
    }
    if (*(int *)(*(longlong *)(lVar2 + 0x18) + 0x30) != 0x103) {
      return iVar3;
    }
  }
  DeAllocateIrpAndIrb(param_1,lVar2);
  return iVar3;
}



===== Sbp2BusResetNotification @ 140006a80 =====

void Sbp2BusResetNotification(undefined8 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  longlong lVar3;
  undefined2 uVar4;
  
  if (*(int *)(param_1 + 2) != 0x4f444673) {
    if ((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return;
    }
    if (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2) {
      return;
    }
    uVar4 = 0x10;
LAB_140006c18:
    WPP_SF_q(WPP_GLOBAL_Control[3],uVar4,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1);
    return;
  }
  iVar1 = IoAcquireRemoveLockEx(param_1 + 3,0,"",1,0x20);
  if (iVar1 < 0) {
    if ((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return;
    }
    if (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2) {
      return;
    }
    uVar4 = 0x13;
    goto LAB_140006c18;
  }
  puVar2 = (undefined4 *)ExAllocatePool2(0x40,0x10,0x6b776253);
  if (puVar2 == (undefined4 *)0x0) {
    if ((((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2)) goto LAB_140006bdb;
    uVar4 = 0x11;
  }
  else {
    lVar3 = IoAllocateWorkItem(*param_1);
    *(longlong *)(puVar2 + 2) = lVar3;
    if (lVar3 != 0) {
      *puVar2 = 0xffffffff;
      IoQueueWorkItem(lVar3,Sbp2BusResetNotificationWorker,0,puVar2);
      return;
    }
    ExFreePoolWithTag(puVar2,0x6b776253);
    if ((((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2)) goto LAB_140006bdb;
    uVar4 = 0x12;
  }
  WPP_SF_q(WPP_GLOBAL_Control[3],uVar4,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1);
LAB_140006bdb:
  IoReleaseRemoveLockEx(param_1 + 3,0,0x20);
  return;
}



===== Sbp2BusResetNotificationEx @ 140006c50 =====

void Sbp2BusResetNotificationEx(longlong *param_1)

{
  undefined8 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  longlong lVar4;
  undefined2 uVar5;
  
  puVar1 = (undefined8 *)*param_1;
  if (*(int *)(puVar1 + 2) != 0x4f444673) {
    if ((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return;
    }
    if (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2) {
      return;
    }
    uVar5 = 0xc;
LAB_140006df2:
    WPP_SF_q(WPP_GLOBAL_Control[3],uVar5,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,puVar1);
    return;
  }
  iVar2 = IoAcquireRemoveLockEx(puVar1 + 3,0,"",1,0x20);
  if (iVar2 < 0) {
    if ((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return;
    }
    if (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2) {
      return;
    }
    uVar5 = 0xf;
    goto LAB_140006df2;
  }
  puVar3 = (undefined4 *)ExAllocatePool2(0x40,0x10,0x6b776253);
  if (puVar3 == (undefined4 *)0x0) {
    if ((((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2)) goto LAB_140006db5;
    uVar5 = 0xd;
  }
  else {
    lVar4 = IoAllocateWorkItem(*puVar1);
    *(longlong *)(puVar3 + 2) = lVar4;
    if (lVar4 != 0) {
      *puVar3 = (int)param_1[1];
      IoQueueWorkItem(lVar4,Sbp2BusResetNotificationWorker,0,puVar3);
      return;
    }
    ExFreePoolWithTag(puVar3,0x6b776253);
    if ((((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2)) goto LAB_140006db5;
    uVar5 = 0xe;
  }
  WPP_SF_q(WPP_GLOBAL_Control[3],uVar5,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,puVar1);
LAB_140006db5:
  IoReleaseRemoveLockEx(puVar1 + 3,0,0x20);
  return;
}



===== Sbp2BusResetNotificationWorker @ 140006e30 =====

void Sbp2BusResetNotificationWorker(longlong param_1,int *param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined1 uVar5;
  int iVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  int iVar9;
  char cVar10;
  byte bVar11;
  short sVar12;
  byte bVar13;
  uint uVar14;
  uint uVar15;
  ulonglong uVar16;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  ExAcquireFastMutex(lVar2 + 0x570);
  lVar1 = lVar2 + 0xa0;
  uVar5 = KeAcquireSpinLockRaiseToDpc(lVar1);
  *(uint *)(lVar2 + 0x14) = *(uint *)(lVar2 + 0x14) | 0x2000;
  uVar16 = 0;
  if (*(int *)(lVar2 + 0x98) != 0) {
    do {
      lVar3 = *(longlong *)(uVar16 * 0x78 + 0xa8 + lVar2);
      if (lVar3 != 0) {
        plVar4 = *(longlong **)(lVar3 + 0x40);
        iVar6 = IoAcquireRemoveLockEx(plVar4 + 3,0,"",1,0x20);
        if (-1 < iVar6) {
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
             (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_qDd(WPP_GLOBAL_Control[3],0x14,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                       plVar4,(char)*(undefined4 *)((longlong)plVar4 + 0x14),(char)*param_2);
          }
          Sbp2AddLog((longlong)plVar4,1,0x5273743e,lVar2,uVar16);
          KeAcquireSpinLockAtDpcLevel(plVar4 + 0xb5);
          KeReleaseSpinLockFromDpcLevel(lVar1);
          if (2 < *(ushort *)(lVar2 + 0x5b0)) {
            *(int *)(plVar4 + 0x34) = *param_2;
          }
          if ((*(uint *)((longlong)plVar4 + 0x14) & 0x8000) != 0) {
            KeCancelTimer(plVar4 + 0xbe);
            *(uint *)((longlong)plVar4 + 0x14) = *(uint *)((longlong)plVar4 + 0x14) & 0xffff7bff;
          }
          bVar13 = 3;
          iVar9 = 1;
          Sbp2AddLog((longlong)plVar4,1,0x52737431,0,0);
          uVar15 = *(uint *)((longlong)plVar4 + 0x14);
          bVar11 = (byte)uVar15;
          if (((byte)iVar9 + 1 & bVar11) == 0) {
            if ((((uVar15 & 0x50000) == 0) && (*(int *)((longlong)plVar4 + 0xc4) == iVar9)) &&
               (((byte)iVar9 & bVar11) != 0)) goto LAB_14000701f;
            if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
               (bVar13 <= *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              WPP_SF_qd(WPP_GLOBAL_Control[3],0x15,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                        plVar4,bVar11);
            }
          }
          else if ((uVar15 >> 0x12 & 1) == 0) {
LAB_14000701f:
            *(uint *)((longlong)plVar4 + 0x14) = uVar15 & 0xfdffffff;
            if (((((uVar15 & 0x800) != 0) ||
                 (((*(uint *)(plVar4[0xb] + 0x38) & 0x20) != 0 && ((uVar15 & 0x102008) == 0x102008))
                 )) && (*(uint *)((longlong)plVar4 + 0x14) = uVar15 & 0xfdfffff7 | 0x800,
                       (undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
               (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x800) != 0 &&
                (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
              WPP_SF_qd(WPP_GLOBAL_Control[3],0x16,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                        plVar4,bVar11 & 0xf7);
            }
            uVar14 = 0x800;
            Sbp2AddLog((longlong)plVar4,1,0x52737432,0,0);
            uVar15 = *(uint *)((longlong)plVar4 + 0x14);
            if ((uVar15 >> 10 & 1) == 0) {
              if ((uVar15 & 0x300) != 0) {
                if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & uVar14) != 0)) &&
                   (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                  WPP_SF_qd(WPP_GLOBAL_Control[3],0x17,
                            &WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,plVar4,(char)uVar15);
                }
                *(uint *)((longlong)plVar4 + 0x14) = *(uint *)((longlong)plVar4 + 0x14) & 0xfffffeff
                ;
                KeCancelTimer(plVar4 + 0xbe);
                *(undefined4 *)((longlong)plVar4 + 0x104) = 0x8000001d;
                KeSetEvent(plVar4 + 0x5d,0,0);
              }
              cVar10 = '\x02';
            }
            else {
              uVar14 = *(uint *)(plVar4[0xb] + 0x38);
              *(uint *)((longlong)plVar4 + 0x14) = uVar15 & 0xfffffbff;
              cVar10 = ((uVar14 & 0x10) != 0) + '\x01';
            }
            *(uint *)((longlong)plVar4 + 0x14) = *(uint *)((longlong)plVar4 + 0x14) | 0x2000;
            if (cVar10 == '\x01') {
              Sbp2AddLog((longlong)plVar4,1,0x52737433,0,0);
              *(uint *)((longlong)plVar4 + 0x14) = *(uint *)((longlong)plVar4 + 0x14) | 0x100;
              KeReleaseSpinLock(plVar4 + 0xb5,uVar5);
              uVar7 = Sbp2ManagementTransaction(plVar4,3,*param_2);
              iVar6 = (int)uVar7;
              uVar5 = KeAcquireSpinLockRaiseToDpc(plVar4 + 0xb5);
              if (-1 < iVar6) goto LAB_140007385;
              uVar8 = IsDeviceGone(plVar4,iVar6);
              if ((char)uVar8 == '\0') {
                cVar10 = '\x02';
              }
              if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
                 (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                WPP_SF_qDDd(WPP_GLOBAL_Control[3],0x18,(ulonglong)*(ushort *)(plVar4[0xb] + 8),
                            plVar4,(char)uVar7,(char)*(undefined4 *)((longlong)plVar4 + 0x14),
                            (char)*(ushort *)(plVar4[0xb] + 8));
              }
              Sbp2AddLog((longlong)plVar4,1,0x52737434,(longlong)iVar6,0);
            }
            if (cVar10 == '\x02') {
              uVar7 = Sbp2QueueManagementWorkItem(plVar4,2,*param_2);
              iVar6 = (int)uVar7;
              if ((iVar6 < 0) && (uVar8 = IsDeviceGone(plVar4,iVar6), (char)uVar8 == '\0')) {
                if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x800) != 0 &&
                    (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
                  WPP_SF_qDd(WPP_GLOBAL_Control[3],0x19,
                             &WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,plVar4,(char)uVar7,
                             (char)*(undefined4 *)((longlong)plVar4 + 0x14));
                }
LAB_1400072d4:
                sVar12 = 3;
                Sbp2AddLog((longlong)plVar4,1,0x52737435,3,0);
                if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
                   (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                  WPP_SF_qDDd(WPP_GLOBAL_Control[3],sVar12 + 0x17,
                              (ulonglong)*(ushort *)(plVar4[0xb] + 8),plVar4,(char)iVar6,
                              (char)*(undefined4 *)((longlong)plVar4 + 0x14),
                              (char)*(ushort *)(plVar4[0xb] + 8));
                }
                Sbp2SetDeferLoginTimer((longlong)plVar4);
              }
            }
            else if (cVar10 == '\x03') goto LAB_1400072d4;
          }
          else {
            *(undefined4 *)((longlong)plVar4 + 0x104) = 0xc000000e;
            KeSetEvent(plVar4 + 0x60,0,0);
          }
LAB_140007385:
          KeAcquireSpinLockAtDpcLevel(lVar1);
          KeReleaseSpinLockFromDpcLevel(plVar4 + 0xb5);
          IoReleaseRemoveLockEx(plVar4 + 3,0,0x20);
        }
      }
      uVar15 = (int)uVar16 + 1;
      uVar16 = (ulonglong)uVar15;
    } while (uVar15 < *(uint *)(lVar2 + 0x98));
  }
  *(uint *)(lVar2 + 0x14) = *(uint *)(lVar2 + 0x14) & 0xffffdfff;
  KeReleaseSpinLock(lVar2 + 0xa0,uVar5);
  ExReleaseFastMutex(lVar2 + 0x570);
  IoFreeWorkItem(*(undefined8 *)(param_2 + 2));
  ExFreePoolWithTag(param_2,0x6b776253);
  IoReleaseRemoveLockEx(lVar2 + 0x18,0,0x20);
  return;
}



===== Sbp2DeferPendingRequest @ 14000745c =====

void Sbp2DeferPendingRequest(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  undefined8 uVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  if ((*(uint *)(param_1 + 0x14) & 0x40) != 0) {
    AcquireOrbListLock(param_1,&local_28,'\0');
    plVar1 = (longlong *)(param_1 + 0x70);
    plVar3 = (longlong *)*plVar1;
    if (plVar3 == plVar1) {
      if (param_2 != 0) {
        LOCK();
        lVar4 = *(longlong *)(param_1 + 0xd8);
        *(longlong *)(param_1 + 0xd8) = param_2;
        UNLOCK();
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_qqq(WPP_GLOBAL_Control[3],0x1e,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                     param_1,(char)param_2,(char)lVar4);
        }
      }
    }
    else if ((*(uint *)(plVar3[6] + 0xc) & 0x80000) == 0) {
      LOCK();
      uVar2 = *(undefined8 *)(param_1 + 0xd8);
      *(undefined8 *)(param_1 + 0xd8) = 0;
      UNLOCK();
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_qq(WPP_GLOBAL_Control[3],0x1d,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                  param_1,(char)uVar2);
      }
    }
    else {
      LOCK();
      uVar2 = *(undefined8 *)(param_1 + 0xd8);
      *(undefined8 *)(param_1 + 0xd8) = *(undefined8 *)(plVar3[6] + 0x30);
      UNLOCK();
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) &&
         (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        lVar4 = plVar3[6];
        WPP_SF_qqqD(WPP_GLOBAL_Control[3],lVar4,uVar2,param_1,(char)*(undefined8 *)(lVar4 + 0x30),
                    (char)uVar2,*(undefined1 *)(lVar4 + 0x48));
      }
      *(uint *)(plVar3 + 7) = *(uint *)(plVar3 + 7) & 0xfffffffe;
      plVar3[6] = 0;
      KeCancelTimer(plVar3 + 0x1e);
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_qq(WPP_GLOBAL_Control[3],0x1c,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                  param_1,(char)plVar3);
      }
      FreeAsyncRequestContext(param_1,(longlong)plVar3);
      *(longlong **)(param_1 + 0x78) = plVar1;
      *plVar1 = (longlong)plVar1;
    }
    ReleaseOrbListLock(param_1,&local_28,'\0');
  }
  return;
}



===== Sbp2DoLogin @ 14000764c =====

ulonglong Sbp2DoLogin(longlong *param_1,int param_2)

{
  longlong *plVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined1 uVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  wchar_t *pwVar8;
  longlong lVar9;
  byte bVar10;
  undefined2 uVar11;
  int iVar12;
  undefined8 uVar13;
  ulonglong uVar14;
  undefined *puVar15;
  longlong *plVar16;
  uint uVar17;
  longlong local_res18 [2];
  
  KeGetCurrentIrql();
  plVar1 = param_1 + 0xb5;
  uVar4 = KeAcquireSpinLockRaiseToDpc(plVar1);
  plVar16 = (longlong *)0x0;
  bVar10 = 1;
  Sbp2AddLog((longlong)param_1,1,0x4c4f473e,0,0);
  uVar5 = *(uint *)((longlong)param_1 + 0x14);
  if ((uVar5 & 0x600) != 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) &&
       (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qd(WPP_GLOBAL_Control[3],0x44,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1,
                (char)uVar5);
    }
    Sbp2AddLog((longlong)param_1,1,0x4c4f4731,0,0);
LAB_140007db3:
    KeReleaseSpinLock(param_1 + 0xb5,uVar4);
    return 0;
  }
  if ((uVar5 >> 0xc & 1) != 0) {
    *(uint *)((longlong)param_1 + 0x14) = uVar5 & 0xffffefff;
    Sbp2AddLog((longlong)param_1,bVar10,0x4c4f4732,plVar16,0);
  }
  *(uint *)((longlong)param_1 + 0x14) = *(uint *)((longlong)param_1 + 0x14) | 0x200;
  KeReleaseSpinLock(plVar1);
  puVar15 = (undefined *)0x0;
  uVar13 = 0;
  uVar7 = Sbp2CleanDeviceExtension(*param_1,0,0);
  if ((((char)uVar7 == '\0') && ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0 &&
      (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
    uVar13 = 0x45;
    puVar15 = &WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids;
    plVar16 = param_1;
    WPP_SF_q(WPP_GLOBAL_Control[3],0x45,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1);
  }
  uVar5 = Sbp2InitializeDeviceExtension(param_1,uVar13,puVar15,plVar16);
  uVar14 = (ulonglong)uVar5;
  if ((int)uVar5 < 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qd(WPP_GLOBAL_Control[3],0x46,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1,
                (char)uVar5);
    }
    *(uint *)((longlong)param_1 + 0x104) = uVar5;
    goto LAB_1400077de;
  }
  puVar2 = (undefined8 *)param_1[0x55];
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    lVar9 = param_1[0xb];
    if (((lVar9 == 0) || (pwVar8 = *(wchar_t **)(lVar9 + 0x60), pwVar8 == (wchar_t *)0x0)) &&
       (pwVar8 = L"Unknown", lVar9 == 0)) {
      uVar14 = 0;
    }
    else {
      uVar14 = (ulonglong)*(ushort *)(lVar9 + 8);
    }
    WPP_SF_qdSDd(WPP_GLOBAL_Control[3],WPP_GLOBAL_Control,uVar14,param_1,(char)uVar14,pwVar8,
                 (char)*(undefined4 *)((longlong)param_1 + 0x14),(char)param_2);
  }
  puVar3 = (undefined8 *)param_1[99];
  lVar9 = 0;
  *puVar3 = 0;
  puVar3[1] = 0;
  puVar2[1] = param_1[0x65];
  do {
    uVar5 = *(uint *)((longlong)puVar2 + lVar9 * 4);
    *(uint *)((longlong)puVar2 + lVar9 * 4) =
         uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
    lVar9 = lVar9 + 1;
  } while (lVar9 < 4);
  *(undefined4 *)(puVar2 + 2) = 0;
  uVar11 = 0x8000;
  *(undefined2 *)((longlong)puVar2 + 0x12) = 0x8000;
  *(undefined4 *)((longlong)puVar2 + 0x14) = 0x10;
  if (((*(ushort *)(param_1[0xb] + 10) & 0x1f) == 0) ||
     ((*(ushort *)(param_1[0xb] + 10) & 0x1f) == 0xe)) {
    uVar11 = 0x9000;
    *(undefined2 *)((longlong)puVar2 + 0x12) = 0x9000;
  }
  *(undefined2 *)(puVar2 + 2) = *(undefined2 *)(param_1[0xb] + 8);
  *(undefined2 *)((longlong)puVar2 + 0x12) = uVar11;
  uVar5 = *(uint *)(puVar2 + 2);
  *(uint *)(puVar2 + 2) =
       uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
  uVar5 = *(uint *)((longlong)puVar2 + 0x14);
  *(uint *)((longlong)puVar2 + 0x14) =
       uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
  *puVar2 = 0;
  lVar9 = param_1[0x91];
  puVar2[3] = lVar9;
  uVar5 = (uint)lVar9;
  *(uint *)(puVar2 + 3) =
       uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
  uVar5 = *(uint *)((longlong)puVar2 + 0x1c);
  *(uint *)((longlong)puVar2 + 0x1c) =
       uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
  KeResetEvent(param_1 + 0x5d);
  iVar6 = Sbp2AccessRegisterEx((longlong)param_1,(uint *)(param_1 + 0x57),0x100,param_2);
  uVar14 = (ulonglong)iVar6;
  Sbp2AddLog((longlong)param_1,1,0x4c4f4734,uVar14,0);
  if (iVar6 < 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) &&
       (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qd(WPP_GLOBAL_Control[3],0x4c,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1,
                (char)iVar6);
    }
    Sbp2AddLog((longlong)param_1,1,0x4c4f4736,uVar14,0);
    uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xb5);
    uVar5 = *(uint *)((longlong)param_1 + 0x14) & 0xfffffdff;
    *(uint *)((longlong)param_1 + 0x14) = uVar5;
    if ((iVar6 == -0x3fedff70) || (iVar6 == -0x3ffffdc0)) {
      *(uint *)((longlong)param_1 + 0x14) = uVar5 | 0x8000;
      Sbp2SetManagementTimer((longlong)param_1,3);
      goto LAB_140007db3;
    }
    iVar12 = 1;
    Sbp2AddLog((longlong)param_1,1,0x524c6f67,uVar14,0);
    if ((iVar6 != -0x3ffffff2) && ((*(uint *)((longlong)param_1 + 0x14) >> 0x12 & 1) == 0)) {
      LOCK();
      plVar1 = param_1 + 0xc9;
      lVar9 = *plVar1;
      *(int *)plVar1 = (int)*plVar1 + -1;
      UNLOCK();
      if (iVar12 < (int)lVar9) {
        KeReleaseSpinLock(param_1 + 0xb5,uVar4);
        Sbp2Issue1394BusReset(param_1);
        uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xb5);
        goto LAB_140007d16;
      }
    }
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) &&
       (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qd(WPP_GLOBAL_Control[3],0x4d,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1,
                (char)*(undefined4 *)((longlong)param_1 + 0x14));
    }
    *(uint *)((longlong)param_1 + 0x14) = *(uint *)((longlong)param_1 + 0x14) | 0x100008;
    *(undefined4 *)(param_1[99] + 8) = 0;
    KeReleaseSpinLock(param_1 + 0xb5,uVar4);
    uVar5 = 0xadc;
LAB_140007bad:
    Sbp2LoginErrorHandler(param_1,(int)uVar14,uVar5);
  }
  else {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qd(WPP_GLOBAL_Control[3],0x48,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1,
                (char)iVar6);
    }
    local_res18[0] = (longlong)*(int *)(param_1[0xb] + 0x40) * -10000;
    iVar6 = KeWaitForSingleObject(param_1 + 0x5d,0,0,0,local_res18);
    Sbp2AddLog((longlong)param_1,1,0x4c4f4735,(longlong)iVar6,0);
    uVar4 = KeAcquireSpinLockRaiseToDpc(plVar1);
    uVar5 = *(uint *)((longlong)param_1 + 0x14) & 0xffffddff;
    *(uint *)((longlong)param_1 + 0x14) = uVar5;
    if (iVar6 == 0x102) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) &&
         (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_qd(WPP_GLOBAL_Control[3],0x49,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                  param_1,(char)*(undefined4 *)(param_1[0xb] + 0x40));
        uVar5 = *(uint *)((longlong)param_1 + 0x14);
      }
      uVar17 = 0xc00000b5;
      *(undefined4 *)((longlong)param_1 + 0x104) = 0xc00000b5;
    }
    else {
      uVar17 = *(uint *)((longlong)param_1 + 0x104);
    }
    if ((uVar5 >> 0x12 & 1) == 0) {
      uVar14 = (ulonglong)uVar17;
      if ((int)uVar17 < 0) goto LAB_140007a65;
      if (uVar17 == 0) {
        Sbp2AddLog((longlong)param_1,1,0x4c4f4739,0,0);
        uVar5 = *(uint *)((longlong)param_1 + 0x14);
        *(uint *)((longlong)param_1 + 0x14) = uVar5 & 0xffffdef7 | 0x400;
        if ((uVar5 & 2) != 0) {
          KeSetEvent(param_1 + 0x60,0,0);
        }
        Sbp2RestartPendingPowerIrp(param_1);
      }
    }
    else {
      uVar14 = 0xc000000e;
LAB_140007a65:
      iVar6 = (int)uVar14;
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) &&
         (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_qDd(WPP_GLOBAL_Control[3],0x4a,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                   param_1,(char)uVar14,(char)param_1[0xc9]);
      }
      lVar9 = (longlong)iVar6;
      iVar12 = 1;
      Sbp2AddLog((longlong)param_1,1,0x4c4f4737,lVar9,0);
      if ((iVar6 != -0x7fffffe3) &&
         (Sbp2AddLog((longlong)param_1,(byte)iVar12,0x524c6f67,lVar9,0), iVar6 != -0x3fedff70)) {
        if ((iVar6 != -0x3ffffff2) && ((*(uint *)((longlong)param_1 + 0x14) >> 0x12 & 1) == 0)) {
          LOCK();
          plVar1 = param_1 + 0xc9;
          lVar9 = *plVar1;
          *(int *)plVar1 = (int)*plVar1 + -1;
          UNLOCK();
          if (iVar12 < (int)lVar9) {
            KeReleaseSpinLock(param_1 + 0xb5,uVar4);
            iVar6 = Sbp2Issue1394BusReset(param_1);
            if (iVar6 < 0) {
              Sbp2SetDeferLoginTimer((longlong)param_1);
            }
            uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xb5);
            goto LAB_140007d16;
          }
        }
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) &&
           (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_qd(WPP_GLOBAL_Control[3],0x4b,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                    param_1,(char)*(undefined4 *)((longlong)param_1 + 0x14));
        }
        *(uint *)((longlong)param_1 + 0x14) = *(uint *)((longlong)param_1 + 0x14) | 0x100008;
        *(undefined4 *)(param_1[99] + 8) = 0;
        KeReleaseSpinLock(param_1 + 0xb5,uVar4);
        uVar5 = 0xa86;
        goto LAB_140007bad;
      }
    }
LAB_140007d16:
    KeReleaseSpinLock(param_1 + 0xb5,uVar4);
  }
LAB_1400077de:
  return uVar14 & 0xffffffff;
}



===== Sbp2DoReconnect @ 140007de0 =====

ulonglong Sbp2DoReconnect(longlong *param_1,int param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  undefined *puVar8;
  longlong *plVar9;
  
  KeGetCurrentIrql();
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    if (param_1[0xb] == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = (ulonglong)*(ushort *)(param_1[0xb] + 8);
    }
    WPP_SF_qdD(WPP_GLOBAL_Control[3],0x50,uVar7,param_1,(char)uVar7,
               (char)*(undefined4 *)((longlong)param_1 + 0x14));
  }
  plVar9 = (longlong *)0x0;
  Sbp2AddLog((longlong)param_1,1,0x5245433e,0,0);
  puVar8 = (undefined *)0x0;
  uVar6 = 0;
  uVar5 = Sbp2CleanDeviceExtension(*param_1,0,0);
  if ((((char)uVar5 == '\0') && ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0 &&
      (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
    puVar8 = &WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids;
    uVar6 = 0x51;
    plVar9 = param_1;
    WPP_SF_q(WPP_GLOBAL_Control[3],0x51,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1);
  }
  uVar3 = Sbp2InitializeDeviceExtension(param_1,uVar6,puVar8,plVar9);
  uVar7 = (ulonglong)uVar3;
  if ((int)uVar3 < 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qd(WPP_GLOBAL_Control[3],0x52,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1,
                (char)uVar3);
    }
  }
  else {
    lVar1 = param_1[0x55];
    *(undefined4 *)(lVar1 + 0x10) = 0;
    *(undefined2 *)(lVar1 + 0x12) = 0x8000;
    *(undefined2 *)(lVar1 + 0x10) = *(undefined2 *)param_1[99];
    *(undefined2 *)(lVar1 + 0x12) = 0x8003;
    uVar3 = *(uint *)(lVar1 + 0x10);
    *(uint *)(lVar1 + 0x10) =
         uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    lVar2 = param_1[0x7f];
    *(longlong *)(lVar1 + 0x18) = lVar2;
    uVar3 = (uint)lVar2;
    *(uint *)(lVar1 + 0x18) =
         uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    uVar3 = *(uint *)(lVar1 + 0x1c);
    *(uint *)(lVar1 + 0x1c) =
         uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    Sbp2SetManagementTimer((longlong)param_1,0);
    KeResetEvent(param_1 + 0x5d);
    iVar4 = Sbp2AccessRegisterEx((longlong)param_1,(uint *)(param_1 + 0x57),0x100,param_2);
    uVar7 = (ulonglong)iVar4;
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qd(WPP_GLOBAL_Control[3],0x53,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1,
                (char)iVar4);
    }
    if (iVar4 < 0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_qd(WPP_GLOBAL_Control[3],0x54,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                  param_1,(char)iVar4);
      }
      Sbp2AddLog((longlong)param_1,1,0x52656331,uVar7,0);
      Sbp2ReconnectCompletion(param_1,iVar4);
    }
    Sbp2AddLog((longlong)param_1,1,0x5245433c,uVar7,0);
  }
  return uVar7 & 0xffffffff;
}



===== Sbp2Get1394ConfigInfo @ 14000805c =====

int Sbp2Get1394ConfigInfo(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  uint *puVar5;
  undefined1 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined8 uVar10;
  int iVar11;
  ulonglong uVar12;
  uint uVar13;
  uint *puVar14;
  uint *puVar15;
  longlong lVar16;
  uint uVar17;
  longlong *plVar18;
  uint *puVar19;
  uint local_res20;
  uint *local_e8;
  uint local_d8;
  uint local_d4;
  int local_d0;
  int local_cc;
  uint local_c8;
  undefined8 local_c0;
  int local_b8;
  uint local_b0;
  uint *local_a8;
  uint *local_a0;
  longlong *local_98;
  uint *local_90;
  longlong local_88;
  uint *local_80;
  int local_78;
  int local_74;
  uint local_70;
  undefined8 local_68;
  int local_60;
  undefined8 local_58;
  int local_50;
  
  local_d8 = *(uint *)(param_1 + 0x98);
  local_d0 = 0;
  local_d4 = 0;
  bVar4 = false;
  puVar14 = (uint *)0x0;
  bVar3 = false;
  local_80 = (uint *)0x0;
  local_a0 = (uint *)0x0;
  local_88 = 0;
  AllocateIrpAndIrb(param_1,&local_88);
  lVar16 = local_88;
  if (local_88 == 0) {
    iVar7 = -0x3fffff66;
  }
  else {
    iVar7 = Sbp2GetConfigPacket(param_1,local_88,&local_d0);
    if (iVar7 < 0) {
      local_e8 = (uint *)0x0;
      if ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_Dq(WPP_GLOBAL_Control[3],(ulonglong)*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c),
                    0,iVar7,(char)param_1);
        }
        local_e8 = puVar14;
      }
    }
    else {
      local_98 = (longlong *)(lVar16 + 0x10);
      lVar16 = *local_98;
      local_68 = *(undefined8 *)(lVar16 + 0xa0);
      local_a0 = *(uint **)(lVar16 + 200);
      iVar11 = *(int *)(lVar16 + 0xa8);
      puVar14 = *(uint **)(lVar16 + 0x98);
      local_e8 = *(uint **)(lVar16 + 0xb0);
      local_80 = *(uint **)(lVar16 + 0xd8);
      local_70 = *(uint *)(lVar16 + 0x90) >> 2;
      local_c8 = *(uint *)(lVar16 + 0xac) >> 2;
      local_58 = *(undefined8 *)(lVar16 + 0xb8);
      local_78 = *(int *)(lVar16 + 0xc0);
      local_cc = iVar11;
      local_60 = iVar11;
      local_50 = local_78;
      if (param_2 == 0) {
        uVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xa0);
        uVar12 = 0;
        if (*(int *)(param_1 + 0x98) != 0) {
          do {
            LOCK();
            plVar18 = (longlong *)(uVar12 * 0x78 + 0x108 + param_1);
            lVar16 = *plVar18;
            *plVar18 = 0;
            UNLOCK();
            if (lVar16 != 0) {
              ExFreePool();
              *(undefined2 *)(uVar12 * 0x78 + 0x100 + param_1) = 0;
            }
            uVar13 = (int)uVar12 + 1;
            uVar12 = (ulonglong)uVar13;
          } while (uVar13 < *(uint *)(param_1 + 0x98));
          local_cc = local_60;
          local_78 = local_50;
        }
        iVar11 = local_cc;
        KeReleaseSpinLock(param_1 + 0xa0,uVar6);
        local_d8 = 0;
      }
      uVar12 = (ulonglong)local_70;
      local_res20 = 0;
      uVar13 = 1;
      *(undefined4 *)(param_1 + 0xec) = 0;
      local_c0 = local_68;
      local_b8 = iVar11;
      if (param_2 != 0) {
        for (; uVar13 < local_70; uVar13 = uVar13 + 1) {
          if ((((*(uint *)(param_2 + 8) & 2) != 0) && ((char)puVar14[uVar13] == -0x7f)) &&
             ((puVar14[(ulonglong)uVar13 - 1] & 0xff) == *(uint *)(param_2 + 0xc))) {
            if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              uVar12 = 0x20;
              WPP_SF_qq(WPP_GLOBAL_Control[3],0x20,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                        param_1,(char)param_2);
            }
            uVar8 = puVar14[uVar13];
            local_b8 = local_cc +
                       ((uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8) + uVar13)
                       * 4;
            if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              uVar12 = 0x21;
              WPP_SF_qqDD(WPP_GLOBAL_Control[3],0x21,
                          &WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1,(char)puVar14,
                          (char)local_b8,(char)uVar8);
            }
            Sbp2ParseTextLeaf(param_1,uVar12,(longlong)&local_c0,(undefined8 *)(param_2 + 0x18));
            if (*(uint **)(param_2 + 0x18) == (uint *)0x0) {
              if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                WPP_SF_q(WPP_GLOBAL_Control[3],0x22,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids
                         ,param_1);
              }
              iVar7 = -0x3fffffff;
            }
            else {
              uVar13 = **(uint **)(param_2 + 0x18);
              iVar7 = 0;
              *(uint *)(param_2 + 0x10) = (((uVar13 & 0xff00) << 8 | uVar13 << 0x18) >> 0x10) << 2;
            }
            goto LAB_140008126;
          }
        }
      }
      local_b0 = 1;
      if (param_2 == 0) {
        local_74 = local_d0;
        for (; local_b0 < (uint)uVar12; local_b0 = local_b0 + 1) {
          puVar15 = (uint *)((ulonglong)local_d8 * 0x78);
          uVar13 = puVar14[local_b0];
          uVar8 = uVar13 & 0xff;
          local_90 = puVar15;
          if (uVar8 == 0x14) {
            *(uint *)((longlong)puVar15 + param_1 + 0xb0) =
                 uVar13 >> 0x18 | (uVar13 & 0xff0000) >> 8 | (uVar13 & 0xff00) << 8;
            if ((local_d8 == 0) && (local_80 != (uint *)0x0)) {
              if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0 &&
                  (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
                WPP_SF_q(WPP_GLOBAL_Control[3],0x24,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids
                         ,param_1);
              }
              iVar7 = Sbp2_ProcessTextualDescriptor(local_80,(short *)(param_1 + 0x100));
            }
            if (local_a0 == (uint *)0x0) {
              *(undefined2 *)((longlong)puVar15 + param_1 + 0xf0) = 0;
              *(undefined8 *)((longlong)puVar15 + param_1 + 0xf8) = 0;
            }
            else {
              if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                 (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                WPP_SF_q(WPP_GLOBAL_Control[3],0x25,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids
                         ,param_1);
              }
              iVar7 = Sbp2_ProcessTextualDescriptor
                                (local_a0,(short *)(param_1 + 0xf0 + (longlong)puVar15));
            }
            local_d8 = local_d8 + 1;
            *(longlong *)((longlong)puVar15 + param_1 + 0xc0) = param_1 + 0x558;
            *(undefined4 *)((longlong)puVar15 + param_1 + 0xcc) = *(undefined4 *)(param_1 + 0xcc);
            *(undefined4 *)((longlong)puVar15 + param_1 + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
            *(undefined4 *)((longlong)puVar15 + param_1 + 0xb8) = *(undefined4 *)(param_1 + 0xb8);
            *(undefined4 *)((longlong)puVar15 + param_1 + 0xbc) = *(undefined4 *)(param_1 + 0xbc);
            *(undefined4 *)((longlong)puVar15 + param_1 + 0xe4) = *(undefined4 *)(param_1 + 0xe4);
            *(undefined4 *)((longlong)puVar15 + param_1 + 0xdc) = *(undefined4 *)(param_1 + 0xdc);
LAB_140008ef2:
            local_res20 = local_res20 + 1;
          }
          else {
            if (uVar8 == 0x38) {
              *(uint *)(param_1 + 0xb8) =
                   uVar13 >> 0x18 | (uVar13 & 0xff0000) >> 8 | (uVar13 & 0xff00) << 8;
              goto LAB_140008ef2;
            }
            if (uVar8 == 0x39) {
              *(uint *)(param_1 + 0xb4) =
                   uVar13 >> 0x18 | (uVar13 & 0xff0000) >> 8 | (uVar13 & 0xff00) << 8;
              goto LAB_140008ef2;
            }
            if (uVar8 == 0x3a) {
              uVar8 = uVar13 >> 0x18 | (uVar13 & 0xff0000) >> 8;
              *(uint *)(param_1 + 0xbc) = uVar8 | (uVar13 & 0xff00) << 8;
              if (((ushort)uVar8 & 0xff) < 8) {
                uVar8 = 0xc;
              }
              else {
                uVar8 = (uVar13 >> 0x18) * 4 - 0x14;
                if (0xf < uVar8) {
                  uVar8 = 0x10;
                }
              }
              *(uint *)(param_1 + 0xe4) = uVar8;
              *(uint *)(param_1 + 0xe8) = ((uVar13 & 0xff0000) >> 0x10) * 500;
              goto LAB_140008ef2;
            }
            if (uVar8 == 0x3c) {
              *(uint *)(param_1 + 0xdc) =
                   uVar13 >> 0x18 | (uVar13 & 0xff0000) >> 8 | (uVar13 & 0xff00) << 8;
              if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                WPP_SF_qd(WPP_GLOBAL_Control[3],0x23,
                          &WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1,
                          (char)(uVar13 >> 0x18));
              }
            }
            else if (uVar8 == 0x3d) {
              if ((uVar13 >> 0x18 != 0 || (uVar13 & 0xff0000) != 0) || (uVar13 & 0xff00) != 0) {
                *(undefined4 *)(param_1 + 0xec) = 1;
              }
            }
            else if (uVar8 == 0x54) {
              bVar4 = true;
              *(uint *)(param_1 + 0xcc) =
                   (uVar13 >> 0x18 | (uVar13 & 0xff0000) >> 8 | (uVar13 & 0xff00) << 8) << 2 |
                   0xf0000000;
            }
            else if (uVar8 == 0x81) {
              if (((char)puVar14[(ulonglong)local_b0 - 1] == '\x17') && (local_d4 <= local_d8)) {
                lVar16 = (ulonglong)local_d4 * 0x78;
                if (*(longlong *)(lVar16 + 0x108 + param_1) == 0) {
                  local_90 = (uint *)0x0;
                  local_b8 = local_cc +
                             ((uVar13 >> 0x18 | (uVar13 & 0xff0000) >> 8 | (uVar13 & 0xff00) << 8) +
                             local_b0) * 4;
                  local_c0 = local_68;
                  Sbp2ParseTextLeaf(param_1,0,(longlong)&local_c0,&local_90);
                  puVar15 = local_90;
                  if (local_90 != (uint *)0x0) {
                    iVar7 = Sbp2_ProcessTextualDescriptor
                                      (local_90,(short *)(param_1 + 0x100 + lVar16));
                    ExFreePool(puVar15);
                    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                      WPP_SF_S(WPP_GLOBAL_Control[3],0x26,
                               &WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                               *(wchar_t **)(lVar16 + 0x108 + param_1));
                    }
                  }
                }
                local_d4 = local_d4 + 1;
              }
            }
            else if (uVar8 == 0xd4) {
              if (bVar3) {
                puVar15 = (uint *)0x0;
                local_b8 = local_cc;
                local_a8 = (uint *)0x0;
                uVar8 = 3;
                local_d0 = local_cc +
                           ((uVar13 >> 0x18 | (uVar13 & 0xff0000) >> 8 | (uVar13 & 0xff00) << 8) +
                           local_b0) * 4;
                local_c0 = local_68;
                uVar10 = IoAllocateMdl(local_e8,local_c8,0,0,0);
                *(undefined8 *)(*local_98 + 0xa0) = uVar10;
                if (*(longlong *)(*local_98 + 0xa0) == 0) {
                  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                     (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                    WPP_SF_q(WPP_GLOBAL_Control[3],0x2a,
                             &WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1);
                  }
                  goto LAB_140008126;
                }
                MmBuildMdlForNonPagedPool();
                lVar16 = local_88;
                *(undefined4 *)*local_98 = 0;
                *(undefined4 *)(*local_98 + 4) = 0;
                *(undefined2 *)(*local_98 + 0x8c) = 0xffff;
                *(int *)(*local_98 + 0x90) = local_d0;
                *(undefined4 *)(*local_98 + 0x94) = 4;
                *(undefined4 *)(*local_98 + 0x98) = 0;
                *(undefined4 *)(*local_98 + 0x9c) = 0;
                *(undefined1 *)(*local_98 + 0xad) = 0;
                do {
                  *(int *)(*local_98 + 0xa8) = local_74;
                  iVar7 = Sbp2SendRequest(param_1,lVar16,(undefined *)0x2);
                  if ((-1 < iVar7) || (uVar8 < 2)) break;
                  if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
                      (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
                    WPP_SF_qd(WPP_GLOBAL_Control[3],0x2b,
                              &WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1,(char)iVar7);
                  }
                  if (puVar15 == (uint *)0x0) {
                    AllocateIrpAndIrb(param_1,(longlong *)&local_a8);
                    puVar15 = local_a8;
                    if (local_a8 != (uint *)0x0) goto LAB_14000891c;
                  }
                  else {
LAB_14000891c:
                    **(undefined4 **)(puVar15 + 4) = 0x1a;
                    *(undefined4 *)(*(longlong *)(puVar15 + 4) + 4) = 0;
                    iVar7 = Sbp2SendRequest(param_1,(longlong)puVar15,(undefined *)0x2);
                    if ((((iVar7 < 0) && ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control))
                        && ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                      WPP_SF_qd(WPP_GLOBAL_Control[3],0x2c,
                                &WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1,(char)iVar7
                               );
                    }
                    local_74 = *(int *)(*(longlong *)(puVar15 + 4) + 0x88);
                  }
                  uVar8 = uVar8 - 1;
                } while (uVar8 != 0);
                puVar19 = local_90;
                if (puVar15 != (uint *)0x0) {
                  DeAllocateIrpAndIrb(param_1,(longlong)puVar15);
                }
                plVar18 = local_98;
                if (iVar7 < 0) {
                  lVar16 = *(longlong *)(local_88 + 0x10);
LAB_1400090cd:
                  IoFreeMdl(*(undefined8 *)(lVar16 + 0xa0));
                  goto LAB_140008126;
                }
                uVar8 = ((*local_e8 & 0xff00) << 8 | *local_e8 << 0x18) >> 0x10;
                uVar13 = uVar8 * 4;
                local_c8 = uVar13;
                IoFreeMdl(*(undefined8 *)(*local_98 + 0xa0));
                *(undefined8 *)(*plVar18 + 0xa0) = 0;
                if (0x100 < uVar13) {
                  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                     (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                    WPP_SF_qd(WPP_GLOBAL_Control[3],0x2d,
                              &WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1,(char)uVar13)
                    ;
                  }
                  goto LAB_140008126;
                }
                ExFreePool(local_e8);
                local_e8 = (uint *)ExAllocatePool2(0x40,uVar13 + 4,0x64556253);
                if (local_e8 == (uint *)0x0) goto LAB_140008126;
                uVar10 = IoAllocateMdl(local_e8,uVar13 + 4,0,0,0);
                plVar18 = local_98;
                *(undefined8 *)(*local_98 + 0xa0) = uVar10;
                if (*(longlong *)(*local_98 + 0xa0) == 0) goto LAB_140008126;
                MmBuildMdlForNonPagedPool();
                uVar12 = 1;
                iVar11 = local_d0 + 4;
                local_a8 = (uint *)CONCAT44(local_a8._4_4_,iVar11);
                do {
                  lVar16 = local_88;
                  *(int *)(*plVar18 + 0x90) = iVar11;
                  plVar1 = (longlong *)(*(longlong *)(*plVar18 + 0xa0) + 0x18);
                  *plVar1 = *plVar1 + 4;
                  plVar18 = (longlong *)(*(longlong *)(*plVar18 + 0xa0) + 0x20);
                  *plVar18 = *plVar18 + 4;
                  iVar7 = Sbp2SendRequest(param_1,local_88,(undefined *)0x2);
                  if (iVar7 < 0) {
                    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                      WPP_SF_qd(WPP_GLOBAL_Control[3],0x2e,
                                &WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1,(char)iVar7
                               );
                    }
                    lVar16 = *(longlong *)(lVar16 + 0x10);
                    goto LAB_1400090cd;
                  }
                  uVar13 = local_e8[uVar12];
                  if ((char)uVar13 == '\x14') {
                    *(undefined2 *)((longlong)puVar19 + param_1 + 0x100) = 0;
                    *(uint *)((longlong)puVar19 + param_1 + 0xb0) =
                         uVar13 >> 0x18 | (uVar13 & 0xff0000) >> 8 | (uVar13 & 0xff00) << 8;
                    *(undefined8 *)((longlong)puVar19 + param_1 + 0x108) = 0;
                    if (local_a0 == (uint *)0x0) {
                      *(undefined2 *)((longlong)puVar19 + param_1 + 0xf0) = 0;
                      *(undefined8 *)((longlong)puVar19 + param_1 + 0xf8) = 0;
                    }
                    else {
                      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                        WPP_SF_q(WPP_GLOBAL_Control[3],0x2f,
                                 &WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1);
                      }
                      iVar7 = Sbp2_ProcessTextualDescriptor
                                        (local_a0,(short *)((longlong)puVar19 + param_1 + 0xf0));
                    }
                    local_d8 = local_d8 + 1;
                    *(longlong *)((longlong)puVar19 + param_1 + 0xc0) = param_1 + 0x558;
                    *(undefined4 *)((longlong)puVar19 + param_1 + 0xcc) =
                         *(undefined4 *)(param_1 + 0xcc);
                    if (*(int *)((longlong)puVar19 + param_1 + 0xb4) == 0) {
                      *(undefined4 *)((longlong)puVar19 + param_1 + 0xb4) =
                           *(undefined4 *)(param_1 + 0xb4);
                    }
                    if (*(int *)((longlong)puVar19 + param_1 + 0xb8) == 0) {
                      *(undefined4 *)((longlong)puVar19 + param_1 + 0xb8) =
                           *(undefined4 *)(param_1 + 0xb8);
                    }
                    if (*(int *)((longlong)puVar19 + param_1 + 0xbc) == 0) {
                      *(undefined4 *)((longlong)puVar19 + param_1 + 0xbc) =
                           *(undefined4 *)(param_1 + 0xbc);
                      *(undefined4 *)((longlong)puVar19 + param_1 + 0xe4) =
                           *(undefined4 *)(param_1 + 0xe4);
                    }
                    if (*(int *)((longlong)puVar19 + param_1 + 0xdc) == 0) {
                      *(undefined4 *)((longlong)puVar19 + param_1 + 0xdc) =
                           *(undefined4 *)(param_1 + 0xdc);
                    }
                    local_res20 = local_res20 + 1;
                    *(undefined4 *)((longlong)puVar19 + param_1 + 0xe8) =
                         *(undefined4 *)(param_1 + 0xe8);
                    *(undefined4 *)((longlong)puVar19 + param_1 + 0xec) =
                         *(undefined4 *)(param_1 + 0xec);
                  }
                  uVar13 = local_e8[uVar12];
                  uVar17 = uVar13 & 0xff;
                  if (uVar17 == 0x38) {
                    *(uint *)((longlong)puVar19 + param_1 + 0xb8) =
                         uVar13 >> 0x18 | (uVar13 & 0xff0000) >> 8 | (uVar13 & 0xff00) << 8;
LAB_140008d11:
                    local_res20 = local_res20 + 1;
                  }
                  else {
                    if (uVar17 == 0x39) {
                      *(uint *)((longlong)puVar19 + param_1 + 0xb4) =
                           uVar13 >> 0x18 | (uVar13 & 0xff0000) >> 8 | (uVar13 & 0xff00) << 8;
                      goto LAB_140008d11;
                    }
                    if ((uVar17 == 0x81) && ((char)local_e8[uVar12 - 1] == '\x17')) {
                      local_90 = (uint *)0x0;
                      local_b8 = local_d0 +
                                 ((uVar13 >> 0x18 | (uVar13 & 0xff0000) >> 8 |
                                  (uVar13 & 0xff00) << 8) + (int)uVar12) * 4;
                      Sbp2ParseTextLeaf(param_1,(ulonglong)local_res20,(longlong)&local_c0,&local_90
                                       );
                      puVar15 = local_90;
                      if (local_90 != (uint *)0x0) {
                        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                          WPP_SF_q(WPP_GLOBAL_Control[3],0x30,
                                   &WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1);
                        }
                        iVar7 = Sbp2_ProcessTextualDescriptor
                                          (puVar15,(short *)((longlong)puVar19 + param_1 + 0x100));
                        ExFreePool(puVar15);
                      }
                      local_d4 = local_d4 + 1;
                    }
                  }
                  plVar18 = local_98;
                  uVar13 = (int)uVar12 + 1;
                  uVar12 = (ulonglong)uVar13;
                  iVar11 = (int)local_a8 + 4;
                  local_a8 = (uint *)CONCAT44(local_a8._4_4_,iVar11);
                } while (uVar13 <= uVar8);
                IoFreeMdl();
                *(undefined8 *)(*plVar18 + 0xa0) = 0;
              }
              else {
                bVar3 = true;
                uVar13 = 0;
                if (local_c8 != 0) {
                  puVar19 = local_e8;
                  uVar8 = local_c8;
                  uVar17 = local_res20;
                  do {
                    uVar2 = *puVar19;
                    if ((char)uVar2 == '\x14') {
                      *(uint *)((longlong)puVar15 + param_1 + 0xb0) =
                           uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8;
                      *(longlong *)((longlong)puVar15 + param_1 + 0xc0) = param_1 + 0x558;
                      if (local_d8 == 0) {
                        if (local_80 != (uint *)0x0) {
                          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                             (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                            WPP_SF_q(WPP_GLOBAL_Control[3],0x27,
                                     &WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1);
                          }
                          iVar7 = Sbp2_ProcessTextualDescriptor
                                            (local_80,(short *)(param_1 + 0x100 + (longlong)puVar15)
                                            );
                        }
                      }
                      else {
                        *(undefined2 *)((longlong)puVar15 + param_1 + 0x100) = 0;
                        *(undefined8 *)((longlong)puVar15 + param_1 + 0x108) = 0;
                      }
                      if (local_a0 == (uint *)0x0) {
                        *(undefined2 *)((longlong)puVar15 + param_1 + 0xf0) = 0;
                        *(undefined8 *)((longlong)puVar15 + param_1 + 0xf8) = 0;
                      }
                      else {
                        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                          WPP_SF_q(WPP_GLOBAL_Control[3],0x28,
                                   &WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1);
                        }
                        iVar7 = Sbp2_ProcessTextualDescriptor
                                          (local_a0,(short *)(param_1 + 0xf0 + (longlong)puVar15));
                      }
                      local_d8 = local_d8 + 1;
                      *(undefined4 *)((longlong)puVar15 + param_1 + 0xcc) =
                           *(undefined4 *)(param_1 + 0xcc);
                      if (*(int *)((longlong)puVar15 + param_1 + 0xb4) == 0) {
                        *(undefined4 *)((longlong)puVar15 + param_1 + 0xb4) =
                             *(undefined4 *)(param_1 + 0xb4);
                      }
                      if (*(int *)((longlong)puVar15 + param_1 + 0xb8) == 0) {
                        *(undefined4 *)((longlong)puVar15 + param_1 + 0xb8) =
                             *(undefined4 *)(param_1 + 0xb8);
                      }
                      if (*(int *)((longlong)puVar15 + param_1 + 0xbc) == 0) {
                        *(undefined4 *)((longlong)puVar15 + param_1 + 0xbc) =
                             *(undefined4 *)(param_1 + 0xbc);
                        *(undefined4 *)((longlong)puVar15 + param_1 + 0xe4) =
                             *(undefined4 *)(param_1 + 0xe4);
                      }
                      if (*(int *)((longlong)puVar15 + param_1 + 0xdc) == 0) {
                        *(undefined4 *)((longlong)puVar15 + param_1 + 0xdc) =
                             *(undefined4 *)(param_1 + 0xdc);
                      }
                      uVar17 = local_res20 + 1;
                      uVar8 = local_c8;
                      local_res20 = uVar17;
                    }
                    uVar2 = *puVar19;
                    uVar9 = uVar2 & 0xff;
                    if (uVar9 == 0x38) {
                      *(uint *)((longlong)puVar15 + param_1 + 0xb8) =
                           uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8;
LAB_140008782:
                      uVar17 = uVar17 + 1;
                      local_res20 = uVar17;
                    }
                    else {
                      if (uVar9 == 0x39) {
                        *(uint *)((longlong)puVar15 + param_1 + 0xb4) =
                             uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8;
                        goto LAB_140008782;
                      }
                      if (uVar9 == 0x81) {
                        if ((char)puVar19[-1] == '\x17') {
                          if (*(longlong *)((longlong)puVar15 + param_1 + 0x108) == 0) {
                            local_a8 = (uint *)0x0;
                            local_c0 = local_58;
                            local_b8 = local_78 +
                                       ((uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 |
                                        (uVar2 & 0xff00) << 8) + uVar13) * 4;
                            Sbp2ParseTextLeaf(param_1,0,(longlong)&local_c0,&local_a8);
                            puVar5 = local_a8;
                            if (local_a8 != (uint *)0x0) {
                              iVar7 = Sbp2_ProcessTextualDescriptor
                                                (local_a8,(short *)(param_1 + 0x100 +
                                                                   (longlong)puVar15));
                              ExFreePool(puVar5);
                              if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                                  ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                                 (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                                WPP_SF_S(WPP_GLOBAL_Control[3],0x29,
                                         &WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                                         *(wchar_t **)((longlong)puVar15 + param_1 + 0x108));
                              }
                            }
                            uVar17 = local_res20;
                          }
                          local_d4 = local_d4 + 1;
                          uVar8 = local_c8;
                        }
                      }
                    }
                    uVar13 = uVar13 + 1;
                    puVar19 = puVar19 + 1;
                  } while (uVar13 < uVar8);
                }
              }
            }
          }
          uVar12 = (ulonglong)local_70;
        }
        if ((!bVar4) || (local_res20 < 2)) {
          if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
              (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
            WPP_SF_q(WPP_GLOBAL_Control[3],0x31,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                     param_1);
          }
          iVar7 = -0x3fffff35;
        }
      }
    }
LAB_140008126:
    DeAllocateIrpAndIrb(param_1,local_88);
    if (puVar14 != (uint *)0x0) {
      ExFreePool(puVar14);
    }
    if (local_e8 != (uint *)0x0) {
      ExFreePool(local_e8);
    }
    if (local_a0 != (uint *)0x0) {
      ExFreePool(local_a0);
    }
    if (local_80 != (uint *)0x0) {
      ExFreePool(local_80);
    }
    if (param_2 == 0) {
      *(uint *)(param_1 + 0x98) = local_d8;
    }
  }
  return iVar7;
}



===== Sbp2GetConfigPacket @ 140009188 =====

int Sbp2GetConfigPacket(longlong param_1,longlong param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  undefined2 uVar7;
  longlong *plVar8;
  longlong *plVar9;
  
  plVar9 = (longlong *)(param_2 + 0x10);
  lVar4 = 0;
  lVar5 = 0;
  lVar6 = 0;
  *(undefined4 *)*plVar9 = 0x18;
  *(undefined4 *)(*plVar9 + 4) = 0;
  *(undefined4 *)(*plVar9 + 0x90) = 0;
  *(undefined4 *)(*plVar9 + 0xac) = 0;
  *(undefined4 *)(*plVar9 + 0xc4) = 0;
  *(undefined4 *)(*plVar9 + 0xd0) = 0;
  iVar2 = Sbp2SendRequest(param_1,param_2,(undefined *)0x2);
  if (iVar2 < 0) {
    if ((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar2;
    }
    if ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return iVar2;
    }
    if (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2) {
      return iVar2;
    }
    WPP_SF_D(WPP_GLOBAL_Control[3],0x32,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,iVar2);
    return iVar2;
  }
  if (*(int *)(*plVar9 + 0x90) == 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_q(WPP_GLOBAL_Control[3],0x34,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1);
    }
    return -0x3fffff35;
  }
  lVar3 = ExAllocatePool2(0x40,*(int *)(*plVar9 + 0x90),0x64556253);
  if (lVar3 == 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_(WPP_GLOBAL_Control[3],0x33,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids);
    }
    return -0x3fffff66;
  }
  if ((*(int *)(*plVar9 + 0xac) == 0) ||
     (lVar4 = ExAllocatePool2(0x40,*(int *)(*plVar9 + 0xac),0x64556253), lVar4 != 0)) {
    plVar8 = (longlong *)(param_2 + 0x10);
    if ((*(int *)(*plVar9 + 0xc4) == 0) ||
       (lVar5 = ExAllocatePool2(0x40,*(int *)(*plVar9 + 0xc4),0x6c556253), lVar5 != 0)) {
      plVar9 = (longlong *)(param_2 + 0x10);
      if ((*(int *)(*plVar8 + 0xd0) == 0) ||
         (lVar6 = ExAllocatePool2(0x40,*(int *)(*plVar8 + 0xd0),0x6c556253), lVar6 != 0)) {
        *(undefined4 *)*plVar8 = 0x1a;
        *(undefined4 *)(*plVar8 + 4) = 0;
        iVar2 = Sbp2SendRequest(param_1,param_2,(undefined *)0x2);
        if (iVar2 < 0) {
          if ((((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2)) goto LAB_1400094f6;
          uVar7 = 0x38;
        }
        else {
          puVar1 = (undefined4 *)*plVar9;
          *puVar1 = 0x18;
          *param_3 = puVar1[0x22];
          *(undefined4 *)(*plVar9 + 4) = 0;
          *(longlong *)(*plVar9 + 0x88) = param_1 + 0x558;
          *(longlong *)(*plVar9 + 0x98) = lVar3;
          *(longlong *)(*plVar9 + 0xb0) = lVar4;
          *(longlong *)(*plVar9 + 200) = lVar5;
          *(longlong *)(*plVar9 + 0xd8) = lVar6;
          iVar2 = Sbp2SendRequest(param_1,param_2,(undefined *)0x2);
          if (-1 < iVar2) {
            return iVar2;
          }
          if ((((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2)) goto LAB_1400094f6;
          uVar7 = 0x39;
        }
        WPP_SF_qd(WPP_GLOBAL_Control[3],uVar7,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                  param_1,(char)iVar2);
        goto LAB_1400094f6;
      }
      if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
          (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
        uVar7 = 0x37;
        goto LAB_140009314;
      }
    }
    else if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
            (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      uVar7 = 0x36;
      goto LAB_140009314;
    }
  }
  else if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
          (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    uVar7 = 0x35;
LAB_140009314:
    WPP_SF_(WPP_GLOBAL_Control[3],uVar7,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids);
  }
  iVar2 = -0x3fffff66;
LAB_1400094f6:
  ExFreePool(lVar3);
  if (lVar4 != 0) {
    ExFreePool(lVar4);
  }
  if (lVar5 != 0) {
    ExFreePool(lVar5);
  }
  if (lVar6 != 0) {
    ExFreePool(lVar6);
  }
  return iVar2;
}



===== Sbp2GetControllerInfo @ 1400095a8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int Sbp2GetControllerInfo(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  ushort uVar4;
  int iVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined1 auStackY_88 [32];
  longlong local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = 0;
  uStack_38 = 0;
  local_40 = 0;
  local_3c = 0;
  AllocateIrpAndIrb(param_1,&local_48);
  lVar3 = local_48;
  if (local_48 == 0) {
    return -0x3fffff66;
  }
  **(undefined4 **)(local_48 + 0x10) = 0x16;
  *(undefined4 *)(*(longlong *)(local_48 + 0x10) + 4) = 0;
  *(undefined4 *)(*(longlong *)(local_48 + 0x10) + 0x8c) = 0;
  *(undefined4 *)(*(longlong *)(local_48 + 0x10) + 0x88) = 1;
  iVar5 = Sbp2SendRequest(param_1,local_48,(undefined *)0x2);
  if (iVar5 < 0) goto LAB_1400099dd;
  iVar5 = *(int *)(*(longlong *)(lVar3 + 0x10) + 0x290);
  if (iVar5 == 1) {
    *(undefined4 *)(param_1 + 0x1a4) = 0;
    *(undefined4 *)(param_1 + 0x1a8) = 0x700070;
  }
  else if (iVar5 == 2) {
    *(undefined4 *)(param_1 + 0x1a4) = 1;
    *(undefined4 *)(param_1 + 0x1a8) = 0x800080;
  }
  else if (iVar5 == 4) {
LAB_1400096aa:
    *(undefined4 *)(param_1 + 0x1a4) = 2;
    *(undefined4 *)(param_1 + 0x1a8) = 0x900090;
  }
  else {
    if (iVar5 == 8) {
      *(undefined4 *)(param_1 + 0x1a4) = 3;
    }
    else if (iVar5 == 0x10) {
      *(undefined4 *)(param_1 + 0x1a4) = 4;
    }
    else {
      if (iVar5 != 0x20) goto LAB_1400096aa;
      *(undefined4 *)(param_1 + 0x1a4) = 5;
    }
    *(undefined4 *)(param_1 + 0x1a8) = 0xa000a0;
  }
  **(undefined4 **)(lVar3 + 0x10) = 0x13;
  *(undefined4 *)(*(longlong *)(lVar3 + 0x10) + 4) = 0;
  *(undefined4 *)(*(longlong *)(lVar3 + 0x10) + 0x88) = 2;
  *(longlong *)(*(longlong *)(lVar3 + 0x10) + 0x90) = param_1 + 0x1ac;
  iVar5 = Sbp2SendRequest(param_1,lVar3,(undefined *)0x2);
  if (iVar5 < 0) goto LAB_1400099dd;
  iVar5 = *(int *)(param_1 + 0x1b4);
  if (iVar5 == 0x200) {
    uVar4 = *(ushort *)(param_1 + 0x1aa);
    if (0x70 < uVar4) {
      uVar4 = 0x70;
    }
LAB_1400097aa:
    *(ushort *)(param_1 + 0x1aa) = uVar4;
  }
  else {
    if (iVar5 == 0x400) {
      uVar4 = *(ushort *)(param_1 + 0x1aa);
      if (0x80 < uVar4) {
        uVar4 = 0x80;
      }
      goto LAB_1400097aa;
    }
    if (iVar5 == 0x800) {
      uVar4 = *(ushort *)(param_1 + 0x1aa);
      if (0x90 < uVar4) {
        uVar4 = 0x90;
      }
      goto LAB_1400097aa;
    }
    if (iVar5 == 0x1000) {
      uVar4 = *(ushort *)(param_1 + 0x1aa);
      if (0xa0 < uVar4) {
        uVar4 = 0xa0;
      }
      goto LAB_1400097aa;
    }
  }
  iVar5 = *(int *)(param_1 + 0x1b0);
  if (iVar5 == 0x200) {
    uVar4 = 0x70;
    if (*(ushort *)(param_1 + 0x1a8) < 0x71) {
      uVar4 = *(ushort *)(param_1 + 0x1a8);
    }
    *(ushort *)(param_1 + 0x1a8) = uVar4;
  }
  else if (iVar5 == 0x400) {
    uVar4 = 0x80;
    if (*(ushort *)(param_1 + 0x1a8) < 0x81) {
      uVar4 = *(ushort *)(param_1 + 0x1a8);
    }
    *(ushort *)(param_1 + 0x1a8) = uVar4;
  }
  else if (iVar5 == 0x800) {
    uVar4 = 0x90;
    if (*(ushort *)(param_1 + 0x1a8) < 0x91) {
      uVar4 = *(ushort *)(param_1 + 0x1a8);
    }
    *(ushort *)(param_1 + 0x1a8) = uVar4;
  }
  else if (iVar5 == 0x1000) {
    uVar4 = 0xa0;
    if (*(ushort *)(param_1 + 0x1a8) < 0xa1) {
      uVar4 = *(ushort *)(param_1 + 0x1a8);
    }
    *(ushort *)(param_1 + 0x1a8) = uVar4;
  }
  **(undefined4 **)(lVar3 + 0x10) = 0x13;
  *(undefined4 *)(*(longlong *)(lVar3 + 0x10) + 4) = 0;
  *(undefined4 *)(*(longlong *)(lVar3 + 0x10) + 0x88) = 4;
  *(longlong *)(*(longlong *)(lVar3 + 0x10) + 0x90) = param_1 + 0x1b8;
  iVar5 = Sbp2SendRequest(param_1,lVar3,(undefined *)0x2);
  if (iVar5 < 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_q(WPP_GLOBAL_Control[3],0x7b,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1);
    }
  }
  else {
    **(undefined4 **)(lVar3 + 0x10) = 0x13;
    *(undefined4 *)(*(longlong *)(lVar3 + 0x10) + 4) = 0;
    *(undefined4 *)(*(longlong *)(lVar3 + 0x10) + 0x88) = 7;
    *(undefined4 **)(*(longlong *)(lVar3 + 0x10) + 0x90) = &local_40;
    iVar5 = Sbp2SendRequest(param_1,lVar3,(undefined *)0x2);
    if (iVar5 < 0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_q(WPP_GLOBAL_Control[3],0x7c,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1
                );
      }
      iVar5 = 0;
      *(undefined4 *)(*(longlong *)(param_1 + 0x58) + 0x30) = 0x10000;
    }
    else {
      uVar2 = CONCAT44(local_34,uStack_38);
      uVar7 = 0x1ff000;
      if (uVar2 == 0) {
        uVar1 = *(uint *)(*(longlong *)(param_1 + 0x58) + 0x30);
        uVar7 = 0x1ff000;
        if (uVar1 < 0x1ff000) {
          uVar7 = (ulonglong)uVar1;
        }
        *(int *)(*(longlong *)(param_1 + 0x58) + 0x30) = (int)uVar7;
      }
      else {
        uVar6 = 0x1ff000;
        if (uVar2 < 0x1ff000) {
          uVar6 = uVar2;
        }
        uVar8 = (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x58) + 0x30);
        if ((uVar6 <= uVar8) && (uVar8 = 0x1ff000, uVar2 < 0x1ff000)) {
          uVar8 = uVar2;
        }
        *(int *)(*(longlong *)(param_1 + 0x58) + 0x30) = (int)uVar8;
      }
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        uVar1 = *(uint *)(*(longlong *)(param_1 + 0x58) + 0x30);
        WPP_SF_qDDD(WPP_GLOBAL_Control[3],uVar7,(ulonglong)uVar1,param_1,(char)local_34,
                    (char)uStack_38,(char)uVar1);
      }
    }
  }
LAB_1400099dd:
  DeAllocateIrpAndIrb(param_1,lVar3);
  return iVar5;
}



===== Sbp2GlobalStatusCallback @ 140009a20 =====

undefined8 Sbp2GlobalStatusCallback(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  code *pcVar5;
  undefined1 uVar6;
  char cVar7;
  int iVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined2 uVar12;
  longlong *plVar13;
  undefined1 *puVar14;
  undefined8 uVar15;
  undefined4 uVar16;
  undefined *puVar17;
  size_t _Size;
  longlong *plVar18;
  ushort uVar19;
  longlong lVar20;
  uint uVar21;
  uint *_Src;
  undefined1 auStackY_b8 [8];
  undefined1 auStackY_b0 [24];
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  
  uVar15 = 0;
  local_58 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if (*(longlong **)(param_1 + 0x18) == (longlong *)0x0) {
    if ((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return 0;
    }
    if (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 3) {
      return 0;
    }
    WPP_SF_q(WPP_GLOBAL_Control[3],0x5c,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1);
    return 0;
  }
  lVar2 = **(longlong **)(param_1 + 0x18);
  plVar3 = *(longlong **)(lVar2 + 0x40);
  lVar20 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x10);
  _Src = (uint *)((ulonglong)*(uint *)(lVar20 + 0x2c) + *(longlong *)(lVar20 + 0x20));
  uVar21 = *_Src;
  *_Src = uVar21 >> 0x18 | (uVar21 & 0xff0000) >> 8 | (uVar21 & 0xff00) << 8 | uVar21 << 0x18;
  uVar21 = _Src[1];
  _Src[1] = uVar21 >> 0x18 | (uVar21 & 0xff0000) >> 8 | (uVar21 & 0xff00) << 8 | uVar21 << 0x18;
  uVar9 = CheckStatusResponseValue((longlong)_Src);
  uVar21 = *(uint *)((longlong)plVar3 + 0x14);
  puVar17 = (undefined *)(ulonglong)uVar21;
  iVar8 = (int)uVar9;
  if ((uVar21 >> 0x12 & 1) != 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 3)) goto LAB_140009ae4;
    uVar12 = 0x5d;
LAB_140009ac7:
    WPP_SF_qDd(WPP_GLOBAL_Control[3],uVar12,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,plVar3,
               (char)uVar9,(char)uVar21);
LAB_140009ae4:
    ExpInterlockedPushEntrySList(plVar3 + 0x98,*(undefined8 *)(param_1 + 0x20));
    return 0;
  }
  if ((_Src[1] == *(uint *)((longlong)plVar3 + 700)) && ((short)*_Src == (short)plVar3[0x57])) {
    Sbp2LoginCompletion(plVar3,iVar8);
    puVar14 = auStackY_b8;
    goto LAB_14000a513;
  }
  uVar19 = *(ushort *)((longlong)_Src + 2) & 0xc000;
  if (uVar19 == 0x8000) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_q(WPP_GLOBAL_Control[3],0x5e,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,plVar3);
    }
    Sbp2AccessRegisterEx((longlong)plVar3,(uint *)(plVar3 + 0x20),0x410,-1);
    Sbp2HandleUnsolicited(plVar3,(longlong)_Src);
    puVar14 = auStackY_b8;
    goto LAB_14000a513;
  }
  if (uVar19 == 0xc000) {
    puVar14 = auStackY_b8;
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (puVar14 = auStackY_b8, (*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (puVar14 = auStackY_b8, 4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_q(WPP_GLOBAL_Control[3],0x5f,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,plVar3);
      puVar14 = auStackY_b8;
    }
    goto LAB_14000a513;
  }
  if (plVar3[0x79] == 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 4)) goto LAB_140009ae4;
    uVar12 = 0x60;
    goto LAB_140009ac7;
  }
  uVar21 = _Src[1] - *(int *)((longlong)plVar3 + 0x3a4);
  uVar11 = (ulonglong)uVar21;
  uVar10 = Feature_3834274106__private_IsEnabledDeviceUsageNoInline();
  uVar6 = (undefined1)uVar21;
  if ((int)uVar10 == 0) {
    if (uVar21 < 0x181) {
LAB_140009dbd:
      uVar10 = Feature_4206787897__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar10 == 0) {
        lVar20 = plVar3[0x79];
        AcquireOrbListLock((longlong)plVar3,&local_68,'\x01');
        plVar13 = *(longlong **)(lVar20 + -8 + uVar11);
      }
      else {
        uVar10 = (ulonglong)(uVar21 - 8) / 0x30;
        if (7 < (uint)uVar10) {
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_qd(WPP_GLOBAL_Control[3],0x66,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                      plVar3,(char)uVar10);
          }
          puVar14 = auStackY_b8;
          uVar16 = 0xead;
          goto LAB_14000a4fe;
        }
        AcquireOrbListLock((longlong)plVar3,&local_68,'\x01');
        plVar13 = (longlong *)plVar3[uVar10 + 0xca];
      }
      puVar14 = auStackY_b8;
      lVar20 = param_1;
      if ((plVar13 != (longlong *)0x0) && (puVar14 = auStackY_b8, (int)plVar13[4] == -0x52150055)) {
        uVar6 = SUB81(plVar13,0);
        if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
            (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
          WPP_SF_qq(WPP_GLOBAL_Control[3],0x68,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                    plVar3,uVar6);
        }
        uVar21 = *(uint *)(plVar13 + 7);
        if ((uVar21 & 2) != 0) {
          ReleaseOrbListLock((longlong)plVar3,&local_68,'\x01');
          puVar14 = auStackY_b8;
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (puVar14 = auStackY_b8, (*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (puVar14 = auStackY_b8, 3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_qq(WPP_GLOBAL_Control[3],0x69,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                      plVar3,uVar6);
            puVar14 = auStackY_b8;
          }
          goto LAB_14000a513;
        }
        *(uint *)(plVar13 + 7) = uVar21 | 2;
        lVar20 = *(longlong *)(plVar13[6] + 0x30);
        if ((longlong *)plVar3[0xe] == plVar13) {
          *(uint *)(plVar13 + 7) = uVar21 & 0xfffffffe | 2;
          KeCancelTimer(plVar13 + 0x1e);
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_qq(WPP_GLOBAL_Control[3],0x6a,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                      plVar3,uVar6);
          }
          for (plVar18 = (longlong *)*plVar13; plVar18 != plVar3 + 0xe;
              plVar18 = (longlong *)*plVar18) {
            if ((*(uint *)(plVar18 + 7) & 2) == 0) {
              *(uint *)(plVar18 + 7) = *(uint *)(plVar18 + 7) | 1;
              KeSetTimer(plVar18 + 0x1e,(longlong)*(int *)(plVar13[6] + 0x14) * -10000000,
                         plVar18 + 0x16);
              break;
            }
          }
        }
        Free1394DataMapping((longlong)plVar3,(longlong)plVar13);
        Sbp2_SCSI_RBC_Conversion((longlong)plVar13);
        uVar11 = plVar13[6];
        plVar13[6] = 0;
        lVar4 = *plVar13;
        uVar21 = *(uint *)(plVar3 + 0x10);
        if ((*(longlong **)(lVar4 + 8) == plVar13) &&
           (plVar18 = (longlong *)plVar13[1], (longlong *)*plVar18 == plVar13)) {
          *plVar18 = lVar4;
          *(longlong **)(lVar4 + 8) = plVar18;
          plVar13[1] = (longlong)plVar13;
          *plVar13 = (longlong)plVar13;
          if ((*(ushort *)((longlong)_Src + 2) >> 0xb & 1) == 0) {
            if (uVar19 == 0x4000) {
              if (plVar3[0x17] != 0) {
                FreeAsyncRequestContext((longlong)plVar3,plVar3[0x17]);
              }
              plVar3[0x17] = (longlong)plVar13;
              *(bool *)(plVar3 + 0x18) = *(longlong *)plVar13[8] == -1;
            }
            else {
              FreeAsyncRequestContext((longlong)plVar3,(longlong)plVar13);
              if (plVar3[0x17] != 0) {
                FreeAsyncRequestContext((longlong)plVar3,plVar3[0x17]);
                plVar3[0x17] = 0;
              }
            }
          }
          else {
            Sbp2AddLog((longlong)plVar3,0x40,0x496f5265,(ulonglong)*_Src,(ulonglong)_Src[1]);
            FreeAsyncRequestContext((longlong)plVar3,(longlong)plVar13);
            if (plVar3[0x17] != 0) {
              FreeAsyncRequestContext((longlong)plVar3,plVar3[0x17]);
              plVar3[0x17] = 0;
            }
            Sbp2Reset(*plVar3,1);
            plVar13 = (longlong *)plVar3[0xe];
            if (plVar13 != plVar3 + 0xe) {
              Sbp2AccessRegisterEx((longlong)plVar3,(uint *)(plVar13 + 9),0x404,-1);
            }
          }
          uVar1 = *(uint *)(plVar3 + 0x10);
          ReleaseOrbListLock((longlong)plVar3,&local_68,'\x01');
          uVar6 = KeAcquireSpinLockRaiseToDpc(plVar3 + 0xb5);
          *(undefined4 *)((longlong)plVar3 + 0x64c) = 0;
          KeReleaseSpinLock(plVar3 + 0xb5,uVar6);
          uVar19 = *(ushort *)((longlong)_Src + 2);
          if ((uVar19 & 0x700) < 0x101) {
            if (((uVar19 & 0x3000) - 0x1000 & 0xefff) == 0) {
              if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                WPP_SF_qDd(WPP_GLOBAL_Control[3],0x6f,
                           &WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,plVar3,
                           *(undefined1 *)(uVar11 + 0x48),(char)uVar19);
              }
              *(undefined2 *)(uVar11 + 3) = 0x204;
            }
            else {
              *(undefined2 *)(uVar11 + 3) = 1;
            }
          }
          else {
            *(undefined2 *)(uVar11 + 3) = 0x204;
            if ((*(byte **)(uVar11 + 0x20) == (byte *)0x0) ||
               ((*(uint *)(uVar11 + 0xc) & 0x20) != 0)) {
              if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
                  (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
                WPP_SF_qDd(WPP_GLOBAL_Control[3],0x6e,
                           &WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,plVar3,
                           *(undefined1 *)(uVar11 + 0x48),(char)*_Src);
              }
            }
            else if ((*(uint *)((longlong)plVar3 + 0x14) & 0x10) == 0) {
              if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                WPP_SF_qd(WPP_GLOBAL_Control[3],0x6d,
                          &WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,plVar3,
                          *(undefined1 *)(uVar11 + 0x48));
              }
              if (*(void **)(uVar11 + 0x20) != (void *)0x0) {
                _Size = 0x20;
                if (*(byte *)(uVar11 + 0xb) < 0x21) {
                  _Size = (size_t)*(byte *)(uVar11 + 0xb);
                }
                memmove(*(void **)(uVar11 + 0x20),_Src,_Size);
              }
            }
            else {
              cVar7 = ConvertSbp2SenseDataToScsi
                                ((longlong)_Src,*(byte **)(uVar11 + 0x20),
                                 (uint)*(byte *)(uVar11 + 0xb));
              if (cVar7 != '\0') {
                *(byte *)(uVar11 + 3) = *(byte *)(uVar11 + 3) | 0x80;
              }
              lVar4 = *(longlong *)(uVar11 + 0x20);
              if (((((*(char *)(uVar11 + 0x48) != '\0') || (*(char *)(lVar4 + 2) != '\x02')) ||
                   (*(char *)(lVar4 + 0xc) != ':')) &&
                  (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control &&
                   ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)))) &&
                 (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                WPP_SF_qDDDDDd(WPP_GLOBAL_Control[3],(ulonglong)*(byte *)(lVar4 + 0xd),
                               (ulonglong)*(byte *)(lVar4 + 0xc),plVar3,*(char *)(uVar11 + 0x48),
                               *(undefined1 *)(lVar4 + 2),*(byte *)(lVar4 + 0xc),
                               *(byte *)(lVar4 + 0xd),(char)plVar3[0x10],
                               (char)*(undefined4 *)(uVar11 + 0x14));
              }
            }
          }
          lVar4 = *(longlong *)(_Src + 2);
          plVar3[0x13] = *(longlong *)_Src;
          plVar3[0x14] = lVar4;
          lVar4 = *(longlong *)(_Src + 6);
          plVar3[0x15] = *(longlong *)(_Src + 4);
          plVar3[0x16] = lVar4;
          Sbp2AddLog((longlong)plVar3,0x40,0x496f436f,(longlong)iVar8,lVar20);
          AcquireOrbListLock((longlong)plVar3,&local_68,'\x01');
          if ((longlong *)plVar3[0xe] == plVar3 + 0xe) {
            ReleaseOrbListLock((longlong)plVar3,&local_68,'\x01');
            Sbp2RestartPendingPowerIrp(plVar3);
          }
          else {
            ReleaseOrbListLock((longlong)plVar3,&local_68,'\x01');
          }
          *(int *)(lVar20 + 0x30) = iVar8;
          if (*(char *)(uVar11 + 3) == '\x01') {
            uVar11 = (ulonglong)*(uint *)(uVar11 + 0x10);
          }
          else {
            uVar11 = 0;
          }
          *(ulonglong *)(lVar20 + 0x38) = uVar11;
          IoReleaseRemoveLockEx(plVar3 + 3,lVar20,0x20);
          IofCompleteRequest(lVar20,0);
          if ((*(uint *)(plVar3 + 0xc) <= uVar21) && (uVar1 < uVar21)) {
            Sbp2StartNextPacketByKey(lVar2,*(uint *)((longlong)plVar3 + 0x94));
          }
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_qd(WPP_GLOBAL_Control[3],0x70,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                      plVar3,(char)plVar3[0x10]);
          }
          puVar14 = auStackY_b8;
          goto LAB_14000a513;
        }
        pcVar5 = (code *)swi(0x29);
        (*pcVar5)(3);
        puVar14 = auStackY_b0;
      }
      *(undefined8 *)(puVar14 + -8) = 0x14000a476;
      ReleaseOrbListLock((longlong)plVar3,puVar14 + 0x50,'\x01');
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        uVar15 = WPP_GLOBAL_Control[3];
        *(int *)(puVar14 + 0x20) = (int)uVar11;
        *(undefined8 *)(puVar14 + -8) = 0x14000a4b3;
        WPP_SF_qd(uVar15,0x67,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,plVar3,puVar14[0x20])
        ;
      }
      uVar16 = 0xed2;
      param_1 = lVar20;
    }
    else {
      if ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          puVar17 = &WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids;
          WPP_SF_qd(WPP_GLOBAL_Control[3],100,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                    plVar3,uVar6);
        }
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_qDDDD(WPP_GLOBAL_Control[3],0x65,puVar17,plVar3,(char)*_Src,(char)_Src[1],
                       (char)plVar3[0x74],(char)*(undefined4 *)((longlong)plVar3 + 0x3a4));
        }
      }
      puVar14 = auStackY_b8;
      uVar16 = 0xe98;
    }
  }
  else if (uVar21 < 0x180) {
    if ((7 < uVar21) && ((ulonglong)(uVar21 - 8) == ((ulonglong)(uVar21 - 8) / 0x30) * 0x30))
    goto LAB_140009dbd;
    if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
        (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
      WPP_SF_qd(WPP_GLOBAL_Control[3],99,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,plVar3,
                uVar6);
    }
    puVar14 = auStackY_b8;
    uVar16 = 0xe7f;
  }
  else {
    if ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        puVar17 = &WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids;
        WPP_SF_qd(WPP_GLOBAL_Control[3],0x61,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,plVar3
                  ,uVar6);
      }
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_qDDDD(WPP_GLOBAL_Control[3],0x62,puVar17,plVar3,(char)*_Src,(char)_Src[1],
                     (char)plVar3[0x74],(char)*(undefined4 *)((longlong)plVar3 + 0x3a4));
      }
    }
    puVar14 = auStackY_b8;
    uVar16 = 0xe68;
  }
LAB_14000a4fe:
  lVar2 = *plVar3;
  *(undefined8 *)(puVar14 + -8) = 0x14000a50e;
  Sbp2CreateRequestErrorLog(lVar2,0,uVar16,-0x3ffffe7a);
  uVar15 = 7;
LAB_14000a513:
  uVar9 = *(undefined8 *)(param_1 + 0x20);
  *(undefined8 *)(puVar14 + -8) = 0x14000a525;
  ExpInterlockedPushEntrySList(plVar3 + 0x98,uVar9);
  return uVar15;
}



===== Sbp2HandleUnsolicited @ 14000a580 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void Sbp2HandleUnsolicited(undefined8 *param_1,longlong param_2)

{
  char cVar1;
  int iVar2;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 local_30;
  byte local_28 [2];
  char local_26;
  char local_1c;
  char local_1b;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  if (((*(uint *)((longlong)param_1 + 0x14) & 0x10) != 0) &&
     ((*(byte *)(param_1[0xb] + 10) & 0x1f) == 0xe)) {
    cVar1 = ConvertSbp2SenseDataToScsi(param_2,local_28,0x12);
    if ((cVar1 != '\0') && (((local_26 == '\x06' && (local_1c == '\x7f')) && (local_1b == '\x02'))))
    {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_D(WPP_GLOBAL_Control[3],0x79,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,1);
      }
      local_30 = 0;
      local_38 = 0;
      iVar2 = PoRequestPowerIrp(*param_1,2,1);
      if (((iVar2 < 0) && ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
          (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
        WPP_SF_D(WPP_GLOBAL_Control[3],0x7a,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,iVar2);
      }
    }
  }
  return;
}



===== Sbp2Issue1394BusReset @ 14000a6ac =====

int Sbp2Issue1394BusReset(longlong *param_1)

{
  longlong lVar1;
  int iVar2;
  longlong local_res10;
  
  local_res10 = 0;
  AllocateIrpAndIrb((longlong)param_1,&local_res10);
  lVar1 = local_res10;
  if (local_res10 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    **(undefined4 **)(local_res10 + 0x10) = 0x19;
    *(undefined4 *)(*(longlong *)(local_res10 + 0x10) + 4) = 1;
    *(undefined4 *)(*(longlong *)(local_res10 + 0x10) + 0x88) = 0;
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_q(WPP_GLOBAL_Control[3],10,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1);
    }
    *(uint *)((longlong)param_1 + 0x14) = *(uint *)((longlong)param_1 + 0x14) | 0x8000;
    Sbp2SetManagementTimer((longlong)param_1,3);
    iVar2 = Sbp2SendRequest((longlong)param_1,lVar1,(undefined *)0x2);
    if (iVar2 < 0) {
      KeCancelTimer(param_1 + 0xbe);
      *(uint *)((longlong)param_1 + 0x14) = *(uint *)((longlong)param_1 + 0x14) & 0xffff7fff;
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_qd(WPP_GLOBAL_Control[3],0xb,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1
                  ,(char)iVar2);
      }
      if ((*(uint *)((longlong)param_1 + 0x14) & 0x4c0000) != 0) {
        Sbp2StartQueue(param_1);
      }
    }
    DeAllocateIrpAndIrb((longlong)param_1,lVar1);
  }
  return iVar2;
}



===== Sbp2LoginCompletion @ 14000a7f0 =====

void Sbp2LoginCompletion(longlong *param_1,int param_2)

{
  longlong *plVar1;
  uint uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  
  plVar1 = param_1 + 0xb5;
  uVar4 = KeAcquireSpinLockRaiseToDpc(plVar1);
  uVar5 = (undefined1)param_2;
  if ((*(uint *)((longlong)param_1 + 0x14) >> 9 & 1) == 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
       (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qDd(WPP_GLOBAL_Control[3],0x40,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1
                 ,uVar5,(char)*(uint *)((longlong)param_1 + 0x14));
    }
    KeReleaseSpinLock(plVar1,uVar4);
    return;
  }
  Sbp2AddLog((longlong)param_1,1,0x4c4f473c,(longlong)param_2,0);
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qDd(WPP_GLOBAL_Control[3],0x41,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1,
               (char)*(undefined4 *)((longlong)param_1 + 0x14),uVar5);
  }
  KeCancelTimer(param_1 + 0xbe);
  uVar2 = *(uint *)((longlong)param_1 + 0x14);
  *(int *)((longlong)param_1 + 0x104) = param_2;
  *(uint *)((longlong)param_1 + 0x14) = uVar2 & 0xffffddff;
  uVar3 = (undefined1)uVar2;
  if (param_2 == 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qd(WPP_GLOBAL_Control[3],0x42,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1,
                uVar3);
    }
    uVar2 = *(uint *)param_1[99];
    *(uint *)param_1[99] =
         uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    uVar2 = *(uint *)(param_1[99] + 4);
    *(uint *)(param_1[99] + 4) =
         uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    uVar2 = *(uint *)(param_1[99] + 8);
    *(uint *)(param_1[99] + 8) =
         uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    *(undefined2 *)(param_1[0xb] + 0x28) = *(undefined2 *)(param_1[99] + 4);
    *(undefined4 *)(param_1[0xb] + 0x2c) = *(undefined4 *)(param_1[99] + 8);
    if (*(int *)(param_1[99] + 8) != 0) {
      *(uint *)((longlong)param_1 + 0x14) = *(uint *)((longlong)param_1 + 0x14) & 0xffe9b6f7 | 0x400
      ;
      LOCK();
      *(undefined4 *)(param_1 + 0xc9) = 3;
      UNLOCK();
      KeReleaseSpinLock(plVar1,uVar4);
      Sbp2Reset(*param_1,1);
      Sbp2StartQueue(param_1);
      goto LAB_14000aa92;
    }
    *(undefined4 *)((longlong)param_1 + 0x104) = 0xc0000001;
  }
  else {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
       (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qDd(WPP_GLOBAL_Control[3],0x43,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1
                 ,uVar3,uVar5);
    }
    if (param_2 == -0x3fffffde) {
      if ((*(uint *)((longlong)param_1 + 0x14) >> 10 & 1) != 0) {
        *(undefined4 *)((longlong)param_1 + 0x104) = 0;
        *(uint *)((longlong)param_1 + 0x14) = *(uint *)((longlong)param_1 + 0x14) & 0xffff96f7;
      }
    }
    else if (param_2 == 0x4000) goto LAB_14000aa80;
    if ((*(uint *)((longlong)param_1 + 0x14) >> 0xc & 1) == 0) {
      *(uint *)((longlong)param_1 + 0x14) = *(uint *)((longlong)param_1 + 0x14) & 0xfffff8ff;
    }
  }
LAB_14000aa80:
  KeReleaseSpinLock(plVar1,uVar4);
LAB_14000aa92:
  KeSetEvent(param_1 + 0x5d,0,0);
  return;
}



===== Sbp2ManagementOrbStatusCallback @ 14000aad0 =====

undefined8 Sbp2ManagementOrbStatusCallback(longlong param_1)

{
  uint *puVar1;
  longlong *plVar2;
  short *psVar3;
  undefined1 uVar4;
  int iVar5;
  undefined8 uVar6;
  byte bVar7;
  uint uVar8;
  ulonglong uVar9;
  longlong lVar10;
  undefined1 uVar11;
  
  if (*(longlong **)(param_1 + 0x18) != (longlong *)0x0) {
    plVar2 = *(longlong **)(**(longlong **)(param_1 + 0x18) + 0x40);
    if ((*(uint *)(param_1 + 0x10) & 1) != 0) {
      return 6;
    }
    puVar1 = (uint *)(plVar2 + 0x7a);
    uVar8 = *puVar1;
    *puVar1 = uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 << 0x18;
    uVar8 = *(uint *)((longlong)plVar2 + 0x3d4);
    *(uint *)((longlong)plVar2 + 0x3d4) =
         uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 << 0x18;
    uVar8 = *(uint *)(plVar2[0x55] + 0x10);
    *(uint *)(plVar2[0x55] + 0x10) =
         uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 << 0x18;
    uVar6 = CheckStatusResponseValue((longlong)puVar1);
    iVar5 = (int)uVar6;
    lVar10 = (longlong)iVar5;
    Sbp2AddLog((longlong)plVar2,1,0x4d474d3c,lVar10,
               (ulonglong)(byte)*(undefined2 *)(plVar2[0x55] + 0x12));
    bVar7 = (byte)*(undefined2 *)(plVar2[0x55] + 0x12);
    uVar11 = (undefined1)uVar6;
    if (bVar7 == 0) {
      Sbp2LoginCompletion(plVar2,iVar5);
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_qDd(WPP_GLOBAL_Control[3],0x71,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                   plVar2,uVar11,(char)*(undefined4 *)((longlong)plVar2 + 0x14));
      }
    }
    else {
      if (bVar7 == 1) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_qDd(WPP_GLOBAL_Control[3],0x72,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                     plVar2,uVar11,(char)*(undefined4 *)((longlong)plVar2 + 0x14));
        }
        Sbp2AddLog((longlong)plVar2,1,0x514c473c,lVar10,0);
        if (-1 < iVar5) {
          uVar8 = *(uint *)plVar2[0x6b];
          *(uint *)plVar2[0x6b] =
               uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 << 0x18;
          psVar3 = (short *)plVar2[0x6b];
          if ((*psVar3 == 1) && (4 < (ushort)psVar3[1])) {
            uVar8 = *(uint *)(psVar3 + 4);
            *(uint *)(psVar3 + 4) =
                 uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 << 0x18;
            *(undefined2 *)plVar2[99] = *(undefined2 *)(plVar2[0x6b] + 8);
            if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x800) != 0 &&
                (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
              WPP_SF_q(WPP_GLOBAL_Control[3],0x73,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                       plVar2);
            }
          }
        }
      }
      else {
        uVar8 = bVar7 - 3;
        uVar9 = (ulonglong)uVar8;
        if (uVar8 == 0) {
          Sbp2ReconnectCompletion(plVar2,iVar5);
          return 0;
        }
        if (uVar8 == 4) {
          uVar4 = KeAcquireSpinLockRaiseToDpc(plVar2 + 0xb5);
          *(uint *)((longlong)plVar2 + 0x14) = *(uint *)((longlong)plVar2 + 0x14) | 0x800;
          uVar9 = CONCAT71((int7)(uVar9 >> 8),uVar4);
          KeReleaseSpinLock(plVar2 + 0xb5);
        }
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
           (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_qdDD(WPP_GLOBAL_Control[3],uVar9,(ulonglong)*(ushort *)(plVar2[0x55] + 0x12),plVar2
                      ,(char)*(ushort *)(plVar2[0x55] + 0x12),uVar11,
                      (char)*(undefined4 *)((longlong)plVar2 + 0x14));
        }
        Sbp2AddLog((longlong)plVar2,1,0x4d474d31,lVar10,0);
      }
      KeSetEvent(plVar2 + 0x5d,0,0);
    }
  }
  return 0;
}



===== Sbp2ManagementTransaction @ 14000adcc =====

ulonglong Sbp2ManagementTransaction(longlong *param_1,uint param_2,int param_3)

{
  undefined8 *puVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint *puVar7;
  ushort uVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  longlong local_res8;
  undefined4 uVar11;
  
  uVar10 = (ulonglong)param_2;
  local_res8 = 0;
  uVar11 = 0;
  uVar4 = 1;
  Sbp2AddLog((longlong)param_1,1,0x4d676d3e,(ulonglong)param_2,0);
  if (((*(uint *)((longlong)param_1 + 0x14) & 0x40000) != 0) ||
     (puVar1 = (undefined8 *)param_1[0x55], puVar1 == (undefined8 *)0x0)) {
    return 0xc00000c0;
  }
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  *(uint *)(param_1 + 0x95) = param_2;
  if (param_2 == 0) {
    uVar5 = Sbp2DoLogin(param_1,param_3);
    uVar4 = (uint)uVar5;
LAB_14000b28a:
    uVar5 = (ulonglong)uVar4;
  }
  else if (param_2 == uVar4) {
    memset((void *)param_1[0x6b],0,0x48);
    lVar6 = param_1[0x6d];
    puVar7 = (uint *)(puVar1 + 1);
    *(undefined4 *)(puVar1 + 2) = 0;
    *(undefined2 *)((longlong)puVar1 + 0x12) = 0x8000;
    *(longlong *)puVar7 = lVar6;
    *(undefined4 *)((longlong)puVar1 + 0x14) = 0x48;
    *(undefined2 *)(puVar1 + 2) = *(undefined2 *)(param_1[0xb] + 8);
    lVar6 = 4;
    *puVar1 = 0;
    *(undefined2 *)((longlong)puVar1 + 0x12) = 0x8001;
    do {
      uVar4 = *puVar7;
      *puVar7 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
      puVar7 = puVar7 + 1;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
    lVar6 = param_1[0x7f];
    puVar1[3] = lVar6;
    uVar4 = (uint)lVar6;
    *(uint *)(puVar1 + 3) =
         uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
    uVar4 = *(uint *)((longlong)puVar1 + 0x1c);
    *(uint *)((longlong)puVar1 + 0x1c) =
         uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
    local_res8 = -80000000;
    KeResetEvent(param_1 + 0x5d);
    uVar4 = Sbp2AccessRegisterEx((longlong)param_1,(uint *)(param_1 + 0x57),0x100,-1);
    uVar5 = (ulonglong)uVar4;
    if ((int)uVar4 < 0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_qd(WPP_GLOBAL_Control[3],0x56,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                  param_1,(char)uVar4);
      }
      goto LAB_14000b20f;
    }
    uVar4 = KeWaitForSingleObject(param_1 + 0x5d,0,0,0,&local_res8);
    uVar5 = (ulonglong)uVar4;
    if (uVar4 == 0x102) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) &&
         (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_q(WPP_GLOBAL_Control[3],0x57,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1
                );
      }
      return 0xc0000001;
    }
  }
  else {
    if (param_2 - uVar4 == 2) {
      uVar5 = Sbp2DoReconnect(param_1,param_3);
      uVar4 = (uint)uVar5;
      goto LAB_14000b28a;
    }
    if (param_2 - uVar4 == 6) {
      uVar4 = *(uint *)((longlong)param_1 + 0x14);
      if ((uVar4 & 0x800) != 0) {
        uVar5 = 0;
        goto LAB_14000b28c;
      }
      *(uint *)((longlong)param_1 + 0x14) = uVar4 | 0x800;
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
         (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_qd(WPP_GLOBAL_Control[3],0x58,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                  param_1,(char)uVar4);
      }
    }
    uVar5 = IoAcquireRemoveLockEx(param_1 + 3,0,"",1,CONCAT44(uVar11,0x20));
    if ((int)uVar5 < 0) {
      return uVar5;
    }
    *(undefined4 *)(puVar1 + 2) = 0;
    *(undefined2 *)((longlong)puVar1 + 0x12) = 0x8000;
    *(undefined2 *)(puVar1 + 2) = *(undefined2 *)param_1[99];
    *(ushort *)((longlong)puVar1 + 0x12) = (ushort)param_2 & 0xff | 0x8000;
    uVar4 = *(uint *)(puVar1 + 2);
    *(uint *)(puVar1 + 2) =
         uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
    lVar6 = param_1[0x7f];
    puVar1[3] = lVar6;
    uVar4 = (uint)lVar6;
    *(uint *)(puVar1 + 3) =
         uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
    uVar4 = *(uint *)((longlong)puVar1 + 0x1c);
    *(uint *)((longlong)puVar1 + 0x1c) =
         uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
    bVar2 = KeGetCurrentIrql();
    KeResetEvent(param_1 + 0x5d);
    uVar9 = 0x4d676d31;
    Sbp2AddLog((longlong)param_1,1,0x4d676d31,uVar10,(ulonglong)(bVar2 < 2));
    uVar5 = CONCAT62((int6)((ulonglong)uVar9 >> 0x10),-(ushort)(bVar2 < 2)) & 0xfffffffffffffd00;
    uVar8 = (short)uVar5 + 0x400;
    uVar9 = CONCAT62((int6)(uVar5 >> 0x10),uVar8);
    iVar3 = Sbp2AccessRegisterEx((longlong)param_1,(uint *)(param_1 + 0x57),uVar8,-1);
    uVar5 = (ulonglong)iVar3;
    if (iVar3 < 0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_qdD(WPP_GLOBAL_Control[3],0x5b,uVar9,param_1,(char)param_2,(char)iVar3);
      }
      Sbp2AddLog((longlong)param_1,1,0x4d676d34,uVar10,uVar5);
    }
    else if (bVar2 < 2) {
      local_res8 = (longlong)*(int *)(param_1[0xb] + 0x40) * -10000;
      iVar3 = KeWaitForSingleObject(param_1 + 0x5d,0,0,0,&local_res8);
      uVar5 = (ulonglong)iVar3;
      bVar2 = 1;
      Sbp2AddLog((longlong)param_1,1,0x4d676d32,uVar10,uVar5);
      if (iVar3 == 0x102) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
           (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_qd(WPP_GLOBAL_Control[3],0x59,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                    param_1,(char)param_2);
        }
        uVar5 = 0xc0000001;
      }
      else if (iVar3 == 0) {
        iVar3 = *(int *)((longlong)param_1 + 0x104);
        uVar5 = (ulonglong)iVar3;
        Sbp2AddLog((longlong)param_1,bVar2,0x4d676d33,uVar5,0);
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_qd(WPP_GLOBAL_Control[3],0x5a,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                    param_1,(char)iVar3);
        }
      }
    }
    IoReleaseRemoveLockEx(param_1 + 3,0,0x20);
  }
LAB_14000b28c:
  Sbp2AddLog((longlong)param_1,1,0x4d676d3c,uVar10,(longlong)(int)uVar5);
LAB_14000b20f:
  return uVar5 & 0xffffffff;
}



===== Sbp2ManagementTransactionWorker @ 14000b2e0 =====

void Sbp2ManagementTransactionWorker(longlong param_1,undefined8 param_2)

{
  longlong *plVar1;
  uint uVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong *plVar6;
  code *pcVar7;
  undefined1 uVar8;
  byte bVar9;
  int iVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  longlong lVar15;
  longlong *plVar16;
  undefined8 uVar17;
  undefined1 auStackY_58 [8];
  undefined1 auStackY_50 [24];
  
  plVar3 = *(longlong **)(param_1 + 0x40);
  lVar15 = 0xc000000e;
  iVar10 = -0x3ffffff2;
  plVar16 = plVar3 + 0xb5;
  uVar8 = KeAcquireSpinLockRaiseToDpc(plVar16);
  uVar12 = 1;
  uVar17 = 0x4d675749;
  Sbp2AddLog((longlong)plVar3,1,0x4d675749,param_2,0);
  puVar13 = auStackY_58;
  uVar2 = *(uint *)((longlong)plVar3 + 0x14);
  if ((uVar2 >> 0x12 & 1) == 0) {
    while ((uVar2 >> 8 & 1) != 0) {
      KeReleaseSpinLock(plVar16);
      uVar17 = 0;
      uVar12 = 0;
      KeWaitForSingleObject(plVar3 + 0x5d,0,0,0);
      uVar8 = KeAcquireSpinLockRaiseToDpc(plVar16);
      uVar2 = *(uint *)((longlong)plVar3 + 0x14);
    }
    plVar1 = plVar3 + 0xc6;
    do {
      plVar4 = (longlong *)*plVar1;
      if ((int)plVar4[2] == 2) {
        KeReleaseSpinLock(plVar16);
        uVar11 = Sbp2ManagementTransaction(plVar3,0,*(int *)((longlong)plVar4 + 0x14));
        iVar10 = (int)uVar11;
        uVar8 = KeAcquireSpinLockRaiseToDpc(plVar16);
        uVar17 = 0x4d675731;
LAB_14000b424:
        lVar15 = (longlong)iVar10;
        uVar12 = 1;
        Sbp2AddLog((longlong)plVar3,1,(int)uVar17,lVar15,0);
      }
      else if ((int)plVar4[2] == 4) {
        KeReleaseSpinLock(plVar16,uVar8);
        iVar10 = Sbp2Issue1394BusReset(plVar3);
        uVar8 = KeAcquireSpinLockRaiseToDpc(plVar16);
        uVar17 = 0x4d675732;
        goto LAB_14000b424;
      }
      iVar10 = (int)lVar15;
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_qDddD(WPP_GLOBAL_Control[3],uVar12,uVar17,plVar3,
                     (char)*(undefined4 *)((longlong)plVar3 + 0x14),(char)plVar4[2],
                     (char)*(undefined4 *)((longlong)plVar4 + 0x14),(char)lVar15);
      }
      lVar5 = *plVar4;
      if ((*(longlong **)(lVar5 + 8) != plVar4) ||
         (plVar6 = (longlong *)plVar4[1], (longlong *)*plVar6 != plVar4)) goto LAB_14000b557;
      *plVar6 = lVar5;
      *(longlong **)(lVar5 + 8) = plVar6;
      ExFreePool(plVar4);
    } while ((iVar10 != -0x3ffffff2) && ((longlong *)*plVar1 != plVar1));
  }
  KeReleaseSpinLock(plVar16,uVar8);
  uVar12 = IsDeviceGone(plVar3,iVar10);
  puVar14 = auStackY_58;
  if ((char)uVar12 == '\0') goto LAB_14000b574;
  if ((*(uint *)((longlong)plVar3 + 0x14) & 2) != 0) {
    *(undefined4 *)((longlong)plVar3 + 0x104) = 0xc000000e;
    KeSetEvent(plVar3 + 0x60,0,0);
  }
  bVar9 = KeAcquireSpinLockRaiseToDpc(plVar16);
  plVar16 = (longlong *)(ulonglong)bVar9;
  plVar1 = plVar3 + 0xc6;
  while (plVar4 = (longlong *)*plVar1, plVar4 != plVar1) {
    if (((longlong *)plVar4[1] != plVar1) ||
       (lVar15 = *plVar4, *(longlong **)(lVar15 + 8) != plVar4)) goto LAB_14000b557;
    *plVar1 = lVar15;
    *(longlong **)(lVar15 + 8) = plVar1;
    ExFreePool();
  }
LAB_14000b55e:
  *(undefined8 *)(puVar13 + -8) = 0x14000b56f;
  KeReleaseSpinLock(plVar3 + 0xb5,bVar9);
  puVar14 = puVar13;
LAB_14000b574:
  *(undefined8 *)(puVar14 + -8) = 0x14000b57e;
  IoFreeWorkItem(param_2);
  *(undefined8 *)(puVar14 + -8) = 0x14000b594;
  IoReleaseRemoveLockEx(plVar3 + 3,0,0x20);
  return;
LAB_14000b557:
  bVar9 = (byte)plVar16;
  pcVar7 = (code *)swi(0x29);
  (*pcVar7)(3);
  puVar13 = auStackY_50;
  goto LAB_14000b55e;
}



===== Sbp2ParseTextLeaf @ 14000b5c0 =====

void Sbp2ParseTextLeaf(longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  longlong *plVar1;
  undefined4 uVar2;
  uint uVar3;
  longlong lVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  longlong lVar8;
  undefined8 uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  longlong local_res10;
  longlong local_res18;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  local_res10 = 0;
  local_res18 = param_3;
  AllocateIrpAndIrb(param_1,&local_res10);
  lVar4 = local_res10;
  if (local_res10 == 0) {
    return;
  }
  puVar7 = (uint *)ExAllocatePool2(0x40,0x20,0x32706253);
  if (puVar7 != (uint *)0x0) {
    lVar8 = IoAllocateMdl(puVar7,0x20,0,0,0);
    if (lVar8 != 0) {
      MmBuildMdlForNonPagedPool(lVar8);
      iVar12 = 3;
      while( true ) {
        **(undefined4 **)(lVar4 + 0x10) = 0x1a;
        *(undefined4 *)(*(longlong *)(lVar4 + 0x10) + 4) = 0;
        iVar5 = Sbp2SendRequest(param_1,lVar4,(undefined *)0x2);
        if ((((iVar5 < 0) && ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_qd(WPP_GLOBAL_Control[3],0x3a,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                    param_1,(char)iVar5);
        }
        uVar2 = *(undefined4 *)(*(longlong *)(lVar4 + 0x10) + 0x88);
        *(longlong *)(*(longlong *)(lVar4 + 0x10) + 0xa0) = lVar8;
        **(undefined4 **)(lVar4 + 0x10) = 0;
        *(undefined4 *)(*(longlong *)(lVar4 + 0x10) + 4) = 0;
        *(undefined2 *)(*(longlong *)(lVar4 + 0x10) + 0x8c) = 0xffff;
        *(undefined4 *)(*(longlong *)(lVar4 + 0x10) + 0x90) = *(undefined4 *)(param_3 + 8);
        *(undefined4 *)(*(longlong *)(lVar4 + 0x10) + 0x94) = 4;
        *(undefined4 *)(*(longlong *)(lVar4 + 0x10) + 0x98) = 0;
        *(undefined4 *)(*(longlong *)(lVar4 + 0x10) + 0x9c) = 0;
        *(undefined4 *)(*(longlong *)(lVar4 + 0x10) + 0xa8) = uVar2;
        *(undefined1 *)(*(longlong *)(lVar4 + 0x10) + 0xad) = 0;
        iVar5 = Sbp2SendRequest(param_1,lVar4,(undefined *)0x2);
        if (-1 < iVar5) {
          uVar3 = *puVar7;
          uVar10 = ((uVar3 & 0xff00) << 8 | uVar3 << 0x18) >> 0x10;
          iVar12 = uVar10 * 4;
          if (0x20 < iVar12 + 4U) {
            IoFreeMdl(*(undefined8 *)(*(longlong *)(lVar4 + 0x10) + 0xa0));
            ExFreePool(puVar7);
            puVar7 = (uint *)ExAllocatePool2(0x40,iVar12 + 4U,0x32706253);
            if (puVar7 == (uint *)0x0) goto LAB_14000b9b5;
            uVar9 = IoAllocateMdl(puVar7,iVar12 + 4,0,0,0);
            *(undefined8 *)(*(longlong *)(lVar4 + 0x10) + 0xa0) = uVar9;
            if (*(longlong *)(*(longlong *)(lVar4 + 0x10) + 0xa0) == 0) goto LAB_14000b9a6;
            MmBuildMdlForNonPagedPool();
          }
          uVar11 = 1;
          *puVar7 = uVar3;
          iVar5 = 4;
          goto LAB_14000b8d4;
        }
        local_48 = 0;
        local_58 = 0;
        uStack_50 = 0;
        KeInitializeEvent(&local_58,0,0);
        local_res10 = -5000000;
        KeWaitForSingleObject(&local_58,0,0,0,&local_res10);
        if (iVar12 + -1 == 0) break;
        param_3 = local_res18;
        iVar12 = iVar12 + -1;
      }
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_qd(WPP_GLOBAL_Control[3],(short)iVar12 + 0x3a,
                  &WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1,(char)iVar5);
      }
LAB_14000b99a:
      IoFreeMdl(lVar8);
    }
LAB_14000b9a6:
    ExFreePool(puVar7);
  }
  goto LAB_14000b9b5;
  while( true ) {
    uVar11 = uVar11 + 1;
    iVar5 = iVar5 + 4;
    if (uVar10 < uVar11) break;
LAB_14000b8d4:
    *(int *)(*(longlong *)(lVar4 + 0x10) + 0x90) = *(int *)(local_res18 + 8) + iVar5;
    plVar1 = (longlong *)(*(longlong *)(*(longlong *)(lVar4 + 0x10) + 0xa0) + 0x18);
    *plVar1 = *plVar1 + 4;
    plVar1 = (longlong *)(*(longlong *)(*(longlong *)(lVar4 + 0x10) + 0xa0) + 0x20);
    *plVar1 = *plVar1 + 4;
    iVar6 = Sbp2SendRequest(param_1,lVar4,(undefined *)0x2);
    if (iVar6 < 0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_qd(WPP_GLOBAL_Control[3],0x3c,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                  param_1,(char)iVar6);
      }
      lVar8 = *(longlong *)(*(longlong *)(lVar4 + 0x10) + 0xa0);
      goto LAB_14000b99a;
    }
  }
  *(short *)((longlong)puVar7 + 2) = (short)iVar12;
  *param_4 = puVar7;
  IoFreeMdl(*(undefined8 *)(*(longlong *)(lVar4 + 0x10) + 0xa0));
LAB_14000b9b5:
  DeAllocateIrpAndIrb(param_1,lVar4);
  return;
}



===== Sbp2ReconnectCompletion @ 14000b9e0 =====

void Sbp2ReconnectCompletion(longlong *param_1,int param_2)

{
  longlong *plVar1;
  uint uVar2;
  undefined1 uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  uint uVar6;
  
  plVar1 = param_1 + 0xb5;
  uVar3 = KeAcquireSpinLockRaiseToDpc(plVar1);
  if ((*(uint *)((longlong)param_1 + 0x14) & 0x100) == 0) {
    KeReleaseSpinLock(plVar1,uVar3);
  }
  else {
    Sbp2AddLog((longlong)param_1,1,0x5265633c,(longlong)param_2,0);
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qDd(WPP_GLOBAL_Control[3],0x4e,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1
                 ,(char)param_2,(char)*(undefined4 *)((longlong)param_1 + 0x14));
    }
    KeCancelTimer(param_1 + 0xbe);
    uVar2 = *(uint *)((longlong)param_1 + 0x14);
    uVar6 = uVar2 & 0xffffbeff;
    *(int *)((longlong)param_1 + 0x104) = param_2;
    *(uint *)((longlong)param_1 + 0x14) = uVar6;
    if (param_2 < 0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_qDd(WPP_GLOBAL_Control[3],0x4f,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                   param_1,(char)param_2,(char)uVar6);
      }
      KeReleaseSpinLock(plVar1,uVar3);
      uVar4 = IsDeviceGone(param_1,param_2);
      if ((char)uVar4 == '\0') {
        uVar3 = KeAcquireSpinLockRaiseToDpc(plVar1);
        uVar5 = Sbp2QueueManagementWorkItem(param_1,2,0xffffffff);
        if ((int)uVar5 < 0) {
          Sbp2SetDeferLoginTimer((longlong)param_1);
        }
        KeReleaseSpinLock(plVar1,uVar3);
      }
    }
    else {
      *(undefined4 *)(param_1 + 0xc9) = 3;
      *(uint *)((longlong)param_1 + 0x14) = uVar2 & 0xffed9ef7 | 0x400;
      KeReleaseSpinLock(plVar1,uVar3);
      Sbp2StartQueue(param_1);
    }
    KeSetEvent(param_1 + 0x5d,0,0);
  }
  return;
}



===== Sbp2TaskOrbStatusCallback @ 14000bbd0 =====

undefined8 Sbp2TaskOrbStatusCallback(longlong param_1)

{
  longlong *plVar1;
  uint *puVar2;
  longlong *plVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined1 uVar6;
  
  if (*(longlong **)(param_1 + 0x18) != (longlong *)0x0) {
    plVar3 = *(longlong **)(**(longlong **)(param_1 + 0x18) + 0x40);
    if ((*(uint *)(param_1 + 0x10) & 1) != 0) {
      return 6;
    }
    if ((*(uint *)(param_1 + 0x10) & 2) != 0) {
      plVar1 = plVar3 + 0xb5;
      KeAcquireSpinLockAtDpcLevel(plVar1);
      if ((*(uint *)((longlong)plVar3 + 0x14) >> 0xd & 1) == 0) {
        KeReleaseSpinLockFromDpcLevel(plVar1);
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_q(WPP_GLOBAL_Control[3],0x75,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                   plVar3);
        }
      }
      else if ((*(uint *)((longlong)plVar3 + 0x14) & 0x1200) == 0) {
        KeCancelTimer(plVar3 + 0xbe);
        KeReleaseSpinLockFromDpcLevel(plVar1);
        puVar2 = (uint *)(plVar3 + 0x85);
        uVar4 = *puVar2;
        *puVar2 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
        uVar4 = *(uint *)((longlong)plVar3 + 0x42c);
        *(uint *)((longlong)plVar3 + 0x42c) =
             uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
        uVar5 = CheckStatusResponseValue((longlong)puVar2);
        if ((int)uVar5 != 0) {
          uVar6 = (undefined1)plVar3[0x53];
          if ((int)plVar3[0x53] == 0xf) {
            if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              WPP_SF_qDd(WPP_GLOBAL_Control[3],0x76,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids
                         ,plVar3,0xf,0xf);
            }
            Sbp2CreateRequestErrorLog(*plVar3,0,0x115e,-0x7ffffff0);
            Sbp2Reset(*plVar3,5);
            return 0;
          }
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_qDd(WPP_GLOBAL_Control[3],0x77,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                       plVar3,uVar6,uVar6);
          }
        }
        Sbp2Reset(*plVar3,1);
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_q(WPP_GLOBAL_Control[3],0x78,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                   plVar3);
        }
        KeAcquireSpinLockAtDpcLevel(plVar1);
        uVar4 = *(uint *)((longlong)plVar3 + 0x14);
        *(uint *)((longlong)plVar3 + 0x14) = uVar4 & 0xffffdfff;
        if ((int)plVar3[0x53] == 0xf) {
          *(uint *)((longlong)plVar3 + 0x14) = uVar4 & 0xffffdff7;
          Sbp2AddLog((longlong)plVar3,1,0x54527374,(longlong)(int)uVar5,0);
        }
        uVar4 = *(uint *)(plVar3 + 0xc) >> 1;
        if (uVar4 < 5) {
          uVar4 = 5;
        }
        *(uint *)(plVar3 + 0xc) = uVar4;
        KeReleaseSpinLockFromDpcLevel(plVar1);
        CleanupOrbList(plVar3,-0x3ffffdc0);
        Sbp2StartNextPacketByKey(*plVar3,0);
      }
      else {
        KeReleaseSpinLockFromDpcLevel(plVar1);
      }
    }
  }
  return 0;
}



===== Sbp2UpdateNodeInformation @ 14000be80 =====

int Sbp2UpdateNodeInformation(longlong *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 uVar5;
  int iVar6;
  longlong *plVar7;
  bool bVar8;
  longlong local_res8;
  longlong local_res10;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_res10 = 0;
  local_res8 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  if ((int)param_1[0x34] == -1) {
    AllocateIrpAndIrb((longlong)param_1,&local_res8);
    lVar4 = local_res8;
    if (local_res8 == 0) {
      iVar6 = -0x3fffff66;
    }
    else {
      **(undefined4 **)(local_res8 + 0x10) = 0x1a;
      *(undefined4 *)(*(longlong *)(local_res8 + 0x10) + 4) = 0;
      iVar6 = Sbp2SendRequest((longlong)param_1,local_res8,(undefined *)0x2);
      if (iVar6 < 0) {
        IsDeviceGone(param_1,iVar6);
      }
      else {
        uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xb5);
        uVar1 = *(undefined4 *)(*(longlong *)(lVar4 + 0x10) + 0x88);
        *(undefined4 *)((longlong)param_1 + 0x19c) = uVar1;
        KeReleaseSpinLock(param_1 + 0xb5,CONCAT31((int3)((uint)uVar1 >> 8),uVar5));
      }
      DeAllocateIrpAndIrb((longlong)param_1,lVar4);
      if (-1 < iVar6) goto LAB_14000bee3;
    }
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qd(WPP_GLOBAL_Control[3],0x3d,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_1,
                (char)iVar6);
    }
  }
  else {
    uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xb5);
    *(int *)((longlong)param_1 + 0x19c) = (int)param_1[0x34];
    KeReleaseSpinLock(param_1 + 0xb5,uVar5);
LAB_14000bee3:
    AllocateIrpAndIrb((longlong)param_1,&local_res10);
    lVar4 = local_res10;
    if (local_res10 == 0) {
      iVar6 = -0x3fffff66;
    }
    else {
      **(undefined4 **)(local_res10 + 0x10) = 0x14;
      *(undefined4 *)(*(longlong *)(local_res10 + 0x10) + 0x88) = 1;
      *(undefined4 *)(*(longlong *)(local_res10 + 0x10) + 4) = 0;
      iVar6 = Sbp2SendRequest((longlong)param_1,local_res10,(undefined *)0x2);
      if (iVar6 < 0) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_qd(WPP_GLOBAL_Control[3],0x3e,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                    param_1,(char)iVar6);
        }
      }
      else {
        uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xb5);
        lVar3 = *(longlong *)(lVar4 + 0x10);
        *(undefined2 *)((longlong)param_1 + 0x19a) = *(undefined2 *)(lVar3 + 0x8c);
        KeReleaseSpinLock(param_1 + 0xb5,CONCAT71((int7)((ulonglong)lVar3 >> 8),uVar5));
        AcquireOrbListLock((longlong)param_1,&local_38,'\0');
        plVar7 = (longlong *)param_1[0xe];
        if (plVar7 != param_1 + 0xe) {
          do {
            uVar2 = *(uint *)(plVar7[8] + 8);
            *(uint *)(plVar7[8] + 8) =
                 uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
            uVar2 = *(uint *)(plVar7[8] + 0xc);
            *(uint *)(plVar7[8] + 0xc) =
                 uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
            *(undefined2 *)(plVar7[8] + 10) = *(undefined2 *)((longlong)param_1 + 0x19a);
            uVar2 = *(uint *)(plVar7[8] + 8);
            *(uint *)(plVar7[8] + 8) =
                 uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
            uVar2 = *(uint *)(plVar7[8] + 0xc);
            *(uint *)(plVar7[8] + 0xc) =
                 uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
            bVar8 = plVar7 != (undefined8 *)param_1[0xf];
            plVar7 = (undefined8 *)*plVar7;
          } while (bVar8);
        }
        ReleaseOrbListLock((longlong)param_1,&local_38,'\0');
      }
      DeAllocateIrpAndIrb((longlong)param_1,lVar4);
    }
  }
  return iVar6;
}



===== Sbp2_ProcessTextualDescriptor @ 14000c144 =====

undefined4 Sbp2_ProcessTextualDescriptor(uint *param_1,short *param_2)

{
  longlong *plVar1;
  size_t _Size;
  byte bVar2;
  uint uVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  void *_Dst;
  longlong lVar6;
  int iVar7;
  ulonglong uVar8;
  undefined8 local_38;
  undefined8 uStack_30;
  
  uVar4 = 0;
  plVar1 = (longlong *)(param_2 + 4);
  local_38 = 0;
  uStack_30 = 0;
  if ((*param_2 == 0) && (*plVar1 == 0)) {
    uVar3 = (*param_1 & 0xff00) << 8 | *param_1 << 0x18;
    if ((ushort)(uVar3 >> 0x10) < 2) {
      uVar5 = 0;
    }
    else {
      uVar5 = (ulonglong)((uVar3 >> 0x10) - 2);
    }
    uVar3 = param_1[1];
    _Size = uVar5 * 4;
    uVar3 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    _Dst = (void *)ExAllocatePool2(0x40,_Size + 2,0x32706253);
    if (_Dst == (void *)0x0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_(WPP_GLOBAL_Control[3],0x7f,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids);
      }
      uVar4 = 0xc000009a;
    }
    else {
      memmove(_Dst,param_1 + 3,_Size);
      uVar8 = 0;
      if (uVar5 != 0) {
        do {
          iVar7 = (int)uVar8;
          bVar2 = *(byte *)(uVar8 + (longlong)_Dst);
          if (bVar2 == 0) break;
          if (((bVar2 == 0x2c) || (bVar2 < 0x20)) || (0x7f < bVar2)) {
            if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
               (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              WPP_SF_D(WPP_GLOBAL_Control[3],0x80,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                       (uint)bVar2);
            }
            *(undefined1 *)(uVar8 + (longlong)_Dst) = 0x20;
          }
          if ((int)uVar3 < 0) {
            iVar7 = iVar7 + 1;
          }
          uVar8 = (ulonglong)(iVar7 + 1);
        } while (uVar8 < _Size);
      }
      param_2[0] = 0;
      param_2[1] = 200;
      lVar6 = ExAllocatePool2(0x40,200,0x32706253);
      *plVar1 = lVar6;
      if (lVar6 == 0) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_(WPP_GLOBAL_Control[3],0x81,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids);
        }
        uVar4 = 0xc000009a;
      }
      else {
        if ((int)uVar3 < 0) {
          RtlAppendUnicodeToString(param_2);
        }
        else {
          RtlInitAnsiString(&local_38,_Dst);
          uVar4 = RtlAnsiStringToUnicodeString(param_2,&local_38,0);
        }
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_S(WPP_GLOBAL_Control[3],0x82,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
                   (wchar_t *)*plVar1);
        }
      }
      ExFreePool(_Dst);
    }
  }
  else {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_S(WPP_GLOBAL_Control[3],0x7e,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,
               (wchar_t *)*plVar1);
    }
    uVar4 = 0;
  }
  return uVar4;
}



===== WPP_SF_Dq @ 14000c3ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,0x1f,local_res20,4,
             &param_5,8,0);
  return;
}



===== WPP_SF_qDDD @ 14000c448 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,0x7d,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_qDDDD @ 14000c4bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDDDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_2,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_SF_qDDDDDd @ 14000c540 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDDDDDd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                   undefined1 param_9,undefined1 param_10)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,0x6b,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,&param_9,4,&param_10,4,0);
  return;
}



===== WPP_SF_qDDd @ 14000c5dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDDd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_2,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_qDddD @ 14000c650 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDddD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,0x55,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_SF_qdD @ 14000c6d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qdD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,param_2,&local_res20,8,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_qdDD @ 14000c73c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qdDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,0x74,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_qdSDd @ 14000c7b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qdSDd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,wchar_t *param_6,undefined1 param_7,undefined1 param_8)

{
  longlong lVar1;
  wchar_t *pwVar2;
  undefined8 local_res20;
  
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
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,0x47,&local_res20,8,
             &param_5,4,pwVar2,lVar1,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_SF_qqDD @ 14000c88c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_qqqD @ 14000c8f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqqD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_8a1fd43d597730a303b3ccd4cd330408_Traceguids,0x1b,&local_res20,8,
             &param_5,8,&param_6,8,&param_7,4,0);
  return;
}



===== AcquireOrbListLock @ 14000c96c =====

void AcquireOrbListLock(longlong param_1,undefined8 param_2,char param_3)

{
  void *pvVar1;
  void *pvVar2;
  void *pvVar3;
  
  pvVar2 = SystemReserved1[0xf];
  Sbp2AddLog(param_1,0,0x45716341,SystemReserved1[0xf],(ulonglong)*(uint *)(param_1 + 0x90));
  do {
    do {
      pvVar3 = (void *)0x0;
      LOCK();
      pvVar1 = *(void **)(param_1 + 0x88);
      if (pvVar1 == (void *)0x0) {
        *(void **)(param_1 + 0x88) = pvVar2;
      }
      else {
        pvVar3 = pvVar1;
      }
      UNLOCK();
      if (pvVar3 == pvVar2) {
        *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + 1;
        Sbp2AddLog(param_1,0,0x20716341,pvVar2,(ulonglong)*(uint *)(param_1 + 0x90));
        goto LAB_14000ca52;
      }
      if (param_3 == '\0') {
        KeAcquireInStackQueuedSpinLock(param_1 + 0x68,param_2);
      }
      else {
        KeAcquireInStackQueuedSpinLockAtDpcLevel();
      }
    } while (pvVar3 == (void *)0x0);
    pvVar3 = (void *)0x0;
    LOCK();
    pvVar1 = *(void **)(param_1 + 0x88);
    if (pvVar1 == (void *)0x0) {
      *(void **)(param_1 + 0x88) = pvVar2;
    }
    else {
      pvVar3 = pvVar1;
    }
    UNLOCK();
    if (pvVar1 != (void *)0x0) {
      if (param_3 == '\0') {
        KeReleaseInStackQueuedSpinLock(param_2);
      }
      else {
        KeReleaseInStackQueuedSpinLockFromDpcLevel();
      }
    }
  } while (pvVar3 != pvVar2);
LAB_14000ca52:
  Sbp2AddLog(param_1,0,0x58716341,pvVar2,(ulonglong)*(uint *)(param_1 + 0x90));
  return;
}



===== AllocateAddressForStatus @ 14000ca98 =====

int AllocateAddressForStatus(longlong param_1,longlong *param_2,char param_3)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  longlong local_res8;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_res8 = 0;
  AllocateIrpAndIrb(lVar1,&local_res8);
  lVar2 = local_res8;
  if (local_res8 == 0) {
    return -0x3fffff66;
  }
  **(undefined4 **)(local_res8 + 0x10) = 0x11;
  *(undefined4 *)(*(longlong *)(local_res8 + 0x10) + 4) = 0;
  *(undefined4 *)(*(longlong *)(local_res8 + 0x10) + 0x94) = 0x20;
  *(undefined4 *)(*(longlong *)(local_res8 + 0x10) + 0x9c) = 2;
  *(undefined4 *)(*(longlong *)(local_res8 + 0x10) + 0xa0) = 2;
  *(undefined8 *)(*(longlong *)(local_res8 + 0x10) + 0xc0) = 0;
  *(undefined8 *)(*(longlong *)(local_res8 + 0x10) + 200) = 0;
  *(undefined4 *)(*(longlong *)(local_res8 + 0x10) + 0x90) = 0;
  *(undefined2 *)(*(longlong *)(local_res8 + 0x10) + 0xb8) = 0;
  *(undefined4 *)(*(longlong *)(local_res8 + 0x10) + 0xbc) = 0;
  *(undefined4 *)(*(longlong *)(local_res8 + 0x10) + 0xd0) = 0;
  *(undefined4 *)(*(longlong *)(local_res8 + 0x10) + 0x98) = 0;
  *(longlong *)(*(longlong *)(local_res8 + 0x10) + 0xe8) = lVar1;
  if (param_3 == '\x02') {
    *(code **)(*(longlong *)(local_res8 + 0x10) + 0xa8) = Sbp2TaskOrbStatusCallback;
    lVar4 = lVar1 + 0x428;
LAB_14000cca8:
    lVar4 = IoAllocateMdl(lVar4,0x20,0,0,0);
    param_2[4] = lVar4;
    if (lVar4 == 0) {
      iVar3 = -0x3fffff66;
      goto LAB_14000cc4d;
    }
  }
  else {
    if (param_3 == '\x04') {
      *(code **)(*(longlong *)(local_res8 + 0x10) + 0xa8) = Sbp2ManagementOrbStatusCallback;
      lVar4 = lVar1 + 0x3d0;
      goto LAB_14000cca8;
    }
    if (param_3 == '\b') {
      *(code **)(*(longlong *)(local_res8 + 0x10) + 0xa8) = Sbp2GlobalStatusCallback;
      *(undefined8 *)(*(longlong *)(local_res8 + 0x10) + 0x88) = 0;
      param_2[4] = 0;
      *(longlong *)(*(longlong *)(local_res8 + 0x10) + 0xc0) = lVar1 + 0x4c0;
      *(longlong *)(*(longlong *)(local_res8 + 0x10) + 200) = lVar1 + 0x4d0;
    }
  }
  if (param_2[4] != 0) {
    MmBuildMdlForNonPagedPool();
  }
  *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x88) = param_2[4];
  *(longlong **)(*(longlong *)(lVar2 + 0x10) + 0xb0) = param_2;
  *(longlong **)(*(longlong *)(lVar2 + 0x10) + 0xd8) = param_2 + 1;
  iVar3 = Sbp2SendRequest(lVar1,lVar2,(undefined *)0x2);
  if (-1 < iVar3) {
    param_2[3] = *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0xe0);
    *param_2 = param_1;
    *(undefined2 *)((longlong)param_2 + 10) = *(undefined2 *)(lVar1 + 0x19a);
  }
LAB_14000cc4d:
  DeAllocateIrpAndIrb(lVar1,lVar2);
  return iVar3;
}



===== AllocateIrpAndIrb @ 14000ccdc =====

void AllocateIrpAndIrb(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  char *pcVar3;
  
  if (*(int *)(param_1 + 0x10) == 0x4f445073) {
    lVar1 = ExpInterlockedPopEntrySList(param_1 + 0x580);
    *param_2 = lVar1;
    if (lVar1 != 0) {
      return;
    }
  }
  else {
    *param_2 = 0;
  }
  puVar2 = (undefined8 *)ExAllocatePool2(0x40,0x30,0x6b506253);
  if (puVar2 != (undefined8 *)0x0) {
    *puVar2 = 0;
    puVar2[2] = 0;
    lVar1 = ExAllocatePool2(0x40,0x298,0x62496253);
    puVar2[2] = lVar1;
    if (lVar1 != 0) {
      puVar2[3] = 0;
      lVar1 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 8) >> 8),
                                     *(undefined1 *)(*(longlong *)(param_1 + 8) + 0x4c)),0);
      puVar2[3] = lVar1;
      if (lVar1 != 0) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          pcVar3 = "p";
          if (*(int *)(param_1 + 0x10) != 0x4f445073) {
            pcVar3 = "f";
          }
          WPP_SF_sqq(WPP_GLOBAL_Control[3],lVar1,"f",pcVar3,(char)lVar1,(char)puVar2[2]);
        }
        *param_2 = (longlong)puVar2;
        return;
      }
      ExFreePool(puVar2[2]);
    }
    ExFreePool(puVar2);
  }
  return;
}



===== AllocateSingle1394Address @ 14000ce2c =====

int AllocateSingle1394Address
              (longlong param_1,longlong param_2,undefined4 param_3,undefined8 param_4,
              longlong param_5)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  longlong local_res8;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_res8 = 0;
  AllocateIrpAndIrb(lVar1,&local_res8);
  lVar2 = local_res8;
  if (local_res8 == 0) {
    return -0x3fffff66;
  }
  **(undefined4 **)(local_res8 + 0x10) = 0x11;
  *(undefined4 *)(*(longlong *)(local_res8 + 0x10) + 4) = 0;
  *(undefined4 *)(*(longlong *)(local_res8 + 0x10) + 0x98) = 0;
  *(undefined4 *)(*(longlong *)(local_res8 + 0x10) + 0x94) = param_3;
  *(undefined4 *)(*(longlong *)(local_res8 + 0x10) + 0x9c) = 3;
  *(undefined4 *)(*(longlong *)(local_res8 + 0x10) + 0xa0) = 0;
  *(undefined8 *)(*(longlong *)(local_res8 + 0x10) + 0xa8) = 0;
  *(undefined8 *)(*(longlong *)(local_res8 + 0x10) + 0xb0) = 0;
  *(undefined8 *)(*(longlong *)(local_res8 + 0x10) + 0xc0) = 0;
  *(undefined8 *)(*(longlong *)(local_res8 + 0x10) + 200) = 0;
  *(undefined2 *)(*(longlong *)(local_res8 + 0x10) + 0xb8) = 0;
  *(undefined4 *)(*(longlong *)(local_res8 + 0x10) + 0xbc) = 0;
  *(undefined4 *)(*(longlong *)(local_res8 + 0x10) + 0xd0) = 0;
  *(longlong *)(*(longlong *)(local_res8 + 0x10) + 0xe8) = lVar1;
  *(longlong *)(*(longlong *)(local_res8 + 0x10) + 0xd8) = param_5 + 8;
  if (param_2 == 0) {
    *(undefined4 *)(*(longlong *)(local_res8 + 0x10) + 0x90) = 2;
    *(undefined8 *)(*(longlong *)(local_res8 + 0x10) + 0x88) = 0;
  }
  else {
    *(undefined4 *)(*(longlong *)(local_res8 + 0x10) + 0x90) = 0;
    lVar4 = IoAllocateMdl(param_2,param_3,0,0,0);
    *(longlong *)(param_5 + 0x20) = lVar4;
    if (lVar4 == 0) {
      iVar3 = -0x3fffff66;
      goto LAB_14000cfe7;
    }
    MmBuildMdlForNonPagedPool(lVar4);
    *(undefined8 *)(*(longlong *)(lVar2 + 0x10) + 0x88) = *(undefined8 *)(param_5 + 0x20);
  }
  iVar3 = Sbp2SendRequest(lVar1,lVar2,(undefined *)0x2);
  if (-1 < iVar3) {
    *(undefined8 *)(param_5 + 0x18) = *(undefined8 *)(*(longlong *)(lVar2 + 0x10) + 0xe0);
    *(undefined2 *)(param_5 + 10) = *(undefined2 *)(lVar1 + 0x19a);
    if (param_2 == 0) {
      lVar4 = *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x88);
      *(longlong *)(param_5 + 0x20) = lVar4;
      *(ulonglong *)(param_5 + 0x30) =
           (ulonglong)*(uint *)(lVar4 + 0x2c) + *(longlong *)(lVar4 + 0x20);
    }
  }
LAB_14000cfe7:
  DeAllocateIrpAndIrb(lVar1,lVar2);
  return iVar3;
}



===== CheckStatusResponseValue @ 14000d014 =====

undefined8 CheckStatusResponseValue(longlong param_1)

{
  ushort uVar1;
  byte bVar2;
  undefined8 uVar3;
  byte bVar4;
  
  uVar1 = *(ushort *)(param_1 + 2);
  if ((uVar1 & 0xc000) == 0x8000) {
    return 0xc0000225;
  }
  bVar2 = (byte)(uVar1 >> 0xc) & 3;
  bVar4 = (byte)uVar1;
  if (bVar2 == 0) {
    if (bVar4 < 6) {
      if (bVar4 != 5) {
        if (bVar4 == 0) {
          return 0;
        }
        if (((bVar4 == 1) || (bVar4 == 2)) || (bVar4 == 3)) {
          uVar3 = 0xc00000bb;
          goto LAB_14000d130;
        }
        if (bVar4 != 4) goto LAB_14000d05b;
      }
      uVar3 = 0xc0000022;
      goto LAB_14000d130;
    }
    if (bVar4 == 8) {
      uVar3 = 0xc000009a;
      goto LAB_14000d130;
    }
    if (bVar4 == 9) goto LAB_14000d065;
    if (bVar4 == 10) {
      uVar3 = 0xc0000214;
      goto LAB_14000d130;
    }
    if (bVar4 == 0xb) {
      return 0;
    }
    if (bVar4 == 0xc) {
      uVar3 = 0xc0000240;
      goto LAB_14000d130;
    }
  }
  else {
    if (bVar2 == 1) {
      bVar2 = bVar4 & 0xf;
      if (bVar2 != 2) {
        if (((bVar2 == 4) || (bVar2 == 5)) || (bVar2 == 6)) {
          uVar3 = 0x80000011;
          goto LAB_14000d130;
        }
        if ((bVar2 != 0xc) && (bVar2 != 0xd)) {
          if (bVar2 == 0xe) {
            uVar3 = 0xc000000d;
            goto LAB_14000d130;
          }
          if (bVar2 == 0xf) {
            uVar3 = 0xc0000141;
            goto LAB_14000d130;
          }
          goto LAB_14000d05b;
        }
      }
      uVar3 = 0xc0000186;
      goto LAB_14000d130;
    }
    if (bVar2 == 2) {
LAB_14000d065:
      uVar3 = 0xc00000af;
      goto LAB_14000d130;
    }
  }
LAB_14000d05b:
  uVar3 = 0xc0000001;
LAB_14000d130:
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_DD(WPP_GLOBAL_Control[3],0x17,&WPP_5dde293d94fa35ece92636ed4f4e222d_Traceguids,
              (uint)bVar2,bVar4);
  }
  return uVar3;
}



===== CleanupOrbList @ 14000d180 =====

void CleanupOrbList(longlong *param_1,int param_2)

{
  longlong ****pppplVar1;
  longlong ****pppplVar2;
  longlong **pplVar3;
  longlong ***ppplVar4;
  code *pcVar5;
  longlong ****pppplVar6;
  longlong ****pppplVar7;
  undefined1 uVar8;
  longlong ****local_48;
  longlong ****local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_28 = 0;
  local_38 = 0;
  uStack_30 = 0;
  AcquireOrbListLock((longlong)param_1,&local_38,'\0');
  Sbp2AddLog((longlong)param_1,0x20,0x434f7262,param_1,(longlong)param_2);
  if (param_1[0x17] != 0) {
    FreeAsyncRequestContext((longlong)param_1,param_1[0x17]);
    param_1[0x17] = 0;
  }
  pppplVar1 = (longlong ****)(param_1 + 0xe);
  if ((longlong ****)*pppplVar1 == pppplVar1) {
    ReleaseOrbListLock((longlong)param_1,&local_38,'\0');
    return;
  }
  local_40 = (longlong ****)param_1[0xf];
  pppplVar6 = (longlong ****)&local_48;
  pppplVar7 = (longlong ****)&local_48;
  if ((longlong ****)*local_40 == pppplVar1) {
    *local_40 = (longlong ***)&local_48;
    param_1[0xf] = (longlong)&local_48;
    local_48 = (longlong ****)*pppplVar1;
    pppplVar6 = pppplVar1;
    pppplVar7 = local_40;
    if ((longlong ****)local_48[1] == pppplVar1) {
      local_48[1] = (longlong ***)&local_48;
      param_1[0xf] = (longlong)pppplVar1;
      *pppplVar1 = (longlong ***)pppplVar1;
      while ((pppplVar1 = local_48, pppplVar6 = local_48, pppplVar7 = local_40,
             (longlong *****)local_48[1] == &local_48 &&
             (pppplVar2 = (longlong ****)*local_48, (longlong ****)pppplVar2[1] == local_48))) {
        pppplVar2[1] = (longlong ***)&local_48;
        local_48[1] = (longlong ***)local_48;
        *local_48 = (longlong ***)local_48;
        if ((*(uint *)(local_48 + 7) & 2) == 0) {
          pppplVar6 = local_48 + 0x1e;
          *(uint *)(local_48 + 7) = *(uint *)(local_48 + 7) & 0xfffffffe | 2;
          local_48 = pppplVar2;
          KeCancelTimer(pppplVar6);
          ReleaseOrbListLock((longlong)param_1,&local_38,'\0');
          Sbp2_SCSI_RBC_Conversion((longlong)pppplVar1);
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x2c) < '\0')) &&
             (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_q(WPP_GLOBAL_Control[3],0xb,&WPP_5dde293d94fa35ece92636ed4f4e222d_Traceguids,
                     pppplVar1);
          }
          pplVar3 = pppplVar1[6][6];
          *(int *)(pplVar3 + 6) = param_2;
          ppplVar4 = pppplVar1[6];
          if (param_2 == -0x3fffff4b) {
            *(undefined1 *)((longlong)ppplVar4 + 3) = 9;
          }
          else if (param_2 == -0x3fffff40) {
            *(undefined1 *)((longlong)ppplVar4 + 3) = 8;
          }
          else {
            uVar8 = 0x16;
            if (param_2 != -0x3ffffdc0) {
              uVar8 = 4;
            }
            *(undefined1 *)((longlong)ppplVar4 + 3) = uVar8;
          }
          if (*(short *)pplVar3 == 6) {
            if ((*(uint *)((longlong)param_1 + 0x14) & 0x1100) == 0) {
              pppplVar1[6] = (longlong ***)0x0;
              FreeAsyncRequestContext((longlong)param_1,(longlong)pppplVar1);
              if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                WPP_SF_qq(WPP_GLOBAL_Control[3],0xc,&WPP_5dde293d94fa35ece92636ed4f4e222d_Traceguids
                          ,param_1,(char)pplVar3);
              }
              IoReleaseRemoveLockEx(param_1 + 3,pplVar3);
              IofCompleteRequest(pplVar3,0);
            }
            else {
              if (((*(uint *)((longlong)param_1 + 0x14) & 0x40) == 0) ||
                 ((*(uint *)((longlong)pppplVar1[6] + 0xc) & 0x80000) == 0)) {
                Sbp2StartPacket(*param_1,(longlong *)pplVar3,(uint *)(pppplVar1[6] + 8));
              }
              else {
                Sbp2DeferPendingRequest((longlong)param_1,(longlong)pplVar3);
              }
              pppplVar1[6] = (longlong ***)0x0;
              FreeAsyncRequestContext((longlong)param_1,(longlong)pppplVar1);
            }
          }
          AcquireOrbListLock((longlong)param_1,&local_38,'\0');
        }
        else {
          local_48 = pppplVar2;
          FreeAsyncRequestContext((longlong)param_1,(longlong)pppplVar1);
        }
        if ((longlong *****)local_48 == &local_48) {
          ReleaseOrbListLock((longlong)param_1,&local_38,'\0');
          Sbp2RestartPendingPowerIrp(param_1);
          return;
        }
      }
    }
  }
  local_40 = pppplVar7;
  local_48 = pppplVar6;
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}



===== DeAllocateIrpAndIrb @ 14000d498 =====

void DeAllocateIrpAndIrb(longlong param_1,longlong param_2)

{
  if (*(int *)(param_1 + 0x10) == 0x4f445073) {
    ExpInterlockedPushEntrySList(param_1 + 0x580);
  }
  else {
    IoFreeIrp(*(undefined8 *)(param_2 + 0x18));
    ExFreePool(*(undefined8 *)(param_2 + 0x10));
    ExFreePool(param_2);
  }
  return;
}



===== Free1394DataMapping @ 14000d4fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Free1394DataMapping(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  undefined1 uVar3;
  int iVar4;
  longlong local_res10;
  
  local_res10 = 0;
  plVar1 = (longlong *)(param_2 + 0xa8);
  if (*plVar1 != 0) {
    AllocateIrpAndIrb(param_1,&local_res10);
    lVar2 = local_res10;
    if (local_res10 != 0) {
      **(undefined4 **)(local_res10 + 0x10) = 0x12;
      *(undefined4 *)(*(longlong *)(local_res10 + 0x10) + 4) = 0;
      *(undefined4 *)(*(longlong *)(local_res10 + 0x10) + 0x88) = 1;
      *(undefined8 *)(*(longlong *)(local_res10 + 0x10) + 0x90) = 0;
      *(longlong **)(*(longlong *)(local_res10 + 0x10) + 0x98) = plVar1;
      *(longlong *)(*(longlong *)(local_res10 + 0x10) + 0xa0) = param_1;
      uVar3 = KfRaiseIrql(2);
      iVar4 = (**(code **)(param_1 + 0x1b8))
                        (*(undefined8 *)(param_1 + 0x1c0),*(undefined8 *)(lVar2 + 0x10));
      KeLowerIrql(uVar3);
      if ((((iVar4 < 0) && ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_qd(WPP_GLOBAL_Control[3],0xf,&WPP_5dde293d94fa35ece92636ed4f4e222d_Traceguids,*plVar1
                  ,(char)iVar4);
      }
      if (*(longlong *)(param_2 + 0x50) != 0) {
        IoFreeMdl();
        *(undefined8 *)(param_2 + 0x50) = 0;
      }
      *plVar1 = 0;
      DeAllocateIrpAndIrb(param_1,lVar2);
    }
  }
  return;
}



===== FreeAddressRange @ 14000d650 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FreeAddressRange(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  byte bVar3;
  int iVar4;
  undefined2 uVar5;
  longlong lVar6;
  longlong local_res10;
  
  plVar1 = (longlong *)(param_2 + 0x18);
  local_res10 = 0;
  if (*plVar1 == 0) {
    return;
  }
  AllocateIrpAndIrb(param_1,&local_res10);
  lVar2 = local_res10;
  if (local_res10 == 0) {
    return;
  }
  Sbp2AddLog(param_1,0x20,0x4641526e,param_1,param_2);
  **(undefined4 **)(lVar2 + 0x10) = 0x12;
  *(undefined4 *)(*(longlong *)(lVar2 + 0x10) + 4) = 0;
  *(undefined4 *)(*(longlong *)(lVar2 + 0x10) + 0x88) = 1;
  *(short **)(*(longlong *)(lVar2 + 0x10) + 0x90) = (short *)(param_2 + 8);
  *(longlong **)(*(longlong *)(lVar2 + 0x10) + 0x98) = plVar1;
  if (*(longlong *)(param_2 + 0x20) == 0) {
    if (param_2 == param_1 + 0x480) {
      *(undefined2 *)(*(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x90) + 2) = 0x20;
    }
  }
  else if (param_2 == param_1 + 0x230) {
    *(undefined8 *)(param_2 + 0x20) = 0;
  }
  else {
    *(undefined2 *)(*(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x90) + 2) =
         *(undefined2 *)(*(longlong *)(param_2 + 0x20) + 0x28);
  }
  *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0xa0) = param_1;
  bVar3 = KeGetCurrentIrql();
  if ((bVar3 < 2) || (*(short *)(param_2 + 8) != 0)) {
    iVar4 = Sbp2SendRequest(param_1,lVar2,(undefined *)0x2);
    lVar6 = (longlong)iVar4;
    Sbp2AddLog(param_1,0x20,0x46415232,param_1,lVar6);
    iVar4 = (int)lVar6;
    if ((-1 < iVar4) ||
       ((((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control ||
         ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
        (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2)))) goto LAB_14000d833;
    uVar5 = 0xe;
  }
  else {
    iVar4 = (**(code **)(param_1 + 0x1b8))
                      (*(undefined8 *)(param_1 + 0x1c0),*(undefined8 *)(lVar2 + 0x10));
    lVar6 = (longlong)iVar4;
    Sbp2AddLog(param_1,0x20,0x46415231,param_1,lVar6);
    iVar4 = (int)lVar6;
    if (((-1 < iVar4) || ((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control)) ||
       (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) == 0 ||
        (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2)))) goto LAB_14000d833;
    uVar5 = 0xd;
  }
  WPP_SF_qd(WPP_GLOBAL_Control[3],uVar5,&WPP_5dde293d94fa35ece92636ed4f4e222d_Traceguids,*plVar1,
            (char)iVar4);
LAB_14000d833:
  *plVar1 = 0;
  if (*(longlong *)(param_2 + 0x20) != 0) {
    IoFreeMdl();
    *(undefined8 *)(param_2 + 0x20) = 0;
  }
  DeAllocateIrpAndIrb(param_1,lVar2);
  return;
}



===== FreeAsyncRequestContext @ 14000d878 =====

int FreeAsyncRequestContext(longlong param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  
  if ((param_2 == 0) || (*(int *)(param_2 + 0x20) != -0x52150055)) {
    if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
        (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
      WPP_SF_q(WPP_GLOBAL_Control[3],0x10,&WPP_5dde293d94fa35ece92636ed4f4e222d_Traceguids,param_2);
    }
    iVar2 = 0;
  }
  else {
    if (*(longlong *)(param_2 + 0xa8) != 0) {
      Free1394DataMapping(param_1,param_2);
    }
    *(uint *)(param_2 + 0x38) = *(uint *)(param_2 + 0x38) | 2;
    *(undefined4 *)(param_2 + 0x20) = 0;
    if (*(longlong *)(param_2 + 0x138) != 0) {
      ExFreePool();
      *(undefined8 *)(param_2 + 0x138) = 0;
    }
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_q(WPP_GLOBAL_Control[3],0x11,&WPP_5dde293d94fa35ece92636ed4f4e222d_Traceguids,param_2);
    }
    ExpInterlockedPushEntrySList(param_1 + 0x4e0,param_2 + 0x10);
    LOCK();
    piVar1 = (int *)(param_1 + 0x80);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    iVar2 = iVar2 + -1;
  }
  return iVar2;
}



===== IsDeviceGone @ 14000d980 =====

ulonglong IsDeviceGone(longlong *param_1,int param_2)

{
  ulonglong in_RAX;
  undefined8 uVar1;
  ulonglong uVar2;
  bool bVar3;
  
  if ((param_2 == -0x3ffffff2) && ((int)param_1[2] == 0x4f445073)) {
    bVar3 = (*(uint *)((longlong)param_1 + 0x14) & 0x40000) == 0;
    if (bVar3) {
      *(uint *)((longlong)param_1 + 0x14) = *(uint *)((longlong)param_1 + 0x14) | 0x40000;
    }
    CleanupOrbList(param_1,-0x3ffffff2);
    uVar1 = Sbp2StartQueue(param_1);
    if (bVar3) {
      IoInvalidateDeviceState(*param_1);
      uVar1 = Sbp2AddLog((longlong)param_1,1,0x49766c64,param_1,0xffffffffc000000e);
    }
    uVar2 = CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
  }
  else {
    uVar2 = in_RAX & 0xffffffffffffff00;
  }
  return uVar2;
}



===== ReleaseOrbListLock @ 14000da18 =====

void ReleaseOrbListLock(longlong param_1,undefined8 param_2,char param_3)

{
  void *pvVar1;
  byte bVar2;
  void *pvVar3;
  
  pvVar1 = SystemReserved1[0xf];
  bVar2 = 0;
  pvVar3 = SystemReserved1[0xf];
  Sbp2AddLog(param_1,0,0x456c6552,SystemReserved1[0xf],(ulonglong)*(uint *)(param_1 + 0x90));
  if (pvVar1 == *(void **)(param_1 + 0x88)) {
    *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + -1;
    Sbp2AddLog(param_1,bVar2,0x206c6552,pvVar3,(ulonglong)*(uint *)(param_1 + 0x90));
    if (*(int *)(param_1 + 0x90) == 0) {
      *(undefined8 *)(param_1 + 0x88) = 0;
      if (param_3 == '\0') {
        KeReleaseInStackQueuedSpinLock(param_2);
      }
      else {
        KeReleaseInStackQueuedSpinLockFromDpcLevel();
      }
    }
  }
  Sbp2AddLog(param_1,0,0x586c6552,pvVar1,(ulonglong)*(uint *)(param_1 + 0x90));
  return;
}



===== Sbp2AddLog @ 14000daec =====

void Sbp2AddLog(longlong param_1,byte param_2,undefined4 param_3,undefined8 param_4,
               undefined8 param_5)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_res10;
  
  if ((((param_2 & 0xf) != 0) && (param_1 != 0)) && (*(longlong *)(param_1 + 0x40) != 0)) {
    local_res10._3_1_ = (undefined1)param_3;
    local_res10._0_3_ =
         CONCAT12((char)((uint)param_3 >> 8),
                  CONCAT11((char)((uint)param_3 >> 0x10),(char)((uint)param_3 >> 0x18)));
    LOCK();
    piVar1 = (int *)(param_1 + 0x38);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    puVar3 = (undefined4 *)
             ((ulonglong)(*(uint *)(param_1 + 0x3c) & iVar2 - 1U) * 0x20 +
             *(longlong *)(param_1 + 0x40));
    *puVar3 = local_res10;
    puVar3[2] = *(undefined4 *)(param_1 + 0x14);
    *(undefined8 *)(puVar3 + 6) = param_5;
    *(undefined8 *)(puVar3 + 4) = param_4;
  }
  return;
}



===== Sbp2AllocateLog @ 14000db60 =====

void Sbp2AllocateLog(longlong param_1)

{
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(longlong *)(param_1 + 0x40) = param_1 + 0x690;
  *(longlong *)(param_1 + 0x48) = param_1 + 0x4670;
  *(undefined4 *)(param_1 + 0x3c) = 0x1ff;
  return;
}



===== Sbp2CreateRequestErrorLog @ 14000db88 =====

void Sbp2CreateRequestErrorLog(longlong param_1,longlong param_2,undefined4 param_3,int param_4)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  undefined2 *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  if (param_4 != -0x3ffffff2) {
    uVar5 = CONCAT71((int7)((ulonglong)param_2 >> 8),0x58);
    puVar4 = (undefined2 *)IoAllocateErrorLogEntry();
    uVar6 = 0;
    if (puVar4 == (undefined2 *)0x0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_q(WPP_GLOBAL_Control[3],0x16,&WPP_5dde293d94fa35ece92636ed4f4e222d_Traceguids,
                 *(undefined8 *)(param_1 + 0x40));
      }
    }
    else {
      if ((param_4 == -0x3ffffff3) || (param_4 == -0x3ffffff0)) {
        *(undefined4 *)(puVar4 + 6) = 0xc0040010;
      }
      else if (param_4 == -0x3fffff66) {
        *(undefined4 *)(puVar4 + 6) = 0xc0040002;
      }
      else if (param_4 == -0x3fffff62) {
        *(undefined4 *)(puVar4 + 6) = 0xc004000f;
      }
      else if (param_4 == -0x3ffffe7a) {
        *(undefined4 *)(puVar4 + 6) = 0xc0040014;
      }
      else if (param_4 == -0x3ffffdc0) {
        *(undefined4 *)(puVar4 + 6) = 0xc0040013;
      }
      else {
        uVar5 = 0xc0040019;
        uVar3 = 0xc0040009;
        if (param_4 != 0x102) {
          uVar3 = 0xc0040019;
        }
        *(undefined4 *)(puVar4 + 6) = uVar3;
      }
      *(undefined4 *)(puVar4 + 0xc) = 0;
      *puVar4 = 0xf;
      *(undefined4 *)(puVar4 + 8) = param_3;
      *(int *)(puVar4 + 10) = param_4;
      if (param_2 == 0) {
        puVar4[1] = 0;
      }
      else {
        puVar4[1] = 0x28;
        puVar1 = *(undefined8 **)(param_2 + 0x40);
        uVar2 = puVar1[1];
        *(undefined8 *)(puVar4 + 0x14) = *puVar1;
        *(undefined8 *)(puVar4 + 0x18) = uVar2;
        uVar2 = puVar1[3];
        *(undefined8 *)(puVar4 + 0x1c) = puVar1[2];
        *(undefined8 *)(puVar4 + 0x20) = uVar2;
        *(undefined8 *)(puVar4 + 0x24) = puVar1[4];
      }
      IoWriteErrorLogEntry();
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_qqDq(WPP_GLOBAL_Control[3],uVar5,uVar6,*(undefined8 *)(param_1 + 0x40),(char)param_1,
                    (char)param_4,(char)param_2);
      }
    }
  }
  return;
}



===== Sbp2InsertByKeyDeviceQueue @ 14000dd20 =====

undefined1 Sbp2InsertByKeyDeviceQueue(longlong param_1,longlong *param_2,uint param_3)

{
  code *pcVar1;
  undefined8 *puVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 uVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  KeAcquireSpinLockAtDpcLevel(param_1 + 0x18);
  puVar6 = auStack_28;
  puVar5 = auStack_28;
  uVar7 = 1;
  *(uint *)(param_2 + 2) = param_3;
  if (*(char *)(param_1 + 0x20) == '\x01') {
    for (puVar2 = *(undefined8 **)(param_1 + 8);
        (puVar2 != (undefined8 *)(param_1 + 8) && (*(uint *)(puVar2 + 2) <= param_3));
        puVar2 = (undefined8 *)*puVar2) {
    }
    plVar4 = (longlong *)puVar2[1];
    lVar3 = *plVar4;
    if (*(longlong **)(lVar3 + 8) != plVar4) {
      plVar4 = (longlong *)0x3;
      pcVar1 = (code *)swi(0x29);
      lVar3 = (*pcVar1)();
      puVar5 = auStack_20;
    }
    *param_2 = lVar3;
    param_2[1] = (longlong)plVar4;
    *(longlong **)(lVar3 + 8) = param_2;
    *plVar4 = (longlong)param_2;
    puVar6 = puVar5;
  }
  else {
    *(undefined1 *)(param_1 + 0x20) = 1;
    uVar7 = 0;
  }
  *(undefined8 *)(puVar6 + -8) = 0x14000ddac;
  KeReleaseSpinLockFromDpcLevel(param_1 + 0x18);
  return uVar7;
}



===== Sbp2QueueManagementWorkItem @ 14000ddd8 =====

ulonglong Sbp2QueueManagementWorkItem(undefined8 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined8 *puVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  ulonglong uVar5;
  longlong *plVar6;
  longlong lVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  undefined1 *puVar10;
  undefined1 auStackY_48 [8];
  undefined1 auStackY_40 [24];
  
  puVar1 = param_1 + 3;
  uVar5 = IoAcquireRemoveLockEx(puVar1,0,"",1);
  uVar9 = uVar5 & 0xffffffff;
  if ((int)uVar5 < 0) {
    return uVar5;
  }
  plVar6 = (longlong *)ExAllocatePool2(0x40,0x18,0x6b776253);
  if (plVar6 == (longlong *)0x0) {
LAB_14000df88:
    IoReleaseRemoveLockEx(puVar1,0,0x20);
    uVar9 = 0xc000009a;
    goto LAB_14000dfa2;
  }
  *(undefined4 *)(plVar6 + 2) = param_2;
  plVar2 = param_1 + 0xc6;
  plVar6[1] = (longlong)plVar6;
  *plVar6 = (longlong)plVar6;
  *(undefined4 *)((longlong)plVar6 + 0x14) = param_3;
  if ((longlong *)*plVar2 == plVar2) {
    lVar7 = IoAllocateWorkItem(*param_1);
    if (lVar7 == 0) goto LAB_14000df88;
    lVar3 = *plVar2;
    if (*(longlong **)(lVar3 + 8) == plVar2) {
      *plVar6 = lVar3;
      plVar6[1] = (longlong)plVar2;
      *(longlong **)(lVar3 + 8) = plVar6;
      *plVar2 = (longlong)plVar6;
      IoQueueWorkItem(lVar7,Sbp2ManagementTransactionWorker,1,lVar7);
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_qDd(WPP_GLOBAL_Control[3],0x1c,&WPP_5dde293d94fa35ece92636ed4f4e222d_Traceguids,
                   param_1,(char)plVar6[2],(char)param_3);
      }
      uVar9 = 0;
      goto LAB_14000dfa2;
    }
LAB_14000df5a:
    pcVar4 = (code *)swi(0x29);
    puVar8 = (undefined8 *)(*pcVar4)(3);
    puVar10 = auStackY_40;
  }
  else {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qd(WPP_GLOBAL_Control[3],0x1d,&WPP_5dde293d94fa35ece92636ed4f4e222d_Traceguids,param_1,
                (char)param_2);
    }
    puVar10 = auStackY_48;
    puVar8 = (undefined8 *)param_1[199];
    if ((longlong *)*puVar8 != plVar2) goto LAB_14000df5a;
  }
  *plVar6 = (longlong)plVar2;
  plVar6[1] = (longlong)puVar8;
  *puVar8 = plVar6;
  param_1[199] = plVar6;
  *(undefined8 *)(puVar10 + -8) = 0x14000df7f;
  IoReleaseRemoveLockEx(puVar1,0,0x20);
LAB_14000dfa2:
  return uVar9;
}



===== Sbp2RequestCompletionRoutine @ 14000dfd0 =====

undefined8 Sbp2RequestCompletionRoutine(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  int *piVar1;
  undefined1 uVar2;
  longlong lVar3;
  
  if ((int)param_3[4] == 2) {
    KeSetEvent(param_3 + 1,0,0);
  }
  else {
    if ((int)param_3[4] == 1) {
      if (param_3[5] != 0) {
        piVar1 = *(int **)(param_3[5] + 0x10);
        if (((*piVar1 == 0) || (*piVar1 == 1)) && (piVar1[0x25] == 8)) {
          IoFreeMdl(*(undefined8 *)(piVar1 + 0x28));
          *(undefined8 *)(*(longlong *)(param_3[5] + 0x10) + 0xa0) = 0;
        }
        DeAllocateIrpAndIrb(*param_3,param_3[5]);
      }
      lVar3 = *param_3;
    }
    else {
      LOCK();
      lVar3 = param_3[6];
      *(int *)(param_3 + 6) = 1;
      UNLOCK();
      if ((int)lVar3 == 0) {
        return 0xc0000016;
      }
      lVar3 = *param_3;
    }
    if (*(int *)(lVar3 + 0x10) == 0x4f445073) {
      uVar2 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x590);
      ExFreeToNPagedLookasideList(lVar3 + 0x500,param_3);
      KeReleaseSpinLock(lVar3 + 0x590,uVar2);
    }
    else {
      ExFreePool(param_3);
    }
  }
  return 0xc0000016;
}



===== Sbp2SendRequest @ 14000e0ec =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int Sbp2SendRequest(longlong param_1,longlong param_2,undefined *param_3)

{
  undefined4 uVar1;
  byte bVar2;
  undefined1 uVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  longlong *plVar7;
  longlong lVar8;
  undefined8 uVar9;
  int iVar10;
  int iVar11;
  
  iVar10 = (int)param_3;
  bVar2 = (byte)param_3;
  if (iVar10 != 2) {
    *(undefined4 *)(*(longlong *)(param_2 + 0x18) + 0x30) = 0x103;
  }
  if (*(int *)(param_1 + 0x10) == 0x4f445073) {
    if (((*(uint *)(param_1 + 0x14) & 0x40000) == 0) || (**(int **)(param_2 + 0x10) == 0x12)) {
      uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x590);
      plVar7 = (longlong *)ExAllocateFromNPagedLookasideList(param_1 + 0x500);
      KeReleaseSpinLock(param_1 + 0x590,uVar3);
      goto LAB_14000e1a2;
    }
LAB_14000e3ea:
    iVar10 = -0x3fffffff;
  }
  else {
    param_3 = (undefined *)0x63526253;
    plVar7 = (longlong *)ExAllocatePool2(0x40);
LAB_14000e1a2:
    if (plVar7 == (longlong *)0x0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_(WPP_GLOBAL_Control[3],0x12,&WPP_5dde293d94fa35ece92636ed4f4e222d_Traceguids);
      }
      return -0x3fffff66;
    }
    iVar11 = iVar10;
    if (iVar10 == 2) {
      bVar4 = KeGetCurrentIrql();
      if (bVar4 < bVar2) {
        param_3 = (undefined *)0x0;
        KeInitializeEvent(plVar7 + 1,0);
      }
      else {
        *(undefined4 *)(plVar7 + 6) = 0;
        iVar11 = 3;
      }
    }
    *plVar7 = param_1;
    *(int *)(plVar7 + 4) = iVar11;
    lVar8 = 0;
    if (iVar11 != 2) {
      lVar8 = param_2;
    }
    plVar7[5] = lVar8;
    lVar8 = *(longlong *)(*(longlong *)(param_2 + 0x18) + 0xb8);
    *(undefined1 *)(lVar8 + -0x48) = 0xf;
    *(undefined4 *)(lVar8 + -0x30) = 0x22021d;
    *(undefined8 *)(lVar8 + -0x40) = *(undefined8 *)(param_2 + 0x10);
    lVar8 = *(longlong *)(*(longlong *)(param_2 + 0x18) + 0xb8);
    *(code **)(lVar8 + -0x10) = Sbp2RequestCompletionRoutine;
    *(longlong **)(lVar8 + -8) = plVar7;
    *(undefined1 *)(lVar8 + -0x45) = 0xe0;
    uVar9 = *(undefined8 *)(param_2 + 0x18);
    iVar5 = IofCallDriver(*(undefined8 *)(param_1 + 8));
    if (iVar5 == -0x3fedff70) {
      *(undefined4 *)(*(longlong *)(param_2 + 0x18) + 0x30) = 0xc0120090;
      if ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          uVar9 = 0x13;
          param_3 = &WPP_5dde293d94fa35ece92636ed4f4e222d_Traceguids;
          WPP_SF_(WPP_GLOBAL_Control[3],0x13,&WPP_5dde293d94fa35ece92636ed4f4e222d_Traceguids);
        }
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          uVar1 = *(undefined4 *)(*(longlong *)(param_2 + 0x10) + 0xa8);
          WPP_SF_DDD(WPP_GLOBAL_Control[3],uVar9,param_3,uVar1,(char)uVar1,
                     (char)*(undefined4 *)(param_1 + 0x19c));
        }
      }
      if (*(int *)(param_1 + 0x10) == 0x4f445073) {
        *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x4000;
      }
    }
    lVar8 = _DAT_fffff78000000320;
    if (iVar10 != 2) {
      return iVar5;
    }
    if (iVar11 == 2) {
      if (iVar5 == 0x103) {
        KeWaitForSingleObject(plVar7 + 1,0,0,0,0);
      }
    }
    else {
      uVar6 = KeQueryTimeIncrement();
      do {
        if ((int)plVar7[6] != 0) break;
      } while (_DAT_fffff78000000320 <= (longlong)(lVar8 + 300000000 / (ulonglong)uVar6));
      LOCK();
      lVar8 = plVar7[6];
      *(int *)(plVar7 + 6) = 1;
      UNLOCK();
      if ((int)lVar8 == 0) goto LAB_14000e3ea;
    }
    if (*(int *)(param_1 + 0x10) == 0x4f445073) {
      uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x590);
      ExFreeToNPagedLookasideList(param_1 + 0x500,plVar7);
      KeReleaseSpinLock(param_1 + 0x590,uVar3);
    }
    else {
      ExFreePool(plVar7);
    }
    iVar10 = *(int *)(*(longlong *)(param_2 + 0x18) + 0x30);
  }
  return iVar10;
}



===== Sbp2SetDeferLoginTimer @ 14000e430 =====

void Sbp2SetDeferLoginTimer(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 0x10) != 0x4f445078) {
    uVar1 = *(uint *)(param_1 + 0x14);
    if ((uVar1 >> 0xb & 1) == 0) {
      uVar2 = (2 << ((byte)*(undefined4 *)(*(longlong *)(param_1 + 0x58) + 0x44) & 0x1f)) - 1;
    }
    else {
      uVar2 = 1;
    }
    *(uint *)(param_1 + 0x14) = uVar1 | 0x1000;
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qd(WPP_GLOBAL_Control[3],0x1b,&WPP_5dde293d94fa35ece92636ed4f4e222d_Traceguids,param_1,
                (char)uVar1);
    }
    Sbp2AddLog(param_1,0x40,0x4466724c,0,0);
    Sbp2SetManagementTimer(param_1,uVar2);
  }
  return;
}



===== Sbp2SetManagementTimer @ 14000e4ec =====

void Sbp2SetManagementTimer(longlong param_1,uint param_2)

{
  int iVar1;
  longlong lVar2;
  
  if (param_2 == 0) {
    lVar2 = -10000000;
    iVar1 = *(int *)(*(longlong *)(param_1 + 0x58) + 0x40);
    if (iVar1 != 0) {
      lVar2 = (longlong)iVar1 * -10000;
    }
  }
  else {
    lVar2 = (longlong)(int)param_2 * -10000000;
  }
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qDd(WPP_GLOBAL_Control[3],0x1a,&WPP_5dde293d94fa35ece92636ed4f4e222d_Traceguids,param_1,
               (char)*(undefined4 *)(param_1 + 0x14),
               (char)(SUB168(SEXT816(-0x346dc5d63886594b) * SEXT816(lVar2),8) >> 0xb) -
               (SUB161(SEXT816(-0x346dc5d63886594b) * SEXT816(lVar2),0xf) >> 7));
  }
  Sbp2AddLog(param_1,0x40,0x4d746d72,(ulonglong)param_2,0);
  KeSetTimer(param_1 + 0x5f0,lVar2,param_1 + 0x5b0);
  return;
}



===== Sbp2StartNextPacketByKey @ 14000e5e0 =====

void Sbp2StartNextPacketByKey(longlong param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  longlong *plVar6;
  longlong lVar7;
  longlong *plVar8;
  bool bVar9;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  LOCK();
  piVar1 = (int *)(lVar3 + 0x644);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if (iVar2 == 0) {
    do {
      KeAcquireSpinLockAtDpcLevel(param_1 + 0xb8);
      if (*(char *)(param_1 + 0xc0) == '\0') {
LAB_14000e64c:
        plVar8 = (longlong *)0x0;
      }
      else {
        plVar6 = (longlong *)(param_1 + 0xa8);
        plVar4 = (longlong *)*plVar6;
        if (plVar4 == plVar6) {
          *(undefined1 *)(param_1 + 0xc0) = 0;
          goto LAB_14000e64c;
        }
        plVar8 = plVar4;
        do {
          if (param_2 <= *(uint *)(plVar8 + 2)) {
            if (plVar8 != plVar6) {
              lVar7 = *plVar8;
              if (*(longlong **)(lVar7 + 8) != plVar8) goto LAB_14000e6eb;
              plVar6 = (longlong *)plVar8[1];
              bVar9 = (longlong *)*plVar6 == plVar8;
              goto LAB_14000e6c2;
            }
            break;
          }
          plVar8 = (longlong *)*plVar8;
        } while (plVar8 != plVar6);
        plVar6 = (longlong *)(param_1 + 0xa8);
        if ((longlong *)plVar4[1] != plVar6) {
LAB_14000e6eb:
          pcVar5 = (code *)swi(0x29);
          (*pcVar5)(3);
          pcVar5 = (code *)swi(3);
          (*pcVar5)();
          return;
        }
        lVar7 = *plVar4;
        bVar9 = (longlong *)*(longlong *)(lVar7 + 8) == plVar4;
        plVar8 = plVar4;
LAB_14000e6c2:
        if (!bVar9) goto LAB_14000e6eb;
        *plVar6 = lVar7;
        *(longlong **)(lVar7 + 8) = plVar6;
        *(undefined1 *)((longlong)plVar8 + 0x14) = 0;
      }
      KeReleaseSpinLockFromDpcLevel(param_1 + 0xb8);
      if (plVar8 != (longlong *)0x0) {
        Sbp2StartIo(param_1,plVar8 + -0xf);
      }
      LOCK();
      piVar1 = (int *)(lVar3 + 0x644);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    } while (iVar2 != 1);
  }
  return;
}



===== Sbp2StartPacket @ 14000e6f8 =====

void Sbp2StartPacket(longlong param_1,longlong *param_2,uint *param_3)

{
  longlong *plVar1;
  code *pcVar2;
  undefined1 uVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong *plVar6;
  char cVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  plVar1 = param_2 + 0xf;
  uVar3 = KfRaiseIrql(2);
  KeAcquireSpinLockAtDpcLevel(param_1 + 0xb8);
  puVar8 = auStack_38;
  puVar9 = auStack_38;
  cVar7 = '\x01';
  if (param_3 == (uint *)0x0) {
    if (*(char *)(param_1 + 0xc0) != '\x01') goto LAB_14000e7c9;
    lVar5 = param_1 + 0xa8;
    plVar6 = *(longlong **)(param_1 + 0xb0);
    if (*plVar6 != lVar5) goto LAB_14000e7b2;
  }
  else {
    *(uint *)(param_2 + 0x11) = *param_3;
    if (*(char *)(param_1 + 0xc0) != '\x01') {
LAB_14000e7c9:
      *(undefined1 *)(param_1 + 0xc0) = 1;
      cVar7 = '\0';
      goto LAB_14000e7d1;
    }
    plVar6 = (longlong *)(param_1 + 0xa8);
    plVar4 = (longlong *)*plVar6;
    if (plVar4 != plVar6) {
      do {
        if (*param_3 < *(uint *)(plVar4 + 2)) break;
        plVar4 = (longlong *)*plVar4;
      } while (plVar4 != plVar6);
    }
    plVar6 = (longlong *)plVar4[1];
    lVar5 = *plVar6;
    if (*(longlong **)(lVar5 + 8) == plVar6) {
      *plVar1 = lVar5;
      param_2[0x10] = (longlong)plVar6;
      *(longlong **)(lVar5 + 8) = plVar1;
      *plVar6 = (longlong)plVar1;
      puVar9 = auStack_38;
      goto LAB_14000e7d1;
    }
LAB_14000e7b2:
    plVar6 = (longlong *)0x3;
    pcVar2 = (code *)swi(0x29);
    lVar5 = (*pcVar2)();
    puVar8 = auStack_30;
  }
  *plVar1 = lVar5;
  param_2[0x10] = (longlong)plVar6;
  *plVar6 = (longlong)plVar1;
  *(longlong **)(lVar5 + 8) = plVar1;
  puVar9 = puVar8;
LAB_14000e7d1:
  *(char *)((longlong)param_2 + 0x8c) = cVar7;
  *(undefined8 *)(puVar9 + -8) = 0x14000e7de;
  KeReleaseSpinLockFromDpcLevel(param_1 + 0xb8);
  if (cVar7 == '\0') {
    *(undefined8 *)(puVar9 + -8) = 0x14000e7f2;
    Sbp2StartIo(param_1,param_2);
  }
  *(undefined8 *)(puVar9 + -8) = 0x14000e7fc;
  KeLowerIrql(uVar3);
  return;
}



===== Sbp2StartQueue @ 14000e828 =====

void Sbp2StartQueue(longlong *param_1)

{
  longlong *plVar1;
  undefined1 uVar2;
  longlong lVar3;
  
  KeAcquireSpinLockRaiseToDpc(param_1 + 0xb5);
  if (param_1[0x1c] != 0) {
    KeReleaseSpinLock();
    Sbp2RestartPendingPowerIrp(param_1);
    return;
  }
  if ((*(uint *)((longlong)param_1 + 0x14) & 0x40) == 0) {
    KeReleaseSpinLock(param_1 + 0xb5);
    uVar2 = KfRaiseIrql(2);
    lVar3 = *param_1;
  }
  else {
    KeReleaseSpinLock();
    uVar2 = KfRaiseIrql(2);
    LOCK();
    plVar1 = (longlong *)param_1[0x1b];
    param_1[0x1b] = 0;
    UNLOCK();
    lVar3 = *param_1;
    if (plVar1 != (longlong *)0x0) {
      Sbp2StartIo(lVar3,plVar1);
      goto LAB_14000e8d7;
    }
  }
  Sbp2StartNextPacketByKey(lVar3,*(uint *)((longlong)param_1 + 0x94));
LAB_14000e8d7:
  KeLowerIrql(uVar2);
  return;
}



===== WPP_SF_DD @ 14000e8f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,0);
  return;
}



===== WPP_SF_DDD @ 14000e948 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_5dde293d94fa35ece92636ed4f4e222d_Traceguids,0x14,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_qqDq @ 14000e9ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqDq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_5dde293d94fa35ece92636ed4f4e222d_Traceguids,0x15,&local_res20,8,
             &param_5,8,&param_6,4,&param_7,8,0);
  return;
}



===== WPP_SF_sqq @ 14000ea20 =====

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
            (param_1,0x2b,&WPP_5dde293d94fa35ece92636ed4f4e222d_Traceguids,10,param_4,lVar2,&param_5
             ,8,&param_6,8,0);
  return;
}



===== RtlStringCbPrintfA @ 14000eab4 =====

undefined8 RtlStringCbPrintfA(char *param_1,longlong param_2,char *param_3,undefined8 param_4)

{
  ulonglong _Count;
  int iVar1;
  undefined8 uVar2;
  undefined8 local_res20;
  
  if (param_2 - 1U < 0x7fffffff) {
    _Count = param_2 - 1;
    uVar2 = 0;
    local_res20 = param_4;
    iVar1 = _vsnprintf(param_1,_Count,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      param_1[_Count] = '\0';
      uVar2 = 0x80000005;
    }
    else if ((longlong)iVar1 == _Count) {
      param_1[_Count] = '\0';
    }
  }
  else {
    uVar2 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = '\0';
    }
  }
  return uVar2;
}



===== ConvertSbp2SenseDataToScsi @ 14000eb28 =====

undefined1 ConvertSbp2SenseDataToScsi(longlong param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  if ((param_2 == (byte *)0x0) || (param_3 < 0xe)) {
    uVar2 = 0;
  }
  else {
    memset(param_2,0,(ulonglong)param_3);
    if ((*(byte *)(param_1 + 8) & 0xc0) == 0) {
      *param_2 = 0x70;
      uVar2 = 1;
      bVar1 = *(byte *)(param_1 + 9);
      param_2[1] = 0;
      *param_2 = bVar1 & 0xf0 | 0x70;
      bVar1 = (*(byte *)(param_1 + 9) & 0xf0) * '\x02';
      param_2[2] = bVar1;
      param_2[2] = *(byte *)(param_1 + 9) & 0xf | bVar1;
      param_2[3] = *(byte *)(param_1 + 0xc);
      param_2[4] = *(byte *)(param_1 + 0xd);
      param_2[5] = *(byte *)(param_1 + 0xe);
      param_2[6] = *(byte *)(param_1 + 0xf);
      param_2[7] = 0xb;
      param_2[8] = *(byte *)(param_1 + 0x10);
      param_2[9] = *(byte *)(param_1 + 0x11);
      param_2[10] = *(byte *)(param_1 + 0x12);
      param_2[0xb] = *(byte *)(param_1 + 0x13);
      param_2[0xc] = *(byte *)(param_1 + 10);
      param_2[0xd] = *(byte *)(param_1 + 0xb);
      if (0x11 < param_3) {
        param_2[0xe] = param_2[0xe] | *(byte *)(param_1 + 0x14);
        param_2[0xf] = *(byte *)(param_1 + 0x15);
        param_2[0x10] = *(byte *)(param_1 + 0x16);
        param_2[0x11] = *(byte *)(param_1 + 0x17);
      }
    }
  }
  return uVar2;
}



===== Create1394TransactionForSrb @ 14000ec1c =====

void Create1394TransactionForSrb(longlong *param_1,longlong param_2,undefined8 *param_3)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  uint uVar7;
  longlong *plVar8;
  longlong lVar9;
  undefined7 uVar11;
  undefined *puVar10;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  puVar6 = param_3;
  lVar3 = ExpInterlockedPopEntrySList(param_1 + 0x9c);
  if (lVar3 == 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_q(WPP_GLOBAL_Control[3],0x23,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,param_1);
    }
    *(undefined1 *)(param_2 + 3) = 0x30;
    iVar2 = -0x3fffff66;
    *(undefined4 *)(param_2 + 0x40) = 0xc000009a;
    Sbp2CreateRequestErrorLog(*param_1,0,0x41d,-0x3fffff66);
  }
  else {
    plVar8 = (longlong *)(lVar3 + -0x10);
    uVar11 = (undefined7)((ulonglong)puVar6 >> 8);
    AcquireOrbListLock((longlong)param_1,&local_48,'\x01');
    LOCK();
    plVar1 = param_1 + 0x10;
    lVar9 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + 1;
    UNLOCK();
    *(int *)(lVar3 + 0x130) = (int)lVar9 + 1;
    puVar10 = (undefined *)CONCAT71(uVar11,1);
    ReleaseOrbListLock((longlong)param_1,&local_48,'\x01');
    *(undefined8 *)(lVar3 + 0x128) = 0;
    *(undefined8 *)(lVar3 + 0x98) = 0;
    *(undefined8 *)(lVar3 + 0x120) = 0;
    *(undefined4 *)(lVar3 + 0x10) = 0xadeaffab;
    *(longlong *)(lVar3 + 0x20) = param_2;
    *(longlong *)(lVar3 + 0x18) = *param_1;
    *param_3 = plVar8;
    *(undefined4 *)(lVar3 + 0x28) = 0;
    uVar4 = Sbp2_SCSI_RBC_Conversion((longlong)plVar8);
    iVar2 = (int)uVar4;
    if (iVar2 != 0x103) {
      *(undefined8 *)(lVar3 + 0x20) = 0;
      FreeAsyncRequestContext((longlong)param_1,(longlong)plVar8);
      if (iVar2 < 0) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_(WPP_GLOBAL_Control[3],0x25,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids);
        }
        *(undefined1 *)(param_2 + 3) = 0x30;
        *(int *)(param_2 + 0x40) = iVar2;
        *(undefined8 *)(*(longlong *)(param_2 + 0x30) + 0x38) = 0;
      }
      else {
        *(undefined1 *)(param_2 + 3) = 1;
        *(ulonglong *)(*(longlong *)(param_2 + 0x30) + 0x38) = (ulonglong)*(uint *)(param_2 + 0x10);
      }
      lVar3 = *(longlong *)(param_2 + 0x30);
      *(int *)(lVar3 + 0x30) = iVar2;
      IofCompleteRequest(lVar3,0);
      uVar7 = *(uint *)((longlong)param_1 + 0x94);
      goto LAB_14000efad;
    }
    if ((*(int *)(param_2 + 0x10) == 0) || (*(int *)(param_2 + 0xc) == 0)) {
      Sbp2InitializeOrb((longlong)param_1,(longlong)plVar8);
      goto LAB_14000ef1a;
    }
    puVar6 = *(undefined8 **)(param_2 + 0x18);
    lVar9 = *(longlong *)(*(longlong *)(param_2 + 0x30) + 8);
    if ((undefined8 *)((ulonglong)*(uint *)(lVar9 + 0x2c) + *(longlong *)(lVar9 + 0x20)) == puVar6)
    {
      *(undefined8 *)(lVar3 + 0x40) = 0;
LAB_14000ee81:
      *(longlong *)(lVar3 + 0x48) = lVar9;
      uVar4 = Sbp2BusMapTransfer(puVar6,plVar8);
      iVar2 = (int)uVar4;
      if (iVar2 < 0) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          puVar10 = &WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids;
          WPP_SF_D(WPP_GLOBAL_Control[3],0x28,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,iVar2
                  );
        }
        if (*(longlong *)(lVar3 + 0x40) != 0) {
          IoFreeMdl();
          *(undefined8 *)(lVar3 + 0x40) = 0;
          goto LAB_14000eef5;
        }
      }
      if (iVar2 == 0x103) {
        return;
      }
      if (iVar2 == 0) {
LAB_14000ef1a:
        Sbp2InsertTailList(param_1,plVar8,puVar10);
        return;
      }
    }
    else {
      lVar5 = IoAllocateMdl(puVar6,*(int *)(param_2 + 0x10),0,0,0);
      *(longlong *)(lVar3 + 0x40) = lVar5;
      if (lVar5 != 0) {
        puVar10 = *(undefined **)(param_2 + 0x18);
        IoBuildPartialMdl(lVar9,lVar5,puVar10,*(undefined4 *)(param_2 + 0x10));
        lVar9 = *(longlong *)(lVar3 + 0x40);
        puVar6 = WPP_GLOBAL_Control;
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          puVar6 = (undefined8 *)WPP_GLOBAL_Control[3];
          puVar10 = &WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids;
          WPP_SF_q(puVar6,0x27,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,lVar9);
        }
        goto LAB_14000ee81;
      }
      iVar2 = -0x3fffff66;
      *(undefined1 *)(param_2 + 3) = 0x30;
      *(undefined4 *)(param_2 + 0x40) = 0xc000009a;
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_(WPP_GLOBAL_Control[3],0x26,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids);
      }
    }
LAB_14000eef5:
    if (plVar8 != (longlong *)0x0) {
      *(undefined8 *)(lVar3 + 0x20) = 0;
      FreeAsyncRequestContext((longlong)param_1,(longlong)plVar8);
    }
  }
  lVar3 = *(longlong *)(param_2 + 0x30);
  *(undefined1 *)(param_2 + 3) = 0x30;
  *(int *)(param_2 + 0x40) = iVar2;
  *(int *)(lVar3 + 0x30) = iVar2;
  *(undefined8 *)(lVar3 + 0x38) = 0;
  IofCompleteRequest(lVar3);
  uVar7 = 0;
LAB_14000efad:
  Sbp2StartNextPacketByKey(*param_1,uVar7);
  IoReleaseRemoveLockEx(param_1 + 3,lVar3,0x20);
  return;
}



===== Sbp2AllocComplete @ 14000f000 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Sbp2AllocComplete(longlong *param_1)

{
  uint uVar1;
  longlong *plVar2;
  code *pcVar3;
  int iVar4;
  longlong lVar5;
  char cVar6;
  ulonglong uVar7;
  longlong local_res8;
  
  lVar5 = param_1[0x26];
  cVar6 = '\0';
  plVar2 = *(longlong **)(param_1[5] + 0x40);
  pcVar3 = (code *)plVar2[0x37];
  local_res8 = lVar5;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
     (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qd(WPP_GLOBAL_Control[3],0x2d,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,param_1,
              (char)param_1[7]);
  }
  uVar1 = *(uint *)(param_1 + 7);
  if ((uVar1 & 4) == 0) {
    if ((uVar1 & 8) != 0) {
      lVar5 = param_1[0x26];
      *(uint *)(param_1 + 7) = uVar1 & 0xfffffff7;
      param_1[0x15] = *(longlong *)(*(longlong *)(lVar5 + 0x10) + 0xe0);
      uVar1 = *(uint *)(*(longlong *)(lVar5 + 0x10) + 0xd0);
      uVar7 = (ulonglong)uVar1;
      *(uint *)((longlong)param_1 + 100) = uVar1;
      DeAllocateIrpAndIrb((longlong)plVar2,lVar5);
      param_1[0x26] = 0;
      Sbp2InitializeOrb((longlong)plVar2,(longlong)param_1);
      Sbp2InsertTailList(plVar2,param_1,uVar7);
    }
  }
  else {
    *(uint *)(param_1 + 7) = uVar1 & 0xfffffffb;
    if (param_1[0x26] == 0) {
      AllocateIrpAndIrb((longlong)plVar2,&local_res8);
      if (local_res8 == 0) {
        return;
      }
      param_1[0x26] = local_res8;
      cVar6 = '\x01';
      lVar5 = local_res8;
    }
    *(uint *)(param_1 + 7) = *(uint *)(param_1 + 7) | 8;
    **(undefined4 **)(lVar5 + 0x10) = 0x11;
    *(undefined4 *)(*(longlong *)(lVar5 + 0x10) + 0x94) = *(undefined4 *)(param_1[6] + 0x10);
    *(undefined4 *)(*(longlong *)(lVar5 + 0x10) + 0xa0) = 0;
    if ((*(uint *)(param_1[6] + 0xc) & 0x40) == 0) {
      *(undefined4 *)(*(longlong *)(lVar5 + 0x10) + 0x9c) = 1;
    }
    else {
      *(undefined4 *)(*(longlong *)(lVar5 + 0x10) + 0x9c) = 2;
    }
    *(undefined4 *)(*(longlong *)(lVar5 + 0x10) + 0x90) = 1;
    *(code **)(*(longlong *)(lVar5 + 0x10) + 0xa8) = Sbp2AllocComplete;
    *(longlong **)(*(longlong *)(lVar5 + 0x10) + 0xb0) = param_1;
    *(undefined2 *)(*(longlong *)(lVar5 + 0x10) + 0xb8) = 0;
    *(undefined4 *)(*(longlong *)(lVar5 + 0x10) + 0xbc) = 0;
    *(undefined8 *)(*(longlong *)(lVar5 + 0x10) + 0xc0) = 0;
    *(undefined8 *)(*(longlong *)(lVar5 + 0x10) + 200) = 0;
    *(undefined4 *)(*(longlong *)(lVar5 + 0x10) + 0xd0) = 0;
    *(longlong **)(*(longlong *)(lVar5 + 0x10) + 0xe8) = plVar2;
    *(longlong *)(*(longlong *)(lVar5 + 0x10) + 0xd8) = param_1[0xd];
    *(longlong *)(*(longlong *)(lVar5 + 0x10) + 0x88) = param_1[0xb];
    *(undefined4 *)(*(longlong *)(lVar5 + 0x10) + 0x98) = 0x8000;
    param_1[0x26] = lVar5;
    iVar4 = (*pcVar3)(plVar2[0x38],*(undefined8 *)(lVar5 + 0x10));
    if (iVar4 != 0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_qd(WPP_GLOBAL_Control[3],0x2e,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,
                  param_1,cVar6);
      }
      DeAllocateIrpAndIrb((longlong)plVar2,lVar5);
      *(uint *)(param_1 + 7) = *(uint *)(param_1 + 7) | 0x10;
      param_1[0x26] = 0;
      param_1[0x15] = 0;
      if (cVar6 == '\0') {
        lVar5 = param_1[6];
        param_1[6] = 0;
        FreeAsyncRequestContext((longlong)plVar2,(longlong)param_1);
        *(undefined1 *)(lVar5 + 3) = 4;
        lVar5 = *(longlong *)(lVar5 + 0x30);
        *(int *)(lVar5 + 0x30) = iVar4;
        *(undefined8 *)(lVar5 + 0x38) = 0;
        IofCompleteRequest(lVar5);
        Sbp2StartNextPacketByKey(*plVar2,0);
        IoReleaseRemoveLockEx(plVar2 + 3,lVar5,0x20);
      }
    }
  }
  return;
}



===== Sbp2BusMapTransfer @ 14000f2f4 =====

undefined8 Sbp2BusMapTransfer(undefined8 param_1,longlong *param_2)

{
  undefined8 uVar1;
  
  *(uint *)(param_2 + 7) = *(uint *)(param_2 + 7) | 4;
  param_2[0x26] = 0;
  Sbp2AllocComplete(param_2);
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
     (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qq(WPP_GLOBAL_Control[3],0x2b,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,param_2,
              (char)param_2[0x15]);
  }
  if ((*(uint *)(param_2 + 7) & 0x10) == 0) {
    uVar1 = 0x103;
  }
  else {
    *(uint *)(param_2 + 7) = *(uint *)(param_2 + 7) & 0xffffffe7;
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_q(WPP_GLOBAL_Control[3],0x2c,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,param_2);
    }
    uVar1 = 0xc000009a;
  }
  return uVar1;
}



===== Sbp2InitializeOrb @ 14000f3b8 =====

void Sbp2InitializeOrb(longlong param_1,longlong param_2)

{
  ushort *puVar1;
  byte bVar2;
  uint uVar3;
  longlong lVar4;
  undefined2 uVar5;
  ushort uVar6;
  uint uVar7;
  ulonglong uVar8;
  size_t _Size;
  
  *(undefined4 *)(*(longlong *)(param_2 + 0x40) + 0x10) = 0;
  if (*(longlong *)(param_2 + 0xa8) == 0) {
    *(undefined4 *)(param_2 + 100) = 0;
    *(undefined8 *)(*(longlong *)(param_2 + 0x40) + 8) = 0xffffffffffffffff;
  }
  else {
    if (*(uint *)(param_2 + 100) < 2) {
      *(undefined8 *)(*(longlong *)(param_2 + 0x40) + 8) = **(undefined8 **)(param_2 + 0x68);
      if ((*(longlong *)(param_1 + 0x1b8) == 0) || (*(longlong *)(param_2 + 0x58) == 0)) {
        *(undefined2 *)(*(longlong *)(param_2 + 0x40) + 10) = *(undefined2 *)(param_1 + 0x19a);
        uVar3 = *(uint *)(*(longlong *)(param_2 + 0x40) + 8);
        *(uint *)(*(longlong *)(param_2 + 0x40) + 8) =
             uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
        uVar3 = *(uint *)(*(longlong *)(param_2 + 0x40) + 0xc);
        *(uint *)(*(longlong *)(param_2 + 0x40) + 0xc) =
             uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
      }
      else {
        *(undefined1 *)(*(longlong *)(param_2 + 0x40) + 8) = *(undefined1 *)(param_1 + 0x19b);
        *(undefined1 *)(*(longlong *)(param_2 + 0x40) + 9) = *(undefined1 *)(param_1 + 0x19a);
      }
      uVar5 = *(undefined2 *)(*(longlong *)(param_2 + 0x30) + 0x10);
    }
    else {
      *(undefined8 *)(*(longlong *)(param_2 + 0x40) + 8) = *(undefined8 *)(param_2 + 0x78);
      uVar3 = *(uint *)(*(longlong *)(param_2 + 0x40) + 8);
      *(uint *)(*(longlong *)(param_2 + 0x40) + 8) =
           uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
      uVar3 = *(uint *)(*(longlong *)(param_2 + 0x40) + 0xc);
      *(uint *)(*(longlong *)(param_2 + 0x40) + 0xc) =
           uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
      if (((*(longlong *)(param_1 + 0x1b8) == 0) || (*(longlong *)(param_2 + 0x58) == 0)) &&
         (uVar8 = 0, *(int *)(param_2 + 100) != 0)) {
        do {
          uVar7 = (int)uVar8 + 1;
          uVar3 = *(uint *)(*(longlong *)(param_2 + 0x68) + uVar8 * 8);
          *(uint *)(*(longlong *)(param_2 + 0x68) + uVar8 * 8) =
               uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
          uVar3 = *(uint *)(*(longlong *)(param_2 + 0x68) + 4 + uVar8 * 8);
          *(uint *)(*(longlong *)(param_2 + 0x68) + 4 + uVar8 * 8) =
               uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
          uVar8 = (ulonglong)uVar7;
        } while (uVar7 < *(uint *)(param_2 + 100));
      }
      puVar1 = (ushort *)(*(longlong *)(param_2 + 0x40) + 0x12);
      *puVar1 = *puVar1 | 8;
      uVar5 = *(undefined2 *)(param_2 + 100);
    }
    *(undefined2 *)(*(longlong *)(param_2 + 0x40) + 0x10) = uVar5;
  }
  **(undefined8 **)(param_2 + 0x40) = 0xffffffffffffffff;
  puVar1 = (ushort *)(*(longlong *)(param_2 + 0x40) + 0x12);
  *puVar1 = *puVar1 | (*(ushort *)(param_1 + 0x1a4) & 7) << 8;
  puVar1 = (ushort *)(*(longlong *)(param_2 + 0x40) + 0x12);
  *puVar1 = *puVar1 | 0x8000;
  if ((*(uint *)(*(longlong *)(param_2 + 0x30) + 0xc) & 0x40) == 0) {
    puVar1 = (ushort *)(*(longlong *)(param_2 + 0x40) + 0x12);
    *puVar1 = *puVar1 & 0xf7ff;
    uVar6 = *(ushort *)(param_1 + 0x1aa);
  }
  else {
    puVar1 = (ushort *)(*(longlong *)(param_2 + 0x40) + 0x12);
    *puVar1 = *puVar1 | 0x800;
    uVar6 = *(ushort *)(param_1 + 0x1a8);
  }
  _Size = 0x10;
  puVar1 = (ushort *)(*(longlong *)(param_2 + 0x40) + 0x12);
  *puVar1 = *puVar1 | uVar6;
  bVar2 = *(byte *)(*(longlong *)(param_2 + 0x30) + 10);
  if (bVar2 < 0x11) {
    _Size = (size_t)bVar2;
  }
  lVar4 = *(longlong *)(param_2 + 0x40);
  *(undefined8 *)(lVar4 + 0x14) = 0;
  *(undefined8 *)(lVar4 + 0x1c) = 0;
  memmove((void *)(*(longlong *)(param_2 + 0x40) + 0x14),
          (void *)(*(longlong *)(param_2 + 0x30) + 0x48),_Size);
  uVar3 = *(uint *)(*(longlong *)(param_2 + 0x40) + 0x10);
  *(uint *)(*(longlong *)(param_2 + 0x40) + 0x10) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  return;
}



===== Sbp2InsertTailList @ 14000f588 =====

void Sbp2InsertTailList(longlong *param_1,longlong *param_2,undefined8 param_3)

{
  longlong *plVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 uVar5;
  code *pcVar6;
  uint uVar7;
  longlong *plVar8;
  undefined8 *puVar9;
  byte bVar10;
  longlong lVar11;
  longlong lVar12;
  undefined8 *puVar13;
  undefined1 *puVar14;
  undefined4 uVar15;
  longlong *plVar16;
  undefined8 uVar17;
  int local_res8;
  undefined8 local_res18;
  undefined1 auStackY_88 [8];
  undefined1 auStackY_80 [24];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  local_48 = 0;
  plVar16 = (longlong *)CONCAT71((int7)((ulonglong)param_3 >> 8),1);
  local_58 = 0;
  uStack_50 = 0;
  lVar4 = *(longlong *)(param_1[10] + 0x40);
  uVar2 = *(uint *)(param_2 + 0x28);
  AcquireOrbListLock((longlong)param_1,&local_58,'\x01');
  puVar14 = auStackY_88;
  plVar1 = param_1 + 0xe;
  *(int *)((longlong)param_1 + 0x94) = *(int *)(param_2[6] + 0x40) + 1;
  if ((longlong *)*plVar1 == plVar1) {
    *(undefined8 *)param_2[8] = 0xffffffffffffffff;
    plVar16 = param_2 + 0x16;
    uVar3 = *(uint *)(param_2[6] + 0x14);
    *(uint *)(param_2 + 7) = *(uint *)(param_2 + 7) | 1;
    KeSetTimer(param_2 + 0x1e,(longlong)(int)uVar3 * -10000000,plVar16);
    puVar9 = (undefined8 *)param_1[0xf];
    if ((longlong *)*puVar9 == plVar1) {
      *param_2 = (longlong)plVar1;
      param_2[1] = (longlong)puVar9;
      *puVar9 = param_2;
      param_1[0xf] = (longlong)param_2;
      local_res18 = param_2[9];
      if ((param_1[0x17] == 0) || ((char)param_1[0x18] == '\0')) {
        ReleaseOrbListLock((longlong)param_1,&local_58,'\x01');
        if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
            (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
          WPP_SF_q(WPP_GLOBAL_Control[3],0x30,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,
                   param_2);
        }
        KeAcquireSpinLockAtDpcLevel(lVar4 + 0xa0);
        local_res8 = Sbp2AccessRegisterEx((longlong)param_1,(uint *)&local_res18,0x404,-1);
        KeReleaseSpinLockFromDpcLevel(lVar4 + 0xa0);
        bVar10 = 0x20;
        plVar16 = &local_res18;
        uVar15 = 0x4f726250;
        plVar8 = param_2;
      }
      else {
        uVar7 = (uint)local_res18;
        local_res18._4_4_ = (uint)((ulonglong)local_res18 >> 0x20);
        lVar11 = 0;
        local_res18 = CONCAT44(local_res18._4_4_ >> 0x18 | (local_res18._4_4_ & 0xff0000) >> 8 |
                               (local_res18._4_4_ & 0xff00) << 8 | local_res18._4_4_ << 0x18,
                               uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 |
                               uVar7 << 0x18);
        *(undefined1 *)(param_1 + 0x18) = 0;
        **(longlong **)(param_1[0x17] + 0x40) = local_res18;
        do {
          *(undefined1 *)(lVar11 + *(longlong *)(param_1[0x17] + 0x40)) = 0;
          lVar11 = lVar11 + 1;
        } while (lVar11 < 2);
        ReleaseOrbListLock((longlong)param_1,&local_58,'\x01');
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_q(WPP_GLOBAL_Control[3],0x2f,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,
                   param_2);
        }
        KeAcquireSpinLockAtDpcLevel(lVar4 + 0xa0);
        local_res8 = Sbp2AccessRegisterEx((longlong)param_1,(uint *)(param_1 + 0x20),0x408,-1);
        KeReleaseSpinLockFromDpcLevel(lVar4 + 0xa0);
        bVar10 = 0x10;
        plVar16 = param_1 + 0x20;
        uVar15 = 0x4472426c;
        plVar8 = (longlong *)0x0;
      }
      Sbp2AddLog((longlong)param_1,bVar10,uVar15,plVar16,plVar8);
      puVar14 = auStackY_88;
      if (local_res8 == -0x3fedff70) {
        AcquireOrbListLock((longlong)param_1,&local_58,'\x01');
        if (((longlong *)*plVar1 == param_2) && (5 < uVar3)) {
          KeCancelTimer(param_2 + 0x1e);
          KeSetTimer(param_2 + 0x1e,0xfffffffffd050f80,param_2 + 0x16);
        }
        ReleaseOrbListLock((longlong)param_1,&local_58,'\x01');
        if (((uVar3 != 0) && ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
            (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
          WPP_SF_q(WPP_GLOBAL_Control[3],0x31,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,
                   param_1);
        }
        *(uint *)((longlong)param_1 + 0x14) = *(uint *)((longlong)param_1 + 0x14) | 0x4000;
        return;
      }
      goto LAB_14000f98f;
    }
LAB_14000f8f7:
    pcVar6 = (code *)swi(0x29);
    puVar9 = (undefined8 *)(*pcVar6)(3);
    puVar14 = auStackY_80;
  }
  else {
    lVar11 = param_2[9];
    *(undefined8 *)param_2[8] = 0xffffffffffffffff;
    local_res18._0_4_ = (uint)lVar11;
    lVar12 = param_1[0x17];
    local_res18._4_4_ = (uint)((ulonglong)lVar11 >> 0x20);
    local_res18 = CONCAT44(local_res18._4_4_ >> 0x18 | (local_res18._4_4_ & 0xff0000) >> 8 |
                           (local_res18._4_4_ & 0xff00) << 8 | local_res18._4_4_ << 0x18,
                           (uint)local_res18 >> 0x18 | ((uint)local_res18 & 0xff0000) >> 8 |
                           ((uint)local_res18 & 0xff00) << 8 | (uint)local_res18 << 0x18);
    if ((lVar12 == 0) || ((char)param_1[0x18] == '\0')) {
      lVar12 = param_1[0xf];
    }
    else {
      *(undefined1 *)(param_1 + 0x18) = 0;
    }
    **(longlong **)(lVar12 + 0x40) = local_res18;
    lVar11 = 0;
    do {
      *(undefined1 *)(lVar11 + *(longlong *)(lVar12 + 0x40)) = 0;
      lVar11 = lVar11 + 1;
    } while (lVar11 < 2);
    puVar9 = (undefined8 *)param_1[0xf];
    if ((longlong *)*puVar9 != plVar1) goto LAB_14000f8f7;
  }
  *param_2 = (longlong)plVar1;
  puVar13 = &local_58;
  param_2[1] = (longlong)puVar9;
  uVar17 = CONCAT71((int7)((ulonglong)plVar16 >> 8),1);
  *puVar9 = param_2;
  param_1[0xf] = (longlong)param_2;
  *(undefined8 *)(puVar14 + -8) = 0x14000f91b;
  ReleaseOrbListLock((longlong)param_1,puVar13,'\x01');
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
     (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    lVar11 = param_1[0x10];
    uVar5 = WPP_GLOBAL_Control[3];
    *(longlong **)(puVar14 + 0x20) = param_2;
    *(undefined8 *)(puVar14 + -8) = 0x14000f950;
    WPP_SF_dq(uVar5,puVar13,uVar17,(int)lVar11,puVar14[0x20]);
  }
  *(undefined8 *)(puVar14 + -8) = 0x14000f95e;
  KeAcquireSpinLockAtDpcLevel(lVar4 + 0xa0);
  *(undefined8 *)(puVar14 + -8) = 0x14000f97c;
  Sbp2AccessRegisterEx((longlong)param_1,(uint *)(param_1 + 0x20),0x408,-1);
  *(undefined8 *)(puVar14 + -8) = 0x14000f98a;
  KeReleaseSpinLockFromDpcLevel(lVar4 + 0xa0);
LAB_14000f98f:
  if (uVar2 < *(uint *)(param_1 + 0xc)) {
    uVar2 = *(uint *)((longlong)param_1 + 0x94);
    lVar4 = *param_1;
    *(undefined8 *)(puVar14 + -8) = 0x14000f9a5;
    Sbp2StartNextPacketByKey(lVar4,uVar2);
  }
  return;
}



===== Sbp2IssueInternalCommand @ 14000f9c4 =====

int Sbp2IssueInternalCommand(longlong *param_1,byte param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined1 uVar3;
  int iVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined2 *_Dst;
  longlong lVar7;
  longlong lVar8;
  undefined2 uVar9;
  undefined7 in_register_00000011;
  int iVar10;
  undefined8 uVar11;
  uint uVar12;
  uint local_res8;
  longlong local_res20;
  longlong local_78;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  
  plVar1 = param_1 + 0xb2;
  local_res8 = 0;
  local_78 = 0;
  local_res20 = 0;
  local_58 = 0;
  iVar10 = -0x3fffff66;
  local_68 = 0;
  uStack_60 = 0;
  uVar3 = KeAcquireSpinLockRaiseToDpc(plVar1);
  plVar2 = param_1 + 0xa0;
  puVar5 = (undefined8 *)ExAllocateFromNPagedLookasideList(plVar2);
  KeReleaseSpinLock(plVar1,CONCAT71(in_register_00000011,uVar3));
  if (puVar5 == (undefined8 *)0x0) {
    if ((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3fffff66;
    }
    if ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return -0x3fffff66;
    }
    if (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2) {
      return -0x3fffff66;
    }
    uVar9 = 0x33;
  }
  else {
    *(undefined4 *)(puVar5 + 4) = 2;
    *puVar5 = param_1;
    puVar5[5] = 0;
    lVar6 = ExAllocatePool2(0x48,0x12,0x32706273);
    if (lVar6 == 0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_q(WPP_GLOBAL_Control[3],0x34,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,param_1
                );
      }
      ExFreeToNPagedLookasideList(param_1 + 0xa0,puVar5);
      return -0x3fffff66;
    }
    _Dst = (undefined2 *)ExAllocatePool2(0x48,0x58,0x32706273);
    if (_Dst == (undefined2 *)0x0) {
      ExFreePool(lVar6);
      uVar3 = KeAcquireSpinLockRaiseToDpc(plVar1);
      ExFreeToNPagedLookasideList(plVar2,puVar5);
      KeReleaseSpinLock(plVar1,uVar3);
      if ((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3fffff66;
      }
      if ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return -0x3fffff66;
      }
      if (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2) {
        return -0x3fffff66;
      }
      uVar9 = 0x35;
    }
    else {
      lVar7 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*param_1 >> 8),
                                     *(undefined1 *)(*param_1 + 0x4c)));
      if (lVar7 != 0) {
        do {
          lVar8 = *(longlong *)(lVar7 + 0xb8);
          *(undefined1 *)(lVar8 + -0x48) = 0xf;
          *(undefined4 *)(lVar8 + -0x30) = 0x1b0011;
          *(undefined2 **)(lVar8 + -0x40) = _Dst;
          memset(_Dst,0,0x58);
          *_Dst = 0x58;
          *(undefined4 *)(_Dst + 6) = 0x48;
          *(undefined4 *)(_Dst + 10) = 0x18;
          _Dst[5] = 0x1206;
          *(longlong *)(_Dst + 0x10) = lVar6;
          if (param_2 == 0x12) {
            *(longlong **)(_Dst + 0xc) = param_1 + 0x22;
            *(undefined4 *)(_Dst + 8) = 0x24;
            *(char *)((longlong)_Dst + 0x49) = *(char *)(param_1[0xb] + 8) << 5;
            *(undefined2 *)((longlong)_Dst + 0x4b) = 0x2400;
            *(undefined1 *)(_Dst + 0x25) = 0;
            *(undefined1 *)((longlong)_Dst + 0x4d) = 0;
            if (local_res8 == 0) {
              local_78 = IoAllocateMdl(param_1 + 0x22,0x24,0,0,0);
              if (local_78 == 0) goto LAB_1400100b9;
              MmBuildMdlForNonPagedPool(local_78);
            }
            lVar8 = local_78;
LAB_14000fdb8:
            *(longlong *)(lVar7 + 8) = lVar8;
          }
          else if (param_2 == 0x1a) {
            *(longlong **)(_Dst + 0xc) = param_1 + 0x31;
            *(undefined4 *)(_Dst + 8) = 0x11;
            *(byte *)((longlong)_Dst + 0x49) = *(byte *)((longlong)_Dst + 0x49) | 8;
            *(undefined1 *)(_Dst + 0x25) = 6;
            *(undefined1 *)(_Dst + 0x26) = 0x11;
            if (local_res8 == 0) {
              local_res20 = IoAllocateMdl(param_1 + 0x31,0x11,0,0,0);
              if (local_res20 == 0) goto LAB_1400100b9;
              MmBuildMdlForNonPagedPool(local_res20);
            }
            lVar8 = local_res20;
            goto LAB_14000fdb8;
          }
          *(byte *)(_Dst + 0x24) = param_2;
          uVar11 = 0;
          *(longlong *)(_Dst + 0x18) = lVar7;
          KeInitializeEvent(puVar5 + 1,0);
          lVar8 = *(longlong *)(lVar7 + 0xb8);
          *(code **)(lVar8 + -0x10) = Sbp2RequestCompletionRoutine;
          *(undefined8 **)(lVar8 + -8) = puVar5;
          *(undefined1 *)(lVar8 + -0x45) = 0xe0;
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_qDq(WPP_GLOBAL_Control[3],0x37,uVar11,param_1,param_2,(char)lVar7);
          }
          iVar4 = IofCallDriver(*param_1);
          iVar10 = *(int *)(lVar7 + 0x30);
          if ((iVar10 < 0) && (iVar4 != 0x103)) {
            if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
                (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
              WPP_SF_qDqDD(WPP_GLOBAL_Control[3],(ulonglong)param_2,uVar11,param_1,param_2,
                           (char)lVar7,(char)iVar10,*(undefined1 *)((longlong)_Dst + 3));
            }
LAB_1400100b9:
            ExFreePool(lVar6);
            ExFreePool(_Dst);
            if (*(longlong *)(lVar7 + 8) != 0) {
              IoFreeMdl();
            }
            IoFreeIrp(lVar7);
            uVar3 = KeAcquireSpinLockRaiseToDpc(plVar1);
            ExFreeToNPagedLookasideList(param_1 + 0xa0,puVar5);
            KeReleaseSpinLock(plVar1,uVar3);
            return iVar10;
          }
          KeWaitForSingleObject(puVar5 + 1,0,0,0,0);
          if ((*(byte *)((longlong)_Dst + 3) & 0x3f) == 1) {
LAB_14000ff15:
            iVar10 = 0;
          }
          else {
            if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              WPP_SF_qDd(WPP_GLOBAL_Control[3],0x39,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids
                         ,param_1,param_2,*(byte *)((longlong)_Dst + 3));
            }
            if ((*(byte *)((longlong)_Dst + 3) & 0x3f) == 0x12) {
              if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                WPP_SF_q(WPP_GLOBAL_Control[3],0x3a,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids
                         ,param_1);
              }
              goto LAB_14000ff15;
            }
            if (((char)*(byte *)((longlong)_Dst + 3) < '\0') && ((*(byte *)(lVar6 + 2) & 0xf) == 5))
            {
              iVar10 = -0x3ffffff0;
            }
            else {
              if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
                  (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
                WPP_SF_qDd(WPP_GLOBAL_Control[3],0x3b,
                           &WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,param_1,param_2,
                           (char)local_res8 + '\x01');
              }
              iVar10 = -0x3fffffff;
            }
            local_res8 = local_res8 + 1;
            if (((*(uint *)((longlong)param_1 + 0x14) & 0x3200) != 0) && (local_res8 < 5)) {
              if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
                  (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
                WPP_SF_q(WPP_GLOBAL_Control[3],0x3c,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids
                         ,param_1);
              }
              uVar12 = 0;
              do {
                KeInitializeEvent(&local_68,0,0);
                KeWaitForSingleObject(&local_68);
                if ((*(uint *)((longlong)param_1 + 0x14) & 0x2000) == 0) break;
                uVar12 = uVar12 + 1;
              } while (uVar12 < 6);
            }
          }
          if ((2 < local_res8) || (iVar10 == 0)) goto LAB_1400100b9;
        } while( true );
      }
      ExFreePool(lVar6);
      ExFreePool(_Dst);
      uVar3 = KeAcquireSpinLockRaiseToDpc(plVar1);
      ExFreeToNPagedLookasideList(plVar2,puVar5);
      KeReleaseSpinLock(plVar1,uVar3);
      if ((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3fffff66;
      }
      if ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return -0x3fffff66;
      }
      if (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2) {
        return -0x3fffff66;
      }
      uVar9 = 0x36;
    }
  }
  WPP_SF_q(WPP_GLOBAL_Control[3],uVar9,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,param_1);
  return -0x3fffff66;
}



===== Sbp2ScsiPassThroughCompletion @ 140010150 =====

void Sbp2ScsiPassThroughCompletion(undefined8 param_1)

{
  IofCompleteRequest(param_1,0);
  return;
}



===== Sbp2ScsiRequests @ 140010170 =====

int Sbp2ScsiRequests(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  char cVar4;
  uint uVar5;
  longlong *plVar6;
  longlong lVar7;
  undefined3 uVar8;
  undefined1 uVar9;
  int iVar10;
  int iVar11;
  undefined1 uVar12;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  plVar6 = *(longlong **)(param_1 + 0x40);
  lVar7 = param_2[0x17];
  plVar1 = plVar6 + 3;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  iVar10 = IoAcquireRemoveLockEx(plVar1,param_2,"",1,0x20);
  lVar7 = *(longlong *)(lVar7 + 8);
  iVar11 = 0;
  if (iVar10 < 0) {
    *(undefined1 *)(lVar7 + 3) = 0x30;
    *(int *)(lVar7 + 0x40) = iVar10;
    *(int *)(param_2 + 6) = iVar10;
    param_2[7] = 0;
  }
  else {
    Sbp2AddLog((longlong)plVar6,0x40,0x53637369,param_2,(ulonglong)*(byte *)(lVar7 + 2));
    cVar4 = *(char *)(lVar7 + 2);
    if (cVar4 != '\0') {
      if (cVar4 == '\x01') {
        uVar9 = KeAcquireSpinLockRaiseToDpc(plVar6 + 0xb5);
        if ((*(uint *)((longlong)plVar6 + 0x14) & 0x20) == 0) {
          *(uint *)((longlong)plVar6 + 0x14) = *(uint *)((longlong)plVar6 + 0x14) | 0x20;
          uVar12 = 1;
          *(longlong *)(lVar7 + 0x18) = param_1;
        }
        else {
          iVar11 = -0x7fffffef;
          *(undefined4 *)(lVar7 + 0x40) = 0x80000011;
          uVar12 = 0x30;
        }
        *(undefined1 *)(lVar7 + 3) = uVar12;
        KeReleaseSpinLock(plVar6 + 0xb5,uVar9);
      }
      else if (cVar4 == '\x06') {
        uVar9 = KeAcquireSpinLockRaiseToDpc(plVar6 + 0xb5);
        *(uint *)((longlong)plVar6 + 0x14) = *(uint *)((longlong)plVar6 + 0x14) & 0xffffffdf;
        KeReleaseSpinLock(plVar6 + 0xb5,uVar9);
        iVar11 = 0;
        *(undefined1 *)(lVar7 + 3) = 1;
      }
      else {
        if (cVar4 != '\b') {
          if (cVar4 == '\x12') {
            iVar11 = Sbp2Issue1394BusReset(plVar6);
            if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              WPP_SF_q(WPP_GLOBAL_Control[3],0xe,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,
                       plVar6);
            }
            if (iVar11 < 0) {
              *(int *)(lVar7 + 0x40) = iVar11;
              uVar9 = 0x30;
            }
            else {
              uVar9 = 1;
            }
            *(undefined1 *)(lVar7 + 3) = uVar9;
            goto LAB_1400106d7;
          }
          if (cVar4 != '\x15') {
            if (cVar4 == '\x18') {
              plVar2 = plVar6 + 0xb5;
              uVar9 = KeAcquireSpinLockRaiseToDpc(plVar2);
              uVar5 = *(uint *)((longlong)plVar6 + 0x14);
              uVar8 = (undefined3)(uVar5 >> 8);
              if ((uVar5 & 0x40008) == 0) {
                *(uint *)((longlong)plVar6 + 0x14) = uVar5 | 0x40;
                KeReleaseSpinLock(plVar2,CONCAT31(uVar8,uVar9));
                iVar11 = 0;
                *(undefined1 *)(lVar7 + 3) = 1;
                if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 9 & 1) != 0)) &&
                   (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                  WPP_SF_q(WPP_GLOBAL_Control[3],0xf,
                           &WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,plVar6);
                }
              }
              else {
                KeReleaseSpinLock(plVar2,CONCAT31(uVar8,uVar9));
                iVar11 = -0x3fffff40;
                *(undefined1 *)(lVar7 + 3) = 0x30;
                *(undefined4 *)(lVar7 + 0x40) = 0xc00000c0;
              }
            }
            else if (cVar4 == '\x19') {
              if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 9 & 1) != 0)) &&
                 (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                WPP_SF_q(WPP_GLOBAL_Control[3],0x10,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids
                         ,plVar6);
              }
              plVar2 = plVar6 + 0xb5;
              uVar9 = KeAcquireSpinLockRaiseToDpc(plVar2);
              *(uint *)((longlong)plVar6 + 0x14) = *(uint *)((longlong)plVar6 + 0x14) & 0xffffffbf;
              KeReleaseSpinLock(plVar2,uVar9);
              LOCK();
              plVar3 = (longlong *)plVar6[0x1a];
              plVar6[0x1a] = 0;
              UNLOCK();
              if (plVar3 != (longlong *)0x0) {
                if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 9 & 1) != 0)) &&
                   (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                  WPP_SF_qq(WPP_GLOBAL_Control[3],0x11,
                            &WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,plVar6,(char)plVar3);
                }
                Sbp2StartPacket(param_1,plVar3,(uint *)0x0);
              }
              if (*(int *)((longlong)plVar6 + 0xc4) == 1) {
                uVar9 = KfRaiseIrql(2);
                Sbp2StartNextPacketByKey(param_1,*(uint *)((longlong)plVar6 + 0x94));
                KeLowerIrql(uVar9);
              }
              if ((*(uint *)((longlong)plVar6 + 0x14) & 0x40000) == 0) {
                if (*(int *)((longlong)plVar6 + 0xc4) == 4) {
                  AcquireOrbListLock((longlong)plVar6,&local_48,'\0');
                  if (plVar6[0x17] != 0) {
                    FreeAsyncRequestContext((longlong)plVar6,plVar6[0x17]);
                    plVar6[0x17] = 0;
                    *(undefined1 *)(plVar6 + 0x18) = 0;
                  }
                  ReleaseOrbListLock((longlong)plVar6,&local_48,'\0');
                  if ((int)plVar6[0x19] != 1) {
                    uVar9 = KeAcquireSpinLockRaiseToDpc(plVar2);
                    *(undefined4 *)((longlong)plVar6 + 0x19c) = 0xffffffff;
                    KeReleaseSpinLock(plVar2,uVar9);
                  }
                  *(undefined1 *)(lVar7 + 3) = 1;
                  *(undefined4 *)(param_2 + 6) = 0;
                  IofCompleteRequest(param_2,0);
                  if ((int)plVar6[0x19] == 1) {
                    uVar9 = KfRaiseIrql(2);
                    Sbp2StartNextPacketByKey(param_1,*(uint *)((longlong)plVar6 + 0x94));
                    KeLowerIrql(uVar9);
                  }
                  IoReleaseRemoveLockEx(plVar6 + 3,param_2,0x20);
                  return 0;
                }
                iVar11 = 0;
                *(undefined1 *)(lVar7 + 3) = 1;
              }
              else {
                iVar11 = -0x3fffff40;
                *(undefined1 *)(lVar7 + 3) = 0x30;
                *(undefined4 *)(lVar7 + 0x40) = 0xc00000c0;
              }
            }
            else {
              iVar11 = -0x3fffff45;
              *(undefined1 *)(lVar7 + 3) = 0x30;
              *(undefined4 *)(lVar7 + 0x40) = 0xc00000bb;
              if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                WPP_SF_qd(WPP_GLOBAL_Control[3],0x13,
                          &WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,plVar6,
                          *(undefined1 *)(lVar7 + 10));
              }
            }
            goto LAB_1400106d7;
          }
        }
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_q(WPP_GLOBAL_Control[3],0xc,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,plVar6
                  );
        }
        if ((*(uint *)((longlong)plVar6 + 0x14) & 8) == 0) {
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_q(WPP_GLOBAL_Control[3],0xd,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,
                     plVar6);
          }
        }
        else {
          CleanupOrbList(plVar6,-0x3ffffdc0);
        }
        *(undefined1 *)(lVar7 + 3) = 1;
      }
LAB_1400106d7:
      *(int *)(param_2 + 6) = iVar11;
      IoReleaseRemoveLockEx(plVar1,param_2,0x20);
      IofCompleteRequest(param_2,0);
      return iVar11;
    }
    plVar2 = plVar6 + 0xb5;
    uVar9 = KeAcquireSpinLockRaiseToDpc();
    if ((*(uint *)((longlong)plVar6 + 0x14) & 0x140004) == 0) {
      if ((((*(uint *)(plVar6[0xb] + 0x38) & 0x100) != 0) && (*(char *)(lVar7 + 0x48) == '\0')) &&
         (*(int *)(lVar7 + 0x14) != 0x3c)) {
        *(undefined4 *)(lVar7 + 0x14) = 0x3c;
      }
      if (((*(uint *)(lVar7 + 0xc) & 0x100000) == 0) || (*(int *)((longlong)plVar6 + 0xc4) != 4)) {
        *(byte *)(param_2[0x17] + 3) = *(byte *)(param_2[0x17] + 3) | 1;
        uVar5 = *(uint *)((longlong)plVar6 + 0x14);
        if (((uVar5 & 0x40) == 0) || ((*(uint *)(lVar7 + 0xc) & 0x80000) == 0)) {
          KeReleaseSpinLock(plVar2,uVar9);
          Sbp2StartPacket(param_1,param_2,(uint *)(lVar7 + 0x40));
        }
        else if (((uVar5 >> 0xf & 1) == 0) && ((uVar5 & 0x300) != 0)) {
          KeReleaseSpinLock(plVar2,uVar9);
          Sbp2DeferPendingRequest((longlong)plVar6,(longlong)param_2);
        }
        else if ((uVar5 >> 10 & 1) == 0) {
          KeReleaseSpinLock();
          Sbp2DeferPendingRequest((longlong)plVar6,(longlong)param_2);
          Sbp2SetDeferLoginTimer((longlong)plVar6);
        }
        else {
          KeReleaseSpinLock(plVar2,uVar9);
          uVar9 = KfRaiseIrql(2);
          Sbp2StartIo(param_1,param_2);
          KeLowerIrql(uVar9);
        }
        return 0x103;
      }
      KeReleaseSpinLock(plVar2,uVar9);
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_qq(WPP_GLOBAL_Control[3],0xb,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,plVar6,
                  (char)param_2);
      }
      iVar10 = -0x3fffffff;
      *(undefined4 *)(param_2 + 6) = 0xc0000001;
      *(undefined1 *)(lVar7 + 3) = 0x24;
      IoReleaseRemoveLockEx(plVar1,param_2,0x20);
    }
    else {
      KeReleaseSpinLock(plVar2,uVar9);
      *(undefined1 *)(lVar7 + 3) = 8;
      *(undefined4 *)(lVar7 + 0x40) = 0xc00000c0;
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_qDd(WPP_GLOBAL_Control[3],10,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,plVar6,
                   (char)*(undefined4 *)((longlong)plVar6 + 0x14),0xc0);
      }
      *(undefined4 *)(param_2 + 6) = *(undefined4 *)(lVar7 + 0x40);
      IoReleaseRemoveLockEx(plVar1,param_2,0x20);
      iVar10 = -0x3fffff40;
    }
  }
  IofCompleteRequest(param_2,0);
  return iVar10;
}



===== Sbp2StartIo @ 140010990 =====

longlong * Sbp2StartIo(longlong param_1,longlong *param_2)

{
  uint uVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  code *pcVar6;
  undefined8 *puVar7;
  char cVar8;
  longlong *plVar9;
  undefined7 extraout_var;
  longlong *plVar10;
  undefined7 extraout_var_00;
  byte bVar11;
  undefined2 uVar12;
  undefined1 *puVar13;
  undefined8 uVar14;
  undefined *puVar15;
  undefined8 local_res8;
  undefined1 auStackY_68 [8];
  undefined1 auStackY_60 [24];
  undefined1 uVar16;
  
  plVar2 = *(longlong **)(param_1 + 0x40);
  local_res8 = 0;
  plVar9 = plVar2 + 0xb5;
  lVar3 = *(longlong *)(param_2[0x17] + 8);
  *(undefined4 *)(param_2 + 6) = 0x103;
  *(undefined1 *)(lVar3 + 3) = 0;
  KeAcquireSpinLockAtDpcLevel(plVar9);
  bVar11 = 0x40;
  uVar14 = 0x5374496f;
  Sbp2AddLog((longlong)plVar2,0x40,0x5374496f,param_2,lVar3);
  uVar1 = *(uint *)((longlong)plVar2 + 0x14);
  uVar16 = SUB81(param_2,0);
  if ((uVar1 & 0x860404) == 0x20000) {
    if (((bVar11 & (byte)uVar1) != 0) && ((*(uint *)(lVar3 + 0xc) & 0x80000) != 0)) {
      LOCK();
      lVar3 = plVar2[0x1b];
      plVar2[0x1b] = (longlong)param_2;
      UNLOCK();
      if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
          (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
        WPP_SF_qqq(WPP_GLOBAL_Control[3],0x14,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,
                   plVar2,uVar16,(char)lVar3);
      }
      if ((*(uint *)((longlong)plVar2 + 0x14) & 0x1300) == 0) {
        Sbp2SetDeferLoginTimer((longlong)plVar2);
      }
      plVar9 = (longlong *)KeReleaseSpinLockFromDpcLevel(plVar9);
      return plVar9;
    }
    cVar8 = Sbp2InsertByKeyDeviceQueue(param_1 + 0xa0,param_2 + 0xf,*(uint *)(lVar3 + 0x40));
    if ((cVar8 != '\0') ||
       (cVar8 = Sbp2InsertByKeyDeviceQueue(param_1 + 0xa0,param_2 + 0xf,*(uint *)(lVar3 + 0x40)),
       cVar8 != '\0')) {
      plVar9 = (longlong *)KeReleaseSpinLockFromDpcLevel(plVar9);
      if ((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return plVar9;
      }
      uVar1 = *(uint *)((longlong)WPP_GLOBAL_Control + 0x2c);
      if ((uVar1 & 1) == 0) {
        return (longlong *)(ulonglong)uVar1;
      }
      if (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 4) {
        return (longlong *)(ulonglong)uVar1;
      }
      uVar12 = 0x15;
LAB_140010b4a:
      plVar9 = (longlong *)
               WPP_SF_qq(WPP_GLOBAL_Control[3],uVar12,
                         &WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,plVar2,uVar16);
      return plVar9;
    }
    KeReleaseSpinLockFromDpcLevel(plVar9);
    if ((((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
       (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2)) goto LAB_140010c87;
    uVar12 = 0x16;
  }
  else {
    if ((uVar1 & 0x940004) != 0) {
      KeReleaseSpinLockFromDpcLevel(plVar9);
      *(undefined1 *)(lVar3 + 3) = 8;
      *(undefined4 *)(param_2 + 6) = 0xc00000c0;
      IofCompleteRequest(param_2);
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_qqD(WPP_GLOBAL_Control[3],0x17,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,
                   plVar2,uVar16,(char)*(undefined4 *)((longlong)plVar2 + 0x14));
      }
      goto LAB_140010be2;
    }
    if ((bVar11 & (byte)uVar1) == 0) {
      KeReleaseSpinLockFromDpcLevel(plVar9);
      if ((*(int *)((longlong)plVar2 + 0xc4) == 4) && ((int)plVar2[0x19] == 1)) {
        puVar15 = (undefined *)(ulonglong)*(uint *)(lVar3 + 0x40);
        cVar8 = Sbp2InsertByKeyDeviceQueue(param_1 + 0xa0,param_2 + 0xf,*(uint *)(lVar3 + 0x40));
        if (cVar8 == '\0') {
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
             (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            puVar15 = &WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids;
            WPP_SF_qq(WPP_GLOBAL_Control[3],0x1a,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,
                      plVar2,uVar16);
          }
          LOCK();
          plVar2[0x1a] = (longlong)param_2;
          UNLOCK();
        }
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_qDq(WPP_GLOBAL_Control[3],0x1b,puVar15,plVar2,cVar8,uVar16);
        }
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_qd(WPP_GLOBAL_Control[3],0x1c,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,
                    plVar2,0);
        }
        plVar9 = (longlong *)PoRequestPowerIrp(*plVar2,2,1);
        if (-1 < (int)plVar9) {
          return plVar9;
        }
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_qd(WPP_GLOBAL_Control[3],0x1d,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,
                    plVar2,(char)plVar9);
        }
        if (cVar8 == '\0') {
          LOCK();
          plVar9 = (longlong *)plVar2[0x1a];
          if (param_2 == plVar9) {
            plVar2[0x1a] = 0;
            plVar10 = param_2;
          }
          else {
            plVar10 = plVar9;
          }
          UNLOCK();
          if (param_2 != plVar9) {
            param_2 = (longlong *)0x0;
          }
LAB_140010f04:
          puVar13 = auStackY_68;
          if (param_2 != (longlong *)0x0) {
            *(undefined1 *)(lVar3 + 3) = 4;
            *(undefined4 *)(param_2 + 6) = 0xc0000001;
            IofCompleteRequest(param_2);
LAB_140010be2:
            Sbp2StartNextPacketByKey(param_1,0);
            plVar9 = (longlong *)IoReleaseRemoveLockEx(plVar2 + 3,param_2,0x20);
            return plVar9;
          }
        }
        else {
          plVar9 = (longlong *)0x0;
          KeAcquireSpinLockAtDpcLevel(param_1 + 0xb8);
          puVar4 = *(undefined8 **)(param_1 + 0xa8);
          do {
            puVar7 = puVar4;
            if (puVar7 == (undefined8 *)(param_1 + 0xa8)) goto LAB_140010ef0;
            puVar4 = (undefined8 *)*puVar7;
            plVar9 = puVar7 + -0xf;
          } while (plVar9 != param_2);
          if (((undefined8 *)puVar4[1] == puVar7) &&
             (puVar5 = (undefined8 *)puVar7[1], (undefined8 *)*puVar5 == puVar7)) {
            *puVar5 = puVar4;
            puVar4[1] = puVar5;
LAB_140010ef0:
            plVar10 = (longlong *)KeReleaseSpinLockFromDpcLevel(param_1 + 0xb8);
            puVar13 = auStackY_68;
            if (plVar9 == param_2) goto LAB_140010f04;
          }
          else {
            pcVar6 = (code *)swi(0x29);
            plVar10 = (longlong *)(*pcVar6)(3);
            puVar13 = auStackY_60;
          }
        }
        if ((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return plVar10;
        }
        uVar1 = *(uint *)((longlong)WPP_GLOBAL_Control + 0x2c);
        if ((uVar1 & 1) == 0) {
          return (longlong *)(ulonglong)uVar1;
        }
        if (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2) {
          return (longlong *)(ulonglong)uVar1;
        }
        uVar12 = 0x1e;
        param_2 = plVar2;
LAB_140010f76:
        uVar14 = WPP_GLOBAL_Control[3];
        *(undefined8 *)(puVar13 + -8) = 0x140010f86;
        plVar9 = (longlong *)
                 WPP_SF_q(uVar14,uVar12,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,param_2);
        return plVar9;
      }
      if ((*(uint *)((longlong)plVar2 + 0x14) >> 0xd & 1) == 0) {
        if (((*(int *)((longlong)plVar2 + 0xc4) == 1) || ((int)plVar2[0x19] == 1)) &&
           ((*(uint *)((longlong)plVar2 + 0x14) >> 0x10 & 1) == 0)) goto LAB_140010cff;
        cVar8 = Sbp2InsertByKeyDeviceQueue(param_1 + 0xa0,param_2 + 0xf,*(uint *)(lVar3 + 0x40));
        puVar13 = auStackY_68;
        if (cVar8 == '\0') {
          LOCK();
          plVar9 = (longlong *)plVar2[0x1a];
          plVar2[0x1a] = (longlong)param_2;
          UNLOCK();
          if ((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return plVar9;
          }
          uVar1 = *(uint *)((longlong)WPP_GLOBAL_Control + 0x2c);
          if ((uVar1 & 4) == 0) {
            return (longlong *)(ulonglong)uVar1;
          }
          if (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 4) {
            return (longlong *)(ulonglong)uVar1;
          }
          uVar12 = 0x21;
        }
        else {
          if ((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return (longlong *)CONCAT71(extraout_var_00,cVar8);
          }
          uVar1 = *(uint *)((longlong)WPP_GLOBAL_Control + 0x2c);
          if ((uVar1 & 0x20) == 0) {
            return (longlong *)(ulonglong)uVar1;
          }
          if (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 4) {
            return (longlong *)(ulonglong)uVar1;
          }
          uVar12 = 0x22;
        }
        goto LAB_140010f76;
      }
      KeAcquireSpinLockAtDpcLevel(plVar9);
      cVar8 = Sbp2InsertByKeyDeviceQueue(param_1 + 0xa0,param_2 + 0xf,*(uint *)(lVar3 + 0x40));
      if ((cVar8 != '\0') ||
         (cVar8 = Sbp2InsertByKeyDeviceQueue(param_1 + 0xa0,param_2 + 0xf,*(uint *)(lVar3 + 0x40)),
         cVar8 != '\0')) {
        plVar9 = (longlong *)KeReleaseSpinLockFromDpcLevel(plVar9);
        if ((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return plVar9;
        }
        uVar1 = *(uint *)((longlong)WPP_GLOBAL_Control + 0x2c);
        if ((uVar1 & 0x20) == 0) {
          return (longlong *)(ulonglong)uVar1;
        }
        if (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 4) {
          return (longlong *)(ulonglong)uVar1;
        }
        uVar12 = 0x1f;
        goto LAB_140010b4a;
      }
      KeReleaseSpinLockFromDpcLevel(plVar9);
      if ((((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x20) == 0)) ||
         (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2)) goto LAB_140010c87;
      uVar12 = 0x20;
    }
    else {
      KeReleaseSpinLockFromDpcLevel();
      uVar1 = *(uint *)(lVar3 + 0xc);
      if ((uVar1 >> 0x13 & 1) != 0) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_qqqDD(WPP_GLOBAL_Control[3],(ulonglong)uVar1,uVar14,param_1,uVar16,(char)lVar3,
                       (char)uVar1,(char)*(undefined4 *)((longlong)plVar2 + 0x14));
        }
LAB_140010cff:
        if (((*(uint *)(lVar3 + 0xc) & 0x100000) == 0) &&
           ((undefined4 *)plVar2[0x1f] != (undefined4 *)0x0)) {
          *(undefined4 *)plVar2[0x1f] = 0;
        }
        plVar9 = (longlong *)Create1394TransactionForSrb(plVar2,lVar3,&local_res8);
        return plVar9;
      }
      cVar8 = Sbp2InsertByKeyDeviceQueue(param_1 + 0xa0,param_2 + 0xf,*(uint *)(lVar3 + 0x40));
      if (cVar8 != '\0') {
        return (longlong *)CONCAT71(extraout_var,cVar8);
      }
      if ((((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x20) == 0)) ||
         (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 4)) goto LAB_140010c87;
      uVar12 = 0x18;
    }
  }
  WPP_SF_qq(WPP_GLOBAL_Control[3],uVar12,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,plVar2,
            uVar16);
LAB_140010c87:
  *(undefined1 *)(lVar3 + 3) = 5;
  *(undefined4 *)(param_2 + 6) = 0x80000011;
  IoReleaseRemoveLockEx(plVar2 + 3,param_2,0x20);
  plVar9 = (longlong *)IofCompleteRequest(param_2,0);
  return plVar9;
}



===== Sbp2_SCSI_RBC_Conversion @ 140011110 =====

undefined8 Sbp2_SCSI_RBC_Conversion(longlong param_1)

{
  byte *pbVar1;
  longlong lVar2;
  byte bVar3;
  uint uVar4;
  undefined8 uVar5;
  char cVar6;
  longlong lVar7;
  byte bVar8;
  
  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x40);
  if ((*(uint *)(param_1 + 0x38) & 2) != 0) {
    Sbp2AddLog(lVar7,0x80,0x43646249,(ulonglong)*(byte *)(*(longlong *)(param_1 + 0x30) + 10),
               *(longlong *)(param_1 + 0x30) + 0x48);
    if ((*(byte *)(lVar7 + 0x110) & 0x1f) != 0xe) {
      return 0x103;
    }
    bVar3 = *(byte *)(lVar7 + 0x111);
    cVar6 = '\0';
    bVar8 = 0;
    goto LAB_140011172;
  }
  lVar2 = *(longlong *)(param_1 + 0x30);
  bVar3 = *(byte *)(lVar2 + 10);
  if (*(uint *)(*(longlong *)(lVar7 + 0x58) + 0x3c) < (uint)bVar3) {
    if ((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000001;
    }
    if ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return 0xc0000001;
    }
    if (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2) {
      return 0xc0000001;
    }
    WPP_SF_DD(WPP_GLOBAL_Control[3],0x29,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,
              (uint)bVar3,*(undefined1 *)(lVar2 + 0x48));
    return 0xc0000001;
  }
  Sbp2AddLog(lVar7,0x80,0x4364624f,(ulonglong)bVar3,lVar2 + 0x48);
  lVar2 = *(longlong *)(param_1 + 0x30);
  cVar6 = *(char *)(lVar2 + 0x48);
  if (cVar6 == '\x15') {
    uVar4 = *(uint *)(*(longlong *)(lVar7 + 0x58) + 0x38) & 0x200;
joined_r0x00014001129a:
    if (uVar4 != 0) {
      return 0xc0000001;
    }
  }
  else if (cVar6 == '\x1b') {
    uVar4 = *(uint *)(lVar2 + 0x14);
    if (3 < uVar4) {
      uVar4 = 3;
    }
    *(uint *)(lVar2 + 0x14) = uVar4;
  }
  else if ((((cVar6 == -0x53) && (*(char *)(lVar2 + 0x4a) == 'W')) &&
           (*(char *)(lVar2 + 0x4b) == 'D')) &&
          ((*(char *)(lVar2 + 0x4c) == 'C' && (*(char *)(lVar2 + 0x4d) == '\0')))) {
    uVar4 = *(uint *)(*(longlong *)(lVar7 + 0x58) + 0x38) & 0x400;
    goto joined_r0x00014001129a;
  }
  bVar3 = *(byte *)(lVar7 + 0x110) & 0x1f;
  if (bVar3 != 0xe) {
    if ((bVar3 == 5) && (*(char *)(*(longlong *)(param_1 + 0x30) + 0x48) == 'Z')) {
      pbVar1 = (byte *)(*(longlong *)(param_1 + 0x30) + 0x49);
      *pbVar1 = *pbVar1 | 8;
    }
    return 0x103;
  }
  cVar6 = '\x01';
  bVar3 = *(byte *)(lVar7 + 0x111);
  bVar8 = (byte)(*(uint *)(*(longlong *)(lVar7 + 0x58) + 0x38) >> 7) & 1;
LAB_140011172:
  uVar5 = Rbc_Scsi_Conversion(*(longlong *)(param_1 + 0x30),(longlong *)(param_1 + 0x138),
                              (undefined8 *)(lVar7 + 0x188),cVar6,bVar3 >> 7,bVar8);
  return uVar5;
}



===== WPP_SF_dq @ 1400112c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,0x32,local_res20,4,
             &param_5,8,0);
  return;
}



===== WPP_SF_qDq @ 140011324 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,param_2,&local_res20,8,
             &param_5,4,&param_6,8,0);
  return;
}



===== WPP_SF_qDqDD @ 14001138c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDqDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,0x38,&local_res20,8,
             &param_5,4,&param_6,8,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_SF_qqqDD @ 140011414 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqqDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,0x19,&local_res20,8,
             &param_5,8,&param_6,8,&param_7,4,&param_8,4,0);
  return;
}



===== Sbp2FdoDevicePowerCompletion @ 1400114a0 =====

undefined4 Sbp2FdoDevicePowerCompletion(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qqD(WPP_GLOBAL_Control[3],0x1b,&WPP_ec2105b98f943c8733d777e9929c49d0_Traceguids,lVar1,
               (char)param_2,(char)*(undefined4 *)(param_2 + 0x30));
  }
  if (*(int *)(param_2 + 0x30) < 0) {
    PoStartNextPowerIrp(param_2);
    uVar2 = *(undefined4 *)(param_2 + 0x30);
  }
  else {
    uVar2 = *(undefined4 *)(*(longlong *)(param_2 + 0xb8) + 0x18);
    if (*(int *)(lVar1 + 0x50) == 1) {
      Sbp2SetPowerState(param_1,1,uVar2);
    }
    *(undefined4 *)(lVar1 + 0x50) = uVar2;
    PoStartNextPowerIrp(param_2);
    IofCompleteRequest(param_2,0);
    uVar2 = 0xc0000016;
  }
  return uVar2;
}



===== Sbp2FdoSetPower @ 140011580 =====

undefined4 Sbp2FdoSetPower(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  undefined4 uVar6;
  char *pcVar7;
  undefined8 *puVar8;
  code *pcVar9;
  uint uVar10;
  char *pcVar11;
  char *pcVar12;
  undefined1 uVar13;
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  lVar4 = *(longlong *)(param_1 + 0x40);
  iVar2 = *(int *)(lVar3 + 0x10);
  pcVar11 = "D";
  pcVar12 = "S";
  uVar13 = (undefined1)param_2;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    pcVar7 = "S";
    if (iVar2 != 0) {
      pcVar7 = "D";
    }
    WPP_SF_qsq(WPP_GLOBAL_Control[3],0x1c,"D",lVar4,pcVar7,uVar13);
  }
  if (iVar2 == 0) {
    iVar5 = *(int *)(lVar3 + 0x18);
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      uVar10 = *(int *)(lVar4 + 0x54) - 1;
      pcVar11 = (char *)(ulonglong)uVar10;
      WPP_SF_qDDq(WPP_GLOBAL_Control[3],0x1d,pcVar11,lVar4,(char)uVar10,(char)iVar5 + -1,uVar13);
    }
    if (*(int *)(lVar4 + 0x54) == iVar5) {
      PoStartNextPowerIrp(param_2);
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      uVar6 = PoCallDriver(*(undefined8 *)(lVar4 + 8),param_2);
      goto LAB_14001188c;
    }
    puVar8 = *(undefined8 **)(param_2 + 0xb8);
    if (*(int *)(lVar4 + 0x54) != 1) {
      pcVar9 = Sbp2FdoSystemPowerCompletion;
LAB_1400117f0:
      puVar8[-9] = *puVar8;
      puVar8[-8] = puVar8[1];
      puVar8[-7] = puVar8[2];
      puVar8[-6] = puVar8[3];
      *(undefined4 *)(puVar8 + -5) = *(undefined4 *)(puVar8 + 4);
      *(undefined4 *)((longlong)puVar8 + -0x24) = *(undefined4 *)((longlong)puVar8 + 0x24);
      *(undefined4 *)(puVar8 + -4) = *(undefined4 *)(puVar8 + 5);
      *(undefined4 *)((longlong)puVar8 + -0x1c) = *(undefined4 *)((longlong)puVar8 + 0x2c);
      puVar8[-3] = puVar8[6];
      *(undefined1 *)((longlong)puVar8 + -0x45) = 0;
      lVar3 = *(longlong *)(param_2 + 0xb8);
      *(code **)(lVar3 + -0x10) = pcVar9;
      *(undefined8 *)(lVar3 + -8) = 0;
      *(undefined1 *)(lVar3 + -0x45) = 0xe0;
      goto LAB_140011845;
    }
    *(byte *)((longlong)puVar8 + 3) = *(byte *)((longlong)puVar8 + 3) | 1;
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qq(WPP_GLOBAL_Control[3],0x1e,&WPP_ec2105b98f943c8733d777e9929c49d0_Traceguids,lVar4,
                uVar13);
    }
    pcVar11 = (char *)0x4;
    iVar5 = PoRequestPowerIrp(param_1,2,4,Sbp2FdoSystemPowerDownCompletion,param_2,0);
    if (iVar5 < 0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        pcVar11 = &WPP_ec2105b98f943c8733d777e9929c49d0_Traceguids;
        WPP_SF_qd(WPP_GLOBAL_Control[3],0x1f,&WPP_ec2105b98f943c8733d777e9929c49d0_Traceguids,lVar4,
                  (char)iVar5);
      }
      *(int *)(param_2 + 0x30) = iVar5;
      PoStartNextPowerIrp(param_2);
      IofCompleteRequest(param_2,0);
    }
  }
  else {
    if (iVar2 != 1) {
      *(undefined8 *)(param_2 + 0x38) = 0;
      uVar6 = 0xc0000002;
      *(undefined4 *)(param_2 + 0x30) = 0xc0000002;
      PoStartNextPowerIrp(param_2);
      IofCompleteRequest(param_2,0);
      goto LAB_14001188c;
    }
    iVar5 = *(int *)(lVar3 + 0x18);
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      uVar10 = *(int *)(lVar4 + 0x50) - 1;
      pcVar11 = (char *)(ulonglong)uVar10;
      WPP_SF_qDDq(WPP_GLOBAL_Control[3],0x20,pcVar11,lVar4,(char)uVar10,(char)iVar5 + -1,uVar13);
    }
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    if (*(int *)(lVar4 + 0x50) != iVar5) {
      puVar8 = *(undefined8 **)(param_2 + 0xb8);
      pcVar9 = Sbp2FdoDevicePowerCompletion;
      goto LAB_1400117f0;
    }
    PoStartNextPowerIrp(param_2);
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
LAB_140011845:
    PoCallDriver(*(undefined8 *)(lVar4 + 8),param_2);
  }
  uVar6 = 0x103;
LAB_14001188c:
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    if (iVar2 != 0) {
      pcVar12 = "D";
    }
    WPP_SF_qsqD(WPP_GLOBAL_Control[3],0x21,pcVar11,*(undefined8 *)(param_1 + 0x40),pcVar12,uVar13,
                (char)uVar6);
  }
  return uVar6;
}



===== Sbp2FdoSystemPowerCompletion @ 140011910 =====

int Sbp2FdoSystemPowerCompletion(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  longlong lVar2;
  int iVar3;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qqD(WPP_GLOBAL_Control[3],0x17,&WPP_ec2105b98f943c8733d777e9929c49d0_Traceguids,lVar2,
               (char)param_2,(char)*(undefined4 *)(param_2 + 0x30));
  }
  iVar3 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  if (*(int *)(param_2 + 0x30) < 0) {
    if ((*(int *)(param_2 + 0x30) == -0x3ffffff2) && (iVar3 == 1)) {
      *(uint *)(lVar2 + 0x14) = *(uint *)(lVar2 + 0x14) | 0x800000;
    }
    iVar3 = *(int *)(param_2 + 0x30);
    PoStartNextPowerIrp(param_2);
  }
  else {
    *(int *)(lVar2 + 0x54) = iVar3;
    Sbp2SetPowerState(param_1,0,iVar3);
    if (iVar3 == 1) {
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_qq(WPP_GLOBAL_Control[3],0x18,&WPP_ec2105b98f943c8733d777e9929c49d0_Traceguids,lVar2,
                  (char)param_2);
      }
      iVar3 = PoRequestPowerIrp(param_1,2,1,Sbp2FdoSystemPowerUpCompletion,param_2,0);
      if (iVar3 < 0) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_qd(WPP_GLOBAL_Control[3],0x19,&WPP_ec2105b98f943c8733d777e9929c49d0_Traceguids,
                    lVar2,(char)iVar3);
        }
        *(int *)(param_2 + 0x30) = iVar3;
        PoStartNextPowerIrp(param_2);
        return iVar3;
      }
    }
    else {
      PoStartNextPowerIrp(param_2);
      IofCompleteRequest(param_2,0);
    }
    iVar3 = -0x3fffffea;
  }
  return iVar3;
}



===== Sbp2FdoSystemPowerDownCompletion @ 140011ad0 =====

void Sbp2FdoSystemPowerDownCompletion
               (longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4,int *param_5
               )

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong lVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qqD(WPP_GLOBAL_Control[3],0x15,&WPP_ec2105b98f943c8733d777e9929c49d0_Traceguids,lVar1,
               (char)param_4,(char)*param_5);
  }
  if (*param_5 < 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qd(WPP_GLOBAL_Control[3],0x16,&WPP_ec2105b98f943c8733d777e9929c49d0_Traceguids,lVar1,
                (char)*param_5);
    }
    *(undefined8 *)(param_4 + 0x38) = 0;
    *(int *)(param_4 + 0x30) = *param_5;
    PoStartNextPowerIrp(param_4);
    IofCompleteRequest(param_4,0);
  }
  else {
    PoStartNextPowerIrp(param_4);
    puVar2 = *(undefined8 **)(param_4 + 0xb8);
    puVar2[-9] = *puVar2;
    puVar2[-8] = puVar2[1];
    puVar2[-7] = puVar2[2];
    puVar2[-6] = puVar2[3];
    *(undefined4 *)(puVar2 + -5) = *(undefined4 *)(puVar2 + 4);
    *(undefined4 *)((longlong)puVar2 + -0x24) = *(undefined4 *)((longlong)puVar2 + 0x24);
    *(undefined4 *)(puVar2 + -4) = *(undefined4 *)(puVar2 + 5);
    *(undefined4 *)((longlong)puVar2 + -0x1c) = *(undefined4 *)((longlong)puVar2 + 0x2c);
    puVar2[-3] = puVar2[6];
    *(undefined1 *)((longlong)puVar2 + -0x45) = 0;
    lVar3 = *(longlong *)(param_4 + 0xb8);
    *(code **)(lVar3 + -0x10) = Sbp2FdoSystemPowerCompletion;
    *(longlong *)(lVar3 + -8) = param_4;
    *(undefined1 *)(lVar3 + -0x45) = 0xe0;
    PoCallDriver(*(undefined8 *)(lVar1 + 8),param_4);
  }
  return;
}



===== Sbp2FdoSystemPowerUpCompletion @ 140011c30 =====

void Sbp2FdoSystemPowerUpCompletion
               (longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
               undefined4 *param_5)

{
  undefined4 uVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qqD(WPP_GLOBAL_Control[3],0x1a,&WPP_ec2105b98f943c8733d777e9929c49d0_Traceguids,lVar2,
               (char)param_4,(char)*param_5);
  }
  if (param_4 != 0) {
    uVar1 = *(undefined4 *)(*(longlong *)(param_4 + 0xb8) + 0x18);
    *(undefined4 *)(lVar2 + 0x54) = uVar1;
    Sbp2SetPowerState(param_1,0,uVar1);
    *(undefined4 *)(param_4 + 0x30) = *param_5;
    PoStartNextPowerIrp(param_4);
    IofCompleteRequest(param_4,0);
  }
  return;
}



===== Sbp2PdoCompleteDevicePowerIrp @ 140011cf4 =====

void Sbp2PdoCompleteDevicePowerIrp(longlong param_1,longlong param_2)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  undefined1 uVar4;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  iVar1 = *(int *)(param_2 + 0x30);
  iVar2 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  *(longlong *)(param_2 + 0x38) = (longlong)iVar2;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qqDD(WPP_GLOBAL_Control[3],0xc,&WPP_ec2105b98f943c8733d777e9929c49d0_Traceguids,lVar3,
                (char)param_2,(char)iVar1,(char)*(undefined4 *)(lVar3 + 0x14));
  }
  if (((*(int *)(lVar3 + 0xc4) != iVar2) && (iVar1 != -0x3ffffff2)) && (*(int *)(lVar3 + 0xc4) != 1)
     ) {
    Sbp2SetPowerState(param_1,1,iVar2);
  }
  *(int *)(lVar3 + 0xc4) = iVar2;
  if (iVar2 == 1) {
    uVar4 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x5a8);
    if ((*(uint *)(*(longlong *)(lVar3 + 0x58) + 0x38) & 0x40) != 0) {
      *(uint *)(lVar3 + 0x14) = *(uint *)(lVar3 + 0x14) & 0xfffdffff;
    }
    KeReleaseSpinLock(lVar3 + 0x5a8,
                      CONCAT71((int7)((ulonglong)*(longlong *)(lVar3 + 0x58) >> 8),uVar4));
  }
  PoStartNextPowerIrp(param_2);
  IofCompleteRequest(param_2,0);
  IoReleaseRemoveLockEx(lVar3 + 0x18,param_2,0x20);
  return;
}



===== Sbp2PdoCompletePowerIrp @ 140011e38 =====

void Sbp2PdoCompletePowerIrp(longlong param_1,longlong param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  if (iVar1 == 0) {
    Sbp2PdoCompleteSystemPowerIrp(param_1,param_2);
  }
  else if (iVar1 == 1) {
    Sbp2PdoCompleteDevicePowerIrp(param_1,param_2);
  }
  else {
    PoStartNextPowerIrp(param_2);
    IofCompleteRequest(param_2,0);
  }
  return;
}



===== Sbp2PdoCompleteSystemPowerIrp @ 140011e98 =====

void Sbp2PdoCompleteSystemPowerIrp(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  iVar1 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  *(longlong *)(param_2 + 0x38) = (longlong)iVar1;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qqD(WPP_GLOBAL_Control[3],0xb,&WPP_ec2105b98f943c8733d777e9929c49d0_Traceguids,lVar2,
               (char)param_2,(char)*(undefined4 *)(param_2 + 0x30));
  }
  if (*(int *)(lVar2 + 200) != iVar1) {
    *(int *)(lVar2 + 200) = iVar1;
    Sbp2SetPowerState(param_1,0,iVar1);
  }
  PoStartNextPowerIrp(param_2);
  IofCompleteRequest(param_2,0);
  IoReleaseRemoveLockEx(lVar2 + 0x18,param_2,0x20);
  return;
}



===== Sbp2PdoSetPower @ 140011f78 =====

undefined8 Sbp2PdoSetPower(longlong param_1,longlong param_2,undefined8 param_3)

{
  byte *pbVar1;
  longlong *plVar2;
  int iVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined1 uVar6;
  int iVar7;
  char *pcVar8;
  ulonglong uVar9;
  int iVar10;
  uint uVar11;
  undefined1 uVar12;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  lVar4 = *(longlong *)(param_2 + 0xb8);
  plVar5 = *(longlong **)(param_1 + 0x40);
  iVar3 = *(int *)(lVar4 + 0x10);
  iVar10 = 0;
  iVar7 = 0;
  uVar12 = (undefined1)param_2;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    pcVar8 = "S";
    if (iVar3 != 0) {
      pcVar8 = "D";
    }
    WPP_SF_qsq(WPP_GLOBAL_Control[3],0xd,param_3,plVar5,pcVar8,uVar12);
  }
  pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
  if (iVar3 == 0) {
    iVar3 = *(int *)(lVar4 + 0x18);
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      uVar11 = (int)plVar5[0x19] - 1;
      WPP_SF_qDDq(WPP_GLOBAL_Control[3],0xe,(ulonglong)uVar11,plVar5,(char)uVar11,(char)iVar3 + -1,
                  uVar12);
    }
    Sbp2AddLog((longlong)plVar5,2,0x50435473,(longlong)(int)plVar5[0x19],(longlong)iVar3);
    if ((int)plVar5[0x19] == iVar3) goto LAB_14001244d;
    if (iVar3 == 1) {
      plVar2 = plVar5 + 0xb5;
      uVar6 = KeAcquireSpinLockRaiseToDpc(plVar2);
      if ((*(uint *)(*(longlong *)(plVar5[10] + 0x40) + 0x14) & 0x800000) == 0) {
        if ((*(uint *)(plVar5[0xb] + 0x38) & 0x40) != 0) {
          *(uint *)((longlong)plVar5 + 0x14) = *(uint *)((longlong)plVar5 + 0x14) | 0x20000;
        }
        KeReleaseSpinLock(plVar2,uVar6);
        PoRequestPowerIrp(param_1,2,1,0,0,0);
        goto LAB_14001244d;
      }
      *(uint *)((longlong)plVar5 + 0x14) = *(uint *)((longlong)plVar5 + 0x14) | 0x800000;
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_q(WPP_GLOBAL_Control[3],0xf,&WPP_ec2105b98f943c8733d777e9929c49d0_Traceguids,plVar5);
      }
      iVar7 = -0x3ffffff2;
      KeReleaseSpinLock(plVar2,uVar6);
    }
    else {
      *(int *)(plVar5 + 0x19) = iVar3;
      Sbp2SetPowerState(param_1,0,iVar3);
      iVar7 = PoRequestPowerIrp(param_1,2,4,Sbp2PdoSystemPowerCompletion,param_2,0);
      if (iVar7 < 0) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_qd(WPP_GLOBAL_Control[3],0x11,&WPP_ec2105b98f943c8733d777e9929c49d0_Traceguids,
                    plVar5,(char)iVar7);
        }
      }
      else {
        iVar7 = 0x103;
      }
      if (iVar7 == 0x103) goto LAB_140012463;
    }
  }
  else {
    if (iVar3 == 1) {
      iVar3 = *(int *)(lVar4 + 0x18);
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
         (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        uVar11 = *(int *)((longlong)plVar5 + 0xc4) - 1;
        WPP_SF_qDDqD(WPP_GLOBAL_Control[3],(ulonglong)(iVar3 - 1U),(ulonglong)uVar11,plVar5,
                     (char)uVar11,(char)(iVar3 - 1U),uVar12,
                     (char)*(undefined4 *)((longlong)plVar5 + 0x14));
      }
      Sbp2AddLog((longlong)plVar5,2,0x50435464,(longlong)*(int *)((longlong)plVar5 + 0xc4),
                 (longlong)iVar3);
      if (*(int *)((longlong)plVar5 + 0xc4) != iVar3) {
        if (*(int *)((longlong)plVar5 + 0xc4) == 1) {
          *(int *)((longlong)plVar5 + 0xc4) = iVar3;
          local_38 = 0;
          local_48 = 0;
          uStack_40 = 0;
          Sbp2SetPowerState(param_1,1,iVar3);
          AcquireOrbListLock((longlong)plVar5,&local_48,'\0');
          if ((longlong *)plVar5[0xe] != plVar5 + 0xe) {
            pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
            *pbVar1 = *pbVar1 | 1;
            LOCK();
            plVar5[0x1c] = param_2;
            UNLOCK();
            ReleaseOrbListLock((longlong)plVar5,&local_48,'\0');
            return 0x103;
          }
          ReleaseOrbListLock((longlong)plVar5,&local_48,'\0');
          plVar2 = plVar5 + 0xb5;
          uVar6 = KeAcquireSpinLockRaiseToDpc(plVar2);
          uVar11 = *(uint *)((longlong)plVar5 + 0x14);
          *(uint *)((longlong)plVar5 + 0x14) = uVar11 | 0x10000;
          if (((uVar11 & 0x400) != 0) && ((*(uint *)(plVar5[0xb] + 0x38) & 0x10) == 0)) {
            *(uint *)((longlong)plVar5 + 0x14) = uVar11 & 0xfffffbff | 0x10000;
            KeReleaseSpinLock(plVar2,CONCAT71((int7)((ulonglong)plVar5[0xb] >> 8),uVar6));
            uVar9 = Sbp2ManagementTransaction(plVar5,7,-1);
            if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0 &&
                (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
              WPP_SF_qd(WPP_GLOBAL_Control[3],0x13,&WPP_ec2105b98f943c8733d777e9929c49d0_Traceguids,
                        plVar5,(char)uVar9);
            }
            goto LAB_140012454;
          }
          KeReleaseSpinLock(plVar2,uVar6);
        }
        else {
          plVar2 = plVar5 + 0xb5;
          uVar6 = KeAcquireSpinLockRaiseToDpc(plVar2);
          uVar11 = *(uint *)((longlong)plVar5 + 0x14);
          *(uint *)((longlong)plVar5 + 0x14) = uVar11 & 0xfffeffff;
          if ((((uVar11 & 1) == 0) && ((uVar11 & 0xc) != 0)) || ((uVar11 & 0x1600) != 0)) {
            KeReleaseSpinLock(plVar2,CONCAT31((int3)((uVar11 & 0xfffeffff) >> 8),uVar6));
            Sbp2StartQueue(plVar5);
          }
          else {
            Sbp2QueueManagementWorkItem(plVar5,4,0xffffffff);
            KeReleaseSpinLock(plVar2,uVar6);
          }
        }
      }
    }
    else {
      iVar10 = -0x3ffffffe;
    }
LAB_14001244d:
    iVar7 = iVar10;
  }
LAB_140012454:
  *(int *)(param_2 + 0x30) = iVar7;
  Sbp2PdoCompletePowerIrp(param_1,param_2);
LAB_140012463:
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qqD(WPP_GLOBAL_Control[3],0x14,&WPP_ec2105b98f943c8733d777e9929c49d0_Traceguids,
               *(undefined8 *)(param_1 + 0x40),uVar12,(char)iVar7);
  }
  return 0x103;
}



===== Sbp2PdoSystemPowerCompletion @ 1400124d0 =====

void Sbp2PdoSystemPowerCompletion
               (longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
               undefined4 *param_5)

{
  *(undefined4 *)(param_4 + 0x30) = *param_5;
  Sbp2PdoCompleteSystemPowerIrp(param_1,param_4);
  return;
}



===== Sbp2PowerControl @ 140012500 =====

ulonglong Sbp2PowerControl(longlong param_1,longlong param_2)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  int iVar7;
  char *pcVar8;
  undefined8 uVar9;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  lVar3 = *(longlong *)(param_1 + 0x40);
  bVar1 = *(byte *)(lVar2 + 1);
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    pcVar8 = "fdo";
    if (*(int *)(lVar3 + 0x10) != 0x4f444673) {
      pcVar8 = "pdo";
    }
    WPP_SF_qsqD(WPP_GLOBAL_Control[3],0x22,pcVar8,lVar3,pcVar8,(char)param_2,bVar1);
  }
  if (*(int *)(lVar3 + 0x10) == 0x4f444673) {
    lVar2 = *(longlong *)(param_1 + 0x40);
    if (bVar1 == 2) {
      uVar5 = Sbp2FdoSetPower(param_1,param_2);
    }
    else {
      PoStartNextPowerIrp(param_2);
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      uVar5 = PoCallDriver(*(undefined8 *)(lVar2 + 8),param_2);
    }
  }
  else if (*(int *)(lVar3 + 0x10) == 0x4f445073) {
    iVar7 = 2;
    Sbp2AddLog(lVar3,2,0x5043543e,(ulonglong)bVar1,param_2);
    uVar4 = IoAcquireRemoveLockEx(lVar3 + 0x18,param_2,"",iVar7 + -1,0x20);
    uVar5 = 0;
    if ((int)uVar4 < 0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_q(WPP_GLOBAL_Control[3],0x23,&WPP_ec2105b98f943c8733d777e9929c49d0_Traceguids,lVar3);
      }
      Sbp2AddLog(lVar3,2,0x50435431,(longlong)(int)uVar4,0);
      *(uint *)(param_2 + 0x30) = uVar4;
      PoStartNextPowerIrp(param_2);
      IofCompleteRequest(param_2,0);
      return (ulonglong)uVar4;
    }
    if ((bVar1 != 0) && (bVar1 != 1)) {
      if (bVar1 == 2) {
        uVar9 = 0x50435432;
        Sbp2AddLog(lVar3,2,0x50435432,(longlong)*(int *)(lVar2 + 0x10),param_2);
        uVar6 = Sbp2PdoSetPower(param_1,param_2,uVar9);
        return uVar6;
      }
      if (bVar1 != 3) {
        uVar5 = *(uint *)(param_2 + 0x30);
      }
    }
    *(uint *)(param_2 + 0x30) = uVar5;
    PoStartNextPowerIrp(param_2);
    IofCompleteRequest(param_2,0);
    IoReleaseRemoveLockEx(lVar3 + 0x18,param_2,0x20);
  }
  else {
    uVar5 = 0xc000000e;
    *(undefined4 *)(param_2 + 0x30) = 0xc000000e;
    PoStartNextPowerIrp(param_2);
    IofCompleteRequest(param_2,0);
  }
  return (ulonglong)uVar5;
}



===== Sbp2RestartPendingPowerIrp @ 140012780 =====

ulonglong Sbp2RestartPendingPowerIrp(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  uint uVar3;
  longlong lVar4;
  undefined1 uVar5;
  uint uVar6;
  ulonglong uVar7;
  byte bVar8;
  ulonglong uVar9;
  
  uVar9 = 0;
  LOCK();
  lVar2 = param_1[0x1c];
  param_1[0x1c] = 0;
  UNLOCK();
  if (lVar2 == 0) {
    return 0;
  }
  bVar8 = 2;
  Sbp2AddLog((longlong)param_1,2,0x50497270,lVar2,0);
  lVar4 = *(longlong *)(lVar2 + 0xb8);
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
     (bVar8 <= *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qd(WPP_GLOBAL_Control[3],0x24,&WPP_ec2105b98f943c8733d777e9929c49d0_Traceguids,param_1,
              (char)*(undefined4 *)(lVar4 + 0x18) + -1);
  }
  if (*(int *)(lVar4 + 0x18) == 4) {
    plVar1 = param_1 + 0xb5;
    uVar5 = KeAcquireSpinLockRaiseToDpc(plVar1);
    uVar6 = *(uint *)((longlong)param_1 + 0x14);
    *(uint *)((longlong)param_1 + 0x14) = uVar6 | 0x10000;
    if ((uVar6 & 0x400) != 0) {
      uVar3 = *(uint *)(param_1[0xb] + 0x38);
      if ((uVar3 & 0x10) == 0) {
        *(uint *)((longlong)param_1 + 0x14) = uVar6 & 0xfffffbff | 0x10000;
        KeReleaseSpinLock(plVar1,CONCAT31((int3)(uVar3 >> 8),uVar5));
        uVar7 = Sbp2ManagementTransaction(param_1,7,-1);
        uVar9 = uVar7 & 0xffffffff;
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_qd(WPP_GLOBAL_Control[3],0x25,&WPP_ec2105b98f943c8733d777e9929c49d0_Traceguids,
                    param_1,(char)uVar7);
        }
        goto LAB_1400128df;
      }
    }
    KeReleaseSpinLock(plVar1,uVar5);
  }
  else if ((*(uint *)((longlong)param_1 + 0x14) & 0x1600) == 0) {
    uVar6 = Sbp2Issue1394BusReset(param_1);
    uVar9 = (ulonglong)uVar6;
  }
LAB_1400128df:
  *(undefined4 *)(lVar2 + 0x30) = 0;
  Sbp2PdoCompletePowerIrp(*param_1,lVar2);
  return uVar9;
}



===== Sbp2SetPowerState @ 140012914 =====

void Sbp2SetPowerState(longlong param_1,int param_2,undefined4 param_3)

{
  char *pcVar1;
  char *pcVar2;
  
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    pcVar2 = "S";
    if (param_2 != 0) {
      pcVar2 = "D";
    }
    pcVar1 = "P";
    if (*(int *)(*(longlong *)(param_1 + 0x40) + 0x10) != 0x4f445073) {
      pcVar1 = "F";
    }
    WPP_SF_qssd(WPP_GLOBAL_Control[3],pcVar1,pcVar2,*(longlong *)(param_1 + 0x40),pcVar1,pcVar2,
                (char)param_3 + -1);
  }
  PoSetPowerState(param_1,param_2,param_3);
  return;
}



===== WPP_SF_qDDq @ 1400129c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDDq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ec2105b98f943c8733d777e9929c49d0_Traceguids,param_2,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,8,0);
  return;
}



===== WPP_SF_qDDqD @ 140012a38 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDDqD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ec2105b98f943c8733d777e9929c49d0_Traceguids,0x12,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,8,&param_8,4,0);
  return;
}



===== WPP_SF_qsq @ 140012ac0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qsq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               char *param_5,undefined1 param_6)

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
            (param_1,0x2b,&WPP_ec2105b98f943c8733d777e9929c49d0_Traceguids,param_2,&local_res20,8,
             param_5,lVar2,&param_6,8,0);
  return;
}



===== WPP_SF_qsqD @ 140012b60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qsqD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                char *param_5,undefined1 param_6,undefined1 param_7)

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
            (param_1,0x2b,&WPP_ec2105b98f943c8733d777e9929c49d0_Traceguids,param_2,&local_res20,8,
             param_5,lVar2,&param_6,8,&param_7,4,0);
  return;
}



===== WPP_SF_qssd @ 140012c14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qssd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                char *param_5,char *param_6,undefined1 param_7)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
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
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  lVar1 = -1;
  if (param_5 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    do {
      lVar3 = lVar1;
      lVar1 = lVar3 + 1;
    } while (param_5[lVar1] != '\0');
    lVar3 = lVar3 + 2;
  }
  if (param_5 == (char *)0x0) {
    param_5 = "NULL";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ec2105b98f943c8733d777e9929c49d0_Traceguids,10,&local_res20,8,param_5
             ,lVar3,param_6,lVar2,&param_7,4,0);
  return;
}



===== Rbc_Scsi_Conversion @ 140012cf4 =====

undefined8
Rbc_Scsi_Conversion(longlong param_1,longlong *param_2,undefined8 *param_3,char param_4,char param_5
                   ,char param_6)

{
  char cVar1;
  longlong lVar2;
  undefined2 *puVar3;
  undefined8 *puVar4;
  byte *pbVar5;
  char *pcVar6;
  longlong lVar7;
  undefined8 uVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  longlong lVar12;
  uint uVar13;
  undefined8 uVar14;
  char *pcVar15;
  char *pcVar16;
  ulonglong in_stack_ffffffffffffffc8;
  
  bVar10 = 0;
  pcVar16 = (char *)0x0;
  uVar14 = 0x103;
  if (param_4 == '\0') {
    lVar7 = *param_2;
    lVar12 = param_1;
    if (lVar7 != 0) {
      lVar12 = lVar7;
    }
    if (*(char *)(param_1 + 3) != '\x01') {
      if (lVar7 != 0) {
        if ((*(char *)(lVar12 + 0x48) == '\x1a') &&
           (*(longlong *)(lVar7 + 0x30) != *(longlong *)(*(longlong *)(param_1 + 0x30) + 8))) {
          IoFreeMdl();
          *(undefined8 *)(*(longlong *)(param_1 + 0x30) + 8) = *(undefined8 *)(*param_2 + 0x30);
          *(undefined8 *)(param_1 + 0x18) = *(undefined8 *)(*param_2 + 0x18);
          *(uint *)(param_1 + 0x10) = (uint)*(byte *)(lVar12 + 0x4c);
        }
        *(undefined1 *)(param_1 + 10) = *(undefined1 *)(*param_2 + 10);
        memmove((void *)(param_1 + 0x48),(void *)(*param_2 + 0x48),
                (ulonglong)*(byte *)(*param_2 + 10));
      }
      return 0xc0000001;
    }
    uVar13 = (uint)(in_stack_ffffffffffffffc8 >> 0x20);
    if (*(char *)(lVar12 + 0x48) == '\x15') {
      if (*(int *)(param_1 + 0x10) == 0x11) {
        lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 8);
        if ((*(byte *)(lVar7 + 10) & 5) == 0) {
          lVar7 = MmMapLockedPagesSpecifyCache(lVar7,0,1,0,(ulonglong)uVar13 << 0x20,0x40000010);
        }
        else {
          lVar7 = *(longlong *)(lVar7 + 0x18);
        }
        if (lVar7 != 0) {
          *(byte *)((longlong)param_3 + 6) =
               (*(byte *)((longlong)param_3 + 6) ^ *(byte *)(lVar7 + 6)) & 1 ^
               *(byte *)((longlong)param_3 + 6);
        }
      }
    }
    else if ((*(char *)(lVar12 + 0x48) == '\x1a') && ((*(byte *)(lVar12 + 0x4a) & 0x3f) != 6)) {
      if (lVar7 == 0) {
        return 0xc0000001;
      }
      lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 8);
      if (lVar2 == *(longlong *)(lVar7 + 0x30)) {
        if ((*(byte *)(lVar2 + 10) & 5) == 0) {
          pcVar6 = (char *)MmMapLockedPagesSpecifyCache
                                     (lVar2,0,1,0,(ulonglong)uVar13 << 0x20,0x40000010);
        }
        else {
          pcVar6 = *(char **)(lVar2 + 0x18);
        }
        if (pcVar6 != (char *)0x0) {
          uVar8 = *(undefined8 *)(pcVar6 + 8);
          *param_3 = *(undefined8 *)pcVar6;
          param_3[1] = uVar8;
          *(char *)(param_3 + 2) = pcVar6[0x10];
        }
      }
      else {
        IoFreeMdl();
        *(undefined8 *)(*(longlong *)(param_1 + 0x30) + 8) = *(undefined8 *)(*param_2 + 0x30);
        *(undefined8 *)(param_1 + 0x18) = *(undefined8 *)(*param_2 + 0x18);
        lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 8);
        if ((*(byte *)(lVar7 + 10) & 5) == 0) {
          pcVar6 = (char *)MmMapLockedPagesSpecifyCache
                                     (lVar7,0,1,0,in_stack_ffffffffffffffc8 & 0xffffffff00000000,
                                      0x40000010);
        }
        else {
          pcVar6 = *(char **)(lVar7 + 0x18);
        }
      }
      bVar10 = *(byte *)(lVar12 + 0x4c);
      uVar13 = (uint)bVar10;
      *(uint *)(param_1 + 0x10) = (uint)bVar10;
      pcVar15 = (char *)0x0;
      if ((*(byte *)(lVar12 + 0x49) & 8) == 0) {
        if (bVar10 < 0xc) {
          return 0x103;
        }
        if (pcVar6 == (char *)0x0) {
          return 0xc000009a;
        }
        pcVar6[3] = '\b';
        pcVar16 = pcVar6 + 4;
        pcVar6[0] = '\v';
        pcVar6[1] = '\0';
        bVar9 = (*(byte *)((longlong)param_3 + 0xf) & 0xfc) << 5;
        pcVar6[2] = bVar9;
        cVar1 = *(char *)((longlong)param_3 + 6);
        *pcVar16 = '\0';
        pcVar6[2] = ~(cVar1 << 4) & 0x10U | bVar9;
        uVar13 = bVar10 - 0xc;
        pcVar6[0xb] = *(char *)(param_3 + 1);
        pcVar6[10] = *(char *)((longlong)param_3 + 7);
        pcVar6[9] = '\0';
        *(undefined2 *)(pcVar6 + 5) = *(undefined2 *)((longlong)param_3 + 0xb);
        pcVar6[7] = *(char *)((longlong)param_3 + 0xd);
        pcVar15 = pcVar6;
      }
      if ((0xb < uVar13) &&
         ((bVar10 = *(byte *)(lVar12 + 0x4a) & 0x3f, bVar10 == 0x3f || (bVar10 == 8)))) {
        if (pcVar15 == (char *)0x0) {
          if (pcVar6 == (char *)0x0) {
            return 0xc000009a;
          }
        }
        else {
          *pcVar15 = *pcVar15 + '\f';
          pcVar6 = pcVar16 + 8;
        }
        pcVar6[0] = '\0';
        pcVar6[1] = '\0';
        pcVar6[2] = '\0';
        pcVar6[3] = '\0';
        pcVar6[4] = '\0';
        pcVar6[5] = '\0';
        pcVar6[6] = '\0';
        pcVar6[7] = '\0';
        pcVar6[8] = '\0';
        pcVar6[9] = '\0';
        pcVar6[10] = '\0';
        pcVar6[0xb] = '\0';
        pcVar6[0] = '\b';
        pcVar6[1] = '\f';
        cVar1 = *(char *)((longlong)param_3 + 6);
        *pcVar6 = -0x78;
        pcVar6[3] = '\0';
        pcVar6[2] = ~(cVar1 << 2) & 4U | pcVar6[2] & 0xf8U;
      }
    }
  }
  else {
    cVar1 = *(char *)(param_1 + 0x48);
    if (cVar1 == '\x15') {
      *(byte *)(param_1 + 0x49) = *(byte *)(param_1 + 0x49) | 0x11;
      if (0x10 < *(uint *)(param_1 + 0x10)) {
        puVar4 = *(undefined8 **)(param_1 + 0x18);
        bVar9 = *(byte *)((longlong)puVar4 + 0xc) & 0x3f;
        if (bVar9 == 8) {
          bVar10 = ~(*(byte *)((longlong)puVar4 + 0xe) >> 2) & 1;
        }
        *(undefined4 *)(param_1 + 0x10) = 0x11;
        *(undefined1 *)(param_1 + 0x4c) = 0x11;
        uVar8 = param_3[1];
        *puVar4 = *param_3;
        puVar4[1] = uVar8;
        *(undefined1 *)(puVar4 + 2) = *(undefined1 *)(param_3 + 2);
        pbVar5 = *(byte **)(param_1 + 0x18);
        if (param_6 == '\0') {
          bVar11 = 0;
        }
        else {
          bVar11 = 0x11;
          if (*pbVar5 < 0x11) {
            bVar11 = *pbVar5;
          }
        }
        *pbVar5 = bVar11;
        pbVar5[2] = 0;
        pbVar5[3] = 0;
        pbVar5[1] = 0;
        if (bVar9 == 8) {
          pbVar5[6] = pbVar5[6] & 0xfe | bVar10;
        }
      }
    }
    else if (cVar1 == '\x1a') {
      if ((*(byte *)(param_1 + 0x4a) & 0x3f) != 6) {
        if ((param_5 == '\0') && (*(int *)(param_1 + 0x10) == 0xc)) {
          puVar3 = *(undefined2 **)(param_1 + 0x18);
          uVar14 = 0;
          *(undefined1 *)((longlong)puVar3 + 3) = 8;
          *puVar3 = 0xb;
          bVar10 = (*(byte *)((longlong)param_3 + 0xf) & 0xfc) << 5;
          *(byte *)(puVar3 + 1) = bVar10;
          cVar1 = *(char *)((longlong)param_3 + 6);
          *(undefined1 *)(puVar3 + 2) = 0;
          *(byte *)(puVar3 + 1) = ~(cVar1 << 4) & 0x10U | bVar10;
          *(undefined1 *)((longlong)puVar3 + 0xb) = *(undefined1 *)(param_3 + 1);
          *(undefined1 *)(puVar3 + 5) = *(undefined1 *)((longlong)param_3 + 7);
          *(undefined1 *)((longlong)puVar3 + 9) = 0;
          *(undefined2 *)((longlong)puVar3 + 5) = *(undefined2 *)((longlong)param_3 + 0xb);
          *(undefined1 *)((longlong)puVar3 + 7) = *(undefined1 *)((longlong)param_3 + 0xd);
        }
        else {
          lVar7 = ExAllocatePool2(0x40,0x58,0x32706273);
          *param_2 = lVar7;
          if (lVar7 == 0) {
            return 0xc000009a;
          }
          *(undefined8 *)(lVar7 + 0x30) = *(undefined8 *)(*(longlong *)(param_1 + 0x30) + 8);
          if (*(uint *)(param_1 + 0x10) < 0x11) {
            uVar8 = IoAllocateMdl(param_3,0x11,0,0,0);
            *(undefined8 *)(*(longlong *)(param_1 + 0x30) + 8) = uVar8;
            if (*(longlong *)(*(longlong *)(param_1 + 0x30) + 8) == 0) {
              *(undefined8 *)(*(longlong *)(param_1 + 0x30) + 8) = *(undefined8 *)(*param_2 + 0x30);
              ExFreePool(*param_2);
              *param_2 = 0;
              return 0xc000009a;
            }
            MmBuildMdlForNonPagedPool();
            *(undefined8 *)(*param_2 + 0x18) = *(undefined8 *)(param_1 + 0x18);
            *(undefined8 **)(param_1 + 0x18) = param_3;
          }
          bVar10 = 0x10;
          if (*(byte *)(param_1 + 10) < 0x10) {
            bVar10 = *(byte *)(param_1 + 10);
          }
          *(byte *)(*param_2 + 10) = bVar10;
          memmove((void *)(*param_2 + 0x48),(void *)(param_1 + 0x48),
                  (ulonglong)*(byte *)(*param_2 + 10));
          *(byte *)(param_1 + 0x49) = *(byte *)(param_1 + 0x49) | 8;
          *(byte *)(param_1 + 0x4a) = *(byte *)(param_1 + 0x4a) & 0xc6 | 6;
          *(undefined4 *)(param_1 + 0x10) = 0x11;
          *(undefined1 *)(param_1 + 0x4c) = 0x11;
        }
      }
    }
    else if (cVar1 == '\x1b') {
      bVar10 = *(byte *)(param_1 + 0x4c);
      *(byte *)(param_1 + 0x4c) = (~bVar10 & 1) * ' ' + 0x10 | bVar10 & 0xf;
      if ((bVar10 & 2) != 0) {
        *(byte *)(param_1 + 0x4c) = bVar10 & 0xf;
      }
    }
  }
  return uVar14;
}



===== PortPassThroughBuildIrpEx @ 14001322c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong PortPassThroughBuildIrpEx
                   (longlong param_1,longlong param_2,undefined4 param_3,char param_4,char param_5,
                   longlong param_6)

{
  bool bVar1;
  bool bVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 auStack_b8 [32];
  undefined8 local_98;
  undefined1 local_88;
  longlong local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_b8;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  bVar2 = false;
  local_88 = 0;
  if ((param_5 == '\x01') && (param_6 != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  lVar3 = IoAllocateIrp(*(undefined1 *)(param_1 + 0x4c),0);
  if (lVar3 != 0) {
    *(void **)(lVar3 + 0x98) = SystemReserved1[0xf];
    *(undefined2 *)(*(longlong *)(lVar3 + 0xb8) + -0x48) = 0x10f;
    if (param_2 == 0) goto LAB_1400133e0;
    local_98 = 0;
    local_80 = lVar3;
    lVar4 = IoAllocateMdl(param_2,param_3,0,0);
    *(longlong *)(lVar3 + 8) = lVar4;
    if (lVar4 != 0) {
      if (((bVar1) && (lVar4 = IoGetRequestorProcess(param_6), lVar4 != 0)) &&
         (lVar5 = IoGetCurrentProcess(), lVar4 != lVar5)) {
        KeStackAttachProcess(lVar4,&local_78);
        bVar2 = true;
        local_88 = 1;
      }
      MmProbeAndLockPages(*(undefined8 *)(lVar3 + 8),param_5,param_4 != '\0');
      if (bVar2) {
        KeUnstackDetachProcess(&local_78);
      }
      goto LAB_1400133e0;
    }
    IoFreeIrp(lVar3);
  }
  lVar3 = 0;
LAB_1400133e0:
  return lVar3;
}



===== PortPassThroughExMarshalResultsFromSrbEx @ 140013408 =====

void PortPassThroughExMarshalResultsFromSrbEx
               (longlong param_1,longlong param_2,char param_3,int *param_4)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  char cVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  int *piVar8;
  void *_Dst;
  ulonglong uVar9;
  byte bVar10;
  byte bVar11;
  ulonglong uVar12;
  int iVar13;
  void *_Src;
  uint uVar14;
  
  lVar2 = *(longlong *)(param_1 + 0x18);
  param_4[2] = 0;
  param_4[3] = 0;
  uVar14 = *(int *)(lVar2 + 8) + 0x3f;
  if (uVar14 < 0x40) {
    iVar5 = -0x3fffff6b;
    goto LAB_1400135fa;
  }
  uVar12 = (ulonglong)uVar14;
  puVar6 = (undefined8 *)ExAllocatePool2(0x40,uVar14,0x69506c50);
  if (puVar6 == (undefined8 *)0x0) {
    iVar5 = -0x3fffff66;
    goto LAB_1400135fa;
  }
  uVar7 = PortPassThroughExNormalize(puVar6,param_1);
  iVar5 = (int)uVar7;
  if (-1 < iVar5) {
    cVar4 = '\0';
    iVar13 = *param_4;
    bVar10 = 0;
    _Src = (void *)0x0;
    uVar14 = *(uint *)(*(longlong *)(param_1 + 0xb8) + 8);
    piVar8 = (int *)((ulonglong)*(uint *)(param_2 + 0x78) + param_2);
    iVar5 = *piVar8;
    if ((iVar5 == 0x40) || (iVar5 == 0x41)) {
      _Src = *(void **)(piVar8 + 4);
LAB_1400134cb:
      cVar4 = (char)piVar8[2];
      bVar10 = *(byte *)((longlong)piVar8 + 9);
    }
    else if (iVar5 == 0x42) {
      _Src = *(void **)(piVar8 + 6);
      goto LAB_1400134cb;
    }
    *(char *)(puVar6 + 2) = cVar4;
    if (*(char *)(param_2 + 3) < '\0') {
      bVar11 = *(byte *)((longlong)puVar6 + 0x11);
      if ((bVar11 != 0) &&
         (_Dst = (void *)((ulonglong)*(uint *)((longlong)puVar6 + 0x1c) +
                         *(longlong *)(param_1 + 0x18)), _Dst != (void *)0x0)) {
        *(byte *)((longlong)puVar6 + 0x11) = bVar10;
        memmove(_Dst,_Src,(ulonglong)bVar10);
        bVar11 = *(byte *)((longlong)puVar6 + 0x11);
      }
      iVar13 = 0;
    }
    else {
      *(undefined1 *)((longlong)puVar6 + 0x11) = 0;
      bVar11 = 0;
    }
    iVar1 = *(int *)(param_2 + 0x3c);
    iVar5 = 0;
    if ((*(byte *)(param_2 + 3) & 0x3f) != 0x12) {
      iVar5 = iVar13;
    }
    if (*(char *)((longlong)puVar6 + 0x12) == '\x01') {
      *(int *)((longlong)puVar6 + 0x24) = iVar1;
    }
    else {
      *(int *)(puVar6 + 4) = iVar1;
      if (((*(char *)((longlong)puVar6 + 0x12) == '\x03') && (iVar1 != 0)) &&
         (*(int *)((longlong)puVar6 + 0x24) != 0)) {
        *(undefined4 *)((longlong)puVar6 + 0x24) =
             *(undefined4 *)((ulonglong)*(uint *)(param_2 + 0x7c) + 8 + param_2);
      }
    }
    if (bVar11 == 0) {
      if ((iVar5 < 0) && (cVar4 != '\0')) {
        iVar5 = 0;
        uVar12 = 8;
      }
    }
    else {
      uVar12 = (ulonglong)(*(int *)((longlong)puVar6 + 0x1c) + (uint)bVar11);
    }
    if ((param_3 == '\0') && (puVar6[6] != 0)) {
      uVar12 = (ulonglong)*(uint *)((longlong)puVar6 + 0x24) + puVar6[6];
    }
    puVar3 = *(undefined8 **)(param_1 + 0x18);
    uVar9 = (ulonglong)uVar14;
    if (uVar9 <= uVar12) {
      uVar12 = uVar9;
    }
    *(ulonglong *)(param_4 + 2) = uVar12;
    cVar4 = IoIs32bitProcess(param_1);
    uVar7 = puVar6[1];
    if (cVar4 == '\0') {
      *puVar3 = *puVar6;
      puVar3[1] = uVar7;
      uVar7 = puVar6[3];
      puVar3[2] = puVar6[2];
      puVar3[3] = uVar7;
      uVar7 = puVar6[5];
      puVar3[4] = puVar6[4];
      puVar3[5] = uVar7;
      uVar7 = puVar6[7];
      puVar3[6] = puVar6[6];
      puVar3[7] = uVar7;
    }
    else {
      puVar3 = *(undefined8 **)(param_1 + 0x18);
      *puVar3 = *puVar6;
      puVar3[1] = uVar7;
      uVar7 = puVar6[3];
      puVar3[2] = puVar6[2];
      puVar3[3] = uVar7;
      puVar3[4] = puVar6[4];
    }
  }
  ExFreePoolWithTag(puVar6,0x69506c50);
LAB_1400135fa:
  *param_4 = iVar5;
  return;
}



===== PortPassThroughExNormalize @ 140013624 =====

undefined8 PortPassThroughExNormalize(undefined8 *param_1,longlong param_2)

{
  void *_Src;
  undefined8 *puVar1;
  undefined8 uVar2;
  char cVar3;
  undefined8 uVar4;
  
  _Src = *(void **)(param_2 + 0x18);
  uVar4 = 0;
  cVar3 = IoIs32bitProcess(param_2);
  puVar1 = *(undefined8 **)(param_2 + 0x18);
  if (cVar3 == '\0') {
    if (*(int *)(puVar1 + 1) + 0x3fU < 0x40) {
      uVar4 = 0xc0000095;
    }
    else {
      memmove(param_1,_Src,(ulonglong)(*(int *)(puVar1 + 1) + 0x3fU));
    }
  }
  else {
    uVar2 = puVar1[1];
    *param_1 = *puVar1;
    param_1[1] = uVar2;
    uVar2 = puVar1[3];
    param_1[2] = puVar1[2];
    param_1[3] = uVar2;
    param_1[4] = puVar1[4];
    memmove(param_1 + 7,puVar1 + 6,(ulonglong)*(uint *)(puVar1 + 1));
    param_1[5] = (ulonglong)*(uint *)(puVar1 + 5);
    param_1[6] = (ulonglong)*(uint *)((longlong)puVar1 + 0x2c);
  }
  return uVar4;
}



===== PortPassThroughFreeIrpEx @ 1400136d4 =====

void PortPassThroughFreeIrpEx(longlong param_1)

{
  if (*(longlong *)(param_1 + 8) != 0) {
    MmUnlockPages();
    IoFreeMdl(*(undefined8 *)(param_1 + 8));
    *(undefined8 *)(param_1 + 8) = 0;
  }
  IoFreeIrp(param_1);
  return;
}



===== PortPassThroughFreeSrb @ 140013724 =====

void PortPassThroughFreeSrb(longlong param_1)

{
  int iVar1;
  bool bVar2;
  ulonglong uVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  
  if (*(char *)(param_1 + 2) == '(') {
    bVar2 = false;
    lVar4 = 0;
    uVar6 = 0;
    if (*(uint *)(param_1 + 0x38) != 0) {
      do {
        uVar5 = *(uint *)(param_1 + 0x78 + uVar6 * 4);
        if ((0x7f < uVar5) &&
           (uVar7 = (ulonglong)*(uint *)(param_1 + 0x10), uVar5 <= *(uint *)(param_1 + 0x10))) {
          uVar3 = (ulonglong)uVar5;
          iVar1 = *(int *)((ulonglong)uVar5 + param_1);
          if (iVar1 == 0x40) {
            if (uVar3 + 0x28 <= uVar7) {
              lVar4 = *(longlong *)(uVar3 + 0x10 + param_1);
              break;
            }
          }
          else if (iVar1 == 0x41) {
            if (uVar3 + 0x38 <= uVar7) {
              lVar4 = *(longlong *)(uVar3 + 0x10 + param_1);
              bVar2 = true;
            }
          }
          else if ((iVar1 == 0x42) && (uVar3 + 0x28 <= uVar7)) {
            lVar4 = *(longlong *)(uVar3 + 0x18 + param_1);
            break;
          }
          if (bVar2) break;
        }
        uVar5 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar5;
      } while (uVar5 < *(uint *)(param_1 + 0x38));
      if (lVar4 != 0) {
        ExFreePoolWithTag(lVar4,0x69506c50);
      }
    }
  }
  else if (*(longlong *)(param_1 + 0x20) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x20),0x69506c50);
    *(undefined8 *)(param_1 + 0x20) = 0;
  }
  ExFreePoolWithTag(param_1,0x69506c50);
  return;
}



===== PortPassThroughMarshalResultsFromSrb @ 14001381c =====

void PortPassThroughMarshalResultsFromSrb
               (longlong param_1,longlong param_2,char param_3,int *param_4)

{
  uint uVar1;
  ulonglong *puVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  byte bVar5;
  char cVar6;
  int iVar7;
  undefined8 uVar8;
  int iVar9;
  void *_Dst;
  ulonglong uVar10;
  byte bVar11;
  ulonglong uVar12;
  undefined8 local_68;
  undefined8 uStack_60;
  ulonglong local_58;
  ulonglong uStack_50;
  ulonglong local_48;
  ulonglong uStack_40;
  ulonglong local_38;
  
  param_4[2] = 0;
  param_4[3] = 0;
  local_38 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  uVar8 = PortPassThroughNormalize(&local_68,param_1);
  uVar3 = local_68;
  iVar7 = (int)uVar8;
  if (-1 < iVar7) {
    iVar9 = *param_4;
    uVar12 = (ulonglong)*(uint *)(*(longlong *)(param_1 + 0xb8) + 8);
    local_68._0_3_ = CONCAT12(*(undefined1 *)(param_2 + 4),(undefined2)local_68);
    bVar5 = *(byte *)(param_2 + 3);
    if ((char)bVar5 < '\0') {
      local_68._7_1_ = SUB81(uVar3,7);
      if (local_68._7_1_ == '\0') {
        _Dst = (void *)0x0;
      }
      else {
        _Dst = (void *)((local_48 & 0xffffffff) + *(longlong *)(param_1 + 0x18));
      }
      bVar11 = *(byte *)(param_2 + 0xb);
      local_68 = CONCAT17(bVar11,(undefined7)local_68);
      if ((_Dst != (void *)0x0) && (bVar11 != 0)) {
        memmove(_Dst,*(void **)(param_2 + 0x20),(ulonglong)bVar11);
        bVar5 = *(byte *)(param_2 + 3);
      }
      iVar9 = 0;
    }
    else {
      bVar11 = 0;
      local_68 = local_68 & 0xffffffffffffff;
    }
    uVar3 = uStack_60;
    uVar1 = *(uint *)(param_2 + 0x10);
    uStack_60 = CONCAT44(uVar1,(undefined4)uStack_60);
    uVar4 = uStack_60;
    iVar7 = 0;
    if ((bVar5 & 0x3f) != 0x12) {
      iVar7 = iVar9;
    }
    if (bVar11 == 0) {
      uVar10 = local_68 & 0xffff;
      if ((iVar7 < 0) && (*(char *)(param_2 + 4) != '\0')) {
        iVar7 = 0;
        uVar10 = 3;
      }
    }
    else {
      uVar10 = (ulonglong)((uint)bVar11 + (int)local_48);
    }
    if ((((param_3 == '\0') && (uStack_60._0_1_ = (char)uVar3, (char)uStack_60 != '\0')) &&
        (uVar1 != 0)) && (uStack_50 != 0)) {
      uVar10 = uStack_50 + uVar1;
    }
    puVar2 = *(ulonglong **)(param_1 + 0x18);
    if (uVar12 <= uVar10) {
      uVar10 = uVar12;
    }
    *(ulonglong *)(param_4 + 2) = uVar10;
    uStack_60 = uVar4;
    cVar6 = IoIs32bitProcess(param_1);
    if (cVar6 == '\0') {
      *puVar2 = local_68;
      puVar2[1] = uStack_60;
      puVar2[2] = local_58;
      puVar2[3] = uStack_50;
      puVar2[4] = local_48;
      puVar2[5] = uStack_40;
      puVar2[6] = local_38;
    }
    else {
      puVar2 = *(ulonglong **)(param_1 + 0x18);
      *puVar2 = local_68;
      puVar2[1] = uStack_60;
      puVar2[2] = local_58;
    }
  }
  *param_4 = iVar7;
  return;
}



===== PortPassThroughNormalize @ 1400139a4 =====

undefined8 PortPassThroughNormalize(undefined8 *param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  short *psVar3;
  undefined8 uVar4;
  char cVar5;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  psVar3 = *(short **)(param_2 + 0x18);
  uVar1 = *(uint *)(lVar2 + 0x10);
  cVar5 = IoIs32bitProcess(param_2);
  if (cVar5 == '\0') {
    if (uVar1 < 0x38) {
      return 0xc000000d;
    }
    if (*psVar3 != 0x38) {
      return 0xc0000059;
    }
    uVar4 = *(undefined8 *)(psVar3 + 4);
    *param_1 = *(undefined8 *)psVar3;
    param_1[1] = uVar4;
    uVar4 = *(undefined8 *)(psVar3 + 0xc);
    param_1[2] = *(undefined8 *)(psVar3 + 8);
    param_1[3] = uVar4;
    uVar4 = *(undefined8 *)(psVar3 + 0x14);
    param_1[4] = *(undefined8 *)(psVar3 + 0x10);
    param_1[5] = uVar4;
    param_1[6] = *(undefined8 *)(psVar3 + 0x18);
  }
  else {
    if (uVar1 < 0x2c) {
      return 0xc000000d;
    }
    psVar3 = *(short **)(param_2 + 0x18);
    if (*psVar3 != 0x2c) {
      return 0xc0000059;
    }
    uVar4 = *(undefined8 *)(psVar3 + 4);
    *param_1 = *(undefined8 *)psVar3;
    param_1[1] = uVar4;
    param_1[2] = *(undefined8 *)(psVar3 + 8);
    uVar4 = *(undefined8 *)(psVar3 + 0x12);
    *(undefined8 *)((longlong)param_1 + 0x24) = *(undefined8 *)(psVar3 + 0xe);
    *(undefined8 *)((longlong)param_1 + 0x2c) = uVar4;
    param_1[3] = (ulonglong)*(uint *)(psVar3 + 10);
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(psVar3 + 0xc);
  }
  if (*(int *)(lVar2 + 8) == 0) {
    *(undefined1 *)((longlong)param_1 + 7) = 0;
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return 0;
}



===== PortpAsyncCompletion @ 140013a90 =====

undefined8 PortpAsyncCompletion(undefined8 param_1,undefined8 param_2,char *param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 local_res18 [16];
  
  lVar2 = *(longlong *)(param_3 + 0x10);
  LOCK();
  lVar1 = *(longlong *)(lVar2 + 0x68);
  *(longlong *)(lVar2 + 0x68) = 0;
  UNLOCK();
  if (lVar1 == 0) {
    local_res18[0] = 0;
    IoAcquireCancelSpinLock(local_res18);
    lVar1 = *(longlong *)(*(longlong *)(lVar2 + 0xb8) + 0x20);
    *(undefined8 *)(*(longlong *)(lVar2 + 0xb8) + 0x20) = 0;
    IoReleaseCancelSpinLock(local_res18[0]);
    if (lVar1 != 0) {
      return 0xc0000016;
    }
  }
  else {
    *(undefined8 *)(*(longlong *)(lVar2 + 0xb8) + 0x20) = 0;
  }
  PortpCompleteRequestIrp(*(longlong *)(param_3 + 0x10),param_3);
  return 0xc0000016;
}



===== PortpCancelRoutine @ 140013b20 =====

void PortpCancelRoutine(undefined8 param_1,longlong param_2)

{
  char *pcVar1;
  longlong lVar2;
  undefined1 local_res10 [8];
  
  local_res10[0] = 0;
  pcVar1 = *(char **)(*(longlong *)(param_2 + 0xb8) + 0x20);
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  if (pcVar1 != (char *)0x0) {
    IoCancelIrp(*(undefined8 *)(pcVar1 + 8));
    IoAcquireCancelSpinLock(local_res10);
    lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x20);
    *(undefined8 *)(*(longlong *)(param_2 + 0xb8) + 0x20) = 0;
    IoReleaseCancelSpinLock(local_res10[0]);
    if (lVar2 == 0) {
      PortpCompleteRequestIrp(param_2,pcVar1);
    }
  }
  return;
}



===== PortpCompleteRequestIrp @ 140013bc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PortpCompleteRequestIrp(longlong param_1,char *param_2)

{
  longlong lVar1;
  int local_18 [2];
  undefined8 local_10;
  
  lVar1 = *(longlong *)(param_2 + 8);
  local_18[1] = 0;
  local_18[0] = *(int *)(lVar1 + 0x30);
  local_10 = *(undefined8 *)(lVar1 + 0x38);
  if ((*(int *)(*(longlong *)(param_1 + 0xb8) + 0x18) - 0x4d044U & 0xfffffffb) == 0) {
    PortPassThroughExMarshalResultsFromSrbEx
              (*(longlong *)(param_2 + 0x10),*(longlong *)(param_2 + 0x18),*param_2,local_18);
  }
  else {
    PortPassThroughMarshalResultsFromSrb
              (*(longlong *)(param_2 + 0x10),*(longlong *)(param_2 + 0x18),*param_2,local_18);
  }
  *(int *)(*(longlong *)(param_2 + 0x10) + 0x30) = local_18[0];
  *(undefined8 *)(*(longlong *)(param_2 + 0x10) + 0x38) = local_10;
  PortPassThroughFreeIrpEx(lVar1);
  PortPassThroughFreeSrb(*(longlong *)(param_2 + 0x18));
  (**(code **)(param_2 + 0x20))(*(undefined8 *)(param_2 + 0x10),*(undefined8 *)(param_2 + 0x28));
  ExFreePoolWithTag(param_2,0x69506c50);
  return;
}



===== PortpEnableCancel @ 140013c84 =====

undefined8 PortpEnableCancel(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  
  if (*(char *)(param_1 + 0x44) != '\0') {
    return 0xc0000120;
  }
  if (*(code **)(param_2 + 0x20) != PortpSyncCompletion) {
    pbVar1 = (byte *)(*(longlong *)(param_1 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  *(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x20) = param_2;
  LOCK();
  *(code **)(param_1 + 0x68) = PortpCancelRoutine;
  UNLOCK();
  return 0x103;
}



===== PortpPassThroughZeroUnusedBuffers @ 140013ccc =====

void PortpPassThroughZeroUnusedBuffers(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0xb8) + 0x10);
  uVar2 = *(uint *)(*(longlong *)(param_1 + 0xb8) + 8);
  if (uVar1 < uVar2) {
    memset((void *)((ulonglong)uVar1 + *(longlong *)(param_1 + 0x18)),0,(ulonglong)(uVar2 - uVar1));
  }
  return;
}



===== PortpSyncCompletion @ 140013d10 =====

void PortpSyncCompletion(undefined8 param_1,undefined8 param_2)

{
  KeSetEvent(param_2,0,0);
  return;
}



===== _guard_check_icall @ 140013d40 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140013d58 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140013d7c =====

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



===== __GSHandlerCheck_SEH @ 140013de4 =====

void __GSHandlerCheck_SEH
               (_EXCEPTION_RECORD *param_1,void *param_2,_CONTEXT *param_3,
               _DISPATCHER_CONTEXT *param_4)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = *(uint **)(param_4 + 0x38);
  uVar1 = *puVar2;
  __GSHandlerCheckCommon(param_2,(longlong)param_4);
  if ((puVar2[(ulonglong)uVar1 * 4 + 1] & ((param_1->ExceptionFlags & 0x66) != 0) + 1) != 0) {
    __C_specific_handler(param_1,param_2,param_3,param_4);
  }
  return;
}



===== __cpu_features_init @ 140013e80 =====

/* WARNING: Removing unreachable block (ram,0x000140013eea) */
/* WARNING: Removing unreachable block (ram,0x000140013e99) */
/* WARNING: Removing unreachable block (ram,0x000140013e8a) */

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



===== __security_check_cookie @ 140013f50 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140013f90 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140013fc0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140013fc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140013ff0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 140014020 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_140014063;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_1400140d4;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_1400140d0:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1400140d4;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_1400140cc:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1400140d0;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1400140cc;
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
LAB_1400140d4:
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
LAB_140014063:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memmove @ 140014140 =====

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



===== memset @ 140014440 =====

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



===== __memset_repmovs @ 140014580 =====

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



===== __memset_query @ 140014600 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140014680 =====

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



===== __memset_spec_ermsb_repmovsb @ 1400147c0 =====

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



===== __memset_spec_plain @ 140014840 =====

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



===== DriverEntry @ 14001c008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DriverEntry(longlong param_1)

{
  code *pcVar1;
  undefined *puVar2;
  uint local_res8 [2];
  undefined8 local_18;
  undefined8 uStack_10;
  
  wil_InitializeFeatureStaging();
  _DAT_140018168 = 1;
  _WPP_MAIN_CB = (code *)0x0;
  DAT_140018148 = &WPP_ThisDir_CTLGUID_wppCtlGuid;
  DAT_140018150 = 0;
  _DAT_140018160 = 0;
  local_18 = 0;
  uStack_10 = 0;
  local_res8[0] = 0;
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
    pfnEtwRegisterClassicProvider = (code *)MmGetSystemRoutineAddress(&local_18);
    if (pfnEtwRegisterClassicProvider != (code *)0x0) {
      RtlInitUnicodeString(&local_18,L"EtwUnregister");
      pfnEtwUnregister = MmGetSystemRoutineAddress(&local_18);
      WPPTraceSuite = 4;
    }
  }
  puVar2 = &WPP_MAIN_CB;
  _DAT_140018160 = 0;
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
  *(code **)(param_1 + 0x70) = Sbp2CreateClose;
  *(code **)(param_1 + 0x80) = Sbp2CreateClose;
  *(code **)(param_1 + 0xe0) = Sbp2DeviceControl;
  *(code **)(param_1 + 0xe8) = Sbp2ScsiRequests;
  *(code **)(param_1 + 0x148) = Sbp2PnpDeviceControl;
  *(code **)(param_1 + 0x120) = Sbp2PowerControl;
  *(code **)(param_1 + 0x128) = Sbp2SystemControl;
  *(code **)(*(longlong *)(param_1 + 0x30) + 8) = Sbp2AddDevice;
  *(code **)(param_1 + 0x60) = Sbp2StartIo;
  *(code **)(param_1 + 0x68) = Sbp2Unload;
  return 0;
}



===== Sbp2AddDevice @ 14001c2b0 =====

ulonglong Sbp2AddDevice(undefined8 param_1,undefined8 param_2)

{
  ulonglong uVar1;
  
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qq(WPP_GLOBAL_Control[3],10,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,param_1,
              (char)param_2);
  }
  uVar1 = Sbp2CreateDevObject(param_1,param_2);
  if ((((int)uVar1 < 0) && ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
      (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
    WPP_SF_qd(WPP_GLOBAL_Control[3],0xb,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,param_2,
              (char)uVar1);
  }
  return uVar1 & 0xffffffff;
}



===== Sbp2CreateDevObject @ 14001c364 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 Sbp2CreateDevObject(undefined8 param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined1 auStack_148 [32];
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 *local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  ulonglong uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  wchar_t local_a8 [64];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_148;
  local_d8 = 0;
  uStack_d0 = uStack_d0 & 0xffffffff00000000;
  local_100 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  uVar5 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  local_e8 = (undefined8 *)0x0;
  uStack_e0 = 0;
  do {
    uVar3 = RtlStringCbPrintfW(local_a8,0x80,L"\\Device\\Sbp2Port%x",(ulonglong)uVar5);
    if ((int)uVar3 < 0) {
      return uVar3;
    }
    RtlInitUnicodeString(&local_c8,local_a8);
    uVar6 = 0x2a;
    uVar3 = IoCreateDevice(param_1,0x45b8,&local_c8);
    puVar1 = puRam0000000000000040;
    uVar5 = uVar5 + 1;
  } while ((int)uVar3 == -0x3fffffcb);
  if (-1 < (int)uVar3) {
    memset(puRam0000000000000040,0,0x5b8);
    lVar4 = IoAttachDeviceToDeviceStack(0,param_2);
    puVar1[1] = lVar4;
    if (lVar4 == 0) {
      IoDeleteDevice(0);
      uVar3 = 0xc0000010;
    }
    else {
      puVar1[2] = 0x4f444673;
      *puVar1 = 0;
      puVar1[8] = param_2;
      puVar1[0xb5] = 0;
      *(undefined4 *)(puVar1 + 0xb6) = 0;
      KeInitializeSpinLock(puVar1 + 0x14);
      KeInitializeMutex(puVar1 + 0xc,0);
      RtlStringCbPrintfW(local_a8,0x80,L"\\Device\\Sbp2",uVar6);
      RtlInitUnicodeString(&local_b8,local_a8);
      local_e8 = &local_b8;
      local_f8 = CONCAT44(local_f8._4_4_,0x30);
      uStack_f0 = 0;
      uStack_e0 = CONCAT44(uStack_e0._4_4_,0x250);
      local_d8 = 0;
      uStack_d0 = 0;
      iVar2 = ZwCreateDirectoryObject(&local_100,0xf000f,&local_f8);
      if (iVar2 < 0) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_qd(WPP_GLOBAL_Control[3],0xc,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,
                    puVar1,(char)iVar2);
        }
      }
      else {
        ZwClose(local_100);
      }
      *(undefined4 *)(puVar1 + 0xae) = 1;
      puVar1[0xaf] = 0;
      *(undefined4 *)(puVar1 + 0xb0) = 0;
      KeInitializeEvent(puVar1 + 0xb1,1);
      IoInitializeRemoveLockEx(puVar1 + 3,0x32706253,2,0x2000);
      uRam0000000000000030 = uRam0000000000000030 & 0xffffff7f | 0x10;
      uVar3 = 0;
    }
  }
  return uVar3;
}



===== Sbp2CreateDeviceRelations @ 14001c634 =====

int Sbp2CreateDeviceRelations(longlong *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong *plVar7;
  ulonglong uVar8;
  
  *param_2 = 0;
  uVar1 = *(uint *)(param_1 + 0x13);
  iVar2 = Sbp2Get1394ConfigInfo((longlong)param_1,0);
  if (-1 < iVar2) {
    if ((*(uint *)((longlong)param_1 + 0x14) & 8) == 0) {
      iVar2 = 0;
      uVar8 = 0;
      if ((int)param_1[0x13] != 0) {
        do {
          plVar7 = param_1 + uVar8 * 0xf + 0x15;
          if (*plVar7 == 0) {
            do {
              uVar6 = Sbp2CreatePdo(param_1,plVar7);
              iVar2 = (int)uVar6;
            } while (iVar2 == -0x3fffffcb);
            if (iVar2 < 0) {
              if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                WPP_SF_D(WPP_GLOBAL_Control[3],100,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,
                         iVar2);
              }
              goto LAB_14001c837;
            }
            *(longlong *)(param_2 + (ulonglong)*param_2 * 2 + 2) = *plVar7;
LAB_14001c7c2:
            *param_2 = *param_2 + 1;
            ObfReferenceObject(*plVar7);
          }
          else if ((*(int *)(*(longlong *)(*plVar7 + 0x40) + 0x10) != 0x4f445078) ||
                  (uVar6 = Sbp2ReInitializePdo(param_1,plVar7), -1 < (int)uVar6)) {
            *(longlong *)(param_2 + (ulonglong)*param_2 * 2 + 2) = *plVar7;
            goto LAB_14001c7c2;
          }
          uVar3 = (int)uVar8 + 1;
          uVar8 = (ulonglong)uVar3;
        } while (uVar3 < *(uint *)(param_1 + 0x13));
      }
    }
    else {
      iVar2 = -0x3fffffff;
    }
    plVar7 = param_1 + 0x15;
    if (((*plVar7 != 0) && (*(longlong *)(*plVar7 + 0x40) != 0)) &&
       ((*(uint *)(param_1 + 0x1c) & 0x100) != 0)) {
      uVar3 = 0;
      if (uVar1 != 0) {
        do {
          if (*plVar7 == 0) break;
          uVar3 = uVar3 + 1;
          plVar7 = plVar7 + 0xf;
        } while (uVar3 < uVar1);
      }
      *(uint *)(param_1 + 0x13) = uVar3;
      if ((iVar2 < 0) && (iVar4 = IoAcquireRemoveLockEx(param_1 + 3,0,"",1,0x20), -1 < iVar4)) {
        lVar5 = IoAllocateWorkItem(*param_1);
        if (lVar5 == 0) {
          IoReleaseRemoveLockEx(param_1 + 3,0,0x20);
        }
        else {
          IoQueueWorkItem(lVar5,Sbp2BusResetNotificationWorker,0,lVar5);
        }
      }
    }
  }
LAB_14001c837:
  return iVar2;
}



===== Sbp2CreatePdo @ 14001c860 =====

ulonglong Sbp2CreatePdo(longlong *param_1,longlong *param_2)

{
  longlong *_Dst;
  uint uVar1;
  uint uVar2;
  wchar_t *pwVar3;
  undefined8 uVar4;
  longlong lVar5;
  ulonglong uVar6;
  ushort uVar7;
  longlong *plVar8;
  wchar_t *pwVar9;
  undefined4 uVar10;
  wchar_t *pwVar11;
  undefined8 in_stack_ffffffffffffff98;
  undefined4 uVar12;
  undefined8 local_38;
  undefined8 uStack_30;
  
  uVar12 = (undefined4)((ulonglong)in_stack_ffffffffffffff98 >> 0x20);
  local_38 = 0;
  uStack_30 = 0;
  if ((*(int *)((longlong)param_2 + 0xc) == 0x10483) ||
     (*(int *)((longlong)param_2 + 0xc) == 0x104d8)) {
    uVar7 = *(ushort *)((longlong)param_2 + 10) & 0x1f;
    if ((*(ushort *)((longlong)param_2 + 10) & 0x1f) == 0) {
LAB_14001c8c9:
      uVar10 = 0x2d;
    }
    else if (uVar7 == 2) {
      uVar10 = 0x18;
    }
    else {
      if ((uVar7 == 5) || (uVar7 != 6)) goto LAB_14001c8c9;
      uVar10 = 0x19;
    }
  }
  else {
    uVar10 = 0x22;
  }
  pwVar3 = (wchar_t *)ExAllocatePool2(0x40,0xa00,0x6c536253);
  if (pwVar3 == (wchar_t *)0x0) {
    return 0xc000009a;
  }
  if (param_2[10] == 0) {
    uVar2 = *(uint *)(param_1 + 0xad);
    uVar2 = (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    uVar4 = RtlStringCbPrintfW(pwVar3,0xa00,
                               L"\\Device\\Sbp2\\UNKNOWN_VENDOR&UNKNOWN_MODEL&%x&%08x_%08x_Instance%02d"
                               ,(ulonglong)*(ushort *)(param_2 + 1));
    uVar1 = (uint)uVar4;
  }
  else {
    pwVar9 = L"UNKNOWN_MODEL";
    if ((wchar_t *)param_2[0xc] != (wchar_t *)0x0) {
      pwVar9 = (wchar_t *)param_2[0xc];
    }
    uVar12 = (undefined4)((ulonglong)pwVar9 >> 0x20);
    uVar2 = (uint)*(ushort *)(param_2 + 1);
    uVar4 = RtlStringCbPrintfW(pwVar3,0xa00,L"\\Device\\Sbp2\\%ws&%ws&%x&%08x_%08x_Instance%02d",
                               param_2[10]);
    uVar1 = (uint)uVar4;
  }
  if ((int)uVar1 < 0) {
    ExFreePoolWithTag(pwVar3,0x6c536253);
    return (ulonglong)uVar1;
  }
  RtlInitUnicodeString(&local_38,pwVar3);
  uVar4 = CONCAT44(uVar12,0x100);
  uVar2 = IoCreateDevice(*(undefined8 *)(*param_1 + 8),0x46c0,&local_38,uVar10,uVar4,
                         uVar2 & 0xffffff00,param_2);
  uVar12 = (undefined4)((ulonglong)uVar4 >> 0x20);
  if ((int)uVar2 < 0) {
    ExFreePoolWithTag(pwVar3,0x6c536253);
    return (ulonglong)uVar2;
  }
  if (*(uint *)(*param_2 + 0x98) < 3) {
    *(undefined4 *)(*param_2 + 0x98) = 3;
  }
  _Dst = *(longlong **)(*param_2 + 0x40);
  memset(_Dst,0,0x6c0);
  _Dst[1] = param_1[1];
  *_Dst = *param_2;
  _Dst[0xb] = (longlong)param_2;
  *(int *)(param_2 + 6) = (int)param_1[7];
  _Dst[10] = *param_1;
  *(undefined4 *)(_Dst + 2) = 0x4f445073;
  KeInitializeEvent(_Dst + 0x5d,0,0);
  KeInitializeEvent(_Dst + 0x60,0,0);
  *(undefined4 *)((longlong)_Dst + 0x64c) = 0;
  KeInitializeSpinLock(_Dst + 0xb5);
  IoInitializeRemoveLockEx(_Dst + 3,0x32706253,2,0x2000,CONCAT44(uVar12,0x20));
  *(undefined4 *)(_Dst + 0xc9) = 3;
  plVar8 = _Dst;
  Sbp2AllocateLog((longlong)_Dst);
  Sbp2AddLog((longlong)plVar8,1,0x494e4954,_Dst,0);
  *(undefined2 *)((longlong)param_2 + 0x6a) = 0x20;
  *(undefined2 *)(param_2 + 0xd) = 0;
  uVar4 = 0x62476253;
  lVar5 = ExAllocatePool2(0x40,0x20);
  param_2[0xe] = lVar5;
  if (lVar5 == 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_(WPP_GLOBAL_Control[3],0xe,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids);
    }
  }
  else {
    if ((*(int *)((longlong)param_2 + 0xc) == 0x10483) ||
       (*(int *)((longlong)param_2 + 0xc) == 0x104d8)) {
      uVar7 = *(ushort *)((longlong)param_2 + 10) & 0x1f;
      if ((*(ushort *)((longlong)param_2 + 10) & 0x1f) == 0) {
LAB_14001cbbe:
        pwVar9 = L"GenDisk";
      }
      else if (uVar7 == 1) {
        pwVar9 = L"GenSequential";
      }
      else if (uVar7 == 2) {
        pwVar9 = L"GenPrinter";
      }
      else if (uVar7 == 4) {
        pwVar9 = L"GenWorm";
      }
      else if (uVar7 == 5) {
        pwVar9 = L"GenCdRom";
      }
      else if (uVar7 == 6) {
        pwVar9 = L"GenScanner";
      }
      else if (uVar7 == 7) {
        pwVar9 = L"GenOptical";
      }
      else {
        if (uVar7 != 8) {
          if (uVar7 != 0xe) goto LAB_14001cb76;
          goto LAB_14001cbbe;
        }
        pwVar9 = L"GenChanger";
      }
    }
    else {
LAB_14001cb76:
      pwVar9 = L"GenSbp2Device";
    }
    RtlAppendUnicodeToString(param_2 + 0xd,pwVar9);
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qS(WPP_GLOBAL_Control[3],0xd,uVar4,_Dst,(wchar_t *)param_2[0xe]);
    }
  }
  *(uint *)(*param_2 + 0x30) = *(uint *)(*param_2 + 0x30) | 0x10;
  uVar6 = Sbp2PreAllocateLists(_Dst);
  if ((int)uVar6 < 0) {
    IoDeleteDevice(*_Dst);
    *param_2 = 0;
    return uVar6 & 0xffffffff;
  }
  pwVar9 = (wchar_t *)ExAllocatePool2(0x100,0x600,0x6c536253);
  if (pwVar9 == (wchar_t *)0x0) {
    uVar2 = 0xc000009a;
  }
  else {
    pwVar11 = L"\\DosDevices\\Sbp2&LUN%x&%08x%08x&Instance%02d";
    uVar4 = RtlStringCbPrintfW(pwVar9,0x600,L"\\DosDevices\\Sbp2&LUN%x&%08x%08x&Instance%02d",
                               (ulonglong)*(ushort *)(param_2 + 1));
    uVar2 = (uint)uVar4;
    if (-1 < (int)uVar2) {
      RtlInitUnicodeString(_Dst + 0x2f,pwVar9);
      uVar2 = IoCreateUnprotectedSymbolicLink(_Dst + 0x2f,&local_38);
      uVar6 = (ulonglong)uVar2;
      if (-1 < (int)uVar2) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_qS(WPP_GLOBAL_Control[3],0xf,pwVar11,_Dst,pwVar9);
        }
        goto LAB_14001cdb7;
      }
    }
  }
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
     (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qd(WPP_GLOBAL_Control[3],0x10,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,_Dst,
              (char)uVar2);
  }
  if (pwVar9 != (wchar_t *)0x0) {
    *(undefined2 *)(_Dst + 0x2f) = 0;
    _Dst[0x30] = 0;
    ExFreePoolWithTag(pwVar9,0x6c536253);
  }
  uVar6 = 0;
LAB_14001cdb7:
  ExFreePoolWithTag(pwVar3,0x6c536253);
  KeInitializeDpc(_Dst + 0xb6,Sbp2DeviceManagementTimeoutDpc,_Dst);
  KeInitializeTimer(_Dst + 0xbe);
  *(undefined4 *)(_Dst + 0x34) = 0xffffffff;
  plVar8 = _Dst + 0xc6;
  _Dst[199] = (longlong)plVar8;
  *plVar8 = (longlong)plVar8;
  *(undefined4 *)(_Dst + 200) = 0;
  *(uint *)(*param_2 + 0x30) = *(uint *)(*param_2 + 0x30) & 0xffffff7f;
  return uVar6;
}



===== Sbp2DeviceControl @ 14001ce50 =====

int Sbp2DeviceControl(longlong *param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  int iVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  char cVar8;
  
  lVar1 = param_1[8];
  lVar2 = *(longlong *)(param_2 + 0xb8);
  if (*(int *)(lVar1 + 0x10) == 0x4f445073) {
    iVar4 = *(int *)(lVar2 + 0x18);
    if (iVar4 == 0x41010) {
      puVar3 = *(undefined8 **)(param_2 + 0x18);
      if (*(uint *)(lVar2 + 8) < 0x18) {
        iVar4 = -0x3fffffdd;
      }
      else {
        *puVar3 = 0;
        puVar3[1] = 0;
        puVar3[2] = 0;
        *(undefined4 *)puVar3 = 0x18;
        uVar5 = *(uint *)(*(longlong *)(lVar1 + 0x58) + 0x30);
        *(uint *)((longlong)puVar3 + 4) = uVar5;
        uVar5 = uVar5 >> 0xc;
        *(uint *)(puVar3 + 1) = uVar5;
        if (uVar5 < 0x1ff) {
          *(uint *)(puVar3 + 1) = uVar5 + 1;
        }
        *(undefined4 *)((longlong)puVar3 + 0xc) = 0;
        lVar1 = param_1[0x13];
        *(undefined2 *)((longlong)puVar3 + 0x14) = 0;
        *(int *)(puVar3 + 2) = (int)lVar1;
        iVar4 = 0;
        *(undefined1 *)((longlong)puVar3 + 0x16) = 0;
        *(undefined8 *)(param_2 + 0x38) = 0x18;
      }
      *(int *)(param_2 + 0x30) = iVar4;
      goto LAB_14001cefe;
    }
    if (iVar4 == 0x4d004) {
      cVar8 = '\0';
LAB_14001cf4e:
      uVar7 = Sbp2ScsiPassThrough(param_1,param_2,cVar8);
      return (int)uVar7;
    }
    if (iVar4 == 0x4d014) {
      cVar8 = '\x01';
      goto LAB_14001cf4e;
    }
    if (iVar4 == 0x220801) {
      iVar4 = Sbp2HandleApiRequest(lVar1,param_2);
      return iVar4;
    }
    if (iVar4 != 0x2d1400) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_qqD(WPP_GLOBAL_Control[3],0x42,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,lVar1
                   ,(char)param_2,(char)iVar4);
      }
      goto LAB_14001ceef;
    }
    if (0xb < *(uint *)(lVar2 + 0x10)) {
      uVar6 = Sbp2QueryProperty((longlong)param_1,param_2);
      return (int)uVar6;
    }
    iVar4 = -0x3ffffff3;
    *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
  }
  else {
LAB_14001ceef:
    iVar4 = -0x3fffff45;
    *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
LAB_14001cefe:
  IofCompleteRequest(param_2,0);
  return iVar4;
}



===== Sbp2ForwardIrpSynchronous @ 14001cfc8 =====

undefined4 Sbp2ForwardIrpSynchronous(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  int iVar6;
  longlong lVar7;
  undefined4 uVar8;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  lVar7 = IoAllocateIrp(*(undefined1 *)(param_1 + 0x4c),0);
  if (lVar7 == 0) {
    uVar8 = 0xc000009a;
  }
  else {
    puVar1 = *(undefined8 **)(param_2 + 0xb8);
    lVar2 = *(longlong *)(lVar7 + 0xb8);
    local_28 = 0;
    uStack_20 = 0;
    local_18 = 0;
    uVar5 = puVar1[1];
    *(undefined8 *)(lVar2 + -0x48) = *puVar1;
    *(undefined8 *)(lVar2 + -0x40) = uVar5;
    uVar5 = puVar1[3];
    *(undefined8 *)(lVar2 + -0x38) = puVar1[2];
    *(undefined8 *)(lVar2 + -0x30) = uVar5;
    uVar5 = puVar1[5];
    *(undefined8 *)(lVar2 + -0x28) = puVar1[4];
    *(undefined8 *)(lVar2 + -0x20) = uVar5;
    *(undefined8 *)(lVar2 + -0x18) = puVar1[6];
    *(undefined1 *)(lVar2 + -0x45) = 0;
    uVar8 = *(undefined4 *)(param_2 + 0x34);
    uVar3 = *(undefined4 *)(param_2 + 0x38);
    uVar4 = *(undefined4 *)(param_2 + 0x3c);
    *(undefined4 *)(lVar7 + 0x30) = *(undefined4 *)(param_2 + 0x30);
    *(undefined4 *)(lVar7 + 0x34) = uVar8;
    *(undefined4 *)(lVar7 + 0x38) = uVar3;
    *(undefined4 *)(lVar7 + 0x3c) = uVar4;
    KeInitializeEvent(&local_28,0,0);
    lVar2 = *(longlong *)(lVar7 + 0xb8);
    *(code **)(lVar2 + -0x10) = Sbp2PortForwardIrpSynchronousCompletionRoutine;
    *(undefined8 **)(lVar2 + -8) = &local_28;
    *(undefined1 *)(lVar2 + -0x45) = 0xe0;
    iVar6 = IofCallDriver(param_1,lVar7);
    if (iVar6 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
    }
    uVar8 = *(undefined4 *)(lVar7 + 0x30);
    IoFreeIrp(lVar7);
  }
  return uVar8;
}



===== Sbp2GetHostDDIVersion @ 14001d0e8 =====

int Sbp2GetHostDDIVersion(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  undefined4 local_res10;
  longlong local_res18;
  
  local_res10 = 0;
  local_res18 = 0;
  AllocateIrpAndIrb(param_1,&local_res18);
  lVar1 = local_res18;
  if (local_res18 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    **(undefined4 **)(local_res18 + 0x10) = 0x13;
    *(undefined4 *)(*(longlong *)(local_res18 + 0x10) + 4) = 0;
    *(undefined4 *)(*(longlong *)(local_res18 + 0x10) + 0x88) = 8;
    *(undefined4 **)(*(longlong *)(local_res18 + 0x10) + 0x90) = &local_res10;
    iVar2 = Sbp2SendRequest(param_1,local_res18,(undefined *)0x2);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else {
      *(undefined2 *)(param_1 + 0x5b0) = (undefined2)local_res10;
      *(undefined2 *)(param_1 + 0x5b2) = local_res10._2_2_;
    }
    DeAllocateIrpAndIrb(param_1,lVar1);
  }
  return iVar2;
}



===== Sbp2ReInitializePdo @ 14001d1a8 =====

ulonglong Sbp2ReInitializePdo(longlong *param_1,longlong *param_2)

{
  longlong *plVar1;
  uint uVar2;
  longlong *_Dst;
  int iVar3;
  ulonglong uVar4;
  wchar_t *pwVar5;
  ulonglong uVar6;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_48 = 0;
  uStack_40 = 0;
  if (*(uint *)(*param_2 + 0x98) < 3) {
    *(undefined4 *)(*param_2 + 0x98) = 3;
  }
  _Dst = *(longlong **)(*param_2 + 0x40);
  local_38 = _Dst[3];
  uStack_30 = _Dst[4];
  uVar2 = *(uint *)((longlong)_Dst + 0x14);
  local_28 = _Dst[5];
  uStack_20 = _Dst[6];
  memset(_Dst,0,0x6c0);
  *(undefined4 *)(_Dst + 3) = (undefined4)local_38;
  *(undefined4 *)((longlong)_Dst + 0x1c) = local_38._4_4_;
  *(undefined4 *)(_Dst + 4) = (undefined4)uStack_30;
  *(undefined4 *)((longlong)_Dst + 0x24) = uStack_30._4_4_;
  *(undefined4 *)(_Dst + 5) = (undefined4)local_28;
  *(undefined4 *)((longlong)_Dst + 0x2c) = local_28._4_4_;
  *(undefined4 *)(_Dst + 6) = (undefined4)uStack_20;
  *(undefined4 *)((longlong)_Dst + 0x34) = uStack_20._4_4_;
  _Dst[1] = param_1[1];
  *_Dst = *param_2;
  _Dst[0xb] = (longlong)param_2;
  *(int *)(param_2 + 6) = (int)param_1[7];
  _Dst[10] = *param_1;
  *(undefined4 *)(_Dst + 2) = 0x4f445073;
  KeInitializeEvent(_Dst + 0x5d,0,0);
  KeInitializeEvent(_Dst + 0x60,0,0);
  KeInitializeSpinLock(_Dst + 0xb5);
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_S(WPP_GLOBAL_Control[3],0x6d,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,
             (wchar_t *)param_2[0xe]);
  }
  *(uint *)(*param_2 + 0x30) = *(uint *)(*param_2 + 0x30) | 0x10;
  uVar4 = Sbp2PreAllocateLists(_Dst);
  uVar6 = uVar4 & 0xffffffff;
  if ((int)uVar4 < 0) {
    *param_2 = 0;
    *(uint *)((longlong)_Dst + 0x14) = *(uint *)((longlong)_Dst + 0x14) | uVar2;
  }
  else {
    pwVar5 = (wchar_t *)ExAllocatePool2(0x100,0x600,0x6c536253);
    if (pwVar5 == (wchar_t *)0x0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_(WPP_GLOBAL_Control[3],0x70,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids);
      }
    }
    else {
      RtlStringCbPrintfW(pwVar5,0x600,L"\\DosDevices\\Sbp2&LUN%x&%08x%08x&Instance%02d",
                         (ulonglong)*(ushort *)(param_2 + 1));
      RtlInitUnicodeString(_Dst + 0x2f,pwVar5);
      RtlInitUnicodeString(&local_48,pwVar5);
      iVar3 = IoCreateUnprotectedSymbolicLink(_Dst + 0x2f,&local_48);
      if (iVar3 < 0) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_D(WPP_GLOBAL_Control[3],0x6f,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,iVar3
                  );
        }
      }
      else if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
              (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_S(WPP_GLOBAL_Control[3],0x6e,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,pwVar5)
        ;
      }
    }
    uVar6 = 0;
    *(uint *)(*param_2 + 0x30) = *(uint *)(*param_2 + 0x30) & 0xffffff7f;
    *(undefined4 *)((longlong)_Dst + 0x14) = 0;
  }
  *(undefined4 *)(_Dst + 0x34) = 0xffffffff;
  plVar1 = _Dst + 0xc6;
  _Dst[199] = (longlong)plVar1;
  *plVar1 = (longlong)plVar1;
  return uVar6;
}



===== Sbp2SystemControl @ 14001d470 =====

ulonglong Sbp2SystemControl(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  if (*(int *)(lVar2 + 0x10) == 0x4f444673) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qq(WPP_GLOBAL_Control[3],0x65,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids,lVar2,
                (char)param_2);
    }
    puVar3 = *(undefined8 **)(param_2 + 0xb8);
    puVar3[-9] = *puVar3;
    puVar3[-8] = puVar3[1];
    puVar3[-7] = puVar3[2];
    puVar3[-6] = puVar3[3];
    *(undefined4 *)(puVar3 + -5) = *(undefined4 *)(puVar3 + 4);
    *(undefined4 *)((longlong)puVar3 + -0x24) = *(undefined4 *)((longlong)puVar3 + 0x24);
    *(undefined4 *)(puVar3 + -4) = *(undefined4 *)(puVar3 + 5);
    *(undefined4 *)((longlong)puVar3 + -0x1c) = *(undefined4 *)((longlong)puVar3 + 0x2c);
    puVar3[-3] = puVar3[6];
    *(undefined1 *)((longlong)puVar3 + -0x45) = 0;
    uVar4 = IofCallDriver(*(undefined8 *)(lVar2 + 8),param_2);
  }
  else {
    uVar1 = *(uint *)(param_2 + 0x30);
    IofCompleteRequest(param_2,0);
    uVar4 = (ulonglong)uVar1;
  }
  return uVar4;
}



===== Sbp2_BuildCompatIds @ 14001d530 =====

undefined8 Sbp2_BuildCompatIds(longlong param_1,undefined2 *param_2)

{
  wchar_t *pwVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  *param_2 = 0;
  param_2[1] = 200;
  pwVar1 = (wchar_t *)ExAllocatePool2(0x100,200,0x32706253);
  *(wchar_t **)(param_2 + 4) = pwVar1;
  if (pwVar1 == (wchar_t *)0x0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_(WPP_GLOBAL_Control[3],0x6a,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids);
    }
    uVar2 = 0xc000009a;
  }
  else {
    RtlStringCbPrintfW(pwVar1,(ulonglong)(ushort)param_2[1],L"SBP2\\%d&%d&%d",
                       (ulonglong)*(uint *)(param_1 + 0x10));
  }
  return uVar2;
}



===== Sbp2_BuildDeviceId @ 14001d5f0 =====

undefined8 Sbp2_BuildDeviceId(longlong param_1,undefined2 *param_2)

{
  char cVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 local_18;
  undefined8 uStack_10;
  
  uVar4 = 0;
  *param_2 = 0;
  param_2[1] = 600;
  lVar2 = ExAllocatePool2(0x100,600,0x62476253);
  *(longlong *)(param_2 + 4) = lVar2;
  if (lVar2 == 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_(WPP_GLOBAL_Control[3],0x66,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids);
    }
    uVar4 = 0xc000009a;
  }
  else {
    local_18 = 0;
    uStack_10 = 0;
    RtlInitUnicodeString(&local_18,L"Niveus");
    if ((((*(longlong *)(param_1 + 0x60) != 0) &&
         (cVar1 = RtlEqualUnicodeString(&local_18,param_1 + 0x48,1), cVar1 != '\0')) &&
        (lVar2 = RtlCompareMemory(*(undefined8 *)(param_1 + 0x60),L"IV00",8), lVar2 == 8)) &&
       ((*(short *)(param_1 + 0x58) == 0x10 && (*(short *)(param_1 + 8) == 2)))) {
      builtin_wcsncpy(*(wchar_t **)(param_1 + 0x60),L"IV00XXXX",8);
    }
    lVar2 = *(longlong *)(param_1 + 0x50);
    uVar3 = (ulonglong)(ushort)param_2[1];
    if (lVar2 == 0) {
      RtlStringCbPrintfW(*(wchar_t **)(param_2 + 4),uVar3,
                         L"SBP2\\UNKNOWN VENDOR&UNKNOWN MODEL&LUN%x",
                         (ulonglong)*(ushort *)(param_1 + 8));
    }
    else if ((*(uint *)(param_1 + 0x34) & 0xff) == 0) {
      RtlStringCbPrintfW(*(wchar_t **)(param_2 + 4),uVar3,L"SBP2\\%ws&%ws&LUN%x",lVar2);
    }
    else {
      RtlStringCbPrintfW(*(wchar_t **)(param_2 + 4),uVar3,L"SBP2\\%ws&%ws&LUN%x&REV%x",lVar2);
    }
  }
  return uVar4;
}



===== Sbp2_BuildDeviceText @ 14001d798 =====

undefined8 Sbp2_BuildDeviceText(int param_1,longlong param_2,undefined4 *param_3)

{
  wchar_t *pwVar1;
  undefined8 uVar2;
  
  *param_3 = 0x2580000;
  uVar2 = 0;
  pwVar1 = (wchar_t *)ExAllocatePool2(0x100,600,0x32706253);
  *(wchar_t **)(param_3 + 2) = pwVar1;
  if (pwVar1 == (wchar_t *)0x0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_(WPP_GLOBAL_Control[3],0x6c,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids);
    }
    uVar2 = 0xc000009a;
  }
  else if (param_1 == 0) {
    if (*(longlong *)(param_2 + 0x50) == 0) {
      RtlStringCbPrintfW(pwVar1,(ulonglong)*(ushort *)((longlong)param_3 + 2),
                         L"UNKNOWN VENDOR AND MODEL IEEE 1394 SBP2 Device",0);
    }
    else {
      RtlStringCbPrintfW(pwVar1,(ulonglong)*(ushort *)((longlong)param_3 + 2),
                         L"%ws %ws IEEE 1394 SBP2 Device",*(longlong *)(param_2 + 0x50));
    }
  }
  else if (param_1 == 1) {
    RtlStringCbPrintfW(pwVar1,(ulonglong)*(ushort *)((longlong)param_3 + 2),L"LUN %d",
                       (ulonglong)*(ushort *)(param_2 + 8));
  }
  return uVar2;
}



===== Sbp2_BuildHardwareIds @ 14001d8a4 =====

undefined4 Sbp2_BuildHardwareIds(longlong param_1,short *param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  undefined8 local_68;
  longlong lStack_60;
  undefined8 local_58;
  longlong local_50;
  undefined8 local_48;
  longlong local_40;
  undefined8 local_38;
  longlong local_30;
  
  local_48 = 0x2a0000;
  local_38 = 0;
  local_58 = 0;
  local_30 = 0;
  local_50 = 0;
  uVar4 = 0;
  local_68 = 0;
  lStack_60 = 0;
  local_40 = ExAllocatePool2(0x100,0x2a,0x32706253);
  if (local_40 == 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      uVar3 = 0x67;
LAB_14001d93e:
      WPP_SF_(WPP_GLOBAL_Control[3],uVar3,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids);
    }
  }
  else {
    RtlIntegerToUnicodeString(*(undefined2 *)(param_1 + 8),0x10,&local_48);
    if (*(char *)(param_1 + 0x34) != '\0') {
      local_58._0_4_ = CONCAT22(0x2a,(undefined2)local_58);
      local_50 = ExAllocatePool2(0x100,0x2a,0x32706253);
      if (local_50 != 0) {
        RtlIntegerToUnicodeString(*(uint *)(param_1 + 0x34) & 0xff,0x10,&local_58);
      }
    }
    local_38._0_4_ = CONCAT22(0x2a,(undefined2)local_38);
    local_30 = ExAllocatePool2(0x100,0x2a,0x32706253);
    if (local_30 == 0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        uVar3 = 0x68;
        goto LAB_14001d93e;
      }
    }
    else {
      RtlIntegerToUnicodeString(*(undefined4 *)(param_1 + 0xc),0x10,&local_38);
      if (*(longlong *)(param_1 + 0x60) == 0) {
        RtlInitUnicodeString(&local_68,L"UNKNOWN MODEL");
      }
      else {
        local_68 = CONCAT44(local_68._4_4_,*(undefined4 *)(param_1 + 0x58));
        lStack_60 = *(longlong *)(param_1 + 0x60);
      }
      param_2[0] = 0;
      param_2[1] = 0x4b0;
      lVar2 = ExAllocatePool2(0x100,0x4b0,0x32706253);
      *(longlong *)(param_2 + 4) = lVar2;
      if (lVar2 != 0) {
        RtlAppendUnicodeToString(param_2,L"SBP2\\");
        lVar2 = param_1 + 0x48;
        if (*(longlong *)(param_1 + 0x50) == 0) {
          RtlAppendUnicodeToString(param_2,L"UNKNOWN VENDOR&UNKNOWN MODEL");
        }
        else {
          RtlAppendUnicodeStringToString(param_2,lVar2);
          RtlAppendUnicodeToString(param_2,L"&");
          RtlAppendUnicodeStringToString(param_2,&local_68);
        }
        RtlAppendUnicodeToString(param_2,L"&");
        RtlAppendUnicodeToString(param_2,L"CmdSetId");
        RtlAppendUnicodeStringToString(param_2,&local_38);
        RtlAppendUnicodeToString(param_2,L"&");
        lVar1 = param_1 + 0x68;
        RtlAppendUnicodeStringToString(param_2,lVar1);
        *param_2 = *param_2 + 2;
        RtlAppendUnicodeToString(param_2,L"SBP2\\");
        if (*(longlong *)(param_1 + 0x50) == 0) {
          RtlAppendUnicodeToString(param_2,L"UNKNOWN VENDOR&UNKNOWN MODEL");
        }
        else {
          RtlAppendUnicodeStringToString(param_2,lVar2);
          RtlAppendUnicodeToString(param_2,L"&");
          RtlAppendUnicodeStringToString(param_2,&local_68);
        }
        RtlAppendUnicodeToString(param_2,L"&");
        RtlAppendUnicodeToString(param_2,L"CmdSetId");
        RtlAppendUnicodeStringToString(param_2,&local_38);
        *param_2 = *param_2 + 2;
        if (local_50 != 0) {
          RtlAppendUnicodeToString(param_2,L"SBP2\\");
          if (*(longlong *)(param_1 + 0x50) == 0) {
            RtlAppendUnicodeToString(param_2,L"UNKNOWN VENDOR&UNKNOWN MODEL");
          }
          else {
            RtlAppendUnicodeStringToString(param_2,lVar2);
            RtlAppendUnicodeToString(param_2,L"&");
            RtlAppendUnicodeStringToString(param_2,&local_68);
          }
          RtlAppendUnicodeToString(param_2,L"&");
          RtlAppendUnicodeToString(param_2,L"LUN");
          RtlAppendUnicodeStringToString(param_2,&local_48);
          RtlAppendUnicodeToString(param_2,L"&REV");
          RtlAppendUnicodeStringToString(param_2,&local_58);
          *param_2 = *param_2 + 2;
        }
        RtlAppendUnicodeToString(param_2,L"SBP2\\");
        if (*(longlong *)(param_1 + 0x50) == 0) {
          RtlAppendUnicodeToString(param_2,L"UNKNOWN VENDOR&UNKNOWN MODEL");
        }
        else {
          RtlAppendUnicodeStringToString(param_2,lVar2);
          RtlAppendUnicodeToString(param_2,L"&");
          RtlAppendUnicodeStringToString(param_2,&local_68);
        }
        RtlAppendUnicodeToString(param_2,L"&");
        RtlAppendUnicodeToString(param_2,L"LUN");
        RtlAppendUnicodeStringToString(param_2,&local_48);
        *param_2 = *param_2 + 2;
        RtlAppendUnicodeToString(param_2,L"SBP2\\");
        RtlAppendUnicodeStringToString(param_2,lVar1);
        *param_2 = *param_2 + 2;
        RtlAppendUnicodeStringToString(param_2,lVar1);
        goto LAB_14001de00;
      }
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        uVar3 = 0x69;
        goto LAB_14001d93e;
      }
    }
  }
  uVar4 = 0xc000009a;
LAB_14001de00:
  if (local_50 != 0) {
    ExFreePool();
  }
  if (local_40 != 0) {
    ExFreePool();
  }
  if (local_30 != 0) {
    ExFreePool();
  }
  return uVar4;
}



===== Sbp2_BuildInstanceId @ 14001de68 =====

undefined8 Sbp2_BuildInstanceId(longlong param_1,undefined2 *param_2)

{
  uint uVar1;
  wchar_t *pwVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  *param_2 = 0;
  param_2[1] = 100;
  pwVar2 = (wchar_t *)ExAllocatePool2(0x100,100,0x32706253);
  *(wchar_t **)(param_2 + 4) = pwVar2;
  if (pwVar2 == (wchar_t *)0x0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_(WPP_GLOBAL_Control[3],0x6b,&WPP_2907760f3af034d0edbd0569d145b880_Traceguids);
    }
    uVar3 = 0xc000009a;
  }
  else {
    uVar1 = *(uint *)(*(longlong *)(param_1 + 0x18) + 0xc);
    RtlStringCbPrintfW(pwVar2,(ulonglong)(ushort)param_2[1],L"%08x%08x",
                       (ulonglong)
                       (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 |
                       uVar1 << 0x18));
  }
  return uVar3;
}



===== WppCleanupKm @ 14001df28 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppCleanupKm(void)

{
  undefined8 *puVar1;
  
  if ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    puVar1 = WPP_GLOBAL_Control;
    if (WPPTraceSuite == 4) {
      for (; puVar1 != (undefined8 *)0x0; puVar1 = (undefined8 *)puVar1[2]) {
        if (puVar1[7] != 0) {
          (*pfnEtwUnregister)();
          puVar1[7] = 0;
        }
      }
    }
    else if (WPPTraceSuite == 2) {
      IoWMIRegistrationControl(WPP_GLOBAL_Control,0x80000002);
    }
    WPP_GLOBAL_Control = &WPP_GLOBAL_Control;
  }
  return;
}



===== WppTraceCallback @ 14001dfb0 =====

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



===== wil_details_EvaluateFeatureDependencies @ 14001e238 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  uint uVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  bool bVar5;
  
  puVar4 = (undefined *)0x0;
  ppuVar3 = &Feature_4206787897__private_descriptor;
  ppuVar2 = &Feature_4206787897__private_descriptor;
  do {
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x00014001e273;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_14001e2ed:
  while( true ) {
    if (&UNK_140017797 < ppuVar3) {
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
      if (&UNK_140017797 < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x00014001e273:
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
      if (&UNK_140017797 < ppuVar2) goto LAB_14001e2ed;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_14001e2ed;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14001e328 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_14001e3c0;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_14001e3c0;
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
LAB_14001e3c0:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14001e410 =====

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
      for (ppuVar2 = &Feature_4206787897__private_descriptor;
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
              if (&UNK_140017797 < ppuVar2) {
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14001e490 =====

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
  for (ppuVar3 = &Feature_4206787897__private_descriptor;
      ppuVar3 < &wil_details_featureDescriptors_z; ppuVar3 = ppuVar3 + 1) {
    if (*ppuVar3 != (undefined *)0x0) goto LAB_14001e58d;
  }
LAB_14001e596:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14001e58d:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14001e596;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14001e55e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14001e55e;
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
    if (&UNK_140017797 < ppuVar3) goto LAB_14001e596;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14001e58d;
}



===== Sbp2ConfigLegacyDevice @ 14001e5bc =====

int Sbp2ConfigLegacyDevice(longlong param_1,ulonglong param_2)

{
  longlong lVar1;
  ushort uVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  ushort uVar9;
  ulonglong local_28;
  void *pvStack_20;
  
  puVar8 = (uint *)(param_2 + 0x38);
  *puVar8 = 0;
  local_28 = 0;
  pvStack_20 = (void *)0x0;
  iVar5 = Sbp2GetRegistryValue(param_1,param_2,(int *)puVar8);
  uVar3 = *puVar8;
  uVar2 = *(ushort *)(param_2 + 10);
  uVar9 = uVar2 & 0x1f;
  uVar7 = *(uint *)(param_2 + 0x34) >> 8;
  *puVar8 = uVar3 & 0xfff;
  if (uVar9 == 5) {
    *puVar8 = uVar3 & 0xfff | 0x40;
    RtlInitUnicodeString(&local_28,L"HL-DT-ST");
    if (((ushort)local_28 <= *(ushort *)(param_2 + 0x48)) &&
       (iVar6 = memcmp(pvStack_20,*(void **)(param_2 + 0x50),local_28 & 0xffff), iVar6 == 0)) {
      RtlInitUnicodeString(&local_28,L"GSA-5163D Super Multi DVD Rewriter");
      if (((ushort)local_28 <= *(ushort *)(param_2 + 0x58)) &&
         (iVar6 = memcmp(pvStack_20,*(void **)(param_2 + 0x60),local_28 & 0xffff), iVar6 == 0)) {
        *puVar8 = *puVar8 | 0x400;
      }
    }
    goto LAB_14001e92d;
  }
  RtlInitUnicodeString(&local_28,L"VGP-XL1B");
  lVar1 = param_2 + 0x58;
  cVar4 = RtlEqualUnicodeString(&local_28,lVar1,1);
  if (cVar4 != '\0') {
    *puVar8 = *puVar8 | 0x120;
  }
  if ((uVar9 != 0xe) && ((uVar2 & 0x1f) != 0)) goto LAB_14001e92d;
  *puVar8 = *puVar8 | 0x40;
  RtlInitUnicodeString(&local_28,L"TI STORAGELYNX!!");
  cVar4 = RtlEqualUnicodeString(&local_28,lVar1,1);
  if (cVar4 != '\0') {
    *puVar8 = *puVar8 | 0x10;
  }
  RtlInitUnicodeString(&local_28,L"FireREX Storage");
  cVar4 = RtlEqualUnicodeString(&local_28,lVar1,1);
  if (cVar4 != '\0') {
    *puVar8 = *puVar8 | 0x20;
  }
  puVar8 = (uint *)(param_2 + 0x38);
  RtlInitUnicodeString(&local_28,L"Prolific");
  if ((ushort)local_28 <= *(ushort *)(param_2 + 0x48)) {
    iVar6 = memcmp(pvStack_20,*(void **)(param_2 + 0x50),local_28 & 0xffff);
    if (iVar6 == 0) {
      *puVar8 = *puVar8 | 0x200;
    }
  }
  RtlInitUnicodeString(&local_28,L"PL3507");
  if ((ushort)local_28 <= *(ushort *)(param_2 + 0x48)) {
    iVar6 = memcmp(pvStack_20,*(void **)(param_2 + 0x50),local_28 & 0xffff);
    if (iVar6 == 0) {
      *puVar8 = *puVar8 | 0x200;
    }
  }
  RtlInitUnicodeString(&local_28,L"Iomega");
  if ((ushort)local_28 <= *(ushort *)(param_2 + 0x48)) {
    iVar6 = memcmp(pvStack_20,*(void **)(param_2 + 0x50),local_28 & 0xffff);
    if (iVar6 == 0) {
      RtlInitUnicodeString(&local_28,L"HDD USB 2.0/1394A");
      if ((ushort)local_28 <= *(ushort *)(param_2 + 0x58)) {
        iVar6 = memcmp(pvStack_20,*(void **)(param_2 + 0x60),local_28 & 0xffff);
        if (iVar6 == 0) {
          *(uint *)(param_2 + 0x38) = *(uint *)(param_2 + 0x38) | 0x200;
        }
      }
    }
  }
  if ((uVar7 == 0) && (0x25 < *(uint *)(param_2 + 0x34))) {
    *(uint *)(param_2 + 0x38) = *(uint *)(param_2 + 0x38) | 0x80;
  }
  if ((-1 < iVar5) && ((*(uint *)(param_2 + 0x38) & 0xf) != 0)) goto LAB_14001e92d;
  if (uVar7 == 0) {
    if (*(uint *)(param_2 + 0x34) < 0x26) goto LAB_14001e88c;
  }
  else if ((((uVar7 == 0x28) || (uVar7 == 0x29)) || (uVar7 == 0x1001)) || (uVar7 == 0xa0b8)) {
LAB_14001e88c:
    *(uint *)(param_2 + 0x38) = *(uint *)(param_2 + 0x38) | 1;
  }
  RtlInitUnicodeString(&local_28,L"iPod");
  cVar4 = RtlEqualUnicodeString(&local_28,param_2 + 0x58,1);
  if (cVar4 == '\0') {
    RtlInitUnicodeString(&local_28,L"FireLite Drive  ");
    cVar4 = RtlEqualUnicodeString(&local_28,param_2 + 0x58,1);
    if (cVar4 == '\0') {
      RtlInitUnicodeString(&local_28,L"Prolific");
      if ((*(ushort *)(param_2 + 0x48) < (ushort)local_28) ||
         (iVar6 = memcmp(pvStack_20,*(void **)(param_2 + 0x50),local_28 & 0xffff), iVar6 != 0))
      goto LAB_14001e92d;
    }
  }
  *(uint *)(param_2 + 0x38) = *(uint *)(param_2 + 0x38) | 1;
LAB_14001e92d:
  uVar3 = *(uint *)(param_2 + 0x38);
  if ((uVar3 & 8) != 0) {
    *(undefined4 *)(param_2 + 0x30) = 0x100000;
  }
  if ((uVar3 & 4) != 0) {
    *(undefined4 *)(param_2 + 0x30) = 0x80000;
  }
  if ((uVar3 & 2) != 0) {
    *(undefined4 *)(param_2 + 0x30) = 0x40000;
  }
  if ((uVar3 & 1) != 0) {
    *(undefined4 *)(param_2 + 0x30) = 0x20000;
  }
  return iVar5;
}



===== Sbp2GetRegistryValue @ 14001e984 =====

int Sbp2GetRegistryValue(longlong param_1,ulonglong param_2,int *param_3)

{
  int iVar1;
  longlong lVar2;
  undefined2 uVar3;
  ulonglong local_res10;
  longlong local_res20;
  int iVar4;
  undefined8 local_28;
  longlong local_20;
  
  local_res20 = 0;
  local_28 = 0;
  local_res10 = param_2 & 0xffffffff00000000;
  local_20 = 0;
  iVar1 = IoOpenDeviceRegistryKey(param_1,1,0x20019,&local_res20);
  if (-1 < iVar1) {
    local_28._0_4_ = CONCAT22(0x80,(undefined2)local_28);
    local_20 = ExAllocatePool2(0x40,0x80,0x32706253);
    if (local_20 != 0) {
      lVar2 = ExAllocatePool2(0x40,0x14,0x32706253);
      if (lVar2 != 0) {
        RtlAppendUnicodeToString(&local_28,L"LegacyFlags");
        iVar1 = ZwQueryValueKey(local_res20,&local_28,2,lVar2,0x14,&local_res10);
        if (iVar1 < 0) {
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            uVar3 = 0x19;
            iVar4 = iVar1;
            goto LAB_14001eacb;
          }
        }
        else {
          iVar4 = *(int *)(lVar2 + 0xc);
          *param_3 = iVar4;
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            uVar3 = 0x18;
LAB_14001eacb:
            WPP_SF_qd(WPP_GLOBAL_Control[3],uVar3,&WPP_5dde293d94fa35ece92636ed4f4e222d_Traceguids,
                      *(undefined8 *)(param_1 + 0x40),(char)iVar4);
          }
        }
        ExFreePool(lVar2);
        goto LAB_14001eaee;
      }
    }
  }
  iVar1 = -0x3fffff66;
LAB_14001eaee:
  if (local_res20 != 0) {
    ZwClose();
  }
  if (local_20 != 0) {
    ExFreePool();
  }
  return iVar1;
}



===== Sbp2BuildAdapterDescriptor @ 14001eb34 =====

undefined8 Sbp2BuildAdapterDescriptor(longlong param_1,undefined8 *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined8 uStack_20;
  undefined8 uStack_18;
  undefined8 uStack_10;
  
  uStack_10 = 0;
  uVar1 = *param_3;
  uStack_20 = 0;
  uStack_18 = 0;
  uVar4 = 0x1e;
  if (uVar1 - 0x1e < 2) {
    local_28 = 0x1e;
    uStack_24 = 0x1e;
  }
  else {
    local_28 = 0x20;
    uStack_24 = 0x20;
  }
  if (uVar1 < 0x1e) {
    memmove(param_2,&local_28,(ulonglong)uVar1);
  }
  else {
    uVar2 = *(uint *)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x58) + 0x30);
    uVar3 = uVar2 >> 0xc;
    if (uVar3 < 0x1ff) {
      uVar3 = uVar3 + 1;
    }
    uStack_20 = CONCAT44(uVar3,uVar2);
    *param_2 = CONCAT44(uStack_24,local_28);
    param_2[1] = uStack_20;
    if (uVar1 < 0x20) {
      param_2[2] = 0x101000000000003;
      *(undefined4 *)(param_2 + 3) = 0x10004;
      *(undefined2 *)((longlong)param_2 + 0x1c) = 0;
    }
    else {
      uVar4 = 0x20;
      param_2[2] = 0x101000000000003;
      param_2[3] = 0x10004;
    }
    *param_3 = uVar4;
  }
  return 0;
}



===== Sbp2BuildDeviceDescriptor @ 14001ec14 =====

undefined4 Sbp2BuildDeviceDescriptor(longlong param_1,void *param_2,int *param_3,undefined8 param_4)

{
  char *pcVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  size_t _Size;
  undefined4 local_48;
  undefined4 local_44;
  byte local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined1 local_3d;
  undefined8 local_3c;
  undefined8 uStack_34;
  undefined4 local_2c;
  undefined8 local_28;
  
  iVar2 = *param_3;
  _Size = (size_t)iVar2;
  lVar3 = *(longlong *)(param_1 + 0x40);
  uVar5 = 0;
  memset(param_2,0,_Size);
  local_40 = *(byte *)(lVar3 + 0x110) & 0x1f;
  local_28 = 0;
  local_48 = 0x28;
  local_3c = 0;
  uStack_34 = 0;
  local_44 = 0x58;
  local_3f = 0;
  if ((*(char *)(lVar3 + 0x111) < '\0') || (local_40 == 5)) {
    *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) | 1;
    local_3e = 1;
  }
  else {
    local_3e = 0;
  }
  local_2c = 4;
  local_3d = 1;
  if (0x28 < _Size) {
    _Size = 0x28;
  }
  memmove(param_2,&local_48,_Size);
  if (0 < (int)(iVar2 - 0x28U)) {
    pcVar1 = (char *)(lVar3 + 0x118);
    if (*pcVar1 == '\0') {
      RtlStringCbPrintfA(pcVar1,8,"Vendor",param_4);
      RtlStringCbPrintfA((char *)(lVar3 + 0x120),0x10,"Sbp2",param_4);
      RtlStringCbPrintfA((char *)(lVar3 + 0x130),4,"1.0",param_4);
      uVar5 = 0;
      if ((*(byte *)(lVar3 + 0x14) & 0x10) != 0) {
        uVar5 = 0x80000011;
      }
    }
    if (8 < iVar2 - 0x28U) {
      *(undefined8 *)((longlong)param_2 + 0x28) = *(undefined8 *)pcVar1;
      *(int *)((longlong)param_2 + 0xc) =
           (int)(undefined8 *)((longlong)param_2 + 0x28) - (int)param_2;
      if (0x10 < iVar2 - 0x31U) {
        uVar4 = *(undefined8 *)(lVar3 + 0x128);
        *(undefined8 *)((longlong)param_2 + 0x31) = *(undefined8 *)(lVar3 + 0x120);
        *(undefined8 *)((longlong)param_2 + 0x39) = uVar4;
        *(undefined4 *)((longlong)param_2 + 0x10) = 0x31;
        if (4 < iVar2 - 0x42U) {
          *(undefined4 *)((longlong)param_2 + 0x42) = *(undefined4 *)(lVar3 + 0x130);
          *(undefined4 *)((longlong)param_2 + 0x14) = 0x42;
          if (0x10 < iVar2 + -0x47) {
            RtlStringCbPrintfA((char *)((longlong)param_2 + 0x47),(longlong)(iVar2 + -0x47),
                               "%08x%08x",
                               (ulonglong)
                               *(uint *)(*(longlong *)(*(longlong *)(lVar3 + 0x58) + 0x18) + 0xc));
            *param_3 = 0x58;
            *(int *)((longlong)param_2 + 0x18) =
                 (int)(char *)((longlong)param_2 + 0x47) - (int)param_2;
          }
        }
      }
      return uVar5;
    }
  }
  return 0;
}



===== Sbp2QueryProperty @ 14001edec =====

ulonglong Sbp2QueryProperty(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  int *piVar3;
  uint *_Dst;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  uint local_res8 [2];
  
  uVar6 = 0;
  piVar3 = *(int **)(param_2 + 0x18);
  uVar5 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  local_res8[0] = uVar5;
  if (piVar3[1] < 2) {
    lVar1 = *(longlong *)(param_1 + 0x40) + 0x18;
    uVar8 = 1;
    uVar4 = IoAcquireRemoveLockEx(lVar1,0,"",1,0x20);
    uVar7 = (ulonglong)uVar4;
    if (-1 < (int)uVar4) {
      iVar2 = *piVar3;
      if (iVar2 == 0) {
        if (piVar3[1] == 1) goto LAB_14001ef34;
        uVar5 = Sbp2BuildDeviceDescriptor
                          (param_1,*(void **)(param_2 + 0x18),(int *)local_res8,uVar8);
        uVar7 = (ulonglong)uVar5;
        uVar6 = (ulonglong)local_res8[0];
LAB_14001ef4f:
        *(ulonglong *)(param_2 + 0x38) = uVar6;
      }
      else if (iVar2 == 1) {
        if (piVar3[1] == 1) goto LAB_14001ef34;
        uVar7 = Sbp2BuildAdapterDescriptor(param_1,*(undefined8 **)(param_2 + 0x18),local_res8);
        uVar7 = uVar7 & 0xffffffff;
        *(ulonglong *)(param_2 + 0x38) = (ulonglong)local_res8[0];
      }
      else if (iVar2 == 5) {
        if (piVar3[1] != 1) {
          _Dst = *(uint **)(param_2 + 0x18);
          if (uVar5 < 8) {
            uVar7 = 0xc0000010;
          }
          else {
            uVar4 = 0x10;
            if (uVar5 < 0x10) {
              *_Dst = 0x18;
              _Dst[1] = 0x18;
              uVar7 = 0;
              uVar6 = 8;
            }
            else {
              memset(_Dst,0,(ulonglong)uVar5);
              _Dst[2] = 6;
              _Dst[3] = 0x100;
              if (0x17 < uVar5) {
                *(undefined1 *)(_Dst + 4) = 0;
                uVar4 = 0x18;
              }
              *_Dst = uVar4;
              _Dst[1] = uVar4;
              uVar7 = 0;
              uVar6 = (ulonglong)uVar4;
            }
          }
          goto LAB_14001ef4f;
        }
LAB_14001ef34:
        uVar7 = 0;
      }
      else {
        uVar7 = 0xc00000ef;
        *(undefined8 *)(param_2 + 0x38) = 0;
      }
      *(int *)(param_2 + 0x30) = (int)uVar7;
      IoReleaseRemoveLockEx(lVar1,0,0x20);
      uVar8 = 1;
      goto LAB_14001ef6d;
    }
    *(uint *)(param_2 + 0x30) = uVar4;
  }
  else {
    uVar7 = 0xc00000ef;
    *(undefined4 *)(param_2 + 0x30) = 0xc00000ef;
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  uVar8 = 0;
LAB_14001ef6d:
  IofCompleteRequest(param_2,uVar8);
  return uVar7;
}



===== Sbp2ScsiPassThrough @ 14001ef9c =====

undefined8 Sbp2ScsiPassThrough(longlong *param_1,longlong param_2,char param_3)

{
  byte *pbVar1;
  uint uVar2;
  longlong *plVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined1 uVar7;
  undefined8 in_stack_ffffffffffffffe8;
  
  plVar3 = (longlong *)param_1[8];
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
     (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    uVar7 = SUB81(param_1,0);
    param_1 = plVar3;
    WPP_SF_qq(WPP_GLOBAL_Control[3],0x3d,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids,plVar3,
              uVar7);
  }
  if ((*(char *)(*(longlong *)(param_2 + 0xb8) + 1) == '\0') &&
     ((*(uint *)((longlong)plVar3 + 0x14) & 0x20) != 0)) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_(WPP_GLOBAL_Control[3],0x3e,&WPP_5644a60b4c6c380c3af4903fe075ecfb_Traceguids);
    }
    uVar6 = 0xc0000010;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
    IofCompleteRequest(param_2,0);
  }
  else {
    uVar2 = *(uint *)(plVar3[0xb] + 0x30);
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    uVar5 = uVar2 >> 0xc;
    uVar4 = uVar5 + 1;
    if (0x1fe < uVar5) {
      uVar4 = uVar5;
    }
    PortPassThroughSendAsync
              (*plVar3,param_2,param_3,param_1,uVar4,uVar2,in_stack_ffffffffffffffe8,plVar3);
    uVar6 = 0x103;
  }
  return uVar6;
}



===== PortPassThroughSendAsync @ 14001f0b8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PortPassThroughSendAsync
              (longlong param_1,longlong param_2,char param_3,undefined8 param_4,uint param_5,
              uint param_6,undefined8 param_7,undefined8 param_8)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined4 *puVar6;
  longlong lVar7;
  char *pcVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  undefined1 auStackY_118 [32];
  ushort local_b0 [3];
  char cStack_a9;
  undefined4 uStack_a8;
  uint uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  ulonglong uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_118;
  local_80 = 0;
  local_48 = 0;
  pcVar8 = (char *)0x0;
  _local_b0 = 0;
  uStack_a8 = 0;
  uStack_a4 = 0;
  uStack_a0 = 0;
  uStack_9c = 0;
  uStack_98 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  uVar4 = PortPassThroughNormalize((undefined8 *)local_b0,param_2);
  uVar10 = uStack_98;
  uVar1 = uStack_a4;
  iVar3 = (int)uVar4;
  if (-1 < iVar3) {
    uVar4 = PortPassThroughValidateNormalizedRequest(local_b0,param_2,param_3);
    iVar3 = (int)uVar4;
    if (-1 < iVar3) {
      PortpPassThroughZeroUnusedBuffers(param_2);
      if (uVar1 == 0) {
        uVar9 = 0;
      }
      else if (param_3 == '\0') {
        uVar9 = *(longlong *)(param_2 + 0x18) + uVar10;
      }
      else {
        uVar9 = uVar10;
      }
      if (((uVar9 & *(uint *)(param_1 + 0x98)) != 0) ||
         ((uVar1 != 0 &&
          ((param_5 < (uint)((ulonglong)((uint)uVar9 & 0xfff) + (ulonglong)uVar1 + 0xfff >> 0xc) ||
           (param_6 < uVar1)))))) {
        iVar3 = -0x3ffffff3;
        goto LAB_14001f18c;
      }
    }
  }
  if (iVar3 < 0) goto LAB_14001f18c;
  if (uVar1 == 0) {
    uVar10 = 0;
    if (param_3 == '\0') goto LAB_14001f1f8;
LAB_14001f233:
    cVar2 = *(char *)(param_2 + 0x40);
  }
  else {
    if (param_3 != '\0') goto LAB_14001f233;
    uVar10 = uVar10 + *(longlong *)(param_2 + 0x18);
LAB_14001f1f8:
    cVar2 = '\0';
  }
  lVar5 = PortPassThroughBuildIrpEx(param_1,uVar10,uVar1,(char)uStack_a8 != '\0',cVar2,param_2);
  if (lVar5 == 0) {
    iVar3 = -0x3fffff66;
    goto LAB_14001f18c;
  }
  lVar7 = 0;
  uVar4 = 0x69506c50;
  puVar6 = (undefined4 *)ExAllocatePool2(0x40,0x58);
  if (puVar6 == (undefined4 *)0x0) {
LAB_14001f29c:
    iVar3 = -0x3fffff66;
  }
  else {
    if (cStack_a9 != '\0') {
      uVar4 = 0x69506c50;
      lVar7 = ExAllocatePool2(0x48,cStack_a9);
      if (lVar7 == 0) {
        ExFreePoolWithTag(puVar6,0x69506c50);
        puVar6 = (undefined4 *)0x0;
        goto LAB_14001f29c;
      }
    }
    PortPassThroughSrbInitialize(puVar6,(longlong)local_b0,uVar4,uVar10,lVar7);
    *(undefined4 **)(*(longlong *)(lVar5 + 0xb8) + -0x40) = puVar6;
    *(longlong *)(puVar6 + 0xc) = lVar5;
    pcVar8 = (char *)ExAllocatePool2(0x40,0x30,0x69506c50);
    if (pcVar8 == (char *)0x0) goto LAB_14001f29c;
    *(undefined4 **)(pcVar8 + 0x18) = puVar6;
    *(longlong *)(pcVar8 + 8) = lVar5;
    *pcVar8 = param_3;
    *(longlong *)(pcVar8 + 0x10) = param_2;
    *(code **)(pcVar8 + 0x20) = Sbp2ScsiPassThroughCompletion;
    *(undefined8 *)(pcVar8 + 0x28) = param_8;
    lVar7 = *(longlong *)(lVar5 + 0xb8);
    *(code **)(lVar7 + -0x10) = PortpAsyncCompletion;
    *(char **)(lVar7 + -8) = pcVar8;
    *(undefined1 *)(lVar7 + -0x45) = 0xe0;
    uVar4 = PortpEnableCancel(param_2,(longlong)pcVar8);
    iVar3 = (int)uVar4;
    if (iVar3 == 0x103) {
      IofCallDriver(param_1,lVar5);
      return 0x103;
    }
  }
  PortPassThroughFreeIrpEx(lVar5);
  if (puVar6 != (undefined4 *)0x0) {
    PortPassThroughFreeSrb((longlong)puVar6);
  }
  if (pcVar8 != (char *)0x0) {
    ExFreePoolWithTag(pcVar8,0x69506c50);
  }
LAB_14001f18c:
  *(int *)(param_2 + 0x30) = iVar3;
  Sbp2ScsiPassThroughCompletion(param_2);
  return iVar3;
}



===== PortPassThroughSrbInitialize @ 14001f3a0 =====

void PortPassThroughSrbInitialize
               (undefined4 *param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
               longlong param_5)

{
  undefined4 uVar1;
  uint uVar2;
  
  memset(param_1 + 1,0,0x54);
  *param_1 = 0x58;
  *(undefined1 *)((longlong)param_1 + 5) = *(undefined1 *)(param_2 + 3);
  *(undefined1 *)((longlong)param_1 + 6) = *(undefined1 *)(param_2 + 4);
  *(undefined1 *)((longlong)param_1 + 7) = *(undefined1 *)(param_2 + 5);
  *(undefined1 *)((longlong)param_1 + 10) = *(undefined1 *)(param_2 + 6);
  *(undefined1 *)((longlong)param_1 + 0xb) = *(undefined1 *)(param_2 + 7);
  if (*(int *)(param_2 + 0xc) == 0) {
    uVar2 = 0;
  }
  else if (*(char *)(param_2 + 8) == '\0') {
    uVar2 = 0x80;
  }
  else if (*(char *)(param_2 + 8) == '\x01') {
    uVar2 = 0x40;
  }
  else {
    uVar2 = 0xc0;
  }
  if (param_5 == 0) {
    uVar2 = uVar2 | 0x20;
  }
  param_1[3] = uVar2 | 0x100;
  param_1[4] = *(undefined4 *)(param_2 + 0xc);
  uVar1 = *(undefined4 *)(param_2 + 0x10);
  *(longlong *)(param_1 + 8) = param_5;
  *(undefined8 *)(param_1 + 0xc) = 0;
  param_1[5] = uVar1;
  *(undefined8 *)(param_1 + 6) = param_4;
  memmove(param_1 + 0x12,(void *)(param_2 + 0x24),(ulonglong)*(byte *)(param_2 + 6));
  return;
}



===== PortPassThroughValidateNormalizedRequest @ 14001f46c =====

undefined8 PortPassThroughValidateNormalizedRequest(ushort *param_1,longlong param_2,char param_3)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  
  uVar5 = (ulonglong)*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  uVar2 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  if (0x10 < (byte)param_1[3]) {
    return 0xc000000d;
  }
  if (*(byte *)((longlong)param_1 + 7) != 0) {
    uVar3 = *(uint *)(param_1 + 0x10);
    uVar6 = uVar3 + *(byte *)((longlong)param_1 + 7);
    if (uVar6 < uVar3) {
      return 0xc000000d;
    }
    if (uVar3 < *param_1) {
      return 0xc000000d;
    }
    if ((param_3 == '\0') && (*(int *)(param_1 + 6) != 0)) {
      if (*(ulonglong *)(param_1 + 0xc) <= (ulonglong)uVar3) {
        return 0xc000000d;
      }
      if (*(ulonglong *)(param_1 + 0xc) < (ulonglong)uVar6) {
        return 0xc000000d;
      }
    }
    if (uVar2 < uVar3) {
      return 0xc000000d;
    }
    if (uVar2 < uVar6) {
      return 0xc000000d;
    }
  }
  if (param_3 == '\0') {
    uVar4 = *(ulonglong *)(param_1 + 0xc);
    if ((uVar4 < *param_1) && (*(int *)(param_1 + 6) != 0)) {
      return 0xc000000d;
    }
    if ((char)param_1[4] != '\x01') {
      if (*(uint *)(param_1 + 6) != 0) {
        if (uVar5 < uVar4) {
          return 0xc000000d;
        }
        if (uVar5 < *(uint *)(param_1 + 6) + uVar4) {
          return 0xc000000d;
        }
      }
      if ((char)param_1[4] == '\0') goto LAB_14001f538;
    }
    if (*(uint *)(param_1 + 6) != 0) {
      if (uVar2 < uVar4) {
        return 0xc000000d;
      }
      if ((ulonglong)uVar2 < *(uint *)(param_1 + 6) + uVar4) {
        return 0xc000000d;
      }
    }
  }
  else if ((*(longlong *)(param_1 + 0xc) == 0) && (*(int *)(param_1 + 6) != 0)) {
    return 0xc000000d;
  }
LAB_14001f538:
  if (0x1a5df < *(int *)(param_1 + 8) - 1U) {
    return 0xc000000d;
  }
  cVar1 = (char)param_1[0x12];
  if ((cVar1 == '\x18') || (cVar1 == '9')) {
    return 0xc0000010;
  }
  if (cVar1 == ':') {
    return 0xc0000010;
  }
  return 0;
}



===== entry @ 140020010 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 140020044 =====

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



===== wil_InitializeFeatureStaging @ 140020078 =====

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
    for (ppuVar3 = &Feature_4206787897__private_descriptor;
        ppuVar3 < &wil_details_featureDescriptors_z; ppuVar3 = ppuVar3 + 1) {
      if (*ppuVar3 != (undefined *)0x0) goto LAB_1400200ff;
    }
LAB_140020139:
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
LAB_1400200ff:
  if (ppuVar3 == (undefined **)0x0) goto LAB_140020139;
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
    goto LAB_140020139;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_140017797 < ppuVar3) goto LAB_140020139;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_1400200ff;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14002018c =====

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
  ppuVar4 = &Feature_4206787897__private_descriptor;
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
            if (&UNK_140017797 < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_140020276;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_140020276;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_140020276:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_140017797 < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


