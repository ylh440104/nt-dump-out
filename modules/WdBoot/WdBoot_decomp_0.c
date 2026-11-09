
===== __report_gsfailure @ 140001000 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0xf7,_StackCookie,__security_cookie,__security_cookie_complement,0);
}



===== _guard_check_icall @ 140001030 =====

void _guard_check_icall(void)

{
  return;
}



===== __security_check_cookie @ 140001050 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140001080 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140001080. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1400010a0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== MpEbUnload @ 140005000 =====

void MpEbUnload(void)

{
  return;
}



===== DriverEntry @ 140006000 =====

undefined8 DriverEntry(longlong param_1)

{
  *(code **)(param_1 + 0x68) = MpEbUnload;
  return 0;
}



===== entry @ 140006010 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 14000603c =====

void __cdecl __security_init_cookie(void)

{
  ulonglong uVar1;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    uVar1 = rdtsc();
    __security_cookie =
         ((CONCAT44((int)(__security_cookie >> 0x20),(int)uVar1) | uVar1 & 0xffffffff00000000) ^
         0x140003000) & 0xffffffffffff;
    if (__security_cookie == 0) {
      __security_cookie = 0x2b992ddfa232;
    }
  }
  __security_cookie_complement = ~__security_cookie;
  return;
}


