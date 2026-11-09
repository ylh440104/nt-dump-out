
===== __report_gsfailure @ 1c0001010 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 1c000101d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001c000101d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== KbdHid_Flush @ 1c0001030 =====

int KbdHid_Flush(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong lVar4;
  int iVar5;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar1 = lVar2 + 0x98;
  iVar5 = IoAcquireRemoveLockEx(lVar1,param_2,"",1,0x20);
  if (iVar5 < 0) {
    *(int *)(param_2 + 0x30) = iVar5;
    IofCompleteRequest(param_2,0);
  }
  else {
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
    lVar4 = *(longlong *)(param_2 + 0xb8);
    *(undefined1 *)(lVar4 + -0x48) = 0xe;
    *(undefined4 *)(lVar4 + -0x30) = 0xb0197;
    iVar5 = IofCallDriver(*(undefined8 *)(lVar2 + 8),param_2);
    IoReleaseRemoveLockEx(lVar1,param_2,0x20);
  }
  return iVar5;
}



===== KbdHid_IOCTL @ 1c0001120 =====

ulonglong KbdHid_IOCTL(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  ushort uVar2;
  ushort uVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined4 *puVar6;
  undefined2 *puVar7;
  uint uVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  undefined2 uVar11;
  undefined8 in_stack_ffffffffffffffb8;
  undefined8 uVar12;
  undefined1 uVar13;
  
  puVar4 = *(undefined8 **)(param_1 + 0x40);
  puVar1 = (undefined8 *)(param_2 + 0x38);
  lVar5 = *(longlong *)(param_2 + 0xb8);
  uVar12 = CONCAT44((int)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20),0x20);
  *puVar1 = 0;
  uVar8 = IoAcquireRemoveLockEx(puVar4 + 0x13,param_2,"",1);
  uVar9 = (ulonglong)uVar8;
  if ((int)uVar8 < 0) {
    *(uint *)(param_2 + 0x30) = uVar8;
    IofCompleteRequest(param_2,0);
    return uVar9;
  }
  uVar8 = *(uint *)(lVar5 + 0x18);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  uVar10 = 0;
  uVar13 = (undefined1)param_2;
  if (uVar8 < 0xb0081) {
    if (uVar8 == 0xb0080) {
      if (*(uint *)(lVar5 + 8) < 0xe) {
        uVar9 = 0xc0000023;
      }
      else {
        puVar7 = *(undefined2 **)(param_2 + 0x18);
        *puVar7 = 3;
        memcpy(puVar7 + 1,&DAT_1c0009330,0xc);
        *puVar1 = 0xe;
        uVar9 = 0;
      }
    }
    else if (uVar8 == 0xb0000) {
      if (*(uint *)(lVar5 + 8) < 0x1c) {
        uVar9 = 0xc0000023;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar11 = 0xe;
          goto LAB_1c00014ca;
        }
      }
      else {
        uVar8 = KbdHid_WaitForExtendedAttributesQueryCompletion
                          ((longlong)puVar4,&WPP_RECORDER_INITIALIZED,0);
        uVar9 = (ulonglong)uVar8;
        if ((int)uVar8 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_Lqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,uVar10,0xf,uVar12,0,
                                uVar13,(char)uVar8);
          }
          uVar9 = 0;
        }
        uVar12 = puVar4[0x24];
        puVar1 = *(undefined8 **)(param_2 + 0x18);
        *puVar1 = puVar4[0x23];
        puVar1[1] = uVar12;
        puVar1[2] = puVar4[0x25];
        *(undefined4 *)(puVar1 + 3) = *(undefined4 *)(puVar4 + 0x26);
        *(undefined8 *)(param_2 + 0x38) = 0x1c;
      }
    }
    else if (uVar8 == 0xb0004) {
      if (*(uint *)(lVar5 + 0x10) < 6) {
        uVar9 = 0xc000000d;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar11 = 0x12;
LAB_1c000136c:
          uVar9 = 0xc000000d;
          goto LAB_1c000127f;
        }
      }
      else {
        lVar5 = *(longlong *)(param_2 + 0x18);
        uVar2 = *(ushort *)(lVar5 + 2);
        if ((uVar2 != 0) || (*(short *)(lVar5 + 4) != 0)) {
          if ((*(ushort *)((longlong)puVar4 + 0x12a) <= uVar2) &&
             (uVar2 <= *(ushort *)(puVar4 + 0x26))) {
            uVar3 = *(ushort *)(lVar5 + 4);
            if ((*(ushort *)((longlong)puVar4 + 300) <= uVar3) &&
               (uVar3 <= *(ushort *)((longlong)puVar4 + 0x132))) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,(ulonglong)uVar3,
                                   0x14,uVar12,(char)uVar2,(char)uVar3);
              }
              puVar6 = *(undefined4 **)(param_2 + 0x18);
              *(undefined4 *)((longlong)puVar4 + 0x164) = *puVar6;
              *(undefined2 *)(puVar4 + 0x2d) = *(undefined2 *)(puVar6 + 1);
              *(uint *)(puVar4 + 0x3f) = 1000 / *(ushort *)(*(longlong *)(param_2 + 0x18) + 2);
              uVar2 = *(ushort *)(*(longlong *)(param_2 + 0x18) + 4);
              *(undefined4 *)((longlong)puVar4 + 500) = 0xffffffff;
              *(uint *)(puVar4 + 0x3e) = (uint)uVar2 * -10000;
              goto LAB_1c000129e;
            }
          }
          uVar9 = 0xc000000d;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar11 = 0x13;
            goto LAB_1c000136c;
          }
        }
      }
    }
    else if (uVar8 == 0xb0008) {
      if (3 < *(uint *)(lVar5 + 0x10)) {
        uVar9 = KbdHid_SetLedIndicators(puVar4,*(longlong *)(param_2 + 0x18),param_2);
        uVar9 = uVar9 & 0xffffffff;
        goto LAB_1c00012b2;
      }
      uVar9 = 0xc000000d;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar11 = 0x10;
        goto LAB_1c000136c;
      }
    }
    else if (uVar8 == 0xb0020) {
      if (5 < *(uint *)(lVar5 + 8)) {
        puVar6 = *(undefined4 **)(param_2 + 0x18);
        *puVar6 = *(undefined4 *)((longlong)puVar4 + 0x164);
        *(undefined2 *)(puVar6 + 1) = *(undefined2 *)(puVar4 + 0x2d);
        *puVar1 = 6;
        goto LAB_1c0001344;
      }
      uVar9 = 0xc0000023;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar11 = 0x11;
        goto LAB_1c000127f;
      }
    }
    else {
      if (uVar8 != 0xb0040) goto LAB_1c00015d0;
      if (*(uint *)(lVar5 + 8) < 4) {
        uVar9 = 0xc0000023;
      }
      else {
        uVar9 = 0;
        **(undefined4 **)(param_2 + 0x18) = *(undefined4 *)(puVar4 + 0x2c);
        *puVar1 = 4;
      }
    }
  }
  else if (uVar8 == 0xb0200) {
    if (*(uint *)(lVar5 + 8) < 7) {
      uVar9 = 0xc0000023;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar11 = 0x15;
LAB_1c00014ca:
        uVar9 = 0xc0000023;
        WPP_RECORDER_SF_Lqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0,uVar11,uVar12,0,uVar13,
                            0x23);
      }
    }
    else {
      uVar8 = KbdHid_WaitForExtendedAttributesQueryCompletion
                        ((longlong)puVar4,&WPP_RECORDER_INITIALIZED,0);
      uVar9 = (ulonglong)uVar8;
      if ((int)uVar8 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_Lqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar10,0x16,uVar12,0,
                              uVar13,(char)uVar8);
        }
      }
      else {
        puVar6 = *(undefined4 **)(param_2 + 0x18);
        *puVar6 = *(undefined4 *)((longlong)puVar4 + 0x134);
        *(undefined2 *)(puVar6 + 1) = *(undefined2 *)(puVar4 + 0x27);
        *(undefined1 *)((longlong)puVar6 + 6) = *(undefined1 *)((longlong)puVar4 + 0x13a);
        *(undefined8 *)(param_2 + 0x38) = 7;
      }
    }
  }
  else if (uVar8 == 0xb0203) {
    if (puVar4[0x12] == 0) {
      if (*(uint *)(lVar5 + 0x10) < 0x10) {
        uVar9 = 0xc000000d;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar11 = 0xd;
          goto LAB_1c000136c;
        }
      }
      else {
        uVar12 = (*(undefined8 **)(lVar5 + 0x20))[1];
        puVar4[0x11] = **(undefined8 **)(lVar5 + 0x20);
        puVar4[0x12] = uVar12;
LAB_1c0001344:
        uVar9 = 0;
      }
    }
    else {
      uVar9 = 0xc0000043;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar11 = 0xc;
LAB_1c000127f:
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,uVar11,uVar12,(char)uVar9);
      }
    }
  }
  else if (uVar8 == 0xb0403) {
    uVar9 = 0xc0000002;
  }
  else if ((uVar8 == 0xb0803) || (uVar8 == 0xb1003)) {
    uVar9 = 0xc00000bb;
  }
  else {
LAB_1c00015d0:
    uVar9 = 0xc0000010;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_Dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
LAB_1c000129e:
  *(int *)(param_2 + 0x30) = (int)uVar9;
  IofCompleteRequest(param_2,0);
LAB_1c00012b2:
  IoReleaseRemoveLockEx(puVar4 + 0x13,param_2,0x20);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x18,
                     &WPP_a3eb93ac5d7d3982e3cdea956b1ca812_Traceguids);
  }
  return uVar9;
}



===== KbdHid_PassThrough @ 1c0001730 =====

int KbdHid_PassThrough(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar1 = lVar2 + 0x98;
  iVar3 = IoAcquireRemoveLockEx(lVar1,param_2,"",1,0x20);
  if (iVar3 < 0) {
    *(int *)(param_2 + 0x30) = iVar3;
    IofCompleteRequest(param_2,0);
  }
  else {
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    iVar3 = IofCallDriver(*(undefined8 *)(lVar2 + 8),param_2);
    IoReleaseRemoveLockEx(lVar1,param_2,0x20);
  }
  return iVar3;
}



===== KbdHid_SetLedIndicators @ 1c00017e8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong KbdHid_SetLedIndicators(undefined8 *param_1,longlong param_2,longlong param_3)

{
  ushort uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  uint uVar4;
  int iVar5;
  longlong *plVar6;
  longlong lVar7;
  longlong lVar8;
  ulonglong uVar9;
  bool bVar10;
  undefined1 auStackY_98 [32];
  uint local_58;
  undefined2 local_48 [4];
  ulonglong local_40;
  
  local_40 = ___security_cookie ^ (ulonglong)auStackY_98;
  lVar2 = param_1[0xe];
  plVar6 = (longlong *)0x0;
  lVar8 = 0;
  uVar4 = IoAcquireRemoveLockEx(param_1 + 0x13,param_3,"",1);
  if ((int)uVar4 < 0) {
    *(uint *)(param_3 + 0x30) = uVar4;
    IofCompleteRequest(param_3,0);
    return (ulonglong)uVar4;
  }
  uVar9 = 0;
  if (*(char *)(param_1 + 0xb) == '\0') {
    uVar9 = 0xc0000184;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x19,
                          &WPP_a3eb93ac5d7d3982e3cdea956b1ca812_Traceguids,(char)*param_1,
                          (char)param_3,0x84);
    }
  }
  else if (*(short *)(lVar2 + 0xe) != 0) {
    plVar6 = (longlong *)ExAllocatePool2(0x40,0x10,0x4864624b);
    if (plVar6 != (longlong *)0x0) {
      lVar7 = ExAllocatePool2(0x40,*(undefined2 *)(lVar2 + 0xe),0x4864624b);
      *plVar6 = lVar7;
      if ((lVar7 != 0) &&
         (lVar8 = IoAllocateMdl(lVar7,*(undefined2 *)(lVar2 + 0xe),0,0), lVar8 != 0)) {
        MmBuildMdlForNonPagedPool(lVar8);
        uVar1 = *(ushort *)(param_2 + 2);
        bVar10 = (uVar1 & 4) != 0;
        if (bVar10) {
          local_48[0] = 2;
        }
        local_58 = (uint)bVar10;
        if ((uVar1 & 2) != 0) {
          uVar9 = (ulonglong)local_58;
          local_58 = local_58 + 1;
          local_48[uVar9] = 1;
        }
        if ((uVar1 & 1) != 0) {
          uVar9 = (ulonglong)local_58;
          local_58 = local_58 + 1;
          local_48[uVar9] = 3;
        }
        if ((uVar1 & 8) != 0) {
          uVar9 = (ulonglong)local_58;
          local_58 = local_58 + 1;
          local_48[uVar9] = 5;
        }
        if (local_58 == 0) {
          local_48[0] = 3;
          uVar4 = HidP_UnsetUsages(1,8,0);
        }
        else {
          uVar4 = HidP_SetUsages(1,8,0,local_48);
        }
        if (((uVar4 + 0x80000000 & 0x80000000) != 0) ||
           (uVar9 = (ulonglong)uVar4, uVar4 == 0xc011000f)) {
          lVar7 = *(longlong *)(param_3 + 0xb8);
          plVar6[1] = *(longlong *)(param_3 + 8);
          puVar3 = *(undefined8 **)(param_3 + 0xb8);
          *(longlong *)(param_3 + 8) = lVar8;
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
          *(undefined1 *)(lVar7 + -0x48) = 0xe;
          *(undefined4 *)(lVar7 + -0x30) = 0xb0263;
          *(uint *)(lVar7 + -0x38) = (uint)*(ushort *)(lVar2 + 0xe);
          *(undefined4 *)(lVar7 + -0x40) = 0;
          *(longlong *)(lVar7 + -0x28) = *plVar6;
          iVar5 = IoSetCompletionRoutineEx(*param_1,param_3,KbdHid_SetLedIndicatorsComplete,plVar6);
          if (iVar5 < 0) {
            lVar2 = *(longlong *)(param_3 + 0xb8);
            *(code **)(lVar2 + -0x10) = KbdHid_SetLedIndicatorsComplete;
            *(longlong **)(lVar2 + -8) = plVar6;
            *(undefined1 *)(lVar2 + -0x45) = 0xe0;
          }
          uVar9 = IofCallDriver(param_1[1],param_3);
          return uVar9;
        }
        goto LAB_1c0001b69;
      }
    }
    uVar9 = 0xc000009a;
  }
LAB_1c0001b69:
  *(int *)(param_3 + 0x30) = (int)uVar9;
  IofCompleteRequest(param_3,0);
  if (plVar6 != (longlong *)0x0) {
    if (*plVar6 != 0) {
      ExFreePoolWithTag(*plVar6,0);
    }
    ExFreePoolWithTag(plVar6,0);
  }
  if (lVar8 != 0) {
    IoFreeMdl(lVar8);
  }
  IoReleaseRemoveLockEx(param_1 + 0x13,param_3,0x20);
  return uVar9;
}



===== KbdHid_SetLedIndicatorsComplete @ 1c0001bf0 =====

undefined8 KbdHid_SetLedIndicatorsComplete(longlong param_1,longlong param_2,undefined8 *param_3)

{
  byte *pbVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  IoFreeMdl(*(undefined8 *)(param_2 + 8));
  *(undefined8 *)(param_2 + 8) = param_3[1];
  ExFreePoolWithTag(*param_3,0);
  ExFreePoolWithTag(param_3,0);
  IoReleaseRemoveLockEx(lVar2 + 0x98,param_2,0x20);
  return 0;
}



===== KbdHid_WaitForExtendedAttributesQueryCompletion @ 1c0001c8c =====

undefined4
KbdHid_WaitForExtendedAttributesQueryCompletion
          (longlong param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined8 in_stack_ffffffffffffffd8;
  
  uVar4 = 0;
  LOCK();
  uVar1 = *(uint *)(param_1 + 0x13c);
  if (uVar1 == 0) {
    *(uint *)(param_1 + 0x13c) = 0;
  }
  else {
    uVar4 = uVar1;
  }
  UNLOCK();
  if (uVar4 != 0) {
    if (uVar4 == 1) {
      cVar2 = KeGetCurrentIrql();
      if (cVar2 == '\0') {
        KeWaitForSingleObject(param_1 + 0x140,0,0,0,0);
        return 0;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc0000010;
      }
      bVar3 = KeGetCurrentIrql();
      uVar5 = 0x1a;
      uVar4 = (uint)bVar3;
      goto LAB_1c0001cdc;
    }
    if (uVar4 == 2) {
      return 0;
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
    return 0xc0000010;
  }
  uVar5 = 0x1b;
LAB_1c0001cdc:
  WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_3,uVar5,
                     in_stack_ffffffffffffffd8,(char)uVar4,0x10);
  return 0xc0000010;
}



===== WPP_RECORDER_SF_ @ 1c0001d6c =====

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



===== WPP_RECORDER_SF_Dd @ 1c0001e44 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Dd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined4 local_18 [4];
  
  local_18[0] = 0xc0000010;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_a3eb93ac5d7d3982e3cdea956b1ca812_Traceguids,0x17,&uStack0000000000000030,4,
               local_18,4,0);
  }
  WppAutoLogTrace(param_1,2,3,&WPP_a3eb93ac5d7d3982e3cdea956b1ca812_Traceguids,0x17,
                  &uStack0000000000000030,4,local_18,4,0);
  return;
}



===== WPP_RECORDER_SF_Lqd @ 1c0001f18 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Lqd(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_a3eb93ac5d7d3982e3cdea956b1ca812_Traceguids,param_4,&param_6,4,&param_7,8,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,3,&WPP_a3eb93ac5d7d3982e3cdea956b1ca812_Traceguids,param_4,
                  &param_6,4,&param_7,8,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_d @ 1c000201c =====

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
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,
               &WPP_a3eb93ac5d7d3982e3cdea956b1ca812_Traceguids,param_4,&param_6,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,&WPP_a3eb93ac5d7d3982e3cdea956b1ca812_Traceguids,param_4,
                  &param_6,4,0);
  return;
}



===== WPP_RECORDER_SF_dd @ 1c000211c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dd(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_a3eb93ac5d7d3982e3cdea956b1ca812_Traceguids,param_4,&param_6,4,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,param_2,3,&WPP_a3eb93ac5d7d3982e3cdea956b1ca812_Traceguids,param_4,
                  &param_6,4,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_qqL @ 1c00021f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_a3eb93ac5d7d3982e3cdea956b1ca812_Traceguids,0xb,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,4,3,&WPP_a3eb93ac5d7d3982e3cdea956b1ca812_Traceguids,0xb,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_qqd @ 1c00022f4 =====

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
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,8,&param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,8,&param_8,4,0);
  return;
}



===== WppClassicProviderCallback @ 1c0002450 =====

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



===== _tlgDefineProvider_annotation__Tlgg_TraceLoggingProviderProv @ 1c00024ac =====

void _tlgDefineProvider_annotation__Tlgg_TraceLoggingProviderProv(void)

{
  return;
}



===== wil_details_RecordCachedUsage @ 1c00024b8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  
  local_18 = ___security_cookie ^ (ulonglong)auStack_68;
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



===== wil_details_RecordFeatureUsageReporting @ 1c0002610 =====

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



===== KbdHid_PnPComplete @ 1c00026a0 =====

undefined8 KbdHid_PnPComplete(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  undefined8 uVar2;
  
  if (*(char *)(*(longlong *)(param_2 + 0xb8) + 1) == '\0') {
    KeSetEvent(param_3 + 0xf0,0,0);
    uVar2 = 0xc0000016;
  }
  else {
    if (*(char *)(param_2 + 0x41) != '\0') {
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
    }
    uVar2 = 0;
  }
  return uVar2;
}



===== KbdHid_Power @ 1c00026f0 =====

int KbdHid_Power(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  int iVar8;
  
  bVar6 = false;
  bVar5 = false;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x15,
                     &WPP_6ab2d906fdee3c84bc9e6e4168830b21_Traceguids);
  }
  lVar2 = *(longlong *)(param_2 + 0xb8);
  puVar3 = *(undefined8 **)(param_1 + 0x40);
  iVar8 = *(int *)(lVar2 + 0x10);
  iVar1 = *(int *)(lVar2 + 0x18);
  iVar7 = IoAcquireRemoveLockEx(puVar3 + 0x13,param_2,"",1,0x20);
  if (iVar7 < 0) {
    PoStartNextPowerIrp(param_2);
    *(int *)(param_2 + 0x30) = iVar7;
    IofCompleteRequest(param_2,0);
  }
  else {
    if (*(char *)(lVar2 + 1) == '\x02') {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      if (iVar8 == 1) {
        bVar5 = bVar6;
        if (((*(char *)((longlong)puVar3 + 0x5a) != '\0') && (*(int *)(puVar3 + 3) == 1)) &&
           (1 < iVar1)) {
          bVar5 = true;
        }
        *(int *)(puVar3 + 3) = iVar1;
      }
    }
    PoStartNextPowerIrp(param_2);
    puVar4 = *(undefined8 **)(param_2 + 0xb8);
    if (bVar5) {
      puVar4[-9] = *puVar4;
      puVar4[-8] = puVar4[1];
      puVar4[-7] = puVar4[2];
      puVar4[-6] = puVar4[3];
      *(undefined4 *)(puVar4 + -5) = *(undefined4 *)(puVar4 + 4);
      *(undefined4 *)((longlong)puVar4 + -0x24) = *(undefined4 *)((longlong)puVar4 + 0x24);
      *(undefined4 *)(puVar4 + -4) = *(undefined4 *)(puVar4 + 5);
      *(undefined4 *)((longlong)puVar4 + -0x1c) = *(undefined4 *)((longlong)puVar4 + 0x2c);
      puVar4[-3] = puVar4[6];
      *(undefined1 *)((longlong)puVar4 + -0x45) = 0;
      iVar8 = IoSetCompletionRoutineEx(*puVar3,param_2,KbdHid_PowerCompletion,puVar3,1,1,1);
      if (iVar8 < 0) {
        lVar2 = *(longlong *)(param_2 + 0xb8);
        *(code **)(lVar2 + -0x10) = KbdHid_PowerCompletion;
        *(undefined8 **)(lVar2 + -8) = puVar3;
        *(undefined1 *)(lVar2 + -0x45) = 0xe0;
      }
      iVar7 = PoCallDriver(puVar3[1],param_2);
    }
    else {
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(undefined8 **)(param_2 + 0xb8) = puVar4 + 9;
      iVar7 = PoCallDriver(puVar3[1],param_2);
      IoReleaseRemoveLockEx(puVar3 + 0x13,param_2,0x20);
    }
  }
  return iVar7;
}



===== KbdHid_PowerCompletion @ 1c0002940 =====

undefined8 KbdHid_PowerCompletion(undefined1 param_1,longlong param_2,undefined8 *param_3)

{
  byte *pbVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 uVar5;
  
  iVar2 = *(int *)(param_2 + 0x30);
  lVar3 = param_3[0xe];
  lVar4 = *(longlong *)(param_2 + 0xb8);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    if (*(short *)(WPP_GLOBAL_Control + 0x48) != 0) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x17,
                       &WPP_6ab2d906fdee3c84bc9e6e4168830b21_Traceguids);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x18,
                          &WPP_6ab2d906fdee3c84bc9e6e4168830b21_Traceguids,param_1,(char)param_2,
                          (char)*(undefined4 *)(lVar4 + 0x18) + -1);
    }
  }
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  if (-1 < iVar2) {
    KbdHid_CancelAutoRepeatTimer(param_3,3);
    uVar5 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x88);
    memset(*(void **)(param_3[0xe] + 0x78),0,(ulonglong)*(uint *)(param_3[0xe] + 0x48) << 2);
    memset(*(void **)(param_3[0xe] + 0x80),0,(ulonglong)*(uint *)(param_3[0xe] + 0x48) << 2);
    KeReleaseSpinLock(lVar3 + 0x88,uVar5);
  }
  IoReleaseRemoveLockEx(param_3 + 0x13,param_2,0x20);
  return 0;
}



===== KbdHid_PresenceNotificationCompleted @ 1c0002ad0 =====

undefined8
KbdHid_PresenceNotificationCompleted(undefined8 param_1,longlong param_2,undefined8 *param_3)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x19,
                        &WPP_6ab2d906fdee3c84bc9e6e4168830b21_Traceguids,(char)*param_3,
                        (char)param_2,(char)*(undefined4 *)(param_2 + 0x30));
  }
  if (*(int *)(param_2 + 0x30) == 0) {
    KbdHid_CancelAutoRepeatTimer(param_3,5);
  }
  param_3[99] = 0;
  IoReleaseRemoveLockEx(param_3 + 0x13,param_2,0x20);
  IoFreeIrp(param_2);
  return 0xc0000016;
}



===== KbdHid_QueryDeviceKey @ 1c0002b94 =====

int KbdHid_QueryDeviceKey(undefined8 param_1,undefined8 param_2,void *param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  uint local_res20 [2];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  local_res20[0] = param_4;
  RtlInitUnicodeString(&local_18);
  uVar1 = local_18._2_2_ + 0x18;
  if ((uVar1 < 0x18) || (local_res20[0] = local_18._2_2_ + 0x1c, local_res20[0] < uVar1)) {
    return -0x3fffff6b;
  }
  lVar3 = ExAllocatePool2(0x100,local_res20[0],0x4864624b);
  if (lVar3 == 0) {
    iVar2 = -0x3fffffe9;
  }
  else {
    iVar2 = ZwQueryValueKey(param_1,&local_18,1,lVar3,local_res20[0],local_res20);
    if (-1 < iVar2) {
      if (*(uint *)(lVar3 + 0xc) < 5) {
        memcpy(param_3,(void *)((ulonglong)*(uint *)(lVar3 + 8) + lVar3),
               (ulonglong)*(uint *)(lVar3 + 0xc));
      }
      else {
        iVar2 = -0x3fffffdd;
      }
    }
    ExFreePoolWithTag(lVar3,0);
  }
  return iVar2;
}



===== TraceLoggingKeyRepeatOnRemoval @ 1c0002c94 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TraceLoggingKeyRepeatOnRemoval(undefined8 param_1,undefined8 param_2)

{
  bool bVar1;
  undefined1 auStack_98 [32];
  undefined4 local_78;
  undefined **local_70;
  undefined4 local_68;
  undefined8 local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined *local_48;
  uint local_40;
  undefined4 local_3c;
  undefined *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = ___security_cookie ^ (ulonglong)auStack_98;
  if (5 < DAT_1c000a000) {
    if (((_DAT_1c000a010 & 0x400000000000) == 0) ||
       ((DAT_1c000a018 & 0x400000000000) != DAT_1c000a018)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_1c = 0;
      local_28 = &local_60;
      local_48 = PTR_DAT_1c000a008;
      local_54 = 5;
      local_50 = 0x400000000000;
      local_20 = 8;
      local_58 = 0xb000000;
      local_40 = (uint)*(ushort *)PTR_DAT_1c000a008;
      local_38 = &DAT_1c000961c;
      local_3c = 2;
      local_30 = 0x1e;
      local_2c = 1;
      local_68 = 0x7f;
      local_70 = &local_48;
      local_78 = 3;
      local_60 = param_2;
      EtwWriteTransfer(DAT_1c000a020,&local_58,0,0);
    }
  }
  return;
}



===== WPP_RECORDER_SF_qd @ 1c0002db4 =====

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



===== WPP_RECORDER_SF_qqc @ 1c0002ee0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqc(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_6ab2d906fdee3c84bc9e6e4168830b21_Traceguids,0x13,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,1,0);
  }
  WppAutoLogTrace(param_1,4,5,&WPP_6ab2d906fdee3c84bc9e6e4168830b21_Traceguids,0x13,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,1,0);
  return;
}



===== WPP_RECORDER_SF_qqsd @ 1c0002fd4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqsd(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  char *in_stack_00000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000040 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (in_stack_00000040[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = in_stack_00000040;
    if (in_stack_00000040 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_6ab2d906fdee3c84bc9e6e4168830b21_Traceguids,0x16,&uStack0000000000000030,8,
               &uStack0000000000000038,8,pcVar1,lVar3,&uStack0000000000000048,4,0);
  }
  lVar3 = -1;
  if (in_stack_00000040 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (in_stack_00000040[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (in_stack_00000040 == (char *)0x0) {
    in_stack_00000040 = "NULL";
  }
  WppAutoLogTrace(param_1,4,4,&WPP_6ab2d906fdee3c84bc9e6e4168830b21_Traceguids,0x16,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,in_stack_00000040,lVar2,
                  &uStack0000000000000048,4,0);
  return;
}



===== KbdHidProcessCrashDump @ 1c000316c =====

void KbdHidProcessCrashDump(longlong param_1,byte param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  if (param_2 < 0x80) {
    if (param_2 == 0x1d) {
      if (param_3 == 0) {
        *(uint *)(param_1 + 0x2f0) = *(uint *)(param_1 + 0x2f0) | 0x20;
        return;
      }
      if (param_3 == 1) {
        *(uint *)(param_1 + 0x2f0) = *(uint *)(param_1 + 0x2f0) | 2;
        return;
      }
      return;
    }
    if (param_2 == 0x2a) {
      if (param_3 == 0) {
        *(uint *)(param_1 + 0x2f0) = *(uint *)(param_1 + 0x2f0) | 0x10;
        return;
      }
      return;
    }
    if (param_2 == 0x36) {
      if (param_3 == 0) {
        *(uint *)(param_1 + 0x2f0) = *(uint *)(param_1 + 0x2f0) | 1;
        return;
      }
      return;
    }
    if (param_2 == 0x38) {
      if (param_3 == 0) {
        *(uint *)(param_1 + 0x2f0) = *(uint *)(param_1 + 0x2f0) | 0x40;
        return;
      }
      if (param_3 == 1) {
        *(uint *)(param_1 + 0x2f0) = *(uint *)(param_1 + 0x2f0) | 4;
        return;
      }
      return;
    }
    if (DAT_1c000a1bc < 0x80) {
      if (param_3 == 0) {
        bVar4 = (param_2 & 0x7f) == DAT_1c000a1bc;
LAB_1c00031d1:
        if (bVar4) {
          return;
        }
      }
    }
    else if (param_3 == 1) {
      bVar4 = ((DAT_1c000a1bc ^ param_2) & 0x7f) == 0;
      goto LAB_1c00031d1;
    }
    if (DAT_1c000a1bd < 0x80) {
      if (param_3 != 0) goto LAB_1c00031f9;
      bVar4 = (param_2 & 0x7f) == DAT_1c000a1bd;
    }
    else {
      if (param_3 != 1) goto LAB_1c00031f9;
      bVar4 = ((DAT_1c000a1bd ^ param_2) & 0x7f) == 0;
    }
    if (bVar4) {
      return;
    }
    goto LAB_1c00031f9;
  }
  bVar1 = param_2 & 0x7f;
  if (bVar1 == 0x1d) {
    if (param_3 == 0) {
      *(uint *)(param_1 + 0x2f0) = *(uint *)(param_1 + 0x2f0) & 0xfffffcdf;
      return;
    }
    if (param_3 == 1) {
      *(uint *)(param_1 + 0x2f0) = *(uint *)(param_1 + 0x2f0) & 0xfffffcfd;
      return;
    }
    return;
  }
  if (bVar1 == 0x2a) {
    if (param_3 == 0) {
      *(uint *)(param_1 + 0x2f0) = *(uint *)(param_1 + 0x2f0) & 0xfffffcef;
      return;
    }
    return;
  }
  if (bVar1 == 0x36) {
    if (param_3 == 0) {
      *(uint *)(param_1 + 0x2f0) = *(uint *)(param_1 + 0x2f0) & 0xfffffcfe;
      return;
    }
    return;
  }
  if (bVar1 == 0x38) {
    if (param_3 == 0) {
      *(uint *)(param_1 + 0x2f0) = *(uint *)(param_1 + 0x2f0) & 0xfffffcbf;
      return;
    }
    if (param_3 == 1) {
      *(uint *)(param_1 + 0x2f0) = *(uint *)(param_1 + 0x2f0) & 0xfffffcfb;
      return;
    }
    return;
  }
  if (DAT_1c000a1bc < 0x80) {
    if (param_3 == 0) {
      bVar4 = (param_2 & 0x7f) == DAT_1c000a1bc;
LAB_1c00032cf:
      if (bVar4) goto LAB_1c0003300;
    }
  }
  else if (param_3 == 1) {
    bVar4 = ((DAT_1c000a1bc ^ param_2) & 0x7f) == 0;
    goto LAB_1c00032cf;
  }
  if (DAT_1c000a1bd < 0x80) {
    if ((param_3 != 0) || ((param_2 & 0x7f) != DAT_1c000a1bd)) {
LAB_1c00031f9:
      *(undefined4 *)(param_1 + 0x2f0) = 0;
      return;
    }
  }
  else if ((param_3 != 1) || (((DAT_1c000a1bd ^ param_2) & 0x7f) != 0)) goto LAB_1c00031f9;
LAB_1c0003300:
  uVar3 = *(uint *)(param_1 + 0x2f0);
  uVar2 = uVar3 | 0x200;
  if ((uVar3 & 0x100) == 0) {
    uVar2 = uVar3 | 0x100;
  }
  uVar3 = DAT_1c000a1b8 | 0x300;
  *(uint *)(param_1 + 0x2f0) = uVar2;
  if (uVar2 == uVar3) {
    *(undefined4 *)(param_1 + 0x2f0) = 0;
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0xe2,0,0,0,0);
  }
  return;
}



===== KbdHid_AutoRepeat @ 1c00033e0 =====

void KbdHid_AutoRepeat(undefined8 param_1,undefined8 *param_2)

{
  longlong lVar1;
  char cVar2;
  
  lVar1 = param_2[0xe];
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x14,
                     &WPP_7e65f2fc34253e54541f06c7e51d4e62_Traceguids);
  }
  KbdHid_S0IdleStateUpdate(param_2,1,0);
  cVar2 = KeTryToAcquireSpinLockAtDpcLevel(lVar1 + 0x88);
  if (cVar2 == '\x01') {
    if (**(short **)(lVar1 + 0x80) != 0) {
      HidP_TranslateUsageAndPagesToI8042ScanCodes
                (*(short **)(lVar1 + 0x80),*(undefined4 *)(lVar1 + 0x48),1,lVar1 + 0x4c,
                 KbdHid_InsertCodesIntoQueue,param_2);
    }
    KeReleaseSpinLockFromDpcLevel(lVar1 + 0x88);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x15,
                     &WPP_7e65f2fc34253e54541f06c7e51d4e62_Traceguids);
  }
  return;
}



===== KbdHid_CancelAutoRepeatTimer @ 1c0003500 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong KbdHid_CancelAutoRepeatTimer(undefined8 *param_1,uint param_2)

{
  char cVar1;
  ulonglong in_RAX;
  ulonglong uVar2;
  undefined8 uVar3;
  
  if (DAT_1c000a1be == '\0') {
    cVar1 = KeCancelTimer(param_1 + 0x36);
    if ((param_2 == 5) && (cVar1 != '\0')) {
      param_1[100] = _DAT_fffff78000000014;
    }
    uVar3 = KbdHid_S0IdleStateUpdate(param_1,0,(ulonglong)param_2);
    uVar2 = CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
  }
  else {
    uVar2 = in_RAX & 0xffffffffffffff00;
  }
  return uVar2;
}



===== KbdHid_InitiateStartRead @ 1c0003570 =====

void KbdHid_InitiateStartRead(undefined8 param_1,undefined8 *param_2)

{
  IoAcquireRemoveLockEx(param_2 + 0x13,param_2[0xd],"",1,0x20);
  KbdHid_StartRead(param_2);
  return;
}



===== KbdHid_InsertCodesIntoQueue @ 1c00035c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 KbdHid_InsertCodesIntoQueue(undefined8 *param_1,byte *param_2,ulonglong param_3)

{
  uint uVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  byte bVar4;
  ulonglong uVar5;
  undefined4 local_res18 [2];
  undefined8 in_stack_ffffffffffffffc8;
  
  local_res18[0] = 0;
  puVar3 = (undefined1 *)register0x00000020;
  if ((int)param_3 != 0) {
    uVar5 = param_3 & 0xffffffff;
    do {
      bVar4 = *param_2;
      if (bVar4 == 0xff) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,0xe,
                            in_stack_ffffffffffffffc8,(char)*param_1);
        }
        *(undefined4 *)((longlong)param_1 + 0x10a) = 0xff;
        *(undefined4 *)((longlong)param_1 + 0x114) = 0;
      }
      else {
        uVar1 = *(uint *)((longlong)param_1 + 0x114);
        param_3 = (ulonglong)uVar1;
        if (uVar1 == 0) {
          if (bVar4 == 0xe0) {
            *(ushort *)((longlong)param_1 + 0x10c) = *(ushort *)((longlong)param_1 + 0x10c) | 2;
            *(undefined4 *)((longlong)param_1 + 0x114) = 1;
          }
          else {
            if (bVar4 != 0xe1) goto LAB_1c00036a1;
            *(ushort *)((longlong)param_1 + 0x10c) = *(ushort *)((longlong)param_1 + 0x10c) | 4;
            *(undefined4 *)((longlong)param_1 + 0x114) = 2;
          }
        }
        else {
          if ((uVar1 == 1) || (uVar1 == 2)) {
LAB_1c00036a1:
            if (DAT_1c000a1b8 != 0) {
              KbdHidProcessCrashDump((longlong)param_1,bVar4,uVar1);
            }
            if (0x7f < bVar4) {
              *(ushort *)((longlong)param_1 + 0x10c) = *(ushort *)((longlong)param_1 + 0x10c) | 1;
              bVar4 = bVar4 & 0x7f;
            }
            *(ushort *)((longlong)param_1 + 0x10a) = (ushort)bVar4;
            *(undefined4 *)((longlong)param_1 + 0x114) = 0;
          }
          else if (uVar1 != 0) goto LAB_1c000371d;
          if (*(int *)((longlong)param_1 + 0x1c) != 0) {
            uVar2 = KfRaiseIrql(2);
            param_3 = (longlong)param_1 + 0x114;
            (*(code *)param_1[0x12])(param_1[0x11],param_1 + 0x21,param_3,local_res18);
            KeLowerIrql(uVar2);
          }
          *(undefined2 *)((longlong)param_1 + 0x10c) = 0;
        }
      }
LAB_1c000371d:
      puVar3 = (undefined1 *)0x0;
      param_2 = param_2 + 1;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  return CONCAT71((int7)((ulonglong)puVar3 >> 8),1);
}



===== KbdHid_ReadComplete @ 1c0003750 =====

undefined8 KbdHid_ReadComplete(undefined1 param_1,longlong param_2,longlong *param_3)

{
  uint *puVar1;
  undefined8 *puVar2;
  void *_Dst;
  bool bVar3;
  bool bVar4;
  char cVar5;
  undefined1 uVar6;
  int iVar7;
  undefined8 *puVar8;
  uint uVar9;
  short *psVar10;
  short sVar11;
  longlong *plVar12;
  longlong *_Size;
  short *psVar13;
  bool bVar14;
  undefined1 local_res10;
  code *in_stack_ffffffffffffff88;
  uint local_54;
  longlong *local_50;
  undefined8 *local_48;
  uint *local_40;
  
  local_54 = 0;
  local_res10 = 0;
  bVar4 = false;
  _Size = param_3;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffff88 = (code *)&WPP_7e65f2fc34253e54541f06c7e51d4e62_Traceguids;
    _Size = (longlong *)0x2;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,10,
                     &WPP_7e65f2fc34253e54541f06c7e51d4e62_Traceguids);
  }
  bVar3 = false;
  iVar7 = *(int *)(param_2 + 0x30);
  puVar2 = (undefined8 *)param_3[0xe];
  LOCK();
  bVar14 = (int)param_3[4] == 1;
  if (bVar14) {
    *(int *)(param_3 + 4) = 3;
  }
  UNLOCK();
  bVar14 = !bVar14;
  local_48 = puVar2;
  if (*(int *)((longlong)param_3 + 0x1c) == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qql(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
LAB_1c000381e:
    if (bVar14) {
      KeSetEvent(param_3 + 5,0,0);
      _Size = (longlong *)0x20;
      IoReleaseRemoveLockEx(param_3 + 0x13,param_3[0xd]);
      bVar14 = false;
    }
  }
  else {
    if ((((iVar7 == -0x3fffffaa) || (iVar7 == -0x3fffff9f)) || (iVar7 == -0x3fffff63)) ||
       (iVar7 == -0x3ffffee0)) goto LAB_1c000381e;
    if (iVar7 == 0) {
      puVar1 = (uint *)(puVar2 + 9);
      local_40 = puVar1;
      if (*puVar1 != 0) {
        plVar12 = puVar2 + 0xb;
        in_stack_ffffffffffffff88 = (code *)*puVar2;
        _Size = (longlong *)*plVar12;
        local_54 = *puVar1;
        local_50 = plVar12;
        iVar7 = HidP_GetUsagesEx(0,0,_Size,&local_54,in_stack_ffffffffffffff88,puVar2[10],
                                 *(undefined2 *)((longlong)puVar2 + 0xc));
        if (-1 < iVar7) {
          if ((((local_54 == 1) && (((short *)*plVar12)[1] == 7)) &&
              ((*(short *)*plVar12 == 0x46 &&
               ((DAT_1c000a1b4 != '\0' && (*KdDebuggerEnabled_exref != (code)0x0)))))) &&
             (cVar5 = KdRefreshDebuggerNotPresent(), cVar5 == '\0')) {
            DbgBreakPointWithStatus(2);
          }
          uVar9 = 0;
          psVar13 = (short *)*plVar12;
          if (*puVar1 != 0) {
            do {
              if (*(short *)(*plVar12 + 2) == 7) {
                sVar11 = *psVar13;
                uVar6 = KeAcquireSpinLockRaiseToDpc(param_3 + 0x5d);
                for (psVar10 = (short *)param_3[0x5c]; psVar10 != (short *)0x0;
                    psVar10 = *(short **)(psVar10 + 4)) {
                  if (*psVar10 == sVar11) {
                    sVar11 = psVar10[1];
                    break;
                  }
                }
                KeReleaseSpinLock(param_3 + 0x5d,uVar6);
                *psVar13 = sVar11;
                if (sVar11 == 1) {
                  bVar3 = true;
                  break;
                }
                if (sVar11 == 0) break;
                plVar12 = local_50;
              }
              uVar9 = uVar9 + 1;
              psVar13 = psVar13 + 2;
            } while (uVar9 < *puVar1);
          }
          if (!bVar3) {
            local_res10 = KeAcquireSpinLockRaiseToDpc(puVar2 + 0x11);
            bVar4 = true;
            in_stack_ffffffffffffff88 =
                 (code *)CONCAT44((int)((ulonglong)in_stack_ffffffffffffff88 >> 0x20),
                                  *(undefined4 *)(puVar2 + 9));
            _Size = (longlong *)puVar2[0xe];
            iVar7 = HidP_UsageAndPageListDifference(puVar2[0xf],puVar2[0xb],_Size,puVar2[0xd]);
            if ((-1 < iVar7) && ((*(int *)puVar2[0xd] != 0 || (*(int *)puVar2[0xe] != 0)))) {
              memcpy((int *)puVar2[0xd],(void *)puVar2[0x10],(ulonglong)*(uint *)(puVar2 + 9) << 2);
              in_stack_ffffffffffffff88 =
                   (code *)CONCAT44((int)((ulonglong)in_stack_ffffffffffffff88 >> 0x20),
                                    *(undefined4 *)(puVar2 + 9));
              _Size = (longlong *)puVar2[0xc];
              iVar7 = HidP_UsageAndPageListDifference(puVar2[0xf],puVar2[0xb],_Size,puVar2[0x10]);
              if (-1 < iVar7) {
                in_stack_ffffffffffffff88 = KbdHid_InsertCodesIntoQueue;
                _Size = (longlong *)0x0;
                iVar7 = HidP_TranslateUsageAndPagesToI8042ScanCodes
                                  (puVar2[0xc],*(undefined4 *)(puVar2 + 9),0,(longlong)puVar2 + 0x4c
                                   ,KbdHid_InsertCodesIntoQueue,param_3);
                if (-1 < iVar7) {
                  if ((*(int *)puVar2[0xb] == 0) || (*(int *)puVar2[0x10] != 0)) {
                    in_stack_ffffffffffffff88 = KbdHid_InsertCodesIntoQueue;
                    _Size = (longlong *)0x1;
                    iVar7 = HidP_TranslateUsageAndPagesToI8042ScanCodes
                                      (puVar2[0x10],*(undefined4 *)(puVar2 + 9),1,
                                       (longlong)puVar2 + 0x4c,KbdHid_InsertCodesIntoQueue,param_3);
                  }
                  else {
                    in_stack_ffffffffffffff88 =
                         (code *)CONCAT44((int)((ulonglong)in_stack_ffffffffffffff88 >> 0x20),
                                          *(undefined4 *)(puVar2 + 9));
                    _Size = (longlong *)puVar2[0xe];
                    iVar7 = HidP_UsageAndPageListDifference(puVar2[0xc]);
                  }
                  if (-1 < iVar7) {
                    _Dst = (void *)puVar2[0xf];
                    puVar2[0xf] = puVar2[0xb];
                    _Size = (longlong *)((ulonglong)*(uint *)(puVar2 + 9) << 2);
                    memset(_Dst,0,(size_t)_Size);
                    puVar2[0xb] = _Dst;
                    if (local_54 != 0) {
                      if ((*(short *)puVar2[0xc] == 0) && (*(short *)puVar2[0x10] == 0)) {
                        if ((char)param_3[0x51] == '\0') {
                          *(undefined1 *)(param_3 + 0x51) = 1;
                          DbgPrint(
                                  "*****\n***** CHATTERY   KEYBOARD : Keyboard is sending useless reports.  Tell \'em to fix it.\n*****\n"
                                  );
                          *(uint *)(param_3 + 0xf) = *(uint *)(param_3 + 0xf) | 1;
                          puVar8 = (undefined8 *)
                                   IoAllocateErrorLogEntry(*(undefined8 *)(*param_3 + 8),0x30);
                          if (puVar8 != (undefined8 *)0x0) {
                            *puVar8 = 0;
                            puVar8[1] = 0;
                            puVar8[2] = 0;
                            puVar8[3] = 0;
                            puVar8[4] = 0;
                            puVar8[5] = 0;
                            *(undefined4 *)((longlong)puVar8 + 0xc) = 0x80050001;
                            *(undefined4 *)((longlong)puVar8 + 0x14) = 0x80050001;
                            *(undefined2 *)((longlong)puVar8 + 4) = 0;
                            IoWriteErrorLogEntry(puVar8);
                          }
                        }
                        if ((*(char *)((longlong)param_3 + 0x59) == '\0') && (bVar14)) {
                          KeSetTimerEx(param_3 + 0x48,param_3[0x50],0,param_3 + 0x40);
                        }
                        bVar14 = false;
                        _Size = (longlong *)0x20;
                        IoReleaseRemoveLockEx(param_3 + 0x13,param_3[0xd]);
                        KbdHid_CancelAutoRepeatTimer(param_3,1);
                        goto LAB_1c0003d0b;
                      }
                      if (local_54 != 0) {
                        if (DAT_1c000a1be == '\0') {
                          _Size = (longlong *)(ulonglong)*(uint *)(param_3 + 0x3f);
                          KeSetTimerEx(param_3 + 0x36,param_3[0x3e],_Size,param_3 + 0x2e);
                        }
                        goto LAB_1c0003d0b;
                      }
                    }
                    KbdHid_CancelAutoRepeatTimer(param_3,1);
                  }
                }
              }
            }
          }
          goto LAB_1c0003d0b;
        }
      }
    }
  }
  local_res10 = 0;
LAB_1c0003d0b:
  if (bVar4) {
    KeReleaseSpinLock(puVar2 + 0x11,local_res10);
  }
  if (bVar14) {
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,_Size,0xc,
                        in_stack_ffffffffffffff88,param_1);
    }
    KbdHid_StartRead(param_3);
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0xd,
                     &WPP_7e65f2fc34253e54541f06c7e51d4e62_Traceguids);
  }
  return 0xc0000016;
}



===== KbdHid_S0IdleStateChangeWorkItem @ 1c0003dc0 =====

void KbdHid_S0IdleStateChangeWorkItem(undefined8 param_1,undefined8 *param_2)

{
  int iVar1;
  bool bVar2;
  undefined1 uVar3;
  int iVar4;
  
  bVar2 = false;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x1b,
                     &WPP_7e65f2fc34253e54541f06c7e51d4e62_Traceguids);
  }
  while( true ) {
    uVar3 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x61);
    iVar1 = *(int *)(param_2 + 0x62);
    if (iVar1 == *(int *)(param_2 + 0x60)) {
      bVar2 = true;
      *(undefined1 *)((longlong)param_2 + 0x314) = 0;
    }
    KeReleaseSpinLock(param_2 + 0x61,uVar3);
    if (bVar2) break;
    iVar4 = KbdHid_SendS0IdleStopResumeIrp(param_2,iVar1);
    if (iVar4 < 0) break;
    *(int *)(param_2 + 0x60) = iVar1;
  }
  IoReleaseRemoveLockEx(param_2 + 0x13,KbdHid_S0IdleStateChangeWorkItem,0x20);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x1c,
                     &WPP_7e65f2fc34253e54541f06c7e51d4e62_Traceguids);
  }
  return;
}



===== KbdHid_S0IdleStateUpdate @ 1c0003ef4 =====

void KbdHid_S0IdleStateUpdate(undefined8 *param_1,int param_2,undefined8 param_3)

{
  bool bVar1;
  bool bVar2;
  undefined1 uVar3;
  int iVar4;
  byte bVar5;
  undefined8 uVar6;
  char *pcVar7;
  undefined2 uVar8;
  undefined *in_stack_ffffffffffffffb8;
  
  bVar1 = false;
  bVar2 = false;
  uVar6 = param_3;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar6 = 2;
    in_stack_ffffffffffffffb8 = &WPP_7e65f2fc34253e54541f06c7e51d4e62_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x1d,
                     &WPP_7e65f2fc34253e54541f06c7e51d4e62_Traceguids);
  }
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x61);
  if (*(int *)(param_1 + 0x62) != param_2) {
    bVar1 = true;
    *(int *)(param_1 + 0x62) = param_2;
    if (*(char *)((longlong)param_1 + 0x314) == '\0') {
      *(undefined1 *)((longlong)param_1 + 0x314) = 1;
      bVar2 = true;
    }
  }
  KeReleaseSpinLock(param_1 + 0x61,uVar3);
  if (bVar1) {
    if (bVar2) {
      pcVar7 = "";
      uVar6 = CONCAT44((int)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20),0x20);
      iVar4 = IoAcquireRemoveLockEx(param_1 + 0x13,KbdHid_S0IdleStateChangeWorkItem,"",1);
      if (iVar4 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return;
        }
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,2,0x20,
                           &WPP_7e65f2fc34253e54541f06c7e51d4e62_Traceguids,(char)*param_1,
                           (char)iVar4);
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,pcVar7,0x21,uVar6,
                              (char)*param_1,(char)param_2,(char)param_3);
        }
        IoQueueWorkItem(param_1[0x5f],KbdHid_S0IdleStateChangeWorkItem,1,param_1);
      }
      goto LAB_1c00040e5;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar8 = 0x1f;
    bVar5 = 4;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    if (*(short *)(WPP_GLOBAL_Control + 0x48) == 0) goto LAB_1c00040e5;
    uVar8 = 0x1e;
    bVar5 = 5;
  }
  WPP_RECORDER_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar5,uVar6,uVar8,
                      in_stack_ffffffffffffffb8,(char)*param_1,(char)param_2,(char)param_3);
LAB_1c00040e5:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x22,
                     &WPP_7e65f2fc34253e54541f06c7e51d4e62_Traceguids);
  }
  return;
}



===== KbdHid_StartRead @ 1c000413c =====

int KbdHid_StartRead(undefined8 *param_1)

{
  undefined8 *puVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  int iVar6;
  undefined8 uVar7;
  undefined *in_stack_ffffffffffffffc8;
  
  lVar3 = param_1[0xd];
  iVar6 = *(int *)(lVar3 + 0x30);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffc8 = &WPP_7e65f2fc34253e54541f06c7e51d4e62_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0xf,
                     &WPP_7e65f2fc34253e54541f06c7e51d4e62_Traceguids);
  }
  lVar4 = param_1[0xe];
  LOCK();
  iVar2 = *(int *)(param_1 + 4);
  *(int *)(param_1 + 4) = 1;
  UNLOCK();
  do {
    if (iVar2 != 2) {
LAB_1c00042f2:
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x13,
                         &WPP_7e65f2fc34253e54541f06c7e51d4e62_Traceguids);
      }
      return iVar6;
    }
    if (iVar6 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,0x12,
                            &WPP_7e65f2fc34253e54541f06c7e51d4e62_Traceguids,(char)*param_1,
                            (char)lVar3,(char)iVar6);
      }
      KeSetEvent(param_1 + 5,0,0);
      IoReleaseRemoveLockEx(param_1 + 0x13,param_1[0xd],0x20);
      goto LAB_1c00042f2;
    }
    IoReuseIrp(lVar3,0);
    lVar5 = *(longlong *)(lVar3 + 0xb8);
    *(undefined8 *)(lVar3 + 8) = *(undefined8 *)(lVar4 + 0x90);
    *(uint *)(lVar5 + -0x40) = (uint)*(ushort *)(lVar4 + 0xc);
    *(undefined4 *)(lVar5 + -0x38) = 0;
    *(undefined8 *)(lVar5 + -0x30) = 0;
    *(undefined1 *)(lVar5 + -0x48) = 3;
    *(undefined8 *)(lVar5 + -0x18) = param_1[0x10];
    in_stack_ffffffffffffffc8 =
         (undefined *)CONCAT71((int7)((ulonglong)in_stack_ffffffffffffffc8 >> 8),1);
    iVar6 = IoSetCompletionRoutineEx
                      (*param_1,lVar3,KbdHid_ReadComplete,param_1,in_stack_ffffffffffffffc8,1,1);
    if (iVar6 < 0) {
      lVar5 = *(longlong *)(lVar3 + 0xb8);
      *(code **)(lVar5 + -0x10) = KbdHid_ReadComplete;
      *(undefined8 **)(lVar5 + -8) = param_1;
      *(undefined1 *)(lVar5 + -0x45) = 0xe0;
    }
    puVar1 = param_1 + 8;
    KeResetEvent(puVar1);
    if ((*(int *)((longlong)param_1 + 0x1c) == 0) || (*(char *)((longlong)param_1 + 0x59) == '\x01')
       ) {
      IoReleaseRemoveLockEx(param_1 + 0x13,param_1[0xd],0x20);
      iVar6 = (-(uint)(*(char *)((longlong)param_1 + 0x59) != '\0') & 0x55) + 0xc0000001;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      KeSetEvent(puVar1,0,0);
      KeSetEvent(param_1 + 5,0,0);
      goto LAB_1c00042f2;
    }
    iVar6 = IofCallDriver(param_1[1]);
    uVar7 = 0;
    KeSetEvent(puVar1);
    LOCK();
    iVar2 = *(int *)(param_1 + 4);
    *(int *)(param_1 + 4) = 2;
    UNLOCK();
    if (iVar2 != 3) goto LAB_1c00042f2;
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar7,0x11,
                        in_stack_ffffffffffffffc8,(char)*param_1);
    }
    LOCK();
    iVar2 = *(int *)(param_1 + 4);
    *(int *)(param_1 + 4) = 1;
    UNLOCK();
  } while( true );
}



===== WPP_RECORDER_SF_q @ 1c0004454 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_q(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_7e65f2fc34253e54541f06c7e51d4e62_Traceguids,param_4,&param_6,8,0);
  }
  WppAutoLogTrace(param_1,param_2,2,&WPP_7e65f2fc34253e54541f06c7e51d4e62_Traceguids,param_4,
                  &param_6,8,0);
  return;
}



===== WPP_RECORDER_SF_qDd @ 1c0004508 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_7e65f2fc34253e54541f06c7e51d4e62_Traceguids,0x10,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,4,2,&WPP_7e65f2fc34253e54541f06c7e51d4e62_Traceguids,0x10,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_qLL @ 1c00045fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLL(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_7e65f2fc34253e54541f06c7e51d4e62_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,2,&WPP_7e65f2fc34253e54541f06c7e51d4e62_Traceguids,param_4,
                  &param_6,8,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qLqd @ 1c00046fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLqd
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_7e65f2fc34253e54541f06c7e51d4e62_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,8,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,4,2,&WPP_7e65f2fc34253e54541f06c7e51d4e62_Traceguids,param_4,&param_6,8,
                  &param_7,4,&param_8,8,&param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_qql @ 1c0004814 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qql(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_7e65f2fc34253e54541f06c7e51d4e62_Traceguids,0xb,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,4,2,&WPP_7e65f2fc34253e54541f06c7e51d4e62_Traceguids,0xb,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,0);
  return;
}



===== KbdHid_Close @ 1c0004910 =====

void KbdHid_Close(longlong param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  char cVar4;
  undefined8 uVar5;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x16,
                     &WPP_98d22518711f34f074bb80910c9ade48_Traceguids);
  }
  puVar3 = *(undefined8 **)(param_1 + 0x40);
  ExAcquireFastMutex(puVar3 + 0x17);
  LOCK();
  piVar1 = (int *)((longlong)puVar3 + 0x1c);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqql(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  if (iVar2 == 1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    KeWaitForSingleObject(puVar3 + 8,0,0,0,0);
    if (puVar3[0x10] != 0) {
      IoCancelIrp(puVar3[0xd]);
      KeWaitForSingleObject(puVar3 + 5,0,0,0,0);
    }
    uVar5 = KbdHid_CancelAutoRepeatTimer(puVar3,2);
    cVar4 = KeCancelTimer(puVar3 + 0x48);
    if (cVar4 != '\0' || (char)uVar5 != '\0') {
      KeFlushQueuedDpcs();
    }
    puVar3[0x10] = 0;
  }
  ExReleaseFastMutex(puVar3 + 0x17);
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x19,
                     &WPP_98d22518711f34f074bb80910c9ade48_Traceguids);
  }
  IofCallDriver(puVar3[1],param_2);
  return;
}



===== KbdHid_Create @ 1c0004b10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int KbdHid_Create(longlong param_1,longlong param_2)

{
  uint uVar1;
  undefined8 *puVar2;
  longlong lVar3;
  char cVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined *puVar7;
  undefined8 uVar8;
  undefined2 uVar9;
  longlong lVar10;
  bool bVar11;
  undefined1 auStackY_e8 [32];
  undefined *in_stack_ffffffffffffff38;
  undefined1 uVar12;
  undefined1 uVar13;
  undefined8 local_78;
  undefined8 *local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined2 local_48;
  ulonglong local_40;
  
  local_40 = ___security_cookie ^ (ulonglong)auStackY_e8;
  local_58 = 0;
  local_68 = 0;
  uStack_60 = 0;
  puVar7 = &WPP_98d22518711f34f074bb80910c9ade48_Traceguids;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffff38 = &WPP_98d22518711f34f074bb80910c9ade48_Traceguids;
    puVar7 = (undefined *)0x0;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,10,
                     &WPP_98d22518711f34f074bb80910c9ade48_Traceguids);
  }
  lVar10 = *(longlong *)(param_2 + 0xb8);
  puVar2 = *(undefined8 **)(param_1 + 0x40);
  uVar1 = *(uint *)(*(longlong *)(lVar10 + 8) + 0x10);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqqDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  lVar3 = *(longlong *)(lVar10 + 0x30);
  uVar12 = (undefined1)param_1;
  uVar13 = (undefined1)param_2;
  if ((lVar3 == 0) || (*(short *)(lVar3 + 0x58) == 0)) {
LAB_1c0004d04:
    iVar5 = IoAcquireRemoveLockEx(puVar2 + 0x13,param_2,"",1);
    if (-1 < iVar5) {
      ExAcquireFastMutex();
      if (puVar2[0x12] == 0) {
        iVar5 = -0x3fffffff;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar9 = 0xf;
LAB_1c0004dc3:
          WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar9,
                              &WPP_98d22518711f34f074bb80910c9ade48_Traceguids,uVar12,uVar13,
                              (char)iVar5);
        }
LAB_1c0004fe7:
        lVar10 = 0;
      }
      else {
        puVar6 = *(undefined8 **)(param_2 + 0xb8);
        puVar6[-9] = *puVar6;
        puVar6[-8] = puVar6[1];
        puVar6[-7] = puVar6[2];
        puVar6[-6] = puVar6[3];
        *(undefined4 *)(puVar6 + -5) = *(undefined4 *)(puVar6 + 4);
        *(undefined4 *)((longlong)puVar6 + -0x24) = *(undefined4 *)((longlong)puVar6 + 0x24);
        *(undefined4 *)(puVar6 + -4) = *(undefined4 *)(puVar6 + 5);
        *(undefined4 *)((longlong)puVar6 + -0x1c) = *(undefined4 *)((longlong)puVar6 + 0x2c);
        puVar6[-3] = puVar6[6];
        *(undefined1 *)((longlong)puVar6 + -0x45) = 0;
        KeInitializeEvent(&local_68,0,0);
        lVar3 = *(longlong *)(param_2 + 0xb8);
        *(code **)(lVar3 + -0x10) = KbdHid_CreateComplete;
        *(undefined8 **)(lVar3 + -8) = &local_68;
        *(undefined1 *)(lVar3 + -0x45) = 0xe0;
        iVar5 = IofCallDriver(puVar2[1],param_2);
        KeWaitForSingleObject(&local_68,0,0,0);
        if (iVar5 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar9 = 0x12;
            goto LAB_1c0004dc3;
          }
          goto LAB_1c0004fe7;
        }
        iVar5 = *(int *)(param_2 + 0x30);
        LOCK();
        *(int *)((longlong)puVar2 + 0x1c) = *(int *)((longlong)puVar2 + 0x1c) + 1;
        UNLOCK();
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qqdl(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
        if ((puVar2[0x10] != 0) || ((*(uint *)(*(longlong *)(lVar10 + 8) + 0x10) & 1) == 0))
        goto LAB_1c0004fe7;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qqqDDl(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
        lVar10 = *(longlong *)(lVar10 + 0x30);
        puVar2[0x10] = lVar10;
        KeResetEvent(puVar2 + 5);
        LOCK();
        *(undefined4 *)(puVar2 + 4) = 2;
        UNLOCK();
        IoAcquireRemoveLockEx(puVar2 + 0x13,puVar2[0xd],"",1);
        *(undefined4 *)(puVar2[0xd] + 0x30) = 0;
        iVar5 = KbdHid_StartRead(puVar2);
        if (iVar5 == 0x103) {
          iVar5 = 0;
        }
        else if (iVar5 < 0) {
          puVar2[0x10] = 0;
        }
      }
      ExReleaseFastMutex();
      if ((-1 < iVar5) && (lVar10 != 0)) {
        LOCK();
        bVar11 = *(int *)((longlong)puVar2 + 0x13c) == 0;
        if (bVar11) {
          *(int *)((longlong)puVar2 + 0x13c) = 1;
        }
        UNLOCK();
        if (bVar11) {
          iVar5 = KbdHid_QueryExtendedAttributes(puVar2);
          if (iVar5 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x13,
                                 &WPP_98d22518711f34f074bb80910c9ade48_Traceguids,uVar12,(char)iVar5
                                );
            }
            iVar5 = 0;
          }
          LOCK();
          *(undefined4 *)((longlong)puVar2 + 0x13c) = 2;
          UNLOCK();
          KeSetEvent(puVar2 + 0x28,0,0);
        }
      }
      *(undefined8 *)(param_2 + 0x38) = 0;
      *(int *)(param_2 + 0x30) = iVar5;
      IofCompleteRequest(param_2,0);
      IoReleaseRemoveLockEx(puVar2 + 0x13,param_2,0x20);
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar5;
      }
      if (*(short *)(WPP_GLOBAL_Control + 0x48) == 0) {
        return iVar5;
      }
      uVar9 = 0x14;
      goto LAB_1c0005101;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0xe,
                          &WPP_98d22518711f34f074bb80910c9ade48_Traceguids,uVar12,uVar13,(char)iVar5
                         );
    }
  }
  else {
    puVar6 = &local_78;
    uVar8 = CONCAT71((int7)((ulonglong)puVar7 >> 8),1);
    local_48 = 0;
    local_70 = &local_50;
    local_50 = 0x440042004b005c;
    local_78 = 0xa0008;
    cVar4 = RtlEqualUnicodeString();
    if (cVar4 == '\0') {
      iVar5 = -0x3fffffde;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar9 = 0xc;
LAB_1c0004c62:
        WPP_RECORDER_SF_qqqd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,uVar8,uVar9,
                   in_stack_ffffffffffffff38,uVar12,uVar13,(char)*(longlong *)(lVar10 + 0x30),
                   (char)iVar5);
      }
    }
    else {
      if ((uVar1 & 1) == 0) goto LAB_1c0004d04;
      iVar5 = -0x3fffffbd;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar9 = 0xd;
        goto LAB_1c0004c62;
      }
    }
  }
  *(int *)(param_2 + 0x30) = iVar5;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
    return iVar5;
  }
  if (*(short *)(WPP_GLOBAL_Control + 0x48) == 0) {
    return iVar5;
  }
  uVar9 = 0x15;
LAB_1c0005101:
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,uVar9,
                   &WPP_98d22518711f34f074bb80910c9ade48_Traceguids);
  return iVar5;
}



===== KbdHid_CreateComplete @ 1c0005140 =====

undefined8 KbdHid_CreateComplete(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== KbdHid_QueryExtendedAttributes @ 1c000516c =====

int KbdHid_QueryExtendedAttributes(undefined8 *param_1)

{
  undefined1 uVar1;
  char cVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined8 *puVar5;
  int iVar6;
  longlong lVar7;
  short *psVar8;
  undefined1 *puVar9;
  uint uVar10;
  byte bVar11;
  longlong lVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  ushort *puVar15;
  undefined8 uVar16;
  undefined2 uVar17;
  ushort local_res8 [4];
  uint local_res10 [2];
  uint local_res18 [2];
  uint local_res20 [2];
  undefined8 in_stack_ffffffffffffff58;
  int local_58 [6];
  
  puVar5 = (undefined8 *)param_1[0xe];
  local_res8[0] = 0;
  local_res10[0] = 0;
  local_58[0] = 0;
  local_res18[0] = 0;
  local_res20[0] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  if (*(short *)(puVar5 + 2) != 0) {
    uVar3 = *(ushort *)((longlong)puVar5 + 0x44);
    if (uVar3 != 0) {
      lVar12 = (ulonglong)uVar3 * 0x48;
      uVar14 = 0x4864624b;
      local_res8[0] = uVar3;
      lVar7 = ExAllocatePool2(0x40);
      if (lVar7 == 0) {
        iVar6 = -0x3fffff66;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar12,uVar14,0x1b,
                              in_stack_ffffffffffffff58,(char)*param_1,(char)local_res8[0],0x9a);
        }
      }
      else {
        puVar15 = local_res8;
        lVar12 = lVar7;
        iVar6 = HidP_GetValueCaps(2,lVar7,puVar15,*puVar5);
        if (iVar6 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar12,puVar15,0x1c,
                                in_stack_ffffffffffffff58,(char)*param_1,(char)local_res8[0],
                                (char)iVar6);
          }
        }
        else {
          uVar10 = 0;
          if (local_res8[0] != 0) {
            psVar8 = (short *)(lVar7 + 8);
            uVar14 = 0xc;
            do {
              if (((((psVar8[1] == 0xc) && (*psVar8 == 0x2c0)) && (psVar8[-4] == 0xc)) &&
                  (((char)psVar8[2] == '\x01' && ((ushort)psVar8[0x18] < 0x2c7)))) &&
                 (0x2c0 < (ushort)psVar8[0x19])) {
                uVar16 = 0x4864624b;
                uVar4 = *(undefined2 *)(lVar7 + 6 + (ulonglong)uVar10 * 0x48);
                uVar1 = *(undefined1 *)(lVar7 + 2 + (ulonglong)uVar10 * 0x48);
                uVar13 = (ulonglong)*(ushort *)(puVar5 + 2);
                puVar9 = (undefined1 *)ExAllocatePool2(0x40);
                if (puVar9 == (undefined1 *)0x0) {
                  iVar6 = -0x3fffff66;
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar13,uVar16,
                                        0x1e,in_stack_ffffffffffffff58,(char)*param_1,
                                        (char)*(undefined2 *)(puVar5 + 2),0x9a);
                  }
                }
                else {
                  *puVar9 = uVar1;
                  iVar6 = KbdHid_CallHidClass((longlong)param_1,0xb0192,uVar16,uVar14,puVar9,
                                              (uint)*(ushort *)(puVar5 + 2));
                  if (iVar6 < 0) {
                    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x1f,
                                         &WPP_98d22518711f34f074bb80910c9ade48_Traceguids,
                                         (char)*param_1,(char)iVar6);
                    }
                  }
                  else {
                    iVar6 = HidP_GetUsageValue(2,0xc,uVar4,0x2c3,local_res10,*puVar5,puVar9,
                                               *(undefined2 *)(puVar5 + 2));
                    if (iVar6 < 0) {
                      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                        uVar17 = 0x20;
                        bVar11 = 3;
LAB_1c0005527:
                        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar11,1,
                                           uVar17,&WPP_98d22518711f34f074bb80910c9ade48_Traceguids,
                                           (char)*param_1,(char)iVar6);
                      }
                    }
                    else if (local_res10[0] < 7) {
                      if (local_res10[0] == 6) {
                        iVar6 = HidP_GetUsageValue(2,0xc,uVar4,0x2c4,local_58,*puVar5,puVar9,
                                                   *(undefined2 *)(puVar5 + 2));
                        if (iVar6 < 0) {
                          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                            uVar17 = 0x22;
                            bVar11 = 2;
                            goto LAB_1c0005527;
                          }
                        }
                        else if (local_58[0] == 0) {
                          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                            uVar17 = 0x23;
                            uVar10 = 0;
                            goto LAB_1c0005571;
                          }
                          goto LAB_1c000559d;
                        }
                      }
                    }
                    else {
                      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                        uVar17 = 0x21;
                        uVar10 = local_res10[0];
LAB_1c0005571:
                        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar17,
                                           &WPP_98d22518711f34f074bb80910c9ade48_Traceguids,
                                           (char)*param_1,(char)uVar10);
                      }
LAB_1c000559d:
                      local_res10[0] = 0;
                    }
                    iVar6 = HidP_GetUsageValue(2,0xc,uVar4,0x2c1,local_res18,*puVar5,puVar9,
                                               *(undefined2 *)(puVar5 + 2));
                    if (iVar6 < 0) {
                      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x24,
                                           &WPP_98d22518711f34f074bb80910c9ade48_Traceguids,
                                           (char)*param_1,(char)iVar6);
                      }
                    }
                    else if (2 < local_res18[0]) {
                      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x25,
                                           &WPP_98d22518711f34f074bb80910c9ade48_Traceguids,
                                           (char)*param_1,(char)local_res18[0]);
                      }
                      local_res18[0] = 0;
                    }
                    iVar6 = HidP_GetUsageValue(2,0xc,uVar4,0x2c2,local_res20,*puVar5,puVar9,
                                               *(undefined2 *)(puVar5 + 2));
                    if (iVar6 < 0) {
                      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x26,
                                           &WPP_98d22518711f34f074bb80910c9ade48_Traceguids,
                                           (char)*param_1,(char)iVar6);
                      }
                    }
                    else if (3 < local_res20[0]) {
                      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x27,
                                           &WPP_98d22518711f34f074bb80910c9ade48_Traceguids,
                                           (char)*param_1,(char)local_res20[0]);
                      }
                      local_res20[0] = 0;
                    }
                    iVar6 = HidP_GetUsageValue(2,0xc,uVar4,0x2c5,local_58 + 1,*puVar5,puVar9,
                                               *(undefined2 *)(puVar5 + 2));
                    if ((iVar6 < 0) &&
                       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x28,
                                         &WPP_98d22518711f34f074bb80910c9ade48_Traceguids,
                                         (char)*param_1,(char)iVar6);
                    }
                    iVar6 = HidP_GetUsageValue(2,0xc,uVar4,0x2c6,local_58 + 2,*puVar5,puVar9,
                                               *(undefined2 *)(puVar5 + 2));
                    if ((iVar6 < 0) &&
                       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x29,
                                         &WPP_98d22518711f34f074bb80910c9ade48_Traceguids,
                                         (char)*param_1,(char)iVar6);
                    }
                    cVar2 = *(char *)(param_1 + 0x23);
                    if (cVar2 == '\x04') {
                      local_res10[0] = 1;
LAB_1c00058ea:
                      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,1,0x2a,
                                           &WPP_98d22518711f34f074bb80910c9ade48_Traceguids,
                                           (char)*param_1,(char)local_res10[0]);
                      }
                    }
                    else {
                      if (cVar2 == '\a') {
                        local_res10[0] = 5;
                        goto LAB_1c00058ea;
                      }
                      if (cVar2 == '\b') {
                        local_res10[0] = 2;
                        goto LAB_1c00058ea;
                      }
                      if (local_res10[0] == 1) {
                        if (cVar2 != '\x04') {
                          *(undefined2 *)(param_1 + 0x23) = 4;
                          param_1[0x2b] = 4;
                        }
                      }
                      else if (local_res10[0] == 2) {
                        if (cVar2 != '\b') {
                          *(undefined2 *)(param_1 + 0x23) = 0x608;
                          *(undefined4 *)(param_1 + 0x2b) = 8;
                          *(undefined4 *)((longlong)param_1 + 0x15c) = 6;
                        }
                      }
                      else if ((local_res10[0] == 5) && (cVar2 != '\a')) {
                        *(undefined2 *)(param_1 + 0x23) = 0x207;
                        *(undefined4 *)(param_1 + 0x2b) = 7;
                        *(undefined4 *)((longlong)param_1 + 0x15c) = 2;
                      }
                    }
                    iVar6 = 0;
                  }
                  ExFreePoolWithTag(puVar9,0);
                }
                goto LAB_1c00053c2;
              }
              uVar10 = uVar10 + 1;
              psVar8 = psVar8 + 0x24;
            } while (uVar10 < local_res8[0]);
          }
          iVar6 = -0x3ffffddb;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x1d,
                               &WPP_98d22518711f34f074bb80910c9ade48_Traceguids,(char)*param_1,0x25)
            ;
          }
        }
LAB_1c00053c2:
        ExFreePoolWithTag(lVar7,0);
      }
      goto LAB_1c000597d;
    }
  }
  iVar6 = -0x3fffff45;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x1a,
                       &WPP_98d22518711f34f074bb80910c9ade48_Traceguids,(char)*param_1,0xbb);
  }
LAB_1c000597d:
  *(char *)((longlong)param_1 + 0x135) = (char)local_res18[0];
  *(char *)((longlong)param_1 + 0x136) = (char)local_res20[0];
  *(char *)((longlong)param_1 + 0x137) = (char)local_res10[0];
  *(char *)(param_1 + 0x27) = (char)local_58[0];
  *(char *)((longlong)param_1 + 0x139) = (char)local_58[1];
  *(char *)((longlong)param_1 + 0x13a) = (char)local_58[2];
  *(undefined1 *)((longlong)param_1 + 0x134) = 1;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qdddddddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  if ((iVar6 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x2c,
                       &WPP_98d22518711f34f074bb80910c9ade48_Traceguids,(char)*param_1,(char)iVar6);
  }
  return iVar6;
}



===== WPP_RECORDER_SF_qdd @ 1c0005a88 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qdd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_98d22518711f34f074bb80910c9ade48_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_98d22518711f34f074bb80910c9ade48_Traceguids,param_4,&param_6,8,
                  &param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qdddddddd @ 1c0005b80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qdddddddd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  undefined1 uStack0000000000000070;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_98d22518711f34f074bb80910c9ade48_Traceguids,0x2b,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,
               &uStack0000000000000068,4,&uStack0000000000000070,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_98d22518711f34f074bb80910c9ade48_Traceguids,0x2b,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,&uStack0000000000000068,4,&uStack0000000000000070,4,0);
  return;
}



===== WPP_RECORDER_SF_qq @ 1c0005d3c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_98d22518711f34f074bb80910c9ade48_Traceguids,0x18,&uStack0000000000000030,8,
               &uStack0000000000000038,8,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_98d22518711f34f074bb80910c9ade48_Traceguids,0x18,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,0);
  return;
}



===== WPP_RECORDER_SF_qqdl @ 1c0005e0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqdl(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_98d22518711f34f074bb80910c9ade48_Traceguids,0x10,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_98d22518711f34f074bb80910c9ade48_Traceguids,0x10,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_qqqDD @ 1c0005f24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqqDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_98d22518711f34f074bb80910c9ade48_Traceguids,0xb,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,8,&uStack0000000000000048,4,
               &uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_98d22518711f34f074bb80910c9ade48_Traceguids,0xb,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,8,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_qqqDDl @ 1c0006060 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqqDDl(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_98d22518711f34f074bb80910c9ade48_Traceguids,0x11,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,8,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_98d22518711f34f074bb80910c9ade48_Traceguids,0x11,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,8,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  return;
}



===== WPP_RECORDER_SF_qqqd @ 1c00061b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqqd
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_98d22518711f34f074bb80910c9ade48_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,8,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_98d22518711f34f074bb80910c9ade48_Traceguids,param_4,&param_6,8,
                  &param_7,8,&param_8,8,&param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_qqql @ 1c00062cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqql(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_98d22518711f34f074bb80910c9ade48_Traceguids,0x17,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,8,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_98d22518711f34f074bb80910c9ade48_Traceguids,0x17,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,8,
                  &uStack0000000000000048,4,0);
  return;
}



===== FreeKeyboardUsageMappingList @ 1c00063e0 =====

void FreeKeyboardUsageMappingList(longlong param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  longlong lVar3;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x2e8);
  lVar3 = *(longlong *)(param_1 + 0x2e0);
  *(undefined8 *)(param_1 + 0x2e0) = 0;
  KeReleaseSpinLock(param_1 + 0x2e8,uVar2);
  while (lVar3 != 0) {
    lVar1 = *(longlong *)(lVar3 + 8);
    ExFreePoolWithTag(lVar3,0);
    lVar3 = lVar1;
  }
  return;
}



===== LAtoX @ 1c000645c =====

int LAtoX(ushort *param_1)

{
  int iVar1;
  ushort uVar2;
  ulonglong uVar3;
  
  uVar2 = *param_1;
  iVar1 = 0;
  uVar3 = 0;
  do {
    if (uVar2 == 0) {
      return iVar1;
    }
    if ((ushort)(uVar2 - 0x30) < 10) {
      iVar1 = iVar1 * 0x10 + -0x30;
LAB_1c0006490:
      iVar1 = iVar1 + (uint)uVar2;
    }
    else {
      if ((ushort)(uVar2 - 0x61) < 6) {
        iVar1 = iVar1 * 0x10 + -0x57;
        goto LAB_1c0006490;
      }
      if (5 < (ushort)(uVar2 - 0x41)) {
        return iVar1;
      }
      iVar1 = iVar1 * 0x10 + -0x37 + (uint)uVar2;
    }
    uVar3 = (ulonglong)((int)uVar3 + 1);
    uVar2 = param_1[uVar3];
  } while( true );
}



===== LoadKeyboardUsageMappingList @ 1c00064c8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void LoadKeyboardUsageMappingList(longlong param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined1 auStack_d8 [32];
  undefined4 local_b8;
  undefined4 *local_b0;
  undefined4 local_a8 [2];
  undefined8 local_a0;
  ulonglong local_98 [3];
  undefined8 local_80;
  undefined2 local_78;
  undefined8 local_70;
  undefined2 local_68;
  undefined8 local_60;
  uint local_58;
  int local_54;
  uint local_50;
  undefined8 local_4c;
  ulonglong local_30;
  
  local_30 = ___security_cookie ^ (ulonglong)auStack_d8;
  local_98[0] = 0;
  puVar6 = (undefined2 *)0x0;
  iVar2 = IoOpenDeviceRegistryKey(*(undefined8 *)(param_1 + 0x10),2,0x20019,local_98);
  if (-1 < iVar2) {
    local_a0 = 0;
    local_98[1] = 0;
    local_98[2] = 0;
    RtlInitUnicodeString(local_98 + 1,L"UsageMappings");
    iVar2 = OpenSubkey(&local_a0,local_98[0],local_98 + 1);
    if (-1 < iVar2) {
      local_a8[0] = 0;
      iVar2 = 0;
      puVar5 = (undefined2 *)0x0;
      while( true ) {
        local_b0 = local_a8;
        local_b8 = 0x2a;
        iVar3 = ZwEnumerateValueKey(local_a0,iVar2,1,&local_60);
        if (iVar3 < 0) break;
        puVar4 = puVar5;
        if (((local_60._4_4_ == 1) && (local_54 == 10)) && (local_50 < 0xb)) {
          local_80 = local_4c;
          local_78 = 0;
          local_68 = 0;
          local_70 = *(undefined8 *)((longlong)&local_60 + (ulonglong)local_58);
          puVar4 = (undefined2 *)ExAllocatePool2(0x40,0x10,0x4864624b);
          if (puVar4 == (undefined2 *)0x0) break;
          iVar3 = LAtoX((ushort *)&local_80);
          *puVar4 = (short)iVar3;
          iVar3 = LAtoX((ushort *)&local_70);
          puVar4[1] = (short)iVar3;
          *(undefined8 *)(puVar4 + 4) = 0;
          if (puVar5 == (undefined2 *)0x0) {
            puVar6 = puVar4;
          }
          else {
            *(undefined2 **)(puVar5 + 4) = puVar4;
          }
        }
        iVar2 = iVar2 + 1;
        puVar5 = puVar4;
      }
      ZwClose(local_a0);
    }
    ZwClose(local_98[0]);
  }
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x2e8);
  *(undefined2 **)(param_1 + 0x2e0) = puVar6;
  KeReleaseSpinLock(param_1 + 0x2e8,uVar1);
  return;
}



===== _guard_check_icall @ 1c00066b0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c00066c8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c00066ec =====

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



===== __cpu_features_init @ 1c0006760 =====

/* WARNING: Removing unreachable block (ram,0x0001c00067ca) */
/* WARNING: Removing unreachable block (ram,0x0001c0006779) */
/* WARNING: Removing unreachable block (ram,0x0001c000676a) */

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



===== __security_check_cookie @ 1c0006830 =====

/* WARNING: This is an inlined function */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != ___security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0006870 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c00068a0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c00068a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c00068d0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0006940 =====

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

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



===== memset @ 1c0006c40 =====

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



===== __memset_repmovs @ 1c0006d80 =====

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



===== __memset_query @ 1c0006e00 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0006e80 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0006fc0 =====

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



===== __memset_spec_plain @ 1c0007040 =====

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



===== KbdHid_Unload @ 1c000d010 =====

void KbdHid_Unload(undefined8 param_1)

{
  ExFreePoolWithTag(DAT_1c000a1a8,0);
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
  WppCleanupKm(param_1);
  return;
}



===== WppCleanupKm @ 1c000d08c =====

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



===== WppInitKm @ 1c000d13c =====

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



===== WppLoadTracingSupport @ 1c000d218 =====

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



===== WppTraceCallback @ 1c000d360 =====

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
        memcpy((ushort *)((ulonglong)uVar11 + (longlong)param_4) + 1,*(void **)(puVar3 + 4),
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



===== wil_details_EvaluateFeatureDependencies @ 1c000d5e8 =====

/* WARNING: Removing unreachable block (ram,0x0001c000d610) */
/* WARNING: Removing unreachable block (ram,0x0001c000d620) */
/* WARNING: Removing unreachable block (ram,0x0001c000d625) */
/* WARNING: Removing unreachable block (ram,0x0001c000d62a) */
/* WARNING: Removing unreachable block (ram,0x0001c000d635) */
/* WARNING: Removing unreachable block (ram,0x0001c000d64a) */
/* WARNING: Removing unreachable block (ram,0x0001c000d640) */
/* WARNING: Removing unreachable block (ram,0x0001c000d65a) */
/* WARNING: Removing unreachable block (ram,0x0001c000d677) */
/* WARNING: Removing unreachable block (ram,0x0001c000d686) */
/* WARNING: Removing unreachable block (ram,0x0001c000d68b) */
/* WARNING: Removing unreachable block (ram,0x0001c000d67d) */
/* WARNING: Removing unreachable block (ram,0x0001c000d68d) */
/* WARNING: Removing unreachable block (ram,0x0001c000d692) */
/* WARNING: Removing unreachable block (ram,0x0001c000d682) */
/* WARNING: Removing unreachable block (ram,0x0001c000d615) */
/* WARNING: Removing unreachable block (ram,0x0001c000d61e) */
/* WARNING: Removing unreachable block (ram,0x0001c000d69d) */
/* WARNING: Removing unreachable block (ram,0x0001c000d6a2) */
/* WARNING: Removing unreachable block (ram,0x0001c000d694) */
/* WARNING: Removing unreachable block (ram,0x0001c000d6c5) */
/* WARNING: Removing unreachable block (ram,0x0001c000d6a4) */
/* WARNING: Removing unreachable block (ram,0x0001c000d6be) */
/* WARNING: Removing unreachable block (ram,0x0001c000d6c3) */
/* WARNING: Removing unreachable block (ram,0x0001c000d6b5) */
/* WARNING: Removing unreachable block (ram,0x0001c000d6ba) */
/* WARNING: Removing unreachable block (ram,0x0001c000d699) */

void wil_details_EvaluateFeatureDependencies(void)

{
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 1c000d6d8 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_1c000d770;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_1c000d770;
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
LAB_1c000d770:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 1c000d7c0 =====

void wil_details_OnFeatureUsageProviderFlushNotification(int param_1)

{
  int iVar1;
  longlong *plVar2;
  
  iVar1 = g_wil_details_featureUsageCached;
  if (param_1 == 1) {
    LOCK();
    g_wil_details_featureUsageCached = 0;
    UNLOCK();
    if (iVar1 != 0) {
      for (plVar2 = &wil_details_featureDescriptors_z; plVar2 < &wil_details_featureDescriptors_z;
          plVar2 = plVar2 + 1) {
        if (*plVar2 != 0) {
          do {
            if (plVar2 == (longlong *)0x0) {
              return;
            }
            if ((*(uint *)plVar2[1] & 1) != 0) {
              wil_details_RecordCachedUsage((int)plVar2[3],(uint *)plVar2[1]);
            }
            plVar2 = plVar2 + 7;
            while( true ) {
              if (&UNK_1c0009f97 < plVar2) {
                return;
              }
              if (*plVar2 != 0) break;
              plVar2 = plVar2 + 1;
            }
          } while( true );
        }
      }
    }
  }
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 1c000d840 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  int iVar1;
  uint uVar2;
  longlong *plVar3;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = ___security_cookie ^ (ulonglong)auStack_48;
  for (plVar3 = &wil_details_featureDescriptors_z; plVar3 < &wil_details_featureDescriptors_z;
      plVar3 = plVar3 + 1) {
    if (*plVar3 != 0) goto LAB_1c000d93d;
  }
LAB_1c000d946:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_1c000d93d:
  if (plVar3 == (longlong *)0x0) goto LAB_1c000d946;
  if (((*(char *)((longlong)plVar3 + 0x1d) == '\0') && (*(char *)((longlong)plVar3 + 0x1e) == '\0'))
     && (*(char *)((longlong)plVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration((int)plVar3[3],1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_1c000d90e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_1c000d90e;
        uVar2 = local_20._4_4_ & 0x80;
      }
      uVar2 = uVar2 << 3 | 0x206;
    }
    LOCK();
    *(uint *)*plVar3 = *(uint *)*plVar3 ^ (*(uint *)*plVar3 ^ uVar2) & 0xf80;
    UNLOCK();
  }
  plVar3 = plVar3 + 7;
  while( true ) {
    if (&UNK_1c0009f97 < plVar3) goto LAB_1c000d946;
    if (*plVar3 != 0) break;
    plVar3 = plVar3 + 1;
  }
  goto LAB_1c000d93d;
}



===== KbdHid_AddDevice @ 1c000d970 =====

int KbdHid_AddDevice(longlong param_1,longlong param_2)

{
  short sVar1;
  int iVar2;
  longlong lVar3;
  undefined4 *puVar4;
  longlong *_Dst;
  undefined2 uVar5;
  longlong local_res18;
  undefined *in_stack_ffffffffffffffb8;
  ulonglong uVar6;
  undefined4 uVar7;
  ulonglong in_stack_ffffffffffffffc0;
  
  _Dst = (longlong *)0x0;
  local_res18 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffb8 = &WPP_6ab2d906fdee3c84bc9e6e4168830b21_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0xc,
                     &WPP_6ab2d906fdee3c84bc9e6e4168830b21_Traceguids);
  }
  uVar6 = (ulonglong)in_stack_ffffffffffffffb8 & 0xffffffff00000000;
  iVar2 = IoCreateDevice(param_1,0x328,0,0xb,uVar6,in_stack_ffffffffffffffc0 & 0xffffffffffffff00,
                         &local_res18);
  uVar7 = (undefined4)(uVar6 >> 0x20);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000de75;
    uVar5 = 0xd;
LAB_1c000da31:
LAB_1c000da36:
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,uVar5,
                       &WPP_6ab2d906fdee3c84bc9e6e4168830b21_Traceguids,(char)param_1,(char)iVar2);
  }
  else {
    _Dst = *(longlong **)(local_res18 + 0x40);
    memset(_Dst,0,0x328);
    lVar3 = IoAttachDeviceToDeviceStack(local_res18,param_2);
    _Dst[1] = lVar3;
    if (lVar3 != 0) {
      *_Dst = local_res18;
      *(undefined1 *)(_Dst + 0xb) = 0;
      *(undefined1 *)((longlong)_Dst + 0x5a) = 0;
      LOCK();
      UNLOCK();
      sVar1 = (short)DAT_1c000a1b0;
      DAT_1c000a1b0 = DAT_1c000a1b0 + 1;
      _Dst[2] = param_2;
      *(short *)((longlong)_Dst + 0x5c) = sVar1 + 1;
      KeInitializeSpinLock(_Dst + 0x5d);
      lVar3 = IoAllocateIrp(CONCAT71((int7)((ulonglong)_Dst[1] >> 8),*(undefined1 *)(_Dst[1] + 0x4c)
                                    ),0);
      _Dst[0xd] = lVar3;
      if (lVar3 == 0) {
        iVar2 = -0x3fffff66;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000de75;
        iVar2 = -0x3fffff66;
        uVar5 = 0xe;
        param_1 = local_res18;
        goto LAB_1c000da31;
      }
      KeInitializeEvent(_Dst + 5,1,0);
      KeInitializeEvent(_Dst + 8,0,1);
      IoInitializeRemoveLockEx(_Dst + 0x13,0x4864624b,1,0,CONCAT44(uVar7,0x20));
      _Dst[0x10] = 0;
      *(undefined4 *)(_Dst + 0x17) = 1;
      _Dst[0x18] = 0;
      *(undefined4 *)(_Dst + 0x19) = 0;
      KeInitializeEvent(_Dst + 0x1a,1,0);
      uVar5 = *(undefined2 *)((longlong)_Dst + 0x5c);
      *(undefined2 *)(_Dst + 0x21) = uVar5;
      *(undefined2 *)(_Dst + 0x25) = uVar5;
      *(undefined2 *)((longlong)_Dst + 0x12e) = uVar5;
      *(undefined4 *)((longlong)_Dst + 0x10a) = 0;
      *(undefined4 *)((longlong)_Dst + 0x114) = 0;
      *(undefined4 *)(_Dst + 0x23) = 0x10051;
      _Dst[0x2b] = 0x51;
      *(undefined4 *)((longlong)_Dst + 0x11c) = 0x3000c;
      *(undefined2 *)(_Dst + 0x24) = 0x65;
      *(undefined4 *)((longlong)_Dst + 0x124) = 1;
      *(undefined4 *)((longlong)_Dst + 0x12a) = 0xfa0002;
      *(undefined4 *)(_Dst + 0x26) = 0x3e8001e;
      *(undefined4 *)((longlong)_Dst + 0x134) = 1;
      *(undefined2 *)(_Dst + 0x27) = 0;
      *(undefined1 *)((longlong)_Dst + 0x13a) = 0;
      *(undefined4 *)((longlong)_Dst + 0x13c) = 0;
      KeInitializeEvent(_Dst + 0x28,0,0);
      *(undefined2 *)(_Dst + 0x2c) = *(undefined2 *)((longlong)_Dst + 0x5c);
      *(undefined2 *)((longlong)_Dst + 0x164) = *(undefined2 *)((longlong)_Dst + 0x5c);
      *(undefined2 *)((longlong)_Dst + 0x162) = 0;
      *(undefined4 *)((longlong)_Dst + 0x166) = 0xfa001e;
      KeInitializeDpc(_Dst + 0x2e,KbdHid_AutoRepeat,_Dst);
      KeInitializeTimer(_Dst + 0x36);
      *(undefined4 *)((longlong)_Dst + 500) = 0xffffffff;
      *(undefined4 *)(_Dst + 0x3f) = 0x21;
      *(undefined4 *)(_Dst + 0x3e) = 0xffd9da60;
      KeInitializeDpc(_Dst + 0x40,KbdHid_InitiateStartRead,_Dst);
      KeInitializeTimer(_Dst + 0x48);
      _Dst[0x50] = -500000;
      *(undefined1 *)(_Dst + 0x51) = 0;
      *(undefined4 *)(_Dst + 3) = 1;
      PoSetPowerState(local_res18,1,1);
      *(undefined4 *)(_Dst + 0x54) = 2;
      _Dst[0x55] = (longlong)&KbdHid_WmiGuidList;
      _Dst[0x56] = (longlong)KbdHid_QueryWmiRegInfo;
      _Dst[0x57] = (longlong)KbdHid_QueryWmiDataBlock;
      _Dst[0x58] = (longlong)KbdHid_SetWmiDataItem;
      _Dst[0x59] = (longlong)KbdHid_SetWmiDataItem;
      _Dst[0x5a] = 0;
      _Dst[0x5b] = 0;
      *(uint *)(local_res18 + 0x30) = *(uint *)(local_res18 + 0x30) | 0x2000;
      *(uint *)(local_res18 + 0x30) = *(uint *)(local_res18 + 0x30) & 0xffffff7f;
      *(undefined4 *)(_Dst + 0x60) = 0;
      *(undefined4 *)(_Dst + 0x62) = 0;
      *(undefined1 *)((longlong)_Dst + 0x314) = 0;
      KeInitializeSpinLock(_Dst + 0x61);
      lVar3 = IoAllocateWorkItem(local_res18);
      _Dst[0x5f] = lVar3;
      if (lVar3 != 0) goto LAB_1c000de3a;
      iVar2 = -0x3fffff66;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000de75;
      iVar2 = -0x3fffff66;
      uVar5 = 0xf;
      param_1 = local_res18;
      goto LAB_1c000da36;
    }
    iVar2 = -0x3fffff63;
    puVar4 = (undefined4 *)IoAllocateErrorLogEntry(param_1,0x30);
    if (puVar4 != (undefined4 *)0x0) {
      puVar4[3] = 0xc0050002;
      *puVar4 = 0;
      *(undefined8 *)(puVar4 + 6) = 0;
      puVar4[4] = 0;
      puVar4[5] = 0xc000009d;
      IoWriteErrorLogEntry(puVar4);
    }
  }
LAB_1c000de3a:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x10,
                       &WPP_6ab2d906fdee3c84bc9e6e4168830b21_Traceguids,(char)local_res18,
                       (char)iVar2);
  }
  if (-1 < iVar2) {
    return iVar2;
  }
LAB_1c000de75:
  if (local_res18 != 0) {
    if (_Dst != (longlong *)0x0) {
      if (_Dst[1] != 0) {
        IoDetachDevice();
      }
      if (_Dst[0xd] != 0) {
        IoFreeIrp();
      }
    }
    IoDeleteDevice(local_res18);
  }
  return iVar2;
}



===== KbdHid_CallHidClass @ 1c000dee4 =====

int KbdHid_CallHidClass(longlong param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
                       undefined8 param_5,undefined4 param_6)

{
  int iVar1;
  longlong lVar2;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,10,
                     &WPP_6ab2d906fdee3c84bc9e6e4168830b21_Traceguids);
  }
  KeInitializeEvent(&local_28,0,0);
  lVar2 = IoBuildDeviceIoControlRequest
                    (param_2,*(undefined8 *)(param_1 + 8),0,0,param_5,param_6,0,&local_28,&local_38)
  ;
  if (lVar2 == 0) {
    iVar1 = -0x3fffffff;
  }
  else {
    *(undefined8 *)(*(longlong *)(lVar2 + 0xb8) + -0x18) = *(undefined8 *)(param_1 + 0x80);
    iVar1 = IofCallDriver(*(undefined8 *)(param_1 + 8),lVar2);
    if (iVar1 == 0x103) {
      iVar1 = KeWaitForSingleObject(&local_28,0,0,0,0);
    }
    if (-1 < iVar1) {
      iVar1 = (int)local_38;
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0xb,
                       &WPP_6ab2d906fdee3c84bc9e6e4168830b21_Traceguids);
    }
  }
  return iVar1;
}



===== KbdHid_PnP @ 1c000e080 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int KbdHid_PnP(longlong param_1,longlong param_2)

{
  byte bVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  int iVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  longlong local_res8;
  
  puVar2 = *(undefined8 **)(param_1 + 0x40);
  lVar5 = *(longlong *)(param_2 + 0xb8);
  uVar8 = 1;
  puVar3 = (undefined8 *)puVar2[0xe];
  iVar4 = IoAcquireRemoveLockEx(puVar2 + 0x13);
  if (iVar4 < 0) {
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(int *)(param_2 + 0x30) = iVar4;
    IofCompleteRequest(param_2,0);
    return iVar4;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqc(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  plVar6 = (longlong *)(param_2 + 0xb8);
  bVar1 = *(byte *)(lVar5 + 1);
  if (bVar1 < 10) {
    if (bVar1 != 9) {
      if (bVar1 != 0) {
        if (bVar1 != 1) {
          if (bVar1 == 2) {
            uVar8 = *puVar2;
            IoWMIRegistrationControl(uVar8,2);
            local_res8 = puVar2[0x3e];
            if ((puVar2[100] != 0) && (0xfa < _DAT_fffff78000000014 - puVar2[100])) {
              TraceLoggingKeyRepeatOnRemoval(uVar8,_DAT_fffff78000000014 - puVar2[100]);
            }
            KbdHid_CancelAutoRepeatTimer(puVar2,4);
            KeCancelTimer(puVar2 + 0x48);
            if ((longlong)puVar2[0x50] < local_res8) {
              local_res8 = puVar2[0x50];
            }
            KeDelayExecutionThread(0,0,&local_res8);
            *(undefined1 *)((longlong)puVar2 + 0x59) = 1;
            KeWaitForSingleObject(puVar2 + 8,0,0,0,0);
            IoCancelIrp(puVar2[0xd]);
            *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
            *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
            *(undefined4 *)(param_2 + 0x30) = 0;
            iVar4 = IofCallDriver(puVar2[1],param_2);
            IoReleaseRemoveLockAndWaitEx(puVar2 + 0x13,param_2,0x20);
            IoFreeIrp(puVar2[0xd]);
            IoFreeWorkItem(puVar2[0x5f]);
            if (puVar3 != (undefined8 *)0x0) {
              ExFreePoolWithTag(*puVar3,0);
              IoFreeMdl(puVar3[0x12]);
              ExFreePoolWithTag(puVar3,0);
            }
            FreeKeyboardUsageMappingList((longlong)puVar2);
            IoDetachDevice(puVar2[1]);
            IoDeleteDevice(*puVar2);
            return iVar4;
          }
          if (bVar1 != 3) {
            if (bVar1 == 4) {
              *(undefined1 *)(puVar2 + 0xb) = 0;
            }
            else if ((bVar1 != 5) && (bVar1 != 6)) goto LAB_1c000e48a;
          }
        }
        goto LAB_1c000e486;
      }
      if (*(char *)(puVar2 + 0xb) == '\0') {
        puVar3 = (undefined8 *)*plVar6;
        uVar7 = 0;
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
        KeInitializeEvent(puVar2 + 0x1e,0);
        lVar5 = *plVar6;
        *(code **)(lVar5 + -0x10) = KbdHid_PnPComplete;
        *(undefined8 **)(lVar5 + -8) = puVar2;
        *(undefined1 *)(lVar5 + -0x45) = 0xe0;
        *(undefined4 *)(param_2 + 0x30) = 0;
        lVar5 = param_2;
        iVar4 = IofCallDriver(puVar2[1]);
        if (iVar4 == 0x103) {
          uVar8 = 0;
          uVar7 = 0;
          lVar5 = 0;
          KeWaitForSingleObject(puVar2 + 0x1e);
          iVar4 = *(int *)(param_2 + 0x30);
        }
        if ((-1 < iVar4) && (-1 < *(int *)(param_2 + 0x30))) {
          if (*(char *)((longlong)puVar2 + 0x5a) == '\0') {
            iVar4 = KbdHid_StartDevice(puVar2,lVar5,uVar7,uVar8);
            if (iVar4 < 0) goto LAB_1c000e44a;
            IoWMIRegistrationControl(param_1,1);
            *(undefined1 *)((longlong)puVar2 + 0x5a) = 1;
          }
          *(undefined1 *)(puVar2 + 0xb) = 1;
        }
LAB_1c000e44a:
        *(int *)(param_2 + 0x30) = iVar4;
        *(undefined8 *)(param_2 + 0x38) = 0;
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x14,
                           &WPP_6ab2d906fdee3c84bc9e6e4168830b21_Traceguids);
        }
        iVar4 = 0;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      IofCompleteRequest(param_2,0);
      goto LAB_1c000e4a6;
    }
  }
  else if ((((((bVar1 != 10) && (bVar1 != 0xb)) && (bVar1 != 0xf)) &&
            ((bVar1 != 0x10 && (bVar1 != 0x11)))) &&
           ((bVar1 != 0x12 && ((bVar1 != 0x13 && (bVar1 != 0x14)))))) && (bVar1 == 0x17)) {
LAB_1c000e486:
    *(undefined4 *)(param_2 + 0x30) = 0;
  }
LAB_1c000e48a:
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *plVar6 = *plVar6 + 0x48;
  iVar4 = IofCallDriver(puVar2[1],param_2);
LAB_1c000e4a6:
  IoReleaseRemoveLockEx(puVar2 + 0x13,param_2,0x20);
  return iVar4;
}



===== KbdHid_StartDevice @ 1c000e4ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int KbdHid_StartDevice(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong lVar6;
  uint uVar7;
  undefined8 uVar8;
  uint uVar9;
  ulonglong uVar10;
  undefined1 auStackY_d8 [32];
  undefined4 local_98 [2];
  undefined8 local_90;
  ulonglong local_88;
  undefined4 local_80;
  undefined4 local_78;
  ushort uStack_74;
  undefined2 uStack_72;
  longlong lStack_70;
  longlong local_68;
  longlong lStack_60;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  ulonglong local_38;
  
  local_38 = ___security_cookie ^ (ulonglong)auStackY_d8;
  uVar8 = 0x40;
  memset(&local_78,0,0x40);
  local_88 = 0;
  plVar5 = (longlong *)0x0;
  local_90 = 0;
  local_98[0] = 0;
  local_80 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar8 = 5;
    param_4 = 0x11;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x11,
                     &WPP_6ab2d906fdee3c84bc9e6e4168830b21_Traceguids);
  }
  LoadKeyboardUsageMappingList((longlong)param_1);
  iVar1 = KbdHid_CallHidClass((longlong)param_1,0xb01a8,uVar8,param_4,&local_88,0xc);
  if (iVar1 < 0) {
    return iVar1;
  }
  uVar8 = 0x4864624b;
  lVar4 = ExAllocatePool2(0x40,local_88 & 0xffffffff);
  if (lVar4 == 0) {
    return -0x3fffff66;
  }
  iVar1 = KbdHid_CallHidClass((longlong)param_1,0xb0193,uVar8,param_4,lVar4,(undefined4)local_88);
  if ((-1 < iVar1) && (iVar1 = HidP_GetCaps(lVar4,&local_78), -1 < iVar1)) {
    uVar2 = (uint)&local_90;
    *(undefined2 *)(param_1 + 0x24) = local_48._2_2_;
    iVar1 = IoOpenDeviceRegistryKey(param_1[2],1,0x1f0000);
    if (-1 < iVar1) {
      iVar1 = KbdHid_QueryDeviceKey(local_90,L"KeyboardTypeOverride",local_98,uVar2);
      if (-1 < iVar1) {
        *(char *)(param_1 + 0x23) = (char)local_98[0];
        *(undefined4 *)(param_1 + 0x2b) = local_98[0];
      }
      iVar1 = KbdHid_QueryDeviceKey(local_90,L"KeyboardSubtypeOverride",local_98,uVar2);
      if (-1 < iVar1) {
        *(char *)((longlong)param_1 + 0x119) = (char)local_98[0];
        *(undefined4 *)((longlong)param_1 + 0x15c) = local_98[0];
      }
      iVar1 = KbdHid_QueryDeviceKey(local_90,L"KeyboardNumberTotalKeysOverride",local_98,uVar2);
      if (-1 < iVar1) {
        *(undefined2 *)(param_1 + 0x24) = (undefined2)local_98[0];
      }
      iVar1 = KbdHid_QueryDeviceKey(local_90,L"KeyboardNumberFunctionKeysOverride",local_98,uVar2);
      if (-1 < iVar1) {
        *(undefined2 *)((longlong)param_1 + 0x11c) = (undefined2)local_98[0];
      }
      iVar1 = KbdHid_QueryDeviceKey(local_90,L"KeyboardNumberIndicatorsOverride",local_98,uVar2);
      if (-1 < iVar1) {
        *(undefined2 *)((longlong)param_1 + 0x11e) = (undefined2)local_98[0];
      }
      ZwClose(local_90);
    }
    uVar2 = HidP_MaxUsageListLength(0,7,lVar4);
    if (uVar2 < 0x40000000) {
      uVar7 = uStack_74 + 7 & 0xfffffff8;
      uVar9 = uVar2 * 4 + 7 & 0xfffffff8;
      uVar10 = (ulonglong)uVar9;
      if (uVar10 <= ((ulonglong)~uVar7 - 0x98) / 6) {
        plVar5 = (longlong *)ExAllocatePool2(0x40,uVar7 + uVar9 * 6 + 0x98,0x4864624b);
        param_1[0xe] = plVar5;
        if (plVar5 != (longlong *)0x0) {
          *plVar5 = lVar4;
          plVar5[1] = CONCAT26(uStack_72,CONCAT24(uStack_74,local_78));
          plVar5[2] = lStack_70;
          plVar5[3] = local_68;
          plVar5[4] = lStack_60;
          *(undefined4 *)(plVar5 + 5) = local_58;
          *(undefined4 *)((longlong)plVar5 + 0x2c) = uStack_54;
          *(undefined4 *)(plVar5 + 6) = uStack_50;
          *(undefined4 *)((longlong)plVar5 + 0x34) = uStack_4c;
          plVar5[10] = (longlong)(plVar5 + 0x13);
          *(undefined4 *)(plVar5 + 7) = local_48;
          *(undefined4 *)((longlong)plVar5 + 0x3c) = uStack_44;
          *(undefined4 *)(plVar5 + 8) = uStack_40;
          *(undefined4 *)((longlong)plVar5 + 0x44) = uStack_3c;
          *(uint *)(plVar5 + 9) = uVar2;
          lVar6 = (longlong)(plVar5 + 0x13) + (ulonglong)uVar7;
          plVar5[0xf] = lVar6;
          lVar6 = lVar6 + uVar10;
          plVar5[0xb] = lVar6;
          lVar6 = lVar6 + uVar10;
          plVar5[0xc] = lVar6;
          lVar6 = lVar6 + uVar10;
          plVar5[0x10] = lVar6;
          lVar6 = lVar6 + uVar10;
          plVar5[0xd] = lVar6;
          plVar5[0xe] = uVar10 + lVar6;
          KeInitializeSpinLock(plVar5 + 0x11);
          lVar6 = IoAllocateMdl(plVar5[10],uStack_74,0,0);
          plVar5[0x12] = lVar6;
          if (lVar6 != 0) {
            MmBuildMdlForNonPagedPool(lVar6);
            param_1[100] = 0;
            lVar6 = IoAllocateIrp(CONCAT71((int7)((ulonglong)param_1[1] >> 8),
                                           *(undefined1 *)(param_1[1] + 0x4c)),0);
            param_1[99] = lVar6;
            if (lVar6 != 0) {
              lVar6 = *(longlong *)(lVar6 + 0xb8);
              *(undefined1 *)(lVar6 + -0x48) = 0xe;
              *(undefined4 *)(lVar6 + -0x30) = 0xb0267;
              *(undefined4 *)(lVar6 + -0x38) = 0;
              *(undefined4 *)(lVar6 + -0x40) = 0;
              lVar6 = param_1[99];
              iVar1 = IoSetCompletionRoutineEx
                                (*param_1,lVar6,KbdHid_PresenceNotificationCompleted,param_1);
              if (iVar1 < 0) {
                lVar6 = *(longlong *)(lVar6 + 0xb8);
                *(code **)(lVar6 + -0x10) = KbdHid_PresenceNotificationCompleted;
                *(undefined8 **)(lVar6 + -8) = param_1;
                *(undefined1 *)(lVar6 + -0x45) = 0xe0;
              }
              IoAcquireRemoveLockEx(param_1 + 0x13,param_1[99],"",1);
              iVar3 = IofCallDriver(param_1[1],param_1[99]);
              if (iVar3 < 0) {
                IoReleaseRemoveLockEx(param_1 + 0x13,param_1[99],0x20);
              }
              iVar1 = 0;
              if (iVar3 != 0x103) {
                iVar1 = iVar3;
              }
              if (-1 < iVar1) {
                return iVar1;
              }
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x12,
                                   &WPP_6ab2d906fdee3c84bc9e6e4168830b21_Traceguids,(char)*param_1,
                                   (char)iVar1);
              }
              goto LAB_1c000e9cb;
            }
          }
        }
        iVar1 = -0x3fffff66;
        goto LAB_1c000e9cb;
      }
    }
    iVar1 = -0x3fffffff;
  }
LAB_1c000e9cb:
  ExFreePoolWithTag(lVar4,0);
  if (plVar5 != (longlong *)0x0) {
    if (plVar5[0x12] != 0) {
      IoFreeMdl();
    }
    ExFreePoolWithTag(plVar5,0);
    param_1[0xe] = 0;
  }
  return iVar1;
}



===== KbdHid_SendS0IdleStopResumeIrp @ 1c000ea44 =====

int KbdHid_SendS0IdleStopResumeIrp(undefined8 *param_1,int param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 in_stack_ffffffffffffff90;
  uint uVar8;
  uint in_stack_ffffffffffffff98;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  uVar8 = (uint)((ulonglong)in_stack_ffffffffffffff90 >> 0x20);
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  local_48 = 0;
  uStack_40 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x16,
                     &WPP_7e65f2fc34253e54541f06c7e51d4e62_Traceguids);
  }
  KeInitializeEvent(&local_38,0);
  uVar5 = 0xb025b;
  if (param_2 != 1) {
    uVar5 = 0xb025f;
  }
  uVar4 = 0;
  uVar6 = 0;
  lVar2 = IoBuildDeviceIoControlRequest
                    (uVar5,param_1[1],0,0,0,(ulonglong)uVar8 << 0x20,
                     in_stack_ffffffffffffff98 & 0xffffff00,&local_38,&local_48);
  if (lVar2 == 0) {
    iVar1 = -0x3fffff66;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3fffff66;
    }
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x17,
                       &WPP_7e65f2fc34253e54541f06c7e51d4e62_Traceguids,(char)*param_1,0x9a);
  }
  else {
    lVar3 = lVar2;
    iVar1 = IofCallDriver(param_1[1]);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qLqd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar3,uVar4,0x18,uVar6,(char)*param_1,
                 (char)uVar5,(char)lVar2,(char)iVar1);
    }
    if (iVar1 == 0x103) {
      uVar7 = 0;
      uVar6 = 0;
      uVar4 = 0;
      KeWaitForSingleObject(&local_38,0,0,0);
      iVar1 = (int)local_48;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return (int)local_48;
      }
      WPP_RECORDER_SF_qLqd
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,uVar6,0x19,uVar7,(char)*param_1,
                 (char)uVar5,(char)lVar2,(char)local_48);
    }
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x1a,
                     &WPP_7e65f2fc34253e54541f06c7e51d4e62_Traceguids);
  }
  return iVar1;
}



===== KbdHid_QueryWmiDataBlock @ 1c000ec70 =====

void KbdHid_QueryWmiDataBlock
               (longlong param_1,undefined8 param_2,int param_3,undefined8 param_4,
               undefined8 param_5,undefined4 *param_6,uint param_7,undefined8 *param_8)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  
  uVar6 = 0;
  lVar4 = *(longlong *)(param_1 + 0x40);
  if (param_3 == 0) {
    uVar6 = 0x14;
    if (param_7 < 0x14) {
LAB_1c000ecc6:
      uVar5 = 0xc0000023;
      goto LAB_1c000ed00;
    }
    uVar3 = *(undefined4 *)(lVar4 + 0x124);
    uVar1 = *(ushort *)(lVar4 + 0x11c);
    uVar2 = *(ushort *)(lVar4 + 0x11e);
    *(undefined4 *)param_8 = 2;
    *(undefined4 *)((longlong)param_8 + 4) = uVar3;
    *(undefined4 *)(param_8 + 1) = 0;
    *(uint *)((longlong)param_8 + 0xc) = (uint)uVar1;
    *(uint *)(param_8 + 2) = (uint)uVar2;
  }
  else {
    if (param_3 != 1) {
      uVar5 = 0xc0000295;
      goto LAB_1c000ed00;
    }
    uVar6 = 8;
    if (param_7 < 8) goto LAB_1c000ecc6;
    *param_8 = *(undefined8 *)(lVar4 + 0x158);
  }
  uVar5 = 0;
  *param_6 = uVar6;
LAB_1c000ed00:
  WmiCompleteRequest(param_1,param_2,uVar5,uVar6,0);
  return;
}



===== KbdHid_QueryWmiRegInfo @ 1c000ed30 =====

undefined8
KbdHid_QueryWmiRegInfo
          (longlong param_1,undefined4 *param_2,undefined8 param_3,undefined8 *param_4,
          undefined8 param_5,undefined8 *param_6)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  *param_2 = 0x20;
  *param_4 = &Globals;
  *param_6 = *(undefined8 *)(lVar1 + 0x10);
  return 0;
}



===== KbdHid_SetWmiDataItem @ 1c000ed60 =====

void KbdHid_SetWmiDataItem(undefined8 param_1,undefined8 param_2,int param_3)

{
  undefined8 uVar1;
  
  if ((param_3 == 0) || (uVar1 = 0xc0000295, param_3 == 1)) {
    uVar1 = 0xc00002c6;
  }
  WmiCompleteRequest(param_1,param_2,uVar1,0,0);
  return;
}



===== KbdHid_SystemControl @ 1c000eda0 =====

undefined4 KbdHid_SystemControl(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  int local_res8 [2];
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_res8[0] = 0;
  uVar2 = WmiSystemControl(lVar1 + 0x2a0,param_1,param_2,local_res8);
  if (local_res8[0] != 0) {
    if (local_res8[0] == 1) {
      IofCompleteRequest(param_2,0);
    }
    else {
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      uVar2 = IofCallDriver(*(undefined8 *)(lVar1 + 8),param_2,local_res8[0] + -2);
    }
  }
  return uVar2;
}



===== OpenSubkey @ 1c000ee3c =====

void OpenSubkey(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_1c = 0;
  local_38 = 0x30;
  local_18 = 0;
  uStack_10 = 0;
  local_20 = 0x240;
  local_30 = param_2;
  local_28 = param_3;
  ZwOpenKey(0,0x20019,&local_38);
  return;
}



===== entry @ 1c000f010 =====

void entry(longlong param_1,ushort *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 1c000f044 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __security_init_cookie(void)

{
  code *pcVar1;
  
  if ((___security_cookie == 0) || (___security_cookie == 0x2b992ddfa232)) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(6);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  ___security_cookie_complement = ~___security_cookie;
  return;
}



===== DriverEntry @ 1c000f078 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DriverEntry(longlong param_1,ushort *param_2)

{
  undefined8 uVar1;
  
  _DAT_1c000a168 = 1;
  _WPP_MAIN_CB = 0;
  DAT_1c000a148 = &WPP_ThisDir_CTLGUID_KbdHidTraceGuid;
  DAT_1c000a150 = 0;
  _DAT_1c000a160 = 0;
  _DAT_1c000a180 = 0;
  _DAT_1c000a188 = 0;
  WppLoadTracingSupport();
  _DAT_1c000a160 = 0;
  WppInitKm(param_1,param_2);
  wil_InitializeFeatureStaging();
  DAT_1c000a1a8 = (void *)0x0;
  _DAT_1c000a1b8 = 0;
  _DAT_1c000a1b0 = 0x100000000;
  _Globals = (ulonglong)CONCAT22(*param_2 + 2,*param_2);
  DAT_1c000a1a8 = (void *)ExAllocatePool2(0x100,*param_2 + 2,0x4864624b);
  if (DAT_1c000a1a8 == (void *)0x0) {
    if (g_wil_details_featureChangeNotification != 0) {
      RtlUnregisterFeatureConfigurationChangeNotification();
      g_wil_details_featureChangeNotification = 0;
    }
    if (g_wil_details_featureUsageProvider != 0) {
      RtlUnregisterFeatureUsageProvider();
      g_wil_details_featureUsageProvider = 0;
    }
    g_wil_details_isFeatureStagingInitialized = 0;
    WppCleanupKm(param_1);
    uVar1 = 0xc000009a;
  }
  else {
    memcpy(DAT_1c000a1a8,*(void **)(param_2 + 4),(ulonglong)*param_2);
    Kbdhid_ServiceParameters(param_1,(longlong)DAT_1c000a1a8);
    *(code **)(param_1 + 0x70) = KbdHid_Create;
    *(code **)(param_1 + 0x80) = KbdHid_Close;
    *(code **)(param_1 + 0xe8) = KbdHid_IOCTL;
    *(code **)(param_1 + 0xe0) = KbdHid_PassThrough;
    *(code **)(param_1 + 0xb8) = KbdHid_Flush;
    *(code **)(param_1 + 0x148) = KbdHid_PnP;
    *(code **)(param_1 + 0x120) = KbdHid_Power;
    *(code **)(param_1 + 0x128) = KbdHid_SystemControl;
    *(code **)(param_1 + 0x68) = KbdHid_Unload;
    *(code **)(*(longlong *)(param_1 + 0x30) + 8) = KbdHid_AddDevice;
    uVar1 = 0;
  }
  return uVar1;
}



===== KbdHidCrashDump @ 1c000f254 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void KbdHidCrashDump(longlong param_1)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  longlong lVar4;
  code *pcVar5;
  longlong lVar6;
  undefined1 auStack_118 [32];
  undefined8 local_f8;
  uint local_e8 [2];
  undefined8 local_e0;
  longlong local_d8;
  int local_d0;
  int local_cc;
  uint local_c8 [2];
  undefined8 local_c0;
  undefined8 uStack_b8;
  byte local_a8 [144];
  ulonglong local_18;
  
  local_18 = ___security_cookie ^ (ulonglong)auStack_118;
  local_a8[0] = 0;
  local_a8[1] = 0x29;
  local_a8[2] = 2;
  local_a8[3] = 3;
  local_e0 = 0;
  local_cc = 0;
  local_d0 = 0;
  local_c8[0] = 0;
  local_e8[0] = 0;
  local_a8[4] = 4;
  local_a8[5] = 5;
  local_a8[6] = 6;
  local_a8[7] = 7;
  local_a8[8] = 8;
  local_a8[9] = 9;
  local_a8[10] = 10;
  local_a8[0xb] = 0xb;
  local_a8[0xc] = 0xc;
  local_a8[0xd] = 0xd;
  local_a8[0xe] = 0x7d;
  local_a8[0xf] = 0xe;
  local_a8[0x10] = 0xf;
  local_a8[0x11] = 0x10;
  local_a8[0x12] = 0x11;
  local_a8[0x13] = 0x12;
  local_a8[0x14] = 0x13;
  local_a8[0x15] = 0x14;
  local_a8[0x16] = 0x15;
  local_a8[0x17] = 0x16;
  local_a8[0x18] = 0x17;
  local_a8[0x19] = 0x18;
  local_a8[0x1a] = 0x19;
  local_a8[0x1b] = 0x1a;
  local_a8[0x1c] = 0x1b;
  local_a8[0x1d] = 0;
  local_a8[0x1e] = 0x3a;
  local_a8[0x1f] = 0x1e;
  local_a8[0x20] = 0x1f;
  local_a8[0x21] = 0x20;
  local_a8[0x22] = 0x21;
  local_a8[0x23] = 0x22;
  local_a8[0x24] = 0x23;
  local_a8[0x25] = 0x24;
  local_a8[0x26] = 0x25;
  local_a8[0x27] = 0x26;
  local_a8[0x28] = 0x27;
  local_a8[0x29] = 0x28;
  local_a8[0x2a] = 0x2b;
  local_a8[0x2b] = 0x1c;
  local_a8[0x2c] = 0x2a;
  local_a8[0x2d] = 0;
  local_a8[0x2e] = 0x2c;
  local_a8[0x2f] = 0x2d;
  local_a8[0x30] = 0x2e;
  local_a8[0x31] = 0x2f;
  local_a8[0x32] = 0x30;
  local_a8[0x33] = 0x31;
  local_a8[0x34] = 0x32;
  local_a8[0x35] = 0x33;
  local_a8[0x36] = 0x34;
  local_a8[0x37] = 0x35;
  local_a8[0x38] = 0x73;
  local_a8[0x39] = 0x36;
  local_a8[0x3a] = 0x1d;
  local_a8[0x3b] = 0;
  local_a8[0x3c] = 0x38;
  local_a8[0x3d] = 0x39;
  local_a8[0x3e] = 0xb8;
  local_a8[0x3f] = 0;
  local_a8[0x40] = 0x9d;
  local_a8[0x41] = 0;
  local_a8[0x42] = 0;
  local_a8[0x43] = 0;
  local_a8[0x44] = 0;
  local_a8[0x45] = 0;
  local_a8[0x46] = 0;
  local_a8[0x47] = 0;
  local_a8[0x48] = 0;
  local_a8[0x49] = 0;
  local_a8[0x4a] = 0;
  local_a8[0x4b] = 0xd2;
  local_a8[0x4c] = 0xd3;
  local_a8[0x4d] = 0;
  local_a8[0x4e] = 0;
  local_a8[0x4f] = 0xcb;
  local_a8[0x50] = 199;
  local_a8[0x51] = 0xcf;
  local_a8[0x52] = 0;
  local_a8[0x53] = 200;
  local_a8[0x54] = 0xd0;
  local_a8[0x55] = 0xc9;
  local_a8[0x56] = 0xd1;
  local_a8[0x57] = 0;
  local_a8[0x58] = 0;
  local_a8[0x59] = 0xcd;
  local_a8[0x5a] = 0x45;
  local_a8[0x5b] = 0x47;
  local_a8[0x5c] = 0x4b;
  local_a8[0x5d] = 0x4f;
  local_a8[0x5e] = 0;
  local_a8[0x5f] = 0xb5;
  local_a8[0x60] = 0x48;
  local_a8[0x61] = 0x4c;
  local_a8[0x62] = 0x50;
  local_a8[99] = 0x52;
  local_a8[100] = 0x37;
  local_a8[0x65] = 0x49;
  local_a8[0x66] = 0x4d;
  local_a8[0x67] = 0x51;
  local_a8[0x68] = 0x53;
  local_a8[0x69] = 0x4a;
  local_a8[0x6a] = 0x4e;
  local_a8[0x6b] = 0;
  local_a8[0x6c] = 0x9c;
  local_a8[0x6d] = 0;
  local_a8[0x6e] = 1;
  local_a8[0x6f] = 0;
  local_a8[0x70] = 0x3b;
  local_a8[0x71] = 0x3c;
  local_a8[0x72] = 0x3d;
  local_a8[0x73] = 0x3e;
  local_a8[0x74] = 0x3f;
  local_a8[0x75] = 0x40;
  local_a8[0x76] = 0x41;
  local_a8[0x77] = 0x42;
  local_a8[0x78] = 0x43;
  local_a8[0x79] = 0x44;
  local_a8[0x7a] = 0x57;
  local_a8[0x7b] = 0x58;
  local_a8[0x7c] = 0;
  local_a8[0x7d] = 0x46;
  local_a8[0x7e] = 0;
  local_a8[0x7f] = 0;
  local_a8[0x80] = 0;
  local_a8[0x81] = 0;
  local_a8[0x82] = 0;
  local_a8[0x83] = 0x7b;
  local_a8[0x84] = 0x79;
  local_a8[0x85] = 0x70;
  local_d8 = 0;
  lVar4 = ExAllocatePool2(0x100,0xa8,0x4864624b);
  if (lVar4 != 0) {
    RtlInitUnicodeString(&local_e0,0);
    lVar6 = -1;
    do {
      lVar6 = lVar6 + 1;
    } while (*(short *)(param_1 + lVar6 * 2) != 0);
    sVar2 = ((short)lVar6 + 0xc) * 2;
    local_e0._0_4_ = CONCAT22(sVar2,(undefined2)local_e0);
    local_d8 = ExAllocatePool2(0x100,sVar2,0x4864624b);
    if ((local_d8 != 0) && (iVar3 = RtlAppendUnicodeToString(&local_e0,param_1), -1 < iVar3)) {
      iVar3 = RtlAppendUnicodeToString(&local_e0,L"\\Crashdump");
      lVar6 = local_d8;
      if ((-1 < iVar3) && ((local_e0 & 0xffff) + 2 <= (local_e0 >> 0x10 & 0xffff))) {
        local_c0 = 0;
        uStack_b8 = 0;
        *(undefined2 *)(local_d8 + 2 + (local_e0 >> 1 & 0x7fff) * 2) = 0;
        *(undefined4 *)(lVar4 + 8) = 0x120;
        *(wchar_t **)(lVar4 + 0x10) = L"Dump1Keys";
        *(int **)(lVar4 + 0x18) = &local_d0;
        *(int **)(lVar4 + 0x28) = &local_cc;
        *(wchar_t **)(lVar4 + 0x48) = L"Dump2Key";
        *(uint **)(lVar4 + 0x50) = local_e8;
        *(undefined4 *)(lVar4 + 0x20) = 0x4000004;
        *(undefined4 *)(lVar4 + 0x40) = 0x120;
        *(undefined4 *)(lVar4 + 0x58) = 0x4000004;
        *(uint **)(lVar4 + 0x60) = local_c8;
        *(undefined4 *)(lVar4 + 0x30) = 4;
        *(undefined4 *)(lVar4 + 0x68) = 4;
        RtlInitUnicodeString(&local_c0,L"RtlQueryRegistryValuesEx");
        pcVar5 = (code *)MmGetSystemRoutineAddress(&local_c0);
        local_f8 = 0;
        if (pcVar5 == (code *)0x0) {
          pcVar5 = RtlQueryRegistryValues_exref;
        }
        iVar3 = (*pcVar5)(0x80000000,lVar6,lVar4,0);
        if (-1 < iVar3) {
          DAT_1c000a1b8 = local_d0;
          goto LAB_1c000f543;
        }
      }
    }
  }
  local_e8[0] = local_c8[0];
  DAT_1c000a1b8 = local_cc;
LAB_1c000f543:
  if (DAT_1c000a1b8 != 0) {
    if (local_e8[0] == 0x7c) {
      _DAT_1c000a1bc = 0x54b7;
    }
    else {
      if (local_e8[0] < 0x86) {
        bVar1 = local_a8[(int)local_e8[0]];
      }
      else {
        bVar1 = 0;
      }
      _DAT_1c000a1bc = (ushort)bVar1;
    }
  }
  if (local_d8 != 0) {
    ExFreePoolWithTag(local_d8,0);
  }
  if (lVar4 != 0) {
    ExFreePoolWithTag(lVar4,0);
  }
  return;
}



===== Kbdhid_ServiceParameters @ 1c000f5d8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Kbdhid_ServiceParameters(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  code *pcVar3;
  undefined1 auStackY_168 [32];
  longlong *plVar4;
  int local_138;
  int local_134;
  int local_130 [4];
  longlong local_120 [3];
  undefined1 local_108 [8];
  undefined4 local_100;
  wchar_t *local_f8;
  int *local_f0;
  undefined4 local_e8;
  int *local_e0;
  undefined4 local_d8;
  undefined4 local_c8;
  wchar_t *local_c0;
  int *local_b8;
  undefined4 local_b0;
  int *local_a8;
  undefined4 local_a0;
  undefined4 local_90;
  wchar_t *local_88;
  int *local_80;
  undefined4 local_78;
  int *local_70;
  undefined4 local_68;
  undefined8 local_60;
  undefined4 local_58;
  undefined8 local_50;
  ulonglong local_28;
  
  local_28 = ___security_cookie ^ (ulonglong)auStackY_168;
  local_120[0] = 0;
  local_130[2] = 0;
  local_134 = 0;
  local_130[0] = 0;
  local_130[1] = 1;
  local_138 = 1;
  plVar4 = local_120;
  local_130[3] = 0;
  iVar2 = IoOpenDriverRegistryKey(param_1,0,0x20019,0);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,6,10,plVar4,(char)iVar2);
    }
  }
  else {
    memset(local_108,0,0xe0);
    lVar1 = local_120[0];
    local_f8 = L"BreakOnSysRq";
    local_e8 = 0x4000004;
    local_d8 = 4;
    local_f0 = &local_138;
    local_b0 = 0x4000004;
    local_e0 = local_130 + 1;
    local_a0 = 4;
    local_c0 = L"CrashOnCtrlScroll";
    local_b8 = &local_134;
    local_a8 = local_130 + 2;
    local_88 = L"DisableAutoRepeat";
    local_80 = local_130;
    local_70 = local_130 + 3;
    local_78 = 0x4000004;
    local_68 = 4;
    local_100 = 0x120;
    local_c8 = 0x120;
    local_90 = 0x120;
    local_60 = 0;
    local_58 = 0;
    local_50 = 0;
    local_120[1] = 0;
    local_120[2] = 0;
    RtlInitUnicodeString(local_120 + 1,L"RtlQueryRegistryValuesEx");
    pcVar3 = (code *)MmGetSystemRoutineAddress(local_120 + 1);
    if (pcVar3 == (code *)0x0) {
      pcVar3 = RtlQueryRegistryValues_exref;
    }
    iVar2 = (*pcVar3)(0xc0000000,lVar1,local_108,0);
    if (-1 < iVar2) {
      DAT_1c000a1b4 = local_138 != 0;
      if (local_134 == 0) {
        KbdHidCrashDump(param_2);
      }
      else {
        DAT_1c000a1b8 = 2;
        _DAT_1c000a1bc = 0x46;
      }
      DAT_1c000a1be = local_130[0] != 0;
    }
  }
  if (local_120[0] != 0) {
    ZwClose();
  }
  return;
}



===== wil_InitializeFeatureStaging @ 1c000f7f4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wil_InitializeFeatureStaging(void)

{
  bool bVar1;
  int iVar2;
  longlong *plVar3;
  undefined8 local_res8;
  
  bVar1 = false;
  if (g_wil_details_isFeatureStagingInitialized == 0) {
    g_wil_details_isFeatureStagingInitialized = 1;
    local_res8 = RtlQueryFeatureConfigurationChangeStamp();
    wil_details_PopulateInitialConfiguredFeatureStates();
    wil_details_EvaluateFeatureDependencies();
    for (plVar3 = &wil_details_featureDescriptors_z; plVar3 < &wil_details_featureDescriptors_z;
        plVar3 = plVar3 + 1) {
      if (*plVar3 != 0) goto LAB_1c000f87b;
    }
LAB_1c000f8b5:
    _g_wil_details_recordFeatureUsage = wil_details_RecordFeatureUsageReporting;
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
LAB_1c000f87b:
  if (plVar3 == (longlong *)0x0) goto LAB_1c000f8b5;
  if (((*(char *)((longlong)plVar3 + 0x1d) == '\0') && (*(char *)((longlong)plVar3 + 0x1e) == '\0'))
     && (*(char *)((longlong)plVar3 + 0x1c) == '\0')) {
    iVar2 = RtlRegisterFeatureConfigurationChangeNotification
                      (wil_details_ReevaluateOnFeatureConfigurationChange,0,&local_res8,
                       &g_wil_details_featureChangeNotification);
    if (iVar2 == 0) {
      bVar1 = true;
    }
    else {
      g_wil_details_featureChangeNotification = 0;
    }
    goto LAB_1c000f8b5;
  }
  plVar3 = plVar3 + 7;
  while( true ) {
    if (&UNK_1c0009f97 < plVar3) goto LAB_1c000f8b5;
    if (*plVar3 != 0) break;
    plVar3 = plVar3 + 1;
  }
  goto LAB_1c000f87b;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 1c000f908 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  ulonglong *puVar1;
  undefined8 *puVar2;
  int iVar3;
  longlong *plVar4;
  undefined1 auStack_48 [32];
  ulonglong local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = ___security_cookie ^ (ulonglong)auStack_48;
  plVar4 = &wil_details_featureDescriptors_z;
  while( true ) {
    if (&wil_details_featureDescriptors_z <= plVar4) {
      return;
    }
    if (*plVar4 != 0) break;
    plVar4 = plVar4 + 1;
  }
  do {
    if (plVar4 == (longlong *)0x0) {
      return;
    }
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    if ((*(char *)((longlong)plVar4 + 0x1d) == '\0') && (*(char *)((longlong)plVar4 + 0x1e) == '\0')
       ) {
      iVar3 = RtlQueryFeatureConfiguration
                        ((int)plVar4[3],1 < (byte)(*(char *)((longlong)plVar4 + 0x1c) - 2U),
                         &local_28,&local_20);
      if (iVar3 == -0x7fffffde) {
        do {
          puVar2 = (undefined8 *)*plVar4;
          plVar4 = plVar4 + 7;
          *puVar2 = 0x206;
          while( true ) {
            if (&UNK_1c0009f97 < plVar4) {
              return;
            }
            if (*plVar4 != 0) break;
            plVar4 = plVar4 + 1;
          }
        } while (plVar4 != (longlong *)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_1c000f9f2;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_1c000f9f2;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_1c000f9f2:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*plVar4;
    plVar4 = plVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_1c0009f97 < plVar4) {
        return;
      }
      if (*plVar4 != 0) break;
      plVar4 = plVar4 + 1;
    }
  } while( true );
}


