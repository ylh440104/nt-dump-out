
===== __report_gsfailure @ 1c0001008 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== SvcProxyCallUnimplemented @ 1c0001020 =====

undefined8 SvcProxyCallUnimplemented(void)

{
  return 0xc000001c;
}



===== SvcProxySkCall @ 1c0001030 =====

void SvcProxySkCall(uint *param_1,ulonglong *param_2)

{
  if ((byte)*param_1 < 0xc0) {
    if (SvcCoreIsPresent == 0) {
      *param_2 = 0xc00000bb;
    }
    else {
      (*SvcCoreCall)();
    }
  }
  else {
    SvcProxypSkCall(param_1,param_2);
  }
  return;
}



===== SvcProxypSkCall @ 1c000106c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SvcProxypSkCall(uint *param_1,ulonglong *param_2)

{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined1 auStack_b8 [32];
  undefined4 local_98;
  undefined **local_90;
  undefined2 local_88 [2];
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_78;
  undefined4 local_74;
  undefined8 local_70;
  undefined *local_68;
  uint local_60;
  undefined4 local_5c;
  undefined *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined2 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_b8;
  uVar3 = *param_1;
  if ((uVar3 < 0x200) && (*(longlong *)(param_1 + 2) == 0)) {
    if ((char)uVar3 == -0x40) {
      uVar4 = (ulonglong)(uVar3 & 0x3f);
      bVar2 = KeGetCurrentIrql();
      if ((byte)(&DAT_1c000200c)[uVar4 * 0x18] < bVar2) {
        uVar4 = 0xc0000022;
        local_88[0] = 0x69;
      }
      else if ((*param_1 & 0x100) == 0) {
        uVar4 = 0xc000001c;
        local_88[0] = 0x6e;
      }
      else if (param_1[1] == 0) {
        if ((*(ushort *)(&DAT_1c000200e + uVar4 * 0x18) < 0x51) &&
           (*(ushort *)(&DAT_1c0002010 + uVar4 * 0x18) < 0x51)) {
          uVar3 = (*(code *)(&SvcProxyTable)[uVar4 * 3])(param_1 + 4,param_2 + 2);
          uVar4 = (ulonglong)uVar3;
          goto LAB_1c0001248;
        }
        uVar4 = 0xc0000023;
        local_88[0] = 0x79;
      }
      else {
        uVar4 = 0xc0000206;
        local_88[0] = 0x73;
      }
    }
    else {
      uVar4 = 0xc000001c;
      local_88[0] = 0x60;
    }
  }
  else {
    uVar4 = 0xc000001c;
    local_88[0] = 0x5a;
  }
  if (2 < DAT_1c0003000) {
    if (((DAT_1c0003010 & 1) == 0) || ((DAT_1c0003018 & 1) != DAT_1c0003018)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_3c = 0;
      local_48 = local_88;
      local_2c = 0;
      local_38 = &local_84;
      local_74 = 2;
      local_68 = PTR_DAT_1c0003008;
      local_40 = 2;
      local_30 = 4;
      local_70 = 1;
      local_84 = (undefined4)uVar4;
      local_78 = 0xb000000;
      local_60 = (uint)*(ushort *)PTR_DAT_1c0003008;
      local_58 = &DAT_1c000241c;
      local_5c = 2;
      local_4c = 1;
      local_50 = 0x32;
      local_80 = 0x84;
      local_90 = &local_68;
      local_98 = 4;
      EtwWriteTransfer(DAT_1c0003020,&local_78,0,0);
    }
  }
LAB_1c0001248:
  *param_2 = uVar4;
  return;
}



===== SvcProxyCorepCallHelper @ 1c0001278 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 SvcProxyCorepCallHelper(undefined8 param_1,undefined4 *param_2)

{
  undefined1 auStack_f8 [32];
  undefined4 local_d8;
  undefined1 local_d4 [4];
  undefined4 local_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 local_78 [24];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_f8;
  memset(local_d4,0,0x5c);
  memset(local_78,0,0x60);
  local_d8 = 1;
  if (param_2 != (undefined4 *)0x0) {
    local_d0 = *param_2;
    uStack_cc = param_2[1];
    uStack_c8 = param_2[2];
    uStack_c4 = param_2[3];
  }
  (*DAT_1c0003090)(&local_d8,local_78);
  return local_78[0];
}



===== _tlgDefineProvider_annotation__TlgSVC_PROXY_TRACELOG_PROVIDER_HANDLEProv @ 1c0001310 =====

void _tlgDefineProvider_annotation__TlgSVC_PROXY_TRACELOG_PROVIDER_HANDLEProv(void)

{
  return;
}



===== SvcProxySysCall @ 1c000131c =====

undefined8 SvcProxySysCall(undefined8 param_1)

{
  undefined8 uVar1;
  
  if (SvcCoreIsPresent == 0) {
    uVar1 = 0xc00000bb;
  }
  else {
    uVar1 = (*DAT_1c0003088)(param_1);
  }
  return uVar1;
}



===== __GSHandlerCheck @ 1c0001358 =====

void __GSHandlerCheck(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001c0001358. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __GSHandlerCheck();
  return;
}



===== memset @ 1c000136a =====

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001c000136a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = memset(_Dst,_Val,_Size);
  return pvVar1;
}



===== _guard_check_icall @ 1c0001390 =====

void _guard_check_icall(void)

{
  return;
}



===== __security_check_cookie @ 1c00013b0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c00013f0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c00013f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0001420 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _tlgEnableCallback @ 1c0005008 =====

void _tlgEnableCallback(undefined8 param_1,int param_2,byte param_3,undefined8 param_4,
                       undefined8 param_5,undefined8 param_6,int *param_7)

{
  int iVar1;
  
  if (param_7 != (int *)0x0) {
    if (param_2 == 0) {
      *param_7 = 0;
    }
    else if (param_2 == 1) {
      if (param_3 == 0) {
        iVar1 = 0x100;
      }
      else {
        iVar1 = param_3 + 1;
      }
      *param_7 = iVar1;
      *(undefined8 *)(param_7 + 4) = param_4;
      *(undefined8 *)(param_7 + 6) = param_5;
    }
    if (*(code **)(param_7 + 10) != (code *)0x0) {
      (**(code **)(param_7 + 10))(param_1);
    }
  }
  return;
}



===== entry @ 1c0007010 =====

void entry(void)

{
  __security_init_cookie();
  DriverEntry();
  return;
}



===== __security_init_cookie @ 1c0007044 =====

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



===== DriverEntry @ 1c0007078 =====

undefined8 DriverEntry(void)

{
  return 0;
}



===== SvcSkInitSystem @ 1c0007084 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int SvcSkInitSystem(undefined8 *param_1)

{
  undefined2 uVar1;
  code *pcVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined1 *puVar5;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [40];
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
                    /* 0x7084  1  SvcSkInitSystem */
  puVar5 = auStack_68;
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  uStack_20 = 0;
  local_28 = 0x100;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  local_38 = *(undefined4 *)(PTR_DAT_1c0003008 + -0x10);
  uStack_34 = *(undefined4 *)(PTR_DAT_1c0003008 + -0xc);
  uStack_30 = *(undefined4 *)(PTR_DAT_1c0003008 + -8);
  uStack_2c = *(undefined4 *)(PTR_DAT_1c0003008 + -4);
  if (DAT_1c0003020 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar5 = auStack_60;
  }
  _DAT_1c0003028 = 0;
  uRam00000001c0003030 = 0;
  *(undefined8 *)(puVar5 + -8) = 0x1c0007106;
  iVar3 = EtwRegister(puVar5 + 0x30,_tlgEnableCallback,&DAT_1c0003000,&DAT_1c0003020);
  if (iVar3 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_1c0003008;
    *(undefined8 *)(puVar5 + -8) = 0x1c000712b;
    EtwSetInformation(DAT_1c0003020,2,PTR_DAT_1c0003008,uVar1);
  }
  puVar4 = &SvcCoreCall;
  SvcCoreCall = 0;
  DAT_1c0003088 = 0;
  DAT_1c0003090 = 0;
  *(undefined8 *)(puVar5 + -8) = 0x1c0007151;
  SvcCoreGetEntryPoints();
  if (((SvcCoreCall == 0) || (DAT_1c0003088 == 0)) || (DAT_1c0003090 == 0)) {
    SvcCoreIsPresent = 0;
  }
  else {
    SvcCoreIsPresent = 1;
    *(undefined1 **)(puVar5 + 0x38) = puVar5 + 0x40;
    *(undefined8 **)(puVar5 + 0x30) = param_1;
    *(undefined8 *)(puVar5 + -8) = 0x1c0007197;
    iVar3 = SvcProxyCorepCallHelper(puVar4,(undefined4 *)(puVar5 + 0x30));
    if (iVar3 < 0) goto LAB_1c00071bc;
  }
  param_1[1] = SvcProxySkCall;
  param_1[2] = SvcProxySysCall;
  iVar3 = 0;
LAB_1c00071bc:
  *(undefined8 *)(puVar5 + -8) = 0x1c00071c9;
  return iVar3;
}


