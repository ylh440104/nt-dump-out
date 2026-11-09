
===== _tlgWriteTransfer_EtwWriteTransfer @ 1c0001008 =====

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



===== __report_gsfailure @ 1c00010c0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 1c00010cd =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001c00010cd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== __cpu_features_init @ 1c00010f0 =====

/* WARNING: Removing unreachable block (ram,0x0001c000115a) */
/* WARNING: Removing unreachable block (ram,0x0001c0001109) */
/* WARNING: Removing unreachable block (ram,0x0001c00010fa) */

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



===== copy<gsl::byte_const_,-1,gsl::byte,-1> @ 1c00011b8 =====

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
        memcpy(_Dst,(void *)param_1[1],_Size);
        return;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  details::terminate();
}



===== ~unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_> @ 1c0001238 =====

/* public: __cdecl wistd::unique_ptr<class wistd::unique_ptr<struct _MDL,struct
   wil::function_deleter<void (__cdecl*)(struct _MDL * __ptr64),&void __cdecl
   UnlockAndFreeMdl(struct _MDL * __ptr64)> > [0],struct wistd::default_delete<class
   wistd::unique_ptr<struct _MDL,struct wil::function_deleter<void (__cdecl*)(struct _MDL *
   __ptr64),&void __cdecl UnlockAndFreeMdl(struct _MDL * __ptr64)> > [0]> >::~unique_ptr<class
   wistd::unique_ptr<struct _MDL,struct wil::function_deleter<void (__cdecl*)(struct _MDL *
   __ptr64),&void __cdecl UnlockAndFreeMdl(struct _MDL * __ptr64)> > [0],struct
   wistd::default_delete<class wistd::unique_ptr<struct _MDL,struct wil::function_deleter<void
   (__cdecl*)(struct _MDL * __ptr64),&void __cdecl UnlockAndFreeMdl(struct _MDL * __ptr64)> > [0]>
   >(void) __ptr64 */

void __thiscall
wistd::
unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
::
~unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
          (unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
           *this)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>
  *this_00;
  
  lVar2 = *(longlong *)this;
  *(undefined8 *)this = 0;
  if (lVar2 != 0) {
    plVar1 = (longlong *)(lVar2 + -8);
    lVar3 = *plVar1;
    this_00 = (unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>
               *)(lVar2 + lVar3 * 8);
    for (; lVar3 != 0; lVar3 = lVar3 + -1) {
      this_00 = this_00 + -8;
      unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>
      ::
      ~unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>
                (this_00);
    }
    if (plVar1 != (longlong *)0x0) {
      ExFreePoolWithTag(plVar1,0);
    }
  }
  return;
}



===== ~unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_> @ 1c00012a4 =====

/* public: __cdecl wistd::unique_ptr<struct _MDL,struct wil::function_deleter<void (__cdecl*)(struct
   _MDL * __ptr64),&void __cdecl UnlockAndFreeMdl(struct _MDL * __ptr64)> >::~unique_ptr<struct
   _MDL,struct wil::function_deleter<void (__cdecl*)(struct _MDL * __ptr64),&void __cdecl
   UnlockAndFreeMdl(struct _MDL * __ptr64)> >(void) __ptr64 */

void __thiscall
wistd::
unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>
::
~unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>
          (unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>
           *this)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)this;
  *(undefined8 *)this = 0;
  if (lVar1 != 0) {
    MmUnlockPages(lVar1);
    IoFreeMdl(lVar1);
  }
  return;
}



===== ~Gpadl @ 1c00012e4 =====

/* public: __cdecl Gpadl::~Gpadl(void) __ptr64 */

void __thiscall Gpadl::~Gpadl(Gpadl *this)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(this + 0x38);
  *(undefined8 *)(this + 0x38) = 0;
  if (lVar1 != 0) {
    MdlMapping::~MdlMapping((MdlMapping *)(lVar1 + 0x20));
    lVar2 = *(longlong *)(lVar1 + 0x18);
    *(undefined8 *)(lVar1 + 0x18) = 0;
    if (lVar2 != 0) {
      IoFreeMdl();
    }
    wistd::
    unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
    ::
    ~unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
              ((unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
                *)(lVar1 + 0x10));
    ExFreePoolWithTag(lVar1,0);
  }
  CancellableIrp::~CancellableIrp((CancellableIrp *)(this + 0x28));
  lVar1 = *(longlong *)(this + 0x20);
  *(undefined8 *)(this + 0x20) = 0;
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0);
  }
  lVar1 = *(longlong *)(this + 0x18);
  *(undefined8 *)(this + 0x18) = 0;
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0);
  }
  return;
}



===== AddGpadl @ 1c0001390 =====

/* public: long __cdecl GpadlSet::AddGpadl(class wistd::unique_ptr<struct Gpadl,struct
   wistd::default_delete<struct Gpadl> >) __ptr64 */

long __thiscall GpadlSet::AddGpadl(GpadlSet *this,longlong *param_2)

{
  uint uVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  long lVar6;
  Gpadl *pGVar7;
  GpadlSet *pGVar8;
  longlong *plVar9;
  undefined1 *puVar10;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [24];
  GpadlSet *local_38;
  undefined1 uStack_30;
  undefined4 uStack_2f;
  undefined2 uStack_2b;
  undefined1 uStack_29;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  uVar5 = KeAcquireSpinLockRaiseToDpc();
  uVar4 = _uStack_30;
  plVar2 = (longlong *)*param_2;
  local_20 = (char *)0x0;
  local_18 = 0;
  uVar1 = *(uint *)(plVar2 + 2);
  _uStack_30 = CONCAT41(uStack_2f,uVar5);
  uStack_2b = SUB82(uVar4,5);
  uStack_29 = SUB81(uVar4,7);
  local_28 = (char *)CONCAT44(local_28._4_4_,uVar1);
  local_38 = this;
  pGVar7 = FindGpadl(this,(GpadlKey *)&local_28);
  puVar10 = auStack_58;
  if (pGVar7 == (Gpadl *)0x0) {
    *param_2 = 0;
    pGVar8 = this + 8;
    plVar9 = *(longlong **)(this + 0x10);
    if ((GpadlSet *)*plVar9 != pGVar8) {
      plVar9 = (longlong *)0x3;
      pcVar3 = (code *)swi(0x29);
      pGVar8 = (GpadlSet *)(*pcVar3)();
      puVar10 = auStack_50;
    }
    *plVar2 = (longlong)pGVar8;
    plVar2[1] = (longlong)plVar9;
    *plVar9 = (longlong)plVar2;
    *(longlong **)(pGVar8 + 8) = plVar2;
    if (this != (GpadlSet *)0x0) {
      *(undefined8 *)(puVar10 + -8) = 0x1c00014ba;
      wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_38);
    }
    pGVar7 = (Gpadl *)*param_2;
    *param_2 = 0;
    if (pGVar7 != (Gpadl *)0x0) {
      *(undefined8 *)(puVar10 + -8) = 0x1c00014ce;
      Gpadl::~Gpadl(pGVar7);
      *(undefined8 *)(puVar10 + -8) = 0x1c00014da;
      ExFreePoolWithTag(pGVar7,0);
    }
    lVar6 = 0;
  }
  else {
    local_18 = 0x8e;
    local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\gpadl.cpp";
    local_20 = "GpadlSet::AddGpadl";
    local_10 = "%u";
    OnFailure((ErrorSite *)&local_28,-0x3ffff8f8,(ulonglong)uVar1);
    if (this != (GpadlSet *)0x0) {
      wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_38);
    }
    pGVar7 = (Gpadl *)*param_2;
    *param_2 = 0;
    if (pGVar7 != (Gpadl *)0x0) {
      Gpadl::~Gpadl(pGVar7);
      ExFreePoolWithTag(pGVar7,0);
    }
    lVar6 = -0x3ffff8f8;
  }
  return lVar6;
}



===== CommitMapping @ 1c0001504 =====

/* public: long __cdecl LockedGpadl::CommitMapping(class CompletedIrps & __ptr64) __ptr64 */

long __thiscall LockedGpadl::CommitMapping(LockedGpadl *this,CompletedIrps *param_1)

{
  bool bVar1;
  long lVar2;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  bVar1 = GpadlSet::UnlockGpadl(*(GpadlSet **)this,*(Gpadl **)(this + 8),param_1);
  *(undefined8 *)(this + 8) = 0;
  if (bVar1) {
    lVar2 = 0;
  }
  else {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\gpadl.cpp";
    local_18 = 0x127;
    local_20 = "LockedGpadl::CommitMapping";
    OnFailure((ErrorSite *)&local_28,-0x3ffffe7c);
    lVar2 = -0x3ffffe7c;
  }
  return lVar2;
}



===== Create @ 1c0001570 =====

/* public: static long __cdecl Gpadl::Create(unsigned int,unsigned int,class gsl::span<enum
   gsl::byte const ,-1>,class wistd::unique_ptr<struct Gpadl,struct wistd::default_delete<struct
   Gpadl> > * __ptr64) */

long __cdecl
Gpadl::Create(undefined4 param_1,uint param_2,undefined1 (*param_3) [16],undefined8 *param_4)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  Gpadl *this;
  code *pcVar4;
  undefined1 auVar5 [16];
  __uint64 _Var6;
  uint *puVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  char *pcVar10;
  ulonglong uVar11;
  char *pcVar12;
  undefined1 *puVar13;
  uint *puVar14;
  uint uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined1 auStack_88 [8];
  undefined1 auStack_80 [40];
  undefined8 local_58;
  undefined8 uStack_50;
  char *local_48;
  uint *puStack_40;
  undefined8 local_38;
  char *local_30;
  
  if (param_2 == 0) {
    local_38 = 8;
    local_48 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\gpadl.cpp";
    local_30 = (char *)0x0;
    puStack_40 = (uint *)0x1c000c1f8;
    OnFailure((ErrorSite *)&local_48,-0x3ffffff3);
    return -0x3ffffff3;
  }
  uVar11 = *(ulonglong *)*param_3;
  if (((uVar11 & 7) != 0) || (0xffffffff < uVar11)) {
    local_38 = 0xe;
    local_48 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\gpadl.cpp";
    puStack_40 = (uint *)0x1c000c1f8;
    local_30 = "%zu";
    OnFailure((ErrorSite *)&local_48,-0x3ffffff3);
    return -0x3ffffff3;
  }
  pcVar12 = (char *)(uVar11 >> 3 & 0xffffffff);
  auVar5._8_8_ = 0;
  auVar5._0_8_ = pcVar12;
  _Var6 = SUB168(ZEXT816(8) * auVar5,0);
  if (SUB168(ZEXT816(8) * auVar5,8) != 0) {
    _Var6 = 0xffffffffffffffff;
  }
  puVar7 = operator_new(_Var6);
  if (puVar7 == (uint *)0x0) {
    local_38 = 0x15;
    local_48 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\gpadl.cpp";
    local_30 = (char *)0x0;
    puStack_40 = (uint *)0x1c000c1f8;
    OnFailure((ErrorSite *)&local_48,-0x3fffff66);
    return -0x3fffff66;
  }
  _Var6 = SUB168(ZEXT816(8) * ZEXT416(param_2),0);
  if (SUB168(ZEXT816(8) * ZEXT416(param_2),8) != 0) {
    _Var6 = 0xffffffffffffffff;
  }
  puVar8 = operator_new(_Var6);
  puVar13 = auStack_88;
  if (puVar8 == (undefined8 *)0x0) {
    local_38 = 0x1b;
    local_48 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\gpadl.cpp";
    local_30 = (char *)0x0;
    puStack_40 = (uint *)0x1c000c1f8;
    OnFailure((ErrorSite *)&local_48,-0x3fffff66);
    puVar13 = auStack_88;
  }
  else {
    auVar5 = *param_3;
    uVar16 = auVar5._0_4_;
    uVar17 = auVar5._4_4_;
    uVar18 = auVar5._8_4_;
    uVar19 = auVar5._12_4_;
    if ((auVar5._0_8_ & 7) != 0) {
      local_30 = (char *)0x0;
      local_48 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\util.h";
      local_38 = 0xa2;
      puStack_40 = (uint *)0x1c000c2a0;
      OnFailure((ErrorSite *)&local_48,-0x3fffffff);
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(5);
      puVar13 = auStack_80;
    }
    local_48 = (char *)((longlong)pcVar12 * 8);
    local_58 = (char *)CONCAT44(uVar17,uVar16);
    uStack_50 = (uint *)CONCAT44(uVar19,uVar18);
    *(undefined8 *)(puVar13 + -8) = 0x1c000171a;
    puStack_40 = puVar7;
    gsl::copy<gsl::byte_const_,_1,gsl::byte,_1>(&local_58,&local_48);
    uVar15 = 0;
    if (param_2 != 0) {
      puVar9 = puVar8;
      puVar14 = puVar7;
      do {
        if (pcVar12 == (char *)0x0) {
          local_38 = 0x24;
          goto LAB_1c000194c;
        }
        if (pcVar12 == (char *)0x0) {
LAB_1c00019ef:
                    /* WARNING: Subroutine does not return */
          *(undefined **)(puVar13 + -8) = &UNK_1c00019f4;
          gsl::details::terminate();
        }
        pcVar12 = pcVar12 + -1;
        if (pcVar12 == (char *)0xffffffffffffffff) goto LAB_1c00019ef;
        uVar1 = puVar14[1];
        uVar11 = (longlong)pcVar12 * 0x1000;
        if (0xfff < uVar1) {
LAB_1c00017dd:
          uVar15 = *puVar14;
          local_48 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\gpadl.cpp";
          *(ulonglong *)(puVar13 + 0x20) = uVar11;
          puStack_40 = (uint *)0x1c000c1f8;
          local_38 = 0x2f;
          local_30 = "%u %u %zu";
          *(undefined8 *)(puVar13 + -8) = 0x1c000181c;
          OnFailure((ErrorSite *)&local_48,-0x3ffffff3,(ulonglong)uVar1,(ulonglong)uVar15);
          goto LAB_1c0001970;
        }
        uVar2 = *puVar14;
        if (((uVar2 == 0) || (uVar11 < uVar2)) || (uVar11 - uVar2 < (ulonglong)uVar1))
        goto LAB_1c00017dd;
        pcVar10 = (char *)(ulonglong)(uVar2 + 0xfff + uVar1 >> 0xc);
        if (pcVar12 < pcVar10) goto LAB_1c00019ef;
        pcVar12 = pcVar12 + -(longlong)pcVar10;
        local_58 = pcVar12;
        if (pcVar12 == (char *)0xffffffffffffffff) goto LAB_1c00019ef;
        *puVar9 = puVar14;
        uVar15 = uVar15 + 1;
        puVar9 = puVar9 + 1;
        puVar14 = puVar14 + (longlong)(pcVar10 + 1) * 2;
        uStack_50 = puVar14;
        local_48 = pcVar12;
        puStack_40 = puVar14;
      } while (uVar15 < param_2);
    }
    if (pcVar12 != (char *)0x0) {
      local_38 = 0x39;
LAB_1c000194c:
      local_30 = (char *)0x0;
      local_48 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\gpadl.cpp";
      puStack_40 = (uint *)0x1c000c1f8;
      *(undefined8 *)(puVar13 + -8) = 0x1c0001970;
      OnFailure((ErrorSite *)&local_48,-0x3ffffff3);
LAB_1c0001970:
      *(undefined8 *)(puVar13 + -8) = 0x1c000197c;
      ExFreePoolWithTag(puVar8,0);
      *(undefined8 *)(puVar13 + -8) = 0x1c000198d;
      ExFreePoolWithTag(puVar7,0);
      return -0x3ffffff3;
    }
    *(undefined8 *)(puVar13 + -8) = 0x1c0001847;
    puVar9 = operator_new(0x40);
    if (puVar9 != (undefined8 *)0x0) {
      *puVar9 = 0;
      puVar9[1] = 0;
      *(undefined4 *)((longlong)puVar9 + 0x32) = 0;
      *(undefined2 *)((longlong)puVar9 + 0x36) = 0;
      puVar9[2] = 0;
      puVar9[3] = 0;
      puVar9[4] = 0;
      puVar9[5] = 0;
      *(undefined2 *)(puVar9 + 6) = 0;
      puVar9[7] = 0;
      *(undefined4 *)(puVar9 + 2) = param_1;
      *(uint *)((longlong)puVar9 + 0x14) = param_2;
      lVar3 = puVar9[3];
      puVar9[3] = puVar7;
      if (lVar3 != 0) {
        *(undefined8 *)(puVar13 + -8) = 0x1c000189c;
        ExFreePoolWithTag(lVar3,0);
      }
      lVar3 = puVar9[4];
      puVar9[4] = puVar8;
      if (lVar3 != 0) {
        *(undefined8 *)(puVar13 + -8) = 0x1c00018b7;
        ExFreePoolWithTag(lVar3,0);
      }
      this = (Gpadl *)*param_4;
      *param_4 = puVar9;
      if (this != (Gpadl *)0x0) {
        *(undefined8 *)(puVar13 + -8) = 0x1c00018d1;
        ~Gpadl(this);
        *(undefined8 *)(puVar13 + -8) = 0x1c00018dd;
        ExFreePoolWithTag(this,0);
      }
      return 0;
    }
    local_38 = 0x3f;
    local_48 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\gpadl.cpp";
    local_30 = (char *)0x0;
    puStack_40 = (uint *)0x1c000c1f8;
    *(undefined8 *)(puVar13 + -8) = 0x1c0001919;
    OnFailure((ErrorSite *)&local_48,-0x3fffff66);
    *(undefined8 *)(puVar13 + -8) = 0x1c0001925;
    ExFreePoolWithTag(puVar8,0);
  }
  *(undefined8 *)(puVar13 + -8) = 0x1c0001936;
  ExFreePoolWithTag(puVar7,0);
  return -0x3fffff66;
}



===== DeleteGpadl @ 1c00019fc =====

/* public: long __cdecl GpadlSet::DeleteGpadl(unsigned int,struct _IRP * __ptr64,class CompletedIrps
   & __ptr64) __ptr64 */

long __thiscall
GpadlSet::DeleteGpadl(GpadlSet *this,uint param_1,_IRP *param_2,CompletedIrps *param_3)

{
  undefined1 uVar1;
  bool bVar2;
  long lVar3;
  Gpadl *this_00;
  GpadlSet *this_01;
  undefined8 uVar4;
  GpadlSet *local_48;
  undefined1 uStack_40;
  undefined4 uStack_3f;
  undefined2 uStack_3b;
  undefined1 uStack_39;
  char *local_38;
  char *local_30;
  undefined8 local_28;
  char *local_20;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc();
  uVar4 = _uStack_40;
  local_30 = (char *)0x0;
  local_28 = 0;
  _uStack_40 = CONCAT41(uStack_3f,uVar1);
  uStack_3b = SUB82(uVar4,5);
  uStack_39 = SUB81(uVar4,7);
  local_38 = (char *)CONCAT44(local_38._4_4_,param_1);
  this_01 = this;
  local_48 = this;
  this_00 = FindGpadl(this,(GpadlKey *)&local_38);
  if ((this_00 == (Gpadl *)0x0) || (this_00[0x31] != (Gpadl)0x0)) {
    local_28 = 0x9e;
    local_38 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\gpadl.cpp";
    local_30 = "GpadlSet::DeleteGpadl";
    local_20 = "%u, %d";
    if ((this_00 == (Gpadl *)0x0) || (this_00[0x31] == (Gpadl)0x0)) {
      uVar4 = 0;
    }
    else {
      uVar4 = 1;
    }
    lVar3 = -0x3ffffddb;
    OnFailure((ErrorSite *)&local_38,-0x3ffffddb,(ulonglong)param_1,uVar4);
  }
  else {
    this_00[0x31] = (Gpadl)0x1;
    bVar2 = RemoveGpadlIfUnreferenced(this_01,this_00,param_3);
    if (bVar2) {
      if (this != (GpadlSet *)0x0) {
        wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_48);
      }
      Gpadl::~Gpadl(this_00);
      ExFreePoolWithTag(this_00,0);
      return 0;
    }
    lVar3 = CancellableIrp::Set((CancellableIrp *)(this_00 + 0x28),param_2);
    if (-1 < lVar3) {
      if (this != (GpadlSet *)0x0) {
        wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_48);
      }
      return 0x103;
    }
    local_20 = (char *)0x0;
    local_38 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\gpadl.cpp";
    local_28 = 0xa4;
    local_30 = "GpadlSet::DeleteGpadl";
    OnFailure((ErrorSite *)&local_38,lVar3);
  }
  if (this != (GpadlSet *)0x0) {
    wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_48);
  }
  return lVar3;
}



===== FindGpadl @ 1c0001bb4 =====

/* private: struct Gpadl * __ptr64 __cdecl GpadlSet::FindGpadl(struct GpadlKey const & __ptr64)
   __ptr64 */

Gpadl * __thiscall GpadlSet::FindGpadl(GpadlSet *this,GpadlKey *param_1)

{
  Gpadl *pGVar1;
  Gpadl *pGVar2;
  longlong lVar3;
  Gpadl *pGVar4;
  ulonglong uVar5;
  bool bVar6;
  
  pGVar1 = (Gpadl *)(this + 8);
  if (*(Gpadl **)pGVar1 != pGVar1) {
    pGVar4 = *(Gpadl **)pGVar1;
    do {
      pGVar2 = *(Gpadl **)pGVar4;
      if (*(longlong *)(param_1 + 8) == 0) {
        bVar6 = *(int *)(pGVar4 + 0x10) == *(int *)param_1;
LAB_1c0001bfd:
        if (bVar6) {
          return pGVar4;
        }
      }
      else {
        lVar3 = *(longlong *)(pGVar4 + 0x38);
        if ((lVar3 != 0) && (*(longlong *)(param_1 + 8) == *(longlong *)(lVar3 + 0x30))) {
          uVar5 = 0;
          if (*(longlong *)(lVar3 + 0x30) != 0) {
            uVar5 = (ulonglong)*(uint *)(*(longlong *)(lVar3 + 0x28) + 0x28);
          }
          bVar6 = *(ulonglong *)(param_1 + 0x10) == uVar5;
          goto LAB_1c0001bfd;
        }
      }
      pGVar4 = pGVar2;
    } while (pGVar2 != pGVar1);
  }
  return (Gpadl *)0x0;
}



===== LockGpadl @ 1c0001c14 =====

/* public: long __cdecl GpadlSet::LockGpadl(struct GpadlKey const & __ptr64,class LockedGpadl *
   __ptr64) __ptr64 */

long __thiscall GpadlSet::LockGpadl(GpadlSet *this,GpadlKey *param_1,LockedGpadl *param_2)

{
  undefined8 uVar1;
  undefined1 uVar2;
  Gpadl *pGVar3;
  long lVar4;
  GpadlSet *local_48;
  undefined1 uStack_40;
  undefined4 uStack_3f;
  undefined2 uStack_3b;
  undefined1 uStack_39;
  GpadlSet *local_38;
  Gpadl *pGStack_30;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc();
  uVar1 = _uStack_40;
  _uStack_40 = CONCAT41(uStack_3f,uVar2);
  uStack_3b = SUB82(uVar1,5);
  uStack_39 = SUB81(uVar1,7);
  local_48 = this;
  if (this[0x18] == (GpadlSet)0x0) {
    local_18 = 0x109;
    lVar4 = -0x3ffffe7c;
  }
  else {
    pGVar3 = FindGpadl(this,param_1);
    if (pGVar3 == (Gpadl *)0x0) {
      local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\gpadl.cpp";
      lVar4 = -0x3ffffddb;
      local_18 = 0x10f;
      local_20 = "GpadlSet::LockGpadl";
      local_10 = "%u %p %#zx";
      OnFailure((ErrorSite *)&local_28,-0x3ffffddb,(ulonglong)*(uint *)param_1,
                *(undefined8 *)(param_1 + 8),*(undefined8 *)(param_1 + 0x10));
      goto LAB_1c0001c98;
    }
    if (pGVar3[0x30] == (Gpadl)0x0) {
      pGVar3[0x30] = (Gpadl)0x1;
      wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_48);
      local_38 = this;
      pGStack_30 = pGVar3;
      if (param_2 != (LockedGpadl *)&local_38) {
        LockedGpadl::reset(param_2);
        *(GpadlSet **)param_2 = this;
        local_38 = (GpadlSet *)0x0;
        pGStack_30 = (Gpadl *)0x0;
        *(Gpadl **)(param_2 + 8) = pGVar3;
      }
      LockedGpadl::reset((LockedGpadl *)&local_38);
      return 0;
    }
    local_18 = 0x114;
    lVar4 = -0x3ffff8f8;
  }
  local_10 = (char *)0x0;
  local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\gpadl.cpp";
  local_20 = "GpadlSet::LockGpadl";
  OnFailure((ErrorSite *)&local_28,lVar4);
LAB_1c0001c98:
  wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_48);
  return lVar4;
}



===== Release @ 1c0001d94 =====

/* public: static void __cdecl wil::details::kspin_lock_saved_irql::Release(struct
   wil::details::kspin_lock_saved_irql const & __ptr64) */

void __cdecl wil::details::kspin_lock_saved_irql::Release(kspin_lock_saved_irql *param_1)

{
  KeReleaseSpinLock(*(undefined8 *)param_1,param_1[8]);
  return;
}



===== RemoveGpadlIfUnreferenced @ 1c0001db8 =====

/* private: bool __cdecl GpadlSet::RemoveGpadlIfUnreferenced(struct Gpadl & __ptr64,class
   CompletedIrps & __ptr64) __ptr64 */

bool __thiscall
GpadlSet::RemoveGpadlIfUnreferenced(GpadlSet *this,Gpadl *param_1,CompletedIrps *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  _IRP *p_Var4;
  long lVar5;
  
  lVar5 = 0;
  if (((param_1[0x30] == (Gpadl)0x0) && (param_1[0x31] != (Gpadl)0x0)) &&
     (*(longlong *)(param_1 + 0x38) == 0)) {
    p_Var4 = CancellableIrp::Take((CancellableIrp *)(param_1 + 0x28));
    if (p_Var4 != (_IRP *)0x0) {
      CompletedIrps::Push(param_2,p_Var4,lVar5);
    }
    lVar1 = *(longlong *)param_1;
    if ((*(Gpadl **)(lVar1 + 8) == param_1) &&
       (plVar2 = *(longlong **)(param_1 + 8), (Gpadl *)*plVar2 == param_1)) {
      *plVar2 = lVar1;
      *(longlong **)(lVar1 + 8) = plVar2;
      return true;
    }
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
  }
  return false;
}



===== UnlockGpadl @ 1c0001e24 =====

/* private: bool __cdecl GpadlSet::UnlockGpadl(struct Gpadl & __ptr64,class CompletedIrps & __ptr64)
   __ptr64 */

bool __thiscall GpadlSet::UnlockGpadl(GpadlSet *this,Gpadl *param_1,CompletedIrps *param_2)

{
  GpadlSet GVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  bool bVar5;
  GpadlSet *this_00;
  longlong lVar6;
  Gpadl *this_01;
  GpadlSet *local_18;
  undefined1 uStack_10;
  undefined4 uStack_f;
  undefined2 uStack_b;
  undefined1 uStack_9;
  
  lVar6 = 0;
  this_00 = this;
  uVar4 = KeAcquireSpinLockRaiseToDpc();
  uVar3 = _uStack_10;
  _uStack_10 = CONCAT41(uStack_f,uVar4);
  uStack_b = SUB82(uVar3,5);
  uStack_9 = SUB81(uVar3,7);
  param_1[0x30] = (Gpadl)0x0;
  if (this[0x18] == (GpadlSet)0x0) {
    lVar6 = *(longlong *)(param_1 + 0x38);
    *(undefined8 *)(param_1 + 0x38) = 0;
  }
  local_18 = this;
  bVar5 = RemoveGpadlIfUnreferenced(this_00,param_1,param_2);
  this_01 = (Gpadl *)(-(ulonglong)bVar5 & (ulonglong)param_1);
  GVar1 = this[0x18];
  wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_18);
  if (lVar6 != 0) {
    MdlMapping::~MdlMapping((MdlMapping *)(lVar6 + 0x20));
    lVar2 = *(longlong *)(lVar6 + 0x18);
    *(undefined8 *)(lVar6 + 0x18) = 0;
    if (lVar2 != 0) {
      IoFreeMdl();
    }
    wistd::
    unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
    ::
    ~unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
              ((unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
                *)(lVar6 + 0x10));
    ExFreePoolWithTag(lVar6,0);
  }
  if (this_01 != (Gpadl *)0x0) {
    Gpadl::~Gpadl(this_01);
    ExFreePoolWithTag(this_01,0);
  }
  return (bool)GVar1;
}



===== UnmapAllGpadls @ 1c0001f30 =====

/* public: void __cdecl GpadlSet::UnmapAllGpadls(class CompletedIrps & __ptr64) __ptr64 */

void __thiscall GpadlSet::UnmapAllGpadls(GpadlSet *this,CompletedIrps *param_1)

{
  GpadlSet *pGVar1;
  longlong lVar2;
  code *pcVar3;
  char *pcVar4;
  undefined1 uVar5;
  bool bVar6;
  GpadlSet *pGVar7;
  Gpadl *pGVar8;
  undefined1 *puVar9;
  GpadlSet *pGVar10;
  Gpadl *pGVar11;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  GpadlSet *local_48;
  GpadlSet *local_40;
  Gpadl *local_38;
  Gpadl *local_30;
  GpadlSet *local_28;
  char *pcStack_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_30 = (Gpadl *)&local_38;
  local_38 = (Gpadl *)&local_38;
  local_40 = (GpadlSet *)&local_48;
  local_48 = (GpadlSet *)&local_48;
  pGVar7 = this;
  uVar5 = KeAcquireSpinLockRaiseToDpc();
  pcVar4 = pcStack_20;
  puVar9 = auStack_68;
  pGVar10 = this + 8;
  pcStack_20._0_5_ = CONCAT41(pcStack_20._1_4_,uVar5);
  pcStack_20._5_2_ = SUB82(pcVar4,5);
  pcStack_20._7_1_ = SUB81(pcVar4,7);
  this[0x18] = (GpadlSet)0x0;
  pGVar8 = *(Gpadl **)pGVar10;
  local_28 = this;
  while( true ) {
    do {
      do {
        pGVar11 = pGVar8;
        if (pGVar11 == (Gpadl *)pGVar10) {
          wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_28);
          pGVar7 = local_48;
          goto LAB_1c0002075;
        }
        pGVar8 = *(Gpadl **)pGVar11;
      } while (pGVar11[0x30] != (Gpadl)0x0);
      pGVar1 = *(GpadlSet **)(pGVar11 + 0x38);
      if (pGVar1 != (GpadlSet *)0x0) {
        *(undefined8 *)(pGVar11 + 0x38) = 0;
        if (*(GpadlSet ***)local_40 != &local_48) goto LAB_1c0002026;
        *(GpadlSet **)(pGVar1 + 8) = local_40;
        *(GpadlSet ***)pGVar1 = &local_48;
        *(GpadlSet **)local_40 = pGVar1;
        pGVar7 = local_40;
        local_40 = pGVar1;
      }
      bVar6 = RemoveGpadlIfUnreferenced(pGVar7,pGVar11,param_1);
    } while (!bVar6);
    if (*(Gpadl ***)local_30 != &local_38) break;
    *(Gpadl **)(pGVar11 + 8) = local_30;
    pGVar7 = (GpadlSet *)&local_38;
    *(GpadlSet **)pGVar11 = pGVar7;
    *(Gpadl **)local_30 = pGVar11;
    local_30 = pGVar11;
  }
LAB_1c0002026:
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  puVar9 = auStack_60;
  do {
    pGVar7 = *(GpadlSet **)pGVar10;
    if (pGVar10 != (GpadlSet *)0x0) {
      *(undefined8 *)(puVar9 + -8) = 0x1c0002041;
      MdlMapping::~MdlMapping((MdlMapping *)(pGVar10 + 0x20));
      lVar2 = *(longlong *)(pGVar10 + 0x18);
      *(undefined8 *)(pGVar10 + 0x18) = 0;
      if (lVar2 != 0) {
        *(undefined8 *)(puVar9 + -8) = 0x1c0002056;
        IoFreeMdl();
      }
      *(undefined8 *)(puVar9 + -8) = 0x1c0002064;
      wistd::
      unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
      ::
      ~unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
                ((unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
                  *)(pGVar10 + 0x10));
      *(undefined8 *)(puVar9 + -8) = 0x1c0002070;
      ExFreePoolWithTag(pGVar10,0);
    }
LAB_1c0002075:
    pGVar10 = pGVar7;
  } while (pGVar7 != (GpadlSet *)&local_48);
  local_40 = (GpadlSet *)&local_48;
  local_48 = (GpadlSet *)&local_48;
  pGVar8 = local_38;
  if (local_38 != (Gpadl *)&local_38) {
    do {
      pGVar11 = *(Gpadl **)pGVar8;
      if (pGVar8 != (Gpadl *)0x0) {
        *(undefined8 *)(puVar9 + -8) = 0x1c00020ae;
        Gpadl::~Gpadl(pGVar8);
        *(undefined8 *)(puVar9 + -8) = 0x1c00020ba;
        ExFreePoolWithTag(pGVar8,0);
      }
      pGVar8 = pGVar11;
    } while (pGVar11 != (Gpadl *)&local_38);
  }
  local_30 = (Gpadl *)&local_38;
  local_38 = (Gpadl *)&local_38;
  if (local_48 != (GpadlSet *)&local_48) {
    local_10 = 0;
    local_28 = (GpadlSet *)0x1c000c190;
    local_18 = 0x40;
    pcStack_20 = "ListHead::~ListHead";
    *(undefined8 *)(puVar9 + -8) = 0x1c0002116;
    OnFailure((ErrorSite *)&local_28,-0x3fffffff);
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(5);
  }
  return;
}



===== default_terminate_handler @ 1c0002140 =====

/* void __cdecl gsl::details::default_terminate_handler(void) */

void __cdecl gsl::details::default_terminate_handler(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(0);
  return;
}



===== reset @ 1c000214c =====

/* public: void __cdecl LockedGpadl::reset(void) __ptr64 */

void __thiscall LockedGpadl::reset(LockedGpadl *this)

{
  undefined8 ***local_18;
  undefined8 ***local_10;
  
  if (*(Gpadl **)(this + 8) != (Gpadl *)0x0) {
    local_10 = &local_18;
    local_18 = &local_18;
    GpadlSet::UnlockGpadl(*(GpadlSet **)this,*(Gpadl **)(this + 8),(CompletedIrps *)&local_18);
    *(undefined8 *)(this + 8) = 0;
    CompletedIrps::~CompletedIrps((CompletedIrps *)&local_18);
  }
  return;
}



===== terminate @ 1c0002198 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl gsl::details::terminate(void) */

void __cdecl gsl::details::terminate(void)

{
  (*(code *)`void_(__cdecl*&___ptr64___cdecl_gsl::details::get_terminate_handler(void))(void)'::__l2
            ::handler)();
  return;
}



===== unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_><1,void> @ 1c00021b4 =====

/* public: __cdecl wistd::unique_ptr<struct _MDL,struct wil::function_deleter<void (__cdecl*)(struct
   _MDL * __ptr64),&void __cdecl UnlockAndFreeMdl(struct _MDL * __ptr64)> >::unique_ptr<struct
   _MDL,struct wil::function_deleter<void (__cdecl*)(struct _MDL * __ptr64),&void __cdecl
   UnlockAndFreeMdl(struct _MDL * __ptr64)> ><1,void>(void) __ptr64 */

unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>
* __thiscall
wistd::
unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>
::
unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_><1,void>
          (unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>
           *this)

{
  *(undefined8 *)this = 0;
  return this;
}



===== operator()<NoType,VMBUS_PROXY_NEXT_ACTION_OUTPUT_*> @ 1c00021c4 =====

long <lambda_305d4803163db7a4809cf44b16b40368>::operator()<NoType,VMBUS_PROXY_NEXT_ACTION_OUTPUT_*>
               (longlong *param_1,ulonglong param_2,VMBUS_PROXY_NEXT_ACTION_OUTPUT *param_3)

{
  longlong lVar1;
  longlong lVar2;
  _IRP *p_Var3;
  bool bVar4;
  long lVar5;
  ulonglong local_res10;
  char *local_38;
  char *local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  lVar1 = *param_1;
  local_res10 = param_2;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(lVar1,0);
  lVar2 = *param_1;
  p_Var3 = *(_IRP **)param_1[1];
  if (*(char *)(lVar2 + 0x18) == '\0') {
    local_res10 = local_res10 & 0xffffffff00000000;
    bVar4 = VirtualMachine::FillNextActionIrp
                      ((VirtualMachine *)(lVar2 + 8),param_3,(long *)&local_res10);
    if (bVar4) {
      lVar5 = (long)local_res10;
      goto LAB_1c0002287;
    }
    lVar5 = CancellableIrp::Set((CancellableIrp *)(lVar2 + 0x28),p_Var3);
    if (-1 < lVar5) {
      lVar5 = 0x103;
      goto LAB_1c0002287;
    }
    local_28 = 0x22a;
  }
  else {
    local_28 = 0x224;
    lVar5 = -0x3ffffe7c;
  }
  local_20 = 0;
  local_38 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
  local_30 = "VirtualMachine::VmmIoctlNextAction";
  OnFailure((ErrorSite *)&local_38,lVar5);
LAB_1c0002287:
  if (lVar1 != 0) {
    ExReleasePushLockExclusiveEx(lVar1,0);
    KeLeaveCriticalRegion();
  }
  return lVar5;
}



===== operator()<NoType,_VMBUS_GET_NUMA_NODE_MAP_OUTPUT_PARAMETERS_*,gsl::span<unsigned_int,-1>,unsigned___int64_*> @ 1c00022c8 =====

undefined8
<lambda_e079101f3cc2ee249c4adfbda6baa925>::
operator()<NoType,_VMBUS_GET_NUMA_NODE_MAP_OUTPUT_PARAMETERS_*,gsl::span<unsigned_int,_1>,unsigned___int64_*>
          (longlong *param_1,undefined8 param_2,uint *param_3,ulonglong *param_4,longlong *param_5)

{
  longlong lVar1;
  char *pcVar2;
  uint uVar3;
  undefined8 uVar4;
  char *local_38;
  char *pcStack_30;
  undefined8 local_28;
  undefined8 local_20;
  
  lVar1 = *param_1;
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(lVar1,0);
  pcVar2 = (char *)*param_4;
  pcStack_30 = (char *)param_4[1];
  local_38 = pcVar2;
  uVar3 = DeviceGetTopology(*param_1,&local_38,param_3 + 1);
  *param_3 = uVar3;
  *param_5 = 8;
  if (pcVar2 < (char *)(ulonglong)uVar3) {
    local_20 = 0;
    local_38 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
    local_28 = 0x1a0;
    uVar4 = 0x80000005;
    pcStack_30 = "DeviceIoctlGetNumaNodeMap";
    OnFailure((ErrorSite *)&local_38,-0x7ffffffb);
  }
  else {
    uVar4 = 0;
    *param_5 = (longlong)(ulonglong)uVar3 * 4 + 8;
  }
  if (lVar1 != 0) {
    ExReleasePushLockSharedEx(lVar1,0);
    KeLeaveCriticalRegion();
  }
  return uVar4;
}



===== operator()<NoType,_VMBUS_GET_VM_NAME_OUTPUT_PARAMETERS_*,gsl::span<unsigned_short,-1>,unsigned___int64_*> @ 1c00023cc =====

undefined8
<lambda_4501a69042029aa06c84f308c71f00ba>::
operator()<NoType,_VMBUS_GET_VM_NAME_OUTPUT_PARAMETERS_*,gsl::span<unsigned_short,_1>,unsigned___int64_*>
          (longlong *param_1,undefined8 param_2,undefined4 *param_3,ulonglong *param_4,
          longlong *param_5)

{
  longlong lVar1;
  longlong lVar2;
  void *_Src;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  ushort uVar7;
  char *pcVar8;
  undefined8 uVar9;
  char *local_28;
  char *pcStack_20;
  undefined8 local_18;
  undefined8 local_10;
  
  lVar1 = *param_1;
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(lVar1,0);
  local_28 = (char *)*param_4;
  pcStack_20 = (char *)param_4[1];
  lVar2 = *param_1;
  uVar3 = *(undefined4 *)(lVar2 + 0x40);
  uVar4 = *(undefined4 *)(lVar2 + 0x44);
  uVar5 = *(undefined4 *)(lVar2 + 0x48);
  uVar6 = *(undefined4 *)(lVar2 + 0x4c);
  *param_5 = 0x14;
  *param_3 = uVar3;
  param_3[1] = uVar4;
  param_3[2] = uVar5;
  param_3[3] = uVar6;
  uVar7 = *(ushort *)(lVar2 + 0x30) >> 1;
  pcVar8 = (char *)(ulonglong)uVar7;
  *(ushort *)(param_3 + 4) = uVar7;
  if (local_28 < pcVar8) {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
    local_18 = 500;
    uVar9 = 0x80000005;
    pcStack_20 = "VirtualMachine::DeviceIoctlGetVmName";
    OnFailure((ErrorSite *)&local_28,-0x7ffffffb);
LAB_1c00024d5:
    if (lVar1 != 0) {
      ExReleasePushLockSharedEx(lVar1,0);
      KeLeaveCriticalRegion();
    }
    return uVar9;
  }
  _Src = *(void **)(lVar2 + 0x38);
  if ((((_Src != (void *)0x0) || (pcVar8 == (char *)0x0)) && (pcVar8 <= local_28)) &&
     ((_Src != (void *)0x0 || (pcVar8 == (char *)0x0)))) {
    if ((((pcStack_20 != (char *)0x0) || ((char *)((longlong)local_28 * 2) == (char *)0x0)) &&
        (pcVar8 <= (char *)((longlong)local_28 * 2))) &&
       ((pcStack_20 != (char *)0x0 || (pcVar8 == (char *)0x0)))) {
      memcpy(pcStack_20,_Src,(longlong)pcVar8 * 2);
      *param_5 = (ulonglong)*(ushort *)(lVar2 + 0x30) + 0x14;
      uVar9 = 0;
      goto LAB_1c00024d5;
    }
  }
                    /* WARNING: Subroutine does not return */
  gsl::details::terminate();
}



===== operator()<NoType,_VMBUS_QUERY_SERVER_OPEN_CHANNEL_OUTPUT_PARAMETERS_*> @ 1c000251c =====

long <lambda_d37032be05a81cbc0febac5b1628d321>::
     operator()<NoType,_VMBUS_QUERY_SERVER_OPEN_CHANNEL_OUTPUT_PARAMETERS_*>
               (longlong *param_1,undefined8 param_2,undefined8 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  longlong lVar3;
  code *pcVar4;
  long lVar5;
  longlong lVar6;
  undefined1 *puVar7;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  lVar3 = *param_1;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(lVar3,0);
  puVar7 = auStack_48;
  lVar6 = *(longlong *)param_1[1];
  iVar1 = *(int *)(lVar6 + 0x20);
  if (iVar1 == 0) {
LAB_1c000263b:
    local_18 = 0x18c;
    local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
    lVar5 = -0x3ffffe7c;
    local_20 = "VirtualMachine::DeviceIoctlWaitForOpenChannel";
    local_10 = "%d";
    OnFailure((ErrorSite *)&local_28,-0x3ffffe7c);
    puVar7 = auStack_48;
  }
  else {
    if ((iVar1 == 1) || (iVar1 == 2)) {
      lVar5 = CancellableIrp::Set((CancellableIrp *)(lVar6 + 0x60),*(_IRP **)param_1[2]);
      puVar7 = auStack_48;
      if (lVar5 < 0) {
        local_10 = (char *)0x0;
        local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
        local_18 = 0x182;
        local_20 = "VirtualMachine::DeviceIoctlWaitForOpenChannel";
        OnFailure((ErrorSite *)&local_28,lVar5);
        puVar7 = auStack_48;
      }
      else {
        lVar5 = 0x103;
      }
      goto LAB_1c0002674;
    }
    if (iVar1 != 3) {
      if ((iVar1 == 4) || (iVar1 == 5)) goto LAB_1c000263b;
      local_18 = 0x191;
      local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
      lVar6 = 0xc0000001;
      local_20 = "VirtualMachine::DeviceIoctlWaitForOpenChannel";
      local_10 = "%d";
      OnFailure((ErrorSite *)&local_28,-0x3fffffff);
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(5);
      puVar7 = auStack_40;
    }
    lVar5 = 0;
    uVar2 = *(undefined4 *)(lVar6 + 0x120);
    *param_3 = *(undefined8 *)(lVar6 + 0x118);
    *(undefined4 *)(param_3 + 1) = uVar2;
  }
LAB_1c0002674:
  if (lVar3 != 0) {
    *(undefined8 *)(puVar7 + -8) = 0x1c0002685;
    ExReleasePushLockExclusiveEx(lVar3,0);
    *(undefined8 *)(puVar7 + -8) = 0x1c0002691;
    KeLeaveCriticalRegion();
  }
  return lVar5;
}



===== operator()<NoType,_VMBUS_WAIT_FOR_ACTION_OUTPUT_PARAMETERS_*> @ 1c00026b4 =====

long <lambda_5cd53e81c4e19984027c507a00544d2d>::
     operator()<NoType,_VMBUS_WAIT_FOR_ACTION_OUTPUT_PARAMETERS_*>
               (longlong *param_1,undefined8 param_2,undefined4 *param_3)

{
  CancellableIrp *this;
  int iVar1;
  longlong lVar2;
  code *pcVar3;
  long lVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  lVar2 = *param_1;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(lVar2,0);
  puVar6 = auStack_48;
  puVar5 = auStack_48;
  this = (CancellableIrp *)(*(longlong *)param_1[1] + 0x58);
  if (*(longlong *)this == 0) {
    iVar1 = *(int *)(*(longlong *)param_1[1] + 0x20);
    if (iVar1 == 0) {
      local_18 = 0x11b;
      goto LAB_1c00027b8;
    }
    if ((iVar1 != 1) && (iVar1 != 2)) {
      if (iVar1 == 3) {
        *param_3 = 1;
      }
      else {
        if (iVar1 == 4) goto LAB_1c0002791;
        if (iVar1 != 5) {
          local_18 = 0x12e;
          local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
          local_20 = "VirtualMachine::DeviceIoctlWaitForAction";
          local_10 = "%d";
          OnFailure((ErrorSite *)&local_28,-0x3fffffff);
          pcVar3 = (code *)swi(0x29);
          (*pcVar3)(5);
          puVar5 = auStack_40;
        }
        *param_3 = 3;
        puVar6 = puVar5;
      }
      lVar4 = 0;
      goto LAB_1c00027e3;
    }
LAB_1c0002791:
    lVar4 = CancellableIrp::Set(this,*(_IRP **)param_1[2]);
    puVar6 = auStack_48;
    if (-1 < lVar4) {
      lVar4 = 0x103;
      goto LAB_1c00027e3;
    }
    local_18 = 0x120;
  }
  else {
    local_18 = 0x115;
LAB_1c00027b8:
    lVar4 = -0x3ffffe7c;
  }
  local_10 = (char *)0x0;
  local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
  local_20 = "VirtualMachine::DeviceIoctlWaitForAction";
  OnFailure((ErrorSite *)&local_28,lVar4);
  puVar6 = auStack_48;
LAB_1c00027e3:
  if (lVar2 != 0) {
    *(undefined8 *)(puVar6 + -8) = 0x1c00027f4;
    ExReleasePushLockExclusiveEx(lVar2,0);
    *(undefined8 *)(puVar6 + -8) = 0x1c0002800;
    KeLeaveCriticalRegion();
  }
  return lVar4;
}



===== operator()<VMBUS_PROXY_CLOSE_CHANNEL_INPUT,NoType_*> @ 1c0002824 =====

long <lambda_2534b7c851bf1eb982eb495919bcf656>::operator()<VMBUS_PROXY_CLOSE_CHANNEL_INPUT,NoType_*>
               (longlong *param_1,longlong *param_2)

{
  int iVar1;
  longlong lVar2;
  _IRP *p_Var3;
  code *pcVar4;
  Channel *pCVar5;
  long lVar6;
  Channel *pCVar7;
  Channel *pCVar8;
  undefined1 *puVar9;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  lVar2 = *param_1;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(lVar2,0);
  pCVar8 = (Channel *)(*param_1 + 8);
  p_Var3 = *(_IRP **)param_1[1];
  if (*(char *)(*param_1 + 0x18) == '\0') {
    pCVar5 = *(Channel **)pCVar8;
    do {
      pCVar7 = pCVar5;
      if (pCVar7 == pCVar8) {
        local_18 = 0x29b;
        local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
        lVar6 = -0x3ffffddb;
        local_20 = "VirtualMachine::VmmIoctlCloseChannel";
        local_10 = "%lld";
        OnFailure((ErrorSite *)&local_28,-0x3ffffddb);
        puVar9 = auStack_48;
        goto LAB_1c0002904;
      }
      pCVar5 = *(Channel **)pCVar7;
    } while (*(longlong *)(pCVar7 + 0x10) != *param_2);
    iVar1 = *(int *)(pCVar7 + 0x20);
    if ((((iVar1 != 0) && (iVar1 != 1)) && (iVar1 != 2)) && (iVar1 != 3)) {
      if (iVar1 == 4) {
        VirtualMachine::VmmCloseChannel((VirtualMachine *)0x0,pCVar7,(CompletedIrps *)param_1[2]);
        lVar6 = CancellableIrp::Set((CancellableIrp *)(pCVar7 + 0x50),p_Var3);
        puVar9 = auStack_48;
        if (-1 < lVar6) {
          lVar6 = 0x103;
          goto LAB_1c0002904;
        }
        local_18 = 0x2b7;
        goto LAB_1c000288a;
      }
      if (iVar1 != 5) {
        puVar9 = auStack_48;
        if ((iVar1 != 6) && (puVar9 = auStack_48, iVar1 != 7)) {
          local_18 = 0x2b1;
          local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
          local_20 = "VirtualMachine::VmmIoctlCloseChannel";
          local_10 = "%d";
          OnFailure((ErrorSite *)&local_28,-0x3fffffff);
          pcVar4 = (code *)swi(0x29);
          (*pcVar4)(5);
          puVar9 = auStack_40;
        }
        lVar6 = 0;
        goto LAB_1c0002904;
      }
    }
    local_18 = 0x2a3;
    local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
    lVar6 = -0x3ffffe7c;
    local_20 = "VirtualMachine::VmmIoctlCloseChannel";
    local_10 = "%d";
    OnFailure((ErrorSite *)&local_28,-0x3ffffe7c);
    puVar9 = auStack_48;
  }
  else {
    local_18 = 0x297;
    lVar6 = -0x3ffffe7c;
LAB_1c000288a:
    puVar9 = auStack_48;
    local_10 = (char *)0x0;
    local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
    local_20 = "VirtualMachine::VmmIoctlCloseChannel";
    OnFailure((ErrorSite *)&local_28,lVar6);
  }
LAB_1c0002904:
  if (lVar2 != 0) {
    *(undefined8 *)(puVar9 + -8) = 0x1c0002915;
    ExReleasePushLockExclusiveEx(lVar2,0);
    *(undefined8 *)(puVar9 + -8) = 0x1c0002921;
    KeLeaveCriticalRegion();
  }
  return lVar6;
}



===== operator()<VMBUS_PROXY_DELETE_GPADL_INPUT,NoType_*> @ 1c0002a44 =====

long <lambda_534c481228def1137ccbf02780086789>::operator()<VMBUS_PROXY_DELETE_GPADL_INPUT,NoType_*>
               (longlong *param_1,longlong *param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  long lVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  lVar1 = *param_1;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(lVar1,0);
  puVar5 = (undefined8 *)(*param_1 + 8);
  if (*(char *)(*param_1 + 0x18) == '\0') {
    puVar2 = (undefined8 *)*puVar5;
    do {
      puVar4 = puVar2;
      if (puVar4 == puVar5) {
        local_18 = 0x30d;
        local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
        lVar3 = -0x3ffffddb;
        local_20 = "VirtualMachine::VmmIoctlDeleteGpadl";
        local_10 = "%lld";
        OnFailure((ErrorSite *)&local_28,-0x3ffffddb);
        goto LAB_1c0002b20;
      }
      puVar2 = (undefined8 *)*puVar4;
    } while (puVar4[2] != *param_2);
    lVar3 = GpadlSet::DeleteGpadl
                      ((GpadlSet *)(puVar4 + 5),*(uint *)(param_2 + 1),*(_IRP **)param_1[1],
                       (CompletedIrps *)param_1[2]);
    if (-1 < lVar3) goto LAB_1c0002b20;
    local_18 = 0x311;
  }
  else {
    local_18 = 0x309;
    lVar3 = -0x3ffffe7c;
  }
  local_10 = (char *)0x0;
  local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
  local_20 = "VirtualMachine::VmmIoctlDeleteGpadl";
  OnFailure((ErrorSite *)&local_28,lVar3);
LAB_1c0002b20:
  if (lVar1 != 0) {
    ExReleasePushLockExclusiveEx(lVar1,0);
    KeLeaveCriticalRegion();
  }
  return lVar3;
}



===== operator()<VMBUS_PROXY_RELEASE_CHANNEL_INPUT,NoType_*> @ 1c0002b84 =====

undefined8
<lambda_708f653bac9273f243cdb8e8799c810c>::operator()<VMBUS_PROXY_RELEASE_CHANNEL_INPUT,NoType_*>
          (longlong *param_1,longlong *param_2)

{
  longlong lVar1;
  Channel *pCVar2;
  Channel *pCVar3;
  VirtualMachine *this;
  undefined8 uVar4;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  lVar1 = *param_1;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(lVar1,0);
  this = (VirtualMachine *)(*param_1 + 8);
  pCVar2 = *(Channel **)this;
  do {
    pCVar3 = pCVar2;
    if (pCVar3 == (Channel *)this) {
      local_18 = 0x2bf;
      local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
      uVar4 = 0xc0000225;
      local_20 = "VirtualMachine::VmmIoctlReleaseChannel";
      local_10 = "%lld";
      OnFailure((ErrorSite *)&local_28,-0x3ffffddb);
      goto LAB_1c0002c1a;
    }
    pCVar2 = *(Channel **)pCVar3;
  } while (*(longlong *)(pCVar3 + 0x10) != *param_2);
  if (*(int *)(pCVar3 + 0x20) == 7) {
    VirtualMachine::DeleteChannel(this,pCVar3);
    uVar4 = 0;
  }
  else {
    local_18 = 0x2c2;
    local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
    uVar4 = 0xc0000184;
    local_20 = "VirtualMachine::VmmIoctlReleaseChannel";
    local_10 = "%d";
    OnFailure((ErrorSite *)&local_28,-0x3ffffe7c);
  }
LAB_1c0002c1a:
  if (lVar1 != 0) {
    ExReleasePushLockExclusiveEx(lVar1,0);
    KeLeaveCriticalRegion();
  }
  return uVar4;
}



===== operator()<VMBUS_PROXY_SET_MEMORY_INPUT,NoType_*> @ 1c0002cac =====

undefined8
<lambda_c12b423d71a5f7bb004a4b40fec0c8b9>::operator()<VMBUS_PROXY_SET_MEMORY_INPUT,NoType_*>
          (longlong *param_1,ulonglong *param_2,longlong param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  longlong local_res18;
  _EX_PUSH_LOCK local_res20 [8];
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  uVar1 = param_2[1];
  local_res18 = param_3;
  if ((uVar1 != 0) && ((*param_2 & 0xfff) != 0)) {
                    /* WARNING: Subroutine does not return */
    ExRaiseDatatypeMisalignment();
  }
  if ((uVar1 & 0xfff) == 0) {
    uVar4 = 0;
    if (uVar1 != 0) {
      PsGetCurrentProcess();
      puVar5 = (undefined8 *)ReferenceObObject<_EPROCESS>((_EPROCESS *)&local_res18);
      lVar2 = local_res18;
      uVar4 = *puVar5;
      *puVar5 = 0;
      local_res18 = 0;
      if (lVar2 != 0) {
        ObfDereferenceObject();
      }
    }
    util::AcquireExclusiveLock(local_res20);
    lVar2 = *param_1;
    *(ulonglong *)(lVar2 + 0x68) = *param_2;
    *(ulonglong *)(lVar2 + 0x70) = param_2[1];
    lVar3 = *(longlong *)(lVar2 + 0x60);
    *(undefined8 *)(lVar2 + 0x60) = uVar4;
    if (lVar3 != 0) {
      ObfDereferenceObject();
    }
    wil::
    unique_any_t<wil::details::unique_storage<wil::details::resource_policy<_EX_PUSH_LOCK*___ptr64,void_(__cdecl*)(_EX_PUSH_LOCK*___ptr64),&void___cdecl_util::ReleaseExclusiveLock(struct__EX_PUSH_LOCK*___ptr64),wistd::integral_constant<unsigned___int64,2>,_EX_PUSH_LOCK*___ptr64,_EX_PUSH_LOCK*___ptr64,0,std::nullptr_t>_>_>
    ::
    ~unique_any_t<wil::details::unique_storage<wil::details::resource_policy<_EX_PUSH_LOCK*___ptr64,void_(__cdecl*)(_EX_PUSH_LOCK*___ptr64),&void___cdecl_util::ReleaseExclusiveLock(struct__EX_PUSH_LOCK*___ptr64),wistd::integral_constant<unsigned___int64,2>,_EX_PUSH_LOCK*___ptr64,_EX_PUSH_LOCK*___ptr64,0,std::nullptr_t>_>_>
              ((unique_any_t<wil::details::unique_storage<wil::details::resource_policy<_EX_PUSH_LOCK*___ptr64,void_(__cdecl*)(_EX_PUSH_LOCK*___ptr64),&void___cdecl_util::ReleaseExclusiveLock(struct__EX_PUSH_LOCK*___ptr64),wistd::integral_constant<unsigned___int64,2>,_EX_PUSH_LOCK*___ptr64,_EX_PUSH_LOCK*___ptr64,0,std::nullptr_t>_>_>
                *)local_res20);
    uVar4 = 0;
  }
  else {
    local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
    local_20 = "HandleIrpIoctl::<lambda_c12b423d71a5f7bb004a4b40fec0c8b9>::operator ()";
    local_18 = 0x2a9;
    local_10 = 0;
    OnFailure((ErrorSite *)&local_28,-0x3ffffff3);
    uVar4 = 0xc000000d;
  }
  return uVar4;
}



===== operator()<VMBUS_PROXY_SET_TOPOLOGY_INPUT,NoType_*> @ 1c0002e24 =====

long <lambda_c5b71ad1e55191db30ad3e5708db9c67>::operator()<VMBUS_PROXY_SET_TOPOLOGY_INPUT,NoType_*>
               (longlong *param_1,uint *param_2)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auVar4 [16];
  undefined1 uVar5;
  __uint64 _Var6;
  void *pvVar7;
  long lVar8;
  char *local_48;
  undefined8 uStack_40;
  char *local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 local_20;
  
  lVar2 = *param_1;
  pcVar1 = *(char **)param_1[1];
  uStack_40 = (char *)((ulonglong *)param_1[1])[1];
  local_48 = pcVar1;
  if ((pcVar1 < (char *)(ulonglong)param_2[2]) ||
     ((ulonglong)((longlong)pcVar1 - (longlong)(ulonglong)param_2[2]) >> 2 < CONCAT44(0,*param_2)))
  {
    local_28 = 0x16b;
    lVar8 = -0x3ffffff3;
  }
  else {
    auVar4._8_8_ = 0;
    auVar4._0_8_ = CONCAT44(0,*param_2);
    _Var6 = SUB168(ZEXT816(4) * auVar4,0);
    if (SUB168(ZEXT816(4) * auVar4,8) != 0) {
      _Var6 = 0xffffffffffffffff;
    }
    pvVar7 = operator_new(_Var6);
    if (pvVar7 != (void *)0x0) {
      uStack_30 = (char *)(ulonglong)param_2[2];
      local_38 = (char *)((ulonglong)*param_2 << 2);
      if ((pcVar1 < uStack_30) || (pcVar1 + -(longlong)uStack_30 < local_38)) {
                    /* WARNING: Subroutine does not return */
        gsl::details::terminate();
      }
      uStack_30 = uStack_30 + (longlong)uStack_40;
      local_48 = local_38;
      uStack_40 = pvVar7;
      gsl::copy<gsl::byte_const_,_1,gsl::byte,_1>(&local_38,&local_48);
      pcVar1 = (char *)(lVar2 + 0x78);
      uVar5 = KeAcquireSpinLockRaiseToDpc(pcVar1);
      lVar3 = *(longlong *)(lVar2 + 0x88);
      uStack_40 = (char *)CONCAT17(uStack_30._7_1_,
                                   CONCAT25(uStack_30._5_2_,CONCAT41(uStack_30._1_4_,uVar5)));
      *(uint *)(lVar2 + 0x80) = param_2[1];
      *(uint *)(lVar2 + 0x84) = *param_2;
      *(void **)(lVar2 + 0x88) = pvVar7;
      local_48 = pcVar1;
      if (pcVar1 != (char *)0x0) {
        uStack_30 = uStack_40;
        local_38 = pcVar1;
        wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_38);
      }
      if (lVar3 == 0) {
        return 0;
      }
      ExFreePoolWithTag(lVar3,0);
      return 0;
    }
    lVar8 = -0x3fffff66;
    local_28 = 0x171;
  }
  local_20 = 0;
  local_38 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
  uStack_30 = "VmmIoctlSetTopology";
  OnFailure((ErrorSite *)&local_38,lVar8);
  return lVar8;
}



===== HandleIoctl<NoType,VMBUS_PROXY_NEXT_ACTION_OUTPUT,<lambda_305d4803163db7a4809cf44b16b40368>_> @ 1c0002fec =====

uint HandleIoctl<NoType,VMBUS_PROXY_NEXT_ACTION_OUTPUT,<lambda_305d4803163db7a4809cf44b16b40368>_>
               (longlong param_1,longlong *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  char *local_f8;
  char *pcStack_f0;
  undefined8 local_e8;
  undefined8 local_e0;
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
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  if (*(ulonglong *)(param_1 + 0x10) < 0xd0) {
    local_e0 = 0;
    local_f8 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
    local_e8 = 0x1c1;
    pcStack_f0 = "HandleIoctl";
    OnFailure((ErrorSite *)&local_f8,-0x3fffffdd);
    uVar1 = 0xc0000023;
  }
  else {
    uVar2 = 0;
    memset(&local_d8,0,0xd0);
    uVar1 = <lambda_305d4803163db7a4809cf44b16b40368>::
            operator()<NoType,VMBUS_PROXY_NEXT_ACTION_OUTPUT_*>
                      (param_2,uVar2,(VMBUS_PROXY_NEXT_ACTION_OUTPUT *)&local_d8);
    if ((uVar1 & 0xc0000000) != 0xc0000000) {
      local_f8 = *(char **)(param_1 + 0x10);
      pcStack_f0 = *(char **)(param_1 + 0x18);
      if (local_f8 < 0xd0) {
                    /* WARNING: Subroutine does not return */
        gsl::details::terminate();
      }
      *(undefined8 *)pcStack_f0 = local_d8;
      *(undefined8 *)((longlong)pcStack_f0 + 8) = uStack_d0;
      *(undefined8 *)((longlong)pcStack_f0 + 0x10) = local_c8;
      *(undefined8 *)((longlong)pcStack_f0 + 0x18) = uStack_c0;
      *(undefined8 *)((longlong)pcStack_f0 + 0x20) = local_b8;
      *(undefined8 *)((longlong)pcStack_f0 + 0x28) = uStack_b0;
      *(undefined8 *)((longlong)pcStack_f0 + 0x30) = local_a8;
      *(undefined8 *)((longlong)pcStack_f0 + 0x38) = uStack_a0;
      *(undefined8 *)((longlong)pcStack_f0 + 0x40) = local_98;
      *(undefined8 *)((longlong)pcStack_f0 + 0x48) = uStack_90;
      *(undefined8 *)((longlong)pcStack_f0 + 0x50) = local_88;
      *(undefined8 *)((longlong)pcStack_f0 + 0x58) = uStack_80;
      *(undefined8 *)((longlong)pcStack_f0 + 0x60) = local_78;
      *(undefined8 *)((longlong)pcStack_f0 + 0x68) = uStack_70;
      *(undefined8 *)((longlong)pcStack_f0 + 0x70) = local_68;
      *(undefined8 *)((longlong)pcStack_f0 + 0x78) = uStack_60;
      *(undefined8 *)((longlong)pcStack_f0 + 0x80) = local_58;
      *(undefined8 *)((longlong)pcStack_f0 + 0x88) = uStack_50;
      *(undefined8 *)((longlong)pcStack_f0 + 0x90) = local_48;
      *(undefined8 *)((longlong)pcStack_f0 + 0x98) = uStack_40;
      *(undefined8 *)((longlong)pcStack_f0 + 0xa0) = local_38;
      *(undefined8 *)((longlong)pcStack_f0 + 0xa8) = uStack_30;
      *(undefined8 *)((longlong)pcStack_f0 + 0xb0) = local_28;
      *(undefined8 *)((longlong)pcStack_f0 + 0xb8) = uStack_20;
      *(undefined8 *)((longlong)pcStack_f0 + 0xc0) = local_18;
      *(undefined8 *)((longlong)pcStack_f0 + 200) = uStack_10;
      **(undefined8 **)(param_1 + 0x20) = 0xd0;
    }
  }
  return uVar1;
}



===== HandleIoctl<NoType,_VMBUS_GET_NUMA_NODE_MAP_OUTPUT_PARAMETERS,unsigned_int,8,<lambda_e079101f3cc2ee249c4adfbda6baa925>_> @ 1c000313c =====

undefined8
HandleIoctl<NoType,_VMBUS_GET_NUMA_NODE_MAP_OUTPUT_PARAMETERS,unsigned_int,8,<lambda_e079101f3cc2ee249c4adfbda6baa925>_>
          (longlong param_1,longlong *param_2)

{
  undefined8 uVar1;
  longlong local_res8;
  ulonglong local_38;
  longlong local_30;
  char *local_28;
  uint *puStack_20;
  undefined8 local_18;
  undefined8 local_10;
  
  if (*(ulonglong *)(param_1 + 0x10) < 8) {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
    local_18 = 0x1e9;
    puStack_20 = (uint *)0x1c000c588;
    OnFailure((ErrorSite *)&local_28,-0x3fffffdd);
    return 0xc0000023;
  }
  local_28 = *(char **)(param_1 + 0x10);
  puStack_20 = *(uint **)(param_1 + 0x18);
  local_res8 = 0;
  if ((7 < local_28) &&
     (local_38 = *(ulonglong *)(param_1 + 0x10) - 8, local_38 != 0xffffffffffffffff)) {
    local_38 = local_38 >> 2;
    local_30 = *(longlong *)(param_1 + 0x18) + 8;
    if ((local_30 != 0) || (local_38 == 0)) {
      uVar1 = <lambda_e079101f3cc2ee249c4adfbda6baa925>::
              operator()<NoType,_VMBUS_GET_NUMA_NODE_MAP_OUTPUT_PARAMETERS_*,gsl::span<unsigned_int,_1>,unsigned___int64_*>
                        (param_2,param_2,puStack_20,&local_38,&local_res8);
      if (((uint)uVar1 & 0xc0000000) == 0xc0000000) {
        return uVar1;
      }
      **(longlong **)(param_1 + 0x20) = local_res8;
      return uVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  gsl::details::terminate();
}



===== HandleIoctl<NoType,_VMBUS_GET_VM_NAME_OUTPUT_PARAMETERS,unsigned_short,20,<lambda_4501a69042029aa06c84f308c71f00ba>_> @ 1c0003214 =====

undefined8
HandleIoctl<NoType,_VMBUS_GET_VM_NAME_OUTPUT_PARAMETERS,unsigned_short,20,<lambda_4501a69042029aa06c84f308c71f00ba>_>
          (longlong param_1,longlong *param_2)

{
  undefined8 uVar1;
  longlong local_res8;
  ulonglong local_38;
  longlong local_30;
  char *local_28;
  char *pcStack_20;
  undefined8 local_18;
  undefined8 local_10;
  
  if (*(ulonglong *)(param_1 + 0x10) < 0x14) {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
    local_18 = 0x1e9;
    pcStack_20 = "HandleIoctl";
    OnFailure((ErrorSite *)&local_28,-0x3fffffdd);
    return 0xc0000023;
  }
  local_28 = *(char **)(param_1 + 0x10);
  pcStack_20 = *(char **)(param_1 + 0x18);
  local_res8 = 0;
  if ((0x13 < local_28) &&
     (local_38 = *(ulonglong *)(param_1 + 0x10) - 0x14, local_38 != 0xffffffffffffffff)) {
    local_38 = local_38 >> 1;
    local_30 = *(longlong *)(param_1 + 0x18) + 0x14;
    if ((local_30 != 0) || (local_38 == 0)) {
      uVar1 = <lambda_4501a69042029aa06c84f308c71f00ba>::
              operator()<NoType,_VMBUS_GET_VM_NAME_OUTPUT_PARAMETERS_*,gsl::span<unsigned_short,_1>,unsigned___int64_*>
                        (param_2,param_2,(undefined4 *)pcStack_20,&local_38,&local_res8);
      if (((uint)uVar1 & 0xc0000000) == 0xc0000000) {
        return uVar1;
      }
      **(longlong **)(param_1 + 0x20) = local_res8;
      return uVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  gsl::details::terminate();
}



===== HandleIoctl<NoType,_VMBUS_QUERY_SERVER_OPEN_CHANNEL_OUTPUT_PARAMETERS,<lambda_d37032be05a81cbc0febac5b1628d321>_> @ 1c00032ec =====

uint HandleIoctl<NoType,_VMBUS_QUERY_SERVER_OPEN_CHANNEL_OUTPUT_PARAMETERS,<lambda_d37032be05a81cbc0febac5b1628d321>_>
               (longlong param_1,longlong *param_2)

{
  uint uVar1;
  undefined8 local_38;
  undefined4 local_30;
  char *local_28;
  char *pcStack_20;
  undefined8 local_18;
  undefined8 local_10;
  
  if (*(ulonglong *)(param_1 + 0x10) < 0xc) {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
    local_18 = 0x1c1;
    pcStack_20 = "HandleIoctl";
    OnFailure((ErrorSite *)&local_28,-0x3fffffdd);
    uVar1 = 0xc0000023;
  }
  else {
    local_38 = 0;
    local_30 = 0;
    uVar1 = <lambda_d37032be05a81cbc0febac5b1628d321>::
            operator()<NoType,_VMBUS_QUERY_SERVER_OPEN_CHANNEL_OUTPUT_PARAMETERS_*>
                      (param_2,param_2,&local_38);
    if ((uVar1 & 0xc0000000) != 0xc0000000) {
      local_28 = *(char **)(param_1 + 0x10);
      pcStack_20 = *(char **)(param_1 + 0x18);
      if (local_28 < 0xc) {
                    /* WARNING: Subroutine does not return */
        gsl::details::terminate();
      }
      *(undefined8 *)pcStack_20 = local_38;
      *(undefined4 *)((longlong)pcStack_20 + 8) = local_30;
      **(undefined8 **)(param_1 + 0x20) = 0xc;
    }
  }
  return uVar1;
}



===== HandleIoctl<VMBUS_PROXY_CREATE_GPADL_INPUT,NoType,<lambda_37a5d9f66724ef97eeae3c943e8c43d2>_> @ 1c00033a8 =====

long HandleIoctl<VMBUS_PROXY_CREATE_GPADL_INPUT,NoType,<lambda_37a5d9f66724ef97eeae3c943e8c43d2>_>
               (ulonglong *param_1,longlong *param_2)

{
  longlong lVar1;
  long lVar2;
  ulonglong local_38;
  undefined8 *puStack_30;
  char *local_28;
  char *pcStack_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_38 = *param_1;
  puStack_30 = (undefined8 *)param_1[1];
  if ((local_38 < 0x18) || (puStack_30 == (undefined8 *)0x0)) {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
    local_18 = 0x1cb;
    pcStack_20 = "HandleIoctl";
    OnFailure((ErrorSite *)&local_28,-0x3ffffff3);
    lVar2 = -0x3ffffff3;
  }
  else {
    local_28 = (char *)*puStack_30;
    pcStack_20 = (char *)puStack_30[1];
    lVar1 = *param_2;
    local_18 = puStack_30[2];
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(lVar1,0);
    local_38 = *(ulonglong *)param_2[1];
    puStack_30 = (undefined8 *)((ulonglong *)param_2[1])[1];
    lVar2 = VirtualMachine::VmmIoctlCreateGpadl
                      ((VirtualMachine *)(*param_2 + 8),&local_28,&local_38);
    if (lVar1 != 0) {
      ExReleasePushLockExclusiveEx(lVar1,0);
      KeLeaveCriticalRegion();
    }
  }
  return lVar2;
}



===== HandleIoctl<VMBUS_PROXY_OPEN_CHANNEL_INPUT,VMBUS_PROXY_OPEN_CHANNEL_OUTPUT,<lambda_4ea790c742a4f2601e266a1c389fc768>_> @ 1c00034a0 =====

uint HandleIoctl<VMBUS_PROXY_OPEN_CHANNEL_INPUT,VMBUS_PROXY_OPEN_CHANNEL_OUTPUT,<lambda_4ea790c742a4f2601e266a1c389fc768>_>
               (ulonglong *param_1,longlong *param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  uint uVar3;
  undefined4 local_res8 [2];
  char *local_28;
  char *pcStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  if (param_1[2] < 4) {
    local_18 = 0x1c1;
    uVar3 = 0xc0000023;
  }
  else {
    puVar2 = (undefined8 *)param_1[1];
    if ((0x1f < *param_1) && (puVar2 != (undefined8 *)0x0)) {
      local_28 = (char *)*puVar2;
      pcStack_20 = (char *)puVar2[1];
      local_res8[0] = 0;
      local_18 = puVar2[2];
      uStack_10 = puVar2[3];
      lVar1 = *param_2;
      KeEnterCriticalRegion();
      ExAcquirePushLockExclusiveEx(lVar1,0);
      uVar3 = VirtualMachine::VmmIoctlOpenChannel
                        ((VirtualMachine *)(*param_2 + 8),*(_IRP **)param_2[1],
                         (VMBUS_PROXY_OPEN_CHANNEL_INPUT *)&local_28,
                         (VMBUS_PROXY_OPEN_CHANNEL_OUTPUT *)local_res8,(CompletedIrps *)param_2[2]);
      if (lVar1 != 0) {
        ExReleasePushLockExclusiveEx(lVar1,0);
        KeLeaveCriticalRegion();
      }
      if ((uVar3 & 0xc0000000) != 0xc0000000) {
        local_28 = (char *)param_1[2];
        pcStack_20 = (char *)param_1[3];
        if (local_28 < 4) {
                    /* WARNING: Subroutine does not return */
          gsl::details::terminate();
        }
        *(undefined4 *)pcStack_20 = local_res8[0];
        *(undefined8 *)param_1[4] = 4;
      }
      return uVar3;
    }
    local_18 = 0x1cb;
    uVar3 = 0xc000000d;
  }
  uStack_10 = 0;
  local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
  pcStack_20 = "HandleIoctl";
  OnFailure((ErrorSite *)&local_28,uVar3);
  return uVar3;
}



===== HandleIoctl<VMBUS_PROXY_RUN_CHANNEL_INPUT,NoType,<lambda_da8b075cbd03c62461b6f689aff894a4>_> @ 1c0003604 =====

long HandleIoctl<VMBUS_PROXY_RUN_CHANNEL_INPUT,NoType,<lambda_da8b075cbd03c62461b6f689aff894a4>_>
               (ulonglong *param_1,longlong *param_2)

{
  longlong lVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 *puVar4;
  long lVar5;
  undefined8 *puVar6;
  WorkQueue *this;
  undefined1 *puVar7;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  char *local_28;
  longlong *plStack_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_28 = (char *)*param_1;
  plStack_20 = (longlong *)param_1[1];
  lVar5 = 0;
  if ((local_28 < 8) || (plStack_20 == (longlong *)0x0)) {
    local_18 = 0x1cb;
    local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
    local_10 = 0;
    plStack_20 = (longlong *)0x1c000c588;
    OnFailure((ErrorSite *)&local_28,-0x3ffffff3);
    lVar5 = -0x3ffffff3;
  }
  else {
    lVar1 = *plStack_20;
    lVar2 = *param_2;
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(lVar2,0);
    puVar7 = auStack_48;
    puVar4 = *(undefined8 **)(*param_2 + 8);
    do {
      puVar6 = puVar4;
      if (puVar6 == (undefined8 *)(*param_2 + 8)) {
        this = (WorkQueue *)0x0;
        puVar7 = auStack_48;
        goto LAB_1c0003686;
      }
      puVar4 = (undefined8 *)*puVar6;
    } while (puVar6[2] != lVar1);
    this = (WorkQueue *)puVar6[0x27];
    LOCK();
    lVar1 = *(longlong *)this;
    *(longlong *)this = *(longlong *)this + 1;
    UNLOCK();
    if (lVar1 + 1 < 2) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(0xe);
      puVar7 = auStack_40;
    }
LAB_1c0003686:
    if (lVar2 != 0) {
      *(undefined8 *)(puVar7 + -8) = 0x1c0003697;
      ExReleasePushLockExclusiveEx(lVar2,0);
      *(undefined8 *)(puVar7 + -8) = 0x1c00036a3;
      KeLeaveCriticalRegion();
    }
    if (this != (WorkQueue *)0x0) {
      *(undefined8 *)(puVar7 + -8) = 0x1c00036b5;
      lVar5 = WorkQueue::Run(this);
      *(undefined8 *)(puVar7 + -8) = 0x1c00036bf;
      WorkQueue::Dereference(this);
    }
  }
  return lVar5;
}



===== HandleIoctl<VMBUS_PROXY_SET_VM_NAME_INPUT,NoType,<lambda_8630579025adb04943fa9b7c0f223baf>_> @ 1c000373c =====

long HandleIoctl<VMBUS_PROXY_SET_VM_NAME_INPUT,NoType,<lambda_8630579025adb04943fa9b7c0f223baf>_>
               (ulonglong *param_1,longlong *param_2)

{
  longlong lVar1;
  long lVar2;
  ulonglong local_38;
  undefined8 *puStack_30;
  char *local_28;
  char *pcStack_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_38 = *param_1;
  puStack_30 = (undefined8 *)param_1[1];
  if ((local_38 < 0x14) || (puStack_30 == (undefined8 *)0x0)) {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
    local_18 = 0x1cb;
    pcStack_20 = "HandleIoctl";
    OnFailure((ErrorSite *)&local_28,-0x3ffffff3);
    lVar2 = -0x3ffffff3;
  }
  else {
    local_28 = (char *)*puStack_30;
    pcStack_20 = (char *)puStack_30[1];
    lVar1 = *param_2;
    local_18 = CONCAT44(local_18._4_4_,*(undefined4 *)(puStack_30 + 2));
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(lVar1,0);
    local_38 = *(ulonglong *)param_2[1];
    puStack_30 = (undefined8 *)((ulonglong *)param_2[1])[1];
    lVar2 = VirtualMachine::VmmIoctlSetVmName((VirtualMachine *)(*param_2 + 8),&local_28,&local_38);
    if (lVar1 != 0) {
      ExReleasePushLockExclusiveEx(lVar1,0);
      KeLeaveCriticalRegion();
    }
  }
  return lVar2;
}



===== HandleIoctl<_VMBUS_COMPLETE_OPEN_INPUT_PARAMETERS,NoType,<lambda_266c19f7299a8c70ad99e567673af273>_> @ 1c0003830 =====

long HandleIoctl<_VMBUS_COMPLETE_OPEN_INPUT_PARAMETERS,NoType,<lambda_266c19f7299a8c70ad99e567673af273>_>
               (ulonglong *param_1,longlong *param_2)

{
  longlong lVar1;
  long lVar2;
  char *local_28;
  long *plStack_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_28 = (char *)*param_1;
  plStack_20 = (long *)param_1[1];
  if ((local_28 < 4) || (plStack_20 == (long *)0x0)) {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
    local_18 = 0x1cb;
    lVar2 = -0x3ffffff3;
    plStack_20 = (long *)0x1c000c588;
    OnFailure((ErrorSite *)&local_28,-0x3ffffff3);
  }
  else {
    lVar2 = *plStack_20;
    lVar1 = *param_2;
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(lVar1,0);
    lVar2 = VirtualMachine::DeviceCompleteOpen
                      ((VirtualMachine *)(*param_2 + 8),*(Channel **)param_2[1],lVar2,
                       (CompletedIrps *)param_2[2]);
    if (lVar1 != 0) {
      ExReleasePushLockExclusiveEx(lVar1,0);
      KeLeaveCriticalRegion();
    }
  }
  return lVar2;
}



===== HandleIoctl<_VMBUS_MAP_GPADL_VIEW_INPUT_PARAMS,_VMBUS_MAP_GPADL_VIEW_OUTPUT_PARAMS,<lambda_0fa6f7ba3f2f0cb0949b870cfcf3bb61>_> @ 1c0003914 =====

uint HandleIoctl<_VMBUS_MAP_GPADL_VIEW_INPUT_PARAMS,_VMBUS_MAP_GPADL_VIEW_OUTPUT_PARAMS,<lambda_0fa6f7ba3f2f0cb0949b870cfcf3bb61>_>
               (ulonglong *param_1,undefined8 *param_2)

{
  uint uVar1;
  ulonglong local_38;
  undefined8 *puStack_30;
  char *local_28;
  char *pcStack_20;
  undefined8 local_18;
  undefined8 local_10;
  
  if (param_1[2] < 0x10) {
    local_18 = 0x1c1;
    uVar1 = 0xc0000023;
  }
  else {
    local_38 = *param_1;
    puStack_30 = (undefined8 *)param_1[1];
    if ((0xf < local_38) && (puStack_30 != (undefined8 *)0x0)) {
      local_28 = (char *)*puStack_30;
      pcStack_20 = (char *)puStack_30[1];
      local_38 = 0;
      puStack_30 = (undefined8 *)0x0;
      uVar1 = DeviceIoctlMapGpadl((VirtualMachineFile *)*param_2,*(Channel **)param_2[1],
                                  *(char *)(*(longlong *)param_2[2] + 0x40),
                                  (_VMBUS_MAP_GPADL_VIEW_INPUT_PARAMS *)&local_28,
                                  (_VMBUS_MAP_GPADL_VIEW_OUTPUT_PARAMS *)&local_38);
      if ((uVar1 & 0xc0000000) != 0xc0000000) {
        local_28 = (char *)param_1[2];
        pcStack_20 = (char *)param_1[3];
        if (local_28 < 0x10) {
                    /* WARNING: Subroutine does not return */
          gsl::details::terminate();
        }
        *(ulonglong *)pcStack_20 = local_38;
        *(undefined8 **)((longlong)pcStack_20 + 8) = puStack_30;
        *(undefined8 *)param_1[4] = 0x10;
      }
      return uVar1;
    }
    local_18 = 0x1cb;
    uVar1 = 0xc000000d;
  }
  local_10 = 0;
  local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
  pcStack_20 = "HandleIoctl";
  OnFailure((ErrorSite *)&local_28,uVar1);
  return uVar1;
}



===== HandleIoctl<_VMBUS_OFFER_CHANNEL_INPUT_PARAMETERS,NoType,<lambda_a534ac22b97e81815e4ec8c29d7e7ce5>_> @ 1c0003a1c =====

long HandleIoctl<_VMBUS_OFFER_CHANNEL_INPUT_PARAMETERS,NoType,<lambda_a534ac22b97e81815e4ec8c29d7e7ce5>_>
               (ulonglong *param_1,longlong *param_2)

{
  longlong lVar1;
  long lVar2;
  char *local_e8;
  char *pcStack_e0;
  undefined8 local_d8;
  undefined8 local_d0;
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
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  local_e8 = (char *)*param_1;
  pcStack_e0 = (char *)param_1[1];
  if ((local_e8 < 0xc0) || (pcStack_e0 == (char *)0x0)) {
    local_d0 = 0;
    local_e8 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
    local_d8 = 0x1cb;
    lVar2 = -0x3ffffff3;
    pcStack_e0 = "HandleIoctl";
    OnFailure((ErrorSite *)&local_e8,-0x3ffffff3);
  }
  else {
    local_c8 = *(undefined8 *)pcStack_e0;
    uStack_c0 = *(undefined8 *)((longlong)pcStack_e0 + 8);
    lVar1 = *param_2;
    local_b8 = *(undefined8 *)((longlong)pcStack_e0 + 0x10);
    uStack_b0 = *(undefined8 *)((longlong)pcStack_e0 + 0x18);
    local_a8 = *(undefined8 *)((longlong)pcStack_e0 + 0x20);
    uStack_a0 = *(undefined8 *)((longlong)pcStack_e0 + 0x28);
    local_98 = *(undefined8 *)((longlong)pcStack_e0 + 0x30);
    uStack_90 = *(undefined8 *)((longlong)pcStack_e0 + 0x38);
    local_88 = *(undefined8 *)((longlong)pcStack_e0 + 0x40);
    uStack_80 = *(undefined8 *)((longlong)pcStack_e0 + 0x48);
    local_78 = *(undefined8 *)((longlong)pcStack_e0 + 0x50);
    uStack_70 = *(undefined8 *)((longlong)pcStack_e0 + 0x58);
    local_68 = *(undefined8 *)((longlong)pcStack_e0 + 0x60);
    uStack_60 = *(undefined8 *)((longlong)pcStack_e0 + 0x68);
    local_58 = *(undefined8 *)((longlong)pcStack_e0 + 0x70);
    uStack_50 = *(undefined8 *)((longlong)pcStack_e0 + 0x78);
    local_48 = *(undefined8 *)((longlong)pcStack_e0 + 0x80);
    uStack_40 = *(undefined8 *)((longlong)pcStack_e0 + 0x88);
    local_38 = *(undefined8 *)((longlong)pcStack_e0 + 0x90);
    uStack_30 = *(undefined8 *)((longlong)pcStack_e0 + 0x98);
    local_28 = *(undefined4 *)((longlong)pcStack_e0 + 0xa0);
    uStack_24 = *(undefined4 *)((longlong)pcStack_e0 + 0xa4);
    uStack_20 = *(undefined4 *)((longlong)pcStack_e0 + 0xa8);
    uStack_1c = *(undefined4 *)((longlong)pcStack_e0 + 0xac);
    local_18 = *(undefined4 *)((longlong)pcStack_e0 + 0xb0);
    uStack_14 = *(undefined4 *)((longlong)pcStack_e0 + 0xb4);
    uStack_10 = *(undefined4 *)((longlong)pcStack_e0 + 0xb8);
    uStack_c = *(undefined4 *)((longlong)pcStack_e0 + 0xbc);
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(lVar1,0);
    lVar2 = VirtualMachine::DeviceIoctlOffer
                      ((VirtualMachine *)(*param_2 + 8),*(Channel **)param_2[1],*(_IRP **)param_2[2]
                       ,(_VMBUS_OFFER_CHANNEL_INPUT_PARAMETERS *)&local_c8,
                       (CompletedIrps *)param_2[3]);
    if (lVar1 != 0) {
      ExReleasePushLockExclusiveEx(lVar1,0);
      KeLeaveCriticalRegion();
    }
  }
  return lVar2;
}



===== HandleIoctl<_VMBUS_SET_INTERRUPT_PREFERRED_PROCESSOR_INPUT_PARAMETERS,NoType,<lambda_a997a0f262bd63ad5f730d7aa05bd13c>_> @ 1c0003b80 =====

undefined8
HandleIoctl<_VMBUS_SET_INTERRUPT_PREFERRED_PROCESSOR_INPUT_PARAMETERS,NoType,<lambda_a997a0f262bd63ad5f730d7aa05bd13c>_>
          (ulonglong *param_1,longlong *param_2)

{
  longlong lVar1;
  longlong lVar2;
  CompletedIrps *pCVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  char *local_38;
  char *pcStack_30;
  undefined8 local_28;
  undefined8 local_20;
  
  local_38 = (char *)*param_1;
  pcStack_30 = (char *)param_1[1];
  if ((local_38 < (char *)0x10) || (pcStack_30 == (char *)0x0)) {
    local_20 = 0;
    local_38 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
    local_28 = 0x1cb;
    uVar6 = 0xc000000d;
    pcStack_30 = "HandleIoctl";
    OnFailure((ErrorSite *)&local_38,-0x3ffffff3);
  }
  else {
    uVar6 = *(undefined8 *)pcStack_30;
    uVar5 = *(undefined8 *)(pcStack_30 + 8);
    lVar1 = *param_2;
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(lVar1,0);
    lVar2 = *param_2;
    pCVar3 = (CompletedIrps *)param_2[2];
    lVar4 = *(longlong *)param_2[1];
    if (*(char *)(lVar2 + 0x18) == '\0') {
      *(undefined8 *)(lVar4 + 0x128) = uVar6;
      *(undefined8 *)(lVar4 + 0x130) = uVar5;
      VirtualMachine::WakeVmm((VirtualMachine *)(lVar2 + 8),pCVar3);
      uVar6 = 0;
    }
    else {
      local_20 = 0;
      local_38 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
      local_28 = 0x1cf;
      uVar6 = 0xc0000184;
      pcStack_30 = "VirtualMachine::DeviceIoctlSetInterruptPreferredProcessor";
      OnFailure((ErrorSite *)&local_38,-0x3ffffe7c);
    }
    if (lVar1 != 0) {
      ExReleasePushLockExclusiveEx(lVar1,0);
      KeLeaveCriticalRegion();
    }
  }
  return uVar6;
}



===== HandleIoctl<_VMBUS_UNMAP_GPADL_VIEW_INPUT_PARAMS,NoType,<lambda_5eb3ed8726deee6e74edad3136cfa3d7>_> @ 1c0003cb4 =====

long HandleIoctl<_VMBUS_UNMAP_GPADL_VIEW_INPUT_PARAMS,NoType,<lambda_5eb3ed8726deee6e74edad3136cfa3d7>_>
               (ulonglong *param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  long lVar3;
  ulonglong local_38;
  undefined8 *puStack_30;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_38 = *param_1;
  puStack_30 = (undefined8 *)param_1[1];
  if ((local_38 < 0x10) || (puStack_30 == (undefined8 *)0x0)) {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
    local_18 = 0x1cb;
    lVar3 = -0x3ffffff3;
    local_20 = "HandleIoctl";
    OnFailure((ErrorSite *)&local_28,-0x3ffffff3);
  }
  else {
    local_20 = (char *)*puStack_30;
    local_18 = puStack_30[1];
    local_28 = (char *)((ulonglong)local_28 & 0xffffffff00000000);
    local_38 = 0;
    puStack_30 = (undefined8 *)0x0;
    lVar3 = GpadlSet::LockGpadl((GpadlSet *)(**(longlong **)(param_2 + 8) + 0x28),
                                (GpadlKey *)&local_28,(LockedGpadl *)&local_38);
    if (lVar3 < 0) {
      local_10 = 0;
      local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
      local_18 = 0x135;
      local_20 = "DeviceIoctlUnmapGpadl";
      OnFailure((ErrorSite *)&local_28,lVar3);
    }
    else {
      lVar1 = *(longlong *)((longlong)puStack_30 + 0x38);
      *(undefined8 *)((longlong)puStack_30 + 0x38) = 0;
      if (lVar1 != 0) {
        MdlMapping::~MdlMapping((MdlMapping *)(lVar1 + 0x20));
        lVar2 = *(longlong *)(lVar1 + 0x18);
        *(undefined8 *)(lVar1 + 0x18) = 0;
        if (lVar2 != 0) {
          IoFreeMdl();
        }
        wistd::
        unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
        ::
        ~unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
                  ((unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
                    *)(lVar1 + 0x10));
        ExFreePoolWithTag(lVar1,0);
      }
      lVar3 = 0;
    }
    LockedGpadl::reset((LockedGpadl *)&local_38);
  }
  return lVar3;
}



===== HandleIrp<&long___cdecl_HandleIrpCleanup(struct__IRP*___ptr64)> @ 1c0003e00 =====

/* long __cdecl HandleIrp<&long __cdecl HandleIrpCleanup(struct _IRP * __ptr64)>(struct
   _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl
HandleIrp<&long___cdecl_HandleIrpCleanup(struct__IRP*___ptr64)>
          (_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  long lVar1;
  
  lVar1 = HandleIrpCleanup(param_2);
  if (lVar1 != 0x103) {
    *(long *)(param_2 + 0x30) = lVar1;
    IofCompleteRequest(param_2,0);
  }
  return lVar1;
}



===== HandleIrp<&long___cdecl_HandleIrpClose(struct__IRP*___ptr64)> @ 1c0003e50 =====

/* long __cdecl HandleIrp<&long __cdecl HandleIrpClose(struct _IRP * __ptr64)>(struct _DEVICE_OBJECT
   * __ptr64,struct _IRP * __ptr64) */

long __cdecl
HandleIrp<&long___cdecl_HandleIrpClose(struct__IRP*___ptr64)>(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  long lVar1;
  
  lVar1 = HandleIrpClose(param_2);
  if (lVar1 != 0x103) {
    *(long *)(param_2 + 0x30) = lVar1;
    IofCompleteRequest(param_2,0);
  }
  return lVar1;
}



===== HandleIrp<&long___cdecl_HandleIrpCreate(struct__IRP*___ptr64)> @ 1c0003ea0 =====

/* long __cdecl HandleIrp<&long __cdecl HandleIrpCreate(struct _IRP * __ptr64)>(struct
   _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl
HandleIrp<&long___cdecl_HandleIrpCreate(struct__IRP*___ptr64)>
          (_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  long lVar1;
  
  lVar1 = HandleIrpCreate(param_2);
  if (lVar1 != 0x103) {
    *(long *)(param_2 + 0x30) = lVar1;
    IofCompleteRequest(param_2,0);
  }
  return lVar1;
}



===== HandleIrp<&long___cdecl_HandleIrpIoctl(struct__IRP*___ptr64)> @ 1c0003ef0 =====

/* long __cdecl HandleIrp<&long __cdecl HandleIrpIoctl(struct _IRP * __ptr64)>(struct _DEVICE_OBJECT
   * __ptr64,struct _IRP * __ptr64) */

long __cdecl
HandleIrp<&long___cdecl_HandleIrpIoctl(struct__IRP*___ptr64)>(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  long lVar1;
  
  lVar1 = HandleIrpIoctl(param_2);
  if (lVar1 != 0x103) {
    *(long *)(param_2 + 0x30) = lVar1;
    IofCompleteRequest(param_2,0);
  }
  return lVar1;
}



===== HandleIrp<&long___cdecl_HandleIrpPnp(struct__IRP*___ptr64)> @ 1c0003f40 =====

/* long __cdecl HandleIrp<&long __cdecl HandleIrpPnp(struct _IRP * __ptr64)>(struct _DEVICE_OBJECT *
   __ptr64,struct _IRP * __ptr64) */

long __cdecl
HandleIrp<&long___cdecl_HandleIrpPnp(struct__IRP*___ptr64)>(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  long lVar1;
  
  lVar1 = HandleIrpPnp(param_2);
  if (lVar1 != 0x103) {
    *(long *)(param_2 + 0x30) = lVar1;
    IofCompleteRequest(param_2,0);
  }
  return lVar1;
}



===== ReferenceObObject<_EPROCESS> @ 1c0003f88 =====

/* class wistd::unique_ptr<struct _EPROCESS,struct wil::function_deleter<__int64 (__cdecl*)(void *
   __ptr64),&__int64 __cdecl ObfDereferenceObject(void * __ptr64)> > __cdecl
   ReferenceObObject<struct _EPROCESS>(struct _EPROCESS * __ptr64) */

_EPROCESS * __cdecl ReferenceObObject<_EPROCESS>(_EPROCESS *param_1)

{
  undefined8 in_RDX;
  
  ObfReferenceObject();
  *(undefined8 *)param_1 = in_RDX;
  return param_1;
}



===== copy<unsigned___int64,-1,unsigned___int64,-1> @ 1c0003fc0 =====

/* void __cdecl gsl::copy<unsigned __int64,-1,unsigned __int64,-1>(class gsl::span<unsigned
   __int64,-1>,class gsl::span<unsigned __int64,-1>) */

void __cdecl
gsl::copy<unsigned___int64,_1,unsigned___int64,_1>(ulonglong *param_1,ulonglong *param_2)

{
  ulonglong uVar1;
  void *_Dst;
  
  uVar1 = *param_1;
  if (uVar1 <= *param_2) {
    if (((void *)param_1[1] != (void *)0x0) || (*param_1 * 8 == 0)) {
      _Dst = (void *)param_2[1];
      if ((((_Dst != (void *)0x0) || (*param_2 * 8 == 0)) &&
          ((uVar1 <= *param_2 * 8 && (uVar1 != 0xffffffffffffffff)))) &&
         ((_Dst != (void *)0x0 || (uVar1 == 0)))) {
        memcpy(_Dst,(void *)param_1[1],*param_1 * 8);
        return;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  details::terminate();
}



===== scope_exit<<lambda_33518dc734835b711a9e7f6f385320da>_> @ 1c0004040 =====

undefined8 *
wil::scope_exit<<lambda_33518dc734835b711a9e7f6f385320da>_>(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  *(undefined1 *)(param_1 + 1) = 1;
  return param_1;
}



===== ~lambda_call<<lambda_ff71274176b5d6cd7a946c61720e63be>_> @ 1c0004058 =====

void wil::details::lambda_call<<lambda_ff71274176b5d6cd7a946c61720e63be>_>::
     ~lambda_call<<lambda_ff71274176b5d6cd7a946c61720e63be>_>(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  if ((char)param_1[1] != '\0') {
    *(undefined1 *)(param_1 + 1) = 0;
    lVar1 = *(longlong *)(*(longlong *)(*param_1 + 8) + 0x38);
    *(undefined8 *)(*(longlong *)(*param_1 + 8) + 0x38) = 0;
    if (lVar1 != 0) {
      MdlMapping::~MdlMapping((MdlMapping *)(lVar1 + 0x20));
      lVar2 = *(longlong *)(lVar1 + 0x18);
      *(undefined8 *)(lVar1 + 0x18) = 0;
      if (lVar2 != 0) {
        IoFreeMdl();
      }
      wistd::
      unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
      ::
      ~unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
                ((unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
                  *)(lVar1 + 0x10));
      ExFreePoolWithTag(lVar1,0);
    }
  }
  return;
}



===== ~unique_any_t<wil::details::unique_storage<wil::details::resource_policy<_EX_PUSH_LOCK*___ptr64,void_(__cdecl*)(_EX_PUSH_LOCK*___ptr64),&void___cdecl_util::ReleaseExclusiveLock(struct__EX_PUSH_LOCK*___ptr64),wistd::integral_constant<unsigned___int64,2>,_EX_PUSH_LOCK*___ptr64,_EX_PUSH_LOCK*___ptr64,0,std::nullptr_t>_>_> @ 1c00040c8 =====

/* public: __cdecl wil::unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<struct _EX_PUSH_LOCK * __ptr64,void (__cdecl*)(struct _EX_PUSH_LOCK
   * __ptr64),&void __cdecl util::ReleaseExclusiveLock(struct _EX_PUSH_LOCK * __ptr64),struct
   wistd::integral_constant<unsigned __int64,2>,struct _EX_PUSH_LOCK * __ptr64,struct _EX_PUSH_LOCK
   * __ptr64,0,std::nullptr_t> > >::~unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<struct _EX_PUSH_LOCK * __ptr64,void (__cdecl*)(struct _EX_PUSH_LOCK
   * __ptr64),&void __cdecl util::ReleaseExclusiveLock(struct _EX_PUSH_LOCK * __ptr64),struct
   wistd::integral_constant<unsigned __int64,2>,struct _EX_PUSH_LOCK * __ptr64,struct _EX_PUSH_LOCK
   * __ptr64,0,std::nullptr_t> > >(void) __ptr64 */

void __thiscall
wil::
unique_any_t<wil::details::unique_storage<wil::details::resource_policy<_EX_PUSH_LOCK*___ptr64,void_(__cdecl*)(_EX_PUSH_LOCK*___ptr64),&void___cdecl_util::ReleaseExclusiveLock(struct__EX_PUSH_LOCK*___ptr64),wistd::integral_constant<unsigned___int64,2>,_EX_PUSH_LOCK*___ptr64,_EX_PUSH_LOCK*___ptr64,0,std::nullptr_t>_>_>
::
~unique_any_t<wil::details::unique_storage<wil::details::resource_policy<_EX_PUSH_LOCK*___ptr64,void_(__cdecl*)(_EX_PUSH_LOCK*___ptr64),&void___cdecl_util::ReleaseExclusiveLock(struct__EX_PUSH_LOCK*___ptr64),wistd::integral_constant<unsigned___int64,2>,_EX_PUSH_LOCK*___ptr64,_EX_PUSH_LOCK*___ptr64,0,std::nullptr_t>_>_>
          (unique_any_t<wil::details::unique_storage<wil::details::resource_policy<_EX_PUSH_LOCK*___ptr64,void_(__cdecl*)(_EX_PUSH_LOCK*___ptr64),&void___cdecl_util::ReleaseExclusiveLock(struct__EX_PUSH_LOCK*___ptr64),wistd::integral_constant<unsigned___int64,2>,_EX_PUSH_LOCK*___ptr64,_EX_PUSH_LOCK*___ptr64,0,std::nullptr_t>_>_>
           *this)

{
  if (*(longlong *)this != 0) {
    ExReleasePushLockExclusiveEx(*(longlong *)this,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== ~unique_any_t<wil::details::unique_storage<wil::details::resource_policy<_EX_PUSH_LOCK*___ptr64,void_(__cdecl*)(_EX_PUSH_LOCK*___ptr64),&void___cdecl_util::ReleaseSharedLock(struct__EX_PUSH_LOCK*___ptr64),wistd::integral_constant<unsigned___int64,2>,_EX_PUSH_LOCK*___ptr64,_EX_PUSH_LOCK*___ptr64,0,std::nullptr_t>_>_> @ 1c00040fc =====

/* public: __cdecl wil::unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<struct _EX_PUSH_LOCK * __ptr64,void (__cdecl*)(struct _EX_PUSH_LOCK
   * __ptr64),&void __cdecl util::ReleaseSharedLock(struct _EX_PUSH_LOCK * __ptr64),struct
   wistd::integral_constant<unsigned __int64,2>,struct _EX_PUSH_LOCK * __ptr64,struct _EX_PUSH_LOCK
   * __ptr64,0,std::nullptr_t> > >::~unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<struct _EX_PUSH_LOCK * __ptr64,void (__cdecl*)(struct _EX_PUSH_LOCK
   * __ptr64),&void __cdecl util::ReleaseSharedLock(struct _EX_PUSH_LOCK * __ptr64),struct
   wistd::integral_constant<unsigned __int64,2>,struct _EX_PUSH_LOCK * __ptr64,struct _EX_PUSH_LOCK
   * __ptr64,0,std::nullptr_t> > >(void) __ptr64 */

void __thiscall
wil::
unique_any_t<wil::details::unique_storage<wil::details::resource_policy<_EX_PUSH_LOCK*___ptr64,void_(__cdecl*)(_EX_PUSH_LOCK*___ptr64),&void___cdecl_util::ReleaseSharedLock(struct__EX_PUSH_LOCK*___ptr64),wistd::integral_constant<unsigned___int64,2>,_EX_PUSH_LOCK*___ptr64,_EX_PUSH_LOCK*___ptr64,0,std::nullptr_t>_>_>
::
~unique_any_t<wil::details::unique_storage<wil::details::resource_policy<_EX_PUSH_LOCK*___ptr64,void_(__cdecl*)(_EX_PUSH_LOCK*___ptr64),&void___cdecl_util::ReleaseSharedLock(struct__EX_PUSH_LOCK*___ptr64),wistd::integral_constant<unsigned___int64,2>,_EX_PUSH_LOCK*___ptr64,_EX_PUSH_LOCK*___ptr64,0,std::nullptr_t>_>_>
          (unique_any_t<wil::details::unique_storage<wil::details::resource_policy<_EX_PUSH_LOCK*___ptr64,void_(__cdecl*)(_EX_PUSH_LOCK*___ptr64),&void___cdecl_util::ReleaseSharedLock(struct__EX_PUSH_LOCK*___ptr64),wistd::integral_constant<unsigned___int64,2>,_EX_PUSH_LOCK*___ptr64,_EX_PUSH_LOCK*___ptr64,0,std::nullptr_t>_>_>
           *this)

{
  if (*(longlong *)this != 0) {
    ExReleasePushLockSharedEx(*(longlong *)this,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== ~unique_ptr<VirtualMachineFile,wistd::default_delete<VirtualMachineFile>_> @ 1c0004130 =====

/* public: __cdecl wistd::unique_ptr<struct VirtualMachineFile,struct wistd::default_delete<struct
   VirtualMachineFile> >::~unique_ptr<struct VirtualMachineFile,struct wistd::default_delete<struct
   VirtualMachineFile> >(void) __ptr64 */

void __thiscall
wistd::unique_ptr<VirtualMachineFile,wistd::default_delete<VirtualMachineFile>_>::
~unique_ptr<VirtualMachineFile,wistd::default_delete<VirtualMachineFile>_>
          (unique_ptr<VirtualMachineFile,wistd::default_delete<VirtualMachineFile>_> *this)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)this;
  *(undefined8 *)this = 0;
  if (lVar1 != 0) {
    lVar2 = *(longlong *)(lVar1 + 0x88);
    *(undefined8 *)(lVar1 + 0x88) = 0;
    if (lVar2 != 0) {
      ExFreePoolWithTag(lVar2,0);
    }
    lVar2 = *(longlong *)(lVar1 + 0x60);
    *(undefined8 *)(lVar1 + 0x60) = 0;
    if (lVar2 != 0) {
      ObfDereferenceObject();
    }
    VirtualMachine::~VirtualMachine((VirtualMachine *)(lVar1 + 8));
    ExFreePoolWithTag(lVar1,0);
  }
  return;
}



===== ~VirtualMachine @ 1c00041a8 =====

/* public: __cdecl VirtualMachine::~VirtualMachine(void) __ptr64 */

void __thiscall VirtualMachine::~VirtualMachine(VirtualMachine *this)

{
  code *pcVar1;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  RtlFreeUnicodeString(this + 0x28);
  CancellableIrp::~CancellableIrp((CancellableIrp *)(this + 0x20));
  if (*(VirtualMachine **)this != this) {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\util.h";
    local_18 = 0x40;
    local_20 = "ListHead::~ListHead";
    OnFailure((ErrorSite *)&local_28,-0x3fffffff);
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(5);
  }
  return;
}



===== AcquireExclusiveLock @ 1c000421c =====

/* class wil::unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<struct _EX_PUSH_LOCK * __ptr64,void (__cdecl*)(struct _EX_PUSH_LOCK
   * __ptr64),&void __cdecl util::ReleaseExclusiveLock(struct _EX_PUSH_LOCK * __ptr64),struct
   wistd::integral_constant<unsigned __int64,2>,struct _EX_PUSH_LOCK * __ptr64,struct _EX_PUSH_LOCK
   * __ptr64,0,std::nullptr_t> > > __cdecl util::AcquireExclusiveLock(struct _EX_PUSH_LOCK *
   __ptr64) */

_EX_PUSH_LOCK * __cdecl util::AcquireExclusiveLock(_EX_PUSH_LOCK *param_1)

{
  undefined8 in_RDX;
  
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx();
  *(undefined8 *)param_1 = in_RDX;
  return param_1;
}



===== AcquireSharedLock @ 1c0004264 =====

/* class wil::unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<struct _EX_PUSH_LOCK * __ptr64,void (__cdecl*)(struct _EX_PUSH_LOCK
   * __ptr64),&void __cdecl util::ReleaseSharedLock(struct _EX_PUSH_LOCK * __ptr64),struct
   wistd::integral_constant<unsigned __int64,2>,struct _EX_PUSH_LOCK * __ptr64,struct _EX_PUSH_LOCK
   * __ptr64,0,std::nullptr_t> > > __cdecl util::AcquireSharedLock(struct _EX_PUSH_LOCK * __ptr64)
    */

_EX_PUSH_LOCK * __cdecl util::AcquireSharedLock(_EX_PUSH_LOCK *param_1)

{
  undefined8 in_RDX;
  
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx();
  *(undefined8 *)param_1 = in_RDX;
  return param_1;
}



===== AllocateRingBufferPartialMdl @ 1c00042ac =====

/* long __cdecl AllocateRingBufferPartialMdl(struct _MDL * __ptr64,unsigned int,class
   wistd::unique_ptr<struct _MDL,struct wil::function_deleter<void (__cdecl*)(struct _MDL *
   __ptr64),&void __cdecl IoFreeMdl(struct _MDL * __ptr64)> > * __ptr64) */

long __cdecl
AllocateRingBufferPartialMdl
          (_MDL *param_1,uint param_2,
          unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_IoFreeMdl(struct__MDL*___ptr64)>_>
          *param_3)

{
  _MDL *p_Var1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  uint uVar6;
  char *pcVar7;
  long lVar8;
  char *pcVar9;
  uint uVar10;
  char *pcVar11;
  char *pcVar12;
  ulonglong local_68;
  _MDL *p_Stack_60;
  char *local_58;
  char *pcStack_50;
  undefined8 local_48;
  undefined8 local_40;
  
  pcVar7 = (char *)(ulonglong)param_2;
  if ((*(int *)(param_1 + 0x2c) == 0) && ((*(uint *)(param_1 + 0x28) & 0xfff) == 0)) {
    uVar10 = *(uint *)(param_1 + 0x28) >> 0xc;
    pcVar11 = (char *)(ulonglong)uVar10;
    if (((3 < uVar10) && (1 < param_2)) && (param_2 <= uVar10 - 2)) {
      uVar4 = param_2 - 1;
      uVar10 = uVar10 - param_2;
      uVar6 = uVar10 - 1;
      uVar3 = (uVar4 + uVar6) * 2 + 2;
      lVar5 = IoAllocateMdl(*(undefined8 *)(param_1 + 0x20),uVar3 * 0x1000,0,0,0);
      if (lVar5 != 0) {
        IoBuildPartialMdl(param_1,lVar5,
                          (ulonglong)*(uint *)(param_1 + 0x2c) + *(longlong *)(param_1 + 0x20),0);
        p_Var1 = param_1 + 0x30;
        *(uint *)(lVar5 + 0x28) = uVar3 * 0x1000;
        if ((p_Var1 != (_MDL *)0x0) || (pcVar11 == (char *)0x0)) {
          lVar2 = lVar5 + 0x30;
          pcVar9 = (char *)(ulonglong)uVar3;
          if (((lVar2 != 0) || (uVar3 == 0)) && (pcVar7 <= pcVar11)) {
            local_68 = (ulonglong)param_2;
            p_Stack_60 = p_Var1;
            local_58 = pcVar9;
            pcStack_50 = (char *)lVar2;
            gsl::copy<unsigned___int64,_1,unsigned___int64,_1>(&local_68,&local_58);
            if ((pcVar7 <= pcVar9) &&
               (local_58 = pcVar9 + -(longlong)pcVar7, local_58 != (char *)0xffffffffffffffff)) {
              pcStack_50 = (char *)(lVar2 + (longlong)pcVar7 * 8);
              if ((pcVar11 != (char *)0x0) && ((char *)(ulonglong)uVar4 <= pcVar11 + -1)) {
                p_Stack_60 = param_1 + 0x38;
                local_68 = (ulonglong)uVar4;
                gsl::copy<unsigned___int64,_1,unsigned___int64,_1>(&local_68,&local_58);
                uVar3 = uVar4 * 2 + 1;
                if (((((char *)(ulonglong)uVar3 <= pcVar9) &&
                     (pcVar9 = pcVar9 + -(longlong)(ulonglong)uVar3, local_58 = pcVar9,
                     pcVar9 != (char *)0xffffffffffffffff)) &&
                    (lVar2 = lVar2 + (ulonglong)uVar3 * 8, pcStack_50 = (char *)lVar2,
                    pcVar7 <= pcVar11)) &&
                   (pcVar11 = pcVar11 + -(longlong)pcVar7, pcVar11 != (char *)0xffffffffffffffff)) {
                  pcVar12 = (char *)(ulonglong)uVar10;
                  if (pcVar12 <= pcVar11) {
                    local_68 = (ulonglong)uVar10;
                    p_Stack_60 = p_Var1 + (longlong)pcVar7 * 8;
                    gsl::copy<unsigned___int64,_1,unsigned___int64,_1>(&local_68,&local_58);
                    if ((pcVar12 <= pcVar9) &&
                       (local_58 = pcVar9 + -(longlong)pcVar12,
                       local_58 != (char *)0xffffffffffffffff)) {
                      pcStack_50 = (char *)(lVar2 + (longlong)pcVar12 * 8);
                      if ((pcVar11 != (char *)0x0) && ((char *)(ulonglong)uVar6 <= pcVar11 + -1)) {
                        p_Stack_60 = p_Var1 + (longlong)pcVar7 * 8 + 8;
                        local_68 = (ulonglong)uVar6;
                        gsl::copy<unsigned___int64,_1,unsigned___int64,_1>(&local_68,&local_58);
                        pcVar7 = (char *)(ulonglong)(uVar6 * 2 + 1);
                        if ((((pcVar7 <= pcVar9) && ((longlong)pcVar9 - (longlong)pcVar7 != -1)) &&
                            (pcVar12 <= pcVar11)) && ((longlong)pcVar11 - (longlong)pcVar12 != -1))
                        {
                          lVar2 = *(longlong *)param_3;
                          *(longlong *)param_3 = lVar5;
                          if (lVar2 != 0) {
                            IoFreeMdl();
                          }
                          return 0;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
                    /* WARNING: Subroutine does not return */
        gsl::details::terminate();
      }
      local_48 = 0xde;
      lVar8 = -0x3fffff66;
      goto LAB_1c0004599;
    }
    local_48 = 0xd4;
  }
  else {
    local_48 = 0xc9;
  }
  lVar8 = -0x3ffffff0;
LAB_1c0004599:
  local_40 = 0;
  local_58 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
  pcStack_50 = "AllocateRingBufferPartialMdl";
  OnFailure((ErrorSite *)&local_58,lVar8);
  return lVar8;
}



===== ChCancelInterrupt @ 1c00045f0 =====

undefined1 ChCancelInterrupt(void)

{
  return 0;
}



===== ChCloseChannel @ 1c0004600 =====

void ChCloseChannel(Channel *param_1)

{
  VirtualMachine *pVVar1;
  code *pcVar2;
  long lVar3;
  VirtualMachine *this;
  undefined1 *puVar4;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [24];
  undefined8 ***local_38;
  undefined8 ***local_30;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  pVVar1 = *(VirtualMachine **)(*(longlong *)(param_1 + 0x18) + 0x18);
  local_30 = &local_38;
  local_38 = &local_38;
  KeEnterCriticalRegion();
  this = pVVar1;
  ExAcquirePushLockExclusiveEx(pVVar1,0);
  lVar3 = VirtualMachine::DeviceCloseChannel(this,param_1,(CompletedIrps *)&local_38);
  puVar4 = auStack_58;
  if (lVar3 < 0) {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
    local_18 = 0x3ad;
    local_20 = "ChCloseChannel";
    OnFailure((ErrorSite *)&local_28,lVar3);
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_50;
  }
  if (pVVar1 != (VirtualMachine *)0x0) {
    *(undefined8 *)(puVar4 + -8) = 0x1c00046a0;
    ExReleasePushLockExclusiveEx(pVVar1,0);
    *(undefined8 *)(puVar4 + -8) = 0x1c00046ac;
    KeLeaveCriticalRegion();
  }
  *(undefined8 *)(puVar4 + -8) = 0x1c00046ba;
  CompletedIrps::~CompletedIrps((CompletedIrps *)&local_38);
  return;
}



===== ChCreateWorkItem @ 1c00046e0 =====

undefined8 ChCreateWorkItem(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  WorkQueue *pWVar3;
  code *pcVar4;
  void *pvVar5;
  undefined8 uVar6;
  undefined1 *puVar7;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  plVar2 = *(longlong **)(param_1 + 0x138);
  pvVar5 = operator_new(0x30);
  puVar7 = auStack_48;
  if (pvVar5 == (void *)0x0) {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
    local_18 = 0x468;
    local_20 = "ChCreateWorkItem";
    OnFailure((ErrorSite *)&local_28,-0x3fffff66);
    uVar6 = 0xc000009a;
  }
  else {
    *(undefined8 *)((longlong)pvVar5 + 0x10) = 0;
    *(undefined8 *)((longlong)pvVar5 + 0x28) = 0;
    *(void **)((longlong)pvVar5 + 8) = pvVar5;
    *(void **)pvVar5 = pvVar5;
    *(undefined8 *)((longlong)pvVar5 + 0x18) = 0;
    *(undefined8 *)((longlong)pvVar5 + 0x20) = 0;
    LOCK();
    lVar1 = *plVar2;
    *plVar2 = *plVar2 + 1;
    UNLOCK();
    if (lVar1 + 1 < 2) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(0xe);
      puVar7 = auStack_40;
    }
    pWVar3 = *(WorkQueue **)((longlong)pvVar5 + 0x10);
    *(longlong **)((longlong)pvVar5 + 0x10) = plVar2;
    if (pWVar3 != (WorkQueue *)0x0) {
      *(undefined8 *)(puVar7 + -8) = 0x1c0004754;
      WorkQueue::Dereference(pWVar3);
    }
    *(undefined8 *)((longlong)pvVar5 + 0x28) = param_2;
    uVar6 = 0;
    *param_3 = pvVar5;
  }
  return uVar6;
}



===== ChDequeueWorkItem @ 1c00047c0 =====

undefined1 ChDequeueWorkItem(undefined8 param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  longlong lVar6;
  longlong local_28;
  undefined8 uStack_20;
  longlong local_18;
  undefined8 uStack_10;
  
  lVar6 = param_2[2] + 8;
  uVar5 = KeAcquireSpinLockRaiseToDpc(lVar6);
  uVar4 = uStack_20;
  plVar1 = (longlong *)*param_2;
  uStack_20._0_5_ = CONCAT41(uStack_20._1_4_,uVar5);
  uStack_20._5_2_ = SUB82(uVar4,5);
  uStack_20._7_1_ = SUB81(uVar4,7);
  local_28 = lVar6;
  if (plVar1 == param_2) {
    uVar5 = 0;
    if (lVar6 != 0) {
      uStack_10 = uStack_20;
      local_18 = lVar6;
      wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_18);
    }
  }
  else {
    if (((longlong *)plVar1[1] != param_2) ||
       (plVar2 = (longlong *)param_2[1], (longlong *)*plVar2 != param_2)) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      pcVar3 = (code *)swi(3);
      uVar5 = (*pcVar3)();
      return uVar5;
    }
    *plVar2 = (longlong)plVar1;
    plVar1[1] = (longlong)plVar2;
    param_2[1] = (longlong)param_2;
    *param_2 = (longlong)param_2;
    param_2[3] = 0;
    param_2[4] = 0;
    if (lVar6 != 0) {
      wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_28);
    }
    uVar5 = 1;
  }
  return uVar5;
}



===== ChDestroyWorkItem @ 1c00048a0 =====

void ChDestroyWorkItem(undefined8 param_1,WorkItem *param_2)

{
  if (param_2 != (WorkItem *)0x0) {
    WorkItem::~WorkItem(param_2);
    ExFreePoolWithTag(param_2,0);
  }
  return;
}



===== ChGetLockChildPagesParams @ 1c00048e0 =====

undefined8 ChGetLockChildPagesParams(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 1;
  *(undefined1 *)(param_2 + 1) = 1;
  return 0;
}



===== ChGetNumaNodeMap @ 1c0004900 =====

uint ChGetNumaNodeMap(longlong param_1,uint param_2,longlong param_3,uint *param_4,
                     undefined4 *param_5)

{
  uint uVar1;
  undefined4 local_res10 [6];
  ulonglong local_18;
  longlong local_10;
  
  local_res10[0] = 0;
  local_18 = (ulonglong)param_2;
  if ((param_3 == 0) && (param_2 != 0)) {
                    /* WARNING: Subroutine does not return */
    gsl::details::terminate();
  }
  local_10 = param_3;
  uVar1 = DeviceGetTopology(*(undefined8 *)(*(longlong *)(param_1 + 0x18) + 0x18),&local_18,
                            local_res10);
  if (param_4 != (uint *)0x0) {
    *param_4 = uVar1;
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = local_res10[0];
  }
  return -(uint)(param_2 < uVar1) & 0xc0000023;
}



===== ChGetVaBackingProcess @ 1c0004980 =====

undefined8 ChGetVaBackingProcess(void)

{
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_10 = 0;
  local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
  local_18 = 0x516;
  local_20 = "ChGetVaBackingProcess";
  OnFailure((ErrorSite *)&local_28,-0x3ffffffe);
  return 0xc0000002;
}



===== ChGetVmName @ 1c00049d0 =====

void ChGetVmName(longlong param_1,longlong param_2,undefined2 *param_3,undefined4 *param_4)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x18) + 0x18);
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(lVar1,0);
  if ((param_2 != 0) && (*(ushort *)(lVar1 + 0x30) <= *(ushort *)(param_2 + 2))) {
    RtlCopyUnicodeString(param_2);
  }
  if (param_3 != (undefined2 *)0x0) {
    *param_3 = *(undefined2 *)(lVar1 + 0x30);
  }
  if (param_4 != (undefined4 *)0x0) {
    uVar2 = *(undefined4 *)(lVar1 + 0x44);
    uVar3 = *(undefined4 *)(lVar1 + 0x48);
    uVar4 = *(undefined4 *)(lVar1 + 0x4c);
    *param_4 = *(undefined4 *)(lVar1 + 0x40);
    param_4[1] = uVar2;
    param_4[2] = uVar3;
    param_4[3] = uVar4;
  }
  if (lVar1 != 0) {
    ExReleasePushLockSharedEx(lVar1,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== ChLockChildPages @ 1c0004a90 =====

void ChLockChildPages(longlong param_1,undefined8 param_2,undefined8 param_3,uint param_4,
                     longlong param_5,longlong param_6,uint param_7)

{
  ulonglong local_28;
  longlong local_20;
  ulonglong local_18;
  longlong local_10;
  
  local_28 = (ulonglong)param_7;
  if (((param_5 == 0) && (local_28 != 0)) || ((param_6 == 0 && (local_28 != 0)))) {
                    /* WARNING: Subroutine does not return */
    gsl::details::terminate();
  }
  local_20 = param_6;
  local_10 = param_5;
  local_18 = local_28;
  LockChildPages(*(VirtualMachineFile **)(*(longlong *)(param_1 + 0x18) + 0x18),param_4,&local_18,
                 &local_28);
  return;
}



===== ChMapChildMmioSpace @ 1c0004b00 =====

undefined8 ChMapChildMmioSpace(void)

{
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_10 = 0;
  local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
  local_18 = 0x4f3;
  local_20 = "ChMapChildMmioSpace";
  OnFailure((ErrorSite *)&local_28,-0x3ffffffe);
  return 0xc0000002;
}



===== ChMapChildVaSpace @ 1c0004b50 =====

undefined8 ChMapChildVaSpace(void)

{
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_10 = 0;
  local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
  local_18 = 0x50c;
  local_20 = "ChMapChildVaSpace";
  OnFailure((ErrorSite *)&local_28,-0x3ffffffe);
  return 0xc0000002;
}



===== ChMapGpadlView @ 1c0004ba0 =====

long ChMapGpadlView(longlong param_1,undefined4 param_2,uint param_3,undefined8 *param_4)

{
  VirtualMachineFile *pVVar1;
  long lVar2;
  undefined8 local_48;
  longlong lStack_40;
  undefined8 ***local_38;
  undefined8 ***local_30;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_20 = (char *)0x0;
  local_30 = &local_38;
  local_18 = 0;
  local_38 = &local_38;
  local_28 = (char *)CONCAT44(local_28._4_4_,param_2);
  local_48 = 0;
  lStack_40 = 0;
  pVVar1 = *(VirtualMachineFile **)(*(longlong *)(param_1 + 0x18) + 0x18);
  lVar2 = GpadlSet::LockGpadl((GpadlSet *)(param_1 + 0x28),(GpadlKey *)&local_28,
                              (LockedGpadl *)&local_48);
  if (lVar2 < 0) {
    local_18 = 0x3c8;
  }
  else {
    lVar2 = MapLockedGpadl(pVVar1,(LockedGpadl *)&local_48,param_3);
    if (lVar2 < 0) {
      local_18 = 0x3c9;
    }
    else {
      *param_4 = **(undefined8 **)(*(longlong *)(lStack_40 + 0x38) + 0x10);
      lVar2 = LockedGpadl::CommitMapping((LockedGpadl *)&local_48,(CompletedIrps *)&local_38);
      if (-1 < lVar2) {
        lVar2 = 0;
        goto LAB_1c0004c85;
      }
      local_18 = 0x3cb;
    }
  }
  local_10 = 0;
  local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
  local_20 = "ChMapGpadlView";
  OnFailure((ErrorSite *)&local_28,lVar2);
LAB_1c0004c85:
  LockedGpadl::reset((LockedGpadl *)&local_48);
  CompletedIrps::~CompletedIrps((CompletedIrps *)&local_38);
  return lVar2;
}



===== ChOpenChannel @ 1c0004cc0 =====

long ChOpenChannel(longlong param_1,undefined8 *param_2)

{
  int iVar1;
  longlong lVar2;
  code *pcVar3;
  undefined1 *puVar4;
  long lVar5;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x18) + 0x18);
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(lVar2,0);
  puVar4 = auStack_48;
  if (*(char *)(lVar2 + 0x18) == '\0') {
    iVar1 = *(int *)(param_1 + 0x20);
    if (iVar1 == 0) {
LAB_1c0004dfc:
      local_18 = 0x171;
      local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
      lVar5 = -0x3ffffe7c;
      local_20 = "VirtualMachine::DeviceOpenChannel";
      local_10 = "%d";
      OnFailure((ErrorSite *)&local_28,-0x3ffffe7c);
    }
    else {
      if ((iVar1 != 1) && (iVar1 != 2)) {
        if (iVar1 != 3) {
          if ((iVar1 == 4) || (iVar1 == 5)) goto LAB_1c0004dfc;
          local_18 = 0x176;
          local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
          local_20 = "VirtualMachine::DeviceOpenChannel";
          local_10 = "%d";
          OnFailure((ErrorSite *)&local_28,-0x3fffffff);
          pcVar3 = (code *)swi(0x29);
          (*pcVar3)(5);
          puVar4 = auStack_40;
        }
        *param_2 = *(undefined8 *)(param_1 + 0x118);
        *(undefined4 *)(param_2 + 1) = *(undefined4 *)(param_1 + 0x120);
        if (lVar2 != 0) {
          *(undefined8 *)(puVar4 + -8) = 0x1c0004ddd;
          ExReleasePushLockExclusiveEx(lVar2,0);
          *(undefined8 *)(puVar4 + -8) = 0x1c0004de9;
          KeLeaveCriticalRegion();
        }
        goto LAB_1c0004e87;
      }
      lVar5 = -0x3fffff5d;
    }
  }
  else {
    local_10 = (char *)0x0;
    local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
    local_18 = 0x15d;
    lVar5 = -0x3ffffe7c;
    local_20 = "VirtualMachine::DeviceOpenChannel";
    OnFailure((ErrorSite *)&local_28,-0x3ffffe7c);
  }
  local_10 = (char *)0x0;
  local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
  local_18 = 0x3b5;
  local_20 = "ChOpenChannel";
  OnFailure((ErrorSite *)&local_28,lVar5);
  if (lVar2 != 0) {
    ExReleasePushLockExclusiveEx(lVar2,0);
    KeLeaveCriticalRegion();
  }
  puVar4 = auStack_48;
LAB_1c0004e87:
  return (long)*(undefined8 *)(puVar4 + 0x60);
}



===== ChOpenResult @ 1c0004eb0 =====

void ChOpenResult(Channel *param_1,long param_2)

{
  longlong lVar1;
  code *pcVar2;
  long lVar3;
  undefined1 *puVar4;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [24];
  undefined8 ***local_38;
  undefined8 ***local_30;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x18) + 0x18);
  local_30 = &local_38;
  local_38 = &local_38;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(lVar1,0);
  lVar3 = VirtualMachine::DeviceCompleteOpen
                    ((VirtualMachine *)(lVar1 + 8),param_1,param_2,(CompletedIrps *)&local_38);
  puVar4 = auStack_58;
  if (lVar3 < 0) {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
    local_18 = 0x3bf;
    local_20 = "ChOpenResult";
    OnFailure((ErrorSite *)&local_28,lVar3);
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_50;
  }
  if (lVar1 != 0) {
    *(undefined8 *)(puVar4 + -8) = 0x1c0004f5e;
    ExReleasePushLockExclusiveEx(lVar1,0);
    *(undefined8 *)(puVar4 + -8) = 0x1c0004f6a;
    KeLeaveCriticalRegion();
  }
  *(undefined8 *)(puVar4 + -8) = 0x1c0004f78;
  CompletedIrps::~CompletedIrps((CompletedIrps *)&local_38);
  return;
}



===== ChQueueWorkItem @ 1c0004fa0 =====

undefined1 ChQueueWorkItem(undefined8 param_1,longlong *param_2,longlong param_3,longlong param_4)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined8 uVar6;
  undefined1 uVar7;
  undefined8 *puVar8;
  undefined1 *puVar9;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  longlong local_48;
  undefined8 uStack_40;
  longlong local_38;
  undefined8 uStack_30;
  
  lVar3 = param_2[2];
  lVar1 = lVar3 + 8;
  uVar7 = KeAcquireSpinLockRaiseToDpc(lVar1);
  uVar6 = uStack_40;
  puVar9 = auStack_68;
  uStack_40._0_5_ = CONCAT41(uStack_40._1_4_,uVar7);
  uStack_40._5_2_ = SUB82(uVar6,5);
  uStack_40._7_1_ = SUB81(uVar6,7);
  local_48 = lVar1;
  if ((longlong *)*param_2 == param_2) {
    plVar2 = (longlong *)(lVar3 + 0x10);
    plVar4 = (longlong *)*plVar2;
    param_2[3] = param_3;
    param_2[4] = param_4;
    puVar8 = *(undefined8 **)(lVar3 + 0x18);
    if ((longlong *)*puVar8 != plVar2) {
      pcVar5 = (code *)swi(0x29);
      puVar8 = (undefined8 *)(*pcVar5)(3);
      puVar9 = auStack_60;
    }
    *param_2 = (longlong)plVar2;
    param_2[1] = (longlong)puVar8;
    *puVar8 = param_2;
    *(longlong **)(lVar3 + 0x18) = param_2;
    if (lVar1 != 0) {
      *(undefined8 *)(puVar9 + -8) = 0x1c000505e;
      wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_48);
    }
    if (plVar4 == plVar2) {
      *(undefined8 *)(puVar9 + -8) = 0x1c0005073;
      KeSetEvent(lVar3 + 0x20,0,0);
    }
    uVar7 = 1;
  }
  else {
    uVar7 = 0;
    if (lVar1 != 0) {
      uStack_30 = uStack_40;
      local_38 = lVar1;
      wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_38);
    }
  }
  return uVar7;
}



===== ChRegisterIsr @ 1c00050b0 =====

void ChRegisterIsr(longlong param_1,longlong param_2,undefined8 param_3)

{
  code *pcVar1;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  if (((*(longlong *)(param_1 + 0x158) == 0) && (param_2 != 0)) &&
     (*(longlong *)(param_1 + 0x178) != 0)) {
    *(longlong *)(param_1 + 0x158) = param_2;
    *(undefined8 *)(param_1 + 0x160) = param_3;
    KeInitializeDpc(param_1 + 0x180,DeviceSignalEventDpcRoutine,param_1);
    KeInitializeTimer(param_1 + 0x1c0);
    ExInitializeRundownProtection(param_1 + 0x170);
    ExAcquireRundownProtection(param_1 + 0x170);
    ExQueueDpcEventWait(*(undefined8 *)(param_1 + 0x178),0);
    return;
  }
  local_10 = 0;
  local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
  local_18 = 0x421;
  local_20 = "ChRegisterIsr";
  OnFailure((ErrorSite *)&local_28,-0x3fffffff);
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(5);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== ChSendInterrupt @ 1c00051b0 =====

void ChSendInterrupt(Channel *param_1)

{
  SignalVmm(param_1);
  return;
}



===== ChSetInterruptPreferredProcessor @ 1c00051d0 =====

undefined8 ChSetInterruptPreferredProcessor(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 ***local_38;
  undefined8 ***local_30;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_30 = &local_38;
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x18) + 0x18);
  local_38 = &local_38;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(lVar1,0);
  if (*(char *)(lVar1 + 0x18) == '\0') {
    uVar2 = param_2[1];
    *(undefined8 *)(param_1 + 0x128) = *param_2;
    *(undefined8 *)(param_1 + 0x130) = uVar2;
    VirtualMachine::WakeVmm((VirtualMachine *)(lVar1 + 8),(CompletedIrps *)&local_38);
    if (lVar1 != 0) {
      ExReleasePushLockExclusiveEx(lVar1,0);
      KeLeaveCriticalRegion();
    }
    uVar2 = 0;
  }
  else {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
    local_18 = 0x1c3;
    uVar2 = 0xc0000184;
    local_20 = "VirtualMachine::DeviceSetInterruptPreferredProcessor";
    OnFailure((ErrorSite *)&local_28,-0x3ffffe7c);
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
    local_18 = 0x48e;
    local_20 = "ChSetInterruptPreferredProcessor";
    OnFailure((ErrorSite *)&local_28,-0x3ffffe7c);
    if (lVar1 != 0) {
      ExReleasePushLockExclusiveEx(lVar1,0);
      KeLeaveCriticalRegion();
    }
  }
  CompletedIrps::~CompletedIrps((CompletedIrps *)&local_38);
  return uVar2;
}



===== ChUnlockChildPages @ 1c0005320 =====

undefined8 ChUnlockChildPages(undefined8 param_1,undefined8 param_2,longlong param_3,uint param_4)

{
  ulonglong local_18;
  longlong local_10;
  
  local_18 = (ulonglong)param_4;
  if ((param_3 == 0) && (param_4 != 0)) {
                    /* WARNING: Subroutine does not return */
    gsl::details::terminate();
  }
  local_10 = param_3;
  UnlockChildPages((longlong *)&local_18);
  return 0;
}



===== ChUnmapChildMmioSpace @ 1c0005360 =====

void ChUnmapChildMmioSpace(void)

{
  code *pcVar1;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_10 = 0;
  local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
  local_18 = 0x4fc;
  local_20 = "ChUnmapChildMmioSpace";
  OnFailure((ErrorSite *)&local_28,-0x3fffffff);
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(5);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== ChUnmapGpadlView @ 1c00053b0 =====

long ChUnmapGpadlView(longlong param_1,undefined4 param_2)

{
  longlong lVar1;
  longlong lVar2;
  long lVar3;
  undefined8 local_38;
  longlong lStack_30;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_20 = (char *)0x0;
  local_18 = 0;
  local_28 = (char *)CONCAT44(local_28._4_4_,param_2);
  local_38 = 0;
  lStack_30 = 0;
  lVar3 = GpadlSet::LockGpadl((GpadlSet *)(param_1 + 0x28),(GpadlKey *)&local_28,
                              (LockedGpadl *)&local_38);
  if (lVar3 < 0) {
    local_18 = 0x3d4;
  }
  else {
    lVar1 = *(longlong *)(lStack_30 + 0x38);
    if (lVar1 != 0) {
      *(undefined8 *)(lStack_30 + 0x38) = 0;
      MdlMapping::~MdlMapping((MdlMapping *)(lVar1 + 0x20));
      lVar2 = *(longlong *)(lVar1 + 0x18);
      *(undefined8 *)(lVar1 + 0x18) = 0;
      if (lVar2 != 0) {
        IoFreeMdl();
      }
      wistd::
      unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
      ::
      ~unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
                ((unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
                  *)(lVar1 + 0x10));
      ExFreePoolWithTag(lVar1,0);
      lVar3 = 0;
      goto LAB_1c0005479;
    }
    local_18 = 0x3d7;
    lVar3 = -0x3ffffff3;
  }
  local_10 = 0;
  local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
  local_20 = "ChUnmapGpadlView";
  OnFailure((ErrorSite *)&local_28,lVar3);
LAB_1c0005479:
  LockedGpadl::reset((LockedGpadl *)&local_38);
  return lVar3;
}



===== ChUnregisterIsr @ 1c00054a0 =====

void ChUnregisterIsr(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  char cVar4;
  longlong local_18;
  undefined1 uStack_10;
  undefined4 uStack_f;
  undefined2 uStack_b;
  undefined1 uStack_9;
  
  lVar1 = param_1 + 0x150;
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
  uVar2 = _uStack_10;
  _uStack_10 = CONCAT41(uStack_f,uVar3);
  uStack_b = SUB82(uVar2,5);
  uStack_9 = SUB81(uVar2,7);
  local_18 = lVar1;
  if (*(longlong *)(param_1 + 0x158) == 0) {
    if (lVar1 != 0) {
      wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_18);
    }
  }
  else {
    cVar4 = ExCancelDpcEventWait(*(undefined8 *)(param_1 + 0x178));
    if (((cVar4 != '\0') || (cVar4 = KeCancelTimer(param_1 + 0x1c0), cVar4 != '\0')) ||
       (cVar4 = KeRemoveQueueDpc(param_1 + 0x180), cVar4 != '\0')) {
      ExReleaseRundownProtection(param_1 + 0x170);
    }
    *(undefined1 *)(param_1 + 0x168) = 1;
    if (lVar1 != 0) {
      wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_18);
    }
    ExWaitForRundownProtectionRelease(param_1 + 0x170);
    *(undefined8 *)(param_1 + 0x158) = 0;
    *(undefined8 *)(param_1 + 0x160) = 0;
    *(undefined1 *)(param_1 + 0x168) = 0;
  }
  return;
}



===== DeviceGetTopology @ 1c00055dc =====

/* unsigned int __cdecl DeviceGetTopology(struct VirtualMachineFile & __ptr64,class
   gsl::span<unsigned int,-1>,unsigned int * __ptr64) */

uint __cdecl DeviceGetTopology(longlong param_1,ulonglong *param_2,undefined4 *param_3)

{
  longlong lVar1;
  uint uVar2;
  undefined1 uVar3;
  ulonglong uVar4;
  undefined4 uStack_1f;
  undefined2 uStack_1b;
  undefined1 uStack_19;
  ulonglong local_18;
  void *pvStack_10;
  
  lVar1 = param_1 + 0x78;
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
  *param_3 = *(undefined4 *)(param_1 + 0x80);
  uVar4 = (ulonglong)*(uint *)(param_1 + 0x84);
  if (uVar4 <= *param_2) {
    if (*(void **)(param_1 + 0x88) != (void *)0x0) {
      local_18 = *param_2;
      pvStack_10 = (void *)param_2[1];
      if (uVar4 <= local_18) {
        if ((((pvStack_10 != (void *)0x0) || (local_18 * 4 == 0)) && (uVar4 <= local_18 * 4)) &&
           ((pvStack_10 != (void *)0x0 || (uVar4 == 0)))) {
          memcpy(pvStack_10,*(void **)(param_1 + 0x88),uVar4 * 4);
          goto LAB_1c00056a4;
        }
      }
                    /* WARNING: Subroutine does not return */
      gsl::details::terminate();
    }
    memset((void *)param_2[1],0,uVar4 << 2);
  }
LAB_1c00056a4:
  uVar2 = *(uint *)(param_1 + 0x84);
  if (lVar1 != 0) {
    pvStack_10 = (void *)CONCAT17(uStack_19,CONCAT25(uStack_1b,CONCAT41(uStack_1f,uVar3)));
    local_18 = lVar1;
    wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_18);
  }
  return uVar2;
}



===== DeviceIoctlMapGpadl @ 1c00056e8 =====

/* long __cdecl DeviceIoctlMapGpadl(struct VirtualMachineFile & __ptr64,struct Channel &
   __ptr64,char,struct _VMBUS_MAP_GPADL_VIEW_INPUT_PARAMS const & __ptr64,struct
   _VMBUS_MAP_GPADL_VIEW_OUTPUT_PARAMS * __ptr64) */

long __cdecl
DeviceIoctlMapGpadl(VirtualMachineFile *param_1,Channel *param_2,char param_3,
                   _VMBUS_MAP_GPADL_VIEW_INPUT_PARAMS *param_4,
                   _VMBUS_MAP_GPADL_VIEW_OUTPUT_PARAMS *param_5)

{
  long lVar1;
  _MDL *p_Var2;
  uint uVar3;
  uint uVar4;
  void *local_res10;
  char *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  longlong lStack_50;
  undefined8 ****local_48;
  undefined8 ****local_40;
  char *local_38;
  char *local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  local_70 = 0;
  local_40 = &local_48;
  local_68 = 0;
  local_48 = &local_48;
  local_78 = (char *)CONCAT44(local_78._4_4_,*(undefined4 *)param_4);
  local_58 = 0;
  lStack_50 = 0;
  lVar1 = GpadlSet::LockGpadl((GpadlSet *)(param_2 + 0x28),(GpadlKey *)&local_78,
                              (LockedGpadl *)&local_58);
  if (lVar1 < 0) {
    local_68 = 0xfe;
  }
  else {
    uVar3 = 0x40000010;
    if ((*(uint *)(param_4 + 4) & 1) == 0) {
      uVar4 = (-(uint)((*(uint *)(param_4 + 4) & 4) != 0) & 2) + 2;
    }
    else {
      uVar3 = 0xc0000010;
      uVar4 = 1;
    }
    lVar1 = MapLockedGpadl(param_1,(LockedGpadl *)&local_58,uVar4);
    if (-1 < lVar1) {
      local_78 = (char *)&local_58;
      local_70._0_1_ = 1;
      if (*(uint *)(lStack_50 + 0x14) < 2) {
        p_Var2 = (_MDL *)**(undefined8 **)(*(longlong *)(lStack_50 + 0x38) + 0x10);
        if ((*(uint *)(param_4 + 4) & 2) != 0) {
          lVar1 = AllocateRingBufferPartialMdl
                            (p_Var2,*(uint *)(param_4 + 8),
                             (unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_IoFreeMdl(struct__MDL*___ptr64)>_>
                              *)(*(longlong *)(lStack_50 + 0x38) + 0x18));
          if (lVar1 < 0) {
            local_28 = 0x11e;
            goto LAB_1c00057eb;
          }
          p_Var2 = *(_MDL **)(*(longlong *)(lStack_50 + 0x38) + 0x18);
        }
        local_res10 = (void *)0x0;
        uVar4 = uVar3 | 0x20000000;
        if (param_3 != '\x01') {
          uVar4 = uVar3;
        }
        lVar1 = MdlMapping::Map((MdlMapping *)(*(longlong *)(lStack_50 + 0x38) + 0x20),p_Var2,
                                param_3,uVar4,&local_res10);
        if (lVar1 < 0) {
          local_20 = 0;
          local_38 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
          local_28 = 0x128;
          local_30 = "DeviceIoctlMapGpadl";
          OnFailure((ErrorSite *)&local_38,lVar1);
          wil::details::lambda_call<<lambda_ff71274176b5d6cd7a946c61720e63be>_>::
          ~lambda_call<<lambda_ff71274176b5d6cd7a946c61720e63be>_>((longlong *)&local_78);
          goto LAB_1c000590f;
        }
        local_70._0_1_ = 0;
        *(void **)param_5 = local_res10;
        *(ulonglong *)(param_5 + 8) = (ulonglong)*(uint *)(p_Var2 + 0x28);
        lVar1 = LockedGpadl::CommitMapping((LockedGpadl *)&local_58,(CompletedIrps *)&local_48);
        if (-1 < lVar1) {
          wil::details::lambda_call<<lambda_ff71274176b5d6cd7a946c61720e63be>_>::
          ~lambda_call<<lambda_ff71274176b5d6cd7a946c61720e63be>_>((longlong *)&local_78);
          lVar1 = 0;
          goto LAB_1c000590f;
        }
        local_28 = 0x12d;
      }
      else {
        lVar1 = -0x3fffff45;
        local_28 = 0x118;
      }
LAB_1c00057eb:
      local_20 = 0;
      local_38 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
      local_30 = "DeviceIoctlMapGpadl";
      OnFailure((ErrorSite *)&local_38,lVar1);
      wil::details::lambda_call<<lambda_ff71274176b5d6cd7a946c61720e63be>_>::
      ~lambda_call<<lambda_ff71274176b5d6cd7a946c61720e63be>_>((longlong *)&local_78);
      goto LAB_1c000590f;
    }
    local_68 = 0x110;
  }
  local_60 = 0;
  local_78 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
  local_70._0_1_ = 0x40;
  local_70._1_7_ = 0x1c000c3;
  OnFailure((ErrorSite *)&local_78,lVar1);
LAB_1c000590f:
  LockedGpadl::reset((LockedGpadl *)&local_58);
  CompletedIrps::~CompletedIrps((CompletedIrps *)&local_48);
  return lVar1;
}



===== DeviceIoctlRdmaCopyChildPages @ 1c0005948 =====

/* long __cdecl DeviceIoctlRdmaCopyChildPages(struct VirtualMachineFile & __ptr64,struct _IRP *
   __ptr64) */

long __cdecl DeviceIoctlRdmaCopyChildPages(VirtualMachineFile *param_1,_IRP *param_2)

{
  char *pcVar1;
  longlong lVar2;
  long lVar3;
  char *pcVar4;
  longlong local_res10;
  char *local_48;
  longlong local_40;
  char *local_38;
  char *pcStack_30;
  undefined8 local_28;
  undefined8 local_20;
  
  local_res10 = 0;
  lVar3 = VmbusRdmaCopyChildPagesParseInput
                    (0,*(undefined8 *)(*(longlong *)(param_2 + 0xb8) + 0x20),
                     *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10),&local_res10);
  lVar2 = local_res10;
  if (lVar3 < 0) {
    local_20 = 0;
    local_38 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
    local_28 = 0x148;
    pcStack_30 = "DeviceIoctlRdmaCopyChildPages";
    OnFailure((ErrorSite *)&local_38,lVar3);
    return lVar3;
  }
  *(_IRP **)(local_res10 + 8) = param_2;
  local_40 = *(longlong *)(local_res10 + 0x10);
  pcVar4 = (char *)(ulonglong)*(uint *)(local_res10 + 0x28);
  if (((local_40 == 0) && (pcVar4 != (char *)0x0)) ||
     ((pcVar1 = *(char **)(local_res10 + 0x18), pcVar1 == (char *)0x0 && (pcVar4 != (char *)0x0))))
  {
                    /* WARNING: Subroutine does not return */
    gsl::details::terminate();
  }
  local_48 = pcVar4;
  local_38 = pcVar4;
  pcStack_30 = pcVar1;
  lVar3 = LockChildPages(param_1,(*(char *)(local_res10 + 0x30) != '\0') + 1,(ulonglong *)&local_48,
                         (ulonglong *)&local_38);
  if (lVar3 < 0) {
    local_20 = 0;
    local_38 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
    local_28 = 0x14f;
    pcStack_30 = "DeviceIoctlRdmaCopyChildPages";
    OnFailure((ErrorSite *)&local_38,lVar3);
  }
  else {
    lVar3 = VmbusRdmaCopyChildPages(lVar2);
    if (-1 < lVar3) {
      local_38 = pcVar4;
      pcStack_30 = pcVar1;
      UnlockChildPages((longlong *)&local_38);
      ExFreePoolWithTag(lVar2,0);
      return 0;
    }
    local_20 = 0;
    local_38 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
    local_28 = 0x154;
    pcStack_30 = "DeviceIoctlRdmaCopyChildPages";
    OnFailure((ErrorSite *)&local_38,lVar3);
    local_38 = pcVar4;
    pcStack_30 = pcVar1;
    UnlockChildPages((longlong *)&local_38);
  }
  ExFreePoolWithTag(lVar2,0);
  return lVar3;
}



===== DeviceSignalEventDpcRoutine @ 1c0005b10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl DeviceSignalEventDpcRoutine(struct _KDPC * __ptr64,void * __ptr64,void *
   __ptr64,void * __ptr64) */

void __cdecl DeviceSignalEventDpcRoutine(_KDPC *param_1,void *param_2,void *param_3,void *param_4)

{
  longlong lVar1;
  uint *puVar2;
  code *pcVar3;
  longlong lVar4;
  char *pcVar5;
  undefined1 uVar6;
  char cVar7;
  undefined1 auStackY_98 [32];
  char *local_68;
  char *pcStack_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48 [4];
  ulonglong local_28;
  
  lVar4 = _DAT_fffff78000000008;
  local_28 = __security_cookie ^ (ulonglong)auStackY_98;
  lVar1 = (longlong)param_2 + 0x150;
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
  pcVar5 = pcStack_60;
  pcStack_60._0_5_ = CONCAT41(pcStack_60._1_4_,uVar6);
  pcStack_60._5_2_ = SUB82(pcVar5,5);
  pcStack_60._7_1_ = SUB81(pcVar5,7);
  local_68 = (char *)lVar1;
  if (*(char *)((longlong)param_2 + 0x168) == '\0') {
    puVar2 = (uint *)((longlong)param_2 + 0x208);
    if (10000000 < (ulonglong)(lVar4 - *(longlong *)((longlong)param_2 + 0x200))) {
      *puVar2 = 0;
      *(longlong *)((longlong)param_2 + 0x200) = lVar4;
    }
    if (*puVar2 < 1000) {
      ExQueueDpcEventWait(*(undefined8 *)((longlong)param_2 + 0x178),1);
      cVar7 = (**(code **)((longlong)param_2 + 0x158))(*(undefined8 *)((longlong)param_2 + 0x160));
      if (cVar7 == '\0') {
        *puVar2 = *puVar2 + 1;
      }
    }
    else {
      if (2 < DAT_1c000e008) {
        _tlgWriteTransfer_EtwWriteTransfer(0x1c000e008,&DAT_1c000cf11,0,0,2,local_48);
      }
      cVar7 = KeSetTimer((longlong)param_2 + 0x1c0,0xfffffffffd050f80,(longlong)param_2 + 0x180);
      if (cVar7 != '\0') {
        local_50 = 0;
        local_68 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
        local_58 = 0x416;
        pcStack_60 = "DeviceSignalEventDpcRoutine";
        OnFailure((ErrorSite *)&local_68,-0x3fffffff);
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(5);
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
    }
  }
  else {
    ExReleaseRundownProtection((longlong)param_2 + 0x170);
  }
  if (lVar1 != 0) {
    wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_68);
  }
  return;
}



===== DriverUnload @ 1c0005cd0 =====

/* void __cdecl DriverUnload(struct _DRIVER_OBJECT * __ptr64) */

void __cdecl DriverUnload(_DRIVER_OBJECT *param_1)

{
  undefined8 uVar1;
  
  if (g_controlDevice != (_DEVICE_OBJECT *)0x0) {
    IoDeleteDevice();
    g_controlDevice = (_DEVICE_OBJECT *)0x0;
  }
  uVar1 = DAT_1c000e028;
  DAT_1c000e028 = 0;
  DAT_1c000e008 = 0;
  EtwUnregister(uVar1);
  return;
}



===== HandleIrpCleanup @ 1c0005d24 =====

/* long __cdecl HandleIrpCleanup(struct _IRP * __ptr64) */

long __cdecl HandleIrpCleanup(_IRP *param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  int iVar3;
  undefined8 ***local_28;
  undefined8 ***local_20;
  
  uVar1 = *(ulonglong *)(*(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x30) + 0x20);
  lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x30) + 0x18);
  iVar3 = 2;
  if (uVar1 < 4) {
    iVar3 = (int)uVar1;
  }
  if (iVar3 == 0) {
    local_20 = &local_28;
    local_28 = &local_28;
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(lVar2,0);
    VirtualMachine::VmmCleanupFile((VirtualMachine *)(lVar2 + 8),(CompletedIrps *)&local_28);
    if (lVar2 != 0) {
      ExReleasePushLockExclusiveEx(lVar2,0);
      KeLeaveCriticalRegion();
    }
    CompletedIrps::~CompletedIrps((CompletedIrps *)&local_28);
  }
  return 0;
}



===== HandleIrpClose @ 1c0005dcc =====

/* long __cdecl HandleIrpClose(struct _IRP * __ptr64) */

long __cdecl HandleIrpClose(_IRP *param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  code *pcVar4;
  int iVar5;
  undefined1 *puVar6;
  Channel *pCVar7;
  undefined8 uStack_70;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  undefined8 ****local_48;
  undefined8 ****local_40;
  undefined8 local_38;
  undefined8 local_30;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  pCVar7 = *(Channel **)(*(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x30) + 0x20);
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x30) + 0x18);
  if (pCVar7 < (Channel *)0x4) {
    iVar5 = (int)pCVar7;
    pCVar7 = (Channel *)0x0;
  }
  else {
    iVar5 = 2;
  }
  local_48 = (undefined8 ****)(ulonglong)(uint)local_48;
  if (iVar5 == 0) {
    if (lVar1 == 0) {
      return 0;
    }
    lVar3 = *(longlong *)(lVar1 + 0x88);
    *(undefined8 *)(lVar1 + 0x88) = 0;
    if (lVar3 != 0) {
      ExFreePoolWithTag(lVar3,0);
    }
    lVar3 = *(longlong *)(lVar1 + 0x60);
    *(undefined8 *)(lVar1 + 0x60) = 0;
    if (lVar3 != 0) {
      ObfDereferenceObject();
    }
    VirtualMachine::~VirtualMachine((VirtualMachine *)(lVar1 + 8));
    ExFreePoolWithTag(lVar1,0);
    return 0;
  }
  puVar6 = auStack_68;
  if (iVar5 != 1) {
    puVar6 = auStack_68;
    if (iVar5 != 2) {
      puVar6 = auStack_68;
      if (iVar5 == 3) goto LAB_1c0005f10;
      local_30 = 0;
      local_48 = (undefined8 ****)0x1c000c2b0;
      local_38 = 0x393;
      local_40 = (undefined8 ****)0x1c000c408;
      OnFailure((ErrorSite *)&local_48,-0x3fffffff);
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(5);
      puVar6 = auStack_60;
    }
    local_40 = &local_48;
    local_48 = &local_48;
    *(undefined8 *)(puVar6 + -8) = 0x1c0005e78;
    KeEnterCriticalRegion();
    *(undefined8 *)(puVar6 + -8) = 0x1c0005e89;
    ExAcquirePushLockExclusiveEx(lVar1,0);
    *(undefined8 *)(pCVar7 + 0x18) = 0;
    if (*(longlong *)(pCVar7 + 0x158) != 0) {
      local_10 = 0;
      local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
      local_18 = 0x37f;
      local_20 = "HandleIrpClose";
      *(undefined8 *)(puVar6 + -8) = 0x1c0005ece;
      OnFailure((ErrorSite *)&local_28,-0x3fffffff);
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(5);
      puVar6 = puVar6 + 8;
    }
    *(undefined8 *)(puVar6 + -8) = 0x1c0005ee5;
    VirtualMachine::DeviceCloseFile((VirtualMachine *)(lVar1 + 8),pCVar7,(CompletedIrps *)&local_48)
    ;
    if (lVar1 != 0) {
      *(undefined8 *)(puVar6 + -8) = 0x1c0005ef6;
      ExReleasePushLockExclusiveEx(lVar1,0);
      *(undefined8 *)(puVar6 + -8) = 0x1c0005f02;
      KeLeaveCriticalRegion();
    }
    *(undefined8 *)(puVar6 + -8) = 0x1c0005f10;
    CompletedIrps::~CompletedIrps((CompletedIrps *)&local_48);
  }
LAB_1c0005f10:
  uVar2 = *(undefined8 *)(lVar1 + 0x50);
  *(undefined8 *)(puVar6 + -8) = 0x1c0005f1b;
  ObfDereferenceObject(uVar2);
  return 0;
}



===== HandleIrpCreate @ 1c0005f98 =====

/* long __cdecl HandleIrpCreate(struct _IRP * __ptr64) */

long __cdecl HandleIrpCreate(_IRP *param_1)

{
  short *psVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  char cVar5;
  long lVar6;
  void *_Dst;
  undefined8 uVar7;
  uint uVar8;
  Channel *local_res8;
  char *local_38;
  char *local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x30);
  lVar3 = *(longlong *)(lVar2 + 0x40);
  if (lVar3 == 0) {
    if (*(short *)(lVar2 + 0x58) == 0) {
      _Dst = operator_new(0x90);
      if (_Dst == (void *)0x0) {
        local_res8 = (Channel *)0x0;
        local_38 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
        local_28 = 0x324;
        local_30 = "HandleIrpCreate";
        local_20 = 0;
        OnFailure((ErrorSite *)&local_38,-0x3fffff66);
        wistd::unique_ptr<VirtualMachineFile,wistd::default_delete<VirtualMachineFile>_>::
        ~unique_ptr<VirtualMachineFile,wistd::default_delete<VirtualMachineFile>_>
                  ((unique_ptr<VirtualMachineFile,wistd::default_delete<VirtualMachineFile>_> *)
                   &local_res8);
        return -0x3fffff66;
      }
      memset(_Dst,0,0x90);
      lVar3 = (longlong)_Dst + 8;
      *(longlong *)((longlong)_Dst + 0x10) = lVar3;
      *(longlong *)lVar3 = lVar3;
      *(undefined8 *)((longlong)_Dst + 0x20) = 1;
      *(undefined8 *)((longlong)_Dst + 0x28) = 0;
      *(undefined8 *)((longlong)_Dst + 0x30) = 0;
      *(undefined8 *)((longlong)_Dst + 0x38) = 0;
      *(undefined8 *)((longlong)_Dst + 0x50) = 0;
      *(undefined8 *)((longlong)_Dst + 0x58) = 0;
      *(undefined8 *)((longlong)_Dst + 0x60) = 0;
      KeInitializeSpinLock((longlong)_Dst + 0x78);
      *(undefined4 *)((longlong)_Dst + 0x80) = 1;
      *(undefined4 *)((longlong)_Dst + 0x84) = 1;
      *(undefined8 *)((longlong)_Dst + 0x88) = 0;
      *(longlong *)((longlong)_Dst + 0x50) = lVar2;
      *(void **)(lVar2 + 0x18) = _Dst;
      *(undefined8 *)(lVar2 + 0x20) = 0;
      local_res8 = (Channel *)0x0;
      wistd::unique_ptr<VirtualMachineFile,wistd::default_delete<VirtualMachineFile>_>::
      ~unique_ptr<VirtualMachineFile,wistd::default_delete<VirtualMachineFile>_>
                ((unique_ptr<VirtualMachineFile,wistd::default_delete<VirtualMachineFile>_> *)
                 &local_res8);
      return 0;
    }
    local_28 = 0x31e;
LAB_1c0005fdd:
    lVar6 = -0x3fffffcc;
    goto LAB_1c0005fe2;
  }
  lVar4 = *(longlong *)(lVar3 + 0x18);
  psVar1 = (short *)(lVar2 + 0x58);
  uVar8 = 2;
  if (*(ulonglong *)(lVar3 + 0x20) < 4) {
    uVar8 = (uint)*(ulonglong *)(lVar3 + 0x20);
  }
  local_38 = (char *)(ulonglong)(uint)local_38;
  if (*psVar1 == 0) {
    uVar7 = 1;
LAB_1c000614a:
    if (uVar8 == 0) {
      *(undefined8 *)(lVar2 + 0x20) = uVar7;
      *(longlong *)(lVar2 + 0x18) = lVar4;
      ObfReferenceObject(*(undefined8 *)(lVar4 + 0x50));
      return 0;
    }
    local_28 = 0x338;
  }
  else {
    cVar5 = RtlEqualUnicodeString(psVar1,&DAT_1c000c000,0);
    if (cVar5 == '\0') {
      cVar5 = RtlEqualUnicodeString(psVar1,&DAT_1c000c010,0);
      if (cVar5 == '\0') {
        local_28 = 0x358;
        goto LAB_1c0005fdd;
      }
      uVar7 = 3;
      goto LAB_1c000614a;
    }
    if (uVar8 < 2) {
      KeEnterCriticalRegion();
      ExAcquirePushLockExclusiveEx(lVar4,0);
      local_res8 = (Channel *)0x0;
      lVar6 = VirtualMachine::DeviceCreateChannel((VirtualMachine *)(lVar4 + 8),&local_res8);
      if (lVar6 < 0) {
        local_28 = 0x34c;
        local_38 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
        local_20 = 0;
        local_30 = "HandleIrpCreate";
        OnFailure((ErrorSite *)&local_38,lVar6);
        if (lVar4 != 0) {
          ExReleasePushLockExclusiveEx(lVar4,0);
          KeLeaveCriticalRegion();
        }
        return lVar6;
      }
      *(longlong *)(local_res8 + 0x18) = lVar2;
      *(longlong *)(lVar2 + 0x18) = lVar4;
      *(Channel **)(lVar2 + 0x20) = local_res8;
      ObfReferenceObject(*(undefined8 *)(lVar4 + 0x50));
      if (lVar4 == 0) {
        return 0;
      }
      ExReleasePushLockExclusiveEx(lVar4,0);
      KeLeaveCriticalRegion();
      return 0;
    }
    local_28 = 0x347;
  }
  lVar6 = -0x3ffffff3;
LAB_1c0005fe2:
  local_20 = 0;
  local_38 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
  local_30 = "HandleIrpCreate";
  OnFailure((ErrorSite *)&local_38,lVar6);
  return lVar6;
}



===== HandleIrpIoctl @ 1c000628c =====

/* long __cdecl HandleIrpIoctl(struct _IRP * __ptr64) */

long __cdecl HandleIrpIoctl(_IRP *param_1)

{
  uint uVar1;
  char *pcVar2;
  undefined8 *puVar3;
  char *pcVar4;
  longlong lVar5;
  VirtualMachineFile *pVVar6;
  uint uVar7;
  undefined8 uVar8;
  VirtualMachineFile *this;
  _IRP *p_Var9;
  _IRP *local_res8;
  VirtualMachineFile *local_res10;
  VirtualMachineFile *local_res18 [2];
  VirtualMachineFile *local_b8;
  Channel **ppCStack_b0;
  _IRP **local_a8;
  _IRP **local_a0;
  _IRP *local_98;
  undefined8 uStack_90;
  _IRP *local_88;
  undefined8 *puStack_80;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  _IRP *local_68;
  VirtualMachineFile *local_60;
  Channel **local_58;
  _IRP **local_50;
  int local_48;
  undefined4 local_44;
  VirtualMachineFile *local_40;
  Channel *local_38 [2];
  
  pcVar2 = *(char **)(param_1 + 0xb8);
  local_res8 = param_1;
  if ((*pcVar2 == '\x0e') && ((*(uint *)(pcVar2 + 0x18) & 3) == 0)) {
    puVar3 = *(undefined8 **)(param_1 + 0x18);
    p_Var9 = (_IRP *)(ulonglong)*(uint *)(pcVar2 + 0x10);
    if ((puVar3 == (undefined8 *)0x0) && (p_Var9 != (_IRP *)0x0)) goto LAB_1c00068be;
    local_98 = p_Var9;
    if (puVar3 == (undefined8 *)0x0) {
      uStack_90 = (_IRP **)0x0;
      if (p_Var9 != (_IRP *)0x0) goto LAB_1c00068be;
    }
  }
  else {
    local_98 = (_IRP *)0x0;
    uStack_90 = (_IRP **)0x0;
    puVar3 = uStack_90;
  }
  uStack_90 = (_IRP **)puVar3;
  puVar3 = uStack_90;
  p_Var9 = local_98;
  uVar7 = 0;
  local_88 = local_98;
  puStack_80 = uStack_90;
  pcVar4 = *(char **)(param_1 + 0xb8);
  if ((*pcVar4 == '\x0e') && ((*(uint *)(pcVar4 + 0x18) & 3) == 0)) {
    lVar5 = *(longlong *)(param_1 + 0x18);
    local_98 = (_IRP *)(ulonglong)*(uint *)(pcVar4 + 8);
    if (lVar5 == 0) {
      uStack_90 = (_IRP **)0x0;
      if (local_98 != (_IRP *)0x0) goto LAB_1c00068be;
    }
  }
  else {
    local_98 = (_IRP *)0x0;
    uStack_90 = (_IRP **)0x0;
    lVar5 = (longlong)uStack_90;
  }
  uStack_90 = (_IRP **)lVar5;
  local_68 = param_1 + 0x38;
  local_78 = local_98._0_4_;
  uStack_74 = 0;
  uStack_70 = (undefined4)uStack_90;
  uStack_6c = uStack_90._4_4_;
  uStack_90 = &local_98;
  pVVar6 = *(VirtualMachineFile **)(*(longlong *)(pcVar2 + 0x30) + 0x18);
  local_38[0] = *(Channel **)(*(longlong *)(pcVar2 + 0x30) + 0x20);
  if (local_38[0] < (Channel *)0x4) {
    local_48 = (int)local_38[0];
    local_38[0] = (Channel *)0x0;
  }
  else {
    local_48 = 2;
  }
  local_44 = 0;
  local_40 = pVVar6;
  if (local_48 == 0) {
    uVar7 = *(uint *)(pcVar2 + 0x18);
    if (uVar7 < 0x22c019) {
      if (uVar7 == 0x22c018) {
        ppCStack_b0 = (Channel **)&local_res8;
        local_a8 = &local_98;
        if ((_IRP *)0x7 < p_Var9) {
          if (puVar3 != (undefined8 *)0x0) {
            local_res10 = (VirtualMachineFile *)*puVar3;
            local_b8 = pVVar6;
            local_98 = (_IRP *)&local_98;
            uVar7 = <lambda_2534b7c851bf1eb982eb495919bcf656>::
                    operator()<VMBUS_PROXY_CLOSE_CHANNEL_INPUT,NoType_*>
                              ((longlong *)&local_b8,(longlong *)&local_res10);
            goto LAB_1c00068a4;
          }
        }
      }
      else {
        if (uVar7 == 0x22c004) {
          ppCStack_b0 = (Channel **)&local_88;
          local_b8 = pVVar6;
          local_98 = (_IRP *)&local_98;
          uVar7 = HandleIoctl<VMBUS_PROXY_SET_VM_NAME_INPUT,NoType,<lambda_8630579025adb04943fa9b7c0f223baf>_>
                            ((ulonglong *)&local_88,(longlong *)&local_b8);
          goto LAB_1c00068a4;
        }
        if (uVar7 == 0x22c008) {
          ppCStack_b0 = (Channel **)&local_88;
          if ((_IRP *)0xb < p_Var9) {
            if (puVar3 != (undefined8 *)0x0) {
              local_60 = (VirtualMachineFile *)*puVar3;
              local_58 = (Channel **)CONCAT44(local_58._4_4_,*(undefined4 *)(puVar3 + 1));
              local_b8 = pVVar6;
              local_98 = (_IRP *)&local_98;
              uVar7 = <lambda_c5b71ad1e55191db30ad3e5708db9c67>::
                      operator()<VMBUS_PROXY_SET_TOPOLOGY_INPUT,NoType_*>
                                ((longlong *)&local_b8,(uint *)&local_60);
              goto LAB_1c00068a4;
            }
          }
        }
        else {
          if (uVar7 != 0x22c00c) {
            if (uVar7 == 0x22c010) {
              local_58 = (Channel **)&local_res8;
              local_98 = (_IRP *)&local_98;
              local_60 = pVVar6;
              uVar7 = HandleIoctl<NoType,VMBUS_PROXY_NEXT_ACTION_OUTPUT,<lambda_305d4803163db7a4809cf44b16b40368>_>
                                ((longlong)&local_88,(longlong *)&local_60);
              goto LAB_1c00068a4;
            }
            if (uVar7 == 0x22c014) {
              ppCStack_b0 = (Channel **)&local_res8;
              local_a8 = &local_98;
              local_b8 = pVVar6;
              local_98 = (_IRP *)&local_98;
              uVar7 = HandleIoctl<VMBUS_PROXY_OPEN_CHANNEL_INPUT,VMBUS_PROXY_OPEN_CHANNEL_OUTPUT,<lambda_4ea790c742a4f2601e266a1c389fc768>_>
                                ((ulonglong *)&local_88,(longlong *)&local_b8);
              goto LAB_1c00068a4;
            }
            goto LAB_1c00067da;
          }
          local_res10 = pVVar6;
          if ((_IRP *)0xf < p_Var9) {
            if (puVar3 != (undefined8 *)0x0) {
              local_b8 = (VirtualMachineFile *)*puVar3;
              ppCStack_b0 = (Channel **)puVar3[1];
              local_98 = (_IRP *)&local_98;
              uVar8 = <lambda_c12b423d71a5f7bb004a4b40fec0c8b9>::
                      operator()<VMBUS_PROXY_SET_MEMORY_INPUT,NoType_*>
                                ((longlong *)&local_res10,(ulonglong *)&local_b8,0x22c018);
              uVar7 = (uint)uVar8;
              goto LAB_1c00068a4;
            }
          }
        }
      }
    }
    else {
      if (uVar7 == 0x22c01c) {
        ppCStack_b0 = (Channel **)&local_88;
        local_b8 = pVVar6;
        local_98 = (_IRP *)&local_98;
        uVar7 = HandleIoctl<VMBUS_PROXY_CREATE_GPADL_INPUT,NoType,<lambda_37a5d9f66724ef97eeae3c943e8c43d2>_>
                          ((ulonglong *)&local_88,(longlong *)&local_b8);
        goto LAB_1c00068a4;
      }
      if (uVar7 == 0x22c020) {
        local_58 = (Channel **)&local_res8;
        local_50 = &local_98;
        local_60 = pVVar6;
        if (((_IRP *)0xf < p_Var9) && (puVar3 != (undefined8 *)0x0)) {
          local_b8 = (VirtualMachineFile *)*puVar3;
          ppCStack_b0 = (Channel **)puVar3[1];
          local_98 = (_IRP *)&local_98;
          uVar7 = <lambda_534c481228def1137ccbf02780086789>::
                  operator()<VMBUS_PROXY_DELETE_GPADL_INPUT,NoType_*>
                            ((longlong *)&local_60,(longlong *)&local_b8);
          goto LAB_1c00068a4;
        }
      }
      else {
        if (uVar7 != 0x22c024) {
          if (uVar7 == 0x22c028) {
            local_res10 = pVVar6;
            local_98 = (_IRP *)&local_98;
            uVar7 = HandleIoctl<VMBUS_PROXY_RUN_CHANNEL_INPUT,NoType,<lambda_da8b075cbd03c62461b6f689aff894a4>_>
                              ((ulonglong *)&local_88,(longlong *)&local_res10);
            goto LAB_1c00068a4;
          }
          goto LAB_1c00067da;
        }
        local_res18[0] = pVVar6;
        if (((_IRP *)0x7 < p_Var9) && (puVar3 != (undefined8 *)0x0)) {
          local_res10 = (VirtualMachineFile *)*puVar3;
          local_98 = (_IRP *)&local_98;
          uVar8 = <lambda_708f653bac9273f243cdb8e8799c810c>::
                  operator()<VMBUS_PROXY_RELEASE_CHANNEL_INPUT,NoType_*>
                            ((longlong *)local_res18,(longlong *)&local_res10);
          uVar7 = (uint)uVar8;
          goto LAB_1c00068a4;
        }
      }
    }
    uVar7 = 0xc000000d;
    local_a8 = (_IRP **)0x1cb;
LAB_1c0006526:
    ppCStack_b0 = (Channel **)0x1c000c588;
  }
  else {
    if (local_48 == 2) {
      uVar1 = *(uint *)(pcVar2 + 0x18);
      if (uVar1 < 0x3ec0c5) {
        if (uVar1 == 0x3ec0c4) {
          ppCStack_b0 = local_38;
          local_a8 = &local_98;
          local_b8 = pVVar6;
          local_98 = (_IRP *)&local_98;
          uVar7 = HandleIoctl<_VMBUS_COMPLETE_OPEN_INPUT_PARAMETERS,NoType,<lambda_266c19f7299a8c70ad99e567673af273>_>
                            ((ulonglong *)&local_88,(longlong *)&local_b8);
          goto LAB_1c00068a4;
        }
        if (uVar1 == 0x3ec008) {
          ppCStack_b0 = local_38;
          local_a8 = &local_res8;
          if ((_IRP *)0x3 < local_98) {
            local_res10 = (VirtualMachineFile *)((ulonglong)local_res10 & 0xffffffff00000000);
            local_b8 = pVVar6;
            local_98 = (_IRP *)&local_98;
            uVar7 = <lambda_5cd53e81c4e19984027c507a00544d2d>::
                    operator()<NoType,_VMBUS_WAIT_FOR_ACTION_OUTPUT_PARAMETERS_*>
                              ((longlong *)&local_b8,p_Var9,(undefined4 *)&local_res10);
            if ((uVar7 & 0xc0000000) != 0xc0000000) {
              if (CONCAT44(uStack_74,local_78) < 4) {
LAB_1c00068be:
                    /* WARNING: Subroutine does not return */
                gsl::details::terminate();
              }
              *(undefined4 *)CONCAT44(uStack_6c,uStack_70) = local_res10._0_4_;
              *(undefined8 *)local_68 = 4;
            }
            goto LAB_1c00068a4;
          }
          uVar7 = 0xc0000023;
          local_a8 = (_IRP **)0x1c1;
          goto LAB_1c0006526;
        }
        if (uVar1 == 0x3ec013) {
          local_98 = (_IRP *)&local_98;
          SignalVmm(local_38[0]);
          goto LAB_1c00068a4;
        }
        if (uVar1 == 0x3ec01c) {
          ppCStack_b0 = local_38;
          local_a8 = &local_res8;
          local_a0 = &local_98;
          local_b8 = pVVar6;
          local_98 = (_IRP *)&local_98;
          uVar7 = HandleIoctl<_VMBUS_OFFER_CHANNEL_INPUT_PARAMETERS,NoType,<lambda_a534ac22b97e81815e4ec8c29d7e7ce5>_>
                            ((ulonglong *)&local_88,(longlong *)&local_b8);
          goto LAB_1c00068a4;
        }
        if (uVar1 == 0x3ec040) {
          local_98 = (_IRP *)&local_98;
          KeEnterCriticalRegion();
          this = pVVar6;
          ExAcquirePushLockExclusiveEx(pVVar6,0);
          uVar7 = VirtualMachine::DeviceCloseChannel
                            ((VirtualMachine *)this,local_38[0],(CompletedIrps *)&local_98);
          if (pVVar6 != (VirtualMachineFile *)0x0) {
            ExReleasePushLockExclusiveEx(pVVar6,0);
            KeLeaveCriticalRegion();
          }
          goto LAB_1c00068a4;
        }
        if (uVar1 == 0x3ec0c0) {
          ppCStack_b0 = local_38;
          local_a8 = &local_res8;
          local_b8 = pVVar6;
          local_98 = (_IRP *)&local_98;
          uVar7 = HandleIoctl<NoType,_VMBUS_QUERY_SERVER_OPEN_CHANNEL_OUTPUT_PARAMETERS,<lambda_d37032be05a81cbc0febac5b1628d321>_>
                            ((longlong)&local_88,(longlong *)&local_b8);
          goto LAB_1c00068a4;
        }
      }
      else {
        if (uVar1 == 0x3ec0c8) {
          ppCStack_b0 = local_38;
          local_a8 = &local_res8;
          local_b8 = pVVar6;
          local_98 = (_IRP *)&local_98;
          uVar7 = HandleIoctl<_VMBUS_MAP_GPADL_VIEW_INPUT_PARAMS,_VMBUS_MAP_GPADL_VIEW_OUTPUT_PARAMS,<lambda_0fa6f7ba3f2f0cb0949b870cfcf3bb61>_>
                            ((ulonglong *)&local_88,&local_b8);
          goto LAB_1c00068a4;
        }
        if (uVar1 == 0x3ec0cc) {
          local_58 = local_38;
          local_98 = (_IRP *)&local_98;
          local_60 = pVVar6;
          uVar7 = HandleIoctl<_VMBUS_UNMAP_GPADL_VIEW_INPUT_PARAMS,NoType,<lambda_5eb3ed8726deee6e74edad3136cfa3d7>_>
                            ((ulonglong *)&local_88,(longlong)&local_60);
          goto LAB_1c00068a4;
        }
        if (uVar1 == 0x3ec0d4) {
          ppCStack_b0 = local_38;
          local_a8 = &local_98;
          local_b8 = pVVar6;
          local_98 = (_IRP *)&local_98;
          uVar8 = HandleIoctl<_VMBUS_SET_INTERRUPT_PREFERRED_PROCESSOR_INPUT_PARAMETERS,NoType,<lambda_a997a0f262bd63ad5f730d7aa05bd13c>_>
                            ((ulonglong *)&local_88,(longlong *)&local_b8);
          uVar7 = (uint)uVar8;
          goto LAB_1c00068a4;
        }
        if (uVar1 == 0x3ec0d8) {
          local_res10 = pVVar6;
          local_98 = (_IRP *)&local_98;
          uVar8 = HandleIoctl<NoType,_VMBUS_GET_NUMA_NODE_MAP_OUTPUT_PARAMETERS,unsigned_int,8,<lambda_e079101f3cc2ee249c4adfbda6baa925>_>
                            ((longlong)&local_88,(longlong *)&local_res10);
          uVar7 = (uint)uVar8;
          goto LAB_1c00068a4;
        }
        if (uVar1 == 0x3ec0dc) {
          local_res10 = pVVar6;
          local_98 = (_IRP *)&local_98;
          uVar8 = HandleIoctl<NoType,_VMBUS_GET_VM_NAME_OUTPUT_PARAMETERS,unsigned_short,20,<lambda_4501a69042029aa06c84f308c71f00ba>_>
                            ((longlong)&local_88,(longlong *)&local_res10);
          uVar7 = (uint)uVar8;
          goto LAB_1c00068a4;
        }
      }
    }
    else if (local_48 == 3) {
      if (*(int *)(pcVar2 + 0x18) == 0x3ec0d3) {
        uVar7 = 0xc0000002;
        ppCStack_b0 = (Channel **)0x1c000c3e8;
        local_a8 = (_IRP **)0x301;
        goto LAB_1c0006538;
      }
      if (*(int *)(pcVar2 + 0x18) == 0x3ec0e3) {
        local_98 = (_IRP *)&local_98;
        uVar7 = DeviceIoctlRdmaCopyChildPages(pVVar6,param_1);
        goto LAB_1c00068a4;
      }
    }
LAB_1c00067da:
    uVar7 = 0xc0000010;
    ppCStack_b0 = (Channel **)0x1c000c3e8;
    local_a8 = (_IRP **)0x30b;
  }
LAB_1c0006538:
  local_a0 = (_IRP **)0x0;
  local_b8 = (VirtualMachineFile *)0x1c000c2b0;
  local_98 = (_IRP *)&local_98;
  OnFailure((ErrorSite *)&local_b8,uVar7);
LAB_1c00068a4:
  CompletedIrps::~CompletedIrps((CompletedIrps *)&local_98);
  return uVar7;
}



===== HandleIrpPnp @ 1c00068cc =====

/* long __cdecl HandleIrpPnp(struct _IRP * __ptr64) */

long __cdecl HandleIrpPnp(_IRP *param_1)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  ulonglong *puVar12;
  ulonglong *puVar13;
  ulonglong *puVar14;
  longlong lVar15;
  ulonglong *puVar16;
  int iVar17;
  ulonglong uVar18;
  char *local_168;
  char *local_160;
  undefined8 local_158;
  undefined8 local_150;
  ulonglong local_148 [2];
  code *local_138;
  code *pcStack_130;
  code *local_128;
  code *pcStack_120;
  code *local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  code *pcStack_e0;
  code *local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  code *pcStack_c0;
  code *local_b8;
  code *pcStack_b0;
  code *local_a8;
  code *pcStack_a0;
  code *local_98;
  code *pcStack_90;
  code *local_88;
  code *local_80;
  code *local_78;
  code *local_70;
  code *local_68;
  code *local_60;
  code *local_58;
  code *local_50;
  code *local_48;
  code *local_40;
  code *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  lVar1 = *(longlong *)(param_1 + 0xb8);
  if (((*(char *)(lVar1 + 1) == '\b') && (**(longlong **)(lVar1 + 8) == 0x46317cc573518b7b)) &&
     ((*(longlong **)(lVar1 + 8))[1] == -0x27197cec4c077b68)) {
    if (((*(short *)(lVar1 + 0x12) != 0xd) || (*(short *)(lVar1 + 0x10) != 0x140)) ||
       (lVar2 = *(longlong *)(lVar1 + 0x20), lVar2 == 0)) {
      local_158 = 0x559;
      local_168 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
      local_150 = 0;
      local_160 = "HandleIrpPnp";
      OnFailure((ErrorSite *)&local_168,-0x3ffffff3);
      return -0x3ffffff3;
    }
    uVar18 = *(ulonglong *)(lVar2 + 0x20);
    lVar15 = 2;
    if (uVar18 < 4) {
      iVar17 = (int)uVar18;
      uVar18 = 0;
    }
    else {
      iVar17 = 2;
    }
    local_168 = (char *)(ulonglong)(uint)local_168;
    if (iVar17 == 2) {
      puVar3 = *(ulonglong **)(lVar1 + 0x18);
      local_138 = VmbusInterfaceReference;
      local_148[1] = 0;
      pcStack_130 = VmbusInterfaceDereference;
      local_128 = ChCloseChannel;
      pcStack_120 = ChOpenChannel;
      local_118 = ChOpenResult;
      pcStack_e0 = ChMapGpadlView;
      local_d8 = ChUnmapGpadlView;
      pcStack_c0 = ChRegisterIsr;
      local_b8 = ChUnregisterIsr;
      pcStack_b0 = ChSendInterrupt;
      local_a8 = ChCancelInterrupt;
      pcStack_a0 = ChQueueWorkItem;
      local_98 = ChDequeueWorkItem;
      pcStack_90 = ChCreateWorkItem;
      local_88 = ChDestroyWorkItem;
      local_80 = ChSetInterruptPreferredProcessor;
      local_78 = ChGetNumaNodeMap;
      local_70 = ChGetVmName;
      local_68 = ChGetLockChildPagesParams;
      local_60 = ChLockChildPages;
      local_58 = ChUnlockChildPages;
      local_50 = ChMapChildMmioSpace;
      local_48 = ChUnmapChildMmioSpace;
      local_40 = ChMapChildVaSpace;
      local_38 = ChGetVaBackingProcess;
      uStack_110 = 0;
      local_108 = 0;
      uStack_100 = 0;
      local_f8 = 0;
      uStack_f0 = 0;
      local_e8 = 0;
      uStack_d0 = 0;
      local_c8 = 0;
      local_30 = 0;
      local_28 = 0;
      local_20 = 0;
      local_18 = 0;
      local_10 = 0;
      local_148[0] = 0xd0140;
      puVar12 = puVar3;
      puVar13 = local_148;
      do {
        puVar16 = puVar13;
        puVar14 = puVar12;
        uVar8 = puVar16[1];
        uVar10 = puVar16[2];
        uVar11 = puVar16[3];
        *puVar14 = *puVar16;
        puVar14[1] = uVar8;
        uVar8 = puVar16[4];
        uVar9 = puVar16[5];
        puVar14[2] = uVar10;
        puVar14[3] = uVar11;
        uVar10 = puVar16[6];
        uVar11 = puVar16[7];
        puVar14[4] = uVar8;
        puVar14[5] = uVar9;
        uVar8 = puVar16[8];
        uVar9 = puVar16[9];
        puVar14[6] = uVar10;
        puVar14[7] = uVar11;
        uVar10 = puVar16[10];
        uVar11 = puVar16[0xb];
        puVar14[8] = uVar8;
        puVar14[9] = uVar9;
        uVar8 = puVar16[0xc];
        uVar9 = puVar16[0xd];
        puVar14[10] = uVar10;
        puVar14[0xb] = uVar11;
        uVar10 = puVar16[0xe];
        uVar11 = puVar16[0xf];
        puVar14[0xc] = uVar8;
        puVar14[0xd] = uVar9;
        puVar14[0xe] = uVar10;
        puVar14[0xf] = uVar11;
        lVar15 = lVar15 + -1;
        puVar12 = puVar14 + 0x10;
        puVar13 = puVar16 + 0x10;
      } while (lVar15 != 0);
      uVar8 = puVar16[0x11];
      uVar10 = puVar16[0x12];
      uVar11 = puVar16[0x13];
      puVar14[0x10] = puVar16[0x10];
      puVar14[0x11] = uVar8;
      uVar8 = puVar16[0x14];
      uVar4 = *(undefined4 *)((longlong)puVar16 + 0xa4);
      uVar9 = puVar16[0x15];
      uVar5 = *(undefined4 *)((longlong)puVar16 + 0xac);
      puVar14[0x12] = uVar10;
      puVar14[0x13] = uVar11;
      uVar10 = puVar16[0x16];
      uVar6 = *(undefined4 *)((longlong)puVar16 + 0xb4);
      uVar11 = puVar16[0x17];
      uVar7 = *(undefined4 *)((longlong)puVar16 + 0xbc);
      *(int *)(puVar14 + 0x14) = (int)uVar8;
      *(undefined4 *)((longlong)puVar14 + 0xa4) = uVar4;
      *(int *)(puVar14 + 0x15) = (int)uVar9;
      *(undefined4 *)((longlong)puVar14 + 0xac) = uVar5;
      *(int *)(puVar14 + 0x16) = (int)uVar10;
      *(undefined4 *)((longlong)puVar14 + 0xb4) = uVar6;
      *(int *)(puVar14 + 0x17) = (int)uVar11;
      *(undefined4 *)((longlong)puVar14 + 0xbc) = uVar7;
      puVar3[1] = uVar18;
      ObfReferenceObject(lVar2);
      return 0;
    }
    local_158 = 0x560;
    local_168 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
    local_150 = 0;
    local_160 = "HandleIrpPnp";
    OnFailure((ErrorSite *)&local_168,-0x3ffffff0);
  }
  return -0x3ffffff0;
}



===== LockChildPages @ 1c0006bf0 =====

long LockChildPages(VirtualMachineFile *param_1,uint param_2,ulonglong *param_3,ulonglong *param_4)

{
  char *pcVar1;
  byte bVar2;
  long lVar3;
  char *pcVar4;
  char *local_48;
  char *pcStack_40;
  undefined8 local_38;
  undefined8 local_30;
  
  bVar2 = KeGetCurrentIrql();
  if (bVar2 < 2) {
    pcVar1 = (char *)*param_3;
    pcVar4 = (char *)0x0;
    if (pcVar1 != (char *)0x0) {
      do {
        if (((char *)*param_4 <= pcVar4) || (pcVar1 <= pcVar4)) {
LAB_1c0006cff:
                    /* WARNING: Subroutine does not return */
          gsl::details::terminate();
        }
        lVar3 = LockGuestMemory(param_1,*(_GPA_RANGE **)(param_3[1] + (longlong)pcVar4 * 8),
                                *(_MDL **)(param_4[1] + (longlong)pcVar4 * 8),param_2);
        if (lVar3 < 0) {
          local_30 = 0;
          local_48 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
          local_38 = 0x8f;
          pcStack_40 = "LockChildPages";
          OnFailure((ErrorSite *)&local_48,lVar3);
          if (pcVar4 <= (char *)*param_4) {
            pcStack_40 = (char *)param_4[1];
            local_48 = pcVar4;
            UnlockChildPages((longlong *)&local_48);
            return lVar3;
          }
          goto LAB_1c0006cff;
        }
        pcVar4 = (char *)(ulonglong)((int)pcVar4 + 1);
      } while (pcVar4 < pcVar1);
    }
    lVar3 = 0;
  }
  else {
    lVar3 = -0x3fffff28;
  }
  return lVar3;
}



===== LockGuestMemory @ 1c0006d0c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl LockGuestMemory(struct VirtualMachineFile & __ptr64,struct _GPA_RANGE *
   __ptr64,struct _MDL * __ptr64,unsigned int) */

long __cdecl
LockGuestMemory(VirtualMachineFile *param_1,_GPA_RANGE *param_2,_MDL *param_3,uint param_4)

{
  _MDL *p_Var1;
  longlong lVar2;
  ulonglong uVar3;
  _MDL *p_Var4;
  ulonglong uVar5;
  uint uVar6;
  undefined1 auStack_e8 [32];
  _EX_PUSH_LOCK local_c8 [8];
  char *local_c0;
  char *local_b8;
  undefined8 local_b0;
  char *local_a8;
  undefined8 *local_a0 [5];
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_e8;
  util::AcquireSharedLock(local_c8);
  uVar6 = (uint)(*(int *)(param_2 + 4) + 0xfff + *(int *)param_2) >> 0xc;
  p_Var1 = param_3 + 0x30;
  lVar2 = *(longlong *)(param_1 + 0x68);
  uVar3 = *(ulonglong *)(param_1 + 0x70);
  uVar5 = 0;
  if (uVar6 != 0) {
    p_Var4 = p_Var1;
    do {
      if (uVar3 >> 0xc <= *(ulonglong *)(p_Var4 + (longlong)(param_2 + (8 - (longlong)p_Var1)))) {
        local_c0 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
        local_b8 = "LockGuestMemory";
        local_b0 = 0x51;
        local_a8 = "%#llx %#zx";
        OnFailure((ErrorSite *)&local_c0,-0x3ffffffb);
        wil::
        unique_any_t<wil::details::unique_storage<wil::details::resource_policy<_EX_PUSH_LOCK*___ptr64,void_(__cdecl*)(_EX_PUSH_LOCK*___ptr64),&void___cdecl_util::ReleaseSharedLock(struct__EX_PUSH_LOCK*___ptr64),wistd::integral_constant<unsigned___int64,2>,_EX_PUSH_LOCK*___ptr64,_EX_PUSH_LOCK*___ptr64,0,std::nullptr_t>_>_>
        ::
        ~unique_any_t<wil::details::unique_storage<wil::details::resource_policy<_EX_PUSH_LOCK*___ptr64,void_(__cdecl*)(_EX_PUSH_LOCK*___ptr64),&void___cdecl_util::ReleaseSharedLock(struct__EX_PUSH_LOCK*___ptr64),wistd::integral_constant<unsigned___int64,2>,_EX_PUSH_LOCK*___ptr64,_EX_PUSH_LOCK*___ptr64,0,std::nullptr_t>_>_>
                  ((unique_any_t<wil::details::unique_storage<wil::details::resource_policy<_EX_PUSH_LOCK*___ptr64,void_(__cdecl*)(_EX_PUSH_LOCK*___ptr64),&void___cdecl_util::ReleaseSharedLock(struct__EX_PUSH_LOCK*___ptr64),wistd::integral_constant<unsigned___int64,2>,_EX_PUSH_LOCK*___ptr64,_EX_PUSH_LOCK*___ptr64,0,std::nullptr_t>_>_>
                    *)local_c8);
        return -0x3ffffffb;
      }
      *(ulonglong *)p_Var4 =
           *(ulonglong *)(p_Var4 + (longlong)(param_2 + (8 - (longlong)p_Var1))) * 0x1000 + lVar2;
      uVar5 = uVar5 + 1;
      p_Var4 = p_Var4 + 8;
    } while (uVar5 < uVar6);
  }
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  KeStackAttachProcess(*(undefined8 *)(param_1 + 0x60),&local_78);
  local_a0[0] = &local_78;
  wil::scope_exit<<lambda_33518dc734835b711a9e7f6f385320da>_>(&local_c0,local_a0);
  *(undefined8 *)param_3 = 0;
  *(short *)(param_3 + 8) = ((short)((ulonglong)(uVar6 << 0xc) + 0xfff >> 0xc) + 6) * 8;
  *(undefined2 *)(param_3 + 10) = 0;
  *(undefined8 *)(param_3 + 0x20) = 0;
  *(undefined4 *)(param_3 + 0x2c) = 0;
  *(uint *)(param_3 + 0x28) = uVar6 << 0xc;
  MmProbeAndLockSelectedPages(param_3,p_Var1,1,(~param_4 & 1) * 2);
  *(undefined4 *)(param_3 + 0x2c) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_3 + 0x28) = *(undefined4 *)param_2;
  if ((char)local_b8 != '\0') {
    KeUnstackDetachProcess(local_c0);
  }
  wil::
  unique_any_t<wil::details::unique_storage<wil::details::resource_policy<_EX_PUSH_LOCK*___ptr64,void_(__cdecl*)(_EX_PUSH_LOCK*___ptr64),&void___cdecl_util::ReleaseSharedLock(struct__EX_PUSH_LOCK*___ptr64),wistd::integral_constant<unsigned___int64,2>,_EX_PUSH_LOCK*___ptr64,_EX_PUSH_LOCK*___ptr64,0,std::nullptr_t>_>_>
  ::
  ~unique_any_t<wil::details::unique_storage<wil::details::resource_policy<_EX_PUSH_LOCK*___ptr64,void_(__cdecl*)(_EX_PUSH_LOCK*___ptr64),&void___cdecl_util::ReleaseSharedLock(struct__EX_PUSH_LOCK*___ptr64),wistd::integral_constant<unsigned___int64,2>,_EX_PUSH_LOCK*___ptr64,_EX_PUSH_LOCK*___ptr64,0,std::nullptr_t>_>_>
            ((unique_any_t<wil::details::unique_storage<wil::details::resource_policy<_EX_PUSH_LOCK*___ptr64,void_(__cdecl*)(_EX_PUSH_LOCK*___ptr64),&void___cdecl_util::ReleaseSharedLock(struct__EX_PUSH_LOCK*___ptr64),wistd::integral_constant<unsigned___int64,2>,_EX_PUSH_LOCK*___ptr64,_EX_PUSH_LOCK*___ptr64,0,std::nullptr_t>_>_>
              *)local_c8);
  return 0;
}



===== MapLockedGpadl @ 1c0006f48 =====

/* long __cdecl MapLockedGpadl(struct VirtualMachineFile & __ptr64,class LockedGpadl &
   __ptr64,unsigned int) */

long __cdecl MapLockedGpadl(VirtualMachineFile *param_1,LockedGpadl *param_2,uint param_3)

{
  longlong *plVar1;
  _GPA_RANGE *p_Var2;
  undefined1 auVar3 [16];
  long lVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  __uint64 _Var7;
  ulonglong *puVar8;
  longlong lVar9;
  _MDL *p_Var10;
  ulonglong uVar11;
  longlong lVar12;
  uint uVar13;
  unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>
  *this;
  unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>
  *puVar14;
  unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>
  *local_res10;
  uint local_res18;
  char *local_58;
  char *local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_res18 = param_3;
  if (*(longlong *)(*(longlong *)(param_2 + 8) + 0x38) == 0) {
    puVar5 = operator_new(0x38);
    if (puVar5 != (undefined8 *)0x0) {
      *puVar5 = 0;
      puVar5[1] = 0;
      puVar5[2] = 0;
      puVar5[3] = 0;
      puVar5[4] = 0;
      puVar5[5] = 0;
      puVar5[6] = 0;
      uVar11 = CONCAT44(0,*(uint *)(*(longlong *)(param_2 + 8) + 0x14));
      auVar3._8_8_ = 0;
      auVar3._0_8_ = uVar11;
      uVar6 = SUB168(ZEXT816(8) * auVar3,0);
      if (SUB168(ZEXT816(8) * auVar3,8) != 0) {
        uVar6 = 0xffffffffffffffff;
      }
      _Var7 = uVar6 + 8;
      if (0xfffffffffffffff7 < uVar6) {
        _Var7 = 0xffffffffffffffff;
      }
      puVar8 = operator_new(_Var7);
      if (puVar8 == (ulonglong *)0x0) {
        local_res10 = (unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>
                       *)0x0;
      }
      else {
        *puVar8 = uVar11;
        puVar14 = (unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>
                   *)(puVar8 + 1);
        this = puVar14;
        for (; uVar11 != 0; uVar11 = uVar11 - 1) {
          wistd::
          unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>
          ::
          unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_><1,void>
                    (this);
          this = this + 8;
        }
        local_res10 = puVar14;
        if (puVar14 !=
            (unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>
             *)0x0) {
          lVar9 = *(longlong *)(param_2 + 8);
          uVar13 = 0;
          if (*(int *)(lVar9 + 0x14) != 0) {
            do {
              uVar11 = (ulonglong)uVar13;
              p_Var2 = *(_GPA_RANGE **)(*(longlong *)(lVar9 + 0x20) + uVar11 * 8);
              p_Var10 = (_MDL *)IoAllocateMdl(*(undefined4 *)(p_Var2 + 4),*(undefined4 *)p_Var2,0,0,
                                              0);
              if (p_Var10 == (_MDL *)0x0) {
                local_40 = 0;
                local_58 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
                local_48 = 0xb0;
                local_50 = "MapLockedGpadl";
                OnFailure((ErrorSite *)&local_58,-0x3fffff66);
                wistd::
                unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
                ::
                ~unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
                          ((unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
                            *)&local_res10);
                MdlMapping::~MdlMapping((MdlMapping *)(puVar5 + 4));
                lVar9 = puVar5[3];
                puVar5[3] = 0;
                if (lVar9 != 0) {
                  IoFreeMdl();
                }
                lVar4 = -0x3fffff66;
LAB_1c0007249:
                wistd::
                unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
                ::
                ~unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
                          ((unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
                            *)(puVar5 + 2));
                ExFreePoolWithTag(puVar5,0);
                return lVar4;
              }
              lVar4 = LockGuestMemory(param_1,p_Var2,p_Var10,local_res18);
              if (lVar4 < 0) {
                local_40 = 0;
                local_58 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
                local_48 = 0xb3;
                local_50 = "MapLockedGpadl";
                OnFailure((ErrorSite *)&local_58,lVar4);
                IoFreeMdl(p_Var10);
                wistd::
                unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
                ::
                ~unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
                          ((unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
                            *)&local_res10);
                MdlMapping::~MdlMapping((MdlMapping *)(puVar5 + 4));
                lVar9 = puVar5[3];
                puVar5[3] = 0;
                if (lVar9 != 0) {
                  IoFreeMdl();
                }
                goto LAB_1c0007249;
              }
              lVar9 = *(longlong *)(puVar14 + uVar11 * 8);
              *(_MDL **)(puVar14 + uVar11 * 8) = p_Var10;
              if (lVar9 != 0) {
                MmUnlockPages(lVar9);
                IoFreeMdl(lVar9);
              }
              if (uVar13 != 0) {
                **(undefined8 **)(puVar14 + (ulonglong)(uVar13 - 1) * 8) =
                     *(undefined8 *)(puVar14 + uVar11 * 8);
              }
              lVar9 = *(longlong *)(param_2 + 8);
              uVar13 = uVar13 + 1;
            } while (uVar13 < *(uint *)(lVar9 + 0x14));
          }
          lVar9 = puVar5[2];
          local_res10 = (unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>
                         *)0x0;
          puVar5[2] = puVar14;
          if (lVar9 != 0) {
            plVar1 = (longlong *)(lVar9 + -8);
            lVar12 = *plVar1;
            puVar14 = (unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>
                       *)(lVar9 + lVar12 * 8);
            for (; lVar12 != 0; lVar12 = lVar12 + -1) {
              puVar14 = puVar14 + -8;
              wistd::
              unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>
              ::
              ~unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>
                        (puVar14);
            }
            if (plVar1 != (longlong *)0x0) {
              ExFreePoolWithTag(plVar1,0);
            }
          }
          lVar9 = *(longlong *)(*(longlong *)(param_2 + 8) + 0x38);
          *(undefined8 **)(*(longlong *)(param_2 + 8) + 0x38) = puVar5;
          if (lVar9 != 0) {
            MdlMapping::~MdlMapping((MdlMapping *)(lVar9 + 0x20));
            lVar12 = *(longlong *)(lVar9 + 0x18);
            *(undefined8 *)(lVar9 + 0x18) = 0;
            if (lVar12 != 0) {
              IoFreeMdl();
            }
            wistd::
            unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
            ::
            ~unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
                      ((unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
                        *)(lVar9 + 0x10));
            ExFreePoolWithTag(lVar9,0);
          }
          wistd::
          unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
          ::
          ~unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
                    ((unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
                      *)&local_res10);
          return 0;
        }
      }
      local_48 = 0xa7;
      local_58 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
      local_40 = 0;
      local_50 = "MapLockedGpadl";
      OnFailure((ErrorSite *)&local_58,-0x3fffff66);
      wistd::
      unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
      ::
      ~unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
                ((unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
                  *)&local_res10);
      MdlMapping::~MdlMapping((MdlMapping *)(puVar5 + 4));
      lVar9 = puVar5[3];
      puVar5[3] = 0;
      if (lVar9 != 0) {
        IoFreeMdl();
      }
      wistd::
      unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
      ::
      ~unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
                ((unique_ptr<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0],wistd::default_delete<class_wistd::unique_ptr<_MDL,wil::function_deleter<void_(__cdecl*)(_MDL*___ptr64),&void___cdecl_UnlockAndFreeMdl(struct__MDL*___ptr64)>_>_[0]>_>
                  *)(puVar5 + 2));
      ExFreePoolWithTag(puVar5,0);
      return -0x3fffff66;
    }
    local_48 = 0xa1;
    lVar4 = -0x3fffff66;
  }
  else {
    local_48 = 0x9b;
    lVar4 = -0x3ffff8f8;
  }
  local_40 = 0;
  local_58 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
  local_50 = "MapLockedGpadl";
  OnFailure((ErrorSite *)&local_58,lVar4);
  return lVar4;
}



===== SignalVmm @ 1c000733c =====

/* bool __cdecl SignalVmm(struct Channel & __ptr64) */

bool __cdecl SignalVmm(Channel *param_1)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  
  cVar1 = ExAcquireRundownProtection(param_1 + 0x210);
  if (cVar1 == '\0') {
    bVar3 = false;
  }
  else {
    iVar2 = KeSetEvent(*(undefined8 *)(param_1 + 0x218),0,0);
    ExReleaseRundownProtection(param_1 + 0x210);
    bVar3 = iVar2 == 0;
  }
  return bVar3;
}



===== UnlockChildPages @ 1c00073a8 =====

void UnlockChildPages(longlong *param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)param_1[1];
  puVar1 = puVar2 + *param_1;
  for (; puVar2 != puVar1; puVar2 = puVar2 + 1) {
    MmUnlockPages(*puVar2);
  }
  return;
}



===== VmbusInterfaceDereference @ 1c00073f0 =====

/* void __cdecl VmbusInterfaceDereference(void * __ptr64) */

void __cdecl VmbusInterfaceDereference(void *param_1)

{
  ObfDereferenceObject(*(undefined8 *)((longlong)param_1 + 0x18));
  return;
}



===== VmbusInterfaceReference @ 1c0007410 =====

/* void __cdecl VmbusInterfaceReference(void * __ptr64) */

void __cdecl VmbusInterfaceReference(void *param_1)

{
  ObfReferenceObject(*(undefined8 *)((longlong)param_1 + 0x18));
  return;
}



===== DriverEntry @ 1c0007430 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1,undefined8 param_2)

{
  undefined2 uVar1;
  code *pcVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 auStack_a8 [8];
  undefined1 auStack_a0 [48];
  undefined4 *local_70;
  _DEVICE_OBJECT **local_68;
  _DEVICE_OBJECT *local_58;
  undefined8 local_50;
  wchar_t *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  char *local_30;
  char *pcStack_28;
  undefined8 local_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_a8;
  local_58 = (_DEVICE_OBJECT *)0x0;
  local_48 = L"\\Device\\vmbusproxy";
  local_68 = &local_58;
  local_50 = 0x260024;
  local_70 = &local_40;
  local_40 = 0xd694af51;
  local_3c = 0x45b8bc60;
  local_38 = 0xf1b2a08d;
  local_34 = 0xa86e1769;
  iVar3 = WdmlibIoCreateDeviceSecure(param_1,param_2,&local_50);
  puVar4 = auStack_a8;
  if (iVar3 < 0) {
    local_18 = 0;
    local_30 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\proxydriver.cpp";
    local_20 = 0x5a5;
    pcStack_28 = "DriverEntry";
    OnFailure((ErrorSite *)&local_30,iVar3);
    puVar4 = auStack_a8;
  }
  else {
    *(code **)(param_1 + 0x68) = DriverUnload;
    *(code **)(param_1 + 0x70) = HandleIrp<&long___cdecl_HandleIrpCreate(struct__IRP*___ptr64)>;
    *(code **)(param_1 + 0x100) = HandleIrp<&long___cdecl_HandleIrpCleanup(struct__IRP*___ptr64)>;
    *(code **)(param_1 + 0x80) = HandleIrp<&long___cdecl_HandleIrpClose(struct__IRP*___ptr64)>;
    *(code **)(param_1 + 0xe0) = HandleIrp<&long___cdecl_HandleIrpIoctl(struct__IRP*___ptr64)>;
    *(code **)(param_1 + 0x148) = HandleIrp<&long___cdecl_HandleIrpPnp(struct__IRP*___ptr64)>;
    local_30 = *(char **)(PTR_DAT_1c000e010 + -0x10);
    pcStack_28 = *(char **)(PTR_DAT_1c000e010 + -8);
    if (DAT_1c000e028 != 0) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(5);
      puVar4 = auStack_a0;
    }
    _DAT_1c000e030 = 0;
    uRam00000001c000e038 = 0;
    *(undefined8 *)(puVar4 + -8) = 0x1c000757a;
    iVar3 = EtwRegister(&local_30,_tlgEnableCallback,&DAT_1c000e008,&DAT_1c000e028);
    if (iVar3 == 0) {
      uVar1 = *(undefined2 *)PTR_DAT_1c000e010;
      *(undefined8 *)(puVar4 + -8) = 0x1c000759f;
      EtwSetInformation(DAT_1c000e028,2,PTR_DAT_1c000e010,uVar1);
    }
    *(uint *)(local_58 + 0x30) = *(uint *)(local_58 + 0x30) & 0xffffff7f;
    g_controlDevice = local_58;
    iVar3 = 0;
  }
  *(undefined8 *)(puVar4 + -8) = 0x1c00075c6;
  return iVar3;
}



===== _tlgDefineProvider_annotation__Tlgg_VmbusCommonTraceProviderProv @ 1c00075e4 =====

void _tlgDefineProvider_annotation__Tlgg_VmbusCommonTraceProviderProv(void)

{
  return;
}



===== ~CancellableIrp @ 1c00075f0 =====

/* public: __cdecl CancellableIrp::~CancellableIrp(void) __ptr64 */

void __thiscall CancellableIrp::~CancellableIrp(CancellableIrp *this)

{
  code *pcVar1;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  if (*(longlong *)this != 0) {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\util.cpp";
    local_18 = 0x49;
    local_20 = "CancellableIrp::~CancellableIrp";
    OnFailure((ErrorSite *)&local_28,-0x3fffffff);
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(5);
  }
  return;
}



===== ~CompletedIrps @ 1c0007644 =====

/* public: __cdecl CompletedIrps::~CompletedIrps(void) __ptr64 */

void __thiscall CompletedIrps::~CompletedIrps(CompletedIrps *this)

{
  CompletedIrps *pCVar1;
  CompletedIrps *pCVar2;
  
  pCVar2 = *(CompletedIrps **)this;
  while (pCVar2 != this) {
    pCVar1 = pCVar2 + -0xa8;
    pCVar2 = *(CompletedIrps **)pCVar2;
    IofCompleteRequest(pCVar1,0);
  }
  *(CompletedIrps **)(this + 8) = this;
  *(CompletedIrps **)this = this;
  return;
}



===== ~MdlMapping @ 1c0007690 =====

/* public: __cdecl MdlMapping::~MdlMapping(void) __ptr64 */

void __thiscall MdlMapping::~MdlMapping(MdlMapping *this)

{
  longlong lVar1;
  
  Unmap(this);
  lVar1 = *(longlong *)this;
  *(undefined8 *)this = 0;
  if (lVar1 != 0) {
    ObfDereferenceObject();
  }
  return;
}



===== operator_new @ 1c00076c4 =====

/* void * __ptr64 __cdecl operator new(unsigned __int64,unsigned __int64) */

void * __cdecl operator_new(__uint64 param_1,__uint64 param_2)

{
  void *pvVar1;
  
  pvVar1 = (void *)ExAllocatePool2(0x41,param_1,0x70626d76);
  return pvVar1;
}



===== operator_new @ 1c00076f0 =====

/* void * __ptr64 __cdecl operator new(unsigned __int64) */

void * __cdecl operator_new(__uint64 param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)ExAllocatePool2(0x40,param_1,0x70626d76);
  return pvVar1;
}



===== operator_delete @ 1c000771c =====

/* void __cdecl operator delete(void * __ptr64) */

void __cdecl operator_delete(void *param_1)

{
  if (param_1 != (void *)0x0) {
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== CancelRoutine @ 1c0007740 =====

/* private: static void __cdecl CancellableIrp::CancelRoutine(struct _DEVICE_OBJECT * __ptr64,struct
   _IRP * __ptr64) */

void __cdecl CancellableIrp::CancelRoutine(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  
  IoReleaseCancelSpinLock(2);
  do {
    plVar2 = *(longlong **)(param_2 + 0x78);
  } while (plVar2 == (longlong *)0x0);
  LOCK();
  lVar1 = *plVar2;
  *plVar2 = 0;
  UNLOCK();
  if (lVar1 == 0) {
    *(undefined8 *)(param_2 + 0x78) = 0;
    param_2 = (_IRP *)0x0;
  }
  KeLowerIrql(CONCAT71((int7)((ulonglong)plVar2 >> 8),param_2[0x45]));
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  IofCompleteRequest(param_2,0);
  return;
}



===== Map @ 1c00077a8 =====

/* public: long __cdecl MdlMapping::Map(struct _MDL * __ptr64,char,unsigned long,void * __ptr64 *
   __ptr64) __ptr64 */

long __thiscall
MdlMapping::Map(MdlMapping *this,_MDL *param_1,char param_2,ulong param_3,void **param_4)

{
  undefined8 uVar1;
  longlong lVar2;
  long lVar3;
  void *pvVar4;
  undefined8 *puVar5;
  longlong local_38;
  void *local_30;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  Unmap(this);
  pvVar4 = (void *)MmMapLockedPagesSpecifyCache(param_1,param_2,1,0,0,param_3);
  local_30 = pvVar4;
  if (pvVar4 == (void *)0x0) {
    local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\util.cpp";
    local_20 = "MdlMapping::Map";
    local_18 = 0xb3;
    local_10 = 0;
    OnFailure((ErrorSite *)&local_28,-0x3fffff66);
    lVar3 = -0x3fffff66;
  }
  else {
    PsGetCurrentProcess();
    puVar5 = (undefined8 *)ReferenceObObject<_EPROCESS>((_EPROCESS *)&local_38);
    uVar1 = *puVar5;
    *puVar5 = 0;
    lVar2 = *(longlong *)this;
    *(undefined8 *)this = uVar1;
    if (lVar2 != 0) {
      ObfDereferenceObject();
    }
    lVar2 = local_38;
    local_38 = 0;
    if (lVar2 != 0) {
      ObfDereferenceObject();
    }
    *(void **)(this + 0x10) = pvVar4;
    *(_MDL **)(this + 8) = param_1;
    *param_4 = pvVar4;
    lVar3 = 0;
  }
  return lVar3;
}



===== OnFailure @ 1c00078fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl OnFailure(struct ErrorSite const & __ptr64,long,...) */

void __cdecl OnFailure(ErrorSite *param_1,long param_2,...)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar5;
  longlong lVar4;
  undefined8 in_R8;
  undefined8 in_R9;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined1 auStackY_2d8 [32];
  long local_298 [2];
  undefined8 local_290;
  undefined8 local_288 [4];
  char *local_268;
  int local_260;
  undefined4 local_25c;
  undefined8 *local_258;
  undefined4 local_250;
  undefined4 local_24c;
  long *local_248;
  undefined4 local_240;
  undefined4 local_23c;
  char *local_238;
  int local_230;
  undefined4 local_22c;
  char local_228 [511];
  undefined1 local_29;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_2d8;
  local_228[0] = '\0';
  local_res18 = in_R8;
  local_res20 = in_R9;
  if (*(char **)(param_1 + 0x18) != (char *)0x0) {
    local_290 = 0;
    uVar2 = _vsnprintf(local_228,0x1ff,*(char **)(param_1 + 0x18),(va_list)&local_res18);
    if (((int)uVar2 < 0) || (0x1fe < uVar2)) {
      local_29 = 0;
    }
  }
  if (2 < DAT_1c000e008) {
    local_290 = CONCAT44(local_290._4_4_,*(undefined4 *)(param_1 + 0x10));
    lVar3 = -1;
    lVar5 = -1;
    do {
      lVar4 = lVar5 + 1;
      lVar1 = lVar5 + 1;
      lVar5 = lVar4;
    } while (local_228[lVar1] != '\0');
    local_22c = 0;
    local_238 = local_228;
    local_23c = 0;
    local_230 = (int)lVar4 + 1;
    local_24c = 0;
    local_248 = local_298;
    local_258 = &local_290;
    local_268 = *(char **)param_1;
    local_240 = 4;
    local_250 = 4;
    if (local_268 == (char *)0x0) {
      local_268 = "";
      local_260 = 1;
    }
    else {
      do {
        lVar3 = lVar3 + 1;
      } while (local_268[lVar3] != '\0');
      local_260 = (int)lVar3 + 1;
    }
    local_25c = 0;
    local_298[0] = param_2;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c000e008,&DAT_1c000cf31,0,0,6,local_288);
  }
  if (g_dbgPrintErrors != false) {
    if (local_228[0] == '\0') {
      DbgPrintEx(0,0,"(%s:%d): %#x\n",*(undefined8 *)param_1);
    }
    else {
      DbgPrintEx(0,0,"(%s:%d): %s: %#x\n");
    }
  }
  return;
}



===== Push @ 1c0007ab8 =====

/* public: void __cdecl CompletedIrps::Push(struct _IRP * __ptr64,long) __ptr64 */

void __thiscall CompletedIrps::Push(CompletedIrps *this,_IRP *param_1,long param_2)

{
  code *pcVar1;
  longlong *plVar2;
  _IRP *p_Var3;
  
  *(long *)(param_1 + 0x30) = param_2;
  p_Var3 = param_1 + 0xa8;
  plVar2 = *(longlong **)(this + 8);
  if ((CompletedIrps *)*plVar2 != this) {
    this = (CompletedIrps *)0x3;
    pcVar1 = (code *)swi(0x29);
    plVar2 = (longlong *)(*pcVar1)();
  }
  *(CompletedIrps **)p_Var3 = this;
  *(longlong **)(p_Var3 + 8) = plVar2;
  *plVar2 = (longlong)p_Var3;
  *(_IRP **)(this + 8) = p_Var3;
  return;
}



===== Set @ 1c0007aec =====

/* public: long __cdecl CancellableIrp::Set(struct _IRP * __ptr64) __ptr64 */

long __thiscall CancellableIrp::Set(CancellableIrp *this,_IRP *param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  long lVar4;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  if (*(longlong *)this == 0) {
    *(undefined8 *)(param_1 + 0x78) = 0;
    *(_IRP **)this = param_1;
    uVar2 = KfRaiseIrql(2);
    LOCK();
    uVar3 = *(undefined8 *)(param_1 + 0x68);
    *(code **)(param_1 + 0x68) = CancelRoutine;
    UNLOCK();
    if (param_1[0x44] != (_IRP)0x0) {
      LOCK();
      lVar1 = *(longlong *)(param_1 + 0x68);
      *(longlong *)(param_1 + 0x68) = 0;
      UNLOCK();
      uVar3 = 0;
      if (lVar1 != 0) {
        KeLowerIrql(CONCAT71((int7)((ulonglong)lVar1 >> 8),uVar2));
        local_18 = 0x67;
        lVar4 = -0x3ffffee0;
        goto LAB_1c0007b17;
      }
    }
    *(byte *)(*(longlong *)(param_1 + 0xb8) + 3) = *(byte *)(*(longlong *)(param_1 + 0xb8) + 3) | 1;
    *(CancellableIrp **)(param_1 + 0x78) = this;
    KeLowerIrql(CONCAT71((int7)((ulonglong)uVar3 >> 8),uVar2));
    lVar4 = 0;
  }
  else {
    local_18 = 0x5b;
    lVar4 = -0x3ffff8f8;
LAB_1c0007b17:
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\util.cpp";
    local_20 = "CancellableIrp::Set";
    OnFailure((ErrorSite *)&local_28,lVar4);
  }
  return lVar4;
}



===== Take @ 1c0007bc8 =====

/* public: struct _IRP * __ptr64 __cdecl CancellableIrp::Take(void) __ptr64 */

_IRP * __thiscall CancellableIrp::Take(CancellableIrp *this)

{
  _IRP *p_Var1;
  longlong lVar2;
  
  LOCK();
  p_Var1 = *(_IRP **)this;
  *(undefined8 *)this = 0;
  UNLOCK();
  if (p_Var1 != (_IRP *)0x0) {
    LOCK();
    lVar2 = *(longlong *)(p_Var1 + 0x68);
    *(longlong *)(p_Var1 + 0x68) = 0;
    UNLOCK();
    if (lVar2 == 0) {
      do {
      } while (*(longlong *)(p_Var1 + 0x78) != 0);
    }
  }
  return p_Var1;
}



===== Unmap @ 1c0007bf8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: void __cdecl MdlMapping::Unmap(void) __ptr64 */

void __thiscall MdlMapping::Unmap(MdlMapping *this)

{
  longlong lVar1;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  if (*(longlong *)this != 0) {
    local_48 = 0;
    uStack_40 = 0;
    local_38 = 0;
    uStack_30 = 0;
    local_28 = 0;
    uStack_20 = 0;
    KeStackAttachProcess(*(longlong *)this,&local_48);
    MmUnmapLockedPages(*(undefined8 *)(this + 0x10),*(undefined8 *)(this + 8));
    KeUnstackDetachProcess(&local_48);
    lVar1 = *(longlong *)this;
    *(undefined8 *)this = 0;
    if (lVar1 != 0) {
      ObfDereferenceObject();
    }
  }
  return;
}



===== make_unique<Channel> @ 1c0007c94 =====

/* class wistd::unique_ptr<struct Channel,struct wistd::default_delete<struct Channel> > __cdecl
   make_unique<struct Channel>(void) */

void __cdecl make_unique<Channel>(void)

{
  longlong lVar1;
  void *_Dst;
  undefined8 *in_RCX;
  
  _Dst = operator_new(0x220);
  if (_Dst == (void *)0x0) {
    _Dst = (void *)0x0;
  }
  else {
    memset(_Dst,0,0x220);
    KeInitializeSpinLock((longlong)_Dst + 0x28);
    *(undefined1 *)((longlong)_Dst + 0x40) = 0;
    lVar1 = (longlong)_Dst + 0x30;
    *(longlong *)((longlong)_Dst + 0x38) = lVar1;
    *(longlong *)lVar1 = lVar1;
    *(undefined8 *)((longlong)_Dst + 0x48) = 0;
    *(undefined8 *)((longlong)_Dst + 0x50) = 0;
    *(undefined8 *)((longlong)_Dst + 0x58) = 0;
    *(undefined8 *)((longlong)_Dst + 0x60) = 0;
    memset((void *)((longlong)_Dst + 0x68),0,0xb0);
    *(undefined8 *)((longlong)_Dst + 0x118) = 0;
    *(undefined4 *)((longlong)_Dst + 0x120) = 0;
    *(undefined8 *)((longlong)_Dst + 0x128) = 0;
    *(undefined8 *)((longlong)_Dst + 0x130) = 0;
    *(undefined8 *)((longlong)_Dst + 0x138) = 0;
    *(undefined8 *)((longlong)_Dst + 0x140) = 0;
    *(undefined8 *)((longlong)_Dst + 0x148) = 0;
    KeInitializeSpinLock((longlong)_Dst + 0x150);
    *(undefined8 *)((longlong)_Dst + 0x158) = 0;
    *(undefined8 *)((longlong)_Dst + 0x160) = 0;
    *(undefined1 *)((longlong)_Dst + 0x168) = 0;
    *(undefined8 *)((longlong)_Dst + 0x170) = 0;
    *(undefined8 *)((longlong)_Dst + 0x178) = 0;
    *(undefined8 *)((longlong)_Dst + 0x200) = 0;
    *(undefined4 *)((longlong)_Dst + 0x208) = 0;
    *(undefined8 *)((longlong)_Dst + 0x210) = 0;
    *(undefined8 *)((longlong)_Dst + 0x218) = 0;
  }
  *in_RCX = _Dst;
  return;
}



===== ~Channel @ 1c0007dbc =====

/* public: __cdecl Channel::~Channel(void) __ptr64 */

void __thiscall Channel::~Channel(Channel *this)

{
  longlong lVar1;
  WorkQueue *pWVar2;
  code *pcVar3;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  lVar1 = *(longlong *)(this + 0x218);
  *(undefined8 *)(this + 0x218) = 0;
  if (lVar1 != 0) {
    ObfDereferenceObject();
  }
  lVar1 = *(longlong *)(this + 0x178);
  *(undefined8 *)(this + 0x178) = 0;
  if (lVar1 != 0) {
    ExDeleteDpcEvent();
  }
  lVar1 = *(longlong *)(this + 0x148);
  *(undefined8 *)(this + 0x148) = 0;
  if (lVar1 != 0) {
    ObfDereferenceObject();
  }
  lVar1 = *(longlong *)(this + 0x140);
  *(undefined8 *)(this + 0x140) = 0;
  if (lVar1 != 0) {
    ObfDereferenceObject();
  }
  pWVar2 = *(WorkQueue **)(this + 0x138);
  *(undefined8 *)(this + 0x138) = 0;
  if (pWVar2 != (WorkQueue *)0x0) {
    WorkQueue::Dereference(pWVar2);
  }
  CancellableIrp::~CancellableIrp((CancellableIrp *)(this + 0x60));
  CancellableIrp::~CancellableIrp((CancellableIrp *)(this + 0x58));
  CancellableIrp::~CancellableIrp((CancellableIrp *)(this + 0x50));
  CancellableIrp::~CancellableIrp((CancellableIrp *)(this + 0x48));
  if (*(Channel **)(this + 0x30) != this + 0x30) {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\util.h";
    local_18 = 0x40;
    local_20 = "ListHead::~ListHead";
    OnFailure((ErrorSite *)&local_28,-0x3fffffff);
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(5);
  }
  return;
}



===== DeleteChannel @ 1c0007ed8 =====

/* private: void __cdecl VirtualMachine::DeleteChannel(struct Channel & __ptr64) __ptr64 */

void __thiscall VirtualMachine::DeleteChannel(VirtualMachine *this,Channel *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  
  lVar1 = *(longlong *)param_1;
  if ((*(Channel **)(lVar1 + 8) == param_1) &&
     (plVar2 = *(longlong **)(param_1 + 8), (Channel *)*plVar2 == param_1)) {
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    Channel::~Channel(param_1);
    ExFreePoolWithTag(param_1,0);
    return;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== DeviceCloseChannel @ 1c0007f28 =====

/* public: long __cdecl VirtualMachine::DeviceCloseChannel(struct Channel & __ptr64,class
   CompletedIrps & __ptr64) __ptr64 */

long __thiscall
VirtualMachine::DeviceCloseChannel(VirtualMachine *this,Channel *param_1,CompletedIrps *param_2)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  _IRP *p_Var4;
  GpadlSet *this_00;
  Channel *pCVar5;
  undefined1 *puVar6;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  puVar6 = auStack_48;
  iVar1 = *(int *)(param_1 + 0x20);
  if ((((iVar1 == 0) || (iVar1 == 1)) || (iVar1 == 2)) || (iVar1 == 3)) {
    local_18 = 0x13b;
    local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
    local_20 = "VirtualMachine::DeviceCloseChannel";
    local_10 = "%d";
    OnFailure((ErrorSite *)&local_28,-0x3ffffe7c);
    lVar3 = -0x3ffffe7c;
  }
  else {
    if (iVar1 != 4) {
      pCVar5 = param_1;
      if (iVar1 != 5) {
        local_18 = 0x152;
        local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
        pCVar5 = (Channel *)0xc0000001;
        local_20 = "VirtualMachine::DeviceCloseChannel";
        local_10 = "%d";
        OnFailure((ErrorSite *)&local_28,-0x3fffffff);
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(5);
        puVar6 = auStack_40;
      }
      *(undefined8 *)(puVar6 + -8) = 0x1c0007fb7;
      p_Var4 = CancellableIrp::Take((CancellableIrp *)(pCVar5 + 0x50));
      if (p_Var4 != (_IRP *)0x0) {
        *(undefined8 *)(puVar6 + -8) = 0x1c0007fca;
        CompletedIrps::Push(param_2,p_Var4,0);
      }
      this_00 = (GpadlSet *)(param_1 + 0x28);
      *(undefined8 *)(puVar6 + -8) = 0x1c0007fd6;
      GpadlSet::UnmapAllGpadls(this_00,param_2);
      *(undefined8 *)(puVar6 + -8) = 0x1c0007fde;
      ReleaseEvents((VirtualMachine *)this_00,param_1);
      *(undefined4 *)(param_1 + 0x20) = 2;
    }
    lVar3 = 0;
  }
  return lVar3;
}



===== DeviceCloseFile @ 1c0008038 =====

/* public: void __cdecl VirtualMachine::DeviceCloseFile(struct Channel & __ptr64,class CompletedIrps
   & __ptr64) __ptr64 */

void __thiscall
VirtualMachine::DeviceCloseFile(VirtualMachine *this,Channel *param_1,CompletedIrps *param_2)

{
  int iVar1;
  code *pcVar2;
  _IRP *p_Var3;
  CancellableIrp *this_00;
  undefined1 *puVar4;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  GpadlSet::UnmapAllGpadls((GpadlSet *)(param_1 + 0x28),param_2);
  this_00 = *(CancellableIrp **)(param_1 + 0x138);
  WorkQueue::Rundown((WorkQueue *)this_00);
  ReleaseEvents((VirtualMachine *)this_00,param_1);
  iVar1 = *(int *)(param_1 + 0x20);
  puVar4 = auStack_48;
  if ((iVar1 != 0) && (puVar4 = auStack_48, iVar1 != 1)) {
    puVar4 = auStack_48;
    if ((iVar1 != 2) &&
       (((puVar4 = auStack_48, iVar1 != 3 && (puVar4 = auStack_48, iVar1 != 4)) &&
        (puVar4 = auStack_48, iVar1 != 5)))) {
      local_18 = 0xd2;
      local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
      local_20 = "VirtualMachine::DeviceCloseFile";
      local_10 = "%d";
      OnFailure((ErrorSite *)&local_28,-0x3fffffff);
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(5);
      puVar4 = auStack_40;
    }
    *(undefined8 *)(puVar4 + -8) = 0x1c00080ee;
    p_Var3 = CancellableIrp::Take((CancellableIrp *)(param_1 + 0x48));
    if (p_Var3 != (_IRP *)0x0) {
      *(undefined8 *)(puVar4 + -8) = 0x1c0008104;
      CompletedIrps::Push(param_2,p_Var3,-0x3fffff4a);
    }
    this_00 = (CancellableIrp *)(param_1 + 0x50);
    *(undefined8 *)(puVar4 + -8) = 0x1c000810d;
    p_Var3 = CancellableIrp::Take(this_00);
    if (p_Var3 != (_IRP *)0x0) {
      *(undefined8 *)(puVar4 + -8) = 0x1c0008120;
      this_00 = (CancellableIrp *)param_2;
      CompletedIrps::Push(param_2,p_Var3,0);
    }
    *(undefined4 *)(param_1 + 0x20) = 6;
    if (this[0x10] == (VirtualMachine)0x0) {
      *(undefined8 *)(puVar4 + -8) = 0x1c0008138;
      WakeVmm(this,param_2);
      return;
    }
  }
  *(undefined8 *)(puVar4 + -8) = 0x1c0008142;
  DeleteChannel((VirtualMachine *)this_00,param_1);
  return;
}



===== DeviceCompleteOpen @ 1c000815c =====

/* public: long __cdecl VirtualMachine::DeviceCompleteOpen(struct Channel & __ptr64,long,class
   CompletedIrps & __ptr64) __ptr64 */

long __thiscall
VirtualMachine::DeviceCompleteOpen
          (VirtualMachine *this,Channel *param_1,long param_2,CompletedIrps *param_3)

{
  char *pcVar1;
  long lVar2;
  _IRP *p_Var3;
  uint uVar4;
  CancellableIrp *this_00;
  GpadlSet *this_01;
  long *plVar5;
  CompletedIrps *pCVar6;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  if (*(int *)(param_1 + 0x20) == 3) {
    this_00 = (CancellableIrp *)(param_1 + 0x48);
    p_Var3 = CancellableIrp::Take(this_00);
    pCVar6 = param_3;
    if (p_Var3 != (_IRP *)0x0) {
      pcVar1 = *(char **)(p_Var3 + 0xb8);
      if ((*pcVar1 == '\x0e') && ((*(uint *)(pcVar1 + 0x18) & 3) == 0)) {
        uVar4 = *(uint *)(pcVar1 + 8);
        plVar5 = *(long **)(p_Var3 + 0x18);
        if ((plVar5 == (long *)0x0) && (uVar4 != 0)) goto LAB_1c0008262;
      }
      else {
        uVar4 = 0;
        plVar5 = (long *)0x0;
      }
      if (uVar4 < 4) {
LAB_1c0008262:
                    /* WARNING: Subroutine does not return */
        gsl::details::terminate();
      }
      *plVar5 = param_2;
      *(undefined8 *)(p_Var3 + 0x38) = 4;
      CompletedIrps::Push(param_3,p_Var3,0);
      this_00 = (CancellableIrp *)param_3;
    }
    if (param_2 < 0) {
      this_01 = (GpadlSet *)(param_1 + 0x28);
      GpadlSet::UnmapAllGpadls(this_01,pCVar6);
      ReleaseEvents((VirtualMachine *)this_01,param_1);
      WorkQueue::Rundown(*(WorkQueue **)(param_1 + 0x138));
      *(undefined4 *)(param_1 + 0x20) = 2;
    }
    else {
      *(undefined4 *)(param_1 + 0x20) = 4;
      if (this[0x10] != (VirtualMachine)0x0) {
        VmmCloseChannel((VirtualMachine *)this_00,param_1,pCVar6);
      }
    }
    lVar2 = 0;
  }
  else {
    local_18 = 0x1a0;
    local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
    local_20 = "VirtualMachine::DeviceCompleteOpen";
    local_10 = "%d";
    OnFailure((ErrorSite *)&local_28,-0x3ffffe7c);
    lVar2 = -0x3ffffe7c;
  }
  return lVar2;
}



===== DeviceCreateChannel @ 1c0008270 =====

/* public: long __cdecl VirtualMachine::DeviceCreateChannel(struct Channel * __ptr64 * __ptr64)
   __ptr64 */

long __thiscall VirtualMachine::DeviceCreateChannel(VirtualMachine *this,Channel **param_1)

{
  undefined8 *puVar1;
  WorkQueue *pWVar2;
  longlong lVar3;
  code *pcVar4;
  long lVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  Channel *local_res8;
  char *local_38;
  char *local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  if (this[0x10] == (VirtualMachine)0x0) {
    make_unique<Channel>();
    if (local_res8 == (Channel *)0x0) {
      local_20 = 0;
      local_38 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
      local_28 = 0x7f;
      local_30 = "VirtualMachine::DeviceCreateChannel";
      OnFailure((ErrorSite *)&local_38,-0x3fffff66);
    }
    else {
      puVar6 = operator_new(0x40);
      if (puVar6 == (undefined8 *)0x0) {
        puVar6 = (undefined8 *)0x0;
      }
      else {
        *puVar6 = 1;
        KeInitializeSpinLock(puVar6 + 1);
        puVar1 = puVar6 + 2;
        *(undefined1 *)(puVar6 + 7) = 0;
        puVar6[3] = puVar1;
        *puVar1 = puVar1;
        KeInitializeEvent(puVar6 + 4,0,0);
      }
      pWVar2 = *(WorkQueue **)(local_res8 + 0x138);
      *(undefined8 **)(local_res8 + 0x138) = puVar6;
      if (pWVar2 != (WorkQueue *)0x0) {
        WorkQueue::Dereference(pWVar2);
      }
      if (*(longlong *)(local_res8 + 0x138) != 0) {
        ExWaitForRundownProtectionRelease(local_res8 + 0x210);
        lVar3 = *(longlong *)(this + 0x18);
        *(longlong *)(this + 0x18) = lVar3 + 1;
        *(longlong *)(local_res8 + 0x10) = lVar3;
        plVar7 = *(longlong **)(this + 8);
        if ((VirtualMachine *)*plVar7 != this) {
          pcVar4 = (code *)swi(0x29);
          plVar7 = (longlong *)(*pcVar4)(3);
        }
        *(longlong **)(local_res8 + 8) = plVar7;
        *(VirtualMachine **)local_res8 = this;
        *plVar7 = (longlong)local_res8;
        *(Channel **)(this + 8) = local_res8;
        *param_1 = local_res8;
        return 0;
      }
      local_20 = 0;
      local_38 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
      local_28 = 0x85;
      local_30 = "VirtualMachine::DeviceCreateChannel";
      OnFailure((ErrorSite *)&local_38,-0x3fffff66);
      Channel::~Channel(local_res8);
      ExFreePoolWithTag(local_res8,0);
    }
    lVar5 = -0x3fffff66;
  }
  else {
    local_20 = 0;
    local_38 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
    local_28 = 0x79;
    local_30 = "VirtualMachine::DeviceCreateChannel";
    OnFailure((ErrorSite *)&local_38,-0x3ffffe7c);
    lVar5 = -0x3ffffe7c;
  }
  return lVar5;
}



===== DeviceIoctlOffer @ 1c0008440 =====

/* public: long __cdecl VirtualMachine::DeviceIoctlOffer(struct Channel & __ptr64,struct _IRP *
   __ptr64,struct _VMBUS_OFFER_CHANNEL_INPUT_PARAMETERS const & __ptr64,class CompletedIrps &
   __ptr64) __ptr64 */

long __thiscall
VirtualMachine::DeviceIoctlOffer
          (VirtualMachine *this,Channel *param_1,_IRP *param_2,
          _VMBUS_OFFER_CHANNEL_INPUT_PARAMETERS *param_3,CompletedIrps *param_4)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  int iVar6;
  longlong lVar7;
  longlong lVar8;
  longlong local_res8;
  longlong local_58;
  longlong *local_50;
  char *local_48;
  undefined8 local_40;
  char *local_38;
  
  if (this[0x10] == (VirtualMachine)0x0) {
    if (*(int *)(param_1 + 0x20) == 0) {
      local_res8 = 0;
      if ((*(longlong *)(param_3 + 0xb0) == 0) && (*(longlong *)(param_3 + 0xb8) == 0)) {
        local_50 = &local_res8;
        local_58 = 0;
        local_48 = (char *)0x0;
        local_40 = CONCAT71(local_40._1_7_,1);
        iVar6 = ExCreateDpcEvent(&local_48,&local_58,param_1 + 0x180);
        if (((char)local_40 != '\0') &&
           (lVar7 = *local_50, *local_50 = (longlong)local_48, lVar7 != 0)) {
          ExDeleteDpcEvent();
        }
        lVar7 = local_58;
        if (iVar6 < 0) {
          local_40 = 0x103;
          local_50 = (longlong *)0x1c000c698;
          local_38 = (char *)0x0;
          local_48 = "VirtualMachine::DeviceIoctlOffer";
          OnFailure((ErrorSite *)&local_50,iVar6);
          lVar7 = local_res8;
          local_res8 = 0;
          if (lVar7 == 0) {
            return iVar6;
          }
          ExDeleteDpcEvent();
          return iVar6;
        }
        ObfReferenceObject(local_58);
        lVar8 = 0;
      }
      else {
        local_58 = 0;
        iVar6 = ObReferenceObjectByHandle
                          (*(longlong *)(param_3 + 0xb0),2,*(undefined8 *)ExEventObjectType_exref,
                           param_2[0x40],&local_58,0);
        lVar7 = local_58;
        if (iVar6 < 0) {
          local_40 = 0xf1;
          local_50 = (longlong *)0x1c000c698;
          local_38 = (char *)0x0;
          local_48 = "VirtualMachine::DeviceIoctlOffer";
          OnFailure((ErrorSite *)&local_50,iVar6);
          if (local_res8 != 0) {
            ExDeleteDpcEvent();
          }
          if (lVar7 != 0) {
            ObfDereferenceObject(lVar7);
          }
          return iVar6;
        }
        local_58 = 0;
        iVar6 = ObReferenceObjectByHandle
                          (*(undefined8 *)(param_3 + 0xb8),2,*(undefined8 *)ExEventObjectType_exref,
                           param_2[0x40],&local_58,0);
        lVar8 = local_58;
        if (iVar6 < 0) {
          local_40 = 0xf9;
          local_50 = (longlong *)0x1c000c698;
          local_38 = (char *)0x0;
          local_48 = "VirtualMachine::DeviceIoctlOffer";
          OnFailure((ErrorSite *)&local_50,iVar6);
          if (local_res8 != 0) {
            ExDeleteDpcEvent();
          }
          if (lVar8 != 0) {
            ObfDereferenceObject(lVar8);
          }
          if (lVar7 != 0) {
            ObfDereferenceObject(lVar7);
          }
          return iVar6;
        }
        if ((local_58 == lVar7) && (lVar8 = 0, local_58 != 0)) {
          ObfDereferenceObject();
        }
      }
      uVar5 = *(undefined8 *)(param_3 + 8);
      *(undefined8 *)(param_1 + 0x68) = *(undefined8 *)param_3;
      *(undefined8 *)(param_1 + 0x70) = uVar5;
      uVar5 = *(undefined8 *)(param_3 + 0x18);
      *(undefined8 *)(param_1 + 0x78) = *(undefined8 *)(param_3 + 0x10);
      *(undefined8 *)(param_1 + 0x80) = uVar5;
      uVar5 = *(undefined8 *)(param_3 + 0x28);
      *(undefined8 *)(param_1 + 0x88) = *(undefined8 *)(param_3 + 0x20);
      *(undefined8 *)(param_1 + 0x90) = uVar5;
      uVar5 = *(undefined8 *)(param_3 + 0x38);
      *(undefined8 *)(param_1 + 0x98) = *(undefined8 *)(param_3 + 0x30);
      *(undefined8 *)(param_1 + 0xa0) = uVar5;
      uVar5 = *(undefined8 *)(param_3 + 0x48);
      *(undefined8 *)(param_1 + 0xa8) = *(undefined8 *)(param_3 + 0x40);
      *(undefined8 *)(param_1 + 0xb0) = uVar5;
      uVar5 = *(undefined8 *)(param_3 + 0x58);
      *(undefined8 *)(param_1 + 0xb8) = *(undefined8 *)(param_3 + 0x50);
      *(undefined8 *)(param_1 + 0xc0) = uVar5;
      uVar5 = *(undefined8 *)(param_3 + 0x68);
      *(undefined8 *)(param_1 + 200) = *(undefined8 *)(param_3 + 0x60);
      *(undefined8 *)(param_1 + 0xd0) = uVar5;
      uVar5 = *(undefined8 *)(param_3 + 0x78);
      *(undefined8 *)(param_1 + 0xd8) = *(undefined8 *)(param_3 + 0x70);
      *(undefined8 *)(param_1 + 0xe0) = uVar5;
      uVar5 = *(undefined8 *)(param_3 + 0x88);
      *(undefined8 *)(param_1 + 0xe8) = *(undefined8 *)(param_3 + 0x80);
      *(undefined8 *)(param_1 + 0xf0) = uVar5;
      uVar2 = *(undefined4 *)(param_3 + 0x94);
      uVar3 = *(undefined4 *)(param_3 + 0x98);
      uVar4 = *(undefined4 *)(param_3 + 0x9c);
      *(undefined4 *)(param_1 + 0xf8) = *(undefined4 *)(param_3 + 0x90);
      *(undefined4 *)(param_1 + 0xfc) = uVar2;
      *(undefined4 *)(param_1 + 0x100) = uVar3;
      *(undefined4 *)(param_1 + 0x104) = uVar4;
      uVar2 = *(undefined4 *)(param_3 + 0xa4);
      uVar3 = *(undefined4 *)(param_3 + 0xa8);
      uVar4 = *(undefined4 *)(param_3 + 0xac);
      *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)(param_3 + 0xa0);
      *(undefined4 *)(param_1 + 0x10c) = uVar2;
      *(undefined4 *)(param_1 + 0x110) = uVar3;
      *(undefined4 *)(param_1 + 0x114) = uVar4;
      lVar1 = *(longlong *)(param_1 + 0x140);
      *(longlong *)(param_1 + 0x140) = lVar7;
      if (lVar1 != 0) {
        ObfDereferenceObject();
      }
      lVar7 = *(longlong *)(param_1 + 0x148);
      *(longlong *)(param_1 + 0x148) = lVar8;
      if (lVar7 != 0) {
        ObfDereferenceObject();
      }
      lVar8 = local_res8;
      lVar7 = *(longlong *)(param_1 + 0x178);
      local_res8 = 0;
      *(longlong *)(param_1 + 0x178) = lVar8;
      if (lVar7 != 0) {
        ExDeleteDpcEvent();
      }
      *(undefined4 *)(param_1 + 0x20) = 1;
      WakeVmm(this,param_4);
      lVar7 = local_res8;
      local_res8 = 0;
      if (lVar7 != 0) {
        ExDeleteDpcEvent();
      }
      return 0;
    }
    local_40 = 0xe1;
    local_50 = (longlong *)0x1c000c698;
    local_48 = "VirtualMachine::DeviceIoctlOffer";
    local_38 = "%d";
    OnFailure((ErrorSite *)&local_50,-0x3ffffe7c);
  }
  else {
    local_40 = 0xdc;
    local_50 = (longlong *)0x1c000c698;
    local_38 = (char *)0x0;
    local_48 = "VirtualMachine::DeviceIoctlOffer";
    OnFailure((ErrorSite *)&local_50,-0x3ffffe7c);
  }
  return -0x3ffffe7c;
}



===== FillNextActionIrp @ 1c0008868 =====

/* private: bool __cdecl VirtualMachine::FillNextActionIrp(struct VMBUS_PROXY_NEXT_ACTION_OUTPUT *
   __ptr64,long * __ptr64) __ptr64 */

bool __thiscall
VirtualMachine::FillNextActionIrp
          (VirtualMachine *this,VMBUS_PROXY_NEXT_ACTION_OUTPUT *param_1,long *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  Channel *pCVar3;
  Channel *pCVar4;
  long lVar5;
  
  pCVar4 = *(Channel **)this;
  do {
    pCVar3 = pCVar4;
    if (pCVar3 == (Channel *)this) {
      return false;
    }
    if (*(int *)(pCVar3 + 0x20) == 1) {
      lVar5 = FillOfferAction(pCVar3,param_1);
      *param_2 = lVar5;
      *(undefined4 *)(pCVar3 + 0x20) = 2;
      return true;
    }
    if (*(int *)(pCVar3 + 0x20) == 6) {
      *(undefined4 *)param_1 = 2;
      *(undefined8 *)(param_1 + 8) = *(undefined8 *)(pCVar3 + 0x10);
      *(undefined4 *)(pCVar3 + 0x20) = 7;
      *param_2 = 0;
      return true;
    }
    pCVar4 = *(Channel **)pCVar3;
  } while (*(int *)(pCVar3 + 0x128) < 1);
  *(undefined4 *)param_1 = 3;
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(pCVar3 + 0x10);
  uVar1 = *(undefined8 *)(pCVar3 + 0x128);
  uVar2 = *(undefined8 *)(pCVar3 + 0x130);
  *param_2 = 0;
  *(undefined8 *)(param_1 + 0x10) = uVar1;
  *(undefined8 *)(param_1 + 0x18) = uVar2;
  *(undefined8 *)(pCVar3 + 0x128) = 0;
  *(undefined8 *)(pCVar3 + 0x130) = 0;
  return true;
}



===== FillOfferAction @ 1c0008914 =====

/* long __cdecl FillOfferAction(struct Channel & __ptr64,struct VMBUS_PROXY_NEXT_ACTION_OUTPUT *
   __ptr64) */

long __cdecl FillOfferAction(Channel *param_1,VMBUS_PROXY_NEXT_ACTION_OUTPUT *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  longlong lVar4;
  longlong local_res8;
  longlong local_res18;
  char *local_38;
  char *local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  local_res8 = 0;
  iVar3 = ObOpenObjectByPointer
                    (*(undefined8 *)(param_1 + 0x140),0,0,2,*(undefined8 *)ExEventObjectType_exref,1
                     ,&local_res8);
  if (iVar3 < 0) {
    local_28 = 0x1f;
    local_38 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
    local_20 = 0;
    local_30 = "FillOfferAction";
    OnFailure((ErrorSite *)&local_38,iVar3);
LAB_1c00089a0:
    if (local_res8 != 0) {
      ZwClose();
    }
  }
  else {
    local_res18 = 0;
    lVar4 = 0;
    if (*(longlong *)(param_1 + 0x148) != 0) {
      iVar3 = ObOpenObjectByPointer
                        (*(longlong *)(param_1 + 0x148),0,0,2,*(undefined8 *)ExEventObjectType_exref
                         ,1,&local_res18);
      if (iVar3 < 0) {
        local_28 = 0x2b;
        local_38 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
        local_20 = 0;
        local_30 = "FillOfferAction";
        OnFailure((ErrorSite *)&local_38,iVar3);
        if (local_res18 != 0) {
          ZwClose();
        }
        goto LAB_1c00089a0;
      }
      lVar4 = local_res18;
    }
    *(undefined4 *)param_2 = 1;
    *(undefined8 *)(param_2 + 8) = *(undefined8 *)(param_1 + 0x10);
    uVar1 = *(undefined8 *)(param_1 + 0x70);
    *(undefined8 *)(param_2 + 0x10) = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_2 + 0x18) = uVar1;
    uVar1 = *(undefined8 *)(param_1 + 0x80);
    *(undefined8 *)(param_2 + 0x20) = *(undefined8 *)(param_1 + 0x78);
    *(undefined8 *)(param_2 + 0x28) = uVar1;
    uVar1 = *(undefined8 *)(param_1 + 0x90);
    *(undefined8 *)(param_2 + 0x30) = *(undefined8 *)(param_1 + 0x88);
    *(undefined8 *)(param_2 + 0x38) = uVar1;
    uVar1 = *(undefined8 *)(param_1 + 0xa0);
    *(undefined8 *)(param_2 + 0x40) = *(undefined8 *)(param_1 + 0x98);
    *(undefined8 *)(param_2 + 0x48) = uVar1;
    uVar1 = *(undefined8 *)(param_1 + 0xb0);
    *(undefined8 *)(param_2 + 0x50) = *(undefined8 *)(param_1 + 0xa8);
    *(undefined8 *)(param_2 + 0x58) = uVar1;
    uVar1 = *(undefined8 *)(param_1 + 0xc0);
    *(undefined8 *)(param_2 + 0x60) = *(undefined8 *)(param_1 + 0xb8);
    *(undefined8 *)(param_2 + 0x68) = uVar1;
    uVar1 = *(undefined8 *)(param_1 + 0xd0);
    *(undefined8 *)(param_2 + 0x70) = *(undefined8 *)(param_1 + 200);
    *(undefined8 *)(param_2 + 0x78) = uVar1;
    uVar1 = *(undefined8 *)(param_1 + 0xe0);
    *(undefined8 *)(param_2 + 0x80) = *(undefined8 *)(param_1 + 0xd8);
    *(undefined8 *)(param_2 + 0x88) = uVar1;
    uVar1 = *(undefined8 *)(param_1 + 0xf0);
    *(undefined8 *)(param_2 + 0x90) = *(undefined8 *)(param_1 + 0xe8);
    *(undefined8 *)(param_2 + 0x98) = uVar1;
    uVar1 = *(undefined8 *)(param_1 + 0x100);
    *(undefined8 *)(param_2 + 0xa0) = *(undefined8 *)(param_1 + 0xf8);
    *(undefined8 *)(param_2 + 0xa8) = uVar1;
    uVar1 = *(undefined8 *)(param_1 + 0x108);
    uVar2 = *(undefined8 *)(param_1 + 0x110);
    *(longlong *)(param_2 + 0xc0) = local_res8;
    iVar3 = 0;
    *(longlong *)(param_2 + 200) = lVar4;
    *(undefined8 *)(param_2 + 0xb0) = uVar1;
    *(undefined8 *)(param_2 + 0xb8) = uVar2;
  }
  return iVar3;
}



===== ReleaseEvents @ 1c0008b14 =====

/* private: void __cdecl VirtualMachine::ReleaseEvents(struct Channel & __ptr64) __ptr64 */

void __thiscall VirtualMachine::ReleaseEvents(VirtualMachine *this,Channel *param_1)

{
  longlong lVar1;
  
  if (*(longlong *)(param_1 + 0x218) != 0) {
    ExWaitForRundownProtectionRelease(param_1 + 0x210);
    lVar1 = *(longlong *)(param_1 + 0x218);
    *(undefined8 *)(param_1 + 0x218) = 0;
    if (lVar1 != 0) {
      ObfDereferenceObject();
    }
  }
  return;
}



===== VmmCleanupFile @ 1c0008b68 =====

/* public: void __cdecl VirtualMachine::VmmCleanupFile(class CompletedIrps & __ptr64) __ptr64 */

void __thiscall VirtualMachine::VmmCleanupFile(VirtualMachine *this,CompletedIrps *param_1)

{
  GpadlSet *pGVar1;
  int iVar2;
  VirtualMachine *pVVar3;
  code *pcVar4;
  bool bVar5;
  _IRP *p_Var6;
  uint uVar7;
  GpadlSet *this_00;
  Gpadl *pGVar8;
  Gpadl *pGVar9;
  undefined1 *puVar10;
  Gpadl *pGVar11;
  VirtualMachine *pVVar12;
  undefined1 auStack_88 [8];
  undefined1 auStack_80 [24];
  Gpadl *local_68;
  Gpadl *local_60;
  GpadlSet *local_58;
  undefined1 uStack_50;
  undefined4 uStack_4f;
  undefined2 uStack_4b;
  undefined1 uStack_49;
  GpadlSet *local_48;
  char *pcStack_40;
  undefined8 local_38;
  char *local_30;
  
  this[0x10] = (VirtualMachine)0x1;
  p_Var6 = CancellableIrp::Take((CancellableIrp *)(this + 0x20));
  if (p_Var6 != (_IRP *)0x0) {
    CompletedIrps::Push(param_1,p_Var6,-0x3ffffee0);
  }
  puVar10 = auStack_88;
  if (*(VirtualMachine **)this != this) {
    pVVar12 = *(VirtualMachine **)this;
    do {
      local_60 = (Gpadl *)&local_68;
      pVVar3 = *(VirtualMachine **)pVVar12;
      local_68 = (Gpadl *)&local_68;
      pGVar1 = (GpadlSet *)(pVVar12 + 0x28);
      this_00 = pGVar1;
      uStack_50 = KeAcquireSpinLockRaiseToDpc();
      *(Channel *)(pVVar12 + 0x40) = (Channel)0x0;
      pGVar8 = *(Gpadl **)(pVVar12 + 0x30);
      local_58 = pGVar1;
      while (pGVar8 != (Gpadl *)(pVVar12 + 0x30)) {
        pGVar9 = *(Gpadl **)pGVar8;
        pGVar8[0x31] = (Gpadl)0x1;
        pGVar11 = pGVar8;
        bVar5 = GpadlSet::RemoveGpadlIfUnreferenced(this_00,pGVar8,param_1);
        pGVar8 = pGVar9;
        if (bVar5) {
          if (*(Gpadl ***)local_60 != &local_68) {
            pcVar4 = (code *)swi(0x29);
            (*pcVar4)(3);
            puVar10 = auStack_80;
            goto LAB_1c0008d5c;
          }
          *(Gpadl **)(pGVar11 + 8) = local_60;
          this_00 = (GpadlSet *)&local_68;
          *(GpadlSet **)pGVar11 = this_00;
          *(Gpadl **)local_60 = pGVar11;
          local_60 = pGVar11;
        }
      }
      if (pGVar1 != (GpadlSet *)0x0) {
        pcStack_40 = (char *)CONCAT17(uStack_49,CONCAT25(uStack_4b,CONCAT41(uStack_4f,uStack_50)));
        local_48 = local_58;
        wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_48);
      }
      pGVar8 = local_68;
      while (pGVar9 = pGVar8, pGVar9 != (Gpadl *)&local_68) {
        pGVar8 = *(Gpadl **)pGVar9;
        if (pGVar9 != (Gpadl *)0x0) {
          Gpadl::~Gpadl(pGVar9);
          ExFreePoolWithTag(pGVar9,0);
        }
      }
      local_60 = (Gpadl *)&local_68;
      local_68 = (Gpadl *)&local_68;
      p_Var6 = CancellableIrp::Take((CancellableIrp *)(pVVar12 + 0x50));
      if (p_Var6 != (_IRP *)0x0) {
        CompletedIrps::Push(param_1,p_Var6,-0x3ffffee0);
      }
      p_Var6 = CancellableIrp::Take((CancellableIrp *)(pVVar12 + 0x48));
      if (p_Var6 != (_IRP *)0x0) {
        CompletedIrps::Push(param_1,p_Var6,-0x3ffffee0);
      }
      iVar2 = *(int *)(pVVar12 + 0x20);
      if ((((iVar2 != 0) && (iVar2 != 1)) && (iVar2 != 2)) && (iVar2 != 3)) {
        if (iVar2 == 4) {
          VmmCloseChannel((VirtualMachine *)0x0,(Channel *)pVVar12,param_1);
        }
        else if (iVar2 != 5) {
          uVar7 = iVar2 - 6;
          if ((uVar7 != 0) && (uVar7 != 1)) {
LAB_1c0008d5c:
            local_38 = 0x345;
            local_48 = (GpadlSet *)0x1c000c698;
            pcStack_40 = "VirtualMachine::VmmCleanupFile";
            local_30 = "%d";
            *(undefined8 *)(puVar10 + -8) = 0x1c0008d93;
            OnFailure((ErrorSite *)&local_48,-0x3fffffff);
            pcVar4 = (code *)swi(0x29);
            (*pcVar4)(5);
            pcVar4 = (code *)swi(3);
            (*pcVar4)();
            return;
          }
          DeleteChannel((VirtualMachine *)(ulonglong)uVar7,(Channel *)pVVar12);
        }
      }
      pVVar12 = pVVar3;
    } while (pVVar3 != this);
  }
  return;
}



===== VmmCloseChannel @ 1c0008da0 =====

/* public: void __cdecl VirtualMachine::VmmCloseChannel(struct Channel & __ptr64,class CompletedIrps
   & __ptr64) __ptr64 */

void __thiscall
VirtualMachine::VmmCloseChannel(VirtualMachine *this,Channel *param_1,CompletedIrps *param_2)

{
  char *pcVar1;
  _IRP *p_Var2;
  uint uVar3;
  undefined4 *puVar4;
  
  p_Var2 = CancellableIrp::Take((CancellableIrp *)(param_1 + 0x58));
  if (p_Var2 != (_IRP *)0x0) {
    pcVar1 = *(char **)(p_Var2 + 0xb8);
    if ((*pcVar1 == '\x0e') && ((*(uint *)(pcVar1 + 0x18) & 3) == 0)) {
      puVar4 = *(undefined4 **)(p_Var2 + 0x18);
      uVar3 = *(uint *)(pcVar1 + 8);
      if ((puVar4 == (undefined4 *)0x0) && (uVar3 != 0)) goto LAB_1c0008e24;
    }
    else {
      uVar3 = 0;
      puVar4 = (undefined4 *)0x0;
    }
    if (uVar3 < 4) {
LAB_1c0008e24:
                    /* WARNING: Subroutine does not return */
      gsl::details::terminate();
    }
    *puVar4 = 3;
    *(undefined8 *)(p_Var2 + 0x38) = 4;
    CompletedIrps::Push(param_2,p_Var2,0);
  }
  WorkQueue::Rundown(*(WorkQueue **)(param_1 + 0x138));
  *(undefined4 *)(param_1 + 0x20) = 5;
  return;
}



===== VmmIoctlCreateGpadl @ 1c0008e30 =====

/* public: long __cdecl VirtualMachine::VmmIoctlCreateGpadl(struct VMBUS_PROXY_CREATE_GPADL_INPUT
   const & __ptr64,class gsl::span<enum gsl::byte const ,-1>) __ptr64 */

long __thiscall
VirtualMachine::VmmIoctlCreateGpadl(VirtualMachine *this,longlong *param_1,ulonglong *param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  ulonglong uVar4;
  code *pcVar5;
  longlong lVar6;
  Gpadl *pGVar7;
  VirtualMachine *pVVar8;
  long lVar9;
  VirtualMachine *pVVar10;
  longlong *plVar11;
  undefined1 *puVar12;
  ulonglong uVar13;
  Gpadl *local_res8;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [40];
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  puVar12 = auStack_58;
  if (this[0x10] == (VirtualMachine)0x0) {
    pVVar8 = *(VirtualMachine **)this;
    do {
      pVVar10 = pVVar8;
      if (pVVar10 == this) {
        local_18 = 0x2df;
        local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
        local_20 = "VirtualMachine::VmmIoctlCreateGpadl";
        local_10 = "%lld";
        OnFailure((ErrorSite *)&local_28,-0x3ffffddb);
        return -0x3ffffddb;
      }
      pVVar8 = *(VirtualMachine **)pVVar10;
    } while (*(longlong *)(pVVar10 + 0x10) != *param_1);
    iVar1 = *(int *)(pVVar10 + 0x20);
    if ((iVar1 == 0) || (iVar1 == 1)) {
      local_18 = 0x2e4;
      local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
      local_20 = "VirtualMachine::VmmIoctlCreateGpadl";
      local_10 = "%d";
      OnFailure((ErrorSite *)&local_28,-0x3ffffe7c);
      return -0x3ffffe7c;
    }
    plVar11 = param_1;
    puVar12 = auStack_58;
    if (((((iVar1 != 2) && (puVar12 = auStack_58, iVar1 != 3)) && (puVar12 = auStack_58, iVar1 != 4)
         ) && ((puVar12 = auStack_58, iVar1 != 5 && (puVar12 = auStack_58, iVar1 != 6)))) &&
       (puVar12 = auStack_58, iVar1 != 7)) {
      local_18 = 0x2f4;
      local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
      plVar11 = (longlong *)0xc0000001;
      local_20 = "VirtualMachine::VmmIoctlCreateGpadl";
      local_10 = "%d";
      OnFailure((ErrorSite *)&local_28,-0x3fffffff);
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(5);
      puVar12 = auStack_50;
    }
    uVar13 = (ulonglong)*(uint *)(plVar11 + 2);
    uVar4 = *param_3;
    if ((uVar4 < uVar13) ||
       (local_28 = (char *)(ulonglong)*(uint *)((longlong)plVar11 + 0x14),
       (char *)(uVar4 - uVar13) < local_28)) {
      uVar3 = *(uint *)((longlong)param_1 + 0x14);
      local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
      *(ulonglong *)(puVar12 + 0x20) = uVar4;
      local_20 = "VirtualMachine::VmmIoctlCreateGpadl";
      local_18 = 0x2fa;
      local_10 = "%u %u %zu";
      *(undefined8 *)(puVar12 + -8) = 0x1c0009076;
      OnFailure((ErrorSite *)&local_28,-0x3ffffff3,uVar13,(ulonglong)uVar3);
      return -0x3ffffff3;
    }
    local_res8 = (Gpadl *)0x0;
    local_20 = (char *)(param_3[1] + uVar13);
    lVar6 = param_1[1];
    uVar2 = *(undefined4 *)((longlong)param_1 + 0xc);
    *(undefined8 *)(puVar12 + -8) = 0x1c0008fa8;
    lVar9 = Gpadl::Create((int)lVar6,uVar2,&local_28,&local_res8);
    if (lVar9 < 0) {
      local_10 = (char *)0x0;
      local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
      local_18 = 0x2ff;
      local_20 = "VirtualMachine::VmmIoctlCreateGpadl";
      *(undefined8 *)(puVar12 + -8) = 0x1c0008fdc;
      OnFailure((ErrorSite *)&local_28,lVar9);
      pGVar7 = local_res8;
      if (local_res8 != (Gpadl *)0x0) {
        *(undefined8 *)(puVar12 + -8) = 0x1c0008fed;
        Gpadl::~Gpadl(local_res8);
        *(undefined8 *)(puVar12 + -8) = 0x1c0008ff9;
        ExFreePoolWithTag(pGVar7,0);
      }
      return lVar9;
    }
    *(undefined8 *)(puVar12 + -8) = 0x1c000901a;
    lVar9 = GpadlSet::AddGpadl((GpadlSet *)(pVVar10 + 0x28),&local_res8);
    if (-1 < lVar9) {
      return 0;
    }
    local_18 = 0x300;
  }
  else {
    local_18 = 0x2db;
    lVar9 = -0x3ffffe7c;
  }
  local_10 = (char *)0x0;
  local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
  local_20 = "VirtualMachine::VmmIoctlCreateGpadl";
  *(undefined8 *)(puVar12 + -8) = 0x1c0008e81;
  OnFailure((ErrorSite *)&local_28,lVar9);
  return lVar9;
}



===== VmmIoctlOpenChannel @ 1c00090c0 =====

/* public: long __cdecl VirtualMachine::VmmIoctlOpenChannel(struct _IRP * __ptr64,struct
   VMBUS_PROXY_OPEN_CHANNEL_INPUT const & __ptr64,struct VMBUS_PROXY_OPEN_CHANNEL_OUTPUT *
   __ptr64,class CompletedIrps & __ptr64) __ptr64 */

long __thiscall
VirtualMachine::VmmIoctlOpenChannel
          (VirtualMachine *this,_IRP *param_1,VMBUS_PROXY_OPEN_CHANNEL_INPUT *param_2,
          VMBUS_PROXY_OPEN_CHANNEL_OUTPUT *param_3,CompletedIrps *param_4)

{
  longlong lVar1;
  char *pcVar2;
  longlong lVar3;
  code *pcVar4;
  VirtualMachine *pVVar5;
  undefined1 uVar6;
  int iVar7;
  uint uVar8;
  VirtualMachine *pVVar9;
  _IRP *p_Var10;
  undefined4 *puVar11;
  undefined8 *puVar12;
  longlong lVar13;
  longlong local_res8;
  VirtualMachine *local_38;
  char *pcStack_30;
  undefined8 local_28;
  char *local_20;
  
  if (this[0x10] != (VirtualMachine)0x0) {
    local_20 = (char *)0x0;
    local_38 = (VirtualMachine *)0x1c000c698;
    local_28 = 0x236;
    pcStack_30 = "VirtualMachine::VmmIoctlOpenChannel";
    OnFailure((ErrorSite *)&local_38,-0x3ffffe7c);
    return -0x3ffffe7c;
  }
  pVVar5 = *(VirtualMachine **)this;
  do {
    pVVar9 = pVVar5;
    if (pVVar9 == this) {
      local_28 = 0x23a;
      local_38 = (VirtualMachine *)0x1c000c698;
      pcStack_30 = "VirtualMachine::VmmIoctlOpenChannel";
      local_20 = "%lld";
      OnFailure((ErrorSite *)&local_38,-0x3ffffddb);
      return -0x3ffffddb;
    }
    pVVar5 = *(VirtualMachine **)pVVar9;
  } while (*(longlong *)(pVVar9 + 0x10) != *(longlong *)param_2);
  iVar7 = *(int *)(pVVar9 + 0x20);
  if ((iVar7 == 0) || (iVar7 == 1)) {
LAB_1c0009494:
    local_28 = 0x242;
    local_38 = (VirtualMachine *)0x1c000c698;
    pcStack_30 = "VirtualMachine::VmmIoctlOpenChannel";
    local_20 = "%d";
    OnFailure((ErrorSite *)&local_38,-0x3ffffe7c);
    return -0x3ffffe7c;
  }
  if (iVar7 != 2) {
    if (((iVar7 != 3) && (iVar7 != 4)) && (iVar7 != 5)) {
      if ((iVar7 != 6) && (iVar7 != 7)) {
        local_28 = 0x24f;
        local_38 = (VirtualMachine *)0x1c000c698;
        pcStack_30 = "VirtualMachine::VmmIoctlOpenChannel";
        local_20 = "%d";
        OnFailure((ErrorSite *)&local_38,-0x3fffffff);
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(5);
      }
      *(undefined4 *)param_3 = 0xc00000b6;
      return 0;
    }
    goto LAB_1c0009494;
  }
  lVar13 = 0;
  if (*(longlong *)(param_2 + 0x18) != 0) {
    local_res8 = 0;
    iVar7 = ObReferenceObjectByHandle
                      (*(longlong *)(param_2 + 0x18),2,*(undefined8 *)ExEventObjectType_exref,
                       param_1[0x40],&local_res8,0);
    lVar13 = local_res8;
    if (iVar7 < 0) {
      local_28 = 0x25b;
      goto LAB_1c000926c;
    }
  }
  iVar7 = CancellableIrp::Set((CancellableIrp *)(pVVar9 + 0x48),param_1);
  if (iVar7 < 0) {
    local_28 = 0x25e;
LAB_1c000926c:
    local_20 = (char *)0x0;
    local_38 = (VirtualMachine *)0x1c000c698;
    pcStack_30 = "VirtualMachine::VmmIoctlOpenChannel";
    OnFailure((ErrorSite *)&local_38,iVar7);
    if (lVar13 == 0) {
      return iVar7;
    }
    ObfDereferenceObject(lVar13);
    return iVar7;
  }
  *(undefined8 *)(pVVar9 + 0x118) = *(undefined8 *)(param_2 + 8);
  *(undefined4 *)(pVVar9 + 0x120) = *(undefined4 *)(param_2 + 0x10);
  p_Var10 = CancellableIrp::Take((CancellableIrp *)(pVVar9 + 0x58));
  if (p_Var10 != (_IRP *)0x0) {
    pcVar2 = *(char **)(p_Var10 + 0xb8);
    if ((*pcVar2 == '\x0e') && ((*(uint *)(pcVar2 + 0x18) & 3) == 0)) {
      puVar11 = *(undefined4 **)(p_Var10 + 0x18);
      uVar8 = *(uint *)(pcVar2 + 8);
      if ((puVar11 == (undefined4 *)0x0) && (uVar8 != 0)) goto LAB_1c00094d2;
    }
    else {
      uVar8 = 0;
      puVar11 = (undefined4 *)0x0;
    }
    if (uVar8 < 4) goto LAB_1c00094d2;
    *puVar11 = 1;
    *(undefined8 *)(p_Var10 + 0x38) = 4;
    CompletedIrps::Push(param_4,p_Var10,0);
  }
  p_Var10 = CancellableIrp::Take((CancellableIrp *)(pVVar9 + 0x60));
  if (p_Var10 != (_IRP *)0x0) {
    pcVar2 = *(char **)(p_Var10 + 0xb8);
    if ((*pcVar2 == '\x0e') && ((*(uint *)(pcVar2 + 0x18) & 3) == 0)) {
      puVar12 = *(undefined8 **)(p_Var10 + 0x18);
      uVar8 = *(uint *)(pcVar2 + 8);
      if ((puVar12 == (undefined8 *)0x0) && (uVar8 != 0)) goto LAB_1c00094d2;
    }
    else {
      uVar8 = 0;
      puVar12 = (undefined8 *)0x0;
    }
    if (uVar8 < 0xc) {
LAB_1c00094d2:
                    /* WARNING: Subroutine does not return */
      gsl::details::terminate();
    }
    *puVar12 = *(undefined8 *)(param_2 + 8);
    *(undefined4 *)(puVar12 + 1) = *(undefined4 *)(param_2 + 0x10);
    *(undefined8 *)(p_Var10 + 0x38) = 0xc;
    CompletedIrps::Push(param_4,p_Var10,0);
  }
  lVar3 = *(longlong *)(pVVar9 + 0x138);
  lVar1 = lVar3 + 8;
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
  pcVar2 = pcStack_30;
  pcStack_30._0_5_ = CONCAT41(pcStack_30._1_4_,uVar6);
  pcStack_30._5_2_ = SUB82(pcVar2,5);
  pcStack_30._7_1_ = SUB81(pcVar2,7);
  *(undefined1 *)(lVar3 + 0x38) = 1;
  local_38 = (VirtualMachine *)lVar1;
  if (lVar1 != 0) {
    wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_38);
  }
  if (lVar13 != 0) {
    lVar1 = *(longlong *)(pVVar9 + 0x218);
    *(longlong *)(pVVar9 + 0x218) = lVar13;
    if (lVar1 != 0) {
      ObfDereferenceObject();
    }
    ExReInitializeRundownProtection(pVVar9 + 0x210);
  }
  uVar6 = KeAcquireSpinLockRaiseToDpc(pVVar9 + 0x28);
  pcVar2 = pcStack_30;
  pcStack_30._0_5_ = CONCAT41(pcStack_30._1_4_,uVar6);
  pcStack_30._5_2_ = SUB82(pcVar2,5);
  pcStack_30._7_1_ = SUB81(pcVar2,7);
  pVVar9[0x40] = (VirtualMachine)0x1;
  local_38 = pVVar9 + 0x28;
  wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_38);
  *(undefined4 *)(pVVar9 + 0x20) = 3;
  return 0x103;
}



===== VmmIoctlSetVmName @ 1c00094e0 =====

/* public: long __cdecl VirtualMachine::VmmIoctlSetVmName(struct VMBUS_PROXY_SET_VM_NAME_INPUT const
   & __ptr64,class gsl::span<enum gsl::byte const ,-1>) __ptr64 */

long __thiscall
VirtualMachine::VmmIoctlSetVmName(VirtualMachine *this,undefined8 *param_1,ulonglong *param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  ulonglong uVar3;
  code *pcVar4;
  undefined1 auVar5 [16];
  undefined8 uVar6;
  undefined8 uVar7;
  __uint64 _Var8;
  wchar_t *_Src;
  size_t sVar9;
  ulonglong uVar10;
  undefined1 *puVar11;
  ulonglong _MaxCount;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  longlong local_48;
  wchar_t *pwStack_40;
  char *local_38;
  char *pcStack_30;
  undefined8 local_28;
  undefined8 local_20;
  
  uVar1 = *(ushort *)(param_1 + 2);
  if (uVar1 >> 1 < 0x81) {
    uVar3 = *param_3;
    if (((*(ushort *)((longlong)param_1 + 0x12) <= uVar3) &&
        ((ulonglong)uVar1 <= uVar3 - *(ushort *)((longlong)param_1 + 0x12))) && ((uVar1 & 1) == 0))
    {
      _MaxCount = CONCAT62(0,uVar1 >> 1);
      auVar5._8_8_ = 0;
      auVar5._0_8_ = _MaxCount;
      _Var8 = SUB168(ZEXT816(2) * auVar5,0);
      if (SUB168(ZEXT816(2) * auVar5,8) != 0) {
        _Var8 = 0xffffffffffffffff;
      }
      _Src = operator_new(_Var8);
      puVar11 = auStack_68;
      if (_Src == (wchar_t *)0x0) {
        local_20 = 0;
        local_38 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
        local_28 = 0x20c;
        pcStack_30 = "VirtualMachine::VmmIoctlSetVmName";
        OnFailure((ErrorSite *)&local_38,-0x3fffff66);
        return -0x3fffff66;
      }
      uVar10 = (ulonglong)*(ushort *)((longlong)param_1 + 0x12);
      local_38 = (char *)(ulonglong)*(ushort *)(param_1 + 2);
      if ((uVar3 < uVar10) || ((char *)(uVar3 - uVar10) < local_38)) {
                    /* WARNING: Subroutine does not return */
        gsl::details::terminate();
      }
      pcStack_30 = (char *)(uVar10 + param_3[1]);
      if ((*(ushort *)(param_1 + 2) & 1) != 0) {
        local_20 = 0;
        local_38 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\util.h";
        local_28 = 0xa2;
        pcStack_30 = "CopyBytes";
        OnFailure((ErrorSite *)&local_38,-0x3fffffff);
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(5);
        puVar11 = auStack_60;
      }
      local_48 = _MaxCount * 2;
      *(undefined8 *)(puVar11 + -8) = 0x1c000963f;
      pwStack_40 = _Src;
      gsl::copy<gsl::byte_const_,_1,gsl::byte,_1>(&local_38,&local_48);
      *(undefined8 *)(puVar11 + -8) = 0x1c000964c;
      sVar9 = wcsnlen(_Src,_MaxCount);
      if (sVar9 == _MaxCount) {
        *(undefined8 *)(puVar11 + -8) = 0x1c00096a7;
        RtlFreeUnicodeString(this + 0x28);
        *(undefined4 *)(this + 0x2c) = 0;
        uVar2 = *(undefined2 *)(param_1 + 2);
        uVar6 = *param_1;
        uVar7 = param_1[1];
        *(undefined2 *)(this + 0x28) = uVar2;
        *(undefined2 *)(this + 0x2a) = uVar2;
        *(undefined8 *)(this + 0x38) = uVar6;
        *(undefined8 *)(this + 0x40) = uVar7;
        *(wchar_t **)(this + 0x30) = _Src;
        return 0;
      }
      local_20 = 0;
      local_38 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
      local_28 = 0x214;
      pcStack_30 = "VirtualMachine::VmmIoctlSetVmName";
      *(undefined8 *)(puVar11 + -8) = 0x1c0009689;
      OnFailure((ErrorSite *)&local_38,-0x3ffffff3);
      *(undefined8 *)(puVar11 + -8) = 0x1c0009695;
      ExFreePoolWithTag(_Src,0);
      return -0x3ffffff3;
    }
  }
  local_20 = 0;
  local_38 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\vm.cpp";
  local_28 = 0x205;
  pcStack_30 = "VirtualMachine::VmmIoctlSetVmName";
  OnFailure((ErrorSite *)&local_38,-0x3ffffff3);
  return -0x3ffffff3;
}



===== WakeVmm @ 1c0009734 =====

/* private: void __cdecl VirtualMachine::WakeVmm(class CompletedIrps & __ptr64) __ptr64 */

void __thiscall VirtualMachine::WakeVmm(VirtualMachine *this,CompletedIrps *param_1)

{
  CancellableIrp *this_00;
  char *pcVar1;
  bool bVar2;
  long lVar3;
  _IRP *p_Var4;
  uint uVar5;
  VMBUS_PROXY_NEXT_ACTION_OUTPUT *pVVar6;
  long local_res8 [2];
  
  this_00 = (CancellableIrp *)(this + 0x20);
  p_Var4 = CancellableIrp::Take(this_00);
  if (p_Var4 != (_IRP *)0x0) {
    pcVar1 = *(char **)(p_Var4 + 0xb8);
    if ((*pcVar1 == '\x0e') && ((*(uint *)(pcVar1 + 0x18) & 3) == 0)) {
      pVVar6 = *(VMBUS_PROXY_NEXT_ACTION_OUTPUT **)(p_Var4 + 0x18);
      uVar5 = *(uint *)(pcVar1 + 8);
      if ((pVVar6 == (VMBUS_PROXY_NEXT_ACTION_OUTPUT *)0x0) && (uVar5 != 0)) goto LAB_1c00097e9;
    }
    else {
      uVar5 = 0;
      pVVar6 = (VMBUS_PROXY_NEXT_ACTION_OUTPUT *)0x0;
    }
    if (uVar5 < 0xd0) {
LAB_1c00097e9:
                    /* WARNING: Subroutine does not return */
      gsl::details::terminate();
    }
    local_res8[0] = 0;
    bVar2 = FillNextActionIrp(this,pVVar6,local_res8);
    if (bVar2) {
      lVar3 = local_res8[0];
      if (-1 < local_res8[0]) {
        *(undefined8 *)(p_Var4 + 0x38) = 0xd0;
      }
    }
    else {
      lVar3 = CancellableIrp::Set(this_00,p_Var4);
      if (-1 < lVar3) {
        return;
      }
    }
    CompletedIrps::Push(param_1,p_Var4,lVar3);
  }
  return;
}



===== ~WorkItem @ 1c00097f8 =====

/* public: __cdecl WorkItem::~WorkItem(void) __ptr64 */

void __thiscall WorkItem::~WorkItem(WorkItem *this)

{
  WorkQueue *pWVar1;
  code *pcVar2;
  undefined1 *puVar3;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  puVar3 = auStack_48;
  if (*(WorkItem **)this != this) {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\workqueue.cpp";
    local_18 = 0xe;
    local_20 = "WorkItem::~WorkItem";
    OnFailure((ErrorSite *)&local_28,-0x3fffffff);
    puVar3 = auStack_40;
    this = (WorkItem *)0x5;
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)();
  }
  pWVar1 = *(WorkQueue **)(this + 0x10);
  *(undefined8 *)(this + 0x10) = 0;
  if (pWVar1 != (WorkQueue *)0x0) {
    *(undefined8 *)(puVar3 + -8) = 0x1c0009852;
    WorkQueue::Dereference(pWVar1);
  }
  return;
}



===== Dereference @ 1c0009860 =====

/* public: static void __cdecl WorkQueue::Dereference(class WorkQueue * __ptr64) */

void __cdecl WorkQueue::Dereference(WorkQueue *param_1)

{
  longlong lVar1;
  code *pcVar2;
  undefined1 *puVar3;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  puVar3 = auStack_48;
  LOCK();
  lVar1 = *(longlong *)param_1;
  *(longlong *)param_1 = *(longlong *)param_1 + -1;
  UNLOCK();
  if (lVar1 < 2) {
    if (lVar1 == 1) {
      if (param_1 != (WorkQueue *)0x0) {
        if (*(WorkQueue **)(param_1 + 0x10) != param_1 + 0x10) {
          local_10 = 0;
          local_28 = "onecore\\vm\\dv\\vmbus\\proxy\\sys\\util.h";
          local_18 = 0x40;
          local_20 = "ListHead::~ListHead";
          OnFailure((ErrorSite *)&local_28,-0x3fffffff);
          puVar3 = auStack_40;
          pcVar2 = (code *)swi(0x29);
          (*pcVar2)(5);
        }
        *(undefined8 *)(puVar3 + -8) = 0x1c00098d5;
        ExFreePoolWithTag();
      }
    }
    else {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(0xe);
    }
  }
  return;
}



===== Run @ 1c00098e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl WorkQueue::Run(void) __ptr64 */

long __thiscall WorkQueue::Run(WorkQueue *this)

{
  WorkQueue *pWVar1;
  WorkQueue *pWVar2;
  longlong lVar3;
  code *pcVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  bool bVar7;
  char cVar8;
  undefined1 uVar9;
  int iVar10;
  long lVar11;
  WorkQueue *pWVar12;
  undefined4 uStack_4f;
  undefined2 uStack_4b;
  undefined1 uStack_49;
  WorkQueue *local_48;
  char *pcStack_40;
  undefined8 local_38;
  undefined8 local_30;
  
  cVar8 = PsIsThreadTerminating(SystemReserved1[0xf]);
  if (cVar8 == '\0') {
    pWVar1 = this + 8;
    pWVar2 = this + 0x10;
    do {
      KeEnterCriticalRegion();
      bVar7 = false;
      uVar9 = KeAcquireSpinLockRaiseToDpc(pWVar1);
      pWVar12 = *(WorkQueue **)pWVar2;
      if (pWVar12 == pWVar2) {
        pWVar12 = (WorkQueue *)0x0;
        if (this[0x38] == (WorkQueue)0x0) {
          bVar7 = true;
        }
        else {
          KeResetEvent(this + 0x20);
        }
      }
      else {
        if ((*(WorkQueue **)(pWVar12 + 8) != pWVar2) ||
           (lVar3 = *(longlong *)pWVar12, *(WorkQueue **)(lVar3 + 8) != pWVar12)) {
          pcVar4 = (code *)swi(0x29);
          (*pcVar4)(3);
          pcVar4 = (code *)swi(3);
          lVar11 = (*pcVar4)();
          return lVar11;
        }
        *(longlong *)pWVar2 = lVar3;
        *(WorkQueue **)(lVar3 + 8) = pWVar2;
      }
      if (pWVar1 != (WorkQueue *)0x0) {
        pcStack_40 = (char *)CONCAT17(uStack_49,CONCAT25(uStack_4b,CONCAT41(uStack_4f,uVar9)));
        local_48 = pWVar1;
        wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_48);
      }
      if (pWVar12 == (WorkQueue *)0x0) {
        KeLeaveCriticalRegion();
        if (bVar7) {
          return 0;
        }
        iVar10 = KeWaitForSingleObject(this + 0x20,6,1,1,0);
        if (iVar10 == 0xc0) {
          return 0xc0;
        }
      }
      else {
        pcVar4 = *(code **)(pWVar12 + 0x18);
        uVar5 = *(undefined8 *)(pWVar12 + 0x20);
        *(undefined8 *)(pWVar12 + 0x18) = 0;
        *(undefined8 *)(pWVar12 + 0x20) = 0;
        uVar6 = *(undefined8 *)(pWVar12 + 0x28);
        *(WorkQueue **)(pWVar12 + 8) = pWVar12;
        *(WorkQueue **)pWVar12 = pWVar12;
        ObfReferenceObject(uVar6);
        (*pcVar4)(uVar5);
        ObfDereferenceObject(uVar6);
        cVar8 = KeAreAllApcsDisabled();
        if (cVar8 != '\0') {
          local_38 = 0x66;
          local_48 = (WorkQueue *)0x1c000ca00;
          local_30 = 0;
          pcStack_40 = "WorkQueue::Run";
          OnFailure((ErrorSite *)&local_48,-0x3fffffff);
          pcVar4 = (code *)swi(0x29);
          (*pcVar4)(5);
          return 0xc0;
        }
        KeLeaveCriticalRegion();
      }
      cVar8 = PsIsThreadTerminating(SystemReserved1[0xf]);
    } while (cVar8 == '\0');
  }
  return -0x3fffffb5;
}



===== Rundown @ 1c0009b04 =====

/* public: void __cdecl WorkQueue::Rundown(void) __ptr64 */

void __thiscall WorkQueue::Rundown(WorkQueue *this)

{
  WorkQueue *pWVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  WorkQueue *local_18;
  undefined1 uStack_10;
  undefined4 uStack_f;
  undefined2 uStack_b;
  undefined1 uStack_9;
  
  pWVar1 = this + 8;
  uVar3 = KeAcquireSpinLockRaiseToDpc(pWVar1);
  uVar2 = _uStack_10;
  _uStack_10 = CONCAT41(uStack_f,uVar3);
  uStack_b = SUB82(uVar2,5);
  uStack_9 = SUB81(uVar2,7);
  this[0x38] = (WorkQueue)0x0;
  local_18 = pWVar1;
  KeSetEvent(this + 0x20,0,0);
  if (pWVar1 != (WorkQueue *)0x0) {
    wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_18);
  }
  return;
}



===== WdmlibRtlInitUnicodeStringEx @ 1c0009b8c =====

undefined8 WdmlibRtlInitUnicodeStringEx(short *param_1,longlong param_2)

{
  short sVar1;
  ulonglong uVar2;
  short sVar3;
  
  sVar3 = 0;
  if (param_2 == 0) {
    param_2 = 0;
    sVar1 = 0;
  }
  else {
    uVar2 = 0xffffffffffffffff;
    do {
      uVar2 = uVar2 + 1;
    } while (*(short *)(param_2 + uVar2 * 2) != 0);
    if (0x7ffe < uVar2) {
      return 0xc0000106;
    }
    sVar1 = (short)uVar2 * 2;
    sVar3 = sVar1 + 2;
  }
  *param_1 = sVar1;
  param_1[1] = sVar3;
  *(longlong *)(param_1 + 4) = param_2;
  return 0;
}



===== ReadFromUser @ 1c0009bd8 =====

/* long __cdecl ReadFromUser(class gsl::span<enum gsl::byte,-1>,void const volatile * __ptr64) */

long __cdecl ReadFromUser(size_t *param_1,void *param_2)

{
  if (*(void **)MmUserProbeAddress_exref <= param_2) {
    param_2 = *(void **)MmUserProbeAddress_exref;
  }
  RtlpCopyDeviceMemory((void *)param_1[1],param_2,*param_1);
  return 0;
}



===== WriteToUser @ 1c0009c44 =====

/* long __cdecl WriteToUser(void volatile * __ptr64,class gsl::span<enum gsl::byte const ,-1>) */

long __cdecl WriteToUser(void *param_1,size_t *param_2)

{
  if (*(void **)MmUserProbeAddress_exref <= param_1) {
    param_1 = *(void **)MmUserProbeAddress_exref;
  }
  RtlpCopyDeviceMemory(param_1,(void *)param_2[1],*param_2);
  return 0;
}



===== VmbusRdmaCopyChildPages @ 1c0009cb0 =====

/* WARNING: Type propagation algorithm not settling */

long VmbusRdmaCopyChildPages(longlong param_1)

{
  longlong lVar1;
  bool bVar2;
  long lVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  uint uVar8;
  ulonglong uVar9;
  char *pcVar10;
  uint local_res8;
  char *local_res10;
  char *local_res18;
  char *local_res20;
  char *local_98;
  char *local_68;
  char *pcStack_60;
  undefined8 local_58;
  undefined8 local_50;
  
  pcVar10 = (char *)0x0;
  bVar2 = false;
  local_res20 = (char *)0x0;
  uVar9 = 0;
  uVar8 = 0;
  local_res8 = 0;
  pcVar7 = (char *)**(longlong **)(param_1 + 0x20);
  pcVar5 = (char *)(*(longlong **)(param_1 + 0x20))[1];
  if (*(int *)(param_1 + 0x28) != 0) {
    local_res10 = pcVar7;
    local_res18 = pcVar5;
    do {
      uVar8 = (uint)uVar9;
      if (bVar2) break;
      lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x18) + uVar9 * 8);
      if ((*(byte *)(lVar1 + 10) & 5) == 0) {
        pcVar4 = (char *)MmMapLockedPagesSpecifyCache(lVar1,0,1,0,0,0x40000010);
        pcVar5 = local_res18;
        pcVar7 = local_res10;
      }
      else {
        pcVar4 = *(char **)(lVar1 + 0x18);
      }
      if (pcVar4 == (char *)0x0) {
        local_58 = 0xd1;
        lVar3 = -0x3fffff66;
        goto LAB_1c0009f42;
      }
      pcVar6 = (char *)(ulonglong)*(uint *)(lVar1 + 0x28);
      if (pcVar6 != (char *)0x0) {
        do {
          if (bVar2) break;
          if (pcVar6 < pcVar5) {
            pcVar5 = pcVar6;
          }
          if (*(char *)(param_1 + 0x30) == '\0') {
            if (pcVar5 == (char *)0xffffffffffffffff) {
              if (pcVar6 == (char *)0xffffffffffffffff) goto LAB_1c0009f80;
              pcVar10 = pcVar6;
            }
            else {
              if (pcVar6 < pcVar5) goto LAB_1c0009f80;
              pcVar10 = pcVar5;
            }
            if ((pcVar4 == (char *)0x0) && (pcVar10 != (char *)0x0)) goto LAB_1c0009f80;
            local_68 = pcVar10;
            pcStack_60 = pcVar4;
            lVar3 = WriteToUser(pcVar7,&local_68);
            if (lVar3 < 0) {
              local_58 = 0xde;
              goto LAB_1c0009dd8;
            }
          }
          else {
            if (pcVar5 == (char *)0xffffffffffffffff) {
              local_98 = pcVar6;
              if (pcVar6 == (char *)0xffffffffffffffff) goto LAB_1c0009f80;
            }
            else {
              if (pcVar6 < pcVar5) goto LAB_1c0009f80;
              local_98 = pcVar5;
            }
            local_68 = local_98;
            pcStack_60 = pcVar4;
            lVar3 = ReadFromUser(&local_68,pcVar7);
            if (lVar3 < 0) {
              local_58 = 0xda;
LAB_1c0009dd8:
              local_50 = 0;
              local_68 = "onecore\\vm\\dv\\vmbus\\common\\vmbuscommon.cpp";
              pcStack_60 = "VmbusRdmaCopyChildPages";
              OnFailure((ErrorSite *)&local_68,lVar3);
              return lVar3;
            }
          }
          if ((pcVar6 < pcVar5) ||
             (pcVar6 = pcVar6 + -(longlong)pcVar5, pcVar6 == (char *)0xffffffffffffffff)) {
LAB_1c0009f80:
                    /* WARNING: Subroutine does not return */
            gsl::details::terminate();
          }
          pcVar4 = pcVar4 + (longlong)pcVar5;
          pcVar10 = local_res20 + (longlong)pcVar5;
          if (pcVar5 == local_res18) {
            local_res8 = local_res8 + 1;
            if (local_res8 < *(uint *)(param_1 + 0x2c)) {
              local_res18 = *(char **)(*(longlong *)(param_1 + 0x20) + 8 +
                                      (ulonglong)local_res8 * 0x10);
              local_res10 = *(char **)(*(longlong *)(param_1 + 0x20) + (ulonglong)local_res8 * 0x10)
              ;
            }
            else {
              bVar2 = true;
            }
          }
          else {
            local_res18 = local_res18 + -(longlong)pcVar5;
            local_res10 = local_res10 + (longlong)pcVar5;
          }
          pcVar5 = local_res18;
          pcVar7 = local_res10;
          local_res20 = pcVar10;
          local_68 = pcVar6;
          pcStack_60 = pcVar4;
        } while (pcVar6 != (char *)0x0);
      }
      uVar8 = uVar8 + 1;
      uVar9 = (ulonglong)uVar8;
    } while (uVar8 < *(uint *)(param_1 + 0x28));
  }
  *(char **)(*(longlong *)(param_1 + 8) + 0x38) = pcVar10;
  if (*(char *)(param_1 + 0x30) == '\0') {
    if (uVar8 < *(uint *)(param_1 + 0x28)) goto LAB_1c0009f71;
  }
  else if (!bVar2) {
LAB_1c0009f71:
    local_58 = 0x103;
    lVar3 = -0x7ffffffb;
LAB_1c0009f42:
    local_50 = 0;
    local_68 = "onecore\\vm\\dv\\vmbus\\common\\vmbuscommon.cpp";
    pcStack_60 = "VmbusRdmaCopyChildPages";
    OnFailure((ErrorSite *)&local_68,lVar3);
    return lVar3;
  }
  return 0;
}



===== PkParseGpaRanges @ 1c0009f8c =====

undefined8 PkParseGpaRanges(uint *param_1,uint param_2,uint param_3,undefined8 *param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  
  uVar3 = 0;
  uVar8 = 0;
  if (param_3 != 0) {
    puVar7 = param_4;
    puVar9 = param_1;
    uVar10 = 0;
    do {
      if (((int)uVar3 < 0) ||
         (uVar6 = ((ulonglong)param_2 - (longlong)puVar9) + (longlong)param_1, uVar6 < 8)) {
        return 0xc0000004;
      }
      if ((*puVar9 == 0) || (0xfff < puVar9[1])) {
        return 0xc000000d;
      }
      uVar5 = (ulonglong)(puVar9[1] & 0xfff) + 0xfff + (ulonglong)*puVar9 >> 0xc;
      if (0xfffff < (uint)uVar5) {
        return 0xc000000d;
      }
      uVar2 = uVar10 + (uint)uVar5;
      if (uVar2 < uVar10) {
        return 0xc0000095;
      }
      if (uVar6 < uVar5 * 8 + 8) {
        return 0xc0000004;
      }
      if (param_4 != (undefined8 *)0x0) {
        *puVar7 = puVar9;
      }
      puVar1 = puVar9 + uVar5 * 2 + 2;
      puVar4 = (uint *)0xffffffffffffffff;
      if (puVar9 <= puVar1) {
        puVar4 = puVar1;
      }
      uVar8 = uVar8 + 1;
      uVar3 = -(uint)(puVar1 < puVar9) & 0xc0000095;
      puVar7 = puVar7 + 1;
      puVar9 = puVar4;
      uVar10 = uVar2;
    } while (uVar8 < param_3);
  }
  return 0;
}



===== _guard_check_icall @ 1c000a0a0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c000a0b8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000a0dc =====

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



===== __GSHandlerCheck_SEH @ 1c000a144 =====

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



===== __security_check_cookie @ 1c000a1e0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== RtlpCopyDeviceMemory @ 1c000a210 =====

void * __cdecl RtlpCopyDeviceMemory(void *_Dst,void *_Src,size_t _Size)

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



===== RtlMoveVolatileMemory @ 1c000a220 =====

void * __cdecl RtlMoveVolatileMemory(void *_Dst,void *_Src,size_t _Size)

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



===== RtlSetVolatileMemory @ 1c000a230 =====

void * __cdecl RtlSetVolatileMemory(void *_Dst,int _Val,size_t _Size)

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



===== _guard_dispatch_icall @ 1c000a260 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c000a290 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c000a290. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c000a2c0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c000a340 =====

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



===== memset @ 1c000a640 =====

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



===== __memset_repmovs @ 1c000a780 =====

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



===== __memset_query @ 1c000a800 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c000a880 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c000a9c0 =====

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



===== __memset_spec_plain @ 1c000aa40 =====

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



===== memset$thunk$772440563353939046 @ 1c000b020 =====

void * __cdecl memset_thunk_772440563353939046(void *_Dst,int _Val,size_t _Size)

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



===== _tlgEnableCallback @ 1c0011010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

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



===== WdmlibIoCreateDeviceSecure @ 1c001108c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WdmlibIoCreateDeviceSecure(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 local_18;
  undefined8 uStack_10;
  
  if (WdmlibInitialized == '\0') {
    local_18 = 0;
    uStack_10 = 0;
    RtlInitUnicodeString(&local_18,L"IoCreateDeviceSecure");
    PfnIoCreateDeviceSecure = (code *)MmGetSystemRoutineAddress(&local_18);
    if (PfnIoCreateDeviceSecure == (code *)0x0) {
      PfnIoCreateDeviceSecure = IoDevObjCreateDeviceSecure;
    }
    RtlInitUnicodeString(&local_18,L"IoValidateDeviceIoControlAccess");
    MmGetSystemRoutineAddress(&local_18);
    WdmlibInitialized = '\x01';
  }
  (*PfnIoCreateDeviceSecure)
            (param_1,0,param_3,0x3e,0,0,&SDDL_DEVOBJ_SYS_ALL_ADM_ALL,in_stack_00000040,
             in_stack_00000048);
  return;
}



===== IoDevObjCreateDeviceSecure @ 1c0011180 =====

ulonglong IoDevObjCreateDeviceSecure
                    (ulonglong param_1,ulonglong param_2,longlong param_3,undefined4 param_4,
                    undefined4 param_5,undefined1 param_6,ushort *param_7,undefined4 *param_8,
                    undefined8 *param_9)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  longlong local_res18;
  undefined4 local_res20;
  undefined8 local_68;
  longlong lStack_60;
  undefined8 local_58;
  undefined8 local_50;
  longlong local_48;
  undefined8 local_40;
  
  puVar2 = param_9;
  local_res18 = 0;
  local_58 = 0;
  *param_9 = 0;
  param_9 = (undefined8 *)0x0;
  local_68 = 0;
  lStack_60 = 0;
  if ((param_3 == 0) && (-1 < (char)param_5)) {
    return 0xc000000d;
  }
  uVar5 = param_2;
  local_res20 = param_4;
  if ((param_8 != (undefined4 *)0x0) &&
     (uVar5 = param_1,
     uVar4 = PpRegStateReadCreateClassCreationSettings(param_8,param_1,(uint *)&local_68),
     (int)uVar4 < 0)) {
    return uVar4;
  }
  uVar6 = (uint)local_68;
  if ((local_68 & 2) == 0) {
    uVar5 = SeSddlSecurityDescriptorFromSDDL(param_7,uVar5,&local_res18);
    uVar4 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) goto LAB_1c00112e0;
    uVar6 = 2;
    local_68 = CONCAT44(local_68._4_4_,2);
    lStack_60 = local_res18;
    if (param_8 != (undefined4 *)0x0) {
      local_50 = 2;
      local_40 = 0;
      local_48 = local_res18;
      uVar5 = PpRegStateUpdateStackCreationSettings(param_8,(longlong)&local_50);
      uVar4 = uVar5 & 0xffffffff;
      if ((int)uVar5 < 0) goto LAB_1c00112e0;
    }
  }
  uVar1 = local_res20;
  if ((uVar6 & 1) != 0) {
    uVar1 = local_68._4_4_;
  }
  if ((uVar6 & 4) != 0) {
    param_5 = (undefined4)local_58;
  }
  if ((uVar6 & 8) != 0) {
    param_6 = local_58._4_1_;
  }
  uVar3 = IoCreateDevice(param_1,param_2 & 0xffffffff,param_3,uVar1,param_5,param_6,&param_9);
  uVar4 = (ulonglong)uVar3;
  if (-1 < (int)uVar3) {
    uVar5 = IopDevObjApplyPostCreationSettings(param_9,(uint *)&local_68);
    uVar4 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) {
      IoDeleteDevice(param_9);
    }
    else {
      *puVar2 = param_9;
    }
  }
LAB_1c00112e0:
  if ((uVar6 & 2) != 0) {
    ExFreePoolWithTag(lStack_60,0);
  }
  return uVar4;
}



===== IopDevObjApplyPostCreationSettings @ 1c0011314 =====

ulonglong IopDevObjApplyPostCreationSettings(undefined8 param_1,uint *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  undefined1 local_res10 [8];
  uint local_res18 [2];
  undefined8 local_res20;
  
  local_res18[0] = 0;
  local_res20 = 0;
  local_res10[0] = 0;
  if ((*param_2 & 2) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = SeUtilSecurityInfoFromSecurityDescriptor
                      (*(undefined8 *)(param_2 + 2),local_res10,local_res18);
    if (-1 < (int)uVar2) {
      uVar3 = -(uint)((local_res18[0] & 3) != 0) & 0x80000;
      uVar1 = uVar3 | 0x40000;
      if ((local_res18[0] & 4) == 0) {
        uVar1 = uVar3;
      }
      uVar3 = uVar1 | 0x1000000;
      if ((local_res18[0] & 8) == 0) {
        uVar3 = uVar1;
      }
      uVar2 = ObOpenObjectByPointer
                        (param_1,0x200,0,uVar3,*(undefined8 *)IoDeviceObjectType_exref,0,
                         &local_res20);
      if (-1 < (int)uVar2) {
        uVar1 = ZwSetSecurityObject(local_res20,local_res18[0],*(undefined8 *)(param_2 + 2));
        uVar2 = (ulonglong)uVar1;
        ZwClose(local_res20);
      }
    }
  }
  return uVar2;
}



===== SeSddlSecurityDescriptorFromSDDL @ 1c0011404 =====

ulonglong SeSddlSecurityDescriptorFromSDDL(ushort *param_1,undefined8 param_2,longlong *param_3)

{
  ushort uVar1;
  ulonglong uVar2;
  short *_Dst;
  void *_Src;
  
  uVar2 = (ulonglong)*param_1 + 2;
  if (param_1[1] == uVar2) {
    uVar1 = *param_1 >> 1;
    if ((*(short **)(param_1 + 4))[uVar1] == 0) {
      uVar2 = SepSddlSecurityDescriptorFromSDDLString(*(short **)(param_1 + 4),(uint)uVar1,param_3);
      return uVar2;
    }
  }
  _Dst = (short *)ExAllocatePoolWithTag(1,uVar2,0x73546553);
  if (_Dst == (short *)0x0) {
    *param_3 = 0;
    uVar2 = 0xc000009a;
  }
  else {
    memset(_Dst,0,(ulonglong)*param_1 + 2);
    _Src = *(void **)(param_1 + 4);
    memcpy(_Dst,_Src,(ulonglong)*param_1);
    _Dst[*param_1 >> 1] = 0;
    uVar2 = SepSddlSecurityDescriptorFromSDDLString(_Dst,(uint)_Src,param_3);
    uVar2 = uVar2 & 0xffffffff;
    ExFreePoolWithTag(_Dst,0);
  }
  return uVar2;
}



===== SepSddlAddAceToAcl @ 1c00114e4 =====

undefined8
SepSddlAddAceToAcl(longlong *param_1,uint *param_2,undefined8 param_3,undefined8 param_4,
                  undefined4 param_5,int param_6,undefined8 param_7)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  void *_Dst;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  
  pvVar2 = (void *)*param_1;
  uVar1 = *param_2;
  iVar3 = RtlLengthSid(param_7);
  uVar6 = iVar3 + 8 + uVar1;
  _Dst = pvVar2;
  if (*(ushort *)((longlong)pvVar2 + 2) < uVar6) {
    uVar5 = (iVar3 + 8) * param_6 + uVar1;
    _Dst = (void *)ExAllocatePoolWithTag(1,uVar5,0x6c416553);
    if (_Dst == (void *)0x0) {
      return 0xc000009a;
    }
    memset(_Dst,0,(ulonglong)uVar5);
    memcpy(_Dst,(void *)*param_1,(ulonglong)uVar1);
    *(short *)((longlong)_Dst + 2) = (short)uVar5;
    ExFreePoolWithTag(pvVar2,0);
    *param_1 = (longlong)_Dst;
  }
  *param_2 = uVar6;
  uVar4 = RtlAddAccessAllowedAce(_Dst,2,param_5,param_7);
  return uVar4;
}



===== SepSddlDaclFromSDDLString @ 1c00115e4 =====

int SepSddlDaclFromSDDLString
              (short *param_1,undefined8 param_2,undefined4 *param_3,longlong *param_4)

{
  int iVar1;
  longlong lVar2;
  short *psVar3;
  undefined4 uVar4;
  longlong local_res8;
  short *local_res18 [2];
  
  local_res8 = 0;
  local_res18[0] = (short *)0x0;
  *param_4 = 0;
  *param_3 = 0;
  for (; *param_1 == 0x20; param_1 = param_1 + 1) {
  }
  if ((*param_1 != 0x44) || (param_1[1] != 0x3a)) {
    return -0x3ffffff3;
  }
  uVar4 = 0x1008;
  if (param_1[2] != 0x50) {
    uVar4 = 8;
  }
  lVar2 = 4;
  if (param_1[2] != 0x50) {
    lVar2 = 2;
  }
  iVar1 = SepSddlGetAclForString
                    ((wchar_t *)(lVar2 + (longlong)(param_1 + 1)),&local_res8,local_res18);
  if (iVar1 == 0) {
    for (psVar3 = local_res18[0]; *psVar3 == 0x20; psVar3 = psVar3 + 1) {
    }
    if (*psVar3 == 0) {
      *param_4 = local_res8;
      *param_3 = uVar4;
      return 0;
    }
    iVar1 = -0x3ffffff3;
  }
  if (local_res8 != 0) {
    ExFreePoolWithTag(local_res8,0);
  }
  return iVar1;
}



===== SepSddlGetAclForString @ 1c00116d0 =====

int SepSddlGetAclForString(wchar_t *param_1,longlong *param_2,undefined8 *param_3)

{
  bool bVar1;
  bool bVar2;
  wchar_t wVar3;
  int iVar4;
  int iVar5;
  wchar_t *pwVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined2 *_Dst;
  undefined8 uVar9;
  wchar_t *pwVar10;
  ulonglong uVar11;
  short *psVar12;
  short **ppsVar13;
  undefined8 uVar14;
  uint uVar15;
  uint uVar16;
  undefined **ppuVar17;
  short *local_res8;
  uint local_res10;
  uint local_res18;
  uint local_res20 [2];
  wchar_t *local_58;
  longlong local_50 [2];
  
  *param_2 = 0;
  local_50[0] = 0;
  iVar5 = 0;
  uVar16 = 0;
  pwVar6 = wcschr(param_1,L':');
  *param_3 = pwVar6;
  if (pwVar6 == param_1) {
    return -0x3ffffff3;
  }
  if (pwVar6 == (wchar_t *)0x0) {
    lVar7 = -1;
    do {
      lVar7 = lVar7 + 1;
    } while (param_1[lVar7] != L'\0');
    pwVar6 = param_1 + lVar7;
  }
  else {
    pwVar6 = pwVar6 + -1;
  }
  *param_3 = pwVar6;
  bVar2 = false;
  bVar1 = false;
  uVar14 = 1;
  for (pwVar10 = param_1; pwVar10 < pwVar6; pwVar10 = pwVar10 + 1) {
    if (*pwVar10 == L';') {
      uVar16 = uVar16 + 1;
    }
    else {
      bVar1 = bVar2;
      if (*pwVar10 != L' ') {
        bVar2 = true;
        bVar1 = true;
      }
    }
  }
  local_res18 = uVar16 / 5;
  if ((uVar16 != local_res18 * 5) || ((uVar16 == 0 && (bVar1)))) {
    iVar5 = -0x3ffffff3;
  }
  else {
    if (local_res18 == 0) {
      puVar8 = (undefined8 *)ExAllocatePoolWithTag(1,8);
      *param_2 = (longlong)puVar8;
      if (puVar8 != (undefined8 *)0x0) {
        *puVar8 = 0x80002;
        return 0;
      }
    }
    else {
      uVar16 = local_res18 * 0x30 + 8;
      if (0xffff < uVar16) {
        uVar16 = 0xffff;
      }
      _Dst = (undefined2 *)ExAllocatePoolWithTag(1,uVar16,0x6c416553);
      *param_2 = (longlong)_Dst;
      if (_Dst != (undefined2 *)0x0) {
        local_res20[0] = 8;
        memset(_Dst,0,(ulonglong)uVar16);
        *_Dst = 2;
        _Dst[1] = (short)uVar16;
        *(undefined4 *)(_Dst + 2) = 0;
        local_res10 = 0;
        uVar16 = local_res18;
        uVar15 = 8;
        if (local_res18 != 0) {
          do {
            uVar15 = 0;
            local_res8 = (short *)((ulonglong)local_res8 & 0xffffffff00000000);
            for (; *param_1 == L' '; param_1 = param_1 + 1) {
            }
            if (*param_1 == L'(') {
              do {
                param_1 = param_1 + 1;
              } while (*param_1 == L' ');
            }
            iVar4 = _wcsnicmp(param_1,L"A",1);
            if (iVar4 != 0) {
LAB_1c0011a6b:
              iVar5 = -0x3ffffff3;
LAB_1c0011a6d:
              lVar7 = *param_2;
              goto LAB_1c0011a53;
            }
            for (pwVar6 = param_1 + 2; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
            }
            if (*pwVar6 != L';') goto LAB_1c0011a6b;
            do {
              pwVar6 = pwVar6 + 1;
              wVar3 = *pwVar6;
            } while (wVar3 == L' ');
            if (wVar3 != L';') {
              do {
                uVar11 = 0;
                while (wVar3 == L' ') {
                  pwVar6 = pwVar6 + 1;
                  wVar3 = *pwVar6;
                }
                ppuVar17 = &PTR_u_RC_1c000e040;
                do {
                  iVar4 = _wcsnicmp(pwVar6,(wchar_t *)*ppuVar17,(ulonglong)*(uint *)(ppuVar17 + 1));
                  if (iVar4 == 0) {
                    uVar15 = (uint)local_res8 | *(uint *)(&DAT_1c000e04c + uVar11 * 0x10);
                    local_res8 = (short *)CONCAT44(local_res8._4_4_,uVar15);
                    local_58 = pwVar6 + (uint)(&DAT_1c000e048)[uVar11 * 4];
                    goto LAB_1c001195d;
                  }
                  uVar16 = (int)uVar11 + 1;
                  uVar11 = (ulonglong)uVar16;
                  ppuVar17 = ppuVar17 + 2;
                } while (uVar16 < 8);
                local_58 = pwVar6;
                SepSddlParseWideStringUlong((ushort *)pwVar6,&local_58,(uint *)&local_res8);
                if (local_58 == pwVar6) goto LAB_1c0011a6b;
                uVar15 = (uint)local_res8;
LAB_1c001195d:
                wVar3 = *local_58;
                pwVar6 = local_58;
              } while (wVar3 != L';');
              uVar16 = local_res18;
            }
            pwVar6 = pwVar6 + 1;
            if (iVar5 != 0) goto LAB_1c0011a6d;
            lVar7 = 2;
            do {
              for (; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
              }
              if (*pwVar6 != L';') {
                iVar5 = -0x3ffffff3;
              }
              pwVar6 = pwVar6 + 1;
              lVar7 = lVar7 + -1;
            } while (lVar7 != 0);
            if (iVar5 != 0) goto LAB_1c0011a6d;
            for (; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
            }
            local_res8 = (short *)0x0;
            ppsVar13 = &local_res8;
            uVar9 = SepSddlGetSidForString(pwVar6,local_50,(longlong *)ppsVar13);
            iVar5 = (int)uVar9;
            if (iVar5 != 0) break;
            psVar12 = local_res8;
            if (local_res8 == (short *)0x0) {
LAB_1c00119db:
              iVar5 = -0x3fffff89;
              goto LAB_1c0011a6d;
            }
            for (; *psVar12 == 0x20; psVar12 = psVar12 + 1) {
            }
            if (*psVar12 != 0x29) goto LAB_1c00119db;
            param_1 = psVar12 + 1;
            if (local_50[0] != 0) {
              uVar9 = SepSddlAddAceToAcl(param_2,local_res20,ppsVar13,uVar14,uVar15,
                                         uVar16 - local_res10,local_50[0]);
              iVar5 = (int)uVar9;
              if (iVar5 != 0) goto LAB_1c0011a6d;
            }
            if (*param_1 == L'(') {
              param_1 = psVar12 + 2;
            }
            local_res10 = local_res10 + 1;
          } while (local_res10 < uVar16);
          uVar15 = local_res20[0];
        }
        lVar7 = *param_2;
        if (iVar5 == 0) {
          *(short *)(lVar7 + 2) = (short)uVar15;
          return 0;
        }
LAB_1c0011a53:
        ExFreePoolWithTag(lVar7,0);
        *param_2 = 0;
        return iVar5;
      }
    }
    iVar5 = -0x3fffff66;
  }
  return iVar5;
}



===== SepSddlGetSidForString @ 1c0011a98 =====

undefined8 SepSddlGetSidForString(wchar_t *param_1,undefined8 *param_2,longlong *param_3)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint *puVar5;
  uint uVar6;
  ulonglong uVar7;
  
  uVar4 = 0;
  puVar5 = &DAT_1c000e154;
  uVar7 = 0;
  do {
    iVar2 = _wcsnicmp(param_1,(wchar_t *)(&DAT_1c000e14c + uVar7 * 0x18),(ulonglong)*puVar5);
    if (iVar2 == 0) {
      iVar2 = *(int *)(&DAT_1c000e148 + uVar7 * 0x18);
      uVar6 = (&DAT_1c000e154)[uVar7 * 6];
      *param_3 = (longlong)(param_1 + uVar6);
      if (iVar2 == 1) {
        cVar1 = IoIsWdmVersionAvailable(1,CONCAT71((int7)((ulonglong)(param_1 + uVar6) >> 8),0x20));
        if (cVar1 != '\0') goto LAB_1c0011b2f;
      }
      else {
LAB_1c0011b2f:
        uVar4 = *(undefined8 *)
                 (*(longlong *)(&DAT_1c000e140 + uVar7 * 0x18) + *(longlong *)SeExports_exref);
      }
      uVar3 = 0;
      goto LAB_1c0011b44;
    }
    uVar6 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
    puVar5 = puVar5 + 6;
  } while (uVar6 < 0xe);
  uVar3 = 0xc0000073;
LAB_1c0011b44:
  *param_2 = uVar4;
  return uVar3;
}



===== SepSddlParseWideStringUlong @ 1c0011b6c =====

undefined8 SepSddlParseWideStringUlong(ushort *param_1,undefined8 *param_2,uint *param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  short sVar5;
  uint uVar6;
  int iVar7;
  ushort *puVar8;
  
  uVar1 = *param_1;
  uVar6 = (uint)uVar1;
  *param_3 = 0;
  *param_2 = param_1;
  if (uVar1 == 0x30) {
    if ((param_1[1] - 0x58 & 0xffdf) != 0) {
LAB_1c0011bef:
      iVar7 = 10;
      uVar4 = 0;
      puVar8 = param_1;
      goto LAB_1c0011bcd;
    }
    param_1 = param_1 + 2;
    uVar6 = (uint)*param_1;
  }
  else if ((ushort)(uVar1 - 0x30) < 10) goto LAB_1c0011bef;
  iVar7 = 0x10;
  puVar8 = param_1;
  uVar4 = 0;
  if ((short)uVar6 == 0) {
    return 0;
  }
LAB_1c0011bcd:
  do {
    sVar5 = (short)uVar6;
    if ((ushort)(sVar5 - 0x30U) < 10) {
      iVar2 = uVar6 - 0x30;
    }
    else {
      if (iVar7 != 0x10) break;
      if ((ushort)(sVar5 - 0x41U) < 6) {
        iVar2 = uVar6 - 0x37;
      }
      else {
        if (5 < (ushort)(sVar5 - 0x61U)) break;
        iVar2 = uVar6 - 0x57;
      }
    }
    uVar3 = iVar7 * uVar4 + iVar2;
    if (uVar3 < uVar4) {
      return 0;
    }
    param_1 = param_1 + 1;
    uVar6 = (uint)*param_1;
    uVar4 = uVar3;
  } while (*param_1 != 0);
  if (param_1 == puVar8) {
    return 0;
  }
  *param_2 = param_1;
  *param_3 = uVar4;
  return 1;
}



===== SepSddlSecurityDescriptorFromSDDLString @ 1c0011c78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong SepSddlSecurityDescriptorFromSDDLString(short *param_1,uint param_2,longlong *param_3)

{
  ushort uVar1;
  uint uVar2;
  code *pcVar3;
  ulonglong uVar4;
  void *_Dst;
  wchar_t *pwVar5;
  uint local_res10 [4];
  undefined4 local_res20 [2];
  longlong local_58 [3];
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  
  pwVar5 = L"SeConvertStringSecurityDescriptorToSecurityDescriptor";
  local_58[1] = 0;
  local_58[2] = 0;
  local_res10[0] = param_2;
  RtlInitUnicodeString(local_58 + 1);
  pcVar3 = (code *)MmGetSystemRoutineAddress(local_58 + 1);
  if (pcVar3 != (code *)0x0) {
    uVar4 = (*pcVar3)(param_1,1,param_3);
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    *(ushort *)(*param_3 + 2) = *(ushort *)(*param_3 + 2) | 8;
    return uVar4;
  }
  local_res20[0] = 0;
  local_res10[0] = 0;
  local_58[0] = 0;
  _Dst = (void *)0x0;
  *param_3 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_20 = 0;
  local_30 = 0;
  uStack_28 = 0;
  uVar2 = SepSddlDaclFromSDDLString(param_1,pwVar5,local_res20,local_58);
  if (-1 < (int)uVar2) {
    RtlCreateSecurityDescriptor(&local_40,1);
    RtlSetDaclSecurityDescriptor(&local_40,1,local_58[0],0);
    uVar1 = local_40._2_2_ | (ushort)local_res20[0];
    local_40._0_4_ = CONCAT22(uVar1,(undefined2)local_40);
    RtlAbsoluteToSelfRelativeSD(&local_40,0,local_res10);
    _Dst = (void *)ExAllocatePoolWithTag(1,local_res10[0],0x64536553);
    if (_Dst == (void *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      memset(_Dst,0,(ulonglong)local_res10[0]);
      uVar2 = RtlAbsoluteToSelfRelativeSD(&local_40,_Dst,local_res10);
      if (-1 < (int)uVar2) {
        ExFreePoolWithTag(local_58[0],0);
        *param_3 = (longlong)_Dst;
        goto LAB_1c0011dbd;
      }
    }
  }
  if (local_58[0] != 0) {
    ExFreePoolWithTag(local_58[0],0);
  }
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
LAB_1c0011dbd:
  return (ulonglong)uVar2;
}



===== PiRegStateOpenClassKey @ 1c0011e1c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PiRegStateOpenClassKey
                    (undefined4 *param_1,undefined8 param_2,int param_3,undefined4 *param_4,
                    undefined8 *param_5)

{
  undefined8 uVar1;
  uint uVar2;
  ulonglong uVar3;
  wchar_t *pwVar4;
  undefined4 uVar5;
  undefined1 auStackY_128 [32];
  undefined4 local_b8;
  int local_b4;
  undefined8 local_b0;
  undefined8 local_a8 [2];
  wchar_t local_98 [38];
  undefined2 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  local_b0 = 0;
  local_a8[0] = 0;
  *param_5 = 0;
  local_b8 = 0;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  local_b4 = param_3;
  uVar3 = CmRegUtilOpenExistingWstrKey(0,0x1c000cca0,0x20019,&local_b0);
  if (-1 < (int)uVar3) {
    uVar5 = *param_1;
    pwVar4 = L"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}";
    _snwprintf(local_98,0x27,L"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}");
    uVar1 = local_b0;
    local_4c = 0;
    if (local_b4 == 0) {
      uVar2 = CmRegUtilOpenExistingWstrKey(local_b0,(longlong)local_98,0xf003f,local_a8);
      uVar5 = 2;
    }
    else {
      uVar3 = CmRegUtilCreateWstrKey(local_b0,(longlong)local_98,pwVar4,uVar5,0,&local_b8,local_a8);
      uVar2 = (uint)uVar3;
      uVar5 = local_b8;
    }
    uVar3 = (ulonglong)uVar2;
    ZwClose(uVar1);
    if ((-1 < (int)uVar2) && (*param_5 = local_a8[0], param_4 != (undefined4 *)0x0)) {
      *param_4 = uVar5;
    }
  }
  return uVar3;
}



===== PiRegStateReadStackCreationSettingsFromKey @ 1c0011fb8 =====

ulonglong PiRegStateReadStackCreationSettingsFromKey
                    (undefined8 param_1,uint *param_2,uint *param_3,undefined8 param_4)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  char local_res10 [8];
  uint local_res18 [2];
  longlong local_res20;
  longlong local_58;
  ushort local_50 [12];
  
  param_2[0] = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  local_res20 = 0;
  local_res18[0] = 0;
  local_res10[0] = '\0';
  local_58 = 0;
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  uVar2 = WdmlibRtlInitUnicodeStringEx((short *)local_50,0x1c000cc20);
  uVar1 = (uint)uVar2;
  lVar4 = 0;
  if (((int)uVar1 < 0) ||
     (uVar1 = CmRegUtilUcValueGetFullBuffer(param_1,local_50,param_3,param_4,&local_58),
     lVar4 = local_58, (int)uVar1 < 0)) {
    uVar5 = (ulonglong)uVar1;
    if (uVar1 == 0xc0000034) {
      uVar5 = 0;
    }
  }
  else {
    param_3 = (uint *)0x1;
    uVar1 = SeCaptureSecurityDescriptor
                      ((ulonglong)*(uint *)(local_58 + 8) + local_58,0,1,1,&local_res20);
    uVar5 = (ulonglong)uVar1;
  }
  if (lVar4 != 0) {
    ExFreePoolWithTag(lVar4,0);
  }
  if (-1 < (int)uVar5) {
    if (local_res20 != 0) {
      param_3 = local_res18;
      uVar3 = SeUtilSecurityInfoFromSecurityDescriptor(local_res20,local_res10,param_3);
      uVar5 = uVar3 & 0xffffffff;
      if ((int)uVar3 < 0) goto LAB_1c0012137;
      if (local_res10[0] == '\0') {
        *param_2 = *param_2 | 2;
        *(longlong *)(param_2 + 2) = local_res20;
      }
      else {
        ExFreePoolWithTag(local_res20,0);
      }
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x1c000cc38,param_3,param_2 + 1);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_1c0012137;
    }
    else {
      *param_2 = *param_2 | 1;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x1c000cc50,param_3,param_2 + 4);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_1c0012137;
    }
    else {
      *param_2 = *param_2 | 4;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x1c000cc80,param_3,param_2 + 5);
    uVar5 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      *param_2 = *param_2 | 8;
      return uVar5;
    }
    if ((int)uVar3 == -0x3fffffcc) {
      return 0;
    }
  }
LAB_1c0012137:
  if (*(longlong *)(param_2 + 2) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 2),0);
  }
  param_2[0] = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  return uVar5;
}



===== PpRegStateReadCreateClassCreationSettings @ 1c001217c =====

ulonglong PpRegStateReadCreateClassCreationSettings
                    (undefined4 *param_1,longlong param_2,uint *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  uint *puVar5;
  undefined8 *puVar6;
  ushort *puVar7;
  int local_res18 [2];
  undefined8 local_res20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  *param_3 = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  param_3[1] = 0;
  param_3[4] = 0;
  param_3[5] = 0;
  local_res18[0] = 0;
  local_res20 = 0;
  local_18 = 0;
  uVar2 = PiRegStateOpenClassKey(param_1,param_2,1,local_res18,&local_res20);
  uVar4 = local_res20;
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  if (local_res18[0] == 2) {
    puVar6 = &local_18;
    puVar5 = (uint *)0x20019;
    uVar1 = CmRegUtilOpenExistingWstrKey(local_res20,0x1c000cbc0,0x20019,puVar6);
    ZwClose(local_res20);
    if ((int)uVar1 < 0) {
      if (uVar1 == 0xc0000034) {
        return 0;
      }
      return (ulonglong)uVar1;
    }
    uVar2 = PiRegStateReadStackCreationSettingsFromKey(local_18,param_3,puVar5,puVar6);
    uVar2 = uVar2 & 0xffffffff;
    uVar4 = local_18;
  }
  else {
    puVar7 = (ushort *)(*(longlong *)(param_2 + 0x30) + 0x18);
    if (puVar7 == (ushort *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      local_18 = 0;
      uStack_10 = 0;
      uVar3 = WdmlibRtlInitUnicodeStringEx((short *)&local_18,0x1c000cbd8);
      uVar2 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        uVar1 = CmRegUtilUcValueSetUcString(uVar4,&local_18,puVar7);
        uVar2 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          local_res18[0] = 0x31;
          uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x1c000cbe8,(longlong)local_res18);
          uVar2 = (ulonglong)uVar1;
          if (-1 < (int)uVar1) {
            uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x1c000cc08,(longlong)local_res18);
            uVar2 = (ulonglong)uVar1;
          }
        }
      }
    }
  }
  ZwClose(uVar4);
  return uVar2;
}



===== PpRegStateUpdateStackCreationSettings @ 1c00122e0 =====

ulonglong PpRegStateUpdateStackCreationSettings(undefined4 *param_1,longlong param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined *puVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined *local_res18;
  undefined8 local_res20;
  undefined8 local_38;
  short local_30 [12];
  
  uVar8 = 0;
  local_res18 = (undefined *)0x0;
  uVar7 = 0;
  local_38 = 0;
  local_res20 = 0;
  uVar4 = PiRegStateOpenClassKey(param_1,param_2,0,(undefined4 *)0x0,&local_res20);
  uVar2 = (undefined4)uVar8;
  if (-1 < (int)uVar4) {
    puVar6 = &PiRegStateSysAllInherittedSecurityDescriptor;
    if (PiRegStateDiscriptor == 0) {
      uVar8 = CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
      uVar2 = (undefined4)uVar8;
      uVar7 = 1;
      iVar1 = SeCaptureSecurityDescriptor
                        (&PiRegStateSysAllInherittedSecurityDescriptor,0,1,uVar8,&local_res18);
      if (iVar1 < 0) {
        PiRegStateDiscriptor = 2;
      }
      else {
        PiRegStateDiscriptor = 1;
        ExFreePoolWithTag(local_res18,0);
      }
    }
    if (PiRegStateDiscriptor != 1) {
      puVar6 = (undefined *)0x0;
    }
    local_res18 = puVar6;
    uVar5 = CmRegUtilCreateWstrKey
                      (local_res20,0x1c000cbc0,uVar7,uVar2,puVar6,(undefined4 *)0x0,&local_38);
    uVar4 = uVar5 & 0xffffffff;
    ZwClose(local_res20);
    if (-1 < (int)uVar5) {
      uVar2 = RtlLengthSecurityDescriptor(*(undefined8 *)(param_2 + 8));
      uVar7 = *(undefined8 *)(param_2 + 8);
      local_30[0] = 0;
      local_30[1] = 0;
      local_30[2] = 0;
      local_30[3] = 0;
      local_30[4] = 0;
      local_30[5] = 0;
      local_30[6] = 0;
      local_30[7] = 0;
      uVar5 = WdmlibRtlInitUnicodeStringEx(local_30,0x1c000cc20);
      uVar4 = uVar5 & 0xffffffff;
      if (-1 < (int)uVar5) {
        uVar3 = ZwSetValueKey(local_38,local_30,0,3,uVar7,uVar2);
        uVar4 = (ulonglong)uVar3;
      }
      ZwClose(local_38);
    }
  }
  return uVar4;
}



===== SeUtilSecurityInfoFromSecurityDescriptor @ 1c0012448 =====

undefined8
SeUtilSecurityInfoFromSecurityDescriptor(undefined8 param_1,undefined1 *param_2,uint *param_3)

{
  undefined8 uVar1;
  uint uVar2;
  undefined1 local_res10 [8];
  char local_res20 [8];
  longlong local_28 [2];
  
  local_28[0] = 0;
  local_28[1] = 0;
  *param_3 = 0;
  *param_2 = 0;
  local_res10[0] = 0;
  local_res20[0] = '\0';
  uVar1 = RtlGetOwnerSecurityDescriptor(param_1,local_28,local_res10);
  if (-1 < (int)uVar1) {
    uVar2 = (uint)(local_28[0] != 0);
    uVar1 = RtlGetGroupSecurityDescriptor(param_1,local_28,local_res10);
    if (-1 < (int)uVar1) {
      if (local_28[0] != 0) {
        uVar2 = uVar2 | 2;
      }
      uVar1 = RtlGetSaclSecurityDescriptor(param_1,local_res20,local_28 + 1,local_res10);
      if (-1 < (int)uVar1) {
        if (local_res20[0] != '\0') {
          uVar2 = uVar2 | 8;
        }
        uVar1 = RtlGetDaclSecurityDescriptor(param_1,local_res20,local_28 + 1,local_res10);
        if (-1 < (int)uVar1) {
          if (local_res20[0] != '\0') {
            uVar2 = uVar2 | 4;
          }
          *param_2 = local_res10[0];
          uVar1 = 0;
          *param_3 = uVar2;
        }
      }
    }
  }
  return uVar1;
}



===== CmRegUtilCreateWstrKey @ 1c0012544 =====

ulonglong CmRegUtilCreateWstrKey
                    (undefined8 param_1,longlong param_2,undefined8 param_3,undefined4 param_4,
                    undefined8 param_5,undefined4 *param_6,undefined8 *param_7)

{
  uint uVar1;
  ulonglong uVar2;
  undefined4 local_res20 [2];
  undefined8 local_58;
  short local_50 [8];
  undefined8 local_40;
  undefined8 local_38;
  short *local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined8 local_18;
  
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  local_res20[0] = param_4;
  uVar2 = WdmlibRtlInitUnicodeStringEx(local_50,param_2);
  if (-1 < (int)uVar2) {
    local_24 = 0;
    local_30 = local_50;
    local_res20[0] = 0;
    local_58 = 0;
    local_18 = 0;
    local_20 = param_5;
    local_40 = 0x30;
    local_28 = 0x240;
    local_38 = param_1;
    uVar1 = ZwCreateKey(&local_58,0xf003f,&local_40,0,0,0,local_res20);
    uVar2 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      local_58 = 0;
      local_res20[0] = 0;
    }
    *param_7 = local_58;
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = local_res20[0];
    }
  }
  return uVar2;
}



===== CmRegUtilOpenExistingWstrKey @ 1c0012614 =====

void CmRegUtilOpenExistingWstrKey
               (undefined8 param_1,longlong param_2,uint param_3,undefined8 *param_4)

{
  int iVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 local_58;
  short local_50 [8];
  undefined8 local_40;
  undefined8 local_38;
  short *local_30;
  undefined4 local_28;
  undefined4 local_24;
  
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  uVar3 = (ulonglong)param_3;
  uVar2 = WdmlibRtlInitUnicodeStringEx(local_50,param_2);
  if (-1 < (int)uVar2) {
    local_24 = 0;
    local_30 = local_50;
    local_58 = 0;
    *param_4 = 0;
    local_40 = 0x30;
    local_28 = 0x240;
    local_38 = param_1;
    iVar1 = ZwOpenKey(&local_58,uVar3 & 0xffffffff,&local_40);
    if (-1 < iVar1) {
      *param_4 = local_58;
    }
  }
  return;
}



===== CmRegUtilUcValueGetFullBuffer @ 1c00126a8 =====

int CmRegUtilUcValueGetFullBuffer
              (undefined8 param_1,ushort *param_2,undefined8 param_3,undefined8 param_4,
              undefined8 *param_5)

{
  int iVar1;
  void *_Dst;
  uint uVar2;
  uint local_res20 [2];
  
  local_res20[0] = 0;
  uVar2 = *param_2 + 0x1f & 0xfffffff8;
  *param_5 = 0;
  _Dst = (void *)ExAllocatePoolWithTag(0x200,uVar2,0x62527050);
  if (_Dst == (void *)0x0) {
    return -0x3fffff66;
  }
  memset(_Dst,0,(ulonglong)uVar2);
  iVar1 = ZwQueryValueKey(param_1,param_2,1,_Dst,uVar2,local_res20);
  if (iVar1 < 0) {
    ExFreePoolWithTag(_Dst,0);
    if ((iVar1 != -0x7ffffffb) && (iVar1 != -0x3fffffdd)) {
      return iVar1;
    }
    _Dst = (void *)ExAllocatePoolWithTag(0x200,local_res20[0],0x62527050);
    if (_Dst == (void *)0x0) {
      return -0x3fffff66;
    }
    memset(_Dst,0,(ulonglong)local_res20[0]);
    iVar1 = ZwQueryValueKey(param_1,param_2,1,_Dst,local_res20[0],local_res20);
    if (iVar1 < 0) goto LAB_1c00127e0;
  }
  if (*(int *)((longlong)_Dst + 4) == 3) {
    *param_5 = _Dst;
    return 0;
  }
  iVar1 = -0x3fffffdc;
LAB_1c00127e0:
  ExFreePoolWithTag(_Dst,0);
  return iVar1;
}



===== CmRegUtilUcValueSetUcString @ 1c0012824 =====

undefined4 CmRegUtilUcValueSetUcString(undefined8 param_1,undefined8 param_2,ushort *param_3)

{
  size_t _Size;
  ushort uVar1;
  undefined4 uVar2;
  ushort local_28;
  short local_26;
  undefined4 local_24;
  void *local_20;
  
  uVar1 = *param_3;
  local_24 = 0;
  if ((ulonglong)param_3[1] - (ulonglong)uVar1 < 2) {
    _Size = (ulonglong)uVar1 + 2;
    local_26 = uVar1 + 2;
    local_20 = (void *)ExAllocatePoolWithTag(1,_Size,0x63557050);
    if (local_20 == (void *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      memset(local_20,0,_Size);
      local_28 = *param_3;
      memcpy(local_20,*(void **)(param_3 + 4),(ulonglong)local_28);
      *(undefined2 *)((longlong)local_20 + (ulonglong)(local_28 >> 1) * 2) = 0;
      uVar2 = ZwSetValueKey(param_1,param_2,0,1,local_20,local_28 + 2);
      RtlFreeUnicodeString(&local_28);
    }
  }
  else {
    *(undefined2 *)(*(longlong *)(param_3 + 4) + (ulonglong)(uVar1 >> 1) * 2) = 0;
    uVar2 = ZwSetValueKey(param_1,param_2,0,1,*(undefined8 *)(param_3 + 4),*param_3 + 2);
  }
  return uVar2;
}



===== CmRegUtilWstrValueGetDword @ 1c0012970 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
CmRegUtilWstrValueGetDword
          (undefined8 param_1,longlong param_2,undefined8 param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 *local_40;
  undefined4 local_38 [2];
  short local_30 [8];
  undefined1 local_20 [4];
  int local_1c;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  local_30[4] = 0;
  local_30[5] = 0;
  local_30[6] = 0;
  local_30[7] = 0;
  uVar1 = WdmlibRtlInitUnicodeStringEx(local_30,param_2);
  uVar2 = 0;
  if (-1 < (int)uVar1) {
    local_40 = local_38;
    local_38[0] = 0;
    local_48 = 0x10;
    uVar1 = ZwQueryValueKey(param_1,local_30,2,local_20);
    if (-1 < (int)uVar1) {
      if (local_1c == 4) {
        uVar2 = local_14;
      }
      else {
        uVar1 = 0xc0000024;
      }
    }
    *param_4 = uVar2;
  }
  return uVar1;
}



===== CmRegUtilWstrValueSetWstrString @ 1c0012a14 =====

void CmRegUtilWstrValueSetWstrString(undefined8 param_1,longlong param_2,longlong param_3)

{
  undefined8 uVar1;
  ushort local_28 [8];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = 0;
  uVar1 = WdmlibRtlInitUnicodeStringEx((short *)local_28,param_3);
  if (-1 < (int)uVar1) {
    uVar1 = WdmlibRtlInitUnicodeStringEx((short *)&local_18,param_2);
    if (-1 < (int)uVar1) {
      CmRegUtilUcValueSetUcString(param_1,&local_18,local_28);
    }
  }
  return;
}



===== VmbusRdmaCopyChildPagesParseInput @ 1c0012a70 =====

long VmbusRdmaCopyChildPagesParseInput
               (undefined8 param_1,undefined8 param_2,uint param_3,undefined8 *param_4)

{
  uint uVar1;
  undefined8 *puVar2;
  uint *puVar3;
  code *pcVar4;
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  long lVar8;
  char *pcVar9;
  char *pcVar10;
  ulonglong uVar11;
  char *pcVar12;
  void *pvVar13;
  undefined8 uVar14;
  ulonglong uVar15;
  char *pcVar16;
  ErrorSite *pEVar17;
  int iVar18;
  uint uVar19;
  __uint64 _Var20;
  ulonglong uVar21;
  undefined1 *puVar22;
  void *pvVar23;
  ulonglong uVar24;
  int iVar25;
  char *pcVar26;
  bool bVar27;
  undefined8 uStack_100;
  undefined1 auStack_f8 [8];
  undefined1 auStack_f0 [40];
  char *local_c8;
  char *pcStack_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  char *local_a8;
  char *local_a0;
  undefined8 local_98;
  undefined8 local_90;
  ulonglong local_88;
  char *local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  char *local_58;
  ulonglong local_50;
  char *local_48;
  char *local_38;
  char *pcStack_30;
  
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if (param_3 < 0x20) {
    local_b8 = 0x5b;
LAB_1c0012ab2:
    local_b0 = 0;
    local_c8 = "onecore\\vm\\dv\\vmbus\\common\\vmbuscommon.cpp";
    pEVar17 = (ErrorSite *)&local_c8;
    pcStack_c0 = "VmbusRdmaCopyChildPagesParseInput";
    goto LAB_1c001317d;
  }
  pcStack_c0 = (char *)&local_78;
  local_c8 = (char *)0x20;
  lVar8 = ReadFromUser(&local_c8);
  puVar22 = auStack_f8;
  uVar21 = 0;
  if (lVar8 < 0) {
    local_b8 = 0x5e;
    local_c8 = "onecore\\vm\\dv\\vmbus\\common\\vmbuscommon.cpp";
    local_b0 = 0;
    pcStack_c0 = "VmbusRdmaCopyChildPagesParseInput";
    OnFailure((ErrorSite *)&local_c8,lVar8);
    return lVar8;
  }
  uVar11 = uStack_60 & 0xffffffff;
  if ((int)uStack_60 - 1U < 0x400) {
    uVar15 = local_68 & 0xffffffff;
    if ((int)local_68 - 1U < 0x400) {
      uVar24 = (ulonglong)local_68._4_4_;
      if ((ulonglong)local_68._4_4_ < uVar15 * 8) {
        local_b8 = 0x6c;
        goto LAB_1c0012ab2;
      }
      pcVar26 = (char *)(uVar15 * 0x30 +
                        ((ulonglong)(local_68._4_4_ - (int)(uVar15 * 8)) & 0xfffffffffffffff8));
      auVar5._8_8_ = 0;
      auVar5._0_8_ = uVar15;
      local_58 = SUB168(auVar5 * ZEXT816(8),0);
      if (SUB168(auVar5 * ZEXT816(8),8) == 0) {
        iVar18 = 0;
      }
      else {
        iVar18 = -0x3fffff6b;
        local_58 = (char *)0xffffffffffffffff;
      }
      pcVar9 = local_58;
      iVar25 = (int)local_68;
      if (iVar18 < 0) {
        local_b8 = 0x82;
        local_c8 = "onecore\\vm\\dv\\vmbus\\common\\vmbuscommon.cpp";
        local_b0 = 0;
        pcStack_c0 = "VmbusRdmaCopyChildPagesParseInput";
        OnFailure((ErrorSite *)&local_c8,iVar18);
        uVar15 = 5;
        pcVar4 = (code *)swi(0x29);
        pcVar9 = (char *)(*pcVar4)();
        puVar22 = auStack_f0;
      }
      pcVar9 = pcVar9 + 0x38;
      pcVar16 = (char *)0xffffffffffffffff;
      if (pcVar9 >= (char *)0x38) {
        pcVar16 = pcVar9;
      }
      if (pcVar9 < (char *)0x38) {
        local_b8 = 0x83;
        local_c8 = "onecore\\vm\\dv\\vmbus\\common\\vmbuscommon.cpp";
        local_b0 = 0;
        pcStack_c0 = "VmbusRdmaCopyChildPagesParseInput";
        *(undefined8 *)(puVar22 + -8) = 0x1c0012c3b;
        OnFailure((ErrorSite *)&local_c8,-(uint)(pcVar9 < (char *)0x38) & 0xc0000095);
        uVar15 = 5;
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)();
        puVar22 = puVar22 + 8;
      }
      local_48 = (char *)((ulonglong)(pcVar16 + 7) & 0xfffffffffffffff8);
      pcVar9 = local_48 + uVar24;
      pcVar16 = (char *)0xffffffffffffffff;
      if (pcVar9 >= local_48) {
        pcVar16 = pcVar9;
      }
      if (pcVar9 < local_48) {
        local_b8 = 0x85;
        local_c8 = "onecore\\vm\\dv\\vmbus\\common\\vmbuscommon.cpp";
        local_b0 = 0;
        pcStack_c0 = "VmbusRdmaCopyChildPagesParseInput";
        *(undefined8 *)(puVar22 + -8) = 0x1c0012c8f;
        OnFailure((ErrorSite *)&local_c8,-(uint)(pcVar9 < local_48) & 0xc0000095);
        uVar15 = 5;
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)();
        puVar22 = puVar22 + 8;
      }
      pcVar9 = (char *)((ulonglong)(pcVar16 + 7) & 0xfffffffffffffff8);
      auVar6._8_8_ = 0;
      auVar6._0_8_ = uVar15;
      local_50 = SUB168(auVar6 * ZEXT816(8),0);
      if (SUB168(auVar6 * ZEXT816(8),8) == 0) {
        iVar18 = 0;
      }
      else {
        iVar18 = -0x3fffff6b;
        local_50 = 0xffffffffffffffff;
      }
      uVar15 = local_50;
      if (iVar18 < 0) {
        local_b8 = 0x87;
        local_c8 = "onecore\\vm\\dv\\vmbus\\common\\vmbuscommon.cpp";
        local_b0 = 0;
        pcStack_c0 = "VmbusRdmaCopyChildPagesParseInput";
        *(undefined8 *)(puVar22 + -8) = 0x1c0012cee;
        OnFailure((ErrorSite *)&local_c8,iVar18);
        pcVar4 = (code *)swi(0x29);
        uVar15 = (*pcVar4)(5);
        puVar22 = puVar22 + 8;
      }
      pcVar10 = pcVar9 + uVar15;
      pcVar16 = (char *)0xffffffffffffffff;
      if (pcVar10 >= pcVar9) {
        pcVar16 = pcVar10;
      }
      if (pcVar10 < pcVar9) {
        local_b8 = 0x88;
        local_c8 = "onecore\\vm\\dv\\vmbus\\common\\vmbuscommon.cpp";
        local_b0 = 0;
        pcStack_c0 = "VmbusRdmaCopyChildPagesParseInput";
        *(undefined8 *)(puVar22 + -8) = 0x1c0012d37;
        OnFailure((ErrorSite *)&local_c8,-(uint)(pcVar10 < pcVar9) & 0xc0000095);
        pcVar16 = (char *)0x5;
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)();
        puVar22 = puVar22 + 8;
      }
      local_c8 = (char *)((ulonglong)(pcVar16 + 7) & 0xfffffffffffffff8);
      pcVar16 = local_c8 + (longlong)pcVar26;
      bVar27 = pcVar16 < local_c8;
      pcVar10 = (char *)0xffffffffffffffff;
      if (!bVar27) {
        pcVar10 = pcVar16;
      }
      if (pcVar16 < local_c8) {
        local_b8 = 0x8a;
        local_c8 = "onecore\\vm\\dv\\vmbus\\common\\vmbuscommon.cpp";
        local_b0 = 0;
        pcStack_c0 = "VmbusRdmaCopyChildPagesParseInput";
        *(undefined8 *)(puVar22 + -8) = 0x1c0012d8d;
        OnFailure((ErrorSite *)&local_c8,-(uint)bVar27 & 0xc0000095);
        pcVar10 = (char *)0x5;
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)();
        puVar22 = puVar22 + 8;
      }
      pcVar16 = (char *)((ulonglong)(pcVar10 + 7) & 0xfffffffffffffff8);
      auVar7._8_8_ = 0;
      auVar7._0_8_ = uVar11;
      local_88 = SUB168(auVar7 * ZEXT816(0x10),0);
      if (SUB168(auVar7 * ZEXT816(0x10),8) == 0) {
        iVar18 = 0;
      }
      else {
        iVar18 = -0x3fffff6b;
        local_88 = 0xffffffffffffffff;
      }
      uVar11 = local_88;
      local_38 = pcVar16;
      if (iVar18 < 0) {
        local_b8 = 0x8c;
        local_c8 = "onecore\\vm\\dv\\vmbus\\common\\vmbuscommon.cpp";
        local_b0 = 0;
        pcStack_c0 = "VmbusRdmaCopyChildPagesParseInput";
        *(undefined8 *)(puVar22 + -8) = 0x1c0012df5;
        OnFailure((ErrorSite *)&local_c8,iVar18);
        pcVar16 = (char *)0x5;
        pcVar4 = (code *)swi(0x29);
        uVar11 = (*pcVar4)();
        puVar22 = puVar22 + 8;
      }
      pcVar12 = pcVar16 + uVar11;
      pcVar10 = (char *)0xffffffffffffffff;
      if (pcVar12 >= pcVar16) {
        pcVar10 = pcVar12;
      }
      uVar19 = -(uint)(pcVar12 < pcVar16) & 0xc0000095;
      _Var20 = (__uint64)uVar19;
      if (pcVar12 < pcVar16) {
        local_b8 = 0x8d;
        local_c8 = "onecore\\vm\\dv\\vmbus\\common\\vmbuscommon.cpp";
        local_b0 = 0;
        pcStack_c0 = "VmbusRdmaCopyChildPagesParseInput";
        *(undefined8 *)(puVar22 + -8) = 0x1c0012e3e;
        OnFailure((ErrorSite *)&local_c8,uVar19);
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(5);
        puVar22 = puVar22 + 8;
      }
      pvVar23 = (void *)0x0;
      pcVar16 = (char *)0x0;
      pvVar13 = pvVar23;
      if (pcVar10 == (char *)0x0) {
LAB_1c0012e74:
        lVar8 = 0;
        pcVar16 = pcVar10;
        pvVar23 = pvVar13;
      }
      else {
        *(undefined8 *)(puVar22 + -8) = 0x1c0012e58;
        pvVar13 = operator_new((__uint64)pcVar10,_Var20);
        if (pvVar13 != (void *)0x0) {
          *(undefined8 *)(puVar22 + -8) = 0x1c0012e6d;
          memset(pvVar13,0,(size_t)pcVar10);
          iVar25 = (int)local_68;
          goto LAB_1c0012e74;
        }
        local_98 = 0x3d;
        local_a8 = "onecore\\vm\\inc\\DynamicArray.h";
        local_90 = 0;
        lVar8 = -0x3fffff66;
        local_a0 = "util::DynamicArray<enum gsl::byte>::Reset";
        *(undefined8 *)(puVar22 + -8) = 0x1c0012eb0;
        OnFailure((ErrorSite *)&local_a8,-0x3fffff66);
        iVar25 = (int)local_68;
      }
      if (lVar8 < 0) {
        local_98 = 0x90;
        goto LAB_1c0012ec1;
      }
      if (pcVar16 == (char *)0x0) {
        pcVar16 = (char *)0x0;
        pvVar13 = (void *)0x0;
      }
      else if ((pcVar16 == (char *)0xffffffffffffffff) ||
              (pvVar13 = pvVar23, pvVar23 == (void *)0x0)) goto LAB_1c00131ad;
      *(int *)((longlong)pvVar23 + 0x28) = iVar25;
      *(int *)((longlong)pvVar23 + 0x2c) = (int)uStack_60;
      if (((char *)0x37 < pcVar16) &&
         (((local_58 == (char *)0xffffffffffffffff || (local_58 <= pcVar16 + -0x38)) &&
          (*(longlong *)((longlong)pvVar23 + 0x10) = (longlong)pvVar13 + 0x38, pcVar9 <= pcVar16))))
      {
        if (local_50 == 0xffffffffffffffff) {
          if ((longlong)pcVar16 - (longlong)pcVar9 == 0xffffffffffffffff) goto LAB_1c00131ad;
        }
        else if ((ulonglong)((longlong)pcVar16 - (longlong)pcVar9) < local_50) goto LAB_1c00131ad;
        *(char **)((longlong)pvVar23 + 0x18) = (char *)((longlong)pvVar13 + (longlong)pcVar9);
        if (local_38 <= pcVar16) {
          uVar11 = (longlong)pcVar16 - (longlong)local_38;
          if (local_88 == 0xffffffffffffffff) {
            if (uVar11 == 0xffffffffffffffff) goto LAB_1c00131ad;
          }
          else {
            if (uVar11 < local_88) goto LAB_1c00131ad;
            uVar11 = local_88;
          }
          local_38 = (char *)((longlong)pvVar13 + (longlong)local_38);
          *(char **)((longlong)pvVar23 + 0x20) = local_38;
          *(byte *)((longlong)pvVar23 + 0x30) = uStack_60._4_1_ & 1;
          if ((local_48 <= pcVar16) &&
             (local_68 >> 0x20 <= (ulonglong)((longlong)pcVar16 - (longlong)local_48))) {
            local_80 = (char *)((longlong)pvVar13 + (longlong)local_48);
            *(undefined8 *)(puVar22 + -8) = 0x1c0013011;
            local_88 = local_68 >> 0x20;
            lVar8 = ReadFromUser(&local_88,local_78);
            if (lVar8 < 0) {
              local_98 = 0xa0;
              local_a8 = "onecore\\vm\\dv\\vmbus\\common\\vmbuscommon.cpp";
              local_90 = 0;
              local_a0 = "VmbusRdmaCopyChildPagesParseInput";
              *(undefined8 *)(puVar22 + -8) = 0x1c0013046;
              OnFailure((ErrorSite *)&local_a8,lVar8);
              if (pvVar23 != (void *)0x0) {
                *(undefined8 *)(puVar22 + -8) = 0x1c0013053;
                operator_delete(pvVar23);
              }
              return lVar8;
            }
            local_80 = local_38;
            *(undefined8 *)(puVar22 + -8) = 0x1c0013074;
            local_88 = uVar11;
            lVar8 = ReadFromUser(&local_88,uStack_70);
            if (lVar8 < 0) {
              local_98 = 0xa3;
            }
            else {
              puVar2 = *(undefined8 **)((longlong)pvVar23 + 0x10);
              uVar19 = *(uint *)((longlong)pvVar23 + 0x28);
              *(undefined8 *)(puVar22 + -8) = 0x1c001309f;
              uVar14 = PkParseGpaRanges((uint *)(local_48 + (longlong)pvVar13),local_68._4_4_,uVar19
                                        ,puVar2);
              lVar8 = (long)uVar14;
              if (-1 < lVar8) {
                if ((local_c8 <= pcVar16) && (pcVar26 <= pcVar16 + -(longlong)local_c8)) {
                  pcVar9 = (char *)((longlong)pvVar13 + (longlong)local_c8);
                  if (*(int *)((longlong)pvVar23 + 0x28) == 0) {
LAB_1c001314c:
                    *param_4 = pvVar23;
                    return 0;
                  }
                  while( true ) {
                    puVar3 = *(uint **)(*(longlong *)((longlong)pvVar23 + 0x10) + uVar21 * 8);
                    uVar19 = puVar3[1];
                    uVar1 = *puVar3;
                    *(char **)(*(longlong *)((longlong)pvVar23 + 0x18) + uVar21 * 8) = pcVar9;
                    uVar11 = (ulonglong)uVar1 + 0xfff + (ulonglong)(uVar19 & 0xfff) >> 0xc;
                    pcVar16 = (char *)(uVar11 * 8 + 0x30);
                    if ((pcVar26 < pcVar16) ||
                       (pcVar26 = pcVar26 + -(longlong)pcVar16, local_c8 = pcVar26,
                       pcVar26 == (char *)0xffffffffffffffff)) break;
                    pcVar9 = pcVar9 + (uVar11 + 6) * 8;
                    uVar19 = (int)uVar21 + 1;
                    uVar21 = (ulonglong)uVar19;
                    if (*(uint *)((longlong)pvVar23 + 0x28) <= uVar19) goto LAB_1c001314c;
                    pcStack_c0 = pcVar9;
                    local_38 = pcVar26;
                    pcStack_30 = pcVar9;
                  }
                }
                goto LAB_1c00131ad;
              }
              local_98 = 0xaa;
            }
LAB_1c0012ec1:
            local_90 = 0;
            local_a8 = "onecore\\vm\\dv\\vmbus\\common\\vmbuscommon.cpp";
            local_a0 = "VmbusRdmaCopyChildPagesParseInput";
            *(undefined8 *)(puVar22 + -8) = 0x1c0012ee7;
            OnFailure((ErrorSite *)&local_a8,lVar8);
            if (pvVar23 != (void *)0x0) {
              *(undefined8 *)(puVar22 + -8) = 0x1c0012ef4;
              operator_delete(pvVar23);
            }
            return lVar8;
          }
        }
      }
LAB_1c00131ad:
                    /* WARNING: Subroutine does not return */
      *(undefined **)(puVar22 + -8) = &UNK_1c00131b2;
      gsl::details::terminate();
    }
  }
  local_98 = 0x62;
  local_a8 = "onecore\\vm\\dv\\vmbus\\common\\vmbuscommon.cpp";
  pEVar17 = (ErrorSite *)&local_a8;
  local_90 = 0;
  local_a0 = "VmbusRdmaCopyChildPagesParseInput";
LAB_1c001317d:
  OnFailure(pEVar17,-0x3ffffff3);
  return -0x3ffffff3;
}



===== entry @ 1c0014010 =====

void entry(longlong param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 1c0014044 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __security_init_cookie(void)

{
  code *pcVar1;
  byte bVar2;
  char cVar3;
  char *pcVar4;
  byte in_DH;
  char unaff_BH;
  char *unaff_RSI;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    pcVar1 = (code *)swi(0x29);
    pcVar4 = (char *)(*pcVar1)(6);
    bVar2 = (byte)pcVar4;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4 + bVar2;
    *pcVar4 = *pcVar4;
    cVar3 = bVar2 + in_DH;
    pcVar4 = (char *)CONCAT71((int7)((ulonglong)pcVar4 >> 8),cVar3);
    *pcVar4 = *pcVar4 + cVar3 + CARRY1(bVar2,in_DH);
    pcVar4[0x21] = pcVar4[0x21] + cVar3;
    *pcVar4 = *pcVar4 + cVar3;
    *unaff_RSI = *unaff_RSI + unaff_BH;
    *pcVar4 = *pcVar4 + cVar3;
    *pcVar4 = *pcVar4 + cVar3;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  ___security_cookie_complement = ~__security_cookie;
  return;
}


