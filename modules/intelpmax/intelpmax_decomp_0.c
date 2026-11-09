
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



===== memcpy_s @ 1c0001020 =====

errno_t __cdecl memcpy_s(void *_Dst,rsize_t _DstSize,void *_Src,rsize_t _MaxCount)

{
  errno_t eVar1;
  
  if (_MaxCount == 0) {
LAB_1c000103d:
    eVar1 = 0;
  }
  else {
    if (_Dst == (void *)0x0) {
LAB_1c000107f:
      eVar1 = 0x16;
    }
    else {
      if ((_Src != (void *)0x0) && (_MaxCount <= _DstSize)) {
        memcpy(_Dst,_Src,_MaxCount);
        goto LAB_1c000103d;
      }
      memset(_Dst,0,_DstSize);
      if (_Src == (void *)0x0) goto LAB_1c000107f;
      if (_MaxCount <= _DstSize) {
        return 0x16;
      }
      eVar1 = 0x22;
    }
    _guard_check_icall();
  }
  return eVar1;
}



===== _guard_check_icall @ 1c00010c0 =====

void _guard_check_icall(void)

{
  return;
}



===== __cpu_features_init @ 1c00010e0 =====

/* WARNING: Removing unreachable block (ram,0x0001c000114a) */
/* WARNING: Removing unreachable block (ram,0x0001c00010f9) */
/* WARNING: Removing unreachable block (ram,0x0001c00010ea) */

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



===== RtlUnicodeStringCopy @ 1c00011a8 =====

undefined4 RtlUnicodeStringCopy(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  short sVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined2 *puVar7;
  ulonglong uVar8;
  
  uVar1 = *param_1;
  if ((((((uVar1 & 1) == 0) && (uVar2 = param_1[1], (uVar2 & 1) == 0)) && (uVar1 <= uVar2)) &&
      (uVar2 != 0xffff)) &&
     ((uVar3 = 0, *(longlong *)(param_1 + 4) != 0 || ((uVar1 == 0 && (uVar2 == 0)))))) {
    sVar4 = 0;
    uVar1 = *param_2;
    uVar8 = (ulonglong)(param_1[1] >> 1);
    if (((((uVar1 & 1) == 0) && (uVar2 = param_2[1], (uVar2 & 1) == 0)) &&
        ((uVar1 <= uVar2 && (uVar2 != 0xffff)))) &&
       ((*(longlong *)(param_2 + 4) != 0 || ((uVar1 == 0 && (uVar2 == 0)))))) {
      puVar7 = *(undefined2 **)(param_2 + 4);
      uVar6 = (ulonglong)(uVar1 >> 1);
      sVar4 = 0;
      if (uVar8 != 0) {
        lVar5 = *(longlong *)(param_1 + 4) - (longlong)puVar7;
        do {
          if (uVar6 == 0) goto LAB_1c0001286;
          uVar6 = uVar6 - 1;
          *(undefined2 *)(lVar5 + (longlong)puVar7) = *puVar7;
          sVar4 = sVar4 + 1;
          puVar7 = puVar7 + 1;
          uVar8 = uVar8 - 1;
        } while (uVar8 != 0);
      }
      uVar3 = 0;
      if (uVar6 != 0) {
        uVar3 = 0x80000005;
      }
    }
    else {
      uVar3 = 0xc000000d;
    }
LAB_1c0001286:
    *param_1 = sVar4 * 2;
  }
  else {
    uVar3 = 0xc000000d;
  }
  return uVar3;
}



===== WPP_RECORDER_SF_S @ 1c00012b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_S(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,wchar_t *param_6)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  
  lVar5 = -1;
  uVar4 = (ulonglong)(param_3 >> 0x10);
  lVar3 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar4 * 0x50 + 0x29])) {
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
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,
               &WPP_646089b57ff8355b93d5098264f52e68_Traceguids,param_4,pwVar2,lVar1,0);
  }
  if (param_6 != (wchar_t *)0x0) {
    do {
      lVar5 = lVar5 + 1;
    } while (param_6[lVar5] != L'\0');
    lVar3 = lVar5 * 2 + 2;
  }
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"NULL";
  }
  WppAutoLogTrace(param_1,param_2,param_3,&WPP_646089b57ff8355b93d5098264f52e68_Traceguids,param_4,
                  param_6,lVar3,0);
  return;
}



===== WPP_RECORDER_SF_SD @ 1c0001410 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_SD(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,wchar_t *param_6,undefined1 param_7)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  
  lVar5 = -1;
  uVar4 = (ulonglong)(param_3 >> 0x10);
  lVar3 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar4 * 0x50 + 0x29])) {
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
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,
               &WPP_646089b57ff8355b93d5098264f52e68_Traceguids,param_4,pwVar2,lVar1,&param_7,4,0);
  }
  if (param_6 != (wchar_t *)0x0) {
    do {
      lVar5 = lVar5 + 1;
    } while (param_6[lVar5] != L'\0');
    lVar3 = lVar5 * 2 + 2;
  }
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"NULL";
  }
  WppAutoLogTrace(param_1,param_2,param_3,&WPP_646089b57ff8355b93d5098264f52e68_Traceguids,param_4,
                  param_6,lVar3,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_Sd @ 1c00015a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Sd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,wchar_t *param_6,undefined1 param_7)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar4 = -1;
  lVar3 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
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
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_646089b57ff8355b93d5098264f52e68_Traceguids,param_4,pwVar2,lVar1,&param_7,4,0);
  }
  if (param_6 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (param_6[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"NULL";
  }
  WppAutoLogTrace(param_1,2,1,&WPP_646089b57ff8355b93d5098264f52e68_Traceguids,param_4,param_6,lVar3
                  ,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_Sdd @ 1c00016f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Sdd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,wchar_t *param_6,undefined1 param_7,undefined1 param_8)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar4 = -1;
  lVar3 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
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
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_646089b57ff8355b93d5098264f52e68_Traceguids,param_4,pwVar2,lVar1,&param_7,4,
               &param_8,4,0);
  }
  if (param_6 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (param_6[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"NULL";
  }
  WppAutoLogTrace(param_1,2,1,&WPP_646089b57ff8355b93d5098264f52e68_Traceguids,param_4,param_6,lVar3
                  ,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_SddS @ 1c000186c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_SddS(undefined8 param_1)

{
  longlong lVar1;
  longlong lVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  longlong lVar5;
  longlong lVar6;
  wchar_t *in_stack_00000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  wchar_t *in_stack_00000048;
  
  lVar6 = -1;
  lVar5 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000048 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000048[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar4 = in_stack_00000048;
    if (in_stack_00000048 == (wchar_t *)0x0) {
      pwVar4 = L"NULL";
    }
    if (in_stack_00000030 == (wchar_t *)0x0) {
      lVar2 = 10;
    }
    else {
      lVar2 = -1;
      do {
        lVar2 = lVar2 + 1;
      } while (in_stack_00000030[lVar2] != L'\0');
      lVar2 = lVar2 * 2 + 2;
    }
    pwVar3 = in_stack_00000030;
    if (in_stack_00000030 == (wchar_t *)0x0) {
      pwVar3 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_646089b57ff8355b93d5098264f52e68_Traceguids,0x35,pwVar3,lVar2,
               &uStack0000000000000038,4,&uStack0000000000000040,4,pwVar4,lVar1,0);
  }
  if (in_stack_00000048 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (in_stack_00000048[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (in_stack_00000048 == (wchar_t *)0x0) {
    in_stack_00000048 = L"NULL";
  }
  if (in_stack_00000030 != (wchar_t *)0x0) {
    do {
      lVar6 = lVar6 + 1;
    } while (in_stack_00000030[lVar6] != L'\0');
    lVar5 = lVar6 * 2 + 2;
  }
  if (in_stack_00000030 == (wchar_t *)0x0) {
    in_stack_00000030 = L"NULL";
  }
  WppAutoLogTrace(param_1,2,1,&WPP_646089b57ff8355b93d5098264f52e68_Traceguids,0x35,
                  in_stack_00000030,lVar5,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  in_stack_00000048,lVar1,0);
  return;
}



===== WPP_RECORDER_SF_Sddd @ 1c0001a58 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Sddd
               (undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,undefined8 param_5,
               wchar_t *param_6,undefined1 param_7,undefined1 param_8,undefined1 param_9)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  
  lVar5 = -1;
  uVar4 = (ulonglong)(param_3 >> 0x10);
  lVar3 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar4 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar4 * 0x50 + 0x29])) {
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
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar4 * 0x50 + 0x18),0x2b,
               &WPP_646089b57ff8355b93d5098264f52e68_Traceguids,param_4,pwVar2,lVar1,&param_7,4,
               &param_8,4,&param_9,4,0);
  }
  if (param_6 != (wchar_t *)0x0) {
    do {
      lVar5 = lVar5 + 1;
    } while (param_6[lVar5] != L'\0');
    lVar3 = lVar5 * 2 + 2;
  }
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"NULL";
  }
  WppAutoLogTrace(param_1,param_2,param_3,&WPP_646089b57ff8355b93d5098264f52e68_Traceguids,param_4,
                  param_6,lVar3,&param_7,4,&param_8,4,&param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_Sdddd @ 1c0001c3c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Sdddd(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  wchar_t *in_stack_00000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  lVar4 = -1;
  lVar3 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000030 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000030[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = in_stack_00000030;
    if (in_stack_00000030 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_646089b57ff8355b93d5098264f52e68_Traceguids,0x25,pwVar2,lVar1,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,0);
  }
  if (in_stack_00000030 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (in_stack_00000030[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (in_stack_00000030 == (wchar_t *)0x0) {
    in_stack_00000030 = L"NULL";
  }
  WppAutoLogTrace(param_1,2,1,&WPP_646089b57ff8355b93d5098264f52e68_Traceguids,0x25,
                  in_stack_00000030,lVar3,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_Sdddd_guid_ @ 1c0001e04 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Sdddd_guid_(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  wchar_t *in_stack_00000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  lVar4 = -1;
  lVar3 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000030 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000030[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = in_stack_00000030;
    if (in_stack_00000030 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_646089b57ff8355b93d5098264f52e68_Traceguids,0x36,pwVar2,lVar1,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4);
  }
  if (in_stack_00000030 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (in_stack_00000030[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (in_stack_00000030 == (wchar_t *)0x0) {
    in_stack_00000030 = L"NULL";
  }
  WppAutoLogTrace(param_1,2,1,&WPP_646089b57ff8355b93d5098264f52e68_Traceguids,0x36,
                  in_stack_00000030,lVar3,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4);
  return;
}



===== WPP_RECORDER_SF_Sddddd @ 1c0002004 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Sddddd
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,wchar_t *param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar4 = -1;
  lVar3 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
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
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_646089b57ff8355b93d5098264f52e68_Traceguids,param_4,pwVar2,lVar1,&param_7,4,
               &param_8,4,&param_9,4,&param_10,4,&param_11,4,0);
  }
  if (param_6 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (param_6[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"NULL";
  }
  WppAutoLogTrace(param_1,2,1,&WPP_646089b57ff8355b93d5098264f52e68_Traceguids,param_4,param_6,lVar3
                  ,&param_7,4,&param_8,4,&param_9,4,&param_10,4,&param_11,4,0);
  return;
}



===== WPP_RECORDER_SF_Sdddddd @ 1c00021f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Sdddddd(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  wchar_t *in_stack_00000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  lVar4 = -1;
  lVar3 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000030 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000030[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = in_stack_00000030;
    if (in_stack_00000030 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_646089b57ff8355b93d5098264f52e68_Traceguids,0x21,pwVar2,lVar1,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,0);
  }
  if (in_stack_00000030 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (in_stack_00000030[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (in_stack_00000030 == (wchar_t *)0x0) {
    in_stack_00000030 = L"NULL";
  }
  WppAutoLogTrace(param_1,2,1,&WPP_646089b57ff8355b93d5098264f52e68_Traceguids,0x21,
                  in_stack_00000030,lVar3,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,0);
  return;
}



===== WPP_RECORDER_SF_Sdddddddd @ 1c00023fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Sdddddddd(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  wchar_t *in_stack_00000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  undefined1 uStack0000000000000070;
  
  lVar4 = -1;
  lVar3 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000030 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000030[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = in_stack_00000030;
    if (in_stack_00000030 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_646089b57ff8355b93d5098264f52e68_Traceguids,0x2f,pwVar2,lVar1,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,
               &uStack0000000000000068,4,&uStack0000000000000070,4,0);
  }
  if (in_stack_00000030 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (in_stack_00000030[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (in_stack_00000030 == (wchar_t *)0x0) {
    in_stack_00000030 = L"NULL";
  }
  WppAutoLogTrace(param_1,2,1,&WPP_646089b57ff8355b93d5098264f52e68_Traceguids,0x2f,
                  in_stack_00000030,lVar3,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,&uStack0000000000000068,4,&uStack0000000000000070,4,0);
  return;
}



===== SetPowerLimit @ 1c0002660 =====

void SetPowerLimit(longlong param_1,uint param_2)

{
  undefined1 auVar1 [16];
  longlong lVar2;
  ulonglong uVar3;
  
  uVar3 = (ulonglong)*(uint *)(param_1 + 0x48) * (ulonglong)param_2;
  auVar1._8_8_ = 0;
  auVar1._0_8_ = uVar3;
  lVar2 = SUB168(ZEXT816(0x624dd2f1a9fbe77) * auVar1,8);
  uVar3 = (uVar3 - lVar2 >> 1) + lVar2 >> 9;
  if (0xffffffff < uVar3) {
    uVar3 = 0xffffffff;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_Dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  **(undefined4 **)(param_1 + 0x40) = (int)uVar3;
  LOCK();
  UNLOCK();
  return;
}



===== WPP_RECORDER_SF_ @ 1c00026e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                     undefined8 param_5)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,param_5,param_4,0);
  }
  WppAutoLogTrace(param_1,2,param_3,param_5,param_4,0);
  return;
}



===== WPP_RECORDER_SF_D @ 1c00027a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_D(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
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



===== WppClassicProviderCallback @ 1c00028b0 =====

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



===== WPP_RECORDER_SF_Dd @ 1c000290c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Dd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_6e250f8174553bd178ecbbb9f2cab3da_Traceguids,0x10,&uStack0000000000000030,4,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,4,5,&WPP_6e250f8174553bd178ecbbb9f2cab3da_Traceguids,0x10,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_s @ 1c00029dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_s(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  char *in_stack_00000030;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000030 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (in_stack_00000030[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = in_stack_00000030;
    if (in_stack_00000030 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_6e250f8174553bd178ecbbb9f2cab3da_Traceguids,10,pcVar1,lVar3,0);
  }
  lVar3 = -1;
  if (in_stack_00000030 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (in_stack_00000030[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (in_stack_00000030 == (char *)0x0) {
    in_stack_00000030 = "NULL";
  }
  WppAutoLogTrace(param_1,2,2,&WPP_6e250f8174553bd178ecbbb9f2cab3da_Traceguids,10,in_stack_00000030,
                  lVar2,0);
  return;
}



===== FxStubDriverUnloadCommon @ 1c0002af0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  void **ppvVar1;
  void **ppvVar2;
  
  ppvVar1 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0006158 != &__KMDF_CLASS_BIND_START) {
    ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_1c0006158 + 0x50);
    while( true ) {
      for (; (ppvVar1 + 1 <= ppvVar2 && (*ppvVar1 == (void *)0x0)); ppvVar1 = ppvVar1 + 1) {
      }
      if (ppvVar1 < ppvVar2) break;
      ppvVar1 = ppvVar2;
LAB_1c0002b49:
      if (ppvVar1 == (void **)0x0) goto LAB_1c0002b9f;
      if (ppvVar2 <= ppvVar1) goto LAB_1c0002bb7;
      if (ppvVar1[8] == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      else {
        (*ppvVar1[8])(WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      ppvVar1 = (void **)((longlong)ppvVar1 + (ulonglong)*(uint *)ppvVar1);
    }
    if ((ppvVar1 + 10 <= ppvVar2) && (*(uint *)ppvVar1 == 0x50)) goto LAB_1c0002b49;
LAB_1c0002b9f:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_1c0002bb7:
  WdfVersionUnbind(&DAT_1c00063d0,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 1c0002bf0 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 1c0002c24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FxDriverEntryWorker(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  _WDF_BIND_INFO *p_Var4;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  if (param_1 == (_WDF_BIND_INFO *)0x0) {
    uVar3 = DriverEntry(0,param_2);
  }
  else {
    _DAT_1c00063d0 = 0x2080000;
    _DAT_1c00063d8 = &DAT_1c00061c0;
    RtlCopyUnicodeString(&DAT_1c00063d0);
    p_Var4 = param_1;
    uVar3 = WdfVersionBind(param_1,&DAT_1c00063d0,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < (int)uVar3) {
      uVar1 = FxStubBindClasses(p_Var4);
      if ((-1 < (int)uVar1) && (uVar1 = FxStubInitTypes(), -1 < (int)uVar1)) {
        uVar3 = DriverEntry(param_1,param_2);
        uVar1 = (uint)uVar3;
        if (-1 < (int)uVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_1c00063c8 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",uVar3 & 0xffffffff,
                   &DAT_1c00063d0);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0006158 != &__KMDF_CLASS_BIND_START) {
          local_1c = 0;
          uStack_18 = 0;
          local_28 = &GUID_WDF_LOADER_INTERFACE_DRIVER_ENTRY_FAILURE;
          local_14 = 0;
          local_20 = 0x18;
          iVar2 = WdfLdrQueryInterface(&local_28);
          if (-1 < iVar2) {
            (*(code *)CONCAT44(local_14,uStack_18))(&WdfBindInfo,WdfDriverGlobals);
          }
        }
      }
      FxStubDriverUnloadCommon();
      uVar3 = (ulonglong)uVar1;
    }
  }
  return uVar3;
}



===== FxStubDriverUnload @ 1c0002db0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_1c00063c8 != (code *)0x0) && (DAT_1c00063c8 != FxStubDriverUnload)) {
    (*DAT_1c00063c8)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 1c0002de4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0002e09) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  int iVar1;
  void **ppvVar2;
  
  iVar1 = 0;
  ppvVar2 = &__KMDF_CLASS_BIND_END;
  while( true ) {
    for (; (ppvVar2 + 1 < (void **)((longlong)&__KMDF_CLASS_BIND_END + 1) &&
           (*ppvVar2 == (void *)0x0)); ppvVar2 = ppvVar2 + 1) {
    }
    if ((void **)0x1c000614f < ppvVar2) break;
    if (((&__KMDF_CLASS_BIND_END < ppvVar2 + 10) || (*(uint *)ppvVar2 != 0x50)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_1c0006158 = (undefined *)ppvVar2;
    if (ppvVar2[7] == (code *)0x0) {
      iVar1 = WdfVersionBindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: VersionBindClass WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,ppvVar2,ppvVar2[1],iVar1);
        return iVar1;
      }
    }
    else {
      iVar1 = (*ppvVar2[7])(WdfVersionBindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: ClientBindClass %p, WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,ppvVar2[7],ppvVar2,ppvVar2[1],iVar1);
        return iVar1;
      }
    }
    ppvVar2 = (void **)((ulonglong)*(uint *)ppvVar2 + (longlong)ppvVar2);
  }
  return iVar1;
}



===== FxStubInitTypes @ 1c0002f6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0002f89) */
/* long __cdecl FxStubInitTypes(void) */

long __cdecl FxStubInitTypes(void)

{
  void *pvVar1;
  void **ppvVar2;
  
  ppvVar2 = &__KMDF_TYPE_INIT_END;
  while( true ) {
    for (; (ppvVar2 + 1 < (void **)((longlong)&__KMDF_TYPE_INIT_END + 1) &&
           (*ppvVar2 == (void *)0x0)); ppvVar2 = ppvVar2 + 1) {
    }
    if ((void **)0x1c000616f < ppvVar2) break;
    if (((&__KMDF_TYPE_INIT_END < ppvVar2 + 5) || (*(uint *)ppvVar2 != 0x28)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextObjectContextTypeInfo failed\n");
      return -0x3fffff85;
    }
    if (ppvVar2[4] != (code *)0x0) {
      pvVar1 = (void *)(*ppvVar2[4])();
      ppvVar2[3] = pvVar1;
    }
    ppvVar2 = (void **)((ulonglong)*(uint *)ppvVar2 + (longlong)ppvVar2);
  }
  return 0;
}



===== __security_check_cookie @ 1c0003040 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0003080 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c00030b0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c00030b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c00030e0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0003140 =====

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



===== memset @ 1c0003440 =====

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



===== __memset_repmovs @ 1c0003580 =====

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



===== __memset_query @ 1c0003600 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0003680 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c00037c0 =====

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



===== __memset_spec_plain @ 1c0003840 =====

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



===== AcpiEvaluateDsm @ 1c0009008 =====

int AcpiEvaluateDsm(undefined8 *param_1,longlong param_2,undefined8 param_3,undefined4 param_4,
                   longlong *param_5)

{
  int iVar1;
  int *piVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong local_res10;
  undefined4 local_res18 [4];
  
  local_res18[0] = 0;
  *param_5 = 0;
  local_res10 = param_2;
  piVar2 = (int *)ExAllocatePool2(0x40,0x48,0x78614d50);
  if (piVar2 == (int *)0x0) {
    iVar1 = -0x3fffff66;
  }
  else {
    piVar2[2] = 0x48;
    *piVar2 = 0x43696541;
    piVar2[1] = 0x4d53445f;
    piVar2[3] = 4;
    piVar2[4] = 0x100002;
    uVar4 = 0x10;
    memcpy_s(piVar2 + 5,0x10,&GUID_PMAX_DSM,0x10);
    uVar3 = (ulonglong)*(ushort *)((longlong)piVar2 + 0x12);
    if (*(ushort *)((longlong)piVar2 + 0x12) < 4) {
      uVar3 = 4;
    }
    *(undefined8 *)((longlong)piVar2 + uVar3 + 0x14) = 0x40000;
    *(undefined4 *)((longlong)piVar2 + uVar3 + 0x1c) = 0x40000;
    *(undefined4 *)((longlong)piVar2 + uVar3 + 0x20) = param_4;
    *(undefined8 *)((longlong)piVar2 + uVar3 + 0x24) = 0x40003;
    local_res10 = 0;
    iVar1 = AcpiEvaluateMethod(param_1,uVar4,piVar2,&local_res10,local_res18);
    if (-1 < iVar1) {
      *param_5 = local_res10;
    }
    ExFreePoolWithTag(piVar2,0x78614d50);
  }
  return iVar1;
}



===== AcpiEvaluateMethod @ 1c0009128 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int AcpiEvaluateMethod(undefined8 *param_1,undefined8 param_2,int *param_3,longlong *param_4,
                      undefined4 *param_5)

{
  int iVar1;
  longlong lVar2;
  int iVar3;
  undefined4 uVar4;
  int local_res18 [2];
  longlong local_res20;
  ulonglong local_68;
  longlong local_60;
  undefined4 local_58;
  undefined4 local_54;
  ulonglong local_50;
  int *local_48;
  int local_40;
  undefined4 local_3c;
  
  local_50 = (ulonglong)(uint)local_50;
  local_68 = (ulonglong)(uint)local_68;
  local_res18[0] = 0;
  local_res18[1] = 0;
  local_res20 = 0;
  *param_4 = 0;
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  if (param_3 == (int *)0x0) {
    param_3 = local_res18;
    local_res18[0] = 0x42696541;
    local_res18[1] = 0x4d53445f;
  }
  else {
    iVar3 = *param_3;
    if (iVar3 != 0x42696541) {
      if (iVar3 == 0x43696541) {
        iVar3 = param_3[2];
      }
      else if (iVar3 == 0x49696541) {
        iVar3 = 0xc;
      }
      else {
        if (iVar3 != 0x53696541) {
          return -0x3fffff10;
        }
        iVar3 = param_3[2] + 0xf;
      }
      goto LAB_1c0009188;
    }
  }
  iVar3 = 8;
LAB_1c0009188:
  uVar4 = 0x400;
  while( true ) {
    lVar2 = ExAllocatePool2(0x100,uVar4);
    if (lVar2 == 0) {
      return -0x3fffff66;
    }
    local_3c = 0;
    local_54 = 0;
    local_50 = 1;
    local_68 = 1;
    local_60 = lVar2;
    local_58 = uVar4;
    local_48 = param_3;
    local_40 = iVar3;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                      (WdfDriverGlobals,*param_1,0,0x32c004,&local_50,&local_68,0,&local_res20);
    if (iVar1 != -0x7ffffffb) break;
    uVar4 = *(undefined4 *)(lVar2 + 4);
    ExFreePoolWithTag(lVar2,0x78614d50);
  }
  if ((iVar1 < 0) || (local_res20 == 0)) {
    *param_4 = 0;
    ExFreePoolWithTag(lVar2,0x78614d50);
  }
  else {
    *param_4 = lVar2;
  }
  if (param_5 == (undefined4 *)0x0) {
    return iVar1;
  }
  *param_5 = (int)local_res20;
  return iVar1;
}



===== AcpiParseComponentData @ 1c00092f4 =====

undefined8
AcpiParseComponentData
          (longlong param_1,ulonglong param_2,ulonglong param_3,int param_4,undefined8 param_5,
          longlong param_6,ulonglong param_7,uint *param_8,uint *param_9)

{
  short *psVar1;
  ushort *puVar2;
  ushort uVar3;
  uint uVar4;
  char cVar5;
  undefined8 uVar6;
  char cVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  undefined2 uVar11;
  uint uVar12;
  short *psVar13;
  short *psVar14;
  short *psVar15;
  uint uVar16;
  short *psVar17;
  uint uVar18;
  int iVar19;
  short *psVar20;
  undefined8 in_stack_ffffffffffffff58;
  undefined1 uVar21;
  undefined8 *local_58;
  undefined8 *local_50;
  
  if (param_6 == 0) {
    local_50 = (undefined8 *)0x0;
    uVar8 = param_2;
  }
  else {
    local_50 = (undefined8 *)((ulonglong)*param_8 + param_6);
    if (param_4 == 0) {
      *(uint *)(param_7 + 0x28) = *param_8;
    }
    *(int *)(param_7 + 0x24) = *(int *)(param_7 + 0x24) + 1;
    uVar8 = param_7;
  }
  *param_8 = *param_8 + 0x18;
  psVar1 = (short *)(param_2 + 4);
  uVar21 = (undefined1)param_3;
  cVar7 = (char)param_4;
  if (psVar1 < (short *)(param_2 + 0xc)) {
    psVar13 = (short *)((ulonglong)*(ushort *)(param_2 + 2) + 4 + param_2);
    if ((short *)(param_2 + 0xc) <= psVar13) {
      puVar2 = (ushort *)(param_2 + 6);
      uVar3 = *puVar2;
      uVar8 = (ulonglong)uVar3;
      uVar10 = 4;
      if (3 < uVar3) {
        uVar10 = uVar8;
      }
      param_3 = uVar8;
      if (psVar1 < (short *)(uVar10 + 4 + (longlong)psVar1)) {
        if (uVar3 < 4) {
          param_3 = 4;
        }
        if ((short *)(param_2 + 8 + param_3) <= psVar13) {
          if (*psVar1 == 2) {
            if (*puVar2 == 0x10) {
              if (local_50 != (undefined8 *)0x0) {
                uVar6 = *(undefined8 *)(param_2 + 0x10);
                *local_50 = *(undefined8 *)(param_2 + 8);
                local_50[1] = uVar6;
              }
              goto LAB_1c00094bf;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
              return 0xc014000f;
            }
            uVar11 = 0x2a;
          }
          else {
            if (*psVar1 != 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_Sdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_3,0x28,
                                    in_stack_ffffffffffffff58,*(wchar_t **)(param_1 + 0x10),uVar21,
                                    cVar7 + '\x02');
              }
              return 0xc0140008;
            }
            if (*(int *)(param_2 + 8) == 0) {
              if (local_50 != (undefined8 *)0x0) {
                *local_50 = 0;
                local_50[1] = 0;
              }
LAB_1c00094bf:
              param_5._0_4_ = 0xffffffff;
              uVar10 = 1;
              uVar8 = (ulonglong)*puVar2;
              local_58 = (undefined8 *)0x0;
              if (*puVar2 < 4) {
                uVar8 = 4;
              }
              psVar13 = (short *)(param_2 + 8);
LAB_1c00094f1:
              psVar13 = (short *)((longlong)psVar13 + uVar8);
              uVar18 = 0;
              do {
                if (psVar13 < psVar1) {
                  return 0;
                }
                if (psVar13 + 4 <= psVar13) {
                  return 0;
                }
                psVar14 = (short *)((ulonglong)*(ushort *)(param_2 + 2) + 4 + param_2);
                if (psVar14 < psVar13 + 4) {
                  return 0;
                }
                uVar3 = psVar13[1];
                uVar9 = (ulonglong)uVar3;
                uVar8 = 4;
                if (3 < uVar3) {
                  uVar8 = uVar9;
                }
                if ((short *)(uVar8 + 4 + (longlong)psVar13) <= psVar13) {
                  return 0;
                }
                if (uVar3 < 4) {
                  uVar9 = 4;
                }
                if (psVar14 < (short *)(uVar9 + 4 + (longlong)psVar13)) {
                  return 0;
                }
                cVar5 = (char)uVar10;
                if (*psVar13 != 3) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                    return 0xc0140008;
                  }
                  uVar11 = 0x2b;
LAB_1c0009a16:
                  WPP_RECORDER_SF_Sddd
                            (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar11,
                             in_stack_ffffffffffffff58,*(wchar_t **)(param_1 + 0x10),uVar21,
                             cVar7 + '\x02',cVar5);
                  return 0xc0140008;
                }
                psVar14 = psVar13 + 2;
                if ((psVar13 + 6 <= psVar14) ||
                   (psVar17 = (short *)((ulonglong)(ushort)psVar13[1] + 4 + (longlong)psVar13),
                   psVar17 < psVar13 + 6)) {
LAB_1c00099eb:
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                    return 0xc014000b;
                  }
                  uVar11 = 0x2c;
LAB_1c000994b:
                  WPP_RECORDER_SF_Sddd
                            (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar11,
                             in_stack_ffffffffffffff58,*(wchar_t **)(param_1 + 0x10),uVar21,
                             cVar7 + '\x02',cVar5);
                  return 0xc014000b;
                }
                uVar3 = psVar13[3];
                uVar9 = (ulonglong)uVar3;
                uVar8 = 4;
                if (3 < uVar3) {
                  uVar8 = uVar9;
                }
                if ((short *)(uVar8 + 4 + (longlong)psVar14) <= psVar14) goto LAB_1c00099eb;
                if (uVar3 < 4) {
                  uVar9 = 4;
                }
                if (psVar17 < (short *)(uVar9 + 4 + (longlong)psVar14)) goto LAB_1c00099eb;
                if (*psVar14 != 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                    return 0xc0140008;
                  }
                  uVar11 = 0x2d;
                  goto LAB_1c0009a16;
                }
                uVar4 = *(uint *)(psVar13 + 4);
                if ((int)uVar10 == 1) {
                  if (uVar4 == 0) goto code_r0x0001c00095ea;
                }
                else if (uVar4 <= uVar18) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                    return 0xc014000f;
                  }
                  WPP_RECORDER_SF_Sdddddddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
                  return 0xc014000f;
                }
                uVar8 = (ulonglong)(ushort)psVar13[3];
                if ((ushort)psVar13[3] < 4) {
                  uVar8 = 4;
                }
                psVar17 = (short *)(uVar8 + 4 + (longlong)psVar14);
                if (((psVar17 < psVar14) || (psVar17 + 4 <= psVar17)) ||
                   (psVar20 = (short *)((ulonglong)(ushort)psVar13[1] + 4 + (longlong)psVar13),
                   psVar20 < psVar17 + 4)) {
LAB_1c0009938:
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                    return 0xc014000b;
                  }
                  uVar11 = 0x30;
                  goto LAB_1c000994b;
                }
                uVar3 = psVar17[1];
                uVar9 = (ulonglong)uVar3;
                uVar8 = 4;
                if (3 < uVar3) {
                  uVar8 = uVar9;
                }
                if ((short *)(uVar8 + 4 + (longlong)psVar17) <= psVar17) goto LAB_1c0009938;
                if (uVar3 < 4) {
                  uVar9 = 4;
                }
                if (psVar20 < (short *)(uVar9 + 4 + (longlong)psVar17)) goto LAB_1c0009938;
                if (*psVar17 != 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                    return 0xc0140008;
                  }
                  uVar11 = 0x31;
                  goto LAB_1c0009a16;
                }
                uVar8 = (ulonglong)(ushort)psVar17[1];
                uVar18 = *(uint *)(psVar17 + 2);
                if ((ushort)psVar17[1] < 4) {
                  uVar8 = 4;
                }
                psVar17 = (short *)((longlong)psVar17 + uVar8 + 4);
                if (((psVar17 < psVar14) || (psVar14 = psVar17 + 4, psVar14 <= psVar17)) ||
                   (psVar20 = (short *)((ulonglong)(ushort)psVar13[1] + 4 + (longlong)psVar13),
                   psVar20 < psVar14)) {
LAB_1c00097bd:
                  uVar16 = uVar18;
                }
                else {
                  uVar3 = psVar17[1];
                  psVar14 = (short *)(ulonglong)uVar3;
                  psVar15 = (short *)0x4;
                  if (3 < uVar3) {
                    psVar15 = psVar14;
                  }
                  if ((short *)((longlong)(psVar15 + 2) + (longlong)psVar17) <= psVar17)
                  goto LAB_1c00097bd;
                  psVar15 = psVar14;
                  if (uVar3 < 4) {
                    psVar15 = (short *)0x4;
                  }
                  if (psVar20 < (short *)((longlong)(psVar15 + 2) + (longlong)psVar17))
                  goto LAB_1c00097bd;
                  if (*psVar17 != 0) {
                    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                      return 0xc0140008;
                    }
                    uVar11 = 0x32;
                    goto LAB_1c0009a16;
                  }
                  uVar12 = *(uint *)(psVar17 + 2);
                  uVar16 = uVar12;
                  if (uVar18 < uVar12) {
                    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                      return 0xc014000f;
                    }
                    uVar11 = 0x33;
                    uVar16 = uVar18;
                    goto LAB_1c000978f;
                  }
                }
                if ((param_7 != 0) && (uVar12 = *(uint *)(param_7 + 4), uVar12 < uVar16)) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                    return 0xc014000f;
                  }
                  uVar11 = 0x34;
LAB_1c000978f:
                  WPP_RECORDER_SF_Sddddd
                            (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),psVar14,uVar10,uVar11,
                             in_stack_ffffffffffffff58,*(wchar_t **)(param_1 + 0x10),uVar21,
                             cVar7 + '\x02',cVar5,(char)uVar16,(char)uVar12);
                  return 0xc014000f;
                }
                iVar19 = uVar4 - (uint)param_5;
                if (param_6 != 0) {
                  if ((uint)param_5 == 0xffffffff) {
                    param_5._0_4_ = 0;
                    uVar12 = *param_9;
                    *(uint *)((longlong)local_50 + 0x14) = uVar12;
                    local_58 = (undefined8 *)((ulonglong)uVar12 + param_6);
                    *local_58 = 0;
                  }
                  uVar12 = (uint)param_5 + 1;
                  if (uVar12 < uVar4) {
                    do {
                      uVar8 = (ulonglong)(uint)param_5;
                      param_5._0_4_ = (uint)param_5 + 1;
                      *(undefined4 *)(local_58 + uVar12) = *(undefined4 *)(local_58 + uVar8);
                      *(undefined4 *)((longlong)local_58 + (ulonglong)uVar12 * 8 + 4) =
                           *(undefined4 *)((longlong)local_58 + uVar8 * 8 + 4);
                      uVar12 = uVar12 + 1;
                    } while (uVar12 < uVar4);
                  }
                  param_5._0_4_ = (uint)param_5 + 1;
                  *(uint *)(local_58 + (uint)param_5) = uVar16;
                  *(uint *)((longlong)local_58 + (ulonglong)(uint)param_5 * 8 + 4) = uVar18;
                  *(uint *)(local_50 + 2) = uVar4 + 1;
                }
                *param_9 = *param_9 + iVar19 * 0x18;
                uVar8 = (ulonglong)(ushort)psVar13[1];
                if ((ushort)psVar13[1] < 4) {
                  uVar8 = 4;
                }
                psVar13 = (short *)((longlong)psVar13 + uVar8 + 4);
                uVar10 = (ulonglong)((int)uVar10 + 1);
                uVar18 = uVar4;
              } while( true );
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
              return 0xc014000f;
            }
            uVar11 = 0x29;
          }
          WPP_RECORDER_SF_Sdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_3,uVar11,
                              in_stack_ffffffffffffff58,*(wchar_t **)(param_1 + 0x10),uVar21,
                              cVar7 + '\x02');
          return 0xc014000f;
        }
      }
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_Sdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,param_3,0x27,
                        in_stack_ffffffffffffff58,*(wchar_t **)(param_1 + 0x10),uVar21,
                        cVar7 + '\x02');
  }
  return 0xc014000b;
code_r0x0001c00095ea:
  if ((param_6 != 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_Sddd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),cVar5 + 3,2,(short)uVar10 + 0x2d,
               in_stack_ffffffffffffff58,*(wchar_t **)(param_1 + 0x10),uVar21,cVar7 + '\x02',cVar5);
  }
  uVar8 = (ulonglong)(ushort)psVar13[1];
  if ((ushort)psVar13[1] < 4) {
    uVar8 = 4;
  }
  psVar13 = psVar13 + 2;
  uVar10 = 2;
  goto LAB_1c00094f1;
}



===== AcpiParseDevicePowerStateData @ 1c0009ab0 =====

undefined8
AcpiParseDevicePowerStateData
          (longlong param_1,ulonglong param_2,undefined8 param_3,longlong param_4)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  int iVar5;
  uint uVar6;
  short *psVar7;
  undefined2 uVar8;
  uint *puVar9;
  short *psVar10;
  undefined8 in_stack_ffffffffffffff98;
  undefined1 uVar11;
  undefined1 uVar12;
  
  psVar7 = (short *)(param_2 + 4);
  uVar6 = 0;
  iVar5 = 0;
  uVar11 = (undefined1)param_3;
  uVar4 = param_2;
  if (psVar7 < (short *)(param_2 + 4 + (ulonglong)*(ushort *)(param_2 + 2))) {
    do {
      uVar12 = (undefined1)iVar5;
      if (*psVar7 != 3) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0xc0140008;
        }
        uVar8 = 0x1c;
LAB_1c0009e63:
        WPP_RECORDER_SF_Sdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,param_3,uVar8,
                            in_stack_ffffffffffffff98,*(wchar_t **)(param_1 + 0x10),uVar11,uVar12);
        return 0xc0140008;
      }
      psVar10 = psVar7 + 2;
      if ((short *)((ulonglong)(ushort)psVar7[1] + 4 + (longlong)psVar7) <= psVar10) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0xc014000b;
        }
        uVar8 = 0x1d;
LAB_1c0009da2:
        WPP_RECORDER_SF_Sdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,param_3,uVar8,
                            in_stack_ffffffffffffff98,*(wchar_t **)(param_1 + 0x10),uVar11,uVar12);
        return 0xc014000b;
      }
      if (*psVar10 != 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0xc0140008;
        }
        uVar8 = 0x1e;
        goto LAB_1c0009e63;
      }
      uVar1 = *(uint *)(psVar7 + 4);
      uVar4 = (ulonglong)uVar1;
      if (3 < uVar1) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_Sddd
                    (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x1f,in_stack_ffffffffffffff98,
                     *(wchar_t **)(param_1 + 0x10),uVar11,uVar12,(char)uVar1);
        }
        return 0xc014000f;
      }
      if (iVar5 == 0) {
        if (uVar1 != 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return 0xc014000f;
          }
          WPP_RECORDER_SF_Sdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,param_3,0x20,
                              in_stack_ffffffffffffff98,*(wchar_t **)(param_1 + 0x10),uVar11,
                              (char)uVar1);
          return 0xc014000f;
        }
      }
      else if (uVar1 <= uVar6) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0xc014000f;
        }
        WPP_RECORDER_SF_Sdddddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        return 0xc014000f;
      }
      if ((ushort)psVar7[3] < 4) {
        uVar2 = 4;
      }
      else {
        uVar2 = (ulonglong)(ushort)psVar7[3];
      }
      psVar10 = (short *)(uVar2 + 4 + (longlong)psVar10);
      if ((short *)((ulonglong)(ushort)psVar7[1] + 4 + (longlong)psVar7) <= psVar10) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0xc014000b;
        }
        uVar8 = 0x22;
        goto LAB_1c0009da2;
      }
      if (*psVar10 != 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0xc0140008;
        }
        uVar8 = 0x23;
        goto LAB_1c0009e63;
      }
      uVar6 = *(uint *)(psVar10 + 2);
      if ((ushort)psVar10[1] < 4) {
        uVar2 = 4;
      }
      else {
        uVar2 = (ulonglong)(ushort)psVar10[1];
      }
      psVar10 = (short *)(uVar2 + 4 + (longlong)psVar10);
      if (psVar10 < (short *)((ulonglong)(ushort)psVar7[1] + 4 + (longlong)psVar7)) {
        if (*psVar10 != 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return 0xc0140008;
          }
          uVar8 = 0x24;
          goto LAB_1c0009e63;
        }
        uVar3 = *(uint *)(psVar10 + 2);
        if (uVar6 < *(uint *)(psVar10 + 2)) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return 0xc014000f;
          }
          WPP_RECORDER_SF_Sdddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          return 0xc014000f;
        }
      }
      else {
        uVar3 = uVar6;
      }
      if (param_4 != 0) {
        puVar9 = (uint *)(param_4 + 8 + uVar4 * 8);
        uVar2 = (ulonglong)(4 - uVar1);
        do {
          puVar9[-1] = uVar3;
          *puVar9 = uVar6;
          puVar9 = puVar9 + 2;
          uVar2 = uVar2 - 1;
        } while (uVar2 != 0);
      }
      uVar2 = (ulonglong)(ushort)psVar7[1];
      if ((ushort)psVar7[1] < 4) {
        uVar2 = 4;
      }
      psVar7 = (short *)((longlong)psVar7 + uVar2 + 4);
      iVar5 = iVar5 + 1;
      uVar6 = uVar1;
    } while (psVar7 < (short *)((ulonglong)*(ushort *)(param_2 + 2) + 4 + param_2));
    if (iVar5 != 0) {
      return 0;
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_Sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,param_3,0x26,
                       in_stack_ffffffffffffff98,*(wchar_t **)(param_1 + 0x10),uVar11);
  }
  return 0xc014000b;
}



===== AcpiParsePowerPlane @ 1c0009e98 =====

ulonglong AcpiParsePowerPlane(longlong param_1,longlong param_2,undefined4 param_3,longlong param_4,
                             uint *param_5,uint *param_6,uint *param_7,uint *param_8)

{
  ushort uVar1;
  uint uVar2;
  short *psVar3;
  short sVar4;
  int iVar5;
  short *psVar6;
  ulonglong uVar7;
  ushort *puVar8;
  longlong lVar9;
  ushort *puVar10;
  ushort uVar11;
  ushort *puVar12;
  ushort *puVar13;
  ushort *puVar14;
  undefined2 uVar15;
  ushort *puVar16;
  uint *local_res8;
  undefined4 in_stack_ffffffffffffff68;
  undefined4 in_stack_ffffffffffffff6c;
  undefined8 local_68;
  short *psStack_60;
  longlong local_58;
  longlong lStack_50;
  ushort local_48;
  undefined1 auStack_46 [6];
  ushort *puStack_40;
  
  psVar3 = *(short **)(param_1 + 0x10);
  local_res8 = (uint *)0x0;
  uVar7 = 0;
  _local_48 = 0;
  puStack_40 = (ushort *)0x0;
  local_58 = 0;
  lStack_50 = 0;
  local_68 = (ushort *)0x0;
  psStack_60 = (short *)0x0;
  if (psVar3 != (short *)0x0) {
    lVar9 = 0x7fff;
    psVar6 = psVar3;
    do {
      if (*psVar6 == 0) break;
      psVar6 = psVar6 + 1;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    uVar7 = (ulonglong)(~-(uint)(lVar9 != 0) & 0xc000000d);
    if (lVar9 != 0) {
      sVar4 = (0x7fff - (short)lVar9) * 2;
      uVar11 = sVar4 + 2;
      local_68 = (ushort *)(ulonglong)CONCAT22(uVar11,sVar4);
      psStack_60 = psVar3;
      goto LAB_1c0009f3b;
    }
  }
  local_68._2_2_ = 0;
  uVar11 = local_68._2_2_;
LAB_1c0009f3b:
  if (-1 < (int)uVar7) {
    if (param_4 != 0) {
      uVar2 = *param_8;
      *(uint *)(param_4 + 0x18) = uVar2;
      lStack_50 = (ulonglong)uVar2 + param_4;
      local_58 = (ulonglong)uVar11 << 0x10;
      RtlUnicodeStringCopy((ushort *)&local_58,(ushort *)&local_68);
    }
    puVar10 = (ushort *)0x1;
    *param_8 = *param_8 + (uint)uVar11;
    puVar12 = (ushort *)(param_2 + 0xc);
    local_68 = puVar12;
    if (*puVar12 == 3) {
      while( true ) {
        puVar13 = (ushort *)0x4;
        uVar11 = 0;
        if (((puVar12 < local_68) || (puVar12 + 4 <= puVar12)) ||
           (puVar14 = (ushort *)((ulonglong)(*(int *)(param_2 + 4) - 0xc) + 0xc + param_2),
           puVar14 < puVar12 + 4)) break;
        uVar1 = puVar12[1];
        puVar10 = (ushort *)(ulonglong)uVar1;
        puVar16 = puVar13;
        if (3 < uVar1) {
          puVar16 = puVar10;
        }
        if ((ushort *)((longlong)(puVar16 + 2) + (longlong)puVar12) <= puVar12) break;
        if (uVar1 < 4) {
          puVar10 = puVar13;
        }
        if (puVar14 < (ushort *)((longlong)(puVar10 + 2) + (longlong)puVar12)) break;
        if (*puVar12 != 3) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar15 = 0x14;
LAB_1c000a47a:
            WPP_RECORDER_SF_Sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar10,puVar14,uVar15,
                               CONCAT44(in_stack_ffffffffffffff6c,in_stack_ffffffffffffff68),
                               *(wchar_t **)(param_1 + 0x10),(char)*param_5);
          }
          goto LAB_1c0009fc0;
        }
        puVar10 = puVar12 + 2;
        if ((puVar12 + 6 <= puVar10) ||
           (puVar16 = (ushort *)((ulonglong)puVar12[1] + 4 + (longlong)puVar12),
           puVar16 < puVar12 + 6)) {
LAB_1c000a424:
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return 0xc014000b;
          }
          uVar15 = 0x15;
LAB_1c000a43a:
          WPP_RECORDER_SF_Sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar10,puVar14,uVar15,
                             CONCAT44(in_stack_ffffffffffffff6c,in_stack_ffffffffffffff68),
                             *(wchar_t **)(param_1 + 0x10),(char)*param_5);
          return 0xc014000b;
        }
        uVar1 = puVar12[3];
        puVar14 = (ushort *)(ulonglong)uVar1;
        puVar8 = puVar13;
        if (3 < uVar1) {
          puVar8 = puVar14;
        }
        if ((ushort *)((longlong)(puVar8 + 4) + (longlong)puVar12) <= puVar10) goto LAB_1c000a424;
        if (uVar1 < 4) {
          puVar14 = puVar13;
        }
        if (puVar16 < (ushort *)((longlong)(puVar14 + 4) + (longlong)puVar12)) goto LAB_1c000a424;
        if (*puVar10 != 1) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar15 = 0x16;
            goto LAB_1c000a47a;
          }
          goto LAB_1c0009fc0;
        }
        uVar1 = puVar12[3];
        uVar7 = (ulonglong)uVar1;
        puVar14 = puVar12 + 4;
        if (puVar14 == (ushort *)0x0) {
LAB_1c000a0f7:
          uVar11 = 0;
        }
        else {
          puVar10 = puVar14;
          if (uVar7 != 0) {
            do {
              if ((char)*puVar10 == '\0') break;
              puVar10 = (ushort *)((longlong)puVar10 + 1);
              uVar7 = uVar7 - 1;
            } while (uVar7 != 0);
            if (uVar7 != 0) {
              uVar11 = uVar1 - (short)uVar7;
            }
          }
          if (uVar7 == 0) goto LAB_1c000a0f7;
        }
        _local_48 = CONCAT62(CONCAT42(auStack_46._2_4_,uVar1),uVar11);
        puStack_40 = puVar14;
        if (uVar11 < 3) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return 0xc014000f;
          }
          uVar15 = 0x17;
LAB_1c000a3df:
          WPP_RECORDER_SF_Sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar10,puVar14,uVar15,
                             CONCAT44(in_stack_ffffffffffffff6c,in_stack_ffffffffffffff68),
                             *(wchar_t **)(param_1 + 0x10),(char)*param_5);
          return 0xc014000f;
        }
        if ((char)*puVar14 != '\\') {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return 0xc014000f;
          }
          uVar15 = 0x18;
          goto LAB_1c000a3df;
        }
        iVar5 = RtlxAnsiStringToUnicodeSize();
        if (param_4 != 0) {
          puVar10 = &local_48;
          lStack_50 = (ulonglong)*param_8 + param_4;
          uVar7 = (ulonglong)local_58 >> 0x20;
          puVar14 = (ushort *)0x0;
          local_58._0_4_ = iVar5 << 0x10;
          local_58 = CONCAT44((int)uVar7,(int)local_58);
          RtlAnsiStringToUnicodeString(&local_58);
          local_res8 = (uint *)((ulonglong)*param_5 * 0x2c + 0x20 + param_4);
          *local_res8 = *param_8;
        }
        *param_8 = *param_8 + iVar5;
        uVar7 = (ulonglong)puVar12[3];
        if (puVar12[3] < 4) {
          uVar7 = 4;
        }
        puVar13 = (ushort *)(uVar7 + 8 + (longlong)puVar12);
        if (((puVar13 < puVar12 + 2) || (puVar13 + 4 <= puVar13)) ||
           (puVar14 = (ushort *)((ulonglong)puVar12[1] + 4 + (longlong)puVar12),
           puVar14 < puVar13 + 4)) {
LAB_1c000a392:
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return 0xc014000b;
          }
          uVar15 = 0x19;
          goto LAB_1c000a43a;
        }
        uVar11 = puVar13[1];
        puVar10 = (ushort *)(ulonglong)uVar11;
        puVar16 = (ushort *)0x4;
        if (3 < uVar11) {
          puVar16 = puVar10;
        }
        if ((ushort *)((longlong)(puVar16 + 2) + (longlong)puVar13) <= puVar13) goto LAB_1c000a392;
        if (uVar11 < 4) {
          puVar10 = (ushort *)0x4;
        }
        if (puVar14 < (ushort *)((longlong)(puVar10 + 2) + (longlong)puVar13)) goto LAB_1c000a392;
        if (*puVar13 != 3) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar15 = 0x1a;
            goto LAB_1c000a47a;
          }
          goto LAB_1c0009fc0;
        }
        puVar10 = puVar13;
        uVar7 = AcpiParseDevicePowerStateData
                          (param_1,(ulonglong)puVar13,(ulonglong)*param_5,(longlong)local_res8);
        if ((int)uVar7 < 0) {
          return uVar7;
        }
        uVar7 = (ulonglong)puVar13[1];
        if (puVar13[1] < 4) {
          uVar7 = 4;
        }
        iVar5 = 2;
        for (puVar13 = (ushort *)((longlong)puVar13 + uVar7 + 4);
            ((puVar14 = (ushort *)0x4, puVar12 + 2 <= puVar13 && (puVar13 < puVar13 + 4)) &&
            (puVar16 = (ushort *)((ulonglong)puVar12[1] + 4 + (longlong)puVar12),
            puVar13 + 4 <= puVar16)); puVar13 = (ushort *)((longlong)puVar13 + uVar7 + 4)) {
          uVar11 = puVar13[1];
          puVar10 = (ushort *)(ulonglong)uVar11;
          puVar8 = puVar14;
          if (3 < uVar11) {
            puVar8 = puVar10;
          }
          if ((ushort *)((longlong)(puVar8 + 2) + (longlong)puVar13) <= puVar13) break;
          if (uVar11 < 4) {
            puVar10 = puVar14;
          }
          if (puVar16 < (ushort *)((longlong)(puVar10 + 2) + (longlong)puVar13)) break;
          if (*puVar13 != 3) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_Sdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar10,puVar16,0x1b,
                                  CONCAT44(in_stack_ffffffffffffff6c,in_stack_ffffffffffffff68),
                                  *(wchar_t **)(param_1 + 0x10),(char)*param_5,(char)iVar5);
            }
            goto LAB_1c0009fc0;
          }
          puVar10 = puVar13;
          in_stack_ffffffffffffff68 = param_3;
          uVar7 = AcpiParseComponentData
                            (param_1,(ulonglong)puVar13,(ulonglong)*param_5,iVar5 + -2,
                             CONCAT44(in_stack_ffffffffffffff6c,param_3),param_4,
                             (ulonglong)local_res8,param_6,param_7);
          if ((int)uVar7 < 0) {
            return uVar7;
          }
          uVar7 = (ulonglong)puVar13[1];
          if (puVar13[1] < 4) {
            uVar7 = 4;
          }
          iVar5 = iVar5 + 1;
        }
        puVar13 = (ushort *)(ulonglong)puVar12[1];
        if (puVar12[1] < 4) {
          puVar13 = puVar14;
        }
        puVar12 = (ushort *)((longlong)puVar12 + (longlong)(puVar13 + 2));
        *param_5 = *param_5 + 1;
      }
      if (param_4 != 0) {
        *(uint *)(param_4 + 0x1c) = *param_5;
        uVar7 = AcpiValidatePowerPlaneConsistency(param_1,puVar10,param_4);
        if ((int)uVar7 < 0) {
          return uVar7;
        }
      }
      uVar7 = 0;
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x13,
                          CONCAT44(in_stack_ffffffffffffff6c,in_stack_ffffffffffffff68),
                          *(wchar_t **)(param_1 + 0x10));
      }
LAB_1c0009fc0:
      uVar7 = 0xc0140008;
    }
  }
  return uVar7;
}



===== AcpiQueryPowerPlaneDefinition @ 1c000a4e0 =====

int AcpiQueryPowerPlaneDefinition(undefined8 *param_1,longlong *param_2,int *param_3)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint local_res10 [2];
  uint local_res18 [2];
  uint local_res20 [2];
  longlong *plVar9;
  uint *puVar10;
  uint local_48 [2];
  longlong local_40;
  
  plVar9 = &local_40;
  local_48[0] = 0;
  local_res10[0] = 0;
  local_res20[0] = 0;
  local_res18[0] = 0;
  *param_2 = 0;
  *param_3 = 0;
  local_40 = 0;
  iVar2 = AcpiEvaluateDsm(param_1,(longlong)param_2,param_3,1,plVar9);
  lVar1 = local_40;
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_SD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xf,plVar9,
                         (wchar_t *)param_1[2],(char)iVar2);
    }
  }
  else if (*(int *)(local_40 + 8) == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x10,plVar9,
                        (wchar_t *)param_1[2]);
    }
    iVar2 = -0x3febfff1;
  }
  else if (*(uint *)(local_40 + 4) < 0x14) {
    iVar2 = -0x7ffffffb;
  }
  else {
    puVar10 = local_res10;
    uVar3 = AcpiParsePowerPlane((longlong)param_1,local_40,0,0,puVar10,local_48,local_res20,
                                local_res18);
    iVar2 = (int)uVar3;
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x11,puVar10,
                          (wchar_t *)param_1[2]);
      }
    }
    else if (local_res10[0] == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,2,0x12,puVar10,
                          (wchar_t *)param_1[2]);
      }
      iVar2 = -0x3ffffffe;
    }
    else {
      uVar5 = local_res10[0] * 0x2c + 0x20;
      uVar6 = uVar5 + local_48[0] + 3 & 0xfffffffc;
      uVar7 = uVar6 + local_res20[0] + 1 & 0xfffffffe;
      iVar8 = uVar7 + local_res18[0];
      local_res18[0] = uVar7;
      local_res20[0] = uVar6;
      local_48[0] = uVar5;
      lVar4 = ExAllocatePool2(0x100,iVar8,0x78614d50);
      if (lVar4 == 0) {
        iVar2 = -0x3fffff66;
      }
      else {
        *(uint *)(lVar4 + 0x1c) = local_res10[0];
        local_res10[0] = 0;
        uVar3 = AcpiParsePowerPlane((longlong)param_1,lVar1,iVar8,lVar4,local_res10,local_48,
                                    local_res20,local_res18);
        iVar2 = (int)uVar3;
        *param_2 = lVar4;
        *param_3 = iVar8;
      }
    }
  }
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0x78614d50);
  }
  return iVar2;
}



===== AcpiQueryPowerPlaneDsmSupport @ 1c000a770 =====

undefined8 AcpiQueryPowerPlaneDsmSupport(undefined8 *param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  undefined2 uVar5;
  uint local_res10 [2];
  longlong local_res18 [2];
  longlong *plVar6;
  
  local_res10[0] = 0;
  local_res18[0] = 0;
  plVar6 = local_res18;
  uVar2 = AcpiEvaluateDsm(param_1,param_2,param_3,0,plVar6);
  lVar1 = local_res18[0];
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000a89f;
    uVar5 = 10;
    bVar3 = 2;
    uVar4 = 1;
LAB_1c000a882:
    WPP_RECORDER_SF_SD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar3,uVar4,uVar5,plVar6,
                       (wchar_t *)param_1[2],(char)uVar2);
  }
  else {
    if (*(int *)(local_res18[0] + 8) == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000a89f;
      uVar5 = 0xb;
    }
    else {
      if (*(uint *)(local_res18[0] + 4) < 0x14) goto LAB_1c000a89f;
      if (*(short *)(local_res18[0] + 0xc) == 2) {
        if (*(short *)(local_res18[0] + 0xe) != 0) {
          uVar2 = (uint)*(byte *)(local_res18[0] + 0x10);
          local_res10[0] = uVar2;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1c000a89f;
          uVar4 = 2;
          uVar5 = 0xe;
          bVar3 = 4;
          goto LAB_1c000a882;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000a89f;
        uVar5 = 0xd;
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000a89f;
        uVar5 = 0xc;
      }
    }
    WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar5,plVar6,
                      (wchar_t *)param_1[2]);
  }
LAB_1c000a89f:
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0x78614d50);
  }
  return CONCAT71((int7)((ulonglong)local_res10 >> 8),(local_res10[0] >> 1 & 1) != 0);
}



===== AcpiValidatePowerPlaneConsistency @ 1c000a8d8 =====

undefined8 AcpiValidatePowerPlaneConsistency(longlong param_1,undefined8 param_2,longlong param_3)

{
  longlong lVar1;
  short sVar2;
  short sVar3;
  short *psVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong lVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  undefined2 uVar11;
  uint uVar12;
  uint uVar13;
  uint *puVar14;
  ulonglong uVar15;
  uint *puVar16;
  longlong lVar17;
  uint local_res10;
  undefined8 in_stack_ffffffffffffff88;
  
  uVar8 = *(uint *)(param_3 + 0x1c);
  uVar13 = 0;
  if (uVar8 != 1) {
    uVar10 = 1;
    puVar14 = (uint *)(param_3 + 0x20);
    do {
      if (uVar10 < uVar8) {
        puVar16 = (uint *)((ulonglong)uVar10 * 0x2c + 0x20 + param_3);
        uVar12 = uVar10;
        do {
          psVar4 = (short *)((ulonglong)*puVar14 + param_3);
          do {
            sVar2 = *psVar4;
            sVar3 = *(short *)((longlong)psVar4 +
                              (((ulonglong)*puVar16 + param_3) -
                              (longlong)((ulonglong)*puVar14 + param_3)));
            if (sVar2 != sVar3) break;
            psVar4 = psVar4 + 1;
          } while (sVar3 != 0);
          if (sVar2 == sVar3) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
              return 0xc014000f;
            }
            WPP_RECORDER_SF_SddS(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
            return 0xc014000f;
          }
          uVar12 = uVar12 + 1;
          puVar16 = puVar16 + 0xb;
        } while (uVar12 < uVar8);
      }
      uVar13 = uVar13 + 1;
      uVar10 = uVar10 + 1;
      puVar14 = puVar14 + 0xb;
    } while (uVar13 < uVar8 - 1);
  }
  uVar9 = 0;
  if (uVar8 == 0) {
    return 0;
  }
  do {
    lVar17 = uVar9 * 0x2c;
    uVar8 = *(uint *)(lVar17 + 0x44 + param_3);
    if (uVar8 != 0) {
      uVar10 = 0;
      lVar6 = (ulonglong)*(uint *)(lVar17 + 0x48 + param_3) + param_3;
      local_res10 = 0;
      uVar13 = 0;
      uVar15 = 0;
      if (uVar8 != 0) {
        do {
          lVar1 = lVar6 + uVar15 * 0x18;
          if (*(int *)(lVar1 + 0x10) != 0) {
            lVar7 = (ulonglong)*(uint *)(lVar1 + 0x14) + param_3;
            uVar5 = (ulonglong)(*(int *)(lVar1 + 0x10) - 1);
            uVar10 = uVar10 + *(int *)(lVar7 + 4 + uVar5 * 8);
            uVar13 = uVar13 + *(int *)(lVar7 + uVar5 * 8);
            local_res10 = uVar13;
          }
          uVar12 = (int)uVar15 + 2;
          if (uVar12 < uVar8) {
            do {
              lVar7 = RtlCompareMemory(lVar1,lVar6 + (ulonglong)uVar12 * 0x18,0x10);
              if (lVar7 == 0x10) {
                if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
                  return 0xc014000f;
                }
                WPP_RECORDER_SF_Sdddd_guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
                return 0xc014000f;
              }
              uVar8 = *(uint *)(lVar17 + 0x44 + param_3);
              uVar12 = uVar12 + 1;
            } while (uVar12 < uVar8);
            uVar13 = local_res10;
          }
          uVar12 = (int)uVar15 + 1;
          uVar15 = (ulonglong)uVar12;
        } while (uVar12 < uVar8);
      }
      uVar8 = *(uint *)(lVar17 + 0x28 + param_3);
      if (uVar8 < uVar10) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0xc014000f;
        }
        uVar11 = 0x37;
LAB_1c000ab6d:
        WPP_RECORDER_SF_Sddd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,uVar11,in_stack_ffffffffffffff88,
                   *(wchar_t **)(param_1 + 0x10),(char)uVar9,(char)uVar10,(char)uVar8);
        return 0xc014000f;
      }
      uVar8 = *(uint *)(lVar17 + 0x24 + param_3);
      if (uVar8 < uVar13) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0xc014000f;
        }
        uVar11 = 0x38;
        uVar10 = uVar13;
        goto LAB_1c000ab6d;
      }
    }
    uVar8 = (int)uVar9 + 1;
    uVar9 = (ulonglong)uVar8;
    if (*(uint *)(param_3 + 0x1c) <= uVar8) {
      return 0;
    }
  } while( true );
}



===== EvtDevicePrepareHardware @ 1c000abc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int EvtDevicePrepareHardware(undefined8 param_1)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  wchar_t *pwVar4;
  longlong lVar5;
  void *_Dst;
  undefined8 uVar6;
  byte bVar7;
  longlong lVar8;
  undefined8 *puVar9;
  ulonglong _Size;
  undefined2 uVar10;
  int local_res20 [2];
  ulonglong uVar11;
  undefined4 local_78 [2];
  undefined8 *local_70;
  undefined8 local_68;
  undefined8 local_60;
  ulonglong local_58;
  longlong local_50;
  undefined8 local_48;
  ulonglong local_40;
  undefined *local_38;
  undefined8 local_30;
  
  local_40 = (ulonglong)(uint)local_40;
  local_68 = 0;
  local_78[0] = 0;
  local_res20[0] = 0;
  puVar3 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_FDO_DATA_TYPE_INFO_1c0006018);
  uVar6 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,param_1);
  *puVar3 = uVar6;
  local_38 = &DEVPKEY_Device_BiosDeviceName;
  local_40 = 0x18;
  puVar9 = (undefined8 *)0x0;
  local_30 = 0;
  local_70 = (undefined8 *)0x0;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0xd90))
                    (WdfDriverGlobals,param_1,&local_40,0x200,0,&local_68,local_78);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,3,0xd,
                        &WPP_1ba2a96020a631842d42c8456aa0d7d0_Traceguids,(char)iVar2);
    }
    pwVar4 = L"Unknown";
  }
  else {
    pwVar4 = (wchar_t *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,local_68,0);
  }
  puVar3[2] = pwVar4;
  local_60 = 0;
  local_58 = (ulonglong)(uint)local_58;
  lVar5 = ExAllocatePool2(0x100,0x120);
  if (lVar5 == 0) {
    iVar2 = -0x3fffff66;
LAB_1c000adfa:
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000af70;
    uVar10 = 0xe;
    bVar7 = 3;
  }
  else {
    _Size = 0;
    local_58 = 1;
    local_48 = 0x120;
    uVar11 = 0;
    local_50 = lVar5;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                      (WdfDriverGlobals,*puVar3,0,0x32c028,0,&local_58,0,&local_60);
    if (-1 < iVar2) {
      _Size = 0x78614d50;
      _Dst = (void *)ExAllocatePool2(0x100,(ulonglong)*(ushort *)(lVar5 + 10) + 1);
      if (_Dst == (void *)0x0) {
        iVar2 = -0x3fffff66;
      }
      else {
        _Size = (ulonglong)*(ushort *)(lVar5 + 10);
        memcpy(_Dst,(void *)((ulonglong)*(ushort *)(lVar5 + 8) + lVar5),_Size);
        puVar3[3] = _Dst;
        iVar2 = 0;
      }
    }
    lVar8 = 0x78614d50;
    ExFreePoolWithTag(lVar5);
    if (iVar2 < 0) goto LAB_1c000adfa;
    uVar6 = MiniportPrepareHarware(param_1,lVar8,_Size);
    iVar2 = (int)uVar6;
    if (iVar2 < 0) goto LAB_1c000af70;
    uVar6 = AcpiQueryPowerPlaneDsmSupport(puVar3,lVar8,_Size);
    if ((char)uVar6 == '\0') {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar8,2,0xf,
                         &WPP_1ba2a96020a631842d42c8456aa0d7d0_Traceguids);
      }
      iVar2 = -0x3fffff45;
      goto LAB_1c000af70;
    }
    iVar2 = AcpiQueryPowerPlaneDefinition(puVar3,(longlong *)&local_70,local_res20);
    puVar9 = local_70;
    iVar1 = local_res20[0];
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,0x10,
                          &WPP_1ba2a96020a631842d42c8456aa0d7d0_Traceguids,(char)iVar2);
      }
      puVar9 = local_70;
      goto LAB_1c000af70;
    }
    *local_70 = 0x39;
    local_70[1] = puVar3;
    local_70[2] = SetPowerLimit;
    if (*(char *)(puVar3 + 7) != '\0') {
LAB_1c000af62:
      puVar3[5] = puVar9;
      iVar2 = 0;
      puVar9 = (undefined8 *)0x0;
      *(int *)(puVar3 + 6) = iVar1;
      goto LAB_1c000af70;
    }
    iVar2 = ZwPowerInformation(0x57,local_70,local_res20[0],0,uVar11 & 0xffffffff00000000);
    if (-1 < iVar2) goto LAB_1c000af62;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000af70;
    uVar10 = 0x11;
    bVar7 = 2;
  }
  WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar7,3,uVar10,
                    &WPP_1ba2a96020a631842d42c8456aa0d7d0_Traceguids,(char)iVar2);
LAB_1c000af70:
  if (puVar9 != (undefined8 *)0x0) {
    ExFreePoolWithTag(puVar9,0x78614d50);
  }
  return iVar2;
}



===== EvtDeviceWdmIrpPreprocessPnp @ 1c000afb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EvtDeviceWdmIrpPreprocessPnp(undefined8 param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  
  local_res18 = 0;
  local_48 = 0;
  local_res20 = 0;
  local_res10 = 0;
  local_40 = 0;
  uStack_38 = 0;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DATA_TYPE_INFO_1c0006018);
  if (*(char *)(lVar2 + 0x38) == '\0') {
    (**(code **)(WdfFunctions_01015 + 0x260))(WdfDriverGlobals,param_1,0);
    if (*(longlong *)(lVar2 + 8) == 0) {
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x290))
                        (WdfDriverGlobals,param_1,0xb,0x200,0,&local_res10);
      if (-1 < iVar1) {
        uStack_38 = (**(code **)(WdfFunctions_01015 + 0x610))
                              (WdfDriverGlobals,local_res10,&local_res18);
        local_40 = CONCAT62(CONCAT42(local_40._4_4_,(short)local_res18),(short)local_res18 + -2);
        iVar1 = IoGetDeviceObjectPointer(&local_40,0x1f01ff,&local_res20,&local_48);
        (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,local_res10);
        if (-1 < iVar1) {
          *(undefined8 *)(lVar2 + 8) = local_res20;
        }
      }
    }
  }
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,param_1,param_2);
  return;
}



===== EvtDriverDeviceAdd @ 1c000b140 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int EvtDriverDeviceAdd(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  longlong lVar2;
  undefined2 uVar3;
  undefined8 local_res10;
  undefined1 local_res18 [8];
  undefined8 local_res20;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined *local_a8;
  undefined4 local_98 [10];
  code *local_70;
  
  local_res20 = 0;
  local_c8 = 0;
  uStack_d0 = 0;
  local_d8 = 0x38;
  uStack_c0 = 0x100000001;
  local_b8 = 0;
  uStack_b0 = 0;
  local_a8 = PTR__WDF_FDO_DATA_TYPE_INFO_1c0006018;
  local_res10 = param_2;
  memset(local_98,0,0x90);
  local_70 = EvtDevicePrepareHardware;
  local_98[0] = 0x90;
  (**(code **)(WdfFunctions_01015 + 0x1b8))(WdfDriverGlobals,param_2,local_98);
  local_res18[0] = 0x14;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x248))
                    (WdfDriverGlobals,local_res10,EvtDeviceWdmIrpPreprocessPnp,0x1b,local_res18,1);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar3 = 10;
  }
  else {
    iVar1 = (**(code **)(WdfFunctions_01015 + 600))
                      (WdfDriverGlobals,&local_res10,&local_d8,&local_res20);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      uVar3 = 0xb;
    }
    else {
      lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,local_res20,PTR__WDF_FDO_DATA_TYPE_INFO_1c0006018);
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals,0,lVar2 + 0x20);
      if (-1 < iVar1) {
        return 0;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      uVar3 = 0xc;
    }
  }
  WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,3,uVar3,
                    &WPP_1ba2a96020a631842d42c8456aa0d7d0_Traceguids,(char)iVar1);
  return iVar1;
}



===== WppInitKm @ 1c000b32c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppInitKm(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined *puVar2;
  
  if (WPP_GLOBAL_Control != &WPP_MAIN_CB) {
    WPP_GLOBAL_Control = &WPP_MAIN_CB;
    if ((int)WPPTraceSuite == 4) {
      puVar2 = &WPP_MAIN_CB;
      do {
        pcVar1 = pfnEtwRegisterClassicProvider;
        *(undefined8 *)(puVar2 + 0x38) = 0;
        (*pcVar1)(*(undefined8 *)(puVar2 + 8),0,WppClassicProviderCallback,puVar2,puVar2 + 0x38);
        puVar2 = *(undefined **)(puVar2 + 0x10);
      } while (puVar2 != (undefined *)0x0);
    }
    else if ((int)WPPTraceSuite == 2) {
      _WPP_MAIN_CB = WppTraceCallback;
      IoWMIRegistrationControl(&WPP_MAIN_CB,0x80010001);
    }
    WppAutoLogStart(WPP_GLOBAL_Control,param_1,param_2);
    WPP_RECORDER_INITIALIZED = &WPP_MAIN_CB;
  }
  return;
}



===== WppLoadTracingSupport @ 1c000b408 =====

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
  WPPTraceSuite._0_4_ = 2;
  if (pfnWppGetVersion != (code *)0x0) {
    (*pfnWppGetVersion)(local_res8,0,0,0);
  }
  if (5 < local_res8[0]) {
    RtlInitUnicodeString(&local_18,L"EtwRegisterClassicProvider");
    pfnEtwRegisterClassicProvider = MmGetSystemRoutineAddress(&local_18);
    if (pfnEtwRegisterClassicProvider != 0) {
      RtlInitUnicodeString(&local_18,L"EtwUnregister");
      MmGetSystemRoutineAddress(&local_18);
      WPPTraceSuite._0_4_ = 4;
    }
  }
  return;
}



===== WppTraceCallback @ 1c000b550 =====

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
          bVar13 = (int)WPPTraceSuite != 2;
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



===== MiniportPrepareHarware @ 1c000b7d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 MiniportPrepareHarware(undefined8 param_1,undefined8 param_2,ulonglong param_3)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined **ppuVar8;
  uint uVar9;
  undefined2 uVar10;
  ulonglong local_res18;
  
  local_res18 = param_3;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_FDO_DATA_TYPE_INFO_1c0006018);
  uVar9 = 0;
  ppuVar8 = &ConfigurationData;
  do {
    iVar1 = _stricmp(*(char **)(lVar3 + 0x18),*ppuVar8);
    if (iVar1 == 0) goto LAB_1c000b888;
    uVar9 = uVar9 + 1;
    ppuVar8 = ppuVar8 + 2;
  } while (uVar9 < 2);
  if (uVar9 == 2) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    return 0xc00000bb;
  }
LAB_1c000b888:
  uVar6 = rdmsr(0x606);
  iVar1 = 1;
  if ((uVar6 & 0xf) != 0) {
    uVar6 = (ulonglong)((uint)uVar6 & 0xf);
    do {
      iVar1 = iVar1 * 2;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  local_res18 = 0;
  uVar7 = 0;
  iVar2 = HalGetBusDataByOffset(4,0,0,&local_res18,0x48,4);
  if (iVar2 == 4) {
    if (local_res18 != 0) {
      if ((local_res18 & 1) == 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0xc0000001;
        }
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0xd,
                          &WPP_6e250f8174553bd178ecbbb9f2cab3da_Traceguids,(char)local_res18);
        return 0xc0000001;
      }
      uVar5 = (uint)local_res18 & 0xfffffff0;
      local_res18 = local_res18 & 0xfffffffffffffff0;
      iVar2 = *(int *)(&DAT_1c0006040 + (ulonglong)uVar9 * 2) + uVar5;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0xe,
                          &WPP_6e250f8174553bd178ecbbb9f2cab3da_Traceguids,(char)iVar2);
      }
      uVar7 = 4;
      lVar4 = MmMapIoSpaceEx(iVar2,4,0x204);
      if (lVar4 != 0) {
        *(longlong *)(lVar3 + 0x40) = lVar4;
        *(int *)(lVar3 + 0x48) = iVar1;
        return 0;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,3,0xf,
                         &WPP_6e250f8174553bd178ecbbb9f2cab3da_Traceguids);
      }
      return 0xc000009a;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc0000001;
    }
    uVar10 = 0xc;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc0000001;
    }
    uVar10 = 0xb;
  }
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,4,uVar10,
                   &WPP_6e250f8174553bd178ecbbb9f2cab3da_Traceguids);
  return 0xc0000001;
}



===== __security_init_cookie @ 1c000c008 =====

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



===== DriverEntry @ 1c000c03c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DriverEntry(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 local_res18 [2];
  undefined8 local_28;
  code *local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_28 = 0x20;
  local_18 = 0;
  uStack_10 = 0;
  local_20 = EvtDriverDeviceAdd;
  local_res18[0] = 0;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))
                    (WdfDriverGlobals,param_1,param_2,0,&local_28,local_res18);
  if (-1 < (int)uVar1) {
    if (ChickenBit == '\0') {
      _WPP_MAIN_CB = 0;
      DAT_1c00063e8 = &WPP_ThisDir_CTLGUID_IntelPmaxDriverTraceGuid;
      DAT_1c00063f0 = 0;
      _DAT_1c0006400 = 0;
      _DAT_1c0006408 = 1;
      _DAT_1c0006420 = 0;
      _DAT_1c0006428 = 0;
      WppLoadTracingSupport();
      _DAT_1c0006400 = 0;
      WppInitKm(param_1,param_2);
      uVar1 = 0;
    }
    else {
      uVar1 = 0xc0000001;
    }
  }
  return uVar1;
}


