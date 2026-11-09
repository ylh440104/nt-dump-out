
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



===== WPP_SF_D @ 1c0001020 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_Dq @ 1c0001064 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,8,0);
  return;
}



===== WPP_SF_q @ 1c00010b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,0);
  return;
}



===== WPP_SF_qD @ 1c00010fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,4,0);
  return;
}



===== WPP_SF_qq @ 1c0001150 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,0);
  return;
}



===== DepFSBugCheckNotEnoughSpace @ 1c00011a0 =====

void DepFSBugCheckNotEnoughSpace(int param_1)

{
  int iVar1;
  ulonglong in_stack_ffffffffffffff68;
  undefined8 local_88;
  undefined4 local_80 [2];
  undefined8 local_78;
  undefined8 local_70;
  wchar_t *local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 *local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  ulonglong uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  ulonglong uStack_18;
  
  local_80[0] = 0;
  local_88 = 0;
  local_78 = 0;
  local_68 = L"\\BaseNamedObjects\\BootShellComplete";
  local_70 = 0x480046;
  local_60 = 0;
  uStack_58 = 0;
  local_40 = 0;
  uStack_38 = uStack_38 & 0xffffffff00000000;
  local_50 = (undefined8 *)0x0;
  uStack_48 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  iVar1 = ZwQuerySystemInformation(0x5a,&local_30,0x20,local_80);
  if ((-1 < iVar1) && ((uStack_18 & 1) != 0)) {
    uStack_58 = 0;
    local_50 = &local_70;
    local_40 = 0;
    uStack_38 = 0;
    local_60 = CONCAT44(local_60._4_4_,0x30);
    uStack_48 = CONCAT44(uStack_48._4_4_,0x200);
    while( true ) {
      in_stack_ffffffffffffff68 = in_stack_ffffffffffffff68 & 0xffffffffffffff00;
      iVar1 = ZwCreateEvent(&local_88,0x100000,&local_60,0,in_stack_ffffffffffffff68);
      if (iVar1 != -0x3fffffc6) break;
      local_78 = 0xfffffffffff85ee0;
      KeDelayExecutionThread(0,0,&local_78);
    }
    if (-1 < iVar1) {
      ZwWaitForSingleObject(local_88,0,0);
      ZwClose(local_88);
    }
  }
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0x136,0,(longlong)param_1,0,0);
}



===== DepFSCheckRamdiskBoot @ 1c00012d8 =====

undefined1 DepFSCheckRamdiskBoot(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined1 uVar4;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined1 local_48 [4];
  longlong local_44;
  longlong local_3c;
  int local_34;
  
  local_58 = 0;
  local_68 = 0;
  uStack_60 = 0;
  uVar4 = 0;
  local_78 = 0;
  uStack_70 = 0;
  memset(local_48,0,0x40);
  KeInitializeEvent(&local_68,0,0);
  uVar2 = IoGetAttachedDeviceReference(*(undefined8 *)(param_1 + 8));
  lVar3 = IoBuildDeviceIoControlRequest(0x240008,uVar2,0,0,local_48,0x40,0,&local_68,&local_78);
  if (lVar3 != 0) {
    iVar1 = IofCallDriver(uVar2,lVar3);
    if (iVar1 == 0x103) {
      KeWaitForSingleObject(&local_68,0,0,0,0);
      iVar1 = (int)local_78;
    }
    if ((-1 < iVar1) && (local_34 == 3)) {
      local_44 = local_44 + -0x4dcb684ed9b257fc;
      if (local_44 == 0) {
        local_44 = local_3c + -0x50b7f6a2cf0379ab;
      }
      uVar4 = 0;
      if (local_44 == 0) {
        uVar4 = 1;
      }
    }
  }
  ObfDereferenceObject(uVar2);
  return uVar4;
}



===== WPP_SF_ @ 1c000141c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_DD @ 1c0001448 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,0);
  return;
}



===== FsDepHandleBugcheck @ 1c00014a0 =====

void FsDepHandleBugcheck(void)

{
  if (((*(int *)KiBugCheckData_exref == 0x12f) || (*(int *)KiBugCheckData_exref == 0x136)) &&
     (DAT_1c00051cd == '\0')) {
    DAT_1c00051cd = '\x01';
    KeStallExecutionProcessor(20000000);
  }
  return;
}



===== WppClassicProviderCallback @ 1c00014f0 =====

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



===== WPP_SF_Dqq @ 1c0001524 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dqq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_qqD @ 1c0001584 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,&param_6,4,0);
  return;
}



===== DepFSPostVolumeMount @ 1c00015f0 =====

undefined8
DepFSPostVolumeMount(ulonglong param_1,longlong *param_2,undefined *param_3,ulonglong param_4)

{
  bool bVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  longlong *plVar6;
  code *pcVar7;
  longlong local_res8;
  longlong local_res18;
  
  local_res8 = 0;
  local_res18 = 0;
  iVar4 = 0;
  bVar1 = true;
  plVar6 = param_2;
  pcVar7 = (code *)param_3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    plVar6 = (longlong *)0x2a;
    pcVar7 = (code *)&WPP_bc64936b77293105c4440102cf4189d6_Traceguids;
    param_4 = param_1;
    WPP_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
               &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,param_1,(char)param_2[4],
               (char)param_2[2]);
  }
  iVar2 = 0;
  if (-1 < *(int *)(param_1 + 0x18)) goto LAB_1c000166e;
  if (DAT_1c0005194 == '\0') {
    if ((DAT_1c0005195 == '\0') && (DAT_1c0005196 == '\0')) {
      plVar6 = &local_res18;
      iVar4 = FltGetDeviceObject(param_2[2]);
      if (iVar4 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (plVar6 = (longlong *)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
            (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          plVar6 = (longlong *)0x2d;
LAB_1c0001716:
          pcVar7 = (code *)&WPP_bc64936b77293105c4440102cf4189d6_Traceguids;
          WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(short)plVar6,
                    &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,param_2[2],(char)iVar4);
        }
      }
      else if ((*(int *)(local_res18 + 0x48) - 7U < 2) || (*(int *)(local_res18 + 0x48) == 0x24)) {
        plVar6 = &local_res8;
        iVar4 = FltGetDiskDeviceObject(param_2[2]);
        if (iVar4 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            plVar6 = (longlong *)0x2f;
            goto LAB_1c0001716;
          }
        }
        else {
          cVar3 = KeGetCurrentIrql();
          if (cVar3 == '\x02') {
            pcVar7 = DepFSDecrementActiveMountCountForVolume;
            plVar6 = DAT_1c0005110;
            iVar4 = FltQueueGenericWorkItem
                              (param_3,DAT_1c0005110,DepFSDecrementActiveMountCountForVolume,1,
                               local_res8);
            if (-1 < iVar4) {
              local_res8 = 0;
              bVar1 = false;
              goto LAB_1c000190b;
            }
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              pcVar7 = (code *)&WPP_bc64936b77293105c4440102cf4189d6_Traceguids;
              plVar6 = (longlong *)0x30;
              WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
                         &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,param_2[2],
                         (char)param_2[3],(char)iVar4);
            }
          }
          else {
            uVar5 = DepFSForEachDependency(local_res8,(ulonglong)plVar6,pcVar7,param_4);
            iVar4 = (int)uVar5;
            iVar2 = iVar4;
            if (-1 < iVar4) goto LAB_1c000166e;
          }
        }
      }
      else {
        iVar2 = iVar4;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          pcVar7 = (code *)&WPP_bc64936b77293105c4440102cf4189d6_Traceguids;
          plVar6 = (longlong *)0x2e;
          WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
                    &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,param_2[2],(char)param_2[3]);
        }
LAB_1c000166e:
        iVar4 = iVar2;
        bVar1 = false;
      }
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
      plVar6 = (longlong *)0x2c;
      goto LAB_1c00018c4;
    }
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    plVar6 = (longlong *)0x2b;
LAB_1c00018c4:
    pcVar7 = (code *)&WPP_bc64936b77293105c4440102cf4189d6_Traceguids;
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(short)plVar6,
              &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,param_2[2],(char)param_2[3]);
  }
  if (param_3 != (undefined *)0x0) {
    FltFreeGenericWorkItem(param_3);
  }
  if (local_res8 != 0) {
    ObfDereferenceObject();
  }
LAB_1c000190b:
  if (local_res18 != 0) {
    ObfDereferenceObject();
  }
  if (bVar1) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
                &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,param_2[2],(char)param_2[3]);
    }
    pcVar7 = (code *)0x0;
    plVar6 = (longlong *)0x0;
    KeSetEvent(&DAT_1c0005200);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qqqDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),plVar6,pcVar7,param_1,(char)param_2[4],
                 (char)param_2[2],(char)iVar4);
  }
  return 0;
}



===== WPP_SF_qddZ @ 1c00019e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qddZ(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,wchar_t *param_7)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  wchar_t wVar3;
  undefined8 local_res20;
  
  if (param_7 == (wchar_t *)0x0) {
    wVar3 = L'\b';
  }
  else {
    wVar3 = *param_7;
    if (*param_7 != L'\0') {
      pwVar1 = *(wchar_t **)(param_7 + 4);
      goto LAB_1c0001a1c;
    }
  }
  pwVar1 = L"NULL";
LAB_1c0001a1c:
  pwVar2 = param_7;
  if (param_7 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,4,&param_6,4,pwVar2,2,pwVar1,wVar3
             ,0);
  return;
}



===== WPP_SF_qqq @ 1c0001ab0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_qqqD @ 1c0001b0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqqD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_bc64936b77293105c4440102cf4189d6_Traceguids,0x24,&local_res20,8,
             &param_5,8,&param_6,8,&param_7,4,0);
  return;
}



===== WPP_SF_qqqDD @ 1c0001b80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqqDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  undefined4 local_18 [6];
  
  local_18[0] = 0;
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_bc64936b77293105c4440102cf4189d6_Traceguids,0x32,&local_res20,8,
             &param_5,8,&param_6,8,&param_7,4,local_18,4,0);
  return;
}



===== WPP_SF_Dqqq @ 1c0001c08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dqqq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_d7b1782a7daa350f3d08b40019c93e7e_Traceguids,0x1b,local_res20,4,
             &param_5,8,&param_6,8,&param_7,8,0);
  return;
}



===== DepFSDeleteParentLink @ 1c0001c7c =====

void DepFSDeleteParentLink(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  
  plVar1 = (longlong *)(param_1 + 0x18);
  lVar2 = *plVar1;
  if ((*(longlong **)(lVar2 + 8) == plVar1) &&
     (plVar3 = *(longlong **)(param_1 + 0x20), (longlong *)*plVar3 == plVar1)) {
    *plVar3 = lVar2;
    plVar1 = (longlong *)(param_1 + 0x28);
    *(longlong **)(lVar2 + 8) = plVar3;
    lVar2 = *plVar1;
    if ((*(longlong **)(lVar2 + 8) == plVar1) &&
       (plVar3 = *(longlong **)(param_1 + 0x30), (longlong *)*plVar3 == plVar1)) {
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      ExFreePoolWithTag(param_1,0x6c507044);
      return;
    }
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== WPP_SF_qi @ 1c0001ce4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qi(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_6b5a76be7742304abc77e760f08b1d6f_Traceguids,0xf,&local_res20,8,
             &param_5,8,0);
  return;
}



===== WPP_SF_qqqqq @ 1c0001d3c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqqqq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_6b5a76be7742304abc77e760f08b1d6f_Traceguids,0x1c,&local_res20,8,
             &param_5,8,&param_6,8,&param_7,8,&param_8,8,0);
  return;
}



===== _guard_check_icall @ 1c0001dd0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0001de8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c0001e0c =====

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



===== __cpu_features_init @ 1c0001e80 =====

/* WARNING: Removing unreachable block (ram,0x0001c0001eea) */
/* WARNING: Removing unreachable block (ram,0x0001c0001e99) */
/* WARNING: Removing unreachable block (ram,0x0001c0001e8a) */

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



===== __security_check_cookie @ 1c0001f50 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0001f90 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0001fc0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0001fc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0001ff0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0002040 =====

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



===== memset @ 1c0002340 =====

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



===== __memset_repmovs @ 1c0002480 =====

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



===== __memset_query @ 1c0002500 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0002580 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c00026c0 =====

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



===== __memset_spec_plain @ 1c0002740 =====

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



===== DepFSAutochkWaitWorker @ 1c0008010 =====

void DepFSAutochkWaitWorker(void)

{
  code *pcVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  ulonglong uVar7;
  uint uVar8;
  longlong local_res10 [2];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  
  local_res10[0] = 0;
  bVar2 = false;
  local_20 = 0;
  local_38 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_48 = 0;
  uStack_40 = 0;
  while( true ) {
    cVar3 = FsRtlAreVolumeStartupApplicationsComplete();
    if (cVar3 != '\0') break;
    local_res10[1] = 0xffffffffff676980;
    KeDelayExecutionThread(0,0);
  }
  if ((DAT_1c0005194 == '\0') && (DAT_1c0005196 == '\0')) {
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite();
    bVar2 = true;
    if ((DAT_1c0005194 == '\0') && ((DAT_1c0005196 == '\0' && (DAT_1c00051c4 != 4)))) {
      iVar4 = DepFSGenerateDependencyList(0,(undefined8 **)0x0,0,local_res10,'\x01',0x8000);
      if ((iVar4 < 0) &&
         ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                 &WPP_a4016d7e857d3af68560d770380f4c36_Traceguids,iVar4);
      }
      if (local_res10[0] != 0) {
        uVar7 = 0;
        lVar5 = local_res10[0];
        if (*(int *)(local_res10[0] + 4) != 0) {
          do {
            lVar6 = uVar7 * 0x10 + lVar5;
            if (!bVar2) {
              bVar2 = true;
              KeEnterCriticalRegion();
              ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
              lVar5 = local_res10[0];
            }
            if (((*(byte *)(lVar6 + 8) & 2) != 0) &&
               (lVar6 = *(longlong *)(lVar6 + 0x10),
               *(longlong **)(lVar6 + 0x28) != (longlong *)(lVar6 + 0x28))) {
              if (((*(uint *)(lVar6 + 0x3c) & 4) == 0) &&
                 (uVar8 = *(uint *)(lVar6 + 0x5c), (uVar8 & 0x403) == 0)) {
                if ((*(uint *)(lVar6 + 0x3c) & 2) == 0) {
                  *(uint *)(lVar6 + 0x5c) = uVar8 | 0x600;
                  local_38 = CONCAT44(local_38._4_4_,0x12);
                }
                else {
                  *(uint *)(lVar6 + 0x5c) = uVar8 | 0x200;
                  local_38 = CONCAT44(local_38._4_4_,2);
                }
                local_48 = *(undefined8 *)(lVar6 + 0x68);
                uStack_40 = *(undefined8 *)(lVar6 + 0x78);
                KeInitializeEvent(&local_30,0,0);
                lVar5 = IoBuildDeviceIoControlRequest
                                  (0x2d9198,*(undefined8 *)(lVar6 + 0x80),&local_48,0x18,0,0,0,
                                   &local_30,&local_58);
                if (lVar5 == 0) {
                  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                             &WPP_a4016d7e857d3af68560d770380f4c36_Traceguids,lVar6);
                  }
                }
                else {
                  if (bVar2 != false) {
                    ExReleaseResourceLite(&DAT_1c0005118);
                    KeLeaveCriticalRegion();
                    bVar2 = false;
                  }
                  iVar4 = IofCallDriver(*(undefined8 *)(lVar6 + 0x80),lVar5);
                  if (iVar4 == 0x103) {
                    KeWaitForSingleObject(&local_30,0,0,0,0);
                    iVar4 = (int)local_58;
                  }
                  if (iVar4 < 0) {
                    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                      WPP_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                                &WPP_a4016d7e857d3af68560d770380f4c36_Traceguids,iVar4,(char)lVar6);
                    }
                    if (((*(uint *)(lVar6 + 0x3c) & 0x10) != 0) && ((local_38 & 0x10) != 0)) {
                      DepFSBugCheckNotEnoughSpace(iVar4);
                      pcVar1 = (code *)swi(3);
                      (*pcVar1)();
                      return;
                    }
                  }
                }
                lVar5 = local_res10[0];
              }
            }
            uVar8 = (int)uVar7 + 1;
            uVar7 = (ulonglong)uVar8;
          } while (uVar8 < *(uint *)(lVar5 + 4));
          if (bVar2 == false) {
            bVar2 = true;
            KeEnterCriticalRegion();
            ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
            lVar5 = local_res10[0];
          }
        }
        uVar7 = 0;
        if (*(int *)(lVar5 + 4) != 0) {
          do {
            lVar6 = uVar7 * 0x10 + lVar5;
            if (((*(byte *)(lVar6 + 8) & 1) != 0) && (*(longlong *)(lVar6 + 0x10) != 0)) {
              DereferenceVolumeContext(*(longlong *)(lVar6 + 0x10));
              lVar5 = local_res10[0];
            }
            if (((*(byte *)(lVar6 + 8) & 2) != 0) && (*(longlong *)(lVar6 + 0x10) != 0)) {
              DereferenceDependencyContext(*(longlong *)(lVar6 + 0x10),bVar2,'\0');
              lVar5 = local_res10[0];
            }
            uVar8 = (int)uVar7 + 1;
            uVar7 = (ulonglong)uVar8;
          } while (uVar8 < *(uint *)(lVar5 + 4));
        }
        ExFreePoolWithTag(lVar5,0x6c447044);
      }
    }
  }
  FsDepRegisterUnregisterForBugchecks('\0',bVar2);
  if (bVar2 != false) {
    ExReleaseResourceLite(&DAT_1c0005118);
    KeLeaveCriticalRegion();
  }
  return;
}



===== DepFSFindOurVolumeContext @ 1c0008440 =====

int DepFSFindOurVolumeContext(longlong param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  longlong *plVar2;
  int iVar3;
  undefined8 *puVar4;
  
  puVar4 = DAT_1c00051a0;
  do {
    if ((undefined8 **)puVar4 == &DAT_1c00051a0) {
      return -0x3fffffff;
    }
    puVar1 = puVar4 + -5;
    plVar2 = puVar4 + 4;
    puVar4 = (undefined8 *)*puVar4;
  } while (*plVar2 != param_1);
  iVar3 = ReferenceVolumeContext((longlong)puVar1,'\0');
  if (iVar3 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                &WPP_a4016d7e857d3af68560d770380f4c36_Traceguids,iVar3,(char)puVar1);
    }
  }
  else {
    *param_2 = puVar1;
  }
  return iVar3;
}



===== DepFSHandleAutochkForHostVolume @ 1c00084e8 =====

int DepFSHandleAutochkForHostVolume(undefined8 **param_1,int param_2)

{
  uint *puVar1;
  undefined8 **ppuVar2;
  longlong lVar3;
  bool bVar4;
  int iVar5;
  longlong lVar6;
  ulonglong uVar7;
  uint uVar8;
  longlong local_res18;
  undefined8 local_res20;
  undefined8 *local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  local_res18 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_48 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_60 = 0;
  local_70 = 0;
  uStack_68 = 0;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
  bVar4 = true;
  iVar5 = DepFSGenerateDependencyList(0,param_1,0,&local_res18,'\x01',0x8000);
  if ((((iVar5 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
             &WPP_a4016d7e857d3af68560d770380f4c36_Traceguids,iVar5);
  }
  if (local_res18 != 0) {
    uVar7 = 0;
    if (*(int *)(local_res18 + 4) != 0) {
      do {
        lVar3 = local_res18;
        if (!bVar4) {
          bVar4 = true;
          KeEnterCriticalRegion();
          ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
        }
        if ((((*(byte *)(lVar3 + 8 + uVar7 * 0x10) & 1) != 0) &&
            (ppuVar2 = *(undefined8 ***)(lVar3 + 0x10 + uVar7 * 0x10), ppuVar2 != param_1)) &&
           ((((ulonglong)ppuVar2[7] & 0x24) == 0 &&
            ((param_2 == 1 && (ppuVar2[0xd] == (undefined8 *)0x0)))))) {
          local_res20 = 0;
          local_88 = (undefined8 *)0x0;
          if (bVar4 != false) {
            ExReleaseResourceLite(&DAT_1c0005118);
            KeLeaveCriticalRegion();
            bVar4 = false;
          }
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                     &WPP_a4016d7e857d3af68560d770380f4c36_Traceguids,ppuVar2);
          }
          iVar5 = FltOpenVolume(ppuVar2[8],&local_88);
          if (iVar5 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                        &WPP_a4016d7e857d3af68560d770380f4c36_Traceguids,ppuVar2[9],(char)iVar5);
            }
            iVar5 = 0;
          }
          else {
            iVar5 = FltFlushBuffers(ppuVar2[8],local_res20);
            if (iVar5 < 0) {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
                 (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                          &WPP_a4016d7e857d3af68560d770380f4c36_Traceguids,ppuVar2[9],(char)iVar5);
              }
              iVar5 = 0;
            }
            ObfDereferenceObject(local_res20);
            FltClose(local_88);
          }
        }
        if ((*(byte *)(lVar3 + 8 + uVar7 * 0x10) & 2) != 0) {
          lVar3 = *(longlong *)(lVar3 + 0x10 + uVar7 * 0x10);
          puVar1 = (uint *)(lVar3 + 0x5c);
          if (param_2 == 2) {
            if ((*puVar1 & 0x200) != 0) goto LAB_1c000892b;
            *puVar1 = *puVar1 | 0x200;
          }
          if (((*(longlong **)(lVar3 + 0x28) != (longlong *)(lVar3 + 0x28)) &&
              ((*(uint *)(lVar3 + 0x3c) & 4) == 0)) && ((*puVar1 & 3) == 0)) {
            local_70 = *(undefined8 *)(lVar3 + 0x68);
            uStack_68 = *(undefined8 *)(lVar3 + 0x78);
            local_60 = CONCAT44(local_60._4_4_,param_2);
            KeInitializeEvent(&local_58,0,0);
            lVar6 = IoBuildDeviceIoControlRequest
                              (0x2d9198,*(undefined8 *)(lVar3 + 0x80),&local_70,0x18,0,0,0,&local_58
                               ,&local_80);
            if (lVar6 == 0) {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                         &WPP_a4016d7e857d3af68560d770380f4c36_Traceguids,lVar3);
              }
              iVar5 = -0x3fffff66;
            }
            else {
              if (bVar4 != false) {
                ExReleaseResourceLite(&DAT_1c0005118);
                KeLeaveCriticalRegion();
                bVar4 = false;
              }
              iVar5 = IofCallDriver(*(undefined8 *)(lVar3 + 0x80));
              if (iVar5 == 0x103) {
                KeWaitForSingleObject(&local_58,0,0,0,0);
                iVar5 = (int)local_80;
              }
              if (iVar5 < 0) {
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                   (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                  WPP_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                            &WPP_a4016d7e857d3af68560d770380f4c36_Traceguids,iVar5,(char)lVar3);
                }
                if ((*(uint *)(lVar3 + 0x3c) & 0x10) != 0) {
                    /* WARNING: Subroutine does not return */
                  KeBugCheckEx(0x136,0,(longlong)iVar5,0,0);
                }
              }
            }
          }
        }
LAB_1c000892b:
        uVar8 = (int)uVar7 + 1;
        uVar7 = (ulonglong)uVar8;
      } while (uVar8 < *(uint *)(local_res18 + 4));
      if (bVar4 == false) {
        bVar4 = true;
        KeEnterCriticalRegion();
        ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
      }
    }
    uVar8 = 0;
    if (*(int *)(local_res18 + 4) != 0) {
      do {
        lVar3 = local_res18;
        uVar7 = (ulonglong)uVar8;
        if (((*(byte *)(local_res18 + 8 + uVar7 * 0x10) & 1) != 0) &&
           (lVar6 = *(longlong *)(local_res18 + 0x10 + uVar7 * 0x10), lVar6 != 0)) {
          DereferenceVolumeContext(lVar6);
        }
        if (((*(byte *)(lVar3 + 8 + uVar7 * 0x10) & 2) != 0) &&
           (lVar3 = *(longlong *)(lVar3 + 0x10 + uVar7 * 0x10), lVar3 != 0)) {
          DereferenceDependencyContext(lVar3,bVar4,'\0');
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < *(uint *)(local_res18 + 4));
    }
    ExFreePoolWithTag(local_res18,0x6c447044);
    if (bVar4 == false) {
      return iVar5;
    }
  }
  ExReleaseResourceLite(&DAT_1c0005118);
  KeLeaveCriticalRegion();
  return iVar5;
}



===== DepFSPostCleanup @ 1c0008a40 =====

undefined8 DepFSPostCleanup(longlong param_1,longlong param_2,undefined8 param_3,ulonglong param_4)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 **ppuVar3;
  int iVar4;
  undefined8 **local_18 [2];
  
  local_18[0] = (undefined8 **)0x0;
  if ((((DAT_1c000518c != 0) && ((param_4 & 1) == 0)) &&
      (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 8), lVar1 != 0)) &&
     ((*(uint *)(lVar1 + 0x50) & 0x400000) != 0)) {
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
    iVar4 = DepFSFindOurVolumeContext(*(longlong *)(param_2 + 0x10),local_18);
    ppuVar3 = local_18[0];
    if (iVar4 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                 &WPP_a4016d7e857d3af68560d770380f4c36_Traceguids,iVar4);
      }
      ExReleaseResourceLite(&DAT_1c0005118);
      KeLeaveCriticalRegion();
    }
    else {
      puVar2 = *(undefined8 **)(*(longlong *)(param_1 + 0x10) + 8);
      if (local_18[0][0xd] == puVar2) {
        local_18[0][0xd] = (undefined8 *)0x0;
        *(undefined4 *)(local_18[0] + 0xc) = 8;
        DAT_1c000518c = DAT_1c000518c + -1;
        ExReleaseResourceLite(&DAT_1c0005118);
        KeLeaveCriticalRegion();
        DepFSHandleAutochkForHostVolume(ppuVar3,2);
      }
      else {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                    &WPP_a4016d7e857d3af68560d770380f4c36_Traceguids,puVar2,(char)local_18[0][0xd]);
        }
        ExReleaseResourceLite(&DAT_1c0005118);
        KeLeaveCriticalRegion();
      }
      DereferenceVolumeContext((longlong)ppuVar3);
    }
  }
  return 0;
}



===== DepFSPostCreate @ 1c0008bf0 =====

undefined8 DepFSPostCreate(longlong param_1,longlong param_2,undefined8 param_3,ulonglong param_4)

{
  longlong lVar1;
  undefined8 **ppuVar2;
  int iVar3;
  undefined8 **local_18 [2];
  
  local_18[0] = (undefined8 **)0x0;
  if ((((param_4 & 1) == 0) &&
      (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 8), lVar1 != 0)) &&
     ((*(uint *)(lVar1 + 0x50) & 0x400000) != 0)) {
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
    iVar3 = DepFSFindOurVolumeContext(*(longlong *)(param_2 + 0x10),local_18);
    ppuVar2 = local_18[0];
    if (iVar3 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                 &WPP_a4016d7e857d3af68560d770380f4c36_Traceguids,iVar3);
      }
    }
    else {
      if (*(int *)(param_1 + 0x18) < 0) {
        *(undefined4 *)(local_18[0] + 0xc) = 0x10;
        local_18[0][0xd] = (undefined8 *)0x0;
        DAT_1c000518c = DAT_1c000518c + -1;
        ExReleaseResourceLite();
        KeLeaveCriticalRegion();
        DepFSHandleAutochkForHostVolume(ppuVar2,2);
      }
      else {
        local_18[0][0xd] = *(undefined8 **)(*(longlong *)(param_1 + 0x10) + 8);
        *(undefined4 *)(local_18[0] + 0xc) = 2;
        ExReleaseResourceLite(&DAT_1c0005118);
        KeLeaveCriticalRegion();
      }
      DereferenceVolumeContext((longlong)ppuVar2);
    }
  }
  return 0;
}



===== DepFSPreCreate @ 1c0008d40 =====

uint DepFSPreCreate(longlong param_1,longlong param_2)

{
  uint *puVar1;
  longlong lVar2;
  char cVar3;
  undefined8 uVar4;
  undefined2 uVar5;
  uint uVar6;
  uint local_res20 [2];
  uint local_18 [2];
  undefined8 **local_10;
  
  local_res20[0] = 0;
  local_10 = (undefined8 **)0x0;
  uVar6 = 1;
  cVar3 = FsRtlAreVolumeStartupApplicationsComplete();
  puVar1 = *(uint **)(param_1 + 0x10);
  lVar2 = *(longlong *)(puVar1 + 2);
  if (cVar3 == '\0') {
    if ((((lVar2 == 0) || ((*(uint *)(lVar2 + 0x50) & 0x400000) == 0)) ||
        ((*(byte *)((longlong)puVar1 + 0x2a) & 6) != 0)) ||
       ((*(uint *)(*(longlong *)(puVar1 + 6) + 0x10) & 6) == 0)) goto LAB_1c000901f;
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
    local_res20[0] = DepFSFindOurVolumeContext(*(longlong *)(param_2 + 0x10),&local_10);
    if (-1 < (int)local_res20[0]) {
      if (((undefined8 **)local_10[1] == local_10 + 1) || (*(int *)(local_10 + 0xc) - 1U < 2)) {
        ExReleaseResourceLite(&DAT_1c0005118);
        KeLeaveCriticalRegion();
      }
      else {
        *(undefined4 *)(local_10 + 0xc) = 1;
        local_10[0xd] = *(undefined8 **)(*(longlong *)(param_1 + 0x10) + 8);
        DAT_1c000518c = DAT_1c000518c + 1;
        ExReleaseResourceLite(&DAT_1c0005118);
        KeLeaveCriticalRegion();
        local_res20[0] = DepFSHandleAutochkForHostVolume(local_10,1);
        uVar6 = local_res20[0] >> 0x1f;
      }
      DereferenceVolumeContext((longlong)local_10);
      goto LAB_1c000901f;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c000901f;
    uVar5 = 0xc;
  }
  else {
    if (((lVar2 == 0) || ((*(uint *)(lVar2 + 0x50) & 0x400000) == 0)) ||
       (((*(char *)(param_1 + 0x50) != '\0' || ((*puVar1 & 1) == 0)) &&
        (*(char *)(param_1 + 0x50) != '\x01')))) goto LAB_1c000901f;
    local_res20[0] = FltGetInstanceContext(*(undefined8 *)(param_2 + 0x18),&local_10);
    if (-1 < (int)local_res20[0]) {
      local_18[0] = 0;
      lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18);
      if ((lVar2 != 0) && (local_10[0xf] != (undefined8 *)0x0)) {
        uVar4 = IoGetFileObjectGenericMapping();
        cVar3 = SeAccessCheck(local_10[0xf],*(longlong *)(lVar2 + 8) + 0x20,0,
                              *(undefined4 *)(lVar2 + 0x10),0,0,uVar4,1,local_18,local_res20);
        if (cVar3 == '\0') {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                     &WPP_a4016d7e857d3af68560d770380f4c36_Traceguids,local_res20[0]);
          }
        }
        else {
          *(uint *)(*(longlong *)(lVar2 + 8) + 0x14) = local_18[0];
          puVar1 = (uint *)(*(longlong *)(lVar2 + 8) + 0x10);
          *puVar1 = *puVar1 & ~(local_18[0] | 0x2000000);
        }
      }
      FltReleaseContext(local_10);
      goto LAB_1c000901f;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c000901f;
    uVar5 = 0xb;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
           &WPP_a4016d7e857d3af68560d770380f4c36_Traceguids,local_res20[0]);
LAB_1c000901f:
  if ((int)local_res20[0] < 0) {
    *(uint *)(param_1 + 0x18) = local_res20[0];
    uVar6 = 4;
  }
  return uVar6;
}



===== DepFSCheckFileSystemNameForMatch @ 1c0009050 =====

undefined1 DepFSCheckFileSystemNameForMatch(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  char cVar2;
  undefined1 uVar3;
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 8) + 0x38);
  if ((lVar1 != 0) && (*(longlong *)(lVar1 + 8) != 0)) {
    cVar2 = RtlEqualUnicodeString
                      (param_2,*(longlong *)(*(longlong *)(lVar1 + 8) + 8) + 0x38,
                       CONCAT71((int7)((ulonglong)lVar1 >> 8),1));
    if (cVar2 != '\0') {
      return 1;
    }
  }
  uVar3 = 0;
  if ((*(longlong *)(param_1 + 0x10) != 0) &&
     (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 8), lVar1 != 0)) {
    cVar2 = RtlEqualUnicodeString(param_2,*(longlong *)(lVar1 + 8) + 0x38,1);
    uVar3 = 0;
    if (cVar2 != '\0') {
      uVar3 = 1;
    }
  }
  return uVar3;
}



===== DepFSCheckHostFileObject @ 1c00090fc =====

int DepFSCheckHostFileObject(longlong param_1,longlong param_2,uint param_3,int *param_4)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  undefined2 uVar4;
  wchar_t *pwVar5;
  int local_res10 [2];
  undefined4 local_28 [2];
  undefined8 local_20;
  undefined8 uStack_18;
  
  if (DAT_1c0005108 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
               &WPP_89de4c9ab0183a893b206e6614efcf73_Traceguids,0xc0000184);
    }
    return -0x3ffffe7c;
  }
  uVar1 = *(uint *)(*(longlong *)(param_2 + 8) + 0x48);
  if ((0x24 < uVar1) || ((0x1000100080U >> ((ulonglong)uVar1 & 0x3f) & 1) == 0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                &WPP_89de4c9ab0183a893b206e6614efcf73_Traceguids,uVar1,0x27);
    }
    return -0x3ffffbd9;
  }
  if ((DAT_1c000519a == '\0') || ((param_3 & 0x210) != 0)) {
    if ((DAT_1c0005195 != 0) || (DAT_1c0005194 != '\0')) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                  &WPP_89de4c9ab0183a893b206e6614efcf73_Traceguids,(uint)DAT_1c0005195,DAT_1c0005194
                 );
      }
      return -0x3ffffe77;
    }
    if (uVar1 == 0x14) {
      if ((param_3 & 0x10) == 0) {
        if (param_1 == 0) {
          return 0;
        }
        local_res10[0] = 0;
        local_28[0] = 4;
        if (DAT_1c00051c8 == 0) {
          local_20 = 0;
          uStack_18 = 0;
          RtlInitUnicodeString(&local_20,L"\\Device\\LanmanRedirector");
          FsRtlMupGetProviderIdFromName(&local_20,&DAT_1c00051c8);
        }
        iVar3 = FsRtlMupGetProviderInfoFromFileObject(param_2,1,local_res10,local_28);
        if (-1 < iVar3) {
          if (local_res10[0] == DAT_1c00051c8) {
            iVar3 = DepFSCheckSmbLoopback(param_1);
            return iVar3;
          }
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return -0x3ffffbd9;
          }
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
            return -0x3ffffbd9;
          }
          if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
            return -0x3ffffbd9;
          }
          uVar4 = 0x24;
          goto LAB_1c00091d7;
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return iVar3;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
          return iVar3;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
          return iVar3;
        }
        uVar4 = 0x23;
        goto LAB_1c00091dd;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3ffffbd9;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return -0x3ffffbd9;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return -0x3ffffbd9;
      }
      uVar4 = 0x22;
    }
    else {
      local_20 = 0;
      uStack_18 = 0;
      if ((uVar1 == 7) || (uVar1 == 0x24)) {
        RtlInitUnicodeString(&local_20,L"\\FileSystem\\Ntfs");
        cVar2 = DepFSCheckFileSystemNameForMatch(param_2,&local_20);
        if (cVar2 != '\0') {
          return 0;
        }
        RtlInitUnicodeString(&local_20,L"\\FileSystem\\exfat");
        cVar2 = DepFSCheckFileSystemNameForMatch(param_2,&local_20);
        if (cVar2 != '\0') {
          DepFSCheckRamdiskBoot(param_2);
        }
        return 1;
      }
      if ((param_3 >> 4 & 1) == 0) {
        if ((uVar1 == 7) || (uVar1 == 0x24)) {
          if (*param_4 - 2U < 3) {
            RtlInitUnicodeString(&local_20,L"\\FileSystem\\RAW");
            cVar2 = DepFSCheckFileSystemNameForMatch(param_2,&local_20);
            if (cVar2 == '\0') {
              RtlInitUnicodeString(&local_20,L"\\FileSystem\\exfat");
              cVar2 = DepFSCheckFileSystemNameForMatch(param_2,&local_20);
              if (cVar2 == '\0') {
                pwVar5 = L"\\FileSystem\\Fastfat";
                goto LAB_1c0009308;
              }
            }
          }
          else if (*param_4 == 1) {
            pwVar5 = L"\\FileSystem\\RAW";
LAB_1c0009308:
            RtlInitUnicodeString(&local_20,pwVar5);
            cVar2 = DepFSCheckFileSystemNameForMatch(param_2,&local_20);
            if (cVar2 == '\0') {
              RtlInitUnicodeString(&local_20,L"\\FileSystem\\Udfs");
              cVar2 = DepFSCheckFileSystemNameForMatch(param_2,&local_20);
              if (cVar2 == '\0') {
                return 0;
              }
            }
          }
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return -0x3ffffbd9;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
          return -0x3ffffbd9;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
          return -0x3ffffbd9;
        }
        uVar4 = 0x21;
      }
      else {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return -0x3ffffbd9;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
          return -0x3ffffbd9;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
          return -0x3ffffbd9;
        }
        uVar4 = 0x1f;
      }
    }
    iVar3 = -0x3ffffbd9;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
            &WPP_89de4c9ab0183a893b206e6614efcf73_Traceguids);
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffbd9;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return -0x3ffffbd9;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return -0x3ffffbd9;
    }
    uVar4 = 0x1d;
LAB_1c00091d7:
    iVar3 = -0x3ffffbd9;
LAB_1c00091dd:
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
             &WPP_89de4c9ab0183a893b206e6614efcf73_Traceguids,iVar3);
  }
  return iVar3;
}



===== DepFSCheckSmbLoopback @ 1c00095d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DepFSCheckSmbLoopback(undefined8 param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined1 auStack_118 [32];
  uint local_f8;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined8 local_b0;
  undefined8 uStack_a8;
  short local_98 [2];
  int local_94;
  byte local_88;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_118;
  local_e8 = 0;
  local_b4 = 0;
  local_d0 = 0x30;
  local_e0 = 0;
  uStack_d8 = 0;
  memset(local_98,0,0x74);
  local_c8 = 0;
  local_c0 = 0;
  local_b8 = 0x200;
  local_f8 = local_f8 & 0xffffff00;
  local_b0 = 0;
  uStack_a8 = 0;
  iVar1 = ZwCreateEvent(&local_e8,0x100000,&local_d0,1);
  if (iVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return iVar1;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return iVar1;
    }
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
             &WPP_89de4c9ab0183a893b206e6614efcf73_Traceguids,iVar1);
    return iVar1;
  }
  local_f8 = 0x37;
  iVar1 = ZwQueryInformationFile(param_1,&local_e0,local_98);
  if (iVar1 == 0x103) {
    ZwWaitForSingleObject(local_e8,0,0);
    iVar1 = (int)local_e0;
  }
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c000978b;
    uVar2 = 0x26;
  }
  else {
    if (((local_98[0] == 0) || (local_94 != 0x20000)) || ((local_88 & 1) == 0)) goto LAB_1c000978b;
    iVar1 = -0x3ffffbd9;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c000978b;
    uVar2 = 0x27;
    iVar1 = -0x3ffffbd9;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
           &WPP_89de4c9ab0183a893b206e6614efcf73_Traceguids,iVar1);
LAB_1c000978b:
  if (((((DAT_1c000519c != '\0') && (*KdDebuggerEnabled_exref != (code)0x0)) &&
       (*KdDebuggerNotPresent_exref == (code)0x0)) &&
      ((iVar1 = 0, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)))) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
             &WPP_89de4c9ab0183a893b206e6614efcf73_Traceguids,0);
  }
  ZwClose(local_e8);
  return iVar1;
}



===== DependentFSCheckFileHandle @ 1c0009820 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DependentFSCheckFileHandle
              (longlong param_1,longlong param_2,uint param_3,int *param_4,undefined8 param_5,
              undefined8 param_6,int *param_7)

{
  ushort uVar1;
  longlong lVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  undefined8 uVar9;
  longlong lVar10;
  undefined2 uVar11;
  int iVar12;
  uint uVar13;
  ulonglong uVar14;
  undefined1 auStackY_138 [32];
  uint local_104;
  ulonglong local_100;
  longlong local_f8;
  longlong local_f0;
  undefined8 local_e8;
  longlong local_e0;
  undefined8 local_d8;
  ulonglong uStack_d0;
  undefined2 *local_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  ulonglong local_90;
  ulonglong local_88 [5];
  undefined4 local_60;
  undefined2 local_5c;
  ulonglong local_58;
  
                    /* 0x9820  1  DependentFSCheckFileHandle */
  local_58 = __security_cookie ^ (ulonglong)auStackY_138;
  local_90 = 0;
  local_c8 = (undefined2 *)0x0;
  local_e0 = 0;
  bVar4 = false;
  bVar5 = false;
  bVar3 = false;
  local_b0 = 0;
  uStack_a8 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  if (param_7 != (int *)0x0) {
    *param_7 = 1;
  }
  iVar7 = DepFSCheckHostFileObject(param_1,param_2,param_3,param_4);
  if (iVar7 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar7;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return iVar7;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return iVar7;
    }
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_89de4c9ab0183a893b206e6614efcf73_Traceguids,iVar7);
    return iVar7;
  }
  if ((*(short *)(param_2 + 0x58) == 0) || (*(longlong *)(param_2 + 0x60) == 0)) {
LAB_1c0009afd:
    iVar7 = ZwQueryInformationFile(param_1,&local_d8,&local_b0,0x28);
    if (-1 < iVar7) {
      iVar7 = (int)local_d8;
      if (-1 < (int)local_d8) {
        if (0x27 < uStack_d0) {
          uVar8 = (uint)local_90;
          if (((uVar8 >> 0xe & 1) == 0) || ((param_3 >> 0xd & 1) != 0)) {
            if ((local_90 & 0x10) == 0) {
              if ((uVar8 >> 10 & 1) != 0) {
                local_100 = 0;
                iVar7 = ZwQueryInformationFile(param_1,&local_d8,&local_100,8);
                if ((iVar7 < 0) ||
                   (cVar6 = RtlIsCloudFilesPlaceholder(local_100 & 0xffffffff,local_100 >> 0x20),
                   cVar6 == '\0')) {
                  iVar12 = -0x3ffffd4e;
                  iVar7 = -0x3ffffd4e;
                  bVar4 = bVar5;
                  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                     (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0 ||
                      ((byte)WPP_GLOBAL_Control[0x29] < 2)))) goto LAB_1c000998e;
                  uVar11 = 0x11;
                  goto LAB_1c000997b;
                }
                uVar8 = (uint)local_90;
                bVar3 = true;
              }
              if (*param_4 == 1) {
LAB_1c0009e35:
                KeEnterCriticalRegion();
                bVar3 = true;
                ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
                bVar4 = true;
                if ((DAT_1c0005195 != 0) || (DAT_1c0005194 != '\0')) {
                  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
                      (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
                    WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                              &WPP_89de4c9ab0183a893b206e6614efcf73_Traceguids,(uint)DAT_1c0005195,
                              DAT_1c0005194);
                  }
                  iVar7 = -0x3ffffe77;
                  goto LAB_1c000998e;
                }
                uVar8 = 0;
                bVar4 = bVar3;
                if (DAT_1c0005197 != '\0') {
                  local_100 = 0;
                  local_f0 = 0;
                  local_e8 = 0;
                  iVar7 = FltGetVolumeFromFileObject();
                  if (-1 < iVar7) {
                    iVar7 = FltGetVolumeInstanceFromName(DAT_1c0005110,local_100,0,&local_e8);
                    if (-1 < iVar7) {
                      iVar7 = FltGetInstanceContext(local_e8);
                      if ((-1 < iVar7) &&
                         (iVar7 = ReferenceVolumeContext(local_f0,'\x01'), iVar7 < 0))
                      goto LAB_1c000998e;
                      FltObjectDereference(local_e8);
                      local_e8 = 0;
                    }
                    FltObjectDereference();
                    local_100 = 0;
                  }
                  uVar14 = 0;
                  if (local_f0 != 0) {
                    local_f8 = 0;
                    DepFSGenerateDependencyList(0,(undefined8 **)0x0,0,&local_f8,'\x01',0);
                    if (local_f8 != 0) {
                      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
                         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                        WPP_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                                  &WPP_89de4c9ab0183a893b206e6614efcf73_Traceguids,
                                  *(undefined4 *)(local_f8 + 4),(char)local_f8);
                      }
                      lVar10 = local_f8;
                      if (*(int *)(local_f8 + 4) != 0) {
                        do {
                          uVar1 = *(ushort *)(lVar10 + 8 + uVar14 * 0x10);
                          if ((uVar1 & 1) == 0) {
                            if ((uVar1 & 2) != 0) {
                              DereferenceDependencyContext
                                        (*(longlong *)(lVar10 + 0x10 + uVar14 * 0x10),'\x01','\0');
                              goto LAB_1c000a003;
                            }
                          }
                          else {
                            lVar2 = *(longlong *)(lVar10 + 0x10 + uVar14 * 0x10);
                            if (lVar2 == local_f0) {
                              uVar8 = (uint)*(ushort *)(lVar10 + 10 + uVar14 * 0x10);
                            }
                            DereferenceVolumeContext(lVar2);
LAB_1c000a003:
                            lVar10 = local_f8;
                          }
                          uVar13 = (int)uVar14 + 1;
                          uVar14 = (ulonglong)uVar13;
                        } while (uVar13 < *(uint *)(lVar10 + 4));
                      }
                      ExFreePoolWithTag(lVar10,0x6c447044);
                    }
                    DereferenceVolumeContext(local_f0);
                  }
                }
                iVar7 = 0;
                uVar13 = DAT_1c00051c0;
                if (DAT_1c00051c0 == 0) {
                  if ((param_3 >> 9 & 1) != 0) {
                    uVar13 = 1;
                    goto LAB_1c000a046;
                  }
                }
                else {
LAB_1c000a046:
                  if (uVar8 < uVar13) {
                    if (param_7 != (int *)0x0) {
                      *param_7 = uVar8 + 1;
                    }
                    goto LAB_1c000998e;
                  }
                }
                iVar7 = -0x3ffffbd9;
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                   (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                  WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                            &WPP_89de4c9ab0183a893b206e6614efcf73_Traceguids,uVar8,
                            (char)DAT_1c00051c0);
                }
                goto LAB_1c000998e;
              }
              if (((param_3 >> 0xb & 1) == 0) && ((uVar8 >> 0xb & 1) != 0)) {
                iVar7 = -0x3fc5ffe6;
                if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                   (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0 ||
                    ((byte)WPP_GLOBAL_Control[0x29] < 2)))) goto LAB_1c000998e;
                uVar11 = 0x12;
LAB_1c0009cad:
                iVar7 = -0x3fc5ffe6;
              }
              else {
                if ((uVar8 >> 0x10 & 1) != 0) {
                  iVar7 = -0x3fc5ffe6;
                  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                     ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c000998e;
                  uVar11 = 0x13;
                  goto LAB_1c0009cad;
                }
                if ((((uVar8 >> 9 & 1) == 0) || (bVar3)) || ((param_3 >> 0xc & 1) != 0))
                goto LAB_1c0009e35;
                local_88[4] = 0;
                local_60 = 0;
                local_5c = 0;
                local_88[0] = 0;
                local_88[1] = 0;
                local_88[2] = 0;
                local_88[3] = 0;
                iVar7 = ZwQueryVolumeInformationFile(param_1,&local_d8,local_88,0x2e);
                if (-1 < iVar7) {
                  iVar7 = (int)local_d8;
                  if (-1 < (int)local_d8) {
                    if (0xf < uStack_d0) {
                      if ((local_88[0] & 0x10000000) == 0) {
                        iVar7 = -0x3fc5ffe6;
                        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c000998e;
                        uVar11 = 0x16;
                        goto LAB_1c0009cad;
                      }
                      goto LAB_1c0009e35;
                    }
                    iVar7 = -0x3fffff3d;
                  }
                }
                if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                   ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c000998e;
                uVar11 = 0x15;
              }
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,
                       &WPP_89de4c9ab0183a893b206e6614efcf73_Traceguids,iVar7);
              goto LAB_1c000998e;
            }
            iVar12 = -0x3fffff46;
            iVar7 = -0x3fffff46;
            bVar4 = bVar5;
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c000998e;
            uVar11 = 0x10;
          }
          else {
            iVar12 = -0x3ffffd6d;
            iVar7 = -0x3ffffd6d;
            bVar4 = bVar5;
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c000998e;
            uVar11 = 0xf;
          }
          goto LAB_1c000997b;
        }
        iVar7 = -0x3fffff3d;
      }
    }
    bVar4 = bVar5;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c000998e;
    uVar11 = 0xe;
    iVar12 = iVar7;
LAB_1c000997b:
    uVar9 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    iVar7 = iVar12;
  }
  else {
    local_104 = 0;
    local_e0 = IoGetDeviceAttachmentBaseRef(*(undefined8 *)(param_2 + 8));
    local_c0 = 0;
    uStack_b8 = 0;
    iVar7 = ObQueryNameString(local_e0,&local_c0,0,&local_104);
    if (((iVar7 + 0x80000000U & 0x80000000) == 0) && (iVar7 != -0x3ffffffc)) {
      bVar4 = bVar5;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) goto LAB_1c000998e;
      uVar11 = 0xb;
      iVar12 = iVar7;
      goto LAB_1c000997b;
    }
    local_c8 = (undefined2 *)ExAllocatePool2(0x100,(ulonglong)local_104 + 0x10,0x70527044);
    if (local_c8 != (undefined2 *)0x0) {
      if (0x10000 < local_104) {
        local_104 = 0;
      }
      *local_c8 = (short)local_104;
      local_c8[1] = (short)local_104;
      *(undefined2 **)(local_c8 + 4) = local_c8 + 8;
      iVar7 = ObQueryNameString(local_e0,local_c8,local_104,&local_104);
      if (-1 < iVar7) goto LAB_1c0009afd;
      bVar4 = bVar5;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) goto LAB_1c000998e;
      uVar11 = 0xd;
      iVar12 = iVar7;
      goto LAB_1c000997b;
    }
    iVar7 = -0x3fffff66;
    bVar4 = bVar5;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c000998e;
    uVar9 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    uVar11 = 0xc;
    iVar7 = -0x3fffff66;
  }
  WPP_SF_D(uVar9,uVar11,&WPP_89de4c9ab0183a893b206e6614efcf73_Traceguids,iVar7);
  bVar4 = bVar5;
LAB_1c000998e:
  if (local_e0 != 0) {
    ObfDereferenceObject(local_e0);
  }
  if (local_c8 != (undefined2 *)0x0) {
    ExFreePoolWithTag(local_c8,0x70527044);
  }
  if (bVar4) {
    ExReleaseResourceLite(&DAT_1c0005118);
    KeLeaveCriticalRegion();
  }
  return iVar7;
}



===== DepFSUnload @ 1c000a100 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 DepFSUnload(uint param_1)

{
  undefined8 uVar1;
  undefined *puVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
            &WPP_6e0896578ce0378c051a248e53d8716f_Traceguids);
  }
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
  if (((param_1 & 1) == 0) && (DAT_1c0005180 != 0)) {
    ExReleaseResourceLite(&DAT_1c0005118);
    KeLeaveCriticalRegion();
    uVar1 = 0xc0000001;
  }
  else {
    if (DAT_1c0005195 == '\0') {
      DAT_1c0005195 = '\x01';
      DepFSNotifyChildren(0);
      uVar1 = DAT_1c0005110;
      if (DAT_1c0005197 != '\0') {
        DAT_1c0005110 = 0;
        DAT_1c0005197 = '\0';
        ExReleaseResourceLite(&DAT_1c0005118);
        KeLeaveCriticalRegion();
        FltUnregisterFilter(uVar1);
        KeEnterCriticalRegion();
        ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
      }
      if (DAT_1c00051cc == '\x01') {
        KeDeregisterBugCheckReasonCallback(&DAT_1c00051d0);
        DAT_1c00051cc = '\0';
      }
      DAT_1c0005196 = 1;
      ExReleaseResourceLite(&DAT_1c0005118);
      KeLeaveCriticalRegion();
      ExDeleteResourceLite(&DAT_1c0005118);
    }
    else {
      ExReleaseResourceLite(&DAT_1c0005118);
      KeLeaveCriticalRegion();
    }
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      puVar2 = WPP_GLOBAL_Control;
      if (WPPTraceSuite == 4) {
        for (; puVar2 != (undefined *)0x0; puVar2 = *(undefined **)(puVar2 + 0x10)) {
          if (*(longlong *)(puVar2 + 0x38) != 0) {
            (*pfnEtwUnregister)();
            *(undefined8 *)(puVar2 + 0x38) = 0;
          }
        }
      }
      else if (WPPTraceSuite == 2) {
        IoWMIRegistrationControl(WPP_GLOBAL_Control,0x80000002);
      }
      WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== FsDepRegisterUnregisterForBugchecks @ 1c000a304 =====

void FsDepRegisterUnregisterForBugchecks(char param_1,char param_2)

{
  undefined7 in_register_00000011;
  
  if (param_2 == '\0') {
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(&DAT_1c0005118,CONCAT71(in_register_00000011,1));
  }
  if (param_1 == '\0') {
    if (DAT_1c00051cc == '\x01') {
      KeDeregisterBugCheckReasonCallback(&DAT_1c00051d0);
      DAT_1c00051cc = '\0';
    }
  }
  else if (DAT_1c00051cc == '\0') {
    DAT_1c00051fc = 0;
    DAT_1c00051cc =
         KeRegisterBugCheckReasonCallback
                   (&DAT_1c00051d0,FsDepHandleBugcheck,1,FsDependsBugcheckIdentifier);
  }
  if (param_2 == '\0') {
    ExReleaseResourceLite(&DAT_1c0005118);
    KeLeaveCriticalRegion();
  }
  return;
}



===== WppInitKm @ 1c000a3d4 =====

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



===== WppLoadTracingSupport @ 1c000a464 =====

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



===== WppTraceCallback @ 1c000a5b0 =====

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



===== DepFSDismountDependenciesOnVolume @ 1c000a838 =====

int DepFSDismountDependenciesOnVolume(undefined8 **param_1)

{
  int *piVar1;
  ushort uVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  ulonglong uVar6;
  uint uVar7;
  ulonglong uVar8;
  longlong local_res8;
  
  uVar6 = 0;
  iVar3 = 0;
  local_res8 = 0;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
  if (((*(uint *)(param_1 + 7) & 1) == 0) &&
     (*(uint *)(param_1 + 7) = *(uint *)(param_1 + 7) | 1, (undefined8 **)param_1[1] != param_1 + 1)
     ) {
    iVar3 = DepFSGenerateDependencyList(0,param_1,0,&local_res8,'\x01',0x100);
    ExReleaseResourceLite(&DAT_1c0005118);
    KeLeaveCriticalRegion();
    if ((iVar3 < 0) &&
       ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
       )) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
               &WPP_b2ba12f3bc77374238ec5953d8d4ec6b_Traceguids,iVar3);
    }
    if (local_res8 == 0) {
      return iVar3;
    }
    uVar7 = 0;
    lVar5 = local_res8;
    if (*(int *)(local_res8 + 4) != 0) {
      do {
        uVar8 = (ulonglong)uVar7;
        uVar2 = *(ushort *)(lVar5 + 8 + uVar8 * 0x10);
        if ((uVar2 & 1) == 0) {
          if ((uVar2 & 2) != 0) {
            uVar4 = DepFSDismountDependency(*(longlong *)(lVar5 + 0x10 + uVar8 * 0x10));
            iVar3 = (int)uVar4;
            goto LAB_1c000a959;
          }
        }
        else {
          DereferenceVolumeContext(*(longlong *)(lVar5 + 0x10 + uVar8 * 0x10));
          *(undefined8 *)(lVar5 + 0x10 + uVar8 * 0x10) = 0;
LAB_1c000a959:
          lVar5 = local_res8;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < *(uint *)(lVar5 + 4));
    }
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
    lVar5 = local_res8;
    if (*(int *)(local_res8 + 4) != 0) {
      do {
        uVar2 = *(ushort *)(uVar6 * 0x10 + 8 + lVar5);
        if ((uVar2 & 2) != 0) {
          lVar5 = lVar5 + uVar6 * 0x10;
          if ((uVar2 & 0x100) != 0) {
            LOCK();
            piVar1 = (int *)(*(longlong *)(lVar5 + 0x10) + 0x60);
            *piVar1 = *piVar1 + -1;
            UNLOCK();
          }
          DereferenceDependencyContext(*(longlong *)(lVar5 + 0x10),'\x01','\0');
          lVar5 = local_res8;
        }
        uVar7 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar7;
      } while (uVar7 < *(uint *)(lVar5 + 4));
    }
    ExFreePoolWithTag(lVar5,0x6c447044);
  }
  ExReleaseResourceLite(&DAT_1c0005118);
  KeLeaveCriticalRegion();
  return iVar3;
}



===== DepFSDismountDependency @ 1c000aa1c =====

undefined8 DepFSDismountDependency(longlong param_1)

{
  longlong *plVar1;
  uint uVar2;
  undefined8 *puVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  uint *puVar7;
  undefined8 *puVar8;
  longlong *plVar9;
  undefined1 uVar10;
  ulonglong in_stack_ffffffffffffff80;
  ulonglong uVar11;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 local_40;
  uint local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  
  local_34 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_20 = 0;
  local_30 = 0;
  uStack_28 = 0;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
  if (*(longlong **)(param_1 + 0x28) != (longlong *)(param_1 + 0x28)) {
    uVar2 = *(uint *)(param_1 + 0x5c);
    if ((uVar2 & 3) == 0) {
      local_38 = uVar2 >> 5 & 1;
      if (DAT_1c0005194 != '\0') {
        local_38 = local_38 | 2;
      }
      local_48 = *(undefined8 *)(param_1 + 0x68);
      plVar1 = (longlong *)(param_1 + 0x18);
      plVar9 = (longlong *)*plVar1;
      local_40 = *(undefined8 *)(param_1 + 0x78);
      if (plVar9 != plVar1) {
        do {
          lVar5 = plVar9[-3];
          plVar9 = (longlong *)*plVar9;
          if ((*(uint *)(param_1 + 0x5c) & 0x20) == 0) {
            if ((*(uint *)(lVar5 + 0x38) & 2) != 0) {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
                 (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                          &WPP_b2ba12f3bc77374238ec5953d8d4ec6b_Traceguids,param_1,(char)lVar5);
              }
              uVar6 = 0xc0000022;
              goto LAB_1c000ac62;
            }
          }
          else {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                        &WPP_b2ba12f3bc77374238ec5953d8d4ec6b_Traceguids,param_1,(char)lVar5);
            }
            *(uint *)(lVar5 + 0x38) = *(uint *)(lVar5 + 0x38) | 0x20;
            if ((*(uint *)(lVar5 + 0x38) & 2) != 0) {
                    /* WARNING: Subroutine does not return */
              KeBugCheck(0x22);
            }
          }
        } while (plVar9 != plVar1);
      }
      puVar8 = (undefined8 *)(param_1 + 0x18);
      if ((*(uint *)(param_1 + 0x5c) & 0x20) == 0) {
        puVar3 = (undefined8 *)*puVar8;
        while (puVar3 != puVar8) {
          uVar11 = puVar3[-3];
          uVar10 = (undefined1)uVar11;
          if ((*(uint *)(uVar11 + 0x38) & 5) == 0) {
            iVar4 = ReferenceVolumeContext(uVar11,'\0');
            if (iVar4 < 0) {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
                 (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_Dqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                           &WPP_b2ba12f3bc77374238ec5953d8d4ec6b_Traceguids,iVar4,(char)param_1,
                           uVar10);
                in_stack_ffffffffffffff80 = uVar11;
              }
            }
            else {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
                 (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                          &WPP_b2ba12f3bc77374238ec5953d8d4ec6b_Traceguids,param_1,uVar10);
              }
              *(uint *)(uVar11 + 0x38) = *(uint *)(uVar11 + 0x38) | 4;
              ExReleaseResourceLite(&DAT_1c0005118);
              KeLeaveCriticalRegion();
              DepFSSendDismountRequest(uVar11);
              DereferenceVolumeContext(uVar11);
              KeEnterCriticalRegion();
              ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
            }
            puVar3 = (undefined8 *)*puVar8;
          }
          else {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
               (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              WPP_SF_qq(*(undefined **)((longlong)WPP_GLOBAL_Control + 0x18),0xe,
                        &WPP_b2ba12f3bc77374238ec5953d8d4ec6b_Traceguids,param_1,uVar10);
            }
            puVar3 = (undefined8 *)*puVar3;
          }
        }
      }
      puVar7 = (uint *)(param_1 + 0x5c);
      if ((*(longlong **)(param_1 + 0x28) != (longlong *)(param_1 + 0x28)) && ((*puVar7 & 3) == 0))
      {
        KeInitializeEvent(&local_30,0,0);
        lVar5 = IoBuildDeviceIoControlRequest
                          (0x2d9194,*(undefined8 *)(param_1 + 0x80),&local_48,0x18,0,
                           in_stack_ffffffffffffff80 & 0xffffffff00000000,0,&local_30,&local_58);
        if (lVar5 != 0) {
          *puVar7 = *puVar7 | 1;
          *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
          ExReleaseResourceLite(&DAT_1c0005118);
          KeLeaveCriticalRegion();
          iVar4 = IofCallDriver(*(undefined8 *)(param_1 + 0x80));
          if (iVar4 == 0x103) {
            KeWaitForSingleObject(&local_30,0,0,0,0);
            iVar4 = (int)local_58;
          }
          if ((((iVar4 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                      &WPP_b2ba12f3bc77374238ec5953d8d4ec6b_Traceguids,iVar4,(char)param_1);
          }
          DereferenceDependencyContext(param_1,'\0','\0');
          return 0;
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                   &WPP_b2ba12f3bc77374238ec5953d8d4ec6b_Traceguids,param_1);
        }
        *(uint *)(param_1 + 0x5c) = *(uint *)(param_1 + 0x5c) | 2;
        uVar6 = 0xc000009a;
LAB_1c000ac62:
        ExReleaseResourceLite(&DAT_1c0005118);
        KeLeaveCriticalRegion();
        return uVar6;
      }
    }
  }
  ExReleaseResourceLite(&DAT_1c0005118);
  KeLeaveCriticalRegion();
  return 0;
}



===== DepFSDismountDependencyList @ 1c000aee8 =====

uint DepFSDismountDependencyList(longlong param_1,longlong param_2,char param_3)

{
  int *piVar1;
  ushort uVar2;
  longlong lVar3;
  bool bVar4;
  uint uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  uint uVar8;
  
  uVar5 = 0;
  bVar4 = true;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
             &WPP_b2ba12f3bc77374238ec5953d8d4ec6b_Traceguids,param_1);
  }
  uVar7 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    do {
      uVar2 = *(ushort *)(param_1 + 8 + uVar7 * 0x10);
      if ((uVar2 & 1) == 0) {
        if ((((uVar2 & 2) != 0) &&
            (lVar3 = *(longlong *)(param_1 + 0x10 + uVar7 * 0x10), lVar3 != param_2)) &&
           (lVar3 != 0)) {
          if (bVar4 != false) {
            ExReleaseResourceLite(&DAT_1c0005118);
            KeLeaveCriticalRegion();
            bVar4 = false;
          }
          uVar6 = DepFSDismountDependency(*(longlong *)(param_1 + 0x10 + uVar7 * 0x10));
          uVar5 = (uint)uVar6;
          if ((int)uVar5 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                       &WPP_b2ba12f3bc77374238ec5953d8d4ec6b_Traceguids,uVar5);
            }
            if (param_3 == '\0') break;
          }
        }
      }
      else {
        lVar3 = *(longlong *)(param_1 + 0x10 + uVar7 * 0x10);
        if ((uVar2 & 0x10) != 0) {
          uVar5 = 0xc0000022;
          break;
        }
        if (!bVar4) {
          KeEnterCriticalRegion();
          ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
        }
        if ((*(uint *)(lVar3 + 0x38) & 0x25) == 0) {
          *(uint *)(lVar3 + 0x38) = *(uint *)(lVar3 + 0x38) | 4;
          ExReleaseResourceLite();
          KeLeaveCriticalRegion();
          uVar5 = DepFSSendDismountRequest(lVar3);
          if ((int)uVar5 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                       &WPP_b2ba12f3bc77374238ec5953d8d4ec6b_Traceguids,uVar5);
            }
            if (param_3 == '\0') goto LAB_1c000b0ef;
          }
        }
        else {
          ExReleaseResourceLite(&DAT_1c0005118);
          KeLeaveCriticalRegion();
        }
        bVar4 = false;
        DereferenceVolumeContext(lVar3);
        *(undefined8 *)(param_1 + 0x10 + uVar7 * 0x10) = 0;
      }
      uVar8 = (int)uVar7 + 1;
      uVar7 = (ulonglong)uVar8;
    } while (uVar8 < *(uint *)(param_1 + 4));
    if (bVar4 == false) {
LAB_1c000b0ef:
      bVar4 = true;
      KeEnterCriticalRegion();
      ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
    }
  }
  uVar8 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    do {
      uVar7 = (ulonglong)uVar8;
      uVar2 = *(ushort *)(param_1 + 8 + uVar7 * 0x10);
      if (((uVar2 & 2) != 0) && (lVar3 = *(longlong *)(param_1 + 0x10 + uVar7 * 0x10), lVar3 != 0))
      {
        if ((uVar2 >> 8 & 1) != 0) {
          LOCK();
          piVar1 = (int *)(lVar3 + 0x60);
          *piVar1 = *piVar1 + -1;
          UNLOCK();
        }
        DereferenceDependencyContext(*(longlong *)(param_1 + 0x10 + uVar7 * 0x10),bVar4,'\0');
        *(undefined8 *)(param_1 + 0x10 + uVar7 * 0x10) = 0;
      }
      if (((*(byte *)(param_1 + 8 + uVar7 * 0x10) & 1) != 0) &&
         (lVar3 = *(longlong *)(param_1 + 0x10 + uVar7 * 0x10), lVar3 != 0)) {
        DereferenceVolumeContext(lVar3);
        *(undefined8 *)(param_1 + 0x10 + uVar7 * 0x10) = 0;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < *(uint *)(param_1 + 4));
    if (bVar4 == false) goto LAB_1c000b19c;
  }
  ExReleaseResourceLite(&DAT_1c0005118);
  KeLeaveCriticalRegion();
LAB_1c000b19c:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
              &WPP_b2ba12f3bc77374238ec5953d8d4ec6b_Traceguids,param_1,(char)uVar5);
  }
  return uVar5;
}



===== DepFSSendDismountRequest @ 1c000b200 =====

uint DepFSSendDismountRequest(longlong param_1)

{
  uint uVar1;
  int iVar2;
  undefined2 uVar3;
  undefined4 local_res8 [2];
  undefined8 local_res10;
  longlong local_res18 [2];
  
  local_res8[0] = 0;
  local_res18[0] = 0;
  local_res10 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_b2ba12f3bc77374238ec5953d8d4ec6b_Traceguids,param_1);
  }
  uVar1 = *(uint *)(param_1 + 0x54);
  if ((uVar1 < 0x25) && ((0x100000018cU >> ((ulonglong)uVar1 & 0x3f) & 1) != 0)) {
    if ((*(uint *)(param_1 + 0x38) & 0x20) == 0) {
      uVar1 = FltOpenVolume(*(undefined8 *)(param_1 + 0x40),local_res18,&local_res10);
      if ((int)uVar1 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar3 = 0x14;
LAB_1c000b301:
          param_1 = *(longlong *)(param_1 + 0x48);
          goto LAB_1c000b403;
        }
      }
      else {
        iVar2 = FltFsControlFile(*(undefined8 *)(param_1 + 0x40),local_res10,0x90018,0,0,0,0,
                                 local_res8);
        if ((((iVar2 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                    &WPP_b2ba12f3bc77374238ec5953d8d4ec6b_Traceguids,*(undefined8 *)(param_1 + 0x48)
                    ,(char)iVar2);
        }
        uVar1 = FltFsControlFile(*(undefined8 *)(param_1 + 0x40),local_res10,0x90020,0,0,0,0,
                                 local_res8);
        if (-1 < (int)uVar1) goto LAB_1c000b411;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar3 = 0x16;
          goto LAB_1c000b301;
        }
      }
    }
    else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar3 = 0x13;
      goto LAB_1c000b403;
    }
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar3 = 0x12;
LAB_1c000b403:
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
              &WPP_b2ba12f3bc77374238ec5953d8d4ec6b_Traceguids,param_1,(char)uVar1);
  }
  uVar1 = 0;
LAB_1c000b411:
  if (local_res18[0] != 0) {
    ObfDereferenceObject(local_res10);
    local_res10 = 0;
    FltClose(local_res18[0]);
  }
  return uVar1;
}



===== DependentFSDismountForSystemEvent @ 1c000b460 =====

uint DependentFSDismountForSystemEvent(uint param_1)

{
  bool bVar1;
  uint uVar2;
  longlong local_res10;
  
                    /* 0xb460  4  DependentFSDismountForSystemEvent */
  uVar2 = 0;
  local_res10 = 0;
  if ((DAT_1c0005194 != '\0') || (DAT_1c0005196 != '\0')) {
    return 0;
  }
  KeEnterCriticalRegion();
  bVar1 = true;
  ExAcquireResourceExclusiveLite(&DAT_1c0005118);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
             &WPP_b2ba12f3bc77374238ec5953d8d4ec6b_Traceguids,param_1);
  }
  if (((DAT_1c0005194 == '\0') && (DAT_1c0005196 == '\0')) && (DAT_1c0005180 != 0)) {
    uVar2 = DepFSGenerateDependencyList(0,(undefined8 **)0x0,param_1,&local_res10,'\x01',0x100);
    if ((((int)uVar2 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
               &WPP_b2ba12f3bc77374238ec5953d8d4ec6b_Traceguids,uVar2);
    }
    if (local_res10 != 0) {
      uVar2 = DepFSDismountDependencyList(local_res10,0,'\x01');
      bVar1 = false;
      goto LAB_1c000b577;
    }
  }
  else {
LAB_1c000b577:
    if (local_res10 != 0) {
      ExFreePoolWithTag(local_res10,0x6c447044);
    }
    if (!bVar1) goto LAB_1c000b5b6;
  }
  ExReleaseResourceLite(&DAT_1c0005118);
  KeLeaveCriticalRegion();
LAB_1c000b5b6:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
              &WPP_b2ba12f3bc77374238ec5953d8d4ec6b_Traceguids,param_1,(char)uVar2);
  }
  return uVar2;
}



===== DependentFSDismountForUnsurface @ 1c000b610 =====

uint DependentFSDismountForUnsurface
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  undefined8 *puVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  char cVar5;
  undefined8 *in_stack_ffffffffffffffa8;
  ulonglong uVar6;
  uint in_stack_ffffffffffffffb0;
  undefined8 local_38;
  longlong local_30;
  longlong *local_28;
  undefined *puStack_20;
  
                    /* 0xb610  5  DependentFSDismountForUnsurface */
  local_30 = 0;
  uVar2 = 0;
  local_38 = 0;
  puVar4 = (undefined8 *)0x0;
  local_28 = (longlong *)0x0;
  puStack_20 = (undefined *)0x0;
  if ((DAT_1c0005194 != '\0') || (DAT_1c0005196 != '\0')) {
    return 0;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    in_stack_ffffffffffffffa8 = param_4;
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
              &WPP_b2ba12f3bc77374238ec5953d8d4ec6b_Traceguids,param_1,(char)param_4);
  }
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
  cVar5 = '\x01';
  if (((DAT_1c0005194 == '\0') && (DAT_1c0005196 == '\0')) &&
     ((DAT_1c0005180 != 0 &&
      (puVar3 = DAT_1c00051b0, (undefined8 **)DAT_1c00051b0 != &DAT_1c00051b0)))) {
    do {
      puVar1 = (undefined8 *)*puVar3;
      puVar4 = puVar3 + -5;
      if (((puVar1 != puVar3) && (puVar4 == param_4)) &&
         ((*(uint *)((longlong)puVar3 + 0x34) & 3) == 0)) break;
      puVar4 = (undefined8 *)0x0;
      puVar3 = puVar1;
    } while ((undefined8 **)puVar1 != &DAT_1c00051b0);
    if (puVar4 == (undefined8 *)0x0) goto LAB_1c000b8e6;
    *(int *)(puVar4 + 7) = *(int *)(puVar4 + 7) + 1;
    LOCK();
    *(int *)(puVar4 + 0xc) = *(int *)(puVar4 + 0xc) + 1;
    UNLOCK();
    local_28 = puVar4 + 0x19;
    puStack_20 = &DAT_1c0005200;
    in_stack_ffffffffffffffb0 = in_stack_ffffffffffffffb0 & 0xffffff00;
    uVar6 = (ulonglong)in_stack_ffffffffffffffa8 & 0xffffffffffffff00;
    uVar2 = KeWaitForMultipleObjects(2);
    if (1 < uVar2) {
      ExReleaseResourceLite(&DAT_1c0005118);
      KeLeaveCriticalRegion();
      local_38 = 0xffffffff94b62e00;
      cVar5 = '\0';
      KeWaitForMultipleObjects
                (2,&local_28,1,0,uVar6 & 0xffffffffffffff00,in_stack_ffffffffffffffb0 & 0xffffff00,
                 &local_38,0);
      if (((DAT_1c0005194 == '\0') && (DAT_1c0005196 == '\0')) && (DAT_1c0005180 != 0)) {
        KeEnterCriticalRegion();
        ExAcquireResourceExclusiveLite(&DAT_1c0005118);
        cVar5 = '\x01';
        if (((DAT_1c0005194 == '\0') && (DAT_1c0005196 == '\0')) &&
           ((DAT_1c0005180 != 0 &&
            (((undefined8 *)puVar4[5] != puVar4 + 5 &&
             ((*(uint *)((longlong)puVar4 + 0x5c) & 3) == 0)))))) goto LAB_1c000b86e;
      }
      goto LAB_1c000b8e6;
    }
LAB_1c000b86e:
    uVar2 = DepFSGenerateDependencyList
                      ((longlong)puVar4,(undefined8 **)0x0,0,&local_30,'\x01',0x100);
    if (((int)uVar2 < 0) &&
       ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
       )) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
               &WPP_b2ba12f3bc77374238ec5953d8d4ec6b_Traceguids,uVar2);
    }
    cVar5 = '\x01';
    if (local_30 != 0) {
      uVar2 = DepFSDismountDependencyList(local_30,(longlong)puVar4,'\0');
      cVar5 = '\0';
      goto LAB_1c000b8e6;
    }
  }
  else {
LAB_1c000b8e6:
    if (local_30 != 0) {
      ExFreePoolWithTag(local_30,0x6c447044);
    }
    if (puVar4 == (undefined8 *)0x0) goto LAB_1c000b913;
  }
  DereferenceDependencyContext((longlong)puVar4,cVar5,'\0');
LAB_1c000b913:
  if (cVar5 != '\0') {
    ExReleaseResourceLite(&DAT_1c0005118);
    KeLeaveCriticalRegion();
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
               &WPP_b2ba12f3bc77374238ec5953d8d4ec6b_Traceguids,param_1,(char)param_4,(char)uVar2);
  }
  return uVar2;
}



===== DepFSDecrementActiveMountCount @ 1c000b9a4 =====

void DepFSDecrementActiveMountCount(longlong param_1)

{
  int *piVar1;
  char cVar2;
  wchar_t local_18;
  wchar_t local_16;
  undefined4 local_14;
  undefined8 local_10;
  
  ExAcquirePushLockExclusiveEx(param_1 + 0xb8,0);
  if (*(int *)(param_1 + 0xc0) < 1) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
              &WPP_bc64936b77293105c4440102cf4189d6_Traceguids);
    }
    KeSetEvent(&DAT_1c0005200,0,0);
  }
  local_18 = *(wchar_t *)(param_1 + 0x8a);
  local_14 = 0;
  local_10 = *(undefined8 *)(param_1 + 0x90);
  local_16 = local_18;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    cVar2 = (char)*(undefined4 *)(param_1 + 0xc0);
    WPP_SF_qddZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
                &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,param_1,cVar2,cVar2 + -1,&local_18)
    ;
  }
  piVar1 = (int *)(param_1 + 0xc0);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    KeSetEvent(param_1 + 200,0,0);
  }
  ExReleasePushLockExclusiveEx(param_1 + 0xb8,0);
  return;
}



===== DepFSDecrementActiveMountCountForVolume @ 1c000bae0 =====

void DepFSDecrementActiveMountCountForVolume
               (undefined8 param_1,ulonglong param_2,undefined8 param_3,ulonglong param_4)

{
  undefined8 uVar1;
  
  uVar1 = DepFSForEachDependency(param_3,param_2,param_3,param_4);
  FltFreeGenericWorkItem(param_1);
  ObfDereferenceObject(param_3);
  if ((int)uVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
              &WPP_bc64936b77293105c4440102cf4189d6_Traceguids);
    }
    KeSetEvent(&DAT_1c0005200,0,0);
  }
  return;
}



===== DepFSForEachDependency @ 1c000bb88 =====

undefined8
DepFSForEachDependency(undefined8 param_1,ulonglong param_2,undefined8 param_3,ulonglong param_4)

{
  short *psVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong local_res10;
  undefined4 local_res18 [2];
  
  local_res18[0] = 3;
  local_res10 = param_2 & 0xffffffff00000000;
  lVar3 = 0;
  uVar5 = 0x48;
  while( true ) {
    if (lVar3 != 0) {
      uVar4 = *(ulonglong *)(lVar3 + 8);
      ExFreePoolWithTag(lVar3,0x72517044);
      uVar5 = uVar4 & 0xffffffff;
      if (uVar4 != uVar5) {
        return 0xc000009a;
      }
    }
    uVar4 = uVar5;
    lVar3 = ExAllocatePool2(0x100,uVar5,0x72517044);
    if (lVar3 == 0) break;
    uVar2 = DepFSSendIoctl(param_1,uVar4,local_res18,param_4,lVar3,(int)uVar5,
                           (undefined4 *)&local_res10);
    param_4 = (ulonglong)uVar2;
    if (uVar2 != 0x80000005) {
      if ((int)uVar2 < 0) {
        if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
                   &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,uVar2);
        }
      }
      else if ((0x37 < (uint)local_res10) && (uVar2 = 0, *(int *)(lVar3 + 4) != 0)) {
        do {
          psVar1 = *(short **)(lVar3 + ((ulonglong)uVar2 + 1) * 0x30);
          if ((psVar1 != (short *)0x0) && (*psVar1 == 0x3030)) {
            DepFSDecrementActiveMountCount((longlong)psVar1);
            DependentFSDereferenceDependency(psVar1);
          }
          uVar2 = uVar2 + 1;
        } while (uVar2 < *(uint *)(lVar3 + 4));
      }
      ExFreePoolWithTag(lVar3,0x72517044);
      return 0;
    }
  }
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return 0xc000009a;
  }
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
    return 0xc000009a;
  }
  if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
    return 0xc000009a;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
           &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,(int)uVar5);
  return 0xc000009a;
}



===== DepFSHandleQueryDependentVolume @ 1c000bd14 =====

undefined4 DepFSHandleQueryDependentVolume(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  int iVar11;
  longlong lVar12;
  ulonglong uVar13;
  longlong *plVar14;
  longlong *plVar15;
  undefined2 uVar16;
  int iVar17;
  longlong *plVar18;
  ulonglong uVar19;
  int *piVar20;
  void *pvVar21;
  uint uVar22;
  uint uVar23;
  uint local_res18;
  uint local_88;
  undefined4 local_84;
  longlong local_80;
  undefined8 *local_78;
  longlong lStack_70;
  undefined8 *local_68;
  longlong lStack_60;
  ulonglong local_58;
  longlong local_50;
  
  local_84 = 4;
  local_80 = 0;
  local_res18 = 0;
  uVar23 = 0;
  local_88 = 0x4c;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
              &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,param_1,
              (char)*(undefined8 *)(param_2 + 0x20));
  }
  if (*(uint *)(*(longlong *)(param_1 + 0x10) + 0x20) < 8) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
              &WPP_bc64936b77293105c4440102cf4189d6_Traceguids);
    }
    *(undefined4 *)(param_1 + 0x18) = 0xc000000d;
    return 4;
  }
  piVar20 = *(int **)(*(longlong *)(param_1 + 0x10) + 0x30);
  iVar4 = *piVar20;
  uVar22 = piVar20[1];
  if (((1 < iVar4 - 1U) || ((uVar22 & 0xfffffffc) != 0)) ||
     ((uVar22 == 0 || (((byte)uVar22 & 3) == 3)))) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
                &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,iVar4,(byte)uVar22);
    }
    *(undefined4 *)(param_1 + 0x18) = 0xc0000148;
    return 4;
  }
  iVar11 = FltGetInstanceContext(*(undefined8 *)(param_2 + 0x18),&local_80);
  if (iVar11 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c000be78;
    uVar16 = 0x36;
  }
  else {
    iVar11 = ReferenceVolumeContext(local_80,'\x01');
    if (-1 < iVar11) {
      KeEnterCriticalRegion();
      ExAcquireResourceExclusiveLite(&DAT_1c0005118);
      if ((uVar22 & 2) == 0) {
        plVar18 = (longlong *)(local_80 + 0x18);
        plVar15 = (longlong *)*plVar18;
        if (plVar15 != plVar18) {
          uVar22 = 0;
          do {
            lVar12 = plVar15[-2];
            plVar15 = (longlong *)*plVar15;
            if (iVar4 == 1) {
              local_88 = local_88 + 0x20;
            }
            else {
              iVar11 = local_88 + 0x44 +
                       (uint)*(ushort *)(local_80 + 0x80) + (uint)*(ushort *)(lVar12 + 0x8a);
              if (*(longlong *)(lVar12 + 0x90) != 0) {
                iVar11 = iVar11 + 2 + (uint)*(ushort *)(lVar12 + 0x8a);
              }
              local_88 = iVar11 + (uint)*(ushort *)(lVar12 + 0x98);
            }
            uVar23 = uVar23 + 1;
          } while (plVar15 != plVar18);
          if (uVar23 != 0) {
            uVar5 = *(uint *)(*(longlong *)(param_1 + 0x10) + 0x18);
            if (uVar5 < 8) {
              *(undefined4 *)(param_1 + 0x18) = 0xc0000023;
              *(undefined8 *)(param_1 + 0x20) = 0;
              goto LAB_1c000c720;
            }
            piVar20 = *(int **)(*(longlong *)(param_1 + 0x10) + 0x30);
            if (local_88 <= uVar5) {
              memset(piVar20,0,(ulonglong)local_88);
              *piVar20 = iVar4;
              if (iVar4 == 1) {
                lVar12 = (ulonglong)uVar23 << 5;
              }
              else {
                lVar12 = (ulonglong)uVar23 * 0x44;
              }
              plVar18 = *(longlong **)(local_80 + 0x18);
              if (plVar18 != (longlong *)(local_80 + 0x18)) {
                pvVar21 = (void *)((longlong)piVar20 + lVar12 + 8);
                do {
                  lVar12 = plVar18[-2];
                  plVar18 = (longlong *)*plVar18;
                  uVar13 = (ulonglong)local_res18;
                  uVar19 = (ulonglong)local_res18;
                  if (iVar4 == 1) {
                    piVar20[uVar19 * 8 + 2] = 0x20;
                    piVar20[uVar19 * 8 + 3] = *(int *)(lVar12 + 0x3c);
                    uVar10 = *(undefined8 *)(lVar12 + 0x4c);
                    *(undefined8 *)(piVar20 + uVar19 * 8 + 5) = *(undefined8 *)(lVar12 + 0x44);
                    *(undefined8 *)(piVar20 + uVar19 * 8 + 5 + 2) = uVar10;
                    piVar20[uVar19 * 8 + 9] = *(int *)(lVar12 + 0x54);
                    piVar20[uVar19 * 8 + 4] = *(int *)(lVar12 + 0x40);
                  }
                  else {
                    piVar20[uVar13 * 0x11 + 2] = 0x44;
                    piVar20[uVar13 * 0x11 + 3] = *(int *)(lVar12 + 0x3c);
                    uVar10 = *(undefined8 *)(lVar12 + 0x4c);
                    *(undefined8 *)(piVar20 + uVar13 * 0x11 + 5) = *(undefined8 *)(lVar12 + 0x44);
                    *(undefined8 *)(piVar20 + uVar13 * 0x11 + 5 + 2) = uVar10;
                    piVar20[uVar13 * 0x11 + 9] = *(int *)(lVar12 + 0x54);
                    piVar20[uVar13 * 0x11 + 4] = *(int *)(lVar12 + 0x40);
                    piVar20[uVar13 * 0x11 + 10] = *(int *)(lVar12 + 0x58);
                    iVar11 = (int)piVar20;
                    if (*(void **)(lVar12 + 0x90) != (void *)0x0) {
                      memcpy(pvVar21,*(void **)(lVar12 + 0x90),(ulonglong)*(ushort *)(lVar12 + 0x8a)
                            );
                      iVar17 = (int)pvVar21 - iVar11;
                      piVar20[uVar13 * 0x11 + 0xb] = iVar17;
                      piVar20[uVar13 * 0x11 + 0xc] =
                           ((uint)*(ushort *)(lVar12 + 0x8a) - (uint)*(ushort *)(lVar12 + 0x88)) +
                           -2;
                      pvVar21 = (void *)((longlong)pvVar21 + (ulonglong)*(ushort *)(lVar12 + 0x8a));
                      piVar20[uVar13 * 0x11 + 0xf] =
                           ((uint)*(ushort *)(lVar12 + 0x8a) - (uint)*(ushort *)(lVar12 + 0x88)) +
                           iVar17;
                      piVar20[uVar13 * 0x11 + 0x10] = (uint)*(ushort *)(lVar12 + 0x88);
                    }
                    memcpy(pvVar21,*(void **)(local_80 + 0x88),
                           (ulonglong)*(ushort *)(local_80 + 0x80));
                    piVar20[uVar13 * 0x11 + 0xd] = (int)pvVar21 - iVar11;
                    piVar20[uVar13 * 0x11 + 0xe] = (uint)*(ushort *)(local_80 + 0x80);
                    pvVar21 = (void *)((longlong)pvVar21 + (ulonglong)*(ushort *)(local_80 + 0x80));
                    if (*(ushort *)(lVar12 + 0x98) != 0) {
                      memcpy(pvVar21,*(void **)(lVar12 + 0xa0),(ulonglong)*(ushort *)(lVar12 + 0x98)
                            );
                      piVar20[uVar13 * 0x11 + 0x11] = (int)pvVar21 - iVar11;
                      piVar20[uVar13 * 0x11 + 0x12] = (uint)*(ushort *)(lVar12 + 0x98);
                      pvVar21 = (void *)((longlong)pvVar21 + (ulonglong)*(ushort *)(lVar12 + 0x98));
                    }
                  }
                  local_res18 = local_res18 + 1;
                } while (plVar18 != (longlong *)(local_80 + 0x18));
                goto LAB_1c000c701;
              }
              goto LAB_1c000c709;
            }
            goto LAB_1c000c510;
          }
        }
      }
      else {
        plVar18 = *(longlong **)(local_80 + 8);
        if (plVar18 != (longlong *)(local_80 + 8)) {
          do {
            plVar15 = (longlong *)*plVar18;
            if (((*(int *)(local_80 + 0x50) == 0xd) &&
                (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 8), lVar12 != 0)) &&
               ((lVar6 = *(longlong *)(lVar12 + 0x60), lVar6 != 0 &&
                ((lVar7 = plVar18[0xc], lVar7 != 0 &&
                 (lVar8 = *(longlong *)(lVar7 + 0x60), lVar8 != 0)))))) {
              uVar3 = *(ushort *)(lVar12 + 0x58);
              local_78 = (undefined8 *)(ulonglong)*(uint *)(lVar12 + 0x58);
              uVar22 = *(uint *)(lVar7 + 0x58);
              local_68 = (undefined8 *)(ulonglong)uVar22;
              lStack_70 = lVar6;
              lStack_60 = lVar8;
              if (uVar3 <= *(ushort *)(lVar7 + 0x58)) {
                local_68 = (undefined8 *)(ulonglong)CONCAT22((short)(uVar22 >> 0x10),uVar3);
                iVar11 = RtlCompareUnicodeString
                                   (&local_68,&local_78,CONCAT71((uint7)(byte)(uVar3 >> 8),1));
                if (iVar11 == 0) goto LAB_1c000bfc0;
              }
            }
            else {
LAB_1c000bfc0:
              if (iVar4 == 1) {
                local_88 = local_88 + 0x20;
                uVar23 = uVar23 + 1;
              }
              else {
                uVar3 = *(ushort *)(plVar18 + 0x12);
                plVar1 = plVar18 + 2;
                plVar14 = (longlong *)*plVar1;
                uVar22 = local_88 + 2 + (uint)uVar3;
                if (plVar14 == plVar1) {
                  uVar23 = uVar23 + 1;
                  local_88 = uVar22 + 0x44;
                  if (plVar18[0x11] != 0) {
                    local_88 = uVar22 + 0x46 +
                               (uint)*(ushort *)((longlong)plVar18 + 0x82) + (uint)uVar3;
                  }
                }
                else {
                  local_88 = uVar22;
                  do {
                    plVar2 = plVar14 + -3;
                    iVar11 = local_88 + 0x44;
                    plVar14 = (longlong *)*plVar14;
                    if (plVar18[0x11] != 0) {
                      iVar11 = local_88 + 0x46 + (uint)*(ushort *)((longlong)plVar18 + 0x82);
                    }
                    uVar23 = uVar23 + 1;
                    local_88 = iVar11 + (uint)*(ushort *)(*plVar2 + 0x80) + (uint)uVar3;
                  } while (plVar14 != plVar1);
                }
              }
            }
            plVar18 = plVar15;
          } while (plVar15 != (longlong *)(local_80 + 8));
          if (uVar23 != 0) {
            uVar22 = *(uint *)(*(longlong *)(param_1 + 0x10) + 0x18);
            if (uVar22 < 8) {
              *(undefined4 *)(param_1 + 0x18) = 0xc0000023;
              *(undefined8 *)(param_1 + 0x20) = 0;
              goto LAB_1c000c720;
            }
            piVar20 = *(int **)(*(longlong *)(param_1 + 0x10) + 0x30);
            if (local_88 <= uVar22) {
              memset(piVar20,0,(ulonglong)local_88);
              *piVar20 = iVar4;
              plVar18 = *(longlong **)(local_80 + 8);
              if (iVar4 == 1) {
                lVar12 = (ulonglong)uVar23 << 5;
              }
              else {
                lVar12 = (ulonglong)uVar23 * 0x44;
              }
              uVar22 = local_res18;
              if (plVar18 != (longlong *)(local_80 + 8)) {
                pvVar21 = (void *)((longlong)piVar20 + lVar12 + 8);
                uVar23 = local_res18;
                do {
                  local_68 = (undefined8 *)*plVar18;
                  if ((((*(int *)(local_80 + 0x50) == 0xd) &&
                       (lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 8), lVar12 != 0)) &&
                      (lVar6 = *(longlong *)(lVar12 + 0x60), lVar6 != 0)) &&
                     ((lVar7 = plVar18[0xc], lVar7 != 0 &&
                      (lVar8 = *(longlong *)(lVar7 + 0x60), lVar8 != 0)))) {
                    uVar3 = *(ushort *)(lVar12 + 0x58);
                    local_58 = (ulonglong)*(uint *)(lVar12 + 0x58);
                    uVar22 = *(uint *)(lVar7 + 0x58);
                    local_78 = (undefined8 *)(ulonglong)uVar22;
                    lStack_70 = lVar8;
                    local_50 = lVar6;
                    if (uVar3 <= *(ushort *)(lVar7 + 0x58)) {
                      local_78 = (undefined8 *)(ulonglong)CONCAT22((short)(uVar22 >> 0x10),uVar3);
                      iVar11 = RtlCompareUnicodeString
                                         (&local_78,&local_58,CONCAT71((uint7)(byte)(uVar3 >> 8),1))
                      ;
                      if (iVar11 == 0) goto LAB_1c000c17e;
                    }
                  }
                  else {
LAB_1c000c17e:
                    if (iVar4 == 1) {
                      uVar13 = (ulonglong)local_res18;
                      local_res18 = local_res18 + 1;
                      piVar20[uVar13 * 8 + 2] = 0x20;
                      uVar10 = *(undefined8 *)((longlong)plVar18 + 0x44);
                      *(undefined8 *)(piVar20 + uVar13 * 8 + 5) =
                           *(undefined8 *)((longlong)plVar18 + 0x3c);
                      *(undefined8 *)(piVar20 + uVar13 * 8 + 5 + 2) = uVar10;
                      piVar20[uVar13 * 8 + 9] = *(int *)((longlong)plVar18 + 0x4c);
                      piVar20[uVar13 * 8 + 4] = *(int *)(plVar18 + 7);
                      piVar20[uVar13 * 8 + 3] = *(int *)((longlong)plVar18 + 0x34);
                    }
                    else {
                      puVar9 = (undefined8 *)plVar18[2];
                      iVar11 = (int)piVar20;
                      if (puVar9 == plVar18 + 2) {
                        uVar13 = (ulonglong)uVar23;
                        piVar20[uVar13 * 0x11 + 2] = 0x44;
                        piVar20[uVar13 * 0x11 + 3] = *(int *)((longlong)plVar18 + 0x34);
                        uVar10 = *(undefined8 *)((longlong)plVar18 + 0x44);
                        *(undefined8 *)(piVar20 + uVar13 * 0x11 + 5) =
                             *(undefined8 *)((longlong)plVar18 + 0x3c);
                        *(undefined8 *)(piVar20 + uVar13 * 0x11 + 5 + 2) = uVar10;
                        piVar20[uVar13 * 0x11 + 9] = *(int *)((longlong)plVar18 + 0x4c);
                        piVar20[uVar13 * 0x11 + 4] = *(int *)(plVar18 + 7);
                        piVar20[uVar13 * 0x11 + 10] = *(int *)(plVar18 + 10);
                        if ((void *)plVar18[0x11] != (void *)0x0) {
                          memcpy(pvVar21,(void *)plVar18[0x11],
                                 (ulonglong)*(ushort *)((longlong)plVar18 + 0x82));
                          if ((ulonglong)*(ushort *)(plVar18 + 0x10) + 2 <
                              (ulonglong)*(ushort *)((longlong)plVar18 + 0x82)) {
                            piVar20[uVar13 * 0x11 + 0xb] = (int)pvVar21 - iVar11;
                            piVar20[uVar13 * 0x11 + 0xc] =
                                 ((uint)*(ushort *)((longlong)plVar18 + 0x82) -
                                 (uint)*(ushort *)(plVar18 + 0x10)) + -2;
                          }
                          pvVar21 = (void *)((longlong)pvVar21 +
                                            (ulonglong)*(ushort *)((longlong)plVar18 + 0x82));
                          piVar20[uVar13 * 0x11 + 0xf] =
                               ((uint)*(ushort *)((longlong)plVar18 + 0x82) -
                               (uint)*(ushort *)(plVar18 + 0x10)) + piVar20[uVar13 * 0x11 + 0xb];
                          piVar20[uVar13 * 0x11 + 0x10] = (uint)*(ushort *)(plVar18 + 0x10);
                        }
                        if (*(ushort *)(plVar18 + 0x12) != 0) {
                          memcpy(pvVar21,(void *)plVar18[0x13],
                                 (ulonglong)*(ushort *)(plVar18 + 0x12));
                          piVar20[uVar13 * 0x11 + 0x11] = (int)pvVar21 - iVar11;
                          piVar20[uVar13 * 0x11 + 0x12] = (uint)*(ushort *)(plVar18 + 0x12);
                          pvVar21 = (void *)((longlong)pvVar21 +
                                            (ulonglong)*(ushort *)(plVar18 + 0x12));
                        }
                        uVar23 = uVar23 + 1;
                        local_res18 = uVar23;
                        goto LAB_1c000c45a;
                      }
                      local_78 = puVar9;
                      do {
                        lVar12 = local_78[-3];
                        local_78 = (undefined8 *)*local_78;
                        uVar13 = (ulonglong)local_res18;
                        piVar20[uVar13 * 0x11 + 2] = 0x44;
                        piVar20[uVar13 * 0x11 + 3] = *(int *)((longlong)plVar18 + 0x34);
                        uVar10 = *(undefined8 *)((longlong)plVar18 + 0x44);
                        *(undefined8 *)(piVar20 + uVar13 * 0x11 + 5) =
                             *(undefined8 *)((longlong)plVar18 + 0x3c);
                        *(undefined8 *)(piVar20 + uVar13 * 0x11 + 5 + 2) = uVar10;
                        piVar20[uVar13 * 0x11 + 9] = *(int *)((longlong)plVar18 + 0x4c);
                        piVar20[uVar13 * 0x11 + 4] = *(int *)(plVar18 + 7);
                        piVar20[uVar13 * 0x11 + 10] = *(int *)(plVar18 + 10);
                        if ((void *)plVar18[0x11] != (void *)0x0) {
                          memcpy(pvVar21,(void *)plVar18[0x11],
                                 (ulonglong)*(ushort *)((longlong)plVar18 + 0x82));
                          if ((ulonglong)*(ushort *)(plVar18 + 0x10) + 2 <
                              (ulonglong)*(ushort *)((longlong)plVar18 + 0x82)) {
                            piVar20[uVar13 * 0x11 + 0xb] = (int)pvVar21 - iVar11;
                            piVar20[uVar13 * 0x11 + 0xc] =
                                 ((uint)*(ushort *)((longlong)plVar18 + 0x82) -
                                 (uint)*(ushort *)(plVar18 + 0x10)) + -2;
                          }
                          pvVar21 = (void *)((longlong)pvVar21 +
                                            (ulonglong)*(ushort *)((longlong)plVar18 + 0x82));
                          piVar20[uVar13 * 0x11 + 0xf] =
                               ((uint)*(ushort *)((longlong)plVar18 + 0x82) -
                               (uint)*(ushort *)(plVar18 + 0x10)) + piVar20[uVar13 * 0x11 + 0xb];
                          piVar20[uVar13 * 0x11 + 0x10] = (uint)*(ushort *)(plVar18 + 0x10);
                        }
                        memcpy(pvVar21,*(void **)(lVar12 + 0x88),
                               (ulonglong)*(ushort *)(lVar12 + 0x80));
                        piVar20[uVar13 * 0x11 + 0xd] = (int)pvVar21 - iVar11;
                        piVar20[uVar13 * 0x11 + 0xe] = (uint)*(ushort *)(lVar12 + 0x80);
                        pvVar21 = (void *)((longlong)pvVar21 + (ulonglong)*(ushort *)(lVar12 + 0x80)
                                          );
                        if (*(ushort *)(plVar18 + 0x12) != 0) {
                          memcpy(pvVar21,(void *)plVar18[0x13],
                                 (ulonglong)*(ushort *)(plVar18 + 0x12));
                          piVar20[uVar13 * 0x11 + 0x11] = (int)pvVar21 - iVar11;
                          piVar20[uVar13 * 0x11 + 0x12] = (uint)*(ushort *)(plVar18 + 0x12);
                          pvVar21 = (void *)((longlong)pvVar21 +
                                            (ulonglong)*(ushort *)(plVar18 + 0x12));
                        }
                        local_res18 = local_res18 + 1;
                      } while (local_78 != plVar18 + 2);
                    }
                    uVar23 = local_res18;
                  }
LAB_1c000c45a:
                  plVar18 = local_68;
                } while (local_68 != (undefined8 *)(local_80 + 8));
LAB_1c000c701:
                uVar22 = local_res18;
              }
LAB_1c000c709:
              piVar20[1] = uVar22;
              *(ulonglong *)(param_1 + 0x20) = (ulonglong)local_88;
              *(undefined4 *)(param_1 + 0x18) = 0;
              goto LAB_1c000c720;
            }
LAB_1c000c510:
            piVar20[1] = uVar23;
            *(undefined4 *)(param_1 + 0x18) = 0x80000005;
            *(undefined8 *)(param_1 + 0x20) = 8;
            goto LAB_1c000c720;
          }
        }
      }
      local_84 = 1;
LAB_1c000c720:
      DereferenceVolumeContext(local_80);
      ExReleaseResourceLite(&DAT_1c0005118);
      KeLeaveCriticalRegion();
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,
                  &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,param_1,
                  (char)*(undefined8 *)(param_2 + 0x20));
      }
      return local_84;
    }
    FltReleaseContext(local_80);
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c000be78;
    uVar16 = 0x37;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar16,
           &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,iVar11);
LAB_1c000be78:
  *(int *)(param_1 + 0x18) = iVar11;
  return 4;
}



===== DepFSPostFSControl @ 1c000c7f0 =====

undefined8 DepFSPostFSControl(longlong param_1,longlong param_2,undefined8 param_3,uint param_4)

{
  longlong lVar1;
  int iVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_Dqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
               &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,
               *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x28),(char)param_1,
               (char)*(undefined8 *)(param_2 + 0x20));
  }
  if (((((param_4 & 1) == 0) && (*(int *)(*(longlong *)(param_1 + 0x10) + 0x28) == 0x90020)) &&
      ((lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 8), lVar1 != 0 &&
       (((*(uint *)(lVar1 + 0x50) & 0x400000) != 0 && (-1 < *(int *)(param_1 + 0x18))))))) &&
     (iVar2 = FltDetachVolume(*(undefined8 *)(param_2 + 8),*(undefined8 *)(param_2 + 0x10),0),
     iVar2 < 0)) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
               &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,iVar2);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_Dqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
               &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,
               *(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x28),(char)param_1,
               (char)*(undefined8 *)(param_2 + 0x20));
  }
  return 0;
}



===== DepFSPostPnp @ 1c000c930 =====

undefined8 DepFSPostPnp(longlong param_1,longlong param_2,undefined8 param_3,uint param_4)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
               &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,param_1,
               (char)*(undefined8 *)(param_2 + 0x20),(char)*(undefined8 *)(param_2 + 0x10));
  }
  if ((((param_4 & 1) == 0) && (*(char *)(*(longlong *)(param_1 + 0x10) + 5) == '\x16')) &&
     (-1 < *(int *)(param_1 + 0x18))) {
    *(undefined4 *)(param_1 + 0x18) = 0xc00000bb;
  }
  return 0;
}



===== DepFSPreFSControl @ 1c000c9c0 =====

undefined4 DepFSPreFSControl(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 **local_res20;
  
  uVar2 = 1;
  if ((DAT_1c0005196 == '\0') &&
     (lVar1 = *(longlong *)(param_1 + 0x10), (*(byte *)(lVar1 + 5) & 0xfb) == 0)) {
    if (*(int *)(lVar1 + 0x28) == 0x90020) {
      if ((*(longlong *)(lVar1 + 8) != 0) &&
         ((*(uint *)(*(longlong *)(lVar1 + 8) + 0x50) & 0x400000) != 0)) {
        local_res20 = (undefined8 **)0x0;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0 &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])))) {
          WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                    &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,param_1,
                    (char)*(undefined8 *)(param_2 + 0x20));
        }
        iVar3 = FltGetInstanceContext(*(undefined8 *)(param_2 + 0x18),&local_res20);
        if (-1 < iVar3) {
          iVar3 = ReferenceVolumeContext((longlong)local_res20,'\x01');
          if (iVar3 < 0) {
            FltReleaseContext();
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return 1;
            }
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                       &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,iVar3);
            }
          }
          else {
            uVar2 = 5;
            if (((ulonglong)local_res20[7] & 2) == 0) {
              iVar3 = DepFSDismountDependenciesOnVolume(local_res20);
            }
            else {
              iVar3 = -0x3fffffde;
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                         &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,0xc0000022);
              }
              *(undefined4 *)(param_1 + 0x18) = 0xc0000022;
              uVar2 = 4;
            }
            DereferenceVolumeContext((longlong)local_res20);
          }
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                     &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,param_1,
                     (char)*(undefined8 *)(param_2 + 0x20),(char)iVar3);
        }
      }
    }
    else if (*(int *)(lVar1 + 0x28) == 0x901f0) {
      uVar2 = DepFSHandleQueryDependentVolume(param_1,param_2);
    }
  }
  return uVar2;
}



===== DepFSPrePnp @ 1c000cbc0 =====

undefined8 DepFSPrePnp(longlong param_1,longlong param_2)

{
  char cVar1;
  int iVar2;
  longlong *plVar3;
  undefined7 uVar4;
  undefined8 uVar5;
  longlong local_res8;
  
  local_res8 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
               &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,param_1,
               (char)*(undefined8 *)(param_2 + 0x20),(char)*(undefined8 *)(param_2 + 0x10));
  }
  uVar5 = 1;
  cVar1 = *(char *)(*(longlong *)(param_1 + 0x10) + 5);
  if (cVar1 == '\x16') {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,param_1,
                (char)*(undefined8 *)(param_2 + 0x20));
    }
    iVar2 = FltGetInstanceContext(*(undefined8 *)(param_2 + 0x18),&local_res8);
    if (-1 < iVar2) {
      iVar2 = ReferenceVolumeContext(local_res8,'\x01');
      if (*(longlong **)(local_res8 + 0x18) != (longlong *)(local_res8 + 0x18)) {
        if (*(int *)(*(longlong *)(param_1 + 0x10) + 0x20) == 1) {
          uVar5 = 0;
        }
        else {
          *(undefined4 *)(param_1 + 0x18) = 0xc00000bb;
          uVar5 = 4;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                     &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,0xc00000bb);
          }
        }
      }
      if (-1 < iVar2) {
        DereferenceVolumeContext(local_res8);
      }
    }
  }
  else if (cVar1 == '\x17') {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,param_1,
                (char)*(undefined8 *)(param_2 + 0x20));
    }
    plVar3 = &local_res8;
    iVar2 = FltGetInstanceContext(*(undefined8 *)(param_2 + 0x18),plVar3);
    if (-1 < iVar2) {
      uVar4 = (undefined7)((ulonglong)plVar3 >> 8);
      iVar2 = ReferenceVolumeContext(local_res8,'\x01');
      if (iVar2 < 0) {
        FltReleaseContext(local_res8);
      }
      else {
        KeEnterCriticalRegion();
        ExAcquireResourceExclusiveLite(&DAT_1c0005118,CONCAT71(uVar4,1));
        *(uint *)(local_res8 + 0x38) = *(uint *)(local_res8 + 0x38) | 0x20;
        iVar2 = DepFSNotifyChildren(local_res8);
        ExReleaseResourceLite(&DAT_1c0005118);
        KeLeaveCriticalRegion();
        DereferenceVolumeContext(local_res8);
      }
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                 &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,param_1,
                 (char)*(undefined8 *)(param_2 + 0x20),(char)iVar2);
    }
    iVar2 = FltDetachVolume(*(undefined8 *)(param_2 + 8),*(undefined8 *)(param_2 + 0x10),0);
    if (iVar2 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 1;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                 &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,iVar2);
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
               &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,param_1,
               (char)*(undefined8 *)(param_2 + 0x20),(char)*(undefined8 *)(param_2 + 0x10));
  }
  return uVar5;
}



===== DepFSPreShutdown @ 1c000cef0 =====

undefined8 DepFSPreShutdown(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  ushort uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  uint uVar7;
  ulonglong uVar8;
  longlong local_res20;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
               &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,param_1,
               (char)*(undefined8 *)(param_2 + 0x20),(char)*(undefined8 *)(param_2 + 0x10));
  }
  uVar6 = 0;
  if ((DAT_1c0005194 == '\0') && (DAT_1c0005196 == '\0')) {
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite();
    if ((DAT_1c0005194 == '\0') &&
       ((DAT_1c0005196 == '\0' && (DAT_1c0005194 = '\x01', DAT_1c0005180 != 0)))) {
      local_res20 = 0;
      iVar3 = DepFSGenerateDependencyList(0,(undefined8 **)0x0,0,&local_res20,'\x01',0x8100);
      ExReleaseResourceLite(&DAT_1c0005118);
      KeLeaveCriticalRegion();
      if ((iVar3 < 0) &&
         ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                 &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,iVar3);
      }
      if (local_res20 == 0) goto LAB_1c000d1dd;
      uVar8 = 0;
      lVar5 = local_res20;
      if (*(int *)(local_res20 + 4) != 0) {
        do {
          uVar2 = *(ushort *)(lVar5 + 8 + uVar8 * 0x10);
          if ((uVar2 & 0x10) == 0) {
            if ((uVar2 & 1) != 0) {
              lVar4 = *(longlong *)(lVar5 + 0x10 + uVar8 * 0x10);
              KeEnterCriticalRegion();
              ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
              if ((*(longlong **)(lVar4 + 0x18) == (longlong *)(lVar4 + 0x18)) ||
                 ((*(uint *)(lVar4 + 0x38) & 5) != 0)) {
                ExReleaseResourceLite(&DAT_1c0005118);
                KeLeaveCriticalRegion();
              }
              else {
                *(uint *)(lVar4 + 0x38) = *(uint *)(lVar4 + 0x38) | 4;
                ExReleaseResourceLite(&DAT_1c0005118);
                KeLeaveCriticalRegion();
                DepFSSendDismountRequest(lVar4);
              }
              goto LAB_1c000d120;
            }
            if ((uVar2 & 2) == 0) goto LAB_1c000d12f;
            DepFSDismountDependency(*(longlong *)(lVar5 + 0x10 + uVar8 * 0x10));
LAB_1c000d12a:
            lVar5 = local_res20;
          }
          else if ((uVar2 & 1) != 0) {
            lVar4 = *(longlong *)(lVar5 + 0x10 + uVar8 * 0x10);
LAB_1c000d120:
            DereferenceVolumeContext(lVar4);
            *(undefined8 *)(lVar5 + 0x10 + uVar8 * 0x10) = 0;
            goto LAB_1c000d12a;
          }
LAB_1c000d12f:
          uVar7 = (int)uVar8 + 1;
          uVar8 = (ulonglong)uVar7;
        } while (uVar7 < *(uint *)(lVar5 + 4));
      }
      KeEnterCriticalRegion();
      ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
      lVar5 = local_res20;
      if (*(int *)(local_res20 + 4) != 0) {
        do {
          uVar2 = *(ushort *)(uVar6 * 0x10 + 8 + lVar5);
          if ((uVar2 & 2) != 0) {
            lVar5 = lVar5 + uVar6 * 0x10;
            if ((uVar2 >> 8 & 1) != 0) {
              LOCK();
              piVar1 = (int *)(*(longlong *)(lVar5 + 0x10) + 0x60);
              *piVar1 = *piVar1 + -1;
              UNLOCK();
            }
            DereferenceDependencyContext(*(longlong *)(lVar5 + 0x10),'\x01','\0');
            lVar5 = local_res20;
          }
          uVar7 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar7;
        } while (uVar7 < *(uint *)(lVar5 + 4));
      }
      ExFreePoolWithTag(lVar5,0x6c447044);
    }
    ExReleaseResourceLite(&DAT_1c0005118);
    KeLeaveCriticalRegion();
  }
LAB_1c000d1dd:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
               &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,param_1,
               (char)*(undefined8 *)(param_2 + 0x20),(char)*(undefined8 *)(param_2 + 0x10));
  }
  return 1;
}



===== DepFSPreVolumeMount @ 1c000d250 =====

undefined1 DepFSPreVolumeMount(longlong param_1,longlong param_2,longlong *param_3,longlong param_4)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  undefined2 uVar4;
  longlong *plVar5;
  undefined1 uVar7;
  undefined1 uVar6;
  longlong *plVar8;
  longlong local_res20;
  longlong local_28 [2];
  
  local_res20 = 0;
  local_28[0] = 0;
  uVar7 = 1;
  uVar6 = 1;
  plVar8 = param_3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    plVar8 = (longlong *)&WPP_bc64936b77293105c4440102cf4189d6_Traceguids;
    param_4 = param_1;
    WPP_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
               &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,param_1,
               (char)*(undefined8 *)(param_2 + 0x20),(char)*(undefined8 *)(param_2 + 0x10));
  }
  if (DAT_1c0005194 == '\0') {
    if ((DAT_1c0005195 == '\0') && (DAT_1c0005196 == '\0')) {
      lVar3 = FltAllocateGenericWorkItem();
      if (lVar3 == 0) {
        *(undefined8 *)(param_1 + 0x20) = 0;
        uVar6 = 4;
        *(undefined4 *)(param_1 + 0x18) = 0xc000009a;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          plVar8 = (longlong *)&WPP_bc64936b77293105c4440102cf4189d6_Traceguids;
          WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                    &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,*(undefined8 *)(param_2 + 0x10)
                    ,0x9a);
        }
        goto LAB_1c000d519;
      }
      uVar1 = FltGetDeviceObject(*(undefined8 *)(param_2 + 0x10),local_28);
      plVar8 = (longlong *)(ulonglong)uVar1;
      uVar6 = uVar7;
      if ((int)uVar1 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar4 = 0x20;
LAB_1c000d3cb:
          plVar8 = (longlong *)&WPP_bc64936b77293105c4440102cf4189d6_Traceguids;
          WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
                    &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,*(undefined8 *)(param_2 + 0x10)
                    ,(char)uVar1);
        }
      }
      else if ((*(int *)(local_28[0] + 0x48) - 7U < 2) || (*(int *)(local_28[0] + 0x48) == 0x24)) {
        plVar5 = &local_res20;
        uVar1 = FltGetDiskDeviceObject(*(undefined8 *)(param_2 + 0x10));
        plVar8 = (longlong *)(ulonglong)uVar1;
        if ((int)uVar1 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar4 = 0x22;
            goto LAB_1c000d3cb;
          }
        }
        else {
          iVar2 = DepFSCheckDependencies(local_res20,plVar5,plVar8,param_4);
          if (-1 < iVar2) {
            uVar6 = 0;
            *param_3 = lVar3;
            goto LAB_1c000d519;
          }
          *(undefined8 *)(param_1 + 0x20) = 0;
          uVar6 = 4;
          *(int *)(param_1 + 0x18) = iVar2;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar4 = 0x23;
            goto LAB_1c000d4a8;
          }
        }
      }
      else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar4 = 0x21;
LAB_1c000d4a8:
        plVar8 = (longlong *)&WPP_bc64936b77293105c4440102cf4189d6_Traceguids;
        WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
                  &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,*(undefined8 *)(param_2 + 0x10),
                  (char)*(undefined8 *)(param_2 + 0x18));
      }
      FltFreeGenericWorkItem(lVar3);
      goto LAB_1c000d519;
    }
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0 || ((byte)WPP_GLOBAL_Control[0x29] < 2))))
    goto LAB_1c000d519;
    uVar4 = 0x1e;
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c000d519;
    uVar4 = 0x1d;
  }
  plVar8 = (longlong *)&WPP_bc64936b77293105c4440102cf4189d6_Traceguids;
  WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
            &WPP_bc64936b77293105c4440102cf4189d6_Traceguids,*(undefined8 *)(param_2 + 0x10),
            (char)*(undefined8 *)(param_2 + 0x18));
LAB_1c000d519:
  if (local_res20 != 0) {
    ObfDereferenceObject();
  }
  if (local_28[0] != 0) {
    ObfDereferenceObject();
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qqqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),*(undefined8 *)(param_2 + 0x20),plVar8,
                param_1,(char)*(undefined8 *)(param_2 + 0x20),(char)*(undefined8 *)(param_2 + 0x10),
                uVar6);
  }
  return uVar6;
}



===== DepFSRegisterFilters @ 1c000d5a8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DepFSRegisterFilters(undefined8 param_1)

{
  char cVar1;
  int iVar2;
  undefined4 **ppuVar3;
  undefined1 auStackY_268 [32];
  undefined4 *local_228;
  undefined8 local_220;
  undefined8 local_218;
  undefined8 local_210;
  undefined8 local_208;
  undefined8 local_200;
  undefined8 local_1f8;
  undefined8 uStack_1f0;
  undefined4 local_1e8;
  undefined4 local_1e4;
  undefined4 *local_1e0;
  undefined1 *local_1d8;
  code *local_1d0;
  code *local_1c8;
  code *local_1c0;
  code *local_1b8;
  code *local_1b0;
  undefined8 local_1a8;
  undefined8 local_1a0;
  undefined8 local_198;
  undefined8 local_190;
  undefined8 uStack_188;
  undefined8 local_180;
  undefined4 local_178 [2];
  code *local_170;
  undefined8 local_168;
  undefined4 local_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined2 local_140;
  undefined8 local_13e;
  undefined8 uStack_136;
  undefined8 local_12e;
  undefined8 uStack_126;
  undefined8 local_11e;
  undefined8 uStack_116;
  undefined4 local_10e;
  undefined2 local_10a;
  undefined1 local_108 [4];
  undefined4 local_104;
  code *local_100;
  code *local_f8;
  undefined8 local_f0;
  undefined1 local_e8;
  undefined4 local_e4;
  code *local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined1 local_c8;
  undefined4 local_c4;
  code *local_c0;
  code *local_b8;
  undefined8 local_b0;
  undefined1 local_a8;
  undefined4 local_a4;
  code *local_a0;
  code *local_98;
  undefined8 local_90;
  undefined1 local_88;
  undefined4 local_84;
  code *local_80;
  code *local_78;
  undefined8 local_70;
  undefined1 local_68;
  undefined4 local_64;
  undefined8 local_60;
  code *local_58;
  undefined8 local_50;
  undefined1 local_48;
  undefined8 local_44;
  undefined8 uStack_3c;
  undefined8 local_34;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_268;
  local_168 = 0xffffffffffffffff;
  local_100 = DepFSPreFSControl;
  local_228 = (undefined4 *)0x0;
  local_108[0] = 0xd;
  local_f8 = DepFSPostFSControl;
  local_104 = 1;
  local_f0 = 0;
  local_e8 = 0x10;
  local_e0 = DepFSPreShutdown;
  local_e4 = 1;
  local_d0 = 0;
  local_c0 = DepFSPrePnp;
  local_b8 = DepFSPostPnp;
  local_b0 = 0;
  local_a0 = DepFSPreVolumeMount;
  local_98 = DepFSPostVolumeMount;
  local_90 = 0;
  local_80 = DepFSPreCreate;
  local_78 = DepFSPostCreate;
  local_70 = 0;
  local_58 = DepFSPostCleanup;
  local_50 = 0;
  local_34 = 0;
  local_2c = 0;
  local_170 = DepFSContextCleanup;
  local_148 = 0;
  local_140 = 0xffff;
  local_10e = 0;
  local_10a = 0;
  local_1e0 = local_178;
  local_1d8 = local_108;
  local_1d0 = DepFSUnload;
  local_d8 = 0;
  local_c8 = 0x1b;
  local_c4 = 1;
  local_a8 = 0xed;
  local_a4 = 1;
  local_88 = 0;
  local_84 = 5;
  local_68 = 0x12;
  local_64 = 5;
  local_60 = 0;
  local_48 = 0x80;
  local_44 = 0;
  uStack_3c = 0;
  local_178[0] = 2;
  local_160 = 0x63567044;
  local_158 = 0;
  uStack_150 = 0;
  local_1e8 = 0x2030070;
  local_13e = 0;
  uStack_136 = 0;
  local_1e4 = 8;
  local_12e = 0;
  uStack_126 = 0;
  local_11e = 0;
  uStack_116 = 0;
  local_1c8 = DepFSInstanceSetup;
  local_1c0 = DepFSInstanceQueryTeardown;
  local_1b8 = DepFSInstanceTeardownStart;
  local_1b0 = DepFSInstanceTeardownComplete;
  local_180 = 0;
  local_1a8 = 0;
  local_1a0 = 0;
  local_198 = 0;
  local_190 = 0;
  uStack_188 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
              &WPP_d7b1782a7daa350f3d08b40019c93e7e_Traceguids,param_1,(char)&local_1e8);
  }
  cVar1 = FsRtlAreVolumeStartupApplicationsComplete();
  if (cVar1 == '\0') {
    DAT_1c0005199 = '\x01';
  }
  else {
    local_68 = 0x80;
  }
  ppuVar3 = &local_228;
  if (DAT_1c0005198 != '\0') {
    local_1d0 = (code *)0x0;
  }
  iVar2 = FltRegisterFilter(param_1,&local_1e8);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_Dqqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),local_228,ppuVar3,iVar2,(char)param_1,
                (char)&local_1e8,(char)local_228);
  }
  if (-1 < iVar2) {
    DAT_1c0005197 = '\x01';
    DAT_1c0005110 = local_228;
    ExReleaseResourceLite(&DAT_1c0005118);
    KeLeaveCriticalRegion();
    iVar2 = FltStartFiltering(local_228);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
               &WPP_d7b1782a7daa350f3d08b40019c93e7e_Traceguids,iVar2);
    }
    if (-1 < iVar2) {
      if (DAT_1c0005199 == '\0') {
        return iVar2;
      }
      if (DAT_1c00051c4 == 4) {
        return iVar2;
      }
      local_218 = 0x30;
      local_200 = 0x200;
      local_220 = 0;
      local_210 = 0;
      local_208 = 0;
      local_1f8 = 0;
      uStack_1f0 = 0;
      iVar2 = PsCreateSystemThread(&local_220,0x1fffff,&local_218,0);
      if (iVar2 < 0) {
        return iVar2;
      }
      ZwClose(local_220);
      return iVar2;
    }
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
    if (DAT_1c0005197 != '\0') {
      local_228 = DAT_1c0005110;
      DAT_1c0005197 = 0;
      DAT_1c0005110 = (undefined4 *)0x0;
      ExReleaseResourceLite(&DAT_1c0005118);
      KeLeaveCriticalRegion();
      if (local_228 == (undefined4 *)0x0) {
        return iVar2;
      }
      FltUnregisterFilter();
      return iVar2;
    }
  }
  ExReleaseResourceLite(&DAT_1c0005118);
  KeLeaveCriticalRegion();
  return iVar2;
}



===== DependentFSDereferenceDependency @ 1c000da90 =====

undefined8 DependentFSDereferenceDependency(short *param_1)

{
  undefined8 uVar1;
  
                    /* 0xda90  3  DependentFSDereferenceDependency */
  if (DAT_1c0005108 == 0) {
    uVar1 = 0xc0000184;
  }
  else if (DAT_1c0005196 == '\0') {
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
    if (((param_1 == (short *)0x0) || (*param_1 != 0x3030)) || (*(int *)(param_1 + 0x1c) == 0)) {
      ExReleaseResourceLite(&DAT_1c0005118);
      KeLeaveCriticalRegion();
      uVar1 = 0xc000000d;
    }
    else {
      DereferenceDependencyContext((longlong)param_1,'\x01','\0');
      ExReleaseResourceLite(&DAT_1c0005118);
      KeLeaveCriticalRegion();
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0xc0000189;
  }
  return uVar1;
}



===== DependentFSReferenceDependency @ 1c000db60 =====

undefined8 DependentFSReferenceDependency(short *param_1)

{
  undefined8 uVar1;
  
                    /* 0xdb60  7  DependentFSReferenceDependency */
  if (DAT_1c0005108 == 0) {
    uVar1 = 0xc0000184;
  }
  else if (DAT_1c0005196 == '\0') {
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
    if (((param_1 == (short *)0x0) || (*param_1 != 0x3030)) || (*(int *)(param_1 + 0x1c) == 0)) {
      ExReleaseResourceLite(&DAT_1c0005118);
      KeLeaveCriticalRegion();
      uVar1 = 0xc000000d;
    }
    else {
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
      ExReleaseResourceLite(&DAT_1c0005118);
      KeLeaveCriticalRegion();
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0xc0000189;
  }
  return uVar1;
}



===== DependentFSRegister @ 1c000dc30 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DependentFSRegister(longlong param_1,undefined8 param_2,longlong param_3,ushort *param_4,
                       uint param_5,int *param_6,undefined4 param_7,undefined4 param_8,
                       undefined8 param_9,void *param_10,uint param_11,undefined8 *param_12)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 uVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  uint *puVar11;
  ushort *puVar12;
  void *pvVar13;
  undefined4 *puVar14;
  undefined2 uVar15;
  uint uVar16;
  ulonglong uVar17;
  longlong *plVar18;
  longlong *plVar19;
  longlong *plVar20;
  undefined1 *puVar21;
  undefined1 *puVar22;
  undefined1 auStack_a8 [8];
  undefined1 auStack_a0 [24];
  char local_78;
  uint local_74;
  longlong *local_70;
  longlong local_68;
  uint local_60 [10];
  
                    /* 0xdc30  8  DependentFSRegister */
  puVar12 = (ushort *)0x0;
  local_68 = 0;
  puVar11 = (uint *)0x0;
  local_78 = '\0';
  local_60[0] = 0;
  local_60[1] = 0;
  local_60[2] = 0;
  local_60[3] = 0;
  if (param_12 == (undefined8 *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_d7b1782a7daa350f3d08b40019c93e7e_Traceguids,0xc000000d);
    }
    puVar22 = auStack_a8;
    goto LAB_1c000e6d8;
  }
  iVar9 = DepFSCheckHostFileObject(0,param_3,param_5,param_6);
  if (iVar9 < 0) {
    puVar22 = auStack_a8;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (puVar22 = auStack_a8, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (puVar22 = auStack_a8, 1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_d7b1782a7daa350f3d08b40019c93e7e_Traceguids,iVar9);
      puVar22 = auStack_a8;
    }
    goto LAB_1c000e6d8;
  }
  puVar10 = (undefined4 *)ExAllocatePool2(0x40,0xe0,0x63447044);
  if (puVar10 == (undefined4 *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar15 = 0xc;
LAB_1c000dd8b:
      iVar9 = -0x3fffff66;
LAB_1c000dd91:
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar15,
               &WPP_d7b1782a7daa350f3d08b40019c93e7e_Traceguids,iVar9);
    }
LAB_1c000e34b:
    puVar22 = auStack_a8;
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
    local_78 = '\0';
    puVar21 = auStack_a8;
    if (puVar10 != (undefined4 *)0x0) goto LAB_1c000e64f;
    goto LAB_1c000e65e;
  }
  *puVar10 = 0xe03030;
  puVar10[0xe] = 1;
  puVar10[0xf] = param_5;
  *(undefined8 *)(puVar10 + 0x1e) = param_9;
  puVar10[0x16] = param_8;
  iVar9 = param_6[1];
  iVar7 = param_6[2];
  iVar8 = param_6[3];
  puVar10[0x11] = *param_6;
  puVar10[0x12] = iVar9;
  puVar10[0x13] = iVar7;
  puVar10[0x14] = iVar8;
  puVar10[0x15] = param_6[4];
  puVar10[0x10] = param_7;
  puVar14 = puVar10 + 10;
  *(undefined4 **)(puVar10 + 0xc) = puVar14;
  *(undefined4 **)puVar14 = puVar14;
  puVar14 = puVar10 + 2;
  *(undefined4 **)(puVar10 + 4) = puVar14;
  *(undefined4 **)puVar14 = puVar14;
  puVar14 = puVar10 + 6;
  *(undefined4 **)(puVar10 + 8) = puVar14;
  *(undefined4 **)puVar14 = puVar14;
  puVar10[0x30] = 0;
  ExInitializePushLock(puVar10 + 0x2e);
  KeInitializeEvent(puVar10 + 0x32,0,1);
  puVar11 = (uint *)ExAllocatePool2(0x100,0x210,0x70527044);
  if (puVar11 == (uint *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar15 = 0xd;
      goto LAB_1c000dd8b;
    }
    goto LAB_1c000e34b;
  }
  iVar9 = ZwQueryInformationFile(param_2,local_60,puVar11,0x210);
  if (iVar9 == -0x7ffffffb) {
    uVar16 = *puVar11;
    ExFreePoolWithTag(puVar11,0x70527044);
    puVar11 = (uint *)ExAllocatePool2(0x100,uVar16 + 8,0x70527044);
    if (puVar11 == (uint *)0x0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar15 = 0xe;
        goto LAB_1c000dd8b;
      }
      goto LAB_1c000e34b;
    }
    iVar9 = ZwQueryInformationFile(param_2,local_60,puVar11,uVar16 + 8);
  }
  if (iVar9 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar15 = 0xf;
      goto LAB_1c000dd91;
    }
    goto LAB_1c000e34b;
  }
  if (*puVar11 != 0) {
    local_74 = 0;
    local_68 = IoGetDeviceAttachmentBaseRef(*(undefined8 *)(param_3 + 8));
    local_60[4] = 0;
    local_60[5] = 0;
    local_60[6] = 0;
    local_60[7] = 0;
    iVar9 = ObQueryNameString(local_68,local_60 + 4,0,&local_74);
    if (((iVar9 + 0x80000000U & 0x80000000) == 0) && (iVar9 != -0x3ffffffc)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29])))
         ) {
        uVar15 = 0x10;
        goto LAB_1c000dd91;
      }
    }
    else {
      puVar12 = (ushort *)ExAllocatePool2(0x100,(ulonglong)local_74 + 0x10,0x70527044);
      if (puVar12 == (ushort *)0x0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar15 = 0x11;
          goto LAB_1c000dd8b;
        }
      }
      else {
        if (0x10000 < local_74) {
          local_74 = 0;
        }
        *puVar12 = (ushort)local_74;
        puVar12[1] = (ushort)local_74;
        *(ushort **)(puVar12 + 4) = puVar12 + 8;
        iVar9 = ObQueryNameString(local_68,puVar12,local_74,&local_74);
        if (iVar9 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar15 = 0x12;
            goto LAB_1c000dd91;
          }
        }
        else {
          if (*puVar12 < local_74) {
            local_74 = (uint)*puVar12;
          }
          uVar17 = (ulonglong)(*puVar11 + local_74) + 2;
          if (uVar17 < 0x10001) {
            pvVar13 = (void *)ExAllocatePool2(0x100,uVar17,0x70527044);
            *(void **)(puVar10 + 0x24) = pvVar13;
            if (pvVar13 != (void *)0x0) {
              *(short *)(puVar10 + 0x22) = (short)*puVar11;
              memcpy(pvVar13,*(void **)(puVar12 + 4),(ulonglong)local_74);
              *(short *)((longlong)puVar10 + 0x8a) = (short)local_74 + 2 + (short)*puVar11;
              *(undefined2 *)(*(longlong *)(puVar10 + 0x24) + (ulonglong)(local_74 >> 1) * 2) = 0x5c
              ;
              memcpy((void *)((ulonglong)local_74 + 2 + *(longlong *)(puVar10 + 0x24)),puVar11 + 1,
                     (ulonglong)*puVar11);
              goto LAB_1c000e224;
            }
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar15 = 0x14;
              goto LAB_1c000dd8b;
            }
          }
          else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                  (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar15 = 0x13;
            goto LAB_1c000dd8b;
          }
        }
      }
    }
    goto LAB_1c000e34b;
  }
LAB_1c000e224:
  if ((param_10 != (void *)0x0) && (param_11 != 0)) {
    pvVar13 = (void *)ExAllocatePool2(0x100,(ulonglong)param_11,0x63417044);
    *(void **)(puVar10 + 0x2a) = pvVar13;
    if (pvVar13 != (void *)0x0) {
      puVar10[0x2c] = param_11;
      memcpy(pvVar13,param_10,(ulonglong)param_11);
      goto LAB_1c000e2bc;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c000e34b;
    uVar15 = 0x15;
LAB_1c000e335:
    WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar15,
              &WPP_d7b1782a7daa350f3d08b40019c93e7e_Traceguids,0xc000009a,(char)param_11);
    goto LAB_1c000e34b;
  }
LAB_1c000e2bc:
  if ((param_4 != (ushort *)0x0) && (*param_4 != 0)) {
    pvVar13 = (void *)ExAllocatePool2(0x100,*param_4,0x64447044);
    *(void **)(puVar10 + 0x28) = pvVar13;
    if (pvVar13 == (void *)0x0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) goto LAB_1c000e34b;
      uVar15 = 0x16;
      param_11 = (uint)*param_4;
      goto LAB_1c000e335;
    }
    *(ushort *)(puVar10 + 0x26) = *param_4;
    *(ushort *)((longlong)puVar10 + 0x9a) = *param_4;
    memcpy(pvVar13,*(void **)(param_4 + 4),(ulonglong)*param_4);
  }
  puVar22 = auStack_a8;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
  uVar16 = (uint)DAT_1c0005195;
  puVar21 = auStack_a8;
  if ((DAT_1c0005195 == 0) && (puVar21 = auStack_a8, DAT_1c0005194 == 0)) {
    plVar19 = DAT_1c00051b0;
    plVar18 = DAT_1c00051b0;
    if ((longlong **)DAT_1c00051b0 != &DAT_1c00051b0) {
      do {
        plVar19 = (longlong *)*plVar18;
        if (((plVar19 != plVar18) && ((*(uint *)((longlong)plVar18 + 0x34) & 3) == 0)) &&
           (plVar18[0xb] == param_1)) {
          plVar18 = plVar18 + -2;
          plVar20 = (longlong *)*plVar18;
          if (plVar20 != plVar18) goto LAB_1c000e567;
        }
        plVar18 = plVar19;
      } while ((longlong **)plVar19 != &DAT_1c00051b0);
    }
    goto LAB_1c000e440;
  }
LAB_1c000e6f8:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(uint *)(puVar21 + 0x20) = (uint)DAT_1c0005194;
    *(undefined8 *)(puVar21 + -8) = 0x1c000e73c;
    WPP_SF_DD(uVar5,0x17,&WPP_d7b1782a7daa350f3d08b40019c93e7e_Traceguids,uVar16,puVar21[0x20]);
  }
LAB_1c000e64b:
LAB_1c000e64f:
  puVar22 = puVar21;
  *(undefined8 *)(puVar22 + -8) = 0x1c000e65a;
  DereferenceDependencyContext((longlong)puVar10,'\x01',local_78);
  puVar10 = (undefined4 *)0x0;
  goto LAB_1c000e65e;
  while( true ) {
    *puVar14 = 0x383050;
    *(undefined4 **)(puVar14 + 2) = puVar10;
    puVar2 = (undefined8 *)(puVar14 + 10);
    plVar19 = *(longlong **)(puVar10 + 8);
    if ((undefined4 *)*plVar19 != puVar10 + 6) goto LAB_1c000e6f1;
    *(longlong **)(puVar14 + 0xc) = plVar19;
    *puVar2 = puVar10 + 6;
    *plVar19 = (longlong)puVar2;
    *(undefined8 **)(puVar10 + 8) = puVar2;
    *(longlong *)(puVar14 + 4) = local_70[-3];
    plVar20 = (longlong *)(puVar14 + 6);
    lVar4 = local_70[-3];
    plVar19 = *(longlong **)(lVar4 + 0x20);
    if (*plVar19 != lVar4 + 0x18) goto LAB_1c000e6f1;
    *plVar20 = lVar4 + 0x18;
    *(longlong **)(puVar14 + 8) = plVar19;
    *plVar19 = (longlong)plVar20;
    *(longlong **)(lVar4 + 0x20) = plVar20;
    plVar20 = plVar3;
    if (plVar3 == plVar18) break;
LAB_1c000e567:
    plVar3 = (longlong *)*plVar20;
    local_70 = plVar20;
    puVar14 = (undefined4 *)ExAllocatePool2(0x100,0x38,0x6c507044);
    if (puVar14 == (undefined4 *)0x0) {
      puVar21 = auStack_a8;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (puVar21 = auStack_a8, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (puVar21 = auStack_a8, 1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                 &WPP_d7b1782a7daa350f3d08b40019c93e7e_Traceguids,0xc000009a);
        puVar21 = auStack_a8;
      }
      goto LAB_1c000e64b;
    }
  }
LAB_1c000e440:
  puVar10[0xe] = puVar10[0xe] + 1;
  if ((longlong **)*DAT_1c00051b8 != &DAT_1c00051b0) {
LAB_1c000e6f1:
    uVar16 = (uint)plVar19;
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)(3);
    puVar21 = auStack_a0;
    goto LAB_1c000e6f8;
  }
  puVar2 = (undefined8 *)(puVar10 + 10);
  *puVar2 = &DAT_1c00051b0;
  *(undefined8 **)(puVar10 + 0xc) = DAT_1c00051b8;
  *DAT_1c00051b8 = puVar2;
  DAT_1c0005180 = DAT_1c0005180 + 1;
  _DAT_1c0005184 = _DAT_1c0005184 + 1;
  DAT_1c00051b8 = puVar2;
  if (((param_5 & 0x10) != 0) && (DAT_1c0005198 = 1, DAT_1c00051cc == '\0')) {
    FsDepRegisterUnregisterForBugchecks('\x01','\x01');
  }
  if (DAT_1c0005197 == '\0') {
    iVar9 = DepFSRegisterFilters(DAT_1c0005108);
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
    if (-1 < iVar9) {
      DAT_1c0005197 = '\x01';
      goto LAB_1c000e4dd;
    }
    local_78 = '\x01';
    puVar21 = auStack_a8;
    goto LAB_1c000e64f;
  }
LAB_1c000e4dd:
  *(longlong *)(puVar10 + 0x1a) = param_3;
  ObfReferenceObject(param_3);
  *(longlong *)(puVar10 + 0x20) = param_1;
  ObfReferenceObject();
  DepFSGetParentVolumeContext(param_1,(longlong)puVar10);
  plVar19 = *(longlong **)(puVar10 + 0x1c);
  if (plVar19 != (longlong *)0x0) {
    puVar2 = (undefined8 *)plVar19[2];
    if ((longlong *)*puVar2 != plVar19 + 1) goto LAB_1c000e6f1;
    puVar1 = (undefined8 *)(puVar10 + 2);
    *puVar1 = plVar19 + 1;
    *(undefined8 **)(puVar10 + 4) = puVar2;
    *puVar2 = puVar1;
    plVar19[2] = (longlong)puVar1;
    if (*(int *)((longlong)plVar19 + 0x54) == 0x14) {
      puVar10[0xf] = puVar10[0xf] | 8;
    }
  }
  DereferenceDependencyContext((longlong)puVar10,'\x01','\0');
LAB_1c000e65e:
  lVar4 = local_68;
  if (puVar11 != (uint *)0x0) {
    *(undefined8 *)(puVar22 + -8) = 0x1c000e676;
    ExFreePoolWithTag(puVar11,0x70527044);
  }
  if (lVar4 != 0) {
    *(undefined8 *)(puVar22 + -8) = 0x1c000e68a;
    ObfDereferenceObject(lVar4);
  }
  if (puVar12 != (ushort *)0x0) {
    *(undefined8 *)(puVar22 + -8) = 0x1c000e6a3;
    ExFreePoolWithTag(puVar12,0x70527044);
  }
  *param_12 = puVar10;
  *(undefined8 *)(puVar22 + -8) = 0x1c000e6c5;
  ExReleaseResourceLite(&DAT_1c0005118);
  *(undefined8 *)(puVar22 + -8) = 0x1c000e6d1;
  KeLeaveCriticalRegion();
LAB_1c000e6d8:
  return (int)*(undefined8 *)(puVar22 + 200);
}



===== DependentFSRegisterDeviceName @ 1c000e760 =====

uint DependentFSRegisterDeviceName(longlong param_1,ushort *param_2)

{
  int iVar1;
  uint uVar2;
  void *_Dst;
  
                    /* 0xe760  9  DependentFSRegisterDeviceName */
  if (*(longlong *)(param_1 + 0xa0) == 0) {
    _Dst = (void *)ExAllocatePool2(0x100,*param_2,0x64447044);
    *(void **)(param_1 + 0xa0) = _Dst;
    if (_Dst == (void *)0x0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                  &WPP_d7b1782a7daa350f3d08b40019c93e7e_Traceguids,0xc000009a,(char)*param_2);
      }
      uVar2 = 0xc000009a;
    }
    else {
      *(ushort *)(param_1 + 0x98) = *param_2;
      *(ushort *)(param_1 + 0x9a) = *param_2;
      memcpy(_Dst,*(void **)(param_2 + 4),(ulonglong)*param_2);
      uVar2 = 0;
    }
  }
  else {
    iVar1 = RtlCompareUnicodeString(param_2,param_1 + 0x98,0);
    uVar2 = -(uint)(iVar1 != 0) & 0xc000000d;
  }
  return uVar2;
}



===== DependentFSCheckStoragePrivilege @ 1c000e850 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 DependentFSCheckStoragePrivilege(longlong param_1,int *param_2,uint param_3)

{
  char cVar1;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
                    /* 0xe850  2  DependentFSCheckStoragePrivilege */
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  if ((param_3 & 0x70000) != 0) {
    cVar1 = RtlIsSandboxedToken(param_1,1);
    if (cVar1 == '\x01') {
      return 0xc0000022;
    }
    if ((DAT_1c000519b == '\0') || (*param_2 != 1)) {
      if (param_1 == 0) {
        return 0xc0000061;
      }
      local_38 = 0x1c;
      local_28 = 0x1c;
      local_30 = 1;
      local_2c = 1;
      local_20 = 0;
      cVar1 = SePrivilegeCheck(&local_30,param_1,1);
      if (cVar1 == '\0') {
        return 0xc0000061;
      }
      return 0;
    }
  }
  return 0;
}



===== DependentFSGetVirtualStoragePolicies @ 1c000e930 =====

undefined8 DependentFSGetVirtualStoragePolicies(ulonglong param_1)

{
  undefined4 uVar1;
  undefined4 *in_stack_00000028;
  
                    /* 0xe930  6  DependentFSGetVirtualStoragePolicies */
  if (((param_1 & 4) == 0) &&
     ((DAT_1c00051c4 == 2 ||
      ((DAT_1c00051c4 != 4 && (((param_1 & 0x10) != 0 || ((param_1 & 0x20) != 0)))))))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  *in_stack_00000028 = uVar1;
  return 0;
}



===== DepFSCheckDependencies @ 1c000e96c =====

int DepFSCheckDependencies
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  short *psVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  uint local_res10 [2];
  undefined4 local_res18 [4];
  
  lVar3 = 0;
  local_res18[0] = 3;
  local_res10[0] = 0;
  uVar6 = 0x48;
  while( true ) {
    if (lVar3 != 0) {
      uVar4 = *(ulonglong *)(lVar3 + 8);
      ExFreePoolWithTag(lVar3,0x72517044);
      lVar3 = 0;
      uVar6 = uVar4 & 0xffffffff;
      if (uVar4 != uVar6) {
        iVar2 = -0x3fffff66;
        goto LAB_1c000eb3a;
      }
    }
    uVar4 = uVar6;
    lVar3 = ExAllocatePool2(0x100,uVar6,0x72517044);
    if (lVar3 == 0) break;
    iVar2 = DepFSSendIoctl(param_1,uVar4,local_res18,param_4,lVar3,(int)uVar6,local_res10);
    if (iVar2 != -0x7ffffffb) {
      if (iVar2 < 0) {
        if (iVar2 != -0x3ffffff0) {
LAB_1c000eb3a:
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                     &WPP_a3c4d1782baa35d2d3c4179a15ae3a1d_Traceguids,iVar2);
          }
        }
LAB_1c000eb6b:
        iVar2 = 0;
        if (lVar3 == 0) {
          return 0;
        }
      }
      else if (0x37 < local_res10[0]) {
        uVar6 = 0;
        uVar5 = 0;
        if (*(int *)(lVar3 + 4) != 0) {
          do {
            psVar1 = *(short **)(lVar3 + (uVar6 + 1) * 0x30);
            if (((((psVar1 != (short *)0x0) && (*psVar1 == 0x3030)) &&
                 ((DepFSIncrementActiveMountCount((longlong)psVar1), 0 < *(int *)(psVar1 + 0x30) ||
                  ((*(uint *)(psVar1 + 0x2e) & 0x31) != 0)))) &&
                ((iVar2 = -0x3fc5ffe4, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)))) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                       &WPP_a3c4d1782baa35d2d3c4179a15ae3a1d_Traceguids,psVar1);
            }
            uVar5 = *(uint *)(lVar3 + 4);
            uVar7 = (int)uVar6 + 1;
            uVar6 = (ulonglong)uVar7;
          } while (uVar7 < uVar5);
        }
        uVar6 = 0;
        if (uVar5 != 0) {
          do {
            psVar1 = *(short **)(lVar3 + (uVar6 + 1) * 0x30);
            if ((psVar1 != (short *)0x0) && (*psVar1 == 0x3030)) {
              if (iVar2 < 0) {
                DepFSDecrementActiveMountCount((longlong)psVar1);
              }
              DependentFSDereferenceDependency(psVar1);
            }
            uVar5 = (int)uVar6 + 1;
            uVar6 = (ulonglong)uVar5;
          } while (uVar5 < *(uint *)(lVar3 + 4));
        }
      }
      ExFreePoolWithTag(lVar3,0x72517044);
      return iVar2;
    }
  }
  iVar2 = -0x3fffff66;
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_1c000eb6b;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
             &WPP_a3c4d1782baa35d2d3c4179a15ae3a1d_Traceguids,(int)uVar6);
  }
  goto LAB_1c000eb3a;
}



===== DepFSGenerateDependencyList @ 1c000eba0 =====

int DepFSGenerateDependencyList
              (longlong param_1,undefined8 **param_2,uint param_3,undefined8 *param_4,char param_5,
              uint param_6)

{
  undefined8 *puVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 **ppuVar4;
  longlong lVar5;
  bool bVar6;
  int iVar7;
  undefined2 *puVar8;
  byte *pbVar9;
  ushort uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  undefined2 uVar13;
  uint uVar14;
  undefined8 *puVar15;
  longlong lVar16;
  undefined8 **ppuVar17;
  undefined8 *puVar18;
  longlong *plVar19;
  int iVar20;
  uint uVar21;
  int local_58;
  
  iVar7 = 0;
  local_58 = 0;
  if (param_5 == '\0') {
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
  }
  iVar20 = (DAT_1c0005190 + DAT_1c0005180) * 0x10 + 8;
  puVar8 = (undefined2 *)ExAllocatePool2(0x100,iVar20);
  *param_4 = puVar8;
  if (puVar8 == (undefined2 *)0x0) {
    if (param_5 == '\0') {
      ExReleaseResourceLite(&DAT_1c0005118);
      KeLeaveCriticalRegion();
    }
    return -0x3fffff66;
  }
  *puVar8 = 0x3040;
  puVar8[1] = (short)iVar20;
  iVar20 = DAT_1c0005190 + DAT_1c0005180;
  *(int *)(puVar8 + 2) = iVar20;
  if (iVar20 == 0) {
    if (param_5 == '\0') {
      ExReleaseResourceLite(&DAT_1c0005118);
      KeLeaveCriticalRegion();
    }
    return 0;
  }
  uVar21 = iVar20 - 1;
  if (param_1 == 0) {
    if (param_2 == (undefined8 **)0x0) {
      if (param_3 == 0) {
        ppuVar17 = (undefined8 **)DAT_1c00051a0;
        iVar20 = local_58;
        if ((undefined8 **)DAT_1c00051a0 != &DAT_1c00051a0) {
          do {
            param_2 = ppuVar17 + -5;
            ppuVar4 = (undefined8 **)*ppuVar17;
            if ((undefined8 **)ppuVar17[-2] == ppuVar17 + -2) {
              iVar7 = ReferenceVolumeContext((longlong)param_2,'\0');
              local_58 = iVar7;
              if (iVar7 < 0) {
                if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
                   ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c000eeb2;
                uVar13 = 0x11;
                goto LAB_1c000ee91;
              }
              uVar11 = (ulonglong)uVar21;
              *(undefined8 ***)(puVar8 + uVar11 * 8 + 8) = param_2;
              *(undefined4 *)(puVar8 + uVar11 * 8 + 4) = 1;
              if (((ulonglong)ppuVar17[2] & 2) != 0) {
                puVar8[uVar11 * 8 + 4] = 0x11;
              }
              uVar21 = uVar21 - 1;
            }
            ppuVar17 = ppuVar4;
            iVar20 = iVar7;
          } while (ppuVar4 != &DAT_1c00051a0);
        }
      }
      else {
        iVar20 = iVar7;
        if ((undefined8 **)DAT_1c00051b0 != &DAT_1c00051b0) {
          ppuVar17 = (undefined8 **)DAT_1c00051b0;
          do {
            bVar6 = false;
            ppuVar4 = (undefined8 **)*ppuVar17;
            if (((param_3 & 0x11) != 0) && ((*(byte *)((longlong)ppuVar17 + 0x14) & 8) != 0)) {
              bVar6 = true;
            }
            if (((*(uint *)((longlong)ppuVar17 + 0x34) & 0x10) == 0) && (bVar6)) {
              uVar11 = (ulonglong)uVar21;
              *(undefined8 ***)(puVar8 + uVar11 * 8 + 8) = ppuVar17 + -5;
              puVar8[uVar11 * 8 + 4] = 2;
              if ((*(uint *)((longlong)ppuVar17 + 0x14) & 0x30) != 0) {
                puVar8[uVar11 * 8 + 4] = 0x12;
              }
              puVar8[uVar11 * 8 + 5] = 0;
              if ((param_6 & 0x100) != 0) {
                LOCK();
                *(int *)(ppuVar17 + 7) = *(int *)(ppuVar17 + 7) + 1;
                UNLOCK();
                puVar8[uVar11 * 8 + 4] = puVar8[uVar11 * 8 + 4] | 0x100;
              }
              *(int *)(ppuVar17 + 2) = *(int *)(ppuVar17 + 2) + 1;
              uVar21 = uVar21 - 1;
            }
            ppuVar17 = ppuVar4;
          } while (ppuVar4 != &DAT_1c00051b0);
        }
      }
LAB_1c000ede7:
      lVar16 = (longlong)(*(int *)(puVar8 + 2) + -1);
      iVar7 = iVar20;
      if (-1 < *(int *)(puVar8 + 2) + -1) {
        pbVar9 = (byte *)(puVar8 + lVar16 * 8 + 4);
        while( true ) {
          lVar16 = lVar16 + -1;
          lVar3 = *(longlong *)(pbVar9 + 8);
          if (lVar3 == 0) break;
          if ((*pbVar9 & 1) != 0) {
            puVar15 = *(undefined8 **)(lVar3 + 8);
LAB_1c000f146:
            do {
              puVar18 = puVar15;
              if (puVar18 == (undefined8 *)(lVar3 + 8)) goto LAB_1c000f327;
              puVar1 = puVar18 + -1;
              bVar6 = true;
              puVar15 = (undefined8 *)*puVar18;
              if ((*(uint *)((longlong)puVar18 + 0x54) & 0x10) == 0) {
                uVar14 = uVar21 + 1;
                if (uVar14 < *(uint *)(puVar8 + 2)) {
                  do {
                    uVar11 = (ulonglong)uVar14;
                    if (*(undefined8 **)(puVar8 + uVar11 * 8 + 8) == puVar1) {
                      bVar6 = false;
                      uVar10 = puVar8[uVar11 * 8 + 5];
                      if ((ushort)puVar8[uVar11 * 8 + 5] <= *(ushort *)(pbVar9 + 2)) {
                        uVar10 = *(ushort *)(pbVar9 + 2);
                      }
                      puVar8[uVar11 * 8 + 5] = uVar10;
                    }
                    uVar14 = uVar14 + 1;
                  } while (uVar14 < *(uint *)(puVar8 + 2));
                  if (!bVar6) goto LAB_1c000f146;
                }
                uVar11 = (ulonglong)uVar21;
                *(undefined8 **)(puVar8 + uVar11 * 8 + 8) = puVar1;
                puVar8[uVar11 * 8 + 4] = 2;
                if ((*(uint *)((longlong)puVar18 + 0x34) & 0x30) != 0) {
                  puVar8[uVar11 * 8 + 4] = 0x12;
                }
                if ((*(uint *)(lVar3 + 0x38) & 0x20) != 0) {
                  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
                     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                              &WPP_a3c4d1782baa35d2d3c4179a15ae3a1d_Traceguids,puVar1,(char)lVar3);
                  }
                  *(uint *)((longlong)puVar18 + 0x54) = *(uint *)((longlong)puVar18 + 0x54) | 0x20;
                }
                puVar8[(ulonglong)uVar21 * 8 + 5] = *(undefined2 *)(pbVar9 + 2);
                if ((param_6 & 0x100) != 0) {
                  LOCK();
                  *(int *)(puVar18 + 0xb) = *(int *)(puVar18 + 0xb) + 1;
                  UNLOCK();
                  puVar8[(ulonglong)uVar21 * 8 + 4] = puVar8[(ulonglong)uVar21 * 8 + 4] | 0x100;
                }
                *(int *)(puVar18 + 6) = *(int *)(puVar18 + 6) + 1;
                uVar21 = uVar21 - 1;
              }
            } while( true );
          }
          plVar2 = (longlong *)(lVar3 + 0x18);
          plVar19 = (longlong *)*plVar2;
          if (plVar19 != plVar2) {
            uVar11 = (ulonglong)(uVar21 + 1);
            do {
              bVar6 = true;
              lVar5 = plVar19[-3];
              plVar19 = (longlong *)*plVar19;
              uVar12 = uVar11;
              if ((uint)uVar11 < *(uint *)(puVar8 + 2)) {
                do {
                  if (*(longlong *)(puVar8 + uVar12 * 8 + 8) == lVar5) {
                    bVar6 = false;
                    uVar10 = puVar8[uVar12 * 8 + 5];
                    if ((uint)(ushort)puVar8[uVar12 * 8 + 5] <= *(ushort *)(pbVar9 + 2) + 1) {
                      uVar10 = (ushort)(*(ushort *)(pbVar9 + 2) + 1);
                    }
                    puVar8[uVar12 * 8 + 5] = uVar10;
                  }
                  uVar14 = (int)uVar12 + 1;
                  uVar12 = (ulonglong)uVar14;
                } while (uVar14 < *(uint *)(puVar8 + 2));
                if (bVar6) goto LAB_1c000f1b5;
              }
              else {
LAB_1c000f1b5:
                iVar7 = ReferenceVolumeContext(lVar5,'\0');
                local_58 = iVar7;
                if (iVar7 < 0) {
                  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                    WPP_SF_Dqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                               &WPP_a3c4d1782baa35d2d3c4179a15ae3a1d_Traceguids,iVar7,(char)param_1,
                               (char)lVar5);
                  }
                  if ((param_6 & 0x8000) == 0) goto LAB_1c000f241;
                }
                else {
                  uVar12 = (ulonglong)uVar21;
                  *(longlong *)(puVar8 + uVar12 * 8 + 8) = lVar5;
                  puVar8[uVar12 * 8 + 4] = 1;
                  puVar8[uVar12 * 8 + 5] = *(short *)(pbVar9 + 2) + 1;
                  if ((*(uint *)(lVar5 + 0x38) & 2) != 0) {
                    puVar8[uVar12 * 8 + 4] = 0x11;
                  }
                  if ((*(uint *)(lVar3 + 0x5c) & 0x20) != 0) {
                    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
                       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                                &WPP_a3c4d1782baa35d2d3c4179a15ae3a1d_Traceguids,lVar3,(char)lVar5);
                    }
                    uVar14 = *(uint *)(lVar5 + 0x38);
                    *(uint *)(lVar5 + 0x38) = uVar14 | 0x20;
                    if ((uVar14 & 2) != 0) goto LAB_1c000f33b;
                  }
                  uVar21 = uVar21 - 1;
                  uVar11 = (ulonglong)((uint)uVar11 - 1);
                }
              }
            } while (plVar19 != plVar2);
          }
LAB_1c000f327:
          if (lVar16 < 0) break;
          pbVar9 = pbVar9 + -0x10;
        }
        iVar7 = local_58;
      }
      if (-1 < iVar7) goto LAB_1c000f3bc;
    }
    else {
      local_58 = ReferenceVolumeContext((longlong)param_2,'\0');
      if (-1 < local_58) {
        uVar11 = (ulonglong)uVar21;
        *(undefined8 ***)(puVar8 + uVar11 * 8 + 8) = param_2;
        *(undefined4 *)(puVar8 + uVar11 * 8 + 4) = 1;
        if (((ulonglong)param_2[7] & 2) != 0) {
          puVar8[uVar11 * 8 + 4] = 0x11;
        }
        uVar21 = iVar20 - 2;
        iVar20 = local_58;
        goto LAB_1c000ede7;
      }
      iVar7 = local_58;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar13 = 0x10;
LAB_1c000ee91:
        WPP_SF_Dqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar13,
                   &WPP_a3c4d1782baa35d2d3c4179a15ae3a1d_Traceguids,local_58,0,(char)param_2);
        iVar7 = local_58;
      }
    }
LAB_1c000eeb2:
    if ((param_6 & 0x8000) != 0) goto LAB_1c000f3bc;
  }
  else {
    puVar15 = *(undefined8 **)(param_1 + 0x18);
    do {
      while( true ) {
        iVar20 = local_58;
        if (puVar15 == (undefined8 *)(param_1 + 0x18)) goto LAB_1c000ede7;
        lVar16 = puVar15[-3];
        puVar15 = (undefined8 *)*puVar15;
        iVar7 = ReferenceVolumeContext(lVar16,'\0');
        local_58 = iVar7;
        if (iVar7 < 0) break;
        uVar11 = (ulonglong)uVar21;
        *(longlong *)(puVar8 + uVar11 * 8 + 8) = lVar16;
        *(undefined4 *)(puVar8 + uVar11 * 8 + 4) = 1;
        if ((*(uint *)(lVar16 + 0x38) & 2) != 0) {
          puVar8[uVar11 * 8 + 4] = 0x11;
        }
        if ((*(uint *)(param_1 + 0x5c) & 0x20) != 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                      &WPP_a3c4d1782baa35d2d3c4179a15ae3a1d_Traceguids,param_1,(char)lVar16);
          }
          uVar14 = *(uint *)(lVar16 + 0x38);
          *(uint *)(lVar16 + 0x38) = uVar14 | 0x20;
          if ((uVar14 & 2) != 0) {
LAB_1c000f33b:
                    /* WARNING: Subroutine does not return */
            KeBugCheck(0x22);
          }
        }
        uVar21 = uVar21 - 1;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_Dqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                   &WPP_a3c4d1782baa35d2d3c4179a15ae3a1d_Traceguids,iVar7,(char)param_1,(char)lVar16
                  );
      }
    } while ((param_6 & 0x8000) != 0);
  }
LAB_1c000f241:
  uVar11 = 0;
  if (*(int *)(puVar8 + 2) != 0) {
    do {
      if ((puVar8[uVar11 * 8 + 4] & 1) == 0) {
        if ((puVar8[uVar11 * 8 + 4] & 2) != 0) {
          if ((param_6 & 0x100) != 0) {
            LOCK();
            *(int *)(*(longlong *)(puVar8 + uVar11 * 8 + 8) + 0x60) =
                 *(int *)(*(longlong *)(puVar8 + uVar11 * 8 + 8) + 0x60) + -1;
            UNLOCK();
          }
          DereferenceDependencyContext(*(longlong *)(puVar8 + uVar11 * 8 + 8),'\x01','\0');
        }
      }
      else {
        DereferenceVolumeContext(*(longlong *)(puVar8 + uVar11 * 8 + 8));
      }
      uVar21 = (int)uVar11 + 1;
      uVar11 = (ulonglong)uVar21;
    } while (uVar21 < *(uint *)(puVar8 + 2));
    iVar7 = local_58;
  }
  ExFreePoolWithTag(puVar8,0x6c447044);
  *param_4 = 0;
LAB_1c000f3bc:
  if (param_5 == '\0') {
    ExReleaseResourceLite(&DAT_1c0005118);
    KeLeaveCriticalRegion();
  }
  return iVar7;
}



===== DepFSGetParentVolumeContext @ 1c000f408 =====

int DepFSGetParentVolumeContext(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  undefined8 uVar2;
  int iVar3;
  undefined8 local_res8;
  undefined8 local_res10;
  
  uVar2 = DAT_1c0005110;
  local_res10 = 0;
  plVar1 = (longlong *)(param_2 + 0x70);
  local_res8 = 0;
  if (*plVar1 == 0) {
    iVar3 = FltGetVolumeFromFileObject(DAT_1c0005110,*(undefined8 *)(param_2 + 0x68),&local_res10);
    if (iVar3 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                   &WPP_a3c4d1782baa35d2d3c4179a15ae3a1d_Traceguids,uVar2,
                   (char)*(undefined8 *)(param_2 + 0x68),(char)iVar3);
      }
    }
    else {
      iVar3 = FltGetVolumeInstanceFromName(uVar2,local_res10,0,&local_res8);
      if (iVar3 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                     &WPP_a3c4d1782baa35d2d3c4179a15ae3a1d_Traceguids,uVar2,
                     (char)*(undefined8 *)(param_2 + 0x68),(char)iVar3);
        }
      }
      else {
        iVar3 = FltGetInstanceContext(local_res8,plVar1);
        if (iVar3 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                       &WPP_a3c4d1782baa35d2d3c4179a15ae3a1d_Traceguids,uVar2,
                       (char)*(undefined8 *)(param_2 + 0x68),(char)iVar3);
          }
        }
        else {
          iVar3 = ReferenceVolumeContext(*plVar1,'\x01');
          if (iVar3 < 0) {
            FltReleaseContext();
          }
          else {
            DereferenceVolumeContext(*plVar1);
          }
        }
        FltObjectDereference(local_res8);
      }
      FltObjectDereference(local_res10);
    }
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}



===== DepFSIncrementActiveMountCount @ 1c000f5d4 =====

void DepFSIncrementActiveMountCount(longlong param_1)

{
  char cVar1;
  wchar_t local_18;
  wchar_t local_16;
  undefined4 local_14;
  undefined8 local_10;
  
  ExAcquirePushLockExclusiveEx(param_1 + 0xb8,0);
  if (*(int *)(param_1 + 0xc0) < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
              &WPP_a3c4d1782baa35d2d3c4179a15ae3a1d_Traceguids);
    }
    KeSetEvent(&DAT_1c0005200,0,0);
  }
  local_18 = *(wchar_t *)(param_1 + 0x8a);
  local_14 = 0;
  local_10 = *(undefined8 *)(param_1 + 0x90);
  local_16 = local_18;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    cVar1 = (char)*(undefined4 *)(param_1 + 0xc0);
    WPP_SF_qddZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                &WPP_a3c4d1782baa35d2d3c4179a15ae3a1d_Traceguids,param_1,cVar1,cVar1 + '\x01',
                &local_18);
  }
  *(int *)(param_1 + 0xc0) = *(int *)(param_1 + 0xc0) + 1;
  if (*(int *)(param_1 + 0xc0) == 1) {
    KeClearEvent(param_1 + 200);
  }
  ExReleasePushLockExclusiveEx(param_1 + 0xb8,0);
  return;
}



===== DepFSSendIoctl @ 1c000f710 =====

int DepFSSendIoctl(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                  undefined8 param_5,undefined4 param_6,undefined4 *param_7)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 local_38;
  longlong local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_38 = 0;
  local_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  lVar2 = IoGetAttachedDeviceReference();
  KeInitializeEvent(&local_28,0,0);
  lVar3 = IoBuildDeviceIoControlRequest
                    (0x2d118c,lVar2,param_3,4,param_5,param_6,0,&local_28,&local_38);
  if (lVar3 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    iVar1 = IofCallDriver(lVar2,lVar3);
    if (iVar1 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
      iVar1 = (int)local_38;
    }
    if (local_30 != 0) {
      *param_7 = (int)local_30;
    }
  }
  if (lVar2 != 0) {
    KeEnterCriticalRegion();
    ObfDereferenceObject(lVar2);
    KeLeaveCriticalRegion();
  }
  return iVar1;
}



===== DereferenceDependencyContext @ 1c000f850 =====

void DereferenceDependencyContext(longlong param_1,char param_2,char param_3)

{
  longlong *plVar1;
  int *piVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong *plVar5;
  code *pcVar6;
  undefined7 in_register_00000011;
  undefined1 *puVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  if (param_2 == '\0') {
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(&DAT_1c0005118,CONCAT71(in_register_00000011,1));
  }
  puVar7 = auStack_28;
  if ((param_3 == '\0') || (plVar1 = (longlong *)(param_1 + 0x28), (longlong *)*plVar1 == plVar1)) {
LAB_1c000f8d2:
    piVar2 = (int *)(param_1 + 0x38);
    *piVar2 = *piVar2 + -1;
    if (*piVar2 != 0) goto LAB_1c000f9f3;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_a3c4d1782baa35d2d3c4179a15ae3a1d_Traceguids,param_1);
    }
    if (*(longlong *)(param_1 + 0x80) != 0) {
      ObfDereferenceObject();
    }
    puVar7 = auStack_28;
    plVar1 = (longlong *)(param_1 + 8);
    plVar4 = (longlong *)*plVar1;
    if (plVar4 != plVar1) {
      if (((longlong *)plVar4[1] != plVar1) ||
         (plVar5 = *(longlong **)(param_1 + 0x10), (longlong *)*plVar5 != plVar1))
      goto LAB_1c000f96c;
      *plVar5 = (longlong)plVar4;
      plVar4[1] = (longlong)plVar5;
      *(longlong **)(param_1 + 0x10) = plVar1;
      *plVar1 = (longlong)plVar1;
    }
    while (plVar1 = *(longlong **)(param_1 + 0x18), plVar1 != (longlong *)(param_1 + 0x18)) {
      DepFSDeleteParentLink((longlong)(plVar1 + -5));
    }
  }
  else {
    DAT_1c0005180 = DAT_1c0005180 + -1;
    lVar3 = *plVar1;
    if ((*(longlong **)(lVar3 + 8) == plVar1) &&
       (plVar4 = *(longlong **)(param_1 + 0x30), (longlong *)*plVar4 == plVar1)) {
      *plVar4 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar4;
      *(longlong **)(param_1 + 0x30) = plVar1;
      *plVar1 = (longlong)plVar1;
      *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + -1;
      goto LAB_1c000f8d2;
    }
LAB_1c000f96c:
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)(3);
    puVar7 = auStack_20;
  }
  if (*(longlong *)(param_1 + 0x68) != 0) {
    *(undefined8 *)(puVar7 + -8) = 0x1c000f983;
    ObfDereferenceObject();
  }
  lVar3 = *(longlong *)(param_1 + 0x90);
  if (lVar3 != 0) {
    *(undefined8 *)(puVar7 + -8) = 0x1c000f9a0;
    ExFreePoolWithTag(lVar3,0x70527044);
  }
  lVar3 = *(longlong *)(param_1 + 0xa8);
  if (lVar3 != 0) {
    *(undefined8 *)(puVar7 + -8) = 0x1c000f9bd;
    ExFreePoolWithTag(lVar3,0x63417044);
  }
  lVar3 = *(longlong *)(param_1 + 0xa0);
  if (lVar3 != 0) {
    *(undefined8 *)(puVar7 + -8) = 0x1c000f9da;
    ExFreePoolWithTag(lVar3,0x64447044);
  }
  *(undefined8 *)(puVar7 + -8) = 0x1c000f9ee;
  ExFreePoolWithTag(param_1,0x63447044);
LAB_1c000f9f3:
  if (param_2 == '\0') {
    *(undefined8 *)(puVar7 + -8) = 0x1c000fa06;
    ExReleaseResourceLite(&DAT_1c0005118);
    *(undefined8 *)(puVar7 + -8) = 0x1c000fa12;
    KeLeaveCriticalRegion();
  }
  return;
}



===== DereferenceVolumeContext @ 1c000fa30 =====

void DereferenceVolumeContext(longlong param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = *(undefined8 *)(param_1 + 0x48);
  uVar2 = *(undefined8 *)(param_1 + 0x40);
  LOCK();
  *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) + -1;
  UNLOCK();
  FltReleaseContext();
  FltObjectDereference(uVar2);
  FltObjectDereference(uVar1);
  return;
}



===== ReferenceVolumeContext @ 1c000fa84 =====

int ReferenceVolumeContext(longlong param_1,char param_2)

{
  int iVar1;
  
  if (param_2 == '\0') {
    FltReferenceContext();
  }
  iVar1 = FltObjectReference(*(undefined8 *)(param_1 + 0x48));
  if (-1 < iVar1) {
    iVar1 = FltObjectReference(*(undefined8 *)(param_1 + 0x40));
    if (-1 < iVar1) {
      LOCK();
      *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) + 1;
      UNLOCK();
      return iVar1;
    }
    FltObjectDereference(*(undefined8 *)(param_1 + 0x48));
  }
  if (param_2 == '\0') {
    FltReleaseContext(param_1);
  }
  return iVar1;
}



===== DependentFSUnregister @ 1c000fb20 =====

undefined4
DependentFSUnregister
          (undefined8 param_1,undefined8 param_2,ulonglong param_3,undefined8 param_4,short *param_5
          )

{
  short *psVar1;
  undefined4 uVar2;
  int iVar3;
  
                    /* 0xfb20  10  DependentFSUnregister */
  uVar2 = 0;
  if (DAT_1c0005108 == 0) {
    uVar2 = 0xc0000184;
  }
  else if (DAT_1c0005196 == '\0') {
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(&DAT_1c0005118);
    psVar1 = param_5;
    if (((param_5 == (short *)0x0) || (*param_5 != 0x3030)) ||
       ((*(uint *)(param_5 + 0x2e) & 0x10) != 0)) {
      ExReleaseResourceLite(&DAT_1c0005118);
      KeLeaveCriticalRegion();
      uVar2 = 0xc000000d;
    }
    else {
      *(int *)(param_5 + 0x1c) = *(int *)(param_5 + 0x1c) + 1;
      LOCK();
      *(int *)(param_5 + 0x30) = *(int *)(param_5 + 0x30) + 1;
      UNLOCK();
      if ((param_3 & 1) != 0) {
        param_5 = (short *)0x0;
        iVar3 = DepFSGenerateDependencyList
                          ((longlong)psVar1,(undefined8 **)0x0,0,&param_5,'\x01',0x100);
        if (((iVar3 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29])
            ))) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                   &WPP_0b1a402d4649327a4c9cede05191c76b_Traceguids,iVar3);
        }
        if (param_5 != (short *)0x0) {
          DepFSDismountDependencyList((longlong)param_5,(longlong)psVar1,'\x01');
          ExFreePoolWithTag(param_5,0x6c447044);
          KeEnterCriticalRegion();
          ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
        }
      }
      if ((*(uint *)(psVar1 + 0x2e) & 0x10) == 0) {
        *(uint *)(psVar1 + 0x2e) = *(uint *)(psVar1 + 0x2e) | 0x10;
      }
      else {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                   &WPP_0b1a402d4649327a4c9cede05191c76b_Traceguids,psVar1);
        }
        uVar2 = 0xc000000d;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                  &WPP_0b1a402d4649327a4c9cede05191c76b_Traceguids,uVar2,(char)psVar1);
      }
      LOCK();
      *(int *)(psVar1 + 0x30) = *(int *)(psVar1 + 0x30) + -1;
      UNLOCK();
      DereferenceDependencyContext((longlong)psVar1,'\x01','\x01');
      ExReleaseResourceLite(&DAT_1c0005118);
      KeLeaveCriticalRegion();
    }
  }
  else {
    uVar2 = 0xc0000189;
  }
  return uVar2;
}



===== DepFSInstanceSetup @ 1c000fd70 =====

/* WARNING: Removing unreachable block (ram,0x0001c0010afd) */
/* WARNING: Removing unreachable block (ram,0x0001c0010606) */
/* WARNING: Removing unreachable block (ram,0x0001c0010613) */
/* WARNING: Removing unreachable block (ram,0x0001c0010647) */
/* WARNING: Removing unreachable block (ram,0x0001c00108ce) */
/* WARNING: Removing unreachable block (ram,0x0001c00108e9) */
/* WARNING: Removing unreachable block (ram,0x0001c00108f0) */
/* WARNING: Removing unreachable block (ram,0x0001c00108f6) */
/* WARNING: Removing unreachable block (ram,0x0001c001066f) */
/* WARNING: Removing unreachable block (ram,0x0001c00106a9) */
/* WARNING: Removing unreachable block (ram,0x0001c0010850) */
/* WARNING: Removing unreachable block (ram,0x0001c0010863) */
/* WARNING: Removing unreachable block (ram,0x0001c001086a) */
/* WARNING: Removing unreachable block (ram,0x0001c0010870) */
/* WARNING: Removing unreachable block (ram,0x0001c0010896) */
/* WARNING: Removing unreachable block (ram,0x0001c00106b7) */
/* WARNING: Removing unreachable block (ram,0x0001c00106ca) */
/* WARNING: Removing unreachable block (ram,0x0001c00106d1) */
/* WARNING: Removing unreachable block (ram,0x0001c00106d7) */
/* WARNING: Removing unreachable block (ram,0x0001c00106fe) */
/* WARNING: Removing unreachable block (ram,0x0001c0010708) */
/* WARNING: Removing unreachable block (ram,0x0001c000ffb3) */
/* WARNING: Removing unreachable block (ram,0x0001c001006a) */
/* WARNING: Removing unreachable block (ram,0x0001c00109d6) */
/* WARNING: Removing unreachable block (ram,0x0001c0010a3a) */
/* WARNING: Removing unreachable block (ram,0x0001c0010a46) */
/* WARNING: Removing unreachable block (ram,0x0001c0010a4d) */
/* WARNING: Removing unreachable block (ram,0x0001c0010a53) */
/* WARNING: Removing unreachable block (ram,0x0001c0010a79) */
/* WARNING: Removing unreachable block (ram,0x0001c00109f7) */
/* WARNING: Removing unreachable block (ram,0x0001c0010a04) */
/* WARNING: Removing unreachable block (ram,0x0001c0010a0b) */
/* WARNING: Removing unreachable block (ram,0x0001c0010a1b) */
/* WARNING: Removing unreachable block (ram,0x0001c0010a26) */
/* WARNING: Removing unreachable block (ram,0x0001c0010a30) */
/* WARNING: Removing unreachable block (ram,0x0001c0010c7c) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff68 : 0x0001c00104ac */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

ulonglong DepFSInstanceSetup(longlong param_1,undefined8 param_2,uint param_3,undefined4 *param_4)

{
  uint *puVar1;
  short *psVar2;
  undefined8 uVar3;
  code *pcVar4;
  int iVar5;
  longlong lVar6;
  ulonglong *puVar7;
  ulonglong *puVar8;
  short sVar9;
  undefined8 uVar10;
  ulonglong *puVar11;
  undefined1 *puVar12;
  byte bVar13;
  ulonglong uVar14;
  ulonglong **ppuVar15;
  undefined8 *puVar16;
  undefined8 *puVar17;
  undefined **ppuVar18;
  int iVar19;
  uint uVar20;
  ulonglong uVar21;
  undefined1 auStackY_b8 [8];
  undefined1 auStackY_b0 [24];
  uint local_78;
  undefined1 local_68;
  uint local_64;
  undefined4 local_60;
  byte local_5c;
  undefined4 local_50;
  uint local_4c;
  undefined4 local_48;
  undefined4 local_44;
  ulonglong *local_40;
  undefined **local_38;
  ulonglong *local_30;
  
  local_5c = 0;
  local_68 = 0;
  iVar5 = 0;
  local_30 = (ulonglong *)0x0;
  lVar6 = 0;
  local_40 = (ulonglong *)0x0;
  local_48 = 0;
  local_50 = 0;
  local_44 = 0;
  local_38 = (undefined **)0x0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_6b5a76be7742304abc77e760f08b1d6f_Traceguids,*(undefined8 *)(param_1 + 0x10),
              (char)*(undefined8 *)(param_1 + 0x18));
  }
  uVar14 = 0xc01c000f;
  if (DAT_1c0005194 == '\0') {
    if ((DAT_1c0005195 != '\0') || (DAT_1c0005196 != '\0')) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29])))
         ) {
        sVar9 = (short)&uRam0000000000000008 + 4;
        goto LAB_1c0010aca;
      }
      goto LAB_1c0010ae7;
    }
    uVar20 = (uint)param_4;
    if ((uVar20 < 0x1d) && ((0x1040003cU >> (uVar20 & 0x1f) & 1) != 0)) {
      local_68 = 1;
    }
    if ((param_3 < 0x25) && ((0x100000018cU >> ((ulonglong)param_3 & 0x3f) & 1) != 0)) {
      local_78 = FltGetDiskDeviceObject(*(undefined8 *)(param_1 + 0x10));
      uVar14 = (ulonglong)local_78;
      if (-1 < (int)local_78) {
        local_64 = (undefined4)uRam0000000000000048;
        local_60 = uRam0000000000000030._4_4_;
        goto LAB_1c000ff28;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        sVar9 = (short)&uRam0000000000000008 + 5;
LAB_1c000fef7:
        WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),sVar9,
                  &WPP_6b5a76be7742304abc77e760f08b1d6f_Traceguids,*(undefined8 *)(param_1 + 0x10),
                  (char)local_78);
      }
      goto LAB_1c0010af1;
    }
    local_64 = 0;
    local_60 = 0;
LAB_1c000ff28:
    iVar19 = 0;
    bVar13 = 0;
    if (param_3 == 0x14) {
LAB_1c00100e5:
      local_5c = bVar13;
      iVar5 = iVar19;
      if (uVar20 == 1) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((byte)((byte)param_4 & (byte)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c)) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                    &WPP_6b5a76be7742304abc77e760f08b1d6f_Traceguids,*(undefined8 *)(param_1 + 0x10)
                    ,(char)*(undefined8 *)(param_1 + 0x18));
        }
        uVar14 = 0xc01c000f;
        local_78 = 0xc01c000f;
        goto LAB_1c0010af1;
      }
    }
    else if (uVar20 != 0x1b) {
      ppuVar15 = &local_40;
      local_78 = FltOpenVolume(*(undefined8 *)(param_1 + 0x18));
      uVar14 = (ulonglong)local_78;
      if ((int)local_78 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          sVar9 = (short)&uRam0000000000000008 + 6;
          goto LAB_1c000fef7;
        }
        goto LAB_1c0010af1;
      }
      puVar17 = &uRam0000000000000048;
      bVar13 = (byte)((uint)*(undefined4 *)(*(longlong *)(local_40[2] + 0x10) + 0x30) >> 8) & 1;
      do {
        if (lVar6 != 0) {
          puVar16 = *(undefined8 **)(lVar6 + 8);
          uVar10 = 0x72517044;
          ExFreePoolWithTag(lVar6);
          lVar6 = 0;
          puVar17 = (undefined8 *)((ulonglong)puVar16 & 0xffffffff);
          if (puVar16 != puVar17) {
            uVar14 = 0xc000009a;
            local_78 = 0xc000009a;
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_qi(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,ppuVar15,
                        *(undefined8 *)(param_1 + 0x10),(char)puVar16);
            }
            goto LAB_1c0010af1;
          }
        }
        lVar6 = ExAllocatePool2(0x100);
        iVar19 = 0;
        if (lVar6 == 0) {
          uVar14 = 0xc000009a;
          local_78 = 0xc000009a;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                      &WPP_6b5a76be7742304abc77e760f08b1d6f_Traceguids,
                      *(undefined8 *)(param_1 + 0x10),(char)puVar17);
          }
          goto LAB_1c0010af1;
        }
        local_48 = 3;
        ppuVar15 = (ulonglong **)0x2d118c;
        iVar5 = FltDeviceIoControlFile(*(undefined8 *)(param_1 + 0x18));
      } while (iVar5 == -0x7ffffffb);
      if (iVar5 < 0) {
        *(undefined4 *)(lVar6 + 4) = 0;
        if (((iVar5 != -0x3ffffff0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29])
            ))) {
          WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                    &WPP_6b5a76be7742304abc77e760f08b1d6f_Traceguids,*(undefined8 *)(param_1 + 0x10)
                    ,(char)iVar5);
        }
      }
      else {
        iVar19 = *(int *)(lVar6 + 4);
      }
      goto LAB_1c00100e5;
    }
    puVar12 = auStackY_b8;
    FltGetVolumeName(*(undefined8 *)(param_1 + 0x10));
    local_78 = FltObjectReference(*(undefined8 *)(param_1 + 0x10));
    uVar14 = (ulonglong)local_78;
    if ((int)local_78 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        sVar9 = (short)&uRam0000000000000010 + 4;
LAB_1c001027a:
        WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),sVar9,
                   &WPP_6b5a76be7742304abc77e760f08b1d6f_Traceguids,*(undefined8 *)(param_1 + 0x10),
                   (char)*(undefined8 *)(param_1 + 0x18),(char)uVar14);
      }
      goto LAB_1c0010af1;
    }
    local_78 = FltObjectReference(*(undefined8 *)(param_1 + 0x18));
    uVar14 = (ulonglong)local_78;
    if ((int)local_78 < 0) {
      FltObjectDereference(*(undefined8 *)(param_1 + 0x10));
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        sVar9 = (short)&uRam0000000000000010 + 3;
        goto LAB_1c001027a;
      }
      goto LAB_1c0010af1;
    }
    local_78 = FltAllocateContext(*(undefined8 *)(param_1 + 8));
    uVar14 = (ulonglong)local_78;
    if ((int)local_78 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                   &WPP_6b5a76be7742304abc77e760f08b1d6f_Traceguids,*(undefined8 *)(param_1 + 0x10),
                   (char)*(undefined8 *)(param_1 + 0x18),(char)local_78);
      }
      FltObjectDereference(*(undefined8 *)(param_1 + 0x18));
      FltObjectDereference(*(undefined8 *)(param_1 + 0x10));
      goto LAB_1c0010af1;
    }
    memset((void *)0x0,0,0x98);
    uRam0000000000000000 = 0x3020;
    uRam0000000000000002 = 0x98;
    uRam0000000000000040 = *(undefined8 *)(param_1 + 0x18);
    uRam0000000000000048 = *(undefined8 *)(param_1 + 0x10);
    LOCK();
    iRam0000000000000074 = iRam0000000000000074 + 1;
    UNLOCK();
    puVar7 = (ulonglong *)0x0;
    uRam000000000000005c = local_68;
    uRam0000000000000070 = local_60;
    uRam0000000000000058 = local_64;
    uRam0000000000000088 = 0x90;
    uRam0000000000000080 = 0;
    uRam0000000000000082 = (undefined2)local_50;
    if (local_5c != 0) {
      uRam0000000000000038 = uRam0000000000000038 | 2;
    }
    uRam0000000000000050 = uVar20;
    uRam0000000000000054 = param_3;
    FltGetVolumeName(*(undefined8 *)(param_1 + 0x10),0x80,&local_50);
    puRam0000000000000020 = &uRam0000000000000018;
    uRam0000000000000018 = 0x18;
    uRam0000000000000030 = 0x28;
    uRam0000000000000028 = 0x28;
    uRam0000000000000010 = 8;
    uRam0000000000000008 = 8;
    local_78 = FltSetInstanceContext(*(undefined8 *)(param_1 + 0x18));
    uVar14 = (ulonglong)local_78;
    if ((int)local_78 < 0) {
      ppuVar18 = &WPP_GLOBAL_Control;
      puVar12 = auStackY_b8;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (puVar12 = auStackY_b8, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (puVar12 = auStackY_b8, 1 < (byte)WPP_GLOBAL_Control[0x29])) {
        ppuVar18 = &WPP_GLOBAL_Control;
        puVar7 = (ulonglong *)0x0;
        WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                   &WPP_6b5a76be7742304abc77e760f08b1d6f_Traceguids,*(undefined8 *)(param_1 + 0x10),
                   (char)*(undefined8 *)(param_1 + 0x18),(char)local_78);
        puVar12 = auStackY_b8;
      }
      goto LAB_1c0010af4;
    }
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
    if (iVar5 != 0) {
      uVar20 = 0;
      local_64 = 0;
      uVar21 = 0;
      local_4c = 0;
      if (*(int *)(lVar6 + 4) != 0) {
        do {
          ppuVar18 = *(undefined ***)(lVar6 + (uVar21 + 1) * 0x30);
          if (((ppuVar18 == (undefined **)0x0) || (*(short *)ppuVar18 != 0x3030)) ||
             ((*(uint *)((longlong)ppuVar18 + 0x5c) & 0x10) != 0)) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                         &WPP_6b5a76be7742304abc77e760f08b1d6f_Traceguids,
                         *(undefined8 *)(param_1 + 0x10),(char)*(undefined8 *)(param_1 + 0x18),
                         (char)ppuVar18);
              uVar20 = local_64;
            }
          }
          else {
            puVar7 = (ulonglong *)ExAllocatePool2(0x100);
            if (puVar7 == (ulonglong *)0x0) {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                           &WPP_6b5a76be7742304abc77e760f08b1d6f_Traceguids,
                           *(undefined8 *)(param_1 + 0x10),(char)*(undefined8 *)(param_1 + 0x18),
                           0x9a);
              }
              local_78 = 0xc000009a;
              uVar14 = 0xc000009a;
              ExReleaseResourceLite(&DAT_1c0005118);
              KeLeaveCriticalRegion();
              goto LAB_1c0010af1;
            }
            *(undefined4 *)puVar7 = 0x383050;
            puVar11 = puVar7 + 5;
            puVar7[1] = (ulonglong)ppuVar18;
            local_64 = local_64 + 1;
            puVar16 = (undefined8 *)(ulonglong)local_64;
            puVar17 = (undefined8 *)ppuVar18[4];
            if ((undefined **)*puVar17 != ppuVar18 + 3) goto LAB_1c001097f;
            *puVar11 = (ulonglong)(ppuVar18 + 3);
            puVar7[6] = (ulonglong)puVar17;
            *puVar17 = puVar11;
            ppuVar18[4] = (undefined *)puVar11;
            puVar8 = puVar7 + 3;
            puVar7[2] = 0;
            puVar11 = puRam0000000000000020;
            if (*puRam0000000000000020 != 0x18) goto LAB_1c001097f;
            *puVar8 = 0x18;
            puVar7[4] = (ulonglong)puRam0000000000000020;
            *puRam0000000000000020 = (ulonglong)puVar8;
            puRam0000000000000020 = puVar8;
            if (((ppuVar18[0x15] != (undefined *)0x0) && (*(int *)(ppuVar18 + 0x16) != 0)) &&
               (local_38 == (undefined **)0x0)) {
              *(int *)(ppuVar18 + 7) = *(int *)(ppuVar18 + 7) + 1;
              *(uint *)((longlong)ppuVar18 + 0x5c) = *(uint *)((longlong)ppuVar18 + 0x5c) | 0x100;
              local_38 = ppuVar18;
            }
            if (local_5c != 0) {
              *(uint *)((longlong)ppuVar18 + 0x3c) = *(uint *)((longlong)ppuVar18 + 0x3c) | 0x10;
              if (ppuVar18[0xe] != (undefined *)0x0) {
                puVar1 = (uint *)(ppuVar18[0xe] + 0x38);
                *puVar1 = *puVar1 | 2;
              }
            }
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_qqqqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar11,(ulonglong)local_64,
                           *(undefined8 *)(param_1 + 0x10),(char)*(undefined8 *)(param_1 + 0x18),
                           (char)puVar7,0,(char)ppuVar18);
            }
            uVar20 = local_64;
          }
          local_4c = (int)uVar21 + 1;
          uVar21 = (ulonglong)local_4c;
        } while (local_4c < *(uint *)(lVar6 + 4));
        if ((((*(uint *)(lVar6 + 4) != 0) && (uVar20 == 0)) &&
            ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29])
            ))) {
          WPP_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                     &WPP_6b5a76be7742304abc77e760f08b1d6f_Traceguids,
                     *(undefined8 *)(param_1 + 0x10),(char)*(undefined8 *)(param_1 + 0x18),0);
        }
      }
    }
    ppuVar18 = &WPP_GLOBAL_Control;
    puVar7 = (ulonglong *)0x0;
    puVar16 = &DAT_1c00051a0;
    puVar8 = &uRam0000000000000028;
    puVar11 = DAT_1c00051a8;
    if ((undefined8 *)*DAT_1c00051a8 != &DAT_1c00051a0) {
LAB_1c001097f:
      pcVar4 = (code *)swi(0x29);
      puVar8 = (ulonglong *)(*pcVar4)(3);
      puVar12 = auStackY_b0;
    }
    *puVar8 = (ulonglong)puVar16;
    puVar8[1] = (ulonglong)puVar11;
    *puVar11 = (ulonglong)puVar8;
    DAT_1c0005190 = DAT_1c0005190 + 1;
    *(undefined8 *)(puVar12 + -8) = 0x1c00109ab;
    DAT_1c00051a8 = puVar8;
    ExReleaseResourceLite(&DAT_1c0005118);
    *(undefined8 *)(puVar12 + -8) = 0x1c00109b7;
    KeLeaveCriticalRegion();
    if (local_38 == (undefined **)0x0) goto LAB_1c0010af4;
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      sVar9 = (short)&uRam0000000000000008 + 3;
LAB_1c0010aca:
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),sVar9,
                &WPP_6b5a76be7742304abc77e760f08b1d6f_Traceguids,*(undefined8 *)(param_1 + 0x10),
                (char)*(undefined8 *)(param_1 + 0x18));
    }
LAB_1c0010ae7:
    local_78 = 0xc01c000f;
LAB_1c0010af1:
    ppuVar18 = &WPP_GLOBAL_Control;
    puVar7 = (ulonglong *)0x0;
    puVar12 = auStackY_b8;
LAB_1c0010af4:
    if (local_38 == (undefined **)0x0) goto LAB_1c0010b23;
  }
  *(undefined8 *)(puVar12 + -8) = 0x1c0010b23;
  DereferenceDependencyContext((longlong)local_38,'\0','\0');
LAB_1c0010b23:
  if (lVar6 == 0) {
    if ((param_3 - 7 < 2) || (param_3 == 0x24)) {
      if (((undefined **)WPP_GLOBAL_Control != ppuVar18) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29])))
         ) {
        uVar10 = *(undefined8 *)(param_1 + 0x10);
        uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        *(undefined8 *)(puVar12 + 0x20) = *(undefined8 *)(param_1 + 0x18);
        *(undefined8 *)(puVar12 + -8) = 0x1c0010c2d;
        WPP_SF_qq(uVar3,0x20,&WPP_6b5a76be7742304abc77e760f08b1d6f_Traceguids,uVar10,puVar12[0x20]);
      }
      *(undefined8 *)(puVar12 + -8) = 0x1c0010c40;
      KeSetEvent(&DAT_1c0005200,0,0);
    }
  }
  else {
    *(undefined8 *)(puVar12 + -8) = 0x1c0010b33;
    KeEnterCriticalRegion();
    *(undefined8 *)(puVar12 + -8) = 0x1c0010b48;
    ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
    uVar21 = (ulonglong)puVar7 & 0xffffffff;
    if ((uint)puVar7 < *(uint *)(lVar6 + 4)) {
      do {
        psVar2 = *(short **)(lVar6 + (uVar21 + 1) * 0x30);
        if ((psVar2 != (short *)0x0) && (*psVar2 == 0x3030)) {
          if ((param_3 - 7 < 2) || (param_3 == 0x24)) {
            *(undefined8 *)(puVar12 + -8) = 0x1c0010b90;
            DepFSDecrementActiveMountCount((longlong)psVar2);
          }
          *(undefined8 *)(puVar12 + -8) = 0x1c0010b9d;
          DereferenceDependencyContext((longlong)psVar2,'\x01','\0');
        }
        uVar20 = (int)uVar21 + 1;
        uVar21 = (ulonglong)uVar20;
      } while (uVar20 < *(uint *)(lVar6 + 4));
      uVar14 = (ulonglong)local_78;
    }
    *(undefined8 *)(puVar12 + -8) = 0x1c0010bbb;
    ExReleaseResourceLite(&DAT_1c0005118);
    *(undefined8 *)(puVar12 + -8) = 0x1c0010bc7;
    KeLeaveCriticalRegion();
    *(undefined8 *)(puVar12 + -8) = 0x1c0010bdb;
    ExFreePoolWithTag(lVar6,0x72517044);
  }
  if (local_30 != puVar7) {
    *(undefined8 *)(puVar12 + -8) = 0x1c0010c56;
    ObfDereferenceObject(local_40);
    *(undefined8 *)(puVar12 + -8) = 0x1c0010c6a;
    local_40 = puVar7;
    FltClose(local_30);
    local_30 = puVar7;
  }
  if ((int)uVar14 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar10 = *(undefined8 *)(param_1 + 0x10);
      uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      *(undefined8 *)(puVar12 + 0x20) = *(undefined8 *)(param_1 + 0x18);
      *(undefined8 *)(puVar12 + -8) = 0x1c0010d0b;
      WPP_SF_qq(uVar3,0x22,&WPP_6b5a76be7742304abc77e760f08b1d6f_Traceguids,uVar10,puVar12[0x20]);
    }
    uVar14 = 0xc01c000f;
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar10 = *(undefined8 *)(param_1 + 0x10);
    uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(undefined8 *)(puVar12 + 0x20) = *(undefined8 *)(param_1 + 0x18);
    *(undefined8 *)(puVar12 + -8) = 0x1c0010cc7;
    WPP_SF_qq(uVar3,0x21,&WPP_6b5a76be7742304abc77e760f08b1d6f_Traceguids,uVar10,puVar12[0x20]);
  }
  return uVar14;
}



===== DepFSCleanupVolumeContext @ 1c0010d38 =====

void DepFSCleanupVolumeContext(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  longlong *plVar6;
  
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
  while (plVar1 = *(longlong **)(param_1 + 0x18), plVar1 != (longlong *)(param_1 + 0x18)) {
    DepFSDeleteParentLink((longlong)(plVar1 + -3));
  }
  plVar1 = (longlong *)(param_1 + 8);
  plVar6 = (longlong *)*plVar1;
  if ((longlong *)*plVar1 != plVar1) {
    do {
      plVar2 = (longlong *)*plVar6;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                  &WPP_f74f0f1428a330a1ddba74e336bf7301_Traceguids,plVar6 + -1,(char)param_1);
      }
      plVar6[0xd] = 0;
      lVar3 = *plVar6;
      if ((*(longlong **)(lVar3 + 8) != plVar6) ||
         (plVar4 = (longlong *)plVar6[1], (longlong *)*plVar4 != plVar6)) goto LAB_1c0010ecf;
      *plVar4 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar4;
      plVar6[1] = (longlong)plVar6;
      *plVar6 = (longlong)plVar6;
      plVar6 = plVar2;
    } while (plVar2 != plVar1);
    *(longlong **)(param_1 + 0x10) = plVar1;
    *plVar1 = (longlong)plVar1;
  }
  plVar1 = (longlong *)(param_1 + 0x28);
  if ((longlong *)*plVar1 != plVar1) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
               &WPP_f74f0f1428a330a1ddba74e336bf7301_Traceguids,param_1);
    }
    lVar3 = *plVar1;
    if ((*(longlong **)(lVar3 + 8) != plVar1) ||
       (plVar6 = *(longlong **)(param_1 + 0x30), (longlong *)*plVar6 != plVar1)) {
LAB_1c0010ecf:
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    *plVar6 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar6;
    *(longlong **)(param_1 + 0x30) = plVar1;
    *plVar1 = (longlong)plVar1;
    DAT_1c0005190 = DAT_1c0005190 + -1;
  }
  if (*(longlong *)(param_1 + 0x78) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x78),0x73447044);
    *(undefined8 *)(param_1 + 0x78) = 0;
  }
  ExReleaseResourceLite(&DAT_1c0005118);
  KeLeaveCriticalRegion();
  return;
}



===== DepFSContextCleanup @ 1c0010ee0 =====

void DepFSContextCleanup(longlong param_1,short param_2)

{
  if (param_2 == 2) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_f74f0f1428a330a1ddba74e336bf7301_Traceguids,param_1);
    }
    DepFSCleanupVolumeContext(param_1);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_f74f0f1428a330a1ddba74e336bf7301_Traceguids,param_1);
    }
  }
  return;
}



===== DepFSInstanceQueryTeardown @ 1c0010f80 =====

int DepFSInstanceQueryTeardown(longlong param_1)

{
  int iVar1;
  longlong *plVar2;
  undefined7 uVar3;
  longlong local_res8;
  
  local_res8 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
             &WPP_f74f0f1428a330a1ddba74e336bf7301_Traceguids,*(undefined8 *)(param_1 + 0x18));
  }
  plVar2 = &local_res8;
  iVar1 = FltGetInstanceContext(*(undefined8 *)(param_1 + 0x18),plVar2);
  if (-1 < iVar1) {
    uVar3 = (undefined7)((ulonglong)plVar2 >> 8);
    iVar1 = ReferenceVolumeContext(local_res8,'\x01');
    if (iVar1 < 0) {
      FltReleaseContext(local_res8);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                  &WPP_f74f0f1428a330a1ddba74e336bf7301_Traceguids,*(undefined8 *)(param_1 + 0x18),
                  (char)iVar1);
      }
    }
    else {
      KeEnterCriticalRegion();
      ExAcquireResourceExclusiveLite(&DAT_1c0005118,CONCAT71(uVar3,1));
      if ((*(longlong **)(local_res8 + 8) != (longlong *)(local_res8 + 8)) ||
         ((*(uint *)(local_res8 + 0x38) & 2) != 0)) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0 &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])))) {
          WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                    &WPP_f74f0f1428a330a1ddba74e336bf7301_Traceguids,local_res8,
                    (char)*(undefined4 *)(local_res8 + 0x38));
        }
        iVar1 = -0x3fe3fff0;
      }
      ExReleaseResourceLite(&DAT_1c0005118);
      KeLeaveCriticalRegion();
      DereferenceVolumeContext(local_res8);
      if (-1 < iVar1) {
        return iVar1;
      }
    }
  }
  return -0x3fe3fff0;
}



===== DepFSInstanceTeardownComplete @ 1c0011110 =====

void DepFSInstanceTeardownComplete(longlong param_1)

{
  int iVar1;
  longlong local_res8;
  
  local_res8 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
             &WPP_f74f0f1428a330a1ddba74e336bf7301_Traceguids,*(undefined8 *)(param_1 + 0x18));
  }
  iVar1 = FltGetInstanceContext(*(undefined8 *)(param_1 + 0x18),&local_res8);
  if (-1 < iVar1) {
    iVar1 = ReferenceVolumeContext(local_res8,'\x01');
    DepFSCleanupVolumeContext(local_res8);
    if (iVar1 < 0) {
      FltReleaseContext();
    }
    else {
      DereferenceVolumeContext(local_res8);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
             &WPP_f74f0f1428a330a1ddba74e336bf7301_Traceguids,*(undefined8 *)(param_1 + 0x18));
  }
  return;
}



===== DepFSInstanceTeardownStart @ 1c0011200 =====

void DepFSInstanceTeardownStart(longlong param_1)

{
  int iVar1;
  longlong *plVar2;
  undefined7 uVar3;
  longlong local_res8;
  
  local_res8 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
             &WPP_f74f0f1428a330a1ddba74e336bf7301_Traceguids,*(undefined8 *)(param_1 + 0x18));
  }
  plVar2 = &local_res8;
  iVar1 = FltGetInstanceContext(*(undefined8 *)(param_1 + 0x18),plVar2);
  if (-1 < iVar1) {
    uVar3 = (undefined7)((ulonglong)plVar2 >> 8);
    iVar1 = ReferenceVolumeContext(local_res8,'\x01');
    if (iVar1 < 0) {
      FltReleaseContext(local_res8);
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                  &WPP_f74f0f1428a330a1ddba74e336bf7301_Traceguids,*(undefined8 *)(param_1 + 0x18),
                  (char)iVar1);
      }
    }
    else {
      KeEnterCriticalRegion();
      ExAcquireResourceExclusiveLite(&DAT_1c0005118,CONCAT71(uVar3,1));
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                  &WPP_f74f0f1428a330a1ddba74e336bf7301_Traceguids,local_res8,
                  (char)*(undefined4 *)(local_res8 + 0x38));
      }
      *(uint *)(local_res8 + 0x38) = *(uint *)(local_res8 + 0x38) | 0x20;
      iVar1 = DepFSNotifyChildren(local_res8);
      ExReleaseResourceLite(&DAT_1c0005118);
      KeLeaveCriticalRegion();
      DereferenceVolumeContext(local_res8);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
              &WPP_f74f0f1428a330a1ddba74e336bf7301_Traceguids,*(undefined8 *)(param_1 + 0x18),
              (char)iVar1);
  }
  return;
}



===== DepFSNotifyChildren @ 1c00113b8 =====

int DepFSNotifyChildren(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  int iVar7;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  
  iVar7 = 0;
  puVar5 = (undefined8 *)(param_1 + 8);
  if (param_1 == 0) {
    puVar5 = &DAT_1c00051b0;
  }
  puVar6 = (undefined8 *)*puVar5;
  if (puVar6 != puVar5) {
    iVar7 = 0;
    do {
      lVar4 = (longlong)puVar6 - ((-(ulonglong)(param_1 != 0) & 0xffffffffffffffe0) + 0x28);
      if ((*(longlong **)(lVar4 + 0x28) == (longlong *)(lVar4 + 0x28)) ||
         ((*(uint *)(lVar4 + 0x5c) & 3) != 0)) {
        puVar6 = (undefined8 *)*puVar6;
      }
      else {
        local_20 = 0;
        local_58 = 0;
        uStack_50 = 0;
        local_30 = 0;
        uStack_28 = 0;
        local_48 = *(undefined8 *)(lVar4 + 0x68);
        uStack_40 = *(undefined8 *)(lVar4 + 0x78);
        local_38 = 1;
        for (puVar3 = DAT_1c00051b0; (undefined8 **)puVar3 != &DAT_1c00051b0;
            puVar3 = (undefined8 *)*puVar3) {
          if (puVar3[0xb] == *(longlong *)(lVar4 + 0x80)) {
            *(uint *)((longlong)puVar3 + 0x34) = *(uint *)((longlong)puVar3 + 0x34) | 0x20;
          }
        }
        KeInitializeEvent(&local_30,0,0);
        lVar2 = IoBuildDeviceIoControlRequest
                          (0x2d9194,*(undefined8 *)(lVar4 + 0x80),&local_48,0x18,0,0,0,&local_30,
                           &local_58);
        if (lVar2 == 0) {
          puVar6 = (undefined8 *)*puVar6;
          iVar7 = -0x3fffff66;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                     &WPP_f74f0f1428a330a1ddba74e336bf7301_Traceguids,lVar4);
          }
          *(uint *)(lVar4 + 0x5c) = *(uint *)(lVar4 + 0x5c) | 2;
        }
        else {
          *(uint *)(lVar4 + 0x5c) = *(uint *)(lVar4 + 0x5c) | 1;
          *(int *)(lVar4 + 0x38) = *(int *)(lVar4 + 0x38) + 1;
          ExReleaseResourceLite(&DAT_1c0005118);
          KeLeaveCriticalRegion();
          iVar1 = IofCallDriver(*(undefined8 *)(lVar4 + 0x80),lVar2);
          if (iVar1 == 0x103) {
            KeWaitForSingleObject(&local_30,0,0,0,0);
            iVar1 = (int)local_58;
          }
          KeEnterCriticalRegion();
          ExAcquireResourceExclusiveLite(&DAT_1c0005118,1);
          if ((((iVar1 < 0) &&
               (iVar7 = iVar1, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                      &WPP_f74f0f1428a330a1ddba74e336bf7301_Traceguids,lVar4,(char)iVar1);
          }
          DereferenceDependencyContext(lVar4,'\x01','\0');
          puVar6 = (undefined8 *)*puVar5;
        }
      }
    } while (puVar6 != puVar5);
  }
  return iVar7;
}



===== entry @ 1c0013010 =====

void entry(undefined8 param_1,undefined8 *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 1c0013044 =====

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



===== DriverEntry @ 1c0013078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DriverEntry(undefined8 param_1,undefined8 *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStack_e8 [32];
  undefined4 local_c8;
  undefined4 *local_c0;
  undefined4 local_b8 [2];
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
  undefined8 *local_80;
  undefined4 local_78;
  undefined4 local_74;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined1 local_40 [12];
  int local_34;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_e8;
  local_8c = 0;
  local_74 = 0;
  local_b0 = 0;
  local_b8[0] = 0;
  local_a0 = 0;
  uStack_98 = 0;
  uVar3 = 0;
  local_50 = 0;
  uStack_48 = 0;
  memset(&DAT_1c0005104,0,0x114);
  _Globals = 0x1183010;
  ExInitializeResourceLite(&DAT_1c0005118);
  DAT_1c00051a8 = &DAT_1c00051a0;
  DAT_1c00051a0 = &DAT_1c00051a0;
  DAT_1c00051b8 = &DAT_1c00051b0;
  DAT_1c00051b0 = &DAT_1c00051b0;
  KeInitializeEvent(&DAT_1c0005200,0,0);
  DAT_1c0005228 = &WPP_ThisDir_CTLGUID_VdrvRootTraceGuid;
  DAT_1c00051c4 = 1;
  _WPP_MAIN_CB = 0;
  DAT_1c0005230 = 0;
  _DAT_1c0005240 = 0;
  _DAT_1c0005248 = 1;
  DAT_1c0005108 = param_1;
  WppLoadTracingSupport();
  _DAT_1c0005240 = 0;
  WppInitKm();
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_6e0896578ce0378c051a248e53d8716f_Traceguids);
  }
  RtlInitUnicodeString
            (&local_50,
             L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\FileSystem\\GroupPolicyKeys"
            );
  DAT_1c00051c0 = FsRtlQueryMaximumVirtualDiskNestingLevel();
LAB_1c00131f4:
  do {
    local_90 = 0x30;
    uVar3 = uVar3 + 1;
    local_88 = 0;
    local_78 = 0x240;
    local_80 = &local_50;
    if (uVar3 == 1) {
      local_80 = param_2;
    }
    local_70 = 0;
    uStack_68 = 0;
    iVar2 = ZwOpenKey(&local_b0,0x20019,&local_90);
    if (-1 < iVar2) {
      if (uVar3 == 1) {
        local_a8 = 0;
        local_60 = 0;
        uStack_58 = 0;
        RtlInitUnicodeString(&local_60,L"Parameters");
        local_88 = local_b0;
        local_80 = &local_60;
        local_90 = 0x30;
        local_78 = 0x240;
        local_70 = 0;
        uStack_68 = 0;
        iVar2 = ZwOpenKey(&local_a8,0x20019,&local_90);
        ZwClose(local_b0);
        local_b0 = local_a8;
        if (iVar2 < 0) goto LAB_1c00131f4;
      }
      RtlInitUnicodeString(&local_a0,L"VirtualDiskNoLocalMount");
      local_c0 = local_b8;
      local_c8 = 0x14;
      iVar2 = ZwQueryValueKey(local_b0,&local_a0,2,local_40);
      if (-1 < iVar2) {
        DAT_1c000519a = local_34 != 0;
      }
      if (((uVar3 == 1) && (*KdDebuggerEnabled_exref != (code)0x0)) &&
         (*KdDebuggerNotPresent_exref == (code)0x0)) {
        RtlInitUnicodeString(&local_a0,L"RelaxedTestMode");
        local_c0 = local_b8;
        local_c8 = 0x14;
        iVar2 = ZwQueryValueKey(local_b0,&local_a0,2,local_40);
        if (-1 < iVar2) {
          DAT_1c000519c = local_34 != 0;
        }
      }
      RtlInitUnicodeString(&local_a0,L"VirtualDiskExpandOnMount");
      local_c0 = local_b8;
      local_c8 = 0x14;
      iVar2 = ZwQueryValueKey(local_b0,&local_a0,2,local_40);
      if (((-1 < iVar2) && ((local_34 - 1U & 0xfffffffc) == 0)) && (local_34 != 3)) {
        DAT_1c00051c4 = local_34;
      }
      if (uVar3 == 1) {
        local_a8 = 0;
        local_60 = 0;
        uStack_58 = 0;
        RtlInitUnicodeString(&local_60,L"AccessControl");
        local_88 = local_b0;
        local_80 = &local_60;
        local_90 = 0x30;
        local_78 = 0x240;
        local_70 = 0;
        uStack_68 = 0;
        iVar2 = ZwOpenKey(&local_a8,0x20019,&local_90);
        if (-1 < iVar2) {
          RtlInitUnicodeString(&local_a0,L"ISOMountAllowNormalUser");
          local_c0 = local_b8;
          local_c8 = 0x14;
          iVar2 = ZwQueryValueKey(local_a8,&local_a0,2,local_40);
          if (-1 < iVar2) {
            DAT_1c000519b = local_34 != 0;
          }
          ZwClose(local_a8);
        }
      }
      ZwClose(local_b0);
    }
    if (1 < uVar3) {
      cVar1 = FsRtlAreVolumeStartupApplicationsComplete();
      if (cVar1 == '\0') {
        FsDepRegisterUnregisterForBugchecks('\x01','\0');
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_6e0896578ce0378c051a248e53d8716f_Traceguids);
      }
      return 0;
    }
  } while( true );
}


