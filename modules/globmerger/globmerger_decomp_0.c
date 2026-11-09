
===== _tlgWriteTransfer_EtwWriteTransfer @ 140001008 =====

void _tlgWriteTransfer_EtwWriteTransfer
               (longlong param_1,byte *param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5,undefined8 *param_6)

{
  int local_18;
  uint local_14;
  undefined8 local_10;
  
  local_18 = (uint)*param_2 << 0x18;
  local_14 = (uint)*(ushort *)(param_2 + 1);
  local_10 = *(undefined8 *)(param_2 + 3);
  *param_6 = *(undefined8 *)(param_1 + 8);
  *(uint *)(param_6 + 1) = (uint)**(ushort **)(param_1 + 8);
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(*(undefined8 *)(param_1 + 0x20),&local_18,param_3,param_4,param_5,param_6);
  return;
}



===== Write<_tlgWrapSz<char>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>_> @ 1400010ac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapSz<char>,struct _tlgWrapSz<char>,struct _tlgWrapperByVal<4>,struct
   _tlgWrapperByVal<2>,struct _tlgWrapperByVal<4> >(struct _tlgProvider_t const * __ptr64,void const
   * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,struct _tlgWrapSz<char> const
   & __ptr64,struct _tlgWrapSz<char> const & __ptr64,struct _tlgWrapperByVal<4> const &
   __ptr64,struct _tlgWrapperByVal<2> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapSz<char>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapSz<char> *param_5,_tlgWrapSz<char> *param_6,_tlgWrapperByVal<4> *param_7,
          _tlgWrapperByVal<2> *param_8,_tlgWrapperByVal<4> *param_9)

{
  long lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auStackY_b8 [32];
  undefined8 local_88 [4];
  char *local_68;
  int local_60;
  undefined4 local_5c;
  char *local_58;
  int local_50;
  undefined4 local_4c;
  _tlgWrapperByVal<4> *local_48;
  undefined8 local_40;
  _tlgWrapperByVal<2> *local_38;
  undefined8 local_30;
  _tlgWrapperByVal<4> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_28 = param_9;
  lVar3 = -1;
  local_38 = param_8;
  local_48 = param_7;
  local_20 = 4;
  local_30 = 2;
  local_40 = 4;
  local_58 = *(char **)param_6;
  if (local_58 == (char *)0x0) {
    local_58 = "";
    local_50 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (local_58[lVar2] != '\0');
    local_50 = (int)lVar2 + 1;
  }
  local_4c = 0;
  local_68 = *(char **)param_5;
  if (local_68 == (char *)0x0) {
    local_68 = "";
    local_60 = 1;
  }
  else {
    do {
      lVar3 = lVar3 + 1;
    } while (local_68[lVar3] != '\0');
    local_60 = (int)lVar3 + 1;
  }
  local_5c = 0;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x140017008,param_2,0,0,7,local_88);
  return lVar1;
}



===== `dynamic_initializer_for_'g_SourceCims'' @ 1400011b0 =====

void _dynamic_initializer_for__g_SourceCims__(void)

{
  atexit(_dynamic_atexit_destructor_for__g_SourceCims__);
  return;
}



===== __report_gsfailure @ 1400011e0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== RtlRaiseStatus @ 1400011ed =====

void RtlRaiseStatus(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400011ed. Too many branches */
                    /* WARNING: Subroutine does not return */
                    /* WARNING: Treating indirect jump as call */
  RtlRaiseStatus();
  return;
}



===== DbgPrintEx @ 1400011ff =====

void DbgPrintEx(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400011ff. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DbgPrintEx();
  return;
}



===== _purecall @ 140001220 =====

void _purecall(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001220. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _purecall();
  return;
}



===== ExFreePoolWithTag @ 140001232 =====

void ExFreePoolWithTag(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001232. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ExFreePoolWithTag();
  return;
}



===== __C_specific_handler @ 140001244 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140001244. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== __cpu_features_init @ 140001260 =====

/* WARNING: Removing unreachable block (ram,0x0001400012ca) */
/* WARNING: Removing unreachable block (ram,0x000140001279) */
/* WARNING: Removing unreachable block (ram,0x00014000126a) */

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



===== Multiply<BUCL::Rtl::CCallDisposition,unsigned___int64> @ 140001328 =====

/* auto __cdecl BUCL::Implementation::Multiply<class BUCL::Rtl::CCallDisposition,unsigned
   __int64>(unsigned __int64,unsigned __int64,unsigned __int64 & __ptr64) */

__uint64 __cdecl
BUCL::Implementation::Multiply<BUCL::Rtl::CCallDisposition,unsigned___int64>
          (__uint64 param_1,__uint64 param_2,__uint64 *param_3)

{
  byte bVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong *in_R9;
  ulonglong uVar6;
  int iVar7;
  
  bVar1 = 0;
  uVar2 = 0;
  iVar7 = (int)((ulonglong)param_3 >> 0x20);
  if ((int)(param_2 >> 0x20) == 0) {
    if (iVar7 == 0) {
      uVar4 = (param_2 & 0xffffffff) * ((ulonglong)param_3 & 0xffffffff);
      goto LAB_1400013c4;
    }
LAB_140001367:
    uVar4 = (param_2 >> 0x20) * ((ulonglong)param_3 & 0xffffffff);
    if ((uVar4 & 0xffffffff00000000) == 0) {
      uVar5 = ((ulonglong)param_3 >> 0x20) * (param_2 & 0xffffffff);
      if ((uVar5 & 0xffffffff00000000) == 0) {
        uVar6 = (param_2 & 0xffffffff) * ((ulonglong)param_3 & 0xffffffff);
        uVar5 = uVar5 << 0x20;
        uVar3 = (uVar4 << 0x20) + uVar5;
        uVar4 = uVar3 + uVar6;
        if ((uVar5 <= uVar3) && (uVar6 <= uVar4)) {
          bVar1 = 1;
        }
        uVar2 = ~-(uint)bVar1 & 0xc0000095;
        goto LAB_1400013c4;
      }
    }
  }
  else if (iVar7 == 0) goto LAB_140001367;
  uVar2 = 0xc0000095;
  uVar4 = 0xffffffffffffffff;
LAB_1400013c4:
  *(uint *)param_1 = uVar2;
  *in_R9 = uVar4;
  return param_1;
}



===== default_terminate_handler @ 1400013f0 =====

/* void __cdecl gsl::details::default_terminate_handler(void) */

void __cdecl gsl::details::default_terminate_handler(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(0);
  return;
}



===== terminate @ 1400013fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl gsl::details::terminate(void) */

void __cdecl gsl::details::terminate(void)

{
  (*(code *)`void_(__cdecl*&___ptr64___cdecl_gsl::details::get_terminate_handler(void))(void)'::__l2
            ::handler)();
  return;
}



===== <lambda_invoker_cdecl> @ 140001420 =====

/* private: static __cdecl <lambda_0c21ff7660cb5f8a927fe0a25528ee7d>::<lambda_invoker_cdecl>(struct
   Windows::Rtl::IRtlFormattedOutputStream * __ptr64,void const * __ptr64) */

void __cdecl
<lambda_0c21ff7660cb5f8a927fe0a25528ee7d>::<lambda_invoker_cdecl>
          (IRtlFormattedOutputStream *param_1,void *param_2)

{
  return;
}



===== AppendString<_LUNICODE_STRING,Windows::AutoOperatorAmpersandHelper<_LUNICODE_STRING,Windows::Auto<_LUNICODE_STRING>_>,0> @ 14000142c =====

/* long __cdecl Windows::StringUtil::Rtl::AppendString<struct _LUNICODE_STRING,class
   Windows::AutoOperatorAmpersandHelper<struct _LUNICODE_STRING,class Windows::Auto<struct
   _LUNICODE_STRING> >,0>(struct _LUNICODE_STRING const & __ptr64,class
   Windows::AutoOperatorAmpersandHelper<struct _LUNICODE_STRING,class Windows::Auto<struct
   _LUNICODE_STRING> >) */

long __cdecl
Windows::StringUtil::Rtl::
AppendString<_LUNICODE_STRING,Windows::AutoOperatorAmpersandHelper<_LUNICODE_STRING,Windows::Auto<_LUNICODE_STRING>_>,0>
          (ulonglong *param_1,undefined8 *param_2)

{
  void *_Src;
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong _Size;
  int iVar3;
  
  puVar1 = (ulonglong *)*param_2;
  _Size = *param_1;
  _Src = (void *)param_1[2];
  uVar2 = *puVar1;
  if (puVar1[1] - uVar2 < _Size) {
    if (uVar2 + _Size < uVar2) {
      return -0x3fffff6b;
    }
    iVar3 = RtlReallocateLUnicodeString(uVar2,uVar2 + _Size,puVar1);
    if (iVar3 < 0) {
      return iVar3;
    }
  }
  if (_Size != 0) {
    puVar1 = (ulonglong *)*param_2;
    if (puVar1[1] - *puVar1 < _Size) {
                    /* WARNING: Subroutine does not return */
      RtlRaiseStatus(0xc00000e5);
    }
    memmove((void *)(puVar1[2] + (*puVar1 & 0xfffffffffffffffe)),_Src,_Size);
    *puVar1 = *puVar1 + _Size;
  }
  return 0;
}



===== CompareStringsByOrdinalCaseInvariant<_LUNICODE_STRING,_LUNICODE_STRING> @ 1400014d4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl Windows::StringUtil::Rtl::CompareStringsByOrdinalCaseInvariant<struct
   _LUNICODE_STRING,struct _LUNICODE_STRING>(struct _LUNICODE_STRING const & __ptr64,struct
   _LUNICODE_STRING const & __ptr64,int * __ptr64) */

long __cdecl
Windows::StringUtil::Rtl::CompareStringsByOrdinalCaseInvariant<_LUNICODE_STRING,_LUNICODE_STRING>
          (_LUNICODE_STRING *param_1,_LUNICODE_STRING *param_2,int *param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  ushort uVar4;
  ushort uVar5;
  undefined1 auStack_98 [32];
  longlong local_78;
  longlong lStack_70;
  ushort *local_68;
  longlong local_60;
  longlong lStack_58;
  ushort *local_50;
  longlong local_48;
  longlong lStack_40;
  ushort *local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_98;
  local_60 = *(longlong *)param_1;
  lStack_58 = *(longlong *)(param_1 + 8);
  local_50 = *(ushort **)(param_1 + 0x10);
  local_48 = *(longlong *)param_2;
  lStack_40 = *(longlong *)(param_2 + 8);
  local_38 = *(ushort **)(param_2 + 0x10);
  do {
    if (local_60 == 0) {
LAB_14000161e:
      iVar2 = -(uint)(local_48 != 0);
LAB_140001623:
      *param_3 = iVar2;
      return 0;
    }
    if (local_48 == 0) {
      if (local_60 != 0) {
        *param_3 = 1;
        return 0;
      }
      goto LAB_14000161e;
    }
    uVar1 = *local_50;
    uVar4 = *local_38;
    if (0x7f < uVar1) {
      local_78 = local_60;
      lStack_70 = lStack_58;
      *param_3 = 0;
      local_68 = local_50;
      local_60 = local_48;
      lStack_58 = lStack_40;
      local_50 = local_38;
      iVar3 = RtlCompareLUnicodeStrings(&local_78,&local_60,param_3,param_3);
      iVar2 = 0;
      if (iVar3 < 0) {
        iVar2 = iVar3;
      }
      return iVar2;
    }
    uVar5 = uVar1 + 0x20;
    if (0x19 < (ushort)(uVar1 - 0x41)) {
      uVar5 = uVar1;
    }
    if ((ushort)(uVar4 - 0x41) < 0x1a) {
      uVar4 = uVar4 + 0x20;
    }
    if (uVar5 != uVar4) {
      iVar2 = (-(uint)(uVar5 < uVar4) & 0xfffffffe) + 1;
      goto LAB_140001623;
    }
    if (local_60 == 0) {
LAB_1400015b5:
                    /* WARNING: Subroutine does not return */
      RtlRaiseStatus(0xc00000e5);
    }
    local_50 = local_50 + 1;
    local_60 = local_60 + -2;
    lStack_58 = lStack_58 + -2;
    if (local_48 == 0) goto LAB_1400015b5;
    local_38 = local_38 + 1;
    local_48 = local_48 + -2;
    lStack_40 = lStack_40 + -2;
  } while( true );
}



===== QuickSort<BUCL::Rtl::CCallDisposition,unsigned___int64,Windows::Auto<_LUNICODE_STRING>,struct_BUCL::Implementation::ComparisonResultKind<BUCL::Rtl::CCallDisposition>_(__cdecl*)(_LUNICODE_STRING_const&___ptr64,_LUNICODE_STRING_const&___ptr64)> @ 140001650 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* class BUCL::Rtl::CCallDisposition __cdecl BUCL::Implementation::QuickSort<class
   BUCL::Rtl::CCallDisposition,unsigned __int64,class Windows::Auto<struct _LUNICODE_STRING>,struct
   BUCL::Implementation::ComparisonResultKind<class BUCL::Rtl::CCallDisposition> (__cdecl*)(struct
   _LUNICODE_STRING const & __ptr64,struct _LUNICODE_STRING const & __ptr64)>(class
   Windows::Auto<struct _LUNICODE_STRING> * __ptr64,unsigned __int64,struct
   BUCL::Implementation::ComparisonResultKind<class BUCL::Rtl::CCallDisposition> (__cdecl*)(struct
   _LUNICODE_STRING const & __ptr64,struct _LUNICODE_STRING const & __ptr64)) */

Auto<_LUNICODE_STRING> * __cdecl
BUCL::Implementation::
QuickSort<BUCL::Rtl::CCallDisposition,unsigned___int64,Windows::Auto<_LUNICODE_STRING>,struct_BUCL::Implementation::ComparisonResultKind<BUCL::Rtl::CCallDisposition>_(__cdecl*)(_LUNICODE_STRING_const&___ptr64,_LUNICODE_STRING_const&___ptr64)>
          (Auto<_LUNICODE_STRING> *param_1,__uint64 param_2,
          _func_ComparisonResultKind<BUCL::Rtl::CCallDisposition>__LUNICODE_STRING_ptr__LUNICODE_STRING_ptr
          *param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  _LUNICODE_STRING *p_Var7;
  _LUNICODE_STRING *p_Var8;
  longlong lVar9;
  longlong lVar10;
  _LUNICODE_STRING *p_Var11;
  _LUNICODE_STRING *p_Var12;
  _LUNICODE_STRING *p_Var13;
  undefined1 auStack_468 [32];
  undefined8 local_448;
  _LUNICODE_STRING *local_440;
  _LUNICODE_STRING *local_438;
  undefined8 local_428 [62];
  undefined8 local_238 [62];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_468;
  if (param_3 < (_func_ComparisonResultKind<BUCL::Rtl::CCallDisposition>__LUNICODE_STRING_ptr__LUNICODE_STRING_ptr
                 *)0x2) {
LAB_140001a07:
    *(undefined4 *)param_1 = 0;
    return param_1;
  }
  memset(local_428,0,0x1f0);
  memset(local_238,0,0x1f0);
  p_Var8 = (_LUNICODE_STRING *)(param_2 + (longlong)(param_3 + -1) * 0x18);
  lVar10 = 0;
LAB_1400016c8:
  uVar5 = ((longlong)((longlong)p_Var8 - param_2) >> 3) * -0x5555555555555555 + 1;
  if (8 < uVar5) {
    p_Var7 = (_LUNICODE_STRING *)(param_2 + (uVar5 >> 1) * 0x18);
    local_448 = KeyContext::Compare((_LUNICODE_STRING *)param_2,p_Var7);
    if ((char)local_448 != '\0') {
      if ('\0' < (char)((ulonglong)local_448 >> 8)) {
        uVar2 = *(undefined8 *)(param_2 + 8);
        uVar3 = *(undefined8 *)p_Var7;
        uVar1 = *(undefined8 *)(p_Var7 + 8);
        uVar6 = *(undefined8 *)(p_Var7 + 0x10);
        *(undefined8 *)p_Var7 = *(undefined8 *)param_2;
        *(undefined8 *)(p_Var7 + 8) = uVar2;
        *(undefined8 *)(p_Var7 + 0x10) = *(undefined8 *)(param_2 + 0x10);
        *(undefined8 *)param_2 = uVar3;
        *(undefined8 *)(param_2 + 8) = uVar1;
        *(undefined8 *)(param_2 + 0x10) = uVar6;
      }
      local_448 = KeyContext::Compare((_LUNICODE_STRING *)param_2,p_Var8);
      if ((char)local_448 != '\0') {
        if ('\0' < (char)((ulonglong)local_448 >> 8)) {
          uVar2 = *(undefined8 *)(param_2 + 8);
          uVar3 = *(undefined8 *)p_Var8;
          uVar1 = *(undefined8 *)(p_Var8 + 8);
          uVar6 = *(undefined8 *)(p_Var8 + 0x10);
          *(undefined8 *)p_Var8 = *(undefined8 *)param_2;
          *(undefined8 *)(p_Var8 + 8) = uVar2;
          *(undefined8 *)(p_Var8 + 0x10) = *(undefined8 *)(param_2 + 0x10);
          *(undefined8 *)param_2 = uVar3;
          *(undefined8 *)(param_2 + 8) = uVar1;
          *(undefined8 *)(param_2 + 0x10) = uVar6;
        }
        local_448 = KeyContext::Compare(p_Var7,p_Var8);
        if ((char)local_448 != '\0') {
          if ('\0' < (char)((ulonglong)local_448 >> 8)) {
            uVar2 = *(undefined8 *)(p_Var7 + 8);
            uVar3 = *(undefined8 *)p_Var8;
            uVar1 = *(undefined8 *)(p_Var8 + 8);
            uVar6 = *(undefined8 *)(p_Var8 + 0x10);
            *(undefined8 *)p_Var8 = *(undefined8 *)p_Var7;
            *(undefined8 *)(p_Var8 + 8) = uVar2;
            *(undefined8 *)(p_Var8 + 0x10) = *(undefined8 *)(p_Var7 + 0x10);
            *(undefined8 *)p_Var7 = uVar3;
            *(undefined8 *)(p_Var7 + 8) = uVar1;
            *(undefined8 *)(p_Var7 + 0x10) = uVar6;
          }
          p_Var11 = p_Var8;
          p_Var12 = (_LUNICODE_STRING *)param_2;
          do {
            local_440 = p_Var7;
            local_438 = p_Var7;
            if (p_Var12 < p_Var7) {
              do {
                p_Var12 = p_Var12 + 0x18;
                local_448 = KeyContext::Compare(p_Var12,p_Var7);
                if ((char)local_448 == '\0') goto LAB_1400019f9;
                if (p_Var7 <= p_Var12) goto LAB_140001897;
              } while ((char)((ulonglong)local_448 >> 8) < '\x01');
            }
            else {
LAB_140001897:
              do {
                p_Var12 = p_Var12 + 0x18;
                local_448 = KeyContext::Compare(p_Var12,p_Var7);
                if ((char)local_448 == '\0') goto LAB_1400019f9;
              } while ((p_Var12 < p_Var8) && ((char)((ulonglong)local_448 >> 8) < '\x01'));
            }
            do {
              p_Var13 = p_Var11;
              p_Var11 = p_Var13 + -0x18;
              local_448 = KeyContext::Compare(p_Var11,p_Var7);
              if ((char)local_448 == '\0') goto LAB_1400019f9;
            } while ((p_Var7 < p_Var11) && ('\0' < (char)((ulonglong)local_448 >> 8)));
            if (p_Var11 < p_Var12) goto LAB_14000192e;
            uVar6 = *(undefined8 *)(p_Var12 + 8);
            uVar2 = *(undefined8 *)p_Var11;
            uVar3 = *(undefined8 *)(p_Var13 + -0x10);
            p_Var7 = p_Var12;
            if (local_440 != p_Var11) {
              p_Var7 = local_438;
            }
            uVar1 = *(undefined8 *)(p_Var13 + -8);
            *(undefined8 *)p_Var11 = *(undefined8 *)p_Var12;
            *(undefined8 *)(p_Var13 + -0x10) = uVar6;
            *(undefined8 *)(p_Var13 + -8) = *(undefined8 *)(p_Var12 + 0x10);
            *(undefined8 *)p_Var12 = uVar2;
            *(undefined8 *)(p_Var12 + 8) = uVar3;
            *(undefined8 *)(p_Var12 + 0x10) = uVar1;
          } while( true );
        }
      }
    }
LAB_1400019f9:
    uVar4 = local_448._4_4_;
LAB_1400019fd:
    *(undefined4 *)param_1 = uVar4;
    return param_1;
  }
  for (; p_Var11 = (_LUNICODE_STRING *)param_2, p_Var7 = (_LUNICODE_STRING *)param_2,
      param_2 < p_Var8; p_Var8 = p_Var8 + -0x18) {
    while (p_Var12 = p_Var11, p_Var7 = p_Var7 + 0x18, p_Var7 <= p_Var8) {
      uVar5 = KeyContext::Compare(p_Var7,p_Var12);
      if ((char)uVar5 == '\0') {
        uVar5 = uVar5 >> 0x20;
        goto LAB_14000174a;
      }
      p_Var11 = p_Var7;
      if ((char)(uVar5 >> 8) < '\0') {
        p_Var11 = p_Var12;
      }
    }
    uVar2 = *(undefined8 *)p_Var8;
    uVar3 = *(undefined8 *)(p_Var8 + 8);
    uVar6 = *(undefined8 *)(p_Var8 + 0x10);
    uVar1 = *(undefined8 *)(p_Var12 + 8);
    *(undefined8 *)p_Var8 = *(undefined8 *)p_Var12;
    *(undefined8 *)(p_Var8 + 8) = uVar1;
    *(undefined8 *)(p_Var8 + 0x10) = *(undefined8 *)(p_Var12 + 0x10);
    *(undefined8 *)p_Var12 = uVar2;
    *(undefined8 *)(p_Var12 + 8) = uVar3;
    *(undefined8 *)(p_Var12 + 0x10) = uVar6;
  }
  uVar5 = 0;
LAB_14000174a:
  uVar4 = (int)uVar5;
  if (uVar5 >> 0x1f != 0) goto LAB_1400019fd;
  goto LAB_140001761;
LAB_14000192e:
  if (p_Var7 < p_Var13) {
    do {
      p_Var13 = p_Var13 + -0x18;
      local_448 = KeyContext::Compare(p_Var13,p_Var7);
      if ((char)local_448 == '\0') goto LAB_1400019f9;
      if (p_Var13 <= p_Var7) goto LAB_14000195e;
    } while ((char)((ulonglong)local_448 >> 8) == '\0');
  }
  else {
LAB_14000195e:
    do {
      p_Var13 = p_Var13 + -0x18;
      uVar6 = KeyContext::Compare(p_Var13,p_Var7);
      if ((char)uVar6 == '\0') {
        uVar4 = (int)((ulonglong)uVar6 >> 0x20);
        goto LAB_1400019fd;
      }
    } while ((param_2 < p_Var13) && ((char)((ulonglong)uVar6 >> 8) == '\0'));
  }
  if (((longlong)((longlong)p_Var13 - param_2) >> 3) * -0x5555555555555555 <
      ((longlong)p_Var8 - (longlong)p_Var12 >> 3) * -0x5555555555555555) {
    if (p_Var12 < p_Var8) {
      local_428[lVar10] = p_Var12;
      local_238[lVar10] = p_Var8;
      lVar10 = lVar10 + 1;
    }
    if (param_2 < p_Var13) {
      p_Var8 = p_Var13;
      goto LAB_1400016c8;
    }
  }
  else {
    if (param_2 < p_Var13) {
      local_428[lVar10] = param_2;
      local_238[lVar10] = p_Var13;
      lVar10 = lVar10 + 1;
    }
    if (p_Var12 < p_Var8) {
      param_2 = (__uint64)p_Var12;
      goto LAB_1400016c8;
    }
  }
LAB_140001761:
  lVar9 = lVar10 + -1;
  if (lVar10 != 0) {
    param_2 = (__uint64)local_428[lVar9];
    p_Var8 = (_LUNICODE_STRING *)local_238[lVar9];
    lVar10 = lVar9;
    goto LAB_1400016c8;
  }
  goto LAB_140001a07;
}



===== KeyContext @ 140001a40 =====

/* public: __cdecl KeyContext::KeyContext(struct KeyContext && __ptr64) __ptr64 */

KeyContext * __thiscall KeyContext::KeyContext(KeyContext *this,KeyContext *param_1)

{
  CVector<Windows::Auto<_LUNICODE_STRING>,BUCL::Rtl::CCallDisposition> *this_00;
  undefined8 uVar1;
  
  *(undefined8 *)this = 0;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  BUCL::CVector<Windows::Auto<_LUNICODE_STRING>,BUCL::Rtl::CCallDisposition>::Close
            ((CVector<Windows::Auto<_LUNICODE_STRING>,BUCL::Rtl::CCallDisposition> *)this);
  this_00 = (CVector<Windows::Auto<_LUNICODE_STRING>,BUCL::Rtl::CCallDisposition> *)(this + 0x18);
  uVar1 = *(undefined8 *)param_1;
  *(undefined8 *)param_1 = *(undefined8 *)this;
  *(undefined8 *)this = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(this + 8);
  *(undefined8 *)(this + 8) = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(this + 0x10);
  *(undefined8 *)(this + 0x10) = uVar1;
  *(undefined8 *)this_00 = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  BUCL::CVector<Windows::Auto<_LUNICODE_STRING>,BUCL::Rtl::CCallDisposition>::Close(this_00);
  uVar1 = *(undefined8 *)(param_1 + 0x18);
  *(undefined8 *)(param_1 + 0x18) = *(undefined8 *)this_00;
  *(undefined8 *)this_00 = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x20);
  *(undefined8 *)(param_1 + 0x20) = *(undefined8 *)(this + 0x20);
  *(undefined8 *)(this + 0x20) = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x28);
  *(undefined8 *)(param_1 + 0x28) = *(undefined8 *)(this + 0x28);
  *(undefined8 *)(this + 0x28) = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x38);
  *(undefined8 *)(this + 0x30) = *(undefined8 *)(param_1 + 0x30);
  *(undefined8 *)(this + 0x38) = uVar1;
  *(undefined8 *)(this + 0x40) = *(undefined8 *)(param_1 + 0x40);
  *(undefined8 *)(param_1 + 0x30) = 0;
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(undefined8 *)(param_1 + 0x40) = 0;
  *(undefined8 *)(this + 0x50) = 0;
  *(undefined8 *)(this + 0x58) = 0;
  this[0x48] = (KeyContext)0x0;
  uVar1 = *(undefined8 *)(param_1 + 0x50);
  *(undefined8 *)(param_1 + 0x50) = 0;
  *(undefined8 *)(this + 0x50) = uVar1;
  *(undefined8 *)(this + 0x58) = *(undefined8 *)(param_1 + 0x58);
  *(undefined8 *)(param_1 + 0x58) = 0;
  uVar1 = *(undefined8 *)(param_1 + 0x60);
  *(undefined8 *)(param_1 + 0x60) = 0;
  *(undefined8 *)(this + 0x60) = uVar1;
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  *(undefined4 *)(this + 0x70) = *(undefined4 *)(param_1 + 0x70);
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  *(undefined4 *)(this + 0x78) = *(undefined4 *)(param_1 + 0x78);
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  return this;
}



===== ~KeyContext @ 140001b88 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: __cdecl KeyContext::~KeyContext(void) __ptr64 */

void __thiscall KeyContext::~KeyContext(KeyContext *this)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(this + 0x60);
  if (puVar1 != (undefined8 *)0x0) {
    *(undefined8 *)(this + 0x60) = 0;
    (**(code **)*puVar1)();
  }
  Windows::Rtl::SystemImplementation::CSilHandle::Close((CSilHandle *)(this + 0x48));
  puVar1 = *(undefined8 **)(this + 0x50);
  if (puVar1 != (undefined8 *)0x0) {
    *(undefined8 *)(this + 0x50) = 0;
    (**(code **)*puVar1)();
  }
  if (*(longlong *)(this + 0x40) != 0) {
    RtlFreeLUnicodeString((longlong)(this + 0x30));
    *(undefined8 *)(this + 0x30) = 0;
    *(undefined8 *)(this + 0x38) = 0;
    *(undefined8 *)(this + 0x40) = 0;
  }
  BUCL::CVector<Windows::Auto<_LUNICODE_STRING>,BUCL::Rtl::CCallDisposition>::Close
            ((CVector<Windows::Auto<_LUNICODE_STRING>,BUCL::Rtl::CCallDisposition> *)(this + 0x18));
  BUCL::CVector<Windows::Auto<_LUNICODE_STRING>,BUCL::Rtl::CCallDisposition>::Close
            ((CVector<Windows::Auto<_LUNICODE_STRING>,BUCL::Rtl::CCallDisposition> *)this);
  return;
}



===== Assign @ 140001c1c =====

/* public: long __cdecl Windows::Rtl::AutoString<struct _LUNICODE_STRING,class Windows::Auto<struct
   _LUNICODE_STRING> >::Assign(struct _LUNICODE_STRING const & __ptr64) __ptr64 */

long __thiscall
Windows::Rtl::AutoString<_LUNICODE_STRING,Windows::Auto<_LUNICODE_STRING>_>::Assign
          (AutoString<_LUNICODE_STRING,Windows::Auto<_LUNICODE_STRING>_> *this,
          _LUNICODE_STRING *param_1)

{
  __uint64 _Var1;
  int iVar2;
  undefined8 uVar3;
  __uint64 local_38;
  undefined8 uStack_30;
  longlong local_28;
  longlong local_10;
  
  local_28 = 0;
  local_38 = 0;
  uStack_30 = 0;
  uVar3 = RtlDuplicateLUnicodeString((ulonglong *)param_1,&local_38);
  iVar2 = (int)uVar3;
  if (iVar2 < 0) {
    if (local_28 != 0) {
      RtlFreeLUnicodeString((longlong)&local_38);
    }
  }
  else {
    local_10 = *(longlong *)(this + 0x10);
    _Var1 = *(__uint64 *)this;
    uVar3 = *(undefined8 *)(this + 8);
    *(__uint64 *)this = local_38;
    *(undefined8 *)(this + 8) = uStack_30;
    *(longlong *)(this + 0x10) = local_28;
    if (local_10 != 0) {
      local_38 = _Var1;
      uStack_30 = uVar3;
      local_28 = local_10;
      RtlFreeLUnicodeString((longlong)&local_38);
    }
    iVar2 = 0;
  }
  return iVar2;
}



===== Close @ 140001cb8 =====

/* public: void __cdecl BUCL::CVector<class Windows::Auto<struct _LUNICODE_STRING>,class
   BUCL::Rtl::CCallDisposition>::Close(void) __ptr64 */

void __thiscall
BUCL::CVector<Windows::Auto<_LUNICODE_STRING>,BUCL::Rtl::CCallDisposition>::Close
          (CVector<Windows::Auto<_LUNICODE_STRING>,BUCL::Rtl::CCallDisposition> *this)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(this + 8);
  lVar2 = *(longlong *)this;
  while (lVar2 != lVar1) {
    if (*(longlong *)(lVar1 + -8) != 0) {
      RtlFreeLUnicodeString(lVar1 + -0x18);
      *(undefined8 *)(lVar1 + -0x18) = 0;
      *(undefined8 *)(lVar1 + -0x10) = 0;
      *(undefined8 *)(lVar1 + -8) = 0;
    }
    lVar1 = *(longlong *)(this + 8) + -0x18;
    *(longlong *)(this + 8) = lVar1;
    lVar2 = *(longlong *)this;
  }
  if (lVar2 != 0) {
    ExFreePoolWithTag(lVar2,0);
  }
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)this = 0;
  return;
}



===== Close @ 140001d40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: void __cdecl Windows::Rtl::SystemImplementation::CSilHandle::Close(void) __ptr64 */

void __thiscall Windows::Rtl::SystemImplementation::CSilHandle::Close(CSilHandle *this)

{
  undefined8 *puVar1;
  long lVar2;
  undefined1 auStack_68 [32];
  char *local_48;
  code *local_40;
  int **local_38;
  int local_28 [2];
  int *local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  if (*(longlong *)(this + 0x10) != 0) {
    local_28[0] = (**(code **)(**(longlong **)(this + 8) + 0x30))();
    if (*this == (CSilHandle)0x0) {
      if (local_28[0] < 0) {
        local_20 = (int *)CONCAT44(local_20._4_4_,local_28[0]);
        if (local_28[0] < 0) {
          lVar2 = ErrorHandling::Rtl::
                  CBaseNtStatusCarryingFrame<Windows::ErrorHandling::Rtl::CVoidRaiseFrame,void>::
                  GetNtStatus((CBaseNtStatusCarryingFrame<Windows::ErrorHandling::Rtl::CVoidRaiseFrame,void>
                               *)&local_20);
                    /* WARNING: Subroutine does not return */
          RtlRaiseStatus(lVar2);
        }
        return;
      }
    }
    else if (local_28[0] < 0) {
      local_20 = local_28;
      local_38 = &local_20;
      local_40 = <lambda_0c21ff7660cb5f8a927fe0a25528ee7d>::<lambda_invoker_cdecl>;
      local_48 = "0";
      WCP::Rtl::RtlTrace(2,&WCP::Rtl::Facility_SIL,"CSilHandle.Close() failed with {0}\n",1);
    }
    else {
      WCP::Rtl::RtlTrace(0,&WCP::Rtl::Facility_SIL,"CSilHandle.Close() succeeded\n",0);
    }
    *(undefined8 *)(this + 0x10) = 0;
    puVar1 = *(undefined8 **)(this + 8);
    if (puVar1 != (undefined8 *)0x0) {
      *(undefined8 *)(this + 8) = 0;
      (**(code **)*puVar1)();
    }
  }
  return;
}



===== Compare @ 140001e44 =====

/* public: static struct BUCL::Implementation::ComparisonResultKind<class
   BUCL::Rtl::CCallDisposition> __cdecl KeyContext::Compare(struct _LUNICODE_STRING const &
   __ptr64,struct _LUNICODE_STRING const & __ptr64) */

ulonglong __cdecl KeyContext::Compare(_LUNICODE_STRING *param_1,_LUNICODE_STRING *param_2)

{
  undefined1 uVar1;
  uint uVar2;
  int local_res18 [2];
  undefined8 local_res20;
  
  local_res18[0] = 0;
  uVar2 = Windows::StringUtil::Rtl::
          CompareStringsByOrdinalCaseInvariant<_LUNICODE_STRING,_LUNICODE_STRING>
                    (param_1,param_2,local_res18);
  if ((int)uVar2 < 0) {
    local_res20 = (ulonglong)uVar2 << 0x20;
  }
  else if (local_res18[0] == 0) {
    local_res20 = 1;
  }
  else {
    uVar1 = 1;
    if (local_res18[0] < 0) {
      uVar1 = 0xff;
    }
    local_res20 = (ulonglong)CONCAT11(uVar1,1);
  }
  return local_res20;
}



===== Create @ 140001ea0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl KeyContext::Create(bool,class
   Windows::Rtl::SystemImplementation::IRtlRegistryProvider * __ptr64,struct _LUNICODE_STRING const
   & __ptr64,struct KeyContext * __ptr64) */

long __cdecl
KeyContext::Create(bool param_1,IRtlRegistryProvider *param_2,_LUNICODE_STRING *param_3,
                  KeyContext *param_4)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined1 auStack_d8 [32];
  undefined8 *local_b8;
  undefined4 local_b0;
  undefined8 local_a8;
  int *local_a0;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  int local_58 [2];
  undefined8 *local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  longlong local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_d8;
  local_30 = 0;
  uStack_28 = 0;
  uVar2 = RtlInitUnicodeStringFromLUnicodeString((ulonglong *)param_3,(undefined4 *)&local_30);
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  local_80 = 0;
  local_78 = &local_30;
  local_58[0] = 0;
  local_a0 = local_58;
  local_a8 = 0;
  local_b8 = &local_88;
  local_b0 = 0;
  local_88 = 0x30;
  local_70 = 0x40;
  local_68 = 0;
  uStack_60 = 0;
  iVar4 = (**(code **)(*(longlong *)param_2 + 0x60))
                    (param_2,(ulonglong)param_1 << 2,param_4 + 0x48,0x20019);
  if (iVar4 < 0) {
    return iVar4;
  }
  if (local_58[0] == 1) {
    if (*(longlong *)(param_4 + 0x60) != 0) {
      pcVar1 = (code *)swi(3);
      lVar3 = (*pcVar1)();
      return lVar3;
    }
    local_50 = (undefined8 *)0x0;
    iVar4 = (**(code **)(*(longlong *)param_2 + 8))
                      (param_2,&_GUID_c9056cc7_3aa0_492e_ae49_f64b5fbb857f,&local_50);
    if (iVar4 < 0) {
      puVar5 = local_50;
    }
    else {
      if (local_50 == (undefined8 *)0x0) {
        iVar4 = -0x3ffffd47;
        goto LAB_140002070;
      }
      puVar5 = *(undefined8 **)(param_4 + 0x60);
      *(undefined8 **)(param_4 + 0x60) = local_50;
    }
    if (puVar5 != (undefined8 *)0x0) {
      local_50 = (undefined8 *)0x0;
      (**(code **)*puVar5)(puVar5);
    }
    if (iVar4 < 0) goto LAB_140002070;
    local_38 = 0;
    local_48 = 0;
    uStack_40 = 0;
    iVar4 = (**(code **)(*(longlong *)param_2 + 0x70))
                      (param_2,*(undefined8 *)(param_4 + 0x58),2,&local_48);
    if (-1 < iVar4) {
      *(undefined4 *)(param_4 + 0x68) = *(undefined4 *)(local_38 + 0x14);
      *(undefined4 *)(param_4 + 0x70) = *(undefined4 *)(local_38 + 0x18);
      *(undefined4 *)(param_4 + 0x6c) = *(undefined4 *)(local_38 + 0x20);
      *(undefined4 *)(param_4 + 0x74) = *(undefined4 *)(local_38 + 0x24);
      *(undefined4 *)(param_4 + 0x78) = *(undefined4 *)(local_38 + 0x28);
      iVar4 = GetAllSubKeys(param_4);
      if (-1 < iVar4) {
        lVar3 = GetAllValues(param_4);
        if (lVar3 < 0) {
          if (local_38 != 0) {
            RtlFreeLUnicodeString((longlong)&local_48);
          }
          return lVar3;
        }
        if (local_38 != 0) {
          RtlFreeLUnicodeString((longlong)&local_48);
        }
        goto LAB_14000206e;
      }
    }
    if (local_38 != 0) {
      RtlFreeLUnicodeString((longlong)&local_48);
    }
  }
  else {
LAB_14000206e:
    iVar4 = 0;
  }
LAB_140002070:
  return iVar4;
}



===== GetAllSubKeys @ 140002098 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl KeyContext::GetAllSubKeys(void) __ptr64 */

long __thiscall KeyContext::GetAllSubKeys(KeyContext *this)

{
  int iVar1;
  int *piVar2;
  long lVar3;
  uint uVar4;
  undefined1 auStack_d8 [32];
  undefined4 local_b8;
  ulonglong *local_b0;
  undefined8 *local_a8;
  undefined8 local_a0;
  int local_88 [2];
  ulonglong local_80;
  ulonglong local_78;
  longlong local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  ulonglong local_50 [3];
  undefined8 local_38;
  undefined8 uStack_30;
  longlong local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_d8;
  uVar4 = 0;
  if (*(int *)(this + 0x68) != 0) {
    do {
      local_50[2] = 0;
      local_a0 = 0;
      local_50[0] = 0;
      local_50[1] = 0;
      local_58 = 0;
      local_a8 = &local_68;
      local_b0 = local_50;
      local_68 = 0;
      uStack_60 = 0;
      local_b8 = 0;
      iVar1 = (**(code **)(**(longlong **)(this + 0x60) + 0xb8))
                        (*(longlong **)(this + 0x60),0,*(undefined8 *)(this + 0x58),uVar4);
      if (iVar1 < 0) goto LAB_14000221c;
      if ((local_50[2] == 0) || (local_50[0] < 0x10)) {
                    /* WARNING: Subroutine does not return */
        RtlRaiseStatus(0xc00000e5);
      }
      local_80 = (ulonglong)*(uint *)(local_50[2] + 0xc);
      local_70 = local_50[2] + 0x10;
      local_28 = 0;
      local_38 = 0;
      uStack_30 = 0;
      local_78 = local_80;
      iVar1 = Windows::Rtl::AutoString<_LUNICODE_STRING,Windows::Auto<_LUNICODE_STRING>_>::Assign
                        ((AutoString<_LUNICODE_STRING,Windows::Auto<_LUNICODE_STRING>_> *)&local_38,
                         (_LUNICODE_STRING *)&local_80);
      if (iVar1 < 0) {
LAB_14000220d:
        if (local_28 != 0) {
          RtlFreeLUnicodeString((longlong)&local_38);
        }
LAB_14000221c:
        if (local_50[2] != 0) {
          RtlFreeLUnicodeString((longlong)local_50);
        }
        return iVar1;
      }
      piVar2 = (int *)BUCL::CVector<Windows::Auto<_LUNICODE_STRING>,BUCL::Rtl::CCallDisposition>::
                      SwapOntoBack((CVector<Windows::Auto<_LUNICODE_STRING>,BUCL::Rtl::CCallDisposition>
                                    *)this,(Auto<_LUNICODE_STRING> *)local_88,
                                   (GrowthPolicy)&local_38);
      iVar1 = *piVar2;
      if (iVar1 < 0) goto LAB_14000220d;
      if (local_28 != 0) {
        RtlFreeLUnicodeString((longlong)&local_38);
      }
      if (local_50[2] != 0) {
        RtlFreeLUnicodeString((longlong)local_50);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(this + 0x68));
  }
  BUCL::Implementation::
  QuickSort<BUCL::Rtl::CCallDisposition,unsigned___int64,Windows::Auto<_LUNICODE_STRING>,struct_BUCL::Implementation::ComparisonResultKind<BUCL::Rtl::CCallDisposition>_(__cdecl*)(_LUNICODE_STRING_const&___ptr64,_LUNICODE_STRING_const&___ptr64)>
            ((Auto<_LUNICODE_STRING> *)local_88,*(__uint64 *)this,
             (_func_ComparisonResultKind<BUCL::Rtl::CCallDisposition>__LUNICODE_STRING_ptr__LUNICODE_STRING_ptr
              *)(((longlong)(*(longlong *)(this + 8) - *(__uint64 *)this) >> 3) *
                -0x5555555555555555));
  lVar3 = 0;
  if (local_88[0] < 0) {
    lVar3 = local_88[0];
  }
  return lVar3;
}



===== GetAllValues @ 140002248 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl KeyContext::GetAllValues(void) __ptr64 */

long __thiscall KeyContext::GetAllValues(KeyContext *this)

{
  int iVar1;
  int *piVar2;
  long lVar3;
  uint uVar4;
  undefined1 auStack_b8 [32];
  undefined4 local_98;
  ulonglong *local_90;
  undefined8 local_88;
  int local_78 [2];
  ulonglong local_70;
  ulonglong local_68;
  longlong local_60;
  ulonglong local_58 [3];
  undefined8 local_40;
  undefined8 uStack_38;
  longlong local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_b8;
  uVar4 = 0;
  if (*(int *)(this + 0x6c) != 0) {
    do {
      local_90 = local_58;
      local_58[2] = 0;
      local_58[0] = 0;
      local_58[1] = 0;
      local_88 = 0;
      local_98 = 0;
      iVar1 = (**(code **)(**(longlong **)(this + 0x60) + 0xc0))
                        (*(longlong **)(this + 0x60),0,*(undefined8 *)(this + 0x58),uVar4);
      if (iVar1 < 0) {
LAB_140002390:
        if (local_58[2] != 0) {
          RtlFreeLUnicodeString((longlong)local_58);
        }
        return iVar1;
      }
      if ((local_58[2] == 0) || (local_58[0] < 0xc)) {
                    /* WARNING: Subroutine does not return */
        RtlRaiseStatus(0xc00000e5);
      }
      local_70 = (ulonglong)*(uint *)(local_58[2] + 8);
      local_60 = local_58[2] + 0xc;
      local_30 = 0;
      local_40 = 0;
      uStack_38 = 0;
      local_68 = local_70;
      iVar1 = Windows::Rtl::AutoString<_LUNICODE_STRING,Windows::Auto<_LUNICODE_STRING>_>::Assign
                        ((AutoString<_LUNICODE_STRING,Windows::Auto<_LUNICODE_STRING>_> *)&local_40,
                         (_LUNICODE_STRING *)&local_70);
      if (iVar1 < 0) {
        if (local_30 != 0) {
          RtlFreeLUnicodeString((longlong)&local_40);
        }
        goto LAB_140002390;
      }
      piVar2 = (int *)BUCL::CVector<Windows::Auto<_LUNICODE_STRING>,BUCL::Rtl::CCallDisposition>::
                      SwapOntoBack((CVector<Windows::Auto<_LUNICODE_STRING>,BUCL::Rtl::CCallDisposition>
                                    *)(this + 0x18),(Auto<_LUNICODE_STRING> *)local_78,
                                   (GrowthPolicy)&local_40);
      iVar1 = *piVar2;
      if (iVar1 < 0) {
        if (local_30 != 0) {
          RtlFreeLUnicodeString((longlong)&local_40);
        }
        if (local_58[2] != 0) {
          RtlFreeLUnicodeString((longlong)local_58);
        }
        return iVar1;
      }
      if (local_30 != 0) {
        RtlFreeLUnicodeString((longlong)&local_40);
      }
      if (local_58[2] != 0) {
        RtlFreeLUnicodeString((longlong)local_58);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(this + 0x6c));
  }
  BUCL::Implementation::
  QuickSort<BUCL::Rtl::CCallDisposition,unsigned___int64,Windows::Auto<_LUNICODE_STRING>,struct_BUCL::Implementation::ComparisonResultKind<BUCL::Rtl::CCallDisposition>_(__cdecl*)(_LUNICODE_STRING_const&___ptr64,_LUNICODE_STRING_const&___ptr64)>
            ((Auto<_LUNICODE_STRING> *)local_78,*(__uint64 *)(this + 0x18),
             (_func_ComparisonResultKind<BUCL::Rtl::CCallDisposition>__LUNICODE_STRING_ptr__LUNICODE_STRING_ptr
              *)(((longlong)(*(longlong *)(this + 0x20) - *(__uint64 *)(this + 0x18)) >> 3) *
                -0x5555555555555555));
  lVar3 = 0;
  if (local_78[0] < 0) {
    lVar3 = local_78[0];
  }
  return lVar3;
}



===== GetNtStatus @ 140002418 =====

/* public: long __cdecl Windows::ErrorHandling::Rtl::CBaseNtStatusCarryingFrame<struct
   Windows::ErrorHandling::Rtl::CVoidRaiseFrame,void>::GetNtStatus(void)const __ptr64 */

long __thiscall
Windows::ErrorHandling::Rtl::
CBaseNtStatusCarryingFrame<Windows::ErrorHandling::Rtl::CVoidRaiseFrame,void>::GetNtStatus
          (CBaseNtStatusCarryingFrame<Windows::ErrorHandling::Rtl::CVoidRaiseFrame,void> *this)

{
  return *(long *)this;
}



===== GrowByOne @ 140002424 =====

/* private: class BUCL::Rtl::CCallDisposition __cdecl BUCL::CVector<struct KeyContext,class
   BUCL::Rtl::CCallDisposition>::GrowByOne(enum BUCL::GrowthPolicy) __ptr64 */

uint * __thiscall
BUCL::CVector<KeyContext,BUCL::Rtl::CCallDisposition>::GrowByOne
          (CVector<KeyContext,BUCL::Rtl::CCallDisposition> *this,GrowthPolicy param_1)

{
  uint uVar1;
  KeyContext *pKVar2;
  KeyContext *pKVar3;
  undefined4 in_register_00000014;
  uint *puVar4;
  __uint64 *p_Var5;
  __uint64 *p_Var6;
  KeyContext *pKVar7;
  undefined1 in_R8B;
  longlong lVar8;
  __uint64 *p_Var9;
  uint uVar10;
  KeyContext *this_00;
  uint local_res18 [4];
  
  puVar4 = (uint *)CONCAT44(in_register_00000014,param_1);
  local_res18[0] = CONCAT31(local_res18[0]._1_3_,in_R8B);
  lVar8 = *(longlong *)(this + 0x10) - *(longlong *)this >> 3;
  p_Var9 = (__uint64 *)(lVar8 * -0xf0f0f0f0f0f0f0f);
  p_Var5 = p_Var9;
  if (p_Var9 != (__uint64 *)0xffffffffffffffff) {
    p_Var5 = (__uint64 *)((longlong)p_Var9 + 1);
  }
  uVar1 = 0xc0000095;
  uVar10 = 0xc0000095;
  if (p_Var9 != (__uint64 *)0xffffffffffffffff) {
    uVar10 = 0;
  }
  if ((int)uVar10 < 0) {
    *puVar4 = uVar10;
    return puVar4;
  }
  if (p_Var5 <= p_Var9) {
    uVar1 = 0;
    goto LAB_1400025e5;
  }
  p_Var6 = (__uint64 *)0x4;
  if ((__uint64 *)0x3 < p_Var9) {
    if (p_Var9 < (__uint64 *)0x21) {
      p_Var6 = (__uint64 *)(lVar8 * -0x1e1e1e1e1e1e1e1e);
    }
    else {
      p_Var6 = (__uint64 *)(((ulonglong)p_Var9 >> 1) + (longlong)p_Var9);
    }
    if (p_Var9 <= p_Var6) {
      uVar1 = 0;
    }
    if ((int)uVar1 < 0) goto LAB_1400025e5;
  }
  if (p_Var6 < p_Var5) {
    p_Var6 = p_Var5;
  }
  if ((__uint64 *)0x1e1e1e1e1e1e1e0 < p_Var6) {
    uVar1 = 0xc0000017;
    goto LAB_1400025e5;
  }
  if (p_Var9 < p_Var6) {
    Implementation::Multiply<BUCL::Rtl::CCallDisposition,unsigned___int64>
              ((__uint64)local_res18,0x88,p_Var6);
    if (-1 < (int)local_res18[0]) {
      pKVar2 = operator_new(0);
      if (pKVar2 != (KeyContext *)0x0) {
        this_00 = pKVar2;
        for (pKVar7 = *(KeyContext **)this; pKVar3 = *(KeyContext **)(this + 8), pKVar7 != pKVar3;
            pKVar7 = pKVar7 + 0x88) {
          if (this_00 != (KeyContext *)0x0) {
            KeyContext::KeyContext(this_00,pKVar7);
          }
          this_00 = this_00 + 0x88;
        }
        pKVar7 = *(KeyContext **)this;
        lVar8 = (longlong)pKVar3 - (longlong)pKVar7;
        while (pKVar7 != pKVar3) {
          KeyContext::~KeyContext(pKVar3 + -0x88);
          pKVar3 = (KeyContext *)(*(longlong *)(this + 8) + -0x88);
          *(KeyContext **)(this + 8) = pKVar3;
          pKVar7 = *(KeyContext **)this;
        }
        if (pKVar7 != (KeyContext *)0x0) {
          ExFreePoolWithTag(pKVar7,0);
        }
        *(KeyContext **)this = pKVar2;
        *(KeyContext **)(this + 8) = pKVar2 + (lVar8 >> 3) * 8;
        *(KeyContext **)(this + 0x10) = pKVar2 + (longlong)p_Var6 * 0x88;
        goto LAB_1400025d7;
      }
      local_res18[0] = 0xc0000017;
    }
  }
  else {
LAB_1400025d7:
    local_res18[0] = 0;
  }
  uVar1 = -(uint)((int)local_res18[0] < 0) & local_res18[0];
LAB_1400025e5:
  if ((int)uVar1 < 0) {
    *puVar4 = uVar1;
  }
  else {
    *puVar4 = 0;
  }
  return puVar4;
}



===== MergeGlobbedRegistry @ 140002614 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl MergeGlobbedRegistry(struct Windows::Vector<class
   Windows::Rtl::SystemImplementation::IRtlRegistryProvider * __ptr64>,class
   Windows::Rtl::SystemImplementation::IRtlRegistryProvider * __ptr64,struct _LUNICODE_STRING const
   & __ptr64) */

long __cdecl MergeGlobbedRegistry(longlong *param_1,longlong *param_2,_LUNICODE_STRING *param_3)

{
  undefined8 *puVar1;
  KeyContext *pKVar2;
  uint uVar3;
  long lVar4;
  ulonglong uVar5;
  KeyContext *pKVar6;
  undefined8 *puVar7;
  undefined1 auStack_1b8 [32];
  undefined8 *local_198;
  undefined4 local_190;
  undefined8 local_188;
  undefined4 local_180;
  undefined8 local_178;
  undefined8 local_170;
  KeyContext *local_158;
  KeyContext *pKStack_150;
  KeyContext *local_148;
  uint local_138 [2];
  undefined8 local_130;
  undefined8 local_128;
  undefined8 *local_120;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 uStack_108;
  CSilHandle local_100 [8];
  undefined8 *local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined1 local_90;
  undefined8 local_88;
  longlong lStack_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined4 local_58;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_1b8;
  local_e8 = 0;
  uStack_e0 = 0;
  uVar3 = RtlInitUnicodeStringFromLUnicodeString((ulonglong *)param_3,(undefined4 *)&local_e8);
  if (-1 < (int)uVar3) {
    local_170 = 0;
    local_120 = &local_e8;
    local_178 = 0;
    local_198 = &local_130;
    local_180 = 0;
    local_188 = 0;
    local_190 = 0;
    local_130 = 0x30;
    local_128 = 0;
    local_118 = 0x40;
    local_110 = 0;
    uStack_108 = 0;
    local_100[0] = (CSilHandle)0x0;
    local_f8 = (undefined8 *)0x0;
    uStack_f0 = 0;
    uVar3 = (**(code **)(*param_2 + 0x50))(param_2,0,local_100,0x20006);
    if ((int)uVar3 < 0) {
      Windows::Rtl::SystemImplementation::CSilHandle::Close(local_100);
      puVar1 = local_f8;
      if (local_f8 != (undefined8 *)0x0) {
        local_f8 = (undefined8 *)0x0;
        (**(code **)*puVar1)();
      }
    }
    else {
      puVar7 = (undefined8 *)*param_1;
      local_158 = (KeyContext *)0x0;
      pKStack_150 = (KeyContext *)0x0;
      pKVar6 = (KeyContext *)0x0;
      local_148 = (KeyContext *)0x0;
      puVar1 = puVar7 + param_1[1];
      for (; pKVar2 = local_158, puVar7 != puVar1; puVar7 = puVar7 + 1) {
        local_90 = 0;
        local_d8 = 0;
        uStack_d0 = 0;
        local_c8 = 0;
        uStack_c0 = 0;
        local_b8 = 0;
        uStack_b0 = 0;
        local_98 = 0;
        local_a8 = 0;
        uStack_a0 = 0;
        local_78 = 0;
        local_88 = 0;
        lStack_80 = 0;
        local_70 = 0;
        local_68 = 0;
        local_60 = 0;
        local_58 = 0;
        lVar4 = KeyContext::Create(true,(IRtlRegistryProvider *)*puVar7,param_3,
                                   (KeyContext *)&local_d8);
        if (lVar4 < 0) {
          KeyContext::~KeyContext((KeyContext *)&local_d8);
          pKVar2 = local_158;
          while (pKVar2 != pKVar6) {
            pKVar6 = pKVar6 + -0x88;
            KeyContext::~KeyContext(pKVar6);
          }
          if (pKVar2 != (KeyContext *)0x0) {
            ExFreePoolWithTag(pKVar2,0);
          }
          Windows::Rtl::SystemImplementation::CSilHandle::Close(local_100);
          puVar1 = local_f8;
          if (local_f8 != (undefined8 *)0x0) {
            local_f8 = (undefined8 *)0x0;
            (**(code **)*puVar1)();
          }
          return lVar4;
        }
        if (lStack_80 != 0) {
          if (pKVar6 == local_148) {
            BUCL::CVector<KeyContext,BUCL::Rtl::CCallDisposition>::GrowByOne
                      ((CVector<KeyContext,BUCL::Rtl::CCallDisposition> *)&local_158,
                       (GrowthPolicy)local_138);
            if ((int)local_138[0] < 0) {
              KeyContext::~KeyContext((KeyContext *)&local_d8);
              pKVar2 = local_158;
              pKVar6 = pKStack_150;
              while (pKVar2 != pKVar6) {
                pKVar6 = pKVar6 + -0x88;
                KeyContext::~KeyContext(pKVar6);
              }
              if (pKVar2 != (KeyContext *)0x0) {
                ExFreePoolWithTag(pKVar2,0);
              }
              Windows::Rtl::SystemImplementation::CSilHandle::Close(local_100);
              puVar1 = local_f8;
              if (local_f8 != (undefined8 *)0x0) {
                local_f8 = (undefined8 *)0x0;
                (**(code **)*puVar1)();
              }
              return local_138[0];
            }
            pKVar6 = pKStack_150;
          }
          if (pKVar6 != (KeyContext *)0x0) {
            KeyContext::KeyContext(pKVar6,(KeyContext *)&local_d8);
          }
          pKVar6 = pKVar6 + 0x88;
          pKStack_150 = pKVar6;
        }
        KeyContext::~KeyContext((KeyContext *)&local_d8);
      }
      pKStack_150 = (KeyContext *)
                    (((longlong)pKVar6 - (longlong)local_158 >> 3) * -0xf0f0f0f0f0f0f0f);
      uVar5 = MergeKey((KeyContext *)param_3,(longlong *)&local_158,uStack_f0,param_2);
      uVar3 = (uint)uVar5;
      if ((int)uVar3 < 0) {
        while (pKVar2 != pKVar6) {
          pKVar6 = pKVar6 + -0x88;
          KeyContext::~KeyContext(pKVar6);
        }
        if (pKVar2 != (KeyContext *)0x0) {
          ExFreePoolWithTag(pKVar2,0);
        }
        Windows::Rtl::SystemImplementation::CSilHandle::Close(local_100);
        puVar1 = local_f8;
        if (local_f8 != (undefined8 *)0x0) {
          local_f8 = (undefined8 *)0x0;
          (**(code **)*puVar1)();
        }
      }
      else {
        while (pKVar2 != pKVar6) {
          pKVar6 = pKVar6 + -0x88;
          KeyContext::~KeyContext(pKVar6);
        }
        if (pKVar2 != (KeyContext *)0x0) {
          ExFreePoolWithTag(pKVar2,0);
        }
        Windows::Rtl::SystemImplementation::CSilHandle::Close(local_100);
        puVar1 = local_f8;
        if (local_f8 != (undefined8 *)0x0) {
          local_f8 = (undefined8 *)0x0;
          (**(code **)*puVar1)();
        }
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}



===== MergeKey @ 1400029c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong MergeKey(KeyContext *param_1,longlong *param_2,undefined8 param_3,longlong *param_4)

{
  undefined8 *puVar1;
  undefined4 *puVar2;
  longlong *plVar3;
  ulonglong *puVar4;
  KeyContext *pKVar5;
  long lVar6;
  uint uVar7;
  undefined4 extraout_var;
  longlong *plVar8;
  undefined4 extraout_var_00;
  ulonglong uVar9;
  longlong lVar10;
  __uint64 *p_Var11;
  longlong *plVar12;
  KeyContext *pKVar13;
  longlong *plVar14;
  KeyContext *pKVar15;
  __uint64 *p_Var16;
  longlong *plVar17;
  longlong *plVar18;
  ulonglong uVar19;
  __uint64 *p_Var20;
  bool bVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  undefined8 uVar28;
  undefined1 auStackY_1c8 [32];
  ulonglong local_168;
  uint local_160 [2];
  KeyContext *local_158;
  KeyContext *pKStack_150;
  KeyContext *local_148;
  longlong *local_140;
  longlong *local_138;
  KeyContext *local_128;
  longlong local_120;
  longlong *local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  longlong **local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  ulonglong local_d8;
  longlong lStack_d0;
  longlong local_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  CSilHandle local_a8 [8];
  undefined8 *local_a0;
  undefined8 uStack_98;
  longlong *local_90;
  longlong lStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined8 local_58;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStackY_1c8;
  plVar18 = (longlong *)*param_2;
  plVar8 = plVar18 + param_2[1] * 0x11;
  local_140 = plVar8;
  local_138 = plVar18;
  local_128 = param_1;
  local_118 = param_4;
  local_110 = param_3;
  do {
    local_70 = 0;
    bVar21 = false;
    local_c0 = 0;
    uStack_b8 = 0;
    local_b0 = 0;
    pKVar15 = local_158;
    pKVar13 = pKStack_150;
    pKVar5 = local_148;
    for (plVar14 = plVar18; local_158 = pKVar15, pKStack_150 = pKVar13, local_148 = pKVar5,
        plVar14 != plVar8; plVar14 = plVar14 + 0x11) {
      lVar10 = plVar14[3];
      uVar19 = (ulonglong)*(uint *)(plVar14 + 0x10);
      if (uVar19 < (ulonglong)((plVar14[4] - lVar10 >> 3) * -0x5555555555555555)) {
        local_148 = *(KeyContext **)(lVar10 + 0x10 + uVar19 * 0x18);
        uVar22 = SUB84(local_148,0);
        uVar23 = (undefined4)((ulonglong)local_148 >> 0x20);
        puVar1 = (undefined8 *)(lVar10 + uVar19 * 0x18);
        uVar24 = *(undefined4 *)puVar1;
        uVar25 = *(undefined4 *)((longlong)puVar1 + 4);
        local_158 = (KeyContext *)*puVar1;
        uVar26 = *(undefined4 *)(puVar1 + 1);
        uVar27 = *(undefined4 *)((longlong)puVar1 + 0xc);
        pKStack_150 = (KeyContext *)puVar1[1];
        if (bVar21) {
          local_168 = local_168 & 0xffffffff00000000;
          lVar6 = Windows::StringUtil::Rtl::
                  CompareStringsByOrdinalCaseInvariant<_LUNICODE_STRING,_LUNICODE_STRING>
                            ((_LUNICODE_STRING *)&local_158,(_LUNICODE_STRING *)&local_c0,
                             (int *)&local_168);
          if (lVar6 < 0) {
            return CONCAT44(extraout_var,lVar6);
          }
          if (-1 < (int)local_168) goto LAB_140002af4;
          lVar10 = plVar14[3];
          uVar19 = (ulonglong)*(uint *)(plVar14 + 0x10);
          if ((ulonglong)((plVar14[4] - lVar10 >> 3) * -0x5555555555555555) <= uVar19) {
                    /* WARNING: Subroutine does not return */
            RtlRaiseStatus(0xc00000e5);
          }
          puVar2 = (undefined4 *)(lVar10 + uVar19 * 0x18);
          uVar24 = *puVar2;
          uVar25 = puVar2[1];
          uVar26 = puVar2[2];
          uVar27 = puVar2[3];
          uVar28 = *(undefined8 *)(lVar10 + 0x10 + uVar19 * 0x18);
          uVar22 = (undefined4)uVar28;
          uVar23 = (undefined4)((ulonglong)uVar28 >> 0x20);
        }
        else {
          bVar21 = true;
          local_158 = pKVar15;
          pKStack_150 = pKVar13;
          local_148 = pKVar5;
        }
        local_b0 = CONCAT44(uVar23,uVar22);
        local_c0 = CONCAT44(uVar25,uVar24);
        uStack_b8 = CONCAT44(uVar27,uVar26);
      }
LAB_140002af4:
      pKVar15 = local_158;
      pKVar13 = pKStack_150;
      pKVar5 = local_148;
    }
    if (!bVar21) goto LAB_140002dc9;
    plVar12 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    plVar17 = (longlong *)0x0;
    if (plVar18 != plVar8) {
      do {
        lVar10 = plVar18[3];
        uVar19 = (ulonglong)*(uint *)(plVar18 + 0x10);
        if (uVar19 < (ulonglong)((plVar18[4] - lVar10 >> 3) * -0x5555555555555555)) {
          local_168 = local_168 & 0xffffffff00000000;
          puVar1 = (undefined8 *)(lVar10 + uVar19 * 0x18);
          local_158 = (KeyContext *)*puVar1;
          pKStack_150 = (KeyContext *)puVar1[1];
          local_148 = *(KeyContext **)(lVar10 + 0x10 + uVar19 * 0x18);
          lVar6 = Windows::StringUtil::Rtl::
                  CompareStringsByOrdinalCaseInvariant<_LUNICODE_STRING,_LUNICODE_STRING>
                            ((_LUNICODE_STRING *)&local_c0,(_LUNICODE_STRING *)&local_158,
                             (int *)&local_168);
          if (((int)local_168 == 0) && (-1 < lVar6)) {
            if (plVar14 == plVar17) {
              p_Var11 = (__uint64 *)((longlong)plVar17 - (longlong)plVar12 >> 3);
              p_Var16 = p_Var11;
              if (p_Var11 != (__uint64 *)0xffffffffffffffff) {
                p_Var16 = (__uint64 *)((longlong)p_Var11 + 1);
              }
              uVar19 = 0xc0000095;
              if (p_Var11 != (__uint64 *)0xffffffffffffffff) {
                uVar19 = 0;
              }
              if (-1 < (char)(uVar19 >> 0x18)) {
                if (p_Var11 < p_Var16) {
                  if (p_Var11 < (__uint64 *)0x4) {
                    p_Var20 = (__uint64 *)0x4;
                  }
                  else {
                    if (p_Var11 < (__uint64 *)0x21) {
                      p_Var20 = (__uint64 *)((longlong)p_Var11 * 2);
                    }
                    else {
                      p_Var20 = (__uint64 *)(((ulonglong)p_Var11 >> 1) + (longlong)p_Var11);
                    }
                    uVar7 = -(uint)(p_Var20 < p_Var11) & 0xc0000095;
                    if ((int)uVar7 < 0) goto LAB_140002cca;
                  }
                  if (p_Var20 < p_Var16) {
                    p_Var20 = p_Var16;
                  }
                  if (p_Var20 < (__uint64 *)0x1fffffffffffffff) {
                    plVar8 = plVar12;
                    if (p_Var11 < p_Var20) {
                      local_168 = 0;
                      BUCL::Implementation::Multiply<BUCL::Rtl::CCallDisposition,unsigned___int64>
                                ((__uint64)local_160,8,p_Var20);
                      uVar7 = local_160[0];
                      if (-1 < (int)local_160[0]) {
                        plVar8 = operator_new(local_168);
                        if (plVar8 != (longlong *)0x0) {
                          if (plVar12 != plVar14) {
                            plVar17 = plVar12;
                            do {
                              plVar3 = (longlong *)
                                       (((longlong)plVar8 - (longlong)plVar12) + (longlong)plVar17);
                              if (plVar3 != (longlong *)0x0) {
                                *plVar3 = *plVar17;
                              }
                              plVar17 = plVar17 + 1;
                            } while (plVar17 != plVar14);
                          }
                          if (plVar12 != (longlong *)0x0) {
                            ExFreePoolWithTag(plVar12,0);
                          }
                          plVar14 = plVar8 + ((longlong)plVar14 - (longlong)plVar12 >> 3);
                          plVar17 = plVar8 + (longlong)p_Var20;
                          goto LAB_140002cbd;
                        }
                        uVar7 = 0xc0000017;
                        plVar8 = plVar12;
                      }
                    }
                    else {
LAB_140002cbd:
                      uVar7 = 0;
                    }
                    uVar7 = -(uint)((int)uVar7 < 0) & uVar7;
                    plVar12 = plVar8;
                  }
                  else {
                    uVar7 = 0xc0000017;
                  }
                }
                else {
                  uVar7 = 0;
                }
LAB_140002cca:
                uVar19 = (ulonglong)(-(uint)((int)uVar7 < 0) & uVar7);
              }
              if (-1 < (char)(uVar19 >> 0x18)) goto LAB_140002d04;
              if ((int)uVar19 < 0) {
                if (plVar12 == (longlong *)0x0) {
                  return uVar19;
                }
                ExFreePoolWithTag(plVar12,0);
                return uVar19;
              }
            }
            else {
LAB_140002d04:
              if (plVar14 != (longlong *)0x0) {
                *plVar14 = (longlong)plVar18;
              }
              plVar14 = plVar14 + 1;
            }
            *(int *)(plVar18 + 0x10) = (int)plVar18[0x10] + 1;
            plVar8 = local_140;
          }
        }
        plVar18 = plVar18 + 0x11;
      } while (plVar18 != plVar8);
      plVar18 = local_138;
    }
    param_4 = local_118;
    param_1 = local_128;
    lStack_88 = (longlong)plVar14 - (longlong)plVar12 >> 3;
    local_90 = plVar12;
    uVar19 = MergeValue((ulonglong *)local_128,&local_90,&local_c0,local_110,local_118);
    if ((int)uVar19 < 0) {
      if (plVar12 != (longlong *)0x0) {
        ExFreePoolWithTag(plVar12,0);
      }
      return uVar19 & 0xffffffff;
    }
    if (plVar12 != (longlong *)0x0) {
      ExFreePoolWithTag(plVar12,0);
    }
  } while( true );
joined_r0x000140003283:
  while (pKVar13 != pKVar15) {
    KeyContext::~KeyContext(pKVar15 + -0x88);
    pKVar15 = pKVar15 + -0x88;
  }
  goto LAB_140003299;
joined_r0x0001400032ca:
  while (pKVar13 != pKVar15) {
    pKVar15 = pKVar15 + -0x88;
    KeyContext::~KeyContext(pKVar15);
  }
  goto LAB_140003299;
joined_r0x0001400033a6:
  while (pKVar13 != pKVar15) {
    pKVar15 = pKVar15 + -0x88;
    KeyContext::~KeyContext(pKVar15);
  }
  goto LAB_140003299;
LAB_140002dc9:
  uVar24 = 0;
  uVar25 = 0;
  uVar26 = 0;
  uVar27 = 0;
  uVar28 = 0;
  local_b0 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  for (plVar14 = plVar18; plVar14 != plVar8; plVar14 = plVar14 + 0x11) {
    lVar10 = *plVar14;
    uVar19 = (ulonglong)*(uint *)((longlong)plVar14 + 0x7c);
    if (uVar19 < (ulonglong)((plVar14[1] - lVar10 >> 3) * -0x5555555555555555)) {
      if (local_c0 != 0) {
        puVar1 = (undefined8 *)(lVar10 + uVar19 * 0x18);
        local_80 = *puVar1;
        uStack_78 = puVar1[1];
        local_168 = local_168 & 0xffffffff00000000;
        local_70 = *(undefined8 *)(lVar10 + 0x10 + uVar19 * 0x18);
        lVar6 = Windows::StringUtil::Rtl::
                CompareStringsByOrdinalCaseInvariant<_LUNICODE_STRING,_LUNICODE_STRING>
                          ((_LUNICODE_STRING *)&local_80,(_LUNICODE_STRING *)&local_c0,
                           (int *)&local_168);
        if (lVar6 < 0) {
          return CONCAT44(extraout_var_00,lVar6);
        }
        if (-1 < (int)local_168) {
          uVar24 = (undefined4)local_c0;
          uVar25 = local_c0._4_4_;
          uVar26 = (undefined4)uStack_b8;
          uVar27 = uStack_b8._4_4_;
          uVar28 = local_b0;
          goto LAB_140002e9f;
        }
        lVar10 = *plVar14;
        uVar19 = (ulonglong)*(uint *)((longlong)plVar14 + 0x7c);
        if ((ulonglong)((plVar14[1] - lVar10 >> 3) * -0x5555555555555555) <= uVar19) {
                    /* WARNING: Subroutine does not return */
          RtlRaiseStatus(0xc00000e5);
        }
      }
      local_b0 = *(undefined8 *)(lVar10 + 0x10 + uVar19 * 0x18);
      puVar4 = (ulonglong *)(lVar10 + uVar19 * 0x18);
      local_c0 = *puVar4;
      uStack_b8 = puVar4[1];
      uVar24 = (int)*puVar4;
      uVar25 = *(undefined4 *)((longlong)puVar4 + 4);
      uVar26 = (int)puVar4[1];
      uVar27 = *(undefined4 *)((longlong)puVar4 + 0xc);
      uVar28 = local_b0;
    }
LAB_140002e9f:
  }
  if (CONCAT44(uVar25,uVar24) == 0) {
    return 0;
  }
  local_70 = *(undefined8 *)(param_1 + 0x10);
  local_d8 = 0;
  lStack_d0 = 0;
  local_c8 = 0;
  local_80 = *(undefined8 *)param_1;
  uStack_78 = *(undefined8 *)(param_1 + 8);
  local_68 = uVar24;
  uStack_64 = uVar25;
  uStack_60 = uVar26;
  uStack_5c = uVar27;
  local_58 = uVar28;
  uVar19 = RtlCombineNtPathSegments(2,(longlong)&local_80,(longlong *)&local_d8);
  uVar9 = uVar19 & 0xffffffff;
  if ((int)uVar19 < 0) goto LAB_1400033c5;
  if (lStack_d0 - local_d8 < 2) {
    uVar7 = -(uint)(local_d8 + 2 < local_d8) & 0xc0000095;
    uVar9 = (ulonglong)uVar7;
    if (((int)uVar7 < 0) && ((int)uVar7 < 0)) {
LAB_1400033c5:
      if (local_c8 == 0) {
        return uVar9;
      }
      RtlFreeLUnicodeString((longlong)&local_d8);
      return uVar9;
    }
    uVar7 = RtlReallocateLUnicodeString(local_d8,local_d8 + 2,&local_d8);
    uVar9 = (ulonglong)uVar7;
    if ((int)uVar7 < 0) goto LAB_1400033c5;
  }
  local_148 = (KeyContext *)0x0;
  local_158 = (KeyContext *)0x0;
  pKStack_150 = (KeyContext *)0x0;
  pKVar15 = (KeyContext *)0x0;
  pKVar13 = (KeyContext *)0x0;
  *(undefined2 *)(local_c8 + (local_d8 & 0xfffffffffffffffe)) = 0;
  if (plVar18 != plVar8) {
    do {
      lVar10 = *plVar18;
      uVar19 = (ulonglong)*(uint *)((longlong)plVar18 + 0x7c);
      if (uVar19 < (ulonglong)((plVar18[1] - lVar10 >> 3) * -0x5555555555555555)) {
        local_168 = local_168 & 0xffffffff00000000;
        puVar1 = (undefined8 *)(lVar10 + uVar19 * 0x18);
        local_80 = *puVar1;
        uStack_78 = puVar1[1];
        local_70 = *(undefined8 *)(lVar10 + 0x10 + uVar19 * 0x18);
        lVar6 = Windows::StringUtil::Rtl::
                CompareStringsByOrdinalCaseInvariant<_LUNICODE_STRING,_LUNICODE_STRING>
                          ((_LUNICODE_STRING *)&local_c0,(_LUNICODE_STRING *)&local_80,
                           (int *)&local_168);
        if (((int)local_168 == 0) && (-1 < lVar6)) {
          if (pKVar15 == local_148) {
            BUCL::CVector<KeyContext,BUCL::Rtl::CCallDisposition>::GrowByOne
                      ((CVector<KeyContext,BUCL::Rtl::CCallDisposition> *)&local_158,
                       (GrowthPolicy)local_160);
            pKVar13 = local_158;
            uVar19 = (ulonglong)local_160[0];
            pKVar15 = pKStack_150;
            if ((int)local_160[0] < 0) goto joined_r0x000140003283;
          }
          if (pKVar15 != (KeyContext *)0x0) {
            memset(pKVar15,0,0x88);
            *(undefined8 *)pKVar15 = 0;
            *(undefined8 *)(pKVar15 + 8) = 0;
            *(undefined8 *)(pKVar15 + 0x10) = 0;
            *(undefined8 *)(pKVar15 + 0x18) = 0;
            *(undefined8 *)(pKVar15 + 0x20) = 0;
            *(undefined8 *)(pKVar15 + 0x28) = 0;
            *(undefined8 *)(pKVar15 + 0x30) = 0;
            *(undefined8 *)(pKVar15 + 0x38) = 0;
            *(undefined8 *)(pKVar15 + 0x40) = 0;
            pKVar15[0x48] = (KeyContext)0x0;
            *(undefined8 *)(pKVar15 + 0x50) = 0;
            *(undefined8 *)(pKVar15 + 0x58) = 0;
            *(undefined8 *)(pKVar15 + 0x60) = 0;
            *(undefined8 *)(pKVar15 + 0x68) = 0;
            *(undefined8 *)(pKVar15 + 0x70) = 0;
            *(undefined8 *)(pKVar15 + 0x78) = 0;
            *(undefined4 *)(pKVar15 + 0x80) = 0;
          }
          pKVar15 = pKVar15 + 0x88;
          pKStack_150 = pKVar15;
          uVar7 = KeyContext::Create(false,(IRtlRegistryProvider *)plVar18[0xc],
                                     (_LUNICODE_STRING *)&local_d8,
                                     pKVar13 + ((longlong)pKVar15 - (longlong)pKVar13 >> 3) * 8 +
                                               -0x88);
          uVar19 = (ulonglong)uVar7;
          if ((int)uVar7 < 0) goto joined_r0x0001400032ca;
          *(int *)((longlong)plVar18 + 0x7c) = *(int *)((longlong)plVar18 + 0x7c) + 1;
          plVar8 = local_140;
        }
      }
      plVar18 = plVar18 + 0x11;
    } while (plVar18 != plVar8);
  }
  local_90 = (longlong *)0x0;
  lStack_88 = 0;
  uVar7 = RtlInitUnicodeStringFromLUnicodeString(&local_d8,(undefined4 *)&local_90);
  uVar19 = (ulonglong)uVar7;
  if ((int)uVar7 < 0) goto joined_r0x0001400033a6;
  local_f8 = &local_90;
  local_108 = 0x30;
  local_100 = 0;
  local_f0 = 0x40;
  local_e8 = 0;
  uStack_e0 = 0;
  local_a8[0] = (CSilHandle)0x0;
  local_a0 = (undefined8 *)0x0;
  uStack_98 = 0;
  uVar7 = (**(code **)(*param_4 + 0x50))(param_4,0,local_a8,0x20006);
  uVar19 = (ulonglong)uVar7;
  if ((int)uVar7 < 0) {
    Windows::Rtl::SystemImplementation::CSilHandle::Close(local_a8);
    puVar1 = local_a0;
    bVar21 = local_a0 != (undefined8 *)0x0;
    local_a0 = (undefined8 *)0x0;
    if (bVar21) {
      local_a0 = (undefined8 *)0x0;
      (**(code **)*puVar1)();
    }
    while (pKVar13 != pKVar15) {
      pKVar15 = pKVar15 + -0x88;
      KeyContext::~KeyContext(pKVar15);
    }
    goto LAB_140003299;
  }
  if (SecurityDescriptor != (void *)0x0) {
    uVar7 = (**(code **)(*param_4 + 0x20))(param_4,0,uStack_98,0);
    uVar19 = (ulonglong)uVar7;
    if ((int)uVar7 < 0) {
      Windows::Rtl::SystemImplementation::CSilHandle::Close(local_a8);
      puVar1 = local_a0;
      bVar21 = local_a0 != (undefined8 *)0x0;
      local_a0 = (undefined8 *)0x0;
      if (bVar21) {
        local_a0 = (undefined8 *)0x0;
        (**(code **)*puVar1)();
      }
      while (pKVar13 != pKVar15) {
        pKVar15 = pKVar15 + -0x88;
        KeyContext::~KeyContext(pKVar15);
      }
      goto LAB_140003299;
    }
  }
  local_120 = ((longlong)pKVar15 - (longlong)pKVar13 >> 3) * -0xf0f0f0f0f0f0f0f;
  local_128 = pKVar13;
  uVar9 = MergeKey((KeyContext *)&local_d8,(longlong *)&local_128,uStack_98,param_4);
  uVar19 = uVar9 & 0xffffffff;
  if (-1 < (int)uVar9) {
    Windows::Rtl::SystemImplementation::CSilHandle::Close(local_a8);
    puVar1 = local_a0;
    bVar21 = local_a0 != (undefined8 *)0x0;
    local_a0 = (undefined8 *)0x0;
    if (bVar21) {
      local_a0 = (undefined8 *)0x0;
      (**(code **)*puVar1)();
    }
    while (pKVar13 != pKVar15) {
      pKVar15 = pKVar15 + -0x88;
      KeyContext::~KeyContext(pKVar15);
    }
    if (pKVar13 != (KeyContext *)0x0) {
      ExFreePoolWithTag(pKVar13,0);
    }
    plVar18 = local_138;
    plVar8 = local_140;
    if (local_c8 != 0) {
      RtlFreeLUnicodeString((longlong)&local_d8);
    }
    goto LAB_140002dc9;
  }
  Windows::Rtl::SystemImplementation::CSilHandle::Close(local_a8);
  puVar1 = local_a0;
  bVar21 = local_a0 != (undefined8 *)0x0;
  local_a0 = (undefined8 *)0x0;
  if (bVar21) {
    local_a0 = (undefined8 *)0x0;
    (**(code **)*puVar1)();
  }
  while (pKVar13 != pKVar15) {
    pKVar15 = pKVar15 + -0x88;
    KeyContext::~KeyContext(pKVar15);
  }
LAB_140003299:
  if (pKVar13 != (KeyContext *)0x0) {
    ExFreePoolWithTag(pKVar13,0);
  }
  if (local_c8 != 0) {
    RtlFreeLUnicodeString((longlong)&local_d8);
  }
  return uVar19;
}



===== MergeValue @ 140003400 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong MergeValue(ulonglong *param_1,longlong **param_2,ulonglong *param_3,undefined8 param_4,
                    longlong *param_5)

{
  longlong *plVar1;
  longlong *plVar2;
  uint uVar3;
  uint uVar4;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  ulonglong uVar5;
  char **ppcVar6;
  ulonglong *puVar7;
  ulonglong uVar8;
  longlong *plVar9;
  undefined1 auStack_178 [32];
  ulonglong *local_158;
  undefined8 *local_150;
  int *local_148;
  int *local_140;
  char *local_128;
  char *local_120;
  ulonglong local_118;
  undefined8 local_110;
  longlong local_108;
  longlong *local_100;
  longlong *plStack_f8;
  longlong local_f0;
  int local_e8 [2];
  undefined8 local_e0;
  undefined8 uStack_d8;
  longlong local_d0;
  char *local_c8;
  char *pcStack_c0;
  longlong local_b8;
  undefined8 local_b0;
  ulonglong local_a8 [2];
  wchar_t local_98 [8];
  ulonglong local_88 [2];
  wchar_t *local_78;
  longlong *local_70;
  longlong *plStack_68;
  longlong local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStack_178;
  local_100 = (longlong *)0x0;
  plStack_f8 = (longlong *)0x0;
  uVar3 = RtlInitUnicodeStringFromLUnicodeString(param_1,(undefined4 *)&local_100);
  if ((int)uVar3 < 0) {
    return CONCAT44(extraout_var,uVar3);
  }
  puVar7 = local_a8;
  local_a8[0] = 0;
  local_a8[1] = 0;
  uVar3 = RtlInitUnicodeStringFromLUnicodeString(param_3,(undefined4 *)puVar7);
  if ((int)uVar3 < 0) {
    return CONCAT44(extraout_var_00,uVar3);
  }
  local_70 = (longlong *)(*param_1 - 0x24);
  local_118 = param_1[2];
  if (*param_1 < 0x24) {
    local_118 = 0x103d;
    local_128 = "OneCore\\Internal\\Base\\inc\\rtlstringutil.h";
    ppcVar6 = &local_128;
    local_110 = 0;
    local_120 = "Windows::StringUtil::Rtl::SubStringByByteCount";
  }
  else {
    if (local_70 <= (longlong *)(*param_1 - 0x24)) {
      local_f0 = local_118 + 0x24;
      local_b8 = 0;
      local_88[0] = 0x34;
      local_88[1] = 0x34;
      local_78 = L"\\Registry\\Machine\\Override";
      local_c8 = (char *)0x0;
      pcStack_c0 = (char *)0x0;
      local_100 = local_70;
      plStack_f8 = local_70;
      plStack_68 = local_70;
      local_60 = local_f0;
      uVar5 = RtlCombineNtPathSegments(2,(longlong)local_88,(longlong *)&local_c8);
      uVar8 = uVar5 & 0xffffffff;
      if (-1 < (int)uVar5) {
        local_98[0] = L'\0';
        local_98[1] = L'\0';
        local_98[2] = L'\0';
        local_98[3] = L'\0';
        local_98[4] = L'\0';
        local_98[5] = L'\0';
        local_98[6] = L'\0';
        local_98[7] = L'\0';
        uVar3 = RtlInitUnicodeStringFromLUnicodeString
                          ((ulonglong *)&local_c8,(undefined4 *)local_98);
        uVar8 = (ulonglong)uVar3;
        if (-1 < (int)uVar3) {
          plVar9 = *param_2;
          local_d0 = 0;
          uVar3 = 0;
          local_108 = 0;
          local_e0 = 0;
          uStack_d8 = 0;
          plVar1 = plVar9 + (longlong)param_2[1];
          if (plVar9 != plVar1) {
            do {
              local_88[0] = 0x30;
              local_78 = local_98;
              local_140 = local_e8;
              local_88[1] = 0;
              local_158 = local_88;
              local_70 = (longlong *)0x40;
              plStack_68 = (longlong *)0x0;
              local_60 = 0;
              local_100 = (longlong *)((ulonglong)local_100 & 0xffffffffffffff00);
              plStack_f8 = (longlong *)0x0;
              local_f0 = 0;
              local_e8[0] = 0;
              local_148 = (int *)0x0;
              local_150 = (undefined8 *)((ulonglong)local_150 & 0xffffffff00000000);
              uVar4 = (**(code **)(**(longlong **)(*plVar9 + 0x60) + 0x60))
                                (*(longlong **)(*plVar9 + 0x60),5,&local_100,0x20019);
              if ((int)uVar4 < 0) {
LAB_14000374b:
                Windows::Rtl::SystemImplementation::CSilHandle::Close((CSilHandle *)&local_100);
                plVar1 = plStack_f8;
                if (plStack_f8 != (longlong *)0x0) {
                  plStack_f8 = (longlong *)0x0;
                  (**(code **)*plVar1)();
                }
                if (local_d0 != 0) {
                  RtlFreeLUnicodeString((longlong)&local_e0);
                  local_118 = 0;
                  local_e0 = 0;
                  uStack_d8 = 0;
                  local_d0 = 0;
                }
                if (local_b8 != 0) {
                  RtlFreeLUnicodeString((longlong)&local_c8);
                }
                return (ulonglong)uVar4;
              }
              if (local_e8[0] == 1) {
                local_148 = local_e8;
                local_150 = &local_e0;
                local_158 = (ulonglong *)CONCAT44(local_158._4_4_,2);
                uVar4 = (**(code **)(**(longlong **)(*plVar9 + 0x60) + 0x80))
                                  (*(longlong **)(*plVar9 + 0x60),1,local_f0,local_a8);
                if ((int)uVar4 < 0) goto LAB_14000374b;
                if (((local_e8[0] == 1) && (*(int *)(local_d0 + 4) == 4)) &&
                   (*(int *)(local_d0 + 8) == 4)) {
                  if (uVar3 < *(uint *)(local_d0 + 0xc)) {
                    local_108 = *plVar9;
                    uVar3 = *(uint *)(local_d0 + 0xc);
                  }
                }
              }
              Windows::Rtl::SystemImplementation::CSilHandle::Close((CSilHandle *)&local_100);
              plVar2 = plStack_f8;
              if (plStack_f8 != (longlong *)0x0) {
                plStack_f8 = (longlong *)0x0;
                (**(code **)*plVar2)();
              }
              plVar9 = plVar9 + 1;
            } while (plVar9 != plVar1);
            if (local_108 != 0) {
              local_100 = &local_108;
              plStack_f8 = (longlong *)0x1;
              param_2 = &local_100;
            }
          }
          uVar3 = SetMergedValue((longlong *)param_2,local_a8,param_4,param_5);
          uVar8 = (ulonglong)uVar3;
          if (-1 < (int)uVar3) {
            if (local_d0 != 0) {
              RtlFreeLUnicodeString((longlong)&local_e0);
              local_118 = 0;
              local_e0 = 0;
              uStack_d8 = 0;
              local_d0 = 0;
            }
            if (local_b8 != 0) {
              RtlFreeLUnicodeString((longlong)&local_c8);
            }
            return 0;
          }
          if (local_d0 != 0) {
            RtlFreeLUnicodeString((longlong)&local_e0);
            local_118 = 0;
            local_e0 = 0;
            uStack_d8 = 0;
            local_d0 = 0;
          }
        }
      }
      if (local_b8 != 0) {
        RtlFreeLUnicodeString((longlong)&local_c8);
      }
      return uVar8;
    }
    local_b8 = 0x1043;
    local_c8 = "OneCore\\Internal\\Base\\inc\\rtlstringutil.h";
    ppcVar6 = &local_c8;
    local_b0 = 0;
    pcStack_c0 = "Windows::StringUtil::Rtl::SubStringByByteCount";
  }
  RtlReportErrorOrigination(ppcVar6,puVar7,-0x7ffffffb);
  return 0x80000005;
}



===== RtlTrace @ 140003814 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl Windows::WCP::Rtl::RtlTrace(unsigned long,struct
   Windows::WCP::Rtl::_RTL_TRACING_FACILITY * __ptr64,char const * __ptr64 const,unsigned
   __int64,...) */

void __cdecl
Windows::WCP::Rtl::RtlTrace
          (ulong param_1,_RTL_TRACING_FACILITY *param_2,char *param_3,__uint64 param_4,...)

{
  return;
}



===== SetMergedValue @ 140003840 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint SetMergedValue(longlong *param_1,undefined8 param_2,undefined8 param_3,longlong *param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  uint uVar3;
  longlong *plVar4;
  bool bVar5;
  undefined1 auStack_f8 [32];
  undefined4 local_d8;
  undefined8 *local_d0;
  longlong local_c8;
  undefined4 local_c0;
  undefined8 local_b8;
  ulonglong local_a8;
  ulonglong local_a0;
  longlong local_98;
  undefined8 local_90;
  ulonglong *local_88;
  ulonglong local_80;
  longlong lStack_78;
  longlong local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  longlong local_58;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStack_f8;
  plVar4 = (longlong *)*param_1;
  local_70 = 0;
  plVar1 = plVar4 + param_1[1];
  bVar5 = false;
  local_80 = 0;
  lStack_78 = 0;
  local_90 = param_3;
  if (plVar4 != plVar1) {
    do {
      local_58 = 0;
      local_68 = 0;
      uStack_60 = 0;
      local_c8 = 0;
      plVar2 = *(longlong **)(*plVar4 + 0x60);
      local_d0 = &local_68;
      local_d8 = 2;
      uVar3 = (**(code **)(*plVar2 + 0x80))(plVar2,0,*(undefined8 *)(*plVar4 + 0x58));
      if ((int)uVar3 < 0) {
        if (local_58 != 0) {
          RtlFreeLUnicodeString((longlong)&local_68);
          local_98 = 0;
          local_68 = 0;
          uStack_60 = 0;
          local_58 = 0;
        }
        bVar5 = local_70 == 0;
LAB_140003b23:
        if (!bVar5) {
          RtlFreeLUnicodeString((longlong)&local_80);
        }
        return uVar3;
      }
      if ((*(int *)(local_58 + 4) == 7) && (1 < (ulonglong)param_1[1])) {
        local_88 = &local_80;
        bVar5 = true;
        local_a8 = (ulonglong)*(uint *)(local_58 + 8);
        local_98 = local_58 + 0xc;
        local_a0 = local_a8;
        uVar3 = Windows::StringUtil::Rtl::
                AppendString<_LUNICODE_STRING,Windows::AutoOperatorAmpersandHelper<_LUNICODE_STRING,Windows::Auto<_LUNICODE_STRING>_>,0>
                          (&local_a8,&local_88);
        if ((int)uVar3 < 0) {
          if (local_58 != 0) {
            RtlFreeLUnicodeString((longlong)&local_68);
            local_98 = 0;
            local_68 = 0;
            uStack_60 = 0;
            local_58 = 0;
          }
          bVar5 = local_70 == 0;
          goto LAB_140003b23;
        }
        local_80 = local_80 - 2;
      }
      else {
        local_c8 = local_58 + 0xc;
        local_c0 = *(undefined4 *)(local_58 + 8);
        local_b8 = 0;
        local_d0 = (undefined8 *)CONCAT44(local_d0._4_4_,*(int *)(local_58 + 4));
        local_d8 = 0;
        uVar3 = (**(code **)(*param_4 + 0xa0))(param_4,0,local_90,param_2);
        if ((int)uVar3 < 0) {
          if (local_58 != 0) {
            RtlFreeLUnicodeString((longlong)&local_68);
            local_98 = 0;
            local_68 = 0;
            uStack_60 = 0;
            local_58 = 0;
          }
          bVar5 = local_70 == 0;
          goto LAB_140003b23;
        }
      }
      if (local_58 != 0) {
        RtlFreeLUnicodeString((longlong)&local_68);
      }
      plVar4 = plVar4 + 1;
    } while (plVar4 != plVar1);
    if (!bVar5) goto LAB_140003a99;
    if (lStack_78 - local_80 < 2) {
      uVar3 = -(uint)(local_80 + 2 < local_80) & 0xc0000095;
      if ((((int)uVar3 < 0) && ((int)uVar3 < 0)) ||
         (uVar3 = RtlReallocateLUnicodeString(local_80,local_80 + 2,&local_80), (int)uVar3 < 0))
      goto LAB_1400039ef;
    }
    local_b8 = 0;
    *(undefined2 *)(local_70 + (local_80 & 0xfffffffffffffffe)) = 0;
    local_80 = local_80 + 2;
    local_c0 = (undefined4)local_80;
    local_c8 = local_70;
    local_d0 = (undefined8 *)CONCAT44(local_d0._4_4_,7);
    local_d8 = 0;
    uVar3 = (**(code **)(*param_4 + 0xa0))(param_4,0,local_90,param_2);
    if ((int)uVar3 < 0) {
LAB_1400039ef:
      if (local_70 != 0) {
        RtlFreeLUnicodeString((longlong)&local_80);
      }
      return uVar3;
    }
  }
LAB_140003a99:
  if (local_70 != 0) {
    RtlFreeLUnicodeString((longlong)&local_80);
  }
  return 0;
}



===== SwapOntoBack @ 140003b3c =====

/* public: class BUCL::Rtl::CCallDisposition __cdecl BUCL::CVector<class Windows::Auto<struct
   _LUNICODE_STRING>,class BUCL::Rtl::CCallDisposition>::SwapOntoBack(class Windows::Auto<struct
   _LUNICODE_STRING> * __ptr64,enum BUCL::GrowthPolicy) __ptr64 */

Auto<_LUNICODE_STRING> * __thiscall
BUCL::CVector<Windows::Auto<_LUNICODE_STRING>,BUCL::Rtl::CCallDisposition>::SwapOntoBack
          (CVector<Windows::Auto<_LUNICODE_STRING>,BUCL::Rtl::CCallDisposition> *this,
          Auto<_LUNICODE_STRING> *param_1,GrowthPolicy param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  uint uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  uint uVar10;
  undefined8 *puVar11;
  __uint64 *p_Var12;
  undefined4 in_register_00000084;
  undefined8 *puVar13;
  __uint64 *p_Var14;
  undefined1 in_R9B;
  longlong lVar15;
  __uint64 *p_Var16;
  uint local_res20 [2];
  
  puVar13 = (undefined8 *)CONCAT44(in_register_00000084,param_2);
  local_res20[0] = CONCAT31(local_res20[0]._1_3_,in_R9B);
  if (*(longlong *)(this + 8) != *(longlong *)(this + 0x10)) goto LAB_140003d07;
  lVar15 = *(longlong *)(this + 0x10) - *(longlong *)this >> 3;
  p_Var16 = (__uint64 *)(lVar15 * -0x5555555555555555);
  p_Var14 = p_Var16;
  if (p_Var16 != (__uint64 *)0xffffffffffffffff) {
    p_Var14 = (__uint64 *)((longlong)p_Var16 + 1);
  }
  uVar7 = 0xc0000095;
  uVar10 = 0xc0000095;
  if (p_Var16 != (__uint64 *)0xffffffffffffffff) {
    uVar10 = 0;
  }
  if (-1 < (int)uVar10) {
    if (p_Var16 < p_Var14) {
      p_Var12 = (__uint64 *)0x4;
      if ((__uint64 *)0x3 < p_Var16) {
        if (p_Var16 < (__uint64 *)0x21) {
          p_Var12 = (__uint64 *)(lVar15 * 0x5555555555555556);
        }
        else {
          p_Var12 = (__uint64 *)(((ulonglong)p_Var16 >> 1) + (longlong)p_Var16);
        }
        if (p_Var16 <= p_Var12) {
          uVar7 = 0;
        }
        if ((int)uVar7 < 0) goto LAB_140003cee;
      }
      if (p_Var12 < p_Var14) {
        p_Var12 = p_Var14;
      }
      if (p_Var12 < (__uint64 *)0xaaaaaaaaaaaaaaa) {
        if (p_Var16 < p_Var12) {
          Implementation::Multiply<BUCL::Rtl::CCallDisposition,unsigned___int64>
                    ((__uint64)local_res20,0x18,p_Var12);
          if (-1 < (int)local_res20[0]) {
            puVar8 = operator_new(0);
            if (puVar8 != (undefined8 *)0x0) {
              puVar11 = puVar8;
              for (puVar9 = *(undefined8 **)this; puVar2 = *(undefined8 **)(this + 8),
                  puVar9 != puVar2; puVar9 = puVar9 + 3) {
                if (puVar11 != (undefined8 *)0x0) {
                  uVar1 = puVar9[1];
                  *puVar11 = *puVar9;
                  puVar11[1] = uVar1;
                  puVar11[2] = puVar9[2];
                  *puVar9 = 0;
                  puVar9[1] = 0;
                  puVar9[2] = 0;
                }
                puVar11 = puVar11 + 3;
              }
              lVar15 = *(longlong *)this;
              Close(this);
              *(undefined8 **)this = puVar8;
              *(undefined8 **)(this + 8) = puVar8 + ((longlong)puVar2 - lVar15 >> 3);
              *(undefined8 **)(this + 0x10) = puVar8 + (longlong)p_Var12 * 3;
              goto LAB_140003ce0;
            }
            local_res20[0] = 0xc0000017;
          }
        }
        else {
LAB_140003ce0:
          local_res20[0] = 0;
        }
        uVar7 = -(uint)((int)local_res20[0] < 0) & local_res20[0];
      }
      else {
        uVar7 = 0xc0000017;
      }
    }
    else {
      uVar7 = 0;
    }
LAB_140003cee:
    uVar10 = -(uint)((int)uVar7 < 0) & uVar7;
  }
  if ((int)uVar10 < 0) {
    *(uint *)param_1 = uVar10;
    return param_1;
  }
LAB_140003d07:
  puVar8 = *(undefined8 **)(this + 8);
  if (puVar8 != (undefined8 *)0x0) {
    *puVar8 = 0;
    puVar8[1] = 0;
    puVar8[2] = 0;
  }
  puVar8 = *(undefined8 **)(this + 8);
  uVar3 = *puVar13;
  uVar4 = puVar13[1];
  *(undefined4 *)param_1 = 0;
  uVar5 = *puVar8;
  uVar6 = puVar8[1];
  uVar1 = puVar8[2];
  *puVar8 = uVar3;
  puVar8[1] = uVar4;
  puVar8[2] = puVar13[2];
  *puVar13 = uVar5;
  puVar13[1] = uVar6;
  puVar13[2] = uVar1;
  *(longlong *)(this + 8) = *(longlong *)(this + 8) + 0x18;
  return param_1;
}



===== Enumerate<utl::vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_>&___ptr64> @ 140003d70 =====

/* auto __cdecl TMeta::Enumerate<class utl::vector<struct Compositefs::Layer,class
   utl::allocator<struct Compositefs::Layer> > & __ptr64>(class utl::vector<struct
   Compositefs::Layer,class utl::allocator<struct Compositefs::Layer> > & __ptr64,unsigned __int64)
    */

vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_> * __cdecl
TMeta::Enumerate<utl::vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_>&___ptr64>
          (vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_> *param_1,__uint64 param_2)

{
  *(undefined8 *)(param_1 + 8) = 0;
  *(__uint64 *)param_1 = param_2;
  return param_1;
}



===== MakeVector<Compositefs::Layer> @ 140003d84 =====

/* struct Windows::Vector<struct Compositefs::Layer> __cdecl Windows::MakeVector<struct
   Compositefs::Layer>(struct Compositefs::Layer * __ptr64,unsigned __int64) */

Layer * __cdecl Windows::MakeVector<Compositefs::Layer>(Layer *param_1,__uint64 param_2)

{
  undefined8 in_R8;
  
  *(__uint64 *)param_1 = param_2;
  *(undefined8 *)(param_1 + 8) = in_R8;
  return param_1;
}



===== _RangeFillApc<utl::allocator<Compositefs::Layer>_> @ 140003d98 =====

/* bool __cdecl utl::_RangeFillApc<class utl::allocator<struct Compositefs::Layer> >(struct
   utl::integral_constant<bool,0>,class utl::allocator<struct Compositefs::Layer> & __ptr64,struct
   Compositefs::Layer * __ptr64,unsigned __int64) */

bool __cdecl
utl::_RangeFillApc<utl::allocator<Compositefs::Layer>_>
          (undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4)

{
  undefined8 *puVar1;
  
  if (param_4 != 0) {
    puVar1 = (undefined8 *)(param_3 + 0x18);
    do {
      puVar1[-3] = 0;
      puVar1[-2] = 0;
      puVar1[-1] = 0;
      *puVar1 = 0;
      puVar1[1] = 0;
      *(undefined1 *)(puVar1 + 2) = 0;
      *(undefined4 *)((longlong)puVar1 + 0x11) = 0;
      *(undefined2 *)((longlong)puVar1 + 0x15) = 0;
      *(undefined1 *)((longlong)puVar1 + 0x17) = 0;
      puVar1[3] = 0;
      puVar1 = puVar1 + 7;
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return true;
}



===== make_shared<utl::vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_>,utl::vector<struct_Compositefs::Layer,class_utl::allocator<struct_Compositefs::Layer>_>_> @ 140003de0 =====

/* class utl::shared_ptr<class utl::vector<struct Compositefs::Layer,class utl::allocator<struct
   Compositefs::Layer> > > __cdecl utl::make_shared<class utl::vector<struct
   Compositefs::Layer,class utl::allocator<struct Compositefs::Layer> >,class utl::vector<struct
   Compositefs::Layer,class utl::allocator<struct Compositefs::Layer> > >(class utl::vector<struct
   Compositefs::Layer,class utl::allocator<struct Compositefs::Layer> > && __ptr64) */

vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_> * __cdecl
utl::
make_shared<utl::vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_>,utl::vector<struct_Compositefs::Layer,class_utl::allocator<struct_Compositefs::Layer>_>_>
          (vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_> *param_1)

{
  undefined8 *puVar1;
  nothrow_t *in_RDX;
  
  *(undefined8 *)param_1 = 0;
  *(undefined8 *)(param_1 + 8) = 0;
  puVar1 = operator_new(0x28,in_RDX);
  if (puVar1 != (undefined8 *)0x0) {
    *(undefined4 *)(puVar1 + 1) = 1;
    *(undefined4 *)((longlong)puVar1 + 0xc) = 1;
    *puVar1 = &_RefCountVtable<utl::_RefCountStored<utl::vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_>,utl::allocator<int>,0>,0>
               ::_vftable_;
    puVar1[2] = *(undefined8 *)in_RDX;
    puVar1[3] = *(undefined8 *)(in_RDX + 8);
    puVar1[4] = *(undefined8 *)(in_RDX + 0x10);
    *(undefined8 *)in_RDX = 0xffffffffffffffff;
    *(undefined8 *)(in_RDX + 8) = 0xffffffffffffffff;
    *(undefined8 *)(in_RDX + 0x10) = 0xffffffffffffffff;
    *(undefined8 **)param_1 = puVar1 + 2;
    *(undefined8 **)(param_1 + 8) = puVar1;
  }
  return param_1;
}



===== operator= @ 140003e68 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: struct _PARTITION_INFORMATION_EX __cdecl utl::atomic<struct
   _PARTITION_INFORMATION_EX>::operator=(struct _PARTITION_INFORMATION_EX) __ptr64 */

undefined8 * __thiscall
utl::atomic<_PARTITION_INFORMATION_EX>::operator=
          (undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint uVar5;
  bool bVar6;
  
  uVar5 = 0;
  while( true ) {
    LOCK();
    bVar6 = DAT_140017230 == '\0';
    if (bVar6) {
      DAT_140017230 = '\x01';
    }
    UNLOCK();
    if (bVar6) break;
    if (0x1f < uVar5) {
      NtYieldExecution();
    }
    uVar5 = uVar5 + 1;
  }
  _g_PartitionInformation = *param_3;
  uRam00000001400171a8 = param_3[1];
  _DAT_1400171b0 = param_3[2];
  uRam00000001400171b8 = param_3[3];
  _DAT_1400171c0 = param_3[4];
  uRam00000001400171c8 = param_3[5];
  _DAT_1400171d0 = param_3[6];
  uRam00000001400171d8 = param_3[7];
  _DAT_1400171e0 = param_3[8];
  uRam00000001400171e8 = param_3[9];
  _DAT_1400171f0 = param_3[10];
  uRam00000001400171f8 = param_3[0xb];
  _DAT_140017200 = param_3[0xc];
  uRam0000000140017208 = param_3[0xd];
  _DAT_140017220 = param_3[0x10];
  uRam0000000140017228 = param_3[0x11];
  _DAT_140017210 = param_3[0xe];
  uRam0000000140017218 = param_3[0xf];
  uVar1 = param_3[1];
  DAT_140017230 = 0;
  uVar2 = param_3[2];
  uVar3 = param_3[3];
  *param_2 = *param_3;
  param_2[1] = uVar1;
  uVar1 = param_3[4];
  uVar4 = param_3[5];
  param_2[2] = uVar2;
  param_2[3] = uVar3;
  uVar2 = param_3[6];
  uVar3 = param_3[7];
  param_2[4] = uVar1;
  param_2[5] = uVar4;
  uVar1 = param_3[8];
  uVar4 = param_3[9];
  param_2[6] = uVar2;
  param_2[7] = uVar3;
  uVar2 = param_3[10];
  uVar3 = param_3[0xb];
  param_2[8] = uVar1;
  param_2[9] = uVar4;
  uVar1 = param_3[0xc];
  uVar4 = param_3[0xd];
  param_2[10] = uVar2;
  param_2[0xb] = uVar3;
  uVar2 = param_3[0xe];
  uVar3 = param_3[0xf];
  param_2[0xc] = uVar1;
  param_2[0xd] = uVar4;
  uVar1 = param_3[0x10];
  uVar4 = param_3[0x11];
  param_2[0xe] = uVar2;
  param_2[0xf] = uVar3;
  param_2[0x10] = uVar1;
  param_2[0x11] = uVar4;
  return param_2;
}



===== _CallDeleter @ 140003f70 =====

/* public: virtual void __cdecl utl::_RefCountVtable<class utl::_RefCountStored<class
   utl::vector<struct Compositefs::Layer,class utl::allocator<struct Compositefs::Layer> >,class
   utl::allocator<int>,0>,0>::_CallDeleter(void) __ptr64 */

void __thiscall
utl::
_RefCountVtable<utl::_RefCountStored<utl::vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_>,utl::allocator<int>,0>,0>
::_CallDeleter(_RefCountVtable<utl::_RefCountStored<utl::vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_>,utl::allocator<int>,0>,0>
               *this)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(this + 0x10);
  if ((lVar1 != -1) && (*(longlong *)(this + 0x18) = lVar1, lVar1 != 0)) {
    ExFreePoolWithTag(lVar1,0);
  }
  return;
}



===== _DecStrong @ 140003fa4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl utl::_RefCountBase::_DecStrong(void) __ptr64 */

void __thiscall utl::_RefCountBase::_DecStrong(_RefCountBase *this)

{
  _RefCountBase *p_Var1;
  int iVar2;
  
  if (*(longlong *)(this + 8) == 0x100000001) {
    (*(code *)**(undefined8 **)this)(this);
  }
  else {
    LOCK();
    p_Var1 = this + 8;
    iVar2 = *(int *)p_Var1;
    *(int *)p_Var1 = *(int *)p_Var1 + -1;
    UNLOCK();
    if (iVar2 != 1) {
      return;
    }
    (*(code *)**(undefined8 **)this)(this);
    if (*(int *)(this + 0xc) != 1) {
      LOCK();
      p_Var1 = this + 0xc;
      iVar2 = *(int *)p_Var1;
      *(int *)p_Var1 = *(int *)p_Var1 + -1;
      UNLOCK();
      if (iVar2 != 1) {
        return;
      }
    }
  }
  (**(code **)(*(longlong *)this + 8))(this);
  return;
}



===== _FreeRefCount @ 140004030 =====

/* public: virtual void __cdecl utl::_RefCountVtable<class utl::_RefCountStored<class
   utl::vector<struct Compositefs::Layer,class utl::allocator<struct Compositefs::Layer> >,class
   utl::allocator<int>,0>,0>::_FreeRefCount(void) __ptr64 */

void __cdecl
utl::
_RefCountVtable<utl::_RefCountStored<utl::vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_>,utl::allocator<int>,0>,0>
::_FreeRefCount(void)

{
  longlong in_RCX;
  
  if (in_RCX != 0) {
    ExFreePoolWithTag(in_RCX,0);
  }
  return;
}



===== _GrowMinimum @ 140004054 =====

/* private: bool __cdecl utl::vector<struct Compositefs::Layer,class utl::allocator<struct
   Compositefs::Layer> >::_GrowMinimum(unsigned __int64) __ptr64 */

bool __thiscall
utl::vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_>::_GrowMinimum
          (vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_> *this,__uint64 param_1)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  void *_Dst;
  bool bVar4;
  
  uVar3 = ((ulonglong)((*(longlong *)(this + 0x10) - *(longlong *)this >> 3) * 0x6db6db6db6db6db7)
          >> 2) * 7 + 8;
  if (uVar3 < param_1) {
    uVar3 = param_1;
  }
  if (0x249249249249249 < uVar3) {
    uVar3 = 0x249249249249249;
  }
  bVar4 = false;
  if ((param_1 <= uVar3) && (uVar3 < 0x492492492492493)) {
    _Dst = operator_new(uVar3 * 0x38,(nothrow_t *)param_1);
    if ((_Dst != (void *)0x0) && (_Dst != (void *)0xffffffffffffffff)) {
      memmove(_Dst,*(void **)this,(*(longlong *)(this + 8) - (longlong)*(void **)this >> 3) * 8);
      lVar1 = *(longlong *)this;
      lVar2 = *(longlong *)(this + 8);
      if ((lVar1 != -1) && (*(longlong *)(this + 8) = lVar1, lVar1 != 0)) {
        ExFreePoolWithTag(lVar1,0);
      }
      *(void **)this = _Dst;
      bVar4 = true;
      *(void **)(this + 8) = (void *)((lVar2 - lVar1 >> 3) * 8 + (longlong)_Dst);
      *(void **)(this + 0x10) = (void *)(uVar3 * 0x38 + (longlong)_Dst);
    }
  }
  return bVar4;
}



===== load @ 14000416c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: class utl::shared_ptr<class utl::vector<struct Compositefs::Layer,class
   utl::allocator<struct Compositefs::Layer> > > __cdecl utl::atomic<class utl::shared_ptr<class
   utl::vector<struct Compositefs::Layer,class utl::allocator<struct Compositefs::Layer> > >
   >::load(enum utl::memory_order)const __ptr64 */

undefined8 * __thiscall
utl::atomic<utl::shared_ptr<utl::vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_>_>_>
::load(atomic<utl::shared_ptr<utl::vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_>_>_>
       *this,memory_order param_1)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  undefined4 in_register_00000014;
  uint uVar3;
  bool bVar4;
  
  puVar1 = (undefined8 *)CONCAT44(in_register_00000014,param_1);
  uVar3 = 0;
  uVar2 = DAT_140017270;
  do {
    LOCK();
    bVar4 = uVar2 == DAT_140017270;
    if (bVar4) {
      DAT_140017270 = uVar2 | 1;
    }
    else {
      uVar2 = DAT_140017270;
    }
    UNLOCK();
  } while (!bVar4);
  while ((uVar2 & 7) != 0) {
    if (0x1f < uVar3) {
      NtYieldExecution();
    }
    uVar3 = uVar3 + 1;
    uVar2 = DAT_140017270;
    do {
      LOCK();
      bVar4 = uVar2 == DAT_140017270;
      if (bVar4) {
        DAT_140017270 = uVar2 | 1;
      }
      else {
        uVar2 = DAT_140017270;
      }
      UNLOCK();
    } while (!bVar4);
  }
  *puVar1 = 0;
  puVar1[1] = uVar2;
  *puVar1 = _g_CompositeFsLayers;
  if (uVar2 != 0) {
    LOCK();
    *(int *)(uVar2 + 8) = *(int *)(uVar2 + 8) + 1;
    UNLOCK();
  }
  DAT_140017270 = uVar2;
  return puVar1;
}



===== _tlgDefineProvider_annotation__Tlgg_TraceLoggingProviderProv @ 140004210 =====

void _tlgDefineProvider_annotation__Tlgg_TraceLoggingProviderProv(void)

{
  return;
}



===== EmplaceBack<gsl::span<wchar_t,-1>_> @ 14000421c =====

/* public: class BUCL::Rtl::CCallDisposition __cdecl BUCL::CVector<class gsl::span<wchar_t const
   ,-1>,class BUCL::Rtl::CCallDisposition>::EmplaceBack<class gsl::span<wchar_t,-1> >(class
   gsl::span<wchar_t,-1> && __ptr64) __ptr64 */

span<wchar_t,_1> * __thiscall
BUCL::CVector<gsl::span<wchar_t_const_,-1>,BUCL::Rtl::CCallDisposition>::
EmplaceBack<gsl::span<wchar_t,_1>_>
          (CVector<gsl::span<wchar_t_const_,_1>,BUCL::Rtl::CCallDisposition> *this,
          span<wchar_t,_1> *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  uint uVar7;
  undefined8 *puVar8;
  __uint64 *p_Var9;
  undefined8 *puVar10;
  __uint64 *p_Var11;
  ulonglong uVar12;
  longlong *in_R8;
  __uint64 *p_Var13;
  uint local_res8 [2];
  
  if (*(longlong *)(this + 8) == *(longlong *)(this + 0x10)) {
    p_Var13 = (__uint64 *)(*(longlong *)(this + 0x10) - *(longlong *)this >> 4);
    p_Var9 = p_Var13;
    if (p_Var13 != (__uint64 *)0xffffffffffffffff) {
      p_Var9 = (__uint64 *)((longlong)p_Var13 + 1);
    }
    uVar7 = 0xc0000095;
    if (p_Var13 != (__uint64 *)0xffffffffffffffff) {
      uVar7 = 0;
    }
    if (-1 < (int)uVar7) {
      if (p_Var13 < p_Var9) {
        p_Var11 = (__uint64 *)0x4;
        if ((__uint64 *)0x3 < p_Var13) {
          if (p_Var13 < (__uint64 *)0x21) {
            p_Var11 = (__uint64 *)((longlong)p_Var13 * 2);
          }
          else {
            p_Var11 = (__uint64 *)(((ulonglong)p_Var13 >> 1) + (longlong)p_Var13);
          }
          uVar7 = -(uint)(p_Var11 < p_Var13) & 0xc0000095;
          if ((int)uVar7 < 0) goto LAB_1400043a5;
        }
        if (p_Var11 < p_Var9) {
          p_Var11 = p_Var9;
        }
        if (p_Var11 < (__uint64 *)0xfffffffffffffff) {
          if (p_Var13 < p_Var11) {
            Implementation::Multiply<BUCL::Rtl::CCallDisposition,unsigned___int64>
                      ((__uint64)local_res8,0x10,p_Var11);
            if (-1 < (int)local_res8[0]) {
              puVar5 = operator_new(0);
              if (puVar5 != (undefined8 *)0x0) {
                puVar10 = puVar5;
                for (puVar8 = *(undefined8 **)this; puVar6 = *(undefined8 **)(this + 8),
                    puVar8 != puVar6; puVar8 = puVar8 + 2) {
                  if (puVar10 != (undefined8 *)0x0) {
                    uVar4 = puVar8[1];
                    *puVar10 = *puVar8;
                    puVar10[1] = uVar4;
                  }
                  puVar10 = puVar10 + 2;
                }
                puVar8 = *(undefined8 **)this;
                uVar12 = (longlong)puVar6 - (longlong)puVar8;
                if (puVar8 != puVar6) {
                  do {
                    puVar6 = puVar6 + -2;
                  } while (puVar6 != puVar8);
                  *(undefined8 **)(this + 8) = puVar6;
                }
                if (puVar8 != (undefined8 *)0x0) {
                  ExFreePoolWithTag(puVar8,0);
                }
                *(undefined8 **)this = puVar5;
                *(ulonglong *)(this + 8) = (uVar12 & 0xfffffffffffffff0) + (longlong)puVar5;
                *(undefined8 **)(this + 0x10) = puVar5 + (longlong)p_Var11 * 2;
                goto LAB_140004397;
              }
              local_res8[0] = 0xc0000017;
            }
          }
          else {
LAB_140004397:
            local_res8[0] = 0;
          }
          uVar7 = -(uint)((int)local_res8[0] < 0) & local_res8[0];
        }
        else {
          uVar7 = 0xc0000017;
        }
      }
      else {
        uVar7 = 0;
      }
LAB_1400043a5:
      uVar7 = -(uint)((int)uVar7 < 0) & uVar7;
    }
    if ((int)uVar7 < 0) {
      *(uint *)param_1 = uVar7;
      return param_1;
    }
  }
  plVar1 = *(longlong **)(this + 8);
  if (plVar1 == (longlong *)0x0) {
LAB_1400043e5:
    *(longlong *)(this + 8) = *(longlong *)(this + 8) + 0x10;
    *(undefined4 *)param_1 = 0;
    return param_1;
  }
  lVar2 = *in_R8;
  if (lVar2 != -1) {
    lVar3 = in_R8[1];
    *plVar1 = lVar2;
    plVar1[1] = lVar3;
    if ((lVar3 != 0) || (lVar2 == 0)) goto LAB_1400043e5;
  }
                    /* WARNING: Subroutine does not return */
  gsl::details::terminate();
}



===== _RangeDestroyApc<utl::allocator<CimFs::MappedRegionKernel>_> @ 140004414 =====

/* void __cdecl utl::_RangeDestroyApc<class utl::allocator<struct CimFs::MappedRegionKernel> >(class
   utl::allocator<struct CimFs::MappedRegionKernel> & __ptr64,struct CimFs::MappedRegionKernel *
   __ptr64,unsigned __int64) */

void __cdecl
utl::_RangeDestroyApc<utl::allocator<CimFs::MappedRegionKernel>_>
          (allocator<CimFs::MappedRegionKernel> *param_1,MappedRegionKernel *param_2,
          __uint64 param_3)

{
  BlockLocationMapper *this;
  MappedRegionKernel *pMVar1;
  
  if (param_3 != 0) {
    pMVar1 = param_2 + param_3 * 0x90;
    do {
      param_3 = param_3 - 1;
      this = *(BlockLocationMapper **)(pMVar1 + -0x88);
      if (this != (BlockLocationMapper *)0x0) {
        Cim::BlockLocationMapper::~BlockLocationMapper(this);
        ExFreePoolWithTag(this,0);
      }
      if (*(longlong *)(pMVar1 + -0x90) != 0) {
        ZwClose();
      }
      pMVar1 = pMVar1 + -0x90;
    } while (param_3 != 0);
  }
  return;
}



===== copy<gsl::byte_const_,-1,gsl::byte,-1> @ 140004494 =====

/* void __cdecl gsl::copy<enum gsl::byte const ,-1,enum gsl::byte,-1>(class gsl::span<enum gsl::byte
   const ,-1>,class gsl::span<enum gsl::byte,-1>) */

void __cdecl gsl::copy<gsl::byte_const_,_1,gsl::byte,_1>(ulonglong *param_1,ulonglong *param_2)

{
  ulonglong uVar1;
  size_t _Size;
  ulonglong uVar2;
  void *_Dst;
  
  uVar1 = *param_1;
  if (uVar1 <= *param_2) {
    _Size = *param_1;
    if ((_Size != 0xffffffffffffffff) && (((void *)param_1[1] != (void *)0x0 || (_Size == 0)))) {
      uVar2 = *param_2;
      _Dst = (void *)param_2[1];
      if ((uVar2 != 0xffffffffffffffff) &&
         ((((_Dst != (void *)0x0 || (uVar2 == 0)) && (uVar1 <= uVar2)) &&
          ((uVar1 != 0xffffffffffffffff && ((_Dst != (void *)0x0 || (uVar1 == 0)))))))) {
        memmove(_Dst,(void *)param_1[1],_Size);
        return;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  details::terminate();
}



===== ~CVector<gsl::byte,BUCL::Rtl::CCallDisposition> @ 140004514 =====

/* public: __cdecl BUCL::CVector<enum gsl::byte,class BUCL::Rtl::CCallDisposition>::~CVector<enum
   gsl::byte,class BUCL::Rtl::CCallDisposition>(void) __ptr64 */

void __thiscall
BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>::
~CVector<gsl::byte,BUCL::Rtl::CCallDisposition>
          (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *this)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)this;
  lVar2 = *(longlong *)(this + 8);
  if (lVar1 != lVar2) {
    do {
      lVar2 = lVar2 + -1;
    } while (lVar2 != lVar1);
    *(longlong *)(this + 8) = lVar2;
  }
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0);
  }
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)this = 0;
  return;
}



===== ~vector<CimFs::MappedRegionKernel,utl::allocator<CimFs::MappedRegionKernel>_> @ 140004564 =====

/* public: __cdecl utl::vector<struct CimFs::MappedRegionKernel,class utl::allocator<struct
   CimFs::MappedRegionKernel> >::~vector<struct CimFs::MappedRegionKernel,class
   utl::allocator<struct CimFs::MappedRegionKernel> >(void) __ptr64 */

void __thiscall
utl::vector<CimFs::MappedRegionKernel,utl::allocator<CimFs::MappedRegionKernel>_>::
~vector<CimFs::MappedRegionKernel,utl::allocator<CimFs::MappedRegionKernel>_>
          (vector<CimFs::MappedRegionKernel,utl::allocator<CimFs::MappedRegionKernel>_> *this)

{
  allocator<CimFs::MappedRegionKernel> *paVar1;
  longlong lVar2;
  
  paVar1 = *(allocator<CimFs::MappedRegionKernel> **)this;
  if (paVar1 != (allocator<CimFs::MappedRegionKernel> *)0xffffffffffffffff) {
    lVar2 = *(longlong *)(this + 8);
    *(allocator<CimFs::MappedRegionKernel> **)(this + 8) = paVar1;
    _RangeDestroyApc<utl::allocator<CimFs::MappedRegionKernel>_>
              (paVar1,(MappedRegionKernel *)paVar1,(lVar2 - (longlong)paVar1) / 0x90);
    if (*(longlong *)this != 0) {
      ExFreePoolWithTag(*(longlong *)this,0);
    }
  }
  return;
}



===== AreSameVolume @ 1400045c8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl AreSameVolume(struct _UNICODE_STRING,struct _UNICODE_STRING,bool * __ptr64) */

long __cdecl AreSameVolume(undefined8 param_1,undefined8 param_2,undefined1 *param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_4f8 [32];
  undefined4 local_4d8;
  undefined4 local_4d0;
  char *local_4c8;
  char *pcStack_4c0;
  undefined8 local_4b8;
  char *pcStack_4b0;
  undefined8 local_498;
  undefined8 uStack_490;
  undefined8 local_488;
  undefined8 uStack_480;
  undefined8 local_478;
  undefined8 uStack_470;
  longlong local_468;
  longlong local_460 [3];
  uint local_448;
  undefined1 local_444 [524];
  uint local_238;
  undefined1 local_234 [524];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_4f8;
  uStack_490 = 0;
  local_468 = 0;
  *param_3 = 0;
  local_4d0 = 0x20;
  uVar2 = 0x80;
  local_498 = 0x30;
  uStack_480 = 0x240;
  local_478 = 0;
  uStack_470 = 0;
  local_4d8 = 7;
  local_460[1] = 0;
  local_460[2] = 0;
  local_488 = param_1;
  iVar1 = ZwOpenFile(&local_468,0x80,&local_498,local_460 + 1);
  if (iVar1 == -0x3fffffc6) goto LAB_14000484e;
  if (iVar1 < 0) {
    local_4b8 = 0x276;
    local_4c8 = "onecore\\base\\servicing\\globmerger\\kernel\\cimloader.cpp";
    pcStack_4c0 = "AreSameVolume";
    pcStack_4b0 = 
    "ZwOpenFile( &Handle1, ( 0x0080 ), &Attr, &IoStatus, 0x00000001 | 0x00000002 | 0x00000004, 0x00000020)"
    ;
    RtlReportErrorOrigination(&local_4c8,uVar2,iVar1);
    goto LAB_1400046a1;
  }
  pcStack_4c0 = (char *)0x0;
  local_460[0] = 0;
  local_4c8 = (char *)0x30;
  pcStack_4b0 = (char *)0x240;
  uVar2 = 0x80;
  local_4d0 = 0x20;
  local_498 = 0x30;
  uStack_490 = 0;
  local_4d8 = 7;
  uStack_480 = 0x240;
  local_478 = 0;
  uStack_470 = 0;
  local_4b8 = param_2;
  local_488 = param_2;
  iVar1 = ZwOpenFile(local_460,0x80,&local_498,local_460 + 1);
  if (iVar1 == -0x3fffffc6) {
LAB_14000483d:
    if (local_460[0] != 0) {
      ZwClose();
    }
LAB_14000484e:
    if (local_468 != 0) {
      ZwClose();
    }
    return 0;
  }
  if (iVar1 < 0) {
    local_4b8 = 0x28a;
    local_4c8 = "onecore\\base\\servicing\\globmerger\\kernel\\cimloader.cpp";
    pcStack_4c0 = "AreSameVolume";
    pcStack_4b0 = 
    "ZwOpenFile( &Handle2, ( 0x0080 ), &Attr, &IoStatus, 0x00000001 | 0x00000002 | 0x00000004, 0x00000020)"
    ;
    RtlReportErrorOrigination(&local_4c8,uVar2,iVar1);
  }
  else {
    memset(&local_238,0,0x208);
    memset(&local_448,0,0x208);
    local_4d8 = 0x3a;
    iVar1 = NtQueryInformationFile(local_468,local_460 + 1,&local_238,0x208);
    if (-1 < iVar1) {
      local_4d8 = 0x3a;
      iVar1 = NtQueryInformationFile(local_460[0],local_460 + 1,&local_448,0x208);
      if (-1 < iVar1) {
        if ((local_238 == local_448) &&
           (iVar1 = memcmp(local_234,local_444,(ulonglong)local_238), iVar1 == 0)) {
          *param_3 = 1;
        }
        goto LAB_14000483d;
      }
    }
  }
  if (local_460[0] != 0) {
    ZwClose();
  }
LAB_1400046a1:
  if (local_468 != 0) {
    ZwClose();
  }
  return iVar1;
}



===== CompareDiskInfo @ 140004890 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140004c81) */
/* long __cdecl CompareDiskInfo(struct _UNICODE_STRING,struct _GUID,unsigned long,struct
   _PARTITION_INFORMATION_EX const & __ptr64,bool * __ptr64) */

long __cdecl
CompareDiskInfo(undefined8 param_1,longlong *param_2,int param_3,int *param_4,undefined1 *param_5)

{
  int iVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  int *piVar4;
  uint uVar5;
  undefined1 auStack_188 [32];
  longlong *local_168;
  undefined4 local_160;
  undefined8 local_158;
  undefined4 local_150;
  int *local_148;
  uint local_140;
  char *local_138;
  char *local_130;
  undefined8 local_128;
  char *local_120;
  undefined1 *local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  longlong local_e0 [3];
  int local_c8 [2];
  longlong local_c0;
  longlong local_98;
  longlong local_90;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_188;
  local_160 = 0x20;
  local_118 = param_5;
  *param_5 = 0;
  local_110 = 0x30;
  local_108 = 0;
  uVar2 = 0x80;
  local_f8 = 0x240;
  local_e0[0] = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  local_168 = (longlong *)CONCAT44(local_168._4_4_,7);
  local_e0[1] = 0;
  local_e0[2] = 0;
  local_100 = param_1;
  iVar1 = ZwOpenFile(local_e0,0x80,&local_110,local_e0 + 1);
  if (iVar1 < 0) {
    local_128 = 0x202;
    local_138 = "onecore\\base\\servicing\\globmerger\\kernel\\cimloader.cpp";
    local_120 = 
    "ZwOpenFile( &Handle, ( 0x0080 ), &Attr, &IoStatus, 0x00000001 | 0x00000002 | 0x00000004, 0x00000020)"
    ;
    local_130 = "CompareDiskInfo";
    RtlReportErrorOrigination(&local_138,uVar2,iVar1);
LAB_140004974:
    if (local_e0[0] != 0) {
      ZwClose();
    }
    return iVar1;
  }
  piVar4 = (int *)0x0;
  uVar5 = 0x1000;
  while( true ) {
    if (piVar4 != (int *)0x0) {
      ExFreePoolWithTag(piVar4,0);
    }
    uVar3 = (ulonglong)uVar5;
    if (uVar5 == 0) {
      uVar3 = 1;
    }
    piVar4 = (int *)ExAllocatePool2(0x40,uVar3,0x4c467346);
    if (piVar4 == (int *)0x0) {
      local_128 = 0x20a;
      local_138 = "onecore\\base\\servicing\\globmerger\\kernel\\cimloader.cpp";
      local_120 = "Info.AllocateWithTotalSize(DriveLayoutSize)";
      local_130 = "CompareDiskInfo";
      RtlReportErrorOrigination(&local_138,uVar3,-0x3fffffe9);
      if (local_e0[0] != 0) {
        ZwClose();
      }
      return -0x3fffffe9;
    }
    uVar2 = 0;
    local_150 = 0;
    local_168 = local_e0 + 1;
    local_158 = 0;
    local_160 = 0x70050;
    local_148 = piVar4;
    local_140 = uVar5;
    iVar1 = ZwDeviceIoControlFile(local_e0[0],0,0,0);
    if (iVar1 != -0x3fffffdd) break;
    uVar5 = uVar5 * 2;
  }
  if (iVar1 < 0) {
    local_128 = 0x219;
    local_138 = "onecore\\base\\servicing\\globmerger\\kernel\\cimloader.cpp";
    local_120 = 
    "ZwDeviceIoControlFile( Handle.get(), nullptr, nullptr, nullptr, &IoStatus, ( ((0x00000007) << 16) | ((0) << 14) | ((0x0014) << 2) | (0) ), nullptr, 0, Info, DriveLayoutSize)"
    ;
    local_130 = "CompareDiskInfo";
    RtlReportErrorOrigination(&local_138,uVar2,iVar1);
    ExFreePoolWithTag(piVar4,0);
    if (local_e0[0] != 0) {
      ZwClose();
    }
    return iVar1;
  }
  iVar1 = *piVar4;
  if (iVar1 != *param_4) goto LAB_140004b90;
  if (iVar1 == 0) {
    if (piVar4[2] != param_3) goto LAB_140004b90;
  }
  else if (((iVar1 != 1) || (*(longlong *)(piVar4 + 2) != *param_2)) ||
          (*(longlong *)(piVar4 + 4) != param_2[1])) goto LAB_140004b90;
  memset(local_c8,0,0x90);
  local_148 = local_c8;
  local_140 = 0x90;
  local_150 = 0;
  local_168 = local_e0 + 1;
  local_158 = 0;
  uVar2 = 0;
  local_160 = 0x70048;
  iVar1 = ZwDeviceIoControlFile(local_e0[0],0,0,0);
  if (iVar1 < 0) {
    local_128 = 0x246;
    local_138 = "onecore\\base\\servicing\\globmerger\\kernel\\cimloader.cpp";
    local_120 = 
    "ZwDeviceIoControlFile( Handle.get(), nullptr, nullptr, nullptr, &IoStatus, ( ((0x00000007) << 16) | ((0) << 14) | ((0x0012) << 2) | (0) ), nullptr, 0, &VolumePartitionInformation, sizeof(PARTITION_INFORMATION_EX))"
    ;
    local_130 = "CompareDiskInfo";
    RtlReportErrorOrigination(&local_138,uVar2,iVar1);
    ExFreePoolWithTag(piVar4,0);
    goto LAB_140004974;
  }
  if (*param_4 == 0) {
    if (*(longlong *)(param_4 + 2) != local_c0) goto LAB_140004b90;
  }
  else if (((*param_4 != 1) || (*(longlong *)(param_4 + 0xc) != local_98)) ||
          (*(longlong *)(param_4 + 0xe) != local_90)) goto LAB_140004b90;
  *local_118 = 1;
LAB_140004b90:
  ExFreePoolWithTag(piVar4,0);
  if (local_e0[0] != 0) {
    ZwClose();
  }
  return 0;
}



===== DismountCim @ 140004c9c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl DismountCim(struct _UNICODE_STRING const & __ptr64) */

long __cdecl DismountCim(_UNICODE_STRING *param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_e8 [32];
  undefined8 *local_c8;
  undefined4 local_c0;
  ulonglong local_b8;
  undefined4 local_b0;
  undefined8 local_a8;
  ulonglong local_a0;
  undefined4 local_98;
  undefined4 local_90;
  undefined8 local_88;
  undefined4 local_80;
  char *local_78;
  char *local_70;
  undefined8 local_68;
  char *local_60;
  undefined8 local_58;
  undefined8 local_50;
  _UNICODE_STRING *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  longlong local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_e8;
  local_80 = 0x100;
  local_88 = 0;
  local_90 = 0;
  local_98 = 0;
  local_a0 = 0;
  uVar2 = 0x100100;
  local_a8 = CONCAT44(local_a8._4_4_,0x48);
  local_b0 = 1;
  local_b8 = local_b8 & 0xffffffff00000000;
  local_c0 = 0;
  local_c8 = (undefined8 *)0x0;
  local_58 = 0x30;
  local_50 = 0;
  local_40 = 0x240;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  local_48 = param_1;
  iVar1 = IoCreateFile(&local_28,0x100100,&local_58,&local_20);
  if (iVar1 < 0) {
    local_68 = 0x141;
    local_60 = 
    "IoCreateFile( &Handle, ( 0x0100 ) | (0x00100000L), &Attr, &IoStatus, nullptr, 0, 0, 0x00000001, 0x00000040 | 0x00000008, nullptr, 0, CreateFileTypeNone, nullptr, 0x0100)"
    ;
  }
  else {
    local_c8 = &local_20;
    local_a0 = local_a0 & 0xffffffff00000000;
    local_a8 = 0;
    local_b0 = 0;
    uVar2 = 0;
    local_b8 = 0;
    local_c0 = 0x90020;
    iVar1 = ZwFsControlFile(local_28,0,0,0);
    if (iVar1 == 0x103) {
      uVar2 = 0;
      iVar1 = ZwWaitForSingleObject(local_28,0,0);
      if (iVar1 < 0) {
        local_68 = 0x154;
        local_60 = "ZwWaitForSingleObject(Handle.get(), 0 , nullptr)";
      }
      else {
        if (-1 < (int)local_20) goto LAB_140004e3c;
        local_68 = 0x155;
        local_60 = "IoStatus.Status";
        iVar1 = (int)local_20;
      }
    }
    else {
      if (-1 < iVar1) {
LAB_140004e3c:
        if (local_28 != 0) {
          ZwClose();
        }
        return 0;
      }
      local_68 = 0x150;
      local_60 = 
      "ZwFsControlFile( Handle.get(), nullptr, nullptr, nullptr, &IoStatus, ( ((0x00000009) << 16) | ((0) << 14) | ((8) << 2) | (0) ), nullptr, 0, nullptr, 0)"
      ;
    }
  }
  local_78 = "onecore\\base\\servicing\\globmerger\\kernel\\cimloader.cpp";
  local_70 = "DismountCim";
  RtlReportErrorOrigination(&local_78,uVar2,iVar1);
  if (local_28 != 0) {
    ZwClose();
  }
  return iVar1;
}



===== MountMergedCim @ 140004e7c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* long __cdecl MountMergedCim(unsigned long,struct _GUID const & __ptr64,struct _UNICODE_STRING
   const & __ptr64,struct Windows::Vector<struct _UNICODE_STRING const > const & __ptr64,void *
   __ptr64,void * __ptr64) */

long __cdecl
MountMergedCim(ulong param_1,_GUID *param_2,_UNICODE_STRING *param_3,
              Vector<_UNICODE_STRING_const_> *param_4,void *param_5,void *param_6)

{
  allocator<CimFs::MappedRegionKernel> *paVar1;
  ushort uVar2;
  long lVar3;
  uint uVar4;
  int iVar5;
  allocator<CimFs::MappedRegionKernel> *paVar6;
  allocator<CimFs::MappedRegionKernel> *paVar7;
  uint *puVar8;
  int *piVar9;
  ulonglong uVar10;
  allocator<CimFs::MappedRegionKernel> *paVar11;
  CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *pCVar12;
  _UNICODE_STRING **pp_Var13;
  _GUID *p_Var14;
  __uint64 *p_Var15;
  CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *pCVar16;
  undefined8 uVar17;
  __uint64 *p_Var18;
  ulonglong uVar19;
  MappedRegionKernel *pMVar20;
  ushort *puVar21;
  allocator<CimFs::MappedRegionKernel> *paVar22;
  __uint64 *p_Var23;
  CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *pCVar24;
  __uint64 _Var25;
  undefined8 uVar26;
  ushort *puVar27;
  CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *pCVar28;
  uint uVar29;
  longlong lVar30;
  _UNICODE_STRING *p_Var31;
  MappedRegionKernel *pMVar32;
  bool bVar33;
  undefined1 auStack_228 [32];
  CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *local_208;
  undefined4 local_200;
  undefined1 local_1f8;
  undefined8 *local_1f0;
  undefined8 *local_1e8;
  uint local_1d8;
  uint local_1d4;
  ulong local_1d0 [2];
  CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *local_1c8;
  CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *pCStack_1c0;
  undefined8 local_1b8;
  char *local_1b0;
  CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *local_1a8;
  CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *pCStack_1a0;
  undefined8 local_198;
  char *local_190;
  CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *local_188;
  CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *pCStack_180;
  undefined8 local_178;
  char *local_170;
  _GUID *local_168;
  MappedRegionKernel *local_160;
  longlong lStack_158;
  undefined8 local_150;
  CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *local_148;
  CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *pCStack_140;
  undefined8 local_138;
  char *local_130;
  _UNICODE_STRING *local_128;
  CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *pCStack_120;
  undefined8 local_118;
  char *local_110;
  CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *local_108;
  longlong lStack_100;
  CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *local_f8;
  CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *pCStack_f0;
  undefined8 local_e8;
  char *local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  wchar_t *local_c8;
  longlong local_c0;
  MappedRegionKernel *local_b8;
  MappedRegionKernel *pMStack_b0;
  undefined8 local_a8;
  char *local_a0;
  CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *local_98;
  CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *pCStack_90;
  undefined8 local_88;
  char *local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  ulonglong local_50;
  
  pp_Var13 = &local_128;
  local_50 = __security_cookie ^ (ulonglong)auStack_228;
  local_f8 = param_6;
  local_148 = param_5;
  local_1d0[0] = param_1;
  local_168 = param_2;
  local_128 = param_3;
  if (*(ushort *)param_3 < 3) {
    local_a8 = 0x5b;
    local_a0 = "ParentVolume.Length > sizeof(WCHAR)";
    p_Var14 = param_2;
LAB_140004f0c:
    pMStack_b0 = (MappedRegionKernel *)0x140012720;
    local_b8 = (MappedRegionKernel *)0x1400125e0;
    RtlReportErrorOrigination(&local_b8,p_Var14,-0x3ffffff3);
    return -0x3ffffff3;
  }
  p_Var14 = (_GUID *)0x5c;
  if (*(short *)(*(longlong *)(param_3 + 8) + -2 + (ulonglong)(*(ushort *)param_3 >> 1) * 2) == 0x5c
     ) {
    local_a8 = 0x5c;
    local_a0 = "ParentVolume.Buffer[(ParentVolume.Length / sizeof(WCHAR)) - 1] != L\'\\\\\'";
    goto LAB_140004f0c;
  }
  local_1d8 = 0;
  local_98 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x160014;
  pCStack_90 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x1400125b0;
  local_188 = _g_GlobMergerConfigPath;
  pCStack_180 = pCRam0000000140017058;
  lVar3 = ReadRegDWORD(&local_188,&local_98,&local_1d8);
  if (lVar3 < 0) {
    return lVar3;
  }
  pCVar28 = *(CVector<gsl::byte,BUCL::Rtl::CCallDisposition> **)param_4;
  local_a8 = 0xffffffffffffffff;
  local_188 = pCVar28 + *(longlong *)(param_4 + 8) * 0x10;
  local_150 = 0;
  local_160 = (MappedRegionKernel *)0x0;
  lStack_158 = 0;
  local_b8 = (MappedRegionKernel *)0xffffffffffffffff;
  pMStack_b0 = (MappedRegionKernel *)0xffffffffffffffff;
  if (param_5 == (void *)0x0) {
    uVar10 = 0x1c;
    if (pCVar28 != local_188) {
      do {
        uVar2 = *(ushort *)pCVar28;
        pCVar28 = pCVar28 + 0x10;
        uVar10 = uVar10 + 4 + (ulonglong)uVar2 + (ulonglong)*(ushort *)param_3;
      } while (pCVar28 != local_188);
    }
    piVar9 = (int *)BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>::Resize
                              ((CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)&local_160,
                               (__uint64)local_1d0);
    p_Var31 = local_128;
    pMVar32 = local_160;
    iVar5 = *piVar9;
    if (iVar5 < 0) {
      if (local_160 != (MappedRegionKernel *)0x0) {
        ExFreePoolWithTag(local_160,0);
      }
      return iVar5;
    }
    if (((uVar10 == 0xffffffffffffffff) || (local_160 == (MappedRegionKernel *)0x0)) ||
       (uVar10 < 0x1c)) {
LAB_140005ce3:
                    /* WARNING: Subroutine does not return */
      gsl::details::terminate();
    }
    pCVar28 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)(uVar10 - 0x18);
    if (pCVar28 == (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0xffffffffffffffff)
    goto LAB_140005ce3;
    pCVar16 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)(local_160 + 0x18);
    *(undefined4 *)(local_160 + 0x14) = *(undefined4 *)(param_4 + 8);
    uVar26 = *(undefined8 *)local_168;
    uVar17 = *(undefined8 *)(local_168 + 8);
    *(uint *)(local_160 + 0x10) = local_1d8 | param_1;
    *(undefined8 *)local_160 = uVar26;
    *(undefined8 *)(local_160 + 8) = uVar17;
    puVar21 = *(ushort **)param_4;
    puVar27 = puVar21 + *(longlong *)(param_4 + 8) * 8;
    if (puVar21 != puVar27) {
      do {
        pCVar24 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)((ulonglong)*puVar21 + 4);
        if (pCVar28 < pCVar24) goto LAB_140005ce3;
        *(ushort *)pCVar16 = *puVar21 + *(short *)p_Var31;
        if (pCVar28 < (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x4) goto LAB_140005ce3;
        local_148 = pCVar28 + -4;
        if (local_148 == (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0xffffffffffffffff)
        goto LAB_140005ce3;
        local_f8 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)(ulonglong)*(ushort *)p_Var31;
        pCStack_140 = pCVar16 + 4;
        pCStack_f0 = *(CVector<gsl::byte,BUCL::Rtl::CCallDisposition> **)(p_Var31 + 8);
        if ((pCStack_f0 == (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x0) &&
           (local_f8 != (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x0)) goto LAB_140005ce3;
        local_1c8 = local_f8;
        pCStack_1c0 = pCStack_f0;
        local_98 = local_148;
        pCStack_90 = pCStack_140;
        gsl::copy<gsl::byte_const_,_1,gsl::byte,_1>(&local_1c8,&local_98);
        pCVar12 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)
                  ((ulonglong)*(ushort *)p_Var31 + 4);
        if (pCVar28 < pCVar12) goto LAB_140005ce3;
        local_188 = pCVar28 + -(longlong)pCVar12;
        if (local_188 == (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0xffffffffffffffff)
        goto LAB_140005ce3;
        pCStack_180 = pCVar16 + (longlong)pCVar12;
        local_1a8 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)(ulonglong)*puVar21;
        pCStack_1a0 = *(CVector<gsl::byte,BUCL::Rtl::CCallDisposition> **)(puVar21 + 4);
        if ((pCStack_1a0 == (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x0) &&
           (local_1a8 != (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x0)) goto LAB_140005ce3;
        local_1c8 = local_188;
        pCStack_1c0 = pCStack_180;
        local_98 = local_1a8;
        pCStack_90 = pCStack_1a0;
        gsl::copy<gsl::byte_const_,_1,gsl::byte,_1>(&local_98,&local_1c8);
        if (pCVar28 < pCVar24) goto LAB_140005ce3;
        pCVar28 = pCVar28 + -(longlong)pCVar24;
        local_128 = (_UNICODE_STRING *)pCVar28;
        if (pCVar28 == (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0xffffffffffffffff)
        goto LAB_140005ce3;
        pCVar16 = pCVar16 + (longlong)pCVar24;
        puVar21 = puVar21 + 8;
        pCStack_120 = pCVar16;
        local_98 = pCVar28;
        pCStack_90 = pCVar16;
      } while (puVar21 != puVar27);
    }
    uVar26 = 0x220014;
  }
  else {
    paVar11 = (allocator<CimFs::MappedRegionKernel> *)0x0;
    paVar22 = (allocator<CimFs::MappedRegionKernel> *)0x0;
    paVar7 = (allocator<CimFs::MappedRegionKernel> *)0x0;
    bVar33 = pCVar28 == local_188;
    while (uVar4 = 0, !bVar33) {
      if (paVar22 == paVar7) {
        p_Var15 = (__uint64 *)((longlong)paVar7 - (longlong)paVar11 >> 4);
        p_Var23 = p_Var15;
        if (p_Var15 != (__uint64 *)0xffffffffffffffff) {
          p_Var23 = (__uint64 *)((longlong)p_Var15 + 1);
        }
        uVar29 = 0xc0000095;
        if (p_Var15 != (__uint64 *)0xffffffffffffffff) {
          uVar29 = uVar4;
        }
        if (-1 < (int)uVar29) {
          if (p_Var15 < p_Var23) {
            if (p_Var15 < (__uint64 *)0x4) {
              p_Var18 = (__uint64 *)0x4;
            }
            else {
              if (p_Var15 < (__uint64 *)0x21) {
                p_Var18 = (__uint64 *)((longlong)p_Var15 * 2);
              }
              else {
                p_Var18 = (__uint64 *)(((ulonglong)p_Var15 >> 1) + (longlong)p_Var15);
              }
              uVar4 = -(uint)(p_Var18 < p_Var15) & 0xc0000095;
              if ((int)uVar4 < 0) goto LAB_1400051a5;
            }
            if (p_Var18 < p_Var23) {
              p_Var18 = p_Var23;
            }
            if (p_Var18 < (__uint64 *)0xfffffffffffffff) {
              paVar6 = paVar11;
              if (p_Var15 < p_Var18) {
                local_1a8 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x0;
                BUCL::Implementation::Multiply<BUCL::Rtl::CCallDisposition,unsigned___int64>
                          ((__uint64)&local_1d4,0x10,p_Var18);
                uVar4 = local_1d4;
                if (-1 < (int)local_1d4) {
                  paVar6 = operator_new((__uint64)local_1a8);
                  if (paVar6 != (allocator<CimFs::MappedRegionKernel> *)0x0) {
                    if (paVar11 != paVar22) {
                      paVar7 = paVar11;
                      do {
                        paVar1 = paVar7 + ((longlong)paVar6 - (longlong)paVar11);
                        if (paVar1 != (allocator<CimFs::MappedRegionKernel> *)0x0) {
                          uVar26 = *(undefined8 *)(paVar7 + 8);
                          *(undefined8 *)paVar1 = *(undefined8 *)paVar7;
                          *(undefined8 *)(paVar1 + 8) = uVar26;
                          *(undefined8 *)paVar7 = 0;
                          *(undefined8 *)(paVar7 + 8) = 0;
                        }
                        paVar7 = paVar7 + 0x10;
                      } while (paVar7 != paVar22);
                    }
                    lVar30 = (longlong)paVar22 - (longlong)paVar11;
                    while (paVar11 != paVar22) {
                      paVar22 = paVar22 + -0x10;
                      FsFltWil::Details::FreeUnicodeString((_UNICODE_STRING *)paVar22);
                    }
                    if (paVar11 != (allocator<CimFs::MappedRegionKernel> *)0x0) {
                      ExFreePoolWithTag(paVar11,0);
                    }
                    paVar22 = paVar6 + (lVar30 >> 4) * 0x10;
                    paVar7 = paVar6 + (longlong)p_Var18 * 0x10;
                    goto LAB_140005197;
                  }
                  uVar4 = 0xc0000017;
                  paVar6 = paVar11;
                }
              }
              else {
LAB_140005197:
                uVar4 = 0;
              }
              uVar4 = -(uint)((int)uVar4 < 0) & uVar4;
              paVar11 = paVar6;
            }
            else {
              uVar4 = 0xc0000017;
            }
          }
          else {
          }
LAB_1400051a5:
          uVar29 = -(uint)((int)uVar4 < 0) & uVar4;
        }
        param_3 = local_128;
        if (-1 < (int)uVar29) goto LAB_1400051d5;
        if ((int)uVar29 < 0) goto joined_r0x0001400052c7;
      }
      else {
LAB_1400051d5:
        if (paVar22 != (allocator<CimFs::MappedRegionKernel> *)0x0) {
          *(undefined8 *)paVar22 = 0;
          *(undefined8 *)(paVar22 + 8) = 0;
        }
        paVar22 = paVar22 + 0x10;
      }
      pCStack_1a0 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x0;
      local_1a8 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)
                  ((ulonglong)(ushort)(*(short *)param_3 + *(short *)pCVar28) << 0x10);
      uVar10 = (ulonglong)(ushort)(*(short *)param_3 + *(short *)pCVar28);
      lStack_100 = ExAllocatePool2(0x100,uVar10,0x4c467346);
      if (lStack_100 == 0) {
        local_108 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x0;
        lStack_100 = 0;
      }
      else {
        local_108 = local_1a8;
        local_1a8 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x0;
      }
      pCStack_1a0 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x0;
      FsFltWil::Details::FreeUnicodeString((_UNICODE_STRING *)&local_1a8);
      lVar30 = lStack_100;
      pCVar16 = local_108;
      uVar19 = (longlong)paVar22 - (longlong)paVar11 & 0xfffffffffffffff0;
      p_Var31 = (_UNICODE_STRING *)(paVar11 + (uVar19 - 0x10));
      if (p_Var31 != (_UNICODE_STRING *)&local_108) {
        local_108 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x0;
        lStack_100 = 0;
        FsFltWil::Details::FreeUnicodeString(p_Var31);
        *(CVector<gsl::byte,BUCL::Rtl::CCallDisposition> **)p_Var31 = pCVar16;
        *(longlong *)(p_Var31 + 8) = lVar30;
      }
      FsFltWil::Details::FreeUnicodeString((_UNICODE_STRING *)&local_108);
      if (*(longlong *)(paVar11 + (uVar19 - 8)) == 0) {
        local_a8 = 0x6c;
        local_b8 = (MappedRegionKernel *)0x1400125e0;
        pMStack_b0 = (MappedRegionKernel *)0x140012720;
        local_a0 = "FullPaths.GetBack().Buffer";
        RtlReportErrorOrigination(&local_b8,uVar10,-0x3fffffe9);
        while (paVar11 != paVar22) {
          paVar22 = paVar22 + -0x10;
          FsFltWil::Details::FreeUnicodeString((_UNICODE_STRING *)paVar22);
        }
        if (paVar11 != (allocator<CimFs::MappedRegionKernel> *)0x0) {
          ExFreePoolWithTag(paVar11,0);
        }
        return -0x3fffffe9;
      }
      iVar5 = RtlAppendUnicodeStringToString(p_Var31,param_3);
      if (iVar5 < 0) goto joined_r0x000140005313;
      iVar5 = RtlAppendUnicodeStringToString(p_Var31,pCVar28);
      if (iVar5 < 0) goto joined_r0x0001400052fb;
      pCVar28 = pCVar28 + 0x10;
      bVar33 = pCVar28 == local_188;
    }
    local_1b8 = 0;
    local_1c8 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x0;
    pCStack_1c0 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x0;
    pCVar28 = local_1c8;
    for (paVar7 = paVar11; local_1c8 = pCVar28, paVar7 != paVar22; paVar7 = paVar7 + 0x10) {
      pCStack_180 = *(CVector<gsl::byte,BUCL::Rtl::CCallDisposition> **)(paVar7 + 8);
      local_188 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)
                  (ulonglong)(*(ushort *)paVar7 >> 1);
      if ((pCStack_180 == (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x0) &&
         (local_188 != (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x0)) {
                    /* WARNING: Subroutine does not return */
        gsl::details::terminate();
      }
      puVar8 = (uint *)BUCL::CVector<gsl::span<wchar_t_const_,-1>,BUCL::Rtl::CCallDisposition>::
                       EmplaceBack<gsl::span<wchar_t,_1>_>
                                 ((CVector<gsl::span<wchar_t_const_,_1>,BUCL::Rtl::CCallDisposition>
                                   *)&local_1c8,(span<wchar_t,_1> *)&local_1d4);
      uVar29 = *puVar8;
      if ((int)uVar29 < 0) {
        if (local_1c8 != (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x0) {
          ExFreePoolWithTag(local_1c8,0);
        }
        do {
          paVar22 = paVar22 + -0x10;
          FsFltWil::Details::FreeUnicodeString((_UNICODE_STRING *)paVar22);
        } while (paVar22 != paVar11);
        if (paVar11 == (allocator<CimFs::MappedRegionKernel> *)0x0) {
          return uVar29;
        }
        goto LAB_1400052e2;
      }
      pCVar28 = local_1c8;
    }
    local_1a8 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x0;
    local_188 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)
                ((longlong)pCStack_1c0 - (longlong)pCVar28 >> 4);
    if (local_188 == (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0xffffffffffffffff)
    goto LAB_140005ce3;
    pCStack_180 = pCVar28;
    if (pCVar28 == (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x0) {
      if (local_188 != (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x0) goto LAB_140005ce3;
    }
    local_208 = local_f8;
    local_98 = local_188;
    pCStack_90 = pCVar28;
    iVar5 = CimFs::OpenFileSystemsKernel(&local_98,&local_b8,&local_1a8,local_148);
    pMVar20 = local_b8;
    if (iVar5 < 0) {
      if (pCVar28 != (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x0) {
        ExFreePoolWithTag(pCVar28,0);
      }
      while (paVar11 != paVar22) {
        paVar22 = paVar22 + -0x10;
        FsFltWil::Details::FreeUnicodeString((_UNICODE_STRING *)paVar22);
      }
      if (paVar11 != (allocator<CimFs::MappedRegionKernel> *)0x0) {
        ExFreePoolWithTag(paVar11,0);
      }
      pMVar20 = local_b8;
      if (local_b8 == (MappedRegionKernel *)0xffffffffffffffff) {
        return iVar5;
      }
      utl::_RangeDestroyApc<utl::allocator<CimFs::MappedRegionKernel>_>
                ((allocator<CimFs::MappedRegionKernel> *)(pMStack_b0 + -(longlong)local_b8),local_b8
                 ,(longlong)(pMStack_b0 + -(longlong)local_b8) / 0x90);
      if (pMVar20 == (MappedRegionKernel *)0x0) {
        return iVar5;
      }
LAB_140005503:
      ExFreePoolWithTag(pMVar20,0);
      return iVar5;
    }
    pCVar16 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)&local_160;
    _Var25 = ((longlong)pMStack_b0 - (longlong)local_b8 >> 4) * -0x71c71c71c71c71c7;
    piVar9 = (int *)BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>::Resize
                              (pCVar16,(__uint64)&local_1d4);
    pMVar32 = local_160;
    iVar5 = *piVar9;
    if (iVar5 < 0) {
      if (pCVar28 != (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x0) {
        ExFreePoolWithTag(pCVar28,0);
        pCVar16 = pCVar28;
      }
      while (paVar11 != paVar22) {
        paVar22 = paVar22 + -0x10;
        pCVar16 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)paVar22;
        FsFltWil::Details::FreeUnicodeString((_UNICODE_STRING *)paVar22);
      }
      if (paVar11 != (allocator<CimFs::MappedRegionKernel> *)0x0) {
        ExFreePoolWithTag(paVar11,0);
        pCVar16 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)paVar11;
      }
      if ((pMVar20 != (MappedRegionKernel *)0xffffffffffffffff) &&
         (utl::_RangeDestroyApc<utl::allocator<CimFs::MappedRegionKernel>_>
                    ((allocator<CimFs::MappedRegionKernel> *)pCVar16,pMVar20,_Var25),
         pMVar20 != (MappedRegionKernel *)0x0)) {
        ExFreePoolWithTag(pMVar20,0);
      }
      pMVar20 = local_160;
      if (local_160 == (MappedRegionKernel *)0x0) {
        return iVar5;
      }
      goto LAB_140005503;
    }
    uVar10 = lStack_158 - (longlong)local_160;
    if (uVar10 == 0xffffffffffffffff) goto LAB_140005ce3;
    if (local_160 == (MappedRegionKernel *)0x0) goto LAB_140005ce3;
    if (uVar10 < 0x28) goto LAB_140005ce3;
    pCVar16 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)(uVar10 - 0x20);
    if (pCVar16 == (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0xffffffffffffffff)
    goto LAB_140005ce3;
    pCVar24 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)(local_160 + 0x20);
    uVar26 = *(undefined8 *)local_168;
    uVar17 = *(undefined8 *)(local_168 + 8);
    *(CVector<gsl::byte,BUCL::Rtl::CCallDisposition> **)(local_160 + 0x10) = local_1a8;
    *(uint *)(local_160 + 0x18) = local_1d8 | local_1d0[0];
    *(undefined8 *)local_160 = uVar26;
    *(undefined8 *)(local_160 + 8) = uVar17;
    *(int *)(local_160 + 0x1c) = (int)_Var25;
    for (; pMVar20 != pMStack_b0; pMVar20 = pMVar20 + 0x90) {
      if (pCVar16 < (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x20) goto LAB_140005ce3;
      *(undefined8 *)pCVar24 = *(undefined8 *)pMVar20;
      uVar26 = *(undefined8 *)(pMVar20 + 0x80);
      *(undefined8 *)(pCVar24 + 8) = *(undefined8 *)(pMVar20 + 0x78);
      *(undefined8 *)(pCVar24 + 0x10) = uVar26;
      *(undefined2 *)(pCVar24 + 0x18) = *(undefined2 *)(pMVar20 + 0x88);
      if (pCVar16 < (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x20) goto LAB_140005ce3;
      pCVar16 = pCVar16 + -0x20;
      local_148 = pCVar16;
      if (pCVar16 == (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0xffffffffffffffff)
      goto LAB_140005ce3;
      pCVar24 = pCVar24 + 0x20;
      pCStack_140 = pCVar24;
    }
    uVar26 = 0x22001c;
    if (pCVar28 != (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x0) {
      ExFreePoolWithTag(pCVar28,0);
    }
    while (paVar11 != paVar22) {
      paVar22 = paVar22 + -0x10;
      FsFltWil::Details::FreeUnicodeString((_UNICODE_STRING *)paVar22);
    }
    if (paVar11 != (allocator<CimFs::MappedRegionKernel> *)0x0) {
      ExFreePoolWithTag(paVar11,0);
    }
  }
  local_d0 = 0x2c002a;
  local_c8 = L"\\Device\\cimfs\\control";
  local_1c8 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)&local_c0;
  local_c0 = 0;
  pCVar16 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x2000000;
  local_d8 = 0;
  pCStack_1c0 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x0;
  local_1b8 = CONCAT71(local_1b8._1_7_,1);
  iVar5 = IoGetDeviceObjectPointer(&local_d0,0x2000000,&pCStack_1c0,&local_d8);
  pCVar28 = pCStack_1c0;
  if ((char)local_1b8 != '\0') {
    lVar30 = *(longlong *)local_1c8;
    *(CVector<gsl::byte,BUCL::Rtl::CCallDisposition> **)local_1c8 = pCStack_1c0;
    pCVar16 = pCVar28;
    if (lVar30 != 0) {
      ObfDereferenceObject();
      pCVar16 = pCVar28;
    }
  }
  if (iVar5 < 0) {
    local_1b8 = 0xc0;
    local_1c8 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x1400125e0;
    pp_Var13 = (_UNICODE_STRING **)&local_1c8;
    pCStack_1c0 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x140012720;
    local_1b0 = 
    "IoGetDeviceObjectPointer( &CimDevicePath, (0x02000000L), wil::out_param(DeviceFileObject), &DeviceObject)"
    ;
    goto LAB_140005c73;
  }
  local_68 = 0;
  local_78 = 0;
  uStack_70 = 0;
  KeInitializeEvent(&local_78,1,0);
  local_1e8 = &local_60;
  local_1f0 = &local_78;
  local_1f8 = 0;
  local_200 = 0;
  local_208 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x0;
  local_60 = 0;
  uStack_58 = 0;
  uVar17 = local_d8;
  pCVar16 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)
            IoBuildDeviceIoControlRequest(uVar26,local_d8,pMVar32);
  if (pCVar16 == (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x0) {
    local_88 = 0xd1;
    local_98 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x1400125e0;
    pCStack_90 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x140012720;
    local_80 = 
    "Irp = IoBuildDeviceIoControlRequest( IoctlCode, DeviceObject, Buffer.Begin(), static_cast<ULONG>(Buffer.Size()), nullptr, 0, 0 , &Event, &IoStatus)"
    ;
    RtlReportErrorOrigination(&local_98,uVar17,-0x3fffffe9);
    lVar30 = local_c0;
    local_c0 = 0;
    if (lVar30 != 0) {
      ObfDereferenceObject();
    }
    iVar5 = -0x3fffffe9;
    goto LAB_140005c94;
  }
  iVar5 = IofCallDriver(local_d8);
  if (iVar5 == 0x103) {
    local_208 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x0;
    pCVar16 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x0;
    iVar5 = KeWaitForSingleObject(&local_78,0,0);
    if (iVar5 < 0) {
      local_138 = 0xd9;
      local_148 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x1400125e0;
      pp_Var13 = (_UNICODE_STRING **)&local_148;
      pCStack_140 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x140012720;
      local_130 = "KeWaitForSingleObject(&Event, Executive, KernelMode, 0 , nullptr)";
    }
    else {
      if (-1 < (int)local_60) goto LAB_140005bd2;
      local_e8 = 0xda;
      local_f8 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x1400125e0;
      pp_Var13 = (_UNICODE_STRING **)&local_f8;
      pCStack_f0 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x140012720;
      local_e0 = "IoStatus.Status";
      iVar5 = (int)local_60;
    }
LAB_140005c73:
    RtlReportErrorOrigination(pp_Var13,pCVar16,iVar5);
  }
  else {
    if (iVar5 < 0) {
      local_178 = 0xd5;
      local_188 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x1400125e0;
      pp_Var13 = (_UNICODE_STRING **)&local_188;
      pCStack_180 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x140012720;
      local_170 = "IofCallDriver(DeviceObject,Irp)";
      goto LAB_140005c73;
    }
LAB_140005bd2:
    iVar5 = OpenVolume(local_168);
    if (-1 < iVar5) {
      pCVar16 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x1;
      iVar5 = SeConvertStringSecurityDescriptorToSecurityDescriptor
                        (L"O:SYG:SYD:AI(A;CI;FA;;;BA)(A;CI;FA;;;WD)(A;CI;FA;;;AC)(A;CI;FA;;;SY)(A;CI;FA;;;BU)(A;CI;FA;;;S-1-15-2-2)"
                         ,1,&SecurityDescriptor);
      if (iVar5 < 0) {
        local_198 = 0xe6;
        local_1a8 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x1400125e0;
        pp_Var13 = (_UNICODE_STRING **)&local_1a8;
        pCStack_1a0 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x140012720;
        local_190 = 
        "SeConvertStringSecurityDescriptorToSecurityDescriptor( L\"O:SYG:SYD:AI(A;CI;FA;;;BA)(A;CI;FA;;;WD)(A;CI;FA;;;AC)(A;CI;FA;;;SY)(A;CI;FA;;;BU)(A;CI;FA;;;S-1-15-2-2)\", 1, &SecurityDescriptor, nullptr)"
        ;
      }
      else {
        iVar5 = SetGlobMergerIsEnabledRegKey();
        lVar30 = local_c0;
        if (-1 < iVar5) {
          local_c0 = 0;
          if (lVar30 != 0) {
            ObfDereferenceObject();
          }
          utl::vector<CimFs::MappedRegionKernel,utl::allocator<CimFs::MappedRegionKernel>_>::
          ~vector<CimFs::MappedRegionKernel,utl::allocator<CimFs::MappedRegionKernel>_>
                    ((vector<CimFs::MappedRegionKernel,utl::allocator<CimFs::MappedRegionKernel>_> *
                     )&local_b8);
          BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>::
          ~CVector<gsl::byte,BUCL::Rtl::CCallDisposition>
                    ((CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)&local_160);
          return 0;
        }
        local_118 = 0xe8;
        local_128 = (_UNICODE_STRING *)0x1400125e0;
        pCStack_120 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x140012720;
        local_110 = "SetGlobMergerIsEnabledRegKey()";
      }
      goto LAB_140005c73;
    }
  }
  lVar30 = local_c0;
  local_c0 = 0;
  if (lVar30 != 0) {
    ObfDereferenceObject();
  }
LAB_140005c94:
  utl::vector<CimFs::MappedRegionKernel,utl::allocator<CimFs::MappedRegionKernel>_>::
  ~vector<CimFs::MappedRegionKernel,utl::allocator<CimFs::MappedRegionKernel>_>
            ((vector<CimFs::MappedRegionKernel,utl::allocator<CimFs::MappedRegionKernel>_> *)
             &local_b8);
  BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>::
  ~CVector<gsl::byte,BUCL::Rtl::CCallDisposition>
            ((CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)&local_160);
  return iVar5;
joined_r0x000140005313:
  while (paVar11 != paVar22) {
    paVar22 = paVar22 + -0x10;
    FsFltWil::Details::FreeUnicodeString((_UNICODE_STRING *)paVar22);
  }
  goto LAB_140005326;
joined_r0x0001400052c7:
  while (paVar11 != paVar22) {
    paVar22 = paVar22 + -0x10;
    FsFltWil::Details::FreeUnicodeString((_UNICODE_STRING *)paVar22);
  }
  if (paVar11 != (allocator<CimFs::MappedRegionKernel> *)0x0) {
LAB_1400052e2:
    ExFreePoolWithTag(paVar11,0);
  }
  return uVar29;
joined_r0x0001400052fb:
  while (paVar11 != paVar22) {
    paVar22 = paVar22 + -0x10;
    FsFltWil::Details::FreeUnicodeString((_UNICODE_STRING *)paVar22);
  }
LAB_140005326:
  if (paVar11 != (allocator<CimFs::MappedRegionKernel> *)0x0) {
    ExFreePoolWithTag(paVar11,0);
  }
  return iVar5;
}



===== MountSourceCim @ 140005cf0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl MountSourceCim(struct _GUID const & __ptr64,struct _UNICODE_STRING const & __ptr64)
    */

long __cdecl MountSourceCim(_GUID *param_1,_UNICODE_STRING *param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong *plVar4;
  int iVar5;
  int *piVar6;
  ulonglong uVar7;
  longlong *plVar8;
  longlong *plVar9;
  undefined8 uVar10;
  undefined1 auStack_f8 [32];
  undefined8 local_d8;
  undefined4 local_d0;
  undefined1 local_c8;
  longlong *local_c0;
  undefined8 *local_b8;
  longlong *local_a8;
  longlong *plStack_a0;
  undefined8 local_98;
  char *local_90;
  ulonglong local_88;
  longlong lStack_80;
  undefined1 local_78 [8];
  undefined8 local_70;
  undefined8 local_68;
  wchar_t *local_60;
  longlong local_58 [4];
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_f8;
  local_a8 = (longlong *)0x0;
  plStack_a0 = (longlong *)0x0;
  local_98 = 0;
  piVar6 = (int *)BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>::Resize
                            ((CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)&local_a8,
                             (__uint64)local_78);
  plVar4 = plStack_a0;
  plVar3 = local_a8;
  iVar5 = *piVar6;
  if (iVar5 < 0) {
    if (local_a8 != (longlong *)0x0) {
      ExFreePoolWithTag(local_a8,0);
    }
    return iVar5;
  }
  uVar7 = (longlong)plStack_a0 - (longlong)local_a8;
  lVar1 = lStack_80;
  if ((((uVar7 != 0xffffffffffffffff) && (local_a8 != (longlong *)0x0)) && (0x1b < uVar7)) &&
     ((longlong *)(uVar7 - 0x18) != (longlong *)0xffffffffffffffff)) {
    lVar1 = *(longlong *)param_1;
    lVar2 = *(longlong *)(param_1 + 8);
    *(undefined4 *)(local_a8 + 2) = 0;
    plVar9 = local_a8 + 3;
    *local_a8 = lVar1;
    local_a8[1] = lVar2;
    *(undefined2 *)((longlong)local_a8 + 0x14) = *(undefined2 *)param_2;
    lStack_80 = *(longlong *)(param_2 + 8);
    local_88 = (ulonglong)*(ushort *)param_2;
    if ((lStack_80 != 0) || (lVar1 = 0, local_88 == 0)) {
      local_88 = (ulonglong)*(ushort *)param_2;
      local_a8 = (longlong *)(uVar7 - 0x18);
      plStack_a0 = plVar9;
      gsl::copy<gsl::byte_const_,_1,gsl::byte,_1>(&local_88,&local_a8);
      local_68 = 0x2c002a;
      local_60 = L"\\Device\\cimfs\\control";
      local_a8 = local_58;
      local_58[0] = 0;
      plVar8 = (longlong *)0x2000000;
      local_70 = 0;
      plStack_a0 = (longlong *)0x0;
      local_98 = CONCAT71(local_98._1_7_,1);
      iVar5 = IoGetDeviceObjectPointer(&local_68,0x2000000,&plStack_a0,&local_70);
      plVar9 = plStack_a0;
      if (((char)local_98 != '\0') &&
         (lVar1 = *local_a8, *local_a8 = (longlong)plStack_a0, plVar8 = plVar9, lVar1 != 0)) {
        ObfDereferenceObject();
        plVar8 = plVar9;
      }
      if (iVar5 < 0) {
        local_98 = 0x10a;
        local_90 = 
        "IoGetDeviceObjectPointer( &CimDevicePath, (0x02000000L), wil::out_param(DeviceFileObject), &DeviceObject)"
        ;
      }
      else {
        local_58[3] = 0;
        local_58[1] = 0;
        local_58[2] = 0;
        KeInitializeEvent(local_58 + 1,1,0);
        local_b8 = &local_38;
        local_c0 = local_58 + 1;
        local_c8 = 0;
        local_d0 = 0;
        local_d8 = 0;
        local_38 = 0;
        uStack_30 = 0;
        uVar10 = local_70;
        plVar8 = (longlong *)
                 IoBuildDeviceIoControlRequest(0x22000c,local_70,plVar3,(int)plVar4 - (int)plVar3);
        if (plVar8 == (longlong *)0x0) {
          local_98 = 0x11b;
          local_a8 = (longlong *)0x1400125e0;
          plStack_a0 = (longlong *)0x140012b58;
          local_90 = 
          "Irp = IoBuildDeviceIoControlRequest( ( ((0x00000022) << 16) | ((0) << 14) | ((3) << 2) | (0) ), DeviceObject, Buffer.Begin(), static_cast<ULONG>(Buffer.Size()), nullptr, 0, 0 , &Event, &IoStatus)"
          ;
          RtlReportErrorOrigination(&local_a8,uVar10,-0x3fffffe9);
          lVar1 = local_58[0];
          local_58[0] = 0;
          if (lVar1 != 0) {
            ObfDereferenceObject();
          }
          if (plVar3 != (longlong *)0x0) {
            ExFreePoolWithTag(plVar3,0);
          }
          return -0x3fffffe9;
        }
        iVar5 = IofCallDriver(local_70);
        if (iVar5 == 0x103) {
          local_d8 = 0;
          plVar8 = (longlong *)0x0;
          iVar5 = KeWaitForSingleObject(local_58 + 1,0,0,0);
          if (iVar5 < 0) {
            local_98 = 0x123;
            local_90 = "KeWaitForSingleObject(&Event, Executive, KernelMode, 0 , nullptr)";
          }
          else {
            if (-1 < (int)local_38) goto LAB_1400060a3;
            local_98 = 0x124;
            local_90 = "IoStatus.Status";
            iVar5 = (int)local_38;
          }
        }
        else {
          if (-1 < iVar5) {
LAB_1400060a3:
            lVar1 = local_58[0];
            local_58[0] = 0;
            if (lVar1 != 0) {
              ObfDereferenceObject();
            }
            if (plVar3 != (longlong *)0x0) {
              ExFreePoolWithTag(plVar3,0);
            }
            return 0;
          }
          local_98 = 0x11f;
          local_90 = "IofCallDriver(DeviceObject,Irp)";
        }
      }
      plStack_a0 = (longlong *)0x140012b58;
      local_a8 = (longlong *)0x1400125e0;
      RtlReportErrorOrigination(&local_a8,plVar8,iVar5);
      lVar1 = local_58[0];
      local_58[0] = 0;
      if (lVar1 != 0) {
        ObfDereferenceObject();
      }
      if (plVar3 != (longlong *)0x0) {
        ExFreePoolWithTag(plVar3,0);
      }
      return iVar5;
    }
  }
  lStack_80 = lVar1;
                    /* WARNING: Subroutine does not return */
  gsl::details::terminate();
}



===== OpenFile @ 1400060e8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl OpenFile(struct _UNICODE_STRING const & __ptr64) */

long __cdecl OpenFile(_UNICODE_STRING *param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_e8 [32];
  undefined8 local_c8;
  undefined4 local_c0;
  undefined4 local_b8;
  undefined4 local_b0;
  undefined4 local_a8;
  undefined8 local_a0;
  undefined4 local_98;
  undefined4 local_90;
  undefined8 local_88;
  undefined4 local_80;
  char *local_78;
  char *local_70;
  undefined8 local_68;
  char *local_60;
  undefined8 local_58;
  undefined8 local_50;
  _UNICODE_STRING *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  longlong local_28 [4];
  
  local_28[3] = __security_cookie ^ (ulonglong)auStack_e8;
  local_50 = 0;
  local_28[0] = 0;
  local_80 = 0x100;
  local_88 = 0;
  uVar2 = 0x120089;
  local_90 = 0;
  local_98 = 0;
  local_a0 = 0;
  local_a8 = 8;
  local_b0 = 1;
  local_b8 = 7;
  local_c0 = 0;
  local_c8 = 0;
  local_58 = 0x30;
  local_40 = 0x240;
  local_38 = 0;
  uStack_30 = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_48 = param_1;
  iVar1 = IoCreateFile(local_28,0x120089,&local_58,local_28 + 1);
  if (iVar1 < 0) {
    local_68 = 0x1b8;
    local_78 = "onecore\\base\\servicing\\globmerger\\kernel\\cimloader.cpp";
    local_70 = "OpenFile";
    local_60 = 
    "IoCreateFile( &Handle, (((0x00020000L)) | ( 0x0001 ) | ( 0x0080 ) | ( 0x0008 ) | (0x00100000L)), &Attr, &IoStatus, nullptr, 0, 0x00000001 | 0x00000002 | 0x00000004, 0x00000001, 0x00000008, nullptr, 0, CreateFileTypeNone, nullptr, 0x0100)"
    ;
    RtlReportErrorOrigination(&local_78,uVar2,iVar1);
    if (local_28[0] != 0) {
      ZwClose();
    }
  }
  else {
    if (local_28[0] != 0) {
      ZwClose();
    }
    iVar1 = 0;
  }
  return iVar1;
}



===== ReadFile @ 140006220 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl ReadFile(struct _UNICODE_STRING const & __ptr64,class BUCL::CVector<enum
   gsl::byte,class BUCL::Rtl::CCallDisposition> * __ptr64) */

long __cdecl
ReadFile(_UNICODE_STRING *param_1,CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *param_2)

{
  int iVar1;
  longlong lVar2;
  int *piVar3;
  undefined8 *puVar4;
  undefined1 auStack_118 [32];
  undefined8 *local_f8;
  ulonglong local_f0;
  int local_e8;
  undefined8 *local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined4 local_c0;
  undefined8 local_b8;
  undefined4 local_b0;
  char *local_a8;
  char *local_a0;
  undefined8 local_98;
  char *local_90;
  undefined1 local_88 [8];
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  _UNICODE_STRING *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  longlong local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_118;
  lVar2 = *(longlong *)(param_2 + 8);
  if (*(longlong *)param_2 != lVar2) {
    do {
      lVar2 = lVar2 + -1;
    } while (lVar2 != *(longlong *)param_2);
    *(longlong *)(param_2 + 8) = lVar2;
  }
  local_60 = 0;
  local_38 = 0;
  local_b0 = 0x100;
  local_b8 = 0;
  local_c0 = 0;
  puVar4 = (undefined8 *)0x120089;
  local_c8 = 0;
  local_d0 = 0;
  local_d8 = CONCAT44(local_d8._4_4_,0x48);
  local_e0 = (undefined8 *)CONCAT44(local_e0._4_4_,1);
  local_e8 = 1;
  local_f0 = local_f0 & 0xffffffff00000000;
  local_f8 = (undefined8 *)0x0;
  local_68 = 0x30;
  local_50 = 0x240;
  local_48 = 0;
  uStack_40 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_58 = param_1;
  iVar1 = IoCreateFile(&local_38,0x120089,&local_68,&local_30);
  if ((iVar1 == -0x3fffffcc) || (iVar1 == -0x3fffffc6)) goto LAB_1400064cf;
  if (iVar1 < 0) {
    local_98 = 0x176;
    local_90 = 
    "IoCreateFile( &Handle, (((0x00020000L)) | ( 0x0001 ) | ( 0x0080 ) | ( 0x0008 ) | (0x00100000L)), &Attr, &IoStatus, nullptr, 0, 0x00000001, 0x00000001, 0x00000040 | 0x00000008, nullptr, 0, CreateFileTypeNone, nullptr, 0x0100)"
    ;
  }
  else {
    local_f8 = (undefined8 *)CONCAT44(local_f8._4_4_,5);
    local_70 = 0;
    puVar4 = &local_30;
    local_80 = 0;
    uStack_78 = 0;
    iVar1 = ZwQueryInformationFile(local_38,puVar4,&local_80,0x18);
    if (iVar1 < 0) {
      local_98 = 0x184;
      local_90 = 
      "ZwQueryInformationFile( Handle.get(), &IoStatus, &FileInfo, sizeof(FileInfo), FileStandardInformation)"
      ;
    }
    else {
      piVar3 = (int *)BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>::Resize
                                (param_2,(__uint64)local_88);
      iVar1 = *piVar3;
      if (iVar1 < 0) goto LAB_140006339;
      local_d8 = 0;
      local_e0 = &local_20;
      local_e8 = *(int *)(param_2 + 8) - *(int *)param_2;
      local_20 = 0;
      puVar4 = (undefined8 *)0x0;
      local_f0 = *(ulonglong *)param_2;
      local_f8 = &local_30;
      iVar1 = ZwReadFile(local_38,0,0,0);
      if (iVar1 == 0x103) {
        puVar4 = (undefined8 *)0x0;
        iVar1 = ZwWaitForSingleObject(local_38,0,0);
        if (iVar1 < 0) {
          local_98 = 0x19a;
          local_90 = "ZwWaitForSingleObject(Handle.get(), 0 , nullptr)";
        }
        else {
          if (-1 < (int)local_30) goto LAB_1400064cf;
          local_98 = 0x19b;
          local_90 = "IoStatus.Status";
          iVar1 = (int)local_30;
        }
      }
      else {
        if (-1 < iVar1) {
LAB_1400064cf:
          if (local_38 != 0) {
            ZwClose();
          }
          return 0;
        }
        local_98 = 0x196;
        local_90 = 
        "ZwReadFile( Handle.get(), nullptr, nullptr, nullptr, &IoStatus, Buffer->Begin(), static_cast<ULONG>(Buffer->Size()), &Offset, nullptr)"
        ;
      }
    }
  }
  local_a0 = "ReadFile";
  local_a8 = "onecore\\base\\servicing\\globmerger\\kernel\\cimloader.cpp";
  RtlReportErrorOrigination(&local_a8,puVar4,iVar1);
LAB_140006339:
  if (local_38 != 0) {
    ZwClose();
  }
  return iVar1;
}



===== ReadRegDWORD @ 140006510 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl ReadRegDWORD(struct _UNICODE_STRING,struct _UNICODE_STRING,unsigned long * __ptr64)
    */

long __cdecl ReadRegDWORD(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined1 auStack_b8 [32];
  undefined4 local_98;
  undefined4 *local_90;
  char *local_88;
  char *local_80;
  undefined8 local_78;
  char *local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  longlong local_38;
  undefined4 local_30 [2];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_b8;
  *param_3 = 0;
  local_60 = 0;
  local_38 = 0;
  uVar3 = 0x20019;
  local_68 = 0x30;
  local_50 = 0x240;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = param_1;
  iVar1 = ZwOpenKey(&local_38,0x20019,&local_68);
  if (iVar1 != -0x3fffffcc) {
    if (iVar1 < 0) {
      local_78 = 0x1c8;
      local_88 = "onecore\\base\\servicing\\globmerger\\kernel\\cimloader.cpp";
      local_80 = "ReadRegDWORD";
      local_70 = 
      "ZwOpenKey(&Handle, ((((0x00020000L)) | (0x0001) | (0x0008) | (0x0010)) & (~(0x00100000L))), &Attr)"
      ;
      RtlReportErrorOrigination(&local_88,uVar3,iVar1);
      if (local_38 != 0) {
        ZwClose();
      }
      return iVar1;
    }
    uVar3 = 0x14;
    lVar2 = ExAllocatePool2(0x40,0x14,0x4c467346);
    if (lVar2 == 0) {
      local_78 = 0x1d2;
      local_88 = "onecore\\base\\servicing\\globmerger\\kernel\\cimloader.cpp";
      local_80 = "ReadRegDWORD";
      local_70 = "Info.AllocateWithTotalSize(InfoSize)";
      RtlReportErrorOrigination(&local_88,uVar3,-0x3fffffe9);
      if (local_38 != 0) {
        ZwClose();
      }
      return -0x3fffffe9;
    }
    local_90 = local_30;
    local_30[0] = 0;
    local_98 = 0x14;
    iVar1 = ZwQueryValueKey(local_38,param_2,2,lVar2);
    if (iVar1 != -0x3fffffcc) {
      if (iVar1 < 0) {
        local_78 = 0x1dd;
        local_88 = "onecore\\base\\servicing\\globmerger\\kernel\\cimloader.cpp";
        local_80 = "ReadRegDWORD";
        local_70 = 
        "ZwQueryValueKey( Handle.get(), const_cast<PUNICODE_STRING>(&ValueName), KeyValuePartialInformation, Info, InfoSize, &ResultLength)"
        ;
        RtlReportErrorOrigination(&local_88,param_2,iVar1);
        ExFreePoolWithTag(lVar2,0);
        if (local_38 != 0) {
          ZwClose();
        }
        return iVar1;
      }
      if ((*(int *)(lVar2 + 8) == 4) && (*(int *)(lVar2 + 4) == 4)) {
        *param_3 = *(undefined4 *)(lVar2 + 0xc);
      }
    }
    ExFreePoolWithTag(lVar2,0);
  }
  if (local_38 != 0) {
    ZwClose();
  }
  return 0;
}



===== Resize @ 140006754 =====

/* public: class BUCL::Rtl::CCallDisposition __cdecl BUCL::CVector<enum gsl::byte,class
   BUCL::Rtl::CCallDisposition>::Resize(unsigned __int64) __ptr64 */

__uint64 __thiscall
BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>::Resize
          (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *this,__uint64 param_1)

{
  longlong lVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  __uint64 *in_R8;
  longlong lVar6;
  int local_res8 [2];
  
  lVar6 = *(longlong *)(this + 8);
  lVar1 = *(longlong *)this;
  if (in_R8 <= (__uint64 *)(lVar6 - lVar1)) {
    if (in_R8 < (__uint64 *)(lVar6 - lVar1)) {
      do {
        lVar6 = lVar6 + -1;
      } while (in_R8 < (__uint64 *)(lVar6 - lVar1));
      *(longlong *)(this + 8) = lVar6;
    }
    goto LAB_140006871;
  }
  if ((__uint64 *)(*(longlong *)(this + 0x10) - lVar1) < in_R8) {
    Implementation::Multiply<BUCL::Rtl::CCallDisposition,unsigned___int64>
              ((__uint64)local_res8,1,in_R8);
    if (-1 < local_res8[0]) {
      puVar2 = operator_new(0);
      if (puVar2 != (undefined1 *)0x0) {
        puVar5 = puVar2;
        for (puVar4 = *(undefined1 **)this; puVar3 = *(undefined1 **)(this + 8), puVar4 != puVar3;
            puVar4 = puVar4 + 1) {
          if (puVar5 != (undefined1 *)0x0) {
            *puVar5 = *puVar4;
          }
          puVar5 = puVar5 + 1;
        }
        puVar4 = *(undefined1 **)this;
        lVar6 = (longlong)puVar3 - (longlong)puVar4;
        if (puVar4 != puVar3) {
          do {
            puVar3 = puVar3 + -1;
          } while (puVar3 != puVar4);
          *(undefined1 **)(this + 8) = puVar3;
        }
        if (puVar4 != (undefined1 *)0x0) {
          ExFreePoolWithTag(puVar4,0);
        }
        *(undefined1 **)this = puVar2;
        *(undefined1 **)(this + 8) = puVar2 + lVar6;
        *(undefined1 **)(this + 0x10) = puVar2 + (longlong)in_R8;
        goto LAB_14000682f;
      }
      local_res8[0] = -0x3fffffe9;
    }
  }
  else {
LAB_14000682f:
    local_res8[0] = 0;
  }
  if (local_res8[0] < 0) {
    *(int *)param_1 = local_res8[0];
    return param_1;
  }
  do {
    if (*(undefined1 **)(this + 8) != (undefined1 *)0x0) {
      **(undefined1 **)(this + 8) = 0;
    }
    *(longlong *)(this + 8) = *(longlong *)(this + 8) + 1;
  } while (in_R8 != (__uint64 *)(*(longlong *)(this + 8) - *(longlong *)this));
LAB_140006871:
  *(undefined4 *)param_1 = 0;
  return param_1;
}



===== SetGlobMergerIsEnabledRegKey @ 140006894 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl SetGlobMergerIsEnabledRegKey(void) */

long __cdecl SetGlobMergerIsEnabledRegKey(void)

{
  int iVar1;
  _UNICODE_STRING *p_Var2;
  undefined1 auStack_b8 [32];
  undefined4 *local_98;
  undefined4 local_90;
  undefined8 local_88;
  char *local_78;
  char *local_70;
  undefined8 local_68;
  char *local_60;
  undefined8 local_58;
  undefined8 local_50;
  _UNICODE_STRING *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  longlong local_28;
  undefined4 local_20 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_b8;
  local_88 = 0;
  local_90 = 0;
  local_98 = (undefined4 *)0x0;
  local_50 = 0;
  local_28 = 0;
  p_Var2 = (_UNICODE_STRING *)0x20006;
  local_48 = &g_GlobMergerConfigPath;
  local_38 = 0;
  uStack_30 = 0;
  local_58 = 0x30;
  local_40 = 0x240;
  iVar1 = ZwCreateKey(&local_28,0x20006,&local_58,0);
  if (iVar1 < 0) {
    local_68 = 0x41;
    local_60 = 
    "ZwCreateKey(&Handle, ((((0x00020000L)) | (0x0002) | (0x0004)) & (~(0x00100000L))), &Attr, 0L, nullptr, (0x00000000L), nullptr)"
    ;
  }
  else {
    local_98 = local_20;
    local_20[0] = 1;
    local_90 = 4;
    p_Var2 = &g_GlobMergerIsEnabledValue;
    iVar1 = ZwSetValueKey(local_28,&g_GlobMergerIsEnabledValue,0);
    if (-1 < iVar1) {
      if (local_28 != 0) {
        ZwClose();
      }
      return 0;
    }
    local_68 = 0x4b;
    local_60 = 
    "ZwSetValueKey( Handle.get(), &g_GlobMergerIsEnabledValue, 0, ( 4ul ), &dwValue, sizeof(DWORD))"
    ;
  }
  local_70 = "SetGlobMergerIsEnabledRegKey";
  local_78 = "onecore\\base\\servicing\\globmerger\\kernel\\cimloader.cpp";
  RtlReportErrorOrigination(&local_78,p_Var2,iVar1);
  if (local_28 != 0) {
    ZwClose();
  }
  return iVar1;
}



===== AppendGuid<Windows::AutoOperatorAmpersandHelper<_UNICODE_STRING,Windows::Auto<_UNICODE_STRING>_>_> @ 140006a04 =====

/* long __cdecl Windows::StringUtil::Rtl::AppendGuid<class
   Windows::AutoOperatorAmpersandHelper<struct _UNICODE_STRING,class Windows::Auto<struct
   _UNICODE_STRING> > >(unsigned long,struct _GUID const & __ptr64,class
   Windows::AutoOperatorAmpersandHelper<struct _UNICODE_STRING,class Windows::Auto<struct
   _UNICODE_STRING> >) */

long __cdecl
Windows::StringUtil::Rtl::
AppendGuid<Windows::AutoOperatorAmpersandHelper<_UNICODE_STRING,Windows::Auto<_UNICODE_STRING>_>_>
          (uint param_1,ulong *param_2,undefined8 *param_3)

{
  ushort uVar1;
  Auto<_UNICODE_STRING> *pAVar2;
  uint uVar3;
  long lVar4;
  ushort uVar5;
  
  pAVar2 = (Auto<_UNICODE_STRING> *)*param_3;
  uVar1 = *(ushort *)pAVar2;
  uVar5 = ((ushort)(param_1 >> 1) & 2) + (-(ushort)((param_1 & 8) != 0) & 0xfffc) + 0x4c;
  if ((ulonglong)*(ushort *)(pAVar2 + 2) - (ulonglong)uVar1 < (ulonglong)uVar5) {
    uVar5 = uVar5 + uVar1;
    if (uVar5 < uVar1) {
      return -0x3fffff6b;
    }
    uVar3 = RtlReallocateUnicodeString
                      ((ulonglong)*(ushort *)(pAVar2 + 2) - (ulonglong)uVar1,(ulonglong)uVar5,
                       (ushort *)pAVar2);
    if ((int)uVar3 < 0) {
      return uVar3;
    }
  }
  if ((param_1 & 8) == 0) {
    *(undefined2 *)(*(longlong *)(pAVar2 + 8) + (ulonglong)(*(ushort *)pAVar2 >> 1) * 2) = 0x7b;
    *(short *)pAVar2 = *(short *)pAVar2 + 2;
  }
  uVar3 = (param_1 & 2) << 3 | 9;
  lVar4 = AppendInteger<Windows::Auto<_UNICODE_STRING>*___ptr64,unsigned_long>
                    (uVar3,*param_2,pAVar2);
  if (-1 < lVar4) {
    *(undefined2 *)(*(longlong *)(pAVar2 + 8) + (ulonglong)(*(ushort *)pAVar2 >> 1) * 2) = 0x2d;
    *(short *)pAVar2 = *(short *)pAVar2 + 2;
    lVar4 = AppendInteger<Windows::Auto<_UNICODE_STRING>*___ptr64,unsigned_short>
                      (uVar3,(ushort)param_2[1],pAVar2);
    if (-1 < lVar4) {
      *(undefined2 *)(*(longlong *)(pAVar2 + 8) + (ulonglong)(*(ushort *)pAVar2 >> 1) * 2) = 0x2d;
      *(short *)pAVar2 = *(short *)pAVar2 + 2;
      lVar4 = AppendInteger<Windows::Auto<_UNICODE_STRING>*___ptr64,unsigned_short>
                        (uVar3,*(ushort *)((longlong)param_2 + 6),pAVar2);
      if (-1 < lVar4) {
        *(undefined2 *)(*(longlong *)(pAVar2 + 8) + (ulonglong)(*(ushort *)pAVar2 >> 1) * 2) = 0x2d;
        *(short *)pAVar2 = *(short *)pAVar2 + 2;
        lVar4 = AppendInteger<Windows::Auto<_UNICODE_STRING>*___ptr64,unsigned_char>
                          (uVar3,(uchar)param_2[2],pAVar2);
        if ((-1 < lVar4) &&
           (lVar4 = AppendInteger<Windows::Auto<_UNICODE_STRING>*___ptr64,unsigned_char>
                              (uVar3,*(uchar *)((longlong)param_2 + 9),pAVar2), -1 < lVar4)) {
          *(undefined2 *)(*(longlong *)(pAVar2 + 8) + (ulonglong)(*(ushort *)pAVar2 >> 1) * 2) =
               0x2d;
          *(short *)pAVar2 = *(short *)pAVar2 + 2;
          lVar4 = AppendInteger<Windows::Auto<_UNICODE_STRING>*___ptr64,unsigned_char>
                            (uVar3,*(uchar *)((longlong)param_2 + 10),pAVar2);
          if (((-1 < lVar4) &&
              (((lVar4 = AppendInteger<Windows::Auto<_UNICODE_STRING>*___ptr64,unsigned_char>
                                   (uVar3,*(uchar *)((longlong)param_2 + 0xb),pAVar2), -1 < lVar4 &&
                (lVar4 = AppendInteger<Windows::Auto<_UNICODE_STRING>*___ptr64,unsigned_char>
                                   (uVar3,(uchar)param_2[3],pAVar2), -1 < lVar4)) &&
               (lVar4 = AppendInteger<Windows::Auto<_UNICODE_STRING>*___ptr64,unsigned_char>
                                  (uVar3,*(uchar *)((longlong)param_2 + 0xd),pAVar2), -1 < lVar4))))
             && ((lVar4 = AppendInteger<Windows::Auto<_UNICODE_STRING>*___ptr64,unsigned_char>
                                    (uVar3,*(uchar *)((longlong)param_2 + 0xe),pAVar2), -1 < lVar4
                 && (lVar4 = AppendInteger<Windows::Auto<_UNICODE_STRING>*___ptr64,unsigned_char>
                                       (uVar3,*(uchar *)((longlong)param_2 + 0xf),pAVar2),
                    -1 < lVar4)))) {
            if ((param_1 & 8) == 0) {
              *(undefined2 *)(*(longlong *)(pAVar2 + 8) + (ulonglong)(*(ushort *)pAVar2 >> 1) * 2) =
                   0x7d;
              *(short *)pAVar2 = *(short *)pAVar2 + 2;
            }
            if ((param_1 & 4) != 0) {
              *(undefined2 *)(*(longlong *)(pAVar2 + 8) + (ulonglong)(*(ushort *)pAVar2 >> 1) * 2) =
                   0;
            }
            lVar4 = 0;
          }
        }
      }
    }
  }
  return lVar4;
}



===== AppendInteger<Windows::Auto<_UNICODE_STRING>*___ptr64,unsigned_char> @ 140006c20 =====

/* long __cdecl Windows::StringUtil::Rtl::AppendInteger<class Windows::Auto<struct _UNICODE_STRING>
   * __ptr64,unsigned char>(unsigned long,unsigned char,class Windows::Auto<struct _UNICODE_STRING>
   * __ptr64) */

long __cdecl
Windows::StringUtil::Rtl::AppendInteger<Windows::Auto<_UNICODE_STRING>*___ptr64,unsigned_char>
          (ulong param_1,uchar param_2,Auto<_UNICODE_STRING> *param_3)

{
  short sVar1;
  ulonglong uVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  ushort uVar6;
  ushort uVar7;
  char cVar8;
  byte bVar9;
  int iVar10;
  longlong lVar11;
  ulonglong uVar12;
  char cVar13;
  
  uVar12 = (ulonglong)param_2;
  cVar13 = '\0';
  iVar10 = (-(uint)((param_1 & 1) != 0) & 6) + 10;
  uVar5 = uVar12;
  do {
    cVar13 = cVar13 + '\x01';
    uVar2 = (longlong)(int)uVar5 / (longlong)iVar10;
    uVar5 = uVar2 & 0xffffffff;
  } while ((int)uVar2 != 0);
  cVar8 = '\0';
  if ((param_1 & 8) != 0) {
    iVar3 = 0xff;
    do {
      cVar8 = cVar8 + '\x01';
      iVar3 = iVar3 / iVar10;
    } while (iVar3 != 0);
    cVar8 = cVar8 - cVar13;
  }
  uVar7 = *(ushort *)param_3;
  uVar6 = (-(ushort)((param_1 & 4) != 0) & 2) + (-(ushort)((param_1 & 2) != 0) & 4) + cVar8 * 2 +
          cVar13 * 2;
  if ((ulonglong)*(ushort *)(param_3 + 2) - (ulonglong)uVar7 < (ulonglong)uVar6) {
    uVar6 = uVar6 + uVar7;
    if (uVar6 < uVar7) {
      return -0x3fffff6b;
    }
    uVar4 = RtlReallocateUnicodeString
                      ((ulonglong)*(ushort *)(param_3 + 2) - (ulonglong)uVar7,(ulonglong)uVar6,
                       (ushort *)param_3);
    if ((int)uVar4 < 0) {
      return uVar4;
    }
  }
  if (((param_1 & 1) != 0) && ((param_1 & 2) != 0)) {
    *(undefined2 *)(*(longlong *)(param_3 + 8) + (ulonglong)(*(ushort *)param_3 >> 1) * 2) = 0x30;
    sVar1 = *(short *)param_3;
    *(ushort *)param_3 = sVar1 + 2U;
    *(undefined2 *)(*(longlong *)(param_3 + 8) + (ulonglong)((ushort)(sVar1 + 2U) >> 1) * 2) = 0x78;
    *(short *)param_3 = *(short *)param_3 + 2;
  }
  for (; cVar8 != '\0'; cVar8 = cVar8 + -1) {
    *(undefined2 *)(*(longlong *)(param_3 + 8) + (ulonglong)(*(ushort *)param_3 >> 1) * 2) = 0x30;
    *(short *)param_3 = *(short *)param_3 + 2;
  }
  uVar4 = (-(uint)((param_1 & 1) != 0) & 6) + 10;
  lVar11 = (longlong)(int)((int)cVar13 + ((*(ushort *)param_3 >> 1) - 1)) * 2;
  do {
    uVar5 = uVar12 % (ulonglong)uVar4;
    uVar12 = uVar12 / uVar4;
    bVar9 = (byte)uVar5;
    if ((param_1 & 0x10) == 0) {
      sVar1 = (short)uVar5;
      uVar7 = sVar1 + 0x30;
      if (9 < bVar9) {
        uVar7 = sVar1 + 0x57;
      }
    }
    else {
      cVar8 = '0';
      if (9 < bVar9) {
        cVar8 = '7';
      }
      uVar7 = (ushort)(byte)(cVar8 + bVar9);
    }
    *(ushort *)(lVar11 + *(longlong *)(param_3 + 8)) = uVar7;
    lVar11 = lVar11 + -2;
  } while ((char)uVar12 != '\0');
  uVar7 = cVar13 * 2 + *(short *)param_3;
  *(ushort *)param_3 = uVar7;
  if ((param_1 & 4) != 0) {
    *(undefined2 *)(*(longlong *)(param_3 + 8) + (ulonglong)(uVar7 >> 1) * 2) = 0;
  }
  return 0;
}



===== AppendInteger<Windows::Auto<_UNICODE_STRING>*___ptr64,unsigned_short> @ 140006e38 =====

/* long __cdecl Windows::StringUtil::Rtl::AppendInteger<class Windows::Auto<struct _UNICODE_STRING>
   * __ptr64,unsigned short>(unsigned long,unsigned short,class Windows::Auto<struct
   _UNICODE_STRING> * __ptr64) */

long __cdecl
Windows::StringUtil::Rtl::AppendInteger<Windows::Auto<_UNICODE_STRING>*___ptr64,unsigned_short>
          (ulong param_1,ushort param_2,Auto<_UNICODE_STRING> *param_3)

{
  short sVar1;
  ulonglong uVar2;
  uint uVar3;
  int iVar4;
  ushort uVar5;
  ushort uVar6;
  char cVar7;
  byte bVar8;
  int iVar9;
  longlong lVar10;
  uint uVar11;
  char cVar12;
  
  uVar11 = (uint)param_2;
  cVar12 = '\0';
  iVar9 = (-(uint)((param_1 & 1) != 0) & 6) + 10;
  uVar3 = uVar11;
  do {
    cVar12 = cVar12 + '\x01';
    uVar3 = (int)uVar3 / iVar9;
  } while (uVar3 != 0);
  cVar7 = '\0';
  if ((param_1 & 8) != 0) {
    iVar4 = 0xffff;
    do {
      cVar7 = cVar7 + '\x01';
      iVar4 = iVar4 / iVar9;
    } while (iVar4 != 0);
    cVar7 = cVar7 - cVar12;
  }
  uVar6 = *(ushort *)param_3;
  uVar5 = (-(ushort)((param_1 & 4) != 0) & 2) + (-(ushort)((param_1 & 2) != 0) & 4) + cVar7 * 2 +
          cVar12 * 2;
  if ((ulonglong)*(ushort *)(param_3 + 2) - (ulonglong)uVar6 < (ulonglong)uVar5) {
    uVar5 = uVar5 + uVar6;
    if (uVar5 < uVar6) {
      return -0x3fffff6b;
    }
    uVar3 = RtlReallocateUnicodeString
                      ((ulonglong)*(ushort *)(param_3 + 2) - (ulonglong)uVar6,(ulonglong)uVar5,
                       (ushort *)param_3);
    if ((int)uVar3 < 0) {
      return uVar3;
    }
  }
  if (((param_1 & 1) != 0) && ((param_1 & 2) != 0)) {
    *(undefined2 *)(*(longlong *)(param_3 + 8) + (ulonglong)(*(ushort *)param_3 >> 1) * 2) = 0x30;
    sVar1 = *(short *)param_3;
    *(ushort *)param_3 = sVar1 + 2U;
    *(undefined2 *)(*(longlong *)(param_3 + 8) + (ulonglong)((ushort)(sVar1 + 2U) >> 1) * 2) = 0x78;
    *(short *)param_3 = *(short *)param_3 + 2;
  }
  for (; cVar7 != '\0'; cVar7 = cVar7 + -1) {
    *(undefined2 *)(*(longlong *)(param_3 + 8) + (ulonglong)(*(ushort *)param_3 >> 1) * 2) = 0x30;
    *(short *)param_3 = *(short *)param_3 + 2;
  }
  uVar3 = (-(uint)((param_1 & 1) != 0) & 6) + 10;
  lVar10 = (longlong)(int)((int)cVar12 + ((*(ushort *)param_3 >> 1) - 1)) * 2;
  do {
    uVar2 = (ulonglong)uVar11 % (ulonglong)uVar3;
    uVar11 = uVar11 / uVar3;
    bVar8 = (byte)uVar2;
    if ((param_1 & 0x10) == 0) {
      sVar1 = (short)uVar2;
      uVar6 = sVar1 + 0x30;
      if (9 < bVar8) {
        uVar6 = sVar1 + 0x57;
      }
    }
    else {
      cVar7 = '0';
      if (9 < bVar8) {
        cVar7 = '7';
      }
      uVar6 = (ushort)(byte)(cVar7 + bVar8);
    }
    *(ushort *)(lVar10 + *(longlong *)(param_3 + 8)) = uVar6;
    lVar10 = lVar10 + -2;
  } while ((short)uVar11 != 0);
  uVar6 = cVar12 * 2 + *(short *)param_3;
  *(ushort *)param_3 = uVar6;
  if ((param_1 & 4) != 0) {
    *(undefined2 *)(*(longlong *)(param_3 + 8) + (ulonglong)(uVar6 >> 1) * 2) = 0;
  }
  return 0;
}



===== AppendInteger<Windows::Auto<_UNICODE_STRING>*___ptr64,unsigned_long> @ 140007054 =====

/* long __cdecl Windows::StringUtil::Rtl::AppendInteger<class Windows::Auto<struct _UNICODE_STRING>
   * __ptr64,unsigned long>(unsigned long,unsigned long,class Windows::Auto<struct _UNICODE_STRING>
   * __ptr64) */

long __cdecl
Windows::StringUtil::Rtl::AppendInteger<Windows::Auto<_UNICODE_STRING>*___ptr64,unsigned_long>
          (ulong param_1,ulong param_2,Auto<_UNICODE_STRING> *param_3)

{
  short sVar1;
  ulong uVar2;
  ulonglong uVar3;
  byte bVar4;
  ushort uVar5;
  ushort uVar6;
  char cVar7;
  uint uVar8;
  longlong lVar9;
  char cVar10;
  
  cVar10 = '\0';
  uVar8 = (-(uint)((param_1 & 1) != 0) & 6) + 10;
  uVar2 = param_2;
  do {
    cVar10 = cVar10 + '\x01';
    uVar2 = uVar2 / uVar8;
  } while (uVar2 != 0);
  cVar7 = '\0';
  if ((param_1 & 8) != 0) {
    uVar3 = 0xffffffff;
    do {
      cVar7 = cVar7 + '\x01';
      uVar3 = uVar3 / uVar8;
    } while ((int)uVar3 != 0);
    cVar7 = cVar7 - cVar10;
  }
  uVar6 = *(ushort *)param_3;
  uVar5 = (-(ushort)((param_1 & 4) != 0) & 2) + (-(ushort)((param_1 & 2) != 0) & 4) + cVar7 * 2 +
          cVar10 * 2;
  if ((ulonglong)*(ushort *)(param_3 + 2) - (ulonglong)uVar6 < (ulonglong)uVar5) {
    uVar5 = uVar5 + uVar6;
    if (uVar5 < uVar6) {
      return -0x3fffff6b;
    }
    uVar8 = RtlReallocateUnicodeString
                      ((ulonglong)*(ushort *)(param_3 + 2) - (ulonglong)uVar6,(ulonglong)uVar5,
                       (ushort *)param_3);
    if ((int)uVar8 < 0) {
      return uVar8;
    }
  }
  if (((param_1 & 1) != 0) && ((param_1 & 2) != 0)) {
    *(undefined2 *)(*(longlong *)(param_3 + 8) + (ulonglong)(*(ushort *)param_3 >> 1) * 2) = 0x30;
    sVar1 = *(short *)param_3;
    *(ushort *)param_3 = sVar1 + 2U;
    *(undefined2 *)(*(longlong *)(param_3 + 8) + (ulonglong)((ushort)(sVar1 + 2U) >> 1) * 2) = 0x78;
    *(short *)param_3 = *(short *)param_3 + 2;
  }
  for (; cVar7 != '\0'; cVar7 = cVar7 + -1) {
    *(undefined2 *)(*(longlong *)(param_3 + 8) + (ulonglong)(*(ushort *)param_3 >> 1) * 2) = 0x30;
    *(short *)param_3 = *(short *)param_3 + 2;
  }
  uVar8 = (-(uint)((param_1 & 1) != 0) & 6) + 10;
  lVar9 = (longlong)(int)(((*(ushort *)param_3 >> 1) - 1) + (int)cVar10) * 2;
  do {
    uVar3 = (ulonglong)param_2 % (ulonglong)uVar8;
    param_2 = param_2 / uVar8;
    bVar4 = (byte)uVar3;
    if ((param_1 & 0x10) == 0) {
      sVar1 = (short)uVar3;
      uVar6 = sVar1 + 0x30;
      if (9 < bVar4) {
        uVar6 = sVar1 + 0x57;
      }
    }
    else {
      cVar7 = '0';
      if (9 < bVar4) {
        cVar7 = '7';
      }
      uVar6 = (ushort)(byte)(cVar7 + bVar4);
    }
    *(ushort *)(lVar9 + *(longlong *)(param_3 + 8)) = uVar6;
    lVar9 = lVar9 + -2;
  } while (param_2 != 0);
  uVar6 = cVar10 * 2 + *(short *)param_3;
  *(ushort *)param_3 = uVar6;
  if ((param_1 & 4) != 0) {
    *(undefined2 *)(*(longlong *)(param_3 + 8) + (ulonglong)(uVar6 >> 1) * 2) = 0;
  }
  return 0;
}



===== AppendString<_LUNICODE_STRING,Windows::AutoOperatorAmpersandHelper<_UNICODE_STRING,Windows::Auto<_UNICODE_STRING>_>,0> @ 140007264 =====

/* long __cdecl Windows::StringUtil::Rtl::AppendString<struct _LUNICODE_STRING,class
   Windows::AutoOperatorAmpersandHelper<struct _UNICODE_STRING,class Windows::Auto<struct
   _UNICODE_STRING> >,0>(struct _LUNICODE_STRING const & __ptr64,class
   Windows::AutoOperatorAmpersandHelper<struct _UNICODE_STRING,class Windows::Auto<struct
   _UNICODE_STRING> >) */

long __cdecl
Windows::StringUtil::Rtl::
AppendString<_LUNICODE_STRING,Windows::AutoOperatorAmpersandHelper<_UNICODE_STRING,Windows::Auto<_UNICODE_STRING>_>,0>
          (ulonglong *param_1,undefined8 *param_2)

{
  void *_Src;
  ushort uVar1;
  ushort *puVar2;
  ulonglong _Size;
  uint uVar3;
  long lVar4;
  ulonglong uVar5;
  ushort uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  
  puVar2 = (ushort *)*param_2;
  _Size = *param_1;
  _Src = (void *)param_1[2];
  uVar1 = *puVar2;
  uVar8 = (ulonglong)uVar1;
  if (puVar2[1] - uVar8 < _Size) {
    uVar7 = 0;
    if (_Size < 0x10000) {
      uVar7 = _Size & 0xffff;
      uVar5 = (ulonglong)(-(uint)(_Size != uVar7) & 0xc00000e5);
    }
    else {
      uVar5 = 0xc0000095;
    }
    if ((char)(uVar5 >> 0x18) < '\0') {
LAB_1400072ed:
      if (-1 < (int)uVar5) goto LAB_1400072f1;
    }
    else {
      uVar6 = (short)uVar7 + uVar1;
      uVar8 = (ulonglong)uVar6;
      uVar3 = -(uint)(uVar6 < uVar1);
      uVar5 = (ulonglong)(uVar3 & 0xc0000095);
      if ((int)uVar3 < 0) goto LAB_1400072ed;
LAB_1400072f1:
      uVar3 = RtlReallocateUnicodeString(uVar5,uVar8,puVar2);
      uVar5 = (ulonglong)uVar3;
      if (-1 < (int)uVar3) goto LAB_140007307;
    }
    lVar4 = (long)uVar5;
  }
  else {
LAB_140007307:
    puVar2 = (ushort *)*param_2;
    if (_Size != 0) {
      if ((ulonglong)puVar2[1] - (ulonglong)*puVar2 < _Size) {
                    /* WARNING: Subroutine does not return */
        ExRaiseStatus(0xc00000e5);
      }
      memmove((void *)(*(longlong *)(puVar2 + 4) + (ulonglong)(*puVar2 >> 1) * 2),_Src,_Size);
      *puVar2 = *puVar2 + (short)_Size;
    }
    lVar4 = 0;
  }
  return lVar4;
}



===== AppendTranscodedString<_LUTF8_STRING,Windows::AutoOperatorAmpersandHelper<_UNICODE_STRING,Windows::Auto<_UNICODE_STRING>_>,&unsigned_long___cdecl_Windows::StringUtil::Impl::IdentityTransform(unsigned_long)> @ 140007368 =====

/* long __cdecl Windows::StringUtil::Rtl::Impl::AppendTranscodedString<struct _LUTF8_STRING,class
   Windows::AutoOperatorAmpersandHelper<struct _UNICODE_STRING,class Windows::Auto<struct
   _UNICODE_STRING> >,&unsigned long __cdecl Windows::StringUtil::Impl::IdentityTransform(unsigned
   long)>(struct _LUTF8_STRING const & __ptr64,class Windows::AutoOperatorAmpersandHelper<struct
   _UNICODE_STRING,class Windows::Auto<struct _UNICODE_STRING> >) */

long __cdecl
Windows::StringUtil::Rtl::Impl::
AppendTranscodedString<_LUTF8_STRING,Windows::AutoOperatorAmpersandHelper<_UNICODE_STRING,Windows::Auto<_UNICODE_STRING>_>,&unsigned_long___cdecl_Windows::StringUtil::Impl::IdentityTransform(unsigned_long)>
          (longlong *param_1,undefined8 *param_2)

{
  byte bVar1;
  ushort *puVar2;
  uint uVar3;
  undefined8 *puVar4;
  uint uVar5;
  ulonglong uVar6;
  ushort uVar7;
  int iVar8;
  char **ppcVar9;
  byte *pbVar10;
  uint uVar11;
  ushort *puVar12;
  byte *pbVar13;
  uint uVar14;
  byte *pbVar15;
  ushort uVar16;
  ushort *puVar17;
  uint local_d8 [2];
  byte *local_d0;
  char *local_c8;
  char *local_c0;
  undefined8 local_b8;
  char *local_b0;
  ushort *local_a8;
  char *local_a0;
  undefined8 local_98;
  char *local_90;
  undefined8 *local_88;
  char *local_80;
  char *local_78;
  undefined8 local_70;
  char *local_68;
  char *local_60;
  char *local_58;
  undefined8 local_50;
  undefined8 local_48;
  
  pbVar10 = (byte *)param_1[2];
  pbVar15 = pbVar10 + *param_1;
  uVar14 = 0;
  uVar5 = 0xc0000095;
  local_88 = param_2;
  if (pbVar10 != pbVar15) {
    do {
      uVar16 = (ushort)uVar14;
      if ((char)*pbVar10 < '\0') {
        RtlDecodeUtf8(local_d8,pbVar10,pbVar15);
        pbVar13 = local_d0;
        if (local_d8[0] == 0xffffffff) {
          uVar11 = (uint)local_d0;
          if (-1 < (int)uVar11) {
                    /* WARNING: Subroutine does not return */
            ExRaiseStatus(0xc00000e5);
          }
          local_b8 = 0xa79;
          local_c0 = "Windows::StringUtil::Rtl::Impl::CalculateEncodingLengthForString";
          local_b0 = "__rv.UcsCharacter != (0xffffffff)";
          goto LAB_140007515;
        }
        uVar6 = RtlGetEncodingSizeUtf16(local_d8[0]);
        param_2 = (undefined8 *)0x0;
        local_a8 = (ushort *)((ulonglong)local_a8 & 0xffffffff);
        iVar8 = 0;
        if (uVar6 < 0x10000) {
          iVar8 = (int)(uVar6 & 0xffff);
          uVar11 = -(uint)(uVar6 != (uVar6 & 0xffff)) & 0xc00000e5;
        }
        else {
          uVar11 = 0xc0000095;
        }
        if (-1 < (int)uVar11) {
          uVar14 = uVar14 + iVar8;
          uVar3 = -(uint)((ushort)uVar14 < uVar16);
          uVar11 = uVar3 & 0xc0000095;
          if (-1 < (int)uVar3) goto LAB_140007440;
        }
        if ((int)uVar11 < 0) goto LAB_140007525;
      }
      else {
        pbVar13 = pbVar10 + 1;
        uVar14 = uVar14 + 2;
      }
LAB_140007440:
      if ((ushort)uVar14 <= uVar16) {
        local_98 = 0xa7c;
        local_a8 = (ushort *)0x140012420;
        local_a0 = "Windows::StringUtil::Rtl::Impl::CalculateEncodingLengthForString";
        local_90 = "NewTempBytesRequired > TempBytesRequired";
        RtlReportErrorOrigination(&local_a8,param_2,-0x3fffff6b);
        uVar11 = 0xc0000095;
        goto LAB_140007525;
      }
      uVar14 = uVar14 & 0xffff;
      pbVar10 = pbVar13;
    } while (pbVar13 != pbVar15);
  }
  puVar4 = local_88;
  puVar2 = (ushort *)*local_88;
  uVar16 = *puVar2;
  pbVar10 = (byte *)(ulonglong)uVar16;
  if ((ulonglong)puVar2[1] - (longlong)pbVar10 < (ulonglong)uVar14) {
    uVar7 = (short)uVar14 + uVar16;
    if (uVar7 < uVar16) goto LAB_1400075b2;
    pbVar10 = (byte *)(ulonglong)uVar7;
    uVar5 = RtlReallocateUnicodeString((ulonglong)uVar7,(ulonglong)pbVar10,puVar2);
    if ((int)uVar5 < 0) goto LAB_1400075b2;
  }
  puVar2 = (ushort *)*puVar4;
  pbVar15 = (byte *)param_1[2];
  pbVar13 = pbVar15 + *param_1;
  puVar17 = (ushort *)
            ((ulonglong)puVar2[1] + (longlong)(*(longlong *)(puVar2 + 4) + (ulonglong)*puVar2));
  puVar12 = (ushort *)(*(longlong *)(puVar2 + 4) + (ulonglong)*puVar2);
  do {
    while( true ) {
      if (pbVar15 == pbVar13) {
        *puVar2 = (short)puVar12 - puVar2[4];
        return 0;
      }
      bVar1 = *pbVar15;
      if (puVar17 <= puVar12) {
        local_50 = 0xa9e;
        local_60 = "OneCore\\Internal\\Base\\inc\\rtlstringutil.h";
        local_48 = 0;
        local_58 = "Windows::StringUtil::Rtl::Impl::AppendTranscodedStringToPreallocatedBuffer";
        RtlReportErrorOrigination(&local_60,pbVar10,-0x7ffffffb);
        uVar11 = 0x80000005;
        goto LAB_140007525;
      }
      if ((char)bVar1 < '\0') break;
      pbVar15 = pbVar15 + 1;
      *puVar12 = (ushort)bVar1;
      puVar12 = puVar12 + 1;
    }
    RtlDecodeUtf8(local_d8,pbVar15,pbVar13);
    pbVar15 = local_d0;
    pbVar10 = (byte *)(ulonglong)local_d8[0];
    if (local_d8[0] == 0xffffffff) {
      uVar11 = (uint)local_d0;
      if (-1 < (int)uVar11) {
                    /* WARNING: Subroutine does not return */
        ExRaiseStatus(0xc00000e5);
      }
      local_70 = 0xaaa;
      local_80 = "OneCore\\Internal\\Base\\inc\\rtlstringutil.h";
      ppcVar9 = &local_80;
      local_78 = "Windows::StringUtil::Rtl::Impl::AppendTranscodedStringToPreallocatedBuffer";
      local_68 = "__rv.UcsCharacter != (0xffffffff)";
      goto LAB_14000751d;
    }
    RtlEncodeUtf16LE((longlong *)&local_a8,local_d8[0],(short *)puVar12,(longlong)puVar17);
    puVar12 = local_a8;
  } while (local_a8 != (ushort *)0x0);
  if (-1 < (int)(uint)local_a0) {
                    /* WARNING: Subroutine does not return */
    ExRaiseStatus(0xc00000e5);
  }
  local_b8 = 0xaab;
  local_c0 = "Windows::StringUtil::Rtl::Impl::AppendTranscodedStringToPreallocatedBuffer";
  local_b0 = "__rv.NewCursorValue != 0";
  uVar11 = (uint)local_a0;
LAB_140007515:
  local_c8 = "OneCore\\Internal\\Base\\inc\\rtlstringutil.h";
  ppcVar9 = &local_c8;
LAB_14000751d:
  RtlReportErrorOrigination(ppcVar9,pbVar10,uVar11);
LAB_140007525:
  uVar5 = uVar11;
LAB_1400075b2:
  return uVar5;
}



===== ~CVector<Windows::Auto<_UNICODE_STRING>,BUCL::Rtl::CCallDisposition> @ 1400076a0 =====

/* public: __cdecl BUCL::CVector<class Windows::Auto<struct _UNICODE_STRING>,class
   BUCL::Rtl::CCallDisposition>::~CVector<class Windows::Auto<struct _UNICODE_STRING>,class
   BUCL::Rtl::CCallDisposition>(void) __ptr64 */

void __thiscall
BUCL::CVector<Windows::Auto<_UNICODE_STRING>,BUCL::Rtl::CCallDisposition>::
~CVector<Windows::Auto<_UNICODE_STRING>,BUCL::Rtl::CCallDisposition>
          (CVector<Windows::Auto<_UNICODE_STRING>,BUCL::Rtl::CCallDisposition> *this)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(this + 8);
  lVar2 = *(longlong *)this;
  while (lVar2 != lVar1) {
    if (*(longlong *)(lVar1 + -8) != 0) {
      RtlDeallocateUnicodeString(lVar1 + -0x10);
      *(undefined8 *)(lVar1 + -0x10) = 0;
      *(undefined8 *)(lVar1 + -8) = 0;
    }
    lVar1 = *(longlong *)(this + 8) + -0x10;
    *(longlong *)(this + 8) = lVar1;
    lVar2 = *(longlong *)this;
  }
  if (lVar2 != 0) {
    ExFreePoolWithTag(lVar2,0);
  }
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)this = 0;
  return;
}



===== FreeBootLayers @ 140007718 =====

/* void __cdecl Compositefs::FreeBootLayers(struct _UNICODE_STRING * __ptr64 const,unsigned long) */

void __cdecl Compositefs::FreeBootLayers(_UNICODE_STRING *param_1,ulong param_2)

{
  ulonglong uVar1;
  undefined8 local_18;
  undefined8 uStack_10;
  
  if (param_2 != 0) {
    uVar1 = (ulonglong)param_2;
    do {
      local_18 = *(undefined8 *)param_1;
      uStack_10 = *(undefined8 *)(param_1 + 8);
      if (*(longlong *)(param_1 + 8) != 0) {
        RtlDeallocateUnicodeString((longlong)&local_18);
      }
      param_1 = param_1 + 0x10;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  return;
}



===== GetBootLayerPath @ 140007760 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl Compositefs::GetBootLayerPath(struct Compositefs::Layer const & __ptr64,class
   Windows::Auto<struct _UNICODE_STRING> & __ptr64) */

long __cdecl Compositefs::GetBootLayerPath(Layer *param_1,Auto<_UNICODE_STRING> *param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  int iVar3;
  long lVar4;
  undefined1 auStack_88 [32];
  undefined8 *local_68;
  char *local_60;
  char *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_38;
  longlong lStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_88;
  local_38 = 0;
  lStack_30 = 0;
  if (*(int *)param_1 == 1) {
    local_68 = &local_38;
    lVar4 = Windows::StringUtil::Rtl::
            AppendString<_LUNICODE_STRING,Windows::AutoOperatorAmpersandHelper<_UNICODE_STRING,Windows::Auto<_UNICODE_STRING>_>,0>
                      (&DAT_140012160,&local_68);
    if (lVar4 < 0) {
      if (lStack_30 != 0) {
        RtlDeallocateUnicodeString((longlong)&local_38);
      }
      return lVar4;
    }
    local_68 = &local_38;
    iVar3 = Windows::StringUtil::Rtl::
            AppendGuid<Windows::AutoOperatorAmpersandHelper<_UNICODE_STRING,Windows::Auto<_UNICODE_STRING>_>_>
                      (8,param_1 + 8,&local_68);
  }
  else {
    if (*(int *)param_1 != 2) {
      local_48 = 0;
      local_60 = "onecore\\base\\servicing\\globmerger\\kernel\\compositefs.cpp";
      local_50 = 0x84;
      local_58 = "Compositefs::GetBootLayerPath";
      RtlReportErrorOrigination(&local_60,param_2,-0x3ffffff3);
      if (lStack_30 != 0) {
        RtlDeallocateUnicodeString((longlong)&local_38);
      }
      return -0x3ffffff3;
    }
    iVar3 = GetVolumeDevicePathFromArcName
                      (*(char **)(param_1 + 8),(Auto<_UNICODE_STRING> *)&local_38);
  }
  if (iVar3 < 0) {
    if (lStack_30 != 0) {
      RtlDeallocateUnicodeString((longlong)&local_38);
    }
  }
  else {
    uVar1 = *(undefined8 *)param_2;
    lVar2 = *(longlong *)(param_2 + 8);
    *(undefined8 *)param_2 = local_38;
    *(longlong *)(param_2 + 8) = lStack_30;
    if (lVar2 != 0) {
      local_38 = uVar1;
      lStack_30 = lVar2;
      RtlDeallocateUnicodeString((longlong)&local_38);
    }
    iVar3 = 0;
  }
  return iVar3;
}



===== GetBootLayers @ 1400078a4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* long __cdecl Compositefs::GetBootLayers(struct _UNICODE_STRING * __ptr64,unsigned long * __ptr64)
    */

long __cdecl Compositefs::GetBootLayers(_UNICODE_STRING *param_1,ulong *param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  uint uVar9;
  ulonglong uVar10;
  longlong lVar11;
  int local_48 [2];
  undefined8 *local_40;
  undefined8 *puStack_38;
  undefined8 local_30;
  
  uVar4 = DAT_140017250;
  uVar8 = (ulonglong)DAT_140017250;
  if (*param_2 < DAT_140017250) {
    *param_2 = DAT_140017250;
    lVar6 = -0x3fffffdd;
  }
  else {
    local_30 = 0;
    local_40 = (undefined8 *)0x0;
    puStack_38 = (undefined8 *)0x0;
    if (DAT_140017250 != 0) {
      BUCL::CVector<Windows::Auto<_UNICODE_STRING>,BUCL::Rtl::CCallDisposition>::Reserve
                ((CVector<Windows::Auto<_UNICODE_STRING>,BUCL::Rtl::CCallDisposition> *)&local_40,
                 (__uint64)local_48);
      iVar5 = local_48[0];
      if (local_48[0] < 0) {
LAB_140007986:
        BUCL::CVector<Windows::Auto<_UNICODE_STRING>,BUCL::Rtl::CCallDisposition>::
        ~CVector<Windows::Auto<_UNICODE_STRING>,BUCL::Rtl::CCallDisposition>
                  ((CVector<Windows::Auto<_UNICODE_STRING>,BUCL::Rtl::CCallDisposition> *)&local_40)
        ;
        return iVar5;
      }
      do {
        if (puStack_38 != (undefined8 *)0x0) {
          *puStack_38 = 0;
          puStack_38[1] = 0;
        }
        puStack_38 = puStack_38 + 2;
      } while (uVar8 != (longlong)puStack_38 - (longlong)local_40 >> 4);
    }
    puVar7 = local_40;
    uVar10 = 0;
    if (uVar4 != 0) {
      do {
        iVar5 = GetBootLayerPath((Layer *)(uVar10 * 0x38 + _g_BootLayers),
                                 (Auto<_UNICODE_STRING> *)(puVar7 + uVar10 * 2));
        if (iVar5 < 0) goto LAB_140007986;
        uVar9 = (int)uVar10 + 1;
        uVar10 = (ulonglong)uVar9;
      } while (uVar9 < uVar4);
      lVar11 = (longlong)param_1 - (longlong)puVar7;
      do {
        uVar2 = *puVar7;
        uVar3 = puVar7[1];
        *puVar7 = 0;
        puVar7[1] = 0;
        puVar1 = (undefined8 *)((longlong)puVar7 + lVar11);
        *puVar1 = uVar2;
        puVar1[1] = uVar3;
        puVar7 = puVar7 + 2;
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
    }
    BUCL::CVector<Windows::Auto<_UNICODE_STRING>,BUCL::Rtl::CCallDisposition>::
    ~CVector<Windows::Auto<_UNICODE_STRING>,BUCL::Rtl::CCallDisposition>
              ((CVector<Windows::Auto<_UNICODE_STRING>,BUCL::Rtl::CCallDisposition> *)&local_40);
    lVar6 = 0;
    *param_2 = uVar4;
  }
  return lVar6;
}



===== GetVolumeDevicePathFromArcName @ 1400079b8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl Compositefs::GetVolumeDevicePathFromArcName(char const * __ptr64 const,class
   Windows::Auto<struct _UNICODE_STRING> & __ptr64) */

long __cdecl
Compositefs::GetVolumeDevicePathFromArcName(char *param_1,Auto<_UNICODE_STRING> *param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong *puVar4;
  ulonglong *puVar5;
  uint uVar6;
  undefined1 auStack_b8 [32];
  char *local_98;
  char *pcStack_90;
  ulonglong *local_88;
  char *local_80;
  char *local_78;
  char *pcStack_70;
  wchar_t *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong *local_48 [2];
  ulonglong local_38;
  longlong lStack_30;
  undefined4 local_28 [2];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_b8;
  local_38 = 0;
  lStack_30 = 0;
  uVar3 = RtlReallocateUnicodeString(param_1,0x104,(ushort *)&local_38);
  if (-1 < (int)uVar3) {
    local_48[0] = &local_38;
    local_78 = (char *)0x12;
    pcStack_70 = (char *)0x12;
    local_68 = L"\\ArcName\\";
    uVar3 = Windows::StringUtil::Rtl::
            AppendString<_LUNICODE_STRING,Windows::AutoOperatorAmpersandHelper<_UNICODE_STRING,Windows::Auto<_UNICODE_STRING>_>,0>
                      (&local_78,local_48);
    if (-1 < (int)uVar3) {
      local_68 = (wchar_t *)0x0;
      local_78 = (char *)0x0;
      pcStack_70 = (char *)0x0;
      if (param_1 != (char *)0x0) {
        local_78 = (char *)0xffffffffffffffff;
        do {
          pcStack_70 = local_78;
          local_78 = pcStack_70 + 1;
        } while (param_1[(longlong)local_78] != '\0');
        pcStack_70 = pcStack_70 + 2;
        local_68 = (wchar_t *)param_1;
      }
      local_48[0] = &local_38;
      local_88 = (ulonglong *)local_68;
      local_98 = local_78;
      pcStack_90 = pcStack_70;
      uVar3 = Windows::StringUtil::Rtl::Impl::
              AppendTranscodedString<_LUTF8_STRING,Windows::AutoOperatorAmpersandHelper<_UNICODE_STRING,Windows::Auto<_UNICODE_STRING>_>,&unsigned_long___cdecl_Windows::StringUtil::Impl::IdentityTransform(unsigned_long)>
                        (&local_98,local_48);
      if (-1 < (int)uVar3) {
        uVar6 = 0;
        while( true ) {
          local_68 = (wchar_t *)&local_38;
          local_78 = (char *)0x30;
          pcStack_70 = (char *)0x0;
          puVar5 = (ulonglong *)0x1;
          local_60 = 0x240;
          local_48[0] = (ulonglong *)0x0;
          local_58 = 0;
          uStack_50 = 0;
          uVar3 = ZwOpenSymbolicLinkObject(local_48,1,&local_78);
          if ((int)uVar3 < 0) break;
          puVar5 = &local_38;
          local_38 = local_38 & 0xffffffffffff0000;
          local_28[0] = 0;
          puVar4 = local_48[0];
          uVar3 = ZwQuerySymbolicLinkObject(local_48[0],puVar5,local_28);
          if (uVar3 == 0xc0000023) {
            uVar3 = RtlReallocateUnicodeString(puVar4,0x104,(ushort *)&local_38);
            if ((int)uVar3 < 0) goto LAB_140007c36;
            puVar5 = &local_38;
            uVar3 = ZwQuerySymbolicLinkObject(local_48[0],puVar5,local_28);
            if ((int)uVar3 < 0) {
              local_88 = (ulonglong *)0x63;
              local_80 = "ZwQuerySymbolicLinkObject(DeviceHandle.get(), &DevicePath, &Length)";
              goto LAB_140007c22;
            }
          }
          else if ((int)uVar3 < 0) {
            local_88 = (ulonglong *)0x5b;
            local_80 = "ZwQuerySymbolicLinkObject( DeviceHandle.get(), &DevicePath, &Length)";
            goto LAB_140007c22;
          }
          if (local_48[0] != (ulonglong *)0x0) {
            ZwClose();
          }
          uVar6 = uVar6 + 1;
          if (1 < uVar6) {
            uVar1 = *(ulonglong *)param_2;
            lVar2 = *(longlong *)(param_2 + 8);
            *(ulonglong *)param_2 = local_38;
            *(longlong *)(param_2 + 8) = lStack_30;
            if (lVar2 != 0) {
              local_38 = uVar1;
              lStack_30 = lVar2;
              RtlDeallocateUnicodeString((longlong)&local_38);
            }
            return 0;
          }
        }
        local_88 = (ulonglong *)0x4f;
        local_80 = "ZwOpenSymbolicLinkObject(&DeviceHandle, (0x0001), &ObjectAttributes)";
LAB_140007c22:
        pcStack_90 = "Compositefs::GetVolumeDevicePathFromArcName";
        local_98 = "onecore\\base\\servicing\\globmerger\\kernel\\compositefs.cpp";
        RtlReportErrorOrigination(&local_98,puVar5,uVar3);
LAB_140007c36:
        if (local_48[0] != (ulonglong *)0x0) {
          ZwClose();
        }
      }
      if (lStack_30 != 0) {
        RtlDeallocateUnicodeString((longlong)&local_38);
      }
      return uVar3;
    }
  }
  if (lStack_30 != 0) {
    RtlDeallocateUnicodeString((longlong)&local_38);
  }
  return uVar3;
}



===== MountBootLayers @ 140007c84 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* long __cdecl Compositefs::MountBootLayers(void * __ptr64,void * __ptr64) */

long __cdecl Compositefs::MountBootLayers(void *param_1,void *param_2)

{
  int iVar1;
  _GUID *p_Var2;
  Layer *pLVar3;
  Layer *pLVar4;
  undefined1 auStackY_158 [32];
  undefined8 local_e8;
  wchar_t *pwStack_e0;
  char *local_d8;
  char *local_d0;
  undefined8 local_c8;
  char *local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 *local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  longlong local_88 [2];
  undefined8 local_78;
  wchar_t *pwStack_70;
  char *local_68;
  char *local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_158;
  pLVar4 = _g_BootLayers + _DAT_140017250 * 0x38;
  p_Var2 = param_2;
  pLVar3 = _g_BootLayers;
  do {
    if (pLVar3 == pLVar4) {
      return 0;
    }
    local_78 = 0;
    pwStack_70 = (wchar_t *)0x0;
    local_e8 = 0;
    pwStack_e0 = (wchar_t *)0x0;
    if (*(int *)pLVar3 == 1) {
      if (pLVar3[0x28] == (Layer)0x0) {
        iVar1 = GetVolumeDevicePathFromArcName
                          (*(char **)(pLVar3 + 0x30),(Auto<_UNICODE_STRING> *)&local_e8);
        goto LAB_140007d24;
      }
      local_78 = 0x780078;
      pwStack_70 = L"\\Device\\vmsmb\\VSMB-{dcc079ae-60ba-4d07-847c-3493609c0870}\\os";
    }
    else {
      if (*(int *)pLVar3 != 2) {
        local_58 = 0xd5;
        local_68 = "onecore\\base\\servicing\\globmerger\\kernel\\compositefs.cpp";
        local_50 = 0;
        local_60 = "Compositefs::MountBootLayers";
        RtlReportErrorOrigination(&local_68,p_Var2,-0x3ffffff3);
        return -0x3ffffff3;
      }
      iVar1 = GetBootLayerPath(pLVar3,(Auto<_UNICODE_STRING> *)&local_e8);
LAB_140007d24:
      if (iVar1 < 0) goto LAB_140007f1c;
      local_78 = local_e8;
      pwStack_70 = pwStack_e0;
    }
    local_a8 = &local_78;
    local_b8 = 0x30;
    local_b0 = 0;
    local_a0 = 0x240;
    local_98 = 0;
    uStack_90 = 0;
    local_88[0] = 0;
    local_48 = 0;
    uStack_40 = 0;
    p_Var2 = param_2;
    iVar1 = FltCreateFile(param_1,param_2,local_88,0x80100000);
    if (iVar1 < 0) {
      local_c8 = 0xec;
      local_c0 = 
      "FltCreateFile( reinterpret_cast<PFLT_FILTER>(Filter), reinterpret_cast<PFLT_INSTANCE>(Instance), &DeviceHandle, (0x80000000L) | (0x00100000L), &ObjectAttributes, &IoStatusBlock, nullptr, 0, 0x00000001 | 0x00000002, 0x00000001, 0x00000020, nullptr, 0, 0)"
      ;
LAB_140007ef7:
      local_d0 = "Compositefs::MountBootLayers";
      local_d8 = "onecore\\base\\servicing\\globmerger\\kernel\\compositefs.cpp";
      RtlReportErrorOrigination(&local_d8,p_Var2,iVar1);
      if (local_88[0] != 0) {
        ZwClose();
      }
LAB_140007f1c:
      if (pwStack_e0 != (wchar_t *)0x0) {
        RtlDeallocateUnicodeString((longlong)&local_e8);
      }
      return iVar1;
    }
    if (*(int *)pLVar3 == 1) {
      local_68 = *(char **)(pLVar3 + 0x18);
      p_Var2 = (_GUID *)(pLVar3 + 8);
      local_60 = (char *)(ulonglong)*(uint *)(pLVar3 + 0x20);
      iVar1 = MountMergedCim(*(uint *)(pLVar3 + 0x24) | 0x10,p_Var2,(_UNICODE_STRING *)&local_78,
                             (Vector<_UNICODE_STRING_const_> *)&local_68,param_1,param_2);
      if (iVar1 < 0) {
        local_c8 = 0xfe;
        local_c0 = 
        "MountMergedCim( CimMountFlags, BootLayer.u.Cimfs.TargetVolume, VolumeToMount, CimFilesVector, Filter, Instance)"
        ;
        goto LAB_140007ef7;
      }
    }
    if (local_88[0] != 0) {
      ZwClose();
    }
    if (pwStack_e0 != (wchar_t *)0x0) {
      RtlDeallocateUnicodeString((longlong)&local_e8);
    }
    pLVar3 = pLVar3 + 0x38;
  } while( true );
}



===== Reserve @ 140007f3c =====

/* public: class BUCL::Rtl::CCallDisposition __cdecl BUCL::CVector<class Windows::Auto<struct
   _UNICODE_STRING>,class BUCL::Rtl::CCallDisposition>::Reserve(unsigned __int64) __ptr64 */

__uint64 __thiscall
BUCL::CVector<Windows::Auto<_UNICODE_STRING>,BUCL::Rtl::CCallDisposition>::Reserve
          (CVector<Windows::Auto<_UNICODE_STRING>,BUCL::Rtl::CCallDisposition> *this,
          __uint64 param_1)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  __uint64 *in_R8;
  int local_res8 [2];
  
  if ((__uint64 *)(*(longlong *)(this + 0x10) - *(longlong *)this >> 4) < in_R8) {
    Implementation::Multiply<BUCL::Rtl::CCallDisposition,unsigned___int64>
              ((__uint64)local_res8,0x10,in_R8);
    if (local_res8[0] < 0) {
      *(int *)param_1 = local_res8[0];
      return param_1;
    }
    puVar2 = operator_new(0);
    if (puVar2 == (undefined8 *)0x0) {
      *(undefined4 *)param_1 = 0xc0000017;
      return param_1;
    }
    puVar5 = puVar2;
    for (puVar4 = *(undefined8 **)this; puVar3 = *(undefined8 **)(this + 8), puVar4 != puVar3;
        puVar4 = puVar4 + 2) {
      if (puVar5 != (undefined8 *)0x0) {
        uVar1 = puVar4[1];
        *puVar5 = *puVar4;
        puVar5[1] = uVar1;
        *puVar4 = 0;
        puVar4[1] = 0;
      }
      puVar5 = puVar5 + 2;
    }
    puVar4 = *(undefined8 **)this;
    uVar6 = (longlong)puVar3 - (longlong)puVar4;
    while (puVar4 != puVar3) {
      if (puVar3[-1] != 0) {
        RtlDeallocateUnicodeString((longlong)(puVar3 + -2));
        puVar3[-2] = 0;
        puVar3[-1] = 0;
      }
      puVar3 = (undefined8 *)(*(longlong *)(this + 8) + -0x10);
      *(undefined8 **)(this + 8) = puVar3;
      puVar4 = *(undefined8 **)this;
    }
    if (puVar4 != (undefined8 *)0x0) {
      ExFreePoolWithTag(puVar4,0);
    }
    *(undefined8 **)this = puVar2;
    *(ulonglong *)(this + 8) = (uVar6 & 0xfffffffffffffff0) + (longlong)puVar2;
    *(undefined8 **)(this + 0x10) = puVar2 + (longlong)in_R8 * 2;
  }
  *(undefined4 *)param_1 = 0;
  return param_1;
}



===== SetBootInformation @ 140008060 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl Compositefs::SetBootInformation(struct Windows::Vector<struct Compositefs::Layer>
   const & __ptr64) */

void __cdecl Compositefs::SetBootInformation(Vector<Compositefs::Layer> *param_1)

{
  _g_BootLayers = *(undefined8 *)param_1;
  _DAT_140017250 = *(undefined8 *)(param_1 + 8);
  return;
}



===== Allocate<> @ 140008074 =====

/* public: class CmRegistryProvider * __ptr64 __cdecl Windows::AutoNewPtr<class
   CmRegistryProvider>::Allocate<>(void) __ptr64 */

CmRegistryProvider * __thiscall
Windows::AutoNewPtr<CmRegistryProvider>::Allocate<>(AutoNewPtr<CmRegistryProvider> *this)

{
  code *pcVar1;
  CmRegistryProvider *pCVar2;
  
  pCVar2 = (CmRegistryProvider *)ExAllocatePool2(0x40,0x78,0x4c467346);
  if (pCVar2 == (CmRegistryProvider *)0x0) {
    pCVar2 = (CmRegistryProvider *)0x0;
  }
  else {
    memset(pCVar2,0,0x78);
    *(undefined4 *)(pCVar2 + 8) = 1;
    *(undefined ***)pCVar2 = &CmRegistryProvider::_vftable_;
    *(undefined8 *)(pCVar2 + 0x10) = 0;
    *(undefined8 *)(pCVar2 + 0x18) = 0;
    *(undefined8 *)(pCVar2 + 0x20) = 0;
    *(undefined8 *)(pCVar2 + 0x28) = 0;
    *(undefined8 *)(pCVar2 + 0x30) = 0;
    *(undefined8 *)(pCVar2 + 0x38) = 0;
    *(undefined8 *)(pCVar2 + 0x40) = 0;
    *(undefined8 *)(pCVar2 + 0x48) = 0;
    *(undefined8 *)(pCVar2 + 0x50) = 0;
    *(undefined8 *)(pCVar2 + 0x58) = 0;
    *(undefined8 *)(pCVar2 + 0x60) = 0;
    *(undefined8 *)(pCVar2 + 0x68) = 0;
    *(undefined8 *)(pCVar2 + 0x70) = 0;
  }
  if (*(longlong *)this == 0) {
    *(CmRegistryProvider **)this = pCVar2;
    return pCVar2;
  }
  pcVar1 = (code *)swi(3);
  pCVar2 = (CmRegistryProvider *)(*pcVar1)();
  return pCVar2;
}



===== AppendGuid<Windows::AutoOperatorAmpersandHelper<_LUNICODE_STRING,Windows::Auto<_LUNICODE_STRING>_>_> @ 140008128 =====

/* long __cdecl Windows::StringUtil::Rtl::AppendGuid<class
   Windows::AutoOperatorAmpersandHelper<struct _LUNICODE_STRING,class Windows::Auto<struct
   _LUNICODE_STRING> > >(unsigned long,struct _GUID const & __ptr64,class
   Windows::AutoOperatorAmpersandHelper<struct _LUNICODE_STRING,class Windows::Auto<struct
   _LUNICODE_STRING> >) */

long __cdecl
Windows::StringUtil::Rtl::
AppendGuid<Windows::AutoOperatorAmpersandHelper<_LUNICODE_STRING,Windows::Auto<_LUNICODE_STRING>_>_>
          (undefined8 param_1,ulong *param_2,undefined8 *param_3)

{
  Auto<_LUNICODE_STRING> *pAVar1;
  ulonglong uVar2;
  int iVar3;
  long lVar4;
  
  pAVar1 = (Auto<_LUNICODE_STRING> *)*param_3;
  uVar2 = *(ulonglong *)pAVar1;
  if (*(longlong *)(pAVar1 + 8) - uVar2 < 0x4c) {
    if (uVar2 + 0x4c < uVar2) {
      return -0x3fffff6b;
    }
    iVar3 = RtlReallocateLUnicodeString(uVar2,uVar2 + 0x4c,(ulonglong *)pAVar1);
    if (iVar3 < 0) {
      return iVar3;
    }
  }
  *(undefined2 *)(*(longlong *)(pAVar1 + 0x10) + (*(ulonglong *)pAVar1 & 0xfffffffffffffffe)) = 0x7b
  ;
  *(longlong *)pAVar1 = *(longlong *)pAVar1 + 2;
  lVar4 = AppendInteger<Windows::Auto<_LUNICODE_STRING>*___ptr64,unsigned_long>(9,*param_2,pAVar1);
  if (-1 < lVar4) {
    *(undefined2 *)(*(longlong *)(pAVar1 + 0x10) + (*(ulonglong *)pAVar1 & 0xfffffffffffffffe)) =
         0x2d;
    *(longlong *)pAVar1 = *(longlong *)pAVar1 + 2;
    lVar4 = AppendInteger<Windows::Auto<_LUNICODE_STRING>*___ptr64,unsigned_short>
                      (9,(ushort)param_2[1],pAVar1);
    if (-1 < lVar4) {
      *(undefined2 *)(*(longlong *)(pAVar1 + 0x10) + (*(ulonglong *)pAVar1 & 0xfffffffffffffffe)) =
           0x2d;
      *(longlong *)pAVar1 = *(longlong *)pAVar1 + 2;
      lVar4 = AppendInteger<Windows::Auto<_LUNICODE_STRING>*___ptr64,unsigned_short>
                        (9,*(ushort *)((longlong)param_2 + 6),pAVar1);
      if (-1 < lVar4) {
        *(undefined2 *)(*(longlong *)(pAVar1 + 0x10) + (*(ulonglong *)pAVar1 & 0xfffffffffffffffe))
             = 0x2d;
        *(longlong *)pAVar1 = *(longlong *)pAVar1 + 2;
        lVar4 = AppendInteger<Windows::Auto<_LUNICODE_STRING>*___ptr64,unsigned_char>
                          (9,(uchar)param_2[2],pAVar1);
        if ((-1 < lVar4) &&
           (lVar4 = AppendInteger<Windows::Auto<_LUNICODE_STRING>*___ptr64,unsigned_char>
                              (9,*(uchar *)((longlong)param_2 + 9),pAVar1), -1 < lVar4)) {
          *(undefined2 *)
           (*(longlong *)(pAVar1 + 0x10) + (*(ulonglong *)pAVar1 & 0xfffffffffffffffe)) = 0x2d;
          *(longlong *)pAVar1 = *(longlong *)pAVar1 + 2;
          lVar4 = AppendInteger<Windows::Auto<_LUNICODE_STRING>*___ptr64,unsigned_char>
                            (9,*(uchar *)((longlong)param_2 + 10),pAVar1);
          if (((-1 < lVar4) &&
              (((lVar4 = AppendInteger<Windows::Auto<_LUNICODE_STRING>*___ptr64,unsigned_char>
                                   (9,*(uchar *)((longlong)param_2 + 0xb),pAVar1), -1 < lVar4 &&
                (lVar4 = AppendInteger<Windows::Auto<_LUNICODE_STRING>*___ptr64,unsigned_char>
                                   (9,(uchar)param_2[3],pAVar1), -1 < lVar4)) &&
               (lVar4 = AppendInteger<Windows::Auto<_LUNICODE_STRING>*___ptr64,unsigned_char>
                                  (9,*(uchar *)((longlong)param_2 + 0xd),pAVar1), -1 < lVar4)))) &&
             ((lVar4 = AppendInteger<Windows::Auto<_LUNICODE_STRING>*___ptr64,unsigned_char>
                                 (9,*(uchar *)((longlong)param_2 + 0xe),pAVar1), -1 < lVar4 &&
              (lVar4 = AppendInteger<Windows::Auto<_LUNICODE_STRING>*___ptr64,unsigned_char>
                                 (9,*(uchar *)((longlong)param_2 + 0xf),pAVar1), -1 < lVar4)))) {
            *(undefined2 *)
             (*(longlong *)(pAVar1 + 0x10) + (*(ulonglong *)pAVar1 & 0xfffffffffffffffe)) = 0x7d;
            *(longlong *)pAVar1 = *(longlong *)pAVar1 + 2;
            lVar4 = 0;
          }
        }
      }
    }
  }
  return lVar4;
}



===== AppendInteger<Windows::Auto<_LUNICODE_STRING>*___ptr64,unsigned_char> @ 1400082dc =====

/* long __cdecl Windows::StringUtil::Rtl::AppendInteger<class Windows::Auto<struct _LUNICODE_STRING>
   * __ptr64,unsigned char>(unsigned long,unsigned char,class Windows::Auto<struct _LUNICODE_STRING>
   * __ptr64) */

long __cdecl
Windows::StringUtil::Rtl::AppendInteger<Windows::Auto<_LUNICODE_STRING>*___ptr64,unsigned_char>
          (ulong param_1,uchar param_2,Auto<_LUNICODE_STRING> *param_3)

{
  ulonglong uVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  ulonglong uVar5;
  char cVar6;
  char cVar7;
  byte bVar8;
  int iVar9;
  ulonglong uVar10;
  uint uVar11;
  longlong lVar12;
  
  uVar5 = (ulonglong)param_2;
  cVar6 = '\0';
  iVar9 = (-(uint)((param_1 & 1) != 0) & 6) + 10;
  uVar10 = uVar5;
  do {
    cVar6 = cVar6 + '\x01';
    uVar1 = (longlong)(int)uVar10 / (longlong)iVar9;
    uVar10 = uVar1 & 0xffffffff;
  } while ((int)uVar1 != 0);
  cVar7 = '\0';
  if ((param_1 & 8) != 0) {
    iVar4 = 0xff;
    do {
      cVar7 = cVar7 + '\x01';
      iVar4 = iVar4 / iVar9;
    } while (iVar4 != 0);
    cVar7 = cVar7 - cVar6;
  }
  uVar10 = (ulonglong)(-(uint)((param_1 & 2) != 0) & 4) +
           (ulonglong)(-(uint)((param_1 & 4) != 0) & 2) + (longlong)(cVar6 * 2) +
           (longlong)(cVar7 * 2);
  uVar1 = *(ulonglong *)param_3;
  if (*(longlong *)(param_3 + 8) - uVar1 < uVar10) {
    uVar10 = uVar1 + uVar10;
    if (uVar10 < uVar1) {
      return -0x3fffff6b;
    }
    iVar9 = RtlReallocateLUnicodeString(uVar1,uVar10,(ulonglong *)param_3);
    if (iVar9 < 0) {
      return iVar9;
    }
  }
  if (((param_1 & 1) != 0) && ((param_1 & 2) != 0)) {
    *(undefined2 *)(*(longlong *)(param_3 + 0x10) + (*(ulonglong *)param_3 & 0xfffffffffffffffe)) =
         0x30;
    lVar12 = *(longlong *)param_3;
    *(ulonglong *)param_3 = lVar12 + 2U;
    *(undefined2 *)(*(longlong *)(param_3 + 0x10) + (lVar12 + 2U & 0xfffffffffffffffe)) = 0x78;
    *(longlong *)param_3 = *(longlong *)param_3 + 2;
  }
  for (; cVar7 != '\0'; cVar7 = cVar7 + -1) {
    *(undefined2 *)(*(longlong *)(param_3 + 0x10) + (*(ulonglong *)param_3 & 0xfffffffffffffffe)) =
         0x30;
    *(longlong *)param_3 = *(longlong *)param_3 + 2;
  }
  lVar12 = ((longlong)cVar6 + ((*(ulonglong *)param_3 >> 1) - 1)) * 2;
  uVar11 = (-(uint)((param_1 & 1) != 0) & 6) + 10;
  do {
    uVar10 = uVar5 % (ulonglong)uVar11;
    uVar5 = uVar5 / uVar11;
    bVar8 = (byte)uVar10;
    if ((param_1 & 0x10) == 0) {
      sVar2 = (short)uVar10;
      uVar3 = sVar2 + 0x30;
      if (9 < bVar8) {
        uVar3 = sVar2 + 0x57;
      }
    }
    else {
      cVar7 = '0';
      if (9 < bVar8) {
        cVar7 = '7';
      }
      uVar3 = (ushort)(byte)(cVar7 + bVar8);
    }
    *(ushort *)(lVar12 + *(longlong *)(param_3 + 0x10)) = uVar3;
    lVar12 = lVar12 + -2;
  } while ((char)uVar5 != '\0');
  uVar5 = *(longlong *)param_3 + (longlong)(cVar6 * 2);
  *(ulonglong *)param_3 = uVar5;
  if ((param_1 & 4) != 0) {
    *(undefined2 *)(*(longlong *)(param_3 + 0x10) + (uVar5 & 0xfffffffffffffffe)) = 0;
  }
  return 0;
}



===== AppendInteger<Windows::Auto<_LUNICODE_STRING>*___ptr64,unsigned_short> @ 1400084e0 =====

/* long __cdecl Windows::StringUtil::Rtl::AppendInteger<class Windows::Auto<struct _LUNICODE_STRING>
   * __ptr64,unsigned short>(unsigned long,unsigned short,class Windows::Auto<struct
   _LUNICODE_STRING> * __ptr64) */

long __cdecl
Windows::StringUtil::Rtl::AppendInteger<Windows::Auto<_LUNICODE_STRING>*___ptr64,unsigned_short>
          (ulong param_1,ushort param_2,Auto<_LUNICODE_STRING> *param_3)

{
  ulonglong uVar1;
  short sVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  char cVar6;
  char cVar7;
  byte bVar8;
  int iVar9;
  ulonglong uVar10;
  longlong lVar11;
  uint uVar12;
  
  uVar12 = (uint)param_2;
  cVar6 = '\0';
  iVar9 = (-(uint)((param_1 & 1) != 0) & 6) + 10;
  uVar4 = uVar12;
  do {
    cVar6 = cVar6 + '\x01';
    uVar4 = (int)uVar4 / iVar9;
  } while (uVar4 != 0);
  cVar7 = '\0';
  if ((param_1 & 8) != 0) {
    iVar5 = 0xffff;
    do {
      cVar7 = cVar7 + '\x01';
      iVar5 = iVar5 / iVar9;
    } while (iVar5 != 0);
    cVar7 = cVar7 - cVar6;
  }
  uVar10 = (ulonglong)(-(uint)((param_1 & 2) != 0) & 4) +
           (ulonglong)(-(uint)((param_1 & 4) != 0) & 2) + (longlong)(cVar6 * 2) +
           (longlong)(cVar7 * 2);
  uVar1 = *(ulonglong *)param_3;
  if (*(longlong *)(param_3 + 8) - uVar1 < uVar10) {
    uVar10 = uVar1 + uVar10;
    if (uVar10 < uVar1) {
      return -0x3fffff6b;
    }
    iVar9 = RtlReallocateLUnicodeString(uVar1,uVar10,(ulonglong *)param_3);
    if (iVar9 < 0) {
      return iVar9;
    }
  }
  if (((param_1 & 1) != 0) && ((param_1 & 2) != 0)) {
    *(undefined2 *)(*(longlong *)(param_3 + 0x10) + (*(ulonglong *)param_3 & 0xfffffffffffffffe)) =
         0x30;
    lVar11 = *(longlong *)param_3;
    *(ulonglong *)param_3 = lVar11 + 2U;
    *(undefined2 *)(*(longlong *)(param_3 + 0x10) + (lVar11 + 2U & 0xfffffffffffffffe)) = 0x78;
    *(longlong *)param_3 = *(longlong *)param_3 + 2;
  }
  for (; cVar7 != '\0'; cVar7 = cVar7 + -1) {
    *(undefined2 *)(*(longlong *)(param_3 + 0x10) + (*(ulonglong *)param_3 & 0xfffffffffffffffe)) =
         0x30;
    *(longlong *)param_3 = *(longlong *)param_3 + 2;
  }
  lVar11 = ((longlong)cVar6 + ((*(ulonglong *)param_3 >> 1) - 1)) * 2;
  uVar4 = (-(uint)((param_1 & 1) != 0) & 6) + 10;
  do {
    uVar10 = (ulonglong)uVar12 % (ulonglong)uVar4;
    uVar12 = uVar12 / uVar4;
    bVar8 = (byte)uVar10;
    if ((param_1 & 0x10) == 0) {
      sVar2 = (short)uVar10;
      uVar3 = sVar2 + 0x30;
      if (9 < bVar8) {
        uVar3 = sVar2 + 0x57;
      }
    }
    else {
      cVar7 = '0';
      if (9 < bVar8) {
        cVar7 = '7';
      }
      uVar3 = (ushort)(byte)(cVar7 + bVar8);
    }
    *(ushort *)(lVar11 + *(longlong *)(param_3 + 0x10)) = uVar3;
    lVar11 = lVar11 + -2;
  } while ((short)uVar12 != 0);
  uVar10 = *(longlong *)param_3 + (longlong)(cVar6 * 2);
  *(ulonglong *)param_3 = uVar10;
  if ((param_1 & 4) != 0) {
    *(undefined2 *)(*(longlong *)(param_3 + 0x10) + (uVar10 & 0xfffffffffffffffe)) = 0;
  }
  return 0;
}



===== AppendInteger<Windows::Auto<_LUNICODE_STRING>*___ptr64,unsigned_long> @ 1400086e4 =====

/* long __cdecl Windows::StringUtil::Rtl::AppendInteger<class Windows::Auto<struct _LUNICODE_STRING>
   * __ptr64,unsigned long>(unsigned long,unsigned long,class Windows::Auto<struct _LUNICODE_STRING>
   * __ptr64) */

long __cdecl
Windows::StringUtil::Rtl::AppendInteger<Windows::Auto<_LUNICODE_STRING>*___ptr64,unsigned_long>
          (ulong param_1,ulong param_2,Auto<_LUNICODE_STRING> *param_3)

{
  ulonglong uVar1;
  short sVar2;
  ushort uVar3;
  ulong uVar4;
  uint uVar5;
  int iVar6;
  byte bVar7;
  char cVar8;
  char cVar9;
  uint uVar10;
  ulonglong uVar11;
  longlong lVar12;
  
  cVar8 = '\0';
  uVar10 = (-(uint)((param_1 & 1) != 0) & 6) + 10;
  uVar4 = param_2;
  do {
    cVar8 = cVar8 + '\x01';
    uVar4 = uVar4 / uVar10;
  } while (uVar4 != 0);
  cVar9 = '\0';
  if ((param_1 & 8) != 0) {
    uVar5 = 0xffffffff;
    do {
      cVar9 = cVar9 + '\x01';
      uVar5 = uVar5 / uVar10;
    } while (uVar5 != 0);
    cVar9 = cVar9 - cVar8;
  }
  uVar11 = (ulonglong)(-(uint)((param_1 & 2) != 0) & 4) +
           (ulonglong)(-(uint)((param_1 & 4) != 0) & 2) + (longlong)(cVar8 * 2) +
           (longlong)(cVar9 * 2);
  uVar1 = *(ulonglong *)param_3;
  if (*(longlong *)(param_3 + 8) - uVar1 < uVar11) {
    uVar11 = uVar1 + uVar11;
    if (uVar11 < uVar1) {
      return -0x3fffff6b;
    }
    iVar6 = RtlReallocateLUnicodeString(uVar1,uVar11,(ulonglong *)param_3);
    if (iVar6 < 0) {
      return iVar6;
    }
  }
  if (((param_1 & 1) != 0) && ((param_1 & 2) != 0)) {
    *(undefined2 *)(*(longlong *)(param_3 + 0x10) + (*(ulonglong *)param_3 & 0xfffffffffffffffe)) =
         0x30;
    lVar12 = *(longlong *)param_3;
    *(ulonglong *)param_3 = lVar12 + 2U;
    *(undefined2 *)(*(longlong *)(param_3 + 0x10) + (lVar12 + 2U & 0xfffffffffffffffe)) = 0x78;
    *(longlong *)param_3 = *(longlong *)param_3 + 2;
  }
  for (; cVar9 != '\0'; cVar9 = cVar9 + -1) {
    *(undefined2 *)(*(longlong *)(param_3 + 0x10) + (*(ulonglong *)param_3 & 0xfffffffffffffffe)) =
         0x30;
    *(longlong *)param_3 = *(longlong *)param_3 + 2;
  }
  lVar12 = ((longlong)cVar8 + ((*(ulonglong *)param_3 >> 1) - 1)) * 2;
  uVar10 = (-(uint)((param_1 & 1) != 0) & 6) + 10;
  do {
    uVar11 = (ulonglong)param_2 % (ulonglong)uVar10;
    param_2 = param_2 / uVar10;
    bVar7 = (byte)uVar11;
    if ((param_1 & 0x10) == 0) {
      sVar2 = (short)uVar11;
      uVar3 = sVar2 + 0x30;
      if (9 < bVar7) {
        uVar3 = sVar2 + 0x57;
      }
    }
    else {
      cVar9 = '0';
      if (9 < bVar7) {
        cVar9 = '7';
      }
      uVar3 = (ushort)(byte)(cVar9 + bVar7);
    }
    *(ushort *)(lVar12 + *(longlong *)(param_3 + 0x10)) = uVar3;
    lVar12 = lVar12 + -2;
  } while (param_2 != 0);
  uVar11 = *(longlong *)param_3 + (longlong)(cVar8 * 2);
  *(ulonglong *)param_3 = uVar11;
  if ((param_1 & 4) != 0) {
    *(undefined2 *)(*(longlong *)(param_3 + 0x10) + (uVar11 & 0xfffffffffffffffe)) = 0;
  }
  return 0;
}



===== EmplaceBack<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>_> @ 1400088e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: class BUCL::Rtl::CCallDisposition __cdecl BUCL::CVector<class Windows::Auto<class
   Windows::Rtl::SystemImplementation::IRtlRegistryProvider * __ptr64>,class
   BUCL::Rtl::CCallDisposition>::EmplaceBack<class Windows::Auto<class
   Windows::Rtl::SystemImplementation::IRtlRegistryProvider * __ptr64> >(class Windows::Auto<class
   Windows::Rtl::SystemImplementation::IRtlRegistryProvider * __ptr64> && __ptr64) __ptr64 */

Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64> * __thiscall
BUCL::
CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
::EmplaceBack<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>_>
          (CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
           *this,Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64> *param_1)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  uint uVar4;
  undefined8 *puVar5;
  __uint64 *p_Var6;
  undefined8 *puVar7;
  longlong lVar8;
  __uint64 *p_Var9;
  undefined8 *in_R8;
  __uint64 *p_Var10;
  uint local_res8 [2];
  
  if (*(longlong *)(this + 8) != *(longlong *)(this + 0x10)) goto LAB_140008aa1;
  p_Var10 = (__uint64 *)(*(longlong *)(this + 0x10) - *(longlong *)this >> 3);
  p_Var6 = p_Var10;
  if (p_Var10 != (__uint64 *)0xffffffffffffffff) {
    p_Var6 = (__uint64 *)((longlong)p_Var10 + 1);
  }
  uVar4 = 0xc0000095;
  if (p_Var10 != (__uint64 *)0xffffffffffffffff) {
    uVar4 = 0;
  }
  if (-1 < (int)uVar4) {
    if (p_Var10 < p_Var6) {
      p_Var9 = (__uint64 *)0x4;
      if ((__uint64 *)0x3 < p_Var10) {
        if (p_Var10 < (__uint64 *)0x21) {
          p_Var9 = (__uint64 *)((longlong)p_Var10 * 2);
        }
        else {
          p_Var9 = (__uint64 *)(((ulonglong)p_Var10 >> 1) + (longlong)p_Var10);
        }
        uVar4 = -(uint)(p_Var9 < p_Var10) & 0xc0000095;
        if ((int)uVar4 < 0) goto LAB_140008a88;
      }
      if (p_Var9 < p_Var6) {
        p_Var9 = p_Var6;
      }
      if (p_Var9 < (__uint64 *)0x1fffffffffffffff) {
        if (p_Var10 < p_Var9) {
          Implementation::Multiply<BUCL::Rtl::CCallDisposition,unsigned___int64>
                    ((__uint64)local_res8,8,p_Var9);
          if (-1 < (int)local_res8[0]) {
            puVar2 = operator_new(0);
            if (puVar2 != (undefined8 *)0x0) {
              puVar7 = puVar2;
              for (puVar5 = *(undefined8 **)this; puVar3 = *(undefined8 **)(this + 8),
                  puVar5 != puVar3; puVar5 = puVar5 + 1) {
                if (puVar7 != (undefined8 *)0x0) {
                  uVar1 = *puVar5;
                  *puVar5 = 0;
                  *puVar7 = uVar1;
                }
                puVar7 = puVar7 + 1;
              }
              puVar5 = *(undefined8 **)this;
              lVar8 = (longlong)puVar3 - (longlong)puVar5;
              while (puVar5 != puVar3) {
                puVar5 = (undefined8 *)puVar3[-1];
                if (puVar5 != (undefined8 *)0x0) {
                  puVar3[-1] = 0;
                  (**(code **)*puVar5)();
                }
                puVar3 = (undefined8 *)(*(longlong *)(this + 8) + -8);
                *(undefined8 **)(this + 8) = puVar3;
                puVar5 = *(undefined8 **)this;
              }
              if (puVar5 != (undefined8 *)0x0) {
                ExFreePoolWithTag(puVar5,0);
              }
              *(undefined8 **)this = puVar2;
              *(undefined8 **)(this + 8) = puVar2 + (lVar8 >> 3);
              *(undefined8 **)(this + 0x10) = puVar2 + (longlong)p_Var9;
              goto LAB_140008a7a;
            }
            local_res8[0] = 0xc0000017;
          }
        }
        else {
LAB_140008a7a:
          local_res8[0] = 0;
        }
        uVar4 = -(uint)((int)local_res8[0] < 0) & local_res8[0];
      }
      else {
        uVar4 = 0xc0000017;
      }
    }
    else {
      uVar4 = 0;
    }
LAB_140008a88:
    uVar4 = -(uint)((int)uVar4 < 0) & uVar4;
  }
  if ((int)uVar4 < 0) {
    *(uint *)param_1 = uVar4;
    return param_1;
  }
LAB_140008aa1:
  puVar2 = *(undefined8 **)(this + 8);
  if (puVar2 != (undefined8 *)0x0) {
    uVar1 = *in_R8;
    *in_R8 = 0;
    *puVar2 = uVar1;
  }
  *(longlong *)(this + 8) = *(longlong *)(this + 8) + 8;
  *(undefined4 *)param_1 = 0;
  return param_1;
}



===== EmplaceBack<BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>_> @ 140008adc =====

/* public: class BUCL::Rtl::CCallDisposition __cdecl BUCL::CVector<class BUCL::CVector<enum
   gsl::byte,class BUCL::Rtl::CCallDisposition>,class
   BUCL::Rtl::CCallDisposition>::EmplaceBack<class BUCL::CVector<enum gsl::byte,class
   BUCL::Rtl::CCallDisposition> >(class BUCL::CVector<enum gsl::byte,class
   BUCL::Rtl::CCallDisposition> && __ptr64) __ptr64 */

CVector<gsl::byte,BUCL::Rtl::CCallDisposition> * __thiscall
BUCL::CVector<BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>,BUCL::Rtl::CCallDisposition>::
EmplaceBack<BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>_>
          (CVector<BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>,BUCL::Rtl::CCallDisposition>
           *this,CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *param_1)

{
  undefined8 uVar1;
  void *pvVar2;
  uint uVar3;
  __uint64 *p_Var4;
  undefined8 *puVar5;
  __uint64 *p_Var6;
  undefined8 *puVar7;
  undefined8 *in_R8;
  undefined8 *puVar8;
  longlong lVar9;
  __uint64 *p_Var10;
  uint local_res8 [2];
  
  if (*(longlong *)(this + 8) != *(longlong *)(this + 0x10)) goto LAB_140008cb6;
  lVar9 = *(longlong *)(this + 0x10) - *(longlong *)this >> 3;
  p_Var10 = (__uint64 *)(lVar9 * -0x5555555555555555);
  p_Var4 = p_Var10;
  if (p_Var10 != (__uint64 *)0xffffffffffffffff) {
    p_Var4 = (__uint64 *)((longlong)p_Var10 + 1);
  }
  uVar3 = 0xc0000095;
  if (p_Var10 != (__uint64 *)0xffffffffffffffff) {
    uVar3 = 0;
  }
  if (-1 < (int)uVar3) {
    if (p_Var10 < p_Var4) {
      p_Var6 = (__uint64 *)0x4;
      if ((__uint64 *)0x3 < p_Var10) {
        if (p_Var10 < (__uint64 *)0x21) {
          p_Var6 = (__uint64 *)(lVar9 * 0x5555555555555556);
        }
        else {
          p_Var6 = (__uint64 *)(((ulonglong)p_Var10 >> 1) + (longlong)p_Var10);
        }
        uVar3 = -(uint)(p_Var6 < p_Var10) & 0xc0000095;
        if ((int)uVar3 < 0) goto LAB_140008c9d;
      }
      if (p_Var6 < p_Var4) {
        p_Var6 = p_Var4;
      }
      if (p_Var6 < (__uint64 *)0xaaaaaaaaaaaaaaa) {
        if (p_Var10 < p_Var6) {
          Implementation::Multiply<BUCL::Rtl::CCallDisposition,unsigned___int64>
                    ((__uint64)local_res8,0x18,p_Var6);
          if (-1 < (int)local_res8[0]) {
            pvVar2 = operator_new(0);
            if (pvVar2 != (void *)0x0) {
              puVar5 = *(undefined8 **)this;
              puVar7 = *(undefined8 **)(this + 8);
              if (puVar5 != puVar7) {
                puVar8 = (undefined8 *)((longlong)pvVar2 + 0x10);
                do {
                  puVar7 = puVar8 + -2;
                  if (puVar7 != (undefined8 *)0x0) {
                    *puVar8 = 0;
                    puVar8[-1] = 0;
                    *puVar7 = 0;
                    uVar1 = *puVar5;
                    *puVar5 = 0;
                    *puVar7 = uVar1;
                    uVar1 = puVar5[1];
                    puVar5[1] = puVar8[-1];
                    puVar8[-1] = uVar1;
                    uVar1 = puVar5[2];
                    puVar5[2] = *puVar8;
                    *puVar8 = uVar1;
                  }
                  puVar7 = *(undefined8 **)(this + 8);
                  puVar5 = puVar5 + 3;
                  puVar8 = puVar8 + 3;
                } while (puVar5 != puVar7);
              }
              lVar9 = *(longlong *)this;
              Close(this);
              *(void **)this = pvVar2;
              *(void **)(this + 8) =
                   (void *)((longlong)pvVar2 + ((longlong)puVar7 - lVar9 >> 3) * 8);
              *(void **)(this + 0x10) = (void *)((longlong)pvVar2 + (longlong)p_Var6 * 0x18);
              goto LAB_140008c8f;
            }
            local_res8[0] = 0xc0000017;
          }
        }
        else {
LAB_140008c8f:
          local_res8[0] = 0;
        }
        uVar3 = -(uint)((int)local_res8[0] < 0) & local_res8[0];
      }
      else {
        uVar3 = 0xc0000017;
      }
    }
    else {
      uVar3 = 0;
    }
LAB_140008c9d:
    uVar3 = -(uint)((int)uVar3 < 0) & uVar3;
  }
  if ((int)uVar3 < 0) {
    *(uint *)param_1 = uVar3;
    return param_1;
  }
LAB_140008cb6:
  puVar5 = *(undefined8 **)(this + 8);
  if (puVar5 != (undefined8 *)0x0) {
    puVar5[2] = 0;
    puVar5[1] = 0;
    *puVar5 = 0;
    uVar1 = *in_R8;
    *in_R8 = 0;
    *puVar5 = uVar1;
    uVar1 = in_R8[1];
    in_R8[1] = puVar5[1];
    puVar5[1] = uVar1;
    uVar1 = in_R8[2];
    in_R8[2] = puVar5[2];
    puVar5[2] = uVar1;
  }
  *(longlong *)(this + 8) = *(longlong *)(this + 8) + 0x18;
  *(undefined4 *)param_1 = 0;
  return param_1;
}



===== TrySplitStringOnAsciiPredicateMatch<_LUNICODE_STRING,Windows::StringUtil::Impl::NtSlashPredicate> @ 140008d20 =====

/* bool __cdecl Windows::StringUtil::Impl::TrySplitStringOnAsciiPredicateMatch<struct
   _LUNICODE_STRING,class Windows::StringUtil::Impl::NtSlashPredicate>(enum
   Windows::StringUtil::Impl::TrySplitStringOnAsciiPredicateMatchFlags,struct _LUNICODE_STRING const
   & __ptr64,class Windows::StringUtil::Impl::NtSlashPredicate const & __ptr64,struct
   _LUNICODE_STRING * __ptr64,struct _LUNICODE_STRING * __ptr64) */

bool __cdecl
Windows::StringUtil::Impl::
TrySplitStringOnAsciiPredicateMatch<_LUNICODE_STRING,Windows::StringUtil::Impl::NtSlashPredicate>
          (TrySplitStringOnAsciiPredicateMatchFlags param_1,_LUNICODE_STRING *param_2,
          NtSlashPredicate *param_3,_LUNICODE_STRING *param_4,_LUNICODE_STRING *param_5)

{
  longlong lVar1;
  ulonglong uVar2;
  short *psVar3;
  bool bVar4;
  ulonglong uVar5;
  longlong lStack_30;
  short *local_28;
  ulonglong uStack_18;
  
  uVar2 = *(ulonglong *)param_2;
  bVar4 = false;
  lVar1 = *(longlong *)(param_2 + 0x10);
  lStack_30 = 0;
  local_28 = (short *)0x0;
  uStack_18 = uVar2;
  if (uVar2 != 0) {
    uVar5 = (uVar2 >> 1) - 1;
    psVar3 = (short *)(lVar1 + uVar5 * 2);
    for (; uStack_18 = uVar2, uVar5 < uVar2 >> 1; uVar5 = uVar5 - 1) {
      uStack_18 = (longlong)psVar3 - lVar1;
      if (*psVar3 == 0x5c) {
        lStack_30 = (uVar2 - uStack_18) + -2;
        if (lStack_30 != 0) {
          local_28 = psVar3 + 1;
        }
        bVar4 = true;
        break;
      }
      psVar3 = psVar3 + -1;
    }
  }
  *(ulonglong *)param_4 = uStack_18;
  *(ulonglong *)(param_4 + 8) = uStack_18;
  *(longlong *)(param_4 + 0x10) = lVar1;
  *(longlong *)param_5 = lStack_30;
  *(longlong *)(param_5 + 8) = lStack_30;
  *(short **)(param_5 + 0x10) = local_28;
  return bVar4;
}



===== RegistryTimers @ 140008dec =====

/* public: __cdecl RegistryTimers::RegistryTimers(void) __ptr64 */

RegistryTimers * __thiscall RegistryTimers::RegistryTimers(RegistryTimers *this)

{
  *this = (RegistryTimers)0x0;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *this = (RegistryTimers)0x0;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  this[0x28] = (RegistryTimers)0x0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  this[0x28] = (RegistryTimers)0x0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  this[0x50] = (RegistryTimers)0x0;
  *(undefined8 *)(this + 0x58) = 0;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined8 *)(this + 0x68) = 0;
  *(undefined8 *)(this + 0x70) = 0;
  this[0x50] = (RegistryTimers)0x0;
  *(undefined8 *)(this + 0x58) = 0;
  *(undefined8 *)(this + 0x60) = 0;
  this[0x78] = (RegistryTimers)0x0;
  *(undefined8 *)(this + 0x80) = 0;
  *(undefined8 *)(this + 0x88) = 0;
  *(undefined8 *)(this + 0x90) = 0;
  *(undefined8 *)(this + 0x98) = 0;
  this[0x78] = (RegistryTimers)0x0;
  *(undefined8 *)(this + 0x80) = 0;
  *(undefined8 *)(this + 0x88) = 0;
  this[0xa0] = (RegistryTimers)0x0;
  *(undefined8 *)(this + 0xa8) = 0;
  *(undefined8 *)(this + 0xb0) = 0;
  *(undefined8 *)(this + 0xb8) = 0;
  *(undefined8 *)(this + 0xc0) = 0;
  this[0xa0] = (RegistryTimers)0x0;
  *(undefined8 *)(this + 0xa8) = 0;
  *(undefined8 *)(this + 0xb0) = 0;
  this[200] = (RegistryTimers)0x0;
  *(undefined8 *)(this + 0xd0) = 0;
  *(undefined8 *)(this + 0xd8) = 0;
  *(undefined8 *)(this + 0xe0) = 0;
  *(undefined8 *)(this + 0xe8) = 0;
  this[200] = (RegistryTimers)0x0;
  *(undefined8 *)(this + 0xd0) = 0;
  *(undefined8 *)(this + 0xd8) = 0;
  this[0xf0] = (RegistryTimers)0x0;
  *(undefined8 *)(this + 0xf8) = 0;
  *(undefined8 *)(this + 0x100) = 0;
  *(undefined8 *)(this + 0x108) = 0;
  *(undefined8 *)(this + 0x110) = 0;
  this[0xf0] = (RegistryTimers)0x0;
  *(undefined8 *)(this + 0xf8) = 0;
  *(undefined8 *)(this + 0x100) = 0;
  this[0x118] = (RegistryTimers)0x0;
  *(undefined8 *)(this + 0x120) = 0;
  *(undefined8 *)(this + 0x128) = 0;
  *(undefined8 *)(this + 0x130) = 0;
  *(undefined8 *)(this + 0x138) = 0;
  this[0x118] = (RegistryTimers)0x0;
  *(undefined8 *)(this + 0x120) = 0;
  *(undefined8 *)(this + 0x128) = 0;
  this[0x140] = (RegistryTimers)0x0;
  *(undefined8 *)(this + 0x148) = 0;
  *(undefined8 *)(this + 0x150) = 0;
  *(undefined8 *)(this + 0x158) = 0;
  *(undefined8 *)(this + 0x160) = 0;
  this[0x140] = (RegistryTimers)0x0;
  *(undefined8 *)(this + 0x148) = 0;
  *(undefined8 *)(this + 0x150) = 0;
  return this;
}



===== ~CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition> @ 140008f94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: __cdecl BUCL::CVector<class Windows::Auto<class
   Windows::Rtl::SystemImplementation::IRtlRegistryProvider * __ptr64>,class
   BUCL::Rtl::CCallDisposition>::~CVector<class Windows::Auto<class
   Windows::Rtl::SystemImplementation::IRtlRegistryProvider * __ptr64>,class
   BUCL::Rtl::CCallDisposition>(void) __ptr64 */

void __thiscall
BUCL::
CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
::
~CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
          (CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
           *this)

{
  undefined8 *puVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar2 = *(longlong *)(this + 8);
  lVar3 = *(longlong *)this;
  while (lVar3 != lVar2) {
    puVar1 = *(undefined8 **)(lVar2 + -8);
    if (puVar1 != (undefined8 *)0x0) {
      *(undefined8 *)(lVar2 + -8) = 0;
      (**(code **)*puVar1)();
    }
    lVar2 = *(longlong *)(this + 8) + -8;
    *(longlong *)(this + 8) = lVar2;
    lVar3 = *(longlong *)this;
  }
  if (lVar3 != 0) {
    ExFreePoolWithTag(lVar3,0);
  }
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)this = 0;
  return;
}



===== ~OnBlockExitImpl<<lambda_0900b3b0397de7d8025b4ec4a90b502a>_> @ 140009004 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: __cdecl Windows::Detail::OnBlockExitImpl<class <lambda_0900b3b0397de7d8025b4ec4a90b502a>
   >::~OnBlockExitImpl<class <lambda_0900b3b0397de7d8025b4ec4a90b502a> >(void) __ptr64 */

void __thiscall
Windows::Detail::OnBlockExitImpl<<lambda_0900b3b0397de7d8025b4ec4a90b502a>_>::
~OnBlockExitImpl<<lambda_0900b3b0397de7d8025b4ec4a90b502a>_>
          (OnBlockExitImpl<<lambda_0900b3b0397de7d8025b4ec4a90b502a>_> *this)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 auStack_38 [32];
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  if ((*this != (OnBlockExitImpl<<lambda_0900b3b0397de7d8025b4ec4a90b502a>_>)0x0) &&
     (lVar1 = *(longlong *)(*(longlong *)(this + 8) + 0x60), *(char *)(lVar1 + 0xa0) != '\0')) {
    local_18 = 0;
    lVar2 = KeQueryPerformanceCounter(&local_18);
    LOCK();
    *(longlong *)(lVar1 + 0xa8) =
         *(longlong *)(lVar1 + 0xa8) + (lVar2 - *(longlong *)(lVar1 + 0xb0));
    UNLOCK();
    *(undefined1 *)(lVar1 + 0xa0) = 0;
  }
  return;
}



===== ~OnBlockExitImpl<<lambda_215c4eb5720f7bbaa58112496b2362ea>_> @ 140009078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: __cdecl Windows::Detail::OnBlockExitImpl<class <lambda_215c4eb5720f7bbaa58112496b2362ea>
   >::~OnBlockExitImpl<class <lambda_215c4eb5720f7bbaa58112496b2362ea> >(void) __ptr64 */

void __thiscall
Windows::Detail::OnBlockExitImpl<<lambda_215c4eb5720f7bbaa58112496b2362ea>_>::
~OnBlockExitImpl<<lambda_215c4eb5720f7bbaa58112496b2362ea>_>
          (OnBlockExitImpl<<lambda_215c4eb5720f7bbaa58112496b2362ea>_> *this)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 auStack_38 [32];
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  if ((*this != (OnBlockExitImpl<<lambda_215c4eb5720f7bbaa58112496b2362ea>_>)0x0) &&
     (lVar1 = *(longlong *)(*(longlong *)(this + 8) + 0x60), *(char *)(lVar1 + 0xf0) != '\0')) {
    local_18 = 0;
    lVar2 = KeQueryPerformanceCounter(&local_18);
    LOCK();
    *(longlong *)(lVar1 + 0xf8) =
         *(longlong *)(lVar1 + 0xf8) + (lVar2 - *(longlong *)(lVar1 + 0x100));
    UNLOCK();
    *(undefined1 *)(lVar1 + 0xf0) = 0;
  }
  return;
}



===== ~OnBlockExitImpl<<lambda_3156162d9f3dab841a21b521aa54357f>_> @ 1400090ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: __cdecl Windows::Detail::OnBlockExitImpl<class <lambda_3156162d9f3dab841a21b521aa54357f>
   >::~OnBlockExitImpl<class <lambda_3156162d9f3dab841a21b521aa54357f> >(void) __ptr64 */

void __thiscall
Windows::Detail::OnBlockExitImpl<<lambda_3156162d9f3dab841a21b521aa54357f>_>::
~OnBlockExitImpl<<lambda_3156162d9f3dab841a21b521aa54357f>_>
          (OnBlockExitImpl<<lambda_3156162d9f3dab841a21b521aa54357f>_> *this)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 auStack_38 [32];
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  if ((*this != (OnBlockExitImpl<<lambda_3156162d9f3dab841a21b521aa54357f>_>)0x0) &&
     (lVar1 = *(longlong *)(*(longlong *)(this + 8) + 0x60), *(char *)(lVar1 + 0x78) != '\0')) {
    local_18 = 0;
    lVar2 = KeQueryPerformanceCounter(&local_18);
    LOCK();
    *(longlong *)(lVar1 + 0x80) =
         *(longlong *)(lVar1 + 0x80) + (lVar2 - *(longlong *)(lVar1 + 0x88));
    UNLOCK();
    *(undefined1 *)(lVar1 + 0x78) = 0;
  }
  return;
}



===== ~OnBlockExitImpl<<lambda_32d53f16296fbe318a7a20974fbdbb6f>_> @ 140009158 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: __cdecl Windows::Detail::OnBlockExitImpl<class <lambda_32d53f16296fbe318a7a20974fbdbb6f>
   >::~OnBlockExitImpl<class <lambda_32d53f16296fbe318a7a20974fbdbb6f> >(void) __ptr64 */

void __thiscall
Windows::Detail::OnBlockExitImpl<<lambda_32d53f16296fbe318a7a20974fbdbb6f>_>::
~OnBlockExitImpl<<lambda_32d53f16296fbe318a7a20974fbdbb6f>_>
          (OnBlockExitImpl<<lambda_32d53f16296fbe318a7a20974fbdbb6f>_> *this)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 auStack_38 [32];
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  if ((*this != (OnBlockExitImpl<<lambda_32d53f16296fbe318a7a20974fbdbb6f>_>)0x0) &&
     (lVar1 = *(longlong *)(*(longlong *)(this + 8) + 0x60), *(char *)(lVar1 + 0x118) != '\0')) {
    local_18 = 0;
    lVar2 = KeQueryPerformanceCounter(&local_18);
    LOCK();
    *(longlong *)(lVar1 + 0x120) =
         *(longlong *)(lVar1 + 0x120) + (lVar2 - *(longlong *)(lVar1 + 0x128));
    UNLOCK();
    *(undefined1 *)(lVar1 + 0x118) = 0;
  }
  return;
}



===== ~OnBlockExitImpl<<lambda_8ba2b512a3f33f72fb6eb20b576878a5>_> @ 1400091cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: __cdecl Windows::Detail::OnBlockExitImpl<class <lambda_8ba2b512a3f33f72fb6eb20b576878a5>
   >::~OnBlockExitImpl<class <lambda_8ba2b512a3f33f72fb6eb20b576878a5> >(void) __ptr64 */

void __thiscall
Windows::Detail::OnBlockExitImpl<<lambda_8ba2b512a3f33f72fb6eb20b576878a5>_>::
~OnBlockExitImpl<<lambda_8ba2b512a3f33f72fb6eb20b576878a5>_>
          (OnBlockExitImpl<<lambda_8ba2b512a3f33f72fb6eb20b576878a5>_> *this)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 auStack_38 [32];
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  if ((*this != (OnBlockExitImpl<<lambda_8ba2b512a3f33f72fb6eb20b576878a5>_>)0x0) &&
     (lVar1 = *(longlong *)(*(longlong *)(this + 8) + 0x60), *(char *)(lVar1 + 0x140) != '\0')) {
    local_18 = 0;
    lVar2 = KeQueryPerformanceCounter(&local_18);
    LOCK();
    *(longlong *)(lVar1 + 0x148) =
         *(longlong *)(lVar1 + 0x148) + (lVar2 - *(longlong *)(lVar1 + 0x150));
    UNLOCK();
    *(undefined1 *)(lVar1 + 0x140) = 0;
  }
  return;
}



===== ~OnBlockExitImpl<<lambda_b98ed077e732c52fc62505173bcb5195>_> @ 140009240 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: __cdecl Windows::Detail::OnBlockExitImpl<class <lambda_b98ed077e732c52fc62505173bcb5195>
   >::~OnBlockExitImpl<class <lambda_b98ed077e732c52fc62505173bcb5195> >(void) __ptr64 */

void __thiscall
Windows::Detail::OnBlockExitImpl<<lambda_b98ed077e732c52fc62505173bcb5195>_>::
~OnBlockExitImpl<<lambda_b98ed077e732c52fc62505173bcb5195>_>
          (OnBlockExitImpl<<lambda_b98ed077e732c52fc62505173bcb5195>_> *this)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 auStack_38 [32];
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  if ((*this != (OnBlockExitImpl<<lambda_b98ed077e732c52fc62505173bcb5195>_>)0x0) &&
     (lVar1 = *(longlong *)(*(longlong *)(this + 8) + 0x60), *(char *)(lVar1 + 200) != '\0')) {
    local_18 = 0;
    lVar2 = KeQueryPerformanceCounter(&local_18);
    LOCK();
    *(longlong *)(lVar1 + 0xd0) =
         *(longlong *)(lVar1 + 0xd0) + (lVar2 - *(longlong *)(lVar1 + 0xd8));
    UNLOCK();
    *(undefined1 *)(lVar1 + 200) = 0;
  }
  return;
}



===== ~RegistryTimers @ 1400092b4 =====

/* public: __cdecl RegistryTimers::~RegistryTimers(void) __ptr64 */

void __thiscall RegistryTimers::~RegistryTimers(RegistryTimers *this)

{
  Windows::Rtl::StopWatch::~StopWatch((StopWatch *)(this + 0x140));
  Windows::Rtl::StopWatch::~StopWatch((StopWatch *)(this + 0x118));
  Windows::Rtl::StopWatch::~StopWatch((StopWatch *)(this + 0xf0));
  Windows::Rtl::StopWatch::~StopWatch((StopWatch *)(this + 200));
  Windows::Rtl::StopWatch::~StopWatch((StopWatch *)(this + 0xa0));
  Windows::Rtl::StopWatch::~StopWatch((StopWatch *)(this + 0x78));
  Windows::Rtl::StopWatch::~StopWatch((StopWatch *)(this + 0x50));
  Windows::Rtl::StopWatch::~StopWatch((StopWatch *)(this + 0x28));
  Windows::Rtl::StopWatch::~StopWatch((StopWatch *)this);
  return;
}



===== ~StopWatch @ 14000932c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: __cdecl Windows::Rtl::StopWatch::~StopWatch(void) __ptr64 */

void __thiscall Windows::Rtl::StopWatch::~StopWatch(StopWatch *this)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  lVar3 = 0;
  if (*(longlong *)(this + 0x20) != 0) {
    if (*this != (StopWatch)0x0) {
      local_28 = 0;
      lVar2 = KeQueryPerformanceCounter(&local_28);
      LOCK();
      *(longlong *)(this + 8) = *(longlong *)(this + 8) + (lVar2 - *(longlong *)(this + 0x10));
      UNLOCK();
      *this = (StopWatch)0x0;
    }
    pcVar1 = *(char **)(this + 0x20);
    if ((*pcVar1 == '\0') && (*(longlong *)(pcVar1 + 0x18) == 0)) {
      *(undefined8 *)(pcVar1 + 0x18) = *(undefined8 *)(this + 0x18);
    }
    if (*this != (StopWatch)0x0) {
      local_20 = 0;
      lVar3 = KeQueryPerformanceCounter(&local_20);
      lVar3 = lVar3 - *(longlong *)(this + 0x10);
    }
    LOCK();
    *(longlong *)(pcVar1 + 8) = *(longlong *)(pcVar1 + 8) + *(longlong *)(this + 8) + lVar3;
    UNLOCK();
  }
  return;
}



===== operator() @ 1400093ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void <lambda_59dcddcc7819714d190c2c60fb1d8fec>::operator()(undefined8 *param_1)

{
  char *pcVar1;
  undefined8 uVar2;
  long lVar3;
  uint uVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined1 auStack_88 [32];
  ulonglong *local_68;
  undefined8 local_60;
  undefined8 local_58;
  wchar_t *local_50;
  ulonglong local_48 [3];
  ulonglong *local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  pcVar1 = (char *)param_1[1];
  if (*pcVar1 != '\0') {
                    /* WARNING: Subroutine does not return */
    RtlRaiseStatus(0xc00000e5);
  }
  uVar5 = KeQueryPerformanceCounter(pcVar1 + 0x18);
  uVar2 = *param_1;
  *(undefined8 *)(pcVar1 + 0x10) = uVar5;
  *pcVar1 = '\x01';
  local_48[2] = 0;
  local_68 = local_48;
  local_60 = 0x14;
  local_58 = 0x14;
  local_50 = L"\\??\\Volume";
  local_48[0] = 0;
  local_48[1] = 0;
  lVar3 = Windows::StringUtil::Rtl::
          AppendString<_LUNICODE_STRING,Windows::AutoOperatorAmpersandHelper<_LUNICODE_STRING,Windows::Auto<_LUNICODE_STRING>_>,0>
                    (&local_60,&local_68);
  if (-1 < lVar3) {
    local_30 = local_48;
    lVar3 = Windows::StringUtil::Rtl::
            AppendGuid<Windows::AutoOperatorAmpersandHelper<_LUNICODE_STRING,Windows::Auto<_LUNICODE_STRING>_>_>
                      (0,uVar2,&local_30);
    if (-1 < lVar3) {
      local_28 = 0;
      uStack_20 = 0;
      uVar4 = RtlInitUnicodeStringFromLUnicodeString(local_48,(undefined4 *)&local_28);
      if (-1 < (int)uVar4) {
        DismountCim((_UNICODE_STRING *)&local_28);
      }
    }
  }
  if (local_48[2] != 0) {
    RtlFreeLUnicodeString((longlong)local_48);
  }
  if (*pcVar1 != '\0') {
    local_30 = (ulonglong *)0x0;
    lVar6 = KeQueryPerformanceCounter(&local_30);
    LOCK();
    *(longlong *)(pcVar1 + 8) = *(longlong *)(pcVar1 + 8) + (lVar6 - *(longlong *)(pcVar1 + 0x10));
    UNLOCK();
    *pcVar1 = '\0';
  }
  return;
}



===== `scalar_deleting_destructor' @ 140009520 =====

/* public: virtual void * __ptr64 __cdecl CmRegistryProvider::`scalar deleting destructor'(unsigned
   int) __ptr64 */

void * __thiscall
CmRegistryProvider::_scalar_deleting_destructor_(CmRegistryProvider *this,uint param_1)

{
  *(undefined ***)this = &Windows::Rtl::IRtlObject::_vftable_;
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0);
  }
  return this;
}



===== Assign @ 140009558 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl Windows::Rtl::SystemImplementation::CSilHandle::Assign(void * __ptr64,class
   Windows::Rtl::SystemImplementation::IRtlObjectProvider * __ptr64) __ptr64 */

long __thiscall
Windows::Rtl::SystemImplementation::CSilHandle::Assign
          (CSilHandle *this,void *param_1,IRtlObjectProvider *param_2)

{
  undefined8 *puVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  undefined1 auStack_38 [32];
  undefined8 *local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  Close(this);
  local_18 = (undefined8 *)0x0;
  iVar3 = (**(code **)(*(longlong *)param_2 + 8))
                    (param_2,&_GUID_7f9050d1_414f_43ac_8190_ee41dfc53f33,&local_18);
  puVar1 = local_18;
  if (iVar3 < 0) {
    if (local_18 != (undefined8 *)0x0) {
      local_18 = (undefined8 *)0x0;
      (**(code **)*puVar1)();
    }
  }
  else {
    puVar1 = *(undefined8 **)(this + 8);
    if (puVar1 != (undefined8 *)0x0) {
      *(undefined8 *)(this + 8) = 0;
      (**(code **)*puVar1)();
    }
    if (*(longlong *)(this + 8) != 0) {
      pcVar2 = (code *)swi(3);
      lVar4 = (*pcVar2)();
      return lVar4;
    }
    *(undefined8 **)(this + 8) = local_18;
    iVar3 = 0;
    *(void **)(this + 0x10) = param_1;
  }
  return iVar3;
}



===== SysDuplicateObject @ 140009620 =====

/* public: virtual long __cdecl CmRegistryProvider::SysDuplicateObject(void * __ptr64,void *
   __ptr64,void * __ptr64,class Windows::Rtl::SystemImplementation::CSilHandle * __ptr64,unsigned
   long,unsigned long,unsigned long) __ptr64 */

long __thiscall
CmRegistryProvider::SysDuplicateObject
          (CmRegistryProvider *this,void *param_1,void *param_2,void *param_3,CSilHandle *param_4,
          ulong param_5,ulong param_6,ulong param_7)

{
  return -0x3ffffbd7;
}



===== CheckFilterLoad @ 140009630 =====

/* long __cdecl CheckFilterLoad(struct _UNICODE_STRING,bool * __ptr64) */

long __cdecl CheckFilterLoad(undefined4 *param_1,char *param_2)

{
  long lVar1;
  undefined8 local_28;
  wchar_t *pwStack_20;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  *param_2 = '\0';
  local_28 = 0x2c002c;
  pwStack_20 = L"\\Device\\BootPartition\\";
  local_18 = *param_1;
  uStack_14 = param_1[1];
  uStack_10 = param_1[2];
  uStack_c = param_1[3];
  lVar1 = AreSameVolume(&local_18,&local_28,param_2);
  if (-1 < lVar1) {
    if ((*param_2 != '\0') && (lVar1 = OpenFile((_UNICODE_STRING *)&DAT_140012178), lVar1 < 0)) {
      return lVar1;
    }
    lVar1 = 0;
  }
  return lVar1;
}



===== Close @ 14000968c =====

/* public: void __cdecl BUCL::CVector<class BUCL::CVector<enum gsl::byte,class
   BUCL::Rtl::CCallDisposition>,class BUCL::Rtl::CCallDisposition>::Close(void) __ptr64 */

void __thiscall
BUCL::CVector<BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>,BUCL::Rtl::CCallDisposition>::
Close(CVector<BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>,BUCL::Rtl::CCallDisposition>
      *this)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(this + 8);
  lVar2 = *(longlong *)this;
  while (lVar2 != lVar3) {
    lVar2 = *(longlong *)(lVar3 + -0x18);
    lVar1 = *(longlong *)(lVar3 + -0x10);
    if (lVar2 != lVar1) {
      do {
        lVar1 = lVar1 + -1;
      } while (lVar1 != lVar2);
      *(longlong *)(lVar3 + -0x10) = lVar1;
    }
    if (lVar2 != 0) {
      ExFreePoolWithTag(lVar2,0);
    }
    *(undefined8 *)(lVar3 + -8) = 0;
    *(undefined8 *)(lVar3 + -0x10) = 0;
    *(undefined8 *)(lVar3 + -0x18) = 0;
    lVar3 = *(longlong *)(this + 8) + -0x18;
    *(longlong *)(this + 8) = lVar3;
    lVar2 = *(longlong *)this;
  }
  if (lVar2 != 0) {
    ExFreePoolWithTag(lVar2,0);
  }
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)this = 0;
  return;
}



===== SysClose @ 140009730 =====

/* public: virtual long __cdecl CmRegistryProvider::SysClose(void * __ptr64) __ptr64 */

long __thiscall CmRegistryProvider::SysClose(CmRegistryProvider *this,void *param_1)

{
  return 0;
}



===== CreateInterface @ 140009740 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl Windows::Rtl::CRtlRefCountedObjectBase<class
   CmRegistryProvider,class Windows::Rtl::SystemImplementation::IRtlRegistryProvider,class
   Windows::Rtl::SystemImplementation::IRtlObjectProvider,struct Windows::Rtl::IRtlObject,struct
   Windows::Rtl::Detail::CRtlRefCountedObjectBaseNoInterface,struct
   Windows::Rtl::Detail::CRtlRefCountedObjectBaseNoInterface,struct
   Windows::Rtl::Detail::CRtlRefCountedObjectBaseNoInterface>::CreateInterface(struct _GUID const &
   __ptr64,class Windows::Auto<struct Windows::Rtl::IRtlObject * __ptr64> * __ptr64) __ptr64 */

long __thiscall
Windows::Rtl::
CRtlRefCountedObjectBase<CmRegistryProvider,Windows::Rtl::SystemImplementation::IRtlRegistryProvider,Windows::Rtl::SystemImplementation::IRtlObjectProvider,Windows::Rtl::IRtlObject,Windows::Rtl::Detail::CRtlRefCountedObjectBaseNoInterface,Windows::Rtl::Detail::CRtlRefCountedObjectBaseNoInterface,Windows::Rtl::Detail::CRtlRefCountedObjectBaseNoInterface>
::CreateInterface(CRtlRefCountedObjectBase<CmRegistryProvider,Windows::Rtl::SystemImplementation::IRtlRegistryProvider,Windows::Rtl::SystemImplementation::IRtlObjectProvider,Windows::Rtl::IRtlObject,Windows::Rtl::Detail::CRtlRefCountedObjectBaseNoInterface,Windows::Rtl::Detail::CRtlRefCountedObjectBaseNoInterface,Windows::Rtl::Detail::CRtlRefCountedObjectBaseNoInterface>
                  *this,_GUID *param_1,Auto<Windows::Rtl::IRtlObject*___ptr64> *param_2)

{
  undefined8 *puVar1;
  code *pcVar2;
  long lVar3;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  if (param_2 == (Auto<Windows::Rtl::IRtlObject*___ptr64> *)0x0) {
    local_18 = 0x119;
    local_28 = "OneCore\\Internal\\Base\\inc\\rtl_object_library.h";
    local_20 = 
    "Windows::Rtl::CRtlRefCountedObjectBase<class CmRegistryProvider,class Windows::Rtl::SystemImplementation::IRtlRegistryProvider,class Windows::Rtl::SystemImplementation::IRtlObjectProvider,struct Windows::Rtl::IRtlObject,struct Windows::Rtl::Detail::CRtlRefCountedObjectBaseNoInterface,struct Windows::Rtl::Detail::CRtlRefCountedObjectBaseNoInterface,struct Windows::Rtl::Detail::CRtlRefCountedObjectBaseNoInterface>::CreateInterface"
    ;
    local_10 = "Not-null check failed: pObject";
    RtlReportErrorOrigination(&local_28,param_1,-0x3ffffff3);
    lVar3 = -0x3ffffff3;
  }
  else {
    puVar1 = *(undefined8 **)param_2;
    if (puVar1 != (undefined8 *)0x0) {
      *(undefined8 *)param_2 = 0;
      (**(code **)*puVar1)();
    }
    if (((((*(longlong *)param_1 == 0x49e9079f38218435) &&
          (*(longlong *)(param_1 + 8) == 0xcd882bb29c143fbb)) ||
         ((*(longlong *)param_1 == 0x492e3aa0c9056cc7 &&
          (*(longlong *)(param_1 + 8) == 0x7f85bb5f4bf649ae)))) ||
        ((*(longlong *)param_1 == 0x43ac414f7f9050d1 &&
         (*(longlong *)(param_1 + 8) == 0x333fc5df41ee9081)))) ||
       ((*(longlong *)param_1 == 0x49e9079f38218435 &&
        (*(longlong *)(param_1 + 8) == 0xcd882bb29c143fbb)))) {
      LOCK();
      *(int *)(this + 8) = *(int *)(this + 8) + 1;
      UNLOCK();
      if (*(longlong *)param_2 != 0) {
        pcVar2 = (code *)swi(3);
        lVar3 = (*pcVar2)();
        return lVar3;
      }
      *(CRtlRefCountedObjectBase<CmRegistryProvider,Windows::Rtl::SystemImplementation::IRtlRegistryProvider,Windows::Rtl::SystemImplementation::IRtlObjectProvider,Windows::Rtl::IRtlObject,Windows::Rtl::Detail::CRtlRefCountedObjectBaseNoInterface,Windows::Rtl::Detail::CRtlRefCountedObjectBaseNoInterface,Windows::Rtl::Detail::CRtlRefCountedObjectBaseNoInterface>
        **)param_2 = this;
    }
    lVar3 = 0;
  }
  return lVar3;
}



===== DetermineMountFlags @ 140009834 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* unsigned long __cdecl DetermineMountFlags(char const * __ptr64) */

ulong __cdecl DetermineMountFlags(char *param_1)

{
  char cVar1;
  byte bVar2;
  ulong uVar3;
  char cVar4;
  ulonglong uVar6;
  ulonglong uVar5;
  char *pcVar7;
  char *pcVar8;
  longlong lVar9;
  longlong lVar10;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  longlong lStack_40;
  char *local_38;
  undefined8 local_30;
  longlong lStack_28;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  bVar2 = 0;
  local_38 = (char *)0x0;
  lStack_40 = 0;
  if (param_1 == (char *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = 0xffffffffffffffff;
    do {
      uVar6 = uVar5;
      uVar5 = uVar6 + 1;
    } while (param_1[uVar5] != '\0');
    lStack_40 = uVar6 + 2;
    local_38 = param_1;
  }
  lVar9 = 6;
  if (uVar5 < 6) {
    uVar3 = 0x10;
  }
  else {
    pcVar7 = "cimfs{";
    local_30 = 6;
    local_48 = 6;
    lVar10 = 6;
    pcVar8 = local_38;
    while (lVar10 != 0) {
      cVar1 = *pcVar8;
      cVar4 = cVar1 + ' ';
      if (0x19 < (byte)(cVar1 + 0xbfU)) {
        cVar4 = cVar1;
      }
      if (cVar4 != *pcVar7) goto LAB_14000991c;
      if (lVar10 == 0) {
LAB_140009907:
        lStack_28 = lStack_40;
                    /* WARNING: Subroutine does not return */
        RtlRaiseStatus(0xc00000e5);
      }
      pcVar8 = pcVar8 + 1;
      lVar10 = lVar10 + -1;
      if (lVar9 == 0) goto LAB_140009907;
      pcVar7 = pcVar7 + 1;
      lVar9 = lVar9 + -1;
    }
    bVar2 = 1;
LAB_14000991c:
    uVar3 = (-(uint)bVar2 & 0xfffffff8) + 0x10;
  }
  return uVar3;
}



===== ElapsedMilliseconds @ 140009954 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: unsigned __int64 __cdecl Windows::Rtl::StopWatch::ElapsedMilliseconds(void)const __ptr64
    */

__uint64 __thiscall Windows::Rtl::StopWatch::ElapsedMilliseconds(StopWatch *this)

{
  longlong lVar1;
  __uint64 _Var2;
  undefined1 auStack_38 [32];
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  if (*this == (StopWatch)0x0) {
    lVar1 = 0;
  }
  else {
    local_18 = 0;
    lVar1 = KeQueryPerformanceCounter(&local_18);
    lVar1 = lVar1 - *(longlong *)(this + 0x10);
  }
  if (*(longlong *)(this + 8) + lVar1 == 0) {
    _Var2 = 0;
  }
  else if (*(ulonglong *)(this + 0x18) == 0) {
    _Var2 = 0xffffffffffffffff;
  }
  else {
    _Var2 = (ulonglong)((*(longlong *)(this + 8) + lVar1) * 1000) / *(ulonglong *)(this + 0x18);
  }
  return _Var2;
}



===== IsUnbufferedSil @ 1400099e0 =====

/* public: virtual bool __cdecl CmRegistryProvider::IsUnbufferedSil(void)const __ptr64 */

bool __thiscall CmRegistryProvider::IsUnbufferedSil(CmRegistryProvider *this)

{
  return true;
}



===== MapPath @ 1400099ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: bool __cdecl CmRegistryProvider::MapPath(struct _OBJECT_ATTRIBUTES * __ptr64,void *
   __ptr64 * __ptr64) __ptr64 */

bool __thiscall
CmRegistryProvider::MapPath(CmRegistryProvider *this,_OBJECT_ATTRIBUTES *param_1,void **param_2)

{
  short *psVar1;
  bool bVar2;
  long lVar3;
  undefined1 auStack_98 [32];
  int local_78 [2];
  undefined8 local_70;
  undefined8 uStack_68;
  wchar_t *local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  wchar_t *local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_98;
  local_60 = *(wchar_t **)(*(ushort **)(param_1 + 0x10) + 4);
  local_48 = L"\\registry\\machine\\override\\";
  local_58 = 0x36;
  uStack_50 = 0x36;
  if (0x35 < **(ushort **)(param_1 + 0x10)) {
    uStack_68 = 0x36;
    local_70 = 0x36;
    local_78[0] = 0;
    lVar3 = Windows::StringUtil::Rtl::
            CompareStringsByOrdinalCaseInvariant<_LUNICODE_STRING,_LUNICODE_STRING>
                      ((_LUNICODE_STRING *)&local_70,(_LUNICODE_STRING *)&local_58,local_78);
    if ((local_78[0] != 0) || (bVar2 = true, lVar3 < 0)) {
      bVar2 = false;
    }
    if (bVar2) {
      if (*(void **)(this + 0x70) == (void *)0x0) {
        return false;
      }
      *param_2 = *(void **)(this + 0x70);
      *(longlong *)(*(longlong *)(param_1 + 0x10) + 8) =
           *(longlong *)(*(longlong *)(param_1 + 0x10) + 8) + 0x36;
      **(short **)(param_1 + 0x10) = **(short **)(param_1 + 0x10) + -0x36;
      *(short *)(*(longlong *)(param_1 + 0x10) + 2) =
           *(short *)(*(longlong *)(param_1 + 0x10) + 2) + -0x36;
      psVar1 = *(short **)(param_1 + 0x10);
      if (*psVar1 == 0) {
        return true;
      }
      if (**(short **)(psVar1 + 4) == 0x5c) {
        *(short **)(psVar1 + 4) = *(short **)(psVar1 + 4) + 1;
        psVar1[1] = psVar1[1] + -2;
        *psVar1 = *psVar1 + -2;
        return true;
      }
      return true;
    }
  }
  uStack_68 = 0x34;
  local_48 = *(wchar_t **)(*(ushort **)(param_1 + 0x10) + 4);
  local_60 = L"\\registry\\machine\\software";
  local_70 = 0x34;
  if (0x33 < **(ushort **)(param_1 + 0x10)) {
    uStack_50 = 0x34;
    local_58 = 0x34;
    local_78[0] = 0;
    lVar3 = Windows::StringUtil::Rtl::
            CompareStringsByOrdinalCaseInvariant<_LUNICODE_STRING,_LUNICODE_STRING>
                      ((_LUNICODE_STRING *)&local_58,(_LUNICODE_STRING *)&local_70,local_78);
    if ((local_78[0] != 0) || (bVar2 = true, lVar3 < 0)) {
      bVar2 = false;
    }
    if (bVar2) {
      *param_2 = *(void **)(this + 0x68);
      *(longlong *)(*(longlong *)(param_1 + 0x10) + 8) =
           *(longlong *)(*(longlong *)(param_1 + 0x10) + 8) + 0x34;
      **(short **)(param_1 + 0x10) = **(short **)(param_1 + 0x10) + -0x34;
      *(short *)(*(longlong *)(param_1 + 0x10) + 2) =
           *(short *)(*(longlong *)(param_1 + 0x10) + 2) + -0x34;
      psVar1 = *(short **)(param_1 + 0x10);
      if ((*psVar1 != 0) && (**(short **)(psVar1 + 4) == 0x5c)) {
        *(short **)(psVar1 + 4) = *(short **)(psVar1 + 4) + 1;
        psVar1[1] = psVar1[1] + -2;
        *psVar1 = *psVar1 + -2;
      }
      return true;
    }
  }
  return false;
}



===== OpenVolume @ 140009bfc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl OpenVolume(struct _GUID const & __ptr64) */

long __cdecl OpenVolume(_GUID *param_1)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined1 auStack_58 [32];
  ulonglong *local_38 [2];
  ulonglong local_28;
  longlong lStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_38[0] = (ulonglong *)(ulonglong)(uint)local_38[0];
  local_28 = 0;
  lStack_20 = 0;
  uVar2 = RtlReallocateUnicodeString(0x14,0x14,(ushort *)&local_28);
  if ((int)uVar2 < 0) {
    if (lStack_20 != 0) {
      RtlDeallocateUnicodeString((longlong)&local_28);
    }
    return uVar2;
  }
  if ((local_28 >> 0x10 & 0xffff) - (local_28 & 0xffff) < 0x14) {
                    /* WARNING: Subroutine does not return */
    ExRaiseStatus(0xc00000e5);
  }
  memmove((void *)(lStack_20 + (local_28 >> 1 & 0x7fff) * 2),L"\\??\\Volume",0x14);
  local_28 = CONCAT62(local_28._2_6_,(ushort)local_28 + 0x14);
  local_38[0] = &local_28;
  uVar2 = Windows::StringUtil::Rtl::
          AppendGuid<Windows::AutoOperatorAmpersandHelper<_UNICODE_STRING,Windows::Auto<_UNICODE_STRING>_>_>
                    (0,param_1,local_38);
  if (-1 < (int)uVar2) {
    uVar3 = local_28 & 0xffff;
    if ((local_28 >> 0x10 & 0xffff) - uVar3 < 2) {
      local_38[0] = (ulonglong *)CONCAT62(local_38[0]._2_6_,2);
      local_38[0] = (ulonglong *)((ulonglong)local_38[0] & 0xffffffff);
      uVar1 = -(uint)((ushort)((ushort)local_28 + 2) < (ushort)local_28);
      uVar2 = uVar1 & 0xc0000095;
      if ((((int)uVar1 < 0) && ((int)uVar2 < 0)) ||
         (uVar2 = RtlReallocateUnicodeString
                            (uVar3,(ulonglong)(ushort)((ushort)local_28 + 2),(ushort *)&local_28),
         (int)uVar2 < 0)) goto LAB_140009ccd;
      uVar3 = local_28 & 0xffff;
    }
    *(undefined2 *)(lStack_20 + (uVar3 & 0xfffffffffffffffe)) = 0x5c;
    local_28 = CONCAT62(local_28._2_6_,(ushort)local_28 + 2);
    uVar2 = OpenFile((_UNICODE_STRING *)&local_28);
    if (-1 < (int)uVar2) {
      if (lStack_20 != 0) {
        RtlDeallocateUnicodeString((longlong)&local_28);
      }
      return 0;
    }
  }
LAB_140009ccd:
  if (lStack_20 != 0) {
    RtlDeallocateUnicodeString((longlong)&local_28);
  }
  return uVar2;
}



===== Release @ 140009db0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual void __cdecl Windows::Rtl::CRtlRefCountedObjectBase<class
   CmRegistryProvider,class Windows::Rtl::SystemImplementation::IRtlRegistryProvider,class
   Windows::Rtl::SystemImplementation::IRtlObjectProvider,struct Windows::Rtl::IRtlObject,struct
   Windows::Rtl::Detail::CRtlRefCountedObjectBaseNoInterface,struct
   Windows::Rtl::Detail::CRtlRefCountedObjectBaseNoInterface,struct
   Windows::Rtl::Detail::CRtlRefCountedObjectBaseNoInterface>::Release(void) __ptr64 */

void __thiscall
Windows::Rtl::
CRtlRefCountedObjectBase<CmRegistryProvider,Windows::Rtl::SystemImplementation::IRtlRegistryProvider,Windows::Rtl::SystemImplementation::IRtlObjectProvider,Windows::Rtl::IRtlObject,Windows::Rtl::Detail::CRtlRefCountedObjectBaseNoInterface,Windows::Rtl::Detail::CRtlRefCountedObjectBaseNoInterface,Windows::Rtl::Detail::CRtlRefCountedObjectBaseNoInterface>
::Release(CRtlRefCountedObjectBase<CmRegistryProvider,Windows::Rtl::SystemImplementation::IRtlRegistryProvider,Windows::Rtl::SystemImplementation::IRtlObjectProvider,Windows::Rtl::IRtlObject,Windows::Rtl::Detail::CRtlRefCountedObjectBaseNoInterface,Windows::Rtl::Detail::CRtlRefCountedObjectBaseNoInterface,Windows::Rtl::Detail::CRtlRefCountedObjectBaseNoInterface>
          *this)

{
  CRtlRefCountedObjectBase<CmRegistryProvider,Windows::Rtl::SystemImplementation::IRtlRegistryProvider,Windows::Rtl::SystemImplementation::IRtlObjectProvider,Windows::Rtl::IRtlObject,Windows::Rtl::Detail::CRtlRefCountedObjectBaseNoInterface,Windows::Rtl::Detail::CRtlRefCountedObjectBaseNoInterface,Windows::Rtl::Detail::CRtlRefCountedObjectBaseNoInterface>
  *pCVar1;
  int iVar2;
  
  LOCK();
  pCVar1 = this + 8;
  iVar2 = *(int *)pCVar1;
  *(int *)pCVar1 = *(int *)pCVar1 + -1;
  UNLOCK();
  if ((iVar2 == 1) &&
     (this != (CRtlRefCountedObjectBase<CmRegistryProvider,Windows::Rtl::SystemImplementation::IRtlRegistryProvider,Windows::Rtl::SystemImplementation::IRtlObjectProvider,Windows::Rtl::IRtlObject,Windows::Rtl::Detail::CRtlRefCountedObjectBaseNoInterface,Windows::Rtl::Detail::CRtlRefCountedObjectBaseNoInterface,Windows::Rtl::Detail::CRtlRefCountedObjectBaseNoInterface>
               *)0x0)) {
    (**(code **)(*(longlong *)this + 0x10))(this,1);
  }
  return;
}



===== SetErrorLogger @ 140009de4 =====

/* void __cdecl SetErrorLogger(void) */

void __cdecl SetErrorLogger(void)

{
  RtlRegisterErrorOriginationCallback();
  return;
}



===== Start @ 140009dfc =====

/* public: void __cdecl Windows::Rtl::StopWatch::Start(void) __ptr64 */

void __thiscall Windows::Rtl::StopWatch::Start(StopWatch *this)

{
  undefined8 uVar1;
  
  if (*this != (StopWatch)0x0) {
                    /* WARNING: Subroutine does not return */
    RtlRaiseStatus(0xc00000e5);
  }
  uVar1 = KeQueryPerformanceCounter(this + 0x18);
  *(undefined8 *)(this + 0x10) = uVar1;
  *this = (StopWatch)0x1;
  return;
}



===== Stop @ 140009e40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: class Windows::Rtl::StopWatch & __ptr64 __cdecl Windows::Rtl::StopWatch::Stop(void)
   __ptr64 */

StopWatch * __thiscall Windows::Rtl::StopWatch::Stop(StopWatch *this)

{
  longlong lVar1;
  undefined1 auStack_38 [32];
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  if (*this != (StopWatch)0x0) {
    local_18 = 0;
    lVar1 = KeQueryPerformanceCounter(&local_18);
    LOCK();
    *(longlong *)(this + 8) = *(longlong *)(this + 8) + (lVar1 - *(longlong *)(this + 0x10));
    UNLOCK();
    *this = (StopWatch)0x0;
  }
  return this;
}



===== StoreSourceCims @ 140009ea0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140009f46) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* long __cdecl StoreSourceCims(struct Windows::Vector<struct _UNICODE_STRING const > const &
   __ptr64) */

long __cdecl StoreSourceCims(Vector<_UNICODE_STRING_const_> *param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined8 *puVar10;
  undefined1 auStack_b8 [32];
  longlong local_98;
  undefined8 *puStack_90;
  undefined8 *local_88;
  uint local_80 [2];
  undefined8 local_78;
  longlong lStack_70;
  undefined8 local_68;
  longlong lStack_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStack_b8;
  lVar6 = *(longlong *)param_1;
  puVar10 = (undefined8 *)0x0;
  local_98 = 0;
  puStack_90 = (undefined8 *)0x0;
  puVar7 = (undefined8 *)0x0;
  lVar9 = *(longlong *)(param_1 + 8) * 0x10 + lVar6;
  local_88 = (undefined8 *)0x0;
  do {
    lVar1 = local_98;
    if (lVar6 == lVar9) {
      uVar3 = 0;
      local_98 = _g_SourceCims;
      puStack_90 = DAT_140017280;
      local_88 = DAT_140017288;
      _g_SourceCims = lVar1;
      DAT_140017280 = puVar7;
      DAT_140017288 = puVar10;
LAB_14000a0c2:
      BUCL::CVector<Windows::Auto<_UNICODE_STRING>,BUCL::Rtl::CCallDisposition>::
      ~CVector<Windows::Auto<_UNICODE_STRING>,BUCL::Rtl::CCallDisposition>
                ((CVector<Windows::Auto<_UNICODE_STRING>,BUCL::Rtl::CCallDisposition> *)&local_98);
      return uVar3;
    }
    local_78 = 0;
    lStack_70 = 0;
    local_68 = 0;
    lStack_60 = 0;
    uVar3 = RtlDuplicateUnicodeString(0,lVar6,&local_68);
    lVar1 = lStack_60;
    uVar2 = local_68;
    if ((int)uVar3 < 0) {
      if (lStack_60 != 0) {
        RtlDeallocateUnicodeString((longlong)&local_68);
      }
LAB_14000a02a:
      if (lStack_70 != 0) {
        RtlDeallocateUnicodeString((longlong)&local_78);
      }
      goto LAB_14000a0c2;
    }
    local_68 = 0;
    lStack_60 = 0;
    local_78 = uVar2;
    lStack_70 = lVar1;
    if (puVar7 == puVar10) {
      uVar4 = (longlong)puVar10 - local_98 >> 4;
      uVar5 = uVar4;
      if (uVar4 != 0xffffffffffffffff) {
        uVar5 = uVar4 + 1;
      }
      uVar3 = 0xc0000095;
      if (uVar4 != 0xffffffffffffffff) {
        uVar3 = 0;
      }
      if (-1 < (int)uVar3) {
        if (uVar4 < uVar5) {
          if (uVar4 < 4) {
            uVar8 = 4;
          }
          else {
            if (uVar4 < 0x21) {
              uVar8 = uVar4 * 2;
            }
            else {
              uVar8 = (uVar4 >> 1) + uVar4;
            }
            uVar3 = -(uint)(uVar8 < uVar4) & 0xc0000095;
            if ((int)-(uint)(uVar8 < uVar4) < 0) goto LAB_14000a012;
          }
          if (uVar8 < uVar5) {
            uVar8 = uVar5;
          }
          if (uVar8 < 0xfffffffffffffff) {
            BUCL::CVector<Windows::Auto<_UNICODE_STRING>,BUCL::Rtl::CCallDisposition>::Reserve
                      ((CVector<Windows::Auto<_UNICODE_STRING>,BUCL::Rtl::CCallDisposition> *)
                       &local_98,(__uint64)local_80);
            puVar7 = puStack_90;
            puVar10 = local_88;
            uVar3 = 0;
            if ((int)local_80[0] < 0) {
              uVar3 = local_80[0];
            }
          }
          else {
            uVar3 = 0xc0000017;
          }
        }
        else {
          uVar3 = 0;
        }
LAB_14000a012:
        uVar3 = -(uint)((int)uVar3 < 0) & uVar3;
      }
      if (-1 < (int)uVar3) goto LAB_14000a042;
      if ((int)uVar3 < 0) goto LAB_14000a02a;
    }
    else {
LAB_14000a042:
      if (puVar7 != (undefined8 *)0x0) {
        *puVar7 = 0;
        puVar7[1] = 0;
      }
      local_78 = *puVar7;
      lStack_70 = puVar7[1];
      *puVar7 = uVar2;
      puVar7[1] = lVar1;
      puVar7 = puVar7 + 2;
      puStack_90 = puVar7;
    }
    if (lStack_70 != 0) {
      RtlDeallocateUnicodeString((longlong)&local_78);
      local_78 = 0;
      lStack_70 = 0;
    }
    lVar6 = lVar6 + 0x10;
  } while( true );
}



===== SysCreateKey @ 14000a120 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CmRegistryProvider::SysCreateKey(unsigned long,class
   Windows::Rtl::SystemImplementation::CSilHandle * __ptr64,unsigned long,struct _OBJECT_ATTRIBUTES
   & __ptr64,unsigned long,struct _UNICODE_STRING * __ptr64,unsigned long,void * __ptr64,unsigned
   long * __ptr64) __ptr64 */

long __thiscall
CmRegistryProvider::SysCreateKey
          (CmRegistryProvider *this,ulong param_1,CSilHandle *param_2,ulong param_3,
          _OBJECT_ATTRIBUTES *param_4,ulong param_5,_UNICODE_STRING *param_6,ulong param_7,
          void *param_8,ulong *param_9)

{
  char *pcVar1;
  bool bVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined4 in_register_00000014;
  _OBJECT_ATTRIBUTES *p_Var6;
  void *pvVar7;
  undefined1 auStack_f8 [32];
  ulong local_d8;
  void **local_d0;
  char *local_b8;
  char *local_b0;
  undefined8 local_a8;
  char *local_a0;
  void *local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 *local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  void *local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_f8;
  if (param_9 != (ulong *)0x0) {
    *param_9 = 0;
  }
  pcVar1 = *(char **)(this + 0x60);
  if (*pcVar1 != '\0') {
                    /* WARNING: Subroutine does not return */
    RtlRaiseStatus(0xc00000e5);
  }
  uVar4 = KeQueryPerformanceCounter(pcVar1 + 0x18,CONCAT44(in_register_00000014,param_1));
  *pcVar1 = '\x01';
  *(undefined8 *)(pcVar1 + 0x10) = uVar4;
  p_Var6 = (_OBJECT_ATTRIBUTES *)&local_90;
  local_90 = *(undefined8 *)param_4;
  uStack_88 = *(undefined8 *)(param_4 + 8);
  local_60 = (void *)0x0;
  local_58 = **(undefined8 **)(param_4 + 0x10);
  uStack_50 = (*(undefined8 **)(param_4 + 0x10))[1];
  local_80 = &local_58;
  local_70 = *(undefined8 *)(param_4 + 0x20);
  uStack_68 = *(undefined8 *)(param_4 + 0x28);
  uStack_78 = *(undefined8 *)(param_4 + 0x18);
  bVar2 = MapPath(this,p_Var6,&local_60);
  if (bVar2) {
    local_d0 = &local_98;
    local_d8 = param_7;
    local_98 = (void *)0x0;
    pvVar7 = local_60;
    iVar3 = (**(code **)(this + 0x18))(1,local_60,param_3 | 0x100,&local_90);
    if (iVar3 < 0) {
      local_a8 = 0xe3;
      local_b8 = "onecore\\base\\servicing\\globmerger\\kernel\\kernelmerger.cpp";
      local_b0 = "CmRegistryProvider::SysCreateKey";
      local_a0 = 
      "m_Fns.CreateOrOpenKey( 1 , Hive, DesiredAccess | (0x0100), &LocalAttr, CreateOptions, &NewKey)"
      ;
      RtlReportErrorOrigination(&local_b8,pvVar7,iVar3);
    }
    else {
      iVar3 = Windows::Rtl::SystemImplementation::CSilHandle::Assign
                        (param_2,local_98,(IRtlObjectProvider *)this);
      if (-1 < iVar3) {
        if (param_9 != (ulong *)0x0) {
          *param_9 = 1;
        }
        pcVar1 = *(char **)(this + 0x60);
        if (*pcVar1 != '\0') {
          local_60 = (void *)0x0;
          lVar5 = KeQueryPerformanceCounter(&local_60);
          LOCK();
          *(longlong *)(pcVar1 + 8) =
               *(longlong *)(pcVar1 + 8) + (lVar5 - *(longlong *)(pcVar1 + 0x10));
          UNLOCK();
          *pcVar1 = '\0';
        }
        return 0;
      }
    }
    pcVar1 = *(char **)(this + 0x60);
    if (*pcVar1 != '\0') {
      local_60 = (void *)0x0;
      lVar5 = KeQueryPerformanceCounter(&local_60);
      LOCK();
      *(longlong *)(pcVar1 + 8) = *(longlong *)(pcVar1 + 8) + (lVar5 - *(longlong *)(pcVar1 + 0x10))
      ;
      UNLOCK();
      *pcVar1 = '\0';
    }
  }
  else {
    local_a8 = 0xd8;
    local_b8 = "onecore\\base\\servicing\\globmerger\\kernel\\kernelmerger.cpp";
    local_a0 = (char *)0x0;
    local_b0 = "CmRegistryProvider::SysCreateKey";
    RtlReportErrorOrigination(&local_b8,p_Var6,-0x3fffffc7);
    pcVar1 = *(char **)(this + 0x60);
    if (*pcVar1 != '\0') {
      local_60 = (void *)0x0;
      lVar5 = KeQueryPerformanceCounter(&local_60);
      LOCK();
      *(longlong *)(pcVar1 + 8) = *(longlong *)(pcVar1 + 8) + (lVar5 - *(longlong *)(pcVar1 + 0x10))
      ;
      UNLOCK();
      *pcVar1 = '\0';
    }
    iVar3 = -0x3fffffc7;
  }
  return iVar3;
}



===== SysEnumerateKey @ 14000a360 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: virtual long __cdecl CmRegistryProvider::SysEnumerateKey(unsigned long,void *
   __ptr64,unsigned long,enum _KEY_INFORMATION_CLASS,class Windows::Auto<struct _LBLOB> *
   __ptr64,struct _LUNICODE_STRING const & __ptr64,unsigned long * __ptr64) __ptr64 */

long __thiscall
CmRegistryProvider::SysEnumerateKey
          (CmRegistryProvider *this,ulong param_1,void *param_2,ulong param_3,
          _KEY_INFORMATION_CLASS param_4,Auto<_LBLOB> *param_5,_LUNICODE_STRING *param_6,
          ulong *param_7)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  char **ppcVar4;
  undefined4 in_register_00000014;
  ulonglong uVar5;
  undefined1 auStack_d8 [32];
  undefined4 local_b8;
  uint *local_b0;
  OnBlockExitImpl<<lambda_b98ed077e732c52fc62505173bcb5195>_> local_98 [8];
  CmRegistryProvider *local_90;
  char *local_88;
  char *local_80;
  undefined8 local_78;
  char *local_70;
  char *local_68;
  char *local_60;
  undefined8 local_58;
  char *local_50;
  uint local_48 [2];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_d8;
  if (param_7 != (ulong *)0x0) {
    *param_7 = 0;
  }
  lVar1 = *(longlong *)(this + 0x60);
  if (*(char *)(lVar1 + 200) != '\0') {
                    /* WARNING: Subroutine does not return */
    RtlRaiseStatus(0xc00000e5);
  }
  uVar3 = KeQueryPerformanceCounter(lVar1 + 0xe0,CONCAT44(in_register_00000014,param_1));
  local_b0 = local_48;
  *(undefined8 *)(lVar1 + 0xd8) = uVar3;
  uVar5 = (ulonglong)param_3;
  *(undefined1 *)(lVar1 + 200) = 1;
  local_48[0] = 0;
  local_b8 = *(undefined4 *)(param_5 + 8);
  local_98[0] = (OnBlockExitImpl<<lambda_b98ed077e732c52fc62505173bcb5195>_>)0x1;
  local_90 = this;
  iVar2 = (**(code **)(this + 0x28))(param_2,uVar5,param_4,*(undefined8 *)(param_5 + 0x10));
  if (iVar2 == -0x3fffffdd) {
    uVar3 = RtlAllocateLBlob((ulonglong)local_48[0],(undefined8 *)param_5);
    iVar2 = (int)uVar3;
    if (iVar2 < 0) goto LAB_14000a4c8;
    local_b8 = *(undefined4 *)(param_5 + 8);
    local_b0 = local_48;
    uVar5 = (ulonglong)param_3;
    iVar2 = (**(code **)(this + 0x28))(param_2,uVar5,param_4,*(undefined8 *)(param_5 + 0x10));
    if (-1 < iVar2) goto LAB_14000a4d5;
    local_58 = 0x1ee;
    local_68 = "onecore\\base\\servicing\\globmerger\\kernel\\kernelmerger.cpp";
    ppcVar4 = &local_68;
    local_60 = "CmRegistryProvider::SysEnumerateKey";
    local_50 = 
    "m_Fns.EnumKey( KeyHandle, Index, KeyInformationClass, KeyInformation->Buffer, static_cast<ULONG>(KeyInformation->MaximumLength), &ResultLength)"
    ;
  }
  else {
    if (-1 < iVar2) {
LAB_14000a4d5:
      *(ulonglong *)param_5 = (ulonglong)local_48[0];
      if (param_7 != (ulong *)0x0) {
        *param_7 = 1;
      }
      Windows::Detail::OnBlockExitImpl<<lambda_b98ed077e732c52fc62505173bcb5195>_>::
      ~OnBlockExitImpl<<lambda_b98ed077e732c52fc62505173bcb5195>_>(local_98);
      return 0;
    }
    local_78 = 0x1e1;
    local_88 = "onecore\\base\\servicing\\globmerger\\kernel\\kernelmerger.cpp";
    ppcVar4 = &local_88;
    local_80 = "CmRegistryProvider::SysEnumerateKey";
    local_70 = 
    "m_Fns.EnumKey( KeyHandle, Index, KeyInformationClass, KeyInformation->Buffer, static_cast<ULONG>(KeyInformation->MaximumLength), &ResultLength)"
    ;
  }
  RtlReportErrorOrigination(ppcVar4,uVar5,iVar2);
LAB_14000a4c8:
  Windows::Detail::OnBlockExitImpl<<lambda_b98ed077e732c52fc62505173bcb5195>_>::
  ~OnBlockExitImpl<<lambda_b98ed077e732c52fc62505173bcb5195>_>(local_98);
  return iVar2;
}



===== SysEnumerateValueKey @ 14000a520 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: virtual long __cdecl CmRegistryProvider::SysEnumerateValueKey(unsigned long,void *
   __ptr64,unsigned long,enum _KEY_VALUE_INFORMATION_CLASS,class Windows::Auto<struct _LBLOB> *
   __ptr64,unsigned long * __ptr64) __ptr64 */

long __thiscall
CmRegistryProvider::SysEnumerateValueKey
          (CmRegistryProvider *this,ulong param_1,void *param_2,ulong param_3,
          _KEY_VALUE_INFORMATION_CLASS param_4,Auto<_LBLOB> *param_5,ulong *param_6)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  char **ppcVar4;
  undefined4 in_register_00000014;
  ulonglong uVar5;
  undefined1 auStack_d8 [32];
  undefined4 local_b8;
  uint *local_b0;
  OnBlockExitImpl<<lambda_215c4eb5720f7bbaa58112496b2362ea>_> local_98 [8];
  CmRegistryProvider *local_90;
  char *local_88;
  char *local_80;
  undefined8 local_78;
  char *local_70;
  char *local_68;
  char *local_60;
  undefined8 local_58;
  char *local_50;
  uint local_48 [2];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_d8;
  if (param_6 != (ulong *)0x0) {
    *param_6 = 0;
  }
  lVar1 = *(longlong *)(this + 0x60);
  if (*(char *)(lVar1 + 0xf0) != '\0') {
                    /* WARNING: Subroutine does not return */
    RtlRaiseStatus(0xc00000e5);
  }
  uVar3 = KeQueryPerformanceCounter(lVar1 + 0x108,CONCAT44(in_register_00000014,param_1));
  local_b0 = local_48;
  *(undefined8 *)(lVar1 + 0x100) = uVar3;
  uVar5 = (ulonglong)param_3;
  *(undefined1 *)(lVar1 + 0xf0) = 1;
  local_48[0] = 0;
  local_b8 = *(undefined4 *)(param_5 + 8);
  local_98[0] = (OnBlockExitImpl<<lambda_215c4eb5720f7bbaa58112496b2362ea>_>)0x1;
  local_90 = this;
  iVar2 = (**(code **)(this + 0x40))(param_2,uVar5,param_4,*(undefined8 *)(param_5 + 0x10));
  if (iVar2 == -0x3fffffdd) {
    uVar3 = RtlAllocateLBlob((ulonglong)local_48[0],(undefined8 *)param_5);
    iVar2 = (int)uVar3;
    if (iVar2 < 0) goto LAB_14000a688;
    local_b8 = *(undefined4 *)(param_5 + 8);
    local_b0 = local_48;
    uVar5 = (ulonglong)param_3;
    iVar2 = (**(code **)(this + 0x40))(param_2,uVar5,param_4,*(undefined8 *)(param_5 + 0x10));
    if (-1 < iVar2) goto LAB_14000a695;
    local_58 = 0x21e;
    local_68 = "onecore\\base\\servicing\\globmerger\\kernel\\kernelmerger.cpp";
    ppcVar4 = &local_68;
    local_60 = "CmRegistryProvider::SysEnumerateValueKey";
    local_50 = 
    "m_Fns.EnumValue( KeyHandle, Index, KeyValueInformationClass, KeyValueInformation->Buffer, static_cast<ULONG>(KeyValueInformation->MaximumLength), &ResultLength)"
    ;
  }
  else {
    if (-1 < iVar2) {
LAB_14000a695:
      *(ulonglong *)param_5 = (ulonglong)local_48[0];
      if (param_6 != (ulong *)0x0) {
        *param_6 = 1;
      }
      Windows::Detail::OnBlockExitImpl<<lambda_215c4eb5720f7bbaa58112496b2362ea>_>::
      ~OnBlockExitImpl<<lambda_215c4eb5720f7bbaa58112496b2362ea>_>(local_98);
      return 0;
    }
    local_78 = 0x211;
    local_88 = "onecore\\base\\servicing\\globmerger\\kernel\\kernelmerger.cpp";
    ppcVar4 = &local_88;
    local_80 = "CmRegistryProvider::SysEnumerateValueKey";
    local_70 = 
    "m_Fns.EnumValue( KeyHandle, Index, KeyValueInformationClass, KeyValueInformation->Buffer, static_cast<ULONG>(KeyValueInformation->MaximumLength), &ResultLength)"
    ;
  }
  RtlReportErrorOrigination(ppcVar4,uVar5,iVar2);
LAB_14000a688:
  Windows::Detail::OnBlockExitImpl<<lambda_215c4eb5720f7bbaa58112496b2362ea>_>::
  ~OnBlockExitImpl<<lambda_215c4eb5720f7bbaa58112496b2362ea>_>(local_98);
  return iVar2;
}



===== SysOpenKey @ 14000a6e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CmRegistryProvider::SysOpenKey(unsigned long,class
   Windows::Rtl::SystemImplementation::CSilHandle * __ptr64,unsigned long,struct _OBJECT_ATTRIBUTES
   & __ptr64,unsigned long,void * __ptr64,unsigned long * __ptr64) __ptr64 */

long __thiscall
CmRegistryProvider::SysOpenKey
          (CmRegistryProvider *this,ulong param_1,CSilHandle *param_2,ulong param_3,
          _OBJECT_ATTRIBUTES *param_4,ulong param_5,void *param_6,ulong *param_7)

{
  longlong lVar1;
  bool bVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  _OBJECT_ATTRIBUTES *p_Var6;
  void *pvVar7;
  undefined1 auStack_f8 [32];
  ulong local_d8;
  void **local_d0;
  char *local_b8;
  char *local_b0;
  undefined8 local_a8;
  char *local_a0;
  void *local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 *local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  void *local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_f8;
  if (param_7 != (ulong *)0x0) {
    *param_7 = 0;
  }
  lVar1 = *(longlong *)(this + 0x60);
  if (*(char *)(lVar1 + 0x28) != '\0') {
                    /* WARNING: Subroutine does not return */
    RtlRaiseStatus(0xc00000e5);
  }
  uVar4 = KeQueryPerformanceCounter(lVar1 + 0x40);
  *(undefined1 *)(lVar1 + 0x28) = 1;
  *(undefined8 *)(lVar1 + 0x38) = uVar4;
  p_Var6 = (_OBJECT_ATTRIBUTES *)&local_90;
  local_90 = *(undefined8 *)param_4;
  uStack_88 = *(undefined8 *)(param_4 + 8);
  local_58 = **(undefined8 **)(param_4 + 0x10);
  uStack_50 = (*(undefined8 **)(param_4 + 0x10))[1];
  local_80 = &local_58;
  local_70 = *(undefined8 *)(param_4 + 0x20);
  uStack_68 = *(undefined8 *)(param_4 + 0x28);
  uStack_78 = *(undefined8 *)(param_4 + 0x18);
  local_60 = (void *)0x0;
  bVar2 = MapPath(this,p_Var6,&local_60);
  if (bVar2) {
    local_d0 = &local_98;
    local_d8 = param_5;
    local_98 = (void *)0x0;
    pvVar7 = local_60;
    iVar3 = (**(code **)(this + 0x18))(0,local_60,param_3 | 0x100,&local_90);
    if (iVar3 != -0x3fffffcc) {
      if (iVar3 < 0) {
        local_a8 = 0x119;
        local_b8 = "onecore\\base\\servicing\\globmerger\\kernel\\kernelmerger.cpp";
        local_b0 = "CmRegistryProvider::SysOpenKey";
        local_a0 = 
        "m_Fns.CreateOrOpenKey( 0 , Hive, DesiredAccess | (0x0100), &LocalAttr, OpenOptions, &NewKey)"
        ;
        RtlReportErrorOrigination(&local_b8,pvVar7,iVar3);
      }
      else {
        iVar3 = Windows::Rtl::SystemImplementation::CSilHandle::Assign
                          (param_2,local_98,(IRtlObjectProvider *)this);
        if (-1 < iVar3) {
          if (param_7 != (ulong *)0x0) {
            *param_7 = 1;
          }
          goto LAB_14000a909;
        }
      }
      lVar1 = *(longlong *)(this + 0x60);
      if (*(char *)(lVar1 + 0x28) == '\0') {
        return iVar3;
      }
      local_60 = (void *)0x0;
      lVar5 = KeQueryPerformanceCounter(&local_60);
      LOCK();
      *(longlong *)(lVar1 + 0x30) =
           *(longlong *)(lVar1 + 0x30) + (lVar5 - *(longlong *)(lVar1 + 0x38));
      UNLOCK();
      *(undefined1 *)(lVar1 + 0x28) = 0;
      return iVar3;
    }
    if ((param_1 & 1) == 0) {
      local_a8 = 0x123;
      local_b8 = "onecore\\base\\servicing\\globmerger\\kernel\\kernelmerger.cpp";
      local_a0 = (char *)0x0;
      local_b0 = "CmRegistryProvider::SysOpenKey";
      RtlReportErrorOrigination(&local_b8,pvVar7,-0x3fffffcc);
      lVar1 = *(longlong *)(this + 0x60);
      if (*(char *)(lVar1 + 0x28) != '\0') {
        local_60 = (void *)0x0;
        lVar5 = KeQueryPerformanceCounter(&local_60);
        LOCK();
        *(longlong *)(lVar1 + 0x30) =
             *(longlong *)(lVar1 + 0x30) + (lVar5 - *(longlong *)(lVar1 + 0x38));
        UNLOCK();
        *(undefined1 *)(lVar1 + 0x28) = 0;
      }
      return -0x3fffffcc;
    }
    if (param_7 != (ulong *)0x0) {
      *param_7 = 2;
    }
  }
  else {
    if ((param_1 & 4) == 0) {
      local_a8 = 0x10c;
      local_b8 = "onecore\\base\\servicing\\globmerger\\kernel\\kernelmerger.cpp";
      local_a0 = (char *)0x0;
      local_b0 = "CmRegistryProvider::SysOpenKey";
      RtlReportErrorOrigination(&local_b8,p_Var6,-0x3fffffc7);
      lVar1 = *(longlong *)(this + 0x60);
      if (*(char *)(lVar1 + 0x28) != '\0') {
        local_60 = (void *)0x0;
        lVar5 = KeQueryPerformanceCounter(&local_60);
        LOCK();
        *(longlong *)(lVar1 + 0x30) =
             *(longlong *)(lVar1 + 0x30) + (lVar5 - *(longlong *)(lVar1 + 0x38));
        UNLOCK();
        *(undefined1 *)(lVar1 + 0x28) = 0;
      }
      return -0x3fffffc7;
    }
    if (param_7 != (ulong *)0x0) {
      *param_7 = 4;
    }
  }
LAB_14000a909:
  lVar1 = *(longlong *)(this + 0x60);
  if (*(char *)(lVar1 + 0x28) != '\0') {
    local_60 = (void *)0x0;
    lVar5 = KeQueryPerformanceCounter(&local_60);
    LOCK();
    *(longlong *)(lVar1 + 0x30) =
         *(longlong *)(lVar1 + 0x30) + (lVar5 - *(longlong *)(lVar1 + 0x38));
    UNLOCK();
    *(undefined1 *)(lVar1 + 0x28) = 0;
  }
  return 0;
}



===== SysQueryKey @ 14000a9d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CmRegistryProvider::SysQueryKey(void * __ptr64,enum
   _KEY_INFORMATION_CLASS,class Windows::Auto<struct _LBLOB> * __ptr64) __ptr64 */

long __thiscall
CmRegistryProvider::SysQueryKey
          (CmRegistryProvider *this,void *param_1,_KEY_INFORMATION_CLASS param_2,
          Auto<_LBLOB> *param_3)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined1 auStack_a8 [32];
  uint *local_88;
  char *local_78;
  char *local_70;
  undefined8 local_68;
  char *local_60;
  uint local_58 [2];
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_a8;
  lVar1 = *(longlong *)(this + 0x60);
  if (*(char *)(lVar1 + 0x50) != '\0') {
                    /* WARNING: Subroutine does not return */
    RtlRaiseStatus(0xc00000e5);
  }
  lVar4 = lVar1 + 0x68;
  uVar3 = KeQueryPerformanceCounter();
  *(undefined1 *)(lVar1 + 0x50) = 1;
  *(undefined8 *)(lVar1 + 0x60) = uVar3;
  uVar3 = RtlReallocateLBlob(lVar4,0x30,(ulonglong *)param_3);
  iVar2 = (int)uVar3;
  if (-1 < iVar2) {
    local_88 = local_58;
    uVar5 = (ulonglong)param_2;
    local_58[0] = 0;
    iVar2 = (**(code **)(this + 0x20))
                      (param_1,uVar5,*(undefined8 *)(param_3 + 0x10),*(undefined4 *)(param_3 + 8));
    if (iVar2 == -0x3fffffdd) {
      uVar3 = RtlAllocateLBlob((ulonglong)local_58[0],(undefined8 *)param_3);
      iVar2 = (int)uVar3;
      if (iVar2 < 0) goto LAB_14000aa46;
      local_88 = local_58;
      uVar5 = (ulonglong)param_2;
      iVar2 = (**(code **)(this + 0x20))
                        (param_1,uVar5,*(undefined8 *)(param_3 + 0x10),*(undefined4 *)(param_3 + 8))
      ;
      if (-1 < iVar2) goto LAB_14000ab28;
      local_68 = 0x158;
    }
    else {
      if (-1 < iVar2) {
LAB_14000ab28:
        *(ulonglong *)param_3 = (ulonglong)local_58[0];
        lVar1 = *(longlong *)(this + 0x60);
        if (*(char *)(lVar1 + 0x50) != '\0') {
          local_50 = 0;
          lVar4 = KeQueryPerformanceCounter(&local_50);
          LOCK();
          *(longlong *)(lVar1 + 0x58) =
               *(longlong *)(lVar1 + 0x58) + (lVar4 - *(longlong *)(lVar1 + 0x60));
          UNLOCK();
          *(undefined1 *)(lVar1 + 0x50) = 0;
        }
        return 0;
      }
      local_68 = 0x14c;
    }
    local_78 = "onecore\\base\\servicing\\globmerger\\kernel\\kernelmerger.cpp";
    local_70 = "CmRegistryProvider::SysQueryKey";
    local_60 = 
    "m_Fns.QueryKey( KeyHandle, KeyInformationClass, KeyInformation->Buffer, static_cast<ULONG>(KeyInformation->MaximumLength), &ResultLength)"
    ;
    RtlReportErrorOrigination(&local_78,uVar5,iVar2);
  }
LAB_14000aa46:
  lVar1 = *(longlong *)(this + 0x60);
  if (*(char *)(lVar1 + 0x50) != '\0') {
    local_50 = 0;
    lVar4 = KeQueryPerformanceCounter(&local_50);
    LOCK();
    *(longlong *)(lVar1 + 0x58) =
         *(longlong *)(lVar1 + 0x58) + (lVar4 - *(longlong *)(lVar1 + 0x60));
    UNLOCK();
    *(undefined1 *)(lVar1 + 0x50) = 0;
  }
  return iVar2;
}



===== SysQuerySecurityObject @ 14000ab80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: virtual long __cdecl CmRegistryProvider::SysQuerySecurityObject(unsigned long,void *
   __ptr64,unsigned long,void * __ptr64,unsigned long,unsigned long * __ptr64,unsigned long *
   __ptr64) __ptr64 */

long __thiscall
CmRegistryProvider::SysQuerySecurityObject
          (CmRegistryProvider *this,ulong param_1,void *param_2,ulong param_3,void *param_4,
          ulong param_5,ulong *param_6,ulong *param_7)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 in_register_00000014;
  ulong *puVar4;
  undefined1 auStack_b8 [48];
  OnBlockExitImpl<<lambda_32d53f16296fbe318a7a20974fbdbb6f>_> local_88 [8];
  CmRegistryProvider *local_80;
  char *local_78;
  char *local_70;
  undefined8 local_68;
  char *local_60;
  ulong local_58 [2];
  ulong local_50 [2];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_b8;
  if (param_7 != (ulong *)0x0) {
    *param_7 = 0;
  }
  if (param_6 != (ulong *)0x0) {
    *param_6 = 0;
  }
  lVar1 = *(longlong *)(this + 0x60);
  local_50[0] = param_3;
  if (*(char *)(lVar1 + 0x118) != '\0') {
                    /* WARNING: Subroutine does not return */
    RtlRaiseStatus(0xc00000e5);
  }
  uVar3 = KeQueryPerformanceCounter(lVar1 + 0x130,CONCAT44(in_register_00000014,param_1));
  *(undefined1 *)(lVar1 + 0x118) = 1;
  *(undefined8 *)(lVar1 + 0x128) = uVar3;
  puVar4 = local_50;
  local_58[0] = param_5;
  local_88[0] = (OnBlockExitImpl<<lambda_32d53f16296fbe318a7a20974fbdbb6f>_>)0x1;
  local_80 = this;
  iVar2 = (**(code **)(this + 0x48))(param_2,puVar4,param_4,local_58);
  if (iVar2 < 0) {
    local_68 = 0x23a;
    local_78 = "onecore\\base\\servicing\\globmerger\\kernel\\kernelmerger.cpp";
    local_70 = "CmRegistryProvider::SysQuerySecurityObject";
    local_60 = "m_Fns.QuerySecurity(Handle, &SecurityInformation, SecurityDescriptor, &LocalLength)"
    ;
    RtlReportErrorOrigination(&local_78,puVar4,iVar2);
    Windows::Detail::OnBlockExitImpl<<lambda_32d53f16296fbe318a7a20974fbdbb6f>_>::
    ~OnBlockExitImpl<<lambda_32d53f16296fbe318a7a20974fbdbb6f>_>(local_88);
  }
  else {
    *param_6 = local_58[0];
    if (param_7 != (ulong *)0x0) {
      *param_7 = 1;
    }
    Windows::Detail::OnBlockExitImpl<<lambda_32d53f16296fbe318a7a20974fbdbb6f>_>::
    ~OnBlockExitImpl<<lambda_32d53f16296fbe318a7a20974fbdbb6f>_>(local_88);
    iVar2 = 0;
  }
  return iVar2;
}



===== SysQueryValueKey @ 14000acc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: virtual long __cdecl CmRegistryProvider::SysQueryValueKey(unsigned long,void *
   __ptr64,struct _UNICODE_STRING & __ptr64,enum _KEY_VALUE_INFORMATION_CLASS,class
   Windows::Auto<struct _LBLOB> * __ptr64,unsigned long * __ptr64) __ptr64 */

long __thiscall
CmRegistryProvider::SysQueryValueKey
          (CmRegistryProvider *this,ulong param_1,void *param_2,_UNICODE_STRING *param_3,
          _KEY_VALUE_INFORMATION_CLASS param_4,Auto<_LBLOB> *param_5,ulong *param_6)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  char **ppcVar5;
  char **ppcVar6;
  undefined1 auStack_d8 [32];
  undefined4 local_b8;
  uint *local_b0;
  char *local_98;
  char *pcStack_90;
  undefined8 local_88;
  undefined8 local_80;
  OnBlockExitImpl<<lambda_3156162d9f3dab841a21b521aa54357f>_> local_78 [8];
  CmRegistryProvider *local_70;
  char *local_68;
  char *local_60;
  undefined8 local_58;
  char *local_50;
  uint local_48 [2];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_d8;
  if (param_6 != (ulong *)0x0) {
    *param_6 = 0;
  }
  lVar1 = *(longlong *)(this + 0x60);
  if (*(char *)(lVar1 + 0x78) != '\0') {
                    /* WARNING: Subroutine does not return */
    RtlRaiseStatus(0xc00000e5);
  }
  uVar4 = KeQueryPerformanceCounter(lVar1 + 0x90);
  local_b0 = local_48;
  *(undefined8 *)(lVar1 + 0x88) = uVar4;
  *(undefined1 *)(lVar1 + 0x78) = 1;
  local_b8 = *(undefined4 *)(param_5 + 8);
  local_98 = *(char **)param_3;
  pcStack_90 = *(char **)(param_3 + 8);
  local_48[0] = 0;
  ppcVar6 = &local_98;
  local_78[0] = (OnBlockExitImpl<<lambda_3156162d9f3dab841a21b521aa54357f>_>)0x1;
  local_70 = this;
  iVar2 = (**(code **)(this + 0x30))(param_2,ppcVar6,param_4,*(undefined8 *)(param_5 + 0x10));
  iVar3 = -0x3fffffcc;
  if (iVar2 == -0x3fffffcc) {
    if ((param_1 & 1) != 0) {
      if (param_6 != (ulong *)0x0) {
        *param_6 = 2;
      }
      goto LAB_14000ae7d;
    }
    local_80 = 0;
    local_98 = "onecore\\base\\servicing\\globmerger\\kernel\\kernelmerger.cpp";
    ppcVar5 = &local_98;
    local_88 = 0x18e;
    pcStack_90 = "CmRegistryProvider::SysQueryValueKey";
LAB_14000ae5a:
    RtlReportErrorOrigination(ppcVar5,ppcVar6,iVar3);
LAB_14000ae5f:
    Windows::Detail::OnBlockExitImpl<<lambda_3156162d9f3dab841a21b521aa54357f>_>::
    ~OnBlockExitImpl<<lambda_3156162d9f3dab841a21b521aa54357f>_>(local_78);
    return iVar3;
  }
  if (iVar2 == -0x3fffffdd) {
    uVar4 = RtlAllocateLBlob((ulonglong)local_48[0],(undefined8 *)param_5);
    iVar3 = (int)uVar4;
    if (iVar3 < 0) goto LAB_14000ae5f;
    local_b8 = *(undefined4 *)(param_5 + 8);
    local_b0 = local_48;
    local_98 = *(char **)param_3;
    pcStack_90 = *(char **)(param_3 + 8);
    ppcVar6 = &local_98;
    iVar3 = (**(code **)(this + 0x30))(param_2,ppcVar6,param_4,*(undefined8 *)(param_5 + 0x10));
    if (iVar3 < 0) {
      local_58 = 0x19c;
      local_68 = "onecore\\base\\servicing\\globmerger\\kernel\\kernelmerger.cpp";
      ppcVar5 = &local_68;
      local_60 = "CmRegistryProvider::SysQueryValueKey";
      local_50 = 
      "m_Fns.QueryValueKey( KeyHandle, ValueName, KeyValueInformationClass, KeyValueInformation->Buffer, static_cast<ULONG>(KeyValueInformation->MaximumLength), &ResultLength)"
      ;
      goto LAB_14000ae5a;
    }
  }
  *(ulonglong *)param_5 = (ulonglong)local_48[0];
  if (param_6 != (ulong *)0x0) {
    *param_6 = 1;
  }
LAB_14000ae7d:
  Windows::Detail::OnBlockExitImpl<<lambda_3156162d9f3dab841a21b521aa54357f>_>::
  ~OnBlockExitImpl<<lambda_3156162d9f3dab841a21b521aa54357f>_>(local_78);
  return 0;
}



===== SysSetSecurityObject @ 14000aec0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CmRegistryProvider::SysSetSecurityObject(unsigned long,void *
   __ptr64,struct _UNICODE_STRING const * __ptr64,unsigned long,void * __ptr64,struct
   Windows::Rtl::KtmTransactionInfoPointer) __ptr64 */

long __thiscall
CmRegistryProvider::SysSetSecurityObject
          (CmRegistryProvider *this,undefined8 param_2_00,undefined8 param_2,undefined8 param_4_00,
          undefined1 param_4,undefined8 param_5)

{
  longlong lVar1;
  undefined8 uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined1 *puVar5;
  OnBlockExitImpl<<lambda_8ba2b512a3f33f72fb6eb20b576878a5>_> local_48 [8];
  CmRegistryProvider *local_40;
  char *local_38;
  char *local_30;
  undefined8 local_28;
  char *local_20;
  
  uVar2 = param_5;
  lVar1 = *(longlong *)(this + 0x60);
  if (*(char *)(lVar1 + 0x140) != '\0') {
                    /* WARNING: Subroutine does not return */
    RtlRaiseStatus(0xc00000e5);
  }
  uVar4 = KeQueryPerformanceCounter(lVar1 + 0x158);
  *(undefined1 *)(lVar1 + 0x140) = 1;
  puVar5 = &param_4;
  *(undefined8 *)(lVar1 + 0x150) = uVar4;
  local_48[0] = (OnBlockExitImpl<<lambda_8ba2b512a3f33f72fb6eb20b576878a5>_>)0x1;
  local_40 = this;
  iVar3 = (**(code **)(this + 0x50))(param_2,puVar5,uVar2);
  if (iVar3 < 0) {
    local_28 = 0x250;
    local_38 = "onecore\\base\\servicing\\globmerger\\kernel\\kernelmerger.cpp";
    local_30 = "CmRegistryProvider::SysSetSecurityObject";
    local_20 = "m_Fns.SetSecurity(Handle, &SecurityInformation, SecurityDescriptor)";
    RtlReportErrorOrigination(&local_38,puVar5,iVar3);
    Windows::Detail::OnBlockExitImpl<<lambda_8ba2b512a3f33f72fb6eb20b576878a5>_>::
    ~OnBlockExitImpl<<lambda_8ba2b512a3f33f72fb6eb20b576878a5>_>(local_48);
  }
  else {
    Windows::Detail::OnBlockExitImpl<<lambda_8ba2b512a3f33f72fb6eb20b576878a5>_>::
    ~OnBlockExitImpl<<lambda_8ba2b512a3f33f72fb6eb20b576878a5>_>(local_48);
    iVar3 = 0;
  }
  return iVar3;
}



===== SysSetValueKey @ 14000afb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CmRegistryProvider::SysSetValueKey(unsigned long,void *
   __ptr64,struct _UNICODE_STRING & __ptr64,unsigned long,unsigned long,void * __ptr64,unsigned
   long,unsigned long * __ptr64) __ptr64 */

long __thiscall
CmRegistryProvider::SysSetValueKey
          (CmRegistryProvider *this,ulong param_1,void *param_2,_UNICODE_STRING *param_3,
          ulong param_4,ulong param_5,void *param_6,ulong param_7,ulong *param_8)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 in_register_00000014;
  OnBlockExitImpl<<lambda_0900b3b0397de7d8025b4ec4a90b502a>_> local_58 [8];
  CmRegistryProvider *local_50;
  char *local_48;
  char *local_40;
  undefined8 local_38;
  char *local_30;
  
  if (param_8 != (ulong *)0x0) {
    *param_8 = 0;
  }
  lVar1 = *(longlong *)(this + 0x60);
  if (*(char *)(lVar1 + 0xa0) != '\0') {
                    /* WARNING: Subroutine does not return */
    RtlRaiseStatus(0xc00000e5);
  }
  uVar3 = KeQueryPerformanceCounter(lVar1 + 0xb8,CONCAT44(in_register_00000014,param_1));
  *(undefined8 *)(lVar1 + 0xb0) = uVar3;
  *(undefined1 *)(lVar1 + 0xa0) = 1;
  local_58[0] = (OnBlockExitImpl<<lambda_0900b3b0397de7d8025b4ec4a90b502a>_>)0x1;
  local_50 = this;
  iVar2 = (**(code **)(this + 0x38))(param_2,param_3,param_5,param_6,param_7);
  if (iVar2 < 0) {
    local_38 = 0x1b7;
    local_48 = "onecore\\base\\servicing\\globmerger\\kernel\\kernelmerger.cpp";
    local_40 = "CmRegistryProvider::SysSetValueKey";
    local_30 = "m_Fns.SetValue(KeyHandle, &ValueName, Type, Data, DataSize)";
    RtlReportErrorOrigination(&local_48,param_3,iVar2);
    Windows::Detail::OnBlockExitImpl<<lambda_0900b3b0397de7d8025b4ec4a90b502a>_>::
    ~OnBlockExitImpl<<lambda_0900b3b0397de7d8025b4ec4a90b502a>_>(local_58);
  }
  else {
    if (param_8 != (ulong *)0x0) {
      *param_8 = 1;
    }
    Windows::Detail::OnBlockExitImpl<<lambda_0900b3b0397de7d8025b4ec4a90b502a>_>::
    ~OnBlockExitImpl<<lambda_0900b3b0397de7d8025b4ec4a90b502a>_>(local_58);
    iVar2 = 0;
  }
  return iVar2;
}



===== TraceErrorOrigination @ 14000b0e0 =====

/* void __cdecl TraceErrorOrigination(struct Windows::ErrorHandling::_RTL_CALL_SITE const *
   __ptr64,struct _GUID const & __ptr64,unsigned long) */

void __cdecl TraceErrorOrigination(_RTL_CALL_SITE *param_1,_GUID *param_2,ulong param_3)

{
  if (param_1 == (_RTL_CALL_SITE *)0x0) {
    DbgPrintEx(0,0,"GlobMerger Error: \'0x%08X\' originated.\n",param_3);
  }
  else {
    DbgPrintEx(0,0,
               "%hs(%d) GlobMerger Error: \'0x%08X\' originated in function \'%hs\', expression: \'%hs\'\n"
               ,*(undefined8 *)param_1,*(undefined4 *)(param_1 + 0x10),param_3,
               *(undefined8 *)(param_1 + 8),*(undefined8 *)(param_1 + 0x18));
  }
  return;
}



===== GlobMergeHive @ 14000b150 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint GlobMergeHive(char *param_1,longlong *param_2,ulonglong *param_3)

{
  longlong lVar1;
  char *pcVar2;
  char *pcVar3;
  _UNICODE_STRING *p_Var4;
  ulonglong uVar5;
  bool bVar6;
  uint uVar7;
  long lVar8;
  uint uVar9;
  ulonglong uVar10;
  longlong lVar11;
  uint *puVar12;
  CmRegistryProvider *pCVar13;
  __uint64 _Var14;
  char **ppcVar15;
  ushort uVar16;
  _LUNICODE_STRING *p_Var17;
  CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *pCVar18;
  longlong *plVar19;
  ulonglong uVar20;
  _UNICODE_STRING *p_Var21;
  undefined1 auStackY_728 [32];
  char *local_6f8;
  char *local_6f0;
  wchar_t *local_6e8;
  undefined8 local_6e0;
  char **local_6d8;
  longlong local_6d0;
  longlong lStack_6c8;
  undefined8 local_6c0;
  undefined8 local_6b8;
  undefined8 uStack_6b0;
  undefined8 local_6a8;
  longlong *local_6a0;
  longlong *local_698;
  undefined1 local_690;
  undefined4 *local_688;
  StopWatch *local_680;
  ushort local_678;
  ushort uStack_676;
  undefined4 uStack_674;
  ulonglong uStack_670;
  ulonglong local_668;
  ulonglong uStack_660;
  ulonglong local_658;
  CVector<gsl::byte,BUCL::Rtl::CCallDisposition> local_650 [4];
  CVector<gsl::byte,BUCL::Rtl::CCallDisposition> local_64c [4];
  Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64> local_648 [8];
  ulonglong *local_640;
  undefined8 *local_638;
  undefined8 *local_630;
  char *local_628;
  ulonglong *local_620;
  undefined8 local_618;
  undefined8 uStack_610;
  undefined8 local_608;
  char *local_600;
  char *local_5f8;
  undefined8 local_5f0;
  char *local_5e8;
  char *local_5e0;
  char *local_5d8;
  undefined8 local_5d0;
  char *local_5c8;
  char *local_5c0;
  char *local_5b8;
  undefined8 local_5b0;
  char *local_5a8;
  char *local_5a0;
  char *local_598;
  undefined8 local_590;
  char *local_588;
  undefined8 local_580;
  undefined8 local_578;
  wchar_t *local_570;
  undefined8 local_568;
  undefined8 local_560;
  wchar_t *local_558;
  undefined8 local_550;
  undefined8 local_548;
  wchar_t *local_540;
  ulonglong local_538;
  ulonglong uStack_530;
  ulonglong local_528;
  undefined2 local_520;
  undefined4 local_51c;
  _LUNICODE_STRING local_510 [24];
  longlong local_4f8;
  longlong local_4f0;
  undefined8 local_4e8;
  undefined8 uStack_4e0;
  longlong local_4d8;
  longlong local_4d0;
  undefined8 uStack_4c8;
  longlong local_4c0;
  ulonglong local_4b8;
  undefined8 uStack_4b0;
  longlong local_4a8;
  ulonglong local_4a0;
  undefined8 uStack_498;
  longlong local_490;
  undefined4 local_488;
  undefined4 local_484;
  undefined4 local_480;
  undefined4 local_47c;
  char *local_478;
  char *pcStack_470;
  longlong local_468;
  undefined8 local_460;
  StopWatch local_458 [8];
  longlong local_450;
  longlong local_448;
  undefined8 local_440;
  undefined8 local_438;
  ulonglong local_430;
  undefined8 uStack_428;
  longlong local_420;
  ulonglong local_418;
  undefined8 uStack_410;
  longlong local_408;
  StopWatch local_400 [8];
  longlong local_3f8;
  longlong local_3f0;
  undefined8 local_3e8;
  undefined8 local_3e0;
  longlong local_3d8;
  longlong lStack_3d0;
  undefined8 local_3c8;
  longlong local_3b8;
  longlong lStack_3b0;
  longlong local_3a8;
  longlong lStack_3a0;
  undefined8 local_398;
  StopWatch local_390 [8];
  longlong local_388;
  longlong local_380;
  undefined8 local_378;
  undefined8 local_370;
  ulonglong *local_368;
  ulonglong *local_360;
  StopWatch local_358 [8];
  longlong local_350;
  longlong local_348;
  undefined8 local_340;
  undefined8 local_338;
  ulonglong local_328;
  ulonglong uStack_320;
  StopWatch local_318 [8];
  undefined8 local_310;
  undefined8 local_308;
  undefined8 local_300;
  undefined8 local_2f8;
  StopWatch local_2f0 [8];
  undefined8 local_2e8;
  undefined8 local_2e0;
  undefined8 local_2d8;
  undefined8 local_2d0;
  undefined8 local_2c8;
  undefined8 local_2c0;
  undefined8 local_2b8;
  undefined8 local_2b0;
  undefined8 uStack_2a8;
  undefined8 local_2a0;
  undefined8 uStack_298;
  undefined8 local_290;
  undefined8 uStack_288;
  undefined8 local_280;
  undefined8 uStack_278;
  undefined8 local_270;
  undefined8 uStack_268;
  undefined8 local_260;
  RegistryTimers local_258 [40];
  StopWatch local_230 [40];
  StopWatch local_208 [40];
  StopWatch local_1e0 [40];
  StopWatch local_1b8 [40];
  StopWatch local_190 [40];
  StopWatch local_168 [40];
  StopWatch local_140 [40];
  StopWatch local_118 [48];
  undefined8 local_e8;
  undefined8 local_e0;
  wchar_t *local_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  longlong local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  wchar_t *local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  longlong local_78;
  undefined8 local_70;
  undefined8 local_68;
  wchar_t *local_60;
  ulonglong local_58;
  ulonglong local_50;
  ulonglong local_48;
  ulonglong local_38;
  
                    /* 0xb150  10  GlobMergeHive */
  local_38 = __security_cookie ^ (ulonglong)auStackY_728;
  local_300 = 0;
  local_2f8 = 0;
  local_318[0] = (StopWatch)0x0;
  local_310 = 0;
  local_308 = 0;
  local_340 = 0;
  local_338 = 0;
  local_358[0] = (StopWatch)0x0;
  local_350 = 0;
  local_348 = 0;
  local_440 = 0;
  local_438 = 0;
  local_458[0] = (StopWatch)0x0;
  local_450 = 0;
  local_448 = 0;
  local_3e8 = 0;
  local_3e0 = 0;
  local_400[0] = (StopWatch)0x0;
  local_3f8 = 0;
  local_3f0 = 0;
  local_378 = 0;
  local_370 = 0;
  local_390[0] = (StopWatch)0x0;
  local_388 = 0;
  local_380 = 0;
  local_2d8 = 0;
  local_2d0 = 0;
  local_2f0[0] = (StopWatch)0x0;
  local_2e8 = 0;
  local_2e0 = 0;
  local_628 = param_1;
  RegistryTimers::RegistryTimers(local_258);
  if (local_318[0] != (StopWatch)0x0) {
                    /* WARNING: Subroutine does not return */
    RtlRaiseStatus(0xc00000e5);
  }
  local_308 = KeQueryPerformanceCounter(&local_300);
  local_318[0] = (StopWatch)0x1;
  local_488 = 0x12345678;
  local_4d8 = 0;
  local_638 = &local_4e8;
  local_484 = 0x12341234;
  local_568 = 0x14;
  local_560 = 0x14;
  local_558 = L"\\??\\Volume";
  local_480 = 0x34123412;
  local_47c = 0xaa907856;
  local_4e8 = 0;
  uStack_4e0 = 0;
  uVar7 = Windows::StringUtil::Rtl::
          AppendString<_LUNICODE_STRING,Windows::AutoOperatorAmpersandHelper<_LUNICODE_STRING,Windows::Auto<_LUNICODE_STRING>_>,0>
                    (&local_568,&local_638);
  if (-1 < (int)uVar7) {
    local_630 = &local_4e8;
    uVar7 = Windows::StringUtil::Rtl::
            AppendGuid<Windows::AutoOperatorAmpersandHelper<_LUNICODE_STRING,Windows::Auto<_LUNICODE_STRING>_>_>
                      (0,&local_488,&local_630);
    if (-1 < (int)uVar7) {
      local_51c = 0;
      local_6c0 = 0;
      local_6d0 = 0;
      lStack_6c8 = 0;
      uVar16 = (short)*param_3 - 0x16;
      local_6a8 = 0;
      local_328 = *param_3;
      uStack_320 = param_3[1];
      local_520 = 0x16;
      local_6b8 = 0;
      uStack_6b0 = 0;
      if ((ushort)*param_3 < 0x16) {
        local_6e8 = (wchar_t *)0x103d;
        local_6f8 = "OneCore\\Internal\\Base\\inc\\rtlstringutil.h";
        ppcVar15 = &local_6f8;
        local_6e0 = 0;
        local_6f0 = "Windows::StringUtil::Rtl::SubStringByByteCount";
LAB_14000b49c:
        RtlReportErrorOrigination(ppcVar15,(ulonglong)uVar16,-0x7ffffffb);
        uVar7 = 0x80000005;
      }
      else {
        if ((int)((ushort)*param_3 - 0x16) < (int)(uint)uVar16) {
          local_468 = 0x1043;
          local_478 = "OneCore\\Internal\\Base\\inc\\rtlstringutil.h";
          ppcVar15 = &local_478;
          local_460 = 0;
          pcStack_470 = "Windows::StringUtil::Rtl::SubStringByByteCount";
          goto LAB_14000b49c;
        }
        uStack_674 = 0;
        uVar20 = uStack_320 + 0x16;
        local_668 = (ulonglong)uVar16;
        uStack_660 = (ulonglong)uVar16;
        p_Var17 = (_LUNICODE_STRING *)&local_538;
        local_328 = (ulonglong)CONCAT22(uVar16,uVar16);
        local_608 = 0;
        local_618 = 0;
        uStack_610 = 0;
        local_678 = uVar16;
        uStack_676 = uVar16;
        uStack_670 = uVar20;
        local_658 = uVar20;
        local_538 = local_668;
        uStack_530 = uStack_660;
        local_528 = uVar20;
        uStack_320 = uVar20;
        bVar6 = Windows::StringUtil::Impl::
                TrySplitStringOnAsciiPredicateMatch<_LUNICODE_STRING,Windows::StringUtil::Impl::NtSlashPredicate>
                          ((TrySplitStringOnAsciiPredicateMatchFlags)uVar20,p_Var17,
                           (NtSlashPredicate *)0x16,local_510,(_LUNICODE_STRING *)&local_618);
        if (!bVar6) {
          local_6e8 = (wchar_t *)0xd18;
          local_6f8 = "OneCore\\Internal\\Base\\inc\\rtlstringutil.h";
          local_6e0 = 0;
          local_6f0 = "Windows::StringUtil::Rtl::SplitNtPath";
          RtlReportErrorOrigination(&local_6f8,p_Var17,-0x3fffffc7);
          BUCL::
          CVector<BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>,BUCL::Rtl::CCallDisposition>
          ::Close((CVector<BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>,BUCL::Rtl::CCallDisposition>
                   *)&local_6b8);
          BUCL::
          CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
          ::
          ~CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
                    ((CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
                      *)&local_6d0);
          if (local_4d8 != 0) {
            RtlFreeLUnicodeString((longlong)&local_4e8);
            local_6e8 = (wchar_t *)0x0;
            local_4e8 = 0;
            uStack_4e0 = 0;
            local_4d8 = 0;
          }
          uVar7 = 0xc0000039;
          goto LAB_14000c645;
        }
        pCVar18 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)&local_e8;
        local_4c0 = 0;
        local_260 = local_608;
        local_e8 = 0x22;
        local_e0 = 0x22;
        local_d8 = L"\\Registry\\Machine";
        local_270 = local_618;
        uStack_268 = uStack_610;
        local_4d0 = 0;
        uStack_4c8 = 0;
        local_d0 = local_618;
        uStack_c8 = uStack_610;
        local_c0 = local_608;
        uVar10 = RtlCombineNtPathSegments(2,(longlong)pCVar18,&local_4d0);
        uVar5 = local_668;
        p_Var4 = DAT_140017280;
        uVar7 = (uint)uVar10;
        if (-1 < (int)uVar7) {
          local_490 = 0;
          local_4a8 = 0;
          local_4a0 = 0;
          uStack_498 = 0;
          local_4b8 = 0;
          uStack_4b0 = 0;
          lVar11 = local_490;
          lVar1 = local_4a8;
          p_Var21 = _g_SourceCims;
          while( true ) {
            local_4a8 = lVar1;
            local_490 = lVar11;
            if (p_Var21 == p_Var4) break;
            local_60 = L"Windows";
            local_70 = 0xe;
            local_68 = 0xe;
            local_58 = uVar5;
            local_88 = local_4e8;
            uStack_80 = uStack_4e0;
            local_78 = local_4d8;
            local_50 = uStack_660;
            local_48 = uVar20;
            uVar10 = RtlCombineNtPathSegments(3,(longlong)&local_88,(longlong *)&local_4a0);
            uVar7 = (uint)uVar10;
            if ((int)uVar7 < 0) {
LAB_14000bdd4:
              if (local_4a8 != 0) {
                RtlFreeLUnicodeString((longlong)&local_4b8);
              }
              if (local_490 != 0) {
                RtlFreeLUnicodeString((longlong)&local_4a0);
              }
              if (local_4c0 != 0) {
                RtlFreeLUnicodeString((longlong)&local_4d0);
                local_6e8 = (wchar_t *)0x0;
                local_4d0 = 0;
                uStack_4c8 = 0;
                local_4c0 = 0;
              }
              BUCL::
              CVector<BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>,BUCL::Rtl::CCallDisposition>
              ::Close((CVector<BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>,BUCL::Rtl::CCallDisposition>
                       *)&local_6b8);
              BUCL::
              CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
              ::
              ~CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
                        ((CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
                          *)&local_6d0);
              goto LAB_14000b3ab;
            }
            local_a0 = 0x40;
            local_98 = 0x40;
            local_90 = L"Windows\\System32\\config\\OVERRIDE";
            local_b8 = local_4e8;
            uStack_b0 = uStack_4e0;
            local_a8 = local_4d8;
            uVar10 = RtlCombineNtPathSegments(2,(longlong)&local_b8,(longlong *)&local_4b8);
            uVar7 = (uint)uVar10;
            if ((int)uVar7 < 0) goto LAB_14000bdd4;
            local_280 = 0;
            uStack_278 = 0;
            uVar7 = RtlInitUnicodeStringFromLUnicodeString(&local_4a0,(undefined4 *)&local_280);
            if ((int)uVar7 < 0) goto LAB_14000bdd4;
            local_290 = 0;
            uStack_288 = 0;
            uVar7 = RtlInitUnicodeStringFromLUnicodeString(&local_4b8,(undefined4 *)&local_290);
            if ((int)uVar7 < 0) goto LAB_14000bdd4;
            if (local_358[0] != (StopWatch)0x0) {
LAB_14000c433:
                    /* WARNING: Subroutine does not return */
              RtlRaiseStatus(0xc00000e5);
            }
            local_348 = KeQueryPerformanceCounter(&local_340);
            local_358[0] = (StopWatch)0x1;
            uVar7 = MountSourceCim((_GUID *)&local_488,p_Var21);
            if ((int)uVar7 < 0) goto LAB_14000bdd4;
            if (local_358[0] != (StopWatch)0x0) {
              local_2c0 = 0;
              lVar11 = KeQueryPerformanceCounter(&local_2c0);
              LOCK();
              local_350 = local_350 + (lVar11 - local_348);
              UNLOCK();
              local_358[0] = (StopWatch)0x0;
              uVar20 = uStack_320;
            }
            local_688 = &local_488;
            local_690 = 1;
            local_680 = local_458;
            if (local_400[0] != (StopWatch)0x0) goto LAB_14000c433;
            local_3f0 = KeQueryPerformanceCounter(&local_3e8);
            local_400[0] = (StopWatch)0x1;
            pCVar18 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)&local_3d8;
            local_3c8 = 0;
            local_3d8 = 0;
            lStack_3d0 = 0;
            uVar7 = ReadFile((_UNICODE_STRING *)&local_280,pCVar18);
            if ((int)uVar7 < 0) {
              if (local_3d8 != 0) {
                ExFreePoolWithTag(local_3d8,0);
              }
              if (local_458[0] != (StopWatch)0x0) goto LAB_14000c433;
              local_448 = KeQueryPerformanceCounter(&local_440);
              local_458[0] = (StopWatch)0x1;
              local_408 = 0;
              local_620 = &local_418;
              local_550 = 0x14;
              local_548 = 0x14;
              local_540 = L"\\??\\Volume";
              local_418 = 0;
              uStack_410 = 0;
              lVar8 = Windows::StringUtil::Rtl::
                      AppendString<_LUNICODE_STRING,Windows::AutoOperatorAmpersandHelper<_LUNICODE_STRING,Windows::Auto<_LUNICODE_STRING>_>,0>
                                (&local_550,&local_620);
              if (-1 < lVar8) {
                local_368 = &local_418;
                lVar8 = Windows::StringUtil::Rtl::
                        AppendGuid<Windows::AutoOperatorAmpersandHelper<_LUNICODE_STRING,Windows::Auto<_LUNICODE_STRING>_>_>
                                  (0,&local_488,&local_368);
                if (-1 < lVar8) {
                  local_2a0 = 0;
                  uStack_298 = 0;
                  uVar9 = RtlInitUnicodeStringFromLUnicodeString
                                    (&local_418,(undefined4 *)&local_2a0);
                  if (-1 < (int)uVar9) {
                    DismountCim((_UNICODE_STRING *)&local_2a0);
                  }
                }
              }
              if (local_408 != 0) {
                RtlFreeLUnicodeString((longlong)&local_418);
              }
              if (local_458[0] != (StopWatch)0x0) {
                local_368 = (ulonglong *)0x0;
                lVar11 = KeQueryPerformanceCounter(&local_368);
                LOCK();
                local_450 = local_450 + (lVar11 - local_448);
                UNLOCK();
                local_458[0] = (StopWatch)0x0;
              }
              goto LAB_14000bdd4;
            }
            if (local_400[0] != (StopWatch)0x0) {
              local_2c8 = 0;
              lVar11 = KeQueryPerformanceCounter(&local_2c8);
              LOCK();
              local_3f8 = local_3f8 + (lVar11 - local_3f0);
              UNLOCK();
              local_400[0] = (StopWatch)0x0;
              uVar20 = uStack_320;
            }
            lVar11 = local_3d8;
            if (local_3d8 != lStack_3d0) {
              if (local_390[0] != (StopWatch)0x0) goto LAB_14000c433;
              local_380 = KeQueryPerformanceCounter(&local_378);
              plVar19 = &local_4f0;
              local_390[0] = (StopWatch)0x1;
              local_4f0 = 0;
              uVar7 = (*(code *)*param_2)(lVar11);
              if (-1 < (int)uVar7) {
                if (local_390[0] != (StopWatch)0x0) {
                  local_2b8 = 0;
                  lVar11 = KeQueryPerformanceCounter(&local_2b8);
                  LOCK();
                  local_388 = local_388 + (lVar11 - local_380);
                  UNLOCK();
                  local_390[0] = (StopWatch)0x0;
                  lVar11 = local_3d8;
                  uVar20 = uStack_320;
                }
                if (local_400[0] != (StopWatch)0x0) goto LAB_14000c433;
                local_3f0 = KeQueryPerformanceCounter(&local_3e8);
                local_400[0] = (StopWatch)0x1;
                pCVar18 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)&local_3a8;
                local_398 = 0;
                local_3a8 = 0;
                lStack_3a0 = 0;
                uVar7 = ReadFile((_UNICODE_STRING *)&local_290,pCVar18);
                if ((int)uVar7 < 0) {
                  if (local_3a8 != 0) {
                    ExFreePoolWithTag(local_3a8,0);
                  }
                  if (lVar11 != 0) {
                    ExFreePoolWithTag(lVar11,0);
                  }
                  if (local_458[0] != (StopWatch)0x0) goto LAB_14000c433;
                  local_448 = KeQueryPerformanceCounter(&local_440);
                  local_458[0] = (StopWatch)0x1;
                  local_468 = 0;
                  local_6d8 = &local_478;
                  local_6f8 = (char *)0x14;
                  local_6f0 = (char *)0x14;
                  local_6e8 = L"\\??\\Volume";
                  local_478 = (char *)0x0;
                  pcStack_470 = (char *)0x0;
                  lVar8 = Windows::StringUtil::Rtl::
                          AppendString<_LUNICODE_STRING,Windows::AutoOperatorAmpersandHelper<_LUNICODE_STRING,Windows::Auto<_LUNICODE_STRING>_>,0>
                                    (&local_6f8,&local_6d8);
                  if (-1 < lVar8) {
                    local_6d8 = &local_478;
                    lVar8 = Windows::StringUtil::Rtl::
                            AppendGuid<Windows::AutoOperatorAmpersandHelper<_LUNICODE_STRING,Windows::Auto<_LUNICODE_STRING>_>_>
                                      (0,&local_488,&local_6d8);
                    if (-1 < lVar8) {
                      local_3b8 = 0;
                      lStack_3b0 = 0;
                      uVar9 = RtlInitUnicodeStringFromLUnicodeString
                                        ((ulonglong *)&local_478,(undefined4 *)&local_3b8);
                      if (-1 < (int)uVar9) {
                        DismountCim((_UNICODE_STRING *)&local_3b8);
                      }
                    }
                  }
                  if (local_468 != 0) {
                    RtlFreeLUnicodeString((longlong)&local_478);
                  }
                  Windows::Rtl::StopWatch::Stop(local_458);
                  goto LAB_14000c240;
                }
                Windows::Rtl::StopWatch::Stop(local_400);
                lVar11 = local_3a8;
                local_4f8 = 0;
                if (local_3a8 != lStack_3a0) {
                  Windows::Rtl::StopWatch::Start(local_390);
                  pCVar18 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)&local_4f8;
                  uVar7 = (*(code *)*param_2)(lVar11);
                  if ((int)uVar7 < 0) {
                    local_5f0 = 0x380;
                    local_600 = "onecore\\base\\servicing\\globmerger\\kernel\\kernelmerger.cpp";
                    local_5f8 = "GlobMergeHive";
                    local_5e8 = "Fns->LoadSourceHive(OverrideBuffer.Begin(), &OverrideHive)";
                    RtlReportErrorOrigination(&local_600,pCVar18,uVar7);
                    BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>::
                    ~CVector<gsl::byte,BUCL::Rtl::CCallDisposition>
                              ((CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)&local_3a8);
                    BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>::
                    ~CVector<gsl::byte,BUCL::Rtl::CCallDisposition>
                              ((CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)&local_3d8);
                    Windows::Rtl::StopWatch::Start(local_458);
                    local_468 = 0;
                    local_6d8 = &local_478;
                    local_6f8 = (char *)0x14;
                    local_6f0 = (char *)0x14;
                    local_6e8 = L"\\??\\Volume";
                    local_478 = (char *)0x0;
                    pcStack_470 = (char *)0x0;
                    lVar8 = Windows::StringUtil::Rtl::
                            AppendString<_LUNICODE_STRING,Windows::AutoOperatorAmpersandHelper<_LUNICODE_STRING,Windows::Auto<_LUNICODE_STRING>_>,0>
                                      (&local_6f8,&local_6d8);
                    if (-1 < lVar8) {
                      local_6d8 = &local_478;
                      lVar8 = Windows::StringUtil::Rtl::
                              AppendGuid<Windows::AutoOperatorAmpersandHelper<_LUNICODE_STRING,Windows::Auto<_LUNICODE_STRING>_>_>
                                        (0,&local_488,&local_6d8);
                      if (-1 < lVar8) {
                        local_3b8 = 0;
                        lStack_3b0 = 0;
                        uVar9 = RtlInitUnicodeStringFromLUnicodeString
                                          ((ulonglong *)&local_478,(undefined4 *)&local_3b8);
                        if (-1 < (int)uVar9) {
                          DismountCim((_UNICODE_STRING *)&local_3b8);
                        }
                      }
                    }
                    if (local_468 != 0) {
                      RtlFreeLUnicodeString((longlong)&local_478);
                    }
                    Windows::Rtl::StopWatch::Stop(local_458);
                    goto LAB_14000bdd4;
                  }
                  Windows::Rtl::StopWatch::Stop(local_390);
                }
                local_6a0 = (longlong *)0x0;
                pCVar13 = Windows::AutoNewPtr<CmRegistryProvider>::Allocate<>
                                    ((AutoNewPtr<CmRegistryProvider> *)&local_6a0);
                if (pCVar13 != (CmRegistryProvider *)0x0) {
                  local_698 = local_6a0;
                  local_6a0[0xd] = local_4f0;
                  local_6a0[0xe] = local_4f8;
                  lVar11 = param_2[1];
                  local_6a0[2] = *param_2;
                  local_6a0[3] = lVar11;
                  lVar11 = param_2[3];
                  local_6a0[4] = param_2[2];
                  local_6a0[5] = lVar11;
                  lVar11 = param_2[5];
                  local_6a0[6] = param_2[4];
                  local_6a0[7] = lVar11;
                  lVar11 = param_2[7];
                  local_6a0[8] = param_2[6];
                  local_6a0[9] = lVar11;
                  lVar11 = param_2[8];
                  lVar1 = param_2[9];
                  local_6a0[0xc] = (longlong)local_258;
                  local_6a0[10] = lVar11;
                  local_6a0[0xb] = lVar1;
                  puVar12 = (uint *)BUCL::
                                    CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
                                    ::
                                    EmplaceBack<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>_>
                                              ((CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
                                                *)&local_6d0,local_648);
                  uVar7 = *puVar12;
                  if (local_698 != (longlong *)0x0) {
                    (**(code **)*local_698)();
                  }
                  if ((int)uVar7 < 0) {
LAB_14000be52:
                    BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>::
                    ~CVector<gsl::byte,BUCL::Rtl::CCallDisposition>
                              ((CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)&local_3a8);
                    BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>::
                    ~CVector<gsl::byte,BUCL::Rtl::CCallDisposition>
                              ((CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)&local_3d8);
                  }
                  else {
                    puVar12 = (uint *)BUCL::
                                      CVector<BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>,BUCL::Rtl::CCallDisposition>
                                      ::
                                      EmplaceBack<BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>_>
                                                ((CVector<BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>,BUCL::Rtl::CCallDisposition>
                                                  *)&local_6b8,local_650);
                    uVar7 = *puVar12;
                    if ((int)uVar7 < 0) goto LAB_14000be52;
                    pCVar18 = local_64c;
                    puVar12 = (uint *)BUCL::
                                      CVector<BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>,BUCL::Rtl::CCallDisposition>
                                      ::
                                      EmplaceBack<BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>_>
                                                ((CVector<BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>,BUCL::Rtl::CCallDisposition>
                                                  *)&local_6b8,pCVar18);
                    uVar7 = *puVar12;
                    BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>::
                    ~CVector<gsl::byte,BUCL::Rtl::CCallDisposition>
                              ((CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)&local_3a8);
                    BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>::
                    ~CVector<gsl::byte,BUCL::Rtl::CCallDisposition>
                              ((CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)&local_3d8);
                    if (-1 < (int)uVar7) goto LAB_14000bba6;
                  }
                  <lambda_59dcddcc7819714d190c2c60fb1d8fec>::operator()(&local_688);
                  goto LAB_14000bdd4;
                }
                local_5d0 = 0x385;
                local_5e0 = "onecore\\base\\servicing\\globmerger\\kernel\\kernelmerger.cpp";
                local_5d8 = "GlobMergeHive";
                local_5c8 = "SourceReg.Allocate()";
                RtlReportErrorOrigination(&local_5e0,pCVar18,-0x3fffffe9);
                if (local_6a0 != (longlong *)0x0) {
                  (**(code **)(*local_6a0 + 0x10))(local_6a0,1);
                }
                BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>::
                ~CVector<gsl::byte,BUCL::Rtl::CCallDisposition>
                          ((CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)&local_3a8);
                BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>::
                ~CVector<gsl::byte,BUCL::Rtl::CCallDisposition>
                          ((CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)&local_3d8);
                <lambda_59dcddcc7819714d190c2c60fb1d8fec>::operator()(&local_688);
                if (local_4a8 != 0) {
                  RtlFreeLUnicodeString((longlong)&local_4b8);
                }
                if (local_490 != 0) {
                  RtlFreeLUnicodeString((longlong)&local_4a0);
                }
                if (local_4c0 != 0) {
                  RtlFreeLUnicodeString((longlong)&local_4d0);
                  local_6e8 = (wchar_t *)0x0;
                  local_4d0 = 0;
                  uStack_4c8 = 0;
                  local_4c0 = 0;
                }
                BUCL::
                CVector<BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>,BUCL::Rtl::CCallDisposition>
                ::Close((CVector<BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>,BUCL::Rtl::CCallDisposition>
                         *)&local_6b8);
                BUCL::
                CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
                ::
                ~CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
                          ((CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
                            *)&local_6d0);
                goto LAB_14000bf65;
              }
              local_5b0 = 0x374;
              local_5c0 = "onecore\\base\\servicing\\globmerger\\kernel\\kernelmerger.cpp";
              local_5b8 = "GlobMergeHive";
              local_5a8 = "Fns->LoadSourceHive(HiveBuffer.Begin(), &Hive)";
              RtlReportErrorOrigination(&local_5c0,plVar19,uVar7);
              if (lVar11 != 0) {
                ExFreePoolWithTag(lVar11,0);
              }
              if (local_458[0] != (StopWatch)0x0) {
                    /* WARNING: Subroutine does not return */
                RtlRaiseStatus(0xc00000e5);
              }
              local_448 = KeQueryPerformanceCounter(&local_440);
              local_458[0] = (StopWatch)0x1;
              local_420 = 0;
              local_640 = &local_430;
              local_580 = 0x14;
              local_578 = 0x14;
              local_570 = L"\\??\\Volume";
              local_430 = 0;
              uStack_428 = 0;
              lVar8 = Windows::StringUtil::Rtl::
                      AppendString<_LUNICODE_STRING,Windows::AutoOperatorAmpersandHelper<_LUNICODE_STRING,Windows::Auto<_LUNICODE_STRING>_>,0>
                                (&local_580,&local_640);
              if (-1 < lVar8) {
                local_360 = &local_430;
                lVar8 = Windows::StringUtil::Rtl::
                        AppendGuid<Windows::AutoOperatorAmpersandHelper<_LUNICODE_STRING,Windows::Auto<_LUNICODE_STRING>_>_>
                                  (0,&local_488,&local_360);
                if (-1 < lVar8) {
                  local_2b0 = 0;
                  uStack_2a8 = 0;
                  uVar9 = RtlInitUnicodeStringFromLUnicodeString
                                    (&local_430,(undefined4 *)&local_2b0);
                  if (-1 < (int)uVar9) {
                    DismountCim((_UNICODE_STRING *)&local_2b0);
                  }
                }
              }
              if (local_420 != 0) {
                RtlFreeLUnicodeString((longlong)&local_430);
              }
              if (local_458[0] != (StopWatch)0x0) {
                local_360 = (ulonglong *)0x0;
                lVar11 = KeQueryPerformanceCounter(&local_360);
                LOCK();
                local_450 = local_450 + (lVar11 - local_448);
                UNLOCK();
                local_458[0] = (StopWatch)0x0;
              }
LAB_14000c240:
              if (local_4a8 != 0) {
                RtlFreeLUnicodeString((longlong)&local_4b8);
              }
              if (local_490 != 0) {
                RtlFreeLUnicodeString((longlong)&local_4a0);
              }
              if (local_4c0 != 0) {
                RtlFreeLUnicodeString((longlong)&local_4d0);
                local_6e8 = (wchar_t *)0x0;
                local_4d0 = 0;
                uStack_4c8 = 0;
                local_4c0 = 0;
              }
              BUCL::
              CVector<BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>,BUCL::Rtl::CCallDisposition>
              ::Close((CVector<BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>,BUCL::Rtl::CCallDisposition>
                       *)&local_6b8);
              BUCL::
              CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
              ::
              ~CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
                        ((CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
                          *)&local_6d0);
              if (local_4d8 != 0) {
                RtlFreeLUnicodeString((longlong)&local_4e8);
                local_6e8 = (wchar_t *)0x0;
                local_4e8 = 0;
                uStack_4e0 = 0;
                local_4d8 = 0;
              }
              goto LAB_14000c645;
            }
            if (local_3d8 != 0) {
              pCVar18 = (CVector<gsl::byte,BUCL::Rtl::CCallDisposition> *)0x0;
              ExFreePoolWithTag(local_3d8);
            }
LAB_14000bba6:
            <lambda_59dcddcc7819714d190c2c60fb1d8fec>::operator()(&local_688);
            p_Var21 = p_Var21 + 0x10;
            lVar11 = local_490;
            lVar1 = local_4a8;
          }
          local_6d8 = (char **)0x0;
          pCVar13 = Windows::AutoNewPtr<CmRegistryProvider>::Allocate<>
                              ((AutoNewPtr<CmRegistryProvider> *)&local_6d8);
          ppcVar15 = local_6d8;
          if (pCVar13 == (CmRegistryProvider *)0x0) {
            local_590 = 0x393;
            local_5a0 = "onecore\\base\\servicing\\globmerger\\kernel\\kernelmerger.cpp";
            local_598 = "GlobMergeHive";
            local_588 = "Reg.Allocate()";
            RtlReportErrorOrigination(&local_5a0,pCVar18,-0x3fffffe9);
            if (local_6d8 != (char **)0x0) {
              (**(code **)(*local_6d8 + 0x10))(local_6d8,1);
            }
            if (lVar1 != 0) {
              RtlFreeLUnicodeString((longlong)&local_4b8);
            }
            if (lVar11 != 0) {
              RtlFreeLUnicodeString((longlong)&local_4a0);
            }
            if (local_4c0 != 0) {
              RtlFreeLUnicodeString((longlong)&local_4d0);
              local_6e8 = (wchar_t *)0x0;
              local_4d0 = 0;
              uStack_4c8 = 0;
              local_4c0 = 0;
            }
            BUCL::
            CVector<BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>,BUCL::Rtl::CCallDisposition>
            ::Close((CVector<BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>,BUCL::Rtl::CCallDisposition>
                     *)&local_6b8);
            BUCL::
            CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
            ::
            ~CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
                      ((CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
                        *)&local_6d0);
LAB_14000bf65:
            if (local_4d8 != 0) {
              RtlFreeLUnicodeString((longlong)&local_4e8);
              local_6e8 = (wchar_t *)0x0;
              local_4e8 = 0;
              uStack_4e0 = 0;
              local_4d8 = 0;
            }
            uVar7 = 0xc0000017;
          }
          else {
            local_6d8[0xd] = local_628;
            local_6d8[0xe] = (char *)0x0;
            pcVar2 = (char *)param_2[1];
            local_6d8[2] = (char *)*param_2;
            local_6d8[3] = pcVar2;
            pcVar2 = (char *)param_2[3];
            local_6d8[4] = (char *)param_2[2];
            local_6d8[5] = pcVar2;
            pcVar2 = (char *)param_2[5];
            local_6d8[6] = (char *)param_2[4];
            local_6d8[7] = pcVar2;
            pcVar2 = (char *)param_2[7];
            local_6d8[8] = (char *)param_2[6];
            local_6d8[9] = pcVar2;
            pcVar2 = (char *)param_2[8];
            pcVar3 = (char *)param_2[9];
            local_6d8[0xc] = (char *)local_258;
            local_6d8[10] = pcVar2;
            local_6d8[0xb] = pcVar3;
            _Var14 = Windows::Rtl::StopWatch::ElapsedMilliseconds(local_318);
            DbgPrintEx(0,0,"GlobMerger prep time: %llu\n",_Var14);
            _Var14 = Windows::Rtl::StopWatch::ElapsedMilliseconds(local_358);
            DbgPrintEx(0,0,"    - mount time: %llu\n",_Var14);
            _Var14 = Windows::Rtl::StopWatch::ElapsedMilliseconds(local_458);
            DbgPrintEx(0,0,"    - dismount time: %llu\n",_Var14);
            _Var14 = Windows::Rtl::StopWatch::ElapsedMilliseconds(local_400);
            DbgPrintEx(0,0,"    - read time: %llu\n",_Var14);
            _Var14 = Windows::Rtl::StopWatch::ElapsedMilliseconds(local_390);
            DbgPrintEx(0,0,"    - load time: %llu\n",_Var14);
            Windows::Rtl::StopWatch::Start(local_2f0);
            local_3b8 = local_6d0;
            lStack_3b0 = lStack_6c8 - local_6d0 >> 3;
            uVar7 = MergeGlobbedRegistry(&local_3b8,ppcVar15,&local_4d0);
            if (-1 < (int)uVar7) {
              Windows::Rtl::StopWatch::Stop(local_2f0);
              _Var14 = Windows::Rtl::StopWatch::ElapsedMilliseconds(local_2f0);
              DbgPrintEx(0,0,"GlobMerger merge time: %llu\n",_Var14);
              _Var14 = Windows::Rtl::StopWatch::ElapsedMilliseconds((StopWatch *)local_258);
              DbgPrintEx(0,0,"    - create time: %llu\n",_Var14);
              _Var14 = Windows::Rtl::StopWatch::ElapsedMilliseconds(local_230);
              DbgPrintEx(0,0,"    - open time: %llu\n",_Var14);
              _Var14 = Windows::Rtl::StopWatch::ElapsedMilliseconds(local_208);
              DbgPrintEx(0,0,"    - query key time: %llu\n",_Var14);
              _Var14 = Windows::Rtl::StopWatch::ElapsedMilliseconds(local_1e0);
              DbgPrintEx(0,0,"    - query value time: %llu\n",_Var14);
              _Var14 = Windows::Rtl::StopWatch::ElapsedMilliseconds(local_1b8);
              DbgPrintEx(0,0,"    - set value time: %llu\n",_Var14);
              _Var14 = Windows::Rtl::StopWatch::ElapsedMilliseconds(local_190);
              DbgPrintEx(0,0,"    - enum key time: %llu\n",_Var14);
              _Var14 = Windows::Rtl::StopWatch::ElapsedMilliseconds(local_168);
              DbgPrintEx(0,0,"    - enum value time: %llu\n",_Var14);
              _Var14 = Windows::Rtl::StopWatch::ElapsedMilliseconds(local_140);
              DbgPrintEx(0,0,"    - query security time: %llu\n",_Var14);
              _Var14 = Windows::Rtl::StopWatch::ElapsedMilliseconds(local_118);
              DbgPrintEx(0,0,"    - set security time: %llu\n",_Var14);
              (**(code **)(*ppcVar15 + 0x10))(ppcVar15,1);
              if (lVar1 != 0) {
                RtlFreeLUnicodeString((longlong)&local_4b8);
              }
              if (lVar11 != 0) {
                RtlFreeLUnicodeString((longlong)&local_4a0);
              }
              if (local_4c0 != 0) {
                RtlFreeLUnicodeString((longlong)&local_4d0);
                local_6e8 = (wchar_t *)0x0;
                local_4d0 = 0;
                uStack_4c8 = 0;
                local_4c0 = 0;
              }
              BUCL::
              CVector<BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>,BUCL::Rtl::CCallDisposition>
              ::Close((CVector<BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>,BUCL::Rtl::CCallDisposition>
                       *)&local_6b8);
              BUCL::
              CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
              ::
              ~CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
                        ((CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
                          *)&local_6d0);
              if (local_4d8 != 0) {
                RtlFreeLUnicodeString((longlong)&local_4e8);
                local_6e8 = (wchar_t *)0x0;
                local_4e8 = 0;
                uStack_4e0 = 0;
                local_4d8 = 0;
              }
              RegistryTimers::~RegistryTimers(local_258);
              Windows::Rtl::StopWatch::~StopWatch(local_2f0);
              Windows::Rtl::StopWatch::~StopWatch(local_390);
              Windows::Rtl::StopWatch::~StopWatch(local_400);
              Windows::Rtl::StopWatch::~StopWatch(local_458);
              Windows::Rtl::StopWatch::~StopWatch(local_358);
              Windows::Rtl::StopWatch::~StopWatch(local_318);
              return 0;
            }
            (**(code **)(*ppcVar15 + 0x10))(ppcVar15,1);
            if (lVar1 != 0) {
              RtlFreeLUnicodeString((longlong)&local_4b8);
            }
            if (lVar11 != 0) {
              RtlFreeLUnicodeString((longlong)&local_4a0);
            }
            if (local_4c0 != 0) {
              RtlFreeLUnicodeString((longlong)&local_4d0);
              local_6e8 = (wchar_t *)0x0;
              local_4d0 = 0;
              uStack_4c8 = 0;
              local_4c0 = 0;
            }
            BUCL::
            CVector<BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>,BUCL::Rtl::CCallDisposition>
            ::Close((CVector<BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>,BUCL::Rtl::CCallDisposition>
                     *)&local_6b8);
            BUCL::
            CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
            ::
            ~CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
                      ((CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
                        *)&local_6d0);
            if (local_4d8 != 0) {
              RtlFreeLUnicodeString((longlong)&local_4e8);
              local_6e8 = (wchar_t *)0x0;
              local_4e8 = 0;
              uStack_4e0 = 0;
              local_4d8 = 0;
            }
          }
          goto LAB_14000c645;
        }
        if (local_4c0 != 0) {
          RtlFreeLUnicodeString((longlong)&local_4d0);
          local_6e8 = (wchar_t *)0x0;
          local_4d0 = 0;
          uStack_4c8 = 0;
          local_4c0 = 0;
        }
      }
      BUCL::
      CVector<BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>,BUCL::Rtl::CCallDisposition>::
      Close((CVector<BUCL::CVector<gsl::byte,BUCL::Rtl::CCallDisposition>,BUCL::Rtl::CCallDisposition>
             *)&local_6b8);
      BUCL::
      CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
      ::
      ~CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
                ((CVector<Windows::Auto<Windows::Rtl::SystemImplementation::IRtlRegistryProvider*___ptr64>,BUCL::Rtl::CCallDisposition>
                  *)&local_6d0);
    }
  }
LAB_14000b3ab:
  if (local_4d8 != 0) {
    RtlFreeLUnicodeString((longlong)&local_4e8);
    local_6e8 = (wchar_t *)0x0;
    local_4e8 = 0;
    uStack_4e0 = 0;
    local_4d8 = 0;
  }
LAB_14000c645:
  RegistryTimers::~RegistryTimers(local_258);
  Windows::Rtl::StopWatch::~StopWatch(local_2f0);
  Windows::Rtl::StopWatch::~StopWatch(local_390);
  Windows::Rtl::StopWatch::~StopWatch(local_400);
  Windows::Rtl::StopWatch::~StopWatch(local_458);
  Windows::Rtl::StopWatch::~StopWatch(local_358);
  Windows::Rtl::StopWatch::~StopWatch(local_318);
  return uVar7;
}



===== DllInitialize @ 14000c970 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DllInitialize(undefined8 param_1,int param_2,int param_3)

{
  ulonglong uVar1;
  int iVar2;
  undefined8 *puVar3;
  
                    /* 0xc970  8  DllInitialize */
  _DAT_140017260 = &exitList;
  _exitList = &exitList;
  wil_InitializeFeatureStaging();
  for (puVar3 = &__crtXca; iVar2 = (int)param_1, puVar3 < &__crtXcz; puVar3 = puVar3 + 1) {
    if ((code *)*puVar3 != (code *)0x0) {
      (*(code *)*puVar3)();
    }
  }
  uVar1 = Cp_DllInitialize();
  if ((int)uVar1 < 0) {
    doexit(iVar2,param_2,param_3);
    if (g_wil_details_featureChangeNotification != 0) {
      RtlUnregisterFeatureConfigurationChangeNotification();
      g_wil_details_featureChangeNotification = 0;
    }
    if (g_wil_details_featureUsageProvider != 0) {
      RtlUnregisterFeatureUsageProvider();
      g_wil_details_featureUsageProvider = 0;
    }
    g_wil_details_isFeatureStagingInitialized = 0;
  }
  return uVar1 & 0xffffffff;
}



===== DllUnload @ 14000ca30 =====

ulonglong DllUnload(int param_1,int param_2,int param_3)

{
  ulonglong uVar1;
  
                    /* 0xca30  9  DllUnload */
  uVar1 = Cp_DllUnload();
  if (-1 < (int)uVar1) {
    doexit(param_1,param_2,param_3);
    if (g_wil_details_featureChangeNotification != 0) {
      RtlUnregisterFeatureConfigurationChangeNotification();
      g_wil_details_featureChangeNotification = 0;
    }
    if (g_wil_details_featureUsageProvider != 0) {
      RtlUnregisterFeatureUsageProvider();
      g_wil_details_featureUsageProvider = 0;
    }
    g_wil_details_isFeatureStagingInitialized = 0;
  }
  return uVar1 & 0xffffffff;
}



===== wil_details_RecordCachedUsage @ 14000ca9c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_RecordCachedUsage(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  bool bVar6;
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
    bVar6 = uVar2 == uVar4;
    if (bVar6) {
      *param_2 = uVar2 & 0xffc0401e;
    }
    else {
      uVar2 = uVar4;
    }
    UNLOCK();
  } while (!bVar6);
  uVar3 = uVar2 >> 1 & 0xf;
  uVar4 = 0;
  if (uVar3 != 0) {
    uVar4 = param_2[1];
    do {
      LOCK();
      uVar1 = param_2[1];
      bVar6 = uVar4 == uVar1;
      if (bVar6) {
        param_2[1] = uVar4 | uVar3;
      }
      else {
        uVar4 = uVar1;
      }
      UNLOCK();
    } while (!bVar6);
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
  if (0 < (longlong)puVar5 - (longlong)&local_48 >> 3) {
    wil_details_RecordFeatureUsageCallback();
  }
  return;
}



===== wil_details_RecordFeatureUsageReporting @ 14000cbf0 =====

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



===== operator_new @ 14000cc74 =====

/* void * __ptr64 __cdecl operator new(unsigned __int64) */

void * __cdecl operator_new(__uint64 param_1)

{
  void *pvVar1;
  __uint64 _Var2;
  
  _Var2 = 1;
  if (param_1 != 0) {
    _Var2 = param_1;
  }
  pvVar1 = (void *)ExAllocatePool2(0x40,_Var2,0x4c467346);
  return pvVar1;
}



===== operator_new @ 14000cca8 =====

/* void * __ptr64 __cdecl operator new(unsigned __int64,struct std::nothrow_t const & __ptr64) */

void * __cdecl operator_new(__uint64 param_1,nothrow_t *param_2)

{
  void *pvVar1;
  __uint64 _Var2;
  
  _Var2 = 1;
  if (param_1 != 0) {
    _Var2 = param_1;
  }
  pvVar1 = (void *)ExAllocatePool2(0x40,_Var2,0x204c5455);
  return pvVar1;
}



===== FreeUnicodeString @ 14000ccdc =====

/* void __cdecl FsFltWil::Details::FreeUnicodeString(struct _UNICODE_STRING * __ptr64) */

void __cdecl FsFltWil::Details::FreeUnicodeString(_UNICODE_STRING *param_1)

{
  if ((*(longlong *)(param_1 + 8) != 0) && (*(longlong *)(param_1 + 8) != 0xdeadbeef)) {
    RtlFreeUnicodeString();
    *(undefined4 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0xdeadbeef;
  }
  return;
}



===== doexit @ 14000cd2c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl doexit(int,int,int) */

void __cdecl doexit(int param_1,int param_2,int param_3)

{
  _LIST_ENTRY *p_Var1;
  code *pcVar2;
  _LIST_ENTRY *p_Var3;
  
  while( true ) {
    p_Var3 = _exitList;
    if (_exitList == &exitList) {
      return;
    }
    if ((*(_LIST_ENTRY **)(_exitList + 8) != &exitList) ||
       (p_Var1 = *(_LIST_ENTRY **)_exitList, *(_LIST_ENTRY **)(p_Var1 + 8) != _exitList)) break;
    _exitList = p_Var1;
    *(_LIST_ENTRY **)(p_Var1 + 8) = &exitList;
    pcVar2 = *(code **)(p_Var3 + 0x10);
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)();
    }
    ExFreePoolWithTag(p_Var3,0);
  }
  pcVar2 = (code *)swi(0x29);
  (*pcVar2)(3);
  return;
}



===== atexit @ 14000cda0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl atexit(_func_5014 *param_1)

{
  code *pcVar1;
  longlong *plVar2;
  longlong *plVar3;
  _LIST_ENTRY *p_Var4;
  _func_5014 *p_Var5;
  
  plVar2 = (longlong *)ExAllocatePoolWithTag(0x600,0x18,0x4550634f);
  p_Var5 = (_func_5014 *)0x0;
  if (plVar2 != (longlong *)0x0) {
    plVar2[2] = (longlong)param_1;
    p_Var4 = &exitList;
    plVar3 = _exitList;
    if ((_LIST_ENTRY *)_exitList[1] != &exitList) {
      plVar3 = (longlong *)0x3;
      pcVar1 = (code *)swi(0x29);
      plVar2 = (longlong *)(*pcVar1)();
    }
    plVar2[1] = (longlong)p_Var4;
    *plVar2 = (longlong)plVar3;
    plVar3[1] = (longlong)plVar2;
    p_Var5 = param_1;
    _exitList = plVar2;
  }
  return (p_Var5 != (_func_5014 *)0x0) - 1;
}



===== _CppDriverUnload @ 14000ce20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _CppDriverUnload(int param_1,int param_2,int param_3)

{
  if (DAT_140017298 != (code *)0x0) {
    (*DAT_140017298)();
  }
  doexit(param_1,param_2,param_3);
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



===== DriverEntry @ 14000ce90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DriverEntry(longlong param_1)

{
  undefined8 *puVar1;
  
  _DAT_140017260 = &exitList;
  _exitList = &exitList;
  wil_InitializeFeatureStaging();
  for (puVar1 = &__crtXca; puVar1 < &__crtXcz; puVar1 = puVar1 + 1) {
    if ((code *)*puVar1 != (code *)0x0) {
      (*(code *)*puVar1)();
    }
  }
  if (*(longlong *)(param_1 + 0x68) != 0) {
    DAT_140017298 = *(longlong *)(param_1 + 0x68);
    *(code **)(param_1 + 0x68) = _CppDriverUnload;
  }
  return 0;
}



===== TryConvertSubspan<Cim::Format::RegionSet,gsl::byte> @ 14000cf18 =====

/* long __cdecl Cim::TryConvertSubspan<struct Cim::Format::RegionSet,enum gsl::byte>(class
   gsl::span<struct Cim::Format::RegionSet,-1> & __ptr64,class gsl::span<enum gsl::byte,-1>,unsigned
   __int64,unsigned __int64) */

long __cdecl
Cim::TryConvertSubspan<Cim::Format::RegionSet,gsl::byte>
          (ulonglong *param_1,ulonglong *param_2,undefined8 param_3,ulonglong param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  if (param_4 == 0) {
    *param_1 = 0;
    param_1[1] = 0;
  }
  else {
    if (((*param_2 < 0x49) || (uVar2 = *param_2 - 0x48, uVar2 < param_4)) ||
       (param_4 != (param_4 / 0x18) * 0x18)) {
      *param_1 = 0;
      param_1[1] = 0;
      return -0x3ffffff3;
    }
    if (param_4 == 0xffffffffffffffff) {
      if (uVar2 == 0xffffffffffffffff) goto LAB_14000cfcf;
    }
    else {
      uVar2 = param_4;
    }
    uVar1 = param_2[1];
    uVar2 = uVar2 / 0x18;
    if ((uVar2 == 0xffffffffffffffff) || ((uVar1 + 0x48 == 0 && (uVar2 != 0)))) {
LAB_14000cfcf:
                    /* WARNING: Subroutine does not return */
      gsl::details::terminate();
    }
    *param_1 = uVar2;
    param_1[1] = uVar1 + 0x48;
  }
  return 0;
}



===== ~BlockLocationMapper @ 14000cfdc =====

/* public: __cdecl Cim::BlockLocationMapper::~BlockLocationMapper(void) __ptr64 */

void __thiscall Cim::BlockLocationMapper::~BlockLocationMapper(BlockLocationMapper *this)

{
  _RefCountBase *this_00;
  longlong lVar1;
  BlockLocationMapper *pBVar2;
  
  *(undefined8 *)this = 0;
  this_00 = *(_RefCountBase **)(this + 8);
  *(undefined8 *)(this + 8) = 0;
  if (this_00 != (_RefCountBase *)0x0) {
    utl::_RefCountBase::_DecStrong(this_00);
  }
  lVar1 = *(longlong *)(this + 0x50);
  *(undefined8 *)(this + 0x50) = 0;
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0);
  }
  if (*(longlong *)(this + 0x50) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x50),0);
  }
  pBVar2 = *(BlockLocationMapper **)(this + 0x10);
  if ((pBVar2 != this + 0x20) && (pBVar2 != (BlockLocationMapper *)0x0)) {
    ExFreePoolWithTag(pBVar2,0);
  }
  if (*(_RefCountBase **)(this + 8) != (_RefCountBase *)0x0) {
    utl::_RefCountBase::_DecStrong(*(_RefCountBase **)(this + 8));
  }
  return;
}



===== TryConvertSubspan<Cim::Format::RegionSet,gsl::byte> @ 14000d06c =====

/* long __cdecl Cim::TryConvertSubspan<struct Cim::Format::RegionSet,enum gsl::byte>(class
   gsl::span<struct Cim::Format::RegionSet,-1> & __ptr64,class gsl::span<enum gsl::byte,-1>,unsigned
   __int64,unsigned __int64,class CimFs::StackEventTracer & __ptr64) */

long __cdecl
Cim::TryConvertSubspan<Cim::Format::RegionSet,gsl::byte>
          (undefined8 param_1,undefined8 *param_2,undefined8 param_3,ulonglong param_4,
          StackEventTracer *param_5)

{
  long lVar1;
  char *pcVar2;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  local_18 = *(undefined4 *)param_2;
  uStack_14 = *(undefined4 *)((longlong)param_2 + 4);
  uStack_10 = *(undefined4 *)(param_2 + 1);
  uStack_c = *(undefined4 *)((longlong)param_2 + 0xc);
  lVar1 = TryConvertSubspan<Cim::Format::RegionSet,gsl::byte>(local_18,&local_18);
  if (lVar1 < 0) {
    pcVar2 = "is";
    if (param_4 != (param_4 / 0x18) * 0x18) {
      pcVar2 = "IS NOT";
    }
    CimFs::ProcessTraceStatusOrigin
              (lVar1,param_5,0x34e000f0298,"Cim::TryConvertSubspan",
               "ORIGIN: Invalid parameters. Span address: %p, Span size: %zu, Offset: %zu, Subspan length: %zu, Subspan element size: %zu, Subspan length %s byte-alinged."
               ,param_2[1],*param_2,0x48,param_4,0x18,pcVar2);
  }
  return lVar1;
}



===== _RangeTransferAppc<utl::allocator<CimFs::MappedRegionKernel>_> @ 14000d140 =====

/* bool __cdecl utl::_RangeTransferAppc<class utl::allocator<struct CimFs::MappedRegionKernel>
   >(struct utl::integral_constant<bool,0>,class utl::allocator<struct CimFs::MappedRegionKernel> &
   __ptr64,struct CimFs::MappedRegionKernel * __ptr64,struct CimFs::MappedRegionKernel *
   __ptr64,unsigned __int64) */

bool __cdecl
utl::_RangeTransferAppc<utl::allocator<CimFs::MappedRegionKernel>_>
          (allocator<CimFs::MappedRegionKernel> *param_1,undefined8 param_2,
          MappedRegionKernel *param_3,longlong param_4,longlong param_5)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  longlong lVar5;
  
  if (param_5 != 0) {
    lVar5 = (longlong)param_3 - param_4;
    puVar4 = (undefined8 *)(param_4 + 8);
    do {
      *(undefined8 *)(lVar5 + -8 + (longlong)puVar4) = puVar4[-1];
      puVar4[-1] = 0;
      uVar3 = *puVar4;
      *puVar4 = 0;
      *(undefined8 *)((longlong)puVar4 + lVar5) = uVar3;
      uVar3 = puVar4[2];
      puVar1 = puVar4 + 0x12;
      puVar2 = (undefined8 *)(lVar5 + -0x88 + (longlong)puVar1);
      *puVar2 = puVar4[1];
      puVar2[1] = uVar3;
      uVar3 = puVar4[4];
      puVar2 = (undefined8 *)(lVar5 + -0x78 + (longlong)puVar1);
      *puVar2 = puVar4[3];
      puVar2[1] = uVar3;
      uVar3 = puVar4[6];
      puVar2 = (undefined8 *)(lVar5 + -0x68 + (longlong)puVar1);
      *puVar2 = puVar4[5];
      puVar2[1] = uVar3;
      uVar3 = puVar4[8];
      puVar2 = (undefined8 *)(lVar5 + -0x58 + (longlong)puVar1);
      *puVar2 = puVar4[7];
      puVar2[1] = uVar3;
      uVar3 = puVar4[10];
      puVar2 = (undefined8 *)(lVar5 + -0x48 + (longlong)puVar1);
      *puVar2 = puVar4[9];
      puVar2[1] = uVar3;
      uVar3 = puVar4[0xc];
      puVar2 = (undefined8 *)(lVar5 + -0x38 + (longlong)puVar1);
      *puVar2 = puVar4[0xb];
      puVar2[1] = uVar3;
      *(undefined8 *)(lVar5 + -0x28 + (longlong)puVar1) = puVar4[0xd];
      uVar3 = puVar4[0xf];
      puVar2 = (undefined8 *)(lVar5 + -0x20 + (longlong)puVar1);
      *puVar2 = puVar4[0xe];
      puVar2[1] = uVar3;
      param_1 = (allocator<CimFs::MappedRegionKernel> *)(ulonglong)*(ushort *)(puVar4 + 0x10);
      *(ushort *)(lVar5 + -0x10 + (longlong)puVar1) = *(ushort *)(puVar4 + 0x10);
      param_5 = param_5 + -1;
      puVar4 = puVar1;
    } while (param_5 != 0);
  }
  _RangeDestroyApc<utl::allocator<CimFs::MappedRegionKernel>_>(param_1,param_3,0);
  return true;
}



===== swprintf_s<50> @ 14000d204 =====

/* int __cdecl swprintf_s<50>(wchar_t (& __ptr64)[50],wchar_t const * __ptr64,...) */

int __cdecl swprintf_s<50>(wchar_t *param_1,wchar_t *param_2,...)

{
  int iVar1;
  undefined8 in_R8;
  undefined8 in_R9;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = in_R8;
  local_res20 = in_R9;
  iVar1 = vswprintf_s(param_1,0x32,param_2,(va_list)&local_res18);
  return iVar1;
}



===== OpenFileSystemKernel @ 14000d23c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl CimFs::OpenFileSystemKernel(class gsl::span<wchar_t const ,-1>,class
   utl::vector<struct Cim::Format::RegionSet,class utl::allocator<struct Cim::Format::RegionSet> > &
   __ptr64,struct Cim::Format::RegionOffset & __ptr64,class gsl::span<enum gsl::byte,-1> *
   __ptr64,void * __ptr64,void * __ptr64) */

long __cdecl
CimFs::OpenFileSystemKernel
          (undefined4 *param_1,
          vector<Cim::Format::RegionSet,utl::allocator<Cim::Format::RegionSet>_> *param_2,
          undefined8 *param_3,undefined8 param_4,longlong param_5,undefined8 param_6)

{
  char cVar1;
  undefined8 *puVar2;
  longlong lVar3;
  short sVar4;
  undefined8 uVar5;
  bool bVar6;
  int iVar7;
  long lVar8;
  uint *puVar9;
  uint *puVar10;
  undefined8 *puVar11;
  uint *puVar12;
  char *pcVar13;
  __uint64 _Var14;
  uint uVar15;
  ulonglong uVar16;
  undefined1 auStackY_1e8 [32];
  longlong local_168 [2];
  undefined8 local_158;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  ulonglong local_148;
  ulonglong uStack_140;
  ulonglong local_138;
  uint *puStack_130;
  undefined8 *local_128;
  ulonglong local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 local_100;
  ulonglong *local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined4 local_d8 [2];
  undefined8 local_d0;
  undefined8 local_c8;
  undefined1 local_c0;
  undefined8 local_bc;
  undefined8 uStack_b4;
  undefined8 local_ac;
  undefined8 uStack_a4;
  undefined2 local_9c;
  undefined1 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  longlong local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  longlong local_58;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1e8;
  uStack_150 = param_1[2];
  uStack_14c = param_1[3];
  uStack_110 = *(undefined8 *)(param_1 + 2);
  local_bc = 0;
  uStack_b4 = 0;
  local_ac = 0;
  uStack_a4 = 0;
  local_d0 = 0x22500080078;
  local_80 = 0;
  uStack_78 = 0;
  sVar4 = (short)*param_1 * 2;
  local_158 = (ushort *)(ulonglong)CONCAT22(sVar4,sVar4);
  local_f8 = &local_118;
  local_d8[0] = 0;
  local_c8 = 0;
  local_c0 = 0;
  local_9c = 0;
  local_88 = 0;
  local_70 = 0;
  local_58 = 0;
  local_108 = 0x30;
  local_f0 = 0x240;
  local_100 = 0;
  local_168[0] = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_118 = (ulonglong)local_158;
  local_e8 = 0;
  uStack_e0 = 0;
  local_148 = 0;
  uStack_140 = 0;
  local_128 = param_3;
  if (param_5 == 0) {
    iVar7 = IoCreateFile(local_168,0x120089,&local_108,&local_148);
  }
  else {
    iVar7 = FltCreateFileEx2(param_5,param_6,local_168,0);
  }
  if (iVar7 < 0) {
    ProcessTraceStatusFromApi
              (iVar7,(StackEventTracer *)local_d8,0x22a000800be,"CimFs::OpenFileSystemKernel",
               "API: Opening cim file. Path: %ws");
    if (local_168[0] != 0) {
      ZwClose();
    }
  }
  else {
    puVar9 = (uint *)ExAllocatePoolWithTag(0x401,0x1000,0x6d4d4943);
    if (puVar9 == (uint *)0x0) {
      if (local_168[0] != 0) {
        ZwClose();
      }
      return -0x3fffff66;
    }
    local_158 = (ushort *)0x0;
    iVar7 = ZwReadFile(local_168[0],0,0,0);
    if (iVar7 == 0x103) {
      ZwWaitForSingleObject(local_168[0],0,0);
    }
    uVar16 = uStack_140;
    local_138 = uStack_140;
    if (uStack_140 == 0xffffffffffffffff) {
                    /* WARNING: Subroutine does not return */
      gsl::details::terminate();
    }
    puStack_130 = puVar9;
    if (local_168[0] != 0) {
      ZwClose();
    }
    if ((0x47 < uVar16) && (puVar9 != (uint *)0x0)) {
      puVar12 = puVar9 + 2;
      if (puVar9 != puVar12) {
        pcVar13 = "cimfile0SET Error - formatting failed";
        puVar10 = puVar9;
        do {
          cVar1 = *pcVar13;
          pcVar13 = pcVar13 + 1;
          if ((char)*puVar10 != cVar1) goto LAB_14000d7cb;
          puVar10 = (uint *)((longlong)puVar10 + 1);
        } while (puVar10 != puVar12);
      }
      if (((int)*(undefined8 *)(puVar9 + 4) - 1U < 4) && (*puVar12 == uVar16)) {
        local_148 = 0;
        uStack_140 = 0;
        local_158 = (ushort *)((longlong)puVar9 + 0x46);
        lVar8 = Cim::TryConvertSubspan<Cim::Format::RegionSet,gsl::byte>(&local_148,&local_138);
        uVar16 = 0;
        if (lVar8 < 0) {
          ProcessTraceStatusPushLocation
                    (lVar8,(StackEventTracer *)local_d8,0x356000800fc,"CimFs::OpenFileSystemKernel",
                     "PUSH: Failed to convert parent region sets span.");
        }
        else {
          if (*(ushort *)((longlong)puVar9 + 0x46) != 0) {
            do {
              if (local_148 <= uVar16) {
                    /* WARNING: Subroutine does not return */
                gsl::details::terminate();
              }
              puVar11 = (undefined8 *)(uStack_140 + uVar16 * 0x18);
              puVar2 = *(undefined8 **)(param_2 + 8);
              if (puVar2 == *(undefined8 **)(param_2 + 0x10)) {
                lVar3 = *(longlong *)param_2;
                bVar6 = utl::vector<Cim::Format::RegionSet,utl::allocator<Cim::Format::RegionSet>_>
                        ::_Grow(param_2);
                if (!bVar6) {
                  _Var14 = 0xf000080105;
                  goto LAB_14000d701;
                }
                puVar2 = *(undefined8 **)(param_2 + 8);
                if ((ulonglong)((longlong)puVar11 - lVar3) <
                    (ulonglong)((longlong)puVar2 - *(longlong *)param_2)) {
                  puVar11 = (undefined8 *)(*(longlong *)param_2 + ((longlong)puVar11 - lVar3));
                }
                uVar5 = puVar11[1];
                *puVar2 = *puVar11;
                puVar2[1] = uVar5;
                puVar2[2] = puVar11[2];
              }
              else {
                uVar5 = puVar11[1];
                *puVar2 = *puVar11;
                puVar2[1] = uVar5;
                puVar2[2] = puVar11[2];
              }
              *(longlong *)(param_2 + 8) = *(longlong *)(param_2 + 8) + 0x18;
              uVar15 = (int)uVar16 + 1;
              uVar16 = (ulonglong)uVar15;
            } while (uVar15 < *local_158);
            param_3 = local_128;
          }
          puVar11 = *(undefined8 **)(param_2 + 8);
          puVar12 = puVar9 + 8;
          if (puVar11 == *(undefined8 **)(param_2 + 0x10)) {
            lVar3 = *(longlong *)param_2;
            bVar6 = utl::vector<Cim::Format::RegionSet,utl::allocator<Cim::Format::RegionSet>_>::
                    _Grow(param_2);
            if (!bVar6) {
              _Var14 = 0xf10008010e;
LAB_14000d701:
              ProcessTraceStatusOrigin
                        (-0x3fffff66,(StackEventTracer *)local_d8,_Var14,
                         "CimFs::OpenFileSystemKernel","ORIGIN: Failed to add regionSet");
              if (puVar9 != (uint *)0x0) {
                ExFreePoolWithTag(puVar9,0);
              }
              if (local_58 != 0) {
                ExFreePoolWithTag(local_58,0);
              }
              if (local_70 == 0) {
                return -0x3fffff66;
              }
              ExFreePoolWithTag(local_70,0);
              return -0x3fffff66;
            }
            puVar11 = *(undefined8 **)(param_2 + 8);
            if ((ulonglong)((longlong)puVar12 - lVar3) <
                (ulonglong)((longlong)puVar11 - *(longlong *)param_2)) {
              puVar12 = (uint *)(((longlong)puVar12 - lVar3) + *(longlong *)param_2);
            }
            uVar5 = *(undefined8 *)(puVar12 + 2);
            *puVar11 = *(undefined8 *)puVar12;
            puVar11[1] = uVar5;
            puVar11[2] = *(undefined8 *)(puVar12 + 4);
          }
          else {
            uVar5 = *(undefined8 *)(puVar9 + 10);
            *puVar11 = *(undefined8 *)puVar12;
            puVar11[1] = uVar5;
            puVar11[2] = *(undefined8 *)(puVar9 + 0xc);
          }
          *(longlong *)(param_2 + 8) = *(longlong *)(param_2 + 8) + 0x18;
          *param_3 = *(undefined8 *)(puVar9 + 0xe);
        }
        if (puVar9 != (uint *)0x0) {
          ExFreePoolWithTag(puVar9,0);
        }
        if (local_58 != 0) {
          ExFreePoolWithTag(local_58,0);
        }
        if (local_70 != 0) {
          ExFreePoolWithTag(local_70,0);
        }
        return lVar8;
      }
    }
LAB_14000d7cb:
    iVar7 = -0x3ffffff3;
    ProcessTraceStatusOrigin
              (-0x3ffffff3,(StackEventTracer *)local_d8,0xef000800f0,"CimFs::OpenFileSystemKernel",
               "ORIGIN: Invalid FilesystemHeader. Path: %ws");
    if (puVar9 != (uint *)0x0) {
      ExFreePoolWithTag(puVar9,0);
    }
  }
  if (local_58 != 0) {
    ExFreePoolWithTag(local_58,0);
  }
  if (local_70 != 0) {
    ExFreePoolWithTag(local_70,0);
  }
  return iVar7;
}



===== OpenFileSystemsKernel @ 14000d874 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl CimFs::OpenFileSystemsKernel(class gsl::span<class gsl::span<wchar_t const
   ,-1>,-1>,class utl::vector<struct CimFs::MappedRegionKernel,class utl::allocator<struct
   CimFs::MappedRegionKernel> > & __ptr64,struct Cim::Format::RegionOffset & __ptr64,void *
   __ptr64,void * __ptr64) */

long __cdecl
CimFs::OpenFileSystemsKernel
          (longlong *param_1,undefined8 param_2,ulonglong *param_3,undefined8 param_4)

{
  short sVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined8 uVar4;
  long lVar5;
  ulonglong uVar6;
  ulonglong *puVar7;
  ulonglong *puVar8;
  undefined1 auStackY_178 [32];
  undefined8 local_148;
  ulonglong uStack_140;
  ulonglong local_138 [2];
  longlong local_128;
  longlong lStack_120;
  undefined8 local_118;
  undefined8 local_108;
  longlong local_f8;
  longlong lStack_f0;
  undefined4 local_e8 [2];
  undefined8 local_e0;
  undefined8 local_d8;
  undefined1 local_d0;
  undefined8 local_cc;
  undefined8 uStack_c4;
  undefined8 local_bc;
  undefined8 uStack_b4;
  undefined2 local_ac;
  undefined1 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  longlong local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  longlong local_68;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_178;
  puVar7 = (ulonglong *)param_1[1];
  puVar8 = puVar7 + *param_1 * 2;
  local_e8[0] = 0;
  local_e0 = 0x22400080191;
  local_d8 = 0;
  local_d0 = 0;
  local_cc = 0;
  uStack_c4 = 0;
  local_ac = 0;
  local_bc = 0;
  uStack_b4 = 0;
  local_98 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  local_108 = param_2;
  while( true ) {
    uVar4 = local_108;
    if (puVar7 == puVar8) {
      return 0;
    }
    local_118 = 0xffffffffffffffff;
    local_128 = -1;
    lStack_120 = -1;
    local_138[0] = 0;
    local_148 = *puVar7;
    uStack_140 = puVar7[1];
    lVar5 = OpenFileSystemKernel(&local_148,&local_128,local_138);
    lVar3 = local_128;
    if (lVar5 < 0) {
      ProcessTraceStatusPushLocation
                (lVar5,(StackEventTracer *)local_e8,0xf60008019b,"CimFs::OpenFileSystemsKernel",
                 "PUSH: OpenFileSystemKernel failed");
      if (local_128 - 1U < 0xfffffffffffffffe) {
        ExFreePoolWithTag(local_128,0);
      }
      if (local_68 != 0) {
        ExFreePoolWithTag(local_68,0);
      }
      if (local_80 != 0) {
        ExFreePoolWithTag(local_80,0);
      }
      return lVar5;
    }
    local_f8 = (lStack_120 - local_128 >> 3) * -0x5555555555555555;
    if ((local_f8 == -1) || ((lStack_f0 = local_128, local_128 == 0 && (local_f8 != 0)))) break;
    local_148 = *puVar7;
    uStack_140 = puVar7[1];
    uVar6 = local_148;
    do {
      uVar2 = uVar6;
      uVar6 = uVar2 - 1;
      if ((longlong)uVar6 < 0) {
        uVar6 = 0;
        uStack_140 = 0;
        goto LAB_14000d9c6;
      }
      if (local_148 <= uVar6) goto LAB_14000dbc0;
    } while (*(short *)(uStack_140 + uVar6 * 2) != 0x5c);
    if (((local_148 < uVar6) || (((uStack_140 == 0 && (uVar6 != 0)) || (local_148 < uVar2)))) ||
       (local_148 - uVar2 == -1)) break;
LAB_14000d9c6:
    sVar1 = (short)uVar6 * 2;
    lStack_120 = local_128;
    local_148 = (ulonglong)CONCAT22(sVar1,sVar1);
    local_128 = local_f8;
    lVar5 = OpenRegionSetsKernel(&local_148,&local_128,uVar4,param_4);
    if (lVar5 < 0) {
      ProcessTraceStatusPushLocation
                (lVar5,(StackEventTracer *)local_e8,0xf7000801a2,"CimFs::OpenFileSystemsKernel",
                 "PUSH: OpenRegionSetsKernel failed");
      if (lVar3 - 1U < 0xfffffffffffffffe) {
        ExFreePoolWithTag(lVar3,0);
      }
      if (local_68 != 0) {
        ExFreePoolWithTag(local_68,0);
      }
      if (local_80 != 0) {
        ExFreePoolWithTag(local_80,0);
      }
      return lVar5;
    }
    if (((*param_3 & 0xffffffffffff) == 0) && (*param_3 < 0x1000000000000)) {
      *param_3 = local_138[0];
    }
    if (lVar3 - 1U < 0xfffffffffffffffe) {
      ExFreePoolWithTag(lVar3,0);
    }
    puVar7 = puVar7 + 2;
  }
LAB_14000dbc0:
                    /* WARNING: Subroutine does not return */
  gsl::details::terminate();
}



===== OpenRegionKernel @ 14000dbcc =====

/* long __cdecl CimFs::OpenRegionKernel(void * __ptr64 const,struct CimFs::MappedRegionKernel &
   __ptr64,void * __ptr64,void * __ptr64,class CimFs::StackEventTracer & __ptr64) */

long __cdecl
CimFs::OpenRegionKernel
          (void *param_1,MappedRegionKernel *param_2,void *param_3,void *param_4,
          StackEventTracer *param_5)

{
  short sVar1;
  int iVar2;
  undefined8 in_stack_ffffffffffffff48;
  undefined4 uVar3;
  undefined8 in_stack_ffffffffffffff50;
  uint uVar4;
  undefined8 in_stack_ffffffffffffff58;
  undefined4 uVar5;
  undefined8 in_stack_ffffffffffffff60;
  undefined4 uVar6;
  undefined8 in_stack_ffffffffffffff70;
  undefined4 uVar7;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  MappedRegionKernel *pMStack_40;
  undefined8 local_38;
  void *local_30;
  ulonglong *local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  uVar4 = (uint)((ulonglong)in_stack_ffffffffffffff50 >> 0x20);
  uVar5 = (undefined4)((ulonglong)in_stack_ffffffffffffff58 >> 0x20);
  uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffff60 >> 0x20);
  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffff48 >> 0x20);
  uVar7 = (undefined4)((ulonglong)in_stack_ffffffffffffff70 >> 0x20);
  iVar2 = *(int *)(param_2 + 0x74);
  pMStack_40 = param_2 + 0x10;
  if ((iVar2 == -1) || ((pMStack_40 == (MappedRegionKernel *)0x0 && (iVar2 != 0)))) {
                    /* WARNING: Subroutine does not return */
    gsl::details::terminate();
  }
  sVar1 = (short)iVar2 * 2;
  local_38 = 0x30;
  local_20 = 0x240;
  local_58 = (ulonglong)CONCAT22(sVar1,sVar1);
  local_28 = &local_48;
  local_48 = local_58;
  local_18 = 0;
  uStack_10 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_30 = param_1;
  if (param_3 == (void *)0x0) {
    if (*(longlong *)param_2 != 0) {
      ZwClose();
    }
    *(undefined8 *)param_2 = 0;
    iVar2 = IoCreateFile(param_2,0x120089,&local_38,&local_58,0,(ulonglong)uVar4 << 0x20,
                         CONCAT44(uVar5,1),CONCAT44(uVar6,1),0x40,0,0,0,0,0x101);
  }
  else {
    if (*(longlong *)param_2 != 0) {
      ZwClose();
    }
    *(undefined8 *)param_2 = 0;
    iVar2 = FltCreateFileEx2(param_3,param_4,param_2,0,CONCAT44(uVar3,0x120089),&local_38,&local_58,
                             0,0,CONCAT44(uVar7,1),1,0x40,0,0,0x101,0);
  }
  if (iVar2 < 0) {
    ProcessTraceStatusFromApi
              (iVar2,param_5,0xec0008005f,"CimFs::OpenRegionKernel",
               "API: Opening region file. Path: %ws",pMStack_40);
  }
  return iVar2;
}



===== OpenRegionSetsKernel @ 14000ddb8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl CimFs::OpenRegionSetsKernel(struct _UNICODE_STRING,class gsl::span<struct
   Cim::Format::RegionSet const ,-1>,class utl::vector<struct CimFs::MappedRegionKernel,class
   utl::allocator<struct CimFs::MappedRegionKernel> > & __ptr64,void * __ptr64,void * __ptr64) */

long __cdecl
CimFs::OpenRegionSetsKernel
          (undefined8 param_1,longlong *param_2,
          vector<CimFs::MappedRegionKernel,utl::allocator<CimFs::MappedRegionKernel>_> *param_3,
          void *param_4,void *param_5)

{
  undefined8 *puVar1;
  MappedRegionKernel *pMVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  MappedRegionKernel *pMVar6;
  bool bVar7;
  int iVar8;
  uint *puVar9;
  ulonglong uVar10;
  __uint64 _Var11;
  longlong lVar12;
  longlong lVar13;
  uint *puVar14;
  ushort uVar15;
  undefined1 auStackY_1d8 [32];
  void *local_158;
  void *local_150;
  void *local_148;
  MappedRegionKernel *local_140;
  vector<CimFs::MappedRegionKernel,utl::allocator<CimFs::MappedRegionKernel>_> *local_138;
  uint *local_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined4 local_e8 [2];
  undefined8 local_e0;
  undefined8 local_d8;
  undefined1 local_d0;
  undefined8 local_cc;
  undefined8 uStack_c4;
  undefined8 local_bc;
  undefined8 uStack_b4;
  undefined2 local_ac;
  undefined1 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  longlong local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  longlong local_68;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_1d8;
  local_e8[0] = 0;
  local_d8 = 0;
  local_d0 = 0;
  lVar12 = *param_2;
  local_150 = param_5;
  local_e0 = 0x2260008011c;
  local_ac = 0;
  local_98 = 0;
  local_80 = 0;
  local_68 = 0;
  local_cc = 0;
  uStack_c4 = 0;
  local_bc = 0;
  uStack_b4 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_148 = param_4;
  local_138 = param_3;
  if (lVar12 == 0) {
    iVar8 = -0x3ffffff3;
    ProcessTraceStatusOrigin
              (-0x3ffffff3,(StackEventTracer *)local_e8,0xf200080123,"CimFs::OpenRegionSetsKernel",
               "ORIGIN: RegionSets empty");
LAB_14000de7c:
    if (local_68 != 0) {
      ExFreePoolWithTag(local_68,0);
    }
    if (local_80 != 0) {
      ExFreePoolWithTag(local_80,0);
    }
  }
  else {
    local_118 = 0x30;
    local_100 = 0x240;
    local_110 = 0;
    local_158 = (void *)0x0;
    local_128 = 0;
    uStack_120 = 0;
    local_f8 = 0;
    uStack_f0 = 0;
    local_108 = param_1;
    if (param_4 == (void *)0x0) {
      iVar8 = IoCreateFile(&local_158,0x100001,&local_118,&local_128);
    }
    else {
      iVar8 = FltCreateFileEx2(param_4,param_5,&local_158,0);
    }
    if (iVar8 < 0) {
      ProcessTraceStatusFromApi
                (iVar8,(StackEventTracer *)local_e8,0xf30008015e,"CimFs::OpenRegionSetsKernel",
                 "API: Opening cim directory. Path: %ws");
      if (local_158 != (void *)0x0) {
        ZwClose();
      }
      if (local_68 != 0) {
        ExFreePoolWithTag(local_68,0);
      }
      if (local_80 != 0) {
        ExFreePoolWithTag(local_80,0);
      }
    }
    else {
      puVar14 = (uint *)param_2[1];
      puVar9 = puVar14 + lVar12 * 6;
      lVar12 = 0;
      lVar13 = 0;
      local_130 = puVar9;
      if (puVar14 != puVar9) {
        do {
          uVar15 = 0;
          if ((short)puVar14[4] != 0) {
            do {
              if (*(longlong *)(param_3 + 8) == *(longlong *)(param_3 + 0x10)) {
                uVar10 = (*(longlong *)(param_3 + 0x10) - *(longlong *)param_3 >> 4) *
                         -0x71c71c71c71c71c7;
                _Var11 = (uVar10 >> 2) * 7 + 8;
                if (0xe38e38e38e38e3 < _Var11) {
                  _Var11 = 0xe38e38e38e38e3;
                }
                if ((uVar10 < _Var11) &&
                   (bVar7 = utl::
                            vector<CimFs::MappedRegionKernel,utl::allocator<CimFs::MappedRegionKernel>_>
                            ::_SetCapacity(param_3,_Var11), bVar7)) goto LAB_14000e0a2;
                iVar8 = -0x3fffff66;
                ProcessTraceStatusOrigin
                          (-0x3fffff66,(StackEventTracer *)local_e8,0xf400080177,
                           "CimFs::OpenRegionSetsKernel","ORIGIN: Failed to add region");
LAB_14000e271:
                if (local_158 != (void *)0x0) {
                  ZwClose();
                }
                goto LAB_14000de7c;
              }
LAB_14000e0a2:
              puVar1 = *(undefined8 **)(param_3 + 8);
              memset(puVar1 + 2,0,0x80);
              *puVar1 = 0;
              puVar1[1] = 0;
              *(undefined4 *)((longlong)puVar1 + 0x74) = 0;
              pMVar2 = *(MappedRegionKernel **)(param_3 + 8);
              *(MappedRegionKernel **)(param_3 + 8) = pMVar2 + 0x90;
              local_140 = pMVar2;
              iVar8 = swprintf_s<50>((wchar_t *)(pMVar2 + 0x10),
                                     L"%ls_%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x_%u",
                                     (char *)L"region",*puVar14,(uint)(ushort)puVar14[1],
                                     (uint)*(ushort *)((longlong)puVar14 + 6),(uint)(byte)puVar14[2]
                                     ,(uint)*(byte *)((longlong)puVar14 + 9),
                                     (uint)*(byte *)((longlong)puVar14 + 10),
                                     (uint)*(byte *)((longlong)puVar14 + 0xb),(uint)(byte)puVar14[3]
                                     ,(uint)*(byte *)((longlong)puVar14 + 0xd),
                                     (uint)*(byte *)((longlong)puVar14 + 0xe),
                                     (uint)*(byte *)((longlong)puVar14 + 0xf),(uint)uVar15);
              pMVar6 = local_140;
              *(int *)(pMVar2 + 0x74) = iVar8;
              iVar8 = OpenRegionKernel(local_158,local_140,local_148,local_150,
                                       (StackEventTracer *)local_e8);
              if (iVar8 < 0) {
                ProcessTraceStatusPushLocation
                          (iVar8,(StackEventTracer *)local_e8,0xf500080180,
                           "CimFs::OpenRegionSetsKernel","PUSH: OpenRegionKernel failed");
                goto LAB_14000e271;
              }
              *(ushort *)(pMVar6 + 0x88) = uVar15;
              uVar15 = uVar15 + 1;
              uVar3 = puVar14[1];
              uVar4 = puVar14[2];
              uVar5 = puVar14[3];
              *(uint *)(pMVar6 + 0x78) = *puVar14;
              *(uint *)(pMVar6 + 0x7c) = uVar3;
              *(uint *)(pMVar6 + 0x80) = uVar4;
              *(uint *)(pMVar6 + 0x84) = uVar5;
              param_3 = local_138;
            } while (uVar15 < (ushort)puVar14[4]);
            puVar9 = local_130;
          }
          puVar14 = puVar14 + 6;
        } while (puVar14 != puVar9);
        lVar12 = local_80;
        lVar13 = local_68;
      }
      if (local_158 != (void *)0x0) {
        ZwClose();
      }
      if (lVar13 != 0) {
        ExFreePoolWithTag(lVar13,0);
      }
      if (lVar12 != 0) {
        ExFreePoolWithTag(lVar12,0);
      }
      iVar8 = 0;
    }
  }
  return iVar8;
}



===== _Grow @ 14000e2c0 =====

/* private: bool __cdecl utl::vector<struct Cim::Format::RegionSet,class utl::allocator<struct
   Cim::Format::RegionSet> >::_Grow(void) __ptr64 */

bool __thiscall
utl::vector<Cim::Format::RegionSet,utl::allocator<Cim::Format::RegionSet>_>::_Grow
          (vector<Cim::Format::RegionSet,utl::allocator<Cim::Format::RegionSet>_> *this)

{
  longlong lVar1;
  longlong lVar2;
  void *_Dst;
  nothrow_t *pnVar3;
  nothrow_t *pnVar4;
  bool bVar5;
  
  pnVar4 = (nothrow_t *)
           ((*(longlong *)(this + 0x10) - *(longlong *)this >> 3) * -0x5555555555555555);
  pnVar3 = (nothrow_t *)(((ulonglong)pnVar4 >> 2) * 7 + 8);
  if ((nothrow_t *)0x555555555555555 < pnVar3) {
    pnVar3 = (nothrow_t *)0x555555555555555;
  }
  bVar5 = false;
  if ((pnVar4 < pnVar3) && (pnVar3 < (nothrow_t *)0xaaaaaaaaaaaaaab)) {
    _Dst = operator_new((longlong)pnVar3 * 0x18,pnVar4);
    if ((_Dst != (void *)0x0) && (_Dst != (void *)0xffffffffffffffff)) {
      memmove(_Dst,*(void **)this,(*(longlong *)(this + 8) - (longlong)*(void **)this >> 3) << 3);
      lVar1 = *(longlong *)this;
      lVar2 = *(longlong *)(this + 8);
      if ((lVar1 != -1) && (*(longlong *)(this + 8) = lVar1, lVar1 != 0)) {
        ExFreePoolWithTag(lVar1,0);
      }
      *(void **)this = _Dst;
      bVar5 = true;
      *(void **)(this + 8) = (void *)((longlong)_Dst + (lVar2 - lVar1 >> 3) * 8);
      *(void **)(this + 0x10) = (void *)((longlong)pnVar3 * 0x18 + (longlong)_Dst);
    }
  }
  return bVar5;
}



===== _SetCapacity @ 14000e3e0 =====

/* private: bool __cdecl utl::vector<struct CimFs::MappedRegionKernel,class utl::allocator<struct
   CimFs::MappedRegionKernel> >::_SetCapacity(unsigned __int64) __ptr64 */

bool __thiscall
utl::vector<CimFs::MappedRegionKernel,utl::allocator<CimFs::MappedRegionKernel>_>::_SetCapacity
          (vector<CimFs::MappedRegionKernel,utl::allocator<CimFs::MappedRegionKernel>_> *this,
          __uint64 param_1)

{
  MappedRegionKernel *pMVar1;
  bool bVar2;
  MappedRegionKernel *pMVar3;
  allocator<CimFs::MappedRegionKernel> *paVar4;
  bool bVar5;
  longlong lVar6;
  
  bVar5 = false;
  if (param_1 < 0x1c71c71c71c71c8) {
    pMVar3 = operator_new(param_1 * 0x90,(nothrow_t *)param_1);
    if ((pMVar3 != (MappedRegionKernel *)0x0) &&
       (pMVar3 != (MappedRegionKernel *)0xffffffffffffffff)) {
      paVar4 = (allocator<CimFs::MappedRegionKernel> *)
               ((*(longlong *)(this + 8) - *(longlong *)this >> 4) * -0x71c71c71c71c71c7);
      bVar2 = _RangeTransferAppc<utl::allocator<CimFs::MappedRegionKernel>_>();
      if (bVar2) {
        pMVar1 = *(MappedRegionKernel **)this;
        lVar6 = *(longlong *)(this + 8) - (longlong)pMVar1 >> 4;
        if (pMVar1 != (MappedRegionKernel *)0xffffffffffffffff) {
          *(MappedRegionKernel **)(this + 8) = pMVar1;
          _RangeDestroyApc<utl::allocator<CimFs::MappedRegionKernel>_>
                    (paVar4,pMVar1,lVar6 * -0x71c71c71c71c71c7);
          if (*(longlong *)this != 0) {
            ExFreePoolWithTag(*(longlong *)this,0);
          }
        }
        *(MappedRegionKernel **)this = pMVar3;
        bVar5 = true;
        *(MappedRegionKernel **)(this + 8) = pMVar3 + lVar6 * 0x10;
        *(MappedRegionKernel **)(this + 0x10) = pMVar3 + param_1 * 0x90;
      }
      else {
        _RangeDestroyApc<utl::allocator<CimFs::MappedRegionKernel>_>(paVar4,pMVar3,0);
        ExFreePoolWithTag(pMVar3,0);
      }
    }
  }
  return bVar5;
}



===== ProcessTraceStatusFromApi @ 14000e4f8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl CimFs::ProcessTraceStatusFromApi(long,class CimFs::StackEventTracer &
   __ptr64,unsigned __int64,char const * __ptr64,char const * __ptr64,...) */

void __cdecl
CimFs::ProcessTraceStatusFromApi
          (long param_1,StackEventTracer *param_2,__uint64 param_3,char *param_4,char *param_5,...)

{
  uint uVar1;
  ulonglong uVar2;
  _tlgWrapSz<char> *p_Var3;
  _tlgProvider_t *_Dest;
  undefined *puVar4;
  _GUID *_Args;
  _GUID _Stack0000000000000030;
  undefined1 auStackY_4a8 [32];
  _tlgWrapSz<char> *p_Var5;
  _tlgWrapperByVal<4> *p_Var6;
  _tlgWrapperByVal<4> *p_Var7;
  undefined2 local_458 [2];
  long local_454;
  long local_450 [2];
  _tlgProvider_t *local_448;
  _tlgProvider_t *local_440;
  _tlgProvider_t local_438 [1023];
  undefined1 local_39;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_4a8;
  if (param_1 < 0) {
    *(undefined2 *)(param_2 + 0x3c) = 0;
    *(long *)param_2 = param_1;
    *(__uint64 *)(param_2 + 0x10) = param_3;
    param_2[0x18] = (StackEventTracer)0x1;
  }
  local_448 = (_tlgProvider_t *)0x0;
  uVar2 = Feature_CimfsStackEventTracerFix__private_IsEnabledDeviceUsageNoInline();
  _Args = &_Stack0000000000000030;
  _Dest = local_438;
  if ((int)uVar2 == 0) {
    uVar1 = _vsnprintf((char *)_Dest,0x3ff,param_5,(va_list)_Args);
    if (((int)uVar1 < 0) || (0x3fe < uVar1)) {
      local_39 = 0;
    }
  }
  else {
    SafeFormatMessage((char *)_Dest,(__uint64)param_2,param_5,(char *)_Args);
  }
  local_458[0] = (undefined2)param_3;
  local_450[0] = (long)(param_3 >> 0x20);
  if (((param_1 + 0x3ffffff1U < 2) || (param_1 == -0x3fffffdd)) || (param_1 == -0x7ffffffb)) {
    if (DAT_140017008 < 6) {
      return;
    }
    if ((DAT_140017018 & 5) == 0) {
      return;
    }
    if (((uint)DAT_140017020 & 5) != DAT_140017020) {
      return;
    }
    local_440 = local_438;
    puVar4 = &DAT_1400152b3;
    p_Var7 = (_tlgWrapperByVal<4> *)local_450;
    p_Var6 = (_tlgWrapperByVal<4> *)&local_454;
    p_Var5 = (_tlgWrapSz<char> *)&local_448;
    p_Var3 = (_tlgWrapSz<char> *)&local_440;
    local_454 = local_450[0];
    local_450[0] = param_1;
    local_448 = (_tlgProvider_t *)param_4;
  }
  else {
    if (DAT_140017008 < 3) {
      return;
    }
    if ((DAT_140017018 & 5) == 0) {
      return;
    }
    if (((uint)DAT_140017020 & 5) != DAT_140017020) {
      return;
    }
    local_448 = local_438;
    puVar4 = &DAT_14001520d;
    p_Var7 = (_tlgWrapperByVal<4> *)&local_454;
    p_Var6 = (_tlgWrapperByVal<4> *)local_450;
    p_Var5 = (_tlgWrapSz<char> *)&local_440;
    p_Var3 = (_tlgWrapSz<char> *)&local_448;
    local_454 = param_1;
    local_440 = (_tlgProvider_t *)param_4;
  }
  _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
  ::
  Write<_tlgWrapSz<char>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>_>
            (_Dest,puVar4,(_GUID *)param_5,_Args,p_Var3,p_Var5,p_Var6,
             (_tlgWrapperByVal<2> *)local_458,p_Var7);
  return;
}



===== ProcessTraceStatusOrigin @ 14000e6e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl CimFs::ProcessTraceStatusOrigin(long,class CimFs::StackEventTracer &
   __ptr64,unsigned __int64,char const * __ptr64,char const * __ptr64,...) */

void __cdecl
CimFs::ProcessTraceStatusOrigin
          (long param_1,StackEventTracer *param_2,__uint64 param_3,char *param_4,char *param_5,...)

{
  uint uVar1;
  ulonglong uVar2;
  _tlgWrapSz<char> *p_Var3;
  _tlgProvider_t *_Dest;
  undefined *puVar4;
  _GUID *_Args;
  _GUID _Stack0000000000000030;
  undefined1 auStackY_4a8 [32];
  _tlgWrapSz<char> *p_Var5;
  _tlgWrapperByVal<4> *p_Var6;
  _tlgWrapperByVal<4> *p_Var7;
  undefined2 local_458 [2];
  long local_454;
  long local_450 [2];
  _tlgProvider_t *local_448;
  _tlgProvider_t *local_440;
  _tlgProvider_t local_438 [1023];
  undefined1 local_39;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_4a8;
  if (param_1 < 0) {
    *(undefined2 *)(param_2 + 0x3c) = 0;
    *(long *)param_2 = param_1;
    *(__uint64 *)(param_2 + 0x10) = param_3;
    param_2[0x18] = (StackEventTracer)0x0;
  }
  local_448 = (_tlgProvider_t *)0x0;
  uVar2 = Feature_CimfsStackEventTracerFix__private_IsEnabledDeviceUsageNoInline();
  _Args = &_Stack0000000000000030;
  _Dest = local_438;
  if ((int)uVar2 == 0) {
    uVar1 = _vsnprintf((char *)_Dest,0x3ff,param_5,(va_list)_Args);
    if (((int)uVar1 < 0) || (0x3fe < uVar1)) {
      local_39 = 0;
    }
  }
  else {
    SafeFormatMessage((char *)_Dest,(__uint64)param_2,param_5,(char *)_Args);
  }
  local_458[0] = (undefined2)param_3;
  local_450[0] = (long)(param_3 >> 0x20);
  if (((param_1 + 0x3ffffff1U < 2) || (param_1 == -0x3fffffdd)) || (param_1 == -0x7ffffffb)) {
    if (DAT_140017008 < 6) {
      return;
    }
    if ((DAT_140017018 & 3) == 0) {
      return;
    }
    if (((uint)DAT_140017020 & 3) != DAT_140017020) {
      return;
    }
    local_440 = local_438;
    puVar4 = &DAT_140015166;
    p_Var7 = (_tlgWrapperByVal<4> *)local_450;
    p_Var6 = (_tlgWrapperByVal<4> *)&local_454;
    p_Var5 = (_tlgWrapSz<char> *)&local_448;
    p_Var3 = (_tlgWrapSz<char> *)&local_440;
    local_454 = local_450[0];
    local_450[0] = param_1;
    local_448 = (_tlgProvider_t *)param_4;
  }
  else {
    if (DAT_140017008 < 3) {
      return;
    }
    if ((DAT_140017018 & 3) == 0) {
      return;
    }
    if (((uint)DAT_140017020 & 3) != DAT_140017020) {
      return;
    }
    local_448 = local_438;
    puVar4 = &DAT_140015260;
    p_Var7 = (_tlgWrapperByVal<4> *)&local_454;
    p_Var6 = (_tlgWrapperByVal<4> *)local_450;
    p_Var5 = (_tlgWrapSz<char> *)&local_440;
    p_Var3 = (_tlgWrapSz<char> *)&local_448;
    local_454 = param_1;
    local_440 = (_tlgProvider_t *)param_4;
  }
  _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
  ::
  Write<_tlgWrapSz<char>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>_>
            (_Dest,puVar4,(_GUID *)param_5,_Args,p_Var3,p_Var5,p_Var6,
             (_tlgWrapperByVal<2> *)local_458,p_Var7);
  return;
}



===== ProcessTraceStatusPushLocation @ 14000e8c8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl CimFs::ProcessTraceStatusPushLocation(long,class CimFs::StackEventTracer &
   __ptr64,unsigned __int64,char const * __ptr64,char const * __ptr64,...) */

void __cdecl
CimFs::ProcessTraceStatusPushLocation
          (long param_1,StackEventTracer *param_2,__uint64 param_3,char *param_4,char *param_5,...)

{
  uint uVar1;
  ulonglong uVar2;
  _tlgWrapSz<char> *p_Var3;
  long lVar4;
  _tlgProvider_t *_Dest;
  undefined *puVar5;
  _GUID *_Args;
  _GUID _Stack0000000000000030;
  undefined1 auStackY_4b8 [32];
  _tlgWrapSz<char> *p_Var6;
  _tlgWrapperByVal<4> *p_Var7;
  _tlgWrapperByVal<4> *p_Var8;
  undefined2 local_468 [2];
  long local_464;
  long local_460 [2];
  _tlgProvider_t *local_458;
  _tlgProvider_t *local_450;
  _tlgProvider_t local_448 [1023];
  undefined1 local_49;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_4b8;
  lVar4 = (long)(param_3 >> 0x20);
  if (param_1 < 0) {
    if (*(longlong *)(param_2 + 0x10) == 0) {
      *(undefined2 *)(param_2 + 0x3c) = 0;
      *(long *)param_2 = param_1;
      *(__uint64 *)(param_2 + 0x10) = param_3;
      param_2[0x18] = (StackEventTracer)0x0;
    }
    else if ((*(ushort *)(param_2 + 0x3c) < 8) && (*(int *)param_2 < 0)) {
      *(long *)(param_2 + (ulonglong)*(ushort *)(param_2 + 0x3c) * 4 + 0x1c) = lVar4;
      *(short *)(param_2 + 0x3c) = *(short *)(param_2 + 0x3c) + 1;
    }
  }
  local_458 = (_tlgProvider_t *)0x0;
  uVar2 = Feature_CimfsStackEventTracerFix__private_IsEnabledDeviceUsageNoInline();
  _Args = &_Stack0000000000000030;
  _Dest = local_448;
  if ((int)uVar2 == 0) {
    uVar1 = _vsnprintf((char *)_Dest,0x3ff,param_5,(va_list)_Args);
    if (((int)uVar1 < 0) || (0x3fe < uVar1)) {
      local_49 = 0;
    }
  }
  else {
    SafeFormatMessage((char *)_Dest,(__uint64)param_2,param_5,(char *)_Args);
  }
  local_468[0] = (undefined2)param_3;
  if (((param_1 + 0x3ffffff1U < 2) || (param_1 == -0x3fffffdd)) || (param_1 == -0x7ffffffb)) {
    if (DAT_140017008 < 6) {
      return;
    }
    if ((DAT_140017018 & 9) == 0) {
      return;
    }
    if (((uint)DAT_140017020 & 9) != DAT_140017020) {
      return;
    }
    local_450 = local_448;
    puVar5 = &DAT_140015111;
    p_Var8 = (_tlgWrapperByVal<4> *)local_460;
    p_Var7 = (_tlgWrapperByVal<4> *)&local_464;
    p_Var6 = (_tlgWrapSz<char> *)&local_458;
    p_Var3 = (_tlgWrapSz<char> *)&local_450;
    local_464 = lVar4;
    local_460[0] = param_1;
    local_458 = (_tlgProvider_t *)param_4;
  }
  else {
    if (DAT_140017008 < 5) {
      return;
    }
    if ((DAT_140017018 & 9) == 0) {
      return;
    }
    if (((uint)DAT_140017020 & 9) != DAT_140017020) {
      return;
    }
    local_458 = local_448;
    puVar5 = &DAT_1400151bb;
    p_Var8 = (_tlgWrapperByVal<4> *)&local_464;
    p_Var7 = (_tlgWrapperByVal<4> *)local_460;
    p_Var6 = (_tlgWrapSz<char> *)&local_450;
    p_Var3 = (_tlgWrapSz<char> *)&local_458;
    local_464 = param_1;
    local_460[0] = lVar4;
    local_450 = (_tlgProvider_t *)param_4;
  }
  _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
  ::
  Write<_tlgWrapSz<char>,_tlgWrapSz<char>,_tlgWrapperByVal<4>,_tlgWrapperByVal<2>,_tlgWrapperByVal<4>_>
            (_Dest,puVar5,(_GUID *)param_5,_Args,p_Var3,p_Var6,p_Var7,
             (_tlgWrapperByVal<2> *)local_468,p_Var8);
  return;
}



===== SafeFormatMessage @ 14000eae0 =====

/* void __cdecl CimFs::SafeFormatMessage(char * __ptr64,unsigned __int64,char const * __ptr64,char *
   __ptr64) */

void __cdecl CimFs::SafeFormatMessage(char *param_1,__uint64 param_2,char *param_3,char *param_4)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  char *pcVar4;
  int iVar5;
  longlong lVar6;
  
  if (param_1 != (char *)0x0) {
    lVar6 = 0x400;
    if (param_3 == (char *)0x0) {
      lVar3 = 0x7ffffffe;
      pcVar4 = "No message provided";
      for (; lVar6 != 0; lVar6 = lVar6 + -1) {
        if ((lVar3 == 0) || (cVar1 = *pcVar4, cVar1 == '\0')) {
          if (lVar6 != 0) goto LAB_14000ec63;
          break;
        }
        pcVar4 = pcVar4 + 1;
        *param_1 = cVar1;
        param_1 = param_1 + 1;
        lVar3 = lVar3 + -1;
      }
      param_1 = param_1 + -1;
    }
    else {
      iVar5 = 0;
      uVar2 = _vsnprintf(param_1,0x3ff,param_3,param_4);
      if (((int)uVar2 < 0) || (0x3ff < uVar2)) {
        param_1[0x3ff] = '\0';
        iVar5 = -0x7ff8ff86;
      }
      else if (uVar2 == 0x3ff) {
        param_1[0x3ff] = '\0';
      }
      if (-1 < iVar5) {
        return;
      }
      lVar3 = 0x7ffffffe;
      pcVar4 = "SET Error - formatting failed";
      for (; lVar6 != 0; lVar6 = lVar6 + -1) {
        if ((lVar3 == 0) || (cVar1 = *pcVar4, cVar1 == '\0')) {
          if (lVar6 != 0) goto LAB_14000ec63;
          break;
        }
        pcVar4 = pcVar4 + 1;
        *param_1 = cVar1;
        param_1 = param_1 + 1;
        lVar3 = lVar3 + -1;
      }
      param_1 = param_1 + -1;
    }
LAB_14000ec63:
    *param_1 = '\0';
  }
  return;
}



===== Feature_CimfsStackEventTracerFix__private_IsEnabledDeviceUsageNoInline @ 14000ecc8 =====

ulonglong Feature_CimfsStackEventTracerFix__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_CimfsStackEventTracerFix__private_featureState;
  if ((Feature_CimfsStackEventTracerFix__private_featureState & 0x10) == 0) {
    uVar1 = Feature_CimfsStackEventTracerFix__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_CimfsStackEventTracerFix__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_CimfsStackEventTracerFix__private_IsEnabledFallback @ 14000ed00 =====

void Feature_CimfsStackEventTracerFix__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 14000ed18 =====

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
LAB_14000ef1b:
    uVar5 = *param_2;
    do {
      uVar4 = uVar5;
      param_1[1] = 0;
      uVar5 = uVar4 | 1;
      if ((uVar4 >> 0xe & 1) != (uint)(param_3 == 4)) {
        uVar3 = uVar4 >> 5 & 0x1ff;
        if (uVar3 != 0) {
          param_1[1] = uVar3;
          param_1[2] = ~-(uint)(param_3 != 0) & 4;
          uVar5 = uVar4 & 0xffffc01f | 1;
        }
        uVar3 = 0;
        if (param_3 == 4) {
          uVar3 = 0x4000;
        }
        uVar5 = uVar3 | uVar5 & 0xffffbfff;
      }
      uVar6 = uVar5 >> 5 & 0x1ff;
      uVar3 = uVar6 + 1;
      if ((0x1ff < uVar3) || (uVar3 < uVar6)) {
        uVar3 = 1;
        param_1[2] = param_3;
        param_1[1] = uVar6;
      }
      LOCK();
      uVar6 = *param_2;
      if (uVar4 == uVar6) {
        *param_2 = uVar5 ^ (uVar3 << 5 ^ uVar5) & 0x3fe0;
        uVar5 = uVar4;
      }
      else {
        uVar5 = uVar6;
      }
      UNLOCK();
    } while (uVar4 != uVar6);
    *param_1 = ~uVar4 & 1;
  }
  else {
    if (param_3 != 1) {
      if ((param_3 == 2) || (param_3 == 3)) {
LAB_14000edf3:
        uVar5 = 0;
        if (param_3 == 2) {
          uVar5 = 2;
        }
        else if (param_3 == 3) {
          uVar5 = 8;
        }
        else if (param_3 == 6) {
          uVar5 = 4;
        }
        else if (param_3 == 7) {
          uVar5 = 0x10;
        }
        uVar3 = 1;
        uVar4 = *param_2;
        do {
          uVar2 = uVar4;
          uVar4 = uVar5 | uVar2;
          param_1[4] = (uint)(uVar4 == uVar2);
          uVar6 = uVar4 | 1;
          if (uVar4 == uVar2) {
            uVar6 = uVar4;
          }
          LOCK();
          uVar1 = *param_2;
          if (uVar2 == uVar1) {
            *param_2 = uVar6;
            uVar4 = uVar2;
          }
          else {
            uVar4 = uVar1;
          }
          UNLOCK();
        } while (uVar2 != uVar1);
        if (((uVar6 & 1) == 0) || ((uVar2 & 1) != 0)) {
          uVar3 = 0;
        }
        *param_1 = uVar3;
        return param_1;
      }
      if (param_3 == 4) goto LAB_14000ef1b;
      if (param_3 != 5) {
        if ((param_3 != 6) && (param_3 != 7)) {
          uVar5 = param_3 - 0x140;
          if ((int)uVar5 < 0x40) {
            uVar4 = param_2[1];
            do {
              if (((uVar4 & 0x10) == 0) || ((uVar4 >> 5 & 0x3f) != uVar5)) {
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
                param_2[1] = (uVar5 * 0x20 ^ uVar4) & 0x7e0 ^ uVar4 | 0x10;
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
        goto LAB_14000edf3;
      }
    }
    uVar5 = *param_2;
    do {
      uVar4 = uVar5;
      param_1[1] = 0;
      uVar5 = uVar4 | 1;
      if ((uVar4 >> 0x16 & 1) != (uint)(param_3 == 5)) {
        uVar3 = uVar4 >> 0xf & 0x7f;
        if (uVar3 != 0) {
          param_1[1] = uVar3;
          uVar3 = 5;
          if (param_3 != 1) {
            uVar3 = 1;
          }
          uVar5 = uVar4 & 0xffc07fff | 1;
          param_1[2] = uVar3;
        }
        uVar3 = 0;
        if (param_3 == 5) {
          uVar3 = 0x400000;
        }
        uVar5 = uVar3 | uVar5 & 0xffbfffff;
      }
      uVar6 = uVar5 >> 0xf & 0x7f;
      uVar3 = uVar6 + 1;
      if ((0x7f < uVar3) || (uVar3 < uVar6)) {
        uVar3 = 1;
        param_1[2] = param_3;
        param_1[1] = uVar6;
      }
      LOCK();
      uVar6 = *param_2;
      if (uVar4 == uVar6) {
        *param_2 = uVar5 ^ (uVar3 << 0xf ^ uVar5) & 0x3f8000;
        uVar5 = uVar4;
      }
      else {
        uVar5 = uVar6;
      }
      UNLOCK();
    } while (uVar4 != uVar6);
    *param_1 = ~uVar4 & 1;
  }
  param_1[4] = 0;
  return param_1;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 14000f004 =====

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
      goto LAB_14000f0c7;
    }
    if (param_3 == 2) {
      uVar2 = (uVar4 ^ 1) * 4 + 1;
      uVar3 = 0;
      goto LAB_14000f0c7;
    }
    if (param_3 == 3) {
      uVar2 = (uVar4 ^ 1) * 4 + 2;
      uVar3 = 0;
      goto LAB_14000f0c7;
    }
    if (param_3 == 4) {
      uVar2 = (uVar4 ^ 1) * 4 + 3;
      uVar3 = 0;
      goto LAB_14000f0c7;
    }
    uVar2 = param_3 - 5;
    uVar3 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      uVar2 = (uVar4 ^ 1) * 2 + 8;
      goto LAB_14000f0c7;
    }
    if (uVar2 == 1) {
      uVar2 = (uVar4 ^ 1) * 2 + 9;
      goto LAB_14000f0c7;
    }
    bVar5 = (char)param_3 + 0x9c;
    if (bVar5 < 0x32) {
      uVar2 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar5;
      goto LAB_14000f0c7;
    }
  }
  uVar2 = 0xff;
LAB_14000f0c7:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x36e3062,&Feature_SFS_CD_BugFixes_2406_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 14000f120 =====

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
                     (local_50,(uint *)&Feature_CimfsStackEventTracerFix__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)
              (0x36e3062,param_3,1,&Feature_CimfsStackEventTracerFix__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)param_3,0x36e3062);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 14000f20c =====

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
LAB_14000f2bf:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_14000f2ed;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_14000f2bf;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_14000f2ed:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 14000f478 =====

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
  if ((Feature_CimfsStackEventTracerFix__private_featureState & 2) != 0) {
    uVar1 = Feature_CimfsStackEventTracerFix__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_CimfsStackEventTracerFix__private_featureState;
      if (bVar3) {
        Feature_CimfsStackEventTracerFix__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_CimfsStackEventTracerFix__private_featureState;
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



===== wil_details_IsEnabledFallback @ 14000f4cc =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_CimfsStackEventTracerFix__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_CimfsStackEventTracerFix__private_featureState,
                             (ulonglong)param_1,0x1400165e8);
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



===== __GSHandlerCheck @ 14000f568 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000f58c =====

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



===== __security_check_cookie @ 14000f600 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 14000f640 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 14000f670 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014000f670. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 14000f6a0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 14000f700 =====

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



===== memset @ 14000fa00 =====

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



===== __memset_repmovs @ 14000fb40 =====

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



===== __memset_query @ 14000fbc0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 14000fc40 =====

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



===== __memset_spec_ermsb_repmovsb @ 14000fd80 =====

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



===== __memset_spec_plain @ 14000fe00 =====

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



===== memcmp @ 14000ff20 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_14000ff63;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_14000ffd4;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_14000ffd0:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000ffd4;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_14000ffcc:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000ffd0;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14000ffcc;
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
LAB_14000ffd4:
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
LAB_14000ff63:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== `dynamic_atexit_destructor_for_'g_SourceCims'' @ 14000fff0 =====

void _dynamic_atexit_destructor_for__g_SourceCims__(void)

{
  BUCL::CVector<Windows::Auto<_UNICODE_STRING>,BUCL::Rtl::CCallDisposition>::
  ~CVector<Windows::Auto<_UNICODE_STRING>,BUCL::Rtl::CCallDisposition>(&g_SourceCims);
  return;
}



===== `dynamic_initializer_for_'g_CompositeFsLayers'' @ 14001a010 =====

void _dynamic_initializer_for__g_CompositeFsLayers__(void)

{
  atexit(_dynamic_atexit_destructor_for__g_CompositeFsLayers__);
  return;
}



===== `dynamic_atexit_destructor_for_'g_CompositeFsLayers'' @ 14001a030 =====

void _dynamic_atexit_destructor_for__g_CompositeFsLayers__(void)

{
  if (DAT_140017270 != (_RefCountBase *)0x0) {
    utl::_RefCountBase::_DecStrong(DAT_140017270);
  }
  return;
}



===== CompositefsWaitForBootInformation @ 14001a054 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl CompositefsWaitForBootInformation(void) */

long __cdecl CompositefsWaitForBootInformation(void)

{
  longlong lVar1;
  uint uVar2;
  longlong *plVar3;
  atomic<utl::shared_ptr<utl::vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_>_>_>
  *in_RCX;
  _KEVENT *this;
  undefined1 auStack_68 [32];
  undefined8 *local_48;
  undefined1 local_38 [8];
  _RefCountBase *local_30;
  undefined8 local_28;
  _RefCountBase *local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  plVar3 = (longlong *)
           utl::
           atomic<utl::shared_ptr<utl::vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_>_>_>
           ::load(in_RCX,(memory_order)&local_28);
  lVar1 = *plVar3;
  if (local_20 != (_RefCountBase *)0x0) {
    utl::_RefCountBase::_DecStrong(local_20);
  }
  if (lVar1 == 0) {
    local_48 = &local_28;
    local_28 = 0xfffffffffd050f80;
    this = &g_Event;
    KeWaitForSingleObject(&g_Event,0,0,0);
    plVar3 = (longlong *)
             utl::
             atomic<utl::shared_ptr<utl::vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_>_>_>
             ::load((atomic<utl::shared_ptr<utl::vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_>_>_>
                     *)this,(memory_order)local_38);
    lVar1 = *plVar3;
    if (local_30 != (_RefCountBase *)0x0) {
      utl::_RefCountBase::_DecStrong(local_30);
    }
    uVar2 = ~-(uint)(lVar1 != 0) & 0xc0000189;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



===== CimfsMountBootVolume @ 14001a100 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long CimfsMountBootVolume(longlong param_1,_UNICODE_STRING *param_2)

{
  longlong lVar1;
  long lVar2;
  ulong uVar3;
  _UNICODE_STRING *p_Var4;
  undefined1 auStackY_78 [32];
  char local_48 [16];
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined8 local_28;
  ulonglong local_20;
  ulonglong local_18;
  
                    /* 0x1a100  1  CimfsMountBootVolume */
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  if (g_BootVolumeCreated == (atomic<bool>)0x0) {
    p_Var4 = param_2;
    SetErrorLogger();
    local_38 = *(undefined4 *)p_Var4;
    uStack_34 = *(undefined4 *)(p_Var4 + 4);
    uStack_30 = *(undefined4 *)(p_Var4 + 8);
    uStack_2c = *(undefined4 *)(p_Var4 + 0xc);
    local_48[0] = '\0';
    lVar2 = CheckFilterLoad(&local_38,local_48);
    if (lVar2 < 0) {
      return lVar2;
    }
    if ((local_48[0] != '\0') && (g_BootVolumeCreated == (atomic<bool>)0x0)) {
      if (_g_Status < 0) {
        return _g_Status;
      }
      return -0x3ffffff2;
    }
    lVar1 = *(longlong *)(param_1 + 0xf0);
    local_20 = (ulonglong)*(uint *)(lVar1 + 0xf00);
    local_28 = *(undefined8 *)(lVar1 + 0xef8);
    uVar3 = DetermineMountFlags(*(char **)(param_1 + 0xb8));
    lVar2 = MountMergedCim(uVar3,(_GUID *)(lVar1 + 0xee8),param_2,
                           (Vector<_UNICODE_STRING_const_> *)&local_28,(void *)0x0,(void *)0x0);
    if (lVar2 < 0) {
      return lVar2;
    }
    _g_LoaderBlock = 0;
    lVar2 = StoreSourceCims((Vector<_UNICODE_STRING_const_> *)&local_28);
    if (lVar2 < 0) {
      return lVar2;
    }
    g_BootVolumeCreated = (atomic<bool>)0x1;
  }
  return 0;
}



===== CimfsMountBootVolume2 @ 14001a230 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014001a3de) */
/* WARNING: Removing unreachable block (ram,0x00014001a431) */
/* WARNING: Removing unreachable block (ram,0x00014001a451) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long CimfsMountBootVolume2(_UNICODE_STRING *param_1,void *param_2,void *param_3)

{
  undefined4 uVar1;
  long lVar2;
  uint uVar3;
  bool bVar4;
  undefined1 auStackY_158 [32];
  undefined8 local_118;
  undefined8 uStack_110;
  undefined4 local_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined8 local_e8;
  undefined8 uStack_e0;
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
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 local_58;
  ulonglong local_40;
  
                    /* 0x1a230  2  CimfsMountBootVolume2 */
  local_40 = __security_cookie ^ (ulonglong)auStackY_158;
  if (g_BootVolumeCreated == (atomic<bool>)0x0) {
    SetErrorLogger();
    if (_g_LoaderBlock == 0) {
      local_58 = 0xfffffffffd050f80;
      KeWaitForSingleObject(&g_Event,0,0,0);
      if (_g_LoaderBlock == 0) {
        return -0x3ffffe77;
      }
    }
    uVar3 = 0;
    while( true ) {
      uVar1 = _g_MbrSignature;
      LOCK();
      bVar4 = DAT_140017230 == '\0';
      if (bVar4) {
        DAT_140017230 = '\x01';
      }
      UNLOCK();
      if (bVar4) break;
      if (0x1f < uVar3) {
        NtYieldExecution();
      }
      uVar3 = uVar3 + 1;
    }
    uVar3 = 0;
    local_e8 = _g_PartitionInformation;
    uStack_e0 = uRam00000001400171a8;
    local_d8 = _DAT_1400171b0;
    uStack_d0 = uRam00000001400171b8;
    local_c8 = _DAT_1400171c0;
    uStack_c0 = uRam00000001400171c8;
    local_b8 = _DAT_1400171d0;
    uStack_b0 = uRam00000001400171d8;
    local_a8 = _DAT_1400171e0;
    uStack_a0 = uRam00000001400171e8;
    local_98 = _DAT_1400171f0;
    uStack_90 = uRam00000001400171f8;
    local_88 = _DAT_140017200;
    uStack_80 = uRam0000000140017208;
    uStack_78 = _DAT_140017210;
    uStack_70 = uRam0000000140017218;
    uStack_68 = _DAT_140017220;
    uStack_60 = uRam0000000140017228;
    DAT_140017230 = '\0';
    while( true ) {
      LOCK();
      bVar4 = DAT_140017198 == '\0';
      if (bVar4) {
        DAT_140017198 = '\x01';
      }
      UNLOCK();
      if (bVar4) break;
      if (0x1f < uVar3) {
        NtYieldExecution();
      }
      uVar3 = uVar3 + 1;
    }
    DAT_140017198 = '\0';
    local_118 = _g_GptDiskId;
    uStack_110 = uRam0000000140017190;
    local_108 = *(undefined4 *)param_1;
    uStack_104 = *(undefined4 *)(param_1 + 4);
    uStack_100 = *(undefined4 *)(param_1 + 8);
    uStack_fc = *(undefined4 *)(param_1 + 0xc);
    lVar2 = CompareDiskInfo(&local_108,&local_118,uVar1,&local_e8);
    if (lVar2 < 0) {
      _g_Status = lVar2;
      return lVar2;
    }
  }
  return 0;
}



===== CimfsSetBootInformation @ 14001a490 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
CimfsSetBootInformation
          (atomic<_PARTITION_INFORMATION_EX> *param_1,undefined8 *param_2,undefined8 *param_3,
          undefined4 param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined8 *puVar5;
  bool bVar6;
  undefined8 local_2e8;
  undefined8 uStack_2e0;
  undefined8 local_2d8;
  undefined8 uStack_2d0;
  undefined8 local_2c8;
  undefined8 uStack_2c0;
  undefined8 local_2b8;
  undefined8 uStack_2b0;
  undefined8 local_2a8;
  undefined8 uStack_2a0;
  undefined8 local_298;
  undefined8 uStack_290;
  undefined8 local_288;
  undefined8 uStack_280;
  undefined4 uStack_278;
  undefined4 uStack_274;
  undefined4 uStack_270;
  undefined4 uStack_26c;
  undefined4 uStack_268;
  undefined4 uStack_264;
  undefined4 uStack_260;
  undefined4 uStack_25c;
  undefined8 local_258;
  undefined8 uStack_250;
  undefined8 local_248;
  undefined8 uStack_240;
  undefined8 local_238;
  undefined8 uStack_230;
  undefined8 local_228;
  undefined8 uStack_220;
  undefined8 local_218;
  undefined8 uStack_210;
  undefined8 local_208;
  undefined8 uStack_200;
  undefined8 local_1f8;
  undefined8 uStack_1f0;
  undefined4 local_1e8;
  undefined4 uStack_1e4;
  undefined4 uStack_1e0;
  undefined4 uStack_1dc;
  undefined4 uStack_1d8;
  undefined4 uStack_1d4;
  undefined4 uStack_1d0;
  undefined4 uStack_1cc;
  undefined8 local_1c8;
  undefined8 uStack_1c0;
  undefined8 local_1b8;
  undefined8 uStack_1b0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined1 local_138 [144];
  undefined1 local_a8 [160];
  
                    /* 0x1a490  3  CimfsSetBootInformation */
  _g_LoaderBlock = param_1;
  if (param_2 == (undefined8 *)0x0) {
    memset(&local_258,0,0x90);
    param_1 = (atomic<_PARTITION_INFORMATION_EX> *)&local_1c8;
    puVar3 = local_a8;
    local_1c8 = local_258;
    uStack_1c0 = uStack_250;
    local_1b8 = local_248;
    uStack_1b0 = uStack_240;
    local_1a8 = local_238;
    uStack_1a0 = uStack_230;
    local_198 = local_228;
    uStack_190 = uStack_220;
    local_188 = local_218;
    uStack_180 = uStack_210;
    local_178 = local_208;
    uStack_170 = uStack_200;
    local_168 = local_1f8;
    uStack_160 = uStack_1f0;
    uStack_158 = local_1e8;
    uStack_154 = uStack_1e4;
    uStack_150 = uStack_1e0;
    uStack_14c = uStack_1dc;
    uStack_148 = uStack_1d8;
    uStack_144 = uStack_1d4;
    uStack_140 = uStack_1d0;
    uStack_13c = uStack_1cc;
    puVar5 = &local_1c8;
  }
  else {
    local_2e8 = *param_2;
    uStack_2e0 = param_2[1];
    local_2d8 = param_2[2];
    uStack_2d0 = param_2[3];
    local_2c8 = param_2[4];
    uStack_2c0 = param_2[5];
    local_2b8 = param_2[6];
    uStack_2b0 = param_2[7];
    local_2a8 = param_2[8];
    uStack_2a0 = param_2[9];
    local_298 = param_2[10];
    uStack_290 = param_2[0xb];
    local_288 = param_2[0xc];
    uStack_280 = param_2[0xd];
    uStack_268 = *(undefined4 *)(param_2 + 0x10);
    uStack_264 = *(undefined4 *)((longlong)param_2 + 0x84);
    uStack_260 = *(undefined4 *)(param_2 + 0x11);
    uStack_25c = *(undefined4 *)((longlong)param_2 + 0x8c);
    uStack_278 = *(undefined4 *)(param_2 + 0xe);
    uStack_274 = *(undefined4 *)((longlong)param_2 + 0x74);
    uStack_270 = *(undefined4 *)(param_2 + 0xf);
    uStack_26c = *(undefined4 *)((longlong)param_2 + 0x7c);
    puVar3 = local_138;
    puVar5 = &local_2e8;
  }
  utl::atomic<_PARTITION_INFORMATION_EX>::operator=(param_1,puVar3,puVar5);
  uVar4 = 0;
  if (param_3 == (undefined8 *)0x0) {
    while( true ) {
      LOCK();
      bVar6 = DAT_140017198 == '\0';
      if (bVar6) {
        DAT_140017198 = '\x01';
      }
      UNLOCK();
      if (bVar6) break;
      if (0x1f < uVar4) {
        NtYieldExecution();
      }
      uVar4 = uVar4 + 1;
    }
    _g_GptDiskId = 0;
    uRam0000000140017190 = 0;
  }
  else {
    uVar1 = *param_3;
    uVar2 = param_3[1];
    while( true ) {
      LOCK();
      bVar6 = DAT_140017198 == '\0';
      if (bVar6) {
        DAT_140017198 = '\x01';
      }
      UNLOCK();
      if (bVar6) break;
      if (0x1f < uVar4) {
        NtYieldExecution();
      }
      uVar4 = uVar4 + 1;
    }
    _g_GptDiskId = uVar1;
    uRam0000000140017190 = uVar2;
  }
  DAT_140017198 = 0;
  _g_MbrSignature = param_4;
  KeSetEvent(&g_Event,0,0);
  return 0;
}



===== CompositefsFreeBootLayers @ 14001a670 =====

void CompositefsFreeBootLayers(_UNICODE_STRING *param_1,ulong param_2)

{
                    /* 0x1a670  4  CompositefsFreeBootLayers */
  Compositefs::FreeBootLayers(param_1,param_2);
  return;
}



===== CompositefsGetBootLayers @ 14001a690 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long CompositefsGetBootLayers(_UNICODE_STRING *param_1,ulong *param_2)

{
  long lVar1;
  
                    /* 0x1a690  5  CompositefsGetBootLayers */
  lVar1 = CompositefsWaitForBootInformation();
  if ((lVar1 < 0) || (lVar1 = Compositefs::GetBootLayers(param_1,param_2), lVar1 < 0)) {
    _g_Status = lVar1;
    return lVar1;
  }
  return 0;
}



===== CompositefsMountBootLayers @ 14001a6e0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long CompositefsMountBootLayers
               (atomic<utl::shared_ptr<utl::vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_>_>_>
                *param_1,void *param_2)

{
  _RefCountBase *this;
  long lVar1;
  undefined8 *puVar2;
  undefined1 local_18 [8];
  _RefCountBase *local_10;
  
                    /* 0x1a6e0  6  CompositefsMountBootLayers */
  lVar1 = CompositefsWaitForBootInformation();
  if ((lVar1 < 0) || (lVar1 = Compositefs::MountBootLayers(param_1,param_2), lVar1 < 0)) {
    _g_Status = lVar1;
    return lVar1;
  }
  puVar2 = (undefined8 *)
           utl::
           atomic<utl::shared_ptr<utl::vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_>_>_>
           ::load(param_1,(memory_order)local_18);
  this = (_RefCountBase *)puVar2[1];
  puVar2[1] = 0;
  *puVar2 = 0;
  if (this != (_RefCountBase *)0x0) {
    utl::_RefCountBase::_DecStrong(this);
  }
  if (local_10 != (_RefCountBase *)0x0) {
    utl::_RefCountBase::_DecStrong(local_10);
  }
  return 0;
}



===== CompositefsSetBootInformation @ 14001a760 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014001a817) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 CompositefsSetBootInformation(longlong param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined4 uVar5;
  Vector<Compositefs::Layer> *pVVar6;
  undefined8 *puVar7;
  _RefCountBase *this;
  longlong *plVar8;
  _RefCountBase *p_Var9;
  undefined4 *puVar10;
  uint uVar11;
  ulonglong uVar12;
  bool bVar13;
  undefined1 auStack_a8 [32];
  undefined1 local_88 [8];
  _RefCountBase *local_80;
  Layer local_78 [16];
  vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_> local_68 [16];
  __uint64 local_58;
  __uint64 _Stack_50;
  undefined8 local_48;
  undefined8 *local_40;
  longlong local_38;
  ulonglong local_20;
  
                    /* 0x1a760  7  CompositefsSetBootInformation */
  local_20 = __security_cookie ^ (ulonglong)auStack_a8;
  local_48 = 0xffffffffffffffff;
  local_58 = 0xffffffffffffffff;
  _Stack_50 = 0xffffffffffffffff;
  uVar12 = (ulonglong)*(uint *)(*(longlong *)(param_1 + 0xf0) + 0xf70);
  if (uVar12 == 0) {
    _Stack_50 = -1;
  }
  else {
    bVar13 = utl::vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_>::_GrowMinimum
                       ((vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_> *)&local_58,
                        uVar12);
    if ((!bVar13) || (bVar13 = utl::_RangeFillApc<utl::allocator<Compositefs::Layer>_>(), !bVar13))
    goto code_r0x00014001a9b7;
    _Stack_50 = uVar12 * 0x38 + local_58;
  }
  TMeta::Enumerate<utl::vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_>&___ptr64>
            ((vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_> *)&local_40,
             (__uint64)&local_58);
  puVar1 = (undefined4 *)local_40[1];
  for (puVar10 = (undefined4 *)*local_40; puVar10 != puVar1; puVar10 = puVar10 + 0xe) {
    piVar2 = *(int **)(*(longlong *)(*(longlong *)(param_1 + 0xf0) + 0xf68) + local_38 * 8);
    if (*piVar2 == 0) {
      *puVar10 = 2;
      *(undefined8 *)(puVar10 + 2) = *(undefined8 *)(piVar2 + 2);
    }
    else {
      if (*piVar2 != 0xb) {
        _g_Status = 0xc000000d;
        goto code_r0x00014001a9c4;
      }
      *puVar10 = 1;
      uVar3 = *(undefined8 *)(piVar2 + 4);
      *(undefined8 *)(puVar10 + 2) = *(undefined8 *)(piVar2 + 2);
      *(undefined8 *)(puVar10 + 4) = uVar3;
      *(undefined8 *)(puVar10 + 6) = *(undefined8 *)(piVar2 + 6);
      puVar10[8] = piVar2[8];
      puVar10[9] = piVar2[9];
      *(char *)(puVar10 + 10) = (char)piVar2[10];
      *(undefined8 *)(puVar10 + 0xc) = *(undefined8 *)(piVar2 + 0xc);
    }
    local_38 = local_38 + 1;
  }
  pVVar6 = (Vector<Compositefs::Layer> *)Windows::MakeVector<Compositefs::Layer>(local_78,local_58);
  Compositefs::SetBootInformation(pVVar6);
  puVar7 = (undefined8 *)
           utl::
           make_shared<utl::vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_>,utl::vector<struct_Compositefs::Layer,class_utl::allocator<struct_Compositefs::Layer>_>_>
                     (local_68);
  uVar3 = *puVar7;
  p_Var9 = (_RefCountBase *)puVar7[1];
  *puVar7 = 0;
  puVar7[1] = 0;
  uVar11 = 0;
  this = DAT_140017270;
  do {
    LOCK();
    bVar13 = this == DAT_140017270;
    if (bVar13) {
      DAT_140017270 = (_RefCountBase *)((ulonglong)this | 1);
    }
    else {
      this = DAT_140017270;
    }
    UNLOCK();
  } while (!bVar13);
  while (((ulonglong)this & 7) != 0) {
    if (0x1f < uVar11) {
      NtYieldExecution();
    }
    uVar11 = uVar11 + 1;
    this = DAT_140017270;
    do {
      LOCK();
      bVar13 = this == DAT_140017270;
      if (bVar13) {
        DAT_140017270 = (_RefCountBase *)((ulonglong)this | 1);
      }
      else {
        this = DAT_140017270;
      }
      UNLOCK();
    } while (!bVar13);
  }
  _g_CompositeFsLayers = uVar3;
  DAT_140017270 = p_Var9;
  if (this != (_RefCountBase *)0x0) {
    utl::_RefCountBase::_DecStrong(this);
  }
  p_Var9 = (_RefCountBase *)puVar7[1];
  if (p_Var9 != (_RefCountBase *)0x0) {
    utl::_RefCountBase::_DecStrong(p_Var9);
  }
  plVar8 = (longlong *)
           utl::
           atomic<utl::shared_ptr<utl::vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_>_>_>
           ::load((atomic<utl::shared_ptr<utl::vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_>_>_>
                   *)p_Var9,(memory_order)local_88);
  lVar4 = *plVar8;
  if (local_80 != (_RefCountBase *)0x0) {
    utl::_RefCountBase::_DecStrong(local_80);
  }
  if (lVar4 != 0) {
    KeSetEvent(&g_Event,0,0);
    if (local_58 != 0xffffffffffffffff) {
      _Stack_50 = local_58;
      utl::
      _RefCountVtable<utl::_RefCountStored<utl::vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_>,utl::allocator<int>,0>,0>
      ::_FreeRefCount();
    }
    return 0;
  }
code_r0x00014001a9b7:
  _g_Status = 0xc0000017;
code_r0x00014001a9c4:
  uVar5 = _g_Status;
  if (local_58 != 0xffffffffffffffff) {
    _Stack_50 = local_58;
    utl::
    _RefCountVtable<utl::_RefCountStored<utl::vector<Compositefs::Layer,utl::allocator<Compositefs::Layer>_>,utl::allocator<int>,0>,0>
    ::_FreeRefCount();
  }
  return uVar5;
}



===== Cp_DllInitialize @ 14001aa0c =====

undefined8 Cp_DllInitialize(void)

{
  KeInitializeEvent(&g_Event,0,0);
  return 0;
}



===== Cp_DllUnload @ 14001aa38 =====

undefined8 Cp_DllUnload(void)

{
  return 0;
}



===== NtYieldExecution @ 14001aa50 =====

void NtYieldExecution(void)

{
                    /* 0x1aa50  11  NtYieldExecution */
  Ordinal_6(0);
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 14001aa70 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  uint uVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  bool bVar5;
  
  puVar4 = (undefined *)0x0;
  ppuVar3 = &wil_details_featureDescriptors_a;
  ppuVar2 = &wil_details_featureDescriptors_a;
  do {
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x00014001aaab;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_14001ab25:
  while( true ) {
    if (&UNK_1400167a7 < ppuVar3) {
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
      if (&UNK_1400167a7 < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x00014001aaab:
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
      if (&UNK_1400167a7 < ppuVar2) goto LAB_14001ab25;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_14001ab25;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14001ab60 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_14001abfc;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_14001abfc;
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
LAB_14001abfc:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14001ac60 =====

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
      for (ppuVar2 = &wil_details_featureDescriptors_a; ppuVar2 < &wil_details_featureDescriptors_z;
          ppuVar2 = ppuVar2 + 1) {
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
              if (&UNK_1400167a7 < ppuVar2) {
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



===== wil_details_RecordFeatureUsageCallback @ 14001ace0 =====

void wil_details_RecordFeatureUsageCallback(void)

{
  RtlRecordFeatureUsage();
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14001ad00 =====

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
  for (ppuVar3 = &wil_details_featureDescriptors_a; ppuVar3 < &wil_details_featureDescriptors_z;
      ppuVar3 = ppuVar3 + 1) {
    if (*ppuVar3 != (undefined *)0x0) goto LAB_14001adfd;
  }
LAB_14001ae06:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14001adfd:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14001ae06;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14001adce:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14001adce;
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
    if (&UNK_1400167a7 < ppuVar3) goto LAB_14001ae06;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14001adfd;
}



===== RtlAllocateLUnicodeString @ 14001ae2c =====

undefined8 RtlAllocateLUnicodeString(__uint64 param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  void *pvVar2;
  undefined8 *puVar3;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  if ((param_1 & 1) == 0) {
    if (param_1 != 0) {
      puVar3 = param_2;
      pvVar2 = LstringKmAllocateString(param_1);
      param_2[2] = pvVar2;
      if (pvVar2 == (void *)0x0) {
        local_18 = 0x62;
        local_28 = "onecore\\base\\lstring\\lunicode_string.cpp";
        local_20 = "RtlAllocateLUnicodeString";
        local_10 = "String->Buffer = reinterpret_cast<PWSTR>((*RtlAllocateStringRoutine)(Bytes))";
        RtlReportErrorOrigination(&local_28,puVar3,-0x3fffffe9);
        return 0xc0000017;
      }
      param_2[1] = param_1;
    }
    uVar1 = 0;
  }
  else {
    local_18 = 0x5e;
    local_28 = "onecore\\base\\lstring\\lunicode_string.cpp";
    local_20 = "RtlAllocateLUnicodeString";
    local_10 = "(Bytes % sizeof(WCHAR)) == 0";
    RtlReportErrorOrigination(&local_28,param_2,-0x3ffffff3);
    uVar1 = 0xc000000d;
  }
  return uVar1;
}



===== RtlCompareLUnicodeStrings @ 14001af08 =====

void RtlCompareLUnicodeStrings
               (longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 in_stack_ffffffffffffffe8;
  
  RtlCompareEncodedLBlobs
            (param_1,param_2,(longlong *)param_2,param_4,in_stack_ffffffffffffffe8,
             (undefined4 *)param_4);
  return;
}



===== RtlDeallocateUnicodeString @ 14001af28 =====

void RtlDeallocateUnicodeString(longlong param_1)

{
  if ((param_1 != 0) && (*(void **)(param_1 + 8) != (void *)0x0)) {
    LstringKmFreeString(*(void **)(param_1 + 8));
  }
  return;
}



===== RtlDuplicateLUnicodeString @ 14001af4c =====

undefined8 RtlDuplicateLUnicodeString(ulonglong *param_1,__uint64 *param_2)

{
  __uint64 _Size;
  char cVar1;
  undefined8 uVar2;
  ulonglong *puVar3;
  __uint64 *p_Var4;
  char *local_38;
  char *local_30;
  undefined8 local_28;
  char *local_20;
  
  if (param_2 == (__uint64 *)0x0) {
    local_28 = 0xa4;
    local_20 = "Not-null check failed: Destination";
  }
  else {
    param_2[2] = 0;
    *param_2 = 0;
    param_2[1] = 0;
    puVar3 = param_1;
    p_Var4 = param_2;
    cVar1 = RtlIsLUnicodeStringValid(param_1);
    if (cVar1 != '\0') {
      _Size = *puVar3;
      if (_Size != 0) {
        uVar2 = RtlAllocateLUnicodeString(_Size,param_2);
        if ((int)uVar2 < 0) {
          return uVar2;
        }
        memmove((void *)param_2[2],(void *)param_1[2],_Size);
        *param_2 = _Size;
      }
      return 0;
    }
    local_28 = 0xa5;
    local_20 = "RtlIsLUnicodeStringValid(Source)";
    param_2 = p_Var4;
  }
  local_30 = "RtlDuplicateLUnicodeString";
  local_38 = "onecore\\base\\lstring\\lunicode_string.cpp";
  RtlReportErrorOrigination(&local_38,param_2,-0x3ffffff3);
  return 0xc000000d;
}



===== RtlFreeLUnicodeString @ 14001b024 =====

void RtlFreeLUnicodeString(longlong param_1)

{
  if ((param_1 != 0) && (*(void **)(param_1 + 0x10) != (void *)0x0)) {
    LstringKmFreeString(*(void **)(param_1 + 0x10));
  }
  return;
}



===== RtlInitUnicodeStringFromLUnicodeString @ 14001b048 =====

uint RtlInitUnicodeStringFromLUnicodeString(ulonglong *param_1,undefined4 *param_2)

{
  ulonglong uVar1;
  char cVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  undefined4 *puVar6;
  ulonglong *puVar7;
  char *local_38;
  char *local_30;
  undefined8 local_28;
  char *local_20;
  
  uVar4 = 0;
  *param_2 = 0;
  *(undefined8 *)(param_2 + 2) = 0;
  puVar6 = param_2;
  puVar7 = param_1;
  cVar2 = RtlIsLUnicodeStringValid(param_1);
  if (cVar2 == '\0') {
    local_28 = 0x165;
    local_38 = "onecore\\base\\lstring\\lunicode_string.cpp";
    local_30 = "RtlInitUnicodeStringFromLUnicodeString";
    local_20 = "::RtlIsLUnicodeStringValid(Source)";
    RtlReportErrorOrigination(&local_38,param_2,-0x3ffffff3);
    uVar5 = 0xc000000d;
  }
  else {
    uVar1 = *param_1;
    uVar4 = uVar4 & 0xffff;
    uVar3 = 0;
    if (uVar1 < 0x10000) {
      uVar4 = uVar1 & 0xffff;
      uVar5 = -(uint)(uVar1 != uVar4) & 0xc00000e5;
    }
    else {
      uVar5 = 0xc0000095;
    }
    if ((int)uVar5 < 0) {
      local_28 = 0x16b;
      local_38 = "onecore\\base\\lstring\\lunicode_string.cpp";
      local_30 = "RtlInitUnicodeStringFromLUnicodeString";
      local_20 = "BUCL::Rtl::ConvertInteger(Source->Length, Length)";
      RtlReportErrorOrigination(&local_38,uVar4,uVar5);
    }
    else {
      uVar1 = puVar7[1];
      uVar5 = 0xc0000095;
      if (uVar1 < 0x10000) {
        uVar3 = uVar1 & 0xffff;
        uVar5 = -(uint)(uVar1 != uVar3) & 0xc00000e5;
      }
      if ((int)uVar5 < 0) {
        local_28 = 0x16d;
        local_38 = "onecore\\base\\lstring\\lunicode_string.cpp";
        local_30 = "RtlInitUnicodeStringFromLUnicodeString";
        local_20 = "BUCL::Rtl::ConvertInteger(Source->MaximumLength, MaximumLength)";
        RtlReportErrorOrigination(&local_38,uVar4,uVar5);
      }
      else {
        *(short *)puVar6 = (short)uVar4;
        *(short *)((longlong)puVar6 + 2) = (short)uVar3;
        *(ulonglong *)(puVar6 + 2) = puVar7[2];
        uVar5 = 0;
      }
    }
  }
  return uVar5;
}



===== RtlIsLUnicodeStringValid @ 14001b1a4 =====

undefined1 RtlIsLUnicodeStringValid(ulonglong *param_1)

{
  ulonglong uVar1;
  
  if ((((param_1 != (ulonglong *)0x0) && (uVar1 = *param_1, (uVar1 & 1) == 0)) &&
      ((param_1[1] & 1) == 0)) && (uVar1 <= param_1[1])) {
    if (param_1[2] != 0) {
      return 1;
    }
    if (uVar1 == 0) {
      return 1;
    }
  }
  return 0;
}



===== RtlIsUnicodeStringValid @ 14001b1d8 =====

undefined1 RtlIsUnicodeStringValid(ushort *param_1)

{
  ushort uVar1;
  
  if ((((param_1 != (ushort *)0x0) && (uVar1 = *param_1, (uVar1 & 1) == 0)) &&
      ((param_1[1] & 1) == 0)) && (uVar1 <= param_1[1])) {
    if (*(longlong *)(param_1 + 4) != 0) {
      return 1;
    }
    if (uVar1 == 0) {
      return 1;
    }
  }
  return 0;
}



===== RtlReallocateLUnicodeString @ 14001b210 =====

int RtlReallocateLUnicodeString(undefined8 param_1,ulonglong param_2,ulonglong *param_3)

{
  char cVar1;
  undefined8 uVar2;
  int iVar3;
  ulonglong *puVar4;
  ulonglong uVar5;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  if (param_3 == (ulonglong *)0x0) {
    local_18 = 0x4f7;
    local_10 = "Not-null check failed: String";
  }
  else if ((param_2 & 1) == 0) {
    puVar4 = param_3;
    uVar5 = param_2;
    cVar1 = RtlIsLUnicodeStringValid(param_3);
    if (cVar1 != '\0') {
      uVar2 = RtlReallocateLBlob(param_3,uVar5,puVar4);
      iVar3 = 0;
      if ((int)uVar2 < 0) {
        iVar3 = (int)uVar2;
      }
      return iVar3;
    }
    local_18 = 0x4f9;
    local_10 = "::RtlIsLUnicodeStringValid(String)";
  }
  else {
    local_18 = 0x4f8;
    local_10 = "(Bytes % sizeof(WCHAR)) == 0";
  }
  local_20 = "RtlReallocateLUnicodeString";
  local_28 = "onecore\\base\\lstring\\lunicode_string.cpp";
  RtlReportErrorOrigination(&local_28,param_2,-0x3ffffff3);
  return -0x3ffffff3;
}



===== RtlReallocateUnicodeString @ 14001b2f0 =====

uint RtlReallocateUnicodeString(undefined8 param_1,ulonglong param_2,ushort *param_3)

{
  char cVar1;
  void *_Dst;
  uint uVar2;
  ushort uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  char *local_48;
  char *local_40;
  undefined8 local_38;
  char *local_30;
  
  if (param_3 == (ushort *)0x0) {
    local_38 = 0x4cf;
    local_30 = "Not-null check failed: String";
  }
  else {
    uVar5 = param_2;
    cVar1 = RtlIsUnicodeStringValid(param_3);
    if (cVar1 != '\0') {
      uVar4 = 0;
      if (uVar5 < 0x10000) {
        uVar4 = uVar5 & 0xffff;
        uVar2 = -(uint)(uVar5 != uVar4) & 0xc00000e5;
      }
      else {
        uVar2 = 0xc0000095;
      }
      if ((int)uVar2 < 0) {
        local_38 = 0x4d2;
        local_48 = "onecore\\base\\lstring\\lunicode_string.cpp";
        local_40 = "RtlReallocateUnicodeString";
        local_30 = "BUCL::Rtl::ConvertInteger(Bytes, NewLength)";
        RtlReportErrorOrigination(&local_48,param_2,uVar2);
        return uVar2;
      }
      if (*(longlong *)(param_3 + 4) == 0) {
        _Dst = LstringKmAllocateString(uVar5);
        if (_Dst != (void *)0x0) goto LAB_14001b463;
        local_38 = 0x4e0;
      }
      else {
        _Dst = LstringKmAllocateString(uVar5);
        if (_Dst != (void *)0x0) {
          memmove(_Dst,*(void **)(param_3 + 4),(ulonglong)*param_3);
          LstringKmFreeString(*(void **)(param_3 + 4));
LAB_14001b463:
          *(void **)(param_3 + 4) = _Dst;
          uVar3 = (ushort)uVar4;
          param_3[1] = uVar3;
          if (uVar3 < *param_3) {
            *param_3 = uVar3;
          }
          return 0;
        }
        local_38 = 0x4d7;
      }
      local_48 = "onecore\\base\\lstring\\lunicode_string.cpp";
      local_40 = "RtlReallocateUnicodeString";
      local_30 = "NewBuffer = (*RtlAllocateStringRoutine)(Bytes)";
      RtlReportErrorOrigination(&local_48,param_2,-0x3fffffe9);
      return 0xc0000017;
    }
    local_38 = 0x4d0;
    local_30 = "::RtlIsUnicodeStringValid(String)";
  }
  local_40 = "RtlReallocateUnicodeString";
  local_48 = "onecore\\base\\lstring\\lunicode_string.cpp";
  RtlReportErrorOrigination(&local_48,param_2,-0x3ffffff3);
  return 0xc000000d;
}



===== RtlRegisterErrorOriginationCallback @ 14001b4ac =====

undefined8 RtlRegisterErrorOriginationCallback(void)

{
  undefined8 uVar1;
  
  uVar1 = DAT_140017290;
  LOCK();
  DAT_140017290 = TraceErrorOrigination;
  UNLOCK();
  return uVar1;
}



===== RtlReportErrorOrigination @ 14001b4c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RtlReportErrorOrigination(undefined8 *param_1,undefined8 param_2,int param_3)

{
  code *pcVar1;
  char *pcVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  if (param_3 == g_NTSTATUS_to_break_on) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  uVar3 = 0;
  if (DAT_140017290 != (code *)0x0) {
    (*DAT_140017290)(param_1,&_GUID_44edceb3_7a6e_47e9_b787_5aa9dadfa4ab);
  }
  if (param_3 != -0x3fffff1b) {
    return;
  }
  if (param_1 == (undefined8 *)0x0) {
    pcVar4 = "";
    pcVar2 = "";
  }
  else {
    uVar3 = *(undefined4 *)(param_1 + 2);
    pcVar2 = (char *)*param_1;
    pcVar4 = (char *)param_1[3];
  }
  DbgPrintEx(0x65,0,"\n*** Assertion failed: %s\n***   Source File: %s, line %ld\n\n",pcVar4,pcVar2,
             uVar3);
                    /* WARNING: Subroutine does not return */
  RtlRaiseStatus(0xc0000420);
}



===== RtlAllocateLBlob @ 14001b55c =====

undefined8 RtlAllocateLBlob(__uint64 param_1,undefined8 *param_2)

{
  void *pvVar1;
  undefined8 *puVar2;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  if (param_1 != 0) {
    puVar2 = param_2;
    pvVar1 = LstringKmAllocateString(param_1);
    param_2[2] = pvVar1;
    if (pvVar1 == (void *)0x0) {
      local_18 = 0x7ba;
      local_28 = "onecore\\base\\lstring\\lblob.cpp";
      local_20 = "RtlAllocateLBlob";
      local_10 = "Blob->Buffer = (PUCHAR)((*RtlAllocateStringRoutine)(Bytes))";
      RtlReportErrorOrigination(&local_28,puVar2,-0x3fffffe9);
      return 0xc0000017;
    }
    param_2[1] = param_1;
  }
  return 0;
}



===== RtlCompareEncodedLBlobs @ 14001b5ec =====

ulonglong RtlCompareEncodedLBlobs
                    (longlong *param_1,undefined8 param_2,longlong *param_3,undefined8 param_4,
                    undefined8 param_5,undefined4 *param_6)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  ushort *puVar5;
  ushort *puVar6;
  undefined4 uVar7;
  ushort *puVar8;
  ushort *puVar9;
  ushort *puVar10;
  ushort *puVar11;
  char *local_88;
  char *local_80;
  undefined8 local_78;
  char *local_70;
  uint local_68;
  uint local_60;
  uint uStack_5c;
  uint uStack_58;
  uint uStack_54;
  uint local_50 [6];
  
  if (param_6 == (undefined4 *)0x0) {
    local_78 = 0x8c4;
    local_70 = "Not-null check failed: ComparisonResult";
LAB_14001b7a0:
    local_80 = "RtlCompareEncodedLBlobs";
    local_88 = "onecore\\base\\lstring\\lblob.cpp";
    RtlReportErrorOrigination(&local_88,param_2,-0x3ffffff3);
    return 0xc000000d;
  }
  *param_6 = 0;
  if (param_1 == (longlong *)0x0) {
    local_78 = 0x8c5;
    local_70 = "Not-null check failed: String1";
    goto LAB_14001b7a0;
  }
  if (param_3 == (longlong *)0x0) {
    local_78 = 0x8c7;
    local_70 = "Not-null check failed: String2";
    goto LAB_14001b7a0;
  }
  puVar5 = (ushort *)param_1[2];
  puVar8 = (ushort *)param_3[2];
  puVar10 = (ushort *)(*param_1 + (longlong)puVar5);
  puVar11 = (ushort *)(*param_3 + (longlong)puVar8);
  puVar6 = puVar8;
  if (puVar5 != puVar10) {
    do {
      puVar8 = puVar6;
      puVar9 = puVar5;
      if (puVar6 == puVar11) break;
      puVar3 = RtlDecodeUtf16LE(local_50,puVar5,puVar10);
      uVar1 = *puVar3;
      uStack_5c = puVar3[1];
      uStack_58 = puVar3[2];
      uStack_54 = puVar3[3];
      puVar9 = *(ushort **)(puVar3 + 2);
      if (uVar1 == 0xffffffff) {
        if (-1 < (int)puVar9) {
LAB_14001b7d1:
          local_60 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
          RtlRaiseStatus(0xc00000e5);
        }
        local_78 = 0x8dc;
LAB_14001b737:
        local_60 = 0xffffffff;
        local_88 = "onecore\\base\\lstring\\lblob.cpp";
        local_80 = "RtlCompareEncodedLBlobs";
        local_70 = "__rv.UcsCharacter != (0xffffffff)";
        RtlReportErrorOrigination(&local_88,puVar5,(int)puVar9);
        return (ulonglong)puVar9 & 0xffffffff;
      }
      local_60 = uVar1;
      puVar4 = RtlDecodeUtf16LE((uint *)&local_88,puVar6,puVar11);
      local_68 = *puVar4;
      uStack_5c = puVar4[1];
      puVar3 = puVar4 + 2;
      uStack_58 = *puVar3;
      uStack_54 = puVar4[3];
      puVar8 = *(ushort **)puVar3;
      if (local_68 == 0xffffffff) {
        if (-1 < (int)*(ushort **)puVar3) goto LAB_14001b7d1;
        local_78 = 0x8dd;
        puVar5 = puVar6;
        puVar9 = *(ushort **)puVar3;
        goto LAB_14001b737;
      }
      local_60 = local_68;
      uVar1 = RtlDowncaseUCSCharacter(uVar1);
      uVar2 = RtlDowncaseUCSCharacter(local_68);
      if (uVar1 < uVar2) {
        uVar7 = 0xffffffff;
        goto LAB_14001b773;
      }
      if (uVar1 != uVar2) goto LAB_14001b705;
      puVar6 = puVar8;
      puVar5 = puVar9;
    } while (puVar9 != puVar10);
    if (puVar9 != puVar10) {
LAB_14001b705:
      uVar7 = 1;
      goto LAB_14001b773;
    }
  }
  uVar7 = 0;
  if (puVar8 != puVar11) {
    uVar7 = 0xffffffff;
  }
LAB_14001b773:
  *param_6 = uVar7;
  return 0;
}



===== RtlIsLBlobValid @ 14001b7e4 =====

ulonglong RtlIsLBlobValid(ulonglong *param_1)

{
  ulonglong in_RAX;
  
  if ((param_1 == (ulonglong *)0x0) || ((param_1[2] == 0 && (*param_1 != 0)))) {
    return in_RAX & 0xffffffffffffff00;
  }
  return CONCAT71((int7)(param_1[1] >> 8),*param_1 <= param_1[1]);
}



===== RtlReallocateLBlob @ 14001b80c =====

undefined8 RtlReallocateLBlob(undefined8 param_1,ulonglong param_2,ulonglong *param_3)

{
  ulonglong uVar1;
  void *_Dst;
  ulonglong uVar2;
  ulonglong *puVar3;
  char *local_38;
  char *local_30;
  undefined8 local_28;
  char *local_20;
  
  uVar2 = param_2;
  if (param_3 == (ulonglong *)0x0) {
    local_28 = 0x81;
    local_20 = "Not-null check failed: Blob";
  }
  else {
    puVar3 = param_3;
    uVar1 = RtlIsLBlobValid(param_3);
    if ((char)uVar1 != '\0') {
      if (puVar3[2] == 0) {
        _Dst = LstringKmAllocateString(param_2);
        if (_Dst == (void *)0x0) {
          local_28 = 0x98;
          local_20 = "Temp = (PUCHAR)((*RtlAllocateStringRoutine)(Bytes))";
          goto LAB_14001b8e1;
        }
      }
      else {
        if (param_2 <= puVar3[1]) {
          return 0;
        }
        _Dst = LstringKmAllocateString(param_2);
        if (_Dst == (void *)0x0) {
          local_28 = 0x8f;
          local_20 = "Temp = (*RtlAllocateStringRoutine)(Bytes)";
LAB_14001b8e1:
          local_30 = "RtlReallocateLBlob";
          local_38 = "onecore\\base\\lstring\\lblob.cpp";
          RtlReportErrorOrigination(&local_38,uVar2,-0x3fffffe9);
          return 0xc0000017;
        }
        memmove(_Dst,(void *)param_3[2],*param_3);
        LstringKmFreeString((void *)param_3[2]);
      }
      param_3[2] = (ulonglong)_Dst;
      param_3[1] = param_2;
      if (param_2 < *param_3) {
        *param_3 = param_2;
      }
      return 0;
    }
    local_28 = 0x82;
    local_20 = "::RtlIsLBlobValid(Blob)";
  }
  local_30 = "RtlReallocateLBlob";
  local_38 = "onecore\\base\\lstring\\lblob.cpp";
  RtlReportErrorOrigination(&local_38,uVar2,-0x3ffffff3);
  return 0xc000000d;
}



===== RtlCombineNtPathSegments @ 14001b974 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong RtlCombineNtPathSegments(ulonglong param_1,longlong param_2,longlong *param_3)

{
  undefined2 *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong *puVar4;
  ulonglong uVar5;
  undefined2 *puVar6;
  longlong lVar7;
  ulonglong uVar8;
  undefined2 *_Dst;
  undefined2 *puVar9;
  ulonglong uVar10;
  undefined1 auStack_f8 [32];
  char local_d8;
  char *local_d0;
  char *local_c8;
  undefined8 local_c0;
  char *local_b8;
  ulonglong local_b0;
  ulonglong local_a8;
  longlong local_a0;
  ulonglong local_98;
  ulonglong *local_90;
  longlong *local_88;
  longlong local_80;
  longlong lStack_78;
  longlong local_70;
  longlong local_68;
  ulonglong uStack_60;
  longlong local_58;
  ulonglong uStack_50;
  undefined2 *local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_f8;
  local_a0 = param_2;
  local_88 = param_3;
  if (param_2 == 0) {
    local_c0 = 0x25a;
    local_b8 = "(PathSegmentCount == 0) || (PathSegments != 0)";
  }
  else {
    if (param_3 != (longlong *)0x0) {
      uVar8 = 0;
      uVar5 = 0;
      if (param_1 != 0) {
        do {
          local_a8 = 0;
          puVar4 = (ulonglong *)(local_a0 + uVar5 * 0x18);
          local_b0 = 0;
          uVar10 = *puVar4;
          uVar2 = RtlTrimNtPathSegment(puVar4,(longlong *)&local_a8,(longlong *)&local_b0);
          if ((int)uVar2 < 0) {
            return uVar2;
          }
          if ((uVar10 < local_a8) || (uVar10 - local_a8 < local_b0)) goto LAB_14001bd44;
          uVar2 = local_b0;
          if (uVar5 == 0) {
            uVar3 = 0;
          }
          else {
            uVar3 = local_a8;
            if (uVar5 == param_1) {
              uVar2 = 0;
            }
          }
          lVar7 = uVar10 - (uVar2 + uVar3);
          if ((lVar7 != 0) &&
             ((uVar10 = lVar7 + uVar8, uVar10 < uVar8 ||
              ((uVar8 = uVar10, uVar5 != 0 && (uVar8 = uVar10 + 2, uVar8 < uVar10)))))) {
            return 0xc0000095;
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 < param_1);
      }
      local_48 = (undefined2 *)0x0;
      local_d8 = '\0';
      local_68 = 0;
      uStack_60 = 0;
      local_58 = 0;
      uStack_50 = 0;
      if ((ulonglong)param_3[1] < uVar8) {
        uVar8 = RtlAllocateLUnicodeString(uVar8,&local_58);
        if ((int)uVar8 < 0) {
          if (local_48 != (undefined2 *)0x0) {
            RtlFreeLUnicodeString((longlong)&local_58);
          }
          return uVar8 & 0xffffffff;
        }
        local_d8 = '\x01';
        uVar8 = uStack_50;
        puVar9 = local_48;
      }
      else {
        uVar8 = param_3[1];
        puVar9 = (undefined2 *)param_3[2];
      }
      puVar6 = local_48;
      uVar5 = 0;
      _Dst = puVar9;
      local_68 = local_58;
      uStack_60 = uStack_50;
      if (param_1 != 0) {
        lVar7 = local_a0;
        do {
          local_b0 = 0;
          local_90 = (ulonglong *)(lVar7 + uVar5 * 0x18);
          local_98 = 0;
          uVar10 = *local_90;
          if (uVar10 != 0) {
            uVar2 = RtlTrimNtPathSegment(local_90,(longlong *)&local_b0,(longlong *)&local_98);
            puVar4 = (ulonglong *)0x0;
            local_a8 = CONCAT44(local_a8._4_4_,(int)uVar2);
            if ((int)uVar2 < 0) {
              if (puVar6 == (undefined2 *)0x0) {
                return uVar2;
              }
              RtlFreeLUnicodeString((longlong)&local_58);
              return local_a8 & 0xffffffff;
            }
            if ((uVar10 < local_b0) || (uVar10 - local_b0 < local_98)) goto LAB_14001bd44;
            uVar10 = local_98;
            if (uVar5 == 0) {
              uVar2 = 0;
            }
            else {
              if (uVar5 == param_1) {
                uVar10 = 0;
              }
              if (local_b0 < 2) {
                if (uVar8 < 2) {
                  local_c0 = 0x2ae;
                  local_b8 = "BytesLeft >= sizeof(WCHAR)";
                  goto LAB_14001bcff;
                }
                *_Dst = 0x5c;
                _Dst = _Dst + 1;
                uVar8 = uVar8 - 2;
                uVar2 = local_b0;
              }
              else {
                uVar2 = local_b0 - 2;
              }
            }
            uVar10 = (*local_90 - uVar10) - uVar2;
            if (uVar8 < uVar10) {
              local_c0 = 0x2b9;
              local_b8 = "BytesLeft >= BytesToCopy";
              puVar4 = local_90;
LAB_14001bcff:
              local_c8 = "RtlCombineNtPathSegments";
              local_d0 = "onecore\\base\\lstring\\path.cpp";
              RtlReportErrorOrigination(&local_d0,puVar4,-0x3fffffdd);
              if (puVar6 != (undefined2 *)0x0) {
                RtlFreeLUnicodeString((longlong)&local_58);
              }
              return 0xc0000023;
            }
            memmove(_Dst,(void *)(local_90[2] + uVar2),uVar10);
            _Dst = (undefined2 *)((longlong)_Dst + uVar10);
            uVar8 = uVar8 - uVar10;
            lVar7 = local_a0;
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 < param_1);
        param_3 = local_88;
      }
      puVar1 = local_48;
      if (local_d8 != '\0') {
        local_80 = *param_3;
        lStack_78 = param_3[1];
        local_70 = param_3[2];
        local_c0 = 0;
        local_58 = 0;
        uStack_50 = 0;
        local_48 = (undefined2 *)0x0;
        *param_3 = local_68;
        param_3[1] = uStack_60;
        param_3[2] = (longlong)puVar1;
        if (local_70 != 0) {
          RtlFreeLUnicodeString((longlong)&local_80);
        }
        puVar6 = local_48;
      }
      if (puVar9 <= _Dst) {
        *param_3 = (longlong)_Dst - (longlong)puVar9;
        if (puVar6 != (undefined2 *)0x0) {
          RtlFreeLUnicodeString((longlong)&local_58);
        }
        return 0;
      }
LAB_14001bd44:
                    /* WARNING: Subroutine does not return */
      RtlRaiseStatus(0xc00000e5);
    }
    local_c0 = 0x25b;
    local_b8 = "Not-null check failed: PathOut";
  }
  local_c8 = "RtlCombineNtPathSegments";
  local_d0 = "onecore\\base\\lstring\\path.cpp";
  RtlReportErrorOrigination(&local_d0,param_2,-0x3ffffff3);
  return 0xc000000d;
}



===== RtlTrimNtPathSegment @ 14001bd58 =====

undefined8 RtlTrimNtPathSegment(ulonglong *param_1,longlong *param_2,longlong *param_3)

{
  short sVar1;
  short *psVar2;
  char cVar3;
  undefined8 uVar4;
  short *psVar5;
  short *psVar6;
  longlong lVar7;
  longlong lVar8;
  longlong *plVar9;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  lVar7 = 0;
  *param_2 = 0;
  *param_3 = 0;
  plVar9 = param_2;
  cVar3 = RtlIsLUnicodeStringValid(param_1);
  if (cVar3 == '\0') {
    local_18 = 0x224;
    local_28 = "onecore\\base\\lstring\\path.cpp";
    local_20 = "RtlTrimNtPathSegment";
    local_10 = "RtlIsLUnicodeStringValid(Segment)";
    RtlReportErrorOrigination(&local_28,param_2,-0x3ffffff3);
    uVar4 = 0xc000000d;
  }
  else {
    psVar2 = (short *)param_1[2];
    psVar5 = (short *)(*param_1 + (longlong)psVar2);
    psVar6 = psVar2;
    lVar8 = lVar7;
    if (psVar2 < psVar5) {
      do {
        sVar1 = *psVar6;
        psVar6 = psVar6 + 1;
        if (sVar1 != 0x5c) break;
        lVar8 = lVar8 + 2;
      } while (psVar6 < psVar5);
      if (psVar6 < psVar5) {
        do {
          psVar5 = psVar5 + -1;
          if (*psVar5 != 0x5c) break;
          lVar7 = lVar7 + 2;
        } while (psVar2 < psVar5);
      }
    }
    *plVar9 = lVar8;
    uVar4 = 0;
    *param_3 = lVar7;
  }
  return uVar4;
}



===== RtlDowncaseUCSCharacter @ 14001be14 =====

uint RtlDowncaseUCSCharacter(uint param_1)

{
  ushort uVar1;
  
  if (param_1 < 0x80) {
    if (param_1 - 0x41 < 0x1a) {
      return param_1 + 0x20;
    }
  }
  else if (param_1 < 0x10000) {
    uVar1 = RtlDowncaseUnicodeChar();
    return (uint)uVar1;
  }
  return param_1;
}



===== RtlDecodeUtf16LE @ 14001be54 =====

uint * RtlDecodeUtf16LE(uint *param_1,ushort *param_2,ushort *param_3)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  ushort *puVar4;
  
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  if ((param_3 <= param_2) || ((ulonglong)((longlong)param_3 - (longlong)param_2) < 2))
  goto LAB_14001becc;
  uVar1 = *param_2;
  puVar4 = param_2 + 1;
  if (uVar1 < 0xd800) {
LAB_14001bec1:
    uVar3 = (uint)uVar1;
LAB_14001bec3:
    *param_1 = uVar3;
    *(ushort **)(param_1 + 2) = puVar4;
  }
  else {
    if (uVar1 < 0xdc00) {
      if (3 < (ulonglong)((longlong)param_3 - (longlong)param_2)) {
        uVar2 = *puVar4;
        puVar4 = param_2 + 2;
        if ((ushort)(uVar2 + 0x2400) < 0x400) {
          uVar3 = (uint)uVar1 * 0x400 + -0x35fdc00 + (uint)uVar2;
          goto LAB_14001bec3;
        }
      }
    }
    else if (0xdfff < uVar1) goto LAB_14001bec1;
LAB_14001becc:
    *param_1 = 0xffffffff;
    param_1[2] = 0xc0000161;
  }
  return param_1;
}



===== RtlDecodeUtf8 @ 14001bee4 =====

uint * RtlDecodeUtf8(uint *param_1,byte *param_2,byte *param_3)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  bool bVar4;
  
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  if (param_3 <= param_2) goto LAB_14001c188;
  bVar1 = *param_2;
  pbVar3 = param_2 + 1;
  uVar2 = (uint)bVar1;
  if ((char)bVar1 < '\0') {
    if ((bVar1 & 0xe0) == 0xc0) {
      if (param_3 <= pbVar3) goto LAB_14001c188;
      bVar1 = *pbVar3;
      pbVar3 = param_2 + 2;
      if ((bVar1 & 0xc0) != 0x80) goto LAB_14001c188;
      uVar2 = (uVar2 & 0x1f) << 6 | bVar1 & 0x3f;
      bVar4 = uVar2 < 0x80;
    }
    else if ((bVar1 & 0xf0) == 0xe0) {
      if (param_3 + -1 <= pbVar3) goto LAB_14001c188;
      bVar1 = *pbVar3;
      pbVar3 = param_2 + 3;
      if (((bVar1 & 0xc0) != 0x80) || ((param_2[2] & 0xc0) != 0x80)) goto LAB_14001c188;
      uVar2 = ((uVar2 & 0xf) << 6 | bVar1 & 0x3f) << 6 | param_2[2] & 0x3f;
      bVar4 = uVar2 < 0x800;
    }
    else if ((bVar1 & 0xf8) == 0xf0) {
      if (param_3 + -2 <= pbVar3) goto LAB_14001c188;
      bVar1 = *pbVar3;
      pbVar3 = param_2 + 4;
      if ((((bVar1 & 0xc0) != 0x80) || ((param_2[2] & 0xc0) != 0x80)) ||
         ((param_2[3] & 0xc0) != 0x80)) goto LAB_14001c188;
      uVar2 = (((uVar2 & 7) << 6 | bVar1 & 0x3f) << 6 | param_2[2] & 0x3f) << 6 | param_2[3] & 0x3f;
      bVar4 = uVar2 < 0x10000;
    }
    else if ((bVar1 & 0xfc) == 0xf8) {
      if (param_3 + -3 <= pbVar3) goto LAB_14001c188;
      bVar1 = *pbVar3;
      pbVar3 = param_2 + 5;
      if ((((bVar1 & 0xc0) != 0x80) || ((param_2[2] & 0xc0) != 0x80)) ||
         (((param_2[3] & 0xc0) != 0x80 || ((param_2[4] & 0xc0) != 0x80)))) goto LAB_14001c188;
      uVar2 = ((((uVar2 & 3) << 6 | bVar1 & 0x3f) << 6 | param_2[2] & 0x3f) << 6 | param_2[3] & 0x3f
              ) << 6 | param_2[4] & 0x3f;
      bVar4 = uVar2 < 0x200000;
    }
    else {
      if (((bVar1 & 0xfe) != 0xfc) || (param_3 + -4 <= pbVar3)) goto LAB_14001c188;
      bVar1 = *pbVar3;
      pbVar3 = param_2 + 6;
      if (((bVar1 & 0xc0) != 0x80) ||
         (((((param_2[2] & 0xc0) != 0x80 || ((param_2[3] & 0xc0) != 0x80)) ||
           ((param_2[4] & 0xc0) != 0x80)) || ((param_2[5] & 0xc0) != 0x80)))) goto LAB_14001c188;
      uVar2 = (((((uVar2 & 1) << 6 | bVar1 & 0x3f) << 6 | param_2[2] & 0x3f) << 6 |
               param_2[3] & 0x3f) << 6 | param_2[4] & 0x3f) << 6 | param_2[5] & 0x3f;
      bVar4 = uVar2 < 0x4000000;
    }
    *param_1 = uVar2;
    if (bVar4) {
LAB_14001c188:
      *param_1 = 0xffffffff;
      param_1[2] = 0xc0000161;
      return param_1;
    }
  }
  else {
    *param_1 = uVar2;
  }
  *(byte **)(param_1 + 2) = pbVar3;
  return param_1;
}



===== RtlEncodeUtf16LE @ 14001c1b0 =====

longlong * RtlEncodeUtf16LE(longlong *param_1,uint param_2,short *param_3,longlong param_4)

{
  short *psVar1;
  
  psVar1 = (short *)0x0;
  *(undefined4 *)((longlong)param_1 + 0xc) = 0;
  if (param_2 < 0x10000) {
    if ((ulonglong)(param_4 - (longlong)param_3) < 2) {
LAB_14001c1ec:
      *(undefined4 *)(param_1 + 1) = 0xc0000023;
      goto LAB_14001c23d;
    }
    if (0x3ff < param_2 - 0xdc00) {
      psVar1 = param_3;
LAB_14001c228:
      *param_3 = (short)param_2;
      *(undefined4 *)(param_1 + 1) = 0;
      psVar1 = psVar1 + 1;
      goto LAB_14001c23d;
    }
  }
  else if (param_2 < 0x110000) {
    if (3 < (ulonglong)(param_4 - (longlong)param_3)) {
      psVar1 = param_3 + 1;
      *psVar1 = ((ushort)param_2 & 0x3ff) + 0xdc00;
      param_2 = (uint)(ushort)((short)(param_2 - 0x10000 >> 10) + 0xd800);
      goto LAB_14001c228;
    }
    goto LAB_14001c1ec;
  }
  *(undefined4 *)(param_1 + 1) = 0xc0000161;
LAB_14001c23d:
  *param_1 = (longlong)psVar1;
  return param_1;
}



===== RtlGetEncodingSizeUtf16 @ 14001c24c =====

longlong RtlGetEncodingSizeUtf16(uint param_1)

{
  if (param_1 < 0x10000) {
    return 2;
  }
  return (ulonglong)(-(uint)(param_1 < 0x10ffff) & 5) - 1;
}



===== LstringKmAllocateString @ 14001c274 =====

/* void * __ptr64 __cdecl LstringKmAllocateString(unsigned __int64) */

void * __cdecl LstringKmAllocateString(__uint64 param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)ExAllocatePoolWithTag(0x401,param_1,0x6d6b736c);
  return pvVar1;
}



===== LstringKmFreeString @ 14001c2a0 =====

/* void __cdecl LstringKmFreeString(void * __ptr64) */

void __cdecl LstringKmFreeString(void *param_1)

{
  if (param_1 != (void *)0x0) {
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== entry @ 14001e010 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 14001e044 =====

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



===== wil_InitializeFeatureStaging @ 14001e078 =====

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
    for (ppuVar3 = &wil_details_featureDescriptors_a; ppuVar3 < &wil_details_featureDescriptors_z;
        ppuVar3 = ppuVar3 + 1) {
      if (*ppuVar3 != (undefined *)0x0) goto LAB_14001e0ff;
    }
LAB_14001e139:
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
LAB_14001e0ff:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14001e139;
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
    goto LAB_14001e139;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_1400167a7 < ppuVar3) goto LAB_14001e139;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14001e0ff;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14001e18c =====

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
  ppuVar4 = &wil_details_featureDescriptors_a;
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
            if (&UNK_1400167a7 < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_14001e276;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_14001e276;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_14001e276:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_1400167a7 < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


