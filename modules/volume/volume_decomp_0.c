
===== VolumePassThrough @ 140001010 =====

void VolumePassThrough(longlong param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  IofCallDriver(*(undefined8 *)(lVar1 + 8));
  return;
}



===== __report_gsfailure @ 140001050 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _guard_check_icall @ 140001070 =====

void _guard_check_icall(void)

{
  return;
}



===== __security_check_cookie @ 140001090 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1400010d0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001400010d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140001100 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== VolumeAddDevice @ 140006010 =====

int VolumeAddDevice(undefined8 param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong local_res18;
  
  local_res18 = 0;
  plVar3 = (longlong *)0x0;
  iVar1 = IoCreateDevice(param_1,0x18,0,0x2d,0x100,0,&local_res18);
  if (iVar1 < 0) {
    local_res18 = 0;
  }
  else {
    plVar3 = *(longlong **)(local_res18 + 0x40);
    *plVar3 = 0;
    plVar3[1] = 0;
    plVar3[2] = 0;
    lVar2 = IoAttachDeviceToDeviceStack(local_res18,param_2);
    plVar3[1] = lVar2;
    if (lVar2 != 0) {
      *plVar3 = local_res18;
      *(undefined4 *)(local_res18 + 0x48) = *(undefined4 *)(lVar2 + 0x48);
      *(uint *)(local_res18 + 0x30) = *(uint *)(local_res18 + 0x30) | 0x10;
      *(uint *)(local_res18 + 0x30) =
           *(uint *)(plVar3[1] + 0x30) & 0x6000 | *(uint *)(local_res18 + 0x30);
      *(uint *)(local_res18 + 0x34) =
           *(uint *)(local_res18 + 0x34) | *(uint *)(param_2 + 0x34) & 0x5010f;
      *(uint *)(local_res18 + 0x30) = *(uint *)(local_res18 + 0x30) & 0xffffff7f;
      return iVar1;
    }
    iVar1 = -0x3ffffff2;
  }
  if (local_res18 != 0) {
    if (plVar3[1] != 0) {
      IoDetachDevice(plVar3[1]);
    }
    IoDeleteDevice(local_res18);
  }
  return iVar1;
}



===== VolumeUnload @ 140006160 =====

void VolumeUnload(void)

{
  return;
}



===== VolumePnp @ 140006170 =====

int VolumePnp(longlong param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  int iVar3;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  cVar1 = *(char *)(*(longlong *)(param_2 + 0xb8) + 1);
  if (cVar1 != '\x17') {
    if (cVar1 == '\0') {
      IoForwardIrpSynchronously(*(undefined8 *)(lVar2 + 8),param_2);
      iVar3 = *(int *)(param_2 + 0x30);
      *(int *)(param_2 + 0x30) = iVar3;
      IofCompleteRequest(param_2,0);
      return iVar3;
    }
    if (cVar1 == '\x02') {
      iVar3 = VolumeRemoveDevice(param_1,param_2);
      return iVar3;
    }
    if (cVar1 == '\x16') {
      iVar3 = VolumeDeviceUsageNotification(param_1,param_2);
      return iVar3;
    }
  }
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  iVar3 = IofCallDriver(*(undefined8 *)(lVar2 + 8),param_2);
  return iVar3;
}



===== VolumeDeviceUsageNotification @ 140006220 =====

int VolumeDeviceUsageNotification(longlong param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  
  lVar4 = *(longlong *)(param_1 + 0x40);
  lVar5 = *(longlong *)(param_2 + 0xb8);
  IoForwardIrpSynchronously(*(undefined8 *)(lVar4 + 8));
  iVar3 = *(int *)(param_2 + 0x30);
  if ((-1 < iVar3) && (*(int *)(lVar5 + 0x10) == 1)) {
    if (*(char *)(lVar5 + 8) == '\0') {
      LOCK();
      piVar1 = (int *)(lVar4 + 0x10);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x2000;
      }
    }
    else {
      LOCK();
      piVar1 = (int *)(lVar4 + 0x10);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      if (iVar2 == 0) {
        *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xffffdfff;
      }
    }
  }
  *(int *)(param_2 + 0x30) = iVar3;
  IofCompleteRequest(param_2,0);
  return iVar3;
}



===== VolumeRemoveDevice @ 1400062e0 =====

undefined4 VolumeRemoveDevice(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  
  puVar1 = *(undefined8 **)(param_1 + 0x40);
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  uVar2 = IofCallDriver(puVar1[1]);
  IoDetachDevice(puVar1[1]);
  IoDeleteDevice(*puVar1);
  return uVar2;
}



===== entry @ 140007010 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 140007044 =====

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



===== DriverEntry @ 140007078 =====

undefined8 DriverEntry(longlong param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  
  *(code **)(*(longlong *)(param_1 + 0x30) + 8) = VolumeAddDevice;
  puVar2 = (undefined8 *)(param_1 + 0x70);
  for (lVar1 = 0x1c; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = VolumePassThrough;
    puVar2 = puVar2 + 1;
  }
  *(code **)(param_1 + 0x148) = VolumePnp;
  *(code **)(param_1 + 0x68) = VolumeUnload;
  return 0;
}


