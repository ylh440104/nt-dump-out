
===== _tlgWriteTransfer_EtwWriteTransfer @ 180001008 =====

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



===== `dynamic_initializer_for_'Aes128Sha1Registrar'' @ 1800010b0 =====

void Kerb3961::_dynamic_initializer_for__Aes128Sha1Registrar__(void)

{
  code *pcVar1;
  undefined8 uVar2;
  
  uVar2 = RegisterCipherSuite((EncryptionAlgorithm *)
                              &
                              PTR__vftable__for__Kerb3961__VersionedEncryptionAlgorithm<1>___180018040
                              ,(longlong *)
                               &
                               PTR__vftable__for__Kerb3961__VersionedChecksumAlgorithm<1>___180018048
                             );
  if ((char)uVar2 == '\0') {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(0x29c);
  }
  return;
}



===== `dynamic_initializer_for_'Aes256Sha1Registrar'' @ 1800010e0 =====

void Kerb3961::_dynamic_initializer_for__Aes256Sha1Registrar__(void)

{
  code *pcVar1;
  undefined8 uVar2;
  
  uVar2 = RegisterCipherSuite((EncryptionAlgorithm *)
                              &
                              PTR__vftable__for__Kerb3961__VersionedEncryptionAlgorithm<1>___1800180e0
                              ,(longlong *)
                               &
                               PTR__vftable__for__Kerb3961__VersionedChecksumAlgorithm<1>___1800180e8
                             );
  if ((char)uVar2 == '\0') {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(0x29c);
  }
  return;
}



===== `dynamic_initializer_for_'Aes128Sha2Registrar'' @ 180001110 =====

void Kerb3961::_dynamic_initializer_for__Aes128Sha2Registrar__(void)

{
  code *pcVar1;
  undefined8 uVar2;
  
  uVar2 = RegisterCipherSuite((EncryptionAlgorithm *)
                              &
                              PTR__vftable__for__Kerb3961__VersionedEncryptionAlgorithm<1>___180018180
                              ,(longlong *)
                               &
                               PTR__vftable__for__Kerb3961__VersionedChecksumAlgorithm<1>___180018188
                             );
  if ((char)uVar2 == '\0') {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(0x29c);
  }
  return;
}



===== `dynamic_initializer_for_'Aes256Sha2Registrar'' @ 180001140 =====

void Kerb3961::_dynamic_initializer_for__Aes256Sha2Registrar__(void)

{
  code *pcVar1;
  undefined8 uVar2;
  
  uVar2 = RegisterCipherSuite((EncryptionAlgorithm *)
                              &
                              PTR__vftable__for__Kerb3961__VersionedEncryptionAlgorithm<1>___180018200
                              ,(longlong *)
                               &
                               PTR__vftable__for__Kerb3961__VersionedChecksumAlgorithm<1>___180018208
                             );
  if ((char)uVar2 == '\0') {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(0x29c);
  }
  return;
}



===== `dynamic_initializer_for_'g_keyUsageMap'' @ 180001170 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Kerb3961::_dynamic_initializer_for__g_keyUsageMap__
               (_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
                *param_1,
               pair<utl::_TreeNode<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>*___ptr64,bool>
               *param_2)

{
  KeyUsageMap *pKVar1;
  undefined8 *puVar2;
  pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_> **pppVar3;
  longlong local_res8;
  undefined8 local_28;
  undefined8 uStack_20;
  nothrow_t local_18 [16];
  
  DAT_180018298 = 0;
  DAT_180018288 = &g_keyUsageMap;
  pppVar3 = &KeyUsageMap::c_keyUsageData;
  DAT_180018290 = &g_keyUsageMap;
  do {
    if (DAT_180018290 == &g_keyUsageMap) {
      param_1 = (_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
                 *)0x28;
      pKVar1 = operator_new__(0x28,(nothrow_t *)param_2);
      if (pKVar1 == (KeyUsageMap *)0x0) goto LAB_1800012a2;
      *(pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_> **)(pKVar1 + 0x18) =
           *pppVar3;
      *(undefined4 *)(pKVar1 + 0x20) = *(undefined4 *)((longlong)pppVar3 + 8);
      pKVar1[0x24] = *(KeyUsageMap *)((longlong)pppVar3 + 0xc);
      *(undefined **)pKVar1 = &DAT_180018281;
      *(void ***)(pKVar1 + 8) = &utl::_TreeSentinel;
      *(void ***)(pKVar1 + 0x10) = &utl::_TreeSentinel;
      DAT_180018298 = DAT_180018298 + 1;
      _g_keyUsageMap = pKVar1;
      DAT_180018288 = pKVar1;
      DAT_180018290 = pKVar1;
LAB_18000126c:
      if (pKVar1 == (KeyUsageMap *)0x0) {
LAB_1800012a2:
                    /* WARNING: Subroutine does not return */
        ConsistencyFail((ushort *)L"Allocation failure during initialization");
      }
    }
    else {
      local_res8 = 0;
      param_2 = (pair<utl::_TreeNode<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>*___ptr64,bool>
                 *)local_18;
      puVar2 = (undefined8 *)
               utl::
               _Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
               ::_FindInsertionPointUnique
                         (param_1,(_TreeNode<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>
                                   **)param_2,(KeyUsage *)&local_res8,
                          (_TreeNode<struct_utl::pair<enum_Kerb3961::KeyUsage_const_,struct_Kerb3961::KeyPolicyScenario_const_>_>
                           *)pppVar3);
      local_28 = *puVar2;
      uStack_20 = puVar2[1];
      if (local_res8 == 0) {
        param_1 = (_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
                   *)0x28;
        pKVar1 = operator_new__(0x28,(nothrow_t *)param_2);
        if (pKVar1 == (KeyUsageMap *)0x0) goto LAB_1800012a2;
        param_2 = (pair<utl::_TreeNode<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>*___ptr64,bool>
                   *)&local_28;
        *(pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_> **)(pKVar1 + 0x18) =
             *pppVar3;
        *(undefined4 *)(pKVar1 + 0x20) = *(undefined4 *)((longlong)pppVar3 + 8);
        *(_TreeNode<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_> *)
         (pKVar1 + 0x24) =
             *(_TreeNode<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_> *
              )((longlong)pppVar3 + 0xc);
        utl::
        _Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
        ::_InsertAt(param_1,param_2,
                    (_TreeNode<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>
                     *)pKVar1);
        goto LAB_18000126c;
      }
    }
    pppVar3 = (pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_> **)
              ((longlong)pppVar3 + 0x10);
    if (pppVar3 ==
        (pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_> **)
        "m_components.emplace_back(utl::move(buffer))") {
      atexit(_dynamic_atexit_destructor_for__g_keyUsageMap__);
      return;
    }
  } while( true );
}



===== `dynamic_initializer_for_'Feature_RC4Deprecation'' @ 1800012c0 =====

void Kerb3961::Velocity::_dynamic_initializer_for__Feature_RC4Deprecation__(void)

{
  ulonglong uVar1;
  
  uVar1 = Feature_RC4Deprecation__private_IsEnabledDeviceUsageNoInline();
  Feature_RC4Deprecation = (int)uVar1 != 0;
  return;
}



===== `dynamic_initializer_for_'g_domainCipherPolicy'' @ 1800012e0 =====

void Kerb3961::_dynamic_initializer_for__g_domainCipherPolicy__
               (undefined8 param_1,undefined4 param_2)

{
  CipherPolicyImpl::CipherPolicyImpl(&g_domainCipherPolicy,CONCAT31((int3)((uint)param_2 >> 8),2));
  atexit(_dynamic_atexit_destructor_for__g_domainCipherPolicy__);
  return;
}



===== `dynamic_initializer_for_'g_localCipherPolicy'' @ 180001310 =====

void Kerb3961::_dynamic_initializer_for__g_localCipherPolicy__
               (undefined8 param_1,undefined4 param_2)

{
  CipherPolicyImpl::CipherPolicyImpl(&g_localCipherPolicy,CONCAT31((int3)((uint)param_2 >> 8),1));
  atexit(_dynamic_atexit_destructor_for__g_localCipherPolicy__);
  return;
}



===== `dynamic_initializer_for_'RC4Registrar'' @ 180001340 =====

void Kerb3961::_dynamic_initializer_for__RC4Registrar__(void)

{
  code *pcVar1;
  undefined8 uVar2;
  
  uVar2 = RegisterCipherSuite((EncryptionAlgorithm *)&DAT_1800182a0,
                              (longlong *)
                              &
                              PTR__vftable__for__Kerb3961__VersionedChecksumAlgorithm<1>___1800182a8
                             );
  if ((char)uVar2 == '\0') {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(0x29c);
  }
  return;
}



===== `dynamic_initializer_for_'g_checksums'' @ 180001370 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Kerb3961::_dynamic_initializer_for__g_checksums__(void)

{
  _DAT_180018348 = 0;
  DAT_180018338 = &g_checksums;
  DAT_180018340 = &g_checksums;
  atexit(_dynamic_atexit_destructor_for__g_checksums__);
  return;
}



===== `dynamic_initializer_for_'g_cipherLock'' @ 1800013b0 =====

void Kerb3961::_dynamic_initializer_for__g_cipherLock__(void)

{
  ExInitializePushLock(&g_cipherLock);
  return;
}



===== `dynamic_initializer_for_'g_encryptions'' @ 1800013e0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Kerb3961::_dynamic_initializer_for__g_encryptions__(void)

{
  _DAT_180018328 = 0;
  DAT_180018318 = &g_encryptions;
  DAT_180018320 = &g_encryptions;
  atexit(_dynamic_atexit_destructor_for__g_encryptions__);
  return;
}



===== `dynamic_initializer_for_'initializationSentinel'' @ 180001420 =====

void Kerb3961::_dynamic_initializer_for__initializationSentinel__(void)

{
  g_dynamicInitializationDone = true;
  return;
}



===== __report_gsfailure @ 180001440 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== BCryptEncrypt @ 180001450 =====

NTSTATUS __stdcall
BCryptEncrypt(BCRYPT_KEY_HANDLE hKey,PUCHAR pbInput,ULONG cbInput,void *pPaddingInfo,PUCHAR pbIV,
             ULONG cbIV,PUCHAR pbOutput,ULONG cbOutput,ULONG *pcbResult,ULONG dwFlags)

{
  NTSTATUS NVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180001450. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  NVar1 = BCryptEncrypt(hKey,pbInput,cbInput,pPaddingInfo,pbIV,cbIV,pbOutput,cbOutput,pcbResult,
                        dwFlags);
  return NVar1;
}



===== BCryptDecrypt @ 180001470 =====

NTSTATUS __stdcall
BCryptDecrypt(BCRYPT_KEY_HANDLE hKey,PUCHAR pbInput,ULONG cbInput,void *pPaddingInfo,PUCHAR pbIV,
             ULONG cbIV,PUCHAR pbOutput,ULONG cbOutput,ULONG *pcbResult,ULONG dwFlags)

{
  NTSTATUS NVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000180001470. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  NVar1 = BCryptDecrypt(hKey,pbInput,cbInput,pPaddingInfo,pbIV,cbIV,pbOutput,cbOutput,pcbResult,
                        dwFlags);
  return NVar1;
}



===== Concatenate<4> @ 180001484 =====

/* WARNING: Removing unreachable block (ram,0x000180001554) */
/* struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct Kerb3961::ResultBlock const &
   __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::OwnedBinary,16>(struct
   Kerb3961::OwnedBinary const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)>
   __cdecl Kerb3961::Concatenate<4>(struct utl::array<struct Kerb3961::ReadOnlyBinary const ,4>) */

ulonglong * __cdecl Kerb3961::Concatenate<4>(ulonglong *param_1,ulonglong *param_2)

{
  ulonglong *puVar1;
  size_t _Size;
  ulonglong *puVar2;
  char *pcVar3;
  ulonglong uVar4;
  void *_Dst;
  void *local_38 [2];
  
  puVar1 = param_2 + 8;
  uVar4 = 0;
  puVar2 = param_2;
  do {
    if (puVar2 == puVar1) {
      if (uVar4 < 0x100000000) {
        if (uVar4 == 0) {
          *param_1 = 0;
          param_1[1] = 0;
        }
        else {
          utl::make_unique<unsigned_char_[0],0>((__uint64)local_38);
          if (local_38[0] == (void *)0x0) {
            Logging::Verify::ConditionFailed("result");
            *param_1 = 0;
            param_1[1] = 0;
            *(undefined4 *)(param_1 + 2) = 0xc0000017;
            return param_1;
          }
          _Dst = local_38[0];
          for (; param_2 != puVar1; param_2 = param_2 + 2) {
            _Size = *param_2;
            memmove(_Dst,(void *)param_2[1],_Size);
            _Dst = (void *)((longlong)_Dst + _Size);
          }
          *param_1 = uVar4;
          param_1[1] = (ulonglong)local_38[0];
        }
        *(undefined4 *)(param_1 + 2) = 0;
      }
      else {
        pcVar3 = "length <= utl::numeric_limits<uint32_t>::max()";
LAB_180001565:
        Logging::Verify::ConditionFailed(pcVar3);
        *param_1 = 0;
        param_1[1] = 0;
        *(undefined4 *)(param_1 + 2) = 0xc0000095;
      }
      return param_1;
    }
    if (0xffffffff < *puVar2) {
      pcVar3 = "entry.length <= utl::numeric_limits<uint32_t>::max()";
      goto LAB_180001565;
    }
    uVar4 = uVar4 + *puVar2;
    puVar2 = puVar2 + 2;
  } while( true );
}



===== Split<2> @ 18000159c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* struct utl::array<struct Kerb3961::MutableBinary const ,2> __cdecl Kerb3961::Split<2>(struct
   Kerb3961::MutableBinary const & __ptr64,struct utl::array<unsigned __int64,2>) */

longlong * __cdecl Kerb3961::Split<2>(longlong *param_1,ulonglong *param_2,longlong param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong *plVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined1 auStack_58 [32];
  longlong local_38 [6];
  
  local_38[4] = __security_cookie ^ (ulonglong)auStack_58;
  uVar2 = param_2[1];
  plVar4 = local_38;
  uVar5 = 0;
  uVar6 = 0;
  do {
    lVar3 = *(longlong *)(param_3 + uVar6 * 8);
    lVar1 = uVar2 + uVar5;
    *plVar4 = lVar3;
    uVar5 = uVar5 + lVar3;
    uVar6 = uVar6 + 1;
    plVar4[1] = lVar1;
    plVar4 = plVar4 + 2;
  } while (uVar6 < 2);
  if (*param_2 < uVar5) {
                    /* WARNING: Subroutine does not return */
    ConsistencyFail((ushort *)L"Splitting buffer into parts that exceed the whole");
  }
  *param_1 = local_38[0];
  param_1[1] = local_38[1];
  param_1[2] = local_38[2];
  param_1[3] = local_38[3];
  return param_1;
}



===== Split<2> @ 180001630 =====

/* struct utl::array<struct Kerb3961::ReadOnlyBinary const ,2> const __cdecl
   Kerb3961::Split<2>(struct Kerb3961::ReadOnlyBinary const & __ptr64,struct utl::array<unsigned
   __int64,2>) */

ReadOnlyBinary * __cdecl
Kerb3961::Split<2>(ReadOnlyBinary *param_1,ulonglong *param_2,longlong param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  ReadOnlyBinary *pRVar5;
  
  lVar4 = 2;
  uVar3 = 0;
  pRVar5 = param_1;
  do {
    ReadOnlyBinary::ReadOnlyBinary(pRVar5);
    pRVar5 = pRVar5 + 0x10;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  uVar2 = 0;
  pRVar5 = param_1;
  do {
    lVar4 = *(longlong *)(param_3 + uVar2 * 8);
    uVar2 = uVar2 + 1;
    lVar1 = param_2[1] + uVar3;
    *(longlong *)pRVar5 = lVar4;
    uVar3 = uVar3 + lVar4;
    *(longlong *)(pRVar5 + 8) = lVar1;
    pRVar5 = pRVar5 + 0x10;
  } while (uVar2 < 2);
  if (*param_2 < uVar3) {
                    /* WARNING: Subroutine does not return */
    ConsistencyFail((ushort *)L"Splitting buffer into parts that exceed the whole");
  }
  return param_1;
}



===== Split<3> @ 1800016cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* struct utl::array<struct Kerb3961::MutableBinary const ,3> __cdecl Kerb3961::Split<3>(struct
   Kerb3961::MutableBinary const & __ptr64,struct utl::array<unsigned __int64,3>) */

longlong * __cdecl Kerb3961::Split<3>(longlong *param_1,ulonglong *param_2,longlong param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong *plVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined1 auStack_68 [32];
  longlong local_48 [5];
  longlong lStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  uVar2 = param_2[1];
  plVar4 = local_48;
  uVar5 = 0;
  uVar6 = 0;
  do {
    lVar3 = *(longlong *)(param_3 + uVar6 * 8);
    lVar1 = uVar2 + uVar5;
    *plVar4 = lVar3;
    uVar5 = uVar5 + lVar3;
    uVar6 = uVar6 + 1;
    plVar4[1] = lVar1;
    plVar4 = plVar4 + 2;
  } while (uVar6 < 3);
  if (*param_2 < uVar5) {
                    /* WARNING: Subroutine does not return */
    ConsistencyFail((ushort *)L"Splitting buffer into parts that exceed the whole");
  }
  *param_1 = local_48[0];
  param_1[1] = local_48[1];
  param_1[2] = local_48[2];
  param_1[3] = local_48[3];
  param_1[4] = local_48[4];
  param_1[5] = lStack_20;
  return param_1;
}



===== make_unique<unsigned_char_[0],0> @ 180001768 =====

/* class utl::unique_ptr<unsigned char [0],struct utl::default_delete<unsigned char [0]> > __cdecl
   utl::make_unique<unsigned char [0],0>(unsigned __int64) */

__uint64 __cdecl utl::make_unique<unsigned_char_[0],0>(__uint64 param_1)

{
  void *_Dst;
  __uint64 in_RDX;
  
  _Dst = operator_new__(in_RDX,(nothrow_t *)in_RDX);
  if (_Dst == (void *)0x0) {
    _Dst = (void *)0x0;
  }
  else {
    memset(_Dst,0,in_RDX);
  }
  *(void **)param_1 = _Dst;
  return param_1;
}



===== make_unique<Kerb3961::SimplifiedSpecificKey,0> @ 1800017bc =====

/* class utl::unique_ptr<struct Kerb3961::SimplifiedSpecificKey,struct utl::default_delete<struct
   Kerb3961::SimplifiedSpecificKey> > __cdecl utl::make_unique<struct
   Kerb3961::SimplifiedSpecificKey,0>(void) */

void __cdecl utl::make_unique<Kerb3961::SimplifiedSpecificKey,0>(void)

{
  void *_Dst;
  undefined8 *in_RCX;
  nothrow_t *in_RDX;
  
  _Dst = operator_new__(0x48,in_RDX);
  if (_Dst == (void *)0x0) {
    _Dst = (void *)0x0;
  }
  else {
    memset(_Dst,0,0x48);
    *(undefined4 *)((longlong)_Dst + 0x10) = 0xc0000001;
    *(undefined8 *)((longlong)_Dst + 0x20) = 0;
    *(undefined4 *)((longlong)_Dst + 0x28) = 0xc0000001;
    *(undefined8 *)((longlong)_Dst + 0x30) = 0;
    *(undefined8 *)((longlong)_Dst + 0x38) = 0;
    *(undefined4 *)((longlong)_Dst + 0x40) = 0xc0000001;
  }
  *in_RCX = _Dst;
  return;
}



===== ReadOnlyBinary @ 180001824 =====

/* public: __cdecl Kerb3961::ReadOnlyBinary::ReadOnlyBinary(void) __ptr64 */

ReadOnlyBinary * __thiscall Kerb3961::ReadOnlyBinary::ReadOnlyBinary(ReadOnlyBinary *this)

{
  *(undefined8 *)this = 0;
  *(undefined8 *)(this + 8) = 0;
  return this;
}



===== `vcall'{160,{flat}}'_}' @ 180001838 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* [thunk]: __cdecl Kerb3961::EncryptionAlgorithm::`vcall'{160,{flat}}' }' */

void __thiscall Kerb3961::EncryptionAlgorithm::_vcall__160__flat______(EncryptionAlgorithm *this)

{
  (**(code **)(*(longlong *)this + 0xa0))();
  return;
}



===== `vcall'{176,{flat}}'_}' @ 180001850 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* [thunk]: __cdecl Kerb3961::EncryptionAlgorithm::`vcall'{176,{flat}}' }' */

void __thiscall Kerb3961::EncryptionAlgorithm::_vcall__176__flat______(EncryptionAlgorithm *this)

{
  (**(code **)(*(longlong *)this + 0xb0))();
  return;
}



===== LoadCipherPolicy @ 180001870 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::StatusOnly,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly & __ptr64)> __cdecl
   Kerb3961::Aes3962::LoadCipherPolicy(std::nullptr_t) __ptr64 */

undefined4 * __thiscall Kerb3961::Aes3962::LoadCipherPolicy(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0;
  return param_2;
}



===== BlockDecrypt @ 180001880 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::StatusOnly,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly & __ptr64)> __cdecl
   Kerb3961::Aes3962::BlockDecrypt(struct Kerb3961::ReadOnlyBinary const & __ptr64,struct
   Kerb3961::MutableBinary const & __ptr64,struct Kerb3961::MutableBinary const & __ptr64) __ptr64
    */

ReadOnlyBinary * __thiscall
Kerb3961::Aes3962::BlockDecrypt
          (Aes3962 *this,ReadOnlyBinary *param_1,MutableBinary *param_2,MutableBinary *param_3)

{
  ulonglong *in_stack_00000028;
  
  if (*in_stack_00000028 < 0x10) {
    Logging::Verify::ConditionFailed("cipherText.length >= AES_BLOCK_SIZE");
    *(undefined4 *)param_1 = 0xc0000023;
  }
  else {
    DecryptCTS(param_1,*(__uint64 *)(this + 0x80),(ReadOnlyBinary *)param_2,param_2,param_3);
  }
  return param_1;
}



===== BlockEncrypt @ 1800018e0 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::StatusOnly,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly & __ptr64)> __cdecl
   Kerb3961::Aes3962::BlockEncrypt(struct Kerb3961::ReadOnlyBinary const & __ptr64,struct
   Kerb3961::MutableBinary const & __ptr64,struct Kerb3961::MutableBinary const & __ptr64) __ptr64
    */

ReadOnlyBinary * __thiscall
Kerb3961::Aes3962::BlockEncrypt
          (Aes3962 *this,ReadOnlyBinary *param_1,MutableBinary *param_2,MutableBinary *param_3)

{
  ulonglong *in_stack_00000028;
  
  if (*in_stack_00000028 < 0x10) {
    Logging::Verify::ConditionFailed("clearText.length >= AES_BLOCK_SIZE");
    *(undefined4 *)param_1 = 0xc0000023;
  }
  else {
    EncryptCTS(param_1,*(__uint64 *)(this + 0x80),(ReadOnlyBinary *)param_2,param_2,param_3);
  }
  return param_1;
}



===== ChecksumEnabledForAccount @ 180001940 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: virtual bool __cdecl Kerb3961::Aes3962::ChecksumEnabledForAccount(struct
   Kerb3961::KeyPolicyScenario,unsigned int,enum Kerb3961::UserPolicyAttributes) __ptr64 */

bool __thiscall
Kerb3961::Aes3962::ChecksumEnabledForAccount
          (Aes3962 *this,uint *param_2,uint param_3,ulonglong param_4)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  bool bVar4;
  ulonglong uVar5;
  CipherPolicyImpl *pCVar6;
  uint *puVar7;
  uint local_58;
  byte local_54;
  uint local_48;
  undefined1 local_44;
  longlong *local_38;
  longlong lStack_30;
  longlong *local_28;
  longlong lStack_20;
  longlong *local_18 [2];
  
  uVar5 = Feature_184236346__private_IsEnabledDeviceUsageNoInline();
  bVar1 = (byte)param_2[1];
  if ((int)uVar5 == 0) {
    local_58 = *param_2;
    if ((((bVar1 & 0x20) != 0) || (((char)uVar5 + 8U & bVar1) == 0)) && ((param_4 >> 0x39 & 1) != 0)
       ) {
      return true;
    }
    puVar7 = &local_58;
    local_54 = bVar1;
    goto LAB_180001ab6;
  }
  if (((bVar1 & 0x28) != 8) && ((param_4 >> 0x39 & 1) != 0)) {
    bVar2 = 0x10;
    if (*(longlong *)(this + 0x38) == 0x10) {
      bVar2 = 8;
    }
    local_58 = (uint)bVar2;
    param_3 = param_3 | local_58;
  }
  if ((short)param_3 == 0) {
    local_58 = 0;
    if ((param_4 & 0x87) == 0) {
      pCVar6 = (CipherPolicyImpl *)0x0;
      if ((bVar1 & 2) == 0) {
        pCVar6 = &g_localCipherPolicy;
      }
      local_28 = (longlong *)0x0;
      lStack_20 = 0;
      local_38 = (longlong *)0x0;
      lStack_30 = 0;
      (**(code **)(*(longlong *)pCVar6 + 0x68))
                (0,local_18,0xffffff76,0x8000000000000008,&local_38,&local_28);
      if (lStack_30 != 0) {
        (**(code **)(*local_38 + 0x38))(local_38,&local_38);
      }
      if (lStack_20 != 0) {
        (**(code **)(*local_28 + 0x38))(local_28,&local_28);
      }
      if (local_18[0] == (longlong *)0x0) goto LAB_180001aa0;
      local_48 = *param_2;
      local_44 = (undefined1)param_2[1];
      cVar3 = (**(code **)(*local_18[0] + 0x40))(local_18[0],&local_48,param_3,param_4);
      local_58 = CONCAT31(local_58._1_3_,0x20);
      if (cVar3 == '\0') goto LAB_180001aa0;
    }
    else {
LAB_180001aa0:
      local_58 = CONCAT31(local_58._1_3_,0x18);
    }
    param_3 = local_58;
  }
  local_48 = *param_2;
  puVar7 = &local_48;
  local_44 = (undefined1)param_2[1];
LAB_180001ab6:
  bVar4 = EnabledForUsage(this + -8,puVar7,param_3);
  return bVar4;
}



===== ChecksumEnabledForUsage @ 180001af0 =====

/* private: virtual bool __cdecl Kerb3961::Aes3962::ChecksumEnabledForUsage(struct
   Kerb3961::KeyPolicyScenario,unsigned int) __ptr64 */

bool __thiscall Kerb3961::Aes3962::ChecksumEnabledForUsage(Aes3962 *this,undefined4 *param_2)

{
  bool bVar1;
  undefined4 local_res8;
  undefined1 local_resc;
  
  local_res8 = *param_2;
  local_resc = *(undefined1 *)(param_2 + 1);
  bVar1 = EnabledForUsage(this + -8,&local_res8);
  return bVar1;
}



===== ChecksumNumber @ 180001b20 =====

/* protected: virtual unsigned int __cdecl Kerb3961::SimplifiedCipherSuite::ChecksumNumber(void)
   __ptr64 */

uint __thiscall Kerb3961::SimplifiedCipherSuite::ChecksumNumber(SimplifiedCipherSuite *this)

{
  return *(uint *)(this + 0x14);
}



===== CipherEnabledForAccount @ 180001b30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: virtual bool __cdecl Kerb3961::Aes3962::CipherEnabledForAccount(struct
   Kerb3961::KeyPolicyScenario,unsigned int,enum Kerb3961::UserPolicyAttributes) __ptr64 */

bool __thiscall
Kerb3961::Aes3962::CipherEnabledForAccount
          (Aes3962 *this,uint *param_2,uint param_3,ulonglong param_4)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  bool bVar4;
  ulonglong uVar5;
  CipherPolicyImpl *pCVar6;
  uint *puVar7;
  uint local_58;
  byte local_54;
  uint local_48;
  undefined1 local_44;
  longlong *local_38;
  longlong lStack_30;
  longlong *local_28;
  longlong lStack_20;
  longlong *local_18 [2];
  
  uVar5 = Feature_184236346__private_IsEnabledDeviceUsageNoInline();
  bVar1 = (byte)param_2[1];
  if ((int)uVar5 == 0) {
    local_58 = *param_2;
    if ((((bVar1 & 0x20) != 0) || (((char)uVar5 + 8U & bVar1) == 0)) && ((param_4 >> 0x39 & 1) != 0)
       ) {
      return true;
    }
    puVar7 = &local_58;
    local_54 = bVar1;
    goto LAB_180001ca6;
  }
  if (((bVar1 & 0x28) != 8) && ((param_4 >> 0x39 & 1) != 0)) {
    bVar2 = 0x10;
    if (*(longlong *)(this + 0x40) == 0x10) {
      bVar2 = 8;
    }
    local_58 = (uint)bVar2;
    param_3 = param_3 | local_58;
  }
  if ((short)param_3 == 0) {
    local_58 = 0;
    if ((param_4 & 0x87) == 0) {
      pCVar6 = (CipherPolicyImpl *)0x0;
      if ((bVar1 & 2) == 0) {
        pCVar6 = &g_localCipherPolicy;
      }
      local_28 = (longlong *)0x0;
      lStack_20 = 0;
      local_38 = (longlong *)0x0;
      lStack_30 = 0;
      (**(code **)(*(longlong *)pCVar6 + 0x60))
                (0,local_18,0x17,0x8000000000000008,&local_38,&local_28);
      if (lStack_30 != 0) {
        (**(code **)(*local_38 + 0x38))(local_38,&local_38);
      }
      if (lStack_20 != 0) {
        (**(code **)(*local_28 + 0x38))(local_28,&local_28);
      }
      if (local_18[0] == (longlong *)0x0) goto LAB_180001c90;
      local_48 = *param_2;
      local_44 = (undefined1)param_2[1];
      cVar3 = (**(code **)(*local_18[0] + 0x58))(local_18[0],&local_48,param_3,param_4);
      local_58 = CONCAT31(local_58._1_3_,0x20);
      if (cVar3 == '\0') goto LAB_180001c90;
    }
    else {
LAB_180001c90:
      local_58 = CONCAT31(local_58._1_3_,0x18);
    }
    param_3 = local_58;
  }
  local_48 = *param_2;
  puVar7 = &local_48;
  local_44 = (undefined1)param_2[1];
LAB_180001ca6:
  bVar4 = EnabledForUsage(this,puVar7,param_3);
  return bVar4;
}



===== CipherEnabledForUsage @ 180001ce0 =====

/* private: virtual bool __cdecl Kerb3961::Aes3962::CipherEnabledForUsage(struct
   Kerb3961::KeyPolicyScenario,unsigned int) __ptr64 */

bool __thiscall Kerb3961::Aes3962::CipherEnabledForUsage(Aes3962 *this,undefined4 *param_2)

{
  bool bVar1;
  undefined4 local_18;
  undefined1 local_14;
  
  local_18 = *param_2;
  local_14 = *(undefined1 *)(param_2 + 1);
  bVar1 = EnabledForUsage(this,&local_18);
  return bVar1;
}



===== ChecksumNumber @ 180001d10 =====

/* private: virtual unsigned int __cdecl Kerb3961::RC4_4757::ChecksumNumber(void) __ptr64 */

uint __thiscall Kerb3961::RC4_4757::ChecksumNumber(RC4_4757 *this)

{
  return *(uint *)(this + 0x18);
}



===== CoalesceAuthWrapBuffers @ 180001d1c =====

/* private: struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct Kerb3961::ResultBlock
   const & __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::OwnedBinary,16>(struct
   Kerb3961::OwnedBinary const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)>
   __cdecl Kerb3961::SSPICipherSuite<1,1>::CoalesceAuthWrapBuffers(struct Kerb3961::WrapBuffers
   const & __ptr64) __ptr64 */

WrapBuffers * __thiscall
Kerb3961::SSPICipherSuite<1,1>::CoalesceAuthWrapBuffers
          (SSPICipherSuite<1,1> *this,WrapBuffers *param_1)

{
  longlong *plVar1;
  size_t *psVar2;
  longlong *plVar3;
  char *pcVar4;
  ulonglong uVar5;
  size_t *psVar6;
  longlong *in_R8;
  ulonglong uVar7;
  void *_Dst;
  undefined8 local_38;
  void *local_30;
  int local_28;
  
  if (*in_R8 == 0) {
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  else {
    plVar3 = (longlong *)in_R8[1];
    plVar1 = plVar3 + *in_R8 * 3;
    uVar5 = 0;
    if (plVar3 != plVar1) {
      do {
        uVar7 = uVar5;
        if ((char)plVar3[2] == '\0') {
          uVar7 = *plVar3 + uVar5;
          if (uVar7 < uVar5) {
            pcVar4 = "newTotalLength >= totalLength";
LAB_180001dd3:
            Logging::Verify::ConditionFailed(pcVar4);
            *(undefined8 *)param_1 = 0;
            *(undefined8 *)(param_1 + 8) = 0;
            *(undefined4 *)(param_1 + 0x10) = 0xc0000095;
            return param_1;
          }
          if (0xffffffffffff0000 < uVar7) {
            pcVar4 = "newTotalLength <= MessageLimit";
            goto LAB_180001dd3;
          }
        }
        plVar3 = plVar3 + 3;
        uVar5 = uVar7;
      } while (plVar3 != plVar1);
      if (uVar7 != 0) {
        MakeBuffer((__uint64)&local_38);
        if (-1 < local_28) {
          psVar6 = (size_t *)in_R8[1];
          psVar2 = psVar6 + *in_R8 * 3;
          _Dst = local_30;
          for (; psVar6 != psVar2; psVar6 = psVar6 + 3) {
            if ((char)psVar6[2] == '\0') {
              memmove(_Dst,(void *)psVar6[1],*psVar6);
              _Dst = (void *)((longlong)_Dst + *psVar6);
            }
          }
          *(undefined8 *)param_1 = local_38;
          *(int *)(param_1 + 0x10) = local_28;
          *(void **)(param_1 + 8) = local_30;
          return param_1;
        }
        Logging::Verify::ConditionFailed("result");
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(undefined4 *)(param_1 + 0x10) = 0xc0000017;
        if (local_30 == (void *)0x0) {
          return param_1;
        }
        operator_delete__(local_30);
        return param_1;
      }
    }
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return param_1;
}



===== CoalesceEncryptedWrapBuffers @ 180001e84 =====

/* private: struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct Kerb3961::ResultBlock
   const & __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::OwnedBinary,16>(struct
   Kerb3961::OwnedBinary const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)>
   __cdecl Kerb3961::SSPICipherSuite<1,1>::CoalesceEncryptedWrapBuffers(struct Kerb3961::WrapBuffers
   const & __ptr64) __ptr64 */

WrapBuffers * __thiscall
Kerb3961::SSPICipherSuite<1,1>::CoalesceEncryptedWrapBuffers
          (SSPICipherSuite<1,1> *this,WrapBuffers *param_1)

{
  size_t *psVar1;
  longlong *plVar2;
  longlong *plVar3;
  char *pcVar4;
  ulonglong uVar5;
  void *_Dst;
  size_t *psVar6;
  longlong *in_R8;
  longlong lVar7;
  ulonglong uVar8;
  undefined8 local_38;
  void *local_30;
  int local_28;
  
  if (*in_R8 == 0) {
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  else {
    plVar2 = (longlong *)in_R8[1];
    lVar7 = 0;
    plVar3 = plVar2;
    uVar5 = 0;
    if (plVar2 != plVar2 + *in_R8 * 3) {
      do {
        uVar8 = uVar5;
        if ((char)plVar3[2] != '\0') {
          uVar8 = *plVar3 + uVar5;
          if (uVar8 < uVar5) {
            pcVar4 = "newTotalLength >= totalLength";
LAB_180001f41:
            Logging::Verify::ConditionFailed(pcVar4);
            *(undefined8 *)param_1 = 0;
            *(undefined8 *)(param_1 + 8) = 0;
            *(undefined4 *)(param_1 + 0x10) = 0xc0000095;
            return param_1;
          }
          if (0xffffffffffff0000 < uVar8) {
            pcVar4 = "newTotalLength <= MessageLimit";
            goto LAB_180001f41;
          }
          lVar7 = lVar7 + 1;
        }
        plVar3 = plVar3 + 3;
        uVar5 = uVar8;
      } while (plVar3 != plVar2 + *in_R8 * 3);
      if ((lVar7 != 0) && (uVar8 != 0)) {
        if ((lVar7 == 1) && ((char)plVar2[2] != '\0')) {
          *(undefined8 *)param_1 = 0;
          *(undefined8 *)(param_1 + 8) = 0;
          *(undefined4 *)(param_1 + 0x10) = 0xff;
          return param_1;
        }
        MakeBuffer((__uint64)&local_38);
        if (-1 < local_28) {
          psVar6 = (size_t *)in_R8[1];
          psVar1 = psVar6 + *in_R8 * 3;
          _Dst = local_30;
          for (; psVar6 != psVar1; psVar6 = psVar6 + 3) {
            if ((char)psVar6[2] != '\0') {
              memmove(_Dst,(void *)psVar6[1],*psVar6);
              _Dst = (void *)((longlong)_Dst + *psVar6);
            }
          }
          *(undefined8 *)param_1 = local_38;
          *(int *)(param_1 + 0x10) = local_28;
          *(void **)(param_1 + 8) = local_30;
          return param_1;
        }
        Logging::Verify::ConditionFailed("result");
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(undefined4 *)(param_1 + 0x10) = 0xc0000017;
        if (local_30 == (void *)0x0) {
          return param_1;
        }
        operator_delete__(local_30);
        return param_1;
      }
    }
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return param_1;
}



===== CoalesceMICBuffers @ 180002020 =====

/* private: struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct Kerb3961::ResultBlock
   const & __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::OwnedBinary,16>(struct
   Kerb3961::OwnedBinary const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)>
   __cdecl Kerb3961::SSPICipherSuite<1,1>::CoalesceMICBuffers(struct Kerb3961::MicBuffers const &
   __ptr64) __ptr64 */

MicBuffers * __thiscall
Kerb3961::SSPICipherSuite<1,1>::CoalesceMICBuffers(SSPICipherSuite<1,1> *this,MicBuffers *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  char *pcVar3;
  longlong *plVar4;
  void *_Dst;
  size_t *psVar5;
  size_t *psVar6;
  longlong *in_R8;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined8 local_38;
  void *local_30;
  int local_28;
  
  lVar1 = *in_R8;
  if (lVar1 == 0) {
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  else if (lVar1 == 1) {
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0xff;
  }
  else {
    plVar4 = (longlong *)in_R8[1];
    plVar2 = plVar4 + lVar1 * 2;
    uVar7 = 0;
    for (; plVar4 != plVar2; plVar4 = plVar4 + 2) {
      uVar8 = *plVar4 + uVar7;
      if (uVar8 < uVar7) {
        pcVar3 = "newTotalLength >= totalLength";
LAB_1800020d6:
        Logging::Verify::ConditionFailed(pcVar3);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(undefined4 *)(param_1 + 0x10) = 0xc0000095;
        return param_1;
      }
      if (0xffffffffffff0000 < uVar8) {
        pcVar3 = "newTotalLength <= MessageLimit";
        goto LAB_1800020d6;
      }
      uVar7 = uVar8;
    }
    MakeBuffer((__uint64)&local_38);
    if (local_28 < 0) {
      Logging::Verify::ConditionFailed("result");
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(undefined4 *)(param_1 + 0x10) = 0xc0000017;
      if (local_30 != (void *)0x0) {
        operator_delete__(local_30);
      }
    }
    else {
      psVar6 = (size_t *)in_R8[1];
      psVar5 = psVar6 + *in_R8 * 2;
      _Dst = local_30;
      for (; psVar6 != psVar5; psVar6 = psVar6 + 2) {
        memmove(_Dst,(void *)psVar6[1],*psVar6);
        _Dst = (void *)((longlong)_Dst + *psVar6);
      }
      *(undefined8 *)param_1 = local_38;
      *(int *)(param_1 + 0x10) = local_28;
      *(void **)(param_1 + 8) = local_30;
    }
  }
  return param_1;
}



===== CoalescePlainWrapBuffers @ 180002170 =====

/* private: struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct Kerb3961::ResultBlock
   const & __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::OwnedBinary,16>(struct
   Kerb3961::OwnedBinary const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)>
   __cdecl Kerb3961::SSPICipherSuite<1,1>::CoalescePlainWrapBuffers(struct Kerb3961::WrapBuffers
   const & __ptr64) __ptr64 */

WrapBuffers * __thiscall
Kerb3961::SSPICipherSuite<1,1>::CoalescePlainWrapBuffers
          (SSPICipherSuite<1,1> *this,WrapBuffers *param_1)

{
  longlong *plVar1;
  size_t *psVar2;
  longlong lVar3;
  longlong *plVar4;
  char *pcVar5;
  ulonglong uVar6;
  void *_Dst;
  size_t *psVar7;
  longlong *in_R8;
  ulonglong uVar8;
  undefined8 local_38;
  void *local_30;
  int local_28;
  
  lVar3 = *in_R8;
  if (lVar3 == 0) {
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  else if (lVar3 == 1) {
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0xff;
  }
  else {
    plVar4 = (longlong *)in_R8[1];
    plVar1 = plVar4 + lVar3 * 3;
    uVar6 = 0;
    for (; plVar4 != plVar1; plVar4 = plVar4 + 3) {
      uVar8 = *plVar4 + uVar6;
      if (uVar8 < uVar6) {
        pcVar5 = "newTotalLength >= totalLength";
LAB_180002225:
        Logging::Verify::ConditionFailed(pcVar5);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(undefined4 *)(param_1 + 0x10) = 0xc0000095;
        return param_1;
      }
      if (0xffffffffffff0000 < uVar8) {
        pcVar5 = "newTotalLength <= MessageLimit";
        goto LAB_180002225;
      }
      uVar6 = uVar8;
    }
    MakeBuffer((__uint64)&local_38);
    if (local_28 < 0) {
      Logging::Verify::ConditionFailed("result");
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(undefined4 *)(param_1 + 0x10) = 0xc0000017;
      if (local_30 != (void *)0x0) {
        operator_delete__(local_30);
      }
    }
    else {
      psVar7 = (size_t *)in_R8[1];
      psVar2 = psVar7 + *in_R8 * 3;
      _Dst = local_30;
      for (; psVar7 != psVar2; psVar7 = psVar7 + 3) {
        memmove(_Dst,(void *)psVar7[1],*psVar7);
        _Dst = (void *)((longlong)_Dst + *psVar7);
      }
      *(undefined8 *)param_1 = local_38;
      *(int *)(param_1 + 0x10) = local_28;
      *(void **)(param_1 + 8) = local_30;
    }
  }
  return param_1;
}



===== CommonGetMIC @ 1800022c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::RFC4121CipherSuite<1,1,0>::CommonGetMIC(struct Kerb3961::ReadOnlyBinary const &
   __ptr64,unsigned __int64,unsigned int,struct Kerb3961::ReadOnlyBinary const & __ptr64,bool,bool)
   __ptr64 */

ReadOnlyBinary * __thiscall
Kerb3961::RFC4121CipherSuite<1,1,0>::CommonGetMIC
          (RFC4121CipherSuite<1,1,0> *this,ReadOnlyBinary *param_1,__uint64 param_2,uint param_3,
          ReadOnlyBinary *param_4,bool param_5,bool param_6)

{
  RFC4121CipherSuite<1,1,0> *pRVar1;
  int iVar2;
  int iVar3;
  uint in_register_0000008c;
  undefined7 in_stack_00000031;
  char in_stack_00000040;
  EncryptionAlgorithm *local_78;
  longlong local_70;
  long local_68;
  ReadOnlyBinary local_60 [8];
  undefined4 *local_58;
  long local_50;
  ReadOnlyBinary local_48 [8];
  void *local_40;
  long local_38;
  undefined1 local_30 [8];
  void *local_28;
  long local_20;
  
  pRVar1 = this + 8;
  iVar2 = (**(code **)(*(longlong *)pRVar1 + 0x68))(pRVar1);
  iVar3 = (**(code **)(*(longlong *)this + 0xe0))(this);
  if (iVar2 != iVar3) {
                    /* WARNING: Subroutine does not return */
    ConsistencyFail((ushort *)
                    L"A cipher suite\'s included checksum must be the required checksum for the included cipher"
                   );
  }
  (**(code **)(*(longlong *)this + 0xa8))
            (this,&local_78,CONCAT71(in_stack_00000031,param_5),param_6 * '\x02' + '\x17',2);
  if (local_68 < 0) {
    Logging::Verify::StatusFailed("specificKey",local_68);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(long *)(param_1 + 0x10) = local_68;
  }
  else {
    MakeBuffer((__uint64)local_60);
    if (local_50 < 0) {
      Logging::Verify::StatusFailed("headerBuffer",local_50);
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(long *)(param_1 + 0x10) = local_50;
      if (local_58 == (undefined4 *)0x0) goto LAB_180002488;
    }
    else {
      local_58[1] = 0xffffffff;
      *local_58 = 0xff000404;
      *(undefined8 *)(local_58 + 2) = 0;
      if (!param_6) {
        *(undefined1 *)((longlong)local_58 + 2) = 1;
      }
      if (in_stack_00000040 != '\0') {
        *(byte *)((longlong)local_58 + 2) = !param_6 | 4;
      }
      *(ulonglong *)(local_58 + 2) =
           (ulonglong)(in_register_0000008c >> 0x18) |
           ((ulonglong)in_register_0000008c & 0xff0000) >> 8 |
           ((ulonglong)in_register_0000008c & 0xff00) << 8 |
           ((ulonglong)in_register_0000008c & 0xff) << 0x18 | ((ulonglong)param_3 & 0xff000000) << 8
           | ((ulonglong)param_3 & 0xff0000) << 0x18 | ((ulonglong)param_3 & 0xff00) << 0x28 |
           (ulonglong)param_3 << 0x38;
      Concatenate(local_48,(ReadOnlyBinary *)param_2);
      if (local_38 < 0) {
        Logging::Verify::StatusFailed("combinedInput",local_38);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(long *)(param_1 + 0x10) = local_38;
      }
      else {
        (**(code **)(*(longlong *)pRVar1 + 0x58))(pRVar1,local_30,&local_78,local_48);
        if (local_20 < 0) {
          Logging::Verify::StatusFailed("hmac",local_20);
          *(undefined8 *)param_1 = 0;
          *(undefined8 *)(param_1 + 8) = 0;
          *(long *)(param_1 + 0x10) = local_20;
        }
        else {
          Concatenate(param_1,local_60);
        }
        if (local_28 != (void *)0x0) {
          operator_delete__(local_28);
        }
      }
      if (local_40 != (void *)0x0) {
        operator_delete__(local_40);
      }
    }
    operator_delete__(local_58);
  }
LAB_180002488:
  if (local_70 != 0) {
    EncryptionAlgorithm::_vcall__160__flat______(local_78);
  }
  return param_1;
}



===== CommonUnwrap @ 1800024e0 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::UnwrapResult,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::DoubleGetter<struct
   Kerb3961::UnwrapResult,struct Kerb3961::OwnedBinary,0,16>(struct Kerb3961::UnwrapResult const &
   __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::DoubleSetter<struct
   Kerb3961::UnwrapResult,struct Kerb3961::OwnedBinary,0,16>(struct Kerb3961::UnwrapResult &
   __ptr64)> __cdecl Kerb3961::RFC4121CipherSuite<1,1,0>::CommonUnwrap(struct
   Kerb3961::ReadOnlyBinary const & __ptr64,struct Kerb3961::ReadOnlyBinary const & __ptr64,struct
   Kerb3961::ReadOnlyBinary const & __ptr64,bool,bool) __ptr64 */

ReadOnlyBinary * __thiscall
Kerb3961::RFC4121CipherSuite<1,1,0>::CommonUnwrap
          (RFC4121CipherSuite<1,1,0> *this,ReadOnlyBinary *param_1,ReadOnlyBinary *param_2,
          ReadOnlyBinary *param_3,bool param_4,bool param_5)

{
  short *psVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  char *pcVar4;
  int iVar5;
  ReadOnlyBinary RVar6;
  byte in_stack_00000038;
  ReadOnlyBinary local_58 [8];
  void *local_50;
  undefined8 local_40;
  void *local_38;
  int local_30;
  undefined8 local_2c;
  undefined8 uStack_24;
  undefined4 local_1c;
  
  if (*(ulonglong *)param_2 < 0x10) {
    pcVar4 = "inputMessage.length >= WrapHeaderSize";
  }
  else {
    psVar1 = *(short **)(param_2 + 8);
    if (*psVar1 == 0x405) {
      if (*(char *)((longlong)psVar1 + 3) == -1) {
        RVar6 = (ReadOnlyBinary)0x1;
        if ((bool)(*(byte *)(psVar1 + 1) & 1) == param_5) {
          if ((*(byte *)(psVar1 + 1) >> 2 & 1) != in_stack_00000038) {
            Logging::Verify::ConditionFailed
                      ("WI_IsFlagSet(header.flags, GSSAPIFlags::AcceptorSubkey) == acceptorSubkey");
            *(undefined8 *)(param_1 + 0x14) = 0;
            *(undefined8 *)(param_1 + 0x1c) = 0;
            *(undefined4 *)(param_1 + 0x24) = 0;
            *(undefined8 *)param_1 = 0;
            *(undefined8 *)(param_1 + 8) = 0;
            *(undefined4 *)(param_1 + 0x10) = 0x80090348;
            return param_1;
          }
          local_1c = 0;
          local_2c = 0;
          uStack_24 = 0;
          local_38 = (void *)0x0;
          if ((*(byte *)(psVar1 + 1) & 2) == 0) {
            puVar3 = (undefined8 *)CommonUnwrapIntegrity(this,local_58,param_2,param_3);
            if (local_38 != (void *)0x0) {
              operator_delete__(local_38);
            }
            local_40 = *puVar3;
            local_38 = (void *)puVar3[1];
            *puVar3 = 0;
            iVar5 = *(int *)(puVar3 + 2);
            puVar3[1] = 0;
            *(undefined4 *)(puVar3 + 2) = 0xc0000001;
            local_30 = iVar5;
            if (local_50 != (void *)0x0) {
              operator_delete__(local_50);
            }
            if (-1 < iVar5) {
              RVar6 = (ReadOnlyBinary)0x0;
              goto LAB_1800026df;
            }
            pcVar4 = 
            "result.outputMessage = CommonUnwrapIntegrity(inputMessage, authData, protocolKey)";
          }
          else {
            puVar3 = (undefined8 *)CommonUnwrapConfidential(this,local_58,param_2,param_3);
            if (local_38 != (void *)0x0) {
              operator_delete__(local_38);
            }
            local_40 = *puVar3;
            local_38 = (void *)puVar3[1];
            *puVar3 = 0;
            iVar5 = *(int *)(puVar3 + 2);
            puVar3[1] = 0;
            *(undefined4 *)(puVar3 + 2) = 0xc0000001;
            local_30 = iVar5;
            if (local_50 != (void *)0x0) {
              operator_delete__(local_50);
            }
            if (-1 < iVar5) {
LAB_1800026df:
              uVar2 = *(ulonglong *)(psVar1 + 4);
              *(int *)(param_1 + 0x10) = local_30;
              *(undefined8 *)param_1 = local_40;
              *(void **)(param_1 + 8) = local_38;
              *(ulonglong *)(param_1 + 0x18) =
                   uVar2 >> 0x38 | (uVar2 & 0xff000000000000) >> 0x28 |
                   (uVar2 & 0xff0000000000) >> 0x18 | (uVar2 & 0xff00000000) >> 8 |
                   (uVar2 & 0xff000000) << 8 | (uVar2 & 0xff0000) << 0x18 | (uVar2 & 0xff00) << 0x28
                   | uVar2 << 0x38;
              *(undefined4 *)(param_1 + 0x20) = 0;
              param_1[0x24] = RVar6;
              return param_1;
            }
            pcVar4 = 
            "result.outputMessage = CommonUnwrapConfidential(inputMessage, authData, protocolKey)";
          }
          Logging::Verify::StatusFailed(pcVar4,iVar5);
          *(undefined8 *)(param_1 + 0x14) = 0;
          *(undefined8 *)(param_1 + 0x1c) = 0;
          *(undefined4 *)(param_1 + 0x24) = 0;
          *(int *)(param_1 + 0x10) = iVar5;
          *(undefined8 *)(param_1 + 8) = 0;
          *(undefined8 *)param_1 = 0;
          if (local_38 == (void *)0x0) {
            return param_1;
          }
          operator_delete__(local_38);
          return param_1;
        }
        pcVar4 = "WI_IsFlagSet(header.flags, GSSAPIFlags::SentByAcceptor) == initiator";
      }
      else {
        pcVar4 = "header.filler == header.FillerValue";
      }
      Logging::Verify::ConditionFailed(pcVar4);
      *(undefined8 *)(param_1 + 0x14) = 0;
      *(undefined8 *)(param_1 + 0x1c) = 0;
      *(undefined4 *)(param_1 + 0x24) = 0;
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(undefined4 *)(param_1 + 0x10) = 0x8009030f;
      return param_1;
    }
    pcVar4 = "header.tokenID == GSSAPITokenID::Wrap";
  }
  Logging::Verify::ConditionFailed(pcVar4);
  *(undefined8 *)(param_1 + 0x14) = 0;
  *(undefined8 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined8 *)param_1 = 0;
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0x80090308;
  return param_1;
}



===== CommonUnwrapConfidential @ 180002730 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct Kerb3961::ResultBlock
   const & __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::OwnedBinary,16>(struct
   Kerb3961::OwnedBinary const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)>
   __cdecl Kerb3961::RFC4121CipherSuite<1,1,0>::CommonUnwrapConfidential(struct
   Kerb3961::ReadOnlyBinary const & __ptr64,struct Kerb3961::ReadOnlyBinary const & __ptr64,struct
   Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64 */

ReadOnlyBinary * __thiscall
Kerb3961::RFC4121CipherSuite<1,1,0>::CommonUnwrapConfidential
          (RFC4121CipherSuite<1,1,0> *this,ReadOnlyBinary *param_1,ReadOnlyBinary *param_2,
          ReadOnlyBinary *param_3)

{
  byte *pbVar1;
  byte bVar2;
  short sVar3;
  ushort uVar4;
  bool bVar5;
  long lVar6;
  undefined8 *puVar7;
  void *pvVar8;
  char *pcVar9;
  ReadOnlyBinary *pRVar10;
  longlong lVar11;
  byte bVar12;
  undefined8 in_stack_00000028;
  undefined1 auStack_168 [32];
  undefined1 *local_148;
  ReadOnlyBinary *local_140;
  undefined8 local_128;
  void *local_120;
  long local_118;
  EncryptionAlgorithm *local_110;
  longlong local_108;
  long local_100;
  EncryptionAlgorithm *local_f8;
  longlong local_f0;
  long local_e8;
  ulonglong local_e0;
  void *local_d8;
  long local_d0;
  longlong local_c8;
  void *local_c0;
  undefined8 local_b8;
  ulonglong local_a8;
  byte *local_a0;
  undefined1 local_98 [16];
  undefined1 local_88 [32];
  ulonglong local_68;
  longlong local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStack_168;
  sVar3 = *(short *)(*(longlong *)(param_2 + 8) + 6);
  local_128 = 0;
  local_120 = (void *)0x0;
  local_118 = -0x3fffffff;
  if (sVar3 != 0) {
    puVar7 = (undefined8 *)Unrotate(this,(ReadOnlyBinary *)&local_c8,(ushort)param_2);
    if (local_120 != (void *)0x0) {
      operator_delete__(local_120);
    }
    local_128 = *puVar7;
    *puVar7 = 0;
    local_120 = (void *)puVar7[1];
    puVar7[1] = 0;
    local_118 = *(long *)(puVar7 + 2);
    *(undefined4 *)(puVar7 + 2) = 0xc0000001;
    if (local_c0 != (void *)0x0) {
      operator_delete__(local_c0);
    }
    lVar6 = local_118;
    if (local_118 < 0) {
      Logging::Verify::StatusFailed("unrotatedBuffer",local_118);
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(long *)(param_1 + 0x10) = lVar6;
      goto LAB_180002a5c;
    }
    *(undefined2 *)((longlong)local_120 + 6) = 0;
  }
  local_c8 = 0x10;
  pRVar10 = (ReadOnlyBinary *)&local_128;
  if (sVar3 == 0) {
    pRVar10 = param_2;
  }
  lVar11 = *(longlong *)(pRVar10 + 8);
  local_c0 = (void *)(*(longlong *)pRVar10 - 0x10);
  Split<2>(&local_a8,pRVar10,&local_c8);
  bVar5 = true;
  local_148 = (undefined1 *)CONCAT44(local_148._4_4_,1);
  (**(code **)(*(longlong *)this + 0xa8))
            (this,&local_110,in_stack_00000028,(~*(byte *)(lVar11 + 2) & 1) * '\x02' + '\x16');
  if (local_100 < 0) {
    Logging::Verify::StatusFailed("specificKey",local_100);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(long *)(param_1 + 0x10) = local_100;
  }
  else {
    (**(code **)(*(longlong *)this + 0xb8))(this,&local_f8,&local_110,0);
    if (local_e8 < 0) {
      Logging::Verify::StatusFailed("state",local_e8);
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(long *)(param_1 + 0x10) = local_e8;
    }
    else {
      local_148 = local_98;
      local_140 = param_3;
      (**(code **)(*(longlong *)this + 0xd0))(this,&local_e0,&local_110,&local_f8);
      lVar6 = local_d0;
      if (local_d0 < 0) {
        Logging::Verify::StatusFailed("decryption",local_d0);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(long *)(param_1 + 0x10) = lVar6;
      }
      else {
        uVar4 = *(ushort *)(lVar11 + 4);
        pvVar8 = (void *)(ulonglong)(ushort)(uVar4 >> 8 | uVar4 << 8);
        if (local_e0 < (longlong)pvVar8 + 0x10U) {
          pcVar9 = "decryption.length >= WrapHeaderSize + fillingSize";
        }
        else {
          lVar11 = (local_e0 - (longlong)pvVar8) + -0x10;
          local_b8 = 0x10;
          local_c8 = lVar11;
          local_c0 = pvVar8;
          Split<3>(local_88,&local_e0,&local_c8);
          if (local_a8 == local_68) {
            if (local_a8 != 0) {
              if (0xffffffff < local_a8) goto LAB_180002a00;
              bVar12 = 0;
              if ((int)local_a8 != 0) {
                local_60 = local_60 - (longlong)local_a0;
                local_a8 = local_a8 & 0xffffffff;
                do {
                  pbVar1 = local_a0 + local_60;
                  bVar2 = *local_a0;
                  local_a0 = local_a0 + 1;
                  bVar12 = bVar12 | *pbVar1 ^ bVar2;
                  local_a8 = local_a8 - 1;
                } while (local_a8 != 0);
                if (bVar12 != 0) goto LAB_180002a00;
              }
            }
          }
          else {
LAB_180002a00:
            bVar5 = false;
          }
          if (bVar5) {
            *(long *)(param_1 + 0x10) = local_d0;
            *(void **)(param_1 + 8) = local_d8;
            local_d0 = -0x3fffffff;
            *(longlong *)param_1 = lVar11;
            local_e0 = 0;
            local_d8 = (void *)0x0;
            goto LAB_180002a34;
          }
          pcVar9 = "SecureEqualBuffer(headerBuffer, decryptedHeader)";
        }
        Logging::Verify::ConditionFailed(pcVar9);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(undefined4 *)(param_1 + 0x10) = 0x8009030f;
      }
      if (local_d8 != (void *)0x0) {
        operator_delete__(local_d8);
      }
    }
LAB_180002a34:
    if (local_f0 != 0) {
      EncryptionAlgorithm::_vcall__176__flat______(local_f8);
    }
  }
  if (local_108 != 0) {
    EncryptionAlgorithm::_vcall__160__flat______(local_110);
  }
LAB_180002a5c:
  if (local_120 != (void *)0x0) {
    operator_delete__(local_120);
  }
  return param_1;
}



===== CommonUnwrapIntegrity @ 180002a98 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct Kerb3961::ResultBlock
   const & __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::OwnedBinary,16>(struct
   Kerb3961::OwnedBinary const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)>
   __cdecl Kerb3961::RFC4121CipherSuite<1,1,0>::CommonUnwrapIntegrity(struct
   Kerb3961::ReadOnlyBinary const & __ptr64,struct Kerb3961::ReadOnlyBinary const & __ptr64,struct
   Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64 */

ReadOnlyBinary * __thiscall
Kerb3961::RFC4121CipherSuite<1,1,0>::CommonUnwrapIntegrity
          (RFC4121CipherSuite<1,1,0> *this,ReadOnlyBinary *param_1,ReadOnlyBinary *param_2,
          ReadOnlyBinary *param_3)

{
  void *pvVar1;
  RFC4121CipherSuite<1,1,0> *pRVar2;
  longlong lVar3;
  ReadOnlyBinary *pRVar4;
  long lVar5;
  void *pvVar6;
  int iVar7;
  int iVar8;
  undefined8 *puVar9;
  int *piVar10;
  ReadOnlyBinary *pRVar11;
  char *pcVar12;
  ulonglong uVar13;
  undefined8 in_stack_00000028;
  undefined1 auStack_138 [32];
  undefined1 *local_118;
  undefined4 local_108 [2];
  EncryptionAlgorithm *local_100;
  longlong local_f8;
  int local_f0;
  undefined8 local_e8;
  void *local_e0;
  long local_d8;
  longlong local_c8;
  void *local_c0;
  ulonglong local_a8;
  void *local_a0;
  long local_98;
  undefined1 local_90 [16];
  ReadOnlyBinary local_80 [16];
  undefined1 local_70 [16];
  undefined1 local_60 [16];
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStack_138;
  local_108[0] = 0;
  Unrotate(this,(ReadOnlyBinary *)&local_a8,(ushort)param_2);
  pvVar6 = local_a0;
  if (local_98 < 0) {
    Logging::Verify::StatusFailed("buffer",local_98);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(long *)(param_1 + 0x10) = local_98;
    if (local_a0 == (void *)0x0) {
      return param_1;
    }
    goto LAB_180002d58;
  }
  uVar13 = (ulonglong)
           (ushort)(*(ushort *)((longlong)local_a0 + 4) >> 8 |
                   *(ushort *)((longlong)local_a0 + 4) << 8);
  *(undefined2 *)((longlong)local_a0 + 6) = 0;
  *(undefined2 *)((longlong)local_a0 + 4) = 0;
  if (local_a8 < uVar13 + 0x10) {
    Logging::Verify::ConditionFailed("buffer.length >= checksumSize + WrapHeaderSize");
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0x8009030f;
  }
  else {
    local_c8 = local_a8 - uVar13;
    pvVar1 = (void *)(local_c8 + -0x10);
    local_c0 = (void *)uVar13;
    Split<2>(local_70,&local_a8,&local_c8);
    local_c8 = 0x10;
    local_c0 = pvVar1;
    Split<2>(local_90,local_70,&local_c8);
    lVar3 = *(longlong *)param_3;
    if ((lVar3 == 0) || (pvVar1 == (void *)0x0)) {
      pRVar4 = local_80;
      pRVar11 = (ReadOnlyBinary *)&local_c8;
      if (lVar3 != 0) {
        pRVar11 = (ReadOnlyBinary *)&local_a8;
        pRVar4 = param_3;
      }
      puVar9 = (undefined8 *)Concatenate(pRVar11,pRVar4);
      local_d8 = *(long *)(puVar9 + 2);
      local_e8 = *puVar9;
      *(undefined4 *)(puVar9 + 2) = 0xc0000001;
      local_e0 = (void *)puVar9[1];
      *puVar9 = 0;
      puVar9[1] = 0;
      if ((((lVar3 != 0) + 1U & 2) != 0) && (local_a0 != (void *)0x0)) {
        operator_delete__(local_a0);
      }
      if ((lVar3 == 0) && (local_c0 != (void *)0x0)) {
        operator_delete__(local_c0);
      }
      lVar5 = local_d8;
      if (local_d8 < 0) {
        Logging::Verify::StatusFailed("checksumInput",local_d8);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(long *)(param_1 + 0x10) = lVar5;
      }
      else {
        local_118 = (undefined1 *)CONCAT44(local_118._4_4_,2);
        (**(code **)(*(longlong *)this + 0xa8))
                  (this,&local_100,in_stack_00000028,
                   (~*(byte *)((longlong)pvVar6 + 2) & 1) * '\x02' + '\x16');
        if (local_f0 < 0) {
          pcVar12 = "specificKey";
          iVar7 = local_f0;
LAB_180002cae:
          Logging::Verify::StatusFailed(pcVar12,iVar7);
          *(undefined8 *)param_1 = 0;
          *(undefined8 *)(param_1 + 8) = 0;
          *(int *)(param_1 + 0x10) = iVar7;
        }
        else {
          pRVar2 = this + 8;
          iVar7 = (**(code **)(*(longlong *)pRVar2 + 0x68))(pRVar2);
          iVar8 = (**(code **)(*(longlong *)this + 0xe0))(this);
          if (iVar7 != iVar8) {
                    /* WARNING: Subroutine does not return */
            ConsistencyFail((ushort *)
                            L"A cipher suite\'s included checksum must be the required checksum for the included cipher"
                           );
          }
          local_118 = local_60;
          piVar10 = (int *)(**(code **)(*(longlong *)pRVar2 + 0x60))
                                     (pRVar2,local_108,&local_100,&local_e8);
          iVar7 = *piVar10;
          if (iVar7 < 0) {
            pcVar12 = "this->VerifyMic(specificKey, checksumInput, checksumBuffer)";
            goto LAB_180002cae;
          }
          CopyBuffer(param_1);
        }
        if (local_f8 != 0) {
          EncryptionAlgorithm::_vcall__160__flat______(local_100);
        }
      }
      if (local_e0 != (void *)0x0) {
        operator_delete__(local_e0);
      }
    }
    else {
      Logging::Verify::ConditionFailed("authData.length == 0 || plaintextSize == 0");
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(undefined4 *)(param_1 + 0x10) = 0x8009030a;
    }
  }
  local_a0 = pvVar6;
LAB_180002d58:
  operator_delete__(local_a0);
  return param_1;
}



===== CommonVerifyMIC @ 180002da0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::VerifyMICResult,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::VerifyMICResult,12>(struct Kerb3961::VerifyMICResult const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::VerifyMICResult,12>(struct Kerb3961::VerifyMICResult & __ptr64)> __cdecl
   Kerb3961::RFC4121CipherSuite<1,1,0>::CommonVerifyMIC(struct Kerb3961::ReadOnlyBinary const &
   __ptr64,struct Kerb3961::ReadOnlyBinary const & __ptr64,struct Kerb3961::ReadOnlyBinary const &
   __ptr64,bool,bool) __ptr64 */

ReadOnlyBinary * __thiscall
Kerb3961::RFC4121CipherSuite<1,1,0>::CommonVerifyMIC
          (RFC4121CipherSuite<1,1,0> *this,ReadOnlyBinary *param_1,ReadOnlyBinary *param_2,
          ReadOnlyBinary *param_3,bool param_4,bool param_5)

{
  byte bVar1;
  short *psVar2;
  longlong lVar3;
  ulonglong uVar4;
  int *piVar5;
  char *pcVar6;
  ulonglong uVar7;
  undefined1 local_res20 [8];
  undefined7 in_stack_00000029;
  byte in_stack_00000038;
  ulonglong local_68;
  short *local_60;
  EncryptionAlgorithm *local_58;
  longlong local_50;
  long local_48;
  ReadOnlyBinary local_40 [8];
  void *local_38;
  int local_30;
  
  if (*(ulonglong *)param_3 < 0x10) {
    pcVar6 = "inputSignature.length >= MICHeaderSize";
LAB_180002dd2:
    Logging::Verify::ConditionFailed(pcVar6);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0x80090308;
    return param_1;
  }
  psVar2 = *(short **)(param_3 + 8);
  if (*psVar2 != 0x404) {
    pcVar6 = "resultToken.tokenID == GSSAPITokenID::MIC";
    goto LAB_180002dd2;
  }
  if (*(char *)((longlong)psVar2 + 3) != -1) {
    pcVar6 = "resultToken.filler == MICToken::FillerValue";
LAB_180002e0d:
    Logging::Verify::ConditionFailed(pcVar6);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0x8009030f;
    return param_1;
  }
  if (*(int *)(psVar2 + 2) != -1) {
    pcVar6 = "resultToken.filler2 == MICToken::Filler2Value";
    goto LAB_180002e0d;
  }
  bVar1 = *(byte *)(psVar2 + 1);
  if ((bVar1 & 2) != 0) {
    pcVar6 = "WI_IsFlagSet(resultToken.flags, GSSAPIFlags::Sealed) == false";
    goto LAB_180002e0d;
  }
  if ((bool)(bVar1 & 1) != param_5) {
    pcVar6 = "WI_IsFlagSet(resultToken.flags, GSSAPIFlags::SentByAcceptor) == initiator";
    goto LAB_180002e0d;
  }
  if ((bVar1 >> 2 & 1) != in_stack_00000038) {
    Logging::Verify::ConditionFailed
              ("WI_IsFlagSet(resultToken.flags, GSSAPIFlags::AcceptorSubkey) == acceptorSubkey");
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0x80090348;
    return param_1;
  }
  (**(code **)(*(longlong *)this + 0xa8))
            (this,&local_58,CONCAT71(in_stack_00000029,param_4),!param_5 * '\x02' + '\x17',2);
  if (local_48 < 0) {
    Logging::Verify::StatusFailed("specificKey",local_48);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(long *)(param_1 + 0xc) = local_48;
    goto LAB_180002f9c;
  }
  lVar3 = *(longlong *)param_3;
  uVar4 = (**(code **)(*(longlong *)(this + 8) + 0x80))(this + 8);
  local_68 = 0x10;
  uVar7 = lVar3 - 0x10U;
  if (uVar4 < lVar3 - 0x10U) {
    uVar7 = uVar4;
  }
  local_60 = *(short **)(param_3 + 8);
  Concatenate(local_40,param_2);
  if (local_30 < 0) {
    pcVar6 = "combinedInput";
LAB_180002f29:
    Logging::Verify::StatusFailed(pcVar6,local_30);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(int *)(param_1 + 0xc) = local_30;
  }
  else {
    local_60 = psVar2 + 8;
    local_68 = uVar7;
    piVar5 = (int *)(**(code **)(*(longlong *)(this + 8) + 0x60))
                              (this + 8,local_res20,&local_58,local_40,&local_68);
    local_30 = *piVar5;
    if (local_30 < 0) {
      pcVar6 = 
      "this->VerifyMic(specificKey, combinedInput, {micLength, reinterpret_cast<const uint8_t*>(&resultToken.data)})"
      ;
      goto LAB_180002f29;
    }
    uVar7 = *(ulonglong *)(psVar2 + 4);
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(ulonglong *)param_1 =
         uVar7 >> 0x38 | (uVar7 & 0xff000000000000) >> 0x28 | (uVar7 & 0xff0000000000) >> 0x18 |
         (uVar7 & 0xff00000000) >> 8 | (uVar7 & 0xff000000) << 8 | (uVar7 & 0xff0000) << 0x18 |
         (uVar7 & 0xff00) << 0x28 | uVar7 << 0x38;
  }
  if (local_38 != (void *)0x0) {
    operator_delete__(local_38);
  }
LAB_180002f9c:
  if (local_50 == 0) {
    return param_1;
  }
  EncryptionAlgorithm::_vcall__160__flat______(local_58);
  return param_1;
}



===== CommonWrapEncrypted @ 180002fe0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::RFC4121CipherSuite<1,1,0>::CommonWrapEncrypted(struct Kerb3961::MutableBinary const &
   __ptr64,struct Kerb3961::ReadOnlyBinary const & __ptr64,unsigned __int64,unsigned int,struct
   Kerb3961::ReadOnlyBinary const & __ptr64,bool,bool,unsigned __int64 * __ptr64) __ptr64 */

MutableBinary * __thiscall
Kerb3961::RFC4121CipherSuite<1,1,0>::CommonWrapEncrypted
          (RFC4121CipherSuite<1,1,0> *this,MutableBinary *param_1,ReadOnlyBinary *param_2,
          __uint64 param_3,uint param_4,ReadOnlyBinary *param_5,bool param_6,bool param_7,
          __uint64 *param_8)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  ReadOnlyBinary *pRVar7;
  ushort uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  longlong *plVar11;
  uint in_stack_0000002c;
  undefined7 in_stack_00000039;
  ulonglong *in_stack_00000050;
  undefined1 auStack_198 [32];
  ReadOnlyBinary *local_178;
  __uint64 local_170;
  EncryptionAlgorithm *local_158;
  longlong local_150;
  long local_148;
  undefined2 local_140;
  byte local_13e;
  undefined1 local_13d;
  ushort local_13c;
  ushort local_13a;
  ulonglong local_138;
  EncryptionAlgorithm *local_128;
  longlong local_120;
  long local_118;
  ReadOnlyBinary local_110 [8];
  void *local_108;
  long local_100;
  undefined8 local_f8;
  __uint64 local_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  ulonglong local_d8;
  void *local_d0;
  int local_c8;
  longlong local_b8;
  void *local_b0;
  ulonglong local_a8;
  longlong local_a0;
  undefined8 local_98;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStack_198;
  local_f8 = CONCAT71(in_stack_00000039,param_6);
  local_f0 = param_3;
  if ((int)param_5 == 0) {
    uVar9 = (**(code **)(*(longlong *)this + 0x170))(this,*(longlong *)param_2 + 0x10);
    if (in_stack_00000050 != (ulonglong *)0x0) {
      *in_stack_00000050 = uVar9;
    }
    local_140 = 0x405;
    local_138 = (ulonglong)(in_stack_0000002c >> 0x18) |
                ((ulonglong)in_stack_0000002c & 0xff0000) >> 8 |
                ((ulonglong)in_stack_0000002c & 0xff00) << 8 |
                ((ulonglong)in_stack_0000002c & 0xff) << 0x18 |
                ((ulonglong)param_4 & 0xff000000) << 8 | ((ulonglong)param_4 & 0xff0000) << 0x18 |
                ((ulonglong)param_4 & 0xff00) << 0x28 | CONCAT44(in_stack_0000002c,param_4) << 0x38;
    local_13c = (ushort)uVar9 >> 8 | (ushort)uVar9 << 8;
    local_13e = 2;
    if (!param_7) {
      local_13e = 3;
    }
    local_13d = 0xff;
    local_13a = 0;
    if ((char)param_8 != '\0') {
      local_13e = local_13e | 4;
    }
    uStack_e0 = &local_140;
    local_e8 = 0x10;
    pRVar7 = (ReadOnlyBinary *)RandomBuffer((__uint64)&local_b8);
    Concatenate(local_110,param_2,pRVar7);
    if (local_b0 != (void *)0x0) {
      operator_delete__(local_b0);
    }
    if (local_100 < 0) {
      Logging::Verify::StatusFailed("encryptBuffer",local_100);
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(long *)(param_1 + 0x10) = local_100;
    }
    else {
      local_178 = (ReadOnlyBinary *)CONCAT44(local_178._4_4_,1);
      (**(code **)(*(longlong *)this + 0xa8))(this,&local_158,local_f8,param_7 * '\x02' + '\x16');
      if (local_148 < 0) {
        Logging::Verify::StatusFailed("specificKey",local_148);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(long *)(param_1 + 0x10) = local_148;
      }
      else {
        (**(code **)(*(longlong *)this + 0xb8))(this,&local_128,&local_158,1);
        if (local_118 < 0) {
          Logging::Verify::StatusFailed("state",local_118);
          *(undefined8 *)param_1 = 0;
          *(undefined8 *)(param_1 + 8) = 0;
          *(long *)(param_1 + 0x10) = local_118;
        }
        else {
          local_170 = local_f0;
          local_178 = local_110;
          (**(code **)(*(longlong *)this + 200))(this,&local_d8,&local_158,&local_128);
          if (local_c8 < 0) {
            Logging::Verify::StatusFailed("encryption",local_c8);
            *(undefined8 *)param_1 = 0;
            *(undefined8 *)(param_1 + 8) = 0;
            *(int *)(param_1 + 0x10) = local_c8;
          }
          else {
            uVar9 = -(ulonglong)(in_stack_00000050 != (ulonglong *)0x0) & uVar9;
            local_b8 = (**(code **)(*(longlong *)this + 0x178))(this);
            local_b0 = *(void **)param_2;
            uVar10 = 0;
            local_a0 = ((local_d8 - (longlong)local_b0) - local_b8) - uVar9;
            local_a8 = uVar9;
            uVar8 = (ushort)local_a0;
            local_13a = uVar8 >> 8 | uVar8 << 8;
            uVar9 = 0;
            plVar11 = &local_98;
            do {
              lVar2 = (&local_b8)[uVar10];
              lVar1 = (longlong)local_d0 + uVar9;
              *plVar11 = lVar2;
              uVar9 = uVar9 + lVar2;
              uVar10 = uVar10 + 1;
              plVar11[1] = lVar1;
              plVar11 = plVar11 + 2;
            } while (uVar10 < 4);
            if (local_d8 < uVar9) {
                    /* WARNING: Subroutine does not return */
              ConsistencyFail((ushort *)L"Splitting buffer into parts that exceed the whole");
            }
            memmove(*(void **)(param_2 + 8),(void *)CONCAT44(uStack_7c,uStack_80),(size_t)local_b0);
            uVar6 = uStack_6c;
            uVar5 = uStack_70;
            uVar4 = uStack_74;
            uVar3 = local_78;
            uStack_6c = uStack_8c;
            uStack_70 = uStack_90;
            uStack_74 = local_98._4_4_;
            local_78 = (undefined4)local_98;
            local_88 = local_68;
            uStack_84 = uStack_64;
            uStack_80 = uStack_60;
            uStack_7c = uStack_5c;
            local_98._0_4_ = (undefined4)local_e8;
            local_98._4_4_ = local_e8._4_4_;
            uStack_90 = (undefined4)uStack_e0;
            uStack_8c = uStack_e0._4_4_;
            local_68 = uVar3;
            uStack_64 = uVar4;
            uStack_60 = uVar5;
            uStack_5c = uVar6;
            Concatenate<4>(param_1,&local_98);
          }
          if (local_d0 != (void *)0x0) {
            operator_delete__(local_d0);
          }
        }
        if (local_120 != 0) {
          EncryptionAlgorithm::_vcall__176__flat______(local_128);
        }
      }
      if (local_150 != 0) {
        EncryptionAlgorithm::_vcall__160__flat______(local_158);
      }
    }
    if (local_108 != (void *)0x0) {
      operator_delete__(local_108);
    }
  }
  else {
    Logging::Verify::ConditionFailed("QOP == 0");
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0xc000000d;
  }
  return param_1;
}



===== CommonWrapPlain @ 180003360 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::RFC4121CipherSuite<1,1,0>::CommonWrapPlain(struct Kerb3961::ReadOnlyBinary const &
   __ptr64,unsigned __int64,struct Kerb3961::ReadOnlyBinary const & __ptr64,bool,bool) __ptr64 */

ReadOnlyBinary * __thiscall
Kerb3961::RFC4121CipherSuite<1,1,0>::CommonWrapPlain
          (RFC4121CipherSuite<1,1,0> *this,ReadOnlyBinary *param_1,__uint64 param_2,
          ReadOnlyBinary *param_3,bool param_4,bool param_5)

{
  RFC4121CipherSuite<1,1,0> *pRVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  undefined7 in_stack_00000029;
  char in_stack_00000038;
  EncryptionAlgorithm *local_a8;
  longlong local_a0;
  long local_98;
  undefined2 local_90;
  byte local_8e;
  undefined1 local_8d;
  undefined4 local_8c;
  ulonglong local_88;
  ReadOnlyBinary local_78 [8];
  void *local_70;
  long local_68;
  ushort local_60 [4];
  void *local_58;
  long local_50;
  undefined8 local_48;
  undefined2 *local_40;
  undefined8 local_38;
  void *local_30;
  long local_28;
  
  local_8d = 0xff;
  local_90 = 0x405;
  local_8c = 0;
  local_8e = !param_5;
  local_88 = (ulonglong)param_3 >> 0x38 | ((ulonglong)param_3 & 0xff000000000000) >> 0x28 |
             ((ulonglong)param_3 & 0xff0000000000) >> 0x18 |
             ((ulonglong)param_3 & 0xff00000000) >> 8 | ((ulonglong)param_3 & 0xff000000) << 8 |
             ((ulonglong)param_3 & 0xff0000) << 0x18 | ((ulonglong)param_3 & 0xff00) << 0x28 |
             (longlong)param_3 << 0x38;
  if (in_stack_00000038 != '\0') {
    local_8e = local_8e | 4;
  }
  local_40 = &local_90;
  local_48 = 0x10;
  Concatenate(local_78,(ReadOnlyBinary *)param_2);
  if (local_68 < 0) {
    Logging::Verify::StatusFailed("checksumMessage",local_68);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(long *)(param_1 + 0x10) = local_68;
    goto LAB_180003540;
  }
  (**(code **)(*(longlong *)this + 0xa8))
            (this,&local_a8,CONCAT71(in_stack_00000029,param_4),param_5 * '\x02' + '\x16',2);
  if (local_98 < 0) {
    Logging::Verify::StatusFailed("specificKey",local_98);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(long *)(param_1 + 0x10) = local_98;
  }
  else {
    pRVar1 = this + 8;
    iVar3 = (**(code **)(*(longlong *)pRVar1 + 0x68))(pRVar1);
    iVar4 = (**(code **)(*(longlong *)this + 0xe0))(this);
    if (iVar3 != iVar4) {
                    /* WARNING: Subroutine does not return */
      ConsistencyFail((ushort *)
                      L"A cipher suite\'s included checksum must be the required checksum for the included cipher"
                     );
    }
    (**(code **)(*(longlong *)pRVar1 + 0x58))(pRVar1,local_60,&local_a8,local_78);
    if (local_50 < 0) {
      Logging::Verify::StatusFailed("mic",local_50);
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
LAB_18000351d:
      *(long *)(param_1 + 0x10) = local_50;
    }
    else {
      uVar2 = local_60[0] >> 8 | local_60[0] << 8;
      local_8c = CONCAT22(uVar2,uVar2);
      Concatenate((ReadOnlyBinary *)&local_38,(ReadOnlyBinary *)&local_48);
      if (-1 < local_28) {
        *(undefined8 *)param_1 = local_38;
        *(void **)(param_1 + 8) = local_30;
        local_50 = local_28;
        goto LAB_18000351d;
      }
      Logging::Verify::StatusFailed("resultBuffer",local_28);
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(long *)(param_1 + 0x10) = local_28;
      if (local_30 != (void *)0x0) {
        operator_delete__(local_30);
      }
    }
    if (local_58 != (void *)0x0) {
      operator_delete__(local_58);
    }
  }
  if (local_a0 != 0) {
    EncryptionAlgorithm::_vcall__160__flat______(local_a8);
  }
LAB_180003540:
  if (local_70 != (void *)0x0) {
    operator_delete__(local_70);
  }
  return param_1;
}



===== CompatibleCipher @ 180003590 =====

/* protected: virtual bool __cdecl Kerb3961::SimplifiedCipherSuite::CompatibleCipher(unsigned int)
   __ptr64 */

bool __thiscall
Kerb3961::SimplifiedCipherSuite::CompatibleCipher(SimplifiedCipherSuite *this,uint param_1)

{
  return param_1 == *(uint *)(this + 0x10);
}



===== Concatenate @ 1800035a0 =====

/* WARNING: Removing unreachable block (ram,0x000180003691) */
/* struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct Kerb3961::ResultBlock const &
   __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::OwnedBinary,16>(struct
   Kerb3961::OwnedBinary const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)>
   __cdecl Kerb3961::Concatenate(struct Kerb3961::ReadOnlyBinary const & __ptr64,struct
   Kerb3961::ReadOnlyBinary const & __ptr64,struct Kerb3961::ReadOnlyBinary const & __ptr64) */

ReadOnlyBinary * __cdecl
Kerb3961::Concatenate(ReadOnlyBinary *param_1,ReadOnlyBinary *param_2,ReadOnlyBinary *param_3)

{
  size_t _Size;
  ulonglong *puVar1;
  char *pcVar2;
  ulonglong uVar3;
  size_t *psVar4;
  undefined8 *in_R9;
  void *_Dst;
  void *local_res8;
  ulonglong local_48;
  size_t asStack_40 [5];
  
  puVar1 = &local_48;
  uVar3 = 0;
  local_48 = *(ulonglong *)param_2;
  asStack_40[0] = *(size_t *)(param_2 + 8);
  asStack_40[1] = *(undefined8 *)param_3;
  asStack_40[2] = *(undefined8 *)(param_3 + 8);
  asStack_40[3] = *in_R9;
  asStack_40[4] = in_R9[1];
  do {
    if (puVar1 == asStack_40 + 5) {
      if (uVar3 < 0x100000000) {
        if (uVar3 == 0) {
          *(undefined8 *)param_1 = 0;
          *(undefined8 *)(param_1 + 8) = 0;
        }
        else {
          utl::make_unique<unsigned_char_[0],0>((__uint64)&local_res8);
          if (local_res8 == (void *)0x0) {
            Logging::Verify::ConditionFailed("result");
            *(undefined8 *)param_1 = 0;
            *(undefined8 *)(param_1 + 8) = 0;
            *(undefined4 *)(param_1 + 0x10) = 0xc0000017;
            return param_1;
          }
          _Dst = local_res8;
          for (psVar4 = &local_48; psVar4 != asStack_40 + 5; psVar4 = psVar4 + 2) {
            _Size = *psVar4;
            memmove(_Dst,(void *)psVar4[1],_Size);
            _Dst = (void *)((longlong)_Dst + _Size);
          }
          *(ulonglong *)param_1 = uVar3;
          *(void **)(param_1 + 8) = local_res8;
        }
        *(undefined4 *)(param_1 + 0x10) = 0;
      }
      else {
        pcVar2 = "length <= utl::numeric_limits<uint32_t>::max()";
LAB_1800036a2:
        Logging::Verify::ConditionFailed(pcVar2);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(undefined4 *)(param_1 + 0x10) = 0xc0000095;
      }
      return param_1;
    }
    if (0xffffffff < *puVar1) {
      pcVar2 = "entry.length <= utl::numeric_limits<uint32_t>::max()";
      goto LAB_1800036a2;
    }
    uVar3 = uVar3 + *puVar1;
    puVar1 = puVar1 + 2;
  } while( true );
}



===== Concatenate @ 1800036dc =====

/* WARNING: Removing unreachable block (ram,0x0001800037c5) */
/* struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct Kerb3961::ResultBlock const &
   __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::OwnedBinary,16>(struct
   Kerb3961::OwnedBinary const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)>
   __cdecl Kerb3961::Concatenate(struct Kerb3961::ReadOnlyBinary const & __ptr64,struct
   Kerb3961::ReadOnlyBinary const & __ptr64) */

ReadOnlyBinary * __cdecl Kerb3961::Concatenate(ReadOnlyBinary *param_1,ReadOnlyBinary *param_2)

{
  size_t _Size;
  ulonglong *puVar1;
  char *pcVar2;
  ulonglong uVar3;
  size_t *psVar4;
  undefined8 *in_R8;
  void *_Dst;
  void *local_res8;
  ulonglong local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong uStack_20;
  
  puVar1 = &local_38;
  uVar3 = 0;
  local_38 = *(ulonglong *)param_2;
  uStack_30 = *(undefined8 *)(param_2 + 8);
  local_28 = *in_R8;
  uStack_20 = in_R8[1];
  do {
    if (puVar1 == (ulonglong *)((longlong)register0x00000020 + -0x18)) {
      if (uVar3 < 0x100000000) {
        if (uVar3 == 0) {
          *(undefined8 *)param_1 = 0;
          *(undefined8 *)(param_1 + 8) = 0;
        }
        else {
          utl::make_unique<unsigned_char_[0],0>((__uint64)&local_res8);
          if (local_res8 == (void *)0x0) {
            Logging::Verify::ConditionFailed("result");
            *(undefined8 *)param_1 = 0;
            *(undefined8 *)(param_1 + 8) = 0;
            *(undefined4 *)(param_1 + 0x10) = 0xc0000017;
            return param_1;
          }
          _Dst = local_res8;
          for (psVar4 = &local_38; psVar4 != (size_t *)((longlong)register0x00000020 + -0x18);
              psVar4 = psVar4 + 2) {
            _Size = *psVar4;
            memmove(_Dst,(void *)psVar4[1],_Size);
            _Dst = (void *)((longlong)_Dst + _Size);
          }
          *(ulonglong *)param_1 = uVar3;
          *(void **)(param_1 + 8) = local_res8;
        }
        *(undefined4 *)(param_1 + 0x10) = 0;
      }
      else {
        pcVar2 = "length <= utl::numeric_limits<uint32_t>::max()";
LAB_1800037d6:
        Logging::Verify::ConditionFailed(pcVar2);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(undefined4 *)(param_1 + 0x10) = 0xc0000095;
      }
      return param_1;
    }
    if (0xffffffff < *puVar1) {
      pcVar2 = "entry.length <= utl::numeric_limits<uint32_t>::max()";
      goto LAB_1800037d6;
    }
    uVar3 = uVar3 + *puVar1;
    puVar1 = puVar1 + 2;
  } while( true );
}



===== ConsistencyFail @ 180003810 =====

/* void __cdecl Kerb3961::ConsistencyFail(unsigned short const * __ptr64) */

void __cdecl Kerb3961::ConsistencyFail(ushort *param_1)

{
  code *pcVar1;
  
  Logging::Verify::ConsistencyFail(param_1);
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(0x29c);
  return;
}



===== CopyBuffer @ 18000382c =====

/* WARNING: Removing unreachable block (ram,0x00018000388f) */
/* struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct Kerb3961::ResultBlock const &
   __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::OwnedBinary,16>(struct
   Kerb3961::OwnedBinary const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)>
   __cdecl Kerb3961::CopyBuffer(struct Kerb3961::ReadOnlyBinary const & __ptr64) */

ReadOnlyBinary * __cdecl Kerb3961::CopyBuffer(ReadOnlyBinary *param_1)

{
  size_t sVar1;
  size_t *in_RDX;
  void *local_res10;
  
  if (*in_RDX == 0) {
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  else {
    utl::make_unique<unsigned_char_[0],0>((__uint64)&local_res10);
    if (local_res10 == (void *)0x0) {
      Logging::Verify::ConditionFailed("copy");
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(undefined4 *)(param_1 + 0x10) = 0xc0000017;
    }
    else {
      memmove(local_res10,(void *)in_RDX[1],*in_RDX);
      sVar1 = *in_RDX;
      *(undefined4 *)(param_1 + 0x10) = 0;
      *(size_t *)param_1 = sVar1;
      *(void **)(param_1 + 8) = local_res10;
    }
  }
  return param_1;
}



===== Decrypt @ 1800038d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::SimplifiedCipherSuite::Decrypt(struct Kerb3961::ReturnType<struct
   Kerb3961::SpecificKeyReturn,&struct Kerb3961::ResultBlock const & __ptr64 __cdecl
   Kerb3961::SingleGetter<struct Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn
   const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn & __ptr64)> & __ptr64,struct
   Kerb3961::ReturnType<struct Kerb3961::CipherStateReturn,&struct Kerb3961::ResultBlock const &
   __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::CipherStateReturn,16>(struct
   Kerb3961::CipherStateReturn const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::CipherStateReturn,16>(struct Kerb3961::CipherStateReturn
   & __ptr64)> & __ptr64,struct Kerb3961::ReadOnlyBinary const & __ptr64,struct
   Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64 */

ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
* __thiscall
Kerb3961::SimplifiedCipherSuite::Decrypt
          (SimplifiedCipherSuite *this,
          ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
          *param_1,ReturnType<Kerb3961::CipherStateReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn&___ptr64)>
                   *param_2,ReadOnlyBinary *param_3,ReadOnlyBinary *param_4)

{
  byte *pbVar1;
  byte bVar2;
  longlong lVar3;
  int *piVar4;
  char *pcVar5;
  byte *pbVar6;
  int iVar7;
  byte bVar8;
  longlong lVar9;
  longlong *in_stack_00000030;
  undefined1 auStackY_128 [32];
  ReadOnlyBinary local_f8 [8];
  void *local_f0;
  int local_e8;
  ulonglong local_d8;
  longlong local_d0;
  ulonglong local_c8;
  byte *local_c0;
  long local_b8;
  undefined1 local_b0 [8];
  longlong local_a8;
  undefined8 local_a0;
  undefined1 local_98 [16];
  ulonglong local_88;
  longlong local_80;
  undefined1 local_78 [32];
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_128;
  if (*in_stack_00000030 != 0) {
    DecryptWithTag(this,param_1,param_2,param_3,param_4);
    return param_1;
  }
  if (*(SimplifiedCipherSuite **)param_2 != this) {
    pcVar5 = "specificKey.algorithm == this";
LAB_18000392d:
    Logging::Verify::ConditionFailed(pcVar5);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0xc000000d;
    return param_1;
  }
  lVar3 = *(longlong *)(param_2 + 8);
  local_a8 = *(longlong *)(this + 0x38);
  local_a0 = *(undefined8 *)(param_3 + 8);
  if ((*(longlong *)(lVar3 + 0x18) == 0) && (*(longlong *)(lVar3 + 0x30) == 0)) {
    pcVar5 = "key->Ke.length > 0 || key->Ki.length > 0";
    goto LAB_18000392d;
  }
  local_d0 = *(longlong *)(this + 0x28);
  if (*(ulonglong *)param_4 < (ulonglong)(local_d0 + local_a8)) {
    pcVar5 = "cipherText.length >= m_hmacSize + m_cipherBlockSize";
    goto LAB_18000392d;
  }
  local_d8 = *(ulonglong *)param_4 - local_d0;
  lVar9 = local_d8 - local_a8;
  if (local_d8 % *(ulonglong *)(this + 0x30) != 0) {
    pcVar5 = "encryptSize % m_messageBlockSize == 0";
    goto LAB_18000392d;
  }
  Split<2>(local_98,param_4,&local_d8);
  CopyBuffer(local_f8);
  if (local_e8 < 0) {
    pcVar5 = "cipherTextCopy";
    iVar7 = local_e8;
  }
  else {
    piVar4 = (int *)(**(code **)(*(longlong *)this + 0x198))(this,local_b0,lVar3 + 0x18,&local_a8);
    iVar7 = *piVar4;
    if (-1 < iVar7) {
      (**(code **)(*(longlong *)this + 0x188))(this,&local_c8,lVar3 + 0x30,local_f8);
      if (local_b8 < 0) {
        Logging::Verify::StatusFailed("hmac",local_b8);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(long *)(param_1 + 0x10) = local_b8;
      }
      else if (local_c8 == local_88) {
        if (local_c8 != 0) {
          if (0xffffffff < local_c8) goto LAB_180003af7;
          bVar8 = 0;
          if ((int)local_c8 != 0) {
            local_c8 = local_c8 & 0xffffffff;
            pbVar6 = local_c0;
            do {
              pbVar1 = pbVar6 + (local_80 - (longlong)local_c0);
              bVar2 = *pbVar6;
              pbVar6 = pbVar6 + 1;
              bVar8 = bVar8 | *pbVar1 ^ bVar2;
              local_c8 = local_c8 - 1;
            } while (local_c8 != 0);
            if (bVar8 != 0) goto LAB_180003af7;
          }
        }
        if (lVar9 == 0) {
          *(undefined8 *)param_1 = 0;
          *(undefined8 *)(param_1 + 8) = 0;
          *(undefined4 *)(param_1 + 0x10) = 0;
        }
        else {
          local_d8 = *(ulonglong *)(this + 0x38);
          local_d0 = lVar9;
          Split<2>(local_78,local_f8,&local_d8);
          CopyBuffer((ReadOnlyBinary *)param_1);
        }
      }
      else {
LAB_180003af7:
        Logging::Verify::ConditionFailed("SecureEqualBuffer(hmac, checksum)");
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(undefined4 *)(param_1 + 0x10) = 0x8009030f;
      }
      if (local_c0 != (byte *)0x0) {
        operator_delete__(local_c0);
      }
      goto LAB_180003b1f;
    }
    pcVar5 = "BlockDecrypt(key->Ke, IV, cipherTextCopy)";
  }
  Logging::Verify::StatusFailed(pcVar5,iVar7);
  *(undefined8 *)param_1 = 0;
  *(undefined8 *)(param_1 + 8) = 0;
  *(int *)(param_1 + 0x10) = iVar7;
LAB_180003b1f:
  if (local_f0 == (void *)0x0) {
    return param_1;
  }
  operator_delete__(local_f0);
  return param_1;
}



===== DecryptWithTag @ 180003b58 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct Kerb3961::ResultBlock
   const & __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::OwnedBinary,16>(struct
   Kerb3961::OwnedBinary const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)>
   __cdecl Kerb3961::SimplifiedCipherSuite::DecryptWithTag(struct Kerb3961::ReturnType<struct
   Kerb3961::SpecificKeyReturn,&struct Kerb3961::ResultBlock const & __ptr64 __cdecl
   Kerb3961::SingleGetter<struct Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn
   const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn & __ptr64)> & __ptr64,struct
   Kerb3961::ReturnType<struct Kerb3961::CipherStateReturn,&struct Kerb3961::ResultBlock const &
   __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::CipherStateReturn,16>(struct
   Kerb3961::CipherStateReturn const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::CipherStateReturn,16>(struct Kerb3961::CipherStateReturn
   & __ptr64)> & __ptr64,struct Kerb3961::ReadOnlyBinary const & __ptr64,struct
   Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64 */

ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
* __thiscall
Kerb3961::SimplifiedCipherSuite::DecryptWithTag
          (SimplifiedCipherSuite *this,
          ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
          *param_1,ReturnType<Kerb3961::CipherStateReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn&___ptr64)>
                   *param_2,ReadOnlyBinary *param_3,ReadOnlyBinary *param_4)

{
  byte *pbVar1;
  byte bVar2;
  longlong lVar3;
  int *piVar4;
  char *pcVar5;
  byte *pbVar6;
  int iVar7;
  byte bVar8;
  longlong lVar9;
  ReadOnlyBinary *in_stack_00000030;
  undefined1 auStack_138 [32];
  ReadOnlyBinary *local_118;
  ReadOnlyBinary local_108 [8];
  void *local_100;
  int local_f8;
  ulonglong local_e8;
  longlong local_e0;
  ulonglong local_d8;
  byte *local_d0;
  long local_c8;
  ReadOnlyBinary local_c0 [8];
  void *local_b8;
  long local_b0;
  undefined1 local_a8 [8];
  ReadOnlyBinary *local_a0;
  longlong local_98;
  undefined8 local_90;
  undefined1 local_88 [16];
  ulonglong local_78;
  longlong local_70;
  ReadOnlyBinary local_68 [32];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_138;
  local_a0 = in_stack_00000030;
  if (*(SimplifiedCipherSuite **)param_2 != this) {
    Logging::Verify::ConditionFailed("specificKey.algorithm == this");
    goto LAB_180003ba7;
  }
  lVar3 = *(longlong *)(param_2 + 8);
  local_98 = *(longlong *)(this + 0x38);
  local_90 = *(undefined8 *)(param_3 + 8);
  if ((*(longlong *)(lVar3 + 0x18) == 0) && (*(longlong *)(lVar3 + 0x30) == 0)) {
    pcVar5 = "key->Ke.length > 0 || key->Ki.length > 0";
  }
  else {
    local_e0 = *(longlong *)(this + 0x28);
    if (*(ulonglong *)param_4 < (ulonglong)(local_e0 + local_98)) {
      pcVar5 = "cipherText.length >= m_hmacSize + m_cipherBlockSize";
    }
    else {
      local_e8 = *(ulonglong *)param_4 - local_e0;
      lVar9 = local_e8 - local_98;
      if (local_e8 % *(ulonglong *)(this + 0x30) == 0) {
        Split<2>(local_88,param_4,&local_e8);
        CopyBuffer(local_108);
        if (local_f8 < 0) {
          pcVar5 = "decrypted";
          iVar7 = local_f8;
        }
        else {
          local_118 = local_108;
          piVar4 = (int *)(**(code **)(*(longlong *)this + 0x198))
                                    (this,local_a8,lVar3 + 0x18,&local_98);
          iVar7 = *piVar4;
          if (-1 < iVar7) {
            local_e8 = *(ulonglong *)(this + 0x38);
            local_e0 = lVar9;
            Split<2>(local_68,local_108,&local_e8);
            Concatenate(local_c0,local_68,local_a0);
            if (local_b0 < 0) {
              Logging::Verify::StatusFailed("checksumData",local_b0);
              *(undefined8 *)param_1 = 0;
              *(undefined8 *)(param_1 + 8) = 0;
              *(long *)(param_1 + 0x10) = local_b0;
            }
            else {
              (**(code **)(*(longlong *)this + 0x188))(this,&local_d8,lVar3 + 0x30,local_c0);
              if (local_c8 < 0) {
                Logging::Verify::StatusFailed("hmac",local_c8);
                *(undefined8 *)param_1 = 0;
                *(undefined8 *)(param_1 + 8) = 0;
                *(long *)(param_1 + 0x10) = local_c8;
              }
              else if (local_d8 == local_78) {
                if (local_d8 != 0) {
                  if (0xffffffff < local_d8) goto LAB_180003dad;
                  bVar8 = 0;
                  if ((int)local_d8 != 0) {
                    local_d8 = local_d8 & 0xffffffff;
                    pbVar6 = local_d0;
                    do {
                      pbVar1 = pbVar6 + (local_70 - (longlong)local_d0);
                      bVar2 = *pbVar6;
                      pbVar6 = pbVar6 + 1;
                      bVar8 = bVar8 | *pbVar1 ^ bVar2;
                      local_d8 = local_d8 - 1;
                    } while (local_d8 != 0);
                    if (bVar8 != 0) goto LAB_180003dad;
                  }
                }
                if (lVar9 == 0) {
                  *(undefined8 *)param_1 = 0;
                  *(undefined8 *)(param_1 + 8) = 0;
                  *(undefined4 *)(param_1 + 0x10) = 0;
                }
                else {
                  CopyBuffer((ReadOnlyBinary *)param_1);
                }
              }
              else {
LAB_180003dad:
                Logging::Verify::ConditionFailed("SecureEqualBuffer(hmac, checksum)");
                *(undefined8 *)param_1 = 0;
                *(undefined8 *)(param_1 + 8) = 0;
                *(undefined4 *)(param_1 + 0x10) = 0x8009030f;
              }
              if (local_d0 != (byte *)0x0) {
                operator_delete__(local_d0);
              }
            }
            if (local_b8 != (void *)0x0) {
              operator_delete__(local_b8);
            }
            goto LAB_180003de4;
          }
          pcVar5 = "BlockDecrypt(key->Ke, IV, decrypted)";
        }
        Logging::Verify::StatusFailed(pcVar5,iVar7);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(int *)(param_1 + 0x10) = iVar7;
LAB_180003de4:
        if (local_100 == (void *)0x0) {
          return param_1;
        }
        operator_delete__(local_100);
        return param_1;
      }
      pcVar5 = "encryptSize % m_messageBlockSize == 0";
    }
  }
  Logging::Verify::ConditionFailed(pcVar5);
LAB_180003ba7:
  *(undefined8 *)param_1 = 0;
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0xc000000d;
  return param_1;
}



===== DeriveKey @ 180003e24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct Kerb3961::ResultBlock
   const & __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::OwnedBinary,16>(struct
   Kerb3961::OwnedBinary const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)>
   __cdecl Kerb3961::SimplifiedCipherSuite::DeriveKey(struct Kerb3961::ReadOnlyBinary const &
   __ptr64,struct Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64 */

ReadOnlyBinary * __thiscall
Kerb3961::SimplifiedCipherSuite::DeriveKey
          (SimplifiedCipherSuite *this,ReadOnlyBinary *param_1,ReadOnlyBinary *param_2)

{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined1 local_res8 [8];
  undefined8 local_78;
  void *local_70;
  long local_68;
  undefined1 local_60 [8];
  void *local_58;
  long local_50;
  undefined1 local_48 [8];
  void *local_40;
  int local_38;
  
  uVar5 = ((*(longlong *)(this + 0x20) - 1U) -
          (*(longlong *)(this + 0x20) - 1U) % *(ulonglong *)(this + 0x38)) +
          *(ulonglong *)(this + 0x38);
  MakeBuffer((__uint64)&local_78);
  if (local_68 < 0) {
    Logging::Verify::StatusFailed("workSpace",local_68);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(long *)(param_1 + 0x10) = local_68;
  }
  else {
    MakeBuffer((__uint64)local_60);
    if (local_50 < 0) {
      Logging::Verify::StatusFailed("IV",local_50);
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(long *)(param_1 + 0x10) = local_50;
    }
    else {
      Nfold((__uint64)local_48,*(ReadOnlyBinary **)(this + 0x38));
      if (local_38 < 0) {
        pcVar2 = "nfoldConstant";
        iVar3 = local_38;
LAB_180003ee8:
        Logging::Verify::StatusFailed(pcVar2,iVar3);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(int *)(param_1 + 0x10) = iVar3;
      }
      else {
        uVar4 = 0;
        if (uVar5 != 0) {
          do {
            memset(local_58,0,*(size_t *)(this + 0x38));
            piVar1 = (int *)(**(code **)(*(longlong *)this + 400))
                                      (this,local_res8,param_2,local_60,local_48);
            iVar3 = *piVar1;
            if (iVar3 < 0) {
              pcVar2 = "BlockEncrypt(baseKey, IV, nfoldConstant)";
              goto LAB_180003ee8;
            }
            memmove((void *)((longlong)local_70 + uVar4),local_40,*(size_t *)(this + 0x38));
            uVar4 = uVar4 + *(longlong *)(this + 0x38);
          } while (uVar4 < uVar5);
        }
        local_78 = *(undefined8 *)(this + 0x20);
        (**(code **)(*(longlong *)this + 0x80))(this,param_1,&local_78);
      }
      if (local_40 != (void *)0x0) {
        operator_delete__(local_40);
      }
    }
    if (local_58 != (void *)0x0) {
      operator_delete__(local_58);
    }
  }
  if (local_70 != (void *)0x0) {
    operator_delete__(local_70);
  }
  return param_1;
}



===== DeriveSpecificKey @ 180003ff0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: virtual struct Kerb3961::ReturnType<struct Kerb3961::SpecificKeyReturn,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn & __ptr64)> __cdecl
   Kerb3961::SimplifiedCipherSuite::DeriveSpecificKey(struct Kerb3961::ReadOnlyBinary const &
   __ptr64,enum Kerb3961::KeyUsage,enum Kerb3961::SpecificKeyScenario) __ptr64 */

ReadOnlyBinary * __thiscall
Kerb3961::SimplifiedCipherSuite::DeriveSpecificKey
          (SimplifiedCipherSuite *this,ReadOnlyBinary *param_1,KeyUsage param_2,
          SpecificKeyScenario param_3)

{
  long lVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  char *pcVar4;
  int iVar5;
  undefined4 in_register_00000084;
  ReadOnlyBinary *pRVar6;
  int in_stack_00000028;
  undefined1 auStack_98 [32];
  ReadOnlyBinary local_78 [8];
  void *local_70;
  int local_68;
  undefined8 *local_60;
  undefined8 *local_58;
  undefined8 local_48;
  ulonglong local_40;
  
  pRVar6 = (ReadOnlyBinary *)CONCAT44(in_register_00000084,param_2);
  local_40 = __security_cookie ^ (ulonglong)auStack_98;
  local_48 = (ulonglong)
             (param_3 >> 0x18 | (param_3 & 0xff0000) >> 8 | (param_3 & 0xff00) << 8 |
             param_3 << 0x18);
  utl::make_unique<Kerb3961::SimplifiedSpecificKey,0>();
  puVar2 = local_60;
  if (local_60 == (undefined8 *)0x0) {
    Logging::Verify::ConditionFailed("specificKey");
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0xc0000017;
  }
  else {
    if (in_stack_00000028 - 2U < 2) {
      local_58 = &local_48;
      local_48._0_5_ = CONCAT14(0x99,(undefined4)local_48);
      local_60 = (undefined8 *)0x5;
      DeriveKey(this,local_78,pRVar6);
      if (-1 < local_68) {
        puVar3 = (undefined8 *)(**(code **)(*(longlong *)this + 0x80))(this,&local_60,local_78);
        if ((void *)puVar2[1] != (void *)0x0) {
          operator_delete__((void *)puVar2[1]);
        }
        *puVar2 = *puVar3;
        *puVar3 = 0;
        puVar2[1] = puVar3[1];
        puVar3[1] = 0;
        *(undefined4 *)(puVar2 + 2) = *(undefined4 *)(puVar3 + 2);
        *(undefined4 *)(puVar3 + 2) = 0xc0000001;
        lVar1 = *(long *)(puVar2 + 2);
        if (local_58 != (undefined8 *)0x0) {
          operator_delete__(local_58);
        }
        if (lVar1 < 0) {
          Logging::Verify::StatusFailed("specificKey->Kc = RandomToKey(derivedKey)",lVar1);
          *(undefined8 *)param_1 = 0;
          *(undefined8 *)(param_1 + 8) = 0;
          *(long *)(param_1 + 0x10) = lVar1;
          if (local_70 != (void *)0x0) {
            operator_delete__(local_70);
          }
          goto LAB_180004130;
        }
        if (local_70 != (void *)0x0) {
          operator_delete__(local_70);
        }
        goto LAB_180004175;
      }
LAB_18000409c:
      pcVar4 = "derivedKey";
      iVar5 = local_68;
    }
    else {
LAB_180004175:
      if ((in_stack_00000028 - 1U & 0xfffffffd) != 0) {
LAB_180004306:
        *(SimplifiedCipherSuite **)param_1 = this;
        *(undefined8 **)(param_1 + 8) = puVar2;
        *(undefined4 *)(param_1 + 0x10) = 0;
        return param_1;
      }
      local_58 = &local_48;
      local_48._0_5_ = CONCAT14(0xaa,(undefined4)local_48);
      local_60 = (undefined8 *)0x5;
      DeriveKey(this,local_78,pRVar6);
      if (local_68 < 0) goto LAB_18000409c;
      puVar3 = (undefined8 *)(**(code **)(*(longlong *)this + 0x80))(this,&local_60,local_78);
      if ((void *)puVar2[4] != (void *)0x0) {
        operator_delete__((void *)puVar2[4]);
      }
      puVar2[3] = *puVar3;
      *puVar3 = 0;
      puVar2[4] = puVar3[1];
      puVar3[1] = 0;
      *(undefined4 *)(puVar2 + 5) = *(undefined4 *)(puVar3 + 2);
      *(undefined4 *)(puVar3 + 2) = 0xc0000001;
      iVar5 = *(int *)(puVar2 + 5);
      if (local_58 != (undefined8 *)0x0) {
        operator_delete__(local_58);
      }
      if (iVar5 < 0) {
        pcVar4 = "specificKey->Ke = RandomToKey(derivedKey)";
      }
      else {
        if (local_70 != (void *)0x0) {
          operator_delete__(local_70);
        }
        local_58 = &local_48;
        local_48._0_5_ = CONCAT14(0x55,(undefined4)local_48);
        local_60 = (undefined8 *)0x5;
        DeriveKey(this,local_78,pRVar6);
        if (local_68 < 0) goto LAB_18000409c;
        puVar3 = (undefined8 *)(**(code **)(*(longlong *)this + 0x80))(this,&local_60,local_78);
        if ((void *)puVar2[7] != (void *)0x0) {
          operator_delete__((void *)puVar2[7]);
        }
        puVar2[6] = *puVar3;
        *puVar3 = 0;
        puVar2[7] = puVar3[1];
        puVar3[1] = 0;
        *(undefined4 *)(puVar2 + 8) = *(undefined4 *)(puVar3 + 2);
        *(undefined4 *)(puVar3 + 2) = 0xc0000001;
        iVar5 = *(int *)(puVar2 + 8);
        if (local_58 != (undefined8 *)0x0) {
          operator_delete__(local_58);
        }
        if (-1 < iVar5) {
          if (local_70 != (void *)0x0) {
            operator_delete__(local_70);
          }
          goto LAB_180004306;
        }
        pcVar4 = "specificKey->Ki = RandomToKey(derivedKey)";
      }
    }
    Logging::Verify::StatusFailed(pcVar4,iVar5);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(int *)(param_1 + 0x10) = iVar5;
    if (local_70 != (void *)0x0) {
      operator_delete__(local_70);
    }
  }
  if (puVar2 == (undefined8 *)0x0) {
    return param_1;
  }
LAB_180004130:
  if ((void *)puVar2[7] != (void *)0x0) {
    operator_delete__((void *)puVar2[7]);
  }
  if ((void *)puVar2[4] != (void *)0x0) {
    operator_delete__((void *)puVar2[4]);
  }
  if ((void *)puVar2[1] != (void *)0x0) {
    operator_delete__((void *)puVar2[1]);
  }
  operator_delete__(puVar2);
  return param_1;
}



===== EnabledForUsage @ 180004340 =====

/* private: bool __cdecl Kerb3961::Aes3962::EnabledForUsage(struct
   Kerb3961::KeyPolicyScenario,unsigned int) __ptr64 */

bool __thiscall Kerb3961::Aes3962::EnabledForUsage(Aes3962 *this,char *param_2,uint param_3)

{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  
  bVar3 = (byte)param_3 >> 3;
  if (*(longlong *)(this + 0x40) != 0x10) {
    bVar3 = (byte)param_3 >> 4;
  }
  bVar2 = false;
  if (((param_3 & 0x20) == 0) || (bVar1 = true, (byte)(*param_2 - 1U) < 2)) {
    bVar1 = false;
  }
  if (((param_2[1] == '\x02') || ((bVar3 & 1) != 0)) || (bVar1)) {
    bVar2 = true;
  }
  Logging::Cipher::UsageEnabled
            (*(ushort **)(this + 0x50),bVar2,CONCAT31((int3)(param_3 >> 8),param_2[1]),param_3);
  return bVar2;
}



===== Encrypt @ 1800043c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::SimplifiedCipherSuite::Encrypt(struct Kerb3961::ReturnType<struct
   Kerb3961::SpecificKeyReturn,&struct Kerb3961::ResultBlock const & __ptr64 __cdecl
   Kerb3961::SingleGetter<struct Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn
   const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn & __ptr64)> & __ptr64,struct
   Kerb3961::ReturnType<struct Kerb3961::CipherStateReturn,&struct Kerb3961::ResultBlock const &
   __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::CipherStateReturn,16>(struct
   Kerb3961::CipherStateReturn const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::CipherStateReturn,16>(struct Kerb3961::CipherStateReturn
   & __ptr64)> & __ptr64,struct Kerb3961::ReadOnlyBinary const & __ptr64,struct
   Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64 */

ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
* __thiscall
Kerb3961::SimplifiedCipherSuite::Encrypt
          (SimplifiedCipherSuite *this,
          ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
          *param_1,ReturnType<Kerb3961::CipherStateReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn&___ptr64)>
                   *param_2,ReadOnlyBinary *param_3,ReadOnlyBinary *param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  NTSTATUS NVar3;
  int *piVar4;
  char *pcVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong *in_stack_00000030;
  undefined1 auStackY_138 [32];
  undefined8 local_108;
  void *local_100;
  long local_f8;
  longlong local_f0;
  longlong local_e8;
  undefined8 local_e0;
  longlong local_d8;
  size_t local_c8;
  void *local_c0;
  int local_b8;
  longlong local_b0;
  undefined8 local_a8;
  undefined1 local_a0 [24];
  void *local_88;
  ULONG local_80 [2];
  PUCHAR local_78;
  void *local_68;
  ULONG local_60;
  PUCHAR local_58;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStackY_138;
  if (*in_stack_00000030 != 0) {
    EncryptWithTag(this,param_1,param_2,param_3,param_4);
    return param_1;
  }
  if (*(SimplifiedCipherSuite **)param_2 != this) {
    pcVar5 = "specificKey.algorithm == this";
LAB_18000441d:
    Logging::Verify::ConditionFailed(pcVar5);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0xc000000d;
    return param_1;
  }
  lVar1 = *(longlong *)(param_2 + 8);
  local_b0 = *(longlong *)(this + 0x38);
  local_a8 = *(undefined8 *)(param_3 + 8);
  if ((*(longlong *)(lVar1 + 0x18) == 0) && (*(longlong *)(lVar1 + 0x30) == 0)) {
    pcVar5 = "key->Ke.length > 0 || key->Ki.length > 0";
    goto LAB_18000441d;
  }
  uVar2 = *(ulonglong *)param_4;
  uVar6 = (uVar2 - 1) + local_b0;
  lVar7 = (uVar6 - uVar6 % *(ulonglong *)(this + 0x30)) + *(ulonglong *)(this + 0x30);
  local_f0 = (lVar7 - uVar2) - local_b0;
  if ((ulonglong)(*(longlong *)(this + 0x28) + lVar7) <= uVar2) {
    Logging::Verify::ConditionFailed("finalSize > clearData.length");
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0xc0000095;
    return param_1;
  }
  MakeBuffer((__uint64)&local_108);
  if (local_f8 < 0) {
    Logging::Verify::StatusFailed("result",local_f8);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
LAB_18000467a:
    *(long *)(param_1 + 0x10) = local_f8;
  }
  else {
    local_e0 = *(undefined8 *)(this + 0x28);
    local_e8 = lVar7;
    Split<2>(local_a0,&local_108,&local_e8);
    local_e8 = *(longlong *)(this + 0x38);
    local_e0 = *(undefined8 *)param_4;
    local_d8 = local_f0;
    Split<3>(local_80,local_a0,&local_e8);
    NVar3 = BCryptGenRandom((BCRYPT_ALG_HANDLE)0x0,local_78,local_80[0],2);
    if (NVar3 < 0) {
      Logging::Verify::StatusFailed("RandomFill(confounder)",NVar3);
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
    }
    else {
      memmove(local_68,*(void **)(param_4 + 8),*(size_t *)param_4);
      NVar3 = BCryptGenRandom((BCRYPT_ALG_HANDLE)0x0,local_58,local_60,2);
      if (-1 < NVar3) {
        (**(code **)(*(longlong *)this + 0x188))(this,&local_c8,lVar1 + 0x30,local_a0);
        if (local_b8 < 0) {
          pcVar5 = "hmac";
        }
        else {
          memmove(local_88,local_c0,local_c8);
          piVar4 = (int *)(**(code **)(*(longlong *)this + 400))
                                    (this,&local_f0,lVar1 + 0x18,&local_b0);
          local_b8 = *piVar4;
          if (-1 < local_b8) {
            *(undefined8 *)param_1 = local_108;
            *(void **)(param_1 + 8) = local_100;
            local_100 = local_c0;
            goto LAB_18000467a;
          }
          pcVar5 = "BlockEncrypt(key->Ke, IV, encryptedPart)";
        }
        Logging::Verify::StatusFailed(pcVar5,local_b8);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(int *)(param_1 + 0x10) = local_b8;
        if (local_c0 != (void *)0x0) {
          operator_delete__(local_c0);
        }
        goto LAB_18000467e;
      }
      Logging::Verify::StatusFailed("RandomFill(pad)",NVar3);
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
    }
    *(NTSTATUS *)(param_1 + 0x10) = NVar3;
  }
LAB_18000467e:
  if (local_100 == (void *)0x0) {
    return param_1;
  }
  operator_delete__(local_100);
  return param_1;
}



===== EncryptWithTag @ 1800046b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct Kerb3961::ResultBlock
   const & __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::OwnedBinary,16>(struct
   Kerb3961::OwnedBinary const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)>
   __cdecl Kerb3961::SimplifiedCipherSuite::EncryptWithTag(struct Kerb3961::ReturnType<struct
   Kerb3961::SpecificKeyReturn,&struct Kerb3961::ResultBlock const & __ptr64 __cdecl
   Kerb3961::SingleGetter<struct Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn
   const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn & __ptr64)> & __ptr64,struct
   Kerb3961::ReturnType<struct Kerb3961::CipherStateReturn,&struct Kerb3961::ResultBlock const &
   __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::CipherStateReturn,16>(struct
   Kerb3961::CipherStateReturn const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::CipherStateReturn,16>(struct Kerb3961::CipherStateReturn
   & __ptr64)> & __ptr64,struct Kerb3961::ReadOnlyBinary const & __ptr64,struct
   Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64 */

ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
* __thiscall
Kerb3961::SimplifiedCipherSuite::EncryptWithTag
          (SimplifiedCipherSuite *this,
          ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
          *param_1,ReturnType<Kerb3961::CipherStateReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn&___ptr64)>
                   *param_2,ReadOnlyBinary *param_3,ReadOnlyBinary *param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  ULONG UVar3;
  ULONG UVar4;
  ULONG UVar5;
  ULONG UVar6;
  NTSTATUS NVar7;
  int *piVar8;
  ulonglong uVar9;
  char *pcVar10;
  longlong lVar11;
  ULONG *in_stack_00000030;
  undefined1 auStack_168 [32];
  undefined1 *local_148;
  undefined8 local_138;
  void *local_130;
  long local_128;
  longlong local_120;
  longlong local_118;
  undefined8 local_110;
  longlong local_108;
  size_t local_f8;
  void *local_f0;
  int local_e8;
  undefined1 local_e0 [8];
  void *local_d8;
  long local_d0;
  ULONG *local_c8;
  longlong local_c0;
  undefined8 local_b8;
  ULONG local_a8 [2];
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  ULONG local_98;
  ULONG UStack_94;
  ULONG UStack_90;
  ULONG UStack_8c;
  ULONG local_88;
  ULONG UStack_84;
  ULONG UStack_80;
  ULONG UStack_7c;
  ULONG local_78;
  ULONG UStack_74;
  ULONG UStack_70;
  ULONG UStack_6c;
  undefined1 local_68 [24];
  void *local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_168;
  local_c8 = in_stack_00000030;
  if (*(SimplifiedCipherSuite **)param_2 == this) {
    lVar1 = *(longlong *)(param_2 + 8);
    local_c0 = *(longlong *)(this + 0x38);
    local_b8 = *(undefined8 *)(param_3 + 8);
    if ((*(longlong *)(lVar1 + 0x18) != 0) || (*(longlong *)(lVar1 + 0x30) != 0)) {
      uVar2 = *(ulonglong *)param_4;
      uVar9 = (uVar2 - 1) + local_c0;
      lVar11 = (*(ulonglong *)(this + 0x30) - uVar9 % *(ulonglong *)(this + 0x30)) + uVar9;
      local_120 = (lVar11 - uVar2) - local_c0;
      if ((ulonglong)(*(longlong *)(this + 0x28) + lVar11) <= uVar2) {
        Logging::Verify::ConditionFailed("finalSize > clearData.length");
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(undefined4 *)(param_1 + 0x10) = 0xc0000095;
        return param_1;
      }
      MakeBuffer((__uint64)&local_138);
      if (local_128 < 0) {
        Logging::Verify::StatusFailed("result",local_128);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(long *)(param_1 + 0x10) = local_128;
      }
      else {
        local_110 = *(undefined8 *)(this + 0x28);
        local_118 = lVar11;
        Split<2>(local_68,&local_138,&local_118);
        local_118 = *(longlong *)(this + 0x38);
        local_110 = *(undefined8 *)param_4;
        local_108 = local_120;
        Split<3>(local_a8,local_68,&local_118);
        NVar7 = BCryptGenRandom((BCRYPT_ALG_HANDLE)0x0,(PUCHAR)CONCAT44(uStack_9c,uStack_a0),
                                local_a8[0],2);
        if (NVar7 < 0) {
          pcVar10 = "RandomFill(confounder)";
        }
        else {
          memmove((void *)CONCAT44(UStack_8c,UStack_90),*(void **)(param_4 + 8),*(size_t *)param_4);
          NVar7 = BCryptGenRandom((BCRYPT_ALG_HANDLE)0x0,(PUCHAR)CONCAT44(UStack_7c,UStack_80),
                                  local_88,2);
          UVar6 = UStack_7c;
          UVar5 = UStack_80;
          UVar4 = UStack_84;
          UVar3 = local_88;
          if (-1 < NVar7) {
            local_88 = local_98;
            UStack_84 = UStack_94;
            UStack_80 = UStack_90;
            UStack_7c = UStack_8c;
            local_78 = UVar3;
            UStack_74 = UVar4;
            UStack_70 = UVar5;
            UStack_6c = UVar6;
            local_98 = *local_c8;
            UStack_94 = local_c8[1];
            UStack_90 = local_c8[2];
            UStack_8c = local_c8[3];
            Concatenate<4>(local_e0,local_a8);
            if (local_d0 < 0) {
              Logging::Verify::StatusFailed("checksumData",local_d0);
              *(undefined8 *)param_1 = 0;
              *(undefined8 *)(param_1 + 8) = 0;
              *(long *)(param_1 + 0x10) = local_d0;
            }
            else {
              (**(code **)(*(longlong *)this + 0x188))(this,&local_f8,lVar1 + 0x30,local_e0);
              if (local_e8 < 0) {
                pcVar10 = "hmac";
              }
              else {
                memmove(local_50,local_f0,local_f8);
                local_148 = local_68;
                piVar8 = (int *)(**(code **)(*(longlong *)this + 400))
                                          (this,&local_120,lVar1 + 0x18,&local_c0);
                local_e8 = *piVar8;
                if (-1 < local_e8) {
                  *(undefined8 *)param_1 = local_138;
                  *(void **)(param_1 + 8) = local_130;
                  *(long *)(param_1 + 0x10) = local_128;
                  if (local_f0 != (void *)0x0) {
                    operator_delete__(local_f0);
                  }
                  local_130 = local_d8;
                  goto LAB_1800049cf;
                }
                pcVar10 = "BlockEncrypt(key->Ke, IV, encryptedPart)";
              }
              Logging::Verify::StatusFailed(pcVar10,local_e8);
              *(undefined8 *)param_1 = 0;
              *(undefined8 *)(param_1 + 8) = 0;
              *(int *)(param_1 + 0x10) = local_e8;
              if (local_f0 != (void *)0x0) {
                operator_delete__(local_f0);
              }
            }
            if (local_d8 != (void *)0x0) {
              operator_delete__(local_d8);
            }
            goto LAB_1800049cf;
          }
          pcVar10 = "RandomFill(pad)";
        }
        Logging::Verify::StatusFailed(pcVar10,NVar7);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(NTSTATUS *)(param_1 + 0x10) = NVar7;
      }
LAB_1800049cf:
      if (local_130 == (void *)0x0) {
        return param_1;
      }
      operator_delete__(local_130);
      return param_1;
    }
    Logging::Verify::ConditionFailed("key->Ke.length > 0 || key->Ki.length > 0");
  }
  else {
    Logging::Verify::ConditionFailed("specificKey.algorithm == this");
  }
  *(undefined8 *)param_1 = 0;
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0xc000000d;
  return param_1;
}



===== EncryptionPrefixLength @ 180004a10 =====

/* protected: virtual unsigned __int64 __cdecl
   Kerb3961::SimplifiedCipherSuite::EncryptionPrefixLength(void) __ptr64 */

__uint64 __thiscall
Kerb3961::SimplifiedCipherSuite::EncryptionPrefixLength(SimplifiedCipherSuite *this)

{
  return *(__uint64 *)(this + 0x38);
}



===== FreeCipherState @ 180004a20 =====

/* protected: virtual void __cdecl Kerb3961::SimplifiedCipherSuite::FreeCipherState(void * __ptr64)
   __ptr64 */

void __thiscall
Kerb3961::SimplifiedCipherSuite::FreeCipherState(SimplifiedCipherSuite *this,void *param_1)

{
  operator_delete__(param_1);
  return;
}



===== FreeSpecificKey @ 180004a40 =====

/* private: virtual void __cdecl Kerb3961::Aes8009::FreeSpecificKey(void * __ptr64) __ptr64 */

void __thiscall Kerb3961::Aes8009::FreeSpecificKey(Aes8009 *this,void *param_1)

{
  if (param_1 != (void *)0x0) {
    if (*(void **)((longlong)param_1 + 0x38) != (void *)0x0) {
      operator_delete__(*(void **)((longlong)param_1 + 0x38));
    }
    if (*(void **)((longlong)param_1 + 0x20) != (void *)0x0) {
      operator_delete__(*(void **)((longlong)param_1 + 0x20));
    }
    if (*(void **)((longlong)param_1 + 8) != (void *)0x0) {
      operator_delete__(*(void **)((longlong)param_1 + 8));
    }
    operator_delete__(param_1);
  }
  return;
}



===== GSSGetMIC @ 180004a90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::SSPICipherSuite<1,1>::GSSGetMIC(struct Kerb3961::ReadOnlyBinary const &
   __ptr64,unsigned __int64,unsigned int,struct Kerb3961::ReadOnlyBinary const & __ptr64,bool,bool)
   __ptr64 */

ReadOnlyBinary * __thiscall
Kerb3961::SSPICipherSuite<1,1>::GSSGetMIC
          (SSPICipherSuite<1,1> *this,ReadOnlyBinary *param_1,__uint64 param_2,uint param_3,
          ReadOnlyBinary *param_4,bool param_5,bool param_6)

{
  undefined7 in_stack_00000031;
  
  if ((int)param_4 == -0x7fffffff) {
    Logging::Verify::ConditionFailed("QOP != KERB_WRAP_NO_ENCRYPT");
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0x8009030a;
  }
  else if (*(ulonglong *)param_2 < 0xffffffffffff0001) {
    (**(code **)(*(longlong *)this + 0x148))
              (this,param_1,param_2,param_3,(int)param_4,CONCAT71(in_stack_00000031,param_5),param_6
              );
  }
  else {
    Logging::Verify::ConditionFailed("inputMessage.length <= MessageLimit");
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0xc0000095;
  }
  return param_1;
}



===== GSSUnwrap @ 180004b40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::UnwrapResult,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::DoubleGetter<struct
   Kerb3961::UnwrapResult,struct Kerb3961::OwnedBinary,0,16>(struct Kerb3961::UnwrapResult const &
   __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::DoubleSetter<struct
   Kerb3961::UnwrapResult,struct Kerb3961::OwnedBinary,0,16>(struct Kerb3961::UnwrapResult &
   __ptr64)> __cdecl Kerb3961::SSPICipherSuite<1,1>::GSSUnwrap(struct Kerb3961::ReadOnlyBinary const
   & __ptr64,struct Kerb3961::ReadOnlyBinary const & __ptr64,bool,bool) __ptr64 */

ReadOnlyBinary * __thiscall
Kerb3961::SSPICipherSuite<1,1>::GSSUnwrap
          (SSPICipherSuite<1,1> *this,ReadOnlyBinary *param_1,ReadOnlyBinary *param_2,bool param_3,
          bool param_4)

{
  undefined7 in_register_00000089;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  void *local_30;
  long local_28;
  undefined8 local_20;
  int local_18;
  ReadOnlyBinary local_14;
  
  if (*(ulonglong *)param_2 < 0xffffffffffff0001) {
    local_48 = 0;
    local_40 = 0;
    (**(code **)(*(longlong *)this + 0x168))
              (this,&local_38,param_2,&local_48,CONCAT71(in_register_00000089,param_3),param_4);
    if (local_28 < 0) {
      Logging::Verify::StatusFailed("result",local_28);
      *(undefined8 *)(param_1 + 0x14) = 0;
      *(undefined8 *)(param_1 + 0x1c) = 0;
      *(undefined4 *)(param_1 + 0x24) = 0;
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(long *)(param_1 + 0x10) = local_28;
      if (local_30 != (void *)0x0) {
        operator_delete__(local_30);
      }
    }
    else {
      if (local_14 == (ReadOnlyBinary)0x0) {
        if (local_18 != 0) {
                    /* WARNING: Subroutine does not return */
          ConsistencyFail((ushort *)L"GSS-API cannot havea QOP when conf = false");
        }
        local_18 = -0x7fffffff;
      }
      *(undefined8 *)param_1 = local_38;
      *(void **)(param_1 + 8) = local_30;
      *(undefined8 *)(param_1 + 0x18) = local_20;
      *(long *)(param_1 + 0x10) = local_28;
      *(int *)(param_1 + 0x20) = local_18;
      param_1[0x24] = local_14;
    }
  }
  else {
    Logging::Verify::ConditionFailed("inputMessage.length <= MessageLimit");
    *(undefined8 *)(param_1 + 0x14) = 0;
    *(undefined8 *)(param_1 + 0x1c) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0xc0000095;
  }
  return param_1;
}



===== GSSVerifyMIC @ 180004c70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::VerifyMICResult,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::VerifyMICResult,12>(struct Kerb3961::VerifyMICResult const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::VerifyMICResult,12>(struct Kerb3961::VerifyMICResult & __ptr64)> __cdecl
   Kerb3961::SSPICipherSuite<1,1>::GSSVerifyMIC(struct Kerb3961::ReadOnlyBinary const &
   __ptr64,struct Kerb3961::ReadOnlyBinary const & __ptr64,struct Kerb3961::ReadOnlyBinary const &
   __ptr64,bool,bool) __ptr64 */

ReadOnlyBinary * __thiscall
Kerb3961::SSPICipherSuite<1,1>::GSSVerifyMIC
          (SSPICipherSuite<1,1> *this,ReadOnlyBinary *param_1,ReadOnlyBinary *param_2,
          ReadOnlyBinary *param_3,bool param_4,bool param_5)

{
  char *pcVar1;
  
  if (*(ulonglong *)param_2 < 0xffffffffffff0001) {
    if (*(ulonglong *)param_3 < 0xffffffffffff0001) {
      (**(code **)(*(longlong *)this + 0x150))(this);
      return param_1;
    }
    pcVar1 = "inputSignature.length <= MessageLimit";
  }
  else {
    pcVar1 = "inputMessage.length <= MessageLimit";
  }
  Logging::Verify::ConditionFailed(pcVar1);
  *(undefined8 *)param_1 = 0;
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0xc0000095;
  return param_1;
}



===== GSSWrap @ 180004cf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::SSPICipherSuite<1,1>::GSSWrap(struct Kerb3961::ReadOnlyBinary const & __ptr64,unsigned
   __int64,unsigned int,struct Kerb3961::ReadOnlyBinary const & __ptr64,bool,bool) __ptr64 */

ReadOnlyBinary * __thiscall
Kerb3961::SSPICipherSuite<1,1>::GSSWrap
          (SSPICipherSuite<1,1> *this,ReadOnlyBinary *param_1,__uint64 param_2,uint param_3,
          ReadOnlyBinary *param_4,bool param_5,bool param_6)

{
  undefined4 in_register_0000008c;
  undefined7 in_stack_00000031;
  undefined1 in_stack_00000040;
  undefined8 local_58;
  undefined8 local_50;
  ReadOnlyBinary local_48 [8];
  void *local_40;
  long local_38;
  ReadOnlyBinary local_30 [8];
  void *local_28;
  long local_20;
  
  if (*(ulonglong *)param_2 < 0xffffffffffff0001) {
    if ((int)param_4 == -0x7fffffff) {
      (**(code **)(*(longlong *)this + 0x160))
                (this,local_48,param_2,CONCAT44(in_register_0000008c,param_3),
                 CONCAT71(in_stack_00000031,param_5),param_6,in_stack_00000040);
      if (local_38 < 0) {
        Logging::Verify::StatusFailed("header",local_38);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(long *)(param_1 + 0x10) = local_38;
      }
      else {
        Concatenate(param_1,local_48);
      }
    }
    else {
      CopyBuffer(local_48);
      if (local_38 < 0) {
        Logging::Verify::ConditionFailed("inputCopy");
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(undefined4 *)(param_1 + 0x10) = 0xc0000017;
      }
      else {
        local_58 = 0;
        local_50 = 0;
        (**(code **)(*(longlong *)this + 0x158))
                  (this,local_30,local_48,&local_58,CONCAT44(in_register_0000008c,param_3),
                   (int)param_4,CONCAT71(in_stack_00000031,param_5),param_6,in_stack_00000040,0);
        if (local_20 < 0) {
          Logging::Verify::StatusFailed("header",local_20);
          *(undefined8 *)param_1 = 0;
          *(undefined8 *)(param_1 + 8) = 0;
          *(long *)(param_1 + 0x10) = local_20;
        }
        else {
          Concatenate(param_1,local_30);
        }
        if (local_28 != (void *)0x0) {
          operator_delete__(local_28);
        }
      }
    }
    if (local_40 != (void *)0x0) {
      operator_delete__(local_40);
    }
  }
  else {
    Logging::Verify::ConditionFailed("inputMessage.length <= MessageLimit");
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0xc0000095;
  }
  return param_1;
}



===== GetKeySeedLength @ 180004ec0 =====

/* protected: virtual unsigned __int64 __cdecl
   Kerb3961::SimplifiedCipherSuite::GetKeySeedLength(void) __ptr64 */

__uint64 __thiscall Kerb3961::SimplifiedCipherSuite::GetKeySeedLength(SimplifiedCipherSuite *this)

{
  return *(__uint64 *)(this + 0x20);
}



===== GetChecksumName @ 180004ed0 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::ReadOnlyStringResult,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::ReadOnlyStringResult,16>(struct Kerb3961::ReadOnlyStringResult const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::ReadOnlyStringResult,16>(struct Kerb3961::ReadOnlyStringResult & __ptr64)> const
   __cdecl Kerb3961::Aes3962::GetChecksumName(void) __ptr64 */

void __thiscall Kerb3961::Aes3962::GetChecksumName(Aes3962 *this)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 *in_RDX;
  
  uVar1 = *(undefined8 *)(this + 0x60);
  uVar2 = *(undefined8 *)(this + 0x58);
  *(undefined4 *)(in_RDX + 2) = 0;
  *in_RDX = uVar1;
  in_RDX[1] = uVar2;
  return;
}



===== GetChecksumPreferenceWeight @ 180004ef0 =====

/* private: virtual unsigned int __cdecl Kerb3961::Aes3962::GetChecksumPreferenceWeight(void)
   __ptr64 */

uint __thiscall Kerb3961::Aes3962::GetChecksumPreferenceWeight(Aes3962 *this)

{
  return *(uint *)(this + 0x44);
}



===== GetCipherAttributes @ 180004f00 =====

/* private: virtual enum Kerb3961::CipherAttributes __cdecl
   Kerb3961::Aes3962::GetCipherAttributes(void) __ptr64 */

CipherAttributes __thiscall Kerb3961::Aes3962::GetCipherAttributes(Aes3962 *this)

{
  return *(CipherAttributes *)(this + 0x70);
}



===== GetCipherBitmask @ 180004f10 =====

/* private: virtual unsigned int __cdecl Kerb3961::Aes3962::GetCipherBitmask(void) __ptr64 */

uint __thiscall Kerb3961::Aes3962::GetCipherBitmask(Aes3962 *this)

{
  byte bVar1;
  uint local_res8;
  
  bVar1 = 0x10;
  if (*(longlong *)(this + 0x40) == 0x10) {
    bVar1 = 8;
  }
  local_res8 = (uint)bVar1;
  return local_res8;
}



===== GetCipherName @ 180004f40 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::ReadOnlyStringResult,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::ReadOnlyStringResult,16>(struct Kerb3961::ReadOnlyStringResult const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::ReadOnlyStringResult,16>(struct Kerb3961::ReadOnlyStringResult & __ptr64)> const
   __cdecl Kerb3961::Aes3962::GetCipherName(void) __ptr64 */

void __thiscall Kerb3961::Aes3962::GetCipherName(Aes3962 *this)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 *in_RDX;
  
  uVar1 = *(undefined8 *)(this + 0x58);
  uVar2 = *(undefined8 *)(this + 0x50);
  *(undefined4 *)(in_RDX + 2) = 0;
  *in_RDX = uVar1;
  in_RDX[1] = uVar2;
  return;
}



===== GetCipherPreferenceWeight @ 180004f60 =====

/* private: virtual unsigned int __cdecl Kerb3961::Aes3962::GetCipherPreferenceWeight(void) __ptr64
    */

uint __thiscall Kerb3961::Aes3962::GetCipherPreferenceWeight(Aes3962 *this)

{
  return *(uint *)(this + 0x48);
}



===== GetCipherSessionKeyBitmask @ 180004f70 =====

/* private: virtual unsigned int __cdecl Kerb3961::Aes3962::GetCipherSessionKeyBitmask(void) __ptr64
    */

uint __thiscall Kerb3961::Aes3962::GetCipherSessionKeyBitmask(Aes3962 *this)

{
  return 0x20;
}



===== GetCiphertextLength @ 180004f90 =====

/* protected: virtual struct Kerb3961::ReturnType<struct Kerb3961::ResultAdapter<unsigned
   __int64>,&struct Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::ResultAdapter<unsigned __int64>,8>(struct Kerb3961::ResultAdapter<unsigned __int64>
   const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::ResultAdapter<unsigned __int64>,8>(struct Kerb3961::ResultAdapter<unsigned __int64> &
   __ptr64)> __cdecl Kerb3961::SimplifiedCipherSuite::GetCiphertextLength(unsigned __int64) __ptr64
    */

__uint64 __thiscall
Kerb3961::SimplifiedCipherSuite::GetCiphertextLength(SimplifiedCipherSuite *this,__uint64 param_1)

{
  ulonglong in_R8;
  ulonglong uVar1;
  
  uVar1 = *(longlong *)(this + 0x38) + -1 + in_R8;
  uVar1 = (*(longlong *)(this + 0x28) - uVar1 % *(ulonglong *)(this + 0x30)) + uVar1 +
          *(ulonglong *)(this + 0x30);
  if (in_R8 < uVar1) {
    *(undefined4 *)(param_1 + 8) = 0xc0000001;
    *(undefined4 *)(param_1 + 8) = 0;
    *(ulonglong *)param_1 = uVar1;
  }
  else {
    Logging::Verify::ConditionFailed("finalSize > plaintextLength");
    *(undefined8 *)param_1 = 0;
    *(undefined4 *)(param_1 + 8) = 0xc0000001;
    *(undefined4 *)(param_1 + 8) = 0xc0000095;
  }
  return param_1;
}



===== GetDefaultStringToKeyParams @ 180005000 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::ReadOnlyBinaryResult,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::ReadOnlyBinaryResult,16>(struct Kerb3961::ReadOnlyBinaryResult const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::ReadOnlyBinaryResult,16>(struct Kerb3961::ReadOnlyBinaryResult & __ptr64)> const
   __cdecl Kerb3961::Aes3962::GetDefaultStringToKeyParams(void) __ptr64 */

void __thiscall Kerb3961::Aes3962::GetDefaultStringToKeyParams(Aes3962 *this)

{
  undefined8 *in_RDX;
  
  *(undefined4 *)(in_RDX + 2) = 0;
  in_RDX[1] = &`private:_virtual_struct_Kerb3961::ReturnType<Kerb3961::ReadOnlyBinaryResult,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::ReadOnlyBinaryResult,16>(struct_Kerb3961::ReadOnlyBinaryResult_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::ReadOnlyBinaryResult,16>(struct_Kerb3961::ReadOnlyBinaryResult&___ptr64)>_const___cdecl_Kerb3961::Aes3962::GetDefaultStringToKeyParams(void)___ptr64'
               ::__l2::params;
  *in_RDX = 4;
  return;
}



===== GetInterfaceVersion @ 180005030 =====

/* private: virtual enum Kerb3961::EncryptionInterfaceVersion __cdecl
   Kerb3961::VersionedEncryptionAlgorithm<1>::GetInterfaceVersion(void) __ptr64 */

EncryptionInterfaceVersion __thiscall
Kerb3961::VersionedEncryptionAlgorithm<1>::GetInterfaceVersion
          (VersionedEncryptionAlgorithm<1> *this)

{
  return 1;
}



===== GetMic @ 180005040 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::SimplifiedCipherSuite::GetMic(struct Kerb3961::ReturnType<struct
   Kerb3961::SpecificKeyReturn,&struct Kerb3961::ResultBlock const & __ptr64 __cdecl
   Kerb3961::SingleGetter<struct Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn
   const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn & __ptr64)> & __ptr64,struct
   Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64 */

ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
* __thiscall
Kerb3961::SimplifiedCipherSuite::GetMic
          (SimplifiedCipherSuite *this,
          ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
          *param_1,ReadOnlyBinary *param_2)

{
  char *pcVar1;
  
  if (*(SimplifiedCipherSuite **)param_2 == this + -8) {
    if (**(longlong **)(param_2 + 8) != 0) {
      (**(code **)(*(longlong *)(this + -8) + 0x188))();
      return param_1;
    }
    pcVar1 = "key->Kc.length > 0";
  }
  else {
    pcVar1 = "specificKey.algorithm == this";
  }
  Logging::Verify::ConditionFailed(pcVar1);
  *(undefined8 *)param_1 = 0;
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0xc000000d;
  return param_1;
}



===== GetProtocolKeyLength @ 1800050b0 =====

/* private: virtual unsigned __int64 __cdecl Kerb3961::Aes3962::GetProtocolKeyLength(void) __ptr64
    */

__uint64 __thiscall Kerb3961::Aes3962::GetProtocolKeyLength(Aes3962 *this)

{
  return *(__uint64 *)(this + 0x40);
}



===== GetCipherPreferenceWeight @ 1800050c0 =====

/* private: virtual unsigned int __cdecl Kerb3961::RC4_4757::GetCipherPreferenceWeight(void) __ptr64
    */

uint __thiscall Kerb3961::RC4_4757::GetCipherPreferenceWeight(RC4_4757 *this)

{
  return *(uint *)(this + 0x1c);
}



===== GetSSPISizes @ 1800050d0 =====

/* private: virtual struct Kerb3961::SSPISizes const & __ptr64 __cdecl
   Kerb3961::RFC4121CipherSuite<1,1,0>::GetSSPISizes(void) __ptr64 */

SSPISizes * __thiscall
Kerb3961::RFC4121CipherSuite<1,1,0>::GetSSPISizes(RFC4121CipherSuite<1,1,0> *this)

{
  return &`private:_virtual_struct_Kerb3961::SSPISizes_const&___ptr64___cdecl_Kerb3961::RFC4121CipherSuite<1,1,0>::GetSSPISizes(void)___ptr64'
          ::__l2::sspiSizes;
}



===== HashData @ 1800050e0 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::Aes3962::HashData(struct Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64 */

ReadOnlyBinary * __thiscall Kerb3961::Aes3962::HashData(Aes3962 *this,ReadOnlyBinary *param_1)

{
  __uint64 in_R8;
  undefined8 local_18;
  undefined8 local_10;
  
  local_18 = 0;
  local_10 = 0;
  GetHashCommon(param_1,*(ReadOnlyBinary **)(this + 0x88),(ReadOnlyBinary *)&local_18,in_R8);
  return param_1;
}



===== HmacData @ 180005130 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::Aes3962::HmacData(struct Kerb3961::ReadOnlyBinary const & __ptr64,struct
   Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64 */

ReadOnlyBinary * __thiscall
Kerb3961::Aes3962::HmacData(Aes3962 *this,ReadOnlyBinary *param_1,ReadOnlyBinary *param_2)

{
  __uint64 in_R9;
  undefined1 local_28 [8];
  void *local_20;
  long local_18;
  
  GetHmac(local_28,*(ReadOnlyBinary **)(this + 0x90),param_2,in_R9);
  if (local_18 < 0) {
    Logging::Verify::StatusFailed("result",local_18);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(long *)(param_1 + 0x10) = local_18;
    if (local_20 != (void *)0x0) {
      operator_delete__(local_20);
    }
  }
  else {
    *(void **)(param_1 + 8) = local_20;
    *(long *)(param_1 + 0x10) = local_18;
    *(undefined8 *)param_1 = 0xc;
  }
  return param_1;
}



===== Initialize @ 1800051c0 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::StatusOnly,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly & __ptr64)> __cdecl
   Kerb3961::Aes3962::Initialize(void) __ptr64 */

void __thiscall Kerb3961::Aes3962::Initialize(Aes3962 *this)

{
  NTSTATUS NVar1;
  char *pcVar2;
  long *in_RDX;
  
  NVar1 = BCryptOpenAlgorithmProvider((BCRYPT_ALG_HANDLE *)(this + 0x80),L"AES",(LPCWSTR)0x0,0);
  if (NVar1 < 0) {
    pcVar2 = "BCryptOpenAlgorithmProvider(&m_cipherHandle, BCRYPT_AES_ALGORITHM, nullptr, 0)";
  }
  else {
    NVar1 = BCryptSetProperty(*(BCRYPT_HANDLE *)(this + 0x80),L"ChainingMode",
                              (PUCHAR)L"ChainingModeCBC",0x20,0);
    if (NVar1 < 0) {
      pcVar2 = 
      "BCryptSetProperty(m_cipherHandle, BCRYPT_CHAINING_MODE, (PUCHAR)BCRYPT_CHAIN_MODE_CBC, sizeof(BCRYPT_CHAIN_MODE_CBC), 0 )"
      ;
    }
    else {
      NVar1 = BCryptOpenAlgorithmProvider((BCRYPT_ALG_HANDLE *)(this + 0x88),L"SHA1",(LPCWSTR)0x0,0)
      ;
      if (NVar1 < 0) {
        pcVar2 = "BCryptOpenAlgorithmProvider(&m_hashHandle, BCRYPT_SHA1_ALGORITHM, nullptr, 0)";
      }
      else {
        NVar1 = BCryptOpenAlgorithmProvider
                          ((BCRYPT_ALG_HANDLE *)(this + 0x90),L"SHA1",(LPCWSTR)0x0,8);
        if (-1 < NVar1) {
          *in_RDX = 0;
          return;
        }
        pcVar2 = 
        "BCryptOpenAlgorithmProvider(&m_checksumHandle, BCRYPT_SHA1_ALGORITHM, nullptr, BCRYPT_ALG_HANDLE_HMAC_FLAG)"
        ;
      }
    }
  }
  Logging::Verify::StatusFailed(pcVar2,NVar1);
  *in_RDX = NVar1;
  return;
}



===== InitializeChecksum @ 1800052e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: virtual struct Kerb3961::ReturnType<struct Kerb3961::StatusOnly,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly & __ptr64)> __cdecl
   Kerb3961::CipherSuite<1,1>::InitializeChecksum(void) __ptr64 */

void __thiscall Kerb3961::CipherSuite<1,1>::InitializeChecksum(CipherSuite<1,1> *this)

{
  undefined4 *puVar1;
  undefined4 *in_RDX;
  undefined1 local_res8 [8];
  
  if (*(int *)(this + 8) == 0) {
    puVar1 = (undefined4 *)(**(code **)(*(longlong *)(this + -8) + 0x138))(this + -8,local_res8);
    *(undefined4 *)(this + 0xc) = *puVar1;
    *puVar1 = 0xc0000001;
  }
  *(int *)(this + 8) = *(int *)(this + 8) + 1;
  *in_RDX = *(undefined4 *)(this + 0xc);
  return;
}



===== InitializeCipher @ 180005340 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: virtual struct Kerb3961::ReturnType<struct Kerb3961::StatusOnly,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly & __ptr64)> __cdecl
   Kerb3961::CipherSuite<1,1>::InitializeCipher(void) __ptr64 */

void __thiscall Kerb3961::CipherSuite<1,1>::InitializeCipher(CipherSuite<1,1> *this)

{
  undefined4 *puVar1;
  undefined4 *in_RDX;
  undefined1 local_res8 [8];
  
  if (*(int *)(this + 0x10) == 0) {
    puVar1 = (undefined4 *)(**(code **)(*(longlong *)this + 0x138))(this,local_res8);
    *(undefined4 *)(this + 0x14) = *puVar1;
    *puVar1 = 0xc0000001;
  }
  *(int *)(this + 0x10) = *(int *)(this + 0x10) + 1;
  *in_RDX = *(undefined4 *)(this + 0x14);
  return;
}



===== InitializeCipherState @ 1800053a0 =====

/* WARNING: Removing unreachable block (ram,0x00018000540c) */
/* protected: virtual struct Kerb3961::ReturnType<struct Kerb3961::CipherStateReturn,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::CipherStateReturn,16>(struct Kerb3961::CipherStateReturn const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::CipherStateReturn,16>(struct Kerb3961::CipherStateReturn & __ptr64)> __cdecl
   Kerb3961::SimplifiedCipherSuite::InitializeCipherState(struct Kerb3961::ReturnType<struct
   Kerb3961::SpecificKeyReturn,&struct Kerb3961::ResultBlock const & __ptr64 __cdecl
   Kerb3961::SingleGetter<struct Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn
   const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn & __ptr64)> & __ptr64,bool)
   __ptr64 */

ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
* __thiscall
Kerb3961::SimplifiedCipherSuite::InitializeCipherState
          (SimplifiedCipherSuite *this,
          ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
          *param_1,bool param_2)

{
  longlong local_res8;
  
  utl::make_unique<unsigned_char_[0],0>((__uint64)&local_res8);
  if (local_res8 == 0) {
    Logging::Verify::ConditionFailed("cipherState");
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined8 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0xc0000001;
    *(undefined4 *)(param_1 + 0x10) = 0xc0000017;
  }
  else {
    *(undefined4 *)(param_1 + 0x10) = 0xc0000001;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(SimplifiedCipherSuite **)param_1 = this;
    *(longlong *)(param_1 + 8) = local_res8;
  }
  return param_1;
}



===== MakeBuffer @ 180005430 =====

/* WARNING: Removing unreachable block (ram,0x00018000547f) */
/* struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct Kerb3961::ResultBlock const &
   __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::OwnedBinary,16>(struct
   Kerb3961::OwnedBinary const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)>
   __cdecl Kerb3961::MakeBuffer(unsigned __int64) */

__uint64 __cdecl Kerb3961::MakeBuffer(__uint64 param_1)

{
  undefined8 in_RDX;
  longlong local_res18 [2];
  
  utl::make_unique<unsigned_char_[0],0>((__uint64)local_res18);
  if (local_res18[0] == 0) {
    Logging::Verify::ConditionFailed("buffer");
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0xc0000017;
  }
  else {
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined8 *)param_1 = in_RDX;
    *(longlong *)(param_1 + 8) = local_res18[0];
  }
  return param_1;
}



===== MarshalChecksumPolicy @ 1800054b0 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::Aes8009::MarshalChecksumPolicy(void) __ptr64 */

void __thiscall Kerb3961::Aes8009::MarshalChecksumPolicy(Aes8009 *this)

{
  undefined8 *in_RDX;
  
  *in_RDX = 0;
  in_RDX[1] = 0;
  *(undefined4 *)(in_RDX + 2) = 0;
  return;
}



===== PaddingForLength @ 1800054d0 =====

/* protected: virtual unsigned __int64 __cdecl
   Kerb3961::SimplifiedCipherSuite::PaddingForLength(unsigned __int64) __ptr64 */

__uint64 __thiscall
Kerb3961::SimplifiedCipherSuite::PaddingForLength(SimplifiedCipherSuite *this,__uint64 param_1)

{
  ulonglong uVar1;
  
  uVar1 = (param_1 - 1) + *(longlong *)(this + 0x38);
  return *(ulonglong *)(this + 0x30) +
         (((uVar1 - uVar1 % *(ulonglong *)(this + 0x30)) - *(longlong *)(this + 0x38)) - param_1);
}



===== PreferredCipher @ 180005500 =====

/* protected: virtual unsigned int __cdecl Kerb3961::SimplifiedCipherSuite::PreferredCipher(void)
   __ptr64 */

uint __thiscall Kerb3961::SimplifiedCipherSuite::PreferredCipher(SimplifiedCipherSuite *this)

{
  return *(uint *)(this + 0x10);
}



===== PseudoRandom @ 180005510 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::SimplifiedCipherSuite::PseudoRandom(struct Kerb3961::ReadOnlyBinary const &
   __ptr64,struct Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64 */

ReadOnlyBinary * __thiscall
Kerb3961::SimplifiedCipherSuite::PseudoRandom
          (SimplifiedCipherSuite *this,ReadOnlyBinary *param_1,ReadOnlyBinary *param_2)

{
  long lVar1;
  ulonglong uVar2;
  long *plVar3;
  undefined1 local_res8 [8];
  ulonglong local_68;
  void *local_60;
  long local_58;
  undefined1 local_50 [8];
  void *local_48;
  long local_40;
  ReadOnlyBinary local_38 [8];
  void *local_30;
  long local_28;
  
  (**(code **)(*(longlong *)this + 0x180))();
  lVar1 = local_58;
  if (local_58 < 0) {
    Logging::Verify::StatusFailed("tmp",local_58);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(long *)(param_1 + 0x10) = lVar1;
    goto LAB_1800056be;
  }
  uVar2 = *(ulonglong *)(this + 0x30);
  if (local_68 <= uVar2) {
                    /* WARNING: Subroutine does not return */
    ConsistencyFail((ushort *)L"The hash must be at least the message block size");
  }
  local_68 = (local_68 / uVar2) * uVar2;
  MakeBuffer((__uint64)local_50);
  if (local_40 < 0) {
    Logging::Verify::StatusFailed("IV",local_40);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(long *)(param_1 + 0x10) = local_40;
LAB_1800055bb:
    if (local_48 == (void *)0x0) goto LAB_1800056be;
  }
  else {
    DeriveKey(this,local_38,param_2);
    if (local_28 < 0) {
      Logging::Verify::StatusFailed("derivedKey",local_28);
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(long *)(param_1 + 0x10) = local_28;
LAB_180005614:
      if (local_30 != (void *)0x0) {
        operator_delete__(local_30);
      }
      goto LAB_1800055bb;
    }
    plVar3 = (long *)(**(code **)(*(longlong *)this + 400))
                               (this,local_res8,local_38,local_50,&local_68);
    uVar2 = local_68;
    lVar1 = *plVar3;
    if (lVar1 < 0) {
      Logging::Verify::StatusFailed("BlockEncrypt(derivedKey, IV, tmp)",lVar1);
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(long *)(param_1 + 0x10) = lVar1;
      goto LAB_180005614;
    }
    *(long *)(param_1 + 0x10) = local_58;
    local_68 = 0;
    *(ulonglong *)param_1 = uVar2;
    *(void **)(param_1 + 8) = local_60;
    local_58 = -0x3fffffff;
    local_60 = (void *)0x0;
    if (local_30 != (void *)0x0) {
      operator_delete__(local_30);
    }
    if (local_48 == (void *)0x0) goto LAB_1800056be;
  }
  operator_delete__(local_48);
LAB_1800056be:
  if (local_60 != (void *)0x0) {
    operator_delete__(local_60);
  }
  return param_1;
}



===== RandomBuffer @ 1800056f8 =====

/* struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct Kerb3961::ResultBlock const &
   __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::OwnedBinary,16>(struct
   Kerb3961::OwnedBinary const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)>
   __cdecl Kerb3961::RandomBuffer(unsigned __int64) */

__uint64 __cdecl Kerb3961::RandomBuffer(__uint64 param_1)

{
  NTSTATUS NVar1;
  longlong in_RDX;
  PUCHAR local_res10;
  
  if (in_RDX == 0) {
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  else {
    utl::make_unique<unsigned_char_[0],0>((__uint64)&local_res10);
    if (local_res10 == (PUCHAR)0x0) {
      Logging::Verify::ConditionFailed("result");
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(undefined4 *)(param_1 + 0x10) = 0xc0000017;
    }
    else {
      NVar1 = BCryptGenRandom((BCRYPT_ALG_HANDLE)0x0,local_res10,(ULONG)in_RDX,2);
      if (-1 < NVar1) {
        *(undefined4 *)(param_1 + 0x10) = 0;
        *(longlong *)param_1 = in_RDX;
        *(PUCHAR *)(param_1 + 8) = local_res10;
        return param_1;
      }
      Logging::Verify::StatusFailed("RandomFill({bytes, &result[0]})",NVar1);
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(NTSTATUS *)(param_1 + 0x10) = NVar1;
    }
    if (local_res10 != (PUCHAR)0x0) {
      operator_delete__(local_res10);
    }
  }
  return param_1;
}



===== RandomKey @ 1800057d0 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::Aes3962::RandomKey(void) __ptr64 */

void __thiscall Kerb3961::Aes3962::RandomKey(Aes3962 *this)

{
  __uint64 in_RDX;
  
  RandomBuffer(in_RDX);
  return;
}



===== RandomToKey @ 180005800 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::Aes3962::RandomToKey(struct Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64 */

ReadOnlyBinary * __thiscall Kerb3961::Aes3962::RandomToKey(Aes3962 *this,ReadOnlyBinary *param_1)

{
  ulonglong *in_R8;
  
  if (*in_R8 < *(ulonglong *)(this + 0x40)) {
    Logging::Verify::ConditionFailed("randomSeed.length >= m_keySize");
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0xc0000023;
  }
  else {
    CopyBuffer(param_1);
  }
  return param_1;
}



===== SSPIGetMIC @ 180005860 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::SSPICipherSuite<1,1>::SSPIGetMIC(struct Kerb3961::MicBuffers const & __ptr64,unsigned
   __int64,unsigned int,struct Kerb3961::ReadOnlyBinary const & __ptr64,bool,bool) __ptr64 */

MicBuffers * __thiscall
Kerb3961::SSPICipherSuite<1,1>::SSPIGetMIC
          (SSPICipherSuite<1,1> *this,MicBuffers *param_1,__uint64 param_2,uint param_3,
          ReadOnlyBinary *param_4,bool param_5,bool param_6)

{
  MicBuffers *pMVar1;
  undefined4 in_register_0000008c;
  undefined7 in_stack_00000031;
  undefined1 in_stack_00000040;
  MicBuffers local_38 [8];
  void *local_30;
  long local_28;
  
  if ((int)param_4 == -0x7fffffff) {
    Logging::Verify::ConditionFailed("QOP != KERB_WRAP_NO_ENCRYPT");
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0x8009030a;
  }
  else {
    CoalesceMICBuffers(this,local_38);
    if (local_28 < 0) {
      Logging::Verify::StatusFailed("combinedBuffer",local_28);
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(long *)(param_1 + 0x10) = local_28;
    }
    else {
      if (local_28 == 0xff) {
        pMVar1 = *(MicBuffers **)(param_2 + 8);
      }
      else {
        pMVar1 = local_38;
      }
      if (*(ulonglong *)pMVar1 < 0xffffffffffff0001) {
        (**(code **)(*(longlong *)this + 0x148))
                  (this,param_1,pMVar1,CONCAT44(in_register_0000008c,param_3),(int)param_4,
                   CONCAT71(in_stack_00000031,param_5),param_6,in_stack_00000040);
      }
      else {
        Logging::Verify::ConditionFailed("effectiveInput.length <= MessageLimit");
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(undefined4 *)(param_1 + 0x10) = 0xc0000095;
      }
    }
    if (local_30 != (void *)0x0) {
      operator_delete__(local_30);
    }
  }
  return param_1;
}



===== SSPIUnwrap @ 1800059a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::VerifyMICResult,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::VerifyMICResult,12>(struct Kerb3961::VerifyMICResult const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::VerifyMICResult,12>(struct Kerb3961::VerifyMICResult & __ptr64)> __cdecl
   Kerb3961::SSPICipherSuite<1,1>::SSPIUnwrap(struct Kerb3961::WrapBuffers const & __ptr64,struct
   Kerb3961::ReadOnlyBinary const & __ptr64,struct Kerb3961::ReadOnlyBinary const & __ptr64,struct
   Kerb3961::ReadOnlyBinary const & __ptr64,bool,bool) __ptr64 */

WrapBuffers * __thiscall
Kerb3961::SSPICipherSuite<1,1>::SSPIUnwrap
          (SSPICipherSuite<1,1> *this,WrapBuffers *param_1,ReadOnlyBinary *param_2,
          ReadOnlyBinary *param_3,ReadOnlyBinary *param_4,bool param_5,bool param_6)

{
  size_t *psVar1;
  SSPICipherSuite<1,1> *this_00;
  WrapBuffers *pWVar2;
  void *_Src;
  size_t *psVar3;
  undefined7 in_stack_00000031;
  undefined1 in_stack_00000040;
  WrapBuffers local_98 [8];
  void *local_90;
  long local_88;
  WrapBuffers local_80 [8];
  void *local_78;
  long local_70;
  ReadOnlyBinary local_68 [8];
  void *local_60;
  long local_58;
  undefined1 local_50 [8];
  void *local_48;
  long local_40;
  undefined8 local_38;
  int local_30;
  char local_2c;
  
  this_00 = this;
  CoalesceEncryptedWrapBuffers(this,local_98);
  if (local_88 < 0) {
    Logging::Verify::StatusFailed("combinedBuffer",local_88);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(long *)(param_1 + 0xc) = local_88;
    goto LAB_180005b62;
  }
  if (local_88 == 0xff) {
    pWVar2 = *(WrapBuffers **)(param_2 + 8);
  }
  else {
    pWVar2 = local_98;
  }
  CoalesceAuthWrapBuffers(this_00,local_80);
  if (local_70 < 0) {
    Logging::Verify::StatusFailed("authBuffer",local_70);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(long *)(param_1 + 0xc) = local_70;
  }
  else {
    Concatenate(local_68,param_3,(ReadOnlyBinary *)pWVar2);
    if (local_58 < 0) {
      Logging::Verify::StatusFailed("completeWrapToken",local_58);
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(long *)(param_1 + 0xc) = local_58;
    }
    else {
      (**(code **)(*(longlong *)this + 0x168))
                (this,local_50,local_68,local_80,CONCAT71(in_stack_00000031,param_5),param_6,
                 in_stack_00000040);
      if (local_40 < 0) {
        Logging::Verify::StatusFailed("result",local_40);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(long *)(param_1 + 0xc) = local_40;
        if (local_48 != (void *)0x0) goto LAB_180005b41;
      }
      else {
        if (local_2c == '\0') {
          if (local_30 != 0) {
                    /* WARNING: Subroutine does not return */
            ConsistencyFail((ushort *)L"GSS-API cannot have a QOP when conf = false");
          }
          local_30 = -0x7fffffff;
        }
        psVar3 = *(size_t **)(param_2 + 8);
        psVar1 = psVar3 + *(longlong *)param_2 * 3;
        _Src = local_48;
        if (psVar3 != psVar1) {
          do {
            if ((char)psVar3[2] != '\0') {
              memmove((void *)psVar3[1],_Src,*psVar3);
              _Src = (void *)((longlong)_Src + *psVar3);
            }
            psVar3 = psVar3 + 3;
          } while (psVar3 != psVar1);
        }
        *(undefined8 *)param_1 = local_38;
        *(int *)(param_1 + 8) = local_30;
        *(undefined4 *)(param_1 + 0xc) = 0;
        if (local_48 != (void *)0x0) {
LAB_180005b41:
          operator_delete__(local_48);
        }
      }
    }
    if (local_60 != (void *)0x0) {
      operator_delete__(local_60);
    }
  }
  if (local_78 != (void *)0x0) {
    operator_delete__(local_78);
  }
LAB_180005b62:
  if (local_90 != (void *)0x0) {
    operator_delete__(local_90);
  }
  return param_1;
}



===== SSPIVerifyMIC @ 180005bb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::VerifyMICResult,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::VerifyMICResult,12>(struct Kerb3961::VerifyMICResult const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::VerifyMICResult,12>(struct Kerb3961::VerifyMICResult & __ptr64)> __cdecl
   Kerb3961::SSPICipherSuite<1,1>::SSPIVerifyMIC(struct Kerb3961::MicBuffers const & __ptr64,struct
   Kerb3961::ReadOnlyBinary const & __ptr64,struct Kerb3961::ReadOnlyBinary const &
   __ptr64,bool,bool) __ptr64 */

MicBuffers * __thiscall
Kerb3961::SSPICipherSuite<1,1>::SSPIVerifyMIC
          (SSPICipherSuite<1,1> *this,MicBuffers *param_1,ReadOnlyBinary *param_2,
          ReadOnlyBinary *param_3,bool param_4,bool param_5)

{
  char *pcVar1;
  MicBuffers *pMVar2;
  undefined7 in_stack_00000029;
  undefined1 in_stack_00000038;
  MicBuffers local_28 [8];
  void *local_20;
  long local_18;
  
  CoalesceMICBuffers(this,local_28);
  if (local_18 < 0) {
    Logging::Verify::StatusFailed("combinedBuffer",local_18);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(long *)(param_1 + 0xc) = local_18;
  }
  else {
    if (local_18 == 0xff) {
      pMVar2 = *(MicBuffers **)(param_2 + 8);
    }
    else {
      pMVar2 = local_28;
    }
    if (*(ulonglong *)pMVar2 < 0xffffffffffff0001) {
      if (*(ulonglong *)param_3 < 0xffffffffffff0001) {
        (**(code **)(*(longlong *)this + 0x150))
                  (this,param_1,pMVar2,param_3,CONCAT71(in_stack_00000029,param_4),param_5,
                   in_stack_00000038);
        goto LAB_180005c86;
      }
      pcVar1 = "inputSignature.length <= MessageLimit";
    }
    else {
      pcVar1 = "effectiveInput.length <= MessageLimit";
    }
    Logging::Verify::ConditionFailed(pcVar1);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0xc0000095;
  }
LAB_180005c86:
  if (local_20 != (void *)0x0) {
    operator_delete__(local_20);
  }
  return param_1;
}



===== SSPIWrap @ 180005cc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::SSPICipherSuite<1,1>::SSPIWrap(struct Kerb3961::WrapBuffers const & __ptr64,unsigned
   __int64,unsigned int,struct Kerb3961::ReadOnlyBinary const & __ptr64,bool,bool,unsigned __int64 *
   __ptr64) __ptr64 */

WrapBuffers * __thiscall
Kerb3961::SSPICipherSuite<1,1>::SSPIWrap
          (SSPICipherSuite<1,1> *this,WrapBuffers *param_1,__uint64 param_2,uint param_3,
          ReadOnlyBinary *param_4,bool param_5,bool param_6,__uint64 *param_7)

{
  size_t *psVar1;
  long lVar2;
  SSPICipherSuite<1,1> *this_00;
  size_t *psVar3;
  WrapBuffers *pWVar4;
  undefined4 in_register_0000008c;
  void *_Src;
  undefined7 in_stack_00000031;
  undefined8 *in_stack_00000048;
  undefined8 local_88;
  void *local_80;
  long local_78;
  WrapBuffers local_70 [8];
  void *local_68;
  long local_60;
  WrapBuffers local_58 [8];
  void *local_50;
  long local_48;
  
  if (in_stack_00000048 != (undefined8 *)0x0) {
    *in_stack_00000048 = 0;
  }
  if ((int)param_4 == -0x7fffffff) {
    CoalescePlainWrapBuffers(this,local_58);
    if (local_48 < 0) {
      Logging::Verify::StatusFailed("combinedBuffer",local_48);
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(long *)(param_1 + 0x10) = local_48;
    }
    else {
      if (local_48 == 0xff) {
        pWVar4 = *(WrapBuffers **)(param_2 + 8);
      }
      else {
        pWVar4 = local_58;
      }
      (**(code **)(*(longlong *)this + 0x160))
                (this,param_1,pWVar4,CONCAT44(in_register_0000008c,param_3),
                 CONCAT71(in_stack_00000031,param_5),param_6,(ulonglong)param_7 & 0xff);
    }
  }
  else {
    this_00 = this;
    CoalesceEncryptedWrapBuffers(this,local_70);
    if (local_60 < 0) {
      Logging::Verify::StatusFailed("combinedBuffer",local_60);
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(long *)(param_1 + 0x10) = local_60;
    }
    else {
      if (local_60 == 0xff) {
        pWVar4 = *(WrapBuffers **)(param_2 + 8);
      }
      else {
        pWVar4 = local_70;
      }
      CoalesceAuthWrapBuffers(this_00,local_58);
      if (local_48 < 0) {
        Logging::Verify::StatusFailed("authBuffer",local_48);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(long *)(param_1 + 0x10) = local_48;
      }
      else {
        (**(code **)(*(longlong *)this + 0x158))
                  (this,&local_88,pWVar4,local_58,CONCAT44(in_register_0000008c,param_3),
                   (int)param_4,CONCAT71(in_stack_00000031,param_5),param_6,param_7._0_1_);
        lVar2 = local_78;
        if (local_78 < 0) {
          Logging::Verify::StatusFailed("result",local_78);
          *(undefined8 *)param_1 = 0;
          *(undefined8 *)(param_1 + 8) = 0;
          *(long *)(param_1 + 0x10) = lVar2;
          if (local_80 != (void *)0x0) {
            operator_delete__(local_80);
          }
        }
        else {
          if (local_60 != 0xff) {
            psVar3 = *(size_t **)(param_2 + 8);
            _Src = *(void **)(pWVar4 + 8);
            psVar1 = psVar3 + *(longlong *)param_2 * 3;
            if (psVar3 != psVar1) {
              do {
                if ((char)psVar3[2] != '\0') {
                  memmove((void *)psVar3[1],_Src,*psVar3);
                  _Src = (void *)((longlong)_Src + *psVar3);
                }
                psVar3 = psVar3 + 3;
              } while (psVar3 != psVar1);
            }
          }
          *(undefined8 *)param_1 = local_88;
          *(void **)(param_1 + 8) = local_80;
          *(long *)(param_1 + 0x10) = local_78;
          local_78 = -0x3fffffff;
          local_88 = 0;
          local_80 = (void *)0x0;
        }
      }
      if (local_50 != (void *)0x0) {
        operator_delete__(local_50);
      }
    }
    local_50 = local_68;
  }
  if (local_50 != (void *)0x0) {
    operator_delete__(local_50);
  }
  return param_1;
}



===== StringToKey @ 180005f30 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::Aes3962::StringToKey(struct Kerb3961::ReadOnlyString const & __ptr64,struct
   Kerb3961::ReadOnlyString const & __ptr64,struct Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64
    */

ReadOnlyString * __thiscall
Kerb3961::Aes3962::StringToKey
          (Aes3962 *this,ReadOnlyString *param_1,ReadOnlyString *param_2,ReadOnlyBinary *param_3)

{
  uint uVar1;
  char *pcVar2;
  longlong *in_stack_00000028;
  
  if (*in_stack_00000028 == 4) {
    uVar1 = *(uint *)in_stack_00000028[1];
    uVar1 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    if (*(uint *)(this + 0x74) < uVar1) {
      pcVar2 = "iterations <= m_maxIterationCount";
    }
    else {
      if (*(uint *)(this + 0x78) <= uVar1) {
        Logging::Verify::StatusFailed("passwordUTF8",-0x3fffffff);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(undefined4 *)(param_1 + 0x10) = 0xc0000001;
        return param_1;
      }
      pcVar2 = "iterations >= m_minIterationCount";
    }
  }
  else {
    pcVar2 = "stringToKeyParameters.length == sizeof(uint32_t)";
  }
  Logging::Verify::ConditionFailed(pcVar2);
  *(undefined8 *)param_1 = 0;
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0xc000000d;
  return param_1;
}



===== Uninitialize @ 180005fc0 =====

/* private: virtual void __cdecl Kerb3961::Aes3962::Uninitialize(void) __ptr64 */

void __thiscall Kerb3961::Aes3962::Uninitialize(Aes3962 *this)

{
  if (*(BCRYPT_ALG_HANDLE *)(this + 0x80) != (BCRYPT_ALG_HANDLE)0x0) {
    BCryptCloseAlgorithmProvider(*(BCRYPT_ALG_HANDLE *)(this + 0x80),0);
    *(undefined8 *)(this + 0x80) = 0;
  }
  if (*(BCRYPT_ALG_HANDLE *)(this + 0x88) != (BCRYPT_ALG_HANDLE)0x0) {
    BCryptCloseAlgorithmProvider(*(BCRYPT_ALG_HANDLE *)(this + 0x88),0);
    *(undefined8 *)(this + 0x90) = 0;
  }
  if (*(BCRYPT_ALG_HANDLE *)(this + 0x90) != (BCRYPT_ALG_HANDLE)0x0) {
    BCryptCloseAlgorithmProvider(*(BCRYPT_ALG_HANDLE *)(this + 0x90),0);
    *(undefined8 *)(this + 0x90) = 0;
  }
  return;
}



===== UninitializeChecksum @ 180006040 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: virtual void __cdecl Kerb3961::CipherSuite<1,1>::UninitializeChecksum(void) __ptr64 */

void __thiscall Kerb3961::CipherSuite<1,1>::UninitializeChecksum(CipherSuite<1,1> *this)

{
  CipherSuite<1,1> *pCVar1;
  
  pCVar1 = this + 8;
  *(int *)pCVar1 = *(int *)pCVar1 + -1;
  if (*(int *)pCVar1 == 0) {
    (**(code **)(*(longlong *)(this + -8) + 0x140))();
  }
  return;
}



===== UninitializeCipher @ 180006070 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: virtual void __cdecl Kerb3961::CipherSuite<1,1>::UninitializeCipher(void) __ptr64 */

void __thiscall Kerb3961::CipherSuite<1,1>::UninitializeCipher(CipherSuite<1,1> *this)

{
  CipherSuite<1,1> *pCVar1;
  
  pCVar1 = this + 0x10;
  *(int *)pCVar1 = *(int *)pCVar1 + -1;
  if (*(int *)pCVar1 == 0) {
    (**(code **)(*(longlong *)this + 0x140))();
  }
  return;
}



===== Unrotate @ 180006098 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct Kerb3961::ResultBlock
   const & __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::OwnedBinary,16>(struct
   Kerb3961::OwnedBinary const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)>
   __cdecl Kerb3961::RFC4121CipherSuite<1,1,0>::Unrotate(struct Kerb3961::ReadOnlyBinary const &
   __ptr64,unsigned short) __ptr64 */

ReadOnlyBinary * __thiscall
Kerb3961::RFC4121CipherSuite<1,1,0>::Unrotate
          (RFC4121CipherSuite<1,1,0> *this,ReadOnlyBinary *param_1,ushort param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  ReadOnlyBinary *pRVar6;
  undefined6 in_register_00000082;
  ulonglong *puVar7;
  ushort in_R9W;
  undefined1 auStack_98 [32];
  longlong local_78 [4];
  ReadOnlyBinary local_58 [8];
  undefined8 local_50 [3];
  ReadOnlyBinary local_38 [16];
  ulonglong local_28;
  
  puVar7 = (ulonglong *)CONCAT62(in_register_00000082,param_2);
  local_28 = __security_cookie ^ (ulonglong)auStack_98;
  pRVar6 = local_58;
  local_78[0] = 0x10;
  local_78[1] = (ulonglong)in_R9W % (*puVar7 - 0x10);
  lVar5 = 3;
  local_78[2] = (*puVar7 - 0x10) - local_78[1];
  uVar4 = 0;
  do {
    ReadOnlyBinary::ReadOnlyBinary(pRVar6);
    pRVar6 = pRVar6 + 0x10;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  uVar1 = puVar7[1];
  pRVar6 = local_58;
  uVar3 = 0;
  do {
    lVar2 = local_78[uVar3];
    lVar5 = uVar1 + uVar4;
    *(longlong *)pRVar6 = lVar2;
    uVar4 = uVar4 + lVar2;
    uVar3 = uVar3 + 1;
    *(longlong *)(pRVar6 + 8) = lVar5;
    pRVar6 = pRVar6 + 0x10;
  } while (uVar3 < 3);
  if (*puVar7 < uVar4) {
                    /* WARNING: Subroutine does not return */
    ConsistencyFail((ushort *)L"Splitting buffer into parts that exceed the whole");
  }
  Concatenate(param_1,local_58,local_38);
  return param_1;
}



===== UpgradeInterfaceVersion @ 180006190 =====

/* private: virtual union Kerb3961::ChecksumInterface __cdecl
   Kerb3961::VersionedChecksumAlgorithmBase<struct
   Kerb3961::ChecksumAlgorithm>::UpgradeInterfaceVersion(enum Kerb3961::ChecksumInterfaceVersion)
   __ptr64 */

undefined8 __thiscall
Kerb3961::VersionedChecksumAlgorithmBase<Kerb3961::ChecksumAlgorithm>::UpgradeInterfaceVersion
          (VersionedChecksumAlgorithmBase<Kerb3961::ChecksumAlgorithm> *this,
          ChecksumInterfaceVersion param_1)

{
  undefined4 in_register_00000014;
  int in_R8D;
  
  *(undefined8 *)CONCAT44(in_register_00000014,param_1) = 0;
  if (in_R8D == 1) {
    *(VersionedChecksumAlgorithmBase<Kerb3961::ChecksumAlgorithm> **)
     CONCAT44(in_register_00000014,param_1) = this;
  }
  return CONCAT44(in_register_00000014,param_1);
}



===== VerifyMic @ 1800061b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: virtual struct Kerb3961::ReturnType<struct Kerb3961::StatusOnly,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly & __ptr64)> __cdecl
   Kerb3961::SimplifiedCipherSuite::VerifyMic(struct Kerb3961::ReturnType<struct
   Kerb3961::SpecificKeyReturn,&struct Kerb3961::ResultBlock const & __ptr64 __cdecl
   Kerb3961::SingleGetter<struct Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn
   const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn & __ptr64)> & __ptr64,struct
   Kerb3961::ReadOnlyBinary const & __ptr64,struct Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64
    */

ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
* __thiscall
Kerb3961::SimplifiedCipherSuite::VerifyMic
          (SimplifiedCipherSuite *this,
          ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
          *param_1,ReadOnlyBinary *param_2,ReadOnlyBinary *param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  long lVar3;
  SimplifiedCipherSuite *pSVar4;
  char *pcVar5;
  uint uVar6;
  ulonglong uVar7;
  byte bVar8;
  ulonglong *in_stack_00000028;
  ulonglong local_28;
  void *local_20;
  long local_18;
  
  pSVar4 = this + -8;
  if (*(SimplifiedCipherSuite **)param_2 == pSVar4) {
    if (**(longlong **)(param_2 + 8) == 0) {
      pcVar5 = "key->Kc.length > 0";
      goto LAB_1800061d5;
    }
    (**(code **)(*(longlong *)pSVar4 + 0x188))(pSVar4,&local_28);
  }
  else {
    pcVar5 = "specificKey.algorithm == this";
LAB_1800061d5:
    Logging::Verify::ConditionFailed(pcVar5);
    local_28 = 0;
    local_20 = (void *)0x0;
    local_18 = -0x3ffffff3;
  }
  lVar3 = local_18;
  if (local_18 < 0) {
    Logging::Verify::StatusFailed("compare",local_18);
    *(long *)param_1 = lVar3;
    goto LAB_1800062a0;
  }
  uVar7 = *in_stack_00000028;
  if (uVar7 == local_28) {
    if (uVar7 != 0) {
      if (0xffffffff < uVar7) goto LAB_18000628a;
      bVar8 = 0;
      uVar7 = 0;
      if ((uint)*in_stack_00000028 != 0) {
        do {
          pbVar1 = (byte *)(uVar7 + (longlong)local_20);
          pbVar2 = (byte *)(uVar7 + in_stack_00000028[1]);
          uVar6 = (int)uVar7 + 1;
          uVar7 = (ulonglong)uVar6;
          bVar8 = bVar8 | *pbVar1 ^ *pbVar2;
        } while (uVar6 < (uint)*in_stack_00000028);
        if (bVar8 != 0) goto LAB_18000628a;
      }
    }
    *(undefined4 *)param_1 = 0;
  }
  else {
LAB_18000628a:
    Logging::Verify::ConditionFailed("SecureEqualBuffer(mic, compare)");
    *(undefined4 *)param_1 = 0x8009030f;
  }
LAB_1800062a0:
  if (local_20 != (void *)0x0) {
    operator_delete__(local_20);
  }
  return param_1;
}



===== acquire_exclusive @ 1800062c4 =====

/* public: class wil::unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<unsigned __int64 * __ptr64,void (__cdecl*)(unsigned __int64 *
   __ptr64) noexcept,&void __cdecl wil::details::release_push_lock_exclusive(unsigned __int64 *
   __ptr64),struct wistd::integral_constant<unsigned __int64,1>,unsigned __int64 * __ptr64,unsigned
   __int64 * __ptr64,0,std::nullptr_t> > > __cdecl wil::push_lock::acquire_exclusive(void) __ptr64
    */

void __thiscall wil::push_lock::acquire_exclusive(push_lock *this)

{
  undefined8 *in_RDX;
  
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(this,0);
  *in_RDX = this;
  return;
}



===== acquire_shared @ 18000630c =====

/* public: class wil::unique_any_t<class wil::details::unique_storage<struct
   wil::details::resource_policy<unsigned __int64 * __ptr64,void (__cdecl*)(unsigned __int64 *
   __ptr64) noexcept,&void __cdecl wil::details::release_push_lock_shared(unsigned __int64 *
   __ptr64),struct wistd::integral_constant<unsigned __int64,1>,unsigned __int64 * __ptr64,unsigned
   __int64 * __ptr64,0,std::nullptr_t> > > __cdecl wil::push_lock::acquire_shared(void) __ptr64 */

void __thiscall wil::push_lock::acquire_shared(push_lock *this)

{
  undefined8 *in_RDX;
  
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(this,0);
  *in_RDX = this;
  return;
}



===== Feature_184236346__private_IsEnabledDeviceUsageNoInline @ 180006354 =====

ulonglong Feature_184236346__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)(uint)Feature_184236346__private_featureState;
  if (((uint)Feature_184236346__private_featureState & 0x10) == 0) {
    uVar1 = Feature_184236346__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)((uint)Feature_184236346__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_184236346__private_IsEnabledFallback @ 18000638c =====

void Feature_184236346__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_184236346__private_descriptor);
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 1800063a8 =====

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
LAB_1800065ab:
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
LAB_180006483:
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
      if (param_3 == 4) goto LAB_1800065ab;
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
        goto LAB_180006483;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 180006694 =====

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
      goto LAB_180006765;
    }
    if (param_3 == 2) {
      uVar3 = (uVar2 ^ 1) * 4 + 1;
      goto LAB_180006765;
    }
    if (param_3 == 3) {
      uVar3 = (uVar2 ^ 1) * 4 + 2;
      goto LAB_180006765;
    }
    if (param_3 == 4) {
      uVar3 = (uVar2 ^ 1) * 4 + 3;
      goto LAB_180006765;
    }
    if (param_3 == 5) {
      uVar3 = (uVar2 ^ 1) * 2 + 8;
      goto LAB_180006765;
    }
    if (param_3 == 6) {
      uVar3 = (uVar2 ^ 1) * 2 + 9;
      goto LAB_180006765;
    }
    bVar4 = (char)param_3 + 0x9c;
    if (bVar4 < 0x32) {
      uVar3 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar4;
      goto LAB_180006765;
    }
  }
  uVar3 = 0xff;
LAB_180006765:
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



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 1800067bc =====

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



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 1800068ac =====

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
LAB_18000695f:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_18000698d;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_18000695f;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_18000698d:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 180006b18 =====

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



===== wil_details_IsEnabledFallback @ 180006b7c =====

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



===== Concatenate<5> @ 180006c10 =====

/* WARNING: Removing unreachable block (ram,0x000180006ce0) */
/* struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct Kerb3961::ResultBlock const &
   __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::OwnedBinary,16>(struct
   Kerb3961::OwnedBinary const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)>
   __cdecl Kerb3961::Concatenate<5>(struct utl::array<struct Kerb3961::ReadOnlyBinary const ,5>) */

ulonglong * __cdecl Kerb3961::Concatenate<5>(ulonglong *param_1,ulonglong *param_2)

{
  ulonglong *puVar1;
  size_t _Size;
  ulonglong *puVar2;
  char *pcVar3;
  ulonglong uVar4;
  void *_Dst;
  void *local_38 [2];
  
  puVar1 = param_2 + 10;
  uVar4 = 0;
  puVar2 = param_2;
  do {
    if (puVar2 == puVar1) {
      if (uVar4 < 0x100000000) {
        if (uVar4 == 0) {
          *param_1 = 0;
          param_1[1] = 0;
        }
        else {
          utl::make_unique<unsigned_char_[0],0>((__uint64)local_38);
          if (local_38[0] == (void *)0x0) {
            Logging::Verify::ConditionFailed("result");
            *param_1 = 0;
            param_1[1] = 0;
            *(undefined4 *)(param_1 + 2) = 0xc0000017;
            return param_1;
          }
          _Dst = local_38[0];
          for (; param_2 != puVar1; param_2 = param_2 + 2) {
            _Size = *param_2;
            memmove(_Dst,(void *)param_2[1],_Size);
            _Dst = (void *)((longlong)_Dst + _Size);
          }
          *param_1 = uVar4;
          param_1[1] = (ulonglong)local_38[0];
        }
        *(undefined4 *)(param_1 + 2) = 0;
      }
      else {
        pcVar3 = "length <= utl::numeric_limits<uint32_t>::max()";
LAB_180006cf1:
        Logging::Verify::ConditionFailed(pcVar3);
        *param_1 = 0;
        param_1[1] = 0;
        *(undefined4 *)(param_1 + 2) = 0xc0000095;
      }
      return param_1;
    }
    if (0xffffffff < *puVar2) {
      pcVar3 = "entry.length <= utl::numeric_limits<uint32_t>::max()";
      goto LAB_180006cf1;
    }
    uVar4 = uVar4 + *puVar2;
    puVar2 = puVar2 + 2;
  } while( true );
}



===== ApplyCipherPolicy @ 180006d30 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::StatusOnly,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly & __ptr64)> __cdecl
   Kerb3961::Aes8009::ApplyCipherPolicy(struct Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64 */

ReadOnlyBinary * __thiscall
Kerb3961::Aes8009::ApplyCipherPolicy(Aes8009 *this,ReadOnlyBinary *param_1)

{
  longlong *in_R8;
  
  if (*in_R8 == 1) {
    this[0x7c] = *(Aes8009 *)in_R8[1];
    *(undefined4 *)param_1 = 0;
  }
  else {
    Logging::Verify::ConditionFailed("marshaledPolicy.length == sizeof(m_policy)");
    *(undefined4 *)param_1 = 0xc000000d;
  }
  return param_1;
}



===== ChecksumEnabledForAccount @ 180006d80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: virtual bool __cdecl Kerb3961::Aes8009::ChecksumEnabledForAccount(struct
   Kerb3961::KeyPolicyScenario,unsigned int,enum Kerb3961::UserPolicyAttributes) __ptr64 */

bool __thiscall
Kerb3961::Aes8009::ChecksumEnabledForAccount
          (Aes8009 *this,undefined4 *param_2,uint param_3,ulonglong param_4)

{
  byte bVar1;
  uint uVar2;
  ulonglong uVar3;
  bool bVar4;
  uint uVar5;
  char cStack_17;
  
  uVar5 = param_3;
  uVar3 = Feature_184236346__private_IsEnabledDeviceUsageNoInline();
  bVar4 = false;
  if ((int)uVar3 == 0) {
    if ((((*(byte *)(param_2 + 1) & 0x20) == 0) && ((*(byte *)(param_2 + 1) & 8) != 0)) ||
       ((param_4 >> 0x39 & 1) == 0)) {
      bVar4 = true;
      if (*(longlong *)(this + 0x10) == 0x10) {
        bVar1 = (byte)param_3 >> 6 & 1;
      }
      else {
        bVar1 = (byte)param_3 >> 7;
      }
      cStack_17 = (char)((uint)*param_2 >> 8);
      if ((cStack_17 != '\x02') && (bVar1 == 0)) {
        bVar4 = false;
      }
      Logging::Cipher::UsageEnabled
                (*(ushort **)(this + 0x38),bVar4,CONCAT31((int3)(uVar5 >> 8),cStack_17),param_3);
    }
    else {
      bVar4 = true;
    }
  }
  else {
    if (((*(byte *)(param_2 + 1) & 0x28) != 8) && ((param_4 >> 0x39 & 1) != 0)) {
      uVar2 = (**(code **)(*(longlong *)(this + -8) + 0x30))();
      param_3 = param_3 | uVar2;
    }
    if (*(longlong *)(this + 0x10) == 0x10) {
      bVar1 = (byte)param_3 >> 6 & 1;
    }
    else {
      bVar1 = (byte)param_3 >> 7;
    }
    cStack_17 = (char)((uint)*param_2 >> 8);
    if ((cStack_17 == '\x02') || (bVar1 != 0)) {
      bVar4 = true;
    }
    Logging::Cipher::UsageEnabled
              (*(ushort **)(this + 0x38),bVar4,CONCAT31((int3)(uVar5 >> 8),cStack_17),param_3);
  }
  return bVar4;
}



===== ChecksumEnabledForUsage @ 180006e90 =====

/* private: virtual bool __cdecl Kerb3961::Aes8009::ChecksumEnabledForUsage(struct
   Kerb3961::KeyPolicyScenario,unsigned int) __ptr64 */

bool __thiscall
Kerb3961::Aes8009::ChecksumEnabledForUsage(Aes8009 *this,undefined4 *param_2,uint param_3)

{
  byte bVar1;
  bool bVar2;
  char cStackX_9;
  
  if (*(longlong *)(this + 0x10) == 0x10) {
    bVar1 = (byte)param_3 >> 6 & 1;
  }
  else {
    bVar1 = (byte)param_3 >> 7;
  }
  cStackX_9 = (char)((uint)*param_2 >> 8);
  if ((cStackX_9 == '\x02') || (bVar2 = false, bVar1 != 0)) {
    bVar2 = true;
  }
  Logging::Cipher::UsageEnabled
            (*(ushort **)(this + 0x38),bVar2,CONCAT31((int3)(param_3 >> 8),cStackX_9),param_3);
  return bVar2;
}



===== GetRequiredChecksum @ 180006ef0 =====

/* private: virtual unsigned int __cdecl Kerb3961::RC4_4757::GetRequiredChecksum(void) __ptr64 */

uint __thiscall Kerb3961::RC4_4757::GetRequiredChecksum(RC4_4757 *this)

{
  return *(uint *)(this + 0x20);
}



===== CipherEnabledForAccount @ 180006f00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: virtual bool __cdecl Kerb3961::Aes8009::CipherEnabledForAccount(struct
   Kerb3961::KeyPolicyScenario,unsigned int,enum Kerb3961::UserPolicyAttributes) __ptr64 */

bool __thiscall
Kerb3961::Aes8009::CipherEnabledForAccount
          (Aes8009 *this,undefined4 *param_2,uint param_3,ulonglong param_4)

{
  byte bVar1;
  uint uVar2;
  ulonglong uVar3;
  bool bVar4;
  uint uVar5;
  char cStack_17;
  
  uVar5 = param_3;
  uVar3 = Feature_184236346__private_IsEnabledDeviceUsageNoInline();
  bVar4 = false;
  if ((int)uVar3 == 0) {
    if ((((*(byte *)(param_2 + 1) & 0x20) == 0) && ((*(byte *)(param_2 + 1) & 8) != 0)) ||
       ((param_4 >> 0x39 & 1) == 0)) {
      bVar4 = true;
      if (*(longlong *)(this + 0x18) == 0x10) {
        bVar1 = (byte)param_3 >> 6 & 1;
      }
      else {
        bVar1 = (byte)param_3 >> 7;
      }
      cStack_17 = (char)((uint)*param_2 >> 8);
      if ((cStack_17 != '\x02') && (bVar1 == 0)) {
        bVar4 = false;
      }
      Logging::Cipher::UsageEnabled
                (*(ushort **)(this + 0x40),bVar4,CONCAT31((int3)(uVar5 >> 8),cStack_17),param_3);
    }
    else {
      bVar4 = true;
    }
  }
  else {
    if (((*(byte *)(param_2 + 1) & 0x28) != 8) && ((param_4 >> 0x39 & 1) != 0)) {
      uVar2 = (**(code **)(*(longlong *)this + 0x30))(this);
      param_3 = param_3 | uVar2;
    }
    if (*(longlong *)(this + 0x18) == 0x10) {
      bVar1 = (byte)param_3 >> 6 & 1;
    }
    else {
      bVar1 = (byte)param_3 >> 7;
    }
    cStack_17 = (char)((uint)*param_2 >> 8);
    if ((cStack_17 == '\x02') || (bVar1 != 0)) {
      bVar4 = true;
    }
    Logging::Cipher::UsageEnabled
              (*(ushort **)(this + 0x40),bVar4,CONCAT31((int3)(uVar5 >> 8),cStack_17),param_3);
  }
  return bVar4;
}



===== CipherEnabledForUsage @ 180007010 =====

/* private: virtual bool __cdecl Kerb3961::Aes8009::CipherEnabledForUsage(struct
   Kerb3961::KeyPolicyScenario,unsigned int) __ptr64 */

bool __thiscall
Kerb3961::Aes8009::CipherEnabledForUsage(Aes8009 *this,undefined4 *param_2,uint param_3)

{
  byte bVar1;
  bool bVar2;
  char cStackX_9;
  
  if (*(longlong *)(this + 0x18) == 0x10) {
    bVar1 = (byte)param_3 >> 6 & 1;
  }
  else {
    bVar1 = (byte)param_3 >> 7;
  }
  cStackX_9 = (char)((uint)*param_2 >> 8);
  if ((cStackX_9 == '\x02') || (bVar2 = false, bVar1 != 0)) {
    bVar2 = true;
  }
  Logging::Cipher::UsageEnabled
            (*(ushort **)(this + 0x40),bVar2,CONCAT31((int3)(param_3 >> 8),cStackX_9),param_3);
  return bVar2;
}



===== CompatibleCipher @ 180007070 =====

/* private: virtual bool __cdecl Kerb3961::Aes8009::CompatibleCipher(unsigned int) __ptr64 */

bool __thiscall Kerb3961::Aes8009::CompatibleCipher(Aes8009 *this,uint param_1)

{
  return param_1 == *(uint *)(this + 0x18);
}



===== Decrypt @ 180007080 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::Aes8009::Decrypt(struct Kerb3961::ReturnType<struct Kerb3961::SpecificKeyReturn,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn & __ptr64)> & __ptr64,struct
   Kerb3961::ReturnType<struct Kerb3961::CipherStateReturn,&struct Kerb3961::ResultBlock const &
   __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::CipherStateReturn,16>(struct
   Kerb3961::CipherStateReturn const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::CipherStateReturn,16>(struct Kerb3961::CipherStateReturn
   & __ptr64)> & __ptr64,struct Kerb3961::ReadOnlyBinary const & __ptr64,struct
   Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64 */

ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
* __thiscall
Kerb3961::Aes8009::Decrypt
          (Aes8009 *this,
          ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
          *param_1,ReturnType<Kerb3961::CipherStateReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn&___ptr64)>
                   *param_2,ReadOnlyBinary *param_3,ReadOnlyBinary *param_4)

{
  undefined8 *_Size;
  byte *pbVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  char *pcVar4;
  byte *pbVar5;
  int iVar6;
  undefined8 *_Size_00;
  byte bVar7;
  ReadOnlyBinary *pRVar8;
  ulonglong uVar9;
  long lVar10;
  undefined1 auStackY_138 [32];
  longlong local_108 [2];
  undefined8 *local_f8;
  undefined8 *local_f0;
  undefined1 local_e8 [8];
  byte *local_e0;
  long local_d8;
  undefined8 *local_c8;
  undefined8 *local_c0;
  undefined1 local_b8 [8];
  byte *local_b0;
  int local_a8;
  undefined1 local_a0 [8];
  undefined8 *local_98;
  ulonglong local_90;
  void *local_88;
  undefined1 local_80 [8];
  void *local_78;
  ulonglong local_70;
  longlong local_68;
  undefined1 local_60 [24];
  void *local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_138;
  if (*(ulonglong *)param_4 < *(longlong *)(this + 0x30) + 0x10U) {
    Logging::Verify::ConditionFailed("cipherText.length >= m_micLength + AES_BLOCK_SIZE");
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0xc000000d;
    return param_1;
  }
  _Size_00 = (undefined8 *)(*(ulonglong *)param_4 - *(longlong *)(this + 0x30));
  local_108[0] = *(longlong *)(param_2 + 8);
  local_c8 = *(undefined8 **)(param_3 + 8);
  _Size = _Size_00 + -2;
  MakeBuffer((__uint64)local_e8);
  lVar10 = local_d8;
  if (local_d8 < 0) {
    Logging::Verify::StatusFailed("hmacBuffer",local_d8);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(long *)(param_1 + 0x10) = local_d8;
    goto LAB_18000730d;
  }
  local_f0 = *(undefined8 **)(this + 0x30);
  local_f8 = _Size_00;
  Split<2>(local_80,param_4,&local_f8);
  local_f8 = (undefined8 *)0x10;
  local_f0 = _Size_00;
  Split<2>(local_a0,local_e8,&local_f8);
  puVar3 = local_c8;
  uVar2 = local_c8[1];
  *local_98 = *local_c8;
  local_98[1] = uVar2;
  memmove(local_88,local_78,(size_t)_Size_00);
  pRVar8 = (ReadOnlyBinary *)(local_108[0] + 0x30);
  GetHmac(local_b8,*(ReadOnlyBinary **)(this + 0x70),pRVar8,(__uint64)local_e8);
  if (local_a8 < 0) {
    pcVar4 = "hmac";
    iVar6 = local_a8;
LAB_1800071c6:
    Logging::Verify::StatusFailed(pcVar4,iVar6);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(int *)(param_1 + 0x10) = iVar6;
  }
  else {
    uVar9 = *(ulonglong *)(this + 0x30);
    if (uVar9 == local_70) {
      if (uVar9 != 0) {
        if (0xffffffff < uVar9) goto LAB_1800072de;
        pRVar8 = (ReadOnlyBinary *)((ulonglong)pRVar8 & 0xffffffffffffff00);
        if ((int)uVar9 != 0) {
          uVar9 = uVar9 & 0xffffffff;
          pbVar5 = local_b0;
          do {
            pbVar1 = pbVar5 + (local_68 - (longlong)local_b0);
            bVar7 = *pbVar5;
            pbVar5 = pbVar5 + 1;
            bVar7 = (byte)pRVar8 | *pbVar1 ^ bVar7;
            pRVar8 = (ReadOnlyBinary *)CONCAT71((int7)((ulonglong)pRVar8 >> 8),bVar7);
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
          if (bVar7 != 0) goto LAB_1800072de;
          lVar10 = local_d8;
        }
      }
      local_f8 = (undefined8 *)0x10;
      local_f0 = puVar3;
      if (local_90 < 0x10) {
        Logging::Verify::ConditionFailed("cipherText.length >= AES_BLOCK_SIZE");
        iVar6 = -0x3fffffdd;
      }
      else {
        DecryptCTS(local_108,*(__uint64 *)(this + 0x68),pRVar8,
                   (MutableBinary *)(local_108[0] + 0x18),(MutableBinary *)&local_f8);
        iVar6 = (int)local_108[0];
      }
      if (-1 < iVar6) {
        local_c8 = (undefined8 *)0x10;
        local_c0 = _Size;
        Split<2>(local_60,&local_90,&local_c8);
        memmove(local_e0,local_48,(size_t)_Size);
        *(long *)(param_1 + 0x10) = lVar10;
        *(undefined8 **)param_1 = _Size;
        *(byte **)(param_1 + 8) = local_e0;
        local_e0 = local_b0;
        goto LAB_18000730d;
      }
      pcVar4 = "BlockDecrypt(key->Ke, {AES_BLOCK_SIZE, IV}, ciphertextHMAC)";
      goto LAB_1800071c6;
    }
LAB_1800072de:
    Logging::Verify::ConditionFailed("SecureEqualBuffer(hmac, MIC)");
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0x8009030f;
  }
  if (local_b0 != (byte *)0x0) {
    operator_delete__(local_b0);
  }
LAB_18000730d:
  if (local_e0 != (byte *)0x0) {
    operator_delete__(local_e0);
  }
  return param_1;
}



===== DeriveKey @ 180007340 =====

/* private: struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct Kerb3961::ResultBlock
   const & __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::OwnedBinary,16>(struct
   Kerb3961::OwnedBinary const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)>
   __cdecl Kerb3961::Aes8009::DeriveKey(struct Kerb3961::ReadOnlyBinary const & __ptr64,struct
   Kerb3961::ReadOnlyBinary const & __ptr64,struct Kerb3961::ReadOnlyBinary const & __ptr64,unsigned
   __int64) __ptr64 */

ReadOnlyBinary * __thiscall
Kerb3961::Aes8009::DeriveKey
          (Aes8009 *this,ReadOnlyBinary *param_1,ReadOnlyBinary *param_2,ReadOnlyBinary *param_3,
          __uint64 param_4)

{
  uint uVar1;
  ulonglong uVar2;
  __uint64 _Var3;
  undefined4 local_res8 [2];
  undefined1 uStack0000000000000030;
  undefined7 in_stack_00000031;
  uint local_b8 [2];
  undefined8 local_b0;
  uint *puStack_a8;
  long local_a0;
  undefined8 local_98;
  undefined1 *puStack_90;
  undefined8 local_80;
  undefined4 *puStack_78;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 *puStack_60;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 local_48;
  undefined1 *puStack_40;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  uint *puStack_20;
  
  uVar2 = CONCAT71(in_stack_00000031,uStack0000000000000030);
  if (*(uint *)(this + 0x78) < uVar2) {
    Logging::Verify::ConditionFailed("resultSize <= m_checksumLength");
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0xc000000d;
  }
  else {
    local_58 = *(undefined4 *)param_3;
    uStack_54 = *(undefined4 *)(param_3 + 4);
    uStack_50 = *(undefined4 *)(param_3 + 8);
    uStack_4c = *(undefined4 *)(param_3 + 0xc);
    puStack_78 = local_res8;
    local_98 = 1;
    local_res8[0] = 0x1000000;
    local_80 = 4;
    uVar1 = (uint)uVar2;
    local_b8[0] = (uVar1 & 0x1fffffff) >> 0x15 | (uVar1 * 8 & 0xff0000) >> 8 |
                  (uVar1 * 8 & 0xff00) << 8 | uVar1 << 0x1b;
    puStack_a8 = local_b8;
    puStack_90 = &uStack0000000000000030;
    local_b0 = 4;
    uStack0000000000000030 = 0;
    local_38 = *(undefined4 *)param_4;
    uStack_34 = *(undefined4 *)(param_4 + 4);
    uStack_30 = *(undefined4 *)(param_4 + 8);
    uStack_2c = *(undefined4 *)(param_4 + 0xc);
    local_68 = 4;
    uStack_64 = 0;
    local_48 = 1;
    local_28 = 4;
    uStack_24 = 0;
    puStack_40 = puStack_90;
    puStack_60 = puStack_78;
    puStack_20 = puStack_a8;
    _Var3 = Concatenate<5>(&local_98,&local_68);
    GetHmac(&local_b0,*(ReadOnlyBinary **)(this + 0x70),param_2,_Var3);
    if (puStack_90 != (undefined1 *)0x0) {
      operator_delete__(puStack_90);
    }
    if (local_a0 < 0) {
      Logging::Verify::StatusFailed("hmac",local_a0);
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(long *)(param_1 + 0x10) = local_a0;
      if (puStack_a8 != (uint *)0x0) {
        operator_delete__(puStack_a8);
      }
    }
    else {
      *(uint **)(param_1 + 8) = puStack_a8;
      *(long *)(param_1 + 0x10) = local_a0;
      *(ulonglong *)param_1 = uVar2;
    }
  }
  return param_1;
}



===== DeriveSpecificKey @ 1800074a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::SpecificKeyReturn,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn & __ptr64)> __cdecl
   Kerb3961::Aes8009::DeriveSpecificKey(struct Kerb3961::ReadOnlyBinary const & __ptr64,enum
   Kerb3961::KeyUsage,enum Kerb3961::SpecificKeyScenario) __ptr64 */

ReadOnlyBinary * __thiscall
Kerb3961::Aes8009::DeriveSpecificKey
          (Aes8009 *this,ReadOnlyBinary *param_1,KeyUsage param_2,SpecificKeyScenario param_3)

{
  long lVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  char *pcVar4;
  int iVar5;
  undefined4 in_register_00000084;
  ReadOnlyBinary *pRVar6;
  int in_stack_00000028;
  undefined1 auStackY_b8 [32];
  undefined8 *local_88;
  undefined8 *local_80;
  undefined8 local_78;
  undefined8 *local_70;
  ReadOnlyBinary local_68 [8];
  void *local_60;
  undefined8 local_50;
  ulonglong local_48;
  
  pRVar6 = (ReadOnlyBinary *)CONCAT44(in_register_00000084,param_2);
  local_48 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_50 = (ulonglong)
             (param_3 >> 0x18 | (param_3 & 0xff0000) >> 8 | (param_3 & 0xff00) << 8 |
             param_3 << 0x18);
  utl::make_unique<Kerb3961::SimplifiedSpecificKey,0>();
  puVar2 = local_88;
  if (local_88 == (undefined8 *)0x0) {
    Logging::Verify::ConditionFailed("specificKey");
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0xc0000017;
  }
  else {
    if (in_stack_00000028 - 2U < 2) {
      local_70 = &local_50;
      local_50._0_5_ = CONCAT14(0x99,(undefined4)local_50);
      local_88 = (undefined8 *)0x0;
      local_80 = (undefined8 *)0x0;
      local_78 = 5;
      puVar3 = (undefined8 *)
               DeriveKey(this,local_68,pRVar6,(ReadOnlyBinary *)&local_78,(__uint64)&local_88);
      if ((void *)puVar2[1] != (void *)0x0) {
        operator_delete__((void *)puVar2[1]);
      }
      *puVar2 = *puVar3;
      *puVar3 = 0;
      puVar2[1] = puVar3[1];
      puVar3[1] = 0;
      *(undefined4 *)(puVar2 + 2) = *(undefined4 *)(puVar3 + 2);
      *(undefined4 *)(puVar3 + 2) = 0xc0000001;
      lVar1 = *(long *)(puVar2 + 2);
      if (local_60 != (void *)0x0) {
        operator_delete__(local_60);
      }
      if (lVar1 < 0) {
        Logging::Verify::StatusFailed
                  ("specificKey->Kc = DeriveKey(protocolKey, {5, constant.data}, {}, m_micLength)",
                   lVar1);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(long *)(param_1 + 0x10) = lVar1;
        goto LAB_1800075c2;
      }
    }
    if ((in_stack_00000028 - 1U & 0xfffffffd) != 0) {
LAB_18000774a:
      *(Aes8009 **)param_1 = this;
      *(undefined8 **)(param_1 + 8) = puVar2;
      *(undefined4 *)(param_1 + 0x10) = 0;
      return param_1;
    }
    local_80 = &local_50;
    local_50._0_5_ = CONCAT14(0xaa,(undefined4)local_50);
    local_78 = 0;
    local_70 = (undefined8 *)0x0;
    local_88 = (undefined8 *)0x5;
    puVar3 = (undefined8 *)
             DeriveKey(this,local_68,pRVar6,(ReadOnlyBinary *)&local_88,(__uint64)&local_78);
    if ((void *)puVar2[4] != (void *)0x0) {
      operator_delete__((void *)puVar2[4]);
    }
    puVar2[3] = *puVar3;
    *puVar3 = 0;
    puVar2[4] = puVar3[1];
    puVar3[1] = 0;
    *(undefined4 *)(puVar2 + 5) = *(undefined4 *)(puVar3 + 2);
    *(undefined4 *)(puVar3 + 2) = 0xc0000001;
    iVar5 = *(int *)(puVar2 + 5);
    if (local_60 != (void *)0x0) {
      operator_delete__(local_60);
    }
    if (iVar5 < 0) {
      pcVar4 = "specificKey->Ke = DeriveKey(protocolKey, {5, constant.data}, {}, m_keySize)";
    }
    else {
      local_80 = &local_50;
      local_50._0_5_ = CONCAT14(0x55,(undefined4)local_50);
      local_78 = 0;
      local_70 = (undefined8 *)0x0;
      local_88 = (undefined8 *)0x5;
      puVar3 = (undefined8 *)
               DeriveKey(this,local_68,pRVar6,(ReadOnlyBinary *)&local_88,(__uint64)&local_78);
      if ((void *)puVar2[7] != (void *)0x0) {
        operator_delete__((void *)puVar2[7]);
      }
      puVar2[6] = *puVar3;
      *puVar3 = 0;
      puVar2[7] = puVar3[1];
      puVar3[1] = 0;
      *(undefined4 *)(puVar2 + 8) = *(undefined4 *)(puVar3 + 2);
      *(undefined4 *)(puVar3 + 2) = 0xc0000001;
      iVar5 = *(int *)(puVar2 + 8);
      if (local_60 != (void *)0x0) {
        operator_delete__(local_60);
      }
      if (-1 < iVar5) goto LAB_18000774a;
      pcVar4 = "specificKey->Ki = DeriveKey(protocolKey, {5, constant.data}, {}, m_micLength)";
    }
    Logging::Verify::StatusFailed(pcVar4,iVar5);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(int *)(param_1 + 0x10) = iVar5;
  }
  if (puVar2 == (undefined8 *)0x0) {
    return param_1;
  }
LAB_1800075c2:
  if ((void *)puVar2[7] != (void *)0x0) {
    operator_delete__((void *)puVar2[7]);
  }
  if ((void *)puVar2[4] != (void *)0x0) {
    operator_delete__((void *)puVar2[4]);
  }
  if ((void *)puVar2[1] != (void *)0x0) {
    operator_delete__((void *)puVar2[1]);
  }
  operator_delete__(puVar2);
  return param_1;
}



===== Encrypt @ 180007790 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::Aes8009::Encrypt(struct Kerb3961::ReturnType<struct Kerb3961::SpecificKeyReturn,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn & __ptr64)> & __ptr64,struct
   Kerb3961::ReturnType<struct Kerb3961::CipherStateReturn,&struct Kerb3961::ResultBlock const &
   __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::CipherStateReturn,16>(struct
   Kerb3961::CipherStateReturn const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::CipherStateReturn,16>(struct Kerb3961::CipherStateReturn
   & __ptr64)> & __ptr64,struct Kerb3961::ReadOnlyBinary const & __ptr64,struct
   Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64 */

ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
* __thiscall
Kerb3961::Aes8009::Encrypt
          (Aes8009 *this,
          ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
          *param_1,ReturnType<Kerb3961::CipherStateReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn&___ptr64)>
                   *param_2,ReadOnlyBinary *param_3,ReadOnlyBinary *param_4)

{
  size_t _Size;
  ulonglong uVar1;
  ReturnType<Kerb3961::CipherStateReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn&___ptr64)>
  *pRVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  ReadOnlyBinary *_Size_00;
  undefined1 auStackY_128 [32];
  size_t local_f8;
  ReturnType<Kerb3961::CipherStateReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn&___ptr64)>
  *local_f0;
  ReturnType<Kerb3961::CipherStateReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn&___ptr64)>
  *local_e8;
  undefined8 local_e0;
  ReturnType<Kerb3961::CipherStateReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn&___ptr64)>
  *local_d8;
  long local_d0;
  MutableBinary *local_c8;
  ReadOnlyBinary *local_c0;
  undefined1 local_b8 [8];
  ReturnType<Kerb3961::CipherStateReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn&___ptr64)>
  *local_b0;
  long local_a8;
  undefined1 local_a0 [8];
  undefined4 *local_98;
  ulonglong local_90;
  void *local_88;
  ULONG local_80 [2];
  PUCHAR local_78;
  void *local_68;
  undefined1 local_60 [8];
  void *local_58;
  void *local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_128;
  uVar1 = *(ulonglong *)param_4;
  _Size = uVar1 + 0x10;
  local_e8 = param_2;
  if (*(longlong *)(this + 0x30) + _Size <= uVar1) {
    Logging::Verify::ConditionFailed("resultSize > clearData.length");
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0xc0000095;
    return param_1;
  }
  MakeBuffer((__uint64)&local_e0);
  if (local_d0 < 0) {
    Logging::Verify::StatusFailed("resultBuffer",local_d0);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(long *)(param_1 + 0x10) = local_d0;
  }
  else {
    pRVar2 = *(ReturnType<Kerb3961::CipherStateReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn&___ptr64)>
               **)(param_3 + 8);
    local_c8 = (MutableBinary *)(*(longlong *)(local_e8 + 8) + 0x18);
    if ((*(longlong *)local_c8 == 0) ||
       (local_c0 = (ReadOnlyBinary *)(*(longlong *)(local_e8 + 8) + 0x30),
       *(longlong *)local_c0 == 0)) {
      local_e8 = pRVar2;
      Logging::Verify::ConditionFailed("key->Ke.length > 0 && key->Ki.length > 0");
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(undefined4 *)(param_1 + 0x10) = 0xc000000d;
    }
    else {
      local_f8 = 0x10;
      local_f0 = (ReturnType<Kerb3961::CipherStateReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn&___ptr64)>
                  *)_Size;
      local_e8 = pRVar2;
      Split<2>(local_a0,&local_e0,&local_f8);
      local_f0 = *(ReturnType<Kerb3961::CipherStateReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn&___ptr64)>
                   **)param_4;
      local_f8 = 0x10;
      Split<2>(local_80,&local_90,&local_f8);
      uVar3 = *(undefined4 *)(pRVar2 + 4);
      uVar4 = *(undefined4 *)(pRVar2 + 8);
      uVar5 = *(undefined4 *)(pRVar2 + 0xc);
      *local_98 = *(undefined4 *)pRVar2;
      local_98[1] = uVar3;
      local_98[2] = uVar4;
      local_98[3] = uVar5;
      iVar6 = BCryptGenRandom((BCRYPT_ALG_HANDLE)0x0,local_78,local_80[0],2);
      if (iVar6 < 0) {
        pcVar7 = "RandomFill(confounder)";
      }
      else {
        _Size_00 = *(ReadOnlyBinary **)param_4;
        memmove(local_68,*(void **)(param_4 + 8),(size_t)_Size_00);
        local_f0 = local_e8;
        local_f8 = 0x10;
        if (local_90 < 0x10) {
          Logging::Verify::ConditionFailed("clearText.length >= AES_BLOCK_SIZE");
          iVar6 = -0x3fffffdd;
        }
        else {
          EncryptCTS(&local_e8,*(__uint64 *)(this + 0x68),_Size_00,local_c8,
                     (MutableBinary *)&local_f8);
          iVar6 = (int)local_e8;
        }
        if (-1 < iVar6) {
          local_f8 = uVar1 + 0x20;
          local_f0 = local_d8;
          GetHmac(local_b8,*(ReadOnlyBinary **)(this + 0x70),local_c0,(__uint64)&local_f8);
          if (local_a8 < 0) {
            Logging::Verify::StatusFailed("hmac",local_a8);
            *(undefined8 *)param_1 = 0;
            *(undefined8 *)(param_1 + 8) = 0;
            *(long *)(param_1 + 0x10) = local_a8;
            if (local_b0 !=
                (ReturnType<Kerb3961::CipherStateReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn&___ptr64)>
                 *)0x0) {
              operator_delete__(local_b0);
            }
            if (local_d8 ==
                (ReturnType<Kerb3961::CipherStateReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn&___ptr64)>
                 *)0x0) {
              return param_1;
            }
          }
          else {
            local_f0 = *(ReturnType<Kerb3961::CipherStateReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn&___ptr64)>
                         **)(this + 0x30);
            local_f8 = _Size;
            Split<2>(local_60,&local_e0,&local_f8);
            memmove(local_58,local_88,_Size);
            memmove(local_48,local_b0,*(size_t *)(this + 0x30));
            *(undefined8 *)param_1 = local_e0;
            *(long *)(param_1 + 0x10) = local_d0;
            *(ReturnType<Kerb3961::CipherStateReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn&___ptr64)>
              **)(param_1 + 8) = local_d8;
            if (local_b0 ==
                (ReturnType<Kerb3961::CipherStateReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn&___ptr64)>
                 *)0x0) {
              return param_1;
            }
            local_d8 = local_b0;
          }
          goto LAB_180007a6b;
        }
        pcVar7 = "BlockEncrypt(key->Ke, {AES_BLOCK_SIZE, IV}, ciphertext)";
      }
      Logging::Verify::StatusFailed(pcVar7,iVar6);
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(int *)(param_1 + 0x10) = iVar6;
    }
  }
  if (local_d8 ==
      (ReturnType<Kerb3961::CipherStateReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn&___ptr64)>
       *)0x0) {
    return param_1;
  }
LAB_180007a6b:
  operator_delete__(local_d8);
  return param_1;
}



===== GetKeySeedLength @ 180007ab0 =====

/* private: virtual unsigned __int64 __cdecl Kerb3961::RC4_4757::GetKeySeedLength(void) __ptr64 */

__uint64 __thiscall Kerb3961::RC4_4757::GetKeySeedLength(RC4_4757 *this)

{
  return 0x10;
}



===== FreeCipherState @ 180007ac0 =====

/* private: virtual void __cdecl Kerb3961::Aes8009::FreeCipherState(void * __ptr64) __ptr64 */

void __thiscall Kerb3961::Aes8009::FreeCipherState(Aes8009 *this,void *param_1)

{
  if (param_1 != (void *)0x0) {
    operator_delete__(param_1);
  }
  return;
}



===== GetChecksumLength @ 180007ae0 =====

/* private: virtual unsigned __int64 __cdecl Kerb3961::Aes8009::GetChecksumLength(void) __ptr64 */

__uint64 __thiscall Kerb3961::Aes8009::GetChecksumLength(Aes8009 *this)

{
  return *(__uint64 *)(this + 0x28);
}



===== GetChecksumName @ 180007af0 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::ReadOnlyStringResult,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::ReadOnlyStringResult,16>(struct Kerb3961::ReadOnlyStringResult const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::ReadOnlyStringResult,16>(struct Kerb3961::ReadOnlyStringResult & __ptr64)> const
   __cdecl Kerb3961::Aes8009::GetChecksumName(void) __ptr64 */

void __thiscall Kerb3961::Aes8009::GetChecksumName(Aes8009 *this)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 *in_RDX;
  
  uVar1 = *(undefined8 *)(this + 0x50);
  uVar2 = *(undefined8 *)(this + 0x48);
  *(undefined4 *)(in_RDX + 2) = 0;
  *in_RDX = uVar1;
  in_RDX[1] = uVar2;
  return;
}



===== GetCipherPreferenceWeight @ 180007b10 =====

/* private: virtual unsigned int __cdecl Kerb3961::Aes8009::GetCipherPreferenceWeight(void) __ptr64
    */

uint __thiscall Kerb3961::Aes8009::GetCipherPreferenceWeight(Aes8009 *this)

{
  return *(uint *)(this + 0x24);
}



===== GetCipherAttributes @ 180007b20 =====

/* private: virtual enum Kerb3961::CipherAttributes __cdecl
   Kerb3961::Aes8009::GetCipherAttributes(void) __ptr64 */

CipherAttributes __thiscall Kerb3961::Aes8009::GetCipherAttributes(Aes8009 *this)

{
  return 0x80000007;
}



===== GetCipherBitmask @ 180007b30 =====

/* private: virtual unsigned int __cdecl Kerb3961::Aes8009::GetCipherBitmask(void) __ptr64 */

uint __thiscall Kerb3961::Aes8009::GetCipherBitmask(Aes8009 *this)

{
  byte bVar1;
  uint local_res8;
  
  bVar1 = 0x80;
  if (*(longlong *)(this + 0x18) == 0x10) {
    bVar1 = 0x40;
  }
  local_res8 = (uint)bVar1;
  return local_res8;
}



===== GetCipherName @ 180007b60 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::ReadOnlyStringResult,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::ReadOnlyStringResult,16>(struct Kerb3961::ReadOnlyStringResult const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::ReadOnlyStringResult,16>(struct Kerb3961::ReadOnlyStringResult & __ptr64)> const
   __cdecl Kerb3961::Aes8009::GetCipherName(void) __ptr64 */

void __thiscall Kerb3961::Aes8009::GetCipherName(Aes8009 *this)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 *in_RDX;
  
  uVar1 = *(undefined8 *)(this + 0x48);
  uVar2 = *(undefined8 *)(this + 0x40);
  *(undefined4 *)(in_RDX + 2) = 0;
  *in_RDX = uVar1;
  in_RDX[1] = uVar2;
  return;
}



===== GetCipherSessionKeyBitmask @ 180007b80 =====

/* private: virtual unsigned int __cdecl Kerb3961::Aes8009::GetCipherSessionKeyBitmask(void) __ptr64
    */

uint __thiscall Kerb3961::Aes8009::GetCipherSessionKeyBitmask(Aes8009 *this)

{
                    /* 0x7b80  22   */
  return 0;
}



===== GetCiphertextLength @ 180007b90 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::ResultAdapter<unsigned
   __int64>,&struct Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::ResultAdapter<unsigned __int64>,8>(struct Kerb3961::ResultAdapter<unsigned __int64>
   const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::ResultAdapter<unsigned __int64>,8>(struct Kerb3961::ResultAdapter<unsigned __int64> &
   __ptr64)> __cdecl Kerb3961::Aes8009::GetCiphertextLength(unsigned __int64) __ptr64 */

__uint64 __thiscall Kerb3961::Aes8009::GetCiphertextLength(Aes8009 *this,__uint64 param_1)

{
  ulonglong uVar1;
  ulonglong in_R8;
  
  uVar1 = *(longlong *)(this + 0x30) + 0x10 + in_R8;
  if (in_R8 < uVar1) {
    *(undefined4 *)(param_1 + 8) = 0xc0000001;
    *(undefined4 *)(param_1 + 8) = 0;
    *(ulonglong *)param_1 = uVar1;
  }
  else {
    Logging::Verify::ConditionFailed("resultSize > plaintextLength");
    *(undefined8 *)param_1 = 0;
    *(undefined4 *)(param_1 + 8) = 0xc0000001;
    *(undefined4 *)(param_1 + 8) = 0xc0000095;
  }
  return param_1;
}



===== GetDefaultStringToKeyParams @ 180007bf0 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::ReadOnlyBinaryResult,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::ReadOnlyBinaryResult,16>(struct Kerb3961::ReadOnlyBinaryResult const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::ReadOnlyBinaryResult,16>(struct Kerb3961::ReadOnlyBinaryResult & __ptr64)> const
   __cdecl Kerb3961::Aes8009::GetDefaultStringToKeyParams(void) __ptr64 */

void __thiscall Kerb3961::Aes8009::GetDefaultStringToKeyParams(Aes8009 *this)

{
  undefined8 *in_RDX;
  
  *(undefined4 *)(in_RDX + 2) = 0;
  in_RDX[1] = &`private:_virtual_struct_Kerb3961::ReturnType<Kerb3961::ReadOnlyBinaryResult,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::ReadOnlyBinaryResult,16>(struct_Kerb3961::ReadOnlyBinaryResult_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::ReadOnlyBinaryResult,16>(struct_Kerb3961::ReadOnlyBinaryResult&___ptr64)>_const___cdecl_Kerb3961::Aes8009::GetDefaultStringToKeyParams(void)___ptr64'
               ::__l2::params;
  *in_RDX = 4;
  return;
}



===== GetProtocolKeyLength @ 180007c20 =====

/* private: virtual unsigned __int64 __cdecl Kerb3961::Aes8009::GetProtocolKeyLength(void) __ptr64
    */

__uint64 __thiscall Kerb3961::Aes8009::GetProtocolKeyLength(Aes8009 *this)

{
  return *(__uint64 *)(this + 0x18);
}



===== GetMic @ 180007c30 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::Aes8009::GetMic(struct Kerb3961::ReturnType<struct Kerb3961::SpecificKeyReturn,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn & __ptr64)> & __ptr64,struct
   Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64 */

ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
* __thiscall
Kerb3961::Aes8009::GetMic
          (Aes8009 *this,
          ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
          *param_1,ReadOnlyBinary *param_2)

{
  __uint64 in_R9;
  undefined1 local_28 [8];
  void *local_20;
  long local_18;
  
  if (*(longlong *)*(ReadOnlyBinary **)(param_2 + 8) == 0) {
    Logging::Verify::ConditionFailed("key->Kc.length > 0");
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0xc000000d;
  }
  else {
    GetHmac(local_28,*(ReadOnlyBinary **)(this + 0x68),*(ReadOnlyBinary **)(param_2 + 8),in_R9);
    if (local_18 < 0) {
      Logging::Verify::StatusFailed("hmac",local_18);
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(long *)(param_1 + 0x10) = local_18;
      if (local_20 != (void *)0x0) {
        operator_delete__(local_20);
      }
    }
    else {
      *(undefined8 *)param_1 = *(undefined8 *)(this + 0x28);
      *(void **)(param_1 + 8) = local_20;
      *(long *)(param_1 + 0x10) = local_18;
    }
  }
  return param_1;
}



===== GetRequiredChecksum @ 180007cf0 =====

/* private: virtual unsigned int __cdecl Kerb3961::Aes8009::GetRequiredChecksum(void) __ptr64 */

uint __thiscall Kerb3961::Aes8009::GetRequiredChecksum(Aes8009 *this)

{
  return *(uint *)(this + 0x28);
}



===== Initialize @ 180007d00 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::StatusOnly,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly & __ptr64)> __cdecl
   Kerb3961::Aes8009::Initialize(void) __ptr64 */

void __thiscall Kerb3961::Aes8009::Initialize(Aes8009 *this)

{
  NTSTATUS NVar1;
  char *pcVar2;
  long *in_RDX;
  ULONG local_res8 [2];
  
  local_res8[0] = 0;
  NVar1 = BCryptOpenAlgorithmProvider((BCRYPT_ALG_HANDLE *)(this + 0x68),L"AES",(LPCWSTR)0x0,0);
  if (NVar1 < 0) {
    pcVar2 = "BCryptOpenAlgorithmProvider(&m_cipherHandle, BCRYPT_AES_ALGORITHM, nullptr, 0)";
  }
  else {
    NVar1 = BCryptSetProperty(*(BCRYPT_HANDLE *)(this + 0x68),L"ChainingMode",
                              (PUCHAR)L"ChainingModeCBC",0x20,0);
    if (NVar1 < 0) {
      pcVar2 = 
      "BCryptSetProperty(m_cipherHandle, BCRYPT_CHAINING_MODE, (PUCHAR)BCRYPT_CHAIN_MODE_CBC, sizeof(BCRYPT_CHAIN_MODE_CBC), 0 )"
      ;
    }
    else {
      NVar1 = BCryptOpenAlgorithmProvider
                        ((BCRYPT_ALG_HANDLE *)(this + 0x70),*(LPCWSTR *)(this + 0x38),(LPCWSTR)0x0,8
                        );
      if (NVar1 < 0) {
        pcVar2 = 
        "BCryptOpenAlgorithmProvider(&m_checksumHandle, m_hashAlgorithmName, nullptr, BCRYPT_ALG_HANDLE_HMAC_FLAG)"
        ;
      }
      else {
        NVar1 = BCryptGetProperty(*(BCRYPT_HANDLE *)(this + 0x70),L"HashDigestLength",
                                  (PUCHAR)(this + 0x78),4,local_res8,0);
        if (-1 < NVar1) {
          this[0x7c] = (Aes8009)0x1;
          *in_RDX = 0;
          return;
        }
        pcVar2 = 
        "BCryptGetProperty(m_checksumHandle, BCRYPT_HASH_LENGTH, reinterpret_cast<uint8_t*>(&m_checksumLength), sizeof(m_checksumLength), &ignore, 0)"
        ;
      }
    }
  }
  Logging::Verify::StatusFailed(pcVar2,NVar1);
  *in_RDX = NVar1;
  return;
}



===== InitializeCipherState @ 180007e30 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::CipherStateReturn,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::CipherStateReturn,16>(struct Kerb3961::CipherStateReturn const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::CipherStateReturn,16>(struct Kerb3961::CipherStateReturn & __ptr64)> __cdecl
   Kerb3961::Aes8009::InitializeCipherState(struct Kerb3961::ReturnType<struct
   Kerb3961::SpecificKeyReturn,&struct Kerb3961::ResultBlock const & __ptr64 __cdecl
   Kerb3961::SingleGetter<struct Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn
   const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn & __ptr64)> & __ptr64,bool)
   __ptr64 */

ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
* __thiscall
Kerb3961::Aes8009::InitializeCipherState
          (Aes8009 *this,
          ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
          *param_1,bool param_2)

{
  undefined1 local_28 [8];
  void *local_20;
  long local_18;
  
  MakeBuffer((__uint64)local_28);
  if (local_18 < 0) {
    Logging::Verify::StatusFailed("cipherState",local_18);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined8 *)(param_1 + 0x10) = 0;
    *(long *)(param_1 + 0x10) = local_18;
    if (local_20 != (void *)0x0) {
      operator_delete__(local_20);
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(void **)(param_1 + 8) = local_20;
    *(Aes8009 **)param_1 = this;
  }
  return param_1;
}



===== MarshalCipherPolicy @ 180007ec0 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::Aes8009::MarshalCipherPolicy(void) __ptr64 */

void __thiscall Kerb3961::Aes8009::MarshalCipherPolicy(Aes8009 *this)

{
  undefined8 *in_RDX;
  undefined8 local_28;
  Aes8009 *local_20;
  long local_18;
  
  MakeBuffer((__uint64)&local_28);
  if (local_18 < 0) {
    Logging::Verify::StatusFailed("marshaledPolicy",local_18);
    *in_RDX = 0;
    in_RDX[1] = 0;
    *(long *)(in_RDX + 2) = local_18;
    if (local_20 != (Aes8009 *)0x0) {
      operator_delete__(local_20);
    }
  }
  else {
    *local_20 = this[0x7c];
    *in_RDX = local_28;
    *(long *)(in_RDX + 2) = local_18;
    in_RDX[1] = local_20;
  }
  return;
}



===== PseudoRandom @ 180007f50 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::Aes8009::PseudoRandom(struct Kerb3961::ReadOnlyBinary const & __ptr64,struct
   Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64 */

ReadOnlyBinary * __thiscall
Kerb3961::Aes8009::PseudoRandom(Aes8009 *this,ReadOnlyBinary *param_1,ReadOnlyBinary *param_2)

{
  __uint64 in_R9;
  undefined8 local_18;
  char *local_10;
  
  local_18 = 3;
  local_10 = "prf";
  DeriveKey(this,param_1,param_2,(ReadOnlyBinary *)&local_18,in_R9);
  return param_1;
}



===== RandomKey @ 180007fa0 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::Aes8009::RandomKey(void) __ptr64 */

void __thiscall Kerb3961::Aes8009::RandomKey(Aes8009 *this)

{
  __uint64 in_RDX;
  
  RandomBuffer(in_RDX);
  return;
}



===== RandomToKey @ 180007fd0 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::Aes8009::RandomToKey(struct Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64 */

ReadOnlyBinary * __thiscall Kerb3961::Aes8009::RandomToKey(Aes8009 *this,ReadOnlyBinary *param_1)

{
  ulonglong *in_R8;
  
  if (*in_R8 < *(ulonglong *)(this + 0x18)) {
    Logging::Verify::ConditionFailed("randomSeed.length >= m_keySize");
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0xc0000023;
  }
  else {
    CopyBuffer(param_1);
  }
  return param_1;
}



===== StringToKey @ 180008030 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::Aes8009::StringToKey(struct Kerb3961::ReadOnlyString const & __ptr64,struct
   Kerb3961::ReadOnlyString const & __ptr64,struct Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64
    */

ReadOnlyString * __thiscall
Kerb3961::Aes8009::StringToKey
          (Aes8009 *this,ReadOnlyString *param_1,ReadOnlyString *param_2,ReadOnlyBinary *param_3)

{
  ulonglong uVar1;
  bool bVar2;
  uint uVar3;
  char *pcVar4;
  __uint64 _Var5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong *in_stack_00000028;
  undefined2 *local_38;
  undefined2 *local_30;
  undefined2 local_28;
  undefined6 uStack_26;
  
  if (*in_stack_00000028 == 4) {
    uVar3 = *(uint *)in_stack_00000028[1];
    uVar3 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    if (*(uint *)(this + 0x60) < uVar3) {
      pcVar4 = "iterations <= m_maxIterationCount";
    }
    else {
      if (*(uint *)(this + 100) <= uVar3) {
        local_38 = &local_28;
        local_30 = &local_28;
        local_28 = 0;
        _Var5 = *(ulonglong *)param_3 + 1 + *(longlong *)(this + 0x48);
        if (*(ulonglong *)param_3 < _Var5) {
          uVar6 = 7;
          if ((_Var5 < 8) ||
             (bVar2 = utl::
                      basic_string<unsigned_short,utl::char_traits<unsigned_short>,utl::allocator<unsigned_short>_>
                      ::_Grow((basic_string<unsigned_short,utl::char_traits<unsigned_short>,utl::allocator<unsigned_short>_>
                               *)&local_38,_Var5), bVar2)) {
            bVar2 = utl::
                    basic_string<unsigned_short,utl::char_traits<unsigned_short>,utl::allocator<unsigned_short>_>
                    ::append((basic_string<unsigned_short,utl::char_traits<unsigned_short>,utl::allocator<unsigned_short>_>
                              *)&local_38,*(ushort **)(this + 0x40),*(__uint64 *)(this + 0x48));
            if (bVar2) {
              uVar7 = (longlong)local_30 - (longlong)local_38 >> 1;
              if (local_38 != &local_28) {
                uVar6 = CONCAT62(uStack_26,local_28) - (longlong)local_38 >> 1;
              }
              uVar1 = uVar7 + 1;
              if ((uVar1 < uVar7) ||
                 ((uVar6 < uVar1 &&
                  (bVar2 = utl::
                           basic_string<unsigned_short,utl::char_traits<unsigned_short>,utl::allocator<unsigned_short>_>
                           ::_Grow((basic_string<unsigned_short,utl::char_traits<unsigned_short>,utl::allocator<unsigned_short>_>
                                    *)&local_38,uVar1), !bVar2)))) {
                pcVar4 = "saltp.append(1, L\'\\x00\')";
              }
              else {
                local_38[uVar7] = 0;
                local_30 = local_38 + uVar1;
                *local_30 = 0;
                bVar2 = utl::
                        basic_string<unsigned_short,utl::char_traits<unsigned_short>,utl::allocator<unsigned_short>_>
                        ::append((basic_string<unsigned_short,utl::char_traits<unsigned_short>,utl::allocator<unsigned_short>_>
                                  *)&local_38,*(ushort **)(param_3 + 8),*(__uint64 *)param_3);
                if (bVar2) {
                  Logging::Verify::StatusFailed("saltUTF8",-0x3fffffff);
                  *(undefined8 *)param_1 = 0;
                  *(undefined8 *)(param_1 + 8) = 0;
                  *(undefined4 *)(param_1 + 0x10) = 0xc0000001;
                  goto LAB_1800081f4;
                }
                pcVar4 = "saltp.append(salt.buffer, salt.length)";
              }
            }
            else {
              pcVar4 = "saltp.append(m_encryptionTypeName)";
            }
            Logging::Verify::ConditionFailed(pcVar4);
            *(undefined8 *)param_1 = 0;
            *(undefined8 *)(param_1 + 8) = 0;
            *(undefined4 *)(param_1 + 0x10) = 0xc0000023;
          }
          else {
            Logging::Verify::ConditionFailed
                      ("saltp.reserve(salt.length + m_encryptionTypeName.length() + 1)");
            *(undefined8 *)param_1 = 0;
            *(undefined8 *)(param_1 + 8) = 0;
            *(undefined4 *)(param_1 + 0x10) = 0xc0000017;
          }
        }
        else {
          Logging::Verify::ConditionFailed("saltpLength > salt.length");
          *(undefined8 *)param_1 = 0;
          *(undefined8 *)(param_1 + 8) = 0;
          *(undefined4 *)(param_1 + 0x10) = 0xc0000095;
        }
LAB_1800081f4:
        if (local_38 == &local_28) {
          return param_1;
        }
        operator_delete__(local_38);
        return param_1;
      }
      pcVar4 = "iterations >= m_minIterationCount";
    }
  }
  else {
    pcVar4 = "stringToKeyParameters.length == sizeof(uint32_t)";
  }
  Logging::Verify::ConditionFailed(pcVar4);
  *(undefined8 *)param_1 = 0;
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0xc000000d;
  return param_1;
}



===== Uninitialize @ 180008230 =====

/* private: virtual void __cdecl Kerb3961::Aes8009::Uninitialize(void) __ptr64 */

void __thiscall Kerb3961::Aes8009::Uninitialize(Aes8009 *this)

{
  if (*(BCRYPT_ALG_HANDLE *)(this + 0x68) != (BCRYPT_ALG_HANDLE)0x0) {
    BCryptCloseAlgorithmProvider(*(BCRYPT_ALG_HANDLE *)(this + 0x68),0);
    *(undefined8 *)(this + 0x68) = 0;
  }
  if (*(BCRYPT_ALG_HANDLE *)(this + 0x70) != (BCRYPT_ALG_HANDLE)0x0) {
    BCryptCloseAlgorithmProvider(*(BCRYPT_ALG_HANDLE *)(this + 0x70),0);
    *(undefined8 *)(this + 0x70) = 0;
  }
  return;
}



===== VerifyMic @ 180008280 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::StatusOnly,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly & __ptr64)> __cdecl
   Kerb3961::RC4_4757::VerifyMic(struct Kerb3961::ReturnType<struct
   Kerb3961::SpecificKeyReturn,&struct Kerb3961::ResultBlock const & __ptr64 __cdecl
   Kerb3961::SingleGetter<struct Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn
   const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn & __ptr64)> & __ptr64,struct
   Kerb3961::ReadOnlyBinary const & __ptr64,struct Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64
    */

ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
* __thiscall
Kerb3961::RC4_4757::VerifyMic
          (RC4_4757 *this,
          ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
          *param_1,ReadOnlyBinary *param_2,ReadOnlyBinary *param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  ulonglong uVar3;
  uint uVar4;
  ulonglong uVar5;
  byte bVar6;
  ulonglong *in_stack_00000028;
  ulonglong local_28;
  void *local_20;
  long local_18;
  
  (**(code **)(*(longlong *)this + 0x58))(this,&local_28);
  if (local_18 < 0) {
    Logging::Verify::StatusFailed("compare",local_18);
    *(long *)param_1 = local_18;
    goto LAB_18000831e;
  }
  uVar3 = *in_stack_00000028;
  if (uVar3 == local_28) {
    if (uVar3 != 0) {
      if (0xffffffff < uVar3) goto LAB_18000830c;
      bVar6 = 0;
      uVar5 = 0;
      if ((int)uVar3 != 0) {
        do {
          pbVar1 = (byte *)(uVar5 + in_stack_00000028[1]);
          pbVar2 = (byte *)(uVar5 + (longlong)local_20);
          uVar4 = (int)uVar5 + 1;
          uVar5 = (ulonglong)uVar4;
          bVar6 = bVar6 | *pbVar1 ^ *pbVar2;
        } while (uVar4 < (uint)*in_stack_00000028);
        if (bVar6 != 0) goto LAB_18000830c;
      }
    }
    *(undefined4 *)param_1 = 0;
  }
  else {
LAB_18000830c:
    Logging::Verify::ConditionFailed("SecureEqualBuffer(mic, compare)");
    *(undefined4 *)param_1 = 0x8009030f;
  }
LAB_18000831e:
  if (local_20 != (void *)0x0) {
    operator_delete__(local_20);
  }
  return param_1;
}



===== _Grow @ 180008344 =====

/* private: bool __cdecl utl::basic_string<unsigned short,struct utl::char_traits<unsigned
   short>,class utl::allocator<unsigned short> >::_Grow(unsigned __int64) __ptr64 */

bool __thiscall
utl::basic_string<unsigned_short,utl::char_traits<unsigned_short>,utl::allocator<unsigned_short>_>::
_Grow(basic_string<unsigned_short,utl::char_traits<unsigned_short>,utl::allocator<unsigned_short>_>
      *this,__uint64 param_1)

{
  basic_string<unsigned_short,utl::char_traits<unsigned_short>,utl::allocator<unsigned_short>_>
  *pbVar1;
  __uint64 _Var2;
  longlong lVar3;
  ulonglong uVar4;
  void *_Dst;
  bool bVar5;
  
  pbVar1 = this + 0x10;
  if (*(basic_string<unsigned_short,utl::char_traits<unsigned_short>,utl::allocator<unsigned_short>_>
        **)this == pbVar1) {
    lVar3 = 7;
  }
  else {
    lVar3 = *(longlong *)pbVar1 -
            (longlong)
            *(basic_string<unsigned_short,utl::char_traits<unsigned_short>,utl::allocator<unsigned_short>_>
              **)this >> 1;
  }
  uVar4 = lVar3 * 2 + 1;
  if (uVar4 < param_1) {
    uVar4 = param_1;
  }
  if (0x3ffffffffffffff7 < uVar4) {
    uVar4 = 0x3ffffffffffffff7;
  }
  bVar5 = false;
  if ((param_1 <= uVar4) &&
     (uVar4 = uVar4 + 8 & 0xfffffffffffffff8, _Var2 = uVar4 * 2, uVar4 < 0x8000000000000000)) {
    _Dst = operator_new__(_Var2,(nothrow_t *)param_1);
    if (_Dst != (void *)0x0) {
      lVar3 = *(longlong *)(this + 8) - (longlong)*(void **)this >> 1;
      memmove(_Dst,*(void **)this,lVar3 * 2 + 2);
      if (*(basic_string<unsigned_short,utl::char_traits<unsigned_short>,utl::allocator<unsigned_short>_>
            **)this != pbVar1) {
        operator_delete__(*(basic_string<unsigned_short,utl::char_traits<unsigned_short>,utl::allocator<unsigned_short>_>
                            **)this);
      }
      *(void **)this = _Dst;
      *(void **)(this + 8) = (void *)((longlong)_Dst + lVar3 * 2);
      bVar5 = true;
      *(__uint64 *)pbVar1 = (_Var2 - 2) + (longlong)_Dst;
    }
  }
  return bVar5;
}



===== append @ 180008438 =====

/* public: bool __cdecl utl::basic_string<unsigned short,struct utl::char_traits<unsigned
   short>,class utl::allocator<unsigned short> >::append(unsigned short const * __ptr64,unsigned
   __int64) __ptr64 */

bool __thiscall
utl::basic_string<unsigned_short,utl::char_traits<unsigned_short>,utl::allocator<unsigned_short>_>::
append(basic_string<unsigned_short,utl::char_traits<unsigned_short>,utl::allocator<unsigned_short>_>
       *this,ushort *param_1,__uint64 param_2)

{
  basic_string<unsigned_short,utl::char_traits<unsigned_short>,utl::allocator<unsigned_short>_>
  *pbVar1;
  ulonglong uVar2;
  undefined2 *puVar3;
  basic_string<unsigned_short,utl::char_traits<unsigned_short>,utl::allocator<unsigned_short>_>
  *pbVar4;
  size_t _Size;
  longlong lVar5;
  void *_Dst;
  ulonglong uVar6;
  longlong lVar7;
  ulonglong uVar8;
  
  pbVar4 = *(basic_string<unsigned_short,utl::char_traits<unsigned_short>,utl::allocator<unsigned_short>_>
             **)this;
  lVar7 = (longlong)*(void **)(this + 8) - (longlong)pbVar4 >> 1;
  uVar2 = lVar7 + param_2;
  if (param_2 <= uVar2) {
    pbVar1 = this + 0x10;
    lVar5 = 7;
    if (pbVar4 == pbVar1) {
      uVar6 = 7;
    }
    else {
      uVar6 = *(longlong *)pbVar1 - (longlong)pbVar4 >> 1;
    }
    if (uVar2 <= uVar6) {
      memmove(*(void **)(this + 8),param_1,param_2 * 2);
      *(__uint64 *)(this + 8) = *(longlong *)(this + 8) + param_2 * 2;
      **(undefined2 **)(this + 8) = 0;
      return true;
    }
    if (pbVar4 != pbVar1) {
      lVar5 = *(longlong *)pbVar1 - (longlong)pbVar4 >> 1;
    }
    uVar6 = lVar5 * 2 + 1;
    uVar8 = uVar2;
    if (uVar2 <= uVar6) {
      uVar8 = uVar6;
    }
    if (uVar8 < 0x3ffffffffffffff8) {
      uVar8 = uVar8 + 1;
      if (0x7fffffffffffffff < uVar8) {
        return false;
      }
    }
    else {
      if (0x3ffffffffffffff7 < uVar2) {
        return false;
      }
      uVar8 = 0x3ffffffffffffff8;
    }
    _Dst = operator_new__(uVar8 * 2,(nothrow_t *)param_1);
    if (_Dst != (void *)0x0) {
      _Size = lVar7 * 2;
      memmove(_Dst,*(void **)this,_Size);
      memmove((void *)(_Size + (longlong)_Dst),param_1,param_2 * 2);
      puVar3 = (undefined2 *)((longlong)_Dst + uVar2 * 2);
      *puVar3 = 0;
      if (*(basic_string<unsigned_short,utl::char_traits<unsigned_short>,utl::allocator<unsigned_short>_>
            **)this != pbVar1) {
        operator_delete__(*(basic_string<unsigned_short,utl::char_traits<unsigned_short>,utl::allocator<unsigned_short>_>
                            **)this);
      }
      *(void **)this = _Dst;
      *(undefined2 **)(this + 8) = puVar3;
      *(void **)pbVar1 = (void *)((longlong)_Dst + (uVar8 - 1) * 2);
      return true;
    }
  }
  return false;
}



===== DecryptCBC @ 1800085a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* struct Kerb3961::ReturnType<struct Kerb3961::StatusOnly,&struct Kerb3961::ResultBlock const &
   __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly
   const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly & __ptr64)> __cdecl Kerb3961::DecryptCBC(void
   * __ptr64,unsigned __int64,struct Kerb3961::ReadOnlyBinary const & __ptr64,struct
   Kerb3961::MutableBinary const & __ptr64,struct Kerb3961::MutableBinary const & __ptr64) */

void * __cdecl
Kerb3961::DecryptCBC
          (void *param_1,__uint64 param_2,ReadOnlyBinary *param_3,MutableBinary *param_4,
          MutableBinary *param_5)

{
  ulonglong *puVar1;
  NTSTATUS NVar2;
  char *pcVar3;
  BCRYPT_KEY_HANDLE local_res8;
  ULONG UStack0000000000000030;
  undefined4 in_stack_00000034;
  
  puVar1 = (ulonglong *)CONCAT44(in_stack_00000034,UStack0000000000000030);
  if (0xffffffff < *puVar1) {
    pcVar3 = 
    "static_cast<size_t>(data.length) <= static_cast<size_t>(utl::numeric_limits<uint32_t>::max())";
LAB_1800085d7:
    Logging::Verify::ConditionFailed(pcVar3);
    *(undefined4 *)param_1 = 0xc0000095;
    return param_1;
  }
  if (0xffffffff < *(ulonglong *)param_4) {
    pcVar3 = 
    "static_cast<size_t>(key.length) <= static_cast<size_t>(utl::numeric_limits<uint32_t>::max())";
    goto LAB_1800085d7;
  }
  if (*(ReadOnlyBinary **)param_5 != param_3) {
    pcVar3 = "IV.length == blockSize";
LAB_180008609:
    Logging::Verify::ConditionFailed(pcVar3);
    *(undefined4 *)param_1 = 0xc000000d;
    return param_1;
  }
  if (*puVar1 % (ulonglong)param_3 != 0) {
    pcVar3 = "data.length % blockSize == 0";
    goto LAB_180008609;
  }
  local_res8 = (BCRYPT_KEY_HANDLE)0x0;
  NVar2 = BCryptGenerateSymmetricKey
                    ((BCRYPT_ALG_HANDLE)param_2,&local_res8,(PUCHAR)0x0,0,*(PUCHAR *)(param_4 + 8),
                     *(ULONG *)param_4,0);
  if (NVar2 < 0) {
    pcVar3 = 
    "BCryptGenerateSymmetricKey(cipherCBC, &keyHandle, nullptr, 0, const_cast<uint8_t*>(key.buffer), static_cast<uint32_t>(key.length), 0)"
    ;
  }
  else {
    UStack0000000000000030 = 0;
    NVar2 = BCryptDecrypt(local_res8,(PUCHAR)puVar1[1],(ULONG)*puVar1,(void *)0x0,
                          *(PUCHAR *)(param_5 + 8),*(ULONG *)param_5,(PUCHAR)puVar1[1],
                          (ULONG)*puVar1,&UStack0000000000000030,0);
    if (-1 < NVar2) {
      *(undefined4 *)param_1 = 0;
      goto LAB_1800086d9;
    }
    pcVar3 = 
    "direction.BCrypt(keyHandle.get(), data.buffer, static_cast<uint32_t>(data.length), nullptr, IV.buffer, static_cast<uint32_t>(IV.length), data.buffer, static_cast<uint32_t>(data.length), &returnLength, 0)"
    ;
  }
  Logging::Verify::StatusFailed(pcVar3,NVar2);
  *(NTSTATUS *)param_1 = NVar2;
LAB_1800086d9:
  if (local_res8 == (BCRYPT_KEY_HANDLE)0x0) {
    return param_1;
  }
  BCryptDestroyKey(local_res8);
  return param_1;
}



===== DecryptCTS @ 180008710 =====

/* struct Kerb3961::ReturnType<struct Kerb3961::StatusOnly,&struct Kerb3961::ResultBlock const &
   __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly
   const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly & __ptr64)> __cdecl Kerb3961::DecryptCTS(void
   * __ptr64,unsigned __int64,struct Kerb3961::ReadOnlyBinary const & __ptr64,struct
   Kerb3961::MutableBinary const & __ptr64,struct Kerb3961::MutableBinary const & __ptr64) */

void * __cdecl
Kerb3961::DecryptCTS
          (void *param_1,__uint64 param_2,ReadOnlyBinary *param_3,MutableBinary *param_4,
          MutableBinary *param_5)

{
  ulonglong uVar1;
  NTSTATUS NVar2;
  char *pcVar3;
  ReadOnlyBinary *local_res18;
  ulonglong *in_stack_00000030;
  
  uVar1 = *in_stack_00000030;
  local_res18 = param_3;
  if (uVar1 < 0x10) {
    Logging::Verify::ConditionFailed("data.length >= blockSize");
    *(undefined4 *)param_1 = 0xc0000023;
  }
  else {
    if (uVar1 < 0x100000000) {
      if (*(ulonglong *)param_4 < 0x100000000) {
        if (*(longlong *)param_5 != 0x10) {
          Logging::Verify::ConditionFailed("IV.length == blockSize");
          *(undefined4 *)param_1 = 0xc000000d;
          return param_1;
        }
        if (uVar1 == 0x10) {
          DecryptCBC(param_1,param_2,(ReadOnlyBinary *)0x10,param_4,param_5);
          return param_1;
        }
        local_res18 = (ReadOnlyBinary *)0x0;
        NVar2 = BCryptGenerateSymmetricKey
                          ((BCRYPT_ALG_HANDLE)param_2,&local_res18,(PUCHAR)0x0,0,
                           *(PUCHAR *)(param_4 + 8),*(ULONG *)param_4,0);
        if (NVar2 < 0) {
          Logging::Verify::StatusFailed
                    ("BCryptGenerateSymmetricKey(cipherCBC, &keyHandle, nullptr, 0, const_cast<uint8_t*>(key.buffer), static_cast<uint32_t>(key.length), 0)"
                     ,NVar2);
          *(NTSTATUS *)param_1 = NVar2;
        }
        else {
          DecryptCTSCore(param_1,(PUCHAR)0x10,local_res18,(ULONG *)param_5,
                         (longlong *)in_stack_00000030);
        }
        if (local_res18 == (ReadOnlyBinary *)0x0) {
          return param_1;
        }
        BCryptDestroyKey(local_res18);
        return param_1;
      }
      pcVar3 = 
      "static_cast<size_t>(key.length) <= static_cast<size_t>(utl::numeric_limits<uint32_t>::max())"
      ;
    }
    else {
      pcVar3 = 
      "static_cast<size_t>(data.length) <= static_cast<size_t>(utl::numeric_limits<uint32_t>::max())"
      ;
    }
    Logging::Verify::ConditionFailed(pcVar3);
    *(undefined4 *)param_1 = 0xc0000095;
  }
  return param_1;
}



===== DecryptCTSCore @ 180008860 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS *
Kerb3961::DecryptCTSCore
          (NTSTATUS *param_1,PUCHAR param_2,BCRYPT_KEY_HANDLE param_3,ULONG *param_4,
          longlong *param_5)

{
  BCRYPT_KEY_HANDLE hKey;
  long lVar1;
  ULONG *pUVar2;
  NTSTATUS NVar3;
  int iVar4;
  char *pcVar5;
  PUCHAR pUVar6;
  ulonglong uVar7;
  PUCHAR _Size;
  undefined1 auStackY_128 [32];
  ULONG local_d8 [2];
  BCRYPT_KEY_HANDLE local_d0;
  longlong local_c8;
  PUCHAR local_c0;
  PUCHAR local_b8;
  ulonglong local_a8;
  PUCHAR local_a0;
  int local_98;
  longlong *local_90;
  ULONG *local_88;
  undefined1 local_80 [16];
  ulonglong local_70;
  PUCHAR local_68;
  void *local_58;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStackY_128;
  local_90 = param_5;
  uVar7 = *param_5 - 1;
  uVar7 = uVar7 - uVar7 % (ulonglong)param_2;
  local_c8 = uVar7 - (longlong)param_2;
  _Size = (PUCHAR)(*param_5 - uVar7);
  local_d0 = param_3;
  local_c0 = param_2;
  local_b8 = _Size;
  local_88 = param_4;
  Split<3>(local_80,param_5,&local_c8);
  CopyBuffer((ReadOnlyBinary *)&local_a8);
  if (local_98 < 0) {
    pcVar5 = "finalBlockCopy";
    iVar4 = local_98;
LAB_1800088ef:
    Logging::Verify::StatusFailed(pcVar5,iVar4);
    *param_1 = iVar4;
  }
  else {
    local_d8[0] = 0;
    if (_Size == param_2) {
LAB_1800089d3:
      memmove(local_68,local_58,(size_t)_Size);
      pUVar2 = local_88;
      hKey = local_d0;
      iVar4 = BCryptDecrypt(local_d0,(PUCHAR)local_90[1],(ULONG)uVar7,(void *)0x0,
                            *(PUCHAR *)(local_88 + 2),*local_88,(PUCHAR)local_90[1],(ULONG)uVar7,
                            local_d8,0);
      if (-1 < iVar4) {
        if (local_d8[0] != uVar7) {
LAB_180008afa:
                    /* WARNING: Subroutine does not return */
          ConsistencyFail((ushort *)
                          L"Decrypted text shorter than expected.  DecryptCTS is only for use with CBC mode algorithm handles."
                         );
        }
        NVar3 = BCryptDecrypt(hKey,local_a0,(ULONG)local_a8,(void *)0x0,*(PUCHAR *)(pUVar2 + 2),
                              *pUVar2,local_a0,(ULONG)local_a8,local_d8,0);
        if (NVar3 < 0) {
          Logging::Verify::StatusFailed
                    ("BCryptDecrypt(key, finalBlockCopy.buffer, static_cast<uint32_t>(finalBlockCopy.length), nullptr, IV.buffer, static_cast<uint32_t>(IV.length), finalBlockCopy.buffer, static_cast<uint32_t>(finalBlockCopy.length), &returnLength, 0)"
                     ,NVar3);
          *param_1 = NVar3;
        }
        else {
          if (local_d8[0] != local_a8) goto LAB_180008afa;
          memmove(local_58,local_a0,(size_t)_Size);
          *param_1 = 0;
        }
        if (local_a0 == (PUCHAR)0x0) {
          return param_1;
        }
        goto LAB_180008ad1;
      }
      pcVar5 = 
      "BCryptDecrypt(key, data.buffer, static_cast<uint32_t>(nonFinalBlockSize), nullptr, IV.buffer, static_cast<uint32_t>(IV.length), data.buffer, static_cast<uint32_t>(nonFinalBlockSize), &returnLength, 0)"
      ;
      goto LAB_1800088ef;
    }
    MakeBuffer((__uint64)&local_c8);
    pUVar6 = local_c0;
    lVar1 = (long)local_b8;
    if ((long)local_b8 < 0) {
      Logging::Verify::StatusFailed("zeroIV",(long)local_b8);
      *param_1 = lVar1;
      pUVar6 = local_c0;
      if (local_c0 != (PUCHAR)0x0) {
LAB_180008948:
        operator_delete__(pUVar6);
      }
    }
    else {
      NVar3 = BCryptDecrypt(local_d0,local_68,(ULONG)local_70,(void *)0x0,local_c0,(ULONG)local_c8,
                            local_68,(ULONG)local_70,local_d8,0);
      if (-1 < NVar3) {
        if (local_d8[0] != local_70) goto LAB_180008afa;
        if (pUVar6 != (PUCHAR)0x0) {
          operator_delete__(pUVar6);
        }
        goto LAB_1800089d3;
      }
      Logging::Verify::StatusFailed
                ("BCryptDecrypt(key, finalBlock.buffer, static_cast<uint32_t>(finalBlock.length), nullptr, zeroIV.buffer, static_cast<uint32_t>(zeroIV.length), finalBlock.buffer, static_cast<uint32_t>(finalBlock.length), &returnLength, 0)"
                 ,NVar3);
      *param_1 = NVar3;
      if (pUVar6 != (PUCHAR)0x0) goto LAB_180008948;
    }
  }
  if (local_a0 == (PUCHAR)0x0) {
    return param_1;
  }
LAB_180008ad1:
  operator_delete__(local_a0);
  return param_1;
}



===== EncryptCBC @ 180008b10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* struct Kerb3961::ReturnType<struct Kerb3961::StatusOnly,&struct Kerb3961::ResultBlock const &
   __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly
   const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly & __ptr64)> __cdecl Kerb3961::EncryptCBC(void
   * __ptr64,unsigned __int64,struct Kerb3961::ReadOnlyBinary const & __ptr64,struct
   Kerb3961::MutableBinary const & __ptr64,struct Kerb3961::MutableBinary const & __ptr64) */

void * __cdecl
Kerb3961::EncryptCBC
          (void *param_1,__uint64 param_2,ReadOnlyBinary *param_3,MutableBinary *param_4,
          MutableBinary *param_5)

{
  ulonglong *puVar1;
  NTSTATUS NVar2;
  char *pcVar3;
  BCRYPT_KEY_HANDLE local_res8;
  ULONG UStack0000000000000030;
  undefined4 in_stack_00000034;
  
  puVar1 = (ulonglong *)CONCAT44(in_stack_00000034,UStack0000000000000030);
  if (0xffffffff < *puVar1) {
    pcVar3 = 
    "static_cast<size_t>(data.length) <= static_cast<size_t>(utl::numeric_limits<uint32_t>::max())";
LAB_180008b47:
    Logging::Verify::ConditionFailed(pcVar3);
    *(undefined4 *)param_1 = 0xc0000095;
    return param_1;
  }
  if (0xffffffff < *(ulonglong *)param_4) {
    pcVar3 = 
    "static_cast<size_t>(key.length) <= static_cast<size_t>(utl::numeric_limits<uint32_t>::max())";
    goto LAB_180008b47;
  }
  if (*(ReadOnlyBinary **)param_5 != param_3) {
    pcVar3 = "IV.length == blockSize";
LAB_180008b79:
    Logging::Verify::ConditionFailed(pcVar3);
    *(undefined4 *)param_1 = 0xc000000d;
    return param_1;
  }
  if (*puVar1 % (ulonglong)param_3 != 0) {
    pcVar3 = "data.length % blockSize == 0";
    goto LAB_180008b79;
  }
  local_res8 = (BCRYPT_KEY_HANDLE)0x0;
  NVar2 = BCryptGenerateSymmetricKey
                    ((BCRYPT_ALG_HANDLE)param_2,&local_res8,(PUCHAR)0x0,0,*(PUCHAR *)(param_4 + 8),
                     *(ULONG *)param_4,0);
  if (NVar2 < 0) {
    pcVar3 = 
    "BCryptGenerateSymmetricKey(cipherCBC, &keyHandle, nullptr, 0, const_cast<uint8_t*>(key.buffer), static_cast<uint32_t>(key.length), 0)"
    ;
  }
  else {
    UStack0000000000000030 = 0;
    NVar2 = BCryptEncrypt(local_res8,(PUCHAR)puVar1[1],(ULONG)*puVar1,(void *)0x0,
                          *(PUCHAR *)(param_5 + 8),*(ULONG *)param_5,(PUCHAR)puVar1[1],
                          (ULONG)*puVar1,&UStack0000000000000030,0);
    if (-1 < NVar2) {
      *(undefined4 *)param_1 = 0;
      goto LAB_180008c49;
    }
    pcVar3 = 
    "direction.BCrypt(keyHandle.get(), data.buffer, static_cast<uint32_t>(data.length), nullptr, IV.buffer, static_cast<uint32_t>(IV.length), data.buffer, static_cast<uint32_t>(data.length), &returnLength, 0)"
    ;
  }
  Logging::Verify::StatusFailed(pcVar3,NVar2);
  *(NTSTATUS *)param_1 = NVar2;
LAB_180008c49:
  if (local_res8 == (BCRYPT_KEY_HANDLE)0x0) {
    return param_1;
  }
  BCryptDestroyKey(local_res8);
  return param_1;
}



===== EncryptCTS @ 180008c80 =====

/* struct Kerb3961::ReturnType<struct Kerb3961::StatusOnly,&struct Kerb3961::ResultBlock const &
   __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly
   const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly & __ptr64)> __cdecl Kerb3961::EncryptCTS(void
   * __ptr64,unsigned __int64,struct Kerb3961::ReadOnlyBinary const & __ptr64,struct
   Kerb3961::MutableBinary const & __ptr64,struct Kerb3961::MutableBinary const & __ptr64) */

void * __cdecl
Kerb3961::EncryptCTS
          (void *param_1,__uint64 param_2,ReadOnlyBinary *param_3,MutableBinary *param_4,
          MutableBinary *param_5)

{
  ulonglong uVar1;
  NTSTATUS NVar2;
  char *pcVar3;
  ReadOnlyBinary *local_res18;
  ulonglong *in_stack_00000030;
  
  uVar1 = *in_stack_00000030;
  local_res18 = param_3;
  if (uVar1 < 0x10) {
    Logging::Verify::ConditionFailed("data.length >= blockSize");
    *(undefined4 *)param_1 = 0xc0000023;
  }
  else {
    if (uVar1 < 0x100000000) {
      if (*(ulonglong *)param_4 < 0x100000000) {
        if (*(longlong *)param_5 != 0x10) {
          Logging::Verify::ConditionFailed("IV.length == blockSize");
          *(undefined4 *)param_1 = 0xc000000d;
          return param_1;
        }
        if (uVar1 == 0x10) {
          EncryptCBC(param_1,param_2,(ReadOnlyBinary *)0x10,param_4,param_5);
          return param_1;
        }
        local_res18 = (ReadOnlyBinary *)0x0;
        NVar2 = BCryptGenerateSymmetricKey
                          ((BCRYPT_ALG_HANDLE)param_2,&local_res18,(PUCHAR)0x0,0,
                           *(PUCHAR *)(param_4 + 8),*(ULONG *)param_4,0);
        if (NVar2 < 0) {
          Logging::Verify::StatusFailed
                    ("BCryptGenerateSymmetricKey(cipherCBC, &keyHandle, nullptr, 0, const_cast<uint8_t*>(key.buffer), static_cast<uint32_t>(key.length), 0)"
                     ,NVar2);
          *(NTSTATUS *)param_1 = NVar2;
        }
        else {
          EncryptCTSCore(param_1,0x10,local_res18,(ULONG *)param_5,(longlong *)in_stack_00000030);
        }
        if (local_res18 == (ReadOnlyBinary *)0x0) {
          return param_1;
        }
        BCryptDestroyKey(local_res18);
        return param_1;
      }
      pcVar3 = 
      "static_cast<size_t>(key.length) <= static_cast<size_t>(utl::numeric_limits<uint32_t>::max())"
      ;
    }
    else {
      pcVar3 = 
      "static_cast<size_t>(data.length) <= static_cast<size_t>(utl::numeric_limits<uint32_t>::max())"
      ;
    }
    Logging::Verify::ConditionFailed(pcVar3);
    *(undefined4 *)param_1 = 0xc0000095;
  }
  return param_1;
}



===== EncryptCTSCore @ 180008dd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS *
Kerb3961::EncryptCTSCore
          (NTSTATUS *param_1,ulonglong param_2,BCRYPT_KEY_HANDLE param_3,ULONG *param_4,
          longlong *param_5)

{
  NTSTATUS NVar1;
  longlong lVar2;
  size_t _Size;
  undefined1 auStackY_138 [32];
  ULONG local_e8 [4];
  longlong local_d8;
  size_t local_d0;
  longlong local_c8;
  undefined1 local_b8 [8];
  PUCHAR local_b0;
  long local_a8;
  ULONG local_a0 [2];
  PUCHAR local_98;
  size_t local_90;
  void *local_88;
  undefined1 local_80 [24];
  void *local_68;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStackY_138;
  lVar2 = ((*param_5 - 1U) / param_2) * param_2;
  _Size = *param_5 - lVar2;
  local_d8 = lVar2;
  local_d0 = _Size;
  Split<2>(local_a0,param_5,&local_d8);
  local_e8[0] = 0;
  NVar1 = BCryptEncrypt(param_3,local_98,local_a0[0],(void *)0x0,*(PUCHAR *)(param_4 + 2),*param_4,
                        local_98,local_a0[0],local_e8,0);
  if (NVar1 < 0) {
    Logging::Verify::StatusFailed
              ("BCryptEncrypt(key, nonFinalBuffer.buffer, static_cast<uint32_t>(nonFinalBuffer.length), nullptr, IV.buffer, static_cast<uint32_t>(IV.length), nonFinalBuffer.buffer, static_cast<uint32_t>(nonFinalBuffer.length), &returnLength, 0)"
               ,NVar1);
    *param_1 = NVar1;
  }
  else {
    local_c8 = param_2 - _Size;
    local_d8 = lVar2 - param_2;
    local_d0 = _Size;
    Split<3>(local_80,local_a0,&local_d8);
    MakeBuffer((__uint64)local_b8);
    if (local_a8 < 0) {
      Logging::Verify::StatusFailed("finalBlock",local_a8);
      *param_1 = local_a8;
      if (local_b0 == (PUCHAR)0x0) {
        return param_1;
      }
    }
    else {
      memmove(local_b0,local_88,local_90);
      NVar1 = BCryptEncrypt(param_3,local_b0,(ULONG)param_2,(void *)0x0,*(PUCHAR *)(param_4 + 2),
                            *param_4,local_b0,(ULONG)param_2,local_e8,0);
      if (NVar1 < 0) {
        Logging::Verify::StatusFailed
                  ("BCryptEncrypt(key, finalBlock.buffer, static_cast<uint32_t>(blockSize), nullptr, IV.buffer, static_cast<uint32_t>(IV.length), finalBlock.buffer, static_cast<uint32_t>(blockSize), &returnLength, 0)"
                   ,NVar1);
        *param_1 = NVar1;
      }
      else {
        memmove(local_88,local_68,_Size);
        memmove(local_68,local_b0,param_2);
        *param_1 = 0;
      }
      if (local_b0 == (PUCHAR)0x0) {
        return param_1;
      }
    }
    operator_delete__(local_b0);
  }
  return param_1;
}



===== GetHashCommon @ 180008fc4 =====

/* struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct Kerb3961::ResultBlock const &
   __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::OwnedBinary,16>(struct
   Kerb3961::OwnedBinary const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)>
   __cdecl Kerb3961::GetHashCommon(void * __ptr64,struct Kerb3961::ReadOnlyBinary const &
   __ptr64,struct Kerb3961::ReadOnlyBinary const & __ptr64,unsigned __int64) */

void * __cdecl
Kerb3961::GetHashCommon
          (void *param_1,ReadOnlyBinary *param_2,ReadOnlyBinary *param_3,__uint64 param_4)

{
  NTSTATUS NVar1;
  long lVar2;
  char *pcVar3;
  UCHAR local_res20 [8];
  ulonglong in_stack_00000028;
  undefined8 in_stack_ffffffffffffff98;
  ULONG *pcbResult;
  undefined4 uVar4;
  ULONG local_48 [2];
  undefined8 local_40;
  void *local_38;
  int local_30;
  
  uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffff98 >> 0x20);
  if (0xffffffff < *(ulonglong *)param_4) {
    pcVar3 = 
    "static_cast<size_t>(data.length) <= static_cast<size_t>(utl::numeric_limits<uint32_t>::max())";
LAB_180008ff8:
    Logging::Verify::ConditionFailed(pcVar3);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)((longlong)param_1 + 8) = 0;
    *(undefined4 *)((longlong)param_1 + 0x10) = 0xc0000095;
    return param_1;
  }
  if (0xffffffff < *(ulonglong *)param_3) {
    pcVar3 = 
    "static_cast<size_t>(key.length) <= static_cast<size_t>(utl::numeric_limits<uint32_t>::max())";
    goto LAB_180008ff8;
  }
  if (0xffffffff < in_stack_00000028) {
    pcVar3 = 
    "static_cast<size_t>(expectedHashSize) <= static_cast<size_t>(utl::numeric_limits<uint32_t>::max())"
    ;
    goto LAB_180008ff8;
  }
  if (in_stack_00000028 == 0) {
    pcbResult = local_48;
    local_48[0] = 0;
    local_res20[0] = '\0';
    local_res20[1] = '\0';
    local_res20[2] = '\0';
    local_res20[3] = '\0';
    NVar1 = BCryptGetProperty(param_2,L"HashDigestLength",local_res20,4,pcbResult,0);
    uVar4 = (undefined4)((ulonglong)pcbResult >> 0x20);
    if (NVar1 < 0) {
      Logging::Verify::StatusFailed
                ("BCryptGetProperty(hashAlgorithm, BCRYPT_HASH_LENGTH, reinterpret_cast<PUCHAR>(&length), sizeof(length), &ignore, 0)"
                 ,NVar1);
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)((longlong)param_1 + 8) = 0;
      local_30 = NVar1;
      goto LAB_180009144;
    }
  }
  MakeBuffer((__uint64)&local_40);
  if (local_30 < 0) {
    Logging::Verify::StatusFailed("result",local_30);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)((longlong)param_1 + 8) = 0;
    *(int *)((longlong)param_1 + 0x10) = local_30;
    if (local_38 == (void *)0x0) {
      return param_1;
    }
  }
  else {
    lVar2 = BCryptHash(param_2,*(undefined8 *)(param_3 + 8),*(undefined4 *)param_3,
                       *(undefined8 *)(param_4 + 8),CONCAT44(uVar4,*(undefined4 *)param_4),local_38,
                       (int)local_40);
    if (-1 < lVar2) {
      *(undefined8 *)param_1 = local_40;
      *(void **)((longlong)param_1 + 8) = local_38;
LAB_180009144:
      *(int *)((longlong)param_1 + 0x10) = local_30;
      return param_1;
    }
    Logging::Verify::StatusFailed
              ("BCryptHash(hashAlgorithm, const_cast<uint8_t*>(key.buffer), static_cast<uint32_t>(key.length), const_cast<uint8_t*>(data.buffer), static_cast<uint32_t>(data.length), result.buffer, static_cast<uint32_t>(result.length))"
               ,lVar2);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)((longlong)param_1 + 8) = 0;
    *(long *)((longlong)param_1 + 0x10) = lVar2;
    if (local_38 == (void *)0x0) {
      return param_1;
    }
  }
  operator_delete__(local_38);
  return param_1;
}



===== GetHmac @ 18000916c =====

/* struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct Kerb3961::ResultBlock const &
   __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::OwnedBinary,16>(struct
   Kerb3961::OwnedBinary const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)>
   __cdecl Kerb3961::GetHmac(void * __ptr64,struct Kerb3961::ReadOnlyBinary const & __ptr64,struct
   Kerb3961::ReadOnlyBinary const & __ptr64,unsigned __int64) */

void * __cdecl
Kerb3961::GetHmac(void *param_1,ReadOnlyBinary *param_2,ReadOnlyBinary *param_3,__uint64 param_4)

{
  if (*(longlong *)param_3 == 0) {
    Logging::Verify::ConditionFailed("key.length > 0");
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)((longlong)param_1 + 8) = 0;
    *(undefined4 *)((longlong)param_1 + 0x10) = 0xc000000d;
  }
  else {
    GetHashCommon(param_1,param_2,param_3,param_4);
  }
  return param_1;
}



===== ~_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0> @ 1800091b8 =====

/* protected: __cdecl utl::_Tree<enum Kerb3961::KeyUsage const ,struct utl::pair<enum
   Kerb3961::KeyUsage const ,struct Kerb3961::KeyPolicyScenario const >,struct utl::less<enum
   Kerb3961::KeyUsage const >,class utl::allocator<struct utl::pair<enum Kerb3961::KeyUsage const
   ,struct Kerb3961::KeyPolicyScenario const > >,0>::~_Tree<enum Kerb3961::KeyUsage const ,struct
   utl::pair<enum Kerb3961::KeyUsage const ,struct Kerb3961::KeyPolicyScenario const >,struct
   utl::less<enum Kerb3961::KeyUsage const >,class utl::allocator<struct utl::pair<enum
   Kerb3961::KeyUsage const ,struct Kerb3961::KeyPolicyScenario const > >,0>(void) __ptr64 */

void __thiscall
utl::
_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
::
~_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
          (_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
           *this)

{
  _Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
  *p_Var1;
  _Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
  *p_Var2;
  
  p_Var2 = *(_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
             **)(this + 0x10);
  if (p_Var2 == this) {
    return;
  }
  do {
    while (*(_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
             **)(p_Var2 + 8) !=
           (_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
            *)&_TreeSentinel) {
      p_Var2 = *(_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
                 **)(p_Var2 + 8);
    }
    while (p_Var1 = p_Var2, *(void ***)(p_Var2 + 0x10) == &_TreeSentinel) {
      do {
        p_Var2 = (_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
                  *)((ulonglong)*(void **)p_Var1 & 0xfffffffffffffffe);
        operator_delete__(p_Var1);
        if (p_Var2 == this) {
          *(_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
            **)this = this;
          *(_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
            **)(this + 8) = this;
          *(_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
            **)(this + 0x10) = this;
          *(undefined8 *)(this + 0x18) = 0;
          return;
        }
        p_Var1 = p_Var2;
      } while (*(void ***)(p_Var2 + 8) == &_TreeSentinel);
      *(void ***)(p_Var2 + 8) = &_TreeSentinel;
    }
    p_Var2 = *(_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
               **)(p_Var2 + 0x10);
  } while( true );
}



===== GetScenarioForKeyUsage @ 18000923c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* class utl::optional<struct Kerb3961::KeyPolicyScenario> __cdecl
   Kerb3961::GetScenarioForKeyUsage(enum Kerb3961::KeyUsage) */

undefined4 * __cdecl Kerb3961::GetScenarioForKeyUsage(KeyUsage param_1)

{
  KeyUsageMap *pKVar1;
  undefined4 in_register_0000000c;
  undefined4 *puVar2;
  longlong lVar3;
  ulonglong in_RDX;
  KeyUsageMap *pKVar4;
  undefined4 local_res8;
  KeyUsageMap local_resc;
  undefined1 uStackX_d;
  
  puVar2 = (undefined4 *)CONCAT44(in_register_0000000c,param_1);
  if (DAT_180018290 != &g_keyUsageMap) {
    pKVar4 = &g_keyUsageMap;
    pKVar1 = _g_keyUsageMap;
    do {
      if (*(ulonglong *)(pKVar1 + 0x18) < in_RDX) {
        lVar3 = 0x10;
      }
      else {
        lVar3 = 8;
        pKVar4 = pKVar1;
      }
      pKVar1 = *(KeyUsageMap **)(pKVar1 + lVar3);
    } while (pKVar1 != (KeyUsageMap *)&utl::_TreeSentinel);
    if ((pKVar4 != &g_keyUsageMap) && (*(ulonglong *)(pKVar4 + 0x18) <= in_RDX)) {
      local_res8 = *(undefined4 *)(pKVar4 + 0x20);
      local_resc = pKVar4[0x24];
      uStackX_d = 1;
      goto LAB_1800092ae;
    }
  }
  local_resc = (KeyUsageMap)0x0;
  local_res8 = 0;
  uStackX_d = 0;
LAB_1800092ae:
  *puVar2 = local_res8;
  *(ushort *)(puVar2 + 1) = CONCAT11(uStackX_d,local_resc);
  return puVar2;
}



===== _FindInsertionPointUnique @ 1800092cc =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* private: struct utl::pair<struct utl::_TreeNode<struct utl::pair<enum Kerb3961::KeyUsage const
   ,struct Kerb3961::KeyPolicyScenario const > > * __ptr64,bool> __cdecl utl::_Tree<enum
   Kerb3961::KeyUsage const ,struct utl::pair<enum Kerb3961::KeyUsage const ,struct
   Kerb3961::KeyPolicyScenario const >,struct utl::less<enum Kerb3961::KeyUsage const >,class
   utl::allocator<struct utl::pair<enum Kerb3961::KeyUsage const ,struct Kerb3961::KeyPolicyScenario
   const > >,0>::_FindInsertionPointUnique(struct utl::_TreeNode<struct utl::pair<enum
   Kerb3961::KeyUsage const ,struct Kerb3961::KeyPolicyScenario const > > * __ptr64 & __ptr64,enum
   Kerb3961::KeyUsage const & __ptr64,struct utl::_TreeNode<struct utl::pair<enum Kerb3961::KeyUsage
   const ,struct Kerb3961::KeyPolicyScenario const > > * __ptr64) __ptr64 */

_TreeNode<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_> ** __thiscall
utl::
_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
::_FindInsertionPointUnique
          (_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
           *this,_TreeNode<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>
                 **param_1,KeyUsage *param_2,
          _TreeNode<struct_utl::pair<enum_Kerb3961::KeyUsage_const_,struct_Kerb3961::KeyPolicyScenario_const_>_>
          *param_3)

{
  void **ppvVar1;
  undefined8 uVar2;
  code *pcVar3;
  KeyUsageMap *pKVar4;
  KeyUsageMap *pKVar5;
  KeyUsageMap *pKVar6;
  _TreeNode<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_> *p_Var7;
  void *pvVar8;
  void *pvVar9;
  bool bVar10;
  KeyUsageMap *in_stack_00000028;
  
  p_Var7 = DAT_180018288;
  if (in_stack_00000028 == &Kerb3961::g_keyUsageMap) {
    pvVar8 = *(void **)param_3;
    if (*(void **)(DAT_180018288 + 0x18) < pvVar8) {
      param_2[0] = 0;
      param_2[1] = 0;
      *param_1 = p_Var7;
      *(undefined1 *)(param_1 + 1) = 1;
      return param_1;
    }
  }
  else {
    pvVar8 = *(void **)param_3;
    if (pvVar8 < *(void **)(in_stack_00000028 + 0x18)) {
      if (in_stack_00000028 == DAT_180018290) {
        *param_1 = (_TreeNode<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>
                    *)DAT_180018290;
        *(undefined1 *)(param_1 + 1) = 0;
        goto LAB_18000940c;
      }
      pKVar5 = *(KeyUsageMap **)(in_stack_00000028 + 8);
      pvVar9 = pvVar8;
      if (pKVar5 == (KeyUsageMap *)&_TreeSentinel) {
        pKVar4 = (KeyUsageMap *)(*(ulonglong *)in_stack_00000028 & 0xfffffffffffffffe);
        pKVar5 = pKVar4;
        if ((((*(KeyUsageMap **)(pKVar4 + 8) == in_stack_00000028) &&
             (*(KeyUsageMap **)pKVar4 != in_stack_00000028)) &&
            (pKVar5 = (KeyUsageMap *)((ulonglong)*(KeyUsageMap **)pKVar4 & 0xfffffffffffffffe),
            *(KeyUsageMap **)(pKVar5 + 8) == pKVar4)) &&
           (pKVar6 = pKVar5, *(KeyUsageMap **)pKVar5 != pKVar4)) {
          do {
            pKVar5 = (KeyUsageMap *)(*(ulonglong *)pKVar6 & 0xfffffffffffffffe);
            bVar10 = *(KeyUsageMap **)(pKVar5 + 8) == pKVar6;
            pKVar6 = pKVar5;
          } while (bVar10);
        }
      }
      else {
        if (in_stack_00000028 == pKVar5) {
          pcVar3 = (code *)swi(0x2c);
          (*pcVar3)();
        }
        pKVar4 = *(KeyUsageMap **)(pKVar5 + 0x10);
        while (pKVar6 = pKVar4, pKVar6 != (KeyUsageMap *)&_TreeSentinel) {
          pKVar5 = pKVar6;
          pKVar4 = *(KeyUsageMap **)(pKVar6 + 0x10);
        }
      }
      if (*(void **)(pKVar5 + 0x18) < pvVar9) {
        param_2[0] = 0;
        param_2[1] = 0;
        ppvVar1 = *(void ***)(pKVar5 + 0x10);
        if (ppvVar1 != &_TreeSentinel) {
          pKVar5 = in_stack_00000028;
        }
        *param_1 = (_TreeNode<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>
                    *)pKVar5;
        *(bool *)(param_1 + 1) = ppvVar1 == &_TreeSentinel;
        return param_1;
      }
    }
  }
  p_Var7 = _g_keyUsageMap;
  param_2[0] = 0;
  param_2[1] = 0;
  do {
    bVar10 = *(void **)(p_Var7 + 0x18) <= pvVar8;
    if (bVar10) {
      *(_TreeNode<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_> **)
       param_2 = p_Var7;
    }
    *param_1 = p_Var7;
    p_Var7 = *(_TreeNode<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>
               **)(p_Var7 + (ulonglong)bVar10 * 8 + 8);
  } while (p_Var7 != (_TreeNode<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>
                      *)&_TreeSentinel);
  uVar2 = *(undefined8 *)param_2;
  *(bool *)(param_1 + 1) = bVar10;
  if (uVar2 == 0) {
    return param_1;
  }
  if (*(ulonglong *)param_3 <= *(ulonglong *)(uVar2 + 0x18)) {
    return param_1;
  }
LAB_18000940c:
  param_2[0] = 0;
  param_2[1] = 0;
  return param_1;
}



===== _InsertAt @ 18000942c =====

/* private: void __cdecl utl::_Tree<enum Kerb3961::KeyUsage const ,struct utl::pair<enum
   Kerb3961::KeyUsage const ,struct Kerb3961::KeyPolicyScenario const >,struct utl::less<enum
   Kerb3961::KeyUsage const >,class utl::allocator<struct utl::pair<enum Kerb3961::KeyUsage const
   ,struct Kerb3961::KeyPolicyScenario const > >,0>::_InsertAt(struct utl::pair<struct
   utl::_TreeNode<struct utl::pair<enum Kerb3961::KeyUsage const ,struct Kerb3961::KeyPolicyScenario
   const > > * __ptr64,bool> const & __ptr64,struct utl::_TreeNode<struct utl::pair<enum
   Kerb3961::KeyUsage const ,struct Kerb3961::KeyPolicyScenario const > > * __ptr64) __ptr64 */

void __thiscall
utl::
_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
::_InsertAt(_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
            *this,pair<utl::_TreeNode<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>*___ptr64,bool>
                  *param_1,
           _TreeNode<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>
           *param_2)

{
  pair<utl::_TreeNode<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>*___ptr64,bool>
  pVar1;
  KeyUsageMap *pKVar2;
  byte *pbVar3;
  ulonglong *puVar4;
  ulonglong *puVar5;
  ulonglong uVar6;
  longlong lVar7;
  ulonglong *puVar8;
  ulonglong *puVar9;
  ulonglong uVar10;
  KeyUsageMap *pKVar11;
  ulonglong uVar12;
  longlong lVar13;
  
  pKVar11 = *(KeyUsageMap **)param_1;
  pVar1 = param_1[8];
  *(KeyUsageMap **)param_2 = pKVar11;
  lVar13 = 8;
  *(void ***)(param_2 + 8) = &_TreeSentinel;
  *(void ***)(param_2 + 0x10) = &_TreeSentinel;
  *(_TreeNode<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_> **)
   (pKVar11 + ((ulonglong)(byte)pVar1 + 1) * 8) = param_2;
  uVar6 = ~-(ulonglong)
            (pVar1 != (pair<utl::_TreeNode<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>*___ptr64,bool>
                       )0x0) & 8;
  if (*(KeyUsageMap **)((longlong)&DAT_180018288 + uVar6) == pKVar11) {
    *(_TreeNode<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_> **)
     ((longlong)&DAT_180018288 + uVar6) = param_2;
  }
  do {
    uVar6 = *(ulonglong *)pKVar11;
    if ((uVar6 & 1) != 0) {
LAB_180009588:
      DAT_180018298 = DAT_180018298 + 1;
      return;
    }
    puVar9 = (ulonglong *)(uVar6 & 0xfffffffffffffffe);
    pKVar2 = (KeyUsageMap *)puVar9[2];
    uVar12 = (ulonglong)(pKVar2 != pKVar11);
    if ((*(byte *)puVar9[uVar12 + 1] & 1) != 0) {
      pbVar3 = *(byte **)(pKVar11 + (uVar12 + 1) * 8);
      if ((*pbVar3 & 1) == 0) {
        lVar7 = 8;
        uVar10 = (ulonglong)(pKVar2 == pKVar11);
        puVar4 = *(ulonglong **)(pbVar3 + uVar10 * 8 + 8);
        *(ulonglong **)pbVar3 = puVar9;
        if ((KeyUsageMap *)puVar9[2] == pKVar11) {
          lVar7 = 0x10;
        }
        *(byte **)(lVar7 + (longlong)puVar9) = pbVar3;
        *(byte **)pKVar11 = pbVar3;
        *puVar4 = (ulonglong)((uint)*puVar4 & 1) | (ulonglong)pKVar11;
        *(ulonglong **)(pKVar11 + ((uVar10 ^ 1) + 1) * 8) = puVar4;
        *(KeyUsageMap **)(pbVar3 + uVar10 * 8 + 8) = pKVar11;
      }
      else {
        uVar10 = (ulonglong)(pKVar2 == pKVar11);
      }
      puVar4 = (ulonglong *)puVar9[uVar10 + 1];
      puVar8 = (ulonglong *)(*puVar9 & 0xfffffffffffffffe);
      puVar5 = (ulonglong *)puVar4[uVar12 + 1];
      *puVar4 = (ulonglong)puVar8 | 1;
      if ((ulonglong *)(*puVar8 & 0xfffffffffffffffe) == puVar9) {
        *puVar8 = (ulonglong)puVar4;
      }
      else {
        if ((ulonglong *)puVar8[2] == puVar9) {
          lVar13 = 0x10;
        }
        *(ulonglong **)(lVar13 + (longlong)puVar8) = puVar4;
      }
      *puVar9 = (ulonglong)puVar4;
      *puVar5 = (*puVar5 ^ uVar6) & 0xfffffffffffffffe ^ *puVar5;
      puVar9[(uVar12 ^ 1) + 1] = (ulonglong)puVar5;
      puVar4[uVar12 + 1] = (ulonglong)puVar9;
      goto LAB_180009588;
    }
    *(ulonglong *)puVar9[1] = *(ulonglong *)puVar9[1] | 1;
    *(ulonglong *)puVar9[2] = *(ulonglong *)puVar9[2] | 1;
    pKVar11 = (KeyUsageMap *)(*puVar9 & 0xfffffffffffffffe);
    if (pKVar11 == &Kerb3961::g_keyUsageMap) goto LAB_180009588;
    *puVar9 = (ulonglong)pKVar11;
  } while( true );
}



===== try_emplace<unsigned___int64_const&___ptr64,unsigned_char_const*___ptr64,0> @ 1800095ac =====

/* public: struct utl::pair<class utl::_TreeIt<struct utl::pair<unsigned int const ,struct
   Kerb3961::ReadOnlyBinary> >,bool> __cdecl utl::map<unsigned int,struct
   Kerb3961::ReadOnlyBinary,struct utl::less<unsigned int>,class utl::allocator<struct
   utl::pair<unsigned int const ,struct Kerb3961::ReadOnlyBinary> > >::try_emplace<unsigned __int64
   const & __ptr64,unsigned char const * __ptr64,0>(unsigned int const & __ptr64,unsigned __int64
   const & __ptr64,unsigned char const * __ptr64 && __ptr64) __ptr64 */

uint * __thiscall
utl::
map<unsigned_int,Kerb3961::ReadOnlyBinary,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>_>_>
::try_emplace<unsigned___int64_const&___ptr64,unsigned_char_const*___ptr64,0>
          (map<unsigned_int,Kerb3961::ReadOnlyBinary,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>_>_>
           *this,uint *param_1,__uint64 *param_2,uchar **param_3)

{
  ulonglong uVar1;
  void **ppvVar2;
  ulonglong *puVar3;
  _TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>_> *p_Var4;
  void **ppvVar5;
  bool bVar6;
  ulonglong *in_stack_00000028;
  void **local_28;
  bool bStack_20;
  undefined7 uStack_1f;
  
  param_1[0] = 0;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  if (*(map<unsigned_int,Kerb3961::ReadOnlyBinary,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>_>_>
        **)(this + 0x10) == this) {
    puVar3 = operator_new__(0x30,(nothrow_t *)param_1);
    if (puVar3 != (ulonglong *)0x0) {
      *(int *)(puVar3 + 3) = (int)*param_2;
      uVar1 = *in_stack_00000028;
      puVar3[4] = (ulonglong)*param_3;
      puVar3[5] = uVar1;
      *puVar3 = (ulonglong)this | 1;
      puVar3[1] = (ulonglong)&_TreeSentinel;
      puVar3[2] = (ulonglong)&_TreeSentinel;
      *(ulonglong **)this = puVar3;
      *(ulonglong **)(this + 8) = puVar3;
      *(ulonglong **)(this + 0x10) = puVar3;
      *(longlong *)(this + 0x18) = *(longlong *)(this + 0x18) + 1;
    }
    *(ulonglong **)param_1 = puVar3;
    *(bool *)(param_1 + 2) = puVar3 != (ulonglong *)0x0;
  }
  else {
    ppvVar5 = (void **)0x0;
    ppvVar2 = *(void ***)this;
    do {
      local_28 = ppvVar2;
      bVar6 = *(uint *)(local_28 + 3) <= (uint)*param_2;
      if (bVar6) {
        ppvVar5 = local_28;
      }
      _bStack_20 = CONCAT71(uStack_1f,bVar6);
      ppvVar2 = local_28[(ulonglong)bVar6 + 1];
    } while (local_28[(ulonglong)bVar6 + 1] != &_TreeSentinel);
    if (((ppvVar5 == (void **)0x0) || ((uint)*param_2 <= *(uint *)(ppvVar5 + 3))) &&
       (ppvVar5 != (void **)0x0)) {
      *(void ***)param_1 = ppvVar5;
    }
    else {
      p_Var4 = operator_new__(0x30,(nothrow_t *)&_TreeSentinel);
      if (p_Var4 == (_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>_> *)0x0) {
        *(undefined1 *)(param_1 + 2) = 0;
      }
      else {
        *(int *)(p_Var4 + 0x18) = (int)*param_2;
        uVar1 = *in_stack_00000028;
        *(uchar **)(p_Var4 + 0x20) = *param_3;
        *(ulonglong *)(p_Var4 + 0x28) = uVar1;
        _Tree<unsigned_int,utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>_>,0>
        ::_InsertAt((_Tree<unsigned_int,utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>_>,0>
                     *)this,(pair<utl::_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>_>*___ptr64,bool>
                             *)&local_28,p_Var4);
        *(undefined1 *)(param_1 + 2) = 1;
      }
      *(_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>_> **)param_1 = p_Var4;
    }
  }
  return param_1;
}



===== AddPolicy @ 18000971c =====

/* private: struct Kerb3961::ReturnType<struct Kerb3961::StatusOnly,&struct Kerb3961::ResultBlock
   const & __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::StatusOnly,0>(struct
   Kerb3961::StatusOnly const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly & __ptr64)>
   __cdecl Kerb3961::MarshaledPolicyBuilder::AddPolicy(enum Kerb3961::MarshaledPolicyType,unsigned
   int,struct Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64 */

long * __thiscall
Kerb3961::MarshaledPolicyBuilder::AddPolicy
          (MarshaledPolicyBuilder *this,MarshaledPolicyType param_1,uint param_2,
          ReadOnlyBinary *param_3)

{
  size_t sVar1;
  undefined8 *puVar2;
  bool bVar3;
  ulonglong uVar4;
  undefined4 in_register_00000014;
  long *plVar5;
  __uint64 _Var6;
  size_t *in_stack_00000028;
  undefined8 local_48;
  uint *local_40;
  long local_38;
  
  plVar5 = (long *)CONCAT44(in_register_00000014,param_1);
  sVar1 = *in_stack_00000028;
  MakeBuffer((__uint64)&local_48);
  if (local_38 < 0) {
    Logging::Verify::StatusFailed("buffer",local_38);
    *plVar5 = local_38;
    if (local_40 == (uint *)0x0) {
      return plVar5;
    }
LAB_18000978d:
    operator_delete__(local_40);
    return plVar5;
  }
  *local_40 = param_2;
  local_40[1] = (uint)param_3;
  *(size_t *)(local_40 + 2) = *in_stack_00000028;
  *(size_t *)(local_40 + 4) = (sVar1 + 0x17 & 0xfffffffffffffff8) + 8;
  memmove(local_40 + 6,(void *)in_stack_00000028[1],*in_stack_00000028);
  if (*(longlong *)(this + 8) == *(longlong *)(this + 0x10)) {
    uVar4 = (*(longlong *)(this + 0x10) - *(longlong *)this >> 3) * -0x5555555555555555;
    _Var6 = (uVar4 >> 2) * 7 + 8;
    if (0x555555555555555 < _Var6) {
      _Var6 = 0x555555555555555;
    }
    if ((_Var6 <= uVar4) ||
       (bVar3 = utl::
                vector<Kerb3961::ReturnType<Kerb3961::OwnedBinary,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary&___ptr64)>,utl::allocator<Kerb3961::ReturnType<Kerb3961::OwnedBinary,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary&___ptr64)>_>_>
                ::_SetCapacity((vector<Kerb3961::ReturnType<Kerb3961::OwnedBinary,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary&___ptr64)>,utl::allocator<Kerb3961::ReturnType<Kerb3961::OwnedBinary,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary&___ptr64)>_>_>
                                *)this,_Var6), !bVar3)) {
      Logging::Verify::ConditionFailed("m_components.emplace_back(utl::move(buffer))");
      *plVar5 = -0x3fffffe9;
      goto LAB_18000978d;
    }
  }
  puVar2 = *(undefined8 **)(this + 8);
  *(long *)(puVar2 + 2) = local_38;
  *puVar2 = local_48;
  puVar2[1] = local_40;
  *(longlong *)(this + 8) = *(longlong *)(this + 8) + 0x18;
  *plVar5 = 0;
  return plVar5;
}



===== _InsertAt @ 18000986c =====

/* private: void __cdecl utl::_Tree<unsigned int,struct utl::pair<unsigned int const ,struct
   Kerb3961::ReadOnlyBinary>,struct utl::less<unsigned int>,class utl::allocator<struct
   utl::pair<unsigned int const ,struct Kerb3961::ReadOnlyBinary> >,0>::_InsertAt(struct
   utl::pair<struct utl::_TreeNode<struct utl::pair<unsigned int const ,struct
   Kerb3961::ReadOnlyBinary> > * __ptr64,bool> const & __ptr64,struct utl::_TreeNode<struct
   utl::pair<unsigned int const ,struct Kerb3961::ReadOnlyBinary> > * __ptr64) __ptr64 */

void __thiscall
utl::
_Tree<unsigned_int,utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>_>,0>
::_InsertAt(_Tree<unsigned_int,utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>_>,0>
            *this,pair<utl::_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>_>*___ptr64,bool>
                  *param_1,
           _TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>_> *param_2)

{
  pair<utl::_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>_>*___ptr64,bool> pVar1
  ;
  ulonglong uVar2;
  _Tree<unsigned_int,utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>_>,0>
  *p_Var3;
  byte *pbVar4;
  ulonglong *puVar5;
  ulonglong *puVar6;
  longlong lVar7;
  longlong lVar8;
  ulonglong *puVar9;
  ulonglong *puVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  _Tree<unsigned_int,utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>_>,0>
  *p_Var13;
  
  p_Var13 = *(_Tree<unsigned_int,utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>_>,0>
              **)param_1;
  pVar1 = param_1[8];
  *(_Tree<unsigned_int,utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>_>,0>
    **)param_2 = p_Var13;
  *(void ***)(param_2 + 8) = &_TreeSentinel;
  *(void ***)(param_2 + 0x10) = &_TreeSentinel;
  *(_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>_> **)
   (p_Var13 + (ulonglong)(byte)pVar1 * 8 + 8) = param_2;
  lVar7 = (-(ulonglong)
            (pVar1 != (pair<utl::_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>_>*___ptr64,bool>
                       )0x0) & 0xfffffffffffffff8) + 0x10;
  if (*(_Tree<unsigned_int,utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>_>,0>
        **)(this + lVar7) == p_Var13) {
    *(_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>_> **)(this + lVar7) =
         param_2;
  }
  do {
    uVar2 = *(ulonglong *)p_Var13;
    if ((uVar2 & 1) != 0) {
LAB_1800099c6:
      *(longlong *)(this + 0x18) = *(longlong *)(this + 0x18) + 1;
      return;
    }
    puVar10 = (ulonglong *)(uVar2 & 0xfffffffffffffffe);
    p_Var3 = (_Tree<unsigned_int,utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>_>,0>
              *)puVar10[2];
    uVar12 = (ulonglong)(p_Var3 != p_Var13);
    if ((*(byte *)puVar10[uVar12 + 1] & 1) != 0) {
      pbVar4 = *(byte **)(p_Var13 + uVar12 * 8 + 8);
      lVar7 = 8;
      if ((*pbVar4 & 1) == 0) {
        lVar8 = 8;
        uVar11 = (ulonglong)(p_Var3 == p_Var13);
        puVar5 = *(ulonglong **)(pbVar4 + uVar11 * 8 + 8);
        *(ulonglong **)pbVar4 = puVar10;
        if ((_Tree<unsigned_int,utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>_>,0>
             *)puVar10[2] == p_Var13) {
          lVar8 = 0x10;
        }
        *(byte **)(lVar8 + (longlong)puVar10) = pbVar4;
        *(byte **)p_Var13 = pbVar4;
        *puVar5 = (ulonglong)((uint)*puVar5 & 1) | (ulonglong)p_Var13;
        *(ulonglong **)(p_Var13 + (uVar11 ^ 1) * 8 + 8) = puVar5;
        *(_Tree<unsigned_int,utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>_>,0>
          **)(pbVar4 + uVar11 * 8 + 8) = p_Var13;
      }
      else {
        uVar11 = (ulonglong)(p_Var3 == p_Var13);
      }
      puVar5 = (ulonglong *)puVar10[uVar11 + 1];
      puVar9 = (ulonglong *)(*puVar10 & 0xfffffffffffffffe);
      puVar6 = (ulonglong *)puVar5[uVar12 + 1];
      *puVar5 = (ulonglong)puVar9 | 1;
      if ((ulonglong *)(*puVar9 & 0xfffffffffffffffe) == puVar10) {
        *puVar9 = (ulonglong)puVar5;
      }
      else {
        if ((ulonglong *)puVar9[2] == puVar10) {
          lVar7 = 0x10;
        }
        *(ulonglong **)(lVar7 + (longlong)puVar9) = puVar5;
      }
      *puVar10 = (ulonglong)puVar5;
      *puVar6 = (*puVar6 ^ uVar2) & 0xfffffffffffffffe ^ *puVar6;
      puVar10[(uVar12 ^ 1) + 1] = (ulonglong)puVar6;
      puVar5[uVar12 + 1] = (ulonglong)puVar10;
      goto LAB_1800099c6;
    }
    *(ulonglong *)puVar10[1] = *(ulonglong *)puVar10[1] | 1;
    *(ulonglong *)puVar10[2] = *(ulonglong *)puVar10[2] | 1;
    p_Var13 = (_Tree<unsigned_int,utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>_>,0>
               *)(*puVar10 & 0xfffffffffffffffe);
    if (this == p_Var13) goto LAB_1800099c6;
    *puVar10 = (ulonglong)p_Var13;
  } while( true );
}



===== _SetCapacity @ 1800099e8 =====

/* private: bool __cdecl utl::vector<struct Kerb3961::ReturnType<struct
   Kerb3961::OwnedBinary,&struct Kerb3961::ResultBlock const & __ptr64 __cdecl
   Kerb3961::SingleGetter<struct Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const &
   __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)>,class utl::allocator<struct
   Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct Kerb3961::ResultBlock const & __ptr64
   __cdecl Kerb3961::SingleGetter<struct Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary
   const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> > >::_SetCapacity(unsigned
   __int64) __ptr64 */

bool __thiscall
utl::
vector<Kerb3961::ReturnType<Kerb3961::OwnedBinary,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary&___ptr64)>,utl::allocator<Kerb3961::ReturnType<Kerb3961::OwnedBinary,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary&___ptr64)>_>_>
::_SetCapacity(vector<Kerb3961::ReturnType<Kerb3961::OwnedBinary,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary&___ptr64)>,utl::allocator<Kerb3961::ReturnType<Kerb3961::OwnedBinary,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary&___ptr64)>_>_>
               *this,__uint64 param_1)

{
  void *pvVar1;
  void *pvVar2;
  void *pvVar3;
  bool bVar4;
  longlong lVar5;
  undefined4 *puVar6;
  bool bVar7;
  longlong lVar8;
  void *local_28;
  void *pvStack_20;
  void *local_18;
  
  bVar7 = false;
  if (param_1 < 0xaaaaaaaaaaaaaab) {
    local_28 = operator_new__(param_1 * 0x18,(nothrow_t *)param_1);
  }
  else {
    local_28 = (void *)0x0;
  }
  pvVar3 = local_28;
  bVar4 = false;
  if (local_28 != (void *)0x0) {
    pvVar1 = (void *)(param_1 * 0x18 + (longlong)local_28);
    pvStack_20 = local_28;
    local_18 = pvVar1;
    if (local_28 == (void *)0xffffffffffffffff) goto LAB_180009afb;
    lVar8 = *(longlong *)this;
    lVar5 = (*(longlong *)(this + 8) - lVar8 >> 3) * -0x5555555555555555;
    if (lVar5 != 0) {
      puVar6 = (undefined4 *)(lVar8 + 0x10);
      lVar8 = (longlong)local_28 - lVar8;
      do {
        *(undefined4 *)((longlong)puVar6 + lVar8) = 0xc0000001;
        *(undefined4 *)((longlong)puVar6 + lVar8) = *puVar6;
        *puVar6 = 0xc0000001;
        *(undefined8 *)(lVar8 + -0x10 + (longlong)puVar6) = *(undefined8 *)(puVar6 + -4);
        *(undefined8 *)(puVar6 + -4) = 0;
        *(undefined8 *)(lVar8 + -8 + (longlong)puVar6) = *(undefined8 *)(puVar6 + -2);
        *(undefined8 *)(puVar6 + -2) = 0;
        puVar6 = puVar6 + 6;
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
    }
    pvVar2 = (void *)((longlong)local_28 + (*(longlong *)(this + 8) - *(longlong *)this >> 3) * 8);
    _Uninit(this);
    *(void **)this = pvVar3;
    *(void **)(this + 8) = pvVar2;
    *(void **)(this + 0x10) = pvVar1;
    bVar4 = true;
  }
  bVar7 = bVar4;
  local_18 = (void *)0xffffffffffffffff;
  pvStack_20 = (void *)0xffffffffffffffff;
LAB_180009afb:
  local_28 = pvStack_20;
  _Uninit((vector<Kerb3961::ReturnType<Kerb3961::OwnedBinary,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary&___ptr64)>,utl::allocator<Kerb3961::ReturnType<Kerb3961::OwnedBinary,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary&___ptr64)>_>_>
           *)&local_28);
  return bVar7;
}



===== _Uninit @ 180009b2c =====

/* private: void __cdecl utl::vector<struct Kerb3961::ReturnType<struct
   Kerb3961::OwnedBinary,&struct Kerb3961::ResultBlock const & __ptr64 __cdecl
   Kerb3961::SingleGetter<struct Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const &
   __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)>,class utl::allocator<struct
   Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct Kerb3961::ResultBlock const & __ptr64
   __cdecl Kerb3961::SingleGetter<struct Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary
   const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> > >::_Uninit(void) __ptr64 */

void __thiscall
utl::
vector<Kerb3961::ReturnType<Kerb3961::OwnedBinary,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary&___ptr64)>,utl::allocator<Kerb3961::ReturnType<Kerb3961::OwnedBinary,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary&___ptr64)>_>_>
::_Uninit(vector<Kerb3961::ReturnType<Kerb3961::OwnedBinary,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary&___ptr64)>,utl::allocator<Kerb3961::ReturnType<Kerb3961::OwnedBinary,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary&___ptr64)>_>_>
          *this)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  
  lVar1 = *(longlong *)this;
  if (lVar1 != -1) {
    lVar2 = *(longlong *)(this + 8);
    *(longlong *)(this + 8) = lVar1;
    lVar2 = (lVar2 - lVar1) / 6 + (lVar2 - lVar1 >> 0x3f);
    lVar2 = (lVar2 >> 2) - (lVar2 >> 0x3f);
    if (lVar2 != 0) {
      puVar3 = (undefined8 *)(lVar1 + (lVar2 * 3 + 1) * 8);
      do {
        puVar3 = puVar3 + -3;
        lVar2 = lVar2 + -1;
        if ((void *)*puVar3 != (void *)0x0) {
          operator_delete__((void *)*puVar3);
        }
      } while (lVar2 != 0);
    }
    operator_delete__(*(void **)this);
  }
  return;
}



===== Nfold @ 180009bbc =====

/* struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct Kerb3961::ResultBlock const &
   __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::OwnedBinary,16>(struct
   Kerb3961::OwnedBinary const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)>
   __cdecl Kerb3961::Nfold(unsigned __int64,struct Kerb3961::ReadOnlyBinary const & __ptr64) */

__uint64 __cdecl Kerb3961::Nfold(__uint64 param_1,ReadOnlyBinary *param_2)

{
  void *_Src;
  ReadOnlyBinary *pRVar1;
  ulonglong _Size;
  byte *pbVar2;
  ReadOnlyBinary *pRVar3;
  byte bVar5;
  byte bVar4;
  undefined8 *in_R8;
  ReadOnlyBinary *pRVar6;
  ReadOnlyBinary *pRVar7;
  byte *pbVar8;
  byte *pbVar9;
  ushort local_res10;
  ReadOnlyBinary *local_58;
  byte *local_50;
  long local_48;
  
  pRVar7 = (ReadOnlyBinary *)*in_R8;
  _Src = (void *)in_R8[1];
  pRVar3 = param_2;
  pRVar6 = pRVar7;
  if (param_2 < pRVar7) {
    pRVar3 = pRVar7;
    pRVar6 = param_2;
  }
  pRVar3 = (ReadOnlyBinary *)((ulonglong)pRVar3 % (ulonglong)pRVar6);
  while (pRVar1 = pRVar3, pRVar1 != (ReadOnlyBinary *)0x0) {
    pRVar3 = (ReadOnlyBinary *)((ulonglong)pRVar6 % (ulonglong)pRVar1);
    pRVar6 = pRVar1;
  }
  pRVar3 = (ReadOnlyBinary *)(((ulonglong)param_2 / (ulonglong)pRVar6) * (longlong)pRVar7);
  MakeBuffer((__uint64)&local_58);
  pbVar9 = local_50;
  if (local_48 < 0) {
    Logging::Verify::StatusFailed("scratchBuffer",local_48);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(long *)(param_1 + 0x10) = local_48;
    if (local_50 == (byte *)0x0) {
      return param_1;
    }
  }
  else {
    memmove(local_50,_Src,(size_t)pRVar7);
    if (pRVar7 < pRVar3) {
      pbVar8 = pbVar9 + (longlong)pRVar7;
      _Size = 1 % (ulonglong)pRVar7;
      do {
        pbVar2 = pbVar8 + -(longlong)pRVar7;
        memmove(pbVar8,pRVar7 + ((longlong)pbVar2 - _Size),_Size);
        memmove(pbVar8 + _Size,pbVar2,(longlong)pRVar7 - _Size);
        bVar5 = pbVar2[(longlong)pRVar7 * 2 + -1];
        if (pRVar7 != (ReadOnlyBinary *)0x0) {
          pbVar2 = pbVar8;
          pRVar6 = pRVar7;
          do {
            bVar4 = bVar5 << 3;
            bVar5 = *pbVar2;
            *pbVar2 = bVar5 >> 5 | bVar4;
            pbVar2 = pbVar2 + 1;
            pRVar6 = pRVar6 + -1;
          } while (pRVar6 != (ReadOnlyBinary *)0x0);
        }
        pbVar8 = pbVar8 + (longlong)pRVar7;
      } while ((ReadOnlyBinary *)(pbVar8 + -(longlong)pbVar9) < pRVar3);
      pbVar9 = local_50;
    }
    if (param_2 < pRVar3) {
      pRVar7 = param_2;
      if (param_2 == (ReadOnlyBinary *)0x0) {
                    /* WARNING: Subroutine does not return */
        ConsistencyFail((ushort *)L"Integers must be at least one byte in AccumulateOnes");
      }
      do {
        pbVar8 = pbVar9 + (longlong)param_2;
        local_res10 = 0;
        pbVar2 = pbVar8;
        pRVar6 = param_2;
        do {
          pbVar2 = pbVar2 + -1;
          local_res10 = (ushort)*pbVar2 +
                        (ushort)(byte)pRVar7[(longlong)pbVar2] + (local_res10 >> 8);
          *pbVar2 = (byte)local_res10;
          pRVar6 = pRVar6 + -1;
        } while (pRVar6 != (ReadOnlyBinary *)0x0);
        while( true ) {
          pbVar8 = pbVar8 + -1;
          local_res10 = (local_res10 >> 8) + (ushort)*pbVar8;
          *pbVar8 = (byte)local_res10;
          if ((char)(local_res10 >> 8) == '\0') break;
          if (pbVar8 == pbVar9) {
                    /* WARNING: Subroutine does not return */
            ConsistencyFail((ushort *)L"One\'s complement addition should not wrap more than once");
          }
        }
        pRVar7 = pRVar7 + (longlong)param_2;
      } while (pRVar7 < pRVar3);
    }
    local_58 = param_2;
    CopyBuffer((ReadOnlyBinary *)param_1);
    if (pbVar9 == (byte *)0x0) {
      return param_1;
    }
    local_50 = pbVar9;
  }
  operator_delete__(local_50);
  return param_1;
}



===== try_emplace<Kerb3961::EncryptionAlgorithm*___ptr64&___ptr64,0> @ 180009df0 =====

/* public: struct utl::pair<class utl::_TreeIt<struct utl::pair<unsigned int const ,struct
   Kerb3961::EncryptionAlgorithm * __ptr64> >,bool> __cdecl utl::map<unsigned int,struct
   Kerb3961::EncryptionAlgorithm * __ptr64,struct utl::less<unsigned int>,class
   utl::allocator<struct utl::pair<unsigned int const ,struct Kerb3961::EncryptionAlgorithm *
   __ptr64> > >::try_emplace<struct Kerb3961::EncryptionAlgorithm * __ptr64 & __ptr64,0>(unsigned
   int && __ptr64,struct Kerb3961::EncryptionAlgorithm * __ptr64 & __ptr64) __ptr64 */

uint * __thiscall
utl::
map<unsigned_int,Kerb3961::EncryptionAlgorithm*___ptr64,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>_>
::try_emplace<Kerb3961::EncryptionAlgorithm*___ptr64&___ptr64,0>
          (map<unsigned_int,Kerb3961::EncryptionAlgorithm*___ptr64,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>_>
           *this,uint *param_1,EncryptionAlgorithm **param_2)

{
  void **ppvVar1;
  ulonglong *puVar2;
  _TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *p_Var3;
  void **ppvVar4;
  ulonglong *in_R9;
  bool bVar5;
  void **local_28;
  bool bStack_20;
  undefined7 uStack_1f;
  
  param_1[0] = 0;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  if (*(map<unsigned_int,Kerb3961::EncryptionAlgorithm*___ptr64,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>_>
        **)(this + 0x10) == this) {
    puVar2 = operator_new__(0x28,(nothrow_t *)param_1);
    if (puVar2 != (ulonglong *)0x0) {
      *(undefined4 *)(puVar2 + 3) = *(undefined4 *)param_2;
      puVar2[4] = *in_R9;
      *puVar2 = (ulonglong)this | 1;
      puVar2[1] = (ulonglong)&_TreeSentinel;
      puVar2[2] = (ulonglong)&_TreeSentinel;
      *(ulonglong **)this = puVar2;
      *(ulonglong **)(this + 8) = puVar2;
      *(ulonglong **)(this + 0x10) = puVar2;
      *(longlong *)(this + 0x18) = *(longlong *)(this + 0x18) + 1;
    }
    *(ulonglong **)param_1 = puVar2;
    *(bool *)(param_1 + 2) = puVar2 != (ulonglong *)0x0;
  }
  else {
    ppvVar4 = (void **)0x0;
    ppvVar1 = *(void ***)this;
    do {
      local_28 = ppvVar1;
      bVar5 = *(uint *)(local_28 + 3) <= *(uint *)param_2;
      if (bVar5) {
        ppvVar4 = local_28;
      }
      _bStack_20 = CONCAT71(uStack_1f,bVar5);
      ppvVar1 = local_28[(ulonglong)bVar5 + 1];
    } while (local_28[(ulonglong)bVar5 + 1] != &_TreeSentinel);
    if (((ppvVar4 == (void **)0x0) || (*(uint *)param_2 <= *(uint *)(ppvVar4 + 3))) &&
       (ppvVar4 != (void **)0x0)) {
      *(void ***)param_1 = ppvVar4;
    }
    else {
      p_Var3 = operator_new__(0x28,(nothrow_t *)&_TreeSentinel);
      if (p_Var3 == (_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                     *)0x0) {
        *(undefined1 *)(param_1 + 2) = 0;
      }
      else {
        *(undefined4 *)(p_Var3 + 0x18) = *(undefined4 *)param_2;
        *(ulonglong *)(p_Var3 + 0x20) = *in_R9;
        _Tree<unsigned_int,utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>,0>
        ::_InsertAt((_Tree<unsigned_int,utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>,0>
                     *)this,(pair<utl::_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>*___ptr64,bool>
                             *)&local_28,p_Var3);
        *(undefined1 *)(param_1 + 2) = 1;
      }
      *(_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> **)param_1
           = p_Var3;
    }
  }
  return param_1;
}



===== CipherPolicyImpl @ 180009f44 =====

/* public: __cdecl Kerb3961::CipherPolicyImpl::CipherPolicyImpl(enum Kerb3961::KeyPolicyQualifiers)
   __ptr64 */

CipherPolicyImpl * __thiscall
Kerb3961::CipherPolicyImpl::CipherPolicyImpl(CipherPolicyImpl *this,KeyPolicyQualifiers param_1)

{
  CipherPolicyImpl *pCVar1;
  CipherPolicyImpl *pCVar2;
  
  *(undefined4 *)(this + 8) = 0;
  *(undefined ***)this = &_vftable_;
  this[0xc] = SUB41(param_1,0);
  ExInitializePushLock(this + 0x10);
  pCVar1 = this + 0x18;
  *(CipherPolicyImpl **)pCVar1 = pCVar1;
  pCVar2 = this + 0x58;
  *(CipherPolicyImpl **)(this + 0x20) = pCVar1;
  *(CipherPolicyImpl **)(this + 0x28) = pCVar1;
  *(undefined8 *)(this + 0x30) = 0;
  pCVar1 = this + 0x38;
  *(CipherPolicyImpl **)pCVar1 = pCVar1;
  *(CipherPolicyImpl **)(this + 0x40) = pCVar1;
  *(CipherPolicyImpl **)(this + 0x48) = pCVar1;
  *(undefined8 *)(this + 0x50) = 0;
  pCVar1 = this + 0x78;
  *(CipherPolicyImpl **)pCVar2 = pCVar2;
  *(CipherPolicyImpl **)(this + 0x60) = pCVar2;
  *(CipherPolicyImpl **)(this + 0x68) = pCVar2;
  *(undefined8 *)(this + 0x70) = 0;
  *(CipherPolicyImpl **)pCVar1 = pCVar1;
  *(CipherPolicyImpl **)(this + 0x80) = pCVar1;
  *(CipherPolicyImpl **)(this + 0x88) = pCVar1;
  *(undefined8 *)(this + 0x90) = 0;
  *(undefined4 *)(this + 0x9c) = 0;
  *(undefined4 *)(this + 0x98) = 0;
  *(CipherPolicyImpl **)(this + 0xa8) = this;
  *(CipherPolicyImpl **)(this + 0xb0) = pCVar2;
  *(undefined8 *)(this + 0xa0) = 0x80;
  return this;
}



===== ApplyCipherPolicies @ 18000a000 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual struct Kerb3961::ReturnType<struct Kerb3961::StatusOnly,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly & __ptr64)> __cdecl
   Kerb3961::CipherPolicyImpl::ApplyCipherPolicies(struct Kerb3961::ReadOnlyBinary const & __ptr64)
   __ptr64 */

ReadOnlyBinary * __thiscall
Kerb3961::CipherPolicyImpl::ApplyCipherPolicies(CipherPolicyImpl *this,ReadOnlyBinary *param_1)

{
  uchar **ppuVar1;
  __uint64 *p_Var2;
  char cVar3;
  ulonglong uVar4;
  longlong *plVar5;
  code *pcVar6;
  code *pcVar7;
  uint uVar8;
  longlong lVar9;
  _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *p_Var10;
  undefined8 ***pppuVar11;
  int *piVar12;
  char *pcVar13;
  undefined8 ***pppuVar14;
  int *piVar15;
  undefined1 *puVar16;
  ulonglong uVar17;
  int iVar18;
  ulonglong *in_R8;
  int *local_res8;
  longlong local_res18;
  undefined8 uStack_d0;
  undefined1 auStack_c8 [32];
  int **local_a8;
  uint local_98 [2];
  char local_90;
  uint local_88 [2];
  char local_80;
  ulonglong local_78;
  int *local_70;
  undefined8 ***local_68;
  undefined8 ***local_60;
  undefined8 ***local_58;
  undefined8 local_50;
  undefined8 ***local_48;
  undefined8 ***local_40;
  undefined8 ***local_38;
  undefined8 local_30;
  
  wil::push_lock::acquire_exclusive((push_lock *)(this + 0x10));
  memset(&local_78,0,0x50);
  uVar17 = *in_R8;
  local_68 = &local_68;
  local_50 = 0;
  local_30 = 0;
  piVar12 = (int *)in_R8[1];
  local_60 = &local_68;
  local_48 = &local_48;
  local_40 = &local_48;
  local_58 = local_60;
  local_38 = local_40;
  if (uVar17 < 0x18) {
LAB_18000a4f8:
    pcVar13 = "remainingSize >= MarshaledPolicyHeaderSize";
LAB_18000a4ff:
    iVar18 = -0x3ffffff3;
    Logging::Verify::ConditionFailed(pcVar13);
    puVar16 = auStack_c8;
    pcVar13 = "reader.Read(marshaledPolicies)";
  }
  else {
    if (uVar17 < *(ulonglong *)(piVar12 + 4)) {
LAB_18000a28c:
      pcVar13 = "header->TotalLength <= remainingSize";
      goto LAB_18000a4ff;
    }
    uVar4 = *(ulonglong *)(piVar12 + 2);
    if (uVar4 == 0) {
LAB_18000a280:
      pcVar13 = "header->ContentLength > 0";
      goto LAB_18000a4ff;
    }
    if (*(ulonglong *)(piVar12 + 4) - 0x18 < uVar4) {
LAB_18000a274:
      pcVar13 = "header->ContentLength <= header->TotalLength - MarshaledPolicyHeaderSize";
      goto LAB_18000a4ff;
    }
    if (*piVar12 != 1) {
      pcVar13 = "header->Type == MarshaledPolicyType::Global";
      goto LAB_18000a4ff;
    }
    if (piVar12[1] != 0) {
      pcVar13 = "header->Id == 0";
      goto LAB_18000a4ff;
    }
    local_70 = piVar12 + 6;
    piVar15 = (int *)((longlong)piVar12 + *(longlong *)(piVar12 + 4));
    uVar17 = uVar17 - *(longlong *)(piVar12 + 4);
    local_78 = uVar4;
    if (uVar17 != 0) {
      do {
        if (uVar17 < 0x18) goto LAB_18000a4f8;
        if (uVar17 < *(ulonglong *)(piVar15 + 4)) goto LAB_18000a28c;
        ppuVar1 = (uchar **)(piVar15 + 2);
        if (*ppuVar1 == (uchar *)0x0) goto LAB_18000a280;
        if ((uchar *)(*(ulonglong *)(piVar15 + 4) - 0x18) < *ppuVar1) goto LAB_18000a274;
        if (1 < *piVar15 - 2U) {
          pcVar13 = 
          "header->Type == MarshaledPolicyType::Encryption || header->Type == MarshaledPolicyType::Checksum"
          ;
          goto LAB_18000a4ff;
        }
        p_Var2 = (__uint64 *)(piVar15 + 1);
        if ((int)*p_Var2 == 0) {
          pcVar13 = "header->Id != 0";
          goto LAB_18000a4ff;
        }
        local_res8 = piVar15 + 6;
        local_a8 = &local_res8;
        if (*piVar15 == 2) {
          utl::
          map<unsigned_int,Kerb3961::ReadOnlyBinary,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>_>_>
          ::try_emplace<unsigned___int64_const&___ptr64,unsigned_char_const*___ptr64,0>
                    ((map<unsigned_int,Kerb3961::ReadOnlyBinary,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>_>_>
                      *)&local_68,local_98,p_Var2,ppuVar1);
          cVar3 = local_90;
        }
        else {
          utl::
          map<unsigned_int,Kerb3961::ReadOnlyBinary,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>_>_>
          ::try_emplace<unsigned___int64_const&___ptr64,unsigned_char_const*___ptr64,0>
                    ((map<unsigned_int,Kerb3961::ReadOnlyBinary,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::ReadOnlyBinary>_>_>
                      *)&local_48,local_88,p_Var2,ppuVar1);
          cVar3 = local_80;
        }
        if (cVar3 == '\0') {
          pcVar13 = "result.second";
          goto LAB_18000a4ff;
        }
        plVar5 = (longlong *)(piVar15 + 4);
        piVar15 = (int *)((longlong)piVar15 + *plVar5);
        uVar17 = uVar17 - *plVar5;
      } while (uVar17 != 0);
    }
    piVar12 = local_70;
    if (local_78 == 0) {
                    /* WARNING: Subroutine does not return */
      ConsistencyFail((ushort *)
                      L"You can only retrieve the global policy following a successful call to Read()"
                     );
    }
    if (local_78 != 0x28) {
      Logging::Verify::ConditionFailed("globalBlob.length == sizeof(MarshaledGlobalPolicyData)");
      puVar16 = auStack_c8;
      *(undefined4 *)param_1 = 0xc000000d;
      goto LAB_18000a51a;
    }
    _g_supportedEncryptionTypes = *local_70;
    _g_assumedEncryptionTypes = local_70[1];
    _g_realmEncryptionTypes = local_70[2];
    _g_krbtgtEncryptionTypes = local_70[3];
    _g_trustEncryptionTypes = local_70[4];
    uVar17 = Feature_184236346__private_IsEnabledDeviceUsageNoInline();
    puVar16 = auStack_c8;
    if ((int)uVar17 == 0) {
      _g_defaultAssumedEncryptionTypes = piVar12[5];
      _g_defaultRealmEncryptionTypes = piVar12[6];
      _g_defaultKrbtgtEncryptionTypes = piVar12[7];
      _g_defaultTrustEncryptionTypes = piVar12[8];
    }
    Velocity::Feature_RC4Deprecation = SUB41(piVar12[9],0);
    for (p_Var10 = *(_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                     **)(this + 0x28);
        p_Var10 !=
        (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *)
        (this + 0x18);
        p_Var10 = (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                   *)utl::
                     _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                     ::_Traverse(p_Var10,true)) {
      plVar5 = *(longlong **)(p_Var10 + 0x20);
      pcVar6 = *(code **)(*plVar5 + 0xd8);
      *(undefined8 *)(puVar16 + -8) = 0x18000a227;
      uVar8 = (*pcVar6)(plVar5);
      if ((undefined8 ****)local_58 == &local_68) {
LAB_18000a343:
        local_res8 = (int *)((ulonglong)local_res8 & 0xffffffff00000000);
      }
      else {
        pppuVar14 = &local_68;
        pppuVar11 = local_68;
        do {
          if (*(uint *)(pppuVar11 + 3) < uVar8) {
            lVar9 = 0x10;
          }
          else {
            lVar9 = 8;
            pppuVar14 = pppuVar11;
          }
          pppuVar11 = *(undefined8 ****)(lVar9 + (longlong)pppuVar11);
        } while (pppuVar11 != &utl::_TreeSentinel);
        if (((undefined8 ****)pppuVar14 == &local_68) || (uVar8 < *(uint *)(pppuVar14 + 3)))
        goto LAB_18000a343;
        pcVar6 = *(code **)(*plVar5 + 0x68);
        pcVar7 = *(code **)(*plVar5 + 0xd8);
        *(undefined8 *)(puVar16 + -8) = 0x18000a2d3;
        uVar8 = (*pcVar7)(plVar5);
        pppuVar14 = &local_68;
        if ((undefined8 ****)local_58 == &local_68) {
LAB_18000a31e:
          pcVar7 = (code *)swi(0x2c);
          (*pcVar7)();
          puVar16 = puVar16 + 8;
        }
        else {
          pppuVar11 = local_68;
          do {
            if (*(uint *)(pppuVar11 + 3) < uVar8) {
              lVar9 = 0x10;
            }
            else {
              lVar9 = 8;
              pppuVar14 = pppuVar11;
            }
            pppuVar11 = *(undefined8 ****)(lVar9 + (longlong)pppuVar11);
          } while (pppuVar11 != &utl::_TreeSentinel);
          if ((undefined8 ****)pppuVar14 == &local_68) goto LAB_18000a31e;
          if (uVar8 < *(uint *)(pppuVar14 + 3)) {
            pppuVar14 = &local_68;
            goto LAB_18000a31e;
          }
        }
        *(undefined8 *)(puVar16 + -8) = 0x18000a333;
        (*pcVar6)(plVar5,&local_res8,pppuVar14 + 4);
        if ((int)local_res8 < 0) {
          pcVar13 = "reader.ApplyCipher(encryption.second)";
          iVar18 = (int)local_res8;
          goto LAB_18000a360;
        }
      }
      *(undefined8 *)(puVar16 + -8) = 0x18000a351;
    }
    for (p_Var10 = *(_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                     **)(this + 0x48);
        p_Var10 !=
        (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *)
        (this + 0x38);
        p_Var10 = (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                   *)utl::
                     _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                     ::_Traverse(p_Var10,true)) {
      plVar5 = *(longlong **)(p_Var10 + 0x20);
      pcVar6 = *(code **)(*plVar5 + 0x68);
      *(undefined8 *)(puVar16 + -8) = 0x18000a393;
      uVar8 = (*pcVar6)(plVar5);
      if ((undefined8 ****)local_38 == &local_48) {
LAB_18000a464:
        local_res8 = (int *)((ulonglong)local_res8 & 0xffffffff00000000);
      }
      else {
        pppuVar14 = &local_48;
        pppuVar11 = local_48;
        do {
          if (*(uint *)(pppuVar11 + 3) < uVar8) {
            lVar9 = 0x10;
          }
          else {
            lVar9 = 8;
            pppuVar14 = pppuVar11;
          }
          pppuVar11 = *(undefined8 ****)(lVar9 + (longlong)pppuVar11);
        } while (pppuVar11 != &utl::_TreeSentinel);
        if (((undefined8 ****)pppuVar14 == &local_48) || (uVar8 < *(uint *)(pppuVar14 + 3)))
        goto LAB_18000a464;
        pcVar6 = *(code **)(*plVar5 + 0x50);
        pcVar7 = *(code **)(*plVar5 + 0x68);
        *(undefined8 *)(puVar16 + -8) = 0x18000a3f4;
        uVar8 = (*pcVar7)(plVar5);
        pppuVar14 = &local_48;
        if ((undefined8 ****)local_38 == &local_48) {
LAB_18000a43f:
          pcVar7 = (code *)swi(0x2c);
          (*pcVar7)();
          puVar16 = puVar16 + 8;
        }
        else {
          pppuVar11 = local_48;
          do {
            if (*(uint *)(pppuVar11 + 3) < uVar8) {
              lVar9 = 0x10;
            }
            else {
              lVar9 = 8;
              pppuVar14 = pppuVar11;
            }
            pppuVar11 = *(undefined8 ****)(lVar9 + (longlong)pppuVar11);
          } while (pppuVar11 != &utl::_TreeSentinel);
          if ((undefined8 ****)pppuVar14 == &local_48) goto LAB_18000a43f;
          if (uVar8 < *(uint *)(pppuVar14 + 3)) {
            pppuVar14 = &local_48;
            goto LAB_18000a43f;
          }
        }
        *(undefined8 *)(puVar16 + -8) = 0x18000a454;
        (*pcVar6)(plVar5,&local_res8,pppuVar14 + 4);
        if ((int)local_res8 < 0) {
          pcVar13 = "reader.ApplyChecksum(checksum.second)";
          iVar18 = (int)local_res8;
LAB_18000a360:
          *(undefined8 *)(puVar16 + -8) = 0x18000a367;
          Logging::Verify::StatusFailed(pcVar13,iVar18);
          *(int *)param_1 = iVar18;
          goto LAB_18000a51a;
        }
      }
      *(undefined8 *)(puVar16 + -8) = 0x18000a472;
    }
    *(undefined8 *)(puVar16 + -8) = 0x18000a492;
    piVar12 = (int *)OrderCiphers(this);
    iVar18 = *piVar12;
    if (-1 < iVar18) {
      *(undefined8 *)(puVar16 + -8) = 0x18000a4a6;
      uVar17 = Feature_184236346__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar17 == 0) {
        *(undefined8 *)(puVar16 + -8) = 0x18000a4af;
        uVar17 = Feature_KdcReplicationNoRc4__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar17 != 0) {
          *(undefined8 *)(puVar16 + -8) = 0x18000a4bc;
          piVar12 = (int *)UpgradeDefaults(this);
          iVar18 = *piVar12;
          if (iVar18 < 0) {
            pcVar13 = "UpgradeDefaults()";
            goto LAB_18000a510;
          }
        }
      }
      *(undefined4 *)param_1 = 0;
      goto LAB_18000a51a;
    }
    pcVar13 = "OrderCiphers()";
  }
LAB_18000a510:
  *(undefined8 *)(puVar16 + -8) = 0x18000a517;
  Logging::Verify::StatusFailed(pcVar13,iVar18);
  *(int *)param_1 = iVar18;
LAB_18000a51a:
  *(undefined8 *)(puVar16 + -8) = 0x18000a523;
  utl::
  _Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
  ::
  ~_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
            ((_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
              *)&local_48);
  *(undefined8 *)(puVar16 + -8) = 0x18000a52c;
  utl::
  _Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
  ::
  ~_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
            ((_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
              *)&local_68);
  if (local_res18 != 0) {
    *(undefined8 *)(puVar16 + -8) = 0x18000a53e;
    ExReleasePushLockExclusiveEx(local_res18,0);
    *(undefined8 *)(puVar16 + -8) = 0x18000a54a;
    KeLeaveCriticalRegion();
  }
  return param_1;
}



===== CheckKeyUsage @ 18000a584 =====

/* public: static struct Kerb3961::ReturnType<struct Kerb3961::StatusOnly,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly & __ptr64)> __cdecl
   Kerb3961::CipherPolicyImpl::CheckKeyUsage(enum Kerb3961::KeyUsage & __ptr64) */

KeyUsage * __cdecl Kerb3961::CipherPolicyImpl::CheckKeyUsage(KeyUsage *param_1)

{
  char *pcVar1;
  longlong *in_RDX;
  undefined1 local_res10;
  char local_res11;
  char local_res15;
  
  if ((*in_RDX == -0x8000000000000000) && (!g_allowPolicyBypass)) {
                    /* WARNING: Subroutine does not return */
    ConsistencyFail((ushort *)L"Non test code is attempting to bypass policy");
  }
  GetScenarioForKeyUsage((KeyUsage)&local_res10);
  if (local_res15 == '\0') {
    pcVar1 = "scenarioOpt.has_value()";
  }
  else {
    if (local_res11 == '\x06') {
      *in_RDX = -0x8000000000000000;
      *param_1 = 0;
      return param_1;
    }
    pcVar1 = "keyScenario.usageOperations == KeyPolicyOperation::GssApi";
  }
  Logging::Verify::ConditionFailed(pcVar1);
  *param_1 = 0xc000000d;
  return param_1;
}



===== CloseCipherPartnerHandle @ 18000a610 =====

/* public: virtual void __cdecl Kerb3961::CipherPolicyImpl::CloseCipherPartnerHandle(struct
   Kerb3961::CipherPartnerHandle & __ptr64)const __ptr64 */

void __thiscall
Kerb3961::CipherPolicyImpl::CloseCipherPartnerHandle
          (CipherPolicyImpl *this,CipherPartnerHandle *param_1)

{
  _Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
  *this_00;
  
  if (*(CipherPolicyImpl **)param_1 != this) {
                    /* WARNING: Subroutine does not return */
    ConsistencyFail((ushort *)L"Tried to free cipher partner handle with wrong policy");
  }
  this_00 = *(_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
              **)(param_1 + 8);
  if (this_00 ==
      (_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
       *)(this + 0x58)) {
    *(undefined8 *)(param_1 + 8) = 0;
  }
  else if (this_00 !=
           (_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
            *)0x0) {
    utl::
    _Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
    ::
    ~_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
              (this_00 + 0x20);
    utl::
    _Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
    ::
    ~_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
              (this_00);
    operator_delete__(this_00);
    *(undefined8 *)(param_1 + 8) = 0;
  }
  return;
}



===== EnsureInitialization @ 18000a678 =====

/* public: struct Kerb3961::CipherPolicyImpl::InitializationSentinel __cdecl
   Kerb3961::CipherPolicyImpl::EnsureInitialization(enum Kerb3961::KeyUsage)const __ptr64 */

undefined1 * __thiscall
Kerb3961::CipherPolicyImpl::EnsureInitialization(CipherPolicyImpl *this,KeyUsage param_1)

{
  undefined4 in_register_00000014;
  longlong in_R8;
  
  if (*(int *)(this + 8) == 0) {
    wil::push_lock::acquire_exclusive((push_lock *)(this + 0x10));
    if (*(int *)(this + 8) == 0) {
                    /* WARNING: Subroutine does not return */
      ConsistencyFail((ushort *)L"Kernel cannot use last-resort initialization");
    }
    if (in_R8 != 0) {
      ExReleasePushLockExclusiveEx(in_R8,0);
      KeLeaveCriticalRegion();
    }
  }
  *(undefined1 *)CONCAT44(in_register_00000014,param_1) = 0;
  return (undefined1 *)CONCAT44(in_register_00000014,param_1);
}



===== FilterCipherPartnerHandle @ 18000a6f0 =====

/* public: virtual struct Kerb3961::ReturnType<struct Kerb3961::StatusOnly,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly & __ptr64)> __cdecl
   Kerb3961::CipherPolicyImpl::FilterCipherPartnerHandle(struct Kerb3961::CipherPartnerHandle &
   __ptr64,unsigned int,enum Kerb3961::UserPolicyAttributes)const __ptr64 */

CipherPartnerHandle * __thiscall
Kerb3961::CipherPolicyImpl::FilterCipherPartnerHandle
          (CipherPolicyImpl *this,CipherPartnerHandle *param_1,uint param_2,
          UserPolicyAttributes param_3)

{
  *(undefined4 *)param_1 = 0xc0000001;
  return param_1;
}



===== GetAttributesOfKeyUsage @ 18000a710 =====

/* public: virtual struct Kerb3961::ReturnType<struct Kerb3961::ResultAdapter<struct
   Kerb3961::KeyPolicyScenario>,&struct Kerb3961::ResultBlock const & __ptr64 __cdecl
   Kerb3961::SingleGetter<struct Kerb3961::ResultAdapter<struct
   Kerb3961::KeyPolicyScenario>,8>(struct Kerb3961::ResultAdapter<struct
   Kerb3961::KeyPolicyScenario> const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::ResultAdapter<struct
   Kerb3961::KeyPolicyScenario>,8>(struct Kerb3961::ResultAdapter<struct
   Kerb3961::KeyPolicyScenario> & __ptr64)> __cdecl
   Kerb3961::CipherPolicyImpl::GetAttributesOfKeyUsage(enum Kerb3961::KeyUsage)const __ptr64 */

undefined4 * __thiscall
Kerb3961::CipherPolicyImpl::GetAttributesOfKeyUsage(CipherPolicyImpl *this,KeyUsage param_1)

{
  CipherPolicyImpl CVar1;
  undefined4 in_register_00000014;
  undefined4 *puVar2;
  undefined4 local_res20;
  byte local_res24;
  char local_res25;
  
  puVar2 = (undefined4 *)CONCAT44(in_register_00000014,param_1);
  GetScenarioForKeyUsage((KeyUsage)&local_res20);
  if (local_res25 == '\0') {
    Logging::Verify::ConditionFailed("scenario.has_value()");
    *puVar2 = 0;
    *(undefined1 *)(puVar2 + 1) = 0;
    puVar2[2] = 0xc000000d;
  }
  else {
    CVar1 = this[0xc];
    *puVar2 = local_res20;
    *(byte *)(puVar2 + 1) = local_res24 | (byte)CVar1;
    puVar2[2] = 0;
  }
  return puVar2;
}



===== GetChecksumForEncryption @ 18000a780 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual struct Kerb3961::ReturnType<struct Kerb3961::ResultAdapter<struct
   Kerb3961::ChecksumAlgorithm * __ptr64>,&struct Kerb3961::ResultBlock const & __ptr64 __cdecl
   Kerb3961::SingleGetter<struct Kerb3961::ResultAdapter<struct Kerb3961::ChecksumAlgorithm *
   __ptr64>,8>(struct Kerb3961::ResultAdapter<struct Kerb3961::ChecksumAlgorithm * __ptr64> const &
   __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::ResultAdapter<struct Kerb3961::ChecksumAlgorithm * __ptr64>,8>(struct
   Kerb3961::ResultAdapter<struct Kerb3961::ChecksumAlgorithm * __ptr64> & __ptr64)> __cdecl
   Kerb3961::CipherPolicyImpl::GetChecksumForEncryption(struct Kerb3961::EncryptionAlgorithm *
   __ptr64,enum Kerb3961::KeyUsage,struct Kerb3961::CipherPartnerHandle const & __ptr64,struct
   Kerb3961::CipherPartnerHandle const & __ptr64)const __ptr64 */

EncryptionAlgorithm * __thiscall
Kerb3961::CipherPolicyImpl::GetChecksumForEncryption
          (CipherPolicyImpl *this,EncryptionAlgorithm *param_1,KeyUsage param_2,
          CipherPartnerHandle *param_3,CipherPartnerHandle *param_4)

{
  KeyUsage KVar1;
  undefined4 in_register_00000084;
  
  KVar1 = (**(code **)(*(longlong *)CONCAT44(in_register_00000084,param_2) + 0xe0))
                    ((longlong *)CONCAT44(in_register_00000084,param_2));
  OpenChecksumById(this,(uint)param_1,KVar1,param_3,param_4);
  return param_1;
}



===== GetCipherPartnerHandle @ 18000a7f0 =====

/* public: virtual struct Kerb3961::ReturnType<struct Kerb3961::ResultAdapter<struct
   Kerb3961::CipherPartnerHandle>,&struct Kerb3961::ResultBlock const & __ptr64 __cdecl
   Kerb3961::SingleGetter<struct Kerb3961::ResultAdapter<struct
   Kerb3961::CipherPartnerHandle>,16>(struct Kerb3961::ResultAdapter<struct
   Kerb3961::CipherPartnerHandle> const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::ResultAdapter<struct
   Kerb3961::CipherPartnerHandle>,16>(struct Kerb3961::ResultAdapter<struct
   Kerb3961::CipherPartnerHandle> & __ptr64)> __cdecl
   Kerb3961::CipherPolicyImpl::GetCipherPartnerHandle(void)const __ptr64 */

void __thiscall Kerb3961::CipherPolicyImpl::GetCipherPartnerHandle(CipherPolicyImpl *this)

{
  undefined8 *in_RDX;
  
  *in_RDX = 0;
  in_RDX[1] = 0;
  *(undefined4 *)(in_RDX + 2) = 0xc0000001;
  return;
}



===== GetCipherAttributes @ 18000a810 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual struct Kerb3961::ReturnType<struct Kerb3961::ResultAdapter<enum
   Kerb3961::CipherAttributes>,&struct Kerb3961::ResultBlock const & __ptr64 __cdecl
   Kerb3961::SingleGetter<struct Kerb3961::ResultAdapter<enum Kerb3961::CipherAttributes>,4>(struct
   Kerb3961::ResultAdapter<enum Kerb3961::CipherAttributes> const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::ResultAdapter<enum Kerb3961::CipherAttributes>,4>(struct Kerb3961::ResultAdapter<enum
   Kerb3961::CipherAttributes> & __ptr64)> __cdecl
   Kerb3961::CipherPolicyImpl::GetCipherAttributes(unsigned int)const __ptr64 */

undefined4 * __thiscall
Kerb3961::CipherPolicyImpl::GetCipherAttributes(CipherPolicyImpl *this,uint param_1)

{
  undefined4 uVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined4 in_register_00000014;
  undefined4 *puVar4;
  longlong lVar5;
  uint in_R8D;
  char local_res20 [8];
  longlong local_18;
  
  puVar4 = (undefined4 *)CONCAT44(in_register_00000014,param_1);
  EnsureInitialization(this,(KeyUsage)local_res20);
  wil::push_lock::acquire_shared((push_lock *)&g_cipherLock);
  if (DAT_180018320 != &g_encryptions) {
    ppuVar3 = &g_encryptions;
    ppuVar2 = (undefined **)g_encryptions;
    do {
      if (*(uint *)(ppuVar2 + 3) < in_R8D) {
        lVar5 = 0x10;
      }
      else {
        lVar5 = 8;
        ppuVar3 = ppuVar2;
      }
      ppuVar2 = *(undefined ***)((longlong)ppuVar2 + lVar5);
    } while (ppuVar2 != &utl::_TreeSentinel);
    if (((ppuVar3 == &g_encryptions) || (*(uint *)(ppuVar3 + 3) <= in_R8D)) &&
       (ppuVar3 != &g_encryptions)) {
      uVar1 = (**(code **)(*(longlong *)ppuVar3[4] + 0x28))();
      puVar4[1] = 0;
      *puVar4 = uVar1;
      goto LAB_18000a8be;
    }
  }
  *puVar4 = 0;
  puVar4[1] = 0xc0000001;
  puVar4[1] = 0xc00002fd;
LAB_18000a8be:
  if (local_18 != 0) {
    ExReleasePushLockSharedEx(local_18,0);
    KeLeaveCriticalRegion();
  }
  if (local_res20[0] != '\0') {
    Kerb3961::UninitializeCiphers();
  }
  return puVar4;
}



===== GetCipherBitmask @ 18000a910 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual struct Kerb3961::ReturnType<struct Kerb3961::ResultAdapter<unsigned int>,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::ResultAdapter<unsigned int>,4>(struct Kerb3961::ResultAdapter<unsigned int> const &
   __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::ResultAdapter<unsigned int>,4>(struct Kerb3961::ResultAdapter<unsigned int> & __ptr64)>
   __cdecl Kerb3961::CipherPolicyImpl::GetCipherBitmask(unsigned int)const __ptr64 */

undefined4 * __thiscall
Kerb3961::CipherPolicyImpl::GetCipherBitmask(CipherPolicyImpl *this,uint param_1)

{
  undefined4 uVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined4 in_register_00000014;
  undefined4 *puVar4;
  longlong lVar5;
  uint in_R8D;
  char local_res20 [8];
  longlong local_18;
  
  puVar4 = (undefined4 *)CONCAT44(in_register_00000014,param_1);
  EnsureInitialization(this,(KeyUsage)local_res20);
  wil::push_lock::acquire_shared((push_lock *)&g_cipherLock);
  if (DAT_180018320 != &g_encryptions) {
    ppuVar3 = &g_encryptions;
    ppuVar2 = (undefined **)g_encryptions;
    do {
      if (*(uint *)(ppuVar2 + 3) < in_R8D) {
        lVar5 = 0x10;
      }
      else {
        lVar5 = 8;
        ppuVar3 = ppuVar2;
      }
      ppuVar2 = *(undefined ***)((longlong)ppuVar2 + lVar5);
    } while (ppuVar2 != &utl::_TreeSentinel);
    if (((ppuVar3 == &g_encryptions) || (*(uint *)(ppuVar3 + 3) <= in_R8D)) &&
       (ppuVar3 != &g_encryptions)) {
      uVar1 = (**(code **)(*(longlong *)ppuVar3[4] + 0x30))();
      puVar4[1] = 0;
      *puVar4 = uVar1;
      goto LAB_18000a9be;
    }
  }
  *puVar4 = 0;
  puVar4[1] = 0xc0000001;
  puVar4[1] = 0xc00002fd;
LAB_18000a9be:
  if (local_18 != 0) {
    ExReleasePushLockSharedEx(local_18,0);
    KeLeaveCriticalRegion();
  }
  if (local_res20[0] != '\0') {
    Kerb3961::UninitializeCiphers();
  }
  return puVar4;
}



===== GetCipherSSPISizes @ 18000aa10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual struct Kerb3961::ReturnType<struct Kerb3961::ResultAdapter<struct
   Kerb3961::SSPISizes>,&struct Kerb3961::ResultBlock const & __ptr64 __cdecl
   Kerb3961::SingleGetter<struct Kerb3961::ResultAdapter<struct Kerb3961::SSPISizes>,32>(struct
   Kerb3961::ResultAdapter<struct Kerb3961::SSPISizes> const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::ResultAdapter<struct Kerb3961::SSPISizes>,32>(struct Kerb3961::ResultAdapter<struct
   Kerb3961::SSPISizes> & __ptr64)> __cdecl Kerb3961::CipherPolicyImpl::GetCipherSSPISizes(unsigned
   int)const __ptr64 */

undefined8 * __thiscall
Kerb3961::CipherPolicyImpl::GetCipherSSPISizes(CipherPolicyImpl *this,uint param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined **ppuVar6;
  undefined4 *puVar7;
  undefined **ppuVar8;
  undefined4 in_register_00000014;
  undefined8 *puVar9;
  longlong lVar10;
  uint in_R8D;
  char local_res20 [8];
  longlong local_18;
  
  puVar9 = (undefined8 *)CONCAT44(in_register_00000014,param_1);
  EnsureInitialization(this,(KeyUsage)local_res20);
  wil::push_lock::acquire_shared((push_lock *)&g_cipherLock);
  if (DAT_180018320 != &g_encryptions) {
    ppuVar8 = &g_encryptions;
    ppuVar6 = (undefined **)g_encryptions;
    do {
      if (*(uint *)(ppuVar6 + 3) < in_R8D) {
        lVar10 = 0x10;
      }
      else {
        lVar10 = 8;
        ppuVar8 = ppuVar6;
      }
      ppuVar6 = *(undefined ***)((longlong)ppuVar6 + lVar10);
    } while (ppuVar6 != &utl::_TreeSentinel);
    if (((ppuVar8 == &g_encryptions) || (*(uint *)(ppuVar8 + 3) <= in_R8D)) &&
       (ppuVar8 != &g_encryptions)) {
      puVar7 = (undefined4 *)(**(code **)(*(longlong *)ppuVar8[4] + 0x130))();
      uVar1 = puVar7[1];
      uVar2 = puVar7[2];
      uVar3 = puVar7[3];
      uVar4 = *(undefined8 *)(puVar7 + 4);
      uVar5 = *(undefined8 *)(puVar7 + 6);
      *(undefined4 *)puVar9 = *puVar7;
      *(undefined4 *)((longlong)puVar9 + 4) = uVar1;
      *(undefined4 *)(puVar9 + 1) = uVar2;
      *(undefined4 *)((longlong)puVar9 + 0xc) = uVar3;
      puVar9[2] = uVar4;
      puVar9[3] = uVar5;
      *(undefined4 *)(puVar9 + 4) = 0;
      goto LAB_18000aad4;
    }
  }
  *puVar9 = 0;
  puVar9[1] = 0;
  puVar9[2] = 0;
  puVar9[3] = 0;
  *(undefined4 *)(puVar9 + 4) = 0xc0000001;
  *(undefined4 *)(puVar9 + 4) = 0xc00002fd;
LAB_18000aad4:
  if (local_18 != 0) {
    ExReleasePushLockSharedEx(local_18,0);
    KeLeaveCriticalRegion();
  }
  if (local_res20[0] != '\0') {
    Kerb3961::UninitializeCiphers();
  }
  return puVar9;
}



===== GetDefaultDomainPartnerHandle @ 18000ab20 =====

/* public: virtual struct Kerb3961::ReturnType<struct Kerb3961::ResultAdapter<struct
   Kerb3961::CipherPartnerHandle>,&struct Kerb3961::ResultBlock const & __ptr64 __cdecl
   Kerb3961::SingleGetter<struct Kerb3961::ResultAdapter<struct
   Kerb3961::CipherPartnerHandle>,16>(struct Kerb3961::ResultAdapter<struct
   Kerb3961::CipherPartnerHandle> const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::ResultAdapter<struct
   Kerb3961::CipherPartnerHandle>,16>(struct Kerb3961::ResultAdapter<struct
   Kerb3961::CipherPartnerHandle> & __ptr64)> __cdecl
   Kerb3961::CipherPolicyImpl::GetDefaultDomainPartnerHandle(void) __ptr64 */

void __thiscall Kerb3961::CipherPolicyImpl::GetDefaultDomainPartnerHandle(CipherPolicyImpl *this)

{
  undefined8 *in_RDX;
  
  if (((byte)this[0xc] & 2) == 0) {
                    /* WARNING: Subroutine does not return */
    ConsistencyFail((ushort *)
                    L"You cannot call GetDefaultDomainPartnerHandle on a non-domain policy.");
  }
  *(undefined4 *)(in_RDX + 2) = 0;
  in_RDX[1] = this + 0x58;
  *in_RDX = this;
  return;
}



===== GetDefaultDomainSupportedEncTypesBitmask @ 18000ab60 =====

/* public: virtual struct Kerb3961::ReturnType<struct Kerb3961::ResultAdapter<unsigned int>,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::ResultAdapter<unsigned int>,4>(struct Kerb3961::ResultAdapter<unsigned int> const &
   __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::ResultAdapter<unsigned int>,4>(struct Kerb3961::ResultAdapter<unsigned int> & __ptr64)>
   __cdecl Kerb3961::CipherPolicyImpl::GetDefaultDomainSupportedEncTypesBitmask(void)const __ptr64
    */

void __thiscall
Kerb3961::CipherPolicyImpl::GetDefaultDomainSupportedEncTypesBitmask(CipherPolicyImpl *this)

{
  undefined4 *in_RDX;
  undefined4 uVar1;
  char local_res8 [8];
  undefined1 local_res18 [5];
  char local_res1d;
  
  EnsureInitialization(this,(KeyUsage)local_res8);
  if (this[0xc] != (CipherPolicyImpl)0x2) {
                    /* WARNING: Subroutine does not return */
    ConsistencyFail((ushort *)L"Only the domain policy has the DDSET defined");
  }
  GetScenarioForKeyUsage((KeyUsage)local_res18);
  uVar1 = 0;
  if (local_res1d == '\0') {
                    /* WARNING: Subroutine does not return */
    ConsistencyFail((ushort *)L"Failed to retrieve scenario data for KeyUsage::Ticket");
  }
  GetScenarioForKeyUsage((KeyUsage)local_res18);
  if (local_res1d == (char)uVar1) {
                    /* WARNING: Subroutine does not return */
    ConsistencyFail((ushort *)L"Failed to retrieve scenario data for KeyUsage::TgsRepSessionKey");
  }
  *in_RDX = uVar1;
  in_RDX[1] = 0xc0000001;
  if (local_res8[0] != (char)uVar1) {
    Kerb3961::UninitializeCiphers();
  }
  return;
}



===== GetEncryptionForChecksum @ 18000ac00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual struct Kerb3961::ReturnType<struct Kerb3961::ResultAdapter<struct
   Kerb3961::EncryptionAlgorithm * __ptr64>,&struct Kerb3961::ResultBlock const & __ptr64 __cdecl
   Kerb3961::SingleGetter<struct Kerb3961::ResultAdapter<struct Kerb3961::EncryptionAlgorithm *
   __ptr64>,8>(struct Kerb3961::ResultAdapter<struct Kerb3961::EncryptionAlgorithm * __ptr64> const
   & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::ResultAdapter<struct Kerb3961::EncryptionAlgorithm * __ptr64>,8>(struct
   Kerb3961::ResultAdapter<struct Kerb3961::EncryptionAlgorithm * __ptr64> & __ptr64)> __cdecl
   Kerb3961::CipherPolicyImpl::GetEncryptionForChecksum(struct Kerb3961::ChecksumAlgorithm *
   __ptr64,enum Kerb3961::KeyUsage,struct Kerb3961::CipherPartnerHandle const & __ptr64,struct
   Kerb3961::CipherPartnerHandle const & __ptr64)const __ptr64 */

ChecksumAlgorithm * __thiscall
Kerb3961::CipherPolicyImpl::GetEncryptionForChecksum
          (CipherPolicyImpl *this,ChecksumAlgorithm *param_1,KeyUsage param_2,
          CipherPartnerHandle *param_3,CipherPartnerHandle *param_4)

{
  KeyUsage KVar1;
  undefined4 in_register_00000084;
  
  KVar1 = (**(code **)(*(longlong *)CONCAT44(in_register_00000084,param_2) + 0x78))
                    ((longlong *)CONCAT44(in_register_00000084,param_2));
  OpenEncryptionById(this,(uint)param_1,KVar1,param_3,param_4);
  return param_1;
}



===== GetSupportedEncryptionTypesBitmask @ 18000ac70 =====

/* public: virtual struct Kerb3961::ReturnType<struct Kerb3961::ResultAdapter<unsigned int>,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::ResultAdapter<unsigned int>,4>(struct Kerb3961::ResultAdapter<unsigned int> const &
   __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::ResultAdapter<unsigned int>,4>(struct Kerb3961::ResultAdapter<unsigned int> & __ptr64)>
   __cdecl Kerb3961::CipherPolicyImpl::GetSupportedEncryptionTypesBitmask(void)const __ptr64 */

void __thiscall
Kerb3961::CipherPolicyImpl::GetSupportedEncryptionTypesBitmask(CipherPolicyImpl *this)

{
  undefined4 *in_RDX;
  
  *in_RDX = 0;
  in_RDX[1] = 0xc0000001;
  return;
}



===== GetUnfilteredDefaultDomainSupportedEncTypesBitmask @ 18000ac90 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual unsigned int __cdecl
   Kerb3961::CipherPolicyImpl::GetUnfilteredDefaultDomainSupportedEncTypesBitmask(void)const __ptr64
    */

uint __thiscall
Kerb3961::CipherPolicyImpl::GetUnfilteredDefaultDomainSupportedEncTypesBitmask
          (CipherPolicyImpl *this)

{
  if (this[0xc] != (CipherPolicyImpl)0x2) {
                    /* WARNING: Subroutine does not return */
    ConsistencyFail((ushort *)L"Only the domain policy has the DDSET defined");
  }
  return _g_assumedEncryptionTypes;
}



===== InitializeCiphers @ 18000acc0 =====

/* public: virtual struct Kerb3961::ReturnType<struct Kerb3961::StatusOnly,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly & __ptr64)> __cdecl
   Kerb3961::CipherPolicyImpl::InitializeCiphers(std::nullptr_t) __ptr64 */

long * __thiscall
Kerb3961::CipherPolicyImpl::InitializeCiphers(CipherPolicyImpl *this,long *param_2)

{
  int *piVar1;
  ulonglong uVar2;
  char *pcVar3;
  CipherPolicyImpl *this_00;
  int iVar4;
  longlong local_res10;
  
  wil::push_lock::acquire_exclusive((push_lock *)(this + 0x10));
  YouMustLinkWithTheWholearchiveFlag();
  *(int *)(this + 8) = *(int *)(this + 8) + 1;
  piVar1 = (int *)Kerb3961::InitializeCiphers();
  iVar4 = *piVar1;
  if (iVar4 < 0) {
    pcVar3 = "::Kerb3961::InitializeCiphers()";
  }
  else {
    this_00 = this;
    piVar1 = (int *)OrderCiphers(this);
    iVar4 = *piVar1;
    if (-1 < iVar4) {
      uVar2 = Feature_184236346__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar2 == 0) {
        uVar2 = Feature_KdcReplicationNoRc4__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar2 != 0) {
          piVar1 = (int *)UpgradeDefaults(this_00);
          iVar4 = *piVar1;
          if (iVar4 < 0) {
            pcVar3 = "UpgradeDefaults()";
            goto LAB_18000ad02;
          }
        }
      }
      *param_2 = 0;
      goto LAB_18000ad5f;
    }
    pcVar3 = "OrderCiphers()";
  }
LAB_18000ad02:
  Logging::Verify::StatusFailed(pcVar3,iVar4);
  *param_2 = iVar4;
  UninitializeCiphersNoLock(this);
LAB_18000ad5f:
  if (local_res10 != 0) {
    ExReleasePushLockExclusiveEx(local_res10,0);
    KeLeaveCriticalRegion();
  }
  return param_2;
}



===== MarshalCipherPolicies @ 18000ada0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::CipherPolicyImpl::MarshalCipherPolicies(void) __ptr64 */

void __thiscall Kerb3961::CipherPolicyImpl::MarshalCipherPolicies(CipherPolicyImpl *this)

{
  longlong *plVar1;
  undefined4 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  int *piVar5;
  _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *p_Var6;
  size_t *psVar7;
  char *pcVar8;
  longlong *in_RDX;
  size_t *psVar9;
  int iVar10;
  undefined4 *_Dst;
  long local_res8 [2];
  longlong local_res18;
  longlong local_88;
  undefined4 *local_80;
  int local_78;
  size_t *local_70;
  size_t *psStack_68;
  undefined8 local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined1 local_34;
  undefined2 local_33;
  undefined1 local_31;
  
  wil::push_lock::acquire_shared((push_lock *)(this + 0x10));
  local_58 = _g_supportedEncryptionTypes;
  local_54 = _g_assumedEncryptionTypes;
  local_50 = _g_realmEncryptionTypes;
  local_4c = _g_krbtgtEncryptionTypes;
  local_48 = _g_trustEncryptionTypes;
  local_44 = _g_defaultAssumedEncryptionTypes;
  local_40 = _g_defaultRealmEncryptionTypes;
  local_3c = _g_defaultKrbtgtEncryptionTypes;
  local_38 = _g_defaultTrustEncryptionTypes;
  uVar4 = Feature_RC4Deprecation__private_IsEnabledDeviceUsageNoInline();
  local_34 = (int)uVar4 != 0;
  local_88 = 0x28;
  local_60 = 0xffffffffffffffff;
  local_33 = 0;
  local_31 = 0;
  local_80 = &local_58;
  local_70 = (size_t *)0xffffffffffffffff;
  psStack_68 = (size_t *)0xffffffffffffffff;
  MarshaledPolicyBuilder::AddPolicy
            ((MarshaledPolicyBuilder *)&local_70,(MarshaledPolicyType)local_res8,1,
             (ReadOnlyBinary *)0x0);
  if (local_res8[0] < 0) {
    Logging::Verify::StatusFailed
              ("builder.AddGlobalPolicy({sizeof(MarshaledGlobalPolicyData), reinterpret_cast<const uint8_t*>(&globalPolicy)})"
               ,local_res8[0]);
    *in_RDX = 0;
    in_RDX[1] = 0;
    *(long *)(in_RDX + 2) = local_res8[0];
  }
  else {
    for (p_Var6 = *(_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                    **)(this + 0x28);
        p_Var6 != (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                   *)(this + 0x18);
        p_Var6 = (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                  *)utl::
                    _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                    ::_Traverse(p_Var6,true)) {
      plVar1 = *(longlong **)(p_Var6 + 0x20);
      (**(code **)(*plVar1 + 0x60))(plVar1,&local_88);
      if (local_78 < 0) {
        pcVar8 = "policy";
        iVar10 = local_78;
LAB_18000af38:
        Logging::Verify::StatusFailed(pcVar8,iVar10);
        if (local_80 != (undefined4 *)0x0) {
          operator_delete__(local_80);
        }
        pcVar8 = "builder.AddCipher(encryption.second)";
        goto LAB_18000af54;
      }
      if (local_88 != 0) {
        uVar3 = (**(code **)(*plVar1 + 0xd8))(plVar1);
        piVar5 = (int *)MarshaledPolicyBuilder::AddPolicy
                                  ((MarshaledPolicyBuilder *)&local_70,
                                   (MarshaledPolicyType)local_res8,2,
                                   (ReadOnlyBinary *)(ulonglong)uVar3);
        if (*piVar5 < 0) {
          pcVar8 = "AddPolicy(MarshaledPolicyType::Encryption, alg->CipherNumber(), policy)";
          iVar10 = *piVar5;
          goto LAB_18000af38;
        }
      }
      if (local_80 != (undefined4 *)0x0) {
        operator_delete__(local_80);
      }
    }
    for (p_Var6 = *(_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                    **)(this + 0x48); psVar9 = local_70,
        p_Var6 != (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                   *)(this + 0x38);
        p_Var6 = (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                  *)utl::
                    _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                    ::_Traverse(p_Var6,true)) {
      plVar1 = *(longlong **)(p_Var6 + 0x20);
      (**(code **)(*plVar1 + 0x48))(plVar1,&local_88);
      if (local_78 < 0) {
        pcVar8 = "policy";
        iVar10 = local_78;
LAB_18000b000:
        Logging::Verify::StatusFailed(pcVar8,iVar10);
        if (local_80 != (undefined4 *)0x0) {
          operator_delete__(local_80);
        }
        pcVar8 = "builder.AddChecksum(checksum.second)";
LAB_18000af54:
        Logging::Verify::StatusFailed(pcVar8,iVar10);
        *in_RDX = 0;
        in_RDX[1] = 0;
        local_78 = iVar10;
        goto LAB_18000b0ac;
      }
      if (local_88 != 0) {
        uVar3 = (**(code **)(*plVar1 + 0x68))(plVar1);
        piVar5 = (int *)MarshaledPolicyBuilder::AddPolicy
                                  ((MarshaledPolicyBuilder *)&local_70,
                                   (MarshaledPolicyType)local_res8,3,
                                   (ReadOnlyBinary *)(ulonglong)uVar3);
        if (*piVar5 < 0) {
          pcVar8 = "AddPolicy(MarshaledPolicyType::Checksum, alg->ChecksumNumber(), policy)";
          iVar10 = *piVar5;
          goto LAB_18000b000;
        }
      }
      if (local_80 != (undefined4 *)0x0) {
        operator_delete__(local_80);
      }
    }
    for (psVar7 = local_70; psVar7 != psStack_68; psVar7 = psVar7 + 3) {
    }
    MakeBuffer((__uint64)&local_88);
    puVar2 = local_80;
    if (local_78 < 0) {
      Logging::Verify::StatusFailed("result",local_78);
      *in_RDX = 0;
      in_RDX[1] = 0;
      *(int *)(in_RDX + 2) = local_78;
      if (local_80 != (undefined4 *)0x0) {
        operator_delete__(local_80);
      }
    }
    else {
      _Dst = local_80;
      for (; psVar9 != psStack_68; psVar9 = psVar9 + 3) {
        memmove(_Dst,(void *)psVar9[1],*psVar9);
        _Dst = (undefined4 *)((longlong)_Dst + *psVar9);
      }
      if (_Dst != (undefined4 *)(local_88 + (longlong)puVar2)) {
                    /* WARNING: Subroutine does not return */
        ConsistencyFail((ushort *)L"Incorrect length calculated in GetMarsheldPolicy");
      }
      *in_RDX = local_88;
      in_RDX[1] = (longlong)puVar2;
LAB_18000b0ac:
      *(int *)(in_RDX + 2) = local_78;
    }
  }
  utl::
  vector<Kerb3961::ReturnType<Kerb3961::OwnedBinary,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary&___ptr64)>,utl::allocator<Kerb3961::ReturnType<Kerb3961::OwnedBinary,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary&___ptr64)>_>_>
  ::_Uninit((vector<Kerb3961::ReturnType<Kerb3961::OwnedBinary,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary&___ptr64)>,utl::allocator<Kerb3961::ReturnType<Kerb3961::OwnedBinary,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary&___ptr64)>_>_>
             *)&local_70);
  if (local_res18 != 0) {
    ExReleasePushLockSharedEx(local_res18,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== OpenChecksumById @ 18000b110 =====

/* public: virtual struct Kerb3961::ReturnType<struct Kerb3961::ResultAdapter<struct
   Kerb3961::ChecksumAlgorithm * __ptr64>,&struct Kerb3961::ResultBlock const & __ptr64 __cdecl
   Kerb3961::SingleGetter<struct Kerb3961::ResultAdapter<struct Kerb3961::ChecksumAlgorithm *
   __ptr64>,8>(struct Kerb3961::ResultAdapter<struct Kerb3961::ChecksumAlgorithm * __ptr64> const &
   __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::ResultAdapter<struct Kerb3961::ChecksumAlgorithm * __ptr64>,8>(struct
   Kerb3961::ResultAdapter<struct Kerb3961::ChecksumAlgorithm * __ptr64> & __ptr64)> __cdecl
   Kerb3961::CipherPolicyImpl::OpenChecksumById(unsigned int,enum Kerb3961::KeyUsage,struct
   Kerb3961::CipherPartnerHandle const & __ptr64,struct Kerb3961::CipherPartnerHandle const &
   __ptr64)const __ptr64 */

undefined8 * __thiscall
Kerb3961::CipherPolicyImpl::OpenChecksumById
          (CipherPolicyImpl *this,uint param_1,KeyUsage param_2,CipherPartnerHandle *param_3,
          CipherPartnerHandle *param_4)

{
  long lVar1;
  undefined *puVar2;
  long *plVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  undefined4 in_register_00000014;
  undefined8 *puVar6;
  longlong lVar7;
  char local_38 [4];
  KeyUsage local_34;
  char local_2f;
  longlong local_28;
  
  puVar6 = (undefined8 *)CONCAT44(in_register_00000014,param_1);
  plVar3 = (long *)CheckKeyUsage(&local_34);
  lVar1 = *plVar3;
  if (lVar1 < 0) {
    Logging::Verify::StatusFailed("CheckKeyUsage(keyUsage)",lVar1);
    *puVar6 = 0;
    *(long *)(puVar6 + 1) = lVar1;
    return puVar6;
  }
  EnsureInitialization(this,(KeyUsage)local_38);
  wil::push_lock::acquire_shared((push_lock *)&g_cipherLock);
  if (DAT_180018340 != &g_checksums) {
    ppuVar5 = &g_checksums;
    ppuVar4 = (undefined **)g_checksums;
    do {
      if (*(KeyUsage *)(ppuVar4 + 3) < param_2) {
        lVar7 = 0x10;
      }
      else {
        lVar7 = 8;
        ppuVar5 = ppuVar4;
      }
      ppuVar4 = *(undefined ***)((longlong)ppuVar4 + lVar7);
    } while (ppuVar4 != &utl::_TreeSentinel);
    if ((ppuVar5 != &g_checksums) && (*(KeyUsage *)(ppuVar5 + 3) <= param_2)) {
      puVar2 = ppuVar5[4];
      if (param_3 == (CipherPartnerHandle *)0x8000000000000000) {
        *(undefined4 *)(puVar6 + 1) = 0;
        *puVar6 = puVar2;
      }
      else {
        GetScenarioForKeyUsage((KeyUsage)&local_34);
        if (local_2f == '\0') {
          Logging::Verify::ConditionFailed("scenarioOpt.has_value()");
          *puVar6 = 0;
          *(undefined4 *)(puVar6 + 1) = 0xc000000d;
        }
        else {
          Logging::Verify::StatusFailed("ChecksumEnabledForUs(checksum, keyScenario)",-0x3fffffff);
          *puVar6 = 0;
          *(undefined4 *)(puVar6 + 1) = 0xc0000001;
        }
      }
      goto LAB_18000b237;
    }
  }
  *puVar6 = 0;
  *(undefined4 *)(puVar6 + 1) = 0xc00002fd;
LAB_18000b237:
  if (local_28 != 0) {
    ExReleasePushLockSharedEx(local_28,0);
    KeLeaveCriticalRegion();
  }
  if (local_38[0] != '\0') {
    Kerb3961::UninitializeCiphers();
  }
  return puVar6;
}



===== OpenEncryptionById @ 18000b290 =====

/* public: virtual struct Kerb3961::ReturnType<struct Kerb3961::ResultAdapter<struct
   Kerb3961::EncryptionAlgorithm * __ptr64>,&struct Kerb3961::ResultBlock const & __ptr64 __cdecl
   Kerb3961::SingleGetter<struct Kerb3961::ResultAdapter<struct Kerb3961::EncryptionAlgorithm *
   __ptr64>,8>(struct Kerb3961::ResultAdapter<struct Kerb3961::EncryptionAlgorithm * __ptr64> const
   & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::ResultAdapter<struct Kerb3961::EncryptionAlgorithm * __ptr64>,8>(struct
   Kerb3961::ResultAdapter<struct Kerb3961::EncryptionAlgorithm * __ptr64> & __ptr64)> __cdecl
   Kerb3961::CipherPolicyImpl::OpenEncryptionById(unsigned int,enum Kerb3961::KeyUsage,struct
   Kerb3961::CipherPartnerHandle const & __ptr64,struct Kerb3961::CipherPartnerHandle const &
   __ptr64)const __ptr64 */

undefined8 * __thiscall
Kerb3961::CipherPolicyImpl::OpenEncryptionById
          (CipherPolicyImpl *this,uint param_1,KeyUsage param_2,CipherPartnerHandle *param_3,
          CipherPartnerHandle *param_4)

{
  long lVar1;
  undefined *puVar2;
  long *plVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  undefined4 in_register_00000014;
  undefined8 *puVar6;
  longlong lVar7;
  char local_38 [4];
  KeyUsage local_34;
  char local_2f;
  longlong local_28;
  
  puVar6 = (undefined8 *)CONCAT44(in_register_00000014,param_1);
  plVar3 = (long *)CheckKeyUsage(&local_34);
  lVar1 = *plVar3;
  if (lVar1 < 0) {
    Logging::Verify::StatusFailed("CheckKeyUsage(keyUsage)",lVar1);
    *puVar6 = 0;
    *(long *)(puVar6 + 1) = lVar1;
    return puVar6;
  }
  EnsureInitialization(this,(KeyUsage)local_38);
  wil::push_lock::acquire_shared((push_lock *)&g_cipherLock);
  if (DAT_180018320 != &g_encryptions) {
    ppuVar5 = &g_encryptions;
    ppuVar4 = (undefined **)g_encryptions;
    do {
      if (*(KeyUsage *)(ppuVar4 + 3) < param_2) {
        lVar7 = 0x10;
      }
      else {
        lVar7 = 8;
        ppuVar5 = ppuVar4;
      }
      ppuVar4 = *(undefined ***)((longlong)ppuVar4 + lVar7);
    } while (ppuVar4 != &utl::_TreeSentinel);
    if ((ppuVar5 != &g_encryptions) && (*(KeyUsage *)(ppuVar5 + 3) <= param_2)) {
      puVar2 = ppuVar5[4];
      if (param_3 == (CipherPartnerHandle *)0x8000000000000000) {
        *(undefined4 *)(puVar6 + 1) = 0;
        *puVar6 = puVar2;
      }
      else {
        GetScenarioForKeyUsage((KeyUsage)&local_34);
        if (local_2f == '\0') {
          Logging::Verify::ConditionFailed("scenarioOpt.has_value()");
          *puVar6 = 0;
          *(undefined4 *)(puVar6 + 1) = 0xc000000d;
        }
        else {
          Logging::Verify::StatusFailed("CipherEnabledForUs(encryption, keyScenario)",-0x3fffffff);
          *puVar6 = 0;
          *(undefined4 *)(puVar6 + 1) = 0xc0000001;
        }
      }
      goto LAB_18000b3b7;
    }
  }
  *puVar6 = 0;
  *(undefined4 *)(puVar6 + 1) = 0xc00002fd;
LAB_18000b3b7:
  if (local_28 != 0) {
    ExReleasePushLockSharedEx(local_28,0);
    KeLeaveCriticalRegion();
  }
  if (local_38[0] != '\0') {
    Kerb3961::UninitializeCiphers();
  }
  return puVar6;
}



===== OrderCiphers @ 18000b404 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: struct Kerb3961::ReturnType<struct Kerb3961::StatusOnly,&struct Kerb3961::ResultBlock
   const & __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::StatusOnly,0>(struct
   Kerb3961::StatusOnly const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly & __ptr64)>
   __cdecl Kerb3961::CipherPolicyImpl::OrderCiphers(void) __ptr64 */

void __thiscall Kerb3961::CipherPolicyImpl::OrderCiphers(CipherPolicyImpl *this)

{
  CipherPolicyImpl *pCVar1;
  undefined8 ***pppuVar2;
  undefined8 uVar3;
  CipherPolicyImpl *pCVar4;
  undefined8 ***pppuVar5;
  undefined8 ***pppuVar6;
  _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *p_Var7;
  undefined4 *in_RDX;
  uint local_res18 [2];
  longlong local_res20;
  longlong local_78;
  char local_70;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined8 ***local_58;
  undefined8 ***pppuStack_50;
  undefined8 ***local_48;
  undefined8 local_40;
  undefined8 ***local_38;
  undefined8 ***pppuStack_30;
  undefined8 ***local_28;
  undefined8 local_20;
  
  wil::push_lock::acquire_exclusive((push_lock *)&g_cipherLock);
  local_40 = 0;
  local_58 = &local_58;
  pppuStack_50 = &local_58;
  local_48 = pppuStack_50;
  for (p_Var7 = DAT_180018320;
      p_Var7 != (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                 *)&g_encryptions;
      p_Var7 = (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                *)utl::
                  _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                  ::_Traverse(p_Var7,true)) {
    local_68 = *(undefined4 *)(p_Var7 + 0x18);
    uStack_64 = *(undefined4 *)(p_Var7 + 0x1c);
    uStack_60 = *(undefined4 *)(p_Var7 + 0x20);
    uStack_5c = *(undefined4 *)(p_Var7 + 0x24);
    local_res18[0] = (**(code **)(**(longlong **)(p_Var7 + 0x20) + 0x40))();
    local_res18[0] = ~local_res18[0];
    utl::
    map<unsigned_int,Kerb3961::EncryptionAlgorithm*___ptr64,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>_>
    ::try_emplace<Kerb3961::EncryptionAlgorithm*___ptr64&___ptr64,0>
              ((map<unsigned_int,Kerb3961::EncryptionAlgorithm*___ptr64,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>_>
                *)&local_58,(uint *)&local_78,(EncryptionAlgorithm **)local_res18);
    if (local_78 == 0) {
      Logging::Verify::ConditionFailed("pos != nullptr");
      *in_RDX = 0xc0000017;
      goto LAB_18000b6bc;
    }
    if (local_70 == '\0') {
      Logging::Verify::ConditionFailed("inserted");
      *in_RDX = 0xc0000035;
      goto LAB_18000b6bc;
    }
  }
  local_20 = 0;
  local_38 = &local_38;
  pppuStack_30 = &local_38;
  p_Var7 = DAT_180018340;
  local_28 = pppuStack_30;
  do {
    if (p_Var7 == (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                   *)&g_checksums) {
      pCVar1 = this + 0x18;
      pppuVar5 = *(undefined8 ****)pCVar1;
      pppuVar6 = *(undefined8 ****)(this + 0x20);
      uVar3 = *(undefined8 *)(this + 0x30);
      pppuVar2 = *(undefined8 ****)(this + 0x28);
      pCVar4 = *(CipherPolicyImpl **)(this + 0x28);
      if ((undefined8 ****)local_48 == &local_58) {
        *(CipherPolicyImpl **)pCVar1 = pCVar1;
        local_40 = 0;
        *(CipherPolicyImpl **)(this + 0x20) = pCVar1;
        *(CipherPolicyImpl **)(this + 0x28) = pCVar1;
      }
      else {
        *(ulonglong *)((ulonglong)local_58 & 0xfffffffffffffffe) = (ulonglong)pCVar1 | 1;
        *(undefined8 ****)pCVar1 = local_58;
        *(undefined8 ****)(this + 0x20) = pppuStack_50;
        *(undefined8 ****)(this + 0x28) = local_48;
      }
      *(undefined8 *)(this + 0x30) = local_40;
      if (pCVar4 == pCVar1) {
        local_40 = 0;
        local_58 = &local_58;
        pppuStack_50 = &local_58;
        local_48 = &local_58;
      }
      else {
        *(ulonglong *)((ulonglong)pppuVar5 & 0xfffffffffffffffe) = (ulonglong)&local_58 | 1;
        local_58 = pppuVar5;
        pppuStack_50 = pppuVar6;
        local_48 = pppuVar2;
        local_40 = uVar3;
      }
      pCVar1 = this + 0x38;
      pppuVar5 = *(undefined8 ****)pCVar1;
      pppuVar6 = *(undefined8 ****)(this + 0x40);
      uVar3 = *(undefined8 *)(this + 0x50);
      pppuVar2 = *(undefined8 ****)(this + 0x48);
      pCVar4 = *(CipherPolicyImpl **)(this + 0x48);
      if ((undefined8 ****)local_28 == &local_38) {
        *(CipherPolicyImpl **)pCVar1 = pCVar1;
        local_20 = 0;
        *(CipherPolicyImpl **)(this + 0x40) = pCVar1;
        *(CipherPolicyImpl **)(this + 0x48) = pCVar1;
      }
      else {
        *(ulonglong *)((ulonglong)local_38 & 0xfffffffffffffffe) = (ulonglong)pCVar1 | 1;
        *(undefined8 ****)pCVar1 = local_38;
        *(undefined8 ****)(this + 0x40) = pppuStack_30;
        *(undefined8 ****)(this + 0x48) = local_28;
      }
      *(undefined8 *)(this + 0x50) = local_20;
      if (pCVar4 == pCVar1) {
        local_20 = 0;
        local_38 = &local_38;
        pppuStack_30 = &local_38;
        local_28 = &local_38;
      }
      else {
        *(ulonglong *)((ulonglong)pppuVar5 & 0xfffffffffffffffe) = (ulonglong)&local_38 | 1;
        local_38 = pppuVar5;
        pppuStack_30 = pppuVar6;
        local_28 = pppuVar2;
        local_20 = uVar3;
      }
      *in_RDX = 0;
LAB_18000b6b3:
      utl::
      _Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
      ::
      ~_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
                ((_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
                  *)&local_38);
LAB_18000b6bc:
      utl::
      _Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
      ::
      ~_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
                ((_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
                  *)&local_58);
      if (local_res20 != 0) {
        ExReleasePushLockExclusiveEx(local_res20,0);
        KeLeaveCriticalRegion();
      }
      return;
    }
    local_68 = *(undefined4 *)(p_Var7 + 0x18);
    uStack_64 = *(undefined4 *)(p_Var7 + 0x1c);
    uStack_60 = *(undefined4 *)(p_Var7 + 0x20);
    uStack_5c = *(undefined4 *)(p_Var7 + 0x24);
    local_res18[0] = (**(code **)(**(longlong **)(p_Var7 + 0x20) + 0x28))();
    local_res18[0] = ~local_res18[0];
    utl::
    map<unsigned_int,Kerb3961::EncryptionAlgorithm*___ptr64,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>_>
    ::try_emplace<Kerb3961::EncryptionAlgorithm*___ptr64&___ptr64,0>
              ((map<unsigned_int,Kerb3961::EncryptionAlgorithm*___ptr64,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>_>
                *)&local_38,(uint *)&local_78,(EncryptionAlgorithm **)local_res18);
    if (local_78 == 0) {
      Logging::Verify::ConditionFailed("pos != nullptr");
      *in_RDX = 0xc0000017;
      goto LAB_18000b6b3;
    }
    if (local_70 == '\0') {
      Logging::Verify::ConditionFailed("inserted");
      *in_RDX = 0xc0000035;
      goto LAB_18000b6b3;
    }
    p_Var7 = (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
              *)utl::
                _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                ::_Traverse(p_Var7,true);
  } while( true );
}



===== RehydrateChecksum @ 18000b710 =====

/* public: virtual struct Kerb3961::ReturnType<struct Kerb3961::ResultAdapter<struct
   Kerb3961::ChecksumAlgorithm * __ptr64>,&struct Kerb3961::ResultBlock const & __ptr64 __cdecl
   Kerb3961::SingleGetter<struct Kerb3961::ResultAdapter<struct Kerb3961::ChecksumAlgorithm *
   __ptr64>,8>(struct Kerb3961::ResultAdapter<struct Kerb3961::ChecksumAlgorithm * __ptr64> const &
   __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::ResultAdapter<struct Kerb3961::ChecksumAlgorithm * __ptr64>,8>(struct
   Kerb3961::ResultAdapter<struct Kerb3961::ChecksumAlgorithm * __ptr64> & __ptr64)> __cdecl
   Kerb3961::CipherPolicyImpl::RehydrateChecksum(unsigned int,enum Kerb3961::KeyUsage)const __ptr64
    */

undefined8 * __thiscall
Kerb3961::CipherPolicyImpl::RehydrateChecksum(CipherPolicyImpl *this,uint param_1,KeyUsage param_2)

{
  long lVar1;
  undefined *puVar2;
  long *plVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  undefined4 in_register_00000014;
  undefined8 *puVar6;
  longlong lVar7;
  longlong in_R9;
  char local_38 [4];
  KeyUsage local_34;
  char local_2f;
  longlong local_28;
  
  puVar6 = (undefined8 *)CONCAT44(in_register_00000014,param_1);
  plVar3 = (long *)CheckKeyUsage(&local_34);
  lVar1 = *plVar3;
  if (lVar1 < 0) {
    Logging::Verify::StatusFailed("CheckKeyUsage(keyUsage)",lVar1);
    *puVar6 = 0;
    *(long *)(puVar6 + 1) = lVar1;
    return puVar6;
  }
  EnsureInitialization(this,(KeyUsage)local_38);
  wil::push_lock::acquire_shared((push_lock *)&g_cipherLock);
  if (DAT_180018340 != &g_checksums) {
    ppuVar5 = &g_checksums;
    ppuVar4 = (undefined **)g_checksums;
    do {
      if (*(KeyUsage *)(ppuVar4 + 3) < param_2) {
        lVar7 = 0x10;
      }
      else {
        lVar7 = 8;
        ppuVar5 = ppuVar4;
      }
      ppuVar4 = *(undefined ***)((longlong)ppuVar4 + lVar7);
    } while (ppuVar4 != &utl::_TreeSentinel);
    if ((ppuVar5 != &g_checksums) && (*(KeyUsage *)(ppuVar5 + 3) <= param_2)) {
      puVar2 = ppuVar5[4];
      if (in_R9 == -0x8000000000000000) {
        *(undefined4 *)(puVar6 + 1) = 0;
        *puVar6 = puVar2;
      }
      else {
        GetScenarioForKeyUsage((KeyUsage)&local_34);
        if (local_2f == '\0') {
          Logging::Verify::ConditionFailed("scenarioOpt.has_value()");
          *puVar6 = 0;
          *(undefined4 *)(puVar6 + 1) = 0xc000000d;
        }
        else {
          Logging::Verify::StatusFailed("ChecksumEnabledForUs(checksum, keyScenario)",-0x3fffffff);
          *puVar6 = 0;
          *(undefined4 *)(puVar6 + 1) = 0xc0000001;
        }
      }
      goto LAB_18000b837;
    }
  }
  *puVar6 = 0;
  *(undefined4 *)(puVar6 + 1) = 0xc00002fd;
LAB_18000b837:
  if (local_28 != 0) {
    ExReleasePushLockSharedEx(local_28,0);
    KeLeaveCriticalRegion();
  }
  if (local_38[0] != '\0') {
    Kerb3961::UninitializeCiphers();
  }
  return puVar6;
}



===== RehydrateEncryption @ 18000b890 =====

/* public: virtual struct Kerb3961::ReturnType<struct Kerb3961::ResultAdapter<struct
   Kerb3961::EncryptionAlgorithm * __ptr64>,&struct Kerb3961::ResultBlock const & __ptr64 __cdecl
   Kerb3961::SingleGetter<struct Kerb3961::ResultAdapter<struct Kerb3961::EncryptionAlgorithm *
   __ptr64>,8>(struct Kerb3961::ResultAdapter<struct Kerb3961::EncryptionAlgorithm * __ptr64> const
   & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::ResultAdapter<struct Kerb3961::EncryptionAlgorithm * __ptr64>,8>(struct
   Kerb3961::ResultAdapter<struct Kerb3961::EncryptionAlgorithm * __ptr64> & __ptr64)> __cdecl
   Kerb3961::CipherPolicyImpl::RehydrateEncryption(unsigned int,enum Kerb3961::KeyUsage)const
   __ptr64 */

undefined8 * __thiscall
Kerb3961::CipherPolicyImpl::RehydrateEncryption
          (CipherPolicyImpl *this,uint param_1,KeyUsage param_2)

{
  long lVar1;
  undefined *puVar2;
  long *plVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  undefined4 in_register_00000014;
  undefined8 *puVar6;
  longlong lVar7;
  longlong in_R9;
  char local_38 [4];
  KeyUsage local_34;
  char local_2f;
  longlong local_28;
  
  puVar6 = (undefined8 *)CONCAT44(in_register_00000014,param_1);
  plVar3 = (long *)CheckKeyUsage(&local_34);
  lVar1 = *plVar3;
  if (lVar1 < 0) {
    Logging::Verify::StatusFailed("CheckKeyUsage(keyUsage)",lVar1);
    *puVar6 = 0;
    *(long *)(puVar6 + 1) = lVar1;
    return puVar6;
  }
  EnsureInitialization(this,(KeyUsage)local_38);
  wil::push_lock::acquire_shared((push_lock *)&g_cipherLock);
  if (DAT_180018320 != &g_encryptions) {
    ppuVar5 = &g_encryptions;
    ppuVar4 = (undefined **)g_encryptions;
    do {
      if (*(KeyUsage *)(ppuVar4 + 3) < param_2) {
        lVar7 = 0x10;
      }
      else {
        lVar7 = 8;
        ppuVar5 = ppuVar4;
      }
      ppuVar4 = *(undefined ***)((longlong)ppuVar4 + lVar7);
    } while (ppuVar4 != &utl::_TreeSentinel);
    if ((ppuVar5 != &g_encryptions) && (*(KeyUsage *)(ppuVar5 + 3) <= param_2)) {
      puVar2 = ppuVar5[4];
      if (in_R9 == -0x8000000000000000) {
        *(undefined4 *)(puVar6 + 1) = 0;
        *puVar6 = puVar2;
      }
      else {
        GetScenarioForKeyUsage((KeyUsage)&local_34);
        if (local_2f == '\0') {
          Logging::Verify::ConditionFailed("scenarioOpt.has_value()");
          *puVar6 = 0;
          *(undefined4 *)(puVar6 + 1) = 0xc000000d;
        }
        else {
          Logging::Verify::StatusFailed("CipherEnabledForUs(encryption, keyScenario)",-0x3fffffff);
          *puVar6 = 0;
          *(undefined4 *)(puVar6 + 1) = 0xc0000001;
        }
      }
      goto LAB_18000b9b7;
    }
  }
  *puVar6 = 0;
  *(undefined4 *)(puVar6 + 1) = 0xc00002fd;
LAB_18000b9b7:
  if (local_28 != 0) {
    ExReleasePushLockSharedEx(local_28,0);
    KeLeaveCriticalRegion();
  }
  if (local_38[0] != '\0') {
    Kerb3961::UninitializeCiphers();
  }
  return puVar6;
}



===== ReloadCipherPolicies @ 18000ba10 =====

/* public: virtual struct Kerb3961::ReturnType<struct Kerb3961::StatusOnly,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly & __ptr64)> __cdecl
   Kerb3961::CipherPolicyImpl::ReloadCipherPolicies(std::nullptr_t) __ptr64 */

long * __thiscall
Kerb3961::CipherPolicyImpl::ReloadCipherPolicies(CipherPolicyImpl *this,long *param_2)

{
  int *piVar1;
  ulonglong uVar2;
  char *pcVar3;
  int iVar4;
  longlong local_res20;
  
  wil::push_lock::acquire_exclusive((push_lock *)(this + 0x10));
  piVar1 = (int *)OrderCiphers(this);
  iVar4 = *piVar1;
  if (iVar4 < 0) {
    pcVar3 = "OrderCiphers()";
LAB_18000ba48:
    Logging::Verify::StatusFailed(pcVar3,iVar4);
    *param_2 = iVar4;
  }
  else {
    uVar2 = Feature_184236346__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar2 == 0) {
      uVar2 = Feature_KdcReplicationNoRc4__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar2 != 0) {
        piVar1 = (int *)UpgradeDefaults(this);
        iVar4 = *piVar1;
        if (iVar4 < 0) {
          pcVar3 = "UpgradeDefaults()";
          goto LAB_18000ba48;
        }
      }
    }
    *param_2 = 0;
  }
  if (local_res20 != 0) {
    ExReleasePushLockExclusiveEx(local_res20,0);
    KeLeaveCriticalRegion();
  }
  return param_2;
}



===== RunningIsolated @ 18000bac0 =====

/* public: virtual void __cdecl Kerb3961::CipherPolicyImpl::RunningIsolated(void) __ptr64 */

void __thiscall Kerb3961::CipherPolicyImpl::RunningIsolated(CipherPolicyImpl *this)

{
  this[0xc] = (CipherPolicyImpl)((byte)this[0xc] | 4);
  return;
}



===== SelectCipher @ 18000bad0 =====

/* public: virtual struct Kerb3961::ReturnType<struct Kerb3961::ResultAdapter<struct
   Kerb3961::EncryptionAlgorithm * __ptr64>,&struct Kerb3961::ResultBlock const & __ptr64 __cdecl
   Kerb3961::SingleGetter<struct Kerb3961::ResultAdapter<struct Kerb3961::EncryptionAlgorithm *
   __ptr64>,8>(struct Kerb3961::ResultAdapter<struct Kerb3961::EncryptionAlgorithm * __ptr64> const
   & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::ResultAdapter<struct Kerb3961::EncryptionAlgorithm * __ptr64>,8>(struct
   Kerb3961::ResultAdapter<struct Kerb3961::EncryptionAlgorithm * __ptr64> & __ptr64)> __cdecl
   Kerb3961::CipherPolicyImpl::SelectCipher(enum Kerb3961::KeyUsage,struct
   Kerb3961::CipherPartnerHandle const & __ptr64,struct Kerb3961::CipherPartnerHandle const &
   __ptr64)const __ptr64 */

undefined8 __thiscall
Kerb3961::CipherPolicyImpl::SelectCipher
          (CipherPolicyImpl *this,KeyUsage param_1,CipherPartnerHandle *param_2,
          CipherPartnerHandle *param_3)

{
  undefined4 in_register_00000014;
  
  *(undefined8 *)CONCAT44(in_register_00000014,param_1) = 0;
  *(undefined4 *)(CONCAT44(in_register_00000014,param_1) + 8) = 0xc0000001;
  return CONCAT44(in_register_00000014,param_1);
}



===== UninitializeCiphers @ 18000baf0 =====

/* public: virtual void __cdecl Kerb3961::CipherPolicyImpl::UninitializeCiphers(void) __ptr64 */

void __thiscall Kerb3961::CipherPolicyImpl::UninitializeCiphers(CipherPolicyImpl *this)

{
  longlong local_res8;
  
  wil::push_lock::acquire_exclusive((push_lock *)(this + 0x10));
  UninitializeCiphersNoLock(this);
  if (local_res8 != 0) {
    ExReleasePushLockExclusiveEx(local_res8,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== UninitializeCiphersNoLock @ 18000bb40 =====

/* public: void __cdecl Kerb3961::CipherPolicyImpl::UninitializeCiphersNoLock(void) __ptr64 */

void __thiscall Kerb3961::CipherPolicyImpl::UninitializeCiphersNoLock(CipherPolicyImpl *this)

{
  CipherPolicyImpl *pCVar1;
  CipherPolicyImpl *pCVar2;
  CipherPolicyImpl *pCVar3;
  
  if (*(int *)(this + 8) == 0) {
                    /* WARNING: Subroutine does not return */
    ConsistencyFail((ushort *)L"Mismatched calls to LocalCipherPolicy\'s init and uninit");
  }
  *(int *)(this + 8) = *(int *)(this + 8) + -1;
  Kerb3961::UninitializeCiphers();
  if (*(int *)(this + 8) == 0) {
    pCVar1 = this + 0x18;
    pCVar2 = *(CipherPolicyImpl **)(this + 0x28);
    if (*(CipherPolicyImpl **)(this + 0x28) != pCVar1) {
      do {
        while (*(CipherPolicyImpl **)(pCVar2 + 8) != (CipherPolicyImpl *)&utl::_TreeSentinel) {
          pCVar2 = *(CipherPolicyImpl **)(pCVar2 + 8);
        }
        while (pCVar3 = pCVar2, *(void ***)(pCVar2 + 0x10) == &utl::_TreeSentinel) {
          do {
            pCVar2 = (CipherPolicyImpl *)((ulonglong)*(void **)pCVar3 & 0xfffffffffffffffe);
            operator_delete__(pCVar3);
            if (pCVar2 == pCVar1) {
              *(CipherPolicyImpl **)pCVar1 = pCVar1;
              *(CipherPolicyImpl **)(this + 0x20) = pCVar1;
              *(CipherPolicyImpl **)(this + 0x28) = pCVar1;
              *(undefined8 *)(this + 0x30) = 0;
              goto LAB_18000bbd2;
            }
            pCVar3 = pCVar2;
          } while (*(void ***)(pCVar2 + 8) == &utl::_TreeSentinel);
          *(void ***)(pCVar2 + 8) = &utl::_TreeSentinel;
        }
        pCVar2 = *(CipherPolicyImpl **)(pCVar2 + 0x10);
      } while( true );
    }
LAB_18000bbd2:
    pCVar1 = this + 0x38;
    pCVar2 = *(CipherPolicyImpl **)(this + 0x48);
    if (*(CipherPolicyImpl **)(this + 0x48) != pCVar1) {
      do {
        while (*(CipherPolicyImpl **)(pCVar2 + 8) != (CipherPolicyImpl *)&utl::_TreeSentinel) {
          pCVar2 = *(CipherPolicyImpl **)(pCVar2 + 8);
        }
        while (pCVar3 = pCVar2, *(void ***)(pCVar2 + 0x10) == &utl::_TreeSentinel) {
          do {
            pCVar2 = (CipherPolicyImpl *)((ulonglong)*(void **)pCVar3 & 0xfffffffffffffffe);
            operator_delete__(pCVar3);
            if (pCVar2 == pCVar1) {
              *(CipherPolicyImpl **)pCVar1 = pCVar1;
              *(CipherPolicyImpl **)(this + 0x40) = pCVar1;
              *(CipherPolicyImpl **)(this + 0x48) = pCVar1;
              *(undefined8 *)(this + 0x50) = 0;
              return;
            }
            pCVar3 = pCVar2;
          } while (*(void ***)(pCVar2 + 8) == &utl::_TreeSentinel);
          *(void ***)(pCVar2 + 8) = &utl::_TreeSentinel;
        }
        pCVar2 = *(CipherPolicyImpl **)(pCVar2 + 0x10);
      } while( true );
    }
  }
  return;
}



===== UpgradeDefaults @ 18000bc50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: struct Kerb3961::ReturnType<struct Kerb3961::StatusOnly,&struct Kerb3961::ResultBlock
   const & __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::StatusOnly,0>(struct
   Kerb3961::StatusOnly const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly & __ptr64)>
   __cdecl Kerb3961::CipherPolicyImpl::UpgradeDefaults(void) __ptr64 */

void __thiscall Kerb3961::CipherPolicyImpl::UpgradeDefaults(CipherPolicyImpl *this)

{
  EncryptionTypeBitmask *pEVar1;
  undefined4 *in_RDX;
  EncryptionTypeBitmask **ppEVar2;
  undefined1 auStack_88 [32];
  uint local_68;
  longlong local_60;
  EncryptionTypeBitmask *local_58;
  undefined8 local_50;
  EncryptionTypeBitmask *local_48;
  undefined8 local_40;
  EncryptionTypeBitmask *local_38;
  undefined8 local_30;
  EncryptionTypeBitmask *local_28;
  undefined8 local_20;
  EncryptionTypeBitmask *local_18 [2];
  
  local_18[0] = (EncryptionTypeBitmask *)(__security_cookie ^ (ulonglong)auStack_88);
  wil::push_lock::acquire_exclusive((push_lock *)&g_cipherLock);
  local_50 = 0x24;
  local_58 = &g_defaultAssumedEncryptionTypes;
  ppEVar2 = &local_58;
  local_40 = 0x1c;
  local_48 = &g_defaultRealmEncryptionTypes;
  local_38 = &g_defaultKrbtgtEncryptionTypes;
  local_28 = &g_defaultTrustEncryptionTypes;
  local_30 = 0x18;
  local_20 = 0x1c;
  do {
    local_68 = *(uint *)(ppEVar2 + 1);
    if (((byte)g_supportedEncryptionTypes & 4) == 0) {
      local_68 = local_68 | 0x18;
    }
    pEVar1 = *ppEVar2;
    ppEVar2 = ppEVar2 + 2;
    *(uint *)pEVar1 = local_68;
  } while (ppEVar2 != local_18);
  *in_RDX = 0;
  if (local_60 != 0) {
    ExReleasePushLockExclusiveEx(local_60,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== YouMustLinkWithTheWholearchiveFlag @ 18000bd48 =====

/* void __cdecl Kerb3961::YouMustLinkWithTheWholearchiveFlag(void) */

void __cdecl Kerb3961::YouMustLinkWithTheWholearchiveFlag(void)

{
  if (g_dynamicInitializationDone) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ConsistencyFail((ushort *)L"You must pass the /WHOLEARCHIVE flag to the linker");
}



===== _InsertAt @ 18000bd70 =====

/* private: void __cdecl utl::_Tree<unsigned int,struct utl::pair<unsigned int const ,struct
   Kerb3961::EncryptionAlgorithm * __ptr64>,struct utl::less<unsigned int>,class
   utl::allocator<struct utl::pair<unsigned int const ,struct Kerb3961::EncryptionAlgorithm *
   __ptr64> >,0>::_InsertAt(struct utl::pair<struct utl::_TreeNode<struct utl::pair<unsigned int
   const ,struct Kerb3961::EncryptionAlgorithm * __ptr64> > * __ptr64,bool> const & __ptr64,struct
   utl::_TreeNode<struct utl::pair<unsigned int const ,struct Kerb3961::EncryptionAlgorithm *
   __ptr64> > * __ptr64) __ptr64 */

void __thiscall
utl::
_Tree<unsigned_int,utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>,0>
::_InsertAt(_Tree<unsigned_int,utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>,0>
            *this,pair<utl::_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>*___ptr64,bool>
                  *param_1,
           _TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
           *param_2)

{
  pair<utl::_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>*___ptr64,bool>
  pVar1;
  _Tree<unsigned_int,utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>,0>
  *p_Var2;
  byte *pbVar3;
  ulonglong *puVar4;
  longlong lVar5;
  _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *this_00;
  ulonglong uVar6;
  _Tree<unsigned_int,utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>,0>
  *p_Var7;
  
  p_Var7 = *(_Tree<unsigned_int,utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>,0>
             **)param_1;
  pVar1 = param_1[8];
  *(_Tree<unsigned_int,utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>,0>
    **)param_2 = p_Var7;
  *(void ***)(param_2 + 8) = &_TreeSentinel;
  *(void ***)(param_2 + 0x10) = &_TreeSentinel;
  *(_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> **)
   (p_Var7 + (ulonglong)(byte)pVar1 * 8 + 8) = param_2;
  lVar5 = (-(ulonglong)
            (pVar1 != (pair<utl::_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>*___ptr64,bool>
                       )0x0) & 0xfffffffffffffff8) + 0x10;
  if (*(_Tree<unsigned_int,utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>,0>
        **)(this + lVar5) == p_Var7) {
    *(_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> **)
     (this + lVar5) = param_2;
  }
  do {
    if ((*(ulonglong *)p_Var7 & 1) != 0) {
LAB_18000be60:
      *(longlong *)(this + 0x18) = *(longlong *)(this + 0x18) + 1;
      return;
    }
    this_00 = (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
               *)(*(ulonglong *)p_Var7 & 0xfffffffffffffffe);
    p_Var2 = *(_Tree<unsigned_int,utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>,0>
               **)(this_00 + 0x10);
    uVar6 = (ulonglong)(p_Var2 != p_Var7);
    if ((**(byte **)(this_00 + uVar6 * 8 + 8) & 1) != 0) {
      pbVar3 = *(byte **)(p_Var7 + uVar6 * 8 + 8);
      if ((*pbVar3 & 1) == 0) {
        lVar5 = 8;
        uVar6 = (ulonglong)(p_Var2 == p_Var7);
        puVar4 = *(ulonglong **)(pbVar3 + uVar6 * 8 + 8);
        *(_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> **
         )pbVar3 = this_00;
        if (*(_Tree<unsigned_int,utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>,0>
              **)(this_00 + 0x10) == p_Var7) {
          lVar5 = 0x10;
        }
        *(byte **)(this_00 + lVar5) = pbVar3;
        *(byte **)p_Var7 = pbVar3;
        *puVar4 = (ulonglong)((uint)*puVar4 & 1) | (ulonglong)p_Var7;
        *(ulonglong **)(p_Var7 + (uVar6 ^ 1) * 8 + 8) = puVar4;
        *(_Tree<unsigned_int,utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>,0>
          **)(pbVar3 + uVar6 * 8 + 8) = p_Var7;
      }
      _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>::
      _NodeRotate(this_00,p_Var2 != p_Var7,false,true);
      goto LAB_18000be60;
    }
    **(ulonglong **)(this_00 + 8) = **(ulonglong **)(this_00 + 8) | 1;
    **(ulonglong **)(this_00 + 0x10) = **(ulonglong **)(this_00 + 0x10) | 1;
    p_Var7 = (_Tree<unsigned_int,utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>,0>
              *)(*(ulonglong *)this_00 & 0xfffffffffffffffe);
    if (this == p_Var7) goto LAB_18000be60;
    *(_Tree<unsigned_int,utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>,0>
      **)this_00 = p_Var7;
  } while( true );
}



===== _NodeRotate @ 18000be7c =====

/* private: struct utl::_TreeNode<struct utl::pair<unsigned int const ,struct
   Kerb3961::EncryptionAlgorithm * __ptr64> > * __ptr64 __cdecl utl::_TreeNodeHeader<struct
   utl::pair<unsigned int const ,struct Kerb3961::EncryptionAlgorithm * __ptr64>
   >::_NodeRotate(bool,bool,bool) __ptr64 */

_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> * __thiscall
utl::_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>::
_NodeRotate(_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
            *this,bool param_1,bool param_2,bool param_3)

{
  _TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *p_Var1;
  ulonglong *puVar2;
  longlong lVar3;
  ulonglong *puVar4;
  ulonglong uVar5;
  
  puVar4 = (ulonglong *)(*(ulonglong *)this & 0xfffffffffffffffe);
  uVar5 = (ulonglong)param_1;
  p_Var1 = *(_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> **)
            (this + ((ulonglong)param_1 ^ 1) * 8 + 8);
  puVar2 = *(ulonglong **)(p_Var1 + uVar5 * 8 + 8);
  *(ulonglong *)p_Var1 = (ulonglong)param_3 | (ulonglong)puVar4;
  if ((_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *)
      (*puVar4 & 0xfffffffffffffffe) == this) {
    *puVar4 = (ulonglong)p_Var1;
  }
  else {
    lVar3 = 8;
    if ((_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *)
        puVar4[2] == this) {
      lVar3 = 0x10;
    }
    *(_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> **)
     (lVar3 + (longlong)puVar4) = p_Var1;
  }
  *(ulonglong *)this = (ulonglong)param_2 | (ulonglong)p_Var1;
  *puVar2 = (ulonglong)((uint)*puVar2 & 1) | (ulonglong)this;
  *(ulonglong **)(this + (uVar5 ^ 1) * 8 + 8) = puVar2;
  *(_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> **)
   (p_Var1 + uVar5 * 8 + 8) = this;
  return p_Var1;
}



===== _Traverse @ 18000bf10 =====

/* public: struct utl::_TreeNode<struct utl::pair<unsigned int const ,struct
   Kerb3961::EncryptionAlgorithm * __ptr64> > * __ptr64 __cdecl utl::_TreeNodeHeader<struct
   utl::pair<unsigned int const ,struct Kerb3961::EncryptionAlgorithm * __ptr64> >::_Traverse(bool)
   __ptr64 */

_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> * __thiscall
utl::_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>::
_Traverse(_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
          *this,bool param_1)

{
  code *pcVar1;
  _TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *p_Var2;
  _TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *p_Var3;
  _TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *p_Var4;
  ulonglong uVar5;
  byte bVar6;
  void **ppvVar7;
  bool bVar8;
  
  uVar5 = (ulonglong)param_1;
  ppvVar7 = &_TreeSentinel;
  bVar6 = !param_1;
  p_Var2 = *(_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> **)
            (this + uVar5 * 8 + 8);
  if (p_Var2 != (_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *
                )&_TreeSentinel) {
    if (this == (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                 *)p_Var2) {
      pcVar1 = (code *)swi(0x2c);
      p_Var2 = (_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *)
               (*pcVar1)();
    }
    for (p_Var3 = *(_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                    **)(p_Var2 + (ulonglong)bVar6 * 8 + 8);
        p_Var3 != (_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                   *)ppvVar7;
        p_Var3 = *(_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                   **)(p_Var3 + (ulonglong)bVar6 * 8 + 8)) {
      p_Var2 = p_Var3;
    }
    return p_Var2;
  }
  p_Var3 = (_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *)
           (*(ulonglong *)this & 0xfffffffffffffffe);
  p_Var2 = p_Var3;
  if ((((*(_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
           **)(p_Var3 + uVar5 * 8 + 8) == this) &&
       (*(_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> **
         )p_Var3 != this)) &&
      (p_Var2 = (_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *
                )((ulonglong)
                  *(_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                    **)p_Var3 & 0xfffffffffffffffe),
      *(_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> **)
       (p_Var2 + uVar5 * 8 + 8) == p_Var3)) &&
     (p_Var4 = p_Var2,
     *(_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> **)p_Var2
     != p_Var3)) {
    do {
      p_Var2 = (_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *)
               (*(ulonglong *)p_Var4 & 0xfffffffffffffffe);
      bVar8 = *(_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> **
               )(p_Var2 + uVar5 * 8 + 8) == p_Var4;
      p_Var4 = p_Var2;
    } while (bVar8);
  }
  return p_Var2;
}



===== Feature_KdcReplicationNoRc4__private_IsEnabledDeviceUsageNoInline @ 18000bf94 =====

ulonglong Feature_KdcReplicationNoRc4__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)(uint)Feature_KdcReplicationNoRc4__private_featureState;
  if (((uint)Feature_KdcReplicationNoRc4__private_featureState & 0x10) == 0) {
    uVar1 = Feature_KdcReplicationNoRc4__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)((uint)Feature_KdcReplicationNoRc4__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_KdcReplicationNoRc4__private_IsEnabledFallback @ 18000bfcc =====

void Feature_KdcReplicationNoRc4__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_KdcReplicationNoRc4__private_descriptor);
  return;
}



===== Feature_RC4Deprecation__private_IsEnabledDeviceUsageNoInline @ 18000bfe8 =====

ulonglong Feature_RC4Deprecation__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_RC4Deprecation__private_featureState;
  if ((Feature_RC4Deprecation__private_featureState & 0x10) == 0) {
    uVar1 = Feature_RC4Deprecation__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_RC4Deprecation__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_RC4Deprecation__private_IsEnabledFallback @ 18000c020 =====

void Feature_RC4Deprecation__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_RC4Deprecation__private_descriptor);
  return;
}



===== GetLocalCipherPolicy @ 18000c040 =====

CipherPolicyImpl * GetLocalCipherPolicy(void)

{
                    /* 0xc040  21   */
  return &Kerb3961::g_localCipherPolicy;
}



===== ApplyCipherPolicy @ 18000c050 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::StatusOnly,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly & __ptr64)> __cdecl
   Kerb3961::RC4_4757::ApplyCipherPolicy(struct Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64 */

ReadOnlyBinary * __thiscall
Kerb3961::RC4_4757::ApplyCipherPolicy(RC4_4757 *this,ReadOnlyBinary *param_1)

{
  ulonglong uVar1;
  longlong *in_R8;
  
  uVar1 = Feature_184236346__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar1 != 0) {
    if (*in_R8 != 4) {
      Logging::Verify::ConditionFailed("marshaledPolicy.length == sizeof(m_policy)");
      *(undefined4 *)param_1 = 0xc000000d;
      return param_1;
    }
    *(undefined4 *)(this + 0x68) = *(undefined4 *)in_R8[1];
  }
  *(undefined4 *)param_1 = 0;
  return param_1;
}



===== ChecksumEnabledForAccount @ 18000c0c0 =====

/* private: virtual bool __cdecl Kerb3961::RC4_4757::ChecksumEnabledForAccount(struct
   Kerb3961::KeyPolicyScenario,unsigned int,enum Kerb3961::UserPolicyAttributes) __ptr64 */

bool __thiscall
Kerb3961::RC4_4757::ChecksumEnabledForAccount
          (RC4_4757 *this,undefined4 *param_2,ulonglong param_3,undefined8 param_4)

{
  bool bVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined4 local_18;
  undefined1 local_14;
  
  uVar3 = param_3;
  uVar2 = Feature_184236346__private_IsEnabledDeviceUsageNoInline();
  bVar1 = false;
  local_18 = *param_2;
  if ((int)uVar2 == 0) {
    local_18._1_1_ = (char)((uint)local_18 >> 8);
    uVar4 = CONCAT71((int7)(uVar3 >> 8),local_18._1_1_);
    if (((local_18._1_1_ == '\x02') || ((param_3 & 4) != 0)) || (local_18._1_1_ == '\b')) {
      bVar1 = true;
    }
    Logging::Cipher::UsageEnabled
              (*(ushort **)(this + 0x20),bVar1,(KeyPolicyOperation)uVar4,(uint)param_3);
  }
  else {
    local_14 = *(undefined1 *)(param_2 + 1);
    bVar1 = EnabledForAccountCommon(this + -8,&local_18,param_3 & 0xffffffff,param_4);
  }
  return bVar1;
}



===== ChecksumEnabledForUsage @ 18000c160 =====

/* private: virtual bool __cdecl Kerb3961::RC4_4757::ChecksumEnabledForUsage(struct
   Kerb3961::KeyPolicyScenario,unsigned int) __ptr64 */

bool __thiscall
Kerb3961::RC4_4757::ChecksumEnabledForUsage(RC4_4757 *this,undefined4 *param_2,uint param_3)

{
  bool bVar1;
  char cStackX_9;
  
  cStackX_9 = (char)((uint)*param_2 >> 8);
  if (((cStackX_9 == '\x02') || ((param_3 & 4) != 0)) || (cStackX_9 == '\b')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  Logging::Cipher::UsageEnabled
            (*(ushort **)(this + 0x20),bVar1,CONCAT31((int3)(param_3 >> 8),cStackX_9),param_3);
  return bVar1;
}



===== CipherEnabledForAccount @ 18000c1b0 =====

/* private: virtual bool __cdecl Kerb3961::RC4_4757::CipherEnabledForAccount(struct
   Kerb3961::KeyPolicyScenario,unsigned int,enum Kerb3961::UserPolicyAttributes) __ptr64 */

bool __thiscall
Kerb3961::RC4_4757::CipherEnabledForAccount
          (RC4_4757 *this,undefined4 *param_2,ulonglong param_3,undefined8 param_4)

{
  bool bVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined4 local_18;
  undefined1 local_14;
  
  uVar3 = param_3;
  uVar2 = Feature_184236346__private_IsEnabledDeviceUsageNoInline();
  bVar1 = false;
  local_18 = *param_2;
  if ((int)uVar2 == 0) {
    local_18._1_1_ = (char)((uint)local_18 >> 8);
    uVar4 = CONCAT71((int7)(uVar3 >> 8),local_18._1_1_);
    if (((local_18._1_1_ == '\x02') || ((param_3 & 4) != 0)) || (local_18._1_1_ == '\b')) {
      bVar1 = true;
    }
    Logging::Cipher::UsageEnabled
              (*(ushort **)(this + 0x28),bVar1,(KeyPolicyOperation)uVar4,(uint)param_3);
  }
  else {
    local_14 = *(undefined1 *)(param_2 + 1);
    bVar1 = EnabledForAccountCommon(this,&local_18,param_3 & 0xffffffff,param_4);
  }
  return bVar1;
}



===== CipherEnabledForUsage @ 18000c250 =====

/* private: virtual bool __cdecl Kerb3961::RC4_4757::CipherEnabledForUsage(struct
   Kerb3961::KeyPolicyScenario,unsigned int) __ptr64 */

bool __thiscall
Kerb3961::RC4_4757::CipherEnabledForUsage(RC4_4757 *this,undefined4 *param_2,uint param_3)

{
  bool bVar1;
  char cStackX_9;
  
  cStackX_9 = (char)((uint)*param_2 >> 8);
  if (((cStackX_9 == '\x02') || ((param_3 & 4) != 0)) || (cStackX_9 == '\b')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  Logging::Cipher::UsageEnabled
            (*(ushort **)(this + 0x28),bVar1,CONCAT31((int3)(param_3 >> 8),cStackX_9),param_3);
  return bVar1;
}



===== CommonGetMIC @ 18000c2a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::RC4_4757::CommonGetMIC(struct Kerb3961::ReadOnlyBinary const & __ptr64,unsigned
   __int64,unsigned int,struct Kerb3961::ReadOnlyBinary const & __ptr64,bool,bool) __ptr64 */

ReadOnlyBinary * __thiscall
Kerb3961::RC4_4757::CommonGetMIC
          (RC4_4757 *this,ReadOnlyBinary *param_1,__uint64 param_2,uint param_3,
          ReadOnlyBinary *param_4,bool param_5,bool param_6)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  long lVar5;
  ReadOnlyBinary local_res8 [8];
  undefined7 in_stack_00000031;
  undefined8 local_d8;
  undefined8 *local_d0;
  long local_c8;
  undefined8 local_c0;
  void *local_b8;
  long local_b0;
  ReadOnlyBinary local_a8 [8];
  undefined8 *local_a0;
  long local_98;
  ReadOnlyBinary local_90 [8];
  void *local_88;
  long local_80;
  ReadOnlyBinary local_78 [8];
  void *local_70;
  long local_68;
  undefined8 local_60;
  undefined8 *local_58;
  long local_50;
  ReadOnlyBinary local_48 [8];
  void *local_40;
  
  iVar1 = (**(code **)(*(longlong *)(this + 8) + 0x68))();
  iVar2 = (**(code **)(*(longlong *)this + 0xe0))(this);
  if (iVar1 != iVar2) {
                    /* WARNING: Subroutine does not return */
    ConsistencyFail((ushort *)
                    L"A cipher suite\'s included checksum must be the required checksum for the included cipher"
                   );
  }
  MakeBuffer((__uint64)&local_60);
  if (local_50 < 0) {
    Logging::Verify::StatusFailed("headerBuffer",local_50);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(long *)(param_1 + 0x10) = local_50;
LAB_18000c5e9:
    if (local_58 == (undefined8 *)0x0) {
      return param_1;
    }
    goto LAB_18000c5ee;
  }
  *local_58 = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  *(undefined4 *)((longlong)local_58 + 4) = 0xffffffff;
  *(undefined4 *)local_58 = 0x110101;
  *(uint *)((longlong)local_58 + 0xc) = ~-(uint)param_6;
  *(uint *)(local_58 + 1) =
       param_3 >> 0x18 | (param_3 & 0xff0000) >> 8 | (param_3 & 0xff00) << 8 | param_3 << 0x18;
  HmacData(this,local_a8,(ReadOnlyBinary *)CONCAT71(in_stack_00000031,param_5));
  if (local_98 < 0) {
    Logging::Verify::StatusFailed("Ksign",local_98);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(long *)(param_1 + 0x10) = local_98;
  }
  else {
    local_d8 = 8;
    local_d0 = local_58;
    Concatenate(local_90,&`private:_virtual_struct_Kerb3961::ReturnType<Kerb3961::OwnedBinary,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary&___ptr64)>___cdecl_Kerb3961::RC4_4757::CommonGetMIC(Kerb3961::ReadOnlyBinary_const&___ptr64,unsigned___int64,unsigned_int,Kerb3961::ReadOnlyBinary_const&___ptr64,bool,bool)___ptr64'
                          ::__l2::_S8,(ReadOnlyBinary *)&local_d8);
    if (local_80 < 0) {
      Logging::Verify::StatusFailed("signBuffer",local_80);
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(long *)(param_1 + 0x10) = local_80;
    }
    else {
      HashData(this,local_78);
      if (local_68 < 0) {
        Logging::Verify::StatusFailed("hash",local_68);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(long *)(param_1 + 0x10) = local_68;
      }
      else {
        HmacData(this,(ReadOnlyBinary *)&local_d8,local_a8);
        puVar4 = local_d0;
        if (local_c8 < 0) {
          Logging::Verify::StatusFailed("checksum",local_c8);
          *(undefined8 *)param_1 = 0;
          *(undefined8 *)(param_1 + 8) = 0;
          *(long *)(param_1 + 0x10) = local_c8;
          puVar4 = local_d0;
          if (local_d0 == (undefined8 *)0x0) goto LAB_18000c43e;
        }
        else {
          local_58[2] = *local_d0;
          HmacData(this,(ReadOnlyBinary *)&local_c0,
                   (ReadOnlyBinary *)CONCAT71(in_stack_00000031,param_5));
          lVar5 = local_b0;
          if (local_b0 < 0) {
            Logging::Verify::StatusFailed("Kseq",local_b0);
            *(undefined8 *)param_1 = 0;
            *(undefined8 *)(param_1 + 8) = 0;
          }
          else {
            local_d8 = 8;
            local_d0 = local_58 + 2;
            puVar3 = (undefined8 *)HmacData(this,local_48,(ReadOnlyBinary *)&local_c0);
            if (local_b8 != (void *)0x0) {
              operator_delete__(local_b8);
            }
            local_c0 = *puVar3;
            local_b8 = (void *)puVar3[1];
            *puVar3 = 0;
            local_b0 = *(long *)(puVar3 + 2);
            puVar3[1] = 0;
            *(undefined4 *)(puVar3 + 2) = 0xc0000001;
            if (local_40 != (void *)0x0) {
              operator_delete__(local_40);
            }
            lVar5 = local_b0;
            if (-1 < local_b0) {
              local_d0 = local_58 + 1;
              local_d8 = 8;
              RC4Data(this,local_res8,(MutableBinary *)&local_c0);
              *(long *)(param_1 + 0x10) = local_50;
              *(undefined8 *)param_1 = local_60;
              *(undefined8 **)(param_1 + 8) = local_58;
              if (local_b8 != (void *)0x0) {
                operator_delete__(local_b8);
              }
              operator_delete__(puVar4);
              if (local_70 != (void *)0x0) {
                operator_delete__(local_70);
              }
              if (local_88 != (void *)0x0) {
                operator_delete__(local_88);
              }
              local_58 = local_a0;
              goto LAB_18000c5e9;
            }
            Logging::Verify::StatusFailed("Kseq",local_b0);
            *(undefined8 *)param_1 = 0;
            *(undefined8 *)(param_1 + 8) = 0;
          }
          *(long *)(param_1 + 0x10) = lVar5;
          if (local_b8 != (void *)0x0) {
            operator_delete__(local_b8);
          }
        }
        operator_delete__(puVar4);
      }
LAB_18000c43e:
      if (local_70 != (void *)0x0) {
        operator_delete__(local_70);
      }
    }
    if (local_88 != (void *)0x0) {
      operator_delete__(local_88);
    }
  }
  if (local_a0 != (undefined8 *)0x0) {
    operator_delete__(local_a0);
  }
  if (local_58 == (undefined8 *)0x0) {
    return param_1;
  }
LAB_18000c5ee:
  operator_delete__(local_58);
  return param_1;
}



===== CommonUnwrap @ 18000c630 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::UnwrapResult,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::DoubleGetter<struct
   Kerb3961::UnwrapResult,struct Kerb3961::OwnedBinary,0,16>(struct Kerb3961::UnwrapResult const &
   __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::DoubleSetter<struct
   Kerb3961::UnwrapResult,struct Kerb3961::OwnedBinary,0,16>(struct Kerb3961::UnwrapResult &
   __ptr64)> __cdecl Kerb3961::RC4_4757::CommonUnwrap(struct Kerb3961::ReadOnlyBinary const &
   __ptr64,struct Kerb3961::ReadOnlyBinary const & __ptr64,struct Kerb3961::ReadOnlyBinary const &
   __ptr64,bool,bool) __ptr64 */

ReadOnlyBinary * __thiscall
Kerb3961::RC4_4757::CommonUnwrap
          (RC4_4757 *this,ReadOnlyBinary *param_1,ReadOnlyBinary *param_2,ReadOnlyBinary *param_3,
          bool param_4,bool param_5)

{
  byte *pbVar1;
  byte bVar2;
  long lVar3;
  undefined8 uVar4;
  int iVar5;
  int iVar6;
  undefined8 *puVar7;
  int *piVar8;
  uint *puVar9;
  ReadOnlyBinary *pRVar10;
  char *pcVar11;
  longlong lVar12;
  uint *puVar13;
  void *pvVar14;
  byte *pbVar15;
  byte bVar16;
  uint uVar17;
  longlong lVar18;
  undefined7 in_stack_00000029;
  undefined1 auStack_298 [32];
  ReadOnlyBinary local_278;
  undefined8 local_270;
  void *local_268;
  int local_260;
  undefined8 local_258;
  void *local_250;
  int local_248;
  uint local_240 [2];
  ReadOnlyBinary local_238 [8];
  void *local_230;
  long local_228;
  undefined8 local_220;
  byte *local_218;
  int local_210;
  longlong local_208;
  uint *local_200;
  long local_1f8;
  undefined8 local_1e8;
  void *local_1e0;
  int local_1d8;
  undefined8 local_1d0;
  uint *local_1c8;
  int local_1c0;
  uint *local_1b8;
  short *psStack_1b0;
  short local_1a8;
  short sStack_1a6;
  short sStack_1a4;
  short sStack_1a2;
  uint uStack_1a0;
  int iStack_19c;
  undefined8 local_198;
  undefined8 uStack_190;
  ReadOnlyBinary local_188 [8];
  void *local_180;
  ReadOnlyBinary *local_170;
  ReadOnlyBinary *local_168;
  ReadOnlyBinary local_160 [8];
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  uchar **ppuStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined4 local_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 local_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 local_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  ulonglong local_48;
  
  pbVar15 = (byte *)&local_198;
  local_48 = __security_cookie ^ (ulonglong)auStack_298;
  local_170 = param_3;
  local_168 = param_2;
  iVar5 = (**(code **)(*(longlong *)(this + 8) + 0x68))();
  iVar6 = (**(code **)(*(longlong *)this + 0xe0))(this);
  if (iVar5 != iVar6) {
                    /* WARNING: Subroutine does not return */
    ConsistencyFail((ushort *)
                    L"A cipher suite\'s included checksum must be the required checksum for the included cipher"
                   );
  }
  if (*(ulonglong *)param_2 < 0x20) {
    pcVar11 = "message.length >= sizeof(WrapToken)";
  }
  else {
    psStack_1b0 = *(short **)(param_2 + 8);
    local_200 = &uStack_1a0;
    local_1b8 = (uint *)(*(ulonglong *)param_2 - 0x20);
    lVar18 = 8;
    local_208 = 8;
    local_1a8 = *psStack_1b0;
    sStack_1a6 = psStack_1b0[1];
    sStack_1a4 = psStack_1b0[2];
    sStack_1a2 = psStack_1b0[3];
    uStack_1a0 = *(uint *)(psStack_1b0 + 4);
    iStack_19c = *(int *)(psStack_1b0 + 6);
    uStack_150 = &uStack_190;
    local_220 = 8;
    local_158 = 8;
    local_198 = *(undefined8 *)(psStack_1b0 + 8);
    uStack_190 = *(undefined8 *)(psStack_1b0 + 0xc);
    psStack_1b0 = psStack_1b0 + 0x10;
    local_218 = pbVar15;
    if (local_1a8 == 0x102) {
      if (sStack_1a6 == 0x11) {
        if (sStack_1a2 == -1) {
          if (sStack_1a4 == 0x10) {
            local_278 = (ReadOnlyBinary)0x1;
          }
          else {
            local_278 = (ReadOnlyBinary)0x0;
            if (sStack_1a4 != -1) {
              Logging::Verify::ConditionFailed
                        ("encrypted || header.SEAL_ALG == header.IntegrityOnly");
              goto LAB_18000c6bb;
            }
          }
          HmacData(this,local_238,(ReadOnlyBinary *)CONCAT71(in_stack_00000029,param_4));
          if (local_228 < 0) {
            Logging::Verify::StatusFailed("Ksign",local_228);
            *(undefined8 *)(param_1 + 0x14) = 0;
            *(undefined8 *)(param_1 + 0x1c) = 0;
            *(undefined4 *)(param_1 + 0x24) = 0;
            *(undefined8 *)param_1 = 0;
            *(undefined8 *)(param_1 + 8) = 0;
            *(long *)(param_1 + 0x10) = local_228;
            goto LAB_18000cf08;
          }
          HmacData(this,(ReadOnlyBinary *)&local_258,
                   (ReadOnlyBinary *)CONCAT71(in_stack_00000029,param_4));
          if (local_248 < 0) {
LAB_18000c7fb:
            pcVar11 = "Kseq";
            iVar5 = local_248;
LAB_18000c802:
            Logging::Verify::StatusFailed(pcVar11,iVar5);
            *(undefined8 *)(param_1 + 0x14) = 0;
            *(undefined8 *)(param_1 + 0x1c) = 0;
            *(undefined4 *)(param_1 + 0x24) = 0;
            *(undefined8 *)param_1 = 0;
            *(undefined8 *)(param_1 + 8) = 0;
            *(int *)(param_1 + 0x10) = iVar5;
          }
          else {
            puVar7 = (undefined8 *)
                     HmacData(this,(ReadOnlyBinary *)&local_1e8,(ReadOnlyBinary *)&local_258);
            if (local_250 != (void *)0x0) {
              operator_delete__(local_250);
            }
            local_258 = *puVar7;
            local_250 = (void *)puVar7[1];
            *puVar7 = 0;
            local_248 = *(int *)(puVar7 + 2);
            puVar7[1] = 0;
            *(undefined4 *)(puVar7 + 2) = 0xc0000001;
            if (local_1e0 != (void *)0x0) {
              operator_delete__(local_1e0);
            }
            if (local_248 < 0) goto LAB_18000c7fb;
            piVar8 = (int *)RC4Data(this,(ReadOnlyBinary *)local_240,(MutableBinary *)&local_258);
            iVar5 = *piVar8;
            if (iVar5 < 0) {
              pcVar11 = "RC4Data(Kseq, sequenceBuffer)";
              goto LAB_18000c802;
            }
            if (iStack_19c == -(uint)param_5) {
              uVar17 = uStack_1a0 >> 0x18 | (uStack_1a0 & 0xff0000) >> 8 |
                       (uStack_1a0 & 0xff00) << 8 | uStack_1a0 << 0x18;
              local_270 = 0;
              local_268 = (void *)0x0;
              local_260 = -0x3fffffff;
              local_240[0] = uVar17;
              if (local_278 == (ReadOnlyBinary)0x0) {
                if ((*(uint **)local_170 != (uint *)0x0) && (local_1b8 != (uint *)0x0)) {
                  Logging::Verify::ConditionFailed
                            ("authData.length == 0 || payloadBuffer.length == 0");
                  *(undefined8 *)(param_1 + 0x14) = 0;
                  *(undefined8 *)(param_1 + 0x1c) = 0;
                  *(undefined4 *)(param_1 + 0x24) = 0;
                  *(undefined8 *)param_1 = 0;
                  *(undefined8 *)(param_1 + 8) = 0;
                  *(undefined4 *)(param_1 + 0x10) = 0x8009030a;
                  goto LAB_18000ceea;
                }
                local_138 = 8;
                local_88 = 4;
                uStack_80 = &`private:_virtual_struct_Kerb3961::ReturnType<Kerb3961::OwnedBinary,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary&___ptr64)>___cdecl_Kerb3961::RC4_4757::CommonWrapEncrypted(Kerb3961::MutableBinary_const&___ptr64,Kerb3961::ReadOnlyBinary_const&___ptr64,unsigned___int64,unsigned_int,Kerb3961::ReadOnlyBinary_const&___ptr64,bool,bool,unsigned___int64*___ptr64)___ptr64'
                             ::__l2::salt;
                uStack_130 = *(undefined8 *)(local_168 + 8);
                uVar4 = uStack_130;
                uStack_130._4_4_ = (undefined4)((ulonglong)uStack_130 >> 0x20);
                pRVar10 = (ReadOnlyBinary *)&local_1b8;
                if (*(uint **)local_170 != (uint *)0x0) {
                  pRVar10 = local_170;
                }
                local_78 = 8;
                uStack_74 = 0;
                uStack_70 = (undefined4)uStack_130;
                uStack_6c = uStack_130._4_4_;
                local_68 = (undefined4)local_158;
                uStack_64 = local_158._4_4_;
                uStack_60 = (undefined4)uStack_150;
                uStack_5c = uStack_150._4_4_;
                local_58 = *(undefined4 *)pRVar10;
                uStack_54 = *(undefined4 *)(pRVar10 + 4);
                uStack_50 = *(undefined4 *)(pRVar10 + 8);
                uStack_4c = *(undefined4 *)(pRVar10 + 0xc);
                uStack_130 = uVar4;
                Concatenate<4>(&local_1e8,&local_88);
                if (local_268 != (void *)0x0) {
                  operator_delete__(local_268);
                }
                local_270 = local_1e8;
                local_268 = local_1e0;
                local_260 = local_1d8;
                if (local_1d8 < 0) {
                  Logging::Verify::StatusFailed("checksummedData",local_1d8);
                  *(undefined8 *)(param_1 + 0x14) = 0;
                  *(undefined8 *)(param_1 + 0x1c) = 0;
                  *(undefined4 *)(param_1 + 0x24) = 0;
                  *(undefined8 *)param_1 = 0;
                  *(undefined8 *)(param_1 + 8) = 0;
                  *(int *)(param_1 + 0x10) = local_1d8;
                  goto LAB_18000ceea;
                }
                puVar7 = (undefined8 *)CopyBuffer(local_188);
                pvVar14 = (void *)puVar7[1];
                lVar3 = *(long *)(puVar7 + 2);
                puVar7[1] = 0;
                *(undefined4 *)(puVar7 + 2) = 0xc0000001;
                *puVar7 = 0;
                if (local_180 != (void *)0x0) {
                  operator_delete__(local_180);
                }
                if (lVar3 < 0) {
                  Logging::Verify::StatusFailed("outputMessage",lVar3);
                  *(undefined8 *)(param_1 + 0x14) = 0;
                  *(undefined8 *)(param_1 + 0x1c) = 0;
                  *(undefined4 *)(param_1 + 0x24) = 0;
                  *(undefined8 *)param_1 = 0;
                  *(undefined8 *)(param_1 + 8) = 0;
                  *(long *)(param_1 + 0x10) = lVar3;
                }
                else {
LAB_18000cc64:
                  HashData(this,(ReadOnlyBinary *)&local_1d0);
                  if (local_1c0 < 0) {
LAB_18000cc82:
                    iVar5 = local_1c0;
                    Logging::Verify::StatusFailed("Sgn_Cksum",local_1c0);
                    *(undefined8 *)(param_1 + 0x14) = 0;
                    *(undefined8 *)(param_1 + 0x1c) = 0;
                    *(undefined4 *)(param_1 + 0x24) = 0;
                    *(undefined8 *)param_1 = 0;
                    *(undefined8 *)(param_1 + 8) = 0;
                    *(int *)(param_1 + 0x10) = iVar5;
                  }
                  else {
                    puVar7 = (undefined8 *)HmacData(this,local_188,local_238);
                    if (local_1c8 != (uint *)0x0) {
                      operator_delete__(local_1c8);
                    }
                    local_1d0 = *puVar7;
                    local_1c8 = (uint *)puVar7[1];
                    *puVar7 = 0;
                    local_1c0 = *(int *)(puVar7 + 2);
                    puVar7[1] = 0;
                    *(undefined4 *)(puVar7 + 2) = 0xc0000001;
                    if (local_180 != (void *)0x0) {
                      operator_delete__(local_180);
                    }
                    if (local_1c0 < 0) goto LAB_18000cc82;
                    lVar12 = (longlong)local_1c8 - (longlong)pbVar15;
                    bVar16 = 0;
                    do {
                      pbVar1 = pbVar15 + lVar12;
                      bVar2 = *pbVar15;
                      pbVar15 = pbVar15 + 1;
                      bVar16 = bVar16 | *pbVar1 ^ bVar2;
                      lVar18 = lVar18 + -1;
                    } while (lVar18 != 0);
                    if (bVar16 == 0) {
                      *(ulonglong *)(param_1 + 0x18) = (ulonglong)uVar17;
                      param_1[0x24] = local_278;
                      *(void **)(param_1 + 8) = pvVar14;
                      *(undefined4 *)(param_1 + 0x20) = 0;
                      *(undefined4 *)(param_1 + 0x10) = 0;
                      puVar13 = local_1c8;
                      goto LAB_18000cedd;
                    }
                    Logging::Verify::ConditionFailed
                              (
                              "SecureEqualBuffer(checksumBuffer, Sgn_Cksum.buffer, checksumBuffer.length)"
                              );
                    *(undefined8 *)(param_1 + 0x14) = 0;
                    *(undefined8 *)(param_1 + 0x1c) = 0;
                    *(undefined4 *)(param_1 + 0x24) = 0;
                    *(undefined8 *)param_1 = 0;
                    *(undefined8 *)(param_1 + 8) = 0;
                    *(undefined4 *)(param_1 + 0x10) = 0x8009030f;
                  }
                  puVar13 = local_1c8;
                  if (local_1c8 != (uint *)0x0) {
LAB_18000cc11:
                    operator_delete__(puVar13);
                  }
                }
LAB_18000cc16:
                if (local_268 != (void *)0x0) {
                  operator_delete__(local_268);
                }
                if (pvVar14 == (void *)0x0) goto LAB_18000cef9;
              }
              else {
                CopyBuffer((ReadOnlyBinary *)&local_208);
                puVar13 = local_200;
                if (local_1f8 < 0) {
                  Logging::Verify::StatusFailed("Klocal",local_1f8);
                  *(undefined8 *)(param_1 + 0x14) = 0;
                  *(undefined8 *)(param_1 + 0x1c) = 0;
                  *(undefined4 *)(param_1 + 0x24) = 0;
                  *(undefined8 *)(param_1 + 8) = 0;
                  *(long *)(param_1 + 0x10) = local_1f8;
                  puVar13 = local_200;
LAB_18000cedd:
                  *(undefined8 *)param_1 = 0;
                  if (puVar13 == (uint *)0x0) goto LAB_18000ceea;
                }
                else {
                  if (local_208 != 0) {
                    puVar9 = local_200;
                    lVar12 = local_208;
                    do {
                      *(byte *)puVar9 = (byte)*puVar9 ^ 0xf0;
                      puVar9 = (uint *)((longlong)puVar9 + 1);
                      lVar12 = lVar12 + -1;
                    } while (lVar12 != 0);
                  }
                  HmacData(this,(ReadOnlyBinary *)&local_220,(ReadOnlyBinary *)&local_208);
                  if (local_210 < 0) {
LAB_18000c98a:
                    iVar5 = local_210;
                    Logging::Verify::StatusFailed("Kcrypt",local_210);
                    *(undefined8 *)(param_1 + 0x14) = 0;
                    *(undefined8 *)(param_1 + 0x1c) = 0;
                    *(undefined4 *)(param_1 + 0x24) = 0;
                    *(undefined8 *)param_1 = 0;
                    *(int *)(param_1 + 0x10) = iVar5;
                    *(undefined8 *)(param_1 + 8) = 0;
                  }
                  else {
                    local_200 = &uStack_1a0;
                    local_208 = 4;
                    puVar7 = (undefined8 *)HmacData(this,local_188,(ReadOnlyBinary *)&local_220);
                    if (local_218 != (byte *)0x0) {
                      operator_delete__(local_218);
                    }
                    local_220 = *puVar7;
                    local_218 = (byte *)puVar7[1];
                    *puVar7 = 0;
                    local_210 = *(int *)(puVar7 + 2);
                    puVar7[1] = 0;
                    *(undefined4 *)(puVar7 + 2) = 0xc0000001;
                    if (local_180 != (void *)0x0) {
                      operator_delete__(local_180);
                    }
                    if (local_210 < 0) goto LAB_18000c98a;
                    Concatenate((ReadOnlyBinary *)&local_1e8,(ReadOnlyBinary *)&local_158);
                    if (local_1d8 < 0) {
                      pcVar11 = "tmp";
                      iVar5 = local_1d8;
                    }
                    else {
                      piVar8 = (int *)RC4Data(this,local_160,(MutableBinary *)&local_220);
                      iVar5 = *piVar8;
                      if (-1 < iVar5) {
                        local_200 = local_1b8;
                        local_208 = 8;
                        Split<2>(&local_88,&local_1e8,&local_208);
                        local_c8 = 8;
                        local_118 = *(undefined4 *)local_170;
                        uStack_114 = *(undefined4 *)(local_170 + 4);
                        uStack_110 = *(undefined4 *)(local_170 + 8);
                        uStack_10c = *(undefined4 *)(local_170 + 0xc);
                        uStack_130 = *(undefined8 *)(local_168 + 8);
                        local_148 = 4;
                        ppuStack_140 = &`private:_virtual_struct_Kerb3961::ReturnType<Kerb3961::OwnedBinary,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary&___ptr64)>___cdecl_Kerb3961::RC4_4757::CommonWrapEncrypted(Kerb3961::MutableBinary_const&___ptr64,Kerb3961::ReadOnlyBinary_const&___ptr64,unsigned___int64,unsigned_int,Kerb3961::ReadOnlyBinary_const&___ptr64,bool,bool,unsigned___int64*___ptr64)___ptr64'
                                        ::__l2::salt;
                        local_138 = 8;
                        local_128 = (undefined4)local_88;
                        uStack_124 = local_88._4_4_;
                        uStack_120 = (undefined4)uStack_80;
                        uStack_11c = uStack_80._4_4_;
                        local_108 = local_78;
                        uStack_104 = uStack_74;
                        uStack_100 = uStack_70;
                        uStack_fc = uStack_6c;
                        uStack_c0 = uStack_130;
                        puVar7 = (undefined8 *)Concatenate<5>(local_188,&local_148);
                        if (local_268 != (void *)0x0) {
                          operator_delete__(local_268);
                        }
                        local_270 = *puVar7;
                        local_268 = (void *)puVar7[1];
                        *puVar7 = 0;
                        local_260 = *(int *)(puVar7 + 2);
                        puVar7[1] = 0;
                        *(undefined4 *)(puVar7 + 2) = 0xc0000001;
                        if (local_180 != (void *)0x0) {
                          operator_delete__(local_180);
                        }
                        if (local_260 < 0) {
                          pcVar11 = "checksummedData";
                          iVar5 = local_260;
                          goto LAB_18000ca61;
                        }
                        puVar7 = (undefined8 *)CopyBuffer(local_188);
                        pvVar14 = (void *)puVar7[1];
                        lVar3 = *(long *)(puVar7 + 2);
                        puVar7[1] = 0;
                        *(undefined4 *)(puVar7 + 2) = 0xc0000001;
                        *puVar7 = 0;
                        if (local_180 != (void *)0x0) {
                          operator_delete__(local_180);
                        }
                        if (-1 < lVar3) {
                          if (local_1e0 != (void *)0x0) {
                            operator_delete__(local_1e0);
                          }
                          if (local_218 != (byte *)0x0) {
                            operator_delete__(local_218);
                          }
                          if (puVar13 != (uint *)0x0) {
                            operator_delete__(puVar13);
                          }
                          uVar17 = local_240[0];
                          goto LAB_18000cc64;
                        }
                        Logging::Verify::StatusFailed("outputMessage",lVar3);
                        *(undefined8 *)(param_1 + 0x14) = 0;
                        *(undefined8 *)(param_1 + 0x1c) = 0;
                        *(undefined4 *)(param_1 + 0x24) = 0;
                        *(undefined8 *)param_1 = 0;
                        *(undefined8 *)(param_1 + 8) = 0;
                        *(long *)(param_1 + 0x10) = lVar3;
                        if (local_1e0 != (void *)0x0) {
                          operator_delete__(local_1e0);
                        }
                        if (local_218 != (byte *)0x0) {
                          operator_delete__(local_218);
                        }
                        if (puVar13 == (uint *)0x0) goto LAB_18000cc16;
                        goto LAB_18000cc11;
                      }
                      pcVar11 = "RC4Data(Kcrypt, tmp)";
                    }
LAB_18000ca61:
                    Logging::Verify::StatusFailed(pcVar11,iVar5);
                    *(undefined8 *)(param_1 + 0x14) = 0;
                    *(undefined8 *)(param_1 + 0x1c) = 0;
                    *(undefined4 *)(param_1 + 0x24) = 0;
                    *(undefined8 *)param_1 = 0;
                    *(undefined8 *)(param_1 + 8) = 0;
                    *(int *)(param_1 + 0x10) = iVar5;
                    if (local_1e0 != (void *)0x0) {
                      operator_delete__(local_1e0);
                    }
                  }
                  if (local_218 != (byte *)0x0) {
                    operator_delete__(local_218);
                  }
                  if (puVar13 == (uint *)0x0) goto LAB_18000ceea;
                }
                operator_delete__(puVar13);
LAB_18000ceea:
                pvVar14 = local_268;
                if (local_268 == (void *)0x0) goto LAB_18000cef9;
              }
              operator_delete__(pvVar14);
            }
            else {
              Logging::Verify::ConditionFailed("header.SND_SEQ.Direction == expectedDirection");
              *(undefined8 *)(param_1 + 0x14) = 0;
              *(undefined8 *)(param_1 + 0x1c) = 0;
              *(undefined4 *)(param_1 + 0x24) = 0;
              *(undefined8 *)param_1 = 0;
              *(undefined8 *)(param_1 + 8) = 0;
              *(undefined4 *)(param_1 + 0x10) = 0x8009030f;
            }
          }
LAB_18000cef9:
          if (local_250 != (void *)0x0) {
            operator_delete__(local_250);
          }
LAB_18000cf08:
          if (local_230 == (void *)0x0) {
            return param_1;
          }
          operator_delete__(local_230);
          return param_1;
        }
        pcVar11 = "header.Filler == header.FillerBytes";
      }
      else {
        pcVar11 = "header.SGN_ALG == header.SignAlgorithm";
      }
    }
    else {
      pcVar11 = "header.TOK_ID == header.ID";
    }
  }
  Logging::Verify::ConditionFailed(pcVar11);
LAB_18000c6bb:
  *(undefined8 *)(param_1 + 0x14) = 0;
  *(undefined8 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined8 *)param_1 = 0;
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0x8009030f;
  return param_1;
}



===== CommonVerifyMIC @ 18000cf60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::VerifyMICResult,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::VerifyMICResult,12>(struct Kerb3961::VerifyMICResult const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::VerifyMICResult,12>(struct Kerb3961::VerifyMICResult & __ptr64)> __cdecl
   Kerb3961::RC4_4757::CommonVerifyMIC(struct Kerb3961::ReadOnlyBinary const & __ptr64,struct
   Kerb3961::ReadOnlyBinary const & __ptr64,struct Kerb3961::ReadOnlyBinary const &
   __ptr64,bool,bool) __ptr64 */

ReadOnlyBinary * __thiscall
Kerb3961::RC4_4757::CommonVerifyMIC
          (RC4_4757 *this,ReadOnlyBinary *param_1,ReadOnlyBinary *param_2,ReadOnlyBinary *param_3,
          bool param_4,bool param_5)

{
  byte *pbVar1;
  byte bVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  undefined8 *puVar6;
  uint uVar7;
  char *pcVar8;
  byte *pbVar9;
  byte bVar10;
  longlong lVar11;
  ReadOnlyBinary local_res8 [8];
  undefined7 in_stack_00000029;
  undefined8 local_e8;
  undefined8 local_e0;
  void *local_d8;
  int local_d0;
  ReadOnlyBinary local_c8 [8];
  void *local_c0;
  long local_b8;
  ReadOnlyBinary local_b0 [8];
  void *local_a8;
  long local_a0;
  ReadOnlyBinary local_98 [8];
  void *local_90;
  long local_88;
  undefined8 local_80;
  short *local_78;
  ReadOnlyBinary local_70 [8];
  byte *local_68;
  long local_60;
  undefined8 local_58;
  undefined8 *local_50;
  ReadOnlyBinary local_48 [8];
  void *local_40;
  
  iVar4 = (**(code **)(*(longlong *)(this + 8) + 0x68))();
  iVar5 = (**(code **)(*(longlong *)this + 0xe0))(this);
  if (iVar4 != iVar5) {
                    /* WARNING: Subroutine does not return */
    ConsistencyFail((ushort *)
                    L"A cipher suite\'s included checksum must be the required checksum for the included cipher"
                   );
  }
  if (*(longlong *)param_3 != 0x18) {
    pcVar8 = "inputSignature.length == sizeof(MICToken)";
LAB_18000cfc3:
    Logging::Verify::ConditionFailed(pcVar8);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0x8009030f;
    return param_1;
  }
  psVar3 = *(short **)(param_3 + 8);
  if (*psVar3 != 0x101) {
    pcVar8 = "header.TOK_ID == header.ID";
    goto LAB_18000cfc3;
  }
  if (psVar3[1] != 0x11) {
    pcVar8 = "header.SGN_ALG == header.SignAlgorithm";
    goto LAB_18000cfc3;
  }
  if (*(int *)(psVar3 + 2) != -1) {
    pcVar8 = "header.Filler == header.FillerBytes";
    goto LAB_18000cfc3;
  }
  HmacData(this,local_c8,(ReadOnlyBinary *)CONCAT71(in_stack_00000029,param_4));
  if (local_b8 < 0) {
    Logging::Verify::StatusFailed("Ksign",local_b8);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(long *)(param_1 + 0xc) = local_b8;
    goto LAB_18000d2a6;
  }
  local_78 = *(short **)(param_3 + 8);
  local_80 = 8;
  Concatenate(local_b0,&`private:_virtual_struct_Kerb3961::ReturnType<Kerb3961::OwnedBinary,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary&___ptr64)>___cdecl_Kerb3961::RC4_4757::CommonGetMIC(Kerb3961::ReadOnlyBinary_const&___ptr64,unsigned___int64,unsigned_int,Kerb3961::ReadOnlyBinary_const&___ptr64,bool,bool)___ptr64'
                        ::__l2::_S8,(ReadOnlyBinary *)&local_80);
  if (local_a0 < 0) {
    Logging::Verify::StatusFailed("signBuffer",local_a0);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(long *)(param_1 + 0xc) = local_a0;
  }
  else {
    HashData(this,local_98);
    if (local_88 < 0) {
      Logging::Verify::StatusFailed("hash",local_88);
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(long *)(param_1 + 0xc) = local_88;
    }
    else {
      HmacData(this,local_70,local_c8);
      if (local_60 < 0) {
        Logging::Verify::StatusFailed("checksum",local_60);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(long *)(param_1 + 0xc) = local_60;
      }
      else {
        bVar10 = 0;
        lVar11 = 8;
        pbVar9 = local_68;
        do {
          pbVar1 = pbVar9 + ((longlong)(psVar3 + 8) - (longlong)local_68);
          bVar2 = *pbVar9;
          pbVar9 = pbVar9 + 1;
          bVar10 = bVar10 | *pbVar1 ^ bVar2;
          lVar11 = lVar11 + -1;
        } while (lVar11 != 0);
        if (bVar10 == 0) {
          HmacData(this,(ReadOnlyBinary *)&local_e0,
                   (ReadOnlyBinary *)CONCAT71(in_stack_00000029,param_4));
          if (local_d0 < 0) {
LAB_18000d171:
            iVar4 = local_d0;
            Logging::Verify::StatusFailed("Kseq",local_d0);
            *(undefined8 *)param_1 = 0;
            *(undefined8 *)(param_1 + 8) = 0;
            *(int *)(param_1 + 0xc) = iVar4;
          }
          else {
            local_80 = 8;
            local_78 = psVar3 + 8;
            puVar6 = (undefined8 *)HmacData(this,local_48,(ReadOnlyBinary *)&local_e0);
            if (local_d8 != (void *)0x0) {
              operator_delete__(local_d8);
            }
            local_e0 = *puVar6;
            local_d8 = (void *)puVar6[1];
            *puVar6 = 0;
            puVar6[1] = 0;
            local_d0 = *(int *)(puVar6 + 2);
            *(undefined4 *)(puVar6 + 2) = 0xc0000001;
            if (local_40 != (void *)0x0) {
              operator_delete__(local_40);
            }
            if (local_d0 < 0) goto LAB_18000d171;
            local_e8 = *(undefined8 *)(psVar3 + 4);
            local_50 = &local_e8;
            local_58 = 8;
            RC4Data(this,local_res8,(MutableBinary *)&local_e0);
            if (local_e8._4_4_ == -(uint)param_5) {
              *(undefined4 *)(param_1 + 8) = 0;
              uVar7 = (uint)local_e8 >> 0x18 | ((uint)local_e8 & 0xff0000) >> 8 |
                      ((uint)local_e8 & 0xff00) << 8 | (uint)local_e8 << 0x18;
              *(undefined4 *)(param_1 + 0xc) = 0xc0000001;
              *(undefined4 *)(param_1 + 0xc) = 0;
              local_e8 = CONCAT44(local_e8._4_4_,uVar7);
              *(ulonglong *)param_1 = (ulonglong)uVar7;
            }
            else {
              Logging::Verify::ConditionFailed("seqCopy.Direction == expectedDirection");
              *(undefined8 *)param_1 = 0;
              *(undefined8 *)(param_1 + 8) = 0;
              *(undefined4 *)(param_1 + 0xc) = 0x8009030f;
            }
          }
          if (local_d8 != (void *)0x0) {
            operator_delete__(local_d8);
          }
        }
        else {
          Logging::Verify::ConditionFailed
                    (
                    "SecureEqualBuffer(checksum, reinterpret_cast<const uint8_t*>(&header.SGN_CKSUM), sizeof(header.SGN_CKSUM))"
                    );
          *(undefined8 *)param_1 = 0;
          *(undefined8 *)(param_1 + 8) = 0;
          *(undefined4 *)(param_1 + 0xc) = 0x8009030f;
        }
      }
      if (local_68 != (byte *)0x0) {
        operator_delete__(local_68);
      }
    }
    if (local_90 != (void *)0x0) {
      operator_delete__(local_90);
    }
  }
  if (local_a8 != (void *)0x0) {
    operator_delete__(local_a8);
  }
LAB_18000d2a6:
  if (local_c0 == (void *)0x0) {
    return param_1;
  }
  operator_delete__(local_c0);
  return param_1;
}



===== CommonWrapEncrypted @ 18000d2f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::RC4_4757::CommonWrapEncrypted(struct Kerb3961::MutableBinary const & __ptr64,struct
   Kerb3961::ReadOnlyBinary const & __ptr64,unsigned __int64,unsigned int,struct
   Kerb3961::ReadOnlyBinary const & __ptr64,bool,bool,unsigned __int64 * __ptr64) __ptr64 */

MutableBinary * __thiscall
Kerb3961::RC4_4757::CommonWrapEncrypted
          (RC4_4757 *this,MutableBinary *param_1,ReadOnlyBinary *param_2,__uint64 param_3,
          uint param_4,ReadOnlyBinary *param_5,bool param_6,bool param_7,__uint64 *param_8)

{
  uint *puVar1;
  long lVar2;
  ReadOnlyBinary *pRVar3;
  int iVar4;
  int iVar5;
  NTSTATUS NVar6;
  byte *pbVar7;
  undefined8 *puVar8;
  int *piVar9;
  byte *pbVar10;
  char *pcVar11;
  undefined7 in_stack_00000039;
  undefined8 *in_stack_00000050;
  undefined1 auStack_1b8 [32];
  undefined8 local_198;
  void *local_190;
  long local_188;
  undefined8 local_180;
  void *local_178;
  int local_170;
  undefined8 local_168;
  undefined8 *local_160;
  long local_158;
  ReadOnlyBinary local_150 [8];
  uint *local_148;
  long local_140;
  longlong local_138;
  byte *local_130;
  long local_128;
  undefined8 local_118;
  uint *local_110;
  undefined8 local_108;
  void *local_100;
  int local_f8;
  ReadOnlyBinary *local_f0;
  ReadOnlyBinary local_e8 [8];
  void *local_e0;
  int local_d8;
  ReadOnlyBinary *local_d0;
  ReadOnlyBinary *local_c8;
  undefined8 local_c0;
  uint *local_b8;
  undefined8 local_b0;
  uint *local_a8;
  long local_a0;
  undefined8 local_98;
  uint *local_90;
  undefined8 local_88;
  uint *local_80;
  size_t local_78;
  void *local_70;
  size_t local_68;
  void *local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStack_1b8;
  local_d0 = (ReadOnlyBinary *)CONCAT71(in_stack_00000039,param_6);
  local_f0 = param_2;
  local_c8 = (ReadOnlyBinary *)param_3;
  iVar4 = (**(code **)(*(longlong *)(this + 8) + 0x68))();
  iVar5 = (**(code **)(*(longlong *)this + 0xe0))(this);
  if (iVar4 != iVar5) {
                    /* WARNING: Subroutine does not return */
    ConsistencyFail((ushort *)
                    L"A cipher suite\'s included checksum must be the required checksum for the included cipher"
                   );
  }
  if ((int)param_5 != 0) {
    Logging::Verify::ConditionFailed("QOP == 0");
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0x8009030a;
    return param_1;
  }
  MakeBuffer((__uint64)&local_b0);
  if (local_a0 < 0) {
    Logging::Verify::StatusFailed("headerBuffer",local_a0);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(long *)(param_1 + 0x10) = local_a0;
LAB_18000d98c:
    if (local_a8 == (uint *)0x0) {
      return param_1;
    }
    goto LAB_18000d991;
  }
  if (in_stack_00000050 != (undefined8 *)0x0) {
    *in_stack_00000050 = 0;
  }
  local_88 = 8;
  local_98 = 8;
  local_c0 = 8;
  local_a8[0] = 0;
  local_a8[1] = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_90 = local_a8 + 4;
  local_a8[4] = 0;
  local_a8[5] = 0;
  local_a8[6] = 0;
  local_a8[7] = 0;
  *(undefined2 *)((longlong)local_a8 + 6) = 0xffff;
  local_b8 = local_a8 + 6;
  puVar1 = local_a8 + 2;
  *puVar1 = param_4 >> 0x18 | (param_4 & 0xff0000) >> 8 | (param_4 & 0xff00) << 8 | param_4 << 0x18;
  local_a8[3] = ~-(uint)param_7;
  *local_a8 = 0x110102;
  *(undefined2 *)(local_a8 + 1) = 0x10;
  local_80 = puVar1;
  NVar6 = BCryptGenRandom((BCRYPT_ALG_HANDLE)0x0,(PUCHAR)local_b8,8,2);
  if (NVar6 < 0) {
    Logging::Verify::StatusFailed("RandomFill(confounderBuffer)",NVar6);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(NTSTATUS *)(param_1 + 0x10) = NVar6;
    goto LAB_18000d991;
  }
  HmacData(this,local_150,local_d0);
  if (local_140 < 0) {
    Logging::Verify::StatusFailed("Ksign",local_140);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(long *)(param_1 + 0x10) = local_140;
  }
  else {
    local_118 = 8;
    local_110 = local_a8;
    Concatenate((ReadOnlyBinary *)&local_198,
                &`private:_virtual_struct_Kerb3961::ReturnType<Kerb3961::OwnedBinary,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary&___ptr64)>___cdecl_Kerb3961::RC4_4757::CommonWrapPlain(Kerb3961::ReadOnlyBinary_const&___ptr64,unsigned___int64,Kerb3961::ReadOnlyBinary_const&___ptr64,bool,bool)___ptr64'
                 ::__l2::_S27,(ReadOnlyBinary *)&local_118);
    lVar2 = local_188;
    if (local_188 < 0) {
      Logging::Verify::StatusFailed("signBuffer",local_188);
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(long *)(param_1 + 0x10) = lVar2;
    }
    else {
      CopyBuffer((ReadOnlyBinary *)&local_138);
      pbVar10 = local_130;
      if (local_128 < 0) {
        Logging::Verify::StatusFailed("Klocal",local_128);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(long *)(param_1 + 0x10) = local_128;
        pbVar10 = local_130;
        if (local_130 == (byte *)0x0) goto LAB_18000d50b;
      }
      else {
        if (local_138 != 0) {
          pbVar7 = local_130;
          do {
            *pbVar7 = *pbVar7 ^ 0xf0;
            pbVar7 = pbVar7 + 1;
            local_138 = local_138 + -1;
          } while (local_138 != 0);
        }
        HmacData(this,(ReadOnlyBinary *)&local_180,(ReadOnlyBinary *)&local_138);
        if (local_170 < 0) {
          pcVar11 = "Kcrypt";
          iVar4 = local_170;
LAB_18000d59c:
          Logging::Verify::StatusFailed(pcVar11,iVar4);
          *(undefined8 *)param_1 = 0;
          *(undefined8 *)(param_1 + 8) = 0;
LAB_18000d5ac:
          *(int *)(param_1 + 0x10) = iVar4;
        }
        else {
          local_118 = 4;
          local_110 = puVar1;
          puVar8 = (undefined8 *)
                   HmacData(this,(ReadOnlyBinary *)&local_138,(ReadOnlyBinary *)&local_180);
          if (local_178 != (void *)0x0) {
            operator_delete__(local_178);
          }
          local_180 = *puVar8;
          local_178 = (void *)puVar8[1];
          *puVar8 = 0;
          local_170 = *(int *)(puVar8 + 2);
          puVar8[1] = 0;
          *(undefined4 *)(puVar8 + 2) = 0xc0000001;
          if (local_130 != (byte *)0x0) {
            operator_delete__(local_130);
          }
          pRVar3 = local_f0;
          iVar4 = local_170;
          if (local_170 < 0) {
            Logging::Verify::StatusFailed("Kcrypt",local_170);
            *(undefined8 *)param_1 = 0;
            *(undefined8 *)(param_1 + 8) = 0;
            goto LAB_18000d5ac;
          }
          puVar8 = (undefined8 *)
                   Concatenate((ReadOnlyBinary *)&local_138,(ReadOnlyBinary *)&local_198,local_c8);
          if (local_190 != (void *)0x0) {
            operator_delete__(local_190);
          }
          local_198 = *puVar8;
          local_190 = (void *)puVar8[1];
          *puVar8 = 0;
          puVar8[1] = 0;
          local_188 = *(long *)(puVar8 + 2);
          *(undefined4 *)(puVar8 + 2) = 0xc0000001;
          if (local_130 != (byte *)0x0) {
            operator_delete__(local_130);
          }
          if (local_188 < 0) {
            pcVar11 = "signBuffer";
            iVar4 = local_188;
            goto LAB_18000d59c;
          }
          HashData(this,(ReadOnlyBinary *)&local_168);
          lVar2 = local_158;
          if (local_158 < 0) {
            Logging::Verify::StatusFailed("Sgn_Cksum",local_158);
            *(undefined8 *)param_1 = 0;
            *(undefined8 *)(param_1 + 8) = 0;
            *(long *)(param_1 + 0x10) = lVar2;
          }
          else {
            Concatenate(local_e8,(ReadOnlyBinary *)&local_c0);
            if (local_d8 < 0) {
              pcVar11 = "tmp";
              iVar4 = local_d8;
LAB_18000d737:
              Logging::Verify::StatusFailed(pcVar11,iVar4);
              *(undefined8 *)param_1 = 0;
              *(undefined8 *)(param_1 + 8) = 0;
LAB_18000d747:
              *(int *)(param_1 + 0x10) = iVar4;
            }
            else {
              piVar9 = (int *)RC4Data(this,(ReadOnlyBinary *)&local_f0,(MutableBinary *)&local_180);
              iVar4 = *piVar9;
              if (iVar4 < 0) {
                pcVar11 = "RC4Data(Kcrypt, tmp)";
                goto LAB_18000d737;
              }
              local_110 = *(uint **)pRVar3;
              local_118 = 8;
              Split<2>(&local_78,local_e8,&local_118);
              memmove(local_a8 + 6,local_70,local_78);
              memmove(*(void **)(pRVar3 + 8),local_60,local_68);
              puVar8 = (undefined8 *)HmacData(this,(ReadOnlyBinary *)&local_138,local_150);
              if (local_160 != (undefined8 *)0x0) {
                operator_delete__(local_160);
              }
              local_168 = *puVar8;
              local_160 = (undefined8 *)puVar8[1];
              *puVar8 = 0;
              local_158 = *(long *)(puVar8 + 2);
              puVar8[1] = 0;
              *(undefined4 *)(puVar8 + 2) = 0xc0000001;
              if (local_130 != (byte *)0x0) {
                operator_delete__(local_130);
              }
              iVar4 = local_158;
              if (local_158 < 0) {
                Logging::Verify::StatusFailed("Sgn_Cksum",local_158);
                *(undefined8 *)param_1 = 0;
                *(undefined8 *)(param_1 + 8) = 0;
                goto LAB_18000d747;
              }
              *(undefined8 *)(local_a8 + 4) = *local_160;
              HmacData(this,(ReadOnlyBinary *)&local_108,local_d0);
              if (local_f8 < 0) {
LAB_18000d86c:
                pcVar11 = "Kseq";
                iVar4 = local_f8;
              }
              else {
                puVar8 = (undefined8 *)
                         HmacData(this,(ReadOnlyBinary *)&local_138,(ReadOnlyBinary *)&local_108);
                if (local_100 != (void *)0x0) {
                  operator_delete__(local_100);
                }
                local_108 = *puVar8;
                local_100 = (void *)puVar8[1];
                *puVar8 = 0;
                local_f8 = *(int *)(puVar8 + 2);
                puVar8[1] = 0;
                *(undefined4 *)(puVar8 + 2) = 0xc0000001;
                if (local_130 != (byte *)0x0) {
                  operator_delete__(local_130);
                }
                if (local_f8 < 0) goto LAB_18000d86c;
                piVar9 = (int *)RC4Data(this,(ReadOnlyBinary *)&local_f0,(MutableBinary *)&local_108
                                       );
                iVar4 = *piVar9;
                if (-1 < iVar4) {
                  *(long *)(param_1 + 0x10) = local_a0;
                  *(undefined8 *)param_1 = local_b0;
                  *(uint **)(param_1 + 8) = local_a8;
                  if (local_100 != (void *)0x0) {
                    operator_delete__(local_100);
                  }
                  if (local_e0 != (void *)0x0) {
                    operator_delete__(local_e0);
                  }
                  if (local_160 != (undefined8 *)0x0) {
                    operator_delete__(local_160);
                  }
                  if (local_178 != (void *)0x0) {
                    operator_delete__(local_178);
                  }
                  if (pbVar10 != (byte *)0x0) {
                    operator_delete__(pbVar10);
                  }
                  if (local_190 != (void *)0x0) {
                    operator_delete__(local_190);
                  }
                  local_a8 = local_148;
                  goto LAB_18000d98c;
                }
                pcVar11 = "RC4Data(Kseq, sequenceBuffer)";
              }
              Logging::Verify::StatusFailed(pcVar11,iVar4);
              *(undefined8 *)param_1 = 0;
              *(undefined8 *)(param_1 + 8) = 0;
              *(int *)(param_1 + 0x10) = iVar4;
              if (local_100 != (void *)0x0) {
                operator_delete__(local_100);
              }
            }
            if (local_e0 != (void *)0x0) {
              operator_delete__(local_e0);
            }
          }
          if (local_160 != (undefined8 *)0x0) {
            operator_delete__(local_160);
          }
        }
        if (local_178 != (void *)0x0) {
          operator_delete__(local_178);
        }
        if (pbVar10 == (byte *)0x0) goto LAB_18000d50b;
      }
      operator_delete__(pbVar10);
    }
LAB_18000d50b:
    if (local_190 != (void *)0x0) {
      operator_delete__(local_190);
    }
  }
  if (local_148 != (uint *)0x0) {
    operator_delete__(local_148);
  }
LAB_18000d991:
  operator_delete__(local_a8);
  return param_1;
}



===== CommonWrapPlain @ 18000d9d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::RC4_4757::CommonWrapPlain(struct Kerb3961::ReadOnlyBinary const & __ptr64,unsigned
   __int64,struct Kerb3961::ReadOnlyBinary const & __ptr64,bool,bool) __ptr64 */

ReadOnlyBinary * __thiscall
Kerb3961::RC4_4757::CommonWrapPlain
          (RC4_4757 *this,ReadOnlyBinary *param_1,__uint64 param_2,ReadOnlyBinary *param_3,
          bool param_4,bool param_5)

{
  int iVar1;
  int iVar2;
  NTSTATUS NVar3;
  undefined8 *puVar4;
  int *piVar5;
  char *pcVar6;
  uint uVar7;
  ReadOnlyBinary local_res8 [8];
  undefined7 in_stack_00000029;
  undefined8 local_158;
  undefined8 *local_150;
  int local_148;
  undefined8 local_140;
  undefined8 uStack_138;
  long local_130;
  undefined8 local_128;
  void *local_120;
  int local_118;
  ReadOnlyBinary local_110 [8];
  undefined8 *local_108;
  long local_100;
  undefined8 local_f8;
  undefined8 *local_f0;
  long local_e8;
  undefined8 local_e0;
  undefined8 *local_d8;
  undefined8 local_d0;
  uint *local_c8;
  ReadOnlyBinary local_c0 [8];
  void *local_b8;
  undefined8 local_a8;
  uchar **ppuStack_a0;
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined8 local_58;
  undefined8 uStack_50;
  
  iVar1 = (**(code **)(*(longlong *)(this + 8) + 0x68))();
  iVar2 = (**(code **)(*(longlong *)this + 0xe0))(this);
  if (iVar1 != iVar2) {
                    /* WARNING: Subroutine does not return */
    ConsistencyFail((ushort *)
                    L"A cipher suite\'s included checksum must be the required checksum for the included cipher"
                   );
  }
  MakeBuffer((__uint64)&local_f8);
  if (local_e8 < 0) {
    Logging::Verify::StatusFailed("headerBuffer",local_e8);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(long *)(param_1 + 0x10) = local_e8;
LAB_18000dd97:
    if (local_f0 == (undefined8 *)0x0) {
      return param_1;
    }
    goto LAB_18000dd9c;
  }
  local_d0 = 8;
  uVar7 = (uint)param_3;
  local_e0 = 8;
  *local_f0 = 0;
  local_f0[1] = 0;
  local_c8 = (uint *)(local_f0 + 1);
  local_140 = 8;
  local_f0[2] = 0;
  local_f0[3] = 0;
  *(undefined4 *)((longlong)local_f0 + 4) = 0xffffffff;
  local_d8 = local_f0 + 2;
  uStack_138 = (PUCHAR)(local_f0 + 3);
  *local_c8 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18;
  *(uint *)((longlong)local_f0 + 0xc) = ~-(uint)param_5;
  *(undefined4 *)local_f0 = 0x110102;
  NVar3 = BCryptGenRandom((BCRYPT_ALG_HANDLE)0x0,uStack_138,8,2);
  if (NVar3 < 0) {
    Logging::Verify::StatusFailed("RandomFill(confounderBuffer)",NVar3);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(NTSTATUS *)(param_1 + 0x10) = NVar3;
    goto LAB_18000dd9c;
  }
  HmacData(this,local_110,(ReadOnlyBinary *)CONCAT71(in_stack_00000029,param_4));
  if (local_100 < 0) {
    Logging::Verify::StatusFailed("Ksign",local_100);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(long *)(param_1 + 0x10) = local_100;
  }
  else {
    local_58 = 8;
    uStack_50 = local_f0;
    puVar4 = uStack_50;
    local_78 = *(undefined4 *)param_2;
    uStack_74 = *(undefined4 *)(param_2 + 4);
    uStack_70 = *(undefined4 *)(param_2 + 8);
    uStack_6c = *(undefined4 *)(param_2 + 0xc);
    local_a8 = 4;
    ppuStack_a0 = &`private:_virtual_struct_Kerb3961::ReturnType<Kerb3961::OwnedBinary,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::OwnedBinary,16>(struct_Kerb3961::OwnedBinary&___ptr64)>___cdecl_Kerb3961::RC4_4757::CommonWrapEncrypted(Kerb3961::MutableBinary_const&___ptr64,Kerb3961::ReadOnlyBinary_const&___ptr64,unsigned___int64,unsigned_int,Kerb3961::ReadOnlyBinary_const&___ptr64,bool,bool,unsigned___int64*___ptr64)___ptr64'
                   ::__l2::salt;
    uStack_50._0_4_ = SUB84(local_f0,0);
    uStack_50._4_4_ = (undefined4)((ulonglong)local_f0 >> 0x20);
    local_98 = 8;
    uStack_94 = 0;
    uStack_90 = (undefined4)uStack_50;
    uStack_8c = uStack_50._4_4_;
    local_88 = (undefined4)local_140;
    uStack_84 = local_140._4_4_;
    uStack_80 = (undefined4)uStack_138;
    uStack_7c = uStack_138._4_4_;
    uStack_50 = puVar4;
    Concatenate<4>(&local_140,&local_a8);
    if (local_130 < 0) {
      Logging::Verify::StatusFailed("signBuffer",local_130);
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(long *)(param_1 + 0x10) = local_130;
    }
    else {
      HashData(this,(ReadOnlyBinary *)&local_158);
      if (local_148 < 0) {
LAB_18000dbd5:
        iVar1 = local_148;
        Logging::Verify::StatusFailed("Sgn_Cksum",local_148);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(int *)(param_1 + 0x10) = iVar1;
      }
      else {
        puVar4 = (undefined8 *)HmacData(this,local_c0,local_110);
        if (local_150 != (undefined8 *)0x0) {
          operator_delete__(local_150);
        }
        local_158 = *puVar4;
        local_150 = (undefined8 *)puVar4[1];
        *puVar4 = 0;
        local_148 = *(int *)(puVar4 + 2);
        puVar4[1] = 0;
        *(undefined4 *)(puVar4 + 2) = 0xc0000001;
        if (local_b8 != (void *)0x0) {
          operator_delete__(local_b8);
        }
        if (local_148 < 0) goto LAB_18000dbd5;
        local_f0[2] = *local_150;
        HmacData(this,(ReadOnlyBinary *)&local_128,
                 (ReadOnlyBinary *)CONCAT71(in_stack_00000029,param_4));
        if (local_118 < 0) {
LAB_18000dc98:
          pcVar6 = "Kseq";
          iVar1 = local_118;
        }
        else {
          puVar4 = (undefined8 *)HmacData(this,local_c0,(ReadOnlyBinary *)&local_128);
          if (local_120 != (void *)0x0) {
            operator_delete__(local_120);
          }
          local_128 = *puVar4;
          local_120 = (void *)puVar4[1];
          *puVar4 = 0;
          local_118 = *(int *)(puVar4 + 2);
          puVar4[1] = 0;
          *(undefined4 *)(puVar4 + 2) = 0xc0000001;
          if (local_b8 != (void *)0x0) {
            operator_delete__(local_b8);
          }
          if (local_118 < 0) goto LAB_18000dc98;
          piVar5 = (int *)RC4Data(this,local_res8,(MutableBinary *)&local_128);
          iVar1 = *piVar5;
          if (-1 < iVar1) {
            *(long *)(param_1 + 0x10) = local_e8;
            *(undefined8 *)param_1 = local_f8;
            *(undefined8 **)(param_1 + 8) = local_f0;
            if (local_120 != (void *)0x0) {
              operator_delete__(local_120);
            }
            if (local_150 != (undefined8 *)0x0) {
              operator_delete__(local_150);
            }
            if (uStack_138 != (PUCHAR)0x0) {
              operator_delete__(uStack_138);
            }
            local_f0 = local_108;
            goto LAB_18000dd97;
          }
          pcVar6 = "RC4Data(Kseq, sequenceBuffer)";
        }
        Logging::Verify::StatusFailed(pcVar6,iVar1);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(int *)(param_1 + 0x10) = iVar1;
        if (local_120 != (void *)0x0) {
          operator_delete__(local_120);
        }
      }
      if (local_150 != (undefined8 *)0x0) {
        operator_delete__(local_150);
      }
    }
    if (uStack_138 != (PUCHAR)0x0) {
      operator_delete__(uStack_138);
    }
  }
  if (local_108 != (undefined8 *)0x0) {
    operator_delete__(local_108);
  }
LAB_18000dd9c:
  operator_delete__(local_f0);
  return param_1;
}



===== Decrypt @ 18000dde0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::RC4_4757::Decrypt(struct Kerb3961::ReturnType<struct
   Kerb3961::SpecificKeyReturn,&struct Kerb3961::ResultBlock const & __ptr64 __cdecl
   Kerb3961::SingleGetter<struct Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn
   const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn & __ptr64)> & __ptr64,struct
   Kerb3961::ReturnType<struct Kerb3961::CipherStateReturn,&struct Kerb3961::ResultBlock const &
   __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::CipherStateReturn,16>(struct
   Kerb3961::CipherStateReturn const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::CipherStateReturn,16>(struct Kerb3961::CipherStateReturn
   & __ptr64)> & __ptr64,struct Kerb3961::ReadOnlyBinary const & __ptr64,struct
   Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64 */

ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
* __thiscall
Kerb3961::RC4_4757::Decrypt
          (RC4_4757 *this,
          ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
          *param_1,ReturnType<Kerb3961::CipherStateReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn&___ptr64)>
                   *param_2,ReadOnlyBinary *param_3,ReadOnlyBinary *param_4)

{
  size_t _Size;
  byte *pbVar1;
  byte bVar2;
  long lVar3;
  ReadOnlyBinary *pRVar4;
  ulonglong uVar5;
  bool bVar6;
  long *plVar7;
  char *pcVar8;
  byte *pbVar9;
  byte bVar10;
  long lVar11;
  undefined1 auStack_108 [32];
  undefined4 local_e8 [2];
  ReadOnlyBinary local_e0 [8];
  byte *local_d8;
  long local_d0;
  ReadOnlyBinary local_c8 [8];
  void *local_c0;
  long local_b8;
  undefined8 local_a8;
  undefined4 *local_a0;
  ReadOnlyBinary local_98 [8];
  void *local_90;
  long local_88;
  ulonglong local_80;
  byte *local_78;
  long local_70;
  ReadOnlyBinary local_68 [8];
  ulonglong local_60;
  longlong local_58;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_108;
  if (this != *(RC4_4757 **)param_2) {
    pcVar8 = "this == specificKey.algorithm";
LAB_18000de20:
    Logging::Verify::ConditionFailed(pcVar8);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0xc000000d;
    return param_1;
  }
  if (this != *(RC4_4757 **)param_3) {
    pcVar8 = "this == cipherState.algorithm";
    goto LAB_18000de20;
  }
  pRVar4 = *(ReadOnlyBinary **)(param_2 + 8);
  local_e8[0] = *(undefined4 *)(pRVar4 + 0x18);
  uVar5 = *(ulonglong *)param_4;
  if (0xffffffff < uVar5) {
    pcVar8 = "cipherText.length <= utl::numeric_limits<uint32_t>::max()";
    goto LAB_18000de20;
  }
  if (uVar5 < 0x18) {
    pcVar8 = "cipherText.length >= EncryptionHeaderSize";
    goto LAB_18000de20;
  }
  _Size = uVar5 - 0x18;
  local_a8 = 0x10;
  local_a0 = (undefined4 *)(uVar5 - 0x10);
  Split<2>(&local_60,param_4,&local_a8);
  local_a0 = local_e8;
  local_a8 = 4;
  HmacData(this,local_c8,pRVar4);
  if (local_b8 < 0) {
    Logging::Verify::StatusFailed("K1",local_b8);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(long *)(param_1 + 0x10) = local_b8;
    goto LAB_18000e08d;
  }
  HmacData(this,local_98,local_c8);
  if (local_88 < 0) {
    Logging::Verify::StatusFailed("K3",local_88);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(long *)(param_1 + 0x10) = local_88;
  }
  else {
    CopyBuffer(local_e0);
    lVar11 = local_d0;
    if (local_d0 < 0) {
      Logging::Verify::StatusFailed("result",local_d0);
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
LAB_18000e071:
      *(long *)(param_1 + 0x10) = lVar11;
    }
    else {
      plVar7 = (long *)RC4Data(this,local_68,(MutableBinary *)local_98);
      lVar3 = *plVar7;
      if (lVar3 < 0) {
        Logging::Verify::StatusFailed("RC4Data(K3, result)",lVar3);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(long *)(param_1 + 0x10) = lVar3;
      }
      else {
        HmacData(this,(ReadOnlyBinary *)&local_80,local_c8);
        if (local_70 < 0) {
          Logging::Verify::StatusFailed("checksum",local_70);
          *(undefined8 *)param_1 = 0;
          *(undefined8 *)(param_1 + 8) = 0;
          *(long *)(param_1 + 0x10) = local_70;
        }
        else {
          if (local_80 == local_60) {
            if (local_80 == 0) {
              bVar6 = true;
            }
            else {
              if (0xffffffff < local_80) goto LAB_18000e026;
              bVar10 = 0;
              bVar6 = true;
              if ((int)local_80 != 0) {
                local_80 = local_80 & 0xffffffff;
                pbVar9 = local_78;
                do {
                  pbVar1 = pbVar9 + (local_58 - (longlong)local_78);
                  bVar2 = *pbVar9;
                  pbVar9 = pbVar9 + 1;
                  bVar10 = bVar10 | *pbVar1 ^ bVar2;
                  local_80 = local_80 - 1;
                } while (local_80 != 0);
                lVar11 = local_d0;
                if (bVar10 != 0) goto LAB_18000e026;
              }
            }
          }
          else {
LAB_18000e026:
            bVar6 = false;
          }
          if (bVar6) {
            memmove(local_d8,local_d8 + 8,_Size);
            pbVar9 = local_d8 + _Size;
            pbVar9[0] = 0;
            pbVar9[1] = 0;
            pbVar9[2] = 0;
            pbVar9[3] = 0;
            pbVar9[4] = 0;
            pbVar9[5] = 0;
            pbVar9[6] = 0;
            pbVar9[7] = 0;
            *(size_t *)param_1 = _Size;
            *(byte **)(param_1 + 8) = local_d8;
            local_d8 = local_78;
            goto LAB_18000e071;
          }
          Logging::Verify::ConditionFailed("SecureEqualBuffer(checksum, MIC)");
          *(undefined8 *)param_1 = 0;
          *(undefined8 *)(param_1 + 8) = 0;
          *(undefined4 *)(param_1 + 0x10) = 0x8009030f;
        }
        if (local_78 != (byte *)0x0) {
          operator_delete__(local_78);
        }
      }
    }
    if (local_d8 != (byte *)0x0) {
      operator_delete__(local_d8);
    }
  }
  if (local_90 != (void *)0x0) {
    operator_delete__(local_90);
  }
LAB_18000e08d:
  if (local_c0 == (void *)0x0) {
    return param_1;
  }
  operator_delete__(local_c0);
  return param_1;
}



===== DeriveSpecificKey @ 18000e0d0 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::SpecificKeyReturn,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn & __ptr64)> __cdecl
   Kerb3961::RC4_4757::DeriveSpecificKey(struct Kerb3961::ReadOnlyBinary const & __ptr64,enum
   Kerb3961::KeyUsage,enum Kerb3961::SpecificKeyScenario) __ptr64 */

ReadOnlyBinary * __thiscall
Kerb3961::RC4_4757::DeriveSpecificKey
          (RC4_4757 *this,ReadOnlyBinary *param_1,KeyUsage param_2,SpecificKeyScenario param_3)

{
  long lVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined4 in_register_0000008c;
  ReadOnlyBinary local_28 [8];
  void *local_20;
  
  puVar2 = operator_new__(0x20,(nothrow_t *)param_1);
  if (puVar2 == (undefined8 *)0x0) {
    Logging::Verify::ConditionFailed("specificKey");
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0xc0000017;
  }
  else {
    *(undefined8 *)((longlong)puVar2 + 0x14) = 0;
    *(undefined4 *)((longlong)puVar2 + 0x1c) = 0;
    *puVar2 = 0;
    puVar2[1] = 0;
    *(undefined4 *)(puVar2 + 2) = 0xc0000001;
    puVar3 = (undefined8 *)CopyBuffer(local_28);
    if ((void *)puVar2[1] != (void *)0x0) {
      operator_delete__((void *)puVar2[1]);
    }
    *puVar2 = *puVar3;
    *puVar3 = 0;
    puVar2[1] = puVar3[1];
    puVar3[1] = 0;
    *(undefined4 *)(puVar2 + 2) = *(undefined4 *)(puVar3 + 2);
    *(undefined4 *)(puVar3 + 2) = 0xc0000001;
    if (local_20 != (void *)0x0) {
      operator_delete__(local_20);
    }
    lVar1 = *(long *)(puVar2 + 2);
    if (lVar1 < 0) {
      Logging::Verify::StatusFailed("specificKey->key",lVar1);
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(long *)(param_1 + 0x10) = lVar1;
      if ((void *)puVar2[1] != (void *)0x0) {
        operator_delete__((void *)puVar2[1]);
      }
      operator_delete__(puVar2);
    }
    else {
      puVar2[3] = CONCAT44(in_register_0000008c,param_3);
      if (CONCAT44(in_register_0000008c,param_3) == 3) {
        puVar2[3] = 8;
      }
      *(undefined4 *)(param_1 + 0x10) = 0;
      *(RC4_4757 **)param_1 = this;
      *(undefined8 **)(param_1 + 8) = puVar2;
    }
  }
  return param_1;
}



===== EnabledForAccountCommon @ 18000e210 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: bool __cdecl Kerb3961::RC4_4757::EnabledForAccountCommon(struct
   Kerb3961::KeyPolicyScenario,unsigned int,enum Kerb3961::UserPolicyAttributes) __ptr64 */

bool __thiscall
Kerb3961::RC4_4757::EnabledForAccountCommon
          (RC4_4757 *this,undefined4 *param_2,uint param_3,uint param_4)

{
  byte bVar1;
  ulonglong uVar2;
  bool bVar3;
  uint uVar4;
  bool bVar5;
  char cStackX_9;
  
  bVar3 = false;
  uVar4 = param_3;
  if (((short)param_3 != 0) || ((*(byte *)(param_2 + 1) & 2) == 0)) goto LAB_18000e2ac;
  uVar2 = Feature_184236346__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 == 0) {
    bVar5 = false;
  }
  else {
    bVar5 = *(int *)(this + 0x68) == 2;
  }
  bVar1 = *(byte *)(param_2 + 1);
  uVar2 = Feature_Servicing_KerbRC4NewUsage__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 == 0) {
    if ((param_4 & 0x80) == 0) {
      if ((param_4 & 3) != 0) goto LAB_18000e2ac;
LAB_18000e295:
      if (bVar5) goto LAB_18000e2ac;
    }
  }
  else {
    if ((param_4 & 3) != 0) goto LAB_18000e2ac;
    if (((param_4 & 0x80) == 0) && ((bVar1 & 8) != 0)) goto LAB_18000e295;
  }
  param_3 = (**(code **)(*(longlong *)this + 0x30))(this);
LAB_18000e2ac:
  cStackX_9 = (char)((uint)*param_2 >> 8);
  if (((cStackX_9 == '\x02') || ((param_3 & 4) != 0)) || (cStackX_9 == '\b')) {
    bVar3 = true;
  }
  Logging::Cipher::UsageEnabled
            (*(ushort **)(this + 0x28),bVar3,CONCAT31((int3)(uVar4 >> 8),cStackX_9),param_3);
  return bVar3;
}



===== Encrypt @ 18000e310 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::RC4_4757::Encrypt(struct Kerb3961::ReturnType<struct
   Kerb3961::SpecificKeyReturn,&struct Kerb3961::ResultBlock const & __ptr64 __cdecl
   Kerb3961::SingleGetter<struct Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn
   const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn & __ptr64)> & __ptr64,struct
   Kerb3961::ReturnType<struct Kerb3961::CipherStateReturn,&struct Kerb3961::ResultBlock const &
   __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::CipherStateReturn,16>(struct
   Kerb3961::CipherStateReturn const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::CipherStateReturn,16>(struct Kerb3961::CipherStateReturn
   & __ptr64)> & __ptr64,struct Kerb3961::ReadOnlyBinary const & __ptr64,struct
   Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64 */

ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
* __thiscall
Kerb3961::RC4_4757::Encrypt
          (RC4_4757 *this,
          ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
          *param_1,ReturnType<Kerb3961::CipherStateReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::CipherStateReturn,16>(struct_Kerb3961::CipherStateReturn&___ptr64)>
                   *param_2,ReadOnlyBinary *param_3,ReadOnlyBinary *param_4)

{
  undefined8 uVar1;
  NTSTATUS NVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  undefined1 auStack_108 [32];
  undefined4 local_e8 [2];
  ReadOnlyBinary *local_e0;
  undefined8 local_d8;
  undefined4 *local_d0;
  ReadOnlyBinary local_c8 [8];
  void *local_c0;
  long local_b8;
  undefined4 *local_b0;
  undefined8 local_a8;
  void *local_a0;
  long local_98;
  ReadOnlyBinary local_90 [8];
  void *local_88;
  int local_80;
  ReadOnlyBinary local_78 [8];
  undefined8 *local_70;
  long local_68;
  undefined1 local_60 [8];
  undefined8 *local_58;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_108;
  if (this != *(RC4_4757 **)param_2) {
    pcVar4 = "this == specificKey.algorithm";
LAB_18000e350:
    Logging::Verify::ConditionFailed(pcVar4);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0xc000000d;
    return param_1;
  }
  if (this != *(RC4_4757 **)param_3) {
    pcVar4 = "this == cipherState.algorithm";
    goto LAB_18000e350;
  }
  local_e0 = *(ReadOnlyBinary **)(param_2 + 8);
  local_e8[0] = *(undefined4 *)(local_e0 + 0x18);
  if (0xffffffe7 < *(ulonglong *)param_4) {
    Logging::Verify::ConditionFailed
              (
              "static_cast<size_t>(clearData.length) <= static_cast<size_t>(utl::numeric_limits<uint32_t>::max() - EncryptionHeaderSize)"
              );
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0xc0000095;
    return param_1;
  }
  local_b0 = (undefined4 *)(*(ulonglong *)param_4 + 8);
  MakeBuffer((__uint64)&local_a8);
  if (local_98 < 0) {
    Logging::Verify::StatusFailed("result",local_98);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(long *)(param_1 + 0x10) = local_98;
LAB_18000e5b8:
    if (local_a0 == (void *)0x0) {
      return param_1;
    }
    goto LAB_18000e5bd;
  }
  NVar2 = BCryptGenRandom((BCRYPT_ALG_HANDLE)0x0,(PUCHAR)((longlong)local_a0 + 0x10),8,2);
  if (NVar2 < 0) {
    Logging::Verify::StatusFailed
              ("RandomFill({sizeof(header.confounder), header.confounder})",NVar2);
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(NTSTATUS *)(param_1 + 0x10) = NVar2;
  }
  else {
    memmove((void *)((longlong)local_a0 + 0x18),*(void **)(param_4 + 8),*(size_t *)param_4);
    local_d0 = local_e8;
    local_d8 = 4;
    HmacData(this,local_c8,local_e0);
    if (local_b8 < 0) {
      Logging::Verify::StatusFailed("K1",local_b8);
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(long *)(param_1 + 0x10) = local_b8;
    }
    else {
      local_d0 = local_b0;
      local_d8 = 0x10;
      Split<2>(local_60,&local_a8,&local_d8);
      HmacData(this,local_78,local_c8);
      if (local_68 < 0) {
        Logging::Verify::StatusFailed("checksum",local_68);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(long *)(param_1 + 0x10) = local_68;
        if (local_70 == (undefined8 *)0x0) goto LAB_18000e49e;
      }
      else {
        uVar1 = local_70[1];
        *local_58 = *local_70;
        local_58[1] = uVar1;
        HmacData(this,local_90,local_c8);
        if (local_80 < 0) {
          pcVar4 = "K3";
          iVar5 = local_80;
        }
        else {
          piVar3 = (int *)RC4Data(this,(ReadOnlyBinary *)&local_e0,(MutableBinary *)local_90);
          iVar5 = *piVar3;
          if (-1 < iVar5) {
            *(long *)(param_1 + 0x10) = local_98;
            *(undefined8 *)param_1 = local_a8;
            *(void **)(param_1 + 8) = local_a0;
            if (local_88 != (void *)0x0) {
              operator_delete__(local_88);
            }
            operator_delete__(local_70);
            local_a0 = local_c0;
            goto LAB_18000e5b8;
          }
          pcVar4 = "RC4Data(K3, encryptedPart)";
        }
        Logging::Verify::StatusFailed(pcVar4,iVar5);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(int *)(param_1 + 0x10) = iVar5;
        if (local_88 != (void *)0x0) {
          operator_delete__(local_88);
        }
      }
      operator_delete__(local_70);
    }
LAB_18000e49e:
    if (local_c0 != (void *)0x0) {
      operator_delete__(local_c0);
    }
  }
  if (local_a0 == (void *)0x0) {
    return param_1;
  }
LAB_18000e5bd:
  operator_delete__(local_a0);
  return param_1;
}



===== FreeCipherState @ 18000e600 =====

/* private: virtual void __cdecl Kerb3961::RC4_4757::FreeCipherState(void * __ptr64) __ptr64 */

void __thiscall Kerb3961::RC4_4757::FreeCipherState(RC4_4757 *this,void *param_1)

{
  return;
}



===== FreeSpecificKey @ 18000e610 =====

/* private: virtual void __cdecl Kerb3961::RC4_4757::FreeSpecificKey(void * __ptr64) __ptr64 */

void __thiscall Kerb3961::RC4_4757::FreeSpecificKey(RC4_4757 *this,void *param_1)

{
  if (param_1 != (void *)0x0) {
    if (*(void **)((longlong)param_1 + 8) != (void *)0x0) {
      operator_delete__(*(void **)((longlong)param_1 + 8));
    }
    operator_delete__(param_1);
  }
  return;
}



===== GetChecksumName @ 18000e640 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::ReadOnlyStringResult,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::ReadOnlyStringResult,16>(struct Kerb3961::ReadOnlyStringResult const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::ReadOnlyStringResult,16>(struct Kerb3961::ReadOnlyStringResult & __ptr64)> const
   __cdecl Kerb3961::RC4_4757::GetChecksumName(void) __ptr64 */

void __thiscall Kerb3961::RC4_4757::GetChecksumName(RC4_4757 *this)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 *in_RDX;
  
  uVar1 = *(undefined8 *)(this + 0x38);
  uVar2 = *(undefined8 *)(this + 0x30);
  *(undefined4 *)(in_RDX + 2) = 0;
  *in_RDX = uVar1;
  in_RDX[1] = uVar2;
  return;
}



===== GetCipherAttributes @ 18000e660 =====

/* private: virtual enum Kerb3961::CipherAttributes __cdecl
   Kerb3961::RC4_4757::GetCipherAttributes(void) __ptr64 */

CipherAttributes __thiscall Kerb3961::RC4_4757::GetCipherAttributes(RC4_4757 *this)

{
  int iVar1;
  ulonglong uVar2;
  CipherAttributes CVar3;
  
  uVar2 = Feature_184236346__private_IsEnabledDeviceUsageNoInline();
  CVar3 = 0;
  if ((int)uVar2 == 0) {
    CVar3 = *(CipherAttributes *)(this + 0x48);
  }
  else {
    iVar1 = *(int *)(this + 0x68);
    if (iVar1 == 1) {
      CVar3 = 0x40;
    }
    else if (iVar1 == 2) {
      CVar3 = 0xc0;
    }
    else if (iVar1 == 3) {
      CVar3 = 0x1c0;
    }
    CVar3 = CVar3 | *(CipherAttributes *)(this + 0x48);
  }
  return CVar3;
}



===== GetCipherBitmask @ 18000e6c0 =====

/* private: virtual unsigned int __cdecl Kerb3961::RC4_4757::GetCipherBitmask(void) __ptr64 */

uint __thiscall Kerb3961::RC4_4757::GetCipherBitmask(RC4_4757 *this)

{
  return 4;
}



===== GetCipherName @ 18000e6e0 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::ReadOnlyStringResult,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::ReadOnlyStringResult,16>(struct Kerb3961::ReadOnlyStringResult const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::ReadOnlyStringResult,16>(struct Kerb3961::ReadOnlyStringResult & __ptr64)> const
   __cdecl Kerb3961::RC4_4757::GetCipherName(void) __ptr64 */

void __thiscall Kerb3961::RC4_4757::GetCipherName(RC4_4757 *this)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 *in_RDX;
  
  uVar1 = *(undefined8 *)(this + 0x30);
  uVar2 = *(undefined8 *)(this + 0x28);
  *(undefined4 *)(in_RDX + 2) = 0;
  *in_RDX = uVar1;
  in_RDX[1] = uVar2;
  return;
}



===== GetCiphertextLength @ 18000e700 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::ResultAdapter<unsigned
   __int64>,&struct Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::ResultAdapter<unsigned __int64>,8>(struct Kerb3961::ResultAdapter<unsigned __int64>
   const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::ResultAdapter<unsigned __int64>,8>(struct Kerb3961::ResultAdapter<unsigned __int64> &
   __ptr64)> __cdecl Kerb3961::RC4_4757::GetCiphertextLength(unsigned __int64) __ptr64 */

__uint64 __thiscall Kerb3961::RC4_4757::GetCiphertextLength(RC4_4757 *this,__uint64 param_1)

{
  ulonglong in_R8;
  
  if (in_R8 < 0xffffffe8) {
    *(undefined4 *)(param_1 + 8) = 0xc0000001;
    *(undefined4 *)(param_1 + 8) = 0;
    *(ulonglong *)param_1 = in_R8 + 0x18;
  }
  else {
    Logging::Verify::ConditionFailed
              (
              "static_cast<size_t>(plaintextLength) <= static_cast<size_t>(utl::numeric_limits<uint32_t>::max() - EncryptionHeaderSize)"
              );
    *(undefined8 *)param_1 = 0;
    *(undefined4 *)(param_1 + 8) = 0xc0000001;
    *(undefined4 *)(param_1 + 8) = 0xc0000095;
  }
  return param_1;
}



===== GetMic @ 18000e760 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::RC4_4757::GetMic(struct Kerb3961::ReturnType<struct Kerb3961::SpecificKeyReturn,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn & __ptr64)> & __ptr64,struct
   Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64 */

ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
* __thiscall
Kerb3961::RC4_4757::GetMic
          (RC4_4757 *this,
          ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
          *param_1,ReadOnlyBinary *param_2)

{
  RC4_4757 *this_00;
  ulonglong *in_R9;
  undefined1 auStack_c8 [32];
  undefined4 local_a8 [2];
  undefined8 local_a0;
  undefined4 *local_98;
  ReadOnlyBinary local_90 [8];
  void *local_88;
  long local_80;
  ReadOnlyBinary local_78 [8];
  void *local_70;
  long local_68;
  ReadOnlyBinary local_60 [8];
  void *local_58;
  long local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined1 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_c8;
  this_00 = this + -8;
  if (this_00 == *(RC4_4757 **)param_2) {
    local_a0 = 0xd;
    local_a8[0] = *(undefined4 *)(*(ReadOnlyBinary **)(param_2 + 8) + 0x18);
    local_98 = &local_48;
    local_48 = 0x6e676973;
    local_44 = 0x72757461;
    local_40 = 0x79656b65;
    local_3c = 0;
    HmacData(this_00,local_90,*(ReadOnlyBinary **)(param_2 + 8));
    if (local_80 < 0) {
      Logging::Verify::StatusFailed("Ksign",local_80);
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(long *)(param_1 + 0x10) = local_80;
    }
    else if (*in_R9 < 0xfffffffc) {
      local_98 = local_a8;
      local_a0 = 4;
      Concatenate(local_78,(ReadOnlyBinary *)&local_a0);
      if (local_68 < 0) {
        Logging::Verify::StatusFailed("hashData",local_68);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(long *)(param_1 + 0x10) = local_68;
      }
      else {
        HashData(this_00,local_60);
        if (local_50 < 0) {
          Logging::Verify::StatusFailed("tmp",local_50);
          *(undefined8 *)param_1 = 0;
          *(undefined8 *)(param_1 + 8) = 0;
          *(long *)(param_1 + 0x10) = local_50;
        }
        else {
          HmacData(this_00,(ReadOnlyBinary *)param_1,local_90);
        }
        if (local_58 != (void *)0x0) {
          operator_delete__(local_58);
        }
      }
      if (local_70 != (void *)0x0) {
        operator_delete__(local_70);
      }
    }
    else {
      Logging::Verify::ConditionFailed
                ("message.length <= utl::numeric_limits<uint32_t>::max() - sizeof(uint32_t)");
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(undefined4 *)(param_1 + 0x10) = 0xc000000d;
    }
    if (local_88 != (void *)0x0) {
      operator_delete__(local_88);
    }
  }
  else {
    Logging::Verify::ConditionFailed("this == specificKey.algorithm");
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0xc000000d;
  }
  return param_1;
}



===== GetSSPISizes @ 18000e920 =====

/* private: virtual struct Kerb3961::SSPISizes const & __ptr64 __cdecl
   Kerb3961::RC4_4757::GetSSPISizes(void) __ptr64 */

SSPISizes * __thiscall Kerb3961::RC4_4757::GetSSPISizes(RC4_4757 *this)

{
  return &`private:_virtual_struct_Kerb3961::SSPISizes_const&___ptr64___cdecl_Kerb3961::RC4_4757::GetSSPISizes(void)___ptr64'
          ::__l2::sspiSizes;
}



===== HashData @ 18000e930 =====

/* private: struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct Kerb3961::ResultBlock
   const & __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::OwnedBinary,16>(struct
   Kerb3961::OwnedBinary const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)>
   __cdecl Kerb3961::RC4_4757::HashData(struct Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64 */

ReadOnlyBinary * __thiscall Kerb3961::RC4_4757::HashData(RC4_4757 *this,ReadOnlyBinary *param_1)

{
  long lVar1;
  ulonglong *in_R8;
  void *local_res18;
  
  if (*in_R8 < 0x100000000) {
    utl::make_unique<unsigned_char_[0],0>((__uint64)&local_res18);
    lVar1 = BCryptHash(*(undefined8 *)(this + 0x58),0,0,in_R8[1],(int)*in_R8,local_res18,0x10);
    if (lVar1 < 0) {
      Logging::Verify::StatusFailed
                ("BCryptHash(m_hashHandle, nullptr, 0, const_cast<uint8_t*>(data.buffer), static_cast<uint32_t>(data.length), result.get(), HASH_SIZE)"
                 ,lVar1);
      *(undefined8 *)param_1 = 0;
      *(undefined8 *)(param_1 + 8) = 0;
      *(long *)(param_1 + 0x10) = lVar1;
      if (local_res18 != (void *)0x0) {
        operator_delete__(local_res18);
      }
    }
    else {
      *(undefined8 *)param_1 = 0x10;
      *(void **)(param_1 + 8) = local_res18;
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
  }
  else {
    Logging::Verify::ConditionFailed
              (
              "static_cast<size_t>(data.length) <= static_cast<size_t>(utl::numeric_limits<uint32_t>::max())"
              );
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0xc0000095;
  }
  return param_1;
}



===== HmacData @ 18000ea14 =====

/* private: struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct Kerb3961::ResultBlock
   const & __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::OwnedBinary,16>(struct
   Kerb3961::OwnedBinary const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)>
   __cdecl Kerb3961::RC4_4757::HmacData(struct Kerb3961::ReadOnlyBinary const & __ptr64,struct
   Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64 */

ReadOnlyBinary * __thiscall
Kerb3961::RC4_4757::HmacData(RC4_4757 *this,ReadOnlyBinary *param_1,ReadOnlyBinary *param_2)

{
  long lVar1;
  char *pcVar2;
  ulonglong *in_R9;
  undefined8 local_38;
  void *local_30;
  long local_28;
  
  if (*in_R9 < 0x100000000) {
    if (*(ulonglong *)param_2 < 0x100000000) {
      MakeBuffer((__uint64)&local_38);
      if (local_28 < 0) {
        Logging::Verify::StatusFailed("result",local_28);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(long *)(param_1 + 0x10) = local_28;
        if (local_30 == (void *)0x0) {
          return param_1;
        }
      }
      else {
        lVar1 = BCryptHash(*(undefined8 *)(this + 0x60),*(undefined8 *)(param_2 + 8),
                           *(undefined4 *)param_2,in_R9[1],(int)*in_R9,local_30,0x10);
        if (-1 < lVar1) {
          *(undefined8 *)param_1 = local_38;
          *(long *)(param_1 + 0x10) = local_28;
          *(void **)(param_1 + 8) = local_30;
          return param_1;
        }
        Logging::Verify::StatusFailed
                  ("BCryptHash(m_checksumHandle, const_cast<uint8_t*>(key.buffer), static_cast<uint32_t>(key.length), const_cast<uint8_t*>(data.buffer), static_cast<uint32_t>(data.length), result.buffer, HASH_SIZE)"
                   ,lVar1);
        *(undefined8 *)param_1 = 0;
        *(undefined8 *)(param_1 + 8) = 0;
        *(long *)(param_1 + 0x10) = lVar1;
        if (local_30 == (void *)0x0) {
          return param_1;
        }
      }
      operator_delete__(local_30);
      return param_1;
    }
    pcVar2 = 
    "static_cast<size_t>(key.length) <= static_cast<size_t>(utl::numeric_limits<uint32_t>::max())";
  }
  else {
    pcVar2 = 
    "static_cast<size_t>(data.length) <= static_cast<size_t>(utl::numeric_limits<uint32_t>::max())";
  }
  Logging::Verify::ConditionFailed(pcVar2);
  *(undefined8 *)param_1 = 0;
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0xc0000095;
  return param_1;
}



===== Initialize @ 18000eb50 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::StatusOnly,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly & __ptr64)> __cdecl
   Kerb3961::RC4_4757::Initialize(void) __ptr64 */

void __thiscall Kerb3961::RC4_4757::Initialize(RC4_4757 *this)

{
  NTSTATUS NVar1;
  char *pcVar2;
  long *in_RDX;
  
  NVar1 = BCryptOpenAlgorithmProvider((BCRYPT_ALG_HANDLE *)(this + 0x50),L"RC4",(LPCWSTR)0x0,0);
  if (NVar1 < 0) {
    pcVar2 = "BCryptOpenAlgorithmProvider(&m_cipherHandle, BCRYPT_RC4_ALGORITHM, nullptr, 0)";
  }
  else {
    NVar1 = BCryptOpenAlgorithmProvider((BCRYPT_ALG_HANDLE *)(this + 0x60),L"MD5",(LPCWSTR)0x0,8);
    if (NVar1 < 0) {
      pcVar2 = 
      "BCryptOpenAlgorithmProvider(&m_checksumHandle, BCRYPT_MD5_ALGORITHM, nullptr, BCRYPT_ALG_HANDLE_HMAC_FLAG)"
      ;
    }
    else {
      NVar1 = BCryptOpenAlgorithmProvider((BCRYPT_ALG_HANDLE *)(this + 0x58),L"MD5",(LPCWSTR)0x0,0);
      if (-1 < NVar1) {
        *in_RDX = 0;
        return;
      }
      pcVar2 = "BCryptOpenAlgorithmProvider(&m_hashHandle, BCRYPT_MD5_ALGORITHM, nullptr, 0)";
    }
  }
  Logging::Verify::StatusFailed(pcVar2,NVar1);
  *in_RDX = NVar1;
  return;
}



===== InitializeCipherState @ 18000ec20 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::CipherStateReturn,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::CipherStateReturn,16>(struct Kerb3961::CipherStateReturn const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::CipherStateReturn,16>(struct Kerb3961::CipherStateReturn & __ptr64)> __cdecl
   Kerb3961::RC4_4757::InitializeCipherState(struct Kerb3961::ReturnType<struct
   Kerb3961::SpecificKeyReturn,&struct Kerb3961::ResultBlock const & __ptr64 __cdecl
   Kerb3961::SingleGetter<struct Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn
   const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::SpecificKeyReturn,16>(struct Kerb3961::SpecificKeyReturn & __ptr64)> & __ptr64,bool)
   __ptr64 */

ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
* __thiscall
Kerb3961::RC4_4757::InitializeCipherState
          (RC4_4757 *this,
          ReturnType<Kerb3961::SpecificKeyReturn,&struct_Kerb3961::ResultBlock_const&___ptr64___cdecl_Kerb3961::SingleGetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn_const&___ptr64),&struct_Kerb3961::ResultBlock&___ptr64___cdecl_Kerb3961::SingleSetter<struct_Kerb3961::SpecificKeyReturn,16>(struct_Kerb3961::SpecificKeyReturn&___ptr64)>
          *param_1,bool param_2)

{
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(RC4_4757 **)param_1 = this;
  return param_1;
}



===== MarshalCipherPolicy @ 18000ec40 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::RC4_4757::MarshalCipherPolicy(void) __ptr64 */

void __thiscall Kerb3961::RC4_4757::MarshalCipherPolicy(RC4_4757 *this)

{
  ulonglong uVar1;
  undefined8 *in_RDX;
  undefined8 local_28;
  undefined4 *local_20;
  long local_18;
  
  uVar1 = Feature_184236346__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar1 == 0) {
    *in_RDX = 0;
    in_RDX[1] = 0;
    *(undefined4 *)(in_RDX + 2) = 0;
  }
  else {
    MakeBuffer((__uint64)&local_28);
    if (local_18 < 0) {
      Logging::Verify::StatusFailed("marshaledPolicy",local_18);
      *in_RDX = 0;
      in_RDX[1] = 0;
      *(long *)(in_RDX + 2) = local_18;
      if (local_20 != (undefined4 *)0x0) {
        operator_delete__(local_20);
      }
    }
    else {
      *local_20 = *(undefined4 *)(this + 0x68);
      *(long *)(in_RDX + 2) = local_18;
      *in_RDX = local_28;
      in_RDX[1] = local_20;
    }
  }
  return;
}



===== PseudoRandom @ 18000ecf0 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::RC4_4757::PseudoRandom(struct Kerb3961::ReadOnlyBinary const & __ptr64,struct
   Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64 */

ReadOnlyBinary * __thiscall
Kerb3961::RC4_4757::PseudoRandom(RC4_4757 *this,ReadOnlyBinary *param_1,ReadOnlyBinary *param_2)

{
  __uint64 in_R9;
  
  GetHmac(param_1,(ReadOnlyBinary *)0x31,param_2,in_R9);
  return param_1;
}



===== RC4Data @ 18000ed1c =====

/* private: struct Kerb3961::ReturnType<struct Kerb3961::StatusOnly,&struct Kerb3961::ResultBlock
   const & __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::StatusOnly,0>(struct
   Kerb3961::StatusOnly const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl
   Kerb3961::SingleSetter<struct Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly & __ptr64)>
   __cdecl Kerb3961::RC4_4757::RC4Data(struct Kerb3961::ReadOnlyBinary const & __ptr64,struct
   Kerb3961::MutableBinary const & __ptr64) __ptr64 */

ReadOnlyBinary * __thiscall
Kerb3961::RC4_4757::RC4Data(RC4_4757 *this,ReadOnlyBinary *param_1,MutableBinary *param_2)

{
  NTSTATUS NVar1;
  char *pcVar2;
  ulonglong *in_R9;
  ULONG local_res20 [2];
  BCRYPT_KEY_HANDLE local_18 [2];
  
  if (0xffffffff < *in_R9) {
    Logging::Verify::ConditionFailed
              (
              "static_cast<size_t>(data.length) <= static_cast<size_t>(utl::numeric_limits<uint32_t>::max())"
              );
    *(undefined4 *)param_1 = 0xc0000095;
    return param_1;
  }
  local_18[0] = (BCRYPT_KEY_HANDLE)0x0;
  NVar1 = BCryptGenerateSymmetricKey
                    (*(BCRYPT_ALG_HANDLE *)(this + 0x50),local_18,(PUCHAR)0x0,0,
                     *(PUCHAR *)(param_2 + 8),*(ULONG *)param_2,0);
  if (NVar1 < 0) {
    pcVar2 = 
    "BCryptGenerateSymmetricKey(m_cipherHandle, &keyHandle, nullptr, 0, const_cast<uint8_t*>(key.buffer), static_cast<uint32_t>(key.length), 0)"
    ;
  }
  else {
    local_res20[0] = 0;
    NVar1 = BCryptEncrypt(local_18[0],(PUCHAR)in_R9[1],(ULONG)*in_R9,(void *)0x0,(PUCHAR)0x0,0,
                          (PUCHAR)in_R9[1],(ULONG)*in_R9,local_res20,0);
    if (-1 < NVar1) {
      *(undefined4 *)param_1 = 0;
      goto LAB_18000edfc;
    }
    pcVar2 = 
    "BCryptEncrypt(keyHandle.get(), data.buffer, static_cast<uint32_t>(data.length), nullptr, nullptr, 0, data.buffer, static_cast<uint32_t>(data.length), &returnLength, 0)"
    ;
  }
  Logging::Verify::StatusFailed(pcVar2,NVar1);
  *(NTSTATUS *)param_1 = NVar1;
LAB_18000edfc:
  if (local_18[0] != (BCRYPT_KEY_HANDLE)0x0) {
    BCryptDestroyKey(local_18[0]);
  }
  return param_1;
}



===== RandomKey @ 18000ee30 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::RC4_4757::RandomKey(void) __ptr64 */

void __thiscall Kerb3961::RC4_4757::RandomKey(RC4_4757 *this)

{
  __uint64 in_RDX;
  
  RandomBuffer(in_RDX);
  return;
}



===== RandomToKey @ 18000ee60 =====

/* private: virtual struct Kerb3961::ReturnType<struct Kerb3961::OwnedBinary,&struct
   Kerb3961::ResultBlock const & __ptr64 __cdecl Kerb3961::SingleGetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary const & __ptr64),&struct
   Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::OwnedBinary,16>(struct Kerb3961::OwnedBinary & __ptr64)> __cdecl
   Kerb3961::RC4_4757::RandomToKey(struct Kerb3961::ReadOnlyBinary const & __ptr64) __ptr64 */

ReadOnlyBinary * __thiscall Kerb3961::RC4_4757::RandomToKey(RC4_4757 *this,ReadOnlyBinary *param_1)

{
  ulonglong *in_R8;
  
  if (*in_R8 < 0x10) {
    Logging::Verify::ConditionFailed("randomSeed.length >= KEY_SIZE");
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0xc000000d;
  }
  else {
    CopyBuffer(param_1);
  }
  return param_1;
}



===== Uninitialize @ 18000eec0 =====

/* private: virtual void __cdecl Kerb3961::RC4_4757::Uninitialize(void) __ptr64 */

void __thiscall Kerb3961::RC4_4757::Uninitialize(RC4_4757 *this)

{
  if (*(BCRYPT_ALG_HANDLE *)(this + 0x50) != (BCRYPT_ALG_HANDLE)0x0) {
    BCryptCloseAlgorithmProvider(*(BCRYPT_ALG_HANDLE *)(this + 0x50),0);
    *(undefined8 *)(this + 0x50) = 0;
  }
  if (*(BCRYPT_ALG_HANDLE *)(this + 0x58) != (BCRYPT_ALG_HANDLE)0x0) {
    BCryptCloseAlgorithmProvider(*(BCRYPT_ALG_HANDLE *)(this + 0x58),0);
    *(undefined8 *)(this + 0x58) = 0;
  }
  if (*(BCRYPT_ALG_HANDLE *)(this + 0x60) != (BCRYPT_ALG_HANDLE)0x0) {
    BCryptCloseAlgorithmProvider(*(BCRYPT_ALG_HANDLE *)(this + 0x60),0);
    *(undefined8 *)(this + 0x60) = 0;
  }
  return;
}



===== Feature_Servicing_KerbRC4NewUsage__private_IsEnabledDeviceUsageNoInline @ 18000ef2c =====

ulonglong Feature_Servicing_KerbRC4NewUsage__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_Servicing_KerbRC4NewUsage__private_featureState;
  if ((Feature_Servicing_KerbRC4NewUsage__private_featureState & 0x10) == 0) {
    uVar1 = Feature_Servicing_KerbRC4NewUsage__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_Servicing_KerbRC4NewUsage__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_Servicing_KerbRC4NewUsage__private_IsEnabledFallback @ 18000ef64 =====

void Feature_Servicing_KerbRC4NewUsage__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_Servicing_KerbRC4NewUsage__private_descriptor);
  return;
}



===== InitializeCiphers @ 18000ef80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* struct Kerb3961::ReturnType<struct Kerb3961::StatusOnly,&struct Kerb3961::ResultBlock const &
   __ptr64 __cdecl Kerb3961::SingleGetter<struct Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly
   const & __ptr64),&struct Kerb3961::ResultBlock & __ptr64 __cdecl Kerb3961::SingleSetter<struct
   Kerb3961::StatusOnly,0>(struct Kerb3961::StatusOnly & __ptr64)> __cdecl
   Kerb3961::InitializeCiphers(void) */

void __cdecl Kerb3961::InitializeCiphers(void)

{
  longlong *plVar1;
  byte bVar2;
  uint uVar3;
  int *piVar4;
  _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *p_Var5;
  _TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_> *p_Var6;
  uint *in_RCX;
  longlong lVar7;
  undefined **ppuVar8;
  undefined1 local_res8 [8];
  longlong local_res10;
  
  wil::push_lock::acquire_exclusive((push_lock *)&g_cipherLock);
  bVar2 = 1;
  if (g_ciphersInitialized == 0) {
    for (p_Var5 = DAT_180018320;
        p_Var5 != (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                   *)&g_encryptions;
        p_Var5 = (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                  *)utl::
                    _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                    ::_Traverse(p_Var5,true)) {
      plVar1 = *(longlong **)(p_Var5 + 0x20);
      uVar3 = *(uint *)(p_Var5 + 0x18);
      piVar4 = (int *)(**(code **)(*plVar1 + 0x10))(plVar1,local_res8);
      if (*piVar4 < 0) {
        bVar2 = 0;
        (**(code **)(*plVar1 + 0x18))(plVar1);
        if (DAT_180018320 !=
            (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
             *)&g_encryptions) {
          ppuVar8 = &g_encryptions;
          p_Var6 = (_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_>
                    *)g_encryptions;
          do {
            if (*(uint *)(p_Var6 + 0x18) < uVar3) {
              lVar7 = 0x10;
            }
            else {
              lVar7 = 8;
              ppuVar8 = (undefined **)p_Var6;
            }
            p_Var6 = *(_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_>
                       **)(p_Var6 + lVar7);
          } while (p_Var6 != (_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_>
                              *)&utl::_TreeSentinel);
          if ((ppuVar8 != &g_encryptions) && (*(uint *)((longlong)ppuVar8 + 0x18) <= uVar3)) {
            utl::
            _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_>::
            _HeadUnlinkNode((_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_>
                             *)&g_encryptions,
                            (_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_>
                             *)ppuVar8);
            _DAT_180018328 = _DAT_180018328 + -1;
            operator_delete__(ppuVar8);
          }
        }
      }
    }
    for (p_Var5 = DAT_180018340;
        p_Var5 != (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                   *)&g_checksums;
        p_Var5 = (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                  *)utl::
                    _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                    ::_Traverse(p_Var5,true)) {
      plVar1 = *(longlong **)(p_Var5 + 0x20);
      uVar3 = *(uint *)(p_Var5 + 0x18);
      piVar4 = (int *)(**(code **)(*plVar1 + 0x10))(plVar1,local_res8);
      if (*piVar4 < 0) {
        bVar2 = 0;
        (**(code **)(*plVar1 + 0x18))(plVar1);
        if (DAT_180018340 !=
            (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
             *)&g_checksums) {
          ppuVar8 = &g_checksums;
          p_Var6 = (_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_>
                    *)g_checksums;
          do {
            if (*(uint *)(p_Var6 + 0x18) < uVar3) {
              lVar7 = 0x10;
            }
            else {
              lVar7 = 8;
              ppuVar8 = (undefined **)p_Var6;
            }
            p_Var6 = *(_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_>
                       **)(p_Var6 + lVar7);
          } while (p_Var6 != (_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_>
                              *)&utl::_TreeSentinel);
          if ((ppuVar8 != &g_checksums) && (*(uint *)((longlong)ppuVar8 + 0x18) <= uVar3)) {
            utl::
            _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_>::
            _HeadUnlinkNode((_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_>
                             *)&g_checksums,
                            (_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_>
                             *)ppuVar8);
            _DAT_180018348 = _DAT_180018348 + -1;
            operator_delete__(ppuVar8);
          }
        }
      }
    }
  }
  g_ciphersInitialized = g_ciphersInitialized + 1;
  *in_RCX = ~-(uint)bVar2 & 0xc0000001;
  if (local_res10 != 0) {
    ExReleasePushLockExclusiveEx(local_res10,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== UninitializeCiphers @ 18000f18c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl Kerb3961::UninitializeCiphers(void) */

void __cdecl Kerb3961::UninitializeCiphers(void)

{
  _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *p_Var1;
  longlong local_res8;
  
  wil::push_lock::acquire_exclusive((push_lock *)&g_cipherLock);
  if (g_ciphersInitialized == 0) {
                    /* WARNING: Subroutine does not return */
    ConsistencyFail((ushort *)L"Cannot uninitialize ciphers that are not initialized");
  }
  g_ciphersInitialized = g_ciphersInitialized - 1;
  if (g_ciphersInitialized == 0) {
    for (p_Var1 = DAT_180018320;
        p_Var1 != (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                   *)&g_encryptions;
        p_Var1 = (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                  *)utl::
                    _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                    ::_Traverse(p_Var1,true)) {
      (**(code **)(**(longlong **)(p_Var1 + 0x20) + 0x18))();
    }
    for (p_Var1 = DAT_180018340;
        p_Var1 != (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                   *)&g_checksums;
        p_Var1 = (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                  *)utl::
                    _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                    ::_Traverse(p_Var1,true)) {
      (**(code **)(**(longlong **)(p_Var1 + 0x20) + 0x18))();
    }
  }
  if (local_res8 != 0) {
    ExReleasePushLockExclusiveEx(local_res8,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== _HeadUnlinkNode @ 18000f260 =====

/* public: void __cdecl utl::_TreeNodeHeader<struct utl::pair<unsigned int const ,struct
   Kerb3961::ChecksumAlgorithm * __ptr64> >::_HeadUnlinkNode(struct utl::_TreeNode<struct
   utl::pair<unsigned int const ,struct Kerb3961::ChecksumAlgorithm * __ptr64> > * __ptr64) __ptr64
    */

void __thiscall
utl::_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_>::
_HeadUnlinkNode(_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_>
                *this,_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_>
                      *param_1)

{
  ulonglong *puVar1;
  undefined8 *puVar2;
  ulonglong *puVar3;
  ulonglong *puVar4;
  _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *p_Var5;
  longlong lVar6;
  _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *p_Var7;
  _TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *p_Var8;
  char cVar9;
  ulonglong uVar10;
  _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_> *p_Var11;
  _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *this_00;
  ulonglong uVar12;
  longlong lVar13;
  bool bVar14;
  bool bVar15;
  
  p_Var7 = *(_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
             **)(param_1 + 0x10);
  p_Var11 = (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_> *
            )((ulonglong)*(void **)param_1 & 0xfffffffffffffffe);
  bVar14 = p_Var7 != (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                      *)&_TreeSentinel;
  bVar15 = false;
  lVar13 = 8;
  cVar9 = (*(void ***)(param_1 + 8) != &_TreeSentinel) + bVar14;
  if (cVar9 == '\0') {
    if (this == p_Var11) {
      *(_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_> **)
       this = this;
      *(_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_> **)
       (this + 8) = this;
      *(_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_> **)
       (this + 0x10) = this;
      return;
    }
    if (*(_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_> **)
         (this + 8) == param_1) {
      p_Var8 = _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
               ::_Traverse((_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                            *)param_1,false);
      *(_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> **)
       (this + 8) = p_Var8;
    }
    else if (*(_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_> **)
              (this + 0x10) == param_1) {
      p_Var8 = _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
               ::_Traverse((_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                            *)param_1,true);
      *(_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> **)
       (this + 0x10) = p_Var8;
    }
    bVar15 = *(_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_> **)
              (p_Var11 + 0x10) == param_1;
    *(void ***)(p_Var11 + (ulonglong)bVar15 * 8 + 8) = &_TreeSentinel;
    if ((~(byte)*param_1 & 1) != 0) {
      return;
    }
    this_00 = (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
               *)p_Var11;
  }
  else {
    if (cVar9 == '\x01') {
      uVar10 = (ulonglong)bVar14;
      puVar2 = *(undefined8 **)(param_1 + uVar10 * 8 + 8);
      if (*(_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_> **)
           (this + uVar10 * 8 + 8) == param_1) {
        p_Var8 = _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                 ::_Traverse((_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                              *)param_1,bVar14);
        *(_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> **)
         (this + uVar10 * 8 + 8) = p_Var8;
      }
      if ((_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_> *)
          (*(ulonglong *)p_Var11 & 0xfffffffffffffffe) == param_1) {
        *(undefined8 **)p_Var11 = puVar2;
      }
      else {
        if (*(_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_> **)
             (p_Var11 + 0x10) == param_1) {
          lVar13 = 0x10;
        }
        *(undefined8 **)(p_Var11 + lVar13) = puVar2;
      }
      *puVar2 = *(undefined8 *)param_1;
      return;
    }
    p_Var5 = *(_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
               **)(p_Var7 + 8);
    if (*(_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> **
         )(p_Var7 + 8) ==
        (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *)
        &_TreeSentinel) {
      if ((((byte)*p_Var7 & 1) == 0) || (bVar15 = true, (**(byte **)(p_Var7 + 0x10) & 1) == 0)) {
        bVar15 = false;
      }
      *(void **)p_Var7 = *(void **)param_1;
      puVar1 = *(ulonglong **)(param_1 + 8);
      *(ulonglong **)(p_Var7 + 8) = puVar1;
      *puVar1 = (ulonglong)(uint)*puVar1 & 1 | (ulonglong)p_Var7;
      **(ulonglong **)(p_Var7 + 0x10) = (ulonglong)p_Var7 | 1;
      if ((_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_> *)
          (*(ulonglong *)p_Var11 & 0xfffffffffffffffe) == param_1) {
        *(_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> **
         )p_Var11 = p_Var7;
      }
      else {
        lVar6 = 8;
        if (*(_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_> **)
             (p_Var11 + 0x10) == param_1) {
          lVar6 = 0x10;
        }
        *(_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> **
         )(p_Var11 + lVar6) = p_Var7;
      }
      if (!bVar15) {
        return;
      }
      bVar15 = true;
      this_00 = p_Var7;
    }
    else {
      do {
        this_00 = p_Var7;
        p_Var7 = p_Var5;
        p_Var5 = *(_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                   **)(p_Var7 + 8);
      } while (*(_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                 **)(p_Var7 + 8) !=
               (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
                *)&_TreeSentinel);
      if ((((byte)*p_Var7 & 1) == 0) || (bVar14 = true, (**(byte **)(p_Var7 + 0x10) & 1) == 0)) {
        bVar14 = false;
      }
      puVar1 = *(ulonglong **)(p_Var7 + 0x10);
      *(ulonglong **)(this_00 + 8) = puVar1;
      *puVar1 = (ulonglong)this_00 | 1;
      *(void **)p_Var7 = *(void **)param_1;
      puVar1 = *(ulonglong **)(param_1 + 8);
      *(ulonglong **)(p_Var7 + 8) = puVar1;
      *puVar1 = (ulonglong)(uint)*puVar1 & 1 | (ulonglong)p_Var7;
      puVar1 = *(ulonglong **)(param_1 + 0x10);
      *(ulonglong **)(p_Var7 + 0x10) = puVar1;
      *puVar1 = (ulonglong)(uint)*puVar1 & 1 | (ulonglong)p_Var7;
      if ((_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_> *)
          (*(ulonglong *)p_Var11 & 0xfffffffffffffffe) == param_1) {
        *(_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> **
         )p_Var11 = p_Var7;
      }
      else {
        lVar6 = 8;
        if (*(_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_> **)
             (p_Var11 + 0x10) == param_1) {
          lVar6 = 0x10;
        }
        *(_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> **
         )(p_Var11 + lVar6) = p_Var7;
      }
      if (!bVar14) {
        return;
      }
    }
  }
  while( true ) {
    uVar10 = (ulonglong)bVar15;
    if ((~**(byte **)(this_00 + (uVar10 ^ 1) * 8 + 8) & 1) != 0) {
      _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>::
      _NodeRotate(this_00,bVar15,false,true);
    }
    puVar1 = *(ulonglong **)(this_00 + (uVar10 ^ 1) * 8 + 8);
    if ((~*(byte *)puVar1[(uVar10 ^ 1) + 1] & 1) != 0) break;
    if ((~*(byte *)puVar1[(ulonglong)bVar15 + 1] & 1) != 0) {
      uVar10 = *puVar1 & 0xfffffffffffffffe;
      uVar12 = (ulonglong)(bVar15 ^ 1);
      puVar3 = (ulonglong *)puVar1[(uVar12 ^ 1) + 1];
      puVar4 = (ulonglong *)puVar3[uVar12 + 1];
      *puVar3 = uVar10 | 1;
      if (*(ulonglong **)(uVar10 + 0x10) == puVar1) {
        lVar13 = 0x10;
      }
      *(ulonglong **)(lVar13 + uVar10) = puVar3;
      *puVar1 = (ulonglong)puVar3 | 1;
      *puVar4 = (ulonglong)(uint)*puVar4 & 1 | (ulonglong)puVar1;
      puVar1[(uVar12 ^ 1) + 1] = (ulonglong)puVar4;
      puVar3[uVar12 + 1] = (ulonglong)puVar1;
      goto LAB_18000f56e;
    }
    *puVar1 = *puVar1 & 0xfffffffffffffffe;
    uVar10 = *(ulonglong *)this_00;
    if ((~(byte)uVar10 & 1) != 0) {
      *(ulonglong *)this_00 = uVar10 | 1;
      return;
    }
    p_Var11 = (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_>
               *)(uVar10 & 0xfffffffffffffffe);
    if (this == p_Var11) {
      return;
    }
    bVar15 = *(_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
               **)(p_Var11 + 0x10) == this_00;
    this_00 = (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
               *)p_Var11;
  }
  *(ulonglong *)puVar1[((ulonglong)bVar15 ^ 1) + 1] =
       *(ulonglong *)puVar1[((ulonglong)bVar15 ^ 1) + 1] | 1;
LAB_18000f56e:
  _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>::
  _NodeRotate(this_00,bVar15,true,(bool)((byte)*this_00 & 1));
  return;
}



===== RegisterChecksum @ 18000f5b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong RegisterChecksum(longlong *param_1)

{
  int *piVar1;
  ulonglong uVar2;
  int *extraout_RAX;
  longlong *local_res8;
  undefined4 local_res10 [2];
  longlong local_res18;
  _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *local_18;
  char local_10;
  
  local_res8 = param_1;
                    /* 0xf5b0  12   */
  wil::push_lock::acquire_exclusive((push_lock *)&Kerb3961::g_cipherLock);
  local_res10[0] = (**(code **)(*param_1 + 0x68))(param_1);
  piVar1 = (int *)utl::
                  map<unsigned_int,Kerb3961::EncryptionAlgorithm*___ptr64,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>_>
                  ::try_emplace<Kerb3961::EncryptionAlgorithm*___ptr64&___ptr64,0>
                            ((map<unsigned_int,Kerb3961::EncryptionAlgorithm*___ptr64,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>_>
                              *)&Kerb3961::g_checksums,(uint *)&local_18,
                             (EncryptionAlgorithm **)local_res10);
  if ((local_18 ==
       (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *)
       0x0) || (local_10 == '\0')) {
LAB_18000f69a:
    if (local_res18 != 0) {
      ExReleasePushLockExclusiveEx(local_res18,0);
      piVar1 = (int *)KeLeaveCriticalRegion();
    }
    uVar2 = (ulonglong)piVar1 & 0xffffffffffffff00;
  }
  else {
    if (Kerb3961::g_ciphersInitialized != 0) {
      piVar1 = (int *)(**(code **)(*param_1 + 0x10))(param_1,&local_res8);
      if (*piVar1 < 0) {
        (**(code **)(*param_1 + 0x18))(param_1);
        utl::_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
        ::_Traverse(local_18,true);
        utl::_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_>::
        _HeadUnlinkNode((_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_>
                         *)&Kerb3961::g_checksums,
                        (_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_>
                         *)local_18);
        _DAT_180018348 = _DAT_180018348 + -1;
        operator_delete__(local_18);
        piVar1 = extraout_RAX;
        goto LAB_18000f69a;
      }
    }
    if (local_res18 != 0) {
      ExReleasePushLockExclusiveEx(local_res18,0);
      piVar1 = (int *)KeLeaveCriticalRegion();
    }
    uVar2 = CONCAT71((int7)((ulonglong)piVar1 >> 8),1);
  }
  return uVar2;
}



===== RegisterCipherSuite @ 18000f6e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong RegisterCipherSuite(EncryptionAlgorithm *param_1,longlong *param_2)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  int *piVar6;
  ulonglong extraout_RAX;
  ulonglong extraout_RAX_00;
  EncryptionAlgorithm *local_res8;
  longlong *local_res10;
  undefined4 local_res18 [2];
  longlong local_res20;
  _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *local_48;
  char local_40;
  _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *local_38;
  char local_30;
  
  local_res8 = param_1;
  local_res10 = param_2;
                    /* 0xf6e0  13   */
  wil::push_lock::acquire_exclusive((push_lock *)&Kerb3961::g_cipherLock);
  local_res18[0] = (**(code **)(*(longlong *)param_1 + 0xd8))(param_1);
  utl::
  map<unsigned_int,Kerb3961::EncryptionAlgorithm*___ptr64,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>_>
  ::try_emplace<Kerb3961::EncryptionAlgorithm*___ptr64&___ptr64,0>
            ((map<unsigned_int,Kerb3961::EncryptionAlgorithm*___ptr64,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>_>
              *)&Kerb3961::g_encryptions,(uint *)&local_48,(EncryptionAlgorithm **)local_res18);
  uVar4 = (**(code **)(*param_2 + 0x68))(param_2);
  local_res8 = (EncryptionAlgorithm *)CONCAT44(local_res8._4_4_,uVar4);
  uVar5 = utl::
          map<unsigned_int,Kerb3961::EncryptionAlgorithm*___ptr64,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>_>
          ::try_emplace<Kerb3961::EncryptionAlgorithm*___ptr64&___ptr64,0>
                    ((map<unsigned_int,Kerb3961::EncryptionAlgorithm*___ptr64,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>_>
                      *)&Kerb3961::g_checksums,(uint *)&local_38,&local_res8);
  if ((local_30 == '\0') || (local_40 == '\0')) {
    bVar2 = false;
LAB_18000f7c7:
    bVar3 = false;
LAB_18000f7ca:
    if (!bVar3) {
LAB_18000f7ce:
      uVar5 = CONCAT71((int7)(uVar5 >> 8),1);
      goto LAB_18000f7d0;
    }
  }
  else {
    bVar2 = true;
    if (Kerb3961::g_ciphersInitialized == 0) goto LAB_18000f7c7;
    piVar6 = (int *)(**(code **)(*(longlong *)param_1 + 0x10))(param_1,&local_res8);
    iVar1 = *piVar6;
    piVar6 = (int *)(**(code **)(*param_2 + 0x10))(param_2,&local_res8);
    bVar2 = true;
    bVar3 = true;
    uVar5 = 0;
    if (*piVar6 < 0) goto LAB_18000f7ca;
    if (-1 < iVar1) goto LAB_18000f7ce;
  }
  uVar5 = uVar5 & 0xffffffffffffff00;
LAB_18000f7d0:
  if ((bVar2) && ((char)uVar5 != '\0')) {
    if (local_res20 != 0) {
      ExReleasePushLockExclusiveEx(local_res20,0);
      uVar5 = KeLeaveCriticalRegion();
    }
    uVar5 = CONCAT71((int7)(uVar5 >> 8),1);
  }
  else {
    if (bVar3) {
      (**(code **)(*param_2 + 0x18))(param_2);
      uVar5 = (**(code **)(*(longlong *)param_1 + 0x18))(param_1);
    }
    if (local_40 != '\0') {
      utl::_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>::
      _Traverse(local_48,true);
      utl::_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_>::
      _HeadUnlinkNode((_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_>
                       *)&Kerb3961::g_encryptions,
                      (_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_>
                       *)local_48);
      _DAT_180018328 = _DAT_180018328 + -1;
      operator_delete__(local_48);
      uVar5 = extraout_RAX;
    }
    if (local_30 != '\0') {
      utl::_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>::
      _Traverse(local_38,true);
      utl::_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_>::
      _HeadUnlinkNode((_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_>
                       *)&Kerb3961::g_checksums,
                      (_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_>
                       *)local_38);
      _DAT_180018348 = _DAT_180018348 + -1;
      operator_delete__(local_38);
      uVar5 = extraout_RAX_00;
    }
    if (local_res20 != 0) {
      ExReleasePushLockExclusiveEx(local_res20,0);
      uVar5 = KeLeaveCriticalRegion();
    }
    uVar5 = uVar5 & 0xffffffffffffff00;
  }
  return uVar5;
}



===== RegisterEncryption @ 18000f8c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong RegisterEncryption(longlong *param_1)

{
  int *piVar1;
  ulonglong uVar2;
  int *extraout_RAX;
  longlong *local_res8;
  undefined4 local_res10 [2];
  longlong local_res18;
  _TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *local_18;
  char local_10;
  
  local_res8 = param_1;
                    /* 0xf8c0  11   */
  wil::push_lock::acquire_exclusive((push_lock *)&Kerb3961::g_cipherLock);
  local_res10[0] = (**(code **)(*param_1 + 0xd8))(param_1);
  piVar1 = (int *)utl::
                  map<unsigned_int,Kerb3961::EncryptionAlgorithm*___ptr64,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>_>
                  ::try_emplace<Kerb3961::EncryptionAlgorithm*___ptr64&___ptr64,0>
                            ((map<unsigned_int,Kerb3961::EncryptionAlgorithm*___ptr64,utl::less<unsigned_int>,utl::allocator<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>_>
                              *)&Kerb3961::g_encryptions,(uint *)&local_18,
                             (EncryptionAlgorithm **)local_res10);
  if ((local_18 ==
       (_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_> *)
       0x0) || (local_10 == '\0')) {
LAB_18000f9ad:
    if (local_res18 != 0) {
      ExReleasePushLockExclusiveEx(local_res18,0);
      piVar1 = (int *)KeLeaveCriticalRegion();
    }
    uVar2 = (ulonglong)piVar1 & 0xffffffffffffff00;
  }
  else {
    if (Kerb3961::g_ciphersInitialized != 0) {
      piVar1 = (int *)(**(code **)(*param_1 + 0x10))(param_1,&local_res8);
      if (*piVar1 < 0) {
        (**(code **)(*param_1 + 0x18))(param_1);
        utl::_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::EncryptionAlgorithm*___ptr64>_>
        ::_Traverse(local_18,true);
        utl::_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_>::
        _HeadUnlinkNode((_TreeNodeHeader<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_>
                         *)&Kerb3961::g_encryptions,
                        (_TreeNode<utl::pair<unsigned_int_const_,Kerb3961::ChecksumAlgorithm*___ptr64>_>
                         *)local_18);
        _DAT_180018328 = _DAT_180018328 + -1;
        operator_delete__(local_18);
        piVar1 = extraout_RAX;
        goto LAB_18000f9ad;
      }
    }
    if (local_res18 != 0) {
      ExReleasePushLockExclusiveEx(local_res18,0);
      piVar1 = (int *)KeLeaveCriticalRegion();
    }
    uVar2 = CONCAT71((int7)((ulonglong)piVar1 >> 8),1);
  }
  return uVar2;
}



===== ConditionFailed @ 18000f9e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl Kerb3961::Logging::Verify::ConditionFailed(char const * __ptr64) */

void __cdecl Kerb3961::Logging::Verify::ConditionFailed(char *param_1)

{
  longlong lVar1;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [4];
  char *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  if ((((Velocity::Feature_RC4Deprecation) && (2 < DAT_180018000)) && ((DAT_180018010 & 1) != 0)) &&
     (((uint)DAT_180018018 & 1) == DAT_180018018)) {
    if (param_1 == (char *)0x0) {
      param_1 = "";
      local_20 = 1;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (param_1[lVar1] != '\0');
      local_20 = (int)lVar1 + 1;
    }
    local_1c = 0;
    local_28 = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(0x180018000,&DAT_1800163c1,0,0,3,local_48);
  }
  return;
}



===== ConsistencyFail @ 18000fa9c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl Kerb3961::Logging::Verify::ConsistencyFail(unsigned short const * __ptr64) */

void __cdecl Kerb3961::Logging::Verify::ConsistencyFail(ushort *param_1)

{
  longlong lVar1;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [4];
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  if ((((Velocity::Feature_RC4Deprecation) && (1 < DAT_180018000)) && ((DAT_180018010 & 1) != 0)) &&
     (((uint)DAT_180018018 & 1) == DAT_180018018)) {
    if (param_1 == (ushort *)0x0) {
      local_20 = 2;
      param_1 = (ushort *)L"";
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (param_1[lVar1] != 0);
      local_20 = (int)lVar1 * 2 + 2;
    }
    local_1c = 0;
    local_28 = (wchar_t *)param_1;
    _tlgWriteTransfer_EtwWriteTransfer(0x180018000,&DAT_1800163eb,0,0,3,local_48);
  }
  return;
}



===== StatusFailed @ 18000fb5c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl Kerb3961::Logging::Verify::StatusFailed(char const * __ptr64,long) */

void __cdecl Kerb3961::Logging::Verify::StatusFailed(char *param_1,long param_2)

{
  longlong lVar1;
  undefined1 auStackY_98 [32];
  long local_68 [4];
  undefined8 local_58 [4];
  char *local_38;
  int local_30;
  undefined4 local_2c;
  long *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  if ((((Velocity::Feature_RC4Deprecation) && (2 < DAT_180018000)) && ((DAT_180018010 & 1) != 0)) &&
     (((uint)DAT_180018018 & 1) == DAT_180018018)) {
    local_20 = 4;
    local_28 = local_68;
    if (param_1 == (char *)0x0) {
      param_1 = "";
      local_30 = 1;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (param_1[lVar1] != '\0');
      local_30 = (int)lVar1 + 1;
    }
    local_2c = 0;
    local_68[0] = param_2;
    local_38 = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(0x180018000,&DAT_180016391,0,0,4,local_58);
  }
  return;
}



===== UsageEnabled @ 18000fc38 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl Kerb3961::Logging::Cipher::UsageEnabled(unsigned short const * __ptr64,bool,enum
   Kerb3961::KeyPolicyOperation,unsigned int) */

void __cdecl
Kerb3961::Logging::Cipher::UsageEnabled
          (ushort *param_1,bool param_2,KeyPolicyOperation param_3,uint param_4)

{
  longlong lVar1;
  undefined1 auStackY_b8 [32];
  undefined1 local_88 [4];
  uint local_84;
  uint local_80 [2];
  undefined8 local_78 [4];
  wchar_t *local_58;
  int local_50;
  undefined4 local_4c;
  uint *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  uint *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  if ((((Velocity::Feature_RC4Deprecation) && (4 < DAT_180018000)) && ((DAT_180018010 & 3) != 0)) &&
     (((uint)DAT_180018018 & 3) == DAT_180018018)) {
    local_80[0] = (uint)param_2;
    local_28 = &local_84;
    local_38 = local_88;
    local_48 = local_80;
    local_88[0] = (undefined1)param_3;
    local_20 = 4;
    local_30 = 1;
    local_40 = 4;
    if (param_1 == (ushort *)0x0) {
      local_50 = 2;
      param_1 = (ushort *)L"";
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (param_1[lVar1] != 0);
      local_50 = (int)lVar1 * 2 + 2;
    }
    local_4c = 0;
    local_84 = param_4;
    local_58 = (wchar_t *)param_1;
    _tlgWriteTransfer_EtwWriteTransfer(0x180018000,&DAT_180016415,0,0,6,local_78);
  }
  return;
}



===== _tlgDefineProvider_annotation__Tlgc_traceProviderProv @ 18000fd50 =====

void _tlgDefineProvider_annotation__Tlgc_traceProviderProv(void)

{
  return;
}



===== operator_new[] @ 18000fd5c =====

/* void * __ptr64 __cdecl operator new[](unsigned __int64,struct std::nothrow_t const & __ptr64) */

void * __cdecl operator_new__(__uint64 param_1,nothrow_t *param_2)

{
  __uint64 *p_Var1;
  __uint64 *p_Var2;
  
  if (param_1 + 0x10 < param_1) {
    p_Var1 = (__uint64 *)0x0;
  }
  else {
    p_Var2 = (__uint64 *)ExAllocatePoolWithTag(0x600,param_1 + 0x10,0x4362724b);
    p_Var1 = (__uint64 *)0x0;
    if (p_Var2 != (__uint64 *)0x0) {
      *p_Var2 = param_1;
      p_Var1 = p_Var2 + 2;
      *(undefined4 *)(p_Var2 + 1) = 0x200;
    }
  }
  return p_Var1;
}



===== operator_delete[] @ 18000fdb0 =====

/* void __cdecl operator delete[](void * __ptr64) */

void __cdecl operator_delete__(void *param_1)

{
  longlong lVar1;
  undefined1 *puVar2;
  
                    /* 0xfdb0  1   */
  if (param_1 != (void *)0x0) {
    puVar2 = param_1;
    for (lVar1 = *(longlong *)((longlong)param_1 + -0x10); lVar1 != 0; lVar1 = lVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    ExFreePoolWithTag((longlong *)((longlong)param_1 + -0x10),0x4362724b);
  }
  return;
}



===== DllInitialize @ 18000fdf0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* long __cdecl DllInitialize(struct _UNICODE_STRING * __ptr64) */

long __cdecl DllInitialize(_UNICODE_STRING *param_1)

{
  undefined2 uVar1;
  code *pcVar2;
  int iVar3;
  _func_void **pp_Var4;
  undefined1 *puVar5;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  ulonglong local_18;
  
                    /* 0xfdf0  2  DllInitialize */
  puVar5 = auStack_48;
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  for (pp_Var4 = &__xc_a; pp_Var4 != &__xc_z; pp_Var4 = pp_Var4 + 1) {
    if (*pp_Var4 != (_func_void *)0x0) {
      (**pp_Var4)();
    }
  }
  wil_InitializeFeatureStaging();
  if (Kerb3961::Velocity::Feature_RC4Deprecation != false) {
    local_28 = *(undefined4 *)(PTR_DAT_180018008 + -0x10);
    uStack_24 = *(undefined4 *)(PTR_DAT_180018008 + -0xc);
    uStack_20 = *(undefined4 *)(PTR_DAT_180018008 + -8);
    uStack_1c = *(undefined4 *)(PTR_DAT_180018008 + -4);
    puVar5 = auStack_48;
    if (DAT_180018020 != 0) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(5);
      puVar5 = auStack_40;
    }
    _DAT_180018028 = 0;
    uRam0000000180018030 = 0;
    *(undefined8 *)(puVar5 + -8) = 0x18000fe8b;
    iVar3 = EtwRegister(puVar5 + 0x20,_tlgEnableCallback,&DAT_180018000,&DAT_180018020);
    if (iVar3 == 0) {
      uVar1 = *(undefined2 *)PTR_DAT_180018008;
      *(undefined8 *)(puVar5 + -8) = 0x18000feb0;
      EtwSetInformation(DAT_180018020,2,PTR_DAT_180018008,uVar1);
    }
  }
  *(undefined8 *)(puVar5 + -8) = 0x18000fec4;
  return 0;
}



===== DllUnload @ 18000fee0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl DllUnload(void) */

long __cdecl DllUnload(void)

{
  undefined8 uVar1;
  ulonglong uVar2;
  
                    /* 0xfee0  3  DllUnload */
  uVar2 = 0;
  if (countAtexitFunctions != 0) {
    do {
      (*atexitFunctions[uVar2])();
      uVar2 = uVar2 + 1;
    } while (uVar2 < countAtexitFunctions);
  }
  operator_delete__(atexitFunctions);
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  uVar1 = DAT_180018020;
  g_wil_details_isFeatureStagingInitialized = 0;
  if (Kerb3961::Velocity::Feature_RC4Deprecation != false) {
    DAT_180018020 = 0;
    DAT_180018000 = 0;
    EtwUnregister(uVar1);
  }
  return 0;
}



===== Release @ 18000ff9c =====

/* public: static void __cdecl wil::details::kspin_lock_saved_irql::Release(struct
   wil::details::kspin_lock_saved_irql const & __ptr64) */

void __cdecl wil::details::kspin_lock_saved_irql::Release(kspin_lock_saved_irql *param_1)

{
  KeReleaseSpinLock(*(undefined8 *)param_1,param_1[8]);
  return;
}



===== DriverEntry @ 18000ffc0 =====

undefined8 DriverEntry(void)

{
  return 0xc0000002;
}



===== atexit @ 18000ffd0 =====

int __cdecl atexit(_func_5014 *param_1)

{
  undefined1 auVar1 [16];
  undefined8 uVar2;
  undefined1 uVar3;
  __uint64 _Size;
  _func_void **_Dst;
  nothrow_t *pnVar4;
  undefined *local_18;
  undefined1 uStack_10;
  undefined4 uStack_f;
  undefined2 uStack_b;
  undefined1 uStack_9;
  
  if ((DAT_180018630 & 1) == 0) {
    DAT_180018630 = DAT_180018630 | 1;
    KeInitializeSpinLock(&DAT_180018638);
  }
  uVar3 = KeAcquireSpinLockRaiseToDpc(&DAT_180018638);
  uVar2 = _uStack_10;
  _uStack_10 = CONCAT41(uStack_f,uVar3);
  uStack_b = SUB82(uVar2,5);
  uStack_9 = SUB81(uVar2,7);
  local_18 = &DAT_180018638;
  if (countAtexitFunctions == allocatedAtexitFunctions) {
    auVar1._8_8_ = 0;
    auVar1._0_8_ = allocatedAtexitFunctions + 0x10;
    pnVar4 = SUB168(ZEXT816(8) * auVar1,8);
    _Size = SUB168(ZEXT816(8) * auVar1,0);
    if (pnVar4 != (nothrow_t *)0x0) {
      _Size = 0xffffffffffffffff;
    }
    _Dst = operator_new__(_Size,pnVar4);
    if (_Dst == (_func_void **)0x0) {
      wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_18);
      return -1;
    }
    memset(_Dst,0,_Size);
    memmove(_Dst,atexitFunctions,allocatedAtexitFunctions << 3);
    operator_delete__(atexitFunctions);
    allocatedAtexitFunctions = allocatedAtexitFunctions + 0x10;
    atexitFunctions = _Dst;
  }
  atexitFunctions[countAtexitFunctions] = (_func_void *)param_1;
  countAtexitFunctions = countAtexitFunctions + 1;
  wil::details::kspin_lock_saved_irql::Release((kspin_lock_saved_irql *)&local_18);
  return 0;
}



===== wil_details_RecordCachedUsage @ 18001012c =====

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



===== wil_details_RecordFeatureUsageReporting @ 180010280 =====

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



===== __GSHandlerCheck @ 180010308 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 18001032c =====

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



===== __cpu_features_init @ 1800103a0 =====

/* WARNING: Removing unreachable block (ram,0x00018001040a) */
/* WARNING: Removing unreachable block (ram,0x0001800103b9) */
/* WARNING: Removing unreachable block (ram,0x0001800103aa) */

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



===== __security_check_cookie @ 180010470 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1800104b0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1800104e0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001800104e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 180010510 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 180010580 =====

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



===== memset @ 180010880 =====

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



===== __memset_repmovs @ 1800109c0 =====

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



===== __memset_query @ 180010a40 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 180010ac0 =====

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
        if (param_3 != &DAT_00000001) {
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



===== __memset_spec_ermsb_repmovsb @ 180010c00 =====

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



===== __memset_spec_plain @ 180010c80 =====

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
        if (param_3 != &DAT_00000001) {
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



===== `dynamic_atexit_destructor_for_'g_keyUsageMap'' @ 180010d80 =====

void Kerb3961::_dynamic_atexit_destructor_for__g_keyUsageMap__(void)

{
  utl::
  _Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
  ::
  ~_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
            ((_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
              *)&g_keyUsageMap);
  return;
}



===== `dynamic_atexit_destructor_for_'g_domainCipherPolicy'' @ 180010da0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Kerb3961::_dynamic_atexit_destructor_for__g_domainCipherPolicy__(void)

{
  if (DAT_180018620 != 0) {
    (**(code **)(*DAT_180018618 + 0x38))(DAT_180018618,&DAT_180018618);
  }
  utl::
  _Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
  ::
  ~_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
            ((_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
              *)&DAT_1800185e8);
  utl::
  _Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
  ::
  ~_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
            ((_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
              *)&DAT_1800185c8);
  utl::
  _Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
  ::
  ~_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
            ((_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
              *)&DAT_1800185a8);
  utl::
  _Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
  ::
  ~_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
            ((_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
              *)&DAT_180018588);
  return;
}



===== `dynamic_atexit_destructor_for_'g_localCipherPolicy'' @ 180010e10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Kerb3961::_dynamic_atexit_destructor_for__g_localCipherPolicy__(void)

{
  if (DAT_180018560 != 0) {
    (**(code **)(*DAT_180018558 + 0x38))(DAT_180018558,&DAT_180018558);
  }
  utl::
  _Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
  ::
  ~_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
            ((_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
              *)&DAT_180018528);
  utl::
  _Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
  ::
  ~_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
            ((_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
              *)&DAT_180018508);
  utl::
  _Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
  ::
  ~_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
            ((_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
              *)&DAT_1800184e8);
  utl::
  _Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
  ::
  ~_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
            ((_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
              *)&DAT_1800184c8);
  return;
}



===== `dynamic_atexit_destructor_for_'g_checksums'' @ 180010e80 =====

void Kerb3961::_dynamic_atexit_destructor_for__g_checksums__(void)

{
  utl::
  _Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
  ::
  ~_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
            ((_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
              *)&g_checksums);
  return;
}



===== `dynamic_atexit_destructor_for_'g_encryptions'' @ 180010ea0 =====

void Kerb3961::_dynamic_atexit_destructor_for__g_encryptions__(void)

{
  utl::
  _Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
  ::
  ~_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
            ((_Tree<Kerb3961::KeyUsage_const_,utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>,utl::less<Kerb3961::KeyUsage_const_>,utl::allocator<utl::pair<Kerb3961::KeyUsage_const_,Kerb3961::KeyPolicyScenario_const_>_>,0>
              *)&g_encryptions);
  return;
}



===== _tlgEnableCallback @ 18001b010 =====

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



===== wil_details_EvaluateFeatureDependencies @ 18001b08c =====

void wil_details_EvaluateFeatureDependencies(void)

{
  uint uVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  bool bVar5;
  
  puVar4 = (undefined *)0x0;
  ppuVar3 = &Feature_184236346__private_descriptor;
  ppuVar2 = &Feature_184236346__private_descriptor;
  do {
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x00018001b0c7;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_18001b141:
  while( true ) {
    if (&UNK_1800175a7 < ppuVar3) {
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
      if (&UNK_1800175a7 < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x00018001b0c7:
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
      if (&UNK_1800175a7 < ppuVar2) goto LAB_18001b141;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_18001b141;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 18001b17c =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_18001b218;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_18001b218;
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
LAB_18001b218:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 18001b280 =====

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
      for (ppuVar2 = &Feature_184236346__private_descriptor;
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
              if (&UNK_1800175a7 < ppuVar2) {
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



===== wil_details_RecordFeatureUsageCallback @ 18001b300 =====

void wil_details_RecordFeatureUsageCallback(void)

{
  RtlRecordFeatureUsage();
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 18001b320 =====

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
  for (ppuVar3 = &Feature_184236346__private_descriptor; ppuVar3 < &wil_details_featureDescriptors_z
      ; ppuVar3 = ppuVar3 + 1) {
    if (*ppuVar3 != (undefined *)0x0) goto LAB_18001b41d;
  }
LAB_18001b426:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_18001b41d:
  if (ppuVar3 == (undefined **)0x0) goto LAB_18001b426;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_18001b3ee:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_18001b3ee;
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
    if (&UNK_1800175a7 < ppuVar3) goto LAB_18001b426;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_18001b41d;
}



===== entry @ 18001d010 =====

void entry(void)

{
  __security_init_cookie();
  DriverEntry();
  return;
}



===== __security_init_cookie @ 18001d044 =====

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



===== wil_InitializeFeatureStaging @ 18001d078 =====

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
    for (ppuVar3 = &Feature_184236346__private_descriptor;
        ppuVar3 < &wil_details_featureDescriptors_z; ppuVar3 = ppuVar3 + 1) {
      if (*ppuVar3 != (undefined *)0x0) goto LAB_18001d0ff;
    }
LAB_18001d139:
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
LAB_18001d0ff:
  if (ppuVar3 == (undefined **)0x0) goto LAB_18001d139;
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
    goto LAB_18001d139;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_1800175a7 < ppuVar3) goto LAB_18001d139;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_18001d0ff;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 18001d18c =====

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
  ppuVar4 = &Feature_184236346__private_descriptor;
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
            if (&UNK_1800175a7 < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_18001d276;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_18001d276;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_18001d276:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_1800175a7 < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


