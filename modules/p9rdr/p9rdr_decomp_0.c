
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



===== __report_gsfailure @ 1400010c0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== <lambda_invoker_cdecl><_RTL_BALANCED_NODE_*,void_*> @ 1400010d0 =====

void <lambda_6147e7f0ea888d6333dcffafecd83788>::<lambda_invoker_cdecl><_RTL_BALANCED_NODE_*,void_*>
               (longlong param_1)

{
  p9fs::ConnectionTarget::ReleaseReference((ConnectionTarget *)(param_1 + -0x20));
  return;
}



===== <lambda_invoker_cdecl><_RX_CONTEXT_*> @ 1400010f0 =====

undefined8
<lambda_cd394d8ecd56021729833a0b47c31c76>::<lambda_invoker_cdecl><_RX_CONTEXT_*>(longlong param_1)

{
  WaitRxContext *pWVar1;
  UserCallback *this;
  
  pWVar1 = (WaitRxContext *)(param_1 + 0xd0);
  LOCK();
  this = *(UserCallback **)pWVar1;
  *(undefined8 *)pWVar1 = 0;
  UNLOCK();
  if (this != (UserCallback *)0x0) {
    p9fs::UserCallback::RemoveWaiter(this,pWVar1);
    p9fs::UserCallback::ReleaseReference(this);
  }
  return 0;
}



===== <lambda_invoker_cdecl><void_*,long,bool> @ 140001130 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void <lambda_dc7efe792c9d9606d3444dbabbc62522>::<lambda_invoker_cdecl><void_*,long,bool>
               (_MRX_CREATENETROOT_CONTEXT *param_1,uint param_2,bool param_3)

{
  longlong lVar1;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  lVar1 = *(longlong *)(param_1 + 0x20);
  RxClearMinirdrCancelRoutine(lVar1);
  *(undefined8 *)(lVar1 + 0xd0) = 0;
  *(undefined8 *)(lVar1 + 0xd8) = 0;
  *(undefined8 *)(lVar1 + 0xe0) = 0;
  *(undefined8 *)(lVar1 + 0xe8) = 0;
  if ((int)param_2 < 0) {
    local_18 = 0x22f;
    local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\device.cpp";
    local_20 = 
    "p9fs::Device::CallUserCallback::<lambda_dc7efe792c9d9606d3444dbabbc62522>::operator ()";
    local_10 = "P9: Failed user mode callback: 0x%x\n";
    p9fs::TraceLog((ErrorSite *)&local_28,-0x3fffffff,(ulonglong)param_2);
    *(uint *)(param_1 + 0x11c) = param_2;
    (**(code **)(param_1 + 0x110))(param_1);
  }
  else {
    p9fs::Device::CreateNetRootAndVNetRoot(&p9fs::GlobalDevice,param_1,param_3);
  }
  return;
}



===== ReinterpretSpan<unsigned_short,gsl::byte> @ 1400011f8 =====

/* class gsl::span<unsigned short,-1> __cdecl p9fs::ReinterpretSpan<unsigned short,enum
   gsl::byte>(class gsl::span<enum gsl::byte,-1>) */

ulonglong * __cdecl
p9fs::ReinterpretSpan<unsigned_short,gsl::byte>(ulonglong *param_1,ulonglong *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar1 = param_2[1];
  uVar2 = *param_2;
  *param_1 = uVar2 >> 1;
  param_1[1] = uVar1;
  if ((uVar1 == 0) && (uVar2 >> 1 != 0)) {
                    /* WARNING: Subroutine does not return */
    gsl::details::terminate();
  }
  return param_1;
}



===== copy<gsl::byte_const_,-1,gsl::byte,-1> @ 14000122c =====

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



===== copy<unsigned_short,-1,unsigned_short,-1> @ 1400012ac =====

/* void __cdecl gsl::copy<unsigned short,-1,unsigned short,-1>(class gsl::span<unsigned
   short,-1>,class gsl::span<unsigned short,-1>) */

void __cdecl gsl::copy<unsigned_short,_1,unsigned_short,_1>(ulonglong *param_1,ulonglong *param_2)

{
  ulonglong uVar1;
  void *_Dst;
  
  uVar1 = *param_1;
  if (uVar1 <= *param_2) {
    if (((void *)param_1[1] != (void *)0x0) || (*param_1 * 2 == 0)) {
      _Dst = (void *)param_2[1];
      if ((((_Dst != (void *)0x0) || (*param_2 * 2 == 0)) &&
          ((uVar1 <= *param_2 * 2 && (uVar1 != 0xffffffffffffffff)))) &&
         ((_Dst != (void *)0x0 || (uVar1 == 0)))) {
        memmove(_Dst,(void *)param_1[1],*param_1 * 2);
        return;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  details::terminate();
}



===== ConnectionTargetKey @ 140001328 =====

/* public: __cdecl p9fs::ConnectionTargetKey::ConnectionTargetKey(struct _LUID,class
   std::basic_string_view<unsigned short>) __ptr64 */

ConnectionTargetKey * __thiscall
p9fs::ConnectionTargetKey::ConnectionTargetKey
          (ConnectionTargetKey *this,undefined8 param_2,undefined8 *param_3)

{
  short sVar1;
  undefined8 uVar2;
  undefined4 local_res8 [8];
  short local_18;
  short sStack_16;
  undefined4 uStack_14;
  undefined8 uStack_10;
  
  uVar2 = *param_3;
  uStack_10 = param_3[1];
  *(undefined8 *)this = param_2;
  sVar1 = (short)uVar2 * 2;
  _local_18 = CONCAT22(sVar1,sVar1);
  local_res8[0] = 0;
  *(undefined8 *)(this + 8) = uVar2;
  *(undefined8 *)(this + 0x10) = uStack_10;
  uStack_14 = 0;
  RtlHashUnicodeString(&local_18,1,0,local_res8);
  *(undefined4 *)(this + 0x18) = local_res8[0];
  return this;
}



===== AddConnectionTarget @ 1400013a4 =====

/* private: long __cdecl p9fs::Device::AddConnectionTarget(struct _P9RDR_ADD_CONNECTION_TARGET_INPUT
   const & __ptr64,struct _LUID,class gsl::span<enum gsl::byte const ,-1>) __ptr64 */

long __thiscall
p9fs::Device::AddConnectionTarget
          (undefined8 param_1_00,undefined8 *param_1,undefined8 param_3,ulonglong *param_4)

{
  ConnectionTarget *pCVar1;
  __uint64 _Size;
  ConnectionTarget *pCVar2;
  ushort uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  undefined8 uVar24;
  bool bVar25;
  uint uVar26;
  ConnectionTarget *this;
  ulonglong *puVar27;
  ulonglong uVar28;
  undefined8 *puVar29;
  ulonglong uVar30;
  ulonglong uVar31;
  ulonglong local_98;
  ConnectionTarget *pCStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  char *local_78;
  char *local_70;
  undefined8 local_68;
  char *local_60;
  
  uVar31 = *param_4;
  _Size = uVar31 + 0xe8;
  this = operator_new(_Size);
  if (this == (ConnectionTarget *)0x0) {
    return -0x3fffff66;
  }
  memset(this,0,_Size);
  pCVar1 = this + 8;
  *(undefined8 *)pCVar1 = 0;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0xb8) = 0;
  *(undefined8 *)(this + 0xc0) = 0;
  *(undefined8 *)(this + 200) = 0;
  *(undefined8 *)(this + 0xd0) = 0;
  *(undefined8 *)(this + 0xe0) = 1;
  if (((_Size == 0xffffffffffffffff) || (_Size < 0xe8)) || (uVar31 == 0xffffffffffffffff))
  goto LAB_140001788;
  pCVar2 = this + 0xe8;
  local_88 = *param_4;
  uStack_80 = (ConnectionTarget *)param_4[1];
  local_98 = uVar31;
  pCStack_90 = pCVar2;
  gsl::copy<gsl::byte_const_,_1,gsl::byte,_1>(&local_88,&local_98);
  uVar3 = *(ushort *)((longlong)param_1 + 0x8c);
  if (uVar3 <= uVar31) {
    local_88 = (ulonglong)uVar3;
    local_98 = (ulonglong)uVar3;
    pCStack_90 = pCVar2;
    uStack_80 = pCVar2;
    puVar27 = (ulonglong *)ReinterpretSpan<unsigned_short,gsl::byte>(&local_78,&local_88);
    uVar30 = *puVar27;
    pCStack_90 = (ConnectionTarget *)puVar27[1];
    local_98 = uVar30;
    if ((uVar30 != 0xffffffffffffffff) && ((pCStack_90 != (ConnectionTarget *)0x0 || (uVar30 == 0)))
       ) {
      uVar28 = Feature_3131016505__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar28 != 0) {
        uStack_80 = pCStack_90;
        local_88 = uVar30;
        bVar25 = IsValidDistributionName(&local_88);
        if (!bVar25) {
          local_68 = 0x202;
          local_60 = "P9: Invalid share name in connection target.\n";
          local_78 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\device.cpp";
          local_70 = "p9fs::Device::AddConnectionTarget";
          TraceLog((ErrorSite *)&local_78,-0x3fffffff);
          ConnectionTarget::ReleaseReference(this);
          return -0x3ffffff3;
        }
      }
      uStack_80 = pCStack_90;
      local_88 = uVar30;
      puVar29 = (undefined8 *)
                ConnectionTargetKey::ConnectionTargetKey
                          ((ConnectionTargetKey *)&local_78,param_3,&local_88);
      uVar16 = puVar29[1];
      uVar17 = puVar29[2];
      uVar18 = puVar29[3];
      *(undefined8 *)this = *puVar29;
      *(undefined8 *)(this + 8) = uVar16;
      *(undefined8 *)(this + 0x10) = uVar17;
      *(undefined8 *)(this + 0x18) = uVar18;
      uVar16 = param_1[1];
      uVar4 = *(undefined4 *)(param_1 + 2);
      uVar5 = *(undefined4 *)((longlong)param_1 + 0x14);
      uVar6 = *(undefined4 *)(param_1 + 3);
      uVar7 = *(undefined4 *)((longlong)param_1 + 0x1c);
      uVar8 = *(undefined4 *)(param_1 + 4);
      uVar9 = *(undefined4 *)((longlong)param_1 + 0x24);
      uVar10 = *(undefined4 *)(param_1 + 5);
      uVar11 = *(undefined4 *)((longlong)param_1 + 0x2c);
      uVar12 = *(undefined4 *)(param_1 + 6);
      uVar13 = *(undefined4 *)((longlong)param_1 + 0x34);
      uVar14 = *(undefined4 *)(param_1 + 7);
      uVar15 = *(undefined4 *)((longlong)param_1 + 0x3c);
      uVar17 = param_1[8];
      uVar18 = param_1[9];
      uVar19 = param_1[10];
      uVar20 = param_1[0xb];
      uVar21 = param_1[0xc];
      uVar22 = param_1[0xd];
      uVar23 = param_1[0xe];
      uVar24 = param_1[0xf];
      *(undefined8 *)(this + 0x38) = *param_1;
      *(undefined8 *)(this + 0x40) = uVar16;
      *(undefined4 *)(this + 0x48) = uVar4;
      *(undefined4 *)(this + 0x4c) = uVar5;
      *(undefined4 *)(this + 0x50) = uVar6;
      *(undefined4 *)(this + 0x54) = uVar7;
      *(undefined4 *)(this + 0x58) = uVar8;
      *(undefined4 *)(this + 0x5c) = uVar9;
      *(undefined4 *)(this + 0x60) = uVar10;
      *(undefined4 *)(this + 100) = uVar11;
      *(undefined4 *)(this + 0x68) = uVar12;
      *(undefined4 *)(this + 0x6c) = uVar13;
      *(undefined4 *)(this + 0x70) = uVar14;
      *(undefined4 *)(this + 0x74) = uVar15;
      *(undefined8 *)(this + 0x78) = uVar17;
      *(undefined8 *)(this + 0x80) = uVar18;
      *(undefined8 *)(this + 0x88) = uVar19;
      *(undefined8 *)(this + 0x90) = uVar20;
      *(undefined8 *)(this + 0x98) = uVar21;
      *(undefined8 *)(this + 0xa0) = uVar22;
      *(undefined8 *)(this + 0xa8) = uVar23;
      *(undefined8 *)(this + 0xb0) = uVar24;
      uVar30 = (ulonglong)*(ushort *)((longlong)param_1 + 0x8c);
      if ((uVar30 <= uVar31) && (uVar31 = uVar31 - uVar30, uVar31 != 0xffffffffffffffff)) {
        pCVar2 = pCVar2 + uVar30;
        uVar30 = (ulonglong)*(ushort *)((longlong)param_1 + 0x8e);
        if (((uVar30 <= uVar31) && ((pCVar2 != (ConnectionTarget *)0x0 || (uVar30 == 0)))) &&
           ((local_88 = uVar30, uStack_80 = pCVar2, pCVar2 != (ConnectionTarget *)0x0 ||
            (uVar30 == 0)))) {
          local_88._0_4_ = (uint)*(ushort *)((longlong)param_1 + 0x8e);
          *(uint *)(this + 200) = (uint)local_88;
          *(undefined4 *)(this + 0xcc) = 0;
          *(ConnectionTarget **)(this + 0xd0) = pCVar2;
          *(undefined4 *)(this + 0xd8) = *(undefined4 *)(param_1 + 0x10);
          if (*(short *)(this + 0x38) == 1) {
            uVar30 = (ulonglong)*(ushort *)((longlong)param_1 + 0x8e);
            if ((uVar31 < uVar30) || (local_88 = uVar31 - uVar30, local_88 == 0xffffffffffffffff))
            goto LAB_140001788;
            uStack_80 = pCVar2 + uVar30;
            puVar27 = (ulonglong *)ReinterpretSpan<unsigned_short,gsl::byte>(&local_78);
            local_98 = *puVar27;
            pCStack_90 = (ConnectionTarget *)puVar27[1];
            local_88 = local_98;
            if ((local_98 == 0xffffffffffffffff) ||
               ((pCStack_90 == (ConnectionTarget *)0x0 &&
                (uStack_80 = (ConnectionTarget *)0x0, local_98 != 0)))) {
                    /* WARNING: Subroutine does not return */
              gsl::details::terminate();
            }
            local_88._0_4_ = (uint)local_98;
            local_88._4_4_ = (undefined4)(local_98 >> 0x20);
            uStack_80._0_4_ = SUB84(pCStack_90,0);
            uStack_80._4_4_ = (undefined4)((ulonglong)pCStack_90 >> 0x20);
            *(uint *)(this + 0xb8) = (uint)local_88;
            *(undefined4 *)(this + 0xbc) = local_88._4_4_;
            *(undefined4 *)(this + 0xc0) = (undefined4)uStack_80;
            *(undefined4 *)(this + 0xc4) = uStack_80._4_4_;
            uStack_80 = pCStack_90;
          }
          local_60 = "P9: Adding connection target for \"%.*S\" using address family %d\n";
          uVar26 = (uint)*(ushort *)(this + 0x38);
          local_78 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\device.cpp";
          local_70 = "p9fs::Device::AddConnectionTarget";
          local_68 = 0x213;
          TraceLog((ErrorSite *)&local_78,0,(ulonglong)*(uint *)pCVar1,*(undefined8 *)(this + 0x10),
                   uVar26);
          bVar25 = ConnectionTargetTree::Insert((ConnectionTargetTree *)&DAT_14001a340,this);
          if (bVar25) {
            ConnectionTarget::ReleaseReference(this);
            return 0;
          }
          local_60 = "P9: Connection target \"%.*S\" already exists.\n";
          local_78 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\device.cpp";
          local_70 = "p9fs::Device::AddConnectionTarget";
          local_68 = 0x219;
          TraceLog((ErrorSite *)&local_78,-0x3fffffff,(ulonglong)*(uint *)pCVar1,
                   *(undefined8 *)(this + 0x10),uVar26);
          ConnectionTarget::ReleaseReference(this);
          return -0x3fffffcb;
        }
      }
LAB_140001788:
                    /* WARNING: Subroutine does not return */
      gsl::details::terminate();
    }
  }
                    /* WARNING: Subroutine does not return */
  gsl::details::terminate();
}



===== AddConnectionTarget @ 1400017a0 =====

/* public: long __cdecl p9fs::Device::AddConnectionTarget(struct _RX_CONTEXT * __ptr64) __ptr64 */

long __thiscall p9fs::Device::AddConnectionTarget(Device *this,_RX_CONTEXT *param_1)

{
  ushort uVar1;
  uint uVar2;
  short *psVar3;
  Device *pDVar4;
  long lVar5;
  char *pcVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  char *pcVar9;
  uint uVar10;
  char *local_28;
  Device *pDStack_20;
  undefined8 local_18;
  char *local_10;
  
  lVar5 = CheckIoctlAccess(this);
  if (lVar5 < 0) {
    local_18 = 0x84;
LAB_1400017cf:
    local_10 = (char *)0x0;
    local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\device.cpp";
    pDStack_20 = (Device *)0x1400162c0;
    TraceLog((ErrorSite *)&local_28,lVar5);
    return lVar5;
  }
  uVar2 = *(uint *)(param_1 + 0x228);
  uVar7 = (ulonglong)uVar2;
  if (uVar2 < 0x90) {
    local_18 = 0x8a;
  }
  else {
    psVar3 = *(short **)(param_1 + 0x218);
    uVar1 = psVar3[0x46];
    uVar10 = (uint)(ushort)psVar3[0x47] + (uint)uVar1;
    if ((ulonglong)uVar10 + 0x90 <= uVar7) {
      if (((uVar1 & 1) == 0) && (uVar1 != 0)) {
        if (*psVar3 == 1) {
          uVar8 = (ulonglong)(uVar2 - uVar10) - 0x90;
          if (((uVar8 & 1) != 0) || (0xfffe < (ulonglong)(uVar2 - uVar10) - 0x91)) {
            local_18 = 0xa7;
            local_10 = "P9: Invalid AF_UNIX path in P9RDR_ADD_CONNECTION_TARGET_INPUT.";
            goto LAB_140001927;
          }
          uVar10 = uVar10 + (int)uVar8;
        }
        pcVar9 = (char *)(longlong)(int)uVar10;
        pDVar4 = pDStack_20;
        if (0x8f < uVar7) {
          pcVar6 = (char *)(uVar7 - 0x90);
          if (pcVar9 == (char *)0xffffffffffffffff) {
            if (pcVar6 == (char *)0xffffffffffffffff) goto LAB_14000196a;
          }
          else {
            if (pcVar6 < pcVar9) goto LAB_14000196a;
            pcVar6 = pcVar9;
          }
          pDStack_20 = (Device *)(psVar3 + 0x48);
          local_28 = pcVar6;
          if ((pDStack_20 != (Device *)0x0) || (pDVar4 = (Device *)0, pcVar6 == (char *)0x0)) {
            lVar5 = AddConnectionTarget(pDStack_20,psVar3,*(undefined8 *)(psVar3 + 0x42),&local_28);
            if (-1 < lVar5) {
              return 0;
            }
            local_18 = 0xb2;
            goto LAB_1400017cf;
          }
        }
LAB_14000196a:
        pDStack_20 = pDVar4;
                    /* WARNING: Subroutine does not return */
        gsl::details::terminate();
      }
      local_18 = 0x9b;
      local_10 = "P9: Invalid share name in P9RDR_ADD_CONNECTION_TARGET_INPUT.";
      goto LAB_140001927;
    }
    local_18 = 0x94;
  }
  local_10 = "P9: Invalid buffer for P9RDR_ADD_CONNECTION_TARGET_INPUT.";
LAB_140001927:
  local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\device.cpp";
  pDStack_20 = (Device *)0x1400162c0;
  TraceLog((ErrorSite *)&local_28,-0x3fffffff);
  return -0x3ffffff3;
}



===== CallUserCallback @ 140001978 =====

/* private: long __cdecl p9fs::Device::CallUserCallback(struct _MRX_CREATENETROOT_CONTEXT *
   __ptr64,class std::basic_string_view<unsigned short>) __ptr64 */

long __thiscall p9fs::Device::CallUserCallback(Device *this,longlong param_1,undefined8 *param_3)

{
  longlong lVar1;
  int iVar2;
  char *local_28;
  char *pcStack_20;
  undefined8 local_18;
  undefined8 local_10;
  
  lVar1 = *(longlong *)(param_1 + 0x20);
  *(longlong *)(lVar1 + 0xe0) = param_1;
  *(code **)(lVar1 + 0xd8) =
       <lambda_dc7efe792c9d9606d3444dbabbc62522>::<lambda_invoker_cdecl><void_*,long,bool>;
  iVar2 = RxSetMinirdrCancelRoutine
                    (lVar1,<lambda_cd394d8ecd56021729833a0b47c31c76>::
                           <lambda_invoker_cdecl><_RX_CONTEXT_*>);
  if (iVar2 < 0) {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\device.cpp";
    local_18 = 0x240;
    pcStack_20 = "p9fs::Device::CallUserCallback";
    TraceLog((ErrorSite *)&local_28,iVar2);
  }
  else {
    local_28 = (char *)*param_3;
    pcStack_20 = (char *)param_3[1];
    iVar2 = UserCallbackManager::CallUserCallback
                      ((UserCallbackManager *)(this + 0x318),
                       *(undefined8 *)(*(longlong *)(param_1 + 0x108) + 0x48),lVar1 + 0xd0,&local_28
                      );
  }
  return iVar2;
}



===== CheckIoctlAccess @ 140001a50 =====

/* private: long __cdecl p9fs::Device::CheckIoctlAccess(void) __ptr64 */

long __thiscall p9fs::Device::CheckIoctlAccess(Device *this)

{
  char cVar1;
  undefined8 uVar2;
  long lVar3;
  ulonglong local_res8;
  undefined4 local_res10 [2];
  char *local_48;
  char *local_40;
  undefined8 local_38;
  char *local_30;
  undefined1 local_28 [32];
  
  local_res8 = (ulonglong)this & 0xffffffff00000000;
  local_res10[0] = 0;
  SeCaptureSubjectContext(local_28);
  uVar2 = IoGetFileObjectGenericMapping();
  cVar1 = SeAccessCheck(&DAT_14001a380,local_28,0,0x1f01ff,0,0,uVar2,1,local_res10,&local_res8);
  lVar3 = 0;
  if (cVar1 == '\0') {
    local_38 = 0x24d;
    local_48 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\device.cpp";
    local_40 = "p9fs::Device::CheckIoctlAccess";
    local_30 = "P9: Ioctl access check failed.";
    TraceLog((ErrorSite *)&local_48,-0x3fffffff);
    lVar3 = (long)local_res8;
  }
  SeReleaseSubjectContext(local_28);
  return lVar3;
}



===== Clear @ 140001b38 =====

/* public: void __cdecl p9fs::ConnectionTargetTree::Clear(void) __ptr64 */

void __thiscall p9fs::ConnectionTargetTree::Clear(ConnectionTargetTree *this)

{
  ConnectionTargetTree *pCVar1;
  ConnectionTargetTree *pCVar2;
  ConnectionTargetTree CVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  
  pCVar1 = this + 0x10;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(pCVar1,0);
  puVar4 = *(undefined8 **)this;
  pCVar2 = this + 8;
  CVar3 = *pCVar2;
  if (((byte)*pCVar2 & 1) != 0) {
    if (puVar4 == (undefined8 *)0x0) goto LAB_140001be9;
    puVar4 = (undefined8 *)((ulonglong)puVar4 ^ (ulonglong)this);
  }
  if (puVar4 != (undefined8 *)0x0) {
    do {
      while (puVar5 = (undefined8 *)*puVar4, puVar5 != (undefined8 *)0x0) {
        puVar6 = puVar4;
LAB_140001bae:
        if (((byte)CVar3 & 1) != 0) {
          puVar5 = (undefined8 *)((ulonglong)puVar4 ^ (ulonglong)puVar5);
        }
        *puVar6 = 0;
        puVar4 = puVar5;
      }
      puVar6 = puVar4 + 1;
      puVar5 = (undefined8 *)*puVar6;
      if (puVar5 != (undefined8 *)0x0) goto LAB_140001bae;
      puVar5 = (undefined8 *)(puVar4[2] & 0xfffffffffffffffc);
      if ((((byte)CVar3 & 1) != 0) && (puVar5 != (undefined8 *)0x0)) {
        puVar5 = (undefined8 *)((ulonglong)puVar5 ^ (ulonglong)puVar4);
      }
      <lambda_6147e7f0ea888d6333dcffafecd83788>::<lambda_invoker_cdecl><_RTL_BALANCED_NODE_*,void_*>
                ((longlong)puVar4);
      if (puVar5 == (undefined8 *)0x0) break;
      puVar4 = puVar5;
    } while( true );
  }
LAB_140001be9:
  CVar3 = *pCVar2;
  *(undefined8 *)this = 0;
  *(undefined8 *)(this + 8) = 0;
  if (((byte)CVar3 & 1) != 0) {
    this[8] = (ConnectionTargetTree)0x1;
  }
  if (pCVar1 != (ConnectionTargetTree *)0x0) {
    ExReleasePushLockExclusiveEx(pCVar1,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== CompareNode @ 140001c40 =====

/* private: static long __cdecl p9fs::ConnectionTargetTree::CompareNode(void * __ptr64,struct
   _RTL_BALANCED_NODE * __ptr64) */

long __cdecl p9fs::ConnectionTargetTree::CompareNode(void *param_1,_RTL_BALANCED_NODE *param_2)

{
  short sVar1;
  long lVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  undefined8 uStack_10;
  
  if (*(ulonglong *)param_1 < *(ulonglong *)(param_2 + -0x20)) {
LAB_140001c52:
    lVar2 = -1;
  }
  else {
    if (*(ulonglong *)param_1 <= *(ulonglong *)(param_2 + -0x20)) {
      if (*(uint *)((longlong)param_1 + 0x18) < *(uint *)(param_2 + -8)) goto LAB_140001c52;
      if (*(uint *)((longlong)param_1 + 0x18) <= *(uint *)(param_2 + -8)) {
        uStack_10 = *(undefined8 *)((longlong)param_1 + 0x10);
        sVar1 = (short)*(undefined8 *)((longlong)param_1 + 8) * 2;
        uStack_20 = *(undefined8 *)(param_2 + -0x10);
        local_28._0_4_ = CONCAT22(sVar1,sVar1);
        local_28 = (ulonglong)(uint)local_28;
        local_18 = local_28;
        sVar1 = (short)*(undefined8 *)(param_2 + -0x18) * 2;
        local_28._0_4_ = CONCAT22(sVar1,sVar1);
        local_28 = (ulonglong)(uint)local_28;
        lVar2 = RtlCompareUnicodeString(&local_18,&local_28,1);
        return lVar2;
      }
    }
    lVar2 = 1;
  }
  return lVar2;
}



===== CreateAcl @ 140001ce0 =====

/* private: static class util::BasicExpected<class wistd::unique_ptr<struct _ACL,struct
   wistd::default_delete<struct _ACL> >,long> __cdecl p9fs::Device::CreateAcl(class gsl::span<void *
   __ptr64,-1>) */

undefined1 * __cdecl p9fs::Device::CreateAcl(undefined1 *param_1,longlong *param_2)

{
  undefined8 *puVar1;
  int iVar2;
  long lVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  int iVar7;
  char *local_38;
  char *local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  puVar6 = (undefined8 *)param_2[1];
  iVar7 = 8;
  puVar1 = puVar6 + *param_2;
  for (puVar5 = puVar6; puVar5 != puVar1; puVar5 = puVar5 + 1) {
    iVar2 = RtlLengthSid(*puVar5);
    iVar7 = iVar7 + 8 + iVar2;
  }
  lVar4 = ExAllocatePool2(0x100,iVar7,0x78523950);
  if (lVar4 == 0) {
    *param_1 = 0;
    *(undefined4 *)(param_1 + 8) = 0xc000009a;
  }
  else {
    lVar3 = RtlCreateAcl(lVar4,iVar7,2);
    if (lVar3 < 0) {
      local_28 = 0x263;
LAB_140001d8d:
      local_20 = 0;
      local_38 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\device.cpp";
      local_30 = "p9fs::Device::CreateAcl";
      TraceLog((ErrorSite *)&local_38,lVar3);
      *param_1 = 0;
      *(long *)(param_1 + 8) = lVar3;
      ExFreePoolWithTag(lVar4,0);
    }
    else {
      for (; puVar6 != puVar1; puVar6 = puVar6 + 1) {
        lVar3 = RtlAddAccessAllowedAce(lVar4,2,0x1f01ff,*puVar6);
        if (lVar3 < 0) {
          local_28 = 0x267;
          goto LAB_140001d8d;
        }
      }
      *param_1 = 1;
      *(longlong *)(param_1 + 8) = lVar4;
    }
  }
  return param_1;
}



===== CreateNetRootAndVNetRoot @ 140001e34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl p9fs::Device::CreateNetRootAndVNetRoot(struct _MRX_CREATENETROOT_CONTEXT *
   __ptr64,bool) __ptr64 */

void __thiscall
p9fs::Device::CreateNetRootAndVNetRoot
          (Device *this,_MRX_CREATENETROOT_CONTEXT *param_1,bool param_2)

{
  code *pcVar1;
  ulonglong uVar2;
  short *psVar3;
  bool bVar4;
  uint uVar5;
  Session *pSVar6;
  longlong lVar7;
  Device *pDVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  Device *local_res8;
  Device *local_res10;
  undefined1 auStack_d8 [8];
  undefined1 auStack_d0 [24];
  ushort local_b8 [4];
  short *psStack_b0;
  ulonglong local_a8;
  short *psStack_a0;
  ulonglong local_98;
  short *psStack_90;
  ulonglong local_88;
  short *psStack_80;
  char *local_78;
  char *local_70;
  undefined8 local_68;
  char *local_60;
  ConnectionTargetKey local_58 [48];
  
  local_b8[0] = 0;
  local_b8[1] = 0;
  local_b8[2] = 0;
  local_b8[3] = 0;
  psStack_b0 = (short *)0x0;
  local_res8 = this;
  RtlInitUnicodeString(local_b8,0);
  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x108) + 0x20);
  ExtractNetRootName(*(_UNICODE_STRING **)(lVar7 + 0x58),*(_MRX_SRV_CALL_ **)(lVar7 + 0x20),
                     (_UNICODE_STRING *)local_b8,(_UNICODE_STRING *)0x0);
  local_60 = "P9: Create V_NET_ROOT: %wZ\n";
  local_78 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\device.cpp";
  local_70 = "p9fs::Device::CreateNetRootAndVNetRoot";
  local_68 = 0xef;
  TraceLog((ErrorSite *)&local_78,0,*(undefined8 *)(lVar7 + 0x58));
  local_a8 = (ulonglong)(local_b8[0] >> 1);
  psStack_a0 = psStack_b0;
  if (psStack_b0 == (short *)0x0) {
    if (local_a8 != 0) {
LAB_140002124:
                    /* WARNING: Subroutine does not return */
      gsl::details::terminate();
    }
LAB_140001ef5:
    uVar2 = (ulonglong)(local_b8[0] >> 1);
    psVar3 = psStack_b0;
  }
  else {
    if ((local_a8 == 0) || (*psStack_b0 != 0x5c)) goto LAB_140001ef5;
    local_98 = local_a8 - 1;
    if (local_98 == 0xffffffffffffffff) goto LAB_140002124;
    psStack_90 = psStack_b0 + 1;
    uVar2 = local_98;
    psVar3 = psStack_90;
  }
  local_88 = uVar2;
  psStack_80 = psVar3;
  ConnectionTargetKey::ConnectionTargetKey
            (local_58,*(undefined8 *)(*(longlong *)(param_1 + 0x108) + 0x48),&local_88);
  ConnectionTargetTree::Find
            ((ConnectionTargetTree *)&DAT_14001a340,(ConnectionTargetKey *)&local_res8);
  pDVar8 = local_res8;
  if (local_res8 == (Device *)0x0) {
    if (param_2) {
      local_88 = uVar2;
      psStack_80 = psVar3;
      bVar4 = IsValidDistributionName(&local_88);
      if (bVar4) {
        uVar5 = IsSupportedUser(&GlobalDevice,*(_SECURITY_SUBJECT_CONTEXT **)(param_1 + 0x28));
        if (-1 < (int)uVar5) {
          local_88 = uVar2;
          psStack_80 = psVar3;
          uVar5 = CallUserCallback(&GlobalDevice,param_1,&local_88);
          puVar10 = auStack_d8;
          if (-1 < (int)uVar5) goto LAB_1400020f5;
        }
        local_78 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\device.cpp";
        local_60 = "P9: Failed user mode callback: 0x%x\n";
        local_70 = "p9fs::Device::CreateNetRootAndVNetRoot";
        local_68 = 0x10d;
        TraceLog((ErrorSite *)&local_78,-0x3fffffff,(ulonglong)uVar5);
      }
    }
    *(undefined4 *)(param_1 + 0x11c) = 0xc00000cc;
  }
  else {
    *(undefined4 *)(lVar7 + 0x50) = 7;
    *(undefined1 *)(lVar7 + 0x4d) = 0;
    *(undefined4 *)(param_1 + 0x11c) = 0;
    pSVar6 = operator_new(0x108);
    if (pSVar6 != (Session *)0x0) {
      pSVar6 = (Session *)Session::Session(pSVar6,(_WSK_PROVIDER_NPI *)&DAT_14001a330);
      if (pSVar6 != (Session *)0x0) {
        KeInitializeSpinLock(pSVar6 + 0x48);
        lVar7 = RxCreateMidAtlas(0x400,0x80);
        puVar9 = auStack_d8;
        *(longlong *)(pSVar6 + 0x40) = lVar7;
        if (lVar7 == 0) {
          *(undefined4 *)(param_1 + 0x118) = 0xc0000017;
          (**(code **)(param_1 + 0x110))(param_1);
          Session::~Session(pSVar6);
          ExFreePoolWithTag(pSVar6,0);
          puVar10 = auStack_d8;
        }
        else {
          local_res10 = pDVar8;
          *(Session **)(*(longlong *)(param_1 + 0x108) + 0x28) = pSVar6;
          puVar10 = auStack_d8;
          if (pDVar8 != (Device *)0x0) {
            LOCK();
            pDVar8 = pDVar8 + 0xe0;
            lVar7 = *(longlong *)pDVar8;
            *(longlong *)pDVar8 = *(longlong *)pDVar8 + 1;
            UNLOCK();
            if (lVar7 + 1 < 2) {
              pcVar1 = (code *)swi(0x29);
              (*pcVar1)(0xe);
              puVar9 = auStack_d0;
            }
            pDVar8 = local_res8;
            puVar10 = puVar9;
          }
          *(undefined8 *)(puVar10 + -8) = 0x1400020da;
          Session::Connect(pSVar6,param_1,&local_res10);
        }
        goto LAB_1400020f5;
      }
    }
    *(undefined4 *)(param_1 + 0x118) = 0xc000009a;
  }
  (**(code **)(param_1 + 0x110))(param_1);
  puVar10 = auStack_d8;
LAB_1400020f5:
  if (pDVar8 != (Device *)0x0) {
    *(undefined8 *)(puVar10 + -8) = 0x140002102;
    ConnectionTarget::ReleaseReference((ConnectionTarget *)pDVar8);
  }
  return;
}



===== CreateSecurityDescriptor @ 140002130 =====

/* private: static long __cdecl p9fs::Device::CreateSecurityDescriptor(void * __ptr64,struct _ACL *
   __ptr64) */

long __cdecl p9fs::Device::CreateSecurityDescriptor(void *param_1,_ACL *param_2)

{
  long lVar1;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  lVar1 = RtlCreateSecurityDescriptor(param_1,1);
  if (lVar1 < 0) {
    local_18 = 0x26f;
  }
  else {
    lVar1 = RtlSetDaclSecurityDescriptor(param_1,1,param_2,0);
    if (-1 < lVar1) {
      return 0;
    }
    local_18 = 0x270;
  }
  local_10 = 0;
  local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\device.cpp";
  local_20 = "p9fs::Device::CreateSecurityDescriptor";
  TraceLog((ErrorSite *)&local_28,lVar1);
  return lVar1;
}



===== EnumerateConnections @ 1400021dc =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl p9fs::Device::EnumerateConnections(struct _RX_CONTEXT * __ptr64) __ptr64 */

long __thiscall p9fs::Device::EnumerateConnections(Device *this,_RX_CONTEXT *param_1)

{
  wint_t *pwVar1;
  _RX_PREFIX_TABLE *p_Var2;
  wint_t wVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  uint uVar12;
  ulonglong uVar13;
  uint uVar14;
  char *pcVar15;
  uint uVar16;
  Device *local_res8;
  _RX_CONTEXT *local_res10;
  ushort *local_res18;
  char *local_108;
  wint_t *pwStack_100;
  undefined8 local_f8;
  char *local_f0;
  ulonglong local_e8;
  wint_t *pwStack_e0;
  ulonglong local_d8;
  wint_t *pwStack_d0;
  ulonglong local_c8;
  wint_t *pwStack_c0;
  char *local_b8;
  wint_t *pwStack_b0;
  char *local_a8;
  longlong local_a0;
  ulonglong local_98;
  wint_t *pwStack_90;
  ulonglong local_88;
  wint_t *pwStack_80;
  ulonglong local_78;
  wint_t *pwStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  
  uVar11 = (ulonglong)*(uint *)(param_1 + 0x22c);
  local_res8 = this;
  local_res10 = param_1;
  if (*(longlong *)(param_1 + 0x220) == 0) {
    if (uVar11 != 0) goto LAB_140002679;
  }
  else {
    uVar16 = 4;
    if (3 < uVar11) {
      local_e8 = uVar11 - 4;
      if (local_e8 != 0xffffffffffffffff) {
        pwStack_e0 = (wint_t *)(*(longlong *)(param_1 + 0x220) + 4);
        local_res8 = (Device *)((ulonglong)this & 0xffffffff00000000);
        uVar14 = 4;
        iVar4 = IoGetRequestorSessionId(*(undefined8 *)(param_1 + 0x28),&local_res8);
        if (iVar4 < 0) {
          local_f8 = 0x198;
          local_108 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\device.cpp";
          local_f0 = (char *)0x0;
          pwStack_100 = (wint_t *)0x140016508;
          TraceLog((ErrorSite *)&local_108,iVar4);
          return iVar4;
        }
        p_Var2 = *(_RX_PREFIX_TABLE **)(_GlobalDevice + 0x1f8);
        KeEnterCriticalRegion();
        ExAcquireResourceExclusiveLite(p_Var2 + 0x18,1);
        local_68 = 0;
        uStack_60 = 0;
        local_58 = 0;
        uStack_50 = 0;
        local_48 = 0;
        uStack_40 = 0;
        lVar6 = RxPrefixTableLookupFirstObject
                          (*(undefined8 *)(_GlobalDevice + 0x1f8),0,0,0xeb12,&local_68);
        if (lVar6 != 0) {
          uVar11 = local_e8;
          do {
            if (*(int *)(lVar6 + 0xcc) == 3) {
              if (*(int *)(lVar6 + 0x58) == (int)local_res8) {
                if (*(char *)(lVar6 + 0xc0) != '\0') {
                  local_res18 = (ushort *)(*(longlong *)(lVar6 + 0x20) + 0xd8);
                  uVar12 = *local_res18 + 4;
                  if (*(short *)(*(longlong *)(lVar6 + 0xe8) + 4) == 0x3a) {
                    uVar12 = (uint)*local_res18;
                  }
                  uVar12 = uVar12 + 6;
                  uVar7 = uVar12 + uVar16;
                  uVar5 = 0xffffffff;
                  if (uVar16 <= uVar7) {
                    uVar5 = uVar7;
                  }
                  uVar8 = -(uint)(uVar7 < uVar16) & 0xc0000095;
                  if (uVar7 < uVar16) {
                    local_f8 = 0x1b7;
                    local_108 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\device.cpp";
                    local_f0 = (char *)0x0;
                    pwStack_100 = (wint_t *)0x140016508;
                    TraceLog((ErrorSite *)&local_108,uVar8);
                    RxPrefixTableEndLookup(&local_68);
                    if (p_Var2 == (_RX_PREFIX_TABLE *)0x0) {
                      return uVar8;
                    }
                    details::ReleasePrefixTableLock(p_Var2);
                    return uVar8;
                  }
                  uVar13 = (ulonglong)uVar12;
                  uVar16 = uVar5;
                  if (uVar13 <= uVar11) {
                    pwStack_c0 = pwStack_e0;
                    local_108 = (char *)(ulonglong)uVar12;
                    pwStack_100 = pwStack_e0;
                    local_c8 = uVar13;
                    ReinterpretSpan<unsigned_short,gsl::byte>(&local_d8,&local_108);
                    if (local_d8 == 0) goto LAB_140002679;
                    *pwStack_d0 = 0x5c;
                    if (local_d8 == 0) goto LAB_140002679;
                    pcVar9 = (char *)(local_d8 - 1);
                    local_b8 = pcVar9;
                    if (pcVar9 == (char *)0xffffffffffffffff) goto LAB_140002679;
                    pwStack_b0 = pwStack_d0 + 1;
                    pcVar15 = (char *)(ulonglong)(*local_res18 >> 1);
                    if (*(longlong *)(local_res18 + 4) == 0) {
                      if (pcVar15 != (char *)0x0) goto LAB_140002679;
                    }
                    local_108 = pcVar9;
                    pwStack_100 = pwStack_b0;
                    local_a8 = pcVar15;
                    local_a0 = *(longlong *)(local_res18 + 4);
                    gsl::copy<unsigned_short,_1,unsigned_short,_1>(&local_a8,&local_108);
                    if (pcVar9 <= pcVar15) goto LAB_140002679;
                    pwStack_d0[(longlong)(pcVar15 + 1)] = 0;
                    if (pcVar9 < pcVar15 + 1) goto LAB_140002679;
                    uVar10 = (longlong)pcVar9 - (longlong)(pcVar15 + 1);
                    local_98 = uVar10;
                    if (uVar10 == 0xffffffffffffffff) goto LAB_140002679;
                    pwVar1 = pwStack_d0 + (longlong)(pcVar15 + 2);
                    wVar3 = *(wint_t *)(*(longlong *)(lVar6 + 0xe8) + 4);
                    local_d8 = uVar10;
                    pwStack_d0 = pwVar1;
                    pwStack_90 = pwVar1;
                    if (wVar3 != 0x3a) {
                      wVar3 = towupper(wVar3);
                      if (uVar10 == 0) goto LAB_140002679;
                      *pwVar1 = wVar3;
                      if (uVar10 < 2) goto LAB_140002679;
                      local_88 = uVar10 - 2;
                      pwVar1[1] = 0x3a;
                      if (local_88 == 0xffffffffffffffff) goto LAB_140002679;
                      pwStack_80 = pwVar1 + 2;
                      local_d8 = local_88;
                      pwStack_d0 = pwStack_80;
                    }
                    if (local_d8 == 0) goto LAB_140002679;
                    *pwStack_d0 = 0;
                    if (uVar11 < uVar13) goto LAB_140002679;
                    uVar11 = uVar11 - uVar13;
                    local_78 = uVar11;
                    if (uVar11 == 0xffffffffffffffff) goto LAB_140002679;
                    pwStack_e0 = (wint_t *)((longlong)pwStack_e0 + uVar13);
                    uVar14 = uVar5;
                    local_e8 = uVar11;
                    pwStack_70 = pwStack_e0;
                  }
                }
              }
            }
            lVar6 = RxPrefixTableLookupNextObject(&local_68);
          } while (lVar6 != 0);
          param_1 = local_res10;
        }
        **(uint **)(param_1 + 0x220) = uVar16;
        *(ulonglong *)(param_1 + 0xb8) = (ulonglong)uVar14;
        RxPrefixTableEndLookup(&local_68);
        if (uVar14 < uVar16) {
          if (p_Var2 != (_RX_PREFIX_TABLE *)0x0) {
            details::ReleasePrefixTableLock(p_Var2);
          }
          return -0x7ffffffb;
        }
        if (p_Var2 != (_RX_PREFIX_TABLE *)0x0) {
          details::ReleasePrefixTableLock(p_Var2);
        }
        return 0;
      }
LAB_140002679:
                    /* WARNING: Subroutine does not return */
      gsl::details::terminate();
    }
  }
  local_f8 = 0x193;
  local_108 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\device.cpp";
  pwStack_100 = (wint_t *)0x140016508;
  local_f0 = "%s";
  TraceLog((ErrorSite *)&local_108,-0x3fffffdd,
           "outputBuffer.size() < sizeof(P9RDR_ENUMERATE_CONNECTIONS_OUTPUT)");
  return -0x3fffffdd;
}



===== ExtractNetRootName @ 140002688 =====

/* public: static void __cdecl p9fs::Device::ExtractNetRootName(struct _UNICODE_STRING *
   __ptr64,struct _MRX_SRV_CALL_ * __ptr64,struct _UNICODE_STRING * __ptr64,struct _UNICODE_STRING *
   __ptr64) */

void __cdecl
p9fs::Device::ExtractNetRootName
          (_UNICODE_STRING *param_1,_MRX_SRV_CALL_ *param_2,_UNICODE_STRING *param_3,
          _UNICODE_STRING *param_4)

{
  short *psVar1;
  short *psVar2;
  ulonglong uVar3;
  short sVar4;
  ulonglong uVar5;
  undefined8 uStack_20;
  ulonglong local_18;
  undefined2 uStack_10;
  undefined2 uStack_e;
  undefined2 uStack_c;
  undefined2 uStack_a;
  
  uVar5 = (ulonglong)(**(ushort **)(param_2 + 0x40) >> 1);
  if ((*(longlong *)(*(ushort **)(param_2 + 0x40) + 4) != 0) || (uVar5 == 0)) {
    local_18 = (ulonglong)(*(ushort *)param_1 >> 1);
    if (((*(longlong *)(param_1 + 8) != 0) || (local_18 == 0)) && (uVar5 <= local_18)) {
      local_18 = local_18 - uVar5;
      if (local_18 != 0xffffffffffffffff) {
        uVar3 = 0;
        psVar1 = (short *)(*(longlong *)(param_1 + 8) + uVar5 * 2);
        if ((local_18 != 0) && (uVar3 = 0, *psVar1 == 0x5c)) {
          uVar3 = 1;
        }
        uStack_10 = 0;
        uStack_e = 0;
        uStack_c = 0;
        uStack_a = 0;
        for (; (uVar3 < local_18 && (psVar1[uVar3] != 0x5c)); uVar3 = uVar3 + 1) {
        }
        sVar4 = 0;
        if ((uVar3 != local_18) && (uVar3 != 0xffffffffffffffff)) {
          if ((local_18 < uVar3) || (local_18 - uVar3 == -1)) goto LAB_1400027c9;
          psVar2 = psVar1 + uVar3;
          local_18._0_2_ = (short)(local_18 - uVar3);
          uStack_10 = SUB82(psVar2,0);
          uStack_e = (undefined2)((ulonglong)psVar2 >> 0x10);
          uStack_c = (undefined2)((ulonglong)psVar2 >> 0x20);
          uStack_a = (undefined2)((ulonglong)psVar2 >> 0x30);
          sVar4 = (short)local_18;
          local_18 = uVar3;
        }
        *(ulonglong *)param_3 = (ulonglong)CONCAT22((short)local_18 * 2,(short)local_18 * 2);
        *(short **)(param_3 + 8) = psVar1;
        if (param_4 != (_UNICODE_STRING *)0x0) {
          uStack_20 = CONCAT26(uStack_a,CONCAT24(uStack_c,CONCAT22(uStack_e,uStack_10)));
          *(ulonglong *)param_4 = (ulonglong)CONCAT22(sVar4 * 2,sVar4 * 2);
          *(undefined8 *)(param_4 + 8) = uStack_20;
        }
        return;
      }
    }
  }
LAB_1400027c9:
                    /* WARNING: Subroutine does not return */
  gsl::details::terminate();
}



===== Find @ 1400027d8 =====

/* public: class p9fs::SharedPtr<class p9fs::ConnectionTarget> __cdecl
   p9fs::ConnectionTargetTree::Find(class p9fs::ConnectionTargetKey const & __ptr64) __ptr64 */

ConnectionTargetKey * __thiscall
p9fs::ConnectionTargetTree::Find(ConnectionTargetTree *this,ConnectionTargetKey *param_1)

{
  ConnectionTargetTree *pCVar1;
  longlong lVar2;
  ConnectionTargetTree CVar3;
  code *pcVar4;
  long lVar5;
  _RTL_BALANCED_NODE *p_Var6;
  _RTL_BALANCED_NODE *p_Var7;
  undefined1 *puVar8;
  void *in_R8;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  pCVar1 = this + 0x10;
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(pCVar1,0);
  puVar8 = auStack_38;
  CVar3 = this[8];
  p_Var7 = *(_RTL_BALANCED_NODE **)this;
  if (((byte)this[8] & 1) == 0) {
LAB_14000285f:
    while (p_Var7 != (_RTL_BALANCED_NODE *)0x0) {
      lVar5 = CompareNode(in_R8,p_Var7);
      if (lVar5 < 0) {
        p_Var6 = *(_RTL_BALANCED_NODE **)p_Var7;
      }
      else {
        if (lVar5 < 1) break;
        p_Var6 = *(_RTL_BALANCED_NODE **)(p_Var7 + 8);
      }
      if ((((byte)CVar3 & 1) == 0) || (p_Var6 == (_RTL_BALANCED_NODE *)0x0)) {
        p_Var7 = p_Var6;
      }
      else {
        p_Var7 = (_RTL_BALANCED_NODE *)((ulonglong)p_Var7 ^ (ulonglong)p_Var6);
      }
    }
    if (p_Var7 != (_RTL_BALANCED_NODE *)0x0) {
      *(_RTL_BALANCED_NODE **)param_1 = p_Var7 + -0x20;
      LOCK();
      p_Var7 = p_Var7 + 0xc0;
      lVar2 = *(longlong *)p_Var7;
      *(longlong *)p_Var7 = *(longlong *)p_Var7 + 1;
      UNLOCK();
      if (lVar2 + 1 < 2) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(0xe);
        puVar8 = auStack_30;
      }
      goto LAB_140002894;
    }
  }
  else if (p_Var7 != (_RTL_BALANCED_NODE *)0x0) {
    p_Var7 = (_RTL_BALANCED_NODE *)((ulonglong)p_Var7 ^ (ulonglong)this);
    goto LAB_14000285f;
  }
  *(undefined8 *)param_1 = 0;
  puVar8 = auStack_38;
LAB_140002894:
  if (pCVar1 != (ConnectionTargetTree *)0x0) {
    *(undefined8 *)(puVar8 + -8) = 0x1400028a5;
    ExReleasePushLockSharedEx(pCVar1,0);
    *(undefined8 *)(puVar8 + -8) = 0x1400028b1;
    KeLeaveCriticalRegion();
  }
  return param_1;
}



===== Insert @ 1400028dc =====

/* public: bool __cdecl p9fs::ConnectionTargetTree::Insert(class p9fs::ConnectionTarget & __ptr64)
   __ptr64 */

bool __thiscall
p9fs::ConnectionTargetTree::Insert(ConnectionTargetTree *this,ConnectionTarget *param_1)

{
  ConnectionTargetTree *pCVar1;
  ConnectionTargetTree *pCVar2;
  ConnectionTarget *pCVar3;
  longlong lVar4;
  ConnectionTargetTree CVar5;
  code *pcVar6;
  long lVar7;
  ConnectionTargetTree *pCVar8;
  _RTL_BALANCED_NODE *p_Var9;
  _RTL_BALANCED_NODE *p_Var10;
  undefined1 *puVar11;
  undefined1 uVar12;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  pCVar1 = this + 0x10;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(pCVar1,0);
  puVar11 = auStack_38;
  p_Var9 = *(_RTL_BALANCED_NODE **)this;
  pCVar2 = this + 8;
  CVar5 = *pCVar2;
  if (((byte)*pCVar2 & 1) == 0) {
LAB_140002937:
    if (p_Var9 != (_RTL_BALANCED_NODE *)0x0) {
      do {
        lVar7 = CompareNode(param_1,p_Var9);
        if (lVar7 < 0) {
          p_Var10 = *(_RTL_BALANCED_NODE **)p_Var9;
        }
        else {
          if (lVar7 < 1) break;
          p_Var10 = *(_RTL_BALANCED_NODE **)(p_Var9 + 8);
        }
        if ((((byte)CVar5 & 1) != 0) && (p_Var10 != (_RTL_BALANCED_NODE *)0x0)) {
          p_Var10 = (_RTL_BALANCED_NODE *)((ulonglong)p_Var9 ^ (ulonglong)p_Var10);
        }
        p_Var9 = p_Var10;
      } while (p_Var10 != (_RTL_BALANCED_NODE *)0x0);
      if (p_Var9 != (_RTL_BALANCED_NODE *)0x0) {
        if (pCVar1 != (ConnectionTargetTree *)0x0) {
          ExReleasePushLockExclusiveEx(pCVar1,0);
          KeLeaveCriticalRegion();
        }
        return false;
      }
    }
  }
  else if (p_Var9 != (_RTL_BALANCED_NODE *)0x0) {
    p_Var9 = (_RTL_BALANCED_NODE *)((ulonglong)p_Var9 ^ (ulonglong)this);
    goto LAB_140002937;
  }
  pCVar8 = this + 8;
  LOCK();
  pCVar3 = param_1 + 0xe0;
  lVar4 = *(longlong *)pCVar3;
  *(longlong *)pCVar3 = *(longlong *)pCVar3 + 1;
  UNLOCK();
  if (lVar4 + 1 < 2) {
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)(0xe);
    puVar11 = auStack_30;
  }
  CVar5 = *pCVar2;
  p_Var9 = *(_RTL_BALANCED_NODE **)this;
  if (((byte)*pCVar8 & 1) != 0) {
    if (p_Var9 == (_RTL_BALANCED_NODE *)0x0) {
LAB_140002a25:
      uVar12 = 0;
      goto LAB_140002a28;
    }
    p_Var9 = (_RTL_BALANCED_NODE *)((ulonglong)p_Var9 ^ (ulonglong)this);
  }
  uVar12 = 0;
  if (p_Var9 != (_RTL_BALANCED_NODE *)0x0) {
    do {
      *(undefined8 *)(puVar11 + -8) = 0x1400029ee;
      lVar7 = CompareNode(param_1,p_Var9);
      if (lVar7 < 0) {
        p_Var10 = *(_RTL_BALANCED_NODE **)p_Var9;
        if (((byte)CVar5 & 1) != 0) {
          if (p_Var10 == (_RTL_BALANCED_NODE *)0x0) goto LAB_140002a25;
          p_Var10 = (_RTL_BALANCED_NODE *)((ulonglong)p_Var10 ^ (ulonglong)p_Var9);
        }
        if (p_Var10 == (_RTL_BALANCED_NODE *)0x0) goto LAB_140002a25;
      }
      else {
        p_Var10 = *(_RTL_BALANCED_NODE **)(p_Var9 + 8);
        if (((byte)CVar5 & 1) != 0) {
          if (p_Var10 == (_RTL_BALANCED_NODE *)0x0) goto LAB_140002a07;
          p_Var10 = (_RTL_BALANCED_NODE *)((ulonglong)p_Var10 ^ (ulonglong)p_Var9);
        }
        if (p_Var10 == (_RTL_BALANCED_NODE *)0x0) goto LAB_140002a07;
      }
      p_Var9 = p_Var10;
    } while( true );
  }
LAB_140002a28:
  *(undefined8 *)(puVar11 + -8) = 0x140002a39;
  RtlRbInsertNodeEx(this,p_Var9,uVar12,param_1 + 0x20);
  if (pCVar1 != (ConnectionTargetTree *)0x0) {
    *(undefined8 *)(puVar11 + -8) = 0x140002a4f;
    ExReleasePushLockExclusiveEx(pCVar1,0);
    *(undefined8 *)(puVar11 + -8) = 0x140002a5b;
    KeLeaveCriticalRegion();
  }
  return true;
LAB_140002a07:
  uVar12 = 1;
  goto LAB_140002a28;
}



===== IsSupportedUser @ 140002a84 =====

/* private: long __cdecl p9fs::Device::IsSupportedUser(struct _SECURITY_SUBJECT_CONTEXT * __ptr64)
   __ptr64 */

long __thiscall p9fs::Device::IsSupportedUser(Device *this,_SECURITY_SUBJECT_CONTEXT *param_1)

{
  char cVar1;
  undefined8 uVar2;
  uint local_res10 [2];
  undefined4 local_res18 [2];
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  if (param_1 != (_SECURITY_SUBJECT_CONTEXT *)0x0) {
    local_res10[0] = 0;
    local_res18[0] = 0;
    uVar2 = IoGetFileObjectGenericMapping();
    cVar1 = SeAccessCheck(this + 0x368,param_1,1,0x1f01ff,0,0,uVar2,1,local_res18,local_res10);
    if (cVar1 == '\0') {
      local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\device.cpp";
      local_18 = 0x282;
      local_20 = "p9fs::Device::IsSupportedUser";
      local_10 = "P9: failed interactive user check 0x%x\n";
      TraceLog((ErrorSite *)&local_28,-0x3fffffff,(ulonglong)local_res10[0]);
      return local_res10[0];
    }
  }
  return 0;
}



===== Register @ 140002b60 =====

/* public: long __cdecl p9fs::Device::Register(struct _DRIVER_OBJECT * __ptr64,struct
   _MINIRDR_DISPATCH const & __ptr64) __ptr64 */

long __thiscall
p9fs::Device::Register(Device *this,_DRIVER_OBJECT *param_1,_MINIRDR_DISPATCH *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  _ACL *p_Var9;
  undefined8 *puVar10;
  long lVar11;
  undefined8 *puVar12;
  longlong lVar13;
  _MINIRDR_DISPATCH *p_Var14;
  Device *local_res8;
  char local_78 [8];
  _ACL *local_70;
  undefined8 local_68;
  _ACL *p_Stack_60;
  undefined8 local_58;
  undefined8 local_50;
  char *local_48;
  _ACL *p_Stack_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_58 = *(undefined8 *)(*(longlong *)SeExports_exref + 0x108);
  local_50 = *(undefined8 *)(*(longlong *)SeExports_exref + 0x110);
  p_Stack_60 = (_ACL *)&local_58;
  local_68 = 2;
  local_48 = (char *)0x2;
  local_res8 = this;
  p_Stack_40 = p_Stack_60;
  CreateAcl(local_78,&local_48);
  if (local_78[0] == '\0') {
    local_48 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\device.cpp";
    local_38 = 0x16;
    p_Stack_40 = (_ACL *)0x140016240;
    local_30 = 0;
    lVar11 = (long)local_70;
    TraceLog((ErrorSite *)&local_48,lVar11);
  }
  else {
    local_res8 = *(Device **)(*(longlong *)SeExports_exref + 0x100);
    p_Stack_40 = (_ACL *)&local_res8;
    local_48 = (char *)0x1;
    CreateAcl(&local_68,&local_48);
    if ((char)local_68 == '\0') {
      local_48 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\device.cpp";
      local_38 = 0x1b;
      p_Stack_40 = (_ACL *)0x140016240;
      local_30 = 0;
      lVar11 = (long)p_Stack_60;
      TraceLog((ErrorSite *)&local_48,lVar11);
    }
    else {
      lVar11 = CreateSecurityDescriptor(&DAT_14001a380,local_70);
      if (lVar11 < 0) {
        local_38 = 0x1e;
LAB_140002c9e:
        local_30 = 0;
        local_48 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\device.cpp";
        p_Stack_40 = (_ACL *)0x140016240;
        TraceLog((ErrorSite *)&local_48,lVar11);
        p_Var9 = p_Stack_60;
        if (((char)local_68 != '\0') && (p_Stack_60 = (_ACL *)0x0, p_Var9 != (_ACL *)0x0)) {
          ExFreePoolWithTag(p_Var9,0);
        }
        p_Var9 = local_70;
        if ((local_78[0] != '\0') && (local_70 = (_ACL *)0x0, p_Var9 != (_ACL *)0x0)) {
          ExFreePoolWithTag(p_Var9,0);
        }
        return lVar11;
      }
      lVar11 = CreateSecurityDescriptor(&DAT_14001a3a8,p_Stack_60);
      if (lVar11 < 0) {
        local_38 = 0x21;
        goto LAB_140002c9e;
      }
      lVar13 = 5;
      DAT_14001a370 = local_70;
      DAT_14001a378 = p_Stack_60;
      local_70 = (_ACL *)0x0;
      p_Stack_60 = (_ACL *)0x0;
      puVar10 = (undefined8 *)&DAT_14001a048;
      do {
        p_Var14 = param_2;
        puVar12 = puVar10;
        uVar5 = *(undefined8 *)(p_Var14 + 8);
        uVar6 = *(undefined8 *)(p_Var14 + 0x10);
        uVar7 = *(undefined8 *)(p_Var14 + 0x18);
        *puVar12 = *(undefined8 *)p_Var14;
        puVar12[1] = uVar5;
        uVar5 = *(undefined8 *)(p_Var14 + 0x20);
        uVar8 = *(undefined8 *)(p_Var14 + 0x28);
        puVar12[2] = uVar6;
        puVar12[3] = uVar7;
        uVar6 = *(undefined8 *)(p_Var14 + 0x30);
        uVar7 = *(undefined8 *)(p_Var14 + 0x38);
        puVar12[4] = uVar5;
        puVar12[5] = uVar8;
        uVar5 = *(undefined8 *)(p_Var14 + 0x40);
        uVar8 = *(undefined8 *)(p_Var14 + 0x48);
        puVar12[6] = uVar6;
        puVar12[7] = uVar7;
        uVar6 = *(undefined8 *)(p_Var14 + 0x50);
        uVar7 = *(undefined8 *)(p_Var14 + 0x58);
        puVar12[8] = uVar5;
        puVar12[9] = uVar8;
        uVar5 = *(undefined8 *)(p_Var14 + 0x60);
        uVar8 = *(undefined8 *)(p_Var14 + 0x68);
        puVar12[10] = uVar6;
        puVar12[0xb] = uVar7;
        uVar6 = *(undefined8 *)(p_Var14 + 0x70);
        uVar7 = *(undefined8 *)(p_Var14 + 0x78);
        puVar12[0xc] = uVar5;
        puVar12[0xd] = uVar8;
        puVar12[0xe] = uVar6;
        puVar12[0xf] = uVar7;
        lVar13 = lVar13 + -1;
        puVar10 = puVar12 + 0x10;
        param_2 = p_Var14 + 0x80;
      } while (lVar13 != 0);
      uVar5 = *(undefined8 *)(p_Var14 + 0x88);
      uVar6 = *(undefined8 *)(p_Var14 + 0x90);
      uVar7 = *(undefined8 *)(p_Var14 + 0x98);
      puVar12[0x10] = *(undefined8 *)(p_Var14 + 0x80);
      puVar12[0x11] = uVar5;
      uVar5 = *(undefined8 *)(p_Var14 + 0xa0);
      uVar8 = *(undefined8 *)(p_Var14 + 0xa8);
      puVar12[0x12] = uVar6;
      puVar12[0x13] = uVar7;
      uVar6 = *(undefined8 *)(p_Var14 + 0xb0);
      uVar7 = *(undefined8 *)(p_Var14 + 0xb8);
      puVar12[0x14] = uVar5;
      puVar12[0x15] = uVar8;
      uVar1 = *(undefined4 *)(p_Var14 + 0xc0);
      uVar2 = *(undefined4 *)(p_Var14 + 0xc4);
      uVar3 = *(undefined4 *)(p_Var14 + 200);
      uVar4 = *(undefined4 *)(p_Var14 + 0xcc);
      puVar12[0x16] = uVar6;
      puVar12[0x17] = uVar7;
      *(undefined4 *)(puVar12 + 0x18) = uVar1;
      *(undefined4 *)((longlong)puVar12 + 0xc4) = uVar2;
      *(undefined4 *)(puVar12 + 0x19) = uVar3;
      *(undefined4 *)((longlong)puVar12 + 0xcc) = uVar4;
      local_28 = 0;
      uStack_20 = 0;
      RtlInitUnicodeString(&local_28,L"\\Device\\P9Rdr");
      lVar11 = RxRegisterMinirdr(&GlobalDevice,param_1,&DAT_14001a048,0xc2,&local_28,0,0x14,0x10);
    }
    p_Var9 = p_Stack_60;
    if (((char)local_68 != '\0') && (p_Stack_60 = (_ACL *)0x0, p_Var9 != (_ACL *)0x0)) {
      ExFreePoolWithTag(p_Var9,0);
    }
  }
  p_Var9 = local_70;
  if ((local_78[0] != '\0') && (local_70 = (_ACL *)0x0, p_Var9 != (_ACL *)0x0)) {
    ExFreePoolWithTag(p_Var9,0);
  }
  return lVar11;
}



===== ReleasePrefixTableLock @ 140002e90 =====

/* void __cdecl p9fs::details::ReleasePrefixTableLock(struct _RX_PREFIX_TABLE * __ptr64) */

void __cdecl p9fs::details::ReleasePrefixTableLock(_RX_PREFIX_TABLE *param_1)

{
  ExReleaseResourceLite(param_1 + 0x18);
  KeLeaveCriticalRegion();
  return;
}



===== ReleaseReference @ 140002ebc =====

/* public: bool __cdecl p9fs::ConnectionTarget::ReleaseReference(void) __ptr64 */

bool __thiscall p9fs::ConnectionTarget::ReleaseReference(ConnectionTarget *this)

{
  ConnectionTarget *pCVar1;
  longlong lVar2;
  code *pcVar3;
  
  LOCK();
  pCVar1 = this + 0xe0;
  lVar2 = *(longlong *)pCVar1;
  *(longlong *)pCVar1 = *(longlong *)pCVar1 + -1;
  UNLOCK();
  if (lVar2 < 2) {
    if (lVar2 == 1) {
      if (this == (ConnectionTarget *)0x0) {
        return true;
      }
      ExFreePoolWithTag(this,0);
      return true;
    }
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(0xe);
  }
  return false;
}



===== Remove @ 140002f0c =====

/* public: bool __cdecl p9fs::ConnectionTargetTree::Remove(class p9fs::ConnectionTargetKey const &
   __ptr64) __ptr64 */

bool __thiscall
p9fs::ConnectionTargetTree::Remove(ConnectionTargetTree *this,ConnectionTargetKey *param_1)

{
  ConnectionTargetTree *pCVar1;
  ConnectionTargetTree CVar2;
  long lVar3;
  _RTL_BALANCED_NODE *p_Var4;
  _RTL_BALANCED_NODE *p_Var5;
  
  pCVar1 = this + 0x10;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(pCVar1,0);
  CVar2 = this[8];
  p_Var5 = *(_RTL_BALANCED_NODE **)this;
  if (((byte)this[8] & 1) != 0) {
    if (p_Var5 == (_RTL_BALANCED_NODE *)0x0) goto LAB_140002f9b;
    p_Var5 = (_RTL_BALANCED_NODE *)((ulonglong)p_Var5 ^ (ulonglong)this);
  }
  while (p_Var5 != (_RTL_BALANCED_NODE *)0x0) {
    lVar3 = CompareNode(param_1,p_Var5);
    if (lVar3 < 0) {
      p_Var4 = *(_RTL_BALANCED_NODE **)p_Var5;
    }
    else {
      if (lVar3 < 1) break;
      p_Var4 = *(_RTL_BALANCED_NODE **)(p_Var5 + 8);
    }
    if ((((byte)CVar2 & 1) == 0) || (p_Var4 == (_RTL_BALANCED_NODE *)0x0)) {
      p_Var5 = p_Var4;
    }
    else {
      p_Var5 = (_RTL_BALANCED_NODE *)((ulonglong)p_Var5 ^ (ulonglong)p_Var4);
    }
  }
  if (p_Var5 != (_RTL_BALANCED_NODE *)0x0) {
    RtlRbRemoveNode(this,p_Var5);
    ConnectionTarget::ReleaseReference((ConnectionTarget *)(p_Var5 + -0x20));
    if (pCVar1 != (ConnectionTargetTree *)0x0) {
      ExReleasePushLockExclusiveEx(pCVar1,0);
      KeLeaveCriticalRegion();
    }
    return true;
  }
LAB_140002f9b:
  if (pCVar1 != (ConnectionTargetTree *)0x0) {
    ExReleasePushLockExclusiveEx(pCVar1,0);
    KeLeaveCriticalRegion();
  }
  return false;
}



===== RemoveConnectionTarget @ 140003024 =====

/* public: long __cdecl p9fs::Device::RemoveConnectionTarget(struct _RX_CONTEXT * __ptr64) __ptr64
    */

long __thiscall p9fs::Device::RemoveConnectionTarget(Device *this,_RX_CONTEXT *param_1)

{
  uint uVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  bool bVar5;
  long lVar6;
  ulonglong *puVar7;
  ulonglong local_68;
  undefined8 *puStack_60;
  ulonglong local_48;
  ulonglong uStack_40;
  char *local_38;
  char *local_30;
  undefined8 local_28;
  char *local_20;
  
  lVar6 = CheckIoctlAccess(this);
  if (lVar6 < 0) {
    local_20 = (char *)0x0;
    local_38 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\device.cpp";
    local_30 = "p9fs::Device::RemoveConnectionTarget";
    local_28 = 0xb9;
    TraceLog((ErrorSite *)&local_38,lVar6);
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x228);
    if (7 < uVar1) {
      puVar2 = *(undefined8 **)(param_1 + 0x218);
      if (((puVar2 == (undefined8 *)0x0) || ((ulonglong)uVar1 < 8)) ||
         (local_68 = (ulonglong)uVar1 - 8, local_68 == 0xffffffffffffffff)) {
                    /* WARNING: Subroutine does not return */
        gsl::details::terminate();
      }
      puStack_60 = puVar2 + 1;
      if ((local_68 & 1) == 0) {
        puVar7 = (ulonglong *)ReinterpretSpan<unsigned_short,gsl::byte>(&local_38);
        uVar3 = *puVar7;
        uVar4 = puVar7[1];
        local_68 = uVar3;
        local_48 = uVar3;
        uStack_40 = uVar4;
        if ((uVar3 == 0xffffffffffffffff) ||
           ((uVar4 == 0 && (puStack_60 = (undefined8 *)0x0, uVar3 != 0)))) {
                    /* WARNING: Subroutine does not return */
          gsl::details::terminate();
        }
        local_28 = 0xce;
        local_20 = "P9: Removing connection target for \"%.*S\"\n";
        local_38 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\device.cpp";
        local_30 = "p9fs::Device::RemoveConnectionTarget";
        puStack_60 = (undefined8 *)uVar4;
        TraceLog((ErrorSite *)&local_38,0,uVar3 & 0xffffffff,uVar4);
        local_48 = local_68;
        uStack_40 = (ulonglong)puStack_60;
        ConnectionTargetKey::ConnectionTargetKey((ConnectionTargetKey *)&local_68,*puVar2,&local_48)
        ;
        bVar5 = ConnectionTargetTree::Remove
                          ((ConnectionTargetTree *)&DAT_14001a340,(ConnectionTargetKey *)&local_68);
        if (bVar5) {
          return 0;
        }
        local_38 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\device.cpp";
        local_20 = "P9: Connection target \"%.*S\" does not exist.\n";
        local_30 = "p9fs::Device::RemoveConnectionTarget";
        local_28 = 0xd2;
        TraceLog((ErrorSite *)&local_38,-0x3fffffff,uVar3 & 0xffffffff,uVar4);
        return -0x3fffffcc;
      }
      local_28 = 200;
      local_20 = "P9: Invalid share name in P9RDR_REMOVE_CONNECTION_TARGET_INPUT.";
      local_38 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\device.cpp";
      local_30 = "p9fs::Device::RemoveConnectionTarget";
      TraceLog((ErrorSite *)&local_38,-0x3fffffff);
    }
    lVar6 = -0x3ffffff3;
  }
  return lVar6;
}



===== default_terminate_handler @ 140003220 =====

/* void __cdecl gsl::details::default_terminate_handler(void) */

void __cdecl gsl::details::default_terminate_handler(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(0);
  return;
}



===== terminate @ 14000322c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl gsl::details::terminate(void) */

void __cdecl gsl::details::terminate(void)

{
  (*(code *)`void_(__cdecl*&___ptr64___cdecl_gsl::details::get_terminate_handler(void))(void)'::__l2
            ::handler)();
  return;
}



===== Feature_3131016505__private_IsEnabledDeviceUsageNoInline @ 140003248 =====

ulonglong Feature_3131016505__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)(uint)Feature_3131016505__private_featureState;
  if (((uint)Feature_3131016505__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3131016505__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)((uint)Feature_3131016505__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3131016505__private_IsEnabledFallback @ 140003280 =====

void Feature_3131016505__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&wil_details_featureDescriptors_a);
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 14000329c =====

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
LAB_14000349f:
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
LAB_140003377:
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
      if (param_3 == 4) goto LAB_14000349f;
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
        goto LAB_140003377;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140003588 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (longlong param_1,ulonglong param_2,int param_3)

{
  bool bVar1;
  undefined7 extraout_var;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  int local_res18 [4];
  
  uVar2 = (uint)param_2 & 1;
  if (param_3 != 0) {
    if (param_3 == 1) {
      uVar3 = (uVar2 ^ 1) << 2;
      goto LAB_140003659;
    }
    if (param_3 == 2) {
      uVar3 = (uVar2 ^ 1) * 4 + 1;
      goto LAB_140003659;
    }
    if (param_3 == 3) {
      uVar3 = (uVar2 ^ 1) * 4 + 2;
      goto LAB_140003659;
    }
    if (param_3 == 4) {
      uVar3 = (uVar2 ^ 1) * 4 + 3;
      goto LAB_140003659;
    }
    if (param_3 == 5) {
      uVar3 = (uVar2 ^ 1) * 2 + 8;
      goto LAB_140003659;
    }
    if (param_3 == 6) {
      uVar3 = (uVar2 ^ 1) * 2 + 9;
      goto LAB_140003659;
    }
    bVar4 = (char)param_3 + 0x9c;
    if (bVar4 < 0x32) {
      uVar3 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar4;
      goto LAB_140003659;
    }
  }
  uVar3 = 0xff;
LAB_140003659:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(param_1,param_2,uVar3);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (*(undefined4 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x10),0,uVar2,local_res18,0
               ,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 1400036b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (longlong param_1,undefined8 param_2,uint param_3)

{
  uint6 uVar1;
  uint *puVar2;
  undefined1 auStack_98 [32];
  uint *local_78;
  undefined8 local_68;
  uint local_60 [6];
  uint local_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_98;
  puVar2 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_60,*(uint **)(param_1 + 8),param_3,(uint)((ulonglong)param_2 >> 0x20));
  local_48 = *puVar2;
  uStack_44 = puVar2[1];
  uStack_40 = puVar2[2];
  uStack_3c = puVar2[3];
  local_38 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_78 = &local_48;
    (*g_wil_details_recordFeatureUsage)
              (*(undefined4 *)(param_1 + 0x18),param_3,1,*(undefined8 *)(param_1 + 8));
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_68._0_6_ = CONCAT24((short)param_3,*(undefined4 *)(param_1 + 0x18));
    uVar1 = (uint6)local_68;
    local_68 = (ulonglong)(uint6)local_68;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_68 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_68);
  }
  return (int)local_38 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 1400037a0 =====

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
LAB_140003853:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_140003881;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_140003853;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_140003881:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140003a0c =====

void wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath
               (uint param_1,int param_2,undefined8 *param_3)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  puVar2 = (uint *)*param_3;
  if (param_2 == 3) {
    uVar4 = 0x10;
  }
  else {
    if (param_2 != 4) {
      return;
    }
    uVar4 = 0x20;
  }
  if ((*(char *)((longlong)param_3 + 0x1e) == '\0') && (*(char *)((longlong)param_3 + 0x1d) == '\0')
     ) {
    uVar3 = *puVar2;
    if ((uVar3 & 2) != 0) {
      while ((uVar3 & 1) == (param_1 & 1)) {
        LOCK();
        uVar1 = *puVar2;
        bVar5 = uVar3 == uVar1;
        if (bVar5) {
          *puVar2 = uVar4 | uVar3;
        }
        else {
          uVar3 = uVar1;
        }
        UNLOCK();
        if (bVar5) {
          return;
        }
        if ((uVar3 & 2) == 0) {
          return;
        }
      }
    }
  }
  else {
    LOCK();
    *puVar2 = *puVar2 | uVar4;
    UNLOCK();
  }
  return;
}



===== wil_details_IsEnabledFallback @ 140003a70 =====

uint wil_details_IsEnabledFallback(ulonglong param_1,int param_2,undefined8 *param_3)

{
  ulonglong local_res8;
  
  local_res8 = param_1 & 0xffffffff;
  if ((param_1 & 2) == 0) {
    local_res8 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                           ((uint *)*param_3,param_1,(longlong)param_3);
    param_1 = local_res8 & 0xffffffff;
  }
  if ((param_2 != 0) &&
     (wil_details_FeatureReporting_ReportUsageToService((longlong)param_3,local_res8,param_2),
     param_2 - 3U < 2)) {
    wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath((uint)local_res8,param_2,param_3);
  }
  return (uint)param_1 & 1;
}



===== <lambda_invoker_cdecl><void_*> @ 140003b10 =====

void <lambda_9e1816bf46d92e332471f74ea94ec544>::<lambda_invoker_cdecl><void_*>(Session *param_1)

{
  p9fs::Session::Disconnect(param_1);
  if (param_1 != (Session *)0x0) {
    p9fs::Session::~Session(param_1);
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== ~DirectoryEnumerator @ 140003b4c =====

/* public: __cdecl p9fs::DirectoryEnumerator::~DirectoryEnumerator(void) __ptr64 */

void __thiscall p9fs::DirectoryEnumerator::~DirectoryEnumerator(DirectoryEnumerator *this)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(this + 0x28);
  *(undefined8 *)(this + 0x28) = 0;
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0);
  }
  lVar1 = *(longlong *)(this + 0x18);
  *(undefined8 *)(this + 0x18) = 0;
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0);
  }
  lVar1 = *(longlong *)(this + 8);
  *(undefined8 *)(this + 8) = 0;
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0);
  }
  return;
}



===== DriverUnload @ 140003bc0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl p9fs::DriverUnload(struct _DRIVER_OBJECT * __ptr64) */

void __cdecl p9fs::DriverUnload(_DRIVER_OBJECT *param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  
  lVar2 = RxCreateRxContext(0,_GlobalDevice,0x200);
  if (lVar2 != 0) {
    KeEnterCriticalRegion();
    RxStopMinirdr(lVar2,lVar2 + 0x23);
    KeLeaveCriticalRegion();
    RxDereferenceAndDeleteRxContext_Real(lVar2);
  }
  if (_GlobalDevice != 0) {
    RxUnregisterMinirdr();
    _GlobalDevice = 0;
  }
  if (DAT_14001a370 != 0) {
    ExFreePoolWithTag(DAT_14001a370,0);
    DAT_14001a370 = 0;
  }
  if (DAT_14001a378 != 0) {
    ExFreePoolWithTag(DAT_14001a378,0);
    DAT_14001a378 = 0;
  }
  ConnectionTargetTree::Clear((ConnectionTargetTree *)&DAT_14001a340);
  uVar1 = DAT_14001a028;
  DAT_14001a028 = 0;
  DAT_14001a008 = 0;
  EtwUnregister(uVar1);
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



===== InitializeDispatchTable @ 140003d0c =====

/* struct _MINIRDR_DISPATCH __cdecl p9fs::InitializeDispatchTable(void) */

void __cdecl p9fs::InitializeDispatchTable(void)

{
  undefined4 *in_RCX;
  
  memset(in_RCX,0,0x2d0);
  *in_RCX = 0x2d0ebff;
  in_RCX[1] = 7;
  *(code **)(in_RCX + 6) = P9Start;
  *(code **)(in_RCX + 8) = P9Stop;
  *(code **)(in_RCX + 0x8c) = P9DevFcbXXXControlFile;
  *(code **)(in_RCX + 0x86) = P9CreateSrvCall;
  *(code **)(in_RCX + 0x68) = P9CreateVNetRoot;
  *(code **)(in_RCX + 0x7a) = P9ExtractNetRootName;
  *(code **)(in_RCX + 0x8a) = P9FinalizeNetRoot;
  *(code **)(in_RCX + 0x76) = P9FinalizeNetRoot;
  *(code **)(in_RCX + 0x74) = P9FinalizeVNetRoot;
  *(code **)(in_RCX + 0xe) = P9Create;
  *(code **)(in_RCX + 0x12) = P9CheckForCollapsibleOpen;
  *(code **)(in_RCX + 0x1a) = P9CleanupFobx;
  *(code **)(in_RCX + 0x1c) = P9CloseSrvOpen;
  *(code **)(in_RCX + 0x28) = P9ForceClosed;
  *(code **)(in_RCX + 0x20) = P9FinalizeNetRoot;
  *(code **)(in_RCX + 0x24) = P9FinalizeNetRoot;
  *(code **)(in_RCX + 0x22) = P9FinalizeNetRoot;
  *(code **)(in_RCX + 0x62) = P9ExtendFile;
  *(code **)(in_RCX + 100) = P9ExtendFile;
  *(code **)(in_RCX + 0x16) = P9Flush;
  *(code **)(in_RCX + 0x30) = P9QueryDirectoryInfo;
  *(code **)(in_RCX + 0x44) = P9QueryVolumeInfo;
  *(code **)(in_RCX + 0x32) = P9QueryFileInfo;
  *(code **)(in_RCX + 0x34) = P9SetFileInfo;
  *(code **)(in_RCX + 0x48) = P9IsValidDirectory;
  *(code **)(in_RCX + 0x4c) = P9Read;
  *(code **)(in_RCX + 0x4e) = P9Write;
  *(code **)(in_RCX + 0x46) = P9NotImplemented;
  *(code **)(in_RCX + 0x3c) = P9NotImplemented;
  *(code **)(in_RCX + 0x36) = P9NotImplemented;
  *(code **)(in_RCX + 0x50) = P9NotImplemented;
  *(code **)(in_RCX + 0x52) = P9NotImplemented;
  *(code **)(in_RCX + 0x54) = P9NotImplemented;
  *(code **)(in_RCX + 0x56) = P9NotImplemented;
  *(code **)(in_RCX + 0x58) = P9NotImplemented;
  *(code **)(in_RCX + 0x5a) = P9NotImplemented;
  *(code **)(in_RCX + 0x5c) = P9NotImplemented;
  return;
}



===== P9CheckForCollapsibleOpen @ 140003f00 =====

/* long __cdecl p9fs::P9CheckForCollapsibleOpen(struct _RX_CONTEXT * __ptr64) */

long __cdecl p9fs::P9CheckForCollapsibleOpen(_RX_CONTEXT *param_1)

{
  return -0x3ffffddb;
}



===== P9CleanupFobx @ 140003f10 =====

/* long __cdecl p9fs::P9CleanupFobx(struct _RX_CONTEXT * __ptr64) */

long __cdecl p9fs::P9CleanupFobx(_RX_CONTEXT *param_1)

{
  DirectoryEnumerator *this;
  
  this = *(DirectoryEnumerator **)(*(longlong *)(param_1 + 0x40) + 0x38);
  if (this != (DirectoryEnumerator *)0x0) {
    DirectoryEnumerator::~DirectoryEnumerator(this);
    ExFreePoolWithTag(this,0);
  }
  *(undefined8 *)(*(longlong *)(param_1 + 0x40) + 0x38) = 0;
  return 0;
}



===== P9CloseSrvOpen @ 140003f60 =====

/* long __cdecl p9fs::P9CloseSrvOpen(struct _RX_CONTEXT * __ptr64) */

long __cdecl p9fs::P9CloseSrvOpen(_RX_CONTEXT *param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  undefined **local_68;
  _RX_CONTEXT *local_60;
  undefined8 local_58;
  char *local_50;
  char *local_48;
  char *local_40;
  undefined8 local_38;
  char *local_30;
  
  uVar3 = *(uint *)(*(longlong *)(param_1 + 0x48) + 0x30);
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x48) + 0x28) + 0x28);
  uVar2 = 0;
  if (uVar3 != 0xffffffff) {
    uVar2 = 0;
    if ((*(int *)(*(longlong *)(param_1 + 0x38) + 0xc0) == 0) &&
       ((*(uint *)(*(longlong *)(param_1 + 0x38) + 0x9c) & 1) != 0)) {
      uVar2 = RxSetMinirdrCancelRoutine(param_1,Session::CancelRxContext);
      if ((int)uVar2 < 0) {
        local_68 = (undefined **)0x140016c60;
        local_50 = "P9: Failed to set cancellation routine for delete: 0x%x\n";
        local_60 = (_RX_CONTEXT *)0x140016f70;
        local_58 = 0x236;
        TraceLog((ErrorSite *)&local_68,-0x3fffffff,(ulonglong)uVar2);
      }
      else {
        local_68 = &Session::ContextCancellationManager::_vftable_;
        local_60 = param_1;
        uVar2 = P9Client::Remove((P9Client *)(lVar1 + 0x50),uVar3,(ICancellationManager *)&local_68)
        ;
        if ((int)uVar2 < 0) {
          local_48 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\session.cpp";
          local_30 = "P9: Failed to delete file: 0x%x\n";
          local_40 = "p9fs::Session::CloseSrvOpen";
          local_38 = 0x23e;
          TraceLog((ErrorSite *)&local_48,-0x3fffffff,(ulonglong)uVar2);
        }
        local_68 = &Session::ContextCancellationManager::_vftable_;
      }
    }
    local_48 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\session.cpp";
    local_30 = "P9: Close fid = %d\n";
    local_40 = "p9fs::Session::CloseSrvOpen";
    local_38 = 0x244;
    TraceLog((ErrorSite *)&local_48,0,(ulonglong)uVar3);
    uVar3 = P9Client::Clunk((P9Client *)(lVar1 + 0x50),uVar3);
    if ((int)uVar3 < 0) {
      local_48 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\session.cpp";
      local_40 = "p9fs::Session::CloseSrvOpen";
      local_38 = 0x245;
      local_30 = (char *)0x0;
      TraceLog((ErrorSite *)&local_48,uVar3);
      uVar2 = uVar3;
    }
    else {
      *(undefined8 *)(*(longlong *)(param_1 + 0x48) + 0x30) = 0xffffffff;
    }
  }
  return uVar2;
}



===== P9Create @ 140004110 =====

/* long __cdecl p9fs::P9Create(struct _RX_CONTEXT * __ptr64) */

long __cdecl p9fs::P9Create(_RX_CONTEXT *param_1)

{
  long lVar1;
  
  lVar1 = Session::Create(*(Session **)(*(longlong *)(*(longlong *)(param_1 + 0x48) + 0x28) + 0x28),
                          param_1);
  return lVar1;
}



===== P9CreateSrvCall @ 140004140 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl p9fs::P9CreateSrvCall(struct _MRX_SRV_CALL_ * __ptr64,struct
   _MRX_SRVCALL_CALLBACK_CONTEXT * __ptr64) */

long __cdecl p9fs::P9CreateSrvCall(_MRX_SRV_CALL_ *param_1,_MRX_SRVCALL_CALLBACK_CONTEXT *param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = RtlEqualUnicodeString(*(undefined8 *)(param_1 + 0x40),&DAT_140016070,1);
  uVar2 = 0;
  if (cVar1 == '\0') {
    cVar1 = RtlEqualUnicodeString(*(undefined8 *)(param_1 + 0x40),&DAT_140016060,1);
    if (cVar1 == '\0') {
      uVar2 = 0xc00000be;
      goto LAB_1400041a1;
    }
  }
  *(undefined4 *)(param_1 + 0x60) = 6;
LAB_1400041a1:
  *(undefined4 *)(param_2 + 0x118) = uVar2;
  (**(code **)(param_2 + 0x110))(param_2);
  return 0x103;
}



===== P9CreateVNetRoot @ 1400041e0 =====

/* long __cdecl p9fs::P9CreateVNetRoot(struct _MRX_CREATENETROOT_CONTEXT * __ptr64) */

long __cdecl p9fs::P9CreateVNetRoot(_MRX_CREATENETROOT_CONTEXT *param_1)

{
  Device::CreateNetRootAndVNetRoot((Device *)param_1,param_1,true);
  return 0x103;
}



===== P9FinalizeNetRoot @ 140004200 =====

/* long __cdecl p9fs::P9FinalizeNetRoot(struct _MRX_NET_ROOT_ * __ptr64,unsigned char * __ptr64) */

long __cdecl p9fs::P9FinalizeNetRoot(_MRX_NET_ROOT_ *param_1,uchar *param_2)

{
  return 0;
}



===== P9DevFcbXXXControlFile @ 140004210 =====

/* long __cdecl p9fs::P9DevFcbXXXControlFile(struct _RX_CONTEXT * __ptr64) */

long __cdecl p9fs::P9DevFcbXXXControlFile(_RX_CONTEXT *param_1)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 uVar5;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  if (param_1[0x20] == (_RX_CONTEXT)0xd) {
    if (*(int *)(param_1 + 0x20c) == 0x140007) {
      if ((*(uint *)(param_1 + 0x78) & 2) == 0) {
LAB_1400043b0:
        param_1[0x23] = (_RX_CONTEXT)0x1;
        return -0x3fbefffd;
      }
      lVar4 = *(longlong *)(param_1 + 0x48);
      if (lVar4 != 0) {
        uVar5 = 0xff;
LAB_1400043d1:
        lVar2 = RxFinalizeConnection
                          (*(undefined8 *)(*(longlong *)(lVar4 + 0x28) + 0x20),
                           *(longlong *)(lVar4 + 0x28),uVar5);
        return lVar2;
      }
    }
    else if (*(int *)(param_1 + 0x20c) == 0x14000b) {
      if ((*(uint *)(param_1 + 0x78) & 2) == 0) goto LAB_1400043b0;
      lVar4 = *(longlong *)(param_1 + 0x48);
      if (lVar4 != 0) {
        uVar5 = 1;
        goto LAB_1400043d1;
      }
    }
  }
  else if (param_1[0x20] == (_RX_CONTEXT)0xe) {
    iVar1 = *(int *)(param_1 + 0x20c);
    if (iVar1 == 0x220007) {
      lVar2 = RxStartMinirdr(param_1,param_1 + 0x23);
      if (lVar2 != -0x3fbefffd) {
        uVar3 = ZwUpdateWnfStateData(&WNF_9P_REDIRECTOR_STARTED,0,0,0,0,0,0);
        if ((int)uVar3 < 0) {
          local_18 = 0x66;
          local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\device.cpp";
          local_20 = "p9fs::Device::Start";
          local_10 = "P9: Failed to publish start notification: 0x%x\n";
          TraceLog((ErrorSite *)&local_28,-0x3fffffff,(ulonglong)uVar3);
        }
      }
    }
    else {
      if (iVar1 == 0x220008) {
        lVar2 = Device::AddConnectionTarget((Device *)param_1,param_1);
        return lVar2;
      }
      if (iVar1 == 0x22000c) {
        lVar2 = Device::RemoveConnectionTarget((Device *)param_1,param_1);
        return lVar2;
      }
      if (iVar1 != 0x220013) {
        if (iVar1 == 0x220014) {
          lVar2 = UserCallbackManager::RegisterUserCallback
                            ((UserCallbackManager *)&PTR_LOOP_14001a358,param_1);
          return lVar2;
        }
        if (iVar1 == 0x220018) {
          lVar2 = Device::EnumerateConnections((Device *)param_1,param_1);
          return lVar2;
        }
        return -0x3ffffff0;
      }
      lVar2 = Device::CheckIoctlAccess((Device *)param_1);
      if (lVar2 < 0) {
        local_10 = (char *)0x0;
        local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\device.cpp";
        local_18 = 0xe2;
        local_20 = "p9fs::Device::ClearConnectionTargets";
        TraceLog((ErrorSite *)&local_28,lVar2);
      }
      else {
        ConnectionTargetTree::Clear((ConnectionTargetTree *)&DAT_14001a340);
        lVar2 = 0;
      }
    }
    return lVar2;
  }
  return -0x3ffffff0;
}



===== P9ExtendFile @ 140004400 =====

/* long __cdecl p9fs::P9ExtendFile(struct _RX_CONTEXT * __ptr64,union _LARGE_INTEGER * __ptr64,union
   _LARGE_INTEGER * __ptr64) */

long __cdecl
p9fs::P9ExtendFile(_RX_CONTEXT *param_1,_LARGE_INTEGER *param_2,_LARGE_INTEGER *param_3)

{
  *(undefined8 *)param_3 = *(undefined8 *)param_2;
  return 0;
}



===== P9ExtractNetRootName @ 140004410 =====

/* void __cdecl p9fs::P9ExtractNetRootName(struct _UNICODE_STRING * __ptr64,struct _MRX_SRV_CALL_ *
   __ptr64,struct _UNICODE_STRING * __ptr64,struct _UNICODE_STRING * __ptr64) */

void __cdecl
p9fs::P9ExtractNetRootName
          (_UNICODE_STRING *param_1,_MRX_SRV_CALL_ *param_2,_UNICODE_STRING *param_3,
          _UNICODE_STRING *param_4)

{
  Device::ExtractNetRootName(param_1,param_2,param_3,param_4);
  return;
}



===== P9FinalizeVNetRoot @ 140004430 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* long __cdecl p9fs::P9FinalizeVNetRoot(struct _MRX_V_NET_ROOT_ * __ptr64,unsigned char * __ptr64)
    */

long __cdecl p9fs::P9FinalizeVNetRoot(_MRX_V_NET_ROOT_ *param_1,uchar *param_2)

{
  Session *this;
  uint uVar1;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  this = *(Session **)(param_1 + 0x28);
  if (this != (Session *)0x0) {
    *(undefined8 *)(param_1 + 0x28) = 0;
    uVar1 = RxDispatchToWorkerThread
                      (_GlobalDevice,4,
                       <lambda_9e1816bf46d92e332471f74ea94ec544>::<lambda_invoker_cdecl><void_*>,
                       this);
    if ((int)uVar1 < 0) {
      local_18 = 0x15e;
      local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\p9rdr.cpp";
      local_20 = "p9fs::P9FinalizeVNetRoot";
      local_10 = "P9: Could not dispatch for graceful disconnect: 0x%x\n";
      TraceLog((ErrorSite *)&local_28,-0x3fffffff,(ulonglong)uVar1);
      Session::~Session(this);
      ExFreePoolWithTag(this,0);
    }
  }
  return 0;
}



===== P9Flush @ 1400044e0 =====

/* long __cdecl p9fs::P9Flush(struct _RX_CONTEXT * __ptr64) */

long __cdecl p9fs::P9Flush(_RX_CONTEXT *param_1)

{
  uint uVar1;
  longlong lVar2;
  long lVar3;
  undefined **local_18;
  _RX_CONTEXT *local_10;
  
  lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x48) + 0x28) + 0x28);
  uVar1 = *(uint *)(param_1 + 0x78);
  if ((uVar1 >> 0xc & 1) != 0) {
    if ((uVar1 & 2) == 0) {
      param_1[0x23] = (_RX_CONTEXT)0x1;
      return -0x3fbefffd;
    }
    *(uint *)(param_1 + 0x78) = uVar1 & 0xffffefff;
  }
  local_18 = &Session::ContextCancellationManager::_vftable_;
  local_10 = param_1;
  lVar3 = P9Client::Fsync((P9Client *)(lVar2 + 0x50),*(uint *)(*(longlong *)(param_1 + 0x48) + 0x30)
                          ,(ICancellationManager *)&local_18);
  return lVar3;
}



===== P9ForceClosed @ 140004540 =====

/* long __cdecl p9fs::P9ForceClosed(struct _MRX_SRV_OPEN_ * __ptr64) */

long __cdecl p9fs::P9ForceClosed(_MRX_SRV_OPEN_ *param_1)

{
  return -0x3ffffffe;
}



===== P9IsValidDirectory @ 140004550 =====

/* long __cdecl p9fs::P9IsValidDirectory(struct _RX_CONTEXT * __ptr64,struct _UNICODE_STRING *
   __ptr64) */

long __cdecl p9fs::P9IsValidDirectory(_RX_CONTEXT *param_1,_UNICODE_STRING *param_2)

{
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  local_18 = 0x174;
  local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\p9rdr.cpp";
  local_20 = "p9fs::P9IsValidDirectory";
  local_10 = "P9: P9IsValidDirectory not implemented\n";
  TraceLog((ErrorSite *)&local_28,-0x3fffffff);
  return -0x3ffffffe;
}



===== P9NotImplemented @ 1400045a0 =====

/* long __cdecl p9fs::P9NotImplemented(struct _RX_CONTEXT * __ptr64) */

long __cdecl p9fs::P9NotImplemented(_RX_CONTEXT *param_1)

{
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\p9rdr.cpp";
  local_18 = 0x17b;
  local_20 = "p9fs::P9NotImplemented";
  local_10 = "P9: Not implemented: %d\n";
  TraceLog((ErrorSite *)&local_28,-0x3fffffff,(ulonglong)(byte)param_1[0x20]);
  return -0x3ffffffe;
}



===== P9QueryDirectoryInfo @ 140004600 =====

/* long __cdecl p9fs::P9QueryDirectoryInfo(struct _RX_CONTEXT * __ptr64) */

long __cdecl p9fs::P9QueryDirectoryInfo(_RX_CONTEXT *param_1)

{
  long lVar1;
  
  lVar1 = Session::QueryDirectoryInfo
                    (*(Session **)(*(longlong *)(*(longlong *)(param_1 + 0x48) + 0x28) + 0x28),
                     param_1);
  if ((lVar1 == -0x7ffffffa) &&
     ((param_1[0x1f7] != (_RX_CONTEXT)0x0 || (param_1[500] != (_RX_CONTEXT)0x0)))) {
    lVar1 = -0x3ffffff1;
  }
  return lVar1;
}



===== P9QueryFileInfo @ 140004650 =====

/* long __cdecl p9fs::P9QueryFileInfo(struct _RX_CONTEXT * __ptr64) */

long __cdecl p9fs::P9QueryFileInfo(_RX_CONTEXT *param_1)

{
  long lVar1;
  
  lVar1 = Session::QueryFileInfo
                    (*(Session **)(*(longlong *)(*(longlong *)(param_1 + 0x48) + 0x28) + 0x28),
                     param_1);
  return lVar1;
}



===== P9QueryVolumeInfo @ 140004680 =====

/* long __cdecl p9fs::P9QueryVolumeInfo(struct _RX_CONTEXT * __ptr64) */

long __cdecl p9fs::P9QueryVolumeInfo(_RX_CONTEXT *param_1)

{
  long lVar1;
  
  lVar1 = Session::QueryVolumeInfo
                    (*(Session **)(*(longlong *)(*(longlong *)(param_1 + 0x48) + 0x28) + 0x28),
                     param_1);
  return lVar1;
}



===== P9Read @ 1400046b0 =====

/* long __cdecl p9fs::P9Read(struct _RX_CONTEXT * __ptr64) */

long __cdecl p9fs::P9Read(_RX_CONTEXT *param_1)

{
  Session *this;
  int iVar1;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  this = *(Session **)(*(longlong *)(*(longlong *)(param_1 + 0x48) + 0x28) + 0x28);
  iVar1 = RxSetMinirdrCancelRoutine(param_1,Session::CancelRxContext);
  if (iVar1 < 0) {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\session.cpp";
    local_18 = 0x169;
    local_20 = "p9fs::Session::Read";
    TraceLog((ErrorSite *)&local_28,iVar1);
  }
  else {
    *(undefined4 *)(param_1 + 0xd8) = 0;
    iVar1 = Session::ReadWorker(this,param_1);
  }
  return iVar1;
}



===== P9SetFileInfo @ 140004750 =====

/* long __cdecl p9fs::P9SetFileInfo(struct _RX_CONTEXT * __ptr64) */

long __cdecl p9fs::P9SetFileInfo(_RX_CONTEXT *param_1)

{
  long lVar1;
  
  lVar1 = Session::SetFileInfo
                    (*(Session **)(*(longlong *)(*(longlong *)(param_1 + 0x48) + 0x28) + 0x28),
                     param_1);
  return lVar1;
}



===== P9Start @ 140004780 =====

/* long __cdecl p9fs::P9Start(struct _RX_CONTEXT * __ptr64,struct _RDBSS_DEVICE_OBJECT * __ptr64) */

long __cdecl p9fs::P9Start(_RX_CONTEXT *param_1,_RDBSS_DEVICE_OBJECT *param_2)

{
  int iVar1;
  undefined8 local_38;
  _WSK_CLIENT_DISPATCH *local_30;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_38 = 0;
  local_30 = &WskRegistration::s_Dispatch;
  iVar1 = WskRegister(&local_38,&DAT_14001a318);
  if (iVar1 < 0) {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\wsktransport.cpp";
    local_18 = 0x74;
    local_20 = "p9fs::WskRegistration::Register";
    TraceLog((ErrorSite *)&local_28,iVar1);
  }
  else {
    iVar1 = WskCaptureProviderNPI(&DAT_14001a318,0xffffffff,&DAT_14001a330);
  }
  return iVar1;
}



===== P9Stop @ 140004820 =====

/* long __cdecl p9fs::P9Stop(struct _RX_CONTEXT * __ptr64,struct _RDBSS_DEVICE_OBJECT * __ptr64) */

long __cdecl p9fs::P9Stop(_RX_CONTEXT *param_1,_RDBSS_DEVICE_OBJECT *param_2)

{
  UserCallback *this;
  undefined8 ***pppuVar1;
  undefined8 ***local_18;
  undefined8 ***pppuStack_10;
  
  pppuStack_10 = (undefined8 ***)0x0;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&DAT_14001a368,0);
  if ((undefined **)PTR_LOOP_14001a358 == &PTR_LOOP_14001a358) {
    pppuStack_10 = &local_18;
    local_18 = &local_18;
  }
  else {
    local_18 = (undefined8 ***)PTR_LOOP_14001a358;
    pppuStack_10 = (undefined8 ***)PTR_LOOP_14001a360;
    *(undefined8 *****)(PTR_LOOP_14001a358 + 8) = &local_18;
    *(undefined8 *****)PTR_LOOP_14001a360 = &local_18;
    PTR_LOOP_14001a360 = (undefined *)&PTR_LOOP_14001a358;
    PTR_LOOP_14001a358 = (undefined *)&PTR_LOOP_14001a358;
  }
  ExReleasePushLockExclusiveEx(&DAT_14001a368,0);
  KeLeaveCriticalRegion();
  for (pppuVar1 = local_18; (undefined8 ****)pppuVar1 != &local_18;
      pppuVar1 = (undefined8 ***)*pppuVar1) {
    this = (UserCallback *)(pppuVar1 + -4);
    if (pppuVar1[-3] != (undefined8 **)0x0) {
      UserCallback::CompleteRequest(this,-0x3ffffee0,0);
    }
    UserCallback::CancelWaiters(this);
    UserCallback::ReleaseReference(this);
  }
  ConnectionTargetTree::Clear((ConnectionTargetTree *)&DAT_14001a340);
  WskReleaseProviderNPI(&DAT_14001a318);
  WskDeregister(&DAT_14001a318);
  return 0;
}



===== P9Write @ 140004960 =====

/* long __cdecl p9fs::P9Write(struct _RX_CONTEXT * __ptr64) */

long __cdecl p9fs::P9Write(_RX_CONTEXT *param_1)

{
  Session *this;
  int iVar1;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  this = *(Session **)(*(longlong *)(*(longlong *)(param_1 + 0x48) + 0x28) + 0x28);
  iVar1 = RxSetMinirdrCancelRoutine(param_1,Session::CancelRxContext);
  if (iVar1 < 0) {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\session.cpp";
    local_18 = 0x1ca;
    local_20 = "p9fs::Session::Write";
    TraceLog((ErrorSite *)&local_28,iVar1);
  }
  else {
    *(undefined4 *)(param_1 + 0xd8) = 0;
    iVar1 = Session::WriteWorker(this,param_1);
  }
  return iVar1;
}



===== DriverEntry @ 1400049fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long DriverEntry(_DRIVER_OBJECT *param_1)

{
  undefined2 uVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  int iVar7;
  long lVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  Device *pDVar11;
  Device *this;
  longlong lVar12;
  undefined1 *puVar13;
  undefined1 auStack_5e8 [8];
  undefined1 auStack_5e0 [1464];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  ulonglong local_18;
  
  puVar13 = auStack_5e8;
  local_18 = __security_cookie ^ (ulonglong)auStack_5e8;
  lVar12 = 5;
  local_28 = *(undefined4 *)(PTR_DAT_14001a010 + -0x10);
  uStack_24 = *(undefined4 *)(PTR_DAT_14001a010 + -0xc);
  uStack_20 = *(undefined4 *)(PTR_DAT_14001a010 + -8);
  uStack_1c = *(undefined4 *)(PTR_DAT_14001a010 + -4);
  if (DAT_14001a028 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar13 = auStack_5e0;
  }
  _DAT_14001a030 = 0;
  uRam000000014001a038 = 0;
  *(undefined8 *)(puVar13 + -8) = 0x140004a73;
  iVar7 = EtwRegister(puVar13 + 0x5c0,_tlgEnableCallback,&DAT_14001a008,&DAT_14001a028);
  if (iVar7 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_14001a010;
    *(undefined8 *)(puVar13 + -8) = 0x140004a98;
    EtwSetInformation(DAT_14001a028,2,PTR_DAT_14001a010,uVar1);
  }
  *(undefined8 *)(puVar13 + -8) = 0x140004aa2;
  wil_InitializeFeatureStaging();
  *(undefined8 *)(puVar13 + -8) = 0x140004aaf;
  puVar9 = (undefined8 *)p9fs::InitializeDispatchTable();
  this = (Device *)(puVar13 + 0x20);
  do {
    pDVar11 = this;
    puVar10 = puVar9;
    uVar3 = puVar10[1];
    uVar4 = puVar10[2];
    uVar5 = puVar10[3];
    *(undefined8 *)pDVar11 = *puVar10;
    *(undefined8 *)(pDVar11 + 8) = uVar3;
    uVar3 = puVar10[4];
    uVar6 = puVar10[5];
    *(undefined8 *)(pDVar11 + 0x10) = uVar4;
    *(undefined8 *)(pDVar11 + 0x18) = uVar5;
    uVar4 = puVar10[6];
    uVar5 = puVar10[7];
    *(undefined8 *)(pDVar11 + 0x20) = uVar3;
    *(undefined8 *)(pDVar11 + 0x28) = uVar6;
    uVar3 = puVar10[8];
    uVar6 = puVar10[9];
    *(undefined8 *)(pDVar11 + 0x30) = uVar4;
    *(undefined8 *)(pDVar11 + 0x38) = uVar5;
    uVar4 = puVar10[10];
    uVar5 = puVar10[0xb];
    *(undefined8 *)(pDVar11 + 0x40) = uVar3;
    *(undefined8 *)(pDVar11 + 0x48) = uVar6;
    uVar3 = puVar10[0xc];
    uVar6 = puVar10[0xd];
    *(undefined8 *)(pDVar11 + 0x50) = uVar4;
    *(undefined8 *)(pDVar11 + 0x58) = uVar5;
    uVar4 = puVar10[0xe];
    uVar5 = puVar10[0xf];
    *(undefined8 *)(pDVar11 + 0x60) = uVar3;
    *(undefined8 *)(pDVar11 + 0x68) = uVar6;
    this = pDVar11 + 0x80;
    *(undefined8 *)(pDVar11 + 0x70) = uVar4;
    *(undefined8 *)(pDVar11 + 0x78) = uVar5;
    lVar12 = lVar12 + -1;
    puVar9 = puVar10 + 0x10;
  } while (lVar12 != 0);
  uVar3 = puVar10[0x11];
  uVar4 = puVar10[0x12];
  uVar5 = puVar10[0x13];
  *(undefined8 *)this = puVar10[0x10];
  *(undefined8 *)(pDVar11 + 0x88) = uVar3;
  uVar3 = puVar10[0x14];
  uVar6 = puVar10[0x15];
  *(undefined8 *)(pDVar11 + 0x90) = uVar4;
  *(undefined8 *)(pDVar11 + 0x98) = uVar5;
  uVar4 = puVar10[0x16];
  uVar5 = puVar10[0x17];
  *(undefined8 *)(pDVar11 + 0xa0) = uVar3;
  *(undefined8 *)(pDVar11 + 0xa8) = uVar6;
  uVar3 = puVar10[0x18];
  uVar6 = puVar10[0x19];
  *(undefined8 *)(pDVar11 + 0xb0) = uVar4;
  *(undefined8 *)(pDVar11 + 0xb8) = uVar5;
  *(undefined8 *)(pDVar11 + 0xc0) = uVar3;
  *(undefined8 *)(pDVar11 + 200) = uVar6;
  *(undefined8 *)(puVar13 + -8) = 0x140004b36;
  lVar8 = p9fs::Device::Register(this,param_1,(_MINIRDR_DISPATCH *)(puVar13 + 0x20));
  if (lVar8 < 0) {
    if (g_wil_details_featureChangeNotification != 0) {
      *(undefined8 *)(puVar13 + -8) = 0x140004b5c;
      RtlUnregisterFeatureConfigurationChangeNotification();
      g_wil_details_featureChangeNotification = 0;
    }
    if (g_wil_details_featureUsageProvider != 0) {
      *(undefined8 *)(puVar13 + -8) = 0x140004b7c;
      RtlUnregisterFeatureUsageProvider();
      g_wil_details_featureUsageProvider = 0;
    }
    g_wil_details_isFeatureStagingInitialized = 0;
  }
  else {
    *(code **)(param_1 + 0x68) = p9fs::DriverUnload;
  }
  *(undefined8 *)(puVar13 + -8) = 0x140004ba2;
  return lVar8;
}



===== _tlgDefineProvider_annotation__TlgPlan9RedirectorTraceLoggingProviderProv @ 140004bbc =====

void _tlgDefineProvider_annotation__TlgPlan9RedirectorTraceLoggingProviderProv(void)

{
  return;
}



===== wil_details_RecordCachedUsage @ 140004bc8 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140004d20 =====

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



===== `scalar_deleting_destructor' @ 140004db0 =====

/* public: virtual void * __ptr64 __cdecl p9fs::WskTransport::`scalar deleting destructor'(unsigned
   int) __ptr64 */

void * __thiscall p9fs::WskTransport::_scalar_deleting_destructor_(WskTransport *this,uint param_1)

{
  *(undefined ***)this = &_vftable_;
  Close(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0);
  }
  return this;
}



===== Close @ 140004e00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl p9fs::WskTransport::Close(void) __ptr64 */

long __thiscall p9fs::WskTransport::Close(WskTransport *this)

{
  longlong *plVar1;
  _IRP *p_Var2;
  long lVar3;
  AutoResetEvent local_58 [8];
  _IRP *local_50;
  AutoResetEvent local_48 [24];
  char *local_30;
  char *local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  ExWaitForRundownProtectionRelease(this + 0x10);
  ExRundownCompleted(this + 0x10);
  LOCK();
  plVar1 = *(longlong **)(this + 0x18);
  *(longlong *)(this + 0x18) = 0;
  UNLOCK();
  if (plVar1 == (longlong *)0x0) {
    lVar3 = 0;
  }
  else {
    KeInitializeEvent(local_48,1);
    CreateSynchronousIrp(local_58);
    if (local_58[0] == (AutoResetEvent)0x0) {
      local_18 = 0;
      local_30 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\wsktransport.cpp";
      local_20 = 0x167;
      local_28 = "p9fs::WskTransport::Close";
      lVar3 = (long)local_50;
      TraceLog((ErrorSite *)&local_30,lVar3);
    }
    else {
      lVar3 = (**(code **)(*plVar1 + 8))(plVar1,local_50);
      lVar3 = WaitForIrp(local_50,local_48,lVar3);
    }
    p_Var2 = local_50;
    if ((local_58[0] != (AutoResetEvent)0x0) && (local_50 = (_IRP *)0x0, p_Var2 != (_IRP *)0x0)) {
      RxCeFreeIrp();
    }
  }
  return lVar3;
}



===== Connect @ 140004f10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl p9fs::WskTransport::Connect(struct sockaddr * __ptr64,void
   (__cdecl*)(long,void * __ptr64),void * __ptr64) __ptr64 */

long __thiscall
p9fs::WskTransport::Connect
          (WskTransport *this,sockaddr *param_1,_func_void_long_void_ptr *param_2,void *param_3)

{
  ushort uVar1;
  longlong lVar2;
  _IRP *p_Var3;
  _IRP *p_Var4;
  long lVar5;
  longlong lVar6;
  ErrorSite *pEVar7;
  ulong uVar8;
  undefined1 auStackY_148 [32];
  AutoResetEvent local_118 [8];
  _IRP *local_110;
  char *local_108;
  char *local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined4 local_e8 [2];
  char *local_e0;
  char *local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_b8 [14];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_148;
  if (*(longlong *)(this + 0x18) != 0) {
    return -0x3ffffaf0;
  }
  memset(local_b8,0,0x70);
  uVar1 = *(ushort *)param_1;
  if (uVar1 == 1) {
    local_b8[0] = CONCAT62(local_b8[0]._2_6_,1);
    uVar8 = 0;
  }
  else if (uVar1 == 2) {
    local_b8[0] = 2;
    uVar8 = 6;
  }
  else {
    if (uVar1 != 0x22) {
      return -0x3ffffff3;
    }
    local_b8[0] = CONCAT62(local_b8[0]._2_6_,0x22);
    uVar8 = 1;
  }
  CreateSocket(this,(ushort)local_118,(uint)uVar1);
  p_Var3 = local_110;
  if (local_118[0] == (AutoResetEvent)0x0) {
    local_d8 = "p9fs::WskTransport::Connect";
    local_e0 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\wsktransport.cpp";
    local_d0 = 0xb7;
    local_c8 = 0;
    TraceLog((ErrorSite *)&local_e0,(long)local_110);
    return (long)local_110;
  }
  *(_IRP **)(this + 0x18) = local_110;
  if (*(short *)param_1 == 0x22) {
    local_e8[0] = 1;
    lVar5 = SetSocketOption(this,uVar8,4,local_e8,4);
    if (lVar5 < 0) {
      local_c8 = 0;
      local_e0 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\wsktransport.cpp";
      local_d8 = "p9fs::WskTransport::Connect";
      pEVar7 = (ErrorSite *)&local_e0;
      local_d0 = 0xbe;
      goto LAB_140005062;
    }
  }
  KeInitializeEvent(&local_e0,1);
  CreateSynchronousIrp(local_118);
  if (local_118[0] == (AutoResetEvent)0x0) {
    local_f0 = 0;
    local_108 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\wsktransport.cpp";
    local_100 = "p9fs::WskTransport::Bind";
    local_f8 = 0x19b;
    lVar5 = (long)local_110;
    TraceLog((ErrorSite *)&local_108,lVar5);
  }
  else {
    lVar5 = (**(code **)(**(longlong **)(this + 0x18) + 0x10))
                      (*(longlong **)(this + 0x18),local_b8,0,local_110);
    lVar5 = WaitForIrp(local_110,(AutoResetEvent *)&local_e0,lVar5);
  }
  p_Var4 = local_110;
  if ((local_118[0] != (AutoResetEvent)0x0) && (local_110 = (_IRP *)0x0, p_Var4 != (_IRP *)0x0)) {
    RxCeFreeIrp();
  }
  if (lVar5 < 0) {
    local_f8 = 0xc2;
  }
  else {
    if ((*(short *)param_1 != 1) || (lVar5 = SetSocketAfUnixPath(this), -1 < lVar5)) {
      lVar6 = RxCeAllocateIrpWithMDL(2,0,0);
      if (lVar6 == 0) {
        return -0x3fffff66;
      }
      *(char *)(lVar6 + 0x43) = *(char *)(lVar6 + 0x43) + -1;
      lVar2 = *(longlong *)(lVar6 + 0xb8);
      *(longlong *)(lVar6 + 0xb8) = lVar2 + -0x48;
      *(undefined8 *)(lVar2 + -0x40) = this;
      *(_func_void_long_void_ptr **)(lVar2 + -0x38) = param_2;
      *(void **)(lVar2 + -0x30) = param_3;
      lVar6 = *(longlong *)(lVar6 + 0xb8);
      *(code **)(lVar6 + -0x10) = ConnectComplete;
      *(undefined8 **)(lVar6 + -8) = (undefined8 *)(lVar2 + -0x40);
      *(undefined1 *)(lVar6 + -0x45) = 0xe0;
      (**(code **)(**(longlong **)(this + 0x18) + 0x20))(p_Var3,param_1,0);
      return 0x103;
    }
    local_f8 = 200;
  }
  local_f0 = 0;
  local_100 = "p9fs::WskTransport::Connect";
  pEVar7 = (ErrorSite *)&local_108;
  local_108 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\wsktransport.cpp";
LAB_140005062:
  TraceLog(pEVar7,lVar5);
  return lVar5;
}



===== ConnectComplete @ 140005230 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static long __cdecl p9fs::WskTransport::ConnectComplete(struct _DEVICE_OBJECT *
   __ptr64,struct _IRP * __ptr64,void * __ptr64) */

long __cdecl
p9fs::WskTransport::ConnectComplete(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  longlong lVar1;
  char cVar2;
  ulonglong uVar3;
  
  lVar1 = *(longlong *)param_3;
  cVar2 = ExAcquireRundownProtection(lVar1 + 0x10U);
  uVar3 = -(ulonglong)(cVar2 != '\0') & lVar1 + 0x10U;
  if (uVar3 != 0) {
    (**(code **)((longlong)param_3 + 8))
              (*(undefined4 *)(param_2 + 0x30),*(undefined8 *)((longlong)param_3 + 0x10));
    ExReleaseRundownProtection(uVar3);
  }
  if (param_2 != (_IRP *)0x0) {
    param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    RxCeFreeIrp(param_2);
  }
  return -0x3fffffea;
}



===== CreateSocket @ 1400052cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: class util::BasicExpected<struct _WSK_SOCKET * __ptr64,long> __cdecl
   p9fs::WskTransport::CreateSocket(unsigned short,unsigned long) __ptr64 */

undefined1 * __thiscall
p9fs::WskTransport::CreateSocket(WskTransport *this,ushort param_1,ulong param_2)

{
  long lVar1;
  _IRP *p_Var2;
  undefined6 in_register_00000012;
  undefined1 *puVar3;
  undefined4 in_R9D;
  AutoResetEvent local_68 [8];
  _IRP *local_60;
  AutoResetEvent local_58 [24];
  char *local_40;
  char *local_38;
  undefined8 local_30;
  undefined8 local_28;
  
  puVar3 = (undefined1 *)CONCAT62(in_register_00000012,param_1);
  KeInitializeEvent(local_58,1);
  CreateSynchronousIrp(local_68);
  if (local_68[0] == (AutoResetEvent)0x0) {
    lVar1 = (long)local_60;
    local_30 = 0x18e;
  }
  else {
    lVar1 = (**(code **)((*(undefined8 **)(this + 8))[1] + 8))
                      (**(undefined8 **)(this + 8),(short)param_2,1,in_R9D,8,0,0,0,0,0,local_60);
    lVar1 = WaitForIrp(local_60,local_58,lVar1);
    if (-1 < lVar1) {
      *(undefined8 *)(puVar3 + 8) = *(undefined8 *)(local_60 + 0x38);
      *puVar3 = 1;
      p_Var2 = local_60;
      if (local_68[0] == (AutoResetEvent)0x0) {
        return puVar3;
      }
      goto LAB_1400053f1;
    }
    local_30 = 0x192;
  }
  local_28 = 0;
  local_40 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\wsktransport.cpp";
  local_38 = "p9fs::WskTransport::CreateSocket";
  TraceLog((ErrorSite *)&local_40,lVar1);
  *puVar3 = 0;
  *(long *)(puVar3 + 8) = lVar1;
  if (local_68[0] == (AutoResetEvent)0x0) {
    return puVar3;
  }
  p_Var2 = local_60;
LAB_1400053f1:
  local_60 = (_IRP *)0x0;
  if (p_Var2 != (_IRP *)0x0) {
    RxCeFreeIrp();
  }
  return puVar3;
}



===== CreateSynchronousIrp @ 140005430 =====

/* class util::BasicExpected<class wistd::unique_ptr<struct _IRP,class p9fs::IrpDeleter<0> >,long>
   __cdecl p9fs::CreateSynchronousIrp(class p9fs::AutoResetEvent & __ptr64) */

AutoResetEvent * __cdecl p9fs::CreateSynchronousIrp(AutoResetEvent *param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 in_RDX;
  
  lVar2 = RxCeAllocateIrpWithMDL(1,0,0);
  if (lVar2 == 0) {
    *param_1 = (AutoResetEvent)0x0;
    *(undefined4 *)(param_1 + 8) = 0xc000009a;
  }
  else {
    lVar1 = *(longlong *)(lVar2 + 0xb8);
    *(code **)(lVar1 + -0x10) = SynchronousWskComplete;
    *(undefined8 *)(lVar1 + -8) = in_RDX;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    *param_1 = (AutoResetEvent)0x1;
    *(longlong *)(param_1 + 8) = lVar2;
  }
  return param_1;
}



===== Receive @ 1400054a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl p9fs::WskTransport::Receive(class gsl::span<enum gsl::byte,-1>,void
   (__cdecl*)(long,unsigned long,void * __ptr64),void * __ptr64) __ptr64 */

long __thiscall
p9fs::WskTransport::Receive
          (WskTransport *this,undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  char cVar4;
  longlong lVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  undefined8 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  
  cVar4 = ExAcquireRundownProtection(this + 0x10);
  uVar7 = -(ulonglong)(cVar4 != '\0') & (ulonglong)(this + 0x10);
  if (uVar7 != 0) {
    if ((this[0x20] == (WskTransport)0x0) && (*(longlong *)(this + 0x18) != 0)) {
      lVar5 = RxCeAllocateIrpWithMDL(2,0,0);
      if (lVar5 == 0) {
        ExReleaseRundownProtection(uVar7);
        return -0x3fffff66;
      }
      *(char *)(lVar5 + 0x43) = *(char *)(lVar5 + 0x43) + -1;
      lVar2 = *(longlong *)(lVar5 + 0xb8);
      uVar1 = *(undefined4 *)param_2;
      uVar6 = param_2[1];
      *(longlong *)(lVar5 + 0xb8) = lVar2 + -0x48;
      uVar6 = IoAllocateMdl(uVar6,uVar1,0,0,0);
      MmBuildMdlForNonPagedPool(uVar6);
      *(undefined8 *)(lVar2 + -0x40) = this;
      *(undefined8 *)(lVar2 + -0x38) = param_3;
      *(undefined8 *)(lVar2 + -0x30) = param_4;
      *(undefined8 *)(lVar2 + -0x28) = uVar6;
      lVar3 = *(longlong *)(lVar5 + 0xb8);
      *(code **)(lVar3 + -0x10) = SendReceiveComplete;
      *(undefined8 **)(lVar3 + -8) = (undefined8 *)(lVar2 + -0x40);
      *(undefined1 *)(lVar3 + -0x45) = 0xe0;
      local_40 = 0;
      local_3c = 0;
      local_38 = *param_2;
      local_48 = uVar6;
      (**(code **)(**(longlong **)(this + 0x18) + 0x38))
                (*(longlong **)(this + 0x18),&local_48,0,lVar5);
      ExReleaseRundownProtection(uVar7);
      return 0x103;
    }
    ExReleaseRundownProtection(uVar7);
  }
  return -0x3ffffdf4;
}



===== Reset @ 140005628 =====

/* public: long __cdecl util::DynamicArray<enum gsl::byte>::Reset(unsigned __int64,unsigned __int64)
   __ptr64 */

long __thiscall
util::DynamicArray<gsl::byte>::Reset
          (DynamicArray<gsl::byte> *this,__uint64 param_1,__uint64 param_2)

{
  longlong lVar1;
  void *_Dst;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  if (param_1 == 0) {
    _Dst = (void *)0x0;
  }
  else {
    _Dst = (void *)ExAllocatePool2(0x40,param_1,0x78523950);
    if (_Dst == (void *)0x0) {
      local_10 = 0;
      local_28 = "onecore\\vm\\inc\\DynamicArray.h";
      local_18 = 0x3d;
      local_20 = "util::DynamicArray<enum gsl::byte>::Reset";
      p9fs::TraceLog((ErrorSite *)&local_28,-0x3fffff66);
      return -0x3fffff66;
    }
    memset(_Dst,0,param_1);
  }
  lVar1 = *(longlong *)this;
  *(void **)this = _Dst;
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0);
  }
  *(__uint64 *)(this + 8) = param_1;
  return 0;
}



===== Send @ 1400056f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl p9fs::WskTransport::Send(class gsl::span<enum gsl::byte const
   ,-1>,void (__cdecl*)(long,unsigned long,void * __ptr64),void * __ptr64) __ptr64 */

long __thiscall
p9fs::WskTransport::Send
          (WskTransport *this,undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong lVar4;
  char cVar5;
  longlong lVar6;
  ulonglong uVar7;
  longlong local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  
  cVar5 = ExAcquireRundownProtection(this + 0x10);
  uVar7 = -(ulonglong)(cVar5 != '\0') & (ulonglong)(this + 0x10);
  if (uVar7 != 0) {
    if ((this[0x20] == (WskTransport)0x0) && (*(longlong *)(this + 0x18) != 0)) {
      lVar6 = RxCeAllocateIrpWithMDL(2,0,0);
      if (lVar6 != 0) {
        *(char *)(lVar6 + 0x43) = *(char *)(lVar6 + 0x43) + -1;
        lVar2 = *(longlong *)(lVar6 + 0xb8);
        uVar1 = *(undefined4 *)param_2;
        uVar3 = param_2[1];
        *(longlong *)(lVar6 + 0xb8) = lVar2 + -0x48;
        local_48 = IoAllocateMdl(uVar3,uVar1,0,0,0);
        if (local_48 != 0) {
          MmBuildMdlForNonPagedPool(local_48);
          *(undefined8 *)(lVar2 + -0x40) = this;
          *(undefined8 *)(lVar2 + -0x38) = param_3;
          *(undefined8 *)(lVar2 + -0x30) = param_4;
          *(longlong *)(lVar2 + -0x28) = local_48;
          lVar4 = *(longlong *)(lVar6 + 0xb8);
          *(code **)(lVar4 + -0x10) = SendReceiveComplete;
          *(undefined8 **)(lVar4 + -8) = (undefined8 *)(lVar2 + -0x40);
          *(undefined1 *)(lVar4 + -0x45) = 0xe0;
          local_40 = 0;
          local_3c = 0;
          local_38 = *param_2;
          (**(code **)(**(longlong **)(this + 0x18) + 0x30))
                    (*(longlong **)(this + 0x18),&local_48,0,lVar6);
          ExReleaseRundownProtection(uVar7);
          return 0x103;
        }
        *(char *)(lVar6 + 0x43) = *(char *)(lVar6 + 0x43) + '\x01';
        *(longlong *)(lVar6 + 0xb8) = *(longlong *)(lVar6 + 0xb8) + 0x48;
        RxCeFreeIrp(lVar6);
      }
      ExReleaseRundownProtection(uVar7);
      return -0x3fffff66;
    }
    ExReleaseRundownProtection(uVar7);
  }
  return -0x3ffffdf4;
}



===== SendReceiveComplete @ 1400058a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static long __cdecl p9fs::WskTransport::SendReceiveComplete(struct _DEVICE_OBJECT *
   __ptr64,struct _IRP * __ptr64,void * __ptr64) */

long __cdecl
p9fs::WskTransport::SendReceiveComplete(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  ulonglong uVar4;
  
  IoFreeMdl(*(undefined8 *)((longlong)param_3 + 0x18));
  lVar1 = *(longlong *)param_3;
  cVar2 = ExAcquireRundownProtection(lVar1 + 0x10U);
  uVar4 = -(ulonglong)(cVar2 != '\0') & lVar1 + 0x10U;
  if (uVar4 != 0) {
    iVar3 = *(int *)(param_2 + 0x30);
    if ((-1 < iVar3) && (*(longlong *)(param_2 + 0x38) == 0)) {
      iVar3 = -0x3ffffdf4;
    }
    (**(code **)((longlong)param_3 + 8))
              (iVar3,*(undefined4 *)(param_2 + 0x38),*(undefined8 *)((longlong)param_3 + 0x10));
    ExReleaseRundownProtection(uVar4);
  }
  if (param_2 != (_IRP *)0x0) {
    param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    RxCeFreeIrp(param_2);
  }
  return -0x3fffffea;
}



===== SetSocketAfUnixPath @ 140005960 =====

/* private: long __cdecl p9fs::WskTransport::SetSocketAfUnixPath(void) __ptr64 */

long __thiscall p9fs::WskTransport::SetSocketAfUnixPath(WskTransport *this)

{
  __uint64 _Var1;
  undefined8 *puVar2;
  long lVar3;
  undefined8 *puVar4;
  __uint64 in_R8;
  undefined8 *local_48;
  undefined8 *puStack_40;
  undefined8 *local_38;
  undefined8 *puStack_30;
  char *local_28;
  char *pcStack_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_48 = (undefined8 *)0x0;
  puStack_40 = (undefined8 *)0x0;
  _Var1 = *(longlong *)(this + 0x28) * 2 + 8;
  lVar3 = util::DynamicArray<gsl::byte>::Reset((DynamicArray<gsl::byte> *)&local_48,_Var1,in_R8);
  puVar4 = local_48;
  if (lVar3 < 0) {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\wsktransport.cpp";
    local_18 = 0x1b3;
    pcStack_20 = "p9fs::WskTransport::SetSocketAfUnixPath";
    TraceLog((ErrorSite *)&local_28,lVar3);
    puVar4 = local_48;
    if (local_48 == (undefined8 *)0x0) {
      return lVar3;
    }
LAB_1400059dd:
    ExFreePoolWithTag(puVar4,0);
    return lVar3;
  }
  *local_48 = 0;
  puVar2 = local_48;
  if ((((longlong)puStack_40 - 1U < 0xfffffffffffffffe) && ((undefined8 *)0x7 < puStack_40)) &&
     (puVar2 = puStack_40 + -1, puVar2 != (undefined8 *)0xffffffffffffffff)) {
    puStack_40 = local_48 + 1;
    local_48 = puVar2;
    ReinterpretSpan<unsigned_short,gsl::byte>(&local_28,&local_48);
    local_48 = *(undefined8 **)(this + 0x28);
    puStack_30 = *(undefined8 **)(this + 0x30);
    puVar2 = local_48;
    local_38 = local_48;
    if ((local_48 != (undefined8 *)0xffffffffffffffff) &&
       ((puStack_30 != (undefined8 *)0x0 ||
        (puStack_40 = (undefined8 *)0x0, local_48 == (undefined8 *)0x0)))) {
      puStack_40 = puStack_30;
      gsl::copy<unsigned_short,_1,unsigned_short,_1>(&local_38,&local_28);
      lVar3 = SetSocketOption(this,0xffff,0x98000000,puVar4,_Var1);
      goto LAB_1400059dd;
    }
  }
  local_48 = puVar2;
                    /* WARNING: Subroutine does not return */
  gsl::details::terminate();
}



===== SetSocketOption @ 140005ad8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl p9fs::WskTransport::SetSocketOption(unsigned long,unsigned long,void *
   __ptr64,unsigned __int64) __ptr64 */

long __thiscall
p9fs::WskTransport::SetSocketOption
          (WskTransport *this,ulong param_1,ulong param_2,void *param_3,__uint64 param_4)

{
  _IRP *p_Var1;
  long lVar2;
  AutoResetEvent local_58 [8];
  _IRP *local_50;
  AutoResetEvent local_48 [24];
  char *local_30;
  char *local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  KeInitializeEvent(local_48,1);
  CreateSynchronousIrp(local_58);
  if (local_58[0] == (AutoResetEvent)0x0) {
    local_18 = 0;
    local_30 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\wsktransport.cpp";
    local_20 = 0x1a6;
    local_28 = "p9fs::WskTransport::SetSocketOption";
    lVar2 = (long)local_50;
    TraceLog((ErrorSite *)&local_30,lVar2);
  }
  else {
    lVar2 = (**(code **)**(undefined8 **)(this + 0x18))
                      (*(undefined8 **)(this + 0x18),0,param_2,param_1,param_4,param_3,0,0,0,
                       local_50);
    lVar2 = WaitForIrp(local_50,local_48,lVar2);
  }
  p_Var1 = local_50;
  if (local_58[0] != (AutoResetEvent)0x0) {
    local_50 = (_IRP *)0x0;
    if (p_Var1 != (_IRP *)0x0) {
      RxCeFreeIrp();
    }
  }
  return lVar2;
}



===== Stop @ 140005c00 =====

/* public: virtual long __cdecl p9fs::WskTransport::Stop(void) __ptr64 */

long __thiscall p9fs::WskTransport::Stop(WskTransport *this)

{
  this[0x20] = (WskTransport)0x1;
  return 0;
}



===== SynchronousWskComplete @ 140005c10 =====

/* long __cdecl p9fs::SynchronousWskComplete(struct _DEVICE_OBJECT * __ptr64,struct _IRP *
   __ptr64,void * __ptr64) */

long __cdecl p9fs::SynchronousWskComplete(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  KeSetEvent(param_3,0,0);
  return -0x3fffffea;
}



===== WaitForIrp @ 140005c3c =====

/* long __cdecl p9fs::WaitForIrp(struct _IRP * __ptr64,class p9fs::AutoResetEvent & __ptr64,long) */

long __cdecl p9fs::WaitForIrp(_IRP *param_1,AutoResetEvent *param_2,long param_3)

{
  char cVar1;
  uint uVar2;
  undefined8 local_res20;
  char *local_38;
  char *local_30;
  undefined8 local_28;
  char *local_20;
  
  if (param_3 == 0x103) {
    local_res20 = 0xfffffffffa0a1f00;
    uVar2 = KeWaitForSingleObject(param_2,6,0,0,&local_res20);
    if (uVar2 != 0) {
      local_28 = 0x5e;
      local_20 = "P9: Wait for synchronous IRP completion failed: 0x%x\n";
      local_38 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\wsktransport.cpp";
      local_30 = "p9fs::WaitForIrp";
      TraceLog((ErrorSite *)&local_38,-0x3fffffff,(ulonglong)uVar2);
      cVar1 = IoCancelIrp(param_1);
      if (cVar1 == '\0') {
        local_38 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\wsktransport.cpp";
        local_20 = "P9: Could not cancel IRP.\n";
        local_30 = "p9fs::WaitForIrp";
        local_28 = 0x61;
        TraceLog((ErrorSite *)&local_38,-0x3fffffff);
      }
      KeWaitForSingleObject(param_2,6,0,0,0);
    }
    param_3 = *(long *)(param_1 + 0x30);
  }
  return param_3;
}



===== <lambda_invoker_cdecl><void_*> @ 140005d50 =====

void <lambda_bcf30decff36993d57a95fb6b08fa600>::<lambda_invoker_cdecl><void_*>(undefined8 *param_1)

{
  RxDestroyMidAtlas(*param_1,param_1[1]);
  ExFreePoolWithTag(param_1,0);
  return;
}



===== <lambda_invoker_cdecl><void_*> @ 140005d90 =====

void <lambda_e6194d171ffda1cd05b83128a0039f97>::<lambda_invoker_cdecl><void_*>(void)

{
  return;
}



===== ~SharedPtr<p9fs::Exchange> @ 140005d9c =====

/* public: __cdecl p9fs::SharedPtr<class p9fs::Exchange>::~SharedPtr<class p9fs::Exchange>(void)
   __ptr64 */

void __thiscall
p9fs::SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>(SharedPtr<p9fs::Exchange> *this)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  code *pcVar4;
  
  lVar3 = *(longlong *)this;
  if (lVar3 != 0) {
    LOCK();
    plVar1 = (longlong *)(lVar3 + 0x70);
    lVar2 = *plVar1;
    *plVar1 = *plVar1 + -1;
    UNLOCK();
    if (lVar2 < 2) {
      if (lVar2 == 1) {
        lVar2 = *(longlong *)(lVar3 + 0x68);
        *(undefined8 *)(lVar3 + 0x68) = 0;
        if (lVar2 != 0) {
          ExFreePoolWithTag(lVar2,0);
        }
        FidLease::~FidLease((FidLease *)(lVar3 + 0x20));
        ExFreePoolWithTag(lVar3,0);
      }
      else {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(0xe);
      }
    }
  }
  *(undefined8 *)this = 0;
  return;
}



===== CleanupMidAtlas @ 140005e1c =====

/* void __cdecl p9fs::CleanupMidAtlas(struct _RX_MID_ATLAS * __ptr64) */

void __cdecl p9fs::CleanupMidAtlas(_RX_MID_ATLAS *param_1)

{
  RxDestroyMidAtlas(param_1,<lambda_e6194d171ffda1cd05b83128a0039f97>::
                            <lambda_invoker_cdecl><void_*>);
  return;
}



===== FindAndRemove @ 140005e40 =====

/* public: virtual class util::BasicExpected<class p9fs::SharedPtr<class p9fs::Exchange>,long>
   __cdecl p9fs::MidExchangeManager::FindAndRemove(unsigned short) __ptr64 */

undefined1 * __thiscall
p9fs::MidExchangeManager::FindAndRemove(MidExchangeManager *this,ushort param_1)

{
  MidExchangeManager *pMVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  int iVar4;
  undefined6 in_register_00000012;
  undefined1 *puVar5;
  undefined2 in_R8W;
  longlong local_res8;
  undefined8 local_res20;
  MidExchangeManager *local_48;
  undefined1 uStack_40;
  undefined4 uStack_3f;
  undefined2 uStack_3b;
  undefined1 uStack_39;
  char *local_38;
  char *local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  puVar5 = (undefined1 *)CONCAT62(in_register_00000012,param_1);
  pMVar1 = this + 0x10;
  uVar3 = KeAcquireSpinLockRaiseToDpc(pMVar1);
  uVar2 = _uStack_40;
  _uStack_40 = CONCAT41(uStack_3f,uVar3);
  uStack_3b = SUB82(uVar2,5);
  uStack_39 = SUB81(uVar2,7);
  local_48 = pMVar1;
  if (*(longlong *)(this + 8) == 0) {
    *puVar5 = 0;
    *(undefined4 *)(puVar5 + 8) = 0xc000020c;
  }
  else {
    local_res8 = 0;
    iVar4 = RxMapAndDissociateMidFromContext(*(longlong *)(this + 8),in_R8W,&local_res8);
    if (iVar4 < 0) {
      local_20 = 0;
      local_38 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\midexchange.cpp";
      local_28 = 0x61;
      local_30 = "p9fs::MidExchangeManager::FindAndRemove";
      TraceLog((ErrorSite *)&local_38,iVar4);
      *puVar5 = 0;
      *(int *)(puVar5 + 8) = iVar4;
    }
    else if (local_res8 == 0) {
      *puVar5 = 0;
      *(undefined4 *)(puVar5 + 8) = 0xc0000225;
    }
    else {
      local_res20 = 0;
      *puVar5 = 1;
      *(longlong *)(puVar5 + 8) = local_res8;
      SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>
                ((SharedPtr<p9fs::Exchange> *)&local_res20);
    }
  }
  if (pMVar1 != (MidExchangeManager *)0x0) {
    wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_48);
  }
  return puVar5;
}



===== RegisterExchange @ 140005f60 =====

/* public: virtual long __cdecl p9fs::MidExchangeManager::RegisterExchange(class
   p9fs::SharedPtr<class p9fs::Exchange>) __ptr64 */

long __thiscall
p9fs::MidExchangeManager::RegisterExchange
          (MidExchangeManager *this,SharedPtr<p9fs::Exchange> *param_2)

{
  MidExchangeManager *pMVar1;
  undefined8 uVar2;
  char *pcVar3;
  uint7 uVar4;
  char *pcVar5;
  undefined1 uVar6;
  byte bVar7;
  int iVar8;
  _RX_MID_ATLAS *p_Var9;
  _RX_MID_ATLAS *p_Var10;
  _RX_MID_ATLAS *p_Var11;
  undefined4 uVar12;
  undefined4 uVar13;
  MidExchangeManager *local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  
  pMVar1 = this + 0x10;
  uVar6 = KeAcquireSpinLockRaiseToDpc(pMVar1);
  uVar2 = uStack_40;
  uVar4 = uStack_40._1_7_;
  uStack_40 = (char *)CONCAT71(uStack_40._1_7_,uVar6);
  pcVar5 = uStack_40;
  uVar12 = (undefined4)uStack_40;
  uStack_40._4_4_ = SUB84(uVar2,4);
  uVar13 = uStack_40._4_4_;
  p_Var10 = *(_RX_MID_ATLAS **)(this + 8);
  p_Var11 = (_RX_MID_ATLAS *)0x0;
  if (*(_RX_MID_ATLAS **)(this + 8) == (_RX_MID_ATLAS *)0x0) {
    local_48 = (MidExchangeManager *)0x0;
    uStack_40 = (char *)((ulonglong)uVar4 << 8);
    if (pMVar1 != (MidExchangeManager *)0x0) {
      uStack_40 = (char *)CONCAT44(uVar13,uVar12);
      local_48 = pMVar1;
      wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_48);
    }
    bVar7 = KeGetCurrentIrql();
    if (1 < bVar7) {
      iVar8 = -0x3ffffdf4;
      goto LAB_1400060d6;
    }
    p_Var9 = (_RX_MID_ATLAS *)RxCreateMidAtlas(0x400,0x80);
    if (p_Var9 == (_RX_MID_ATLAS *)0x0) {
      iVar8 = -0x3fffff66;
      goto LAB_1400060d6;
    }
    uVar6 = KeAcquireSpinLockRaiseToDpc(pMVar1);
    pcVar3 = uStack_40;
    uStack_40 = (char *)CONCAT71(uStack_40._1_7_,uVar6);
    pcVar5 = uStack_40;
    uStack_40._4_4_ = SUB84(pcVar3,4);
    p_Var10 = *(_RX_MID_ATLAS **)(this + 8);
    p_Var11 = p_Var9;
    uVar12 = (undefined4)uStack_40;
    uVar13 = uStack_40._4_4_;
    if (*(_RX_MID_ATLAS **)(this + 8) == (_RX_MID_ATLAS *)0x0) {
      p_Var11 = (_RX_MID_ATLAS *)0x0;
      *(_RX_MID_ATLAS **)(this + 8) = p_Var9;
      p_Var10 = p_Var9;
    }
  }
  uStack_40 = pcVar5;
  local_48 = pMVar1;
  iVar8 = RxAssociateContextWithMid(p_Var10,*(longlong *)param_2,*(longlong *)param_2 + 0x1a);
  if (iVar8 < 0) {
    local_30 = 0;
    local_48 = (MidExchangeManager *)0x140016b08;
    local_38 = 0x50;
    uStack_40 = "p9fs::MidExchangeManager::RegisterExchange";
    TraceLog((ErrorSite *)&local_48,iVar8);
    if (pMVar1 != (MidExchangeManager *)0x0) {
      uStack_40 = (char *)CONCAT44(uVar13,uVar12);
      local_48 = pMVar1;
      wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_48);
    }
    if (p_Var11 != (_RX_MID_ATLAS *)0x0) {
      CleanupMidAtlas(p_Var11);
    }
  }
  else {
    *(undefined8 *)param_2 = 0;
    if (pMVar1 != (MidExchangeManager *)0x0) {
      uStack_40 = (char *)CONCAT44(uVar13,uVar12);
      local_48 = pMVar1;
      wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_48);
    }
    if (p_Var11 != (_RX_MID_ATLAS *)0x0) {
      CleanupMidAtlas(p_Var11);
    }
    iVar8 = 0;
  }
LAB_1400060d6:
  SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>(param_2);
  return iVar8;
}



===== Release @ 140006108 =====

/* public: static void __cdecl wil::details::kspin_lock_saved_irql::Release(struct
   wil::details::kspin_lock_saved_irql const & __ptr64) */

void __cdecl wil::details::kspin_lock_saved_irql::Release(kspin_lock_saved_irql *param_1)

{
  KeReleaseSpinLock(*(undefined8 *)param_1,param_1[8]);
  return;
}



===== Stop @ 140006130 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual void __cdecl p9fs::MidExchangeManager::Stop(void (__cdecl*)(void * __ptr64))
   __ptr64 */

void __thiscall
p9fs::MidExchangeManager::Stop(MidExchangeManager *this,_func_void_void_ptr *param_1)

{
  MidExchangeManager *pMVar1;
  longlong lVar2;
  char *pcVar3;
  undefined1 uVar4;
  byte bVar5;
  int iVar6;
  longlong *plVar7;
  MidExchangeManager *local_28;
  char *pcStack_20;
  undefined8 local_18;
  char *local_10;
  
  if (*(longlong *)(this + 8) != 0) {
    pMVar1 = this + 0x10;
    uVar4 = KeAcquireSpinLockRaiseToDpc(pMVar1);
    pcVar3 = pcStack_20;
    lVar2 = *(longlong *)(this + 8);
    pcStack_20._0_5_ = CONCAT41(pcStack_20._1_4_,uVar4);
    pcStack_20._5_2_ = SUB82(pcVar3,5);
    pcStack_20._7_1_ = SUB81(pcVar3,7);
    local_28 = pMVar1;
    if (lVar2 == 0) {
      if (pMVar1 != (MidExchangeManager *)0x0) {
        wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_28);
      }
    }
    else {
      *(undefined8 *)(this + 8) = 0;
      if (pMVar1 != (MidExchangeManager *)0x0) {
        wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_28);
      }
      bVar5 = KeGetCurrentIrql();
      if (bVar5 < 2) {
        RxDestroyMidAtlas(lVar2,param_1);
      }
      else {
        plVar7 = operator_new(0x10);
        if (plVar7 == (longlong *)0x0) {
          plVar7 = (longlong *)0x0;
        }
        else {
          *plVar7 = lVar2;
          plVar7[1] = (longlong)param_1;
        }
        if (plVar7 == (longlong *)0x0) {
          local_28 = (MidExchangeManager *)0x140016b08;
          local_10 = "P9: Failed to destroy mid atlas: out of memory.\n";
          pcStack_20 = "p9fs::MidExchangeManager::Stop";
          local_18 = 0x97;
          TraceLog((ErrorSite *)&local_28,-0x3fffffff);
        }
        iVar6 = RxDispatchToWorkerThread
                          (_GlobalDevice,1,
                           <lambda_bcf30decff36993d57a95fb6b08fa600>::<lambda_invoker_cdecl><void_*>
                           ,plVar7);
        if (iVar6 < 0) {
          local_28 = (MidExchangeManager *)0x140016b08;
          local_10 = "P9: Failed to destroy mid atlas.\n";
          pcStack_20 = "p9fs::MidExchangeManager::Stop";
          local_18 = 0xa5;
          TraceLog((ErrorSite *)&local_28,-0x3fffffff);
          if (plVar7 != (longlong *)0x0) {
            ExFreePoolWithTag(plVar7,0);
          }
        }
      }
    }
  }
  return;
}



===== <lambda_invoker_cdecl><unsigned_int,void_*> @ 1400062e0 =====

void <lambda_8804cf93af8d009258c5b36c41b58831>::<lambda_invoker_cdecl><unsigned_int,void_*>
               (uint param_1,_RX_CONTEXT *param_2)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  __uint64 _Var4;
  undefined8 local_res10;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  LOCK();
  local_res10 = *(undefined8 *)(param_2 + 0xd0);
  *(undefined8 *)(param_2 + 0xd0) = 0;
  UNLOCK();
  p9fs::SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>
            ((SharedPtr<p9fs::Exchange> *)&local_res10);
  uVar1 = *(uint *)(param_2 + 0x228);
  uVar3 = *(int *)(param_2 + 0xd8) + param_1;
  if (uVar1 < uVar3) {
    local_18 = 0x1ea;
    local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\session.cpp";
    local_20 = "p9fs::Session::WriteWorker::<lambda_8804cf93af8d009258c5b36c41b58831>::operator ()";
    local_10 = "P9: Server claimed to write %u bytes, more than %u\n";
    p9fs::TraceLog((ErrorSite *)&local_28,-0x3fffffff,(ulonglong)param_1,(ulonglong)uVar1);
    _Var4 = 0;
    lVar2 = -0x3ffffe7a;
  }
  else {
    if (uVar3 < uVar1) {
      *(uint *)(param_2 + 0xd8) = uVar3;
      lVar2 = p9fs::DispatchIfNecessary
                        (3,<lambda_a8cbd45afd2471e75b8ecf91e825f2f0>::<lambda_invoker_cdecl><void_*>
                         ,param_2);
      if (-1 < lVar2) {
        return;
      }
    }
    else {
      lVar2 = 0;
    }
    _Var4 = (__uint64)uVar3;
  }
  p9fs::Session::CompleteRxContext(param_2,lVar2,_Var4);
  return;
}



===== <lambda_invoker_cdecl><unsigned_int,p9fs::Qid,void_*> @ 1400063c0 =====

void <lambda_b3638c863a088673b8e5d9abfa4c3fac>::
     <lambda_invoker_cdecl><unsigned_int,p9fs::Qid,void_*>
               (undefined8 param_1,undefined8 *param_2,longlong param_3)

{
  undefined8 uVar1;
  
  uVar1 = param_2[1];
  *(undefined8 *)(param_3 + 0xf0) = *param_2;
  *(undefined8 *)(param_3 + 0xf8) = uVar1;
  p9fs::P9Client::FinishReconnect((P9Client *)(param_3 + 0x50),0);
  return;
}



===== <lambda_invoker_cdecl><unsigned_int,p9fs::Qid,void_*> @ 1400063f0 =====

void <lambda_ed524fdfd70bbebc8b2de28b7f45f083>::
     <lambda_invoker_cdecl><unsigned_int,p9fs::Qid,void_*>
               (undefined4 param_1,undefined8 *param_2,void *param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar2 = *param_2;
  uVar3 = param_2[1];
  lVar1 = *(longlong *)(*(longlong *)((longlong)param_3 + 0x108) + 0x28);
  *(undefined4 *)(lVar1 + 0xe8) = param_1;
  *(undefined8 *)(lVar1 + 0xf0) = uVar2;
  *(undefined8 *)(lVar1 + 0xf8) = uVar3;
  *(undefined4 *)((longlong)param_3 + 0x118) = 0;
  p9fs::DispatchIfNecessary
            (1,<lambda_a272816bb16cd9cb6687a6cf4df9bec5>::<lambda_invoker_cdecl><void_*>,param_3);
  return;
}



===== <lambda_invoker_cdecl><long,void_*> @ 140006440 =====

void <lambda_03050e333895841c5623010b92b7b52d>::<lambda_invoker_cdecl><long,void_*>
               (uint param_1,longlong param_2)

{
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  local_18 = 0x107;
  local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\session.cpp";
  local_20 = "p9fs::Session::Reconnect::<lambda_03050e333895841c5623010b92b7b52d>::operator ()";
  local_10 = "P9: Reconnect failed 0x%x\n";
  p9fs::TraceLog((ErrorSite *)&local_28,-0x3fffffff,(ulonglong)param_1);
  p9fs::P9Client::FinishReconnect((P9Client *)(param_2 + 0x50),param_1);
  return;
}



===== <lambda_invoker_cdecl><long,void_*> @ 1400064b0 =====

void <lambda_3d39892d3c49c50879dfc58e2faecfe3>::<lambda_invoker_cdecl><long,void_*>
               (long param_1,_MRX_CREATENETROOT_CONTEXT *param_2)

{
  p9fs::FinalizeVNetRoot(param_2,param_1);
  return;
}



===== <lambda_invoker_cdecl><long,void_*> @ 1400064d0 =====

void <lambda_ac6e3dfe5313820cec630216c13a3357>::<lambda_invoker_cdecl><long,void_*>
               (long param_1,longlong param_2)

{
  p9fs::P9Client::FinishReconnect((P9Client *)(param_2 + 0x50),param_1);
  return;
}



===== <lambda_invoker_cdecl><void_*> @ 1400064f0 =====

void <lambda_23b9756acbd054bcd311d2b60eae7fdc>::<lambda_invoker_cdecl><void_*>(Session *param_1)

{
  if (param_1 != (Session *)0x0) {
    p9fs::Session::~Session(param_1);
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== <lambda_invoker_cdecl><void_*> @ 140006520 =====

void <lambda_29e28994f96b9e1fb9850352512e0e1f>::<lambda_invoker_cdecl><void_*>(longlong param_1)

{
  P9Client *this;
  longlong lVar1;
  long lVar2;
  undefined8 local_38;
  Exchange *pEStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  lVar1 = *(longlong *)(param_1 + 0xe0);
  this = (P9Client *)(param_1 + 0x50);
  local_28 = *(undefined8 *)(lVar1 + 200);
  uStack_20 = *(undefined8 *)(lVar1 + 0xd0);
  local_38 = 0;
  pEStack_30 = (Exchange *)0x0;
  local_18 = 0;
  uStack_14 = 0;
  uStack_10 = 0;
  uStack_c = 0;
  p9fs::P9Client::Reattach
            (this,&local_38,*(undefined4 *)(param_1 + 0xe8),&local_18,&local_28,
             *(undefined4 *)(lVar1 + 0xd8),
             <lambda_b3638c863a088673b8e5d9abfa4c3fac>::
             <lambda_invoker_cdecl><unsigned_int,p9fs::Qid,void_*>,
             <lambda_ac6e3dfe5313820cec630216c13a3357>::<lambda_invoker_cdecl><long,void_*>,param_1)
  ;
  if ((char)local_38 == '\0') {
    lVar2 = (long)pEStack_30;
  }
  else {
    lVar2 = p9fs::P9Client::SendExchange(this,pEStack_30,true);
    if (-1 < lVar2) goto LAB_1400065c7;
  }
  p9fs::P9Client::FinishReconnect(this,lVar2);
LAB_1400065c7:
  if ((char)local_38 != '\0') {
    p9fs::SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>
              ((SharedPtr<p9fs::Exchange> *)&pEStack_30);
  }
  return;
}



===== <lambda_invoker_cdecl><void_*> @ 1400065f0 =====

void <lambda_64ac325a1dbb1a2c9a536140b95bfdf4>::<lambda_invoker_cdecl><void_*>
               (_MRX_CREATENETROOT_CONTEXT *param_1)

{
  P9Client *this;
  longlong lVar1;
  longlong lVar2;
  long lVar3;
  undefined8 local_38;
  Exchange *pEStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x108) + 0x28);
  *(undefined4 *)(param_1 + 0x11c) = 0;
  lVar2 = *(longlong *)(lVar1 + 0xe0);
  this = (P9Client *)(lVar1 + 0x50);
  local_28 = *(undefined8 *)(lVar2 + 200);
  uStack_20 = *(undefined8 *)(lVar2 + 0xd0);
  local_38 = 0;
  pEStack_30 = (Exchange *)0x0;
  local_18 = 0;
  uStack_14 = 0;
  uStack_10 = 0;
  uStack_c = 0;
  p9fs::P9Client::Attach
            (this,&local_38,&local_18,&local_28,*(undefined4 *)(lVar2 + 0xd8),
             <lambda_ed524fdfd70bbebc8b2de28b7f45f083>::
             <lambda_invoker_cdecl><unsigned_int,p9fs::Qid,void_*>,
             <lambda_3d39892d3c49c50879dfc58e2faecfe3>::<lambda_invoker_cdecl><long,void_*>,param_1)
  ;
  if ((char)local_38 == '\0') {
    lVar3 = (long)pEStack_30;
  }
  else {
    lVar3 = p9fs::P9Client::SendExchange(this,pEStack_30,true);
    if (-1 < lVar3) goto LAB_1400066a3;
  }
  p9fs::FinalizeVNetRoot(param_1,lVar3);
LAB_1400066a3:
  if ((char)local_38 != '\0') {
    p9fs::SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>
              ((SharedPtr<p9fs::Exchange> *)&pEStack_30);
  }
  return;
}



===== <lambda_invoker_cdecl><void_*> @ 1400066d0 =====

void <lambda_933469331779dd6d6184cf3716107e2a>::<lambda_invoker_cdecl><void_*>(_RX_CONTEXT *param_1)

{
  long lVar1;
  
  lVar1 = p9fs::Session::ReadWorker
                    (*(Session **)(*(longlong *)(*(longlong *)(param_1 + 0x48) + 0x28) + 0x28),
                     param_1);
  if (lVar1 != 0x103) {
    p9fs::Session::CompleteRxContext(param_1,lVar1,(ulonglong)*(uint *)(param_1 + 0xd8));
  }
  return;
}



===== <lambda_invoker_cdecl><void_*> @ 140006720 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void <lambda_a272816bb16cd9cb6687a6cf4df9bec5>::<lambda_invoker_cdecl><void_*>(longlong param_1)

{
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\session.cpp";
  local_18 = 0x60;
  local_20 = "p9fs::FinalizeVNetRoot::<lambda_a272816bb16cd9cb6687a6cf4df9bec5>::operator ()";
  local_10 = "P9: Create V_NET_ROOT (%wZ) status: 0x%x.\n";
  p9fs::TraceLog((ErrorSite *)&local_28,0,
                 *(undefined8 *)(*(longlong *)(*(longlong *)(param_1 + 0x108) + 0x20) + 0x58),
                 (ulonglong)*(uint *)(param_1 + 0x118));
  (**(code **)(param_1 + 0x110))(param_1);
  return;
}



===== <lambda_invoker_cdecl><void_*> @ 1400067a0 =====

void <lambda_a8cbd45afd2471e75b8ecf91e825f2f0>::<lambda_invoker_cdecl><void_*>(_RX_CONTEXT *param_1)

{
  long lVar1;
  
  lVar1 = p9fs::Session::WriteWorker
                    (*(Session **)(*(longlong *)(*(longlong *)(param_1 + 0x48) + 0x28) + 0x28),
                     param_1);
  if (lVar1 != 0x103) {
    p9fs::Session::CompleteRxContext(param_1,lVar1,(ulonglong)*(uint *)(param_1 + 0xd8));
  }
  return;
}



===== <lambda_invoker_cdecl><void_*,long,bool> @ 1400067f0 =====

void <lambda_acf277aeafc9bc3b9cfb30dfc01ea4b2>::<lambda_invoker_cdecl><void_*,long,bool>
               (longlong param_1,int param_2,bool param_3)

{
  if (param_2 < 0) {
    p9fs::P9Client::FinishReconnect((P9Client *)(*(Session **)(param_1 + 0x20) + 0x50),param_2);
  }
  else {
    p9fs::Session::Reconnect(*(Session **)(param_1 + 0x20),param_3);
  }
  if (param_1 != 0) {
    if (*(longlong *)(param_1 + 0x28) != 0) {
      ExReleaseRundownProtection();
    }
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== <lambda_invoker_cdecl><gsl::span<enum_gsl::byte_const_,-1>,void_*> @ 140006850 =====

void <lambda_3fb1c450e0f042f5dc40e1c0009fe329>::
     <lambda_invoker_cdecl><gsl::span<enum_gsl::byte_const_,_1>,void_*>
               (longlong *param_1,_RX_CONTEXT *param_2)

{
  char *pcVar1;
  char *pcVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  uint uVar6;
  __uint64 _Var7;
  undefined8 local_res8;
  char *local_38;
  char *pcStack_30;
  undefined8 local_28;
  char *local_20;
  
  pcVar1 = (char *)*param_1;
  pcVar2 = (char *)param_1[1];
  LOCK();
  local_res8 = *(undefined8 *)(param_2 + 0xd0);
  *(undefined8 *)(param_2 + 0xd0) = 0;
  UNLOCK();
  p9fs::SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>
            ((SharedPtr<p9fs::Exchange> *)&local_res8);
  uVar4 = *(uint *)(param_2 + 0x228);
  uVar5 = (ulonglong)uVar4;
  uVar6 = *(int *)(param_2 + 0xd8) + (int)pcVar1;
  if (uVar4 < uVar6) {
    local_28 = 0x186;
    local_38 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\session.cpp";
    pcStack_30 = "p9fs::Session::ReadWorker::<lambda_3fb1c450e0f042f5dc40e1c0009fe329>::operator ()"
    ;
    local_20 = "P9: Server returned %u bytes, more than %u\n";
    p9fs::TraceLog((ErrorSite *)&local_38,-0x3fffffff,(ulonglong)uVar6,uVar5);
    _Var7 = 0;
    uVar4 = 0xc0000186;
  }
  else if (pcVar1 == (char *)0x0) {
    _Var7 = (__uint64)uVar6;
    uVar4 = ~-(uint)(uVar6 != 0) & 0xc0000011;
  }
  else {
    lVar3 = *(longlong *)(param_2 + 0x210);
    if ((*(byte *)(lVar3 + 10) & 5) == 0) {
      lVar3 = MmMapLockedPagesSpecifyCache(lVar3,0,1,0,0,0x40000010);
    }
    else {
      lVar3 = *(longlong *)(lVar3 + 0x18);
    }
    if ((((lVar3 == 0) && (uVar4 != 0)) || (uVar5 < *(uint *)(param_2 + 0xd8))) ||
       (uVar5 - *(uint *)(param_2 + 0xd8) == -1)) {
                    /* WARNING: Subroutine does not return */
      gsl::details::terminate();
    }
    local_38 = pcVar1;
    pcStack_30 = pcVar2;
    gsl::copy<gsl::byte_const_,_1,gsl::byte,_1>(&local_38);
    if (uVar6 < uVar4) {
      *(uint *)(param_2 + 0xd8) = uVar6;
      uVar4 = p9fs::DispatchIfNecessary
                        (3,<lambda_933469331779dd6d6184cf3716107e2a>::<lambda_invoker_cdecl><void_*>
                         ,param_2);
      if (-1 < (int)uVar4) {
        return;
      }
      _Var7 = (__uint64)uVar6;
    }
    else {
      _Var7 = (__uint64)uVar6;
      uVar4 = 0;
    }
  }
  p9fs::Session::CompleteRxContext(param_2,uVar4,_Var7);
  return;
}



===== Session @ 1400069d8 =====

/* public: __cdecl p9fs::Session::Session(struct _WSK_PROVIDER_NPI & __ptr64) __ptr64 */

Session * __thiscall p9fs::Session::Session(Session *this,_WSK_PROVIDER_NPI *param_1)

{
  Session *pSVar1;
  
  *(_WSK_PROVIDER_NPI **)(this + 8) = param_1;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined ***)this = &WskTransport::_vftable_;
  this[0x20] = (Session)0x0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  ExInitializeRundownProtection(this + 0x10);
  *(Session **)(this + 0x50) = this;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined ***)(this + 0x38) = &MidExchangeManager::_vftable_;
  *(Session **)(this + 0x58) = this + 0x38;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined8 *)(this + 0x68) = 0;
  *(undefined8 *)(this + 0x70) = 0;
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined8 *)(this + 0x80) = 0;
  *(undefined8 *)(this + 0x88) = 0;
  *(undefined8 *)(this + 0x90) = 0;
  *(undefined8 *)(this + 0x98) = 0;
  KeInitializeSpinLock(this + 0xa0);
  *(undefined4 *)(this + 0xa8) = 0;
  *(code **)(this + 0xb0) = ReconnectCallback;
  *(Session **)(this + 0xb8) = this;
  KeInitializeSpinLock(this + 0xc0);
  this[0xd8] = (Session)0x0;
  pSVar1 = this + 200;
  *(Session **)(this + 0xd0) = pSVar1;
  *(Session **)pSVar1 = pSVar1;
  *(undefined4 *)(this + 0xe8) = 0xffffffff;
  *(undefined8 *)(this + 0xe0) = 0;
  *(undefined8 *)(this + 0xf0) = 0;
  *(undefined8 *)(this + 0xf8) = 0;
  ExInitializeRundownProtection(this + 0x100);
  return this;
}



===== ~Session @ 140006af0 =====

/* public: __cdecl p9fs::Session::~Session(void) __ptr64 */

void __thiscall p9fs::Session::~Session(Session *this)

{
  ExWaitForRundownProtectionRelease(this + 0x100);
  ExRundownCompleted(this + 0x100);
  if (*(ConnectionTarget **)(this + 0xe0) != (ConnectionTarget *)0x0) {
    ConnectionTarget::ReleaseReference(*(ConnectionTarget **)(this + 0xe0));
  }
  *(undefined8 *)(this + 0xe0) = 0;
  P9Client::~P9Client((P9Client *)(this + 0x50));
  *(undefined ***)this = &WskTransport::_vftable_;
  WskTransport::Close((WskTransport *)this);
  return;
}



===== CallUserCallbackForReconnect @ 140006b68 =====

/* private: long __cdecl p9fs::Session::CallUserCallbackForReconnect(void) __ptr64 */

long __thiscall p9fs::Session::CallUserCallbackForReconnect(Session *this)

{
  ulonglong *puVar1;
  undefined8 *puVar2;
  char cVar3;
  long lVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  ulonglong local_28 [2];
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  puVar5 = operator_new(0x30);
  if (puVar5 == (undefined8 *)0x0) {
    puVar5 = (undefined8 *)0x0;
  }
  else {
    *puVar5 = 0;
    puVar5[1] = 0;
    puVar5[2] = 0;
    puVar5[3] = 0;
    puVar5[5] = 0;
  }
  puVar5[4] = this;
  cVar3 = ExAcquireRundownProtection(this + 0x100);
  uVar6 = -(ulonglong)(cVar3 != '\0') & (ulonglong)(this + 0x100);
  puVar1 = puVar5 + 5;
  if (puVar1 == local_28) {
    if (uVar6 != 0) {
      ExReleaseRundownProtection(uVar6);
    }
  }
  else {
    if (*puVar1 != 0) {
      ExReleaseRundownProtection();
    }
    *puVar1 = uVar6;
  }
  puVar5[1] = <lambda_acf277aeafc9bc3b9cfb30dfc01ea4b2>::<lambda_invoker_cdecl><void_*,long,bool>;
  puVar5[2] = puVar5;
  puVar2 = *(undefined8 **)(this + 0xe0);
  local_18 = *(undefined4 *)(puVar2 + 1);
  uStack_14 = *(undefined4 *)((longlong)puVar2 + 0xc);
  uStack_10 = *(undefined4 *)(puVar2 + 2);
  uStack_c = *(undefined4 *)((longlong)puVar2 + 0x14);
  lVar4 = UserCallbackManager::CallUserCallback
                    ((UserCallbackManager *)&PTR_LOOP_14001a358,*puVar2,puVar5,&local_18);
  if ((lVar4 != 0x103) && (puVar5 != (undefined8 *)0x0)) {
    if (puVar5[5] != 0) {
      ExReleaseRundownProtection();
    }
    ExFreePoolWithTag(puVar5,0);
  }
  return lVar4;
}



===== CancelRxContext @ 140006ca0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl p9fs::Session::CancelRxContext(struct _RX_CONTEXT * __ptr64) */

long __cdecl p9fs::Session::CancelRxContext(_RX_CONTEXT *param_1)

{
  char cVar1;
  bool bVar2;
  longlong local_res8 [4];
  
  LOCK();
  local_res8[0] = *(longlong *)(param_1 + 0xd0);
  *(longlong *)(param_1 + 0xd0) = 0;
  UNLOCK();
  if ((((local_res8[0] != 0) && (cVar1 = *(char *)(local_res8[0] + 0x18), cVar1 != 'h')) &&
      (cVar1 != 'n')) && ((cVar1 != 'x' && (cVar1 != -0x7c)))) {
    LOCK();
    bVar2 = *(int *)(local_res8[0] + 0x60) == 0x103;
    if (bVar2) {
      *(int *)(local_res8[0] + 0x60) = -0x3ffffee0;
    }
    UNLOCK();
    if (bVar2) {
      (**(code **)(local_res8[0] + 0x38))(0xc0000120,*(undefined8 *)(local_res8[0] + 0x40));
    }
  }
  SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>((SharedPtr<p9fs::Exchange> *)local_res8);
  return 0;
}



===== CancelWaitIrp @ 140006d10 =====

/* public: virtual struct _IRP * __ptr64 __cdecl
   p9fs::Session::ContextCancellationManager::CancelWaitIrp(void)const __ptr64 */

_IRP * __thiscall
p9fs::Session::ContextCancellationManager::CancelWaitIrp(ContextCancellationManager *this)

{
  return *(_IRP **)(*(longlong *)(this + 8) + 0x28);
}



===== Cleanup @ 140006d20 =====

/* public: virtual void __cdecl p9fs::Session::ContextCancellationManager::Cleanup(void) __ptr64 */

void __thiscall p9fs::Session::ContextCancellationManager::Cleanup(ContextCancellationManager *this)

{
  undefined8 local_res8 [4];
  
  LOCK();
  local_res8[0] = *(undefined8 *)(*(longlong *)(this + 8) + 0xd0);
  *(undefined8 *)(*(longlong *)(this + 8) + 0xd0) = 0;
  UNLOCK();
  SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>((SharedPtr<p9fs::Exchange> *)local_res8);
  return;
}



===== CompleteRxContext @ 140006d4c =====

/* private: static void __cdecl p9fs::Session::CompleteRxContext(struct _RX_CONTEXT *
   __ptr64,long,unsigned __int64) */

void __cdecl p9fs::Session::CompleteRxContext(_RX_CONTEXT *param_1,long param_2,__uint64 param_3)

{
  undefined8 local_res8 [4];
  
  *(long *)(param_1 + 0xb0) = param_2;
  *(__uint64 *)(param_1 + 0xb8) = param_3;
  LOCK();
  local_res8[0] = *(undefined8 *)(param_1 + 0xd0);
  *(undefined8 *)(param_1 + 0xd0) = 0;
  UNLOCK();
  SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>((SharedPtr<p9fs::Exchange> *)local_res8);
  RxLowIoCompletion(param_1);
  return;
}



===== Connect @ 140006d98 =====

/* public: void __cdecl p9fs::Session::Connect(struct _MRX_CREATENETROOT_CONTEXT * __ptr64,class
   p9fs::SharedPtr<class p9fs::ConnectionTarget>) __ptr64 */

void __thiscall
p9fs::Session::Connect(Session *this,_MRX_CREATENETROOT_CONTEXT *param_1,longlong *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  ConnectionTarget *this_00;
  code *pcVar3;
  undefined8 uVar4;
  long lVar5;
  short sVar6;
  undefined1 *puVar7;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [40];
  
  lVar2 = *param_3;
  if (*(ConnectionTarget **)(this + 0xe0) != (ConnectionTarget *)0x0) {
    ConnectionTarget::ReleaseReference(*(ConnectionTarget **)(this + 0xe0));
  }
  *(longlong *)(this + 0xe0) = lVar2;
  sVar6 = 1;
  puVar7 = auStack_38;
  if (lVar2 != 0) {
    LOCK();
    plVar1 = (longlong *)(lVar2 + 0xe0);
    lVar2 = *plVar1;
    *plVar1 = *plVar1 + 1;
    UNLOCK();
    puVar7 = auStack_38;
    if (lVar2 + 1 < 2) {
      pcVar3 = (code *)swi(0x29);
      sVar6 = 1;
      (*pcVar3)(0xe);
      puVar7 = auStack_30;
    }
  }
  lVar2 = *param_3;
  if (*(short *)(lVar2 + 0x38) == sVar6) {
    uVar4 = *(undefined8 *)(lVar2 + 0xc0);
    *(undefined8 *)(this + 0x28) = *(undefined8 *)(lVar2 + 0xb8);
    *(undefined8 *)(this + 0x30) = uVar4;
  }
  lVar2 = *param_3;
  *(_MRX_CREATENETROOT_CONTEXT **)(puVar7 + 0x20) = param_1;
  *(undefined8 *)(puVar7 + -8) = 0x140006e2a;
  lVar5 = P9Client::Connect((P9Client *)(this + 0x50),(sockaddr *)(lVar2 + 0x38),
                            <lambda_64ac325a1dbb1a2c9a536140b95bfdf4>::
                            <lambda_invoker_cdecl><void_*>,
                            <lambda_3d39892d3c49c50879dfc58e2faecfe3>::
                            <lambda_invoker_cdecl><long,void_*>,*(void **)(puVar7 + 0x20));
  if (lVar5 != 0x103) {
    *(undefined8 *)(puVar7 + -8) = 0x140006e3b;
    FinalizeVNetRoot(param_1,lVar5);
  }
  this_00 = (ConnectionTarget *)*param_3;
  if (this_00 != (ConnectionTarget *)0x0) {
    *(undefined8 *)(puVar7 + -8) = 0x140006e48;
    ConnectionTarget::ReleaseReference(this_00);
  }
  *param_3 = 0;
  return;
}



===== DetermineIfDirectoryEmpty @ 140006e68 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl p9fs::Session::DetermineIfDirectoryEmpty(unsigned int,class
   p9fs::ICancellationManager & __ptr64) __ptr64 */

long __thiscall
p9fs::Session::DetermineIfDirectoryEmpty(Session *this,uint param_1,ICancellationManager *param_2)

{
  P9Client *this_00;
  longlong lVar1;
  ulonglong _Size;
  OpenFlags OVar2;
  int iVar3;
  char *pcVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined1 auStack_3f8 [32];
  undefined8 local_3d8;
  char *local_3c8;
  char *pcStack_3c0;
  undefined8 local_3b8;
  undefined8 local_3b0;
  P9Client *local_3a8;
  char *pcStack_3a0;
  undefined8 local_398;
  undefined8 local_390;
  char local_388 [8];
  OpenFlags local_380;
  char local_368 [8];
  OpenFlags local_360;
  DirectoryEnumerator local_348 [112];
  ulonglong local_2d8;
  void *local_2d0;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_3f8;
  local_3d8 = CONCAT62(local_3d8._2_6_,0x5c);
  local_3c8 = (char *)0x0;
  this_00 = (P9Client *)(this + 0x50);
  pcStack_3c0 = (char *)0x0;
  local_3a8 = (P9Client *)0x0;
  pcStack_3a0 = (char *)0x0;
  P9Client::WalkPath(this_00,local_388,param_1,&local_3a8);
  if (local_388[0] == '\0') {
    local_3a8 = (P9Client *)0x140016c60;
    local_398 = 0x268;
    pcStack_3a0 = "p9fs::Session::DetermineIfDirectoryEmpty";
    local_390 = 0;
    TraceLog((ErrorSite *)&local_3a8,local_380);
  }
  else {
    pcStack_3a0 = (char *)CONCAT44(pcStack_3a0._4_4_,local_380);
    local_3d8 = 0;
    local_3a8 = this_00;
    P9Client::Open(this_00,(uint)local_368,local_380,(ICancellationManager *)0x10000);
    if (local_368[0] == '\0') {
      local_3c8 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\session.cpp";
      local_3b8 = 0x26d;
      pcStack_3c0 = "p9fs::Session::DetermineIfDirectoryEmpty";
      local_3b0 = 0;
      TraceLog((ErrorSite *)&local_3c8,local_360);
      OVar2 = local_360;
    }
    else {
      DirectoryEnumerator::DirectoryEnumerator(local_348,this_00,local_380,0);
      pcVar4 = (char *)0x0;
      do {
        pcVar4 = pcVar4 + 1;
      } while (*(short *)(&u__ + (longlong)pcVar4 * 2) != 0);
      if (pcVar4 == (char *)0xffffffffffffffff) {
LAB_140007107:
                    /* WARNING: Subroutine does not return */
        gsl::details::terminate();
      }
      pcStack_3c0 = "*";
      local_3c8 = pcVar4;
      OVar2 = DirectoryEnumerator::Initialize(local_348,0x400,&local_3c8,1);
      if ((int)OVar2 < 0) {
        local_3b8 = 0x271;
        local_3c8 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\session.cpp";
        local_3b0 = 0;
        pcStack_3c0 = "p9fs::Session::DetermineIfDirectoryEmpty";
        TraceLog((ErrorSite *)&local_3c8,OVar2);
        DirectoryEnumerator::~DirectoryEnumerator(local_348);
      }
      else {
        OVar2 = DirectoryEnumerator::Next(local_348,param_2);
        _Size = local_2d8;
        while (-1 < (int)OVar2) {
          uVar6 = 0;
          do {
            uVar5 = uVar6 + 1;
            lVar1 = uVar6 + 1;
            uVar6 = uVar5;
          } while ("."[lVar1] != '\0');
          if (uVar5 == 0xffffffffffffffff) goto LAB_140007107;
          local_2d8 = _Size;
          if (((_Size < uVar5) || (uVar5 < _Size)) ||
             (iVar3 = memcmp(local_2d0,".",_Size), iVar3 != 0)) {
            uVar6 = 0;
            do {
              uVar5 = uVar6 + 1;
              pcVar4 = &DAT_1400170a5 + uVar6;
              uVar6 = uVar5;
            } while (*pcVar4 != '\0');
            if (uVar5 == 0xffffffffffffffff) goto LAB_140007107;
            if (((_Size < uVar5) || (uVar5 < _Size)) ||
               (iVar3 = memcmp(local_2d0,&s___,_Size), iVar3 != 0)) {
              DirectoryEnumerator::~DirectoryEnumerator(local_348);
              OVar2 = 0xc0000101;
              goto LAB_140007097;
            }
          }
          OVar2 = DirectoryEnumerator::Next(local_348,param_2);
          _Size = local_2d8;
        }
        DirectoryEnumerator::~DirectoryEnumerator(local_348);
        if (OVar2 == 0x80000006) {
          OVar2 = 0;
        }
      }
    }
LAB_140007097:
    UniqueFid::Reset((UniqueFid *)&local_3a8,0xffffffff);
    local_380 = OVar2;
  }
  return local_380;
}



===== Disconnect @ 140007114 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl p9fs::Session::Disconnect(void) __ptr64 */

void __thiscall p9fs::Session::Disconnect(Session *this)

{
  _IRP *p_Var1;
  char cVar2;
  uint uVar3;
  long lVar4;
  ulonglong uVar5;
  AutoResetEvent local_58 [8];
  _IRP *local_50;
  char *local_48;
  char *local_40;
  undefined8 local_38;
  char *local_30;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  if (*(int *)(this + 0xe8) != -1) {
    local_48 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\session.cpp";
    local_30 = "P9: Finalize VNetRoot fid = %d\n";
    local_40 = "p9fs::Session::ClunkRootFid";
    local_38 = 0x255;
    TraceLog((ErrorSite *)&local_48,0);
    uVar3 = P9Client::Clunk((P9Client *)(this + 0x50),*(uint *)(this + 0xe8));
    if ((int)uVar3 < 0) {
      local_30 = "P9: Clunk fid %d failed: 0x%x\n";
      local_48 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\session.cpp";
      local_40 = "p9fs::Session::ClunkRootFid";
      local_38 = 0x259;
      TraceLog((ErrorSite *)&local_48,-0x3fffffff,(ulonglong)*(uint *)(this + 0xe8),(ulonglong)uVar3
              );
    }
    *(undefined4 *)(this + 0xe8) = 0xffffffff;
  }
  cVar2 = ExAcquireRundownProtection(this + 0x10);
  uVar5 = -(ulonglong)(cVar2 != '\0') & (ulonglong)(this + 0x10);
  if (uVar5 != 0) {
    if ((this[0x20] == (Session)0x0) && (*(longlong *)(this + 0x18) != 0)) {
      KeInitializeEvent(&local_48,1);
      CreateSynchronousIrp(local_58);
      if (local_58[0] == (AutoResetEvent)0x0) {
        local_10 = (char *)0x0;
        local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\wsktransport.cpp";
        local_18 = 0x14b;
        local_20 = "p9fs::WskTransport::Disconnect";
        uVar3 = (uint)local_50;
        TraceLog((ErrorSite *)&local_28,uVar3);
      }
      else {
        lVar4 = (**(code **)(**(longlong **)(this + 0x18) + 0x40))
                          (*(longlong **)(this + 0x18),0,0,local_50);
        uVar3 = WaitForIrp(local_50,(AutoResetEvent *)&local_48,lVar4);
      }
      p_Var1 = local_50;
      if (local_58[0] != (AutoResetEvent)0x0) {
        local_50 = (_IRP *)0x0;
        if (p_Var1 != (_IRP *)0x0) {
          RxCeFreeIrp();
        }
      }
      ExReleaseRundownProtection(uVar5);
      goto LAB_1400072c5;
    }
    ExReleaseRundownProtection(uVar5);
  }
  uVar3 = 0;
LAB_1400072c5:
  if ((int)uVar3 < 0) {
    local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\session.cpp";
    local_10 = "P9: Disconnect failed: 0x%x\n";
    local_20 = "p9fs::Session::Disconnect";
    local_18 = 0x29d;
    TraceLog((ErrorSite *)&local_28,-0x3fffffff,(ulonglong)uVar3);
  }
  uVar3 = WskTransport::Close((WskTransport *)this);
  if ((int)uVar3 < 0) {
    local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\session.cpp";
    local_10 = "P9: Close socket failed: 0x%x\n";
    local_20 = "p9fs::Session::Disconnect";
    local_18 = 0x2a3;
    TraceLog((ErrorSite *)&local_28,-0x3fffffff,(ulonglong)uVar3);
  }
  return;
}



===== ErrorCallback @ 140007360 =====

/* private: static void __cdecl p9fs::Session::ErrorCallback(long,void * __ptr64) */

void __cdecl p9fs::Session::ErrorCallback(long param_1,void *param_2)

{
  CompleteRxContext(param_2,param_1,0);
  return;
}



===== FinalizeVNetRoot @ 140007380 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl p9fs::FinalizeVNetRoot(struct _MRX_CREATENETROOT_CONTEXT * __ptr64,long) */

void __cdecl p9fs::FinalizeVNetRoot(_MRX_CREATENETROOT_CONTEXT *param_1,long param_2)

{
  if (param_2 < 0) {
    if (*(longlong *)(*(longlong *)(param_1 + 0x108) + 0x28) != 0) {
      *(undefined8 *)(*(longlong *)(param_1 + 0x108) + 0x28) = 0;
      RxDispatchToWorkerThread
                (_GlobalDevice,3,
                 <lambda_23b9756acbd054bcd311d2b60eae7fdc>::<lambda_invoker_cdecl><void_*>);
    }
  }
  *(long *)(param_1 + 0x118) = param_2;
  DispatchIfNecessary(1,<lambda_a272816bb16cd9cb6687a6cf4df9bec5>::<lambda_invoker_cdecl><void_*>,
                      param_1);
  return;
}



===== ReadWorker @ 1400073f4 =====

/* public: long __cdecl p9fs::Session::ReadWorker(struct _RX_CONTEXT * __ptr64) __ptr64 */

long __thiscall p9fs::Session::ReadWorker(Session *this,_RX_CONTEXT *param_1)

{
  longlong lVar1;
  code *pcVar2;
  long lVar3;
  Exchange *pEVar4;
  undefined1 *puVar5;
  undefined1 uVar6;
  undefined1 auStackY_78 [8];
  undefined1 auStackY_70 [24];
  undefined4 in_stack_ffffffffffffffac;
  void *in_stack_ffffffffffffffb8;
  char local_38 [8];
  Exchange *local_30;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  P9Client::Read((P9Client *)(this + 0x50),(uint)local_38,
                 (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x48) + 0x30),
                 *(int *)(param_1 + 0xd8) + (int)*(undefined8 *)(param_1 + 0x220),
                 (_func_void_span<gsl::byte_const_,_1>_void_ptr *)
                 CONCAT44(in_stack_ffffffffffffffac,
                          *(int *)(param_1 + 0x228) - *(int *)(param_1 + 0xd8)),
                 <lambda_3fb1c450e0f042f5dc40e1c0009fe329>::
                 <lambda_invoker_cdecl><gsl::span<enum_gsl::byte_const_,_1>,void_*>,
                 in_stack_ffffffffffffffb8);
  puVar5 = auStackY_78;
  if (local_38[0] == '\0') {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\session.cpp";
    local_18 = 0x1bd;
    local_20 = "p9fs::Session::ReadWorker";
    lVar3 = (long)local_30;
    TraceLog((ErrorSite *)&local_28,lVar3);
    puVar5 = auStackY_78;
  }
  else {
    uVar6 = true;
    LOCK();
    pEVar4 = local_30 + 0x70;
    lVar1 = *(longlong *)pEVar4;
    *(longlong *)pEVar4 = *(longlong *)pEVar4 + 1;
    UNLOCK();
    pEVar4 = local_30;
    if (lVar1 + 1 < 2) {
      pcVar2 = (code *)swi(0x29);
      uVar6 = 1;
      (*pcVar2)(0xe);
      puVar5 = auStackY_70;
    }
    *(Exchange **)(param_1 + 0xd0) = pEVar4;
    *(undefined8 *)(puVar5 + -8) = 0x1400074ba;
    lVar3 = P9Client::SendExchange((P9Client *)(this + 0x50),local_30,(bool)uVar6);
  }
  if (local_38[0] != '\0') {
    *(undefined8 *)(puVar5 + -8) = 0x1400074cb;
    SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>((SharedPtr<p9fs::Exchange> *)&local_30);
  }
  return lVar3;
}



===== Reconnect @ 1400074e8 =====

/* private: void __cdecl p9fs::Session::Reconnect(bool) __ptr64 */

void __thiscall p9fs::Session::Reconnect(Session *this,bool param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  code *pcVar3;
  undefined8 uVar4;
  uint uVar5;
  long lVar6;
  ConnectionTarget *pCVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  short sVar10;
  ConnectionTarget *local_res8;
  undefined1 auStack_c8 [8];
  undefined1 auStack_c0 [40];
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  char *local_88;
  char *local_80;
  undefined8 local_78;
  undefined8 local_70;
  char *local_68;
  char *local_60;
  undefined8 local_58;
  char *local_50;
  ConnectionTargetKey local_48 [32];
  
  lVar6 = 0;
  if (this[0x20] == (Session)0x0) {
    if (*(longlong *)(this + 0x18) != 0) goto LAB_14000755a;
  }
  else {
    this[0x20] = (Session)0x0;
    lVar6 = WskTransport::Close((WskTransport *)this);
    if (lVar6 < 0) {
      local_78 = 0x184;
      local_88 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\wsktransport.cpp";
      local_70 = 0;
      local_80 = "p9fs::WskTransport::Reinitialize";
      TraceLog((ErrorSite *)&local_88,lVar6);
LAB_14000755a:
      P9Client::FinishReconnect((P9Client *)(this + 0x50),lVar6);
      return;
    }
    ExReInitializeRundownProtection(this + 0x10);
  }
  local_58 = 0xe1;
  local_50 = "P9: Attempting to reconnect.\n";
  local_68 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\session.cpp";
  local_60 = "p9fs::Session::Reconnect";
  TraceLog((ErrorSite *)&local_68,0);
  puVar2 = *(undefined8 **)(this + 0xe0);
  local_98 = *(undefined4 *)(puVar2 + 1);
  uStack_94 = *(undefined4 *)((longlong)puVar2 + 0xc);
  uStack_90 = *(undefined4 *)(puVar2 + 2);
  uStack_8c = *(undefined4 *)((longlong)puVar2 + 0x14);
  ConnectionTargetKey::ConnectionTargetKey(local_48,*puVar2,&local_98);
  ConnectionTargetTree::Find
            ((ConnectionTargetTree *)&DAT_14001a340,(ConnectionTargetKey *)&local_res8);
  pCVar7 = local_res8;
  if (local_res8 == (ConnectionTarget *)0x0) {
    if (param_1) {
      uVar5 = CallUserCallbackForReconnect(this);
      puVar9 = auStack_c8;
      if (-1 < (int)uVar5) goto LAB_1400076c2;
      local_68 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\session.cpp";
      local_50 = "P9: User callback failed 0x%x\n";
      local_60 = "p9fs::Session::Reconnect";
      local_58 = 0xf0;
      TraceLog((ErrorSite *)&local_68,-0x3fffffff,(ulonglong)uVar5);
    }
    puVar9 = auStack_c8;
    lVar6 = -0x3fffff34;
  }
  else {
    if (*(ConnectionTarget **)(this + 0xe0) != (ConnectionTarget *)0x0) {
      ConnectionTarget::ReleaseReference(*(ConnectionTarget **)(this + 0xe0));
    }
    puVar8 = auStack_c8;
    *(ConnectionTarget **)(this + 0xe0) = pCVar7;
    sVar10 = 1;
    puVar9 = auStack_c8;
    if (pCVar7 != (ConnectionTarget *)0x0) {
      LOCK();
      pCVar7 = pCVar7 + 0xe0;
      lVar1 = *(longlong *)pCVar7;
      *(longlong *)pCVar7 = *(longlong *)pCVar7 + 1;
      UNLOCK();
      sVar10 = 1;
      if (lVar1 + 1 < 2) {
        pcVar3 = (code *)swi(0x29);
        sVar10 = 1;
        (*pcVar3)(0xe);
        puVar8 = auStack_c0;
      }
      pCVar7 = local_res8;
      puVar9 = puVar8;
    }
    lVar1 = *(longlong *)(this + 0xe0);
    if (*(short *)(lVar1 + 0x38) == sVar10) {
      uVar4 = *(undefined8 *)(lVar1 + 0xc0);
      *(undefined8 *)(this + 0x28) = *(undefined8 *)(lVar1 + 0xb8);
      *(undefined8 *)(this + 0x30) = uVar4;
    }
    *(Session **)(puVar9 + 0x20) = this;
    *(undefined8 *)(puVar9 + -8) = 0x1400076b0;
    lVar6 = P9Client::Connect((P9Client *)(this + 0x50),(sockaddr *)(lVar1 + 0x38),
                              <lambda_29e28994f96b9e1fb9850352512e0e1f>::
                              <lambda_invoker_cdecl><void_*>,
                              <lambda_03050e333895841c5623010b92b7b52d>::
                              <lambda_invoker_cdecl><long,void_*>,*(void **)(puVar9 + 0x20));
    if (lVar6 == 0x103) goto LAB_1400076c2;
  }
  *(undefined8 *)(puVar9 + -8) = 0x1400076c2;
  P9Client::FinishReconnect((P9Client *)(this + 0x50),lVar6);
LAB_1400076c2:
  if (pCVar7 == (ConnectionTarget *)0x0) {
    return;
  }
  *(undefined8 *)(puVar9 + -8) = 0x1400076cf;
  ConnectionTarget::ReleaseReference(pCVar7);
  return;
}



===== ReconnectCallback @ 140007700 =====

/* private: static void __cdecl p9fs::Session::ReconnectCallback(void * __ptr64) */

void __cdecl p9fs::Session::ReconnectCallback(void *param_1)

{
  Reconnect(param_1,true);
  return;
}



===== RegisterExchange @ 140007720 =====

/* public: virtual long __cdecl p9fs::Session::ContextCancellationManager::RegisterExchange(class
   p9fs::Exchange & __ptr64) __ptr64 */

long __thiscall
p9fs::Session::ContextCancellationManager::RegisterExchange
          (ContextCancellationManager *this,Exchange *param_1)

{
  Exchange *pEVar1;
  longlong lVar2;
  code *pcVar3;
  longlong lVar4;
  
  lVar4 = *(longlong *)(this + 8);
  if ((*(uint *)(lVar4 + 0x80) & 2) != 0) {
    return -0x3ffffee0;
  }
  LOCK();
  pEVar1 = param_1 + 0x70;
  lVar2 = *(longlong *)pEVar1;
  *(longlong *)pEVar1 = *(longlong *)pEVar1 + 1;
  UNLOCK();
  if (lVar2 + 1 < 2) {
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(0xe);
  }
  *(Exchange **)(lVar4 + 0xd0) = param_1;
  return 0;
}



===== Reset @ 140007764 =====

/* public: long __cdecl p9fs::UniqueFid::Reset(unsigned int) __ptr64 */

long __thiscall p9fs::UniqueFid::Reset(UniqueFid *this,uint param_1)

{
  long lVar1;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  if ((*(uint *)(this + 8) == 0xffffffff) ||
     (lVar1 = P9Client::Clunk(*(P9Client **)this,*(uint *)(this + 8)), -1 < lVar1)) {
    *(uint *)(this + 8) = param_1;
    return 0;
  }
  local_10 = 0;
  local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.h";
  local_18 = 0xfa;
  local_20 = "p9fs::UniqueFid::Reset";
  TraceLog((ErrorSite *)&local_28,lVar1);
  return lVar1;
}



===== WriteWorker @ 1400077e4 =====

/* public: long __cdecl p9fs::Session::WriteWorker(struct _RX_CONTEXT * __ptr64) __ptr64 */

long __thiscall p9fs::Session::WriteWorker(Session *this,_RX_CONTEXT *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  longlong lVar4;
  code *pcVar5;
  long lVar6;
  longlong lVar7;
  ulonglong uVar8;
  Exchange *pEVar9;
  undefined1 *puVar10;
  undefined1 auStack_88 [8];
  undefined1 auStack_80 [24];
  char **local_68;
  code *local_60;
  _RX_CONTEXT *local_50;
  char local_48 [8];
  Exchange *local_40;
  char *local_38;
  char *local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  lVar7 = *(longlong *)(param_1 + 0x210);
  uVar1 = *(uint *)(param_1 + 0xd8);
  lVar4 = *(longlong *)(param_1 + 0x220);
  uVar2 = *(undefined4 *)(*(longlong *)(param_1 + 0x48) + 0x30);
  uVar3 = *(uint *)(param_1 + 0x228);
  if ((*(byte *)(lVar7 + 10) & 5) == 0) {
    local_60 = (code *)CONCAT44(local_60._4_4_,0x40000010);
    local_68 = (char **)((ulonglong)local_68 & 0xffffffff00000000);
    lVar7 = MmMapLockedPagesSpecifyCache(lVar7,0,1);
  }
  else {
    lVar7 = *(longlong *)(lVar7 + 0x18);
  }
  if ((((lVar7 == 0) && (uVar3 != 0)) ||
      (uVar8 = (ulonglong)*(uint *)(param_1 + 0xd8), uVar3 < uVar8)) ||
     (local_38 = (char *)(uVar3 - uVar8), local_38 == (char *)0xffffffffffffffff)) {
                    /* WARNING: Subroutine does not return */
    gsl::details::terminate();
  }
  local_30 = (char *)(lVar7 + uVar8);
  local_60 = <lambda_8804cf93af8d009258c5b36c41b58831>::<lambda_invoker_cdecl><unsigned_int,void_*>;
  local_68 = &local_38;
  local_50 = param_1;
  P9Client::Write((P9Client *)(this + 0x50),local_48,uVar2,(ulonglong)uVar1 + lVar4);
  puVar10 = auStack_88;
  if (local_48[0] == '\0') {
    local_20 = 0;
    local_38 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\session.cpp";
    local_28 = 0x20f;
    local_30 = "p9fs::Session::WriteWorker";
    lVar6 = (long)local_40;
    TraceLog((ErrorSite *)&local_38,lVar6);
    puVar10 = auStack_88;
  }
  else {
    LOCK();
    pEVar9 = local_40 + 0x70;
    lVar7 = *(longlong *)pEVar9;
    *(longlong *)pEVar9 = *(longlong *)pEVar9 + 1;
    UNLOCK();
    pEVar9 = local_40;
    if (lVar7 + 1 < 2) {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(0xe);
      puVar10 = auStack_80;
    }
    *(Exchange **)(param_1 + 0xd0) = pEVar9;
    *(undefined8 *)(puVar10 + -8) = 0x140007953;
    lVar6 = P9Client::SendExchange((P9Client *)(this + 0x50),local_40,true);
  }
  if (local_48[0] != '\0') {
    *(undefined8 *)(puVar10 + -8) = 0x140007900;
    SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>((SharedPtr<p9fs::Exchange> *)&local_40);
  }
  return lVar6;
}



===== operator_new @ 140007964 =====

/* void * __ptr64 __cdecl operator new(unsigned __int64) */

void * __cdecl operator_new(__uint64 param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)ExAllocatePool2(0x40,param_1,0x78523950);
  return pvVar1;
}



===== ConvertFileAttributes @ 140007990 =====

/* unsigned long __cdecl p9fs::ConvertFileAttributes(struct p9fs::StatResult const &
   __ptr64,unsigned long * __ptr64) */

ulong __cdecl p9fs::ConvertFileAttributes(StatResult *param_1,ulong *param_2)

{
  undefined8 uVar1;
  ulong uVar2;
  
  uVar2 = 0x10;
  if ((*(uint *)param_1 & 0xf000) != 0x4000) {
    uVar2 = 0;
  }
  uVar1 = LxUtilFsFileModeToReparseTag(*(uint *)param_1);
  if (((ulong)uVar1 != 0) && (uVar2 = uVar2 | 0x400, param_2 != (ulong *)0x0)) {
    *param_2 = (ulong)uVar1;
  }
  if (uVar2 == 0) {
    uVar2 = 0x80;
  }
  return uVar2;
}



===== ConvertFileSize @ 1400079e4 =====

/* void __cdecl p9fs::ConvertFileSize(struct p9fs::StatResult const & __ptr64,union _LARGE_INTEGER &
   __ptr64,union _LARGE_INTEGER & __ptr64) */

void __cdecl
p9fs::ConvertFileSize(StatResult *param_1,_LARGE_INTEGER *param_2,_LARGE_INTEGER *param_3)

{
  undefined8 uVar1;
  
  if ((*(uint *)param_1 & 0xf000) == 0x4000) {
    *(undefined8 *)param_2 = 0;
    *(undefined8 *)param_3 = 0;
    return;
  }
  uVar1 = *(undefined8 *)(param_1 + 0x20);
  *(undefined8 *)param_2 = uVar1;
  if (*(longlong *)(param_1 + 0x30) == 0) {
    *(undefined8 *)param_3 = uVar1;
    return;
  }
  *(longlong *)param_3 = *(longlong *)(param_1 + 0x30) << 9;
  return;
}



===== ConvertFileTimes @ 140007a20 =====

/* void __cdecl p9fs::ConvertFileTimes(struct p9fs::StatResult const & __ptr64,union _LARGE_INTEGER
   & __ptr64,union _LARGE_INTEGER & __ptr64,union _LARGE_INTEGER & __ptr64,union _LARGE_INTEGER &
   __ptr64) */

void __cdecl
p9fs::ConvertFileTimes
          (StatResult *param_1,_LARGE_INTEGER *param_2,_LARGE_INTEGER *param_3,
          _LARGE_INTEGER *param_4,_LARGE_INTEGER *param_5)

{
  longlong lVar1;
  longlong lVar2;
  longlong local_18;
  undefined8 local_10;
  
  local_18 = *(longlong *)(param_1 + 0x58);
  local_10 = *(undefined8 *)(param_1 + 0x60);
  LxUtilTimespecToNtTime((ulonglong *)param_5,&local_18);
  local_18 = *(longlong *)(param_1 + 0x38);
  local_10 = *(undefined8 *)(param_1 + 0x40);
  LxUtilTimespecToNtTime((ulonglong *)param_3,&local_18);
  local_18 = *(longlong *)(param_1 + 0x48);
  local_10 = *(undefined8 *)(param_1 + 0x50);
  LxUtilTimespecToNtTime((ulonglong *)param_4,&local_18);
  lVar2 = *(longlong *)param_5;
  if (*(longlong *)param_3 <= *(longlong *)param_5) {
    lVar2 = *(longlong *)param_3;
  }
  lVar1 = *(longlong *)param_4;
  if (lVar2 < *(longlong *)param_4) {
    lVar1 = lVar2;
  }
  *(longlong *)param_2 = lVar1;
  return;
}



===== DereferenceObject @ 140007ae0 =====

/* void __cdecl p9fs::details::DereferenceObject(void * __ptr64) */

void __cdecl p9fs::details::DereferenceObject(void *param_1)

{
  ObfDereferenceObject();
  return;
}



===== DispatchIfNecessary @ 140007afc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* long __cdecl p9fs::DispatchIfNecessary(enum _RX_WORK_QUEUE_TYPE,void (__cdecl*)(void *
   __ptr64),void * __ptr64) */

long __cdecl
p9fs::DispatchIfNecessary(_RX_WORK_QUEUE_TYPE param_1,_func_void_void_ptr *param_2,void *param_3)

{
  byte bVar1;
  long lVar2;
  
  bVar1 = KeGetCurrentIrql();
  if (bVar1 < 2) {
    (*param_2)(param_3);
    lVar2 = 0;
  }
  else {
    lVar2 = RxDispatchToWorkerThread(_GlobalDevice,param_1,param_2,param_3);
  }
  return lVar2;
}



===== GetLogonInformation @ 140007b64 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* struct p9fs::LogonInformation __cdecl p9fs::GetLogonInformation(struct _SECURITY_SUBJECT_CONTEXT
   * __ptr64) */

_SECURITY_SUBJECT_CONTEXT * __cdecl p9fs::GetLogonInformation(_SECURITY_SUBJECT_CONTEXT *param_1)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  longlong lVar4;
  longlong *in_RDX;
  undefined1 auStack_78 [32];
  void *local_58;
  int *local_50;
  char *local_48;
  char *local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  SeLockSubjectContext();
  lVar4 = *in_RDX;
  local_20 = 0;
  uStack_18 = 0;
  if (lVar4 == 0) {
    lVar4 = in_RDX[2];
  }
  SeQueryAuthenticationIdToken(lVar4,&local_20);
  lVar4 = *in_RDX;
  if (lVar4 == 0) {
    lVar4 = in_RDX[2];
  }
  local_50 = (int *)0x0;
  iVar2 = SeQueryInformationToken(lVar4,0x12,&local_50);
  if (iVar2 < 0) {
    local_30 = 0;
    local_48 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\util.cpp";
    local_38 = 0xb9;
    local_40 = "p9fs::GetLinkedLogonId";
    TraceLog((ErrorSite *)&local_48,iVar2);
LAB_140007cbc:
    if (local_50 != (int *)0x0) goto LAB_140007cc5;
  }
  else {
    local_58 = (void *)0x0;
    if (*local_50 == 2) {
      lVar3 = SeGetLinkedToken(3,lVar4,&local_58);
      if (-1 < lVar3) {
LAB_140007cdb:
        local_28 = 0;
        SeQueryAuthenticationIdToken(local_58,&local_28);
        uVar1 = local_28;
        if (local_58 != (void *)0x0) {
          details::DereferenceObject(local_58);
        }
        if (local_50 != (int *)0x0) {
          ExFreePool();
        }
        uStack_18 = uVar1;
        goto LAB_140007d1f;
      }
      local_38 = 0xc2;
LAB_140007c88:
      local_30 = 0;
      local_48 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\util.cpp";
      local_40 = "p9fs::GetLinkedLogonId";
      TraceLog((ErrorSite *)&local_48,lVar3);
      if (local_58 != (void *)0x0) {
        details::DereferenceObject(local_58);
      }
      goto LAB_140007cbc;
    }
    if (*local_50 == 3) {
      lVar3 = SeGetLinkedToken(2,lVar4,&local_58);
      if (-1 < lVar3) goto LAB_140007cdb;
      local_38 = 0xbe;
      goto LAB_140007c88;
    }
LAB_140007cc5:
    ExFreePool();
  }
  uStack_18 = local_20;
LAB_140007d1f:
  *(undefined4 *)param_1 = (undefined4)local_20;
  *(undefined4 *)(param_1 + 4) = local_20._4_4_;
  *(undefined4 *)(param_1 + 8) = (undefined4)uStack_18;
  *(undefined4 *)(param_1 + 0xc) = uStack_18._4_4_;
  if (in_RDX != (longlong *)0x0) {
    SeUnlockSubjectContext();
  }
  return param_1;
}



===== IsValidDistributionName @ 140007d68 =====

/* bool __cdecl p9fs::IsValidDistributionName(class std::basic_string_view<unsigned short>) */

bool __cdecl p9fs::IsValidDistributionName(ulonglong *param_1)

{
  ushort uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  bool bVar4;
  bool bVar5;
  
  uVar2 = *param_1;
  if (uVar2 < 0x101) {
    uVar3 = 0;
    if (uVar2 != 0) {
      if (uVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        gsl::details::terminate();
      }
      do {
        uVar1 = *(ushort *)(param_1[1] + uVar3 * 2);
        if (uVar1 < 0x61) {
          if (uVar1 < 0x41) {
            if (0x2f < uVar1) {
              bVar4 = uVar1 < 0x39;
              bVar5 = uVar1 == 0x39;
              goto LAB_140007d9d;
            }
            bVar4 = uVar1 == 0x2d;
            bVar5 = uVar1 == 0x2e;
          }
          else {
            bVar4 = uVar1 < 0x5a;
            bVar5 = uVar1 == 0x5a;
          }
          if ((!bVar4 && !bVar5) && (uVar1 != 0x5f)) goto LAB_140007d9f;
        }
        else {
          bVar4 = uVar1 < 0x7a;
          bVar5 = uVar1 == 0x7a;
LAB_140007d9d:
          if (!bVar4 && !bVar5) goto LAB_140007d9f;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < uVar2);
    }
    bVar4 = true;
  }
  else {
LAB_140007d9f:
    bVar4 = false;
  }
  return bVar4;
}



===== NtPathUnescape @ 140007de8 =====

/* class util::BasicExpected<class p9fs::UnescapedPath,long> __cdecl p9fs::NtPathUnescape(class
   std::basic_string_view<unsigned short>) */

undefined1 * __cdecl p9fs::NtPathUnescape(undefined1 *param_1,short *param_2)

{
  int iVar1;
  undefined8 local_res10;
  undefined8 local_38;
  longlong lStack_30;
  char *local_28;
  char *pcStack_20;
  undefined8 local_18;
  undefined8 local_10;
  
  pcStack_20 = *(char **)(param_2 + 4);
  local_res10 = 0;
  local_38 = (char *)(ulonglong)CONCAT22(*param_2 * 2,*param_2 * 2);
  local_28 = local_38;
  local_38 = (char *)0x0;
  lStack_30 = 0;
  iVar1 = LxUtilNtPathUnescape((ushort *)&local_28,(ushort *)&local_38,&local_res10);
  if (iVar1 < 0) {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\util.cpp";
    local_18 = 0xf9;
    pcStack_20 = "p9fs::NtPathUnescape";
    TraceLog((ErrorSite *)&local_28,iVar1);
    *param_1 = 0;
    *(int *)(param_1 + 8) = iVar1;
  }
  else {
    local_28 = (char *)((ulonglong)local_38 >> 1 & 0x7fff);
    pcStack_20 = (char *)lStack_30;
    if ((lStack_30 == 0) && (local_28 != (char *)0x0)) {
                    /* WARNING: Subroutine does not return */
      gsl::details::terminate();
    }
    *param_1 = 1;
    *(char **)(param_1 + 8) = local_28;
    *(longlong *)(param_1 + 0x10) = lStack_30;
    *(undefined8 *)(param_1 + 0x18) = local_res10;
  }
  return param_1;
}



===== TraceLog @ 140007ed4 =====

/* void __cdecl p9fs::TraceLog(struct ErrorSite const & __ptr64,long,...) */

void __cdecl p9fs::TraceLog(ErrorSite *param_1,long param_2,...)

{
  undefined8 in_R8;
  undefined8 in_R9;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = in_R8;
  local_res20 = in_R9;
  TraceLogHelper(param_1,param_2,(char *)&local_res18);
  return;
}



===== TraceLogHelper @ 140007efc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl TraceLogHelper(struct ErrorSite const & __ptr64,long,char * __ptr64) */

void __cdecl TraceLogHelper(ErrorSite *param_1,long param_2,char *param_3)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  byte *pbVar6;
  undefined1 auStackY_2d8 [32];
  undefined4 uVar7;
  undefined4 local_298;
  long local_294 [3];
  undefined8 local_288 [4];
  char *local_268;
  int local_260;
  undefined4 local_25c;
  undefined4 *local_258;
  undefined8 local_250;
  long *local_248;
  ulonglong local_240;
  undefined4 *local_238;
  int local_230;
  undefined4 local_22c;
  undefined4 local_228;
  undefined1 local_29;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_2d8;
  if ((DAT_14001a008 == 0) && (!p9fs::P9DebugOutputEnabled)) {
    return;
  }
  local_228._0_1_ = '\0';
  if ((*(char **)(param_1 + 0x18) != (char *)0x0) &&
     ((uVar2 = _vsnprintf((char *)&local_228,0x1ff,*(char **)(param_1 + 0x18),param_3),
      (int)uVar2 < 0 || (0x1fe < uVar2)))) {
    local_29 = 0;
  }
  if (param_2 < 0) {
    if (DAT_14001a008 < 3) goto LAB_1400080c3;
    local_298 = *(undefined4 *)(param_1 + 0x10);
    lVar3 = -1;
    lVar5 = -1;
    do {
      lVar4 = lVar5 + 1;
      lVar1 = lVar5 + 1;
      lVar5 = lVar4;
    } while (*(char *)((longlong)&local_228 + lVar1) != '\0');
    local_230 = (int)lVar4 + 1;
    local_22c = 0;
    local_238 = &local_228;
    local_248 = local_294;
    local_268 = *(char **)param_1;
    local_240 = 4;
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
    pbVar6 = &DAT_140018344;
    uVar7 = 6;
    local_294[0] = param_2;
  }
  else {
    if (DAT_14001a008 < 5) goto LAB_1400080c3;
    local_298 = *(undefined4 *)(param_1 + 0x10);
    lVar3 = -1;
    lVar5 = -1;
    do {
      lVar4 = lVar5 + 1;
      lVar1 = lVar5 + 1;
      lVar5 = lVar4;
    } while (*(char *)((longlong)&local_228 + lVar1) != '\0');
    local_240 = (ulonglong)((int)lVar4 + 1);
    local_248 = &local_228;
    local_268 = *(char **)param_1;
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
    pbVar6 = &DAT_140018311;
    uVar7 = 5;
  }
  local_250 = 4;
  local_258 = &local_298;
  local_25c = 0;
  _tlgWriteTransfer_EtwWriteTransfer(0x14001a008,pbVar6,0,0,uVar7,local_288);
LAB_1400080c3:
  if (p9fs::P9DebugOutputEnabled != false) {
    DbgPrintEx(0,0,"(%s:%d): %x: %s",*(undefined8 *)param_1);
  }
  return;
}



===== QueryFileInfo @ 140008124 =====

/* public: long __cdecl p9fs::Session::QueryFileInfo(struct _RX_CONTEXT * __ptr64) __ptr64 */

long __thiscall p9fs::Session::QueryFileInfo(Session *this,_RX_CONTEXT *param_1)

{
  uint uVar1;
  _LARGE_INTEGER *p_Var2;
  int iVar3;
  ulong uVar4;
  longlong lVar5;
  ICancellationManager *pIVar6;
  char *local_e8;
  char *local_e0;
  undefined8 local_d8;
  char *local_d0;
  undefined **local_c8;
  _RX_CONTEXT *local_c0;
  char local_b8 [8];
  uint local_b0;
  uint local_98 [4];
  undefined4 local_88;
  
  p_Var2 = *(_LARGE_INTEGER **)(param_1 + 0x1b8);
  iVar3 = *(int *)(param_1 + 0x1b0);
  if (iVar3 == 4) {
    pIVar6 = (ICancellationManager *)0xe1;
  }
  else if (iVar3 == 5) {
    pIVar6 = (ICancellationManager *)0x603;
  }
  else {
    if (iVar3 == 6) {
      if (7 < *(uint *)(param_1 + 0x1c8)) {
        *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) - 8;
        *(undefined8 *)p_Var2 = *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 0xf0);
        return 0;
      }
      local_d8 = 0x15;
      local_e0 = "p9fs::FillInternalInfo";
      goto LAB_14000859d;
    }
    if (iVar3 == 7) {
      if (3 < *(uint *)(param_1 + 0x1c8)) {
        *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) - 4;
        *(undefined4 *)p_Var2 = 0;
        return 0;
      }
      local_d8 = 0x49;
      local_e0 = "p9fs::FillEaInfo";
      goto LAB_14000859d;
    }
    if (iVar3 == 0x16) {
      return -0x3fffff45;
    }
    if (iVar3 == 0x22) {
      pIVar6 = (ICancellationManager *)0x6e1;
    }
    else {
      if (iVar3 != 0x23) {
        if (iVar3 == 0x30) {
          return -0x3fffff45;
        }
        if (iVar3 != 0x37) {
          local_d8 = 0x134;
          local_e8 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\fileinfo.cpp";
          local_e0 = "p9fs::Session::QueryFileInfo";
          local_d0 = "P9: Unsupported file info class: %d\n";
          TraceLog((ErrorSite *)&local_e8,-0x3fffffff);
          return -0x3fffff45;
        }
        if (0x73 < *(uint *)(param_1 + 0x1c8)) {
          *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) - 0x74;
          memset(p_Var2 + 0xc,0,0x68);
          *(undefined4 *)p_Var2 = 0x740001;
          *(undefined4 *)(p_Var2 + 4) = 0x480000;
          *(undefined4 *)(p_Var2 + 8) = 1;
          return 0;
        }
        local_d8 = 0x27;
        local_e0 = "p9fs::FillRemoteProtocolInfo";
        goto LAB_14000859d;
      }
      pIVar6 = (ICancellationManager *)0x1;
    }
  }
  uVar1 = *(uint *)(param_1 + 0x78);
  if ((uVar1 >> 0xc & 1) != 0) {
    if ((uVar1 & 2) == 0) {
      param_1[0x23] = (_RX_CONTEXT)0x1;
      return -0x3fbefffd;
    }
    *(uint *)(param_1 + 0x78) = uVar1 & 0xffffefff;
  }
  iVar3 = RxSetMinirdrCancelRoutine(param_1,CancelRxContext);
  if (iVar3 < 0) {
    local_d8 = 0x13c;
    local_e8 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\fileinfo.cpp";
    local_d0 = (char *)0x0;
    local_e0 = "p9fs::Session::QueryFileInfo";
    TraceLog((ErrorSite *)&local_e8,iVar3);
    return iVar3;
  }
  local_c8 = &ContextCancellationManager::_vftable_;
  local_c0 = param_1;
  P9Client::GetAttr((P9Client *)(this + 0x50),(uint)local_b8,
                    (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x48) + 0x30),pIVar6);
  if (local_b8[0] == '\0') {
    local_e8 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\fileinfo.cpp";
    local_d8 = 0x142;
    local_e0 = "p9fs::Session::QueryFileInfo";
    local_d0 = (char *)0x0;
    TraceLog((ErrorSite *)&local_e8,local_b0);
    return local_b0;
  }
  if ((ICancellationManager *)((ulonglong)local_b0 & (ulonglong)pIVar6) != pIVar6) {
    return -0x3ffffe7a;
  }
  iVar3 = *(int *)(param_1 + 0x1b0);
  if (iVar3 == 4) {
    if (0x27 < *(uint *)(param_1 + 0x1c8)) {
      *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) - 0x28;
      ConvertFileTimes((StatResult *)local_98,p_Var2,p_Var2 + 8,p_Var2 + 0x10,p_Var2 + 0x18);
      uVar4 = ConvertFileAttributes((StatResult *)local_98,(ulong *)0x0);
      *(ulong *)(p_Var2 + 0x20) = uVar4;
      return 0;
    }
    local_d8 = 0xc;
    local_e0 = "p9fs::FillBasicInfo";
  }
  else if (iVar3 == 5) {
    lVar5 = *(longlong *)(param_1 + 0x38);
    if (0x17 < *(uint *)(param_1 + 0x1c8)) {
      *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) - 0x18;
      p_Var2[0x15] = (_LARGE_INTEGER)((local_98[0] & 0xf000) == 0x4000);
      ConvertFileSize((StatResult *)local_98,p_Var2 + 8,p_Var2);
      *(undefined4 *)(p_Var2 + 0x10) = local_88;
      p_Var2[0x14] = (_LARGE_INTEGER)(*(byte *)(lVar5 + 0x9c) & 1);
      return 0;
    }
    local_d8 = 0x36;
    local_e0 = "p9fs::FillStandardInfo";
  }
  else if (iVar3 == 0x22) {
    if (0x37 < *(uint *)(param_1 + 0x1c8)) {
      *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) - 0x38;
      ConvertFileSize((StatResult *)local_98,p_Var2 + 0x28,p_Var2 + 0x20);
      ConvertFileTimes((StatResult *)local_98,p_Var2,p_Var2 + 8,p_Var2 + 0x10,p_Var2 + 0x18);
      uVar4 = ConvertFileAttributes((StatResult *)local_98,(ulong *)0x0);
      *(ulong *)(p_Var2 + 0x30) = uVar4;
      return 0;
    }
    local_d8 = 0x1d;
    local_e0 = "p9fs::FillNetworkOpenInfo";
  }
  else {
    if (iVar3 != 0x23) {
      return -0x3fffff45;
    }
    if (7 < *(uint *)(param_1 + 0x1c8)) {
      *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) - 8;
      uVar4 = ConvertFileAttributes((StatResult *)local_98,(ulong *)(p_Var2 + 4));
      *(ulong *)p_Var2 = uVar4;
      return 0;
    }
    local_d8 = 0x53;
    local_e0 = "p9fs::FillAttributeTagInfo";
  }
LAB_14000859d:
  local_e8 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\fileinfo.cpp";
  local_d0 = (char *)0x0;
  TraceLog((ErrorSite *)&local_e8,-0x7ffffffb);
  return -0x7ffffffb;
}



===== SetFileInfo @ 1400085e4 =====

/* public: long __cdecl p9fs::Session::SetFileInfo(struct _RX_CONTEXT * __ptr64) __ptr64 */

long __thiscall p9fs::Session::SetFileInfo(Session *this,_RX_CONTEXT *param_1)

{
  uint uVar1;
  _FILE_RENAME_INFORMATION *p_Var2;
  int iVar3;
  long lVar4;
  uint uVar5;
  undefined **local_b8;
  _RX_CONTEXT *p_Stack_b0;
  char *local_a8;
  char *local_a0;
  undefined8 local_98;
  char *local_90;
  StatResult local_88 [32];
  undefined8 local_68;
  undefined **local_50;
  undefined8 local_48;
  undefined **local_40;
  undefined8 local_38;
  
  p_Var2 = *(_FILE_RENAME_INFORMATION **)(param_1 + 0x1b8);
  lVar4 = 0;
  uVar5 = 0;
  memset(local_88,0,0x68);
  iVar3 = *(int *)(param_1 + 0x1b0);
  if (iVar3 == 4) {
    if (0 < *(longlong *)(p_Var2 + 0x10)) {
      local_b8 = (undefined **)0x0;
      p_Stack_b0 = (_RX_CONTEXT *)0x0;
      uVar5 = 0x120;
      LxUtilNtTimeToTimespec((longlong *)&local_b8,*(longlong *)(p_Var2 + 0x10));
      local_38 = p_Stack_b0;
      local_40 = local_b8;
    }
    if (0 < *(longlong *)(p_Var2 + 8)) {
      local_b8 = (undefined **)0x0;
      p_Stack_b0 = (_RX_CONTEXT *)0x0;
      uVar5 = uVar5 | 0x90;
      LxUtilNtTimeToTimespec((longlong *)&local_b8,*(longlong *)(p_Var2 + 8));
      local_48 = p_Stack_b0;
      local_50 = local_b8;
    }
    uVar1 = uVar5 | 0x40;
    if (*(longlong *)(p_Var2 + 0x18) < 1) {
      uVar1 = uVar5;
    }
    uVar5 = uVar1;
    if (uVar5 == 0) {
      return 0;
    }
  }
  else if ((iVar3 != 10) && (iVar3 != 0xd)) {
    if ((iVar3 != 0x13) && (iVar3 != 0x14)) {
      local_98 = 0x17d;
      local_a8 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\fileinfo.cpp";
      local_a0 = "p9fs::Session::SetFileInfo";
      local_90 = "P9: Unsupported set file info class: %d\n";
      TraceLog((ErrorSite *)&local_a8,-0x3fffffff);
      return -0x3fffff45;
    }
    local_68 = *(undefined8 *)p_Var2;
    uVar5 = 8;
  }
  uVar1 = *(uint *)(param_1 + 0x78);
  if ((uVar1 >> 0xc & 1) != 0) {
    if ((uVar1 & 2) == 0) {
      param_1[0x23] = (_RX_CONTEXT)0x1;
      return -0x3fbefffd;
    }
    *(uint *)(param_1 + 0x78) = uVar1 & 0xffffefff;
  }
  iVar3 = RxSetMinirdrCancelRoutine(param_1,CancelRxContext);
  if (iVar3 < 0) {
    local_98 = 0x185;
    local_a8 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\fileinfo.cpp";
    local_90 = (char *)0x0;
    local_a0 = "p9fs::Session::SetFileInfo";
    TraceLog((ErrorSite *)&local_a8,iVar3);
    return iVar3;
  }
  local_b8 = &ContextCancellationManager::_vftable_;
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0x48) + 0x30);
  p_Stack_b0 = param_1;
  if (uVar5 != 0) {
    lVar4 = P9Client::SetAttr((P9Client *)(this + 0x50),uVar1,uVar5,local_88,
                              (ICancellationManager *)&local_b8);
    return lVar4;
  }
  if (*(int *)(param_1 + 0x1b0) == 10) {
    lVar4 = SetRenameInfo((P9Client *)(this + 0x50),*(uint *)(this + 0xe8),uVar1,param_1,p_Var2,
                          (ICancellationManager *)&local_b8);
    return lVar4;
  }
  if (*(int *)(param_1 + 0x1b0) != 0xd) {
    return -0x3fffff45;
  }
  if ((*p_Var2 != (_FILE_RENAME_INFORMATION)0x0) && (**(short **)(param_1 + 0x38) == -0x13df)) {
    lVar4 = DetermineIfDirectoryEmpty(this,uVar1,(ICancellationManager *)&local_b8);
  }
  return lVar4;
}



===== SetRenameInfo @ 140008850 =====

/* long __cdecl p9fs::SetRenameInfo(class p9fs::P9Client & __ptr64,unsigned int,unsigned int,struct
   _RX_CONTEXT * __ptr64,struct _FILE_RENAME_INFORMATION & __ptr64,class p9fs::ICancellationManager
   & __ptr64) */

long __cdecl
p9fs::SetRenameInfo(P9Client *param_1,uint param_2,uint param_3,_RX_CONTEXT *param_4,
                   _FILE_RENAME_INFORMATION *param_5,ICancellationManager *param_6)

{
  _FILE_RENAME_INFORMATION *p_Var1;
  longlong lVar2;
  short *psVar3;
  long lVar4;
  ulonglong uVar5;
  undefined4 *puVar6;
  short sVar7;
  P9Client *pPVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  uint uVar13;
  undefined4 uVar14;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  _FILE_RENAME_INFORMATION *p_Stack_b0;
  char local_a8 [8];
  char *local_a0;
  char *pcStack_98;
  longlong local_90;
  char local_88 [8];
  longlong local_80;
  short *psStack_78;
  longlong local_70;
  char local_68 [8];
  uint local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  
  p_Stack_b0 = (_FILE_RENAME_INFORMATION *)0x0;
  p_Var1 = param_5 + 0x14;
  uVar13 = *(uint *)(param_5 + 0x10) >> 1;
  pPVar8 = (P9Client *)(ulonglong)uVar13;
  if ((p_Var1 == (_FILE_RENAME_INFORMATION *)0x0) && (pPVar8 != (P9Client *)0x0)) {
LAB_140008c8c:
                    /* WARNING: Subroutine does not return */
    gsl::details::terminate();
  }
  if (param_4[0x1cf] == (_RX_CONTEXT)0x0) {
    local_d8 = (char *)pPVar8;
    uStack_d0 = (char *)p_Var1;
    puVar6 = (undefined4 *)PathDissectLast(local_68,&local_d8,0x5c);
    uVar9 = *puVar6;
    uVar10 = puVar6[1];
    uVar11 = puVar6[2];
    uVar12 = puVar6[3];
    uVar13 = puVar6[4];
    uVar14 = puVar6[5];
    p_Var1 = *(_FILE_RENAME_INFORMATION **)(puVar6 + 6);
  }
  else {
    lVar2 = *(longlong *)(*(ushort **)(*(longlong *)(param_4 + 0x48) + 0x50) + 4);
    uVar5 = (ulonglong)(**(ushort **)(*(longlong *)(param_4 + 0x48) + 0x50) >> 1);
    if ((lVar2 == 0) && (uVar5 != 0)) goto LAB_140008c8c;
    local_d8 = (char *)uVar5;
    uStack_d0 = (char *)lVar2;
    puVar6 = (undefined4 *)PathDissectLast(local_68,&local_d8,0x5c);
    local_b8._4_4_ = 0;
    local_58 = *(undefined8 *)(puVar6 + 4);
    uStack_50 = *(undefined8 *)(puVar6 + 6);
    uVar9 = *puVar6;
    uVar10 = puVar6[1];
    uVar11 = puVar6[2];
    uVar12 = puVar6[3];
    uVar14 = local_b8._4_4_;
    local_b8 = pPVar8;
    p_Stack_b0 = p_Var1;
  }
  local_d8 = (char *)CONCAT44(uVar10,uVar9);
  uStack_d0 = (char *)CONCAT44(uVar12,uVar11);
  NtPathUnescape(local_88,&local_d8);
  lVar4 = (long)local_80;
  if (local_88[0] == '\0') {
    local_d8 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\fileinfo.cpp";
    local_c8 = 0xb5;
    uStack_d0 = "p9fs::SetRenameInfo";
    local_c0 = 0;
    TraceLog((ErrorSite *)&local_d8,lVar4);
    goto LAB_140008ba7;
  }
  local_d8 = (char *)CONCAT44(uVar14,uVar13);
  uStack_d0 = (char *)p_Var1;
  NtPathUnescape(local_a8,&local_d8);
  if (local_a8[0] == '\0') {
    local_d8 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\fileinfo.cpp";
    local_c8 = 0xb8;
    uStack_d0 = "p9fs::SetRenameInfo";
    local_c0 = 0;
    lVar4 = (long)local_a0;
    TraceLog((ErrorSite *)&local_d8,lVar4);
  }
  else {
    p_Stack_b0 = (_FILE_RENAME_INFORMATION *)CONCAT44(p_Stack_b0._4_4_,0xffffffff);
    local_b8 = param_1;
    if (local_80 == 0) {
      sVar7 = (-(ushort)(local_70 != 0) & 0xffd3) + 0x5c;
    }
    else {
      lVar2 = local_80;
      psVar3 = psStack_78;
      if (*psStack_78 == 0x5c) {
        if ((local_80 == 0) ||
           (local_d8 = (char *)(local_80 + -1), local_d8 == (char *)0xffffffffffffffff))
        goto LAB_140008c8c;
        lVar2 = (longlong)local_d8;
        psVar3 = psStack_78 + 1;
      }
      uStack_d0 = (char *)psVar3;
      local_d8 = (char *)lVar2;
      sVar7 = (-(ushort)(local_70 != 0) & 0xffd3) + 0x5c;
      P9Client::WalkPath(param_1,local_68,param_2,&local_d8,sVar7);
      param_2 = local_60;
      if (local_68[0] == '\0') {
        local_d8 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\fileinfo.cpp";
        local_c8 = 0xcd;
        uStack_d0 = "p9fs::SetRenameInfo";
        local_c0 = 0;
        TraceLog((ErrorSite *)&local_d8,local_60);
        goto LAB_140008aa7;
      }
      UniqueFid::Reset((UniqueFid *)&local_b8,local_60);
    }
    if (param_4[0x1cc] == (_RX_CONTEXT)0x0) {
      local_d8 = local_a0;
      uStack_d0 = pcStack_98;
      P9Client::WalkPath(param_1,local_68,param_2,&local_d8,sVar7);
      if (local_68[0] == '\0') {
        if (local_60 != 0xc0000034) {
LAB_140008aa7:
          UniqueFid::Reset((UniqueFid *)&local_b8,0xffffffff);
          if ((local_a8[0] != '\0') && (local_90 != 0)) {
            ExFreePoolWithTag(local_90,0);
            local_90 = 0;
          }
          if ((local_88[0] != '\0') && (local_70 != 0)) {
            ExFreePoolWithTag(local_70,0);
          }
          return local_60;
        }
        goto LAB_140008b56;
      }
      lVar4 = P9Client::Clunk(param_1,local_60);
      if (-1 < lVar4) {
        UniqueFid::Reset((UniqueFid *)&local_b8,0xffffffff);
        if ((local_a8[0] != '\0') && (local_90 != 0)) {
          ExFreePoolWithTag(local_90,0);
          local_90 = 0;
        }
        if ((local_88[0] != '\0') && (local_70 != 0)) {
          ExFreePoolWithTag(local_70,0);
        }
        return -0x3fffffcb;
      }
      local_c8 = 0xe1;
      local_d8 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\fileinfo.cpp";
      local_c0 = 0;
      uStack_d0 = "p9fs::SetRenameInfo";
      TraceLog((ErrorSite *)&local_d8,lVar4);
    }
    else {
LAB_140008b56:
      local_d8 = local_a0;
      uStack_d0 = pcStack_98;
      lVar4 = P9Client::Rename(param_1,param_3,param_2,&local_d8,param_6);
    }
    UniqueFid::Reset((UniqueFid *)&local_b8,0xffffffff);
  }
  if ((local_a8[0] != '\0') && (local_90 != 0)) {
    ExFreePoolWithTag(local_90,0);
    local_90 = 0;
  }
LAB_140008ba7:
  if ((local_88[0] != '\0') && (local_70 != 0)) {
    ExFreePoolWithTag(local_70,0);
  }
  return lVar4;
}



===== FillDirectoryInfo @ 140008c98 =====

/* void __cdecl p9fs::FillDirectoryInfo(enum _FILE_INFORMATION_CLASS,void * __ptr64,struct
   p9fs::DirectoryEnumerator::ExtendedDirectoryEntry const & __ptr64,unsigned long) */

void __cdecl
p9fs::FillDirectoryInfo
          (_FILE_INFORMATION_CLASS param_1,void *param_2,ExtendedDirectoryEntry *param_3,
          ulong param_4)

{
  ulong uVar1;
  StatResult *pSVar2;
  
  if (param_1 == 1) {
    pSVar2 = (StatResult *)(param_3 + 0x40);
    ConvertFileTimes(pSVar2,(_LARGE_INTEGER *)((longlong)param_2 + 8),
                     (_LARGE_INTEGER *)((longlong)param_2 + 0x10),
                     (_LARGE_INTEGER *)((longlong)param_2 + 0x18),
                     (_LARGE_INTEGER *)((longlong)param_2 + 0x20));
    ConvertFileSize(pSVar2,(_LARGE_INTEGER *)((longlong)param_2 + 0x28),
                    (_LARGE_INTEGER *)((longlong)param_2 + 0x30));
    uVar1 = ConvertFileAttributes(pSVar2,(ulong *)0x0);
    *(ulong *)((longlong)param_2 + 0x38) = uVar1;
    *(ulong *)((longlong)param_2 + 0x3c) = param_4;
  }
  else if (param_1 == 2) {
    FillFullDirectoryInfo(param_2,param_3,param_4);
  }
  else if (param_1 == 3) {
    FillFullDirectoryInfo(param_2,param_3,param_4);
    *(undefined1 *)((longlong)param_2 + 0x44) = 0;
  }
  else if (param_1 == 0xc) {
    *(ulong *)((longlong)param_2 + 8) = param_4;
  }
  else if (param_1 == 0x25) {
    FillFullDirectoryInfo(param_2,param_3,param_4);
    *(undefined1 *)((longlong)param_2 + 0x44) = 0;
    *(undefined8 *)((longlong)param_2 + 0x60) = *(undefined8 *)(param_3 + 0x30);
  }
  else {
    FillFullDirectoryInfo(param_2,param_3,param_4);
    *(undefined8 *)((longlong)param_2 + 0x48) = *(undefined8 *)(param_3 + 0x30);
  }
  return;
}



===== FillFullDirectoryInfo @ 140008d74 =====

/* void __cdecl p9fs::FillFullDirectoryInfo(struct _FILE_FULL_DIR_INFORMATION * __ptr64,struct
   p9fs::DirectoryEnumerator::ExtendedDirectoryEntry const & __ptr64,unsigned long) */

void __cdecl
p9fs::FillFullDirectoryInfo
          (_FILE_FULL_DIR_INFORMATION *param_1,ExtendedDirectoryEntry *param_2,ulong param_3)

{
  ulong uVar1;
  StatResult *pSVar2;
  
  pSVar2 = (StatResult *)(param_2 + 0x40);
  ConvertFileTimes(pSVar2,(_LARGE_INTEGER *)(param_1 + 8),(_LARGE_INTEGER *)(param_1 + 0x10),
                   (_LARGE_INTEGER *)(param_1 + 0x18),(_LARGE_INTEGER *)(param_1 + 0x20));
  ConvertFileSize(pSVar2,(_LARGE_INTEGER *)(param_1 + 0x28),(_LARGE_INTEGER *)(param_1 + 0x30));
  uVar1 = ConvertFileAttributes(pSVar2,(ulong *)(param_1 + 0x40));
  *(ulong *)(param_1 + 0x3c) = param_3;
  *(ulong *)(param_1 + 0x38) = uVar1;
  return;
}



===== QueryDirectoryInfo @ 140008de0 =====

/* public: long __cdecl p9fs::Session::QueryDirectoryInfo(struct _RX_CONTEXT * __ptr64) __ptr64 */

long __thiscall p9fs::Session::QueryDirectoryInfo(Session *this,_RX_CONTEXT *param_1)

{
  undefined1 auVar1 [16];
  uint uVar2;
  longlong lVar3;
  ushort uVar4;
  ulong uVar5;
  short sVar6;
  bool bVar7;
  bool bVar8;
  uint *puVar9;
  undefined8 uVar10;
  int iVar11;
  long lVar12;
  DirectoryEnumerator *pDVar13;
  char *pcVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  long lVar17;
  ulonglong _Size;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  uint local_res18;
  int local_res20;
  char *local_118;
  uint *puStack_110;
  undefined8 local_108;
  char *local_100;
  undefined8 local_f8;
  uint *puStack_f0;
  uint *local_e8;
  undefined1 local_d8 [16];
  ulonglong local_c8;
  uint *puStack_c0;
  uint *local_b8;
  char *local_a8;
  uint *puStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  char *local_88;
  uint *puStack_80;
  undefined **local_78;
  _RX_CONTEXT *local_70;
  char *local_68;
  uint *puStack_60;
  
  uVar2 = *(uint *)(param_1 + 0x1b0);
  if (uVar2 == 1) {
    _Size = 0x40;
  }
  else if (uVar2 == 2) {
    _Size = 0x44;
  }
  else if (uVar2 == 3) {
    _Size = 0x5e;
  }
  else if (uVar2 == 0xc) {
    _Size = 0xc;
  }
  else if (uVar2 == 0x25) {
    _Size = 0x68;
  }
  else if (uVar2 == 0x26) {
    _Size = 0x50;
  }
  else {
    _Size = 0;
  }
  if (_Size == 0) {
    local_108 = 0x85;
    local_118 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\dirinfo.cpp";
    puStack_110 = (uint *)0x140017350;
    local_100 = "P9: Unsupported dir info class: %d\n";
    TraceLog((ErrorSite *)&local_118,-0x3fffffff,(ulonglong)uVar2);
    return -0x3ffffffd;
  }
  if (param_1[0x1f6] != (_RX_CONTEXT)0x0) {
    return -0x3ffffffe;
  }
  uVar2 = *(uint *)(param_1 + 0x78);
  if ((uVar2 >> 0xc & 1) != 0) {
    if ((uVar2 & 2) == 0) {
      param_1[0x23] = (_RX_CONTEXT)0x1;
      return -0x3fbefffd;
    }
    *(uint *)(param_1 + 0x78) = uVar2 & 0xffffefff;
  }
  iVar11 = RxSetMinirdrCancelRoutine(param_1,CancelRxContext);
  if (iVar11 < 0) {
    local_108 = 0x93;
    goto LAB_140008f07;
  }
  lVar3 = *(longlong *)(param_1 + 0x40);
  local_78 = &ContextCancellationManager::_vftable_;
  pDVar13 = *(DirectoryEnumerator **)(lVar3 + 0x38);
  local_70 = param_1;
  if (pDVar13 == (DirectoryEnumerator *)0x0) {
    iVar11 = *(int *)(param_1 + 0x1b0);
    uVar2 = *(uint *)(*(longlong *)(param_1 + 0x48) + 0x30);
    pDVar13 = operator_new(0x310);
    if ((pDVar13 == (DirectoryEnumerator *)0x0) ||
       (pDVar13 = (DirectoryEnumerator *)
                  DirectoryEnumerator::DirectoryEnumerator
                            (pDVar13,(P9Client *)(this + 0x50),uVar2,(iVar11 != 0xc) + 2),
       pDVar13 == (DirectoryEnumerator *)0x0)) {
      return -0x3fffff66;
    }
    *(DirectoryEnumerator **)(lVar3 + 0x38) = pDVar13;
    puStack_f0 = *(uint **)(lVar3 + 0x58);
    uVar4 = *(ushort *)(lVar3 + 0x50) >> 1;
    local_f8 = (char *)(ulonglong)uVar4;
    if ((puStack_f0 == (uint *)0x0) && (local_f8 != (char *)0x0)) goto LAB_140009323;
    local_c8 = (ulonglong)uVar4;
    puStack_c0 = puStack_f0;
    iVar11 = DirectoryEnumerator::Initialize
                       (pDVar13,*(longlong *)(this + 0x68) + -0x18,&local_c8,
                        param_1[0x1f8] != (_RX_CONTEXT)0x0);
    if (iVar11 < 0) {
      local_108 = 0xad;
LAB_140008f07:
      local_100 = (char *)0x0;
      local_118 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\dirinfo.cpp";
      puStack_110 = (uint *)0x140017350;
      TraceLog((ErrorSite *)&local_118,iVar11);
      return iVar11;
    }
    iVar11 = DirectoryEnumerator::Next(pDVar13,(ICancellationManager *)&local_78);
    if (iVar11 < 0) {
      local_108 = 0xb0;
      goto LAB_140008f07;
    }
  }
  else if (param_1[500] == (_RX_CONTEXT)0x0) {
    if (((byte)pDVar13[0x30c] & 1) != 0) {
      return -0x7ffffffa;
    }
  }
  else {
    puStack_f0 = *(uint **)(lVar3 + 0x58);
    uVar4 = *(ushort *)(lVar3 + 0x50) >> 1;
    local_f8 = (char *)(ulonglong)uVar4;
    if ((puStack_f0 == (uint *)0x0) && (local_f8 != (char *)0x0)) goto LAB_140009323;
    local_c8 = (ulonglong)uVar4;
    puStack_c0 = puStack_f0;
    iVar11 = DirectoryEnumerator::Restart(pDVar13,&local_c8,param_1[0x1f8] != (_RX_CONTEXT)0x0);
    if (iVar11 < 0) {
      local_108 = 0xb6;
      goto LAB_140008f07;
    }
    iVar11 = DirectoryEnumerator::Next(pDVar13,(ICancellationManager *)&local_78);
    if (iVar11 < 0) {
      local_108 = 0xb9;
      goto LAB_140008f07;
    }
  }
  local_e8 = *(uint **)(param_1 + 0x1b8);
  bVar7 = true;
  uVar16 = (ulonglong)*(uint *)(param_1 + 0x1c8);
  local_res18 = 0;
  local_res20 = 0;
  local_b8 = (uint *)0x0;
  if ((local_e8 != (uint *)0x0) || (uVar16 == 0)) {
    if (uVar16 < _Size) {
      return 0;
    }
    while( true ) {
      local_68 = (char *)(uVar16 - _Size);
      auVar1 = *(undefined1 (*) [16])(pDVar13 + 0xf8);
      uVar18 = auVar1._0_4_;
      uVar19 = auVar1._4_4_;
      uVar20 = auVar1._8_4_;
      uVar21 = auVar1._12_4_;
      local_d8 = auVar1;
      if (local_68 == (char *)0xffffffffffffffff) break;
      puStack_110 = (uint *)((longlong)local_e8 + _Size);
      local_118 = local_68;
      puStack_60 = puStack_110;
      ReinterpretSpan<unsigned_short,gsl::byte>(&local_a8);
      puVar9 = puStack_a0;
      pcVar14 = auVar1._0_8_;
      bVar8 = false;
      if (local_a8 < pcVar14) {
        if (!bVar7) {
          return 0;
        }
        if (local_a8 == (char *)0xffffffffffffffff) {
          local_98 = pcVar14;
          if (pcVar14 == (char *)0xffffffffffffffff) break;
        }
        else {
          if (pcVar14 < local_a8) break;
          local_98 = local_a8;
        }
        uStack_90 = local_d8._8_8_;
        uVar10 = uStack_90;
        uStack_90._0_4_ = local_d8._8_4_;
        uStack_90._4_4_ = local_d8._12_4_;
        bVar8 = true;
        uVar18 = (undefined4)local_98;
        uVar19 = local_98._4_4_;
        uVar20 = (undefined4)uStack_90;
        uVar21 = uStack_90._4_4_;
        uStack_90 = uVar10;
      }
      else {
        if (pcVar14 == (char *)0xffffffffffffffff) {
          local_88 = local_a8;
          if (local_a8 == (char *)0xffffffffffffffff) break;
        }
        else {
          local_88 = pcVar14;
        }
        puStack_80 = puStack_a0;
        local_a8 = local_88;
      }
      pcVar14 = local_a8;
      uVar5 = (int)local_a8 * 2;
      memset(local_e8,0,_Size);
      FillDirectoryInfo(*(_FILE_INFORMATION_CLASS *)(param_1 + 0x1b0),local_e8,
                        (ExtendedDirectoryEntry *)(pDVar13 + 0x50),uVar5);
      puStack_110 = puVar9;
      local_d8._4_4_ = uVar19;
      local_d8._0_4_ = uVar18;
      local_d8._8_4_ = uVar20;
      local_d8._12_4_ = uVar21;
      local_118 = pcVar14;
      gsl::copy<unsigned_short,_1,unsigned_short,_1>(local_d8,&local_118);
      sVar6 = (short)pcVar14 * 2;
      local_f8 = (char *)(ulonglong)CONCAT22(sVar6,sVar6);
      puStack_f0 = puVar9;
      local_118 = local_f8;
      puStack_110 = puVar9;
      LxUtilNtFileNameEscapeInPlace((ushort *)&local_118);
      puVar9 = local_e8;
      iVar11 = (int)_Size + uVar5;
      *(int *)(param_1 + 0x1c8) = *(int *)(param_1 + 0x1c8) - (local_res20 + iVar11);
      if (bVar8) {
        return -0x7ffffffb;
      }
      if (local_b8 != (uint *)0x0) {
        *local_b8 = local_res18;
      }
      local_res18 = iVar11 + 7U & 0xfffffff8;
      local_b8 = local_e8;
      local_res20 = local_res18 - iVar11;
      lVar12 = DirectoryEnumerator::Next(pDVar13,(ICancellationManager *)&local_78);
      if (lVar12 < 0) {
        lVar17 = 0;
        if (lVar12 != -0x7ffffffa) {
          lVar17 = lVar12;
        }
        return lVar17;
      }
      uVar15 = (ulonglong)local_res18;
      if (uVar16 <= uVar15) {
        return 0;
      }
      if (param_1[0x1f5] != (_RX_CONTEXT)0x0) {
        return 0;
      }
      if ((uVar16 < uVar15) ||
         (uVar16 = uVar16 - uVar15, local_c8 = uVar16, uVar16 == 0xffffffffffffffff)) break;
      local_e8 = (uint *)(uVar15 + (longlong)puVar9);
      bVar7 = false;
      if (uVar16 < _Size) {
        return 0;
      }
      puStack_c0 = local_e8;
    }
  }
LAB_140009323:
                    /* WARNING: Subroutine does not return */
  gsl::details::terminate();
}



===== QueryVolumeInfo @ 140009330 =====

/* public: long __cdecl p9fs::Session::QueryVolumeInfo(struct _RX_CONTEXT * __ptr64) __ptr64 */

long __thiscall p9fs::Session::QueryVolumeInfo(Session *this,_RX_CONTEXT *param_1)

{
  uint uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  char *local_78;
  char *local_70;
  undefined8 local_68;
  char *local_60;
  char local_58 [8];
  long local_50;
  uint local_4c;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_18;
  
  iVar5 = *(int *)(param_1 + 0x1b0);
  if (iVar5 == 1) {
    puVar3 = *(undefined8 **)(param_1 + 0x1b8);
    if (0x17 < *(uint *)(param_1 + 0x1c8)) {
      *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) - 0x18;
      *puVar3 = 0;
      puVar3[1] = 0;
      *(undefined1 *)(puVar3 + 2) = 0;
      return 0;
    }
    local_68 = 0x29;
    local_70 = "p9fs::FillFsVolumeInfo";
  }
  else {
    if (iVar5 != 3) {
      if (iVar5 == 4) {
        puVar4 = *(undefined4 **)(param_1 + 0x1b8);
        lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x48) + 0x28) + 0x20);
        if (7 < *(uint *)(param_1 + 0x1c8)) {
          *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) - 8;
          puVar4[1] = 0x10;
          *puVar4 = *(undefined4 *)(lVar2 + 0x50);
          return 0;
        }
        local_68 = 0xf;
        local_70 = "p9fs::FillFsDeviceInfo";
        goto LAB_140009675;
      }
      if ((iVar5 != 5) && (iVar5 != 7)) {
        local_68 = 0x60;
        local_78 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\volinfo.cpp";
        local_70 = "p9fs::Session::QueryVolumeInfo";
        local_60 = "P9: Unsupported volume info class: %d\n";
        TraceLog((ErrorSite *)&local_78,-0x3fffffff);
        return -0x3fffff45;
      }
    }
    uVar1 = *(uint *)(param_1 + 0x78);
    if ((uVar1 >> 0xc & 1) != 0) {
      if ((uVar1 & 2) == 0) {
        param_1[0x23] = (_RX_CONTEXT)0x1;
        return -0x3fbefffd;
      }
      *(uint *)(param_1 + 0x78) = uVar1 & 0xffffefff;
    }
    iVar5 = RxSetMinirdrCancelRoutine(param_1,CancelRxContext);
    if (iVar5 < 0) {
      local_68 = 0x68;
      local_78 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\volinfo.cpp";
      local_60 = (char *)0x0;
      local_70 = "p9fs::Session::QueryVolumeInfo";
      TraceLog((ErrorSite *)&local_78,iVar5);
      return iVar5;
    }
    P9Client::StatFs((P9Client *)(this + 0x50),(uint)local_58,
                     (ICancellationManager *)
                     (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x48) + 0x30));
    if (local_58[0] == '\0') {
      local_78 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\volinfo.cpp";
      local_68 = 0x6e;
      local_70 = "p9fs::Session::QueryVolumeInfo";
      local_60 = (char *)0x0;
      TraceLog((ErrorSite *)&local_78,local_50);
      return local_50;
    }
    iVar5 = *(int *)(param_1 + 0x1b0);
    if (iVar5 == 3) {
      puVar3 = *(undefined8 **)(param_1 + 0x1b8);
      if (0x17 < *(uint *)(param_1 + 0x1c8)) {
        *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) - 0x18;
        *puVar3 = local_48;
        puVar3[1] = local_40;
        *(uint *)(puVar3 + 2) = local_4c >> 9;
        *(undefined4 *)((longlong)puVar3 + 0x14) = 0x200;
        return 0;
      }
      local_68 = 0x34;
      local_70 = "p9fs::FillFsSizeInfo";
    }
    else if (iVar5 == 5) {
      puVar4 = *(undefined4 **)(param_1 + 0x1b8);
      if (0xf < *(uint *)(param_1 + 0x1c8)) {
        *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) - 0x10;
        puVar4[1] = local_18;
        *puVar4 = 0x400003;
        puVar4[2] = 4;
        puVar4[3] = 0x500039;
        return 0;
      }
      local_68 = 0x18;
      local_70 = "p9fs::FillFsAttributeInfo";
    }
    else {
      if (iVar5 != 7) {
        return -0x3fffff45;
      }
      puVar3 = *(undefined8 **)(param_1 + 0x1b8);
      if (0x1f < *(uint *)(param_1 + 0x1c8)) {
        *(uint *)(param_1 + 0x1c8) = *(uint *)(param_1 + 0x1c8) - 0x20;
        *puVar3 = local_48;
        puVar3[1] = local_38;
        puVar3[2] = local_40;
        *(uint *)(puVar3 + 3) = local_4c >> 9;
        *(undefined4 *)((longlong)puVar3 + 0x1c) = 0x200;
        return 0;
      }
      local_68 = 0x42;
      local_70 = "p9fs::FillFsFullSizeInfo";
    }
  }
LAB_140009675:
  local_78 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\volinfo.cpp";
  local_60 = (char *)0x0;
  TraceLog((ErrorSite *)&local_78,-0x7ffffffb);
  return -0x7ffffffb;
}



===== Create @ 1400096b4 =====

/* public: long __cdecl p9fs::Session::Create(struct _RX_CONTEXT * __ptr64) __ptr64 */

long __thiscall p9fs::Session::Create(Session *this,_RX_CONTEXT *param_1)

{
  char *pcVar1;
  P9Client *this_00;
  longlong lVar2;
  ushort *puVar3;
  undefined1 uVar4;
  char cVar5;
  long lVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  AccessFlags AVar10;
  ushort *puVar11;
  basic_string_view<unsigned_short> *pbVar12;
  ICancellationManager *pIVar13;
  bool bVar14;
  undefined4 uVar15;
  AccessFlags local_res18;
  int local_res20;
  AccessFlags local_res24;
  undefined8 local_198;
  undefined8 local_190;
  ulonglong local_188;
  char *local_180;
  undefined1 local_178 [12];
  undefined4 uStack_16c;
  char local_168 [8];
  char *local_160;
  ushort *puStack_158;
  longlong local_150;
  P9Client *local_148;
  OpenFlags local_140;
  undefined **local_138;
  _RX_CONTEXT *local_130;
  P9Client *local_128;
  undefined4 local_120;
  char *local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  char *local_100;
  char local_f8 [4];
  uint local_f4;
  char local_e8 [8];
  long local_e0;
  StatResult local_c8 [136];
  
  lVar2 = *(longlong *)(param_1 + 0x48);
  local_198 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\create.cpp";
  *(uint *)(lVar2 + 0x48) = *(uint *)(lVar2 + 0x48) | 0x203;
  *(undefined8 *)(lVar2 + 0x30) = 0xffffffff;
  local_190 = "p9fs::Session::Create";
  if ((*(uint *)(param_1 + 0x20c) >> 0xd & 1) != 0) {
    local_188 = 0x1e5;
    local_180 = "P9: Unsupported create options: 0x%x\n";
    TraceLog((ErrorSite *)&local_198,-0x3fffffff);
    return -0x3fffff45;
  }
  puVar3 = *(ushort **)(lVar2 + 0x50);
  local_188 = 0x1ea;
  local_180 = "P9: Create: %wZ\n";
  TraceLog((ErrorSite *)&local_198,0,puVar3);
  unique0x00023d00 = *(longlong *)(puVar3 + 4);
  local_178._0_8_ = CONCAT62(0,*puVar3 >> 1);
  if ((unique0x00023d00 == 0) && (local_178._0_8_ != 0)) goto LAB_14000a009;
  NtPathUnescape(local_168,local_178);
  lVar6 = (long)local_160;
  if (local_168[0] != '\0') {
    bVar14 = local_150 != 0;
    puVar11 = (ushort *)0x0;
    pcVar1 = local_160;
    puVar3 = puStack_158;
    if ((local_160 != (char *)0x0) &&
       (puVar11 = puStack_158, (uint)*puStack_158 == (-(uint)bVar14 & 0xffffffd3) + 0x5c)) {
      if (local_160 == (char *)0x0) {
LAB_14000a009:
                    /* WARNING: Subroutine does not return */
        gsl::details::terminate();
      }
      pcVar1 = local_160 + -1;
      local_178._0_8_ = pcVar1;
      if (pcVar1 == (char *)0xffffffffffffffff) goto LAB_14000a009;
      puVar3 = puStack_158 + 1;
      stack0xfffffffffffffe90 = (longlong)puVar3;
    }
    uVar15 = (undefined4)((ulonglong)puVar3 >> 0x20);
    if ((pcVar1 == (char *)0x0) || ((*(uint *)(param_1 + 0x20c) & 1) != 0)) {
      uVar4 = 1;
    }
    else {
      uVar4 = 0;
    }
    pbVar12 = (basic_string_view<unsigned_short> *)CONCAT71((int7)((ulonglong)puVar11 >> 8),uVar4);
    DetermineCreateMethod((_NT_CREATE_PARAMETERS *)&local_198,(bool)((char)param_1 + -0x10));
    if (local_198._0_1_ == (ErrorSite)0x0) {
      local_118 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\create.cpp";
      uStack_110._0_4_ = 0x40017620;
      uStack_110._4_4_ = 1;
      local_108 = 0x201;
      local_100 = (char *)0x0;
      TraceLog((ErrorSite *)&local_118,local_198._4_4_);
      if ((local_168[0] != '\0') && (local_150 != 0)) {
        ExFreePoolWithTag(local_150,0);
      }
      return local_198._4_4_;
    }
    local_190._0_6_ = CONCAT24((-(ushort)bVar14 & 0xffd3) + 0x5c,(uint)local_190);
    uVar9 = (uint)local_188;
    if (pcVar1 == (char *)0x0) {
      if ((local_188 & 8) == 0) {
        *(undefined8 *)(param_1 + 0x248) = 4;
        if ((local_168[0] != '\0') && (local_150 != 0)) {
          ExFreePoolWithTag(local_150,0);
        }
        return -0x3fffffcb;
      }
      uVar9 = (uint)local_188 & 0xfffffffa;
      local_188 = local_188 & 0xfffffffffffffffa;
    }
    this_00 = (P9Client *)(this + 0x50);
    local_res18 = *(AccessFlags *)(this + 0xe8);
    if (this[0xd8] != (Session)0x0) {
      local_178._8_4_ = (int)puVar3;
      local_178._0_8_ = pcVar1;
      uStack_16c = uVar15;
      lVar6 = CreateWOpen(this_00,param_1,local_res18,local_178,(longlong)&local_198 + 4);
      bVar14 = local_168[0] == '\0';
      goto LAB_140009fd1;
    }
    local_120 = 0xffffffff;
    local_178._8_4_ = (int)puVar3;
    local_178._0_8_ = pcVar1;
    uStack_16c = uVar15;
    local_128 = this_00;
    iVar7 = RxSetMinirdrCancelRoutine(param_1,CancelRxContext);
    if (-1 < iVar7) {
      local_138 = &ContextCancellationManager::_vftable_;
      local_130 = param_1;
      if ((uVar9 & 1) != 0) {
        pbVar12 = (basic_string_view<unsigned_short> *)(ulonglong)*(uint *)(this + 0xe8);
        LookupParent((P9Client *)&local_res20,(uint)this_00,pbVar12,(CreateMethod *)local_178);
        if (local_res20._0_1_ == (P9Client)0x0) {
          local_198 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\create.cpp";
          local_190 = "p9fs::Session::Create";
          local_188 = 0x228;
          local_180 = (char *)0x0;
          TraceLog((ErrorSite *)&local_198,local_res24);
          UniqueFid::Reset((UniqueFid *)&local_128,0xffffffff);
          if ((local_168[0] != '\0') && (local_150 != 0)) {
            ExFreePoolWithTag(local_150,0);
          }
          return local_res24;
        }
        if (local_res24 == 0xffffffff) {
          pcVar1 = local_178._0_8_;
          puVar3 = local_178._8_8_;
        }
        else {
          UniqueFid::Reset((UniqueFid *)&local_128,local_res24);
          pcVar1 = local_178._0_8_;
          puVar3 = local_178._8_8_;
          local_res18 = local_res24;
        }
      }
      local_140 = 0xffffffff;
      iVar7 = -0x3fffffcb;
      local_res20 = 0;
      local_148 = this_00;
      do {
        AVar10 = (AccessFlags)pbVar12;
        _local_178 = *(undefined1 (*) [16])(this + 0xf0);
        if ((uVar9 & 2) != 0) {
          AVar10 = local_res18;
          local_118 = pcVar1;
          uStack_110 = puVar3;
          LookupItem(local_f8,this_00,local_res18,&local_118,local_178,(longlong)&local_198 + 4,
                     param_1);
          if (local_f8[0] == '\0') {
            if (local_f4 != 0xc0000034) {
LAB_140009a7d:
              UniqueFid::Reset((UniqueFid *)&local_148,0xffffffff);
              local_138 = &ContextCancellationManager::_vftable_;
              UniqueFid::Reset((UniqueFid *)&local_128,0xffffffff);
              if ((local_168[0] != '\0') && (local_150 != 0)) {
                ExFreePoolWithTag(local_150,0);
              }
              return local_f4;
            }
            uVar9 = (uint)local_188;
            if ((local_188 & 4) == 0) goto LAB_140009a7d;
          }
          else {
            UniqueFid::Reset((UniqueFid *)&local_148,local_f4);
            uVar9 = (uint)local_188;
          }
        }
        if ((uVar9 & 4) == 0) goto LAB_140009c14;
        pbVar12 = (basic_string_view<unsigned_short> *)&local_148;
        local_118 = pcVar1;
        uStack_110 = puVar3;
        lVar6 = CreateNewItem(this_00,&local_128,pbVar12,&local_118,local_178,&local_138,
                              (longlong)&local_198 + 4,uVar4,param_1);
        AVar10 = (AccessFlags)pbVar12;
        uVar9 = (uint)local_188;
        if (-1 < lVar6) goto LAB_140009c14;
        if ((lVar6 != -0x3ffffdd3) && ((lVar6 != -0x3fffffcb || ((local_188 & 2) == 0))))
        goto LAB_140009bc9;
        local_res20 = local_res20 + 1;
        if (2 < local_res20) goto LAB_140009c14;
      } while( true );
    }
    local_180 = (char *)0x0;
    local_198 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\create.cpp";
    local_190 = "p9fs::Session::Create";
    local_188 = 0x220;
    TraceLog((ErrorSite *)&local_198,iVar7);
    UniqueFid::Reset((UniqueFid *)&local_128,0xffffffff);
    goto LAB_140009959;
  }
  local_198 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\create.cpp";
  local_190 = "p9fs::Session::Create";
  local_188 = 0x1ee;
  local_180 = (char *)0x0;
  TraceLog((ErrorSite *)&local_198,lVar6);
  bVar14 = local_168[0] == '\0';
  goto LAB_140009fd1;
LAB_140009c14:
  if (local_res20 == 3) {
    UniqueFid::Reset((UniqueFid *)&local_148,0xffffffff);
    local_138 = &ContextCancellationManager::_vftable_;
    UniqueFid::Reset((UniqueFid *)&local_128,0xffffffff);
    if ((local_168[0] != '\0') && (local_150 != 0)) {
      ExFreePoolWithTag(local_150,0);
    }
    return -0x3ffffe7b;
  }
  if ((*(uint *)(param_1 + 0x1f0) & 0x10000) != 0) {
    if (this[0xd8] == (Session)0x0) {
      local_118 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\create.cpp";
      uStack_110._0_4_ = 0x40017550;
      uStack_110._4_4_ = 1;
      local_108 = 0x14a;
      local_100 = "P9: Can\'t check for delete access with 9P2000.L\n";
      TraceLog((ErrorSite *)&local_118,-0x3fffffff);
      lVar6 = 0;
    }
    else {
      lVar6 = P9Client::Access(this_00,local_140,AVar10,(ICancellationManager *)&local_138);
    }
    if (lVar6 < 0) {
      local_180 = (char *)0x0;
      local_198 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\create.cpp";
      local_190 = "p9fs::Session::Create";
      local_188 = 0x26b;
      TraceLog((ErrorSite *)&local_198,lVar6);
LAB_140009bc9:
      UniqueFid::Reset((UniqueFid *)&local_148,0xffffffff);
      local_138 = &ContextCancellationManager::_vftable_;
      UniqueFid::Reset((UniqueFid *)&local_128,0xffffffff);
      if ((local_168[0] != '\0') && (local_150 != 0)) {
        ExFreePoolWithTag(local_150,0);
      }
      return lVar6;
    }
  }
  if ((uVar9 & 8) != 0) {
    uVar8 = (uint)local_190 & 3;
    if (uVar8 == 3) {
      if ((uVar9 & 0x10) != 0) goto LAB_140009d35;
    }
    else {
      pIVar13 = (ICancellationManager *)((ulonglong)local_190 & 0xffffffff);
      if ((((byte)uStack_16c & 0x80) != 0) && ((uVar8 == 1 || (uVar8 == 2)))) {
LAB_140009d35:
        pIVar13 = (ICancellationManager *)(ulonglong)((uint)local_190 & 0xfffffffc);
      }
      P9Client::Open(this_00,(uint)&local_118,local_140,pIVar13);
      if (local_118._0_1_ == (ErrorSite)0x0) {
        local_198 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\create.cpp";
        local_190 = "p9fs::Session::Create";
        local_188 = 0x281;
        local_180 = (char *)0x0;
        TraceLog((ErrorSite *)&local_198,(long)uStack_110);
        UniqueFid::Reset((UniqueFid *)&local_148,0xffffffff);
        local_138 = &ContextCancellationManager::_vftable_;
        UniqueFid::Reset((UniqueFid *)&local_128,0xffffffff);
        if ((local_168[0] != '\0') && (local_150 != 0)) {
          ExFreePoolWithTag(local_150,0);
        }
        return (long)uStack_110;
      }
      if ((ushort *)local_178._0_8_ != uStack_110) {
        unique0x10000747 = local_108;
        local_178._0_8_ = uStack_110;
        cVar5 = (char)((ulonglong)local_108 >> 0x20);
        if ((*(uint *)(param_1 + 0x20c) & 1) != 0) {
          if (cVar5 < '\0') {
LAB_140009da9:
            if ((*(uint *)(param_1 + 0x20c) & 0x40) == 0) {
              if ((uVar9 & 0x20) != 0) goto LAB_140009e86;
            }
            else {
              iVar7 = -0x3fffff46;
            }
          }
          else {
            iVar7 = -0x3ffffefd;
          }
          local_198 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\create.cpp";
          local_190 = "p9fs::Session::Create";
          local_188 = 0x289;
          local_180 = (char *)0x0;
          TraceLog((ErrorSite *)&local_198,iVar7);
          UniqueFid::Reset((UniqueFid *)&local_148,0xffffffff);
          local_138 = &ContextCancellationManager::_vftable_;
          UniqueFid::Reset((UniqueFid *)&local_128,0xffffffff);
LAB_140009959:
          if ((local_168[0] != '\0') && (local_150 != 0)) {
            ExFreePoolWithTag(local_150,0);
          }
          return iVar7;
        }
        if (cVar5 < '\0') goto LAB_140009da9;
      }
    }
  }
LAB_140009e86:
  P9Client::GetAttr(this_00,(uint)local_e8,(ulonglong)local_140,(ICancellationManager *)0x6e2);
  if (local_e8[0] == '\0') {
    local_198 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\create.cpp";
    local_190 = "p9fs::Session::Create";
    local_188 = 0x291;
    local_180 = (char *)0x0;
    TraceLog((ErrorSite *)&local_198,local_e0);
    UniqueFid::Reset((UniqueFid *)&local_148,0xffffffff);
    local_138 = &ContextCancellationManager::_vftable_;
    UniqueFid::Reset((UniqueFid *)&local_128,0xffffffff);
    if ((local_168[0] != '\0') && (local_150 != 0)) {
      ExFreePoolWithTag(local_150,0);
    }
    return local_e0;
  }
  lVar6 = FinalizeCreate(param_1,(Qid *)local_178,local_c8,(UniqueFid *)&local_148);
  UniqueFid::Reset((UniqueFid *)&local_148,0xffffffff);
  local_138 = &ContextCancellationManager::_vftable_;
  UniqueFid::Reset((UniqueFid *)&local_128,0xffffffff);
  bVar14 = local_168[0] == '\0';
LAB_140009fd1:
  if ((!bVar14) && (local_150 != 0)) {
    ExFreePoolWithTag(local_150,0);
  }
  return lVar6;
}



===== CreateNewItem @ 14000a018 =====

/* long __cdecl p9fs::CreateNewItem(class p9fs::P9Client & __ptr64,class p9fs::UniqueFid &
   __ptr64,class p9fs::UniqueFid & __ptr64,class std::basic_string_view<unsigned short>,struct
   p9fs::Qid & __ptr64,class p9fs::ICancellationManager & __ptr64,struct p9fs::CreateMethod &
   __ptr64,bool,struct _RX_CONTEXT * __ptr64) */

long __cdecl
p9fs::CreateNewItem(P9Client *param_1,longlong param_2,UniqueFid *param_3,undefined8 *param_4,
                   longlong *param_5,undefined8 param_6,longlong param_7,char param_8,
                   longlong param_9)

{
  uint uVar1;
  undefined4 uVar2;
  ErrorSite *pEVar3;
  undefined4 in_stack_ffffffffffffff68;
  undefined2 uVar4;
  char *local_78;
  char *pcStack_70;
  undefined8 local_68;
  undefined8 local_60;
  char *local_58;
  char *local_50;
  longlong lStack_48;
  undefined8 local_40;
  char *local_38;
  char *local_30;
  longlong local_28;
  undefined8 local_20;
  
  uVar4 = (undefined2)((uint)in_stack_ffffffffffffff68 >> 0x10);
  uVar1 = *(uint *)(param_2 + 8);
  if (param_8 == '\0') {
    *(undefined4 *)(param_2 + 8) = 0xffffffff;
    UniqueFid::Reset(param_3,uVar1);
    local_78 = (char *)*param_4;
    pcStack_70 = (char *)param_4[1];
    P9Client::Create(param_1,&local_58,*(undefined4 *)(param_3 + 8),&local_78,
                     *(uint *)(param_7 + 4) | 0xc0);
    if (local_58._0_1_ != (ErrorSite)0x0) {
      *param_5 = (longlong)local_50;
      param_5[1] = lStack_48;
      *(undefined8 *)(param_9 + 0x248) = 2;
      *(uint *)(param_7 + 0xc) = *(uint *)(param_7 + 0xc) & 0xfffffff7;
      return 0;
    }
    local_20 = 0;
    local_38 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\create.cpp";
    pEVar3 = (ErrorSite *)&local_38;
    local_28 = 0x135;
    local_30 = "p9fs::CreateNewItem";
  }
  else {
                    /* WARNING: Load size is inaccurate */
    local_78 = (char *)*param_4;
    pcStack_70 = (char *)param_4[1];
    P9Client::MkDir(*param_4,&local_58,uVar1,&local_78);
    if (local_58._0_1_ != (ErrorSite)0x0) {
      *(undefined8 *)(param_9 + 0x248) = 2;
      uVar2 = *(undefined4 *)(param_2 + 8);
      *param_5 = (longlong)local_50;
      param_5[1] = lStack_48;
      local_78 = (char *)*param_4;
      pcStack_70 = (char *)param_4[1];
      P9Client::WalkPath(param_1,&local_38,uVar2,&local_78,
                         CONCAT22(uVar4,*(undefined2 *)(param_7 + 8)));
      if (local_38._0_1_ == (ErrorSite)0x0) {
        local_40 = 0;
        local_58 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\create.cpp";
        lStack_48 = 0x126;
        local_50 = "p9fs::CreateNewItem";
        TraceLog((ErrorSite *)&local_58,(uint)local_30);
        return (uint)local_30;
      }
      UniqueFid::Reset(param_3,(uint)local_30);
      if (local_28 == *param_5) {
        return 0;
      }
      return -0x3ffffdd3;
    }
    local_60 = 0;
    local_78 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\create.cpp";
    pEVar3 = (ErrorSite *)&local_78;
    local_68 = 0x120;
    pcStack_70 = "p9fs::CreateNewItem";
  }
  TraceLog(pEVar3,(long)local_50);
  return (long)local_50;
}



===== CreateWOpen @ 14000a20c =====

/* long __cdecl p9fs::CreateWOpen(class p9fs::P9Client & __ptr64,struct _RX_CONTEXT *
   __ptr64,unsigned int,class std::basic_string_view<unsigned short>,struct p9fs::CreateMethod &
   __ptr64) */

long __cdecl
p9fs::CreateWOpen(P9Client *param_1,_RX_CONTEXT *param_2,undefined4 param_3,undefined8 *param_4,
                 uint *param_5)

{
  longlong lVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  P9Client *local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  char *local_b0;
  char local_a8 [8];
  long local_a0;
  uint uStack_9c;
  Qid local_90 [12];
  byte local_84;
  longlong local_80;
  StatResult local_70 [104];
  
  uVar4 = *(uint *)(param_2 + 0x20c);
  uVar5 = 0;
  uVar6 = 0x1b6;
  if ((uVar4 & 1) == 0) {
    if ((uVar4 & 0x40) != 0) {
      uVar5 = 2;
    }
  }
  else {
    param_5[1] = param_5[1] | 0x10000;
    uVar6 = 0x1ff;
    uVar4 = *(uint *)(param_2 + 0x20c);
  }
  uVar3 = uVar5 | 1;
  if ((*(uint *)(param_2 + 0x1f0) & 0x10000) == 0) {
    uVar3 = uVar5;
  }
  uVar5 = uVar3 | 4;
  if ((uVar4 >> 0x15 & 1) == 0) {
    uVar5 = uVar3;
  }
  if ((param_5[3] & 4) != 0) {
    uVar4 = param_5[1];
    param_5[1] = uVar4 | 0x40;
    if ((param_5[3] & 2) == 0) {
      param_5[1] = uVar4 | 0xc0;
    }
  }
  local_c8 = (P9Client *)*param_4;
  uStack_c0._0_4_ = *(undefined4 *)(param_4 + 1);
  uStack_c0._4_4_ = *(undefined4 *)((longlong)param_4 + 0xc);
  P9Client::WOpen(param_1,local_a8,param_3,&local_c8,(short)param_5[2],param_5[1],uVar5,uVar6);
  lVar1 = local_80;
  if (local_a8[0] == '\0') {
    local_b0 = (char *)0x0;
    local_c8 = (P9Client *)0x1400174a8;
    local_b8 = 0x1aa;
    uStack_c0 = "p9fs::CreateWOpen";
    TraceLog((ErrorSite *)&local_c8,local_a0);
    lVar2 = local_a0;
  }
  else {
    if ((char)uStack_9c == '\0') {
      *(ulonglong *)(param_2 + 0x248) = (ulonglong)*param_5;
    }
    else {
      uStack_9c = uStack_9c & 0xff;
      if (uStack_9c == 1) {
        *(undefined8 *)(param_2 + 0x248) = 2;
      }
      else {
        if (uStack_9c == 2) {
LAB_14000a39f:
          lVar1 = local_80;
          local_80 = 0;
          if (lVar1 != 0) {
            ExFreePoolWithTag(lVar1,0);
          }
          return -0x3fffffc6;
        }
        if (uStack_9c == 3) {
          local_80 = 0;
          if (lVar1 != 0) {
            ExFreePoolWithTag(lVar1,0);
          }
          return -0x3fffffcc;
        }
        if (uStack_9c == 4) {
          if ((local_84 & 2) != 0) {
            local_c8 = (P9Client *)0x1400174a8;
            local_b8 = 0x1c1;
            uStack_c0._0_4_ = 0x400175e0;
            uStack_c0._4_4_ = 1;
            local_b0 = "P9: Encountered symlink, target: %s\n";
            TraceLog((ErrorSite *)&local_c8,0,local_80);
          }
          if (local_a8[0] == '\0') {
            return -0x3fffffc6;
          }
          goto LAB_14000a39f;
        }
      }
    }
    uStack_c0 = (char *)CONCAT44(uStack_c0._4_4_,local_a0);
    local_c8 = param_1;
    lVar2 = FinalizeCreate(param_2,local_90,local_70,(UniqueFid *)&local_c8);
    UniqueFid::Reset((UniqueFid *)&local_c8,0xffffffff);
  }
  lVar1 = local_80;
  if ((local_a8[0] != '\0') && (local_80 = 0, lVar1 != 0)) {
    ExFreePoolWithTag(lVar1,0);
  }
  return lVar2;
}



===== DetermineCreateMethod @ 14000a478 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* class util::BasicExpected<struct p9fs::CreateMethod,long> __cdecl
   p9fs::DetermineCreateMethod(struct _NT_CREATE_PARAMETERS const & __ptr64,bool) */

_NT_CREATE_PARAMETERS * __cdecl
p9fs::DetermineCreateMethod(_NT_CREATE_PARAMETERS *param_1,bool param_2)

{
  uint uVar1;
  uint uVar2;
  undefined7 in_register_00000011;
  char in_R8B;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  char *pcStack_30;
  undefined8 local_28;
  char *local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  uVar2 = *(uint *)CONCAT71(in_register_00000011,param_2);
  uVar1 = uVar2 & 0x21;
  if ((uVar2 & 2) == 0) {
    if ((uVar2 & 4) == 0) {
      uVar2 = ~-(uint)(uVar1 != 0) & 3;
    }
    else {
      uVar2 = (uVar1 != 0) + 0x401;
    }
  }
  else {
    uVar2 = (uVar1 != 0) + 1;
  }
  uVar1 = ((uint *)CONCAT71(in_register_00000011,param_2))[6];
  local_38 = (char *)CONCAT44(uVar2,1);
  if (uVar1 == 0) {
    if (in_R8B != '\0') goto LAB_14000a542;
    pcStack_30 = (char *)0x1f00000000;
    local_38._0_4_ = 0;
  }
  else {
    if (uVar1 == 1) {
      pcStack_30 = (char *)0x2b00000000;
      goto LAB_14000a592;
    }
    if (uVar1 == 2) {
      pcStack_30 = (char *)0x500000000;
      goto LAB_14000a592;
    }
    if (uVar1 == 3) {
      pcStack_30 = (char *)0x2f00000000;
      goto LAB_14000a592;
    }
    if (uVar1 == 4) {
      if (in_R8B != '\0') goto LAB_14000a542;
      pcStack_30 = (char *)0x1a00000000;
    }
    else {
      if (uVar1 != 5) {
        local_28 = 0xb6;
        local_38 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\create.cpp";
        pcStack_30 = "p9fs::DetermineCreateMethod";
        local_20 = "P9: Invalid create disposition: %d\n";
        TraceLog((ErrorSite *)&local_38,-0x3fffffff,(ulonglong)uVar1);
LAB_14000a542:
        *param_1 = (_NT_CREATE_PARAMETERS)0x0;
        *(undefined4 *)(param_1 + 4) = 0xc000000d;
        return param_1;
      }
      if (in_R8B != '\0') goto LAB_14000a542;
      pcStack_30 = (char *)0x1f00000000;
    }
    local_38._0_4_ = 3;
  }
  local_38 = (char *)(CONCAT44(uVar2,(undefined4)local_38) | 0x20000000000);
LAB_14000a592:
  *param_1 = (_NT_CREATE_PARAMETERS)0x1;
  *(char **)(param_1 + 4) = local_38;
  *(char **)(param_1 + 0xc) = pcStack_30;
  return param_1;
}



===== FinalizeCreate @ 14000a5c0 =====

/* long __cdecl p9fs::FinalizeCreate(struct _RX_CONTEXT * __ptr64,struct p9fs::Qid & __ptr64,struct
   p9fs::StatResult & __ptr64,class p9fs::UniqueFid && __ptr64) */

long __cdecl
p9fs::FinalizeCreate(_RX_CONTEXT *param_1,Qid *param_2,StatResult *param_3,UniqueFid *param_4)

{
  uint uVar1;
  long lVar2;
  longlong lVar3;
  undefined4 local_res8 [2];
  undefined4 local_c8 [2];
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  char *local_90;
  char *local_88;
  undefined8 local_80;
  char *local_78;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 *local_60;
  undefined4 *local_58;
  undefined8 *local_50;
  undefined8 *local_48;
  undefined8 *local_40;
  undefined8 *local_38;
  undefined8 *local_30;
  undefined8 *local_28;
  undefined8 *local_20;
  
  lVar3 = RxCreateNetFobx(param_1,*(undefined8 *)(param_1 + 0x48));
  *(longlong *)(param_1 + 0x40) = lVar3;
  if (lVar3 == 0) {
    lVar2 = -0x3fffff66;
  }
  else {
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 0xf0) = *(undefined8 *)param_2;
    local_c8[0] = *(undefined4 *)(param_3 + 0x10);
    local_res8[0] = 0;
    local_b8 = 0;
    local_b0 = 0;
    local_a8 = 0;
    local_a0 = 0;
    ConvertFileTimes(param_3,(_LARGE_INTEGER *)&local_b8,(_LARGE_INTEGER *)&local_b0,
                     (_LARGE_INTEGER *)&local_a8,(_LARGE_INTEGER *)&local_a0);
    local_98 = 0;
    local_c0 = 0;
    ConvertFileSize(param_3,(_LARGE_INTEGER *)&local_c0,(_LARGE_INTEGER *)&local_98);
    local_60 = local_res8;
    local_64 = 0;
    local_68 = 0;
    local_58 = local_c8;
    local_50 = &local_b8;
    local_48 = &local_b0;
    local_40 = &local_a8;
    local_38 = &local_a0;
    local_30 = &local_98;
    local_28 = &local_c0;
    local_20 = &local_c0;
    RxFinishFcbInitialization
              (*(undefined8 *)(param_1 + 0x38),((int)(char)param_2[0xc] >> 7) + 0xec22,&local_68);
    uVar1 = *(uint *)(param_4 + 8);
    *(undefined4 *)(param_4 + 8) = 0xffffffff;
    local_80 = 0x17a;
    *(ulonglong *)(*(longlong *)(param_1 + 0x48) + 0x30) = (ulonglong)uVar1;
    local_90 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\create.cpp";
    local_88 = "p9fs::FinalizeCreate";
    local_78 = "P9: Create: %wZ succeeded; fid = %d\n";
    TraceLog((ErrorSite *)&local_90,0,*(undefined8 *)(*(longlong *)(param_1 + 0x48) + 0x50),
             (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x48) + 0x30));
    lVar2 = 0;
  }
  return lVar2;
}



===== LookupItem @ 14000a750 =====

/* class util::BasicExpected<unsigned int,long> __cdecl p9fs::LookupItem(class p9fs::P9Client &
   __ptr64,unsigned int,class std::basic_string_view<unsigned short>,struct p9fs::Qid &
   __ptr64,struct p9fs::CreateMethod & __ptr64,struct _RX_CONTEXT * __ptr64) */

undefined1 * __cdecl
p9fs::LookupItem(undefined1 *param_1,P9Client *param_2,undefined8 param_3,longlong *param_4,
                undefined4 *param_5,uint *param_6,longlong param_7)

{
  uint uVar1;
  int iVar2;
  P9Client *local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_48 = (P9Client *)*param_4;
  uStack_40._0_4_ = (undefined4)param_4[1];
  uStack_40._4_4_ = *(undefined4 *)((longlong)param_4 + 0xc);
  P9Client::WalkPath(param_2,&local_28,param_3,&local_48,(short)param_6[2]);
  if (local_28._0_1_ == (ErrorSite)0x0) {
    local_30 = 0;
    local_48 = (P9Client *)0x1400174a8;
    local_38 = 0x100;
    uStack_40 = "p9fs::LookupItem";
    TraceLog((ErrorSite *)&local_48,(long)local_20);
    *param_1 = 0;
    *(long *)(param_1 + 4) = (long)local_20;
    return param_1;
  }
  uStack_40 = (char *)CONCAT44(uStack_40._4_4_,(long)local_20);
  if (*param_4 != 0) {
    *param_5 = (undefined4)local_18;
    param_5[1] = local_18._4_4_;
    param_5[2] = (undefined4)uStack_10;
    param_5[3] = uStack_10._4_4_;
  }
  uVar1 = *(uint *)(param_7 + 0x20c);
  if ((uVar1 & 1) == 0) {
    if (*(char *)(param_5 + 3) < '\0') goto LAB_14000a823;
  }
  else {
    if (-1 < *(char *)(param_5 + 3)) {
      iVar2 = -0x3ffffefd;
      goto LAB_14000a83f;
    }
    param_6[1] = param_6[1] | 0x10000;
LAB_14000a823:
    if ((uVar1 & 0x40) != 0) {
      iVar2 = -0x3fffff46;
      goto LAB_14000a83f;
    }
    if ((param_6[3] & 0x20) == 0) {
      iVar2 = -0x3fffffcb;
      goto LAB_14000a83f;
    }
  }
  iVar2 = 0;
LAB_14000a83f:
  local_48 = param_2;
  if (iVar2 < 0) {
    uStack_10 = 0;
    local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\create.cpp";
    local_18 = 0x10b;
    local_20 = "p9fs::LookupItem";
    TraceLog((ErrorSite *)&local_28,iVar2);
    *param_1 = 0;
    *(int *)(param_1 + 4) = iVar2;
  }
  else {
    *(ulonglong *)(param_7 + 0x248) = (ulonglong)*param_6;
    param_6[3] = param_6[3] & 0xfffffffb;
    *param_1 = 1;
    uStack_40 = (char *)CONCAT44(uStack_40._4_4_,0xffffffff);
    *(long *)(param_1 + 4) = (long)local_20;
  }
  UniqueFid::Reset((UniqueFid *)&local_48,0xffffffff);
  return param_1;
}



===== LookupParent @ 14000a8c4 =====

/* class util::BasicExpected<unsigned int,long> __cdecl p9fs::LookupParent(class p9fs::P9Client &
   __ptr64,unsigned int,class std::basic_string_view<unsigned short> & __ptr64,struct
   p9fs::CreateMethod & __ptr64) */

P9Client * __cdecl
p9fs::LookupParent(P9Client *param_1,uint param_2,basic_string_view<unsigned_short> *param_3,
                  CreateMethod *param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined4 in_register_00000014;
  longlong in_stack_00000028;
  longlong local_48;
  longlong lStack_40;
  char local_38 [8];
  int local_30;
  
  local_48 = *(longlong *)param_4;
  lStack_40 = *(longlong *)(param_4 + 8);
  plVar3 = (longlong *)PathDissectLast(local_38,&local_48,*(undefined2 *)(in_stack_00000028 + 8));
  local_48 = *plVar3;
  lStack_40 = plVar3[1];
  lVar1 = plVar3[2];
  lVar2 = plVar3[3];
  if ((local_48 == 0) && ((*(uint *)(in_stack_00000028 + 0xc) & 4) == 0)) {
    *(undefined4 *)(param_1 + 4) = 0xffffffff;
  }
  else {
    P9Client::WalkPath((P9Client *)CONCAT44(in_register_00000014,param_2),local_38,
                       (ulonglong)param_3 & 0xffffffff,&local_48,
                       *(undefined2 *)(in_stack_00000028 + 8));
    if (local_38[0] == '\0') {
      *param_1 = (P9Client)0x0;
      if (local_30 == -0x3fffffcc) {
        *(undefined4 *)(param_1 + 4) = 0xc000003a;
        return param_1;
      }
      *(int *)(param_1 + 4) = local_30;
      return param_1;
    }
    *(int *)(param_1 + 4) = local_30;
    *(longlong *)param_4 = lVar1;
    *(longlong *)(param_4 + 8) = lVar2;
  }
  *param_1 = (P9Client)0x1;
  return param_1;
}



===== <lambda_invoker_cdecl><void_*> @ 14000a9b0 =====

void <lambda_db9de5964e1bd3f2ba08d009c80347e5>::<lambda_invoker_cdecl><void_*>
               (UserCallback *param_1)

{
  p9fs::UserCallback::CancelWaiters(param_1);
  if (param_1 != (UserCallback *)0x0) {
    p9fs::UserCallback::ReleaseReference(param_1);
  }
  return;
}



===== UserCallback @ 14000a9d8 =====

/* public: __cdecl p9fs::UserCallback::UserCallback(struct _RX_CONTEXT * __ptr64,struct _LUID,struct
   _LUID,struct _LIST_ENTRY * __ptr64) __ptr64 */

UserCallback * __thiscall
p9fs::UserCallback::UserCallback
          (UserCallback *this,longlong param_1,undefined8 param_3,undefined8 param_4,
          longlong param_5)

{
  byte *pbVar1;
  code *pcVar2;
  UserCallback *pUVar3;
  longlong *plVar4;
  
  *(longlong *)(this + 8) = param_1;
  *(undefined8 *)(this + 0x10) = param_3;
  *(undefined8 *)(this + 0x18) = param_4;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  this[0x50] = (UserCallback)0x0;
  *(undefined8 *)this = 1;
  *(undefined8 *)(this + 0x30) = 0;
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0xb0) = 0x103;
    pbVar1 = (byte *)(*(longlong *)(*(longlong *)(*(longlong *)(this + 8) + 0x28) + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  pUVar3 = this + 0x20;
  plVar4 = *(longlong **)(param_5 + 8);
  if (*plVar4 != param_5) {
    param_5 = 3;
    pcVar2 = (code *)swi(0x29);
    pUVar3 = (UserCallback *)(*pcVar2)();
  }
  *(longlong *)pUVar3 = param_5;
  *(longlong **)(pUVar3 + 8) = plVar4;
  *plVar4 = (longlong)pUVar3;
  *(UserCallback **)(param_5 + 8) = pUVar3;
  return this;
}



===== AddWaiter @ 14000aa58 =====

/* public: class util::BasicExpected<bool,long> __cdecl p9fs::UserCallback::AddWaiter(class
   p9fs::WaitRxContext & __ptr64) __ptr64 */

WaitRxContext * __thiscall p9fs::UserCallback::AddWaiter(UserCallback *this,WaitRxContext *param_1)

{
  UserCallback *pUVar1;
  longlong lVar2;
  code *pcVar3;
  longlong lVar4;
  undefined1 *puVar5;
  undefined8 *in_R8;
  WaitRxContext WVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  pUVar1 = this + 0x30;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(pUVar1,0);
  puVar5 = auStack_28;
  lVar4 = *(longlong *)(this + 0x38);
  WVar6 = (WaitRxContext)(lVar4 == 0);
  if ((*(longlong *)(this + 8) == 0) && (lVar4 == 0)) {
    *param_1 = (WaitRxContext)0x0;
    *(undefined4 *)(param_1 + 4) = 0xc0000225;
  }
  else {
    *in_R8 = this;
    LOCK();
    lVar2 = *(longlong *)this;
    *(longlong *)this = *(longlong *)this + 1;
    UNLOCK();
    puVar5 = auStack_28;
    if (lVar2 + 1 < 2) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(0xe);
      puVar5 = auStack_20;
    }
    if (lVar4 == 0) {
      *(undefined8 **)(this + 0x38) = in_R8;
    }
    else {
      *(undefined8 **)(*(longlong *)(this + 0x40) + 0x18) = in_R8;
    }
    *(undefined8 **)(this + 0x40) = in_R8;
    if (lVar4 == 0) {
      *(undefined8 *)(puVar5 + -8) = 0x14000aafe;
      SetCallbackTimeout(this);
    }
    *param_1 = (WaitRxContext)0x1;
    param_1[4] = WVar6;
  }
  if (pUVar1 != (UserCallback *)0x0) {
    *(undefined8 *)(puVar5 + -8) = 0x14000ab16;
    ExReleasePushLockExclusiveEx(pUVar1,0);
    *(undefined8 *)(puVar5 + -8) = 0x14000ab22;
    KeLeaveCriticalRegion();
  }
  return param_1;
}



===== CallUserCallback @ 14000ab4c =====

/* WARNING: Removing unreachable block (ram,0x00014000ada8) */
/* WARNING: Removing unreachable block (ram,0x00014000adad) */
/* WARNING: Removing unreachable block (ram,0x00014000adb5) */
/* WARNING: Removing unreachable block (ram,0x00014000ad1c) */
/* WARNING: Removing unreachable block (ram,0x00014000ae4a) */
/* WARNING: Removing unreachable block (ram,0x00014000ae4f) */
/* public: long __cdecl p9fs::UserCallbackManager::CallUserCallback(struct _LUID,class
   p9fs::WaitRxContext & __ptr64,class std::basic_string_view<unsigned short>) __ptr64 */

long __thiscall
p9fs::UserCallbackManager::CallUserCallback
          (UserCallbackManager *this,undefined8 param_2,undefined8 param_3,ulonglong *param_4)

{
  longlong lVar1;
  code *pcVar2;
  char *pcVar3;
  UserCallbackManager *pUVar4;
  bool bVar5;
  long lVar6;
  ulonglong uVar7;
  UserCallback *pUVar8;
  ulonglong *puVar9;
  ulonglong uVar10;
  undefined1 *puVar11;
  UserCallback *this_00;
  uint uVar12;
  undefined1 auStack_108 [8];
  undefined1 auStack_100 [24];
  UserCallback *local_e8;
  undefined4 local_e0;
  char *local_d8;
  char *local_d0;
  undefined8 local_c8;
  char *local_c0;
  UserCallbackManager *local_b8;
  char *local_a8;
  char *pcStack_a0;
  undefined8 local_98;
  char *local_90;
  undefined8 local_88;
  ulonglong local_80;
  UserCallback *local_70;
  ulonglong local_68;
  ulonglong uStack_60;
  char *local_58;
  char *local_50;
  undefined8 local_48;
  char *local_40;
  
  uVar7 = Feature_3131016505__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar7 != 0) {
    local_68 = *param_4;
    uStack_60 = param_4[1];
    bVar5 = IsValidDistributionName(&local_68);
    if (!bVar5) {
      local_c8 = 0x231;
      local_c0 = "P9: Invalid instance name for callback.\n";
      local_d8 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\usercallback.cpp";
      local_d0 = "p9fs::UserCallbackManager::CallUserCallback";
      TraceLog((ErrorSite *)&local_d8,-0x3fffffff);
      return -0x3ffffff3;
    }
  }
  local_b8 = this + 0x10;
  while( true ) {
    pUVar4 = local_b8;
    pUVar8 = (UserCallback *)0x0;
    KeEnterCriticalRegion();
    ExAcquirePushLockSharedEx(pUVar4,0);
    FindCallbackWithLockHeld(this,&local_e8,param_2);
    if (pUVar4 != (UserCallbackManager *)0x0) {
      ExReleasePushLockSharedEx(pUVar4);
      KeLeaveCriticalRegion();
    }
    this_00 = local_e8;
    if (local_e8 != (UserCallback *)0x0) break;
    local_70 = (UserCallback *)CONCAT44(local_70._4_4_,0xc0000225);
    pUVar8 = (UserCallback *)0xc0000225;
    uVar12 = 0xc0000225;
LAB_14000ad37:
    bVar5 = false;
    this_00 = local_70;
LAB_14000ad3b:
    local_e8 = (UserCallback *)0x0;
    if (bVar5) goto LAB_14000adc5;
    if (uVar12 != 0xc0000225) {
      local_c0 = (char *)0x0;
      local_d8 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\usercallback.cpp";
      local_d0 = "p9fs::UserCallbackManager::CallUserCallback";
      local_c8 = 0x23e;
      TraceLog((ErrorSite *)&local_d8,(long)pUVar8);
      return uVar12;
    }
    local_58 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\usercallback.cpp";
    local_40 = "P9: Waiting for callback to be registered.\n";
    local_50 = "p9fs::UserCallbackManager::CallUserCallback";
    local_48 = 0x241;
    TraceLog((ErrorSite *)&local_58,0);
    lVar6 = NotifyUserProcess(this,param_2,param_3);
    if (lVar6 != -0x3ffffdd3) {
      return lVar6;
    }
  }
  UserCallback::AddWaiter(local_e8,(WaitRxContext *)&local_88);
  if (local_88._0_1_ == (WaitRxContext)0x0) {
    local_90 = (char *)0x0;
    uVar12 = local_88._4_4_;
    local_a8 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\usercallback.cpp";
    pcStack_a0 = "p9fs::UserCallbackManager::FindCallbackAndAddWaiter";
    local_98 = 0x2f1;
    TraceLog((ErrorSite *)&local_a8,local_88._4_4_);
    local_70 = (UserCallback *)CONCAT44(local_70._4_4_,uVar12);
    if (this_00 != (UserCallback *)0x0) {
      UserCallback::ReleaseReference(this_00);
    }
    pUVar8 = (UserCallback *)(ulonglong)uVar12;
    goto LAB_14000ad37;
  }
  bVar5 = true;
  if (local_88._4_1_ == '\0') {
    local_70 = (UserCallback *)0x0;
    local_e0 = 0;
    if (this_00 != (UserCallback *)0x0) {
      UserCallback::ReleaseReference(this_00);
    }
    local_e0 = 0;
    uVar12 = 0;
    this_00 = pUVar8;
    goto LAB_14000ad3b;
  }
LAB_14000adc5:
  puVar11 = auStack_108;
  if (this_00 != (UserCallback *)0x0) {
    LOCK();
    lVar1 = *(longlong *)this_00;
    *(longlong *)this_00 = *(longlong *)this_00 + 1;
    UNLOCK();
    puVar11 = auStack_108;
    if (lVar1 + 1 < 2) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(0xe);
      puVar11 = auStack_100;
    }
  }
  if (this_00 != (UserCallback *)0x0) {
    *(undefined8 *)(puVar11 + -8) = 0x14000adf6;
    UserCallback::ReleaseReference(this_00);
    if (this_00 != (UserCallback *)0x0) {
      local_90 = "P9: Invoking user-mode callback for instance %.*S.\n";
      local_a8 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\usercallback.cpp";
      pcStack_a0 = "p9fs::UserCallbackManager::CallUserCallback";
      local_b8 = (UserCallbackManager *)param_4[1];
      uVar7 = *param_4;
      *(uint *)(puVar11 + 0x20) = (uint)uVar7;
      local_98 = 0x25b;
      *(undefined8 *)(puVar11 + -8) = 0x14000ae9f;
      TraceLog((ErrorSite *)&local_a8,0,(ulonglong)(uint)uVar7,local_b8);
      *(undefined8 *)(puVar11 + -8) = 0x14000aea4;
      uVar7 = Feature_4009910584__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar7 != 0) {
        local_a8 = (char *)*param_4;
        pcStack_a0 = (char *)param_4[1];
        *(undefined8 *)(puVar11 + -8) = 0x14000afa3;
        UserCallback::InvokeRequest(this_00,&local_a8);
LAB_14000afa3:
        *(undefined8 *)(puVar11 + -8) = 0x14000afab;
        UserCallback::ReleaseReference(this_00);
        return 0x103;
      }
      uVar7 = *(ulonglong *)(*(longlong *)(this_00 + 8) + 0x220);
      uVar10 = (ulonglong)*(uint *)(*(longlong *)(this_00 + 8) + 0x22c);
      if ((uVar7 != 0) || (uVar10 == 0)) {
        local_a8 = (char *)*param_4;
        pcStack_a0 = (char *)param_4[1];
        if (((local_a8 != (char *)0xffffffffffffffff) &&
            ((pcStack_a0 != (char *)0x0 || (local_a8 == (char *)0x0)))) &&
           ((pcVar3 = (char *)((longlong)local_a8 * 2), pcStack_a0 != (char *)0x0 ||
            (pcVar3 == (char *)0x0)))) {
          *(undefined8 *)(puVar11 + -8) = 0x14000af24;
          local_88 = uVar10;
          local_80 = uVar7;
          local_58 = pcVar3;
          local_50 = pcStack_a0;
          gsl::copy<gsl::byte_const_,_1,gsl::byte,_1>(&local_58,&local_88);
          *(undefined8 *)(puVar11 + -8) = 0x14000af39;
          local_68 = uVar10;
          uStack_60 = uVar7;
          puVar9 = (ulonglong *)ReinterpretSpan<unsigned_short,gsl::byte>(&local_d8);
          if (*puVar9 <= *param_4) {
                    /* WARNING: Subroutine does not return */
            *(undefined **)(puVar11 + -8) = &UNK_14000afd7;
            gsl::details::terminate();
          }
          uVar12 = *(uint *)(puVar11 + 0x20);
          *(undefined2 *)(puVar9[1] + *param_4 * 2) = 0;
          local_c0 = "P9: Invoking user-mode callback for instance %.*S.\n";
          local_d8 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\usercallback.cpp";
          local_d0 = "p9fs::UserCallbackManager::CallUserCallback";
          local_c8 = 0x26f;
          *(undefined8 *)(puVar11 + -8) = 0x14000af7d;
          TraceLog((ErrorSite *)&local_d8,0,(ulonglong)uVar12,local_b8);
          *(undefined8 *)(puVar11 + -8) = 0x14000af8b;
          UserCallback::CompleteRequest(this_00,0,(__uint64)(pcVar3 + 2));
          goto LAB_14000afa3;
        }
      }
                    /* WARNING: Subroutine does not return */
      *(undefined **)(puVar11 + -8) = &UNK_14000afd1;
      gsl::details::terminate();
    }
  }
  local_d8 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\usercallback.cpp";
  local_c0 = "P9: Waiting for existing callback.\n";
  local_d0 = "p9fs::UserCallbackManager::CallUserCallback";
  local_c8 = 0x255;
  *(undefined8 *)(puVar11 + -8) = 0x14000ae21;
  TraceLog((ErrorSite *)&local_d8,0);
  return 0x103;
}



===== CancelRxContext @ 14000afe0 =====

/* private: static long __cdecl p9fs::UserCallbackManager::CancelRxContext(struct _RX_CONTEXT *
   __ptr64) */

long __cdecl p9fs::UserCallbackManager::CancelRxContext(_RX_CONTEXT *param_1)

{
  UserCallback *this;
  longlong lVar1;
  
  LOCK();
  this = *(UserCallback **)(param_1 + 0xd8);
  *(undefined8 *)(param_1 + 0xd8) = 0;
  UNLOCK();
  if (this != (UserCallback *)0x0) {
    lVar1 = *(longlong *)(param_1 + 0xd0) + 0x10;
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(lVar1,0);
    UserCallback::RemoveFromList(this);
    UserCallback::ReleaseReference(this);
    if (lVar1 != 0) {
      ExReleasePushLockExclusiveEx(lVar1,0);
      KeLeaveCriticalRegion();
    }
    UserCallback::CancelWaiters(this);
    if (*(longlong *)(this + 8) != 0) {
      UserCallback::CompleteRequest(this,-0x3ffffee0,0);
    }
    UserCallback::ReleaseReference(this);
  }
  return 0;
}



===== CancelTimer @ 14000b094 =====

/* private: void __cdecl p9fs::UserCallback::CancelTimer(void) __ptr64 */

void __thiscall p9fs::UserCallback::CancelTimer(UserCallback *this)

{
  char cVar1;
  
  if (*(longlong *)(this + 0x48) != 0) {
    cVar1 = ExCancelTimer(*(longlong *)(this + 0x48),0);
    if (cVar1 != '\0') {
      ReleaseReference(this);
    }
  }
  return;
}



===== CancelWaiters @ 14000b0d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl p9fs::UserCallback::CancelWaiters(void) __ptr64 */

void __thiscall p9fs::UserCallback::CancelWaiters(UserCallback *this)

{
  UserCallback *pUVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  
  pUVar1 = this + 0x30;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(pUVar1,0);
  puVar2 = *(undefined8 **)(this + 0x38);
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  CancelTimer(this);
  if (pUVar1 != (UserCallback *)0x0) {
    ExReleasePushLockExclusiveEx(pUVar1,0);
    KeLeaveCriticalRegion();
  }
  while (puVar3 = puVar2, puVar3 != (undefined8 *)0x0) {
    puVar2 = (undefined8 *)puVar3[3];
    LOCK();
    pUVar1 = (UserCallback *)*puVar3;
    *puVar3 = 0;
    UNLOCK();
    if (pUVar1 != (UserCallback *)0x0) {
      (*(code *)puVar3[1])(puVar3[2],0xc00000cc,0);
      ReleaseReference(pUVar1);
    }
  }
  return;
}



===== CompleteRequest @ 14000b18c =====

/* private: static void __cdecl p9fs::UserCallback::CompleteRequest(struct _RX_CONTEXT *
   __ptr64,long,unsigned __int64) */

void __cdecl p9fs::UserCallback::CompleteRequest(_RX_CONTEXT *param_1,long param_2,__uint64 param_3)

{
  UserCallback *this;
  
  LOCK();
  this = *(UserCallback **)(param_1 + 0xd8);
  *(undefined8 *)(param_1 + 0xd8) = 0;
  UNLOCK();
  if (this != (UserCallback *)0x0) {
    ReleaseReference(this);
  }
  *(long *)(*(longlong *)(param_1 + 0x28) + 0x30) = param_2;
  *(__uint64 *)(*(longlong *)(param_1 + 0x28) + 0x38) = param_3;
  RxCompleteRequestEx(param_1,*(undefined8 *)(param_1 + 0x28),param_2);
  return;
}



===== CompleteRequest @ 14000b1f4 =====

/* public: void __cdecl p9fs::UserCallback::CompleteRequest(long,unsigned __int64) __ptr64 */

void __thiscall
p9fs::UserCallback::CompleteRequest(UserCallback *this,long param_1,__uint64 param_2)

{
  UserCallback *pUVar1;
  ulonglong uVar2;
  _RX_CONTEXT *p_Var3;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  uVar2 = Feature_4009910584__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 == 0) {
    LOCK();
    p_Var3 = *(_RX_CONTEXT **)(this + 8);
    *(undefined8 *)(this + 8) = 0;
    UNLOCK();
  }
  else {
    pUVar1 = this + 0x30;
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(pUVar1,0);
    LOCK();
    p_Var3 = *(_RX_CONTEXT **)(this + 8);
    *(undefined8 *)(this + 8) = 0;
    UNLOCK();
    if (pUVar1 != (UserCallback *)0x0) {
      ExReleasePushLockExclusiveEx(pUVar1,0);
      KeLeaveCriticalRegion();
    }
  }
  if (p_Var3 == (_RX_CONTEXT *)0x0) {
    local_18 = 0x89;
    local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\usercallback.cpp";
    local_20 = "p9fs::UserCallback::CompleteRequest";
    local_10 = "P9: Invalid attempt to invoke a user-mode callback.\n";
    TraceLog((ErrorSite *)&local_28,-0x3fffffff);
  }
  else {
    CompleteRequest(p_Var3,param_1,param_2);
  }
  return;
}



===== DeleteTimer @ 14000b2e4 =====

/* void __cdecl p9fs::details::DeleteTimer(struct _EX_TIMER * __ptr64) */

void __cdecl p9fs::details::DeleteTimer(_EX_TIMER *param_1)

{
  ExDeleteTimer(param_1,1,1,0);
  return;
}



===== FindCallbackWithLockHeld @ 14000b30c =====

/* private: class p9fs::SharedPtr<class p9fs::UserCallback> __cdecl
   p9fs::UserCallbackManager::FindCallbackWithLockHeld(struct _LUID)const __ptr64 */

longlong * __thiscall
p9fs::UserCallbackManager::FindCallbackWithLockHeld
          (UserCallbackManager *this,longlong *param_2,undefined8 param_3)

{
  UserCallbackManager *pUVar1;
  longlong lVar2;
  UserCallbackManager *pUVar3;
  code *pcVar4;
  int iVar5;
  
  iVar5 = (int)((ulonglong)param_3 >> 0x20);
  pUVar3 = *(UserCallbackManager **)this;
  while( true ) {
    if (pUVar3 == this) {
      *param_2 = 0;
      return param_2;
    }
    pUVar1 = pUVar3 + -0x20;
    if ((((int)param_3 == *(int *)(pUVar3 + -0x10)) && (iVar5 == *(int *)(pUVar3 + -0xc))) ||
       (((int)param_3 == *(int *)(pUVar3 + -8) && (iVar5 == *(int *)(pUVar3 + -4))))) break;
    pUVar3 = *(UserCallbackManager **)pUVar3;
  }
  *param_2 = (longlong)pUVar1;
  LOCK();
  lVar2 = *(longlong *)pUVar1;
  *(longlong *)pUVar1 = *(longlong *)pUVar1 + 1;
  UNLOCK();
  if (lVar2 + 1 < 2) {
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(0xe);
    return param_2;
  }
  return param_2;
}



===== FindOrInsertCallbackWithLockHeld @ 14000b370 =====

/* WARNING: Removing unreachable block (ram,0x00014000b3f6) */
/* private: class p9fs::SharedPtr<class p9fs::UserCallback> __cdecl
   p9fs::UserCallbackManager::FindOrInsertCallbackWithLockHeld(struct _LUID) __ptr64 */

longlong * __thiscall
p9fs::UserCallbackManager::FindOrInsertCallbackWithLockHeld
          (UserCallbackManager *this,longlong *param_2,undefined8 param_3)

{
  longlong lVar1;
  code *pcVar2;
  long lVar3;
  UserCallback *pUVar4;
  undefined1 *puVar5;
  longlong local_res20;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  UserCallbackManager *local_18;
  
  FindCallbackWithLockHeld(this,&local_res20);
  if (local_res20 == 0) {
    pUVar4 = operator_new(0x58);
    if ((pUVar4 != (UserCallback *)0x0) &&
       (local_18 = this, pUVar4 = (UserCallback *)UserCallback::UserCallback(pUVar4,0,param_3,0),
       pUVar4 != (UserCallback *)0x0)) {
      lVar3 = UserCallback::Initialize(pUVar4);
      puVar5 = auStack_38;
      if (-1 < lVar3) {
        *param_2 = (longlong)pUVar4;
        LOCK();
        lVar1 = *(longlong *)pUVar4;
        *(longlong *)pUVar4 = *(longlong *)pUVar4 + 1;
        UNLOCK();
        if (lVar1 + 1 < 2) {
          pcVar2 = (code *)swi(0x29);
          (*pcVar2)(0xe);
          puVar5 = auStack_30;
        }
        if (*(UserCallback **)(puVar5 + 0x58) == (UserCallback *)0x0) {
          return param_2;
        }
        *(undefined8 *)(puVar5 + -8) = 0x14000b3fe;
        UserCallback::ReleaseReference(*(UserCallback **)(puVar5 + 0x58));
        return param_2;
      }
      UserCallback::RemoveFromList(pUVar4);
      UserCallback::ReleaseReference(pUVar4);
    }
    *param_2 = 0;
  }
  else {
    *param_2 = local_res20;
  }
  return param_2;
}



===== Initialize @ 14000b448 =====

/* public: long __cdecl p9fs::UserCallback::Initialize(void) __ptr64 */

long __thiscall p9fs::UserCallback::Initialize(UserCallback *this)

{
  longlong lVar1;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  if (*(longlong *)(this + 0x48) == 0) {
    lVar1 = ExAllocateTimer(TimerCallback,this,0);
    if (*(_EX_TIMER **)(this + 0x48) != (_EX_TIMER *)0x0) {
      details::DeleteTimer(*(_EX_TIMER **)(this + 0x48));
    }
    *(longlong *)(this + 0x48) = lVar1;
    if (lVar1 == 0) {
      local_10 = 0;
      local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\usercallback.cpp";
      local_18 = 0x5f;
      local_20 = "p9fs::UserCallback::Initialize";
      TraceLog((ErrorSite *)&local_28,-0x3fffff66);
      return -0x3fffff66;
    }
  }
  return 0;
}



===== InvokeRequest @ 14000b4e0 =====

/* public: void __cdecl p9fs::UserCallback::InvokeRequest(class std::basic_string_view<unsigned
   short>) __ptr64 */

void __thiscall p9fs::UserCallback::InvokeRequest(UserCallback *this,ulonglong *param_2)

{
  UserCallback *pUVar1;
  _RX_CONTEXT *p_Var2;
  longlong lVar3;
  longlong lVar4;
  ulonglong *puVar5;
  ulonglong uVar6;
  ulonglong local_88;
  longlong local_80;
  longlong local_78;
  ulonglong local_70;
  ulonglong local_68;
  longlong local_60;
  ulonglong local_58;
  ulonglong uStack_50;
  char *local_48;
  char *local_40;
  undefined8 local_38;
  char *local_30;
  
  pUVar1 = this + 0x30;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(pUVar1,0);
  LOCK();
  p_Var2 = *(_RX_CONTEXT **)(this + 8);
  *(undefined8 *)(this + 8) = 0;
  UNLOCK();
  if (p_Var2 == (_RX_CONTEXT *)0x0) {
    local_38 = 0xad;
    local_48 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\usercallback.cpp";
    local_40 = "p9fs::UserCallback::InvokeRequest";
    local_30 = "P9: Invalid attempt to invoke a user-mode callback.\n";
    TraceLog((ErrorSite *)&local_48,-0x3fffffff);
    if (pUVar1 != (UserCallback *)0x0) {
      ExReleasePushLockExclusiveEx(pUVar1,0);
      KeLeaveCriticalRegion();
    }
    return;
  }
  lVar3 = *(longlong *)(p_Var2 + 0x220);
  uVar6 = (ulonglong)*(uint *)(p_Var2 + 0x22c);
  if ((lVar3 != 0) || (uVar6 == 0)) {
    local_58 = *param_2;
    local_70 = param_2[1];
    uStack_50 = local_70;
    if (((local_58 != 0xffffffffffffffff) && ((local_70 != 0 || (local_58 == 0)))) &&
       ((lVar4 = local_58 * 2, local_70 != 0 || (lVar4 == 0)))) {
      local_88 = uVar6;
      local_80 = lVar3;
      local_78 = lVar4;
      gsl::copy<gsl::byte_const_,_1,gsl::byte,_1>(&local_78,&local_88);
      local_68 = uVar6;
      local_60 = lVar3;
      puVar5 = (ulonglong *)ReinterpretSpan<unsigned_short,gsl::byte>(&local_48);
      if (*puVar5 <= *param_2) {
                    /* WARNING: Subroutine does not return */
        gsl::details::terminate();
      }
      *(undefined2 *)(puVar5[1] + *param_2 * 2) = 0;
      if (pUVar1 != (UserCallback *)0x0) {
        ExReleasePushLockExclusiveEx(pUVar1);
        KeLeaveCriticalRegion();
      }
      CompleteRequest(p_Var2,0,lVar4 + 2);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  gsl::details::terminate();
}



===== NotifyUserProcess @ 14000b694 =====

/* private: long __cdecl p9fs::UserCallbackManager::NotifyUserProcess(struct _LUID,class
   p9fs::WaitRxContext & __ptr64) __ptr64 */

long __thiscall
p9fs::UserCallbackManager::NotifyUserProcess
          (UserCallbackManager *this,undefined8 param_2,undefined8 *param_3)

{
  UserCallbackManager *pUVar1;
  longlong lVar2;
  code *pcVar3;
  int iVar4;
  UserCallback *pUVar5;
  undefined1 *puVar6;
  UserCallback *local_res20;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [24];
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_48;
  char *local_38;
  char *local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  local_48 = 0;
  local_50 = 0;
  local_58 = 0;
  iVar4 = ZwUpdateWnfStateData(&WNF_9P_UNKNOWN_DISTRO_NAME,0,0,0);
  if (iVar4 < 0) {
    local_20 = 0;
    local_38 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\usercallback.cpp";
    local_28 = 0x323;
    local_30 = "p9fs::UserCallbackManager::NotifyUserProcess";
    TraceLog((ErrorSite *)&local_38,iVar4);
  }
  else {
    pUVar1 = this + 0x10;
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(pUVar1,0);
    FindOrInsertCallbackWithLockHeld(this,&local_res20,param_2);
    puVar6 = auStack_78;
    if (local_res20 == (UserCallback *)0x0) {
      if (pUVar1 != (UserCallbackManager *)0x0) {
        ExReleasePushLockExclusiveEx(pUVar1,0);
        KeLeaveCriticalRegion();
      }
      iVar4 = -0x3fffff66;
    }
    else if ((*(longlong *)(local_res20 + 8) == 0) && (*(longlong *)(local_res20 + 0x38) == 0)) {
      *param_3 = local_res20;
      LOCK();
      lVar2 = *(longlong *)local_res20;
      *(longlong *)local_res20 = *(longlong *)local_res20 + 1;
      UNLOCK();
      pUVar5 = local_res20;
      if (lVar2 + 1 < 2) {
        pcVar3 = (code *)swi(0x29);
        pUVar5 = (UserCallback *)(*pcVar3)(0xe);
        puVar6 = auStack_70;
      }
      *(undefined8 **)(pUVar5 + 0x38) = param_3;
      *(undefined8 **)(local_res20 + 0x40) = param_3;
      local_res20[0x50] = (UserCallback)0x1;
      *(undefined8 *)(puVar6 + -8) = 0x14000b7c6;
      iVar4 = UserCallback::SetCallbackTimeout(local_res20);
      if (iVar4 < 0) {
        local_20 = 0;
        local_38 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\usercallback.cpp";
        local_28 = 0x337;
        local_30 = "p9fs::UserCallbackManager::NotifyUserProcess";
        *(undefined8 *)(puVar6 + -8) = 0x14000b7fa;
        TraceLog((ErrorSite *)&local_38,iVar4);
        *(undefined8 *)(puVar6 + -8) = 0x14000b802;
        UserCallback::ReleaseReference(local_res20);
        if (pUVar1 != (UserCallbackManager *)0x0) {
          *(undefined8 *)(puVar6 + -8) = 0x14000b813;
          ExReleasePushLockExclusiveEx(pUVar1,0);
          *(undefined8 *)(puVar6 + -8) = 0x14000b81f;
          KeLeaveCriticalRegion();
        }
      }
      else {
        *(undefined8 *)(puVar6 + -8) = 0x14000b830;
        UserCallback::ReleaseReference(local_res20);
        if (pUVar1 != (UserCallbackManager *)0x0) {
          *(undefined8 *)(puVar6 + -8) = 0x14000b841;
          ExReleasePushLockExclusiveEx(pUVar1,0);
          *(undefined8 *)(puVar6 + -8) = 0x14000b84d;
          KeLeaveCriticalRegion();
        }
        iVar4 = 0x103;
      }
    }
    else {
      UserCallback::ReleaseReference(local_res20);
      if (pUVar1 != (UserCallbackManager *)0x0) {
        ExReleasePushLockExclusiveEx(pUVar1,0);
        KeLeaveCriticalRegion();
      }
      iVar4 = -0x3ffffdd3;
    }
  }
  return iVar4;
}



===== RegisterUserCallback @ 14000b8a4 =====

/* public: long __cdecl p9fs::UserCallbackManager::RegisterUserCallback(struct _RX_CONTEXT *
   __ptr64) __ptr64 */

long __thiscall
p9fs::UserCallbackManager::RegisterUserCallback(UserCallbackManager *this,_RX_CONTEXT *param_1)

{
  UserCallbackManager *pUVar1;
  longlong lVar2;
  code *pcVar3;
  undefined8 uVar4;
  int iVar5;
  long lVar6;
  undefined8 *puVar7;
  longlong *plVar8;
  UserCallback *pUVar9;
  UserCallback *this_00;
  undefined1 *puVar10;
  bool bVar11;
  UserCallback *local_res8;
  UserCallback *local_res10;
  undefined1 auStack_e8 [8];
  undefined1 auStack_e0 [24];
  UserCallbackManager *local_c8;
  undefined8 local_b8;
  longlong lStack_b0;
  undefined8 uStack_a8;
  longlong local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  longlong lStack_80;
  char *local_78;
  char *local_70;
  undefined8 local_68;
  char *local_60;
  undefined1 local_58 [48];
  
  SeCaptureSubjectContext(local_58);
  puVar7 = (undefined8 *)GetLogonInformation((_SECURITY_SUBJECT_CONTEXT *)&local_78);
  uVar4 = *puVar7;
  lVar2 = puVar7[1];
  local_b8 = uVar4;
  lStack_b0 = lVar2;
  SeReleaseSubjectContext(local_58);
  pUVar1 = this + 0x10;
  local_88 = uVar4;
  lStack_80 = lVar2;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(pUVar1,0);
  local_98 = 0;
  uStack_90 = 0;
  if (*(uint *)(param_1 + 0x22c) < 0x202) {
    local_68 = 0x1e3;
    local_78 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\usercallback.cpp";
    local_70 = "p9fs::UserCallbackManager::RegisterUserCallback";
    local_60 = "P9: User callback buffer too small: %lu bytes.\n";
    TraceLog((ErrorSite *)&local_78,-0x3fffffff);
    if (pUVar1 != (UserCallbackManager *)0x0) {
      ExReleasePushLockExclusiveEx(pUVar1,0);
      KeLeaveCriticalRegion();
    }
    return -0x3fffffdd;
  }
  FindCallbackWithLockHeld(this,&local_res8,local_b8);
  bVar11 = false;
  this_00 = local_res8;
  if (local_res8 == (UserCallback *)0x0) {
    plVar8 = (longlong *)FindCallbackWithLockHeld(this,&local_res10,lStack_b0);
    this_00 = (UserCallback *)*plVar8;
    *plVar8 = 0;
    local_res8 = this_00;
    if (local_res10 != (UserCallback *)0x0) {
      UserCallback::ReleaseReference(local_res10);
    }
    bVar11 = this_00 == (UserCallback *)0x0;
  }
  if (bVar11) {
    pUVar9 = operator_new(0x58);
    if ((pUVar9 == (UserCallback *)0x0) ||
       (local_c8 = this,
       pUVar9 = (UserCallback *)UserCallback::UserCallback(pUVar9,param_1,local_b8,lStack_b0),
       pUVar9 == (UserCallback *)0x0)) {
      if (this_00 != (UserCallback *)0x0) {
        UserCallback::ReleaseReference(this_00);
      }
      if (pUVar1 != (UserCallbackManager *)0x0) {
        ExReleasePushLockExclusiveEx(pUVar1,0);
        KeLeaveCriticalRegion();
      }
      return -0x3fffff66;
    }
    lVar6 = UserCallback::Initialize(pUVar9);
    if (lVar6 < 0) {
      UserCallback::RemoveFromList(pUVar9);
      UserCallback::ReleaseReference(pUVar9);
      if (this_00 != (UserCallback *)0x0) {
        UserCallback::ReleaseReference(this_00);
      }
      if (pUVar1 != (UserCallbackManager *)0x0) {
        ExReleasePushLockExclusiveEx(pUVar1,0);
        KeLeaveCriticalRegion();
      }
      return lVar6;
    }
  }
  else {
    UserCallback::ReplyCallback(this_00,(_RX_CONTEXT *)&local_b8,(LogonInformation *)param_1);
    if (local_b8._0_1_ == (_RX_CONTEXT)0x0) {
      local_60 = (char *)0x0;
      local_78 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\usercallback.cpp";
      local_70 = "p9fs::UserCallbackManager::RegisterUserCallback";
      local_68 = 500;
      TraceLog((ErrorSite *)&local_78,(long)lStack_b0);
      if (this_00 != (UserCallback *)0x0) {
        UserCallback::ReleaseReference(this_00);
      }
      if (pUVar1 != (UserCallbackManager *)0x0) {
        ExReleasePushLockExclusiveEx(pUVar1,0);
        KeLeaveCriticalRegion();
      }
      return (long)lStack_b0;
    }
    local_98 = lStack_b0;
    uStack_90 = uStack_a8;
    pUVar9 = this_00;
  }
  puVar10 = auStack_e8;
  *(UserCallbackManager **)(param_1 + 0xd0) = this;
  *(UserCallback **)(param_1 + 0xd8) = pUVar9;
  LOCK();
  lVar2 = *(longlong *)pUVar9;
  *(longlong *)pUVar9 = *(longlong *)pUVar9 + 1;
  UNLOCK();
  if (lVar2 + 1 < 2) {
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(0xe);
    puVar10 = auStack_e0;
  }
  *(undefined8 *)(puVar10 + -8) = 0x14000bab6;
  iVar5 = RxSetMinirdrCancelRoutine(param_1,CancelRxContext);
  if (iVar5 < 0) {
    *(undefined8 *)(puVar10 + -8) = 0x14000bac7;
    UserCallback::RemoveFromList(pUVar9);
    *(undefined8 *)(puVar10 + -8) = 0x14000bad7;
    UserCallback::CompleteRequest(pUVar9,-0x3ffffee0,0);
    *(undefined8 *)(puVar10 + -8) = 0x14000badf;
    UserCallback::ReleaseReference(pUVar9);
  }
  if (pUVar1 != (UserCallbackManager *)0x0) {
    *(undefined8 *)(puVar10 + -8) = 0x14000baf0;
    ExReleasePushLockExclusiveEx(pUVar1,0);
    *(undefined8 *)(puVar10 + -8) = 0x14000bafc;
    KeLeaveCriticalRegion();
  }
  if (local_98 != 0) {
    *(undefined8 *)(puVar10 + -8) = 0x14000bb11;
    ResumeWaiters((WaiterList *)&local_98);
  }
  if (local_res8 != (UserCallback *)0x0) {
    *(undefined8 *)(puVar10 + -8) = 0x14000bb1f;
    UserCallback::ReleaseReference(local_res8);
  }
  return 0x103;
}



===== ReleaseReference @ 14000bc0c =====

/* public: bool __cdecl p9fs::UserCallback::ReleaseReference(void) __ptr64 */

bool __thiscall p9fs::UserCallback::ReleaseReference(UserCallback *this)

{
  longlong lVar1;
  code *pcVar2;
  
  LOCK();
  lVar1 = *(longlong *)this;
  *(longlong *)this = *(longlong *)this + -1;
  UNLOCK();
  if (lVar1 < 2) {
    if (lVar1 == 1) {
      if (this == (UserCallback *)0x0) {
        return true;
      }
      if (*(_EX_TIMER **)(this + 0x48) != (_EX_TIMER *)0x0) {
        details::DeleteTimer(*(_EX_TIMER **)(this + 0x48));
      }
      ExFreePoolWithTag(this,0);
      return true;
    }
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(0xe);
  }
  return false;
}



===== RemoveFromList @ 14000bc78 =====

/* public: void __cdecl p9fs::UserCallback::RemoveFromList(void) __ptr64 */

void __thiscall p9fs::UserCallback::RemoveFromList(UserCallback *this)

{
  UserCallback *pUVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  
  pUVar1 = this + 0x20;
  lVar2 = *(longlong *)pUVar1;
  if ((*(UserCallback **)(lVar2 + 8) == pUVar1) &&
     (plVar3 = *(longlong **)(this + 0x28), (UserCallback *)*plVar3 == pUVar1)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    CancelTimer(this);
    return;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== RemoveWaiter @ 14000bcb4 =====

/* private: void __cdecl p9fs::UserCallback::RemoveWaiter(class p9fs::WaitRxContext * __ptr64)
   __ptr64 */

void __thiscall p9fs::UserCallback::RemoveWaiter(UserCallback *this,WaitRxContext *param_1)

{
  UserCallback *pUVar1;
  WaitRxContext *pWVar2;
  WaitRxContext *pWVar3;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  pUVar1 = this + 0x30;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(pUVar1,0);
  pWVar3 = *(WaitRxContext **)(this + 0x38);
  if (pWVar3 == param_1) {
    *(undefined8 *)(this + 0x38) = *(undefined8 *)(param_1 + 0x18);
    if (*(WaitRxContext **)(this + 0x40) == param_1) {
      *(undefined8 *)(this + 0x40) = 0;
    }
    CancelTimer(this);
  }
  else {
    if (pWVar3 != (WaitRxContext *)0x0) {
      do {
        pWVar2 = *(WaitRxContext **)(pWVar3 + 0x18);
        if (pWVar2 == param_1) break;
        pWVar3 = pWVar2;
      } while (pWVar2 != (WaitRxContext *)0x0);
      if (pWVar3 != (WaitRxContext *)0x0) {
        *(undefined8 *)(pWVar3 + 0x18) = *(undefined8 *)(param_1 + 0x18);
        *(undefined8 *)(param_1 + 0x18) = 0;
        if (param_1 == *(WaitRxContext **)(this + 0x40)) {
          *(WaitRxContext **)(this + 0x40) = pWVar3;
        }
        goto LAB_14000bd80;
      }
    }
    local_18 = 0x19e;
    local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\usercallback.cpp";
    local_20 = "p9fs::UserCallback::RemoveWaiter";
    local_10 = "P9: Attempt to remove waiter that is not in the list.\n";
    TraceLog((ErrorSite *)&local_28,-0x3fffffff);
  }
LAB_14000bd80:
  if (pUVar1 != (UserCallback *)0x0) {
    ExReleasePushLockExclusiveEx(pUVar1,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== ReplyCallback @ 14000bdbc =====

/* public: class util::BasicExpected<struct p9fs::WaiterList,long> __cdecl
   p9fs::UserCallback::ReplyCallback(struct _RX_CONTEXT * __ptr64,struct p9fs::LogonInformation
   const & __ptr64) __ptr64 */

_RX_CONTEXT * __thiscall
p9fs::UserCallback::ReplyCallback(UserCallback *this,_RX_CONTEXT *param_1,LogonInformation *param_2)

{
  UserCallback *pUVar1;
  byte *pbVar2;
  int *in_R9;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  char *local_40;
  char *local_38;
  char *local_30;
  undefined8 local_28;
  char *local_20;
  
  uStack_50 = (char *)0x0;
  pUVar1 = this + 0x30;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(pUVar1);
  if (*(longlong *)(this + 8) == 0) {
    if (this[0x50] == (UserCallback)0x0) {
      local_28 = 0xeb;
      local_20 = "P9: Received callback reply.\n";
    }
    else {
      if ((*(int *)(this + 0x10) == *in_R9) && (*(int *)(this + 0x14) == in_R9[1])) {
        in_R9 = in_R9 + 2;
      }
      *(undefined8 *)(this + 0x18) = *(undefined8 *)in_R9;
      local_20 = "P9: Received callback registration after trigger-start.\n";
      uStack_50 = (char *)CONCAT71(uStack_50._1_7_,1);
      this[0x50] = (UserCallback)0x0;
      local_28 = 0xe5;
    }
    local_38 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\usercallback.cpp";
    local_30 = "p9fs::UserCallback::ReplyCallback";
    TraceLog((ErrorSite *)&local_38,0);
    *(LogonInformation **)(this + 8) = param_2;
    local_20 = "P9: Received callback reply.\n";
    local_38 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\usercallback.cpp";
    local_30 = "p9fs::UserCallback::ReplyCallback";
    local_28 = 0xef;
    TraceLog((ErrorSite *)&local_38,0);
    *(undefined4 *)(*(longlong *)(this + 8) + 0xb0) = 0x103;
    pbVar2 = (byte *)(*(longlong *)(*(longlong *)(*(longlong *)(this + 8) + 0x28) + 0xb8) + 3);
    *pbVar2 = *pbVar2 | 1;
    local_58 = *(char **)(this + 0x38);
    *(undefined8 *)(this + 0x38) = 0;
    *(undefined8 *)(this + 0x40) = 0;
    CancelTimer(this);
    *param_1 = (_RX_CONTEXT)0x1;
    *(undefined4 *)(param_1 + 8) = (undefined4)local_58;
    *(undefined4 *)(param_1 + 0xc) = local_58._4_4_;
    *(undefined4 *)(param_1 + 0x10) = (undefined4)uStack_50;
    *(undefined4 *)(param_1 + 0x14) = uStack_50._4_4_;
  }
  else {
    local_48 = 0xcf;
    local_40 = "P9: Received reply to callback that\'s not waiting.\n";
    local_58 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\usercallback.cpp";
    uStack_50 = "p9fs::UserCallback::ReplyCallback";
    TraceLog((ErrorSite *)&local_58,-0x3fffffff);
    *param_1 = (_RX_CONTEXT)0x0;
    *(undefined4 *)(param_1 + 8) = 0xc000a003;
  }
  if (pUVar1 != (UserCallback *)0x0) {
    ExReleasePushLockExclusiveEx(pUVar1,0);
    KeLeaveCriticalRegion();
  }
  return param_1;
}



===== ResumeWaiters @ 14000bf8c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl p9fs::UserCallbackManager::ResumeWaiters(struct p9fs::WaiterList
   const & __ptr64) */

void __cdecl p9fs::UserCallbackManager::ResumeWaiters(WaiterList *param_1)

{
  UserCallback *this;
  undefined8 *puVar1;
  undefined8 *puVar2;
  WaiterList WVar3;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  WVar3 = param_1[8];
  puVar2 = *(undefined8 **)param_1;
  while (puVar2 != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)puVar2[3];
    local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\usercallback.cpp";
    local_18 = 0x29e;
    local_20 = "p9fs::UserCallbackManager::ResumeWaiters";
    local_10 = "P9: Retrying create.\n";
    TraceLog((ErrorSite *)&local_28,0);
    LOCK();
    this = (UserCallback *)*puVar2;
    *puVar2 = 0;
    UNLOCK();
    if (this != (UserCallback *)0x0) {
      (*(code *)puVar2[1])(puVar2[2],0,WVar3);
      UserCallback::ReleaseReference(this);
    }
    WVar3 = (WaiterList)0x1;
    puVar2 = puVar1;
  }
  return;
}



===== SetCallbackTimeout @ 14000c03c =====

/* private: long __cdecl p9fs::UserCallback::SetCallbackTimeout(void) __ptr64 */

long __thiscall p9fs::UserCallback::SetCallbackTimeout(UserCallback *this)

{
  longlong lVar1;
  undefined8 uVar2;
  code *pcVar3;
  undefined1 *puVar4;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [32];
  
  puVar4 = auStack_28;
  LOCK();
  lVar1 = *(longlong *)this;
  *(longlong *)this = *(longlong *)this + 1;
  UNLOCK();
  if (lVar1 + 1 < 2) {
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(0xe);
    puVar4 = auStack_20;
  }
  uVar2 = *(undefined8 *)(this + 0x48);
  *(undefined8 *)(puVar4 + -8) = 0x14000c075;
  ExSetTimer(uVar2,0xfffffffff4143e00,0,0);
  return 0;
}



===== TimerCallback @ 14000c090 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* private: static void __cdecl p9fs::UserCallback::TimerCallback(struct _EX_TIMER * __ptr64,void *
   __ptr64) */

void __cdecl p9fs::UserCallback::TimerCallback(_EX_TIMER *param_1,void *param_2)

{
  int iVar1;
  UserCallback *this;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  char *local_10;
  
  local_18 = 0x1bf;
  local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\sys\\usercallback.cpp";
  local_20 = "p9fs::UserCallback::TimerCallback";
  local_10 = "P9: User callback timed out.\n";
  TraceLog((ErrorSite *)&local_28,0);
  iVar1 = RxDispatchToWorkerThread
                    (_GlobalDevice,3,
                     <lambda_db9de5964e1bd3f2ba08d009c80347e5>::<lambda_invoker_cdecl><void_*>,
                     param_2);
  this = (UserCallback *)0x0;
  if (iVar1 < 0) {
    this = param_2;
  }
  if (this != (UserCallback *)0x0) {
    ReleaseReference(this);
  }
  return;
}



===== Feature_4009910584__private_IsEnabledDeviceUsageNoInline @ 14000c110 =====

ulonglong Feature_4009910584__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)(uint)Feature_4009910584__private_featureState;
  if (((uint)Feature_4009910584__private_featureState & 0x10) == 0) {
    uVar1 = Feature_4009910584__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)((uint)Feature_4009910584__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_4009910584__private_IsEnabledFallback @ 14000c148 =====

void Feature_4009910584__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_4009910584__private_descriptor);
  return;
}



===== ~FidLease @ 14000c164 =====

/* public: __cdecl p9fs::FidLease::~FidLease(void) __ptr64 */

void __thiscall p9fs::FidLease::~FidLease(FidLease *this)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  longlong local_18;
  undefined1 uStack_10;
  undefined4 uStack_f;
  undefined2 uStack_b;
  undefined1 uStack_9;
  
  uVar2 = *(uint *)(this + 8);
  if (uVar2 != 0xffffffff) {
    lVar3 = *(longlong *)this;
    lVar1 = lVar3 + 0x20;
    uVar5 = KeAcquireSpinLockRaiseToDpc(lVar1);
    uVar4 = _uStack_10;
    _uStack_10 = CONCAT41(uStack_f,uVar5);
    uStack_b = SUB82(uVar4,5);
    uStack_9 = SUB81(uVar4,7);
    local_18 = lVar1;
    DbgPrint("Returning %d\n",uVar2);
    if (uVar2 < *(uint *)(lVar3 + 0x28)) {
      *(uint *)(lVar3 + 0x28) = uVar2;
    }
    RtlClearBit(lVar3 + 0x10,uVar2);
    if (lVar1 != 0) {
      wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_18);
    }
  }
  *(undefined4 *)(this + 8) = 0xffffffff;
  return;
}



===== ~FidProvider @ 14000c22c =====

/* public: __cdecl p9fs::FidProvider::~FidProvider(void) __ptr64 */

void __thiscall p9fs::FidProvider::~FidProvider(FidProvider *this)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)this;
  *(undefined8 *)this = 0;
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0);
  }
  return;
}



===== GetNewFid @ 14000c25c =====

/* public: class util::BasicExpected<class p9fs::FidLease,long> __cdecl
   p9fs::FidProvider::GetNewFid(void) __ptr64 */

void __thiscall p9fs::FidProvider::GetNewFid(FidProvider *this)

{
  FidProvider *pFVar1;
  undefined1 uVar2;
  int iVar3;
  undefined1 *in_RDX;
  undefined8 in_R9;
  FidProvider *pFVar4;
  undefined4 uStack_1f;
  undefined2 uStack_1b;
  undefined1 uStack_19;
  FidProvider *local_18;
  undefined8 uStack_10;
  
  pFVar1 = this + 0x20;
  uVar2 = KeAcquireSpinLockRaiseToDpc(pFVar1);
  pFVar4 = pFVar1;
  iVar3 = RtlFindClearBitsAndSet(this + 0x10,1,*(undefined4 *)(this + 0x28),in_R9,pFVar1,uVar2);
  if (iVar3 == -1) {
    *in_RDX = 0;
    *(undefined4 *)(in_RDX + 8) = 0xc000009a;
  }
  else {
    *(int *)(this + 0x28) = iVar3 + 1;
    *(int *)(in_RDX + 0x10) = iVar3;
    *in_RDX = 1;
    *(FidProvider **)(in_RDX + 8) = this;
    uStack_10 = CONCAT44(uStack_10._4_4_,0xffffffff);
    local_18 = this;
    FidLease::~FidLease((FidLease *)&local_18);
  }
  if (pFVar1 != (FidProvider *)0x0) {
    uStack_10 = CONCAT17(uStack_19,CONCAT25(uStack_1b,CONCAT41(uStack_1f,uVar2)));
    local_18 = pFVar4;
    wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_18);
  }
  return;
}



===== <lambda_invoker_cdecl><p9fs::StatFsResult_const_&,void_*> @ 14000c330 =====

void <lambda_22d39e197da456b3d32f68b152e2332a>::
     <lambda_invoker_cdecl><p9fs::StatFsResult_const_&,void_*>(undefined4 *param_1,longlong param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  
  uVar1 = param_1[1];
  uVar2 = param_1[2];
  uVar3 = param_1[3];
  uVar4 = param_1[4];
  uVar5 = param_1[5];
  uVar6 = param_1[6];
  uVar7 = param_1[7];
  uVar8 = param_1[8];
  uVar9 = param_1[9];
  uVar10 = param_1[10];
  uVar11 = param_1[0xb];
  uVar12 = param_1[0xc];
  uVar13 = param_1[0xd];
  uVar14 = param_1[0xe];
  uVar15 = param_1[0xf];
  *(undefined4 *)(param_2 + 0x20) = *param_1;
  *(undefined4 *)(param_2 + 0x24) = uVar1;
  *(undefined4 *)(param_2 + 0x28) = uVar2;
  *(undefined4 *)(param_2 + 0x2c) = uVar3;
  *(undefined4 *)(param_2 + 0x30) = uVar4;
  *(undefined4 *)(param_2 + 0x34) = uVar5;
  *(undefined4 *)(param_2 + 0x38) = uVar6;
  *(undefined4 *)(param_2 + 0x3c) = uVar7;
  *(undefined4 *)(param_2 + 0x40) = uVar8;
  *(undefined4 *)(param_2 + 0x44) = uVar9;
  *(undefined4 *)(param_2 + 0x48) = uVar10;
  *(undefined4 *)(param_2 + 0x4c) = uVar11;
  *(undefined4 *)(param_2 + 0x50) = uVar12;
  *(undefined4 *)(param_2 + 0x54) = uVar13;
  *(undefined4 *)(param_2 + 0x58) = uVar14;
  *(undefined4 *)(param_2 + 0x5c) = uVar15;
  KeSetEvent(param_2,0,0);
  return;
}



===== <lambda_invoker_cdecl><unsigned_int,unsigned_short,gsl::span<enum_gsl::byte_const_,-1>,void_*> @ 14000c380 =====

void <lambda_b317092193afddf539e07e3a80607ab1>::
     <lambda_invoker_cdecl><unsigned_int,unsigned_short,gsl::span<enum_gsl::byte_const_,_1>,void_*>
               (undefined4 param_1,ushort param_2,ulonglong *param_3,longlong param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  ulonglong uVar5;
  ulonglong local_38;
  ulonglong uStack_30;
  undefined8 local_28;
  ulonglong local_18;
  ulonglong uStack_10;
  
  local_38 = *param_3;
  uStack_30 = param_3[1];
  *(undefined4 *)(param_4 + 0x20) = param_1;
  if (param_2 != 0) {
    uVar5 = (ulonglong)((uint)param_2 * 0xd - 0xd);
    if ((local_38 < uVar5) || (local_18 = local_38 - uVar5, local_18 == 0xffffffffffffffff)) {
                    /* WARNING: Subroutine does not return */
      gsl::details::terminate();
    }
    uStack_30 = uStack_30 + uVar5;
    local_28 = 0;
    local_38 = local_18;
    uStack_10 = uStack_30;
    puVar4 = (undefined4 *)p9fs::SpanReader::Qid((SpanReader *)&local_38);
    uVar1 = puVar4[1];
    uVar2 = puVar4[2];
    uVar3 = puVar4[3];
    *(undefined4 *)(param_4 + 0x28) = *puVar4;
    *(undefined4 *)(param_4 + 0x2c) = uVar1;
    *(undefined4 *)(param_4 + 0x30) = uVar2;
    *(undefined4 *)(param_4 + 0x34) = uVar3;
  }
  KeSetEvent(param_4,0,0);
  return;
}



===== <lambda_invoker_cdecl><unsigned_int,enum_p9fs::WOpenStatus,unsigned_int,p9fs::Qid,std::basic_string_view<char>,unsigned_int,p9fs::StatResult_const_&,void_*> @ 14000c420 =====

void <lambda_a9925a96b5dba09fd9b9e575892a499b>::
     <lambda_invoker_cdecl><unsigned_int,enum_p9fs::WOpenStatus,unsigned_int,p9fs::Qid,std::basic_string_view<char>,unsigned_int,p9fs::StatResult_const_&,void_*>
               (undefined4 param_1,undefined1 param_2,undefined4 param_3,undefined8 *param_4,
               ulonglong *param_5,undefined4 param_6,undefined8 *param_7,longlong param_8)

{
  ulonglong uVar1;
  undefined8 uVar2;
  longlong lVar3;
  ulonglong _Size;
  void *_Src;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  void *_Dst;
  
  uVar4 = *param_4;
  uVar5 = param_4[1];
  uVar6 = param_7[1];
  uVar7 = param_7[2];
  uVar8 = param_7[3];
  uVar9 = param_7[4];
  uVar10 = param_7[5];
  uVar11 = param_7[6];
  uVar12 = param_7[7];
  uVar13 = param_7[8];
  uVar14 = param_7[9];
  uVar15 = param_7[10];
  uVar16 = param_7[0xb];
  uVar2 = param_7[0xc];
  *(undefined8 *)(param_8 + 0x50) = *param_7;
  *(undefined8 *)(param_8 + 0x58) = uVar6;
  *(undefined4 *)(param_8 + 0x20) = param_1;
  *(undefined8 *)(param_8 + 0x60) = uVar7;
  *(undefined8 *)(param_8 + 0x68) = uVar8;
  *(undefined1 *)(param_8 + 0x24) = param_2;
  _Size = *param_5;
  _Src = (void *)param_5[1];
  *(undefined8 *)(param_8 + 0x70) = uVar9;
  *(undefined8 *)(param_8 + 0x78) = uVar10;
  *(undefined4 *)(param_8 + 0x28) = param_3;
  *(undefined8 *)(param_8 + 0x80) = uVar11;
  *(undefined8 *)(param_8 + 0x88) = uVar12;
  *(undefined4 *)(param_8 + 0x48) = param_6;
  *(undefined8 *)(param_8 + 0x90) = uVar13;
  *(undefined8 *)(param_8 + 0x98) = uVar14;
  *(undefined8 *)(param_8 + 0xa0) = uVar15;
  *(undefined8 *)(param_8 + 0xa8) = uVar16;
  *(undefined8 *)(param_8 + 0x30) = uVar4;
  *(undefined8 *)(param_8 + 0x38) = uVar5;
  uVar1 = _Size + 1;
  *(undefined8 *)(param_8 + 0xb0) = uVar2;
  _Dst = operator_new(uVar1);
  if (_Dst == (void *)0x0) {
    *(undefined4 *)(param_8 + 0x18) = 0xc000009a;
LAB_14000c561:
    KeSetEvent(param_8,0,0);
    return;
  }
  if ((((((uVar1 != 0xffffffffffffffff) && (_Size != 0xffffffffffffffff)) &&
        ((_Src != (void *)0x0 || (_Size == 0)))) &&
       ((_Size <= uVar1 && (_Size != 0xffffffffffffffff)))) &&
      ((_Src != (void *)0x0 || (_Size == 0)))) && (_Size <= uVar1)) {
    memmove(_Dst,_Src,_Size);
    if (_Size < uVar1) {
      *(undefined1 *)((longlong)_Dst + _Size) = 0;
      lVar3 = *(longlong *)(param_8 + 0x40);
      *(void **)(param_8 + 0x40) = _Dst;
      if (lVar3 != 0) {
        ExFreePoolWithTag(lVar3,0);
      }
      goto LAB_14000c561;
    }
  }
                    /* WARNING: Subroutine does not return */
  gsl::details::terminate();
}



===== <lambda_invoker_cdecl><long,void_*> @ 14000c5b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void <lambda_885416cc7ccce8bc388436daf3235291>::<lambda_invoker_cdecl><long,void_*>
               (ulonglong param_1,longlong *param_2)

{
  uint uVar1;
  code *pcVar2;
  longlong lVar3;
  char local_28 [8];
  long local_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if ((int)param_1 < 0) {
    pcVar2 = (code *)param_2[2];
    lVar3 = param_2[3];
  }
  else {
    uVar1 = p9fs::P9Client::FillData((P9Client *)*param_2);
    param_1 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      *(undefined1 *)(*param_2 + 0x88) = 1;
      local_18 = 8;
      uStack_14 = 0;
      uStack_10 = 0x40017b60;
      uStack_c = 1;
      p9fs::P9Client::Negotiate((P9Client *)*param_2,local_28);
      if ((local_28[0] != '\0') &&
         (local_20 = p9fs::P9Client::SendExchange
                               ((P9Client *)*param_2,(Exchange *)CONCAT44(uStack_1c,local_20),true),
         -1 < local_20)) {
        if (local_28[0] == '\0') {
          return;
        }
        p9fs::SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>
                  ((SharedPtr<p9fs::Exchange> *)&local_20);
        return;
      }
      (*(code *)param_2[2])(local_20,param_2[3]);
      if (local_28[0] != '\0') {
        p9fs::SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>
                  ((SharedPtr<p9fs::Exchange> *)&local_20);
      }
      goto LAB_14000c5d1;
    }
    pcVar2 = (code *)param_2[2];
    lVar3 = param_2[3];
  }
  (*pcVar2)(param_1,lVar3);
LAB_14000c5d1:
  ExFreePoolWithTag(param_2,0);
  return;
}



===== <lambda_invoker_cdecl><long,void_*> @ 14000c6b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void <lambda_c7d885a82edffe1fe9d980783ef3870a>::<lambda_invoker_cdecl><long,void_*>
               (uint param_1,longlong *param_2)

{
  char local_38 [8];
  long local_30;
  undefined4 uStack_2c;
  char *local_28;
  char *pcStack_20;
  undefined8 local_18;
  char *local_10;
  
  local_18 = 0x91;
  local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
  pcStack_20 = 
  "p9fs::P9Client::Connect::<lambda_885416cc7ccce8bc388436daf3235291>::()::<lambda_c7d885a82edffe1fe9d980783ef3870a>::operator ()"
  ;
  local_10 = "Negotiate() failed with 0x%x";
  p9fs::TraceLog((ErrorSite *)&local_28,-0x3fffffff,(ulonglong)param_1);
  if (param_1 == 0xc0000463) {
    *(undefined1 *)(*param_2 + 0x88) = 0;
    local_28 = (char *)0x8;
    pcStack_20 = "9P2000.L";
    p9fs::P9Client::Negotiate((P9Client *)*param_2,local_38);
    if ((local_38[0] == '\0') ||
       (local_30 = p9fs::P9Client::SendExchange
                             ((P9Client *)*param_2,(Exchange *)CONCAT44(uStack_2c,local_30),true),
       local_30 < 0)) {
      (*(code *)param_2[2])(local_30,param_2[3]);
    }
    if (local_38[0] != '\0') {
      p9fs::SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>
                ((SharedPtr<p9fs::Exchange> *)&local_30);
    }
  }
  else {
    (*(code *)param_2[2])(param_1,param_2[3]);
  }
  ExFreePoolWithTag(param_2,0);
  return;
}



===== <lambda_invoker_cdecl><void_*> @ 14000c7d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void <lambda_64722871e2ac3aecf52e1a467ed8eece>::<lambda_invoker_cdecl><void_*>(longlong param_1)

{
  (**(code **)(param_1 + 8))(*(undefined8 *)(param_1 + 0x18));
  ExFreePoolWithTag(param_1,0);
  return;
}



===== <lambda_invoker_cdecl><p9fs::Qid,unsigned_int,void_*> @ 14000c810 =====

void <lambda_66e576979ea43980c2067f8f9e2d60a1>::
     <lambda_invoker_cdecl><p9fs::Qid,unsigned_int,void_*>
               (undefined4 *param_1,undefined4 param_2,longlong param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar1 = *param_1;
  uVar2 = param_1[1];
  uVar3 = param_1[2];
  uVar4 = param_1[3];
  *(undefined4 *)(param_3 + 0x30) = param_2;
  *(undefined4 *)(param_3 + 0x20) = uVar1;
  *(undefined4 *)(param_3 + 0x24) = uVar2;
  *(undefined4 *)(param_3 + 0x28) = uVar3;
  *(undefined4 *)(param_3 + 0x2c) = uVar4;
  KeSetEvent(param_3,0,0);
  return;
}



===== <lambda_invoker_cdecl><p9fs::Qid,void_*> @ 14000c850 =====

void <lambda_cb63b31bc136f3dc874582943a742327>::<lambda_invoker_cdecl><p9fs::Qid,void_*>
               (undefined4 *param_1,longlong param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = param_1[1];
  uVar2 = param_1[2];
  uVar3 = param_1[3];
  *(undefined4 *)(param_2 + 0x20) = *param_1;
  *(undefined4 *)(param_2 + 0x24) = uVar1;
  *(undefined4 *)(param_2 + 0x28) = uVar2;
  *(undefined4 *)(param_2 + 0x2c) = uVar3;
  KeSetEvent(param_2,0,0);
  return;
}



===== <lambda_invoker_cdecl><gsl::span<enum_gsl::byte_const_,-1>,void_*> @ 14000c880 =====

void <lambda_f2b2459de070180cb9d191c0493c3427>::
     <lambda_invoker_cdecl><gsl::span<enum_gsl::byte_const_,_1>,void_*>
               (ulonglong *param_1,longlong param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  ulonglong uStack_10;
  
  uVar2 = *param_1;
  if (*(ulonglong *)(param_2 + 0x20) < uVar2) {
    *(undefined4 *)(param_2 + 0x18) = 0xc0000186;
  }
  else {
    local_28 = *(ulonglong *)(param_2 + 0x20);
    uStack_20 = *(undefined8 *)(param_2 + 0x28);
    local_18 = uVar2;
    uStack_10 = param_1[1];
    gsl::copy<gsl::byte_const_,_1,gsl::byte,_1>(&local_18,&local_28);
    uVar1 = *(ulonglong *)(param_2 + 0x20);
    if (uVar2 == 0xffffffffffffffff) {
      local_28 = uVar1;
      if (uVar1 == 0xffffffffffffffff) {
LAB_14000c916:
                    /* WARNING: Subroutine does not return */
        gsl::details::terminate();
      }
    }
    else {
      if (uVar1 < uVar2) goto LAB_14000c916;
      local_28 = uVar2;
    }
    uStack_20 = *(undefined8 *)(param_2 + 0x28);
    *(ulonglong *)(param_2 + 0x20) = local_28;
    *(undefined8 *)(param_2 + 0x28) = uStack_20;
  }
  KeSetEvent(param_2,0,0);
  return;
}



===== <lambda_invoker_cdecl><unsigned___int64,p9fs::Qid,p9fs::StatResult_const_&,void_*> @ 14000c930 =====

void <lambda_0edc01e6e64b501bbf8dc1ae09b4c941>::
     <lambda_invoker_cdecl><unsigned___int64,p9fs::Qid,p9fs::StatResult_const_&,void_*>
               (undefined8 param_1,undefined4 *param_2,undefined4 *param_3,longlong param_4)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  
  uVar2 = *param_3;
  uVar3 = param_3[1];
  uVar4 = param_3[2];
  uVar5 = param_3[3];
  uVar10 = *(undefined8 *)(param_3 + 4);
  uVar11 = *(undefined8 *)(param_3 + 6);
  uVar12 = *(undefined8 *)(param_3 + 8);
  uVar13 = *(undefined8 *)(param_3 + 10);
  uVar1 = *(undefined8 *)(param_3 + 0x18);
  uVar6 = *param_2;
  uVar7 = param_2[1];
  uVar8 = param_2[2];
  uVar9 = param_2[3];
  uVar14 = *(undefined8 *)(param_3 + 0xc);
  uVar15 = *(undefined8 *)(param_3 + 0xe);
  uVar16 = *(undefined8 *)(param_3 + 0x10);
  uVar17 = *(undefined8 *)(param_3 + 0x12);
  uVar18 = *(undefined8 *)(param_3 + 0x14);
  uVar19 = *(undefined8 *)(param_3 + 0x16);
  *(undefined8 *)(param_4 + 0x20) = param_1;
  *(undefined4 *)(param_4 + 0x38) = uVar2;
  *(undefined4 *)(param_4 + 0x3c) = uVar3;
  *(undefined4 *)(param_4 + 0x40) = uVar4;
  *(undefined4 *)(param_4 + 0x44) = uVar5;
  *(undefined8 *)(param_4 + 0x48) = uVar10;
  *(undefined8 *)(param_4 + 0x50) = uVar11;
  *(undefined8 *)(param_4 + 0x58) = uVar12;
  *(undefined8 *)(param_4 + 0x60) = uVar13;
  *(undefined8 *)(param_4 + 0x68) = uVar14;
  *(undefined8 *)(param_4 + 0x70) = uVar15;
  *(undefined8 *)(param_4 + 0x78) = uVar16;
  *(undefined8 *)(param_4 + 0x80) = uVar17;
  *(undefined8 *)(param_4 + 0x88) = uVar18;
  *(undefined8 *)(param_4 + 0x90) = uVar19;
  *(undefined8 *)(param_4 + 0x98) = uVar1;
  *(undefined4 *)(param_4 + 0x28) = uVar6;
  *(undefined4 *)(param_4 + 0x2c) = uVar7;
  *(undefined4 *)(param_4 + 0x30) = uVar8;
  *(undefined4 *)(param_4 + 0x34) = uVar9;
  KeSetEvent(param_4,0,0);
  return;
}



===== ~P9Client @ 14000c9d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: __cdecl p9fs::P9Client::~P9Client(void) __ptr64 */

void __thiscall p9fs::P9Client::~P9Client(P9Client *this)

{
  longlong lVar1;
  
  (**(code **)(**(longlong **)this + 0x28))();
  (**(code **)(**(longlong **)(this + 8) + 0x10))(*(longlong **)(this + 8),CleanupExchange);
  FidProvider::~FidProvider((FidProvider *)(this + 0x30));
  lVar1 = *(longlong *)(this + 0x10);
  *(undefined8 *)(this + 0x10) = 0;
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0);
  }
  return;
}



===== Access @ 14000ca34 =====

/* public: class util::BasicExpected<class p9fs::SharedPtr<class p9fs::Exchange>,long> __cdecl
   p9fs::P9Client::Access(unsigned int,enum p9fs::AccessFlags,void (__cdecl*)(void * __ptr64),void
   (__cdecl*)(long,void * __ptr64),void * __ptr64) __ptr64 */

SpanWriter * __thiscall
p9fs::P9Client::Access
          (P9Client *this,uint param_1,AccessFlags param_2,_func_void_void_ptr *param_3,
          _func_void_long_void_ptr *param_4,void *param_5)

{
  _func_void_long_void_ptr *p_Var1;
  _func_void_long_void_ptr *p_Var2;
  undefined4 in_register_00000014;
  SpanWriter *pSVar3;
  long lVar4;
  undefined7 uVar5;
  undefined8 local_58;
  _func_void_long_void_ptr *p_Stack_50;
  char local_48 [8];
  _func_void_long_void_ptr *local_40;
  char *local_38;
  char *local_30;
  _func_void_long_void_ptr *p_Stack_28;
  undefined8 local_20;
  undefined8 local_18;
  
  uVar5 = (undefined7)((ulonglong)param_3 >> 8);
  pSVar3 = (SpanWriter *)CONCAT44(in_register_00000014,param_1);
  AllocateBuffer((MessageType)local_48,CONCAT71((int7)((ulonglong)pSVar3 >> 8),0x80));
  p_Var2 = local_40;
  if (local_48[0] == '\0') {
    local_18 = 0;
    local_30 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
    lVar4 = (long)local_40;
    local_20 = 0x2c3;
    p_Stack_28 = (_func_void_long_void_ptr *)0x140017e50;
    TraceLog((ErrorSite *)&local_30,lVar4);
    *pSVar3 = (SpanWriter)0x0;
    *(long *)(pSVar3 + 8) = lVar4;
  }
  else {
    if (local_38 == (char *)0x0) {
      p_Stack_50 = (_func_void_long_void_ptr *)0x0;
    }
    else {
      if (local_38 == (char *)0xffffffffffffffff) goto LAB_14000cbea;
      p_Stack_50 = local_40;
      if (local_40 == (_func_void_long_void_ptr *)0x0) goto LAB_14000cbea;
    }
    p_Var1 = p_Stack_50;
    local_30 = local_38;
    p_Stack_28 = p_Stack_50;
    if ((((local_38 < (char *)0x7) || (local_38 + -7 < (char *)0x4)) ||
        (*(AccessFlags *)(p_Stack_50 + 7) = param_2, local_38 < (char *)0xb)) ||
       (local_38 + -0xb < (char *)0x4)) {
LAB_14000cbea:
                    /* WARNING: Subroutine does not return */
      gsl::details::terminate();
    }
    local_58 = 0;
    p_Stack_50 = (_func_void_long_void_ptr *)0xffffffff;
    *(undefined4 *)(p_Var1 + 0xb) = 8;
    local_40 = (_func_void_long_void_ptr *)0x0;
    param_4 = p_Var2;
    local_20 = 0xf;
    CreateExchange(this,pSVar3,(MessageType)&local_30,(FidLease *)CONCAT71(uVar5,0x80),
                   (unique_ptr<enum_gsl::byte_[0],wistd::default_delete<enum_gsl::byte_[0]>_> *)
                   &local_58,&param_4,SyncContextGenericCallback,SyncContextErrorCallback);
    FidLease::~FidLease((FidLease *)&local_58);
    if (param_4 != (_func_void_long_void_ptr *)0x0) {
      ExFreePoolWithTag(param_4,0);
    }
  }
  p_Var2 = local_40;
  if (local_48[0] != '\0') {
    local_40 = (_func_void_long_void_ptr *)0x0;
    if (p_Var2 != (_func_void_long_void_ptr *)0x0) {
      ExFreePoolWithTag(p_Var2,0);
    }
  }
  return pSVar3;
}



===== Access @ 14000cbf8 =====

/* public: long __cdecl p9fs::P9Client::Access(unsigned int,enum p9fs::AccessFlags,class
   p9fs::ICancellationManager * __ptr64) __ptr64 */

long __thiscall
p9fs::P9Client::Access
          (P9Client *this,uint param_1,AccessFlags param_2,ICancellationManager *param_3)

{
  long lVar1;
  ICancellationManager *pIVar2;
  _func_void_long_void_ptr *in_stack_ffffffffffffff88;
  void *in_stack_ffffffffffffff90;
  char local_58 [8];
  Exchange *local_50;
  char *local_48;
  char *local_40;
  undefined8 local_38;
  undefined8 local_30;
  SyncContextHeader local_28 [24];
  undefined4 local_10;
  
  pIVar2 = param_3;
  KeInitializeEvent(local_28,1);
  local_10 = 0;
  Access(this,(uint)local_58,param_1,(_func_void_void_ptr *)pIVar2,in_stack_ffffffffffffff88,
         in_stack_ffffffffffffff90);
  if (local_58[0] == '\0') {
    local_30 = 0;
    local_48 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
    local_38 = 0x2d1;
    local_40 = "p9fs::P9Client::Access";
    lVar1 = (long)local_50;
    TraceLog((ErrorSite *)&local_48,lVar1);
  }
  else {
    lVar1 = WaitWithCancellation(this,local_28,local_50,param_3);
  }
  if (local_58[0] != '\0') {
    SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>((SharedPtr<p9fs::Exchange> *)&local_50);
  }
  return lVar1;
}



===== AllocateBuffer @ 14000ccd0 =====

/* private: static class util::BasicExpected<class util::DynamicArray<enum gsl::byte>,long> __cdecl
   p9fs::P9Client::AllocateBuffer(enum p9fs::MessageType,unsigned __int64) */

undefined1 * __cdecl p9fs::P9Client::AllocateBuffer(MessageType param_1,__uint64 param_2)

{
  uint uVar1;
  long lVar2;
  undefined4 in_register_0000000c;
  undefined1 *puVar3;
  __uint64 in_R8;
  longlong local_18;
  undefined8 local_10;
  
  puVar3 = (undefined1 *)CONCAT44(in_register_0000000c,param_1);
  local_18 = 0;
  local_10 = 0;
  uVar1 = GetMessageSize((MessageType)CONCAT71((int7)((ulonglong)puVar3 >> 8),(char)param_2));
  lVar2 = util::DynamicArray<gsl::byte>::Reset
                    ((DynamicArray<gsl::byte> *)&local_18,(ulonglong)((int)in_R8 + uVar1),in_R8);
  if (lVar2 < 0) {
    *puVar3 = 0;
    *(long *)(puVar3 + 8) = lVar2;
    if (local_18 != 0) {
      ExFreePoolWithTag(local_18,0);
    }
  }
  else {
    *(longlong *)(puVar3 + 8) = local_18;
    *(undefined8 *)(puVar3 + 0x10) = local_10;
    *puVar3 = 1;
  }
  return puVar3;
}



===== Attach @ 14000cd44 =====

/* public: class util::BasicExpected<class p9fs::SharedPtr<class p9fs::Exchange>,long> __cdecl
   p9fs::P9Client::Attach(class std::basic_string_view<char>,class
   std::basic_string_view<char>,unsigned int,void (__cdecl*)(unsigned int,struct p9fs::Qid,void *
   __ptr64),void (__cdecl*)(long,void * __ptr64),void * __ptr64) __ptr64 */

SpanWriter * __thiscall
p9fs::P9Client::Attach
          (P9Client *this,SpanWriter *param_2,undefined8 *param_3,ulonglong *param_4,
          undefined4 param_5,_func_void_long_void_ptr *param_6,void *param_7)

{
  char *pcVar1;
  char *pcVar2;
  long lVar3;
  undefined7 uVar4;
  char *local_res18;
  char *local_88;
  char *pcStack_80;
  char local_78 [8];
  char *local_70;
  char *local_68;
  char *local_60;
  char *pcStack_58;
  char *local_50;
  undefined8 local_48;
  char local_40;
  long local_38 [2];
  undefined4 local_30;
  
  uVar4 = (undefined7)((ulonglong)param_4 >> 8);
  AllocateBuffer((MessageType)local_78,CONCAT71((int7)((ulonglong)param_2 >> 8),0x68));
  if (local_78[0] == '\0') {
    local_60 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
    local_50 = (char *)0xd1;
    lVar3 = (long)local_70;
    pcStack_58 = "p9fs::P9Client::Attach";
    local_48 = 0;
    TraceLog((ErrorSite *)&local_60,lVar3);
    *param_2 = (SpanWriter)0x0;
    *(long *)(param_2 + 8) = lVar3;
  }
  else {
    if (local_68 == (char *)0x0) {
      pcStack_80 = (char *)0x0;
      local_88 = (char *)0x0;
    }
    else {
      local_88 = local_68;
      if (local_68 == (char *)0xffffffffffffffff) goto LAB_14000cfb4;
      pcStack_80 = local_70;
      if (local_70 == (char *)0x0) goto LAB_14000cfb4;
    }
    pcVar2 = pcStack_80;
    pcVar1 = local_88;
    local_60 = local_88;
    pcStack_58 = pcStack_80;
    if (local_88 < (char *)0x7) goto LAB_14000cfb4;
    FidProvider::GetNewFid((FidProvider *)(this + 0x30));
    if (local_40 == '\0') {
      local_60 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
      local_50 = (char *)0xd5;
      pcStack_58 = "p9fs::P9Client::Attach";
      local_48 = 0;
      TraceLog((ErrorSite *)&local_60,local_38[0]);
      *param_2 = (SpanWriter)0x0;
      *(long *)(param_2 + 8) = local_38[0];
    }
    else {
      if (((pcVar1 + -7 < (char *)0x4) ||
          (*(undefined4 *)(pcVar2 + 7) = local_30, pcVar1 < (char *)0xb)) ||
         (pcVar1 + -0xb < (char *)0x4)) {
LAB_14000cfb4:
                    /* WARNING: Subroutine does not return */
        gsl::details::terminate();
      }
      local_88 = (char *)*param_3;
      pcStack_80 = (char *)param_3[1];
      pcVar2[0xb] = -1;
      pcVar2[0xc] = -1;
      pcVar2[0xd] = -1;
      pcVar2[0xe] = -1;
      local_50 = (char *)0xf;
      SpanWriter::String((SpanWriter *)&local_60,&local_88);
      local_88 = (char *)*param_4;
      pcStack_80 = (char *)param_4[1];
      SpanWriter::String((SpanWriter *)&local_60,&local_88);
      if ((local_60 < local_50) || ((ulonglong)((longlong)local_60 - (longlong)local_50) < 4))
      goto LAB_14000cfb4;
      pcVar2 = pcStack_58 + (longlong)local_50;
      local_50 = local_50 + 4;
      *(undefined4 *)pcVar2 = param_5;
      local_res18 = local_70;
      local_70 = (char *)0x0;
      CreateExchange(this,param_2,(MessageType)&local_60,(FidLease *)CONCAT71(uVar4,0x68),
                     (unique_ptr<enum_gsl::byte_[0],wistd::default_delete<enum_gsl::byte_[0]>_> *)
                     local_38,&local_res18,param_6,param_7);
      if (local_res18 != (char *)0x0) {
        ExFreePoolWithTag(local_res18,0);
      }
    }
    if (local_40 != '\0') {
      FidLease::~FidLease((FidLease *)local_38);
    }
  }
  pcVar2 = local_70;
  if (local_78[0] != '\0') {
    local_70 = (char *)0x0;
    if (pcVar2 != (char *)0x0) {
      ExFreePoolWithTag(pcVar2,0);
    }
  }
  return param_2;
}



===== AttemptReconnect @ 14000cfc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl p9fs::P9Client::AttemptReconnect(class p9fs::Exchange & __ptr64) __ptr64 */

void __thiscall p9fs::P9Client::AttemptReconnect(P9Client *this,Exchange *param_1)

{
  P9Client *pPVar1;
  P9Client *pPVar2;
  P9Client *pPVar3;
  undefined8 uVar4;
  code *pcVar5;
  undefined8 *puVar6;
  Exchange *pEVar7;
  undefined1 *puVar8;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  P9Client *local_18;
  undefined1 local_10;
  undefined4 uStack_f;
  undefined2 uStack_b;
  undefined1 uStack_9;
  
  pPVar1 = this + 0x70;
  local_10 = KeAcquireSpinLockRaiseToDpc(pPVar1);
  puVar8 = auStack_38;
  pPVar2 = this + 0x78;
  local_18 = pPVar1;
  pPVar3 = *(P9Client **)pPVar2;
  pEVar7 = param_1 + 0x50;
  puVar6 = *(undefined8 **)(this + 0x80);
  if ((P9Client *)*puVar6 != pPVar2) {
    pcVar5 = (code *)swi(0x29);
    puVar6 = (undefined8 *)(*pcVar5)(3);
    puVar8 = auStack_30;
  }
  *(P9Client **)pEVar7 = pPVar2;
  *(undefined8 **)(param_1 + 0x58) = puVar6;
  *puVar6 = pEVar7;
  *(Exchange **)(this + 0x80) = pEVar7;
  if (pPVar1 != (P9Client *)0x0) {
    *(undefined8 *)(puVar8 + 0x20) = *(undefined8 *)(puVar8 + 0x20);
    *(undefined8 *)(puVar8 + 0x28) = *(undefined8 *)(puVar8 + 0x28);
    *(undefined8 *)(puVar8 + -8) = 0x14000d058;
    wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)(puVar8 + 0x20));
  }
  if (pPVar3 == pPVar2) {
    pcVar5 = *(code **)(this + 0x60);
    uVar4 = *(undefined8 *)(this + 0x68);
    *(undefined8 *)(puVar8 + -8) = 0x14000d06a;
    (*pcVar5)(uVar4);
  }
  return;
}



===== CancelExchange @ 14000d08c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static void __cdecl p9fs::P9Client::CancelExchange(class p9fs::Exchange & __ptr64,long)
    */

void __cdecl p9fs::P9Client::CancelExchange(Exchange *param_1,long param_2)

{
  Exchange EVar1;
  int iVar2;
  bool bVar3;
  
  if ((param_2 != -0x3ffffee0) ||
     ((((EVar1 = param_1[0x18], EVar1 != (Exchange)0x68 && (EVar1 != (Exchange)0x6e)) &&
       (EVar1 != (Exchange)0x78)) && (EVar1 != (Exchange)0x84)))) {
    iVar2 = -0x3ffffee0;
    if (param_2 != 0x102) {
      iVar2 = param_2;
    }
    LOCK();
    bVar3 = *(int *)(param_1 + 0x60) == 0x103;
    if (bVar3) {
      *(int *)(param_1 + 0x60) = iVar2;
    }
    UNLOCK();
    if (bVar3) {
      (**(code **)(param_1 + 0x38))(iVar2,*(undefined8 *)(param_1 + 0x40));
    }
  }
  return;
}



===== CleanupExchange @ 14000d0f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl p9fs::P9Client::CleanupExchange(void * __ptr64) */

void __cdecl p9fs::P9Client::CleanupExchange(void *param_1)

{
  bool bVar1;
  void *local_res8 [4];
  
  LOCK();
  bVar1 = *(int *)((longlong)param_1 + 0x60) == 0x103;
  if (bVar1) {
    *(int *)((longlong)param_1 + 0x60) = -0x3ffffdf4;
  }
  UNLOCK();
  local_res8[0] = param_1;
  if (bVar1) {
    (**(code **)((longlong)param_1 + 0x38))(0xc000020c,*(undefined8 *)((longlong)param_1 + 0x40));
  }
  SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>((SharedPtr<p9fs::Exchange> *)local_res8);
  return;
}



===== Clunk @ 14000d134 =====

/* public: class util::BasicExpected<class p9fs::SharedPtr<class p9fs::Exchange>,long> __cdecl
   p9fs::P9Client::Clunk(unsigned int,void (__cdecl*)(void * __ptr64),void (__cdecl*)(long,void *
   __ptr64),void * __ptr64) __ptr64 */

SpanWriter * __thiscall
p9fs::P9Client::Clunk
          (P9Client *this,uint param_1,_func_void_void_ptr *param_2,
          _func_void_long_void_ptr *param_3,void *param_4)

{
  char *pcVar1;
  undefined4 in_register_00000014;
  SpanWriter *pSVar2;
  long lVar3;
  undefined7 uVar4;
  char *local_68;
  char *pcStack_60;
  P9Client *local_58;
  undefined4 local_50;
  char local_48 [8];
  char *local_40;
  char *local_38;
  char *local_30;
  char *pcStack_28;
  undefined8 local_20;
  undefined8 local_18;
  
  uVar4 = (undefined7)((ulonglong)param_3 >> 8);
  pSVar2 = (SpanWriter *)CONCAT44(in_register_00000014,param_1);
  AllocateBuffer((MessageType)local_48,CONCAT71((int7)((ulonglong)pSVar2 >> 8),0x78));
  pcVar1 = local_40;
  if (local_48[0] == '\0') {
    local_18 = 0;
    local_30 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
    lVar3 = (long)local_40;
    local_20 = 0x31c;
    pcStack_28 = "p9fs::P9Client::Clunk";
    TraceLog((ErrorSite *)&local_30,lVar3);
    *pSVar2 = (SpanWriter)0x0;
    *(long *)(pSVar2 + 8) = lVar3;
  }
  else {
    if (local_38 == (char *)0x0) {
      pcStack_60 = (char *)0x0;
    }
    else {
      if (local_38 == (char *)0xffffffffffffffff) goto LAB_14000d2ca;
      pcStack_60 = local_40;
      if (local_40 == (char *)0x0) goto LAB_14000d2ca;
    }
    local_30 = local_38;
    pcStack_28 = pcStack_60;
    if ((local_38 < (char *)0x7) || (local_38 + -7 < (char *)0x4)) {
LAB_14000d2ca:
                    /* WARNING: Subroutine does not return */
      gsl::details::terminate();
    }
    local_50 = SUB84(param_2,0);
    *(undefined4 *)(pcStack_60 + 7) = local_50;
    local_40 = (char *)0x0;
    local_68 = pcVar1;
    local_58 = this + 0x30;
    local_20 = 0xb;
    CreateExchange(this,pSVar2,(MessageType)&local_30,(FidLease *)CONCAT71(uVar4,0x78),
                   (unique_ptr<enum_gsl::byte_[0],wistd::default_delete<enum_gsl::byte_[0]>_> *)
                   &local_58,&local_68,param_3,param_4);
    FidLease::~FidLease((FidLease *)&local_58);
    if (local_68 != (char *)0x0) {
      ExFreePoolWithTag(local_68,0);
    }
  }
  pcVar1 = local_40;
  if (local_48[0] != '\0') {
    local_40 = (char *)0x0;
    if (pcVar1 != (char *)0x0) {
      ExFreePoolWithTag(pcVar1,0);
    }
  }
  return pSVar2;
}



===== Clunk @ 14000d2d8 =====

/* public: long __cdecl p9fs::P9Client::Clunk(unsigned int) __ptr64 */

long __thiscall p9fs::P9Client::Clunk(P9Client *this,uint param_1)

{
  long lVar1;
  char local_58 [8];
  Exchange *local_50;
  char *local_48;
  char *local_40;
  undefined8 local_38;
  undefined8 local_30;
  SyncContextHeader local_28 [24];
  undefined4 local_10;
  
  KeInitializeEvent(local_28,1);
  local_10 = 0;
  Clunk(this,(uint)local_58,(_func_void_void_ptr *)(ulonglong)param_1,SyncContextGenericCallback,
        SyncContextErrorCallback);
  if (local_58[0] == '\0') {
    lVar1 = (long)local_50;
    local_38 = 0x32c;
  }
  else {
    lVar1 = SendExchange(this,local_50,false);
    if (-1 < lVar1) {
      lVar1 = Wait(local_28,local_50,(ICancellationManager *)0x0);
      goto LAB_14000d3a3;
    }
    local_38 = 0x32d;
  }
  local_30 = 0;
  local_48 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
  local_40 = "p9fs::P9Client::Clunk";
  TraceLog((ErrorSite *)&local_48,lVar1);
LAB_14000d3a3:
  if (local_58[0] != '\0') {
    SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>((SharedPtr<p9fs::Exchange> *)&local_50);
  }
  return lVar1;
}



===== ClunkAsync @ 14000d3d0 =====

/* public: long __cdecl p9fs::P9Client::ClunkAsync(unsigned int) __ptr64 */

long __thiscall p9fs::P9Client::ClunkAsync(P9Client *this,uint param_1)

{
  long lVar1;
  char local_38 [8];
  Exchange *local_30;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  Clunk(this,(uint)local_38,(_func_void_void_ptr *)(ulonglong)param_1,
        <lambda_e6194d171ffda1cd05b83128a0039f97>::<lambda_invoker_cdecl><void_*>,
        <lambda_e6194d171ffda1cd05b83128a0039f97>::<lambda_invoker_cdecl><void_*>);
  if (local_38[0] == '\0') {
    lVar1 = (long)local_30;
    local_18 = 0x336;
  }
  else {
    lVar1 = SendExchange(this,local_30,false);
    if (-1 < lVar1) {
      if (local_38[0] != '\0') {
        SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>
                  ((SharedPtr<p9fs::Exchange> *)&local_30);
      }
      return 0;
    }
    local_18 = 0x337;
  }
  local_10 = 0;
  local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
  local_20 = "p9fs::P9Client::ClunkAsync";
  TraceLog((ErrorSite *)&local_28,lVar1);
  if (local_38[0] != '\0') {
    SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>((SharedPtr<p9fs::Exchange> *)&local_30);
  }
  return lVar1;
}



===== Connect @ 14000d494 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl p9fs::P9Client::Connect(struct sockaddr * __ptr64,void (__cdecl*)(void *
   __ptr64),void (__cdecl*)(long,void * __ptr64),void * __ptr64) __ptr64 */

long __thiscall
p9fs::P9Client::Connect
          (P9Client *this,sockaddr *param_1,_func_void_void_ptr *param_2,
          _func_void_long_void_ptr *param_3,void *param_4)

{
  longlong lVar1;
  long lVar2;
  int iVar3;
  void *_Dst;
  undefined8 *puVar4;
  _func_void_void_ptr *p_Var5;
  char *local_38;
  char *pcStack_30;
  undefined8 local_28;
  undefined8 local_20;
  
  p_Var5 = param_2;
  if (*(longlong *)(this + 0x30) == 0) {
    _Dst = (void *)ExAllocatePool2(0x40,0x4000,0x78523950);
    if (_Dst == (void *)0x0) {
      local_20 = 0;
      local_38 = "onecore\\vm\\inc\\DynamicArray.h";
      local_28 = 0x3d;
      pcStack_30 = "util::DynamicArray<unsigned long>::Reset";
      TraceLog((ErrorSite *)&local_38,-0x3fffff66);
      local_20 = 0;
      local_38 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\fid.cpp";
      local_28 = 0x1a;
      pcStack_30 = "p9fs::FidProvider::Initialize";
      TraceLog((ErrorSite *)&local_38,-0x3fffff66);
      local_20 = 0;
      local_38 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
      local_28 = 0x68;
      pcStack_30 = "p9fs::P9Client::Connect";
      TraceLog((ErrorSite *)&local_38,-0x3fffff66);
      return -0x3fffff66;
    }
    memset(_Dst,0,0x4000);
    lVar1 = *(longlong *)(this + 0x30);
    *(void **)(this + 0x30) = _Dst;
    if (lVar1 != 0) {
      ExFreePoolWithTag(lVar1,0);
    }
    *(undefined8 *)(this + 0x38) = 0x1000;
    p_Var5 = (_func_void_void_ptr *)0x20000;
    RtlInitializeBitMap(this + 0x40,*(undefined8 *)(this + 0x30));
  }
  lVar2 = util::DynamicArray<gsl::byte>::Reset
                    ((DynamicArray<gsl::byte> *)(this + 0x10),0x10000,(__uint64)p_Var5);
  if (lVar2 < 0) {
    local_20 = 0;
    local_38 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
    local_28 = 0x6b;
    pcStack_30 = "p9fs::P9Client::Connect";
    TraceLog((ErrorSite *)&local_38,lVar2);
    return lVar2;
  }
  if (*(longlong *)(this + 0x18) == 0) {
    pcStack_30 = (char *)0x0;
  }
  else {
    pcStack_30 = *(char **)(this + 0x10);
    if ((*(longlong *)(this + 0x18) == -1) || (pcStack_30 == (char *)0x0)) {
                    /* WARNING: Subroutine does not return */
      gsl::details::terminate();
    }
  }
  local_38 = (char *)0x0;
  *(undefined8 *)(this + 0x20) = 0;
  *(char **)(this + 0x28) = pcStack_30;
  puVar4 = operator_new(0x20);
  if (puVar4 == (undefined8 *)0x0) {
    return -0x3fffff66;
  }
  puVar4[3] = param_4;
  *puVar4 = this;
  puVar4[1] = param_2;
  puVar4[2] = param_3;
  iVar3 = (**(code **)(**(longlong **)this + 8))
                    (*(longlong **)this,param_1,
                     <lambda_885416cc7ccce8bc388436daf3235291>::<lambda_invoker_cdecl><long,void_*>,
                     puVar4);
  if (iVar3 < 0) {
    ExFreePoolWithTag(puVar4,0);
  }
  return iVar3;
}



===== CountWalkPath @ 14000d6d8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: static class util::BasicExpected<struct p9fs::P9Client::CountWalkPathResult,long>
   __cdecl p9fs::P9Client::CountWalkPath(class std::basic_string_view<unsigned short>,unsigned
   short) */

undefined1 * __cdecl
p9fs::P9Client::CountWalkPath(undefined1 *param_1,longlong *param_2,undefined2 param_3)

{
  undefined1 auVar1 [16];
  longlong lVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  short sVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined1 auStack_c8 [32];
  char local_a8 [4];
  uint local_a4;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined1 local_78 [32];
  longlong local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_c8;
  uStack_50._0_4_ = 0;
  uStack_50._4_4_ = 0;
  local_58 = 0;
  uStack_50 = 0;
  lVar2 = 0;
  if (*param_2 != 0) {
    uVar6 = (undefined4)*param_2;
    uVar7 = *(undefined4 *)((longlong)param_2 + 4);
    uVar8 = (undefined4)param_2[1];
    uVar9 = *(undefined4 *)((longlong)param_2 + 0xc);
    uStack_50._0_2_ = 0;
    sVar5 = (short)uStack_50;
    do {
      lVar2 = local_58;
      local_98 = (char *)CONCAT44(uVar7,uVar6);
      uStack_90 = (char *)CONCAT44(uVar9,uVar8);
      puVar4 = (undefined8 *)PathDissectFirst(local_78,&local_98,param_3);
      local_98 = (char *)*puVar4;
      uStack_90 = (char *)puVar4[1];
      auVar1 = *(undefined1 (*) [16])(puVar4 + 2);
      uVar6 = auVar1._0_4_;
      uVar7 = auVar1._4_4_;
      uVar8 = auVar1._8_4_;
      uVar9 = auVar1._12_4_;
      StringUnicodeToUtf8Length(local_a8,&local_98);
      uVar3 = uStack_50;
      if (local_a8[0] == '\0') {
        local_80 = 0;
        local_98 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
        local_88 = 0x650;
        uStack_90 = "p9fs::P9Client::CountWalkPath";
        TraceLog((ErrorSite *)&local_98,local_a4);
        *param_1 = 0;
        *(uint *)(param_1 + 8) = local_a4;
        return param_1;
      }
      sVar5 = sVar5 + 1;
      uStack_50 = CONCAT62(uStack_50._2_6_,sVar5);
      local_58 = lVar2 + (ulonglong)local_a4 + 2;
    } while (auVar1._0_8_ != 0);
    uStack_50._4_4_ = SUB84(uVar3,4);
    lVar2 = local_58;
  }
  *param_1 = 1;
  *(longlong *)(param_1 + 8) = lVar2;
  *(undefined4 *)(param_1 + 0x10) = (undefined4)uStack_50;
  *(undefined4 *)(param_1 + 0x14) = uStack_50._4_4_;
  return param_1;
}



===== Create @ 14000d7e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: class util::BasicExpected<struct p9fs::P9Client::OpenResult,long> __cdecl
   p9fs::P9Client::Create(unsigned int,class std::basic_string_view<unsigned short>,enum
   p9fs::OpenFlags,unsigned long,unsigned long,class p9fs::ICancellationManager * __ptr64) __ptr64
    */

undefined1 * __thiscall
p9fs::P9Client::Create
          (P9Client *this,undefined1 *param_2,undefined4 param_3,undefined8 *param_4,
          undefined4 param_5,undefined8 param_6,undefined8 param_7,ICancellationManager *param_8)

{
  long lVar1;
  undefined1 auStack_e8 [32];
  undefined4 local_c8;
  code *local_b0;
  SyncContextHeader *local_a0;
  char local_98 [8];
  Exchange *local_90;
  char *local_88;
  char *pcStack_80;
  undefined8 local_78;
  undefined8 local_70;
  SyncContextHeader local_68 [24];
  undefined4 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_e8;
  KeInitializeEvent(local_68,1);
  local_50 = 0;
  local_38 = 0;
  local_a0 = local_68;
  local_b0 = <lambda_66e576979ea43980c2067f8f9e2d60a1>::
             <lambda_invoker_cdecl><p9fs::Qid,unsigned_int,void_*>;
  local_48 = 0;
  uStack_40 = 0;
  local_c8 = param_5;
  local_88 = (char *)*param_4;
  pcStack_80 = (char *)param_4[1];
  Create(this,local_98,param_3,&local_88);
  if (local_98[0] == '\0') {
    lVar1 = (long)local_90;
    local_78 = 0x1c0;
  }
  else {
    lVar1 = WaitWithCancellation(this,local_68,local_90,param_8);
    if (-1 < lVar1) {
      *param_2 = 1;
      *(undefined8 *)(param_2 + 8) = local_48;
      *(undefined8 *)(param_2 + 0x10) = uStack_40;
      *(undefined8 *)(param_2 + 0x18) = local_38;
      goto LAB_14000d8f1;
    }
    local_78 = 0x1c1;
  }
  local_70 = 0;
  local_88 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
  pcStack_80 = "p9fs::P9Client::Create";
  TraceLog((ErrorSite *)&local_88,lVar1);
  *param_2 = 0;
  *(long *)(param_2 + 8) = lVar1;
LAB_14000d8f1:
  if (local_98[0] != '\0') {
    SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>((SharedPtr<p9fs::Exchange> *)&local_90);
  }
  return param_2;
}



===== Create @ 14000d930 =====

/* public: class util::BasicExpected<class p9fs::SharedPtr<class p9fs::Exchange>,long> __cdecl
   p9fs::P9Client::Create(unsigned int,class std::basic_string_view<unsigned short>,enum
   p9fs::OpenFlags,unsigned long,unsigned long,void (__cdecl*)(struct p9fs::Qid,unsigned int,void *
   __ptr64),void (__cdecl*)(long,void * __ptr64),void * __ptr64) __ptr64 */

SpanWriter * __thiscall
p9fs::P9Client::Create
          (P9Client *this,SpanWriter *param_2,undefined4 param_3,ulonglong *param_4,
          undefined4 param_5,undefined8 param_6,undefined8 param_7,_func_void_long_void_ptr *param_8
          )

{
  char *pcVar1;
  char *pcVar2;
  char **ppcVar3;
  long lVar4;
  undefined8 local_res20;
  char *local_68;
  char *pcStack_60;
  char local_58 [8];
  char *local_50;
  char *local_48;
  char *local_40;
  char *pcStack_38;
  char *local_30;
  undefined8 local_28;
  
  local_68 = (char *)*param_4;
  pcStack_60 = (char *)param_4[1];
  ppcVar3 = &local_68;
  StringUnicodeToUtf8Length(&local_res20,ppcVar3);
  if ((char)local_res20 == '\0') {
    local_40 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
    local_30 = (char *)0x1a5;
    pcStack_38 = "p9fs::P9Client::Create";
    local_28 = 0;
    TraceLog((ErrorSite *)&local_40,local_res20._4_4_);
    *param_2 = (SpanWriter)0x0;
    *(long *)(param_2 + 8) = local_res20._4_4_;
  }
  else {
    AllocateBuffer((MessageType)local_58,CONCAT71((int7)((ulonglong)ppcVar3 >> 8),0xe));
    if (local_58[0] == '\0') {
      local_40 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
      local_30 = (char *)0x1a7;
      lVar4 = (long)local_50;
      pcStack_38 = "p9fs::P9Client::Create";
      local_28 = 0;
      TraceLog((ErrorSite *)&local_40,lVar4);
      *param_2 = (SpanWriter)0x0;
      *(long *)(param_2 + 8) = lVar4;
    }
    else {
      if (local_48 == (char *)0x0) {
        local_68 = (char *)0x0;
        pcStack_60 = (char *)0x0;
      }
      else {
        local_68 = local_48;
        if (local_48 == (char *)0xffffffffffffffff) goto LAB_14000dbb6;
        pcStack_60 = local_50;
        if (local_50 == (char *)0x0) goto LAB_14000dbb6;
      }
      local_40 = local_68;
      pcStack_38 = pcStack_60;
      if ((local_68 < (char *)0x7) || (local_68 + -7 < (char *)0x4)) {
LAB_14000dbb6:
                    /* WARNING: Subroutine does not return */
        gsl::details::terminate();
      }
      local_68 = (char *)*param_4;
      pcVar1 = (char *)param_4[1];
      *(undefined4 *)(pcStack_60 + 7) = param_3;
      local_30 = (char *)0xb;
      pcStack_60 = pcVar1;
      SpanWriterWriteUnicodeString(&local_40,&local_68);
      if ((local_40 < local_30) || ((ulonglong)((longlong)local_40 - (longlong)local_30) < 4))
      goto LAB_14000dbb6;
      pcVar1 = local_30 + 4;
      *(undefined4 *)(pcStack_38 + (longlong)local_30) = param_5;
      if ((local_40 < pcVar1) || ((ulonglong)((longlong)local_40 - (longlong)pcVar1) < 4))
      goto LAB_14000dbb6;
      pcVar2 = local_30 + 8;
      pcVar1 = pcVar1 + (longlong)pcStack_38;
      pcVar1[0] = -0x4a;
      pcVar1[1] = '\x01';
      pcVar1[2] = '\0';
      pcVar1[3] = '\0';
      if ((local_40 < pcVar2) || ((ulonglong)((longlong)local_40 - (longlong)pcVar2) < 4))
      goto LAB_14000dbb6;
      local_30 = local_30 + 0xc;
      pcVar2 = pcStack_38 + (longlong)pcVar2;
      pcVar2[0] = '\0';
      pcVar2[1] = '\0';
      pcVar2[2] = '\0';
      pcVar2[3] = '\0';
      local_res20 = local_50;
      local_50 = (char *)0x0;
      pcStack_60 = (char *)0xffffffff;
      local_68 = (char *)0x0;
      CreateExchange(this,param_2,(MessageType)&local_40,
                     (FidLease *)CONCAT71((int7)((ulonglong)pcStack_38 >> 8),0xe),
                     (unique_ptr<enum_gsl::byte_[0],wistd::default_delete<enum_gsl::byte_[0]>_> *)
                     &local_68,&local_res20,param_8,SyncContextErrorCallback);
      FidLease::~FidLease((FidLease *)&local_68);
      if (local_res20 != (char *)0x0) {
        ExFreePoolWithTag(local_res20,0);
      }
    }
    pcVar1 = local_50;
    if (local_58[0] != '\0') {
      local_50 = (char *)0x0;
      if (pcVar1 != (char *)0x0) {
        ExFreePoolWithTag(pcVar1,0);
      }
    }
  }
  return param_2;
}



===== CreateExchange @ 14000dbc4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: class util::BasicExpected<class p9fs::SharedPtr<class p9fs::Exchange>,long> __cdecl
   p9fs::P9Client::CreateExchange(class p9fs::SpanWriter & __ptr64,enum p9fs::MessageType,class
   p9fs::FidLease && __ptr64,class wistd::unique_ptr<enum gsl::byte [0],struct
   wistd::default_delete<enum gsl::byte [0]> > && __ptr64,void * __ptr64,void (__cdecl*)(long,void *
   __ptr64),void * __ptr64) __ptr64 */

SpanWriter * __thiscall
p9fs::P9Client::CreateExchange
          (P9Client *this,SpanWriter *param_1,MessageType param_2,FidLease *param_3,
          unique_ptr<enum_gsl::byte_[0],wistd::default_delete<enum_gsl::byte_[0]>_> *param_4,
          void *param_5,_func_void_long_void_ptr *param_6,void *param_7)

{
  undefined2 uVar1;
  ulonglong *puVar2;
  ulonglong *puVar3;
  ulonglong uVar4;
  undefined4 *puVar5;
  int iVar6;
  ulonglong *puVar7;
  code *pcVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined4 in_register_00000084;
  ulonglong *puVar11;
  undefined8 *puVar12;
  ulonglong in_stack_00000048;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  ulonglong *local_48;
  ulonglong *local_40;
  char *pcStack_38;
  undefined8 local_30;
  undefined8 local_28;
  
  puVar11 = (ulonglong *)CONCAT44(in_register_00000084,param_2);
  puVar7 = operator_new(0x78);
  puVar9 = auStack_68;
  puVar10 = auStack_68;
  if (puVar7 == (ulonglong *)0x0) {
    local_48 = (ulonglong *)0x0;
    *(undefined4 *)(param_1 + 8) = 0xc000009a;
  }
  else {
    puVar2 = (ulonglong *)puVar11[2];
    puVar3 = (ulonglong *)*puVar11;
    if (puVar2 == (ulonglong *)0xffffffffffffffff) {
      puVar10 = auStack_68;
      local_40 = puVar3;
      if (puVar3 == (ulonglong *)0xffffffffffffffff) goto LAB_14000dd78;
    }
    else {
      if (puVar3 < puVar2) goto LAB_14000dd78;
      local_40 = puVar2;
    }
    pcStack_38 = (char *)puVar11[1];
    puVar7[2] = (ulonglong)this;
    *(char *)(puVar7 + 3) = (char)param_3;
    *puVar7 = (ulonglong)local_40;
    puVar7[1] = (ulonglong)pcStack_38;
    *(undefined2 *)((longlong)puVar7 + 0x1a) = 0;
    puVar7[4] = *(ulonglong *)param_4;
    *(undefined4 *)(puVar7 + 5) = *(undefined4 *)(param_4 + 8);
    *(undefined4 *)(param_4 + 8) = 0xffffffff;
    puVar7[6] = (ulonglong)param_6;
    puVar7[7] = (ulonglong)param_7;
    puVar7[8] = in_stack_00000048;
    *(undefined4 *)(puVar7 + 9) = 0;
    puVar7[10] = 0;
    puVar7[0xb] = 0;
    *(undefined4 *)(puVar7 + 0xc) = 0x103;
    uVar4 = *(ulonglong *)param_5;
    *(undefined8 *)param_5 = 0;
    puVar7[0xd] = uVar4;
    puVar7[0xe] = 1;
    puVar12 = *(undefined8 **)(this + 8);
    pcVar8 = *(code **)*puVar12;
    LOCK();
    puVar2 = puVar7 + 0xe;
    uVar4 = *puVar2;
    *puVar2 = *puVar2 + 1;
    UNLOCK();
    puVar9 = auStack_68;
    local_48 = puVar7;
    local_40 = puVar7;
    if ((longlong)(uVar4 + 1) < 2) {
      pcVar8 = (code *)swi(0x29);
      pcVar8 = (code *)(*pcVar8)(0xe);
      puVar9 = auStack_60;
    }
    *(undefined8 *)(puVar9 + -8) = 0x14000dcdc;
    iVar6 = (*pcVar8)(puVar12,&local_40);
    if (-1 < iVar6) {
      uVar1 = *(undefined2 *)((longlong)puVar7 + 0x1a);
      puVar10 = puVar9;
      if (*puVar11 < 7) {
LAB_14000dd78:
                    /* WARNING: Subroutine does not return */
        *(undefined **)(puVar10 + -8) = &UNK_14000dd7d;
        gsl::details::terminate();
      }
      puVar5 = (undefined4 *)puVar11[1];
      local_48 = (ulonglong *)0x0;
      *puVar5 = (int)puVar11[2];
      *(char *)(puVar5 + 1) = (char)param_3;
      *(undefined2 *)((longlong)puVar5 + 5) = uVar1;
      *param_1 = (SpanWriter)0x1;
      *(ulonglong **)(param_1 + 8) = puVar7;
      goto LAB_14000dd4d;
    }
    local_30 = 0x3a1;
    local_40 = (ulonglong *)0x140017be0;
    local_28 = 0;
    pcStack_38 = "p9fs::P9Client::CreateExchange";
    *(undefined8 *)(puVar9 + -8) = 0x14000dd11;
    TraceLog((ErrorSite *)&local_40,iVar6);
    *(int *)(param_1 + 8) = iVar6;
  }
  *param_1 = (SpanWriter)0x0;
LAB_14000dd4d:
  *(undefined8 *)(puVar9 + -8) = 0x14000dd56;
  SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>((SharedPtr<p9fs::Exchange> *)&local_48);
  return param_1;
}



===== FillData @ 14000dd84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl p9fs::P9Client::FillData(void) __ptr64 */

long __thiscall p9fs::P9Client::FillData(P9Client *this)

{
  size_t _Size;
  long lVar1;
  ulonglong uVar2;
  longlong lVar3;
  size_t local_18;
  longlong lStack_10;
  
  _Size = *(size_t *)(this + 0x20);
  if (_Size != 0) {
    if (*(void **)(this + 0x28) != *(void **)(this + 0x10)) {
      memmove(*(void **)(this + 0x10),*(void **)(this + 0x28),_Size);
      uVar2 = *(ulonglong *)(this + 0x18);
      if (uVar2 == 0) {
        lVar3 = 0;
        uVar2 = 0;
      }
      else {
        lVar3 = *(longlong *)(this + 0x10);
        if ((uVar2 == 0xffffffffffffffff) || (lVar3 == 0)) goto LAB_14000de8b;
      }
      if (_Size == 0xffffffffffffffff) {
        local_18 = uVar2;
        if (uVar2 == 0xffffffffffffffff) goto LAB_14000de8b;
      }
      else {
        if (uVar2 < _Size) goto LAB_14000de8b;
        local_18 = _Size;
      }
      *(size_t *)(this + 0x20) = local_18;
      *(longlong *)(this + 0x28) = lVar3;
      lStack_10 = lVar3;
    }
  }
  uVar2 = *(ulonglong *)(this + 0x18);
  if (uVar2 == 0) {
    lVar3 = 0;
    uVar2 = 0;
  }
  else {
    lVar3 = *(longlong *)(this + 0x10);
    if ((uVar2 == 0xffffffffffffffff) || (lVar3 == 0)) goto LAB_14000de8b;
  }
  if ((_Size <= uVar2) && (local_18 = uVar2 - _Size, local_18 != 0xffffffffffffffff)) {
    lStack_10 = lVar3 + _Size;
    lVar1 = (**(code **)(**(longlong **)this + 0x18))
                      (*(longlong **)this,&local_18,ReceiveCallback,this);
    return lVar1;
  }
LAB_14000de8b:
                    /* WARNING: Subroutine does not return */
  gsl::details::terminate();
}



===== FinishReconnect @ 14000de98 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl p9fs::P9Client::FinishReconnect(long) __ptr64 */

void __thiscall p9fs::P9Client::FinishReconnect(P9Client *this,long param_1)

{
  P9Client *pPVar1;
  P9Client *pPVar2;
  longlong ****pppplVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  long lVar6;
  longlong ****pppplVar7;
  bool bVar8;
  Exchange *local_res8;
  longlong ****local_38;
  longlong ****pppplStack_30;
  P9Client *local_28;
  undefined8 uStack_20;
  
  local_38 = (longlong ****)0x0;
  pppplStack_30 = (longlong ****)0x0;
  if (param_1 < 0) {
    (**(code **)(**(longlong **)this + 0x20))();
  }
  pPVar1 = this + 0x70;
  uVar5 = KeAcquireSpinLockRaiseToDpc(pPVar1);
  uVar4 = uStack_20;
  pPVar2 = this + 0x78;
  uStack_20._0_5_ = CONCAT41(uStack_20._1_4_,uVar5);
  uStack_20._5_2_ = SUB82(uVar4,5);
  uStack_20._7_1_ = SUB81(uVar4,7);
  if (*(P9Client **)pPVar2 == pPVar2) {
    pppplStack_30 = (longlong ****)&local_38;
    local_38 = (longlong ****)&local_38;
  }
  else {
    local_38 = *(longlong *****)pPVar2;
    pppplStack_30 = *(longlong *****)(this + 0x80);
    local_38[1] = (longlong ***)&local_38;
    *pppplStack_30 = (longlong ***)&local_38;
    *(P9Client **)(this + 0x80) = pPVar2;
    *(P9Client **)pPVar2 = pPVar2;
  }
  local_28 = pPVar1;
  if (pPVar1 != (P9Client *)0x0) {
    wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_28);
  }
  pppplVar7 = local_38;
  if ((longlong *****)local_38 != &local_38) {
    do {
      pppplVar3 = (longlong ****)*pppplVar7;
      local_res8 = (Exchange *)(pppplVar7 + -10);
      if (param_1 < 0) {
        LOCK();
        bVar8 = *(int *)(pppplVar7 + 2) == 0x103;
        if (bVar8) {
          *(long *)(pppplVar7 + 2) = param_1;
        }
        UNLOCK();
        lVar6 = param_1;
joined_r0x00014000dfa0:
        if (bVar8) {
          (*(code *)pppplVar7[-3])(lVar6,pppplVar7[-2]);
        }
      }
      else if ((*(int *)(pppplVar7 + 2) == 0x103) &&
              (lVar6 = SendExchange(this,local_res8,false), lVar6 < 0)) {
        LOCK();
        bVar8 = *(int *)(pppplVar7 + 2) == 0x103;
        if (bVar8) {
          *(long *)(pppplVar7 + 2) = lVar6;
        }
        UNLOCK();
        goto joined_r0x00014000dfa0;
      }
      SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>
                ((SharedPtr<p9fs::Exchange> *)&local_res8);
      pppplVar7 = pppplVar3;
    } while ((longlong *****)pppplVar3 != &local_38);
  }
  return;
}



===== Fsync @ 14000dfe0 =====

/* public: long __cdecl p9fs::P9Client::Fsync(unsigned int,class p9fs::ICancellationManager *
   __ptr64) __ptr64 */

long __thiscall p9fs::P9Client::Fsync(P9Client *this,uint param_1,ICancellationManager *param_2)

{
  char *pcVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 in_R9;
  char *local_res20;
  SpanWriter local_a8 [8];
  long local_a0;
  undefined4 uStack_9c;
  char *local_98;
  char *pcStack_90;
  char local_88 [8];
  char *local_80;
  char *local_78;
  char *local_70;
  char *pcStack_68;
  undefined8 local_60;
  undefined8 local_58;
  SyncContextHeader local_50 [24];
  undefined4 local_38;
  
  uVar3 = 0;
  KeInitializeEvent(local_50,1);
  local_38 = 0;
  AllocateBuffer((MessageType)local_88,CONCAT71((int7)((ulonglong)uVar3 >> 8),0x32));
  if (local_88[0] == '\0') {
    lVar2 = (long)local_80;
    local_70 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
    pcStack_68 = "p9fs::P9Client::Fsync";
    local_60 = 0x2ae;
    local_58 = 0;
    TraceLog((ErrorSite *)&local_70,lVar2);
    local_a8[0] = (SpanWriter)0x0;
    local_a0 = lVar2;
    if (local_88[0] != '\0') {
LAB_14000e167:
      pcVar1 = local_80;
      local_80 = (char *)0x0;
      if (pcVar1 != (char *)0x0) {
        ExFreePoolWithTag(pcVar1,0);
      }
      goto LAB_14000e182;
    }
  }
  else {
    if (local_78 == (char *)0x0) {
      local_98 = (char *)0x0;
      pcStack_90 = (char *)0x0;
    }
    else {
      local_98 = local_78;
      if ((local_78 == (char *)0xffffffffffffffff) ||
         (pcStack_90 = local_80, local_80 == (char *)0x0)) goto LAB_14000e1ef;
    }
    local_70 = local_98;
    pcStack_68 = pcStack_90;
    if ((local_98 < (char *)0x7) || (local_98 + -7 < (char *)0x4)) {
LAB_14000e1ef:
                    /* WARNING: Subroutine does not return */
      gsl::details::terminate();
    }
    *(uint *)(pcStack_90 + 7) = param_1;
    local_res20 = local_80;
    local_60 = 0xb;
    local_80 = (char *)0x0;
    pcStack_90 = (char *)0xffffffff;
    local_98 = (char *)0x0;
    CreateExchange(this,local_a8,(MessageType)&local_70,
                   (FidLease *)CONCAT71((int7)((ulonglong)in_R9 >> 8),0x32),
                   (unique_ptr<enum_gsl::byte_[0],wistd::default_delete<enum_gsl::byte_[0]>_> *)
                   &local_98,&local_res20,SyncContextGenericCallback,SyncContextErrorCallback);
    FidLease::~FidLease((FidLease *)&local_98);
    if (local_res20 != (char *)0x0) {
      ExFreePoolWithTag(local_res20,0);
    }
    if (local_88[0] != '\0') goto LAB_14000e167;
LAB_14000e182:
    if (local_a8[0] != (SpanWriter)0x0) {
      lVar2 = WaitWithCancellation(this,local_50,(Exchange *)CONCAT44(uStack_9c,local_a0),param_2);
      goto LAB_14000e1aa;
    }
  }
  lVar2 = local_a0;
  local_70 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
  pcStack_68 = "p9fs::P9Client::Fsync";
  local_60 = 0x2ba;
  local_58 = 0;
  TraceLog((ErrorSite *)&local_70,local_a0);
LAB_14000e1aa:
  if (local_a8[0] != (SpanWriter)0x0) {
    SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>((SharedPtr<p9fs::Exchange> *)&local_a0);
  }
  return lVar2;
}



===== GetAttr @ 14000e1fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: class util::BasicExpected<struct p9fs::P9Client::GetAttrResult,long> __cdecl
   p9fs::P9Client::GetAttr(unsigned int,unsigned __int64,class p9fs::ICancellationManager * __ptr64)
   __ptr64 */

undefined1 * __thiscall
p9fs::P9Client::GetAttr(P9Client *this,uint param_1,__uint64 param_2,ICancellationManager *param_3)

{
  long lVar1;
  undefined4 in_register_00000014;
  undefined1 *puVar2;
  ICancellationManager *in_stack_00000028;
  undefined1 auStackY_148 [32];
  void *in_stack_fffffffffffffee0;
  char local_108 [8];
  Exchange *local_100;
  char *local_f8;
  char *local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  SyncContextHeader local_d8 [24];
  undefined4 local_c0;
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
  ulonglong local_38;
  
  puVar2 = (undefined1 *)CONCAT44(in_register_00000014,param_1);
  local_38 = __security_cookie ^ (ulonglong)auStackY_148;
  KeInitializeEvent(local_d8);
  local_c0 = 0;
  memset(&local_b8,0,0x80);
  GetAttr(this,(uint)local_108,param_2 & 0xffffffff,
          (_func_void___uint64_Qid_StatResult_ptr_void_ptr *)param_3,
          <lambda_0edc01e6e64b501bbf8dc1ae09b4c941>::
          <lambda_invoker_cdecl><unsigned___int64,p9fs::Qid,p9fs::StatResult_const_&,void_*>,
          in_stack_fffffffffffffee0);
  if (local_108[0] == '\0') {
    lVar1 = (long)local_100;
    local_e8 = 0x24d;
  }
  else {
    lVar1 = WaitWithCancellation(this,local_d8,local_100,in_stack_00000028);
    if (-1 < lVar1) {
      *(undefined8 *)(puVar2 + 8) = local_b8;
      *(undefined8 *)(puVar2 + 0x10) = uStack_b0;
      *puVar2 = 1;
      *(undefined8 *)(puVar2 + 0x18) = local_a8;
      *(undefined8 *)(puVar2 + 0x20) = uStack_a0;
      *(undefined8 *)(puVar2 + 0x28) = local_98;
      *(undefined8 *)(puVar2 + 0x30) = uStack_90;
      *(undefined8 *)(puVar2 + 0x38) = local_88;
      *(undefined8 *)(puVar2 + 0x40) = uStack_80;
      *(undefined8 *)(puVar2 + 0x48) = local_78;
      *(undefined8 *)(puVar2 + 0x50) = uStack_70;
      *(undefined8 *)(puVar2 + 0x58) = local_68;
      *(undefined8 *)(puVar2 + 0x60) = uStack_60;
      *(undefined8 *)(puVar2 + 0x68) = local_58;
      *(undefined8 *)(puVar2 + 0x70) = uStack_50;
      *(undefined8 *)(puVar2 + 0x78) = local_48;
      *(undefined8 *)(puVar2 + 0x80) = uStack_40;
      goto LAB_14000e338;
    }
    local_e8 = 0x24e;
  }
  local_e0 = 0;
  local_f8 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
  local_f0 = "p9fs::P9Client::GetAttr";
  TraceLog((ErrorSite *)&local_f8,lVar1);
  *puVar2 = 0;
  *(long *)(puVar2 + 8) = lVar1;
LAB_14000e338:
  if (local_108[0] != '\0') {
    SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>((SharedPtr<p9fs::Exchange> *)&local_100);
  }
  return puVar2;
}



===== GetAttr @ 14000e378 =====

/* public: class util::BasicExpected<class p9fs::SharedPtr<class p9fs::Exchange>,long> __cdecl
   p9fs::P9Client::GetAttr(unsigned int,unsigned __int64,void (__cdecl*)(unsigned __int64,struct
   p9fs::Qid,struct p9fs::StatResult const & __ptr64,void * __ptr64),void (__cdecl*)(long,void *
   __ptr64),void * __ptr64) __ptr64 */

SpanWriter * __thiscall
p9fs::P9Client::GetAttr
          (P9Client *this,uint param_1,__uint64 param_2,
          _func_void___uint64_Qid_StatResult_ptr_void_ptr *param_3,_func_void_long_void_ptr *param_4
          ,void *param_5)

{
  char *pcVar1;
  char *pcVar2;
  undefined4 in_register_00000014;
  SpanWriter *pSVar3;
  long lVar4;
  undefined7 uVar5;
  undefined8 local_58;
  char *pcStack_50;
  char local_48 [8];
  char *local_40;
  char *local_38;
  char *local_30;
  char *pcStack_28;
  undefined8 local_20;
  undefined8 local_18;
  
  uVar5 = (undefined7)((ulonglong)param_3 >> 8);
  pSVar3 = (SpanWriter *)CONCAT44(in_register_00000014,param_1);
  AllocateBuffer((MessageType)local_48,CONCAT71((int7)((ulonglong)pSVar3 >> 8),0x18));
  pcVar2 = local_40;
  if (local_48[0] == '\0') {
    local_18 = 0;
    local_30 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
    lVar4 = (long)local_40;
    local_20 = 0x237;
    pcStack_28 = "p9fs::P9Client::GetAttr";
    TraceLog((ErrorSite *)&local_30,lVar4);
    *pSVar3 = (SpanWriter)0x0;
    *(long *)(pSVar3 + 8) = lVar4;
  }
  else {
    if (local_38 == (char *)0x0) {
      pcStack_50 = (char *)0x0;
    }
    else {
      if (local_38 == (char *)0xffffffffffffffff) goto LAB_14000e533;
      pcStack_50 = local_40;
      if (local_40 == (char *)0x0) goto LAB_14000e533;
    }
    pcVar1 = pcStack_50;
    local_30 = local_38;
    pcStack_28 = pcStack_50;
    if ((((local_38 < (char *)0x7) || (local_38 + -7 < (char *)0x4)) ||
        (*(int *)(pcStack_50 + 7) = (int)param_2, local_38 < (char *)0xb)) ||
       (local_38 + -0xb < (char *)0x8)) {
LAB_14000e533:
                    /* WARNING: Subroutine does not return */
      gsl::details::terminate();
    }
    local_58 = 0;
    pcStack_50 = (char *)0xffffffff;
    *(_func_void___uint64_Qid_StatResult_ptr_void_ptr **)(pcVar1 + 0xb) = param_3;
    local_40 = (char *)0x0;
    param_5 = pcVar2;
    local_20 = 0x13;
    CreateExchange(this,pSVar3,(MessageType)&local_30,(FidLease *)CONCAT71(uVar5,0x18),
                   (unique_ptr<enum_gsl::byte_[0],wistd::default_delete<enum_gsl::byte_[0]>_> *)
                   &local_58,&param_5,param_4,SyncContextErrorCallback);
    FidLease::~FidLease((FidLease *)&local_58);
    if (param_5 != (void *)0x0) {
      ExFreePoolWithTag(param_5,0);
    }
  }
  pcVar2 = local_40;
  if (local_48[0] != '\0') {
    local_40 = (char *)0x0;
    if (pcVar2 != (char *)0x0) {
      ExFreePoolWithTag(pcVar2,0);
    }
  }
  return pSVar3;
}



===== GetMessageSize @ 14000e540 =====

/* unsigned int __cdecl p9fs::GetMessageSize(enum p9fs::MessageType) */

uint __cdecl p9fs::GetMessageSize(MessageType param_1)

{
  MessageType MVar1;
  int iVar2;
  
  MVar1 = param_1 & 0xff;
  if (MVar1 < 0x47) {
    if (MVar1 == 0x46) {
      return 0x11;
    }
    if (MVar1 < 0x19) {
      if (MVar1 != 0x18) {
        if (0x10 < MVar1) {
          if (MVar1 == 0x11) {
            return 0x14;
          }
          if (MVar1 == 0x12) {
            return 0x1d;
          }
          if (MVar1 == 0x13) {
            return 0x14;
          }
          if (MVar1 == 0x14) {
            return 0x11;
          }
          if (MVar1 == 0x15) {
            return 7;
          }
          if (MVar1 == 0x16) {
            return 0xb;
          }
          if (MVar1 == 0x17) {
            return 9;
          }
          return 0;
        }
        if (MVar1 != 0x10) {
          if (MVar1 == 7) {
            return 0xb;
          }
          if (MVar1 == 8) {
            return 0xb;
          }
          if (MVar1 == 9) {
            return 0x43;
          }
          if (MVar1 == 0xc) {
            return 0xf;
          }
          if (MVar1 != 0xd) {
            if (MVar1 == 0xe) {
              return 0x19;
            }
            if (MVar1 != 0xf) {
              return 0;
            }
          }
          return 0x18;
        }
      }
      return 0x13;
    }
    if (0x28 < MVar1) {
      if (MVar1 == 0x29) {
        return 0xb;
      }
      if (MVar1 == 0x32) {
        return 0xb;
      }
      if (MVar1 == 0x33) {
        return 7;
      }
      if (MVar1 == 0x34) {
        return 0x26;
      }
      if (MVar1 == 0x35) {
        return 8;
      }
      if (MVar1 == 0x36) {
        return 0x22;
      }
      if (MVar1 == 0x37) {
        return 0x1e;
      }
      return 0;
    }
    if (MVar1 == 0x28) {
      return 0x17;
    }
    if (MVar1 == 0x19) {
      return 0xa0;
    }
    if (MVar1 == 0x1a) {
      return 0x43;
    }
    if (MVar1 == 0x1b) {
      return 7;
    }
    if (MVar1 == 0x1e) {
      return 0x11;
    }
    if (MVar1 == 0x1f) {
      return 0xf;
    }
    iVar2 = MVar1 - 0x20;
    if (iVar2 == 0) {
      return 0x19;
    }
  }
  else if (MVar1 < 0x6f) {
    if (MVar1 == 0x6e) {
      return 0x11;
    }
    if (MVar1 < 0x65) {
      if (MVar1 == 100) {
        return 0xd;
      }
      if (MVar1 == 0x47) {
        return 7;
      }
      if (MVar1 == 0x48) {
        return 0x15;
      }
      if (MVar1 == 0x49) {
        return 0x14;
      }
      if (MVar1 == 0x4a) {
        return 0x13;
      }
      if (MVar1 == 0x4b) {
        return 7;
      }
      iVar2 = MVar1 - 0x4c;
      if (iVar2 == 0) {
        return 0x11;
      }
    }
    else {
      if (MVar1 == 0x65) {
        return 0xd;
      }
      if (MVar1 == 0x66) {
        return 0x13;
      }
      if (MVar1 == 0x67) {
        return 0x14;
      }
      if (MVar1 == 0x68) {
        return 0x17;
      }
      if (MVar1 == 0x69) {
        return 0x14;
      }
      iVar2 = MVar1 - 0x6c;
      if (iVar2 == 0) {
        return 9;
      }
    }
  }
  else {
    if (0x7a < MVar1) {
      if (MVar1 == 0x7b) {
        return 7;
      }
      if (MVar1 == 0x80) {
        return 0xf;
      }
      if (MVar1 == 0x81) {
        return 7;
      }
      if (MVar1 == 0x82) {
        return 0x17;
      }
      if (MVar1 == 0x83) {
        return 0xb;
      }
      if (MVar1 == 0x84) {
        return 0x29;
      }
      if (MVar1 == 0x85) {
        return 0xa1;
      }
      return 0;
    }
    if (MVar1 == 0x7a) {
      return 0xb;
    }
    if (MVar1 == 0x6f) {
      return 9;
    }
    if (MVar1 == 0x74) {
      return 0x17;
    }
    if (MVar1 == 0x75) {
      return 0xb;
    }
    if (MVar1 == 0x76) {
      return 0x17;
    }
    if (MVar1 == 0x77) {
      return 0xb;
    }
    iVar2 = MVar1 - 0x78;
    if (iVar2 == 0) {
      return 0xb;
    }
  }
  if (iVar2 == 1) {
    return 7;
  }
  return 0;
}



===== HandleIoError @ 14000e794 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl p9fs::P9Client::HandleIoError(void) __ptr64 */

void __thiscall p9fs::P9Client::HandleIoError(P9Client *this)

{
  (**(code **)(**(longlong **)this + 0x20))();
  (**(code **)(**(longlong **)(this + 8) + 0x10))(*(longlong **)(this + 8),CleanupExchange);
  return;
}



===== HandleReply @ 14000e7d0 =====

/* private: void __cdecl p9fs::P9Client::HandleReply(void) __ptr64 */

void __thiscall p9fs::P9Client::HandleReply(P9Client *this)

{
  undefined1 uVar1;
  ushort uVar2;
  ulonglong uVar3;
  long lVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong local_98;
  longlong lStack_90;
  undefined8 local_88;
  ulonglong local_80;
  longlong lStack_78;
  ulonglong local_70;
  longlong lStack_68;
  longlong local_60;
  longlong lStack_58;
  undefined1 local_50 [8];
  uint *local_48;
  undefined1 local_40 [8];
  undefined1 *local_38;
  undefined1 local_30 [8];
  ushort *local_28;
  ulonglong local_20;
  longlong lStack_18;
  undefined8 local_10;
  
  uVar5 = *(ulonglong *)(this + 0x20);
  while (6 < uVar5) {
    if (uVar5 == 0xffffffffffffffff) {
LAB_14000e94b:
                    /* WARNING: Subroutine does not return */
      gsl::details::terminate();
    }
    lStack_78 = *(longlong *)(this + 0x28);
    local_80 = uVar5;
    if ((lStack_78 == 0) && (uVar5 != 0)) goto LAB_14000e94b;
    local_88 = 0;
    local_98 = uVar5;
    lStack_90 = lStack_78;
    SpanReader::Read((SpanReader *)&local_98,(uint)local_50);
    uVar6 = *local_48;
    uVar5 = (ulonglong)uVar6;
    if (*(ulonglong *)(this + 0x18) < uVar5) goto LAB_14000e925;
    if (*(ulonglong *)(this + 0x20) < uVar5) break;
    SpanReader::Read((SpanReader *)&local_98,(uint)local_40);
    uVar1 = *local_38;
    SpanReader::Read((SpanReader *)&local_98,(uint)local_30);
    uVar6 = uVar6 - 7;
    uVar7 = (ulonglong)uVar6;
    uVar3 = *(ulonglong *)(this + 0x20);
    uVar2 = *local_28;
    if ((uVar3 < 7) || (uVar3 - 7 < uVar7)) goto LAB_14000e94b;
    lStack_68 = *(longlong *)(this + 0x28) + 7;
    local_70 = uVar7;
    if ((lStack_68 == 0) && (uVar7 != 0)) goto LAB_14000e94b;
    local_10 = 0;
    local_20 = uVar7;
    lStack_18 = lStack_68;
    if ((uVar3 < uVar5) || (local_60 = uVar3 - uVar5, local_60 == -1)) goto LAB_14000e94b;
    lStack_58 = *(longlong *)(this + 0x28) + uVar5;
    *(longlong *)(this + 0x20) = local_60;
    *(longlong *)(this + 0x28) = lStack_58;
    ProcessReply(this,CONCAT31((int3)(uVar6 >> 8),uVar1),uVar2,(SpanReader *)&local_20);
    uVar5 = *(ulonglong *)(this + 0x20);
  }
  lVar4 = FillData(this);
  if (lVar4 < 0) {
LAB_14000e925:
    HandleIoError(this);
  }
  return;
}



===== MkDir @ 14000e958 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: class util::BasicExpected<struct p9fs::Qid,long> __cdecl p9fs::P9Client::MkDir(unsigned
   int,class std::basic_string_view<unsigned short>,unsigned long,unsigned long,class
   p9fs::ICancellationManager * __ptr64) __ptr64 */

undefined1 * __thiscall
p9fs::P9Client::MkDir
          (P9Client *this,undefined1 *param_2,undefined4 param_3,undefined8 *param_4,
          undefined8 param_5,undefined8 param_6,ICancellationManager *param_7)

{
  long lVar1;
  undefined1 auStack_e8 [48];
  code *local_b8;
  SyncContextHeader *local_a8;
  char local_98 [8];
  Exchange *local_90;
  char *local_88;
  char *pcStack_80;
  undefined8 local_78;
  undefined8 local_70;
  SyncContextHeader local_68 [24];
  undefined4 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_e8;
  KeInitializeEvent(local_68,1);
  local_88 = (char *)*param_4;
  pcStack_80 = (char *)param_4[1];
  local_a8 = local_68;
  local_50 = 0;
  local_b8 = <lambda_cb63b31bc136f3dc874582943a742327>::<lambda_invoker_cdecl><p9fs::Qid,void_*>;
  local_48 = 0;
  uStack_40 = 0;
  MkDir(this,local_98,param_3,&local_88);
  if (local_98[0] == '\0') {
    lVar1 = (long)local_90;
    local_78 = 0x1e3;
  }
  else {
    lVar1 = WaitWithCancellation(this,local_68,local_90,param_7);
    if (-1 < lVar1) {
      *param_2 = 1;
      *(undefined8 *)(param_2 + 8) = local_48;
      *(undefined8 *)(param_2 + 0x10) = uStack_40;
      goto LAB_14000ea4f;
    }
    local_78 = 0x1e4;
  }
  local_70 = 0;
  local_88 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
  pcStack_80 = "p9fs::P9Client::MkDir";
  TraceLog((ErrorSite *)&local_88,lVar1);
  *param_2 = 0;
  *(long *)(param_2 + 8) = lVar1;
LAB_14000ea4f:
  if (local_98[0] != '\0') {
    SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>((SharedPtr<p9fs::Exchange> *)&local_90);
  }
  return param_2;
}



===== MkDir @ 14000ea8c =====

/* public: class util::BasicExpected<class p9fs::SharedPtr<class p9fs::Exchange>,long> __cdecl
   p9fs::P9Client::MkDir(unsigned int,class std::basic_string_view<unsigned short>,unsigned
   long,unsigned long,void (__cdecl*)(struct p9fs::Qid,void * __ptr64),void (__cdecl*)(long,void *
   __ptr64),void * __ptr64) __ptr64 */

SpanWriter * __thiscall
p9fs::P9Client::MkDir
          (P9Client *this,SpanWriter *param_2,undefined4 param_3,ulonglong *param_4,
          undefined8 param_5,undefined8 param_6,_func_void_long_void_ptr *param_7)

{
  char *pcVar1;
  char *pcVar2;
  char **ppcVar3;
  long lVar4;
  undefined8 local_res20;
  char *local_68;
  char *pcStack_60;
  char local_58 [8];
  char *local_50;
  char *local_48;
  char *local_40;
  char *pcStack_38;
  char *local_30;
  undefined8 local_28;
  
  local_68 = (char *)*param_4;
  pcStack_60 = (char *)param_4[1];
  ppcVar3 = &local_68;
  StringUnicodeToUtf8Length(&local_res20,ppcVar3);
  if ((char)local_res20 == '\0') {
    local_40 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
    local_30 = (char *)0x1ca;
    pcStack_38 = "p9fs::P9Client::MkDir";
    local_28 = 0;
    TraceLog((ErrorSite *)&local_40,local_res20._4_4_);
    *param_2 = (SpanWriter)0x0;
    *(long *)(param_2 + 8) = local_res20._4_4_;
  }
  else {
    AllocateBuffer((MessageType)local_58,CONCAT71((int7)((ulonglong)ppcVar3 >> 8),0x48));
    if (local_58[0] == '\0') {
      local_40 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
      local_30 = (char *)0x1cc;
      lVar4 = (long)local_50;
      pcStack_38 = "p9fs::P9Client::MkDir";
      local_28 = 0;
      TraceLog((ErrorSite *)&local_40,lVar4);
      *param_2 = (SpanWriter)0x0;
      *(long *)(param_2 + 8) = lVar4;
    }
    else {
      if (local_48 == (char *)0x0) {
        local_68 = (char *)0x0;
        pcStack_60 = (char *)0x0;
      }
      else {
        local_68 = local_48;
        if (local_48 == (char *)0xffffffffffffffff) goto LAB_14000ecee;
        pcStack_60 = local_50;
        if (local_50 == (char *)0x0) goto LAB_14000ecee;
      }
      local_40 = local_68;
      pcStack_38 = pcStack_60;
      if ((local_68 < (char *)0x7) || (local_68 + -7 < (char *)0x4)) {
LAB_14000ecee:
                    /* WARNING: Subroutine does not return */
        gsl::details::terminate();
      }
      local_68 = (char *)*param_4;
      pcVar1 = (char *)param_4[1];
      *(undefined4 *)(pcStack_60 + 7) = param_3;
      local_30 = (char *)0xb;
      pcStack_60 = pcVar1;
      SpanWriterWriteUnicodeString(&local_40,&local_68);
      if ((local_40 < local_30) || ((ulonglong)((longlong)local_40 - (longlong)local_30) < 4))
      goto LAB_14000ecee;
      pcVar1 = local_30 + 4;
      pcVar2 = pcStack_38 + (longlong)local_30;
      pcVar2[0] = -1;
      pcVar2[1] = '\x01';
      pcVar2[2] = '\0';
      pcVar2[3] = '\0';
      if ((local_40 < pcVar1) || ((ulonglong)((longlong)local_40 - (longlong)pcVar1) < 4))
      goto LAB_14000ecee;
      local_30 = local_30 + 8;
      pcVar1 = pcVar1 + (longlong)pcStack_38;
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      pcVar1[2] = '\0';
      pcVar1[3] = '\0';
      local_res20 = local_50;
      local_50 = (char *)0x0;
      pcStack_60 = (char *)0xffffffff;
      local_68 = (char *)0x0;
      CreateExchange(this,param_2,(MessageType)&local_40,
                     (FidLease *)CONCAT71((int7)((ulonglong)pcStack_38 >> 8),0x48),
                     (unique_ptr<enum_gsl::byte_[0],wistd::default_delete<enum_gsl::byte_[0]>_> *)
                     &local_68,&local_res20,param_7,SyncContextErrorCallback);
      FidLease::~FidLease((FidLease *)&local_68);
      if (local_res20 != (char *)0x0) {
        ExFreePoolWithTag(local_res20,0);
      }
    }
    pcVar1 = local_50;
    if (local_58[0] != '\0') {
      local_50 = (char *)0x0;
      if (pcVar1 != (char *)0x0) {
        ExFreePoolWithTag(pcVar1,0);
      }
    }
  }
  return param_2;
}



===== Negotiate @ 14000ecfc =====

/* private: class util::BasicExpected<class p9fs::SharedPtr<class p9fs::Exchange>,long> __cdecl
   p9fs::P9Client::Negotiate(unsigned int,class std::basic_string_view<char>,void (__cdecl*)(void *
   __ptr64),void (__cdecl*)(long,void * __ptr64),void * __ptr64) __ptr64 */

SpanWriter * __thiscall
p9fs::P9Client::Negotiate
          (P9Client *this,SpanWriter *param_2,undefined8 param_3,undefined8 *param_4,
          _func_void_long_void_ptr *param_5,void *param_6)

{
  undefined8 uVar1;
  char *pcVar2;
  long lVar3;
  undefined7 uVar4;
  char *local_res20;
  undefined8 local_58;
  char *pcStack_50;
  char local_48 [8];
  char *local_40;
  char *local_38;
  char *local_30;
  char *pcStack_28;
  undefined8 local_20;
  undefined8 local_18;
  
  uVar4 = (undefined7)((ulonglong)param_4 >> 8);
  AllocateBuffer((MessageType)local_48,CONCAT71((int7)((ulonglong)param_2 >> 8),100));
  if (local_48[0] == '\0') {
    local_18 = 0;
    local_30 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
    lVar3 = (long)local_40;
    local_20 = 0x3c8;
    pcStack_28 = "p9fs::P9Client::Negotiate";
    TraceLog((ErrorSite *)&local_30,lVar3);
    *param_2 = (SpanWriter)0x0;
    *(long *)(param_2 + 8) = lVar3;
  }
  else {
    if (local_38 == (char *)0x0) {
      pcStack_50 = (char *)0x0;
    }
    else {
      if (local_38 == (char *)0xffffffffffffffff) goto LAB_14000eea6;
      pcStack_50 = local_40;
      if (local_40 == (char *)0x0) goto LAB_14000eea6;
    }
    local_30 = local_38;
    pcStack_28 = pcStack_50;
    if ((local_38 < (char *)0x7) || (local_38 + -7 < (char *)0x4)) {
LAB_14000eea6:
                    /* WARNING: Subroutine does not return */
      gsl::details::terminate();
    }
    local_58 = *param_4;
    uVar1 = param_4[1];
    pcStack_50[7] = '\0';
    pcStack_50[8] = '\0';
    pcStack_50[9] = '\x01';
    pcStack_50[10] = '\0';
    local_20 = 0xb;
    pcStack_50 = (char *)uVar1;
    SpanWriter::String((SpanWriter *)&local_30,&local_58);
    local_res20 = local_40;
    local_40 = (char *)0x0;
    local_58 = 0;
    pcStack_50 = (char *)0xffffffff;
    CreateExchange(this,param_2,(MessageType)&local_30,(FidLease *)CONCAT71(uVar4,100),
                   (unique_ptr<enum_gsl::byte_[0],wistd::default_delete<enum_gsl::byte_[0]>_> *)
                   &local_58,&local_res20,param_5,param_6);
    FidLease::~FidLease((FidLease *)&local_58);
    if (local_res20 != (char *)0x0) {
      ExFreePoolWithTag(local_res20,0);
    }
  }
  pcVar2 = local_40;
  if (local_48[0] != '\0') {
    local_40 = (char *)0x0;
    if (pcVar2 != (char *)0x0) {
      ExFreePoolWithTag(pcVar2,0);
    }
  }
  return param_2;
}



===== Open @ 14000eeb4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: class util::BasicExpected<struct p9fs::P9Client::OpenResult,long> __cdecl
   p9fs::P9Client::Open(unsigned int,enum p9fs::OpenFlags,class p9fs::ICancellationManager *
   __ptr64) __ptr64 */

undefined1 * __thiscall
p9fs::P9Client::Open(P9Client *this,uint param_1,OpenFlags param_2,ICancellationManager *param_3)

{
  long lVar1;
  undefined4 in_register_00000014;
  undefined1 *puVar2;
  ICancellationManager *in_stack_00000028;
  undefined1 auStackY_d8 [32];
  void *in_stack_ffffffffffffff50;
  char local_98 [8];
  Exchange *local_90;
  char *local_88;
  char *local_80;
  undefined8 local_78;
  undefined8 local_70;
  SyncContextHeader local_68 [24];
  undefined4 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  puVar2 = (undefined1 *)CONCAT44(in_register_00000014,param_1);
  local_30 = __security_cookie ^ (ulonglong)auStackY_d8;
  KeInitializeEvent(local_68,1);
  local_50 = 0;
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  Open(this,(uint)local_98,param_2,(_func_void_Qid_uint_void_ptr *)((ulonglong)param_3 & 0xffffffff)
       ,<lambda_66e576979ea43980c2067f8f9e2d60a1>::
        <lambda_invoker_cdecl><p9fs::Qid,unsigned_int,void_*>,in_stack_ffffffffffffff50);
  if (local_98[0] == '\0') {
    lVar1 = (long)local_90;
    local_78 = 0x19b;
  }
  else {
    lVar1 = WaitWithCancellation(this,local_68,local_90,in_stack_00000028);
    if (-1 < lVar1) {
      *puVar2 = 1;
      *(undefined8 *)(puVar2 + 8) = local_48;
      *(undefined8 *)(puVar2 + 0x10) = uStack_40;
      *(undefined8 *)(puVar2 + 0x18) = local_38;
      goto LAB_14000efb1;
    }
    local_78 = 0x19c;
  }
  local_70 = 0;
  local_88 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
  local_80 = "p9fs::P9Client::Open";
  TraceLog((ErrorSite *)&local_88,lVar1);
  *puVar2 = 0;
  *(long *)(puVar2 + 8) = lVar1;
LAB_14000efb1:
  if (local_98[0] != '\0') {
    SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>((SharedPtr<p9fs::Exchange> *)&local_90);
  }
  return puVar2;
}



===== Open @ 14000eff0 =====

/* public: class util::BasicExpected<class p9fs::SharedPtr<class p9fs::Exchange>,long> __cdecl
   p9fs::P9Client::Open(unsigned int,enum p9fs::OpenFlags,void (__cdecl*)(struct p9fs::Qid,unsigned
   int,void * __ptr64),void (__cdecl*)(long,void * __ptr64),void * __ptr64) __ptr64 */

SpanWriter * __thiscall
p9fs::P9Client::Open
          (P9Client *this,uint param_1,OpenFlags param_2,_func_void_Qid_uint_void_ptr *param_3,
          _func_void_long_void_ptr *param_4,void *param_5)

{
  char *pcVar1;
  char *pcVar2;
  undefined4 in_register_00000014;
  SpanWriter *pSVar3;
  long lVar4;
  undefined4 uVar5;
  undefined8 local_58;
  char *pcStack_50;
  char local_48 [8];
  char *local_40;
  char *local_38;
  char *local_30;
  char *pcStack_28;
  undefined8 local_20;
  undefined8 local_18;
  
  uVar5 = SUB84(param_3,0);
  pSVar3 = (SpanWriter *)CONCAT44(in_register_00000014,param_1);
  AllocateBuffer((MessageType)local_48,CONCAT71((int7)((ulonglong)pSVar3 >> 8),0xc));
  pcVar2 = local_40;
  if (local_48[0] == '\0') {
    local_18 = 0;
    local_30 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
    lVar4 = (long)local_40;
    local_20 = 0x186;
    pcStack_28 = "p9fs::P9Client::Open";
    TraceLog((ErrorSite *)&local_30,lVar4);
    *pSVar3 = (SpanWriter)0x0;
    *(long *)(pSVar3 + 8) = lVar4;
  }
  else {
    if (local_38 == (char *)0x0) {
      pcStack_50 = (char *)0x0;
    }
    else {
      if (local_38 == (char *)0xffffffffffffffff) goto LAB_14000f1aa;
      pcStack_50 = local_40;
      if (local_40 == (char *)0x0) goto LAB_14000f1aa;
    }
    pcVar1 = pcStack_50;
    local_30 = local_38;
    pcStack_28 = pcStack_50;
    if ((((local_38 < (char *)0x7) || (local_38 + -7 < (char *)0x4)) ||
        (*(OpenFlags *)(pcStack_50 + 7) = param_2, local_38 < (char *)0xb)) ||
       (local_38 + -0xb < (char *)0x4)) {
LAB_14000f1aa:
                    /* WARNING: Subroutine does not return */
      gsl::details::terminate();
    }
    local_58 = 0;
    pcStack_50 = (char *)0xffffffff;
    *(undefined4 *)(pcVar1 + 0xb) = uVar5;
    local_40 = (char *)0x0;
    param_5 = pcVar2;
    local_20 = 0xf;
    CreateExchange(this,pSVar3,(MessageType)&local_30,
                   (FidLease *)
                   CONCAT44((int)((ulonglong)param_3 >> 0x20),
                            CONCAT31((int3)((ulonglong)param_3 >> 8),0xc)),
                   (unique_ptr<enum_gsl::byte_[0],wistd::default_delete<enum_gsl::byte_[0]>_> *)
                   &local_58,&param_5,param_4,SyncContextErrorCallback);
    FidLease::~FidLease((FidLease *)&local_58);
    if (param_5 != (void *)0x0) {
      ExFreePoolWithTag(param_5,0);
    }
  }
  pcVar2 = local_40;
  if (local_48[0] != '\0') {
    local_40 = (char *)0x0;
    if (pcVar2 != (char *)0x0) {
      ExFreePoolWithTag(pcVar2,0);
    }
  }
  return pSVar3;
}



===== ProcessGetAttrReply @ 14000f1b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl p9fs::P9Client::ProcessGetAttrReply(class p9fs::Exchange & __ptr64,class
   p9fs::SpanReader & __ptr64) __ptr64 */

void __thiscall
p9fs::P9Client::ProcessGetAttrReply(P9Client *this,Exchange *param_1,SpanReader *param_2)

{
  undefined8 uVar1;
  undefined1 auStack_c8 [48];
  undefined1 local_98 [8];
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined1 local_88 [112];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_c8;
  SpanReader::Read(param_2,(uint)local_98);
  uVar1 = *(undefined8 *)CONCAT44(uStack_8c,uStack_90);
  SpanReader::Qid(param_2);
  SpanReader::ReadStatResult(param_2);
  (**(code **)(param_1 + 0x30))(uVar1,local_98,local_88,*(undefined8 *)(param_1 + 0x40));
  return;
}



===== ProcessReadReply @ 14000f268 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl p9fs::P9Client::ProcessReadReply(class p9fs::Exchange & __ptr64,class
   p9fs::SpanReader & __ptr64) __ptr64 */

void __thiscall
p9fs::P9Client::ProcessReadReply(P9Client *this,Exchange *param_1,SpanReader *param_2)

{
  ulonglong uVar1;
  bool bVar2;
  ulonglong local_28;
  uint *puStack_20;
  ulonglong local_18;
  
  SpanReader::Read(param_2,(uint)&local_28);
  uVar1 = *(ulonglong *)(param_2 + 0x10);
  local_28 = (ulonglong)*puStack_20;
  if (*(ulonglong *)param_2 - uVar1 < local_28) {
    local_28 = 0;
    puStack_20 = (uint *)0x0;
    local_18 = 0;
    bVar2 = false;
  }
  else {
    if (*(ulonglong *)param_2 < uVar1) {
                    /* WARNING: Subroutine does not return */
      gsl::details::terminate();
    }
    puStack_20 = (uint *)(*(longlong *)(param_2 + 8) + uVar1);
    *(ulonglong *)(param_2 + 0x10) = local_28 + uVar1;
    bVar2 = true;
    local_18 = (ulonglong)(byte)local_18;
  }
  if (bVar2) {
    (**(code **)(param_1 + 0x30))(&local_28,*(undefined8 *)(param_1 + 0x40));
  }
  else {
    (**(code **)(param_1 + 0x38))(0xc0000186);
  }
  return;
}



===== ProcessReply @ 14000f340 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl p9fs::P9Client::ProcessReply(enum p9fs::MessageType,unsigned short,class
   p9fs::SpanReader & __ptr64) __ptr64 */

void __thiscall
p9fs::P9Client::ProcessReply(P9Client *this,MessageType param_1,ushort param_2,SpanReader *param_3)

{
  Exchange *pEVar1;
  longlong lVar2;
  Exchange EVar3;
  int iVar4;
  uint uVar5;
  code *pcVar6;
  undefined4 uVar7;
  longlong *plVar8;
  undefined8 uVar9;
  char cVar10;
  undefined1 *puVar11;
  byte bVar12;
  bool bVar13;
  undefined4 local_res8 [2];
  undefined1 auStack_98 [8];
  undefined1 auStack_90 [24];
  Exchange *local_78;
  char local_70 [8];
  Exchange *local_68 [2];
  undefined1 local_58 [8];
  undefined4 uStack_50;
  undefined4 uStack_4c;
  char *local_48;
  char *pcStack_40;
  undefined8 local_38;
  char *local_30;
  
  plVar8 = *(longlong **)(this + 8);
  cVar10 = (char)param_1;
  (**(code **)(*plVar8 + 8))(plVar8,local_70,param_2);
  if (local_70[0] == '\0') {
    local_38 = 0x40b;
    local_48 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
    pcStack_40 = "p9fs::P9Client::ProcessReply";
    local_30 = "P9: Server responded to unknown tag %d.\n";
    TraceLog((ErrorSite *)&local_48,-0x3fffffff,param_2);
    puVar11 = auStack_98;
    goto LAB_14000f68e;
  }
  bVar12 = 1;
  local_78 = local_68[0];
  puVar11 = auStack_98;
  if (local_68[0] != (Exchange *)0x0) {
    LOCK();
    pEVar1 = local_68[0] + 0x70;
    lVar2 = *(longlong *)pEVar1;
    *(longlong *)pEVar1 = *(longlong *)pEVar1 + 1;
    UNLOCK();
    puVar11 = auStack_98;
    if (lVar2 + 1 < 2) {
      plVar8 = (longlong *)0x0;
      pcVar6 = (code *)swi(0x29);
      bVar12 = 1;
      (*pcVar6)(0xe);
      puVar11 = auStack_90;
    }
  }
  LOCK();
  bVar13 = *(int *)(local_68[0] + 0x60) == 0x103;
  if (bVar13) {
    *(int *)(local_68[0] + 0x60) = 0;
  }
  UNLOCK();
  if (!bVar13) {
    if (((*(int *)(local_78 + 0x28) != -1) && (local_78[0x18] != (Exchange)0x78)) &&
       (bVar12 < (byte)(cVar10 - 6U))) {
      uVar5 = *(uint *)(local_78 + 0x28);
      *(undefined4 *)(local_78 + 0x28) = 0xffffffff;
      *(undefined8 *)(puVar11 + -8) = 0x14000f432;
      ClunkAsync(this,uVar5);
    }
    goto LAB_14000f685;
  }
  *(undefined8 *)(puVar11 + -8) = 0x14000f43f;
  uVar5 = GetMessageSize((MessageType)CONCAT71((int7)((ulonglong)plVar8 >> 8),cVar10));
  pEVar1 = local_78;
  if (*(longlong *)param_3 + 7U < (ulonglong)uVar5) {
    pcVar6 = *(code **)(local_78 + 0x38);
    uVar9 = *(undefined8 *)(local_78 + 0x40);
LAB_14000f5f4:
    uVar7 = 0xc0000186;
LAB_14000f644:
    *(undefined8 *)(puVar11 + -8) = 0x14000f649;
    (*pcVar6)(uVar7,uVar9);
  }
  else {
    EVar3 = local_78[0x18];
    if ((byte)EVar3 + 1 != (param_1 & 0xff)) {
      if (bVar12 < (byte)(cVar10 - 6U)) {
        uVar7 = 0xc0000186;
      }
      else {
        *(undefined8 *)(puVar11 + -8) = 0x14000f490;
        SpanReader::Read(param_3,(uint)local_58);
        local_res8[0] = 0;
        iVar4 = *(int *)CONCAT44(uStack_4c,uStack_50);
        if (iVar4 == 0x5f) {
          uVar7 = 0xc0000463;
        }
        else {
          *(undefined8 *)(puVar11 + -8) = 0x14000f4b1;
          LxUtilLxErrorToNtStatus(-iVar4,local_res8);
          uVar7 = local_res8[0];
        }
      }
      uVar9 = *(undefined8 *)(pEVar1 + 0x40);
      pcVar6 = *(code **)(pEVar1 + 0x38);
      goto LAB_14000f644;
    }
    if ((byte)EVar3 < 0x65) {
      if (EVar3 == (Exchange)0x64) {
        *(undefined8 *)(puVar11 + -8) = 0x14000f5b2;
        ProcessVersionReply(this,local_78,param_3);
      }
      else if (EVar3 == (Exchange)0x8) {
        *(undefined8 *)(puVar11 + -8) = 0x14000f59f;
        ProcessStatFsReply((P9Client *)0x9,local_78,param_3);
      }
      else if (((byte)EVar3 - 0xc & 0xfffffffd) == 0) {
        *(undefined8 *)(puVar11 + -8) = 0x14000f55d;
        SpanReader::Qid(param_3);
        *(undefined8 *)(puVar11 + -8) = 0x14000f56f;
        SpanReader::Read(param_3,(uint)&local_48);
        pcVar6 = *(code **)(pEVar1 + 0x30);
        uVar9 = *(undefined8 *)(pEVar1 + 0x40);
        uVar7 = *(undefined4 *)pcStack_40;
        *(undefined8 *)(puVar11 + -8) = 0x14000f58f;
        (*pcVar6)(local_58,uVar7,uVar9);
      }
      else {
        if (EVar3 != (Exchange)0x14) {
          if (EVar3 == (Exchange)0x18) {
            *(undefined8 *)(puVar11 + -8) = 0x14000f54c;
            ProcessGetAttrReply((P9Client *)0x19,local_78,param_3);
            goto LAB_14000f685;
          }
          if (EVar3 != (Exchange)0x1a) {
            if (EVar3 == (Exchange)0x28) goto LAB_14000f608;
            if (EVar3 != (Exchange)0x32) {
              if (EVar3 != (Exchange)0x48) goto LAB_14000f5ec;
              *(undefined8 *)(puVar11 + -8) = 0x14000f515;
              SpanReader::Qid(param_3);
              pcVar6 = *(code **)(pEVar1 + 0x30);
              uVar9 = *(undefined8 *)(pEVar1 + 0x40);
              *(undefined8 *)(puVar11 + -8) = 0x14000f52f;
              (*pcVar6)(local_58,uVar9);
              goto LAB_14000f685;
            }
          }
        }
        pcVar6 = *(code **)(local_78 + 0x30);
        uVar9 = *(undefined8 *)(local_78 + 0x40);
LAB_14000f61d:
        *(undefined8 *)(puVar11 + -8) = 0x14000f622;
        (*pcVar6)(uVar9);
      }
    }
    else if (EVar3 == (Exchange)0x68) {
      *(undefined8 *)(puVar11 + -8) = 0x14000f664;
      SpanReader::Qid(param_3);
      pcVar6 = *(code **)(local_68[0] + 0x30);
      uVar9 = *(undefined8 *)(local_68[0] + 0x40);
      uVar7 = *(undefined4 *)(local_68[0] + 0x28);
      *(undefined4 *)(local_68[0] + 0x28) = 0xffffffff;
      *(undefined8 *)(puVar11 + -8) = 0x14000f685;
      (*pcVar6)(uVar7,&local_48,uVar9);
    }
    else if (EVar3 == (Exchange)0x6e) {
      *(undefined8 *)(puVar11 + -8) = 0x14000f656;
      ProcessWalkReply((P9Client *)0x6f,local_78,param_3);
    }
    else {
      if (EVar3 != (Exchange)0x74) {
        if (EVar3 == (Exchange)0x76) {
          *(undefined8 *)(puVar11 + -8) = 0x14000f636;
          SpanReader::Read(param_3,(uint)&local_48);
          pcVar6 = *(code **)(local_68[0] + 0x30);
          uVar9 = *(undefined8 *)(local_68[0] + 0x40);
          uVar7 = *(undefined4 *)pcStack_40;
          goto LAB_14000f644;
        }
        if (((EVar3 != (Exchange)0x78) && (EVar3 != (Exchange)0x7a)) && (EVar3 != (Exchange)0x80)) {
          if (EVar3 != (Exchange)0x82) {
            if (EVar3 != (Exchange)0x84) {
LAB_14000f5ec:
              pcVar6 = *(code **)(local_78 + 0x38);
              uVar9 = *(undefined8 *)(local_78 + 0x40);
              goto LAB_14000f5f4;
            }
            *(undefined8 *)(puVar11 + -8) = 0x14000f606;
            ProcessWOpenReply((P9Client *)0x85,local_78,param_3);
            goto LAB_14000f685;
          }
          goto LAB_14000f608;
        }
        pcVar6 = *(code **)(local_68[0] + 0x30);
        uVar9 = *(undefined8 *)(local_68[0] + 0x40);
        goto LAB_14000f61d;
      }
LAB_14000f608:
      *(undefined8 *)(puVar11 + -8) = 0x14000f613;
      ProcessReadReply((P9Client *)(ulonglong)((byte)EVar3 + 1),local_78,param_3);
    }
  }
LAB_14000f685:
  *(undefined8 *)(puVar11 + -8) = 0x14000f68e;
  SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>((SharedPtr<p9fs::Exchange> *)&local_78);
LAB_14000f68e:
  if (local_70[0] != '\0') {
    *(undefined8 *)(puVar11 + -8) = 0x14000f69d;
    SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>((SharedPtr<p9fs::Exchange> *)local_68);
  }
  return;
}



===== ProcessStatFsReply @ 14000f6c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl p9fs::P9Client::ProcessStatFsReply(class p9fs::Exchange & __ptr64,class
   p9fs::SpanReader & __ptr64) __ptr64 */

void __thiscall
p9fs::P9Client::ProcessStatFsReply(P9Client *this,Exchange *param_1,SpanReader *param_2)

{
  undefined1 auStack_98 [32];
  undefined1 local_78 [8];
  undefined8 *local_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_98;
  local_2c = 0;
  SpanReader::Read(param_2,(uint)local_78);
  local_68 = *(undefined4 *)local_70;
  SpanReader::Read(param_2,(uint)local_78);
  local_64 = *(undefined4 *)local_70;
  SpanReader::Read(param_2,(uint)local_78);
  local_60 = *local_70;
  SpanReader::Read(param_2,(uint)local_78);
  local_58 = *local_70;
  SpanReader::Read(param_2,(uint)local_78);
  local_50 = *local_70;
  SpanReader::Read(param_2,(uint)local_78);
  local_48 = *local_70;
  SpanReader::Read(param_2,(uint)local_78);
  local_40 = *local_70;
  SpanReader::Read(param_2,(uint)local_78);
  local_38 = *local_70;
  SpanReader::Read(param_2,(uint)local_78);
  local_30 = *(undefined4 *)local_70;
  (**(code **)(param_1 + 0x30))(&local_68,*(undefined8 *)(param_1 + 0x40));
  return;
}



===== ProcessVersionReply @ 14000f814 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl p9fs::P9Client::ProcessVersionReply(class p9fs::Exchange & __ptr64,class
   p9fs::SpanReader & __ptr64) __ptr64 */

void __thiscall
p9fs::P9Client::ProcessVersionReply(P9Client *this,Exchange *param_1,SpanReader *param_2)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  char *_Buf2;
  __uint64 local_28;
  uint *local_20;
  char local_18;
  
  SpanReader::Read(param_2,(uint)&local_28);
  _Buf2 = "9P2000.L";
  if (this[0x88] != (P9Client)0x0) {
    _Buf2 = "9P2000.W";
  }
  uVar1 = *local_20;
  SpanReader::TryString(param_2);
  if ((((local_18 == '\0') || (local_28 != 8)) || (iVar2 = memcmp(local_20,_Buf2,8), iVar2 != 0)) ||
     ((uVar3 = Feature_4005450042__private_IsEnabledDeviceUsageNoInline(), (int)uVar3 != 0 &&
      (uVar1 < 0x19)))) {
    (**(code **)(param_1 + 0x38))(0xc0000186,*(undefined8 *)(param_1 + 0x40));
    return;
  }
  if ((ulonglong)uVar1 < *(ulonglong *)(this + 0x18)) {
    util::DynamicArray<gsl::byte>::Reset
              ((DynamicArray<gsl::byte> *)(this + 0x10),(ulonglong)uVar1,local_28);
    uVar3 = Feature_3059645754__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar3 != 0) {
      *(undefined8 *)(this + 0x20) = 0;
      *(undefined8 *)(this + 0x28) = 0;
    }
  }
  (**(code **)(param_1 + 0x30))(*(undefined8 *)(param_1 + 0x40));
  return;
}



===== ProcessWOpenReply @ 14000f90c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl p9fs::P9Client::ProcessWOpenReply(class p9fs::Exchange & __ptr64,class
   p9fs::SpanReader & __ptr64) __ptr64 */

void __thiscall
p9fs::P9Client::ProcessWOpenReply(P9Client *this,Exchange *param_1,SpanReader *param_2)

{
  byte bVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  undefined4 uVar5;
  undefined1 auStack_128 [32];
  undefined4 *local_108;
  undefined4 local_100;
  undefined1 *local_f8;
  undefined8 local_f0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined1 local_b8 [16];
  undefined1 local_a8 [112];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_128;
  SpanReader::Read(param_2,(uint)&local_d8);
  bVar1 = *uStack_d0;
  SpanReader::Read(param_2,(uint)&local_d8);
  uVar2 = *(undefined2 *)uStack_d0;
  SpanReader::Qid(param_2);
  SpanReader::Read(param_2,(uint)&local_d8);
  SpanReader::Read(param_2,(uint)&local_d8);
  if ((local_d8 != 0xffffffffffffffff) && ((uStack_d0 != (byte *)0x0 || (local_d8 == 0)))) {
    uVar4 = 0;
    if (local_d8 != 0) {
      if (local_d8 == 0) goto LAB_14000fa94;
      do {
        if (uStack_d0[uVar4] == 0) break;
        uVar4 = uVar4 + 1;
      } while (uVar4 < local_d8);
      if (uVar4 == 0xffffffffffffffff) {
        goto LAB_14000f9f3;
      }
    }
    if (uVar4 <= local_d8) {
      local_d8 = uVar4;
LAB_14000f9f3:
      SpanReader::Read(param_2,(uint)&local_c8);
      uVar3 = *(undefined4 *)CONCAT44(uStack_bc,uStack_c0);
      SpanReader::ReadStatResult(param_2);
      uVar5 = 0xffffffff;
      if (bVar1 < 2) {
        uVar5 = *(undefined4 *)(param_1 + 0x28);
        *(undefined4 *)(param_1 + 0x28) = 0xffffffff;
      }
      local_f0 = *(undefined8 *)(param_1 + 0x40);
      local_f8 = local_a8;
      local_108 = &local_c8;
      local_c8 = (undefined4)local_d8;
      uStack_c4 = local_d8._4_4_;
      uStack_c0 = (undefined4)uStack_d0;
      uStack_bc = uStack_d0._4_4_;
      local_100 = uVar3;
      (**(code **)(param_1 + 0x30))
                (uVar5,CONCAT71((int7)((ulonglong)local_108 >> 8),bVar1),uVar2,local_b8);
      return;
    }
  }
LAB_14000fa94:
                    /* WARNING: Subroutine does not return */
  gsl::details::terminate();
}



===== ProcessWalkReply @ 14000faa0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl p9fs::P9Client::ProcessWalkReply(class p9fs::Exchange & __ptr64,class
   p9fs::SpanReader & __ptr64) __ptr64 */

void __thiscall
p9fs::P9Client::ProcessWalkReply(P9Client *this,Exchange *param_1,SpanReader *param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  uint5 uVar4;
  bool bVar5;
  ushort *puVar6;
  ulonglong uVar7;
  ulonglong local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  SpanReader::Read(param_2,(uint)&local_28);
  puVar6 = uStack_20;
  local_28 = 0;
  uStack_20 = (ushort *)0x0;
  uVar1 = *puVar6;
  if (uVar1 == 0) {
    local_28._0_4_ = 0;
    uStack_20._0_4_ = 0;
    uStack_20._4_4_ = 0;
  }
  else {
    uVar3 = *(ulonglong *)(param_2 + 0x10);
    uVar7 = (ulonglong)uVar1 * 0xd;
    if (*(ulonglong *)param_2 - uVar3 < uVar7) {
      local_28 = 0;
      local_18 = 0;
      bVar5 = false;
      uStack_20 = (ushort *)0x0;
    }
    else {
      if (*(ulonglong *)param_2 < uVar3) {
                    /* WARNING: Subroutine does not return */
        gsl::details::terminate();
      }
      uStack_20 = (ushort *)(*(longlong *)(param_2 + 8) + uVar3);
      *(ulonglong *)(param_2 + 0x10) = uVar7 + uVar3;
      bVar5 = true;
      uVar4 = (uint5)local_18;
      local_18 = (ulonglong)(uVar4 & 0xff);
      local_28 = uVar7;
    }
    if (!bVar5) {
      (**(code **)(param_1 + 0x38))(0xc0000186,*(undefined8 *)(param_1 + 0x40));
      return;
    }
  }
  uVar2 = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(param_1 + 0x28) = 0xffffffff;
  local_28 = (ulonglong)(uint)local_28;
  (**(code **)(param_1 + 0x30))(uVar2,(ulonglong)uVar1,&local_28,*(undefined8 *)(param_1 + 0x40));
  return;
}



===== Qid @ 14000fba0 =====

/* public: struct p9fs::Qid __cdecl p9fs::SpanReader::Qid(void) __ptr64 */

void __thiscall p9fs::SpanReader::Qid(SpanReader *this)

{
  undefined8 *in_RDX;
  undefined1 local_18 [8];
  undefined8 *local_10;
  
  *in_RDX = 0;
  in_RDX[1] = 0;
  Read(this,(uint)local_18);
  *(undefined1 *)((longlong)in_RDX + 0xc) = *(undefined1 *)local_10;
  Read(this,(uint)local_18);
  *(undefined4 *)(in_RDX + 1) = *(undefined4 *)local_10;
  Read(this,(uint)local_18);
  *in_RDX = *local_10;
  return;
}



===== Read @ 14000fc24 =====

/* public: class util::BasicExpected<class p9fs::SharedPtr<class p9fs::Exchange>,long> __cdecl
   p9fs::P9Client::Read(unsigned int,unsigned __int64,unsigned int,void (__cdecl*)(class
   gsl::span<enum gsl::byte const ,-1>,void * __ptr64),void (__cdecl*)(long,void * __ptr64),void *
   __ptr64) __ptr64 */

SpanWriter * __thiscall
p9fs::P9Client::Read
          (P9Client *this,uint param_1,__uint64 param_2,uint param_3,
          _func_void_span<gsl::byte_const_,_1>_void_ptr *param_4,_func_void_long_void_ptr *param_5,
          void *param_6)

{
  undefined8 uVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 in_register_00000014;
  SpanWriter *pSVar4;
  long lVar5;
  undefined4 in_register_0000008c;
  undefined8 local_58;
  char *pcStack_50;
  char local_48 [8];
  char *local_40;
  char *local_38;
  char *local_30;
  char *pcStack_28;
  undefined8 local_20;
  undefined8 local_18;
  
  pSVar4 = (SpanWriter *)CONCAT44(in_register_00000014,param_1);
  uVar1 = CONCAT44(in_register_0000008c,param_3);
  AllocateBuffer((MessageType)local_48,CONCAT71((int7)((ulonglong)pSVar4 >> 8),0x74));
  pcVar3 = local_40;
  if (local_48[0] == '\0') {
    local_18 = 0;
    local_30 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
    lVar5 = (long)local_40;
    local_20 = 0x208;
    pcStack_28 = "p9fs::P9Client::Read";
    TraceLog((ErrorSite *)&local_30,lVar5);
    *pSVar4 = (SpanWriter)0x0;
    *(long *)(pSVar4 + 8) = lVar5;
LAB_14000fc9b:
    pcVar3 = local_40;
    if (local_48[0] != '\0') {
      local_40 = (char *)0x0;
      if (pcVar3 != (char *)0x0) {
        ExFreePoolWithTag(pcVar3,0);
      }
    }
    return pSVar4;
  }
  if (local_38 == (char *)0x0) {
    pcStack_50 = (char *)0x0;
  }
  else {
    if (local_38 == (char *)0xffffffffffffffff) goto LAB_14000fe0c;
    pcStack_50 = local_40;
    if (local_40 == (char *)0x0) goto LAB_14000fe0c;
  }
  pcVar2 = pcStack_50;
  local_30 = local_38;
  pcStack_28 = pcStack_50;
  if (((((char *)0x6 < local_38) && ((char *)0x3 < local_38 + -7)) &&
      (*(int *)(pcStack_50 + 7) = (int)param_2, (char *)0xa < local_38)) &&
     ((char *)0x7 < local_38 + -0xb)) {
    *(undefined8 *)(pcStack_50 + 0xb) = uVar1;
    if (*(int *)(this + 0x18) - 0x18U < (uint)param_4) {
      param_4._0_4_ = *(int *)(this + 0x18) - 0x18U;
    }
    if (((char *)0x12 < local_38) && ((char *)0x3 < local_38 + -0x13)) {
      local_58 = 0;
      pcStack_50 = (char *)0xffffffff;
      *(uint *)(pcVar2 + 0x13) = (uint)param_4;
      local_40 = (char *)0x0;
      param_6 = pcVar3;
      local_20 = 0x17;
      CreateExchange(this,pSVar4,(MessageType)&local_30,
                     (FidLease *)CONCAT44(in_register_0000008c,CONCAT31((int3)(param_3 >> 8),0x74)),
                     (unique_ptr<enum_gsl::byte_[0],wistd::default_delete<enum_gsl::byte_[0]>_> *)
                     &local_58,&param_6,param_5,Session::ErrorCallback);
      FidLease::~FidLease((FidLease *)&local_58);
      if (param_6 != (void *)0x0) {
        ExFreePoolWithTag(param_6,0);
      }
      goto LAB_14000fc9b;
    }
  }
LAB_14000fe0c:
                    /* WARNING: Subroutine does not return */
  gsl::details::terminate();
}



===== Read @ 14000fe18 =====

/* public: class gsl::span<enum gsl::byte const ,-1> __cdecl p9fs::SpanReader::Read(unsigned int)
   __ptr64 */

ulonglong * __thiscall p9fs::SpanReader::Read(SpanReader *this,uint param_1)

{
  longlong lVar1;
  code *pcVar2;
  undefined4 in_register_00000014;
  ulonglong *puVar3;
  undefined1 *puVar4;
  uint in_R8D;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  puVar3 = (ulonglong *)CONCAT44(in_register_00000014,param_1);
  puVar4 = auStack_48;
  uVar7 = *(ulonglong *)this;
  uVar5 = *(ulonglong *)(this + 0x10);
  uVar6 = (ulonglong)in_R8D;
  if (uVar7 - uVar5 < uVar6) {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\storage\\plan9\\inc\\p9protohelpers.h";
    local_18 = 0x29;
    puVar3 = (ulonglong *)&DAT_c0000001;
    local_20 = "p9fs::SpanReader::Read";
    TraceLog((ErrorSite *)&local_28,-0x3fffffff);
    puVar4 = auStack_40;
    this = (SpanReader *)&DAT_00000005;
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)();
  }
  if (uVar7 < uVar5) {
                    /* WARNING: Subroutine does not return */
    *(undefined **)(puVar4 + -8) = &UNK_14000fe93;
    gsl::details::terminate();
  }
  lVar1 = *(longlong *)(this + 8);
  *puVar3 = uVar6;
  puVar3[1] = lVar1 + uVar5;
  *(ulonglong *)(this + 0x10) = *(longlong *)(this + 0x10) + uVar6;
  return puVar3;
}



===== ReadDirHelper @ 14000fe9c =====

/* private: class util::BasicExpected<class p9fs::SharedPtr<class p9fs::Exchange>,long> __cdecl
   p9fs::P9Client::ReadDirHelper(enum p9fs::MessageType,unsigned int,unsigned __int64,unsigned
   int,void (__cdecl*)(class gsl::span<enum gsl::byte const ,-1>,void * __ptr64),void
   (__cdecl*)(long,void * __ptr64),void * __ptr64) __ptr64 */

SpanWriter * __thiscall
p9fs::P9Client::ReadDirHelper
          (P9Client *this,MessageType param_1,uint param_2,__uint64 param_3,uint param_4,
          _func_void_span<gsl::byte_const_,_1>_void_ptr *param_5,_func_void_long_void_ptr *param_6,
          void *param_7)

{
  char *pcVar1;
  char *pcVar2;
  undefined4 in_register_00000014;
  SpanWriter *pSVar3;
  long lVar4;
  undefined4 uVar5;
  undefined4 in_stack_0000002c;
  undefined8 local_58;
  char *pcStack_50;
  char local_48 [8];
  char *local_40;
  char *local_38;
  char *local_30;
  char *pcStack_28;
  undefined8 local_20;
  undefined8 local_18;
  
  uVar5 = (undefined4)param_3;
  pSVar3 = (SpanWriter *)CONCAT44(in_register_00000014,param_1);
  AllocateBuffer((MessageType)local_48,CONCAT71((int7)((ulonglong)pSVar3 >> 8),(char)param_2));
  pcVar2 = local_40;
  if (local_48[0] == '\0') {
    local_18 = 0;
    local_30 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
    lVar4 = (long)local_40;
    local_20 = 0x61a;
    pcStack_28 = "p9fs::P9Client::ReadDirHelper";
    TraceLog((ErrorSite *)&local_30,lVar4);
    *pSVar3 = (SpanWriter)0x0;
    *(long *)(pSVar3 + 8) = lVar4;
  }
  else {
    if (local_38 == (char *)0x0) {
      pcStack_50 = (char *)0x0;
    }
    else {
      if (local_38 == (char *)0xffffffffffffffff) goto LAB_14001007a;
      pcStack_50 = local_40;
      if (local_40 == (char *)0x0) goto LAB_14001007a;
    }
    pcVar1 = pcStack_50;
    local_30 = local_38;
    pcStack_28 = pcStack_50;
    if ((((local_38 < (char *)0x7) || (local_38 + -7 < (char *)0x4)) ||
        (*(undefined4 *)(pcStack_50 + 7) = uVar5, local_38 < (char *)0xb)) ||
       (((local_38 + -0xb < (char *)0x8 ||
         (*(ulonglong *)(pcStack_50 + 0xb) = CONCAT44(in_stack_0000002c,param_4),
         local_38 < (char *)0x13)) || (local_38 + -0x13 < (char *)0x4)))) {
LAB_14001007a:
                    /* WARNING: Subroutine does not return */
      gsl::details::terminate();
    }
    local_58 = 0;
    pcStack_50 = (char *)0xffffffff;
    *(undefined4 *)(pcVar1 + 0x13) = param_5._0_4_;
    local_40 = (char *)0x0;
    param_7 = pcVar2;
    local_20 = 0x17;
    CreateExchange(this,pSVar3,(MessageType)&local_30,
                   (FidLease *)
                   CONCAT44((int)(param_3 >> 0x20),CONCAT31((int3)(param_3 >> 8),(char)param_2)),
                   (unique_ptr<enum_gsl::byte_[0],wistd::default_delete<enum_gsl::byte_[0]>_> *)
                   &local_58,&param_7,param_6,SyncContextErrorCallback);
    FidLease::~FidLease((FidLease *)&local_58);
    if (param_7 != (void *)0x0) {
      ExFreePoolWithTag(param_7,0);
    }
  }
  pcVar2 = local_40;
  if (local_48[0] != '\0') {
    local_40 = (char *)0x0;
    if (pcVar2 != (char *)0x0) {
      ExFreePoolWithTag(pcVar2,0);
    }
  }
  return pSVar3;
}



===== ReadDirHelper @ 140010088 =====

/* private: long __cdecl p9fs::P9Client::ReadDirHelper(enum p9fs::MessageType,unsigned int,unsigned
   __int64,class gsl::span<enum gsl::byte,-1> & __ptr64,class p9fs::ICancellationManager * __ptr64)
   __ptr64 */

long __thiscall
p9fs::P9Client::ReadDirHelper
          (P9Client *this,MessageType param_1,uint param_2,__uint64 param_3,
          span<gsl::byte,_1> *param_4,ICancellationManager *param_5)

{
  long lVar1;
  undefined8 uVar2;
  undefined4 in_stack_ffffffffffffff64;
  void *in_stack_ffffffffffffff70;
  char local_78 [8];
  Exchange *local_70;
  char *local_68;
  char *local_60;
  undefined8 local_58;
  undefined8 local_50;
  SyncContextHeader local_48 [24];
  undefined4 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  uVar2 = 0;
  KeInitializeEvent(local_48,1);
  local_30 = 0;
  local_28 = *(undefined8 *)param_4;
  uStack_20 = *(undefined8 *)(param_4 + 8);
  ReadDirHelper(this,(MessageType)local_78,
                (uint)CONCAT71((int7)((ulonglong)uVar2 >> 8),(char)param_1),(ulonglong)param_2,
                (uint)param_3,
                (_func_void_span<gsl::byte_const_,_1>_void_ptr *)
                CONCAT44(in_stack_ffffffffffffff64,*(undefined4 *)param_4),
                <lambda_f2b2459de070180cb9d191c0493c3427>::
                <lambda_invoker_cdecl><gsl::span<enum_gsl::byte_const_,_1>,void_*>,
                in_stack_ffffffffffffff70);
  if (local_78[0] == '\0') {
    lVar1 = (long)local_70;
    local_58 = 0x63d;
  }
  else {
    lVar1 = WaitWithCancellation(this,local_48,local_70,param_5);
    if (-1 < lVar1) {
      *(undefined8 *)param_4 = local_28;
      *(undefined8 *)(param_4 + 8) = uStack_20;
      if (local_78[0] != '\0') {
        SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>
                  ((SharedPtr<p9fs::Exchange> *)&local_70);
      }
      return 0;
    }
    local_58 = 0x63e;
  }
  local_50 = 0;
  local_68 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
  local_60 = "p9fs::P9Client::ReadDirHelper";
  TraceLog((ErrorSite *)&local_68,lVar1);
  if (local_78[0] != '\0') {
    SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>((SharedPtr<p9fs::Exchange> *)&local_70);
  }
  return lVar1;
}



===== ReadStatResult @ 1400101bc =====

/* public: struct p9fs::StatResult __cdecl p9fs::SpanReader::ReadStatResult(void) __ptr64 */

void __thiscall p9fs::SpanReader::ReadStatResult(SpanReader *this)

{
  undefined4 *in_RDX;
  undefined1 local_18 [8];
  undefined8 *local_10;
  
  memset(in_RDX,0,0x68);
  Read(this,(uint)local_18);
  *in_RDX = *(undefined4 *)local_10;
  Read(this,(uint)local_18);
  in_RDX[1] = *(undefined4 *)local_10;
  Read(this,(uint)local_18);
  in_RDX[2] = *(undefined4 *)local_10;
  Read(this,(uint)local_18);
  *(undefined8 *)(in_RDX + 4) = *local_10;
  Read(this,(uint)local_18);
  *(undefined8 *)(in_RDX + 6) = *local_10;
  Read(this,(uint)local_18);
  *(undefined8 *)(in_RDX + 8) = *local_10;
  Read(this,(uint)local_18);
  *(undefined8 *)(in_RDX + 10) = *local_10;
  Read(this,(uint)local_18);
  *(undefined8 *)(in_RDX + 0xc) = *local_10;
  Read(this,(uint)local_18);
  *(undefined8 *)(in_RDX + 0xe) = *local_10;
  Read(this,(uint)local_18);
  *(undefined8 *)(in_RDX + 0x10) = *local_10;
  Read(this,(uint)local_18);
  *(undefined8 *)(in_RDX + 0x12) = *local_10;
  Read(this,(uint)local_18);
  *(undefined8 *)(in_RDX + 0x14) = *local_10;
  Read(this,(uint)local_18);
  *(undefined8 *)(in_RDX + 0x16) = *local_10;
  Read(this,(uint)local_18);
  *(undefined8 *)(in_RDX + 0x18) = *local_10;
  return;
}



===== Reattach @ 140010378 =====

/* public: class util::BasicExpected<class p9fs::SharedPtr<class p9fs::Exchange>,long> __cdecl
   p9fs::P9Client::Reattach(unsigned int,class std::basic_string_view<char>,class
   std::basic_string_view<char>,unsigned int,void (__cdecl*)(unsigned int,struct p9fs::Qid,void *
   __ptr64),void (__cdecl*)(long,void * __ptr64),void * __ptr64) __ptr64 */

SpanWriter * __thiscall
p9fs::P9Client::Reattach
          (P9Client *this,SpanWriter *param_2,undefined4 param_3,undefined8 *param_4,
          ulonglong *param_5,undefined4 param_6,_func_void_long_void_ptr *param_7,void *param_8,
          undefined8 param_9)

{
  undefined8 uVar1;
  ulonglong *puVar2;
  char *pcVar3;
  long lVar4;
  undefined7 uVar5;
  char *local_68;
  ulonglong *puStack_60;
  char local_58 [8];
  ulonglong *local_50;
  char *local_48;
  char *local_40;
  ulonglong *puStack_38;
  char *local_30;
  undefined8 local_28;
  
  puVar2 = param_5;
  uVar5 = (undefined7)((ulonglong)param_4 >> 8);
  AllocateBuffer((MessageType)local_58,CONCAT71((int7)((ulonglong)param_2 >> 8),0x68));
  if (local_58[0] == '\0') {
    local_28 = 0;
    local_40 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
    lVar4 = (long)local_50;
    local_30 = (char *)0xe8;
    puStack_38 = (ulonglong *)0x140017cf0;
    TraceLog((ErrorSite *)&local_40,lVar4);
    *param_2 = (SpanWriter)0x0;
    *(long *)(param_2 + 8) = lVar4;
LAB_1400103f6:
    puVar2 = local_50;
    if (local_58[0] != '\0') {
      local_50 = (ulonglong *)0x0;
      if (puVar2 != (ulonglong *)0x0) {
        ExFreePoolWithTag(puVar2,0);
      }
    }
    return param_2;
  }
  if (local_48 == (char *)0x0) {
    puStack_60 = (ulonglong *)0x0;
  }
  else {
    local_68 = local_48;
    if (local_48 == (char *)0xffffffffffffffff) goto LAB_140010598;
    puStack_60 = local_50;
    if (local_50 == (ulonglong *)0x0) goto LAB_140010598;
  }
  local_68 = local_48;
  local_40 = local_48;
  puStack_38 = puStack_60;
  if (((((char *)0x6 < local_48) && ((char *)0x3 < local_48 + -7)) &&
      (*(undefined4 *)((longlong)puStack_60 + 7) = param_3, (char *)0xa < local_48)) &&
     ((char *)0x3 < local_48 + -0xb)) {
    local_68 = (char *)*param_4;
    uVar1 = param_4[1];
    local_30 = (char *)0xf;
    *(undefined4 *)((longlong)puStack_60 + 0xb) = 0xffffffff;
    puStack_60 = (ulonglong *)uVar1;
    SpanWriter::String((SpanWriter *)&local_40,&local_68);
    local_68 = (char *)*puVar2;
    puStack_60 = (ulonglong *)puVar2[1];
    SpanWriter::String((SpanWriter *)&local_40,&local_68);
    puVar2 = local_50;
    if ((local_30 <= local_40) && (3 < (ulonglong)((longlong)local_40 - (longlong)local_30))) {
      pcVar3 = (char *)((longlong)puStack_38 + (longlong)local_30);
      local_30 = local_30 + 4;
      local_68 = (char *)0x0;
      *(undefined4 *)pcVar3 = param_6;
      local_50 = (ulonglong *)0x0;
      param_5 = puVar2;
      puStack_60 = (ulonglong *)0xffffffff;
      CreateExchange(this,param_2,(MessageType)&local_40,(FidLease *)CONCAT71(uVar5,0x68),
                     (unique_ptr<enum_gsl::byte_[0],wistd::default_delete<enum_gsl::byte_[0]>_> *)
                     &local_68,&param_5,param_7,param_8);
      FidLease::~FidLease((FidLease *)&local_68);
      if (param_5 != (ulonglong *)0x0) {
        ExFreePoolWithTag(param_5,0);
      }
      goto LAB_1400103f6;
    }
  }
LAB_140010598:
                    /* WARNING: Subroutine does not return */
  gsl::details::terminate();
}



===== ReceiveCallback @ 1400105b0 =====

/* private: static void __cdecl p9fs::P9Client::ReceiveCallback(long,unsigned long,void * __ptr64)
    */

void __cdecl p9fs::P9Client::ReceiveCallback(long param_1,ulong param_2,void *param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong local_18;
  
  if (param_1 < 0) {
    HandleIoError(param_3);
  }
  else {
    local_18 = *(ulonglong *)((longlong)param_3 + 0x18);
    uVar2 = (ulonglong)param_2 + *(longlong *)((longlong)param_3 + 0x20);
    if (local_18 == 0) {
      lVar1 = 0;
      local_18 = 0;
    }
    else {
      lVar1 = *(longlong *)((longlong)param_3 + 0x10);
      if ((local_18 == 0xffffffffffffffff) || (lVar1 == 0)) goto LAB_140010624;
    }
    if (uVar2 == 0xffffffffffffffff) {
      if (local_18 == 0xffffffffffffffff) goto LAB_140010624;
    }
    else {
      if (local_18 < uVar2) {
LAB_140010624:
                    /* WARNING: Subroutine does not return */
        gsl::details::terminate();
      }
      local_18 = uVar2;
    }
    *(ulonglong *)((longlong)param_3 + 0x20) = local_18;
    *(longlong *)((longlong)param_3 + 0x28) = lVar1;
    HandleReply(param_3);
  }
  return;
}



===== Remove @ 140010630 =====

/* public: long __cdecl p9fs::P9Client::Remove(unsigned int,class p9fs::ICancellationManager *
   __ptr64) __ptr64 */

long __thiscall p9fs::P9Client::Remove(P9Client *this,uint param_1,ICancellationManager *param_2)

{
  char *pcVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 in_R9;
  char *local_res20;
  SpanWriter local_a8 [8];
  long local_a0;
  undefined4 uStack_9c;
  char *local_98;
  char *pcStack_90;
  char local_88 [8];
  char *local_80;
  char *local_78;
  char *local_70;
  char *pcStack_68;
  undefined8 local_60;
  undefined8 local_58;
  SyncContextHeader local_50 [24];
  undefined4 local_38;
  
  uVar3 = 0;
  KeInitializeEvent(local_50,1);
  local_38 = 0;
  AllocateBuffer((MessageType)local_88,CONCAT71((int7)((ulonglong)uVar3 >> 8),0x7a));
  if (local_88[0] == '\0') {
    lVar2 = (long)local_80;
    local_70 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
    pcStack_68 = "p9fs::P9Client::Remove";
    local_60 = 0x27b;
    local_58 = 0;
    TraceLog((ErrorSite *)&local_70,lVar2);
    local_a8[0] = (SpanWriter)0x0;
    local_a0 = lVar2;
    if (local_88[0] != '\0') {
LAB_1400107b7:
      pcVar1 = local_80;
      local_80 = (char *)0x0;
      if (pcVar1 != (char *)0x0) {
        ExFreePoolWithTag(pcVar1,0);
      }
      goto LAB_1400107d2;
    }
  }
  else {
    if (local_78 == (char *)0x0) {
      local_98 = (char *)0x0;
      pcStack_90 = (char *)0x0;
    }
    else {
      local_98 = local_78;
      if ((local_78 == (char *)0xffffffffffffffff) ||
         (pcStack_90 = local_80, local_80 == (char *)0x0)) goto LAB_14001083f;
    }
    local_70 = local_98;
    pcStack_68 = pcStack_90;
    if ((local_98 < (char *)0x7) || (local_98 + -7 < (char *)0x4)) {
LAB_14001083f:
                    /* WARNING: Subroutine does not return */
      gsl::details::terminate();
    }
    *(uint *)(pcStack_90 + 7) = param_1;
    local_res20 = local_80;
    local_60 = 0xb;
    local_80 = (char *)0x0;
    pcStack_90 = (char *)0xffffffff;
    local_98 = (char *)0x0;
    CreateExchange(this,local_a8,(MessageType)&local_70,
                   (FidLease *)CONCAT71((int7)((ulonglong)in_R9 >> 8),0x7a),
                   (unique_ptr<enum_gsl::byte_[0],wistd::default_delete<enum_gsl::byte_[0]>_> *)
                   &local_98,&local_res20,SyncContextGenericCallback,SyncContextErrorCallback);
    FidLease::~FidLease((FidLease *)&local_98);
    if (local_res20 != (char *)0x0) {
      ExFreePoolWithTag(local_res20,0);
    }
    if (local_88[0] != '\0') goto LAB_1400107b7;
LAB_1400107d2:
    if (local_a8[0] != (SpanWriter)0x0) {
      lVar2 = WaitWithCancellation(this,local_50,(Exchange *)CONCAT44(uStack_9c,local_a0),param_2);
      goto LAB_1400107fa;
    }
  }
  lVar2 = local_a0;
  local_70 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
  pcStack_68 = "p9fs::P9Client::Remove";
  local_60 = 0x28a;
  local_58 = 0;
  TraceLog((ErrorSite *)&local_70,local_a0);
LAB_1400107fa:
  if (local_a8[0] != (SpanWriter)0x0) {
    SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>((SharedPtr<p9fs::Exchange> *)&local_a0);
  }
  return lVar2;
}



===== Rename @ 14001084c =====

/* public: class util::BasicExpected<class p9fs::SharedPtr<class p9fs::Exchange>,long> __cdecl
   p9fs::P9Client::Rename(unsigned int,unsigned int,class std::basic_string_view<unsigned
   short>,void (__cdecl*)(void * __ptr64),void (__cdecl*)(long,void * __ptr64),void * __ptr64)
   __ptr64 */

SpanWriter * __thiscall
p9fs::P9Client::Rename
          (P9Client *this,SpanWriter *param_2_00,undefined4 param_2,undefined8 param_4,char *param_5
          ,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  undefined8 uVar1;
  char *pcVar2;
  char **ppcVar3;
  long lVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char *local_68;
  char *pcStack_60;
  char local_58 [8];
  char *local_50;
  char *local_48;
  char *local_40;
  char *pcStack_38;
  undefined8 local_30;
  undefined8 local_28;
  
  pcVar2 = param_5;
  uVar6 = (undefined4)((ulonglong)param_4 >> 0x20);
  ppcVar3 = &local_68;
  local_68 = *(char **)param_5;
  pcStack_60 = *(char **)(param_5 + 8);
  uVar5 = (int)param_4;
  StringUnicodeToUtf8Length(&param_5,ppcVar3);
  if ((char)param_5 == '\0') {
    lVar4 = param_5._4_4_;
    local_40 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
    local_30 = 0x294;
    pcStack_38 = "p9fs::P9Client::Rename";
    local_28 = 0;
    TraceLog((ErrorSite *)&local_40,param_5._4_4_);
    *param_2_00 = (SpanWriter)0x0;
    *(long *)(param_2_00 + 8) = lVar4;
  }
  else {
    AllocateBuffer((MessageType)local_58,CONCAT71((int7)((ulonglong)ppcVar3 >> 8),0x14));
    if (local_58[0] == '\0') {
      local_40 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
      local_30 = 0x296;
      lVar4 = (long)local_50;
      pcStack_38 = "p9fs::P9Client::Rename";
      local_28 = 0;
      TraceLog((ErrorSite *)&local_40,lVar4);
      *param_2_00 = (SpanWriter)0x0;
      *(long *)(param_2_00 + 8) = lVar4;
    }
    else {
      if (local_48 == (char *)0x0) {
        local_68 = (char *)0x0;
        pcStack_60 = (char *)0x0;
      }
      else {
        local_68 = local_48;
        if (local_48 == (char *)0xffffffffffffffff) goto LAB_140010a89;
        pcStack_60 = local_50;
        if (local_50 == (char *)0x0) goto LAB_140010a89;
      }
      local_40 = local_68;
      pcStack_38 = pcStack_60;
      if ((((local_68 < (char *)0x7) || (local_68 + -7 < (char *)0x4)) ||
          (*(undefined4 *)(pcStack_60 + 7) = param_2, local_68 < (char *)0xb)) ||
         (local_68 + -0xb < (char *)0x4)) {
LAB_140010a89:
                    /* WARNING: Subroutine does not return */
        gsl::details::terminate();
      }
      local_68 = *(char **)pcVar2;
      uVar1 = *(undefined8 *)(pcVar2 + 8);
      *(int *)(pcStack_60 + 0xb) = (int)param_4;
      local_30 = 0xf;
      pcStack_60 = (char *)uVar1;
      SpanWriterWriteUnicodeString(&local_40,&local_68);
      param_5 = local_50;
      local_50 = (char *)0x0;
      pcStack_60 = (char *)0xffffffff;
      local_68 = (char *)0x0;
      CreateExchange(this,param_2_00,(MessageType)&local_40,
                     (FidLease *)CONCAT44(uVar6,CONCAT31((int3)((uint)uVar5 >> 8),0x14)),
                     (unique_ptr<enum_gsl::byte_[0],wistd::default_delete<enum_gsl::byte_[0]>_> *)
                     &local_68,&param_5,SyncContextGenericCallback,SyncContextErrorCallback);
      FidLease::~FidLease((FidLease *)&local_68);
      if (param_5 != (char *)0x0) {
        ExFreePoolWithTag(param_5,0);
      }
    }
    pcVar2 = local_50;
    if (local_58[0] != '\0') {
      local_50 = (char *)0x0;
      if (pcVar2 != (char *)0x0) {
        ExFreePoolWithTag(pcVar2,0);
      }
    }
  }
  return param_2_00;
}



===== Rename @ 140010a98 =====

/* public: long __cdecl p9fs::P9Client::Rename(unsigned int,unsigned int,class
   std::basic_string_view<unsigned short>,class p9fs::ICancellationManager * __ptr64) __ptr64 */

long __thiscall
p9fs::P9Client::Rename
          (P9Client *this,undefined4 param_1,undefined4 param_2,undefined8 *param_4,
          ICancellationManager *param_5)

{
  long lVar1;
  char local_58 [8];
  Exchange *local_50;
  char *local_48;
  char *pcStack_40;
  undefined8 local_38;
  undefined8 local_30;
  SyncContextHeader local_28 [24];
  undefined4 local_10;
  
  KeInitializeEvent(local_28,1);
  local_48 = (char *)*param_4;
  pcStack_40 = (char *)param_4[1];
  local_10 = 0;
  Rename(this,local_58,param_1,param_2,&local_48);
  if (local_58[0] == '\0') {
    local_30 = 0;
    local_48 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
    local_38 = 0x2a6;
    pcStack_40 = "p9fs::P9Client::Rename";
    lVar1 = (long)local_50;
    TraceLog((ErrorSite *)&local_48,lVar1);
  }
  else {
    lVar1 = WaitWithCancellation(this,local_28,local_50,param_5);
  }
  if (local_58[0] != '\0') {
    SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>((SharedPtr<p9fs::Exchange> *)&local_50);
  }
  return lVar1;
}



===== SendCallback @ 140010b90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl p9fs::P9Client::SendCallback(long,unsigned long,void * __ptr64) */

void __cdecl p9fs::P9Client::SendCallback(long param_1,ulong param_2,void *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  bool bVar5;
  void *local_res18 [2];
  longlong local_18;
  longlong lStack_10;
  
  local_res18[0] = param_3;
  if (param_1 < 0) {
    LOCK();
    bVar5 = *(int *)((longlong)param_3 + 0x60) == 0x103;
    if (bVar5) {
      *(int *)((longlong)param_3 + 0x60) = param_1;
    }
    UNLOCK();
    if (bVar5) {
      plVar1 = *(longlong **)(*(longlong *)((longlong)param_3 + 0x10) + 8);
      (**(code **)(*plVar1 + 8))(plVar1,&local_18,*(undefined2 *)((longlong)param_3 + 0x1a));
      if ((char)local_18 != '\0') {
        SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>
                  ((SharedPtr<p9fs::Exchange> *)&lStack_10);
      }
      (**(code **)((longlong)param_3 + 0x38))(param_1,*(undefined8 *)((longlong)param_3 + 0x40));
    }
  }
  else {
    *(int *)((longlong)param_3 + 0x48) = *(int *)((longlong)param_3 + 0x48) + param_2;
    uVar3 = (ulonglong)*(uint *)((longlong)param_3 + 0x48);
    if (uVar3 < *(ulonglong *)param_3) {
      lVar4 = *(ulonglong *)param_3 - uVar3;
      lVar2 = lStack_10;
      if ((lVar4 == -1) ||
         ((lStack_10 = *(longlong *)((longlong)param_3 + 8) + uVar3, local_18 = lVar4,
          lStack_10 == 0 && (lVar2 = 0, lVar4 != 0)))) {
        lStack_10 = lVar2;
                    /* WARNING: Subroutine does not return */
        gsl::details::terminate();
      }
      (**(code **)(*(longlong *)**(undefined8 **)((longlong)param_3 + 0x10) + 0x10))
                ((longlong *)**(undefined8 **)((longlong)param_3 + 0x10),&local_18,SendCallback,
                 param_3);
    }
    else {
      lVar2 = *(longlong *)((longlong)param_3 + 0x68);
      *(undefined8 *)((longlong)param_3 + 0x68) = 0;
      if (lVar2 != 0) {
        ExFreePoolWithTag(lVar2,0);
      }
      *(undefined8 *)param_3 = 0;
      *(undefined8 *)((longlong)param_3 + 8) = 0;
    }
  }
  SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>((SharedPtr<p9fs::Exchange> *)local_res18);
  return;
}



===== SendExchange @ 140010ca8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl p9fs::P9Client::SendExchange(class p9fs::Exchange & __ptr64,bool) __ptr64 */

long __thiscall p9fs::P9Client::SendExchange(P9Client *this,Exchange *param_1,bool param_2)

{
  longlong lVar1;
  undefined2 uVar2;
  longlong *plVar3;
  longlong lVar4;
  code *pcVar5;
  int iVar6;
  Exchange *pEVar7;
  undefined1 *puVar8;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [72];
  
  puVar8 = auStack_58;
  LOCK();
  pEVar7 = param_1 + 0x70;
  lVar1 = *(longlong *)pEVar7;
  *(longlong *)pEVar7 = *(longlong *)pEVar7 + 1;
  UNLOCK();
  pEVar7 = param_1;
  if (lVar1 + 1 < 2) {
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(0xe);
    puVar8 = auStack_50;
  }
  plVar3 = *(longlong **)this;
  lVar1 = *(longlong *)pEVar7;
  pcVar5 = *(code **)(*plVar3 + 0x10);
  if (lVar1 != -1) {
    lVar4 = *(longlong *)(param_1 + 8);
    *(longlong *)(puVar8 + 0x30) = lVar1;
    *(longlong *)(puVar8 + 0x38) = lVar4;
    if ((lVar4 != 0) || (lVar1 == 0)) {
      *(undefined4 *)(puVar8 + 0x30) = *(undefined4 *)(puVar8 + 0x30);
      *(undefined4 *)(puVar8 + 0x34) = *(undefined4 *)(puVar8 + 0x34);
      *(undefined4 *)(puVar8 + 0x38) = *(undefined4 *)(puVar8 + 0x38);
      *(undefined4 *)(puVar8 + 0x3c) = *(undefined4 *)(puVar8 + 0x3c);
      *(undefined8 *)(puVar8 + -8) = 0x140010d39;
      iVar6 = (*pcVar5)(plVar3,puVar8 + 0x30,SendCallback,param_1);
      if (iVar6 == 0x103) {
        *(undefined8 *)(puVar8 + 0x60) = 0;
      }
      else {
        if (((iVar6 == -0x3ffffdf4) && (param_2)) && (*(longlong *)(this + 0x60) != 0)) {
          *(undefined8 *)(puVar8 + -8) = 0x140010d69;
          AttemptReconnect(this,param_1);
          *(undefined8 *)(puVar8 + 0x60) = 0;
          *(undefined8 *)(puVar8 + -8) = 0x140010d79;
          SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>
                    ((SharedPtr<p9fs::Exchange> *)(puVar8 + 0x60));
          return 0x103;
        }
        plVar3 = *(longlong **)(this + 8);
        uVar2 = *(undefined2 *)(param_1 + 0x1a);
        pcVar5 = *(code **)(*plVar3 + 8);
        *(undefined8 *)(puVar8 + -8) = 0x140010dae;
        (*pcVar5)(plVar3,puVar8 + 0x40,uVar2);
        if (puVar8[0x40] != '\0') {
          *(undefined8 *)(puVar8 + -8) = 0x140010dbf;
          SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>
                    ((SharedPtr<p9fs::Exchange> *)(puVar8 + 0x48));
        }
      }
      *(undefined8 *)(puVar8 + -8) = 0x140010dc9;
      SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>
                ((SharedPtr<p9fs::Exchange> *)(puVar8 + 0x60));
      return iVar6;
    }
  }
                    /* WARNING: Subroutine does not return */
  *(undefined **)(puVar8 + -8) = &UNK_140010dd2;
  gsl::details::terminate();
}



===== SetAttr @ 140010ddc =====

/* public: class util::BasicExpected<class p9fs::SharedPtr<class p9fs::Exchange>,long> __cdecl
   p9fs::P9Client::SetAttr(unsigned int,unsigned int,struct p9fs::StatResult const & __ptr64,void
   (__cdecl*)(void * __ptr64),void (__cdecl*)(long,void * __ptr64),void * __ptr64) __ptr64 */

SpanWriter * __thiscall
p9fs::P9Client::SetAttr
          (P9Client *this,uint param_1,uint param_2,StatResult *param_3,_func_void_void_ptr *param_4
          ,_func_void_long_void_ptr *param_5,void *param_6)

{
  _func_void_long_void_ptr *p_Var1;
  _func_void_long_void_ptr *p_Var2;
  undefined4 in_register_00000014;
  SpanWriter *pSVar3;
  long lVar4;
  undefined4 uVar5;
  undefined8 local_58;
  _func_void_long_void_ptr *p_Stack_50;
  char local_48 [8];
  _func_void_long_void_ptr *local_40;
  char *local_38;
  char *local_30;
  _func_void_long_void_ptr *p_Stack_28;
  undefined8 local_20;
  undefined8 local_18;
  
  uVar5 = SUB84(param_3,0);
  pSVar3 = (SpanWriter *)CONCAT44(in_register_00000014,param_1);
  AllocateBuffer((MessageType)local_48,CONCAT71((int7)((ulonglong)pSVar3 >> 8),0x1a));
  p_Var2 = local_40;
  if (local_48[0] == '\0') {
    local_18 = 0;
    local_30 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
    lVar4 = (long)local_40;
    local_20 = 0x259;
    p_Stack_28 = (_func_void_long_void_ptr *)0x140017df0;
    TraceLog((ErrorSite *)&local_30,lVar4);
    *pSVar3 = (SpanWriter)0x0;
    *(long *)(pSVar3 + 8) = lVar4;
LAB_140010e53:
    p_Var2 = local_40;
    if (local_48[0] != '\0') {
      local_40 = (_func_void_long_void_ptr *)0x0;
      if (p_Var2 != (_func_void_long_void_ptr *)0x0) {
        ExFreePoolWithTag(p_Var2,0);
      }
    }
    return pSVar3;
  }
  if (local_38 == (char *)0x0) {
    p_Stack_50 = (_func_void_long_void_ptr *)0x0;
  }
  else {
    if (local_38 == (char *)0xffffffffffffffff) goto LAB_140011099;
    p_Stack_50 = local_40;
    if (local_40 == (_func_void_long_void_ptr *)0x0) goto LAB_140011099;
  }
  p_Var1 = p_Stack_50;
  local_30 = local_38;
  p_Stack_28 = p_Stack_50;
  if ((((((char *)0x6 < local_38) && ((char *)0x3 < local_38 + -7)) &&
       (*(uint *)(p_Stack_50 + 7) = param_2, (char *)0xa < local_38)) &&
      (((char *)0x3 < local_38 + -0xb &&
       (*(undefined4 *)(p_Stack_50 + 0xb) = uVar5, (char *)0xe < local_38)))) &&
     ((char *)0x3 < local_38 + -0xf)) {
    *(undefined4 *)(p_Stack_50 + 0xf) = *(undefined4 *)param_4;
    if ((((((char *)0x12 < local_38) && ((char *)0x3 < local_38 + -0x13)) &&
         ((*(undefined4 *)(p_Stack_50 + 0x13) = *(undefined4 *)(param_4 + 4),
          (char *)0x16 < local_38 &&
          ((((char *)0x3 < local_38 + -0x17 &&
            (*(undefined4 *)(p_Stack_50 + 0x17) = *(undefined4 *)(param_4 + 8),
            (char *)0x1a < local_38)) && ((char *)0x7 < local_38 + -0x1b)))))) &&
        ((*(undefined8 *)(p_Stack_50 + 0x1b) = *(undefined8 *)(param_4 + 0x20),
         (char *)0x22 < local_38 && ((char *)0x7 < local_38 + -0x23)))) &&
       ((*(undefined8 *)(p_Stack_50 + 0x23) = *(undefined8 *)(param_4 + 0x38),
        (char *)0x2a < local_38 &&
        ((((char *)0x7 < local_38 + -0x2b &&
          (*(undefined8 *)(p_Stack_50 + 0x2b) = *(undefined8 *)(param_4 + 0x40),
          (char *)0x32 < local_38)) &&
         (((char *)0x7 < local_38 + -0x33 &&
          ((*(undefined8 *)(p_Stack_50 + 0x33) = *(undefined8 *)(param_4 + 0x48),
           (char *)0x3a < local_38 && ((char *)0x7 < local_38 + -0x3b)))))))))) {
      local_58 = 0;
      p_Stack_50 = (_func_void_long_void_ptr *)0xffffffff;
      *(undefined8 *)(p_Var1 + 0x3b) = *(undefined8 *)(param_4 + 0x50);
      local_40 = (_func_void_long_void_ptr *)0x0;
      param_5 = p_Var2;
      local_20 = 0x43;
      CreateExchange(this,pSVar3,(MessageType)&local_30,
                     (FidLease *)
                     CONCAT44((int)((ulonglong)param_3 >> 0x20),
                              CONCAT31((int3)((ulonglong)param_3 >> 8),0x1a)),
                     (unique_ptr<enum_gsl::byte_[0],wistd::default_delete<enum_gsl::byte_[0]>_> *)
                     &local_58,&param_5,SyncContextGenericCallback,SyncContextErrorCallback);
      FidLease::~FidLease((FidLease *)&local_58);
      if (param_5 != (_func_void_long_void_ptr *)0x0) {
        ExFreePoolWithTag(param_5,0);
      }
      goto LAB_140010e53;
    }
  }
LAB_140011099:
                    /* WARNING: Subroutine does not return */
  gsl::details::terminate();
}



===== SetAttr @ 1400110a8 =====

/* public: long __cdecl p9fs::P9Client::SetAttr(unsigned int,unsigned int,struct p9fs::StatResult
   const & __ptr64,class p9fs::ICancellationManager * __ptr64) __ptr64 */

long __thiscall
p9fs::P9Client::SetAttr
          (P9Client *this,uint param_1,uint param_2,StatResult *param_3,
          ICancellationManager *param_4)

{
  long lVar1;
  _func_void_long_void_ptr *in_stack_ffffffffffffff90;
  void *in_stack_ffffffffffffff98;
  char local_58 [8];
  Exchange *local_50;
  char *local_48;
  char *local_40;
  undefined8 local_38;
  undefined8 local_30;
  SyncContextHeader local_28 [24];
  undefined4 local_10;
  
  KeInitializeEvent(local_28,1);
  local_10 = 0;
  SetAttr(this,(uint)local_58,param_1,(StatResult *)(ulonglong)param_2,
          (_func_void_void_ptr *)param_3,in_stack_ffffffffffffff90,in_stack_ffffffffffffff98);
  if (local_58[0] == '\0') {
    local_30 = 0;
    local_48 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
    local_38 = 0x270;
    local_40 = "p9fs::P9Client::SetAttr";
    lVar1 = (long)local_50;
    TraceLog((ErrorSite *)&local_48,lVar1);
  }
  else {
    lVar1 = WaitWithCancellation(this,local_28,local_50,param_4);
  }
  if (local_58[0] != '\0') {
    SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>((SharedPtr<p9fs::Exchange> *)&local_50);
  }
  return lVar1;
}



===== StatFs @ 140011194 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: class util::BasicExpected<struct p9fs::StatFsResult,long> __cdecl
   p9fs::P9Client::StatFs(unsigned int,class p9fs::ICancellationManager * __ptr64) __ptr64 */

undefined1 * __thiscall
p9fs::P9Client::StatFs(P9Client *this,uint param_1,ICancellationManager *param_2)

{
  char *pcVar1;
  long lVar2;
  undefined4 in_register_00000014;
  undefined1 *puVar3;
  undefined8 uVar4;
  ICancellationManager *in_R9;
  ICancellationManager *pIVar5;
  undefined1 auStackY_168 [32];
  SpanWriter local_118 [8];
  long local_110;
  undefined4 uStack_10c;
  char *local_108;
  char *pcStack_100;
  undefined8 local_f8;
  undefined8 local_f0;
  char local_e8 [8];
  char *local_e0;
  char *local_d8;
  char *local_d0;
  char *pcStack_c8;
  undefined8 local_c0;
  undefined4 local_b8;
  undefined4 local_b4;
  SyncContextHeader local_a8 [24];
  undefined4 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  puVar3 = (undefined1 *)CONCAT44(in_register_00000014,param_1);
  local_48 = __security_cookie ^ (ulonglong)auStackY_168;
  pIVar5 = in_R9;
  KeInitializeEvent(local_a8);
  uVar4 = 0;
  local_90 = 0;
  memset(&local_88,0,0x40);
  AllocateBuffer((MessageType)local_e8,CONCAT71((int7)((ulonglong)uVar4 >> 8),8));
  if (local_e8[0] == '\0') {
    lVar2 = (long)local_e0;
    local_108 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
    pcStack_100 = "p9fs::P9Client::StatFs";
    local_f8 = 0xfb;
    local_f0 = 0;
    TraceLog((ErrorSite *)&local_108,lVar2);
    local_118[0] = (SpanWriter)0x0;
    local_110 = lVar2;
    if (local_e8[0] != '\0') {
LAB_140011345:
      pcVar1 = local_e0;
      local_e0 = (char *)0x0;
      if (pcVar1 != (char *)0x0) {
        ExFreePoolWithTag(pcVar1,0);
      }
      goto LAB_140011360;
    }
LAB_140011367:
    local_f8 = 0x10f;
    lVar2 = local_110;
  }
  else {
    if (local_d8 == (char *)0x0) {
      local_d0 = (char *)0x0;
      pcStack_c8 = (char *)0x0;
    }
    else {
      local_d0 = local_d8;
      if ((local_d8 == (char *)0xffffffffffffffff) ||
         (pcStack_c8 = local_e0, local_e0 == (char *)0x0)) goto LAB_14001141b;
    }
    local_108 = local_d0;
    pcStack_100 = pcStack_c8;
    if ((local_d0 < (char *)0x7) || (local_d0 + -7 < (char *)0x4)) {
LAB_14001141b:
                    /* WARNING: Subroutine does not return */
      gsl::details::terminate();
    }
    local_b8 = 0xffffffff;
    *(int *)(pcStack_c8 + 7) = (int)param_2;
    local_d0 = local_e0;
    local_f8 = 0xb;
    local_e0 = (char *)0x0;
    local_b4 = 0;
    local_c0 = 0;
    CreateExchange(this,local_118,(MessageType)&local_108,
                   (FidLease *)CONCAT71((int7)((ulonglong)pIVar5 >> 8),8),
                   (unique_ptr<enum_gsl::byte_[0],wistd::default_delete<enum_gsl::byte_[0]>_> *)
                   &local_c0,&local_d0,
                   <lambda_22d39e197da456b3d32f68b152e2332a>::
                   <lambda_invoker_cdecl><p9fs::StatFsResult_const_&,void_*>,
                   SyncContextErrorCallback);
    FidLease::~FidLease((FidLease *)&local_c0);
    if (local_d0 != (char *)0x0) {
      ExFreePoolWithTag(local_d0,0);
    }
    if (local_e8[0] != '\0') goto LAB_140011345;
LAB_140011360:
    if (local_118[0] == (SpanWriter)0x0) goto LAB_140011367;
    lVar2 = WaitWithCancellation(this,local_a8,(Exchange *)CONCAT44(uStack_10c,local_110),in_R9);
    if (-1 < lVar2) {
      *(undefined8 *)(puVar3 + 8) = local_88;
      *(undefined8 *)(puVar3 + 0x10) = uStack_80;
      *puVar3 = 1;
      *(undefined8 *)(puVar3 + 0x18) = local_78;
      *(undefined8 *)(puVar3 + 0x20) = uStack_70;
      *(undefined8 *)(puVar3 + 0x28) = local_68;
      *(undefined8 *)(puVar3 + 0x30) = uStack_60;
      *(undefined8 *)(puVar3 + 0x38) = local_58;
      *(undefined8 *)(puVar3 + 0x40) = uStack_50;
      goto LAB_1400113ba;
    }
    local_f8 = 0x110;
  }
  local_108 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
  pcStack_100 = "p9fs::P9Client::StatFs";
  local_f0 = 0;
  TraceLog((ErrorSite *)&local_108,lVar2);
  *(long *)(puVar3 + 8) = lVar2;
  *puVar3 = 0;
LAB_1400113ba:
  if (local_118[0] != (SpanWriter)0x0) {
    SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>((SharedPtr<p9fs::Exchange> *)&local_110);
  }
  return puVar3;
}



===== String @ 140011428 =====

/* public: void __cdecl p9fs::SpanWriter::String(class std::basic_string_view<char>) __ptr64 */

void __thiscall p9fs::SpanWriter::String(SpanWriter *this,ulonglong *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  code *pcVar3;
  undefined1 *puVar4;
  char *pcVar5;
  SpanWriter *pSVar6;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [24];
  char *local_38;
  longlong local_30;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  puVar4 = auStack_58;
  pcVar5 = (char *)*param_2;
  pSVar6 = this;
  if ((char *)0xffff < pcVar5) {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\storage\\plan9\\inc\\p9protohelpers.h";
    local_18 = 0x10c;
    local_20 = "p9fs::SpanWriter::String";
    TraceLog((ErrorSite *)&local_28,-0x3fffffff);
    this = (SpanWriter *)&DAT_00000005;
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)();
    puVar4 = auStack_50;
  }
  uVar1 = *(ulonglong *)(this + 0x10);
  if ((uVar1 <= *(ulonglong *)this) && (1 < *(ulonglong *)this - uVar1)) {
    uVar2 = *(ulonglong *)(this + 8);
    *(ulonglong *)(pSVar6 + 0x10) = uVar1 + 2;
    *(short *)(uVar1 + uVar2) = (short)*param_2;
    uVar1 = *(ulonglong *)(pSVar6 + 0x10);
    if ((uVar1 <= *(ulonglong *)pSVar6) && (pcVar5 <= (char *)(*(ulonglong *)pSVar6 - uVar1))) {
      local_30 = *(ulonglong *)(pSVar6 + 8) + uVar1;
      *(char **)(pSVar6 + 0x10) = pcVar5 + uVar1;
      uVar1 = param_2[1];
      if ((uVar1 != 0) || (pcVar5 == (char *)0x0)) {
        *(undefined8 *)(puVar4 + -8) = 0x1400114f5;
        local_38 = pcVar5;
        local_28 = pcVar5;
        local_20 = (char *)uVar1;
        gsl::copy<gsl::byte_const_,_1,gsl::byte,_1>(&local_28,&local_38);
        return;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  *(undefined **)(puVar4 + -8) = &UNK_140011501;
  gsl::details::terminate();
}



===== SyncContextErrorCallback @ 140011510 =====

/* private: static void __cdecl p9fs::P9Client::SyncContextErrorCallback(long,void * __ptr64) */

void __cdecl p9fs::P9Client::SyncContextErrorCallback(long param_1,void *param_2)

{
  *(long *)((longlong)param_2 + 0x18) = param_1;
  KeSetEvent(param_2,0,0);
  return;
}



===== SyncContextGenericCallback @ 140011540 =====

/* private: static void __cdecl p9fs::P9Client::SyncContextGenericCallback(void * __ptr64) */

void __cdecl p9fs::P9Client::SyncContextGenericCallback(void *param_1)

{
  KeSetEvent(param_1,0,0);
  return;
}



===== TryString @ 140011564 =====

/* public: struct p9fs::ReadResult<class std::basic_string_view<char> > __cdecl
   p9fs::SpanReader::TryString(void) __ptr64 */

void __thiscall p9fs::SpanReader::TryString(SpanReader *this)

{
  ulonglong uVar1;
  bool bVar2;
  ushort *puVar3;
  ulonglong uVar4;
  ulonglong *in_RDX;
  ulonglong uVar5;
  ulonglong local_28;
  
  uVar1 = *(ulonglong *)this;
  uVar5 = *(ulonglong *)(this + 0x10);
  if (uVar1 - uVar5 < 2) {
    bVar2 = false;
    puVar3 = (ushort *)0x0;
  }
  else {
    if (uVar1 < uVar5) goto LAB_14001166f;
    bVar2 = true;
    puVar3 = (ushort *)(*(longlong *)(this + 8) + uVar5);
    uVar5 = uVar5 + 2;
    *(ulonglong *)(this + 0x10) = uVar5;
  }
  if (bVar2) {
    uVar4 = (ulonglong)*puVar3;
    if (uVar1 - uVar5 < uVar4) {
      bVar2 = false;
      uVar4 = 0;
      uVar5 = 0;
    }
    else {
      if (uVar1 < uVar5) goto LAB_14001166f;
      *(ulonglong *)(this + 0x10) = uVar4 + uVar5;
      uVar5 = *(longlong *)(this + 8) + uVar5;
      bVar2 = true;
    }
    if (bVar2) {
      if ((uVar4 == 0xffffffffffffffff) || ((uVar5 == 0 && (uVar4 != 0)))) goto LAB_14001166f;
      local_28 = 0;
      if (uVar4 == 0) {
LAB_14001164f:
        if (uVar4 < local_28) {
LAB_14001166f:
                    /* WARNING: Subroutine does not return */
          gsl::details::terminate();
        }
      }
      else {
        if (uVar4 == 0) goto LAB_14001166f;
        do {
          if (*(char *)(uVar5 + local_28) == '\0') break;
          local_28 = local_28 + 1;
        } while (local_28 < uVar4);
        if (local_28 != 0xffffffffffffffff) goto LAB_14001164f;
        local_28 = uVar4;
      }
      *in_RDX = local_28;
      in_RDX[1] = uVar5;
      *(undefined1 *)(in_RDX + 2) = 1;
      goto LAB_1400115cf;
    }
  }
  in_RDX[2] = 0;
  *in_RDX = 0;
  in_RDX[1] = 0;
LAB_1400115cf:
  *(undefined4 *)((longlong)in_RDX + 0x11) = 0;
  *(undefined2 *)((longlong)in_RDX + 0x15) = 0;
  *(undefined1 *)((longlong)in_RDX + 0x17) = 0;
  return;
}



===== WOpen @ 14001167c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: class util::BasicExpected<struct p9fs::P9Client::WOpenResult,long> __cdecl
   p9fs::P9Client::WOpen(unsigned int,class std::basic_string_view<unsigned short>,unsigned
   short,enum p9fs::OpenFlags,enum p9fs::WOpenFlags,unsigned long,unsigned long,unsigned __int64)
   __ptr64 */

undefined1 * __thiscall
p9fs::P9Client::WOpen
          (P9Client *this,undefined1 *param_2,undefined4 param_3,undefined8 *param_4,
          undefined2 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  long lVar1;
  longlong lVar2;
  undefined1 auStack_198 [32];
  undefined2 local_178;
  undefined4 local_170;
  undefined4 local_168;
  undefined4 local_160;
  code *local_148;
  SyncContextHeader *local_138;
  char local_128 [8];
  Exchange *local_120;
  char *local_118;
  char *pcStack_110;
  undefined8 local_108;
  undefined8 local_100;
  SyncContextHeader local_f8 [24];
  undefined4 local_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  longlong local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
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
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_198;
  KeInitializeEvent(local_f8);
  local_e0 = 0;
  memset(&local_b0,0,0x70);
  local_b8 = 0;
  local_ac = 0;
  local_138 = local_f8;
  local_148 = <lambda_a9925a96b5dba09fd9b9e575892a499b>::
              <lambda_invoker_cdecl><unsigned_int,enum_p9fs::WOpenStatus,unsigned_int,p9fs::Qid,std::basic_string_view<char>,unsigned_int,p9fs::StatResult_const_&,void_*>
  ;
  local_160 = param_8;
  local_168 = param_7;
  local_170 = param_6;
  local_d8 = 0;
  uStack_d0 = 0;
  local_178 = param_5;
  local_c8 = 0;
  uStack_c0 = 0;
  local_118 = (char *)*param_4;
  pcStack_110 = (char *)param_4[1];
  WOpen(this,local_128,param_3,&local_118);
  if (local_128[0] == '\0') {
    lVar1 = (long)local_120;
    local_108 = 0x312;
LAB_14001175e:
    local_100 = 0;
    local_118 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
    pcStack_110 = "p9fs::P9Client::WOpen";
    TraceLog((ErrorSite *)&local_118,lVar1);
    *param_2 = 0;
    *(long *)(param_2 + 8) = lVar1;
    if (local_128[0] != '\0') goto LAB_140011854;
  }
  else {
    lVar1 = SendExchange(this,local_120,true);
    if (lVar1 < 0) {
      local_108 = 0x313;
      goto LAB_14001175e;
    }
    lVar1 = Wait(local_f8,local_120,(ICancellationManager *)0x0);
    if (lVar1 < 0) {
      local_108 = 0x314;
      goto LAB_14001175e;
    }
    lVar2 = 0;
    *param_2 = 1;
    *(undefined4 *)(param_2 + 8) = (undefined4)local_d8;
    *(undefined8 *)(param_2 + 0x18) = local_c8;
    *(undefined8 *)(param_2 + 0x20) = uStack_c0;
    param_2[0xc] = local_d8._4_1_;
    *(undefined4 *)(param_2 + 0x10) = (undefined4)uStack_d0;
    *(longlong *)(param_2 + 0x28) = local_b8;
    *(undefined8 *)(param_2 + 0x38) = local_a8;
    *(undefined8 *)(param_2 + 0x40) = uStack_a0;
    local_b8 = 0;
    *(undefined8 *)(param_2 + 0x48) = local_98;
    *(undefined8 *)(param_2 + 0x50) = uStack_90;
    *(undefined4 *)(param_2 + 0x30) = local_b0;
    *(undefined8 *)(param_2 + 0x58) = local_88;
    *(undefined8 *)(param_2 + 0x60) = uStack_80;
    *(undefined8 *)(param_2 + 0x68) = local_78;
    *(undefined8 *)(param_2 + 0x70) = uStack_70;
    *(undefined8 *)(param_2 + 0x78) = local_68;
    *(undefined8 *)(param_2 + 0x80) = uStack_60;
    *(undefined8 *)(param_2 + 0x88) = local_58;
    *(undefined8 *)(param_2 + 0x90) = uStack_50;
    *(undefined8 *)(param_2 + 0x98) = local_48;
    if (local_128[0] == '\0') goto LAB_140011862;
LAB_140011854:
    SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>((SharedPtr<p9fs::Exchange> *)&local_120);
  }
  lVar2 = local_b8;
LAB_140011862:
  local_b8 = 0;
  if (lVar2 != 0) {
    ExFreePoolWithTag(lVar2,0);
  }
  return param_2;
}



===== WOpen @ 1400118a8 =====

/* public: class util::BasicExpected<class p9fs::SharedPtr<class p9fs::Exchange>,long> __cdecl
   p9fs::P9Client::WOpen(unsigned int,class std::basic_string_view<unsigned short>,unsigned
   short,enum p9fs::OpenFlags,enum p9fs::WOpenFlags,unsigned long,unsigned long,unsigned
   __int64,void (__cdecl*)(unsigned int,enum p9fs::WOpenStatus,unsigned int,struct p9fs::Qid,class
   std::basic_string_view<char>,unsigned int,struct p9fs::StatResult const & __ptr64,void *
   __ptr64),void (__cdecl*)(long,void * __ptr64),void * __ptr64) __ptr64 */

SpanWriter * __thiscall
p9fs::P9Client::WOpen
          (P9Client *this,SpanWriter *param_2,undefined4 param_3,undefined8 *param_4,
          undefined2 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
          undefined8 param_9,undefined8 param_10,_func_void_long_void_ptr *param_11)

{
  char *pcVar1;
  char *pcVar2;
  char **ppcVar3;
  long lVar4;
  undefined7 uVar5;
  char *local_res20;
  char *local_a8;
  char *pcStack_a0;
  undefined8 local_98;
  undefined8 local_90;
  char local_88 [8];
  char *local_80;
  char *local_78;
  char *local_68;
  char *pcStack_60;
  char local_58;
  long local_50 [2];
  undefined4 local_48;
  char local_40 [8];
  long local_38;
  undefined2 local_30;
  
  uVar5 = (undefined7)((ulonglong)param_4 >> 8);
  local_68 = (char *)*param_4;
  pcStack_60 = (char *)param_4[1];
  ppcVar3 = &local_68;
  CountWalkPath(local_40,ppcVar3,param_5);
  if (local_40[0] == '\0') {
    local_a8 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
    local_98 = 0x2dc;
    pcStack_a0 = "p9fs::P9Client::WOpen";
    local_90 = 0;
    TraceLog((ErrorSite *)&local_a8,local_38);
    *param_2 = (SpanWriter)0x0;
    *(long *)(param_2 + 8) = local_38;
  }
  else {
    AllocateBuffer((MessageType)local_88,CONCAT71((int7)((ulonglong)ppcVar3 >> 8),0x84));
    if (local_88[0] == '\0') {
      local_a8 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
      local_98 = 0x2df;
      lVar4 = (long)local_80;
      pcStack_a0 = "p9fs::P9Client::WOpen";
      local_90 = 0;
      TraceLog((ErrorSite *)&local_a8,lVar4);
      *param_2 = (SpanWriter)0x0;
      *(long *)(param_2 + 8) = lVar4;
    }
    else {
      if (local_78 == (char *)0x0) {
        pcStack_60 = (char *)0x0;
        local_68 = (char *)0x0;
      }
      else {
        local_68 = local_78;
        if (local_78 == (char *)0xffffffffffffffff) goto LAB_140011bf7;
        pcStack_60 = local_80;
        if (local_80 == (char *)0x0) goto LAB_140011bf7;
      }
      pcVar1 = pcStack_60;
      pcVar2 = local_68;
      local_a8 = local_68;
      pcStack_a0 = pcStack_60;
      if (local_68 < (char *)0x7) {
LAB_140011bf7:
                    /* WARNING: Subroutine does not return */
        gsl::details::terminate();
      }
      FidProvider::GetNewFid((FidProvider *)(this + 0x30));
      if (local_58 == '\0') {
        local_a8 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
        local_98 = 0x2e3;
        pcStack_a0 = "p9fs::P9Client::WOpen";
        local_90 = 0;
        TraceLog((ErrorSite *)&local_a8,local_50[0]);
        *param_2 = (SpanWriter)0x0;
        *(long *)(param_2 + 8) = local_50[0];
      }
      else {
        if (((((pcVar2 + -7 < (char *)0x4) ||
              (*(undefined4 *)(pcVar1 + 7) = param_3, pcVar2 < (char *)0xb)) ||
             (pcVar2 + -0xb < (char *)0x4)) ||
            (((*(undefined4 *)(pcVar1 + 0xb) = local_48, pcVar2 < (char *)0xf ||
              (pcVar2 + -0xf < (char *)0x4)) ||
             ((*(undefined4 *)(pcVar1 + 0xf) = param_6, pcVar2 < (char *)0x13 ||
              ((pcVar2 + -0x13 < (char *)0x4 ||
               (*(undefined4 *)(pcVar1 + 0x13) = param_7, pcVar2 < (char *)0x17)))))))) ||
           ((pcVar2 + -0x17 < (char *)0x4 ||
            (((((*(undefined4 *)(pcVar1 + 0x17) = param_8, pcVar2 < (char *)0x1b ||
                (pcVar2 + -0x1b < (char *)0x4)) ||
               (pcVar1[0x1b] = '\0', pcVar1[0x1c] = '\0', pcVar1[0x1d] = '\0', pcVar1[0x1e] = '\0',
               pcVar2 < (char *)0x1f)) ||
              ((pcVar2 + -0x1f < (char *)0x8 ||
               (pcVar1[0x1f] = -0x1e, pcVar1[0x20] = '\x06', pcVar1[0x21] = '\0',
               pcVar1[0x22] = '\0', pcVar1[0x23] = '\0', pcVar1[0x24] = '\0', pcVar1[0x25] = '\0',
               pcVar1[0x26] = '\0', pcVar2 < (char *)0x27)))) || (pcVar2 + -0x27 < (char *)0x2))))))
        goto LAB_140011bf7;
        local_68 = (char *)*param_4;
        pcStack_60 = (char *)param_4[1];
        *(undefined2 *)(pcVar1 + 0x27) = local_30;
        local_98 = 0x29;
        WriteWalkPath(&local_68,param_5,&local_a8);
        local_res20 = local_80;
        local_80 = (char *)0x0;
        CreateExchange(this,param_2,(MessageType)&local_a8,(FidLease *)CONCAT71(uVar5,0x84),
                       (unique_ptr<enum_gsl::byte_[0],wistd::default_delete<enum_gsl::byte_[0]>_> *)
                       local_50,&local_res20,param_11,SyncContextErrorCallback);
        if (local_res20 != (char *)0x0) {
          ExFreePoolWithTag(local_res20,0);
        }
      }
      if (local_58 != '\0') {
        FidLease::~FidLease((FidLease *)local_50);
      }
    }
    pcVar1 = local_80;
    if (local_88[0] != '\0') {
      local_80 = (char *)0x0;
      if (pcVar1 != (char *)0x0) {
        ExFreePoolWithTag(pcVar1,0);
      }
    }
  }
  return param_2;
}



===== Wait @ 140011c04 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static long __cdecl p9fs::P9Client::Wait(struct p9fs::SyncContextHeader & __ptr64,class
   p9fs::Exchange & __ptr64,class p9fs::ICancellationManager * __ptr64) */

long __cdecl
p9fs::P9Client::Wait(SyncContextHeader *param_1,Exchange *param_2,ICancellationManager *param_3)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  bool bVar4;
  undefined8 local_res8;
  
  uVar3 = 0;
  local_res8 = 0xfffffffffa0a1f00;
  if ((param_3 != (ICancellationManager *)0x0) && (cVar1 = KeGetCurrentIrql(), cVar1 == '\0')) {
    uVar3 = (**(code **)(*(longlong *)param_3 + 0x10))(param_3);
  }
  iVar2 = FsRtlCancellableWaitForSingleObject(param_1,&local_res8,uVar3);
  if (iVar2 != 0) {
    CancelExchange(param_2,iVar2);
    iVar2 = KeWaitForSingleObject(param_1,6,0,0,&local_res8);
    if (iVar2 != 0) {
      LOCK();
      bVar4 = *(int *)(param_2 + 0x60) == 0x103;
      if (bVar4) {
        *(int *)(param_2 + 0x60) = -0x3ffffee0;
      }
      UNLOCK();
      if (bVar4) {
        (**(code **)(param_2 + 0x38))(0xc0000120,*(undefined8 *)(param_2 + 0x40));
      }
      return -0x3ffffee0;
    }
  }
  return *(long *)(param_1 + 0x18);
}



===== WaitWithCancellation @ 140011ce4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl p9fs::P9Client::WaitWithCancellation(struct p9fs::SyncContextHeader &
   __ptr64,class p9fs::Exchange & __ptr64,class p9fs::ICancellationManager * __ptr64) __ptr64 */

long __thiscall
p9fs::P9Client::WaitWithCancellation
          (P9Client *this,SyncContextHeader *param_1,Exchange *param_2,ICancellationManager *param_3
          )

{
  long lVar1;
  code *pcVar2;
  char *local_38;
  char *local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  if (param_3 == (ICancellationManager *)0x0) {
    lVar1 = 0;
  }
  else {
    lVar1 = (*(code *)**(undefined8 **)param_3)(param_3,param_2);
  }
  if (lVar1 < 0) {
    local_28 = 0x5ec;
  }
  else {
    lVar1 = SendExchange(this,param_2,true);
    if (-1 < lVar1) {
      lVar1 = Wait(param_1,param_2,param_3);
      if (param_3 == (ICancellationManager *)0x0) {
        return lVar1;
      }
      pcVar2 = *(code **)(*(longlong *)param_3 + 8);
      goto LAB_140011da1;
    }
    local_28 = 0x5ed;
  }
  local_20 = 0;
  local_38 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
  local_30 = "p9fs::P9Client::WaitWithCancellation";
  TraceLog((ErrorSite *)&local_38,lVar1);
  if (param_3 == (ICancellationManager *)0x0) {
    return lVar1;
  }
  pcVar2 = *(code **)(*(longlong *)param_3 + 8);
LAB_140011da1:
  (*pcVar2)(param_3);
  return lVar1;
}



===== Walk @ 140011dcc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: class util::BasicExpected<struct p9fs::P9Client::WalkResult,long> __cdecl
   p9fs::P9Client::Walk(unsigned int,class std::basic_string_view<char>) __ptr64 */

undefined1 * __thiscall
p9fs::P9Client::Walk(P9Client *this,undefined1 *param_2,undefined4 param_3,undefined8 *param_4)

{
  long lVar1;
  undefined1 auStack_d8 [32];
  code *local_b8;
  SyncContextHeader *local_a8;
  char local_98 [8];
  Exchange *local_90;
  char *local_88;
  char *pcStack_80;
  undefined8 local_78;
  undefined8 local_70;
  SyncContextHeader local_68 [24];
  undefined4 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_d8;
  KeInitializeEvent(local_68,1);
  local_38 = 0;
  local_a8 = local_68;
  local_48 = 0;
  uStack_40 = 0;
  local_88 = (char *)*param_4;
  pcStack_80 = (char *)param_4[1];
  local_b8 = <lambda_b317092193afddf539e07e3a80607ab1>::
             <lambda_invoker_cdecl><unsigned_int,unsigned_short,gsl::span<enum_gsl::byte_const_,_1>,void_*>
  ;
  local_50 = 0;
  Walk(this,local_98,param_3,&local_88);
  if (local_98[0] == '\0') {
    lVar1 = (long)local_90;
    local_78 = 0x143;
  }
  else {
    lVar1 = SendExchange(this,local_90,true);
    if (lVar1 < 0) {
      local_78 = 0x144;
    }
    else {
      lVar1 = Wait(local_68,local_90,(ICancellationManager *)0x0);
      if (-1 < lVar1) {
        *param_2 = 1;
        *(undefined8 *)(param_2 + 8) = local_48;
        *(undefined8 *)(param_2 + 0x10) = uStack_40;
        *(undefined8 *)(param_2 + 0x18) = local_38;
        goto LAB_140011eec;
      }
      local_78 = 0x145;
    }
  }
  local_70 = 0;
  local_88 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
  pcStack_80 = "p9fs::P9Client::Walk";
  TraceLog((ErrorSite *)&local_88,lVar1);
  *param_2 = 0;
  *(long *)(param_2 + 8) = lVar1;
LAB_140011eec:
  if (local_98[0] != '\0') {
    SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>((SharedPtr<p9fs::Exchange> *)&local_90);
  }
  return param_2;
}



===== Walk @ 140011f28 =====

/* public: class util::BasicExpected<class p9fs::SharedPtr<class p9fs::Exchange>,long> __cdecl
   p9fs::P9Client::Walk(unsigned int,class std::basic_string_view<char>,void (__cdecl*)(unsigned
   int,unsigned short,class gsl::span<enum gsl::byte const ,-1>,void * __ptr64),void
   (__cdecl*)(long,void * __ptr64),void * __ptr64) __ptr64 */

SpanWriter * __thiscall
p9fs::P9Client::Walk
          (P9Client *this,SpanWriter *param_2,undefined4 param_3,ulonglong *param_4,
          _func_void_long_void_ptr *param_5)

{
  ulonglong uVar1;
  char *pcVar2;
  char *pcVar3;
  long lVar4;
  undefined7 uVar5;
  char *local_res20;
  char *local_88;
  char *pcStack_80;
  char local_78 [8];
  char *local_70;
  char *local_68;
  char local_60;
  long local_58 [2];
  undefined4 local_50;
  char *local_48;
  char *pcStack_40;
  undefined8 local_38;
  undefined8 local_30;
  
  uVar5 = (undefined7)((ulonglong)param_4 >> 8);
  uVar1 = *param_4;
  AllocateBuffer((MessageType)local_78,CONCAT71((int7)((ulonglong)param_2 >> 8),0x6e));
  if (local_78[0] == '\0') {
    local_48 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
    local_38 = 0x11a;
    lVar4 = (long)local_70;
    pcStack_40 = "p9fs::P9Client::Walk";
    local_30 = 0;
    TraceLog((ErrorSite *)&local_48,lVar4);
    *param_2 = (SpanWriter)0x0;
    *(long *)(param_2 + 8) = lVar4;
  }
  else {
    if (local_68 == (char *)0x0) {
      pcStack_80 = (char *)0x0;
      local_88 = (char *)0x0;
    }
    else {
      local_88 = local_68;
      if ((local_68 == (char *)0xffffffffffffffff) ||
         (pcStack_80 = local_70, local_70 == (char *)0x0)) goto LAB_1400121b3;
    }
    pcVar3 = pcStack_80;
    pcVar2 = local_88;
    local_48 = local_88;
    pcStack_40 = pcStack_80;
    if (local_88 < (char *)0x7) {
LAB_1400121b3:
                    /* WARNING: Subroutine does not return */
      gsl::details::terminate();
    }
    FidProvider::GetNewFid((FidProvider *)(this + 0x30));
    if (local_60 != '\0') {
      if ((((pcVar2 + -7 < (char *)0x4) ||
           (*(undefined4 *)(pcVar3 + 7) = param_3, pcVar2 < (char *)0xb)) ||
          (pcVar2 + -0xb < (char *)0x4)) ||
         (*(undefined4 *)(pcVar3 + 0xb) = local_50, pcVar2 < (char *)0xf)) goto LAB_1400121b3;
      if (uVar1 == 0) {
        if (pcVar2 + -0xf < (char *)0x2) goto LAB_1400121b3;
        local_38 = 0x11;
        pcVar3[0xf] = '\0';
        pcVar3[0x10] = '\0';
      }
      else {
        if (pcVar2 + -0xf < (char *)0x2) goto LAB_1400121b3;
        local_88 = (char *)*param_4;
        pcStack_80 = (char *)param_4[1];
        local_38 = 0x11;
        pcVar3[0xf] = '\x01';
        pcVar3[0x10] = '\0';
        SpanWriter::String((SpanWriter *)&local_48,&local_88);
      }
      local_res20 = local_70;
      local_70 = (char *)0x0;
      CreateExchange(this,param_2,(MessageType)&local_48,(FidLease *)CONCAT71(uVar5,0x6e),
                     (unique_ptr<enum_gsl::byte_[0],wistd::default_delete<enum_gsl::byte_[0]>_> *)
                     local_58,&local_res20,param_5,SyncContextErrorCallback);
      if (local_res20 != (char *)0x0) {
        ExFreePoolWithTag(local_res20,0);
      }
      if (local_60 != '\0') {
        FidLease::~FidLease((FidLease *)local_58);
      }
      if (local_78[0] == '\0') {
        return param_2;
      }
      pcVar3 = local_70;
      goto LAB_140012062;
    }
    local_48 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
    local_38 = 0x11e;
    pcStack_40 = "p9fs::P9Client::Walk";
    local_30 = 0;
    TraceLog((ErrorSite *)&local_48,local_58[0]);
    *param_2 = (SpanWriter)0x0;
    *(long *)(param_2 + 8) = local_58[0];
    if (local_60 != '\0') {
      FidLease::~FidLease((FidLease *)local_58);
    }
  }
  if (local_78[0] == '\0') {
    return param_2;
  }
  pcVar3 = local_70;
LAB_140012062:
  local_70 = (char *)0x0;
  if (pcVar3 != (char *)0x0) {
    ExFreePoolWithTag(pcVar3,0);
  }
  return param_2;
}



===== WalkPath @ 1400121c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: class util::BasicExpected<struct p9fs::P9Client::WalkResult,long> __cdecl
   p9fs::P9Client::WalkPath(unsigned int,class std::basic_string_view<unsigned short>,unsigned
   short) __ptr64 */

undefined1 * __thiscall
p9fs::P9Client::WalkPath
          (P9Client *this,undefined1 *param_2,undefined4 param_3,undefined8 *param_4,
          undefined2 param_5)

{
  long lVar1;
  undefined1 auStack_d8 [32];
  undefined2 local_b8;
  code *local_b0;
  SyncContextHeader *local_a0;
  char local_98 [8];
  Exchange *local_90;
  char *local_88;
  char *pcStack_80;
  undefined8 local_78;
  undefined8 local_70;
  SyncContextHeader local_68 [24];
  undefined4 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_d8;
  KeInitializeEvent(local_68,1);
  local_38 = 0;
  local_a0 = local_68;
  local_50 = 0;
  local_b0 = <lambda_b317092193afddf539e07e3a80607ab1>::
             <lambda_invoker_cdecl><unsigned_int,unsigned_short,gsl::span<enum_gsl::byte_const_,_1>,void_*>
  ;
  local_48 = 0;
  uStack_40 = 0;
  local_b8 = param_5;
  local_88 = (char *)*param_4;
  pcStack_80 = (char *)param_4[1];
  WalkPath(this,local_98,param_3,&local_88);
  if (local_98[0] == '\0') {
    lVar1 = (long)local_90;
    local_78 = 0x17b;
  }
  else {
    lVar1 = SendExchange(this,local_90,true);
    if (lVar1 < 0) {
      local_78 = 0x17c;
    }
    else {
      lVar1 = Wait(local_68,local_90,(ICancellationManager *)0x0);
      if (-1 < lVar1) {
        *param_2 = 1;
        *(undefined8 *)(param_2 + 8) = local_48;
        *(undefined8 *)(param_2 + 0x10) = uStack_40;
        *(undefined8 *)(param_2 + 0x18) = local_38;
        goto LAB_1400122e9;
      }
      local_78 = 0x17d;
    }
  }
  local_70 = 0;
  local_88 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
  pcStack_80 = "p9fs::P9Client::WalkPath";
  TraceLog((ErrorSite *)&local_88,lVar1);
  *param_2 = 0;
  *(long *)(param_2 + 8) = lVar1;
LAB_1400122e9:
  if (local_98[0] != '\0') {
    SharedPtr<p9fs::Exchange>::~SharedPtr<p9fs::Exchange>((SharedPtr<p9fs::Exchange> *)&local_90);
  }
  return param_2;
}



===== WalkPath @ 140012328 =====

/* public: class util::BasicExpected<class p9fs::SharedPtr<class p9fs::Exchange>,long> __cdecl
   p9fs::P9Client::WalkPath(unsigned int,class std::basic_string_view<unsigned short>,unsigned
   short,void (__cdecl*)(unsigned int,unsigned short,class gsl::span<enum gsl::byte const ,-1>,void
   * __ptr64),void (__cdecl*)(long,void * __ptr64),void * __ptr64) __ptr64 */

SpanWriter * __thiscall
p9fs::P9Client::WalkPath
          (P9Client *this,SpanWriter *param_2,undefined4 param_3,undefined8 *param_4,
          undefined2 param_5,_func_void_long_void_ptr *param_6)

{
  char *pcVar1;
  char *pcVar2;
  char **ppcVar3;
  long lVar4;
  undefined7 uVar5;
  char *local_res20;
  char *local_a8;
  char *pcStack_a0;
  undefined8 local_98;
  undefined8 local_90;
  char local_88 [8];
  char *local_80;
  char *local_78;
  char *local_68;
  char *pcStack_60;
  char local_58;
  long local_50 [2];
  undefined4 local_48;
  char local_40 [8];
  long local_38;
  undefined2 local_30;
  
  uVar5 = (undefined7)((ulonglong)param_4 >> 8);
  local_68 = (char *)*param_4;
  pcStack_60 = (char *)param_4[1];
  ppcVar3 = &local_68;
  CountWalkPath(local_40,ppcVar3,param_5);
  if (local_40[0] == '\0') {
    local_a8 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
    local_98 = 0x152;
    pcStack_a0 = "p9fs::P9Client::WalkPath";
    local_90 = 0;
    TraceLog((ErrorSite *)&local_a8,local_38);
    *param_2 = (SpanWriter)0x0;
    *(long *)(param_2 + 8) = local_38;
  }
  else {
    AllocateBuffer((MessageType)local_88,CONCAT71((int7)((ulonglong)ppcVar3 >> 8),0x6e));
    if (local_88[0] == '\0') {
      local_a8 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
      local_98 = 0x155;
      lVar4 = (long)local_80;
      pcStack_a0 = "p9fs::P9Client::WalkPath";
      local_90 = 0;
      TraceLog((ErrorSite *)&local_a8,lVar4);
      *param_2 = (SpanWriter)0x0;
      *(long *)(param_2 + 8) = lVar4;
    }
    else {
      if (local_78 == (char *)0x0) {
        pcStack_60 = (char *)0x0;
        local_68 = (char *)0x0;
      }
      else {
        local_68 = local_78;
        if (local_78 == (char *)0xffffffffffffffff) goto LAB_1400125db;
        pcStack_60 = local_80;
        if (local_80 == (char *)0x0) goto LAB_1400125db;
      }
      pcVar2 = pcStack_60;
      pcVar1 = local_68;
      local_a8 = local_68;
      pcStack_a0 = pcStack_60;
      if (local_68 < (char *)0x7) {
LAB_1400125db:
                    /* WARNING: Subroutine does not return */
        gsl::details::terminate();
      }
      FidProvider::GetNewFid((FidProvider *)(this + 0x30));
      if (local_58 == '\0') {
        local_a8 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
        local_98 = 0x159;
        pcStack_a0 = "p9fs::P9Client::WalkPath";
        local_90 = 0;
        TraceLog((ErrorSite *)&local_a8,local_50[0]);
        *param_2 = (SpanWriter)0x0;
        *(long *)(param_2 + 8) = local_50[0];
      }
      else {
        if ((((pcVar1 + -7 < (char *)0x4) ||
             (*(undefined4 *)(pcVar2 + 7) = param_3, pcVar1 < (char *)0xb)) ||
            (pcVar1 + -0xb < (char *)0x4)) ||
           ((*(undefined4 *)(pcVar2 + 0xb) = local_48, pcVar1 < (char *)0xf ||
            (pcVar1 + -0xf < (char *)0x2)))) goto LAB_1400125db;
        local_68 = (char *)*param_4;
        pcStack_60 = (char *)param_4[1];
        *(undefined2 *)(pcVar2 + 0xf) = local_30;
        local_98 = 0x11;
        WriteWalkPath(&local_68,param_5,&local_a8);
        local_res20 = local_80;
        local_80 = (char *)0x0;
        CreateExchange(this,param_2,(MessageType)&local_a8,(FidLease *)CONCAT71(uVar5,0x6e),
                       (unique_ptr<enum_gsl::byte_[0],wistd::default_delete<enum_gsl::byte_[0]>_> *)
                       local_50,&local_res20,param_6,SyncContextErrorCallback);
        if (local_res20 != (char *)0x0) {
          ExFreePoolWithTag(local_res20,0);
        }
      }
      if (local_58 != '\0') {
        FidLease::~FidLease((FidLease *)local_50);
      }
    }
    pcVar1 = local_80;
    if (local_88[0] != '\0') {
      local_80 = (char *)0x0;
      if (pcVar1 != (char *)0x0) {
        ExFreePoolWithTag(pcVar1,0);
      }
    }
  }
  return param_2;
}



===== Write @ 1400125e8 =====

/* public: class util::BasicExpected<class p9fs::SharedPtr<class p9fs::Exchange>,long> __cdecl
   p9fs::P9Client::Write(unsigned int,unsigned __int64,class gsl::span<enum gsl::byte const
   ,-1>,void (__cdecl*)(unsigned int,void * __ptr64),void (__cdecl*)(long,void * __ptr64),void *
   __ptr64) __ptr64 */

SpanWriter * __thiscall
p9fs::P9Client::Write
          (P9Client *this,SpanWriter *param_2,undefined4 param_3,undefined8 param_4,
          ulonglong *param_5,_func_void_long_void_ptr *param_6,undefined8 param_7,undefined8 param_8
          )

{
  char *pcVar1;
  ulonglong *puVar2;
  long lVar3;
  char *pcVar4;
  undefined7 uVar5;
  char *local_78;
  ulonglong *puStack_70;
  char *local_68;
  ulonglong uStack_60;
  char local_58 [8];
  ulonglong *local_50;
  char *local_48;
  char *local_40;
  ulonglong *puStack_38;
  char *local_30;
  undefined8 local_28;
  
  puVar2 = param_5;
  uVar5 = (undefined7)((ulonglong)param_4 >> 8);
  pcVar1 = (char *)*param_5;
  AllocateBuffer((MessageType)local_58,CONCAT71((int7)((ulonglong)param_2 >> 8),0x76));
  if (local_58[0] == '\0') {
    local_28 = 0;
    local_40 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9client.cpp";
    lVar3 = (long)local_50;
    local_30 = (char *)0x21f;
    puStack_38 = (ulonglong *)0x140017dc0;
    TraceLog((ErrorSite *)&local_40,lVar3);
    *param_2 = (SpanWriter)0x0;
    *(long *)(param_2 + 8) = lVar3;
LAB_14001266a:
    puVar2 = local_50;
    if ((local_58[0] != '\0') && (local_50 = (ulonglong *)0x0, puVar2 != (ulonglong *)0x0)) {
      ExFreePoolWithTag(puVar2,0);
    }
    return param_2;
  }
  if (local_48 == (char *)0x0) {
    puStack_70 = (ulonglong *)0x0;
  }
  else {
    local_78 = local_48;
    if ((local_48 == (char *)0xffffffffffffffff) ||
       (puStack_70 = local_50, local_50 == (ulonglong *)0x0)) goto LAB_140012862;
  }
  local_78 = local_48;
  local_40 = local_48;
  puStack_38 = puStack_70;
  if (((((char *)0x6 < local_48) && ((char *)0x3 < local_48 + -7)) &&
      (*(undefined4 *)((longlong)puStack_70 + 7) = param_3, (char *)0xa < local_48)) &&
     ((char *)0x7 < local_48 + -0xb)) {
    *(undefined8 *)((longlong)puStack_70 + 0xb) = param_4;
    pcVar4 = (char *)(*(longlong *)(this + 0x18) - 0x18U);
    if (pcVar1 <= (char *)(*(longlong *)(this + 0x18) - 0x18U)) {
      pcVar4 = pcVar1;
    }
    if (((char *)0x12 < local_48) && ((char *)0x3 < local_48 + -0x13)) {
      *(int *)((longlong)puStack_70 + 0x13) = (int)pcVar4;
      if (pcVar4 == (char *)0xffffffffffffffff) {
        local_68 = pcVar1;
        if (pcVar1 == (char *)0xffffffffffffffff) goto LAB_140012862;
      }
      else {
        if (pcVar1 < pcVar4) goto LAB_140012862;
        local_68 = pcVar4;
      }
      uStack_60 = puVar2[1];
      if ((char *)0x16 < local_48) {
        local_48 = local_48 + -0x17;
        if (local_68 == (char *)0xffffffffffffffff) {
          local_78 = local_48;
          if (local_48 == (char *)0xffffffffffffffff) goto LAB_140012862;
        }
        else {
          if (local_48 < local_68) goto LAB_140012862;
          local_78 = local_68;
        }
        puStack_70 = (ulonglong *)((longlong)puStack_70 + 0x17);
        local_30 = local_68 + 0x17;
        gsl::copy<gsl::byte_const_,_1,gsl::byte,_1>(&local_68,&local_78);
        param_5 = local_50;
        local_50 = (ulonglong *)0x0;
        local_68 = (char *)0x0;
        uStack_60 = 0xffffffff;
        CreateExchange(this,param_2,(MessageType)&local_40,(FidLease *)CONCAT71(uVar5,0x76),
                       (unique_ptr<enum_gsl::byte_[0],wistd::default_delete<enum_gsl::byte_[0]>_> *)
                       &local_68,&param_5,param_6,Session::ErrorCallback);
        FidLease::~FidLease((FidLease *)&local_68);
        if (param_5 != (ulonglong *)0x0) {
          ExFreePoolWithTag(param_5,0);
        }
        goto LAB_14001266a;
      }
    }
  }
LAB_140012862:
                    /* WARNING: Subroutine does not return */
  gsl::details::terminate();
}



===== WriteWalkPath @ 140012870 =====

/* private: static void __cdecl p9fs::P9Client::WriteWalkPath(class std::basic_string_view<unsigned
   short>,unsigned short,class p9fs::SpanWriter & __ptr64) */

void __cdecl p9fs::P9Client::WriteWalkPath(longlong *param_1,undefined2 param_2,undefined8 param_3)

{
  undefined1 auVar1 [16];
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined1 local_38 [48];
  
  if (*param_1 != 0) {
    uVar3 = (undefined4)*param_1;
    uVar4 = *(undefined4 *)((longlong)param_1 + 4);
    uVar5 = (undefined4)param_1[1];
    uVar6 = *(undefined4 *)((longlong)param_1 + 0xc);
    do {
      local_48 = uVar3;
      uStack_44 = uVar4;
      uStack_40 = uVar5;
      uStack_3c = uVar6;
      puVar2 = (undefined4 *)PathDissectFirst(local_38,&local_48,param_2);
      local_48 = *puVar2;
      uStack_44 = puVar2[1];
      uStack_40 = puVar2[2];
      uStack_3c = puVar2[3];
      auVar1 = *(undefined1 (*) [16])(puVar2 + 4);
      uVar3 = auVar1._0_4_;
      uVar4 = auVar1._4_4_;
      uVar5 = auVar1._8_4_;
      uVar6 = auVar1._12_4_;
      SpanWriterWriteUnicodeString(param_3,&local_48);
    } while (auVar1._0_8_ != 0);
  }
  return;
}



===== Feature_3059645754__private_IsEnabledDeviceUsageNoInline @ 1400128e4 =====

ulonglong Feature_3059645754__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_3059645754__private_featureState;
  if ((Feature_3059645754__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3059645754__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3059645754__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3059645754__private_IsEnabledFallback @ 14001291c =====

void Feature_3059645754__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_3059645754__private_descriptor);
  return;
}



===== Feature_4005450042__private_IsEnabledDeviceUsageNoInline @ 140012938 =====

ulonglong Feature_4005450042__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_4005450042__private_featureState;
  if ((Feature_4005450042__private_featureState & 0x10) == 0) {
    uVar1 = Feature_4005450042__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_4005450042__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_4005450042__private_IsEnabledFallback @ 140012970 =====

void Feature_4005450042__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_4005450042__private_descriptor);
  return;
}



===== DirectoryEnumerator @ 14001298c =====

/* public: __cdecl p9fs::DirectoryEnumerator::DirectoryEnumerator(class p9fs::P9Client &
   __ptr64,unsigned int,enum p9fs::DirectoryEnumeratorFlags) __ptr64 */

DirectoryEnumerator * __thiscall
p9fs::DirectoryEnumerator::DirectoryEnumerator
          (DirectoryEnumerator *this,P9Client *param_1,uint param_2,DirectoryEnumeratorFlags param_3
          )

{
  *(P9Client **)this = param_1;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0;
  *(undefined8 *)(this + 0x58) = 0;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined8 *)(this + 0x68) = 0;
  *(undefined8 *)(this + 0x70) = 0;
  *(undefined8 *)(this + 0x78) = 0;
  memset(this + 0x80,0,0x78);
  *(undefined8 *)(this + 0xf8) = 0;
  *(undefined8 *)(this + 0x100) = 0;
  memset(this + 0x108,0,0x200);
  *(uint *)(this + 0x308) = param_2;
  *(undefined4 *)(this + 0x30c) = 0;
  if ((param_3 & 1) != 0) {
    *(uint *)(this + 0x30c) = *(uint *)(this + 0x30c) | 4;
  }
  if ((param_3 & 2) != 0) {
    *(uint *)(this + 0x30c) = *(uint *)(this + 0x30c) | 8;
  }
  return this;
}



===== HandleSingleFileQuery @ 140012a60 =====

/* private: long __cdecl p9fs::DirectoryEnumerator::HandleSingleFileQuery(class
   p9fs::ICancellationManager * __ptr64) __ptr64 */

long __thiscall
p9fs::DirectoryEnumerator::HandleSingleFileQuery
          (DirectoryEnumerator *this,ICancellationManager *param_1)

{
  longlong lVar1;
  long lVar2;
  longlong lVar3;
  longlong local_58;
  DirectoryEnumerator *pDStack_50;
  char *local_48;
  char *pcStack_40;
  undefined8 local_38;
  undefined8 local_30;
  char local_28 [8];
  long local_20;
  undefined4 uStack_1c;
  undefined8 uStack_18;
  
  lVar1 = *(longlong *)(this + 0x20);
  if (lVar1 == 0) {
    lVar3 = 0;
  }
  else {
    lVar3 = *(longlong *)(this + 0x18);
    if ((lVar1 == -1) || (lVar3 == 0)) {
                    /* WARNING: Subroutine does not return */
      gsl::details::terminate();
    }
  }
  local_58 = lVar1;
  pDStack_50 = (DirectoryEnumerator *)lVar3;
  lVar2 = Stat(this,&local_58,param_1);
  if (lVar2 < 0) {
    if (lVar2 == -0x3fffffcc) {
      lVar2 = -0x3ffffff1;
    }
  }
  else {
    *(longlong *)(this + 0x70) = lVar1;
    *(longlong *)(this + 0x78) = lVar3;
    *(undefined8 *)(this + 0x60) = 0;
    this[0x68] = (DirectoryEnumerator)((byte)(*(uint *)(this + 0x90) >> 0xc) & 0xf);
    *(undefined8 *)(this + 0x50) = *(undefined8 *)(this + 0x80);
    *(undefined8 *)(this + 0x58) = *(undefined8 *)(this + 0x88);
    if ((*(uint *)(this + 0x30c) & 8) != 0) {
      local_48 = *(char **)(this + 0x70);
      pcStack_40 = *(char **)(this + 0x78);
      pDStack_50 = this + 0x108;
      local_58 = 0x100;
      StringUtf8ToUnicode(local_28,&local_48,&local_58);
      if (local_28[0] == '\0') {
        local_30 = 0;
        local_48 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9readdir.cpp";
        pcStack_40 = "p9fs::DirectoryEnumerator::HandleSingleFileQuery";
        local_38 = 0x111;
        TraceLog((ErrorSite *)&local_48,local_20);
        return local_20;
      }
      *(ulonglong *)(this + 0xf8) = CONCAT44(uStack_1c,local_20);
      *(undefined8 *)(this + 0x100) = uStack_18;
    }
    *(uint *)(this + 0x30c) = *(uint *)(this + 0x30c) | 1;
    lVar2 = 0;
  }
  return lVar2;
}



===== Initialize @ 140012ba4 =====

/* public: long __cdecl p9fs::DirectoryEnumerator::Initialize(unsigned __int64,class
   std::basic_string_view<unsigned short>,bool) __ptr64 */

long __thiscall
p9fs::DirectoryEnumerator::Initialize
          (DirectoryEnumerator *this,__uint64 param_1,undefined8 *param_3,undefined1 param_4)

{
  long lVar1;
  undefined7 uVar2;
  char *local_28;
  char *pcStack_20;
  undefined8 local_18;
  undefined8 local_10;
  
  uVar2 = (undefined7)((ulonglong)param_3 >> 8);
                    /* WARNING: Load size is inaccurate */
  local_28 = (char *)*param_3;
  pcStack_20 = (char *)param_3[1];
  lVar1 = Restart(*param_3,&local_28);
  if (lVar1 < 0) {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9readdir.cpp";
    local_18 = 0x21;
    pcStack_20 = "p9fs::DirectoryEnumerator::Initialize";
    TraceLog((ErrorSite *)&local_28,lVar1);
  }
  else {
    lVar1 = util::DynamicArray<gsl::byte>::Reset
                      ((DynamicArray<gsl::byte> *)(this + 8),param_1,CONCAT71(uVar2,param_4));
  }
  return lVar1;
}



===== Next @ 140012c30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl p9fs::DirectoryEnumerator::Next(class p9fs::ICancellationManager * __ptr64)
   __ptr64 */

long __thiscall
p9fs::DirectoryEnumerator::Next(DirectoryEnumerator *this,ICancellationManager *param_1)

{
  SpanReader *this_00;
  undefined8 uVar1;
  short sVar2;
  uint5 uVar3;
  bool bVar4;
  char cVar5;
  long lVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  longlong lVar10;
  longlong lVar11;
  undefined7 uVar13;
  ICancellationManager *pIVar12;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined1 auStackY_238 [32];
  undefined8 local_208;
  undefined8 uStack_200;
  undefined8 local_1f8;
  char *local_1f0;
  longlong local_1e8;
  longlong local_1e0;
  ulonglong local_1d8;
  void *pvStack_1d0;
  short local_1c8;
  short sStack_1c6;
  undefined4 uStack_1c4;
  longlong lStack_1c0;
  undefined4 local_1b8;
  undefined4 uStack_1b4;
  undefined8 uStack_1b0;
  char *local_1a8;
  char *pcStack_1a0;
  undefined8 local_198;
  undefined8 local_190;
  char *local_188;
  char *local_180;
  undefined8 local_178;
  undefined8 local_170;
  undefined8 local_168;
  DirectoryEnumerator *pDStack_160;
  undefined1 local_158 [8];
  undefined8 *local_150;
  undefined1 local_148 [8];
  undefined1 *local_140;
  undefined4 local_138;
  undefined4 uStack_134;
  undefined8 uStack_130;
  undefined4 local_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 local_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined1 uStack_f0;
  undefined4 uStack_ef;
  undefined2 uStack_eb;
  undefined1 uStack_e9;
  undefined8 local_e8;
  undefined8 uStack_e0;
  ulonglong local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  char local_a0;
  undefined4 local_9f;
  undefined2 local_9b;
  undefined1 local_99;
  undefined8 local_88;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  ulonglong local_68;
  
  local_68 = __security_cookie ^ (ulonglong)auStackY_238;
  if ((*(uint *)(this + 0x30c) & 1) == 0) {
    if ((*(uint *)(this + 0x30c) & 2) == 0) {
      lVar6 = HandleSingleFileQuery(this,param_1);
    }
    else {
      this_00 = (SpanReader *)(this + 0x38);
      pIVar12 = param_1;
      do {
        if ((*(longlong *)this_00 == 0) || (*(longlong *)(this + 0x48) == *(longlong *)this_00)) {
          local_1e8 = *(longlong *)(this + 0x10);
          if (local_1e8 == 0) {
            local_1e8 = 0;
            local_1e0 = 0;
          }
          else {
            lVar11 = *(longlong *)(this + 8);
            if ((local_1e8 == -1) || (local_1e0 = lVar11, lVar11 == 0)) goto LAB_140013256;
          }
          uVar13 = (undefined7)((ulonglong)pIVar12 >> 8);
          if (((*(uint *)(this + 0x30c) & 4) == 0) || ((*(P9Client **)this)[0x88] == (P9Client)0x0))
          {
            lVar6 = P9Client::ReadDirHelper
                              (*(P9Client **)this,(MessageType)CONCAT71(uVar13,0x28),
                               *(uint *)(this + 0x308),*(__uint64 *)(this + 0x60),
                               (span<gsl::byte,_1> *)&local_1e8,param_1);
            if (-1 < lVar6) goto LAB_140012dbf;
            local_1f8 = 0xbb;
LAB_140012d66:
            local_208 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9readdir.cpp";
            uStack_200 = "p9fs::DirectoryEnumerator::FillBuffer";
            local_1f0 = (char *)0x0;
            TraceLog((ErrorSite *)&local_208,lVar6);
          }
          else {
            lVar6 = P9Client::ReadDirHelper
                              (*(P9Client **)this,(MessageType)CONCAT71(uVar13,0x82),
                               *(uint *)(this + 0x308),*(__uint64 *)(this + 0x60),
                               (span<gsl::byte,_1> *)&local_1e8,param_1);
            if (lVar6 < 0) {
              local_1f8 = 0xb7;
              goto LAB_140012d66;
            }
LAB_140012dbf:
            if (local_1e8 == 0) {
              *(uint *)(this + 0x30c) = *(uint *)(this + 0x30c) | 1;
              lVar6 = -0x7ffffffa;
              goto LAB_140013229;
            }
            if (local_1e8 == -1) {
LAB_140013256:
                    /* WARNING: Subroutine does not return */
              gsl::details::terminate();
            }
            local_1a8 = (char *)local_1e8;
            pcStack_1a0 = (char *)local_1e0;
            if (local_1e0 == 0) goto LAB_140013256;
            local_1f8 = 0;
            lVar6 = 0;
            *(longlong *)this_00 = local_1e8;
            *(longlong *)(this + 0x40) = local_1e0;
            *(undefined8 *)(this + 0x48) = 0;
          }
          if (lVar6 < 0) {
LAB_140013229:
            local_1a8 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9readdir.cpp";
            pcStack_1a0 = "p9fs::DirectoryEnumerator::Next";
            local_198 = 0x39;
            local_190 = 0;
            TraceLog((ErrorSite *)&local_1a8,lVar6);
            return lVar6;
          }
        }
        if ((ulonglong)(*(longlong *)this_00 - *(longlong *)(this + 0x48)) < 0x18) {
LAB_140012e9a:
          uVar14 = 0;
          uVar15 = 0;
          uVar16 = 0;
          uVar17 = 0;
          local_e8 = 0;
          uStack_e0 = 0;
          uVar18 = 0;
          uVar19 = 0;
          uVar20 = 0;
          uVar21 = 0;
          local_e8._0_4_ = 0;
          local_e8._4_4_ = 0;
          uStack_e0._0_4_ = 0;
          uStack_e0._4_4_ = 0;
          local_d8 = 0;
          uStack_ef = 0;
          uStack_eb = 0;
          uStack_e9 = 0;
          bVar4 = false;
          uVar22 = (undefined4)local_e8;
          uVar23 = local_e8._4_4_;
          uVar24 = (undefined4)uStack_e0;
          uVar25 = uStack_e0._4_4_;
        }
        else {
          puVar9 = (undefined4 *)SpanReader::Qid(this_00);
          uVar14 = *puVar9;
          uVar15 = puVar9[1];
          uVar16 = puVar9[2];
          uVar17 = puVar9[3];
          SpanReader::Read(this_00,(uint)local_158);
          local_88 = *local_150;
          SpanReader::Read(this_00,(uint)local_148);
          uStack_80 = CONCAT31(uStack_80._1_3_,*local_140);
          SpanReader::TryString(this_00);
          if ((char)local_1f8 == '\0') goto LAB_140012e9a;
          bVar4 = true;
          uVar3 = (uint5)local_d8;
          local_d8 = (ulonglong)(uVar3 & 0xff);
          uVar18 = (undefined4)local_88;
          uVar19 = local_88._4_4_;
          uVar20 = uStack_80;
          uVar21 = uStack_7c;
          uVar22 = (undefined4)local_208;
          uVar23 = local_208._4_4_;
          uVar24 = (long)uStack_200;
          uVar25 = uStack_200._4_4_;
        }
        if (!bVar4) {
          return -0x3ffffe7a;
        }
        if (((*(uint *)(this + 0x30c) & 4) != 0) && (*(char *)(*(longlong *)this + 0x88) != '\0')) {
          if ((ulonglong)(*(longlong *)this_00 - *(longlong *)(this + 0x48)) < 100) {
            memset(&local_108,0,0x70);
            cVar5 = local_a0;
          }
          else {
            SpanReader::ReadStatResult(this_00);
            cVar5 = '\x01';
            local_9f = 0;
            local_9b = 0;
            local_99 = 0;
          }
          if (cVar5 == '\0') {
            return -0x3ffffe7a;
          }
          *(undefined8 *)(this + 0x90) = local_108;
          *(undefined8 *)(this + 0x98) = uStack_100;
          *(undefined8 *)(this + 0xa0) = local_f8;
          *(ulonglong *)(this + 0xa8) =
               CONCAT17(uStack_e9,CONCAT25(uStack_eb,CONCAT41(uStack_ef,uStack_f0)));
          *(undefined8 *)(this + 0xb0) = local_e8;
          *(undefined8 *)(this + 0xb8) = uStack_e0;
          *(ulonglong *)(this + 0xc0) = local_d8;
          *(undefined8 *)(this + 200) = uStack_d0;
          *(undefined8 *)(this + 0xd0) = local_c8;
          *(undefined8 *)(this + 0xd8) = uStack_c0;
          *(undefined8 *)(this + 0xe0) = local_b8;
          *(undefined8 *)(this + 0xe8) = uStack_b0;
          *(undefined8 *)(this + 0xf0) = local_a8;
          *(undefined4 *)(this + 0x80) = uVar14;
          *(undefined4 *)(this + 0x84) = uVar15;
          *(undefined4 *)(this + 0x88) = uVar16;
          *(undefined4 *)(this + 0x8c) = uVar17;
        }
        *(undefined4 *)(this + 0x50) = uVar14;
        *(undefined4 *)(this + 0x54) = uVar15;
        *(undefined4 *)(this + 0x58) = uVar16;
        *(undefined4 *)(this + 0x5c) = uVar17;
        *(undefined4 *)(this + 0x60) = uVar18;
        *(undefined4 *)(this + 100) = uVar19;
        *(undefined4 *)(this + 0x68) = uVar20;
        *(undefined4 *)(this + 0x6c) = uVar21;
        *(undefined4 *)(this + 0x70) = uVar22;
        *(undefined4 *)(this + 0x74) = uVar23;
        *(undefined4 *)(this + 0x78) = uVar24;
        *(undefined4 *)(this + 0x7c) = uVar25;
        if (((*(uint *)(this + 0x30c) & 8) != 0) || (*(longlong *)(this + 0x28) != 0)) {
          pDStack_160 = this + 0x108;
          local_168 = 0x100;
          local_138 = 0x100;
          uStack_134 = 0;
          local_128 = uVar22;
          uStack_124 = uVar23;
          uStack_120 = uVar24;
          uStack_11c = uVar25;
          uStack_130 = pDStack_160;
          StringUtf8ToUnicode(&local_208,&local_128,&local_138);
          if (local_208._0_1_ == (ErrorSite)0x0) {
            local_180 = "p9fs::DirectoryEnumerator::Next";
            local_188 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9readdir.cpp";
            local_178 = 0x5a;
            local_170 = 0;
            TraceLog((ErrorSite *)&local_188,(long)uStack_200);
            return (long)uStack_200;
          }
          *(char **)(this + 0xf8) = uStack_200;
          *(undefined8 *)(this + 0x100) = local_1f8;
        }
        lVar11 = *(longlong *)(this + 0x28);
        if (lVar11 == 0) break;
        lVar10 = *(longlong *)(this + 0x30);
        if (lVar10 == 0) {
          lVar10 = 0;
          lVar11 = 0;
        }
        else if (lVar10 == -1) {
                    /* WARNING: Subroutine does not return */
          gsl::details::terminate();
        }
        uVar1 = *(undefined8 *)(this + 0x100);
        pIVar12 = (ICancellationManager *)&local_118;
        local_1c8 = (short)lVar10 * 2;
        uStack_1c4 = 0;
        local_1d8 = (ulonglong)CONCAT22(local_1c8,local_1c8);
        sVar2 = (short)*(undefined8 *)(this + 0xf8) * 2;
        local_1b8 = CONCAT22(sVar2,sVar2);
        uStack_1b4 = 0;
        uStack_1b0._0_4_ = (undefined4)uVar1;
        uStack_1b0._4_4_ = (undefined4)((ulonglong)uVar1 >> 0x20);
        local_118 = local_1b8;
        uStack_114 = 0;
        uStack_110 = (undefined4)uStack_1b0;
        uStack_10c = uStack_1b0._4_4_;
        pvStack_1d0 = (void *)lVar11;
        sStack_1c6 = local_1c8;
        lStack_1c0 = lVar11;
        uStack_1b0 = uVar1;
        cVar5 = FsRtlIsNameInExpression(&local_1d8,pIVar12,0,0);
      } while (cVar5 == '\0');
      if (((*(uint *)(this + 0x30c) & 4) == 0) || (*(char *)(*(longlong *)this + 0x88) != '\0')) {
        local_1d8 = *(ulonglong *)(this + 0x70);
        pvStack_1d0 = *(void **)(this + 0x78);
        if (local_1d8 == 2) {
          iVar8 = memcmp(pvStack_1d0,&s___,2);
          if (iVar8 == 0) {
            *(undefined8 *)(this + 0x80) = 0;
          }
        }
      }
      else {
        local_1d8 = *(ulonglong *)(this + 0x70);
        pvStack_1d0 = *(void **)(this + 0x78);
        uVar7 = Stat(this,&local_1d8,param_1);
        if ((int)uVar7 < 0) {
          local_208 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9readdir.cpp";
          uStack_200 = "p9fs::DirectoryEnumerator::Next";
          local_1f8 = 0x66;
          local_1f0 = "P9: Stat failed during directory read 0x%x\n";
          TraceLog((ErrorSite *)&local_208,-0x3fffffff,(ulonglong)uVar7);
          *(undefined8 *)(this + 0x80) = *(undefined8 *)(this + 0x50);
          *(undefined8 *)(this + 0x88) = *(undefined8 *)(this + 0x58);
          memset(&local_108,0,0x68);
          *(undefined8 *)(this + 0x90) = local_108;
          *(undefined8 *)(this + 0x98) = uStack_100;
          uVar14 = 0x8000;
          if ((char)this[0x8c] < '\0') {
            uVar14 = 0x4000;
          }
          *(undefined8 *)(this + 0xa0) = local_f8;
          *(ulonglong *)(this + 0xa8) =
               CONCAT17(uStack_e9,CONCAT25(uStack_eb,CONCAT41(uStack_ef,uStack_f0)));
          *(undefined8 *)(this + 0xb0) = local_e8;
          *(undefined8 *)(this + 0xb8) = uStack_e0;
          *(ulonglong *)(this + 0xc0) = local_d8;
          *(undefined8 *)(this + 200) = uStack_d0;
          *(undefined8 *)(this + 0xd0) = local_c8;
          *(undefined8 *)(this + 0xd8) = uStack_c0;
          *(undefined8 *)(this + 0xe0) = local_b8;
          *(undefined8 *)(this + 0xe8) = uStack_b0;
          *(undefined8 *)(this + 0xf0) = local_a8;
          *(undefined4 *)(this + 0x90) = uVar14;
        }
      }
      lVar6 = 0;
    }
  }
  else {
    lVar6 = -0x7ffffffa;
  }
  return lVar6;
}



===== Reset @ 140013268 =====

/* public: long __cdecl util::DynamicArray<unsigned short>::Reset(unsigned __int64,unsigned __int64)
   __ptr64 */

long __thiscall
util::DynamicArray<unsigned_short>::Reset
          (DynamicArray<unsigned_short> *this,__uint64 param_1,__uint64 param_2)

{
  longlong lVar1;
  undefined1 auVar2 [16];
  size_t _Size;
  void *_Dst;
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  if (param_1 == 0) {
    _Dst = (void *)0x0;
  }
  else {
    auVar2._8_8_ = 0;
    auVar2._0_8_ = param_1;
    _Size = SUB168(ZEXT816(2) * auVar2,0);
    if (SUB168(ZEXT816(2) * auVar2,8) != 0) {
      _Size = 0xffffffffffffffff;
    }
    _Dst = (void *)ExAllocatePool2(0x40,_Size,0x78523950);
    if (_Dst == (void *)0x0) {
      local_10 = 0;
      local_28 = "onecore\\vm\\inc\\DynamicArray.h";
      local_18 = 0x3d;
      local_20 = "util::DynamicArray<unsigned short>::Reset";
      p9fs::TraceLog((ErrorSite *)&local_28,-0x3fffff66);
      return -0x3fffff66;
    }
    memset(_Dst,0,_Size);
  }
  lVar1 = *(longlong *)this;
  *(void **)this = _Dst;
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0);
  }
  *(__uint64 *)(this + 8) = param_1;
  return 0;
}



===== Restart @ 140013348 =====

/* public: long __cdecl p9fs::DirectoryEnumerator::Restart(class std::basic_string_view<unsigned
   short>,bool) __ptr64 */

long __thiscall
p9fs::DirectoryEnumerator::Restart(DirectoryEnumerator *this,__uint64 *param_2,char param_3)

{
  DynamicArray<unsigned_short> *this_00;
  longlong lVar1;
  undefined8 uVar2;
  __uint64 _Var3;
  void *pvVar4;
  int iVar5;
  long lVar6;
  char *pcVar7;
  char *_Size;
  char *local_68;
  longlong lStack_60;
  char *local_58;
  void *pvStack_50;
  undefined8 local_48;
  char *local_38;
  char *pcStack_30;
  undefined8 local_28;
  undefined8 local_20;
  
  this_00 = (DynamicArray<unsigned_short> *)(this + 0x28);
  lVar1 = *(longlong *)this_00;
  *(undefined8 *)this_00 = 0;
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0);
  }
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x60) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  *(uint *)(this + 0x30c) = *(uint *)(this + 0x30c) & 0xfffffffe;
  if (param_3 == '\0') {
    local_38 = (char *)*param_2;
    pcStack_30 = (char *)param_2[1];
    StringUnicodeToUtf8(&local_58,&local_38);
    if ((char)local_58 == '\0') {
      local_38 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9readdir.cpp";
      lVar6 = (long)pvStack_50;
      local_28 = 0xa0;
      pcStack_30 = "p9fs::DirectoryEnumerator::Restart";
      local_20 = 0;
      TraceLog((ErrorSite *)&local_38,lVar6);
      pvVar4 = pvStack_50;
      if (((char)local_58 != '\0') && (pvStack_50 = (void *)0x0, pvVar4 != (void *)0x0)) {
        ExFreePoolWithTag(pvVar4,0);
      }
      return lVar6;
    }
    lVar1 = *(longlong *)(this + 0x18);
    uVar2 = *(undefined8 *)(this + 0x20);
    *(uint *)(this + 0x30c) = *(uint *)(this + 0x30c) & 0xfffffffd;
    *(void **)(this + 0x18) = pvStack_50;
    *(undefined8 *)(this + 0x20) = local_48;
    pvStack_50 = (void *)0x0;
    if (lVar1 == 0) {
      return 0;
    }
    local_48 = uVar2;
    ExFreePoolWithTag(lVar1,0);
    return 0;
  }
  pcVar7 = (char *)0x0;
  do {
    pcVar7 = pcVar7 + 1;
  } while (*(short *)(&u__ + (longlong)pcVar7 * 2) != 0);
  if (pcVar7 != (char *)0xffffffffffffffff) {
    local_58 = (char *)*param_2;
    pvStack_50 = (void *)param_2[1];
    if (((pcVar7 <= local_58) && (local_58 <= pcVar7)) &&
       (iVar5 = memcmp(pvStack_50,&u__,(ulonglong)local_58 >> 1), iVar5 == 0)) {
LAB_140013502:
      *(uint *)(this + 0x30c) = *(uint *)(this + 0x30c) | 2;
      return 0;
    }
    pcVar7 = (char *)0x0;
    do {
      pcVar7 = pcVar7 + 1;
    } while (*(short *)(&u____ + (longlong)pcVar7 * 2) != 0);
    if (pcVar7 != (char *)0xffffffffffffffff) {
      local_58 = (char *)*param_2;
      pvStack_50 = (void *)param_2[1];
      _Size = local_58;
      if ((pcVar7 <= local_58) && (local_58 <= pcVar7)) {
        _Size = (char *)((ulonglong)local_58 >> 1);
        iVar5 = memcmp(pvStack_50,&u____,(size_t)_Size);
        if (iVar5 == 0) goto LAB_140013502;
      }
      lVar6 = util::DynamicArray<unsigned_short>::Reset(this_00,*param_2,(__uint64)_Size);
      if (lVar6 < 0) {
        local_28 = 0x96;
        local_38 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9readdir.cpp";
        local_20 = 0;
        pcStack_30 = "p9fs::DirectoryEnumerator::Restart";
        TraceLog((ErrorSite *)&local_38,lVar6);
        return lVar6;
      }
      local_68 = *(char **)(this + 0x30);
      if (local_68 == (char *)0x0) {
        local_68 = (char *)0x0;
        lStack_60 = 0;
      }
      else {
        lStack_60 = *(longlong *)this_00;
        if ((local_68 == (char *)0xffffffffffffffff) || (lStack_60 == 0)) goto LAB_1400135d7;
      }
      local_58 = (char *)*param_2;
      _Var3 = param_2[1];
      local_38 = local_58;
      pcStack_30 = (char *)_Var3;
      if ((local_58 != (char *)0xffffffffffffffff) &&
         ((_Var3 != 0 || (pvStack_50 = (void *)0x0, local_58 == (char *)0x0)))) {
        local_38 = local_68;
        pcStack_30 = (char *)lStack_60;
        pvStack_50 = (void *)_Var3;
        gsl::copy<unsigned_short,_1,unsigned_short,_1>(&local_58,&local_38);
        goto LAB_140013502;
      }
    }
  }
LAB_1400135d7:
                    /* WARNING: Subroutine does not return */
  gsl::details::terminate();
}



===== Stat @ 1400135e4 =====

/* private: long __cdecl p9fs::DirectoryEnumerator::Stat(class std::basic_string_view<char>,class
   p9fs::ICancellationManager * __ptr64) __ptr64 */

long __thiscall p9fs::DirectoryEnumerator::Stat(DirectoryEnumerator *this,size_t *param_2)

{
  P9Client *pPVar1;
  bool bVar2;
  int iVar3;
  char *local_f8;
  char *pcStack_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  P9Client *local_d8;
  undefined4 local_d0;
  char local_c8 [8];
  uint local_c0;
  char local_a8 [8];
  uint local_a0;
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
  
  local_f8 = (char *)*param_2;
  pcStack_f0 = (char *)param_2[1];
  local_d0 = 0xffffffff;
  pPVar1 = *(P9Client **)this;
  bVar2 = false;
  local_d8 = pPVar1;
  if (local_f8 == (char *)0x1) {
    iVar3 = memcmp(pcStack_f0,".",1);
    if (iVar3 != 0) goto LAB_140013653;
    local_c0 = *(uint *)(this + 0x308);
LAB_1400136dd:
    P9Client::GetAttr(*(P9Client **)this,(uint)local_a8,(ulonglong)local_c0,
                      (ICancellationManager *)0xffffffffffffffff);
    if (local_a8[0] == '\0') {
      local_e0 = 0;
      local_f8 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9readdir.cpp";
      pcStack_f0 = "p9fs::DirectoryEnumerator::Stat";
      local_e8 = 0xe7;
      TraceLog((ErrorSite *)&local_f8,local_a0);
      goto LAB_1400137e9;
    }
    *(undefined8 *)(this + 0x80) = local_98;
    *(undefined8 *)(this + 0x88) = uStack_90;
    if (bVar2) {
      *(undefined8 *)(this + 0x80) = 0;
    }
    *(undefined8 *)(this + 0x90) = local_88;
    *(undefined8 *)(this + 0x98) = uStack_80;
    *(undefined8 *)(this + 0xa0) = local_78;
    *(undefined8 *)(this + 0xa8) = uStack_70;
    *(undefined8 *)(this + 0xb0) = local_68;
    *(undefined8 *)(this + 0xb8) = uStack_60;
    *(undefined8 *)(this + 0xc0) = local_58;
    *(undefined8 *)(this + 200) = uStack_50;
    *(undefined8 *)(this + 0xd0) = local_48;
    *(undefined8 *)(this + 0xd8) = uStack_40;
    *(undefined8 *)(this + 0xe0) = local_38;
    *(undefined8 *)(this + 0xe8) = uStack_30;
    *(undefined8 *)(this + 0xf0) = local_28;
    local_a0 = UniqueFid::Reset((UniqueFid *)&local_d8,0xffffffff);
    if (-1 < (int)local_a0) {
      local_a0 = 0;
      goto LAB_1400137e9;
    }
    local_e8 = 0xef;
  }
  else {
LAB_140013653:
    local_f8 = (char *)*param_2;
    pcStack_f0 = (char *)param_2[1];
    if (local_f8 < (char *)0x2) {
      iVar3 = -1;
    }
    else if (local_f8 < (char *)0x3) {
      iVar3 = memcmp(pcStack_f0,&s___,(size_t)local_f8);
    }
    else {
      iVar3 = 1;
    }
    if (iVar3 == 0) {
      bVar2 = true;
      local_c0 = *(uint *)(this + 0x308);
      goto LAB_1400136dd;
    }
    local_f8 = (char *)*param_2;
    pcStack_f0 = (char *)param_2[1];
    P9Client::Walk(pPVar1,local_c8,*(uint *)(this + 0x308));
    if (local_c8[0] != '\0') {
      UniqueFid::Reset((UniqueFid *)&local_d8,local_c0);
      goto LAB_1400136dd;
    }
    local_e8 = 0xe0;
    local_a0 = local_c0;
  }
  local_e0 = 0;
  local_f8 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9readdir.cpp";
  pcStack_f0 = "p9fs::DirectoryEnumerator::Stat";
  TraceLog((ErrorSite *)&local_f8,local_a0);
LAB_1400137e9:
  UniqueFid::Reset((UniqueFid *)&local_d8,0xffffffff);
  return local_a0;
}



===== PathDissectFirst @ 140013820 =====

/* struct p9fs::PathSplitResult __cdecl p9fs::PathDissectFirst(class std::basic_string_view<unsigned
   short>,unsigned short) */

ulonglong * __cdecl p9fs::PathDissectFirst(ulonglong *param_1,ulonglong *param_2,short param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  uVar1 = *param_2;
  if (uVar1 == 0) {
    *param_1 = 0;
    param_1[1] = 0;
    goto LAB_140013839;
  }
  uVar3 = 0;
  if (uVar1 == 0) {
LAB_140013882:
    if (uVar3 <= uVar1) {
      uVar2 = param_2[1];
      uVar4 = uVar3 + 1;
      *param_1 = uVar3;
      param_1[1] = uVar2;
      if ((uVar4 <= uVar1) && (uVar1 - uVar4 != 0xffffffffffffffff)) {
        param_1[2] = uVar1 - uVar4;
        param_1[3] = uVar2 + uVar4 * 2;
        return param_1;
      }
    }
LAB_1400138cc:
                    /* WARNING: Subroutine does not return */
    gsl::details::terminate();
  }
  if (uVar1 == 0) goto LAB_1400138cc;
  do {
    if (*(short *)(param_2[1] + uVar3 * 2) == param_3) goto LAB_140013872;
    uVar3 = uVar3 + 1;
  } while (uVar3 < uVar1);
  if (uVar3 != uVar1) {
LAB_140013872:
    if (uVar3 != 0xffffffffffffffff) goto LAB_140013882;
  }
  uVar1 = param_2[1];
  *param_1 = *param_2;
  param_1[1] = uVar1;
LAB_140013839:
  param_1[2] = 0;
  param_1[3] = 0;
  return param_1;
}



===== PathDissectLast @ 1400138d8 =====

/* struct p9fs::PathSplitResult __cdecl p9fs::PathDissectLast(class std::basic_string_view<unsigned
   short>,unsigned short) */

ulonglong * __cdecl p9fs::PathDissectLast(ulonglong *param_1,ulonglong *param_2,short param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  uVar4 = *param_2;
  if (uVar4 == 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[3] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
  }
  else {
    uVar3 = uVar4;
    uVar1 = uVar4;
    do {
      uVar1 = uVar1 - 1;
      if (uVar4 <= uVar1) goto LAB_140013992;
    } while ((*(short *)(param_2[1] + uVar1 * 2) != param_3) && (uVar3 = uVar3 - 1, uVar3 != 0));
    uVar1 = 0xffffffffffffffff;
    if (uVar3 != 0) {
      uVar1 = uVar3 - 1;
    }
    if (uVar1 == 0xffffffffffffffff) {
      *param_1 = 0;
      param_1[1] = 0;
      uVar4 = *param_2;
      uVar3 = param_2[1];
    }
    else {
      if (uVar4 < uVar1) {
LAB_140013992:
                    /* WARNING: Subroutine does not return */
        gsl::details::terminate();
      }
      uVar3 = param_2[1];
      uVar2 = uVar1 + 1;
      *param_1 = uVar1;
      param_1[1] = uVar3;
      if ((uVar4 < uVar2) || (uVar4 = uVar4 - uVar2, uVar4 == 0xffffffffffffffff))
      goto LAB_140013992;
      uVar3 = uVar3 + uVar2 * 2;
    }
    param_1[2] = uVar4;
    param_1[3] = uVar3;
  }
  return param_1;
}



===== SpanWriterWriteUnicodeString @ 1400139a0 =====

/* void __cdecl p9fs::SpanWriterWriteUnicodeString(class p9fs::SpanWriter & __ptr64,class
   std::basic_string_view<unsigned short>) */

void __cdecl p9fs::SpanWriterWriteUnicodeString(ulonglong *param_1,ulonglong *param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  code *pcVar6;
  longlong lVar7;
  undefined1 *puVar8;
  char local_res10 [4];
  uint local_res14;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  longlong local_28;
  longlong local_20;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if (*param_2 < 0x10000) {
    uVar3 = param_1[2];
    uVar4 = *param_1;
    puVar8 = auStack_48;
    if ((uVar4 < uVar3) || (puVar8 = auStack_48, uVar4 - uVar3 < 2)) goto LAB_140013a82;
    uVar5 = param_1[1];
    uVar1 = uVar3 + 2;
    param_1[2] = uVar1;
    puVar8 = auStack_48;
    if (((uVar4 < uVar1) || (lVar7 = uVar4 - uVar1, puVar8 = auStack_48, lVar7 == -1)) ||
       ((lVar2 = uVar5 + uVar1, lVar2 == 0 && (puVar8 = auStack_48, lVar7 != 0))))
    goto LAB_140013a82;
    local_18 = (undefined4)*param_2;
    uStack_14 = *(undefined4 *)((longlong)param_2 + 4);
    uStack_10 = (undefined4)param_2[1];
    uStack_c = *(undefined4 *)((longlong)param_2 + 0xc);
    local_28 = lVar7;
    local_20 = lVar2;
    StringUnicodeToUtf8(local_res10,&local_18,&local_28);
    if ((local_res10[0] != '\0') && (local_res14 < 0x10000)) {
      *(short *)(uVar5 + uVar3) = (short)local_res14;
      uVar3 = param_1[2];
      puVar8 = auStack_48;
      if ((uVar3 <= *param_1) && (puVar8 = auStack_48, (ulonglong)local_res14 <= *param_1 - uVar3))
      {
        param_1[2] = uVar3 + local_res14;
        return;
      }
      goto LAB_140013a82;
    }
  }
  pcVar6 = (code *)swi(0x29);
  (*pcVar6)(5);
  puVar8 = auStack_40;
LAB_140013a82:
                    /* WARNING: Subroutine does not return */
  *(undefined **)(puVar8 + -8) = &UNK_140013a87;
  gsl::details::terminate();
}



===== StringUnicodeToUtf8 @ 140013a90 =====

/* class util::BasicExpected<unsigned long,long> __cdecl p9fs::StringUnicodeToUtf8(class
   std::basic_string_view<unsigned short>,class gsl::span<char,-1>) */

undefined1 * __cdecl p9fs::StringUnicodeToUtf8(undefined1 *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 local_res10 [6];
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_res10[0] = 0;
  iVar1 = RtlUnicodeToUTF8N(*(undefined8 *)(param_3 + 2),*param_3,local_res10,
                            *(undefined8 *)(param_2 + 2),*param_2 * 2);
  if (iVar1 < 0) {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9util.cpp";
    local_18 = 0x1a;
    local_20 = "p9fs::StringUnicodeToUtf8";
    TraceLog((ErrorSite *)&local_28,iVar1);
    *param_1 = 0;
    *(int *)(param_1 + 4) = iVar1;
  }
  else {
    *(undefined4 *)(param_1 + 4) = local_res10[0];
    *param_1 = 1;
  }
  return param_1;
}



===== StringUnicodeToUtf8 @ 140013b2c =====

/* class util::BasicExpected<class util::DynamicArray<char>,long> __cdecl
   p9fs::StringUnicodeToUtf8(class std::basic_string_view<unsigned short>) */

undefined1 * __cdecl p9fs::StringUnicodeToUtf8(undefined1 *param_1,ulonglong *param_2)

{
  long lVar1;
  void *_Dst;
  char *pcVar2;
  ulonglong uVar3;
  void *pvVar4;
  int iVar5;
  ulonglong uVar6;
  char local_res10 [4];
  uint local_res14;
  ulonglong local_58;
  void *pvStack_50;
  char *local_48;
  char *pcStack_40;
  undefined8 local_38;
  undefined8 local_30;
  
  local_58 = *param_2;
  pvStack_50 = (void *)param_2[1];
  StringUnicodeToUtf8Length(local_res10,&local_58);
  if (local_res10[0] == '\0') {
    local_30 = 0;
    local_48 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9util.cpp";
    local_38 = 0x23;
    pcStack_40 = "p9fs::StringUnicodeToUtf8";
    TraceLog((ErrorSite *)&local_48,local_res14);
    *param_1 = 0;
    *(uint *)(param_1 + 8) = local_res14;
    return param_1;
  }
  uVar6 = (ulonglong)local_res14;
  pvVar4 = (void *)0x0;
  uVar3 = 0;
  _Dst = pvVar4;
  if (uVar6 != 0) {
    _Dst = (void *)ExAllocatePool2(0x40,uVar6,0x78523950);
    if (_Dst == (void *)0x0) {
      local_30 = 0;
      local_48 = "onecore\\vm\\inc\\DynamicArray.h";
      local_38 = 0x3d;
      iVar5 = -0x3fffff66;
      pcStack_40 = "util::DynamicArray<char>::Reset";
      TraceLog((ErrorSite *)&local_48,-0x3fffff66);
      goto LAB_140013c33;
    }
    memset(_Dst,0,(ulonglong)local_res14);
  }
  iVar5 = 0;
  uVar3 = uVar6;
  pvVar4 = _Dst;
LAB_140013c33:
  if (iVar5 < 0) {
    local_30 = 0;
    local_48 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9util.cpp";
    local_38 = 0x25;
    pcStack_40 = "p9fs::StringUnicodeToUtf8";
    TraceLog((ErrorSite *)&local_48,iVar5);
    *(int *)(param_1 + 8) = iVar5;
  }
  else {
    if (uVar3 == 0) {
      local_58 = 0;
      pvStack_50 = (void *)0x0;
    }
    else {
      local_58 = uVar3;
      pvStack_50 = pvVar4;
      if (pvVar4 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        gsl::details::terminate();
      }
    }
    local_48 = (char *)*param_2;
    pcStack_40 = (char *)param_2[1];
    pcVar2 = (char *)StringUnicodeToUtf8(local_res10,&local_48,&local_58);
    if (*pcVar2 != '\0') {
      *param_1 = 1;
      *(void **)(param_1 + 8) = pvVar4;
      *(ulonglong *)(param_1 + 0x10) = uVar3;
      return param_1;
    }
    lVar1 = *(long *)(pcVar2 + 4);
    local_30 = 0;
    local_48 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9util.cpp";
    local_38 = 0x26;
    pcStack_40 = "p9fs::StringUnicodeToUtf8";
    TraceLog((ErrorSite *)&local_48,lVar1);
    *(long *)(param_1 + 8) = lVar1;
  }
  *param_1 = 0;
  if (pvVar4 != (void *)0x0) {
    ExFreePoolWithTag(pvVar4,0);
  }
  return param_1;
}



===== StringUnicodeToUtf8Length @ 140013d28 =====

/* class util::BasicExpected<unsigned long,long> __cdecl p9fs::StringUnicodeToUtf8Length(class
   std::basic_string_view<unsigned short>) */

undefined1 * __cdecl p9fs::StringUnicodeToUtf8Length(undefined1 *param_1,int *param_2)

{
  int iVar1;
  undefined4 local_res10 [6];
  char *local_28;
  char *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_res10[0] = 0;
  iVar1 = RtlUnicodeToUTF8N(0,0,local_res10,*(undefined8 *)(param_2 + 2),*param_2 * 2);
  if (iVar1 < 0) {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9util.cpp";
    local_18 = 0x2f;
    local_20 = "p9fs::StringUnicodeToUtf8Length";
    TraceLog((ErrorSite *)&local_28,iVar1);
    *param_1 = 0;
    *(int *)(param_1 + 4) = iVar1;
  }
  else {
    *(undefined4 *)(param_1 + 4) = local_res10[0];
    *param_1 = 1;
  }
  return param_1;
}



===== StringUtf8ToUnicode @ 140013dbc =====

/* class util::BasicExpected<class gsl::span<unsigned short,-1>,long> __cdecl
   p9fs::StringUtf8ToUnicode(class std::basic_string_view<char>,class gsl::span<unsigned short,-1>)
    */

undefined1 * __cdecl
p9fs::StringUtf8ToUnicode(undefined1 *param_1,undefined4 *param_2,ulonglong *param_3)

{
  ulonglong uVar1;
  int iVar2;
  uint local_res10 [2];
  char *local_28;
  char *pcStack_20;
  undefined8 local_18;
  undefined8 local_10;
  
  uVar1 = param_3[1];
  local_res10[0] = 0;
  iVar2 = RtlUTF8ToUnicodeN(uVar1,(int)*param_3 * 2,local_res10,*(undefined8 *)(param_2 + 2),
                            *param_2);
  if (iVar2 < 0) {
    local_10 = 0;
    local_28 = "onecore\\vm\\dv\\storage\\plan9\\rdr\\lib\\p9util.cpp";
    local_18 = 0x39;
    pcStack_20 = "p9fs::StringUtf8ToUnicode";
    TraceLog((ErrorSite *)&local_28,iVar2);
    *param_1 = 0;
    *(int *)(param_1 + 8) = iVar2;
  }
  else {
    if (*param_3 < (ulonglong)(local_res10[0] >> 1)) {
                    /* WARNING: Subroutine does not return */
      gsl::details::terminate();
    }
    *param_1 = 1;
    *(ulonglong *)(param_1 + 8) = (ulonglong)(local_res10[0] >> 1);
    *(ulonglong *)(param_1 + 0x10) = uVar1;
  }
  return param_1;
}



===== LxUtilLxErrorToNtStatus @ 140013e90 =====

undefined8 LxUtilLxErrorToNtStatus(int param_1,undefined4 *param_2)

{
  ulonglong in_RAX;
  undefined1 uVar1;
  
  uVar1 = 1;
  if (param_1 < -0x16) {
    if (param_1 != -0x17) {
      if (param_1 < -0x26) {
        if (param_1 == -0x27) {
          *param_2 = 0xc0000101;
          goto LAB_140013ee4;
        }
        if ((param_1 == -0x204) || (in_RAX = (ulonglong)(param_1 + 0x202U), param_1 + 0x202U < 3))
        goto switchD_140013f8b_caseD_fffffffc;
        if (param_1 == -0x7c) {
          *param_2 = 0xc0000014;
          goto LAB_140013ee4;
        }
        if (param_1 == -0x7b) {
          *param_2 = 0xc0000013;
          goto LAB_140013ee4;
        }
        if (param_1 == -0x4b) {
          *param_2 = 0xc0000023;
          goto LAB_140013ee4;
        }
        if (param_1 == -0x28) goto LAB_140013f47;
        goto switchD_140013f8b_caseD_ffffffee;
      }
      if (param_1 == -0x24) {
        *param_2 = 0xc0000033;
        goto LAB_140013ee4;
      }
      if (param_1 == -0x22) {
        *param_2 = 0xc0000095;
        goto LAB_140013ee4;
      }
      if (param_1 == -0x20) {
        *param_2 = 0xc000020c;
        goto LAB_140013ee4;
      }
      if (param_1 == -0x1f) {
LAB_140013f47:
        *param_2 = 0xc0000280;
        goto LAB_140013ee4;
      }
      if (param_1 == -0x1e) {
        *param_2 = 0xc00000a2;
        goto LAB_140013ee4;
      }
      in_RAX = (ulonglong)(param_1 + 0x1cU);
      if (param_1 + 0x1cU < 2) {
        *param_2 = 0xc000007f;
        goto LAB_140013ee4;
      }
      if (param_1 != -0x18) goto switchD_140013f8b_caseD_ffffffee;
    }
switchD_140013f8b_caseD_fffffff4:
    *param_2 = 0xc000009a;
    goto LAB_140013ee4;
  }
  if (param_1 + 0x16U < 0x17) {
    in_RAX = (ulonglong)(int)(param_1 + 0x16U);
    switch(param_1) {
    case 0:
      *param_2 = 0;
      break;
    case -0x16:
      *param_2 = 0xc000000d;
      break;
    case -0x15:
      *param_2 = 0xc00000ba;
      break;
    case -0x14:
      *param_2 = 0xc0000103;
      break;
    case -0x13:
      *param_2 = 0xc000009d;
      break;
    default:
      goto switchD_140013f8b_caseD_ffffffee;
    case -0x11:
      *param_2 = 0xc0000035;
      break;
    case -0xe:
      *param_2 = 0xc0000005;
      break;
    case -0xd:
      *param_2 = 0xc0000022;
      break;
    case -0xc:
      goto switchD_140013f8b_caseD_fffffff4;
    case -0xb:
      *param_2 = 0xc000022d;
      break;
    case -9:
      *param_2 = 0xc0000008;
      break;
    case -6:
      *param_2 = 0xc000000e;
      break;
    case -5:
      *param_2 = 0xc0000185;
      break;
    case -4:
switchD_140013f8b_caseD_fffffffc:
      *param_2 = 0xc0000120;
      break;
    case -3:
      *param_2 = 0xc00002f0;
      break;
    case -2:
      *param_2 = 0xc0000034;
      break;
    case -1:
      *param_2 = 0xc00000bb;
    }
  }
  else {
switchD_140013f8b_caseD_ffffffee:
    uVar1 = 0;
    *param_2 = 0xc0000001;
  }
LAB_140013ee4:
  return CONCAT71((int7)(in_RAX >> 8),uVar1);
}



===== __GSHandlerCheck @ 140014048 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14001406c =====

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



===== __cpu_features_init @ 1400140e0 =====

/* WARNING: Removing unreachable block (ram,0x00014001414a) */
/* WARNING: Removing unreachable block (ram,0x0001400140f9) */
/* WARNING: Removing unreachable block (ram,0x0001400140ea) */

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



===== __security_check_cookie @ 1400141b0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1400141f0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140014220 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140014220. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140014250 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 1400142a0 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_1400142e3;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_140014354;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_140014350:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140014354;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_14001434c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140014350;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14001434c;
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
LAB_140014354:
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
LAB_1400142e3:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memmove @ 1400143c0 =====

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



===== memset @ 1400146c0 =====

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



===== __memset_repmovs @ 140014800 =====

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



===== __memset_query @ 140014880 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140014900 =====

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



===== __memset_spec_ermsb_repmovsb @ 140014a40 =====

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



===== __memset_spec_plain @ 140014ac0 =====

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



===== _tlgEnableCallback @ 14001e010 =====

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



===== wil_details_EvaluateFeatureDependencies @ 14001e08c =====

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
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x00014001e0c7;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_14001e141:
  while( true ) {
    if (&UNK_1400198bf < ppuVar3) {
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
      if (&UNK_1400198bf < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x00014001e0c7:
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
      if (&UNK_1400198bf < ppuVar2) goto LAB_14001e141;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_14001e141;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14001e17c =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_14001e218;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_14001e218;
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
LAB_14001e218:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14001e280 =====

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
              if (&UNK_1400198bf < ppuVar2) {
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



===== wil_details_RecordFeatureUsageCallback @ 14001e300 =====

void wil_details_RecordFeatureUsageCallback(void)

{
  RtlRecordFeatureUsage();
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14001e320 =====

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
    if (*ppuVar3 != (undefined *)0x0) goto LAB_14001e41d;
  }
LAB_14001e426:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14001e41d:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14001e426;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14001e3ee:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14001e3ee;
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
    if (&UNK_1400198bf < ppuVar3) goto LAB_14001e426;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14001e41d;
}



===== LxUtilFsFileModeToReparseTag @ 14001e44c =====

undefined8 LxUtilFsFileModeToReparseTag(uint param_1)

{
  undefined8 uVar1;
  uint uVar2;
  
  uVar2 = param_1 & 0xf000;
  if (uVar2 == 0x1000) {
    return 0x80000024;
  }
  if (uVar2 == 0x2000) {
    return 0x80000025;
  }
  if (uVar2 == 0x6000) {
    return 0x80000026;
  }
  if (uVar2 == 0xa000) {
    return 0xa000001d;
  }
  uVar1 = 0x80000023;
  if (uVar2 != 0xc000) {
    uVar1 = 0;
  }
  return uVar1;
}



===== LxUtilNtFileNameEscapeInPlace @ 14001e4a8 =====

void LxUtilNtFileNameEscapeInPlace(ushort *param_1)

{
  undefined8 uVar1;
  ushort *puVar2;
  ushort uVar3;
  ulonglong uVar4;
  
  if (*param_1 >> 1 != 0) {
    puVar2 = *(ushort **)(param_1 + 4);
    uVar4 = (ulonglong)(*param_1 >> 1);
    do {
      uVar3 = *puVar2;
      uVar1 = LxUtilpNtPathCharNeedsEscape(uVar3);
      if ((char)uVar1 != '\0') {
        *puVar2 = uVar3 - 0x1000;
      }
      puVar2 = puVar2 + 1;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  return;
}



===== LxUtilNtPathUnescape @ 14001e4f8 =====

undefined4 LxUtilNtPathUnescape(ushort *param_1,ushort *param_2,undefined8 *param_3)

{
  ushort uVar1;
  short sVar2;
  undefined8 uVar3;
  ushort uVar4;
  ulonglong uVar5;
  ushort uVar6;
  ushort uVar7;
  ushort *puVar8;
  undefined8 uVar9;
  longlong lVar10;
  ushort *local_res8;
  
  uVar1 = *param_1;
  local_res8 = (ushort *)((ulonglong)local_res8 & 0xffffffff00000000);
  uVar6 = uVar1 >> 1;
  uVar5 = 0;
  uVar7 = 0;
  uVar9 = 1;
  if (uVar6 != 0) {
    lVar10 = *(longlong *)(param_1 + 4);
    do {
      uVar7 = (ushort)uVar5;
      sVar2 = *(short *)(lVar10 + uVar5 * 2);
      if ((((ushort)(sVar2 + 0x1000U) < 0x100) && (uVar4 = sVar2 + 0x1000, uVar4 != 0x2f)) &&
         (uVar3 = LxUtilpNtPathCharNeedsEscape(uVar4), (char)uVar3 != '\0')) break;
      uVar7 = uVar7 + (short)uVar9;
      uVar5 = (ulonglong)uVar7;
    } while (uVar7 < uVar6);
  }
  local_res8._0_4_ = 0;
  if (uVar7 == uVar6) {
    uVar9 = *(undefined8 *)param_1;
    uVar3 = *(undefined8 *)(param_1 + 4);
    *param_3 = 0;
    *(undefined8 *)param_2 = uVar9;
    *(undefined8 *)(param_2 + 4) = uVar3;
  }
  else {
    uVar7 = uVar1 + 2;
    if (uVar7 < uVar1) {
      LxUtilNtStatusToLxError(-0x3fffff6b,(undefined4 *)&local_res8);
    }
    else {
      local_res8 = (ushort *)ExAllocatePool2(0x100,uVar7,0x7455784c);
      if (local_res8 == (ushort *)0x0) {
        local_res8._0_4_ = 0xfffffff4;
      }
      else {
        *param_3 = local_res8;
        *(ushort **)(param_2 + 4) = local_res8;
        param_2[1] = uVar7;
        *param_2 = uVar1;
        if (uVar6 != 0) {
          lVar10 = *(longlong *)(param_1 + 4) - (longlong)local_res8;
          uVar5 = (ulonglong)uVar6;
          uVar9 = 0xff;
          puVar8 = local_res8;
          do {
            uVar1 = *(ushort *)(lVar10 + (longlong)puVar8);
            if (((ushort)uVar9 < (ushort)(uVar1 + 0x1000)) ||
               (uVar7 = uVar1 + 0x1000, uVar7 == 0x2f)) {
LAB_14001e63c:
              if (uVar1 == 0x5c) {
                uVar7 = 0x2f;
              }
              else {
                uVar7 = uVar1;
              }
            }
            else {
              uVar3 = LxUtilpNtPathCharNeedsEscape(uVar7);
              if ((char)uVar3 == '\0') goto LAB_14001e63c;
            }
            *puVar8 = uVar7;
            uVar5 = uVar5 - 1;
            puVar8 = puVar8 + 1;
          } while (uVar5 != 0);
        }
        local_res8[uVar6] = 0;
      }
    }
  }
  return local_res8._0_4_;
}



===== LxUtilNtStatusToLxError @ 14001e6a4 =====

undefined8 LxUtilNtStatusToLxError(int param_1,undefined4 *param_2)

{
  ulonglong uVar1;
  undefined1 uVar3;
  undefined1 uVar2;
  
  uVar1 = 0xc00000f0;
  uVar3 = 1;
  uVar2 = 1;
  if (param_1 < -0x3fffff0f) {
    if (param_1 != -0x3fffff10) {
      uVar1 = 0xc0000034;
      if (-0x3fffffcc < param_1) {
        uVar1 = 0xc0000096;
        if (param_1 < -0x3fffff69) {
          if (param_1 != -0x3fffff6a) {
            uVar1 = 0xc000004f;
            if (param_1 < -0x3fffffb0) {
              if (param_1 == -0x3fffffb1) goto LAB_14001e885;
              if (param_1 == -0x3fffffcb) goto LAB_14001ebc2;
              if (param_1 == -0x3fffffc7) goto LAB_14001e721;
              if (param_1 != -0x3fffffc6) {
                if (param_1 == -0x3fffffc5) goto LAB_14001eb57;
                if (param_1 == -0x3fffffbd) goto LAB_14001e87a;
                goto LAB_14001e71e;
              }
            }
            else {
              if (param_1 == -0x3fffffae) {
LAB_14001e8d6:
                *param_2 = 0xffffffc3;
                goto LAB_14001eb5d;
              }
              if (param_1 != -0x3fffffaa) {
                if (param_1 != -0x3fffff9f) {
                  if (param_1 == -0x3fffff81) {
                    *param_2 = 0xffffffe4;
                    goto LAB_14001eb5d;
                  }
                  if (param_1 != -0x3fffff6b) goto LAB_14001ebb2;
                  goto LAB_14001e8c0;
                }
                goto LAB_14001e920;
              }
            }
            goto LAB_14001ea66;
          }
        }
        else {
          uVar1 = 0xc00000be;
          if (-0x3fffff42 < param_1) {
            if (param_1 == -0x3fffff3c) {
              *param_2 = 0xffffff95;
              goto LAB_14001eb5d;
            }
            if (param_1 == -0x3fffff34) goto LAB_14001ea66;
            if (param_1 == -0x3fffff1b) goto LAB_14001e779;
            if (param_1 != -0x3fffff11) goto LAB_14001e71e;
            goto LAB_14001e721;
          }
          if (param_1 == -0x3fffff42) {
            *param_2 = 0xffffff90;
            goto LAB_14001eb5d;
          }
          if (param_1 == -0x3fffff66) {
LAB_14001e7c3:
            *param_2 = 0xfffffff4;
            goto LAB_14001eb5d;
          }
          if (param_1 == -0x3fffff5e) {
            *param_2 = 0xffffffe2;
            goto LAB_14001eb5d;
          }
          if (param_1 == -0x3fffff4b) goto LAB_14001ebca;
          if (param_1 == -0x3fffff46) {
            *param_2 = 0xffffffeb;
            goto LAB_14001eb5d;
          }
          if (param_1 != -0x3fffff45) goto LAB_14001ebb2;
        }
LAB_14001e920:
        *param_2 = 0xffffffff;
        goto LAB_14001eb5d;
      }
      if (param_1 == -0x3fffffcc) {
LAB_14001ea66:
        *param_2 = 0xfffffffe;
        goto LAB_14001eb5d;
      }
      uVar1 = 0xc000000f;
      if (param_1 < -0x3ffffff0) {
        if (param_1 == -0x3ffffff1) goto LAB_14001ea66;
        uVar1 = 0xc0000005;
        if (param_1 < -0x3ffffffa) {
          if (param_1 == -0x3ffffffb) {
            *param_2 = 0xfffffff2;
            goto LAB_14001eb5d;
          }
          if (param_1 != -0x7ffffffb) {
            if (param_1 == -0x7fffffee) goto LAB_14001e8d6;
            if (param_1 == -0x3ffffffe) {
              *param_2 = 0xffffffda;
              goto LAB_14001eb5d;
            }
            if (param_1 == -0x3ffffffd) goto LAB_14001e721;
            if (param_1 != -0x3ffffffc) goto LAB_14001e71e;
          }
LAB_14001e8c0:
          *param_2 = 0xffffffb5;
          goto LAB_14001eb5d;
        }
        if (param_1 == -0x3ffffffa) {
LAB_14001e779:
          *param_2 = 0xfffffffb;
          goto LAB_14001eb5d;
        }
        if (param_1 == -0x3ffffff9) goto LAB_14001e7c3;
        if (param_1 == -0x3ffffff8) goto LAB_14001eb57;
        if (param_1 != -0x3ffffff3) {
          if (param_1 == -0x3ffffff2) goto LAB_14001e76e;
          goto LAB_14001e71e;
        }
      }
      else {
        uVar1 = 0xc000001d;
        if (param_1 < -0x3fffffe2) {
          if ((param_1 == -0x3fffffe3) || (param_1 == -0x3ffffff0)) {
LAB_14001e885:
            *param_2 = 0xffffffa1;
            goto LAB_14001eb5d;
          }
          if (param_1 == -0x3fffffee) goto LAB_14001e779;
          if (param_1 == -0x3fffffed) {
            *param_2 = 0xffffff85;
            goto LAB_14001eb5d;
          }
          if (param_1 == -0x3fffffec) {
            *param_2 = 0xffffff84;
            goto LAB_14001eb5d;
          }
          if (param_1 == -0x3fffffe9) goto LAB_14001e7c3;
        }
        else {
          if (param_1 == -0x3fffffde) {
LAB_14001e87a:
            *param_2 = 0xfffffff3;
            goto LAB_14001eb5d;
          }
          if (param_1 == -0x3fffffdd) goto LAB_14001e8c0;
          if (param_1 == -0x3fffffdc) {
            *param_2 = 0xffffffa5;
            goto LAB_14001eb5d;
          }
          if (param_1 == -0x3fffffcd) goto LAB_14001ea66;
        }
LAB_14001e71e:
        uVar3 = 0;
      }
    }
  }
  else {
    uVar1 = 0xc000011e;
    if (-0x3ffffee2 < param_1) {
      uVar1 = 0xc00002b6;
      if (-0x3ffffd4a < param_1) {
        uVar1 = 0xc01e0114;
        if (param_1 < -0x3fe1feeb) {
          if (param_1 != -0x3fe1feec) {
            if (param_1 == -0x3ffffd10) {
              *param_2 = 0xfffffffd;
              goto LAB_14001eb5d;
            }
            if ((param_1 == -0x3ffffb92) || (param_1 == -0x3fe1fff7)) goto LAB_14001e76e;
            if (param_1 == -0x3fe1ff00) goto LAB_14001e7c3;
            if (param_1 == -0x3fe1fefe) {
              *param_2 = 0xffffff8d;
              goto LAB_14001eb5d;
            }
            uVar1 = (ulonglong)(param_1 + 0x3fe1feeeU);
            if (1 < param_1 + 0x3fe1feeeU) goto LAB_14001e71e;
          }
        }
        else if (param_1 != -0x3fe1feeb) {
          if ((param_1 == -0x3fe1feea) || (param_1 == -0x3fe1fe00)) goto LAB_14001e76e;
          if (param_1 == -0x3fdf0000) goto LAB_14001e87a;
          if (param_1 != 0) {
            if (param_1 == 0x102) goto LAB_14001ebca;
            if (param_1 != 0x40000000) goto LAB_14001ebb2;
            goto LAB_14001ebc2;
          }
LAB_14001ebbd:
          *param_2 = 0;
          goto LAB_14001eb5d;
        }
LAB_14001eb57:
        *param_2 = 0xfffffff7;
        goto LAB_14001eb5d;
      }
      if (param_1 == -0x3ffffd4a) {
LAB_14001e76e:
        *param_2 = 0xffffffed;
        goto LAB_14001eb5d;
      }
      uVar1 = 0xc000022a;
      if (param_1 < -0x3ffffdd5) {
        if (param_1 != -0x3ffffdd6) {
          if (param_1 == -0x3ffffee0) {
            *param_2 = 0xfffffffc;
            goto LAB_14001eb5d;
          }
          if (param_1 == -0x3ffffedf) goto LAB_14001e779;
          if (param_1 == -0x3ffffed3) goto LAB_14001e7c3;
          if (param_1 == -0x3ffffe9f) goto LAB_14001e721;
          if (param_1 == -0x3ffffdf6) {
            *param_2 = 0xffffff9e;
            goto LAB_14001eb5d;
          }
          if (param_1 == -0x3ffffdf4) {
            *param_2 = 0xffffffe0;
            goto LAB_14001eb5d;
          }
          if (param_1 == -0x3ffffdf3) {
            *param_2 = 0xffffff98;
            goto LAB_14001eb5d;
          }
          if (param_1 == -0x3ffffddb) goto LAB_14001ea66;
LAB_14001ebb2:
          uVar2 = 0;
          uVar3 = uVar2;
          if (-1 < param_1) goto LAB_14001ebbd;
          goto LAB_14001e721;
        }
      }
      else if (param_1 != -0x3ffffdd5) {
        if (param_1 == -0x3ffffdd3) {
LAB_14001ebca:
          *param_2 = 0xfffffff5;
          goto LAB_14001eb5d;
        }
        if (param_1 == -0x3ffffdca) {
          *param_2 = 0xffffff91;
          goto LAB_14001eb5d;
        }
        if (param_1 == -0x3ffffdc4) {
          *param_2 = 0xffffff9b;
          goto LAB_14001eb5d;
        }
        if (param_1 == -0x3ffffdc3) {
          *param_2 = 0xffffff8f;
          goto LAB_14001eb5d;
        }
        if (param_1 == -0x3ffffdbf) {
          *param_2 = 0xffffff99;
          goto LAB_14001eb5d;
        }
        if (param_1 == -0x3ffffd87) {
          *param_2 = 0xfffffffa;
          goto LAB_14001eb5d;
        }
        goto LAB_14001ebb2;
      }
LAB_14001ebc2:
      *param_2 = 0xffffffef;
      goto LAB_14001eb5d;
    }
    if (param_1 == -0x3ffffee2) {
      *param_2 = 0xfffffff8;
      goto LAB_14001eb5d;
    }
    if (param_1 < -0x3fffff08) {
      uVar1 = (ulonglong)(param_1 + 0x3fffff0fU);
      if (6 < param_1 + 0x3fffff0fU) goto LAB_14001e71e;
    }
    else {
      uVar1 = (ulonglong)(param_1 + 0x3fffff08U);
      if (2 < param_1 + 0x3fffff08U) {
        if (param_1 == -0x3ffffeff) {
          *param_2 = 0xffffffd9;
          goto LAB_14001eb5d;
        }
        if (param_1 == -0x3ffffefd) {
          *param_2 = 0xffffffec;
          goto LAB_14001eb5d;
        }
        goto LAB_14001ebb2;
      }
    }
  }
LAB_14001e721:
  uVar2 = uVar3;
  *param_2 = 0xffffffea;
LAB_14001eb5d:
  return CONCAT71((int7)(uVar1 >> 8),uVar2);
}



===== LxUtilNtTimeToTimespec @ 14001ebd8 =====

void LxUtilNtTimeToTimespec(longlong *param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  if (param_2 < 0x19db1ded53e8001) {
    lVar2 = 0;
  }
  else {
    lVar2 = param_2 + -0x19db1ded53e8000;
  }
  lVar1 = SUB168(SEXT816(-0x29406b2a1a85bd43) * SEXT816(lVar2),8) + lVar2;
  lVar1 = (lVar1 >> 0x17) - (lVar1 >> 0x3f);
  *param_1 = lVar1;
  param_1[1] = (lVar2 + lVar1 * -10000000) * 100;
  return;
}



===== LxUtilTimespecToNtTime @ 14001ec2c =====

void LxUtilTimespecToNtTime(ulonglong *param_1,longlong *param_2)

{
  ulonglong uVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  bool bVar5;
  
  lVar3 = *param_2 * 10000000;
  lVar4 = SUB168(SEXT816(10000000) * SEXT816(*param_2),8);
  if (lVar3 < 0) {
    bVar5 = lVar4 == -1;
  }
  else {
    bVar5 = lVar4 == 0;
  }
  if (bVar5) {
    lVar4 = SUB168(SEXT816(-0x5c28f5c28f5c28f5) * SEXT816(param_2[1] + 99),8) + param_2[1] + 99;
    lVar4 = (lVar4 >> 6) - (lVar4 >> 0x3f);
    uVar1 = lVar3 + lVar4;
    iVar2 = (int)(lVar3 >> 0x3f);
    if ((-iVar2 != -(int)(lVar4 >> 0x3f)) || (-(uint)(0x7fffffffffffffff < uVar1) == iVar2)) {
      if (((longlong)uVar1 < 0) ||
         (-(uint)(0x7fffffffffffffff < uVar1 + 0x19db1ded53e8000) == (int)((longlong)uVar1 >> 0x3f))
         ) {
        *param_1 = uVar1 + 0x19db1ded53e8000;
        return;
      }
    }
  }
  *param_1 = 0x7fffffffffffffff;
  return;
}



===== LxUtilpNtPathCharNeedsEscape @ 14001ecdc =====

undefined8 LxUtilpNtPathCharNeedsEscape(ushort param_1)

{
  code *pcVar1;
  undefined1 uVar2;
  
  pcVar1 = (code *)0x0;
  uVar2 = 0;
  if ((param_1 < 0x100) &&
     ((param_1 == 0x3a ||
      ((-1 < (char)param_1 &&
       (pcVar1 = FsRtlLegalAnsiCharacterArray_exref,
       (*(byte *)((ulonglong)param_1 + *(longlong *)FsRtlLegalAnsiCharacterArray_exref) & 4) == 0)))
      ))) {
    uVar2 = 1;
  }
  return CONCAT71((int7)((ulonglong)pcVar1 >> 8),uVar2);
}



===== entry @ 14001f010 =====

void entry(_DRIVER_OBJECT *param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 14001f044 =====

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



===== wil_InitializeFeatureStaging @ 14001f078 =====

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
      if (*ppuVar3 != (undefined *)0x0) goto LAB_14001f0ff;
    }
LAB_14001f139:
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
LAB_14001f0ff:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14001f139;
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
    goto LAB_14001f139;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_1400198bf < ppuVar3) goto LAB_14001f139;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14001f0ff;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14001f18c =====

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
            if (&UNK_1400198bf < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_14001f276;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_14001f276;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_14001f276:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_1400198bf < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


