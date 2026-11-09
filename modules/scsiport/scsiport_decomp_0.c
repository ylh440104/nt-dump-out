
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



===== __C_specific_handler @ 140001036 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140001036. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== _wcsnicmp @ 140001048 =====

int __cdecl _wcsnicmp(wchar_t *_Str1,wchar_t *_Str2,size_t _MaxCount)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140001048. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _wcsnicmp(_Str1,_Str2,_MaxCount);
  return iVar1;
}



===== __cpu_features_init @ 140001060 =====

/* WARNING: Removing unreachable block (ram,0x0001400010ca) */
/* WARNING: Removing unreachable block (ram,0x000140001079) */
/* WARNING: Removing unreachable block (ram,0x00014000106a) */

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



===== SpIsAdapterControlTypeSupported @ 140001128 =====

void SpIsAdapterControlTypeSupported(longlong param_1,undefined8 param_2)

{
  RtlAreBitsSet(param_1 + 0x2c8,param_2,1);
  return;
}



===== ScsiPortDispatchUnimplemented @ 140001160 =====

undefined8 ScsiPortDispatchUnimplemented(longlong param_1,longlong param_2)

{
  int *piVar1;
  byte *pbVar2;
  longlong lVar3;
  undefined8 uVar4;
  char *pcVar5;
  
  pbVar2 = *(byte **)(param_2 + 0xb8);
  lVar3 = *(longlong *)(param_1 + 0x40);
  LOCK();
  piVar1 = (int *)(lVar3 + 0x4c);
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if (*(int *)(lVar3 + 0xc) == 0) {
    lVar3 = *(longlong *)(param_1 + 0x40);
    if ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_q(WPP_GLOBAL_Control[3],10,&WPP_bdb79677dd0234bbf914861d6b9f0374_Traceguids,param_2);
      }
      if ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_DD(WPP_GLOBAL_Control[3],0xb,&WPP_bdb79677dd0234bbf914861d6b9f0374_Traceguids,
                    (uint)*pbVar2,pbVar2[1]);
        }
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          pcVar5 = "PDO";
          if ((*(byte *)(lVar3 + 8) & 1) == 0) {
            pcVar5 = "FDO";
          }
          WPP_SF_sq(WPP_GLOBAL_Control[3],0xc,&WPP_bdb79677dd0234bbf914861d6b9f0374_Traceguids,
                    pcVar5,(char)param_1);
        }
      }
    }
    uVar4 = 0xc0000010;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
  }
  else {
    uVar4 = 0xc00000c0;
    *(undefined4 *)(param_2 + 0x30) = 0xc00000c0;
  }
  SpReleaseRemoveLock(param_1,(char)param_2);
  IofCompleteRequest(param_2,0);
  return uVar4;
}



===== ScsiPortGlobalDispatch @ 1400012b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ScsiPortGlobalDispatch(longlong param_1,longlong param_2)

{
  (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x20) +
              (ulonglong)**(byte **)(param_2 + 0xb8) * 8))();
  return;
}



===== WPP_SF_DD @ 1400012dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,0);
  return;
}



===== WPP_SF_q @ 14000132c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,0);
  return;
}



===== WPP_SF_sq @ 140001370 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sq(undefined8 param_1,undefined2 param_2,undefined8 param_3,char *param_4,
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
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,lVar2,&param_5,8,0);
  return;
}



===== SpEnableDisableAdapter @ 1400013e8 =====

undefined4
SpEnableDisableAdapter(longlong *param_1,char *param_2,undefined *param_3,longlong *param_4)

{
  int iVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined8 uVar5;
  char cVar6;
  uint uVar7;
  
  uVar3 = 0;
  cVar6 = (char)param_2;
  uVar2 = KfRaiseIrql(2);
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    param_2 = "disable";
    pcVar4 = "enable";
    if (cVar6 == '\0') {
      pcVar4 = "disable";
    }
    param_4 = param_1;
    WPP_SF_qs(WPP_GLOBAL_Control[3],"disable",param_3,param_1,pcVar4);
  }
  iVar1 = *(int *)((longlong)param_1 + 0x184);
  if (cVar6 == '\0') {
    *(int *)((longlong)param_1 + 0x184) = iVar1 + 1;
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_D(WPP_GLOBAL_Control[3],0xc,&WPP_1080711acb28308ee5f9895e897271df_Traceguids,iVar1);
    }
    if (iVar1 == 0) {
      uVar5 = SpShutdownAdapter((longlong)param_1);
      uVar3 = (undefined4)uVar5;
    }
  }
  else {
    uVar7 = iVar1 - 1;
    *(uint *)((longlong)param_1 + 0x184) = uVar7;
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      param_3 = &WPP_1080711acb28308ee5f9895e897271df_Traceguids;
      param_2 = (char *)0xb;
      param_4 = (longlong *)(ulonglong)uVar7;
      WPP_SF_D(WPP_GLOBAL_Control[3],0xb,&WPP_1080711acb28308ee5f9895e897271df_Traceguids,uVar7);
    }
    if (uVar7 == 0) {
      uVar3 = SpReinitializeAdapter(param_1,param_2,param_3,param_4);
    }
  }
  KeLowerIrql(uVar2);
  return uVar3;
}



===== SpEnableDisableCompletionRoutine @ 140001530 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SpEnableDisableCompletionRoutine(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  undefined4 uVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
     (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qL(WPP_GLOBAL_Control[3],param_2,param_3,param_2,(char)*(undefined4 *)(param_2 + 0x30));
  }
  lVar2 = *(longlong *)(param_2 + 0xb8);
  uVar1 = *(undefined4 *)(param_2 + 0x30);
  pcVar3 = *(code **)(lVar2 + 0x10);
  uVar4 = *(undefined8 *)(lVar2 + 0x18);
  uVar5 = *(undefined8 *)(lVar2 + 8);
  ExFreePoolWithTag(param_3,0);
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)(uVar5,uVar1,uVar4);
  }
  return 0xc0000016;
}



===== SpEnableDisableLogicalUnit @ 1400015e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
SpEnableDisableLogicalUnit(longlong *param_1,char param_2,undefined *param_3,undefined8 param_4)

{
  undefined2 *puVar1;
  longlong lVar2;
  longlong lVar3;
  char *pcVar4;
  undefined2 *_Dst;
  undefined8 uVar5;
  short sVar6;
  ushort uVar7;
  
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
     (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    pcVar4 = "enable";
    if (param_2 == '\0') {
      pcVar4 = "disable";
    }
    WPP_SF_qsq(WPP_GLOBAL_Control[3],"disable",param_3,param_1,pcVar4,(char)param_4);
  }
  uVar5 = *(undefined8 *)(*param_1 + 8);
  sVar6 = *(char *)(*param_1 + 0x4c) * 0x48;
  uVar7 = sVar6 + 0x170;
  if (uVar7 != 0) {
    _Dst = (undefined2 *)ExAllocatePoolWithTag(0,uVar7,0x70506353);
    if (_Dst != (undefined2 *)0x0) {
      puVar1 = _Dst + 0x2c;
      IoInitializeIrp(puVar1,sVar6 + 0x118,*(char *)(*param_1 + 0x4c) + '\x01');
      lVar2 = *param_1;
      lVar3 = *(longlong *)(_Dst + 0x88);
      *(undefined8 *)(lVar3 + -0x28) = 0;
      *(longlong *)(lVar3 + -0x40) = lVar2;
      *(undefined **)(lVar3 + -0x38) = param_3;
      *(undefined8 *)(lVar3 + -0x30) = param_4;
      lVar2 = *(longlong *)(_Dst + 0x88);
      *(char *)((longlong)_Dst + 0x9b) = *(char *)((longlong)_Dst + 0x9b) + -1;
      *(longlong *)(_Dst + 0x88) = lVar2 + -0x48;
      *(code **)(lVar2 + -0x58) = SpEnableDisableCompletionRoutine;
      *(undefined2 **)(lVar2 + -0x50) = _Dst;
      *(undefined1 *)(lVar2 + -0x8d) = 0xe0;
      lVar2 = *(longlong *)(_Dst + 0x88);
      *(undefined2 *)(lVar2 + -0x48) = 0x10f;
      *(undefined2 **)(lVar2 + -0x40) = _Dst;
      memset(_Dst,0,0x58);
      *_Dst = 0x58;
      *(undefined2 **)(_Dst + 0x18) = puVar1;
      *(undefined4 *)(_Dst + 6) = 0x80000;
      *(char *)(_Dst + 1) = (param_2 != '\0') + '\x18';
      uVar5 = IofCallDriver(*param_1,puVar1);
      return uVar5;
    }
    SpLogAllocationFailureFn(uVar5,0,(uint)uVar7,0x70506353,0x656e6162,0xd9);
  }
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
     (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_(WPP_GLOBAL_Control[3],0xe,&WPP_1080711acb28308ee5f9895e897271df_Traceguids);
  }
  if (param_3 != (undefined *)0x0) {
    (*(code *)param_3)(*param_1,0xc000009a,param_4);
  }
  return 0xc000009a;
}



===== SpReinitializeAdapter @ 1400017fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
SpReinitializeAdapter(longlong *param_1,undefined8 param_2,undefined8 param_3,longlong *param_4)

{
  uint *puVar1;
  uint uVar2;
  longlong lVar3;
  char cVar4;
  undefined1 uVar5;
  int iVar6;
  byte bVar7;
  undefined4 uVar8;
  longlong **pplVar9;
  undefined1 auStackY_88 [32];
  byte in_stack_ffffffffffffff98;
  byte in_stack_ffffffffffffffa0;
  undefined1 local_48 [8];
  longlong *local_40;
  undefined8 uStack_38;
  undefined4 local_30;
  undefined2 local_2c;
  undefined1 local_2a;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48[0] = 0;
  local_30 = 0x454b4157;
  local_2c = 0x5055;
  local_2a = 0;
  cVar4 = RtlAreBitsSet(param_1 + 0x59,2,1);
  if (cVar4 == '\x01') {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_(WPP_GLOBAL_Control[3],0x10,&WPP_1080711acb28308ee5f9895e897271df_Traceguids);
    }
    bVar7 = 1;
  }
  else {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_(WPP_GLOBAL_Control[3],0x11,&WPP_1080711acb28308ee5f9895e897271df_Traceguids);
    }
    bVar7 = 0;
  }
  uVar5 = KfRaiseIrql(2);
  KeAcquireSpinLockAtDpcLevel(param_1 + 0x36);
  *(uint *)((longlong)param_1 + 0x17c) = *(uint *)((longlong)param_1 + 0x17c) | 0x40000;
  if (bVar7 == 0) {
    in_stack_ffffffffffffffa0 = (byte)local_48;
    param_4 = (longlong *)&local_30;
    in_stack_ffffffffffffff98 = (byte)param_1[0x3f];
    iVar6 = (*(code *)param_1[0x4f])(param_1[0x29],0,0);
    if (iVar6 != 1) {
      uVar8 = 0xc0000183;
      goto LAB_1400019fd;
    }
  }
  else {
    cVar4 = RtlAreBitsSet(param_1 + 0x59,4,1);
    if (cVar4 == '\x01') {
      (*(code *)param_1[0x57])(param_1[0x29],4);
    }
  }
  pplVar9 = &local_40;
  uStack_38 = (ulonglong)bVar7;
  local_40 = param_1;
  (*(code *)param_1[0x34])(param_1[0x32],SpReinitializeAdapterSynchronized);
  uVar8 = uStack_38._4_4_;
  if (-1 < (longlong)uStack_38) {
    ScsiPortNotification
              (1,param_1[0x29],(undefined *)pplVar9,param_4,in_stack_ffffffffffffff98,
               in_stack_ffffffffffffffa0);
    if ((*(uint *)(param_1 + 0x6d) & 4) != 0) {
      lVar3 = *param_1;
      LOCK();
      puVar1 = (uint *)(*(longlong *)(lVar3 + 0x40) + 0x180);
      uVar2 = *puVar1;
      *puVar1 = 0x20004;
      UNLOCK();
      if ((uVar2 >> 0x11 & 1) == 0) {
        KeInsertQueueDpc(lVar3 + 200,0,0);
      }
    }
  }
LAB_1400019fd:
  KeReleaseSpinLockFromDpcLevel(param_1 + 0x36);
  KeLowerIrql(uVar5);
  return uVar8;
}



===== SpReinitializeAdapterSynchronized @ 140001a50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SpReinitializeAdapterSynchronized(longlong *param_1)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  char cVar5;
  
  lVar1 = *param_1;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_(WPP_GLOBAL_Control[3],0x12,&WPP_1080711acb28308ee5f9895e897271df_Traceguids);
  }
  if ((char)param_1[1] == '\0') {
    cVar5 = (**(code **)(lVar1 + 0x280))(*(undefined8 *)(lVar1 + 0x148));
  }
  else {
    iVar2 = (**(code **)(lVar1 + 0x2b8))(*(undefined8 *)(lVar1 + 0x148),2);
    cVar5 = iVar2 == 0;
  }
  uVar3 = -(uint)(cVar5 != '\x01') & 0xc00000c2;
  uVar4 = (ulonglong)uVar3;
  *(uint *)((longlong)param_1 + 0xc) = uVar3;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    uVar4 = WPP_SF_(WPP_GLOBAL_Control[3],0x13,&WPP_1080711acb28308ee5f9895e897271df_Traceguids);
  }
  *(uint *)(lVar1 + 0x368) = *(uint *)(lVar1 + 0x368) & 0xffffbfff;
  *(uint *)(lVar1 + 0x17c) = *(uint *)(lVar1 + 0x17c) & 0xfff3ffff;
  return CONCAT71((int7)(uVar4 >> 8),1);
}



===== SpShutdownAdapter @ 140001b38 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SpShutdownAdapter(longlong param_1)

{
  char cVar1;
  
  KeAcquireSpinLockAtDpcLevel(param_1 + 0x1b0);
  *(uint *)(param_1 + 0x17c) = *(uint *)(param_1 + 0x17c) | 0x800000;
  KeReleaseSpinLockFromDpcLevel(param_1 + 0x1b0);
  KeCancelTimer(param_1 + 0x400);
  (**(code **)(param_1 + 0x1a0))
            (*(undefined8 *)(param_1 + 400),SpShutdownAdapterSynchronized,param_1);
  cVar1 = RtlAreBitsSet(param_1 + 0x2c8,3,1);
  if (cVar1 != '\0') {
    (**(code **)(param_1 + 0x2b8))(*(undefined8 *)(param_1 + 0x148),3,0);
  }
  return 0;
}



===== SpShutdownAdapterSynchronized @ 140001bf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SpShutdownAdapterSynchronized(longlong param_1)

{
  undefined8 *puVar1;
  
  (**(code **)(param_1 + 0x2b8))(*(undefined8 *)(param_1 + 0x148),1);
  puVar1 = &WPP_GLOBAL_Control;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (puVar1 = (undefined8 *)(ulonglong)*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c),
      (*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    puVar1 = (undefined8 *)
             WPP_SF_(WPP_GLOBAL_Control[3],0x14,&WPP_1080711acb28308ee5f9895e897271df_Traceguids);
  }
  *(uint *)(param_1 + 0x368) = *(uint *)(param_1 + 0x368) | 0x4000;
  *(uint *)(param_1 + 0x17c) = *(uint *)(param_1 + 0x17c) & 0xff7fffff;
  return CONCAT71((int7)((ulonglong)puVar1 >> 8),1);
}



===== WPP_SF_ @ 140001c68 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_D @ 140001c94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_qL @ 140001cd8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_1080711acb28308ee5f9895e897271df_Traceguids,0xf,&local_res20,8,
             &param_5,4,0);
  return;
}



===== WPP_SF_qs @ 140001d34 =====

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
            (param_1,0x2b,&WPP_1080711acb28308ee5f9895e897271df_Traceguids,10,&local_res20,8,param_5
             ,lVar2,0);
  return;
}



===== WPP_SF_qsq @ 140001dbc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qsq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
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
            (param_1,0x2b,&WPP_1080711acb28308ee5f9895e897271df_Traceguids,0xd,&local_res20,8,
             param_5,lVar2,&param_6,8,0);
  return;
}



===== RtlStringCbPrintfW @ 140001e5c =====

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



===== SpAddLogicalUnitToBin @ 140001ed8 =====

void SpAddLogicalUnitToBin(longlong param_1,longlong param_2)

{
  undefined1 uVar1;
  longlong lVar2;
  
  lVar2 = ((ulonglong)((byte)(*(char *)(param_2 + 0x156) + *(char *)(param_2 + 0x155)) & 7) + 0x2e)
          * 0x10 + param_1;
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x1b0);
  KeAcquireSpinLockAtDpcLevel(lVar2);
  *(undefined8 *)(param_2 + 0x1a8) = *(undefined8 *)(lVar2 + 8);
  *(longlong *)(lVar2 + 8) = param_2;
  KeReleaseSpinLockFromDpcLevel(lVar2);
  KeReleaseSpinLock(param_1 + 0x1b0,uVar1);
  return;
}



===== SpCompleteEnumRequest @ 140001f80 =====

void SpCompleteEnumRequest(longlong *param_1,longlong param_2)

{
  int *piVar1;
  undefined8 *puVar2;
  
  LOCK();
  piVar1 = (int *)(*(longlong *)(*param_1 + 0x40) + 0x4c);
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  SpReleaseRemoveLock(*param_1,(char)param_2);
  if (*(int *)(param_2 + 0x30) < 0) {
    IofCompleteRequest(param_2,0);
  }
  else {
    puVar2 = *(undefined8 **)(param_2 + 0xb8);
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
    IofCallDriver(param_1[2],param_2);
  }
  SpReleaseRemoveLock(*param_1,8);
  return;
}



===== SpIsInitiatorLU @ 140002020 =====

undefined1 SpIsInitiatorLU(longlong param_1)

{
  longlong lVar1;
  byte bVar2;
  undefined1 uVar3;
  
  uVar3 = 1;
  lVar1 = *(longlong *)(param_1 + 0x168);
  bVar2 = *(char *)(lVar1 + 0x178) - 1;
  if (*(longlong *)(lVar1 + 0x1f8) == 0) {
    return 0;
  }
  if ((((*(char *)(lVar1 + 0x7e8) == '\0') || (bVar2 != *(byte *)(param_1 + 0x154))) ||
      (*(char *)((ulonglong)bVar2 + 0x49 + *(longlong *)(lVar1 + 0x1f8)) !=
       *(char *)(param_1 + 0x155))) || (*(char *)(param_1 + 0x156) != '\0')) {
    uVar3 = 0;
  }
  return uVar3;
}



===== SpRemoveLogicalUnitFromBin @ 140002080 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SpRemoveLogicalUnitFromBin(longlong param_1,longlong param_2)

{
  undefined1 uVar1;
  longlong lVar2;
  
  lVar2 = ((ulonglong)((uint)*(byte *)(param_2 + 0x156) + (uint)*(byte *)(param_2 + 0x155) & 7) +
          0x2e) * 0x10 + param_1;
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x1b0);
  KeAcquireSpinLockAtDpcLevel(lVar2);
  (**(code **)(param_1 + 0x1a0))
            (*(undefined8 *)(param_1 + 400),SpRemoveLogicalUnitFromBinSynchronized,param_2);
  KeReleaseSpinLockFromDpcLevel(lVar2);
  KeReleaseSpinLock(param_1 + 0x1b0,uVar1);
  if ((*(char *)(param_2 + 0x14e) == '\0') &&
     ((*(char *)(param_2 + 0x14d) != '\0' || (*(char *)(param_2 + 0x14b) != '\0')))) {
    if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0 &&
        (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
      WPP_SF_q(WPP_GLOBAL_Control[3],0x14,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,param_2);
    }
    *(undefined4 *)(param_1 + 0x540) = 1;
    IoInvalidateDeviceRelations(*(undefined8 *)(param_1 + 0x140),0);
  }
  return;
}



===== SpRemoveLogicalUnitFromBinSynchronized @ 1400021c0 =====

undefined8 SpRemoveLogicalUnitFromBinSynchronized(longlong param_1)

{
  char cVar1;
  char cVar2;
  longlong lVar3;
  longlong *plVar4;
  
  cVar1 = *(char *)(param_1 + 0x156);
  cVar2 = *(char *)(param_1 + 0x155);
  lVar3 = *(longlong *)(param_1 + 0x168);
  *(undefined8 *)(lVar3 + 0x360) = 0;
  plVar4 = (longlong *)(lVar3 + 0x2e8 + (ulonglong)(cVar1 + cVar2 & 7) * 0x10);
  do {
    lVar3 = *plVar4;
    if (lVar3 == 0) {
      lVar3 = 0;
LAB_140002219:
      return CONCAT71((int7)((ulonglong)lVar3 >> 8),1);
    }
    if (lVar3 == param_1) {
      lVar3 = *(longlong *)(param_1 + 0x1a8);
      *plVar4 = lVar3;
      *(undefined8 *)(param_1 + 0x1a8) = 0;
      goto LAB_140002219;
    }
    plVar4 = (longlong *)(lVar3 + 0x1a8);
  } while( true );
}



===== SpSendSrbSynchronous @ 140002224 =====

undefined4
SpSendSrbSynchronous
          (longlong *param_1,longlong param_2,longlong param_3,longlong param_4,longlong param_5,
          undefined4 param_6,longlong param_7,undefined8 param_8,undefined4 *param_9)

{
  byte bVar1;
  undefined1 uVar2;
  longlong lVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  undefined4 uVar7;
  undefined *puVar8;
  uint uVar9;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uVar9 = 0;
  do {
    uVar5 = 0;
    KeInitializeEvent();
    if (param_3 == 0) {
      lVar3 = *param_1;
      param_3 = SpAllocateIrpEx(CONCAT71((int7)((ulonglong)lVar3 >> 8),*(undefined1 *)(lVar3 + 0x4c)
                                        ),uVar5,*(undefined8 *)(lVar3 + 8),0x656e756d,0x104d);
      if (param_3 == 0) {
        return 0xc000009a;
      }
    }
    if (param_5 != 0) {
      if (param_4 == 0) {
        param_4 = SpAllocateMdlEx();
        if (param_4 == 0) {
          IoFreeIrp(param_3);
          return 0xc000009a;
        }
        MmBuildMdlForNonPagedPool();
      }
      *(longlong *)(param_3 + 8) = param_4;
    }
    lVar3 = *(longlong *)(param_3 + 0xb8);
    *(undefined2 *)(lVar3 + -0x48) = 0x10f;
    *(longlong *)(lVar3 + -0x40) = param_2;
    *(undefined2 *)(param_2 + 3) = 0;
    *(longlong *)(param_2 + 0x30) = param_3;
    if (param_7 == 0) {
      *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) | 0x20;
      uVar2 = 0;
      lVar3 = 0;
    }
    else {
      uVar2 = 0x12;
      lVar3 = param_7;
    }
    *(longlong *)(param_2 + 0x20) = lVar3;
    *(undefined1 *)(param_2 + 0xb) = uVar2;
    if (param_4 == 0) {
      uVar7 = 0;
      lVar3 = 0;
    }
    else {
      lVar3 = (ulonglong)*(uint *)(param_4 + 0x2c) + *(longlong *)(param_4 + 0x20);
      uVar7 = param_6;
    }
    *(longlong *)(param_2 + 0x18) = lVar3;
    *(undefined4 *)(param_2 + 0x10) = uVar7;
    lVar3 = *(longlong *)(param_3 + 0xb8);
    *(code **)(lVar3 + -0x10) = SpSignalCompletion;
    *(undefined8 **)(lVar3 + -8) = &local_38;
    *(undefined1 *)(lVar3 + -0x45) = 0xe0;
    KeEnterCriticalRegion();
    IofCallDriver(*param_1,param_3);
    puVar8 = (undefined *)0x0;
    KeWaitForSingleObject(&local_38,0,0,0,0);
    uVar7 = *(undefined4 *)(param_3 + 0x30);
    *param_9 = *(undefined4 *)(param_3 + 0x38);
    bVar1 = *(byte *)(param_2 + 3);
    if (bVar1 == 0) goto LAB_1400025a0;
    if ((bVar1 & 0xffffff3f) == 1) {
LAB_14000259e:
      uVar7 = 0;
      goto LAB_1400025a0;
    }
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
       (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      puVar8 = &WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids;
      WPP_SF_D(WPP_GLOBAL_Control[3],0x3a,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,
               (uint)bVar1);
    }
    puVar6 = &WPP_GLOBAL_Control;
    if ((*(byte *)(param_2 + 3) & 0x40) != 0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
         (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        puVar8 = &WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids;
        puVar6 = (undefined8 *)0x3b;
        WPP_SF_D(WPP_GLOBAL_Control[3],0x3b,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,
                 (uint)*(byte *)(param_2 + 6));
      }
      *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xfffffffe;
      GetNextLuRequestWithoutLock(param_1,puVar6,puVar8);
    }
    uVar4 = *(byte *)(param_2 + 3) & 0xffffff3f;
    if (uVar4 == 0x12) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_D(WPP_GLOBAL_Control[3],0x3c,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,
                 (uint)*(byte *)((longlong)param_1 + 0x155));
      }
      goto LAB_14000259e;
    }
    if (((char)*(byte *)(param_2 + 3) < '\0') && ((*(byte *)(param_7 + 2) & 0xf) == 5))
    goto LAB_14000255c;
    if (((uVar4 - 8 & 0xfffffffd) == 0) || (1 < uVar9)) break;
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_D(WPP_GLOBAL_Control[3],0x3d,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,uVar9 + 1
              );
    }
    KeLeaveCriticalRegion();
    uVar9 = uVar9 + 1;
  } while( true );
  if (uVar4 < 0x13) {
    if (uVar4 != 8) {
      if (uVar4 != 9) {
        if (uVar4 == 10) {
          uVar7 = 0xc000009d;
          goto LAB_1400025a0;
        }
        if (uVar4 != 0xb) {
          if (uVar4 != 0x11) goto LAB_140002555;
          goto LAB_14000252c;
        }
      }
      uVar7 = 0xc00000b5;
      goto LAB_1400025a0;
    }
LAB_14000252c:
    uVar7 = 0xc00000c0;
  }
  else {
    if (uVar4 != 0x15) {
      if ((uVar4 == 0x20) || (uVar4 == 0x21)) goto LAB_14000252c;
      if (uVar4 != 0x22) {
LAB_140002555:
        uVar7 = 0xc0000185;
        goto LAB_1400025a0;
      }
    }
LAB_14000255c:
    uVar7 = 0xc0000010;
  }
LAB_1400025a0:
  KeLeaveCriticalRegion();
  return uVar7;
}



===== WPP_SF_DDD @ 1400025d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,0x2f,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_DDL @ 140002638 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,0x22,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_DDd @ 14000269c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,0x25,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_LZ @ 140002700 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_LZ(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
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
      goto LAB_14000273a;
    }
  }
  pwVar1 = L"NULL";
LAB_14000273a:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,param_5,2,pwVar1,wVar2,0);
  return;
}



===== WPP_SF_Lq @ 14000279c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Lq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,param_2,local_res20,4,
             &param_5,8,0);
  return;
}



===== WPP_SF_cc @ 1400027f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_cc(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 param_4,
              undefined1 param_5)

{
  undefined1 local_res20 [8];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,0x2c,local_res20,1,
             &param_5,1,0);
  return;
}



===== WPP_SF_ddd @ 14000284c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ddd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_ddddd @ 1400028a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ddddd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,0x35,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_SF_dddq @ 140002928 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dddq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,4,&param_7,8,0);
  return;
}



===== WPP_SF_iD @ 140002994 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_iD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,0x26,&local_res20,8,
             &param_5,4,0);
  return;
}



===== WPP_SF_qd @ 1400029f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,4,0);
  return;
}



===== WPP_SF_qddd @ 140002a44 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qddd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,0xb,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_sddd @ 140002ab8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sddd(undefined8 param_1,undefined2 param_2,undefined8 param_3,char *param_4,
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
            (param_1,0x2b,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,param_2,param_4,lVar2,
             &param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== DllInitialize @ 140002b60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140002cbf) */
/* WARNING: Removing unreachable block (ram,0x000140002c60) */
/* WARNING: Removing unreachable block (ram,0x000140002dde) */
/* WARNING: Removing unreachable block (ram,0x000140002df2) */
/* WARNING: Removing unreachable block (ram,0x000140002dfb) */
/* WARNING: Removing unreachable block (ram,0x000140002e04) */

undefined8 DllInitialize(void)

{
  int iVar1;
  bool bVar2;
  undefined1 auStack_a8 [32];
  undefined8 local_70;
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
  undefined1 local_28 [24];
  ulonglong local_10;
  
                    /* 0x2b60  1  DllInitialize */
  local_10 = __security_cookie ^ (ulonglong)auStack_a8;
  local_70 = 0;
  local_3c = 0;
  local_54 = 0;
  local_68 = 0;
  uStack_60 = 0;
  LOCK();
  iVar1 = ScsiPortNumDllInitialize + 1;
  UNLOCK();
  bVar2 = ScsiPortNumDllInitialize == 0;
  ScsiPortNumDllInitialize = iVar1;
  if (bVar2) {
    wil_InitializeFeatureStaging();
  }
  RtlInitUnicodeString
            (&local_68,
             L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\ScsiPort\\QueueParams");
  local_50 = 0;
  local_48 = &local_68;
  local_58 = 0x30;
  local_40 = 0x240;
  local_38 = 0;
  uStack_30 = 0;
  iVar1 = ZwOpenKey(&local_70,0x20019,&local_58);
  if (-1 < iVar1) {
    RtlInitUnicodeString(&local_68,L"PerZoneLimit");
    ZwQueryValueKey(local_70,&local_68,2,local_28);
    RtlInitUnicodeString(&local_68,L"PerBlockLimit");
    ZwQueryValueKey(local_70,&local_68,2,local_28);
    ZwClose(local_70);
  }
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_DD(WPP_GLOBAL_Control[3],0x69,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,
              SpPerZoneLimit,(char)SpPerBlockLimit);
  }
  if (SpVrfyLevel != -1) {
    RtlInitUnicodeString
              (&local_68,
               L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\ScsiPort\\Verifier");
    local_50 = 0;
    local_48 = &local_68;
    local_58 = 0x30;
    local_40 = 0x240;
    local_38 = 0;
    uStack_30 = 0;
    iVar1 = ZwOpenKey(&local_70,0x20019,&local_58);
    if (-1 < iVar1) {
      RtlInitUnicodeString(&local_68,L"VerifyLevel");
      ZwQueryValueKey(local_70,&local_68,2,local_28);
      ZwClose(local_70);
    }
  }
  return 0;
}



===== ScsiPortFreeDeviceBase @ 140002e40 =====

void ScsiPortFreeDeviceBase(longlong param_1,longlong param_2)

{
                    /* 0x2e40  7  ScsiPortFreeDeviceBase */
  SpFreeMappedAddress(*(longlong *)(param_1 + -8),param_2);
  return;
}



===== ScsiPortGetBusData @ 140002e60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
ScsiPortGetBusData(longlong param_1,int param_2,undefined8 param_3,undefined8 param_4,
                  longlong *param_5,uint param_6)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined1 auStackY_88 [32];
  undefined4 in_stack_ffffffffffffff98;
  undefined4 in_stack_ffffffffffffff9c;
  undefined8 local_48;
  undefined4 local_40;
  ulonglong local_38;
  
                    /* 0x2e60  8  ScsiPortGetBusData */
  local_38 = __security_cookie ^ (ulonglong)auStackY_88;
  plVar1 = *(longlong **)(param_1 + -8);
  lVar4 = 0;
  local_48 = 0;
  local_40 = 0;
  if ((*(byte *)(plVar1 + 0x2d) & 2) != 0) {
    if ((int)param_4 != *(int *)((longlong)plVar1 + 0x16c)) {
      return 2;
    }
    lVar4 = plVar1[2];
  }
  if (param_6 == 0) {
    if (plVar1[0x39] != 0) {
      ExFreePoolWithTag(plVar1[0x39],0);
      plVar1[0x39] = 0;
    }
    if (param_2 == 1) {
      uVar3 = SpGetBusData((longlong)plVar1,lVar4,1,param_4,
                           CONCAT44(in_stack_ffffffffffffff9c,in_stack_ffffffffffffff98),&local_48,
                           0xc);
      if (0xb < (uint)uVar3) {
        param_6 = (uint)local_48._6_1_ * 0x140 + 0xc;
        goto LAB_140002f39;
      }
    }
    else {
      param_6 = 0x1000;
      if (param_2 == 4) {
        param_6 = 0x40;
      }
LAB_140002f39:
      in_stack_ffffffffffffff98 = 0x696e6974;
      param_4 = *(undefined8 *)(*plVar1 + 8);
      lVar2 = SpAllocatePoolEx(0,(ulonglong)param_6,0x62506353,param_4,0x696e6974,0x1526);
      plVar1[0x39] = lVar2;
      if (lVar2 != 0) {
        *param_5 = lVar2;
        param_5 = (longlong *)plVar1[0x39];
        goto LAB_140002f82;
      }
    }
    uVar3 = 0;
  }
  else {
LAB_140002f82:
    uVar3 = SpGetBusData((longlong)plVar1,lVar4,param_2,param_4,
                         CONCAT44(in_stack_ffffffffffffff9c,in_stack_ffffffffffffff98),param_5,
                         param_6);
  }
  return uVar3;
}



===== ScsiPortGetDeviceBase @ 140002fb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong ScsiPortGetDeviceBase
                   (longlong param_1,uint param_2,uint param_3,undefined1 *param_4,uint param_5,
                   byte param_6)

{
  char cVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  uint uVar6;
  char *pcVar7;
  undefined1 auStackY_a8 [32];
  uint local_64;
  uint local_60;
  longlong local_58;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 local_40;
  ulonglong local_38;
  
                    /* 0x2fb0  9  ScsiPortGetDeviceBase */
  local_38 = __security_cookie ^ (ulonglong)auStackY_a8;
  plVar4 = *(longlong **)(param_1 + -8);
  lVar3 = 0;
  cVar1 = '\0';
  local_58 = 0;
  uVar6 = (uint)param_6;
  local_60 = *(uint *)((longlong)plVar4 + 0x17c) & 0x40000;
  local_64 = uVar6;
  if ((*(byte *)(plVar4 + 0x2d) & 1) == 0) {
    local_40 = 0;
    local_50 = 0;
    uStack_4c = 0;
    uStack_48 = 0;
    uStack_44 = 0;
    uVar2 = SpFindAddressTranslation
                      ((longlong)plVar4,param_2,param_3,param_4,param_5,param_6,
                       (undefined8 *)&local_50);
    cVar1 = (char)uVar2;
    if (cVar1 == '\0') {
      if ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) {
          if (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29)) {
            pcVar7 = "I/O";
            if (param_6 == 0) {
              pcVar7 = "Memory";
            }
            WPP_SF_sL(WPP_GLOBAL_Control[3],0x10,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,
                      pcVar7,(char)param_4);
            lVar3 = local_58;
            uVar6 = local_64;
          }
        }
      }
    }
    else {
      local_58 = CONCAT44(uStack_48,uStack_4c);
      local_64 = (uint)((char)local_50 == '\x01');
      lVar3 = local_58;
      uVar6 = (uint)((char)local_50 == '\x01');
    }
  }
  if (local_60 == 0) {
    if (cVar1 != '\0') goto LAB_140003161;
    cVar1 = HalTranslateBusAddress(param_2,param_3,param_4,&local_64);
    lVar3 = local_58;
    uVar6 = local_64;
  }
  if (cVar1 == '\0') {
    if ((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) == 0) {
      return 0;
    }
    if (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2) {
      return 0;
    }
    pcVar7 = "I/O";
    if (param_6 == 0) {
      pcVar7 = "Memory";
    }
    WPP_SF_sL(WPP_GLOBAL_Control[3],0x11,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,pcVar7,
              (char)param_4);
    return 0;
  }
  if (local_60 != 0) {
    if (uVar6 != 0) {
      return lVar3;
    }
    puVar5 = (undefined8 *)plVar4[0x4d];
    do {
      if (puVar5 == (undefined8 *)0x0) {
LAB_14000324a:
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x2c,0,0,0);
      }
      if ((((undefined1 *)puVar5[3] == param_4) && (*(uint *)(puVar5 + 2) == param_5)) &&
         (*(uint *)(puVar5 + 4) == param_3)) {
        if (puVar5 != (undefined8 *)0x0) {
          return puVar5[1];
        }
        goto LAB_14000324a;
      }
      puVar5 = (undefined8 *)*puVar5;
    } while( true );
  }
LAB_140003161:
  if (uVar6 != 0) {
    return lVar3;
  }
  lVar3 = MmMapIoSpace(lVar3,param_5,0);
  if (lVar3 != 0) {
    plVar4 = SpAllocateAddressMapping(plVar4);
    if (plVar4 != (longlong *)0x0) {
      plVar4[1] = lVar3;
      *(uint *)(plVar4 + 2) = param_5;
      plVar4[3] = (longlong)param_4;
      *(uint *)(plVar4 + 4) = param_3;
      return lVar3;
    }
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_(WPP_GLOBAL_Control[3],0x12,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids);
    }
    MmUnmapIoSpace(lVar3,param_5);
  }
  return 0;
}



===== ScsiPortGetUncachedExtension @ 140003280 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong ScsiPortGetUncachedExtension(longlong param_1,longlong param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  longlong *plVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined1 auStack_a8 [32];
  uint local_88 [4];
  undefined1 local_78 [4];
  undefined1 local_74;
  undefined1 local_73;
  undefined2 local_72;
  undefined1 local_70;
  undefined1 local_6d;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  ulonglong local_38;
  
                    /* 0x3280  13  ScsiPortGetUncachedExtension */
  local_38 = __security_cookie ^ (ulonglong)auStack_a8;
  plVar3 = *(longlong **)(param_1 + -8);
  memset(local_78,0,0x40);
  local_88[0] = 0;
  if ((*(uint *)((longlong)plVar3 + 0x17c) & 0x40000) == 0) {
    lVar5 = plVar3[0xec];
    if ((lVar5 == 0) || ((*(uint *)(lVar5 + 100) & 1) == 0)) {
      lVar5 = plVar3[0x45];
    }
    else {
      lVar5 = *(longlong *)(lVar5 + 0x50);
    }
    if (lVar5 == 0) {
      if (plVar3[0x3a] == 0) {
        memset(local_78,0,0x40);
        local_68 = *(undefined4 *)(param_2 + 0x20);
        local_64 = *(undefined4 *)(param_2 + 8);
        local_60 = *(undefined4 *)(param_2 + 0x28);
        local_5c = *(undefined4 *)(param_2 + 0x2c);
        local_73 = *(undefined1 *)(param_2 + 0x51);
        local_74 = *(undefined1 *)(param_2 + 0x52);
        local_54 = *(undefined4 *)(param_2 + 0x24);
        local_70 = *(undefined1 *)(param_2 + 0x57);
        *(undefined1 *)((longlong)plVar3 + 0x492) = local_70;
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 8 & 1) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_D(WPP_GLOBAL_Control[3],0x14,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,
                   (uint)*(byte *)(param_2 + 0x90));
        }
        *(bool *)((longlong)plVar3 + 0x489) = SpRemapBuffersByDefault != 0;
        if ((*(byte *)(param_2 + 0x90) & 0x7f) == 0) {
          if (Sp64BitPhysicalAddresses == 1) {
            if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 8 & 1) != 0)) &&
               (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              WPP_SF_q(WPP_GLOBAL_Control[3],0x16,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,
                       plVar3);
            }
            *(undefined1 *)((longlong)plVar3 + 0x489) = 1;
          }
        }
        else {
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 8 & 1) != 0)) &&
             (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_(WPP_GLOBAL_Control[3],0x15,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids);
          }
          local_6d = 1;
          *(undefined1 *)((longlong)plVar3 + 0x491) = 1;
          if ((*(byte *)(param_2 + 0x90) & 0x7f) == 2) {
            *(undefined1 *)((longlong)plVar3 + 0x491) = 2;
          }
        }
        local_6c = *(undefined4 *)(param_2 + 4);
        local_72 = 0;
        local_58 = *(undefined4 *)(param_2 + 0x18);
        lVar5 = IoGetDmaAdapter(plVar3[0x28],local_78,local_88);
        plVar3[0x3a] = lVar5;
        if (lVar5 == 0) {
          return 0;
        }
        uVar1 = *(uint *)(param_2 + 0x1c);
        if ((uVar1 < local_88[0]) && (uVar1 != 0)) {
          *(uint *)((longlong)plVar3 + 0x3ec) = uVar1;
        }
        else {
          *(uint *)((longlong)plVar3 + 0x3ec) = local_88[0];
        }
      }
      *(undefined1 *)((longlong)plVar3 + 0x48c) = *(undefined1 *)(param_2 + 0x5c);
      SpInitializePowerParams((longlong)plVar3);
      SpInitializePerformanceParams((longlong)plVar3);
      SpInitializeRequestSenseParams((longlong)plVar3);
      iVar2 = *(int *)(param_2 + 0x8c);
      iVar4 = *(int *)((longlong)plVar3 + 0x214);
      if (*(int *)((longlong)plVar3 + 0x214) != iVar2) {
        *(int *)((longlong)plVar3 + 0x214) = iVar2;
        iVar4 = iVar2;
      }
      if ((iVar4 != 0) || (*(char *)(param_2 + 0x5c) != '\0')) {
        *(undefined1 *)((longlong)plVar3 + 0x48f) = 1;
      }
      uVar6 = SpGetCommonBuffer(plVar3,param_3);
      if (-1 < (int)uVar6) goto LAB_140003326;
    }
  }
  else {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 8 & 1) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_q(WPP_GLOBAL_Control[3],0x13,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,
               plVar3[0x2a]);
    }
    if ((*(uint *)((longlong)plVar3 + 0x17c) & 0x80000) == 0) {
      *(uint *)((longlong)plVar3 + 0x17c) = *(uint *)((longlong)plVar3 + 0x17c) | 0x80000;
LAB_140003326:
      return plVar3[0x2a];
    }
  }
  return 0;
}



===== ScsiPortSetBusDataByOffset @ 140003570 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
ScsiPortSetBusDataByOffset
          (longlong param_1,int param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
          undefined4 param_6,undefined4 param_7)

{
  longlong lVar1;
  undefined8 uVar2;
  
                    /* 0x3570  33  ScsiPortSetBusDataByOffset */
  lVar1 = *(longlong *)(param_1 + -8);
  if ((*(byte *)(lVar1 + 0x168) & 2) == 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_(WPP_GLOBAL_Control[3],0x39,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids);
    }
    uVar2 = 0xc000000d;
  }
  else if (param_2 == 4) {
    uVar2 = (**(code **)(lVar1 + 0x698))(*(undefined8 *)(lVar1 + 0x670),0,param_5,param_6,param_7);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



===== SpCallHwFindAdapter @ 1400035fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong SpCallHwFindAdapter(longlong param_1,undefined8 param_2,undefined8 param_3,char *param_4,
                             longlong param_5,undefined1 *param_6)

{
  longlong *plVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  ulonglong uVar6;
  char cVar7;
  undefined1 uVar8;
  undefined8 local_28;
  undefined8 uStack_20;
  
  plVar1 = *(longlong **)(param_1 + 0x40);
  IoGetDriverObjectExtension(*(undefined8 *)(param_1 + 8),ScsiPortInitialize);
  uVar8 = 0;
  *param_6 = 0;
  SpPreallocateAddressMapping(plVar1);
  iVar3 = (*(code *)plVar1[0x4f])(plVar1[0x29],0,0,*(undefined8 *)(param_4 + 0x10),param_5,param_6);
  if ((*(uint *)(plVar1 + 0x6d) & 0x40) != 0) {
    *(uint *)(plVar1 + 0x6d) = *(uint *)(plVar1 + 0x6d) & 0xffffffbb;
    LogErrorEntry(plVar1,(longlong)(plVar1 + 0x73));
  }
  if (plVar1[0x39] != 0) {
    ExFreePoolWithTag(plVar1[0x39],0);
    plVar1[0x39] = 0;
  }
  if (iVar3 != 1) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_D(WPP_GLOBAL_Control[3],0x45,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,iVar3);
    }
    if (iVar3 == 0) {
      *param_6 = 0;
      return 0xc00000c0;
    }
    if (iVar3 == 2) {
      return 0xc00000c2;
    }
    if (iVar3 == 3) {
      return 0xc000000d;
    }
    return 0xc00000e5;
  }
  if (((*(char *)(param_5 + 0x52) == '\0') && (-1 < (char)plVar1[0x2d])) &&
     (Sp64BitPhysicalAddresses == 1)) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_q(WPP_GLOBAL_Control[3],0x44,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,plVar1);
    }
    return 0xc00000bb;
  }
  uVar4 = 0;
  SpPurgeFreeMappedAddressList((longlong)plVar1);
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_D(WPP_GLOBAL_Control[3],0x46,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,
             (uint)*(byte *)(param_5 + 0x49));
  }
  if ((*(byte *)(plVar1 + 0x2d) & 4) == 0) {
    local_28 = 0;
    uStack_20 = 0;
    RtlInitUnicodeString(&local_28,L"ScsiAdapter");
    puVar5 = SpBuildResourceList(plVar1,param_5);
    plVar1[0x40] = (longlong)puVar5;
    uVar6 = SpReportNewAdapter(param_1);
    uVar4 = (uint)uVar6;
    if ((int)uVar4 < 0) {
      return uVar6;
    }
  }
  if ((plVar1[0x2a] == 0) && (*(int *)(param_5 + 0x8c) != *(int *)((longlong)plVar1 + 0x214))) {
    *(uint *)((longlong)plVar1 + 0x214) = *(int *)(param_5 + 0x8c) + 8U & 0xfffffff8;
  }
  if (*(int *)(param_5 + 0x88) != *(int *)((longlong)plVar1 + 0x264)) {
    *(int *)((longlong)plVar1 + 0x264) = *(int *)(param_5 + 0x88);
  }
  bVar2 = *(byte *)(param_5 + 0x61);
  if (0x80 < *(byte *)(param_5 + 0x61)) {
    bVar2 = 0x80;
  }
  *(byte *)((longlong)plVar1 + 0x179) = bVar2;
  *(undefined1 *)(plVar1 + 0x2f) = *(undefined1 *)(param_5 + 0x48);
  *(undefined1 *)(plVar1 + 0x92) = *(undefined1 *)(param_5 + 0x53);
  *(undefined1 *)((longlong)plVar1 + 0x48e) = *(undefined1 *)(param_5 + 0x5e);
  cVar7 = *(char *)(param_5 + 0x5b);
  *(char *)((longlong)plVar1 + 0x48b) = cVar7;
  *(undefined1 *)((longlong)plVar1 + 0x48d) = *(undefined1 *)(param_5 + 0x5d);
  *(byte *)(plVar1 + 1) =
       (*(char *)(param_5 + 0x93) << 3 ^ *(byte *)(plVar1 + 1)) & 8 ^ *(byte *)(plVar1 + 1);
  if (param_4[1] != '\0') {
    *(undefined1 *)(param_5 + 0x5d) = 0;
    cVar7 = *(char *)((longlong)plVar1 + 0x48b);
    *(undefined1 *)((longlong)plVar1 + 0x48d) = 0;
  }
  if (*param_4 == '\0') {
    if (cVar7 == '\0') goto LAB_140003877;
  }
  else {
    *(undefined1 *)(param_5 + 0x5d) = 0;
    *(undefined1 *)(param_5 + 0x5b) = 0;
    *(undefined1 *)((longlong)plVar1 + 0x48b) = 0;
LAB_140003877:
    if (*(char *)((longlong)plVar1 + 0x48d) == '\0') goto LAB_140003883;
  }
  uVar8 = 1;
LAB_140003883:
  *(undefined1 *)(plVar1 + 0xf3) = uVar8;
  return (ulonglong)uVar4;
}



===== SpCallHwInitialize @ 14000391c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SpCallHwInitialize(longlong param_1)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  longlong *plVar4;
  longlong lVar5;
  bool bVar6;
  undefined1 uVar7;
  char cVar8;
  int iVar9;
  char *pcVar10;
  uint uVar11;
  undefined8 *puVar12;
  int iVar13;
  longlong lVar14;
  ulonglong uVar15;
  char local_res10;
  undefined4 local_res18;
  undefined8 in_stack_ffffffffffffff70;
  undefined8 local_50;
  
  plVar4 = *(longlong **)(param_1 + 0x40);
  lVar5 = plVar4[0x3f];
  KeInitializeSpinLock(plVar4 + 0x36);
  KeInitializeDpc(*plVar4 + 200,ScsiPortCompletionDpc);
  *(undefined4 *)(plVar4 + 0x31) = 0xffffffff;
  iVar13 = 0;
  if (*(longlong *)(param_1 + 0x28) == 0) {
    IoInitializeTimer(param_1,ScsiPortTickHandler,0);
  }
  KeInitializeTimer(plVar4 + 0x80);
  lVar14 = param_1;
  KeInitializeDpc(plVar4 + 0x88,SpMiniPortTimerDpc,param_1);
  KeInitializeSpinLock(plVar4 + 0x38);
  if ((plVar4[0x52] == 0) || ((*(byte *)(plVar4 + 0x2d) & 8) == 0)) {
    plVar4[0x32] = (longlong)plVar4;
    plVar4[0x34] = (longlong)SpSynchronizeExecution;
    if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0 &&
        (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
      WPP_SF_(WPP_GLOBAL_Control[3],0x4a,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids);
    }
  }
  else {
    local_res18 = 0;
    local_50 = 0;
    uVar7 = 0;
    bVar6 = false;
    uVar15 = CONCAT71((int7)((ulonglong)lVar14 >> 8),*(byte *)(plVar4 + 0x2d));
    puVar12 = WPP_GLOBAL_Control;
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      in_stack_ffffffffffffff70 =
           CONCAT44((int)((ulonglong)in_stack_ffffffffffffff70 >> 0x20),*(undefined4 *)(lVar5 + 0xc)
                   );
      WPP_SF_qddddd(WPP_GLOBAL_Control[3],WPP_GLOBAL_Control,uVar15,param_1,
                    (char)*(undefined4 *)(lVar5 + 8),(char)*(undefined4 *)(lVar5 + 0xc),
                    (char)*(undefined4 *)(lVar5 + 0x10),(char)*(undefined4 *)(lVar5 + 0x68),
                    (char)*(undefined4 *)(lVar5 + 0x6c));
      uVar15 = (ulonglong)*(byte *)(plVar4 + 0x2d);
    }
    cVar8 = '\0';
    local_res10 = '\0';
    if (((plVar4[0x52] != 0) && ((*(int *)(lVar5 + 0xc) != 0 || (*(int *)(lVar5 + 0x10) != 0)))) &&
       ((*(int *)(lVar5 + 0x68) != 0 || (*(int *)(lVar5 + 0x6c) != 0)))) {
      bVar6 = true;
    }
    *(undefined4 *)(plVar4 + 0x58) = *(undefined4 *)(lVar5 + 0xc);
    plVar4[0x34] = (longlong)KeSynchronizeExecution_exref;
    if ((uVar15 & 1) == 0) {
      puVar1 = (uint *)plVar4[0x41];
      if (*puVar1 != 0) {
        lVar14 = 0;
        uVar15 = (ulonglong)*puVar1;
        do {
          uVar2 = *(uint *)(lVar14 + 0x10 + (longlong)puVar1);
          puVar12 = (undefined8 *)0x0;
          if (uVar2 != 0) {
            do {
              pcVar10 = (char *)(lVar14 + ((longlong)puVar12 + 1) * 0x14 + (longlong)puVar1);
              if (*pcVar10 == '\x02') {
                local_res18 = *(undefined4 *)(pcVar10 + 8);
                cVar8 = pcVar10[4];
                local_50 = *(undefined8 *)(pcVar10 + 0xc);
                if (pcVar10[1] == '\x03') {
                  uVar7 = 1;
                }
                break;
              }
              uVar11 = (int)puVar12 + 1;
              puVar12 = (undefined8 *)(ulonglong)uVar11;
            } while (uVar11 < uVar2);
          }
          lVar14 = lVar14 + 0x24;
          uVar15 = uVar15 - 1;
        } while (uVar15 != 0);
        local_res10 = cVar8;
      }
    }
    else {
      DbgPrint("SpCallHwInitialize:  fdoExtension->IsMiniportDetected not supported for 64 bits!\n")
      ;
    }
    cVar8 = local_res10;
    if (local_res10 == '\0') {
      cVar8 = '\0';
    }
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      in_stack_ffffffffffffff70 = local_50;
      WPP_SF_ddq(WPP_GLOBAL_Control[3],puVar12,local_50,local_res18,local_res10,(char)local_50);
    }
    uVar15 = CONCAT71((int7)((ulonglong)in_stack_ffffffffffffff70 >> 8),local_res10);
    iVar9 = IoConnectInterrupt(plVar4 + 0x32,ScsiPortInterrupt,param_1,
                               -(ulonglong)bVar6 & (ulonglong)(plVar4 + 0x37),local_res18,uVar15,
                               cVar8,*(undefined4 *)(lVar5 + 0x14),uVar7,local_50,0);
    if (iVar9 < 0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
         (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_D(WPP_GLOBAL_Control[3],0x4d,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,
                 local_res18);
      }
      plVar4[0x32] = 0;
      return iVar9;
    }
    if (bVar6) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        uVar15 = uVar15 & 0xffffffff00000000;
        WPP_SF_dddq(WPP_GLOBAL_Control[3],0x4e,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,
                    *(undefined4 *)(lVar5 + 0x68),(char)local_res18,local_res10,(char)local_50);
      }
      iVar9 = IoConnectInterrupt(plVar4 + 0x33,ScsiPortInterrupt,param_1,plVar4 + 0x37,0,
                                 uVar15 & 0xffffffffffffff00,cVar8,*(undefined4 *)(lVar5 + 0x70),
                                 uVar7,0,0);
      if (iVar9 < 0) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
           (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_D(WPP_GLOBAL_Control[3],0x4f,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,0);
        }
        plVar4[0x33] = 0;
        *(undefined8 *)(lVar5 + 0x68) = 0;
      }
    }
  }
  uVar7 = 1;
  if (*(int *)(lVar5 + 0x34) != 0) {
    uVar3 = **(undefined4 **)(lVar5 + 0x38);
    *(undefined4 *)((longlong)plVar4 + 0x2c4) = uVar3;
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_D(WPP_GLOBAL_Control[3],0x50,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,uVar3);
    }
  }
  *(uint *)((longlong)plVar4 + 0x17c) = *(uint *)((longlong)plVar4 + 0x17c) | 0x1000;
  *(undefined4 *)((longlong)plVar4 + 0x164) = 0xffffffff;
  if (((plVar4[0x3a] == 0) || (*(char *)(lVar5 + 0x52) == '\0')) ||
     (*(char *)(lVar5 + 0x5a) == '\0')) {
    uVar7 = 0;
  }
  *(undefined1 *)((longlong)plVar4 + 0x48a) = uVar7;
  uVar7 = KfRaiseIrql(2);
  cVar8 = (*(code *)plVar4[0x34])(plVar4[0x32],plVar4[0x50],plVar4[0x29]);
  if (cVar8 == '\0') {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_(WPP_GLOBAL_Control[3],0x51,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids);
    }
    iVar13 = -0x3fffff3e;
  }
  else if ((*(uint *)(plVar4 + 0x6d) & 4) != 0) {
    LOCK();
    puVar1 = (uint *)(*(longlong *)(param_1 + 0x40) + 0x180);
    uVar2 = *puVar1;
    *puVar1 = 0x20004;
    UNLOCK();
    if ((uVar2 >> 0x11 & 1) == 0) {
      KeInsertQueueDpc(param_1 + 200,0,0);
    }
  }
  KeLowerIrql(uVar7);
  return iVar13;
}



===== SpGetBusData @ 140003ef0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
SpGetBusData(longlong param_1,longlong param_2,int param_3,undefined8 param_4,undefined8 param_5,
            undefined8 param_6,undefined4 param_7)

{
  undefined8 uVar1;
  
  if (param_2 == 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_(WPP_GLOBAL_Control[3],0x55,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids);
    }
    uVar1 = 0xc000000d;
  }
  else if (param_3 == 4) {
    uVar1 = (**(code **)(param_1 + 0x6a0))(*(undefined8 *)(param_1 + 0x670),0,param_6,0,param_7);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



===== WPP_SF_Z @ 140003f78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Z(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4)

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
      goto LAB_140003fa1;
    }
  }
  pwVar2 = L"NULL";
LAB_140003fa1:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,param_2,param_4,2,pwVar2,
             wVar1,0);
  return;
}



===== WPP_SF_ZL @ 140003ff4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ZL(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4,
              undefined1 param_5)

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
      goto LAB_14000401d;
    }
  }
  pwVar2 = L"NULL";
LAB_14000401d:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,param_2,param_4,2,pwVar2,
             wVar1,&param_5,4,0);
  return;
}



===== WPP_SF_dL @ 140004088 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dL(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,param_2,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_ddq @ 1400040e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ddq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,0x4c,local_res20,4,
             &param_5,4,&param_6,8,0);
  return;
}



===== WPP_SF_h @ 140004148 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_h(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  undefined2 local_res20 [4];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,0x3d,local_res20,2,0);
  return;
}



===== WPP_SF_i @ 140004194 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_i(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,0x26,&local_res20,8,0);
  return;
}



===== WPP_SF_qDD @ 1400041e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_qddddd @ 140004240 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qddddd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                  undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                  undefined1 param_9)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,0x4b,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,&param_9,4,0);
  return;
}



===== WPP_SF_sL @ 1400042d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sL(undefined8 param_1,undefined2 param_2,undefined8 param_3,char *param_4,
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
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,lVar2,&param_5,4,0);
  return;
}



===== WppClassicProviderCallback @ 140004350 =====

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



===== wil_details_RecordCachedUsage @ 140004384 =====

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



===== wil_details_RecordFeatureUsageReporting @ 1400044e0 =====

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



===== GetLogicalUnitExtension @ 140004564 =====

longlong *
GetLogicalUnitExtension
          (longlong param_1,char param_2,uint param_3,byte param_4,longlong param_5,char param_6)

{
  int *piVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined1 uVar4;
  
  uVar4 = 0;
  lVar3 = ((ulonglong)((param_3 & 0xff) + (uint)param_4 & 7) + 0x2e) * 0x10 + param_1;
  if (param_6 != '\0') {
    uVar4 = KeAcquireSpinLockRaiseToDpc(lVar3);
  }
  plVar2 = *(longlong **)(lVar3 + 8);
  while( true ) {
    if (plVar2 == (longlong *)0x0) {
      if (param_6 != '\0') {
        KeReleaseSpinLock(lVar3,uVar4);
      }
      return (longlong *)0x0;
    }
    if (((*(char *)((longlong)plVar2 + 0x155) == (char)param_3) &&
        (*(char *)((longlong)plVar2 + 0x154) == param_2)) &&
       (*(byte *)((longlong)plVar2 + 0x156) == param_4)) break;
    plVar2 = (longlong *)plVar2[0x35];
  }
  if (param_5 != 0) {
    LOCK();
    piVar1 = (int *)(*(longlong *)(*plVar2 + 0x40) + 0x4c);
    *piVar1 = *piVar1 + 1;
    UNLOCK();
  }
  if (param_6 != '\0') {
    KeReleaseSpinLock(lVar3,uVar4);
  }
  return plVar2;
}



===== GetNextLuRequest @ 140004654 =====

void GetNextLuRequest(longlong *param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  undefined8 *puVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  
  uVar1 = *(uint *)(param_1 + 0x28);
  puVar2 = (undefined8 *)param_1[0x2d];
  if ((((uVar1 & 2) == 0) || (*(byte *)(param_1 + 0x3f) <= *(byte *)((longlong)param_1 + 0x1f9))) ||
     ((uVar1 & 0x41) != 0)) {
LAB_140004732:
    KeReleaseSpinLockFromDpcLevel(puVar2 + 0x36);
  }
  else {
    if ((uVar1 & 0x3c) == 0) {
      *(uint *)(param_1 + 0x28) = uVar1 & 0xfffffffd;
      lVar4 = KeRemoveByKeyDeviceQueueIfBusy(*param_1 + 0xa0,(int)param_1[0x2b]);
      if (lVar4 == 0) goto LAB_140004732;
      lVar5 = lVar4 + -0x78;
      lVar3 = *(longlong *)(*(longlong *)(lVar4 + 0x40) + 8);
      lVar4 = *(longlong *)(lVar3 + 0x30);
      UpdateQueuePointers((longlong)param_1,lVar3,param_3);
      KeReleaseSpinLockFromDpcLevel(puVar2 + 0x36);
    }
    else {
      if (((longlong *)param_1[0x3a] != param_1 + 0x3a) || ((uVar1 & 0x1c) != 0)) {
        if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
            (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
          WPP_SF_(WPP_GLOBAL_Control[3],0x39,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids);
        }
        goto LAB_140004732;
      }
      lVar4 = param_1[0x3c];
      param_1[0x3c] = 0;
      *(uint *)(param_1 + 0x28) = uVar1 & 0xffffffdd;
      *(undefined1 *)((longlong)param_1 + 0x157) = 0;
      KeReleaseSpinLockFromDpcLevel(puVar2 + 0x36);
      lVar5 = *(longlong *)(lVar4 + 0x38);
    }
    *(undefined4 *)(lVar4 + 0x90) = *(undefined4 *)((longlong)puVar2 + 0x6e4);
    IoStartPacket(*puVar2,lVar5,0,0);
  }
  return;
}



===== IssueRequestSense @ 1400047f0 =====

void IssueRequestSense(longlong *param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  bool bVar3;
  
  bVar3 = true;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
     (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_(WPP_GLOBAL_Control[3],0x26,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids);
  }
  lVar1 = *(longlong *)(param_2 + 0x30);
  puVar2 = *(undefined8 **)(lVar1 + 0x30);
  KeAcquireSpinLockAtDpcLevel(puVar2[0x2d] + 0x1b0);
  if (puVar2[0x1dc] == lVar1) {
    bVar3 = false;
  }
  else if (puVar2[0x1dd] != lVar1) {
    bVar3 = false;
    DbgPrint("Scsiport: unexpected request sense for srb %#08lx\n",param_2);
  }
  KeReleaseSpinLockFromDpcLevel(puVar2[0x2d] + 0x1b0);
  if (!bVar3) {
    SpSendRequestSenseIrp(param_1,puVar2,param_2);
  }
  return;
}



===== IssueRequestSenseCompletion @ 1400048f0 =====

undefined8 IssueRequestSenseCompletion(undefined8 param_1,ulonglong param_2,longlong *param_3)

{
  byte *pbVar1;
  undefined *puVar2;
  longlong lVar3;
  longlong lVar4;
  byte bVar5;
  undefined1 uVar6;
  undefined8 uVar7;
  longlong lVar8;
  
  puVar2 = (undefined *)param_3[0x1dc];
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
     (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_(WPP_GLOBAL_Control[3],0x28,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids);
  }
  lVar3 = *(longlong *)(puVar2 + 0x38);
  lVar4 = *(longlong *)(puVar2 + 0x40);
  lVar8 = *(longlong *)param_3[0x2d];
  if (*(char *)(lVar3 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(lVar3 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  bVar5 = *(byte *)((longlong)param_3 + 0xefb) & 0x3f;
  if ((bVar5 == 1) || (bVar5 == 0x12)) {
    *(byte *)(lVar4 + 3) = *(byte *)(lVar4 + 3) | 0x80;
    *(char *)(lVar4 + 0xb) = (char)param_3[0x1e1];
    if (*(char *)(param_3[0x2d] + 0x749) != '\0') {
      uVar7 = SpFireSenseDataEvent(lVar4,lVar8);
      if ((((int)uVar7 != 0) && ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x40) != 0 &&
          (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
        WPP_SF_D(WPP_GLOBAL_Control[3],0x29,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,
                 (int)uVar7);
      }
    }
  }
  if (((*(uint *)(lVar4 + 0xc) & 0x100) != 0) && ((*(byte *)(lVar4 + 3) & 0x40) != 0)) {
    SpFlushReleaseQueue(param_3,0,(undefined *)0x0);
    *(byte *)(lVar4 + 3) = *(byte *)(lVar4 + 3) & 0xbf;
  }
  uVar6 = KeAcquireSpinLockRaiseToDpc(param_3[0x2d] + 0x1b0);
  lVar4 = param_3[0x1dd];
  param_3[0x1dd] = 0;
  param_3[0x1dc] = lVar4;
  if (lVar4 == 0) {
    *(uint *)(param_3 + 0x28) = *(uint *)(param_3 + 0x28) & 0xfffffffb;
  }
  KeReleaseSpinLock(param_3[0x2d] + 0x1b0,uVar6);
  SpReleaseRemoveLock(lVar8,(char)lVar3);
  SpCompleteRequest(lVar8,lVar3,puVar2,1);
  if ((*(byte *)((longlong)param_3 + 0xf5a) & 0x20) != 0) {
    MmUnmapLockedPages(param_3[0x1ed],param_3 + 0x1ea);
  }
  if (lVar4 != 0) {
    SpSendRequestSenseIrp((longlong *)param_3[0x2d],param_3,*(longlong *)(param_3[0x1dc] + 0x40));
  }
  return 0xc0000016;
}



===== LogErrorEntry @ 140004adc =====

void LogErrorEntry(undefined8 *param_1,longlong param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  puVar3 = (undefined1 *)IoAllocateErrorLogEntry(*param_1,0x40);
  if (puVar3 == (undefined1 *)0x0) {
    return;
  }
  iVar1 = *(int *)(param_2 + 4);
  if (iVar1 == 1) {
    *(undefined4 *)(puVar3 + 0xc) = 0xc0040005;
    goto LAB_140004b66;
  }
  if ((iVar1 != 2) && (iVar1 != 3)) {
    if (iVar1 == 4) {
      *(undefined4 *)(puVar3 + 0xc) = 0xc0040009;
      goto LAB_140004b66;
    }
    if ((iVar1 != 5) && (iVar1 != 6)) {
      if (iVar1 == 8) {
        *(undefined4 *)(puVar3 + 0xc) = 0xc004000d;
        goto LAB_140004b66;
      }
      if (iVar1 == 9) {
        *(undefined4 *)(puVar3 + 0xc) = 0x8004001a;
        goto LAB_140004b66;
      }
      if (iVar1 == 10) {
        *(undefined4 *)(puVar3 + 0xc) = 0xc0040019;
        goto LAB_140004b66;
      }
    }
  }
  *(undefined4 *)(puVar3 + 0xc) = 0xc004000b;
LAB_140004b66:
  *(undefined4 *)(puVar3 + 0x18) = *(undefined4 *)(param_2 + 0x10);
  *puVar3 = 0xf;
  puVar3[1] = *(undefined1 *)(param_2 + 0xc);
  uVar2 = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(puVar3 + 0x14) = 0;
  *(undefined4 *)(puVar3 + 0x10) = uVar2;
  *(undefined2 *)(puVar3 + 2) = 0x10;
  *(uint *)(puVar3 + 0x28) = (uint)*(byte *)(param_2 + 1);
  *(uint *)(puVar3 + 0x2c) = (uint)*(byte *)(param_2 + 2);
  *(uint *)(puVar3 + 0x30) = (uint)*(byte *)(param_2 + 3);
  *(undefined4 *)(puVar3 + 0x34) = *(undefined4 *)(param_2 + 4);
  IoWriteErrorLogEntry(puVar3);
  return;
}



===== ScsiPortAllocationRoutine @ 140004bd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

char ScsiPortAllocationRoutine(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  cVar1 = *(char *)(*(longlong *)(lVar2 + 0x1f8) + 0x52);
  uVar4 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x1b0,-cVar1);
  if (*(char *)(*(longlong *)(lVar2 + 0x1f8) + 0x52) == '\0') {
    *(undefined8 *)(lVar2 + 0x1c8) = param_3;
  }
  else {
    lVar3 = *(longlong *)
             (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x20) + 0xb8) + 8) + 0x30);
    *(undefined8 *)(lVar3 + 0x58) = param_3;
    *(undefined4 *)(lVar3 + 0x60) = *(undefined4 *)(lVar2 + 0x3ec);
  }
  (**(code **)(lVar2 + 0x1a0))(*(undefined8 *)(lVar2 + 400),SpStartIoSynchronized,param_1);
  KeReleaseSpinLock(lVar2 + 0x1b0,uVar4);
  return (-(cVar1 != '\0') & 2U) + 1;
}



===== ScsiPortCompletionDpc @ 140004cb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ScsiPortCompletionDpc
               (undefined8 param_1,longlong *param_2,undefined8 param_3,longlong *param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  uint uVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong lVar6;
  longlong **pplVar7;
  char cVar8;
  undefined4 uVar9;
  uint uVar10;
  code *pcVar11;
  undefined4 *puVar12;
  byte bVar13;
  longlong *plVar14;
  code *pcVar15;
  longlong **pplVar16;
  longlong **pplVar17;
  undefined1 auStack_118 [32];
  char local_d8 [8];
  longlong *local_d0;
  uint *local_c8;
  uint local_b8 [2];
  longlong **local_b0;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined8 local_98;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined1 local_88 [24];
  longlong *local_70;
  longlong local_68;
  code *local_60;
  int local_58;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_118;
  plVar4 = (longlong *)param_2[8];
  local_b8[1] = 0;
  memset(local_b8,0,0x74);
  plVar1 = plVar4 + 0x36;
  local_d8[0] = '\0';
  pplVar17 = (longlong **)0x0;
  do {
    KeAcquireSpinLockAtDpcLevel(plVar1);
    local_c8 = local_b8;
    pplVar16 = &local_d0;
    pcVar15 = SpGetInterruptState;
    local_d0 = plVar4;
    cVar8 = (*(code *)plVar4[0x34])(plVar4[0x32]);
    if (cVar8 == '\0') {
LAB_140005288:
      KeReleaseSpinLockFromDpcLevel(plVar1);
    }
    else {
      if ((local_b8[0] & 0x170030) != 0) {
        if ((local_b8[0] & 0x10) != 0) {
          if (Sp64BitPhysicalAddresses != 0) {
                    /* WARNING: Subroutine does not return */
            KeBugCheckEx(0x2c,3,0xffffffffc00000bb,plVar4[0x29]);
          }
          param_4 = (longlong *)plVar4[0x3d];
          pcVar15 = *(code **)(*(longlong *)(plVar4[0x3b] + 0x38) + 8);
          pplVar16 = (longlong **)plVar4[0x39];
          (**(code **)(*(longlong *)(plVar4[0x3a] + 8) + 0x28))();
        }
        if ((local_b8[0] & 0x80020) == 0x20) {
          if (Sp64BitPhysicalAddresses != 0) {
                    /* WARNING: Subroutine does not return */
            KeBugCheckEx(0x2c,4,0xffffffffc00000bb,plVar4[0x29]);
          }
          pplVar17 = (longlong **)CONCAT44(uStack_a4,local_a8);
          lVar5 = pplVar17[7][1];
          if ((longlong *)(ulonglong)*(uint *)(pplVar17[8] + 2) <= local_98) {
            local_98 = (longlong *)((longlong)local_98 - pplVar17[8][3]);
          }
          param_4 = (longlong *)
                    ((longlong)pplVar17[0xd] +
                     *(longlong *)(lVar5 + 0x20) + (ulonglong)*(uint *)(lVar5 + 0x2c) +
                    (longlong)local_98);
          pplVar16 = (longlong **)plVar4[0x39];
          local_98 = param_4;
          (**(code **)(*(longlong *)(plVar4[0x3a] + 8) + 0x40))(plVar4[0x3a],lVar5);
          pcVar15 = (code *)plVar4[0x54];
          *(undefined4 *)(plVar4 + 0x3b) = local_a8;
          *(undefined4 *)((longlong)plVar4 + 0x1dc) = uStack_a4;
          *(undefined4 *)(plVar4 + 0x3c) = uStack_a0;
          *(undefined4 *)((longlong)plVar4 + 0x1e4) = uStack_9c;
          *(undefined4 *)(plVar4 + 0x3d) = (undefined4)local_98;
          *(undefined4 *)((longlong)plVar4 + 0x1ec) = local_98._4_4_;
          *(undefined4 *)(plVar4 + 0x3e) = uStack_90;
          *(undefined4 *)((longlong)plVar4 + 500) = uStack_8c;
          if (pcVar15 != (code *)0x0) {
            pplVar16 = (longlong **)plVar4[0x29];
            (*(code *)plVar4[0x34])(plVar4[0x32]);
          }
          if ((*(uint *)(plVar4 + 0x6d) & 4) != 0) {
            LOCK();
            *(undefined4 *)(plVar4 + 0x30) = 0x20004;
            UNLOCK();
          }
        }
        if ((local_b8[0] & 0x90000) == 0x10000) {
          pcVar11 = local_60;
          if (plVar4[0xec] != 0) {
            *(code **)(plVar4[0xec] + 0x38) = local_60;
            pcVar11 = SpHwTimerRequestVrfy;
          }
          plVar4[0x56] = (longlong)pcVar11;
          if (local_58 == 0) {
            KeCancelTimer(plVar4 + 0x80);
          }
          else if ((*(uint *)((longlong)plVar4 + 0x17c) & 0x800000) == 0) {
            pcVar15 = (code *)((longlong)local_58 * -10);
            pplVar16 = (longlong **)(plVar4 + 0x88);
            KeSetTimer(plVar4 + 0x80);
          }
        }
        if ((local_b8[0] & 0x20000) != 0) {
          pcVar15 = (code *)local_b8;
          SpCompletionDpcProcessWmi((longlong)param_2,(longlong)pcVar15,(undefined *)pplVar16);
        }
        if ((local_b8[0] & 0x40000) != 0) {
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            param_4 = (longlong *)plVar4[0x28];
            pplVar16 = (longlong **)&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids;
            WPP_SF_qq(WPP_GLOBAL_Control[3],0x1a,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,
                      param_4,(char)plVar4);
          }
          pcVar15 = (code *)0x0;
          *(undefined4 *)(plVar4 + 0xa8) = 1;
          IoInvalidateDeviceRelations(plVar4[0x28]);
        }
        if ((local_b8[0] & 0x100000) != 0) {
          puVar12 = (undefined4 *)IoAllocateErrorLogEntry(*plVar4,0x30);
          if (puVar12 != (undefined4 *)0x0) {
            puVar12[3] = 0x80040035;
            *(undefined8 *)(puVar12 + 5) = 0x103;
            *puVar12 = 0;
            puVar12[4] = 0x215;
            IoWriteErrorLogEntry(puVar12);
          }
          pcVar15 = (code *)*plVar4;
          DbgPrint(
                  "SpTimeoutSynchronized: Adapter %#p had interrupt pending - the system may not be delivering interrupts from this adapter\n"
                  );
          if (ScsiCheckInterrupts != 0) {
            pcVar15 = (code *)swi(3);
            (*pcVar15)();
            return;
          }
        }
      }
      if ((local_b8[0] & 8) != 0) {
        uVar3 = *(uint *)((longlong)plVar4 + 0x17c);
        *(uint *)((longlong)plVar4 + 0x17c) = uVar3 & 0xfffffffe;
        if ((uVar3 & 0x1001) == 0x1001) {
          if ((local_b8[0] & 0x80) == 0) {
            *(undefined4 *)(plVar4 + 0x31) = 0xffffffff;
          }
        }
        else {
          local_b8[0] = local_b8[0] & 0xfffffff7;
        }
      }
      if ((local_b8[0] & 0x200) != 0) {
        *(int *)(plVar4 + 0x31) = (int)plVar4[0xf4];
      }
      plVar14 = local_70;
      while (plVar14 != (longlong *)0x0) {
        GetNextLuRequest(plVar14,pcVar15,pplVar16);
        KeAcquireSpinLockAtDpcLevel(plVar1);
        plVar2 = plVar14 + 0x36;
        plVar14 = (longlong *)*plVar2;
        *plVar2 = 0;
      }
      KeReleaseSpinLockFromDpcLevel(plVar1);
      if ((local_b8[0] & 0x108) == 8) {
        IoStartNextPacket(*plVar4,0);
      }
      if ((local_b8[0] & 0x40) != 0) {
        LogErrorEntry(plVar4,(longlong)local_88);
      }
      local_d8[0] = '\0';
      while (pplVar7 = local_b0, local_b0 != (longlong **)0x0) {
        pplVar16 = (longlong **)local_d8;
        pplVar17 = (longlong **)local_b0[9];
        local_b0[9] = (longlong *)0x0;
        local_b0 = pplVar17;
        SpProcessCompletedRequest(plVar4,(undefined *)pplVar7,(char *)pplVar16);
        pplVar17 = pplVar7;
      }
      while (lVar5 = local_68, local_68 != 0) {
        local_68 = *(longlong *)(local_68 + 0x1b8);
        KeAcquireSpinLockAtDpcLevel(plVar1);
        plVar14 = *(longlong **)(*(longlong *)(lVar5 + 0x1c0) + 0x38);
        if (plVar14 != (longlong *)0x0) {
          if ((plVar4[0xec] == 0) || ((*(uint *)(plVar4[0xec] + 100) & 1) == 0)) {
            *plVar14 = plVar4[0x46];
            plVar4[0x46] = *(longlong *)(*(longlong *)(lVar5 + 0x1c0) + 0x38);
          }
          else {
            SpInsertSrbExtension((longlong)plVar4,(ulonglong)plVar14);
          }
        }
        lVar6 = *(longlong *)(*(longlong *)(lVar5 + 0x1c0) + 0x30);
        bVar13 = *(byte *)(*(longlong *)(lVar5 + 0x1c0) + 3) & 0x3f;
        if (bVar13 == 1) {
          uVar9 = 0;
        }
        else if (bVar13 < 0x13) {
          if (bVar13 == 0x12) {
            uVar9 = 0x80000005;
          }
          else if (bVar13 == 8) {
LAB_140005188:
            uVar9 = 0xc00000c0;
          }
          else {
            if (bVar13 != 9) {
              if (bVar13 == 10) {
                uVar9 = 0xc000009d;
                goto LAB_1400051c4;
              }
              if (bVar13 != 0xb) {
                if (bVar13 != 0x11) goto LAB_1400051b8;
                goto LAB_140005188;
              }
            }
            uVar9 = 0xc00000b5;
          }
        }
        else {
          if (bVar13 != 0x15) {
            if ((bVar13 == 0x20) || (bVar13 == 0x21)) goto LAB_140005188;
            if (bVar13 != 0x22) {
LAB_1400051b8:
              uVar9 = 0xc0000185;
              goto LAB_1400051c4;
            }
          }
          uVar9 = 0xc0000010;
        }
LAB_1400051c4:
        *(undefined4 *)(lVar6 + 0x30) = uVar9;
        *(undefined8 *)(lVar6 + 0x38) = 0;
        *(undefined8 *)(lVar5 + 0x1c0) = 0;
        KeReleaseSpinLockFromDpcLevel(plVar1);
        SpDecrementActiveRequestCount((longlong)plVar4);
        plVar14 = param_2;
        SpReleaseRemoveLock((longlong)param_2,(char)lVar6);
        param_4 = (longlong *)CONCAT71((int7)((ulonglong)param_4 >> 8),1);
        pplVar16 = pplVar17;
        SpCompleteRequest(plVar14,lVar6,(undefined *)pplVar17,1);
      }
      if (local_d8[0] != '\0') {
        ScsiPortStartIo(param_2,(char *)param_2[4],(undefined *)pplVar16,param_4);
      }
      if ((local_b8[0] & 0x88000) == 0x8000) {
        KeAcquireSpinLockAtDpcLevel(plVar1);
        (*(code *)plVar4[0x55])(plVar4[0x29]);
        if ((*(uint *)((longlong)plVar4 + 0x17c) >> 0xd & 1) != 0) {
          *(uint *)((longlong)plVar4 + 0x17c) = *(uint *)((longlong)plVar4 + 0x17c) & 0xffffdfff;
          (*(code *)plVar4[0x34])(plVar4[0x32],SpEnableInterruptSynchronized,plVar4);
        }
        goto LAB_140005288;
      }
    }
    uVar10 = 0;
    LOCK();
    uVar3 = *(uint *)(plVar4 + 0x30);
    if (uVar3 == 0x20000) {
      *(uint *)(plVar4 + 0x30) = 0;
    }
    else {
      uVar10 = uVar3;
    }
    UNLOCK();
    if ((uVar10 & 4) == 0) {
      return;
    }
  } while( true );
}



===== ScsiPortFdoDispatch @ 140005340 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint ScsiPortFdoDispatch(longlong param_1,undefined *param_2)

{
  int *piVar1;
  byte bVar2;
  undefined4 uVar3;
  undefined8 *puVar4;
  byte *pbVar5;
  longlong lVar6;
  longlong lVar7;
  undefined1 uVar8;
  char cVar9;
  undefined1 uVar10;
  char cVar11;
  uint uVar12;
  longlong *plVar13;
  undefined1 *puVar14;
  undefined1 uVar15;
  undefined *puVar16;
  undefined8 *local_58;
  undefined8 uStack_50;
  
  puVar4 = *(undefined8 **)(param_1 + 0x40);
  pbVar5 = *(byte **)(param_2 + 0xb8);
  uVar8 = 1;
  lVar6 = *(longlong *)(pbVar5 + 8);
  puVar16 = *(undefined **)(lVar6 + 0x30);
  if (puVar16 == param_2) {
    puVar16 = (undefined *)0x0;
  }
  LOCK();
  *(int *)((longlong)puVar4 + 0x4c) = *(int *)((longlong)puVar4 + 0x4c) + 1;
  UNLOCK();
  cVar9 = (char)param_2;
  if ((*(int *)((longlong)puVar4 + 0xc) == 0) ||
     ((bVar2 = *pbVar5, bVar2 < 0x13 && ((0x50004U >> (bVar2 & 0x1f) & 1) != 0)))) {
LAB_1400053cd:
    if (((*(int *)(puVar4 + 5) < 6) || (*(int *)((longlong)puVar4 + 0x2c) == 1)) ||
       ((byte)(*(char *)(lVar6 + 2) - 0x18U) < 2)) {
      if (puVar16 == (undefined *)0x0) {
        uVar12 = (uint)CONCAT71((int7)((ulonglong)param_1 >> 8),*(undefined1 *)(lVar6 + 6));
        plVar13 = GetLogicalUnitExtension
                            ((longlong)puVar4,*(char *)(lVar6 + 5),uVar12,*(byte *)(lVar6 + 7),0,
                             '\x01');
        if (plVar13 == (longlong *)0x0) {
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_(WPP_GLOBAL_Control[3],10,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids);
          }
          uVar12 = 0xc000000e;
          *(undefined1 *)(lVar6 + 3) = 8;
          *(undefined4 *)(param_2 + 0x30) = 0xc000000e;
          SpReleaseRemoveLock(param_1,cVar9);
          puVar16 = (undefined *)0x0;
          goto LAB_140005409;
        }
        bVar2 = *(byte *)(lVar6 + 2);
        if ((((bVar2 & 0xf9) == 0) && (bVar2 != 6)) || (bVar2 == 0x15)) {
          uVar12 = SpRerouteLegacyRequest(param_1,(longlong)param_2,uVar12);
          return uVar12;
        }
      }
      else {
        plVar13 = *(longlong **)(puVar16 + 0x30);
      }
      bVar2 = *(byte *)(lVar6 + 2);
      if (bVar2 < 9) {
        if (bVar2 == 8) {
LAB_140005528:
          if (*(char *)(puVar4 + 0x92) == '\0') {
            *(undefined4 *)(param_2 + 0x30) = 0;
            *(undefined1 *)(lVar6 + 3) = 1;
            SpReleaseRemoveLock(param_1,cVar9);
            SpCompleteRequest(param_1,param_2,puVar16,0);
            return 0;
          }
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_(WPP_GLOBAL_Control[3],0xb,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids);
          }
        }
        else if (bVar2 != 0) {
          if (bVar2 != 1) {
            if (bVar2 == 2) goto LAB_1400055bb;
            if (bVar2 == 4) goto LAB_140005727;
            if ((bVar2 != 5) && (bVar2 != 6)) {
              if (bVar2 != 7) goto LAB_140005688;
              goto LAB_140005528;
            }
          }
          LOCK();
          piVar1 = (int *)(*(longlong *)(*plVar13 + 0x40) + 0x4c);
          *piVar1 = *piVar1 + 1;
          UNLOCK();
          uVar12 = SpClaimLogicalUnit((longlong)puVar4,plVar13,(longlong)param_2,'\x01');
          SpReleaseRemoveLock(*plVar13,cVar9 + '\x02');
LAB_140005872:
          *(uint *)(param_2 + 0x30) = uVar12;
          SpReleaseRemoveLock(param_1,cVar9);
          SpCompleteRequest(param_1,param_2,puVar16,0);
          return uVar12;
        }
LAB_1400055bb:
        *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) =
             *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) | 1;
        uVar12 = *(uint *)(lVar6 + 0xc) & 0x80010;
        if ((uVar12 != 0) && ((uVar12 >> 0x13 == 0 || ((*(uint *)(plVar13 + 0x28) & 0xc0) != 0)))) {
          if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
              (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
            WPP_SF_q(WPP_GLOBAL_Control[3],0xc,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,
                     param_2);
          }
          *(undefined4 *)(puVar16 + 0x90) = *(undefined4 *)((longlong)puVar4 + 0x6e4);
          IoStartPacket(param_1,param_2,0,0);
          return 0x103;
        }
        uVar8 = KfRaiseIrql(2);
        *(undefined4 *)(puVar16 + 0x90) = *(undefined4 *)((longlong)puVar4 + 0x6e4);
        cVar9 = KeInsertByKeyDeviceQueue
                          (*plVar13 + 0xa0,param_2 + 0x78,*(undefined4 *)(lVar6 + 0x40));
        if (cVar9 != '\0') goto LAB_140005908;
        *(undefined1 *)((longlong)plVar13 + 0x157) = 0;
      }
      else {
        if (bVar2 != 0x10) {
          if (bVar2 == 0x12) {
            local_58 = (undefined8 *)0x0;
            uStack_50 = 0;
            uVar10 = KeAcquireSpinLockRaiseToDpc(puVar4 + 0x36);
            uStack_50 = CONCAT71(uStack_50._1_7_,*(undefined1 *)(lVar6 + 5));
            local_58 = puVar4;
            cVar11 = (*(code *)puVar4[0x34])(puVar4[0x32],SpResetBusSynchronized,&local_58);
            if (cVar11 == '\0') {
              if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                WPP_SF_(WPP_GLOBAL_Control[3],0x10,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids)
                ;
              }
              uVar12 = 0xc0000185;
              uVar8 = 0x14;
            }
            else {
              bVar2 = *(byte *)(lVar6 + 5);
              uVar3 = *(undefined4 *)(lVar6 + 0x14);
              lVar7 = *(longlong *)(*(longlong *)(lVar6 + 0x30) + 0x38);
              if (lVar7 == 0) {
                uVar15 = 0;
              }
              else {
                uVar15 = **(undefined1 **)(lVar7 + 0xb8);
              }
              puVar14 = (undefined1 *)IoAllocateErrorLogEntry(*puVar4,0x38);
              if (puVar14 != (undefined1 *)0x0) {
                *(undefined4 *)(puVar14 + 0x14) = 0;
                *(undefined4 *)(puVar14 + 0xc) = 0x80040076;
                *puVar14 = uVar15;
                *(undefined4 *)(puVar14 + 0x10) = 0x52000100;
                *(undefined2 *)(puVar14 + 2) = 8;
                *(uint *)(puVar14 + 0x28) = (uint)bVar2;
                *(undefined4 *)(puVar14 + 0x2c) = uVar3;
                IoWriteErrorLogEntry(puVar14);
              }
              uVar12 = 0;
            }
            *(undefined1 *)(lVar6 + 3) = uVar8;
            KeReleaseSpinLock(puVar4 + 0x36,uVar10);
            goto LAB_140005872;
          }
          if (bVar2 == 0x15) {
LAB_140005727:
            uVar12 = SpFlushReleaseQueue(plVar13,(ulonglong)(bVar2 == 0x15),(undefined *)0x0);
            uVar8 = 1;
            if ((int)uVar12 < 0) {
              uVar8 = 4;
            }
            *(undefined1 *)(lVar6 + 3) = uVar8;
            goto LAB_140005872;
          }
          if (((bVar2 != 0x17) && (bVar2 != 0x18)) && (bVar2 != 0x19)) {
LAB_140005688:
            if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              WPP_SF_q(WPP_GLOBAL_Control[3],0x12,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,
                       lVar6);
            }
            *(undefined1 *)(lVar6 + 3) = 6;
            uVar12 = 0xc0000010;
            goto LAB_140005872;
          }
          goto LAB_1400055bb;
        }
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_(WPP_GLOBAL_Control[3],0x11,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids);
        }
        *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) =
             *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) | 1;
        uVar8 = KfRaiseIrql(2);
      }
      IoStartPacket(param_1,param_2,0,0);
LAB_140005908:
      KeLowerIrql(uVar8);
      return 0x103;
    }
    *(undefined1 *)(lVar6 + 3) = 0x30;
    uVar12 = 0xc00002d3;
    *(undefined4 *)(lVar6 + 0x40) = 0xc00002d3;
  }
  else {
    if (bVar2 == 0xf) {
      cVar11 = *(char *)(*(longlong *)(pbVar5 + 8) + 2);
      if (((cVar11 == '\x06') || (cVar11 == '\x15')) ||
         ((*(uint *)(*(longlong *)(pbVar5 + 8) + 0xc) & 0x80010) != 0)) goto LAB_1400053cd;
    }
    *(undefined1 *)(lVar6 + 3) = 8;
    uVar12 = 0xc00000c0;
  }
  *(uint *)(param_2 + 0x30) = uVar12;
  SpReleaseRemoveLock(param_1,cVar9);
LAB_140005409:
  SpCompleteRequest(param_1,param_2,puVar16,0);
  return uVar12;
}



===== ScsiPortInterrupt @ 140005940 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

char ScsiPortInterrupt(undefined8 param_1,longlong param_2)

{
  uint *puVar1;
  uint uVar2;
  longlong lVar3;
  char cVar4;
  
  lVar3 = *(longlong *)(param_2 + 0x40);
  if ((*(uint *)(lVar3 + 0x368) & 0x84000) == 0) {
    cVar4 = (**(code **)(lVar3 + 0x290))(*(undefined8 *)(lVar3 + 0x148));
    if (cVar4 == '\0') {
      *(undefined4 *)(lVar3 + 0x3dc) = *(undefined4 *)(lVar3 + 0x6e4);
    }
    else {
      *(undefined4 *)(lVar3 + 0x3d8) = *(undefined4 *)(lVar3 + 0x6e4);
      *(undefined4 *)(lVar3 + 0x3e0) = 1;
    }
    if ((*(uint *)(lVar3 + 0x368) & 4) != 0) {
      LOCK();
      puVar1 = (uint *)(*(longlong *)(param_2 + 0x40) + 0x180);
      uVar2 = *puVar1;
      *puVar1 = 0x20004;
      UNLOCK();
      if ((uVar2 >> 0x11 & 1) == 0) {
        KeInsertQueueDpc(param_2 + 200,0,0);
      }
    }
  }
  else {
    cVar4 = '\0';
  }
  return cVar4;
}



===== ScsiPortStartIo @ 1400059f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ScsiPortStartIo(longlong *param_1,char *param_2,undefined *param_3,longlong *param_4)

{
  longlong *plVar1;
  uint *puVar2;
  int *piVar3;
  byte bVar4;
  undefined8 *puVar5;
  char *pcVar6;
  longlong lVar7;
  undefined *puVar8;
  undefined8 *puVar9;
  char cVar10;
  int iVar11;
  undefined8 uVar12;
  longlong lVar13;
  longlong *plVar14;
  undefined1 uVar15;
  uint uVar16;
  undefined *puVar17;
  char *pcVar18;
  char local_res8 [8];
  char local_res10 [16];
  undefined1 uVar19;
  char *in_stack_ffffffffffffff88;
  undefined4 in_stack_ffffffffffffffa0;
  
  puVar5 = (undefined8 *)param_1[8];
  pcVar6 = *(char **)(param_2 + 0xb8);
  local_res10[0] = '\0';
  pcVar18 = param_2;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
     (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    pcVar18 = (char *)0x0;
    param_3 = &WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids;
    WPP_SF_(WPP_GLOBAL_Control[3],0x13,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids);
  }
  cVar10 = *pcVar6;
  if (cVar10 != '\x0f') {
    if (cVar10 != '\x16') {
      KeSetEvent(*(undefined8 *)(param_2 + 0x38),0,0);
      return;
    }
    puVar5 = *(undefined8 **)(param_2 + 0xb8);
    lVar13 = param_1[8];
    if (*(int *)(puVar5 + 2) == 0) {
      SpProcessAdapterSystemState(param_1,(longlong)param_2,param_3,param_4);
      return;
    }
    if (*(int *)(puVar5 + 3) == 1) {
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
      lVar7 = *(longlong *)(param_2 + 0xb8);
      *(code **)(lVar7 + -0x10) = SpSetLowerPowerCompletion;
      *(undefined8 *)(lVar7 + -8) = 0;
      *(undefined1 *)(lVar7 + -0x45) = 0xe0;
      PoCallDriver(*(undefined8 *)(lVar13 + 0x10),param_2);
      return;
    }
    SpProcessAdapterDeviceState((longlong)param_1,(longlong)param_2,param_3);
    return;
  }
  pcVar6 = *(char **)(pcVar6 + 8);
  puVar8 = *(undefined **)(pcVar6 + 0x30);
  pcVar6[3] = '\0';
  if (pcVar6[2] == '\0') {
    pcVar6[4] = '\0';
  }
  iVar11 = *(int *)((longlong)puVar5 + 0xc);
  plVar14 = *(longlong **)(puVar8 + 0x30);
  uVar15 = SUB81(param_2,0);
  if ((iVar11 != 0) &&
     ((((*(uint *)(pcVar6 + 0xc) & 0x80010) != 0 &&
       (((*(uint *)(pcVar6 + 0xc) & 0x80010) >> 0x13 == 0 ||
        ((*(uint *)(plVar14 + 0x28) & 0xc0) != 0)))) || (iVar11 == 1)))) {
    if ((iVar11 == 1) && (*(char *)((longlong)puVar5 + 9) == '\0')) {
      SpFlushReleaseQueue(plVar14,CONCAT71((int7)((ulonglong)pcVar18 >> 8),1),
                          (undefined *)CONCAT71((int7)((ulonglong)param_3 >> 8),1));
    }
    LOCK();
    *(int *)(param_1[8] + 0x4c) = *(int *)(param_1[8] + 0x4c) + 1;
    UNLOCK();
    plVar14 = param_1;
    SpReleaseRemoveLock((longlong)param_1,uVar15);
    param_2[0x30] = -0x40;
    param_2[0x31] = '\0';
    param_2[0x32] = '\0';
    param_2[0x33] = -0x40;
    pcVar6[3] = '\b';
    SpCompleteRequest(plVar14,param_2,puVar8,1);
    IoStartNextPacket(param_1,0);
    SpReleaseRemoveLock((longlong)param_1,0xf0);
    return;
  }
  if ((*(uint *)(plVar14 + 0x28) & 0x20) != 0) {
    KeAcquireSpinLockAtDpcLevel(puVar5 + 0x36);
    if (((*(uint *)(plVar14 + 0x28) & 0x20) != 0) &&
       (((*(uint *)(pcVar6 + 0xc) & 0x80010) == 0 ||
        (((*(uint *)(pcVar6 + 0xc) & 0x80010) >> 0x13 != 0 &&
         ((*(uint *)(plVar14 + 0x28) & 0xc0) == 0)))))) {
      cVar10 = KeInsertByKeyDeviceQueue
                         (*plVar14 + 0xa0,param_2 + 0x78,*(undefined4 *)(pcVar6 + 0x40));
      if (cVar10 == '\0') {
        KeInsertByKeyDeviceQueue(*plVar14 + 0xa0,param_2 + 0x78,*(undefined4 *)(pcVar6 + 0x40));
      }
      *(undefined4 *)(plVar14 + 0x2b) = *(undefined4 *)(pcVar6 + 0x40);
      KeReleaseSpinLockFromDpcLevel(puVar5 + 0x36);
      param_1 = (longlong *)*puVar5;
      goto LAB_140005c62;
    }
    KeReleaseSpinLockFromDpcLevel(puVar5 + 0x36);
  }
  uVar16 = *(uint *)(puVar5 + 3);
  *(uint *)(pcVar6 + 0xc) = *(uint *)(pcVar6 + 0xc) | uVar16;
  uVar12 = SpRequestValidPowerState((ulonglong)uVar16,plVar14,(longlong)pcVar6);
  if ((int)uVar12 == 0x103) {
LAB_140005c62:
    IoStartNextPacket(param_1,0);
    return;
  }
  if (((((*(uint *)(pcVar6 + 0xc) & 0x80000) != 0) &&
       ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_q(WPP_GLOBAL_Control[3],0x14,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,param_2);
  }
  uVar19 = SUB81(pcVar6,0);
  if ((*(char *)((longlong)puVar5 + 0x48f) == '\0') && (*(char *)(puVar5 + 0xf3) == '\0')) {
    pcVar6[0x38] = '\0';
    pcVar6[0x39] = '\0';
    pcVar6[0x3a] = '\0';
    pcVar6[0x3b] = '\0';
    pcVar6[0x3c] = '\0';
    pcVar6[0x3d] = '\0';
    pcVar6[0x3e] = '\0';
    pcVar6[0x3f] = '\0';
LAB_140005cf8:
    cVar10 = -1;
  }
  else {
    in_stack_ffffffffffffff88 = local_res10;
    local_res8[0] = '\0';
    pcVar18 = pcVar6;
    uVar12 = SpAllocateSrbExtension
                       ((longlong)puVar5,(longlong)plVar14,(longlong)pcVar6,local_res8,
                        in_stack_ffffffffffffff88);
    if ((char)uVar12 == '\0') {
      if (local_res8[0] != '\x01') {
        return;
      }
      goto LAB_140005c62;
    }
    if (local_res10[0] != '\x01') goto LAB_140005cf8;
    if (pcVar6[2] == '\0') {
      bVar4 = pcVar6[9];
      if (2 < (byte)(bVar4 - 0x20)) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
           (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          in_stack_ffffffffffffff88 = pcVar6;
          WPP_SF_Dqq(WPP_GLOBAL_Control[3],(ulonglong)bVar4,pcVar18,(uint)bVar4,uVar19,uVar15);
        }
        pcVar6[9] = ' ';
      }
    }
    cVar10 = puVar8[0x88];
  }
  pcVar6[8] = cVar10;
  *(undefined4 *)(puVar8 + 0x78) = *(undefined4 *)(pcVar6 + 0x10);
  if (*(int *)(puVar8 + 0x54) == 0) {
    *(undefined4 *)(puVar8 + 0x54) = *(undefined4 *)(puVar5 + 0x35);
    *(int *)(puVar5 + 0x35) = *(int *)(puVar5 + 0x35) + 1;
  }
  cVar10 = pcVar6[2];
  if (cVar10 == '\x10') {
    plVar14[0x38] = (longlong)pcVar6;
  }
  else if ((byte)(cVar10 - 0x18U) < 2) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      pcVar18 = "lock";
      if (cVar10 != '\x18') {
        pcVar18 = "unlock";
      }
      in_stack_ffffffffffffff88 = param_2;
      WPP_SF_sq(WPP_GLOBAL_Control[3],0x16,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,pcVar18,
                uVar15);
    }
    KeAcquireSpinLockAtDpcLevel(puVar5 + 0x36);
    if (cVar10 == '\x18') {
      LOCK();
      *(int *)(plVar14 + 0x2e) = (int)plVar14[0x2e] + 1;
      UNLOCK();
      *(uint *)(plVar14 + 0x28) = *(uint *)(plVar14 + 0x28) | 0x40;
    }
    else if ((*(uint *)(plVar14 + 0x28) & 0x40) != 0) {
      LOCK();
      plVar1 = plVar14 + 0x2e;
      lVar13 = *plVar1;
      *(int *)plVar1 = (int)*plVar1 + -1;
      UNLOCK();
      if ((int)lVar13 == 1) {
        *(uint *)(plVar14 + 0x28) = *(uint *)(plVar14 + 0x28) & 0xffffffbf;
      }
    }
    KeReleaseSpinLockFromDpcLevel(puVar5 + 0x36);
    param_2[0x30] = '\0';
    param_2[0x31] = '\0';
    param_2[0x32] = '\0';
    param_2[0x33] = '\0';
    pcVar6[3] = '\x01';
  }
  if ((*(uint *)(pcVar6 + 0xc) & 0xc0) == 0) {
LAB_140006256:
    LOCK();
    piVar3 = (int *)((longlong)puVar5 + 0x164);
    *piVar3 = *piVar3 + 1;
    UNLOCK();
    if (((*piVar3 == 0) && (*(char *)((longlong)puVar5 + 0x48a) == '\0')) &&
       (lVar13 = puVar5[0x3a], lVar13 != 0)) {
      (**(code **)(*(longlong *)(lVar13 + 8) + 0x20))
                (lVar13,param_1,*(undefined4 *)((longlong)puVar5 + 0x3ec),ScsiPortAllocationRoutine,
                 plVar14);
      return;
    }
  }
  else {
    *(undefined8 *)(puVar8 + 0xa0) = *(undefined8 *)(pcVar6 + 0x18);
    *(ulonglong *)(puVar8 + 0x68) =
         (*(longlong *)(pcVar6 + 0x18) - (ulonglong)*(uint *)(*(longlong *)(param_2 + 8) + 0x2c)) -
         *(longlong *)(*(longlong *)(param_2 + 8) + 0x20);
    if (puVar5[0x3a] != 0) {
      KeFlushIoBuffers(*(undefined8 *)(param_2 + 8),
                       CONCAT31((uint3)(*(uint *)(pcVar6 + 0xc) >> 0xe),
                                (char)(*(uint *)(pcVar6 + 0xc) >> 6)) & 0xffffff01,1);
    }
    if (*(char *)((longlong)puVar5 + 0x48a) == '\0') {
      if ((((*(char *)(puVar5 + 0x91) == '\x01') || (pcVar6[2] == '\x02')) ||
          ((pcVar6[2] == '\0' && ((pcVar6[0x48] - 0x28U & 0xfd) != 0)))) &&
         (lVar13 = *(longlong *)(param_2 + 8), lVar13 != 0)) {
        if ((*(byte *)(lVar13 + 10) & 5) == 0) {
          lVar13 = MmMapLockedPagesSpecifyCache
                             (lVar13,0,1,0,(ulonglong)in_stack_ffffffffffffff88 & 0xffffffff00000000
                              ,(-(uint)(param_2[0x40] != '\0') & 0xfffffff0) + 0x20);
        }
        else {
          lVar13 = *(longlong *)(lVar13 + 0x18);
        }
        if (lVar13 == 0) {
          if (puVar5[0xef] != 0) {
            KeAcquireSpinLockAtDpcLevel(puVar5 + 0x36);
            lVar13 = SpMapLockedPagesWithReservedMapping
                               ((longlong)puVar5,pcVar6,(longlong)puVar8,*(longlong *)(param_2 + 8))
            ;
            if (lVar13 == -1) {
              if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                WPP_SF_qq(WPP_GLOBAL_Control[3],0x18,
                          &WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,puVar5,uVar19);
              }
              *(uint *)((longlong)puVar5 + 0x17c) = *(uint *)((longlong)puVar5 + 0x17c) | 0x800;
              puVar9 = *(undefined8 **)(pcVar6 + 0x38);
              if (puVar9 != (undefined8 *)0x0) {
                if (((pcVar6[2] != '\x17') && (*(char *)((longlong)puVar5 + 0x48c) != '\0')) &&
                   (*(longlong *)(pcVar6 + 0x20) != 0)) {
                  pcVar6[0xb] = puVar8[0xb0];
                  *(undefined8 *)(pcVar6 + 0x20) = *(undefined8 *)(puVar8 + 0x70);
                }
                if ((puVar5[0xec] == 0) || ((*(uint *)(puVar5[0xec] + 100) & 1) == 0)) {
                  *puVar9 = puVar5[0x46];
                  puVar5[0x46] = puVar9;
                }
                else {
                  SpInsertSrbExtension((longlong)puVar5,(ulonglong)puVar9);
                }
              }
              goto LAB_14000605a;
            }
            KeReleaseSpinLockFromDpcLevel(puVar5 + 0x36);
            if (lVar13 != 0) goto LAB_14000624b;
          }
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_q(WPP_GLOBAL_Control[3],0x19,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,
                     param_2);
          }
          pcVar6[3] = '0';
          pcVar6[4] = -1;
          *(undefined4 *)(puVar8 + 0x8c) = 0xc000009a;
          goto LAB_140006024;
        }
LAB_14000624b:
        *(longlong *)(pcVar6 + 0x18) = *(longlong *)(puVar8 + 0x68) + lVar13;
      }
      goto LAB_140006256;
    }
    uVar16 = (uint)((ulonglong)*(uint *)(pcVar6 + 0x10) + 0xfff +
                    (ulonglong)(*(uint *)(pcVar6 + 0x18) & 0xfff) >> 0xc);
    *(uint *)(puVar8 + 0x60) = uVar16;
    if (uVar16 < 0x12) {
      puVar2 = (uint *)((longlong)puVar5 + 0x79c);
      if (*puVar2 == 0) {
        (**(code **)(*(longlong *)(puVar5[0x3a] + 8) + 0x68))(puVar5[0x3a],0,0,0x11000,puVar2,0);
      }
      uVar16 = *puVar2;
      puVar17 = puVar8 + 0xc0;
      if (0x248 < uVar16) {
        puVar17 = (undefined *)0x0;
        uVar16 = 0;
      }
    }
    else {
      puVar17 = (undefined *)0x0;
      uVar16 = 0;
    }
    uVar12 = *(undefined8 *)(param_2 + 8);
    iVar11 = (**(code **)(*(longlong *)(puVar5[0x3a] + 8) + 0x70))
                       (puVar5[0x3a],*puVar5,uVar12,*(undefined8 *)(pcVar6 + 0x18),
                        *(undefined4 *)(pcVar6 + 0x10),SpReceiveScatterGather,puVar8,
                        CONCAT31((int3)((uint)in_stack_ffffffffffffffa0 >> 8),
                                 (char)(*(uint *)(pcVar6 + 0xc) >> 7)) & 0xffffff01,puVar17,uVar16);
    if (-1 < iVar11) {
      return;
    }
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qqdddD(WPP_GLOBAL_Control[3],(ulonglong)*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c),
                    uVar12,puVar5,uVar19,(char)*(undefined4 *)((longlong)puVar5 + 0x79c),
                    (char)uVar16,(char)*(undefined4 *)(puVar8 + 0x60),(char)iVar11);
    }
    pcVar6[3] = '0';
    pcVar6[4] = -1;
    *(int *)(puVar8 + 0x8c) = iVar11;
  }
LAB_140006024:
  KeAcquireSpinLockAtDpcLevel(puVar5 + 0x36);
  (*(code *)puVar5[0x34])(puVar5[0x32],SpStartIoSynchronized,param_1);
LAB_14000605a:
  KeReleaseSpinLockFromDpcLevel(puVar5 + 0x36);
  return;
}



===== ScsiPortTickHandler @ 1400062b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ScsiPortTickHandler(longlong param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong lVar7;
  code *pcVar8;
  char cVar9;
  int iVar10;
  undefined8 uVar11;
  longlong lVar12;
  undefined1 *puVar13;
  undefined1 uVar14;
  undefined4 uVar15;
  longlong *plVar16;
  longlong *plVar17;
  undefined1 uVar18;
  longlong *plVar19;
  longlong local_res20;
  
  plVar5 = *(longlong **)(param_1 + 0x40);
  KeAcquireSpinLockAtDpcLevel(plVar5 + 0x36);
  *(int *)((longlong)plVar5 + 0x6e4) = *(int *)((longlong)plVar5 + 0x6e4) + 1;
  if ((*(byte *)(plVar5 + 1) & 0xc) == 0xc) {
    do {
      if (*(uint *)(plVar5 + 0x97) <= *(uint *)((longlong)plVar5 + 0x4bc)) break;
      uVar11 = SpWmiPushFreeRequestItem(plVar5);
    } while (-1 < (int)uVar11);
  }
  if ((0 < (int)plVar5[0x31]) &&
     (iVar10 = (int)plVar5[0x31] + -1, *(int *)(plVar5 + 0x31) = iVar10, iVar10 == 0)) {
    cVar9 = (*(code *)plVar5[0x34])(plVar5[0x32],SpTimeoutSynchronized,param_1);
    if ((cVar9 == '\x01') && (lVar12 = IoAllocateErrorLogEntry(*plVar5,0x30), lVar12 != 0)) {
      *(undefined4 *)(lVar12 + 0xc) = 0xc0040075;
      *(undefined8 *)(lVar12 + 0x10) = 0x100;
      *(undefined2 *)(lVar12 + 2) = 0;
      IoWriteErrorLogEntry(lVar12);
    }
    KeReleaseSpinLockFromDpcLevel(plVar5 + 0x36);
    return;
  }
  plVar19 = plVar5 + 0x5c;
  local_res20 = 8;
LAB_1400063da:
LAB_1400063e1:
  do {
    KeAcquireSpinLockAtDpcLevel(plVar19);
    for (plVar17 = (longlong *)plVar19[1]; plVar17 != (longlong *)0x0;
        plVar17 = (longlong *)plVar17[0x35]) {
      uVar4 = *(uint *)(plVar17 + 0x28);
      if ((uVar4 & 8) == 0) {
        iVar10 = (int)plVar17[0x39];
        if (iVar10 == 0) {
          *(undefined4 *)(plVar17 + 0x39) = 0xffffffff;
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x2c) < '\0')) &&
             (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_q(WPP_GLOBAL_Control[3],0x1d,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,
                     *plVar17);
          }
          KeReleaseSpinLockFromDpcLevel(plVar19);
          cVar9 = (*(code *)plVar5[0x34])(plVar5[0x32],SpResetBusSynchronized);
          if (cVar9 == '\0') {
            if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x2c) < '\0')) &&
               (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              WPP_SF_(WPP_GLOBAL_Control[3],0x1e,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids);
            }
            goto LAB_1400063e1;
          }
          uVar15 = 0;
          bVar1 = *(byte *)((longlong)plVar17 + 0x156);
          uVar18 = 0;
          bVar2 = *(byte *)((longlong)plVar17 + 0x155);
          uVar14 = 0;
          bVar3 = *(byte *)((longlong)plVar17 + 0x154);
          if ((plVar17[0x3e] != 0) && (lVar12 = *(longlong *)(plVar17[0x3e] + 0x40), lVar12 != 0)) {
            lVar12 = *(longlong *)(lVar12 + 0x30);
            if (*(longlong *)(lVar12 + 0x38) != 0) {
              uVar18 = **(undefined1 **)(*(longlong *)(lVar12 + 0x38) + 0xb8);
            }
            uVar14 = *(undefined1 *)(lVar12 + 0x50);
            uVar15 = *(undefined4 *)(lVar12 + 0x54);
          }
          puVar13 = (undefined1 *)IoAllocateErrorLogEntry(*plVar5,0x40);
          if (puVar13 != (undefined1 *)0x0) {
            *(undefined4 *)(puVar13 + 0x14) = 0;
            *(undefined4 *)(puVar13 + 0xc) = 0xc0040009;
            *(undefined4 *)(puVar13 + 0x18) = uVar15;
            *puVar13 = uVar18;
            puVar13[1] = uVar14;
            *(undefined4 *)(puVar13 + 0x10) = 0x50000101;
            *(undefined2 *)(puVar13 + 2) = 0x10;
            *(uint *)(puVar13 + 0x28) = (uint)bVar3;
            *(uint *)(puVar13 + 0x2c) = (uint)bVar2;
            *(uint *)(puVar13 + 0x30) = (uint)bVar1;
            *(undefined4 *)(puVar13 + 0x34) = 7;
            IoWriteErrorLogEntry(puVar13);
          }
          goto LAB_1400063da;
        }
        if (iVar10 < 1) {
          if ((((uVar4 >> 8 & 1) != 0) && ((int)plVar5[0xf1] != -1)) &&
             (*(int *)((longlong)plVar17 + 0xfd4) = *(int *)((longlong)plVar17 + 0xfd4) + 1,
             *(uint *)(plVar5 + 0xf1) <= *(uint *)((longlong)plVar17 + 0xfd4))) {
            *(undefined1 *)(plVar17 + 0x3f) = 0xff;
            *(uint *)(plVar17 + 0x28) = uVar4 & 0xfffffeff;
          }
        }
        else {
          *(int *)(plVar17 + 0x39) = iVar10 + -1;
        }
      }
      else {
        lVar12 = plVar17[0x3d];
        if (((uVar4 & 4) == 0) &&
           (((uVar4 & 0x41) == 0 || ((*(uint *)(*(longlong *)(lVar12 + 0x40) + 0xc) & 0x80000) != 0)
            ))) {
          if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x20) != 0 &&
              (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
            WPP_SF_(WPP_GLOBAL_Control[3],0x1b,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids);
          }
          if ((*(uint *)(plVar17 + 0x28) & 0x20) != 0) {
            if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
               (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              WPP_SF_qq(WPP_GLOBAL_Control[3],0x1c,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,
                        plVar17[0x3c],(char)*(undefined8 *)(plVar17[0x3d] + 0x40));
            }
            lVar6 = plVar17[0x3c];
            *(uint *)(plVar17 + 0x28) = *(uint *)(plVar17 + 0x28) & 0xffffffdd;
            plVar17[0x3c] = 0;
            cVar9 = KeInsertByKeyDeviceQueue(*plVar17 + 0xa0,*(longlong *)(lVar6 + 0x38) + 0x78);
            if (cVar9 == '\0') {
              KeInsertByKeyDeviceQueue(*plVar17 + 0xa0,*(longlong *)(lVar6 + 0x38) + 0x78);
            }
          }
          *(uint *)(plVar17 + 0x28) = *(uint *)(plVar17 + 0x28) & 0xffffffe7;
          plVar17[0x3d] = 0;
          KeReleaseSpinLockFromDpcLevel(plVar19);
          KeReleaseSpinLockFromDpcLevel(plVar5 + 0x36);
          *(undefined4 *)(lVar12 + 0x90) = *(undefined4 *)((longlong)plVar5 + 0x6e4);
          IoStartPacket(param_1,*(undefined8 *)(lVar12 + 0x38),0,0);
          KeAcquireSpinLockAtDpcLevel(plVar5 + 0x36);
          goto LAB_1400063e1;
        }
      }
    }
    KeReleaseSpinLockFromDpcLevel(plVar19);
    plVar19 = plVar19 + 2;
    local_res20 = local_res20 + -1;
  } while (local_res20 != 0);
  KeReleaseSpinLockFromDpcLevel(plVar5 + 0x36);
  plVar19 = plVar5 + 0xc9;
  do {
    KeAcquireSpinLockAtDpcLevel(plVar5 + 200);
    plVar17 = (longlong *)*plVar19;
    if (plVar17 == plVar19) {
      if ((longlong *)plVar5[0xfe] != plVar5 + 0xfe) {
        SpTransferBlockedRequestsToAdapter((longlong)plVar5);
        plVar17 = (longlong *)*plVar19;
        goto LAB_1400067d5;
      }
      plVar17 = (longlong *)0x0;
    }
    else {
LAB_1400067d5:
      if (((longlong *)plVar17[1] != plVar19) ||
         (lVar12 = *plVar17, *(longlong **)(lVar12 + 8) != plVar17)) {
        pcVar8 = (code *)swi(0x29);
        (*pcVar8)(3);
        pcVar8 = (code *)swi(3);
        (*pcVar8)();
        return;
      }
      *plVar19 = lVar12;
      *(longlong **)(lVar12 + 8) = plVar19;
    }
    KeReleaseSpinLockFromDpcLevel(plVar5 + 200);
    if (plVar17 == (longlong *)0x0) {
      return;
    }
    plVar16 = plVar17 + -0xf;
    lVar12 = SpAllocateSrbData((longlong)plVar5,(longlong)plVar16,0);
    if (lVar12 == 0) {
      return;
    }
    lVar6 = plVar17[8];
    lVar7 = *(longlong *)(lVar6 + 8);
    *(undefined8 *)(lVar12 + 0x30) = *(undefined8 *)(*(longlong *)(lVar6 + 0x28) + 0x40);
    *(longlong **)(lVar12 + 0x38) = plVar16;
    *(longlong *)(lVar12 + 0x40) = lVar7;
    *(longlong *)(lVar7 + 0x30) = lVar12;
    lVar12 = *(longlong *)(*(longlong *)(lVar6 + 0x28) + 0x40);
    lVar6 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x40);
    if (((*(longlong *)(lVar12 + 0x38) != 0) &&
        (bVar1 = *(byte *)(*(longlong *)(plVar17[8] + 8) + 2), bVar1 < 0x18)) &&
       (((0xdd0185U >> (bVar1 & 0x1f) & 1) != 0 &&
        ((*(uint *)(*(longlong *)(plVar17[8] + 8) + 0xc) & 0x180000) == 0)))) {
      **(undefined4 **)(lVar12 + 0x38) = 0;
    }
    (**(code **)(*(longlong *)(lVar6 + 0x20) + 0x78))(*(undefined8 *)(lVar12 + 0x10),plVar16);
  } while( true );
}



===== SpAllocateSrbExtension @ 1400068c0 =====

ulonglong SpAllocateSrbExtension
                    (longlong param_1,longlong param_2,longlong param_3,undefined1 *param_4,
                    undefined1 *param_5)

{
  longlong lVar1;
  byte bVar2;
  uint uVar3;
  undefined4 uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  undefined8 *local_res8;
  
  lVar5 = *(longlong *)(param_3 + 0x30);
  lVar1 = param_1 + 0x1b0;
  KeAcquireSpinLockAtDpcLevel(lVar1);
  if (*(char *)(param_1 + 0x798) == '\x01') {
    if (*(char *)(param_3 + 2) != '\x10') {
      uVar3 = *(uint *)(param_3 + 0xc);
      uVar7 = 0x102;
      if (*(char *)(param_1 + 0x48d) != '\x01') {
        uVar7 = 2;
      }
      if (((uVar3 & uVar7) == 0) || ((uVar3 & 4) != 0)) {
        *param_5 = 0;
        if (((*(longlong **)(param_2 + 0x1d0) == (longlong *)(param_2 + 0x1d0)) &&
            ((*(uint *)(param_2 + 0x140) & 4) == 0)) ||
           (((uVar3 & 0x80010) != 0 &&
            (((uVar3 & 0x80010) >> 0x13 == 0 || ((*(uint *)(param_2 + 0x140) & 0xc0) != 0))))))
        goto LAB_140006a0e;
      }
      else {
        *param_5 = 1;
        if ((*(uint *)(param_2 + 0x140) & 4) == 0) goto LAB_140006a26;
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_(WPP_GLOBAL_Control[3],0x46,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids);
        }
      }
      *(uint *)(param_2 + 0x140) = *(uint *)(param_2 + 0x140) | 0x20;
      lVar5 = *(longlong *)(param_3 + 0x30);
      *(longlong *)(param_2 + 0x1e0) = lVar5;
      uVar4 = *(undefined4 *)(param_1 + 0x6e4);
      *param_4 = 1;
      *(undefined4 *)(lVar5 + 0x90) = uVar4;
      *(uint *)(param_2 + 0x140) = *(uint *)(param_2 + 0x140) | 2;
    }
LAB_14000691d:
    uVar8 = KeReleaseSpinLockFromDpcLevel(lVar1);
    uVar8 = uVar8 & 0xffffffffffffff00;
  }
  else {
    *param_5 = 0;
LAB_140006a0e:
    *(undefined1 *)(param_3 + 8) = 0xff;
    *(undefined4 *)(lVar5 + 0x90) = *(undefined4 *)(param_1 + 0x6e4);
    *(longlong *)(param_2 + 0x1f0) = lVar5;
LAB_140006a26:
    if (*(char *)(param_1 + 0x48f) == '\0') {
      *(undefined8 *)(param_3 + 0x38) = 0;
      puVar10 = (undefined8 *)KeReleaseSpinLockFromDpcLevel(lVar1);
    }
    else {
      local_res8 = *(undefined8 **)(param_1 + 0x230);
      if (local_res8 == (undefined8 *)0x0) {
        *(uint *)(param_1 + 0x17c) = *(uint *)(param_1 + 0x17c) | 0x800;
        local_res8 = (undefined8 *)0x0;
        goto LAB_14000691d;
      }
      *(undefined8 *)(param_1 + 0x230) = *local_res8;
      if ((*(longlong *)(param_1 + 0x760) == 0) ||
         ((*(uint *)(*(longlong *)(param_1 + 0x760) + 100) & 1) == 0)) {
        puVar9 = (undefined8 *)0x0;
      }
      else {
        puVar9 = (undefined8 *)SpPrepareSrbExtensionForUse(param_1,(longlong *)&local_res8);
      }
      puVar6 = local_res8;
      KeReleaseSpinLockFromDpcLevel(lVar1);
      puVar10 = puVar6;
      if (puVar9 != (undefined8 *)0x0) {
        puVar10 = puVar9;
      }
      *(undefined8 **)(param_3 + 0x38) = puVar10;
      if ((*(char *)(param_3 + 2) != '\x17') && (*(char *)(param_1 + 0x48c) != '\0')) {
        puVar10 = (undefined8 *)0x0;
        if (*(longlong *)(param_3 + 0x20) != 0) {
          *(longlong *)(lVar5 + 0x70) = *(longlong *)(param_3 + 0x20);
          *(undefined1 *)(lVar5 + 0xb0) = *(undefined1 *)(param_3 + 0xb);
          bVar2 = *(byte *)(param_1 + 0x748);
          if ((ulonglong)bVar2 + 0x12 < (ulonglong)*(byte *)(param_3 + 0xb)) {
            puVar10 = &WPP_GLOBAL_Control;
            if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                (puVar10 = (undefined8 *)(ulonglong)*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c),
                (*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              puVar10 = (undefined8 *)
                        WPP_SF_DD(WPP_GLOBAL_Control[3],0x47,
                                  &WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,
                                  (uint)*(byte *)(param_3 + 0xb),bVar2 + 0x12);
            }
            *(uint *)(param_3 + 0xc) = *(uint *)(param_3 + 0xc) | 0x20;
          }
          else {
            *(byte *)(param_3 + 0xb) = bVar2 + 0x12;
            if ((*(longlong *)(param_1 + 0x760) == 0) ||
               ((*(uint *)(*(longlong *)(param_1 + 0x760) + 100) & 1) == 0)) {
              puVar10 = (undefined8 *)((ulonglong)*(uint *)(param_1 + 0x214) + (longlong)puVar6);
            }
            else {
              puVar10 = (undefined8 *)SpPrepareSenseBufferForUse(param_1,(longlong)puVar6);
            }
            *(undefined8 **)(param_3 + 0x20) = puVar10;
          }
        }
      }
    }
    uVar8 = CONCAT71((int7)((ulonglong)puVar10 >> 8),1);
  }
  return uVar8;
}



===== SpCompletionDpcProcessWmi @ 140006b9c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SpCompletionDpcProcessWmi(longlong param_1,longlong param_2,undefined *param_3)

{
  int *piVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 uVar5;
  int iVar6;
  longlong *plVar7;
  longlong lVar8;
  undefined8 uVar9;
  undefined2 uVar10;
  longlong lVar11;
  
  uVar9 = _DAT_fffff78000000014;
  plVar2 = *(longlong **)(param_1 + 0x40);
  lVar3 = *(longlong *)(param_2 + 0x68);
joined_r0x000140006bd5:
  do {
    while( true ) {
      lVar4 = lVar3;
      if (lVar4 == 0) {
        *(undefined8 *)(param_2 + 0x68) = 0;
        do {
          if (*(uint *)(plVar2 + 0x97) <= *(uint *)((longlong)plVar2 + 0x4bc)) {
            return;
          }
          uVar9 = SpWmiPushFreeRequestItem(plVar2);
        } while (-1 < (int)uVar9);
        return;
      }
      lVar3 = *(longlong *)(lVar4 + 0x88);
      if (*(char *)(lVar4 + 0x81) == -1) break;
      param_3 = (undefined *)CONCAT71((int7)((ulonglong)param_3 >> 8),*(undefined1 *)(lVar4 + 0x82))
      ;
      plVar7 = GetLogicalUnitExtension
                         ((longlong)plVar2,*(char *)(lVar4 + 0x81),(uint)param_3,
                          *(byte *)(lVar4 + 0x83),0,'\x01');
      if (plVar7 != (longlong *)0x0) {
        lVar11 = *plVar7;
        goto LAB_140006c26;
      }
      ExFreePoolWithTag(lVar4,0);
    }
    lVar11 = param_1;
LAB_140006c26:
  } while ((lVar11 == 0) || ((*(byte *)(*(longlong *)(lVar11 + 0x40) + 8) & 4) == 0));
  if (*(char *)(lVar4 + 0x80) == '\t') {
    lVar8 = IoAllocateWorkItem(lVar11);
    if (lVar8 == 0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        uVar10 = 0x50;
LAB_140006cef:
        param_3 = &WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids;
        WPP_SF_(WPP_GLOBAL_Control[3],uVar10,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids);
      }
    }
    else {
      LOCK();
      piVar1 = (int *)(*(longlong *)(lVar11 + 0x40) + 0x4c);
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      param_3 = (undefined *)0x0;
      IoQueueWorkItem(lVar8,SpDelayedWmiRegistrationControl,1,lVar8);
    }
  }
  else if (*(char *)(lVar4 + 0x80) == '\b') {
    uVar5 = IoWMIDeviceObjectToProviderId(lVar11);
    *(undefined8 *)(lVar4 + 0x10) = uVar9;
    *(undefined4 *)(lVar4 + 4) = uVar5;
    iVar6 = IoWMIWriteEvent(lVar4);
    if (-1 < iVar6) goto joined_r0x000140006bd5;
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      uVar10 = 0x51;
      goto LAB_140006cef;
    }
  }
  if ((char)plVar2[0x98] != '\0') {
    *(undefined8 *)(lVar4 + 0x88) = 0;
    ExpInterlockedPushEntrySList(plVar2 + 0x94,lVar4);
    LOCK();
    *(int *)((longlong)plVar2 + 0x4bc) = *(int *)((longlong)plVar2 + 0x4bc) + 1;
    UNLOCK();
  }
  goto joined_r0x000140006bd5;
}



===== SpDecrementActiveRequestCount @ 140006d90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SpDecrementActiveRequestCount(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x164);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (((iVar2 + -1 < 0) && (*(char *)(*(longlong *)(param_1 + 0x1f8) + 0x52) == '\0')) &&
     (lVar3 = *(longlong *)(param_1 + 0x1d0), lVar3 != 0)) {
    *(undefined8 *)(param_1 + 0x1c8) = 0;
    (**(code **)(*(longlong *)(lVar3 + 8) + 0x30))(lVar3);
  }
  return;
}



===== SpDelayedWmiRegistrationControl @ 140006df0 =====

void SpDelayedWmiRegistrationControl(longlong param_1,undefined8 param_2)

{
  char cVar1;
  
  if ((*(byte *)(*(longlong *)(param_1 + 0x40) + 8) & 1) != 0) {
    cVar1 = SpIsInitiatorLU(*(longlong *)(param_1 + 0x40));
    if (cVar1 != '\0') goto LAB_140006e27;
  }
  IoWMIRegistrationControl(param_1,3);
LAB_140006e27:
  IoFreeWorkItem(param_2);
  SpReleaseRemoveLock(param_1,(char)param_2);
  return;
}



===== SpEnableInterruptSynchronized @ 140006e60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong SpEnableInterruptSynchronized(longlong *param_1)

{
  uint uVar1;
  longlong lVar2;
  ulonglong in_RAX;
  ulonglong uVar3;
  
  *(uint *)(param_1 + 0x6d) = *(uint *)(param_1 + 0x6d) & 0xffffbfff;
  if ((*(uint *)(param_1 + 0x6d) & 0x80000) == 0) {
    (*(code *)param_1[0x55])(param_1[0x29]);
    uVar3 = (ulonglong)*(uint *)(param_1 + 0x6d);
    if ((*(uint *)(param_1 + 0x6d) & 4) != 0) {
      lVar2 = *param_1;
      uVar3 = *(ulonglong *)(lVar2 + 0x40);
      LOCK();
      uVar1 = *(uint *)(uVar3 + 0x180);
      *(uint *)(uVar3 + 0x180) = 0x20004;
      UNLOCK();
      if ((uVar1 >> 0x11 & 1) == 0) {
        uVar3 = KeInsertQueueDpc(lVar2 + 200,0,0);
      }
    }
    uVar3 = CONCAT71((int7)(uVar3 >> 8),1);
  }
  else {
    uVar3 = in_RAX & 0xffffffffffffff00;
  }
  return uVar3;
}



===== SpFindSafeLogicalUnit @ 140006ee0 =====

longlong * SpFindSafeLogicalUnit(longlong param_1,byte param_2,undefined1 param_3)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uVar4;
  longlong *plVar5;
  byte bVar6;
  uint uVar7;
  undefined8 *puVar8;
  longlong lVar9;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  if (*(char *)(lVar2 + 0x7e8) == '\x01') {
    if (param_2 == 0xff) {
      uVar7 = 0;
      puVar8 = (undefined8 *)(lVar2 + 0x7a8);
      do {
        plVar5 = (longlong *)*puVar8;
        if (plVar5 != (longlong *)0x0) {
          lVar9 = *(longlong *)(*plVar5 + 0x40);
          LOCK();
          piVar1 = (int *)(lVar9 + 0x4c);
          *piVar1 = *piVar1 + 1;
          UNLOCK();
          if (*(int *)(lVar9 + 0xc) == 0) break;
          SpReleaseRemoveLock(*plVar5,param_3);
          plVar5 = (longlong *)0x0;
        }
        uVar7 = uVar7 + 1;
        puVar8 = puVar8 + 1;
      } while (uVar7 < 8);
    }
    else {
      plVar5 = *(longlong **)(lVar2 + 0x7a8 + (ulonglong)param_2 * 8);
      if (plVar5 == (longlong *)0x0) goto LAB_140006fcb;
      lVar9 = *(longlong *)(*plVar5 + 0x40);
      LOCK();
      piVar1 = (int *)(lVar9 + 0x4c);
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      if (*(int *)(lVar9 + 0xc) != 0) {
        SpReleaseRemoveLock(*plVar5,param_3);
        plVar5 = (longlong *)0x0;
      }
    }
    if (plVar5 != (longlong *)0x0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_q(WPP_GLOBAL_Control[3],0x4a,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,plVar5)
        ;
      }
      return plVar5;
    }
  }
LAB_140006fcb:
  bVar6 = 0;
  do {
    lVar9 = ((ulonglong)bVar6 + 0x2e) * 0x10 + lVar2;
    uVar4 = KeAcquireSpinLockRaiseToDpc(lVar9);
    for (plVar5 = *(longlong **)(lVar9 + 8); plVar5 != (longlong *)0x0;
        plVar5 = (longlong *)plVar5[0x35]) {
      if ((*(char *)((longlong)plVar5 + 0x14e) == '\0') &&
         ((param_2 == 0xff || (*(byte *)((longlong)plVar5 + 0x154) == param_2)))) {
        lVar3 = *(longlong *)(*plVar5 + 0x40);
        LOCK();
        *(int *)(lVar3 + 0x4c) = *(int *)(lVar3 + 0x4c) + 1;
        UNLOCK();
        if (*(int *)(lVar3 + 0xc) == 0) {
          KeReleaseSpinLock(lVar9,CONCAT71((int7)((ulonglong)lVar3 >> 8),uVar4));
          return plVar5;
        }
        SpReleaseRemoveLock(*plVar5,param_3);
      }
    }
    KeReleaseSpinLock(lVar9,uVar4);
    bVar6 = bVar6 + 1;
  } while (bVar6 < 8);
  return (longlong *)0x0;
}



===== SpFireSenseDataEvent @ 140007094 =====

undefined8 SpFireSenseDataEvent(longlong param_1,longlong param_2)

{
  longlong lVar1;
  void *_Dst;
  undefined8 uVar2;
  uint uVar3;
  ulonglong uVar4;
  short *psVar5;
  uint uVar6;
  size_t sVar7;
  undefined8 local_28;
  longlong lStack_20;
  
  uVar2 = *(undefined8 *)(param_2 + 8);
  _Dst = (void *)ExAllocatePoolWithTag(4,0x138,0x69506353);
  if (_Dst == (void *)0x0) {
    SpLogAllocationFailureFn(uVar2,4,0x138,0x69506353,0x696e7472,0x2445);
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_(WPP_GLOBAL_Control[3],0x52,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids);
    }
    uVar2 = 0xc000009a;
  }
  else {
    lVar1 = *(longlong *)(param_2 + 0x40);
    memset(_Dst,0,0x138);
    if (*(longlong *)(lVar1 + 0x6b8) != 0) {
      local_28 = 0;
      lStack_20 = 0;
      uVar6 = 0;
      RtlInitUnicodeString(&local_28);
      if (3 < (ushort)local_28) {
        uVar3 = (uint)((ushort)((ushort)local_28 - 2) >> 1);
        uVar4 = (ulonglong)uVar3;
        local_28 = CONCAT62(local_28._2_6_,(ushort)local_28 - 2);
        if (uVar3 != 0) {
          psVar5 = (short *)(lStack_20 + uVar4 * 2);
          do {
            uVar6 = uVar6 + 2;
            if (*psVar5 == 0x5c) {
              sVar7 = 0x1e;
              if (uVar6 < 0x1f) {
                sVar7 = (size_t)uVar6;
              }
              memcpy(_Dst,(void *)(lStack_20 + (ulonglong)((int)uVar4 + 1) * 2),sVar7);
              break;
            }
            psVar5 = psVar5 + -1;
            uVar3 = (int)uVar4 - 1;
            uVar4 = (ulonglong)uVar3;
          } while (uVar3 != 0);
        }
      }
    }
    sVar7 = 0x10;
    *(undefined4 *)((longlong)_Dst + 0x20) = *(undefined4 *)(lVar1 + 0x15c);
    *(undefined1 *)((longlong)_Dst + 0x24) = *(undefined1 *)(param_1 + 2);
    *(undefined1 *)((longlong)_Dst + 0x25) = *(undefined1 *)(param_1 + 3);
    *(undefined1 *)((longlong)_Dst + 0x26) = *(undefined1 *)(param_1 + 5);
    *(undefined1 *)((longlong)_Dst + 0x27) = *(undefined1 *)(param_1 + 6);
    *(undefined1 *)((longlong)_Dst + 0x28) = *(undefined1 *)(param_1 + 7);
    if (*(byte *)(param_1 + 10) < 0x10) {
      sVar7 = (size_t)*(byte *)(param_1 + 10);
    }
    memcpy((void *)((longlong)_Dst + 0x29),(void *)(param_1 + 0x48),sVar7);
    memcpy((void *)((longlong)_Dst + 0x39),*(void **)(param_1 + 0x20),
           (ulonglong)*(byte *)(param_1 + 0xb));
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
       (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_q(WPP_GLOBAL_Control[3],0x53,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,param_2);
    }
    uVar2 = WmiFireEvent(param_2,lVar1 + 0x74c,0,0x138,_Dst);
  }
  return uVar2;
}



===== SpFlushReleaseQueue @ 1400072b0 =====

uint SpFlushReleaseQueue(longlong *param_1,undefined8 param_2,undefined *param_3)

{
  longlong *plVar1;
  undefined *puVar2;
  char cVar3;
  char cVar4;
  undefined1 uVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  
  plVar1 = (longlong *)param_1[0x2d];
  cVar4 = (char)param_3;
  cVar3 = (char)param_2;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    param_3 = &WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids;
    param_2 = 0;
    WPP_SF_D(WPP_GLOBAL_Control[3],0x4b,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,
             (uint)*(byte *)((longlong)param_1 + 0x155));
  }
  uVar5 = KeAcquireSpinLockRaiseToDpc(plVar1 + 0x36);
  if (cVar4 == '\0') {
    if ((*(uint *)(param_1 + 0x28) & 1) == 0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_(WPP_GLOBAL_Control[3],0x4c,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids);
      }
      KeReleaseSpinLock(plVar1 + 0x36,uVar5);
      return -(uint)(cVar3 != '\0') & 0xc0000010;
    }
    *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xfffffffe;
  }
  if (cVar3 == '\0') {
    if (param_1[0x3e] == 0) {
      GetNextLuRequest(param_1,CONCAT71((int7)((ulonglong)param_2 >> 8),1),param_3);
      KeLowerIrql(uVar5);
      return 0;
    }
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_(WPP_GLOBAL_Control[3],0x4f,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids);
    }
    KeReleaseSpinLock(plVar1 + 0x36,uVar5);
    return 0;
  }
  lVar8 = 0;
  while (lVar6 = KeRemoveByKeyDeviceQueueIfBusy(*param_1 + 0xa0,0), lVar6 != 0) {
    *(undefined1 *)(*(longlong *)(*(longlong *)(lVar6 + 0x40) + 8) + 3) = 0x16;
    *(longlong *)(lVar6 + 0x30) = lVar8;
    *(undefined4 *)(lVar6 + -0x48) = 0xc0000001;
    lVar8 = lVar6 + -0x78;
  }
  lVar6 = param_1[0x3c];
  if (lVar6 != 0) {
    lVar7 = *(longlong *)(lVar6 + 0x38);
    lVar6 = *(longlong *)(lVar6 + 0x40);
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qq(WPP_GLOBAL_Control[3],0x4d,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,lVar7,
                (char)lVar6);
    }
    *(undefined1 *)(lVar6 + 3) = 0x16;
    *(longlong *)(lVar7 + 0xa8) = lVar8;
    *(undefined4 *)(lVar7 + 0x30) = 0xc0000001;
    param_1[0x3c] = 0;
    *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xffffffdf;
    lVar8 = lVar7;
  }
  lVar6 = param_1[0x3d];
  if (lVar6 == 0) {
    if (cVar4 != '\0') goto LAB_1400074f5;
  }
  else if (cVar4 != '\0') {
    lVar7 = *(longlong *)(lVar6 + 0x38);
    lVar6 = *(longlong *)(lVar6 + 0x40);
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qq(WPP_GLOBAL_Control[3],0x4e,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,lVar7,
                (char)lVar6);
    }
    *(undefined1 *)(lVar6 + 3) = 0x16;
    *(longlong *)(lVar7 + 0xa8) = lVar8;
    *(undefined4 *)(lVar7 + 0x30) = 0xc0000001;
    param_1[0x3d] = 0;
    *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xffffffe7;
    lVar8 = lVar7;
    goto LAB_1400074f5;
  }
  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xfffffffe;
LAB_1400074f5:
  KeReleaseSpinLock(plVar1 + 0x36,uVar5);
  while (lVar8 != 0) {
    lVar6 = *(longlong *)(lVar8 + 0xa8);
    lVar7 = *(longlong *)(*(longlong *)(lVar8 + 0xb8) + 8);
    puVar2 = *(undefined **)(lVar7 + 0x30);
    *(longlong *)(lVar7 + 0x30) = lVar8;
    lVar7 = *plVar1;
    SpReleaseRemoveLock(lVar7,(char)lVar8);
    SpCompleteRequest(lVar7,lVar8,puVar2,0);
    lVar8 = lVar6;
  }
  return 0;
}



===== SpGetInterruptState @ 1400075e0 =====

ulonglong SpGetInterruptState(longlong *param_1)

{
  byte bVar1;
  uint uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong *plVar7;
  code *pcVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined8 uVar12;
  longlong *plVar13;
  ulonglong uVar14;
  longlong lVar15;
  
  lVar15 = *param_1;
  if ((*(uint *)(lVar15 + 0x368) & 4) == 0) {
    *(uint *)(lVar15 + 0x180) = *(uint *)(lVar15 + 0x180) & 0x20000;
    uVar14 = (ulonglong)(*(uint *)(lVar15 + 0x368) & 0xffffff00);
  }
  else {
    puVar3 = (undefined8 *)param_1[1];
    uVar12 = *(undefined8 *)(lVar15 + 0x370);
    *puVar3 = *(undefined8 *)(lVar15 + 0x368);
    puVar3[1] = uVar12;
    uVar12 = *(undefined8 *)(lVar15 + 0x380);
    puVar3[2] = *(undefined8 *)(lVar15 + 0x378);
    puVar3[3] = uVar12;
    uVar12 = *(undefined8 *)(lVar15 + 0x390);
    puVar3[4] = *(undefined8 *)(lVar15 + 0x388);
    puVar3[5] = uVar12;
    uVar12 = *(undefined8 *)(lVar15 + 0x3a0);
    puVar3[6] = *(undefined8 *)(lVar15 + 0x398);
    puVar3[7] = uVar12;
    uVar12 = *(undefined8 *)(lVar15 + 0x3b0);
    puVar3[8] = *(undefined8 *)(lVar15 + 0x3a8);
    puVar3[9] = uVar12;
    uVar12 = *(undefined8 *)(lVar15 + 0x3c0);
    puVar3[10] = *(undefined8 *)(lVar15 + 0x3b8);
    puVar3[0xb] = uVar12;
    uVar9 = *(undefined4 *)(lVar15 + 0x3cc);
    uVar10 = *(undefined4 *)(lVar15 + 0x3d0);
    uVar11 = *(undefined4 *)(lVar15 + 0x3d4);
    *(undefined4 *)(puVar3 + 0xc) = *(undefined4 *)(lVar15 + 0x3c8);
    *(undefined4 *)((longlong)puVar3 + 100) = uVar9;
    *(undefined4 *)(puVar3 + 0xd) = uVar10;
    *(undefined4 *)((longlong)puVar3 + 0x6c) = uVar11;
    puVar3[0xe] = *(undefined8 *)(lVar15 + 0x3d8);
    *(uint *)(lVar15 + 0x368) = *(uint *)(lVar15 + 0x368) & 0x84180;
    *(undefined8 *)(lVar15 + 0x370) = 0;
    *(undefined8 *)(lVar15 + 0x3b0) = 0;
    *(undefined8 *)(lVar15 + 0x3b8) = 0;
    *(undefined8 *)(lVar15 + 0x3d0) = 0;
    LOCK();
    *(undefined4 *)(lVar15 + 0x180) = 0x20000;
    UNLOCK();
    plVar13 = (longlong *)param_1[1];
    for (lVar15 = plVar13[1]; lVar15 != 0; lVar15 = *(longlong *)(lVar15 + 0x48)) {
      lVar4 = *(longlong *)(lVar15 + 0x40);
      lVar5 = *(longlong *)(lVar15 + 0x30);
      if (*(char *)(lVar4 + 3) != '\x01') {
        if ((((*(char *)(lVar4 + 4) == '\x02') && (-1 < *(char *)(lVar4 + 3))) &&
            (*(longlong *)(lVar4 + 0x20) != 0)) && (*(char *)(lVar4 + 0xb) != '\0')) {
          if ((*(uint *)(lVar5 + 0x140) & 4) == 0) {
            *(uint *)(lVar5 + 0x140) = *(uint *)(lVar5 + 0x140) | 4;
            if (*(longlong *)(lVar5 + 0xee0) == 0) {
              *(longlong *)(lVar5 + 0xee0) = lVar15;
            }
            else {
              *(longlong *)(lVar5 + 0xee8) = lVar15;
            }
          }
          else {
            *(undefined2 *)(lVar4 + 3) = 0x10;
          }
        }
        if (*(char *)(lVar4 + 4) == '(') {
          uVar2 = *(uint *)(lVar5 + 0x140);
          bVar1 = *(byte *)(lVar5 + 0x1f9);
          *(uint *)(lVar5 + 0x140) = uVar2 | 0x10;
          if ((bVar1 <= *(byte *)(lVar5 + 0x1f8)) && (2 < bVar1)) {
            *(uint *)(lVar5 + 0x140) = uVar2 | 0x110;
            *(byte *)(lVar5 + 0x1f8) = bVar1 - 1;
            if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x20) != 0 &&
                (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
              WPP_SF_D(WPP_GLOBAL_Control[3],0x2b,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,
                       (uint)(byte)(bVar1 - 1));
            }
          }
          *(undefined4 *)(lVar5 + 0xfd4) = 0;
        }
      }
      if (*(char *)(lVar4 + 8) == -1) {
LAB_1400077b8:
        plVar13 = (longlong *)(lVar5 + 0x1d0);
        if ((longlong *)*plVar13 == plVar13) {
          *(undefined4 *)(lVar5 + 0x1c8) = 0xffffffff;
        }
        else {
          plVar13 = (longlong *)((longlong *)*plVar13)[4];
          *(undefined4 *)(lVar5 + 0x1c8) = *(undefined4 *)((longlong)plVar13 + 0x14);
        }
      }
      else {
        plVar6 = *(longlong **)(lVar5 + 0x1d0);
        plVar13 = (longlong *)(lVar15 + 0x20);
        lVar4 = *plVar13;
        if ((*(longlong **)(lVar4 + 8) != plVar13) ||
           (plVar7 = *(longlong **)(lVar15 + 0x28), (longlong *)*plVar7 != plVar13)) {
          pcVar8 = (code *)swi(0x29);
          (*pcVar8)(3);
          pcVar8 = (code *)swi(3);
          uVar14 = (*pcVar8)();
          return uVar14;
        }
        *plVar7 = lVar4;
        *(longlong **)(lVar4 + 8) = plVar7;
        if (plVar6 == plVar13) goto LAB_1400077b8;
      }
    }
    uVar14 = CONCAT71((int7)((ulonglong)plVar13 >> 8),1);
  }
  return uVar14;
}



===== SpGetPassThroughSrbFlags @ 14000780c =====

uint SpGetPassThroughSrbFlags(longlong param_1)

{
  return *(uint *)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x168) + 0x18) & 8 |
         *(uint *)(*(longlong *)(param_1 + 0x40) + 0x18) | 0x100;
}



===== SpGetPdo @ 14000782c =====

undefined8
SpGetPdo(longlong param_1,char param_2,uint param_3,byte param_4,longlong param_5,longlong *param_6)

{
  longlong *plVar1;
  undefined8 uVar2;
  
  plVar1 = GetLogicalUnitExtension
                     (*(longlong *)(param_1 + 0x40),param_2,param_3,param_4,param_5,'\x01');
  if (plVar1 == (longlong *)0x0) {
    uVar2 = 0xc000000e;
  }
  else if (*(int *)((longlong)plVar1 + 0xc) == 0) {
    *param_6 = *plVar1;
    uVar2 = 0;
  }
  else {
    SpReleaseRemoveLock(*plVar1,(char)param_5);
    uVar2 = 0xc00000c0;
  }
  return uVar2;
}



===== SpHandleIoctlStorageQueryProperty @ 140007888 =====

undefined4 SpHandleIoctlStorageQueryProperty(longlong param_1,longlong param_2)

{
  undefined4 uVar1;
  
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0xc) {
    uVar1 = 0xc000000d;
  }
  else {
    uVar1 = ScsiPortQueryProperty(param_1,param_2);
  }
  *(undefined4 *)(param_2 + 0x30) = uVar1;
  SpReleaseRemoveLock(param_1,(char)param_2);
  IofCompleteRequest(param_2,0);
  return uVar1;
}



===== SpIsPdoClaimed @ 1400078f0 =====

undefined8 SpIsPdoClaimed(longlong param_1)

{
  return CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x40) >> 8),
                  *(undefined1 *)(*(longlong *)(param_1 + 0x40) + 0x148));
}



===== SpMapLockedPagesWithReservedMapping @ 140007904 =====

longlong SpMapLockedPagesWithReservedMapping
                   (longlong param_1,undefined8 param_2,longlong param_3,longlong param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  
  if ((*(uint *)(param_1 + 0x17c) & 0x200000) == 0) {
    uVar2 = (ulonglong)*(uint *)(param_4 + 0x28) + 0xfff +
            (ulonglong)(*(int *)(param_4 + 0x2c) + *(int *)(param_4 + 0x20) & 0xfff) >> 0xc;
    if (uVar2 < 5) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_qqq(WPP_GLOBAL_Control[3],uVar2,param_2,param_1,(char)param_2,(char)uVar2);
      }
      lVar1 = MmMapLockedPagesWithReservedMapping
                        (*(undefined8 *)(param_1 + 0x778),0x6d506353,param_4,1);
      if (lVar1 != 0) {
        *(uint *)(param_1 + 0x17c) = *(uint *)(param_1 + 0x17c) | 0x200000;
        *(uint *)(param_3 + 0x7c) = *(uint *)(param_3 + 0x7c) | 0x20000000;
      }
    }
    else {
      lVar1 = 0;
    }
  }
  else {
    lVar1 = -1;
  }
  return lVar1;
}



===== SpMiniPortTimerDpc @ 1400079e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SpMiniPortTimerDpc(undefined8 param_1,longlong param_2)

{
  uint *puVar1;
  uint uVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(param_2 + 0x40);
  KeAcquireSpinLockAtDpcLevel(lVar3 + 0x1b0);
  if (((*(uint *)(lVar3 + 0x368) & 0x80000) == 0) && (*(longlong *)(lVar3 + 0x2b0) != 0)) {
    (**(code **)(lVar3 + 0x1a0))
              (*(undefined8 *)(lVar3 + 400),*(longlong *)(lVar3 + 0x2b0),
               *(undefined8 *)(lVar3 + 0x148));
  }
  KeReleaseSpinLockFromDpcLevel(lVar3 + 0x1b0);
  if ((*(uint *)(lVar3 + 0x368) & 4) != 0) {
    LOCK();
    puVar1 = (uint *)(*(longlong *)(param_2 + 0x40) + 0x180);
    uVar2 = *puVar1;
    *puVar1 = 0x20004;
    UNLOCK();
    if ((uVar2 >> 0x11 & 1) == 0) {
      KeInsertQueueDpc(param_2 + 200,0,0);
    }
  }
  return;
}



===== SpProcessCompletedRequest @ 140007a9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SpProcessCompletedRequest(longlong *param_1,undefined *param_2,char *param_3)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined1 *puVar5;
  byte bVar6;
  char cVar7;
  uint uVar8;
  longlong lVar9;
  undefined8 uVar10;
  longlong lVar11;
  undefined *puVar12;
  longlong lVar13;
  longlong *plVar14;
  longlong *plVar15;
  char *_Size;
  uint uVar16;
  undefined4 uVar17;
  ulonglong uVar18;
  undefined4 local_res8;
  undefined1 uVar19;
  ulonglong in_stack_ffffffffffffff98;
  
  uVar17 = *(undefined4 *)(param_2 + 0x8c);
  lVar2 = *(longlong *)(param_2 + 0x40);
  lVar3 = *(longlong *)(param_2 + 0x38);
  plVar4 = *(longlong **)(param_2 + 0x30);
  lVar13 = *param_1;
  uVar19 = (undefined1)lVar2;
  _Size = param_3;
  if ((*(uint *)(lVar2 + 0xc) & 0xc0) != 0) {
    puVar5 = *(undefined1 **)(lVar2 + 0x18);
    *(undefined8 *)(lVar2 + 0x18) = *(undefined8 *)(param_2 + 0xa0);
    if ((((char)param_1[0x91] != '\0') || (*(longlong *)(param_2 + 0x98) != 0)) ||
       (*(char *)(lVar2 + 0x48) == '%')) {
      if ((*(longlong *)(lVar3 + 8) != 0) && ((*(uint *)(lVar2 + 0xc) & 0x40) != 0)) {
        _Size = (char *)0x0;
        KeFlushIoBuffers();
      }
      if (((*(char *)(lVar2 + 0x48) == '%') && (*(char *)(lVar2 + 3) == '\x01')) &&
         (*(int *)(lVar2 + 0x10) == 8)) {
        local_res8 = CONCAT13(*puVar5,CONCAT12(puVar5[1],CONCAT11(puVar5[2],puVar5[3])));
        uVar16 = local_res8 + 1;
        if (uVar16 != *(uint *)(plVar4 + 0x1fb)) {
          uVar8 = *(uint *)((longlong)plVar4 + 0xfdc);
          _Size = (char *)(ulonglong)uVar8;
          if (uVar8 <= uVar16) {
            *(uint *)(plVar4 + 0x1fb) = uVar16;
            *(undefined4 *)((longlong)plVar4 + 0xfe4) = 0;
            *(int *)(plVar4 + 0x200) = local_res8;
            uVar8 = (uVar8 + local_res8 & -uVar8) / uVar8;
            *(uint *)(plVar4 + 0x1fc) = uVar8;
            *(uint *)(plVar4 + 0x1fd) = uVar8;
            *(uint *)((longlong)plVar4 + 0xfec) = uVar8 * 2;
            *(uint *)(plVar4 + 0x1fe) = uVar8 * 3;
            *(uint *)((longlong)plVar4 + 0xff4) = uVar8 - 1;
            *(uint *)(plVar4 + 0x1ff) = uVar8 * 2 + -1;
            *(uint *)((longlong)plVar4 + 0xffc) = uVar8 * 3 + -1;
            if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              _Size = (char *)(ulonglong)*(byte *)(lVar2 + 5);
              in_stack_ffffffffffffff98 = in_stack_ffffffffffffff98 & 0xffffffff00000000;
              WPP_SF_qdddD(WPP_GLOBAL_Control[3],(ulonglong)*(byte *)(lVar2 + 6),_Size,lVar2,
                           *(byte *)(lVar2 + 5),*(byte *)(lVar2 + 6),*(undefined1 *)(lVar2 + 7),
                           (char)uVar16);
            }
          }
        }
      }
      if (*(longlong *)(param_2 + 0x98) != 0) {
        plVar15 = param_1 + 0x36;
        KeAcquireSpinLockAtDpcLevel(plVar15);
        if ((*(uint *)(param_2 + 0x7c) & 0x20000000) == 0) {
          KeReleaseSpinLockFromDpcLevel(plVar15);
          lVar9 = *(longlong *)(param_2 + 0x98);
          if ((*(byte *)(lVar9 + 10) & 5) == 0) {
            _Size = (char *)0x1;
            lVar9 = MmMapLockedPagesSpecifyCache
                              (lVar9,0,1,0,in_stack_ffffffffffffff98 & 0xffffffff00000000,
                               (-(uint)(*(char *)(lVar3 + 0x40) != '\0') & 0xfffffff0) + 0x20);
          }
          else {
            lVar9 = *(longlong *)(lVar9 + 0x18);
          }
          if (lVar9 != 0) {
            MmUnmapLockedPages(lVar9,*(undefined8 *)(param_2 + 0x98));
          }
        }
        else {
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_qq(WPP_GLOBAL_Control[3],0x3b,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,
                      param_1,uVar19);
          }
          _Size = *(char **)(param_2 + 0x98);
          MmUnmapReservedMapping(param_1[0xef],0x6d506353);
          *(uint *)((longlong)param_1 + 0x17c) = *(uint *)((longlong)param_1 + 0x17c) & 0xffdfffff;
          *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) & 0xdfffffff;
          KeReleaseSpinLockFromDpcLevel(plVar15);
        }
        if ((*(uint *)(param_2 + 0x7c) & 0x40000000) == 0) {
          IoFreeMdl(*(undefined8 *)(param_2 + 0x98));
        }
        else {
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            _Size = &WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids;
            WPP_SF_qq(WPP_GLOBAL_Control[3],0x3c,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,
                      param_1,uVar19);
          }
          KeAcquireSpinLockAtDpcLevel(plVar15);
          *(uint *)((longlong)param_1 + 0x17c) = *(uint *)((longlong)param_1 + 0x17c) & 0xffbfffff;
          KeReleaseSpinLockFromDpcLevel(plVar15);
          *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) & 0xbfffffff;
        }
        *(undefined8 *)(param_2 + 0x98) = 0;
      }
    }
  }
  if (*(longlong *)(param_2 + 0x58) != 0) {
    if (*(char *)((longlong)param_1 + 0x48a) == '\x01') {
      _Size = (char *)((ulonglong)
                       CONCAT31((uint3)(*(uint *)(lVar2 + 0xc) >> 0xe),
                                ~(byte)(*(uint *)(lVar2 + 0xc) >> 6)) & 0xffffffffffffff01);
      (**(code **)(*(longlong *)(param_1[0x3a] + 8) + 0x60))();
      *(undefined8 *)(param_2 + 0xa8) = 0;
    }
    else {
      _Size = (char *)(ulonglong)*(uint *)(param_2 + 0x60);
      (**(code **)(*(longlong *)(param_1[0x3a] + 8) + 0x38))();
    }
    *(undefined8 *)(param_2 + 0x58) = 0;
  }
  if (param_2 == (undefined *)plVar4[0x3e]) {
    plVar4[0x3e] = 0;
  }
  plVar15 = param_1 + 0x36;
  KeAcquireSpinLockAtDpcLevel(plVar15);
  if ((*(uint *)(param_2 + 0x7c) & 0x20000000) != 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qq(WPP_GLOBAL_Control[3],0x3d,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,param_1,
                uVar19);
    }
    _Size = *(char **)(lVar3 + 8);
    MmUnmapReservedMapping(param_1[0xef]);
    *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) & 0xdfffffff;
    *(uint *)((longlong)param_1 + 0x17c) = *(uint *)((longlong)param_1 + 0x17c) & 0xffdfffff;
  }
  KeReleaseSpinLockFromDpcLevel(plVar15);
  if ((*(uint *)(lVar2 + 0xc) & 4) != 0) {
    KeAcquireSpinLockAtDpcLevel(plVar15);
    *(uint *)((longlong)param_1 + 0x17c) = *(uint *)((longlong)param_1 + 0x17c) | 0x1000;
    if (-1 < (char)param_1[0x6d]) {
      *(undefined4 *)(param_1 + 0x31) = 0xffffffff;
    }
    KeReleaseSpinLockFromDpcLevel(plVar15);
    if ((*param_3 == '\0') && ((*(uint *)((longlong)param_1 + 0x17c) & 0x801) == 0)) {
      IoStartNextPacket(*param_1);
    }
  }
  *(ulonglong *)(lVar3 + 0x38) = (ulonglong)*(uint *)(lVar2 + 0x10);
  uVar1 = *(undefined4 *)(param_2 + 0x54);
  *(undefined4 *)(param_2 + 0x50) = 0;
  KeAcquireSpinLockAtDpcLevel(plVar15);
  plVar15 = (longlong *)0x0;
  if (*(longlong *)(lVar2 + 0x38) != 0) {
    if (((*(char *)(lVar2 + 2) != '\x17') && (*(char *)((longlong)param_1 + 0x48c) != '\0')) &&
       (*(longlong *)(lVar2 + 0x20) != 0)) {
      if (*(char *)(lVar2 + 3) < '\0') {
        if (*(char *)((longlong)param_1 + 0x749) != '\0') {
          uVar16 = *(uint *)(lVar2 + 0x10);
          if (*(uint *)(param_2 + 0x78) <= *(uint *)(lVar2 + 0x10)) {
            uVar16 = *(uint *)(param_2 + 0x78);
          }
          *(uint *)(lVar2 + 0x10) = uVar16;
          uVar10 = SpFireSenseDataEvent(lVar2,lVar13);
          if (((((int)uVar10 != 0) && ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
             (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_D(WPP_GLOBAL_Control[3],0x3e,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,
                     (int)uVar10);
          }
        }
        if ((*(uint *)(lVar2 + 0xc) & 0x200000) == 0) {
          bVar6 = param_2[0xb0];
          *(byte *)(lVar2 + 0xb) = bVar6;
        }
        else {
          bVar6 = *(byte *)(lVar2 + 0xb);
          uVar10 = *(undefined8 *)(lVar13 + 8);
          uVar18 = (ulonglong)(byte)((bVar6 + 3 & 0xfc) - bVar6);
          lVar9 = bVar6 + uVar18;
          lVar11 = ExAllocatePoolWithTag(4,lVar9 + 8,0x69506353);
          if (lVar11 == 0) {
            SpLogAllocationFailureFn(uVar10,4,(int)lVar9 + 8,0x69506353,0x696e7472,0x19bb);
            bVar6 = param_2[0xb0];
            *(byte *)(lVar2 + 0xb) = bVar6;
          }
          else {
            *(uint *)(lVar2 + 0xc) = *(uint *)(lVar2 + 0xc) | 0x400400;
            *(undefined4 *)((ulonglong)*(byte *)(lVar2 + 0xb) + lVar11 + uVar18) =
                 *(undefined4 *)((longlong)param_1 + 0x15c);
            *(longlong *)(param_2 + 0x70) = lVar11;
            bVar6 = *(byte *)(lVar2 + 0xb);
          }
        }
        _Size = (char *)(ulonglong)bVar6;
        memcpy(*(void **)(param_2 + 0x70),*(void **)(lVar2 + 0x20),(size_t)_Size);
      }
      else {
        *(undefined *)(lVar2 + 0xb) = param_2[0xb0];
      }
      *(undefined8 *)(lVar2 + 0x20) = *(undefined8 *)(param_2 + 0x70);
    }
    plVar15 = (longlong *)0x0;
    if (param_1[0xec] == 0) {
      bVar6 = 0;
    }
    else {
      bVar6 = *(byte *)(param_1[0xec] + 100) & 1;
    }
    plVar14 = *(longlong **)(lVar2 + 0x38);
    if (bVar6 == 0) {
      *plVar14 = param_1[0x46];
      param_1[0x46] = *(longlong *)(lVar2 + 0x38);
    }
    else {
      SpInsertSrbExtension((longlong)param_1,(ulonglong)plVar14);
      plVar15 = plVar14;
    }
  }
  *(char *)((longlong)plVar4 + 0x1f9) = *(char *)((longlong)plVar4 + 0x1f9) + -1;
  if ((*(uint *)((longlong)param_1 + 0x17c) & 0x800) != 0) {
    if ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      _Size = &WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids;
      plVar15 = (longlong *)0x3f;
      WPP_SF_qq(WPP_GLOBAL_Control[3],0x3f,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,param_2,
                (char)*(undefined8 *)(lVar13 + 0x20));
    }
    *(uint *)((longlong)param_1 + 0x17c) = *(uint *)((longlong)param_1 + 0x17c) & 0xfffff7ff;
    *param_3 = '\x01';
  }
  bVar6 = *(byte *)(lVar2 + 3) & 0x3f;
  if (bVar6 == 1) {
    *(undefined4 *)(lVar3 + 0x30) = 0;
    if (((*(uint *)(lVar2 + 0xc) & 0x10) == 0) && ((int)plVar4[0x39] == -1)) {
      GetNextLuRequest(plVar4,plVar15,_Size);
    }
    else {
      KeReleaseSpinLockFromDpcLevel(param_1 + 0x36);
    }
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_q(WPP_GLOBAL_Control[3],0x40,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,lVar3);
    }
    *(longlong *)(lVar2 + 0x30) = lVar3;
    goto LAB_140008671;
  }
  if (*(byte *)(lVar2 + 3) == 0x30) {
    *(undefined4 *)(lVar2 + 0x40) = uVar17;
  }
  else if (bVar6 < 0x13) {
    if (bVar6 == 0x12) {
      uVar17 = 0x80000005;
    }
    else if (bVar6 == 8) {
LAB_14000823c:
      uVar17 = 0xc00000c0;
    }
    else {
      if (bVar6 != 9) {
        if (bVar6 == 10) {
          uVar17 = 0xc000009d;
          goto LAB_140008284;
        }
        if (bVar6 != 0xb) {
          if (bVar6 != 0x11) goto LAB_140008270;
          goto LAB_14000823c;
        }
      }
      uVar17 = 0xc00000b5;
    }
  }
  else {
    if (bVar6 != 0x15) {
      if ((bVar6 == 0x20) || (bVar6 == 0x21)) goto LAB_14000823c;
      if (bVar6 != 0x22) {
LAB_140008270:
        uVar17 = 0xc0000185;
        goto LAB_140008284;
      }
    }
    uVar17 = 0xc0000010;
  }
LAB_140008284:
  *(undefined4 *)(lVar3 + 0x30) = uVar17;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_dDD(WPP_GLOBAL_Control[3],(ulonglong)*(byte *)(lVar2 + 4),_Size,
               (uint)*(byte *)(lVar2 + 6),*(byte *)(lVar2 + 4),*(undefined1 *)(lVar2 + 3));
  }
  cVar7 = *(char *)(lVar2 + 4);
  uVar10 = 0;
  if ((((cVar7 == '\b') || (*(char *)(lVar2 + 3) == '\x05')) || (cVar7 == '(')) &&
     ((*(uint *)(lVar2 + 0xc) & 0x10) == 0)) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_DD(WPP_GLOBAL_Control[3],0x42,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,
                (uint)*(byte *)(lVar2 + 3),cVar7);
    }
    *(undefined4 *)(lVar2 + 0x10) = *(undefined4 *)(param_2 + 0x78);
    uVar16 = *(uint *)(plVar4 + 0x28);
    if (((uVar16 & 8) == 0) || ((*(uint *)(lVar2 + 0xc) & 0x80000) != 0)) {
      bVar6 = *(byte *)((longlong)plVar4 + 0x157);
      *(byte *)((longlong)plVar4 + 0x157) = bVar6 + 1;
      if (0x13 < bVar6) {
        if (((uVar16 & 0x40) == 0) && ((*(uint *)(lVar2 + 0xc) & 0x100) == 0)) {
          *(byte *)(lVar2 + 3) = *(byte *)(lVar2 + 3) | 0x40;
          uVar16 = *(uint *)(plVar4 + 0x28) | 1;
        }
        *(uint *)(plVar4 + 0x28) = uVar16 & 0xffffffef;
        uVar10 = CONCAT71((uint7)(uint3)((uVar16 & 0xffffffef) >> 8),0x48);
        _Size = (char *)IoAllocateErrorLogEntry(*param_1,uVar10);
        if (_Size != (char *)0x0) {
          _Size[0xc] = '\x0f';
          _Size[0xd] = '\0';
          _Size[0xe] = '\x04';
          _Size[0xf] = -0x40;
          *(undefined4 *)(_Size + 0x18) = uVar1;
          uVar10 = CONCAT71((int7)((ulonglong)uVar10 >> 8),**(char **)(lVar3 + 0xb8));
          *_Size = **(char **)(lVar3 + 0xb8);
          _Size[1] = *(char *)((longlong)plVar4 + 0x157);
          _Size[0x10] = '\x03';
          _Size[0x11] = '\x01';
          _Size[0x12] = '\0';
          _Size[0x13] = '\0';
          _Size[0x14] = -0x5d;
          _Size[0x15] = '\0';
          _Size[0x16] = '\0';
          _Size[0x17] = -0x40;
          _Size[2] = '\x18';
          _Size[3] = '\0';
          *(uint *)(_Size + 0x28) = (uint)*(byte *)(lVar2 + 5);
          *(uint *)(_Size + 0x2c) = (uint)*(byte *)(lVar2 + 6);
          *(uint *)(_Size + 0x30) = (uint)*(byte *)(lVar2 + 7);
          *(uint *)(_Size + 0x34) = (uint)*(byte *)(lVar2 + 4);
          _Size[0x38] = '\a';
          _Size[0x39] = '\0';
          _Size[0x3a] = '\0';
          _Size[0x3b] = '\0';
          *(uint *)(_Size + 0x3c) = (uint)*(byte *)(lVar2 + 3);
          IoWriteErrorLogEntry(_Size);
        }
        *(undefined4 *)(lVar3 + 0x30) = 0xc00000a3;
        goto LAB_1400084cb;
      }
      *(undefined2 *)(lVar2 + 3) = 0;
      *(uint *)(plVar4 + 0x28) = *(uint *)(plVar4 + 0x28) | 8;
      plVar4[0x3d] = (longlong)param_2;
    }
    else {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_(WPP_GLOBAL_Control[3],0x43,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids);
      }
      *(undefined2 *)(lVar2 + 3) = 0;
      *(undefined4 *)(param_2 + 0x90) = *(undefined4 *)((longlong)param_1 + 0x6e4);
      uVar17 = *(undefined4 *)(lVar2 + 0x40);
      lVar2 = *plVar4;
      cVar7 = KeInsertByKeyDeviceQueue(lVar2 + 0xa0,lVar3 + 0x78,uVar17);
      if (cVar7 == '\0') {
        KeInsertByKeyDeviceQueue(lVar2 + 0xa0,lVar3 + 0x78,uVar17);
      }
    }
    KeReleaseSpinLockFromDpcLevel(param_1 + 0x36);
    goto LAB_1400083d0;
  }
LAB_1400084cb:
  if (((*(char *)(lVar2 + 4) != '\x02') || (*(char *)(lVar2 + 3) < '\0')) ||
     ((*(longlong *)(lVar2 + 0x20) == 0 || (*(char *)(lVar2 + 0xb) == '\0')))) {
    puVar12 = (undefined *)plVar4[0x1dc];
    if (puVar12 == param_2) {
      puVar12 = (undefined *)plVar4[0x1dd];
      plVar4[0x1dc] = (longlong)puVar12;
      plVar4[0x1dd] = 0;
    }
    if ((undefined *)plVar4[0x1dd] == param_2) {
      plVar4[0x1dd] = 0;
    }
    if (puVar12 == (undefined *)0x0) {
      *(uint *)(plVar4 + 0x28) = *(uint *)(plVar4 + 0x28) & 0xfffffffb;
    }
  }
  if ((((*(char *)(lVar2 + 4) == '\x02') && (-1 < *(char *)(lVar2 + 3))) &&
      ((*(longlong *)(lVar2 + 0x20) != 0 && (*(char *)(lVar2 + 0xb) != '\0')))) ||
     ((*(uint *)(lVar2 + 0xc) & 0x100) == 0)) {
    if (((*(uint *)(plVar4 + 0x28) & 0x40) == 0) &&
       (((*(uint *)(lVar2 + 0xc) & 0x100) == 0 ||
        ((((*(char *)(lVar2 + 4) == '\x02' && (-1 < *(char *)(lVar2 + 3))) &&
          (*(longlong *)(lVar2 + 0x20) != 0)) && (*(char *)(lVar2 + 0xb) != '\0')))))) {
      *(byte *)(lVar2 + 3) = *(byte *)(lVar2 + 3) | 0x40;
      *(uint *)(plVar4 + 0x28) = *(uint *)(plVar4 + 0x28) | 1;
    }
    if (((*(char *)(lVar2 + 4) == '\x02') && (-1 < *(char *)(lVar2 + 3))) &&
       ((*(longlong *)(lVar2 + 0x20) != 0 && (*(char *)(lVar2 + 0xb) != '\0')))) {
      if ((*(uint *)(plVar4 + 0x28) & 8) != 0) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_(WPP_GLOBAL_Control[3],0x44,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids);
        }
        *(undefined4 *)(param_2 + 0x90) = *(undefined4 *)((longlong)param_1 + 0x6e4);
        cVar7 = KeInsertByKeyDeviceQueue
                          (*plVar4 + 0xa0,*(longlong *)(plVar4[0x3d] + 0x38) + 0x78,
                           *(undefined4 *)(lVar2 + 0x40));
        if (cVar7 == '\0') {
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_q(WPP_GLOBAL_Control[3],0x45,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,
                     lVar3);
          }
          goto LAB_14000865e;
        }
        *(uint *)(plVar4 + 0x28) = *(uint *)(plVar4 + 0x28) & 0xffffffe7;
      }
      KeReleaseSpinLockFromDpcLevel(param_1 + 0x36);
      IssueRequestSense(param_1,lVar2);
LAB_1400083d0:
      SpDecrementActiveRequestCount((longlong)param_1);
      return;
    }
  }
  else if ((int)plVar4[0x39] == -1) {
    GetNextLuRequest(plVar4,CONCAT71((int7)((ulonglong)uVar10 >> 8),2),_Size);
    goto LAB_140008671;
  }
LAB_14000865e:
  KeReleaseSpinLockFromDpcLevel(param_1 + 0x36);
LAB_140008671:
  SpDecrementActiveRequestCount((longlong)param_1);
  SpReleaseRemoveLock(lVar13,(char)lVar3);
  SpCompleteRequest(lVar13,lVar3,param_2,1);
  return;
}



===== SpReceiveScatterGather @ 1400086e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SpReceiveScatterGather(longlong param_1,longlong param_2,uint *param_3,longlong param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  bool bVar3;
  undefined1 uVar4;
  int iVar5;
  undefined8 *puVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  longlong lVar14;
  ulonglong in_stack_ffffffffffffff98;
  undefined8 *local_48 [2];
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar2 = *(ulonglong *)(param_4 + 0x40);
  *(uint **)(param_4 + 0x58) = param_3;
  *(uint **)(param_4 + 0xa8) = param_3 + 4;
  if (((*(char *)(lVar1 + 0x488) != '\x01') && (*(char *)(uVar2 + 2) != '\x02')) &&
     ((*(char *)(uVar2 + 2) != '\0' || ((*(char *)(uVar2 + 0x48) - 0x28U & 0xfd) == 0)))) {
    *(undefined8 *)(param_4 + 0x98) = 0;
LAB_140008e21:
    LOCK();
    *(int *)(lVar1 + 0x164) = *(int *)(lVar1 + 0x164) + 1;
    UNLOCK();
    uVar4 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x1b0);
    (**(code **)(lVar1 + 0x1a0))(*(undefined8 *)(lVar1 + 400),SpStartIoSynchronized,param_1);
    KeReleaseSpinLock(lVar1 + 0x1b0,uVar4);
    return;
  }
  puVar6 = *(undefined8 **)(param_2 + 8);
  lVar14 = 0;
  local_48[0] = (undefined8 *)0x0;
  bVar3 = false;
LAB_14000875c:
  uVar4 = (undefined1)uVar2;
  if ((*(char *)(lVar1 + 0x489) != '\0') || (bVar3)) {
    uVar8 = *param_3;
    uVar13 = (ulonglong)uVar8;
    puVar9 = *(uint **)(param_4 + 0xa8);
    in_stack_ffffffffffffff98 = 0;
    puVar6 = (undefined8 *)SpAllocateMdlEx();
    if (puVar6 == (undefined8 *)0x0) {
      puVar6 = (undefined8 *)0x0;
      if (*(longlong *)(lVar1 + 0x780) != 0) {
        KeAcquireSpinLockAtDpcLevel(lVar1 + 0x1b0);
        uVar8 = *param_3;
        uVar13 = (ulonglong)uVar8;
        if ((*(uint *)(lVar1 + 0x17c) & 0x400000) != 0) {
LAB_140008b02:
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_qq(WPP_GLOBAL_Control[3],0x2d,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,
                      lVar1,uVar4);
          }
          *(uint *)(lVar1 + 0x17c) = *(uint *)(lVar1 + 0x17c) | 0x800;
          puVar6 = *(undefined8 **)(uVar2 + 0x38);
          if (puVar6 != (undefined8 *)0x0) {
            if (((*(char *)(uVar2 + 2) != '\x17') && (*(char *)(lVar1 + 0x48c) != '\0')) &&
               (*(longlong *)(uVar2 + 0x20) != 0)) {
              *(undefined1 *)(uVar2 + 0xb) = *(undefined1 *)(param_4 + 0xb0);
              *(undefined8 *)(uVar2 + 0x20) = *(undefined8 *)(param_4 + 0x70);
            }
            if ((*(longlong *)(lVar1 + 0x760) == 0) ||
               ((*(uint *)(*(longlong *)(lVar1 + 0x760) + 100) & 1) == 0)) {
              *puVar6 = *(undefined8 *)(lVar1 + 0x230);
              *(undefined8 **)(lVar1 + 0x230) = puVar6;
            }
            else {
              SpInsertSrbExtension(lVar1,(ulonglong)puVar6);
            }
          }
          (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 0x1d0) + 8) + 0x60))
                    (*(longlong *)(lVar1 + 0x1d0),*(undefined8 *)(param_4 + 0x58),
                     CONCAT31((uint3)(*(uint *)(uVar2 + 0xc) >> 0xe),
                              ~(byte)(*(uint *)(uVar2 + 0xc) >> 6)) & 0xffffff01);
          *(undefined8 *)(param_4 + 0xa8) = 0;
          goto LAB_140008bda;
        }
        if ((uint)(((ulonglong)*(uint *)(uVar2 + 0x18) & 0xfff) +
                   (ulonglong)*(uint *)(uVar2 + 0x10) + 0xfff >> 0xc) < 5) {
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            in_stack_ffffffffffffff98 = uVar2;
            WPP_SF_qq(WPP_GLOBAL_Control[3],0x54,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,
                      lVar1,uVar4);
          }
          *(uint *)(lVar1 + 0x17c) = *(uint *)(lVar1 + 0x17c) | 0x400000;
          *(uint *)(param_4 + 0x7c) = *(uint *)(param_4 + 0x7c) | 0x40000000;
          uVar11 = *(ulonglong *)(uVar2 + 0x18);
          uVar10 = *(uint *)(uVar2 + 0x10);
          puVar6 = *(undefined8 **)(lVar1 + 0x780);
          uVar12 = 0;
          *(undefined2 *)((longlong)puVar6 + 10) = 0;
          *puVar6 = 0;
          *(short *)(puVar6 + 1) =
               ((short)((ulonglong)uVar10 + 0xfff + (uVar11 & 0xfff) >> 0xc) + 6) * 8;
          puVar6[4] = uVar11 & 0xfffffffffffff000;
          *(uint *)((longlong)puVar6 + 0x2c) = (uint)uVar11 & 0xfff;
          *(uint *)(puVar6 + 5) = uVar10;
          puVar9 = *(uint **)(param_4 + 0xa8);
          *(undefined2 *)((longlong)puVar6 + 10) = 0x802;
          if (uVar8 != 0) {
            do {
              uVar10 = 0;
              uVar8 = (uint)((ulonglong)(*puVar9 & 0xfff) + 0xfff + (ulonglong)puVar9[2] >> 0xc);
              uVar11 = uVar12;
              if (uVar8 != 0) {
                do {
                  uVar7 = uVar10 << 0xc;
                  uVar10 = uVar10 + 1;
                  uVar12 = (ulonglong)((int)uVar11 + 1);
                  puVar6[uVar11 + 6] = (ulonglong)uVar7 + *(longlong *)puVar9 >> 0xc;
                  uVar11 = uVar12;
                } while (uVar10 < uVar8);
              }
              puVar9 = puVar9 + 6;
              uVar13 = uVar13 - 1;
            } while (uVar13 != 0);
          }
          if (puVar6 == (undefined8 *)0xffffffffffffffff) goto LAB_140008b02;
        }
        else {
          puVar6 = (undefined8 *)0x0;
        }
        KeReleaseSpinLockFromDpcLevel();
      }
    }
    else {
      uVar11 = 0;
      *(ushort *)((longlong)puVar6 + 10) = *(ushort *)((longlong)puVar6 + 10) | 0x802;
      if (uVar8 != 0) {
        do {
          uVar10 = 0;
          uVar8 = (uint)((ulonglong)(*puVar9 & 0xfff) + 0xfff + (ulonglong)puVar9[2] >> 0xc);
          uVar12 = uVar11;
          if (uVar8 != 0) {
            do {
              uVar7 = uVar10 << 0xc;
              uVar10 = uVar10 + 1;
              uVar11 = (ulonglong)((int)uVar12 + 1);
              puVar6[uVar12 + 6] = (ulonglong)uVar7 + *(longlong *)puVar9 >> 0xc;
              uVar12 = uVar11;
            } while (uVar10 < uVar8);
          }
          puVar9 = puVar9 + 6;
          uVar13 = uVar13 - 1;
        } while (uVar13 != 0);
      }
    }
    *(undefined8 **)(param_4 + 0x98) = puVar6;
LAB_140008a14:
    if (puVar6 == (undefined8 *)0x0) {
      *(undefined4 *)(param_4 + 0x8c) = 0xc000009a;
      *(undefined2 *)(uVar2 + 3) = 0xff30;
      goto LAB_140008e21;
    }
    uVar8 = (uint)(in_stack_ffffffffffffff98 >> 0x20);
    if (*(longlong *)(param_4 + 0x98) != 0) {
      lVar14 = MmMapLockedPagesSpecifyCache
                         (puVar6,0,1,0,(ulonglong)uVar8 << 0x20,
                          (-(uint)(*(char *)(param_2 + 0x40) != '\0') & 0xfffffff0) + 0x20);
      if (lVar14 != 0) goto LAB_140008df7;
LAB_140008c26:
      if (*(longlong *)(lVar1 + 0x778) != 0) {
        KeAcquireSpinLockAtDpcLevel(lVar1 + 0x1b0);
        lVar14 = SpMapLockedPagesWithReservedMapping(lVar1,uVar2,param_4,(longlong)puVar6);
        if (lVar14 == -1) {
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_qq(WPP_GLOBAL_Control[3],0x2e,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,
                      lVar1,uVar4);
          }
          *(uint *)(lVar1 + 0x17c) = *(uint *)(lVar1 + 0x17c) | 0x800;
          puVar6 = *(undefined8 **)(uVar2 + 0x38);
          if (puVar6 != (undefined8 *)0x0) {
            if (((*(char *)(uVar2 + 2) != '\x17') && (*(char *)(lVar1 + 0x48c) != '\0')) &&
               (*(longlong *)(uVar2 + 0x20) != 0)) {
              *(undefined1 *)(uVar2 + 0xb) = *(undefined1 *)(param_4 + 0xb0);
              *(undefined8 *)(uVar2 + 0x20) = *(undefined8 *)(param_4 + 0x70);
            }
            if ((*(longlong *)(lVar1 + 0x760) == 0) ||
               ((*(uint *)(*(longlong *)(lVar1 + 0x760) + 100) & 1) == 0)) {
              *puVar6 = *(undefined8 *)(lVar1 + 0x230);
              *(undefined8 **)(lVar1 + 0x230) = puVar6;
            }
            else {
              SpInsertSrbExtension(lVar1,(ulonglong)puVar6);
            }
          }
          (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 0x1d0) + 8) + 0x60))
                    (*(longlong *)(lVar1 + 0x1d0),*(undefined8 *)(param_4 + 0x58),
                     CONCAT31((uint3)(*(uint *)(uVar2 + 0xc) >> 0xe),
                              ~(byte)(*(uint *)(uVar2 + 0xc) >> 6)) & 0xffffff01);
          *(undefined8 *)(param_4 + 0xa8) = 0;
          if (*(longlong *)(param_4 + 0x98) != 0) {
            if ((*(uint *)(param_4 + 0x7c) >> 0x1e & 1) == 0) {
              IoFreeMdl();
            }
            else {
              *(uint *)(param_4 + 0x7c) = *(uint *)(param_4 + 0x7c) & 0xbfffffff;
              *(uint *)(lVar1 + 0x17c) = *(uint *)(lVar1 + 0x17c) & 0xffbfffff;
            }
            *(undefined8 *)(param_4 + 0x98) = 0;
          }
LAB_140008bda:
          KeReleaseSpinLockFromDpcLevel(lVar1 + 0x1b0);
          return;
        }
        KeReleaseSpinLockFromDpcLevel(lVar1 + 0x1b0);
        if (lVar14 != 0) {
LAB_140008df7:
          *(longlong *)(uVar2 + 0x18) = lVar14;
          if (*(longlong *)(param_4 + 0x98) == 0) {
            *(longlong *)(uVar2 + 0x18) = *(longlong *)(param_4 + 0x68) + lVar14;
          }
          goto LAB_140008e21;
        }
      }
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_q(WPP_GLOBAL_Control[3],0x2f,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,param_2
                );
      }
      *(undefined2 *)(uVar2 + 3) = 0xff30;
      *(undefined4 *)(param_4 + 0x8c) = 0xc000009a;
      if (*(longlong *)(param_4 + 0x98) != 0) {
        IoFreeMdl();
        *(undefined8 *)(param_4 + 0x98) = 0;
      }
      goto LAB_140008e21;
    }
    if (lVar14 != 0) goto LAB_140008df7;
    if ((*(byte *)((longlong)puVar6 + 10) & 5) == 0) {
      in_stack_ffffffffffffff98 = (ulonglong)uVar8 << 0x20;
      lVar14 = MmMapLockedPagesSpecifyCache
                         (puVar6,0,1,0,in_stack_ffffffffffffff98,
                          (-(uint)(*(char *)(param_2 + 0x40) != '\0') & 0xfffffff0) + 0x20);
    }
    else {
      lVar14 = puVar6[3];
    }
    if (lVar14 != 0) goto LAB_140008df7;
    if ((bVar3) || (*(uint *)(puVar6 + 5) <= *(uint *)(uVar2 + 0x10))) goto LAB_140008c26;
  }
  else {
    *(undefined8 *)(param_4 + 0x98) = 0;
    iVar5 = (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 0x1d0) + 8) + 0x78))
                      (*(longlong *)(lVar1 + 0x1d0),param_3,*(undefined8 *)(param_2 + 8),local_48);
    if ((iVar5 < 0) || (*(undefined8 **)(param_2 + 8) == local_48[0])) goto LAB_140008a14;
    if ((*(byte *)((longlong)local_48[0] + 10) & 5) == 0) {
      in_stack_ffffffffffffff98 = in_stack_ffffffffffffff98 & 0xffffffff00000000;
      lVar14 = MmMapLockedPagesSpecifyCache
                         (local_48[0],0,1,0,in_stack_ffffffffffffff98,
                          (-(uint)(*(char *)(param_2 + 0x40) != '\0') & 0xfffffff0) + 0x20);
    }
    else {
      lVar14 = local_48[0][3];
    }
    if (lVar14 != 0) {
      puVar6 = local_48[0];
      goto LAB_140008a14;
    }
  }
  bVar3 = true;
  goto LAB_14000875c;
}



===== SpRerouteLegacyRequest @ 140008e94 =====

undefined4 SpRerouteLegacyRequest(longlong param_1,longlong param_2,undefined4 param_3)

{
  longlong lVar1;
  undefined4 uVar2;
  longlong *plVar3;
  
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  plVar3 = GetLogicalUnitExtension
                     (*(longlong *)(param_1 + 0x40),*(char *)(lVar1 + 5),
                      CONCAT31((int3)((uint)param_3 >> 8),*(undefined1 *)(lVar1 + 6)),
                      *(byte *)(lVar1 + 7),param_2 + 1,'\x01');
  SpReleaseRemoveLock(param_1,(char)param_2);
  if (plVar3 == (longlong *)0x0) {
    uVar2 = 0xc00000c0;
    *(undefined4 *)(param_2 + 0x30) = 0xc00000c0;
    IofCompleteRequest(param_2,0);
  }
  else {
    ObfReferenceObject(*plVar3);
    SpReleaseRemoveLock(*plVar3,(char)(param_2 + 1));
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    uVar2 = IofCallDriver(*plVar3,param_2);
    ObfDereferenceObject(*plVar3);
  }
  return uVar2;
}



===== SpResetBusSynchronized @ 140008f70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 SpResetBusSynchronized(longlong *param_1)

{
  uint *puVar1;
  uint uVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined1 uVar5;
  
  plVar3 = (longlong *)*param_1;
  if ((*(uint *)(plVar3 + 0x6d) & 0x80000) == 0) {
    uVar5 = (*(code *)plVar3[0x53])(plVar3[0x29],(char)param_1[1]);
    *(uint *)(plVar3 + 0x6d) = *(uint *)(plVar3 + 0x6d) | 0x80;
    *(int *)(plVar3 + 0x31) = (int)plVar3[0xf4];
    if ((*(uint *)(plVar3 + 0x6d) & 4) != 0) {
      lVar4 = *plVar3;
      LOCK();
      puVar1 = (uint *)(*(longlong *)(lVar4 + 0x40) + 0x180);
      uVar2 = *puVar1;
      *puVar1 = 0x20004;
      UNLOCK();
      if ((uVar2 >> 0x11 & 1) == 0) {
        KeInsertQueueDpc(lVar4 + 200,0,0);
      }
    }
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}



===== SpSendRequestSenseIrp @ 14000900c =====

void SpSendRequestSenseIrp(longlong *param_1,undefined8 *param_2,longlong param_3)

{
  undefined8 *_Dst;
  undefined8 *puVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  longlong lVar4;
  byte bVar5;
  longlong lVar6;
  uint uVar7;
  
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
     (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_(WPP_GLOBAL_Control[3],0x27,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids);
  }
  if ((*(uint *)(param_3 + 0xc) & 0x200000) != 0) {
    bVar5 = (char)param_1[0xe9] + 0x12;
    uVar2 = *(undefined8 *)(*param_1 + 8);
    lVar6 = ExAllocatePoolWithTag(4,(ulonglong)bVar5 + 8,0x69506353);
    if (lVar6 == 0) {
      SpLogAllocationFailureFn(uVar2,4,bVar5 + 8,0x69506353,0x696e7472,0xeb8);
    }
    else {
      *(uint *)(param_3 + 0xc) = *(uint *)(param_3 + 0xc) | 0x400400;
      *(undefined4 *)((ulonglong)bVar5 + 3 + lVar6 & 0xfffffffffffffffc) =
           *(undefined4 *)((longlong)param_1 + 0x15c);
      *(longlong *)(param_3 + 0x20) = lVar6;
      *(byte *)(param_3 + 0xb) = bVar5;
    }
  }
  lVar6 = param_2[0x1de];
  _Dst = param_2 + 0x1df;
  puVar1 = param_2 + 0x1ea;
  IoInitializeIrp(lVar6,0x118,1);
  uVar3 = *(ulonglong *)(param_3 + 0x20);
  bVar5 = *(byte *)(param_3 + 0xb);
  *puVar1 = 0;
  *(undefined2 *)((longlong)param_2 + 0xf5a) = 0;
  param_2[0x1ee] = uVar3 & 0xfffffffffffff000;
  *(uint *)((longlong)param_2 + 0xf7c) = (uint)uVar3 & 0xfff;
  *(uint *)(param_2 + 0x1ef) = (uint)bVar5;
  *(short *)(param_2 + 0x1eb) = ((short)((ulonglong)bVar5 + 0xfff + (uVar3 & 0xfff) >> 0xc) + 6) * 8
  ;
  memset(_Dst,0,0x58);
  MmBuildMdlForNonPagedPool(puVar1);
  lVar4 = *(longlong *)(lVar6 + 0xb8);
  *(undefined8 **)(lVar6 + 8) = puVar1;
  *(code **)(lVar4 + -0x10) = IssueRequestSenseCompletion;
  *(undefined8 **)(lVar4 + -8) = param_2;
  *(undefined1 *)(lVar4 + -0x45) = 0xe0;
  lVar4 = *(longlong *)(lVar6 + 0xb8);
  *(undefined2 *)(lVar4 + -0x48) = 0x10f;
  *(undefined4 *)(param_2 + 0x1e8) = 3;
  *(undefined1 *)((longlong)param_2 + 0xf02) = 6;
  *(undefined1 *)((longlong)param_2 + 0xf44) = *(undefined1 *)(param_3 + 0xb);
  *(undefined1 *)((longlong)param_2 + 0xf45) = 0;
  *(undefined8 **)(lVar4 + -0x40) = _Dst;
  uVar7 = 0x54;
  param_2[0x1e5] = lVar6;
  *(undefined1 *)((longlong)param_2 + 0xefe) = *(undefined1 *)((longlong)param_2 + 0x155);
  *(undefined1 *)((longlong)param_2 + 0xeff) = *(undefined1 *)((longlong)param_2 + 0x156);
  *(undefined1 *)((longlong)param_2 + 0xefd) = *(undefined1 *)((longlong)param_2 + 0x154);
  *(undefined1 *)((longlong)param_2 + 0xefa) = 0;
  *(undefined2 *)_Dst = 0x58;
  *(undefined4 *)((longlong)param_2 + 0xf0c) = *(undefined4 *)((longlong)param_1 + 0x794);
  *(undefined1 *)((longlong)param_2 + 0xf03) = 0;
  param_2[0x1e3] = 0;
  *(undefined4 *)((longlong)param_2 + 0xf04) = 0x54;
  if ((*(uint *)(param_3 + 0xc) & 0x100) != 0) {
    uVar7 = 0x154;
    *(undefined4 *)((longlong)param_2 + 0xf04) = 0x154;
  }
  if ((*(uint *)(param_3 + 0xc) & 0x80000) != 0) {
    uVar7 = uVar7 | 0x80000;
    *(uint *)((longlong)param_2 + 0xf04) = uVar7;
  }
  if ((*(uint *)(param_3 + 0xc) & 8) != 0) {
    *(uint *)((longlong)param_2 + 0xf04) = uVar7 | 8;
  }
  param_2[0x1e2] = *(undefined8 *)(param_3 + 0x20);
  *(uint *)(param_2 + 0x1e1) = (uint)*(byte *)(param_3 + 0xb);
  *(undefined2 *)((longlong)param_2 + 0xefb) = 0;
  param_2[0x1e4] = 0;
  IofCallDriver(*param_2,lVar6);
  return;
}



===== SpSendResetCompletion @ 1400092a0 =====

undefined8 SpSendResetCompletion(undefined8 param_1,longlong param_2,longlong *param_3)

{
  longlong lVar1;
  
  lVar1 = *param_3;
  *(undefined4 *)(lVar1 + 0x30) = *(undefined4 *)(param_2 + 0x30);
  SpReleaseRemoveLock(param_3[1],(char)lVar1);
  SpReleaseRemoveLock(param_3[2],(char)lVar1);
  IofCompleteRequest(lVar1,0);
  ExFreePoolWithTag(param_3,0);
  IoFreeIrp(param_2);
  return 0xc0000016;
}



===== SpStartIoSynchronized @ 140009330 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 SpStartIoSynchronized(longlong param_1)

{
  uint *puVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 uVar5;
  code *pcVar6;
  undefined1 uVar7;
  uint uVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong lVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  longlong *plVar14;
  longlong *plVar15;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
     (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_(WPP_GLOBAL_Control[3],0x22,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids);
  }
  puVar13 = auStack_28;
  puVar12 = auStack_28;
  plVar15 = (longlong *)0x80010;
  plVar3 = *(longlong **)(*(longlong *)(*(longlong *)(param_1 + 0x20) + 0xb8) + 8);
  lVar4 = plVar3[6];
  lVar10 = *(longlong *)(lVar4 + 0x30);
  *(longlong *)(lVar2 + 0x360) = lVar10;
  uVar8 = *(uint *)(lVar2 + 0x368);
  if ((uVar8 >> 0x13 & 1) == 0) {
    if ((char)uVar8 < '\0') {
      *(uint *)(lVar2 + 0x368) = uVar8 | 0x100;
      return 1;
    }
  }
  else {
    *(uint *)((longlong)plVar3 + 0xc) = *(uint *)((longlong)plVar3 + 0xc) | 0x80010;
    *(undefined1 *)((longlong)plVar3 + 3) = 0x11;
  }
  uVar8 = *(uint *)(lVar2 + 0x17c);
  *(uint *)(lVar2 + 0x17c) = uVar8 | 1;
  if ((*(uint *)((longlong)plVar3 + 0xc) & 4) != 0) {
    *(uint *)(lVar2 + 0x17c) = uVar8 & 0xffffefff | 1;
  }
  *(char *)(lVar10 + 0x1f9) = *(char *)(lVar10 + 0x1f9) + '\x01';
  if ((*(uint *)((longlong)plVar3 + 0xc) & 0x10) == 0) {
    *(uint *)(lVar10 + 0x140) = *(uint *)(lVar10 + 0x140) | 2;
  }
  else {
    uVar8 = *(uint *)((longlong)plVar3 + 0xc) & 0x80010;
    if ((uVar8 != 0) && ((uVar8 >> 0x13 == 0 || ((*(uint *)(lVar10 + 0x140) & 0xc0) != 0)))) {
      *(uint *)(lVar10 + 0x140) = *(uint *)(lVar10 + 0x140) & 0xfffffffb;
    }
    *(undefined4 *)(lVar10 + 0x1c8) = *(undefined4 *)((longlong)plVar3 + 0x14);
  }
  *(uint *)((longlong)plVar3 + 0xc) = *(uint *)((longlong)plVar3 + 0xc) | 0x10000;
  *(undefined4 *)(lVar4 + 0x90) = *(undefined4 *)(lVar2 + 0x6e4);
  if ((char)plVar3[1] == -1) {
    *(longlong *)(lVar10 + 0x1f0) = lVar4;
  }
  else {
    lVar11 = lVar10 + 0x1d0;
    plVar9 = (longlong *)(lVar4 + 0x20);
    plVar14 = *(longlong **)(lVar10 + 0x1d8);
    if (*plVar14 != lVar11) {
      lVar10 = 3;
      pcVar6 = (code *)swi(0x29);
      plVar9 = (longlong *)(*pcVar6)();
      puVar12 = auStack_20;
    }
    *plVar9 = lVar11;
    plVar9[1] = (longlong)plVar14;
    *plVar14 = (longlong)plVar9;
    *(longlong **)(lVar11 + 8) = plVar9;
    puVar13 = puVar12;
  }
  if (*(char *)((longlong)plVar3 + 3) == '\0') {
    *(undefined4 *)(lVar2 + 0x188) = *(undefined4 *)((longlong)plVar3 + 0x14);
    if (*(int *)(lVar10 + 0x1c8) == -1) {
      *(undefined4 *)(lVar10 + 0x1c8) = *(undefined4 *)((longlong)plVar3 + 0x14);
    }
    if ((((*(uint *)((longlong)plVar3 + 0xc) & 0xc0) != 0) &&
        (*(char *)((longlong)plVar3 + 2) == '\0')) &&
       ((((char)plVar3[9] - 0x28U & 0xfd) == 0 && (*(char *)(lVar2 + 0x488) == '\0')))) {
      plVar3[3] = 0;
    }
    pcVar6 = *(code **)(lVar2 + 0x288);
    uVar5 = *(undefined8 *)(lVar2 + 0x148);
    *(undefined8 *)(puVar13 + -8) = 0x140009524;
    uVar7 = (*pcVar6)(uVar5,plVar3);
  }
  else {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      uVar5 = WPP_GLOBAL_Control[3];
      *(undefined8 *)(puVar13 + -8) = 0x1400094ab;
      plVar15 = plVar3;
      WPP_SF_q(uVar5,0x23,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,plVar3);
    }
    lVar4 = *(longlong *)(lVar2 + 0x148);
    *(undefined8 *)(puVar13 + -8) = 0x1400094bc;
    plVar9 = plVar3;
    ScsiPortNotification(0,lVar4,(undefined *)plVar3,plVar15,puVar13[0x20],puVar13[0x28]);
    lVar4 = *(longlong *)(lVar2 + 0x148);
    *(undefined8 *)(puVar13 + -8) = 0x1400094cd;
    ScsiPortNotification(1,lVar4,(undefined *)plVar9,plVar15,puVar13[0x20],puVar13[0x28]);
    uVar7 = *(undefined1 *)((longlong)plVar3 + 3);
  }
  if ((*(uint *)(lVar2 + 0x368) & 4) != 0) {
    LOCK();
    puVar1 = (uint *)(*(longlong *)(param_1 + 0x40) + 0x180);
    uVar8 = *puVar1;
    *puVar1 = 0x20004;
    UNLOCK();
    if ((uVar8 >> 0x11 & 1) == 0) {
      *(undefined8 *)(puVar13 + -8) = 0x140009559;
      KeInsertQueueDpc(param_1 + 200,0,0);
    }
  }
  return uVar7;
}



===== SpSynchronizeExecution @ 140009580 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 SpSynchronizeExecution(longlong param_1,undefined *param_2,undefined8 param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x1c0);
  uVar2 = (*(code *)param_2)(param_3);
  KeReleaseSpinLock(param_1 + 0x1c0,uVar1);
  return uVar2;
}



===== SpTimeoutSynchronized @ 1400095f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 SpTimeoutSynchronized(longlong param_1)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  code *pcVar5;
  char cVar6;
  undefined1 uVar7;
  longlong local_18;
  byte bStack_10;
  undefined7 uStack_f;
  
  lVar4 = *(longlong *)(param_1 + 0x40);
  uVar7 = 1;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x2c) < '\0')) &&
     (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_(WPP_GLOBAL_Control[3],0x24,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids);
  }
  *(undefined4 *)(lVar4 + 0x188) = 0xffffffff;
  uVar2 = *(uint *)(lVar4 + 0x368);
  if ((char)uVar2 < '\0') {
    *(uint *)(lVar4 + 0x368) = uVar2 & 0xffffff7f;
    if (*(longlong *)(lVar4 + 0x760) != 0) {
      SpEnsureAllRequestsAreComplete(lVar4);
    }
    if ((*(uint *)(lVar4 + 0x368) >> 8 & 1) != 0) {
      *(uint *)(lVar4 + 0x368) = *(uint *)(lVar4 + 0x368) & 0xfffffeff;
      SpStartIoSynchronized(param_1);
    }
    uVar7 = 0;
  }
  else {
    bStack_10 = 0;
    uStack_f = 0;
    local_18 = lVar4;
    if ((((uVar2 >> 0x13 & 1) == 0) &&
        (iVar3 = *(int *)(lVar4 + 0x3e0), *(undefined4 *)(lVar4 + 0x3e0) = 0, iVar3 == 0)) &&
       (*(code **)(lVar4 + 0x290) != (code *)0x0)) {
      cVar6 = (**(code **)(lVar4 + 0x290))(*(undefined8 *)(lVar4 + 0x148));
      if (cVar6 != '\0') {
        DbgPrint("SpTimeoutSynchronized: Adapter %#p had interrupt pending - the system may not be delivering interrupts from this adapter\n"
                 ,param_1);
        if (ScsiCheckInterrupts != 0) {
          pcVar5 = (code *)swi(3);
          uVar7 = (*pcVar5)();
          return uVar7;
        }
        *(uint *)(lVar4 + 0x368) = *(uint *)(lVar4 + 0x368) | 0x100004;
        LOCK();
        puVar1 = (uint *)(*(longlong *)(param_1 + 0x40) + 0x180);
        uVar2 = *puVar1;
        *puVar1 = 0x20004;
        UNLOCK();
        if ((uVar2 >> 0x11 & 1) == 0) {
          KeInsertQueueDpc(param_1 + 200,0,0);
        }
      }
    }
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((char)*(undefined4 *)((longlong)WPP_GLOBAL_Control + 0x2c) < '\0')) &&
       (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_(WPP_GLOBAL_Control[3],0x25,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids);
    }
    bStack_10 = 0;
    if (*(char *)(lVar4 + 0x178) != '\0') {
      do {
        uVar7 = SpResetBusSynchronized(&local_18);
        bStack_10 = bStack_10 + 1;
      } while (bStack_10 < *(byte *)(lVar4 + 0x178));
    }
  }
  return uVar7;
}



===== UpdateQueuePointers @ 1400097b0 =====

void UpdateQueuePointers(longlong param_1,longlong param_2,undefined8 param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  int iVar9;
  bool bVar10;
  
  uVar2 = *(uint *)(param_1 + 0x1028);
  uVar8 = (ulonglong)uVar2;
  uVar7 = 0;
  uVar5 = *(uint *)(param_2 + 0x40);
  iVar9 = 0;
  if ((uVar5 < *(uint *)(param_1 + 0x158)) || (*(uint *)(param_1 + 0xff4 + uVar8 * 4) < uVar5)) {
    *(undefined4 *)(param_1 + 0x1030 + uVar8 * 4) = *(undefined4 *)(param_1 + 0xfe4 + uVar8 * 4);
    *(undefined1 *)(param_1 + 0x1040 + uVar8) = 0;
    uVar3 = *(uint *)(param_1 + 0xfdc);
    *(undefined4 *)(param_1 + 0x102c) = 0;
    if (uVar3 != 0) {
      do {
        if (uVar5 <= *(uint *)(param_1 + 0xff4 + uVar7 * 4)) goto LAB_14000992d;
        uVar6 = (int)uVar7 + 1;
        uVar7 = (ulonglong)uVar6;
      } while (uVar6 < uVar3);
    }
    uVar7 = (ulonglong)(uVar3 - 1);
LAB_14000992d:
    *(int *)(param_1 + 0x1028) = (int)uVar7;
    uVar5 = *(uint *)(param_1 + 0x1030 + uVar7 * 4);
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_ddD(WPP_GLOBAL_Control[3],param_2,param_3,uVar2,(char)uVar7,(char)uVar5);
    }
    goto LAB_14000996e;
  }
  *(int *)(param_1 + 0x102c) = *(int *)(param_1 + 0x102c) + 1;
  if (uVar5 == *(uint *)(param_1 + 0x158)) {
    bVar4 = *(char *)(param_1 + 0x1040 + uVar8) + 1;
    bVar10 = SpPerBlockLimit <= bVar4;
    *(byte *)(param_1 + 0x1040 + uVar8) = bVar4;
    if (bVar10) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_qDd(WPP_GLOBAL_Control[3],(ulonglong)bVar4,param_3,param_1,(char)uVar5,(char)uVar2);
      }
      iVar9 = 1;
      goto LAB_14000985c;
    }
  }
  else {
LAB_14000985c:
    bVar4 = 0;
    *(undefined1 *)(param_1 + 0x1040 + uVar8) = 0;
  }
  if (SpPerZoneLimit <= *(uint *)(param_1 + 0x102c)) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qDDdd(WPP_GLOBAL_Control[3],(ulonglong)bVar4,(ulonglong)(iVar9 + uVar5),param_1,
                   (char)(iVar9 + uVar5),bVar4,(char)uVar2,
                   (char)*(undefined4 *)(param_1 + 0x1044 + uVar8 * 4));
    }
    iVar1 = iVar9 + uVar5;
    iVar9 = 0;
    *(int *)(param_1 + 0x1030 + uVar8 * 4) = iVar1;
    *(undefined1 *)(param_1 + 0x1040 + uVar8) = 0;
    *(undefined4 *)(param_1 + 0x102c) = 0;
    uVar2 = *(uint *)(param_1 + 0x1044 + uVar8 * 4);
    *(uint *)(param_1 + 0x1028) = uVar2;
    uVar5 = *(uint *)(param_1 + 0x1030 + (ulonglong)uVar2 * 4);
  }
LAB_14000996e:
  *(uint *)(param_1 + 0x158) = iVar9 + uVar5;
  return;
}



===== WPP_SF_Dqq @ 1400099a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dqq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,0x15,local_res20,4,
             &param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_Ld @ 140009a08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Ld(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,param_2,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_dDD @ 140009a60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,0x41,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_ddD @ 140009ac4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ddD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,0x33,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_qDDdd @ 140009b28 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDDdd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,0x35,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_SF_qDd @ 140009bac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,0x34,&local_res20,8,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_qdddD @ 140009c14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qdddD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,0x3a,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_SF_qq @ 140009c98 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,0);
  return;
}



===== WPP_SF_qqdddD @ 140009ce8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqdddD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                  undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                  undefined1 param_9)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,0x17,&local_res20,8,
             &param_5,8,&param_6,4,&param_7,4,&param_8,4,&param_9,4,0);
  return;
}



===== WPP_SF_qqq @ 140009d78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,0x55,&local_res20,8,
             &param_5,8,&param_6,8,0);
  return;
}



===== SpCompleteRequest @ 140009ddc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SpCompleteRequest(undefined8 param_1,undefined8 param_2,undefined *param_3,undefined1 param_4)

{
  longlong *plVar1;
  
  if (param_3 != (undefined *)0x0) {
    plVar1 = *(longlong **)(param_3 + 0x30);
    if ((byte)(*(char *)(*(longlong *)(param_3 + 0x40) + 2) - 0x18U) < 2) {
      SpStartLockRequest((longlong)plVar1,0,param_3);
    }
    *(undefined8 *)(*(longlong *)(param_3 + 0x40) + 0x30) = *(undefined8 *)(param_3 + 0x38);
    *(undefined8 *)(param_3 + 0x38) = 0;
    *(undefined8 *)(param_3 + 0x40) = 0;
    (**(code **)(param_3 + 0x18))(plVar1[0x2d],param_3);
    SpReleaseRemoveLock(*plVar1,(char)param_2);
  }
  IofCompleteRequest(param_2,param_4);
  return;
}



===== SpReleaseRemoveLock @ 140009e80 =====

void SpReleaseRemoveLock(longlong param_1,undefined1 param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  int iVar4;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  LOCK();
  piVar1 = (int *)(lVar3 + 0x4c);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  iVar4 = iVar2 + -1;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) &&
     (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qqd(WPP_GLOBAL_Control[3],0x14,&WPP_9e0e4c1d5fa93c1a5dcc08851cf79a7f_Traceguids,param_1,
               param_2,(char)iVar4);
  }
  if (iVar4 == 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qq(WPP_GLOBAL_Control[3],(short)iVar2 + 0x14,
                &WPP_9e0e4c1d5fa93c1a5dcc08851cf79a7f_Traceguids,param_1,param_2);
    }
    KeSetEvent(lVar3 + 0x50,0,0);
  }
  return;
}



===== WPP_SF_qqd @ 140009f60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,&param_6,4,0);
  return;
}



===== SpDeleteDeviceMapEntry @ 140009fc0 =====

void SpDeleteDeviceMapEntry(longlong param_1)

{
  if ((*(byte *)(param_1 + 8) & 1) == 0) {
    SpDeleteAdapterDeviceMap(param_1);
  }
  else {
    SpDeleteLogicalUnitDeviceMapEntry(param_1);
  }
  return;
}



===== ScsiPortInitLogicalUnit @ 140009fe4 =====

undefined8 ScsiPortInitLogicalUnit(longlong *param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  
  uVar2 = 0xffffffff;
  uVar3 = 0xffffffff;
  lVar4 = 4;
  lVar1 = PoRegisterDeviceForIdleDetection(*param_1);
  param_1[7] = lVar1;
  ScsiPortInitPdoWmi(param_1);
  SpBuildDeviceMapEntry(param_1,uVar2,uVar3,lVar4);
  return 0;
}



===== ScsiPortPdoDeviceControl @ 14000a030 =====

int ScsiPortPdoDeviceControl(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  ulonglong uVar4;
  undefined1 uVar5;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  uVar1 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  LOCK();
  *(int *)(lVar2 + 0x4c) = *(int *)(lVar2 + 0x4c) + 1;
  UNLOCK();
  uVar5 = (undefined1)param_2;
  if ((*(int *)(lVar2 + 0xc) != 0) && ((*(int *)(lVar2 + 0xc) != 1 || (uVar1 != 0x41024)))) {
    SpReleaseRemoveLock(param_1,uVar5);
    iVar3 = -0x3fffff40;
    goto LAB_14000a14d;
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  if (uVar1 < 0x4d005) {
    if (uVar1 == 0x4d004) {
      uVar4 = SpPdoHandleIoctlScsiPassthrough(param_1,param_2);
      return (int)uVar4;
    }
    if ((uVar1 != 0x4100c) && (uVar1 != 0x41010)) {
      if (uVar1 == 0x41018) {
        iVar3 = SpPdoHandleIoctlScsiGetAddress(param_1,param_2);
        return iVar3;
      }
      if ((uVar1 != 0x41020) && (uVar1 != 0x41024)) {
LAB_14000a108:
        if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x10) != 0 &&
            (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
          WPP_SF_D(WPP_GLOBAL_Control[3],10,&WPP_61736e3ed466352ac1be56969524dc0e_Traceguids,uVar1);
        }
        SpReleaseRemoveLock(param_1,uVar5);
        iVar3 = -0x3ffffff0;
LAB_14000a14d:
        *(int *)(param_2 + 0x30) = iVar3;
        IofCompleteRequest(param_2,0);
        return iVar3;
      }
    }
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    SpReleaseRemoveLock(param_1,uVar5);
    iVar3 = IofCallDriver(*(undefined8 *)(lVar2 + 0x10),param_2);
  }
  else {
    if (uVar1 != 0x4d008) {
      if (uVar1 == 0x4d014) {
        iVar3 = SpPdoHandleIoctlScsiPassthroughDirect(param_1,param_2);
        return iVar3;
      }
      if (uVar1 == 0x2d1400) {
        iVar3 = SpPdoHandleIoctlStorageQueryProperty(param_1,param_2);
        return iVar3;
      }
      if (uVar1 != 0x2d5014) goto LAB_14000a108;
    }
    iVar3 = SpPdoHandleIoctlStorageBreakReservation(param_1,param_2);
  }
  return iVar3;
}



===== ScsiPortPdoScsi @ 14000a1a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong ScsiPortPdoScsi(longlong param_1,longlong param_2,undefined *param_3)

{
  byte bVar1;
  char cVar2;
  longlong *plVar3;
  byte *pbVar4;
  longlong lVar5;
  uint uVar6;
  longlong lVar7;
  ulonglong uVar8;
  
  plVar3 = *(longlong **)(param_1 + 0x40);
  pbVar4 = *(byte **)(param_2 + 0xb8);
  lVar5 = *(longlong *)(pbVar4 + 8);
  LOCK();
  *(int *)((longlong)plVar3 + 0x4c) = *(int *)((longlong)plVar3 + 0x4c) + 1;
  UNLOCK();
  if ((*(int *)((longlong)plVar3 + 0xc) != 0) &&
     ((bVar1 = *pbVar4, 0x12 < bVar1 ||
      (param_3 = (undefined *)0x50004, (0x50004U >> (bVar1 & 0x1f) & 1) == 0)))) {
    if (bVar1 == 0xf) {
      cVar2 = *(char *)(*(longlong *)(pbVar4 + 8) + 2);
      if (((cVar2 == '\x06') || (cVar2 == '\x15')) ||
         ((*(uint *)(*(longlong *)(pbVar4 + 8) + 0xc) & 0x80010) != 0)) goto LAB_14000a217;
    }
    if (*(char *)(lVar5 + 2) != '\x01') {
      uVar6 = 0xc00000c0;
      goto LAB_14000a3c8;
    }
  }
LAB_14000a217:
  cVar2 = *(char *)(lVar5 + 2);
  *(undefined1 *)(lVar5 + 5) = *(undefined1 *)((longlong)plVar3 + 0x154);
  *(undefined1 *)(lVar5 + 6) = *(undefined1 *)((longlong)plVar3 + 0x155);
  *(undefined1 *)(lVar5 + 7) = *(undefined1 *)((longlong)plVar3 + 0x156);
  *(undefined1 *)(lVar5 + 8) = 0xff;
  if (cVar2 == '\x01') {
LAB_14000a3b0:
    uVar6 = SpClaimLogicalUnit(*(longlong *)(plVar3[2] + 0x40),plVar3,param_2,'\0');
LAB_14000a3c8:
    *(uint *)(param_2 + 0x30) = uVar6;
    SpReleaseRemoveLock(param_1,(char)param_2);
    IofCompleteRequest(param_2,0);
    return (ulonglong)uVar6;
  }
  if (cVar2 != '\x04') {
    if (cVar2 == '\x06') goto LAB_14000a3b0;
    if (cVar2 == '\x10') {
      uVar6 = 0xc00000bb;
      goto LAB_14000a3c8;
    }
    if (cVar2 != '\x15') {
      if (cVar2 == '\x16') goto LAB_14000a3b0;
      if ((cVar2 == '\x18') || (cVar2 == '\x19')) {
        SpStartLockRequest((longlong)plVar3,param_2,param_3);
        return 0x103;
      }
      if (((*(uint *)(lVar5 + 0xc) >> 0x14 & 1) != 0) && (*(int *)((longlong)plVar3 + 0x2c) != 1)) {
        if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0 &&
            (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
          WPP_SF_(WPP_GLOBAL_Control[3],0x13,&WPP_61736e3ed466352ac1be56969524dc0e_Traceguids);
        }
        uVar6 = 0xc0000001;
        *(undefined1 *)(lVar5 + 3) = 0x24;
        goto LAB_14000a3c8;
      }
      if ((*(uint *)(lVar5 + 0xc) & 0x80010) == 0) {
        lVar7 = SpAllocateSrbData(plVar3[0x2d],param_2,(longlong)plVar3);
        if (lVar7 == 0) {
          if ((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return 0x103;
          }
          if ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
            return 0x103;
          }
          if (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2) {
            return 0x103;
          }
          WPP_SF_(WPP_GLOBAL_Control[3],0x14,&WPP_61736e3ed466352ac1be56969524dc0e_Traceguids);
          return 0x103;
        }
        goto LAB_14000a34e;
      }
    }
  }
  lVar7 = SpAllocateBypassSrbData((longlong)plVar3);
LAB_14000a34e:
  *(longlong *)(lVar7 + 0x38) = param_2;
  *(longlong *)(lVar7 + 0x40) = lVar5;
  *(longlong **)(lVar7 + 0x30) = plVar3;
  *(longlong *)(lVar5 + 0x30) = lVar7;
  lVar5 = *(longlong *)(plVar3[2] + 0x40);
  lVar7 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  if (((((undefined4 *)plVar3[7] != (undefined4 *)0x0) &&
       (bVar1 = *(byte *)(lVar7 + 2), bVar1 < 0x18)) && ((0xdd0185U >> (bVar1 & 0x1f) & 1) != 0)) &&
     ((*(uint *)(lVar7 + 0xc) & 0x180000) == 0)) {
    *(undefined4 *)plVar3[7] = 0;
  }
  uVar8 = (**(code **)(*(longlong *)(lVar5 + 0x20) + 0x78))(plVar3[2],param_2);
  return uVar8;
}



===== ScsiPortScsi1PdoScsi @ 14000a410 =====

void ScsiPortScsi1PdoScsi(longlong param_1,longlong param_2,undefined8 param_3)

{
  byte *pbVar1;
  byte bVar2;
  
  bVar2 = *(char *)(*(longlong *)(param_1 + 0x40) + 0x156) << 5;
  pbVar1 = (byte *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 8) + 0x49);
  *pbVar1 = *pbVar1 | bVar2;
  ScsiPortPdoScsi(param_1,param_2,(undefined *)CONCAT71((int7)((ulonglong)param_3 >> 8),bVar2));
  return;
}



===== SpPagingPathNotificationCompletion @ 14000a450 =====

undefined8
SpPagingPathNotificationCompletion(undefined8 param_1,longlong param_2,undefined8 *param_3)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined8 uVar7;
  int *piVar8;
  longlong *plVar9;
  undefined8 *puVar10;
  char *pcVar11;
  
  lVar2 = *(longlong *)(param_2 + 0x18);
  lVar3 = *(longlong *)(lVar2 + 0xb8);
  lVar4 = *(longlong *)(lVar3 + 0x28);
  puVar10 = param_3;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    puVar10 = (undefined8 *)&WPP_61736e3ed466352ac1be56969524dc0e_Traceguids;
    WPP_SF_qq(WPP_GLOBAL_Control[3],0xf,&WPP_61736e3ed466352ac1be56969524dc0e_Traceguids,param_2,
              (char)lVar2);
  }
  lVar5 = param_3[8];
  plVar6 = *(longlong **)(lVar4 + 0x40);
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    puVar10 = (undefined8 *)&WPP_61736e3ed466352ac1be56969524dc0e_Traceguids;
    WPP_SF_D(WPP_GLOBAL_Control[3],0x10,&WPP_61736e3ed466352ac1be56969524dc0e_Traceguids,
             *(undefined4 *)(param_2 + 0x30));
  }
  if (-1 < *(int *)(param_2 + 0x30)) {
    iVar1 = *(int *)(lVar3 + 0x10);
    if (iVar1 == 1) {
      piVar8 = (int *)(lVar5 + 0x104);
      plVar9 = (longlong *)((longlong)plVar6 + 0x104);
      pcVar11 = "PagingPathCount";
    }
    else if (iVar1 == 2) {
      piVar8 = (int *)(lVar5 + 0x108);
      plVar9 = plVar6 + 0x21;
      pcVar11 = "HibernatePathCount";
    }
    else {
      if (iVar1 != 3) goto LAB_14000a61a;
      piVar8 = (int *)(lVar5 + 0x10c);
      plVar9 = (longlong *)((longlong)plVar6 + 0x10c);
      pcVar11 = "DumpPathCount";
    }
    if (piVar8 != (int *)0x0) {
      if (*(char *)(lVar3 + 8) == '\0') {
        LOCK();
        *piVar8 = *piVar8 + -1;
        UNLOCK();
      }
      else {
        LOCK();
        *piVar8 = *piVar8 + 1;
        UNLOCK();
      }
      puVar10 = WPP_GLOBAL_Control;
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_sd(WPP_GLOBAL_Control[3],0x11,WPP_GLOBAL_Control,pcVar11,(char)*piVar8);
      }
      IoInvalidateDeviceState(*(undefined8 *)(lVar5 + 0x140));
    }
    if (plVar9 != (longlong *)0x0) {
      if (*(char *)(lVar3 + 8) == '\0') {
        LOCK();
        *(int *)plVar9 = (int)*plVar9 + -1;
        UNLOCK();
      }
      else {
        LOCK();
        *(int *)plVar9 = (int)*plVar9 + 1;
        UNLOCK();
      }
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_sd(WPP_GLOBAL_Control[3],0x12,puVar10,pcVar11,(char)*plVar9);
      }
      IoInvalidateDeviceState(*plVar6);
    }
  }
LAB_14000a61a:
  uVar7 = *(undefined8 *)(param_2 + 0x38);
  *(undefined8 *)(lVar2 + 0x30) = *(undefined8 *)(param_2 + 0x30);
  *(undefined8 *)(lVar2 + 0x38) = uVar7;
  SpReleaseRemoveLock(*plVar6,(char)lVar2);
  IofCompleteRequest(lVar2,0);
  IoFreeIrp(param_2);
  return 0xc0000016;
}



===== SpStartLockRequest @ 14000a67c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SpStartLockRequest(longlong param_1,longlong param_2,undefined *param_3)

{
  byte *pbVar1;
  char cVar2;
  byte bVar3;
  undefined1 uVar4;
  char cVar5;
  longlong lVar6;
  longlong lVar7;
  char *pcVar8;
  char *pcVar9;
  
  lVar7 = param_2;
  uVar4 = KfRaiseIrql(2);
  pcVar8 = "lock";
  if (param_2 == 0) {
    *(undefined8 *)(param_1 + 0x1a0) = 0;
    lVar6 = KeRemoveDeviceQueue(param_1 + 0x178);
    if (lVar6 == 0) goto LAB_14000a833;
    param_2 = lVar6 + -0x78;
    lVar6 = *(longlong *)(*(longlong *)(lVar6 + 0x40) + 8);
    cVar2 = *(char *)(lVar6 + 2);
  }
  else {
    lVar6 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
    cVar2 = *(char *)(lVar6 + 2);
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      param_3 = &WPP_61736e3ed466352ac1be56969524dc0e_Traceguids;
      pcVar9 = "lock";
      if (cVar2 != '\x18') {
        pcVar9 = "unlock";
      }
      WPP_SF_sq(WPP_GLOBAL_Control[3],0x17,&WPP_61736e3ed466352ac1be56969524dc0e_Traceguids,pcVar9,
                (char)param_1);
    }
    lVar7 = param_2 + 0x78;
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    cVar5 = KeInsertDeviceQueue(param_1 + 0x178);
    if (cVar5 != '\0') goto LAB_14000a833;
  }
  *(uint *)(lVar6 + 0xc) = *(uint *)(lVar6 + 0xc) & 0xfffffffd | 0x80000;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    if (cVar2 != '\x18') {
      pcVar8 = "unlock";
    }
    WPP_SF_sqq(WPP_GLOBAL_Control[3],lVar7,param_3,pcVar8,(char)lVar6,(char)param_1);
  }
  lVar7 = SpAllocateBypassSrbData(param_1);
  *(longlong *)(param_1 + 0x1a0) = lVar7;
  *(longlong *)(lVar7 + 0x38) = param_2;
  *(longlong *)(lVar7 + 0x40) = lVar6;
  *(longlong *)(lVar7 + 0x30) = param_1;
  *(longlong *)(lVar6 + 0x30) = lVar7;
  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x40);
  lVar6 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  if (((*(undefined4 **)(param_1 + 0x38) != (undefined4 *)0x0) &&
      (bVar3 = *(byte *)(lVar6 + 2), bVar3 < 0x18)) &&
     (((0xdd0185U >> (bVar3 & 0x1f) & 1) != 0 && ((*(uint *)(lVar6 + 0xc) & 0x180000) == 0)))) {
    **(undefined4 **)(param_1 + 0x38) = 0;
  }
  (**(code **)(*(longlong *)(lVar7 + 0x20) + 0x78))(*(undefined8 *)(param_1 + 0x10),param_2);
LAB_14000a833:
  KeLowerIrql(uVar4);
  return;
}



===== WPP_SF_dddL @ 14000a868 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dddL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_61736e3ed466352ac1be56969524dc0e_Traceguids,0x15,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_sd @ 14000a8d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sd(undefined8 param_1,undefined2 param_2,undefined8 param_3,char *param_4,
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
            (param_1,0x2b,&WPP_61736e3ed466352ac1be56969524dc0e_Traceguids,param_2,param_4,lVar2,
             &param_5,4,0);
  return;
}



===== WPP_SF_sqq @ 14000a958 =====

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
            (param_1,0x2b,&WPP_61736e3ed466352ac1be56969524dc0e_Traceguids,0x18,param_4,lVar2,
             &param_5,8,&param_6,8,0);
  return;
}



===== RtlStringCbPrintfA @ 14000a9ec =====

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



===== WPP_SF_dq @ 14000aa60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,8,0);
  return;
}



===== WPP_SF_qaZ @ 14000aab4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qaZ(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               wchar_t *param_5)

{
  wchar_t wVar1;
  char *pcVar2;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    wVar1 = L'\x04';
  }
  else {
    wVar1 = *param_5;
    if (*param_5 != L'\0') {
      pcVar2 = *(char **)(param_5 + 4);
      goto LAB_14000aaea;
    }
  }
  pcVar2 = "NULL";
LAB_14000aaea:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\x04";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_976cd3c5730d3f52f58c020cb0cc6bda_Traceguids,0x16,&local_res20,8,
             param_5,2,pcVar2,wVar1,0);
  return;
}



===== WPP_SF_qqDd @ 14000ab58 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqDd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_976cd3c5730d3f52f58c020cb0cc6bda_Traceguids,10,&local_res20,8,
             &param_5,8,&param_6,4,&param_7,4,0);
  return;
}



===== SpDeviceStoppedCompletion @ 14000abd0 =====

void SpDeviceStoppedCompletion(undefined8 param_1,undefined4 param_2,undefined4 *param_3)

{
  *param_3 = param_2;
  KeSetEvent(param_3 + 2,0,0);
  return;
}



===== ScsiDebugPrint @ 14000ac00 =====

void ScsiDebugPrint(void)

{
                    /* 0xac00  2  ScsiDebugPrint */
  return;
}



===== ScsiPortCompleteRequest @ 14000ac20 =====

void ScsiPortCompleteRequest
               (longlong param_1,char param_2,char param_3,longlong *param_4,undefined1 param_5)

{
  longlong lVar1;
  undefined *puVar2;
  undefined8 *puVar3;
  char cVar4;
  longlong lVar5;
  longlong *plVar6;
  uint uVar7;
  longlong in_stack_ffffffffffffff98;
  byte in_stack_ffffffffffffffa0;
  uint local_58;
  longlong local_48;
  
                    /* 0xac20  3  ScsiPortCompleteRequest */
  lVar1 = *(longlong *)(param_1 + -8);
  plVar6 = (longlong *)0x0;
  cVar4 = (char)param_4;
  local_58 = 0;
  local_48 = lVar1 + 0x2e0;
  do {
    uVar7 = (uint)plVar6;
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      in_stack_ffffffffffffff98 = local_48;
      WPP_SF_dq(WPP_GLOBAL_Control[3],0x10,&WPP_6385d792dd11340f713c5832152029f9_Traceguids,uVar7,
                (char)local_48);
      param_4 = plVar6;
    }
    lVar5 = *(longlong *)(local_48 + 8);
    if (lVar5 != 0) {
      do {
        if ((((param_2 == -1) || (param_2 == *(char *)(lVar5 + 0x154))) &&
            ((param_3 == -1 || (param_3 == *(char *)(lVar5 + 0x155))))) &&
           ((cVar4 == -1 || (cVar4 == *(char *)(lVar5 + 0x156))))) {
          if (*(longlong *)(lVar5 + 0x1c0) != 0) {
            *(undefined1 *)(*(longlong *)(lVar5 + 0x1c0) + 3) = param_5;
            ScsiPortNotification
                      (0,param_1,*(undefined **)(lVar5 + 0x1c0),param_4,
                       (byte)in_stack_ffffffffffffff98,in_stack_ffffffffffffffa0);
          }
          if (((*(longlong *)(lVar5 + 0x1f0) != 0) &&
              (puVar2 = *(undefined **)(*(longlong *)(lVar5 + 0x1f0) + 0x40),
              puVar2 != (undefined *)0x0)) && ((*(uint *)(puVar2 + 0xc) & 0x10000) != 0)) {
            *(undefined4 *)(puVar2 + 0x10) = 0;
            puVar2[3] = param_5;
            ScsiPortNotification
                      (0,*(longlong *)(lVar1 + 0x148),puVar2,param_4,(byte)in_stack_ffffffffffffff98
                       ,in_stack_ffffffffffffffa0);
          }
          for (puVar3 = *(undefined8 **)(lVar5 + 0x1d0); puVar3 != (undefined8 *)(lVar5 + 0x1d0);
              puVar3 = (undefined8 *)*puVar3) {
            puVar2 = (undefined *)puVar3[4];
            if ((puVar2 != (undefined *)0x0) && ((*(uint *)(puVar2 + 0xc) & 0x10000) != 0)) {
              *(undefined4 *)(puVar2 + 0x10) = 0;
              puVar2[3] = param_5;
              ScsiPortNotification
                        (0,*(longlong *)(lVar1 + 0x148),puVar2,param_4,
                         (byte)in_stack_ffffffffffffff98,in_stack_ffffffffffffffa0);
            }
          }
        }
        lVar5 = *(longlong *)(lVar5 + 0x1a8);
      } while (lVar5 != 0);
      uVar7 = local_58;
    }
    local_58 = uVar7 + 1;
    plVar6 = (longlong *)(ulonglong)local_58;
    local_48 = local_48 + 0x10;
  } while (local_58 < 8);
  return;
}



===== ScsiPortConvertPhysicalAddressToUlong @ 14000ae00 =====

undefined4 ScsiPortConvertPhysicalAddressToUlong(undefined4 param_1)

{
                    /* 0xae00  4  ScsiPortConvertPhysicalAddressToUlong */
  return param_1;
}



===== ScsiPortConvertUlongToPhysicalAddress @ 14000ae10 =====

undefined8 ScsiPortConvertUlongToPhysicalAddress(undefined8 param_1)

{
                    /* 0xae10  5  ScsiPortConvertUlongToPhysicalAddress */
  return param_1;
}



===== ScsiPortFlushDma @ 14000ae20 =====

void ScsiPortFlushDma(longlong param_1)

{
  longlong *plVar1;
  uint uVar2;
  
                    /* 0xae20  6  ScsiPortFlushDma */
  plVar1 = *(longlong **)(param_1 + -8);
  if (Sp64BitPhysicalAddresses != 0) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x2c,0,0xffffffffc00000bb,param_1,*(undefined8 *)(*plVar1 + 8));
  }
  uVar2 = *(uint *)(plVar1 + 0x6d);
  if ((uVar2 & 0x20) == 0) {
    uVar2 = uVar2 | 0x14;
  }
  else {
    uVar2 = uVar2 & 0xffffffdf;
  }
  *(uint *)(plVar1 + 0x6d) = uVar2;
  return;
}



===== ScsiPortGetLogicalUnit @ 14000ae80 =====

longlong ScsiPortGetLogicalUnit(longlong param_1,char param_2,undefined *param_3,byte param_4)

{
  longlong *plVar1;
  longlong lVar2;
  undefined *puVar3;
  
                    /* 0xae80  10  ScsiPortGetLogicalUnit */
  puVar3 = param_3;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    puVar3 = &WPP_6385d792dd11340f713c5832152029f9_Traceguids;
    WPP_SF_D(WPP_GLOBAL_Control[3],10,&WPP_6385d792dd11340f713c5832152029f9_Traceguids,
             (uint)param_3 & 0xff);
  }
  plVar1 = GetLogicalUnitExtension
                     (*(longlong *)(param_1 + -8),param_2,
                      (uint)CONCAT71((int7)((ulonglong)puVar3 >> 8),(char)param_3),param_4,0,'\0');
  lVar2 = 0;
  if (plVar1 != (longlong *)0x0) {
    lVar2 = plVar1[0x2c];
  }
  return lVar2;
}



===== ScsiPortGetPhysicalAddress @ 14000af20 =====

longlong ScsiPortGetPhysicalAddress(longlong param_1,longlong param_2,longlong param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  uint uVar5;
  
                    /* 0xaf20  11  ScsiPortGetPhysicalAddress */
  lVar3 = *(longlong *)(param_1 + -8);
  iVar2 = 0;
  if ((param_2 == 0) ||
     ((*(longlong *)(param_2 + 0x20) != 0 && (*(longlong *)(param_2 + 0x20) == param_3)))) {
    uVar5 = (int)param_3 - *(int *)(lVar3 + 0x228);
    iVar2 = *(int *)(lVar3 + 0x210) - uVar5;
    lVar3 = (ulonglong)uVar5 + *(longlong *)(lVar3 + 0x480);
  }
  else {
    if (*(char *)(lVar3 + 0x48a) != '\0') {
      uVar5 = (int)param_3 - *(int *)(param_2 + 0x18);
      for (plVar4 = *(longlong **)(*(longlong *)(param_2 + 0x30) + 0xa8);
          (uVar1 = *(uint *)(plVar4 + 1), uVar1 != 0 && (uVar1 <= uVar5)); plVar4 = plVar4 + 3) {
        uVar5 = uVar5 - uVar1;
      }
      if (uVar5 <= *(uint *)(plVar4 + 1)) {
        iVar2 = *(uint *)(plVar4 + 1) - uVar5;
        lVar3 = (ulonglong)uVar5 + *plVar4;
        goto LAB_14000afa0;
      }
    }
    lVar3 = 0xffffffff;
  }
LAB_14000afa0:
  *param_4 = iVar2;
  return lVar3;
}



===== ScsiPortGetSrb @ 14000afb0 =====

longlong ScsiPortGetSrb(longlong param_1,char param_2,uint param_3,byte param_4,char param_5)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  
                    /* 0xafb0  12  ScsiPortGetSrb */
  plVar2 = GetLogicalUnitExtension(*(longlong *)(param_1 + -8),param_2,param_3,param_4,0,'\0');
  if (plVar2 != (longlong *)0x0) {
    if (param_5 == -1) {
      plVar4 = (longlong *)plVar2[0x3e];
LAB_14000afdf:
      if (((plVar4 != (longlong *)0x0) && (lVar1 = plVar4[8], lVar1 != 0)) &&
         ((*(uint *)(lVar1 + 0xc) & 0x10000) != 0)) {
        return lVar1;
      }
    }
    else {
      for (plVar3 = (longlong *)plVar2[0x3a]; plVar3 != plVar2 + 0x3a; plVar3 = (longlong *)*plVar3)
      {
        plVar4 = plVar3 + -4;
        if (*(char *)(plVar3[4] + 8) == param_5) goto LAB_14000afdf;
      }
    }
  }
  return 0;
}



===== ScsiPortGetVirtualAddress @ 14000b030 =====

longlong ScsiPortGetVirtualAddress(longlong param_1,uint param_2)

{
  uint uVar1;
  longlong lVar2;
  
                    /* 0xb030  14  ScsiPortGetVirtualAddress */
  lVar2 = *(longlong *)(param_1 + -8);
  uVar1 = *(uint *)(lVar2 + 0x480);
  if ((param_2 < uVar1) || (*(int *)(lVar2 + 0x210) + uVar1 <= param_2)) {
    return 0;
  }
  return (ulonglong)(param_2 - uVar1) + *(longlong *)(lVar2 + 0x228);
}



===== ScsiPortIoMapTransfer @ 14000b070 =====

void ScsiPortIoMapTransfer(longlong param_1,longlong param_2,longlong param_3,undefined4 param_4)

{
  undefined4 uVar1;
  longlong *plVar2;
  
                    /* 0xb070  16  ScsiPortIoMapTransfer */
  plVar2 = *(longlong **)(param_1 + -8);
  if (Sp64BitPhysicalAddresses != 0) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x2c,1,0xffffffffc00000bb,param_1,*(undefined8 *)(*plVar2 + 8));
  }
  if (plVar2[0x3a] != 0) {
    plVar2[0x6f] = *(longlong *)(param_2 + 0x30);
    plVar2[0x71] = param_3;
    *(undefined4 *)(plVar2 + 0x72) = param_4;
    uVar1 = *(undefined4 *)(param_2 + 0xc);
    *(uint *)(plVar2 + 0x6d) = *(uint *)(plVar2 + 0x6d) | 0x24;
    *(undefined4 *)(plVar2 + 0x70) = uVar1;
  }
  return;
}



===== ScsiPortLogError @ 14000b0f0 =====

void ScsiPortLogError(longlong param_1,longlong param_2,undefined1 param_3,undefined1 param_4,
                     undefined1 param_5,undefined4 param_6,undefined4 param_7)

{
  longlong lVar1;
  longlong lVar2;
  
                    /* 0xb0f0  17  ScsiPortLogError */
  lVar1 = *(longlong *)(param_1 + -8);
  if ((*(uint *)(lVar1 + 0x368) & 0x40) == 0) {
    *(undefined4 *)(lVar1 + 0x39c) = param_6;
    *(undefined1 *)(lVar1 + 0x39b) = param_5;
    *(undefined4 *)(lVar1 + 0x3a0) = param_7;
    *(undefined1 *)(lVar1 + 0x39a) = param_4;
    *(undefined1 *)(lVar1 + 0x399) = param_3;
    if (param_2 == 0) {
      *(undefined4 *)(lVar1 + 0x3a8) = 0;
      *(undefined4 *)(lVar1 + 0x3a4) = 0;
    }
    else {
      lVar2 = *(longlong *)(param_2 + 0x30);
      *(undefined4 *)(lVar1 + 0x3a8) = *(undefined4 *)(lVar2 + 0x54);
      *(undefined4 *)(lVar1 + 0x3a4) = *(undefined4 *)(lVar2 + 0x50);
      *(int *)(lVar2 + 0x50) = *(int *)(lVar2 + 0x50) + 1;
    }
    *(uint *)(lVar1 + 0x368) = *(uint *)(lVar1 + 0x368) | 0x44;
  }
  return;
}



===== ScsiPortMoveMemory @ 14000b170 =====

void ScsiPortMoveMemory(undefined4 *param_1,longlong param_2,uint param_3)

{
  longlong lVar1;
  uint uVar2;
  
                    /* 0xb170  18  ScsiPortMoveMemory */
  if (((param_3 & 3) == 0) && ((((byte)param_1 | (byte)param_2) & 3) == 0)) {
    uVar2 = param_3 >> 2;
    if (uVar2 != 0) {
      lVar1 = param_2 - (longlong)param_1;
      do {
        *param_1 = *(undefined4 *)(lVar1 + (longlong)param_1);
        param_1 = param_1 + 1;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
      return;
    }
  }
  else if (param_3 != 0) {
    lVar1 = param_2 - (longlong)param_1;
    do {
      *(undefined1 *)param_1 = *(undefined1 *)(lVar1 + (longlong)param_1);
      param_1 = (undefined4 *)((longlong)param_1 + 1);
      param_3 = param_3 - 1;
    } while (param_3 != 0);
  }
  return;
}



===== ScsiPortNotification @ 14000b1c0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ScsiPortNotification
               (int param_1,longlong param_2,undefined *param_3,longlong *param_4,byte param_5,
               byte param_6)

{
  uint uVar1;
  longlong *plVar2;
  longlong lVar3;
  void *_Dst;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  byte bVar7;
  undefined7 uVar8;
  size_t _Size;
  byte bVar9;
  longlong lVar10;
  int local_res18;
  undefined4 local_res20;
  
                    /* 0xb1c0  19  ScsiPortNotification */
  if (param_2 == 0) {
    lVar6 = 0;
  }
  else {
    lVar6 = *(longlong *)(param_2 + -8);
  }
  local_res18._0_1_ = (byte)param_3;
  local_res20._0_1_ = (byte)param_4;
  if (param_1 < 7) {
    if (param_1 == 6) {
      *(uint *)(lVar6 + 0x368) = *(uint *)(lVar6 + 0x368) | 0x10000;
      *(undefined **)(lVar6 + 0x3c0) = param_3;
      local_res20 = SUB84(param_4,0);
      *(undefined4 *)(lVar6 + 0x3c8) = local_res20;
    }
    else {
      uVar8 = (undefined7)((ulonglong)param_3 >> 8);
      if (param_1 == 0) {
        if ((*(uint *)(param_3 + 0xc) >> 0x10 & 1) == 0) {
          return;
        }
        *(uint *)(param_3 + 0xc) = *(uint *)(param_3 + 0xc) & 0xfffeffff;
        if (param_3[2] == '\x10') {
          plVar2 = GetLogicalUnitExtension
                             (lVar6,param_3[5],(uint)CONCAT71(uVar8,param_3[6]),param_3[7],0,'\0');
          plVar2[0x37] = *(longlong *)(lVar6 + 0x3b8);
          *(longlong **)(lVar6 + 0x3b8) = plVar2;
        }
        else {
          lVar3 = *(longlong *)(param_3 + 0x30);
          if ((SpLunIoLogActive == '\x01') && (param_3[2] == '\0')) {
            lVar5 = *(longlong *)(lVar3 + 0x30);
            uVar1 = *(uint *)(lVar5 + 0x1054);
            lVar10 = (ulonglong)uVar1 * 0x30;
            *(undefined4 *)(lVar10 + 0x1088 + lVar5) = *(undefined4 *)(lVar3 + 0x90);
            *(undefined *)(lVar10 + 0x105c + lVar5) = param_3[3];
            *(undefined *)(lVar10 + 0x105d + lVar5) = param_3[4];
            *(undefined *)(lVar10 + 0x105e + lVar5) = param_3[10];
            *(undefined *)(lVar10 + 0x105f + lVar5) = param_3[8];
            *(undefined *)(lVar10 + 0x1082 + lVar5) = param_3[0xb];
            *(undefined4 *)(lVar10 + 0x1084 + lVar5) = *(undefined4 *)(param_3 + 0x40);
            memcpy((void *)(lVar5 + 0x1060 + lVar10),param_3 + 0x48,(ulonglong)(byte)param_3[10]);
            if (*(char *)(lVar10 + 0x105c + lVar5) < '\0') {
              _Size = 0x12;
              if ((byte)param_3[0xb] < 0x13) {
                _Size = (size_t)(byte)param_3[0xb];
              }
              memcpy((void *)(lVar5 + 0x1070 + lVar10),*(void **)(param_3 + 0x20),_Size);
            }
            iVar4 = 0;
            if (uVar1 != 9) {
              iVar4 = uVar1 + 1;
            }
            *(int *)(lVar5 + 0x1054) = iVar4;
            if (*(uint *)(lVar5 + 0x1058) < 10) {
              *(uint *)(lVar5 + 0x1058) = *(uint *)(lVar5 + 0x1058) + 1;
            }
          }
          if ((((param_3[3] == '\x05') && ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)
               ) && ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
             (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_q(WPP_GLOBAL_Control[3],0xc,&WPP_6385d792dd11340f713c5832152029f9_Traceguids,
                     param_3);
          }
          *(undefined8 *)(lVar3 + 0x48) = *(undefined8 *)(lVar6 + 0x370);
          *(longlong *)(lVar6 + 0x370) = lVar3;
          *(undefined8 *)(lVar6 + 0x360) = *(undefined8 *)(lVar3 + 0x30);
        }
      }
      else if (param_1 == 1) {
        *(uint *)(lVar6 + 0x368) = *(uint *)(lVar6 + 0x368) | 8;
      }
      else if (param_1 == 2) {
        *(uint *)(lVar6 + 0x368) = *(uint *)(lVar6 + 0x368) | 8;
        plVar2 = *(longlong **)(lVar6 + 0x360);
        if (((((plVar2 != (longlong *)0x0) &&
              (*(byte *)((longlong)plVar2 + 0x155) == (byte)local_res20)) &&
             ((*(byte *)((longlong)plVar2 + 0x154) == (byte)local_res18 &&
              (*(byte *)((longlong)plVar2 + 0x156) == param_5)))) ||
            (plVar2 = GetLogicalUnitExtension
                                (lVar6,(byte)local_res18,(uint)CONCAT71(uVar8,(byte)local_res20),
                                 param_5,0,'\0'), plVar2 != (longlong *)0x0)) &&
           ((plVar2[0x36] == 0 && (plVar2[0x3e] == 0)))) {
          plVar2[0x36] = *(longlong *)(lVar6 + 0x3b0);
          *(longlong **)(lVar6 + 0x3b0) = plVar2;
        }
      }
      else if (param_1 == 3) {
        *(uint *)(lVar6 + 0x368) = *(uint *)(lVar6 + 0x368) | 0x280;
      }
      else {
        if (param_1 == 4) {
          *(uint *)(lVar6 + 0x17c) = *(uint *)(lVar6 + 0x17c) | 0x2000;
        }
        else {
          if (param_1 != 5) goto LAB_14000b759;
          *(uint *)(lVar6 + 0x368) = *(uint *)(lVar6 + 0x368) | 0xc000;
        }
        if (*(longlong *)(lVar6 + 0x760) != 0) {
          *(undefined **)(*(longlong *)(lVar6 + 0x760) + 0x30) = param_3;
          param_3 = SpHwRequestInterruptVrfy;
        }
        *(undefined **)(lVar6 + 0x2a8) = param_3;
      }
    }
LAB_14000b759:
    if (lVar6 != 0) {
      *(uint *)(lVar6 + 0x368) = *(uint *)(lVar6 + 0x368) | 4;
    }
    return;
  }
  if (param_1 == 7) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_q(WPP_GLOBAL_Control[3],0xe,&WPP_6385d792dd11340f713c5832152029f9_Traceguids,lVar6);
    }
    *(uint *)(lVar6 + 0x368) = *(uint *)(lVar6 + 0x368) | 0x40000;
    goto LAB_14000b759;
  }
  bVar7 = 0;
  bVar9 = 0;
  if (param_1 == 8) {
    if ((byte)local_res20 != 0xff) {
      bVar7 = param_5;
      bVar9 = param_6;
    }
    if (param_3 == (undefined *)0x0) {
      return;
    }
    if (0x80 < *(uint *)param_3) {
      return;
    }
    _Dst = (void *)SpWmiPopFreeRequestItem(lVar6);
    if (_Dst != (void *)0x0) {
      *(uint *)(lVar6 + 0x368) = *(uint *)(lVar6 + 0x368) | 0x20000;
      *(undefined1 *)((longlong)_Dst + 0x80) = 8;
      *(byte *)((longlong)_Dst + 0x81) = (byte)local_res20;
      if ((byte)local_res20 != 0xff) {
        *(byte *)((longlong)_Dst + 0x82) = bVar7;
        *(byte *)((longlong)_Dst + 0x83) = bVar9;
      }
      memcpy(_Dst,param_3,(ulonglong)*(uint *)param_3);
      *(undefined8 *)((longlong)_Dst + 0x88) = 0;
      lVar3 = *(longlong *)(lVar6 + 0x3d0);
      if (lVar3 == 0) {
        *(void **)(lVar6 + 0x3d0) = _Dst;
      }
      else {
        for (lVar5 = *(longlong *)(lVar3 + 0x88); lVar5 != 0; lVar5 = *(longlong *)(lVar5 + 0x88)) {
          lVar3 = lVar5;
        }
        *(void **)(lVar3 + 0x88) = _Dst;
      }
      goto LAB_14000b759;
    }
    if (*(char *)(lVar6 + 0x4c1) != '\0') {
      return;
    }
    *(undefined1 *)(lVar6 + 0x4c1) = 1;
    if ((byte)local_res20 != 0xff) {
      local_res18._0_1_ = (byte)local_res20;
      goto LAB_14000b69a;
    }
  }
  else {
    if (param_1 != 9) {
      if (param_1 == 0xc) {
        *(undefined8 *)param_3 = _DAT_fffff78000000320;
      }
      else {
        if (param_1 == 0xd) {
                    /* WARNING: Subroutine does not return */
          KeBugCheckEx(0xf7,0,0,0,0);
        }
        if (param_1 == 0xe) {
          local_res18 = (int)param_3;
          SpHandleTraceNotifyType(1,local_res18,param_4);
        }
      }
      goto LAB_14000b759;
    }
    if ((byte)local_res18 != 0xff) {
      bVar7 = (byte)local_res20;
      bVar9 = param_5;
    }
    lVar3 = SpWmiPopFreeRequestItem(lVar6);
    if (lVar3 != 0) {
      *(uint *)(lVar6 + 0x368) = *(uint *)(lVar6 + 0x368) | 0x20000;
      *(undefined1 *)(lVar3 + 0x80) = 9;
      *(byte *)(lVar3 + 0x81) = (byte)local_res18;
      if ((byte)local_res18 != 0xff) {
        *(byte *)(lVar3 + 0x82) = bVar7;
        *(byte *)(lVar3 + 0x83) = bVar9;
      }
      *(undefined8 *)(lVar3 + 0x88) = 0;
      lVar5 = *(longlong *)(lVar6 + 0x3d0);
      if (lVar5 == 0) {
        *(longlong *)(lVar6 + 0x3d0) = lVar3;
      }
      else {
        for (lVar10 = *(longlong *)(lVar5 + 0x88); lVar10 != 0;
            lVar10 = *(longlong *)(lVar10 + 0x88)) {
          lVar5 = lVar10;
        }
        *(longlong *)(lVar5 + 0x88) = lVar3;
      }
      goto LAB_14000b759;
    }
    if (*(char *)(lVar6 + 0x4c1) != '\0') {
      return;
    }
    *(undefined1 *)(lVar6 + 0x4c1) = 1;
    if ((byte)local_res18 != 0xff) goto LAB_14000b69a;
  }
  bVar9 = 0;
  bVar7 = 0;
  local_res18._0_1_ = 0xff;
LAB_14000b69a:
  ScsiPortLogError(param_2,0,(byte)local_res18,bVar7,bVar9,0xb,0);
  return;
}



===== ScsiPortQuerySystemTime @ 14000b780 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ScsiPortQuerySystemTime(undefined8 *param_1)

{
                    /* 0xb780  20  ScsiPortQuerySystemTime */
  *param_1 = _DAT_fffff78000000014;
  return;
}



===== ScsiPortReadPortBufferUchar @ 14000b7a0 =====

void ScsiPortReadPortBufferUchar(undefined2 param_1,undefined1 *param_2,uint param_3)

{
  undefined1 uVar1;
  ulonglong uVar2;
  
                    /* 0xb7a0  21  ScsiPortReadPortBufferUchar */
  uVar2 = (ulonglong)param_3;
  while (uVar2 != 0) {
    uVar2 = uVar2 - 1;
    uVar1 = in(param_1);
    *param_2 = uVar1;
    param_2 = param_2 + 1;
  }
  return;
}



===== ScsiPortReadPortBufferUlong @ 14000b7c0 =====

void ScsiPortReadPortBufferUlong(undefined2 param_1,undefined4 *param_2,uint param_3)

{
  undefined4 uVar1;
  ulonglong uVar2;
  
                    /* 0xb7c0  22  ScsiPortReadPortBufferUlong */
  uVar2 = (ulonglong)param_3;
  while (uVar2 != 0) {
    uVar2 = uVar2 - 1;
    uVar1 = in(param_1);
    *param_2 = uVar1;
    param_2 = param_2 + 1;
  }
  return;
}



===== ScsiPortReadPortBufferUshort @ 14000b7e0 =====

void ScsiPortReadPortBufferUshort(undefined2 param_1,undefined2 *param_2,uint param_3)

{
  undefined2 uVar1;
  ulonglong uVar2;
  
                    /* 0xb7e0  23  ScsiPortReadPortBufferUshort */
  uVar2 = (ulonglong)param_3;
  while (uVar2 != 0) {
    uVar2 = uVar2 - 1;
    uVar1 = in(param_1);
    *param_2 = uVar1;
    param_2 = param_2 + 1;
  }
  return;
}



===== ScsiPortReadPortUchar @ 14000b800 =====

undefined1 ScsiPortReadPortUchar(undefined2 param_1)

{
  undefined1 uVar1;
  
  uVar1 = in(param_1);
  return uVar1;
}



===== ScsiPortReadPortUlong @ 14000b810 =====

undefined4 ScsiPortReadPortUlong(undefined2 param_1)

{
  undefined4 uVar1;
  
  uVar1 = in(param_1);
  return uVar1;
}



===== ScsiPortReadPortUshort @ 14000b820 =====

undefined2 ScsiPortReadPortUshort(undefined2 param_1)

{
  undefined2 uVar1;
  
  uVar1 = in(param_1);
  return uVar1;
}



===== ScsiPortReadRegisterBufferUchar @ 14000b840 =====

void ScsiPortReadRegisterBufferUchar(undefined1 *param_1,undefined1 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0xb840  27  ScsiPortReadRegisterBufferUchar */
  for (uVar1 = (ulonglong)param_3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_2 = *param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return;
}



===== ScsiPortReadRegisterBufferUlong @ 14000b870 =====

void ScsiPortReadRegisterBufferUlong(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0xb870  28  ScsiPortReadRegisterBufferUlong */
  for (uVar1 = (ulonglong)param_3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_2 = *param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return;
}



===== ScsiPortReadRegisterBufferUshort @ 14000b8a0 =====

void ScsiPortReadRegisterBufferUshort(undefined2 *param_1,undefined2 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0xb8a0  29  ScsiPortReadRegisterBufferUshort */
  for (uVar1 = (ulonglong)param_3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_2 = *param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return;
}



===== ScsiPortReadRegisterUchar @ 14000b8d0 =====

undefined1 ScsiPortReadRegisterUchar(undefined1 *param_1)

{
  return *param_1;
}



===== ScsiPortReadRegisterUlong @ 14000b8e0 =====

undefined4 ScsiPortReadRegisterUlong(undefined4 *param_1)

{
  return *param_1;
}



===== ScsiPortReadRegisterUshort @ 14000b8f0 =====

undefined2 ScsiPortReadRegisterUshort(undefined2 *param_1)

{
  return *param_1;
}



===== ScsiPortStallExecution @ 14000b900 =====

void ScsiPortStallExecution(void)

{
                    /* 0xb900  34  ScsiPortStallExecution */
  KeStallExecutionProcessor();
  return;
}



===== ScsiPortValidateRange @ 14000b920 =====

undefined1 ScsiPortValidateRange(void)

{
                    /* 0xb920  35  ScsiPortValidateRange */
  return 1;
}



===== ScsiPortWritePortBufferUchar @ 14000b930 =====

void ScsiPortWritePortBufferUchar(undefined2 param_1,undefined1 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0xb930  36  ScsiPortWritePortBufferUchar */
  uVar1 = (ulonglong)param_3;
  while (uVar1 != 0) {
    uVar1 = uVar1 - 1;
    out(*param_2,param_1);
    param_2 = param_2 + 1;
  }
  return;
}



===== ScsiPortWritePortBufferUlong @ 14000b950 =====

void ScsiPortWritePortBufferUlong(undefined2 param_1,undefined4 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0xb950  37  ScsiPortWritePortBufferUlong */
  uVar1 = (ulonglong)param_3;
  while (uVar1 != 0) {
    uVar1 = uVar1 - 1;
    out(*param_2,param_1);
    param_2 = param_2 + 1;
  }
  return;
}



===== ScsiPortWritePortBufferUshort @ 14000b970 =====

void ScsiPortWritePortBufferUshort(undefined2 param_1,undefined2 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0xb970  38  ScsiPortWritePortBufferUshort */
  uVar1 = (ulonglong)param_3;
  while (uVar1 != 0) {
    uVar1 = uVar1 - 1;
    out(*param_2,param_1);
    param_2 = param_2 + 1;
  }
  return;
}



===== ScsiPortWritePortUchar @ 14000b990 =====

undefined1 ScsiPortWritePortUchar(undefined2 param_1,undefined1 param_2)

{
                    /* 0xb990  39  ScsiPortWritePortUchar */
  out(param_1,param_2);
  return param_2;
}



===== ScsiPortWritePortUlong @ 14000b9a0 =====

undefined4 ScsiPortWritePortUlong(undefined2 param_1,undefined4 param_2)

{
                    /* 0xb9a0  40  ScsiPortWritePortUlong */
  out(param_1,param_2);
  return param_2;
}



===== ScsiPortWritePortUshort @ 14000b9b0 =====

undefined2 ScsiPortWritePortUshort(undefined2 param_1,undefined2 param_2)

{
                    /* 0xb9b0  41  ScsiPortWritePortUshort */
  out(param_1,param_2);
  return param_2;
}



===== ScsiPortWriteRegisterBufferUchar @ 14000b9d0 =====

void ScsiPortWriteRegisterBufferUchar(undefined1 *param_1,undefined1 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0xb9d0  42  ScsiPortWriteRegisterBufferUchar */
  for (uVar1 = (ulonglong)param_3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  LOCK();
  UNLOCK();
  return;
}



===== ScsiPortWriteRegisterBufferUlong @ 14000ba00 =====

void ScsiPortWriteRegisterBufferUlong(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0xba00  43  ScsiPortWriteRegisterBufferUlong */
  for (uVar1 = (ulonglong)param_3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  LOCK();
  UNLOCK();
  return;
}



===== ScsiPortWriteRegisterBufferUshort @ 14000ba30 =====

void ScsiPortWriteRegisterBufferUshort(undefined2 *param_1,undefined2 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0xba30  44  ScsiPortWriteRegisterBufferUshort */
  for (uVar1 = (ulonglong)param_3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  LOCK();
  UNLOCK();
  return;
}



===== ScsiPortWriteRegisterUchar @ 14000ba60 =====

void ScsiPortWriteRegisterUchar(undefined1 *param_1,undefined1 param_2)

{
                    /* 0xba60  45  ScsiPortWriteRegisterUchar */
  *param_1 = param_2;
  LOCK();
  UNLOCK();
  return;
}



===== ScsiPortWriteRegisterUlong @ 14000ba70 =====

void ScsiPortWriteRegisterUlong(undefined4 *param_1,undefined4 param_2)

{
                    /* 0xba70  46  ScsiPortWriteRegisterUlong */
  *param_1 = param_2;
  LOCK();
  UNLOCK();
  return;
}



===== ScsiPortWriteRegisterUshort @ 14000ba80 =====

void ScsiPortWriteRegisterUshort(undefined2 *param_1,undefined2 param_2)

{
                    /* 0xba80  47  ScsiPortWriteRegisterUshort */
  *param_1 = param_2;
  LOCK();
  UNLOCK();
  return;
}



===== ScsiPortDispatchPower @ 14000ba90 =====

ulonglong ScsiPortDispatchPower(longlong param_1,longlong param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  char *pcVar9;
  uint uVar10;
  byte bVar11;
  
  lVar4 = *(longlong *)(param_1 + 0x40);
  lVar5 = *(longlong *)(param_2 + 0xb8);
  uVar10 = *(uint *)(param_2 + 0x30);
  bVar11 = *(byte *)(lVar4 + 8) & 1;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
     (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    pcVar9 = "pdo";
    if (bVar11 == 0) {
      pcVar9 = "fdo";
    }
    uVar7 = (ulonglong)*(byte *)(lVar5 + 1);
    if (4 < *(byte *)(lVar5 + 1)) {
      uVar7 = 4;
    }
    WPP_SF_qssq(WPP_GLOBAL_Control[3],pcVar9,&PowerMinorStrings,param_2,(&PowerMinorStrings)[uVar7],
                pcVar9,(char)param_1);
  }
  cVar1 = *(char *)(lVar5 + 1);
  if (cVar1 == '\0') {
    if (bVar11 == 0) {
      PoStartNextPowerIrp(param_2);
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      uVar10 = PoCallDriver(*(undefined8 *)(lVar4 + 0x10),param_2);
      goto LAB_14000be04;
    }
    uVar10 = 0xc0000010;
  }
  else if (cVar1 == '\x02') {
    iVar2 = *(int *)(lVar5 + 0x10);
    iVar3 = *(int *)(lVar5 + 0x18);
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
       (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_DD(WPP_GLOBAL_Control[3],0xb,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,iVar2,
                (char)iVar3);
    }
    DbgPrint("ScsiPortDispatchPower: %p(%x) SET_POWER type %d state %d\n",param_1,bVar11,iVar2,iVar3
            );
    if (iVar3 != 1) {
      PoSetPowerState(param_1,iVar2,iVar3);
    }
    if ((iVar2 == 0) && (5 < iVar3)) {
      if (bVar11 != 0) {
        DbgPrint("Test %p\n",param_1);
        goto LAB_14000bcf2;
      }
      if ((*(byte *)(lVar4 + 0x168) & 0x40) == 0) goto LAB_14000bd03;
LAB_14000bd78:
      if (((*(byte *)(*(longlong *)(param_1 + 0x40) + 0x168) & 0x10) != 0) && (iVar3 != 1))
      goto LAB_14000bcf2;
      uVar8 = SpSetAdapterPower(param_1,param_2);
      uVar10 = (uint)uVar8;
    }
    else {
      if (bVar11 == 0) goto LAB_14000bd78;
      if (iVar2 == 1) {
        uVar8 = SpSetTargetDeviceState(param_1,param_2,iVar3);
        uVar10 = (uint)uVar8;
      }
      else {
        uVar8 = SpSetTargetSystemState(param_1,param_2,iVar3);
        uVar10 = (uint)uVar8;
      }
    }
    if (uVar10 == 0x103) {
      return 0x103;
    }
  }
  else {
    if (cVar1 != '\x03') {
      if (bVar11 == 0) {
        PoStartNextPowerIrp(param_2);
        *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
        *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
        goto LAB_14000bd3e;
      }
      goto LAB_14000bdb6;
    }
    iVar2 = *(int *)(lVar5 + 0x10);
    iVar3 = *(int *)(lVar5 + 0x18);
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
       (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_DD(WPP_GLOBAL_Control[3],0xc,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,iVar2,
                (char)iVar3);
    }
    if ((iVar2 == 0) && (5 < iVar3)) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
         (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_D(WPP_GLOBAL_Control[3],0xd,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,iVar3);
      }
      if (bVar11 == 0) {
LAB_14000bd03:
        PoStartNextPowerIrp(param_2);
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
LAB_14000bd3e:
        uVar7 = PoCallDriver(*(undefined8 *)(lVar4 + 0x10),param_2);
        return uVar7;
      }
    }
    else if (bVar11 == 0) {
      if (((*(byte *)(lVar4 + 0x168) & 0x10) == 0) &&
         (((lVar5 = *(longlong *)(param_1 + 0x40), *(longlong *)(lVar5 + 0x2b8) != 0 &&
           ((*(byte *)(lVar5 + 0x168) & 4) != 0)) ||
          ((*(char *)(lVar5 + 9) != '\0' && (*(char *)(lVar5 + 10) != '\0')))))) goto LAB_14000bd03;
      uVar10 = 0xc00000bb;
      goto LAB_14000bdb6;
    }
LAB_14000bcf2:
    uVar10 = 0;
  }
LAB_14000bdb6:
  PoStartNextPowerIrp(param_2);
  *(uint *)(param_2 + 0x30) = uVar10;
  IofCompleteRequest(param_2,0);
LAB_14000be04:
  return (ulonglong)uVar10;
}



===== SpPowerAdapterForTargetCompletion @ 14000be30 =====

void SpPowerAdapterForTargetCompletion
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
               int *param_5)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  
  lVar1 = *(longlong *)(param_4 + 0xb8);
  iVar2 = *param_5;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qqL(WPP_GLOBAL_Control[3],0xf,param_3,param_1,(char)param_4,(char)iVar2);
  }
  if (-1 < iVar2) {
    uVar3 = SpSetTargetDeviceState(*(longlong *)(lVar1 + 0x28),param_4,1);
    iVar2 = (int)uVar3;
  }
  if (iVar2 != 0x103) {
    PoStartNextPowerIrp(param_4);
    *(int *)(param_4 + 0x30) = iVar2;
    IofCompleteRequest(param_4,0);
  }
  return;
}



===== SpProcessAdapterDeviceState @ 14000bee4 =====

void SpProcessAdapterDeviceState(longlong param_1,longlong param_2,undefined *param_3)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  int iVar6;
  longlong lVar7;
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  plVar4 = *(longlong **)(param_1 + 0x40);
  iVar6 = 0;
  uVar1 = *(uint *)(lVar3 + 0x18);
  lVar7 = param_2;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    lVar7 = 0;
    param_3 = &WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids;
    WPP_SF_qqd(WPP_GLOBAL_Control[3],0x1c,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,param_1,
               (char)param_2,(char)uVar1);
  }
  uVar2 = *(uint *)((longlong)plVar4 + 0x2c);
  if (((uVar2 == 1) || (uVar1 == 1)) && (uVar2 != uVar1)) {
    iVar6 = SpEnableDisableAdapter
                      (plVar4,(char *)CONCAT71((int7)((ulonglong)lVar7 >> 8),uVar1 == 1),param_3,
                       (longlong *)(ulonglong)uVar2);
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_D(WPP_GLOBAL_Control[3],0x1e,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,iVar6);
    }
    if (iVar6 < 0) goto LAB_14000bfe7;
  }
  else if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
          (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_DD(WPP_GLOBAL_Control[3],0x1d,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,uVar2,
              (char)uVar1);
  }
  *(uint *)((longlong)plVar4 + 0x2c) = uVar1;
LAB_14000bfe7:
  IoStartNextPacket(param_1,0);
  *(int *)(param_2 + 0x30) = iVar6;
  PoStartNextPowerIrp(param_2);
  if (*(int *)(lVar3 + 0x18) == 1) {
    IofCompleteRequest(param_2,0);
  }
  else {
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
    PoCallDriver(plVar4[2],param_2);
  }
  if ((-1 < iVar6) && (uVar1 == 1)) {
    if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0 &&
        (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
      WPP_SF_q(WPP_GLOBAL_Control[3],0x1f,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,
               plVar4[0x28]);
    }
    IoInvalidateDeviceRelations(plVar4[0x28],0);
  }
  return;
}



===== SpProcessAdapterSystemState @ 14000c0dc =====

void SpProcessAdapterSystemState
               (longlong *param_1,longlong param_2,undefined *param_3,longlong *param_4)

{
  int iVar1;
  int iVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  int iVar5;
  undefined2 uVar6;
  longlong lVar7;
  undefined4 uVar8;
  longlong *plVar9;
  
  plVar3 = (longlong *)param_1[8];
  iVar1 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  iVar5 = 0;
  uVar8 = 0;
  lVar7 = param_2;
  plVar9 = plVar3;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    lVar7 = 0;
    param_3 = &WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids;
    param_4 = param_1;
    WPP_SF_qqd(WPP_GLOBAL_Control[3],0x16,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,param_1,
               (char)param_2,(char)iVar1);
  }
  iVar2 = (int)plVar3[5];
  if (((iVar2 == 1) || (iVar1 == 1)) && (iVar2 != iVar1)) {
    *(int *)(plVar3 + 5) = iVar1;
    if (iVar1 == 1) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        lVar7 = 0;
        param_4 = (longlong *)(ulonglong)*(uint *)((longlong)plVar3 + 0x2c);
        param_3 = &WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids;
        WPP_SF_D(WPP_GLOBAL_Control[3],0x1a,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,
                 *(uint *)((longlong)plVar3 + 0x2c));
      }
      iVar5 = SpEnableDisableAdapter
                        (plVar3,(char *)CONCAT71((int7)((ulonglong)lVar7 >> 8),1),param_3,param_4);
      if ((((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) == 0)) ||
         (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 4)) goto LAB_14000c2d1;
      uVar6 = 0x1b;
    }
    else {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_D(WPP_GLOBAL_Control[3],0x18,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,iVar1);
      }
      iVar5 = PoRequestPowerIrp(param_1,2,4,SpRequestAdapterPowerCompletion,param_2,0,uVar8,plVar9);
      if ((((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) == 0)) ||
         (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 4)) goto LAB_14000c2d1;
      uVar6 = 0x19;
    }
    WPP_SF_D(WPP_GLOBAL_Control[3],uVar6,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,iVar5);
  }
  else {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_DD(WPP_GLOBAL_Control[3],0x17,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,iVar2,
                (char)iVar1);
    }
    *(int *)(plVar3 + 5) = iVar1;
  }
LAB_14000c2d1:
  IoStartNextPacket(param_1,0);
  if (iVar5 != 0x103) {
    if (iVar5 < 0) {
      *(int *)(plVar3 + 5) = iVar2;
    }
    PoStartNextPowerIrp(param_2);
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
    PoCallDriver(plVar3[2],param_2);
  }
  return;
}



===== SpRequestAdapterPowerCompletion @ 14000c360 =====

void SpRequestAdapterPowerCompletion
               (longlong param_1,undefined8 param_2,undefined *param_3,longlong *param_4,
               int *param_5)

{
  int iVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  int iVar4;
  longlong *plVar5;
  char *pcVar6;
  
  plVar2 = *(longlong **)(param_1 + 0x40);
  iVar1 = *(int *)(param_4[0x17] + 0x18);
  iVar4 = *param_5;
  plVar5 = param_4;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    plVar5 = plVar2;
    WPP_SF_qqdL(WPP_GLOBAL_Control[3],param_2,param_3,plVar2,(char)param_4,(char)param_3,(char)iVar4
               );
  }
  *(int *)(param_4 + 6) = *param_5;
  if (-1 < iVar4) {
    iVar4 = SpEnableDisableAdapter
                      (plVar2,(char *)CONCAT71((int7)((ulonglong)param_2 >> 8),iVar1 == 1),param_3,
                       plVar5);
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      pcVar6 = "Enable";
      if (iVar1 != 1) {
        pcVar6 = "Disable";
      }
      WPP_SF_sL(WPP_GLOBAL_Control[3],0x21,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,pcVar6,
                (char)iVar4);
    }
    if ((-1 < iVar4) && (iVar1 == 1)) {
      PoSetPowerState(param_1,0,1);
    }
  }
  puVar3 = (undefined8 *)param_4[0x17];
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
  PoStartNextPowerIrp(param_4);
  PoCallDriver(plVar2[2],param_4);
  return;
}



===== SpRequestValidPowerState @ 14000c4c8 =====

undefined8 SpRequestValidPowerState(undefined8 param_1,undefined8 *param_2,longlong param_3)

{
  undefined8 uVar1;
  
  if (((byte)(*(char *)(param_3 + 2) - 0x18U) < 2) ||
     ((*(int *)((longlong)param_2 + 0x2c) == 1 &&
      ((*(int *)(param_2 + 5) == 1 || ((*(uint *)(param_3 + 0xc) & 0x80000) != 0)))))) {
    uVar1 = 0;
  }
  else {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
       (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_dddqddq(WPP_GLOBAL_Control[3],(ulonglong)*(byte *)(param_3 + 7),
                     (ulonglong)*(byte *)(param_3 + 6),(uint)*(byte *)(param_3 + 5),
                     *(byte *)(param_3 + 6),*(byte *)(param_3 + 7),(char)*param_2,
                     (char)*(int *)((longlong)param_2 + 0x2c),(char)*(undefined4 *)(param_2 + 5),
                     (char)*(undefined8 *)(*(longlong *)(param_3 + 0x30) + 0x38));
    }
    uVar1 = *(undefined8 *)(param_3 + 0x30);
    *(uint *)(param_2 + 0x28) = *(uint *)(param_2 + 0x28) | 0x22;
    param_2[0x3c] = uVar1;
    if (*(int *)(param_2 + 5) == 1) {
      if (*(int *)(param_2 + 6) != 1) {
        if ((undefined4 *)param_2[7] != (undefined4 *)0x0) {
          *(undefined4 *)param_2[7] = 0;
        }
        PoRequestPowerIrp(*param_2,2,1,0,0,0);
      }
    }
    else {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_D(WPP_GLOBAL_Control[3],0x11,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,
                 *(int *)(param_2 + 5));
      }
      *(undefined4 *)(param_2 + 6) = 1;
    }
    uVar1 = 0x103;
  }
  return uVar1;
}



===== SpSetAdapterPower @ 14000c61c =====

undefined8 SpSetAdapterPower(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  longlong lVar2;
  undefined8 *puVar3;
  char cVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_(WPP_GLOBAL_Control[3],0xe,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids);
  }
  cVar4 = RtlAreBitsSet(lVar2 + 0x2c8,1,1);
  if (cVar4 == '\0') {
    if ((*(char *)(lVar2 + 9) == '\0') || (*(char *)(lVar2 + 10) == '\0')) {
      *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
      return 0xc00000bb;
    }
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
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
    PoStartNextPowerIrp(param_2);
    PoCallDriver(*(undefined8 *)(lVar2 + 0x10),param_2);
  }
  else {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    IoStartPacket(param_1,param_2,0,0);
  }
  return 0x103;
}



===== SpSetLowerPowerCompletion @ 14000c740 =====

undefined8 SpSetLowerPowerCompletion(longlong *param_1,longlong param_2,char *param_3)

{
  int iVar1;
  undefined1 uVar2;
  char *pcVar3;
  uint uVar4;
  undefined8 uVar5;
  longlong *plVar6;
  
  iVar1 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  uVar5 = 0;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    param_3 = "Device";
    pcVar3 = "System";
    uVar4 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18) - 1;
    if (iVar1 != 0) {
      pcVar3 = "Device";
    }
    WPP_SF_qqsd(WPP_GLOBAL_Control[3],(ulonglong)uVar4,"Device",param_1,(char)param_2,pcVar3,
                (char)uVar4);
  }
  uVar2 = KfRaiseIrql(2);
  uVar4 = *(uint *)(param_2 + 0x30);
  plVar6 = (longlong *)(ulonglong)uVar4;
  if ((int)uVar4 < 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_D(WPP_GLOBAL_Control[3],0x15,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,uVar4);
    }
    PoStartNextPowerIrp(param_2);
    IoStartNextPacket(param_1,0);
  }
  else {
    if (iVar1 == 0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        param_3 = &WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids;
        WPP_SF_(WPP_GLOBAL_Control[3],0x13,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids);
      }
      SpProcessAdapterSystemState(param_1,param_2,param_3,plVar6);
    }
    else {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        param_3 = &WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids;
        WPP_SF_(WPP_GLOBAL_Control[3],0x14,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids);
      }
      SpProcessAdapterDeviceState((longlong)param_1,param_2,param_3);
    }
    uVar5 = 0xc0000016;
  }
  KeLowerIrql(uVar2);
  return uVar5;
}



===== SpSetTargetDesiredPowerCompletion @ 14000c8e0 =====

void SpSetTargetDesiredPowerCompletion(longlong param_1)

{
  longlong lVar1;
  undefined4 *in_stack_00000028;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
     (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_D(WPP_GLOBAL_Control[3],0x22,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,
             *in_stack_00000028);
  }
  *(undefined4 *)(lVar1 + 0x30) = 0;
  return;
}



===== SpSetTargetDeviceState @ 14000c938 =====

undefined8 SpSetTargetDeviceState(longlong param_1,longlong param_2,int param_3)

{
  byte *pbVar1;
  int iVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  
  plVar3 = *(longlong **)(param_1 + 0x40);
  lVar4 = *(longlong *)(param_2 + 0xb8);
  puVar5 = (undefined8 *)plVar3[0x2d];
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
     (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qq(WPP_GLOBAL_Control[3],0x26,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,param_1,
              (char)param_2);
  }
  iVar2 = *(int *)((longlong)plVar3 + 0x2c);
  if (((iVar2 == 1) || (param_3 == 1)) && (iVar2 != param_3)) {
    if ((param_3 == 1) && (*(int *)((longlong)puVar5 + 0x2c) != 1)) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_q(WPP_GLOBAL_Control[3],0x28,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,puVar5)
        ;
      }
      *(longlong *)(lVar4 + 0x28) = param_1;
      uVar6 = PoRequestPowerIrp(*puVar5,2,1,SpPowerAdapterForTargetCompletion,param_2,0);
    }
    else {
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      SpEnableDisableLogicalUnit(plVar3,'\0',SpSetTargetDeviceStateLockedCompletion,param_2);
      uVar6 = 0x103;
    }
  }
  else {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
       (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_DD(WPP_GLOBAL_Control[3],0x27,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,iVar2,
                (char)param_3);
    }
    *(int *)((longlong)plVar3 + 0x2c) = param_3;
    uVar6 = 0;
  }
  return uVar6;
}



===== SpSetTargetDeviceStateForSystemStateCompletion @ 14000cab0 =====

void SpSetTargetDeviceStateForSystemStateCompletion
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
               undefined4 *param_5)

{
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qqL(WPP_GLOBAL_Control[3],0x30,param_3,param_1,(char)param_4,(char)*param_5);
  }
  *(undefined4 *)(param_4 + 0x30) = *param_5;
  PoStartNextPowerIrp(param_4);
  IofCompleteRequest(param_4,0);
  return;
}



===== SpSetTargetDeviceStateLockedCompletion @ 14000cb40 =====

void SpSetTargetDeviceStateLockedCompletion(longlong param_1,int param_2,longlong param_3)

{
  int iVar1;
  longlong *plVar2;
  longlong lVar3;
  
  plVar2 = *(longlong **)(param_1 + 0x40);
  lVar3 = *(longlong *)(param_3 + 0xb8);
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
     (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qqL(WPP_GLOBAL_Control[3],0x23,param_3,param_1,(char)param_3,(char)param_2);
  }
  if (param_2 < 0) {
    *(int *)(param_3 + 0x30) = param_2;
    PoStartNextPowerIrp(param_3);
    IofCompleteRequest(param_3,0);
  }
  else {
    iVar1 = *(int *)(lVar3 + 0x18);
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
       (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_DD(WPP_GLOBAL_Control[3],0x24,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,
                *(undefined4 *)((longlong)plVar2 + 0x2c),(char)iVar1);
    }
    SpAdjustDisabledBit((longlong)plVar2,iVar1 == 1);
    *(int *)((longlong)plVar2 + 0x2c) = iVar1;
    SpEnableDisableLogicalUnit(plVar2,'\x01',SpSetTargetDeviceStateUnlockedCompletion,param_3);
  }
  return;
}



===== SpSetTargetDeviceStateUnlockedCompletion @ 14000cc50 =====

void SpSetTargetDeviceStateUnlockedCompletion(undefined8 param_1,int param_2,longlong param_3)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_3 + 0xb8);
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
     (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qqL(WPP_GLOBAL_Control[3],0x25,param_3,param_1,(char)param_3,(char)param_2);
  }
  if ((-1 < param_2) && (*(int *)(lVar1 + 0x18) == 1)) {
    PoSetPowerState(param_1,1,*(undefined4 *)(lVar1 + 0x18));
  }
  *(int *)(param_3 + 0x30) = param_2;
  PoStartNextPowerIrp(param_3);
  IofCompleteRequest(param_3,0);
  return;
}



===== SpSetTargetSystemState @ 14000cd0c =====

undefined8 SpSetTargetSystemState(longlong param_1,longlong param_2,int param_3)

{
  byte *pbVar1;
  int iVar2;
  longlong *plVar3;
  undefined8 uVar4;
  
  plVar3 = *(longlong **)(param_1 + 0x40);
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qq(WPP_GLOBAL_Control[3],0x29,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,param_1,
              (char)param_2);
  }
  iVar2 = (int)plVar3[5];
  if (((iVar2 == 1) || (param_3 == 1)) && (iVar2 != param_3)) {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    SpEnableDisableLogicalUnit(plVar3,'\0',SpSetTargetSystemStateLockedCompletion,param_2);
    uVar4 = 0x103;
  }
  else {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_DD(WPP_GLOBAL_Control[3],0x2a,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,iVar2,
                (char)param_3);
    }
    *(int *)(plVar3 + 5) = param_3;
    uVar4 = 0;
  }
  return uVar4;
}



===== SpSetTargetSystemStateLockedCompletion @ 14000ce00 =====

void SpSetTargetSystemStateLockedCompletion(longlong param_1,int param_2,longlong param_3)

{
  int iVar1;
  longlong *plVar2;
  
  plVar2 = *(longlong **)(param_1 + 0x40);
  iVar1 = *(int *)(*(longlong *)(param_3 + 0xb8) + 0x18);
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qLq(WPP_GLOBAL_Control[3],0x2b,param_3,param_1,(char)param_2,(char)param_3);
  }
  if (param_2 < 0) {
    *(int *)(param_3 + 0x30) = param_2;
    PoStartNextPowerIrp(param_3);
    IofCompleteRequest(param_3,0);
  }
  else {
    SpAdjustDisabledBit((longlong)plVar2,iVar1 == 1);
    *(int *)(plVar2 + 5) = iVar1;
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_DD(WPP_GLOBAL_Control[3],0x2c,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,iVar1,
                (char)plVar2[6]);
    }
    SpEnableDisableLogicalUnit(plVar2,'\x01',SpSetTargetSystemStateUnlockedCompletion,param_3);
  }
  return;
}



===== SpSetTargetSystemStateUnlockedCompletion @ 14000cf10 =====

void SpSetTargetSystemStateUnlockedCompletion(longlong param_1,int param_2,longlong param_3)

{
  longlong lVar1;
  int iVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  iVar2 = *(int *)(*(longlong *)(param_3 + 0xb8) + 0x18);
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qLq(WPP_GLOBAL_Control[3],0x2d,param_3,param_1,(char)param_2,(char)param_3);
  }
  if (-1 < param_2) {
    if (iVar2 != 1) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_(WPP_GLOBAL_Control[3],0x2f,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids);
      }
      iVar2 = PoRequestPowerIrp(param_1,2,4,SpSetTargetDeviceStateForSystemStateCompletion,param_3,0
                               );
      if (-1 < iVar2) {
        return;
      }
      *(int *)(param_3 + 0x30) = iVar2;
      goto LAB_14000d077;
    }
    PoSetPowerState(param_1,0);
    iVar2 = *(int *)(lVar1 + 0x30);
    if (iVar2 != 0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_D(WPP_GLOBAL_Control[3],0x2e,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,iVar2);
      }
      param_2 = PoRequestPowerIrp(param_1,2,iVar2,SpSetTargetDesiredPowerCompletion,0,0);
    }
    if (param_2 == 0x103) {
      param_2 = 0;
    }
  }
  *(int *)(param_3 + 0x30) = param_2;
LAB_14000d077:
  PoStartNextPowerIrp(param_3);
  IofCompleteRequest(param_3,0);
  return;
}



===== SpSignalPowerCompletion @ 14000d0c0 =====

void SpSignalPowerCompletion(void)

{
  undefined4 *in_R9;
  undefined4 *in_stack_00000028;
  
  *in_R9 = *in_stack_00000028;
  KeSetEvent(in_R9 + 2,0,0);
  return;
}



===== WPP_SF_dddqddq @ 14000d0f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dddqddq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                   undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                   undefined1 param_9,undefined1 param_10)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,0x10,local_res20,4,
             &param_5,4,&param_6,4,&param_7,8,&param_8,4,&param_9,4,&param_10,8,0);
  return;
}



===== WPP_SF_qLq @ 14000d190 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qLq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,param_2,&local_res20,8,
             &param_5,4,&param_6,8,0);
  return;
}



===== WPP_SF_qqL @ 14000d1f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqL(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,param_2,&local_res20,8,
             &param_5,8,&param_6,4,0);
  return;
}



===== WPP_SF_qqdL @ 14000d260 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqdL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,0x20,&local_res20,8,
             &param_5,8,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_qqsd @ 14000d2d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqsd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,char *param_6,undefined1 param_7)

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
            (param_1,0x2b,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,0x12,&local_res20,8,
             &param_5,8,pcVar3,lVar2,&param_7,4,0);
  return;
}



===== WPP_SF_qssq @ 14000d38c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qssq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
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
            (param_1,0x2b,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,10,&local_res20,8,param_5
             ,lVar3,param_6,lVar2,&param_7,8,0);
  return;
}



===== Feature_851677496__private_IsEnabledDeviceUsageNoInline @ 14000d474 =====

ulonglong Feature_851677496__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_851677496__private_featureState;
  if ((Feature_851677496__private_featureState & 0x10) == 0) {
    uVar1 = Feature_851677496__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_851677496__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_851677496__private_IsEnabledFallback @ 14000d4ac =====

void Feature_851677496__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 14000d4c4 =====

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
LAB_14000d6cd:
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
LAB_14000d59f:
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
      if (param_3 == 4) goto LAB_14000d6cd;
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
        goto LAB_14000d59f;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 14000d7b8 =====

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
      goto LAB_14000d87b;
    }
    if (param_3 == 2) {
      uVar2 = (uVar4 ^ 1) * 4 + 1;
      uVar3 = 0;
      goto LAB_14000d87b;
    }
    if (param_3 == 3) {
      uVar2 = (uVar4 ^ 1) * 4 + 2;
      uVar3 = 0;
      goto LAB_14000d87b;
    }
    if (param_3 == 4) {
      uVar2 = (uVar4 ^ 1) * 4 + 3;
      uVar3 = 0;
      goto LAB_14000d87b;
    }
    uVar2 = param_3 - 5;
    uVar3 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      uVar2 = (uVar4 ^ 1) * 2 + 8;
      goto LAB_14000d87b;
    }
    if (uVar2 == 1) {
      uVar2 = (uVar4 ^ 1) * 2 + 9;
      goto LAB_14000d87b;
    }
    bVar5 = (char)param_3 + 0x9c;
    if (bVar5 < 0x32) {
      uVar2 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar5;
      goto LAB_14000d87b;
    }
  }
  uVar2 = 0xff;
LAB_14000d87b:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x3b8ee52,&Feature_851677496_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 14000d8d4 =====

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
                     (local_50,&Feature_851677496__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)(0x3b8ee52,param_3,1,&Feature_851677496__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)param_3,0x3b8ee52);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 14000d9c0 =====

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
LAB_14000da73:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_14000daa1;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_14000da73;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_14000daa1:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 14000dc2c =====

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
  if ((Feature_851677496__private_featureState & 2) != 0) {
    uVar1 = Feature_851677496__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_851677496__private_featureState;
      if (bVar3) {
        Feature_851677496__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_851677496__private_featureState;
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



===== wil_details_IsEnabledFallback @ 14000dc80 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_851677496__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_851677496__private_featureState,(ulonglong)param_1,0x1400168a0
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



===== SpDestroyAdapter @ 14000dd10 =====

void SpDestroyAdapter(longlong *param_1,char param_2)

{
  SpReleaseAdapterResources(param_1,'\0',param_2);
  SpAdapterCleanup((longlong)param_1);
  return;
}



===== SpFlushAllRequests @ 14000dd38 =====

void SpFlushAllRequests(longlong param_1,char param_2,char param_3,char param_4,undefined1 param_5)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined *puVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  uint local_res8;
  longlong *local_48;
  
  plVar1 = *(longlong **)(param_1 + -8);
  lVar6 = 0;
  local_res8 = 0;
  local_48 = plVar1 + 0x5c;
  do {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_dq(WPP_GLOBAL_Control[3],0xe,&WPP_0e590514a8bd32470b453596a0a5c27f_Traceguids,
                local_res8,(char)local_48);
    }
    for (plVar2 = (longlong *)local_48[1]; plVar2 != (longlong *)0x0;
        plVar2 = (longlong *)plVar2[0x35]) {
      if ((((param_2 == -1) || (param_2 == *(char *)((longlong)plVar2 + 0x154))) &&
          ((param_3 == -1 || (param_3 == *(char *)((longlong)plVar2 + 0x155))))) &&
         ((param_4 == -1 || (param_4 == *(char *)((longlong)plVar2 + 0x156))))) {
        while (lVar4 = KeRemoveByKeyDeviceQueueIfBusy(*plVar2 + 0xa0,0), lVar4 != 0) {
          *(undefined1 *)(*(longlong *)(*(longlong *)(lVar4 + 0x40) + 8) + 3) = param_5;
          *(longlong *)(lVar4 + 0x30) = lVar6;
          *(undefined4 *)(lVar4 + -0x48) = 0xc0000001;
          lVar6 = lVar4 + -0x78;
        }
        lVar4 = plVar2[0x3c];
        lVar5 = lVar6;
        if (lVar4 != 0) {
          lVar5 = *(longlong *)(lVar4 + 0x38);
          lVar4 = *(longlong *)(lVar4 + 0x40);
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_qq(WPP_GLOBAL_Control[3],0xf,&WPP_0e590514a8bd32470b453596a0a5c27f_Traceguids,
                      lVar5,(char)lVar4);
          }
          *(undefined1 *)(lVar4 + 3) = param_5;
          *(longlong *)(lVar5 + 0xa8) = lVar6;
          *(undefined4 *)(lVar5 + 0x30) = 0xc0000001;
          plVar2[0x3c] = 0;
          *(uint *)(plVar2 + 0x28) = *(uint *)(plVar2 + 0x28) & 0xffffffdf;
        }
        lVar4 = plVar2[0x3d];
        lVar6 = lVar5;
        if (lVar4 != 0) {
          lVar6 = *(longlong *)(lVar4 + 0x38);
          lVar4 = *(longlong *)(lVar4 + 0x40);
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_qq(WPP_GLOBAL_Control[3],0x10,&WPP_0e590514a8bd32470b453596a0a5c27f_Traceguids,
                      lVar6,(char)lVar4);
          }
          *(undefined1 *)(lVar4 + 3) = param_5;
          *(longlong *)(lVar6 + 0xa8) = lVar5;
          *(undefined4 *)(lVar6 + 0x30) = 0xc0000001;
          plVar2[0x3d] = 0;
          *(uint *)(plVar2 + 0x28) = *(uint *)(plVar2 + 0x28) & 0xffffffe7;
        }
      }
    }
    local_res8 = local_res8 + 1;
    local_48 = local_48 + 2;
  } while (local_res8 < 8);
  KeReleaseSpinLockFromDpcLevel(plVar1 + 0x36);
  while (lVar6 != 0) {
    lVar4 = *(longlong *)(lVar6 + 0xa8);
    lVar5 = *(longlong *)(*(longlong *)(lVar6 + 0xb8) + 8);
    puVar3 = *(undefined **)(lVar5 + 0x30);
    *(longlong *)(lVar5 + 0x30) = lVar6;
    lVar5 = *plVar1;
    SpReleaseRemoveLock(lVar5,(char)lVar6);
    SpCompleteRequest(lVar5,lVar6,puVar3,0);
    lVar6 = lVar4;
  }
  return;
}



===== SpFlushLogicalUnitRequests @ 14000dff8 =====

void SpFlushLogicalUnitRequests(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  
  lVar2 = *(longlong *)(param_1 + 0x168);
  uVar3 = KfRaiseIrql(2);
  lVar1 = lVar2 + 0x1b0;
  KeAcquireSpinLockAtDpcLevel(lVar1);
  lVar2 = *(longlong *)(lVar2 + 0x148);
  if (lVar2 == 0) {
    KeReleaseSpinLockFromDpcLevel(lVar1);
  }
  else {
    SpFlushAllRequests(lVar2,*(char *)(param_1 + 0x154),*(char *)(param_1 + 0x155),
                       *(char *)(param_1 + 0x156),8);
  }
  KeLowerIrql(uVar3);
  return;
}



===== SpReleaseAdapterResources @ 14000e0a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SpReleaseAdapterResources(longlong *param_1,char param_2,char param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  byte bVar4;
  
  if (*(longlong *)(*param_1 + 0x28) != 0) {
    IoStopTimer();
    KeCancelTimer(param_1 + 0x80);
  }
  if ((code *)param_1[0x34] != SpSynchronizeExecution) {
    if (param_1[0x32] != 0) {
      IoDisconnectInterrupt();
    }
    if (param_1[0x33] != 0) {
      IoDisconnectInterrupt();
      param_1[0x33] = 0;
    }
    param_1[0x32] = (longlong)param_1;
    param_1[0x34] = (longlong)SpSynchronizeExecution;
  }
  if (param_1[0x29] != 0) {
    ExFreePoolWithTag(param_1[0x29] + -8,0);
    param_1[0x29] = 0;
  }
  if (param_1[0x3f] != 0) {
    ExFreePoolWithTag(param_1[0x3f],0);
    param_1[0x3f] = 0;
  }
  SpWmiDestroySpRegInfo(*param_1);
  if (param_1[0xec] == 0) {
    bVar4 = 0;
  }
  else {
    bVar4 = (byte)*(undefined4 *)(param_1[0xec] + 100) & 1;
  }
  if (bVar4 == 0) {
    lVar1 = param_1[0x45];
    if ((lVar1 != 0) && ((int)param_1[0x42] != 0)) {
      lVar2 = param_1[0x3a];
      if (lVar2 == 0) {
        ExFreePoolWithTag(lVar1,0);
      }
      else if ((char)param_1[0x43] == '\0') {
        MmFreeContiguousMemorySpecifyCache(lVar1);
      }
      else {
        (**(code **)(*(longlong *)(lVar2 + 8) + 0x18))
                  (lVar2,(int)param_1[0x42],param_1[0x90],lVar1,0);
      }
      param_1[0x45] = 0;
    }
  }
  else {
    SpFreeCommonBufferVrfy((longlong)param_1);
  }
  if (param_1[0x3a] != 0) {
    (**(code **)(*(longlong *)(param_1[0x3a] + 8) + 8))();
    param_1[0x3a] = 0;
  }
  if ((param_3 == '\0') && ((char)param_1[0xcc] != '\0')) {
    if (param_1[0xcb] != 0) {
      ExFreeToNPagedLookasideList(param_1 + 0xb8);
      param_1[0xcb] = 0;
    }
    ExDeleteNPagedLookasideList(param_1 + 0xb8);
    *(undefined1 *)(param_1 + 0xcc) = 0;
  }
  if (param_2 == '\0') {
    if (param_1[0xdd] != 0) {
      ExFreePoolWithTag(param_1[0xdd],0);
      param_1[0xdd] = 0;
    }
    if (param_1[0xde] != 0) {
      ExFreePoolWithTag(param_1[0xde],0);
      param_1[0xde] = 0;
    }
    if (param_1[0xdf] != 0) {
      IoFreeIrp();
      param_1[0xdf] = 0;
    }
    if (param_1[0xe0] != 0) {
      IoFreeMdl();
      param_1[0xe0] = 0;
    }
  }
  SpReleaseMappedAddresses((longlong)param_1);
  if (param_1[0x40] != 0) {
    ExFreePoolWithTag(param_1[0x40],0);
    param_1[0x40] = 0;
  }
  if (param_1[0x41] != 0) {
    ExFreePoolWithTag(param_1[0x41],0);
    param_1[0x41] = 0;
  }
  if (param_1[0xec] != 0) {
    ExFreePoolWithTag(param_1[0xec],0);
    uVar3 = VerifierCodeSectionHandle;
    param_1[0xec] = 0;
    MmUnlockPagableImageSection(uVar3);
  }
  if (param_1[0xef] != 0) {
    MmFreeMappingAddress(param_1[0xef],0x6d506353);
    param_1[0xef] = 0;
  }
  if (param_1[0xf0] != 0) {
    IoFreeMdl();
    param_1[0xf0] = 0;
  }
  *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) & 0xfd;
  return;
}



===== SpRemoveAdapterSynchronized @ 14000e410 =====

undefined1 SpRemoveAdapterSynchronized(longlong param_1)

{
  *(uint *)(param_1 + 0x368) = *(uint *)(param_1 + 0x368) | 0x80000;
  return 1;
}



===== SpTerminateAdapter @ 14000e424 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SpTerminateAdapter(longlong *param_1)

{
  undefined1 uVar1;
  
  uVar1 = KfRaiseIrql(2);
  KeAcquireSpinLockAtDpcLevel(param_1 + 0x36);
  if (*(char *)((longlong)param_1 + 9) == '\0') {
    (*(code *)param_1[0x34])(param_1[0x32],SpTerminateAdapterSynchronized,param_1);
    *(undefined1 *)((longlong)param_1 + 10) = 0xff;
    SpFlushAllRequests(param_1[0x29],-1,-1,-1,0x11);
    KeCancelTimer(param_1 + 0x80);
    *(undefined4 *)(param_1 + 0x31) = 1;
    ScsiPortTickHandler(*param_1);
  }
  else {
    KeReleaseSpinLockFromDpcLevel(param_1 + 0x36);
  }
  KeLowerIrql(uVar1);
  return;
}



===== SpTerminateAdapterSynchronized @ 14000e500 =====

undefined8
SpTerminateAdapterSynchronized
          (longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint *puVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined *puVar5;
  undefined1 uVar6;
  undefined7 uVar7;
  byte bVar8;
  byte in_stack_fffffffffffffff0;
  
  uVar7 = (undefined7)((ulonglong)param_4 >> 8);
  *(uint *)(param_1 + 0x6d) = *(uint *)(param_1 + 0x6d) | 0x80000;
  uVar6 = 0xff;
  bVar8 = 0x11;
  puVar5 = (undefined *)CONCAT71((int7)((ulonglong)param_3 >> 8),0xff);
  ScsiPortCompleteRequest(param_1[0x29],-1,-1,(longlong *)CONCAT71(uVar7,0xff),0x11);
  ScsiPortNotification
            (1,param_1[0x29],puVar5,(longlong *)CONCAT71(uVar7,uVar6),bVar8,
             in_stack_fffffffffffffff0);
  uVar4 = (ulonglong)*(uint *)(param_1 + 0x6d);
  if ((*(uint *)(param_1 + 0x6d) & 4) != 0) {
    lVar3 = *param_1;
    LOCK();
    puVar1 = (uint *)(*(longlong *)(lVar3 + 0x40) + 0x180);
    uVar2 = *puVar1;
    *puVar1 = 0x20004;
    UNLOCK();
    if ((uVar2 >> 0x11 & 1) == 0) {
      uVar4 = KeInsertQueueDpc(lVar3 + 200,0,0);
    }
  }
  return CONCAT71((int7)(uVar4 >> 8),1);
}



===== SpAdjustDisabledBit @ 14000e588 =====

void SpAdjustDisabledBit(longlong param_1,char param_2)

{
  int iVar1;
  undefined1 uVar2;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(param_1 + 0x168) + 0x1b0);
  iVar1 = *(int *)(param_1 + 0x174);
  if (param_2 == '\0') {
    *(uint *)(param_1 + 0x140) = *(uint *)(param_1 + 0x140) | 0x80;
    *(int *)(param_1 + 0x174) = iVar1 + 1;
  }
  else if ((iVar1 == 0) || (*(int *)(param_1 + 0x174) = iVar1 + -1, iVar1 + -1 == 0)) {
    *(uint *)(param_1 + 0x140) = *(uint *)(param_1 + 0x140) & 0xffffff7f;
  }
  KeReleaseSpinLock(*(longlong *)(param_1 + 0x168) + 0x1b0,uVar2);
  return;
}



===== SpAllocateBypassSrbData @ 14000e614 =====

longlong SpAllocateBypassSrbData(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = ExpInterlockedPopEntrySList(param_1 + 0xed0);
  if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x2c,5,4,param_1 + 0x280,0);
  }
  *(undefined8 *)(lVar1 + 0x80) = *(undefined8 *)(param_1 + 0x168);
  *(code **)(lVar1 + 0x18) = SpFreeBypassSrbData;
  *(undefined4 *)(lVar1 + 0x88) = 0xff;
  *(undefined4 *)(lVar1 + 0x10) = 0x3107770;
  *(undefined4 *)(lVar1 + 0x7c) = 0x10000000;
  return lVar1;
}



===== SpAllocateErrorLogEntry @ 14000e69c =====

void SpAllocateErrorLogEntry(undefined8 param_1)

{
  IoAllocateErrorLogEntry(param_1,0x3c);
  return;
}



===== SpAllocateIrpEx @ 14000e6bc =====

longlong SpAllocateIrpEx(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4
                        ,undefined4 param_5)

{
  longlong lVar1;
  
  lVar1 = IoAllocateIrp();
  if (lVar1 == 0) {
    SpLogAllocationFailureFn(param_3,0,0,0x50524973,param_4,param_5);
  }
  return lVar1;
}



===== SpAllocateMdlEx @ 14000e720 =====

longlong SpAllocateMdlEx(void)

{
  longlong lVar1;
  undefined8 in_stack_00000030;
  undefined4 in_stack_00000038;
  undefined4 in_stack_00000040;
  
  lVar1 = IoAllocateMdl();
  if (lVar1 == 0) {
    SpLogAllocationFailureFn(in_stack_00000030,0,0,0x4c444d73,in_stack_00000038,in_stack_00000040);
  }
  return lVar1;
}



===== SpAllocatePoolEx @ 14000e780 =====

longlong SpAllocatePoolEx(undefined8 param_1,longlong param_2,undefined4 param_3,undefined8 param_4,
                         undefined4 param_5,undefined4 param_6)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_2 == 0) {
    lVar1 = 0;
  }
  else {
    lVar2 = param_2;
    lVar1 = ExAllocatePoolWithTag();
    if (lVar1 == 0) {
      SpLogAllocationFailureFn(param_4,lVar2,(int)param_2,param_3,param_5,param_6);
    }
  }
  return lVar1;
}



===== SpAllocateSrbData @ 14000e7f8 =====

longlong SpAllocateSrbData(longlong param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  code *pcVar2;
  undefined1 uVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong *plVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  longlong lVar9;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  lVar4 = ExAllocateFromNPagedLookasideList(param_1 + 0x5c0);
  if (lVar4 != 0) {
    return lVar4;
  }
  if (param_2 == 0) {
    return 0;
  }
  uVar3 = KeAcquireSpinLockRaiseToDpc();
  puVar7 = auStack_28;
  puVar8 = auStack_28;
  LOCK();
  lVar4 = *(longlong *)(param_1 + 0x658);
  *(longlong *)(param_1 + 0x658) = 0;
  UNLOCK();
  if (lVar4 != 0) goto LAB_14000e8e9;
  lVar4 = 0;
  if (param_3 == 0) {
    plVar5 = (longlong *)(param_2 + 0x78);
    plVar6 = *(longlong **)(param_1 + 0x650);
    lVar9 = 0;
    if (*plVar6 == param_1 + 0x648) {
      *plVar5 = param_1 + 0x648;
      *(longlong **)(param_2 + 0x80) = plVar6;
      *plVar6 = (longlong)plVar5;
      *(longlong **)(param_1 + 0x650) = plVar5;
      puVar8 = auStack_28;
      goto LAB_14000e8e9;
    }
LAB_14000e8cf:
    plVar6 = (longlong *)0x3;
    pcVar2 = (code *)swi(0x29);
    plVar5 = (longlong *)(*pcVar2)(3,uVar3);
    puVar7 = auStack_20;
  }
  else {
    if (*(longlong *)(param_3 + 0x1240) == 0) {
      *(undefined8 *)(param_3 + 0x1240) = *(undefined8 *)(param_1 + 0x7f0);
      *(longlong *)(param_1 + 0x7f0) = param_3;
    }
    lVar9 = param_3 + 0x1248;
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    plVar5 = (longlong *)(param_2 + 0x78);
    plVar6 = *(longlong **)(param_3 + 0x1250);
    if (*plVar6 != lVar9) goto LAB_14000e8cf;
  }
  *plVar5 = lVar9;
  plVar5[1] = (longlong)plVar6;
  *plVar6 = (longlong)plVar5;
  *(longlong **)(lVar9 + 8) = plVar5;
  puVar8 = puVar7;
LAB_14000e8e9:
  *(undefined8 *)(puVar8 + -8) = 0x14000e8f3;
  KeReleaseSpinLock(param_1 + 0x640);
  return lVar4;
}



===== SpAllocateSrbDataBackend @ 14000e920 =====

void * SpAllocateSrbDataBackend(uint param_1,int param_2,ulonglong param_3)

{
  int iVar1;
  longlong *plVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  longlong lVar5;
  void *_Dst;
  
  uVar4 = KeAcquireSpinLockRaiseToDpc(&ScsiGlobalAdapterListSpinLock);
  plVar2 = *(longlong **)(*(longlong *)(ScsiGlobalAdapterList + (param_3 & 0xffffffff) * 8) + 0x40);
  KeReleaseSpinLock(&ScsiGlobalAdapterListSpinLock,uVar4);
  lVar5 = ExpInterlockedPopEntrySList(plVar2 + 0x48);
  if ((lVar5 != 0) && (iVar1 = *(int *)(lVar5 + 8), iVar1 != -1)) {
    uVar3 = *(undefined8 *)(*plVar2 + 8);
    if (param_2 != 0) {
      _Dst = (void *)ExAllocatePoolWithTag(param_1,param_2,0x44506353);
      if (_Dst != (void *)0x0) {
        memset(_Dst,0,0x310);
        *(undefined4 *)((longlong)_Dst + 0x7c) = 0;
        *(code **)((longlong)_Dst + 0x18) = SpFreeSrbData;
        *(longlong **)((longlong)_Dst + 0x80) = plVar2;
        *(int *)((longlong)_Dst + 0x88) = iVar1;
        *(undefined4 *)((longlong)_Dst + 0x10) = 0x3107770;
        return _Dst;
      }
      SpLogAllocationFailureFn(uVar3,(ulonglong)param_1,param_2,0x44506353,0x7574696c,0x6d7);
    }
    ExpInterlockedPushEntrySList(plVar2 + 0x48,(ulonglong)(iVar1 - 1) * 0x10 + plVar2[0x4a]);
  }
  return (void *)0x0;
}



===== SpFindAddressTranslation @ 14000ea68 =====

ulonglong SpFindAddressTranslation
                    (longlong param_1,uint param_2,uint param_3,undefined1 *param_4,uint param_5,
                    char param_6,undefined8 *param_7)

{
  longlong lVar1;
  undefined8 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined8 uVar6;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;
  ulonglong uVar10;
  
  uVar10 = 0;
  uVar3 = **(uint **)(param_1 + 0x200);
  if (uVar3 != 0) {
    puVar9 = *(uint **)(param_1 + 0x200) + 4;
    do {
      if ((puVar9[-3] == param_2) && (puVar9[-2] == param_3)) {
        uVar8 = 0;
        if (*puVar9 != 0) {
          puVar7 = puVar9 + 4;
          register0x00000020 = (BADSPACEBASE *)((ulonglong)register0x00000020 & 0xffffffffffffff00);
          do {
            if ((char)puVar7[-3] == (byte)((-(param_6 != '\0') & 0xfeU) + 3)) {
              puVar5 = *(undefined1 **)(puVar7 + -2);
              register0x00000020 = (BADSPACEBASE *)puVar5;
              if (((puVar5 <= param_4) && (param_4 < puVar5 + *puVar7)) &&
                 (register0x00000020 = (BADSPACEBASE *)(param_4 + param_5),
                 register0x00000020 <= puVar5 + *puVar7)) {
                lVar1 = uVar10 * 0x24 + ((ulonglong)uVar8 + 1) * 0x14;
                puVar2 = (undefined8 *)(lVar1 + *(longlong *)(param_1 + 0x208));
                uVar6 = puVar2[1];
                uVar4 = *(undefined4 *)(lVar1 + 0x10 + *(longlong *)(param_1 + 0x208));
                *param_7 = *puVar2;
                param_7[1] = uVar6;
                *(undefined4 *)(param_7 + 2) = uVar4;
                *(longlong *)((longlong)param_7 + 4) =
                     (longlong)(param_4 + (*(longlong *)((longlong)param_7 + 4) - (longlong)puVar5))
                ;
                return CONCAT71((int7)((ulonglong)uVar8 + 1 >> 8),1);
              }
            }
            uVar8 = uVar8 + 1;
            puVar7 = puVar7 + 5;
          } while (uVar8 < *puVar9);
        }
      }
      uVar8 = (int)uVar10 + 1;
      uVar10 = (ulonglong)uVar8;
      puVar9 = puVar9 + 9;
    } while (uVar8 < uVar3);
  }
  return (ulonglong)register0x00000020 & 0xffffffffffffff00;
}



===== SpFreeBypassSrbData @ 14000eb70 =====

void SpFreeBypassSrbData(undefined8 param_1,void *param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)((longlong)param_2 + 0x30);
  memset(param_2,0,0x310);
  ExpInterlockedPushEntrySList(lVar1 + 0xed0,param_2);
  return;
}



===== SpFreeSrbData @ 14000ebc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

longlong SpFreeSrbData(longlong param_1,longlong param_2)

{
  int *piVar1;
  longlong *plVar2;
  int iVar3;
  longlong lVar4;
  byte bVar5;
  longlong *plVar6;
  longlong lVar7;
  longlong lVar8;
  code *pcVar9;
  undefined1 uVar10;
  bool bVar11;
  longlong lVar12;
  undefined1 *puVar13;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  puVar13 = auStack_38;
  LOCK();
  piVar1 = (int *)(param_1 + 0x790);
  iVar3 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  *(undefined4 *)(param_2 + 0x7c) = 0;
  lVar12 = 0;
  LOCK();
  lVar4 = *(longlong *)(param_1 + 0x658);
  if (lVar4 == 0) {
    *(longlong *)(param_1 + 0x658) = param_2;
  }
  else {
    lVar12 = lVar4;
  }
  UNLOCK();
  if (lVar4 == 0) {
    if (iVar3 == 0) {
      lVar4 = param_1 + 0x640;
      plVar2 = (longlong *)(param_1 + 0x648);
      do {
        uVar10 = KeAcquireSpinLockRaiseToDpc(lVar4);
        if ((longlong *)*plVar2 == plVar2) {
          bVar11 = SpTransferBlockedRequestsToAdapter(param_1);
          if (bVar11) goto LAB_14000ec3d;
LAB_14000ed02:
          lVar12 = KeReleaseSpinLock(lVar4,uVar10);
          break;
        }
LAB_14000ec3d:
        LOCK();
        lVar12 = *(longlong *)(param_1 + 0x658);
        *(longlong *)(param_1 + 0x658) = 0;
        UNLOCK();
        if (lVar12 == 0) goto LAB_14000ed02;
        plVar6 = (longlong *)*plVar2;
        if (((longlong *)plVar6[1] != plVar2) ||
           (lVar7 = *plVar6, *(longlong **)(lVar7 + 8) != plVar6)) goto LAB_14000ed16;
        *plVar2 = lVar7;
        *(longlong **)(lVar7 + 8) = plVar2;
        KeReleaseSpinLock(lVar4,uVar10);
        lVar7 = plVar6[8];
        lVar8 = *(longlong *)(lVar7 + 8);
        *(longlong *)(lVar12 + 0x40) = lVar8;
        *(longlong **)(lVar12 + 0x38) = plVar6 + -0xf;
        *(undefined8 *)(lVar12 + 0x30) = *(undefined8 *)(*(longlong *)(lVar7 + 0x28) + 0x40);
        *(longlong *)(lVar8 + 0x30) = lVar12;
        lVar12 = *(longlong *)(lVar12 + 0x30);
        lVar7 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x40);
        if ((((*(undefined4 **)(lVar12 + 0x38) != (undefined4 *)0x0) &&
             (bVar5 = *(byte *)(*(longlong *)(plVar6[8] + 8) + 2), bVar5 < 0x18)) &&
            ((0xdd0185U >> (bVar5 & 0x1f) & 1) != 0)) &&
           ((*(uint *)(*(longlong *)(plVar6[8] + 8) + 0xc) & 0x180000) == 0)) {
          **(undefined4 **)(lVar12 + 0x38) = 0;
        }
        (**(code **)(*(longlong *)(lVar7 + 0x20) + 0x78))
                  (*(undefined8 *)(lVar12 + 0x10),plVar6 + -0xf);
      } while( true );
    }
    goto LAB_14000ed30;
  }
LAB_14000ed1d:
  *(undefined8 *)(puVar13 + -8) = 0x14000ed2b;
  lVar12 = ExFreeToNPagedLookasideList(param_1 + 0x5c0);
LAB_14000ed30:
  LOCK();
  *(int *)(param_1 + 0x790) = *(int *)(param_1 + 0x790) + -1;
  UNLOCK();
  return lVar12;
LAB_14000ed16:
  pcVar9 = (code *)swi(0x29);
  (*pcVar9)(3);
  puVar13 = auStack_30;
  goto LAB_14000ed1d;
}



===== SpFreeSrbDataBackend @ 14000ed60 =====

void SpFreeSrbDataBackend(longlong param_1)

{
  ExpInterlockedPushEntrySList
            (*(longlong *)(param_1 + 0x80) + 0x240,
             (ulonglong)(*(int *)(param_1 + 0x88) - 1) * 0x10 +
             *(longlong *)(*(longlong *)(param_1 + 0x80) + 0x250));
  *(undefined2 *)(param_1 + 0x10) = 0;
  ExFreePoolWithTag(param_1,0);
  return;
}



===== SpLockUnlockQueue @ 14000edb8 =====

int SpLockUnlockQueue(longlong param_1,undefined8 param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  undefined2 *_Dst;
  longlong lVar5;
  undefined8 *puVar6;
  undefined2 uVar7;
  int unaff_EBX;
  
  lVar5 = 0;
  puVar6 = WPP_GLOBAL_Control;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    param_2 = 10;
    puVar6 = (undefined8 *)WPP_GLOBAL_Control[3];
    WPP_SF_sq(puVar6,10,&WPP_433326d8495e374ced4cf2ffd30b12d2_Traceguids,"Unlock",
              (char)*(undefined8 *)(param_1 + 0x40));
  }
  lVar4 = SpAllocateIrpEx(CONCAT71((int7)((ulonglong)puVar6 >> 8),*(char *)(param_1 + 0x4c) + '\x01'
                                  ),param_2,*(undefined8 *)(param_1 + 8),0x7574696c,0x3a4);
  if (lVar4 == 0) {
    if ((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return unaff_EBX;
    }
    if ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x200) == 0) {
      return unaff_EBX;
    }
    if (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2) {
      return unaff_EBX;
    }
    WPP_SF_(WPP_GLOBAL_Control[3],0xb,&WPP_433326d8495e374ced4cf2ffd30b12d2_Traceguids);
    return unaff_EBX;
  }
  uVar1 = *(undefined8 *)(param_1 + 8);
  _Dst = (undefined2 *)ExAllocatePoolWithTag(0,0x58,0x70506353);
  if (_Dst == (undefined2 *)0x0) {
    SpLogAllocationFailureFn(uVar1,0,0x58,0x70506353,0x7574696c,0x3b1);
    if ((((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x200) == 0)) ||
       (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2)) goto LAB_14000f058;
    uVar7 = 0xc;
  }
  else {
    uVar1 = *(undefined8 *)(param_1 + 8);
    lVar5 = ExAllocatePoolWithTag(0,0x18,0x76506353);
    if (lVar5 != 0) {
      memset(_Dst,0,0x58);
      KeInitializeEvent(lVar5,0,0);
      *_Dst = 0x58;
      *(undefined1 *)(_Dst + 1) = 0x19;
      *(longlong *)(_Dst + 0x18) = lVar4;
      *(undefined8 *)(_Dst + 0xc) = 0;
      *(undefined1 *)(_Dst + 4) = 0xff;
      *(uint *)(_Dst + 6) = *(uint *)(_Dst + 6) | 0x80000;
      lVar2 = *(longlong *)(lVar4 + 0xb8);
      *(code **)(lVar2 + -0x10) = SpSignalCompletion;
      *(longlong *)(lVar2 + -8) = lVar5;
      *(undefined1 *)(lVar2 + -0x45) = 0;
      *(undefined1 *)(lVar2 + -0x45) = 0x40;
      *(undefined1 *)(lVar2 + -0x45) = 0xc0;
      *(undefined1 *)(lVar2 + -0x45) = 0xe0;
      lVar2 = *(longlong *)(lVar4 + 0xb8);
      *(undefined2 **)(lVar2 + -0x40) = _Dst;
      *(undefined1 *)(lVar2 + -0x48) = 0xf;
      iVar3 = IofCallDriver(param_1,lVar4);
      if (iVar3 == 0x103) {
        KeWaitForSingleObject(lVar5,0,0,0,0);
      }
      goto LAB_14000f058;
    }
    SpLogAllocationFailureFn(uVar1,0,0x18,0x76506353,0x7574696c,0x3be);
    if ((((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x200) == 0)) ||
       (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2)) goto LAB_14000f058;
    uVar7 = 0xd;
  }
  WPP_SF_(WPP_GLOBAL_Control[3],uVar7,&WPP_433326d8495e374ced4cf2ffd30b12d2_Traceguids);
LAB_14000f058:
  IoFreeIrp(lVar4);
  if (_Dst != (undefined2 *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
  if (lVar5 != 0) {
    ExFreePoolWithTag(lVar5,0);
  }
  return unaff_EBX;
}



===== SpLogAllocationFailureFn @ 14000f0a0 =====

void SpLogAllocationFailureFn
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined2 uVar4;
  
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qDD(WPP_GLOBAL_Control[3],0x20,&WPP_433326d8495e374ced4cf2ffd30b12d2_Traceguids,param_1,
               (char)param_5,(char)param_6);
  }
  puVar1 = (undefined8 *)IoAllocateErrorLogEntry(param_1,0x3c);
  if (puVar1 == (undefined8 *)0x0) {
    lVar2 = IoGetDriverObjectExtension(param_1,ScsiPortInitialize);
    if (lVar2 == 0) {
      if ((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return;
      }
      if ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return;
      }
      if (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2) {
        return;
      }
      uVar4 = 0x21;
    }
    else {
      puVar1 = *(undefined8 **)(lVar2 + 0x38);
      if (puVar1 == (undefined8 *)0x0) {
        if ((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return;
        }
        if ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
          return;
        }
        if (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2) {
          return;
        }
        uVar4 = 0x22;
      }
      else {
        LOCK();
        if (puVar1 == (undefined8 *)*puVar1) {
          *puVar1 = 0;
          puVar3 = puVar1;
        }
        else {
          puVar3 = (undefined8 *)*puVar1;
        }
        UNLOCK();
        if (puVar1 == puVar3) goto LAB_14000f1dd;
        if ((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return;
        }
        if ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
          return;
        }
        if (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2) {
          return;
        }
        uVar4 = 0x23;
      }
    }
    WPP_SF_(WPP_GLOBAL_Control[3],uVar4,&WPP_433326d8495e374ced4cf2ffd30b12d2_Traceguids);
  }
  else {
LAB_14000f1dd:
    *(undefined4 *)((longlong)puVar1 + 0xc) = 0x80040038;
    *(undefined4 *)(puVar1 + 2) = 0x10;
    *(undefined4 *)(puVar1 + 3) = 0;
    *(undefined4 *)puVar1 = 0x100000;
    *(undefined4 *)((longlong)puVar1 + 0x14) = 0xc000009a;
    *(undefined2 *)((longlong)puVar1 + 4) = 0;
    *(undefined4 *)(puVar1 + 5) = param_4;
    *(undefined4 *)((longlong)puVar1 + 0x2c) = param_3;
    *(undefined4 *)(puVar1 + 6) = param_5;
    *(undefined4 *)((longlong)puVar1 + 0x34) = param_6;
    IoWriteErrorLogEntry();
  }
  return;
}



===== SpSignalCompletion @ 14000f250 =====

undefined8 SpSignalCompletion(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== SpTransferBlockedRequestsToAdapter @ 14000f27c =====

bool SpTransferBlockedRequestsToAdapter(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong *plVar8;
  
  plVar1 = (longlong *)(param_1 + 0x7f0);
  plVar8 = (longlong *)*plVar1;
  plVar5 = plVar8;
  if (plVar8 == plVar1) {
LAB_14000f32d:
    plVar7 = (longlong *)(param_1 + 0x648);
  }
  else {
    do {
      plVar6 = plVar5 + 0x249;
      plVar2 = (longlong *)*plVar6;
      if (((longlong *)plVar2[1] != plVar6) ||
         (lVar3 = *plVar2, *(longlong **)(lVar3 + 8) != plVar2)) {
LAB_14000f326:
        param_1 = 3;
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)();
        goto LAB_14000f32d;
      }
      *plVar6 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar6;
      plVar7 = (longlong *)(param_1 + 0x648);
      lVar3 = *plVar7;
      if (*(longlong **)(lVar3 + 8) != plVar7) goto LAB_14000f326;
      *plVar2 = lVar3;
      plVar2[1] = (longlong)plVar7;
      *(longlong **)(lVar3 + 8) = plVar2;
      *plVar7 = (longlong)plVar2;
      if ((longlong *)*plVar6 == plVar6) {
        if (plVar5 == (longlong *)*plVar1) {
          *plVar1 = plVar5[0x248];
          plVar5[0x248] = 0;
          plVar6 = (longlong *)*plVar1;
        }
        else {
          plVar8[0x248] = plVar5[0x248];
          plVar5[0x248] = 0;
          plVar6 = (longlong *)plVar8[0x248];
        }
      }
      else {
        plVar6 = (longlong *)plVar5[0x248];
        plVar8 = plVar5;
      }
      plVar5 = plVar6;
    } while (plVar6 != plVar1);
  }
  return (longlong *)*plVar7 != plVar7;
}



===== WPP_SF_S @ 14000f348 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_S(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4)

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
            (param_1,0x2b,&WPP_433326d8495e374ced4cf2ffd30b12d2_Traceguids,0x17,param_4,lVar1,0);
  return;
}



===== WPP_SF_Zd @ 14000f3c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Zd(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
              undefined1 param_5)

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
      goto LAB_14000f3e8;
    }
  }
  pwVar2 = L"NULL";
LAB_14000f3e8:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_433326d8495e374ced4cf2ffd30b12d2_Traceguids,0x18,param_4,2,pwVar2,
             wVar1,&param_5,4,0);
  return;
}



===== WPP_SF_sssssss @ 14000f458 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sssssss(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
                   char *param_5,char *param_6,char *param_7,char *param_8,char *param_9,
                   char *param_10)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  
  lVar1 = 5;
  if (param_10 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (param_10[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  if (param_10 == (char *)0x0) {
    param_10 = "NULL";
  }
  if (param_9 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    lVar8 = -1;
    do {
      lVar3 = lVar8;
      lVar8 = lVar3 + 1;
    } while (param_9[lVar8] != '\0');
    lVar3 = lVar3 + 2;
  }
  if (param_9 == (char *)0x0) {
    param_9 = "NULL";
  }
  if (param_8 == (char *)0x0) {
    lVar8 = 5;
  }
  else {
    lVar7 = -1;
    do {
      lVar8 = lVar7;
      lVar7 = lVar8 + 1;
    } while (param_8[lVar7] != '\0');
    lVar8 = lVar8 + 2;
  }
  if (param_8 == (char *)0x0) {
    param_8 = "NULL";
  }
  if (param_7 == (char *)0x0) {
    lVar7 = 5;
  }
  else {
    lVar6 = -1;
    do {
      lVar7 = lVar6;
      lVar6 = lVar7 + 1;
    } while (param_7[lVar6] != '\0');
    lVar7 = lVar7 + 2;
  }
  if (param_7 == (char *)0x0) {
    param_7 = "NULL";
  }
  if (param_6 == (char *)0x0) {
    lVar6 = 5;
  }
  else {
    lVar5 = -1;
    do {
      lVar6 = lVar5;
      lVar5 = lVar6 + 1;
    } while (param_6[lVar5] != '\0');
    lVar6 = lVar6 + 2;
  }
  if (param_6 == (char *)0x0) {
    param_6 = "NULL";
  }
  if (param_5 != (char *)0x0) {
    lVar5 = -1;
    do {
      lVar1 = lVar5;
      lVar5 = lVar1 + 1;
    } while (param_5[lVar5] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (param_5 == (char *)0x0) {
    param_5 = "NULL";
  }
  lVar5 = -1;
  if (param_4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar5;
      lVar5 = lVar2 + 1;
    } while (param_4[lVar5] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_433326d8495e374ced4cf2ffd30b12d2_Traceguids,0x1b,param_4,lVar2,
             param_5,lVar1,param_6,lVar6,param_7,lVar7,param_8,lVar8,param_9,lVar3,param_10,lVar4,0)
  ;
  return;
}



===== SpWmiPopFreeRequestItem @ 14000f64c =====

longlong SpWmiPopFreeRequestItem(longlong param_1)

{
  longlong lVar1;
  
  if (*(char *)(param_1 + 0x4c0) == '\0') {
    lVar1 = 0;
  }
  else {
    lVar1 = ExpInterlockedPopEntrySList(param_1 + 0x4a0);
    if (lVar1 != 0) {
      LOCK();
      *(int *)(param_1 + 0x4bc) = *(int *)(param_1 + 0x4bc) + -1;
      UNLOCK();
    }
  }
  return lVar1;
}



===== SpWmiPushFreeRequestItem @ 14000f690 =====

undefined8 SpWmiPushFreeRequestItem(longlong *param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  
  if ((char)param_1[0x98] == '\0') {
    uVar1 = 0xc0000001;
  }
  else {
    uVar1 = *(undefined8 *)(*param_1 + 8);
    lVar2 = ExAllocatePoolWithTag(0,0x90,0x77506353);
    if (lVar2 == 0) {
      SpLogAllocationFailureFn(uVar1,0,0x90,0x77506353,0x776d6920,0x600);
      uVar1 = 0xc000009a;
    }
    else {
      *(undefined8 *)(lVar2 + 0x88) = 0;
      ExpInterlockedPushEntrySList(param_1 + 0x94,lVar2);
      LOCK();
      *(int *)((longlong)param_1 + 0x4bc) = *(int *)((longlong)param_1 + 0x4bc) + 1;
      UNLOCK();
      uVar1 = 0;
    }
  }
  return uVar1;
}



===== SpWmiRemoveFreeMiniPortRequestItems @ 14000f738 =====

undefined8 SpWmiRemoveFreeMiniPortRequestItems(longlong param_1)

{
  longlong lVar1;
  
  *(undefined4 *)(param_1 + 0x4b8) = 0;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_q(WPP_GLOBAL_Control[3],0x18,&WPP_23a3c04cde1b354a8276a948161bd449_Traceguids,param_1);
  }
  while( true ) {
    lVar1 = SpWmiPopFreeRequestItem(param_1);
    if (lVar1 == 0) break;
    ExFreePoolWithTag(lVar1,0);
  }
  return 1;
}



===== WPP_SF_DDDDDDDDDDDD @ 14000f7b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDDDDDDDDDDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4
                        ,undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        ,undefined1 param_9,undefined1 param_10,undefined1 param_11,
                        undefined1 param_12,undefined1 param_13,undefined1 param_14,
                        undefined1 param_15)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_23a3c04cde1b354a8276a948161bd449_Traceguids,0x11,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,&param_9,4,&param_10,4,&param_11,4,
             &param_12,4,&param_13,4,&param_14,4,&param_15,4,0);
  return;
}



===== WPP_SF_Dq @ 14000f898 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_23a3c04cde1b354a8276a948161bd449_Traceguids,0x10,local_res20,4,
             &param_5,8,0);
  return;
}



===== WPP_SF_qqD @ 14000f8f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_23a3c04cde1b354a8276a948161bd449_Traceguids,0x19,&local_res20,8,
             &param_5,8,&param_6,4,0);
  return;
}



===== ScsiPortIoMapTransferVrfy @ 14000f960 =====

void ScsiPortIoMapTransferVrfy
               (longlong param_1,longlong param_2,longlong param_3,undefined4 param_4)

{
  ScsiPortIoMapTransfer(param_1,param_2,param_3,param_4);
  return;
}



===== SpRemapCommonBufferForMiniport @ 14000f978 =====

void SpRemapCommonBufferForMiniport(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong *plVar6;
  longlong local_res8;
  
  lVar4 = *(longlong *)(param_1 + 0x760);
  uVar5 = 0;
  local_res8 = 0;
  lVar1 = *(longlong *)(lVar4 + 0x50);
  if (*(int *)(lVar4 + 0x48) != 0) {
    do {
      lVar4 = *(longlong *)(lVar1 + uVar5 * 8);
      plVar6 = (longlong *)((ulonglong)(*(int *)(param_1 + 0x210) - 0x1000) + lVar4);
      *plVar6 = lVar4;
      uVar3 = *(int *)(param_1 + 0x214) + 0xfffU & 0xfffff000;
      *(uint *)(plVar6 + 1) = uVar3;
      plVar6[4] = (ulonglong)uVar3 + *(longlong *)(lVar1 + uVar5 * 8);
      *(undefined4 *)(plVar6 + 5) = 0x1000;
      lVar4 = SpRemapBlock(lVar4,(ulonglong)uVar3,&local_res8);
      if (lVar4 != 0) {
        plVar6[3] = lVar4;
        plVar6[2] = local_res8;
      }
      lVar4 = *(longlong *)(param_1 + 0x760);
      uVar3 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar3;
    } while (uVar3 < *(uint *)(lVar4 + 0x48));
  }
  if (*(int *)(lVar4 + 0x60) != 0) {
    lVar2 = *(longlong *)(lVar1 + uVar5 * 8);
    plVar6 = (longlong *)
             ((ulonglong)((*(int *)(lVar4 + 0x60) + 0xfffU & 0xfffff000) - 0x1000) + lVar2);
    *plVar6 = lVar2;
    *(undefined4 *)(plVar6 + 1) = *(undefined4 *)(*(longlong *)(param_1 + 0x760) + 0x60);
    plVar6[4] = (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x760) + 0x60) +
                *(longlong *)(lVar1 + uVar5 * 8);
  }
  return;
}



===== SpHandleTraceNotifyType @ 14000fa6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong SpHandleTraceNotifyType(undefined8 param_1,int param_2,longlong *param_3)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  byte bVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint uVar7;
  ulonglong uVar8;
  
  uVar5 = 0x7d3;
  if (param_2 < 0x7d4) {
    if (param_2 == 0x7d3) {
      uVar5 = WmiQueryTraceInformation
                        ((int)*param_3,param_3[1],(int)param_3[2],param_3[3],param_3[4]);
    }
    else {
      if (param_2 == 1000) {
        uVar5 = PortTraceInitTracing(param_3);
        return uVar5;
      }
      if (param_2 == 0x3e9) {
        lVar6 = *param_3;
        PortTraceErrorFreeDriver(lVar6);
        if (*(code **)(lVar6 + 0x10) != (code *)0x0) {
          (**(code **)(lVar6 + 0x10))(*(undefined8 *)(lVar6 + 8));
        }
        uVar5 = ExFreePoolWithTag(lVar6,0);
        return uVar5;
      }
      if (param_2 != 2000) {
        if (param_2 == 0x7d1) {
          uVar5 = PortTraceInitGlobalLogger(param_3);
          return uVar5;
        }
        if (param_2 == 0x7d2) {
          uVar5 = IoWMIRegistrationControl(*param_3,(int)param_3[1]);
          *(int *)((longlong)param_3 + 0xc) = (int)uVar5;
          return uVar5;
        }
        return 0x7d3;
      }
      uVar5 = WmiTraceMessageVa(*param_3,(int)param_3[1],param_3[2],(short)param_3[3],param_3[4]);
    }
    *(int *)(param_3 + 5) = (int)uVar5;
    return uVar5;
  }
  if (param_2 == 0x7d4) {
    uVar5 = RtlInitUnicodeString(*param_3,param_3[1]);
    return uVar5;
  }
  if (param_2 == 0x7d5) {
    uVar5 = vDbgPrintExWithPrefix("ScsiMiniport: ",0xd,0,*param_3,param_3[1]);
    return uVar5;
  }
  if (param_2 == 4000) {
    lVar6 = *param_3;
    ExpInterlockedPushEntrySList(lVar6 + 0x40,param_3[1] + -0x20);
    bVar4 = KeGetCurrentIrql();
    if (bVar4 < 3) {
      uVar5 = PortTraceErrorDrainList(*(undefined8 *)(lVar6 + 8),lVar6 + 0x40);
      return uVar5;
    }
    LOCK();
    *(int *)(lVar6 + 0x54) = *(int *)(lVar6 + 0x54) + 1;
    UNLOCK();
    uVar5 = KeInsertQueueDpc(lVar6 + 0x58,0,0);
    return uVar5;
  }
  if (param_2 != 0xfa1) {
    if (param_2 == 0xfa2) {
      uVar5 = param_3[1];
      LOCK();
      *(undefined4 *)(uVar5 - 0x10) = 0;
      UNLOCK();
      return uVar5;
    }
    return 0x7d3;
  }
  uVar1 = *(uint *)(param_3 + 1);
  lVar6 = 0;
  lVar2 = *param_3;
  if ((uVar1 < 0xf1) && (uVar8 = 0, *(int *)(lVar2 + 0x50) != 0)) {
    do {
      uVar5 = *(ulonglong *)(lVar2 + 0x38);
      lVar3 = *(longlong *)(uVar5 + uVar8 * 8);
      if (*(int *)(lVar3 + 0x10) == 0) {
        uVar5 = 0;
        LOCK();
        uVar7 = *(uint *)(lVar3 + 0x10);
        if (uVar7 == 0) {
          *(uint *)(lVar3 + 0x10) = 1;
        }
        else {
          uVar5 = (ulonglong)uVar7;
        }
        UNLOCK();
        if (uVar7 == 0) {
          *(uint *)(lVar3 + 0x14) = uVar1;
          lVar6 = lVar3 + 0x20;
          break;
        }
      }
      uVar7 = (int)uVar8 + 1;
      uVar8 = (ulonglong)uVar7;
    } while (uVar7 < *(uint *)(lVar2 + 0x50));
  }
  param_3[2] = lVar6;
  return uVar5;
}



===== PortPassThroughBuildIrpEx @ 14000fcb0 =====

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
    if (param_2 == 0) goto LAB_14000fe64;
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
      goto LAB_14000fe64;
    }
    IoFreeIrp(lVar3);
  }
  lVar3 = 0;
LAB_14000fe64:
  return lVar3;
}



===== PortPassThroughExBasicValidation @ 14000fe8c =====

undefined8 PortPassThroughExBasicValidation(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  char cVar6;
  undefined8 uVar7;
  uint uVar8;
  
  lVar4 = *(longlong *)(param_1 + 0xb8);
  lVar5 = *(longlong *)(param_1 + 0x18);
  cVar6 = IoIs32bitProcess();
  uVar2 = *(uint *)(lVar4 + 0x10);
  uVar8 = (-(uint)(cVar6 != '\0') & 0xfffffff4) + 0x40;
  if (uVar2 < uVar8) {
    uVar7 = 0xc0000023;
  }
  else if (*(uint *)(lVar5 + 4) == uVar8) {
    uVar3 = *(uint *)(lVar5 + 0x18);
    uVar1 = *(int *)(lVar5 + 0xc) + uVar3;
    if ((((uVar1 < uVar3) || (*(int *)(lVar5 + 8) == 0)) || (*(int *)(lVar5 + 0xc) == 0)) ||
       (((uVar8 = *(int *)(lVar5 + 8) + -1 + uVar8, uVar3 < uVar8 || (uVar2 <= uVar8)) ||
        ((uVar2 < uVar1 || (3 < *(byte *)(lVar5 + 0x12))))))) {
      uVar7 = 0xc000000d;
    }
    else {
      uVar7 = 0;
    }
  }
  else {
    uVar7 = 0xc0000059;
  }
  return uVar7;
}



===== PortPassThroughExMarshalResultsFromSrbEx @ 14000ff28 =====

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
    goto LAB_14001011a;
  }
  uVar12 = (ulonglong)uVar14;
  puVar6 = (undefined8 *)ExAllocatePool2(0x40,uVar14,0x69506c50);
  if (puVar6 == (undefined8 *)0x0) {
    iVar5 = -0x3fffff66;
    goto LAB_14001011a;
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
LAB_14000ffeb:
      cVar4 = (char)piVar8[2];
      bVar10 = *(byte *)((longlong)piVar8 + 9);
    }
    else if (iVar5 == 0x42) {
      _Src = *(void **)(piVar8 + 6);
      goto LAB_14000ffeb;
    }
    *(char *)(puVar6 + 2) = cVar4;
    if (*(char *)(param_2 + 3) < '\0') {
      bVar11 = *(byte *)((longlong)puVar6 + 0x11);
      if ((bVar11 != 0) &&
         (_Dst = (void *)((ulonglong)*(uint *)((longlong)puVar6 + 0x1c) +
                         *(longlong *)(param_1 + 0x18)), _Dst != (void *)0x0)) {
        *(byte *)((longlong)puVar6 + 0x11) = bVar10;
        memcpy(_Dst,_Src,(ulonglong)bVar10);
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
LAB_14001011a:
  *param_4 = iVar5;
  return;
}



===== PortPassThroughExNormalize @ 140010144 =====

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
      memcpy(param_1,_Src,(ulonglong)(*(int *)(puVar1 + 1) + 0x3fU));
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
    memcpy(param_1 + 7,puVar1 + 6,(ulonglong)*(uint *)(puVar1 + 1));
    param_1[5] = (ulonglong)*(uint *)(puVar1 + 5);
    param_1[6] = (ulonglong)*(uint *)((longlong)puVar1 + 0x2c);
  }
  return uVar4;
}



===== PortPassThroughFreeIrpEx @ 1400101f4 =====

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



===== PortPassThroughFreeSrb @ 140010244 =====

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



===== PortPassThroughMarshalResultsFromSrb @ 14001033c =====

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
        memcpy(_Dst,*(void **)(param_2 + 0x20),(ulonglong)bVar11);
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



===== PortPassThroughNormalize @ 1400104c4 =====

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



===== PortpAsyncCompletion @ 1400105b0 =====

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



===== PortpCancelRoutine @ 140010640 =====

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



===== PortpCompleteRequestIrp @ 1400106e0 =====

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



===== PortpEnableCancel @ 1400107a4 =====

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



===== PortpPassThroughZeroUnusedBuffers @ 1400107ec =====

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



===== PortpSyncCompletion @ 140010830 =====

void PortpSyncCompletion(undefined8 param_1,undefined8 param_2)

{
  KeSetEvent(param_2,0,0);
  return;
}



===== PortTraceInitGlobalLogger @ 140010854 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PortTraceInitGlobalLogger(undefined8 *param_1)

{
  uint *puVar1;
  undefined8 *puVar2;
  uint *puVar3;
  undefined1 *puVar4;
  int iVar5;
  code *pcVar6;
  longlong lVar7;
  undefined1 auStack_198 [32];
  undefined8 local_178;
  undefined4 local_168;
  int local_164;
  uint local_160;
  undefined4 local_15c;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined4 local_140;
  wchar_t *local_138;
  uint *local_130;
  undefined4 local_128;
  undefined4 *local_120;
  undefined4 local_118;
  undefined8 local_110;
  undefined4 local_108;
  wchar_t *local_100;
  undefined4 *local_f8;
  undefined4 local_f0;
  undefined4 *local_e8;
  undefined4 local_e0;
  undefined8 local_d8;
  undefined4 local_d0;
  wchar_t local_98 [56];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_198;
  puVar1 = (uint *)*param_1;
  puVar2 = (undefined8 *)param_1[1];
  puVar3 = (uint *)param_1[2];
  puVar4 = (undefined1 *)param_1[3];
  builtin_wcsncpy(local_98 + 8,L"alLogger\\",10);
  local_138 = L"Start";
  local_130 = (uint *)&local_164;
  local_120 = &local_168;
  local_160 = 0;
  local_15c = 0;
  local_164 = 0;
  local_168 = 0;
  local_98[0x12] = 0;
  builtin_wcsncpy(local_98,L"WMI\\Glob",8);
  local_148 = 0;
  local_140 = 0x120;
  local_128 = 0x4000004;
  local_118 = 4;
  local_110 = 0;
  local_108 = 0;
  local_158 = 0;
  uStack_150 = 0;
  RtlInitUnicodeString(&local_158,L"RtlQueryRegistryValuesEx");
  pcVar6 = (code *)MmGetSystemRoutineAddress(&local_158);
  local_178 = 0;
  if (pcVar6 == (code *)0x0) {
    pcVar6 = RtlQueryRegistryValues_exref;
  }
  iVar5 = (*pcVar6)(0x80000002,local_98,&local_148,0);
  if ((-1 < iVar5) && (local_164 != 0)) {
    local_148 = 0;
    local_138 = L"Flags";
    local_130 = &local_160;
    local_140 = 0x120;
    local_120 = &local_168;
    local_100 = L"Level";
    local_f8 = &local_15c;
    local_e8 = &local_168;
    lVar7 = -1;
    local_128 = 0x4000004;
    local_118 = 4;
    local_110 = 0;
    local_108 = 0x120;
    local_f0 = 0x4000004;
    local_e0 = 1;
    local_d8 = 0;
    local_d0 = 0;
    do {
      lVar7 = lVar7 + 1;
    } while (local_98[lVar7] != L'\0');
    WppGuidToStr((longlong)(local_98 + lVar7),puVar1);
    local_158 = 0;
    uStack_150 = 0;
    RtlInitUnicodeString(&local_158,L"RtlQueryRegistryValuesEx");
    pcVar6 = (code *)MmGetSystemRoutineAddress(&local_158);
    local_178 = 0;
    if (pcVar6 == (code *)0x0) {
      pcVar6 = RtlQueryRegistryValues_exref;
    }
    iVar5 = (*pcVar6)(0x80000002,local_98,&local_148,0);
    if ((-1 < iVar5) && (local_164 == 1)) {
      *puVar2 = 1;
      *puVar3 = local_160 & 0x7fffffff;
      *puVar4 = (undefined1)local_15c;
    }
  }
  return;
}



===== PortTraceInitTracing @ 140010ac0 =====

void PortTraceInitTracing(undefined8 *param_1)

{
  int *piVar1;
  longlong lVar2;
  undefined4 *puVar3;
  
  piVar1 = (int *)*param_1;
  if (*piVar1 == 0x38) {
    piVar1[0xc] = 0;
    piVar1[0xd] = 0;
    if (*(longlong *)(piVar1 + 10) == 0) {
      *(undefined4 *)(param_1 + 1) = 0;
    }
    else {
      puVar3 = (undefined4 *)ExAllocatePool2(0x40,0xa0,0x63546c50);
      if (puVar3 == (undefined4 *)0x0) {
        *(undefined4 *)(param_1 + 1) = 0xc000009a;
      }
      else {
        *puVar3 = 0xa0;
        lVar2 = *(longlong *)(piVar1 + 10);
        *(longlong *)(puVar3 + 2) = lVar2;
        *(undefined8 *)(puVar3 + 4) = *(undefined8 *)(lVar2 + 0x68);
        *(undefined8 *)(lVar2 + 0x68) = *(undefined8 *)(piVar1 + 8);
        PortTraceErrorRegisterDriver((longlong)puVar3,(longlong)piVar1);
        *(undefined4 **)(piVar1 + 0xc) = puVar3;
        *(undefined4 *)(param_1 + 1) = 0;
      }
    }
  }
  else {
    *(undefined4 *)(param_1 + 1) = 0xc000000d;
  }
  return;
}



===== WppGuidToStr @ 140010b68 =====

void WppGuidToStr(longlong param_1,uint *param_2)

{
  longlong lVar1;
  
  lVar1 = param_1;
  WppIntToHex(param_1,*param_2,8);
  *(undefined2 *)(param_1 + 0x10) = 0x2d;
  WppIntToHex(param_1 + 0x12,(uint)(ushort)param_2[1],4);
  *(undefined2 *)(lVar1 + 0x1a) = 0x2d;
  WppIntToHex(lVar1 + 0x1c,(uint)*(ushort *)((longlong)param_2 + 6),4);
  *(undefined2 *)(lVar1 + 0x24) = 0x2d;
  WppIntToHex(lVar1 + 0x26,(uint)(byte)param_2[2],2);
  WppIntToHex(lVar1 + 0x2a,(uint)*(byte *)((longlong)param_2 + 9),2);
  *(undefined2 *)(lVar1 + 0x2e) = 0x2d;
  WppIntToHex(lVar1 + 0x30,(uint)*(byte *)((longlong)param_2 + 10),2);
  WppIntToHex(lVar1 + 0x34,(uint)*(byte *)((longlong)param_2 + 0xb),2);
  WppIntToHex(lVar1 + 0x38,(uint)(byte)param_2[3],2);
  WppIntToHex(lVar1 + 0x3c,(uint)*(byte *)((longlong)param_2 + 0xd),2);
  WppIntToHex(lVar1 + 0x40,(uint)*(byte *)((longlong)param_2 + 0xe),2);
  WppIntToHex(lVar1 + 0x44,(uint)*(byte *)((longlong)param_2 + 0xf),2);
  *(undefined2 *)(lVar1 + 0x48) = 0;
  return;
}



===== WppIntToHex @ 140010c68 =====

void WppIntToHex(longlong param_1,uint param_2,int param_3)

{
  uint uVar1;
  longlong lVar2;
  
  lVar2 = (longlong)(param_3 + -1);
  if (-1 < param_3 + -1) {
    do {
      uVar1 = param_2 & 0xf;
      param_2 = param_2 >> 4;
      *(wchar_t *)(param_1 + lVar2 * 2) = L"0123456789abcdef"[uVar1];
      lVar2 = lVar2 + -1;
    } while (-1 < lVar2);
  }
  return;
}



===== PortTraceErrorDrainList @ 140010c9c =====

void PortTraceErrorDrainList(undefined8 param_1,undefined8 param_2)

{
  void *_Dst;
  longlong lVar1;
  
  while( true ) {
    lVar1 = ExpInterlockedPopEntrySList(param_2);
    if (lVar1 == 0) break;
    _Dst = (void *)IoAllocateErrorLogEntry(param_1,*(undefined1 *)(lVar1 + 0x14));
    if (_Dst != (void *)0x0) {
      memcpy(_Dst,(void *)(lVar1 + 0x20),(ulonglong)*(uint *)(lVar1 + 0x14));
      IoWriteErrorLogEntry(_Dst);
    }
    LOCK();
    *(undefined4 *)(lVar1 + 0x10) = 0;
    UNLOCK();
  }
  return;
}



===== PortpErrorDrainListDpc @ 140010d30 =====

void PortpErrorDrainListDpc(undefined8 param_1,longlong param_2)

{
  PortTraceErrorDrainList(*(undefined8 *)(param_2 + 8),param_2 + 0x40);
  LOCK();
  *(int *)(param_2 + 0x54) = *(int *)(param_2 + 0x54) + -1;
  UNLOCK();
  return;
}



===== PortpErrorInitDpc @ 140010d58 =====

void PortpErrorInitDpc(longlong param_1)

{
  KeInitializeDpc(param_1 + 0x58,PortpErrorDrainListDpc,param_1);
  return;
}



===== _guard_check_icall @ 140010d90 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140010da8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140010dcc =====

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



===== __GSHandlerCheck_SEH @ 140010e34 =====

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



===== __security_check_cookie @ 140010ed0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140010f10 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140010f40 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140010f40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140010f70 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 140010fc0 =====

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
  
                    /* 0x10fc0  48  memcpy
                       0x10fc0  49  memmove */
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



===== memset @ 1400112c0 =====

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



===== __memset_repmovs @ 140011400 =====

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



===== __memset_query @ 140011480 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140011500 =====

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



===== __memset_spec_ermsb_repmovsb @ 140011640 =====

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



===== __memset_spec_plain @ 1400116c0 =====

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



===== memcmp @ 1400117e0 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_140011823;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_140011894;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_140011890:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140011894;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_14001188c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140011890;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14001188c;
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
LAB_140011894:
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
LAB_140011823:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== SpProcessAdapterSystemState$fin$0 @ 1400118ad =====

void SpProcessAdapterSystemState_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  
  IoStartNextPacket(*(undefined8 *)(param_2 + 0x80),0);
  if (*(int *)(param_2 + 0x30) != 0x103) {
    if (*(int *)(param_2 + 0x30) < 0) {
      *(undefined4 *)(*(longlong *)(param_2 + 0x98) + 0x28) = *(undefined4 *)(param_2 + 0x90);
    }
    lVar1 = *(longlong *)(param_2 + 0x88);
    PoStartNextPowerIrp(lVar1);
    puVar2 = *(undefined8 **)(lVar1 + 0xb8);
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
    PoCallDriver(*(undefined8 *)(*(longlong *)(param_2 + 0x38) + 0x10),lVar1);
  }
  return;
}



===== SpLockUnlockQueue$fin$0 @ 140011952 =====

void SpLockUnlockQueue_fin_0(undefined8 param_1,longlong param_2)

{
  IoFreeIrp(*(undefined8 *)(param_2 + 0x60));
  if (*(longlong *)(param_2 + 0x30) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x30),0);
  }
  if (*(longlong *)(param_2 + 0x38) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x38),0);
  }
  return;
}



===== memset @ 140012020 =====

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



===== SpGetSupportedAdapterControlFunctions @ 14001c008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SpGetSupportedAdapterControlFunctions(longlong param_1)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined2 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  RtlInitializeBitMap(param_1 + 0x2c8,param_1 + 0x2d8,5);
  RtlClearAllBits();
  uVar2 = 0;
  if ((*(code **)(param_1 + 0x2b8) != (code *)0x0) && ((*(byte *)(param_1 + 0x168) & 4) != 0)) {
    local_20 = 0;
    local_28 = 5;
    iVar1 = (**(code **)(param_1 + 0x2b8))(*(undefined8 *)(param_1 + 0x148),0,&local_28);
    if (iVar1 == 0) {
      pcVar3 = (char *)((longlong)&local_28 + 4);
      do {
        if (*pcVar3 == '\x01') {
          RtlSetBits(param_1 + 0x2c8,uVar2,1);
        }
        uVar2 = uVar2 + 1;
        pcVar3 = pcVar3 + 1;
      } while (uVar2 < 5);
    }
  }
  return;
}



===== ScsiPortInitializeDispatchTables @ 14001c0ec =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ScsiPortInitializeDispatchTables(void)

{
  longlong lVar1;
  undefined8 *puVar2;
  
  _DAT_140017538 = ScsiPortPdoPnp;
  _DAT_140017518 = ScsiPortSystemControlIrp;
  puVar2 = &DeviceMajorFunctionTable;
  for (lVar1 = 0x1c; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = ScsiPortDispatchUnimplemented;
    puVar2 = puVar2 + 1;
  }
  _DAT_140017458 = ScsiPortPdoPnp;
  _DAT_1400173f0 = ScsiPortPdoDeviceControl;
  _DAT_1400174d0 = ScsiPortPdoDeviceControl;
  DeviceMajorFunctionTable = ScsiPortPdoCreateClose;
  _DAT_1400173f8 = ScsiPortPdoScsi;
  _Scsi1DeviceMajorFunctionTable = ScsiPortPdoCreateClose;
  _DAT_1400174d8 = ScsiPortScsi1PdoScsi;
  puVar2 = &AdapterMajorFunctionTable;
  for (lVar1 = 0x1c; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = ScsiPortDispatchUnimplemented;
    puVar2 = puVar2 + 1;
  }
  _DAT_140017310 = ScsiPortFdoDeviceControl;
  _DAT_140017318 = ScsiPortFdoDispatch;
  _DAT_140017378 = ScsiPortFdoPnp;
  _DAT_140017390 = ScsiPortPdoCreateClose;
  _DAT_140017470 = ScsiPortPdoCreateClose;
  AdapterMajorFunctionTable = ScsiPortFdoCreateClose;
  _DAT_1400172b0 = ScsiPortFdoCreateClose;
  _DAT_140017438 = ScsiPortSystemControlIrp;
  _DAT_140017430 = ScsiPortDispatchPower;
  _DAT_140017510 = ScsiPortDispatchPower;
  _DAT_140017358 = ScsiPortSystemControlIrp;
  _DAT_140017350 = ScsiPortDispatchPower;
  return;
}



===== AdjustReportLuns @ 14001c20c =====

byte * AdjustReportLuns(undefined8 param_1,byte *param_2)

{
  byte *pbVar1;
  byte *_Dst;
  byte bVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  ulonglong uVar9;
  
  uVar3 = CONCAT31(CONCAT21(CONCAT11(*param_2,param_2[1]),param_2[2]),param_2[3]);
  uVar6 = uVar3 >> 3;
  if (0x4000 < uVar6) {
    uVar6 = 0x4000;
    uVar3 = 0x20000;
  }
  _Dst = (byte *)SpAllocatePoolEx(0,(ulonglong)(uVar3 + 0x48),0x78506353,param_1,0x656e756d,0x55d);
  if (_Dst == (byte *)0x0) {
    iVar7 = uVar6 * 8;
    param_2[3] = (byte)iVar7;
    *param_2 = (byte)((uint)iVar7 >> 0x18);
    param_2[1] = (byte)((uint)iVar7 >> 0x10);
    param_2[2] = (byte)((uint)iVar7 >> 8);
    _Dst = param_2;
  }
  else {
    iVar7 = 0;
    memset(_Dst,0,(ulonglong)(uVar3 + 0x48));
    uVar4 = 0;
    do {
      iVar7 = iVar7 + 1;
      _Dst[uVar4 * 8 + 9] = (byte)uVar4;
      bVar2 = (byte)uVar4 + 1;
      uVar4 = (ulonglong)bVar2;
    } while (bVar2 < 8);
    if (uVar6 != 0) {
      uVar9 = (ulonglong)uVar6;
      pbVar1 = param_2;
      do {
        pbVar8 = pbVar1 + 8;
        uVar5 = uVar4;
        if (7 < ((uint)pbVar1[9] | (*pbVar8 & 0x3f) << 8)) {
          uVar5 = (ulonglong)(byte)((char)uVar4 + 1);
          iVar7 = iVar7 + 1;
          *(undefined8 *)(_Dst + uVar4 * 8 + 8) = *(undefined8 *)pbVar8;
        }
        uVar9 = uVar9 - 1;
        uVar4 = uVar5;
        pbVar1 = pbVar8;
      } while (uVar9 != 0);
    }
    iVar7 = iVar7 * 8;
    *(undefined4 *)(_Dst + 4) = *(undefined4 *)(param_2 + 4);
    *_Dst = (byte)((uint)iVar7 >> 0x18);
    _Dst[1] = (byte)((uint)iVar7 >> 0x10);
    _Dst[2] = (byte)((uint)iVar7 >> 8);
    _Dst[3] = (byte)iVar7;
  }
  return _Dst;
}



===== IssueInquiry @ 14001c360 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int IssueInquiry(longlong *param_1,char param_2,undefined1 param_3,void *param_4,undefined1 *param_5
                )

{
  longlong lVar1;
  longlong lVar2;
  void *_Dst;
  undefined8 *puVar3;
  uint uVar4;
  int iVar5;
  undefined7 in_register_00000081;
  undefined1 auStackY_108 [32];
  undefined8 in_stack_ffffffffffffff30;
  uint local_b8 [2];
  undefined1 *local_b0;
  undefined2 local_a8 [5];
  undefined1 local_9e;
  undefined4 local_9c;
  undefined4 local_94;
  undefined1 local_60;
  byte local_5f;
  undefined1 local_5e;
  byte local_5c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_108;
  local_b8[0] = 0;
  local_b0 = param_5;
  lVar1 = param_1[0x2d];
  lVar2 = *(longlong *)(lVar1 + 0x6f8);
  _Dst = *(void **)(lVar1 + 0x6e8);
  puVar3 = *(undefined8 **)(lVar1 + 0x6f0);
  IoInitializeIrp(lVar2,0x118,CONCAT71(in_register_00000081,1));
  memset(_Dst,0,0x100);
  *puVar3 = 0;
  puVar3[1] = 0;
  *(undefined2 *)(puVar3 + 2) = 0;
  memset(local_a8,0,0x58);
  local_a8[0] = 0x58;
  local_9c = 0x48;
  local_94 = *(undefined4 *)(param_1[0x2d] + 0x794);
  local_9e = 6;
  local_60 = 0x12;
  local_5c = (-(param_2 != '\0') & 0xdbU) + 0x24;
  local_5f = param_2 != '\0' | local_5f & 0xfe;
  local_5e = param_3;
  iVar5 = SpSendSrbSynchronous
                    (param_1,(longlong)local_a8,lVar2,*(longlong *)(param_1[0x2d] + 0x700),
                     (longlong)_Dst,(uint)local_5c,(longlong)puVar3,in_stack_ffffffffffffff30,
                     local_b8);
  uVar4 = local_b8[0];
  if (-1 < iVar5) {
    if (param_4 != _Dst) {
      memcpy(param_4,_Dst,(ulonglong)local_b8[0]);
    }
    *local_b0 = (char)uVar4;
  }
  return iVar5;
}



===== SpCloneAndSwapLogicalUnit @ 14001c4d4 =====

int SpCloneAndSwapLogicalUnit(longlong *param_1,void *param_2,ulonglong param_3,undefined8 *param_4)

{
  int *piVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  byte bVar4;
  uint uVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong *plVar8;
  char cVar9;
  int iVar10;
  longlong lVar11;
  void *_Dst;
  longlong lVar12;
  byte bVar13;
  ulonglong uVar14;
  undefined8 *puVar15;
  ushort uVar16;
  longlong *local_50;
  longlong *local_48;
  
  local_48 = (longlong *)param_1[0x2d];
  uVar14 = param_3;
  puVar15 = param_4;
  lVar11 = IoGetDriverObjectExtension(*(undefined8 *)(*local_48 + 8),ScsiPortInitialize);
  lVar6 = *param_1;
  _Dst = (void *)0x0;
  local_50 = (longlong *)0x0;
  uVar16 = 0;
  *param_4 = 0;
  lVar12 = 0;
  SpReleaseRemoveLock(lVar6,0xc0);
  SpWaitForRemoveLock(*param_1,0xcd);
  uVar2 = *(undefined1 *)((longlong)param_1 + 0x156);
  uVar3 = *(undefined1 *)((longlong)param_1 + 0x155);
  bVar4 = *(byte *)((longlong)param_1 + 0x154);
  SpRemoveLogicalUnitFromBin(param_1[0x2d],(longlong)param_1);
  *(undefined2 *)((longlong)param_1 + 0x154) = 0xffff;
  *(undefined1 *)((longlong)param_1 + 0x156) = 0xff;
  if ((short)param_1[0x1f7] == 0) {
LAB_14001c5d6:
    if ((int)param_1[0x1fa] != 0) {
      uVar14 = 0x59506353;
      puVar15 = *(undefined8 **)(*param_1 + 8);
      lVar12 = SpAllocatePoolEx(1,0xff,0x59506353,puVar15,0x656e756d,0xcbd);
      if (lVar12 == 0) {
        if (_Dst != (void *)0x0) {
          ExFreePoolWithTag(_Dst);
        }
        goto LAB_14001c628;
      }
    }
    if ((*(int *)(lVar11 + 0x24) == 1) &&
       (((*(byte *)((longlong)param_2 + 2) & 7) < 2 || (*(int *)((longlong)param_1 + 0xfa4) != 0))))
    {
      cVar9 = '\x01';
    }
    else {
      cVar9 = '\0';
    }
    iVar10 = SpCreateLogicalUnit(local_48,(ulonglong)bVar4,CONCAT71((int7)(uVar14 >> 8),uVar3),
                                 CONCAT71((int7)((ulonglong)puVar15 >> 8),uVar2),'\0',cVar9,
                                 &local_50);
    plVar7 = local_50;
    if (iVar10 < 0) {
      if (_Dst != (void *)0x0) {
        ExFreePoolWithTag(_Dst,0);
      }
      if (lVar12 != 0) {
        ExFreePoolWithTag(lVar12,0);
      }
    }
    else {
      local_50[0x2c] = param_1[0x2c];
      param_1[0x2c] = 0;
      *(int *)(local_50 + 0x28) = (int)param_1[0x28];
      *(undefined1 *)((longlong)local_50 + 0x14c) = *(undefined1 *)((longlong)param_1 + 0x14c);
      local_50[0x1f2] = param_1[0x1f2];
      lVar6 = param_1[500];
      local_50[499] = param_1[499];
      local_50[500] = lVar6;
      local_50[0x1f5] = param_1[0x1f5];
      *(int *)(local_50 + 0x2a) = (int)param_1[0x2a];
      *(int *)(local_50 + 3) = (int)param_1[3];
      *(uint *)(*local_50 + 0x34) = *(uint *)(*local_50 + 0x34) | *(uint *)(*param_1 + 0x34) & 1;
      bVar13 = (*(byte *)(local_50 + 0x1f6) ^ *(byte *)(param_1 + 0x1f6)) & 1 ^
               *(byte *)(local_50 + 0x1f6);
      *(byte *)(local_50 + 0x1f6) = bVar13;
      *(byte *)(local_50 + 0x1f6) = (bVar13 ^ *(byte *)(param_1 + 0x1f6)) & 2 ^ bVar13;
      if (_Dst != (void *)0x0) {
        *(short *)(local_50 + 0x1f7) = (short)param_1[0x1f7];
        *(ushort *)((longlong)local_50 + 0xfba) = uVar16;
        local_50[0x1f8] = (longlong)_Dst;
        memcpy(_Dst,(void *)param_1[0x1f8],(ulonglong)uVar16);
      }
      if (lVar12 != 0) {
        plVar7[0x1f9] = lVar12;
        uVar5 = *(uint *)(param_1 + 0x1fa);
        *(uint *)(plVar7 + 0x1fa) = uVar5;
        memcpy((void *)plVar7[0x1f9],(void *)param_1[0x1f9],(ulonglong)uVar5);
      }
      memcpy((void *)((longlong)plVar7 + 0x1fa),param_2,param_3 & 0xffffffff);
      plVar8 = local_50;
      LOCK();
      piVar1 = (int *)(*(longlong *)(*plVar7 + 0x40) + 0x4c);
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      LOCK();
      piVar1 = (int *)(*(longlong *)(*local_50 + 0x40) + 0x4c);
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      *(undefined1 *)((longlong)local_50 + 0x155) = uVar3;
      *(undefined1 *)((longlong)local_50 + 0x156) = uVar2;
      *(byte *)((longlong)local_50 + 0x154) = bVar4;
      SpAddLogicalUnitToBin(local_50[0x2d],(longlong)local_50);
      *param_4 = plVar8;
    }
  }
  else {
    uVar16 = (short)param_1[0x1f7] + 2;
    uVar14 = 0x59506353;
    puVar15 = *(undefined8 **)(*param_1 + 8);
    _Dst = (void *)SpAllocatePoolEx(1,(ulonglong)uVar16,0x59506353,puVar15,0x656e756d,0xcaf);
    if (_Dst != (void *)0x0) goto LAB_14001c5d6;
LAB_14001c628:
    iVar10 = -0x3fffff66;
  }
  return iVar10;
}



===== SpCreateInitiatorLU @ 14001c858 =====

longlong * SpCreateInitiatorLU(longlong *param_1,ulonglong param_2,undefined8 param_3)

{
  int *piVar1;
  undefined1 uVar2;
  longlong *plVar3;
  int iVar4;
  longlong *plVar5;
  longlong *local_res8;
  
  plVar5 = (longlong *)0x0;
  local_res8 = (longlong *)0x0;
  uVar2 = *(undefined1 *)(param_1[0x3f] + 0x49 + (param_2 & 0xff));
  iVar4 = SpCreateLogicalUnit(param_1,param_2,CONCAT71((int7)((ulonglong)param_3 >> 8),uVar2),0,'\0'
                              ,'\0',&local_res8);
  plVar3 = local_res8;
  if (-1 < iVar4) {
    *(char *)((longlong)local_res8 + 0x154) = (char)param_2;
    *(undefined1 *)((longlong)local_res8 + 0x155) = uVar2;
    *(undefined1 *)((longlong)local_res8 + 0x156) = 0;
    ScsiPortInitPdoWmi(local_res8);
    plVar5 = local_res8;
    LOCK();
    piVar1 = (int *)(*(longlong *)(*plVar3 + 0x40) + 0x4c);
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    *(undefined1 *)((longlong)plVar3 + 0x156) = 0;
    *(char *)((longlong)plVar3 + 0x154) = (char)param_2;
    *(undefined1 *)((longlong)plVar3 + 0x155) = uVar2;
    SpAddLogicalUnitToBin(local_res8[0x2d],(longlong)local_res8);
  }
  return plVar5;
}



===== SpCreateLogicalUnit @ 14001c91c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SpCreateLogicalUnit(longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                       char param_5,char param_6,undefined8 *param_7)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  longlong lVar4;
  void *_Dst;
  void *_Dst_00;
  void *_Dst_01;
  undefined8 *puVar5;
  byte bVar6;
  undefined8 *puVar7;
  longlong lVar8;
  undefined1 auStackY_148 [32];
  undefined8 local_e8;
  undefined8 uStack_e0;
  wchar_t local_d8 [64];
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_148;
  _Dst = (void *)0x0;
  _Dst_00 = (void *)0x0;
  local_e8 = 0;
  uStack_e0 = 0;
  _Dst_01 = (void *)0x0;
  lVar4 = SpAllocateIrpEx(CONCAT71((int7)((ulonglong)param_1 >> 8),1),param_2,
                          *(undefined8 *)(*param_1 + 8),0x656e756d,0xa9d);
  if (lVar4 == 0) {
    if ((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3fffff66;
    }
    if ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) == 0) {
      return -0x3fffff66;
    }
    if (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2) {
      return -0x3fffff66;
    }
    WPP_SF_(WPP_GLOBAL_Control[3],0x30,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids);
    return -0x3fffff66;
  }
  if (param_5 == '\0') {
    RtlStringCbPrintfW(local_d8,0x80,L"%wsPort%xPath%xTarget%xLun%x",param_1[0xd7]);
  }
  else {
    RtlStringCbPrintfW(local_d8,0x80,L"%wsPort%xRescan",param_1[0xd7]);
  }
  RtlInitUnicodeString(&local_e8,local_d8);
  if (*(uint *)((longlong)param_1 + 0x264) != 0) {
    _Dst = (void *)SpAllocatePoolEx(4,(ulonglong)*(uint *)((longlong)param_1 + 0x264),0x48506353,
                                    *(undefined8 *)(*param_1 + 8),0x656e756d,0xad1);
    if (_Dst == (void *)0x0) {
      *param_7 = 0;
      goto LAB_14001ca96;
    }
    memset(_Dst,0,(ulonglong)*(uint *)((longlong)param_1 + 0x264));
  }
  if (param_5 != '\0') {
    _Dst_00 = (void *)SpAllocatePoolEx(1,0xff,0x79506353,*(undefined8 *)(*param_1 + 8),0x656e756d,
                                       0xae8);
    if (_Dst_00 == (void *)0x0) {
      if (_Dst != (void *)0x0) {
        ExFreePoolWithTag(_Dst,0);
      }
LAB_14001ca96:
      IoFreeIrp(lVar4);
      return -0x3fffff66;
    }
    _Dst_01 = (void *)SpAllocatePoolEx(1,0xff,0x79506353,*(undefined8 *)(*param_1 + 8),0x656e756d,
                                       0xaf6);
    if (_Dst_01 == (void *)0x0) {
      if (_Dst != (void *)0x0) {
        ExFreePoolWithTag(_Dst,0);
      }
      IoFreeIrp(lVar4);
      ExFreePoolWithTag(_Dst_00,0);
      return -0x3fffff66;
    }
    memset(_Dst_00,0,0xff);
    memset(_Dst_01,0,0xff);
  }
  iVar3 = IoCreateDevice(*(undefined8 *)(*param_1 + 8),0x1280,&local_e8,0x2d);
  puVar7 = puRam0000000000000040;
  if (iVar3 < 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_D(WPP_GLOBAL_Control[3],0x31,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,iVar3);
    }
    puVar7 = (undefined8 *)0x0;
    if (_Dst != (void *)0x0) {
      ExFreePoolWithTag(_Dst,0);
    }
    IoFreeIrp(lVar4);
    ExFreePoolWithTag(_Dst_00,0);
    ExFreePoolWithTag(_Dst_01,0);
  }
  else {
    uRam000000000000004c = 1;
    uRam0000000000000030 = uRam0000000000000030 | 0x1010;
    uRam0000000000000098 = *(undefined4 *)(*param_1 + 0x98);
    memset(puRam0000000000000040,0,0x1280);
    bVar1 = *(byte *)(puVar7 + 1);
    *puVar7 = 0;
    *(byte *)(puVar7 + 1) = bVar1 | 1;
    puVar7[2] = *param_1;
    puVar5 = (undefined8 *)&Scsi1DeviceMajorFunctionTable;
    if (param_6 == '\0') {
      puVar5 = &DeviceMajorFunctionTable;
    }
    bVar6 = bVar1 & 0xfb | 1;
    puVar7[4] = puVar5;
    *(byte *)(puVar7 + 1) = bVar6;
    bVar1 = *(byte *)(param_1 + 1);
    *(undefined2 *)((longlong)puVar7 + 9) = 0xffff;
    puVar7[8] = 0;
    *(byte *)(puVar7 + 1) = (bVar6 ^ bVar1) & 8 ^ bVar6;
    puVar7[9] = 0;
    puVar7[0xd] = 0xffffffff;
    puVar7[0xe] = 0xffffffffffffffff;
    KeInitializeEvent(puVar7 + 10,1);
    uVar2 = *(undefined4 *)((longlong)param_1 + 0x15c);
    *(undefined2 *)((longlong)puVar7 + 0x154) = 0xffff;
    *(undefined2 *)((longlong)puVar7 + 0x14a) = 0;
    *(undefined4 *)((longlong)puVar7 + 0x144) = uVar2;
    *(undefined1 *)((longlong)puVar7 + 0x156) = 0xff;
    *(undefined1 *)(puVar7 + 0x3f) = 0xff;
    puVar5 = puVar7 + 0x3a;
    puVar7[0x3b] = puVar5;
    *puVar5 = puVar5;
    puVar5 = puVar7 + 0x249;
    puVar7[0x24a] = puVar5;
    *puVar5 = puVar5;
    puVar7[0x2c] = _Dst;
    puVar7[0x2d] = param_1;
    *(undefined4 *)(puVar7 + 0x39) = 0xffffffff;
    KeInitializeSpinLock(puVar7 + 0x1d8);
    InitializeSListHead((PSLIST_HEADER)(puVar7 + 0x1da));
    puVar5 = puVar7 + 0x50;
    lVar8 = 4;
    do {
      ExpInterlockedPushEntrySList(puVar7 + 0x1da,puVar5);
      puVar5 = puVar5 + 0x62;
      lVar8 = lVar8 + -1;
    } while (lVar8 != 0);
    *(undefined8 *)((longlong)puVar7 + 0x2c) = 1;
    *(undefined4 *)(puVar7 + 5) = 1;
    *(undefined4 *)(puVar7 + 0x1fb) = 0xffffffff;
    *(char *)((longlong)puVar7 + 0x14e) = param_5;
    *(undefined4 *)((longlong)puVar7 + 0x1044) = 1;
    puVar7[0x1fc] = 0x3fffffff;
    *(undefined4 *)(puVar7 + 0x1fd) = 0x3fffffff;
    puVar7[0x1de] = lVar4;
    *(undefined4 *)((longlong)puVar7 + 0xfdc) = 4;
    *(undefined4 *)((longlong)puVar7 + 0xfec) = 0x7ffffffe;
    *(undefined4 *)(puVar7 + 0x1fe) = 0xbffffffd;
    *(undefined4 *)((longlong)puVar7 + 0xff4) = 0x3ffffffe;
    *(undefined4 *)(puVar7 + 0x1ff) = 0x7ffffffd;
    *(undefined4 *)((longlong)puVar7 + 0xffc) = 0xbffffffc;
    *(undefined4 *)(puVar7 + 0x200) = 0xfffffffe;
    *(undefined4 *)(puVar7 + 0x209) = 2;
    *(undefined8 *)((longlong)puVar7 + 0x104c) = 3;
    RtlInitAnsiString(puVar7 + 0x1f7,_Dst_00);
    if (_Dst_00 != (void *)0x0) {
      *(undefined2 *)((longlong)puVar7 + 0xfba) = 0xff;
    }
    puVar7[0x1f9] = _Dst_01;
    uRam0000000000000030 = uRam0000000000000030 & 0xffffff7f;
    KeInitializeDeviceQueue(puVar7 + 0x2f);
    puVar7[0x34] = 0;
  }
  *param_7 = puVar7;
  return iVar3;
}



===== SpEnumerateAdapterAsynchronous @ 14001cf00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SpEnumerateAdapterAsynchronous(longlong *param_1,longlong *param_2)

{
  int *piVar1;
  longlong *plVar2;
  longlong *plVar3;
  int iVar4;
  longlong lVar5;
  
  plVar2 = param_1 + 0xa0;
  ExAcquireFastMutex(plVar2);
  plVar3 = param_1 + 0xae;
  LOCK();
  lVar5 = param_1[0xa8];
  *(int *)(param_1 + 0xa8) = 0;
  UNLOCK();
  if ((((int)lVar5 == 0) && ((char)*plVar3 == '\0')) &&
     ((ulonglong)(_DAT_fffff78000000014 - param_1[0xa7]) < 0x11e1a301)) {
    lVar5 = 0;
    ExReleaseFastMutex(plVar2);
    iVar4 = KeWaitForSingleObject(param_1 + 0x99,6,0,0,0);
    if ((char)param_2[4] == '\0') {
      lVar5 = param_2[3];
    }
    (*(code *)param_2[1])(param_1,param_2,iVar4);
    if (iVar4 == 0) {
      KeReleaseMutex(param_1 + 0x99,0);
    }
    if (lVar5 != 0) {
      SpCompleteEnumRequest(param_1,lVar5);
    }
  }
  else {
    LOCK();
    piVar1 = (int *)(*(longlong *)(*param_1 + 0x40) + 0x4c);
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    *param_2 = param_1[0xaf];
    param_1[0xaf] = (longlong)param_2;
    if ((char)*plVar3 == '\0') {
      *(char *)plVar3 = '\x01';
      ExQueueWorkItem(param_1 + 0xa9);
    }
    ExReleaseFastMutex(plVar2);
  }
  return;
}



===== SpEnumerationWorker @ 14001d060 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SpEnumerationWorker(longlong *param_1)

{
  int *piVar1;
  longlong lVar2;
  code *pcVar3;
  longlong ***ppplVar4;
  undefined8 uVar5;
  longlong ***ppplVar6;
  undefined1 *puVar7;
  undefined *puVar8;
  longlong *plVar9;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined8 local_28;
  longlong ***local_18;
  longlong ***local_10;
  
  local_28 = 0;
  local_10 = (longlong ***)&local_18;
  local_18 = (longlong ***)&local_18;
  plVar9 = (longlong *)0x0;
  puVar8 = (undefined *)0x0;
  param_1[0xad] = (longlong)SystemReserved1[0xf];
  uVar5 = 6;
  KeWaitForSingleObject(param_1 + 0x99);
  SpScanAdapter(param_1,uVar5,puVar8,plVar9);
  KeReleaseMutex(param_1 + 0x99,0);
  ExAcquireFastMutex(param_1 + 0xa0);
  puVar7 = auStack_48;
  param_1[0xa7] = _DAT_fffff78000000014;
  LOCK();
  piVar1 = (int *)(*(longlong *)(*param_1 + 0x40) + 0x4c);
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  while( true ) {
    plVar9 = (longlong *)param_1[0xaf];
    if (plVar9 == (longlong *)0x0) break;
    param_1[0xaf] = *plVar9;
    *plVar9 = 0;
    if ((char)plVar9[4] == '\0') {
      ppplVar4 = (longlong ***)(plVar9[3] + 0xa8);
      if ((longlong ****)*local_10 != &local_18) goto LAB_14001d1cf;
      *(longlong ****)(plVar9[3] + 0xb0) = local_10;
      *ppplVar4 = (longlong **)&local_18;
      *local_10 = (longlong **)ppplVar4;
      local_10 = ppplVar4;
    }
    SpReleaseRemoveLock(*param_1,(char)plVar9);
    (*(code *)plVar9[1])(param_1,plVar9,0);
  }
  param_1[0xad] = 0;
  *(undefined1 *)(param_1 + 0xae) = 0;
  ExReleaseFastMutex(param_1 + 0xa0);
  while ((longlong ****)local_18 != &local_18) {
    if (((longlong ****)local_18[1] != &local_18) ||
       (ppplVar4 = (longlong ***)*local_18, (longlong ***)ppplVar4[1] != local_18))
    goto LAB_14001d1cf;
    ppplVar4[1] = (longlong **)&local_18;
    ppplVar6 = local_18 + -0x15;
    local_18 = ppplVar4;
    SpCompleteEnumRequest(param_1,(longlong)ppplVar6);
  }
LAB_14001d1d6:
  lVar2 = *param_1;
  *(undefined8 *)(puVar7 + -8) = 0x14001d1e5;
  SpReleaseRemoveLock(lVar2,(char)param_1 + 'H');
  return;
LAB_14001d1cf:
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  puVar7 = auStack_40;
  goto LAB_14001d1d6;
}



===== SpExtractDeviceRelations @ 14001d204 =====

undefined8 SpExtractDeviceRelations(longlong *param_1,undefined8 param_2,undefined8 *param_3)

{
  byte *pbVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong *plVar4;
  uint *_Dst;
  uint uVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  ulonglong _Size;
  undefined8 uVar9;
  int iVar10;
  byte *local_res8;
  uint local_res10;
  
  lVar2 = *param_1;
  iVar10 = 0;
  uVar9 = 0;
  uVar3 = KeWaitForSingleObject(param_1 + 0x99,0,0,0,0);
  if ((int)uVar3 == 0xc0) {
    uVar3 = 0xc0000240;
  }
  else if (-1 < (int)uVar3) {
    bVar7 = 0;
    pbVar1 = (byte *)(param_1 + 0x2f);
    if (*pbVar1 != 0) {
      do {
        bVar8 = 0;
        if (*(char *)((longlong)param_1 + 0x179) != '\0') {
          do {
            bVar6 = 0;
            do {
              uVar9 = CONCAT71((int7)((ulonglong)uVar9 >> 8),bVar8);
              plVar4 = GetLogicalUnitExtension((longlong)param_1,bVar7,(uint)uVar9,bVar6,0,'\x01');
              if ((((plVar4 != (longlong *)0x0) && (*(char *)((longlong)plVar4 + 0x14b) == '\0')) &&
                  (*(char *)((longlong)plVar4 + 0x14c) != '\0')) &&
                 (*(uint *)((longlong)plVar4 + 0xc) < 2)) {
                iVar10 = iVar10 + 1;
              }
              bVar6 = bVar6 + 1;
            } while (bVar6 != 0xff);
            bVar8 = bVar8 + 1;
          } while (bVar8 < *(byte *)((longlong)param_1 + 0x179));
        }
        bVar7 = bVar7 + 1;
      } while (bVar7 < *pbVar1);
    }
    local_res8 = (byte *)(param_1 + 0x2f);
    uVar5 = iVar10 * 8 + 0x10;
    _Size = (ulonglong)uVar5;
    _Dst = (uint *)SpAllocatePoolEx(1,(ulonglong)uVar5,0x75506353,*(undefined8 *)(lVar2 + 8),
                                    0x656e756d,0x181);
    if (_Dst == (uint *)0x0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 0xe & 1) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_D(WPP_GLOBAL_Control[3],10,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,uVar5);
      }
      KeReleaseMutex(param_1 + 0x99,0);
      uVar3 = 0xc000009a;
    }
    else {
      memset(_Dst,0,_Size);
      uVar5 = 0;
      bVar7 = 0;
      local_res10 = 0;
      if (*pbVar1 != 0) {
        uVar5 = 0;
        do {
          bVar8 = 0;
          if (*(char *)((longlong)param_1 + 0x179) != '\0') {
            do {
              bVar6 = 0;
              do {
                _Size = CONCAT71((int7)(_Size >> 8),bVar8);
                plVar4 = GetLogicalUnitExtension((longlong)param_1,bVar7,(uint)_Size,bVar6,0,'\x01')
                ;
                if (plVar4 != (longlong *)0x0) {
                  if (*(char *)((longlong)plVar4 + 0x14b) == '\0') {
                    if ((*(uint *)((longlong)plVar4 + 0xc) < 2) &&
                       (*(char *)((longlong)plVar4 + 0x14c) != '\0')) {
                      _Size = 0;
                      iVar10 = ObReferenceObjectByPointer(*plVar4,0,0,0);
                      if (iVar10 < 0) {
                        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 0xe & 1) != 0)) &&
                           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                          WPP_SF_Lq(WPP_GLOBAL_Control[3],0xc,_Size,iVar10,
                                    (char)*(undefined8 *)(_Dst + (ulonglong)local_res10 * 2 + 2));
                        }
                      }
                      else {
                        *(longlong *)(_Dst + (ulonglong)local_res10 * 2 + 2) = *plVar4;
                        local_res10 = local_res10 + 1;
                        *(undefined1 *)((longlong)plVar4 + 0x14a) = 1;
                      }
                    }
                    else {
                      *(undefined1 *)((longlong)plVar4 + 0x14a) = 0;
                    }
                  }
                  else {
                    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 0xe & 1) != 0)) &&
                       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                      _Size = (ulonglong)bVar7;
                      WPP_SF_qddd(WPP_GLOBAL_Control[3],(ulonglong)bVar8,_Size,*plVar4,bVar7,bVar8,
                                  bVar6);
                    }
                    *(undefined1 *)((longlong)plVar4 + 0x14a) = 0;
                  }
                }
                bVar6 = bVar6 + 1;
              } while (bVar6 != 0xff);
              bVar8 = bVar8 + 1;
              uVar5 = local_res10;
            } while (bVar8 < *(byte *)((longlong)param_1 + 0x179));
          }
          bVar7 = bVar7 + 1;
        } while (bVar7 < *local_res8);
      }
      *_Dst = uVar5;
      *param_3 = _Dst;
      KeReleaseMutex(param_1 + 0x99,0);
      uVar3 = 0;
    }
  }
  return uVar3;
}



===== SpGetDeviceIdentifiers @ 14001d558 =====

undefined8 SpGetDeviceIdentifiers(longlong *param_1,char param_2,size_t param_3)

{
  char cVar1;
  uint uVar2;
  void *_Src;
  int iVar3;
  undefined4 extraout_var;
  longlong lVar4;
  undefined4 extraout_var_00;
  undefined8 uVar5;
  ulonglong uVar6;
  byte *pbVar7;
  byte bVar8;
  uint uVar9;
  undefined8 uVar10;
  byte local_res10 [8];
  undefined8 local_28;
  undefined8 uStack_20;
  
  pbVar7 = (byte *)(param_1 + 0x1f6);
  uVar9 = 0;
  local_res10[0] = 0;
  _Src = *(void **)(param_1[0x2d] + 0x6e8);
  if ((param_2 != '\0') || ((*pbVar7 & 1) != 0)) {
    uVar2 = *(uint *)(param_1 + 0x1f5);
    if (uVar2 == 0) {
      param_3 = 0;
      iVar3 = IssueInquiry(param_1,'\x01',0,_Src,local_res10);
      uVar5 = CONCAT44(extraout_var,iVar3);
      if ((iVar3 < 0) || (local_res10[0] < 4)) goto LAB_14001d871;
      uVar6 = 0;
      if (*(char *)((longlong)_Src + 3) != '\0') {
        do {
          cVar1 = *(char *)(uVar6 + 4 + (longlong)_Src);
          if (cVar1 == -0x80) {
            if (param_2 != '\0') {
              *(byte *)(param_1 + 0x1f6) = *(byte *)(param_1 + 0x1f6) | 2;
            }
          }
          else if (cVar1 == -0x7d) {
            *(byte *)(param_1 + 0x1f6) = *(byte *)(param_1 + 0x1f6) | 1;
          }
          bVar8 = (char)uVar6 + 1;
          uVar6 = (ulonglong)bVar8;
        } while (bVar8 < *(byte *)((longlong)_Src + 3));
      }
    }
    else {
      *pbVar7 = (byte)(uVar2 >> 1) & 1 | ((byte)uVar2 & 1) * '\x02' | *pbVar7 & 0xfc;
    }
    pbVar7 = (byte *)(param_1 + 0x1f6);
    if (((*pbVar7 & 1) != 0) && (param_1[0x1f9] == 0)) {
      param_3 = 0x79506353;
      lVar4 = SpAllocatePoolEx(1,0xff,0x79506353,*(undefined8 *)(*(longlong *)param_1[0x2d] + 8),
                               0x656e756d,0x1215);
      *(undefined4 *)(param_1 + 0x1fa) = 0;
      if (lVar4 == 0) {
        *pbVar7 = *pbVar7 & 0xfe;
      }
      else {
        param_1[0x1f9] = lVar4;
      }
    }
  }
  if ((*(byte *)(param_1 + 0x1f6) & 2) != 0) {
    uVar10 = CONCAT71((int7)(param_3 >> 8),0x80);
    local_28 = 0;
    uStack_20 = 0;
    iVar3 = IssueInquiry(param_1,'\x01',0x80,_Src,local_res10);
    uVar5 = CONCAT44(extraout_var_00,iVar3);
    if (iVar3 < 0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        uVar5 = WPP_SF_Lq(WPP_GLOBAL_Control[3],0x3e,uVar10,iVar3,(char)param_1);
      }
      goto LAB_14001d871;
    }
    param_3 = 0xfc - (ulonglong)*(byte *)((longlong)_Src + 3);
    memset((void *)((ulonglong)*(byte *)((longlong)_Src + 3) + 4 + (longlong)_Src),0,param_3);
    if (*(int *)((longlong)param_1 + 0xfac) != 0) {
      pbVar7 = (byte *)((longlong)_Src + 4);
      iVar3 = 0;
      if (*(char *)((longlong)_Src + 3) != '\0') {
        do {
          bVar8 = *pbVar7;
          if (bVar8 < 10) {
            bVar8 = bVar8 + 0x30;
LAB_14001d738:
            *pbVar7 = bVar8;
          }
          else if (bVar8 < 0x10) {
            bVar8 = bVar8 + 0x41;
            goto LAB_14001d738;
          }
          pbVar7 = pbVar7 + 1;
          iVar3 = iVar3 + 1;
        } while (iVar3 < (int)(uint)*(byte *)((longlong)_Src + 3));
      }
    }
    RtlInitAnsiString(&local_28,(longlong)_Src + 4);
    if (param_2 == '\0') {
      if ((param_1[0x1f8] != 0) || ((short)local_28 == 0)) {
        param_3 = 0;
        uVar6 = RtlEqualString(&local_28,param_1 + 0x1f7,0);
        if ((char)uVar6 == '\0') {
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
             (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            uVar6 = WPP_SF_(WPP_GLOBAL_Control[3],0x3f,
                            &WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids);
          }
          return uVar6 & 0xffffffffffffff00;
        }
      }
    }
    else {
      RtlCopyString(param_1 + 0x1f7,&local_28);
    }
  }
  if ((*(byte *)(param_1 + 0x1f6) & 1) != 0) {
    uVar5 = CONCAT71((int7)(param_3 >> 8),0x83);
    iVar3 = IssueInquiry(param_1,'\x01',0x83,_Src,local_res10);
    if (iVar3 < 0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_Lq(WPP_GLOBAL_Control[3],0x40,uVar5,iVar3,(char)param_1);
      }
    }
    else {
      memcpy((void *)param_1[0x1f9],_Src,(ulonglong)local_res10[0]);
      uVar9 = (uint)local_res10[0];
    }
  }
  uVar5 = 0xfd0;
  *(uint *)(param_1 + 0x1fa) = uVar9;
LAB_14001d871:
  return CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
}



===== SpGetInquiryData @ 14001d890 =====

ulonglong SpGetInquiryData(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  byte bVar2;
  longlong lVar3;
  byte *pbVar4;
  undefined8 uVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  ulonglong uVar9;
  longlong *plVar10;
  ulonglong uVar11;
  byte *pbVar12;
  uint uVar13;
  undefined *puVar14;
  byte bVar15;
  byte local_res8;
  byte local_res18;
  uint local_58;
  
  uVar13 = 0;
  puVar14 = (undefined *)0x0;
  uVar9 = KeWaitForSingleObject(param_1 + 0x4c8,6,0,0,0);
  if ((int)uVar9 == 0xc0) {
    uVar9 = 0xc0000240;
  }
  else if (-1 < (int)uVar9) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
       (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      puVar14 = &WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids;
      WPP_SF_(WPP_GLOBAL_Control[3],0x11,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids);
    }
    bVar2 = *(byte *)(param_1 + 0x178);
    lVar3 = *(longlong *)(param_2 + 0xb8);
    pbVar4 = *(byte **)(param_2 + 0x18);
    iVar7 = SpCountLogicalUnits(param_1);
    uVar8 = (bVar2 - 1) * 8 + 0xc + iVar7 * 0x34;
    if (*(uint *)(lVar3 + 8) < uVar8) {
      uVar13 = 0xc0000023;
    }
    else {
      *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar8;
      uVar9 = 0;
      local_res8 = 0;
      pbVar12 = pbVar4 + (ulonglong)(bVar2 - 1) * 8 + 0xc;
      *pbVar4 = bVar2;
      if (bVar2 != 0) {
        local_58 = 0;
        do {
          pbVar4[uVar9 * 8 + 5] = *(byte *)(*(longlong *)(param_1 + 0x1f8) + 0x49 + uVar9);
          *(int *)(pbVar4 + uVar9 * 8 + 8) = (int)pbVar12 - (int)pbVar4;
          pbVar4[uVar9 * 8 + 4] = 0;
          local_res18 = 0;
          uVar11 = uVar9;
          bVar15 = (byte)uVar9;
          if (*(char *)(param_1 + 0x179) == '\0') {
LAB_14001db56:
            local_res8 = bVar15;
            pbVar1 = pbVar4 + uVar9 * 8 + 8;
            pbVar1[0] = 0;
            pbVar1[1] = 0;
            pbVar1[2] = 0;
            pbVar1[3] = 0;
          }
          else {
            do {
              bVar15 = 0;
              do {
                puVar14 = (undefined *)CONCAT71((int7)((ulonglong)puVar14 >> 8),local_res18);
                plVar10 = GetLogicalUnitExtension
                                    (param_1,(char)uVar11,(uint)puVar14,bVar15,param_2,'\x01');
                if (plVar10 != (longlong *)0x0) {
                  if (((*(char *)((longlong)plVar10 + 0x14b) == '\0') &&
                      (*(int *)((longlong)plVar10 + 0xc) == 0)) &&
                     (cVar6 = SpIsInitiatorLU((longlong)plVar10), cVar6 == '\0')) {
                    pbVar4[uVar9 * 8 + 4] = pbVar4[uVar9 * 8 + 4] + 1;
                    if ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
                      if (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0) &&
                         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                        puVar14 = &WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids;
                        WPP_SF_ddd(WPP_GLOBAL_Control[3],0x12,
                                   &WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,local_58,
                                   local_res18,bVar15);
                      }
                      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
                         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                        puVar14 = &WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids;
                        WPP_SF_D(WPP_GLOBAL_Control[3],0x13,
                                 &WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,
                                 (uint)pbVar4[uVar9 * 8 + 4]);
                      }
                    }
                    *pbVar12 = local_res8;
                    pbVar12[1] = local_res18;
                    pbVar12[2] = bVar15;
                    pbVar12[3] = *(byte *)(plVar10 + 0x29);
                    pbVar12[4] = 0x24;
                    pbVar12[5] = 0;
                    pbVar12[6] = 0;
                    pbVar12[7] = 0;
                    *(int *)(pbVar12 + 8) = ((int)pbVar12 - (int)pbVar4) + 0x34;
                    uVar5 = *(undefined8 *)((longlong)plVar10 + 0x202);
                    *(undefined8 *)(pbVar12 + 0xc) = *(undefined8 *)((longlong)plVar10 + 0x1fa);
                    *(undefined8 *)(pbVar12 + 0x14) = uVar5;
                    uVar5 = *(undefined8 *)((longlong)plVar10 + 0x212);
                    *(undefined8 *)(pbVar12 + 0x1c) = *(undefined8 *)((longlong)plVar10 + 0x20a);
                    *(undefined8 *)(pbVar12 + 0x24) = uVar5;
                    *(undefined4 *)(pbVar12 + 0x2c) = *(undefined4 *)((longlong)plVar10 + 0x21a);
                    pbVar12 = pbVar12 + 0x34;
                  }
                  SpReleaseRemoveLock(*plVar10,(char)param_2);
                }
                uVar11 = (ulonglong)local_res8;
                bVar15 = bVar15 + 1;
              } while (bVar15 != 0xff);
              local_res18 = local_res18 + 1;
            } while (local_res18 < *(byte *)(param_1 + 0x179));
            bVar15 = local_res8;
            if (pbVar4[uVar9 * 8 + 4] == 0) goto LAB_14001db56;
            pbVar12[-0x2c] = 0;
            pbVar12[-0x2b] = 0;
            pbVar12[-0x2a] = 0;
            pbVar12[-0x29] = 0;
          }
          local_res8 = local_res8 + 1;
          uVar9 = (ulonglong)local_res8;
          puVar14 = (undefined *)0x0;
          local_58 = (uint)local_res8;
        } while (local_58 < bVar2);
      }
      if ((ulonglong)((longlong)pbVar12 - (longlong)pbVar4) < (ulonglong)uVar8) {
        *(longlong *)(param_2 + 0x38) = (longlong)pbVar12 - (longlong)pbVar4;
      }
    }
    *(uint *)(param_2 + 0x30) = uVar13;
    KeReleaseMutex(param_1 + 0x4c8,0);
    return (ulonglong)uVar13;
  }
  *(int *)(param_2 + 0x30) = (int)uVar9;
  return uVar9;
}



===== SpInquireLogicalUnit @ 14001dbc0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014001e20f) */

int SpInquireLogicalUnit
              (longlong param_1,byte param_2,undefined1 param_3,byte param_4,char param_5,
              longlong *param_6,undefined8 *param_7,undefined1 *param_8)

{
  int *piVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  longlong *plVar6;
  undefined8 uVar7;
  byte *_Buf2;
  undefined7 uVar10;
  longlong *plVar8;
  code *pcVar9;
  byte bVar11;
  size_t sVar12;
  char *pcVar13;
  char cVar14;
  byte bVar15;
  undefined1 auStackY_138 [32];
  char local_f6;
  byte local_f4;
  byte local_f3;
  byte local_f2;
  byte local_f1;
  longlong *local_f0;
  undefined1 *local_e8;
  undefined8 *local_e0;
  longlong local_d8 [2];
  undefined8 local_c8;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_138;
  uVar7 = 0;
  local_e0 = param_7;
  local_e8 = param_8;
  local_d8[0] = param_1;
  memset(&local_c8,0,0x68);
  *param_7 = 0;
  cVar14 = '\0';
  cVar3 = '\0';
  local_f6 = '\0';
  local_f2 = 0;
  *param_8 = 1;
  plVar6 = GetLogicalUnitExtension
                     (local_d8[0],param_2,(uint)CONCAT71((int7)((ulonglong)uVar7 >> 8),param_3),
                      param_4,0x14001dbc0,'\x01');
  local_f0 = plVar6;
  if (plVar6 == (longlong *)0x0) {
    if (param_6 == (longlong *)0x0) {
      return -0x3fffff66;
    }
    LOCK();
    piVar1 = (int *)(*(longlong *)(*param_6 + 0x40) + 0x4c);
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    LOCK();
    piVar1 = (int *)(*(longlong *)(*param_6 + 0x40) + 0x4c);
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    *(byte *)((longlong)param_6 + 0x154) = param_2;
    *(undefined1 *)((longlong)param_6 + 0x155) = param_3;
    *(byte *)((longlong)param_6 + 0x156) = param_4;
    SpAddLogicalUnitToBin(param_6[0x2d],(longlong)param_6);
    bVar2 = true;
    local_f0 = param_6;
    local_f6 = '\x01';
  }
  else {
    if (*(char *)((longlong)plVar6 + 0x14b) != '\0') {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 0xe & 1) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_dddq(WPP_GLOBAL_Control[3],0x32,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,
                    (uint)param_2,param_3,param_4,(char)*plVar6);
      }
      SpReleaseRemoveLock(*plVar6,0xc0);
      return -0x3fffff40;
    }
    bVar2 = false;
  }
  plVar6 = local_f0;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 0xe & 1) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    pcVar13 = "new";
    if (!bVar2) {
      pcVar13 = "existing";
    }
    WPP_SF_sddd(WPP_GLOBAL_Control[3],0x33,(ulonglong)(uint)param_2,pcVar13,param_2,param_3,param_4)
    ;
  }
  sVar12 = 0;
  pcVar13 = (char *)&local_c8;
  iVar4 = IssueInquiry(plVar6,'\0',0,pcVar13,&local_f2);
  if (iVar4 < 0) {
    *local_e8 = 0;
  }
  else {
    _Buf2 = (byte *)&local_c8;
    bVar11 = (byte)local_c8 >> 5;
    SpCheckSpecialDeviceFlags(plVar6,_Buf2);
    if (bVar11 == 0) {
LAB_14001ddec:
      if (local_f6 != '\0') {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 0xe & 1) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          pcVar13 = "Removable ";
          if ((local_c8._1_1_ & 0x80) == 0) {
            pcVar13 = "";
          }
          _Buf2 = (byte *)0x0;
          WPP_SF_sddd(WPP_GLOBAL_Control[3],0x39,sVar12,pcVar13,param_2,param_3,param_4);
        }
LAB_14001e065:
        uVar10 = (undefined7)((ulonglong)_Buf2 >> 8);
        uVar7 = SpGetDeviceIdentifiers(plVar6,local_f6,sVar12);
        cVar3 = (char)uVar7;
        if (cVar3 == '\0') {
          iVar4 = -0x3ffffff2;
        }
        if (-1 < iVar4) {
          *(undefined1 *)((longlong)plVar6 + 0x14b) = 0;
          if (local_f6 == '\0') {
            plVar8 = (longlong *)CONCAT71(uVar10,(byte)local_c8);
            bVar11 = *(byte *)((longlong)plVar6 + 0x1fa);
            if (((bVar11 ^ (byte)local_c8) & 0xe0) != 0) {
              plVar8 = (longlong *)(CONCAT71(uVar10,(byte)local_c8) & 0xffffffffffffffe0);
              *(byte *)((longlong)plVar6 + 0x1fa) = bVar11 & 0x1f | (byte)plVar8;
              local_d8[0] = 0;
              local_d8[1] = 0;
              if ((plVar6[0x4d] != 0) && (plVar6[0x4e] != 0)) {
                RtlInitUnicodeString(local_d8,L"InquiryData");
                plVar8 = local_d8;
                pcVar13 = (char *)0x3;
                sVar12 = 0;
                ZwSetValueKey(plVar6[0x4e]);
              }
            }
          }
          else {
            sVar12 = (size_t)local_f2;
            pcVar13 = (char *)&local_f0;
            plVar8 = &local_c8;
            iVar4 = SpCloneAndSwapLogicalUnit(plVar6,plVar8,sVar12,(undefined8 *)pcVar13);
            plVar6 = local_f0;
            if (iVar4 < 0) {
              plVar6 = (longlong *)0x0;
            }
          }
          if (plVar6 != (longlong *)0x0) {
            if ((*(byte *)((longlong)plVar6 + 0x1fa) & 0xe0) == 0x20) {
              *(undefined1 *)((longlong)plVar6 + 0x14c) = 0;
              if ((*(byte *)(plVar6 + 1) & 1) == 0) {
                SpBuildAdapterDeviceMap(plVar6,plVar8,sVar12,pcVar13);
              }
              else {
                SpBuildLogicalUnitDeviceMapEntry((longlong)plVar6,plVar8,sVar12,(longlong)pcVar13);
              }
            }
            else {
              *(undefined1 *)((longlong)plVar6 + 0x14c) = 1;
            }
            if ((local_c8._1_1_ & 0x80) != 0) {
              *(uint *)(*plVar6 + 0x34) = *(uint *)(*plVar6 + 0x34) | 1;
            }
          }
          *local_e0 = plVar6;
          goto LAB_14001e30e;
        }
        goto LAB_14001e248;
      }
      bVar11 = *(byte *)((longlong)plVar6 + 0x1fa);
      if (((bVar11 ^ (byte)local_c8) & 0x1f) != 0) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 0xe & 1) != 0)) &&
           (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_ddd(WPP_GLOBAL_Control[3],0x34,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,
                     (uint)param_2,param_3,param_4);
        }
LAB_14001de53:
        cVar14 = '\x01';
        goto LAB_14001e23c;
      }
      if (((bVar11 ^ (byte)local_c8) & 0xe0) != 0) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 0xe & 1) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          pcVar13 = (char *)(ulonglong)param_2;
          WPP_SF_ddddd(WPP_GLOBAL_Control[3],(ulonglong)(bVar11 >> 5),
                       (ulonglong)((byte)local_c8 >> 5),(uint)param_2,param_3,param_4,bVar11 >> 5,
                       (byte)local_c8 >> 5);
        }
        if ((*(byte *)((longlong)plVar6 + 0x1fa) & 0xe0) == 0x20) {
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 0xe & 1) != 0)) &&
             (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_(WPP_GLOBAL_Control[3],0x36,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids);
          }
          goto LAB_14001de53;
        }
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 0xe & 1) != 0)) &&
           (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_(WPP_GLOBAL_Control[3],0x37,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids);
        }
        iVar4 = 0;
      }
      local_f1 = local_c8._2_1_ & 7;
      local_f4 = 0;
      local_f3 = 0;
      if (local_f1 == 3) {
        local_f4 = local_c8._6_1_;
        local_f3 = local_c8._7_1_;
        local_c8._7_1_ = (local_c8._7_1_ ^ *(byte *)((longlong)plVar6 + 0x201)) & 1 ^ local_c8._7_1_
        ;
        local_c8._6_1_ = (local_c8._6_1_ ^ *(byte *)(plVar6 + 0x40)) & 0x20 ^ local_c8._6_1_;
      }
      bVar15 = local_c8._7_1_;
      bVar11 = local_c8._6_1_;
      _Buf2 = (byte *)((longlong)plVar6 + 0x1fb);
      sVar12 = 0x1f;
      iVar5 = memcmp((void *)((longlong)&local_c8 + 1),_Buf2,0x1f);
      if (local_f1 == 3) {
        local_c8._6_1_ = local_f4;
        local_c8._7_1_ = local_f3;
        bVar11 = local_f4;
        bVar15 = local_f3;
      }
      if (iVar5 == 0) {
        if (local_f1 == 3) {
          *(byte *)(plVar6 + 0x40) = bVar11;
          *(byte *)((longlong)plVar6 + 0x201) = bVar15;
        }
        goto LAB_14001e065;
      }
      cVar3 = '\x01';
      iVar4 = -0x3ffffff2;
      cVar14 = '\x01';
      if ((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_14001e23c;
      if ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 0xe & 1) == 0) goto LAB_14001e248;
      if (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 4) goto LAB_14001e23c;
      WPP_SF_ddd(WPP_GLOBAL_Control[3],0x38,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,
                 (uint)param_2,param_3,param_4);
    }
    else {
      if (bVar11 != 1) {
        if (bVar11 == 3) goto LAB_14001e23c;
        goto LAB_14001ddec;
      }
      if (param_4 == 0) {
        if (((local_c8._3_1_ & 0x10) != 0) || ((int)plVar6[500] == 1)) goto LAB_14001ddec;
      }
      else if (param_5 != '\0') goto LAB_14001ddec;
LAB_14001e23c:
      cVar3 = cVar14;
    }
    iVar4 = -0x3ffffff2;
  }
LAB_14001e248:
  *(undefined1 *)((longlong)plVar6 + 0x14b) = 1;
  if (local_f6 == '\0') {
    if (*(char *)((longlong)plVar6 + 0x14a) == '\0') {
      *(undefined1 *)((longlong)plVar6 + 9) = 2;
      pcVar9 = SpInquireLogicalUnit;
      SpReleaseRemoveLock(*plVar6,0xc0);
      *(undefined1 *)((longlong)plVar6 + 0x14c) = 1;
      SpRemoveLogicalUnit(plVar6,CONCAT71((int7)((ulonglong)pcVar9 >> 8),2));
      if (cVar3 == '\0') {
        return iVar4;
      }
      iVar4 = SpInquireLogicalUnit
                        (local_d8[0],param_2,param_3,param_4,param_5,param_6,local_e0,local_e8);
      return iVar4;
    }
    if (cVar3 != '\0') {
      *(undefined1 *)((longlong)plVar6 + 0x14d) = 1;
    }
  }
  else {
    SpReleaseRemoveLock(*plVar6,0xc0);
    plVar6 = (longlong *)0x0;
    SpWaitForRemoveLock(*param_6,0xcd);
    SpRemoveLogicalUnitFromBin(param_6[0x2d],(longlong)param_6);
    *(undefined2 *)((longlong)param_6 + 0x154) = 0xffff;
    *(undefined1 *)((longlong)param_6 + 0x156) = 0xff;
  }
LAB_14001e30e:
  if (plVar6 != (longlong *)0x0) {
    SpReleaseRemoveLock(*plVar6,0xc0);
  }
  return iVar4;
}



===== SpPrepareLogicalUnitForReuse @ 14001e34c =====

undefined8 SpPrepareLogicalUnitForReuse(longlong *param_1)

{
  uint uVar1;
  longlong lVar2;
  void *_Dst;
  
  lVar2 = param_1[0x2d];
  KeClearEvent(param_1 + 10);
  _Dst = (void *)param_1[0x2c];
  *(undefined2 *)((longlong)param_1 + 0x154) = 0xffff;
  *(undefined1 *)((longlong)param_1 + 0x156) = 0xff;
  if (_Dst == (void *)0x0) {
    uVar1 = *(uint *)(lVar2 + 0x264);
    if (uVar1 == 0) goto LAB_14001e3e8;
    _Dst = (void *)SpAllocatePoolEx(4,(ulonglong)uVar1,0x48506353,*(undefined8 *)(*param_1 + 8),
                                    0x656e756d,0xd6f);
    if (_Dst == (void *)0x0) {
      return 0xc000009a;
    }
    param_1[0x2c] = (longlong)_Dst;
  }
  memset(_Dst,0,(ulonglong)*(uint *)(lVar2 + 0x264));
LAB_14001e3e8:
  *(byte *)(param_1 + 0x1f6) = *(byte *)(param_1 + 0x1f6) & 0xfc;
  *(undefined2 *)((longlong)param_1 + 0x14b) = 0;
  *(undefined4 *)((longlong)param_1 + 0xc) = 0;
  memset((void *)param_1[0x1f8],0,(ulonglong)*(ushort *)((longlong)param_1 + 0xfba));
  *(undefined2 *)(param_1 + 0x1f7) = 0;
  return 0;
}



===== SpScanAdapter @ 14001e430 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SpScanAdapter(longlong *param_1,undefined8 param_2,undefined *param_3,longlong *param_4)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  longlong *plVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined7 uVar7;
  byte bVar8;
  byte bVar9;
  undefined8 *puVar10;
  undefined7 uVar12;
  undefined *puVar11;
  char cVar13;
  byte bVar14;
  undefined1 auStackY_f8 [32];
  longlong local_b8;
  undefined8 local_b0;
  longlong *local_a8;
  longlong local_a0;
  wchar_t local_98 [8];
  undefined8 local_88;
  undefined8 local_80;
  longlong lStack_78;
  wchar_t *local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  ulonglong uStack_58;
  wchar_t *local_50 [3];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_f8;
  lVar1 = *param_1;
  cVar13 = '\0';
  local_a8 = (longlong *)0x0;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    param_2 = 0;
    param_3 = &WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids;
    param_4 = param_1;
    WPP_SF_q(WPP_GLOBAL_Control[3],0x15,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,param_1);
  }
  iVar2 = SpCreateLogicalUnit(param_1,CONCAT71((int7)((ulonglong)param_2 >> 8),0xff),
                              CONCAT71((int7)((ulonglong)param_3 >> 8),0xff),
                              CONCAT71((int7)((ulonglong)param_4 >> 8),0xff),'\x01','\0',&local_a8);
  if (-1 < iVar2) {
    local_88 = MmLockPagableDataSection(GetNextLuRequestWithoutLock);
    LOCK();
    _SpPAGELOCKLockCount = _SpPAGELOCKLockCount + 1;
    UNLOCK();
    bVar8 = 0;
    do {
      local_b8 = 0;
      local_b0 = 0;
      local_50[0] = L"Scsiport";
      local_50[1] = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\ScsiPort\\";
      local_50[2] = L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\Disk";
      local_60 = 0;
      uStack_58 = uStack_58 & 0xffffffff00000000;
      local_a0 = 0;
      local_98[0] = L'\0';
      local_98[1] = L'\0';
      local_98[2] = L'\0';
      local_98[3] = L'\0';
      local_98[4] = L'\0';
      local_98[5] = L'\0';
      local_98[6] = L'\0';
      local_98[7] = L'\0';
      local_80 = 0;
      lStack_78 = 0;
      local_70 = (wchar_t *)0x0;
      uStack_68 = 0;
      if (bVar8 == 0) {
        puVar10 = (undefined8 *)0x20019;
        uVar6 = 0;
        iVar2 = IoOpenDeviceRegistryKey(param_1[0x28],1,0x20019,&local_b8);
        if (-1 < iVar2) goto LAB_14001e5b2;
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
           (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          puVar10 = (undefined8 *)&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids;
          uVar6 = 0;
          WPP_SF_D(WPP_GLOBAL_Control[3],0x16,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,iVar2
                  );
        }
      }
      else {
LAB_14001e5b2:
        RtlInitUnicodeString(local_98,local_50[bVar8]);
        puVar10 = &local_80;
        lStack_78 = local_b8;
        local_70 = local_98;
        local_80 = CONCAT44(local_80._4_4_,0x30);
        uVar6 = 0x20019;
        uStack_68 = CONCAT44(uStack_68._4_4_,0x240);
        local_60 = 0;
        uStack_58 = 0;
        iVar2 = ZwOpenKey(&local_b0,0x20019);
        if (iVar2 < 0) {
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
             (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            uVar6 = 0;
            puVar10 = (undefined8 *)&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids;
            WPP_SF_LZ(WPP_GLOBAL_Control[3],0x17,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,
                      iVar2,local_98);
          }
          if (local_b8 != 0) {
            ZwClose();
          }
        }
        else {
          uVar6 = local_b0;
          uVar3 = SpGetRegistryValue(*(undefined8 *)(lVar1 + 8),local_b0,(ulonglong)puVar10,
                                     &local_a0);
          ZwClose(local_b0);
          if (local_b8 != 0) {
            ZwClose();
            local_b8 = 0;
          }
          if (-1 < (int)uVar3) {
            cVar13 = '\0';
            if ((*(int *)(local_a0 + 4) == 4) &&
               (*(int *)((ulonglong)*(uint *)(local_a0 + 8) + local_a0) != 0)) {
              cVar13 = '\x01';
            }
            uVar6 = 0;
            ExFreePoolWithTag(local_a0,0);
            break;
          }
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
             (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            uVar6 = 0;
            puVar10 = (undefined8 *)&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids;
            WPP_SF_LZ(WPP_GLOBAL_Control[3],0x18,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,
                      (int)uVar3,local_98);
          }
        }
      }
      bVar8 = bVar8 + 1;
    } while (bVar8 < 3);
    iVar2 = SpRequestValidAdapterPowerStateSynchronous(param_1);
    if (-1 < iVar2) {
      if (((char)param_1[0xfd] == '\x01') && (param_1[0xf5] == 0)) {
        plVar4 = SpCreateInitiatorLU(param_1,CONCAT71((int7)((ulonglong)uVar6 >> 8),
                                                      (char)param_1[0x2f] + -1),puVar10);
        param_1[0xf5] = (longlong)plVar4;
        if ((plVar4 == (longlong *)0x0) &&
           ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control &&
             ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
            (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
          puVar10 = (undefined8 *)&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids;
          WPP_SF_qd(WPP_GLOBAL_Control[3],0x19,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,
                    *param_1,(char)param_1[0x2f] + -1);
        }
      }
      bVar8 = 0;
      if ((char)param_1[0x2f] != '\0') {
        do {
          uVar3 = 0;
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
             (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            puVar10 = (undefined8 *)&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids;
            WPP_SF_D(WPP_GLOBAL_Control[3],0x1a,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,
                     (uint)bVar8);
          }
          bVar9 = *(byte *)((longlong)param_1 + 0x179);
          bVar14 = 0;
          if (bVar9 != 0) {
            do {
              if (*(char *)((longlong)param_1 + 0x3f9) == '\0') {
                bVar9 = bVar14;
              }
              else {
                bVar9 = (bVar9 - bVar14) - 1;
              }
              if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
                 (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                puVar10 = (undefined8 *)&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids;
                WPP_SF_DD(WPP_GLOBAL_Control[3],0x1b,
                          &WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,(uint)bVar14,bVar9);
              }
              if (bVar9 == *(byte *)((ulonglong)bVar8 + 0x49 + param_1[0x3f])) {
                if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
                   (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                  puVar10 = (undefined8 *)&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids;
                  WPP_SF_(WPP_GLOBAL_Control[3],0x1c,
                          &WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids);
                }
              }
              else {
                uVar12 = (undefined7)((ulonglong)puVar10 >> 8);
                uVar7 = 0x1400170;
                SpSetVerificationMarks((longlong)param_1,bVar8,bVar9);
                puVar11 = (undefined *)CONCAT71(uVar12,bVar9);
                *(undefined4 *)(local_a8 + 0x2a) = 1;
                uVar5 = SpScanTarget((longlong)param_1,CONCAT71(uVar7,bVar8),puVar11,cVar13,local_a8
                                    );
                puVar10 = (undefined8 *)CONCAT71((int7)((ulonglong)puVar11 >> 8),bVar9);
                uVar3 = uVar5 & 0xffffffff;
                SpPurgeTarget((longlong)param_1,bVar8,bVar9);
                if ((int)uVar5 < 0) goto LAB_14001e928;
              }
              bVar9 = *(byte *)((longlong)param_1 + 0x179);
              bVar14 = bVar14 + 1;
            } while (bVar14 < bVar9);
            if ((int)uVar3 < 0) break;
          }
          bVar8 = bVar8 + 1;
        } while (bVar8 < *(byte *)(param_1 + 0x2f));
      }
    }
LAB_14001e928:
    LOCK();
    _SpPAGELOCKLockCount = _SpPAGELOCKLockCount + -1;
    UNLOCK();
    MmUnlockPagableImageSection(local_88);
    SpDeleteLogicalUnit(local_a8);
  }
  return;
}



===== SpScanTarget @ 14001e97c =====

ulonglong SpScanTarget(longlong param_1,ulonglong param_2,undefined *param_3,char param_4,
                      longlong *param_5)

{
  byte bVar1;
  byte bVar2;
  undefined8 *puVar3;
  int iVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  byte bVar7;
  char cVar8;
  undefined8 **ppuVar9;
  undefined7 uVar10;
  ushort uVar11;
  uint uVar12;
  undefined8 *puVar13;
  undefined *puVar14;
  undefined1 uVar15;
  uint uVar16;
  longlong *plVar17;
  undefined8 *puVar18;
  char local_58;
  char local_57;
  char local_56;
  uint local_54;
  longlong *local_50;
  undefined8 *local_48 [2];
  
  bVar7 = (byte)param_2;
  local_50 = (longlong *)0x0;
  puVar13 = (undefined8 *)0x0;
  local_58 = '\0';
  local_48[0] = (undefined8 *)0x0;
  local_56 = '\0';
  uVar16 = (uint)param_2 & 0xff;
  uVar5 = param_2;
  puVar14 = param_3;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    uVar5 = 0;
    puVar14 = &WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids;
    WPP_SF_D(WPP_GLOBAL_Control[3],0x1d,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,
             (uint)param_3 & 0xff);
  }
  uVar15 = SUB81(param_3,0);
  puVar14 = (undefined *)CONCAT71((int7)((ulonglong)puVar14 >> 8),uVar15);
  ppuVar9 = (undefined8 **)CONCAT71((int7)(uVar5 >> 8),bVar7);
  iVar4 = SpInquireLogicalUnit(param_1,bVar7,uVar15,0,'\x01',param_5,&local_50,&local_58);
  uVar5 = SpPrepareLogicalUnitForReuse(param_5);
  local_54 = (uint)uVar5;
  plVar17 = (longlong *)0x0;
  if (-1 < (int)local_54) {
    plVar17 = param_5;
  }
  if ((iVar4 < 0) && ((local_58 != '\x01' || (local_50 == (longlong *)0x0)))) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_D(WPP_GLOBAL_Control[3],0x1e,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,iVar4);
    }
  }
  else {
    *(undefined4 *)(local_50 + 0x2a) = 0;
    if (*(int *)((longlong)local_50 + 0xf9c) == 0) {
      if (plVar17 != (longlong *)0x0) {
        plVar17[4] = local_50[4];
      }
      if ((int)local_50[499] == 0) {
        local_57 = '\0';
      }
      else {
        local_57 = '\x01';
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          puVar14 = &WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids;
          ppuVar9 = (undefined8 **)0x20;
          WPP_SF_DD(WPP_GLOBAL_Control[3],0x20,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,
                    uVar16,uVar15);
        }
      }
      if (((*(byte *)((longlong)local_50 + 0x1fd) & 0x10) != 0) || ((int)local_50[500] != 0)) {
        if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0 &&
            (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
          puVar14 = &WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids;
          WPP_SF_DD(WPP_GLOBAL_Control[3],0x21,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,
                    uVar16,uVar15);
        }
        ppuVar9 = local_48;
        local_56 = '\x01';
        iVar4 = IssueReportLuns(local_50,ppuVar9);
        if (iVar4 < 0) {
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
             (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_DDL(WPP_GLOBAL_Control[3],ppuVar9,puVar14,uVar16,uVar15,(char)iVar4);
          }
          puVar13 = (undefined8 *)local_50[0x1f2];
        }
        else {
          puVar13 = local_48[0];
        }
        if (((puVar13 != (undefined8 *)0x0) &&
            (local_57 = '\x01', (undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0 &&
            (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
          puVar14 = &WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids;
          ppuVar9 = (undefined8 **)0x23;
          WPP_SF_DD(WPP_GLOBAL_Control[3],0x23,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,
                    uVar16,uVar15);
        }
      }
      if (puVar13 == (undefined8 *)0x0) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          ppuVar9 = (undefined8 **)0x24;
          puVar14 = &WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids;
          WPP_SF_DD(WPP_GLOBAL_Control[3],0x24,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,
                    uVar16,uVar15);
        }
        puVar13 = (undefined8 *)&ScsiPortDefaultLunList;
        local_56 = '\0';
      }
      uVar12 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)puVar13,
                                          *(undefined1 *)((longlong)puVar13 + 1)),
                                 *(undefined1 *)((longlong)puVar13 + 2)),
                        *(undefined1 *)((longlong)puVar13 + 3)) >> 3;
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_DDd(WPP_GLOBAL_Control[3],ppuVar9,puVar14,uVar16,uVar15,(char)uVar12);
      }
      uVar16 = 0;
      if (uVar12 != 0) {
        puVar3 = puVar13;
        do {
          puVar18 = puVar3 + 1;
          local_48[0] = (undefined8 *)0x0;
          bVar1 = *(byte *)((longlong)puVar3 + 9);
          uVar11 = CONCAT11(*(undefined1 *)puVar18,bVar1) & 0x3fff;
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
             (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_iD(WPP_GLOBAL_Control[3],ppuVar9,puVar14,*puVar18,(char)uVar11);
          }
          if (uVar11 == 0) {
            if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
               (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              puVar14 = &WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids;
              ppuVar9 = (undefined8 **)0x27;
              WPP_SF_(WPP_GLOBAL_Control[3],0x27,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids);
            }
          }
          else {
            bVar2 = *(byte *)(*(longlong *)(param_1 + 0x1f8) + 0x92);
            ppuVar9 = (undefined8 **)(ulonglong)bVar2;
            if (uVar11 < bVar2) {
              ppuVar9 = (undefined8 **)(param_2 & 0xff);
              puVar14 = (undefined *)CONCAT71((int7)((ulonglong)puVar14 >> 8),uVar15);
              iVar4 = SpInquireLogicalUnit
                                (param_1,bVar7,uVar15,bVar1,param_4,plVar17,local_48,&local_58);
              if (plVar17 != (longlong *)0x0) {
                uVar6 = SpPrepareLogicalUnitForReuse(plVar17);
                local_54 = (uint)uVar6;
                if ((int)local_54 < 0) {
                  plVar17 = (longlong *)0x0;
                }
              }
              if (iVar4 < 0) {
                if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
                   (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                  puVar14 = &WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids;
                  ppuVar9 = (undefined8 **)0x0;
                  WPP_SF_D(WPP_GLOBAL_Control[3],0x2a,
                           &WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,iVar4);
                }
                puVar14 = (undefined *)CONCAT71((int7)((ulonglong)puVar14 >> 8),local_57);
                uVar10 = (undefined7)((ulonglong)ppuVar9 >> 8);
                ppuVar9 = (undefined8 **)CONCAT71(uVar10,local_58);
                if ((local_57 == '\0') && (local_58 == '\0')) {
                  if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0 &&
                      (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
                    WPP_SF_(WPP_GLOBAL_Control[3],0x2b,
                            &WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids);
                  }
                  break;
                }
                if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
                   (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                  uVar5 = CONCAT71(uVar10,-(local_58 != '\0')) & 0xffffffffffffff43;
                  cVar8 = (char)uVar5 + ' ';
                  ppuVar9 = (undefined8 **)CONCAT71((int7)(uVar5 >> 8),cVar8);
                  WPP_SF_cc(WPP_GLOBAL_Control[3],ppuVar9,puVar14,
                            (-(local_57 != '\0') & 0x53U) + 0x20,cVar8);
                }
              }
              else {
                if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
                   (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                  puVar14 = &WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids;
                  ppuVar9 = (undefined8 **)0x29;
                  WPP_SF_(WPP_GLOBAL_Control[3],0x29,
                          &WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids);
                }
                *(undefined4 *)(local_48[0] + 0x2a) = 0;
              }
            }
            else if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
                    (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              puVar14 = &WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids;
              ppuVar9 = (undefined8 **)0x28;
              WPP_SF_D(WPP_GLOBAL_Control[3],0x28,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,
                       (uint)bVar2);
            }
          }
          uVar16 = uVar16 + 1;
          puVar3 = puVar18;
        } while (uVar16 < uVar12);
      }
      if (local_56 != '\0') {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_q(WPP_GLOBAL_Control[3],0x2d,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,
                   puVar13);
        }
        puVar3 = (undefined8 *)local_50[0x1f2];
        if ((puVar3 != (undefined8 *)0x0) && (puVar3 != puVar13)) {
          if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0 &&
              (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
            WPP_SF_q(WPP_GLOBAL_Control[3],0x2e,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,
                     puVar3);
          }
          ExFreePoolWithTag(local_50[0x1f2],0);
        }
        local_50[0x1f2] = (longlong)puVar13;
      }
      if (plVar17 != (longlong *)0x0) {
        plVar17[4] = (longlong)&DeviceMajorFunctionTable;
      }
      return (ulonglong)local_54;
    }
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_DD(WPP_GLOBAL_Control[3],0x1f,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,uVar16,
                uVar15);
    }
  }
  return uVar5 & 0xffffffff;
}



===== SpSignalEnumerationCompletion @ 14001f050 =====

void SpSignalEnumerationCompletion(undefined8 param_1,longlong param_2,undefined4 param_3)

{
  if (*(undefined4 **)(param_2 + 0x10) != (undefined4 *)0x0) {
    **(undefined4 **)(param_2 + 0x10) = param_3;
  }
  KeSetEvent(*(undefined8 *)(param_2 + 0x18),0,0);
  return;
}



===== ScsiPortInitialize @ 14001f090 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong ScsiPortInitialize(longlong param_1,wchar_t *param_2,undefined *param_3)

{
  code cVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  undefined2 uVar9;
  undefined *puVar10;
  code *pcVar11;
  char *pcVar12;
  longlong *plVar13;
  longlong local_res8;
  
                    /* 0x1f090  15  ScsiPortInitialize */
  uVar5 = 0xc000000d;
  pcVar12 = param_3;
  if (ScsiGlobalAdapterList == -1) {
    _WPP_MAIN_CB = (code *)0x0;
    DAT_140017248 = &WPP_ThisDir_CTLGUID_wppCtlGuid;
    DAT_140017250 = 0;
    _DAT_140017260 = 0;
    _DAT_140017268 = 1;
    pcVar11 = (code *)param_3;
    WppLoadTracingSupport();
    puVar10 = &WPP_MAIN_CB;
    _DAT_140017260 = 0;
    if (WPP_GLOBAL_Control != (undefined8 *)&WPP_MAIN_CB) {
      WPP_GLOBAL_Control = (undefined8 *)&WPP_MAIN_CB;
      if (WPPTraceSuite == 4) {
        do {
          *(undefined8 *)(puVar10 + 0x38) = 0;
          pcVar11 = WppClassicProviderCallback;
          (*pfnEtwRegisterClassicProvider)
                    (*(undefined8 *)(puVar10 + 8),0,WppClassicProviderCallback,puVar10,
                     puVar10 + 0x38);
          puVar10 = *(undefined **)(puVar10 + 0x10);
        } while (puVar10 != (undefined *)0x0);
      }
      else if (WPPTraceSuite == 2) {
        _WPP_MAIN_CB = WppTraceCallback;
        IoWMIRegistrationControl(&WPP_MAIN_CB,0x80010001);
      }
    }
    ScsiGlobalAdapterList = 0;
    ScsiGlobalAdapterListElements = 0;
    KeInitializeSpinLock(&ScsiGlobalAdapterListSpinLock);
    ScsiPortInitializeDispatchTables();
    SpCreateScsiDirectory();
    uVar7 = SpInitializeGuidInterfaceMapping(param_1);
    uVar5 = (uint)uVar7;
    if ((int)uVar5 < 0) {
      return uVar7;
    }
    SpInitDeviceMap();
    cVar1 = *Mm64BitPhysicalAddress_exref;
    pcVar12 = (char *)pcVar11;
    if (cVar1 == (code)0x1) {
      pcVar12 = "SpDetermine64BitSupport: Mm64BitPhysicalAddress is TRUE\n";
      DbgPrintEx(0xc);
    }
    Sp64BitPhysicalAddresses = (uint)(cVar1 == (code)0x1);
  }
  if (0x80 < *(uint *)param_3) {
    if ((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000059;
    }
    if ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) == 0) {
      return 0xc0000059;
    }
    if (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2) {
      return 0xc0000059;
    }
    uVar9 = 10;
LAB_14001f467:
    WPP_SF_(WPP_GLOBAL_Control[3],uVar9,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids);
    return 0xc0000059;
  }
  if ((((*(longlong *)(param_3 + 8) == 0) || (*(longlong *)(param_3 + 0x20) == 0)) ||
      (*(longlong *)(param_3 + 0x10) == 0)) || (*(longlong *)(param_3 + 0x28) == 0)) {
    if ((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000059;
    }
    if ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) == 0) {
      return 0xc0000059;
    }
    if (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 2) {
      return 0xc0000059;
    }
    uVar9 = 0xb;
    goto LAB_14001f467;
  }
  local_res8 = IoGetDriverObjectExtension(param_1,ScsiPortInitialize);
  if (local_res8 == 0) {
    pcVar12 = (char *)&local_res8;
    uVar5 = SpAllocateDriverExtension(param_1,param_2,(undefined8 *)pcVar12);
    if ((int)uVar5 < 0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_D(WPP_GLOBAL_Control[3],0xc,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,uVar5);
      }
      return (ulonglong)uVar5;
    }
  }
  *(code **)(param_1 + 0x60) = ScsiPortStartIo;
  *(code **)(param_1 + 0xe8) = ScsiPortGlobalDispatch;
  *(code **)(param_1 + 0x70) = ScsiPortGlobalDispatch;
  *(code **)(param_1 + 0x80) = ScsiPortGlobalDispatch;
  *(code **)(param_1 + 0xe0) = ScsiPortGlobalDispatch;
  *(code **)(param_1 + 0x148) = ScsiPortGlobalDispatch;
  *(code **)(param_1 + 0x128) = ScsiPortGlobalDispatch;
  *(code **)(param_1 + 0x120) = ScsiPortGlobalDispatch;
  *(code **)(*(longlong *)(param_1 + 0x30) + 8) = ScsiPortAddDevice;
  *(code **)(param_1 + 0x68) = ScsiPortUnload;
  uVar6 = SpQueryPnpInterfaceFlags(local_res8,*(int *)(param_3 + 4),pcVar12);
  if (*(int *)(param_3 + 4) == 0) {
    if ((uVar6 & 1) == 0) {
      return 0xc000000e;
    }
  }
  else if ((uVar6 & 1) == 0) goto LAB_14001f42c;
  plVar13 = (longlong *)(local_res8 + 0x18);
  while (lVar2 = *plVar13, lVar2 != 0) {
    if (*(int *)(lVar2 + 4) == *(int *)(param_3 + 4)) {
      return 0;
    }
    plVar13 = (longlong *)(lVar2 + 0x80);
  }
  puVar8 = (undefined8 *)SpAllocatePoolEx(0,0x88,0x49506353,param_1,0x696e6974,0x1a4);
  if (puVar8 == (undefined8 *)0x0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_(WPP_GLOBAL_Control[3],0xd,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids);
    }
    return 0xc000009a;
  }
  uVar3 = *(undefined8 *)(param_3 + 8);
  *puVar8 = *(undefined8 *)param_3;
  puVar8[1] = uVar3;
  uVar3 = *(undefined8 *)(param_3 + 0x18);
  puVar8[2] = *(undefined8 *)(param_3 + 0x10);
  puVar8[3] = uVar3;
  uVar3 = *(undefined8 *)(param_3 + 0x28);
  puVar8[4] = *(undefined8 *)(param_3 + 0x20);
  puVar8[5] = uVar3;
  uVar3 = *(undefined8 *)(param_3 + 0x38);
  puVar8[6] = *(undefined8 *)(param_3 + 0x30);
  puVar8[7] = uVar3;
  uVar3 = *(undefined8 *)(param_3 + 0x48);
  puVar8[8] = *(undefined8 *)(param_3 + 0x40);
  puVar8[9] = uVar3;
  uVar3 = *(undefined8 *)(param_3 + 0x58);
  puVar8[10] = *(undefined8 *)(param_3 + 0x50);
  puVar8[0xb] = uVar3;
  uVar3 = *(undefined8 *)(param_3 + 0x68);
  puVar8[0xc] = *(undefined8 *)(param_3 + 0x60);
  puVar8[0xd] = uVar3;
  uVar3 = *(undefined8 *)(param_3 + 0x70);
  uVar4 = *(undefined8 *)(param_3 + 0x78);
  puVar8[0x10] = 0;
  puVar8[0xe] = uVar3;
  puVar8[0xf] = uVar4;
  *plVar13 = (longlong)puVar8;
LAB_14001f42c:
  uVar6 = 0;
  if (*(int *)(local_res8 + 0x30) == 0) {
    uVar6 = uVar5;
  }
  *(ushort *)(param_3 + 0x68) = *(ushort *)(param_3 + 0x68) | 0x10;
  return (ulonglong)uVar6;
}



===== SpAllocateAdapterResources @ 14001f498 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SpAllocateAdapterResources(longlong param_1)

{
  longlong *plVar1;
  char cVar2;
  byte bVar3;
  longlong *plVar4;
  uint uVar5;
  uint uVar6;
  longlong lVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  longlong lVar10;
  uint *puVar11;
  longlong lVar12;
  uint uVar13;
  undefined1 auStackY_d8 [32];
  uint local_98 [2];
  longlong local_90;
  longlong local_88;
  undefined1 local_78 [4];
  char local_74;
  undefined1 local_73;
  undefined1 local_72;
  undefined1 local_71;
  undefined1 local_70;
  undefined1 local_6d;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_d8;
  plVar4 = *(longlong **)(param_1 + 0x40);
  lVar12 = plVar4[0x3f];
  *(undefined1 *)(plVar4 + 0x91) = *(undefined1 *)(lVar12 + 0x59);
  *(undefined1 *)((longlong)plVar4 + 0x3fa) = *(undefined1 *)(lVar12 + 0x59);
  local_90 = lVar12;
  local_88 = param_1;
  if ((plVar4[0x3a] == 0) &&
     ((cVar2 = *(char *)(lVar12 + 0x52), cVar2 != '\0' || (*(int *)(lVar12 + 0x20) != -1)))) {
    local_98[0] = 0;
    memset(local_78,0,0x40);
    local_68 = *(undefined4 *)(lVar12 + 0x20);
    local_70 = *(undefined1 *)(lVar12 + 0x57);
    local_64 = *(undefined4 *)(lVar12 + 8);
    local_6c = *(undefined4 *)(lVar12 + 4);
    local_60 = *(undefined4 *)(lVar12 + 0x28);
    local_5c = *(undefined4 *)(lVar12 + 0x2c);
    local_73 = *(undefined1 *)(lVar12 + 0x51);
    local_54 = *(undefined4 *)(lVar12 + 0x24);
    local_72 = *(undefined1 *)(lVar12 + 0x58);
    local_58 = *(undefined4 *)(lVar12 + 0x18);
    *(undefined1 *)((longlong)plVar4 + 0x492) = local_70;
    local_71 = 0;
    local_74 = cVar2;
    if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0 &&
        (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
      WPP_SF_D(WPP_GLOBAL_Control[3],0x47,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,
               (uint)*(byte *)(lVar12 + 0x90));
    }
    *(bool *)((longlong)plVar4 + 0x489) = SpRemapBuffersByDefault != 0;
    if ((*(byte *)(lVar12 + 0x90) & 0x7f) == 0) {
      if (Sp64BitPhysicalAddresses == 1) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_q(WPP_GLOBAL_Control[3],0x49,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,
                   plVar4);
        }
        *(undefined1 *)((longlong)plVar4 + 0x489) = 1;
      }
    }
    else {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_(WPP_GLOBAL_Control[3],0x48,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids);
      }
      local_6d = 1;
      *(undefined1 *)((longlong)plVar4 + 0x491) = 1;
    }
    lVar7 = IoGetDmaAdapter(plVar4[0x28],local_78,local_98);
    plVar4[0x3a] = lVar7;
    uVar5 = local_98[0];
    if (*(uint *)(lVar12 + 0x1c) < local_98[0]) {
      uVar5 = *(uint *)(lVar12 + 0x1c);
    }
    *(uint *)((longlong)plVar4 + 0x3ec) = uVar5;
  }
  bVar3 = *(byte *)(plVar4 + 0x4c);
  if (bVar3 == 0) {
    *(undefined1 *)(plVar4 + 0x4c) = 0xfe;
  }
  else if ((uint)bVar3 < *(uint *)(plVar4 + 0x44)) {
    if ((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_14001f700;
    if (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_DD(WPP_GLOBAL_Control[3],0x1c,&WPP_433326d8495e374ced4cf2ffd30b12d2_Traceguids,
                (uint)bVar3,(char)*(uint *)(plVar4 + 0x44));
    }
  }
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_D(WPP_GLOBAL_Control[3],0x1d,&WPP_433326d8495e374ced4cf2ffd30b12d2_Traceguids,
             (uint)*(byte *)(plVar4 + 0x4c));
  }
LAB_14001f700:
  local_98[0] = (uint)*(byte *)(plVar4 + 0x4c);
  lVar7 = SpAllocatePoolEx(0,(ulonglong)local_98[0] << 4,0x4c546353,*(undefined8 *)(*plVar4 + 8),
                           0x7574696c,0x726);
  if (lVar7 == 0) {
    return 0xc000009a;
  }
  InitializeSListHead((PSLIST_HEADER)(plVar4 + 0x48));
  uVar5 = local_98[0];
  uVar13 = 0;
  plVar4[0x4a] = lVar7;
  if (local_98[0] != 0) {
    puVar11 = (uint *)(lVar7 + 8);
    do {
      uVar13 = uVar13 + 1;
      *puVar11 = uVar13;
      ExpInterlockedPushEntrySList((PSLIST_HEADER)(plVar4 + 0x48));
      puVar11 = puVar11 + 4;
    } while (uVar13 < uVar5);
    lVar12 = local_90;
    param_1 = local_88;
  }
  SpInitializePowerParams((longlong)plVar4);
  SpInitializePerformanceParams((longlong)plVar4);
  lVar7 = plVar4[0xec];
  if ((lVar7 == 0) || ((*(uint *)(lVar7 + 100) & 1) == 0)) {
    lVar7 = plVar4[0x45];
  }
  else {
    lVar7 = *(longlong *)(lVar7 + 0x50);
  }
  if (((*(int *)((longlong)plVar4 + 0x214) != 0) || (*(char *)(lVar12 + 0x5c) != '\0')) &&
     (lVar7 == 0)) {
    SpInitializeRequestSenseParams((longlong)plVar4);
    *(undefined1 *)((longlong)plVar4 + 0x48c) = *(undefined1 *)(lVar12 + 0x5c);
    *(undefined1 *)((longlong)plVar4 + 0x48f) = 1;
    uVar8 = SpGetCommonBuffer(plVar4,0);
    if ((int)uVar8 < 0) {
      return uVar8;
    }
  }
  uVar5 = SpInitializeSrbDataLookasideList(param_1);
  if (-1 < (int)uVar5) {
    lVar7 = SpAllocateSrbData((longlong)plVar4,0,0);
    plVar4[0xcb] = lVar7;
    if (lVar7 == 0) {
      return 0xc000009a;
    }
    plVar1 = plVar4 + 0xc9;
    if ((*plVar1 == 0) && (plVar4[0xca] == 0)) {
      plVar4[0xca] = (longlong)plVar1;
      *plVar1 = (longlong)plVar1;
    }
    KeInitializeSpinLock(plVar4 + 200);
    plVar4[0xb0] = (longlong)(plVar4 + 0xb1);
    if (plVar4[0xdd] == 0) {
      lVar7 = SpAllocatePoolEx(4,0x100,0x71506353,*(undefined8 *)(param_1 + 8),0x696e6974,0x11e9);
      plVar4[0xdd] = lVar7;
      if (lVar7 == 0) {
        return 0xc000009a;
      }
      lVar10 = (ulonglong)*(byte *)(plVar4 + 0xe9) + 0x12;
      uVar9 = 0;
      lVar7 = SpAllocatePoolEx(4,lVar10,0x71506353,*(undefined8 *)(param_1 + 8),0x696e6974,0x11f2);
      plVar4[0xde] = lVar7;
      if (lVar7 == 0) {
        return 0xc000009a;
      }
      lVar7 = SpAllocateIrpEx(CONCAT71((int7)((ulonglong)uVar9 >> 8),1),lVar10,
                              *(undefined8 *)(param_1 + 8),0x696e6974,0x11fd);
      plVar4[0xdf] = lVar7;
      if (lVar7 == 0) {
        return 0xc000009a;
      }
      lVar7 = SpAllocateMdlEx();
      plVar4[0xe0] = lVar7;
      if (lVar7 == 0) {
        return 0xc000009a;
      }
      MmBuildMdlForNonPagedPool(lVar7);
    }
    *(undefined4 *)((longlong)plVar4 + 0x3e4) = 0x18;
    *(undefined4 *)(plVar4 + 0x7d) = *(undefined4 *)(lVar12 + 0x18);
    if (*(char *)(lVar12 + 0x5e) != '\0') {
      *(uint *)(plVar4 + 0x7e) = *(uint *)(plVar4 + 0x7e) | 2;
    }
    *(undefined1 *)(plVar4 + 0x7f) = *(undefined1 *)((longlong)plVar4 + 0x48b);
    *(undefined1 *)((longlong)plVar4 + 0x3f9) = *(undefined1 *)(lVar12 + 0x54);
    uVar13 = *(uint *)(lVar12 + 0x30);
    uVar6 = *(uint *)(param_1 + 0x98);
    if (*(uint *)(param_1 + 0x98) < uVar13) {
      *(uint *)(param_1 + 0x98) = uVar13;
      uVar6 = uVar13;
    }
    *(uint *)((longlong)plVar4 + 0x3f4) = uVar6;
    if (*(int *)((longlong)plVar4 + 0x3ec) == 0) {
      uVar13 = (*(uint *)(plVar4 + 0x7d) >> 0xc) + (uint)((*(uint *)(plVar4 + 0x7d) & 0xfff) != 0);
      *(uint *)((longlong)plVar4 + 0x3ec) = uVar13;
      if (*(uint *)(lVar12 + 0x1c) < uVar13) {
        *(uint *)((longlong)plVar4 + 0x3ec) = *(uint *)(lVar12 + 0x1c);
      }
    }
  }
  return (ulonglong)uVar5;
}



===== SpAllocateDriverExtension @ 14001fa2c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SpAllocateDriverExtension(longlong param_1,wchar_t *param_2,undefined8 *param_3)

{
  uint *puVar1;
  byte bVar2;
  longlong *plVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  longlong lVar7;
  char *pcVar8;
  undefined2 uVar9;
  wchar_t *pwVar10;
  uint uVar11;
  undefined8 *puVar12;
  ulonglong uVar13;
  uint uVar14;
  undefined1 auStackY_238 [32];
  uint local_208;
  longlong *local_200;
  longlong local_1f8;
  wchar_t *local_1f0;
  uint local_1e8;
  uint local_1e4;
  undefined4 local_1e0;
  wchar_t local_1d8 [8];
  uint local_1c8 [2];
  wchar_t *local_1c0;
  undefined8 local_1b8;
  wchar_t *pwStack_1b0;
  wchar_t *local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  ulonglong uStack_190;
  longlong local_188 [2];
  int local_178;
  wchar_t *local_170;
  longlong local_168;
  undefined8 *local_160;
  undefined4 local_158;
  int local_154;
  int local_14c;
  byte local_138 [4];
  uint local_134;
  uint local_130;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_238;
  local_200 = (longlong *)0x0;
  local_1b8 = 0;
  pwStack_1b0 = (wchar_t *)0x0;
  local_1a8 = (wchar_t *)0x0;
  uStack_1a0 = 0;
  local_198 = 0;
  uStack_190 = uStack_190 & 0xffffffff00000000;
  local_1d8[0] = L'\0';
  local_1d8[1] = L'\0';
  local_1d8[2] = L'\0';
  local_1d8[3] = L'\0';
  local_1d8[4] = L'\0';
  local_1d8[5] = L'\0';
  local_1d8[6] = L'\0';
  local_1d8[7] = L'\0';
  local_170 = (wchar_t *)0x0;
  local_1c0 = (wchar_t *)0x0;
  local_168 = 0;
  local_208 = 0;
  *param_3 = 0;
  local_1f8 = param_1;
  local_1f0 = param_2;
  local_188[0] = param_1;
  local_160 = param_3;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_Z(WPP_GLOBAL_Control[3],0x56,param_3,(wchar_t *)(param_1 + 0x38));
  }
  local_1b8._0_4_ = 0x30;
  pwStack_1b0 = (wchar_t *)0x0;
  uStack_1a0._0_4_ = 0x240;
  local_198 = 0;
  uStack_190 = 0;
  puVar12 = &local_1b8;
  local_1a8 = param_2;
  iVar4 = ZwOpenKey(&local_170,0x20019);
  if (iVar4 < 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      uVar9 = 0x57;
LAB_14001fb66:
      WPP_SF_ZL(WPP_GLOBAL_Control[3],uVar9,puVar12,param_2,(char)iVar4);
    }
  }
  else {
    RtlInitUnicodeString(local_1d8,L"Parameters");
    local_1b8._0_4_ = 0x30;
    pwStack_1b0 = local_170;
    uStack_1a0._0_4_ = 0x240;
    local_1a8 = local_1d8;
    local_198 = 0;
    uStack_190 = 0;
    puVar12 = &local_1b8;
    iVar4 = ZwOpenKey(&local_1c0,0x20019);
    if (iVar4 < 0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        uVar9 = 0x58;
        goto LAB_14001fb66;
      }
    }
    else {
      pwVar10 = L"BusType";
      RtlInitUnicodeString(local_1d8);
      local_1e8 = 0;
      uVar6 = SpReadNumericValue(local_1c0,pwVar10,local_1d8,&local_1e8);
      local_208 = local_1e8;
      if ((int)uVar6 < 0) {
        local_208 = 1;
      }
      else if (((((local_1e8 == 1) || (local_1e8 == 2)) ||
                ((local_1e8 == 3 ||
                 (((((local_1e8 == 5 || (local_1e8 == 6)) || (local_1e8 == 8)) ||
                   ((local_1e8 == 9 || (local_1e8 == 10)))) || (local_1e8 == 0xb)))))) &&
               (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)))) &&
              (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_D(WPP_GLOBAL_Control[3],0x59,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,
                 local_1e8);
      }
      RtlInitUnicodeString(local_1d8,L"PnpInterface");
      local_1b8._0_4_ = 0x30;
      pwStack_1b0 = local_1c0;
      uStack_1a0._0_4_ = 0x240;
      local_1a8 = local_1d8;
      local_198 = 0;
      uStack_190 = 0;
      iVar4 = ZwOpenKey(&local_168,0x20019,&local_1b8);
      if (iVar4 < 0) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_ZL(WPP_GLOBAL_Control[3],0x5a,&WPP_GLOBAL_Control,param_2,(char)iVar4);
        }
      }
      else {
        for (uVar11 = 0; local_1e4 = uVar11, uVar11 < 2; uVar11 = uVar11 + 1) {
          uVar13 = 0;
          while( true ) {
            iVar4 = (int)uVar13;
            local_1e0 = 0;
            local_178 = iVar4;
            memset(local_138,0,0xff);
            local_1e8 = ZwEnumerateValueKey(local_168,uVar13,uVar11 != 0,local_138);
            plVar3 = local_200;
            if (local_1e8 == 0x8000001a) break;
            if ((int)local_1e8 < 0) {
              if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
                 (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                WPP_SF_LZ(WPP_GLOBAL_Control[3],0x5b,
                          &WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,local_1e8,param_2);
              }
              goto LAB_14002012b;
            }
            if (uVar11 == 1) {
              local_1c8[0] = 0;
              RtlInitUnicodeString(local_1d8);
              if ((local_134 & 0xfffffffb) == 0) {
                uVar11 = RtlUnicodeStringToInteger(local_1d8,0,local_1c8);
                if (-1 < (int)uVar11) {
                  if (local_1c8[0] < 0x13) {
                    *(uint *)(plVar3 + uVar13 + 0xc) = local_1c8[0];
                    if (local_134 == 0) {
                      *(undefined4 *)((longlong)plVar3 + uVar13 * 8 + 100) = 0;
                      uVar14 = 0;
                      uVar11 = local_1c8[0];
                    }
                    else {
                      bVar2 = local_138[local_130];
                      *(uint *)((longlong)plVar3 + uVar13 * 8 + 100) = (uint)bVar2;
                      if ((bVar2 & 1) != 0) {
                        *(int *)(local_200 + 6) = (int)local_200[6] + 1;
                      }
                      uVar11 = *(uint *)(plVar3 + uVar13 + 0xc);
                      if (uVar11 == 0) {
LAB_1400200cd:
                        puVar1 = (uint *)((longlong)plVar3 + uVar13 * 8 + 100);
                        *puVar1 = *puVar1 & 0xfffffffd;
                        uVar14 = *(uint *)((longlong)plVar3 + uVar13 * 8 + 100);
                      }
                      else {
                        if (uVar11 == 5) {
                          puVar1 = (uint *)((longlong)plVar3 + uVar13 * 8 + 100);
                          *puVar1 = *puVar1 | 4;
                          uVar14 = *(uint *)((longlong)plVar3 + uVar13 * 8 + 100);
                          *(uint *)((longlong)plVar3 + uVar13 * 8 + 100) = uVar14 | 8;
                          uVar14 = uVar14 & 0xfffffffd | 8;
                        }
                        else {
                          if (((uVar11 == 8) || (uVar11 == 0xe)) || (uVar11 == 0xf))
                          goto LAB_1400200cd;
                          uVar14 = *(uint *)((longlong)plVar3 + uVar13 * 8 + 100);
                          if ((uVar14 & 0x10) != 0) goto LAB_1400200d8;
                          uVar14 = uVar14 | 2;
                        }
                        *(uint *)((longlong)plVar3 + uVar13 * 8 + 100) = uVar14;
                      }
                    }
LAB_1400200d8:
                    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
                       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                      WPP_SF_dL(WPP_GLOBAL_Control[3],0x5c,WPP_GLOBAL_Control,uVar11,(char)uVar14);
                    }
                    param_2 = local_1f0;
                    uVar11 = local_1e4;
                    goto LAB_140020113;
                  }
                  DbgPrint("SpAllocateDriverExtension: Fatal error parsing PnpInterface under %wZ - entry %wZ is > MaximumInterfaceType (%d)\n"
                           ,uVar11,local_1f0,local_1d8);
                  *(undefined4 *)(plVar3 + uVar13 + 0xc) = 0xffffffff;
                  goto LAB_14001ff07;
                }
                pcVar8 = 
                "SpAllocateDriverExtension: Fatal error %#08lx parsing PnpInterface under %wZ - entry %wZ is not a valid interface type name\n"
                ;
              }
              else {
                pcVar8 = 
                "SpAllocateDriverExtension: Fatal error parsing PnpInterface under %wZ - entry %wZ is not a REG_DWORD or REG_NONE entry (%d instead)\n"
                ;
                uVar11 = local_1e8;
              }
              param_2 = local_1f0;
              DbgPrint(pcVar8,uVar11,local_1f0,local_1d8);
              goto LAB_14002012b;
            }
LAB_140020113:
            uVar13 = (ulonglong)(iVar4 + 1);
          }
          if (uVar11 == 0) {
            if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
               (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              WPP_SF_D(WPP_GLOBAL_Control[3],0x5d,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,
                       iVar4);
            }
            if (iVar4 != 0) {
              uVar14 = iVar4 * 8 + 0x60;
              if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
                 (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                WPP_SF_D(WPP_GLOBAL_Control[3],0x5e,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids
                         ,uVar14);
              }
              iVar5 = IoAllocateDriverObjectExtension
                                (local_1f8,ScsiPortInitialize,uVar14,&local_200);
              if (-1 < iVar5) {
                memset(local_200,0,(ulonglong)uVar14);
                *(int *)((longlong)local_200 + 0x2c) = iVar4;
                param_2 = local_1f0;
                goto LAB_14001ff2e;
              }
              if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
                 (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                WPP_SF_D(WPP_GLOBAL_Control[3],0x5f,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids
                         ,iVar5);
LAB_14001ff07:
                param_2 = local_1f0;
                break;
              }
              param_2 = local_1f0;
            }
            param_1 = local_1f8;
            goto LAB_14002013b;
          }
LAB_14001ff2e:
        }
LAB_14002012b:
        param_1 = local_1f8;
      }
    }
  }
LAB_14002013b:
  if (local_200 == (longlong *)0x0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_(WPP_GLOBAL_Control[3],0x60,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids);
    }
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_D(WPP_GLOBAL_Control[3],0x61,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,0x60);
    }
    iVar4 = IoAllocateDriverObjectExtension(param_1,ScsiPortInitialize,0x60,&local_200);
    if (-1 < iVar4) {
      memset(local_200,0,0x60);
      goto LAB_140020212;
    }
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_D(WPP_GLOBAL_Control[3],0x62,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,iVar4);
    }
  }
  else {
    *(uint *)((longlong)local_200 + 0x24) = local_208;
LAB_140020212:
    iVar4 = 0;
  }
  if (iVar4 != 0) goto LAB_140020700;
  lVar7 = SpAllocateErrorLogEntry(param_1);
  local_200[7] = lVar7;
  local_200[9] = 0;
  local_200[10] = 0;
  local_200[0xb] = 0;
  *local_200 = param_1;
  lVar7 = *(longlong *)(param_2 + 4);
  local_200[1] = *(longlong *)param_2;
  local_200[2] = lVar7;
  *(short *)((longlong)local_200 + 10) = *(short *)((longlong)local_200 + 10) + 2;
  lVar7 = SpAllocatePoolEx(1,(ulonglong)*(ushort *)((longlong)local_200 + 10),0x52506353,param_1,
                           0x696e6974,0x17c9);
  local_200[2] = lVar7;
  if (local_200[2] == 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_(WPP_GLOBAL_Control[3],99,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids);
    }
    iVar4 = -0x3fffff66;
    goto LAB_140020700;
  }
  RtlCopyUnicodeString(local_200 + 1,param_2);
  if (ScsiPortLegacyAdapterDetection != 0) {
    *(undefined1 *)(local_200 + 5) = 1;
    goto LAB_140020700;
  }
  if (local_1c0 != (wchar_t *)0x0) {
    local_188[0] = 0;
    local_188[1] = 0;
    local_1e8 = 0;
    RtlInitUnicodeString(local_188,L"LegacyAdapterDetection");
    iVar4 = ZwQueryValueKey(local_1c0,local_188,2,&local_158);
    if (((iVar4 < 0) || (local_1e8 < 0x10)) || (local_154 != 4)) {
      *(undefined1 *)(local_200 + 5) = 0;
    }
    else {
      *(bool *)(local_200 + 5) = local_14c == 1;
      local_1e0 = 0;
      iVar4 = ZwSetValueKey(local_1c0,local_188,local_158,4);
      if (((iVar4 < 0) && ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0 &&
          (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
        WPP_SF_D(WPP_GLOBAL_Control[3],100,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,iVar4);
      }
    }
  }
  if ((char)local_200[5] == '\0') {
    local_188[0] = 0;
    local_188[1] = 0;
    local_1f0 = (wchar_t *)0x0;
    local_1f8 = 0;
    RtlInitUnicodeString(local_188,0);
    RtlInitUnicodeString
              (local_1d8,L"\\REGISTRY\\MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class");
    local_1b8._0_4_ = 0x30;
    local_1b8._4_4_ = 0;
    uStack_1a0._0_4_ = 0x240;
    uStack_1a0._4_4_ = 0;
    pwStack_1b0 = (wchar_t *)0x0;
    local_1a8 = local_1d8;
    local_198 = 0;
    uStack_190 = 0;
    iVar4 = ZwOpenKey(&local_1f0,0x20019,&local_1b8);
    if (iVar4 < 0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        uVar9 = 0x65;
LAB_140020510:
        pwVar10 = local_1d8;
LAB_140020515:
        WPP_SF_LZ(WPP_GLOBAL_Control[3],uVar9,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,iVar4
                  ,pwVar10);
      }
    }
    else {
      iVar4 = RtlStringFromGUID(&GUID_DEVCLASS_SCSIADAPTER,local_188);
      if (iVar4 < 0) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_D(WPP_GLOBAL_Control[3],0x66,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,iVar4
                  );
        }
      }
      else {
        local_1b8._0_4_ = 0x30;
        local_1b8._4_4_ = 0;
        pwStack_1b0 = local_1f0;
        uStack_1a0._0_4_ = 0x240;
        uStack_1a0._4_4_ = 0;
        local_1a8 = (wchar_t *)local_188;
        local_198 = 0;
        uStack_190 = 0;
        iVar4 = ZwOpenKey(&local_1f8,0x20019,&local_1b8);
        if (iVar4 < 0) {
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
             (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            uVar9 = 0x67;
            pwVar10 = (wchar_t *)local_188;
            goto LAB_140020515;
          }
        }
        else {
          local_1e0 = 0;
          RtlInitUnicodeString(local_1d8,L"LegacyAdapterDetection");
          iVar4 = ZwQueryValueKey(local_1f8,local_1d8,2,&local_158);
          if (iVar4 < 0) {
            if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
               (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              uVar9 = 0x68;
              goto LAB_140020510;
            }
          }
          else {
            *(bool *)(local_200 + 5) = local_14c != 0;
          }
        }
      }
    }
    if (local_1f0 != (wchar_t *)0x0) {
      ZwClose();
    }
    if (local_1f8 != 0) {
      ZwClose();
    }
    RtlFreeUnicodeString(local_188);
  }
  iVar4 = 0;
LAB_140020700:
  if (local_170 != (wchar_t *)0x0) {
    ZwClose();
  }
  if (local_1c0 != (wchar_t *)0x0) {
    ZwClose();
  }
  if (local_168 != 0) {
    ZwClose();
  }
  if (-1 < iVar4) {
    *local_160 = local_200;
  }
  return iVar4;
}



===== SpBuildConfiguration @ 140020790 =====

void SpBuildConfiguration(longlong param_1,longlong param_2,longlong param_3)

{
  char cVar1;
  short sVar2;
  longlong lVar3;
  undefined4 uVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  uint uVar7;
  ulonglong uVar8;
  
  lVar3 = *(longlong *)(param_1 + 0x200);
  uVar6 = 0;
  uVar8 = 0;
  if (*(int *)(lVar3 + 0x10) != 0) {
    do {
      cVar1 = *(char *)(lVar3 + 0x14 + uVar8 * 0x14);
      uVar7 = (uint)uVar6;
      if (cVar1 == '\x01') {
        if (uVar7 < *(uint *)(param_2 + 0x4c)) {
          puVar5 = (undefined8 *)(uVar6 * 0x10 + *(longlong *)(param_3 + 0x38));
          *puVar5 = *(undefined8 *)(lVar3 + 0x18 + uVar8 * 0x14);
          uVar4 = *(undefined4 *)(lVar3 + 0x20 + uVar8 * 0x14);
          *(undefined1 *)((longlong)puVar5 + 0xc) = 0;
LAB_14002087c:
          uVar6 = (ulonglong)(uVar7 + 1);
          *(undefined4 *)(puVar5 + 1) = uVar4;
        }
      }
      else if (cVar1 == '\x02') {
        *(undefined4 *)(param_3 + 0xc) = *(undefined4 *)(lVar3 + 0x18 + uVar8 * 0x14);
        *(undefined4 *)(param_3 + 0x10) = *(undefined4 *)(lVar3 + 0x1c + uVar8 * 0x14);
        sVar2 = *(short *)(lVar3 + 0x16 + uVar8 * 0x14);
        if (sVar2 == 1) {
          *(undefined4 *)(param_3 + 0x14) = 1;
        }
        else if (sVar2 == 0) {
          *(undefined4 *)(param_3 + 0x14) = 0;
        }
        *(byte *)(param_1 + 0x168) = *(byte *)(param_1 + 0x168) | 8;
      }
      else if (cVar1 == '\x03') {
        if (uVar7 < *(uint *)(param_2 + 0x4c)) {
          puVar5 = (undefined8 *)(uVar6 * 0x10 + *(longlong *)(param_3 + 0x38));
          *puVar5 = *(undefined8 *)(lVar3 + 0x18 + uVar8 * 0x14);
          uVar4 = *(undefined4 *)(lVar3 + 0x20 + uVar8 * 0x14);
          *(undefined1 *)((longlong)puVar5 + 0xc) = 1;
          goto LAB_14002087c;
        }
      }
      else if (cVar1 == '\x04') {
        *(undefined4 *)(param_3 + 0x20) = *(undefined4 *)(lVar3 + 0x18 + uVar8 * 0x14);
        *(undefined4 *)(param_3 + 0x24) = *(undefined4 *)(lVar3 + 0x1c + uVar8 * 0x14);
      }
      uVar7 = (int)uVar8 + 1;
      uVar8 = (ulonglong)uVar7;
    } while (uVar7 < *(uint *)(lVar3 + 0x10));
  }
  return;
}



===== SpBuildResourceList @ 1400208ac =====

undefined4 * SpBuildResourceList(longlong *param_1,longlong param_2)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  undefined1 uVar4;
  undefined2 uVar5;
  longlong lVar6;
  undefined4 *_Dst;
  undefined4 *puVar7;
  undefined1 uVar8;
  int *piVar9;
  size_t _Size;
  int iVar10;
  int iVar11;
  ulonglong uVar12;
  undefined8 *puVar13;
  uint uVar14;
  
  iVar11 = 0;
  lVar6 = IoGetConfigurationInformation();
  if (*(char *)(param_2 + 0x55) != '\0') {
    *(undefined1 *)(lVar6 + 0x1c) = 1;
  }
  if (*(char *)(param_2 + 0x56) != '\0') {
    *(undefined1 *)(lVar6 + 0x1d) = 1;
  }
  if ((*(int *)(param_2 + 0x20) == -1) && (*(int *)(param_2 + 0x24) == -1)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
    iVar11 = 1;
  }
  bVar1 = *(byte *)(param_1 + 0x2d);
  *(byte *)(param_1 + 0x2d) = bVar1 & 0xf7;
  if ((param_1[0x52] == 0) || ((*(int *)(param_2 + 0xc) == 0 && (*(int *)(param_2 + 0x10) == 0)))) {
    iVar10 = 0;
    if (param_1[0x52] == 0) goto LAB_140020968;
  }
  else {
    iVar10 = 1;
    iVar11 = iVar11 + 1;
  }
  if ((*(int *)(param_2 + 0x68) != 0) || (*(int *)(param_2 + 0x6c) != 0)) {
    iVar10 = iVar10 + 1;
    iVar11 = iVar11 + 1;
  }
  if (iVar10 != 0) {
    *(byte *)(param_1 + 0x2d) = bVar1 & 0xf7 | 8;
  }
LAB_140020968:
  if (*(uint *)(param_2 + 0x34) != 0) {
    piVar9 = (int *)(*(longlong *)(param_2 + 0x38) + 8);
    uVar12 = (ulonglong)*(uint *)(param_2 + 0x34);
    do {
      iVar3 = iVar11 + 1;
      if (*piVar9 == 0) {
        iVar3 = iVar11;
      }
      iVar11 = iVar3;
      piVar9 = piVar9 + 4;
      uVar12 = uVar12 - 1;
    } while (uVar12 != 0);
  }
  _Size = ((ulonglong)(iVar11 - 1) + 2) * 0x14;
  _Dst = (undefined4 *)
         SpAllocatePoolEx(1,_Size,0x72506353,*(undefined8 *)(*param_1 + 8),0x696e6974,0x63c);
  if (_Dst != (undefined4 *)0x0) {
    memset(_Dst,0,_Size);
    *_Dst = 1;
    puVar7 = _Dst + 5;
    uVar14 = 0;
    _Dst[1] = *(undefined4 *)(param_2 + 8);
    uVar8 = 3;
    _Dst[2] = *(undefined4 *)(param_2 + 4);
    _Dst[4] = iVar11;
    if (*(int *)(param_2 + 0x34) != 0) {
      do {
        puVar13 = (undefined8 *)((ulonglong)uVar14 * 0x10 + *(longlong *)(param_2 + 0x38));
        if (*(int *)(puVar13 + 1) != 0) {
          if (*(char *)((longlong)puVar13 + 0xc) == '\0') {
            *(undefined1 *)puVar7 = 1;
            *(undefined2 *)((longlong)puVar7 + 2) = 1;
            if (*(int *)(param_2 + 8) == 2) {
              *(undefined2 *)((longlong)puVar7 + 2) = 0x10;
            }
          }
          else {
            *(undefined1 *)puVar7 = 3;
            *(undefined2 *)((longlong)puVar7 + 2) = 0;
          }
          *(undefined1 *)((longlong)puVar7 + 1) = 1;
          *(undefined8 *)(puVar7 + 1) = *puVar13;
          puVar7[3] = *(undefined4 *)(puVar13 + 1);
          puVar7 = puVar7 + 5;
        }
        uVar14 = uVar14 + 1;
      } while (uVar14 < *(uint *)(param_2 + 0x34));
    }
    if (iVar10 == 0) {
      iVar10 = 0;
    }
    else {
      *(undefined1 *)puVar7 = 2;
      if ((*(int *)(param_2 + 8) == 3) || (*(int *)(param_2 + 0x14) == 0)) {
        uVar5 = 0;
        uVar4 = 3;
      }
      else {
        uVar5 = 1;
        uVar4 = 1;
      }
      *(undefined1 *)((longlong)puVar7 + 1) = uVar4;
      *(undefined2 *)((longlong)puVar7 + 2) = uVar5;
      puVar7[1] = *(undefined4 *)(param_2 + 0xc);
      puVar7[2] = *(undefined4 *)(param_2 + 0x10);
      *(undefined8 *)(puVar7 + 3) = 0;
      puVar7 = puVar7 + 5;
      iVar10 = iVar10 + -1;
    }
    if (iVar10 != 0) {
      *(undefined1 *)puVar7 = 2;
      if ((*(int *)(param_2 + 8) == 3) || (*(int *)(param_2 + 0x70) == 0)) {
        uVar5 = 0;
      }
      else {
        uVar5 = 1;
        uVar8 = 1;
      }
      *(undefined1 *)((longlong)puVar7 + 1) = uVar8;
      *(undefined2 *)((longlong)puVar7 + 2) = uVar5;
      puVar7[1] = *(undefined4 *)(param_2 + 0x68);
      puVar7[2] = *(undefined4 *)(param_2 + 0x6c);
      *(undefined8 *)(puVar7 + 3) = 0;
      puVar7 = puVar7 + 5;
    }
    if (bVar2) {
      *(undefined2 *)puVar7 = 0x104;
      puVar7[1] = *(undefined4 *)(param_2 + 0x20);
      puVar7[2] = *(undefined4 *)(param_2 + 0x24);
      *(undefined2 *)((longlong)puVar7 + 2) = 0;
      if (*(int *)(param_2 + 0x20) == -1) {
        puVar7[1] = 0;
      }
      if (*(int *)(param_2 + 0x24) == -1) {
        puVar7[2] = 0;
      }
    }
  }
  return _Dst;
}



===== SpConfigurationCallout @ 140020b40 =====

undefined8 SpConfigurationCallout(undefined1 *param_1)

{
  *param_1 = 1;
  return 0;
}



===== SpCreateAdapter @ 140020b50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SpCreateAdapter(undefined8 param_1,longlong *param_2)

{
  int *piVar1;
  int iVar2;
  short sVar3;
  longlong *_Dst;
  int iVar4;
  longlong lVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined *puVar9;
  wchar_t *pwVar10;
  longlong lVar11;
  undefined1 auStackY_218 [32];
  undefined8 local_1d8;
  void *pvStack_1d0;
  wchar_t local_1c8 [64];
  undefined1 local_148 [256];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_218;
  uVar8 = 0;
  local_1d8 = 0;
  pvStack_1d0 = (void *)0x0;
  lVar5 = IoGetDriverObjectExtension();
  LOCK();
  piVar1 = (int *)(lVar5 + 0x20);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  puVar9 = (undefined *)0x100;
  memset(local_148,0,0x100);
  uVar7 = 0;
  uVar6 = (uint)(*(ushort *)(lVar5 + 8) >> 1);
  if (uVar6 != 0) {
    puVar9 = *(undefined **)(lVar5 + 0x10);
    do {
      sVar3 = *(short *)(puVar9 + (ulonglong)uVar7 * 2);
      if (sVar3 == 0) {
        uVar7 = uVar7 - 1;
        break;
      }
      if ((sVar3 == 0x5c) || (sVar3 == 0x2f)) {
        uVar8 = uVar7 + 1;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar6);
  }
  uVar6 = (uVar7 - uVar8) + 1;
  if ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      puVar9 = &WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids;
      WPP_SF_qd(WPP_GLOBAL_Control[3],0x3a,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,
                (ushort *)(lVar5 + 8),(char)uVar8);
    }
    if ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        puVar9 = &WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids;
        WPP_SF_ddd(WPP_GLOBAL_Control[3],0x3b,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,uVar7
                   ,(char)uVar6,(char)uVar6 * '\x02');
      }
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        puVar9 = &WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids;
        WPP_SF_(WPP_GLOBAL_Control[3],0x3c,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids);
      }
    }
  }
  uVar7 = 0;
  if (uVar6 != 0) {
    do {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_h(WPP_GLOBAL_Control[3],WPP_GLOBAL_Control,puVar9,
                 *(undefined2 *)(*(longlong *)(lVar5 + 0x10) + (ulonglong)(uVar8 + uVar7) * 2));
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar6);
  }
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_(WPP_GLOBAL_Control[3],0x3e,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids);
  }
  memcpy(local_148,(void *)(*(longlong *)(lVar5 + 0x10) + (ulonglong)uVar8 * 2),(ulonglong)uVar6 * 2
        );
  pwVar10 = L"\\Device\\Scsi\\%ws%d";
  RtlStringCbPrintfW(local_1c8,0x80,L"\\Device\\Scsi\\%ws%d",local_148);
  RtlInitUnicodeString(&local_1d8,local_1c8);
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_Z(WPP_GLOBAL_Control[3],0x3f,pwVar10,(wchar_t *)&local_1d8);
  }
  iVar4 = IoCreateDevice(param_1,local_1d8._2_2_ + 0x800,&local_1d8,4);
  if (iVar4 < 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_D(WPP_GLOBAL_Control[3],0x40,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,iVar4);
    }
  }
  else {
    _Dst = *(longlong **)(*param_2 + 0x40);
    memset(_Dst,0,0x800);
    lVar5 = *param_2;
    *(byte *)(_Dst + 1) = *(byte *)(_Dst + 1) & 0xf2;
    *(undefined2 *)((longlong)_Dst + 9) = 0xffff;
    *_Dst = lVar5;
    _Dst[8] = 0;
    _Dst[4] = (longlong)&AdapterMajorFunctionTable;
    *(undefined4 *)(_Dst + 9) = 0;
    *(undefined8 *)((longlong)_Dst + 0x2c) = 1;
    *(undefined4 *)(_Dst + 5) = 1;
    KeInitializeEvent(_Dst + 10,1,0);
    _Dst[0xe] = -1;
    _Dst[0xd] = 0xffffffff;
    *(undefined4 *)((longlong)_Dst + 0x4c) = 0;
    LOCK();
    piVar1 = (int *)(*(longlong *)(*param_2 + 0x40) + 0x4c);
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    lVar5 = 0;
    lVar11 = 8;
    do {
      KeInitializeSpinLock((longlong)_Dst + lVar5 + 0x2e0);
      lVar5 = lVar5 + 0x10;
      lVar11 = lVar11 + -1;
    } while (lVar11 != 0);
    *(int *)(_Dst + 0x2c) = iVar2 + 1;
    _Dst[0xd7] = (longlong)(_Dst + 0x100);
    *(undefined4 *)((longlong)_Dst + 0x15c) = 0xffffffff;
    memcpy(_Dst + 0x100,pvStack_1d0,local_1d8 >> 0x10 & 0xffff);
    KeInitializeMutex(_Dst + 0x99,0);
    _Dst[0xa1] = 0;
    *(undefined4 *)(_Dst + 0xa0) = 1;
    *(undefined4 *)(_Dst + 0xa2) = 0;
    KeInitializeEvent(_Dst + 0xa3,1,0);
    _Dst[0xac] = (longlong)_Dst;
    _Dst[0xab] = (longlong)SpEnumerationWorker;
    _Dst[0xa9] = 0;
    *(undefined4 *)(_Dst + 0xe1) = 1;
    _Dst[0xe2] = 0;
    *(undefined4 *)(_Dst + 0xe3) = 0;
    KeInitializeEvent(_Dst + 0xe4,1,0);
    *(undefined4 *)((longlong)_Dst + 0x774) = 0;
    _Dst[0xfe] = (longlong)(_Dst + 0xfe);
    *(undefined4 *)(_Dst + 0xee) = 0xffffffff;
    *(uint *)(*param_2 + 0x30) = *(uint *)(*param_2 + 0x30) | 0x10;
    *(uint *)(*param_2 + 0x30) = *(uint *)(*param_2 + 0x30) & 0xffffff7f;
  }
  return iVar4;
}



===== SpCreateScsiDirectory @ 140021000 =====

void SpCreateScsiDirectory(void)

{
  int iVar1;
  undefined8 local_res8 [4];
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
  
  local_1c = 0;
  local_res8[0] = 0;
  local_34 = 0;
  local_48 = 0;
  uStack_40 = 0;
  RtlInitUnicodeString(&local_48,L"\\Device\\Scsi");
  local_30 = 0;
  local_28 = &local_48;
  local_38 = 0x30;
  local_20 = 0x250;
  local_18 = 0;
  uStack_10 = 0;
  iVar1 = ZwCreateDirectoryObject(local_res8,0xf000f,&local_38);
  if (-1 < iVar1) {
    ObReferenceObjectByHandle(local_res8[0],0x80,0,0,&ScsiDirectory,0);
    ZwClose(local_res8[0]);
  }
  return;
}



===== SpGetCommonBuffer @ 1400210c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SpGetCommonBuffer(longlong *param_1,int param_2)

{
  undefined8 uVar1;
  void *_Dst;
  longlong lVar2;
  int iVar3;
  longlong *plVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  ulonglong uVar9;
  uint uVar10;
  
  iVar8 = 0;
  iVar5 = 0;
  uVar6 = 0;
  if (param_2 != 0) {
    iVar5 = *(int *)((longlong)param_1 + 0x78c);
    uVar6 = param_2 + 0xfffU & 0xfffff000;
    *(uint *)(param_1 + 0x2b) = uVar6;
  }
  if ((param_1[0xec] != 0) && ((*(uint *)(param_1[0xec] + 100) & 1) != 0)) {
    uVar1 = SpGetCommonBufferVrfy(param_1,uVar6);
    return uVar1;
  }
  iVar3 = *(int *)((longlong)param_1 + 0x214);
  if (iVar3 == 0) {
    iVar3 = 0x10;
    *(undefined4 *)((longlong)param_1 + 0x214) = 0x10;
  }
  if (*(char *)((longlong)param_1 + 0x48c) != '\0') {
    iVar3 = iVar3 + *(byte *)(param_1 + 0xe9) + 0x12;
  }
  uVar10 = iVar3 + 7U & 0xfffffff8;
  uVar7 = uVar10 * (int)param_1[0x44] + 0xfff + uVar6 & 0xfffff000;
  if ((iVar5 != 0) && (uVar6 != 0)) {
    uVar7 = (uVar7 - 1) + iVar5 & -iVar5;
  }
  lVar2 = param_1[0x3a];
  if (lVar2 == 0) {
    _Dst = (void *)SpAllocatePoolEx(0,(ulonglong)uVar7,0x63506353,*(undefined8 *)(*param_1 + 8),
                                    0x696e6974,0x418);
  }
  else if (((Sp64BitPhysicalAddresses == 0) || (*(char *)((longlong)param_1 + 0x491) != '\x01')) &&
          (iVar5 == 0)) {
    _Dst = (void *)(**(code **)(*(longlong *)(lVar2 + 8) + 0x10))(lVar2,uVar7,param_1 + 0x90,0);
    *(undefined1 *)(param_1 + 0x43) = 1;
  }
  else {
    if (iVar5 == 0) {
      uVar9 = 0x100000000;
    }
    else {
      uVar9 = (ulonglong)uVar7;
    }
    _Dst = (void *)MmAllocateContiguousNodeMemory
                             ((ulonglong)uVar7,param_1[0xed],param_1[0xee],uVar9,4,0x80000000);
    if (_Dst != (void *)0x0) {
      lVar2 = MmGetPhysicalAddress(_Dst);
      param_1[0x90] = lVar2;
    }
    *(undefined1 *)(param_1 + 0x43) = 0;
  }
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qDD(WPP_GLOBAL_Control[3],0x17,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,_Dst,
               (char)*(undefined4 *)((longlong)param_1 + 0x484),(char)param_1[0x90]);
  }
  if (_Dst == (void *)0x0) {
    uVar1 = 0xc000009a;
  }
  else {
    memset(_Dst,0,(ulonglong)uVar7);
    *(uint *)(param_1 + 0x42) = uVar7;
    param_1[0x45] = (longlong)_Dst;
    param_1[0x2a] = -(ulonglong)(uVar6 != 0) & (ulonglong)_Dst;
    if (*(char *)((longlong)param_1 + 0x48f) != '\0') {
      plVar4 = (longlong *)((ulonglong)*(uint *)(param_1 + 0x2b) + (longlong)_Dst);
      param_1[0x46] = (longlong)plVar4;
      for (uVar7 = uVar7 - *(uint *)(param_1 + 0x2b); uVar10 * 2 <= uVar7; uVar7 = uVar7 - uVar10) {
        *plVar4 = (longlong)((ulonglong)uVar10 + (longlong)plVar4);
        iVar8 = iVar8 + 1;
        plVar4 = (longlong *)((ulonglong)uVar10 + (longlong)plVar4);
      }
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_D(WPP_GLOBAL_Control[3],0x18,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,iVar8);
      }
      *(int *)(param_1 + 0x44) = iVar8;
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== SpGetRegistryValue @ 14002137c =====

ulonglong SpGetRegistryValue(undefined8 param_1,undefined8 param_2,ulonglong param_3,
                            longlong *param_4)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong local_res18 [2];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res18[0] = param_3 & 0xffffffff00000000;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,L"ScanDisconnectedDevices");
  uVar2 = ZwQueryValueKey(param_2,&local_18,1,0,0,local_res18);
  if (((int)uVar2 == -0x7ffffffb) || ((int)uVar2 == -0x3fffffdd)) {
    lVar3 = SpAllocatePoolEx(0,local_res18[0] & 0xffffffff,0x52506353,param_1,0x696e6974,0xa06);
    if (lVar3 == 0) {
      uVar2 = 0xc000009a;
    }
    else {
      uVar1 = ZwQueryValueKey(param_2,&local_18,1,lVar3,(undefined4)local_res18[0],local_res18);
      uVar2 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) {
        *param_4 = lVar3;
        return 0;
      }
      ExFreePoolWithTag(lVar3,0);
    }
  }
  *param_4 = 0;
  return uVar2;
}



===== SpInitializeAdapterExtension @ 140021490 =====

int SpInitializeAdapterExtension(longlong *param_1,uint *param_2,undefined8 *param_3)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  bool bVar4;
  
  param_1[0x4f] = *(longlong *)(param_2 + 8);
  param_1[0x50] = *(longlong *)(param_2 + 2);
  param_1[0x51] = *(longlong *)(param_2 + 4);
  param_1[0x52] = *(longlong *)(param_2 + 6);
  param_1[0x53] = *(longlong *)(param_2 + 10);
  param_1[0x54] = *(longlong *)(param_2 + 0xc);
  uVar1 = param_2[0x11];
  param_1[0x57] = 0;
  *(uint *)((longlong)param_1 + 0x264) = uVar1;
  if (0x7f < *param_2) {
    param_1[0x57] = *(longlong *)(param_2 + 0x1e);
  }
  lVar3 = IoGetDriverObjectExtension(*(undefined8 *)(*param_1 + 8),ScsiPortInitialize);
  if ((lVar3 != 0) && (*(int *)(lVar3 + 0x40) == 1)) {
    SpDoVerifierInit(param_1,(longlong)param_2);
  }
  uVar1 = param_2[0x12];
  *(undefined1 *)((longlong)param_1 + 0x17a) = 8;
  *(undefined4 *)(param_1 + 0x44) = 0x10;
  *(uint *)((longlong)param_1 + 0x214) = uVar1 + 7 & 0xfffffff8;
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = param_1;
    param_1[0x29] = (longlong)(param_3 + 1);
  }
  lVar3 = MmAllocateMappingAddress(0x4000,0x6d506353);
  param_1[0xef] = lVar3;
  lVar3 = IoAllocateMdl(0,0x4000,0,0,0);
  param_1[0xf0] = lVar3;
  bVar4 = ScsiPortVerifierInitialized != 0;
  iVar2 = -ScsiPortVerifierInitialized;
  *(undefined4 *)((longlong)param_1 + 0x794) = 10;
  *(uint *)(param_1 + 0xf4) = (-(uint)bVar4 & 0x38) + 4;
  return iVar2;
}



===== SpInitializeConfiguration @ 1400215ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
SpInitializeConfiguration(longlong *param_1,wchar_t *param_2,longlong param_3,wchar_t *param_4)

{
  int *piVar1;
  wchar_t *pwVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  wchar_t *_Size;
  wchar_t *pwVar6;
  bool bVar7;
  undefined1 auStack_4f8 [32];
  undefined8 local_4d8;
  undefined4 *local_4d0;
  code *local_4c8;
  char *local_4c0;
  char local_4b8 [4];
  undefined4 local_4b4;
  undefined8 local_4b0;
  undefined8 local_4a8;
  undefined8 uStack_4a0;
  undefined8 local_498;
  undefined8 uStack_490;
  undefined4 local_488;
  undefined4 local_484;
  undefined8 local_480;
  undefined8 *local_478;
  undefined4 local_470;
  undefined4 local_46c;
  undefined8 local_468;
  undefined8 uStack_460;
  int local_458 [4];
  uint local_448;
  wchar_t local_444 [246];
  wchar_t local_258 [256];
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStack_4f8;
  local_4b8[0] = '\0';
  pwVar6 = param_4;
  memset(param_4 + 0x18,0,0x98);
  _Size = (wchar_t *)((ulonglong)*(uint *)(param_3 + 0x4c) << 4);
  memset(*(void **)(param_4 + 0xc),0,(size_t)_Size);
  param_4[0x18] = L'\x98';
  param_4[0x19] = L'\0';
  piVar1 = (int *)(param_3 + 4);
  *(int *)(param_4 + 0x1c) = *piVar1;
  bVar7 = Sp64BitPhysicalAddresses != 1;
  param_4[0x24] = L'\xffff';
  param_4[0x25] = L'\xffff';
  param_4[0x28] = L'\xffff';
  param_4[0x29] = L'\xffff';
  param_4[0x2a] = L'\xffff';
  param_4[0x2b] = L'\xffff';
  param_4[0x22] = L'\x01';
  param_4[0x23] = L'\0';
  *(undefined4 *)(param_4 + 0x32) = *(undefined4 *)(param_3 + 0x4c);
  *(undefined1 *)((longlong)param_4 + 0x91) = 8;
  param_4[0x61] = L'\b';
  *(byte *)(param_4 + 0x60) = bVar7 - 1U & 0x80;
  *(undefined1 *)(param_4 + 0x45) = *(undefined1 *)(param_3 + 0x59);
  *(undefined1 *)((longlong)param_4 + 0x89) = *(undefined1 *)(param_3 + 0x58);
  *(undefined1 *)(param_4 + 0x46) = *(undefined1 *)(param_3 + 0x5b);
  *(undefined1 *)(param_4 + 0x47) = *(undefined1 *)(param_3 + 0x5d);
  *(undefined1 *)((longlong)param_4 + 0x8b) = *(undefined1 *)(param_3 + 0x5a);
  *(undefined1 *)((longlong)param_4 + 0x8d) = *(undefined1 *)(param_3 + 0x5c);
  lVar4 = IoGetConfigurationInformation();
  pwVar2 = param_4 + 4;
  *(undefined1 *)((longlong)param_4 + 0x85) = *(undefined1 *)(lVar4 + 0x1c);
  *(undefined1 *)(param_4 + 0x43) = *(undefined1 *)(lVar4 + 0x1d);
  *(undefined8 *)((longlong)param_4 + 0x79) = 0xffffffffffffffff;
  *(undefined4 *)(param_4 + 0x1a) = *(undefined4 *)pwVar2;
  param_4[0x26] = L'\x11';
  param_4[0x27] = L'\0';
  *param_4 = L'\0';
  *(int *)(param_4 + 2) = (int)param_1[0x2c] + -1;
  if (*(longlong *)(param_4 + 8) != 0) {
    ExFreePoolWithTag();
    param_4[8] = L'\0';
    param_4[9] = L'\0';
    param_4[10] = L'\0';
    param_4[0xb] = L'\0';
  }
  lVar4 = SpOpenDeviceKey(param_2,0xffffffff,_Size,pwVar6);
  if (lVar4 != 0) {
    pwVar6 = local_258;
    _Size = param_4;
    SpParseDevice(param_1,lVar4,(undefined1 *)param_4,(longlong)pwVar6);
    ZwClose(lVar4);
  }
  lVar4 = SpOpenDeviceKey(param_2,*(uint *)(param_4 + 2),_Size,pwVar6);
  if (lVar4 != 0) {
    SpParseDevice(param_1,lVar4,(undefined1 *)param_4,(longlong)local_258);
    ZwClose(lVar4);
  }
  *(undefined4 *)((longlong)param_1 + 0x794) = 10;
  local_4b4 = 0;
  local_484 = 0;
  local_498 = 0;
  uStack_490 = 0;
  local_46c = 0;
  local_4a8 = 0;
  uStack_4a0 = 0;
  local_4b0 = 0;
  RtlInitUnicodeString(&local_4a8,L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\Disk")
  ;
  local_478 = &local_4a8;
  local_488 = 0x30;
  local_480 = 0;
  local_470 = 0x40;
  local_468 = 0;
  uStack_460 = 0;
  iVar3 = ZwOpenKey(&local_4b0,0x20019,&local_488);
  if (-1 < iVar3) {
    RtlInitUnicodeString(&local_498,L"TimeoutValue");
    local_4d0 = &local_4b4;
    local_4d8 = CONCAT44(local_4d8._4_4_,0x200);
    iVar3 = ZwQueryValueKey(local_4b0,&local_498,1,local_458);
    if ((-1 < iVar3) && ((local_458[1] != 4 || (local_458[3] == 4)))) {
      iVar3 = _wcsnicmp(local_444,L"TimeoutValue",(ulonglong)(local_448 >> 1));
      if ((iVar3 == 0) &&
         (((local_458[3] != 0 && (local_458[1] == 4)) &&
          (*(int *)((longlong)local_458 + (ulonglong)(uint)local_458[2]) != 0)))) {
        *(int *)((longlong)param_1 + 0x794) =
             *(int *)((longlong)local_458 + (ulonglong)(uint)local_458[2]);
      }
    }
    ZwClose(local_4b0);
  }
  iVar3 = *piVar1;
  if ((iVar3 == 0xf) || (iVar3 == 5)) {
LAB_140021977:
    uVar5 = 0;
  }
  else {
    if (iVar3 != 3) {
      local_4c0 = local_4b8;
      local_4c8 = SpConfigurationCallout;
      local_4d0 = (undefined4 *)0x0;
      local_4d8 = 0;
      IoQueryDeviceDescription(piVar1,pwVar2,0,0);
      if (local_4b8[0] != '\0') goto LAB_140021977;
    }
    local_4b4 = 2;
    if (*piVar1 == 1) {
      local_4c0 = local_4b8;
      local_4c8 = SpConfigurationCallout;
      local_4d0 = (undefined4 *)0x0;
      local_4d8 = 0;
      IoQueryDeviceDescription(&local_4b4,pwVar2,0,0);
      if (local_4b8[0] != '\0') goto LAB_140021977;
    }
    uVar5 = 0xc00000c0;
  }
  return uVar5;
}



===== SpInitializePerformanceParams @ 1400219a4 =====

void SpInitializePerformanceParams(longlong param_1)

{
  ulonglong uVar1;
  undefined4 local_res8 [8];
  
  local_res8[0] = 0;
  if (((*(byte *)(param_1 + 0x168) & 4) == 0) ||
     (uVar1 = SpReadNumericInstanceValue
                        (*(undefined8 *)(param_1 + 0x140),L"RemainInReducedMaxQueueState",local_res8
                        ), (int)uVar1 < 0)) {
    *(undefined4 *)(param_1 + 0x788) = 0xffffffff;
    return;
  }
  *(undefined4 *)(param_1 + 0x788) = local_res8[0];
  return;
}



===== SpInitializePowerParams @ 1400219f8 =====

void SpInitializePowerParams(longlong param_1)

{
  ulonglong uVar1;
  int local_res8 [8];
  
  local_res8[0] = 0;
  if ((*(byte *)(param_1 + 0x168) & 4) == 0) {
    *(byte *)(param_1 + 0x168) = *(byte *)(param_1 + 0x168) & 0xbf;
  }
  else {
    uVar1 = SpReadNumericInstanceValue
                      (*(undefined8 *)(param_1 + 0x140),L"NeedsSystemShutdownNotification",
                       local_res8);
    if ((int)uVar1 < 0) {
      *(byte *)(param_1 + 0x168) = *(byte *)(param_1 + 0x168) & 0xbf;
    }
    else {
      *(byte *)(param_1 + 0x168) = *(byte *)(param_1 + 0x168) & 0xbf | -(local_res8[0] != 0) & 0x40U
      ;
    }
  }
  return;
}



===== SpInitializeRequestSenseParams @ 140021a68 =====

void SpInitializeRequestSenseParams(longlong param_1)

{
  ulonglong uVar1;
  char cVar2;
  uint local_res8 [2];
  
  cVar2 = '\0';
  local_res8[0] = 0;
  if ((*(byte *)(param_1 + 0x168) & 4) != 0) {
    uVar1 = SpReadNumericInstanceValue
                      (*(undefined8 *)(param_1 + 0x140),L"TotalSenseDataBytes",local_res8);
    if ((-1 < (int)uVar1) && (0x12 < local_res8[0])) {
      if (local_res8[0] < 0xff) {
        cVar2 = (char)local_res8[0] + -0x12;
      }
      else {
        cVar2 = -0x13;
      }
    }
  }
  *(char *)(param_1 + 0x748) = cVar2;
  return;
}



===== SpOpenDeviceKey @ 140021ad0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SpOpenDeviceKey(wchar_t *param_1,uint param_2,undefined8 param_3,wchar_t *param_4)

{
  longlong lVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined1 auStack_168 [32];
  longlong local_138;
  longlong local_130;
  undefined8 local_128;
  undefined8 local_120;
  longlong local_118;
  wchar_t *local_110;
  undefined4 local_108;
  undefined4 local_104;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined4 local_d0;
  undefined4 local_cc;
  longlong local_c8;
  undefined8 *local_c0;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined8 local_b0;
  undefined8 uStack_a8;
  wchar_t local_98 [64];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_168;
  local_b4 = 0;
  puVar3 = &local_120;
  local_128 = 0;
  local_104 = 0;
  local_138 = 0;
  local_118 = 0;
  local_cc = 0;
  local_120 = 0x30;
  local_e0 = 0;
  uStack_d8 = 0;
  local_108 = 0x240;
  local_f0 = 0;
  uStack_e8 = 0;
  local_100 = 0;
  uStack_f8 = 0;
  local_110 = param_1;
  iVar2 = ZwOpenKey(&local_138,0x20019);
  if ((((iVar2 < 0) && ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
     (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_ZL(WPP_GLOBAL_Control[3],0x52,puVar3,param_1,(char)iVar2);
    param_4 = param_1;
  }
  if (local_138 != 0) {
    local_130 = 0;
    RtlInitUnicodeString(&local_f0,L"Parameters");
    local_118 = local_138;
    local_110 = (wchar_t *)&local_f0;
    local_120 = CONCAT44(local_120._4_4_,0x30);
    local_108 = 0x240;
    local_100 = 0;
    uStack_f8 = 0;
    iVar2 = ZwOpenKey(&local_130,0x20019,&local_120);
    if (-1 < iVar2) {
      ZwClose(local_138);
      local_138 = local_130;
    }
    lVar1 = local_138;
    if (local_138 != 0) {
      if (param_2 == 0xffffffff) {
        RtlStringCbPrintfW(local_98,0x80,L"Device",param_4);
      }
      else {
        RtlStringCbPrintfW(local_98,0x80,L"Device%d",(ulonglong)param_2);
      }
      RtlInitUnicodeString(&local_e0,local_98);
      local_c0 = &local_e0;
      local_d0 = 0x30;
      local_b8 = 0x240;
      local_b0 = 0;
      uStack_a8 = 0;
      local_c8 = lVar1;
      ZwOpenKey(&local_128,0x20019,&local_d0);
      ZwClose(lVar1);
    }
  }
  return local_128;
}



===== SpParseDevice @ 140021cf4 =====

void SpParseDevice(longlong *param_1,undefined8 param_2,undefined1 *param_3,longlong param_4)

{
  wchar_t *_Str1;
  char *pcVar1;
  byte bVar2;
  char cVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  longlong lVar8;
  void *_Dst;
  undefined2 uVar9;
  wchar_t *pwVar10;
  longlong lVar11;
  uint uVar12;
  longlong lVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  int iVar16;
  undefined4 local_64;
  uint local_60;
  undefined8 local_58;
  longlong lStack_50;
  longlong local_48;
  void *pvStack_40;
  
  local_64 = 0;
  local_60 = 0;
  local_58 = 0;
  lStack_50 = 0;
  local_48 = 0;
  pvStack_40 = (void *)0x0;
  lVar11 = param_4;
  lVar8 = param_4;
  iVar6 = 0;
LAB_140021d46:
  if (lVar8 != param_4) {
    ExFreePoolWithTag(lVar8,0x63506353);
    lVar11 = param_4;
    lVar8 = param_4;
  }
  iVar5 = ZwEnumerateValueKey(param_2,iVar6,1,lVar8,0x200,&local_64);
  iVar16 = iVar6 + 1;
  if (-1 < iVar5) goto LAB_140021e99;
  if ((iVar5 == -0x7ffffffb) || (iVar5 == -0x3fffffdd)) {
    lVar8 = ExAllocatePoolWithTag(1,local_64,0x63506353);
    if (lVar8 == 0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
         (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_D(WPP_GLOBAL_Control[3],0x19,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,
                 local_64);
      }
      lVar8 = param_4;
    }
    else {
      iVar6 = ZwEnumerateValueKey(param_2,iVar6,1,lVar8,local_64,&local_64);
      if (-1 < iVar6) {
        lVar11 = lVar8;
        goto LAB_140021e99;
      }
      if (iVar6 == -0x7fffffe6) {
        ExFreePoolWithTag(lVar8,0x63506353);
        return;
      }
    }
  }
  else if (iVar5 == -0x7fffffe6) {
    return;
  }
  goto LAB_140021e24;
LAB_140021e99:
  if ((*(int *)(lVar11 + 4) == 4) && (iVar6 = iVar16, *(int *)(lVar11 + 0xc) != 4))
  goto LAB_140021d46;
  _Str1 = (wchar_t *)(lVar11 + 0x14);
  iVar6 = _wcsnicmp(_Str1,L"MaximumLogicalUnit",(ulonglong)(*(uint *)(lVar11 + 0x10) >> 1));
  if (iVar6 == 0) {
    if (*(int *)(lVar11 + 4) == 4) {
      bVar2 = *(byte *)((ulonglong)*(uint *)(lVar11 + 8) + lVar8);
      *(byte *)((longlong)param_1 + 0x17a) = bVar2;
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_D(WPP_GLOBAL_Control[3],0x1d,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,
                 (uint)bVar2);
      }
      if (8 < *(byte *)((longlong)param_1 + 0x17a)) {
        *(undefined1 *)((longlong)param_1 + 0x17a) = 8;
      }
      goto LAB_140021f7f;
    }
    iVar6 = iVar16;
    if ((((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) == 0)) ||
       (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 3)) goto LAB_140021d46;
    uVar9 = 0x1c;
  }
  else {
LAB_140021f7f:
    iVar6 = _wcsnicmp(_Str1,L"InitiatorTargetId",(ulonglong)(*(uint *)(lVar11 + 0x10) >> 1));
    if (iVar6 == 0) {
      if (*(int *)(lVar11 + 4) != 4) {
        iVar6 = iVar16;
        if ((((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) == 0)) ||
           (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 3)) goto LAB_140021d46;
        uVar9 = 0x1e;
        goto LAB_140022b3f;
      }
      bVar2 = *(byte *)((ulonglong)*(uint *)(lVar11 + 8) + lVar8);
      param_3[0x79] = bVar2;
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_D(WPP_GLOBAL_Control[3],0x1f,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,
                 (uint)bVar2);
      }
      if ((int)((byte)param_3[0x91] - 1) < (int)(uint)(byte)param_3[0x79]) {
        param_3[0x79] = 0xff;
      }
    }
    iVar6 = _wcsnicmp(_Str1,L"ScsiDebug",(ulonglong)(*(uint *)(lVar11 + 0x10) >> 1));
    if ((iVar6 == 0) && (*(int *)(lVar11 + 4) != 4)) {
      iVar6 = iVar16;
      if (((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) == 0 ||
          (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 3)))) goto LAB_140021d46;
      uVar9 = 0x20;
    }
    else {
      iVar6 = _wcsnicmp(_Str1,L"BreakPointOnEntry",(ulonglong)(*(uint *)(lVar11 + 0x10) >> 1));
      if (iVar6 == 0) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_(WPP_GLOBAL_Control[3],0x21,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids);
        }
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      iVar6 = _wcsnicmp(_Str1,L"DisableSynchronousTransfers",
                        (ulonglong)(*(uint *)(lVar11 + 0x10) >> 1));
      if (((iVar6 == 0) &&
          (*(uint *)(param_1 + 3) = *(uint *)(param_1 + 3) | 8,
          (undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0 &&
          (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
        WPP_SF_(WPP_GLOBAL_Control[3],0x22,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids);
      }
      iVar6 = _wcsnicmp(_Str1,L"DisableDisconnects",(ulonglong)(*(uint *)(lVar11 + 0x10) >> 1));
      if (((iVar6 == 0) &&
          (*(uint *)(param_1 + 3) = *(uint *)(param_1 + 3) | 4,
          (undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0 &&
          (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
        WPP_SF_(WPP_GLOBAL_Control[3],0x23,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids);
      }
      iVar6 = _wcsnicmp(_Str1,L"DisableTaggedQueuing",(ulonglong)(*(uint *)(lVar11 + 0x10) >> 1));
      if ((((iVar6 == 0) && (*param_3 = 1, (undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)
           ) && ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_(WPP_GLOBAL_Control[3],0x24,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids);
      }
      iVar6 = _wcsnicmp(_Str1,L"DisableMultipleRequests",(ulonglong)(*(uint *)(lVar11 + 0x10) >> 1))
      ;
      if (((iVar6 == 0) &&
          (param_3[1] = 1, (undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0 &&
          (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
        WPP_SF_(WPP_GLOBAL_Control[3],0x25,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids);
      }
      iVar6 = _wcsnicmp(_Str1,L"MinimumUCXAddress",(ulonglong)(*(uint *)(lVar11 + 0x10) >> 1));
      if ((iVar6 == 0) && (*(int *)(lVar11 + 4) == 3)) {
        param_1[0xed] = *(longlong *)((ulonglong)*(uint *)(lVar11 + 8) + lVar8);
      }
      pwVar10 = L"MaximumUCXAddress";
      uVar14 = (ulonglong)(*(uint *)(lVar11 + 0x10) >> 1);
      iVar6 = _wcsnicmp(_Str1,L"MaximumUCXAddress",uVar14);
      if ((iVar6 == 0) && (*(int *)(lVar11 + 4) == 3)) {
        param_1[0xee] = *(longlong *)((ulonglong)*(uint *)(lVar11 + 8) + lVar8);
      }
      if (param_1[0xee] == 0) {
        *(undefined4 *)(param_1 + 0xee) = 0xffffffff;
        *(undefined4 *)((longlong)param_1 + 0x774) = 0;
      }
      if (param_1[0xee] + -0x1000 <= param_1[0xed]) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_i(WPP_GLOBAL_Control[3],pwVar10,uVar14,param_1[0xed]);
        }
        param_1[0xed] = 0;
      }
      iVar6 = _wcsnicmp(_Str1,L"DriverParameters",(ulonglong)(*(uint *)(lVar11 + 0x10) >> 1));
      if (iVar6 == 0) {
        if (*(int *)(lVar11 + 0xc) == 0) {
          iVar6 = iVar16;
          goto LAB_140021d46;
        }
        if (*(longlong *)(param_3 + 0x10) != 0) {
          ExFreePoolWithTag(*(longlong *)(param_3 + 0x10),0);
        }
        _Dst = (void *)SpAllocatePoolEx(0,(ulonglong)*(uint *)(lVar11 + 0xc),0x61506353,
                                        *(undefined8 *)(*param_1 + 8),0x696e6974,0x82b);
        *(void **)(param_3 + 0x10) = _Dst;
        if (_Dst != (void *)0x0) {
          if (*(int *)(lVar11 + 4) == 1) {
            lStack_50 = (ulonglong)*(uint *)(lVar11 + 8) + lVar11;
            local_58._0_4_ = CONCAT22(*(undefined2 *)(lVar11 + 0xc),*(undefined2 *)(lVar11 + 0xc));
            local_48 = (ulonglong)
                       CONCAT42((int)((ulonglong)local_48 >> 0x20),*(undefined2 *)(lVar11 + 0xc)) <<
                       0x10;
            pvStack_40 = _Dst;
            iVar6 = RtlUnicodeStringToAnsiString(&local_48,&local_58,0);
            if (iVar6 < 0) {
              ExFreePoolWithTag(*(undefined8 *)(param_3 + 0x10),0);
              *(undefined8 *)(param_3 + 0x10) = 0;
            }
          }
          else {
            memcpy(_Dst,(void *)((ulonglong)*(uint *)(lVar11 + 8) + lVar11),
                   (ulonglong)*(uint *)(lVar11 + 0xc));
          }
        }
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_(WPP_GLOBAL_Control[3],0x27,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids);
        }
      }
      iVar6 = _wcsnicmp(_Str1,L"MaximumSGList",(ulonglong)(*(uint *)(lVar11 + 0x10) >> 1));
      if (iVar6 == 0) {
        if (*(int *)(lVar11 + 4) != 4) {
          iVar6 = iVar16;
          if ((((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) == 0)) ||
             (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 3)) goto LAB_140021d46;
          uVar9 = 0x28;
          goto LAB_140022b3f;
        }
        bVar2 = *(byte *)((ulonglong)*(uint *)(lVar11 + 8) + lVar8);
        uVar12 = (uint)bVar2;
        *(uint *)(param_3 + 0x4c) = uVar12;
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_D(WPP_GLOBAL_Control[3],0x29,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,
                   (uint)bVar2);
          uVar12 = *(uint *)(param_3 + 0x4c);
        }
        if ((param_3[0x89] == '\0') || (param_3[0x82] != '\0')) {
          uVar7 = 0xff;
        }
        else {
          uVar7 = 0xffffffff;
        }
        if (uVar7 < uVar12) {
          *(uint *)(param_3 + 0x4c) = uVar7;
        }
        else if (uVar12 < 0x10) {
          *(undefined4 *)(param_3 + 0x4c) = 0x10;
        }
      }
      iVar6 = _wcsnicmp(_Str1,L"NumberOfRequests",(ulonglong)(*(uint *)(lVar11 + 0x10) >> 1));
      if (iVar6 == 0) {
        if (*(int *)(lVar11 + 4) != 4) {
          iVar6 = iVar16;
          if ((((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) == 0)) ||
             (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 3)) goto LAB_140021d46;
          uVar9 = 0x2a;
          goto LAB_140022b3f;
        }
        uVar12 = *(uint *)((ulonglong)*(uint *)(lVar11 + 8) + lVar8);
        if (uVar12 < 0x10) {
          uVar12 = 0x10;
        }
        else if (0xff < uVar12) {
          uVar12 = 0xff;
        }
        *(uint *)(param_1 + 0x44) = uVar12;
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_D(WPP_GLOBAL_Control[3],0x2b,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,
                   uVar12);
        }
      }
      iVar6 = _wcsnicmp(_Str1,L"ResourceList",(ulonglong)(*(uint *)(lVar11 + 0x10) >> 1));
      if ((iVar6 == 0) ||
         (iVar6 = _wcsnicmp(_Str1,L"Configuration Data",(ulonglong)(*(uint *)(lVar11 + 0x10) >> 1)),
         iVar6 == 0)) {
        if ((*(int *)(lVar11 + 4) != 9) || (*(uint *)(lVar11 + 0xc) < 4)) {
          iVar6 = iVar16;
          if ((((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) == 0)) ||
             (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 3)) goto LAB_140021d46;
          uVar9 = 0x2c;
          goto LAB_140022b3f;
        }
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_(WPP_GLOBAL_Control[3],0x2d,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids);
        }
        lVar13 = (ulonglong)*(uint *)(lVar11 + 8) + lVar8;
        uVar12 = 0;
        *(undefined4 *)(param_3 + 8) = *(undefined4 *)(lVar13 + 4);
        *(undefined4 *)(param_3 + 0x34) = *(undefined4 *)(lVar13 + 4);
        if (*(int *)(lVar13 + 0xc) != 0) {
          do {
            uVar14 = (ulonglong)uVar12;
            pcVar1 = (char *)(lVar13 + (uVar14 * 5 + 4) * 4);
            if (*(uint *)(lVar11 + 0xc) < ((int)pcVar1 - (int)lVar13) + 0x14U) {
              if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
                 (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                WPP_SF_(WPP_GLOBAL_Control[3],0x2e,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids)
                ;
              }
              break;
            }
            cVar3 = *pcVar1;
            if (cVar3 == '\x01') {
              uVar15 = (ulonglong)local_60;
              if (local_60 < *(uint *)(param_3 + 100)) {
                *(undefined8 *)(*(longlong *)(param_3 + 0x18) + uVar15 * 0x10) =
                     *(undefined8 *)(lVar13 + 0x14 + uVar14 * 0x14);
                *(undefined4 *)(*(longlong *)(param_3 + 0x18) + 8 + uVar15 * 0x10) =
                     *(undefined4 *)(lVar13 + 0x1c + uVar14 * 0x14);
                *(undefined1 *)(*(longlong *)(param_3 + 0x18) + 0xc + uVar15 * 0x10) = 0;
LAB_14002289e:
                local_60 = local_60 + 1;
              }
              else if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                       ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
                      (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                uVar9 = 0x2f;
LAB_140022860:
                WPP_SF_(WPP_GLOBAL_Control[3],uVar9,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids
                       );
              }
            }
            else if (cVar3 == '\x02') {
              *(undefined4 *)(param_3 + 0x40) = *(undefined4 *)(lVar13 + 0x18 + uVar14 * 0x14);
              *(undefined4 *)(param_3 + 0x3c) = *(undefined4 *)(lVar13 + 0x14 + uVar14 * 0x14);
            }
            else if (cVar3 == '\x03') {
              uVar15 = (ulonglong)local_60;
              if (local_60 < *(uint *)(param_3 + 100)) {
                *(undefined8 *)(*(longlong *)(param_3 + 0x18) + uVar15 * 0x10) =
                     *(undefined8 *)(lVar13 + 0x14 + uVar14 * 0x14);
                *(undefined4 *)(*(longlong *)(param_3 + 0x18) + 8 + uVar15 * 0x10) =
                     *(undefined4 *)(lVar13 + 0x1c + uVar14 * 0x14);
                *(undefined1 *)(*(longlong *)(param_3 + 0x18) + 0xc + uVar15 * 0x10) = 1;
                goto LAB_14002289e;
              }
              if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
                 (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                uVar9 = 0x30;
                goto LAB_140022860;
              }
            }
            else if (cVar3 == '\x04') {
              *(undefined4 *)(param_3 + 0x50) = *(undefined4 *)(lVar13 + 0x14 + uVar14 * 0x14);
              *(undefined4 *)(param_3 + 0x54) = *(undefined4 *)(lVar13 + 0x18 + uVar14 * 0x14);
            }
            else if (cVar3 == '\x05') {
              uVar7 = *(uint *)(lVar13 + 0x14 + uVar14 * 0x14);
              if ((uVar7 < 6) ||
                 ((longlong)(ulonglong)*(uint *)(lVar11 + 0xc) <
                  (longlong)(pcVar1 + ((ulonglong)uVar7 - lVar13) + 0x14))) {
                if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0 &&
                    (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
                  uVar9 = 0x31;
                  goto LAB_140022860;
                }
              }
              else {
                param_3[0x79] = *(undefined1 *)(lVar13 + 0x28 + uVar14 * 0x14);
              }
            }
            uVar12 = uVar12 + 1;
          } while (uVar12 < *(uint *)(lVar13 + 0xc));
        }
      }
      iVar6 = _wcsnicmp(_Str1,L"UncachedExtAlignment",(ulonglong)(*(uint *)(lVar11 + 0x10) >> 1));
      if (iVar6 == 0) {
        if (*(int *)(lVar11 + 4) != 4) {
          iVar6 = iVar16;
          if ((((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) == 0)) ||
             (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 3)) goto LAB_140021d46;
          uVar9 = 0x32;
          goto LAB_140022b3f;
        }
        uVar12 = *(uint *)((ulonglong)*(uint *)(lVar11 + 8) + lVar8);
        if (uVar12 < 0x11) {
          if (uVar12 < 3) {
            uVar12 = 3;
          }
        }
        else {
          uVar12 = 0x10;
        }
        iVar6 = 1 << ((byte)uVar12 & 0x1f);
        *(int *)((longlong)param_1 + 0x78c) = iVar6;
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_D(WPP_GLOBAL_Control[3],0x33,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,iVar6
                  );
        }
      }
      iVar6 = _wcsnicmp(_Str1,L"ResetHoldTime",(ulonglong)(*(uint *)(lVar11 + 0x10) >> 1));
      if (iVar6 == 0) {
        if (*(int *)(lVar11 + 4) != 4) {
          iVar6 = iVar16;
          if ((((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) == 0)) ||
             (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 3)) goto LAB_140021d46;
          uVar9 = 0x34;
          goto LAB_140022b3f;
        }
        uVar12 = *(uint *)((ulonglong)*(uint *)(lVar11 + 8) + lVar8);
        uVar7 = 0x3c;
        if (uVar12 < 0x3d) {
          uVar7 = uVar12;
        }
        *(uint *)(param_1 + 0xf4) = uVar7;
      }
      iVar6 = _wcsnicmp(_Str1,L"CreateInitiatorLU",(ulonglong)(*(uint *)(lVar11 + 0x10) >> 1));
      if (iVar6 == 0) {
        if (*(int *)(lVar11 + 4) != 4) {
          iVar6 = iVar16;
          if ((((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) == 0)) ||
             (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 3)) goto LAB_140021d46;
          uVar9 = 0x35;
          goto LAB_140022b3f;
        }
        *(bool *)(param_1 + 0xfd) = *(int *)((ulonglong)*(uint *)(lVar11 + 8) + lVar8) != 0;
      }
      iVar5 = _wcsnicmp(_Str1,L"VirtualDevice",(ulonglong)(*(uint *)(lVar11 + 0x10) >> 1));
      iVar6 = iVar16;
      if (iVar5 != 0) goto LAB_140021d46;
      if (*(int *)(lVar11 + 4) == 4) {
        *(byte *)(param_1 + 0x2d) =
             -(*(int *)((ulonglong)*(uint *)(lVar11 + 8) + lVar8) != 0) & 0x80U |
             *(byte *)(param_1 + 0x2d) & 0x7f;
        goto LAB_140021e24;
      }
      if ((((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) == 0)) ||
         (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 3)) goto LAB_140021d46;
      uVar9 = 0x36;
    }
  }
LAB_140022b3f:
  WPP_SF_(WPP_GLOBAL_Control[3],uVar9,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids);
LAB_140021e24:
  iVar6 = iVar16;
  goto LAB_140021d46;
}



===== SpQueryPnpInterfaceFlags @ 140022bc4 =====

undefined4 SpQueryPnpInterfaceFlags(longlong param_1,int param_2,undefined8 param_3)

{
  int *piVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar3 = 0;
  if (*(uint *)(param_1 + 0x2c) != 0) {
    piVar1 = (int *)(param_1 + 0x60);
    do {
      if (*piVar1 == param_2) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_dL(WPP_GLOBAL_Control[3],0x53,param_3,param_2,
                    (char)*(undefined4 *)(param_1 + 100 + uVar3 * 8));
        }
        return *(undefined4 *)(param_1 + 100 + uVar3 * 8);
      }
      uVar2 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
      piVar1 = piVar1 + 2;
    } while (uVar2 < *(uint *)(param_1 + 0x2c));
  }
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_D(WPP_GLOBAL_Control[3],0x54,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,param_2);
  }
  return 0;
}



===== SpReportNewAdapter @ 140022c7c =====

ulonglong SpReportNewAdapter(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined8 local_res8;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar5 = *(longlong *)(lVar1 + 0x1f8);
  local_res8 = 0;
  uVar2 = IoReportDetectedDevice
                    (*(undefined8 *)(param_1 + 8),*(undefined4 *)(lVar5 + 8),
                     *(undefined4 *)(lVar5 + 4),*(undefined4 *)(lVar5 + 100),
                     *(undefined8 *)(lVar1 + 0x200),0,~*(byte *)(lVar1 + 0x168) & 1,&local_res8);
  uVar3 = (ulonglong)uVar2;
  if (-1 < (int)uVar2) {
    uVar3 = SpWriteNumericInstanceValue(local_res8,L"BusNumber",*(undefined4 *)(lVar5 + 4));
    if ((int)(uint)uVar3 < (int)uVar2) {
      uVar2 = (uint)uVar3;
    }
    uVar3 = SpWriteNumericInstanceValue(local_res8,L"SlotNumber",*(undefined4 *)(lVar5 + 100));
    if ((int)(uint)uVar3 < (int)uVar2) {
      uVar2 = (uint)uVar3;
    }
    uVar4 = SpWriteNumericInstanceValue
                      (local_res8,L"LegacyInterfaceType",*(undefined4 *)(lVar5 + 8));
    uVar3 = (ulonglong)uVar2;
    if ((int)uVar4 < (int)uVar2) {
      uVar3 = uVar4 & 0xffffffff;
    }
    if (-1 < (int)uVar3) {
      lVar5 = IoAttachDeviceToDeviceStack(param_1,local_res8);
      *(longlong *)(lVar1 + 0x10) = lVar5;
      *(undefined8 *)(lVar1 + 0x140) = local_res8;
      uVar3 = (ulonglong)(~-(uint)(lVar5 != 0) & 0xc0000001);
    }
  }
  return uVar3;
}



===== WppLoadTracingSupport @ 140022d90 =====

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



===== WppTraceCallback @ 140022ee0 =====

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



===== wil_details_EvaluateFeatureDependencies @ 140023168 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  uint uVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  bool bVar5;
  
  puVar4 = (undefined *)0x0;
  ppuVar3 = &Feature_851677496__private_descriptor;
  ppuVar2 = &Feature_851677496__private_descriptor;
  do {
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x0001400231a3;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_14002321d:
  while( true ) {
    if (&UNK_1400168d7 < ppuVar3) {
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
      if (&UNK_1400168d7 < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x0001400231a3:
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
      if (&UNK_1400168d7 < ppuVar2) goto LAB_14002321d;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_14002321d;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140023258 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_1400232f0;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_1400232f0;
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
LAB_1400232f0:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140023340 =====

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
      for (ppuVar2 = &Feature_851677496__private_descriptor;
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
              if (&UNK_1400168d7 < ppuVar2) {
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 1400233c0 =====

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
  for (ppuVar3 = &Feature_851677496__private_descriptor; ppuVar3 < &wil_details_featureDescriptors_z
      ; ppuVar3 = ppuVar3 + 1) {
    if (*ppuVar3 != (undefined *)0x0) goto LAB_1400234bd;
  }
LAB_1400234c6:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_1400234bd:
  if (ppuVar3 == (undefined **)0x0) goto LAB_1400234c6;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14002348e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14002348e;
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
    if (&UNK_1400168d7 < ppuVar3) goto LAB_1400234c6;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_1400234bd;
}



===== ScsiPortFdoCreateClose @ 1400234f0 =====

undefined4 ScsiPortFdoCreateClose(longlong param_1,longlong param_2)

{
  longlong lVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  pcVar2 = *(char **)(param_2 + 0xb8);
  uVar3 = 0;
  LOCK();
  *(int *)(lVar1 + 0x4c) = *(int *)(lVar1 + 0x4c) + 1;
  UNLOCK();
  if (*pcVar2 == '\0') {
    if (*(int *)(lVar1 + 0xc) == 0) {
      uVar3 = 0;
      if (*(char *)(lVar1 + 9) != '\0') {
        uVar3 = 0xc00000a3;
      }
    }
    else {
      uVar3 = 0xc00000c0;
    }
  }
  *(undefined4 *)(param_2 + 0x30) = uVar3;
  SpReleaseRemoveLock(param_1,(char)param_2);
  SpCompleteRequest(param_1,param_2,(undefined *)0x0,1);
  return uVar3;
}



===== ScsiPortFdoDeviceControl @ 140023560 =====

ulonglong ScsiPortFdoDeviceControl(longlong param_1,longlong param_2,undefined8 param_3)

{
  int *piVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong lVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  undefined4 extraout_var_01;
  undefined4 extraout_var_02;
  undefined4 extraout_var_03;
  undefined8 uVar9;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  puVar3 = *(undefined8 **)(param_1 + 0x40);
  uVar7 = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  lVar4 = *(longlong *)(param_1 + 0x40);
  LOCK();
  piVar1 = (int *)(lVar4 + 0x4c);
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if (*(int *)(lVar4 + 0xc) == 0) {
    uVar5 = SpRequestValidAdapterPowerStateSynchronous(puVar3);
    if (-1 < (int)uVar5) {
      uVar5 = *(uint *)(lVar2 + 0x18);
      if (uVar5 < 0x4d009) {
        if (uVar5 == 0x4d008) {
          uVar5 = SpSendMiniPortIoctl(*(longlong **)(param_1 + 0x40),param_2);
        }
        else {
          if (uVar5 != 0x4100c) {
            if (uVar5 == 0x41010) {
              if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 0x18) {
                uVar7 = 0xc0000023;
              }
              else {
                lVar2 = *(longlong *)(param_1 + 0x40);
                puVar3 = *(undefined8 **)(param_2 + 0x18);
                uVar9 = *(undefined8 *)(lVar2 + 0x3ec);
                *puVar3 = *(undefined8 *)(lVar2 + 0x3e4);
                puVar3[1] = uVar9;
                puVar3[2] = *(undefined8 *)(lVar2 + 0x3f4);
                *(undefined8 *)(param_2 + 0x38) = 0x18;
              }
LAB_1400236f8:
              *(uint *)(param_2 + 0x30) = uVar7;
              SpReleaseRemoveLock(param_1,(char)param_2);
              SpCompleteRequest(param_1,param_2,(undefined *)0x0,0);
              return (ulonglong)uVar7;
            }
            if (uVar5 == 0x4101c) {
              uVar6 = SpHandleIoctlScsiRescanBus(param_1,param_2);
              return CONCAT44(extraout_var_00,uVar6);
            }
            if (uVar5 == 0x41020) {
              uVar6 = SpHandleIoctlScsiGetDumpPointers(param_1,param_2);
              return CONCAT44(extraout_var,uVar6);
            }
            if (uVar5 == 0x41024) {
              if (*(char *)(param_2 + 0x40) == '\0') {
                if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0x38) {
                  uVar7 = 0xc000000d;
                }
                else {
                  puVar3 = *(undefined8 **)(param_2 + 0x18);
                  ExFreePoolWithTag(puVar3[2],0x50706353);
                  *puVar3 = 0;
                  puVar3[1] = 0;
                  puVar3[2] = 0;
                  puVar3[3] = 0;
                  puVar3[4] = 0;
                  puVar3[5] = 0;
                  puVar3[6] = 0;
                }
              }
              else {
                uVar7 = 0xc0000022;
              }
              goto LAB_1400236f8;
            }
            if (uVar5 == 0x4d004) {
              uVar9 = 0;
              goto LAB_140023637;
            }
            goto LAB_140023767;
          }
          uVar8 = SpGetInquiryData(*(longlong *)(param_1 + 0x40),param_2);
          uVar5 = (uint)uVar8;
        }
        *(uint *)(param_2 + 0x30) = uVar5;
        goto LAB_1400235a5;
      }
      if (uVar5 == 0x4d014) {
        uVar9 = CONCAT71((int7)((ulonglong)param_3 >> 8),1);
LAB_140023637:
        uVar8 = SpHandleIoctlScsiPassThrough(param_1,param_2,uVar9);
        return uVar8;
      }
      if (uVar5 == 0x2d1400) {
        uVar6 = SpHandleIoctlStorageQueryProperty(param_1,param_2);
        return CONCAT44(extraout_var_03,uVar6);
      }
      if (uVar5 == 0x2d5000) {
LAB_1400237b6:
        uVar6 = SpHandleIoctlStorageResetBus(param_1,param_2);
        return CONCAT44(extraout_var_02,uVar6);
      }
      if (uVar5 == 0x2d5014) {
        uVar7 = SpHandleIoctlStorageBreakReservation(param_1,param_2);
        return CONCAT44(extraout_var_01,uVar7);
      }
      if (uVar5 == 0x2dd000) goto LAB_1400237b6;
LAB_140023767:
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_D(WPP_GLOBAL_Control[3],0x21,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids,uVar5);
      }
      uVar5 = 0xc0000010;
    }
  }
  else {
    uVar5 = 0xc00000c0;
  }
  *(uint *)(param_2 + 0x30) = uVar5;
LAB_1400235a5:
  SpReleaseRemoveLock(param_1,(char)param_2);
  SpCompleteRequest(param_1,param_2,(undefined *)0x0,0);
  return (ulonglong)uVar5;
}



===== SpHandleIoctlScsiGetDumpPointers @ 1400237e4 =====

undefined4 SpHandleIoctlScsiGetDumpPointers(longlong param_1,longlong param_2)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  int iVar8;
  undefined4 uVar9;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  uVar9 = 0;
  if (*(char *)(param_2 + 0x40) == '\0') {
    if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 0x38) {
      uVar9 = 0xc0000023;
    }
    else {
      puVar4 = *(undefined8 **)(param_2 + 0x18);
      *puVar4 = 0;
      puVar4[1] = 0;
      puVar4[2] = 0;
      puVar4[3] = 0;
      puVar4[4] = 0;
      puVar4[5] = 0;
      puVar4[6] = 0;
      *puVar4 = *(undefined8 *)(lVar3 + 0x1d0);
      puVar4[1] = lVar3 + 0x268;
      puVar7 = (undefined8 *)
               SpAllocatePoolEx(0,0x98,0x50706353,*(undefined8 *)(param_1 + 8),0x696e7472,0xb16);
      if (puVar7 == (undefined8 *)0x0) {
        uVar9 = 0xc000009a;
      }
      else {
        puVar5 = *(undefined8 **)(lVar3 + 0x1f8);
        uVar6 = puVar5[1];
        *puVar7 = *puVar5;
        puVar7[1] = uVar6;
        uVar6 = puVar5[3];
        puVar7[2] = puVar5[2];
        puVar7[3] = uVar6;
        uVar6 = puVar5[5];
        puVar7[4] = puVar5[4];
        puVar7[5] = uVar6;
        uVar6 = puVar5[7];
        puVar7[6] = puVar5[6];
        puVar7[7] = uVar6;
        uVar6 = puVar5[9];
        puVar7[8] = puVar5[8];
        puVar7[9] = uVar6;
        uVar6 = puVar5[0xb];
        puVar7[10] = puVar5[10];
        puVar7[0xb] = uVar6;
        uVar6 = puVar5[0xd];
        puVar7[0xc] = puVar5[0xc];
        puVar7[0xd] = uVar6;
        uVar6 = puVar5[0xf];
        puVar7[0xe] = puVar5[0xe];
        puVar7[0xf] = uVar6;
        uVar6 = puVar5[0x11];
        puVar7[0x10] = puVar5[0x10];
        puVar7[0x11] = uVar6;
        puVar7[0x12] = puVar5[0x12];
        if ((*(byte *)(lVar3 + 0x168) & 2) != 0) {
          *(undefined4 *)((longlong)puVar7 + 100) = *(undefined4 *)(lVar3 + 0x174);
          *(undefined4 *)((longlong)puVar7 + 4) = *(undefined4 *)(lVar3 + 0x170);
        }
        puVar4[2] = puVar7;
        puVar4[3] = *(undefined8 *)(lVar3 + 0x228);
        puVar4[4] = *(undefined8 *)(lVar3 + 0x480);
        iVar8 = *(int *)(lVar3 + 0x214);
        iVar1 = *(int *)(lVar3 + 0x158);
        if (iVar8 == 0) {
          iVar8 = 0x10;
          *(undefined4 *)(lVar3 + 0x214) = 0x10;
        }
        if (*(char *)(lVar3 + 0x48c) != '\0') {
          iVar8 = iVar8 + *(byte *)(lVar3 + 0x748) + 0x12;
        }
        iVar2 = *(int *)(lVar3 + 0x220);
        *(undefined1 *)((longlong)puVar4 + 0x2c) = 1;
        *(uint *)(puVar4 + 5) = (iVar8 + 7U & 0xfffffff8) * iVar2 + 0xfff + iVar1 & 0xfffff000;
        *(undefined8 *)(param_2 + 0x38) = 0x38;
      }
    }
  }
  else {
    uVar9 = 0xc0000022;
  }
  *(undefined4 *)(param_2 + 0x30) = uVar9;
  SpReleaseRemoveLock(param_1,(char)param_2);
  SpCompleteRequest(param_1,param_2,(undefined *)0x0,0);
  return uVar9;
}



===== SpHandleIoctlScsiPassThrough @ 1400239cc =====

ulonglong SpHandleIoctlScsiPassThrough(longlong param_1,longlong param_2,undefined8 param_3)

{
  ulonglong uVar1;
  
  uVar1 = SpSendPassThrough(*(longlong **)(param_1 + 0x40),param_2,param_3);
  *(int *)(param_2 + 0x30) = (int)uVar1;
  SpReleaseRemoveLock(param_1,(char)param_2);
  SpCompleteRequest(param_1,param_2,(undefined *)0x0,0);
  return uVar1 & 0xffffffff;
}



===== SpHandleIoctlScsiRescanBus @ 140023a24 =====

undefined4 SpHandleIoctlScsiRescanBus(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  undefined4 uVar2;
  undefined4 local_res8 [2];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  longlong local_40;
  code *local_38;
  undefined4 *local_30;
  undefined8 *local_28;
  undefined1 local_20;
  undefined4 local_1f;
  undefined2 local_1b;
  undefined1 local_19;
  
  plVar1 = *(longlong **)(param_1 + 0x40);
  local_res8[0] = 0;
  local_48 = 0;
  local_40 = 0;
  local_1f = 0;
  local_1b = 0;
  local_19 = 0;
  local_58 = 0;
  uStack_50 = 0;
  KeInitializeEvent(&local_58,1);
  local_20 = 1;
  local_38 = SpSignalEnumerationCompletion;
  local_28 = &local_58;
  local_30 = local_res8;
  SpEnumerateAdapterAsynchronous(plVar1,&local_40);
  KeWaitForSingleObject(&local_58,0,0,0,0);
  IoInvalidateDeviceRelations(plVar1[0x28],0);
  uVar2 = local_res8[0];
  *(undefined4 *)(param_2 + 0x30) = local_res8[0];
  SpReleaseRemoveLock(param_1,(char)param_2);
  SpCompleteRequest(param_1,param_2,(undefined *)0x0,0);
  return uVar2;
}



===== SpHandleIoctlStorageBreakReservation @ 140023b18 =====

uint SpHandleIoctlStorageBreakReservation(longlong param_1,longlong param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  char local_res8 [8];
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  local_res8[0] = '\x01';
  uVar2 = -(uint)(*(uint *)(lVar1 + 0x10) == 0) & 0xc000000d;
  if ((*(uint *)(lVar1 + 0x10) < 8) || (**(int **)(param_2 + 0x18) == 8)) {
    uVar3 = uVar2;
    if (-1 < (int)uVar2) {
      *(byte *)(lVar1 + 3) = *(byte *)(lVar1 + 3) | 1;
      uVar4 = (ulonglong)*(uint *)(lVar1 + 0x18);
      uVar2 = SpSendReset(param_1,param_2,*(uint *)(lVar1 + 0x18),local_res8);
      if (((((int)uVar2 < 0) && ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_Ld(WPP_GLOBAL_Control[3],0x1f,uVar4,uVar2,local_res8[0]);
      }
      uVar3 = 0x103;
      if (local_res8[0] == '\0') {
        return 0x103;
      }
    }
  }
  else {
    uVar2 = 0xc000000d;
    uVar3 = 0xc000000d;
  }
  *(uint *)(param_2 + 0x30) = uVar2;
  SpReleaseRemoveLock(param_1,(char)param_2);
  SpCompleteRequest(param_1,param_2,(undefined *)0x0,0);
  return uVar3;
}



===== SpHandleIoctlStorageResetBus @ 140023c04 =====

undefined4 SpHandleIoctlStorageResetBus(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  char local_res8 [8];
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  local_res8[0] = '\x01';
  if (*(int *)(lVar1 + 0x10) == 0) {
    iVar2 = -0x3ffffff3;
    uVar3 = 0xc000000d;
  }
  else {
    *(byte *)(lVar1 + 3) = *(byte *)(lVar1 + 3) | 1;
    uVar4 = (ulonglong)*(uint *)(lVar1 + 0x18);
    iVar2 = SpSendReset(param_1,param_2,*(uint *)(lVar1 + 0x18),local_res8);
    if ((((iVar2 < 0) && ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_Ld(WPP_GLOBAL_Control[3],0x20,uVar4,iVar2,local_res8[0]);
    }
    uVar3 = 0x103;
    if (local_res8[0] == '\0') {
      return 0x103;
    }
  }
  *(int *)(param_2 + 0x30) = iVar2;
  SpReleaseRemoveLock(param_1,(char)param_2);
  SpCompleteRequest(param_1,param_2,(undefined *)0x0,0);
  return uVar3;
}



===== SpSendMiniPortIoctl @ 140023cd8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 SpSendMiniPortIoctl(longlong *param_1,longlong param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  longlong lVar5;
  undefined4 uVar6;
  int iVar7;
  longlong *plVar8;
  longlong lVar9;
  undefined1 uVar10;
  undefined1 auStack_118 [32];
  undefined8 *local_f8;
  undefined8 *local_f0;
  undefined8 *local_e8;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined2 local_a8;
  undefined1 local_a6;
  undefined1 local_a3;
  undefined1 local_a2;
  undefined1 local_a1;
  undefined1 local_9f;
  undefined4 local_9c;
  uint local_98;
  int local_94;
  int *local_90;
  longlong local_78;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_118;
  *(undefined8 *)(param_2 + 0x38) = 0;
  piVar4 = *(int **)(param_2 + 0x18);
  local_d0 = 0;
  uStack_c8 = 0;
  local_c0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_d8 = 1;
  uVar2 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  if (uVar2 < 0x1c) {
    uVar6 = 0xc000000d;
  }
  else if (*piVar4 == 0x1c) {
    uVar1 = piVar4[6] + 0x1c;
    if ((uVar1 < 0x1c) || (uVar1 < (uint)piVar4[6])) {
      return 0xc000000d;
    }
    uVar3 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
    if ((uVar1 <= uVar3) || (uVar1 <= uVar2)) {
      uVar10 = (undefined1)param_2;
      plVar8 = SpFindSafeLogicalUnit(*param_1,0xff,uVar10);
      if (plVar8 == (longlong *)0x0) {
        uVar6 = 0xc00000c0;
      }
      else {
        KeInitializeEvent(&local_d0,0,0);
        local_e8 = &local_b8;
        local_f0 = &local_d0;
        local_f8 = &local_d8;
        lVar9 = IoBuildSynchronousFsdRequest(0xf,*param_1,piVar4,uVar1);
        if (lVar9 != 0) {
          lVar5 = *(longlong *)(lVar9 + 0xb8);
          *(undefined2 **)(lVar5 + -0x40) = &local_a8;
          *(undefined2 *)(lVar5 + -0x48) = 0x10f;
          memset(&local_a8,0,0x58);
          local_a3 = *(undefined1 *)((longlong)plVar8 + 0x154);
          local_a2 = *(undefined1 *)((longlong)plVar8 + 0x155);
          local_a1 = *(undefined1 *)((longlong)plVar8 + 0x156);
          local_a8 = 0x58;
          local_a6 = 2;
          local_9c = 0x1c0;
          local_9f = 0x20;
          local_94 = piVar4[3];
          local_98 = uVar1;
          local_90 = piVar4;
          local_78 = lVar9;
          KeFlushIoBuffers(*(undefined8 *)(lVar9 + 8),0,1);
          iVar7 = IofCallDriver(*param_1,lVar9);
          if (iVar7 == 0x103) {
            local_f8 = (undefined8 *)0x0;
            KeWaitForSingleObject(&local_d0,0,0,0);
          }
          uVar2 = local_98;
          if (uVar3 < local_98) {
            uVar2 = uVar3;
          }
          *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar2;
          *(undefined4 *)(param_2 + 0x30) = (undefined4)local_b8;
          SpReleaseRemoveLock(*plVar8,uVar10);
          return *(undefined4 *)(param_2 + 0x30);
        }
        SpReleaseRemoveLock(*plVar8,uVar10);
        uVar6 = 0xc000009a;
      }
      *(undefined4 *)(param_2 + 0x30) = uVar6;
      return uVar6;
    }
    uVar6 = 0xc0000023;
  }
  else {
    uVar6 = 0xc0000059;
  }
  *(undefined4 *)(param_2 + 0x30) = uVar6;
  return uVar6;
}



===== SpSendPassThrough @ 140023f14 =====

ulonglong SpSendPassThrough(longlong *param_1,longlong param_2,undefined8 param_3)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  char cVar5;
  bool bVar6;
  char cVar7;
  uint uVar8;
  short *psVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  char cVar12;
  ulonglong uVar13;
  byte bVar14;
  undefined1 uVar15;
  bool bVar16;
  longlong local_res10;
  undefined8 in_stack_ffffffffffffffa8;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  local_res10 = 0;
  cVar12 = '\0';
  lVar3 = *(longlong *)(param_2 + 0xb8);
  uVar15 = 0;
  bVar14 = 0;
  cVar5 = (char)param_3;
  if ((*(int *)(lVar3 + 0x18) - 0x4d044U & 0xfffffffb) == 0) {
    uVar10 = PortPassThroughExBasicValidation(param_2);
    bVar6 = true;
    bVar16 = (int)uVar10 == 0;
    if (-1 < (int)uVar10) goto LAB_140023f95;
  }
  else {
    bVar6 = false;
    cVar7 = IoIs32bitProcess();
    if (*(uint *)(lVar3 + 0x10) < (-(uint)(cVar7 != '\0') & 0xfffffff4) + 0x38) {
      return 0xc0000023;
    }
LAB_140023f95:
    lVar4 = *(longlong *)(param_2 + 0x18);
    if (!bVar6) {
      cVar12 = *(char *)(lVar4 + 3);
      uVar15 = *(undefined1 *)(lVar4 + 4);
      bVar14 = *(byte *)(lVar4 + 5);
      goto LAB_140023fd7;
    }
    psVar9 = (short *)((ulonglong)*(uint *)(lVar4 + 0x18) + lVar4);
    if (*psVar9 != 1) {
      return 0xc000000d;
    }
    if (3 < *(uint *)(psVar9 + 2)) {
      cVar12 = (char)psVar9[4];
      uVar15 = *(undefined1 *)((longlong)psVar9 + 9);
      bVar14 = *(byte *)(psVar9 + 5);
      goto LAB_140023fd7;
    }
    uVar10 = 0xc000000d;
    bVar16 = false;
  }
  if (!bVar16) {
    return uVar10;
  }
LAB_140023fd7:
  uVar10 = SpGetPdo(*param_1,cVar12,(uint)CONCAT71((int7)((ulonglong)param_3 >> 8),uVar15),bVar14,
                    param_2,&local_res10);
  lVar4 = local_res10;
  if ((int)uVar10 != 0) {
    return uVar10;
  }
  if ((*(char *)(lVar3 + 1) == (char)uVar10) &&
     (uVar11 = SpIsPdoClaimed(local_res10), (char)uVar11 != '\0')) {
    uVar13 = 0xc0000010;
  }
  else {
    uVar8 = SpGetPassThroughSrbFlags(lVar4);
    uVar1 = *(uint *)(param_1 + 0x7d);
    uVar2 = *(uint *)((longlong)param_1 + 0x3ec);
    local_38 = 0;
    local_48 = 0;
    uStack_40 = 0;
    KeInitializeEvent(&local_48,0,0);
    uVar10 = PortPassThroughSendAsync
                       (lVar4,param_2,cVar5,uVar8,uVar2,uVar1,in_stack_ffffffffffffffa8,&local_48);
    uVar13 = uVar10 & 0xffffffff;
    if ((int)uVar10 == 0x103) {
      KeWaitForSingleObject(&local_48,0,0,0,0);
      uVar13 = (ulonglong)*(uint *)(param_2 + 0x30);
    }
  }
  SpReleaseRemoveLock(lVar4,(char)param_2);
  return uVar13;
}



===== SpSendReset @ 1400240f0 =====

undefined4 SpSendReset(longlong param_1,longlong param_2,undefined4 param_3,char *param_4)

{
  longlong lVar1;
  undefined4 uVar2;
  longlong *plVar3;
  longlong *_Dst;
  longlong lVar4;
  byte bVar5;
  undefined2 uVar6;
  char cVar7;
  undefined1 uVar8;
  
  lVar4 = 0;
  _Dst = (longlong *)0x0;
  uVar8 = 0;
  uVar2 = 0xc000000d;
  plVar3 = (longlong *)0x0;
  if (*(int *)(*(longlong *)(param_2 + 0xb8) + 0x18) == 0x2d5014) {
    if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 8) {
      bVar5 = **(byte **)(param_2 + 0x18);
    }
    else {
      bVar5 = (*(byte **)(param_2 + 0x18))[5];
    }
  }
  else {
    bVar5 = **(byte **)(param_2 + 0x18);
  }
  if (bVar5 < *(byte *)(*(longlong *)(param_1 + 0x40) + 0x178)) {
    plVar3 = SpFindSafeLogicalUnit(param_1,bVar5,(char)param_2);
    if (plVar3 == (longlong *)0x0) {
      uVar2 = 0xc00000c0;
    }
    else {
      _Dst = (longlong *)
             SpAllocatePoolEx(0,0x70,0x43506353,*(undefined8 *)(param_1 + 8),0x696e7472,0x204f);
      if (_Dst == (longlong *)0x0) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          uVar6 = 0x48;
LAB_1400241f8:
          WPP_SF_(WPP_GLOBAL_Control[3],uVar6,&WPP_27422dadea6036b830ce33fdfb0b0cde_Traceguids);
        }
      }
      else {
        memset(_Dst,0,0x70);
        *_Dst = param_2;
        _Dst[1] = *plVar3;
        _Dst[2] = param_1;
        lVar4 = IoBuildAsynchronousFsdRequest(9,*plVar3,0,0,0,0,uVar8);
        if (lVar4 != 0) {
          lVar1 = *(longlong *)(lVar4 + 0xb8);
          *(undefined2 *)(lVar1 + -0x48) = 0x10f;
          *(longlong **)(lVar1 + -0x40) = _Dst + 3;
          *(undefined2 *)((longlong)_Dst + 0x1a) = 0x12;
          _Dst[9] = lVar4;
          *(undefined4 *)((longlong)_Dst + 0x2c) = param_3;
          lVar1 = *(longlong *)(lVar4 + 0xb8);
          *(code **)(lVar1 + -0x10) = SpSendResetCompletion;
          *(longlong **)(lVar1 + -8) = _Dst;
          *(undefined1 *)(lVar1 + -0x45) = 0;
          *(undefined1 *)(lVar1 + -0x45) = 0x40;
          *(undefined1 *)(lVar1 + -0x45) = 0xc0;
          *(undefined1 *)(lVar1 + -0x45) = 0xe0;
          cVar7 = '\0';
          uVar2 = IofCallDriver(*plVar3,lVar4);
          goto LAB_1400242f1;
        }
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          uVar6 = 0x49;
          goto LAB_1400241f8;
        }
      }
      uVar2 = 0xc000009a;
    }
  }
  cVar7 = '\x01';
LAB_1400242f1:
  if (cVar7 != '\0') {
    if (_Dst != (longlong *)0x0) {
      ExFreePoolWithTag(_Dst,0);
    }
    if (lVar4 != 0) {
      IoFreeIrp(lVar4);
    }
    *(undefined4 *)(param_2 + 0x30) = uVar2;
    if (plVar3 != (longlong *)0x0) {
      SpReleaseRemoveLock(*plVar3,(char)param_2);
    }
  }
  *param_4 = cVar7;
  return uVar2;
}



===== SpBuildAdapterDeviceMap @ 140024360 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
SpBuildAdapterDeviceMap(longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *plVar1;
  short sVar2;
  code *pcVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  void *_Dst;
  short *psVar7;
  undefined8 *puVar8;
  uint uVar9;
  undefined1 auStackY_b8 [32];
  undefined4 local_84;
  undefined8 local_80;
  undefined8 uStack_78;
  short local_68 [32];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_80 = 0;
  uStack_78 = 0;
  local_84 = 0;
  lVar5 = IoGetDriverObjectExtension(*(undefined8 *)(*param_1 + 8),ScsiPortInitialize);
  if (ScsiDeviceMapKey == 0) {
    return 0xc0000001;
  }
  plVar1 = param_1 + 0xd5;
  uVar6 = SpCreateNumericKey(ScsiDeviceMapKey,*(undefined4 *)((longlong)param_1 + 0x15c),
                             L"Scsi Port ",param_4,plVar1,&local_84);
  if ((int)uVar6 < 0) {
    return uVar6;
  }
  if ((param_1[0xd8] == 0x11d0af9f09343630) && (param_1[0xd9] == 0x301b1ef80000e992)) {
    RtlInitUnicodeString(&local_80,L"PCCARD");
    ZwSetValueKey(*plVar1,&local_80,0,4);
  }
  if ((int)param_1[0x58] != 0) {
    RtlInitUnicodeString(&local_80,L"Interrupt");
    ZwSetValueKey(*plVar1,&local_80,0,4);
  }
  if (*(int *)((longlong)param_1 + 0x2c4) != 0) {
    RtlInitUnicodeString(&local_80,L"IOAddress");
    ZwSetValueKey(*plVar1,&local_80,0,4);
  }
  if (*(char *)((longlong)param_1 + 0x491) != '\0') {
    RtlInitUnicodeString(&local_80,L"Dma64BitAddresses");
    ZwSetValueKey(*plVar1,&local_80,0,4);
  }
  RtlInitUnicodeString(&local_80,L"Driver");
  psVar7 = (short *)((longlong)*(short **)(lVar5 + 0x10) + ((ulonglong)*(ushort *)(lVar5 + 8) - 2));
  if (*psVar7 != 0x5c) {
    do {
      if (psVar7 <= *(short **)(lVar5 + 0x10)) break;
      psVar7 = psVar7 + -1;
    } while (*psVar7 != 0x5c);
    if (*psVar7 != 0x5c) goto LAB_140024655;
  }
  psVar7 = psVar7 + 1;
  uVar9 = 0;
  do {
    sVar2 = *psVar7;
    psVar7 = psVar7 + 1;
    local_68[uVar9] = sVar2;
    if ((short *)(((ulonglong)*(ushort *)(lVar5 + 8) & 0xfffffffffffffffe) +
                 *(longlong *)(lVar5 + 0x10)) <= psVar7) break;
    uVar9 = uVar9 + 1;
  } while (uVar9 < 0x1e);
  if (0x3f < (ulonglong)(uVar9 + 1) * 2) {
    __report_rangecheckfailure();
    pcVar3 = (code *)swi(3);
    uVar6 = (*pcVar3)();
    return uVar6;
  }
  local_68[uVar9 + 1] = 0;
  ZwSetValueKey(param_1[0xd5],&local_80,0,1);
LAB_140024655:
  uVar6 = *(undefined8 *)(*param_1 + 8);
  _Dst = (void *)SpAllocatePoolEx(1,(ulonglong)*(byte *)(param_1 + 0x2f) << 4,0x56506353,uVar6,
                                  0x6d617020,0x243);
  param_1[0xd6] = (longlong)_Dst;
  if (_Dst == (void *)0x0) {
    uVar6 = 0xc000009a;
  }
  else {
    memset(_Dst,0,(ulonglong)*(byte *)(param_1 + 0x2f) << 4);
    uVar9 = 0;
    if ((char)param_1[0x2f] != '\0') {
      do {
        puVar8 = (undefined8 *)((ulonglong)uVar9 * 0x10 + param_1[0xd6]);
        iVar4 = SpCreateNumericKey(param_1[0xd5],uVar9,L"Scsi Bus ",uVar6,puVar8,&local_84);
        if (-1 < iVar4) {
          SpCreateNumericKey(*puVar8,(uint)*(byte *)(param_1[0x3f] + 0x49 + (ulonglong)uVar9),
                             L"Initiator Id ",uVar6,puVar8 + 1,&local_84);
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < *(byte *)(param_1 + 0x2f));
    }
    uVar6 = 0;
  }
  return uVar6;
}



===== SpBuildDeviceMapEntry @ 140024748 =====

void SpBuildDeviceMapEntry(longlong *param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  if ((*(byte *)(param_1 + 1) & 1) == 0) {
    SpBuildAdapterDeviceMap(param_1,param_2,param_3,param_4);
  }
  else {
    SpBuildLogicalUnitDeviceMapEntry((longlong)param_1,param_2,param_3,param_4);
  }
  return;
}



===== SpBuildLogicalUnitDeviceMapEntry @ 14002476c =====

undefined8
SpBuildLogicalUnitDeviceMapEntry
          (longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined *puVar3;
  byte bVar4;
  int iVar5;
  undefined8 uVar6;
  undefined **ppuVar7;
  longlong lVar8;
  undefined4 local_res8 [2];
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined4 local_28;
  undefined4 local_24;
  longlong local_20;
  
  lVar8 = *(longlong *)(param_1 + 0x168);
  local_24 = 0;
  local_res8[0] = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    param_4 = param_1;
    WPP_SF_q(WPP_GLOBAL_Control[3],10,&WPP_c5fd4388e0e3313e6c841f3bc93a1cc4_Traceguids,param_1);
  }
  lVar8 = *(longlong *)(lVar8 + 0x6b0);
  if (lVar8 == 0) {
    return 0xc0000001;
  }
  plVar1 = (longlong *)(param_1 + 0x268);
  plVar2 = (longlong *)(param_1 + 0x270);
  if ((*plVar1 == 0) || (*plVar2 == 0)) {
    uVar6 = SpCreateNumericKey(*(undefined8 *)(lVar8 + (ulonglong)*(byte *)(param_1 + 0x154) * 0x10)
                               ,(uint)*(byte *)(param_1 + 0x155),L"Target Id ",param_4,plVar1,
                               local_res8);
    if ((int)uVar6 < 0) {
      return uVar6;
    }
    puVar9 = local_res8;
    uVar6 = SpCreateNumericKey(*plVar1,(uint)*(byte *)(param_1 + 0x156),L"Logical Unit Id ",param_4,
                               plVar2,puVar9);
    uVar10 = (undefined4)((ulonglong)puVar9 >> 0x20);
    if ((int)uVar6 < 0) {
      return uVar6;
    }
    RtlInitUnicodeString(&local_48,L"Identifier");
    local_20 = param_1 + 0x202;
    local_28 = 0x1c001c;
    iVar5 = RtlAnsiStringToUnicodeString(&local_38,&local_28,1);
    if (-1 < iVar5) {
      uVar6 = CONCAT44(uVar10,(ushort)local_38 + 2);
      ZwSetValueKey(*plVar2,&local_48,0,1,uStack_30,uVar6);
      uVar10 = (undefined4)((ulonglong)uVar6 >> 0x20);
      RtlFreeUnicodeString(&local_38);
    }
    bVar4 = *(byte *)(param_1 + 0x1fa) & 0x1f;
    if (bVar4 < 0x12) {
      ppuVar7 = &PTR_u_DiskPeripheral_140013110 + (ulonglong)bVar4 * 4;
    }
    else {
      ppuVar7 = &PTR_u_OtherPeripheral_140013330;
    }
    puVar3 = *ppuVar7;
    RtlInitUnicodeString(&local_48,L"Type");
    lVar8 = -1;
    do {
      lVar8 = lVar8 + 1;
    } while (*(short *)(puVar3 + lVar8 * 2) != 0);
    uVar6 = CONCAT44(uVar10,(int)lVar8 * 2 + 2);
    ZwSetValueKey(*plVar2,&local_48,0,1,puVar3,uVar6);
    uVar10 = (undefined4)((ulonglong)uVar6 >> 0x20);
    RtlInitUnicodeString(&local_48,L"InquiryData");
    uVar6 = CONCAT44(uVar10,0x24);
    ZwSetValueKey(*plVar2,&local_48,0,3,(byte *)(param_1 + 0x1fa),uVar6);
    uVar10 = (undefined4)((ulonglong)uVar6 >> 0x20);
    if (*(short *)(param_1 + 0xfb8) != 0) {
      RtlInitUnicodeString(&local_48,L"SerialNumber");
      iVar5 = RtlAnsiStringToUnicodeString(&local_38,(short *)(param_1 + 0xfb8),1);
      if (-1 < iVar5) {
        uVar6 = CONCAT44(uVar10,(ushort)local_38 + 2);
        ZwSetValueKey(*plVar2,&local_48,0,1,uStack_30,uVar6);
        uVar10 = (undefined4)((ulonglong)uVar6 >> 0x20);
        RtlFreeUnicodeString(&local_38);
      }
    }
    if (*(longlong *)(param_1 + 0xfc8) != 0) {
      RtlInitUnicodeString(&local_48,L"DeviceIdentifierPage");
      ZwSetValueKey(*plVar2,&local_48,0,3,*(undefined8 *)(param_1 + 0xfc8),
                    CONCAT44(uVar10,*(undefined4 *)(param_1 + 0xfd0)));
    }
  }
  return 0;
}



===== SpCreateNumericKey @ 140024aa8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SpCreateNumericKey(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
                       undefined8 param_5,undefined8 param_6)

{
  int iVar1;
  undefined1 auStack_178 [32];
  undefined8 local_158;
  undefined4 local_150;
  undefined8 local_148;
  undefined8 local_138;
  undefined1 *puStack_130;
  undefined8 local_128;
  undefined1 *local_120;
  undefined4 local_118;
  undefined4 local_114;
  undefined8 local_110;
  undefined8 *local_108;
  undefined4 local_100;
  undefined4 local_fc;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined1 local_e8 [32];
  undefined1 local_c8 [128];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_178;
  local_128 = 0x400000;
  local_114 = 0;
  local_fc = 0;
  local_138 = 0;
  puStack_130 = (undefined1 *)0x0;
  memset(local_c8,0,0x80);
  local_120 = local_c8;
  RtlInitUnicodeString(&local_138,param_3);
  RtlCopyUnicodeString(&local_128,&local_138);
  puStack_130 = local_e8;
  local_138 = CONCAT44(local_138._4_4_,0x100000);
  iVar1 = RtlIntegerToUnicodeString(param_2,10,&local_138);
  if (-1 < iVar1) {
    RtlAppendUnicodeStringToString(&local_128,&local_138);
    local_108 = &local_128;
    local_148 = param_6;
    local_150 = 1;
    local_118 = 0x30;
    local_100 = 0x40;
    local_f8 = 0;
    uStack_f0 = 0;
    local_158 = 0;
    local_110 = param_1;
    ZwCreateKey(param_5,0x2001f,&local_118,0);
  }
  return;
}



===== SpDeleteAdapterDeviceMap @ 140024c14 =====

void SpDeleteAdapterDeviceMap(longlong param_1)

{
  uint uVar1;
  longlong *plVar2;
  
  if (*(longlong *)(param_1 + 0x6b0) != 0) {
    uVar1 = 0;
    if (*(char *)(param_1 + 0x178) != '\0') {
      do {
        plVar2 = (longlong *)((ulonglong)uVar1 * 0x10 + *(longlong *)(param_1 + 0x6b0));
        if (plVar2[1] != 0) {
          ZwDeleteKey();
          ZwClose(plVar2[1]);
        }
        if (*plVar2 != 0) {
          ZwDeleteKey();
          ZwClose(*plVar2);
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < *(byte *)(param_1 + 0x178));
    }
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x6b0),0);
    *(undefined8 *)(param_1 + 0x6b0) = 0;
  }
  if (*(longlong *)(param_1 + 0x6a8) != 0) {
    ZwDeleteKey();
    ZwClose(*(undefined8 *)(param_1 + 0x6a8));
    *(undefined8 *)(param_1 + 0x6a8) = 0;
  }
  return;
}



===== SpDeleteLogicalUnitDeviceMapEntry @ 140024d08 =====

void SpDeleteLogicalUnitDeviceMapEntry(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x270) != 0) {
    ZwDeleteKey();
    ZwClose(*(undefined8 *)(param_1 + 0x270));
    *(undefined8 *)(param_1 + 0x270) = 0;
  }
  if (*(longlong *)(param_1 + 0x268) != 0) {
    ZwDeleteKey();
    ZwClose(*(undefined8 *)(param_1 + 0x268));
    *(undefined8 *)(param_1 + 0x268) = 0;
  }
  return;
}



===== SpInitDeviceMap @ 140024d84 =====

void SpInitDeviceMap(void)

{
  int iVar1;
  undefined4 local_res8 [2];
  undefined8 local_res10;
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
  
  local_34 = 0;
  local_1c = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_res10 = 0;
  local_res8[0] = 0;
  RtlInitUnicodeString(&local_48,L"\\Registry\\Machine\\Hardware\\DeviceMap\\Scsi");
  local_28 = &local_48;
  local_38 = 0x30;
  local_30 = 0;
  local_20 = 0x40;
  local_18 = 0;
  uStack_10 = 0;
  iVar1 = ZwCreateKey(&local_res10,0x2001f,&local_38,0,0,1,local_res8);
  ScsiDeviceMapKey = 0;
  if (-1 < iVar1) {
    ScsiDeviceMapKey = local_res10;
  }
  return;
}



===== ScsiPortInitPdoWmi @ 140024e3c =====

void ScsiPortInitPdoWmi(longlong *param_1)

{
  undefined8 *puVar1;
  char cVar2;
  byte bVar3;
  
  puVar1 = (undefined8 *)param_1[0x2d];
  bVar3 = *(byte *)(puVar1 + 1);
  if (((bVar3 & 0x10) == 0) && ((bVar3 & 8) != 0)) {
    IoWMIRegistrationControl(*puVar1,(bVar3 & 4 | 2) >> 1);
    *(byte *)(puVar1 + 1) = *(byte *)(puVar1 + 1) | 0x14;
  }
  if ((*(byte *)(param_1 + 1) & 4) == 0) {
    SpWmiInitializeSpRegInfo(*param_1);
    bVar3 = *(byte *)(param_1 + 1);
    if (((bVar3 & 8) != 0) || (param_1[8] != 0)) {
      cVar2 = SpIsInitiatorLU((longlong)param_1);
      if (cVar2 == '\0') {
        IoWMIRegistrationControl(*param_1,1);
        *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) | 4;
        bVar3 = *(byte *)(param_1 + 1);
      }
    }
    if ((bVar3 & 8) != 0) {
      SpWmiInitializeFreeRequestList(*param_1);
    }
  }
  return;
}



===== ScsiPortPdoCreateClose @ 140024ee0 =====

undefined4 ScsiPortPdoCreateClose(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  lVar1 = *(longlong *)(param_1 + 0x40);
  LOCK();
  *(int *)(lVar1 + 0x4c) = *(int *)(lVar1 + 0x4c) + 1;
  UNLOCK();
  if (**(char **)(param_2 + 0xb8) == '\0') {
    if (*(int *)(lVar1 + 0xc) == 0) {
      uVar2 = 0;
      if (*(char *)(lVar1 + 0x14e) == '\x01') {
        uVar2 = 0xc00000a3;
      }
    }
    else {
      uVar2 = 0xc00000c0;
    }
  }
  *(undefined4 *)(param_2 + 0x30) = uVar2;
  SpReleaseRemoveLock(param_1,(char)param_2);
  SpCompleteRequest(param_1,param_2,(undefined *)0x0,0);
  return uVar2;
}



===== ScsiPortPdoPnp @ 140024f50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int ScsiPortPdoPnp(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  byte *pbVar1;
  uint uVar2;
  longlong *plVar3;
  ushort *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  byte bVar7;
  int iVar8;
  undefined8 *puVar9;
  longlong lVar10;
  char *pcVar11;
  undefined8 uVar12;
  undefined **ppuVar13;
  ulonglong uVar14;
  short *psVar15;
  short *psVar16;
  undefined1 uVar17;
  short sVar18;
  ushort *puVar19;
  undefined4 uVar20;
  longlong lVar21;
  bool bVar22;
  undefined1 auStackY_f8 [32];
  ulonglong local_c8;
  short *psStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  int *local_a8;
  char *pcStack_a0;
  undefined8 local_98;
  int local_88 [2];
  undefined8 uStack_80;
  undefined8 local_78;
  undefined4 local_70;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_f8;
  plVar3 = *(longlong **)(param_1 + 0x40);
  lVar10 = *(longlong *)(param_2 + 0xb8);
  bVar22 = true;
  LOCK();
  *(int *)((longlong)plVar3 + 0x4c) = *(int *)((longlong)plVar3 + 0x4c) + 1;
  UNLOCK();
  bVar7 = *(byte *)(lVar10 + 1);
  uVar20 = 0;
  uVar17 = (undefined1)param_2;
  if (bVar7 < 9) {
    if (bVar7 == 8) {
      local_a8 = (int *)IoGetDriverObjectExtension(*(undefined8 *)(*plVar3 + 8),ScsiPortInitialize);
      lVar21 = 0x10;
      if (((*(undefined **)(lVar10 + 8) == &GUID_STORAGE_QUERY_PDO_INFO) ||
          (lVar10 = RtlCompareMemory(), lVar10 == 0x10)) && (local_a8 != (int *)0x0)) {
        iVar8 = local_a8[9];
        bVar7 = *(byte *)((longlong)plVar3 + 0x1fa);
        puVar4 = *(ushort **)(*(longlong *)(param_2 + 0xb8) + 0x18);
        if ((puVar4 == (ushort *)0x0) || (*(ushort *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0x38))
        {
          uVar20 = 0xc000000d;
        }
        else if (*puVar4 < 0x38) {
          *puVar4 = 0x38;
          uVar20 = 0x80000005;
        }
        else {
          *(longlong *)(puVar4 + 4) = plVar3[2];
          *(byte *)(puVar4 + 8) = bVar7 & 0x1f;
          puVar19 = puVar4 + 0xc;
          *(int *)(puVar4 + 10) = iVar8;
          puVar19[0] = 0;
          puVar19[1] = 0;
          puVar19[2] = 0;
          puVar19[3] = 0;
          *(undefined1 *)(puVar4 + 0x10) = 0;
          *(undefined8 *)puVar19 = *(undefined8 *)((longlong)plVar3 + 0x202);
          *(undefined8 *)((longlong)puVar4 + 0x21) = 0;
          *(undefined8 *)((longlong)puVar4 + 0x29) = 0;
          *(undefined1 *)((longlong)puVar4 + 0x31) = 0;
          lVar10 = 8;
          uVar12 = *(undefined8 *)((longlong)plVar3 + 0x212);
          *(undefined8 *)((longlong)puVar4 + 0x21) = *(undefined8 *)((longlong)plVar3 + 0x20a);
          *(undefined8 *)((longlong)puVar4 + 0x29) = uVar12;
          do {
            if ((char)*puVar19 == '\0') {
              *(char *)puVar19 = ' ';
            }
            puVar19 = (ushort *)((longlong)puVar19 + 1);
            lVar10 = lVar10 + -1;
          } while (lVar10 != 0);
          *(undefined1 *)(puVar4 + 0x10) = 0;
          pcVar11 = (char *)((longlong)puVar4 + 0x21);
          do {
            if (*pcVar11 == '\0') {
              *pcVar11 = ' ';
            }
            pcVar11 = pcVar11 + 1;
            lVar21 = lVar21 + -1;
          } while (lVar21 != 0);
          *(undefined1 *)((longlong)puVar4 + 0x31) = 0;
        }
        goto LAB_1400256e2;
      }
    }
    else {
      if (bVar7 == 0) {
        if (*(char *)((longlong)plVar3 + 9) != '\0') {
          if ((*(byte *)(plVar3 + 1) & 2) == 0) {
            uVar12 = ScsiPortInitLogicalUnit(plVar3);
            iVar8 = (int)uVar12;
            if (iVar8 < 0) goto LAB_140025159;
          }
          *(byte *)(plVar3 + 1) = *(byte *)(plVar3 + 1) | 2;
          iVar8 = ScsiPortStartLogicalUnit(plVar3);
          if (-1 < iVar8) {
            *(undefined2 *)((longlong)plVar3 + 9) = 0xff00;
          }
          goto LAB_140025159;
        }
      }
      else {
        if (bVar7 == 1) {
LAB_1400250f2:
          if ((*(int *)((longlong)plVar3 + 0x104) == 0) &&
             (*(char *)((longlong)plVar3 + 0x149) != '\x01')) {
            *(undefined4 *)(param_2 + 0x30) = 0;
            *(undefined1 *)((longlong)plVar3 + 10) = *(undefined1 *)((longlong)plVar3 + 9);
            *(undefined1 *)((longlong)plVar3 + 9) = *(undefined1 *)(lVar10 + 1);
          }
          else {
            *(undefined4 *)(param_2 + 0x30) = 0x80000011;
          }
          goto LAB_1400256e5;
        }
        if (bVar7 == 2) {
LAB_1400252b5:
          if (*(int *)((longlong)plVar3 + 0xc) == 0) {
            *(undefined4 *)((longlong)plVar3 + 0xc) = 1;
          }
          lVar21 = param_2;
          SpReleaseRemoveLock(param_1,uVar17);
          uVar12 = SpRemoveLogicalUnit(plVar3,CONCAT71((int7)((ulonglong)lVar21 >> 8),
                                                       *(undefined1 *)(lVar10 + 1)));
          if ((char)uVar12 == '\0') {
            *(undefined1 *)((longlong)plVar3 + 9) = 0xff;
            *(undefined1 *)((longlong)plVar3 + 10) = *(undefined1 *)(lVar10 + 1);
          }
          else {
            *(undefined1 *)((longlong)plVar3 + 10) = *(undefined1 *)((longlong)plVar3 + 9);
            *(undefined1 *)((longlong)plVar3 + 9) = *(undefined1 *)(lVar10 + 1);
          }
          *(undefined4 *)(param_2 + 0x30) = 0;
          IofCompleteRequest(param_2,0);
          return 0;
        }
        if (bVar7 == 3) {
          bVar22 = *(char *)((longlong)plVar3 + 9) == '\x01';
        }
        else {
          if (bVar7 == 4) {
            local_88[0] = 0;
            local_88[1] = 0;
            uStack_80 = 0;
            local_78 = 0;
            local_70 = 0;
            if (*(char *)((longlong)plVar3 + 9) == '\x04') {
              iVar8 = 0;
            }
            else {
              KeInitializeEvent(&uStack_80,1,0);
              SpEnableDisableLogicalUnit(plVar3,'\0',SpDeviceStoppedCompletion,local_88);
              KeWaitForSingleObject(&uStack_80,0);
              iVar8 = local_88[0];
            }
            *(int *)(param_2 + 0x30) = iVar8;
            *(undefined8 *)(param_2 + 0x38) = 0;
            if (-1 < iVar8) {
              *(undefined2 *)((longlong)plVar3 + 9) = 0xff04;
            }
            goto LAB_140025689;
          }
          if (bVar7 == 5) goto LAB_1400250f2;
          if (bVar7 != 6) {
            if ((bVar7 == 7) && (*(int *)(lVar10 + 8) == 4)) {
              puVar9 = (undefined8 *)
                       SpAllocatePoolEx(1,0x10,0x75506353,*(undefined8 *)(param_1 + 8),0x70646f20,
                                        0x35e);
              if (puVar9 == (undefined8 *)0x0) goto LAB_140025029;
              *puVar9 = 1;
              puVar9[1] = param_1;
              ObfReferenceObject(param_1);
              *(undefined8 **)(param_2 + 0x38) = puVar9;
              goto LAB_1400256e2;
            }
            goto LAB_1400256e5;
          }
          bVar22 = *(char *)((longlong)plVar3 + 9) == '\x05';
        }
        if (bVar22) {
          *(undefined1 *)((longlong)plVar3 + 9) = *(undefined1 *)((longlong)plVar3 + 10);
          *(undefined1 *)((longlong)plVar3 + 10) = 0xff;
        }
      }
      *(undefined4 *)(param_2 + 0x30) = 0;
    }
  }
  else {
    if (bVar7 != 9) {
      if ((bVar7 == 10) || (bVar7 == 0xb)) {
        *(undefined4 *)(param_2 + 0x30) = 0;
        *(undefined8 *)(param_2 + 0x38) = 0;
LAB_140025686:
        iVar8 = 0;
      }
      else {
        if (bVar7 == 0xc) {
          uVar12 = SpQueryDeviceText(param_1,*(int *)(lVar10 + 8),param_3,
                                     (undefined8 *)(param_2 + 0x38));
          iVar8 = (int)uVar12;
LAB_140025159:
          *(int *)(param_2 + 0x30) = iVar8;
          goto LAB_1400256e5;
        }
        if (bVar7 != 0x13) {
          if (bVar7 != 0x14) {
            if (bVar7 == 0x16) {
              lVar10 = param_2;
              if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                 (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                lVar10 = 0xe;
                WPP_SF_qq(WPP_GLOBAL_Control[3],0xe,&WPP_61736e3ed466352ac1be56969524dc0e_Traceguids
                          ,param_2,(char)param_1);
              }
              lVar10 = SpAllocateIrpEx(CONCAT71((int7)((ulonglong)plVar3[2] >> 8),
                                                *(undefined1 *)(plVar3[2] + 0x4c)),lVar10,
                                       *(undefined8 *)(param_1 + 8),0x70646f20,0x381);
              if (lVar10 != 0) {
                pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
                *pbVar1 = *pbVar1 | 1;
                lVar21 = *(longlong *)(lVar10 + 0xb8);
                *(longlong *)(lVar10 + 0x18) = param_2;
                *(undefined4 *)(lVar10 + 0x30) = 0xc00000bb;
                puVar9 = *(undefined8 **)(param_2 + 0xb8);
                uVar12 = puVar9[1];
                *(undefined8 *)(lVar21 + -0x48) = *puVar9;
                *(undefined8 *)(lVar21 + -0x40) = uVar12;
                uVar12 = puVar9[3];
                *(undefined8 *)(lVar21 + -0x38) = puVar9[2];
                *(undefined8 *)(lVar21 + -0x30) = uVar12;
                uVar12 = puVar9[5];
                *(undefined8 *)(lVar21 + -0x28) = puVar9[4];
                *(undefined8 *)(lVar21 + -0x20) = uVar12;
                uVar20 = *(undefined4 *)((longlong)puVar9 + 0x34);
                uVar5 = *(undefined4 *)(puVar9 + 7);
                uVar6 = *(undefined4 *)((longlong)puVar9 + 0x3c);
                *(undefined4 *)(lVar21 + -0x18) = *(undefined4 *)(puVar9 + 6);
                *(undefined4 *)(lVar21 + -0x14) = uVar20;
                *(undefined4 *)(lVar21 + -0x10) = uVar5;
                *(undefined4 *)(lVar21 + -0xc) = uVar6;
                *(undefined8 *)(lVar21 + -8) = puVar9[8];
                lVar10 = *(longlong *)(lVar10 + 0xb8);
                lVar21 = plVar3[2];
                *(code **)(lVar10 + -0x10) = SpPagingPathNotificationCompletion;
                *(longlong *)(lVar10 + -8) = lVar21;
                *(undefined1 *)(lVar10 + -0x45) = 0xe0;
                IofCallDriver(plVar3[2]);
                return 0x103;
              }
LAB_140025029:
              *(undefined4 *)(param_2 + 0x30) = 0xc000009a;
            }
            else if (bVar7 == 0x17) goto LAB_1400252b5;
            goto LAB_1400256e5;
          }
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_q(WPP_GLOBAL_Control[3],0xb,&WPP_61736e3ed466352ac1be56969524dc0e_Traceguids,
                     param_1);
          }
          if (((*(int *)((longlong)plVar3 + 0x104) != 0) &&
              (*(uint *)(param_2 + 0x38) = *(uint *)(param_2 + 0x38) | 0x20,
              (undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
             (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0 &&
              (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
            WPP_SF_q(WPP_GLOBAL_Control[3],0xc,&WPP_61736e3ed466352ac1be56969524dc0e_Traceguids,
                     param_1);
          }
          *(undefined4 *)(param_2 + 0x30) = 0;
          goto LAB_140025686;
        }
        local_b8 = 0;
        uStack_b0 = 0;
        local_c8 = 0;
        psStack_c0 = (short *)0x0;
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_(WPP_GLOBAL_Control[3],0xd,&WPP_61736e3ed466352ac1be56969524dc0e_Traceguids);
        }
        RtlInitUnicodeString(&local_c8,0);
        RtlInitAnsiString(&local_b8,0);
        iVar8 = *(int *)(lVar10 + 8);
        if (iVar8 == 0) {
          iVar8 = ScsiPortGetDeviceId(param_1,&local_c8);
LAB_14002560c:
          bVar22 = false;
        }
        else if (iVar8 == 1) {
          uVar14 = ScsiPortGetHardwareIds
                             (*(undefined8 *)(param_1 + 8),(byte *)((longlong)plVar3 + 0x1fa),
                              &local_c8,param_4);
          iVar8 = (int)uVar14;
        }
        else {
          if (iVar8 != 2) {
            if (iVar8 == 3) {
              local_a8 = (int *)0x0;
              pcStack_a0 = (char *)0x0;
              RtlStringCbPrintfA((char *)local_88,0x40,"%02x%02x%02x",
                                 (ulonglong)*(byte *)(*(longlong *)(param_1 + 0x40) + 0x154));
              RtlInitAnsiString(&local_a8,local_88);
              iVar8 = RtlAnsiStringToUnicodeString(&local_c8,&local_a8,1);
            }
            else {
              iVar8 = *(int *)(param_2 + 0x30);
              *(undefined8 *)(param_2 + 0x38) = 0;
            }
            goto LAB_14002560c;
          }
          uVar12 = *(undefined8 *)(param_1 + 8);
          local_a8 = local_88;
          pcStack_a0 = "SCSI\\RAW";
          bVar7 = *(byte *)((longlong)plVar3 + 0x1fa) & 0x1f;
          local_98 = 0;
          if (bVar7 < 0x12) {
            ppuVar13 = &DeviceTypeInfo + (ulonglong)bVar7 * 4;
          }
          else {
            ppuVar13 = &PTR_s_Other_140013320;
          }
          RtlStringCbPrintfA((char *)local_88,0x1b,"SCSI\\%s",*ppuVar13);
          uVar12 = ScsiPortStringArrayToMultiString(uVar12,&local_c8,(longlong *)&local_a8);
          iVar8 = (int)uVar12;
        }
        *(int *)(param_2 + 0x30) = iVar8;
        if (iVar8 < 0) {
          *(undefined8 *)(param_2 + 0x38) = 0;
        }
        else {
          sVar18 = *psStack_c0;
          psVar16 = psStack_c0;
          while (sVar18 != 0) {
            do {
              psVar15 = psVar16;
              if ((0x5e < (ushort)(sVar18 - 0x21U)) || (sVar18 == 0x2c)) {
                *psVar15 = 0x5f;
              }
              psVar16 = psVar15 + 1;
              sVar18 = *psVar16;
            } while (sVar18 != 0);
            sVar18 = 0;
            if (bVar22) {
              psVar16 = psVar15 + 2;
              sVar18 = *psVar16;
            }
          }
          *(short **)(param_2 + 0x38) = psStack_c0;
        }
      }
LAB_140025689:
      SpReleaseRemoveLock(param_1,uVar17);
      goto LAB_1400256f4;
    }
    lVar10 = *(longlong *)(lVar10 + 8);
    uVar2 = *(uint *)(lVar10 + 4);
    *(uint *)(lVar10 + 4) = uVar2 | 0x100;
    bVar7 = *(byte *)((longlong)plVar3 + 0x1fa) & 0x1f;
    if (bVar7 < 0x12) {
      ppuVar13 = &DeviceTypeInfo + (ulonglong)bVar7 * 4;
      if (ppuVar13 != (undefined **)0x0) goto LAB_1400256cc;
    }
    else {
      ppuVar13 = &PTR_s_Other_140013320;
LAB_1400256cc:
      if (*(char *)(ppuVar13 + 3) != '\0') {
        *(uint *)(lVar10 + 4) = uVar2 | 0x180;
      }
    }
    *(uint *)(lVar10 + 8) = (uint)*(byte *)((longlong)plVar3 + 0x155);
LAB_1400256e2:
    *(undefined4 *)(param_2 + 0x30) = uVar20;
  }
LAB_1400256e5:
  SpReleaseRemoveLock(param_1,uVar17);
  iVar8 = *(int *)(param_2 + 0x30);
LAB_1400256f4:
  SpCompleteRequest(param_1,param_2,(undefined *)0x0,0);
  return iVar8;
}



===== ScsiPortStartLogicalUnit @ 140025734 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int ScsiPortStartLogicalUnit(longlong *param_1)

{
  uint *puVar1;
  int iVar2;
  int extraout_EAX;
  code *pcVar3;
  ulonglong uVar4;
  uint uVar5;
  undefined4 local_res8 [2];
  ulonglong local_res10;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined1 local_88 [8];
  undefined4 local_80;
  wchar_t *local_78;
  uint *local_70;
  undefined4 local_68;
  undefined4 *local_60;
  undefined4 local_58;
  
  local_res10 = 0;
  uVar4 = 1;
  iVar2 = IoOpenDeviceRegistryKey(*param_1,1,0x20019,&local_res10);
  if (iVar2 < 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      uVar4 = 0x16;
      WPP_SF_D(WPP_GLOBAL_Control[3],0x16,&WPP_61736e3ed466352ac1be56969524dc0e_Traceguids,iVar2);
    }
  }
  else {
    local_res8[0] = 0;
    memset(local_88,0,0x70);
    uVar4 = local_res10;
    local_78 = L"DefaultRequestFlags";
    puVar1 = (uint *)(param_1 + 3);
    local_60 = local_res8;
    local_80 = 0x20;
    local_68 = 4;
    local_58 = 4;
    local_98 = 0;
    uStack_90 = 0;
    local_70 = puVar1;
    RtlInitUnicodeString(&local_98,L"RtlQueryRegistryValuesEx");
    pcVar3 = (code *)MmGetSystemRoutineAddress(&local_98);
    if (pcVar3 == (code *)0x0) {
      pcVar3 = RtlQueryRegistryValues_exref;
    }
    iVar2 = (*pcVar3)(0xc0000000,uVar4,local_88,0,0);
    uVar5 = *puVar1 & 0xc;
    *puVar1 = uVar5;
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      uVar4 = (ulonglong)*(byte *)((longlong)param_1 + 0x155);
      WPP_SF_dddL(WPP_GLOBAL_Control[3],uVar4,(ulonglong)uVar5,
                  (uint)*(byte *)((longlong)param_1 + 0x154),*(byte *)((longlong)param_1 + 0x155),
                  *(undefined1 *)((longlong)param_1 + 0x156),(char)uVar5);
    }
    ZwClose(local_res10);
  }
  if ((int)param_1[0x2e] != 0) {
    SpLockUnlockQueue(*param_1,uVar4);
    iVar2 = extraout_EAX;
  }
  return iVar2;
}



===== SpPdoHandleIoctlScsiGetAddress @ 1400258e8 =====

undefined4 SpPdoHandleIoctlScsiGetAddress(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  puVar2 = *(undefined4 **)(param_2 + 0x18);
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 8) {
    uVar3 = 0xc0000023;
  }
  else {
    *puVar2 = 8;
    uVar3 = 0;
    *(undefined1 *)(puVar2 + 1) = *(undefined1 *)(lVar1 + 0x144);
    *(undefined1 *)((longlong)puVar2 + 5) = *(undefined1 *)(lVar1 + 0x154);
    *(undefined1 *)((longlong)puVar2 + 6) = *(undefined1 *)(lVar1 + 0x155);
    *(undefined1 *)((longlong)puVar2 + 7) = *(undefined1 *)(lVar1 + 0x156);
    *(undefined8 *)(param_2 + 0x38) = 8;
  }
  *(undefined4 *)(param_2 + 0x30) = uVar3;
  SpReleaseRemoveLock(param_1,(char)param_2);
  SpCompleteRequest(param_1,param_2,(undefined *)0x0,0);
  return uVar3;
}



===== SpPdoHandleIoctlScsiPassthrough @ 140025978 =====

ulonglong SpPdoHandleIoctlScsiPassthrough(longlong param_1,longlong param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  longlong lVar4;
  longlong lVar5;
  bool bVar6;
  char cVar7;
  undefined4 uVar8;
  uint uVar9;
  ulonglong uVar10;
  ushort *puVar11;
  
  lVar4 = *(longlong *)(param_1 + 0x40);
  lVar5 = *(longlong *)(param_2 + 0xb8);
  uVar1 = *(undefined1 *)(lVar4 + 0x156);
  uVar2 = *(undefined1 *)(lVar4 + 0x155);
  uVar3 = *(undefined1 *)(lVar4 + 0x154);
  if ((*(int *)(lVar5 + 0x18) - 0x4d044U & 0xfffffffb) == 0) {
    uVar10 = PortPassThroughExBasicValidation(param_2);
    bVar6 = true;
    if ((int)uVar10 < 0) goto LAB_1400259f3;
LAB_140025a4b:
    lVar4 = *(longlong *)(param_2 + 0x18);
    if (bVar6) {
      puVar11 = (ushort *)((ulonglong)*(uint *)(lVar4 + 0x18) + lVar4);
      if ((1 < *puVar11) || (*(uint *)(lVar4 + 0xc) < 0xc)) {
        uVar10 = 0xc000000d;
        uVar8 = 0xc000000d;
        goto LAB_1400259f5;
      }
      puVar11[0] = 1;
      puVar11[1] = 0;
      puVar11[2] = 4;
      puVar11[3] = 0;
      *(undefined1 *)(puVar11 + 4) = uVar3;
      *(undefined1 *)((longlong)puVar11 + 9) = uVar2;
      *(undefined1 *)(puVar11 + 5) = uVar1;
      *(undefined1 *)((longlong)puVar11 + 0xb) = 0;
    }
    else {
      *(undefined1 *)(lVar4 + 3) = uVar3;
      *(undefined1 *)(lVar4 + 4) = uVar2;
      *(undefined1 *)(lVar4 + 5) = uVar1;
    }
    lVar4 = *(longlong *)(param_1 + 0x40);
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    SpReleaseRemoveLock(param_1,(char)param_2);
    uVar9 = IofCallDriver(*(undefined8 *)(lVar4 + 0x10),param_2);
    uVar10 = (ulonglong)uVar9;
  }
  else {
    bVar6 = false;
    cVar7 = IoIs32bitProcess();
    if ((-(uint)(cVar7 != '\0') & 0xfffffff4) + 0x38 <= *(uint *)(lVar5 + 0x10)) goto LAB_140025a4b;
    uVar10 = 0xc0000023;
LAB_1400259f3:
    uVar8 = (undefined4)uVar10;
    uVar10 = uVar10 & 0xffffffff;
LAB_1400259f5:
    *(undefined4 *)(param_2 + 0x30) = uVar8;
    SpReleaseRemoveLock(param_1,(char)param_2);
    SpCompleteRequest(param_1,param_2,(undefined *)0x0,0);
  }
  return uVar10;
}



===== SpPdoHandleIoctlScsiPassthroughDirect @ 140025ad8 =====

void SpPdoHandleIoctlScsiPassthroughDirect(longlong param_1,longlong param_2)

{
  SpPdoHandleIoctlScsiPassthrough(param_1,param_2);
  return;
}



===== SpPdoHandleIoctlStorageBreakReservation @ 140025af0 =====

undefined4 SpPdoHandleIoctlStorageBreakReservation(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  int local_res8 [2];
  undefined4 local_res10 [2];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_res10[0] = 0;
  local_38 = 0;
  uStack_30 = 0;
  lVar2 = *(longlong *)(lVar1 + 0x10);
  local_28 = 0;
  uStack_20 = 0;
  SeCaptureSubjectContext(&local_38);
  SeLockSubjectContext(&local_38);
  local_res8[0] = -0x3fffffde;
  uVar5 = IoGetFileObjectGenericMapping();
  cVar3 = SeAccessCheck(*(undefined8 *)(lVar2 + 0x110),&local_38,1,2,0,0,uVar5,
                        *(undefined1 *)(param_2 + 0x40),local_res10,local_res8);
  SeUnlockSubjectContext(&local_38);
  SeReleaseSubjectContext(&local_38);
  if ((cVar3 == '\0') && (local_res8[0] < 0)) {
    SpReleaseRemoveLock(param_1,(char)param_2);
    uVar4 = 0xc0000010;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
    SpCompleteRequest(param_1,param_2,(undefined *)0x0,0);
  }
  else {
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    SpReleaseRemoveLock(param_1,(char)param_2);
    uVar4 = IofCallDriver(*(undefined8 *)(lVar1 + 0x10),param_2);
  }
  return uVar4;
}



===== SpPdoHandleIoctlStorageQueryProperty @ 140025c38 =====

int SpPdoHandleIoctlStorageQueryProperty(longlong param_1,longlong param_2)

{
  int iVar1;
  
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0xc) {
    iVar1 = -0x3ffffff3;
    *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
    SpReleaseRemoveLock(param_1,(char)param_2);
    SpCompleteRequest(param_1,param_2,(undefined *)0x0,0);
  }
  else {
    iVar1 = ScsiPortQueryPropertyPdo(param_1,param_2);
  }
  return iVar1;
}



===== AppendField @ 140025c8c =====

void AppendField(longlong param_1,undefined8 param_2,longlong param_3,uint param_4)

{
  bool bVar1;
  char cVar2;
  longlong lVar3;
  char *pcVar4;
  ulonglong uVar5;
  
  bVar1 = false;
  if ((param_1 != 0) && (param_3 != 0)) {
    *(undefined1 *)(param_1 + 0x3f) = 0;
    lVar3 = -1;
    do {
      lVar3 = lVar3 + 1;
    } while (*(char *)(param_1 + lVar3) != '\0');
    pcVar4 = (char *)(lVar3 + param_1);
    if ((param_1 - (longlong)pcVar4) + 0x40U <= (ulonglong)param_4) {
      param_4 = ((int)param_1 - (int)pcVar4) + 0x40;
    }
    if (param_4 != 0) {
      uVar5 = (ulonglong)param_4;
      lVar3 = param_3 - (longlong)pcVar4;
      do {
        if (bVar1) {
LAB_140025ceb:
          cVar2 = '_';
        }
        else {
          cVar2 = pcVar4[lVar3];
          if (cVar2 == '\0') {
            bVar1 = true;
            goto LAB_140025ceb;
          }
          if (cVar2 == ' ') {
            cVar2 = '_';
          }
        }
        *pcVar4 = cVar2;
        pcVar4 = pcVar4 + 1;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
  }
  return;
}



===== ScsiPortAddDevice @ 140025d10 =====

uint ScsiPortAddDevice(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  uVar2 = SpCreateAdapter(param_1,local_res18);
  if (local_res18[0] != 0) {
    lVar1 = *(longlong *)(local_res18[0] + 0x40);
    *(byte *)(lVar1 + 0x168) = *(byte *)(lVar1 + 0x168) & 0xfe | 4;
    IoGetDriverObjectExtension(param_1,ScsiPortInitialize);
    *(byte *)(lVar1 + 0x168) = *(byte *)(lVar1 + 0x168) & 0xcf;
    lVar3 = IoAttachDeviceToDeviceStack(local_res18[0],param_2);
    *(longlong *)(lVar1 + 0x10) = lVar3;
    *(undefined8 *)(lVar1 + 0x140) = param_2;
    uVar2 = ~-(uint)(lVar3 != 0) & 0xc0000001;
  }
  return uVar2;
}



===== ScsiPortAddGenericControllerId @ 140025db4 =====

wchar_t * ScsiPortAddGenericControllerId(undefined8 param_1,longlong param_2)

{
  size_t _Size;
  int iVar1;
  wchar_t *_Dst;
  ulonglong uVar2;
  ulonglong uVar3;
  wchar_t *pwVar4;
  uint uVar5;
  wchar_t wVar6;
  
  iVar1 = 0;
  if (param_2 != 0) {
    uVar5 = 0;
    while( true ) {
      if ((*(short *)(param_2 + (ulonglong)uVar5 * 2) == 0) &&
         (*(short *)(param_2 + (ulonglong)(uVar5 + 1) * 2) == 0)) break;
      uVar5 = uVar5 + 1;
    }
    iVar1 = uVar5 + 2;
  }
  _Size = (ulonglong)(iVar1 + 0x11) * 2;
  _Dst = (wchar_t *)SpAllocatePoolEx(1,_Size,0x64506353,param_1,0x706e7020,0xaad);
  if (_Dst != (wchar_t *)0x0) {
    memset(_Dst,0x40,_Size);
    if (param_2 == 0) {
      pwVar4 = _Dst;
    }
    else {
      uVar2 = 0;
      while( true ) {
        uVar3 = (ulonglong)((int)uVar2 + 1);
        wVar6 = *(wchar_t *)(param_2 + uVar2 * 2);
        if ((wVar6 == L'\0') && (*(short *)(param_2 + uVar3 * 2) == 0)) break;
        _Dst[uVar2] = wVar6;
        uVar2 = uVar3;
      }
      _Dst[uVar2] = L'\0';
      pwVar4 = _Dst + uVar3;
    }
    uVar2 = 0;
    wVar6 = L'G';
    do {
      uVar2 = (ulonglong)((int)uVar2 + 1);
      *pwVar4 = wVar6;
      pwVar4 = pwVar4 + 1;
      wVar6 = L"GEN_SCSIADAPTER"[uVar2];
    } while (wVar6 != L'\0');
    pwVar4[0] = L'\0';
    pwVar4[1] = L'\0';
  }
  return _Dst;
}



===== ScsiPortFdoPnp @ 140025eb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong ScsiPortFdoPnp(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  longlong *plVar2;
  longlong *plVar3;
  int *_Src;
  ushort *puVar4;
  undefined8 *puVar5;
  char cVar6;
  byte bVar7;
  int iVar8;
  uint uVar9;
  undefined8 uVar10;
  longlong lVar11;
  uint *puVar12;
  undefined1 *puVar13;
  void *pvVar14;
  longlong *plVar15;
  ulonglong uVar16;
  wchar_t *pwVar17;
  uint uVar18;
  undefined1 uVar19;
  longlong lVar20;
  undefined *puVar21;
  uint *puVar22;
  bool bVar23;
  undefined1 auStackY_c8 [32];
  uint *local_80;
  uint local_70 [10];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_c8;
  plVar3 = *(longlong **)(param_1 + 0x40);
  lVar20 = *(longlong *)(param_2 + 0xb8);
  uVar9 = 0xc0000010;
  LOCK();
  *(int *)((longlong)plVar3 + 0x4c) = *(int *)((longlong)plVar3 + 0x4c) + 1;
  UNLOCK();
  uVar19 = (undefined1)param_2;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qqDd(WPP_GLOBAL_Control[3],WPP_GLOBAL_Control,1,param_1,uVar19,
                *(undefined1 *)(lVar20 + 1),(char)*(undefined4 *)((longlong)plVar3 + 0xc));
  }
  puVar21 = (undefined *)0x1;
  bVar7 = *(byte *)(lVar20 + 1);
  plVar15 = (longlong *)(ulonglong)bVar7;
  uVar18 = (uint)bVar7;
  if (bVar7 < 8) {
    if (bVar7 == 7) {
      iVar8 = *(int *)(lVar20 + 8);
      if ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_(WPP_GLOBAL_Control[3],0x10,&WPP_976cd3c5730d3f52f58c020cb0cc6bda_Traceguids);
        }
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_D(WPP_GLOBAL_Control[3],0x11,&WPP_976cd3c5730d3f52f58c020cb0cc6bda_Traceguids,iVar8
                  );
        }
      }
      if (iVar8 == 0) {
        plVar15 = plVar3 + 0xb1;
        LOCK();
        plVar2 = (longlong *)plVar3[0xb0];
        if (plVar15 == plVar2) {
          plVar3[0xb0] = 0;
        }
        else {
          plVar15 = plVar2;
        }
        UNLOCK();
        if (plVar15 != (longlong *)0x0) {
          *plVar15 = 0;
          plVar15[4] = 0;
          plVar15[1] = (longlong)SpQueryDeviceRelationsCompletion;
          plVar15[3] = param_2;
          plVar15[2] = param_2 + 0x30;
          pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
          *pbVar1 = *pbVar1 | 1;
          SpEnumerateAdapterAsynchronous(plVar3,plVar15);
          return 0x103;
        }
        *(undefined4 *)(param_2 + 0x30) = 0x80000011;
        *(undefined8 *)(param_2 + 0x38) = 0;
        goto LAB_140025fcd;
      }
    }
    else {
      if (uVar18 == 0) {
        lVar11 = IoGetDriverObjectExtension(*(undefined8 *)(param_1 + 8),ScsiPortInitialize);
        puVar22 = *(uint **)(lVar20 + 8);
        local_80 = *(uint **)(lVar20 + 0x10);
        local_70[8] = 0;
        local_70[9] = 0;
        local_70[0] = 0;
        local_70[1] = 0;
        local_70[2] = 0;
        local_70[3] = 0;
        local_70[4] = 0;
        local_70[5] = 0;
        local_70[6] = 0;
        local_70[7] = 0;
        if ((*(byte *)(plVar3 + 0x2d) & 4) == 0) {
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_(WPP_GLOBAL_Control[3],0xb,&WPP_976cd3c5730d3f52f58c020cb0cc6bda_Traceguids);
          }
LAB_1400261d6:
          uVar9 = 0xc0000001;
        }
        else if (*(char *)((longlong)plVar3 + 9) == '\0') {
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_(WPP_GLOBAL_Control[3],0xc,&WPP_976cd3c5730d3f52f58c020cb0cc6bda_Traceguids);
          }
          uVar9 = 0;
        }
        else if (puVar22 == (uint *)0x0) {
          iVar8 = SpGetPdoInterfaceType(plVar3[0x28]);
          for (lVar20 = *(longlong *)(lVar11 + 0x18); lVar20 != 0;
              lVar20 = *(longlong *)(lVar20 + 0x80)) {
            if (*(int *)(lVar20 + 4) == iVar8) {
              if ((lVar20 != 0) && (*(int *)(lVar20 + 0x4c) == 0)) {
                *(byte *)(plVar3 + 0x2d) = *(byte *)(plVar3 + 0x2d) | 0x80;
                puVar22 = local_70;
                local_80 = local_70;
                local_70[1] = iVar8;
                local_70[0] = 1;
                local_70[2] = 0;
                local_70[3] = 0;
                local_70[4] = 0;
                local_70[5] = 0;
                local_70[6] = 0;
                local_70[7] = 0;
                local_70[8] = 0;
                local_70[9] = 0;
                goto LAB_140026294;
              }
              break;
            }
          }
          *(undefined4 *)(param_2 + 0x30) = 0xc0000001;
        }
        else {
LAB_140026294:
          local_70[8] = 0;
          local_70[9] = 0;
          local_70[6] = 0;
          local_70[7] = 0;
          local_70[4] = 0;
          local_70[5] = 0;
          local_70[2] = 0;
          local_70[3] = 0;
          uVar9 = SpQueryPnpInterfaceFlags(lVar11,puVar22[1],puVar21);
          if (uVar9 == 0) {
            if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
               (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              WPP_SF_D(WPP_GLOBAL_Control[3],0xd,&WPP_976cd3c5730d3f52f58c020cb0cc6bda_Traceguids,
                       puVar22[1]);
            }
            *(byte *)(plVar3 + 0x2d) = *(byte *)(plVar3 + 0x2d) & 0xfb;
            goto LAB_1400261d6;
          }
          if ((uVar9 & 4) == 0) {
            *(undefined4 *)((longlong)plVar3 + 0x16c) = 0;
          }
          iVar8 = IoGetDeviceProperty(plVar3[0x28]);
          if (iVar8 < 0) {
            plVar3[0xd8] = 0;
            plVar3[0xd9] = 0;
          }
          if (((iVar8 == -0x3fffffcc) && (*(char *)(lVar11 + 0x28) == '\x01')) && ((uVar9 & 2) != 0)
             ) {
            DbgPrint(
                    "ScsiPortFdoPnp: device has no pnp bus type but was not found as a duplicate during detection\n"
                    );
            *(byte *)(plVar3 + 0x2d) = *(byte *)(plVar3 + 0x2d) & 0xfb;
            uVar9 = 0xc0000001;
          }
          else if ((uVar9 & 8) == 0) {
LAB_1400263d4:
            lVar20 = param_2;
            uVar9 = SpStartLowerDevice(param_1,param_2);
            if (-1 < (int)uVar9) {
              if ((*(byte *)(plVar3 + 1) & 2) == 0) {
                if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                   (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                  lVar20 = 0xe;
                  WPP_SF_q(WPP_GLOBAL_Control[3],0xe,
                           &WPP_976cd3c5730d3f52f58c020cb0cc6bda_Traceguids,param_1);
                }
                pvVar14 = RtlDuplicateCmResourceList(*(undefined8 *)(param_1 + 8),lVar20,puVar22);
                plVar3[0x40] = (longlong)pvVar14;
                pvVar14 = RtlDuplicateCmResourceList(*(undefined8 *)(param_1 + 8),lVar20,local_80);
                plVar3[0x41] = (longlong)pvVar14;
                *(byte *)(plVar3 + 1) = *(byte *)(plVar3 + 1) | 2;
                uVar9 = ScsiPortInitPnpAdapter(param_1);
                if ((int)uVar9 < 0) {
                  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
                    WPP_SF_D(WPP_GLOBAL_Control[3],0xf,
                             &WPP_976cd3c5730d3f52f58c020cb0cc6bda_Traceguids,uVar9);
                  }
                  goto LAB_140025fcd;
                }
              }
              uVar10 = ScsiPortStartAdapter(param_1);
              uVar9 = (uint)uVar10;
              if (-1 < (int)uVar9) {
                *(undefined2 *)((longlong)plVar3 + 9) = 0xff00;
              }
            }
          }
          else {
            uVar9 = puVar22[4];
            uVar18 = 0;
            if (uVar9 != 0) {
              puVar12 = puVar22;
              do {
                puVar12 = puVar12 + 5;
                if ((char)*puVar12 == '\x02') goto LAB_1400263d4;
                uVar18 = uVar18 + 1;
              } while (uVar18 < uVar9);
            }
            puVar13 = (undefined1 *)
                      IoAllocateErrorLogEntry(param_1,CONCAT71((uint7)(uint3)(uVar9 >> 8),0x30));
            uVar9 = 0xc0000182;
            if (puVar13 != (undefined1 *)0x0) {
              *puVar13 = 0x1b;
              *(undefined4 *)(puVar13 + 0x10) = 0x418;
              *(undefined4 *)(puVar13 + 0xc) = 0xc004000d;
              IoWriteErrorLogEntry(puVar13);
            }
          }
        }
        goto LAB_140025fcd;
      }
      if (uVar18 == 1) {
LAB_140026131:
        if (((*(byte *)(plVar3 + 0x2d) & 4) == 0) ||
           (cVar6 = SpIsAdapterControlTypeSupported((longlong)plVar3,1), cVar6 == '\0')) {
          uVar9 = 0xc0000001;
          bVar7 = 0;
          goto LAB_1400268a6;
        }
LAB_1400266c7:
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      else {
        if (uVar18 == 2) {
          if (((*(byte *)(plVar3 + 0x2d) & 4) != 0) &&
             ((*(char *)((longlong)plVar3 + 9) != '\0' ||
              (cVar6 = SpIsAdapterControlTypeSupported((longlong)plVar3,1), cVar6 != '\0')))) {
            if (plVar3[0xdb] != 0) {
              plVar2 = plVar3 + 0xda;
              IoSetDeviceInterfaceState(plVar2,0);
              RtlFreeUnicodeString(plVar2);
              RtlInitUnicodeString(plVar2,0);
            }
            if (plVar3[0xff] != 0) {
              ExFreePoolWithTag(plVar3[0xff],0);
              plVar3[0xff] = 0;
            }
            SpReleaseRemoveLock(param_1,uVar19);
            ScsiPortRemoveAdapter(param_1,0,puVar21,plVar15);
            *(undefined2 *)((longlong)plVar3 + 9) = 0xff02;
            uVar9 = SpSendIrpSynchronous(plVar3[2],param_2);
            *(undefined4 *)((longlong)plVar3 + 0xc) = 2;
            IofCompleteRequest(param_2,0);
            IoDetachDevice(plVar3[2]);
            IoDeleteDevice(param_1);
            goto LAB_140025fe3;
          }
          goto LAB_1400261d6;
        }
        if (uVar18 != 3) {
          if (uVar18 == 4) {
            uVar10 = ScsiPortStopAdapter(param_1,param_2);
            uVar9 = (uint)uVar10;
            *(uint *)(param_2 + 0x30) = uVar9;
            *(undefined8 *)(param_2 + 0x38) = 0;
            if (-1 < (int)uVar9) {
              *(undefined1 *)((longlong)plVar3 + 10) = *(undefined1 *)((longlong)plVar3 + 9);
              *(undefined1 *)((longlong)plVar3 + 9) = 4;
              goto LAB_1400268ae;
            }
          }
          else {
            if (uVar18 != 5) {
              if (uVar18 != 6) goto LAB_1400265c7;
              *(undefined4 *)(param_2 + 0x30) = 0;
              bVar23 = *(char *)((longlong)plVar3 + 9) == '\x05';
              goto LAB_140025fa0;
            }
            if ((*(byte *)(plVar3 + 0x2d) & 0x20) == 0) goto LAB_140026131;
            uVar9 = 0xc00000bb;
          }
          goto LAB_140025fcd;
        }
        *(undefined4 *)(param_2 + 0x30) = 0;
        bVar23 = *(char *)((longlong)plVar3 + 9) == '\x01';
LAB_140025fa0:
        if (bVar23) {
          *(undefined1 *)((longlong)plVar3 + 9) = *(undefined1 *)((longlong)plVar3 + 10);
          *(undefined1 *)((longlong)plVar3 + 10) = 0xff;
        }
      }
    }
LAB_1400268ae:
    if (plVar3[2] != 0) {
      puVar5 = *(undefined8 **)(param_2 + 0xb8);
      puVar5[-9] = *puVar5;
      puVar5[-8] = puVar5[1];
      puVar5[-7] = puVar5[2];
      puVar5[-6] = puVar5[3];
      puVar5[-5] = puVar5[4];
      puVar5[-4] = puVar5[5];
      puVar5[-3] = puVar5[6];
      *(undefined1 *)((longlong)puVar5 + -0x45) = 0;
      SpReleaseRemoveLock(param_1,uVar19);
      uVar9 = IofCallDriver(plVar3[2],param_2);
      goto LAB_140025fe3;
    }
    uVar9 = 0xc0000001;
  }
  else {
    if (bVar7 != 8) {
      if (bVar7 == 0xd) {
        lVar20 = *(longlong *)(lVar20 + 8);
        if (lVar20 != 0) {
          *(undefined4 *)(plVar3 + 0x2e) = *(undefined4 *)(lVar20 + 8);
          *(undefined4 *)((longlong)plVar3 + 0x174) = *(undefined4 *)(lVar20 + 0xc);
        }
      }
      else if (bVar7 == 0x13) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_(WPP_GLOBAL_Control[3],0x12,&WPP_976cd3c5730d3f52f58c020cb0cc6bda_Traceguids);
        }
        if (*(int *)(lVar20 + 8) == 2) {
          SpSendIrpSynchronous(plVar3[2],param_2);
          pwVar17 = ScsiPortAddGenericControllerId
                              (*(undefined8 *)(param_1 + 8),*(longlong *)(param_2 + 0x38));
          if (pwVar17 == (wchar_t *)0x0) {
            uVar9 = 0xc000009a;
          }
          else {
            uVar9 = 0;
            if (*(longlong *)(param_2 + 0x38) != 0) {
              ExFreePoolWithTag(*(longlong *)(param_2 + 0x38),0);
            }
            *(wchar_t **)(param_2 + 0x38) = pwVar17;
          }
          goto LAB_140025fcd;
        }
      }
      else if (bVar7 == 0x14) {
        uVar9 = *(uint *)(plVar3 + 0xdc);
        *(uint *)(param_2 + 0x38) = uVar9;
        if (*(int *)((longlong)plVar3 + 0x104) != 0) {
          *(uint *)(param_2 + 0x38) = uVar9 | 0x20;
        }
      }
      else {
        if (bVar7 == 0x16) goto LAB_1400266c7;
        if (bVar7 == 0x17) {
          *(undefined4 *)((longlong)plVar3 + 0xc) = 1;
          if (*(char *)((longlong)plVar3 + 9) == '\0') {
            SpTerminateAdapter(plVar3);
          }
          if (plVar3[0xdb] != 0) {
            plVar2 = plVar3 + 0xda;
            IoSetDeviceInterfaceState(plVar2,0);
            RtlFreeUnicodeString(plVar2);
            RtlInitUnicodeString(plVar2,0);
          }
          SpReleaseRemoveLock(param_1,uVar19);
          lVar20 = param_1;
          SpWaitForRemoveLock(param_1,(char)param_1);
          ScsiPortRemoveAdapter(param_1,CONCAT71((int7)((ulonglong)lVar20 >> 8),1),puVar21,plVar15);
          *(undefined1 *)((longlong)plVar3 + 10) = *(undefined1 *)((longlong)plVar3 + 9);
          *(undefined1 *)((longlong)plVar3 + 9) = 0x17;
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
          uVar16 = IofCallDriver(plVar3[2],param_2);
          return uVar16;
        }
LAB_1400265c7:
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_D(WPP_GLOBAL_Control[3],0x13,&WPP_976cd3c5730d3f52f58c020cb0cc6bda_Traceguids,
                   uVar18);
        }
      }
      goto LAB_1400268ae;
    }
    if ((*(undefined **)(lVar20 + 8) == &GUID_STORAGE_QUERY_FDO_INFO) ||
       (lVar11 = RtlCompareMemory(), lVar11 == 0x10)) {
      puVar4 = *(ushort **)(*(longlong *)(param_2 + 0xb8) + 0x18);
      if ((puVar4 == (ushort *)0x0) || (*(ushort *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0x10)) {
        uVar9 = 0xc000000d;
      }
      else if (*puVar4 < 0x10) {
        *puVar4 = 0x10;
        uVar9 = 0x80000005;
      }
      else {
        uVar9 = 0;
        *(longlong *)(puVar4 + 4) = plVar3[0x28];
      }
      *(uint *)(param_2 + 0x30) = uVar9;
      bVar7 = (byte)(uVar9 >> 0x1f) ^ 1;
LAB_1400268a6:
      if (bVar7 == 0) goto LAB_140025fcd;
      goto LAB_1400268ae;
    }
    if ((*(undefined **)(lVar20 + 8) != &GUID_STORAGE_QUERY_FDO_DEVICE_RELATIONS) &&
       (lVar20 = RtlCompareMemory(), lVar20 != 0x10)) goto LAB_1400268ae;
    _Src = (int *)plVar3[0xff];
    puVar4 = *(ushort **)(*(longlong *)(param_2 + 0xb8) + 0x18);
    if (puVar4 == (ushort *)0x0) {
LAB_14002681d:
      uVar9 = 0xc000000d;
    }
    else if (_Src == (int *)0x0) {
      uVar9 = 0xc000009a;
    }
    else {
      if (*(ushort *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0x18) goto LAB_14002681d;
      iVar8 = *_Src * 8;
      if ((uint)*puVar4 < iVar8 + 0x10U) {
        *(int *)(puVar4 + 4) = *_Src;
        uVar9 = 0x80000005;
      }
      else {
        memcpy(puVar4 + 4,_Src,(ulonglong)(iVar8 + 8));
        uVar9 = 0;
      }
    }
    *(uint *)(param_2 + 0x30) = uVar9;
    if (-1 < (int)uVar9) goto LAB_1400268ae;
  }
LAB_140025fcd:
  SpReleaseRemoveLock(param_1,uVar19);
  *(uint *)(param_2 + 0x30) = uVar9;
  SpCompleteRequest(param_1,param_2,(undefined *)0x0,0);
LAB_140025fe3:
  return (ulonglong)uVar9;
}



===== ScsiPortGetDeviceId @ 140026918 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ScsiPortGetDeviceId(longlong param_1,undefined8 param_2)

{
  byte bVar1;
  longlong lVar3;
  longlong lVar2;
  ulonglong uVar4;
  ulonglong uVar5;
  char *pcVar6;
  byte *pbVar7;
  uint uVar8;
  char *pcVar9;
  undefined **ppuVar10;
  byte *pbVar11;
  byte *pbVar12;
  uint uVar13;
  undefined1 auStackY_198 [32];
  wchar_t local_160 [12];
  char local_148 [256];
  ulonglong local_48 [2];
  
  local_48[0] = __security_cookie ^ (ulonglong)auStackY_198;
  pbVar11 = (byte *)(*(longlong *)(param_1 + 0x40) + 0x1fa);
  local_160[0] = L'\0';
  local_160[1] = L'\0';
  local_160[2] = L'\0';
  local_160[3] = L'\0';
  local_160[4] = L'\0';
  local_160[5] = L'\0';
  local_160[6] = L'\0';
  local_160[7] = L'\0';
  memset(local_148,0,0x100);
  bVar1 = *pbVar11 & 0x1f;
  if (bVar1 < 0x12) {
    ppuVar10 = &DeviceTypeInfo + (ulonglong)bVar1 * 4;
  }
  else {
    ppuVar10 = &PTR_s_Other_140013320;
  }
  RtlStringCbPrintfA(local_148,0x100,"SCSI\\%s",*ppuVar10);
  lVar2 = -1;
  do {
    lVar3 = lVar2;
    lVar2 = lVar3 + 1;
  } while (local_148[lVar3 + 1] != '\0');
  pbVar7 = (byte *)(local_148 + lVar3 + 1);
  uVar13 = 0;
  do {
    pcVar6 = (char *)0x0;
    pbVar12 = (byte *)0x0;
    if (uVar13 == 0) {
      uVar5 = 8;
      pcVar6 = "Ven";
LAB_140026a0c:
      uVar4 = uVar5;
LAB_140026a0f:
      pbVar12 = pbVar11 + uVar5;
      do {
        uVar8 = (int)uVar4 - 1;
        uVar5 = (ulonglong)uVar8;
        if ((pbVar12[uVar5] != 0x20) && (pbVar12[uVar5] != 0)) break;
        uVar4 = uVar5;
      } while (uVar8 != 0);
    }
    else {
      if (uVar13 == 1) {
        uVar5 = 0x10;
        pcVar6 = "Prod";
        goto LAB_140026a0c;
      }
      uVar4 = 0;
      if (uVar13 == 2) {
        uVar5 = 0x20;
        pcVar6 = "Rev";
        uVar4 = 4;
        goto LAB_140026a0f;
      }
    }
    pcVar9 = "&%s_";
    RtlStringCbPrintfA((char *)pbVar7,(longlong)local_48 - (longlong)pbVar7,"&%s_",pcVar6);
    lVar2 = -1;
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (pcVar6[lVar2] != '\0');
    pbVar7 = pbVar7 + lVar3 + 3;
    if (0xff < (ulonglong)((longlong)pbVar7 - (longlong)local_148)) break;
    if ((ulonglong)((longlong)local_48 - (longlong)pbVar7) <= uVar4) {
      uVar4 = (ulonglong)(uint)((int)local_48 - (int)pbVar7);
    }
    if ((int)uVar4 != 0) {
      do {
        bVar1 = 0x5f;
        if (*pbVar12 != 0x20) {
          bVar1 = *pbVar12;
        }
        pbVar12 = pbVar12 + 1;
        *pbVar7 = bVar1;
        pbVar7 = pbVar7 + 1;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    }
    uVar13 = uVar13 + 1;
  } while (uVar13 < 3);
  pcVar6 = local_148;
  RtlInitAnsiString(local_160);
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qaZ(WPP_GLOBAL_Control[3],pcVar6,pcVar9,param_1,local_160);
  }
  RtlAnsiStringToUnicodeString(param_2,local_160,1);
  return;
}



===== ScsiPortGetHardwareIds @ 140026b48 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong ScsiPortGetHardwareIds
                    (undefined8 param_1,byte *param_2,ulonglong *param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong lVar2;
  void *_Dst;
  undefined8 uVar3;
  undefined **ppuVar4;
  longlong *plVar5;
  uint uVar6;
  ulonglong uVar7;
  size_t _Size;
  byte *pbVar8;
  uint uVar9;
  longlong lVar10;
  undefined1 auStackY_f8 [32];
  longlong local_c0 [7];
  char local_88 [64];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_f8;
  if ((*param_2 & 0x1f) < 0x12) {
    ppuVar4 = &DeviceTypeInfo + ((ulonglong)*param_2 & 0x1f) * 4;
  }
  else {
    ppuVar4 = &PTR_s_Other_140013320;
  }
  local_c0[0] = 0;
  local_c0[1] = 0;
  local_c0[2] = 0;
  local_c0[3] = 0;
  local_c0[4] = 0;
  local_c0[5] = 0;
  local_c0[6] = 0;
  uVar7 = 0;
  lVar10 = 6;
  while( true ) {
    uVar6 = (uint)uVar7;
    if (5 < uVar6) break;
    uVar3 = 0;
    memset(local_88,0,0x40);
    if (uVar6 == 0) {
      uVar3 = 0x40;
      RtlStringCbPrintfA(local_88,0x40,"SCSI\\%s",*ppuVar4);
      AppendField((longlong)local_88,uVar3,(longlong)(param_2 + 8),8);
      AppendField((longlong)local_88,uVar3,(longlong)(param_2 + 0x10),0x10);
      uVar9 = 4;
LAB_140026d0e:
      pbVar8 = param_2 + 0x20;
LAB_140026d12:
      AppendField((longlong)local_88,uVar3,(longlong)pbVar8,uVar9);
    }
    else {
      if (uVar6 == 1) {
        uVar3 = 0x40;
        RtlStringCbPrintfA(local_88,0x40,"SCSI\\%s",*ppuVar4);
        AppendField((longlong)local_88,uVar3,(longlong)(param_2 + 8),8);
        pbVar8 = param_2 + 0x10;
        uVar9 = 0x10;
        goto LAB_140026d12;
      }
      if (uVar6 == 2) {
        uVar3 = 0x40;
        RtlStringCbPrintfA(local_88,0x40,"SCSI\\%s",*ppuVar4);
        pbVar8 = param_2 + 8;
        uVar9 = 8;
        goto LAB_140026d12;
      }
      if (uVar6 == 3) {
        uVar3 = 0x40;
        RtlStringCbPrintfA(local_88,0x40,"SCSI\\",param_4);
LAB_140026c39:
        AppendField((longlong)local_88,uVar3,(longlong)(param_2 + 8),8);
        AppendField((longlong)local_88,uVar3,(longlong)(param_2 + 0x10),0x10);
        uVar9 = 1;
        goto LAB_140026d0e;
      }
      if (uVar6 == 4) goto LAB_140026c39;
      if (uVar6 == 5) {
        _Size = 0xffffffffffffffff;
        do {
          _Size = _Size + 1;
        } while (ppuVar4[1][_Size] != '\0');
        memcpy(local_88,ppuVar4[1],_Size);
      }
    }
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (local_88[lVar2 + 1] != '\0');
    if (lVar2 + 1 == 0) break;
    param_4 = param_1;
    _Dst = (void *)SpAllocatePoolEx(1,lVar2 + 2U,0x64506353,param_1,0x706e7020,0x730);
    local_c0[uVar7] = (longlong)_Dst;
    if (_Dst == (void *)0x0) {
      uVar7 = 0xc000009a;
      goto LAB_140026d97;
    }
    memcpy(_Dst,local_88,lVar2 + 2U);
    uVar7 = (ulonglong)(uVar6 + 1);
  }
  uVar7 = ScsiPortStringArrayToMultiString(param_1,param_3,local_c0);
  uVar7 = uVar7 & 0xffffffff;
LAB_140026d97:
  plVar5 = local_c0;
  do {
    if (*plVar5 != 0) {
      ExFreePoolWithTag(*plVar5,0);
    }
    plVar5 = plVar5 + 1;
    lVar10 = lVar10 + -1;
  } while (lVar10 != 0);
  return uVar7;
}



===== ScsiPortStartAdapter @ 140026de8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 ScsiPortStartAdapter(longlong param_1)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  undefined8 *puVar4;
  uint uVar5;
  wchar_t *pwVar6;
  ulonglong uVar7;
  undefined1 auStack_e8 [32];
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  wchar_t local_98 [64];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_e8;
  IoGetDriverObjectExtension(*(undefined8 *)(param_1 + 8),ScsiPortInitialize);
  plVar1 = *(longlong **)(param_1 + 0x40);
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_q(WPP_GLOBAL_Control[3],0x14,&WPP_976cd3c5730d3f52f58c020cb0cc6bda_Traceguids,param_1);
  }
  *(undefined4 *)((longlong)plVar1 + 0x6e4) = 0;
  IoStartTimer(param_1);
  if ((*(byte *)(plVar1 + 1) & 4) == 0) {
    SpWmiInitializeSpRegInfo(param_1);
    if (plVar1[8] != 0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_q(WPP_GLOBAL_Control[3],0x15,&WPP_976cd3c5730d3f52f58c020cb0cc6bda_Traceguids,param_1
                );
      }
      IoWMIRegistrationControl(param_1,1);
      *(byte *)(plVar1 + 1) = *(byte *)(plVar1 + 1) | 4;
    }
    if ((*(byte *)(plVar1 + 1) & 8) != 0) {
      SpWmiInitializeFreeRequestList(param_1);
    }
  }
  if (*(int *)((longlong)plVar1 + 0x15c) == -1) {
    local_a8 = 0;
    uStack_a0 = 0;
    local_b8 = 0;
    uStack_b0 = 0;
    RtlInitUnicodeString(&local_a8,plVar1[0xd7]);
    uVar5 = 0;
    do {
      pwVar6 = L"\\Device\\ScsiPort%d";
      uVar7 = (ulonglong)uVar5;
      local_c8 = 0;
      uStack_c0 = 0;
      RtlStringCbPrintfW(local_98,0x80,L"\\Device\\ScsiPort%d",uVar7);
      RtlInitUnicodeString(&local_c8,local_98);
      puVar4 = &local_a8;
      iVar2 = IoCreateSymbolicLink(&local_c8);
      if (-1 < iVar2) {
        uVar7 = (ulonglong)uVar5;
        *(uint *)((longlong)plVar1 + 0x15c) = uVar5;
        pwVar6 = L"\\DosDevices\\Scsi%d:";
        RtlStringCbPrintfW(local_98,0x80,L"\\DosDevices\\Scsi%d:",uVar7);
        RtlInitUnicodeString(&local_c8,local_98);
        puVar4 = &local_a8;
        IoCreateSymbolicLink(&local_c8);
        break;
      }
      uVar5 = uVar5 + 1;
    } while (iVar2 == -0x3fffffcb);
    lVar3 = IoGetConfigurationInformation();
    *(int *)(lVar3 + 0x10) = *(int *)(lVar3 + 0x10) + 1;
    if ((*(byte *)(plVar1 + 1) & 1) == 0) {
      SpBuildAdapterDeviceMap(plVar1,puVar4,pwVar6,uVar7);
    }
    else {
      SpBuildLogicalUnitDeviceMapEntry((longlong)plVar1,puVar4,pwVar6,uVar7);
    }
    iVar2 = IoRegisterDeviceInterface(plVar1[0x28],&GUID_DEVINTERFACE_STORAGEPORT,0,&local_b8);
    if (-1 < iVar2) {
      *(undefined4 *)(plVar1 + 0xda) = (undefined4)local_b8;
      *(undefined4 *)((longlong)plVar1 + 0x6d4) = local_b8._4_4_;
      *(undefined4 *)(plVar1 + 0xdb) = (undefined4)uStack_b0;
      *(undefined4 *)((longlong)plVar1 + 0x6dc) = uStack_b0._4_4_;
      iVar2 = IoSetDeviceInterfaceState(&local_b8,1);
      if (iVar2 < 0) {
        RtlFreeUnicodeString(&local_b8);
        RtlInitUnicodeString(plVar1 + 0xda,0);
      }
    }
  }
  *(undefined4 *)(plVar1 + 0xa8) = 1;
  return 0;
}



===== ScsiPortUnload @ 140027080 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140027140) */

ulonglong ScsiPortUnload(undefined8 param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  
  uVar2 = IoGetDriverObjectExtension(param_1,ScsiPortInitialize);
  if (uVar2 != 0) {
    uVar1 = *(ulonglong *)(uVar2 + 0x38);
    uVar3 = uVar2;
    if (uVar1 != 0) {
      LOCK();
      uVar3 = *(ulonglong *)(uVar2 + 0x38);
      if (uVar1 == uVar3) {
        *(ulonglong *)(uVar2 + 0x38) = 0;
        uVar3 = uVar1;
      }
      else {
      }
      UNLOCK();
      if (uVar1 == uVar3) {
        uVar3 = IoFreeErrorLogEntry();
      }
    }
    uVar1 = *(ulonglong *)(uVar2 + 0x58);
    if (uVar1 != 0) {
      LOCK();
      uVar3 = *(ulonglong *)(uVar2 + 0x58);
      if (uVar1 == uVar3) {
        *(ulonglong *)(uVar2 + 0x58) = 0;
        uVar3 = uVar1;
      }
      else {
      }
      UNLOCK();
      if (uVar1 == uVar3) {
        MmProtectMdlSystemAddress(*(undefined8 *)(uVar2 + 0x50),4);
        MmUnlockPages(*(undefined8 *)(uVar2 + 0x50));
        IoFreeMdl(*(undefined8 *)(uVar2 + 0x50));
        uVar3 = ExFreePoolWithTag(*(undefined8 *)(uVar2 + 0x48),0);
      }
    }
    uVar2 = uVar3;
    if (VerifierApiCodeSectionHandle != 0) {
      LOCK();
      VerifierApiCodeSectionHandle = 0;
      UNLOCK();
      uVar2 = MmUnlockPagableImageSection();
    }
    if ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      uVar2 = (ulonglong)WPPTraceSuite;
      puVar4 = WPP_GLOBAL_Control;
      if (WPPTraceSuite == 4) {
        for (; puVar4 != (undefined8 *)0x0; puVar4 = (undefined8 *)puVar4[2]) {
          if (puVar4[7] != 0) {
            uVar2 = (*pfnEtwUnregister)();
            puVar4[7] = 0;
          }
        }
      }
      else if (WPPTraceSuite == 2) {
        uVar2 = IoWMIRegistrationControl(WPP_GLOBAL_Control,0x80000002);
      }
      WPP_GLOBAL_Control = &WPP_GLOBAL_Control;
    }
  }
  return uVar2;
}



===== SpFindInitData @ 1400271d0 =====

void SpFindInitData(longlong param_1,int param_2)

{
  longlong lVar1;
  
  for (lVar1 = *(longlong *)(param_1 + 0x18); (lVar1 != 0 && (*(int *)(lVar1 + 4) != param_2));
      lVar1 = *(longlong *)(lVar1 + 0x80)) {
  }
  return;
}



===== SpGetSlotNumber @ 1400271f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SpGetSlotNumber(longlong param_1,longlong param_2,longlong param_3)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  code *pcVar4;
  undefined1 auStack_188 [32];
  undefined8 local_168;
  int local_158;
  int local_154;
  int local_150;
  int local_14c;
  longlong local_148;
  longlong local_140;
  longlong *local_138;
  longlong local_130;
  undefined8 local_128;
  longlong lStack_120;
  undefined8 *local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  ulonglong uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined1 local_d8 [8];
  undefined4 local_d0;
  wchar_t *local_c8;
  int *local_c0;
  undefined4 local_b8;
  int *local_b0;
  undefined4 local_a8;
  undefined4 local_98;
  wchar_t *local_90;
  int *local_88;
  undefined4 local_80;
  int *local_78;
  undefined4 local_70;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_188;
  plVar1 = *(longlong **)(param_1 + 0x40);
  local_148 = 0;
  local_140 = 0;
  local_158 = 0xc000000d;
  *(byte *)(plVar1 + 0x2d) = *(byte *)(plVar1 + 0x2d) & 0xfd;
  local_128 = 0;
  lStack_120 = 0;
  local_118 = (undefined8 *)0x0;
  uStack_110 = 0;
  local_108 = 0;
  uStack_100 = uStack_100 & 0xffffffff00000000;
  local_f8 = 0;
  uStack_f0 = 0;
  local_138 = plVar1;
  local_130 = param_2;
  local_158 = IoOpenDeviceRegistryKey(plVar1[0x28],1,0x20019,&local_148);
  if (local_158 < 0) goto LAB_140027486;
  RtlInitUnicodeString(&local_f8,L"Scsiport");
  local_128 = CONCAT44(local_128._4_4_,0x30);
  lStack_120 = local_148;
  uStack_110 = CONCAT44(uStack_110._4_4_,0x240);
  local_118 = &local_f8;
  local_108 = 0;
  uStack_100 = 0;
  local_158 = ZwOpenKey(&local_140,0x20019,&local_128);
  if (local_158 < 0) goto LAB_140027486;
  local_14c = -1;
  local_150 = -1;
  local_154 = -1;
  memset(local_d8,0,0xa8);
  lVar2 = local_140;
  local_d0 = 0x20;
  local_c8 = L"SlotNumber";
  local_c0 = &local_154;
  local_b8 = 4;
  local_b0 = &local_14c;
  local_a8 = 4;
  local_98 = 0x20;
  local_90 = L"BusNumber";
  local_88 = &local_150;
  local_80 = 4;
  local_78 = &local_14c;
  local_70 = 4;
  local_e8 = 0;
  uStack_e0 = 0;
  RtlInitUnicodeString(&local_e8,L"RtlQueryRegistryValuesEx");
  pcVar4 = (code *)MmGetSystemRoutineAddress(&local_e8);
  if (pcVar4 == (code *)0x0) {
    pcVar4 = RtlQueryRegistryValues_exref;
  }
  local_168 = 0;
  local_158 = (*pcVar4)(0x40000000,lVar2,local_d8,0);
  if (local_158 < 0) goto LAB_140027486;
  if (local_150 == local_14c) {
    if (local_154 == local_14c) {
      local_158 = -0x3fffffff;
      goto LAB_140027486;
    }
    if (local_150 != local_14c) goto LAB_14002745a;
  }
  else {
LAB_14002745a:
    if (local_154 != local_14c) {
      *(int *)(param_2 + 4) = local_150;
      *(int *)(param_2 + 100) = local_154;
      *(byte *)(plVar1 + 0x2d) = *(byte *)(plVar1 + 0x2d) & 0xfd;
      goto LAB_140027486;
    }
  }
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_3 + 8);
  *(undefined4 *)(param_2 + 100) = 0;
  *(byte *)(plVar1 + 0x2d) = *(byte *)(plVar1 + 0x2d) | 2;
LAB_140027486:
  if (local_158 < 0) {
    iVar3 = SpQueryCapabilities(plVar1);
    if (-1 < iVar3) {
      *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_3 + 8);
      *(undefined4 *)(param_2 + 100) = *(undefined4 *)((longlong)plVar1 + 0x16c);
      *(byte *)(plVar1 + 0x2d) = *(byte *)(plVar1 + 0x2d) | 2;
    }
  }
  if (local_148 != 0) {
    ZwClose();
  }
  if (local_140 != 0) {
    ZwClose();
  }
  return;
}



===== SpQueryCapabilities @ 140027504 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SpQueryCapabilities(longlong *param_1)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  undefined1 auStackY_b8 [32];
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined4 local_68 [2];
  uint local_60;
  undefined4 local_5c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_78 = 0;
  local_88 = 0;
  uStack_80 = 0;
  memset(local_68,0,0x40);
  local_68[0] = 0x10040;
  local_5c = 0xffffffff;
  uVar6 = 1;
  local_60 = 0xffffffff;
  puVar5 = &local_88;
  KeInitializeEvent(puVar5,1,0);
  lVar3 = SpAllocateIrpEx(CONCAT71((int7)((ulonglong)puVar5 >> 8),
                                   *(char *)(*param_1 + 0x4c) + '\x01'),uVar6,
                          *(undefined8 *)(*param_1 + 8),0x706e7020,0xb0b);
  uVar4 = 0;
  if (lVar3 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(undefined4 **)(lVar1 + -0x40) = local_68;
    *(undefined2 *)(lVar1 + -0x48) = 0x91b;
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(undefined4 *)(lVar3 + 0x30) = 0xc00000bb;
    *(code **)(lVar1 + -0x10) = SpSignalCompletion;
    *(undefined8 **)(lVar1 + -8) = &local_88;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    IofCallDriver(*param_1,lVar3);
    KeWaitForSingleObject(&local_88,0,0,0);
    iVar2 = *(int *)(lVar3 + 0x30);
    if (-1 < iVar2) {
      uVar4 = (local_60 >> 0x10 ^ *(uint *)((longlong)param_1 + 0x16c)) & 0x1f ^
              *(uint *)((longlong)param_1 + 0x16c);
      uVar4 = ((local_60 & 0xffff) << 5 ^ uVar4) & 0xe0 ^ uVar4;
    }
    *(uint *)((longlong)param_1 + 0x16c) = uVar4;
    IoFreeIrp(lVar3);
  }
  return iVar2;
}



===== SpQueryDeviceRelationsCompletion @ 140027690 =====

longlong SpQueryDeviceRelationsCompletion(longlong *param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  void *_Dst;
  longlong lVar5;
  uint *puVar6;
  uint uVar7;
  ulonglong uVar8;
  uint *local_res8;
  
  lVar1 = *(longlong *)(param_2 + 0x18);
  local_res8 = (uint *)0x0;
  uVar4 = SpExtractDeviceRelations(param_1,param_2,&local_res8);
  puVar6 = local_res8;
  iVar3 = (int)uVar4;
  if (-1 < iVar3) {
    lVar2 = *param_1;
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_dq(WPP_GLOBAL_Control[3],0x19,&WPP_976cd3c5730d3f52f58c020cb0cc6bda_Traceguids,
                *local_res8,(char)param_1);
    }
    uVar8 = 0;
    if (*puVar6 != 0) {
      do {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_dq(WPP_GLOBAL_Control[3],0x1a,&WPP_976cd3c5730d3f52f58c020cb0cc6bda_Traceguids,
                    (int)uVar8,(char)*(undefined8 *)(puVar6 + uVar8 * 2 + 2));
        }
        uVar7 = (int)uVar8 + 1;
        uVar8 = (ulonglong)uVar7;
      } while (uVar7 < *puVar6);
    }
    if (param_1[0xff] != 0) {
      ExFreePoolWithTag(param_1[0xff],0);
      param_1[0xff] = 0;
    }
    uVar7 = *puVar6 * 8 + 8;
    _Dst = (void *)SpAllocatePoolEx(1,(ulonglong)uVar7,0x75506353,*(undefined8 *)(lVar2 + 8),
                                    0x706e7020,0xbbb);
    param_1[0xff] = (longlong)_Dst;
    if (_Dst != (void *)0x0) {
      memcpy(_Dst,puVar6,(ulonglong)uVar7);
    }
  }
  lVar5 = 0;
  LOCK();
  lVar2 = param_1[0xb0];
  if (lVar2 == 0) {
    param_1[0xb0] = (longlong)(param_1 + 0xb1);
  }
  else {
    lVar5 = lVar2;
  }
  UNLOCK();
  puVar6 = (uint *)0x0;
  if (-1 < iVar3) {
    puVar6 = local_res8;
  }
  *(uint **)(lVar1 + 0x38) = puVar6;
  *(int *)(lVar1 + 0x30) = iVar3;
  return lVar5;
}



===== SpStartLowerDevice @ 14002780c =====

int SpStartLowerDevice(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  undefined1 uVar7;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar4 = SpAllocatePoolEx(0,0x18,0x76506353,*(undefined8 *)(param_1 + 8),0x706e7020,0x952);
  if (lVar4 == 0) {
    iVar3 = -0x3fffff66;
  }
  else {
    uVar7 = 1;
    KeInitializeEvent(lVar4,1);
    puVar2 = *(undefined8 **)(param_2 + 0xb8);
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
    lVar5 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar5 + -0x10) = SpSignalCompletion;
    *(longlong *)(lVar5 + -8) = lVar4;
    *(undefined1 *)(lVar5 + -0x45) = 0xe0;
    lVar5 = *(longlong *)(lVar1 + 0x10);
    lVar6 = param_2;
    iVar3 = IofCallDriver(lVar5);
    if (iVar3 == 0x103) {
      lVar6 = 0;
      lVar5 = lVar4;
      KeWaitForSingleObject(lVar4,0,0,0,0);
      iVar3 = *(int *)(param_2 + 0x30);
    }
    if (-1 < iVar3) {
      lVar5 = SpAllocateIrpEx(CONCAT71((int7)((ulonglong)lVar5 >> 8),*(undefined1 *)(param_1 + 0x4c)
                                      ),lVar6,*(undefined8 *)(param_1 + 8),0x706e7020,0x974);
      if (lVar5 != 0) {
        lVar6 = *(longlong *)(lVar5 + 0xb8);
        *(undefined4 *)(lVar5 + 0x30) = 0xc00000bb;
        *(undefined **)(lVar6 + -0x40) = &GUID_BUS_INTERFACE_STANDARD;
        *(longlong *)(lVar6 + -0x30) = lVar1 + 0x668;
        *(undefined4 *)(lVar6 + -0x38) = 0x10040;
        *(undefined2 *)(lVar6 + -0x48) = 0x81b;
        KeResetEvent(lVar4);
        lVar6 = *(longlong *)(lVar5 + 0xb8);
        *(code **)(lVar6 + -0x10) = SpSignalCompletion;
        *(longlong *)(lVar6 + -8) = lVar4;
        *(undefined1 *)(lVar6 + -0x45) = 0xe0;
        IofCallDriver(*(undefined8 *)(lVar1 + 0x10),lVar5);
        KeWaitForSingleObject(lVar4,0,0,0,0);
        if (*(int *)(lVar5 + 0x30) < 0) {
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_D(WPP_GLOBAL_Control[3],0x18,&WPP_976cd3c5730d3f52f58c020cb0cc6bda_Traceguids,
                     *(int *)(lVar5 + 0x30));
          }
          uVar7 = 0;
        }
        *(undefined1 *)(lVar1 + 0x661) = uVar7;
        IoFreeIrp(lVar5);
      }
    }
    ExFreePoolWithTag(lVar4,0);
  }
  return iVar3;
}



===== ScsiPortStopAdapter @ 140027a44 =====

undefined8 ScsiPortStopAdapter(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined *puVar5;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  plVar1 = *(longlong **)(param_1 + 0x40);
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  if ((*(char *)((longlong)plVar1 + 9) == '\0') || (*(char *)((longlong)plVar1 + 10) == '\0')) {
    KeInitializeEvent(&local_28,1);
    *(undefined8 **)(param_2 + 0x38) = &local_28;
    IoStartPacket(param_1);
    plVar4 = (longlong *)0x0;
    puVar5 = (undefined *)0x0;
    KeWaitForSingleObject(&local_28);
    SpEnableDisableAdapter(plVar1,(char *)0x0,puVar5,plVar4);
    SpReleaseAdapterResources(plVar1,'\x01','\0');
    plVar4 = plVar1 + 0x5d;
    lVar3 = 8;
    do {
      for (lVar2 = *plVar4; lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 0x1a8)) {
        memset(*(void **)(lVar2 + 0x160),0,(ulonglong)*(uint *)((longlong)plVar1 + 0x264));
      }
      plVar4 = plVar4 + 2;
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
  }
  return 0;
}



===== SpRequestValidAdapterPowerStateSynchronous @ 140027b48 =====

undefined4 SpRequestValidAdapterPowerStateSynchronous(undefined8 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined4 local_10;
  
  ExAcquireFastMutex(param_1 + 0xe1);
  if (*(int *)(param_1 + 5) == 1) {
    uVar2 = 0;
    if (*(int *)((longlong)param_1 + 0x2c) != 1) {
      local_28 = 0;
      uStack_20 = 0;
      local_18 = 0;
      local_10 = 0;
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_q(WPP_GLOBAL_Control[3],0x31,&WPP_6575920e49f53cb538ed7e6ee78f4ac2_Traceguids,param_1
                );
      }
      KeInitializeEvent(&uStack_20,1);
      iVar1 = PoRequestPowerIrp(*param_1,2,1,SpSignalPowerCompletion,&local_28,0);
      if (iVar1 == 0x103) {
        KeWaitForSingleObject(&uStack_20,0,0,0,0);
      }
      uVar2 = (undefined4)local_28;
    }
  }
  else {
    uVar2 = 0xc0000001;
  }
  ExReleaseFastMutex(param_1 + 0xe1);
  return uVar2;
}



===== ScsiPortQueryProperty @ 140027c80 =====

undefined4 ScsiPortQueryProperty(longlong param_1,longlong param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *_Dst;
  undefined8 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint local_res8 [2];
  
  _Dst = *(uint **)(param_2 + 0x18);
  uVar1 = _Dst[1];
  uVar2 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  if (1 < (int)uVar1) {
    return 0xc00000ef;
  }
  uVar3 = *_Dst;
  uVar6 = 0;
  if (uVar3 == 0) {
LAB_140027d77:
    uVar5 = 0xc0000010;
  }
  else {
    local_res8[0] = uVar2;
    if (uVar3 == 1) {
      if (uVar1 != 1) {
        uVar4 = SpBuildAdapterDescriptor(*(longlong **)(param_1 + 0x40),_Dst,local_res8);
        *(ulonglong *)(param_2 + 0x38) = (ulonglong)local_res8[0];
        return (int)uVar4;
      }
    }
    else {
      if (uVar3 == 2) goto LAB_140027d77;
      if (uVar3 != 5) {
        return 0xc00000ef;
      }
      if (uVar1 != 1) {
        if (uVar2 < 8) {
          uVar5 = 0xc0000010;
        }
        else {
          uVar6 = 0x10;
          if (uVar2 < 0x10) {
            uVar5 = 0;
            *_Dst = 0x18;
            uVar6 = 8;
            _Dst[1] = 0x18;
          }
          else {
            memset(_Dst,0,(ulonglong)uVar2);
            _Dst[2] = 2;
            _Dst[3] = 0;
            if (0x17 < uVar2) {
              *(undefined1 *)(_Dst + 4) = 0;
              uVar6 = 0x18;
            }
            *_Dst = uVar6;
            uVar5 = 0;
            _Dst[1] = uVar6;
          }
        }
        *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar6;
        return uVar5;
      }
    }
    uVar5 = 0;
  }
  return uVar5;
}



===== ScsiPortQueryPropertyPdo @ 140027d98 =====

int ScsiPortQueryPropertyPdo(longlong param_1,longlong param_2)

{
  int *piVar1;
  longlong *plVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  uint local_res8 [2];
  
  piVar1 = *(int **)(param_2 + 0x18);
  iVar3 = 0;
  plVar2 = *(longlong **)(param_1 + 0x40);
  local_res8[0] = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  iVar4 = *piVar1;
  if (iVar4 == 0) {
    if (piVar1[1] == 1) goto LAB_140027e78;
    if (piVar1[1] != 0) {
LAB_140027e73:
      iVar3 = -0x3fffff11;
      goto LAB_140027e78;
    }
    uVar5 = SpBuildDeviceDescriptor(plVar2,piVar1,local_res8);
    iVar3 = (int)uVar5;
  }
  else {
    if ((iVar4 == 1) || (iVar4 != 2)) {
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      SpReleaseRemoveLock(param_1,(char)param_2);
      iVar4 = IofCallDriver(plVar2[2],param_2);
      return iVar4;
    }
    if (plVar2[0x1f9] == 0) {
      iVar3 = -0x3fffff45;
      goto LAB_140027e78;
    }
    if (piVar1[1] == 1) goto LAB_140027e78;
    if (piVar1[1] != 0) goto LAB_140027e73;
    uVar5 = SpBuildDeviceIdDescriptor((longlong)plVar2,piVar1,local_res8);
    iVar3 = (int)uVar5;
  }
  *(ulonglong *)(param_2 + 0x38) = (ulonglong)local_res8[0];
  if (iVar3 == 0x103) {
    return 0x103;
  }
LAB_140027e78:
  *(int *)(param_2 + 0x30) = iVar3;
  SpReleaseRemoveLock(param_1,(char)param_2);
  SpCompleteRequest(param_1,param_2,(undefined *)0x0,1);
  return iVar3;
}



===== SpBuildAdapterDescriptor @ 140027eb4 =====

undefined8 SpBuildAdapterDescriptor(longlong *param_1,void *param_2,uint *param_3)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  size_t _Size;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  undefined1 local_20;
  undefined1 local_1f;
  undefined2 local_1e;
  undefined4 local_1c;
  
  local_1f = 0;
  local_1c = 0;
  lVar2 = IoGetDriverObjectExtension(*(undefined8 *)(*param_1 + 8),ScsiPortInitialize);
  local_30 = (undefined4)param_1[0x7d];
  local_2c = *(undefined4 *)((longlong)param_1 + 0x3ec);
  local_20 = *(undefined1 *)(lVar2 + 0x24);
  local_28 = *(undefined4 *)((longlong)param_1 + 0x3f4);
  local_24 = *(undefined1 *)((longlong)param_1 + 0x3fa);
  local_23 = *(undefined1 *)((longlong)param_1 + 0x3f9);
  local_22 = (undefined1)param_1[0x7f];
  uVar1 = *param_3;
  local_38 = 0x20;
  _Size = (size_t)uVar1;
  local_34 = 0x20;
  local_21 = 1;
  local_1e = 2;
  if (0x1f < uVar1) {
    _Size = 0x20;
  }
  memcpy(param_2,&local_38,_Size);
  uVar3 = 0x20;
  if (uVar1 < 0x20) {
    uVar3 = uVar1;
  }
  *param_3 = uVar3;
  return 0;
}



===== SpBuildDeviceDescriptor @ 140027f90 =====

undefined8 SpBuildDeviceDescriptor(longlong *param_1,void *param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  ulonglong _Size;
  int iVar7;
  int iVar8;
  size_t _Size_00;
  uint uVar9;
  void *pvVar10;
  int iVar11;
  int local_res10;
  undefined4 local_68;
  int local_64;
  byte local_60;
  byte local_5f;
  byte local_5e;
  byte local_5d;
  undefined8 local_5c;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  
  lVar3 = IoGetDriverObjectExtension(*(undefined8 *)(*param_1 + 8));
  uVar6 = *param_3;
  _Size = (ulonglong)(int)uVar6;
  uVar9 = *(byte *)((longlong)param_1 + 0x1fe) + 5;
  iVar11 = 0;
  if (0x24 < uVar9) {
    uVar9 = 0x24;
  }
  local_res10 = uVar9 + 0x47;
  if (*(ushort *)(param_1 + 0x1f7) != 0) {
    iVar11 = *(ushort *)(param_1 + 0x1f7) + 1;
    local_res10 = local_res10 + iVar11;
  }
  memset(param_2,0,(ulonglong)uVar6);
  local_50 = 0xffffffff;
  local_5c = 0;
  local_54 = 0;
  local_48 = 0;
  local_64 = local_res10;
  local_60 = *(byte *)((longlong)param_1 + 0x1fa) & 0x1f;
  local_68 = 0x28;
  local_5f = *(byte *)((longlong)param_1 + 0x1fb) & 0x7f;
  local_5e = *(byte *)((longlong)param_1 + 0x1fb) >> 7;
  local_5d = *(byte *)((longlong)param_1 + 0x201) >> 1 & 1;
  if (0x28 < _Size) {
    _Size = 0x28;
  }
  local_4c = *(undefined4 *)(lVar3 + 0x24);
  memcpy(param_2,&local_68,_Size);
  uVar4 = uVar6 - 0x28;
  if (0 < (int)uVar4) {
    uVar1 = uVar9;
    if ((int)uVar4 <= (int)uVar9) {
      uVar1 = uVar4;
    }
    memcpy((void *)((longlong)param_2 + 0x28),(byte *)((longlong)param_1 + 0x1fa),
           (longlong)(int)uVar1);
    iVar7 = uVar4 - uVar9;
    if (iVar7 < 1) {
      *(uint *)((longlong)param_2 + 0x20) = uVar6 - 0x28;
    }
    else {
      *(uint *)((longlong)param_2 + 0x20) = uVar9;
      pvVar10 = (void *)((longlong)(int)(uVar6 - iVar7) + (longlong)param_2);
      _Size_00 = 8;
      if ((ulonglong)(longlong)iVar7 < 8) {
        _Size_00 = (longlong)iVar7;
      }
      memcpy(pvVar10,(void *)((longlong)param_1 + 0x202),_Size_00);
      iVar8 = iVar7 + -9;
      iVar5 = (int)param_2;
      if (-1 < iVar8) {
        *(int *)((longlong)param_2 + 0xc) = (int)pvVar10 - iVar5;
      }
      if (0 < iVar8) {
        pvVar10 = (void *)((longlong)(int)(uVar6 - iVar8) + (longlong)param_2);
        iVar2 = 0x10;
        if (iVar8 < 0x10) {
          iVar2 = iVar8;
        }
        memcpy(pvVar10,(void *)((longlong)param_1 + 0x20a),(longlong)iVar2);
        iVar8 = iVar7 + -0x1a;
        if (-1 < iVar8) {
          *(int *)((longlong)param_2 + 0x10) = (int)pvVar10 - iVar5;
        }
        if (0 < iVar8) {
          pvVar10 = (void *)((longlong)(int)(uVar6 - iVar8) + (longlong)param_2);
          iVar2 = 4;
          if (iVar8 < 4) {
            iVar2 = iVar8;
          }
          memcpy(pvVar10,(void *)((longlong)param_1 + 0x21a),(longlong)iVar2);
          iVar7 = iVar7 + -0x1f;
          if (-1 < iVar7) {
            *(int *)((longlong)param_2 + 0x14) = (int)pvVar10 - iVar5;
          }
          if (0 < iVar7) {
            pvVar10 = (void *)((longlong)(int)(uVar6 - iVar7) + (longlong)param_2);
            if ((short)param_1[0x1f7] != 0) {
              iVar8 = iVar7;
              if (iVar11 <= iVar7) {
                iVar8 = iVar11;
              }
              memcpy(pvVar10,(void *)param_1[0x1f8],(longlong)iVar8);
              iVar7 = iVar7 - iVar11;
              if (-1 < iVar7) {
                *(int *)((longlong)param_2 + 0x18) = (int)pvVar10 - iVar5;
              }
              if (iVar7 < 1) goto LAB_1400281a7;
            }
            uVar6 = uVar6 - iVar7;
          }
        }
      }
    }
  }
LAB_1400281a7:
  *param_3 = uVar6;
  return 0;
}



===== SpBuildDeviceIdDescriptor @ 1400281cc =====

undefined8 SpBuildDeviceIdDescriptor(longlong param_1,undefined4 *param_2,uint *param_3)

{
  byte bVar1;
  longlong lVar2;
  ushort uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  uint uVar6;
  ushort uVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  int iVar11;
  longlong lVar12;
  
  uVar6 = *param_3;
  lVar2 = *(longlong *)(param_1 + 0xfc8);
  iVar11 = 0;
  if (uVar6 < 8) {
    uVar4 = 0xc000000d;
  }
  else {
    memset(param_2,0,(ulonglong)uVar6);
    *param_2 = 0x10;
    puVar10 = param_2 + 3;
    param_2[1] = 0xc;
    uVar5 = Feature_851677496__private_IsEnabledDeviceUsageNoInline();
    uVar8 = 0;
    if ((int)uVar5 != 0) {
      uVar8 = *(uint *)(param_1 + 0xfd0) - 4;
      if (*(uint *)(param_1 + 0xfd0) < 5) {
        uVar8 = 0;
      }
      if (*(byte *)(lVar2 + 3) <= uVar8) {
        uVar8 = (uint)*(byte *)(lVar2 + 3);
      }
    }
    uVar9 = 0;
    if (*(char *)(lVar2 + 3) != '\0') {
      iVar11 = 0;
      do {
        uVar5 = Feature_851677496__private_IsEnabledDeviceUsageNoInline();
        if (((int)uVar5 != 0) && (uVar8 < uVar9 + 4)) break;
        lVar12 = (ulonglong)uVar9 + lVar2;
        uVar5 = Feature_851677496__private_IsEnabledDeviceUsageNoInline();
        if (((int)uVar5 != 0) && (uVar8 < *(byte *)(lVar12 + 7) + 4 + uVar9)) break;
        uVar7 = *(byte *)(lVar12 + 7) + 0x14 & 0xfffc;
        iVar11 = iVar11 + 1;
        param_2[1] = param_2[1] + (uint)uVar7;
        uVar9 = uVar9 + 4 + (uint)*(byte *)(lVar12 + 7);
        if ((uint)param_2[1] <= uVar6) {
          *puVar10 = *(byte *)(lVar12 + 4) & 0xf;
          puVar10[1] = *(byte *)(lVar12 + 5) & 0xf;
          puVar10[3] = *(byte *)(lVar12 + 5) >> 4 & 3;
          bVar1 = *(byte *)(lVar2 + 3);
          uVar3 = (ushort)*(byte *)(lVar12 + 7);
          if (bVar1 < uVar9) {
            uVar5 = (lVar12 - lVar2) + 8;
            if (bVar1 < uVar5) {
              uVar3 = 0;
            }
            else {
              uVar3 = (ushort)bVar1 - (short)uVar5;
            }
            uVar7 = uVar7 + (uVar3 - *(byte *)(lVar12 + 7));
          }
          *(ushort *)(puVar10 + 2) = uVar3;
          *(ushort *)((longlong)puVar10 + 10) = uVar7;
          if (uVar3 != 0) {
            memcpy(puVar10 + 4,(void *)(lVar12 + 8),(ulonglong)uVar3);
          }
          puVar10 = (uint *)((longlong)puVar10 + (ulonglong)*(ushort *)((longlong)puVar10 + 10));
        }
      } while (uVar9 < *(byte *)(lVar2 + 3));
    }
    uVar6 = *param_3;
    if (0xb < uVar6) {
      param_2[2] = iVar11;
    }
    if ((uint)param_2[1] < uVar6) {
      uVar6 = param_2[1];
    }
    uVar4 = 0;
    *param_3 = uVar6;
  }
  return uVar4;
}



===== SpQueryDeviceText @ 1400283a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SpQueryDeviceText(longlong param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  undefined8 *puVar1;
  longlong lVar2;
  byte bVar3;
  undefined8 uVar4;
  longlong lVar5;
  char *pcVar6;
  int iVar7;
  byte *pbVar8;
  undefined **ppuVar9;
  undefined1 auStack_178 [32];
  uint local_158;
  uint local_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined1 local_128 [8];
  undefined1 local_120 [2];
  undefined8 uStack_11e;
  byte abStack_116 [238];
  ulonglong local_28 [2];
  
  local_28[0] = __security_cookie ^ (ulonglong)auStack_178;
  lVar2 = *(longlong *)(param_1 + 0x40);
  local_138 = 0;
  uStack_130 = 0;
  local_148 = 0;
  uStack_140 = 0;
  RtlInitUnicodeString(&local_148);
  if (param_2 == 0) {
    bVar3 = *(byte *)(lVar2 + 0x1fa) & 0x1f;
    if (bVar3 < 0x12) {
      ppuVar9 = &DeviceTypeInfo + (ulonglong)bVar3 * 4;
    }
    else {
      ppuVar9 = &PTR_s_Other_140013320;
    }
    memset(local_120,0,0xf8);
    iVar7 = 8;
    local_128 = (undefined1  [8])*(undefined8 *)(lVar2 + 0x202);
    lVar5 = 8;
    do {
      if ((local_128[lVar5] & 0xdf) != 0) break;
      iVar7 = iVar7 + -1;
      local_128[lVar5] = 0;
      lVar5 = lVar5 + -1;
    } while (-1 < lVar5);
    lVar5 = (longlong)iVar7;
    iVar7 = 0x10;
    puVar1 = (undefined8 *)(local_128 + lVar5 + 2);
    local_128[lVar5 + 1] = 0x20;
    *(undefined1 *)puVar1 = 0;
    pbVar8 = abStack_116 + lVar5;
    uVar4 = *(undefined8 *)(lVar2 + 0x212);
    *puVar1 = *(undefined8 *)(lVar2 + 0x20a);
    *(undefined8 *)(local_120 + lVar5 + 2) = uVar4;
    do {
      if ((*pbVar8 & 0xdf) != 0) break;
      *pbVar8 = 0;
      iVar7 = iVar7 + -1;
      pbVar8 = pbVar8 + -1;
    } while (-1 < (longlong)pbVar8 - (longlong)puVar1);
    pcVar6 = (char *)((longlong)puVar1 + (longlong)(iVar7 + 1));
    RtlStringCbPrintfA(pcVar6,(longlong)local_28 - (longlong)pcVar6," SCSI %s Device",*ppuVar9);
  }
  else {
    if (param_2 != 1) {
      return 0xc00000bb;
    }
    local_150 = (uint)*(byte *)(lVar2 + 0x156);
    local_158 = (uint)*(byte *)(lVar2 + 0x155);
    RtlStringCbPrintfA(local_128,0x100,"Bus Number %d, Target ID %d, LUN %d",
                       (ulonglong)*(byte *)(lVar2 + 0x154));
  }
  RtlInitAnsiString(&local_138,local_128);
  uVar4 = RtlAnsiStringToUnicodeString(&local_148,&local_138,1);
  *param_4 = uStack_140;
  return uVar4;
}



===== SpAdapterCleanup @ 14002854c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SpAdapterCleanup(longlong param_1)

{
  longlong lVar1;
  wchar_t **ppwVar2;
  undefined1 auStack_d8 [32];
  wchar_t *local_b8 [4];
  wchar_t local_98 [64];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_d8;
  if (*(int *)(param_1 + 0x15c) != -1) {
    lVar1 = 2;
    local_b8[0] = L"\\Device\\ScsiPort%d";
    ppwVar2 = local_b8;
    local_b8[1] = L"\\DosDevices\\Scsi%d:";
    do {
      local_b8[2] = (wchar_t *)0x0;
      local_b8[3] = (wchar_t *)0x0;
      RtlStringCbPrintfW(local_98,0x80,*ppwVar2,(ulonglong)*(uint *)(param_1 + 0x15c));
      RtlInitUnicodeString(local_b8 + 2,local_98);
      IoDeleteSymbolicLink(local_b8 + 2);
      ppwVar2 = ppwVar2 + 1;
      lVar1 = lVar1 + -1;
    } while (lVar1 != 0);
    *(undefined4 *)(param_1 + 0x15c) = 0xffffffff;
    lVar1 = IoGetConfigurationInformation();
    *(int *)(lVar1 + 0x10) = *(int *)(lVar1 + 0x10) + -1;
  }
  return;
}



===== SpDeleteLogicalUnit @ 140028638 =====

void SpDeleteLogicalUnit(longlong *param_1)

{
  longlong lVar1;
  
  if ((*(byte *)(param_1 + 1) & 4) != 0) {
    IoWMIRegistrationControl(*param_1,2);
    *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) & 0xfb;
    lVar1 = *(longlong *)(*param_1 + 0x40);
    if (*(longlong *)(lVar1 + 0x40) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar1 + 0x40),0);
      *(undefined8 *)(lVar1 + 0x40) = 0;
    }
    *(undefined4 *)(lVar1 + 0x48) = 0;
  }
  if (param_1[0x1de] != 0) {
    IoFreeIrp();
    param_1[0x1de] = 0;
  }
  if (param_1[0x2c] != 0) {
    ExFreePoolWithTag(param_1[0x2c],0);
    param_1[0x2c] = 0;
  }
  if (param_1[0x1f8] != 0) {
    ExFreePoolWithTag(param_1[0x1f8],0);
    RtlInitAnsiString(param_1 + 0x1f7,0);
  }
  if (param_1[0x1f9] != 0) {
    ExFreePoolWithTag(param_1[0x1f9],0);
    param_1[0x1f9] = 0;
  }
  if (*(char *)((longlong)param_1 + 0x14e) != '\0') {
    *(undefined8 *)(param_1[0x2d] + 0x740) = 0;
  }
  IoDeleteDevice(*param_1);
  return;
}



===== SpReapChildren @ 140028758 =====

void SpReapChildren(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  longlong *plVar2;
  ulonglong uVar3;
  undefined7 uVar4;
  undefined8 *puVar5;
  longlong lVar6;
  
  uVar4 = (undefined7)((ulonglong)param_2 >> 8);
  puVar5 = (undefined8 *)(param_1 + 0x2e8);
  lVar1 = 8;
  do {
    while (lVar6 = lVar1, plVar2 = (longlong *)*puVar5, plVar2 != (longlong *)0x0) {
      *(undefined2 *)((longlong)plVar2 + 0x14a) = 0x100;
      SpRemoveLogicalUnit(plVar2,CONCAT71(uVar4,2));
      lVar1 = lVar6;
    }
    puVar5 = puVar5 + 2;
    lVar1 = lVar6 + -1;
  } while (lVar6 + -1 != 0);
  plVar2 = (longlong *)(param_1 + 0x7a8);
  uVar3 = (ulonglong)((int)lVar6 + 7);
  do {
    if (*plVar2 != 0) {
      *plVar2 = 0;
    }
    plVar2 = plVar2 + 1;
    uVar3 = uVar3 - 1;
  } while (uVar3 != 0);
  return;
}



===== SpRemoveLogicalUnit @ 1400287d4 =====

ulonglong SpRemoveLogicalUnit(longlong *param_1,undefined8 param_2)

{
  int *piVar1;
  ulonglong in_RAX;
  ulonglong extraout_RAX;
  ulonglong uVar2;
  char cVar3;
  char *pcVar4;
  
  cVar3 = (char)param_2;
  if (*(int *)((longlong)param_1 + 0xc) == 2) {
LAB_140028936:
    uVar2 = CONCAT71((int7)(in_RAX >> 8),1);
  }
  else {
    if (cVar3 == '\x02') {
      param_2 = 0xabcdabcd;
      in_RAX = SpWaitForRemoveLock(*param_1,0xcd);
      if ((char)param_1[0x29] != '\0') {
        *(undefined2 *)(param_1 + 0x29) = 0;
      }
    }
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (in_RAX = (ulonglong)*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c),
        (*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      pcVar4 = "surprise ";
      param_2 = 10;
      if (cVar3 != '\x17') {
        pcVar4 = "";
      }
      in_RAX = WPP_SF_sq(WPP_GLOBAL_Control[3],10,&WPP_0e590514a8bd32470b453596a0a5c27f_Traceguids,
                         pcVar4,(char)param_1);
    }
    if (cVar3 == '\x02') {
      if ((*(char *)((longlong)param_1 + 0x14b) == '\x01') &&
         (*(char *)((longlong)param_1 + 0x14a) == '\0')) {
LAB_1400288e5:
        *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) & 0xfd;
        SpDeleteDeviceMapEntry((longlong)param_1);
        in_RAX = SpFlushLogicalUnitRequests((longlong)param_1);
        if (cVar3 == '\x02') {
          *(undefined4 *)((longlong)param_1 + 0xc) = 2;
          in_RAX = SpRemoveLogicalUnitFromBin(param_1[0x2d],(longlong)param_1);
          *(undefined2 *)((longlong)param_1 + 0x154) = 0xffff;
          *(undefined1 *)((longlong)param_1 + 0x156) = 0xff;
          if (*(char *)((longlong)param_1 + 0x14e) == '\0') {
            in_RAX = SpDeleteLogicalUnit(param_1);
          }
        }
        goto LAB_140028936;
      }
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
         (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        param_2 = 0xb;
        WPP_SF_(WPP_GLOBAL_Control[3],0xb,&WPP_0e590514a8bd32470b453596a0a5c27f_Traceguids);
      }
      in_RAX = *param_1;
      LOCK();
      piVar1 = (int *)(*(longlong *)(in_RAX + 0x40) + 0x4c);
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      *(undefined4 *)((longlong)param_1 + 0xc) = 0;
      if ((int)param_1[0x2e] != 0) {
        SpLockUnlockQueue(*param_1,param_2);
        in_RAX = extraout_RAX;
      }
    }
    else if ((*(char *)((longlong)param_1 + 0x14c) != '\0') ||
            (*(char *)((longlong)param_1 + 0x14b) != '\0')) goto LAB_1400288e5;
    uVar2 = in_RAX & 0xffffffffffffff00;
  }
  return uVar2;
}



===== SpWaitForRemoveLock @ 140028950 =====

void SpWaitForRemoveLock(longlong param_1,undefined1 param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  *(undefined4 *)(lVar1 + 0xc) = 1;
  SpReleaseRemoveLock(param_1,param_2);
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) &&
     (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_D(WPP_GLOBAL_Control[3],0xc,&WPP_0e590514a8bd32470b453596a0a5c27f_Traceguids,
             *(undefined4 *)(lVar1 + 0x4c));
  }
  KeWaitForSingleObject(lVar1 + 0x50,0,0,0,0);
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) &&
     (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_q(WPP_GLOBAL_Control[3],0xd,&WPP_0e590514a8bd32470b453596a0a5c27f_Traceguids,param_1);
  }
  return;
}



===== RtlDuplicateCmResourceList @ 140028a18 =====

void * RtlDuplicateCmResourceList(undefined8 param_1,undefined8 param_2,uint *param_3)

{
  ulonglong uVar1;
  uint uVar2;
  void *_Dst;
  ulonglong _Size;
  uint *puVar3;
  uint uVar4;
  
  uVar4 = 0;
  _Size = 0x28;
  if (*param_3 != 0) {
    puVar3 = param_3 + 4;
    do {
      uVar2 = (uint)_Size + 0x24;
      if (uVar4 == 0) {
        uVar2 = (uint)_Size;
      }
      _Size = (ulonglong)uVar2;
      uVar2 = 0;
      if (*puVar3 != 0) {
        do {
          uVar1 = (ulonglong)((int)_Size + 0x14);
          if (uVar2 == 0) {
            uVar1 = _Size;
          }
          _Size = uVar1;
          uVar2 = uVar2 + 1;
        } while (uVar2 < *puVar3);
      }
      uVar4 = uVar4 + 1;
      puVar3 = puVar3 + 9;
    } while (uVar4 < *param_3);
  }
  _Dst = (void *)SpAllocatePoolEx(0,_Size,0x72506353,param_1,0x7574696c,0x210);
  if (_Dst != (void *)0x0) {
    memcpy(_Dst,param_3,_Size);
  }
  return _Dst;
}



===== ScsiPortStringArrayToMultiString @ 140028ac8 =====

undefined8 ScsiPortStringArrayToMultiString(undefined8 param_1,ulonglong *param_2,longlong *param_3)

{
  short sVar1;
  ushort uVar2;
  void *_Dst;
  undefined8 uVar3;
  longlong lVar4;
  ulonglong uVar5;
  byte bVar6;
  undefined8 local_28;
  ulonglong uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  local_28 = 0;
  uStack_20 = 0;
  RtlInitUnicodeString(param_2,0);
  bVar6 = 0;
  lVar4 = *param_3;
  while (lVar4 != 0) {
    RtlInitAnsiString(&local_18,lVar4);
    sVar1 = RtlxAnsiStringToUnicodeSize(&local_18);
    *(short *)param_2 = (short)*param_2 + sVar1;
    bVar6 = bVar6 + 1;
    lVar4 = param_3[bVar6];
  }
  uVar2 = (short)*param_2 + 2;
  *(ushort *)((longlong)param_2 + 2) = uVar2;
  _Dst = (void *)SpAllocatePoolEx(1,(ulonglong)uVar2,0x64506353,param_1,0x7574696c,0x169);
  param_2[1] = (ulonglong)_Dst;
  if (_Dst == (void *)0x0) {
    uVar3 = 0xc000009a;
  }
  else {
    memset(_Dst,0,(ulonglong)*(ushort *)((longlong)param_2 + 2));
    local_28 = *param_2;
    uStack_20 = param_2[1];
    bVar6 = 0;
    lVar4 = *param_3;
    while (uVar3 = 0, lVar4 != 0) {
      RtlInitAnsiString(&local_18,lVar4);
      RtlAnsiStringToUnicodeString(&local_28,&local_18,0);
      uVar5 = local_28 & 0xffff;
      sVar1 = local_28._2_2_ + (-2 - (short)local_28);
      local_28._0_4_ = CONCAT22(sVar1,(short)local_28);
      uStack_20 = uStack_20 + uVar5 + 2;
      bVar6 = bVar6 + 1;
      lVar4 = param_3[bVar6];
    }
  }
  return uVar3;
}



===== SpAllocateAddressMapping @ 140028c1c =====

longlong * SpAllocateAddressMapping(longlong *param_1)

{
  longlong *plVar1;
  
  plVar1 = (longlong *)param_1[0x4e];
  if (plVar1 == (longlong *)0x0) {
    plVar1 = (longlong *)
             SpAllocatePoolEx(0,0x28,0x6d506353,*(undefined8 *)(*param_1 + 8),0x7574696c,0x86e);
    if (plVar1 == (longlong *)0x0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_(WPP_GLOBAL_Control[3],0x1f,&WPP_433326d8495e374ced4cf2ffd30b12d2_Traceguids);
      }
      return (longlong *)0x0;
    }
  }
  else {
    param_1[0x4e] = *plVar1;
  }
  *plVar1 = 0;
  plVar1[1] = 0;
  plVar1[2] = 0;
  plVar1[3] = 0;
  plVar1[4] = 0;
  *plVar1 = param_1[0x4d];
  param_1[0x4d] = (longlong)plVar1;
  return plVar1;
}



===== SpCheckSpecialDeviceFlags @ 140028cd8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SpCheckSpecialDeviceFlags(longlong *param_1,byte *param_2)

{
  undefined8 uVar1;
  int iVar2;
  undefined1 auStackY_c8 [32];
  longlong local_98;
  longlong local_90;
  wchar_t local_88 [8];
  undefined8 local_78;
  longlong lStack_70;
  wchar_t *local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  ulonglong uStack_50;
  ulonglong local_48;
  longlong lStack_40;
  longlong local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_90 = 0;
  local_98 = 0;
  local_88[0] = L'\0';
  local_88[1] = L'\0';
  local_88[2] = L'\0';
  local_88[3] = L'\0';
  local_88[4] = L'\0';
  local_88[5] = L'\0';
  local_88[6] = L'\0';
  local_88[7] = L'\0';
  local_78 = 0;
  lStack_70 = 0;
  local_68 = (wchar_t *)0x0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = uStack_50 & 0xffffffff00000000;
  local_48 = 0;
  lStack_40 = 0;
  local_38 = 0;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_q(WPP_GLOBAL_Control[3],0xe,&WPP_433326d8495e374ced4cf2ffd30b12d2_Traceguids,param_1);
  }
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_(WPP_GLOBAL_Control[3],0xf,&WPP_433326d8495e374ced4cf2ffd30b12d2_Traceguids);
  }
  RtlInitUnicodeString
            (local_88,
             L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\ScsiPort\\SpecialTargetList"
            );
  local_78 = CONCAT44(local_78._4_4_,0x30);
  lStack_70 = 0;
  uStack_60 = CONCAT44(uStack_60._4_4_,0x240);
  local_68 = local_88;
  local_58 = 0;
  uStack_50 = 0;
  iVar2 = ZwOpenKey(&local_98,0x20019,&local_78);
  if (iVar2 < 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_LZ(WPP_GLOBAL_Control[3],0x10,&WPP_433326d8495e374ced4cf2ffd30b12d2_Traceguids,iVar2,
                local_88);
    }
  }
  else {
    SpProcessSpecialControllerList(*(undefined8 *)(*param_1 + 8),param_2,local_98,&local_48);
  }
  if (local_98 != 0) {
    ZwClose();
    local_98 = 0;
  }
  uVar1 = *(undefined8 *)(param_1[0x2d] + 0x140);
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_(WPP_GLOBAL_Control[3],0x11,&WPP_433326d8495e374ced4cf2ffd30b12d2_Traceguids);
  }
  iVar2 = IoOpenDeviceRegistryKey(uVar1,1,0x20019,&local_90);
  if (iVar2 < 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_D(WPP_GLOBAL_Control[3],0x12,&WPP_433326d8495e374ced4cf2ffd30b12d2_Traceguids,iVar2);
    }
  }
  else {
    RtlInitUnicodeString(local_88,L"ScsiPort\\SpecialTargetList");
    local_78 = CONCAT44(local_78._4_4_,0x30);
    lStack_70 = local_90;
    uStack_60 = CONCAT44(uStack_60._4_4_,0x240);
    local_68 = local_88;
    local_58 = 0;
    uStack_50 = 0;
    iVar2 = ZwOpenKey(&local_98,0x20019,&local_78);
    if (iVar2 < 0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_LZ(WPP_GLOBAL_Control[3],0x13,&WPP_433326d8495e374ced4cf2ffd30b12d2_Traceguids,iVar2,
                  local_88);
      }
    }
    else {
      SpProcessSpecialControllerList(*(undefined8 *)(*param_1 + 8),param_2,local_98,&local_48);
    }
  }
  if (local_90 != 0) {
    ZwClose();
    local_90 = 0;
    if (local_98 != 0) {
      ZwClose();
      local_98 = 0;
    }
  }
  iVar2 = IoOpenDeviceRegistryKey(*param_1,1,0x20019,&local_90);
  if (iVar2 < 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_D(WPP_GLOBAL_Control[3],0x14,&WPP_433326d8495e374ced4cf2ffd30b12d2_Traceguids,iVar2);
    }
  }
  else {
    RtlInitUnicodeString(local_88,L"ScsiPort\\SpecialTargetList");
    local_78 = CONCAT44(local_78._4_4_,0x30);
    lStack_70 = local_90;
    uStack_60 = CONCAT44(uStack_60._4_4_,0x240);
    local_68 = local_88;
    local_58 = 0;
    uStack_50 = 0;
    iVar2 = ZwOpenKey(&local_98,0x20019,&local_78);
    if (iVar2 < 0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_LZ(WPP_GLOBAL_Control[3],0x15,&WPP_433326d8495e374ced4cf2ffd30b12d2_Traceguids,iVar2,
                  local_88);
      }
    }
    else {
      SpProcessSpecialControllerFlags(local_98,(int *)&local_48);
    }
  }
  if (local_90 != 0) {
    ZwClose();
    local_90 = 0;
    if (local_98 != 0) {
      ZwClose();
    }
  }
  param_1[499] = local_48;
  param_1[500] = lStack_40;
  param_1[0x1f5] = local_38;
  return 0;
}



===== SpFreeMappedAddress @ 14002919c =====

ulonglong SpFreeMappedAddress(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 *in_RAX;
  
  puVar2 = (undefined8 *)(param_1 + 0x268);
  puVar3 = *(undefined8 **)(param_1 + 0x268);
  while( true ) {
    if (puVar3 == (undefined8 *)0x0) {
      return (ulonglong)in_RAX & 0xffffffffffffff00;
    }
    if (puVar3[1] == param_2) break;
    in_RAX = (undefined8 *)*puVar3;
    puVar2 = puVar3;
    puVar3 = in_RAX;
  }
  MmUnmapIoSpace(puVar3[1],*(undefined4 *)(puVar3 + 2));
  *puVar2 = *puVar3;
  uVar1 = *(undefined8 *)(param_1 + 0x270);
  *puVar3 = uVar1;
  *(undefined8 **)(param_1 + 0x270) = puVar3;
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== SpGetPdoInterfaceType @ 140029218 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SpGetPdoInterfaceType(undefined8 param_1)

{
  int iVar1;
  ulonglong uVar2;
  longlong *plVar3;
  undefined1 auStack_68 [32];
  int *local_48;
  int local_38;
  int local_34 [3];
  longlong local_28;
  longlong lStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_34[0] = 0;
  local_38 = -1;
  local_34[1] = 0;
  local_28 = 0;
  lStack_20 = 0;
  uVar2 = SpReadNumericInstanceValue(param_1,L"LegacyInterfaceType",local_34);
  if ((int)uVar2 < 0) {
    local_48 = local_34 + 1;
    iVar1 = IoGetDeviceProperty(param_1,0xc,0x10);
    if ((-1 < iVar1) && (uVar2 = 0, (int)SpGuidInterfaceMappingList[2] != -1)) {
      plVar3 = SpGuidInterfaceMappingList;
      do {
        if ((*plVar3 == local_28) && (plVar3[1] == lStack_20)) {
          local_38 = *(int *)((longlong)SpGuidInterfaceMappingList + uVar2 * 0x14 + 0x10);
          break;
        }
        uVar2 = (ulonglong)((int)uVar2 + 1);
        plVar3 = (longlong *)((longlong)SpGuidInterfaceMappingList + uVar2 * 0x14);
      } while ((int)plVar3[2] != -1);
    }
    if (local_38 == -1) {
      local_48 = local_34 + 1;
      iVar1 = IoGetDeviceProperty(param_1,0xd,4,&local_38);
      if ((-1 < iVar1) && (local_38 == 8)) {
        local_38 = 1;
      }
      if (local_38 == -1) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
           (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          WPP_SF_D(WPP_GLOBAL_Control[3],0x1e,&WPP_433326d8495e374ced4cf2ffd30b12d2_Traceguids,iVar1
                  );
        }
        local_38 = 1;
      }
    }
  }
  else {
    local_38 = local_34[0];
  }
  return local_38;
}



===== SpInitializeGuidInterfaceMapping @ 140029384 =====

undefined8 SpInitializeGuidInterfaceMapping(undefined8 param_1)

{
  undefined8 *_Dst;
  undefined8 uVar1;
  
  _Dst = (undefined8 *)SpAllocatePoolEx(1,100,0x54506353,param_1,0x7574696c,0x8a);
  SpGuidInterfaceMappingList = _Dst;
  if (_Dst == (undefined8 *)0x0) {
    uVar1 = 0xc000009a;
  }
  else {
    memset(_Dst,0,100);
    *(undefined4 *)(_Dst + 0xc) = 0xffffffff;
    *(undefined4 *)(_Dst + 2) = 1;
    uVar1 = 0;
    *_Dst = 0x11d0af9f09343630;
    _Dst[1] = 0x301b1ef80000e992;
    *(undefined4 *)((longlong)_Dst + 0x24) = 5;
    *(undefined4 *)(_Dst + 7) = 1;
    *(undefined8 *)((longlong)_Dst + 0x14) = 0x11d0b510c8ebdfb0;
    *(undefined8 *)((longlong)_Dst + 0x1c) = 0xe34225c9a000e580;
    *(undefined4 *)((longlong)_Dst + 0x4c) = 2;
    _Dst[5] = 0x11d0d87de676f854;
    _Dst[6] = 0xc55f05c9a000b292;
    *(undefined8 *)((longlong)_Dst + 0x3c) = 0x11d0f3fcddc35509;
    *(undefined8 *)((longlong)_Dst + 0x44) = 0xd13e75f8000037a5;
  }
  return uVar1;
}



===== SpMultiStringToStringArray @ 140029434 =====

undefined8 SpMultiStringToStringArray(undefined8 param_1,longlong param_2,undefined8 *param_3)

{
  longlong *plVar1;
  short sVar2;
  uint uVar3;
  void *_Dst;
  undefined8 uVar4;
  uint uVar5;
  short *psVar6;
  uint uVar7;
  size_t _Size;
  ulonglong uVar8;
  uint uVar9;
  
  plVar1 = (longlong *)(param_2 + 8);
  uVar3 = (uint)(*(ushort *)(param_2 + 2) >> 1);
  uVar7 = 0;
  if (uVar3 != 0) {
    psVar6 = (short *)*plVar1;
    uVar8 = (ulonglong)uVar3;
    do {
      sVar2 = *psVar6;
      psVar6 = psVar6 + 1;
      uVar3 = uVar7 + 1;
      if (sVar2 != 0) {
        uVar3 = uVar7;
      }
      uVar7 = uVar3;
      uVar8 = uVar8 - 1;
    } while (uVar8 != 0);
  }
  _Size = (ulonglong)(uVar7 + 1) << 3;
  _Dst = (void *)SpAllocatePoolEx(1,_Size,0x64506353,param_1,0x7574696c,0x1b3);
  if (_Dst == (void *)0x0) {
    uVar4 = 0xc000009a;
  }
  else {
    memset(_Dst,0,_Size);
    uVar3 = 0;
    uVar9 = 0;
    if (uVar7 != 0) {
      do {
        *(ulonglong *)((longlong)_Dst + (ulonglong)((uVar7 - uVar9) - 1) * 8) =
             *plVar1 + (ulonglong)uVar3 * 2;
        uVar5 = (uint)(*(ushort *)(param_2 + 2) >> 1);
        if (uVar3 < uVar5) {
          do {
            if (*(short *)(*plVar1 + (ulonglong)uVar3 * 2) == 0) break;
            uVar3 = uVar3 + 1;
          } while (uVar3 < uVar5);
        }
        uVar3 = uVar3 + 1;
        uVar9 = uVar9 + 1;
      } while (uVar9 < uVar7);
    }
    *param_3 = _Dst;
    uVar4 = 0;
  }
  return uVar4;
}



===== SpPreallocateAddressMapping @ 140029548 =====

undefined8 SpPreallocateAddressMapping(longlong *param_1)

{
  longlong *plVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    plVar1 = (longlong *)
             SpAllocatePoolEx(0,0x28,0x6d506353,*(undefined8 *)(*param_1 + 8),0x7574696c,0x8a5);
    if (plVar1 == (longlong *)0x0) {
      return 0;
    }
    *plVar1 = 0;
    plVar1[1] = 0;
    uVar2 = uVar2 + 1;
    plVar1[2] = 0;
    plVar1[3] = 0;
    plVar1[4] = 0;
    *plVar1 = param_1[0x4e];
    param_1[0x4e] = (longlong)plVar1;
  } while (uVar2 < 0x14);
  return CONCAT71((int7)((ulonglong)plVar1 >> 8),1);
}



===== SpProcessSpecialControllerFlags @ 1400295c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SpProcessSpecialControllerFlags(undefined8 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  char *pcVar13;
  undefined1 auStackY_228 [32];
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  undefined1 local_1c8 [8];
  undefined4 local_1c0;
  wchar_t *local_1b8;
  int *local_1b0;
  undefined4 local_188;
  wchar_t *local_180;
  int *local_178;
  undefined4 local_150;
  wchar_t *local_148;
  int *local_140;
  undefined4 local_118;
  wchar_t *local_110;
  int *local_108;
  undefined4 local_e0;
  wchar_t *local_d8;
  int *local_d0;
  undefined4 local_a8;
  wchar_t *local_a0;
  int *local_98;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_228;
  memset(local_1c8,0,0x188);
  local_1c0 = 0x20;
  local_1b8 = L"SparseLUN";
  local_188 = 0x20;
  local_180 = L"OneLUN";
  local_150 = 0x20;
  local_148 = L"LargeLuns";
  local_118 = 0x20;
  local_110 = L"SetLunInCdb";
  local_e0 = 0x20;
  local_d8 = L"NonStandardVPD";
  local_a8 = 0x20;
  local_a0 = L"BinarySN";
  local_1d8 = 0;
  uStack_1d0 = 0;
  local_1b0 = param_2;
  local_178 = param_2 + 1;
  local_140 = param_2 + 2;
  local_108 = param_2 + 3;
  local_d0 = param_2 + 4;
  local_98 = param_2 + 5;
  RtlInitUnicodeString(&local_1d8,L"RtlQueryRegistryValuesEx");
  pcVar6 = (code *)MmGetSystemRoutineAddress(&local_1d8);
  if (pcVar6 == (code *)0x0) {
    pcVar6 = RtlQueryRegistryValues_exref;
  }
  iVar5 = (*pcVar6)(0x40000000,param_1,local_1c8,0);
  if (iVar5 < 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_D(WPP_GLOBAL_Control[3],0x1a,&WPP_433326d8495e374ced4cf2ffd30b12d2_Traceguids,iVar5);
    }
  }
  else if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
          (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    pcVar11 = "";
    iVar5 = param_2[5];
    pcVar7 = "BinarySN";
    iVar1 = param_2[4];
    pcVar10 = "NonStandardVPD";
    iVar2 = param_2[3];
    pcVar12 = "SetLunInCdb";
    iVar3 = param_2[2];
    pcVar13 = "LargeLuns ";
    iVar4 = param_2[1];
    pcVar8 = "OneLun ";
    pcVar9 = "SparseLun ";
    if (iVar5 == 0) {
      pcVar7 = "";
    }
    if (iVar1 == 0) {
      pcVar10 = "";
    }
    if (iVar2 == 0) {
      pcVar12 = "";
    }
    if (iVar3 == 0) {
      pcVar13 = "";
    }
    if (iVar4 == 0) {
      pcVar8 = "";
    }
    if ((((*param_2 == 0) && (pcVar9 = "", iVar4 == 0)) &&
        ((iVar3 == 0 && ((iVar2 == 0 && (iVar1 == 0)))))) && (iVar5 == 0)) {
      pcVar11 = "none";
    }
    WPP_SF_sssssss(WPP_GLOBAL_Control[3],pcVar7,pcVar10,pcVar11,pcVar9,pcVar8,pcVar13,pcVar12,
                   pcVar10,pcVar7);
  }
  return;
}



===== SpProcessSpecialControllerList @ 140029864 =====

void SpProcessSpecialControllerList
               (undefined8 param_1,byte *param_2,undefined8 param_3,ulonglong *param_4)

{
  longlong *plVar1;
  wchar_t wVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  wchar_t *pwVar7;
  ulonglong *puVar8;
  longlong **pplVar9;
  longlong *local_88;
  ulonglong local_80 [2];
  wchar_t local_70 [8];
  longlong *local_60;
  undefined8 uStack_58;
  wchar_t *local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  ulonglong uStack_38;
  
  local_80[0] = 0;
  local_80[1] = 0;
  local_88 = (longlong *)0x0;
  puVar8 = param_4;
  RtlInitUnicodeString(local_80,0);
  uVar4 = ScsiPortGetHardwareIds(param_1,param_2,local_80,puVar8);
  if ((int)uVar4 < 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 8 & 1) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_D(WPP_GLOBAL_Control[3],0x16,&WPP_433326d8495e374ced4cf2ffd30b12d2_Traceguids,
               (int)uVar4);
    }
  }
  else {
    pplVar9 = &local_88;
    puVar8 = local_80;
    uVar5 = SpMultiStringToStringArray(param_1,(longlong)puVar8,pplVar9);
    plVar1 = local_88;
    if (-1 < (int)uVar5) {
      uVar4 = 0;
      if (*local_88 != 0) {
        pwVar7 = (wchar_t *)*local_88;
        do {
          local_88 = (longlong *)0x0;
          local_70[0] = L'\0';
          local_70[1] = L'\0';
          local_70[2] = L'\0';
          local_70[3] = L'\0';
          local_70[4] = L'\0';
          local_70[5] = L'\0';
          local_70[6] = L'\0';
          local_70[7] = L'\0';
          local_40 = 0;
          local_60 = (longlong *)0x0;
          uStack_58 = 0;
          uStack_38 = uStack_38 & 0xffffffff00000000;
          local_50 = (wchar_t *)0x0;
          uStack_48 = 0;
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 8 & 1) != 0)) &&
             (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_S(WPP_GLOBAL_Control[3],puVar8,pplVar9,pwVar7);
          }
          uVar6 = 0;
          if (*pwVar7 != L'\0') {
            wVar2 = *pwVar7;
            do {
              uVar6 = (ulonglong)((int)uVar6 + 1);
              if (wVar2 == L'\\') {
                pwVar7 = pwVar7 + uVar6;
                break;
              }
              wVar2 = pwVar7[uVar6];
            } while (wVar2 != L'\0');
          }
          RtlInitUnicodeString(local_70);
          if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 8 & 1) != 0)) &&
             (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
            WPP_SF_Zd(WPP_GLOBAL_Control[3],pwVar7,pplVar9,local_70,(char)uVar4);
          }
          local_50 = local_70;
          local_60 = (longlong *)CONCAT44(local_60._4_4_,0x30);
          pplVar9 = &local_60;
          puVar8 = (ulonglong *)0x20019;
          uStack_48 = CONCAT44(uStack_48._4_4_,0x240);
          local_40 = 0;
          uStack_38 = 0;
          uStack_58 = param_3;
          iVar3 = ZwOpenKey(&local_88);
          if (iVar3 < 0) {
            if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) >> 8 & 1) != 0)) &&
               (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
              pplVar9 = (longlong **)&WPP_433326d8495e374ced4cf2ffd30b12d2_Traceguids;
              puVar8 = (ulonglong *)0x19;
              WPP_SF_D(WPP_GLOBAL_Control[3],0x19,&WPP_433326d8495e374ced4cf2ffd30b12d2_Traceguids,
                       iVar3);
            }
          }
          else {
            puVar8 = param_4;
            SpProcessSpecialControllerFlags(local_88,(int *)param_4);
            ZwClose(local_88);
          }
          uVar4 = (ulonglong)((int)uVar4 + 1);
          pwVar7 = (wchar_t *)plVar1[uVar4];
        } while (pwVar7 != (wchar_t *)0x0);
      }
      ExFreePoolWithTag(plVar1,0);
    }
    RtlFreeUnicodeString(local_80);
  }
  return;
}



===== SpPurgeFreeMappedAddressList @ 140029ad4 =====

void SpPurgeFreeMappedAddressList(longlong param_1)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_1 + 0x270);
  while (puVar1 != (undefined8 *)0x0) {
    *(undefined8 *)(param_1 + 0x270) = *puVar1;
    ExFreePoolWithTag(puVar1,0);
    puVar1 = *(undefined8 **)(param_1 + 0x270);
  }
  return;
}



===== SpReadNumericInstanceValue @ 140029b18 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SpReadNumericInstanceValue(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  ulonglong uVar1;
  undefined4 uVar2;
  undefined1 auStack_d8 [32];
  undefined4 local_b8;
  uint *local_b0;
  uint local_a8;
  uint local_a4;
  longlong local_a0;
  longlong local_98;
  undefined8 local_90;
  longlong lStack_88;
  undefined8 *local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined1 local_40 [4];
  int local_3c;
  undefined4 local_34;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_d8;
  uVar2 = 0;
  local_a0 = 0;
  local_98 = 0;
  uVar1 = IoOpenDeviceRegistryKey(param_1,1,0x20019,&local_a0);
  if (-1 < (int)uVar1) {
    local_60 = 0;
    uStack_58 = 0;
    local_90 = 0;
    lStack_88 = 0;
    local_80 = (undefined8 *)0x0;
    uStack_78 = 0;
    local_70 = 0;
    uStack_68 = (ulonglong)uStack_68._4_4_ << 0x20;
    RtlInitUnicodeString(&local_60,L"Scsiport");
    local_90 = CONCAT44(local_90._4_4_,0x30);
    lStack_88 = local_a0;
    uStack_78 = CONCAT44(uStack_78._4_4_,0x240);
    local_80 = &local_60;
    local_70 = 0;
    uStack_68 = 0;
    local_a8 = ZwOpenKey(&local_98,0x20019,&local_90);
    uVar1 = (ulonglong)local_a8;
    if (-1 < (int)local_a8) {
      local_50 = 0;
      uStack_48 = 0;
      local_a4 = 0;
      RtlInitUnicodeString(&local_50,param_2);
      local_b0 = &local_a4;
      local_b8 = 0x14;
      local_a8 = ZwQueryValueKey(local_98,&local_50,2,local_40);
      uVar1 = (ulonglong)local_a8;
      if (-1 < (int)local_a8) {
        if ((local_3c == 4) && (3 < local_a4)) {
          uVar2 = local_34;
        }
        else {
          uVar1 = 0xc0000024;
          local_a8 = 0xc0000024;
        }
      }
    }
    if (local_a0 != 0) {
      ZwClose();
    }
    if (local_98 != 0) {
      ZwClose();
    }
    *param_3 = uVar2;
  }
  return uVar1;
}



===== SpReadNumericValue @ 140029ce4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
SpReadNumericValue(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 *local_40;
  undefined4 local_38 [2];
  undefined8 local_30;
  undefined8 uStack_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_20 = 0;
  local_40 = local_38;
  local_38[0] = 0;
  local_48 = 0x14;
  local_30 = 0;
  uStack_28 = 0;
  uVar1 = ZwQueryValueKey(0,param_3,2,&local_30);
  uVar2 = 0;
  if (-1 < (int)uVar1) {
    if (local_30._4_4_ == 4) {
      uVar2 = uStack_28._4_4_;
    }
    else {
      uVar1 = 0xc0000001;
    }
  }
  *param_4 = uVar2;
  return uVar1;
}



===== SpReleaseMappedAddresses @ 140029d78 =====

void SpReleaseMappedAddresses(longlong param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 0x268);
  while (lVar2 != 0) {
    SpFreeMappedAddress(param_1,*(longlong *)(lVar2 + 8));
    lVar2 = *(longlong *)(param_1 + 0x268);
  }
  while (puVar1 = *(undefined8 **)(param_1 + 0x270), puVar1 != (undefined8 *)0x0) {
    *(undefined8 *)(param_1 + 0x270) = *puVar1;
    ExFreePoolWithTag(puVar1,0);
  }
  return;
}



===== SpSendIrpSynchronous @ 140029dd8 =====

undefined4 SpSendIrpSynchronous(undefined8 param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeInitializeEvent(&local_28,1,0);
  puVar1 = *(undefined8 **)(param_2 + 0xb8);
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
  *(code **)(lVar2 + -0x10) = SpSignalCompletion;
  *(undefined8 **)(lVar2 + -8) = &local_28;
  *(undefined1 *)(lVar2 + -0x45) = 0xe0;
  IofCallDriver(param_1,param_2);
  KeWaitForSingleObject(&local_28,0,0,0,0);
  return *(undefined4 *)(param_2 + 0x30);
}



===== SpWriteNumericInstanceValue @ 140029ea0 =====

ulonglong SpWriteNumericInstanceValue(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  uint uVar1;
  ulonglong uVar2;
  undefined4 local_res18 [2];
  longlong local_res20;
  longlong local_68 [5];
  undefined8 local_40;
  longlong lStack_38;
  longlong *local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  
  local_res20 = 0;
  local_68[0] = 0;
  local_res18[0] = param_3;
  uVar2 = IoOpenDeviceRegistryKey(param_1,1,0x2001f,&local_res20);
  if (-1 < (int)uVar2) {
    local_68[1] = 0;
    local_68[2] = 0;
    local_40 = 0;
    lStack_38 = 0;
    local_30 = (longlong *)0x0;
    uStack_28 = 0;
    local_20 = 0;
    uStack_18 = (ulonglong)uStack_18._4_4_ << 0x20;
    RtlInitUnicodeString(local_68 + 1,L"Scsiport");
    local_40 = CONCAT44(local_40._4_4_,0x30);
    lStack_38 = local_res20;
    uStack_28 = CONCAT44(uStack_28._4_4_,0x240);
    local_30 = local_68 + 1;
    local_20 = 0;
    uStack_18 = 0;
    uVar1 = ZwCreateKey(local_68,0x2001f,&local_40,0,0,0,0);
    if (-1 < (int)uVar1) {
      local_68[3] = 0;
      local_68[4] = 0;
      RtlInitUnicodeString(local_68 + 3,param_2);
      uVar1 = ZwSetValueKey(local_68[0],local_68 + 3,0,4,local_res18,4);
    }
    uVar2 = (ulonglong)uVar1;
    if (local_res20 != 0) {
      ZwClose();
    }
    if (local_68[0] != 0) {
      ZwClose();
    }
  }
  return uVar2;
}



===== ScsiPortSystemControlIrp @ 14002a030 =====

int ScsiPortSystemControlIrp(longlong param_1,longlong param_2)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 *puVar4;
  int iVar5;
  uint uVar6;
  undefined8 local_28;
  undefined8 local_20;
  uint local_18;
  undefined4 local_14;
  undefined8 local_10;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  LOCK();
  *(int *)(lVar2 + 0x4c) = *(int *)(lVar2 + 0x4c) + 1;
  UNLOCK();
  if (*(int *)(lVar2 + 0xc) == 0) {
    lVar3 = *(longlong *)(param_2 + 0xb8);
    if (*(longlong *)(lVar3 + 8) == param_1) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_D(WPP_GLOBAL_Control[3],10,&WPP_23a3c04cde1b354a8276a948161bd449_Traceguids,
                 (uint)*(byte *)(lVar3 + 1));
      }
      local_28 = *(undefined8 *)(lVar3 + 8);
      local_20 = *(undefined8 *)(lVar3 + 0x10);
      local_10 = *(undefined8 *)(lVar3 + 0x20);
      local_18 = *(uint *)(lVar3 + 0x18);
      local_14 = *(undefined4 *)(lVar3 + 0x18);
      bVar1 = *(byte *)(lVar3 + 1);
      if (5 < bVar1) {
        if ((bVar1 == 6) || (bVar1 == 7)) {
LAB_14002a144:
          iVar5 = SpWmiIrpNormalRequest(param_1,bVar1,(longlong)&local_28);
        }
        else {
          if (bVar1 != 8) {
            if (bVar1 != 9) goto LAB_14002a106;
            goto LAB_14002a144;
          }
          iVar5 = SpWmiIrpRegisterRequest(param_1,(undefined *)&local_28);
        }
        *(int *)(param_2 + 0x30) = iVar5;
        uVar6 = 0;
        if (-1 < iVar5) {
          uVar6 = local_18;
        }
        *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar6;
        goto LAB_14002a163;
      }
      if (((bVar1 == 5) || (bVar1 == 0)) ||
         ((bVar1 == 1 || (((bVar1 == 2 || (bVar1 == 3)) || (bVar1 == 4)))))) goto LAB_14002a144;
    }
LAB_14002a106:
    SpReleaseRemoveLock(param_1,(char)param_2);
    if ((*(byte *)(lVar2 + 8) & 1) == 0) {
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
      iVar5 = IofCallDriver(*(undefined8 *)(lVar2 + 0x10));
      return iVar5;
    }
    iVar5 = *(int *)(param_2 + 0x30);
  }
  else {
    iVar5 = -0x3fffff40;
    *(undefined4 *)(param_2 + 0x30) = 0xc00000c0;
LAB_14002a163:
    SpReleaseRemoveLock(param_1,(char)param_2);
  }
  SpCompleteRequest(param_1,param_2,(undefined *)0x0,0);
  return iVar5;
}



===== SpAdapterConfiguredForSenseDataEvents @ 14002a1e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong SpAdapterConfiguredForSenseDataEvents(longlong param_1,undefined4 *param_2)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  code *pcVar4;
  undefined8 uVar5;
  longlong local_res8;
  undefined8 local_res10;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined8 local_a0;
  undefined8 *local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined1 local_78 [8];
  undefined4 local_70;
  wchar_t *local_68;
  undefined8 *local_60;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar3 = 0;
  local_res10 = 0;
  local_res8 = 0;
  local_8c = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_a4 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  if (((*(byte *)(lVar1 + 0x168) & 4) == 0) ||
     (uVar3 = IoOpenDeviceRegistryKey(*(undefined8 *)(lVar1 + 0x140),1,0xf003f,&local_res10),
     (int)uVar3 < 0)) {
    return uVar3 & 0xffffffffffffff00;
  }
  RtlInitUnicodeString(&local_c8,L"Scsiport");
  local_a0 = local_res10;
  local_98 = &local_c8;
  local_a8 = 0x30;
  local_90 = 0x240;
  local_88 = 0;
  uStack_80 = 0;
  iVar2 = ZwOpenKey(&local_res8,0x20019,&local_a8);
  if (-1 < iVar2) {
    uStack_d0 = 0;
    local_d8._0_4_ = CONCAT22(0x28,(undefined2)local_d8);
    memset(local_78,0,0x70);
    lVar1 = local_res8;
    local_68 = L"SenseDataEventClass";
    local_60 = &local_d8;
    local_70 = 0x24;
    local_b8 = 0;
    uStack_b0 = 0;
    RtlInitUnicodeString(&local_b8,L"RtlQueryRegistryValuesEx");
    pcVar4 = (code *)MmGetSystemRoutineAddress(&local_b8);
    if (pcVar4 == (code *)0x0) {
      pcVar4 = RtlQueryRegistryValues_exref;
    }
    iVar2 = (*pcVar4)(0xc0000000,lVar1,local_78,0,0);
    if (-1 < iVar2) {
      iVar2 = RtlGUIDFromString(&local_d8,param_2);
      ExFreePoolWithTag(uStack_d0,0);
    }
  }
  if (local_res8 != 0) {
    ZwClose();
  }
  uVar5 = ZwClose(local_res10);
  return CONCAT71((int7)((ulonglong)uVar5 >> 8),(byte)((uint)iVar2 >> 0x1f)) ^ 1;
}



===== SpInitAdapterWmiRegInfo @ 14002a3d0 =====

undefined8 SpInitAdapterWmiRegInfo(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar5 = 0x77506353;
  puVar4 = (undefined4 *)
           SpAllocatePoolEx(0,0xd0,0x77506353,*(undefined8 *)(param_1 + 8),0x776d6920,0x749);
  if (puVar4 == (undefined4 *)0x0) {
    uVar5 = 0xc000009a;
  }
  else {
    puVar4[1] = 0;
    *puVar4 = 0xd0;
    puVar4[2] = 0x38;
    puVar4[3] = 0xb4;
    *(undefined2 *)(puVar4 + 0xe) = 0x7a;
    builtin_wcsncpy((wchar_t *)((longlong)puVar4 + 0x3a),L"\\Reg",4);
    builtin_wcsncpy((wchar_t *)((longlong)puVar4 + 0x42),L"istr",4);
    builtin_wcsncpy((wchar_t *)((longlong)puVar4 + 0x4a),L"y\\Ma",4);
    builtin_wcsncpy((wchar_t *)((longlong)puVar4 + 0x52),L"chin",4);
    builtin_wcsncpy((wchar_t *)((longlong)puVar4 + 0x5a),L"e\\Sy",4);
    builtin_wcsncpy((wchar_t *)((longlong)puVar4 + 0x62),L"stem",4);
    builtin_wcsncpy((wchar_t *)((longlong)puVar4 + 0x6a),L"\\Cur",4);
    builtin_wcsncpy((wchar_t *)((longlong)puVar4 + 0x72),L"rent",4);
    builtin_wcsncpy((wchar_t *)((longlong)puVar4 + 0x7a),L"Cont",4);
    builtin_wcsncpy((wchar_t *)((longlong)puVar4 + 0x82),L"rolS",4);
    builtin_wcsncpy((wchar_t *)((longlong)puVar4 + 0x8a),L"et\\S",4);
    builtin_wcsncpy((wchar_t *)((longlong)puVar4 + 0x92),L"ervi",4);
    builtin_wcsncpy((wchar_t *)((longlong)puVar4 + 0x9a),L"ces\\",4);
    builtin_wcsncpy((wchar_t *)((longlong)puVar4 + 0xa2),L"Scsi",4);
    *(undefined8 *)((longlong)puVar4 + 0xaa) = 0x740072006f0050;
    *(undefined2 *)((longlong)puVar4 + 0xb2) = 0;
    *(undefined2 *)(puVar4 + 0x2d) = 0x18;
    builtin_wcsncpy((wchar_t *)((longlong)puVar4 + 0xb6),L"SCSI",4);
    builtin_wcsncpy((wchar_t *)((longlong)puVar4 + 0xbe),L"PORT",4);
    *(undefined8 *)((longlong)puVar4 + 0xc6) = 0x49004d0057;
    puVar4[4] = 1;
    uVar2 = *(undefined8 *)(lVar1 + 0x74c);
    uVar3 = *(undefined8 *)(lVar1 + 0x754);
    puVar4[10] = 0x60;
    puVar4[0xb] = 1;
    *(undefined8 *)(puVar4 + 6) = uVar2;
    *(undefined8 *)(puVar4 + 8) = uVar3;
    *(undefined8 *)(puVar4 + 0xc) = *(undefined8 *)(lVar1 + 0x140);
    *(undefined4 **)(lVar1 + 0x40) = puVar4;
    *(undefined4 *)(lVar1 + 0x48) = 0xd0;
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_qqD(WPP_GLOBAL_Control[3],WPP_GLOBAL_Control,uVar5,lVar1,(char)puVar4,0xd0);
    }
    uVar5 = 0;
  }
  return uVar5;
}



===== SpWmiDestroySpRegInfo @ 14002a544 =====

void SpWmiDestroySpRegInfo(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (*(longlong *)(lVar1 + 0x40) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0x40),0);
    *(undefined8 *)(lVar1 + 0x40) = 0;
  }
  *(undefined4 *)(lVar1 + 0x48) = 0;
  return;
}



===== SpWmiHandleOnMiniPortBehalf @ 14002a57c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 SpWmiHandleOnMiniPortBehalf(longlong param_1,byte param_2,longlong param_3)

{
  longlong lVar1;
  ulonglong *puVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined4 uVar6;
  undefined1 auStackY_e8 [32];
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_e8;
  lVar1 = *(longlong *)(param_1 + 0x40);
  if ((*(byte *)(lVar1 + 8) & 1) != 0) {
    return 0xc0000295;
  }
  puVar2 = *(ulonglong **)(param_3 + 8);
  local_50 = (undefined4)*puVar2;
  uStack_4c = *(undefined4 *)((longlong)puVar2 + 4);
  uVar4 = *puVar2;
  uStack_48 = (undefined4)puVar2[1];
  uStack_44 = *(undefined4 *)((longlong)puVar2 + 0xc);
  uVar3 = puVar2[1];
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_DDDDDDDDDDDD(WPP_GLOBAL_Control[3],uVar4 >> 0x20 & 0xffff,uVar4 >> 0x30,(uint)param_2,
                        (char)uVar4,(char)(uVar4 >> 0x20),(char)(uVar4 >> 0x30),(char)uVar3,
                        (char)(uVar3 >> 8),(char)(uVar3 >> 0x10),(char)(uVar3 >> 0x18),
                        (char)(uVar3 >> 0x20),(char)(uVar3 >> 0x28),(char)(uVar3 >> 0x30),
                        (char)(uVar3 >> 0x38));
  }
  lVar5 = RtlCompareMemory(&local_50,lVar1 + 0x74c,0x10);
  if (lVar5 != 0x10) {
    if ((undefined8 **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000295;
    }
    if ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x40) == 0) {
      return 0xc0000295;
    }
    if (*(byte *)((longlong)WPP_GLOBAL_Control + 0x29) < 4) {
      return 0xc0000295;
    }
    WPP_SF_(WPP_GLOBAL_Control[3],0x12,&WPP_23a3c04cde1b354a8276a948161bd449_Traceguids);
    return 0xc0000295;
  }
  if (param_2 < 6) {
    if (param_2 == 5) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_(WPP_GLOBAL_Control[3],0x14,&WPP_23a3c04cde1b354a8276a948161bd449_Traceguids);
      }
      *(undefined1 *)(lVar1 + 0x749) = 0;
    }
    else {
      if (((param_2 == 0) || (param_2 == 1)) ||
         ((param_2 == 2 || ((param_2 == 3 || (param_2 != 4)))))) goto LAB_14002a7e2;
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_(WPP_GLOBAL_Control[3],0x13,&WPP_23a3c04cde1b354a8276a948161bd449_Traceguids);
      }
      *(undefined1 *)(lVar1 + 0x749) = 1;
    }
    uVar6 = 0;
    *(undefined4 *)(param_3 + 0x10) = 0;
  }
  else {
LAB_14002a7e2:
    uVar6 = 0xc0000010;
  }
  return uVar6;
}



===== SpWmiInitializeFreeRequestList @ 14002a81c =====

undefined8 SpWmiInitializeFreeRequestList(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  
  plVar1 = *(longlong **)(param_1 + 0x40);
  if ((*(byte *)(plVar1 + 1) & 1) != 0) {
    plVar1 = (longlong *)plVar1[0x2d];
  }
  if ((char)plVar1[0x98] == '\0') {
    KeInitializeSpinLock(plVar1 + 0x96);
    InitializeSListHead((PSLIST_HEADER)(plVar1 + 0x94));
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_q(WPP_GLOBAL_Control[3],0x17,&WPP_23a3c04cde1b354a8276a948161bd449_Traceguids,plVar1);
    }
    plVar1[0x97] = 0;
    lVar2 = 2;
    *(undefined1 *)(plVar1 + 0x98) = 1;
    do {
      SpWmiPushFreeRequestItem(plVar1);
      lVar2 = lVar2 + -1;
    } while (lVar2 != 0);
    *(undefined4 *)(plVar1 + 0x97) = 2;
  }
  else {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_q(WPP_GLOBAL_Control[3],0x16,&WPP_23a3c04cde1b354a8276a948161bd449_Traceguids,plVar1);
    }
    LOCK();
    *(int *)(plVar1 + 0x97) = (int)plVar1[0x97] + 2;
    UNLOCK();
    while (*(uint *)((longlong)plVar1 + 0x4bc) < *(uint *)(plVar1 + 0x97)) {
      SpWmiPushFreeRequestItem(plVar1);
    }
  }
  return 0;
}



===== SpWmiInitializeSpRegInfo @ 14002a93c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SpWmiInitializeSpRegInfo(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  lVar1 = *(longlong *)(param_1 + 0x40);
  if ((*(byte *)(lVar1 + 8) & 1) == 0) {
    local_28 = 0;
    uStack_20 = 0;
    uVar2 = SpAdapterConfiguredForSenseDataEvents(param_1,(undefined4 *)&local_28);
    if ((char)uVar2 != '\0') {
      *(undefined8 *)(lVar1 + 0x74c) = local_28;
      *(undefined8 *)(lVar1 + 0x754) = uStack_20;
      SpInitAdapterWmiRegInfo(param_1);
    }
  }
  return;
}



===== SpWmiIrpNormalRequest @ 14002a9ac =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int SpWmiIrpNormalRequest(longlong param_1,byte param_2,longlong param_3)

{
  longlong lVar1;
  int iVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  iVar2 = SpWmiHandleOnMiniPortBehalf(param_1,param_2,param_3);
  if ((iVar2 == -0x3ffffd6b) && ((*(byte *)(lVar1 + 8) & 8) != 0)) {
    iVar2 = SpWmiPassToMiniPort(param_1,param_2,param_3);
    if (iVar2 < 0) {
      iVar2 = -0x3ffffff0;
    }
    else if (param_2 < 2) {
      *(undefined8 *)(*(longlong *)(param_3 + 0x18) + 0x10) = _DAT_fffff78000000014;
    }
  }
  return iVar2;
}



===== SpWmiIrpRegisterRequest @ 14002aa34 =====

int SpWmiIrpRegisterRequest(longlong param_1,undefined *param_2)

{
  bool bVar1;
  longlong lVar2;
  uint uVar3;
  longlong lVar4;
  int iVar5;
  ulonglong uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined *_Size;
  uint uVar10;
  uint *puVar11;
  undefined *local_res18;
  
  lVar4 = *(longlong *)(param_1 + 0x40);
  uVar8 = 0;
  iVar5 = 0;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qq(WPP_GLOBAL_Control[3],0xb,&WPP_23a3c04cde1b354a8276a948161bd449_Traceguids,param_1,
              (char)param_2);
  }
  if (*(int *)(param_2 + 8) == 0) {
    bVar1 = false;
  }
  else {
    if (*(int *)(param_2 + 8) != 1) {
      return -0x3ffffff3;
    }
    bVar1 = true;
  }
  lVar2 = IoGetDriverObjectExtension(*(undefined8 *)(param_1 + 8),ScsiPortInitialize);
  if (lVar2 == 0) {
    return -0x3fffffff;
  }
  local_res18 = *(undefined **)(*(longlong *)(param_1 + 0x40) + 0x40);
  if ((local_res18 == (undefined *)0x0) ||
     (uVar9 = *(uint *)(*(longlong *)(param_1 + 0x40) + 0x48), uVar9 == 0)) {
    local_res18 = (undefined *)0x0;
    uVar9 = 0;
  }
  _Size = local_res18;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    _Size = &WPP_23a3c04cde1b354a8276a948161bd449_Traceguids;
    WPP_SF_qd(WPP_GLOBAL_Control[3],0xc,&WPP_23a3c04cde1b354a8276a948161bd449_Traceguids,local_res18
              ,(char)uVar9);
  }
  if (((*(byte *)(lVar4 + 8) & 8) == 0) || ((*(byte *)(lVar4 + 8) & 0x11) == 0)) {
    if ((*(uint *)(param_2 + 0x10) < uVar9) && ((3 < *(uint *)(param_2 + 0x14) && (!bVar1)))) {
      **(uint **)(param_2 + 0x18) = uVar9;
      *(undefined4 *)(param_2 + 0x10) = 4;
      return 0;
    }
    uVar7 = 0;
LAB_14002ac5d:
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      _Size = &WPP_23a3c04cde1b354a8276a948161bd449_Traceguids;
      WPP_SF_(WPP_GLOBAL_Control[3],0xe,&WPP_23a3c04cde1b354a8276a948161bd449_Traceguids);
    }
    if (uVar7 != 0) {
      puVar11 = *(uint **)(param_2 + 0x18);
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
         (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_(WPP_GLOBAL_Control[3],0xf,&WPP_23a3c04cde1b354a8276a948161bd449_Traceguids);
      }
      *(undefined2 *)((ulonglong)uVar7 + *(longlong *)(param_2 + 0x18)) = *(undefined2 *)(lVar2 + 8)
      ;
      _Size = (undefined *)(ulonglong)*(ushort *)(lVar2 + 8);
      memcpy((void *)(*(longlong *)(param_2 + 0x18) + 2 + (ulonglong)uVar7),*(void **)(lVar2 + 0x10)
             ,(size_t)_Size);
      uVar10 = uVar7;
      if ((*(byte *)(lVar4 + 8) & 1) == 0) {
        param_1 = *(longlong *)(lVar4 + 0x140);
      }
      while( true ) {
        uVar3 = 0;
        puVar11[2] = uVar10;
        if (puVar11[4] != 0) {
          do {
            uVar6 = (ulonglong)uVar3;
            if ((puVar11[uVar6 * 8 + 10] & 0xc) != 0) {
              *(longlong *)(puVar11 + uVar6 * 8 + 0xc) = param_1;
              puVar11[uVar6 * 8 + 10] = puVar11[uVar6 * 8 + 10] & 0xfffffff3 | 0x20;
            }
            uVar3 = uVar3 + 1;
          } while (uVar3 < puVar11[4]);
        }
        uVar3 = puVar11[1];
        if (uVar3 == 0) break;
        uVar10 = uVar10 - uVar3;
        puVar11 = (uint *)((longlong)puVar11 + (ulonglong)uVar3);
      }
      uVar7 = uVar7 + uVar8;
      *puVar11 = uVar7;
    }
    if ((uVar9 != 0) && (!bVar1)) {
      uVar7 = uVar7 + 7 & 0xfffffff8;
      _Size = (undefined *)(ulonglong)uVar9;
      memcpy((void *)((ulonglong)uVar7 + *(longlong *)(param_2 + 0x18)),local_res18,(size_t)_Size);
      if (uVar7 != 0) {
        for (lVar4 = *(longlong *)(param_2 + 0x18); *(uint *)(lVar4 + 4) != 0;
            lVar4 = lVar4 + (ulonglong)*(uint *)(lVar4 + 4)) {
        }
        *(uint *)(lVar4 + 4) = (*(int *)(param_2 + 0x18) - (int)lVar4) + uVar7;
      }
      uVar7 = uVar7 + uVar9;
    }
  }
  else {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_(WPP_GLOBAL_Control[3],0xd,&WPP_23a3c04cde1b354a8276a948161bd449_Traceguids);
    }
    uVar7 = *(uint *)(param_2 + 0x10);
    if (uVar7 < 4) {
      return -0x3ffffff3;
    }
    uVar8 = *(ushort *)(lVar2 + 8) + 2;
    if ((uVar9 == 0) || (bVar1)) {
      if ((ulonglong)uVar7 <= (ulonglong)uVar8 + 4) goto LAB_14002abdc;
      iVar5 = uVar7 - uVar8;
    }
    else if ((ulonglong)(*(ushort *)(lVar2 + 8) + 9 + uVar9) + 4 < (ulonglong)uVar7) {
      iVar5 = ((uVar7 - uVar9) - uVar8) + -7;
    }
    else {
LAB_14002abdc:
      iVar5 = 4;
    }
    *(int *)(param_2 + 0x10) = iVar5;
    _Size = param_2;
    iVar5 = SpWmiPassToMiniPort(param_1,'\b',(longlong)param_2);
    uVar7 = *(uint *)(param_2 + 0x10);
    if (iVar5 != -0x3fffffdd) {
      if (iVar5 < 0) goto LAB_14002adaa;
      if (uVar7 != 4) goto LAB_14002ac5d;
    }
    if ((uVar9 != 0) && (!bVar1)) {
      **(int **)(param_2 + 0x18) = **(int **)(param_2 + 0x18) + uVar9;
      **(int **)(param_2 + 0x18) = **(int **)(param_2 + 0x18) + 7;
    }
    uVar7 = 4;
    **(int **)(param_2 + 0x18) = **(int **)(param_2 + 0x18) + uVar8;
    iVar5 = 0;
  }
LAB_14002adaa:
  *(uint *)(param_2 + 0x10) = uVar7;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_Dq(WPP_GLOBAL_Control[3],(ulonglong)*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c),_Size,
              iVar5,(char)param_2);
  }
  return iVar5;
}



===== SpWmiPassToMiniPort @ 14002adfc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SpWmiPassToMiniPort(longlong param_1,char param_2,longlong param_3)

{
  longlong *plVar1;
  longlong lVar2;
  void *_Dst;
  longlong lVar3;
  undefined8 uVar4;
  int iVar5;
  uint uVar6;
  undefined1 uVar7;
  longlong lVar8;
  undefined1 auStackY_128 [32];
  undefined8 local_e0;
  void *local_d8;
  longlong local_d0;
  longlong local_c8;
  longlong *local_c0;
  longlong local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined2 local_98;
  undefined1 local_96;
  char local_94;
  undefined1 local_93;
  undefined1 local_92;
  undefined1 local_91;
  undefined1 local_8f;
  undefined4 local_8c;
  undefined4 local_88;
  uint local_84;
  void *local_80;
  undefined8 local_78;
  longlong local_68;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  plVar1 = *(longlong **)(param_1 + 0x40);
  local_e0 = 0;
  local_c8 = param_3 + 3;
  memset(&local_98,0,0x58);
  uVar7 = (undefined1)(param_3 + 3);
  if ((*(byte *)(plVar1 + 1) & 1) == 0) {
    local_c0 = SpFindSafeLogicalUnit(param_1,0xff,uVar7);
    if (local_c0 == (longlong *)0x0) {
      return -0x3fffff40;
    }
    lVar8 = *(longlong *)(param_1 + 0x40);
    local_8f = 1;
    local_93 = *(undefined1 *)((longlong)local_c0 + 0x154);
    local_92 = *(undefined1 *)((longlong)local_c0 + 0x155);
    local_91 = *(undefined1 *)((longlong)local_c0 + 0x156);
  }
  else {
    LOCK();
    *(int *)((longlong)plVar1 + 0x4c) = *(int *)((longlong)plVar1 + 0x4c) + 1;
    UNLOCK();
    local_93 = *(undefined1 *)((longlong)plVar1 + 0x154);
    local_92 = *(undefined1 *)((longlong)plVar1 + 0x155);
    local_91 = *(undefined1 *)((longlong)plVar1 + 0x156);
    lVar8 = plVar1[0x2d];
    local_c0 = plVar1;
  }
  plVar1 = local_c0;
  uVar6 = *(uint *)(param_3 + 0x10);
  if ((param_2 == '\t') && (uVar6 <= **(uint **)(param_3 + 0x18))) {
    uVar6 = **(uint **)(param_3 + 0x18);
  }
  lVar3 = *(longlong *)(lVar8 + 0x1d0);
  local_d0 = lVar8;
  if (lVar3 == 0) {
    _Dst = (void *)SpAllocatePoolEx(0,(ulonglong)uVar6,0x63506353,*(undefined8 *)(param_1 + 8),
                                    0x776d6920,0x3db);
  }
  else {
    _Dst = (void *)(**(code **)(*(longlong *)(lVar3 + 8) + 0x10))(lVar3,uVar6,&local_e0,0);
  }
  local_d8 = _Dst;
  if (_Dst == (void *)0x0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
       (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_D(WPP_GLOBAL_Control[3],0x15,&WPP_23a3c04cde1b354a8276a948161bd449_Traceguids,uVar6);
    }
    SpReleaseRemoveLock(*plVar1,uVar7);
    return -0x3fffff66;
  }
  local_b0 = 0;
  uStack_a8 = 0;
  local_a0 = 0;
  memcpy(_Dst,*(void **)(param_3 + 0x18),(ulonglong)uVar6);
  local_88 = *(undefined4 *)(param_3 + 0x10);
  local_96 = 0x17;
  local_98 = 0x58;
  local_78 = *(undefined8 *)(param_3 + 8);
  local_8c = 0x140;
  local_84 = *(uint *)(lVar8 + 0x794);
  if (local_84 < 10) {
    local_84 = 10;
  }
  if (((param_2 == '\x02') || (param_2 == '\x03')) || (param_2 == '\t')) {
    local_8c = 0x1c0;
  }
  uVar4 = 0;
  local_94 = param_2;
  local_80 = _Dst;
  KeInitializeEvent(&local_b0,0,0);
  lVar3 = SpAllocateIrpEx(CONCAT71((int7)((ulonglong)*plVar1 >> 8),*(undefined1 *)(*plVar1 + 0x4c)),
                          uVar4,*(undefined8 *)(param_1 + 8),0x776d6920,0x41d);
  if (lVar3 != 0) {
    local_b8 = SpAllocateMdlEx();
    if (local_b8 != 0) {
      MmBuildMdlForNonPagedPool(local_b8);
      lVar2 = *(longlong *)(lVar3 + 0xb8);
      *(undefined1 *)(lVar2 + -0x48) = 0xf;
      *(undefined2 **)(lVar2 + -0x40) = &local_98;
      lVar2 = *(longlong *)(lVar3 + 0xb8);
      *(code **)(lVar2 + -0x10) = SpSignalCompletion;
      *(undefined8 **)(lVar2 + -8) = &local_b0;
      *(undefined1 *)(lVar2 + -0x45) = 0;
      *(undefined1 *)(lVar2 + -0x45) = 0x40;
      *(undefined1 *)(lVar2 + -0x45) = 0xc0;
      *(undefined1 *)(lVar2 + -0x45) = 0xe0;
      local_68 = lVar3;
      KeFlushIoBuffers(*(undefined8 *)(lVar3 + 8),0,1);
      IofCallDriver(*plVar1,lVar3);
      KeWaitForSingleObject(&local_b0,0,0,0);
      iVar5 = *(int *)(lVar3 + 0x30);
      if (-1 < iVar5) {
        *(undefined4 *)(param_3 + 0x10) = local_88;
      }
      memcpy(*(void **)(param_3 + 0x18),_Dst,(ulonglong)*(uint *)(param_3 + 0x10));
      IoFreeMdl(local_b8);
      IoFreeIrp(lVar3);
      goto LAB_14002b1ec;
    }
    IoFreeIrp(lVar3);
  }
  iVar5 = -0x3fffff66;
LAB_14002b1ec:
  lVar8 = *(longlong *)(lVar8 + 0x1d0);
  if (lVar8 == 0) {
    ExFreePoolWithTag(_Dst,0);
  }
  else {
    (**(code **)(*(longlong *)(lVar8 + 8) + 0x18))(lVar8,uVar6,local_e0,_Dst);
  }
  SpReleaseRemoveLock(*plVar1,(char)local_c8);
  return iVar5;
}



===== ScsiPortInitializeVrfy @ 14002b250 =====

ulonglong ScsiPortInitializeVrfy(longlong param_1,wchar_t *param_2,undefined *param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  
  if (VerifierApiCodeSectionHandle == 0) {
    VerifierApiCodeSectionHandle = MmLockPagableDataSection(ScsiPortGetSrbVrfy);
  }
  if ((param_1 == 0) || (param_2 == (wchar_t *)0x0)) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0xf1,0x1000,param_1,param_2,0);
  }
  uVar1 = ScsiPortInitialize(param_1,param_2,param_3);
  if (-1 < (int)uVar1) {
    lVar2 = IoGetDriverObjectExtension(param_1,ScsiPortInitialize);
    if (lVar2 != 0) {
      LOCK();
      *(undefined4 *)(lVar2 + 0x40) = 1;
      UNLOCK();
    }
  }
  return uVar1 & 0xffffffff;
}



===== SpDoVerifierInit @ 14002b31c =====

void SpDoVerifierInit(longlong *param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  void *_Dst;
  undefined8 uVar3;
  wchar_t *pwVar4;
  uint uVar5;
  uint local_res8 [4];
  undefined8 local_res18;
  undefined8 local_res20;
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
  
  local_3c = 0;
  local_res18 = 0;
  local_res20 = 0;
  uVar5 = 0;
  local_54 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_res8[0] = 0;
  lVar2 = IoGetDriverObjectExtension(*(undefined8 *)(*param_1 + 8),ScsiPortInitialize);
  if (lVar2 != 0) {
    local_50 = 0;
    local_48 = (undefined8 *)(lVar2 + 8);
    local_58 = 0x30;
    local_40 = 0x240;
    local_38 = 0;
    uStack_30 = 0;
    iVar1 = ZwOpenKey(&local_res20,0x20019,&local_58);
    if (-1 < iVar1) {
      RtlInitUnicodeString(&local_68,L"Parameters");
      local_50 = local_res20;
      local_48 = &local_68;
      local_58 = 0x30;
      local_40 = 0x240;
      local_38 = 0;
      uStack_30 = 0;
      iVar1 = ZwOpenKey(&local_res18,0x20019,&local_58);
      if (-1 < iVar1) {
        pwVar4 = L"VerifyLevel";
        RtlInitUnicodeString(&local_68);
        SpReadNumericValue(local_res18,pwVar4,&local_68,local_res8);
        ZwClose(local_res18);
        uVar5 = local_res8[0];
      }
      ZwClose();
    }
    if (uVar5 == 0xffffffff) {
      return;
    }
  }
  _Dst = (void *)SpAllocatePoolEx(0,0x78,0x66506353,*(undefined8 *)(*param_1 + 8),0x76667279,0xbc6);
  param_1[0xec] = (longlong)_Dst;
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,0x78);
    if (VerifierCodeSectionHandle == 0) {
      VerifierCodeSectionHandle = MmLockPagableDataSection(SpHwFindAdapterVrfy);
    }
    else {
      MmLockPagableSectionByHandle();
    }
    *(uint *)(param_1[0xec] + 100) = uVar5 | SpVrfyLevel;
    *(undefined8 *)param_1[0xec] = *(undefined8 *)(param_2 + 0x20);
    *(undefined8 *)(param_1[0xec] + 8) = *(undefined8 *)(param_2 + 8);
    *(undefined8 *)(param_1[0xec] + 0x10) = *(undefined8 *)(param_2 + 0x10);
    *(undefined8 *)(param_1[0xec] + 0x18) = *(undefined8 *)(param_2 + 0x18);
    *(undefined8 *)(param_1[0xec] + 0x20) = *(undefined8 *)(param_2 + 0x28);
    *(undefined8 *)(param_1[0xec] + 0x28) = *(undefined8 *)(param_2 + 0x30);
    *(undefined8 *)(param_1[0xec] + 0x40) = *(undefined8 *)(param_2 + 0x78);
    param_1[0x50] = (longlong)SpHwInitializeVrfy;
    param_1[0x4f] = (longlong)SpHwFindAdapterVrfy;
    param_1[0x51] = (longlong)SpHwStartIoVrfy;
    param_1[0x52] = (longlong)SpHwInterruptVrfy;
    param_1[0x53] = (longlong)SpHwResetBusVrfy;
    param_1[0x54] = (longlong)SpHwDmaStartedVrfy;
    param_1[0x57] = (longlong)SpHwAdapterControlVrfy;
    uVar3 = SpGetInaccessiblePage(param_1);
    *(undefined8 *)(param_1[0xec] + 0x68) = uVar3;
  }
  return;
}



===== SpVerifierInitialization @ 14002b5dc =====

bool SpVerifierInitialization(void)

{
  int iVar1;
  
  iVar1 = DifRegisterClassDriverPlugin(0x2a,&ScsiPortVerifierFunctionTable,0x100);
  if (-1 < iVar1) {
    KeQueryTimeIncrement();
  }
  return -1 < iVar1;
}



===== PortPassThroughBuildSrb @ 14002b624 =====

undefined4 * PortPassThroughBuildSrb(longlong param_1,undefined8 param_2,uint param_3)

{
  undefined4 *puVar1;
  longlong lVar2;
  
  lVar2 = 0;
  puVar1 = (undefined4 *)ExAllocatePool2(0x40,0x58,0x69506c50);
  if (puVar1 != (undefined4 *)0x0) {
    if ((*(char *)(param_1 + 7) != '\0') &&
       (lVar2 = ExAllocatePool2(0x48,*(char *)(param_1 + 7),0x69506c50), lVar2 == 0)) {
      ExFreePoolWithTag(puVar1,0x69506c50);
      return (undefined4 *)0x0;
    }
    PortPassThroughSrbInitialize(puVar1,param_1,param_3,param_2,lVar2);
  }
  return puVar1;
}



===== PortPassThroughSendAsync @ 14002b6e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PortPassThroughSendAsync
                    (longlong param_1,longlong param_2,char param_3,uint param_4,uint param_5,
                    uint param_6,undefined8 param_7,undefined8 param_8)

{
  longlong lVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined4 *puVar7;
  char *pcVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  undefined1 auStackY_118 [32];
  ushort local_b0 [4];
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
  local_b0[0] = 0;
  local_b0[1] = 0;
  local_b0[2] = 0;
  local_b0[3] = 0;
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
  uVar5 = PortPassThroughNormalize((undefined8 *)local_b0,param_2);
  uVar10 = uStack_98;
  uVar2 = uStack_a4;
  uVar4 = (uint)uVar5;
  if (-1 < (int)uVar4) {
    uVar5 = PortPassThroughValidateNormalizedRequest(local_b0,param_2,param_3);
    uVar4 = (uint)uVar5;
    if (-1 < (int)uVar4) {
      PortpPassThroughZeroUnusedBuffers(param_2);
      if (uVar2 == 0) {
        uVar9 = 0;
      }
      else if (param_3 == '\0') {
        uVar9 = *(longlong *)(param_2 + 0x18) + uVar10;
      }
      else {
        uVar9 = uVar10;
      }
      if (((uVar9 & *(uint *)(param_1 + 0x98)) != 0) ||
         ((uVar2 != 0 &&
          ((param_5 < (uint)((ulonglong)((uint)uVar9 & 0xfff) + (ulonglong)uVar2 + 0xfff >> 0xc) ||
           (param_6 < uVar2)))))) {
        uVar4 = 0xc000000d;
        goto LAB_14002b7b8;
      }
    }
  }
  if ((int)uVar4 < 0) goto LAB_14002b7b8;
  if (uVar2 == 0) {
    uVar10 = 0;
    if (param_3 != '\0') goto LAB_14002b863;
LAB_14002b828:
    cVar3 = '\0';
  }
  else {
    if (param_3 == '\0') {
      uVar10 = uVar10 + *(longlong *)(param_2 + 0x18);
      goto LAB_14002b828;
    }
LAB_14002b863:
    cVar3 = *(char *)(param_2 + 0x40);
  }
  lVar6 = PortPassThroughBuildIrpEx(param_1,uVar10,uVar2,(char)uStack_a8 != '\0',cVar3,param_2);
  if (lVar6 == 0) {
    uVar4 = 0xc000009a;
    goto LAB_14002b7b8;
  }
  puVar7 = PortPassThroughBuildSrb((longlong)local_b0,uVar10,param_4);
  if (puVar7 == (undefined4 *)0x0) {
LAB_14002b881:
    uVar4 = 0xc000009a;
  }
  else {
    *(undefined4 **)(*(longlong *)(lVar6 + 0xb8) + -0x40) = puVar7;
    *(longlong *)(puVar7 + 0xc) = lVar6;
    pcVar8 = (char *)ExAllocatePool2(0x40,0x30,0x69506c50);
    if (pcVar8 == (char *)0x0) goto LAB_14002b881;
    *pcVar8 = param_3;
    *(undefined4 **)(pcVar8 + 0x18) = puVar7;
    *(longlong *)(pcVar8 + 8) = lVar6;
    *(longlong *)(pcVar8 + 0x10) = param_2;
    *(code **)(pcVar8 + 0x20) = PortpSyncCompletion;
    *(undefined8 *)(pcVar8 + 0x28) = param_8;
    lVar1 = *(longlong *)(lVar6 + 0xb8);
    *(code **)(lVar1 + -0x10) = PortpAsyncCompletion;
    *(char **)(lVar1 + -8) = pcVar8;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    uVar10 = PortpEnableCancel(param_2,(longlong)pcVar8);
    uVar4 = (uint)uVar10;
    if (uVar4 == 0x103) {
      IofCallDriver(param_1,lVar6);
      return uVar10 & 0xffffffff;
    }
  }
  PortPassThroughFreeIrpEx(lVar6);
  if (puVar7 != (undefined4 *)0x0) {
    PortPassThroughFreeSrb((longlong)puVar7);
  }
  if (pcVar8 != (char *)0x0) {
    ExFreePoolWithTag(pcVar8,0x69506c50);
  }
LAB_14002b7b8:
  *(uint *)(param_2 + 0x30) = uVar4;
  PortpSyncCompletion(param_2,param_8);
  return (ulonglong)uVar4;
}



===== PortPassThroughSrbInitialize @ 14002b968 =====

void PortPassThroughSrbInitialize
               (undefined4 *param_1,longlong param_2,uint param_3,undefined8 param_4,
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
  param_1[3] = uVar2 | param_3 | 0x100;
  param_1[4] = *(undefined4 *)(param_2 + 0xc);
  uVar1 = *(undefined4 *)(param_2 + 0x10);
  *(longlong *)(param_1 + 8) = param_5;
  *(undefined8 *)(param_1 + 0xc) = 0;
  param_1[5] = uVar1;
  *(undefined8 *)(param_1 + 6) = param_4;
  memcpy(param_1 + 0x12,(void *)(param_2 + 0x24),(ulonglong)*(byte *)(param_2 + 6));
  return;
}



===== PortPassThroughValidateNormalizedRequest @ 14002ba44 =====

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
      if ((char)param_1[4] == '\0') goto LAB_14002bb10;
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
LAB_14002bb10:
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



===== PortTraceErrorFreeDriver @ 14002bb48 =====

void PortTraceErrorFreeDriver(longlong param_1)

{
  uint *puVar1;
  uint uVar2;
  ulonglong uVar3;
  
  LOCK();
  *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + -1;
  UNLOCK();
  puVar1 = (uint *)(param_1 + 0x50);
  if (*(longlong *)(param_1 + 0x38) != 0) {
    uVar3 = 0;
    if (*puVar1 != 0) {
      do {
        ExFreePoolWithTag(*(undefined8 *)(*(longlong *)(param_1 + 0x38) + uVar3 * 8),0);
        uVar2 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < *puVar1);
    }
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x38),0);
    *(undefined8 *)(param_1 + 0x38) = 0;
  }
  *puVar1 = 0;
  return;
}



===== PortTraceErrorRegisterDriver @ 14002bbbc =====

void PortTraceErrorRegisterDriver(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *(uint *)(param_2 + 0xc);
  uVar4 = 10;
  if ((10 < uVar3) || (uVar4 = uVar3, uVar3 != 0)) {
    lVar1 = ExAllocatePool2(0x40,uVar4 * 8,0x6c456c50);
    *(longlong *)(param_1 + 0x38) = lVar1;
    if (lVar1 != 0) {
      uVar3 = 0;
      if (uVar4 != 0) {
        lVar1 = 0;
        do {
          lVar2 = ExAllocatePool2(0x40,0x110,0x6c456c50);
          if (lVar2 == 0) break;
          uVar3 = uVar3 + 1;
          *(longlong *)(lVar1 + *(longlong *)(param_1 + 0x38)) = lVar2;
          lVar1 = lVar1 + 8;
        } while (uVar3 < uVar4);
      }
      *(uint *)(param_1 + 0x50) = uVar3;
    }
  }
  InitializeSListHead((PSLIST_HEADER)(param_1 + 0x40));
  *(undefined4 *)(param_1 + 0x54) = 0;
  LOCK();
  *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
  UNLOCK();
  PortpErrorInitDpc(param_1);
  return;
}



===== SpAllocateDriverExtension$fin$1 @ 14002bc89 =====

void SpAllocateDriverExtension_fin_1(undefined8 param_1,longlong param_2)

{
  int iVar1;
  
  if (*(longlong *)(param_2 + 0x38) == 0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_(WPP_GLOBAL_Control[3],0x60,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids);
    }
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_D(WPP_GLOBAL_Control[3],0x61,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,0x60);
    }
    iVar1 = IoAllocateDriverObjectExtension
                      (*(undefined8 *)(param_2 + 0xb0),ScsiPortInitialize,0x60,param_2 + 0x38);
    if (iVar1 < 0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_D(WPP_GLOBAL_Control[3],0x62,&WPP_7ee5018a90a038b19cfde90c53512c8d_Traceguids,iVar1);
      }
    }
    else {
      memset(*(void **)(param_2 + 0x38),0,0x60);
    }
  }
  else {
    *(undefined4 *)(*(longlong *)(param_2 + 0x38) + 0x24) = *(undefined4 *)(param_2 + 0x30);
  }
  return;
}



===== SpAllocateDriverExtension$fin$0 @ 14002bd95 =====

void SpAllocateDriverExtension_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x48) != 0) {
    ZwClose();
  }
  if (*(longlong *)(param_2 + 0x40) != 0) {
    ZwClose();
  }
  RtlFreeUnicodeString(param_2 + 0xb0);
  return;
}



===== SpSendReset$fin$0 @ 14002bdeb =====

void SpSendReset_fin_0(undefined8 param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  
  cVar1 = *(char *)(param_2 + 0x30);
  if (cVar1 != '\0') {
    if (*(longlong *)(param_2 + 0x38) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_2 + 0x38),0);
    }
    if (*(longlong *)(param_2 + 0x40) != 0) {
      IoFreeIrp();
    }
    lVar2 = *(longlong *)(param_2 + 0x88);
    *(undefined4 *)(lVar2 + 0x30) = *(undefined4 *)(param_2 + 0x34);
    if (*(longlong **)(param_2 + 0x48) != (longlong *)0x0) {
      SpReleaseRemoveLock(**(longlong **)(param_2 + 0x48),(char)lVar2);
    }
  }
  **(char **)(param_2 + 0x98) = cVar1;
  return;
}



===== ScsiPortGetHardwareIds$fin$0 @ 14002be60 =====

undefined8 ScsiPortGetHardwareIds_fin_0(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  uint uVar2;
  longlong *plVar3;
  
  uVar2 = 0;
  *(undefined4 *)(param_2 + 0x30) = 0;
  uVar1 = 0;
  plVar3 = (longlong *)(param_2 + 0x38);
  do {
    if (*plVar3 != 0) {
      uVar1 = ExFreePoolWithTag(*plVar3,0);
    }
    uVar2 = uVar2 + 1;
    plVar3 = plVar3 + 1;
  } while (uVar2 < 6);
  *(uint *)(param_2 + 0x30) = uVar2;
  return uVar1;
}



===== SpGetSlotNumber$fin$0 @ 14002beae =====

void SpGetSlotNumber_fin_0(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  
  if (*(int *)(param_2 + 0x30) < 0) {
    plVar1 = *(longlong **)(param_2 + 0x50);
    iVar3 = SpQueryCapabilities(plVar1);
    *(int *)(param_2 + 0x30) = iVar3;
    if (-1 < iVar3) {
      lVar2 = *(longlong *)(param_2 + 0x58);
      *(undefined4 *)(lVar2 + 4) = *(undefined4 *)(*(longlong *)(param_2 + 0x1a0) + 8);
      *(undefined4 *)(lVar2 + 100) = *(undefined4 *)((longlong)plVar1 + 0x16c);
      *(byte *)(plVar1 + 0x2d) = *(byte *)(plVar1 + 0x2d) | 2;
    }
  }
  if (*(longlong *)(param_2 + 0x40) != 0) {
    ZwClose();
  }
  if (*(longlong *)(param_2 + 0x48) != 0) {
    ZwClose();
  }
  return;
}



===== SpRequestValidAdapterPowerStateSynchronous$fin$0 @ 14002bf2c =====

void SpRequestValidAdapterPowerStateSynchronous_fin_0(undefined8 param_1,longlong param_2)

{
  ExReleaseFastMutex(*(longlong *)(param_2 + 0x60) + 0x708);
  return;
}



===== SpCheckSpecialDeviceFlags$fin$2 @ 14002bf5a =====

void SpCheckSpecialDeviceFlags_fin_2(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x30) != 0) {
    ZwClose();
  }
  return;
}



===== SpCheckSpecialDeviceFlags$fin$1 @ 14002bf80 =====

void SpCheckSpecialDeviceFlags_fin_1(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x38) != 0) {
    ZwClose();
    *(undefined8 *)(param_2 + 0x38) = 0;
    if (*(longlong *)(param_2 + 0x30) != 0) {
      ZwClose();
    }
  }
  return;
}



===== SpCheckSpecialDeviceFlags$fin$0 @ 14002bfc0 =====

void SpCheckSpecialDeviceFlags_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x38) != 0) {
    ZwClose();
    *(undefined8 *)(param_2 + 0x38) = 0;
    if (*(longlong *)(param_2 + 0x30) != 0) {
      ZwClose();
    }
  }
  return;
}



===== SpReadNumericInstanceValue$fin$0 @ 14002c006 =====

void SpReadNumericInstanceValue_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x38) != 0) {
    ZwClose();
  }
  if (*(longlong *)(param_2 + 0x40) != 0) {
    ZwClose();
  }
  return;
}



===== SpWriteNumericInstanceValue$fin$0 @ 14002c048 =====

void SpWriteNumericInstanceValue_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 200) != 0) {
    ZwClose();
  }
  if (*(longlong *)(param_2 + 0x40) != 0) {
    ZwClose();
  }
  return;
}



===== SpWmiPassToMiniPort$fin$0 @ 14002c08d =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SpWmiPassToMiniPort_fin_0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0x58);
  if (*(longlong *)(lVar1 + 0x1d0) == 0) {
    ExFreePoolWithTag(*(undefined8 *)(param_2 + 0x50),0);
  }
  else {
    (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 0x1d0) + 8) + 0x18))
              (*(undefined8 *)(lVar1 + 0x1d0),*(undefined4 *)(param_2 + 0x44),
               *(undefined8 *)(param_2 + 0x48),*(undefined8 *)(param_2 + 0x50),0);
  }
  SpReleaseRemoveLock(**(longlong **)(param_2 + 0x68),(char)*(undefined8 *)(param_2 + 0x60));
  return;
}



===== GetNextLuRequestWithoutLock @ 14002d010 =====

void GetNextLuRequestWithoutLock(longlong *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 uVar1;
  
  uVar1 = KfRaiseIrql(2);
  KeAcquireSpinLockAtDpcLevel(param_1[0x2d] + 0x1b0);
  GetNextLuRequest(param_1,param_2,param_3);
  KeLowerIrql(uVar1);
  return;
}



===== IssueReportLuns @ 14002d070 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int IssueReportLuns(longlong *param_1,undefined8 *param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uVar4;
  byte *pbVar5;
  longlong lVar6;
  byte *pbVar7;
  int iVar8;
  uint uVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  int iVar12;
  undefined *puVar13;
  ulonglong uVar14;
  bool bVar15;
  undefined1 auStackY_138 [32];
  uint local_f4;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined4 local_a8;
  undefined1 local_a4;
  undefined1 local_a3;
  byte local_a2;
  undefined1 local_a1;
  undefined2 local_9e;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  longlong local_90;
  longlong local_88;
  undefined8 local_80;
  longlong local_78;
  undefined1 local_60;
  undefined1 local_5a;
  undefined1 local_59;
  undefined1 local_58;
  undefined1 local_57;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_138;
  memset(&local_a8,0,0x58);
  local_b8 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  uVar14 = 0x10;
  lVar1 = *(longlong *)(param_1[0x2d] + 0x6f0);
  lVar2 = *(longlong *)(param_1[0x2d] + 0x6f8);
  KeInitializeEvent(&local_c8,1,0);
  local_f4 = 0;
  do {
    pbVar5 = (byte *)SpAllocatePoolEx(4,uVar14,0x78506353,*(undefined8 *)(*param_1 + 8),0x656e756d,
                                      0x23b);
    if (pbVar5 == (byte *)0x0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_(WPP_GLOBAL_Control[3],0xd,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids);
      }
      *param_2 = 0;
      return -0x3fffff66;
    }
    lVar6 = SpAllocateMdlEx();
    if (lVar6 == 0) {
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
         (1 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        WPP_SF_(WPP_GLOBAL_Control[3],0xe,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids);
      }
      *param_2 = 0;
      iVar12 = -0x3fffff66;
      goto LAB_14002d481;
    }
    MmBuildMdlForNonPagedPool(lVar6);
    iVar8 = 3;
    do {
      iVar8 = iVar8 + -1;
      IoInitializeIrp(lVar2,0x118,1);
      *(longlong *)(lVar2 + 8) = lVar6;
      lVar3 = *(longlong *)(lVar2 + 0xb8);
      memset(&local_a8,0,0x58);
      *(undefined4 **)(lVar3 + -0x40) = &local_a8;
      *(undefined2 *)(lVar3 + -0x48) = 0x10f;
      lVar3 = *(longlong *)(lVar2 + 0xb8);
      *(code **)(lVar3 + -0x10) = SpSignalCompletion;
      *(undefined8 **)(lVar3 + -8) = &local_c8;
      *(undefined1 *)(lVar3 + -0x45) = 0xe0;
      local_a3 = *(undefined1 *)((longlong)param_1 + 0x154);
      local_a2 = *(byte *)((longlong)param_1 + 0x155);
      local_a1 = *(undefined1 *)((longlong)param_1 + 0x156);
      local_a4 = 0;
      local_80 = 0;
      local_a8 = 0x58;
      local_9c = 0x48;
      local_94 = *(undefined4 *)(param_1[0x2d] + 0x794);
      local_9e = 0x120c;
      local_90 = (ulonglong)*(uint *)(*(longlong *)(lVar2 + 8) + 0x2c) +
                 *(longlong *)(*(longlong *)(lVar2 + 8) + 0x20);
      local_59 = (undefined1)(uVar14 >> 0x10);
      local_58 = (undefined1)(uVar14 >> 8);
      local_60 = 0xa0;
      local_5a = (undefined1)(uVar14 >> 0x18);
      local_57 = (undefined1)uVar14;
      local_98 = (int)uVar14;
      local_88 = lVar1;
      local_78 = lVar2;
      IofCallDriver(*param_1);
      puVar13 = (undefined *)0x0;
      KeWaitForSingleObject(&local_c8,0,0,0);
      uVar11 = (ulonglong)local_a8._3_1_;
      iVar12 = *(int *)(lVar2 + 0x30);
      if ((local_a8._3_1_ & 0x3f) == 1) {
        iVar12 = 0;
        break;
      }
      if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
         (2 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
        puVar13 = &WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids;
        uVar10 = 0;
        WPP_SF_D(WPP_GLOBAL_Control[3],0xf,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,
                 (uint)local_a8._3_1_);
        uVar11 = CONCAT71((int7)((ulonglong)uVar10 >> 8),local_a8._3_1_);
      }
      if ((uVar11 & 0x40) != 0) {
        if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0)) &&
           (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
          puVar13 = &WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids;
          uVar11 = 0x10;
          WPP_SF_D(WPP_GLOBAL_Control[3],0x10,&WPP_9e25629fc066359b9836f2f95a1352f3_Traceguids,
                   (uint)local_a2);
        }
        *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xfffffffe;
        uVar4 = KeAcquireSpinLockRaiseToDpc(param_1[0x2d] + 0x1b0);
        GetNextLuRequest(param_1,uVar11,puVar13);
        KeLowerIrql(uVar4);
        uVar11 = (ulonglong)local_a8._3_1_;
      }
      if (((char)uVar11 < '\0') && ((*(byte *)(lVar1 + 2) & 0xf) == 5)) {
        iVar12 = -0x3ffffff0;
        break;
      }
      if ((((uint)uVar11 & 0x3f) - 8 & 0xfffffffd) == 0) {
        iVar12 = -0x3ffffff2;
        break;
      }
    } while (iVar8 != 0);
    IoFreeMdl(lVar6);
    if (-1 < iVar12) {
      uVar9 = CONCAT31(CONCAT21(CONCAT11(*pbVar5,pbVar5[1]),pbVar5[2]),pbVar5[3]);
      if (0x20000 < (uVar9 & 0xfffffff8)) {
        uVar9 = 0x20000;
      }
      if ((ulonglong)uVar9 + 8 <= uVar14) goto LAB_14002d466;
      uVar14 = (ulonglong)(uVar9 + 8);
      ExFreePoolWithTag(pbVar5,0);
      pbVar5 = (byte *)0x0;
      iVar12 = -0x3ffffff0;
    }
    local_f4 = local_f4 + 1;
  } while (local_f4 < 2);
  if (iVar12 < 0) {
    *param_2 = 0;
    bVar15 = pbVar5 == (byte *)0x0;
  }
  else {
LAB_14002d466:
    pbVar7 = AdjustReportLuns(*(undefined8 *)(*param_1 + 8),pbVar5);
    *param_2 = pbVar7;
    bVar15 = pbVar7 == pbVar5;
  }
  if (!bVar15) {
LAB_14002d481:
    ExFreePoolWithTag(pbVar5,0);
  }
  return iVar12;
}



===== SpCountLogicalUnits @ 14002d560 =====

int SpCountLogicalUnits(longlong param_1)

{
  undefined1 uVar1;
  char cVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  int iVar7;
  longlong lVar8;
  
  iVar7 = 0;
  uVar3 = MmLockPagableDataSection(SpCountLogicalUnits);
  uVar1 = KfRaiseIrql(2);
  plVar6 = (longlong *)(param_1 + 0x2e8);
  lVar4 = param_1 + 0x2e0;
  lVar5 = 8;
  do {
    KeAcquireSpinLockAtDpcLevel(lVar4);
    for (lVar8 = *plVar6; lVar8 != 0; lVar8 = *(longlong *)(lVar8 + 0x1a8)) {
      if (*(char *)(lVar8 + 0x14b) == '\0') {
        cVar2 = SpIsInitiatorLU(lVar8);
        if (cVar2 == '\0') {
          iVar7 = iVar7 + 1;
        }
      }
    }
    KeReleaseSpinLockFromDpcLevel(lVar4);
    lVar4 = lVar4 + 0x10;
    plVar6 = plVar6 + 2;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  KeLowerIrql(uVar1);
  MmUnlockPagableImageSection(uVar3);
  return iVar7;
}



===== SpPurgeTarget @ 14002d64c =====

void SpPurgeTarget(longlong param_1,byte param_2,byte param_3)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong lVar7;
  
  uVar3 = KfRaiseIrql(2);
  plVar6 = (longlong *)(param_1 + 0x2e8);
  lVar5 = 8;
  lVar7 = param_1 + 0x2e0;
  do {
    KeAcquireSpinLockAtDpcLevel(lVar7);
    for (lVar4 = *plVar6; lVar4 != 0; lVar4 = *(longlong *)(lVar4 + 0x1a8)) {
      bVar1 = *(byte *)(lVar4 + 0x154);
      if (bVar1 == param_2) {
        bVar2 = *(byte *)(lVar4 + 0x155);
        if ((bVar2 == param_3) && (*(int *)(lVar4 + 0x150) == 1)) {
          if (((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 0x4000) != 0 &&
              (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))))) {
            WPP_SF_DDD(WPP_GLOBAL_Control[3],(ulonglong)bVar2,(ulonglong)bVar1,(uint)bVar1,bVar2,
                       *(undefined1 *)(lVar4 + 0x156));
          }
          *(undefined1 *)(lVar4 + 0x14b) = 1;
        }
      }
    }
    KeReleaseSpinLockFromDpcLevel(lVar7);
    lVar7 = lVar7 + 0x10;
    plVar6 = plVar6 + 2;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  KeLowerIrql(uVar3);
  return;
}



===== SpSetVerificationMarks @ 14002d774 =====

void SpSetVerificationMarks(longlong param_1,char param_2,char param_3)

{
  undefined1 uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  
  uVar1 = KfRaiseIrql(2);
  plVar5 = (longlong *)(param_1 + 0x2e8);
  lVar4 = 8;
  lVar3 = param_1 + 0x2e0;
  do {
    KeAcquireSpinLockAtDpcLevel(lVar3);
    for (lVar2 = *plVar5; lVar2 != 0; lVar2 = *(longlong *)(lVar2 + 0x1a8)) {
      if ((*(char *)(lVar2 + 0x154) == param_2) && (*(char *)(lVar2 + 0x155) == param_3)) {
        *(undefined4 *)(lVar2 + 0x150) = 1;
      }
    }
    KeReleaseSpinLockFromDpcLevel(lVar3);
    lVar3 = lVar3 + 0x10;
    plVar5 = plVar5 + 2;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  KeLowerIrql(uVar1);
  return;
}



===== SpInitializeSrbDataLookasideList @ 14002d850 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int SpInitializeSrbDataLookasideList(longlong param_1)

{
  longlong lVar1;
  void *pvVar2;
  uint uVar3;
  undefined1 uVar4;
  undefined8 uVar5;
  void *_Dst;
  ulonglong uVar6;
  bool bVar7;
  int local_res18;
  
  local_res18 = 0;
  uVar5 = MmLockPagableDataSection(SpInitializeSrbDataLookasideList);
  LOCK();
  _SpPAGELOCKLockCount = _SpPAGELOCKLockCount + 1;
  UNLOCK();
  uVar4 = KeAcquireSpinLockRaiseToDpc(&ScsiGlobalAdapterListSpinLock);
  uVar3 = ScsiGlobalAdapterListElements;
  uVar6 = (ulonglong)ScsiGlobalAdapterListElements;
  if (ScsiGlobalAdapterListElements + 1 != 0) {
    _Dst = (void *)SpAllocatePoolEx(0,(ulonglong)(ScsiGlobalAdapterListElements + 1) << 3,0x47506353
                                    ,*(undefined8 *)(param_1 + 8),0x696e6974,0x15c2);
    if (_Dst != (void *)0x0) {
      ScsiGlobalAdapterListElements = ScsiGlobalAdapterListElements + 1;
      if (ScsiGlobalAdapterList != (void *)0x0) {
        memcpy(_Dst,ScsiGlobalAdapterList,uVar6 << 3);
      }
      *(longlong *)((longlong)_Dst + uVar6 * 8) = param_1;
      pvVar2 = ScsiGlobalAdapterList;
      bVar7 = ScsiGlobalAdapterList != (void *)0x0;
      ScsiGlobalAdapterList = _Dst;
      if (bVar7) {
        ExFreePoolWithTag(pvVar2,0);
      }
      goto LAB_14002d946;
    }
  }
  local_res18 = -0x3fffff66;
LAB_14002d946:
  KeReleaseSpinLock(&ScsiGlobalAdapterListSpinLock,uVar4);
  MmUnlockPagableImageSection(uVar5);
  LOCK();
  _SpPAGELOCKLockCount = _SpPAGELOCKLockCount + -1;
  UNLOCK();
  if (-1 < local_res18) {
    lVar1 = *(longlong *)(param_1 + 0x40);
    ExInitializeNPagedLookasideList
              (lVar1 + 0x5c0,SpAllocateSrbDataBackend,SpFreeSrbDataBackend,0,0x310,uVar3,0x14);
    *(undefined1 *)(lVar1 + 0x660) = 1;
  }
  return local_res18;
}



===== SpClaimLogicalUnit @ 14002d9e0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int SpClaimLogicalUnit(longlong param_1,longlong *param_2,longlong param_3,char param_4)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  int iVar4;
  undefined8 uVar5;
  longlong lVar6;
  
  lVar1 = *(longlong *)(*(longlong *)(param_3 + 0xb8) + 8);
  if (param_4 != '\0') {
    iVar4 = ScsiPortStartLogicalUnit(param_2);
    if (iVar4 < 0) {
      *(undefined1 *)(lVar1 + 3) = 4;
      return iVar4;
    }
    *(undefined1 *)((longlong)param_2 + 0x149) = 1;
  }
  uVar5 = MmLockPagableDataSection(SpClaimLogicalUnit);
  LOCK();
  _SpPAGELOCKLockCount = _SpPAGELOCKLockCount + 1;
  UNLOCK();
  lVar6 = param_1 + 0x1b0;
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar6);
  if (*(char *)(lVar1 + 2) == '\x06') {
    *(undefined1 *)(param_2 + 0x29) = 0;
    KeReleaseSpinLock(lVar6);
    *(undefined1 *)(lVar1 + 3) = 1;
  }
  else {
    if ((char)param_2[0x29] != '\0') {
      KeReleaseSpinLock(lVar6);
      *(undefined1 *)(lVar1 + 3) = 5;
      return -0x7fffffef;
    }
    lVar2 = *param_2;
    if (*(char *)(lVar1 + 2) == '\x01') {
      *(undefined1 *)(param_2 + 0x29) = 1;
    }
    if (*(char *)(lVar1 + 2) == '\x05') {
      *param_2 = *(longlong *)(lVar1 + 0x18);
    }
    *(longlong *)(lVar1 + 0x18) = lVar2;
    KeReleaseSpinLock(lVar6,uVar3);
    *(undefined1 *)(lVar1 + 3) = 1;
    LOCK();
    _SpPAGELOCKLockCount = _SpPAGELOCKLockCount + -1;
    UNLOCK();
    MmUnlockPagableImageSection(uVar5);
  }
  return 0;
}



===== ScsiPortInitPnpAdapter @ 14002db10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int ScsiPortInitPnpAdapter(longlong param_1)

{
  longlong *plVar1;
  undefined1 uVar2;
  int iVar3;
  longlong lVar4;
  uint *puVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  void *_Dst;
  undefined8 *puVar9;
  uint uVar10;
  undefined4 uVar11;
  bool bVar12;
  undefined1 auStackY_168 [32];
  undefined1 local_138 [4];
  int local_134;
  undefined4 local_130;
  int local_12c;
  longlong *local_128;
  wchar_t *local_120;
  longlong local_118;
  wchar_t local_108 [8];
  longlong local_f8;
  void *local_f0;
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
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_168;
  plVar1 = *(longlong **)(param_1 + 0x40);
  local_128 = plVar1;
  local_118 = param_1;
  lVar4 = IoGetDriverObjectExtension(*(undefined8 *)(param_1 + 8),ScsiPortInitialize);
  local_138[0] = 0;
  uVar11 = 0;
  local_130 = 0;
  local_120 = (wchar_t *)(lVar4 + 8);
  local_134 = 0xc000000d;
  local_12c = SpGetPdoInterfaceType(plVar1[0x28]);
  puVar5 = (uint *)SpFindInitData(lVar4,local_12c);
  if (puVar5 == (uint *)0x0) {
    return -0x3ffffff2;
  }
  uVar10 = puVar5[0x10] + 8;
  if (uVar10 < 8) {
    return -0x3fffff66;
  }
  memset(local_108,0,200);
  if ((puVar5[0x13] != 0) &&
     (local_f0 = (void *)SpAllocatePoolEx(1,(ulonglong)puVar5[0x13] << 4,0x41506353,
                                          *(undefined8 *)(param_1 + 8),0x706e7020,0x800),
     local_f0 == (void *)0x0)) {
    return -0x3fffff66;
  }
  puVar6 = (undefined8 *)
           SpAllocatePoolEx(0,(ulonglong)uVar10,0x68506353,*(undefined8 *)(param_1 + 8),0x706e7020,
                            0x812);
  if (puVar6 == (undefined8 *)0x0) {
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_(WPP_GLOBAL_Control[3],0x17,&WPP_976cd3c5730d3f52f58c020cb0cc6bda_Traceguids);
    }
    uVar11 = 0x81a;
LAB_14002dc7b:
    iVar3 = -0x3fffff66;
    local_134 = -0x3fffff66;
    local_130 = uVar11;
  }
  else {
    memset(puVar6,0,(ulonglong)uVar10);
    SpInitializeAdapterExtension(plVar1,puVar5,puVar6);
    uVar7 = SpInitializeConfiguration(plVar1,local_120,(longlong)puVar5,local_108);
    iVar3 = (int)uVar7;
    local_134 = iVar3;
    if (iVar3 < 0) {
      uVar11 = 0x834;
      local_130 = 0x834;
      goto LAB_14002deee;
    }
    puVar6 = (undefined8 *)
             SpAllocatePoolEx(0,(ulonglong)(puVar5[0x13] * 0x10 + 0x98),0x50706353,
                              *(undefined8 *)(param_1 + 8),0x706e7020,0x846);
    if (puVar6 == (undefined8 *)0x0) {
      uVar11 = 0x84a;
      goto LAB_14002dc7b;
    }
    plVar1[0x3f] = (longlong)puVar6;
    *puVar6 = local_d8;
    puVar6[1] = uStack_d0;
    puVar6[2] = local_c8;
    puVar6[3] = uStack_c0;
    puVar6[4] = local_b8;
    puVar6[5] = uStack_b0;
    puVar6[6] = local_a8;
    puVar6[7] = uStack_a0;
    puVar6[8] = local_98;
    puVar6[9] = uStack_90;
    puVar6[10] = local_88;
    puVar6[0xb] = uStack_80;
    puVar6[0xc] = local_78;
    puVar6[0xd] = uStack_70;
    puVar6[0xe] = local_68;
    puVar6[0xf] = uStack_60;
    puVar6[0x10] = uStack_58;
    puVar6[0x11] = uStack_50;
    puVar6[0x12] = uStack_48;
    *(undefined4 *)((longlong)puVar6 + 0x8c) = *(undefined4 *)((longlong)plVar1 + 0x214);
    *(undefined4 *)(puVar6 + 0x11) = *(undefined4 *)((longlong)plVar1 + 0x264);
    if (puVar5[0x13] != 0) {
      puVar6[7] = puVar6 + 0x13;
      puVar6[7] = (longlong)puVar6 + 0x9fU;
      _Dst = (void *)((longlong)puVar6 + 0x9fU & 0xfffffffffffffff8);
      puVar6[7] = _Dst;
      memcpy(_Dst,local_f0,(ulonglong)puVar5[0x13] << 4);
    }
    *(int *)(puVar6 + 1) = local_12c;
    SpBuildConfiguration((longlong)plVar1,(longlong)puVar5,(longlong)puVar6);
    lVar4 = plVar1[0x40];
    puVar9 = puVar6;
    SpGetSlotNumber(param_1,(longlong)puVar6,lVar4);
    uVar8 = SpCallHwFindAdapter(param_1,puVar9,lVar4,(char *)local_108,(longlong)puVar6,local_138);
    iVar3 = (int)uVar8;
    local_134 = iVar3;
    if (iVar3 == -0x3fffff40) {
      plVar1[0x3f] = 0;
      ExFreePoolWithTag(puVar6,0);
    }
    else {
      if (iVar3 < 0) goto LAB_14002deee;
      uVar8 = SpAllocateAdapterResources(param_1);
      iVar3 = (int)uVar8;
      local_134 = iVar3;
      if (iVar3 < 0) goto LAB_14002deee;
      bVar12 = *(char *)(*(longlong *)(param_1 + 0x40) + 9) == '\x04';
      if (bVar12) {
        *(undefined4 *)((longlong)plVar1 + 0x184) = 0;
        *(uint *)(plVar1 + 0x6d) = *(uint *)(plVar1 + 0x6d) & 0xffffbfff;
      }
      iVar3 = SpCallHwInitialize(param_1);
      local_134 = iVar3;
      if (!bVar12) goto LAB_14002deee;
      uVar7 = MmLockPagableDataSection(ScsiPortInitPnpAdapter);
      uVar2 = KfRaiseIrql(2);
      IoStartNextPacket(param_1,0);
      KeLowerIrql(uVar2);
      MmUnlockPagableImageSection(uVar7);
    }
  }
LAB_14002deee:
  if (iVar3 < 0) {
    lVar4 = IoAllocateErrorLogEntry(param_1);
    if (lVar4 != 0) {
      *(undefined4 *)(lVar4 + 0xc) = 0xc0040004;
      *(undefined4 *)(lVar4 + 0x10) = uVar11;
      *(int *)(lVar4 + 0x14) = iVar3;
      *(undefined2 *)(lVar4 + 2) = 0;
      IoWriteErrorLogEntry(lVar4);
    }
    SpDestroyAdapter(plVar1,'\0');
    if (local_f0 != (void *)0x0) {
      ExFreePoolWithTag(local_f0,0);
    }
    if (local_f8 != 0) {
      ExFreePoolWithTag(local_f8,0);
    }
  }
  else {
    SpGetSupportedAdapterControlFunctions((longlong)plVar1);
  }
  return iVar3;
}



===== ScsiPortRemoveAdapter @ 14002dfb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ScsiPortRemoveAdapter(longlong param_1,longlong param_2,undefined *param_3,longlong *param_4)

{
  longlong *plVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  char cVar4;
  code *pcVar5;
  
  plVar1 = *(longlong **)(param_1 + 0x40);
  cVar4 = (char)param_2;
  if (cVar4 == '\0') {
    if (*(char *)((longlong)plVar1 + 9) != '\x17') {
      param_2 = param_1;
      SpWaitForRemoveLock(param_1,(char)param_1);
    }
    if ((*(char *)((longlong)plVar1 + 9) != '\x17') &&
       ((*(char *)((longlong)plVar1 + 9) == '\0' || (*(char *)((longlong)plVar1 + 10) == '\0')))) {
      SpEnableDisableAdapter(plVar1,(char *)0x0,param_3,param_4);
      uVar3 = MmLockPagableDataSection(ScsiPortRemoveAdapter);
      LOCK();
      _SpPAGELOCKLockCount = _SpPAGELOCKLockCount + 1;
      UNLOCK();
      uVar2 = KeAcquireSpinLockRaiseToDpc(plVar1 + 0x36);
      pcVar5 = SpRemoveAdapterSynchronized;
      (*(code *)plVar1[0x34])(plVar1[0x32],SpRemoveAdapterSynchronized,plVar1);
      param_2 = CONCAT71((int7)((ulonglong)pcVar5 >> 8),uVar2);
      KeReleaseSpinLock(plVar1 + 0x36);
      LOCK();
      _SpPAGELOCKLockCount = _SpPAGELOCKLockCount + -1;
      UNLOCK();
      MmUnlockPagableImageSection(uVar3);
    }
    SpReapChildren((longlong)plVar1,param_2);
  }
  if ((*(byte *)(plVar1 + 1) & 4) != 0) {
    IoWMIRegistrationControl(param_1,2);
    SpWmiRemoveFreeMiniPortRequestItems((longlong)plVar1);
    *(byte *)(plVar1 + 1) = *(byte *)(plVar1 + 1) & 0xeb;
  }
  SpDeleteDeviceMapEntry((longlong)plVar1);
  SpDestroyAdapter(plVar1,cVar4);
  return;
}



===== SpInitializeSrbDataLookasideList$fin$0 @ 14002e0e5 =====

void SpInitializeSrbDataLookasideList_fin_0(undefined8 param_1,longlong param_2)

{
  KeReleaseSpinLock(&ScsiGlobalAdapterListSpinLock,*(undefined1 *)(param_2 + 0x88));
  return;
}



===== ScsiPortInitPnpAdapter$fin$0 @ 14002e115 =====

void ScsiPortInitPnpAdapter_fin_0(undefined8 param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  
  iVar1 = *(int *)(param_2 + 0x34);
  if (iVar1 < 0) {
    lVar2 = IoAllocateErrorLogEntry(*(undefined8 *)(param_2 + 0x50));
    if (lVar2 != 0) {
      *(undefined4 *)(lVar2 + 0xc) = 0xc0040004;
      *(undefined4 *)(lVar2 + 0x10) = *(undefined4 *)(param_2 + 0x38);
      *(int *)(lVar2 + 0x14) = iVar1;
      *(undefined2 *)(lVar2 + 2) = 0;
      IoWriteErrorLogEntry(lVar2);
    }
    SpDestroyAdapter(*(longlong **)(param_2 + 0x40),'\0');
    if (*(longlong *)(param_2 + 0x78) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_2 + 0x78),0);
    }
    if (*(longlong *)(param_2 + 0x70) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_2 + 0x70),0);
    }
  }
  else {
    SpGetSupportedAdapterControlFunctions(*(longlong *)(param_2 + 0x40));
  }
  return;
}



===== ScsiPortCompleteRequestVrfy @ 14002f010 =====

void ScsiPortCompleteRequestVrfy
               (longlong param_1,char param_2,char param_3,longlong *param_4,undefined1 param_5)

{
  ScsiPortCompleteRequest(param_1,param_2,param_3,param_4,param_5);
  return;
}



===== ScsiPortFlushDmaVrfy @ 14002f030 =====

void ScsiPortFlushDmaVrfy(longlong param_1)

{
  ScsiPortFlushDma(param_1);
  return;
}



===== ScsiPortFreeDeviceBaseVrfy @ 14002f050 =====

void ScsiPortFreeDeviceBaseVrfy(longlong param_1,longlong param_2)

{
  ScsiPortFreeDeviceBase(param_1,param_2);
  return;
}



===== ScsiPortGetBusDataVrfy @ 14002f070 =====

void ScsiPortGetBusDataVrfy
               (longlong param_1,int param_2,ulonglong param_3,undefined8 param_4,longlong *param_5,
               uint param_6)

{
  if (param_2 != 4) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0xf1,0x1008,param_2,param_1,param_3 & 0xffffffff);
  }
  ScsiPortGetBusData(param_1,4,param_3,param_4,param_5,param_6);
  return;
}



===== ScsiPortGetDeviceBaseVrfy @ 14002f0d0 =====

void ScsiPortGetDeviceBaseVrfy
               (longlong param_1,uint param_2,uint param_3,undefined1 *param_4,uint param_5,
               byte param_6)

{
  ScsiPortGetDeviceBase(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}



===== ScsiPortGetLogicalUnitVrfy @ 14002f100 =====

void ScsiPortGetLogicalUnitVrfy(longlong param_1,char param_2,undefined *param_3,byte param_4)

{
  ScsiPortGetLogicalUnit(param_1,param_2,param_3,param_4);
  return;
}



===== ScsiPortGetPhysicalAddressVrfy @ 14002f120 =====

longlong ScsiPortGetPhysicalAddressVrfy
                   (longlong param_1,longlong param_2,ulonglong param_3,int *param_4)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  int iVar8;
  uint uVar9;
  ulonglong uVar10;
  uint uVar11;
  
  lVar5 = *(longlong *)(param_1 + -8);
  uVar11 = 0;
  lVar2 = *(longlong *)(lVar5 + 0x760);
  if (((lVar2 == 0) || ((*(uint *)(lVar2 + 100) & 1) == 0)) ||
     ((param_2 != 0 &&
      ((*(ulonglong *)(param_2 + 0x20) == 0 || (*(ulonglong *)(param_2 + 0x20) != param_3)))))) {
    lVar5 = ScsiPortGetPhysicalAddress(param_1,param_2,param_3,param_4);
  }
  else {
    uVar1 = *(uint *)(lVar5 + 0x220);
    uVar6 = 0;
    uVar10 = 0;
    iVar8 = (int)param_3;
    if (uVar1 != 0) {
      uVar7 = (ulonglong)(*(int *)(lVar5 + 0x210) - 0x1000);
      do {
        uVar3 = *(ulonglong *)(*(longlong *)(lVar2 + 0x50) + uVar10 * 8);
        uVar6 = *(ulonglong *)(uVar3 + 0x18 + uVar7);
        uVar4 = uVar3;
        if (uVar6 != 0) {
          uVar4 = uVar6;
        }
        uVar6 = (ulonglong)*(uint *)(lVar5 + 0x214) + 0xfff + uVar4 & 0xfffffffffffff000;
        if ((uVar4 <= param_3) && (param_3 < uVar6)) {
          uVar11 = iVar8 - (int)uVar4;
          break;
        }
        if (*(char *)(lVar5 + 0x48c) == '\x01') {
          uVar4 = *(ulonglong *)(uVar3 + 0x38 + uVar7);
          if (uVar4 == 0) {
            uVar4 = ((ulonglong)*(uint *)(lVar5 + 0x214) + 0xfff & 0xfffffffffffff000) + uVar3;
          }
          uVar6 = uVar4 + 0x1000;
          if ((uVar4 <= param_3) && (param_3 < uVar6)) {
            uVar11 = ((*(int *)(lVar5 + 0x214) + 0xfffU & 0xfffff000) - (int)uVar4) + iVar8;
            break;
          }
        }
        uVar9 = (int)uVar10 + 1;
        uVar10 = (ulonglong)uVar9;
      } while (uVar9 < uVar1);
    }
    if ((uint)uVar10 == uVar1) {
      uVar11 = *(uint *)(*(longlong *)(lVar5 + 0x760) + 0x60);
      if (uVar11 == 0) {
LAB_14002f28b:
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0xf1,0x1006,param_1,param_3,0);
      }
      uVar7 = *(ulonglong *)(*(longlong *)(lVar2 + 0x50) + uVar10 * 8);
      uVar6 = (ulonglong)uVar11 + 0xfff + uVar7 & 0xfffffffffffff000;
      if ((param_3 < uVar7) || (uVar6 <= param_3)) goto LAB_14002f28b;
      uVar11 = iVar8 - (int)uVar7;
    }
    lVar5 = (ulonglong)uVar11 +
            *(longlong *)(*(longlong *)(*(longlong *)(lVar5 + 0x760) + 0x58) + uVar10 * 8);
    *param_4 = ((int)uVar6 - iVar8) + 1;
  }
  return lVar5;
}



===== ScsiPortGetSrbVrfy @ 14002f2e0 =====

void ScsiPortGetSrbVrfy(longlong param_1,char param_2,uint param_3,byte param_4,char param_5)

{
  ScsiPortGetSrb(param_1,param_2,param_3,param_4,param_5);
  return;
}



===== ScsiPortGetUncachedExtensionVrfy @ 14002f300 =====

void ScsiPortGetUncachedExtensionVrfy(longlong param_1,longlong param_2,int param_3)

{
  ScsiPortGetUncachedExtension(param_1,param_2,param_3);
  return;
}



===== ScsiPortGetVirtualAddressVrfy @ 14002f320 =====

ulonglong ScsiPortGetVirtualAddressVrfy(longlong param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  longlong lVar5;
  ulonglong uVar6;
  
  lVar5 = *(longlong *)(param_1 + -8);
  lVar3 = *(longlong *)(lVar5 + 0x760);
  if ((lVar3 == 0) || ((*(uint *)(lVar3 + 100) & 1) == 0)) {
    uVar6 = ScsiPortGetVirtualAddress(param_1,param_2);
  }
  else {
    uVar6 = 0;
    if (*(uint *)(lVar5 + 0x220) != 0) {
      do {
        uVar2 = *(uint *)(*(longlong *)(lVar3 + 0x58) + uVar6 * 8);
        if ((uVar2 <= param_2) &&
           (uVar4 = *(uint *)(lVar5 + 0x210), param_2 < (uVar4 - 0x1000) + uVar2)) {
          lVar5 = *(longlong *)(*(longlong *)(lVar3 + 0x50) + uVar6 * 8);
          goto LAB_14002f3c9;
        }
        uVar2 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar2;
      } while (uVar2 < *(uint *)(lVar5 + 0x220));
    }
    iVar1 = *(int *)(lVar3 + 0x60);
    if (((iVar1 == 0) ||
        (uVar2 = *(uint *)(*(longlong *)(lVar3 + 0x58) + uVar6 * 8), param_2 < uVar2)) ||
       (iVar1 + uVar2 <= param_2)) {
      uVar6 = 0;
    }
    else {
      lVar5 = *(longlong *)(*(longlong *)(lVar3 + 0x50) + uVar6 * 8);
      uVar4 = iVar1 + 0xfffU & 0xfffff000;
LAB_14002f3c9:
      uVar6 = (ulonglong)(param_2 - uVar2) + lVar5;
      lVar5 = (ulonglong)(uVar4 - 0x1000) + lVar5;
      if (((uVar6 < *(ulonglong *)(lVar5 + 0x20)) &&
          (lVar3 = *(longlong *)(lVar5 + 0x18), lVar3 != 0)) ||
         (lVar3 = *(longlong *)(lVar5 + 0x38), lVar3 != 0)) {
        uVar6 = (ulonglong)(param_2 - uVar2) + lVar3;
      }
    }
  }
  return uVar6;
}



===== ScsiPortNotificationVrfy @ 14002f430 =====

void ScsiPortNotificationVrfy
               (int param_1,longlong param_2,undefined *param_3,longlong *param_4,byte param_5,
               byte param_6)

{
  undefined *puVar1;
  byte bVar2;
  longlong *plVar3;
  longlong lVar4;
  int local_res18;
  char local_res20;
  byte in_stack_ffffffffffffffb8;
  byte in_stack_ffffffffffffffc0;
  
  if (param_2 == 0) {
    lVar4 = 0;
  }
  else {
    lVar4 = *(longlong *)(param_2 + -8);
  }
  local_res18._0_1_ = (char)param_3;
  local_res20 = (char)param_4;
  if (5 < param_1) {
    if (param_1 == 6) {
      plVar3 = (longlong *)((ulonglong)param_4 & 0xffffffff);
LAB_14002f6c1:
      ScsiPortNotification
                (param_1,param_2,param_3,plVar3,in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0)
      ;
      return;
    }
    if (param_1 != 7) {
      if (param_1 == 8) {
        plVar3 = (longlong *)((ulonglong)param_4 & 0xff);
        if (local_res20 != -1) {
          ScsiPortNotification(8,param_2,param_3,plVar3,param_5,param_6);
          return;
        }
        goto LAB_14002f6c1;
      }
      if (param_1 == 9) {
        if ((char)local_res18 == -1) {
          ScsiPortNotification
                    (9,param_2,(undefined *)0xff,param_4,in_stack_ffffffffffffffb8,
                     in_stack_ffffffffffffffc0);
          return;
        }
        goto LAB_14002f55f;
      }
      if (param_1 == 0xe) {
        local_res18 = (int)param_3;
        SpHandleTraceNotifyType(5,local_res18,param_4);
        return;
      }
    }
LAB_14002f56e:
    ScsiPortNotification
              (param_1,param_2,param_3,param_4,in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0);
    return;
  }
  if (param_1 == 5) goto LAB_14002f608;
  if (param_1 != 0) {
    if (param_1 != 1) {
      if (param_1 == 2) {
        plVar3 = *(longlong **)(lVar4 + 0x360);
        if ((((plVar3 == (longlong *)0x0) || (*(char *)((longlong)plVar3 + 0x155) != local_res20))
            || (*(char *)((longlong)plVar3 + 0x154) != (char)local_res18)) ||
           (*(byte *)((longlong)plVar3 + 0x156) != param_5)) {
          in_stack_ffffffffffffffc0 = 0;
          plVar3 = GetLogicalUnitExtension
                             (lVar4,(char)local_res18,
                              (uint)CONCAT71((int7)((ulonglong)param_3 >> 8),local_res20),param_5,0,
                              '\0');
        }
        if ((((*(longlong *)(lVar4 + 0x760) != 0) &&
             ((*(uint *)(*(longlong *)(lVar4 + 0x760) + 100) & 0x40000000) == 0)) &&
            ((plVar3 != (longlong *)0x0 &&
             ((plVar3[0x3e] != 0 && (lVar4 = *(longlong *)(plVar3[0x3e] + 0x40), lVar4 != 0)))))) &&
           ((*(uint *)(lVar4 + 0xc) & 0x10000) != 0)) {
                    /* WARNING: Subroutine does not return */
          KeBugCheckEx(0xf1,0x1005,param_2,plVar3,0);
        }
LAB_14002f55f:
        ScsiPortNotification
                  (param_1,param_2,(undefined *)((ulonglong)param_3 & 0xff),
                   (longlong *)((ulonglong)param_4 & 0xff),param_5,in_stack_ffffffffffffffc0);
        return;
      }
      if ((param_1 != 3) && (param_1 == 4)) goto LAB_14002f608;
    }
    goto LAB_14002f56e;
  }
  bVar2 = param_3[3] & 0x3f;
  if (bVar2 == 0) goto LAB_14002f612;
  if (bVar2 == 1) {
    if (param_3[4] != '\0') {
      if (param_3[2] == '\0') goto LAB_14002f612;
      goto LAB_14002f5a0;
    }
  }
  else {
LAB_14002f5a0:
    if ((bVar2 == 0xc) || (((0x16 < bVar2 && ((byte)param_3[3] < 0x20)) || (0x23 < bVar2)))) {
LAB_14002f612:
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0xf1,0x1004,param_3,param_2,0);
    }
  }
  if ((*(uint *)(param_3 + 0xc) & 0x10000) == 0) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0xf1,0x1003,param_2,param_3,0);
  }
  puVar1 = *(undefined **)(*(longlong *)(param_3 + 0x30) + 0xb8);
  if (puVar1 != &SpMarker) {
    *(undefined **)(param_3 + 0x18) = puVar1;
  }
  *(undefined8 *)(*(longlong *)(param_3 + 0x30) + 0xb8) = 0;
LAB_14002f608:
  ScsiPortNotification
            (param_1,param_2,param_3,param_4,in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0);
  return;
}



===== ScsiPortSetBusDataByOffsetVrfy @ 14002f6e0 =====

void ScsiPortSetBusDataByOffsetVrfy
               (longlong param_1,int param_2,ulonglong param_3,undefined8 param_4,undefined8 param_5
               ,undefined4 param_6,undefined4 param_7)

{
  if (param_2 != 4) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0xf1,0x1008,param_2,param_1,param_3 & 0xffffffff);
  }
  ScsiPortSetBusDataByOffset(param_1,4,param_3,param_4,param_5,param_6,param_7);
  return;
}



===== ScsiPortStallExecutionVrfy @ 14002f750 =====

void ScsiPortStallExecutionVrfy(uint param_1)

{
  if (100000 < param_1) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0xf1,0x1001,param_1,0,0);
  }
  KeStallExecutionProcessor();
  return;
}



===== ScsiPortValidateRangeVrfy @ 14002f7a0 =====

void ScsiPortValidateRangeVrfy(void)

{
  ScsiPortValidateRange();
  return;
}



===== SpAllocateContiguousChunk @ 14002f7c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

longlong SpAllocateContiguousChunk
                   (undefined8 param_1,longlong param_2,char param_3,ulonglong param_4,int param_5,
                   undefined8 *param_6,undefined1 *param_7)

{
  longlong lVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  
  uVar3 = param_4 & 0xffffffff;
  if (param_2 == 0) {
    lVar1 = SpAllocatePoolEx(0,uVar3,0x63506353,param_1,0x76667279,0x79b);
  }
  else if (((Sp64BitPhysicalAddresses == 0) || (param_3 != '\x01')) && (param_5 == 0)) {
    lVar1 = (**(code **)(*(longlong *)(param_2 + 8) + 0x10))(param_2,uVar3,param_6,0);
    if (param_7 != (undefined1 *)0x0) {
      *param_7 = 1;
    }
  }
  else {
    lVar1 = MmAllocateContiguousNodeMemory
                      (uVar3,0,0xffffffff,-(ulonglong)(param_5 != 0) & uVar3,4,0x80000000);
    if (lVar1 != 0) {
      uVar2 = MmGetPhysicalAddress(lVar1);
      *param_6 = uVar2;
    }
    if (param_7 != (undefined1 *)0x0) {
      *param_7 = 0;
    }
  }
  return lVar1;
}



===== SpEnsureAllRequestsAreComplete @ 14002f8bc =====

void SpEnsureAllRequestsAreComplete(longlong param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  uint uVar3;
  longlong *plVar4;
  
  if ((*(longlong *)(param_1 + 0x760) != 0) &&
     ((*(uint *)(*(longlong *)(param_1 + 0x760) + 100) & 0x20000000) == 0)) {
    uVar3 = 0;
    plVar4 = (longlong *)(param_1 + 0x2e8);
    do {
      for (lVar1 = *plVar4; lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x1a8)) {
        if (((*(longlong *)(lVar1 + 0x1c0) != 0) &&
            ((*(uint *)(*(longlong *)(lVar1 + 0x1c0) + 0xc) & 0x10000) != 0)) ||
           ((*(longlong *)(lVar1 + 0x1f0) != 0 &&
            ((*(uint *)(*(longlong *)(*(longlong *)(lVar1 + 0x1f0) + 0x40) + 0xc) & 0x10000) != 0)))
           ) {
LAB_14002f95c:
                    /* WARNING: Subroutine does not return */
          KeBugCheckEx(0xf1,0x1007,param_1,*(undefined8 *)(param_1 + 0x148),0);
        }
        for (puVar2 = *(undefined8 **)(lVar1 + 0x1d0); puVar2 != (undefined8 *)(lVar1 + 0x1d0);
            puVar2 = (undefined8 *)*puVar2) {
          if ((*(uint *)(puVar2[4] + 0xc) & 0x10000) != 0) goto LAB_14002f95c;
        }
      }
      uVar3 = uVar3 + 1;
      plVar4 = plVar4 + 2;
    } while (uVar3 < 8);
  }
  return;
}



===== SpFreeCommonBufferVrfy @ 14002f988 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SpFreeCommonBufferVrfy(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  longlong lVar7;
  
  lVar7 = *(longlong *)(param_1 + 0x760);
  if ((lVar7 != 0) && (lVar1 = *(longlong *)(lVar7 + 0x50), lVar1 != 0)) {
    uVar5 = 0;
    if (*(int *)(lVar7 + 0x48) != 0) {
      do {
        uVar3 = (ulonglong)uVar5;
        lVar6 = *(longlong *)(lVar1 + uVar3 * 8);
        if (lVar6 == 0) break;
        lVar6 = (ulonglong)(*(int *)(param_1 + 0x210) - 0x1000) + lVar6;
        if (*(longlong *)(lVar6 + 0x10) != 0) {
          MmProtectMdlSystemAddress(*(longlong *)(lVar6 + 0x10),4);
          MmUnlockPages(*(undefined8 *)(lVar6 + 0x10));
          IoFreeMdl(*(undefined8 *)(lVar6 + 0x10));
        }
        if (*(longlong *)(lVar6 + 0x30) != 0) {
          MmProtectMdlSystemAddress(*(undefined8 *)(lVar6 + 0x10),4);
          MmUnlockPages(*(undefined8 *)(lVar6 + 0x30));
          IoFreeMdl(*(undefined8 *)(lVar6 + 0x30));
        }
        lVar7 = *(longlong *)(param_1 + 0x1d0);
        if (lVar7 == 0) {
          ExFreePoolWithTag(*(undefined8 *)(lVar1 + uVar3 * 8),0);
        }
        else if (*(char *)(*(longlong *)(param_1 + 0x760) + 0x70) == '\0') {
          MmFreeContiguousMemorySpecifyCache
                    (*(undefined8 *)(lVar1 + uVar3 * 8),*(undefined4 *)(param_1 + 0x210),1);
        }
        else {
          (**(code **)(*(longlong *)(lVar7 + 8) + 0x18))
                    (lVar7,*(undefined4 *)(param_1 + 0x210),
                     *(undefined8 *)
                      (*(longlong *)(*(longlong *)(param_1 + 0x760) + 0x58) + uVar3 * 8),
                     *(undefined8 *)(lVar1 + uVar3 * 8),0);
        }
        lVar7 = *(longlong *)(param_1 + 0x760);
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)(lVar7 + 0x48));
    }
    if (*(longlong *)(param_1 + 0x150) != 0) {
      lVar6 = *(longlong *)(param_1 + 0x1d0);
      uVar4 = *(int *)(lVar7 + 0x60) + 0xfffU & 0xfffff000;
      uVar3 = (ulonglong)uVar5;
      if (lVar6 == 0) {
        ExFreePoolWithTag(*(undefined8 *)(lVar1 + uVar3 * 8),0);
      }
      else {
        uVar2 = *(undefined8 *)(lVar1 + uVar3 * 8);
        if (*(char *)(param_1 + 0x218) == '\0') {
          MmFreeContiguousMemorySpecifyCache(uVar2,uVar4,1);
        }
        else {
          (**(code **)(*(longlong *)(lVar6 + 8) + 0x18))
                    (lVar6,uVar4,*(undefined8 *)(*(longlong *)(lVar7 + 0x58) + uVar3 * 8),uVar2,0);
        }
      }
      *(undefined8 *)(param_1 + 0x150) = 0;
    }
    ExFreePoolWithTag(*(undefined8 *)(*(longlong *)(param_1 + 0x760) + 0x50),0);
    *(undefined8 *)(*(longlong *)(param_1 + 0x760) + 0x50) = 0;
    *(undefined8 *)(*(longlong *)(param_1 + 0x760) + 0x58) = 0;
    *(undefined4 *)(*(longlong *)(param_1 + 0x760) + 0x48) = 0;
    *(undefined8 *)(param_1 + 0x230) = 0;
  }
  return;
}



===== SpGetCommonBufferVrfy @ 14002fbcc =====

undefined8 SpGetCommonBufferVrfy(longlong *param_1,uint param_2)

{
  void *_Dst;
  undefined8 uVar1;
  undefined8 *puVar2;
  void *pvVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined1 uVar9;
  undefined1 local_res8 [8];
  void *local_res18;
  
  pvVar3 = (void *)0x0;
  local_res8[0] = 0;
  if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
     (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
    WPP_SF_qd(WPP_GLOBAL_Control[3],0xf,&WPP_b72b8674429138f0fdd4ab7f16c2a86d_Traceguids,param_1,
              (char)param_2);
  }
  iVar7 = *(int *)((longlong)param_1 + 0x78c);
  if (iVar7 != 0) {
    param_2 = (param_2 - 1) + iVar7 & -iVar7;
  }
  uVar6 = (int)param_1[0x44] + 1;
  uVar8 = uVar6 * 0x10;
  if (param_1[0x3a] == 0) {
    uVar8 = uVar6 * 8;
  }
  _Dst = (void *)SpAllocatePoolEx(0,(ulonglong)uVar8,0x63506353,*(undefined8 *)(*param_1 + 8),
                                  0x76667279,0x839);
  if (_Dst == (void *)0x0) {
LAB_14002fc8b:
    uVar1 = 0xc000009a;
  }
  else {
    *(int *)(param_1[0xec] + 0x48) = (int)param_1[0x44];
    memset(_Dst,0,(ulonglong)uVar8);
    *(void **)(param_1[0xec] + 0x50) = _Dst;
    if (param_1[0x3a] != 0) {
      pvVar3 = (void *)((longlong)_Dst + (ulonglong)uVar6 * 8);
      *(void **)(param_1[0xec] + 0x58) = pvVar3;
    }
    iVar7 = *(int *)((longlong)param_1 + 0x214);
    if (iVar7 == 0) {
      *(undefined4 *)((longlong)param_1 + 0x214) = 0x10;
      iVar7 = 0x10;
    }
    uVar8 = iVar7 + 0xfffU & 0xfffff000;
    if (*(char *)((longlong)param_1 + 0x48c) == '\x01') {
      uVar8 = uVar8 + *(byte *)(param_1 + 0xe9) + 0x1011 & 0xfffff000;
    }
    else {
      uVar8 = uVar8 + 0x1000;
    }
    uVar8 = uVar8 + 0x1000;
    puVar2 = (void *)0x0;
    uVar5 = 0;
    *(uint *)(param_1 + 0x42) = uVar8;
    local_res18 = (void *)0x0;
    uVar9 = 0;
    if ((int)param_1[0x44] != 0) {
      do {
        if (param_1[0x3a] == 0) {
          puVar2 = (undefined8 *)0x0;
        }
        else {
          puVar2 = (undefined8 *)((longlong)pvVar3 + uVar5 * 8);
        }
        puVar2 = (undefined8 *)
                 SpAllocateContiguousChunk
                           (*(undefined8 *)(*param_1 + 8),param_1[0x3a],
                            *(char *)((longlong)param_1 + 0x491),(ulonglong)uVar8,0,puVar2,
                            local_res8);
        if (puVar2 == (void *)0x0) {
          *(undefined1 *)(param_1[0xec] + 0x70) = local_res8[0];
          goto LAB_14002fe12;
        }
        memset(puVar2,0,(ulonglong)uVar8);
        *(undefined8 **)((longlong)_Dst + uVar5 * 8) = puVar2;
        uVar6 = (int)uVar5 + 1;
        uVar5 = (ulonglong)uVar6;
        *puVar2 = local_res18;
        local_res18 = puVar2;
      } while (uVar6 < *(uint *)(param_1 + 0x44));
      uVar9 = local_res8[0];
    }
    *(undefined1 *)(param_1[0xec] + 0x70) = uVar9;
    if (param_2 == 0) {
      param_1[0x2a] = 0;
      *(undefined4 *)(param_1[0xec] + 0x60) = 0;
    }
    else {
      uVar8 = param_2 + 0x1000;
      *(uint *)(param_1[0xec] + 0x60) = uVar8;
      uVar6 = param_2 + 0x1fff & 0xfffff000;
      if (param_1[0x3a] == 0) {
        puVar4 = (undefined8 *)0x0;
      }
      else {
        puVar4 = (undefined8 *)((longlong)pvVar3 + uVar5 * 8);
      }
      pvVar3 = (void *)SpAllocateContiguousChunk
                                 (*(undefined8 *)(*param_1 + 8),param_1[0x3a],
                                  *(char *)((longlong)param_1 + 0x491),(ulonglong)uVar6,
                                  *(int *)((longlong)param_1 + 0x78c),puVar4,
                                  (undefined1 *)(param_1 + 0x43));
      *(void **)((longlong)_Dst + uVar5 * 8) = pvVar3;
      if (pvVar3 == (void *)0x0) {
LAB_14002fe12:
        SpFreeCommonBufferVrfy((longlong)param_1);
        goto LAB_14002fc8b;
      }
      memset(pvVar3,0,(ulonglong)uVar6);
      param_1[0x2a] =
           (((ulonglong)uVar8 + 0xfff & 0xfffffffffffff000) - (ulonglong)uVar8) +
           *(longlong *)((longlong)_Dst + uVar5 * 8);
    }
    if (*(char *)((longlong)param_1 + 0x48f) == '\x01') {
      param_1[0x46] = (longlong)puVar2;
    }
    SpRemapCommonBufferForMiniport((longlong)param_1);
    if ((((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (3 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_(WPP_GLOBAL_Control[3],0x10,&WPP_b72b8674429138f0fdd4ab7f16c2a86d_Traceguids);
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== SpGetInaccessiblePage @ 14002ff08 =====

undefined8 SpGetInaccessiblePage(longlong *param_1)

{
  ushort *puVar1;
  longlong lVar2;
  longlong lVar3;
  void *_Dst;
  longlong lVar4;
  bool bVar5;
  longlong local_res8 [2];
  
  local_res8[0] = 0;
  lVar3 = IoGetDriverObjectExtension(*(undefined8 *)(*param_1 + 8),ScsiPortInitialize);
  if (lVar3 == 0) {
    return 0;
  }
  if ((*(longlong *)(lVar3 + 0x58) == 0) &&
     (_Dst = (void *)SpAllocatePoolEx(0,0x1000,0x66506353,*(undefined8 *)(*param_1 + 8),0x76667279,
                                      0xaf9), _Dst != (void *)0x0)) {
    memset(_Dst,0,0x1000);
    lVar4 = SpRemapBlock(_Dst,0x1000,local_res8);
    lVar2 = local_res8[0];
    if (lVar4 != 0) {
      LOCK();
      bVar5 = *(longlong *)(lVar3 + 0x58) == 0;
      if (bVar5) {
        *(longlong *)(lVar3 + 0x58) = lVar4;
      }
      UNLOCK();
      if (bVar5) {
        *(longlong *)(lVar3 + 0x50) = local_res8[0];
        *(void **)(lVar3 + 0x48) = _Dst;
        goto LAB_14002ffff;
      }
      MmProtectMdlSystemAddress(local_res8[0],4);
      puVar1 = (ushort *)(lVar2 + 10);
      *puVar1 = *puVar1 & 0xfffe;
      IoFreeMdl(lVar2);
    }
    ExFreePoolWithTag(_Dst,0);
  }
LAB_14002ffff:
  return *(undefined8 *)(lVar3 + 0x58);
}



===== SpHwAdapterControlVrfy @ 140030020 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 SpHwAdapterControlVrfy(longlong param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + -8) + 0x760) + 0x40))();
  return uVar1;
}



===== SpHwDmaStartedVrfy @ 140030060 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 SpHwDmaStartedVrfy(longlong param_1)

{
  (**(code **)(*(longlong *)(*(longlong *)(param_1 + -8) + 0x760) + 0x28))();
  return _DAT_fffff78000000320;
}



===== SpHwFindAdapterVrfy @ 1400300a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SpHwFindAdapterVrfy(longlong param_1)

{
  (*(code *)**(undefined8 **)(*(longlong *)(param_1 + -8) + 0x760))();
  return;
}



===== SpHwInitializeVrfy @ 1400300e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 SpHwInitializeVrfy(longlong param_1)

{
  undefined1 uVar1;
  
  uVar1 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + -8) + 0x760) + 8))();
  return uVar1;
}



===== SpHwInterruptVrfy @ 140030120 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 SpHwInterruptVrfy(longlong param_1)

{
  undefined1 uVar1;
  
  if (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + -8) + 0x760) + 0x18) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + -8) + 0x760) + 0x18))();
  }
  return uVar1;
}



===== SpHwRequestInterruptVrfy @ 140030170 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 SpHwRequestInterruptVrfy(longlong param_1)

{
  undefined1 uVar1;
  
  uVar1 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + -8) + 0x760) + 0x30))();
  return uVar1;
}



===== SpHwResetBusVrfy @ 1400301b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 SpHwResetBusVrfy(longlong param_1)

{
  undefined1 uVar1;
  
  uVar1 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + -8) + 0x760) + 0x20))();
  return uVar1;
}



===== SpHwStartIoVrfy @ 1400301f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

char SpHwStartIoVrfy(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  char cVar5;
  
  lVar1 = *(longlong *)(param_1 + -8);
  lVar2 = *(longlong *)(param_2 + 0x30);
  if ((*(char *)(lVar1 + 0x488) == '\0') && (cVar5 = *(char *)(param_2 + 2), cVar5 != '\x02')) {
    if (cVar5 == '\0') {
      if (*(char *)(param_2 + 0x48) != '*') {
        if (*(char *)(param_2 + 0x48) != '(') goto LAB_14003027a;
        goto LAB_140030235;
      }
    }
    else {
LAB_140030235:
      if (cVar5 == '\x17') goto LAB_14003027a;
    }
    lVar3 = *(longlong *)(param_2 + 0x18);
    if ((((lVar3 != 0) && (lVar4 = *(longlong *)(*(longlong *)(lVar1 + 0x760) + 0x68), lVar4 != 0))
        && (*(char *)(param_2 + 0x48) != '\x12')) && (*(char *)(param_2 + 0x48) != -0x60)) {
      if (lVar3 != lVar4) {
        *(longlong *)(lVar2 + 0xb8) = lVar3;
        *(undefined8 *)(param_2 + 0x18) = *(undefined8 *)(*(longlong *)(lVar1 + 0x760) + 0x68);
      }
      goto LAB_140030281;
    }
  }
LAB_14003027a:
  *(undefined **)(lVar2 + 0xb8) = &SpMarker;
LAB_140030281:
  cVar5 = (**(code **)(*(longlong *)(lVar1 + 0x760) + 0x10))(param_1,param_2);
  if ((cVar5 == '\0') && (*(undefined **)(lVar2 + 0xb8) != &SpMarker)) {
    *(undefined **)(param_2 + 0x18) = *(undefined **)(lVar2 + 0xb8);
    *(undefined8 *)(lVar2 + 0xb8) = 0;
  }
  return cVar5;
}



===== SpHwTimerRequestVrfy @ 1400302f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 SpHwTimerRequestVrfy(longlong param_1)

{
  undefined1 uVar1;
  
  uVar1 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + -8) + 0x760) + 0x38))();
  return uVar1;
}



===== SpInsertSrbExtension @ 14003032c =====

void SpInsertSrbExtension(longlong param_1,ulonglong param_2)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  uint uVar6;
  longlong *plVar7;
  
  puVar4 = (undefined8 *)(param_2 & 0xfffffffffffff000);
  uVar6 = 0;
  *puVar4 = *(undefined8 *)(param_1 + 0x230);
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0x760) + 0x48);
  plVar7 = *(longlong **)(*(longlong *)(param_1 + 0x760) + 0x50);
  if (uVar1 != 0) {
    uVar3 = (ulonglong)(*(int *)(param_1 + 0x210) - 0x1000);
    do {
      lVar2 = *plVar7;
      plVar7 = plVar7 + 1;
      if ((puVar4 == *(undefined8 **)(uVar3 + 0x18 + lVar2)) ||
         (puVar4 == *(undefined8 **)(uVar3 + lVar2))) {
        puVar5 = *(undefined8 **)(uVar3 + lVar2);
        goto LAB_140030387;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar1);
  }
  puVar5 = (undefined8 *)0x0;
LAB_140030387:
  *(undefined8 **)(param_1 + 0x230) = puVar5;
  if (puVar5 != puVar4) {
    MmProtectMdlSystemAddress
              (*(undefined8 *)
                ((ulonglong)(*(int *)(param_1 + 0x210) - 0x1000) + 0x10 + (longlong)puVar5),1);
    lVar2 = *(longlong *)
             ((ulonglong)(*(int *)(param_1 + 0x210) - 0x1000) + 0x30 +
             *(longlong *)(param_1 + 0x230));
    if (lVar2 != 0) {
      MmProtectMdlSystemAddress(lVar2,1);
    }
  }
  return;
}



===== SpPrepareSenseBufferForUse @ 1400303f8 =====

longlong SpPrepareSenseBufferForUse(longlong param_1,longlong param_2)

{
  byte bVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  
  bVar1 = *(byte *)(param_1 + 0x748);
  uVar5 = (ulonglong)(*(int *)(param_1 + 0x214) + 7) & 0xfffffff8;
  lVar4 = uVar5 + param_2;
  lVar2 = *(longlong *)
           (((ulonglong)(*(int *)(param_1 + 0x210) - 0x1000) -
            ((ulonglong)(*(int *)(param_1 + 0x214) + 0xfff) & 0xfffff000)) + uVar5 + 0x30 + param_2)
  ;
  if (lVar2 != 0) {
    iVar3 = MmProtectMdlSystemAddress(lVar2,4);
    if (-1 < iVar3) {
      if ((*(byte *)(lVar2 + 10) & 5) == 0) {
        lVar4 = MmMapLockedPagesSpecifyCache(lVar2,0,1,0,0,0x10);
      }
      else {
        lVar4 = *(longlong *)(lVar2 + 0x18);
      }
    }
  }
  return (lVar4 - ((ulonglong)bVar1 + 0x19 & 0xfffffff8)) + 0x1000;
}



===== SpPrepareSrbExtensionForUse @ 1400304d0 =====

longlong SpPrepareSrbExtensionForUse(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  
  lVar3 = 0;
  uVar4 = *(int *)(param_1 + 0x214) + 7U & 0xfffffff8;
  lVar1 = *(longlong *)((ulonglong)(*(int *)(param_1 + 0x210) - 0x1000) + 0x10 + *param_2);
  if (lVar1 != 0) {
    iVar2 = MmProtectMdlSystemAddress(lVar1,4);
    if (((iVar2 + 0x80000000U & 0x80000000) != 0) || (iVar2 == -0x3fffff45)) {
      if ((*(byte *)(lVar1 + 10) & 5) == 0) {
        lVar3 = MmMapLockedPagesSpecifyCache(lVar1,0,1,0,0,0x10);
      }
      else {
        lVar3 = *(longlong *)(lVar1 + 0x18);
      }
      if (lVar3 != 0) {
        lVar3 = lVar3 + (ulonglong)((*(int *)(param_1 + 0x210) - uVar4) - 0x2000);
      }
    }
  }
  *param_2 = *param_2 + (ulonglong)((*(int *)(param_1 + 0x210) - uVar4) - 0x2000);
  return lVar3;
}



===== SpRemapBlock @ 1400305c0 =====

longlong SpRemapBlock(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  uVar3 = 0;
  lVar1 = IoAllocateMdl(param_1,param_2,0,0,0);
  if (lVar1 != 0) {
    MmProbeAndLockPages(lVar1,0,2);
    lVar2 = MmMapLockedPagesSpecifyCache(lVar1,0,1,0,uVar3 & 0xffffffff00000000,0x10);
    if (lVar2 != 0) {
      MmProtectMdlSystemAddress(lVar1,1);
      *param_3 = lVar1;
      return lVar2;
    }
    IoFreeMdl();
  }
  *param_3 = 0;
  return 0;
}



===== entry @ 140032010 =====

void entry(void)

{
  __security_init_cookie();
  DriverEntry();
  return;
}



===== __security_init_cookie @ 140032044 =====

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



===== DriverEntry @ 140032078 =====

undefined8 DriverEntry(void)

{
  return 0;
}



===== wil_InitializeFeatureStaging @ 140032084 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
    for (ppuVar3 = &Feature_851677496__private_descriptor;
        ppuVar3 < &wil_details_featureDescriptors_z; ppuVar3 = ppuVar3 + 1) {
      if (*ppuVar3 != (undefined *)0x0) goto LAB_14003210b;
    }
LAB_140032145:
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
LAB_14003210b:
  if (ppuVar3 == (undefined **)0x0) goto LAB_140032145;
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
      _g_wil_details_featureChangeNotification = 0;
    }
    goto LAB_140032145;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_1400168d7 < ppuVar3) goto LAB_140032145;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14003210b;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 140032198 =====

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
  ppuVar4 = &Feature_851677496__private_descriptor;
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
            if (&UNK_1400168d7 < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_140032282;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_140032282;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_140032282:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_1400168d7 < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


