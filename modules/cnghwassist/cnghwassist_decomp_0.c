
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



===== __C_specific_handler @ 1c000101d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001c000101d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== WppClassicProviderCallback @ 1c0001030 =====

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



===== AddHardwareKey @ 1c0001064 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AddHardwareKey(longlong param_1,char param_2)

{
  int iVar1;
  void *pvVar2;
  undefined8 uVar3;
  undefined8 local_res18 [2];
  
  local_res18[0] = 0;
  if ((((g_fHwProvAvailable != '\0') && (*(longlong *)(param_1 + 0x18) == 0)) &&
      (*(char *)(param_1 + 0xc) == '\0')) && (*(char *)(param_1 + 0x6c) == '\0')) {
    pvVar2 = ProvAlloc((ulonglong)g_cbHardwareKeyObjectSize);
    if (pvVar2 != (void *)0x0) {
      if (*(uint *)(param_1 + 8) < 3) {
        uVar3 = *(undefined8 *)(&g_hAlgHardware + (ulonglong)*(uint *)(param_1 + 8) * 8);
      }
      else {
        uVar3 = 0;
      }
      iVar1 = (**(code **)(g_pHwCipherFunctionTable + 0x28))
                        (uVar3,local_res18,pvVar2,g_cbHardwareKeyObjectSize,param_1 + 0x38,
                         *(undefined4 *)(param_1 + 0x58),0);
      if (iVar1 < 0) {
        if (param_2 == '\0') {
          *(undefined1 *)(param_1 + 0x6c) = 1;
        }
        else {
          SwitchKeyToSoftwareOnly(param_1);
        }
        ExFreePoolWithTag(pvVar2,0x48676e43);
      }
      else {
        *(undefined8 *)(param_1 + 0x18) = local_res18[0];
        *(void **)(param_1 + 0x20) = pvVar2;
      }
    }
  }
  return;
}



===== ConvertToInternalChainingMode @ 1c0001160 =====

byte ConvertToInternalChainingMode(wchar_t *param_1,ulonglong param_2)

{
  byte bVar1;
  int iVar2;
  
  if (param_2 < 0x20) {
    bVar1 = 0;
  }
  else {
    iVar2 = wcscmp(param_1,L"ChainingModeCBC");
    if (iVar2 == 0) {
      bVar1 = 1;
    }
    else {
      iVar2 = wcscmp(param_1,L"ChainingModeECB");
      bVar1 = ~-(iVar2 != 0) & 2;
    }
  }
  return bVar1;
}



===== DestroyKeyObject @ 1c00011b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DestroyKeyObject(undefined1 *param_1)

{
  longlong lVar1;
  
  if (*(longlong *)(param_1 + 0x18) != 0) {
    (**(code **)(g_pHwCipherFunctionTable + 0x58))();
    *(undefined8 *)(param_1 + 0x18) = 0;
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x20),0x48676e43);
    *(undefined8 *)(param_1 + 0x20) = 0;
  }
  if (*(BCRYPT_KEY_HANDLE *)(param_1 + 0x10) != (BCRYPT_KEY_HANDLE)0x0) {
    BCryptDestroyKey(*(BCRYPT_KEY_HANDLE *)(param_1 + 0x10));
    *(undefined8 *)(param_1 + 0x10) = 0;
  }
  for (lVar1 = 0x70; lVar1 != 0; lVar1 = lVar1 + -1) {
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
  return;
}



===== GetHandleFromPointer @ 1c0001220 =====

ulonglong GetHandleFromPointer(ulonglong param_1)

{
  return param_1 ^ 0x4000000000000000;
}



===== GetPointerFromAlgHandle @ 1c0001238 =====

int * GetPointerFromAlgHandle(ulonglong param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(param_1 ^ 0x4000000000000000);
  if (*piVar1 != 0x6c416148) {
    piVar1 = (int *)0x0;
  }
  return piVar1;
}



===== ProvAlloc @ 1c000125c =====

void * ProvAlloc(size_t param_1)

{
  void *_Dst;
  
  _Dst = (void *)ExAllocatePool2(0x40,param_1,0x48676e43);
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,param_1);
  }
  return _Dst;
}



===== ProvCrypt @ 1c00012b0 =====

NTSTATUS ProvCrypt(longlong param_1,PUCHAR param_2,uint param_3,longlong param_4,PUCHAR param_5,
                  ULONG param_6,PUCHAR param_7,uint param_8,int *param_9,uint param_10)

{
  NTSTATUS NVar1;
  int iVar2;
  ULONG local_res18 [2];
  
  local_res18[0] = 0;
  if ((param_4 == 0) &&
     ((param_5 == (PUCHAR)0x0 || ((param_6 == 0x10 && (*(int *)(param_1 + 8) != 2)))))) {
    iVar2 = 0;
    for (; 0x100000 < param_3; param_3 = param_3 - 0x100000) {
      if (param_8 < 0x100000) {
                    /* WARNING: Subroutine does not return */
        KeBugCheck(0x6c746166);
      }
      NVar1 = ProvCryptChunk(param_1,param_2,0x100000,(void *)0x0,param_5,param_6,param_7,0x100000,
                             local_res18,param_10 & 0xfffffffe);
      if (NVar1 < 0) {
        return NVar1;
      }
      iVar2 = iVar2 + 0x100000;
      param_2 = param_2 + 0x100000;
      param_7 = param_7 + 0x100000;
      param_8 = param_8 - 0x100000;
    }
    NVar1 = ProvCryptChunk(param_1,param_2,param_3,(void *)0x0,param_5,param_6,param_7,param_8,
                           local_res18,param_10);
    if (-1 < NVar1) {
      *param_9 = local_res18[0] + iVar2;
    }
  }
  else {
    NVar1 = -0x3ffffff3;
  }
  return NVar1;
}



===== ProvCryptChunk @ 1c000141c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS ProvCryptChunk(longlong param_1,PUCHAR param_2,uint param_3,void *param_4,PUCHAR param_5,
                       ULONG param_6,PUCHAR param_7,ULONG param_8,ULONG *param_9,uint param_10)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  byte bVar4;
  char cVar5;
  uint dwFlags;
  uint uVar6;
  NTSTATUS NVar7;
  uint uVar8;
  uint uVar9;
  undefined8 uVar10;
  int *piVar11;
  undefined8 uVar12;
  PUCHAR pUVar13;
  longlong lVar14;
  longlong lVar15;
  undefined1 auStackY_1d8 [32];
  longlong local_158;
  longlong local_150;
  int *local_f8;
  longlong local_f0;
  undefined1 local_e8;
  PUCHAR local_e0;
  uint local_d8;
  undefined8 *local_d0;
  undefined4 local_c8;
  PUCHAR local_c0;
  ULONG local_b8;
  ULONG *local_b0;
  ULONG local_a8;
  uint local_a4;
  NTSTATUS local_a0;
  undefined4 local_9c;
  void *local_98;
  undefined1 local_90 [48];
  int local_60;
  int local_5c;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1d8;
  memset(&local_f0,0,0x98);
  lVar14 = 0;
  local_158 = 0;
  lVar15 = 0;
  local_150 = 0;
  bVar3 = false;
  bVar2 = false;
  pUVar13 = *(PUCHAR *)MmSystemRangeStart_exref;
  uVar8 = param_10 & 0x8000;
  dwFlags = param_10 & 0xffff7fff;
  *(undefined1 *)(param_1 + 0xd) = 1;
  piVar11 = &g_config;
  if (g_nBytesInQueues <= (uint)(&DAT_1c000780c)[(ulonglong)g_currentConfig * 0x10]) {
    piVar11 = &g_config + (ulonglong)g_currentConfig * 0x10;
  }
  local_f8 = piVar11;
  bVar4 = KeGetCurrentIrql();
  if ((((uint)piVar11[10] <= param_3) && (bVar4 < 2)) &&
     ((((byte)param_3 | (byte)param_7 | (byte)param_2) & 0x3f) == 0)) {
    if (param_2 != param_7) {
      uVar9 = (int)param_2 - (int)param_7;
      uVar6 = -uVar9;
      if ((int)uVar6 < 0) {
        uVar6 = uVar9;
      }
      if (uVar6 < param_3) goto LAB_1c00019b1;
    }
    if ((((param_10 & 1) == 0) && (pUVar13 <= param_2)) &&
       ((pUVar13 <= param_2 + ((ulonglong)param_3 - 1) &&
        ((pUVar13 <= param_7 && (pUVar13 <= param_7 + ((ulonglong)param_3 - 1))))))) {
      if (*(longlong *)(param_1 + 0x18) == 0) {
        if ((g_fHwProvAvailable & *(char *)(param_1 + 0x6c) == '\0') == 0) goto LAB_1c00019b1;
        ExAcquireFastMutex(&g_mutexAddHardwareKey);
        AddHardwareKey(param_1,'\0');
        ExReleaseFastMutex(&g_mutexAddHardwareKey);
        if (*(longlong *)(param_1 + 0x18) == 0) goto LAB_1c00019b1;
      }
      local_9c = 0;
      if ((param_3 < (uint)piVar11[2]) || (*piVar11 == 0)) {
        local_9c = 1;
      }
      else if ((param_10 & 0x40) == 0) {
        local_150 = IoAllocateMdl(param_7,param_3,0,0);
        lVar15 = local_150;
        if (local_150 == 0) goto LAB_1c00019b1;
        MmProbeAndLockPages(local_150);
        bVar3 = true;
        if (param_2 != param_7) {
          local_158 = IoAllocateMdl(param_2,param_3,0,0);
          lVar14 = local_158;
          if (local_158 == 0) goto LAB_1c00019b1;
          MmProbeAndLockPages(local_158,0);
          bVar2 = true;
        }
      }
      local_f0 = param_1;
      local_e8 = uVar8 != 0;
      local_e0 = param_2;
      local_d8 = param_3;
      if (param_5 == (PUCHAR)0x0) {
        local_d0 = *(undefined8 **)(param_1 + 0x60);
        local_c8 = *(undefined4 *)(param_1 + 0x68);
      }
      else {
        memcpy(&local_58,param_5,(ulonglong)param_6);
        local_d0 = &local_58;
        local_c8 = 0x10;
      }
      local_c0 = param_7;
      local_b8 = param_8;
      local_b0 = param_9;
      local_a8 = 0;
      local_a0 = 0;
      local_60 = 4;
      local_98 = SystemReserved1[0xf];
      uVar12 = 0;
      uVar10 = 0;
      local_a4 = dwFlags;
      KeInitializeEvent(local_90);
      LOCK();
      iVar1 = g_ulUnique + 1;
      UNLOCK();
      local_5c = g_ulUnique + 1;
      g_ulUnique = iVar1;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        uVar10 = 0xd;
        WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,uVar12,local_5c,(char)local_d8);
      }
      cVar5 = ScheduleRequestNew((longlong *)&local_f8,uVar10,uVar12);
      do {
        if (cVar5 != '\0') {
          WaitForRequestEvent((longlong)&local_f8);
        }
        do {
          if (local_60 == 3) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
              WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,uVar12,local_5c,
                        (char)local_d8);
            }
            if (param_5 != (PUCHAR)0x0) {
              *(undefined8 *)(param_1 + 0x28) = local_58;
              *(undefined8 *)(param_1 + 0x30) = uStack_50;
              *(undefined8 *)param_5 = local_58;
              *(undefined8 *)(param_5 + 8) = uStack_50;
            }
            *local_b0 = local_a8;
            NVar7 = local_a0;
            goto LAB_1c0001a38;
          }
        } while (local_60 != 1);
        SoftwareCryptPiece((longlong *)&local_f8);
        cVar5 = ScheduleRequestAfterSoftwarePiece((longlong *)&local_f8);
      } while( true );
    }
  }
LAB_1c00019b1:
  local_150 = lVar15;
  local_158 = lVar14;
  if (param_5 == (PUCHAR)0x0) {
    pUVar13 = *(PUCHAR *)(param_1 + 0x60);
    param_6 = *(ULONG *)(param_1 + 0x68);
  }
  else {
    pUVar13 = param_5;
  }
  if (uVar8 == 0) {
    NVar7 = BCryptEncrypt(*(BCRYPT_KEY_HANDLE *)(param_1 + 0x10),param_2,param_3,param_4,pUVar13,
                          param_6,param_7,param_8,param_9,dwFlags);
  }
  else {
    NVar7 = BCryptDecrypt(*(BCRYPT_KEY_HANDLE *)(param_1 + 0x10),param_2,param_3,param_4,pUVar13,
                          param_6,param_7,param_8,param_9,dwFlags);
  }
  if (param_5 != (PUCHAR)0x0) {
    uVar10 = *(undefined8 *)(param_5 + 8);
    *(undefined8 *)(param_1 + 0x28) = *(undefined8 *)param_5;
    *(undefined8 *)(param_1 + 0x30) = uVar10;
  }
LAB_1c0001a38:
  if (local_158 != 0) {
    if (bVar2) {
      MmUnlockPages(local_158);
    }
    IoFreeMdl(local_158);
  }
  if (local_150 != 0) {
    if (bVar3) {
      MmUnlockPages(local_150);
    }
    IoFreeMdl(local_150);
  }
  return NVar7;
}



===== ProvDecrypt @ 1c0001ac0 =====

NTSTATUS ProvDecrypt(ulonglong param_1,PUCHAR param_2,uint param_3,void *param_4,PUCHAR param_5,
                    ULONG param_6,PUCHAR param_7,uint param_8,ULONG *param_9,uint param_10)

{
  uint uVar1;
  NTSTATUS NVar2;
  int *piVar3;
  
  piVar3 = (int *)0x0;
  if (*(int *)(param_1 ^ 0x4000000000000000) == 0x794b6148) {
    piVar3 = (int *)(param_1 ^ 0x4000000000000000);
  }
  if (piVar3 == (int *)0x0) {
    NVar2 = -0x3ffffff8;
  }
  else if (((char)piVar3[3] == '\0') && (param_7 != (PUCHAR)0x0)) {
    if ((param_10 & 0xffffffbe) == 0) {
      if ((param_3 & 0xf) == 0) {
        uVar1 = param_3;
        if ((param_10 & 1) != 0) {
          if (param_3 == 0) {
            return 0;
          }
          uVar1 = param_3 - 0x10;
        }
        if (param_8 < uVar1) {
          NVar2 = -0x3fffffdd;
        }
        else {
          NVar2 = ProvCrypt((longlong)piVar3,param_2,param_3,(longlong)param_4,param_5,param_6,
                            param_7,param_8,(int *)param_9,param_10 | 0x8000);
        }
      }
      else {
        NVar2 = -0x3ffffdfa;
      }
    }
    else {
      NVar2 = -0x3ffffff3;
    }
  }
  else {
    NVar2 = BCryptDecrypt(*(BCRYPT_KEY_HANDLE *)(piVar3 + 4),param_2,param_3,param_4,param_5,param_6
                          ,param_7,param_8,param_9,param_10);
  }
  return NVar2;
}



===== ProvDestroyKey @ 1c0001c20 =====

undefined8 ProvDestroyKey(ulonglong param_1)

{
  int *piVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  piVar1 = (int *)0x0;
  if (*(int *)(param_1 ^ 0x4000000000000000) == 0x794b6148) {
    piVar1 = (int *)(param_1 ^ 0x4000000000000000);
  }
  if (piVar1 == (int *)0x0) {
    uVar2 = 0xc0000008;
  }
  else {
    DestroyKeyObject((undefined1 *)piVar1);
  }
  return uVar2;
}



===== ProvDuplicateKey @ 1c0001c70 =====

NTSTATUS ProvDuplicateKey(ulonglong param_1,ulonglong *param_2,undefined8 *param_3,uint param_4,
                         int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  NTSTATUS NVar5;
  longlong lVar6;
  int *piVar7;
  
  piVar7 = (int *)0x0;
  if (*(int *)(param_1 ^ 0x4000000000000000) == 0x794b6148) {
    piVar7 = (int *)(param_1 ^ 0x4000000000000000);
  }
  if (piVar7 == (int *)0x0) {
    NVar5 = -0x3ffffff8;
  }
  else if ((param_5 == 0) && (param_3 != (undefined8 *)0x0)) {
    if (param_4 < g_cbMyKeyObjectSize) {
      NVar5 = -0x3fffffdd;
    }
    else {
      uVar4 = *(undefined8 *)(piVar7 + 2);
      *param_3 = *(undefined8 *)piVar7;
      param_3[1] = uVar4;
      uVar4 = *(undefined8 *)(piVar7 + 6);
      param_3[2] = *(undefined8 *)(piVar7 + 4);
      param_3[3] = uVar4;
      uVar4 = *(undefined8 *)(piVar7 + 10);
      param_3[4] = *(undefined8 *)(piVar7 + 8);
      param_3[5] = uVar4;
      uVar4 = *(undefined8 *)(piVar7 + 0xe);
      param_3[6] = *(undefined8 *)(piVar7 + 0xc);
      param_3[7] = uVar4;
      uVar4 = *(undefined8 *)(piVar7 + 0x12);
      param_3[8] = *(undefined8 *)(piVar7 + 0x10);
      param_3[9] = uVar4;
      iVar1 = piVar7[0x15];
      iVar2 = piVar7[0x16];
      iVar3 = piVar7[0x17];
      *(int *)(param_3 + 10) = piVar7[0x14];
      *(int *)((longlong)param_3 + 0x54) = iVar1;
      *(int *)(param_3 + 0xb) = iVar2;
      *(int *)((longlong)param_3 + 0x5c) = iVar3;
      iVar1 = piVar7[0x19];
      iVar2 = piVar7[0x1a];
      iVar3 = piVar7[0x1b];
      *(int *)(param_3 + 0xc) = piVar7[0x18];
      *(int *)((longlong)param_3 + 100) = iVar1;
      *(int *)(param_3 + 0xd) = iVar2;
      *(int *)((longlong)param_3 + 0x6c) = iVar3;
      param_3[2] = (BCRYPT_KEY_HANDLE)0x0;
      param_3[3] = 0;
      param_3[4] = 0;
      iVar1 = piVar7[2];
      *(int *)(param_3 + 1) = iVar1;
      if (iVar1 == 1) {
        *(undefined4 *)(param_3 + 0xd) = 0x10;
        param_3[0xc] = param_3 + 5;
      }
      else if (iVar1 == 2) {
        param_3[0xc] = 0;
        *(undefined4 *)(param_3 + 0xd) = 0;
      }
      NVar5 = BCryptDuplicateKey(*(BCRYPT_KEY_HANDLE *)(piVar7 + 4),
                                 (BCRYPT_KEY_HANDLE *)(param_3 + 2),(PUCHAR)(param_3 + 0xe),
                                 g_cbSoftwareKeyObjectSize,0);
      if (NVar5 < 0) {
        for (lVar6 = 0x70; lVar6 != 0; lVar6 = lVar6 + -1) {
          *(undefined1 *)param_3 = 0;
          param_3 = (undefined8 *)((longlong)param_3 + 1);
        }
      }
      else {
        if (*(char *)((longlong)param_3 + 0xc) == '\0') {
          AddHardwareKey((longlong)param_3,'\x01');
        }
        *param_2 = (ulonglong)param_3 ^ 0x4000000000000000;
        NVar5 = 0;
      }
    }
  }
  else {
    NVar5 = -0x3ffffff3;
  }
  return NVar5;
}



===== ProvEncrypt @ 1c0001dc0 =====

NTSTATUS ProvEncrypt(ulonglong param_1,PUCHAR param_2,uint param_3,void *param_4,PUCHAR param_5,
                    ULONG param_6,PUCHAR param_7,uint param_8,ULONG *param_9,uint param_10)

{
  NTSTATUS NVar1;
  int *piVar2;
  
  piVar2 = (int *)0x0;
  if (*(int *)(param_1 ^ 0x4000000000000000) == 0x794b6148) {
    piVar2 = (int *)(param_1 ^ 0x4000000000000000);
  }
  if (piVar2 == (int *)0x0) {
    return -0x3ffffff8;
  }
  if (((char)piVar2[3] != '\0') || (param_7 == (PUCHAR)0x0)) {
    NVar1 = BCryptEncrypt(*(BCRYPT_KEY_HANDLE *)(piVar2 + 4),param_2,param_3,param_4,param_5,param_6
                          ,param_7,param_8,param_9,param_10);
    return NVar1;
  }
  if ((param_10 & 0xffffffbe) != 0) {
    return -0x3ffffff3;
  }
  if ((param_10 & 1) == 0) {
    if ((param_3 & 0xf) != 0) {
      return -0x3ffffdfa;
    }
    if (param_3 <= param_8) {
LAB_1c0001e75:
      NVar1 = ProvCrypt((longlong)piVar2,param_2,param_3,(longlong)param_4,param_5,param_6,param_7,
                        param_8,(int *)param_9,param_10);
      return NVar1;
    }
  }
  else if ((0xf < param_8) && ((param_3 & 0xfffffff0) <= param_8 - 0x10)) goto LAB_1c0001e75;
  return -0x3fffffdd;
}



===== ProvExportKey @ 1c0001f20 =====

NTSTATUS ProvExportKey(ulonglong param_1,ulonglong param_2,LPCWSTR param_3,PUCHAR param_4,
                      ULONG param_5,ULONG *param_6,ULONG param_7)

{
  NTSTATUS NVar1;
  int *piVar2;
  BCRYPT_KEY_HANDLE hExportKey;
  int *piVar3;
  
  hExportKey = (BCRYPT_KEY_HANDLE)0x0;
  piVar2 = (int *)0x0;
  piVar3 = (int *)0x0;
  if (*(int *)(param_1 ^ 0x4000000000000000) == 0x794b6148) {
    piVar3 = (int *)(param_1 ^ 0x4000000000000000);
  }
  if (param_2 != 0) {
    if (*(int *)(param_2 ^ 0x4000000000000000) == 0x794b6148) {
      piVar2 = (int *)(param_2 ^ 0x4000000000000000);
    }
    if (piVar2 == (int *)0x0) {
      return -0x3ffffff8;
    }
  }
  if (piVar3 == (int *)0x0) {
    NVar1 = -0x3ffffff3;
  }
  else {
    if (piVar2 != (int *)0x0) {
      hExportKey = *(BCRYPT_KEY_HANDLE *)(piVar2 + 4);
    }
    NVar1 = BCryptExportKey(*(BCRYPT_KEY_HANDLE *)(piVar3 + 4),hExportKey,param_3,param_4,param_5,
                            param_6,param_7);
  }
  return NVar1;
}



===== ProvFree @ 1c0001fb8 =====

void ProvFree(undefined8 param_1)

{
  ExFreePoolWithTag(param_1,0x48676e43);
  return;
}



===== ProvGenerateSymmetricKey @ 1c0001fe0 =====

NTSTATUS ProvGenerateSymmetricKey
                   (ulonglong param_1,ulonglong *param_2,undefined4 *param_3,uint param_4,
                   PUCHAR param_5,uint param_6,ULONG param_7)

{
  NTSTATUS NVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)0x0;
  if (*(int *)(param_1 ^ 0x4000000000000000) == 0x6c416148) {
    piVar3 = (int *)(param_1 ^ 0x4000000000000000);
  }
  if (piVar3 == (int *)0x0) {
    NVar1 = -0x3ffffff8;
  }
  else if (param_3 == (undefined4 *)0x0) {
    NVar1 = -0x3ffffff3;
  }
  else if (param_4 < g_cbMyKeyObjectSize) {
    NVar1 = -0x3fffffdd;
  }
  else {
    memset(param_3,0,0x70);
    iVar2 = piVar3[2];
    param_3[2] = iVar2;
    if (iVar2 == 1) {
      param_3[0x1a] = 0x10;
      *(undefined4 **)(param_3 + 0x18) = param_3 + 10;
    }
    if (0x1f < param_6) {
      param_6 = 0x20;
    }
    NVar1 = BCryptGenerateSymmetricKey
                      (*(BCRYPT_ALG_HANDLE *)(piVar3 + 4),(BCRYPT_KEY_HANDLE *)(param_3 + 4),
                       (PUCHAR)(param_3 + 0x1c),g_cbSoftwareKeyObjectSize,param_5,param_6,param_7);
    if (NVar1 < 0) {
      DestroyKeyObject((undefined1 *)param_3);
    }
    else {
      memcpy(param_3 + 0xe,param_5,(ulonglong)param_6);
      param_3[0x16] = param_6;
      *param_3 = 0x794b6148;
      LOCK();
      UNLOCK();
      iVar2 = g_ulUnique + 1;
      g_ulUnique = g_ulUnique + 1;
      param_3[1] = iVar2;
      if ((char)piVar3[3] == '\0') {
        AddHardwareKey((longlong)param_3,'\x01');
      }
      else {
        *(undefined1 *)(param_3 + 3) = 1;
      }
      *param_2 = (ulonglong)param_3 ^ 0x4000000000000000;
      NVar1 = 0;
    }
  }
  return NVar1;
}



===== ProvGetProperty @ 1c0002150 =====

NTSTATUS ProvGetProperty(ulonglong param_1,wchar_t *param_2,PUCHAR param_3,uint param_4,
                        ULONG *param_5,ULONG param_6)

{
  int iVar1;
  undefined4 uVar2;
  NTSTATUS NVar3;
  int *piVar4;
  BCRYPT_HANDLE hObject;
  int *piVar5;
  
  piVar4 = (int *)(param_1 ^ 0x4000000000000000);
  piVar5 = (int *)0x0;
  if (*piVar4 == 0x6c416148) {
    piVar5 = piVar4;
  }
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)0x0;
    if (*piVar4 == 0x794b6148) {
      piVar5 = piVar4;
    }
    if (piVar5 == (int *)0x0) {
      return -0x3ffffff8;
    }
    hObject = *(BCRYPT_HANDLE *)(piVar5 + 4);
LAB_1c0002216:
    NVar3 = BCryptGetProperty(hObject,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    iVar1 = wcscmp(param_2,L"HardwareThreads");
    if (iVar1 == 0) {
      *param_5 = 4;
      if (param_3 == (PUCHAR)0x0) {
        return 0;
      }
      if (3 < param_4) {
        uVar2 = g_config;
LAB_1c00021d8:
        *(undefined4 *)param_3 = uVar2;
        return 0;
      }
    }
    else {
      iVar1 = wcscmp(param_2,L"ObjectLength");
      if (iVar1 != 0) {
        hObject = *(BCRYPT_HANDLE *)(piVar5 + 4);
        goto LAB_1c0002216;
      }
      *param_5 = 4;
      if (param_3 == (PUCHAR)0x0) {
        return 0;
      }
      if (3 < param_4) {
        uVar2 = g_cbMyKeyObjectSize;
        goto LAB_1c00021d8;
      }
    }
    NVar3 = -0x3fffffdd;
  }
  return NVar3;
}



===== ProvImportKey @ 1c0002280 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS ProvImportKey(ulonglong param_1,ulonglong param_2,LPCWSTR param_3,ulonglong *param_4,
                      undefined4 *param_5,uint param_6,PUCHAR param_7,ULONG param_8,int param_9)

{
  BCRYPT_KEY_HANDLE *phKey;
  byte bVar1;
  NTSTATUS NVar2;
  int iVar3;
  int *piVar4;
  undefined7 extraout_var;
  longlong lVar5;
  UCHAR *pUVar6;
  int *piVar7;
  BCRYPT_KEY_HANDLE hImportKey;
  undefined1 auStackY_138 [32];
  ULONG local_e8 [2];
  PUCHAR local_e0;
  ulonglong *local_d8;
  UCHAR local_d0 [8];
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined4 local_a8;
  wchar_t local_98 [32];
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_138;
  local_e0 = param_7;
  local_d0[0] = '\0';
  local_d0[1] = '\0';
  local_d0[2] = '\0';
  local_d0[3] = '\0';
  local_d0[4] = '\0';
  local_d0[5] = '\0';
  local_d0[6] = '\0';
  local_d0[7] = '\0';
  uStack_c8 = 0;
  local_b0 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_a8 = 0;
  local_e8[0] = 0;
  if (param_9 == 0) {
    piVar7 = (int *)0x0;
    if (*(int *)(param_1 ^ 0x4000000000000000) == 0x6c416148) {
      piVar7 = (int *)(param_1 ^ 0x4000000000000000);
    }
    if (piVar7 == (int *)0x0) {
LAB_1c0002308:
      NVar2 = -0x3ffffff8;
      goto LAB_1c00024f9;
    }
    if (param_5 != (undefined4 *)0x0) {
      if (param_6 < g_cbMyKeyObjectSize) {
        NVar2 = -0x3fffffdd;
        goto LAB_1c00024f9;
      }
      if (param_2 == 0) {
        hImportKey = (BCRYPT_KEY_HANDLE)0x0;
      }
      else {
        piVar4 = (int *)0x0;
        if (*(int *)(param_2 ^ 0x4000000000000000) == 0x794b6148) {
          piVar4 = (int *)(param_2 ^ 0x4000000000000000);
        }
        if (piVar4 == (int *)0x0) goto LAB_1c0002308;
        hImportKey = *(BCRYPT_KEY_HANDLE *)(piVar4 + 4);
      }
      local_d8 = param_4;
      memset(param_5,0,0x70);
      phKey = (BCRYPT_KEY_HANDLE *)(param_5 + 4);
      NVar2 = BCryptImportKey(*(BCRYPT_ALG_HANDLE *)(piVar7 + 4),hImportKey,param_3,phKey,
                              (PUCHAR)(param_5 + 0x1c),g_cbSoftwareKeyObjectSize,local_e0,param_8,0)
      ;
      if (NVar2 < 0) {
        DestroyKeyObject((undefined1 *)param_5);
        goto LAB_1c00024f9;
      }
      NVar2 = BCryptGetProperty(*phKey,L"ChainingMode",(PUCHAR)local_98,0x40,local_e8,0);
      if (NVar2 < 0) {
LAB_1c0002408:
        *(undefined1 *)(param_5 + 3) = 1;
      }
      else {
        bVar1 = ConvertToInternalChainingMode(local_98,0x40);
        iVar3 = (int)CONCAT71(extraout_var,bVar1);
        param_5[2] = iVar3;
        if (iVar3 == 1) {
          param_5[0x1a] = 0x10;
          *(undefined4 **)(param_5 + 0x18) = param_5 + 10;
        }
        else if (iVar3 == 2) {
          *(undefined8 *)(param_5 + 0x18) = 0;
          param_5[0x1a] = 0;
        }
        else if (iVar3 == 0) goto LAB_1c0002408;
      }
      NVar2 = BCryptExportKey(*phKey,(BCRYPT_KEY_HANDLE)0x0,L"KeyDataBlob",local_d0,0x2c,local_e8,0)
      ;
      if (NVar2 < 0) {
        *(undefined1 *)(param_5 + 3) = 1;
      }
      else {
        param_5[0x16] = (undefined4)uStack_c8;
        memcpy(param_5 + 0xe,(void *)((longlong)&uStack_c8 + 4),uStack_c8 & 0xffffffff);
      }
      NVar2 = BCryptGetProperty(*phKey,L"IV",(PUCHAR)(param_5 + 10),0x10,local_e8,0);
      if ((NVar2 < 0) || (local_e8[0] != 0x10)) {
        *(undefined1 *)(param_5 + 3) = 1;
      }
      if (*(char *)(param_5 + 3) == '\0') {
        AddHardwareKey((longlong)param_5,'\x01');
      }
      *param_5 = 0x794b6148;
      LOCK();
      UNLOCK();
      iVar3 = g_ulUnique + 1;
      g_ulUnique = g_ulUnique + 1;
      param_5[1] = iVar3;
      *local_d8 = (ulonglong)param_5 ^ 0x4000000000000000;
      NVar2 = 0;
      goto LAB_1c00024f9;
    }
  }
  NVar2 = -0x3ffffff3;
LAB_1c00024f9:
  pUVar6 = local_d0;
  for (lVar5 = 0x2c; lVar5 != 0; lVar5 = lVar5 + -1) {
    *pUVar6 = '\0';
    pUVar6 = pUVar6 + 1;
  }
  return NVar2;
}



===== ProvSetAlgProperty @ 1c0002530 =====

ulonglong ProvSetAlgProperty(longlong param_1,wchar_t *param_2,wchar_t *param_3,uint param_4,
                            ULONG param_5)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined7 extraout_var;
  ulonglong uVar5;
  ulonglong uVar6;
  wchar_t *pwVar7;
  
  uVar5 = (ulonglong)param_4;
  pwVar7 = param_3;
  iVar2 = wcscmp(param_2,L"CngChatConfiguration");
  if (iVar2 == 0) {
    uVar4 = ConfigSetChatConfig((int *)param_3,param_4);
    uVar6 = uVar4 & 0xffffffff;
    if (-1 < (int)uVar4) {
      ConfigApplyBounds();
      LogConfig("Set",uVar5,pwVar7);
    }
  }
  else {
    uVar3 = BCryptSetProperty(*(BCRYPT_HANDLE *)(param_1 + 0x10),param_2,(PUCHAR)param_3,param_4,
                              param_5);
    uVar6 = (ulonglong)uVar3;
    if (-1 < (int)uVar3) {
      iVar2 = wcscmp(param_2,L"ChainingMode");
      if (iVar2 == 0) {
        bVar1 = ConvertToInternalChainingMode(param_3,uVar5);
        iVar2 = (int)CONCAT71(extraout_var,bVar1);
        *(int *)(param_1 + 8) = iVar2;
        if (iVar2 != 0) {
          return uVar6;
        }
      }
      *(undefined1 *)(param_1 + 0xc) = 1;
    }
  }
  return uVar6;
}



===== ProvSetKeyProperty @ 1c0002600 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

NTSTATUS ProvSetKeyProperty(longlong param_1,wchar_t *param_2,wchar_t *param_3,uint param_4,
                           ULONG param_5)

{
  undefined8 uVar1;
  bool bVar2;
  byte bVar3;
  NTSTATUS NVar4;
  int iVar5;
  undefined7 extraout_var;
  
  bVar2 = false;
  if (*(char *)(param_1 + 0xc) == '\0') {
    iVar5 = wcscmp(param_2,L"ChainingMode");
    if (iVar5 == 0) {
      bVar3 = ConvertToInternalChainingMode(param_3,(ulonglong)param_4);
      iVar5 = (int)CONCAT71(extraout_var,bVar3);
      if ((*(char *)(param_1 + 0xd) == '\0') && (iVar5 != 0)) {
        bVar2 = true;
      }
      else {
        SwitchKeyToSoftwareOnly(param_1);
      }
      *(int *)(param_1 + 8) = iVar5;
      if (iVar5 == 1) {
        *(undefined4 *)(param_1 + 0x68) = 0x10;
        *(longlong *)(param_1 + 0x60) = param_1 + 0x28;
      }
      else if (iVar5 == 2) {
        *(undefined8 *)(param_1 + 0x60) = 0;
        *(undefined4 *)(param_1 + 0x68) = 0;
      }
    }
    else {
      if ((((*param_2 == L'I') && (param_2[1] == L'V')) && (param_2[2] == L'\0')) &&
         (param_4 == 0x10)) {
        uVar1 = *(undefined8 *)(param_3 + 4);
        *(undefined8 *)(param_1 + 0x28) = *(undefined8 *)param_3;
        *(undefined8 *)(param_1 + 0x30) = uVar1;
        return 0;
      }
      SwitchKeyToSoftwareOnly(param_1);
    }
    NVar4 = BCryptSetProperty(*(BCRYPT_HANDLE *)(param_1 + 0x10),param_2,(PUCHAR)param_3,param_4,
                              param_5);
    if (((-1 < NVar4) && (*(char *)(param_1 + 0xc) == '\0')) &&
       ((bVar2 && (*(longlong *)(param_1 + 0x18) != 0)))) {
      iVar5 = (**(code **)(g_pHwCipherFunctionTable + 0x18))
                        (*(longlong *)(param_1 + 0x18),param_2,param_3,(ulonglong)param_4,param_5);
      if (iVar5 < 0) {
        SwitchKeyToSoftwareOnly(param_1);
      }
      NVar4 = 0;
    }
  }
  else {
    NVar4 = BCryptSetProperty(*(BCRYPT_HANDLE *)(param_1 + 0x10),param_2,(PUCHAR)param_3,param_4,
                              param_5);
  }
  return NVar4;
}



===== ProvSetProperty @ 1c0002780 =====

ulonglong ProvSetProperty(ulonglong param_1,wchar_t *param_2,wchar_t *param_3,uint param_4,
                         ULONG param_5)

{
  NTSTATUS NVar1;
  int *piVar2;
  ulonglong uVar3;
  undefined4 extraout_var;
  int *piVar4;
  
  piVar2 = (int *)(param_1 ^ 0x4000000000000000);
  piVar4 = (int *)0x0;
  if (*piVar2 == 0x6c416148) {
    piVar4 = piVar2;
  }
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
    if (*piVar2 == 0x794b6148) {
      piVar4 = piVar2;
    }
    if (piVar4 == (int *)0x0) {
      uVar3 = 0xc0000008;
    }
    else {
      NVar1 = ProvSetKeyProperty((longlong)piVar4,param_2,param_3,param_4,param_5);
      uVar3 = CONCAT44(extraout_var,NVar1);
    }
  }
  else {
    uVar3 = ProvSetAlgProperty((longlong)piVar4,param_2,param_3,param_4,param_5);
  }
  return uVar3;
}



===== SoftwareCryptPiece @ 1c00027e8 =====

void SoftwareCryptPiece(longlong *param_1)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  ULONG dwFlags;
  uint cbInput;
  ULONG local_res8 [2];
  
  local_res8[0] = 0;
  uVar1 = *(uint *)(param_1 + 4);
  if (uVar1 < *(uint *)(*param_1 + 0x20) * 2) {
    dwFlags = *(ULONG *)((longlong)param_1 + 0x54);
    cbInput = uVar1;
  }
  else {
    dwFlags = 0;
    cbInput = *(uint *)(*param_1 + 0x20);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_b2d1c9449828375308fac8044c0c397c_Traceguids,
               *(undefined4 *)((longlong)param_1 + 0x9c),(char)cbInput,(char)uVar1);
  }
  if ((char)param_1[2] == '\0') {
    iVar3 = BCryptEncrypt(*(BCRYPT_KEY_HANDLE *)(param_1[1] + 0x10),(PUCHAR)param_1[3],cbInput,
                          (void *)0x0,(PUCHAR)param_1[5],*(ULONG *)(param_1 + 6),(PUCHAR)param_1[7],
                          *(ULONG *)(param_1 + 8),local_res8,dwFlags);
  }
  else {
    iVar3 = BCryptDecrypt(*(BCRYPT_KEY_HANDLE *)(param_1[1] + 0x10),(PUCHAR)param_1[3],cbInput,
                          (void *)0x0,(PUCHAR)param_1[5],*(ULONG *)(param_1 + 6),(PUCHAR)param_1[7],
                          *(ULONG *)(param_1 + 8),local_res8,dwFlags);
  }
  *(int *)(param_1 + 0xb) = iVar3;
  if (iVar3 < 0) {
    *(undefined4 *)(param_1 + 0x13) = 3;
  }
  else {
    *(uint *)(param_1 + 4) = (int)param_1[4] - cbInput;
    *(uint *)(param_1 + 8) = (int)param_1[8] - cbInput;
    param_1[3] = param_1[3] + (ulonglong)cbInput;
    param_1[7] = param_1[7] + (ulonglong)cbInput;
    *(ULONG *)(param_1 + 10) = (int)param_1[10] + local_res8[0];
    if (dwFlags != 0) {
      lVar2 = param_1[1];
      *(undefined8 *)(lVar2 + 0x28) = 0;
      *(undefined8 *)(lVar2 + 0x30) = 0;
    }
    if ((int)param_1[4] == 0) {
      *(undefined4 *)(param_1 + 0x13) = 3;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_b2d1c9449828375308fac8044c0c397c_Traceguids,
               *(undefined4 *)((longlong)param_1 + 0x9c));
    }
  }
  return;
}



===== SwitchKeyToSoftwareOnly @ 1c0002958 =====

void SwitchKeyToSoftwareOnly(longlong param_1)

{
  if (*(char *)(param_1 + 0xc) == '\0') {
    *(undefined1 *)(param_1 + 0xc) = 1;
    BCryptSetProperty(*(BCRYPT_HANDLE *)(param_1 + 0x10),L"IV",(PUCHAR)(param_1 + 0x28),0x10,0);
  }
  return;
}



===== WPP_SF_D @ 1c0002998 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_DD @ 1c00029dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_b2d1c9449828375308fac8044c0c397c_Traceguids,param_2,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_DDD @ 1c0002a34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,4,0);
  return;
}



===== WaitForRequestEvent @ 1c0002a90 =====

void WaitForRequestEvent(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  longlong *plVar8;
  undefined8 local_res8;
  
  lVar1 = param_1 + 0x68;
  local_res8 = 0xfffffffffd050f80;
  iVar4 = KeWaitForSingleObject(lVar1,0,0,0,&local_res8);
  do {
    if (iVar4 != 0x102) {
      KeClearEvent(lVar1);
      return;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_D(*(undefined **)((longlong)WPP_GLOBAL_Control + 0x18),0xc,
               &WPP_b2d1c9449828375308fac8044c0c397c_Traceguids,*(undefined4 *)(param_1 + 0x9c));
    }
    uVar5 = KeQueryPriorityThread(*(undefined8 *)(param_1 + 0x60));
    uVar3 = KeAcquireSpinLockRaiseToDpc(&g_spinlock);
    uVar2 = g_actualHardwareThreads;
    if (*(int *)(param_1 + 0x98) == 6) {
      if (*(uint *)(param_1 + 0x80) != uVar5) {
        removeRequestFromPriorityQueue(param_1);
        *(uint *)(param_1 + 0x80) = uVar5;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                   &WPP_5afc3381049b3d6e12f0c116e8be5d0a_Traceguids,*(undefined4 *)(param_1 + 0x9c))
          ;
        }
        uVar2 = *(uint *)(param_1 + 0x80);
        *(undefined4 *)(param_1 + 0x98) = 1;
        *(int *)(&g_SwThreadsRunning + (ulonglong)uVar2 * 4) =
             *(int *)(&g_SwThreadsRunning + (ulonglong)uVar2 * 4) + 1;
        if (g_maxPrioritySoftware <= uVar2) {
          g_maxPrioritySoftware = uVar2;
        }
        g_nSwThreadsRunning = g_nSwThreadsRunning + 1;
        KeSetEvent(lVar1,0,0);
      }
    }
    else if ((*(int *)(param_1 + 0x98) == 5) && (*(uint *)(param_1 + 0x80) != uVar5)) {
      uVar7 = 0;
      *(uint *)(param_1 + 0x80) = uVar5;
      if (uVar2 != 0) {
        plVar8 = &g_hwEngineState;
        do {
          if (*plVar8 == param_1) {
            if (DAT_1c00077f4 != 0) {
              if (uVar5 < 0xe) {
                uVar5 = uVar5 + 1;
              }
              if ((uint)(&DAT_1c0007678)[uVar7 * 0xe] < uVar5) {
                (&DAT_1c0007678)[uVar7 * 0xe] = uVar5;
                KeSetActualBasePriorityThread((&DAT_1c0007670)[uVar7 * 7],uVar5);
              }
            }
            break;
          }
          uVar6 = (int)uVar7 + 1;
          uVar7 = (ulonglong)uVar6;
          plVar8 = plVar8 + 7;
        } while (uVar6 < uVar2);
      }
    }
    KeReleaseSpinLock(&g_spinlock,uVar3);
    iVar4 = KeWaitForSingleObject(lVar1,0,0,0,&local_res8);
  } while( true );
}



===== LogConfig @ 1c0002cbc =====

void LogConfig(char *param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,param_1);
  }
  iVar3 = 0;
  lVar5 = 0;
  do {
    lVar4 = 0;
    lVar2 = 0;
    do {
      iVar1 = *(int *)((longlong)&DAT_1c0006064 + lVar2);
      if (((-1 < iVar1) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_dSD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar2,(longlong)iVar1,iVar3,
                   *(wchar_t **)((longlong)&PTR_u_nHwThreads_1c0006068 + lVar2),
                   (char)*(undefined4 *)((longlong)&g_config + lVar5 + iVar1));
      }
      lVar4 = lVar4 + 1;
      lVar2 = lVar4 * 0x10;
    } while (*(int *)(&ConfigSetting + lVar2) != 0);
    iVar3 = iVar3 + 1;
    lVar5 = lVar5 + 0x40;
  } while (iVar3 < 3);
  return;
}



===== WPP_SF_d @ 1c0002d94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_d(undefined8 param_1)

{
  undefined4 local_18 [6];
  
  local_18[0] = g_currentConfig;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_946236d2e182355298098a526199d40a_Traceguids,0xc,local_18,4,0);
  return;
}



===== WPP_SF_dSD @ 1c0002de4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dSD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               wchar_t *param_5,undefined1 param_6)

{
  longlong lVar1;
  undefined4 local_res20 [2];
  
  if (param_5 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_5[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"NULL";
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_946236d2e182355298098a526199d40a_Traceguids,0xb,local_res20,4,param_5
             ,lVar1,&param_6,4,0);
  return;
}



===== WPP_SF_s @ 1c0002e94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_s(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4)

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
            (param_1,0x2b,&WPP_946236d2e182355298098a526199d40a_Traceguids,10,param_4,lVar2,0);
  return;
}



===== GetHardwareAlgHandle @ 1c0002f00 =====

undefined8 GetHardwareAlgHandle(uint param_1)

{
  if (param_1 < 3) {
    return *(undefined8 *)(&g_hAlgHardware + (ulonglong)param_1 * 8);
  }
  return 0;
}



===== HardwareThreadStartFunction @ 1c0002f20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void HardwareThreadStartFunction(longlong *param_1)

{
  uint uVar1;
  longlong *plVar2;
  longlong lVar3;
  int iVar4;
  code *pcVar5;
  uint uVar6;
  int local_res8 [2];
  
  local_res8[0] = 0;
  KeWaitForSingleObject(param_1 + 4,0,0,0,0);
  while( true ) {
    plVar2 = (longlong *)*param_1;
    lVar3 = *plVar2;
    if (*(longlong *)(plVar2[1] + 0x18) == 0) break;
    uVar1 = *(uint *)(plVar2 + 4);
    uVar6 = *(uint *)(lVar3 + 4);
    if ((uVar1 <= *(int *)(lVar3 + 8) + *(uint *)(lVar3 + 4)) &&
       (uVar6 = *(uint *)(lVar3 + 0xc), uVar1 < *(uint *)(lVar3 + 0xc))) {
      uVar6 = uVar1;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                 &WPP_dc649db454553ffbf1df728cab577077_Traceguids,
                 *(undefined4 *)((longlong)plVar2 + 0x9c),(char)uVar6,(char)uVar1);
    }
    if ((char)plVar2[2] == '\0') {
      pcVar5 = *(code **)(g_pHwCipherFunctionTable + 0x30);
    }
    else {
      pcVar5 = *(code **)(g_pHwCipherFunctionTable + 0x38);
    }
    iVar4 = (*pcVar5)(*(undefined8 *)(plVar2[1] + 0x18),plVar2[3],uVar6,0,plVar2[5],(int)plVar2[6],
                      plVar2[7],(int)plVar2[8],local_res8,*(undefined4 *)(lVar3 + 0x18));
    if ((iVar4 == -0x3ffffb9a) && (local_res8[0] == 0)) {
      *(uint *)((longlong)plVar2 + 0x5c) = *(uint *)((longlong)plVar2 + 0x5c) | 1;
    }
    else {
      *(int *)(plVar2 + 0xb) = iVar4;
      if (iVar4 < 0) break;
      *(uint *)(plVar2 + 4) = (int)plVar2[4] - uVar6;
      *(uint *)(plVar2 + 8) = (int)plVar2[8] - uVar6;
      plVar2[3] = plVar2[3] + (ulonglong)uVar6;
      plVar2[7] = plVar2[7] + (ulonglong)uVar6;
      *(int *)(plVar2 + 10) = (int)plVar2[10] + local_res8[0];
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                 &WPP_dc649db454553ffbf1df728cab577077_Traceguids,
                 *(undefined4 *)((longlong)plVar2 + 0x9c));
      }
    }
    ScheduleRequestFromHardware(param_1);
    KeWaitForSingleObject(param_1 + 4,0,0,0,0);
  }
                    /* WARNING: Subroutine does not return */
  KeBugCheck(0x6c746166);
}



===== TryRequestInHardware @ 1c00030e0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong TryRequestInHardware(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  uint uVar2;
  ulonglong in_RAX;
  ulonglong uVar3;
  undefined8 uVar4;
  uint uVar5;
  
  uVar3 = 0;
  uVar5 = ((uint *)*param_1)[0xc] & _g_mHwThreadsIdle;
  if (uVar5 == 0) {
    if (DAT_1c00077f4 != 0) {
      uVar5 = *(uint *)(param_1 + 0x10);
      in_RAX = (ulonglong)uVar5;
      uVar1 = *(uint *)*param_1;
      uVar2 = uVar5 + 1;
      if (0xd < uVar5) {
        uVar2 = uVar5;
      }
      if (uVar1 != 0) {
        in_RAX = 0;
        do {
          if ((uint)(&DAT_1c0007678)[uVar3 * 0xe] < uVar2) {
            (&DAT_1c0007678)[in_RAX * 0xe] = uVar2;
            in_RAX = KeSetActualBasePriorityThread((&DAT_1c0007670)[in_RAX * 7]);
            break;
          }
          uVar5 = (int)in_RAX + 1;
          in_RAX = (ulonglong)uVar5;
          uVar3 = (ulonglong)uVar5;
        } while (uVar5 < uVar1);
      }
    }
    uVar3 = in_RAX & 0xffffffffffffff00;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) {
      WPP_SF_Dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,
                *(undefined4 *)((longlong)param_1 + 0x9c),(char)*(undefined4 *)(param_1 + 4));
    }
    uVar1 = 0;
    if (uVar5 != 0) {
      for (; (uVar5 >> uVar1 & 1) == 0; uVar1 = uVar1 + 1) {
      }
    }
    uVar3 = (ulonglong)uVar1;
    *(undefined4 *)(param_1 + 0x13) = 5;
    if ((uVar5 == 0) || ((&g_hwEngineState)[uVar3 * 7] != 0)) {
                    /* WARNING: Subroutine does not return */
      KeBugCheck(0x6c746166);
    }
    (&g_hwEngineState)[uVar3 * 7] = param_1;
    _g_mHwThreadsIdle = _g_mHwThreadsIdle & ~(&DAT_1c0007668)[uVar3 * 0xe];
    if (DAT_1c00077f4 != 0) {
      uVar5 = g_maxPrioritySoftware;
      if (g_maxPrioritySoftware < *(uint *)(param_1 + 0x10)) {
        uVar5 = *(uint *)(param_1 + 0x10);
      }
      uVar1 = uVar5 + 1;
      if (0xd < uVar5) {
        uVar1 = uVar5;
      }
      if ((&DAT_1c0007678)[uVar3 * 0xe] != uVar1) {
        uVar4 = (&DAT_1c0007670)[uVar3 * 7];
        (&DAT_1c0007678)[uVar3 * 0xe] = uVar1;
        KeSetActualBasePriorityThread(uVar4);
      }
    }
    uVar4 = KeSetEvent(&DAT_1c0007680 + uVar3 * 0x38,0,0);
    uVar3 = CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
  }
  return uVar3;
}



===== WPP_SF_Dd @ 1c0003260 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_dc649db454553ffbf1df728cab577077_Traceguids,10,local_res20,4,&param_5
             ,4,0);
  return;
}



===== IsAllowedOnHardware @ 1c00032b8 =====

undefined8 IsAllowedOnHardware(longlong *param_1)

{
  uint uVar1;
  ulonglong uVar2;
  undefined1 uVar3;
  
  uVar2 = (ulonglong)*(uint *)((longlong)param_1 + 0x5c);
  uVar3 = 1;
  if ((*(uint *)((longlong)param_1 + 0x5c) & 1) == 0) {
    uVar1 = *(uint *)(*param_1 + 0x24);
    uVar2 = (ulonglong)uVar1;
    if ((uVar1 <= g_nSwThreadsRunning) &&
       (uVar1 = *(int *)(*param_1 + 0x34) * (int)param_1[4], uVar2 = (ulonglong)uVar1,
       uVar1 >> 8 <= g_nBytesInQueues)) goto LAB_1c00032e9;
  }
  uVar3 = 0;
LAB_1c00032e9:
  return CONCAT71((int7)(uVar2 >> 8),uVar3);
}



===== ScheduleRequestAfterSoftwarePiece @ 1c00032f4 =====

undefined1 ScheduleRequestAfterSoftwarePiece(longlong *param_1)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  uint uVar8;
  ulonglong uVar9;
  undefined4 *puVar10;
  longlong *plVar11;
  undefined1 uVar12;
  ulonglong uVar13;
  
  lVar2 = *param_1;
  uVar5 = KeQueryPriorityThread(param_1[0xc]);
  uVar4 = KeAcquireSpinLockRaiseToDpc(&g_spinlock);
  uVar3 = g_maxPrioritySoftware;
  uVar1 = *(uint *)(param_1 + 0x10);
  uVar13 = (ulonglong)uVar1;
  uVar7 = (ulonglong)g_maxPrioritySoftware;
  uVar8 = g_nSwThreadsRunning - 1;
  uVar9 = (ulonglong)uVar8;
  g_nSwThreadsRunning = uVar8;
  *(int *)(&g_SwThreadsRunning + uVar13 * 4) = *(int *)(&g_SwThreadsRunning + uVar13 * 4) + -1;
  if (uVar1 == uVar3) {
    if (uVar8 == 0) {
      g_maxPrioritySoftware = 0;
    }
    else if (*(int *)(&g_SwThreadsRunning + uVar7 * 4) == 0) {
      do {
        g_maxPrioritySoftware = (int)uVar7 - 1;
        uVar7 = (ulonglong)g_maxPrioritySoftware;
      } while (*(int *)(&g_SwThreadsRunning + uVar7 * 4) == 0);
    }
  }
  *(undefined4 *)(param_1 + 0x10) = uVar5;
  if (*(uint *)(param_1 + 4) < *(uint *)(lVar2 + 8)) {
    *(uint *)((longlong)param_1 + 0x5c) = *(uint *)((longlong)param_1 + 0x5c) | 1;
  }
  if ((int)param_1[0x13] == 3) {
    uVar12 = 0;
  }
  else {
    uVar6 = IsAllowedOnHardware(param_1);
    if (((char)uVar6 == '\0') ||
       (uVar6 = TryRequestInHardware(param_1,uVar9,uVar13), (char)uVar6 == '\0')) {
      uVar6 = shouldRunInSoftware(param_1);
      if ((char)uVar6 == '\0') {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                   &WPP_5afc3381049b3d6e12f0c116e8be5d0a_Traceguids,
                   *(undefined4 *)((longlong)param_1 + 0x9c));
        }
        addRequestToPriorityQueue((longlong)param_1);
        uVar12 = 1;
      }
      else {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                   &WPP_5afc3381049b3d6e12f0c116e8be5d0a_Traceguids,
                   *(undefined4 *)((longlong)param_1 + 0x9c));
        }
        uVar1 = *(uint *)(param_1 + 0x10);
        *(int *)(&g_SwThreadsRunning + (ulonglong)uVar1 * 4) =
             *(int *)(&g_SwThreadsRunning + (ulonglong)uVar1 * 4) + 1;
        if (g_maxPrioritySoftware <= uVar1) {
          g_maxPrioritySoftware = uVar1;
        }
        g_nSwThreadsRunning = g_nSwThreadsRunning + 1;
        uVar12 = 0;
      }
      goto LAB_1c000358b;
    }
    uVar12 = 1;
  }
  if (((uint)DAT_1c0007444 == 0) ||
     (puVar10 = &g_priorityQueueSw, (uint)DAT_1c0007444 < DAT_1c0007224)) {
    puVar10 = &g_priorityQueueHw;
  }
  if ((puVar10[1] == 0) ||
     (plVar11 = (longlong *)(*(longlong *)(puVar10 + (ulonglong)(uint)puVar10[1] * 4 + 2) + -0x88),
     plVar11 == (longlong *)0x0)) goto LAB_1c000358b;
  uVar6 = shouldRunInSoftware(plVar11);
  if ((char)uVar6 == '\0') {
    if (((*(int *)(lVar2 + 0x1c) != 0) || ((uint)DAT_1c0007444 == 0)) ||
       (DAT_1c0007224 <= (uint)DAT_1c0007444)) goto LAB_1c000358b;
    plVar11 = (longlong *)
              (*(longlong *)((longlong)&DAT_1c0007444 + (DAT_1c0007444 & 0xffffffff) * 0x10 + 4) +
              -0x88);
    uVar6 = shouldRunInSoftware(plVar11);
    if ((char)uVar6 == '\0') goto LAB_1c000358b;
  }
  removeRequestFromPriorityQueue((longlong)plVar11);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_5afc3381049b3d6e12f0c116e8be5d0a_Traceguids,
             *(undefined4 *)((longlong)plVar11 + 0x9c));
  }
  uVar1 = *(uint *)(plVar11 + 0x10);
  *(undefined4 *)(plVar11 + 0x13) = 1;
  *(int *)(&g_SwThreadsRunning + (ulonglong)uVar1 * 4) =
       *(int *)(&g_SwThreadsRunning + (ulonglong)uVar1 * 4) + 1;
  if (g_maxPrioritySoftware <= uVar1) {
    g_maxPrioritySoftware = uVar1;
  }
  g_nSwThreadsRunning = g_nSwThreadsRunning + 1;
  KeSetEvent(plVar11 + 0xd,0,0);
LAB_1c000358b:
  KeReleaseSpinLock(&g_spinlock,uVar4);
  return uVar12;
}



===== ScheduleRequestFromHardware @ 1c00035c4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ScheduleRequestFromHardware(undefined8 *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  uint uVar3;
  undefined1 uVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined2 uVar7;
  longlong *plVar8;
  
  plVar8 = (longlong *)*param_1;
  lVar2 = *plVar8;
  uVar5 = KeQueryPriorityThread(plVar8[0xc]);
  uVar4 = KeAcquireSpinLockRaiseToDpc(&g_spinlock);
  plVar1 = plVar8 + 0x13;
  *(uint *)(plVar8 + 0x10) = uVar5;
  if (*(uint *)(plVar8 + 4) == 0) {
    *(int *)plVar1 = 3;
  }
  if (*(uint *)(plVar8 + 4) < *(uint *)(lVar2 + 8)) {
    *(uint *)((longlong)plVar8 + 0x5c) = *(uint *)((longlong)plVar8 + 0x5c) | 1;
LAB_1c0003631:
    _g_mHwThreadsIdle = _g_mHwThreadsIdle | *(uint *)(param_1 + 1);
    *param_1 = 0;
    KeClearEvent(param_1 + 4);
    if ((int)*plVar1 == 3) {
      KeSetEvent(plVar8 + 0xd,0,0);
    }
    else {
      uVar6 = shouldRunInSoftware(plVar8);
      if ((char)uVar6 == '\0') {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                   &WPP_5afc3381049b3d6e12f0c116e8be5d0a_Traceguids,
                   *(undefined4 *)((longlong)plVar8 + 0x9c));
        }
        addRequestToPriorityQueue((longlong)plVar8);
      }
      else {
        uVar5 = *(uint *)(plVar8 + 0x10);
        *(int *)plVar1 = 1;
        *(int *)(&g_SwThreadsRunning + (ulonglong)uVar5 * 4) =
             *(int *)(&g_SwThreadsRunning + (ulonglong)uVar5 * 4) + 1;
        if (g_maxPrioritySoftware <= uVar5) {
          g_maxPrioritySoftware = uVar5;
        }
        g_nSwThreadsRunning = g_nSwThreadsRunning + 1;
        KeSetEvent(plVar8 + 0xd,0,0);
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                   &WPP_5afc3381049b3d6e12f0c116e8be5d0a_Traceguids,
                   *(undefined4 *)((longlong)plVar8 + 0x9c));
        }
      }
    }
    if (DAT_1c0007224 == 0) goto LAB_1c0003863;
    lVar2 = (&DAT_1c0007228)[(ulonglong)DAT_1c0007224 * 2];
    plVar8 = (longlong *)(lVar2 + -0x88);
    removeRequestFromPriorityQueue((longlong)plVar8);
    *(undefined4 *)(lVar2 + 0x10) = 5;
    *param_1 = plVar8;
    _g_mHwThreadsIdle = _g_mHwThreadsIdle & ~*(uint *)(param_1 + 1);
    if (DAT_1c00077f4 != 0) {
      uVar5 = g_maxPrioritySoftware;
      if (g_maxPrioritySoftware < *(uint *)(lVar2 + -8)) {
        uVar5 = *(uint *)(lVar2 + -8);
      }
      uVar3 = uVar5 + 1;
      if (0xd < uVar5) {
        uVar3 = uVar5;
      }
      if (*(uint *)(param_1 + 3) != uVar3) {
        *(uint *)(param_1 + 3) = uVar3;
        KeSetActualBasePriorityThread(param_1[2]);
      }
    }
    KeSetEvent(param_1 + 4,0,0);
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) goto LAB_1c0003863;
    uVar7 = 0x15;
  }
  else {
    if ((int)*plVar1 == 3) goto LAB_1c0003631;
    uVar6 = IsAllowedOnHardware(plVar8);
    if (((char)uVar6 == '\0') || (uVar5 < DAT_1c0007224)) goto LAB_1c0003631;
    if (DAT_1c00077f4 != 0) {
      if (uVar5 < 0xe) {
        uVar5 = uVar5 + 1;
      }
      if (*(uint *)(param_1 + 3) < uVar5) {
        *(uint *)(param_1 + 3) = uVar5;
        KeSetActualBasePriorityThread(param_1[2],uVar5);
      }
    }
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) == 0)) goto LAB_1c0003863;
    uVar7 = 0x12;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,
           &WPP_5afc3381049b3d6e12f0c116e8be5d0a_Traceguids,*(undefined4 *)((longlong)plVar8 + 0x9c)
          );
LAB_1c0003863:
  KeReleaseSpinLock(&g_spinlock,uVar4);
  return;
}



===== ScheduleRequestNew @ 1c000389c =====

undefined1 ScheduleRequestNew(longlong *param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  longlong lVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined1 uVar7;
  
  lVar2 = *param_1;
  uVar4 = KeQueryPriorityThread(param_1[0xc]);
  *(undefined4 *)(param_1 + 0x10) = uVar4;
  uVar3 = KeAcquireSpinLockRaiseToDpc(&g_spinlock);
  uVar6 = (ulonglong)*(uint *)(lVar2 + 8);
  uVar7 = 1;
  if (*(uint *)(param_1 + 4) < *(uint *)(lVar2 + 8)) {
    *(uint *)((longlong)param_1 + 0x5c) = *(uint *)((longlong)param_1 + 0x5c) | 1;
  }
  uVar5 = IsAllowedOnHardware(param_1);
  if ((char)uVar5 != '\0') {
    uVar5 = TryRequestInHardware(param_1,uVar6,param_3);
    if ((char)uVar5 != '\0') goto LAB_1c00039b7;
  }
  uVar5 = shouldRunInSoftware(param_1);
  if ((char)uVar5 == '\0') {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
               &WPP_5afc3381049b3d6e12f0c116e8be5d0a_Traceguids,
               *(undefined4 *)((longlong)param_1 + 0x9c));
    }
    addRequestToPriorityQueue((longlong)param_1);
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x10);
    *(undefined4 *)(param_1 + 0x13) = 1;
    *(int *)(&g_SwThreadsRunning + (ulonglong)uVar1 * 4) =
         *(int *)(&g_SwThreadsRunning + (ulonglong)uVar1 * 4) + 1;
    if (g_maxPrioritySoftware <= uVar1) {
      g_maxPrioritySoftware = uVar1;
    }
    g_nSwThreadsRunning = g_nSwThreadsRunning + 1;
    uVar7 = 0;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_5afc3381049b3d6e12f0c116e8be5d0a_Traceguids,
               *(undefined4 *)((longlong)param_1 + 0x9c));
    }
  }
LAB_1c00039b7:
  KeReleaseSpinLock(&g_spinlock,uVar3);
  return uVar7;
}



===== WPP_SF_ @ 1c00039e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1)

{
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_5afc3381049b3d6e12f0c116e8be5d0a_Traceguids,10,0);
  return;
}



===== WPP_SF_dDD @ 1c0003a1c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_5afc3381049b3d6e12f0c116e8be5d0a_Traceguids,0xb,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== addRequestToPriorityQueue @ 1c0003a80 =====

void addRequestToPriorityQueue(longlong param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  uint uVar5;
  undefined8 *puVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined1 *puVar9;
  int *piVar10;
  int *piVar11;
  undefined8 *puVar12;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [48];
  
  puVar9 = auStack_38;
  uVar8 = (ulonglong)*(uint *)(param_1 + 0x80);
  if (0x1e < *(uint *)(param_1 + 0x80) - 1) {
                    /* WARNING: Subroutine does not return */
    KeBugCheck(0x6c746166);
  }
  piVar10 = &g_priorityQueueSw;
  *(undefined4 *)(param_1 + 0x98) = 6;
  if ((*(uint *)(param_1 + 0x5c) & 1) == 0) {
    piVar10 = &g_priorityQueueHw;
  }
  puVar12 = (undefined8 *)(param_1 + 0x88);
  piVar11 = piVar10 + uVar8 * 4 + 2;
  puVar6 = *(undefined8 **)(piVar11 + 2);
  if ((int *)*puVar6 != piVar11) {
    param_1 = 3;
    pcVar4 = (code *)swi(0x29);
    puVar6 = (undefined8 *)(*pcVar4)();
    puVar9 = auStack_30;
  }
  *puVar12 = piVar11;
  puVar12[1] = puVar6;
  *puVar6 = puVar12;
  *(undefined8 **)(piVar11 + 2) = puVar12;
  uVar7 = (uint)uVar8;
  iVar1 = *piVar10;
  uVar5 = piVar10[1];
  if ((uint)piVar10[1] <= uVar7) {
    uVar5 = uVar7;
  }
  *piVar10 = iVar1 + 1;
  piVar10[1] = uVar5;
  g_nBytesInQueues = g_nBytesInQueues + (ulonglong)*(uint *)(param_1 + 0x20);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    *(int *)(puVar9 + 0x28) = iVar1 + 1;
    uVar2 = *(undefined4 *)(param_1 + 0x5c);
    uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(uint *)(puVar9 + 0x20) = uVar7;
    *(undefined8 *)(puVar9 + -8) = 0x1c0003b49;
    WPP_SF_dDD(uVar3,uVar8,WPP_GLOBAL_Control,uVar2,puVar9[0x20],puVar9[0x28]);
  }
  return;
}



===== removeRequestFromPriorityQueue @ 1c0003b58 =====

void removeRequestFromPriorityQueue(longlong param_1)

{
  longlong *plVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  uint uVar7;
  int *piVar8;
  
  piVar8 = &g_priorityQueueSw;
  uVar2 = *(uint *)(param_1 + 0x80);
  if ((*(uint *)(param_1 + 0x5c) & 1) == 0) {
    piVar8 = &g_priorityQueueHw;
  }
  plVar1 = (longlong *)(param_1 + 0x88);
  lVar4 = *plVar1;
  if ((*(longlong **)(lVar4 + 8) != plVar1) ||
     (plVar5 = *(longlong **)(param_1 + 0x90), (longlong *)*plVar5 != plVar1)) {
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)(3);
    pcVar6 = (code *)swi(3);
    (*pcVar6)();
    return;
  }
  *plVar5 = lVar4;
  *(longlong **)(lVar4 + 8) = plVar5;
  iVar3 = *piVar8;
  uVar7 = piVar8[1];
  *piVar8 = iVar3 + -1;
  g_nBytesInQueues = g_nBytesInQueues - (ulonglong)*(uint *)(param_1 + 0x20);
  if (uVar2 == uVar7) {
    if (iVar3 + -1 == 0) {
      piVar8[1] = 0;
    }
    else {
      while (*(int **)(piVar8 + (ulonglong)uVar7 * 4 + 2) == piVar8 + (ulonglong)uVar7 * 4 + 2) {
        uVar7 = uVar7 - 1;
        piVar8[1] = uVar7;
      }
    }
  }
  return;
}



===== shouldRunInSoftware @ 1c0003be8 =====

undefined8 shouldRunInSoftware(longlong *param_1)

{
  ulonglong uVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  
  if (0x1f < *(uint *)(param_1 + 0x10)) {
                    /* WARNING: Subroutine does not return */
    KeBugCheck(0x6c746166);
  }
  uVar2 = 1;
  uVar1 = (ulonglong)g_nSwThreadsRunning;
  uVar3 = *(uint *)(*param_1 + 0x1c);
  if (g_nSwThreadsRunning < uVar3) goto LAB_1c0003c67;
  if (uVar3 == 0) {
    if ((*(uint *)((longlong)param_1 + 0x5c) & 1) == 0) {
LAB_1c0003c65:
      uVar2 = 0;
      goto LAB_1c0003c67;
    }
    uVar3 = *(uint *)(*param_1 + 0x38);
    if (g_nSwThreadsRunning < uVar3) goto LAB_1c0003c67;
  }
  for (uVar4 = g_maxPrioritySoftware; *(uint *)(param_1 + 0x10) <= uVar4; uVar4 = uVar4 - 1) {
    uVar1 = (ulonglong)uVar4;
    if (uVar3 <= *(uint *)(&g_SwThreadsRunning + uVar1 * 4)) goto LAB_1c0003c65;
    uVar3 = uVar3 - *(uint *)(&g_SwThreadsRunning + uVar1 * 4);
  }
LAB_1c0003c67:
  return CONCAT71((int7)(uVar1 >> 8),uVar2);
}



===== _guard_check_icall @ 1c0003c80 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0003c98 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c0003cbc =====

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



===== __GSHandlerCheck_SEH @ 1c0003d24 =====

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



===== wcscmp @ 1c0003db6 =====

int __cdecl wcscmp(wchar_t *_Str1,wchar_t *_Str2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0003db6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = wcscmp(_Str1,_Str2);
  return iVar1;
}



===== __cpu_features_init @ 1c0003dd0 =====

/* WARNING: Removing unreachable block (ram,0x0001c0003e3a) */
/* WARNING: Removing unreachable block (ram,0x0001c0003de9) */
/* WARNING: Removing unreachable block (ram,0x0001c0003dda) */

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



===== __security_check_cookie @ 1c0003ea0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0003ee0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0003f10 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0003f10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0003f40 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0003fc0 =====

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



===== memset @ 1c00042c0 =====

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



===== __memset_repmovs @ 1c0004400 =====

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



===== __memset_query @ 1c0004480 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0004500 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0004640 =====

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



===== __memset_spec_plain @ 1c00046c0 =====

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



===== ProvCreateClose @ 1c000a010 =====

undefined8 ProvCreateClose(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== ProvDeviceControl @ 1c000a040 =====

undefined4 ProvDeviceControl(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  uVar4 = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  if ((((*(longlong *)(lVar1 + 0x20) != 0) && (0x27 < *(uint *)(lVar1 + 0x10))) &&
      (puVar2 = *(undefined8 **)(param_2 + 0x70), puVar2 != (undefined8 *)0x0)) &&
     (7 < *(uint *)(lVar1 + 8))) {
    if (*(int *)(lVar1 + 0x18) != 0x220007) {
      uVar4 = 0xc0000010;
      goto LAB_1c000a0bc;
    }
    iVar3 = RtlCompareUnicodeString(*(longlong *)(lVar1 + 0x20) + 8,&DAT_1c0007018,0);
    if (iVar3 == 0) {
      *puVar2 = &ProvCipherFunctionTable;
      goto LAB_1c000a0bc;
    }
  }
  uVar4 = 0xc000000d;
LAB_1c000a0bc:
  *(undefined4 *)(param_2 + 0x30) = uVar4;
  IofCompleteRequest(param_2,0);
  return uVar4;
}



===== ProvUnloadDriver @ 1c000a0f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ProvUnloadDriver(longlong param_1)

{
  longlong lVar1;
  undefined *puVar2;
  
  lVar1 = *(longlong *)(param_1 + 8);
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    puVar2 = WPP_GLOBAL_Control;
    if (WPPTraceSuite == 4) {
      for (; puVar2 != (undefined *)0x0; puVar2 = *(undefined **)(puVar2 + 0x10)) {
        if (*(longlong *)(puVar2 + 0x38) != 0) {
          (*pfnEtwUnregister)();
          *(undefined8 *)(puVar2 + 0x38) = 0;
        }
      }
    }
    else if (WPPTraceSuite == 2) {
      IoWMIRegistrationControl(WPP_GLOBAL_Control,0x80000002);
    }
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
  }
  if (lVar1 != 0) {
    IoDeleteDevice(lVar1);
  }
  return;
}



===== WppInitKm @ 1c000a194 =====

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



===== WppLoadTracingSupport @ 1c000a224 =====

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



===== WppTraceCallback @ 1c000a370 =====

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



===== ProvCloseAlgorithmProvider @ 1c000a600 =====

undefined8 ProvCloseAlgorithmProvider(ulonglong param_1,int param_2)

{
  int *piVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  if (param_2 == 0) {
    piVar1 = GetPointerFromAlgHandle(param_1);
    if (piVar1 == (int *)0x0) {
      uVar2 = 0xc0000008;
    }
    else {
      if (*(BCRYPT_ALG_HANDLE *)(piVar1 + 4) != (BCRYPT_ALG_HANDLE)0x0) {
        BCryptCloseAlgorithmProvider(*(BCRYPT_ALG_HANDLE *)(piVar1 + 4),0);
      }
      piVar1[0] = 0x66666666;
      piVar1[1] = 0x66666666;
      piVar1[2] = 0x66666666;
      piVar1[3] = 0x66666666;
      piVar1[4] = 0x66666666;
      piVar1[5] = 0x66666666;
      ProvFree(piVar1);
    }
  }
  else {
    uVar2 = 0xc000000d;
  }
  return uVar2;
}



===== ProvOpenAlgorithmProvider @ 1c000a670 =====

NTSTATUS ProvOpenAlgorithmProvider(ulonglong *param_1,wchar_t *param_2,ULONG param_3)

{
  int iVar1;
  NTSTATUS NVar2;
  undefined4 *puVar3;
  ulonglong uVar4;
  ULONG local_res20 [2];
  int local_18 [2];
  BCRYPT_ALG_HANDLE local_10;
  
  local_10 = (BCRYPT_ALG_HANDLE)0x0;
  local_18[0] = 0;
  local_res20[0] = 0;
  iVar1 = wcscmp(param_2,L"AES");
  if (iVar1 != 0) {
    return -0x3fffff45;
  }
  NVar2 = BCryptOpenAlgorithmProvider(&local_10,param_2,L"Microsoft Primitive Provider",param_3);
  if (NVar2 < 0) goto LAB_1c000a7b5;
  puVar3 = ProvAlloc(0x18);
  if (puVar3 == (undefined4 *)0x0) {
    NVar2 = -0x3fffffe9;
    goto LAB_1c000a7b5;
  }
  *puVar3 = 0x6c416148;
  LOCK();
  UNLOCK();
  iVar1 = g_ulUnique + 1;
  g_ulUnique = g_ulUnique + 1;
  *(undefined1 *)(puVar3 + 3) = 0;
  puVar3[1] = iVar1;
  puVar3[2] = 1;
  *(BCRYPT_ALG_HANDLE *)(puVar3 + 4) = local_10;
  local_10 = (BCRYPT_ALG_HANDLE)0x0;
  if (g_cbSoftwareKeyObjectSize == 0) {
    NVar2 = BCryptGetProperty(*(BCRYPT_HANDLE *)(puVar3 + 4),L"ObjectLength",(PUCHAR)local_18,4,
                              local_res20,0);
    if (-1 < NVar2) {
      if (local_res20[0] == 4) {
        g_cbSoftwareKeyObjectSize = local_18[0];
        g_cbMyKeyObjectSize = local_18[0] + 0x70;
        goto LAB_1c000a7aa;
      }
      NVar2 = -0x3fffff1b;
    }
    if (*(BCRYPT_ALG_HANDLE *)(puVar3 + 4) != (BCRYPT_ALG_HANDLE)0x0) {
      BCryptCloseAlgorithmProvider(*(BCRYPT_ALG_HANDLE *)(puVar3 + 4),0);
      *(undefined8 *)(puVar3 + 4) = 0;
    }
    ProvFree(puVar3);
  }
  else {
LAB_1c000a7aa:
    uVar4 = GetHandleFromPointer((ulonglong)puVar3);
    *param_1 = uVar4;
  }
LAB_1c000a7b5:
  if (local_10 != (BCRYPT_ALG_HANDLE)0x0) {
    BCryptCloseAlgorithmProvider(local_10,0);
  }
  return NVar2;
}



===== ConfigApplyBounds @ 1c000a7e8 =====

void ConfigApplyBounds(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  longlong lVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  
  lVar7 = 3;
  puVar6 = &DAT_1c00077e8;
  do {
    uVar1 = g_actualHardwareThreads;
    if (g_actualHardwareThreads == 0) {
      uVar1 = 4;
    }
    uVar4 = 0;
    if (puVar6[-2] != 0) {
      uVar4 = puVar6[-2];
    }
    if (uVar4 < uVar1) {
      uVar1 = uVar4;
    }
    puVar6[-2] = uVar1;
    uVar1 = puVar6[-1];
    if (uVar1 < 0x41) {
      uVar1 = 0x40;
    }
    else if (0xfffff < uVar1) {
      uVar1 = 0x100000;
    }
    puVar6[-1] = uVar1 & 0xffffffc0;
    uVar1 = *puVar6;
    if (uVar1 < 0x41) {
      uVar1 = 0x40;
    }
    else if (0xfffff < uVar1) {
      uVar1 = 0x100000;
    }
    uVar1 = uVar1 & 0xffffffc0;
    *puVar6 = uVar1;
    uVar4 = puVar6[1];
    if (uVar4 < 0x41) {
      uVar4 = 0x40;
    }
    else if (0xfffff < uVar4) {
      uVar4 = 0x100000;
    }
    uVar10 = puVar6[2];
    if (uVar10 < 2) {
      uVar9 = 1;
    }
    else {
      uVar9 = (ulonglong)uVar10;
      if (uVar10 == 0xffffffff) {
        uVar9 = 0xffffffff;
      }
    }
    puVar6[2] = (uint)uVar9;
    uVar10 = 0;
    if (puVar6[5] != 0) {
      uVar10 = puVar6[5];
    }
    if (7 < uVar10) {
      uVar10 = 8;
    }
    puVar6[5] = uVar10;
    uVar2 = puVar6[6];
    if (uVar2 < 0x401) {
      uVar2 = 0x400;
    }
    else if (0xfffff < uVar2) {
      uVar2 = 0x100000;
    }
    puVar6[6] = uVar2 & 0xfffffff0;
    uVar2 = 0;
    if (puVar6[7] != 0) {
      uVar2 = puVar6[7];
    }
    if (7 < uVar2) {
      uVar2 = 8;
    }
    uVar5 = 0;
    if (puVar6[8] != 0) {
      uVar5 = puVar6[8];
    }
    if (0xfff < uVar5) {
      uVar5 = 0x1000;
    }
    uVar8 = uVar4 & 0xffffffc0;
    if ((uVar4 & 0xffffffc0) <= uVar1) {
      uVar8 = uVar1;
    }
    puVar6[1] = uVar8;
    uVar4 = puVar6[-1];
    if (puVar6[-1] <= uVar1) {
      uVar4 = uVar1;
    }
    if (uVar4 < uVar8) {
      uVar8 = uVar4;
    }
    puVar6[-1] = uVar8;
    if (uVar10 <= uVar2) {
      uVar2 = uVar10;
    }
    puVar6[7] = uVar2;
    uVar4 = puVar6[0xc];
    if (uVar10 <= puVar6[0xc]) {
      uVar4 = uVar10;
    }
    puVar6[0xc] = uVar4;
    if (uVar1 <= uVar5) {
      uVar5 = uVar1;
    }
    puVar6[8] = uVar5;
    puVar6[0xb] = (uint)((uVar10 << 0x10) / uVar9);
    if (uVar4 == 0) {
      iVar3 = KeQueryActiveProcessorCount(0,(ulonglong)(uVar10 << 0x10) % uVar9);
      puVar6[0xc] = iVar3 + 1U >> 1;
    }
    if (puVar6[-2] == 0 && puVar6[5] == 0) {
      puVar6[5] = 1;
    }
    puVar6[10] = (1 << ((byte)puVar6[-2] & 0x1f)) - 1;
    puVar6 = puVar6 + 0x10;
    lVar7 = lVar7 + -1;
  } while (lVar7 != 0);
  return;
}



===== ConfigReadRegistry @ 1c000a9b8 =====

void ConfigReadRegistry(void)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  longlong local_res8;
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
  local_34 = 0;
  lVar3 = 0;
  local_res8 = 0;
  local_48 = 0;
  uStack_40 = 0;
  RtlInitUnicodeString
            (&local_48,
             L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Services\\CngHwAssist\\Parameters");
  local_30 = 0;
  local_28 = &local_48;
  local_38 = 0x30;
  local_20 = 0x40;
  local_18 = 0;
  uStack_10 = 0;
  iVar2 = ZwOpenKey(&local_res8,1);
  lVar1 = local_res8;
  if (-1 < iVar2) {
    local_res8 = 0;
    lVar3 = lVar1;
  }
  if (local_res8 != 0) {
    ZwClose();
  }
  if (-1 < iVar2) {
    ConfigReadRegistryOne(lVar3,0x1c0006548,0);
    ConfigReadRegistryOne(lVar3,0x1c00067d8,1);
    ConfigReadRegistryOne(lVar3,0x1c00067e8,2);
  }
  if (lVar3 != 0) {
    ZwClose(lVar3);
  }
  return;
}



===== ConfigReadRegistryOne @ 1c000aac8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

short * ConfigReadRegistryOne(undefined8 param_1,longlong param_2,uint param_3)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  short *psVar4;
  longlong lVar5;
  uint uVar6;
  longlong lVar7;
  longlong lVar8;
  uint uVar9;
  ulonglong uVar10;
  longlong lVar11;
  undefined1 auStack_f8 [32];
  undefined4 local_d8 [4];
  short local_c8 [64];
  short *local_48;
  
  psVar3 = (short *)(__security_cookie ^ (ulonglong)auStack_f8);
  local_48 = psVar3;
  local_d8[0] = 0;
  uVar9 = 0;
  lVar8 = 0;
  do {
    if (-1 < *(int *)((longlong)&DAT_1c0006064 + lVar8)) {
      psVar3 = local_c8;
      lVar7 = 0x40;
      do {
        if ((lVar7 == -0x7fffffbe) ||
           (sVar1 = *(short *)((param_2 - (longlong)local_c8) + (longlong)psVar3), sVar1 == 0))
        break;
        *psVar3 = sVar1;
        psVar3 = psVar3 + 1;
        lVar7 = lVar7 + -1;
      } while (lVar7 != 0);
      psVar4 = psVar3 + -1;
      if (lVar7 != 0) {
        psVar4 = psVar3;
      }
      *psVar4 = 0;
      if (lVar7 == 0) {
        return psVar4;
      }
      psVar3 = local_c8;
      lVar7 = 0x40;
      do {
        if (*psVar3 == 0) break;
        psVar3 = psVar3 + 1;
        lVar7 = lVar7 + -1;
      } while (lVar7 != 0);
      uVar10 = -(ulonglong)(lVar7 != 0) & 0x40U - lVar7;
      psVar3 = (short *)-lVar7;
      uVar6 = ~-(uint)(lVar7 != 0) & 0x80070057;
      if (lVar7 != 0) {
        psVar4 = local_c8 + uVar10;
        lVar7 = 0x40 - uVar10;
        if (lVar7 != 0) {
          lVar5 = 0x7ffffffe;
          lVar11 = *(longlong *)((longlong)&PTR_u_nHwThreads_1c0006068 + lVar8) - (longlong)psVar4;
          do {
            if ((lVar5 == 0) || (sVar1 = *(short *)(lVar11 + (longlong)psVar4), sVar1 == 0)) break;
            *psVar4 = sVar1;
            lVar5 = lVar5 + -1;
            psVar4 = psVar4 + 1;
            lVar7 = lVar7 + -1;
          } while (lVar7 != 0);
        }
        psVar3 = psVar4 + -1;
        if (lVar7 != 0) {
          psVar3 = psVar4;
        }
        uVar6 = ~-(uint)(lVar7 != 0) & 0x8007007a;
        *psVar3 = 0;
      }
      if (uVar6 != 0) {
        return psVar3;
      }
      psVar3 = (short *)ReadDwordRegValue(param_1,local_c8,local_d8);
      if ((-1 < (int)psVar3) &&
         (iVar2 = *(int *)((longlong)&DAT_1c0006064 + lVar8), psVar3 = (short *)(longlong)iVar2,
         uVar6 = param_3, -1 < iVar2)) {
        while( true ) {
          psVar3 = (short *)0x3;
          if (param_3 != 0) {
            psVar3 = (short *)(ulonglong)(param_3 + 1);
          }
          if ((uint)psVar3 <= uVar6) break;
          *(undefined4 *)((short *)(longlong)iVar2 + (ulonglong)uVar6 * 0x20 + 0xe0003bf0) =
               local_d8[0];
          uVar6 = uVar6 + 1;
        }
      }
    }
    uVar9 = uVar9 + 1;
    lVar8 = (ulonglong)uVar9 * 0x10;
    if (*(int *)(&ConfigSetting + lVar8) == 0) {
      return psVar3;
    }
  } while( true );
}



===== ConfigSetChatConfig @ 1c000aca8 =====

undefined8 ConfigSetChatConfig(int *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  undefined8 uVar9;
  uint uVar10;
  ulonglong uVar11;
  
  uVar9 = 0;
  if (((((param_2 & 0xf) == 0) && (param_2 != 0)) && (*param_1 == -1)) &&
     ((param_1[1] == 0 && (*(longlong *)(param_1 + 2) == 1)))) {
    if (1 < param_2 >> 4) {
      puVar6 = (uint *)(param_1 + 5);
      uVar11 = (ulonglong)((param_2 >> 4) - 1);
      do {
        if (*puVar6 < 3) {
          uVar8 = 0;
          uVar7 = 0x10000;
          lVar4 = 0;
          do {
            if ((uVar7 == puVar6[-1]) && (puVar6[-1] < 0x50000)) {
              iVar1 = *(int *)((longlong)&DAT_1c0006064 + lVar4);
              uVar7 = puVar6[1];
              uVar2 = *puVar6;
              if (-1 < iVar1) {
                uVar10 = uVar2;
                while( true ) {
                  uVar3 = 3;
                  if (uVar2 != 0) {
                    uVar3 = uVar2 + 1;
                  }
                  if (uVar3 <= uVar10) break;
                  uVar5 = (ulonglong)uVar10;
                  uVar10 = uVar10 + 1;
                  *(uint *)((longlong)&g_config + uVar5 * 0x40 + (longlong)iVar1) = uVar7;
                }
              }
            }
            uVar8 = uVar8 + 1;
            lVar4 = (ulonglong)uVar8 * 0x10;
            uVar7 = *(uint *)(&ConfigSetting + lVar4);
          } while (uVar7 != 0);
        }
        puVar6 = puVar6 + 4;
        uVar11 = uVar11 - 1;
      } while (uVar11 != 0);
    }
  }
  else {
    uVar9 = 0xc000000d;
  }
  return uVar9;
}



===== EventStartCallback @ 1c000adb0 =====

void EventStartCallback(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  if (*(char *)(param_3 + 0x18) == '\0') {
    *(undefined1 *)(param_3 + 0x18) = 1;
    UpdateConfig();
  }
  return;
}



===== EventStopCallback @ 1c000ade0 =====

void EventStopCallback(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  if (*(char *)(param_3 + 0x18) != '\0') {
    *(undefined1 *)(param_3 + 0x18) = 0;
    UpdateConfig();
  }
  return;
}



===== ReadDwordRegValue @ 1c000ae04 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 ReadDwordRegValue(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  undefined8 uVar1;
  undefined1 auStack_98 [32];
  undefined4 local_78;
  undefined4 *local_70;
  undefined4 local_68 [2];
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined4 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_98;
  local_50 = 0;
  local_48 = 0;
  local_60 = 0;
  local_58 = 0;
  local_68[0] = 0;
  local_30 = 0;
  local_40 = 0;
  uStack_38 = 0;
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0xc00000e5;
  }
  else {
    RtlInitUnicodeString(&local_60);
    local_70 = local_68;
    local_78 = 0x14;
    uVar1 = ZwQueryValueKey(param_1,&local_60,2,&local_40);
    if (-1 < (int)uVar1) {
      if ((local_40._4_4_ == 4) && ((int)uStack_38 == 4)) {
        *param_3 = uStack_38._4_4_;
      }
      else {
        uVar1 = 0xc000090b;
      }
    }
  }
  return uVar1;
}



===== UpdateConfig @ 1c000aed8 =====

void UpdateConfig(void)

{
  ulonglong uVar1;
  int iVar2;
  
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&g_currentConfigLock,1);
  g_currentConfig = 0;
  iVar2 = 2;
  while( true ) {
    uVar1 = (ulonglong)(iVar2 - 1);
    if (((&DAT_1c0007040)[uVar1 * 4] != 0) && (*(char *)(&DAT_1c0007048 + uVar1 * 4) != '\0'))
    break;
    iVar2 = iVar2 + -1;
    if (iVar2 == 0) {
LAB_1c000af37:
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18));
      }
      ExReleaseResourceLite(&g_currentConfigLock);
      KeLeaveCriticalRegion();
      return;
    }
  }
  g_currentConfig = (&CngChatPowerConfig)[uVar1 * 8];
  goto LAB_1c000af37;
}



===== ChatDeviceCategoryChange @ 1c000af90 =====

int ChatDeviceCategoryChange(short *param_1)

{
  int iVar1;
  longlong lVar2;
  longlong local_res8;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  iVar1 = 0;
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((*param_1 == 1) && (*(longlong *)(param_1 + 10) == 0x41583cba231a2081)) &&
     (*(longlong *)(param_1 + 0xe) == 0x3537ef3aaffa7e82)) {
    if (((*(longlong *)(param_1 + 2) == 0x11d046f0cb3a4004) &&
        (*(longlong *)(param_1 + 6) == 0x3f05139760008fb0)) && (g_pHwCipherFunctionTable == 0)) {
      iVar1 = IoGetDeviceObjectPointer
                        (*(undefined8 *)(param_1 + 0x14),0x1f01ff,&g_HwProvFileObject,
                         &g_HwProvDeviceObject);
      if (-1 < iVar1) {
        local_2c = 0;
        local_30 = 1;
        local_28 = 0;
        uStack_20 = 0;
        local_18 = 0;
        uStack_10 = 0;
        RtlInitUnicodeString(&local_28,L"AES");
        local_res8 = 0;
        KeInitializeEvent(&local_48,0,0);
        lVar2 = IoBuildDeviceIoControlRequest
                          (0x220007,g_HwProvDeviceObject,&local_30,0x28,&local_res8,8,1,&local_48,
                           &local_58);
        if (lVar2 == 0) {
          iVar1 = -0x3fffff66;
        }
        else {
          iVar1 = IofCallDriver(g_HwProvDeviceObject,lVar2);
          if (iVar1 == 0x103) {
            KeWaitForSingleObject(&local_48,0,0,0,0);
            iVar1 = (int)local_58;
          }
          if (-1 < iVar1) {
            if (local_res8 == 0) {
              iVar1 = -0x3fffffff;
            }
            else {
              g_pHwCipherFunctionTable = local_res8;
              if (g_pnpNotificationEntry != 0) {
                IoUnregisterPlugPlayNotificationEx();
                g_pnpNotificationEntry = 0;
              }
              InitializeHardwareSystem();
            }
          }
        }
      }
    }
  }
  else {
    iVar1 = -0x3ffffff3;
  }
  return iVar1;
}



===== InitializeHardwareSystem @ 1c000b188 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int InitializeHardwareSystem(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  uint *puVar6;
  wchar_t *pwVar7;
  longlong lVar8;
  uint uVar9;
  undefined8 *puVar10;
  wchar_t *pwVar11;
  int *piVar12;
  uint uVar13;
  undefined1 auStack_398 [32];
  undefined8 local_378;
  undefined8 local_370;
  undefined8 *local_368;
  undefined8 local_358;
  undefined8 local_350;
  undefined8 local_348;
  undefined8 uStack_340;
  undefined8 local_338;
  undefined8 uStack_330;
  undefined8 local_328;
  ulonglong uStack_320;
  undefined8 local_318;
  undefined4 local_310;
  undefined4 local_30c;
  undefined8 local_308;
  undefined8 local_300;
  code *local_2f8;
  code *local_2f0;
  undefined8 *local_2e8;
  int local_2d8 [172];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_398;
  local_328 = 0;
  uStack_320 = uStack_320 & 0xffffffff00000000;
  local_348 = 0;
  uStack_340 = 0;
  local_350 = 0;
  local_338 = 0;
  uStack_330 = 0;
  iVar2 = (**(code **)(g_pHwCipherFunctionTable + 8))(&DAT_1c0007168,L"AES",1);
  if (-1 < iVar2) {
    UpdateKeyObjectSize(DAT_1c0007168);
    iVar2 = (**(code **)(g_pHwCipherFunctionTable + 8))(&DAT_1c0007170,L"AES",1);
    if (-1 < iVar2) {
      pwVar11 = L"ChainingModeECB";
      pwVar7 = L"ChainingMode";
      local_378 = (undefined8 *)((ulonglong)local_378._4_4_ << 0x20);
      iVar2 = (**(code **)(g_pHwCipherFunctionTable + 0x18))
                        (DAT_1c0007170,L"ChainingMode",L"ChainingModeECB",0x20);
      if (-1 < iVar2) {
        UpdateKeyObjectSize(DAT_1c0007170);
        puVar4 = &DAT_1c00077e8;
        do {
          puVar4[2] = 0xffffffff;
          puVar4[-2] = 0;
          puVar4[-1] = 0x8000;
          *puVar4 = 0x4000;
          puVar4[1] = 0x10000;
          *(undefined8 *)(puVar4 + 3) = 0;
          puVar4[5] = 1;
          *(undefined8 *)(puVar4 + 6) = 0x1000;
          puVar4[8] = 0x200;
          puVar4[9] = 0x400000;
          *(undefined8 *)(puVar4 + 0xc) = 0;
          puVar4 = puVar4 + 0x10;
        } while ((longlong)puVar4 < 0x1c00078a8);
        LogConfig("Default",pwVar7,pwVar11);
        local_358 = (ulonglong)local_358._4_4_ << 0x20;
        uVar5 = GetHardwareAlgHandle(1);
        piVar12 = local_2d8;
        local_370 = (code *)((ulonglong)local_370._4_4_ << 0x20);
        pwVar7 = L"CngChatConfiguration";
        local_378 = &local_358;
        iVar1 = (**(code **)(g_pHwCipherFunctionTable + 0x10))
                          (uVar5,L"CngChatConfiguration",piVar12,0x2b0);
        if (-1 < iVar1) {
          pwVar7 = (wchar_t *)(local_358 & 0xffffffff);
          if ((uint)local_358 < 0x2b1) {
            ConfigSetChatConfig(local_2d8,(uint)local_358);
          }
        }
        LogConfig("Provider",pwVar7,piVar12);
        ConfigReadRegistry();
        LogConfig("Registry",pwVar7,piVar12);
        ConfigApplyBounds();
        puVar6 = &g_config;
        _g_mHwThreadsIdle = 0;
        lVar8 = 3;
        uVar9 = 0;
        do {
          uVar3 = *puVar6;
          puVar6 = puVar6 + 0x10;
          if (uVar3 < uVar9) {
            uVar3 = uVar9;
          }
          uVar9 = uVar3;
          lVar8 = lVar8 + -1;
        } while (lVar8 != 0);
        LogConfig("Final",0,piVar12);
        if (uVar9 != 0) {
          puVar4 = &DAT_1c0007678;
          uVar3 = 0;
          do {
            *(undefined8 *)(puVar4 + -6) = 0;
            KeInitializeEvent(&DAT_1c0007680 + (ulonglong)uVar3 * 0x38,0,0);
            local_348 = CONCAT44(local_348._4_4_,0x30);
            uStack_340 = 0;
            local_368 = &g_hwEngineState + (ulonglong)uVar3 * 7;
            uStack_330 = CONCAT44(uStack_330._4_4_,0x200);
            local_338 = 0;
            local_370 = HardwareThreadStartFunction;
            local_378 = (undefined8 *)0x0;
            local_328 = 0;
            uStack_320 = 0;
            iVar2 = PsCreateSystemThread(&local_350,0,&local_348,0);
            if (iVar2 < 0) {
              return iVar2;
            }
            local_378 = &local_358;
            local_370 = (code *)0x0;
            local_358 = 0;
            ObReferenceObjectByHandle(local_350,0x1fffff);
            if (local_358 == 0) {
              return -0x3fffff1b;
            }
            *puVar4 = 0x12;
            *(ulonglong *)(puVar4 + -2) = local_358;
            KeSetActualBasePriorityThread();
            g_actualHardwareThreads = g_actualHardwareThreads + 1;
            uVar13 = uVar3 + 1;
            uVar3 = 1 << ((byte)uVar3 & 0x1f);
            _g_mHwThreadsIdle = _g_mHwThreadsIdle | uVar3;
            puVar4[-4] = uVar3;
            puVar4 = puVar4 + 0xe;
            uVar3 = uVar13;
          } while (uVar13 < uVar9);
        }
        puVar10 = &DAT_1c0007040;
        lVar8 = 2;
        do {
          local_308 = puVar10[-1];
          local_318 = 0;
          local_2f8 = EventStartCallback;
          local_2f0 = EventStopCallback;
          local_2e8 = puVar10 + -2;
          local_310 = 0;
          local_300 = 0;
          local_30c = 1;
          EACreateAggregateEvent(&local_318,puVar10);
          puVar10 = puVar10 + 4;
          lVar8 = lVar8 + -1;
        } while (lVar8 != 0);
        g_fHwProvAvailable = 1;
      }
    }
  }
  return iVar2;
}



===== UpdateKeyObjectSize @ 1c000b56c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UpdateKeyObjectSize(undefined8 param_1)

{
  int iVar1;
  uint uVar2;
  int local_res10 [2];
  int local_res18 [4];
  
  local_res18[0] = 0;
  local_res10[0] = 0;
  iVar1 = (**(code **)(g_pHwCipherFunctionTable + 0x10))
                    (param_1,L"ObjectLength",local_res18,4,local_res10,0);
  if (((-1 < iVar1) && (local_res10[0] == 4)) &&
     (uVar2 = local_res18[0] + 0xfU & 0xfffffff0, g_cbHardwareKeyObjectSize <= uVar2)) {
    g_cbHardwareKeyObjectSize = uVar2;
  }
  return;
}



===== entry @ 1c000c010 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 1c000c044 =====

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



===== DriverEntry @ 1c000c078 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DriverEntry(longlong param_1)

{
  int iVar1;
  undefined8 in_stack_ffffffffffffffd8;
  undefined4 uVar2;
  ulonglong in_stack_ffffffffffffffe0;
  
  uVar2 = (undefined4)((ulonglong)in_stack_ffffffffffffffd8 >> 0x20);
  _DAT_1c0007908 = 1;
  _WPP_MAIN_CB = 0;
  DAT_1c00078e8 = &WPP_ThisDir_CTLGUID_WPP_CHAT_CONTROL_GUID;
  DAT_1c00078f0 = 0;
  _DAT_1c0007900 = 0;
  WppLoadTracingSupport();
  _DAT_1c0007900 = 0;
  WppInitKm();
  *(code **)(param_1 + 0x70) = ProvCreateClose;
  *(code **)(param_1 + 0x80) = ProvCreateClose;
  *(code **)(param_1 + 0xe8) = ProvDeviceControl;
  *(code **)(param_1 + 0x68) = ProvUnloadDriver;
  iVar1 = IoCreateDevice(param_1,0,&DAT_1c0007000,0x22,CONCAT44(uVar2,0x100),
                         in_stack_ffffffffffffffe0 & 0xffffffffffffff00,&g_deviceObject);
  if (-1 < iVar1) {
    InitializeScheduler();
    iVar1 = IoRegisterPlugPlayNotification
                      (2,1,&GUID_CNG_CHAT_HW_PROV_INTERFACE,param_1,ChatDeviceCategoryChange,param_1
                       ,&g_pnpNotificationEntry);
    if (-1 < iVar1) {
      _g_mutexAddHardwareKey = 1;
      _DAT_1c00078a8 = 0;
      _DAT_1c00078b0 = 0;
      KeInitializeEvent(&DAT_1c00078b8,1,0);
      RegisterCngProvider();
    }
  }
  return;
}



===== RegisterCngProvider @ 1c000c1b4 =====

NTSTATUS RegisterCngProvider(void)

{
  NTSTATUS NVar1;
  ULONG local_res8 [2];
  PCRYPT_PROVIDER_REFS local_res10;
  wchar_t *local_res18;
  undefined4 *local_res20;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  wchar_t **local_68;
  wchar_t *local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 **local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  wchar_t **local_30;
  
  local_res10 = (PCRYPT_PROVIDER_REFS)0x0;
  local_res8[0] = 0;
  local_6c = 0;
  local_54 = 0;
  local_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_res18 = L"AES";
  BCryptUnregisterProvider(L"CngHwAssist");
  local_res20 = &local_78;
  local_68 = &local_res18;
  local_78 = 1;
  local_74 = 1;
  local_60 = L"CngHwAssist.sys";
  local_50 = &local_res20;
  local_70 = 1;
  local_30 = &local_60;
  local_58 = 1;
  NVar1 = BCryptResolveProviders((LPCWSTR)0x0,0,L"AES",L"CngHwAssist",2,0,local_res8,&local_res10);
  if (NVar1 == -0x3ffffddb) {
    NVar1 = BCryptRegisterProvider(L"CngHwAssist",0,&local_48);
    if (-1 < NVar1) {
      NVar1 = BCryptAddContextFunctionProvider(1,0,1,L"AES",L"CngHwAssist",0xffffffff);
    }
  }
  if (local_res10 != (PCRYPT_PROVIDER_REFS)0x0) {
    BCryptFreeBuffer(local_res10);
  }
  return NVar1;
}



===== InitializeScheduler @ 1c000c2ec =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitializeScheduler(void)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18));
  }
  KeInitializeSpinLock(&g_spinlock);
  memset(&g_SwThreadsRunning,0,0x80);
  lVar2 = 0;
  lVar3 = 0x20;
  do {
    lVar1 = (longlong)&DAT_1c0007228 + lVar2;
    *(longlong *)((longlong)&DAT_1c0007230 + lVar2) = lVar1;
    *(longlong *)lVar1 = lVar1;
    lVar1 = lVar2 + 0x1c0007448;
    *(longlong *)((longlong)&DAT_1c0007450 + lVar2) = lVar1;
    lVar2 = lVar2 + 0x10;
    *(longlong *)lVar1 = lVar1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  _g_priorityQueueHw = 0;
  _g_priorityQueueSw = 0;
  g_nBytesInQueues = 0;
  g_maxPrioritySoftware = 0;
  g_nSwThreadsRunning = 0;
  return;
}


