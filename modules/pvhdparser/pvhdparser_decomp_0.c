
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



===== PVhdCancelMetaOperation @ 1c0001020 =====

void PVhdCancelMetaOperation(longlong *param_1)

{
  longlong lVar1;
  char *pcVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    pcVar2 = "Snapshot";
    if ((int)param_1[6] != 1) {
      pcVar2 = "Resize";
    }
    lVar1 = *param_1 + 0x40;
    WPP_SF_qZqsq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pcVar2,lVar1,*param_1,(wchar_t *)lVar1,
                 (char)param_1[1],pcVar2,(char)param_1[7]);
  }
  IoCancelIrp(param_1[7]);
  return;
}



===== PVhdDriverUnload @ 1c00010b0 =====

void PVhdDriverUnload(void)

{
  IoDeleteDevice(PVhdDevice);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x84,
            &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids);
  }
  WppCleanupKm();
  return;
}



===== PVhdSupportsDataTransferDirectionValidation @ 1c0001110 =====

undefined1 PVhdSupportsDataTransferDirectionValidation(void)

{
  return 1;
}



===== PvhdQoSStatusRequestCompletion @ 1c0001120 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 PvhdQoSStatusRequestCompletion(undefined8 param_1,longlong param_2,longlong param_3)

{
  (**(code **)(param_3 + 0x68))
            (*(undefined4 *)(param_2 + 0x30),*(undefined8 *)(param_3 + 0x60),
             *(undefined8 *)(param_3 + 0x70));
  return 0xc0000016;
}



===== WPP_SF_ @ 1c000114c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_D @ 1c0001178 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_DD @ 1c00011c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,0xc,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_DqZ @ 1c0001218 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DqZ(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,wchar_t *param_6)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  wchar_t wVar3;
  undefined4 local_res20 [2];
  
  if (param_6 == (wchar_t *)0x0) {
    wVar3 = L'\b';
  }
  else {
    wVar3 = *param_6;
    if (*param_6 != L'\0') {
      pwVar1 = *(wchar_t **)(param_6 + 4);
      goto LAB_1c0001251;
    }
  }
  pwVar1 = L"NULL";
LAB_1c0001251:
  pwVar2 = param_6;
  if (param_6 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_2,local_res20,4,
             &param_5,8,pwVar2,2,pwVar1,wVar3,0);
  return;
}



===== WPP_SF_I @ 1c00012d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_I(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,0xe,&local_res20,8,0);
  return;
}



===== WPP_SF_IZ @ 1c0001320 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_IZ(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              wchar_t *param_5)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_5;
    if (*param_5 != L'\0') {
      pwVar1 = *(wchar_t **)(param_5 + 4);
      goto LAB_1c0001359;
    }
  }
  pwVar1 = L"NULL";
LAB_1c0001359:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,0xd,&local_res20,8,
             param_5,2,pwVar1,wVar2,0);
  return;
}



===== WPP_SF_Z @ 1c00013c8 =====

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
      goto LAB_1c00013f1;
    }
  }
  pwVar2 = L"NULL";
LAB_1c00013f1:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_2,param_4,2,pwVar2,
             wVar1,0);
  return;
}



===== WPP_SF_Zd @ 1c0001444 =====

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
      goto LAB_1c000146c;
    }
  }
  pwVar2 = L"NULL";
LAB_1c000146c:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,0xf,param_4,2,pwVar2,
             wVar1,&param_5,4,0);
  return;
}



===== WPP_SF_d @ 1c00014dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_d(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_dD @ 1c0001520 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,0x4a,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_dI @ 1c0001578 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dI(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,8,0);
  return;
}



===== WPP_SF_q @ 1c00015cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,0);
  return;
}



===== WPP_SF_qDDDII @ 1c0001610 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDDDII(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                  undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                  undefined1 param_9)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,0x21,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,4,&param_8,8,&param_9,8,0);
  return;
}



===== WPP_SF_qDqZ_guid_ @ 1c00016a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDqZ_guid_(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                      undefined1 param_5,undefined1 param_6,wchar_t *param_7,undefined8 param_8)

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
      goto LAB_1c00016e6;
    }
  }
  pwVar1 = L"NULL";
LAB_1c00016e6:
  pwVar2 = param_7;
  if (param_7 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,0x3d,&local_res20,8,
             &param_5,4,&param_6,8,pwVar2,2,pwVar1,wVar3,param_8,0x10,0);
  return;
}



===== WPP_SF_qIZ @ 1c000179c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qIZ(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,wchar_t *param_6)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  wchar_t wVar3;
  undefined8 local_res20;
  
  if (param_6 == (wchar_t *)0x0) {
    wVar3 = L'\b';
  }
  else {
    wVar3 = *param_6;
    if (*param_6 != L'\0') {
      pwVar1 = *(wchar_t **)(param_6 + 4);
      goto LAB_1c00017d8;
    }
  }
  pwVar1 = L"NULL";
LAB_1c00017d8:
  pwVar2 = param_6;
  if (param_6 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,0x11,&local_res20,8,
             &param_5,8,pwVar2,2,pwVar1,wVar3,0);
  return;
}



===== WPP_SF_qZ @ 1c0001854 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qZ(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              wchar_t *param_5)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_5;
    if (*param_5 != L'\0') {
      pwVar1 = *(wchar_t **)(param_5 + 4);
      goto LAB_1c000188d;
    }
  }
  pwVar1 = L"NULL";
LAB_1c000188d:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_2,&local_res20,8,
             param_5,2,pwVar1,wVar2,0);
  return;
}



===== WPP_SF_qZ_guid__guid_ii @ 1c00018fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qZ_guid__guid_ii
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               wchar_t *param_5,undefined8 param_6,undefined8 param_7,undefined1 param_8,
               undefined1 param_9)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *param_5;
    if (*param_5 != L'\0') {
      pwVar2 = *(wchar_t **)(param_5 + 4);
      goto LAB_1c000193e;
    }
  }
  pwVar2 = L"NULL";
LAB_1c000193e:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,0x7a,&local_res20,8,
             param_5,2,pwVar2,wVar1,param_6,0x10,param_7,0x10,&param_8,8,&param_9,8,0);
  return;
}



===== WPP_SF_qZ_guid__guid_iid @ 1c0001a08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qZ_guid__guid_iid
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               wchar_t *param_5,undefined8 param_6,undefined8 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *param_5;
    if (*param_5 != L'\0') {
      pwVar2 = *(wchar_t **)(param_5 + 4);
      goto LAB_1c0001a4a;
    }
  }
  pwVar2 = L"NULL";
LAB_1c0001a4a:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,0x80,&local_res20,8,
             param_5,2,pwVar2,wVar1,param_6,0x10,param_7,0x10,&param_8,8,&param_9,8,&param_10,4,0);
  return;
}



===== WPP_SF_qZ_guid_d @ 1c0001b30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qZ_guid_d(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                     wchar_t *param_5,undefined8 param_6,undefined1 param_7)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *param_5;
    if (*param_5 != L'\0') {
      pwVar2 = *(wchar_t **)(param_5 + 4);
      goto LAB_1c0001b6a;
    }
  }
  pwVar2 = L"NULL";
LAB_1c0001b6a:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,0x77,&local_res20,8,
             param_5,2,pwVar2,wVar1,param_6,0x10,&param_7,4,0);
  return;
}



===== WPP_SF_qZ_guid_ddI @ 1c0001c0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qZ_guid_ddI(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                       wchar_t *param_5,undefined8 param_6,undefined1 param_7,undefined1 param_8,
                       undefined1 param_9)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *param_5;
    if (*param_5 != L'\0') {
      pwVar2 = *(wchar_t **)(param_5 + 4);
      goto LAB_1c0001c4e;
    }
  }
  pwVar2 = L"NULL";
LAB_1c0001c4e:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,0x78,&local_res20,8,
             param_5,2,pwVar2,wVar1,param_6,0x10,&param_7,4,&param_8,4,&param_9,8,0);
  return;
}



===== WPP_SF_qZd @ 1c0001d20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qZd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               wchar_t *param_5,undefined1 param_6)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_5;
    if (*param_5 != L'\0') {
      pwVar1 = *(wchar_t **)(param_5 + 4);
      goto LAB_1c0001d59;
    }
  }
  pwVar1 = L"NULL";
LAB_1c0001d59:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_2,&local_res20,8,
             param_5,2,pwVar1,wVar2,&param_6,4,0);
  return;
}



===== WPP_SF_qZqDSI @ 1c0001ddc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qZqDSI(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                  wchar_t *param_5,undefined1 param_6,undefined1 param_7,wchar_t *param_8,
                  undefined1 param_9)

{
  longlong lVar1;
  wchar_t wVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  undefined8 local_res20;
  
  if (param_8 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_8[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  pwVar4 = L"NULL";
  pwVar3 = param_8;
  if (param_8 == (wchar_t *)0x0) {
    pwVar3 = L"NULL";
  }
  if (param_5 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_5;
    if (*param_5 != L'\0') {
      pwVar4 = *(wchar_t **)(param_5 + 4);
    }
  }
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,0x56,&local_res20,8,
             param_5,2,pwVar4,wVar2,&param_6,8,&param_7,4,pwVar3,lVar1,&param_9,8,0);
  return;
}



===== WPP_SF_qZqI @ 1c0001f1c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qZqI(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                wchar_t *param_5,undefined1 param_6,undefined1 param_7)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_5;
    if (*param_5 != L'\0') {
      pwVar1 = *(wchar_t **)(param_5 + 4);
      goto LAB_1c0001f5b;
    }
  }
  pwVar1 = L"NULL";
LAB_1c0001f5b:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,0x53,&local_res20,8,
             param_5,2,pwVar1,wVar2,&param_6,8,&param_7,8,0);
  return;
}



===== WPP_SF_qZq_guid_DI @ 1c0001ff0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qZq_guid_DI(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                       wchar_t *param_5,undefined1 param_6,undefined8 param_7,undefined1 param_8,
                       undefined1 param_9)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_5;
    if (*param_5 != L'\0') {
      pwVar1 = *(wchar_t **)(param_5 + 4);
      goto LAB_1c0002032;
    }
  }
  pwVar1 = L"NULL";
LAB_1c0002032:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,0x57,&local_res20,8,
             param_5,2,pwVar1,wVar2,&param_6,8,param_7,0x10,&param_8,4,&param_9,8,0);
  return;
}



===== WPP_SF_qZqc_guid__guid_DSI @ 1c0002100 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qZqc_guid__guid_DSI
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               wchar_t *param_5,undefined1 param_6,undefined1 param_7,undefined8 param_8,
               undefined8 param_9,undefined1 param_10,wchar_t *param_11,undefined1 param_12)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  longlong lVar3;
  wchar_t *pwVar4;
  undefined8 local_res20;
  
  if (param_11 == (wchar_t *)0x0) {
    lVar3 = 10;
  }
  else {
    lVar3 = -1;
    do {
      lVar3 = lVar3 + 1;
    } while (param_11[lVar3] != L'\0');
    lVar3 = lVar3 * 2 + 2;
  }
  pwVar4 = L"NULL";
  pwVar1 = param_11;
  if (param_11 == (wchar_t *)0x0) {
    pwVar1 = L"NULL";
  }
  if (param_5 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_5;
    if (*param_5 != L'\0') {
      pwVar4 = *(wchar_t **)(param_5 + 4);
    }
  }
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,0x54,&local_res20,8,
             param_5,2,pwVar4,wVar2,&param_6,8,&param_7,1,param_8,0x10,param_9,0x10,&param_10,4,
             pwVar1,lVar3,&param_12,8,0);
  return;
}



===== WPP_SF_qZqcciI @ 1c0002290 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qZqcciI(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   wchar_t *param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                   undefined1 param_9,undefined1 param_10)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_5;
    if (*param_5 != L'\0') {
      pwVar1 = *(wchar_t **)(param_5 + 4);
      goto LAB_1c00022d4;
    }
  }
  pwVar1 = L"NULL";
LAB_1c00022d4:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,0x55,&local_res20,8,
             param_5,2,pwVar1,wVar2,&param_6,8,&param_7,1,&param_8,1,&param_9,8,&param_10,8,0);
  return;
}



===== WPP_SF_qZqd @ 1c00023b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qZqd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                wchar_t *param_5,undefined1 param_6,undefined1 param_7)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_5;
    if (*param_5 != L'\0') {
      pwVar1 = *(wchar_t **)(param_5 + 4);
      goto LAB_1c00023f7;
    }
  }
  pwVar1 = L"NULL";
LAB_1c00023f7:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_2,&local_res20,8,
             param_5,2,pwVar1,wVar2,&param_6,8,&param_7,4,0);
  return;
}



===== WPP_SF_qZqdI @ 1c000248c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qZqdI(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 wchar_t *param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_5;
    if (*param_5 != L'\0') {
      pwVar1 = *(wchar_t **)(param_5 + 4);
      goto LAB_1c00024cb;
    }
  }
  pwVar1 = L"NULL";
LAB_1c00024cb:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,0x49,&local_res20,8,
             param_5,2,pwVar1,wVar2,&param_6,8,&param_7,4,&param_8,8,0);
  return;
}



===== WPP_SF_qZqd_guid_I @ 1c0002578 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qZqd_guid_I(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                       wchar_t *param_5,undefined1 param_6,undefined1 param_7,undefined8 param_8,
                       undefined1 param_9)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_5;
    if (*param_5 != L'\0') {
      pwVar1 = *(wchar_t **)(param_5 + 4);
      goto LAB_1c00025ba;
    }
  }
  pwVar1 = L"NULL";
LAB_1c00025ba:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,0x73,&local_res20,8,
             param_5,2,pwVar1,wVar2,&param_6,8,&param_7,4,param_8,0x10,&param_9,8,0);
  return;
}



===== WPP_SF_qZqd_guid_dddddddI @ 1c0002688 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qZqd_guid_dddddddI
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               wchar_t *param_5,undefined1 param_6,undefined1 param_7,undefined8 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12,
               undefined1 param_13,undefined1 param_14,undefined1 param_15,undefined1 param_16)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_5;
    if (*param_5 != L'\0') {
      pwVar1 = *(wchar_t **)(param_5 + 4);
      goto LAB_1c00026d1;
    }
  }
  pwVar1 = L"NULL";
LAB_1c00026d1:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,0x52,&local_res20,8,
             param_5,2,pwVar1,wVar2,&param_6,8,&param_7,4,param_8,0x10,&param_9,4,&param_10,4,
             &param_11,4,&param_12,4,&param_13,4,&param_14,4,&param_15,4,&param_16,8,0);
  return;
}



===== WPP_SF_qZqdd_guid_ @ 1c000281c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qZqdd_guid_(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                       wchar_t *param_5,undefined1 param_6,undefined1 param_7,undefined8 param_8,
                       undefined8 param_9)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  undefined8 local_res20;
  undefined4 local_18 [4];
  
  local_18[0] = 0x20;
  if (param_5 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_5;
    if (*param_5 != L'\0') {
      pwVar1 = *(wchar_t **)(param_5 + 4);
      goto LAB_1c0002868;
    }
  }
  pwVar1 = L"NULL";
LAB_1c0002868:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,0x74,&local_res20,8,
             param_5,2,pwVar1,wVar2,&param_6,8,&param_7,4,local_18,4,param_9,0x10,0);
  return;
}



===== WPP_SF_qZqddd @ 1c0002938 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qZqddd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                  wchar_t *param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  undefined8 local_res20;
  undefined4 local_18 [4];
  
  local_18[0] = 0;
  if (param_5 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_5;
    if (*param_5 != L'\0') {
      pwVar1 = *(wchar_t **)(param_5 + 4);
      goto LAB_1c0002980;
    }
  }
  pwVar1 = L"NULL";
LAB_1c0002980:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_2,&local_res20,8,
             param_5,2,pwVar1,wVar2,&param_6,8,&param_7,4,&param_8,4,local_18,4,0);
  return;
}



===== WPP_SF_qZqs_guid_ @ 1c0002a48 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qZqs_guid_(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                      wchar_t *param_5,undefined1 param_6,char *param_7,undefined8 param_8)

{
  wchar_t wVar1;
  longlong lVar2;
  longlong lVar3;
  char *pcVar4;
  wchar_t *pwVar5;
  undefined8 local_res20;
  
  if (param_7 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_7[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  pcVar4 = param_7;
  if (param_7 == (char *)0x0) {
    pcVar4 = "NULL";
  }
  if (param_5 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *param_5;
    if (*param_5 != L'\0') {
      pwVar5 = *(wchar_t **)(param_5 + 4);
      goto LAB_1c0002ac6;
    }
  }
  pwVar5 = L"NULL";
LAB_1c0002ac6:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,0x72,&local_res20,8,
             param_5,2,pwVar5,wVar1,&param_6,8,pcVar4,lVar3,param_8,0x10,0);
  return;
}



===== WPP_SF_qZqsq @ 1c0002b7c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qZqsq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 wchar_t *param_5,undefined1 param_6,char *param_7,undefined1 param_8)

{
  wchar_t wVar1;
  longlong lVar2;
  longlong lVar3;
  char *pcVar4;
  wchar_t *pwVar5;
  undefined8 local_res20;
  
  if (param_7 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_7[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  pcVar4 = param_7;
  if (param_7 == (char *)0x0) {
    pcVar4 = "NULL";
  }
  if (param_5 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *param_5;
    if (*param_5 != L'\0') {
      pwVar5 = *(wchar_t **)(param_5 + 4);
      goto LAB_1c0002bf6;
    }
  }
  pwVar5 = L"NULL";
LAB_1c0002bf6:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,0x71,&local_res20,8,
             param_5,2,pwVar5,wVar1,&param_6,8,pcVar4,lVar3,&param_8,8,0);
  return;
}



===== WPP_SF_qd @ 1c0002ca4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,4,0);
  return;
}



===== WPP_SF_qdI @ 1c0002cf8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qdI(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_2,&local_res20,8,
             &param_5,4,&param_6,8,0);
  return;
}



===== WPP_SF_qdII @ 1c0002d60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qdII(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_2,&local_res20,8,
             &param_5,4,&param_6,8,&param_7,8,0);
  return;
}



===== WPP_SF_qdd @ 1c0002dd4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qdd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_2,&local_res20,8,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_qdddic_guid_ @ 1c0002e3c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qdddic_guid_(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        ,undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        ,undefined1 param_9,undefined8 param_10)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,0x14,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,4,&param_8,8,&param_9,1,param_10,0x10,0);
  return;
}



===== WPP_SF_qi_guid__guid_iii @ 1c0002ee4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qi_guid__guid_iii
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined8 param_6,undefined8 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,0x7c,&local_res20,8,
             &param_5,8,param_6,0x10,param_7,0x10,&param_8,8,&param_9,8,&param_10,8,0);
  return;
}



===== WPP_SF_qi_guid_ddi @ 1c0002f90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qi_guid_ddi(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                       undefined1 param_5,undefined8 param_6,undefined1 param_7,undefined1 param_8,
                       undefined1 param_9)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,0x31,&local_res20,8,
             &param_5,8,param_6,0x10,&param_7,4,&param_8,4,&param_9,8,0);
  return;
}



===== WPP_SF_qid @ 1c0003030 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qid(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_2,&local_res20,8,
             &param_5,8,&param_6,4,0);
  return;
}



===== WPP_SF_qidiiii @ 1c0003098 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qidiiii(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                   undefined1 param_9,undefined1 param_10)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,0x34,&local_res20,8,
             &param_5,8,&param_6,4,&param_7,8,&param_8,8,&param_9,8,&param_10,8,0);
  return;
}



===== WPP_SF_qiii @ 1c0003134 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qiii(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined8 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  undefined8 local_18 [3];
  
  local_18[0] = 0x10;
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_2,&local_res20,8,
             &param_5,8,local_18,8,&param_7,8,0);
  return;
}



===== WPP_SF_qqd @ 1c00031b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,&param_6,4,0);
  return;
}



===== WppClassicProviderCallback @ 1c0003210 =====

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



===== PVhdCompleteScsiRequest @ 1c0003244 =====

void PVhdCompleteScsiRequest(undefined8 *param_1)

{
  longlong *plVar1;
  char cVar2;
  longlong lVar3;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids,param_1);
  }
  lVar3 = param_1[1];
  if (((*(char *)(lVar3 + 2) == '\x04') && (*(char *)(lVar3 + 3) == '\x02')) &&
     (((*(byte *)(lVar3 + 0x12) & 0xf) == 6 &&
      ((*(char *)(lVar3 + 0x1c) == '*' && (*(char *)(lVar3 + 0x1d) == '\t')))))) {
    plVar1 = (longlong *)*param_1;
    cVar2 = KeGetCurrentIrql();
    lVar3 = *plVar1;
    if (cVar2 == '\0') {
      PVhdQueryStartingInfo(lVar3);
    }
    else {
      lVar3 = IoAllocateWorkItem(*(undefined8 *)(lVar3 + 0x10));
      if (lVar3 != 0) {
        IoQueueWorkItemEx(lVar3,PVhdReQueryStartingInfoWorkItem,1,*plVar1);
      }
    }
  }
  VstorCompleteScsiRequest(param_1);
  return;
}



===== PVhdFillTunneledIrp @ 1c0003324 =====

void PVhdFillTunneledIrp(longlong param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                        undefined4 param_5,char param_6)

{
  longlong lVar1;
  
  *(undefined8 *)(param_1 + 0x18) = param_3;
  *(undefined4 *)(param_1 + 0x10) = 0x10;
  lVar1 = *(longlong *)(param_1 + 0xb8);
  *(void **)(param_1 + 0x98) = SystemReserved1[0xf];
  *(undefined1 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(lVar1 + -0x40) = param_5;
  *(undefined1 *)(lVar1 + -0x48) = 0xd;
  *(undefined8 *)(lVar1 + -0x18) = param_2;
  *(uint *)(lVar1 + -0x30) = (-(uint)(param_6 != '\0') & 0x60) + 0x90304;
  *(undefined4 *)(lVar1 + -0x38) = param_4;
  return;
}



===== PVhdIrpRequestComplete @ 1c0003380 =====

undefined8 PVhdIrpRequestComplete(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
             &WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids,param_3);
  }
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== PVhdNtStatusToSrbStatus @ 1c00033e8 =====

void PVhdNtStatusToSrbStatus(int param_1,longlong param_2)

{
  if (param_1 == -0x3ffffd7b) {
    *(undefined2 *)(param_2 + 2) = 0x206;
LAB_1c0003488:
    *(undefined2 *)(param_2 + 2) = 0x1804;
    return;
  }
  if (param_1 == -0x3fa300fe) {
    *(undefined2 *)(param_2 + 2) = 0x204;
    *(undefined2 *)(param_2 + 0x1c) = 0x92a;
  }
  else if (param_1 == -0x3fa300fd) {
    *(undefined2 *)(param_2 + 2) = 0x204;
    *(undefined2 *)(param_2 + 0x1c) = 0x32a;
  }
  else if (param_1 == -0x3fa300fc) {
    *(undefined2 *)(param_2 + 2) = 0x204;
    *(undefined2 *)(param_2 + 0x1c) = 0x42a;
  }
  else {
    if (param_1 != -0x3fa300fb) {
      if (param_1 != -0x3fa300fa) {
        if (param_1 == -0x3fa300f9) goto LAB_1c0003488;
        if (param_1 == 0) {
          *(undefined2 *)(param_2 + 2) = 1;
          return;
        }
      }
      *(undefined2 *)(param_2 + 2) = 0x204;
      return;
    }
    *(undefined2 *)(param_2 + 2) = 0x204;
    *(undefined2 *)(param_2 + 0x1c) = 0x52a;
  }
  *(undefined1 *)(param_2 + 0x10) = 0xf0;
  *(undefined1 *)(param_2 + 0x17) = 10;
  *(byte *)(param_2 + 0x12) = *(byte *)(param_2 + 0x12) & 0xf6 | 6;
  return;
}



===== PVhdReadWriteIoComplete @ 1c00034a0 =====

undefined8 PVhdReadWriteIoComplete(undefined8 param_1,longlong param_2,longlong *param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  char cVar3;
  longlong lVar4;
  uint uVar5;
  undefined2 uVar6;
  undefined1 uVar7;
  longlong *plVar8;
  undefined1 uVar9;
  
  uVar1 = *(undefined8 *)(param_2 + 0x30);
  uVar2 = *(undefined8 *)(param_2 + 0x38);
  uVar5 = (uint)uVar1;
  plVar8 = param_3;
  IoFreeIrp(param_2);
  *(int *)(param_3[1] + 0xc) = (int)uVar2;
  uVar9 = (undefined1)uVar2;
  uVar7 = (undefined1)uVar1;
  if ((uVar5 & 0xffffff00) == 0xc05c0000) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qId(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,plVar8,param_3,uVar9,uVar7);
    }
    *(undefined1 *)(*param_3 + 8) = uVar7;
    cVar3 = KeGetCurrentIrql();
    if (cVar3 == '\0') {
      IoSetTopLevelIrp(0);
      PVhdReadWriteIoIssueRetrieveStatusRequestFsctl(param_3);
      return 0xc0000016;
    }
    lVar4 = IoAllocateWorkItem(param_1);
    if (lVar4 != 0) {
      IoQueueWorkItemEx(lVar4,PVhdReadWriteIoRetrieveStatusWorkItem,1,param_3);
      return 0xc0000016;
    }
    uVar5 = 0xc000009a;
  }
  else {
    if ((int)uVar5 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) goto LAB_1c0003609;
      uVar6 = 0x2c;
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5)
         ) goto LAB_1c0003609;
      uVar6 = 0x2d;
    }
    WPP_SF_qId(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,plVar8,param_3,uVar9,uVar7);
  }
LAB_1c0003609:
  PVhdNtStatusToSrbStatus(uVar5,param_3[1]);
  PVhdCompleteScsiRequest(param_3);
  return 0xc0000016;
}



===== PVhdReadWriteIoIssueRetrieveStatusRequestFsctl @ 1c000363c =====

void PVhdReadWriteIoIssueRetrieveStatusRequestFsctl(longlong *param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined4 *puVar4;
  longlong lVar5;
  longlong lVar6;
  int iVar7;
  undefined8 uVar8;
  
  plVar2 = (longlong *)*param_1;
  uVar8 = 0x54507070;
  lVar3 = *plVar2;
  puVar4 = (undefined4 *)ExAllocatePool2(0x40);
  if (puVar4 == (undefined4 *)0x0) {
    iVar7 = -0x3fffffe9;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_Id(*(undefined8 *)(WPP_GLOBAL_Control + 0x18));
    }
  }
  else {
    lVar5 = IoAllocateIrp(*(char *)(*(longlong *)(lVar3 + 0x10) + 0x4c) + '\x01',0);
    if (lVar5 != 0) {
      *puVar4 = 0x2001004;
      LOCK();
      plVar1 = (longlong *)(lVar3 + 0x38);
      lVar6 = *plVar1;
      *plVar1 = *plVar1 + 1;
      UNLOCK();
      lVar6 = lVar6 + 1;
      *(longlong *)(puVar4 + 2) = lVar6;
      *(char *)(puVar4 + 4) = (char)plVar2[1];
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_qqDI(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar6,uVar8,param_1,(char)lVar3,
                    (char)plVar2[1],(char)lVar6);
      }
      uVar8 = *(undefined8 *)(lVar3 + 8);
      *(undefined4 *)(lVar5 + 0x10) = 0x10;
      *(undefined4 **)(lVar5 + 0x18) = puVar4;
      *(void **)(lVar5 + 0x98) = SystemReserved1[0xf];
      lVar6 = *(longlong *)(lVar5 + 0xb8);
      *(undefined1 *)(lVar5 + 0x40) = 0;
      *(undefined8 *)(lVar6 + -0x18) = uVar8;
      *(undefined1 *)(lVar6 + -0x48) = 0xd;
      *(undefined4 *)(lVar6 + -0x38) = 0x28;
      *(undefined4 *)(lVar6 + -0x40) = 0x28;
      *(undefined4 *)(lVar6 + -0x30) = 0x90304;
      plVar2[2] = (longlong)puVar4;
      lVar6 = *(longlong *)(lVar5 + 0xb8);
      *(code **)(lVar6 + -0x10) = PVhdReadWriteIoRetrieveStatusCompleted;
      *(longlong **)(lVar6 + -8) = param_1;
      *(undefined1 *)(lVar6 + -0x45) = 0xe0;
      IofCallDriver(*(undefined8 *)(lVar3 + 0x10),lVar5);
      return;
    }
    iVar7 = -0x3fffff66;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
              &WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids);
    }
    ExFreePoolWithTag(puVar4,0x54507070);
    plVar2[2] = 0;
  }
  PVhdNtStatusToSrbStatus(iVar7,param_1[1]);
  PVhdCompleteScsiRequest(param_1);
  return;
}



===== PVhdReadWriteIoRetrieveStatusCompleted @ 1c0003840 =====

undefined8
PVhdReadWriteIoRetrieveStatusCompleted(undefined8 param_1,longlong param_2,longlong *param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  byte bVar4;
  
  lVar1 = *param_3;
  lVar2 = param_3[1];
  lVar3 = *(longlong *)(lVar1 + 0x10);
  if (((*(int *)(param_2 + 0x30) < 0) || (*(ulonglong *)(param_2 + 0x38) < 0x28)) ||
     (*(int *)(lVar3 + 4) < 0)) {
    *(undefined2 *)(lVar2 + 2) = 0x204;
  }
  else {
    *(undefined1 *)(lVar2 + 2) = *(undefined1 *)(lVar3 + 0x11);
    *(undefined1 *)(lVar2 + 3) = *(undefined1 *)(lVar3 + 0x12);
    bVar4 = *(byte *)(lVar3 + 0x13);
    *(byte *)(lVar2 + 9) = bVar4;
    if (bVar4 < 0x15) {
      if (bVar4 == 0) goto LAB_1c00038b4;
    }
    else {
      *(undefined1 *)(lVar2 + 9) = 0x14;
      bVar4 = 0x14;
    }
    memcpy((void *)(lVar2 + 0x10),(void *)(lVar3 + 0x14),(ulonglong)bVar4);
  }
LAB_1c00038b4:
  IoFreeIrp(param_2);
  ExFreePoolWithTag(lVar3,0x54507070);
  *(undefined8 *)(lVar1 + 0x10) = 0;
  PVhdCompleteScsiRequest(param_3);
  return 0xc0000016;
}



===== PVhdScsiRequestFsctlCompletion @ 1c0003910 =====

undefined8 PVhdScsiRequestFsctlCompletion(undefined8 param_1,longlong param_2,longlong param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  void *_Dst;
  ulonglong uVar3;
  byte bVar4;
  uint uVar5;
  undefined2 uVar6;
  longlong lVar7;
  int iVar8;
  undefined **ppuVar9;
  undefined4 uVar10;
  undefined8 in_stack_ffffffffffffffc8;
  
  puVar1 = *(undefined8 **)(param_3 + 0x18);
  lVar2 = *(longlong *)(param_3 + 0x10);
  _Dst = *(void **)(param_3 + 0x20);
  iVar8 = *(int *)(param_2 + 0x30);
  lVar7 = puVar1[1];
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
            &WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids);
  }
  ppuVar9 = &WPP_GLOBAL_Control;
  if (*(int *)(param_2 + 0x30) < 0) {
    PVhdNtStatusToSrbStatus(*(int *)(param_2 + 0x30),lVar7);
    *(undefined4 *)(puVar1[1] + 0xc) = 0;
    if ((((undefined **)WPP_GLOBAL_Control == ppuVar9) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c0003ba2;
    uVar10 = *(undefined4 *)(param_2 + 0x30);
    uVar6 = 0x22;
  }
  else {
    uVar3 = *(ulonglong *)(param_2 + 0x38);
    if (uVar3 < 8) {
      iVar8 = -0x3fffff3d;
      PVhdNtStatusToSrbStatus(-0x3fffff3d,lVar7);
      *(undefined4 *)(puVar1[1] + 0xc) = 0;
      if ((((undefined **)WPP_GLOBAL_Control != ppuVar9) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_IDI(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar7,ppuVar9,
                   *(undefined8 *)(param_2 + 0x38),in_stack_ffffffffffffffc8,
                   (char)*(undefined8 *)(lVar2 + 8));
      }
      goto LAB_1c0003ba2;
    }
    iVar8 = *(int *)(lVar2 + 4);
    if (iVar8 < 0) {
      PVhdNtStatusToSrbStatus(iVar8,lVar7);
      *(undefined4 *)(puVar1[1] + 0xc) = 0;
      if ((((undefined **)WPP_GLOBAL_Control == ppuVar9) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) goto LAB_1c0003ba2;
      uVar10 = *(undefined4 *)(lVar2 + 4);
      uVar6 = 0x24;
    }
    else {
      uVar5 = *(int *)(lVar2 + 0x1c) + 0x34;
      if (0x33 < uVar5) {
        if ((uVar3 < 0x34) || (uVar3 < uVar5)) {
          iVar8 = -0x3fffff1b;
          PVhdNtStatusToSrbStatus(-0x3fffff1b,lVar7);
          *(undefined4 *)(puVar1[1] + 0xc) = 0;
          if (((undefined **)WPP_GLOBAL_Control != ppuVar9) &&
             (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0 &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
            WPP_SF_IDDI(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar7,ppuVar9,
                        *(undefined8 *)(param_2 + 0x38),in_stack_ffffffffffffffc8,
                        (char)*(undefined4 *)(lVar2 + 0x1c),(char)*(undefined8 *)(lVar2 + 8));
          }
        }
        else {
          *(undefined1 *)(lVar7 + 2) = *(undefined1 *)(lVar2 + 0x12);
          *(undefined1 *)(lVar7 + 3) = *(undefined1 *)(lVar2 + 0x13);
          bVar4 = *(byte *)(lVar2 + 0x15);
          *(byte *)(lVar7 + 9) = bVar4;
          if (0x14 < bVar4) {
            *(undefined1 *)(lVar7 + 9) = 0x14;
            bVar4 = 0x14;
          }
          if (*(uint *)(lVar2 + 0x1c) < *(uint *)(lVar7 + 0xc)) {
            *(uint *)(lVar7 + 0xc) = *(uint *)(lVar2 + 0x1c);
          }
          if (bVar4 != 0) {
            memcpy((void *)(lVar7 + 0x10),(void *)(lVar2 + 0x20),(ulonglong)bVar4);
          }
          iVar8 = 0;
          if (((*(uint *)(lVar7 + 0xc) != 0) && (_Dst != (void *)0x0)) &&
             (*(char *)(lVar7 + 10) != '\0')) {
            memcpy(_Dst,(void *)(lVar2 + 0x34),(ulonglong)*(uint *)(lVar7 + 0xc));
          }
        }
        goto LAB_1c0003ba2;
      }
      iVar8 = -0x3fffff6b;
      PVhdNtStatusToSrbStatus(-0x3fffff6b,lVar7);
      *(undefined4 *)(puVar1[1] + 0xc) = 0;
      if ((((undefined **)WPP_GLOBAL_Control == ppuVar9) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) goto LAB_1c0003ba2;
      uVar6 = 0x25;
      uVar10 = 0xc0000095;
    }
  }
  WPP_SF_dI(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
            &WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids,uVar10,(char)*(undefined8 *)(lVar2 + 8)
           );
LAB_1c0003ba2:
  ExFreePoolWithTag(lVar2,0x54507070);
  *(undefined8 *)(param_3 + 0x10) = 0;
  IoFreeIrp(param_2);
  PVhdCompleteScsiRequest(puVar1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
             &WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids,iVar8);
  }
  return 0xc0000016;
}



===== PvhdSynchronouslFsctl @ 1c0003c38 =====

ulonglong PvhdSynchronouslFsctl
                    (longlong param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong local_38 [6];
  
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  KeInitializeEvent(local_38 + 2,1,0);
  lVar2 = IoBuildDeviceIoControlRequest
                    (0x90350,*(undefined8 *)(param_1 + 0x10),param_3,param_4,0,0,0,local_38 + 2,
                     local_38);
  if (lVar2 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
              &WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids);
    }
    uVar3 = 0xc000009a;
  }
  else {
    lVar1 = *(longlong *)(lVar2 + 0xb8);
    *(undefined8 *)(lVar1 + -0x18) = *(undefined8 *)(param_1 + 8);
    *(undefined1 *)(lVar1 + -0x48) = 0xd;
    uVar3 = IofCallDriver(*(undefined8 *)(param_1 + 0x10),lVar2);
    if (-1 < (int)uVar3) {
      KeWaitForSingleObject(local_38 + 2,0,0,0,0);
      uVar3 = local_38[0] & 0xffffffff;
    }
  }
  return uVar3;
}



===== WPP_SF_DDD @ 1c0003d68 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids,param_2,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_IDD @ 1c0003dcc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_IDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids,0xc,&local_res20,8,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_IDDI @ 1c0003e34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_IDDI(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  undefined4 local_18 [6];
  
  local_18[0] = 0x34;
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids,0x26,&local_res20,8,
             local_18,4,&param_6,4,&param_7,8,0);
  return;
}



===== WPP_SF_IDI @ 1c0003eb8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_IDI(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  undefined4 local_18 [6];
  
  local_18[0] = 8;
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids,0x23,&local_res20,8,
             local_18,4,&param_6,8,0);
  return;
}



===== WPP_SF_Id @ 1c0003f24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Id(undefined8 param_1)

{
  undefined4 local_18 [2];
  undefined8 local_10 [2];
  
  local_10[0] = 0x28;
  local_18[0] = 0xc0000017;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids,0x28,local_10,8,local_18,
             4,0);
  return;
}



===== WPP_SF_qId @ 1c0003f8c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qId(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids,param_2,&local_res20,8,
             &param_5,8,&param_6,4,0);
  return;
}



===== WPP_SF_qq @ 1c0003ff4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids,param_2,&local_res20,8,
             &param_5,8,0);
  return;
}



===== WPP_SF_qqDD @ 1c000404c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids,param_2,&local_res20,8,
             &param_5,8,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_qqDI @ 1c00040c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqDI(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids,0x2a,&local_res20,8,
             &param_5,8,&param_6,4,&param_7,8,0);
  return;
}



===== WPP_SF_qqDI_guid_Z @ 1c0004134 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqDI_guid_Z(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                       undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined8 param_8,
                       wchar_t *param_9)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  wchar_t wVar3;
  undefined8 local_res20;
  
  if (param_9 == (wchar_t *)0x0) {
    wVar3 = L'\b';
  }
  else {
    wVar3 = *param_9;
    if (*param_9 != L'\0') {
      pwVar2 = *(wchar_t **)(param_9 + 4);
      goto LAB_1c0004172;
    }
  }
  pwVar2 = L"NULL";
LAB_1c0004172:
  pwVar1 = param_9;
  if (param_9 == (wchar_t *)0x0) {
    pwVar1 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids,0x1d,&local_res20,8,
             &param_5,8,&param_6,4,&param_7,8,param_8,0x10,pwVar1,2,pwVar2,wVar3,0);
  return;
}



===== WPP_SF_qqDIiDD_guid_Z @ 1c000423c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqDIiDD_guid_Z
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined8 param_11,wchar_t *param_12)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  wchar_t wVar3;
  undefined8 local_res20;
  
  if (param_12 == (wchar_t *)0x0) {
    wVar3 = L'\b';
  }
  else {
    wVar3 = *param_12;
    if (*param_12 != L'\0') {
      pwVar2 = *(wchar_t **)(param_12 + 4);
      goto LAB_1c000427a;
    }
  }
  pwVar2 = L"NULL";
LAB_1c000427a:
  pwVar1 = param_12;
  if (param_12 == (wchar_t *)0x0) {
    pwVar1 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids,0x30,&local_res20,8,
             &param_5,8,&param_6,4,&param_7,8,&param_8,8,&param_9,4,&param_10,4,param_11,0x10,pwVar1
             ,2,pwVar2,wVar3,0);
  return;
}



===== WPP_SF_diid @ 1c000438c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_diid(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_159b873bf96b3f027a476325038fd206_Traceguids,0x1d,local_res20,4,
             &param_5,8,&param_6,8,&param_7,4,0);
  return;
}



===== _guard_check_icall @ 1c0004410 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0004428 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000444c =====

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



===== __cpu_features_init @ 1c00044c0 =====

/* WARNING: Removing unreachable block (ram,0x0001c000452a) */
/* WARNING: Removing unreachable block (ram,0x0001c00044d9) */
/* WARNING: Removing unreachable block (ram,0x0001c00044ca) */

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



===== __security_check_cookie @ 1c0004590 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c00045d0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0004600 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0004600. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0004630 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0004680 =====

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



===== memset @ 1c0004980 =====

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



===== __memset_repmovs @ 1c0004ac0 =====

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



===== __memset_query @ 1c0004b40 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0004bc0 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0004d00 =====

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



===== __memset_spec_plain @ 1c0004d80 =====

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



===== PVhdExecuteScsiRequestDisk @ 1c0005010 =====

void PVhdExecuteScsiRequestDisk(longlong param_1,longlong *param_2,ulonglong param_3)

{
  byte bVar1;
  longlong lVar2;
  longlong *plVar3;
  char cVar4;
  
  lVar2 = param_2[1];
  plVar3 = (longlong *)*param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    bVar1 = *(byte *)(lVar2 + 0x10);
    param_3 = (ulonglong)bVar1;
    WPP_SF_qDqZ_guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_1 + 0x40,param_3,param_2,
                      bVar1,(char)param_1,(wchar_t *)(param_1 + 0x40),param_1 + 0x28);
  }
  *plVar3 = param_1;
  cVar4 = *(char *)(lVar2 + 0x10);
  if (cVar4 == '\b') {
LAB_1c00050c0:
    cVar4 = '\0';
  }
  else {
    if (cVar4 != '\n') {
      if (cVar4 == '(') goto LAB_1c00050c0;
      if (cVar4 != '*') {
        if (cVar4 == -0x78) goto LAB_1c00050c0;
        if (cVar4 != -0x76) {
          if (cVar4 == -0x58) goto LAB_1c00050c0;
          if (cVar4 != -0x56) {
            PVhdScsiRequest(param_1,param_2,param_3);
            goto LAB_1c00050ce;
          }
        }
      }
    }
    cVar4 = '\x01';
  }
  PVhdScsiReadWrite(param_1,(char *)param_2,cVar4);
LAB_1c00050ce:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,
               &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_2,(char)param_1,0);
  }
  return;
}



===== PVhdStartMetaCompletionRoutine @ 1c0005130 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 PVhdStartMetaCompletionRoutine(undefined8 param_1,longlong param_2,longlong *param_3)

{
  longlong *plVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined2 uVar7;
  longlong lVar8;
  longlong *plVar9;
  undefined1 uVar10;
  
  plVar1 = param_3 + 1;
  puVar5 = (undefined4 *)*plVar1;
  lVar8 = param_2;
  plVar9 = param_3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    lVar8 = *param_3 + 0x40;
    WPP_SF_qZqdI(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar8,param_3,*param_3,(wchar_t *)lVar8,
                 (char)param_2,(char)*puVar5,(char)param_3[9]);
  }
  uVar2 = *(undefined4 *)(param_2 + 0x30);
  *(undefined8 *)(puVar5 + 4) = 0;
  puVar5[2] = uVar2;
  uVar3 = *(uint *)(param_2 + 0x38);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar8,plVar9,uVar2,(char)uVar3);
  }
  if ((int)puVar5[2] < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4b,
               &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,puVar5[2]);
    }
    goto LAB_1c0005312;
  }
  if (uVar3 < 0x10) {
    puVar5[2] = 0xc0000023;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c0005312;
    uVar7 = 0x4c;
    uVar10 = 0x10;
  }
  else {
    iVar4 = *(int *)(*(longlong *)(param_2 + 0x18) + 4);
    if (iVar4 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4d,
                 &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,iVar4);
      }
      puVar5[2] = iVar4;
      goto LAB_1c0005312;
    }
    piVar6 = (int *)*plVar1;
    if ((*piVar6 != 0) || ((short)piVar6[10] != 3)) goto LAB_1c0005312;
    if (0x13 < uVar3) {
      **(undefined4 **)(piVar6 + 8) = (int)param_3[10];
      *(undefined8 *)(puVar5 + 4) = 4;
      goto LAB_1c0005312;
    }
    puVar5[2] = 0xc0000023;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c0005312;
    uVar7 = 0x4e;
    uVar10 = 0x14;
  }
  WPP_SF_qZqddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,plVar9,*param_3,
                (wchar_t *)(*param_3 + 0x40),(char)plVar1,(char)uVar3,uVar10);
LAB_1c0005312:
  (*(code *)param_3[2])(param_3[3]);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4f,
             &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,0xc0000016);
  }
  return 0xc0000016;
}



===== PVhdChangeTrackingGetParameters @ 1c000b010 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PVhdChangeTrackingGetParameters(longlong param_1,undefined8 *param_2)

{
  longlong *plVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  undefined1 auStackY_e8 [32];
  int local_b8 [2];
  ulonglong uStack_b0;
  undefined4 local_a8 [2];
  longlong local_a0;
  undefined4 local_98;
  undefined8 local_90;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_e8;
  uVar3 = 0x78;
  memset(local_a8,0,0x78);
  local_b8[0] = 0;
  local_b8[1] = 0;
  uStack_b0 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5c,uVar3,param_1,
              (wchar_t *)(param_1 + 0x40));
  }
  local_a8[0] = 0x2002008;
  *param_2 = 0;
  param_2[1] = 0;
  LOCK();
  plVar1 = (longlong *)(param_1 + 0x38);
  local_a0 = *plVar1;
  *plVar1 = *plVar1 + 1;
  UNLOCK();
  puVar4 = local_a8;
  local_a0 = local_a0 + 1;
  PVhdTunneledFsCtrl(*(undefined8 *)(param_1 + 8),*(longlong *)(param_1 + 0x10),(longlong)puVar4,
                     0x10,0x20,local_b8);
  iVar2 = local_b8[0];
  if ((local_b8[0] < 0) || (uStack_b0 < 0x20)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      WPP_SF_qdI(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5d,puVar4,param_1,(char)local_b8[0],
                 (char)local_a0);
    }
    if (-1 < iVar2) {
      iVar2 = -0x3fffff1b;
    }
  }
  else {
    *(undefined4 *)param_2 = local_98;
    param_2[1] = local_90;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5e,
              &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_1,(char)iVar2);
  }
  return iVar2;
}



===== PVhdChangeTrackingSetParameters @ 1c000b1a0 =====

undefined8 PVhdChangeTrackingSetParameters(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x67,param_3,param_1,
                (wchar_t *)(param_1 + 0x40));
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x68,
                &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_1,2);
    }
  }
  return 0xc0000002;
}



===== PVhdChangeTrackingStart @ 1c000b240 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PVhdChangeTrackingStart(longlong param_1,longlong param_2,undefined8 param_3)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined2 uVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined1 auStackY_88 [32];
  int local_58 [4];
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_88;
  local_58[0] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  local_58[3] = 0;
  local_48 = 0;
  uStack_40 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5f,param_3,param_1,
              (wchar_t *)(param_1 + 0x40));
  }
  uVar9 = *(uint *)(param_2 + 4);
  uVar4 = uVar9 + 0x48;
  if (uVar4 < 0x48) {
    iVar7 = -0x3fffff6b;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3fffff6b;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c000b426;
    uVar6 = 0x60;
  }
  else {
    param_3 = 0x54507070;
    puVar5 = (undefined4 *)ExAllocatePool2(0x100,uVar4);
    if (puVar5 != (undefined4 *)0x0) {
      ClusKRTLGenerateGuid(&local_48);
      *puVar5 = 0x2002009;
      LOCK();
      plVar1 = (longlong *)(param_1 + 0x38);
      lVar2 = *plVar1;
      *plVar1 = *plVar1 + 1;
      UNLOCK();
      *(longlong *)(puVar5 + 2) = lVar2 + 1;
      *(undefined8 *)(puVar5 + 4) = local_48;
      *(undefined8 *)(puVar5 + 6) = uStack_40;
      *(undefined1 *)(puVar5 + 0x10) = *(undefined1 *)(param_2 + 0x20);
      *(undefined8 *)(puVar5 + 0xe) = *(undefined8 *)(param_2 + 0x18);
      uVar3 = *(undefined8 *)(param_2 + 0x10);
      *(undefined8 *)(puVar5 + 10) = *(undefined8 *)(param_2 + 8);
      *(undefined8 *)(puVar5 + 0xc) = uVar3;
      puVar5[9] = *(undefined4 *)(param_2 + 4);
      puVar5[8] = 0x38;
      if (uVar9 != 0) {
        memcpy(puVar5 + 0x12,(void *)(param_2 + 0x28),(ulonglong)uVar9);
      }
      puVar8 = puVar5;
      PVhdTunneledFsCtrl(*(undefined8 *)(param_1 + 8),*(longlong *)(param_1 + 0x10),(longlong)puVar5
                         ,uVar4,0x10,local_58);
      iVar7 = local_58[0];
      if (((local_58[0] < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29])))
         ) {
        WPP_SF_qdI(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x62,puVar8,param_1,(char)local_58[0],
                   (char)*(undefined8 *)(puVar5 + 2));
      }
      ExFreePoolWithTag(puVar5,0x54507070);
      goto LAB_1c000b426;
    }
    iVar7 = -0x3fffff66;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3fffff66;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c000b426;
    uVar6 = 0x61;
    uVar9 = uVar4;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,param_3,uVar9);
LAB_1c000b426:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),99,
              &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_1,(char)iVar7);
  }
  return iVar7;
}



===== PVhdChangeTrackingStop @ 1c000b490 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PVhdChangeTrackingStop(longlong param_1,undefined8 param_2,undefined4 *param_3)

{
  longlong *plVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  undefined1 auStackY_e8 [32];
  int local_b8 [2];
  ulonglong uStack_b0;
  undefined4 local_a8 [2];
  longlong local_a0;
  undefined4 local_98;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_e8;
  uVar3 = 0x78;
  memset(local_a8,0,0x78);
  local_b8[0] = 0;
  local_b8[1] = 0;
  uStack_b0 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),100,uVar3,param_1,
              (wchar_t *)(param_1 + 0x40));
  }
  local_a8[0] = 0x200200a;
  *param_3 = 0;
  LOCK();
  plVar1 = (longlong *)(param_1 + 0x38);
  local_a0 = *plVar1;
  *plVar1 = *plVar1 + 1;
  UNLOCK();
  puVar4 = local_a8;
  local_a0 = local_a0 + 1;
  PVhdTunneledFsCtrl(*(undefined8 *)(param_1 + 8),*(longlong *)(param_1 + 0x10),(longlong)puVar4,
                     0x10,0x14,local_b8);
  iVar2 = local_b8[0];
  if ((local_b8[0] < 0) || (uStack_b0 < 0x14)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      WPP_SF_qdI(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x65,puVar4,param_1,(char)local_b8[0],
                 (char)local_a0);
    }
    if (-1 < iVar2) {
      iVar2 = -0x3fffff1b;
    }
  }
  else {
    *param_3 = local_98;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x66,
              &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_1,(char)iVar2);
  }
  return iVar2;
}



===== PVhdCleanupMetaOperation @ 1c000b610 =====

void PVhdCleanupMetaOperation(longlong *param_1,undefined8 param_2,undefined8 param_3)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x75,param_3,*param_1,
              (wchar_t *)(*param_1 + 0x40));
  }
  if (param_1[7] != 0) {
    IoFreeIrp();
  }
  ExFreePoolWithTag(param_1,0x54507070);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x76,
            &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids);
  }
  return;
}



===== PVhdCloseDisk @ 1c000b6c0 =====

void PVhdCloseDisk(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_2 = 0x2a;
    WPP_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,param_3,param_1,
              (wchar_t *)(param_1 + 8));
  }
  if (*(char *)((longlong)param_1 + 0x56) != '\0') {
    PVhdDismountDisk((longlong)param_1,param_2,param_3);
  }
  ObfDereferenceObjectWithTag(param_1[1],0x54527070);
  ZwClose(*param_1);
  IoFreeIrp(param_1[0xb]);
  ExFreePoolWithTag(param_1[0xc],0x54507070);
  ExFreePoolWithTag(param_1,0x54507070);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
              &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_1,0);
  }
  return;
}



===== PVhdCopyCdpSnapshotInformation @ 1c000b7bc =====

undefined8 PVhdCopyCdpSnapshotInformation(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined2 uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(param_1 + 0x38);
  uVar4 = *(uint *)(param_1 + 0x30);
  if (uVar4 == uVar5) {
    uVar4 = *(uint *)(param_1 + 0x34);
    if (uVar4 == 100) {
      uVar1 = *(undefined8 *)(param_1 + 0x3c);
      uVar2 = *(undefined8 *)(param_1 + 0x44);
      *(uint *)(param_2 + 0xa0) = uVar5;
      *(undefined4 *)(param_2 + 0x9c) = 0x18;
      *(undefined8 *)(param_2 + 0xa4) = uVar1;
      *(undefined8 *)(param_2 + 0xac) = uVar2;
      *(uint *)(param_2 + 0x98) = uVar5;
      memcpy((void *)(param_2 + 0xb4),(void *)(param_1 + 100),(ulonglong)uVar5);
      return 0;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000000d;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return 0xc000000d;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc000000d;
    }
    uVar3 = 0x70;
    uVar5 = 100;
  }
  else {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000000d;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return 0xc000000d;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc000000d;
    }
    uVar3 = 0x6f;
  }
  WPP_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,WPP_GLOBAL_Control,param_1,(char)uVar4
             ,(char)uVar5);
  return 0xc000000d;
}



===== PVhdDeleteSnapshot @ 1c000b8a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PVhdDeleteSnapshot(longlong param_1,undefined8 *param_2,undefined8 param_3)

{
  longlong *plVar1;
  int iVar2;
  ulonglong uVar3;
  undefined1 auStackY_108 [32];
  ulonglong local_b8 [2];
  undefined4 local_a8 [2];
  longlong local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  byte local_88;
  uint local_84;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_108;
  local_b8[0] = 0;
  local_b8[1] = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qZ_guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_1 + 0x40,param_3,param_1,
                     (wchar_t *)(param_1 + 0x40),param_2,(char)*(undefined2 *)(param_2 + 2));
  }
  memset(local_a8,0,0x78);
  local_a8[0] = 0x2002006;
  LOCK();
  plVar1 = (longlong *)(param_1 + 0x38);
  local_a0 = *plVar1;
  *plVar1 = *plVar1 + 1;
  UNLOCK();
  local_98 = *param_2;
  uStack_90 = param_2[1];
  local_a0 = local_a0 + 1;
  local_84 = (uint)*(ushort *)(param_2 + 2);
  local_88 = *(byte *)((longlong)param_2 + 0x14) >> 1 & 1;
  PVhdTunneledFsCtrl(*(undefined8 *)(param_1 + 8),*(longlong *)(param_1 + 0x10),(longlong)local_a8,
                     0x28,0x10,(int *)local_b8);
  uVar3 = local_b8[0];
  iVar2 = (int)local_b8[0];
  if ((int)local_b8[0] < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_1c000ba0c;
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qZ_guid_ddI(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
                         (ulonglong)*(ushort *)(param_2 + 2),param_1 + 0x40,param_1,
                         (wchar_t *)(param_1 + 0x40),param_2,(char)*(ushort *)(param_2 + 2),
                         (char)local_b8[0],(char)local_a0);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x79,
             &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,iVar2);
  }
LAB_1c000ba0c:
  return uVar3 & 0xffffffff;
}



===== PVhdDismountDisk @ 1c000ba40 =====

void PVhdDismountDisk(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,param_3,param_1,
              (wchar_t *)(param_1 + 0x40));
  }
  *(undefined1 *)(param_1 + 0x56) = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
              &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_1,0);
  }
  return;
}



===== PVhdGetHostname @ 1c000bad4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PVhdGetHostname(wchar_t *param_1)

{
  int iVar1;
  code *pcVar2;
  undefined1 *puVar3;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined1 local_78 [8];
  undefined4 local_70;
  wchar_t *local_68;
  wchar_t *local_60;
  undefined4 local_58;
  wchar_t *local_50;
  undefined4 local_48;
  
  memset(local_78,0,0x70);
  RtlInitUnicodeString(param_1,0);
  local_48 = 0;
  local_68 = L"ComputerName";
  local_70 = 0x124;
  local_88 = 0;
  uStack_80 = 0;
  local_58 = 0x1000000;
  local_60 = param_1;
  local_50 = param_1;
  RtlInitUnicodeString(&local_88,L"RtlQueryRegistryValuesEx");
  pcVar2 = (code *)MmGetSystemRoutineAddress(&local_88);
  puVar3 = local_78;
  if (pcVar2 == (code *)0x0) {
    pcVar2 = RtlQueryRegistryValues_exref;
  }
  iVar1 = (*pcVar2)(2,L"ComputerName\\ComputerName",puVar3,0,0);
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,iVar1);
    }
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,puVar3,param_1);
  }
  return iVar1;
}



===== PVhdGetQoSStatusDisk @ 1c000bc20 =====

undefined8
PVhdGetQoSStatusDisk
          (longlong param_1,void *param_2,ulonglong param_3,undefined8 param_4,undefined8 param_5)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x47,param_3,param_1,
              (wchar_t *)(param_1 + 0x40));
  }
  *(undefined8 *)(param_1 + 0x70) = param_5;
  *(undefined8 *)(param_1 + 0x68) = param_4;
  memcpy(*(void **)(param_1 + 0x60),param_2,param_3 & 0xffffffff);
  lVar1 = *(longlong *)(param_1 + 0x58);
  IoReuseIrp(lVar1,0x103);
  lVar2 = *(longlong *)(lVar1 + 0xb8);
  *(void **)(lVar1 + 0x98) = SystemReserved1[0xf];
  *(undefined8 *)(lVar2 + -0x18) = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(lVar2 + -0x20) = *(undefined8 *)(param_1 + 0x10);
  *(undefined1 *)(lVar2 + -0x48) = 0xd;
  *(undefined4 *)(lVar2 + -0x30) = 0x90350;
  *(int *)(lVar2 + -0x38) = (int)param_3;
  *(undefined4 *)(lVar2 + -0x40) = 0x60;
  *(undefined8 *)(lVar1 + 0x18) = *(undefined8 *)(param_1 + 0x60);
  lVar3 = *(longlong *)(lVar1 + 0xb8);
  *(code **)(lVar3 + -0x10) = PvhdQoSStatusRequestCompletion;
  *(longlong *)(lVar3 + -8) = param_1;
  *(undefined1 *)(lVar3 + -0x45) = 0xe0;
  IofCallDriver(*(undefined8 *)(lVar2 + -0x20),lVar1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x48,
              &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_1,3);
  }
  return 0x103;
}



===== PVhdHandleQueryInformationDiskVhdSet @ 1c000bd84 =====

int PVhdHandleQueryInformationDiskVhdSet
              (longlong param_1,undefined8 param_2,uint *param_3,uint param_4,int *param_5,
              uint *param_6)

{
  longlong *plVar1;
  int *piVar2;
  uint *puVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  uint *puVar8;
  int iVar9;
  undefined4 *puVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  undefined4 *puVar15;
  ulonglong local_res8;
  int *piVar16;
  int local_38 [2];
  ulonglong uStack_30;
  
  puVar8 = param_6;
  param_6 = (uint *)0x0;
  local_res8 = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  uStack_30 = 0;
  uVar5 = *puVar8;
  if ((param_4 < 0x20) || (uVar5 < 0x238)) {
    return -0x3fffffdd;
  }
  memset(param_5,0,(ulonglong)uVar5);
  uVar13 = (ulonglong)*puVar8 + 0x10;
  if (uVar13 < 0x10) {
    return -0x3fffff6b;
  }
  uVar14 = 0x54507070;
  puVar10 = (undefined4 *)ExAllocatePool2(0x100,uVar13);
  if (puVar10 == (undefined4 *)0x0) {
    return -0x3fffff66;
  }
  *puVar10 = 0x2002005;
  LOCK();
  plVar1 = (longlong *)(param_1 + 0x38);
  lVar4 = *plVar1;
  *plVar1 = *plVar1 + 1;
  UNLOCK();
  piVar2 = puVar10 + 4;
  *(longlong *)(puVar10 + 2) = lVar4 + 1;
  puVar3 = param_3 + 2;
  uVar7 = *(undefined8 *)(param_3 + 4);
  *(undefined8 *)(puVar10 + 6) = *(undefined8 *)puVar3;
  *(undefined8 *)(puVar10 + 8) = uVar7;
  puVar10[5] = (uint)(byte)param_3[6];
  uVar6 = *param_3;
  if (uVar6 < 0x207) {
    if ((uVar6 != 0x206) && (uVar6 != 0x201)) {
      if (uVar6 == 0x202) {
        *piVar2 = 2;
      }
      else if ((uVar6 != 0x203) && (uVar6 != 0x204)) {
        if (uVar6 != 0x205) {
LAB_1c000beab:
          iVar9 = -0x3ffffff0;
          goto LAB_1c000c087;
        }
        *piVar2 = 5;
      }
    }
  }
  else if (uVar6 != 0x207) {
    if (uVar6 == 0x208) {
      *piVar2 = 8;
    }
    else if (uVar6 != 0x280) {
      if (uVar6 == 0x281) {
        *piVar2 = 10;
      }
      else {
        if (uVar6 != 0x283) goto LAB_1c000beab;
        *piVar2 = 0xc;
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qi_guid_ddi(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar3,uVar14,param_1,
                       (char)*(undefined8 *)(puVar10 + 2),puVar3,(char)*param_3,(char)param_3[6],
                       (char)uVar13);
  }
  piVar16 = local_38;
  puVar15 = puVar10;
  PVhdTunneledFsCtrl(*(undefined8 *)(param_1 + 8),*(longlong *)(param_1 + 0x10),(longlong)puVar10,
                     0x28,(int)uVar13,piVar16);
  iVar9 = local_38[0];
  if (local_38[0] < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qid(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,puVar15,param_1,
                 (char)*(undefined8 *)(puVar10 + 2),(char)local_38[0]);
    }
  }
  else if (uStack_30 < 0x10) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qiii(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,uStack_30,param_1,
                  (char)*(undefined8 *)(puVar10 + 2),piVar16,(char)uStack_30);
    }
    iVar9 = -0x3fffffdd;
  }
  else {
    uVar13 = uStack_30 - 0x10;
    uVar12 = uVar13;
    uVar11 = SvRtlProtoRsvdToVirtstorVhdSetQueryInformationResponse
                       (piVar2,uVar13,param_5,(ulonglong)uVar5,(ulonglong *)&param_6,&local_res8);
    iVar9 = (int)uVar11;
    *puVar8 = (uint)param_6;
    if (((iVar9 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      WPP_SF_qidiiii(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar12,WPP_GLOBAL_Control,param_1,
                     (char)*(undefined8 *)(puVar10 + 2),(char)uVar11,(char)uVar13,(char)uVar5,
                     (char)param_6,(char)local_res8);
    }
  }
LAB_1c000c087:
  ExFreePoolWithTag(puVar10,0x54507070);
  return iVar9;
}



===== PVhdMountDisk @ 1c000c0d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
PVhdMountDisk(longlong param_1,undefined4 param_2,undefined8 *param_3,undefined4 *param_4)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 auStackY_f8 [32];
  undefined2 local_b8 [2];
  undefined4 local_b4;
  undefined8 local_b0;
  undefined8 uStack_a8;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_f8;
  uVar2 = 0;
  uVar3 = 0x80;
  memset(local_b8,0,0x80);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar2 = 0x38;
    WPP_SF_DqZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,uVar3,param_2,(char)param_1,
               (wchar_t *)(param_1 + 0x40));
  }
  *(undefined1 *)(param_1 + 0x56) = 1;
  *(byte *)(param_1 + 0x55) = (byte)param_2 & 1;
  if ((char)(byte)param_2 < '\0') {
    local_b0 = *param_3;
    uStack_a8 = param_3[1];
    local_b4 = 1;
    local_b8[0] = 0x101;
    uVar1 = PvhdSynchronouslFsctl(param_1,uVar2,local_b8,0x80);
    if ((((int)uVar1 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      WPP_SF_qZd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,uVar1 & 0xffffffff,param_1,
                 (wchar_t *)(param_1 + 0x40),(char)uVar1);
    }
  }
  *param_4 = 0x28;
  *(undefined1 *)(param_4 + 1) = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3a,
              &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_1,0);
  }
  return 0;
}



===== PVhdOpenDisk @ 1c000c240 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PVhdOpenDisk(wchar_t *param_1,uint param_2,longlong *param_3,undefined8 param_4,
                      undefined8 *param_5)

{
  ulonglong uVar1;
  wchar_t *pwVar2;
  uint uVar3;
  int iVar4;
  longlong *plVar5;
  ulonglong uVar6;
  longlong lVar7;
  wchar_t wVar8;
  undefined2 uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  char *pcVar13;
  undefined4 *puVar14;
  undefined8 *puVar15;
  undefined1 auStackY_1f8 [32];
  char local_178;
  char local_177 [7];
  undefined4 *local_170;
  undefined8 *local_168;
  undefined4 local_160;
  wchar_t local_158 [4];
  void *pvStack_150;
  undefined8 *local_140;
  undefined8 local_138;
  longlong alStack_130 [4];
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  wchar_t *local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  char acStack_c8 [32];
  undefined4 local_a8;
  undefined1 local_a3;
  undefined2 local_a2;
  char local_a0 [29];
  longlong local_83;
  longlong lStack_7b;
  undefined4 local_70;
  undefined4 local_6c;
  char local_68 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_1f8;
  local_140 = param_5;
  local_170 = (undefined4 *)0x0;
  local_168 = (undefined8 *)0x0;
  local_178 = '\0';
  local_177[0] = '\0';
  alStack_130[3] = 0;
  plVar5 = (longlong *)0x0;
  local_100 = 0;
  uStack_f8 = 0;
  local_f0 = (wchar_t *)0x0;
  uStack_e8 = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  local_110 = 0;
  uStack_108 = 0;
  local_158[0] = L'\0';
  local_158[1] = L'\0';
  local_158[2] = L'\0';
  local_158[3] = L'\0';
  pvStack_150 = (void *)0x0;
  local_138 = 0;
  alStack_130[0] = 0;
  alStack_130[1] = 0;
  alStack_130[2] = 0;
  memset(&local_a8,0,0x5c);
  uVar6 = (ulonglong)(ushort)*param_1;
  uVar11 = (ulonglong)PVhdFileStreamNameSuffix;
  local_d0 = 0;
  acStack_c8[0] = '\0';
  acStack_c8[1] = '\0';
  acStack_c8[2] = '\0';
  acStack_c8[3] = '\0';
  acStack_c8[4] = '\0';
  acStack_c8[5] = '\0';
  acStack_c8[6] = '\0';
  acStack_c8[7] = '\0';
  acStack_c8[0x18] = '\0';
  acStack_c8[0x19] = '\0';
  acStack_c8[0x1a] = '\0';
  acStack_c8[0x1b] = '\0';
  acStack_c8[8] = '\0';
  acStack_c8[9] = '\0';
  acStack_c8[10] = '\0';
  acStack_c8[0xb] = '\0';
  acStack_c8[0xc] = '\0';
  acStack_c8[0xd] = '\0';
  acStack_c8[0xe] = '\0';
  acStack_c8[0xf] = '\0';
  acStack_c8[0x10] = '\0';
  acStack_c8[0x11] = '\0';
  acStack_c8[0x12] = '\0';
  acStack_c8[0x13] = '\0';
  acStack_c8[0x14] = '\0';
  acStack_c8[0x15] = '\0';
  acStack_c8[0x16] = '\0';
  acStack_c8[0x17] = '\0';
  uVar10 = uVar6 + uVar11;
  local_160 = 0;
  if (uVar10 < uVar6) {
    uVar10 = 0xc0000095;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,uVar11,(uint)(ushort)*param_1,
                (char)PVhdFileStreamNameSuffix);
    }
    goto LAB_1c000ce01;
  }
  uVar1 = uVar10 + 0x78;
  if (uVar1 < uVar10) {
    uVar10 = 0xc0000095;
    goto LAB_1c000ce01;
  }
  if (0xffff < uVar10) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_IZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,uVar11,uVar10,param_1);
    }
    uVar10 = 0xc000000d;
    goto LAB_1c000ce01;
  }
  uVar12 = 0x54507070;
  plVar5 = (longlong *)ExAllocatePool2(0x40,uVar1);
  if (plVar5 == (longlong *)0x0) {
    uVar10 = 0xc000009a;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_I(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
               (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),uVar12,uVar1);
    }
    goto LAB_1c000ce01;
  }
  pwVar2 = (wchar_t *)(plVar5 + 8);
  *(short *)((longlong)plVar5 + 0x42) = (short)uVar10;
  *pwVar2 = L'\0';
  pcVar13 = local_177;
  plVar5[9] = (longlong)(plVar5 + 0xf);
  uVar6 = ClusKRTLDetermineVhdFileType((ushort *)param_1,&local_178,pcVar13);
  uVar10 = uVar6 & 0xffffffff;
  if ((int)uVar6 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_Zd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
                (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),pcVar13,param_1,(char)uVar6);
    }
  }
  else if ((local_178 == '\0') && (local_177[0] == '\0')) {
    uVar10 = 0xc05cff08;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,pcVar13,param_1);
    }
  }
  else {
    RtlAppendUnicodeStringToString(pwVar2,param_1);
    RtlAppendUnicodeStringToString(pwVar2,&PVhdFileStreamNameSuffix);
    uVar3 = RtlRandomEx(&RandSeed);
    plVar5[7] = (ulonglong)uVar3 << 0x20;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qIZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)uVar3 << 0x20,pcVar13,plVar5,
                 0,pwVar2);
    }
    uStack_f8 = 0;
    local_100 = CONCAT44(local_100._4_4_,0x30);
    uStack_e8 = CONCAT44(uStack_e8._4_4_,0x240);
    alStack_130[0] = 0;
    alStack_130[3] = 1;
    local_138 = 0x28;
    local_e0 = 0;
    uStack_d8 = 0;
    alStack_130[1] = 0;
    alStack_130[2] = 0;
    local_f0 = pwVar2;
    uVar3 = FsRtlAllocateExtraCreateParameterList(0,alStack_130);
    uVar10 = (ulonglong)uVar3;
    if ((int)uVar3 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar9 = 0x12;
LAB_1c000c88d:
        WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
                  &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,plVar5,(char)uVar10);
      }
    }
    else {
      uVar3 = FsRtlAllocateExtraCreateParameter(&GUID_ECP_OPEN_AS_BLOCK_DEVICE,0xc0,0,0);
      uVar10 = (ulonglong)uVar3;
      if ((int)uVar3 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar9 = 0x13;
          goto LAB_1c000c88d;
        }
      }
      else {
        memset(local_170,0,0xc0);
        *local_170 = 2;
        *local_170 = EcpContextVersion;
        local_170[6] = param_2;
        local_170[7] = 1;
        *(undefined1 *)(local_170 + 1) = 0;
        *(longlong *)(local_170 + 8) = plVar5[7];
        if (param_3 != (longlong *)0x0) {
          *(undefined1 *)(local_170 + 1) = 1;
          lVar7 = param_3[1];
          *(longlong *)(local_170 + 2) = *param_3;
          *(longlong *)(local_170 + 4) = lVar7;
          lVar7 = param_3[1];
          plVar5[5] = *param_3;
          plVar5[6] = lVar7;
        }
        iVar4 = PVhdGetHostname(local_158);
        if (-1 < iVar4) {
          wVar8 = L'~';
          if ((ushort)local_158[0] < 0x7f) {
            wVar8 = local_158[0];
          }
          *(wchar_t *)(local_170 + 10) = wVar8;
          memcpy((void *)((longlong)local_170 + 0x2a),pvStack_150,(ulonglong)(ushort)wVar8);
          ExFreePoolWithTag(pvStack_150,0);
          RtlInitUnicodeString(local_158,0);
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          puVar14 = local_170 + 2;
          if (*(char *)(local_170 + 1) == '\0') {
            puVar14 = (undefined4 *)0x0;
          }
          WPP_SF_qdddic_guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),WPP_GLOBAL_Control,puVar14,
                              plVar5,(char)*local_170,(char)local_170[6],(char)local_170[7],
                              (char)*(undefined8 *)(local_170 + 8),
                              (-(*(char *)(local_170 + 1) != '\0') & 0xbU) + 0x4e,puVar14);
        }
        uVar3 = FsRtlInsertExtraCreateParameter(alStack_130[0],local_170);
        uVar10 = (ulonglong)uVar3;
        if ((int)uVar3 < 0) {
          FsRtlFreeExtraCreateParameter(local_170);
          local_170 = (undefined4 *)0x0;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar9 = 0x15;
            goto LAB_1c000c88d;
          }
        }
        else {
          uVar3 = FsRtlAllocateExtraCreateParameter(&GUID_ECP_NETWORK_OPEN_CONTEXT,0x1c,0);
          uVar10 = (ulonglong)uVar3;
          if ((int)uVar3 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar9 = 0x16;
              goto LAB_1c000c88d;
            }
          }
          else {
            *local_168 = 0;
            local_168[1] = 0;
            local_168[2] = 0;
            *(undefined4 *)(local_168 + 3) = 0;
            *(undefined2 *)local_168 = 0x1c;
            *(undefined4 *)(local_168 + 1) = 0;
            *(undefined4 *)((longlong)local_168 + 4) = 0;
            *(undefined4 *)((longlong)local_168 + 0xc) = 4;
            uVar3 = FsRtlInsertExtraCreateParameter(alStack_130[0]);
            uVar10 = (ulonglong)uVar3;
            if ((int)uVar3 < 0) {
              FsRtlFreeExtraCreateParameter(local_168);
              local_168 = (undefined8 *)0x0;
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                uVar9 = 0x17;
                goto LAB_1c000c88d;
              }
            }
            else {
              uVar12 = 0x20080;
              if ((param_2 & 8) == 0) {
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                   (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                  WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                           &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,plVar5);
                }
                uVar12 = 0x20083;
                local_48 = 0;
                uStack_40 = 0;
                if ((param_3 != (longlong *)0x0) && ((*param_3 != 0 || (param_3[1] != 0)))) {
                  memset(&local_a8,0,0x5c);
                  local_160 = 0x5c;
                  local_a3 = 0x1c;
                  local_a8 = 0x38;
                  local_a2 = 0x10;
                  builtin_strncpy(local_a0 + 0x18,"ance",5);
                  builtin_strncpy(local_a0,"ClusteredApplicationInst",0x18);
                  builtin_strncpy(local_68 + 0x10,"icTy",4);
                  local_83 = *param_3;
                  lStack_7b = param_3[1];
                  local_68[0x14] = 'p';
                  local_68[0x15] = 'e';
                  local_68[0x16] = 0;
                  local_70 = 0;
                  local_6c = 0x21600;
                  builtin_strncpy(local_68,"ApplicationTraff",0x10);
                  local_68[0x17] = '\x01';
                  local_68[0x18] = '\0';
                }
              }
              else {
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                   (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                  WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                           &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,plVar5);
                }
                builtin_strncpy(acStack_c8,"SmbDisableHandleDurability",0x1b);
                local_d0 = 0x1a0000000000;
                acStack_c8[0x1b] = '\0';
              }
              puVar15 = &local_100;
              uVar3 = IoCreateFileEx(plVar5,uVar12,puVar15,&local_110);
              if ((int)uVar3 < 0) {
                if ((uint)local_110 != 0) {
                  uVar3 = (uint)local_110;
                }
                uVar10 = (ulonglong)uVar3;
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                   (2 < (byte)WPP_GLOBAL_Control[0x29])) {
                  puVar15 = (undefined8 *)&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids;
                  WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                            &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,plVar5,(char)uVar3);
                }
                if (uVar3 == 0xc0000034) {
                  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
                    puVar15 = (undefined8 *)&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids;
                    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                             &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,plVar5);
                  }
                  uVar3 = PvhdCheckIfFileExistsAndVolumeSupportsMayhew(plVar5,param_1,puVar15);
                  uVar10 = (ulonglong)uVar3;
                  if (uVar3 != 0xc0000010) {
                    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
                      WPP_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,puVar15,plVar5,
                                 (char)uVar3,0x34);
                    }
                    uVar10 = 0xc0000034;
                  }
                }
                if (-1 < (int)uVar10) goto LAB_1c000ce01;
              }
              else {
                uVar3 = ObReferenceObjectByHandleWithTag
                                  (*plVar5,0,*(undefined8 *)IoFileObjectType_exref,0);
                uVar10 = (ulonglong)uVar3;
                if ((int)uVar3 < 0) {
                  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                              &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,plVar5,(char)uVar3);
                  }
                }
                else {
                  lVar7 = IoGetRelatedDeviceObject(plVar5[1]);
                  plVar5[2] = lVar7;
                  if (lVar7 == 0) {
                    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                               &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,plVar5);
                    }
                    goto LAB_1c000ce01;
                  }
                  uVar3 = PVhdQueryStartingInfo((longlong)plVar5);
                  uVar10 = (ulonglong)uVar3;
                  if (-1 < (int)uVar3) {
                    lVar7 = IoAllocateIrp(CONCAT71((int7)((ulonglong)plVar5[2] >> 8),
                                                   *(undefined1 *)(plVar5[2] + 0x4c)),0);
                    plVar5[0xb] = lVar7;
                    if (lVar7 == 0) {
                      uVar10 = 0xc000009a;
                    }
                    else {
                      lVar7 = ExAllocatePool2(0x40,0x480,0x54507070);
                      plVar5[0xc] = lVar7;
                      if (lVar7 != 0) {
                        *(byte *)((longlong)plVar5 + 0x54) = (byte)param_2 & 1;
                        *(byte *)((longlong)plVar5 + 0x55) = (byte)(param_2 >> 2) & 1;
                        *local_140 = plVar5;
                        goto LAB_1c000ce01;
                      }
                      uVar10 = 0xc000009a;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if (plVar5[1] != 0) {
    ObfDereferenceObjectWithTag(plVar5[1],0x54527070);
    plVar5[1] = 0;
  }
  if (*plVar5 != 0) {
    ZwClose();
    *plVar5 = 0;
  }
  if (plVar5[0xb] != 0) {
    IoFreeIrp();
    plVar5[0xb] = 0;
  }
  if (plVar5[0xc] != 0) {
    ExFreePoolWithTag(plVar5[0xc],0x54507070);
    plVar5[0xc] = 0;
  }
  ExFreePoolWithTag(plVar5,0x54507070);
  plVar5 = (longlong *)0x0;
LAB_1c000ce01:
  if (alStack_130[0] != 0) {
    FsRtlFreeExtraCreateParameterList();
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
              &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,plVar5,(char)uVar10);
  }
  return uVar10;
}



===== PVhdPrepareMetaOperation @ 1c000ce90 =====

ulonglong PVhdPrepareMetaOperation
                    (longlong param_1,uint *param_2,longlong *param_3,longlong param_4,
                    undefined8 *param_5)

{
  longlong *plVar1;
  undefined8 *puVar2;
  uint *puVar3;
  ushort uVar4;
  uint uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  longlong *plVar8;
  longlong lVar9;
  byte bVar10;
  longlong *plVar11;
  uint uVar12;
  ulonglong uVar13;
  char cVar14;
  char cVar15;
  longlong *_Size;
  uint uVar16;
  uint uVar17;
  bool bVar18;
  undefined4 local_res8;
  undefined1 uVar19;
  undefined1 uVar20;
  
  uVar5 = *param_2;
  uVar17 = 0;
  uVar12 = 0x24;
  uVar19 = SUB81(param_2,0);
  _Size = param_3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qZqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x50,param_3,param_1,
                (wchar_t *)(param_1 + 0x40),uVar19,(char)uVar5);
  }
  uVar7 = PVhdValidateMetaOperation(param_2);
  uVar13 = uVar7 & 0xffffffff;
  if ((int)uVar7 < 0) goto LAB_1c000d4f4;
  local_res8 = 0x10;
  if (uVar5 == 0) {
    uVar17 = param_2[0x16];
    _Size = (longlong *)0x3;
    bVar18 = (short)param_2[10] != 3;
    uVar12 = 0x74;
    if (bVar18) {
      uVar12 = 0x5c;
    }
    local_res8 = 0x14;
    if (bVar18) {
      local_res8 = 0x10;
    }
LAB_1c000cf48:
    uVar16 = uVar12 + uVar17;
    if (uVar12 <= uVar16) goto LAB_1c000cf55;
  }
  else {
    if (uVar5 == 3) {
      uVar17 = param_2[0x15];
      uVar12 = 0x5c;
      goto LAB_1c000cf48;
    }
    if (uVar5 == 4) {
      uVar17 = param_2[0xb];
      uVar12 = 0x30;
      goto LAB_1c000cf48;
    }
    if (uVar5 == 1) {
      uVar16 = 0x38;
    }
    else {
      if (uVar5 != 5) goto LAB_1c000cf48;
      uVar16 = 0x3c;
    }
LAB_1c000cf55:
    if (0xb7 < uVar17 + 0xb8) {
      uVar13 = 0;
      _Size = (longlong *)0x54507070;
      plVar8 = (longlong *)ExAllocatePool2(0x40);
      if (plVar8 == (longlong *)0x0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          _Size = (longlong *)&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids;
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x51,
                  &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids);
        }
        uVar13 = 0xc000009a;
        goto LAB_1c000d4f4;
      }
      *plVar8 = param_1;
      plVar8[1] = (longlong)param_2;
      plVar8[2] = (longlong)param_3;
      plVar8[3] = param_4;
      ClusKRTLGenerateGuid(plVar8 + 4);
      *(undefined4 *)(plVar8 + 8) = 0x2002101;
      LOCK();
      plVar1 = (longlong *)(param_1 + 0x38);
      lVar9 = *plVar1;
      *plVar1 = *plVar1 + 1;
      UNLOCK();
      plVar1 = plVar8 + 0xc;
      plVar11 = (longlong *)0x0;
      plVar8[9] = lVar9 + 1;
      plVar8[10] = plVar8[4];
      plVar8[0xb] = plVar8[5];
      uVar20 = (undefined1)(lVar9 + 1);
      if (uVar5 == 0) {
        *(undefined4 *)(plVar8 + 6) = 1;
        *(undefined4 *)plVar1 = 1;
        lVar9 = *(longlong *)(param_2 + 0x14);
        puVar3 = param_2 + 10;
        _Size = (longlong *)0x6;
        plVar8[0x11] = *(longlong *)(param_2 + 0x12);
        plVar8[0x12] = lVar9;
        uVar12 = *puVar3;
        *(undefined4 *)((longlong)plVar8 + 0x6c) = 0;
        plVar11 = plVar8 + 0xe;
        *(uint *)(plVar8 + 0xd) = (uint)(ushort)uVar12;
        do {
          *(undefined4 *)plVar11 =
               *(undefined4 *)((longlong)param_2 + (0x20 - (longlong)plVar1) + (longlong)plVar11);
          plVar11 = (longlong *)((longlong)plVar11 + 4);
          _Size = (longlong *)((longlong)_Size + -1);
        } while (_Size != (longlong *)0x0);
        if ((param_2[0xb] & 1) != 0) {
          *(uint *)((longlong)plVar8 + 0x6c) = *(uint *)((longlong)plVar8 + 0x6c) | 1;
        }
        if ((ushort)*puVar3 != 3) {
LAB_1c000d3db:
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_qZqd_guid_dddddddI
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_1 + 0x40,_Size,param_1,
                       (wchar_t *)(param_1 + 0x40),uVar19,(char)plVar8[0xd],plVar8 + 0x11,
                       (char)*(undefined4 *)((longlong)plVar8 + 0x6c),(char)plVar8[0xe],
                       (char)*(undefined4 *)((longlong)plVar8 + 0x74),(char)plVar8[0xf],
                       (char)*(undefined4 *)((longlong)plVar8 + 0x7c),(char)plVar8[0x10],
                       (char)*(undefined4 *)((longlong)plVar8 + 0x84),uVar20);
          }
          goto LAB_1c000d45f;
        }
        plVar11 = plVar8;
        uVar7 = PVhdCopyCdpSnapshotInformation((longlong)puVar3,(longlong)plVar8);
        uVar13 = uVar7 & 0xffffffff;
        if (-1 < (int)uVar7) goto LAB_1c000d3db;
      }
      else {
        if (uVar5 == 1) {
          *(undefined4 *)(plVar8 + 6) = 0;
          *(undefined4 *)plVar1 = 0;
          cVar14 = *(char *)((longlong)param_2 + 0x31);
          *(char *)((longlong)plVar8 + 0x71) = cVar14;
          uVar12 = param_2[0xc];
          *(char *)(plVar8 + 0xe) = (char)uVar12;
          lVar9 = *(longlong *)(param_2 + 10);
          plVar8[0xd] = lVar9;
          *(undefined1 *)((longlong)plVar8 + 0x72) = *(undefined1 *)((longlong)param_2 + 0x32);
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar7 = CONCAT71((int7)((ulonglong)_Size >> 8),-((char)uVar12 != '\0')) &
                    0xffffffffffffff0b;
            cVar15 = (char)uVar7 + 'N';
            _Size = (longlong *)CONCAT71((int7)(uVar7 >> 8),cVar15);
            bVar10 = (-(cVar14 != '\0') & 0xbU) + 0x4e;
            WPP_SF_qZqcciI(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)bVar10,_Size,
                           param_1,(wchar_t *)(param_1 + 0x40),uVar19,bVar10,cVar15,(char)lVar9,
                           uVar20);
          }
        }
        else if (uVar5 == 2) {
          *(undefined4 *)(plVar8 + 6) = 2;
          *(undefined4 *)plVar1 = 2;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_qZqI(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0,_Size,param_1,
                        (wchar_t *)(param_1 + 0x40),uVar19,uVar20);
          }
        }
        else if (uVar5 == 3) {
          *(undefined4 *)(plVar8 + 6) = 3;
          *(undefined4 *)plVar1 = 3;
          *(undefined4 *)(plVar8 + 0xe) = 0;
          if ((param_2[0xb] & 1) != 0) {
            *(undefined4 *)(plVar8 + 0xe) = 1;
          }
          *(uint *)(plVar8 + 0xd) = (uint)(ushort)param_2[10];
          uVar6 = *(undefined8 *)(param_2 + 0xe);
          *(undefined8 *)((longlong)plVar8 + 0x74) = *(undefined8 *)(param_2 + 0xc);
          *(undefined8 *)((longlong)plVar8 + 0x7c) = uVar6;
          uVar6 = *(undefined8 *)(param_2 + 0x12);
          *(undefined8 *)((longlong)plVar8 + 0x84) = *(undefined8 *)(param_2 + 0x10);
          *(undefined8 *)((longlong)plVar8 + 0x8c) = uVar6;
          *(uint *)((longlong)plVar8 + 0x94) = param_2[0x15];
          _Size = (longlong *)(ulonglong)param_2[0x15];
          memcpy(plVar8 + 0x13,(void *)((ulonglong)param_2[0x14] + 0x28 + (longlong)param_2),
                 (size_t)_Size);
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar7 = CONCAT71((int7)((ulonglong)_Size >> 8),-((param_2[0xb] & 1) != 0)) &
                    0xffffffffffffff0b;
            cVar14 = (char)uVar7 + 'N';
            _Size = (longlong *)CONCAT71((int7)(uVar7 >> 8),cVar14);
            WPP_SF_qZqc_guid__guid_DSI
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_1 + 0x40,_Size,param_1,
                       (wchar_t *)(param_1 + 0x40),uVar19,cVar14,
                       (undefined8 *)((longlong)plVar8 + 0x74),(longlong)plVar8 + 0x84,
                       (char)*(undefined4 *)((longlong)plVar8 + 0x94),(wchar_t *)(plVar8 + 0x13),
                       uVar20);
          }
        }
        else if (uVar5 == 4) {
          *(undefined4 *)(plVar8 + 6) = 4;
          *(undefined4 *)plVar1 = 4;
          *(uint *)(plVar8 + 0xd) = param_2[0xb];
          _Size = (longlong *)(ulonglong)param_2[0xb];
          memcpy((wchar_t *)((longlong)plVar8 + 0x6c),
                 (void *)((ulonglong)param_2[10] + 0x28 + (longlong)param_2),(size_t)_Size);
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_qZqDSI(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_1 + 0x40,_Size,param_1,
                          (wchar_t *)(param_1 + 0x40),uVar19,(char)plVar8[0xd],
                          (wchar_t *)((longlong)plVar8 + 0x6c),uVar20);
          }
        }
        else {
          if (uVar5 != 5) {
            uVar13 = 0xc00000e5;
            goto LAB_1c000d4e5;
          }
          puVar2 = (undefined8 *)((longlong)plVar8 + 0x6c);
          *(undefined4 *)(plVar8 + 6) = 5;
          *(undefined4 *)plVar1 = 5;
          uVar6 = *(undefined8 *)(param_2 + 0xc);
          *puVar2 = *(undefined8 *)(param_2 + 10);
          *(undefined8 *)((longlong)plVar8 + 0x74) = uVar6;
          uVar12 = param_2[0xe];
          uVar4 = (ushort)uVar12;
          _Size = (longlong *)(ulonglong)uVar4;
          *(uint *)(plVar8 + 0xd) = (uint)uVar4;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_qZq_guid_DI(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar2,_Size,param_1,
                               (wchar_t *)(param_1 + 0x40),uVar19,puVar2,(char)uVar12,uVar20);
          }
        }
LAB_1c000d45f:
        plVar11 = (longlong *)0x0;
        lVar9 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(*plVar8 + 0x10) >> 8),
                                       *(char *)(*(longlong *)(*plVar8 + 0x10) + 0x4c) + '\x01'));
        plVar8[7] = lVar9;
        if (lVar9 == 0) {
          uVar13 = 0xc000009a;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            _Size = (longlong *)&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids;
            plVar11 = (longlong *)0x58;
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x58,
                    &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids);
          }
        }
        else {
          _Size = plVar8 + 8;
          plVar11 = *(longlong **)(*plVar8 + 8);
          PVhdFillTunneledIrp(lVar9,plVar11,_Size,uVar16,local_res8,'\x01');
          *param_5 = plVar8;
          if (-1 < (int)uVar13) goto LAB_1c000d4f4;
        }
      }
LAB_1c000d4e5:
      PVhdCleanupMetaOperation(plVar8,plVar11,_Size);
      goto LAB_1c000d4f4;
    }
  }
  uVar13 = 0xc0000095;
LAB_1c000d4f4:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qZd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x59,_Size,param_1,
               (wchar_t *)(param_1 + 0x40),(char)uVar13);
  }
  return uVar13;
}



===== PVhdQueryChanges @ 1c000d560 =====

uint PVhdQueryChanges(longlong param_1,undefined8 *param_2,undefined8 param_3,ulonglong param_4,
                     ulonglong *param_5)

{
  ulonglong uVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  uint uVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  ulonglong uVar10;
  undefined4 *puVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  bool bVar14;
  uint *puVar15;
  uint local_78 [2];
  ulonglong uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  uVar8 = param_4 & 0xffffffff;
  local_68 = 0;
  uStack_60 = 0;
  local_38 = 0;
  puVar4 = (undefined4 *)0x0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_78[0] = 0;
  local_78[1] = 0;
  uStack_70 = 0;
  puVar7 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar7 = (undefined8 *)((longlong)param_2 + 0x24);
    WPP_SF_qZ_guid__guid_ii
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar7,(longlong)param_2 + 0x14,param_1,
               (wchar_t *)(param_1 + 0x40),(longlong)param_2 + 0x14,puVar7,(char)*param_2,
               (char)param_2[1]);
  }
  *param_5 = 0;
  if (*(int *)(param_2 + 2) == 1) {
    local_38 = param_2[1];
    puVar7 = (undefined8 *)0xc0000095;
    uStack_40 = *param_2;
    local_48 = CONCAT44(local_48._4_4_,1);
    local_68 = *(undefined8 *)((longlong)param_2 + 0x14);
    uStack_60 = *(undefined8 *)((longlong)param_2 + 0x1c);
    local_58 = *(undefined8 *)((longlong)param_2 + 0x24);
    uStack_50 = *(undefined8 *)((longlong)param_2 + 0x2c);
    if (uVar8 < 0x10) {
      uVar6 = 0xc0000095;
      goto LAB_1c000d8a8;
    }
    uVar1 = uVar8 + 0x18;
    bVar14 = uVar1 < uVar8 - 0x10;
    uVar10 = 0xffffffffffffffff;
    if (!bVar14) {
      uVar10 = uVar1;
    }
    uVar6 = -(uint)bVar14 & 0xc0000095;
    if ((int)uVar6 < 0) goto LAB_1c000d8a8;
    puVar12 = (undefined8 *)(uVar10 + 0x10);
    if (puVar12 < (undefined8 *)0x10) {
      uVar6 = 0xc0000095;
    }
    else {
      puVar9 = (undefined8 *)0x10000;
      if (((undefined8 *)0x10000 < puVar12) ||
         (puVar9 = puVar12, puVar13 = (undefined8 *)0x48, (undefined8 *)0x47 < puVar12)) {
        puVar13 = puVar9;
      }
      puVar7 = puVar13;
      puVar4 = (undefined4 *)ExAllocatePool2(0x100,puVar13,0x54507070);
      if (puVar4 == (undefined4 *)0x0) {
        uVar6 = 0xc000009a;
      }
      else {
        *puVar4 = 0x200200c;
        LOCK();
        plVar2 = (longlong *)(param_1 + 0x38);
        lVar3 = *plVar2;
        *plVar2 = *plVar2 + 1;
        UNLOCK();
        *(longlong *)(puVar4 + 2) = lVar3 + 1;
        *(undefined8 *)(puVar4 + 4) = local_68;
        *(undefined8 *)(puVar4 + 6) = uStack_60;
        *(undefined8 *)(puVar4 + 8) = local_58;
        *(undefined8 *)(puVar4 + 10) = uStack_50;
        *(undefined8 *)(puVar4 + 0xc) = local_48;
        *(undefined8 *)(puVar4 + 0xe) = uStack_40;
        *(undefined8 *)(puVar4 + 0x10) = local_38;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_qi_guid__guid_iii
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(longlong)param_2 + 0x24,
                     (longlong)param_2 + 0x14,param_1,(char)(lVar3 + 1),(longlong)param_2 + 0x14,
                     (longlong)param_2 + 0x24,(char)*param_2,(char)param_2[1],(char)puVar13);
        }
        puVar7 = *(undefined8 **)(param_1 + 0x10);
        puVar15 = local_78;
        puVar11 = puVar4;
        PVhdTunneledFsCtrl(*(undefined8 *)(param_1 + 8),(longlong)puVar7,(longlong)puVar4,0x48,
                           (int)puVar9,(int *)puVar15);
        uVar6 = local_78[0];
        if ((int)local_78[0] < 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_1c000d949;
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            puVar7 = (undefined8 *)0x7d;
            WPP_SF_qid(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7d,puVar11,param_1,
                       (char)*(undefined8 *)(puVar4 + 2),(char)local_78[0]);
          }
        }
        else if (uStack_70 < 0x10) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            puVar7 = (undefined8 *)0x7e;
            WPP_SF_qiii(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7e,uStack_70,param_1,
                        (char)*(undefined8 *)(puVar4 + 2),puVar15,(char)uStack_70);
          }
          uVar6 = 0xc0000023;
        }
        else {
          puVar7 = (undefined8 *)(uStack_70 - 0x10);
          puVar12 = param_2;
          uVar5 = SvRtlProtoRsvdToVirtstorRctQueryChangesResponse
                            ((undefined8 *)(puVar4 + 4),(ulonglong)puVar7,param_2,uVar8,param_5);
          uVar6 = (uint)uVar5;
          if ((int)uVar6 < 0) {
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_1c000d949;
            puVar7 = (undefined8 *)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c);
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              puVar7 = (undefined8 *)0x7f;
              WPP_SF_qid(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7f,puVar12,param_1,
                         (char)*(undefined8 *)(puVar4 + 2),(char)uVar5);
            }
          }
        }
      }
    }
  }
  else {
    uVar6 = 0xc000000d;
LAB_1c000d8a8:
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar6;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      puVar7 = (undefined8 *)0x7b;
      WPP_SF_qZd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7b,WPP_GLOBAL_Control,param_1,
                 (wchar_t *)(param_1 + 0x40),(char)uVar6);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qZ_guid__guid_iid
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar7,(longlong)param_2 + 0x24,param_1,
               (wchar_t *)(param_1 + 0x40),(longlong)param_2 + 0x14,(longlong)param_2 + 0x24,
               (char)*param_2,(char)param_2[1],(char)uVar6);
  }
  if (puVar4 == (undefined4 *)0x0) {
    return uVar6;
  }
LAB_1c000d949:
  ExFreePoolWithTag(puVar4,0x54507070);
  return uVar6;
}



===== PVhdQueryInformationDisk @ 1c000d990 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PVhdQueryInformationDisk
              (undefined8 *param_1,undefined8 param_2,uint *param_3,uint param_4,ulonglong *param_5,
              uint *param_6)

{
  longlong *plVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  uint uVar5;
  undefined1 uVar6;
  bool bVar7;
  undefined1 auStackY_188 [32];
  int local_148 [2];
  ulonglong uStack_140;
  short local_138 [2];
  int local_134;
  undefined8 local_b8;
  longlong local_b0;
  ulonglong local_a8;
  undefined4 local_98 [2];
  longlong local_90;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined8 local_7c;
  undefined8 uStack_74;
  undefined1 local_6c;
  undefined1 local_6b;
  ulonglong local_68;
  ulonglong local_60;
  ulonglong uStack_58;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_188;
  uVar5 = (uint)param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_2 = 0x2c;
    WPP_SF_DqZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,param_3,uVar5,(char)param_1,
               (wchar_t *)(param_1 + 8));
  }
  if (uVar5 < 0x205) {
    if (uVar5 != 0x204) {
      if (uVar5 == 1) {
        if (0xf < *param_6) {
          iVar3 = 0;
          *param_5 = 0;
          param_5[1] = 0;
          *(undefined4 *)(param_5 + 1) = *(undefined4 *)(param_1 + 3);
          *(undefined4 *)((longlong)param_5 + 0xc) = *(undefined4 *)((longlong)param_1 + 0x1c);
          *param_5 = param_1[4];
          *param_6 = 0x10;
          goto LAB_1c000ddf5;
        }
      }
      else if (uVar5 == 0x101) {
        memset(local_138,0,0x74);
        iVar3 = 0;
        local_148[0] = 0;
        local_148[1] = 0;
        uStack_140 = 0;
        uVar6 = 0;
        if (0x37 < *param_6) {
          memset(local_98,0,0x48);
          local_98[0] = 0x2001005;
          LOCK();
          plVar1 = param_1 + 7;
          local_90 = *plVar1;
          *plVar1 = *plVar1 + 1;
          UNLOCK();
          local_90 = local_90 + 1;
          PVhdTunneledFsCtrl(param_1[1],param_1[2],(longlong)local_98,0x48,0x48,local_148);
          if ((local_148[0] < 0) || (uStack_140 < 0x48)) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 &&
                (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
              WPP_SF_qdII(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,WPP_GLOBAL_Control,param_1
                          ,(char)local_148[0],(char)uStack_140,(char)local_90);
            }
            iVar3 = local_148[0];
            if (-1 < local_148[0]) {
              iVar3 = -0x3fffff1b;
            }
          }
          else {
            iVar2 = ZwQueryInformationFile(*param_1,local_148,local_138,0x74);
            if (((-1 < iVar2) && (0x73 < uStack_140)) && (local_138[0] != 0)) {
              uVar6 = 0;
              if (local_134 == 0x20000) {
                uVar6 = 1;
              }
            }
            *(undefined1 *)((longlong)param_5 + 0x1f) = 0;
            *(undefined4 *)param_5 = local_88;
            *(undefined4 *)((longlong)param_5 + 4) = local_84;
            *(undefined4 *)(param_5 + 1) = local_80;
            *(undefined1 *)((longlong)param_5 + 0x1d) = local_6c;
            *(undefined8 *)((longlong)param_5 + 0xc) = local_7c;
            *(undefined8 *)((longlong)param_5 + 0x14) = uStack_74;
            *(undefined1 *)((longlong)param_5 + 0x1e) = local_6b;
            param_5[4] = local_68;
            param_5[5] = local_60;
            param_5[6] = uStack_58;
            *(undefined1 *)((longlong)param_5 + 0x1c) = uVar6;
            *param_6 = 0x38;
          }
          goto LAB_1c000ddf5;
        }
      }
      else if (uVar5 == 0x104) {
        local_148[0] = 0;
        local_148[1] = 0;
        uStack_140 = 0;
        if (*param_6 != 0) {
          local_b8 = 0x2001006;
          iVar3 = 0;
          *(undefined1 *)param_5 = 0;
          local_a8 = local_a8 & 0xffffffffffffff00;
          LOCK();
          plVar1 = param_1 + 7;
          local_b0 = *plVar1;
          *plVar1 = *plVar1 + 1;
          UNLOCK();
          local_b0 = local_b0 + 1;
          PVhdTunneledFsCtrl(param_1[1],param_1[2],(longlong)&local_b8,0x11,0x11,local_148);
          if ((-1 < local_148[0]) && (0x10 < uStack_140)) {
            *(undefined1 *)param_5 = (undefined1)local_a8;
            *param_6 = 1;
            goto LAB_1c000ddf5;
          }
          iVar3 = local_148[0];
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar4 = 0x2e;
LAB_1c000dbcb:
            WPP_SF_qdII(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,uStack_140,param_1,
                        (char)iVar3,(char)uStack_140,(char)local_b0);
          }
LAB_1c000dbea:
          if (-1 < iVar3) {
            iVar3 = -0x3fffff1b;
          }
          goto LAB_1c000ddf5;
        }
      }
      else {
        if (uVar5 != 0x105) {
          if ((uVar5 != 0x201) && (uVar5 != 0x202)) {
            bVar7 = uVar5 == 0x203;
            goto LAB_1c000ddcb;
          }
          goto LAB_1c000ddd4;
        }
        local_148[0] = 0;
        local_148[1] = 0;
        uStack_140 = 0;
        if (7 < *param_6) {
          local_b8 = 0x200200d;
          iVar3 = 0;
          *param_5 = 0;
          local_a8 = 0;
          LOCK();
          plVar1 = param_1 + 7;
          local_b0 = *plVar1;
          *plVar1 = *plVar1 + 1;
          UNLOCK();
          local_b0 = local_b0 + 1;
          PVhdTunneledFsCtrl(param_1[1],param_1[2],(longlong)&local_b8,0x18,0x18,local_148);
          if ((-1 < local_148[0]) && (0x17 < uStack_140)) {
            *param_5 = local_a8;
            *param_6 = 8;
            goto LAB_1c000ddf5;
          }
          iVar3 = local_148[0];
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar4 = 0x2f;
            goto LAB_1c000dbcb;
          }
          goto LAB_1c000dbea;
        }
      }
      iVar3 = -0x3fffffdd;
      goto LAB_1c000ddf5;
    }
  }
  else if ((((uVar5 != 0x205) && (uVar5 != 0x206)) &&
           ((uVar5 != 0x207 && ((uVar5 != 0x208 && (uVar5 != 0x280)))))) && (uVar5 != 0x281)) {
    bVar7 = uVar5 == 0x283;
LAB_1c000ddcb:
    if (!bVar7) {
      iVar3 = -0x3ffffff0;
      goto LAB_1c000ddf5;
    }
  }
LAB_1c000ddd4:
  iVar3 = PVhdHandleQueryInformationDiskVhdSet
                    ((longlong)param_1,param_2,param_3,param_4,(int *)param_5,param_6);
LAB_1c000ddf5:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
              &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_1,(char)iVar3);
  }
  return iVar3;
}



===== PVhdQueryMetaOperationProgress @ 1c000de60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PVhdQueryMetaOperationProgress(longlong *param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  char *pcVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined1 auStackY_118 [32];
  undefined1 uVar7;
  longlong *in_stack_ffffffffffffff20;
  int local_c8 [2];
  ulonglong uStack_c0;
  undefined4 local_b8 [2];
  longlong local_b0;
  longlong local_a8;
  longlong lStack_a0;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_118;
  lVar3 = *param_1;
  local_c8[0] = 0;
  local_c8[1] = 0;
  uStack_c0 = 0;
  uVar7 = (undefined1)param_1[1];
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    in_stack_ffffffffffffff20 = param_1 + 4;
    pcVar4 = "Snapshot";
    if ((int)param_1[6] != 1) {
      pcVar4 = "Resize";
    }
    WPP_SF_qZqs_guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pcVar4,in_stack_ffffffffffffff20,
                      lVar3,(wchar_t *)(lVar3 + 0x40),uVar7,pcVar4,in_stack_ffffffffffffff20);
  }
  memset(local_b8,0,0x78);
  plVar1 = param_1 + 4;
  local_b8[0] = 0x2002002;
  local_a8 = *plVar1;
  lStack_a0 = param_1[5];
  LOCK();
  plVar2 = (longlong *)(lVar3 + 0x38);
  local_b0 = *plVar2;
  *plVar2 = *plVar2 + 1;
  UNLOCK();
  local_b0 = local_b0 + 1;
  puVar6 = local_b8;
  PVhdTunneledFsCtrl(*(undefined8 *)(lVar3 + 8),*(longlong *)(lVar3 + 0x10),(longlong)puVar6,0x20,
                     0x20,local_c8);
  iVar5 = local_c8[0];
  if (local_c8[0] < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qZqd_guid_I(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar3 + 0x40,puVar6,lVar3,
                         (wchar_t *)(lVar3 + 0x40),uVar7,(char)local_c8[0],plVar1,(char)local_b0);
    }
  }
  else if (uStack_c0 < 0x20) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qZqdd_guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uStack_c0,puVar6,lVar3,
                         (wchar_t *)(lVar3 + 0x40),uVar7,(char)uStack_c0,in_stack_ffffffffffffff20,
                         plVar1);
    }
    iVar5 = -0x3fffff1b;
  }
  else {
    param_2[1] = lStack_a0;
    *param_2 = local_a8;
  }
  return iVar5;
}



===== PVhdQueryMountStatusDisk @ 1c000e050 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PVhdQueryMountStatusDisk(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong *plVar1;
  int iVar2;
  undefined1 auStackY_68 [32];
  int local_38 [4];
  undefined8 local_28;
  longlong lStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = 0;
  lStack_20 = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,param_3,param_1,
              (wchar_t *)(param_1 + 0x40));
  }
  if (*(char *)(param_1 + 0x56) == '\0') {
    iVar2 = local_38[0];
  }
  else {
    local_28 = CONCAT44(local_28._4_4_,0x2001003);
    LOCK();
    plVar1 = (longlong *)(param_1 + 0x38);
    lStack_20 = *plVar1;
    *plVar1 = *plVar1 + 1;
    UNLOCK();
    lStack_20 = lStack_20 + 1;
    PVhdTunneledFsCtrl(*(undefined8 *)(param_1 + 8),*(longlong *)(param_1 + 0x10),
                       (longlong)&local_28,0x10,0x10,local_38);
    iVar2 = local_38[0];
    if (local_38[0] < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return local_38[0];
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        WPP_SF_dI(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
                  &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,local_38[0],(char)lStack_20);
      }
    }
    else {
      iVar2 = PVhdQueryStartingInfo(param_1);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
              &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_1,(char)iVar2);
  }
  return iVar2;
}



===== PVhdQuerySaveVersionDisk @ 1c000e1c0 =====

undefined8 PVhdQuerySaveVersionDisk(longlong param_1,undefined4 *param_2,undefined8 param_3)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,param_3,param_1,
              (wchar_t *)(param_1 + 0x40));
  }
  *param_2 = 1;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,
              &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_1,0);
  }
  return 0;
}



===== PVhdQueryStartingInfo @ 1c000e264 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PVhdQueryStartingInfo(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  undefined1 auStackY_98 [32];
  int local_48 [2];
  ulonglong uStack_40;
  undefined8 local_38;
  longlong local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_98;
  local_38 = 0x2001001;
  local_18 = 0;
  local_48[0] = 0;
  local_48[1] = 0;
  uStack_40 = 0;
  local_28 = 0;
  uStack_20 = 0;
  LOCK();
  plVar1 = (longlong *)(param_1 + 0x38);
  local_30 = *plVar1;
  *plVar1 = *plVar1 + 1;
  UNLOCK();
  lVar2 = *(longlong *)(param_1 + 0x10);
  local_30 = local_30 + 1;
  PVhdTunneledFsCtrl(*(undefined8 *)(param_1 + 8),lVar2,(longlong)&local_38,0x10,0x28,local_48);
  iVar3 = local_48[0];
  if ((local_48[0] < 0) || (uStack_40 < 0x28)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      WPP_SF_qdII(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,uStack_40,param_1,
                  (char)local_48[0],(char)uStack_40,(char)local_30);
    }
    if (-1 < iVar3) {
      iVar3 = -0x3fffff1b;
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qDDDII(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar2,uStack_40,param_1,
                    (char)local_28,(char)((ulonglong)local_28 >> 0x20),(char)uStack_20,
                    (char)local_18,(char)local_30);
    }
    *(undefined4 *)(param_1 + 0x18) = local_28._4_4_;
    *(undefined4 *)(param_1 + 0x1c) = (undefined4)uStack_20;
    *(undefined8 *)(param_1 + 0x20) = local_18;
    *(undefined4 *)(param_1 + 0x50) = (undefined4)local_28;
    iVar3 = 0;
  }
  return iVar3;
}



===== PVhdRestoreDisk @ 1c000e3e0 =====

undefined8 PVhdRestoreDisk(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x43,param_3,param_1,
                (wchar_t *)(param_1 + 0x40));
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x44,
                &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_1,0);
    }
  }
  return 0;
}



===== PVhdSaveDisk @ 1c000e480 =====

undefined8 PVhdSaveDisk(longlong param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x41,param_3,param_1,
              (wchar_t *)(param_1 + 0x40));
  }
  *param_4 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,
              &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_1,0);
  }
  return 0;
}



===== PVhdSetQoSPolicyDisk @ 1c000e530 =====

ulonglong PVhdSetQoSPolicyDisk(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  ulonglong uVar1;
  undefined8 uVar2;
  
  uVar2 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar2 = 0x45;
    WPP_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,param_3,param_1,
              (wchar_t *)(param_1 + 0x40));
  }
  uVar1 = PvhdSynchronouslFsctl(param_1,uVar2,param_2,(int)param_3);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,
              &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_1,(char)uVar1);
  }
  return uVar1 & 0xffffffff;
}



===== PVhdStartMetaOperation @ 1c000e5f0 =====

int PVhdStartMetaOperation(longlong *param_1)

{
  longlong lVar1;
  int iVar2;
  
  lVar1 = *param_1;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qZqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5a,lVar1 + 0x40,lVar1,
                (wchar_t *)(lVar1 + 0x40),(char)param_1[1],(char)param_1[6]);
  }
  iVar2 = PVhdTunneledFsCtrlAsync
                    (*(undefined8 *)(*param_1 + 0x10),PVhdStartMetaCompletionRoutine,param_1,
                     param_1[7]);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qZd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5b,lVar1 + 0x40,lVar1,
               (wchar_t *)(lVar1 + 0x40),(char)iVar2);
  }
  return iVar2;
}



===== PVhdValidateMetaOperation @ 1c000e6bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 PVhdValidateMetaOperation(uint *param_1)

{
  short sVar1;
  undefined2 uVar2;
  uint uVar3;
  
  uVar3 = *param_1;
  if (uVar3 == 0) {
    sVar1 = (short)param_1[10];
    if (sVar1 == 1) {
      return 0;
    }
    if (sVar1 == 3) {
      if (3 < param_1[6]) {
        return 0;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6b,
                  &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_1,(char)param_1[6]);
      }
      return 0xc0000023;
    }
    if (sVar1 == 4) {
      return 0;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc00000bb;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
      return 0xc00000bb;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc00000bb;
    }
    uVar2 = 0x6a;
  }
  else {
    if (uVar3 - 1 < 4) {
      return 0;
    }
    if (uVar3 == 5) {
      uVar3 = (uint)(ushort)param_1[0xe];
      if ((uVar3 == 1) || ((ushort)param_1[0xe] == 4)) {
        uVar3 = param_1[0x13];
        if (uVar3 == 0) {
          if ((*(longlong *)(param_1 + 0xf) == 0) && (*(longlong *)(param_1 + 0x11) == 0)) {
            return 0;
          }
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return 0xc00000bb;
          }
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
            return 0xc00000bb;
          }
          if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
            return 0xc00000bb;
          }
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6e,
                   &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_1);
          return 0xc00000bb;
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0xc00000bb;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
          return 0xc00000bb;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
          return 0xc00000bb;
        }
        uVar2 = 0x6d;
      }
      else {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0xc00000bb;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
          return 0xc00000bb;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
          return 0xc00000bb;
        }
        uVar2 = 0x6c;
      }
    }
    else {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc00000bb;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
        return 0xc00000bb;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return 0xc00000bb;
      }
      uVar2 = 0x69;
    }
  }
  WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
            &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_1,(char)uVar3);
  return 0xc00000bb;
}



===== PvhdCheckIfFileExistsAndVolumeSupportsMayhew @ 1c000e8fc =====

int PvhdCheckIfFileExistsAndVolumeSupportsMayhew
              (undefined8 param_1,wchar_t *param_2,undefined8 param_3)

{
  int iVar1;
  undefined2 uVar2;
  undefined8 *puVar3;
  longlong local_res18;
  longlong local_res20;
  wchar_t *in_stack_ffffffffffffff08;
  undefined8 in_stack_ffffffffffffff18;
  undefined4 uVar4;
  undefined8 in_stack_ffffffffffffff28;
  undefined4 uVar5;
  undefined4 uVar6;
  ulonglong local_a8;
  undefined8 local_a0;
  ulonglong uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  wchar_t *local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  ulonglong uStack_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 uStack_38;
  
  uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffff18 >> 0x20);
  uVar5 = (undefined4)((ulonglong)in_stack_ffffffffffffff28 >> 0x20);
  local_70 = 0;
  local_res20 = 0;
  local_a8 = 0;
  local_5c = 0;
  local_44 = 0;
  local_res18 = 0;
  local_90 = 0;
  uStack_88 = 0;
  uStack_68 = uStack_68 & 0xffffffff00000000;
  local_80 = (wchar_t *)0x0;
  uStack_78 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      in_stack_ffffffffffffff08 = param_2;
      WPP_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,param_3,param_1,param_2);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
               &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_1);
    }
  }
  local_60 = 0x30;
  local_58 = 0;
  puVar3 = (undefined8 *)&local_60;
  local_48 = 0x200;
  local_50 = 0;
  local_40 = 0;
  uStack_38 = 0;
  iVar1 = ZwCreateEvent(&local_res18,0x1f0003,puVar3,0,
                        (ulonglong)in_stack_ffffffffffffff08 & 0xffffffffffffff00);
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c000ebcc;
    uVar2 = 0x24;
  }
  else {
    puVar3 = &local_90;
    uVar6 = 0;
    local_90 = CONCAT44(local_90._4_4_,0x30);
    uStack_88 = 0;
    uStack_78 = CONCAT44(uStack_78._4_4_,0x240);
    local_70 = 0;
    uStack_68 = 0;
    local_80 = param_2;
    iVar1 = IoCreateFile(&local_res20,0x80,puVar3,&local_a0,0,0x80,CONCAT44(uVar4,7),1,
                         CONCAT44(uVar5,8),0,0,0,0,0x101);
    if (iVar1 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_qZd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,puVar3,param_1,param_2,
                   (char)iVar1);
      }
      goto LAB_1c000ebcc;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
               &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_1);
    }
    puVar3 = (undefined8 *)0x0;
    iVar1 = ZwFsControlFile(local_res20,local_res18,0,0,&local_a0,0x90300,0,0,&local_a8,
                            CONCAT44(uVar6,8));
    if (iVar1 == 0x103) {
      puVar3 = (undefined8 *)0x0;
      ZwWaitForSingleObject(local_res18,0);
      iVar1 = (int)local_a0;
    }
    if (-1 < iVar1) {
      if (7 < uStack_98) {
        if ((local_a8 & 1) == 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (2 < (byte)WPP_GLOBAL_Control[0x29])) {
            puVar3 = (undefined8 *)&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids;
            WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
                     &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_1);
          }
          iVar1 = -0x3ffffff0;
        }
        goto LAB_1c000ebcc;
      }
      iVar1 = -0x3fffff3d;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 3))
    goto LAB_1c000ebcc;
    uVar2 = 0x27;
  }
  puVar3 = (undefined8 *)&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids;
  WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
            &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,param_1,(char)iVar1);
LAB_1c000ebcc:
  if (local_res20 != 0) {
    ZwClose();
  }
  if (local_res18 != 0) {
    ZwClose();
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qZd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,puVar3,param_1,param_2,(char)iVar1);
  }
  return iVar1;
}



===== WppCleanupKm @ 1c000ec90 =====

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



===== WppInitKm @ 1c000ed10 =====

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



===== WppLoadTracingSupport @ 1c000eda0 =====

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



===== WppTraceCallback @ 1c000eef0 =====

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



===== PVhdCdbToOffsetLength @ 1c000f178 =====

undefined8
PVhdCdbToOffsetLength
          (char *param_1,uint param_2,undefined1 *param_3,longlong *param_4,undefined4 *param_5)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  code *pcVar10;
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  byte bVar13;
  undefined8 uVar14;
  undefined4 uVar15;
  undefined2 uVar16;
  ulonglong uVar17;
  ulonglong uVar18;
  uint uVar19;
  undefined4 local_res8;
  
  cVar1 = *param_1;
  uVar18 = CONCAT44(0,param_2);
  *param_3 = 0;
  if ((cVar1 == '\b') || (cVar1 == '\n')) {
    bVar13 = param_1[4];
    param_3 = (undefined1 *)(ulonglong)bVar13;
    local_res8._0_2_ = CONCAT11(param_1[2],param_1[3]);
    local_res8._0_3_ = CONCAT12(param_1[1],(ushort)local_res8) & 0x1fffff;
    local_res8 = (uint)(uint3)local_res8;
    uVar17 = (longlong)param_3 * uVar18;
    uVar15 = 0xffffffff;
    if (uVar17 < 0x100000000) {
      uVar15 = (int)uVar17;
    }
    *param_5 = uVar15;
    *param_4 = local_res8 * uVar18;
    if (uVar17 < 0x100000000) {
      return 0;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000015;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
      return 0xc0000015;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc0000015;
    }
    uVar16 = 10;
  }
  else {
    if ((cVar1 == '(') || (cVar1 == '*')) {
      local_res8._0_2_ = CONCAT11(param_1[7],param_1[8]);
      uVar19 = CONCAT13(param_1[2],CONCAT12(param_1[3],CONCAT11(param_1[4],param_1[5])));
      uVar17 = (ushort)local_res8 * uVar18;
      uVar15 = 0xffffffff;
      if (uVar17 < 0x100000000) {
        uVar15 = (int)uVar17;
      }
      *param_5 = uVar15;
      bVar13 = param_1[1];
      *param_4 = uVar19 * uVar18;
      if ((bVar13 & 8) != 0) {
        *param_3 = 1;
      }
      if (uVar17 < 0x100000000) {
        return 0;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc0000015;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
        return 0xc0000015;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return 0xc0000015;
      }
      local_res8 = (uint)(ushort)local_res8;
      uVar16 = 0xd;
    }
    else {
      if ((cVar1 == -0x78) || (cVar1 == -0x76)) {
        cVar1 = param_1[0xd];
        local_res8._0_2_ = CONCAT11(param_1[0xc],cVar1);
        local_res8._0_3_ = CONCAT12(param_1[0xb],(ushort)local_res8);
        local_res8 = CONCAT13(param_1[10],(uint3)local_res8);
        cVar2 = param_1[9];
        cVar3 = param_1[8];
        cVar4 = param_1[7];
        cVar5 = param_1[6];
        cVar6 = param_1[5];
        cVar7 = param_1[4];
        cVar8 = param_1[3];
        cVar9 = param_1[2];
        if ((param_1[1] & 8U) != 0) {
          *param_3 = 1;
        }
        uVar17 = CONCAT17(cVar9,CONCAT16(cVar8,CONCAT15(cVar7,CONCAT14(cVar6,CONCAT13(cVar5,CONCAT12
                                                  (cVar4,CONCAT11(cVar3,cVar2)))))));
        if (local_res8 * uVar18 < 0x100000000) {
          *param_5 = (int)(local_res8 * uVar18);
          auVar11._8_8_ = 0;
          auVar11._0_8_ = uVar18;
          auVar12._8_8_ = 0;
          auVar12._0_8_ = uVar17;
          if (SUB168(auVar11 * auVar12,8) == 0) {
            *param_4 = SUB168(auVar11 * auVar12,0);
            return 0;
          }
          *param_4 = -1;
        }
        else {
          *param_5 = 0xffffffff;
        }
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0xc0000015;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
          return 0xc0000015;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
          return 0xc0000015;
        }
        WPP_SF_IDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),&WPP_GLOBAL_Control,WPP_GLOBAL_Control
                   ,uVar17,cVar1,(char)param_2);
        return 0xc0000015;
      }
      if ((cVar1 != -0x58) && (cVar1 != -0x56)) {
        pcVar10 = (code *)swi(3);
        uVar14 = (*pcVar10)();
        return uVar14;
      }
      if ((param_1[1] & 1U) != 0) {
        return 0xc0000285;
      }
      if ((param_1[1] & 8U) != 0) {
        *param_3 = 1;
      }
      local_res8._0_2_ = CONCAT11(param_1[8],param_1[9]);
      local_res8._0_3_ = CONCAT12(param_1[7],(ushort)local_res8);
      local_res8 = CONCAT13(param_1[6],(uint3)local_res8);
      uVar19 = CONCAT13(param_1[2],CONCAT12(param_1[3],CONCAT11(param_1[4],param_1[5])));
      param_3 = (undefined1 *)(local_res8 * uVar18);
      uVar15 = 0xffffffff;
      if (param_3 < (undefined1 *)0x100000000) {
        uVar15 = (int)param_3;
      }
      *param_5 = uVar15;
      *param_4 = uVar19 * uVar18;
      if (param_3 < (undefined1 *)0x100000000) {
        return 0;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc0000015;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0) {
        return 0xc0000015;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return 0xc0000015;
      }
      uVar16 = 0xb;
    }
    bVar13 = (byte)local_res8;
    local_res8 = uVar19;
  }
  WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar16,param_3,local_res8,bVar13,
             (char)param_2);
  return 0xc0000015;
}



===== PVhdReQueryStartingInfoWorkItem @ 1c000f4d0 =====

void PVhdReQueryStartingInfoWorkItem(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  PVhdQueryStartingInfo(param_2);
  IoFreeWorkItem(param_3);
  return;
}



===== PVhdReadWriteIo @ 1c000f500 =====

undefined8
PVhdReadWriteIo(undefined8 param_1,longlong param_2,longlong param_3,char param_4,char param_5,
               undefined8 param_6,undefined4 param_7)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  lVar2 = IoAllocateIrp(*(char *)(param_2 + 0x4c) + '\x01',0);
  if (lVar2 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
              &WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids);
    }
    uVar3 = 0xc000009a;
  }
  else {
    lVar1 = *(longlong *)(lVar2 + 0xb8);
    *(void **)(lVar2 + 0x98) = SystemReserved1[0xf];
    *(undefined4 *)(lVar2 + 0x10) = 1;
    *(undefined8 *)(lVar2 + 8) = *(undefined8 *)(param_3 + 0x10);
    *(undefined1 *)(lVar2 + 0x40) = 0;
    *(uint *)(lVar2 + 0x10) = (-(uint)(param_5 != '\0') & 0x100) + 0x101;
    *(char *)(lVar1 + -0x48) = (param_5 != '\0') + '\x03';
    if (param_4 != '\0') {
      *(byte *)(lVar1 + -0x46) = *(byte *)(lVar1 + -0x46) | 4;
    }
    *(undefined4 *)(lVar1 + -0x40) = param_7;
    *(undefined8 *)(lVar1 + -0x30) = param_6;
    *(undefined8 *)(lVar1 + -0x18) = param_1;
    lVar1 = *(longlong *)(lVar2 + 0xb8);
    *(code **)(lVar1 + -0x10) = PVhdReadWriteIoComplete;
    *(longlong *)(lVar1 + -8) = param_3;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    IofCallDriver(param_2,lVar2);
    uVar3 = 0x103;
  }
  return uVar3;
}



===== PVhdReadWriteIoRetrieveStatusWorkItem @ 1c000f640 =====

void PVhdReadWriteIoRetrieveStatusWorkItem(undefined8 param_1,longlong *param_2,undefined8 param_3)

{
  PVhdReadWriteIoIssueRetrieveStatusRequestFsctl(param_2);
  IoFreeWorkItem(param_3);
  return;
}



===== PVhdScsiReadWrite @ 1c000f670 =====

void PVhdScsiReadWrite(longlong param_1,char *param_2,char param_3)

{
  uint *puVar1;
  byte bVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  undefined8 uVar6;
  undefined2 uVar7;
  uint uVar8;
  char *pcVar9;
  char local_res8 [8];
  uint local_res10 [4];
  longlong local_res20;
  undefined1 uVar10;
  
  lVar3 = *(longlong *)(param_2 + 8);
  local_res20 = 0;
  local_res10[0] = 0;
  pcVar9 = local_res8;
  local_res8[0] = '\0';
  uVar6 = PVhdCdbToOffsetLength
                    ((char *)(lVar3 + 0x10),*(uint *)(param_1 + 0x18),pcVar9,&local_res20,
                     local_res10);
  lVar4 = local_res20;
  uVar8 = local_res10[0];
  iVar5 = (int)uVar6;
  uVar10 = (undefined1)param_1;
  if (iVar5 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,pcVar9,param_2,uVar10);
    }
    goto LAB_1c000f846;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qqDIiDD_guid_Z
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_1 + 0x28,pcVar9,param_2,uVar10,
               param_3,(char)local_res20,(char)local_res20,(char)local_res10[0],(char)local_res10[0]
               ,param_1 + 0x28,(wchar_t *)(param_1 + 0x40));
  }
  bVar2 = *(byte *)(lVar3 + 10);
  if (param_3 == '\0') {
    if (bVar2 != 0) goto LAB_1c000f782;
LAB_1c000f7ce:
    iVar5 = -0x3ffffff3;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      pcVar9 = (char *)(ulonglong)bVar2;
      uVar7 = 0x31;
      uVar8 = (uint)bVar2;
LAB_1c000f839:
      iVar5 = -0x3ffffff3;
      WPP_SF_qqDD(uVar6,uVar7,pcVar9,param_2,uVar10,(char)uVar8,param_3);
    }
  }
  else {
    if (bVar2 == 1) goto LAB_1c000f7ce;
LAB_1c000f782:
    puVar1 = (uint *)(*(longlong *)(param_2 + 0x10) + 0x28);
    if ((*(longlong *)(param_2 + 0x10) == 0) || (*puVar1 < uVar8)) {
      iVar5 = -0x3ffffff3;
      pcVar9 = WPP_GLOBAL_Control;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0 || ((byte)WPP_GLOBAL_Control[0x29] < 2)))
         ) goto LAB_1c000f846;
      param_3 = (char)*puVar1;
      uVar7 = 0x32;
      uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      goto LAB_1c000f839;
    }
    pcVar9 = param_2;
    uVar6 = PVhdReadWriteIo(*(undefined8 *)(param_1 + 8),*(longlong *)(param_1 + 0x10),
                            (longlong)param_2,local_res8[0],param_3,lVar4,uVar8);
    iVar5 = (int)uVar6;
    if (iVar5 == 0x103) goto LAB_1c000f89b;
  }
LAB_1c000f846:
  PVhdNtStatusToSrbStatus(iVar5,*(longlong *)(param_2 + 8));
  *(undefined4 *)(*(longlong *)(param_2 + 8) + 0xc) = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    pcVar9 = &WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids;
    WPP_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
               &WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids,param_2,uVar10,(char)iVar5);
  }
  PVhdCompleteScsiRequest((undefined8 *)param_2);
LAB_1c000f89b:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,pcVar9,param_2,uVar10);
  }
  return;
}



===== PVhdScsiRequest @ 1c000f8e0 =====

void PVhdScsiRequest(longlong param_1,longlong *param_2,undefined8 param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  longlong lVar8;
  undefined2 uVar9;
  undefined1 uVar10;
  uint uVar11;
  uint local_res10;
  undefined4 *local_res20;
  undefined1 uVar12;
  ulonglong in_stack_ffffffffffffff88;
  undefined1 uVar13;
  
  lVar2 = param_2[1];
  uVar10 = 0;
  plVar3 = (longlong *)*param_2;
  lVar8 = param_2[2];
  local_res20 = (undefined4 *)0x0;
  uVar11 = *(uint *)(lVar2 + 0xc);
  uVar12 = (undefined1)param_1;
  uVar13 = (undefined1)uVar11;
  if (lVar8 == 0) {
    if (uVar11 != 0) goto LAB_1c000f9b6;
LAB_1c000fa19:
    if (((*(char *)(lVar2 + 0x10) == -0x62) && ((*(byte *)(lVar2 + 0x11) & 0x1f) == 0x12)) &&
       (0xfc00 < uVar11)) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_qqDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,param_3,param_2,uVar12,
                    (char)*(undefined4 *)(lVar2 + 0xc),uVar13);
      }
      local_res10 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(lVar2 + 0x1a),
                                               *(undefined1 *)(lVar2 + 0x1b)),
                                      *(undefined1 *)(lVar2 + 0x1c)),*(undefined1 *)(lVar2 + 0x1d));
      if (((local_res10 != uVar11) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0 && (2 < (byte)WPP_GLOBAL_Control[0x29])))
         ) {
        WPP_SF_qqDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,(ulonglong)local_res10,param_2,
                    uVar12,uVar13,*(undefined1 *)(lVar2 + 0x1d));
      }
      *(undefined4 *)(lVar2 + 0x1a) = 0xfc0000;
      uVar11 = 0xfc00;
      *local_res20 = 0xfcfb0000;
      uVar5 = 0xfc34;
    }
    else {
      uVar5 = uVar11 + 0x34;
      if (uVar5 < 0x34) {
        iVar6 = -0x3fffff6b;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar9 = 0x1b;
          iVar6 = -0x3fffff6b;
          goto LAB_1c000fdc7;
        }
        goto LAB_1c000fddf;
      }
    }
    puVar7 = (undefined4 *)ExAllocatePool2(0x100,uVar5,0x54507070);
    if (puVar7 == (undefined4 *)0x0) {
      iVar6 = -0x3fffffe9;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar9 = 0x1c;
        goto LAB_1c000fdc7;
      }
    }
    else {
      *puVar7 = 0x2001002;
      LOCK();
      plVar1 = (longlong *)(param_1 + 0x38);
      lVar8 = *plVar1;
      *plVar1 = *plVar1 + 1;
      UNLOCK();
      *(longlong *)(puVar7 + 2) = lVar8 + 1;
      *(undefined2 *)(puVar7 + 4) = 0x24;
      *(undefined1 *)(puVar7 + 5) = *(undefined1 *)(lVar2 + 8);
      *(undefined1 *)((longlong)puVar7 + 0x15) = *(undefined1 *)(lVar2 + 9);
      *(undefined1 *)((longlong)puVar7 + 0x16) = *(undefined1 *)(lVar2 + 10);
      puVar7[6] = *(undefined4 *)(lVar2 + 0x28);
      puVar7[7] = uVar11;
      uVar4 = *(undefined8 *)(lVar2 + 0x18);
      *(undefined8 *)(puVar7 + 8) = *(undefined8 *)(lVar2 + 0x10);
      *(undefined8 *)(puVar7 + 10) = uVar4;
      if ((uVar11 != 0) && (local_res20 != (undefined4 *)0x0)) {
        memcpy(puVar7 + 0xd,local_res20,(ulonglong)uVar11);
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_qqDI_guid_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_1 + 0x28,
                           (ulonglong)*(byte *)(lVar2 + 0x10),param_2,uVar12,*(byte *)(lVar2 + 0x10)
                           ,(char)*(undefined8 *)(puVar7 + 2),param_1 + 0x28,
                           (wchar_t *)(param_1 + 0x40));
      }
      lVar8 = IoAllocateIrp(*(char *)(*(longlong *)(param_1 + 0x10) + 0x4c) + '\x01',0);
      if (lVar8 == 0) {
        iVar6 = -0x3fffff66;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                  &WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids);
        }
      }
      else {
        PVhdFillTunneledIrp(lVar8,*(undefined8 *)(param_1 + 8),puVar7,uVar5,uVar5,'\0');
        plVar3[1] = 0;
        *plVar3 = param_1;
        plVar3[2] = (longlong)puVar7;
        plVar3[3] = (longlong)param_2;
        plVar3[4] = (longlong)local_res20;
        iVar6 = PVhdTunneledFsCtrlAsync
                          (*(undefined8 *)(param_1 + 0x10),PVhdScsiRequestFsctlCompletion,plVar3,
                           lVar8);
        if (-1 < iVar6) goto LAB_1c000fde7;
        PVhdNtStatusToSrbStatus(iVar6,lVar2);
        *(undefined4 *)(param_2[1] + 0xc) = 0;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_dI(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                    &WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids,iVar6,
                    (char)*(undefined8 *)(puVar7 + 2));
        }
      }
      ExFreePoolWithTag(puVar7,0x54507070);
      if (lVar8 != 0) {
        IoFreeIrp(lVar8);
      }
    }
  }
  else if (*(uint *)(lVar8 + 0x28) < uVar11) {
LAB_1c000f9b6:
    iVar6 = -0x3ffffff3;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      if (lVar8 != 0) {
        uVar10 = (undefined1)*(undefined4 *)(lVar8 + 0x28);
      }
      WPP_SF_qqDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,WPP_GLOBAL_Control,param_2,uVar12,
                  uVar13,uVar10);
    }
  }
  else {
    if ((*(byte *)(lVar8 + 10) & 5) == 0) {
      param_3 = 1;
      local_res20 = (undefined4 *)
                    MmMapLockedPagesSpecifyCache
                              (lVar8,0,1,0,in_stack_ffffffffffffff88 & 0xffffffff00000000,0x40000010
                              );
    }
    else {
      local_res20 = *(undefined4 **)(lVar8 + 0x18);
    }
    if (local_res20 != (undefined4 *)0x0) goto LAB_1c000fa19;
    iVar6 = -0x3fffff66;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar9 = 0x18;
LAB_1c000fdc7:
      WPP_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
                 &WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids,param_2,uVar12,(char)iVar6);
    }
  }
LAB_1c000fddf:
  PVhdCompleteScsiRequest(param_2);
LAB_1c000fde7:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
             &WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids,iVar6);
  }
  return;
}



===== PVhdTunneledFsCtrl @ 1c000fe38 =====

void PVhdTunneledFsCtrl(undefined8 param_1,longlong param_2,longlong param_3,undefined4 param_4,
                       undefined4 param_5,int *param_6)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
            &WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids);
  }
  lVar5 = IoAllocateIrp(*(char *)(param_2 + 0x4c) + '\x01',0);
  if (lVar5 == 0) {
    *param_6 = -0x3fffff66;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
              &WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids);
    }
  }
  else {
    PVhdFillTunneledIrp(lVar5,param_1,param_3,param_4,param_5,'\0');
    KeInitializeEvent(&local_38,0,0);
    lVar1 = *(longlong *)(lVar5 + 0xb8);
    *(code **)(lVar1 + -0x10) = PVhdIrpRequestComplete;
    *(undefined8 **)(lVar1 + -8) = &local_38;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    IofCallDriver(param_2,lVar5);
    KeWaitForSingleObject(&local_38,0,0,0,0);
    iVar2 = *(int *)(lVar5 + 0x34);
    iVar3 = *(int *)(lVar5 + 0x38);
    iVar4 = *(int *)(lVar5 + 0x3c);
    *param_6 = *(int *)(lVar5 + 0x30);
    param_6[1] = iVar2;
    param_6[2] = iVar3;
    param_6[3] = iVar4;
    if (-1 < *param_6) {
      if (*(ulonglong *)(param_6 + 2) < 0x10) {
        *param_6 = -0x3fffffdd;
      }
      else {
        *param_6 = *(int *)(param_3 + 4);
      }
    }
    IoFreeIrp(lVar5);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
             &WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids,*param_6);
  }
  return;
}



===== PVhdTunneledFsCtrlAsync @ 1c0010018 =====

int PVhdTunneledFsCtrlAsync
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
            &WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids);
  }
  iVar1 = IoSetCompletionRoutineEx(param_1,param_4,param_2,param_3,1,1,1);
  if (iVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                &WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids,param_4,(char)iVar1);
    }
  }
  else {
    IofCallDriver(param_1,param_4);
    iVar1 = 0x103;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
             &WPP_ce791e1dc13930b9f62c68a1b2dc4469_Traceguids,iVar1);
  }
  return iVar1;
}



===== ClusKRTLDetermineVhdFileType @ 1c0010144 =====

undefined8 ClusKRTLDetermineVhdFileType(ushort *param_1,char *param_2,undefined1 *param_3)

{
  short sVar1;
  char cVar2;
  undefined1 uVar3;
  ushort uVar4;
  undefined8 uVar5;
  int iVar6;
  ushort uVar7;
  longlong lVar8;
  ushort local_res8 [4];
  longlong local_res10;
  short local_48;
  short local_46;
  undefined4 local_44;
  longlong local_40;
  
  uVar4 = *param_1;
  *param_2 = '\0';
  *param_3 = 0;
  iVar6 = (uVar4 >> 1) - 1;
  local_44 = 0;
  local_res10 = 0;
  uVar7 = 0;
  local_res8[0] = 0;
  if (-1 < iVar6) {
    do {
      sVar1 = *(short *)(*(longlong *)(param_1 + 4) + (longlong)iVar6 * 2);
      if (sVar1 == 0x5c) break;
      if (sVar1 == 0x3a) {
        uVar7 = uVar4 + (short)iVar6 * -2;
        local_res8[0] = uVar7;
      }
      iVar6 = iVar6 + -1;
    } while (-1 < iVar6);
  }
  lVar8 = *(longlong *)(param_1 + 4);
  uVar5 = ClusKRTLFindCharReverse(lVar8,uVar4,0x5c,&local_res10,(short *)local_res8);
  if ((int)uVar5 != -0x3fffffcc) {
    local_res10 = local_res10 + 2;
    uVar4 = local_res8[0] - 2;
    lVar8 = local_res10;
    local_res8[0] = uVar4;
    if (uVar4 == 0) {
      lVar8 = 0;
    }
  }
  if (uVar4 != 0) {
    uVar5 = ClusKRTLFindCharReverse(lVar8,uVar4 - uVar7,0x2e,&local_res10,(short *)local_res8);
    if ((int)uVar5 == 0) {
      local_40 = local_res10 + 2;
      local_48 = local_res8[0] - 2;
      goto LAB_1c001024e;
    }
  }
  local_48 = 0;
  local_40 = 0;
LAB_1c001024e:
  local_46 = local_48;
  cVar2 = RtlEqualUnicodeString(&local_48,&ClusKRTLVhdxFileExtension,1);
  *param_2 = cVar2;
  if (cVar2 == '\0') {
    uVar3 = RtlEqualUnicodeString(&local_48,&ClusKRTLVhdSetFileExtension,1);
    *param_3 = uVar3;
  }
  return 0;
}



===== ClusKRTLGenerateGuid @ 1c00102bc =====

void ClusKRTLGenerateGuid(undefined8 param_1)

{
  int iVar1;
  undefined8 local_res10 [3];
  
  while( true ) {
    iVar1 = ExUuidCreate(param_1);
    if (iVar1 != -0x3ffffdd3) break;
    local_res10[0] = 0xffffffffff676980;
    KeDelayExecutionThread(0,0,local_res10);
  }
  return;
}



===== ClusKRTLQueryValueKey @ 1c0010308 =====

ulonglong ClusKRTLQueryValueKey
                    (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 local_res8;
  undefined4 local_res18 [2];
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8 = 0;
  local_res18[0] = 0;
  local_1c = 0;
  local_30 = 0;
  local_38 = 0x30;
  local_18 = 0;
  uStack_10 = 0;
  local_20 = 0x240;
  local_28 = param_1;
  uVar2 = ZwOpenKey(&local_res8,0x20019,&local_38);
  if (-1 < (int)uVar2) {
    uVar1 = ZwQueryValueKey(local_res8,param_2,1,param_4,0x9c,local_res18);
    uVar2 = (ulonglong)uVar1;
    ZwClose(local_res8);
  }
  return uVar2;
}



===== ClusKRTLReadParameterUlong @ 1c00103d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong ClusKRTLReadParameterUlong(short *param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined1 auStack_108 [32];
  undefined2 local_e8;
  short local_e6;
  undefined4 local_e4;
  longlong local_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  int local_b8 [40];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_108;
  local_e4 = 0;
  local_e8 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  RtlInitUnicodeString(&local_d8,L"\\Parameters");
  RtlInitUnicodeString(&local_c8,L"EcpContextVersion");
  local_e6 = (short)local_d8 + *param_1;
  uVar3 = 0x54524b43;
  local_e0 = ExAllocatePool2(0x40);
  if (local_e0 == 0) {
    uVar2 = 0xc000009a;
    EcpContextVersion = 2;
  }
  else {
    RtlCopyUnicodeString(&local_e8,param_1);
    RtlAppendUnicodeStringToString(&local_e8,&local_d8);
    uVar1 = ClusKRTLQueryValueKey(&local_e8,&local_c8,uVar3,local_b8);
    uVar2 = uVar1 & 0xffffffff;
    if ((((int)uVar1 < 0) || (local_b8[3] == 0)) || (local_b8[1] != 4)) {
      EcpContextVersion = 2;
    }
    else {
      EcpContextVersion = *(undefined4 *)((longlong)local_b8 + (ulonglong)(uint)local_b8[2]);
    }
  }
  if (local_e0 != 0) {
    ExFreePoolWithTag(local_e0,0x54524b43);
  }
  return uVar2;
}



===== ClusKRTLFindCharReverse @ 1c0010520 =====

undefined8
ClusKRTLFindCharReverse
          (longlong param_1,ushort param_2,short param_3,longlong *param_4,short *param_5)

{
  ushort uVar1;
  short sVar2;
  undefined8 uVar3;
  
  uVar1 = param_2 >> 1;
  uVar3 = 0xc0000034;
  if (((uVar1 != 0) && (param_1 != 0)) && (sVar2 = uVar1 - 1, -1 < sVar2)) {
    do {
      if (*(short *)(param_1 + (longlong)sVar2 * 2) == param_3) break;
      sVar2 = sVar2 + -1;
    } while (-1 < sVar2);
    if (-1 < sVar2) {
      uVar3 = 0;
      *param_4 = param_1 + (longlong)sVar2 * 2;
      *param_5 = (uVar1 - sVar2) * 2;
    }
  }
  return uVar3;
}



===== SvRtlProtoRsvdToVirtstorRctQueryChangesResponse @ 1c001058c =====

undefined8
SvRtlProtoRsvdToVirtstorRctQueryChangesResponse
          (undefined8 *param_1,ulonglong param_2,undefined8 *param_3,ulonglong param_4,
          ulonglong *param_5)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  undefined8 uVar5;
  
  *param_5 = 0;
  if (param_2 < 0x28) {
LAB_1c00105b2:
    uVar5 = 0xc000000d;
  }
  else {
    uVar3 = (ulonglong)*(uint *)(param_1 + 1) * 0x18;
    if (uVar3 < 0x100000000) {
      iVar1 = (int)uVar3;
      uVar2 = iVar1 + 0x28;
      if (0x27 < uVar2) {
        if (param_2 < uVar2) goto LAB_1c00105b2;
        uVar2 = iVar1 + 0x10;
        if (0xf < uVar2) {
          if (param_4 < uVar2) {
            return 0xc0000023;
          }
          *(uint *)(param_3 + 1) = *(uint *)(param_1 + 1);
          uVar4 = 0;
          *param_3 = *param_1;
          if (*(int *)(param_1 + 1) != 0) {
            do {
              uVar3 = (ulonglong)uVar4;
              uVar4 = uVar4 + 1;
              param_3[uVar3 * 3 + 2] = param_1[uVar3 * 3 + 2];
              param_3[uVar3 * 3 + 3] = param_1[uVar3 * 3 + 3];
            } while (uVar4 < *(uint *)(param_1 + 1));
          }
          *param_5 = (ulonglong)uVar2;
          return 0;
        }
      }
    }
    uVar5 = 0xc0000095;
  }
  return uVar5;
}



===== SvRtlProtoRsvdToVirtstorVhdSetQueryInformationResponse @ 1c0010650 =====

ulonglong SvRtlProtoRsvdToVirtstorVhdSetQueryInformationResponse
                    (int *param_1,ulonglong param_2,int *param_3,ulonglong param_4,
                    ulonglong *param_5,ulonglong *param_6)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  int *_Dst;
  ulonglong uVar4;
  int *_Src;
  ulonglong uVar5;
  size_t _Size;
  ulonglong uVar6;
  ulonglong uVar7;
  int iVar8;
  ulonglong local_38;
  ulonglong local_30;
  
  uVar5 = 0;
  local_38 = 0;
  local_30 = 0;
  iVar8 = -1;
  uVar6 = 0x238;
  if (param_2 < 4) goto LAB_1c00106a0;
  iVar8 = *param_1;
  if (param_4 < 0x238) {
LAB_1c001072a:
    uVar5 = 0xc0000023;
  }
  else {
    *param_3 = iVar8;
    if (iVar8 < 7) {
      if ((iVar8 == 6) || (iVar8 == 1)) {
LAB_1c00109d4:
        uVar5 = SvRtlProtoRsvdToVirtstorVhdsetPath
                          ((char *)(param_1 + 2),param_2 - 8,(longlong)(param_3 + 2),param_4 - 8,
                           &local_38,&local_30);
        uVar5 = uVar5 & 0xffffffff;
        uVar4 = local_38 + 8;
        uVar6 = 0x238;
        if (0x238 < local_30 + 8) {
          uVar6 = local_30 + 8;
        }
      }
      else {
        if (iVar8 == 2) {
LAB_1c001092c:
          if (param_2 - 8 < 0x18) goto LAB_1c00106a0;
          uVar4 = 8;
          if (param_4 - 8 < 8) goto LAB_1c001072a;
          iVar1 = param_1[2];
          *(char *)(param_3 + 2) = (char)iVar1;
          uVar2 = param_1[3];
          param_3[3] = uVar2;
          uVar7 = 8;
          if ((char)iVar1 != '\0') {
            _Size = (ulonglong)uVar2 * 0x10;
            uVar7 = _Size + 8;
            if (param_2 - 8 < _Size + 0x18) {
              *(undefined1 *)(param_3 + 2) = 0;
              uVar5 = 0xc000000d;
            }
            else if (param_4 - 8 < uVar7) {
              *(undefined1 *)(param_3 + 2) = 0;
              uVar5 = 0xc0000023;
            }
            else {
              _Src = param_1 + 4;
              _Dst = param_3 + 4;
              uVar4 = uVar7;
LAB_1c0010999:
              memcpy(_Dst,_Src,_Size);
              uVar7 = uVar4;
            }
          }
        }
        else {
          if ((iVar8 != 3) && (iVar8 != 4)) {
            if (iVar8 == 5) goto LAB_1c0010777;
LAB_1c00108e9:
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                       &WPP_159b873bf96b3f027a476325038fd206_Traceguids,iVar8);
            }
            uVar6 = 0x238;
            uVar5 = 0xc00000e5;
            goto LAB_1c00106a5;
          }
          if (param_2 - 8 < 0x10) goto LAB_1c00106a0;
          uVar4 = 0xc;
          if (param_4 - 8 < 0xc) goto LAB_1c001072a;
          iVar1 = param_1[2];
          *(char *)(param_3 + 2) = (char)iVar1;
          param_3[3] = param_1[3];
          uVar2 = param_1[4];
          param_3[4] = uVar2;
          uVar7 = 0xc;
          if ((char)iVar1 != '\0') {
            _Size = (size_t)(uint)param_1[4];
            uVar7 = (ulonglong)uVar2 + 0xc;
            if (param_2 - 8 < _Size + 0x10) {
              *(undefined1 *)(param_3 + 2) = 0;
              uVar5 = 0xc000000d;
            }
            else {
              if (uVar7 <= param_4 - 8) {
                _Src = param_1 + 5;
                _Dst = param_3 + 5;
                uVar4 = uVar7;
                goto LAB_1c0010999;
              }
              *(undefined1 *)(param_3 + 2) = 0;
              uVar5 = 0xc0000023;
            }
          }
        }
        uVar4 = uVar4 + 8;
        uVar6 = 0x238;
        if (0x238 < uVar7 + 8) {
          uVar6 = uVar7 + 8;
        }
      }
LAB_1c0010a20:
      if (-1 < (int)uVar5) {
        if (0x238 < uVar4) goto LAB_1c00106a7;
LAB_1c0010a31:
        uVar4 = 0x238;
        goto LAB_1c00106a7;
      }
    }
    else {
      if (iVar8 == 7) goto LAB_1c00109d4;
      if (iVar8 == 8) {
        if (8 < param_2) {
          *(char *)(param_3 + 2) = (char)param_1[2];
          goto LAB_1c0010a31;
        }
      }
      else {
        if (iVar8 != 9) {
          if ((iVar8 != 10) && (iVar8 != 0xc)) goto LAB_1c00108e9;
          goto LAB_1c001092c;
        }
LAB_1c0010777:
        if (0x57 < param_2) {
          iVar1 = param_1[4];
          if (((iVar1 - 1U & 0xfffffffc) != 0) || (iVar1 == 2)) {
            uVar5 = 0xc00000ef;
            goto LAB_1c00106a5;
          }
          memset(param_3 + 2,0,0x230);
          *(undefined8 *)(param_3 + 2) = *(undefined8 *)(param_1 + 2);
          *(char *)(param_3 + 5) = (char)param_1[5];
          param_3[4] = param_1[4];
          uVar3 = *(undefined8 *)(param_1 + 8);
          *(undefined8 *)(param_3 + 6) = *(undefined8 *)(param_1 + 6);
          *(undefined8 *)(param_3 + 8) = uVar3;
          if (iVar1 == 3) {
            uVar3 = *(undefined8 *)(param_1 + 0xc);
            *(undefined8 *)(param_3 + 10) = *(undefined8 *)(param_1 + 10);
            *(undefined8 *)(param_3 + 0xc) = uVar3;
            uVar3 = *(undefined8 *)(param_1 + 0x10);
            *(undefined8 *)(param_3 + 0xe) = *(undefined8 *)(param_1 + 0xe);
            *(undefined8 *)(param_3 + 0x10) = uVar3;
          }
          uVar5 = SvRtlProtoRsvdToVirtstorVhdsetPath
                            ((char *)(param_1 + 0x12),param_2 - 0x48,(longlong)(param_3 + 0x8b),
                             param_4 - 0x22c,&local_38,&local_30);
          uVar5 = uVar5 & 0xffffffff;
          uVar4 = local_38 + 0x22c;
          if (local_30 + 0x22c < 0x239) {
            uVar6 = 0x238;
          }
          else {
            uVar6 = local_30 + 0x22c;
          }
          goto LAB_1c0010a20;
        }
      }
LAB_1c00106a0:
      uVar5 = 0xc000000d;
    }
  }
LAB_1c00106a5:
  uVar4 = 0;
LAB_1c00106a7:
  uVar7 = 0x238;
  if (0x238 < uVar6) {
    uVar7 = uVar6;
  }
  *param_5 = uVar4;
  *param_6 = uVar7;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_diid(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,param_5,iVar8,(char)*param_5,
                (char)uVar7,(char)uVar5);
  }
  return uVar5;
}



===== SvRtlProtoRsvdToVirtstorVhdsetPath @ 1c0010a40 =====

undefined8
SvRtlProtoRsvdToVirtstorVhdsetPath
          (char *param_1,ulonglong param_2,longlong param_3,ulonglong param_4,ulonglong *param_5,
          ulonglong *param_6)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  
  *param_5 = 0;
  *param_6 = 8;
  if (param_2 < 0xc) {
LAB_1c0010a75:
    uVar2 = 0xc000000d;
  }
  else {
    if (7 < param_4) {
      *(char *)(param_3 + 1) = *param_1;
      uVar1 = *(uint *)(param_1 + 4);
      *(uint *)(param_3 + 4) = uVar1;
      *param_5 = 8;
      if (*param_1 == '\0') {
        return 0;
      }
      if (param_2 < (ulonglong)*(uint *)(param_1 + 4) + 0xc) {
        *(undefined1 *)(param_3 + 1) = 0;
        goto LAB_1c0010a75;
      }
      uVar3 = (ulonglong)(*(uint *)(param_1 + 4) + 8);
      *param_6 = uVar3;
      if (uVar3 <= param_4) {
        memcpy((void *)(param_3 + 8),param_1 + 8,(ulonglong)uVar1);
        *param_5 = uVar3;
        return 0;
      }
      *(undefined1 *)(param_3 + 1) = 0;
    }
    uVar2 = 0xc0000023;
  }
  return uVar2;
}



===== entry @ 1c0011010 =====

void entry(longlong param_1,short *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 1c0011044 =====

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



===== DriverEntry @ 1c0011078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1,short *param_2)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  undefined2 uVar4;
  undefined1 auStack_1b8 [32];
  undefined4 local_198;
  undefined1 local_190;
  undefined8 *local_188;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 uStack_16c;
  undefined4 uStack_168;
  undefined4 uStack_164;
  longlong local_160;
  code *local_158;
  code *local_150;
  code *local_140;
  code *local_138;
  code *local_130;
  code *local_128;
  code *local_120;
  code *local_118;
  code *local_110;
  code *local_108;
  code *local_f0;
  code *local_e8;
  code *local_e0;
  code *local_d8;
  code *local_d0;
  code *local_c8;
  code *local_98;
  code *local_90;
  code *local_88;
  code *local_80;
  code *local_78;
  code *local_70;
  code *local_68;
  code *local_58;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_1b8;
  memset(&local_178,0,0x140);
  _DAT_1c0008188 = 1;
  _WPP_MAIN_CB = 0;
  DAT_1c0008168 = &WPP_ThisDir_CTLGUID_PVhdParserGuid;
  bVar1 = false;
  DAT_1c0008170 = 0;
  _DAT_1c0008180 = 0;
  WppLoadTracingSupport();
  _DAT_1c0008180 = 0;
  WppInitKm();
  *(code **)(param_1 + 0x68) = PVhdDriverUnload;
  local_188 = &PVhdDevice;
  local_190 = 0;
  local_198 = 0x100;
  iVar2 = IoCreateDevice(param_1,0,&PVhdDeviceName,0x22);
  if (iVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c001131e;
    uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    uVar4 = 0x81;
  }
  else {
    bVar1 = true;
    _RandSeed = (undefined4)_DAT_fffff78000000014;
    ClusKRTLReadParameterUlong(param_2);
    local_178 = 0x140;
    local_158 = PVhdOpenDisk;
    local_174 = 6;
    local_150 = PVhdCloseDisk;
    local_120 = PVhdQueryInformationDisk;
    local_140 = PVhdMountDisk;
    local_138 = PVhdDismountDisk;
    local_128 = PVhdExecuteScsiRequestDisk;
    local_118 = PVhdQuerySaveVersionDisk;
    local_110 = PVhdSaveDisk;
    local_108 = PVhdRestoreDisk;
    local_130 = PVhdQueryMountStatusDisk;
    local_f0 = PVhdSetQoSPolicyDisk;
    local_e8 = PVhdGetQoSStatusDisk;
    local_d8 = PVhdChangeTrackingGetParameters;
    local_e0 = PVhdChangeTrackingSetParameters;
    local_d0 = PVhdChangeTrackingStart;
    local_c8 = PVhdChangeTrackingStop;
    local_98 = PVhdPrepareMetaOperation;
    local_90 = PVhdStartMetaOperation;
    local_88 = PVhdCancelMetaOperation;
    local_80 = PVhdQueryMetaOperationProgress;
    local_78 = PVhdCleanupMetaOperation;
    local_70 = PVhdDeleteSnapshot;
    local_68 = PVhdQueryChanges;
    local_58 = PVhdSupportsDataTransferDirectionValidation;
    local_170 = 0xdd071510;
    uStack_16c = 0x41a79901;
    uStack_168 = 0xd0402783;
    uStack_164 = 0x4a4bfa8f;
    local_160 = param_1;
    iVar2 = VstorRegisterParser(&local_178);
    if (-1 < iVar2) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x83,
                &WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids);
      }
      return 0;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c001131e;
    uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    uVar4 = 0x82;
  }
  WPP_SF_d(uVar3,uVar4,&WPP_ded68ac50f2b3e6d9475a1670ab5463c_Traceguids,iVar2);
LAB_1c001131e:
  WppCleanupKm();
  if (bVar1) {
    IoDeleteDevice(PVhdDevice);
  }
  return iVar2;
}


