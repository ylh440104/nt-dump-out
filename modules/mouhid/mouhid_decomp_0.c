
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



===== MouHid_Flush @ 1c0001020 =====

int MouHid_Flush(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong lVar4;
  int iVar5;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar1 = lVar2 + 0xf0;
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



===== MouHid_IOCTL @ 1c0001110 =====

int MouHid_IOCTL(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined8 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  undefined2 uVar10;
  undefined8 uVar11;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  *(undefined8 *)(param_2 + 0x38) = 0;
  uVar11 = 1;
  iVar8 = IoAcquireRemoveLockEx(lVar1 + 0xf0,param_2,"",1,0x20);
  if (iVar8 < 0) {
    *(int *)(param_2 + 0x30) = iVar8;
    IofCompleteRequest(param_2,0);
    return iVar8;
  }
  iVar8 = *(int *)(lVar2 + 0x18);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  if (iVar8 == 0xf0000) {
    if (*(uint *)(lVar2 + 8) < 0xc) {
      iVar9 = -0x3fffffdd;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_Ld(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      goto LAB_1c0001300;
    }
    puVar4 = *(undefined8 **)(param_2 + 0x18);
    *puVar4 = *(undefined8 *)(lVar1 + 0x178);
    *(undefined4 *)(puVar4 + 1) = *(undefined4 *)(lVar1 + 0x180);
    *(undefined8 *)(param_2 + 0x38) = 0xc;
LAB_1c00012fe:
    iVar9 = 0;
  }
  else {
    if (iVar8 != 0xf0203) {
      if (iVar8 == 0xf0403) {
        iVar9 = -0x3ffffffe;
      }
      else if ((iVar8 == 0xf0803) || (iVar8 == 0xf1003)) {
        iVar9 = -0x3fffff45;
      }
      else {
        iVar9 = -0x3ffffff0;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_Dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,uVar11,
                             &WPP_5fb2b8b2da473567e94ec36236fb6212_Traceguids,(char)iVar8,0x10);
        }
      }
      goto LAB_1c0001300;
    }
    if (*(longlong *)(lVar1 + 0xe8) == 0) {
      if (0xf < *(uint *)(lVar2 + 0x10)) {
        puVar3 = *(undefined4 **)(lVar2 + 0x20);
        uVar5 = puVar3[1];
        uVar6 = puVar3[2];
        uVar7 = puVar3[3];
        *(undefined4 *)(lVar1 + 0xe0) = *puVar3;
        *(undefined4 *)(lVar1 + 0xe4) = uVar5;
        *(undefined4 *)(lVar1 + 0xe8) = uVar6;
        *(undefined4 *)(lVar1 + 0xec) = uVar7;
        goto LAB_1c00012fe;
      }
      iVar9 = -0x3ffffff3;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0001300;
      uVar10 = 0xc;
    }
    else {
      iVar9 = -0x3fffffbd;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0001300;
      uVar10 = 0xb;
    }
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,uVar10,
                      &WPP_5fb2b8b2da473567e94ec36236fb6212_Traceguids,(char)iVar9);
  }
LAB_1c0001300:
  *(int *)(param_2 + 0x30) = iVar9;
  IofCompleteRequest(param_2,0);
  IoReleaseRemoveLockEx(lVar1 + 0xf0,param_2,0x20);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0xf,
                     &WPP_5fb2b8b2da473567e94ec36236fb6212_Traceguids);
  }
  return iVar9;
}



===== MouHid_LogError @ 1c000138c =====

void MouHid_LogError(undefined8 param_1,undefined4 param_2)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)IoAllocateErrorLogEntry(param_1,0x30);
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    *(undefined2 *)((longlong)puVar1 + 4) = 0;
    *(undefined4 *)((longlong)puVar1 + 0xc) = param_2;
    *(undefined4 *)((longlong)puVar1 + 0x14) = param_2;
    IoWriteErrorLogEntry(puVar1);
  }
  return;
}



===== MouHid_PassThrough @ 1c00013e0 =====

int MouHid_PassThrough(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar1 = lVar2 + 0xf0;
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



===== WPP_RECORDER_SF_ @ 1c0001498 =====

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



===== WPP_RECORDER_SF_Dd @ 1c0001570 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Dd(undefined8 param_1,byte param_2,uint param_3,undefined8 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,0xe,&param_6,4
               ,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,0xe,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_Ld @ 1c000169c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Ld(undefined8 param_1)

{
  undefined4 local_18 [2];
  undefined4 local_10 [2];
  
  local_18[0] = 0xc0000023;
  local_10[0] = 0xf0000;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_5fb2b8b2da473567e94ec36236fb6212_Traceguids,0xd,local_10,4,local_18,4,0);
  }
  WppAutoLogTrace(param_1,2,3,&WPP_5fb2b8b2da473567e94ec36236fb6212_Traceguids,0xd,local_10,4,
                  local_18,4,0);
  return;
}



===== WPP_RECORDER_SF_d @ 1c0001778 =====

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



===== WPP_RECORDER_SF_qqL @ 1c0001874 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_5fb2b8b2da473567e94ec36236fb6212_Traceguids,10,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,4,3,&WPP_5fb2b8b2da473567e94ec36236fb6212_Traceguids,10,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,0);
  return;
}



===== WppClassicProviderCallback @ 1c0001970 =====

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



===== MouHid_AddDevice @ 1c00019d0 =====

int MouHid_AddDevice(undefined8 param_1,longlong param_2)

{
  short sVar1;
  longlong *plVar2;
  undefined1 uVar3;
  int iVar4;
  longlong lVar5;
  undefined4 *puVar6;
  wchar_t *pwVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined8 uVar10;
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined *in_stack_ffffffffffffff88;
  undefined4 uVar11;
  ulonglong in_stack_ffffffffffffff90;
  undefined8 local_58;
  longlong local_50 [3];
  
  local_50[0] = 0;
  local_58 = 0;
  local_res18[0] = 0;
  local_res20[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffff88 = &WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0xc,
                     &WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids);
  }
  iVar4 = IoCreateDevice(param_1,0x1d8,0,0xf,
                         (ulonglong)in_stack_ffffffffffffff88 & 0xffffffff00000000,
                         in_stack_ffffffffffffff90 & 0xffffffffffffff00,local_50);
  if (iVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar4;
    }
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0xd,
                      &WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids,(char)iVar4);
    return iVar4;
  }
  DAT_1c000817c = 0xffffffff;
  RtlInitUnicodeString(local_50 + 1,L"Kernel-OneCore-DeviceFamilyID");
  puVar6 = local_res20;
  uVar10 = 4;
  puVar8 = &DAT_1c000817c;
  uVar3 = ZwQueryLicenseValue(local_50 + 1,0,&DAT_1c000817c,4,puVar6);
  uVar11 = (undefined4)((ulonglong)puVar6 >> 0x20);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    puVar8 = (undefined4 *)0x5;
    uVar11 = 1;
    WPP_RECORDER_SF_Dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,uVar10,
                       &WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids,(char)DAT_1c000817c,uVar3);
  }
  plVar2 = *(longlong **)(local_50[0] + 0x40);
  lVar5 = IoAttachDeviceToDeviceStack(local_50[0],param_2);
  plVar2[1] = lVar5;
  if (lVar5 == 0) {
    puVar6 = (undefined4 *)IoAllocateErrorLogEntry(param_1,0x30);
    iVar4 = -0x3fffff63;
    if (puVar6 != (undefined4 *)0x0) {
      puVar6[3] = 0xc0050002;
      *puVar6 = 0;
      *(undefined8 *)(puVar6 + 6) = 0;
      puVar6[4] = 0;
      puVar6[5] = 0xc000009d;
      IoWriteErrorLogEntry(puVar6);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar8,0xf,
                         &WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids,(char)local_50[0],0x9d);
    }
LAB_1c0001c5b:
    IoDeleteDevice(local_50[0]);
    return iVar4;
  }
  *plVar2 = local_50[0];
  *(undefined1 *)(plVar2 + 4) = 0;
  *(undefined1 *)((longlong)plVar2 + 0x22) = 0;
  *(undefined4 *)(plVar2 + 7) = 0;
  *(undefined4 *)(plVar2 + 0x11) = 0;
  LOCK();
  UNLOCK();
  sVar1 = (short)DAT_1c0008178;
  DAT_1c0008178 = DAT_1c0008178 + 1;
  *(short *)((longlong)plVar2 + 0x24) = sVar1 + 1;
  plVar2[2] = param_2;
  lVar5 = IoAllocateIrp(CONCAT71((int7)((ulonglong)plVar2[1] >> 8),*(undefined1 *)(plVar2[1] + 0x4c)
                                ),0);
  plVar2[0xe] = lVar5;
  if (lVar5 == 0) {
    iVar4 = -0x3fffff66;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar8,0x10,
                         &WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids,(char)local_50[0],0x9a);
    }
    IoDetachDevice(plVar2[1]);
    goto LAB_1c0001c5b;
  }
  KeInitializeEvent(plVar2 + 0x12,1,0);
  KeInitializeEvent(plVar2 + 0x15,0,1);
  KeInitializeEvent(plVar2 + 0x18,0,1);
  uVar10 = CONCAT44(uVar11,0x20);
  IoInitializeRemoveLockEx(plVar2 + 0x1e,0x48756f4d,1,0);
  plVar2[0x10] = 0;
  *(undefined4 *)(plVar2 + 0x22) = 1;
  plVar2[0x23] = 0;
  *(undefined4 *)(plVar2 + 0x24) = 0;
  KeInitializeEvent(plVar2 + 0x25,1,0);
  KeInitializeSpinLock(plVar2 + 8);
  uVar9 = (uint)&local_58;
  puVar6 = (undefined4 *)0x1f0000;
  *(undefined2 *)(plVar2 + 0x2c) = *(undefined2 *)((longlong)plVar2 + 0x24);
  pwVar7 = (wchar_t *)0x1;
  *(undefined2 *)(plVar2 + 0x2f) = 0x80;
  *(undefined2 *)((longlong)plVar2 + 0x17c) = 0;
  *(undefined4 *)(plVar2 + 0x30) = 2;
  iVar4 = IoOpenDeviceRegistryKey(param_2);
  *(undefined2 *)(plVar2 + 6) = 0;
  *(undefined1 *)(plVar2 + 0xb) = 0;
  *(undefined4 *)((longlong)plVar2 + 0x5a) = 0;
  *(undefined1 *)((longlong)plVar2 + 0x5e) = 0;
  *(undefined4 *)(plVar2 + 0xc) = 0;
  *(undefined4 *)((longlong)plVar2 + 100) = 1;
  *(undefined4 *)(plVar2 + 0xd) = 1;
  if (-1 < iVar4) {
    iVar4 = MouHid_QueryDeviceKey(local_58,L"FlipFlopWheel",local_res18,uVar9);
    if (-1 < iVar4) {
      *(undefined1 *)(plVar2 + 6) = (undefined1)local_res18[0];
    }
    iVar4 = MouHid_QueryDeviceKey(local_58,L"FlipFlopHScroll",local_res18,uVar9);
    if (-1 < iVar4) {
      *(undefined1 *)((longlong)plVar2 + 0x31) = (undefined1)local_res18[0];
    }
    iVar4 = MouHid_QueryDeviceKey(local_58,L"WheelScalingFactor",local_res18,uVar9);
    if (iVar4 < 0) {
      *(undefined4 *)((longlong)plVar2 + 0x4c) = 0x78;
      *(undefined4 *)(plVar2 + 9) = 0x78;
    }
    else {
      *(undefined4 *)((longlong)plVar2 + 0x4c) = local_res18[0];
      *(undefined4 *)(plVar2 + 9) = local_res18[0];
    }
    iVar4 = MouHid_QueryDeviceKey(local_58,L"HScrollScalingFactor",local_res18,uVar9);
    if (iVar4 < 0) {
      *(undefined4 *)((longlong)plVar2 + 0x54) = 0x78;
      *(undefined4 *)(plVar2 + 10) = 0x78;
    }
    else {
      *(undefined4 *)((longlong)plVar2 + 0x54) = local_res18[0];
      *(undefined4 *)(plVar2 + 10) = local_res18[0];
    }
    iVar4 = MouHid_QueryDeviceKey(local_58,L"VScrollHighResolutionDisable",local_res18,uVar9);
    if (-1 < iVar4) {
      *(undefined1 *)(plVar2 + 0xb) = (undefined1)local_res18[0];
    }
    iVar4 = MouHid_QueryDeviceKey(local_58,L"VScrollPageOverride",local_res18,uVar9);
    if (-1 < iVar4) {
      *(undefined2 *)((longlong)plVar2 + 0x5a) = (undefined2)local_res18[0];
    }
    iVar4 = MouHid_QueryDeviceKey(local_58,L"VScrollUsageOverride",local_res18,uVar9);
    if (-1 < iVar4) {
      *(undefined2 *)((longlong)plVar2 + 0x5c) = (undefined2)local_res18[0];
    }
    iVar4 = MouHid_QueryDeviceKey(local_58,L"HScrollHighResolutionDisable",local_res18,uVar9);
    if (-1 < iVar4) {
      *(undefined1 *)((longlong)plVar2 + 0x5e) = (undefined1)local_res18[0];
    }
    iVar4 = MouHid_QueryDeviceKey(local_58,L"HScrollPageOverride",local_res18,uVar9);
    if (-1 < iVar4) {
      *(undefined2 *)(plVar2 + 0xc) = (undefined2)local_res18[0];
    }
    puVar6 = local_res18;
    pwVar7 = L"HScrollUsageOverride";
    iVar4 = MouHid_QueryDeviceKey(local_58,L"HScrollUsageOverride",puVar6,uVar9);
    if (-1 < iVar4) {
      *(undefined2 *)((longlong)plVar2 + 0x62) = (undefined2)local_res18[0];
    }
    ZwClose(local_58);
  }
  sVar1 = *(short *)((longlong)plVar2 + 0x5c);
  if (*(short *)((longlong)plVar2 + 0x5a) == 0) {
    if (sVar1 != 0) {
LAB_1c0001f00:
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pwVar7,puVar6,0x11,uVar10,
                            (char)local_50[0],(char)*(short *)((longlong)plVar2 + 0x5a),(char)sVar1)
        ;
      }
      *(undefined4 *)((longlong)plVar2 + 0x5a) = 0;
    }
  }
  else if (sVar1 == 0) goto LAB_1c0001f00;
  sVar1 = *(short *)((longlong)plVar2 + 0x62);
  if ((short)plVar2[0xc] == 0) {
    if (sVar1 == 0) goto LAB_1c0001f84;
  }
  else if (sVar1 != 0) goto LAB_1c0001f84;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pwVar7,puVar6,0x12,uVar10,
                        (char)local_50[0],(char)plVar2[0xc],(char)sVar1);
  }
  *(undefined4 *)(plVar2 + 0xc) = 0;
LAB_1c0001f84:
  uVar10 = 1;
  PoSetPowerState(local_50[0],1);
  *(undefined4 *)(plVar2 + 0x33) = 1;
  plVar2[0x34] = (longlong)&MouHid_WmiGuidList;
  plVar2[0x35] = (longlong)MouHid_QueryWmiRegInfo;
  plVar2[0x36] = (longlong)MouHid_QueryWmiDataBlock;
  plVar2[0x37] = (longlong)MouHid_SetWmiDataBlock;
  plVar2[0x38] = (longlong)MouHid_SetWmiDataBlock;
  plVar2[0x39] = 0;
  plVar2[0x3a] = 0;
  *(uint *)(local_50[0] + 0x30) = *(uint *)(local_50[0] + 0x30) | 0x2000;
  *(uint *)(local_50[0] + 0x30) = *(uint *)(local_50[0] + 0x30) & 0xffffff7f;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,uVar10,0x13,
                       &WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids,(char)local_50[0],0);
  }
  return 0;
}



===== MouHid_PnPComplete @ 1c0002060 =====

undefined8 MouHid_PnPComplete(undefined8 param_1,longlong param_2,longlong param_3)

{
  char *pcVar1;
  undefined8 uVar2;
  
  pcVar1 = *(char **)(param_2 + 0xb8);
  if ((*pcVar1 == '\x1b') && (pcVar1[1] == '\0')) {
    KeSetEvent(param_3 + 0x148,0,0);
    uVar2 = 0xc0000016;
  }
  else {
    if (*(char *)(param_2 + 0x41) != '\0') {
      pcVar1[3] = pcVar1[3] | 1;
    }
    uVar2 = 0;
  }
  return uVar2;
}



===== MouHid_Power @ 1c00020b0 =====

int MouHid_Power(longlong param_1,char *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined1 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  ulonglong uVar10;
  undefined8 in_stack_ffffffffffffffa8;
  undefined4 uVar12;
  undefined8 uVar11;
  
  uVar12 = (undefined4)((ulonglong)in_stack_ffffffffffffffa8 >> 0x20);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar12 = 1;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x1d,
                     &WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids);
  }
  lVar2 = *(longlong *)(param_1 + 0x40);
  plVar1 = (longlong *)(param_2 + 0xb8);
  lVar3 = *plVar1;
  uVar11 = CONCAT44(uVar12,0x20);
  iVar7 = *(int *)(lVar3 + 0x10);
  iVar8 = *(int *)(lVar3 + 0x18);
  pcVar9 = param_2;
  iVar6 = IoAcquireRemoveLockEx(lVar2 + 0xf0,param_2,"",1);
  if (iVar6 < 0) {
    PoStartNextPowerIrp(param_2);
    *(int *)(param_2 + 0x30) = iVar6;
    IofCompleteRequest(param_2,0);
    return iVar6;
  }
  if (*(char *)(lVar3 + 1) == '\x02') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      pcVar9 = "D";
      WPP_RECORDER_SF_qqsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    if (iVar7 == 1) {
      *(undefined4 *)(lVar2 + 0x2c) = *(undefined4 *)(lVar2 + 0x28);
      *(int *)(lVar2 + 0x28) = iVar8;
      if (iVar8 == 1) {
        puVar4 = (undefined8 *)*plVar1;
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
        lVar3 = *plVar1;
        *(code **)(lVar3 + -0x10) = MouHid_PowerCompletion;
        *(undefined8 *)(lVar3 + -8) = 0;
        *(undefined1 *)(lVar3 + -0x45) = 0xe0;
        *(byte *)(*plVar1 + 3) = *(byte *)(*plVar1 + 3) | 1;
        PoCallDriver(*(undefined8 *)(lVar2 + 8));
        iVar7 = 0x103;
        goto LAB_1c000220d;
      }
      iVar8 = 2;
      LOCK();
      iVar7 = *(int *)(lVar2 + 0x38);
      if (iVar7 == 2) {
        *(int *)(lVar2 + 0x38) = 3;
      }
      else {
        iVar8 = iVar7;
      }
      UNLOCK();
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar9,0,0x1f,uVar11,
                           (char)param_1,(char)iVar8);
      }
      uVar5 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x40);
      *(undefined4 *)(lVar2 + 0x4c) = *(undefined4 *)(lVar2 + 0x48);
      *(undefined4 *)(lVar2 + 0x54) = *(undefined4 *)(lVar2 + 0x50);
      uVar10 = (ulonglong)CONCAT31((int3)((uint)*(undefined4 *)(lVar2 + 0x50) >> 8),uVar5);
      KeReleaseSpinLock(lVar2 + 0x40);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar10,4,0x20,
                            &WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids,(char)param_1,
                            (char)*(undefined4 *)(lVar2 + 0x48),(char)*(undefined4 *)(lVar2 + 0x50))
        ;
      }
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_c(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  PoStartNextPowerIrp(param_2);
  param_2[0x43] = param_2[0x43] + '\x01';
  *plVar1 = *plVar1 + 0x48;
  iVar7 = PoCallDriver(*(undefined8 *)(lVar2 + 8),param_2);
  IoReleaseRemoveLockEx(lVar2 + 0xf0,param_2,0x20);
LAB_1c000220d:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x22,
                     &WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids);
  }
  return iVar7;
}



===== MouHid_PowerCompletion @ 1c00023e0 =====

int MouHid_PowerCompletion(longlong param_1,longlong param_2,undefined8 param_3)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  undefined8 *puVar4;
  int iVar5;
  wchar_t *pwVar6;
  bool bVar7;
  undefined *in_stack_ffffffffffffffc8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffc8 = &WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids;
    param_3 = 4;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x17,
                     &WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids);
  }
  pwVar6 = (wchar_t *)&WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids;
  lVar3 = *(longlong *)(param_2 + 0xb8);
  iVar2 = *(int *)(param_2 + 0x30);
  puVar4 = *(undefined8 **)(param_1 + 0x40);
  iVar5 = *(int *)(lVar3 + 0x10);
  if (*(char *)(lVar3 + 1) == '\x02') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      param_3 = 4;
      in_stack_ffffffffffffffc8 = &WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids;
      pwVar6 = L"crollUsageOverride";
      WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x18,
                          &WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids,(char)param_1,
                          (char)param_2,(char)*(undefined4 *)(lVar3 + 0x18) + -1);
    }
    if ((((iVar5 == 1) && (*(int *)(puVar4 + 5) == 1)) && (-1 < iVar2)) && (puVar4[0x10] != 0)) {
      iVar5 = 3;
      LOCK();
      iVar1 = *(int *)(puVar4 + 7);
      if (iVar1 == 3) {
        *(int *)(puVar4 + 7) = 3;
      }
      else {
        iVar5 = iVar1;
      }
      UNLOCK();
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pwVar6,param_3,0x19,
                           in_stack_ffffffffffffffc8,(char)param_1,(char)iVar5);
      }
      if (iVar5 == 3) {
        KeResetEvent(puVar4 + 0x18);
        LOCK();
        bVar7 = *(int *)(puVar4 + 0x11) == 1;
        if (bVar7) {
          *(int *)(puVar4 + 0x11) = 2;
        }
        UNLOCK();
        if (bVar7) {
          iVar5 = MouHid_SetResolutionMultipliers(puVar4,(ulonglong)pwVar6);
          LOCK();
          *(uint *)(puVar4 + 7) = (iVar5 != -0x3fffff45) + 1;
          UNLOCK();
          LOCK();
          if (*(int *)(puVar4 + 0x11) == 2) {
            *(int *)(puVar4 + 0x11) = 1;
          }
          UNLOCK();
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x1a,
                              &WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids,(char)iVar5);
          }
        }
        else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
        KeSetEvent(puVar4 + 0x18,0,0);
      }
    }
  }
  IoReleaseRemoveLockEx(puVar4 + 0x1e,param_2,0x20);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x1c,
                     &WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids);
  }
  return iVar2;
}



===== MouHid_QueryDeviceKey @ 1c000265c =====

int MouHid_QueryDeviceKey(undefined8 param_1,undefined8 param_2,void *param_3,uint param_4)

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
  lVar3 = ExAllocatePool2(0x100,local_res20[0],0x48756f4d);
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



===== WPP_RECORDER_SF_L @ 1c000275c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_L(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids,0x1b,&uStack0000000000000030,4,0);
  }
  WppAutoLogTrace(param_1,2,4,&WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids,0x1b,
                  &uStack0000000000000030,4,0);
  return;
}



===== WPP_RECORDER_SF_c @ 1c0002808 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_c(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids,0x21,&uStack0000000000000030,1,0);
  }
  WppAutoLogTrace(param_1,2,4,&WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids,0x21,
                  &uStack0000000000000030,1,0);
  return;
}



===== WPP_RECORDER_SF_qDD @ 1c00028b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,2,5,&WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids,param_4,&param_6,8,
                  &param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qL @ 1c00029ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids,param_4,&param_6,8,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,4,4,&WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids,param_4,&param_6,8,
                  &param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_qd @ 1c0002a80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qd(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,8,&param_7,4
               ,0);
  }
  WppAutoLogTrace(param_1,param_2,5,param_5,param_4,&param_6,8,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_qdd @ 1c0002b60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qdd(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,
               &param_6,8,&param_7,4,&param_8,4,0);
  }
  WppAutoLogTrace(param_1,4,param_3,param_5,param_4,&param_6,8,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qqc @ 1c0002cb4 =====

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
               &WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids,0x15,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,1,0);
  }
  WppAutoLogTrace(param_1,4,5,&WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids,0x15,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,1,0);
  return;
}



===== WPP_RECORDER_SF_qqd @ 1c0002da8 =====

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



===== WPP_RECORDER_SF_qqsd @ 1c0002ef8 =====

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
               &WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids,0x1e,&uStack0000000000000030,8,
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
  WppAutoLogTrace(param_1,4,4,&WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids,0x1e,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,in_stack_00000040,lVar2,
                  &uStack0000000000000048,4,0);
  return;
}



===== MouHid_ReadComplete @ 1c0003090 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 MouHid_ReadComplete(undefined1 param_1,longlong param_2,longlong *param_3)

{
  ushort uVar1;
  undefined2 *puVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong lVar5;
  bool bVar6;
  undefined1 uVar7;
  ushort uVar8;
  short sVar9;
  int iVar10;
  undefined8 *puVar11;
  byte bVar12;
  ushort *puVar13;
  longlong *plVar14;
  uint uVar15;
  longlong *plVar16;
  uint *puVar17;
  uint *puVar18;
  bool bVar19;
  bool bVar20;
  uint local_res20 [2];
  uint *in_stack_ffffffffffffff88;
  uint local_58 [6];
  
  local_res20[0] = 0;
  local_58[1] = 0;
  local_58[0] = 0;
  bVar6 = false;
  plVar16 = param_3;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    plVar16 = (longlong *)0x2;
    in_stack_ffffffffffffff88 = (uint *)&WPP_8ae6e206fd5f3a01a789e273b148a72f_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,10,
                     &WPP_8ae6e206fd5f3a01a789e273b148a72f_Traceguids);
  }
  iVar10 = *(int *)(param_2 + 0x30);
  plVar14 = (longlong *)0x3;
  puVar2 = (undefined2 *)param_3[0x1b];
  LOCK();
  bVar19 = *(int *)((longlong)param_3 + 0x1c) == 1;
  if (bVar19) {
    *(int *)((longlong)param_3 + 0x1c) = 3;
  }
  UNLOCK();
  bVar19 = !bVar19;
  LOCK();
  bVar20 = (int)param_3[3] == 0;
  if (bVar20) {
    *(int *)(param_3 + 3) = 0;
  }
  UNLOCK();
  if (bVar20) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qql(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
  else if ((((iVar10 != -0x3fffffaa) && (iVar10 != -0x3fffff9f)) && (iVar10 != -0x3fffff63)) &&
          (iVar10 != -0x3ffffee0)) {
    if (iVar10 == 0) {
      *(undefined4 *)((longlong)param_3 + 0x164) = 0;
      *(undefined4 *)((longlong)param_3 + 0x16c) = 0;
      *(undefined4 *)(param_3 + 0x2e) = 0;
      local_58[0] = (uint)(ushort)puVar2[0xe];
      in_stack_ffffffffffffff88 = local_58;
      iVar10 = HidP_GetUsages(0,9,0,*(undefined8 *)(puVar2 + 0x38),in_stack_ffffffffffffff88,
                              *(undefined8 *)(puVar2 + 0x10),*(undefined8 *)(puVar2 + 0x34),
                              puVar2[0x16]);
      if (-1 < iVar10) {
        in_stack_ffffffffffffff88 =
             (uint *)CONCAT44((int)((ulonglong)in_stack_ffffffffffffff88 >> 0x20),
                              (uint)(ushort)puVar2[0xe]);
        iVar10 = HidP_UsageListDifference
                           (*(undefined8 *)(puVar2 + 0x3c),*(undefined8 *)(puVar2 + 0x38),
                            *(undefined8 *)(puVar2 + 0x40),*(undefined8 *)(puVar2 + 0x44));
        if (-1 < iVar10) {
          uVar8 = puVar2[0xe];
          puVar13 = *(ushort **)(puVar2 + 0x44);
          uVar15 = 0;
          if (uVar8 != 0) {
            do {
              uVar1 = *puVar13;
              if (uVar1 == 0) break;
              if (uVar1 < 6) {
                *(ushort *)((longlong)param_3 + 0x164) =
                     *(ushort *)((longlong)param_3 + 0x164) |
                     *(ushort *)(&HidP_TranslateUsageToDownFlag + (ulonglong)uVar1 * 2);
              }
              uVar8 = puVar2[0xe];
              uVar15 = uVar15 + 1;
              puVar13 = puVar13 + 1;
            } while (uVar15 < uVar8);
          }
          puVar13 = *(ushort **)(puVar2 + 0x40);
          uVar15 = 0;
          if (uVar8 != 0) {
            do {
              uVar8 = *puVar13;
              if (uVar8 == 0) break;
              if (uVar8 < 6) {
                *(ushort *)((longlong)param_3 + 0x164) =
                     *(ushort *)((longlong)param_3 + 0x164) |
                     *(ushort *)(&HidP_TranslateUsageToUpFlag + (ulonglong)uVar8 * 2);
              }
              uVar15 = uVar15 + 1;
              puVar13 = puVar13 + 1;
            } while (uVar15 < (ushort)puVar2[0xe]);
          }
          uVar3 = *(undefined8 *)(puVar2 + 0x3c);
          *(undefined8 *)(puVar2 + 0x3c) = *(undefined8 *)(puVar2 + 0x38);
          *(undefined8 *)(puVar2 + 0x38) = uVar3;
        }
      }
      puVar18 = (uint *)((longlong)param_3 + 0x16c);
      puVar17 = (uint *)(param_3 + 0xf);
      if (((*puVar17 & 2) == 0) &&
         (in_stack_ffffffffffffff88 = puVar18,
         iVar10 = HidP_GetScaledUsageValue
                            (0,1,0,0x30,puVar18,*(undefined8 *)(puVar2 + 0x10),
                             *(undefined8 *)(puVar2 + 0x34),puVar2[0x16]), iVar10 == -0x3feefffa)) {
        *puVar17 = *puVar17 | 2;
        bVar6 = true;
        *(int *)(puVar2 + 4) = (1 << ((char)*puVar2 - 1U & 0x1f)) + -1;
      }
      if ((*puVar17 & 2) != 0) {
        in_stack_ffffffffffffff88 = local_res20;
        iVar10 = HidP_GetUsageValue(0,1,0,0x30,in_stack_ffffffffffffff88,
                                    *(undefined8 *)(puVar2 + 0x10),*(undefined8 *)(puVar2 + 0x34),
                                    puVar2[0x16]);
        if (-1 < iVar10) {
          *puVar18 = -(uint)((*(uint *)(puVar2 + 4) + 1 & local_res20[0]) != 0) &
                     ~*(uint *)(puVar2 + 4) | local_res20[0];
        }
      }
      puVar17 = (uint *)(param_3 + 0xf);
      if ((*(char *)(puVar2 + 8) != '\0') && (*(int *)(puVar2 + 4) != 0)) {
        *(int *)((longlong)param_3 + 0x16c) =
             (int)(((longlong)*(int *)((longlong)param_3 + 0x16c) * 0xffff) /
                  (longlong)*(int *)(puVar2 + 4));
      }
      if ((*puVar17 & 4) == 0) {
        in_stack_ffffffffffffff88 = (uint *)(param_3 + 0x2e);
        iVar10 = HidP_GetScaledUsageValue
                           (0,1,0,0x31,in_stack_ffffffffffffff88,*(undefined8 *)(puVar2 + 0x10),
                            *(undefined8 *)(puVar2 + 0x34),puVar2[0x16]);
        if (iVar10 == -0x3feefffa) {
          *puVar17 = *puVar17 | 4;
          bVar6 = true;
          *(int *)(puVar2 + 6) = (1 << ((char)puVar2[1] - 1U & 0x1f)) + -1;
        }
      }
      if ((*puVar17 & 4) != 0) {
        local_res20[0] = 0;
        in_stack_ffffffffffffff88 = local_res20;
        iVar10 = HidP_GetUsageValue(0,1,0,0x31,in_stack_ffffffffffffff88,
                                    *(undefined8 *)(puVar2 + 0x10),*(undefined8 *)(puVar2 + 0x34),
                                    puVar2[0x16]);
        if (-1 < iVar10) {
          *(uint *)(param_3 + 0x2e) =
               -(uint)((*(uint *)(puVar2 + 6) + 1 & local_res20[0]) != 0) & ~*(uint *)(puVar2 + 6) |
               local_res20[0];
        }
      }
      if (*(char *)(puVar2 + 8) != '\0') {
        *(int *)(param_3 + 0x2e) =
             (int)(((longlong)(int)param_3[0x2e] * 0xffff) / (longlong)*(int *)(puVar2 + 6));
      }
      if (*(char *)((longlong)puVar2 + 0x11) == '\0') {
        local_res20[0] = 0;
        if ((*(uint *)(param_3 + 0xf) & 8) == 0) {
          in_stack_ffffffffffffff88 = local_res20;
          iVar10 = HidP_GetScaledUsageValue
                             (0,puVar2[9],0,puVar2[10],in_stack_ffffffffffffff88,
                              *(undefined8 *)(puVar2 + 0x10),*(undefined8 *)(puVar2 + 0x34),
                              puVar2[0x16]);
          if (iVar10 == -0x3feefffc) {
            *(undefined1 *)((longlong)puVar2 + 0x11) = 1;
          }
          else if (iVar10 == -0x3feefffa) {
            *(uint *)(param_3 + 0xf) = *(uint *)(param_3 + 0xf) | 8;
            bVar6 = true;
          }
        }
        if ((*(uint *)(param_3 + 0xf) & 8) != 0) {
          in_stack_ffffffffffffff88 = local_res20;
          iVar10 = HidP_GetUsageValue(0,puVar2[9],0,puVar2[10],in_stack_ffffffffffffff88,
                                      *(undefined8 *)(puVar2 + 0x10),*(undefined8 *)(puVar2 + 0x34),
                                      puVar2[0x16]);
          if (-1 < iVar10) {
            bVar12 = (char)puVar2[2] - 1;
            local_res20[0] =
                 local_res20[0] |
                 -(uint)((1 << (bVar12 & 0x1f) & local_res20[0]) != 0) & -1 << (bVar12 & 0x1f);
          }
        }
        if (local_res20[0] == 0) {
          *(undefined2 *)((longlong)param_3 + 0x166) = 0;
        }
        else {
          uVar7 = KeAcquireSpinLockRaiseToDpc(param_3 + 8);
          lVar4 = (longlong)(int)(local_res20[0] * *(int *)((longlong)param_3 + 0x4c));
          lVar5 = lVar4 / (longlong)*(int *)((longlong)param_3 + 100);
          sVar9 = (short)lVar5;
          local_res20[0] = (uint)lVar5;
          if ((char)param_3[6] != '\0') {
            sVar9 = -sVar9;
          }
          *(short *)((longlong)param_3 + 0x166) = sVar9;
          *(ushort *)((longlong)param_3 + 0x164) = *(ushort *)((longlong)param_3 + 0x164) | 0x400;
          KeReleaseSpinLock(param_3 + 8,
                            CONCAT71((int7)((ulonglong)
                                            (lVar4 % (longlong)*(int *)((longlong)param_3 + 100)) >>
                                           8),uVar7) & 0xffffffff);
        }
      }
      if (*(char *)(puVar2 + 0xb) == '\0') {
        local_res20[0] = 0;
        if ((*(uint *)(param_3 + 0xf) & 0x10) == 0) {
          in_stack_ffffffffffffff88 = local_res20;
          iVar10 = HidP_GetScaledUsageValue
                             (0,puVar2[0xc],0,puVar2[0xd],in_stack_ffffffffffffff88,
                              *(undefined8 *)(puVar2 + 0x10),*(undefined8 *)(puVar2 + 0x34),
                              puVar2[0x16]);
          if (iVar10 == -0x3feefffc) {
            *(undefined1 *)(puVar2 + 0xb) = 1;
          }
          else if (iVar10 == -0x3feefffa) {
            *(uint *)(param_3 + 0xf) = *(uint *)(param_3 + 0xf) | 0x10;
            bVar6 = true;
          }
        }
        if ((*(uint *)(param_3 + 0xf) & 0x10) != 0) {
          in_stack_ffffffffffffff88 = local_res20;
          iVar10 = HidP_GetUsageValue(0,puVar2[0xc],0,puVar2[0xd],in_stack_ffffffffffffff88,
                                      *(undefined8 *)(puVar2 + 0x10),*(undefined8 *)(puVar2 + 0x34),
                                      puVar2[0x16]);
          if (-1 < iVar10) {
            bVar12 = (char)puVar2[3] - 1;
            local_res20[0] =
                 local_res20[0] |
                 -(uint)((1 << (bVar12 & 0x1f) & local_res20[0]) != 0) & -1 << (bVar12 & 0x1f);
          }
        }
        if ((*(ushort *)((longlong)param_3 + 0x164) >> 10 & 1) != 0) {
          if (local_res20[0] == 0) goto LAB_1c0003813;
          uVar7 = KfRaiseIrql(2);
          (*(code *)param_3[0x1d])(param_3[0x1c],param_3 + 0x2c,param_3 + 0x2f,local_58 + 1);
          KeLowerIrql(uVar7);
          *(undefined2 *)((longlong)param_3 + 0x164) = 0x800;
          if (*(char *)((longlong)param_3 + 0x31) == '\0') {
            sVar9 = (short)local_res20[0];
          }
          else {
            sVar9 = -(short)local_res20[0];
          }
          *(short *)((longlong)param_3 + 0x166) = sVar9;
          if (*(char *)(puVar2 + 8) == '\0') {
            *(undefined8 *)((longlong)param_3 + 0x16c) = 0;
          }
        }
        if (local_res20[0] != 0) {
          uVar7 = KeAcquireSpinLockRaiseToDpc(param_3 + 8);
          lVar4 = (longlong)(int)(local_res20[0] * *(int *)((longlong)param_3 + 0x54));
          lVar5 = lVar4 / (longlong)(int)param_3[0xd];
          sVar9 = (short)lVar5;
          local_res20[0] = (uint)lVar5;
          if (*(char *)((longlong)param_3 + 0x31) != '\0') {
            sVar9 = -sVar9;
          }
          *(ushort *)((longlong)param_3 + 0x164) = *(ushort *)((longlong)param_3 + 0x164) | 0x800;
          *(short *)((longlong)param_3 + 0x166) = sVar9;
          KeReleaseSpinLock(param_3 + 8,
                            CONCAT71((int7)((ulonglong)(lVar4 % (longlong)(int)param_3[0xd]) >> 8),
                                     uVar7) & 0xffffffff);
        }
      }
LAB_1c0003813:
      uVar7 = KfRaiseIrql(2);
      plVar16 = param_3 + 0x2f;
      plVar14 = param_3 + 0x2c;
      (*(code *)param_3[0x1d])(param_3[0x1c],plVar14,plVar16,local_58 + 1);
      KeLowerIrql(uVar7);
      if (bVar6) {
        plVar14 = (longlong *)CONCAT71((int7)((ulonglong)plVar14 >> 8),0x30);
        puVar11 = (undefined8 *)IoAllocateErrorLogEntry(*(undefined8 *)(*param_3 + 8));
        if (puVar11 != (undefined8 *)0x0) {
          *puVar11 = 0;
          puVar11[1] = 0;
          puVar11[2] = 0;
          puVar11[3] = 0;
          puVar11[4] = 0;
          puVar11[5] = 0;
          *(undefined4 *)((longlong)puVar11 + 0xc) = 0x80050001;
          *(undefined4 *)((longlong)puVar11 + 0x14) = 0x80050001;
          *(undefined2 *)((longlong)puVar11 + 4) = 0;
          IoWriteErrorLogEntry(puVar11);
        }
      }
    }
    if (bVar19) {
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),plVar14,plVar16,0xc,
                          in_stack_ffffffffffffff88,param_1);
      }
      MouHid_StartRead(param_3);
    }
    goto LAB_1c0003192;
  }
  if (bVar19) {
    KeSetEvent(param_3 + 0x12,0,0);
    IoReleaseRemoveLockEx(param_3 + 0x1e,param_3[0xe],0x20);
  }
LAB_1c0003192:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0xd,
                     &WPP_8ae6e206fd5f3a01a789e273b148a72f_Traceguids);
  }
  return 0xc0000016;
}



===== MouHid_StartRead @ 1c00038f8 =====

int MouHid_StartRead(undefined8 *param_1)

{
  undefined8 *puVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  bool bVar9;
  undefined *in_stack_ffffffffffffffc8;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    in_stack_ffffffffffffffc8 = &WPP_8ae6e206fd5f3a01a789e273b148a72f_Traceguids;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0xe,
                     &WPP_8ae6e206fd5f3a01a789e273b148a72f_Traceguids);
  }
  lVar3 = param_1[0xe];
  lVar4 = param_1[0x1b];
  iVar6 = *(int *)(lVar3 + 0x30);
  LOCK();
  iVar2 = *(int *)((longlong)param_1 + 0x1c);
  *(int *)((longlong)param_1 + 0x1c) = 1;
  UNLOCK();
  do {
    if (iVar2 != 2) {
LAB_1c0003b19:
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x12,
                         &WPP_8ae6e206fd5f3a01a789e273b148a72f_Traceguids);
      }
      return iVar6;
    }
    if (iVar6 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,0x11,
                            &WPP_8ae6e206fd5f3a01a789e273b148a72f_Traceguids,(char)*param_1,
                            (char)lVar3,(char)iVar6);
      }
      KeSetEvent(param_1 + 0x12,0,0);
      IoReleaseRemoveLockEx(param_1 + 0x1e,param_1[0xe],0x20);
      goto LAB_1c0003b19;
    }
    IoReuseIrp(lVar3,0);
    puVar1 = param_1 + 0x15;
    lVar5 = *(longlong *)(lVar3 + 0xb8);
    *(undefined8 *)(lVar3 + 8) = *(undefined8 *)(lVar4 + 0x90);
    *(uint *)(lVar5 + -0x40) = (uint)*(ushort *)(lVar4 + 0x2c);
    *(undefined4 *)(lVar5 + -0x38) = 0;
    *(undefined8 *)(lVar5 + -0x30) = 0;
    *(undefined1 *)(lVar5 + -0x48) = 3;
    *(undefined8 *)(lVar5 + -0x18) = param_1[0x10];
    lVar5 = *(longlong *)(lVar3 + 0xb8);
    *(code **)(lVar5 + -0x10) = MouHid_ReadComplete;
    *(undefined8 **)(lVar5 + -8) = param_1;
    *(undefined1 *)(lVar5 + -0x45) = 0xe0;
    KeResetEvent(puVar1);
    LOCK();
    bVar9 = *(int *)(param_1 + 3) == 0;
    if (bVar9) {
      *(int *)(param_1 + 3) = 0;
    }
    UNLOCK();
    if ((bVar9) || (*(char *)((longlong)param_1 + 0x21) == '\x01')) {
      IoReleaseRemoveLockEx(param_1 + 0x1e,param_1[0xe],0x20);
      iVar6 = (-(uint)(*(char *)((longlong)param_1 + 0x21) != '\0') & 0x55) + 0xc0000001;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      KeSetEvent(puVar1,0,0);
      KeSetEvent(param_1 + 0x12,0,0);
      goto LAB_1c0003b19;
    }
    iVar6 = IofCallDriver(param_1[1]);
    uVar8 = 0;
    uVar7 = 0;
    KeSetEvent(puVar1);
    LOCK();
    iVar2 = *(int *)((longlong)param_1 + 0x1c);
    *(int *)((longlong)param_1 + 0x1c) = 2;
    UNLOCK();
    if (iVar2 != 3) goto LAB_1c0003b19;
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,uVar8,0x10,
                        in_stack_ffffffffffffffc8,(char)*param_1);
    }
    LOCK();
    iVar2 = *(int *)((longlong)param_1 + 0x1c);
    *(int *)((longlong)param_1 + 0x1c) = 1;
    UNLOCK();
  } while( true );
}



===== WPP_RECORDER_SF_q @ 1c0003bf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_q(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_8ae6e206fd5f3a01a789e273b148a72f_Traceguids,param_4,&param_6,8,0);
  }
  WppAutoLogTrace(param_1,5,2,&WPP_8ae6e206fd5f3a01a789e273b148a72f_Traceguids,param_4,&param_6,8,0)
  ;
  return;
}



===== WPP_RECORDER_SF_qDd @ 1c0003c9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_8ae6e206fd5f3a01a789e273b148a72f_Traceguids,0xf,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,4,2,&WPP_8ae6e206fd5f3a01a789e273b148a72f_Traceguids,0xf,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_qql @ 1c0003d90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qql(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_8ae6e206fd5f3a01a789e273b148a72f_Traceguids,0xb,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,4,2,&WPP_8ae6e206fd5f3a01a789e273b148a72f_Traceguids,0xb,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,0);
  return;
}



===== MouHid_Close @ 1c0003e90 =====

void MouHid_Close(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x15,
                     &WPP_bce545a1de1235e2be96703916423b99_Traceguids);
  }
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  ExAcquireFastMutex(lVar2 + 0x110);
  if ((lVar3 != 0) && (lVar3 == *(longlong *)(lVar2 + 0x80))) {
    LOCK();
    *(int *)(lVar2 + 0x18) = *(int *)(lVar2 + 0x18) + -1;
    UNLOCK();
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqql(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    KeWaitForSingleObject(lVar2 + 0xa8,0,0,0,0);
    IoCancelIrp(*(undefined8 *)(lVar2 + 0x70));
    KeWaitForSingleObject(lVar2 + 0x90,0,0,0,0);
    LOCK();
    iVar1 = *(int *)(lVar2 + 0x88);
    *(int *)(lVar2 + 0x88) = 3;
    UNLOCK();
    if (iVar1 == 2) {
      KeWaitForSingleObject(lVar2 + 0xc0,0,0,0,0);
    }
    *(undefined8 *)(lVar2 + 0x80) = 0;
  }
  ExReleaseFastMutex(lVar2 + 0x110);
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x17,
                     &WPP_bce545a1de1235e2be96703916423b99_Traceguids);
  }
  IofCallDriver(*(undefined8 *)(lVar2 + 8),param_2);
  return;
}



===== MouHid_Create @ 1c0004080 =====

int MouHid_Create(longlong param_1,ulonglong param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  longlong lVar5;
  int iVar6;
  int iVar7;
  ulonglong uVar8;
  undefined2 uVar9;
  longlong lVar10;
  bool bVar11;
  undefined4 uVar12;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  local_48 = 0;
  uStack_40 = 0;
  lVar10 = 0;
  local_38 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0xe,
                     &WPP_bce545a1de1235e2be96703916423b99_Traceguids);
  }
  lVar2 = *(longlong *)(param_2 + 0xb8);
  puVar3 = *(undefined8 **)(param_1 + 0x40);
  if (*(short *)(*(longlong *)(lVar2 + 0x30) + 0x58) == 0) {
    puVar1 = puVar3 + 0x1e;
    uVar8 = param_2;
    iVar6 = IoAcquireRemoveLockEx(puVar1,param_2,"",1,0x20);
    if (-1 < iVar6) {
      ExAcquireFastMutex(puVar3 + 0x22);
      if (puVar3[0x1d] == 0) {
        iVar6 = -0x3fffffff;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar8 = CONCAT71((int7)(uVar8 >> 8),2);
          WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x10,
                              &WPP_bce545a1de1235e2be96703916423b99_Traceguids,(char)param_1,
                              (char)param_2,1);
        }
      }
      else {
        puVar4 = *(undefined8 **)(param_2 + 0xb8);
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
        KeInitializeEvent(&local_48,0,0);
        lVar5 = *(longlong *)(param_2 + 0xb8);
        *(code **)(lVar5 + -0x10) = MouHid_CreateComplete;
        *(undefined8 **)(lVar5 + -8) = &local_48;
        *(undefined1 *)(lVar5 + -0x45) = 0xe0;
        iVar6 = IofCallDriver(puVar3[1]);
        uVar12 = 0;
        uVar8 = 0;
        KeWaitForSingleObject(&local_48,0,0,0,0);
        if ((((-1 < iVar6) && (iVar6 = *(int *)(param_2 + 0x30), -1 < iVar6)) &&
            (uVar8 = (ulonglong)*(ushort *)(lVar2 + 0x1a), puVar3[0x10] == 0)) &&
           ((*(uint *)(*(longlong *)(lVar2 + 8) + 0x10) & 1) != 0)) {
          LOCK();
          *(int *)(puVar3 + 3) = *(int *)(puVar3 + 3) + 1;
          UNLOCK();
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qqqDDl(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          }
          lVar10 = *(longlong *)(lVar2 + 0x30);
          puVar3[0x10] = lVar10;
          LOCK();
          *(undefined4 *)(puVar3 + 0x11) = 1;
          UNLOCK();
          KeResetEvent(puVar3 + 0x12);
          LOCK();
          *(undefined4 *)((longlong)puVar3 + 0x1c) = 2;
          UNLOCK();
          uVar8 = puVar3[0xe];
          IoAcquireRemoveLockEx(puVar1,uVar8,"",1,CONCAT44(uVar12,0x20));
          *(undefined4 *)(puVar3[0xe] + 0x30) = 0;
          iVar6 = MouHid_StartRead(puVar3);
          if (iVar6 == 0x103) {
            iVar6 = 0;
          }
          else if (iVar6 < 0) {
            puVar3[0x10] = 0;
          }
        }
      }
      ExReleaseFastMutex(puVar3 + 0x22);
      if ((-1 < iVar6) && (lVar10 != 0)) {
        LOCK();
        bVar11 = *(int *)(puVar3 + 7) == 0;
        if (bVar11) {
          *(int *)(puVar3 + 7) = 0;
        }
        UNLOCK();
        if (bVar11) {
          KeResetEvent(puVar3 + 0x18);
          LOCK();
          bVar11 = *(int *)(puVar3 + 0x11) == 1;
          if (bVar11) {
            *(int *)(puVar3 + 0x11) = 2;
          }
          UNLOCK();
          if (bVar11) {
            iVar7 = MouHid_SetResolutionMultipliers(puVar3,uVar8);
            LOCK();
            *(uint *)(puVar3 + 7) = (iVar7 != -0x3fffff45) + 1;
            UNLOCK();
            LOCK();
            if (*(int *)(puVar3 + 0x11) == 2) {
              *(int *)(puVar3 + 0x11) = 1;
            }
            UNLOCK();
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x12,
                                  &WPP_bce545a1de1235e2be96703916423b99_Traceguids,(char)param_1,
                                  (char)param_2,(char)iVar7);
            }
          }
          KeSetEvent(puVar3 + 0x18,0,0);
        }
      }
      *(int *)(param_2 + 0x30) = iVar6;
      *(undefined8 *)(param_2 + 0x38) = 0;
      IofCompleteRequest(param_2,0);
      IoReleaseRemoveLockEx(puVar1,param_2,0x20);
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar6;
      }
      if (*(short *)(WPP_GLOBAL_Control + 0x48) == 0) {
        return iVar6;
      }
      uVar9 = 0x13;
      goto LAB_1c0004520;
    }
  }
  else {
    iVar6 = -0x3fffffde;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
  *(int *)(param_2 + 0x30) = iVar6;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
    return iVar6;
  }
  if (*(short *)(WPP_GLOBAL_Control + 0x48) == 0) {
    return iVar6;
  }
  uVar9 = 0x14;
LAB_1c0004520:
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,uVar9,
                   &WPP_bce545a1de1235e2be96703916423b99_Traceguids);
  return iVar6;
}



===== MouHid_CreateComplete @ 1c0004560 =====

undefined8 MouHid_CreateComplete(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== MouHid_SetResolutionFeatureForUsage @ 1c000458c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int MouHid_SetResolutionFeatureForUsage
              (undefined8 *param_1,undefined2 param_2,undefined2 param_3,int *param_4)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  ulonglong uVar5;
  undefined1 *puVar6;
  undefined2 uVar7;
  undefined1 auStackY_f8 [32];
  undefined1 local_a8 [2];
  undefined1 local_a6;
  ushort local_a2;
  uint local_88;
  int local_80;
  int local_7c;
  int local_74;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_f8;
  puVar6 = (undefined1 *)0x48;
  memset(local_a8,0,0x48);
  lVar1 = param_1[0x1b];
  *param_4 = 1;
  if (*(short *)(lVar1 + 0x30) != 0) {
    puVar6 = (undefined1 *)0x0;
    iVar2 = HidP_GetSpecificValueCaps(0,param_2,0,param_3);
    if ((((-1 < iVar2) && (puVar4 = (undefined1 *)(ulonglong)local_a2, local_a2 != 0)) &&
        (iVar2 = HidP_GetSpecificValueCaps(2,1), puVar6 = puVar4, -1 < iVar2)) &&
       (local_80 < local_7c)) {
      puVar6 = (undefined1 *)0x48756f4d;
      puVar4 = (undefined1 *)ExAllocatePool2(0x40,*(undefined2 *)(lVar1 + 0x30));
      if (puVar4 == (undefined1 *)0x0) {
        iVar2 = -0x3fffff66;
        goto LAB_1c000480e;
      }
      *puVar4 = local_a6;
      puVar6 = (undefined1 *)0x0;
      iVar2 = MouHid_CallHidClass((longlong)param_1,0xb0192,0,0,puVar4,
                                  (uint)*(ushort *)(lVar1 + 0x30));
      if (-1 < iVar2) {
        puVar6 = (undefined1 *)(ulonglong)local_a2;
        iVar2 = HidP_SetUsageValue(2,1,puVar6,0x48);
        if (iVar2 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar7 = 10;
LAB_1c000475b:
            WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar6,uVar7,
                               &WPP_bce545a1de1235e2be96703916423b99_Traceguids,(char)*param_1,
                               (char)iVar2);
          }
        }
        else {
          puVar6 = puVar4;
          iVar2 = MouHid_CallHidClass((longlong)param_1,0xb0191,puVar4,
                                      (uint)*(ushort *)(lVar1 + 0x30),0,0);
          if (iVar2 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar7 = 0xb;
              goto LAB_1c000475b;
            }
          }
          else {
            puVar6 = (undefined1 *)0x1;
            iVar3 = 1;
            if (local_88 != 0) {
              uVar5 = (ulonglong)local_88;
              do {
                iVar3 = iVar3 * 10;
                uVar5 = uVar5 - 1;
              } while (uVar5 != 0);
            }
            *param_4 = iVar3 * local_74;
          }
        }
      }
      ExFreePoolWithTag(puVar4,0);
      if (-1 < iVar2) {
        return iVar2;
      }
      goto LAB_1c000480e;
    }
  }
  iVar2 = -0x3fffff45;
LAB_1c000480e:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar6,0xc,
                       &WPP_bce545a1de1235e2be96703916423b99_Traceguids,(char)*param_1,(char)iVar2);
  }
  return iVar2;
}



===== MouHid_SetResolutionMultipliers @ 1c0004870 =====

int MouHid_SetResolutionMultipliers(undefined8 *param_1,ulonglong param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  int iVar6;
  int local_res8 [2];
  int local_res10 [2];
  
  lVar1 = param_1[0x1b];
  iVar4 = 1;
  local_res8[0] = 1;
  local_res10[0] = 1;
  iVar6 = 1;
  iVar3 = 0;
  if ((*(short *)(lVar1 + 4) != 0) && (*(char *)(param_1 + 0xb) == '\0')) {
    param_2 = (ulonglong)*(ushort *)(lVar1 + 0x12);
    iVar3 = MouHid_SetResolutionFeatureForUsage
                      (param_1,*(ushort *)(lVar1 + 0x12),*(undefined2 *)(lVar1 + 0x14),local_res8);
    if (iVar3 < 0) goto LAB_1c0004902;
  }
  iVar6 = local_res8[0];
  if ((*(short *)(param_1[0x1b] + 6) != 0) && (*(char *)((longlong)param_1 + 0x5e) == '\0')) {
    param_2 = (ulonglong)*(ushort *)(lVar1 + 0x18);
    iVar3 = MouHid_SetResolutionFeatureForUsage
                      (param_1,*(ushort *)(lVar1 + 0x18),*(undefined2 *)(lVar1 + 0x1a),local_res10);
    iVar4 = local_res10[0];
    if (iVar3 < 0) {
      iVar4 = 1;
    }
  }
LAB_1c0004902:
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 8);
  *(int *)((longlong)param_1 + 100) = iVar6;
  uVar5 = CONCAT71((int7)(param_2 >> 8),uVar2);
  *(int *)(param_1 + 0xd) = iVar4;
  KeReleaseSpinLock(param_1 + 8);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,5,0xd,
                        &WPP_bce545a1de1235e2be96703916423b99_Traceguids,(char)*param_1,(char)iVar6,
                        (char)iVar4);
  }
  return iVar3;
}



===== WPP_RECORDER_SF_qqqDDl @ 1c0004990 =====

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
               &WPP_bce545a1de1235e2be96703916423b99_Traceguids,0x11,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,8,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_bce545a1de1235e2be96703916423b99_Traceguids,0x11,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,8,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  return;
}



===== WPP_RECORDER_SF_qqqd @ 1c0004ae4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqqd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined4 local_18 [4];
  
  local_18[0] = 0xc0000022;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_bce545a1de1235e2be96703916423b99_Traceguids,0xf,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,8,local_18,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_bce545a1de1235e2be96703916423b99_Traceguids,0xf,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,8,
                  local_18,4,0);
  return;
}



===== WPP_RECORDER_SF_qqql @ 1c0004c04 =====

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
               &WPP_bce545a1de1235e2be96703916423b99_Traceguids,0x16,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,8,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_bce545a1de1235e2be96703916423b99_Traceguids,0x16,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,8,
                  &uStack0000000000000048,4,0);
  return;
}



===== _guard_check_icall @ 1c0004d30 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0004d48 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c0004d6c =====

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



===== __cpu_features_init @ 1c0004de0 =====

/* WARNING: Removing unreachable block (ram,0x0001c0004e4a) */
/* WARNING: Removing unreachable block (ram,0x0001c0004df9) */
/* WARNING: Removing unreachable block (ram,0x0001c0004dea) */

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



===== __security_check_cookie @ 1c0004eb0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0004ef0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0004f20 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0004f20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0004f50 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0004fc0 =====

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



===== memset @ 1c00052c0 =====

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



===== __memset_repmovs @ 1c0005400 =====

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



===== __memset_query @ 1c0005480 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0005500 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0005640 =====

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



===== __memset_spec_plain @ 1c00056c0 =====

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



===== MouHid_Unload @ 1c000b010 =====

void MouHid_Unload(undefined8 param_1)

{
  ExFreePoolWithTag(DAT_1c0008170,0);
  WppCleanupKm(param_1);
  return;
}



===== WppCleanupKm @ 1c000b044 =====

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



===== WppInitKm @ 1c000b0f4 =====

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



===== WppLoadTracingSupport @ 1c000b1d0 =====

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



===== WppTraceCallback @ 1c000b320 =====

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



===== MouHid_CallHidClass @ 1c000b5a8 =====

int MouHid_CallHidClass(longlong param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
                       undefined8 param_5,undefined4 param_6)

{
  int iVar1;
  longlong lVar2;
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
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,10,
                     &WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids);
  }
  KeInitializeEvent(&local_38,0,0);
  lVar2 = IoBuildDeviceIoControlRequest
                    (param_2,*(undefined8 *)(param_1 + 8),param_3,param_4,param_5,param_6,0,
                     &local_38,&local_48);
  if (lVar2 == 0) {
    iVar1 = -0x3fffffff;
  }
  else {
    *(undefined8 *)(*(longlong *)(lVar2 + 0xb8) + -0x18) = *(undefined8 *)(param_1 + 0x80);
    iVar1 = IofCallDriver(*(undefined8 *)(param_1 + 8),lVar2);
    if (iVar1 == 0x103) {
      iVar1 = KeWaitForSingleObject(&local_38,0,0,0,0);
    }
    if (-1 < iVar1) {
      iVar1 = (int)local_48;
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0xb,
                       &WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids);
    }
  }
  return iVar1;
}



===== MouHid_PnP @ 1c000b750 =====

int MouHid_PnP(longlong param_1,longlong param_2)

{
  byte bVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 *puVar5;
  int iVar6;
  
  plVar2 = *(longlong **)(param_1 + 0x40);
  lVar3 = *(longlong *)(param_2 + 0xb8);
  lVar4 = plVar2[0x1b];
  iVar6 = IoAcquireRemoveLockEx(plVar2 + 0x1e,param_2,"",1,0x20);
  if (iVar6 < 0) {
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(int *)(param_2 + 0x30) = iVar6;
    IofCompleteRequest(param_2,0);
    return iVar6;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqc(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  bVar1 = *(byte *)(lVar3 + 1);
  if (bVar1 < 10) {
    if (bVar1 != 9) {
      if (bVar1 != 0) {
        if (bVar1 != 1) {
          if (bVar1 == 2) {
            IoWMIRegistrationControl(*plVar2,2);
            *(undefined1 *)((longlong)plVar2 + 0x21) = 1;
            KeWaitForSingleObject(plVar2 + 0x15,0,0,0,0);
            IoCancelIrp(plVar2[0xe]);
            *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
            *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
            *(undefined4 *)(param_2 + 0x30) = 0;
            iVar6 = IofCallDriver(plVar2[1],param_2);
            IoReleaseRemoveLockAndWaitEx(plVar2 + 0x1e,param_2,0x20);
            IoFreeIrp(plVar2[0xe]);
            if (lVar4 != 0) {
              ExFreePoolWithTag(*(undefined8 *)(lVar4 + 0x20),0);
              IoFreeMdl(*(undefined8 *)(lVar4 + 0x90));
              ExFreePoolWithTag(lVar4,0);
            }
            IoDetachDevice(plVar2[1]);
            IoDeleteDevice(*plVar2);
            return iVar6;
          }
          if (bVar1 != 3) {
            if (bVar1 == 4) {
              *(undefined1 *)(plVar2 + 4) = 0;
            }
            else if ((bVar1 != 5) && (bVar1 != 6)) goto LAB_1c000babc;
          }
        }
        goto LAB_1c000bab8;
      }
      if ((char)plVar2[4] == '\0') {
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
        KeInitializeEvent(plVar2 + 0x29,0,0);
        lVar3 = *(longlong *)(param_2 + 0xb8);
        *(code **)(lVar3 + -0x10) = MouHid_PnPComplete;
        *(longlong **)(lVar3 + -8) = plVar2;
        *(undefined1 *)(lVar3 + -0x45) = 0xe0;
        *(undefined4 *)(param_2 + 0x30) = 0;
        iVar6 = IofCallDriver(plVar2[1],param_2);
        if (iVar6 == 0x103) {
          KeWaitForSingleObject(plVar2 + 0x29,0,0,0,0);
          iVar6 = *(int *)(param_2 + 0x30);
        }
        if ((-1 < iVar6) && (-1 < *(int *)(param_2 + 0x30))) {
          if (*(char *)((longlong)plVar2 + 0x22) == '\0') {
            iVar6 = MouHid_StartDevice(plVar2);
            if (iVar6 < 0) goto LAB_1c000ba7f;
            IoWMIRegistrationControl(param_1,1);
            *(undefined1 *)((longlong)plVar2 + 0x22) = 1;
          }
          *(undefined1 *)(plVar2 + 4) = 1;
        }
LAB_1c000ba7f:
        *(int *)(param_2 + 0x30) = iVar6;
        *(undefined8 *)(param_2 + 0x38) = 0;
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x16,
                           &WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids);
        }
        iVar6 = 0;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      IofCompleteRequest(param_2,0);
      goto LAB_1c000badc;
    }
  }
  else if ((((((bVar1 != 10) && (bVar1 != 0xb)) && (bVar1 != 0xf)) &&
            ((bVar1 != 0x10 && (bVar1 != 0x11)))) &&
           ((bVar1 != 0x12 && ((bVar1 != 0x13 && (bVar1 != 0x14)))))) && (bVar1 == 0x17)) {
LAB_1c000bab8:
    *(undefined4 *)(param_2 + 0x30) = 0;
  }
LAB_1c000babc:
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  iVar6 = IofCallDriver(plVar2[1],param_2);
LAB_1c000badc:
  IoReleaseRemoveLockEx(plVar2 + 0x1e,param_2,0x20);
  return iVar6;
}



===== MouHid_StartDevice @ 1c000bb20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int MouHid_StartDevice(longlong *param_1)

{
  undefined2 *puVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  longlong lVar6;
  undefined2 *puVar7;
  longlong lVar8;
  uint uVar9;
  ulonglong uVar10;
  undefined1 auStackY_128 [32];
  ulonglong local_e0;
  undefined4 local_d8;
  short local_c8;
  short sStack_c6;
  ushort uStack_c4;
  undefined2 uStack_c2;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined1 local_88 [15];
  char local_79;
  undefined2 local_76;
  int local_54;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  memset(&local_c8,0,0x40);
  local_e0 = 0;
  local_d8 = 0;
  puVar7 = (undefined2 *)0x0;
  memset(local_88,0,0x48);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,5,0x14,
                     &WPP_da562ded6bb73c5031c86e6f6181bb7a_Traceguids);
  }
  iVar3 = MouHid_CallHidClass((longlong)param_1,0xb01a8,0,0,&local_e0,0xc);
  if (iVar3 < 0) {
    return iVar3;
  }
  lVar6 = ExAllocatePool2(0x40,local_e0 & 0xffffffff);
  if (lVar6 == 0) {
    return -0x3fffff66;
  }
  iVar3 = MouHid_CallHidClass((longlong)param_1,0xb0193,0,0,lVar6,(undefined4)local_e0);
  if ((-1 < iVar3) && (iVar3 = HidP_GetCaps(lVar6,&local_c8), -1 < iVar3)) {
    if ((sStack_c6 != 1) || ((local_c8 != 2 && ((local_c8 != 1 || (DAT_1c0008162 != '\0')))))) {
      iVar3 = -0x3fffffff;
      goto LAB_1c000c0d1;
    }
    uVar2 = HidP_MaxUsageListLength(0,9,lVar6);
    uVar9 = uStack_c4 + 7 & 0xfffffff8;
    uVar4 = (uint)uVar2 * 2 + 7 & 0xfffffff8;
    uVar10 = (ulonglong)uVar4;
    puVar7 = (undefined2 *)ExAllocatePool2(0x40,uVar9 + (uVar4 + 0x26) * 4,0x48756f4d);
    param_1[0x1b] = (longlong)puVar7;
    if (puVar7 != (undefined2 *)0x0) {
      *(longlong *)(puVar7 + 0x10) = lVar6;
      puVar1 = puVar7 + 0x4c;
      *(ulonglong *)(puVar7 + 0x14) =
           CONCAT26(uStack_c2,CONCAT24(uStack_c4,CONCAT22(sStack_c6,local_c8)));
      *(undefined8 *)(puVar7 + 0x18) = uStack_c0;
      *(undefined8 *)(puVar7 + 0x1c) = local_b8;
      *(undefined8 *)(puVar7 + 0x20) = uStack_b0;
      *(undefined4 *)(puVar7 + 0x24) = local_a8;
      *(undefined4 *)(puVar7 + 0x26) = uStack_a4;
      *(undefined4 *)(puVar7 + 0x28) = uStack_a0;
      *(undefined4 *)(puVar7 + 0x2a) = uStack_9c;
      *(undefined4 *)(puVar7 + 0x2c) = local_98;
      *(undefined4 *)(puVar7 + 0x2e) = uStack_94;
      *(undefined4 *)(puVar7 + 0x30) = uStack_90;
      *(undefined4 *)(puVar7 + 0x32) = uStack_8c;
      puVar7[0xe] = uVar2;
      *(ushort *)((longlong)param_1 + 0x17a) = uVar2;
      *(undefined2 **)(puVar7 + 0x34) = puVar1;
      lVar8 = (longlong)puVar1 + (ulonglong)uVar9;
      *(longlong *)(puVar7 + 0x3c) = lVar8;
      lVar8 = lVar8 + uVar10;
      *(longlong *)(puVar7 + 0x38) = lVar8;
      lVar8 = lVar8 + uVar10;
      *(longlong *)(puVar7 + 0x40) = lVar8;
      *(ulonglong *)(puVar7 + 0x44) = uVar10 + lVar8;
      lVar8 = IoAllocateMdl(puVar1,uStack_c4,0,0);
      *(longlong *)(puVar7 + 0x48) = lVar8;
      if (lVar8 != 0) {
        MmBuildMdlForNonPagedPool(lVar8);
        iVar3 = HidP_GetSpecificValueCaps(0,1,0,0x30);
        if (iVar3 < 0) goto LAB_1c000c0d1;
        if (local_79 == '\0') {
          *(undefined2 *)((longlong)param_1 + 0x162) = 0;
          *(undefined1 *)(puVar7 + 8) = 0;
        }
        else if (((local_c8 == 1) && (DAT_1c0008161 != '\0')) || (Globals == '\0')) {
          *(undefined2 *)((longlong)param_1 + 0x162) = 1;
          *(undefined1 *)(puVar7 + 8) = 1;
        }
        else {
          *(undefined2 *)((longlong)param_1 + 0x162) = 0;
          *(undefined1 *)(puVar7 + 8) = 0;
          *(uint *)(param_1 + 0xf) = *(uint *)(param_1 + 0xf) | 1;
          MouHid_LogError(*(undefined8 *)(*param_1 + 8),0x80050002);
        }
        *puVar7 = local_76;
        iVar3 = local_54;
        if (local_54 == 0) {
          iVar3 = (1 << ((char)local_76 - 1U & 0x1f)) + -1;
        }
        *(int *)(puVar7 + 4) = iVar3;
        iVar3 = HidP_GetSpecificValueCaps(0,1,0,0x31);
        if (iVar3 < 0) goto LAB_1c000c0d1;
        puVar7[1] = local_76;
        if (local_54 == 0) {
          local_54 = (1 << ((char)local_76 - 1U & 0x1f)) + -1;
        }
        *(int *)(puVar7 + 6) = local_54;
        if (*(short *)((longlong)param_1 + 0x5c) == 0) {
          iVar5 = HidP_GetSpecificValueCaps(0,1,0,0x38);
          if (-1 < iVar5) {
            puVar7[2] = local_76;
            *(undefined2 *)(param_1 + 0x2f) = 0x100;
            *(undefined1 *)((longlong)puVar7 + 0x11) = 0;
            *(undefined4 *)(puVar7 + 9) = 0x380001;
            goto LAB_1c000bfec;
          }
          iVar5 = HidP_GetSpecificValueCaps(0,1,0,0x32);
          if (-1 < iVar5) {
            puVar7[2] = local_76;
            *(undefined2 *)(param_1 + 0x2f) = 0x100;
            *(undefined1 *)((longlong)puVar7 + 0x11) = 0;
            *(undefined4 *)(puVar7 + 9) = 0x320001;
            goto LAB_1c000bfec;
          }
        }
        else {
          iVar5 = HidP_GetSpecificValueCaps(0,*(undefined2 *)((longlong)param_1 + 0x5a));
          if (-1 < iVar5) {
            puVar7[2] = local_76;
            *(undefined2 *)(param_1 + 0x2f) = 0x100;
            *(undefined1 *)((longlong)puVar7 + 0x11) = 0;
            puVar7[9] = *(undefined2 *)((longlong)param_1 + 0x5a);
            puVar7[10] = *(undefined2 *)((longlong)param_1 + 0x5c);
            goto LAB_1c000bfec;
          }
        }
        *(undefined1 *)((longlong)puVar7 + 0x11) = 1;
        puVar7[2] = 0;
LAB_1c000bfec:
        if (*(short *)((longlong)param_1 + 0x62) == 0) {
          iVar5 = HidP_GetSpecificValueCaps(0,0xc,0,0x238);
          if (-1 < iVar5) {
            puVar7[3] = local_76;
            if (DAT_1c000817c == 5) {
              *(ushort *)(param_1 + 0x2f) = *(ushort *)(param_1 + 0x2f) | 0x8000;
            }
            *(undefined1 *)(puVar7 + 0xb) = 0;
            *(undefined4 *)(puVar7 + 0xc) = 0x238000c;
            return iVar3;
          }
        }
        else {
          iVar5 = HidP_GetSpecificValueCaps(0,(short)param_1[0xc]);
          if (-1 < iVar5) {
            puVar7[3] = local_76;
            if (DAT_1c000817c == 5) {
              *(ushort *)(param_1 + 0x2f) = *(ushort *)(param_1 + 0x2f) | 0x8000;
            }
            *(undefined1 *)(puVar7 + 0xb) = 0;
            puVar7[0xc] = (short)param_1[0xc];
            puVar7[0xd] = *(undefined2 *)((longlong)param_1 + 0x62);
            return iVar3;
          }
        }
        *(undefined1 *)(puVar7 + 0xb) = 1;
        puVar7[3] = 0;
        return iVar3;
      }
    }
    iVar3 = -0x3fffff66;
  }
LAB_1c000c0d1:
  ExFreePoolWithTag(lVar6,0);
  if (puVar7 != (undefined2 *)0x0) {
    if (*(longlong *)(puVar7 + 0x48) != 0) {
      IoFreeMdl();
    }
    ExFreePoolWithTag(puVar7,0);
    param_1[0x1b] = 0;
  }
  return iVar3;
}



===== MouHid_QueryWmiDataBlock @ 1c000c150 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void MouHid_QueryWmiDataBlock
               (longlong param_1,undefined8 param_2,int param_3,int param_4,int param_5,
               undefined4 *param_6,uint param_7,undefined4 *param_8)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined1 auStack_58 [32];
  undefined1 local_38;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  uint uStack_1c;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  uVar2 = 0;
  if (param_3 == 0) {
    if ((param_4 == 0) && (param_5 == 1)) {
      uVar2 = 0x14;
      if (param_7 < 0x14) {
        uVar1 = 0xc0000023;
      }
      else {
        uStack_24 = *(undefined4 *)(*(longlong *)(param_1 + 0x40) + 0x180);
        uStack_20 = 0;
        uStack_1c = (uint)*(ushort *)(*(longlong *)(param_1 + 0x40) + 0x17a);
        local_28 = 2;
        *(ulonglong *)param_8 = CONCAT44(uStack_24,2);
        *(ulonglong *)(param_8 + 2) = (ulonglong)uStack_1c << 0x20;
        param_8[4] = 0;
        uVar1 = 0;
        *param_6 = 0x14;
      }
    }
    else {
      uVar1 = 0xc0000010;
    }
  }
  else {
    uVar1 = 0xc0000295;
  }
  local_38 = 0;
  WmiCompleteRequest(param_1,param_2,uVar1,uVar2);
  return;
}



===== MouHid_QueryWmiRegInfo @ 1c000c220 =====

undefined8
MouHid_QueryWmiRegInfo
          (longlong param_1,undefined4 *param_2,undefined8 param_3,undefined8 *param_4,
          undefined8 param_5,undefined8 *param_6)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  *param_2 = 0x20;
  *param_4 = &DAT_1c0008168;
  *param_6 = *(undefined8 *)(lVar1 + 0x10);
  return 0;
}



===== MouHid_SetWmiDataBlock @ 1c000c250 =====

void MouHid_SetWmiDataBlock(undefined8 param_1,undefined8 param_2,int param_3)

{
  WmiCompleteRequest(param_1,param_2,(-(uint)(param_3 != 0) & 0xffffffcf) + 0xc00002c6,0,0);
  return;
}



===== MouHid_SystemControl @ 1c000c290 =====

undefined4 MouHid_SystemControl(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  int local_res8 [2];
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_res8[0] = 0;
  uVar2 = WmiSystemControl(lVar1 + 0x198,param_1,param_2,local_res8);
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



===== entry @ 1c000d010 =====

void entry(longlong param_1,ushort *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 1c000d044 =====

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



===== DriverEntry @ 1c000d078 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1,ushort *param_2)

{
  int iVar1;
  
  _DAT_1c0008128 = 1;
  _WPP_MAIN_CB = 0;
  DAT_1c0008108 = &WPP_ThisDir_CTLGUID_MouHidTraceGuid;
  DAT_1c0008110 = 0;
  _DAT_1c0008120 = 0;
  _DAT_1c0008140 = 0;
  _DAT_1c0008148 = 0;
  WppLoadTracingSupport();
  _DAT_1c0008120 = 0;
  WppInitKm(param_1,param_2);
  _Globals = 0;
  DAT_1c0008170 = (void *)0x0;
  _DAT_1c0008178 = 0;
  _DAT_1c0008168 = (ulonglong)CONCAT22(*param_2 + 2,*param_2);
  DAT_1c0008170 = (void *)ExAllocatePool2(0x100,*param_2 + 2,0x48756f4d);
  if (DAT_1c0008170 == (void *)0x0) {
    iVar1 = -0x3fffff66;
  }
  else {
    memcpy(DAT_1c0008170,*(void **)(param_2 + 4),(ulonglong)*param_2);
    iVar1 = MouHid_GetRegistryParameters(param_1);
    if (-1 < iVar1) {
      *(code **)(param_1 + 0x70) = MouHid_Create;
      *(code **)(param_1 + 0x80) = MouHid_Close;
      *(code **)(param_1 + 0xe8) = MouHid_IOCTL;
      *(code **)(param_1 + 0xe0) = MouHid_PassThrough;
      *(code **)(param_1 + 0xb8) = MouHid_Flush;
      *(code **)(param_1 + 0x148) = MouHid_PnP;
      *(code **)(param_1 + 0x120) = MouHid_Power;
      *(code **)(param_1 + 0x128) = MouHid_SystemControl;
      *(code **)(param_1 + 0x68) = MouHid_Unload;
      *(code **)(*(longlong *)(param_1 + 0x30) + 8) = MouHid_AddDevice;
      return iVar1;
    }
  }
  if (DAT_1c0008170 != (void *)0x0) {
    ExFreePoolWithTag(DAT_1c0008170,0);
  }
  WppCleanupKm(param_1);
  return iVar1;
}



===== MouHid_GetRegistryParameters @ 1c000d21c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int MouHid_GetRegistryParameters(undefined8 param_1)

{
  byte bVar1;
  int iVar2;
  longlong lVar3;
  uint local_res10 [2];
  uint local_res18 [2];
  uint local_res20 [2];
  longlong local_28 [2];
  
  local_28[0] = 0;
  local_res10[0] = 0;
  local_res18[0] = 0;
  local_res20[0] = 0;
  lVar3 = ExAllocatePool2(0x100,0xe0,0x48756f4d);
  if (lVar3 == 0) {
    iVar2 = -0x3fffffff;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,6,0x10,
                        &WPP_5fb2b8b2da473567e94ec36236fb6212_Traceguids,1);
    }
  }
  else {
    iVar2 = IoOpenDriverRegistryKey(param_1,0,0x20019,0,local_28);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,6,0x11,
                          &WPP_5fb2b8b2da473567e94ec36236fb6212_Traceguids,(char)iVar2);
      }
    }
    else {
      local_res10[0] = (uint)DAT_1c0008162;
      *(wchar_t **)(lVar3 + 0x10) = L"UseOnlyMice";
      *(undefined4 *)(lVar3 + 8) = 0x120;
      *(uint **)(lVar3 + 0x18) = local_res10;
      *(undefined4 *)(lVar3 + 0x30) = 4;
      *(uint **)(lVar3 + 0x28) = local_res10;
      *(undefined4 *)(lVar3 + 0x20) = 0x4000004;
      bVar1 = Globals;
      local_res18[0] = (uint)Globals;
      *(wchar_t **)(lVar3 + 0x48) = L"TreatAbsoluteAsRelative";
      *(uint **)(lVar3 + 0x50) = local_res18;
      *(uint **)(lVar3 + 0x60) = local_res18;
      *(undefined4 *)(lVar3 + 0x40) = 0x120;
      *(undefined4 *)(lVar3 + 0x68) = 4;
      *(undefined4 *)(lVar3 + 0x58) = 0x4000004;
      local_res20[0] = (uint)DAT_1c0008161;
      Globals = bVar1;
      *(wchar_t **)(lVar3 + 0x80) = L"TreatAbsolutePointerAsAbsolute";
      *(uint **)(lVar3 + 0x88) = local_res20;
      *(undefined4 *)(lVar3 + 0x78) = 0x120;
      *(undefined4 *)(lVar3 + 0xa0) = 4;
      *(uint **)(lVar3 + 0x98) = local_res20;
      *(undefined4 *)(lVar3 + 0x90) = 0x4000004;
      iVar2 = RtlQueryRegistryValuesEx(0x40000000,local_28[0],lVar3,0,0);
      if (-1 < iVar2) goto LAB_1c000d412;
    }
    _Globals = 0;
    iVar2 = 0;
    DAT_1c0008162 = 0;
  }
LAB_1c000d412:
  if (local_28[0] != 0) {
    ZwClose();
    local_28[0] = 0;
  }
  if (lVar3 != 0) {
    ExFreePoolWithTag(lVar3,0);
  }
  return iVar2;
}


