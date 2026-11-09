
===== _tlgKeywordOn @ 180001010 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong _tlgKeywordOn(undefined8 param_1,ulonglong param_2)

{
  ulonglong in_RAX;
  
  if (((_DAT_18001b058 & param_2) == 0) ||
     (in_RAX = DAT_18001b060 & param_2, in_RAX != DAT_18001b060)) {
    return in_RAX & 0xffffffffffffff00;
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== _tlgWriteTransfer_EtwWriteTransfer @ 18000103c =====

void _tlgWriteTransfer_EtwWriteTransfer
               (undefined8 param_1,byte *param_2,undefined8 param_3,undefined8 param_4,
               undefined4 param_5,undefined8 *param_6)

{
  int local_18;
  uint local_14;
  undefined8 local_10;
  
  local_18 = (uint)*param_2 << 0x18;
  local_14 = (uint)*(ushort *)(param_2 + 1);
  local_10 = *(undefined8 *)(param_2 + 3);
  *param_6 = PTR_DAT_18001b050;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_18001b050;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(DAT_18001b068,&local_18,0,0,param_5,param_6);
  return;
}



===== _tlgCreate1Sz_char @ 1800010ec =====

void _tlgCreate1Sz_char(longlong *param_1,char *param_2)

{
  int iVar1;
  longlong lVar2;
  
  if (param_2 == (char *)0x0) {
    param_2 = "";
    iVar1 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_2[lVar2] != '\0');
    iVar1 = (int)lVar2 + 1;
  }
  *(undefined4 *)((longlong)param_1 + 0xc) = 0;
  *param_1 = (longlong)param_2;
  *(int *)(param_1 + 1) = iVar1;
  return;
}



===== __report_gsfailure @ 180001130 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __report_rangecheckfailure @ 180001140 =====

void __report_rangecheckfailure(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(8);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 18000114d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00018000114d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== ext_ms_win_ntos_ksr_l1_1_1_KsrMdlToMemoryRuns @ 180001160 =====

undefined8 ext_ms_win_ntos_ksr_l1_1_1_KsrMdlToMemoryRuns(void)

{
  return 0xc00000bb;
}



===== ext_ms_win_ntos_ksr_l1_1_1_KsrFreePersistedMemory @ 180001170 =====

undefined8 ext_ms_win_ntos_ksr_l1_1_1_KsrFreePersistedMemory(void)

{
  return 0;
}



===== AddTriageDumpDataToBitmapDump @ 18000117c =====

void AddTriageDumpDataToBitmapDump(longlong *param_1)

{
  uint uVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong *plVar6;
  ulonglong uVar7;
  longlong *plVar8;
  ulonglong uVar9;
  uint *puVar10;
  uint local_res8 [2];
  
  plVar6 = DAT_18001c348;
  local_res8[0] = 0;
  uVar5 = (ulonglong)*(uint *)((longlong)param_1 + 0xc);
  if (7 < *(uint *)((longlong)param_1 + 0xc)) {
    uVar3 = 0;
    uVar4 = 0;
    param_1[2] = 0x4f04a64d2b4ae195;
    param_1[3] = 0x2ad41b984f7ede8e;
    if (param_1[4] == 0) {
      plVar6 = (longlong *)*plVar6;
      plVar8 = DAT_18001c348;
      if (plVar6 != DAT_18001c348) {
        do {
          uVar4 = uVar3;
          if (((int)plVar6[2] != 0) &&
             (uVar2 = UtilComputeConvertedCompactDataArraySize((longlong)plVar6,local_res8),
             -1 < (int)uVar2)) {
            uVar4 = 0xffffffff;
            if (uVar3 <= local_res8[0] + uVar3) {
              uVar4 = local_res8[0] + uVar3;
            }
          }
          plVar6 = (longlong *)*plVar6;
          uVar3 = uVar4;
        } while (plVar6 != plVar8);
      }
    }
    else {
      if (param_1[4] != *param_1) {
        return;
      }
      param_1[4] = (longlong)DAT_18001bdc8;
      puVar10 = DAT_18001bdc8;
      uVar4 = uVar3;
      if (*(ulonglong *)(DAT_18001bdc8 + 8) <= uVar5) {
        uVar5 = (ulonglong)DAT_18001bdc8[8];
      }
      while (plVar6 = (longlong *)*plVar6, plVar6 != DAT_18001c348) {
        uVar7 = (ulonglong)*(uint *)(plVar6 + 2);
        if (*(uint *)(plVar6 + 2) != 0) {
          uVar2 = UtilComputeConvertedCompactDataArraySize((longlong)plVar6,local_res8);
          uVar3 = local_res8[0];
          if (-1 < (int)uVar2) {
            uVar9 = (ulonglong)local_res8[0];
            uVar1 = local_res8[0] + uVar4;
            if (uVar1 < uVar4) {
              uVar4 = 0xffffffff;
            }
            else {
              if ((uint)uVar5 < local_res8[0]) {
                uVar4 = uVar1 - local_res8[0];
                break;
              }
              *puVar10 = (uint)uVar7;
              puVar10[1] = *(uint *)(plVar6 + 4);
              memcpy(puVar10 + 2,plVar6 + 6,(uVar7 & 0xffffffff) << 4);
              memcpy(puVar10 + (ulonglong)*puVar10 * 4 + 2,(void *)plVar6[5],
                     (ulonglong)*(uint *)(plVar6 + 4));
              puVar10 = (uint *)((longlong)puVar10 + uVar9);
              uVar5 = (ulonglong)((uint)uVar5 - uVar3);
              uVar4 = uVar1;
            }
          }
        }
      }
    }
    *(uint *)(param_1 + 5) = uVar4;
  }
  return;
}



===== AddTriageDumpDataToTriageDump @ 1800012dc =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void AddTriageDumpDataToTriageDump(longlong *param_1)

{
  longlong *plVar1;
  byte *pbVar2;
  undefined8 *puVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong *puVar6;
  undefined8 uVar7;
  bool bVar8;
  longlong *plVar9;
  char cVar10;
  int iVar11;
  uint uVar12;
  byte bVar13;
  uint uVar14;
  longlong *plVar15;
  ulonglong *puVar16;
  short local_res8 [4];
  uint local_res10 [2];
  uint local_res18 [2];
  
  plVar15 = (longlong *)param_1[6];
  plVar1 = param_1 + 4;
  uVar12 = *(uint *)((longlong)param_1 + 0xc);
  local_res8[0] = 0;
  local_res18[0] = 0;
  bVar8 = false;
  local_res10[0] = 0;
  *(undefined4 *)(param_1 + 5) = 0;
  param_1[2] = 0x4b15e6940d910545;
  param_1[3] = 0x6f2ab35f62010c87;
  if (plVar15 == (longlong *)0x0) {
    plVar15 = &CrashdmpExDataCallbackContext;
    param_1[6] = (longlong)&CrashdmpExDataCallbackContext;
    if (*plVar1 == 0) {
      CrashdmpExDataCallbackContext = 0;
      _DAT_18001b310 = 0;
      ram0x00018001b338 = 0;
      _DAT_18001b318 = 0;
      _DAT_18001b320 = 0;
      _DAT_18001b328 = 0;
      _DAT_18001b330 = 0;
    }
    _DAT_18001b320 = CONCAT44(0x18,_DAT_18001b320);
    _DAT_18001b328 = CONCAT62(_DAT_18001b32a,1);
  }
  plVar9 = DAT_18001c348;
  if (*plVar1 == 0) {
    iVar11 = ComputeExtendedArrayDataSize((int *)local_res10,local_res8);
    *(short *)((longlong)plVar15 + 0x22) = local_res8[0];
    *(uint *)((longlong)plVar15 + 0x24) = local_res10[0];
    if (iVar11 == 0) {
      if (local_res10[0] == 0) {
        return;
      }
      if (uVar12 < local_res10[0]) {
        *(uint *)(plVar15 + 6) = *(uint *)(plVar15 + 6) | 2;
        local_res10[0] = uVar12;
      }
    }
    else {
      *(uint *)(plVar15 + 6) = *(uint *)(plVar15 + 6) | 1;
      local_res10[0] = 0x18;
      *(int *)((longlong)plVar15 + 0x2c) = iVar11;
    }
    *(uint *)(plVar15 + 2) = local_res10[0];
    *(uint *)(plVar15 + 5) = local_res10[0];
    *(uint *)(param_1 + 5) = local_res10[0];
  }
  else if (0x17 < *(uint *)(param_1 + 1)) {
    pbVar2 = (byte *)(plVar15 + 3);
    bVar13 = *pbVar2;
    if ((bVar13 & 4) == 0) {
      uVar7 = *(undefined8 *)((longlong)plVar15 + 0x24);
      puVar3 = (undefined8 *)*param_1;
      *puVar3 = *(undefined8 *)((longlong)plVar15 + 0x1c);
      puVar3[1] = uVar7;
      puVar3[2] = *(undefined8 *)((longlong)plVar15 + 0x2c);
      *plVar1 = *param_1;
      *(undefined4 *)(param_1 + 5) = 0x18;
      if ((*(uint *)(plVar15 + 6) & 1) == 0) {
        *(uint *)(param_1 + 7) = *(uint *)(param_1 + 7) | 1;
      }
      *(int *)((longlong)plVar15 + 0x14) = *(int *)((longlong)plVar15 + 0x14) + 0x18;
      *pbVar2 = *pbVar2 | 4;
    }
    else {
      if (*plVar15 == 0) {
        *plVar15 = *DAT_18001c348;
      }
      do {
        if ((bVar13 & 8) != 0) {
          return;
        }
        lVar4 = *plVar15;
        if ((bVar13 & 1) == 0) {
          if ((*(int *)(lVar4 + 0x10) != 0) && (*(int *)(lVar4 + 0x18) != 0)) {
            uVar12 = WriteExtendedTriageDumpArrayHeader(lVar4,param_1,local_res18);
            if ((int)uVar12 < 0) {
              return;
            }
            *(byte *)(plVar15 + 3) = *(byte *)(plVar15 + 3) | 1;
            *(uint *)((longlong)plVar15 + 0xc) = local_res18[0];
            *(undefined4 *)(plVar15 + 1) = 0;
            *(int *)((longlong)plVar15 + 0x14) =
                 *(int *)((longlong)plVar15 + 0x14) + (int)param_1[5];
            return;
          }
        }
        else {
          puVar16 = (ulonglong *)(((ulonglong)*(uint *)(plVar15 + 1) + 3) * 0x10 + lVar4);
          uVar5 = puVar16[1];
          if ((bVar13 & 2) == 0) {
            puVar6 = (ulonglong *)*param_1;
            uVar14 = 0xffffffff;
            if (uVar5 < 0x100000000) {
              uVar14 = (uint)uVar5;
            }
            if (uVar12 < uVar14 + 0x10) {
              return;
            }
            if ((uVar14 == 0) || (cVar10 = IsBufferValid(*puVar16,uVar14), cVar10 == '\0')) {
              *puVar6 = 0;
              puVar6[1] = 0;
              *(int *)(plVar15 + 1) = (int)plVar15[1] + 1;
            }
            else {
              *puVar6 = *puVar16;
              puVar6[1] = (ulonglong)uVar14;
              *(byte *)(plVar15 + 3) = *(byte *)(plVar15 + 3) | 2;
            }
            *(uint *)(param_1 + 7) = *(uint *)(param_1 + 7) | 1;
            param_1[4] = *param_1;
            *(undefined4 *)(param_1 + 5) = 0x10;
            *(int *)((longlong)plVar15 + 0x14) = *(int *)((longlong)plVar15 + 0x14) + 0x10;
            return;
          }
          bVar8 = true;
          uVar14 = 0xffffffff;
          if (uVar5 < 0x100000000) {
            uVar14 = (uint)uVar5;
          }
          uVar5 = *puVar16;
          *(uint *)(param_1 + 5) = uVar14;
          param_1[4] = uVar5;
          *(int *)(plVar15 + 1) = (int)plVar15[1] + 1;
          bVar13 = *pbVar2 & 0xfd;
          *pbVar2 = bVar13;
          if ((int)plVar15[1] != *(int *)((longlong)plVar15 + 0xc)) break;
        }
        if (*(longlong **)*plVar15 == plVar9) {
          bVar13 = bVar13 | 8;
        }
        else {
          *plVar15 = (longlong)*(longlong **)*plVar15;
          bVar13 = bVar13 & 0xfe;
          *(undefined4 *)(plVar15 + 1) = 0;
        }
        *pbVar2 = bVar13;
      } while (!bVar8);
      *(int *)((longlong)plVar15 + 0x14) = *(int *)((longlong)plVar15 + 0x14) + (int)param_1[5];
      if ((bVar13 & 8) == 0) {
        *(uint *)(param_1 + 7) = *(uint *)(param_1 + 7) | 1;
      }
    }
  }
  return;
}



===== ComputeExtendedArrayDataSize @ 180001568 =====

void ComputeExtendedArrayDataSize(int *param_1,short *param_2)

{
  longlong *plVar1;
  uint uVar2;
  longlong *plVar3;
  int iVar4;
  short sVar5;
  uint local_res8 [2];
  uint local_res10 [2];
  
  plVar1 = DAT_18001c348;
  local_res10[0] = 0;
  local_res8[0] = 0;
  *param_1 = 0;
  uVar2 = 0;
  plVar3 = (longlong *)*plVar1;
  iVar4 = 0x18;
  *param_2 = 0;
  sVar5 = 0;
  if (plVar3 != plVar1) {
    do {
      if (((int)plVar3[2] != 0) && ((int)plVar3[3] != 0)) {
        uVar2 = UtilComputeExtendedArrayDataSize((longlong)plVar3,0,local_res10,local_res8);
        if (uVar2 != 0) break;
        iVar4 = iVar4 + 0x14 + ((int)plVar3[4] + 7U & 0xfffffff8) + local_res8[0];
        sVar5 = sVar5 + 1;
      }
      plVar3 = (longlong *)*plVar3;
    } while (plVar3 != plVar1);
    if ((-1 < (int)uVar2) && (sVar5 != 0)) {
      *param_1 = iVar4;
      *param_2 = sVar5;
    }
  }
  return;
}



===== CrashdmpCallbackForTriageDumpData @ 180001630 =====

void CrashdmpCallbackForTriageDumpData(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  if (DAT_18001bd58 - 5U < 2) {
    AddTriageDumpDataToBitmapDump(param_3);
  }
  else if ((DAT_18001bd58 == 4) && ((DAT_18001bd60 & 0x800000) != 0)) {
    AddTriageDumpDataToTriageDump(param_3);
  }
  return;
}



===== CrashdmpDisable @ 180001680 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong CrashdmpDisable(void)

{
  undefined8 uVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  lVar2 = DAT_18001bd40;
  uVar4 = CheckContextIntegrity();
  if ((int)uVar4 < 0) {
    return uVar4 & 0xffffffff;
  }
  if (DAT_18001bcf4 == '\0') {
    return uVar4 & 0xffffffff;
  }
  if (DAT_18001c528 == '\x01') {
    return 0xc0000184;
  }
  uVar4 = SetChangeState('\0','\x01');
  if ((int)uVar4 < 0) {
    return uVar4 & 0xffffffff;
  }
  if ((DAT_18001c4e0 != 0) && (ExUnregisterCallback(), (DAT_18001bd60 & 0x40000) == 0)) {
    CrashdmpKsrCancel(0x18001bd40);
  }
  if ((*(int *)(DAT_18001bd40 + 0x178) != 2) && (*(longlong *)(lVar2 + 8) != 0)) {
    ExFreePoolWithTag();
    *(undefined8 *)(lVar2 + 8) = 0;
  }
  if (DAT_18001c448 != 0) {
    ExFreePoolWithTag();
    DAT_18001c448 = 0;
  }
  uVar3 = CrashdmpFreeDumpStack(lVar2);
  uVar4 = (ulonglong)uVar3;
  if (-1 < (int)uVar3) {
    if (DAT_18001c529 == '\0') {
      uVar4 = 0;
    }
    else {
      uVar5 = McGenEventUnregister_EtwUnregister();
      uVar4 = uVar5 & 0xffffffff;
      if ((int)uVar5 < 0) goto LAB_1800017b2;
      DAT_18001c529 = '\0';
    }
    uVar1 = DAT_18001b068;
    if (DAT_18001c52a != '\0') {
      DAT_18001b068 = 0;
      DAT_18001b048 = 0;
      EtwUnregister(uVar1);
      DAT_18001c52a = '\0';
    }
  }
LAB_1800017b2:
  if (DmpEncryptionContext != '\0') {
    if (DAT_18001b3b8 != 0) {
      ExFreePoolWithTag();
      CurrentSecureDumpHeaderSize = 0;
    }
    _DmpEncryptionContext = 0;
    _DAT_18001b390 = 0;
    DAT_18001b3b8 = 0;
    DAT_18001b398 = 0;
    DAT_18001b3a0 = 0;
    _DAT_18001b3a8 = 0;
    _DAT_18001b3b0 = 0;
  }
  FreeCrashdmpResources(0x18001bd40);
  memset(&DAT_18001bd40,0,0x7e0);
  DAT_18001bcf4 = 0;
  SetChangeState('\0','\0');
  memcpy(&ContextCopy,&Context,0x8d0);
  return uVar4;
}



===== CrashdmpDumpCallback @ 180001860 =====

void CrashdmpDumpCallback(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  longlong *plVar1;
  
  if (7 < *(uint *)((longlong)param_3 + 0xc)) {
    plVar1 = (longlong *)param_3[4];
    param_3[2] = 0x43eaf14665755a40;
    param_3[3] = 0x35fd2857b836918c;
    if (plVar1 == (longlong *)0x0) {
      *(undefined4 *)(param_3 + 5) = 8;
      return;
    }
    if (((plVar1 == (longlong *)*param_3) && (DAT_18001c3f8 != 0)) &&
       (*(undefined4 *)(param_3 + 5) = 8, 7 < *(uint *)(param_3 + 1))) {
      *plVar1 = DAT_18001c3f8;
    }
  }
  return;
}



===== CrashdmpDumpNotification @ 1800018c0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int CrashdmpDumpNotification(int param_1,longlong param_2)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 local_res10 [2];
  undefined4 local_res18 [4];
  
  local_res18[0] = 0;
  cVar1 = KeGetCurrentIrql();
  if (cVar1 == '\0') {
    if ((param_1 == 0) && ((DAT_18001bd60 & 4) == 0)) {
      local_res10[0] = 0;
      _DAT_18001b480 = _DAT_18001b480 | 0x100;
      DAT_18001bd60 = DAT_18001bd60 | 0x100;
      uVar3 = 0x22;
      iVar2 = ZwSetSystemInformation(0x22,local_res10,4);
      if (-1 < iVar2) {
        uVar3 = 2;
        iVar2 = RtlWriteRegistryValue(2,L"CrashControl",L"CrashDumpEnabled",4,local_res18,4);
      }
      CrashdmpWriteErrorLog(uVar3,0x8004009c,0xc00002b6,0x6000,(void *)0x0,0);
    }
    else if ((((DAT_18001bd60 & 4) == 0) || (param_2 == 0)) || (DAT_18001c398 < 1)) {
      iVar2 = -0x3fffff45;
    }
    else {
      KeWaitForSingleObject(&DAT_18001c3b0,0,0,0,0);
      iVar2 = RemoveMpioPath(&DAT_18001c398,(int *)0x0,param_2);
      KeReleaseMutex(&DAT_18001c3b0,0);
      _DAT_18001bab8 = CONCAT44(uRam000000018001c39c,DAT_18001c398);
      uRam000000018001bac0 = _DAT_18001c3a0;
      _DAT_18001bac8 = DAT_18001c3a8;
      uRam000000018001bad0 = _DAT_18001c3b0;
      _DAT_18001bad8 = _DAT_18001c3b8;
      uRam000000018001bae0 = uRam000000018001c3c0;
      _DAT_18001bae8 = _DAT_18001c3c8;
      uRam000000018001baf0 = uRam000000018001c3d0;
      _DAT_18001baf8 = _DAT_18001c3d8;
      uRam000000018001bb00 = uRam000000018001c3e0;
      _DAT_18001bb08 = _DAT_18001c3e8;
      uRam000000018001bb10 = uRam000000018001c3f0;
    }
  }
  else {
    iVar2 = -0x3ffffeb8;
  }
  return iVar2;
}



===== CrashdmpEarlyDumpSupported @ 180001a70 =====

undefined8 CrashdmpEarlyDumpSupported(longlong param_1)

{
  longlong *plVar1;
  int iVar2;
  longlong *plVar3;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  longlong *plVar4;
  undefined1 uVar5;
  
  plVar3 = (longlong *)(ulonglong)DAT_18001bd60;
  uVar5 = 0;
  if (((DAT_18001bd60 & 1) != 0) && (*(int *)(param_1 + 0x178) == 2)) {
    plVar1 = (longlong *)(param_1 + 0x1b8);
    plVar4 = (longlong *)*plVar1;
    if ((plVar4 != plVar1) && (plVar4 == (longlong *)*(longlong *)(param_1 + 0x1c0))) {
      plVar3 = (longlong *)(param_1 + 0x198);
      if (((longlong *)*plVar3 != plVar3) &&
         ((longlong *)*plVar3 == (longlong *)*(longlong *)(param_1 + 0x1a0))) {
        plVar3 = (longlong *)(param_1 + 0x1a8);
        if (((longlong *)*plVar3 != plVar3) &&
           ((longlong *)*plVar3 == *(longlong **)(param_1 + 0x1b0))) {
          for (; plVar4 != plVar1; plVar4 = (longlong *)*plVar4) {
            iVar2 = _wcsicmp((wchar_t *)plVar4[3],L"stornvme.sys");
            plVar3 = (longlong *)CONCAT44(extraout_var,iVar2);
            if (iVar2 == 0) {
LAB_180001b24:
              uVar5 = 1;
              break;
            }
            iVar2 = _wcsicmp((wchar_t *)plVar4[3],L"storahci.sys");
            plVar3 = (longlong *)CONCAT44(extraout_var_00,iVar2);
            if (iVar2 == 0) goto LAB_180001b24;
          }
        }
      }
    }
  }
  return CONCAT71((int7)((ulonglong)plVar3 >> 8),uVar5);
}



===== CrashdmpEnableEncryption @ 180001b50 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 CrashdmpEnableEncryption(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if ((*param_1 != 0x28) || (uVar1 = param_1[7], uVar1 == 0)) {
    return 0xc000000d;
  }
  if ((param_1[6] != 0x1000) || ((uVar1 & 0xfff) != 0)) {
    return 0xc00000bb;
  }
  if (DmpEncryptionContext == '\0') {
    DAT_18001b3b8 = ExAllocatePool2(0x40,uVar1,0x706d4443);
    if (DAT_18001b3b8 == 0) {
      return 0xc000009a;
    }
    _DAT_18001b390 = *(undefined8 *)param_1;
    DAT_18001b398 = *(undefined8 *)(param_1 + 2);
    CurrentSecureDumpHeaderSize = param_1[7];
    DAT_18001b3a0 = *(undefined8 *)(param_1 + 4);
    _DAT_18001b3a8 = *(undefined8 *)(param_1 + 6);
    uVar2 = (undefined4)*(undefined8 *)(param_1 + 8);
    uVar3 = (undefined4)((ulonglong)*(undefined8 *)(param_1 + 8) >> 0x20);
    DmpEncryptionContext = '\x01';
  }
  else {
    if (uVar1 != CurrentSecureDumpHeaderSize) {
      if (DAT_18001b3b8 != 0) {
        ExFreePoolWithTag(DAT_18001b3b8,0);
      }
      DAT_18001b3b8 = ExAllocatePool2(0x40,param_1[7],0x706d4443);
      if (DAT_18001b3b8 == 0) {
        DAT_18001b3b8 = 0;
        CurrentSecureDumpHeaderSize = 0;
        return 0xc000009a;
      }
      CurrentSecureDumpHeaderSize = param_1[7];
    }
    _DAT_18001b390 = *(undefined8 *)param_1;
    DAT_18001b398 = *(undefined8 *)(param_1 + 2);
    DAT_18001b3a0 = *(undefined8 *)(param_1 + 4);
    _DAT_18001b3a8 = *(undefined8 *)(param_1 + 6);
    uVar2 = (undefined4)*(undefined8 *)(param_1 + 8);
    uVar3 = (undefined4)((ulonglong)*(undefined8 *)(param_1 + 8) >> 0x20);
  }
  _DAT_18001b3b0 = CONCAT44(uVar3,uVar2);
  return 0;
}



===== CrashdmpFreeDumpStack @ 180001c90 =====

int CrashdmpFreeDumpStack(longlong param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x170);
  if (((iVar1 == 2) || ((DAT_18001bd60 & 4) == 0)) && (*(int *)(param_1 + 0x178) != 2)) {
    SendFreeDumpPointers
              (*(undefined8 *)(param_1 + 0x278),*(undefined8 *)(param_1 + 0x110),
               *(uint *)(param_1 + 0x11c));
  }
  iVar2 = SendUsageNotification(param_1,'\0',0);
  if (*(longlong *)(param_1 + 0x168) != 0) {
    ObfDereferenceObject();
  }
  FreePortResources(param_1,0x18001bd00);
  if (iVar1 == 2) {
    DAT_18001c528 = 0;
    DAT_18001bc48 = 0;
  }
  return iVar2;
}



===== CrashdmpGetTransferSizes @ 180001d40 =====

void CrashdmpGetTransferSizes(int *param_1,undefined4 *param_2)

{
  ulonglong uVar1;
  int iVar2;
  longlong lVar3;
  
  uVar1 = 0x10000;
  lVar3 = DAT_18001bd40;
  if (DAT_18001c528 != '\0') {
    lVar3 = DAT_18001c520;
  }
  if (lVar3 != 0) {
    uVar1 = 0x10000;
    if (*(uint *)(lVar3 + 0x2d4) != 0) {
      uVar1 = (ulonglong)*(uint *)(lVar3 + 0x2d4);
    }
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = (int)uVar1;
  }
  iVar2 = 0x1000;
  if (lVar3 != 0) {
    iVar2 = 0x1000;
    if (*(int *)(lVar3 + 0x2d0) != 0) {
      iVar2 = *(int *)(lVar3 + 0x2d0);
    }
  }
  if (param_1 != (int *)0x0) {
    *param_1 = iVar2;
  }
  if ((Microsoft_Windows_CrashdumpEnableBits & 1) != 0) {
    McTemplateK0qq_EtwWriteTransfer(param_1,&EventTransferSizes,uVar1,iVar2,(char)uVar1);
  }
  return;
}



===== CrashdmpInitDumpStack @ 180001dc0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong CrashdmpInitDumpStack
                    (undefined8 *param_1,undefined8 param_2,undefined8 *param_3,undefined8 *param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  char *pcVar5;
  undefined1 auStackY_e8 [32];
  undefined8 *in_stack_ffffffffffffff38;
  undefined8 in_stack_ffffffffffffff40;
  undefined8 in_stack_ffffffffffffff48;
  uint local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_58 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_50 = 0;
  uStack_48 = 0;
  if ((*(int *)(param_1 + 0x2e) == 2) && (uVar3 = CheckContextIntegrity(), (int)uVar3 < 0)) {
    return uVar3;
  }
  MarkHiberBootPhase((longlong)param_1);
  puVar4 = param_1;
  FilterCallback(1,param_1,param_3,param_4,in_stack_ffffffffffffff38,in_stack_ffffffffffffff40,
                 in_stack_ffffffffffffff48);
  if (DAT_18001c528 == '\0') {
    if ((((DAT_18001c33c >> 0x11 & 1) == 0) && ((DAT_18001c33c >> 0x12 & 1) == 0)) &&
       ((DAT_18001c33c >> 0x17 & 1) == 0)) {
      puVar4 = (undefined8 *)&DAT_18001c33c;
      DAT_18001c33c = DAT_18001c33c & 0xfffffe41 | 0x41;
      param_3 = (undefined8 *)0x4;
      CrashdmpTelemetrySaveEnvironmentVariable(L"BugCheckProgress",&DAT_18001c33c,4);
      WriteLogProgress(DAT_18001c33c,puVar4,param_3,param_4);
      if (DAT_18001c528 != '\0') goto LAB_180001ed0;
    }
    if ((DAT_18001bd60 & 4) == 0) goto LAB_180001ed0;
    local_68 = InitializeDumpPath(&DAT_18001bd40);
    if ((int)local_68 < 0) {
LAB_180001ec8:
      _DAT_18001c438 = 0x3002;
      goto LAB_180001f0d;
    }
    if (DAT_18001c444 == 0x3002) {
      local_68 = 0xc0000001;
      goto LAB_180001ec8;
    }
LAB_180001f56:
    _DAT_18001c54c = 0;
    if (((DAT_18001c52b == '\x01') && (param_1[0x58] != 0)) &&
       (*(char *)((longlong)param_1 + 0x69) == '\0')) {
      ClearLogFile((longlong)param_1);
      puVar1 = (undefined4 *)param_1[0x58];
      *(undefined8 *)(puVar1 + 6) = 0;
      *puVar1 = 0x474f4c44;
      puVar1[1] = 0x454c4946;
      puVar1[2] = 0x31303030;
      puVar1[3] = 0x30303030;
      uVar2 = 0x504d5544;
      if (param_1 == DAT_18001c520) {
        uVar2 = 0x52424948;
      }
      puVar1[4] = uVar2;
      puVar1[5] = *(undefined4 *)((longlong)param_1 + 0x294);
      *(undefined4 *)(param_1 + 0x56) = 0x20;
      *(undefined4 *)(param_1 + 0x53) = 0x20;
      local_60 = _DAT_fffff78000000014;
      RtlTimeToTimeFields(&local_60,&local_40);
      ExSystemTimeToLocalTime(&local_60,&local_58);
      RtlTimeToTimeFields(&local_58,&local_50);
      pcVar5 = "Hiber";
      if (DAT_18001c528 == '\0') {
        pcVar5 = "Dump";
      }
      WriteLogString((longlong)param_1,
                     "\r\n%s stack initialized at UTC: %04d/%02d/%02d %02d:%02d:%02d, local time: %04d/%02d/%02d %02d:%02d:%02d.\r\n"
                     ,pcVar5,(ulonglong)(uint)(int)(short)local_40);
      if (DAT_18001c528 == '\0') {
        WriteLogString((longlong)param_1,
                       "#BugCheckCode 0x%p\r\n#BugCheckP1 0x%p\r\n#BugCheckP2 0x%p\r\n#BugCheckP3 0x%p\r\n#BugCheckP4 0x%p\r\n"
                       ,*(undefined8 *)KiBugCheckData_exref,
                       *(undefined8 *)(KiBugCheckData_exref + 8));
      }
    }
  }
  else {
LAB_180001ed0:
    if (*(int *)(param_1 + 0x2f) == 2) {
      local_68 = StartDumpDrivers((longlong)param_1,puVar4,param_3,param_4);
    }
    else {
      local_68 = InitializeDumpDriver((longlong)param_1);
    }
    if (-1 < (int)local_68) {
      if (DAT_18001c444 != 0x3001) goto LAB_180001f56;
      local_68 = 0xc0000001;
    }
    _DAT_18001c438 = 0x3001;
  }
LAB_180001f0d:
  memcpy(&ContextCopy,&Context,0x8d0);
  return (ulonglong)local_68;
}



===== CrashdmpInitialize @ 180002110 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong CrashdmpInitialize(wchar_t *param_1,undefined8 *param_2,wchar_t *param_3,char *param_4)

{
  undefined4 uVar1;
  bool bVar2;
  char cVar3;
  wchar_t wVar4;
  uint uVar5;
  int iVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  longlong lVar9;
  short *psVar10;
  uint uVar11;
  undefined8 *puVar12;
  wchar_t *pwVar13;
  uint uVar14;
  code *pcVar15;
  uint uVar16;
  undefined1 uVar17;
  wchar_t *pwVar18;
  wchar_t *pwVar19;
  undefined1 auStackY_118 [32];
  undefined1 local_e8;
  undefined1 local_e7 [3];
  undefined1 local_e4 [8];
  int local_dc;
  wchar_t *local_d8;
  undefined8 *local_d0;
  undefined8 local_c8 [4];
  undefined8 **local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  wchar_t local_58 [12];
  ulonglong local_40;
  
  uVar14 = DAT_18001c55c;
  local_40 = __security_cookie ^ (ulonglong)auStackY_118;
  local_58[8] = L'\0';
  local_58[9] = L'\0';
  local_58[10] = 0;
  pwVar19 = (wchar_t *)0x0;
  uVar16 = 0;
  DAT_18001c360 = 0x706d7544;
  local_e4._0_4_ = 0;
  _DAT_18001ba80 = 0x706d7544;
  local_d8 = (wchar_t *)0x0;
  local_58[0] = L'\0';
  local_58[1] = L'\0';
  local_58[2] = L'\0';
  local_58[3] = L'\0';
  local_58[4] = L'\0';
  local_58[5] = L'\0';
  local_58[6] = L'\0';
  local_58[7] = L'\0';
  pwVar18 = param_3;
  local_d0 = param_2;
  uVar7 = CheckContextIntegrity();
  if ((int)uVar7 < 0) {
    return uVar7;
  }
  pcVar15 = (code *)CONCAT71((int7)((ulonglong)param_2 >> 8),1);
  uVar7 = SetChangeState('\x01','\x01');
  if ((int)uVar7 < 0) {
    return uVar7;
  }
  uVar5 = CrashdmpKsrInitialize(0x18001bd40);
  uVar11 = 0x100c;
  if ((int)uVar5 < 0) {
LAB_1800021bb:
  }
  else {
    if (DAT_18001c444 == 0x100c) {
      uVar5 = 0xc0000001;
      goto LAB_1800021bb;
    }
    DAT_18001bd60 = DAT_18001bd60 & 0xfffffeff;
    GetBootDeviceObject(DAT_18001bd00);
    CrashdmpRegisterEtw();
    CrashdmpRegisterTraceLogging();
    if (DAT_18001c588 != '\0') {
      param_4 = (char *)(ulonglong)uVar14;
      pwVar18 = L"0x%08X";
      pcVar15 = (code *)0xb;
      pwVar13 = local_58;
      iVar6 = swprintf_s(pwVar13,0xb,L"0x%08X");
      if (iVar6 == 10) {
        param_4 = (char *)(ulonglong)uVar14;
        pwVar18 = (wchar_t *)0xc0000001;
        pcVar15 = (code *)0xc00400a1;
        CrashdmpWriteErrorLog(pwVar13,0xc00400a1,0xc0000001,uVar14,local_58,0x16);
        _DAT_18001c588 = 0x100;
      }
    }
    puVar12 = &DAT_18001bd40;
    uVar5 = ReadRegistrySettings(0x18001bd40);
    if (5 < DAT_18001b048) {
      pcVar15 = (code *)0x400000000000;
      uVar7 = _tlgKeywordOn(puVar12,0x400000000000);
      if ((char)uVar7 != '\0') {
        pcVar15 = (code *)&DAT_180018f67;
        local_e4._4_4_ = DAT_18001bd58;
        local_a8 = (undefined8 **)(local_e4 + 4);
        local_a0 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(puVar12,&DAT_180018f67,pwVar18,param_4,3,local_c8);
      }
    }
    uVar11 = 0x1001;
    if (-1 < (int)uVar5) {
      uVar11 = 0x1001;
      if (DAT_18001c444 != 0x1001) {
        pcVar15 = (code *)&DAT_18001bd00;
        uVar8 = InitDumpContext(0x18001bd40,0x18001bd00,param_1);
        uVar5 = (uint)uVar8;
        uVar11 = 0x1002;
        pwVar18 = param_1;
        if ((int)uVar5 < 0) goto LAB_1800021be;
        uVar11 = 0x1002;
        if (DAT_18001c444 != 0x1002) {
          if ((DAT_18001bd60 & 0x10000) == 0) {
            uVar8 = InitDedicatedDumpDevice(0x18001bd40);
            uVar5 = (uint)uVar8;
            uVar11 = 0x100a;
            pwVar18 = param_1;
            if ((int)uVar5 < 0) goto LAB_1800021be;
            uVar11 = 0x100a;
            if (DAT_18001c444 == 0x100a) goto LAB_180002372;
            if ((DAT_18001bd60 & 0x200) == 0) {
              uVar5 = InitDedicatedDump(0x18001bd40);
              bVar2 = IsDedicatedDumpFileStorageReserveEnabled();
              if (bVar2) {
                uVar11 = 0x100b;
              }
              else {
                uVar11 = 0x1003;
              }
              pwVar18 = param_1;
              if ((int)uVar5 < 0) goto LAB_1800021be;
              if (DAT_18001c444 == uVar11) goto LAB_180002372;
            }
            if (DAT_18001bd48 == (undefined8 *)0x0) {
              uVar16 = 0x1009;
              uVar5 = 0xc000000f;
              goto LAB_1800021c0;
            }
          }
          InitDumpPromotionSettings(0x18001bd40);
          uVar5 = GetDumpFileDiskRuns(0x18001bd40);
          if ((((DAT_18001c318 & 2) != 0) && (DAT_18001bd58 == 6)) && (DAT_18001bdc8 != 0)) {
            _DAT_18001c350 = DAT_18001bd50 - *(longlong *)(DAT_18001bda0 + 0x2020);
            if (DmpEncryptionContext != '\0') {
              _DAT_18001c350 = _DAT_18001c350 - DAT_18001b3ac;
            }
            _DAT_18001c350 = _DAT_18001c350 >> 0xc;
          }
          uVar11 = 0x1004;
          if ((int)uVar5 < 0) goto LAB_1800021be;
          if (DAT_18001c444 != 0x1004) {
            memcpy(&ContextCopy,&Context,0x8d0);
            pcVar15 = (code *)&local_d8;
            param_4 = (char *)0x0;
            pwVar18 = (wchar_t *)0x3;
            uVar7 = CrashdmpLoadDumpStack
                              (L"dump_",(undefined8 *)pcVar15,3,(undefined8 *)0x0,DAT_18001bd48);
            pwVar19 = local_d8;
            uVar5 = (uint)uVar7;
            if (-1 < (int)uVar5) {
              if (DAT_18001c444 != 0x1008) {
                DAT_18001bd40 = local_d8;
                *(undefined1 *)(local_d8 + 0x34) = 1;
                if (*(int *)(DAT_18001bd40 + 0xbc) != 2) {
                  pcVar15 = (code *)0x10000;
                  pwVar18 = (wchar_t *)0x706d4443;
                  lVar9 = ExAllocatePool2();
                  *(longlong *)(pwVar19 + 4) = lVar9;
                  if (lVar9 != 0) {
                    if (DAT_18001c444 != 0x1005) goto LAB_1800024f6;
                    pcVar15 = (code *)0x0;
                    ExFreePoolWithTag(lVar9);
                    pwVar19[4] = L'\0';
                    pwVar19[5] = L'\0';
                    pwVar19[6] = L'\0';
                    pwVar19[7] = L'\0';
                  }
                  uVar5 = 0xc000009a;
                  uVar16 = 0x1005;
                  goto LAB_1800021c0;
                }
LAB_1800024f6:
                pcVar15 = (code *)local_e4;
                CrashdmpGetTransferSizes((int *)0x0,(undefined4 *)pcVar15);
                uVar1 = local_e4._0_4_;
                if ((DAT_18001bd60 & 0x20) != 0) {
                  if (*(int *)(pwVar19 + 0xbc) == 1) {
                    if (2 < *(uint *)(pwVar19 + 0xc0)) {
                      if ((*(uint *)(pwVar19 + 0xd8) & 2) == 0) goto LAB_180002535;
                      goto LAB_18000254b;
                    }
                  }
                  else {
LAB_180002535:
                    if ((*(int *)(pwVar19 + 0xbc) == 2) &&
                       (*(char *)((longlong)pwVar19 + 0x231) != '\0')) {
LAB_18000254b:
                      if (local_e4._0_4_ != 0) {
                        DAT_18001c470 = 0;
                        pwVar18 = (wchar_t *)0x706d4443;
                        pcVar15 = (code *)(ulonglong)(uint)local_e4._0_4_;
                        DAT_18001c448 = (void *)ExAllocatePool2(0x40);
                        if (DAT_18001c448 != (void *)0x0) {
                          memset(DAT_18001c448,0,(ulonglong)(uint)uVar1);
                          pcVar15 = (code *)0x30;
                          DAT_18001c484 = uVar1;
                          pwVar18 = (wchar_t *)0x706d4443;
                          DAT_18001c408 = ExAllocatePool2(0x40);
                          if (DAT_18001c408 != 0) {
                            *(undefined1 *)(DAT_18001c408 + 0x2c) = 0;
                            param_4 = StrCrashdump;
                            pwVar18 = (wchar_t *)0x2;
                            pcVar15 = CrashdmpDriveTelemetryCallback;
                            cVar3 = KeRegisterBugCheckReasonCallback(DAT_18001c408);
                            if (cVar3 == '\0') {
                              if (DAT_18001c408 != 0) {
                                pcVar15 = (code *)0x0;
                                ExFreePoolWithTag();
                              }
                              DAT_18001c408 = 0;
                            }
                          }
                        }
                      }
                    }
                  }
                }
                uVar7 = 0;
                if (*(int *)(pwVar19 + 0xbc) != 2) {
                  uVar8 = InitMpioDevice((longlong *)&DAT_18001bd40);
                  uVar5 = (uint)uVar8;
                  uVar11 = 0x1006;
                  if ((int)uVar5 < 0) goto LAB_1800021be;
                  if (DAT_18001c444 == 0x1006) goto LAB_180002372;
                }
                _DAT_18001c340 = (uint)DAT_18001c570;
                DAT_18001bcf4 = 1;
                *local_d0 = &DAT_18001bdc0;
                if ((DAT_18001bd60 & 1) == 0) {
                  param_4 = *(char **)(param_3 + 4);
                  wVar4 = *param_3;
                }
                else {
                  param_4 = (char *)DAT_18001bd70;
                  wVar4 = DAT_18001bd68;
                }
                if (((short *)param_4 == (short *)0x0) || (wVar4 == L'\0')) {
LAB_180002707:
                  InitDumpLogFile((longlong *)&DAT_18001bd40);
                  if ((DAT_18001c548 & 1) != 0) {
                    pwVar18 = (wchar_t *)0x706d4443;
                    pcVar15 = (code *)(ulonglong)*(uint *)(DAT_18001bd40 + 0x16a);
                    DAT_18001c538 = ExAllocatePool2(0x40);
                  }
                }
                else {
                  pwVar18 = (wchar_t *)0x8;
                  if (8 < (ushort)wVar4) {
                    wVar4 = L'\b';
                  }
                  uVar14 = (uint)(ushort)wVar4;
                  pcVar15 = (code *)(ulonglong)uVar14;
                  if (uVar14 != 0) {
                    psVar10 = (short *)param_4;
                    do {
                      if (*psVar10 == 0x3a) break;
                      uVar11 = (int)uVar7 + 1;
                      uVar7 = (ulonglong)uVar11;
                      psVar10 = psVar10 + 1;
                    } while (uVar11 < uVar14);
                  }
                  if ((uint)uVar7 < uVar14) {
                    if (uVar7 < 0x7fffffff) {
                      pcVar15 = (code *)0x8;
                      uVar5 = RtlStringCopyWorkerW
                                        ((short *)&DAT_18001c474,8,8,(longlong)param_4,uVar7);
                      if (-1 < (int)uVar5) goto LAB_180002707;
                    }
                    else {
                      _DAT_18001c474 = 0;
                    }
                    uVar5 = 0;
                  }
                  DAT_18001c52b = 0;
                }
                goto LAB_1800021c0;
              }
              DAT_18001bd40 = local_d8;
              uVar5 = 0xc0000001;
            }
            _DAT_18001c438 = 0x1008;
            goto LAB_1800021c0;
          }
        }
      }
LAB_180002372:
      uVar5 = 0xc0000001;
    }
  }
LAB_1800021be:
  uVar16 = uVar11;
LAB_1800021c0:
  local_dc = 0;
  CrashdmpTelemetrySaveLastCrashdumpInfoAndSettings(0x18001bd40);
  if ((DAT_18001bd60 >> 0x1a & 1) == 0) {
    uVar17 = 0;
    if ((DAT_18001bd60 >> 0x1b & 1) != 0) {
      uVar17 = 2;
    }
  }
  else {
    uVar17 = 1;
  }
  pwVar13 = DAT_18001c4f0;
  if (DAT_18001c4f0 != (wchar_t *)0x0) {
    MmFreePagesFromMdl();
    pwVar13 = DAT_18001c4f0;
    if (DAT_18001c4f0 != (wchar_t *)0x0) {
      pcVar15 = (code *)0x0;
      ExFreePoolWithTag();
      pwVar13 = DAT_18001c4f0;
    }
    DAT_18001c4f0 = (wchar_t *)0x0;
  }
  if ((int)uVar5 < 0) {
    if (((DAT_18001bd60 & 0x10000) != 0) && ((Microsoft_Windows_CrashdumpEnableBits & 8) != 0)) {
      param_4 = (char *)(ulonglong)uVar5;
      McTemplateK0q_EtwWriteTransfer(pwVar13,pcVar15,pwVar18,uVar5);
    }
    if (uVar16 == 0x1009) {
      param_4 = (char *)0x0;
      pwVar18 = (wchar_t *)&local_dc;
      pwVar13 = L"\\Registry\\Machine\\System\\Setup";
      ReadRegULongKey(L"\\Registry\\Machine\\System\\Setup",L"SystemSetupInProgress",pwVar18,0);
    }
    if (local_dc != 1) {
      if ((5 < DAT_18001b048) &&
         (uVar7 = _tlgKeywordOn(pwVar13,0x800000000000), (char)uVar7 != '\0')) {
        local_a8 = (undefined8 **)(local_e4 + 4);
        local_98 = local_e4;
        local_a0 = 4;
        local_88 = &local_e8;
        local_90 = 4;
        local_80 = 1;
        local_e8 = uVar17;
        local_e4._0_4_ = uVar16;
        local_e4._4_4_ = uVar5;
        _tlgWriteTransfer_EtwWriteTransfer(pwVar13,&DAT_180018f11,pwVar18,param_4,5,local_c8);
      }
      if (uVar16 != 0) {
        param_4 = (char *)(ulonglong)uVar16;
        pwVar18 = (wchar_t *)(ulonglong)uVar5;
        CrashdmpWriteErrorLog(pwVar13,0xc004002e,uVar5,uVar16,(void *)0x0,0);
        _DAT_18001c438 = uVar16;
      }
    }
    FreeCrashdmpResources(0x18001bd40);
    if (((pwVar19 != (wchar_t *)0x0) && (*(int *)(DAT_18001bd40 + 0xbc) != 2)) &&
       (*(longlong *)(pwVar19 + 4) != 0)) {
      ExFreePoolWithTag(*(longlong *)(pwVar19 + 4),0);
      pwVar19[4] = L'\0';
      pwVar19[5] = L'\0';
      pwVar19[6] = L'\0';
      pwVar19[7] = L'\0';
    }
    if (DAT_18001c448 != (void *)0x0) {
      ExFreePoolWithTag(DAT_18001c448,0);
      DAT_18001c448 = (void *)0x0;
    }
    _DAT_18001c2f0 = 0;
    DAT_18001bdc8 = 0;
    pwVar13 = DAT_18001bd40;
    FreePortResources((longlong)DAT_18001bd40,0x18001bd00);
  }
  else if ((DAT_18001bd60 & 0x10000) == 0) {
    if (DAT_18001c52e != '\0') {
      pwVar13 = (wchar_t *)&DAT_18001bd40;
      CrashdmpKsrRegister(0x18001bd40);
    }
  }
  else if ((Microsoft_Windows_CrashdumpEnableBits & 0x10) != 0) {
    McTemplateK0_EtwWriteTransfer(pwVar13,&EarlyDumpInitialized,pwVar18);
  }
  if ((5 < DAT_18001b048) && (uVar7 = _tlgKeywordOn(pwVar13,0x400000000000), (char)uVar7 != '\0')) {
    local_e8 = local_dc == 1;
    local_a8 = &local_d0;
    local_98 = local_e4 + 4;
    local_d0 = (undefined8 *)0x1000000;
    local_88 = local_e4;
    local_a0 = 8;
    local_78 = &local_e8;
    local_68 = local_e7;
    local_90 = 4;
    local_80 = 4;
    local_70 = 1;
    local_60 = 1;
    local_e7[0] = uVar17;
    local_e4._0_4_ = uVar16;
    local_e4._4_4_ = uVar5;
    _tlgWriteTransfer_EtwWriteTransfer(pwVar13,&DAT_180018f9b,pwVar18,param_4,7,local_c8);
  }
  SetChangeState('\x01','\0');
  memcpy(&ContextCopy,&Context,0x8d0);
  return (ulonglong)uVar5;
}



===== CrashdmpKsrCancel @ 180002a44 =====

void CrashdmpKsrCancel(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x7a8) != 0) {
    KsrFreePersistedMemoryBlock(&CRASHDMP_KSR_GUID,*(longlong *)(param_1 + 0x7a8),1);
    *(undefined8 *)(param_1 + 0x7a8) = 0;
  }
  return;
}



===== CrashdmpKsrInitialize @ 180002a84 =====

int CrashdmpKsrInitialize(longlong param_1)

{
  ushort *puVar1;
  undefined8 uVar2;
  char cVar3;
  int iVar4;
  undefined8 *puVar5;
  longlong lVar6;
  ulonglong uVar7;
  int *piVar8;
  uint uVar9;
  undefined8 *puVar10;
  uint uVar11;
  ulonglong *puVar12;
  ulonglong uVar13;
  uint local_res10 [4];
  longlong local_res20;
  uint *puVar14;
  undefined4 uVar15;
  
  local_res10[0] = 0;
  local_res20 = 0;
  if (DAT_18001c52e == '\0') {
    return 0;
  }
  cVar3 = ExIsSoftBoot();
  if (cVar3 == '\0') {
    return 0;
  }
  if ((*(uint *)(param_1 + 0x20) & 0x10000) != 0) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffeffff;
    return 0;
  }
  iVar4 = KsrEnumeratePersistedMemory(&CRASHDMP_KSR_GUID,CrashdmpKsrMemoryEnumerate,&local_res20);
  if (iVar4 < 0) goto LAB_180002d0a;
  if (local_res20 == 0) {
    return iVar4;
  }
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x10000;
  iVar4 = KsrClaimPersistedMemory(&CRASHDMP_KSR_GUID,local_res20,0,0,0,local_res10);
  if (iVar4 != -0x3fffffdd) {
    if (-1 < iVar4) {
      iVar4 = -0x3ffffff3;
    }
    goto LAB_180002d0a;
  }
  puVar5 = (undefined8 *)ExAllocatePool2(0x40,(ulonglong)local_res10[0] << 3,0x706d4443);
  if (puVar5 == (undefined8 *)0x0) {
    iVar4 = -0x3fffff66;
    goto LAB_180002d0a;
  }
  puVar14 = local_res10;
  iVar4 = KsrClaimPersistedMemory(&CRASHDMP_KSR_GUID,local_res20,puVar5,local_res10[0],0,puVar14);
  uVar15 = (undefined4)((ulonglong)puVar14 >> 0x20);
  if (-1 < iVar4) {
    uVar11 = 0;
    if (local_res10[0] != 0) {
      uVar13 = (ulonglong)local_res10[0];
      puVar10 = puVar5;
      do {
        uVar2 = *puVar10;
        puVar10 = puVar10 + 1;
        uVar11 = uVar11 + (uint)((ulonglong)uVar2 >> 0x28);
        uVar13 = uVar13 - 1;
      } while (uVar13 != 0);
    }
    lVar6 = ExAllocatePool2(0x40,(ulonglong)uVar11 * 8 + 0x30,0x706d4443);
    *(longlong *)(param_1 + 0x7b0) = lVar6;
    if (lVar6 != 0) {
      KsrFreePersistedMemoryBlock(&CRASHDMP_KSR_GUID,local_res20,0);
      puVar10 = *(undefined8 **)(param_1 + 0x7b0);
      uVar9 = 0;
      *puVar10 = 0;
      *(undefined2 *)((longlong)puVar10 + 10) = 0;
      puVar10[4] = 0;
      *(undefined4 *)((longlong)puVar10 + 0x2c) = 0;
      *(uint *)(puVar10 + 5) = uVar11 << 0xc;
      *(short *)(puVar10 + 1) = ((short)uVar11 + 6) * 8;
      puVar1 = (ushort *)(*(longlong *)(param_1 + 0x7b0) + 10);
      *puVar1 = *puVar1 | 2;
      puVar12 = (ulonglong *)(*(longlong *)(param_1 + 0x7b0) + 0x30);
      if (local_res10[0] != 0) {
        do {
          uVar13 = puVar5[uVar9];
          uVar7 = uVar13 & 0xffffffffff;
          if ((uint)(uVar13 >> 0x28) != 0) {
            uVar13 = uVar13 >> 0x28;
            do {
              *puVar12 = uVar7;
              puVar12 = puVar12 + 1;
              uVar7 = uVar7 + 1;
              uVar13 = uVar13 - 1;
            } while (uVar13 != 0);
          }
          uVar9 = uVar9 + 1;
        } while (uVar9 < local_res10[0]);
      }
      piVar8 = (int *)MmMapLockedPagesSpecifyCache
                                (*(undefined8 *)(param_1 + 0x7b0),0,1,0,0,
                                 CONCAT44(uVar15,0x40000010));
      if (piVar8 != (int *)0x0) {
        if (*piVar8 != 1) {
          iVar4 = -0x3fffff45;
        }
        goto LAB_180002cf5;
      }
    }
    iVar4 = -0x3fffff66;
  }
LAB_180002cf5:
  ExFreePoolWithTag(puVar5,0);
  if (-1 < iVar4) {
    return iVar4;
  }
LAB_180002d0a:
  KsrFreePersistedMemory(&CRASHDMP_KSR_GUID,1);
  return iVar4;
}



===== CrashdmpKsrMemoryEnumerate @ 180002d40 =====

undefined8 CrashdmpKsrMemoryEnumerate(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  *param_3 = param_2;
  return 0;
}



===== CrashdmpKsrNotifyCallbackRoutine @ 180002d50 =====

void CrashdmpKsrNotifyCallbackRoutine(longlong *param_1,int param_2,int *param_3)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = CrashdmpKsrPrepare(param_1);
    if ((iVar1 < 0) && (-1 < *param_3)) {
      *param_3 = iVar1;
      param_3[2] = 0x70647243;
    }
  }
  else if ((param_2 == 1) || ((param_2 == 5 && ((param_3[3] & 1U) == 0)))) {
    CrashdmpKsrCancel((longlong)param_1);
  }
  return;
}



===== CrashdmpKsrPrepare @ 180002d9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int CrashdmpKsrPrepare(longlong *param_1)

{
  longlong lVar1;
  uint uVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined4 *puVar5;
  longlong lVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  uint uVar10;
  int iVar11;
  undefined8 *puVar12;
  int iVar13;
  undefined4 *puVar14;
  uint uVar15;
  uint local_res10 [2];
  ulonglong local_res18;
  undefined8 *local_res20;
  undefined8 local_d8;
  longlong lStack_d0;
  undefined8 local_c8;
  undefined8 *local_c0;
  longlong local_b8;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  int local_60;
  undefined4 uStack_5c;
  void *local_58;
  
  local_a8 = 0xffffffff;
  local_res10[0] = 0;
  local_a4 = 0;
  uStack_a0 = 0;
  uStack_9c = 0;
  uStack_98 = 0;
  uStack_94 = 0;
  memset(&local_90,0,0x40);
  if ((DAT_18001bcf4 != '\0') && ((*(uint *)(param_1 + 4) & 0x20004) == 0x20000)) {
    lVar1 = *param_1;
    puVar12 = &local_d8;
    iVar11 = (int)param_1[10] * 0x10;
    local_c8 = 0;
    lStack_d0 = 0;
    local_d8 = 0x18;
    local_res18 = CONCAT44(local_res18._4_4_,iVar11);
    iVar13 = (**(code **)(lVar1 + 0x208))(*(undefined8 *)(lVar1 + 400),9);
    if (iVar13 == -0x3fffffdd) {
      local_c0 = (undefined8 *)(lVar1 + 0x1b8);
      uVar15 = (local_c8._4_4_ + 7U & 0xfffffff8) + 0x90 + iVar11;
      for (puVar7 = (undefined8 *)*local_c0; puVar7 != local_c0; puVar7 = (undefined8 *)*puVar7) {
        iVar13 = 0x28;
        if (puVar7[5] != 0) {
          lVar4 = -1;
          do {
            lVar4 = lVar4 + 1;
          } while (*(short *)(puVar7[5] + lVar4 * 2) != 0);
          iVar13 = (int)lVar4 * 2 + 0x2a;
        }
        if (puVar7[6] != 0) {
          lVar4 = -1;
          do {
            lVar4 = lVar4 + 1;
          } while (*(short *)(puVar7[6] + lVar4 * 2) != 0);
          iVar13 = iVar13 + (int)lVar4 * 2 + 2;
        }
        if (puVar7[3] != 0) {
          lVar4 = -1;
          do {
            lVar4 = lVar4 + 1;
          } while (*(short *)(puVar7[3] + lVar4 * 2) != 0);
          iVar13 = iVar13 + (int)lVar4 * 2 + 2;
        }
        puVar12 = (undefined8 *)puVar7[4];
        if (puVar12 != (undefined8 *)0x0) {
          lVar4 = -1;
          do {
            lVar4 = lVar4 + 1;
          } while (*(short *)((longlong)puVar12 + lVar4 * 2) != 0);
          iVar13 = iVar13 + (int)lVar4 * 2 + 2;
        }
        uVar15 = uVar15 + (iVar13 + 7U & 0xfffffff8);
      }
      local_res20 = (undefined8 *)(lVar1 + 0x1a8);
      for (puVar7 = (undefined8 *)*local_res20; puVar7 != local_res20;
          puVar7 = (undefined8 *)*puVar7) {
        iVar13 = *(int *)((longlong)puVar7 + 0x24);
        iVar11 = (**(code **)(*(longlong *)(puVar7[7] + 8) + 0x80))(puVar7[7],&local_a8);
        if (iVar11 < 0) {
          uVar8 = 2;
          goto LAB_1800034d9;
        }
        uVar15 = uVar15 + (local_60 + 7U & 0xfffffff8) + 0x80 + (iVar13 + 7U & 0xfffffff8);
      }
      for (puVar12 = *(undefined8 **)(lVar1 + 0x198); puVar12 != (undefined8 *)(lVar1 + 0x198);
          puVar12 = (undefined8 *)*puVar12) {
        uVar15 = uVar15 + (*(int *)((longlong)puVar12 + 0x24) + 0x2fU & 0xfffffff8);
      }
      puVar12 = (undefined8 *)0x0;
      lVar4 = MmAllocatePagesForMdlEx
                        (0,0xffffffffffffffff,0,(ulonglong)uVar15 + 0xfff & 0xfffffffffffff000,1,
                         0x14);
      local_b8 = lVar4;
      if (lVar4 == 0) {
        iVar11 = -0x3fffff66;
        uVar8 = 3;
      }
      else {
        puVar12 = (undefined8 *)0x1;
        puVar5 = (undefined4 *)MmMapLockedPagesSpecifyCache(lVar4,0,1,0,0,0x40000020);
        if (puVar5 == (undefined4 *)0x0) {
          iVar11 = -0x3fffff66;
          uVar15 = 4;
        }
        else {
          KsrMdlToMemoryRuns(lVar4,0,0,local_res10);
          puVar12 = (undefined8 *)0x706d4443;
          lVar6 = ExAllocatePool2(0x40,(ulonglong)local_res10[0] << 3);
          if (lVar6 == 0) {
            iVar11 = -0x3fffff66;
            uVar15 = 5;
          }
          else {
            KsrMdlToMemoryRuns(lVar4,lVar6,local_res10[0],local_res10);
            *puVar5 = 1;
            puVar5[1] = uVar15;
            puVar5[2] = *(undefined4 *)(*param_1 + 0x178);
            *(longlong *)(puVar5 + 4) = param_1[2];
            puVar5[6] = (int)param_1[10];
            iVar13 = (int)local_res18;
            puVar5[8] = (*(uint *)(param_1 + 4) >> 0xe ^ puVar5[8]) & 1 ^ puVar5[8];
            *(undefined8 *)(puVar5 + 10) = *(undefined8 *)(*param_1 + 0x234);
            *(undefined8 *)(puVar5 + 0xc) = *(undefined8 *)(*param_1 + 0x108);
            lVar4 = *param_1;
            uVar3 = *(undefined8 *)(lVar4 + 0x248);
            *(undefined8 *)(puVar5 + 0xe) = *(undefined8 *)(lVar4 + 0x240);
            *(undefined8 *)(puVar5 + 0x10) = uVar3;
            uVar3 = *(undefined8 *)(lVar4 + 600);
            *(undefined8 *)(puVar5 + 0x12) = *(undefined8 *)(lVar4 + 0x250);
            *(undefined8 *)(puVar5 + 0x14) = uVar3;
            uVar3 = *(undefined8 *)(lVar4 + 0x268);
            *(undefined8 *)(puVar5 + 0x16) = *(undefined8 *)(lVar4 + 0x260);
            *(undefined8 *)(puVar5 + 0x18) = uVar3;
            *(undefined8 *)(puVar5 + 0x1a) = *(undefined8 *)(lVar4 + 0x270);
            puVar5[0x1d] = *(undefined4 *)(*param_1 + 0x2d4);
            puVar5[0x1c] = *(undefined4 *)(*param_1 + 0x2d0);
            puVar5[7] = 0x90;
            memcpy(puVar5 + 0x24,(void *)param_1[0xb],local_res18 & 0xffffffff);
            uVar15 = puVar5[7] + iVar13;
            puVar5[0x1e] = uVar15;
            puVar12 = (undefined8 *)*local_c0;
            if (puVar12 != local_c0) {
              do {
                puVar14 = (undefined4 *)((ulonglong)uVar15 + (longlong)puVar5);
                uVar10 = 0x28;
                *puVar14 = 0x28;
                puVar14[4] = *(undefined4 *)(puVar12 + 7);
                puVar14[5] = *(undefined4 *)((longlong)puVar12 + 0x3c);
                if (puVar12[5] != 0) {
                  puVar14[6] = 0x28;
                  lVar4 = -1;
                  do {
                    lVar4 = lVar4 + 1;
                  } while (*(short *)((longlong)puVar12[5] + lVar4 * 2) != 0);
                  uVar10 = (int)lVar4 * 2;
                  memcpy(puVar14 + 10,(void *)puVar12[5],(ulonglong)uVar10);
                  uVar10 = uVar10 + 0x2a;
                }
                if (puVar12[6] != 0) {
                  puVar14[7] = uVar10;
                  lVar4 = -1;
                  do {
                    lVar4 = lVar4 + 1;
                  } while (*(short *)((longlong)puVar12[6] + lVar4 * 2) != 0);
                  uVar2 = (int)lVar4 * 2;
                  local_res18 = (ulonglong)uVar2;
                  memcpy((void *)((ulonglong)uVar10 + (longlong)puVar14),(void *)puVar12[6],
                         (ulonglong)uVar2);
                  uVar10 = uVar10 + (int)local_res18 + 2;
                }
                if (puVar12[3] != 0) {
                  puVar14[8] = uVar10;
                  lVar4 = -1;
                  do {
                    lVar4 = lVar4 + 1;
                  } while (*(short *)((longlong)puVar12[3] + lVar4 * 2) != 0);
                  uVar2 = (int)lVar4 * 2;
                  local_res18 = (ulonglong)uVar2;
                  memcpy((void *)((ulonglong)uVar10 + (longlong)puVar14),(void *)puVar12[3],
                         (ulonglong)uVar2);
                  uVar10 = uVar10 + (int)local_res18 + 2;
                }
                if (puVar12[4] != 0) {
                  puVar14[9] = uVar10;
                  lVar4 = -1;
                  do {
                    lVar4 = lVar4 + 1;
                  } while (*(short *)((longlong)puVar12[4] + lVar4 * 2) != 0);
                  uVar2 = (int)lVar4 * 2;
                  local_res18 = (ulonglong)uVar2;
                  memcpy((void *)((ulonglong)uVar10 + (longlong)puVar14),(void *)puVar12[4],
                         (ulonglong)uVar2);
                  uVar10 = uVar10 + (int)local_res18 + 2;
                }
                puVar14[1] = uVar10;
                puVar12 = (undefined8 *)*puVar12;
                uVar15 = uVar15 + (uVar10 + 7 & 0xfffffff8);
              } while (puVar12 != local_c0);
            }
            puVar5[0x1f] = uVar15;
            for (puVar7 = (undefined8 *)*local_res20; puVar7 != local_res20;
                puVar7 = (undefined8 *)*puVar7) {
              puVar14 = (undefined4 *)((ulonglong)uVar15 + (longlong)puVar5);
              *puVar14 = 0x40;
              puVar14[4] = *(undefined4 *)(puVar7 + 4);
              uVar3 = puVar7[3];
              *(undefined8 *)(puVar14 + 5) = puVar7[2];
              *(undefined8 *)(puVar14 + 7) = uVar3;
              puVar14[9] = *(undefined4 *)(puVar7 + 8);
              iVar13 = *(int *)((longlong)puVar7 + 0x24);
              puVar14[10] = iVar13;
              puVar14[0xb] = 0x40;
              puVar12 = (undefined8 *)(ulonglong)*(uint *)((longlong)puVar7 + 0x24);
              uVar10 = iVar13 + 7U & 0xfffffff8;
              iVar13 = uVar10 + 0x40;
              local_res18 = CONCAT44(local_res18._4_4_,iVar13);
              memcpy(puVar14 + 0x10,(void *)puVar7[5],(size_t)puVar12);
              iVar11 = (**(code **)(*(longlong *)(puVar7[7] + 8) + 0x80))(puVar7[7],&local_a8);
              if (iVar11 < 0) {
                uVar15 = 6;
                goto LAB_180003480;
              }
              uVar8 = local_res18 & 0xffffffff;
              puVar14[0xc] = iVar13;
              uVar10 = uVar10 + 0x80;
              puVar14[0xd] = 0x40;
              uVar9 = (ulonglong)uVar10;
              *(undefined8 *)(uVar8 + (longlong)puVar14) = CONCAT44(uStack_9c,uStack_a0);
              ((undefined8 *)(uVar8 + (longlong)puVar14))[1] = CONCAT44(uStack_94,uStack_98);
              puVar12 = (undefined8 *)(uVar8 + 0x10 + (longlong)puVar14);
              *puVar12 = local_90;
              puVar12[1] = uStack_88;
              puVar12 = (undefined8 *)(uVar8 + 0x20 + (longlong)puVar14);
              *puVar12 = local_80;
              puVar12[1] = uStack_78;
              puVar12 = (undefined8 *)(uVar8 + 0x30 + (longlong)puVar14);
              *puVar12 = local_70;
              puVar12[1] = uStack_68;
              if (CONCAT44(uStack_5c,local_60) != 0) {
                puVar14[0xf] = local_60;
                puVar14[0xe] = uVar10;
                uVar10 = uVar10 + (local_60 + 7U & 0xfffffff8);
                memcpy((void *)(uVar9 + (longlong)puVar14),local_58,CONCAT44(uStack_5c,local_60));
              }
              uVar15 = uVar15 + uVar10;
              puVar14[1] = uVar10;
            }
            puVar5[0x20] = uVar15;
            for (puVar12 = *(undefined8 **)(lVar1 + 0x198); puVar12 != (undefined8 *)(lVar1 + 0x198)
                ; puVar12 = (undefined8 *)*puVar12) {
              puVar14 = (undefined4 *)((ulonglong)uVar15 + (longlong)puVar5);
              *puVar14 = 0x28;
              puVar14[3] = *(undefined4 *)(puVar12 + 4);
              uVar3 = puVar12[3];
              *(undefined8 *)(puVar14 + 4) = puVar12[2];
              *(undefined8 *)(puVar14 + 6) = uVar3;
              iVar13 = *(int *)((longlong)puVar12 + 0x24);
              puVar14[9] = 0x28;
              puVar14[8] = iVar13;
              iVar13 = (iVar13 + 7U & 0xfffffff8) + 0x28;
              memcpy(puVar14 + 10,(void *)puVar12[5],(ulonglong)*(uint *)((longlong)puVar12 + 0x24))
              ;
              puVar14[1] = iVar13;
              uVar15 = uVar15 + iVar13;
            }
            puVar12 = &local_d8;
            puVar5[0x21] = uVar15;
            puVar5[0x22] = local_c8._4_4_;
            lStack_d0 = (ulonglong)uVar15 + (longlong)puVar5;
            local_c8 = CONCAT44(local_c8._4_4_,local_c8._4_4_);
            iVar11 = (**(code **)(*param_1 + 0x208))(*(undefined8 *)(lVar1 + 400),9);
            if (iVar11 < 0) {
              uVar15 = 7;
            }
            else {
              puVar12 = (undefined8 *)(ulonglong)local_res10[0];
              iVar11 = KsrPersistMemory(&CRASHDMP_KSR_GUID,lVar6,puVar12,param_1 + 0xf5);
              uVar15 = 0;
              if (iVar11 < 0) {
                uVar15 = 8;
              }
            }
LAB_180003480:
            ExFreePoolWithTag(lVar6,0);
            lVar4 = local_b8;
          }
        }
        if ((*(byte *)(lVar4 + 10) & 1) != 0) {
          MmUnmapLockedPages(*(undefined8 *)(lVar4 + 0x18),lVar4);
        }
        if (iVar11 < 0) {
          MmFreePagesFromMdl(lVar4);
        }
        ExFreePoolWithTag(lVar4,0);
        uVar8 = (ulonglong)uVar15;
        if (-1 < iVar11) {
          return iVar11;
        }
      }
    }
    else {
      iVar11 = -0x3ffffdfa;
      uVar8 = 1;
    }
LAB_1800034d9:
    if ((Microsoft_Windows_CrashdumpEnableBits & 4) != 0) {
      McTemplateK0qq_EtwWriteTransfer(uVar8,&EarlyDumpPrepareFailure,puVar12,iVar11,(char)uVar8);
    }
  }
  return 0;
}



===== CrashdmpKsrRegister @ 180003514 =====

int CrashdmpKsrRegister(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  longlong local_res10;
  undefined8 local_48;
  wchar_t *local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_1c = 0;
  local_res10 = 0;
  local_30 = 0;
  local_40 = L"\\Callback\\SoftRestart";
  local_28 = &local_48;
  local_38 = 0x30;
  local_48 = 0x2c002a;
  local_20 = 0x240;
  local_18 = 0;
  uStack_10 = 0;
  iVar1 = ExCreateCallback(&local_res10,&local_38,0,0);
  if (-1 < iVar1) {
    lVar2 = ExRegisterCallback(local_res10,CrashdmpKsrNotifyCallbackRoutine,param_1);
    if (lVar2 == 0) {
      iVar1 = -0x3fffffff;
    }
    else {
      *(longlong *)(param_1 + 0x7a0) = lVar2;
    }
  }
  if (local_res10 != 0) {
    ObfDereferenceObject();
  }
  return iVar1;
}



===== CrashdmpLoadDumpStack @ 1800035f0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong CrashdmpLoadDumpStack
                    (undefined8 *param_1,undefined8 *param_2,int param_3,undefined8 *param_4,
                    undefined8 *param_5)

{
  bool bVar1;
  undefined8 *puVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 **ppuVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  undefined8 **ppuVar9;
  short *psVar10;
  undefined8 **ppuVar11;
  longlong lVar12;
  undefined8 uVar13;
  undefined4 uVar14;
  wchar_t *pwVar15;
  int iVar16;
  short *in_stack_ffffffffffffff58;
  undefined8 in_stack_ffffffffffffff60;
  int iVar17;
  undefined4 in_stack_ffffffffffffff6c;
  undefined8 local_90;
  undefined8 *local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  
  iVar16 = (int)param_4;
  local_88 = (undefined8 *)0x0;
  bVar1 = false;
  iVar17 = 0;
  uVar5 = CheckContextIntegrity();
  if ((int)uVar5 < 0) {
    return uVar5;
  }
  if (param_3 == 2) {
    DAT_18001c528 = '\x01';
    if (DAT_18001bcf4 == '\0') {
      GetBootDeviceObject(DAT_18001bd00);
    }
    if (DAT_18001c444 == 0) {
      param_4 = (undefined8 *)0x0;
      iVar3 = ReadRegULongKey(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl"
                              ,L"SimulateError",(longlong)register0x00000020 + -0x98,0);
      if (-1 < iVar3) {
        DAT_18001c444 = iVar17;
      }
    }
    if (DAT_18001c540 == 0) {
      param_4 = (undefined8 *)0xffffffff;
      iVar3 = ReadRegULongKey(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl"
                              ,L"ResumeCapable",(longlong)register0x00000020 + -0x98,0xffffffff);
      if ((iVar3 < 0) || (iVar17 == -1)) {
        DAT_18001c540 = 0xffffffff;
      }
      else {
        DAT_18001c540 = (uint)(iVar17 == 1);
      }
    }
  }
  uVar13 = 0x2e0;
  ppuVar11 = (undefined8 **)0x40;
  pwVar15 = (wchar_t *)0x706d4443;
  ppuVar6 = (undefined8 **)ExAllocatePool2();
  uVar14 = 0x2001;
  if (ppuVar6 == (undefined8 **)0x0) {
LAB_180003b67:
    uVar5 = 0xc000009a;
LAB_180003b6c:
    CrashdmpWriteErrorLog(ppuVar11,0xc004002d,(int)uVar5,uVar14,(void *)0x0,0);
    _DAT_18001c438 = uVar14;
  }
  else {
    if (DAT_18001c444 == 0x2001) {
      ExFreePoolWithTag(ppuVar6,0);
      ppuVar11 = ppuVar6;
      ppuVar6 = (undefined8 **)0x0;
      goto LAB_180003b67;
    }
    ppuVar11 = ppuVar6 + 0x50;
    ppuVar6[0x51] = ppuVar11;
    *ppuVar11 = ppuVar11;
    ppuVar11 = ppuVar6 + 0x25;
    ppuVar6[0x26] = ppuVar11;
    *ppuVar11 = ppuVar11;
    ppuVar6[0x24] = param_1;
    *(int *)(ppuVar6 + 0x2e) = param_3;
    if ((DAT_18001bd60 & 0x10000) == 0) {
      if (param_5 != (undefined8 *)0x0) {
LAB_180003805:
        in_stack_ffffffffffffff58 = (short *)&local_90;
        in_stack_ffffffffffffff60 = 0;
        param_4 = (undefined8 *)0x0;
        uVar13 = 0;
        local_90 = (undefined8 *)0x0;
        pwVar15 = *(wchar_t **)IoFileObjectType_exref;
        ObReferenceObjectByHandle();
        puVar2 = local_90;
        local_88 = local_90;
        puVar7 = (undefined8 *)IoGetAttachedDeviceReference(local_90[1]);
        ppuVar6[0x2d] = puVar2;
        ppuVar6[0x4f] = puVar7;
        if (bVar1) {
          ZwClose(param_5);
        }
        goto LAB_180003870;
      }
      local_70 = 0x30;
      local_58 = 0x200;
      local_60 = DAT_18001bd00;
      if (param_3 == 2) {
        local_60 = DAT_18001bd38;
      }
      ppuVar11 = &param_5;
      local_80 = 0;
      uStack_78 = 0;
      local_68 = 0;
      local_50 = 0;
      uStack_48 = 0;
      uVar4 = ZwOpenFile(ppuVar11,0x100180,&local_70,&local_80,3,0x40);
      uVar5 = (ulonglong)uVar4;
      uVar14 = 0x2002;
      if (-1 < (int)uVar4) {
        if (DAT_18001c444 != 0x2002) {
          bVar1 = true;
          goto LAB_180003805;
        }
        ppuVar11 = (undefined8 **)param_5;
        ZwClose();
        param_5 = (undefined8 *)0x0;
        uVar14 = 0x2002;
        goto LAB_1800037f9;
      }
      goto LAB_180003b6c;
    }
LAB_180003870:
    iVar3 = 0;
    ppuVar11 = ppuVar6;
    uVar8 = QueryPortDriver((undefined4 *)ppuVar6,uVar13,pwVar15,param_4);
    uVar5 = uVar8 & 0xffffffff;
    uVar14 = 0x2003;
    if ((int)uVar8 < 0) goto LAB_180003b6c;
    if (DAT_18001c444 == 0x2003) goto LAB_1800037f9;
    if ((((DAT_18001c52e == '\0') || (param_3 == 2)) || ((DAT_18001bd60 & 0x10000) != 0)) ||
       (uVar13 = CrashdmpEarlyDumpSupported((longlong)ppuVar6), (char)uVar13 == '\0')) {
LAB_180003ab4:
      ppuVar11 = ppuVar6;
      uVar8 = LoadPortDriver((longlong)ppuVar6,0x18001bd00);
      uVar5 = uVar8 & 0xffffffff;
      uVar14 = 0x2004;
      if (-1 < (int)uVar8) {
        if (DAT_18001c444 != 0x2004) {
          ppuVar11 = ppuVar6;
          uVar8 = LoadFilterDrivers((longlong)ppuVar6,0x18001bd00);
          uVar5 = uVar8 & 0xffffffff;
          uVar14 = 0x2005;
          if ((int)uVar8 < 0) goto LAB_180003b6c;
          if (DAT_18001c444 != 0x2005) {
            ppuVar11 = (undefined8 **)0x0;
            uVar4 = FilterCallback(0,ppuVar6,(undefined8 *)pwVar15,param_4,
                                   (undefined8 *)in_stack_ffffffffffffff58,in_stack_ffffffffffffff60
                                   ,CONCAT44(in_stack_ffffffffffffff6c,iVar17));
            uVar5 = (ulonglong)uVar4;
            uVar14 = 0x2006;
            if ((int)uVar4 < 0) goto LAB_180003b6c;
            if (DAT_18001c444 != 0x2006) {
              ppuVar11 = ppuVar6;
              uVar4 = SendUsageNotification((longlong)ppuVar6,'\x01',iVar16);
              uVar5 = (ulonglong)uVar4;
              uVar14 = 0x2007;
              if ((int)uVar4 < 0) goto LAB_180003b6c;
              if (DAT_18001c444 != 0x2007) {
                *param_2 = ppuVar6;
                if (param_3 == 2) {
                  DAT_18001c520 = ppuVar6;
                }
                goto LAB_180003c3c;
              }
            }
          }
        }
LAB_1800037f9:
        uVar5 = 0xc0000001;
      }
      goto LAB_180003b6c;
    }
    ppuVar11 = ppuVar6 + 0x37;
    ppuVar9 = (undefined8 **)*ppuVar11;
    if (ppuVar9 == ppuVar11) goto LAB_180003ab4;
    param_4 = (undefined8 *)0xffffffffffffffff;
    do {
      if (ppuVar9[5] != (undefined8 *)0x0) {
        lVar12 = -1;
        do {
          lVar12 = lVar12 + 1;
        } while (*(short *)((longlong)ppuVar9[5] + lVar12 * 2) != 0);
        iVar3 = iVar3 + 2 + (int)lVar12;
        if (ppuVar9[6] != (undefined8 *)0x0) {
          lVar12 = -1;
          do {
            lVar12 = lVar12 + 1;
          } while (*(short *)((longlong)ppuVar9[6] + lVar12 * 2) != 0);
          iVar3 = iVar3 + (int)lVar12;
        }
      }
      if (ppuVar9[3] != (undefined8 *)0x0) {
        lVar12 = -1;
        do {
          lVar12 = lVar12 + 1;
        } while (*(short *)((longlong)ppuVar9[3] + lVar12 * 2) != 0);
        iVar3 = iVar3 + 2 + (int)lVar12;
        if (ppuVar9[4] != (undefined8 *)0x0) {
          lVar12 = -1;
          do {
            lVar12 = lVar12 + 1;
          } while (*(short *)((longlong)ppuVar9[4] + lVar12 * 2) != 0);
          iVar3 = iVar3 + (int)lVar12;
        }
      }
      ppuVar9 = (undefined8 **)*ppuVar9;
    } while (ppuVar9 != ppuVar11);
    if (iVar3 == 0) goto LAB_180003ab4;
    uVar4 = iVar3 + 1;
    uVar5 = (ulonglong)uVar4;
    pwVar15 = (wchar_t *)0x706d4443;
    psVar10 = (short *)ExAllocatePool2(0x40,uVar5 * 2);
    if (psVar10 != (short *)0x0) {
      for (ppuVar9 = (undefined8 **)*ppuVar11; ppuVar9 != ppuVar11;
          ppuVar9 = (undefined8 **)*ppuVar9) {
        if (ppuVar9[5] != (undefined8 *)0x0) {
          RtlStringCchCatW(psVar10,uVar5,(longlong)ppuVar9[5]);
          RtlStringCchCatW(psVar10,uVar5,0x1800173dc);
          if (ppuVar9[6] != (undefined8 *)0x0) {
            RtlStringCchCatW(psVar10,uVar5,(longlong)ppuVar9[6]);
          }
          RtlStringCchCatW(psVar10,uVar5,0x1800173e0);
        }
        pwVar15 = (wchar_t *)0x0;
        if (ppuVar9[3] != (undefined8 *)0x0) {
          RtlStringCchCatW(psVar10,uVar5,(longlong)ppuVar9[3]);
          RtlStringCchCatW(psVar10,uVar5,0x1800173dc);
          if (ppuVar9[4] != (undefined8 *)0x0) {
            RtlStringCchCatW(psVar10,uVar5,(longlong)ppuVar9[4]);
          }
          pwVar15 = L";";
          RtlStringCchCatW(psVar10,uVar5,0x1800173e0);
        }
      }
      if (uVar4 != 0) {
        param_4 = (undefined8 *)0x1;
        in_stack_ffffffffffffff60 =
             CONCAT44((int)((ulonglong)in_stack_ffffffffffffff60 >> 0x20),uVar4 * 2);
        pwVar15 = L"DriverList";
        uVar13 = 2;
        in_stack_ffffffffffffff58 = psVar10;
        iVar3 = RtlWriteRegistryValue(2,L"CrashControl");
        if ((-1 < iVar3) &&
           (DAT_18001bd60 = DAT_18001bd60 | 0x20000,
           (Microsoft_Windows_CrashdumpEnableBits & 0x10) != 0)) {
          McTemplateK0_EtwWriteTransfer(uVar13,&EarlyDumpSupported,pwVar15);
        }
        ExFreePoolWithTag(psVar10,0);
      }
      goto LAB_180003ab4;
    }
    uVar5 = 0xc0000017;
  }
  if ((DAT_18001c400 != 0) && (KeDeregisterBugCheckReasonCallback(), DAT_18001c400 != 0)) {
    ExFreePoolWithTag(DAT_18001c400,0);
    DAT_18001c400 = 0;
  }
  if ((DAT_18001c408 != 0) && (KeDeregisterBugCheckReasonCallback(), DAT_18001c408 != 0)) {
    ExFreePoolWithTag(DAT_18001c408,0);
    DAT_18001c408 = 0;
  }
  FreePortResources((longlong)ppuVar6,0x18001bd00);
  if (local_88 != (undefined8 *)0x0) {
    ObfDereferenceObject(local_88);
  }
  *param_2 = 0;
  if (DAT_18001c528 == '\x01') {
    DAT_18001c528 = '\0';
  }
LAB_180003c3c:
  memcpy(&ContextCopy,&Context,0x8d0);
  return uVar5;
}



===== CrashdmpLogStatusData @ 180003c80 =====

void CrashdmpLogStatusData(int param_1,undefined8 param_2,void *param_3,uint param_4)

{
  if ((((param_1 == 2) && (param_3 != (void *)0x0)) && (param_4 != 0)) &&
     (((DAT_18001c52b != '\0' && (DAT_18001c520 != 0)) &&
      (*(longlong *)(DAT_18001c520 + 0x2c0) != 0)))) {
    WriteLogData(DAT_18001c520,param_3,param_4);
  }
  return;
}



===== CrashdmpNotify @ 180003cd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CrashdmpNotify(int param_1,undefined4 *param_2,undefined8 *param_3,undefined8 *param_4)

{
  int iVar1;
  int *piVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  longlong lVar7;
  longlong lVar8;
  longlong *plVar9;
  undefined4 local_res20 [2];
  
  puVar3 = DAT_18001bd40;
  local_res20[0] = 0;
  lVar8 = 0;
  puVar6 = param_3;
  uVar5 = CheckContextIntegrity();
  uVar4 = uRam000000018001c494;
  lVar7 = DAT_18001bda0;
  if ((int)uVar5 < 0) {
    return;
  }
  if (7 < param_1) {
    if (param_1 == 8) {
      if ((DAT_18001c4cc != '\0') && (DAT_18001bd58 == 4)) {
        if (DAT_18001c488 != 4) {
          if ((DAT_18001c488 != 5) && (DAT_18001c488 != 6)) goto LAB_18000437c;
          DAT_18001bdc8 = (undefined8 *)(DAT_18001bda0 + 0x2000);
          _DAT_18001c2f0 = 0;
          *DAT_18001bdc8 = _DAT_18001c48c;
          *(undefined8 *)(lVar7 + 0x2008) = uVar4;
          uVar4 = uRam000000018001c4a4;
          *(undefined8 *)(lVar7 + 0x2010) = _DAT_18001c49c;
          *(undefined8 *)(lVar7 + 0x2018) = uVar4;
          uVar4 = uRam000000018001c4b4;
          *(undefined8 *)(lVar7 + 0x2020) = _DAT_18001c4ac;
          *(undefined8 *)(lVar7 + 0x2028) = uVar4;
          uVar4 = uRam000000018001c4c4;
          *(undefined8 *)(lVar7 + 0x2030) = _DAT_18001c4bc;
          *(undefined8 *)(lVar7 + 0x2038) = uVar4;
          DAT_18001bd58 = DAT_18001c488;
          _DAT_18001c2f8 = DAT_18001c488;
        }
        DAT_18001c4cc = '\0';
      }
    }
    else if (param_1 == 9) {
      DAT_18001bd60 = DAT_18001bd60 | 0x40000;
    }
    else if (param_1 == 10) {
      DAT_18001c318 = DAT_18001c318 | 0x20;
      _DAT_18001c2f0 = DAT_18001bda0 + 0x2000;
      _DAT_18001c2f8 = 4;
      DAT_18001bd58 = 4;
      DAT_18001bdc8 = (undefined8 *)0x0;
    }
    else if (param_1 == 0xb) {
      if (DAT_18001c444 == 0xa001) {
        DAT_18001c444 = 0;
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0xe2,0xa001,0,0,0);
      }
    }
    else if (param_1 == 0xc) {
      DAT_18001c4cd = (char)param_3;
    }
    goto LAB_18000437c;
  }
  if (param_1 == 7) {
    if (DAT_18001c590 == 0) {
      DAT_18001c590 = KeQueryPerformanceCounter(&DAT_18001c598);
    }
    if (DAT_18001c444 == 0xa000) {
      DAT_18001c444 = 0;
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0xe2,0xa000,0,0,0);
    }
    goto LAB_18000437c;
  }
  if (param_1 == 1) {
    if ((int)param_3 == 1) {
      DAT_18001bd60 = DAT_18001bd60 | 0x80;
    }
    if (*(char *)(puVar3 + 0x23) == '\x01') {
      *(undefined4 *)(puVar3[0x22] + 8) = 1;
    }
    CrashdmpDisplayString("\n\r%s",StrCollectingData,puVar6,param_4);
    goto LAB_18000437c;
  }
  if (param_1 != 3) {
    if (param_1 == 4) {
      local_res20[0] = 1;
      if (DAT_18001c520 == 0) goto LAB_18000437c;
      if (*(char *)(DAT_18001c520 + 0x230) != '\0') {
        if ((puVar3 != (undefined8 *)0x0) && (*(char *)(puVar3 + 0x23) == '\x01')) {
          lVar8 = puVar3[0x22];
          *(undefined4 *)(lVar8 + 8) = 3;
          (*(code *)DAT_18001bd40[0x41])(*(undefined8 *)(lVar8 + 0x10),7,local_res20);
        }
        *(undefined1 *)(DAT_18001c520 + 0x6a) = 1;
      }
      if (*(int *)(DAT_18001c520 + 0x178) != 2) goto LAB_18000437c;
      lVar8 = *(longlong *)(DAT_18001c520 + 0x110);
      *(undefined4 *)(lVar8 + 8) = 3;
    }
    else {
      if (param_1 != 5) {
        if ((param_1 != 6) || (param_2 == (undefined4 *)0x0)) goto LAB_18000437c;
        if (DAT_18001c4cc != '\0') {
          *param_2 = 0xc0000708;
          goto LAB_18000437c;
        }
        if ((int)param_3 != 4) {
          *param_2 = 0xc000000d;
          goto LAB_18000437c;
        }
        DAT_18001c488 = DAT_18001bd58;
        if (DAT_18001bd58 == 0) {
LAB_180003e0c:
          *param_2 = 0xc0000001;
        }
        else {
          if (DAT_18001bd58 != 4) {
            if ((DAT_18001bd58 != 5) && (DAT_18001bd58 != 6)) goto LAB_180003e0c;
            _DAT_18001c48c = *DAT_18001bdc8;
            uRam000000018001c494 = DAT_18001bdc8[1];
            _DAT_18001c49c = DAT_18001bdc8[2];
            uRam000000018001c4a4 = DAT_18001bdc8[3];
            _DAT_18001c4ac = DAT_18001bdc8[4];
            uRam000000018001c4b4 = DAT_18001bdc8[5];
            _DAT_18001c4bc = DAT_18001bdc8[6];
            uRam000000018001c4c4 = DAT_18001bdc8[7];
            _DAT_18001c2f0 = DAT_18001bda0 + 0x2000;
            DAT_18001bdc8 = (undefined8 *)0x0;
            DAT_18001bd58 = 4;
            _DAT_18001c2f8 = 4;
          }
          DAT_18001c4cc = '\x01';
          *param_2 = 0;
        }
        goto LAB_18000437c;
      }
      local_res20[0] = 2;
      if (DAT_18001c520 == 0) goto LAB_18000437c;
      if (*(char *)(DAT_18001c520 + 0x230) != '\0') {
        if (puVar3 != (undefined8 *)0x0) {
          if (*(char *)(puVar3 + 0x23) == '\x01') {
            lVar8 = puVar3[0x22];
            *(undefined4 *)(lVar8 + 8) = 0;
            (*(code *)DAT_18001bd40[0x41])(*(undefined8 *)(lVar8 + 0x10),7,local_res20);
          }
          else if ((*(char *)(puVar3 + 0x23) == '\0') &&
                  ((code *)DAT_18001bd40[0x44] != (code *)0x0)) {
            (*(code *)DAT_18001bd40[0x44])(2,0,0);
          }
        }
        *(undefined1 *)(DAT_18001c520 + 0x6a) = 0;
      }
      if (*(int *)(DAT_18001c520 + 0x178) != 2) {
        if (*(code **)(DAT_18001c520 + 0x220) != (code *)0x0) {
          (**(code **)(DAT_18001c520 + 0x220))(2,0,0);
        }
        goto LAB_18000437c;
      }
      lVar8 = *(longlong *)(DAT_18001c520 + 0x110);
      *(undefined4 *)(lVar8 + 8) = 0;
    }
    (**(code **)(DAT_18001c520 + 0x208))(*(undefined8 *)(lVar8 + 0x10),7,local_res20);
    goto LAB_18000437c;
  }
  if (puVar3 == (undefined8 *)0x0) goto LAB_18000437c;
  *(undefined1 *)((longlong)puVar3 + 0x69) = 1;
  if (*(char *)(puVar3 + 0x23) == '\x01') {
    lVar8 = puVar3[0x22];
    *(undefined4 *)(lVar8 + 8) = 2;
  }
  CrashdmpInitDumpStack(puVar3,0,puVar6,param_4);
  *(undefined1 *)((longlong)puVar3 + 0x69) = 0;
  PoSetHiberRange(0,0x10000,DAT_18001bda0,DAT_18001bda8,0x42706d44);
  PoSetHiberRange(0,0x10000,DAT_18001c378,0x1000,0x66756264);
  PoSetHiberRange(0,0x10000,DAT_18001bd98,(ulonglong)(DAT_18001bd90 + 1) << 4,0x6d656d44);
  if ((DAT_18001c52b == '\x01') && (DAT_18001bd40[0x55] != 0)) {
    PoSetHiberRange(0,0x10000,DAT_18001bd40[0x55],
                    (ulonglong)(*(int *)(DAT_18001bd40 + 0x54) + 1) << 4,0x6d656d44);
  }
  if (*(char *)(puVar3 + 0x23) == '\x01') {
    for (puVar6 = *(undefined8 **)(lVar8 + 0x28); puVar6 != (undefined8 *)(lVar8 + 0x28);
        puVar6 = (undefined8 *)*puVar6) {
      plVar9 = puVar6 + 9;
      lVar7 = 2;
      do {
        if (*plVar9 != 0) {
          PoSetHiberRange(0,0x10000,*plVar9,*(undefined4 *)(puVar6 + 8),0x66756263);
        }
        plVar9 = plVar9 + 1;
        lVar7 = lVar7 + -1;
      } while (lVar7 != 0);
    }
  }
  else {
    PoSetHiberRange(0,0x10000,puVar3[1],0x10000,0x6d656d44);
    puVar6 = puVar3 + 2;
    lVar8 = 2;
    do {
      PoSetHiberRange(0,0x10000,*puVar6,*(undefined4 *)(puVar3 + 0xe),0x66756263);
      puVar6 = puVar6 + 1;
      lVar8 = lVar8 + -1;
    } while (lVar8 != 0);
    piVar2 = (int *)puVar3[0x22];
    if ((*piVar2 - 2U < 3) && (piVar2[1] - 0x30U < 0x39)) {
      lVar8 = *(longlong *)(piVar2 + 4);
      if (lVar8 != 0) {
        iVar1 = piVar2[6];
LAB_180004165:
        PoSetHiberRange(0,0x10000,lVar8,iVar1,0x66756263);
      }
    }
    else {
      lVar8 = *(longlong *)(piVar2 + 6);
      if (lVar8 != 0) {
        iVar1 = piVar2[10];
        goto LAB_180004165;
      }
    }
  }
  for (puVar6 = (undefined8 *)puVar3[0x25]; puVar6 != puVar3 + 0x25; puVar6 = (undefined8 *)*puVar6)
  {
    PoSetHiberRange(0,0x10000,puVar6[3],*(undefined4 *)(puVar6 + 4),0x676d4944);
  }
LAB_18000437c:
  memcpy(&ContextCopy,&Context,0x8d0);
  return;
}



===== CrashdmpReady @ 1800043c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong CrashdmpReady(char param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  int iVar2;
  undefined4 extraout_var;
  ulonglong uVar3;
  undefined4 *puVar4;
  byte bVar5;
  undefined8 uVar6;
  char local_res10;
  byte local_res11;
  
  bVar5 = 1;
  if (((DAT_18001bd60 & 4) != 0) && ((DAT_18001bd60 & 8) == 0)) {
    iVar2 = InitializeDumpPath(&DAT_18001bd40);
    if (iVar2 < 0) {
      return CONCAT44(extraout_var,iVar2) & 0xffffffffffffff00;
    }
  }
  lVar1 = DAT_18001bd40;
  if (((DAT_18001bd40 == 0) || (DAT_18001c550 != 2)) || ((DAT_18001bd60 & 0x40000) != 0))
  goto LAB_18000454b;
  if (*(int *)(DAT_18001bd40 + 0x178) == 2) {
    bVar5 = 0;
    local_res11 = 0;
    local_res10 = param_1;
    iVar2 = (**(code **)(DAT_18001bd40 + 0x208))
                      (*(undefined8 *)(DAT_18001bd40 + 400),1,&local_res10);
    if (-1 < iVar2) {
      bVar5 = local_res11;
      goto LAB_18000454b;
    }
  }
  else {
    if (((((*(int *)(DAT_18001bd40 + 0x178) != 1) || (*(uint *)(DAT_18001bd40 + 0x180) < 3)) ||
         ((*(byte **)(DAT_18001bd40 + 0x1d0) == (byte *)0x0 ||
          ((bVar5 = **(byte **)(DAT_18001bd40 + 0x1d0), bVar5 != 0 || (param_1 == '\0')))))) ||
        (*(uint *)(DAT_18001bd40 + 0x180) < 4)) ||
       (*(code **)(DAT_18001bd40 + 0x1d8) == (code *)0x0)) goto LAB_18000454b;
    iVar2 = (**(code **)(DAT_18001bd40 + 0x1d8))();
    if (DAT_18001c528 == '\0') {
      DAT_18001c33c = DAT_18001c33c | 0x200;
      puVar4 = &DAT_18001c33c;
      uVar6 = 4;
      CrashdmpTelemetrySaveEnvironmentVariable(L"BugCheckProgress",&DAT_18001c33c,4);
      WriteLogProgress(DAT_18001c33c,puVar4,uVar6,param_4);
    }
    if (-1 < iVar2) {
      bVar5 = **(byte **)(lVar1 + 0x1d0);
      goto LAB_18000454b;
    }
  }
  if (DAT_18001c528 == '\0') {
    DAT_18001c33c = DAT_18001c33c | 0x80000;
    puVar4 = &DAT_18001c33c;
    uVar6 = 4;
    CrashdmpTelemetrySaveEnvironmentVariable(L"BugCheckProgress",&DAT_18001c33c,4);
    WriteLogProgress(DAT_18001c33c,puVar4,uVar6,param_4);
  }
LAB_18000454b:
  uVar3 = (ulonglong)DAT_18001bd60;
  if (((DAT_18001bd60 & 0x10) != 0) && (DAT_18001c550 == 2)) {
    uVar3 = (ulonglong)(uint3)(DAT_18001bd60 >> 8) << 8;
    bVar5 = bVar5 & -(DAT_18001c528 != '\0');
  }
  return CONCAT71((int7)(uVar3 >> 8),bVar5);
}



===== CrashdmpRemoveBitmapDumpHeaderPagesCallback @ 180004590 =====

void CrashdmpRemoveBitmapDumpHeaderPagesCallback
               (undefined8 param_1,undefined8 param_2,longlong param_3)

{
  *(undefined4 *)(param_3 + 8) = 1;
  *(longlong *)(param_3 + 0x10) = DAT_18001bda0;
  *(ulonglong *)(param_3 + 0x18) = *(ulonglong *)(DAT_18001bda0 + 0x2020) >> 0xc;
  return;
}



===== CrashdmpResumeCapable @ 1800045d0 =====

byte CrashdmpResumeCapable(uint *param_1,undefined8 param_2,undefined8 param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  
  bVar2 = 0;
  bVar1 = 0;
  if (DAT_18001c520 != 0) {
    uVar3 = *(uint *)(DAT_18001c520 + 0x290);
    if (DAT_18001c540 == 0xffffffff) {
      bVar2 = *(byte *)(DAT_18001c520 + 0x230);
    }
    else if (DAT_18001c540 == 1) {
      bVar2 = 1;
    }
    else {
      uVar3 = uVar3 | 8;
    }
    if ((Microsoft_Windows_CrashdumpEnableBits & 1) != 0) {
      McTemplateK0tq_EtwWriteTransfer
                ((ulonglong)DAT_18001c540,param_2,param_3,(uint)bVar2,(char)uVar3);
    }
    if (param_1 != (uint *)0x0) {
      *param_1 = uVar3;
    }
    bVar1 = bVar2;
  }
  return bVar1;
}



===== CrashdmpUpdatePhysicalRange @ 180004650 =====

ulonglong CrashdmpUpdatePhysicalRange(int *param_1)

{
  ulonglong uVar1;
  
  if (param_1 == (int *)0x0) {
    uVar1 = 0xc000000d;
  }
  else {
    uVar1 = UpdatePhysicalMemoryBlock(0x18001bd40,param_1);
    uVar1 = uVar1 & 0xffffffff;
    memcpy(&ContextCopy,&Context,0x8d0);
  }
  return uVar1;
}



===== CrashdmpWrite @ 1800046a0 =====

ulonglong CrashdmpWrite(undefined *param_1,char *param_2,undefined8 *param_3,undefined8 *param_4)

{
  uint uVar1;
  ulonglong uVar2;
  undefined4 *puVar3;
  char *pcVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  
  if ((DAT_18001bd60 & 0x100) != 0) {
    if (DAT_18001c528 == '\0') {
      DAT_18001c33c = DAT_18001c33c | 0x1000000;
      puVar3 = &DAT_18001c33c;
      uVar6 = 4;
      CrashdmpTelemetrySaveEnvironmentVariable(L"BugCheckProgress",&DAT_18001c33c,4);
      WriteLogProgress(DAT_18001c33c,puVar3,uVar6,param_4);
    }
    return 0xc0000001;
  }
  if (param_1 != &DAT_18001bdc0) {
    return 0xc000000d;
  }
  uVar2 = CheckContextIntegrity();
  if ((int)uVar2 < 0) {
    return uVar2 & 0xffffffff;
  }
  pcVar4 = StrInitPortDriver;
  CrashdmpDisplayString("\n\r%s",StrInitPortDriver,param_3,param_4);
  if (DAT_18001c528 != '\0') {
    DAT_18001c528 = '\0';
  }
  *(undefined1 *)((longlong)DAT_18001bd40 + 0x69) = 0;
  uVar2 = CrashdmpReady('\0',pcVar4,param_3,param_4);
  if (((char)uVar2 == '\0') && (DmpEncryptionContext == '\0')) {
    uVar2 = DumpWriteCapsule((longlong *)&DAT_18001bd40,pcVar4,param_3,param_4);
    uVar5 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      if (DAT_18001c528 != '\0') goto LAB_1800048e6;
      if ((((DAT_18001c33c >> 0x11 & 1) == 0) && ((DAT_18001c33c & 0x40000) == 0)) &&
         ((DAT_18001c33c >> 0x17 & 1) == 0)) {
        DAT_18001c33c = DAT_18001c33c & 0xfffffe47 | 0x47;
      }
LAB_180004874:
      DAT_18001c33c = DAT_18001c33c | 0x40000;
    }
    else {
      if (((DAT_18001c528 != '\0') || ((DAT_18001c33c >> 0x11 & 1) != 0)) ||
         (((DAT_18001c33c >> 0x12 & 1) != 0 || ((DAT_18001c33c >> 0x17 & 1) != 0))))
      goto LAB_1800048e6;
      DAT_18001c33c = DAT_18001c33c & 0xfffffe47 | 0x47;
    }
    uVar6 = 4;
    puVar3 = &DAT_18001c33c;
    CrashdmpTelemetrySaveEnvironmentVariable(L"BugCheckProgress",&DAT_18001c33c,4);
    WriteLogProgress(DAT_18001c33c,puVar3,uVar6,param_4);
  }
  else {
    if (*(char *)((longlong)DAT_18001bd40 + 0x6b) == '\0') {
      uVar2 = CrashdmpInitDumpStack(DAT_18001bd40,0,param_3,param_4);
      uVar5 = uVar2 & 0xffffffff;
      *(undefined1 *)((longlong)DAT_18001bd40 + 0x6b) = 1;
      if ((int)uVar2 < 0) {
        if (DAT_18001c528 != '\0') goto LAB_1800048e6;
        if ((((DAT_18001c33c >> 0x11 & 1) == 0) && ((DAT_18001c33c & 0x40000) == 0)) &&
           ((DAT_18001c33c >> 0x17 & 1) == 0)) {
          DAT_18001c33c = DAT_18001c33c & 0xfffffe42 | 0x42;
        }
        goto LAB_180004874;
      }
      if (((DAT_18001c528 == '\0') && ((DAT_18001c33c >> 0x11 & 1) == 0)) &&
         (((DAT_18001c33c >> 0x12 & 1) == 0 && ((DAT_18001c33c >> 0x17 & 1) == 0)))) {
        puVar3 = &DAT_18001c33c;
        DAT_18001c33c = DAT_18001c33c & 0xfffffe42 | 0x42;
        uVar6 = 4;
        CrashdmpTelemetrySaveEnvironmentVariable(L"BugCheckProgress",&DAT_18001c33c,4);
        WriteLogProgress(DAT_18001c33c,puVar3,uVar6,param_4);
      }
    }
    uVar1 = DumpWrite((longlong *)&DAT_18001bd40,param_2,DAT_18001bd20,(undefined *)param_4);
    uVar5 = (ulonglong)uVar1;
  }
LAB_1800048e6:
  memcpy(&ContextCopy,&Context,0x8d0);
  return uVar5;
}



===== DriverEntry @ 180004920 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined8 *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  undefined1 auStack_a8 [32];
  undefined4 local_88;
  char local_78 [8];
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  longlong lStack_40;
  longlong local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
                    /* 0x4920  1  DriverEntry */
  local_10 = __security_cookie ^ (ulonglong)auStack_a8;
  local_70 = 0;
  local_78[0] = '\0';
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  if ((param_1 == (undefined8 *)0x0) || (param_2 == (int *)0x0)) {
    iVar1 = -0x3ffffff3;
  }
  else if ((((*param_2 == 1) || (param_2[1] == 0xd)) && (*(longlong *)(param_2 + 0x1e) != 0)) &&
          (*(longlong *)(param_2 + 0x1c) != 0)) {
    KeInitializeSpinLock(&DAT_18001bcf8);
    DAT_18001c5b4 = 0x706d4443;
    Context = 0x706d4443;
    DAT_18001bd00 = *param_1;
    _DAT_18001bd08 = param_1[1];
    _DAT_18001bd10 = param_1[2];
    uRam000000018001bd18 = param_1[3];
    DAT_18001bd20 = param_1[4];
    DAT_18001bd28 = param_1[5];
    _DAT_18001bd30 = param_1[6];
    DAT_18001bd38 = param_1[7];
    *(code **)(param_2 + 2) = CrashdmpInitialize;
    *(code **)(param_2 + 4) = CrashdmpLoadDumpStack;
    *(code **)(param_2 + 6) = CrashdmpInitDumpStack;
    *(code **)(param_2 + 8) = CrashdmpFreeDumpStack;
    *(code **)(param_2 + 10) = CrashdmpDisable;
    *(code **)(param_2 + 0xc) = CrashdmpNotify;
    *(code **)(param_2 + 0xe) = CrashdmpWrite;
    *(code **)(param_2 + 0x10) = CrashdmpUpdatePhysicalRange;
    *(code **)(param_2 + 0x12) = CrashdmpResumeCapable;
    *(code **)(param_2 + 0x14) = CrashdmpGetTransferSizes;
    *(code **)(param_2 + 0x16) = CrashdmpLogStatusData;
    *(code **)(param_2 + 0x18) = CrashdmpReady;
    *(code **)(param_2 + 0x1a) = CrashdmpEnableEncryption;
    DAT_18001c5a8 = param_2;
    CrashdmpRegisterTraceLogging();
    wil_InitializeFeatureStaging();
    CrashdmpTelemetryCheckForPreviousCrash();
    iVar1 = NtQuerySystemInformation(0x5a,&local_30,0x20);
    if (iVar1 < 0) {
      DAT_18001c550 = 0;
    }
    else {
      DAT_18001c550 = 0;
      if ((int)local_20 < 3) {
        DAT_18001c550 = (int)local_20;
      }
    }
    local_88 = 1;
    iVar1 = ZwPowerInformation(0x42,0,0,local_78);
    if ((-1 < iVar1) && (local_78[0] != '\0')) {
      DAT_18001c52c = 1;
    }
    local_58 = 0;
    local_68 = 0xf00000001;
    lStack_40 = 0;
    uStack_50 = 0x40000000;
    uStack_60 = 0xfffffffffffffffe;
    local_48 = 0x80000000;
    local_38 = 0;
    iVar1 = MmQueryMemoryRanges(&local_68);
    if (((-1 < iVar1) && (lStack_40 != 0)) && (DAT_18001c52d = 1, local_38 != 0)) {
      ExFreePoolWithTag(local_38,0);
      local_38 = 0;
    }
    uVar3 = CrashdmpRegisterEtw();
    iVar1 = 0;
    if (-1 < (int)uVar3) {
      iVar1 = (int)uVar3;
    }
    DAT_18001c554 = *(undefined4 *)NtBuildNumber_exref;
    iVar2 = KsrGetFirmwareInformation(&local_70);
    if (-1 < iVar2) {
      DAT_18001c52e = 1;
    }
    memcpy(&ContextCopy,&Context,0x8d0);
  }
  else {
    iVar1 = -0x3fffffa7;
  }
  return iVar1;
}



===== MarkHiberBootPhase @ 180004bf0 =====

void MarkHiberBootPhase(longlong param_1)

{
  uint uVar1;
  undefined8 *puVar2;
  
  PoSetHiberRange(0,0x10000,param_1,0x2e0,0x63637344);
  for (puVar2 = *(undefined8 **)(param_1 + 0x280); puVar2 != (undefined8 *)(param_1 + 0x280);
      puVar2 = (undefined8 *)*puVar2) {
    PoSetHiberRange(0,0x10000,puVar2 + -0x14,200,0x63667344);
  }
  for (puVar2 = *(undefined8 **)(param_1 + 0x128); puVar2 != (undefined8 *)(param_1 + 0x128);
      puVar2 = (undefined8 *)*puVar2) {
    PoSetHiberRange(0,0x10000,puVar2,0x30,0x63647344);
  }
  if (*(int *)(param_1 + 0x178) == 2) {
    for (puVar2 = *(undefined8 **)(param_1 + 0x198); puVar2 != (undefined8 *)(param_1 + 0x198);
        puVar2 = (undefined8 *)*puVar2) {
      PoSetHiberRange(0,0x10000,puVar2 + -1,*(undefined4 *)(puVar2 + -1),0x69647344);
      if (puVar2[5] != 0) {
        PoSetHiberRange(0,0x10000,puVar2[5],*(undefined4 *)((longlong)puVar2 + 0x24),0x69647344);
      }
    }
    for (puVar2 = *(undefined8 **)(param_1 + 0x1a8); puVar2 != (undefined8 *)(param_1 + 0x1a8);
        puVar2 = (undefined8 *)*puVar2) {
      PoSetHiberRange(0,0x10000,puVar2 + -1,*(undefined4 *)(puVar2 + -1),0x69617344);
      if (puVar2[5] != 0) {
        PoSetHiberRange(0,0x10000,puVar2[5],*(undefined4 *)((longlong)puVar2 + 0x24),0x69617344);
      }
    }
    for (puVar2 = *(undefined8 **)(param_1 + 0x1b8); puVar2 != (undefined8 *)(param_1 + 0x1b8);
        puVar2 = (undefined8 *)*puVar2) {
      PoSetHiberRange(0,0x10000,puVar2 + -1,*(undefined4 *)(puVar2 + -1),0x72647344);
      if (puVar2[8] != 0) {
        PoSetHiberRange(0,0x10000,puVar2[8],*(undefined4 *)((longlong)puVar2 + 0x3c),0x72647344);
      }
    }
  }
  else if (((*(int *)(param_1 + 0x178) == 1) && (2 < *(uint *)(param_1 + 0x180))) &&
          (*(longlong *)(param_1 + 0x1d0) != 0)) {
    PoSetHiberRange(0,0x10000,*(longlong *)(param_1 + 0x1d0),1,0x63637344);
  }
  if (DAT_18001bd78 != (uint *)0x0) {
    PoSetHiberRange(0,0x10000,DAT_18001bd78,0x20,0x6d707344);
    uVar1 = 0;
    if (*DAT_18001bd78 != 0) {
      do {
        PoSetHiberRange(0,0x10000,DAT_18001bd78 + ((ulonglong)uVar1 + 1) * 4,0x10,0x6d707344);
        uVar1 = uVar1 + 1;
      } while (uVar1 < *DAT_18001bd78);
    }
  }
  if (((*(int *)(param_1 + 0x170) == 3) && (DAT_18001c448 != 0)) &&
     ((DAT_18001c484 != 0 && ((DAT_18001bd60 & 0x20) != 0)))) {
    PoSetHiberRange(0,0x10000,DAT_18001c448,DAT_18001c484,0x6d707344);
  }
  if (DAT_18001c538 != 0) {
    PoSetHiberRange(0,0x10000,&Context,0x8d0,0x6d707344);
    PoSetHiberRange(0,0x10000,DAT_18001c538,*(undefined4 *)(DAT_18001bd40 + 0x2d4),0x6d707344);
  }
  return;
}



===== McGenEventWrite_EtwWriteTransfer @ 180004f20 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_18001b008;
  uVar2 = 0;
  if (DAT_18001b008 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_18001b008;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(CrashdumpEventProvider_Context,param_2,0,0,param_4,param_5);
  return;
}



===== McTemplateK0_EtwWriteTransfer @ 180004f84 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0_EtwWriteTransfer(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auStackY_58 [32];
  undefined8 local_28 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,1,local_28);
  return;
}



===== McTemplateK0q_EtwWriteTransfer @ 180004fc8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0q_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = local_res20;
  local_1c = 0;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&EarlyDumpInitializationFailure,param_3,2,local_38);
  return;
}



===== McTemplateK0qq_EtwWriteTransfer @ 18000502c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = local_res20;
  local_28 = &param_5;
  local_2c = 0;
  local_30 = 4;
  local_1c = 0;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(4,param_2,param_3,3,local_48);
  return;
}



===== McTemplateK0tq_EtwWriteTransfer @ 180005098 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0tq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = local_res20;
  local_2c = 0;
  local_28 = &param_5;
  local_30 = 4;
  local_1c = 0;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(4,&EventResumeCapable,param_3,3,local_48);
  return;
}



===== RtlStringCchCatW @ 18000510c =====

uint RtlStringCchCatW(short *param_1,longlong param_2,longlong param_3)

{
  short *psVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  
  if (param_2 - 1U < 0x7fffffff) {
    psVar1 = param_1;
    lVar4 = param_2;
    do {
      if (*psVar1 == 0) break;
      psVar1 = psVar1 + 1;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    uVar2 = ~-(uint)(lVar4 != 0) & 0xc000000d;
    uVar3 = -(ulonglong)(lVar4 != 0) & param_2 - lVar4;
    if (lVar4 != 0) {
      uVar2 = RtlStringCopyWorkerW(param_1 + uVar3,param_2 - uVar3,uVar3,param_3,0x7ffffffe);
    }
  }
  else {
    uVar2 = 0xc000000d;
  }
  return uVar2;
}



===== RtlStringCopyWorkerW @ 1800051a4 =====

uint RtlStringCopyWorkerW
               (short *param_1,longlong param_2,undefined8 param_3,longlong param_4,longlong param_5
               )

{
  short sVar1;
  short *psVar2;
  longlong lVar3;
  
  if (param_2 != 0) {
    lVar3 = param_4 - (longlong)param_1;
    do {
      if ((param_5 == 0) || (sVar1 = *(short *)(lVar3 + (longlong)param_1), sVar1 == 0)) break;
      *param_1 = sVar1;
      param_5 = param_5 + -1;
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  psVar2 = param_1 + -1;
  if (param_2 != 0) {
    psVar2 = param_1;
  }
  *psVar2 = 0;
  return ~-(uint)(param_2 != 0) & 0x80000005;
}



===== UtilComputeConvertedCompactDataArraySize @ 180005200 =====

undefined8 UtilComputeConvertedCompactDataArraySize(longlong param_1,uint *param_2)

{
  ulonglong uVar1;
  uint uVar2;
  
  uVar1 = (ulonglong)*(uint *)(param_1 + 0x10) * 0x10;
  if (((uVar1 < 0x100000000) && (uVar2 = (int)uVar1 + 8, 7 < uVar2)) &&
     (uVar2 = uVar2 + *(uint *)(param_1 + 0x20), *(uint *)(param_1 + 0x20) <= uVar2)) {
    *param_2 = uVar2;
    return 0;
  }
  return 0xc0000095;
}



===== UtilComputeExtendedArrayDataSize @ 18000523c =====

uint UtilComputeExtendedArrayDataSize(longlong param_1,uint param_2,uint *param_3,uint *param_4)

{
  ulonglong uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  *param_3 = 0;
  *param_4 = 0;
  uVar4 = 0;
  for (uVar5 = 0; uVar5 < *(uint *)(param_1 + 0x10); uVar5 = uVar5 + 1) {
    uVar6 = uVar4 + 0x10;
    uVar1 = *(ulonglong *)(param_1 + 0x38 + (ulonglong)uVar5 * 0x10);
    if (0xffffffff < uVar1) {
      return 0xc0000095;
    }
    uVar7 = (uint)uVar1;
    cVar2 = IsBufferValid(*(ulonglong *)(param_1 + ((ulonglong)uVar5 + 3) * 0x10),uVar7);
    uVar3 = uVar6;
    if ((cVar2 != '\0') && (uVar3 = uVar7 + uVar6, uVar3 < uVar6)) {
      return 0xc0000095;
    }
    if ((param_2 != 0) && (param_2 < uVar3)) break;
    uVar4 = uVar3;
  }
  if (uVar5 == 0) {
    uVar4 = 0xc0000023;
  }
  else {
    uVar6 = *(uint *)(param_1 + 0x10);
    *param_3 = uVar5;
    *param_4 = uVar4;
    uVar4 = -(uint)(uVar5 < uVar6) & 0x105;
  }
  return uVar4;
}



===== WriteExtendedTriageDumpArrayHeader @ 180005308 =====

uint WriteExtendedTriageDumpArrayHeader(longlong param_1,longlong *param_2,uint *param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint local_res8 [2];
  
  iVar3 = *(int *)(param_1 + 0x20);
  local_res8[0] = 0;
  *param_3 = 0;
  iVar3 = (iVar3 + 7U & 0xfffffff8) + 0x14;
  uVar2 = UtilComputeExtendedArrayDataSize
                    (param_1,*(uint *)((longlong)param_2 + 0xc),param_3,local_res8);
  if ((int)uVar2 < 0) {
    *param_3 = 0;
  }
  else {
    piVar1 = (int *)*param_2;
    piVar1[1] = *param_3;
    piVar1[2] = local_res8[0];
    *piVar1 = iVar3;
    if (uVar2 == 0x105) {
      piVar1[3] = piVar1[3] | 1;
    }
    piVar1[4] = *(int *)(param_1 + 0x20) + 7U & 0xfffffff8;
    memcpy(piVar1 + 5,*(void **)(param_1 + 0x28),(ulonglong)*(uint *)(param_1 + 0x20));
    *(uint *)(param_2 + 7) = *(uint *)(param_2 + 7) | 1;
    param_2[4] = *param_2;
    uVar2 = 0;
    *(int *)(param_2 + 5) = iVar3;
  }
  return uVar2;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 1800053b8 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_18001a807 < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 1800053e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_RecordCachedUsage(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  longlong lVar6;
  bool bVar7;
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
    bVar7 = uVar2 == uVar4;
    if (bVar7) {
      *param_2 = uVar2 & 0xffc0401e;
    }
    else {
      uVar2 = uVar4;
    }
    UNLOCK();
  } while (!bVar7);
  uVar3 = uVar2 >> 1 & 0xf;
  uVar4 = 0;
  if (uVar3 != 0) {
    uVar4 = param_2[1];
    do {
      LOCK();
      uVar1 = param_2[1];
      bVar7 = uVar4 == uVar1;
      if (bVar7) {
        param_2[1] = uVar4 | uVar3;
      }
      else {
        uVar4 = uVar1;
      }
      UNLOCK();
    } while (!bVar7);
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
  lVar6 = (longlong)puVar5 - (longlong)&local_48 >> 3;
  if (0 < lVar6) {
    RtlRecordFeatureUsage(&local_48,lVar6);
  }
  return;
}



===== wil_details_RecordFeatureUsageReporting @ 180005540 =====

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



===== AllocateAdapterCommonBuffer @ 1800055c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
AllocateAdapterCommonBuffer
          (longlong param_1,char param_2,undefined4 param_3,longlong *param_4,undefined8 *param_5)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong local_res8;
  uint in_stack_ffffffffffffffd8;
  
  local_res8 = (-(ulonglong)(param_2 != '\0') & 0xffffffff00000000) + 0xffffffff;
  if ((param_1 == 0) || (lVar1 = *(longlong *)(param_1 + 8), lVar1 == 0)) {
    lVar1 = MmAllocateContiguousNodeMemory
                      (param_3,0,local_res8,-(ulonglong)(param_2 != '\0') & 0x100000000,4,0x80000000
                      );
    if (lVar1 != 0) {
      *param_4 = lVar1;
      uVar2 = MmGetPhysicalAddress(lVar1);
      *param_5 = uVar2;
      return 0;
    }
  }
  else {
    if (*(code **)(lVar1 + 0x98) == (code *)0x0) {
      lVar1 = (**(code **)(lVar1 + 0x10))(param_1,param_3,param_5,0);
    }
    else {
      lVar1 = (**(code **)(lVar1 + 0x98))
                        (param_1,&local_res8,param_3,param_5,in_stack_ffffffffffffffd8 & 0xffffff00,
                         0x80000000);
    }
    *param_4 = lVar1;
    if (lVar1 != 0) {
      return 0;
    }
  }
  return 0xc000009a;
}



===== AllocateAdapterMapRegisters @ 1800056c0 =====

undefined8 AllocateAdapterMapRegisters(longlong param_1,int param_2,undefined4 param_3)

{
  undefined8 uVar1;
  int local_res8 [2];
  undefined8 local_res20;
  
  local_res20 = 0;
  local_res8[0] = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = HalDmaAllocateCrashDumpRegistersEx(param_1,param_2 + 1,param_3,&local_res20,local_res8);
    if ((-1 < (int)uVar1) && (local_res8[0] != param_2 + 1)) {
      HalDmaFreeCrashDumpRegistersEx(param_1,param_3);
      uVar1 = 0xc000009a;
    }
  }
  return uVar1;
}



===== CalculateDumpSize @ 180005744 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong CalculateDumpSize(longlong param_1)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint *puVar6;
  ulonglong uVar7;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  longlong lStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  local_48 = 5;
  local_28 = 0;
  lStack_20 = 0;
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  iVar1 = ZwQueryInformationFile(*(undefined8 *)(param_1 + 8),&local_38,&local_28,0x18);
  if ((iVar1 < 0) || ((int)local_38 < 0)) {
    *(undefined8 *)(param_1 + 0x10) = 0x40000;
    lVar5 = 0x40000;
  }
  else {
    *(longlong *)(param_1 + 0x10) = lStack_20;
    lVar5 = lStack_20;
  }
  uVar7 = *(longlong *)(param_1 + 0x40) * 0x1000 + 0xfff +
          *(longlong *)(*(longlong *)(param_1 + 0x60) + 0x2020) & 0xfffffffffffff000;
  if (DmpEncryptionContext != '\0') {
    uVar7 = uVar7 + (ulonglong)DAT_18001b3ac + 0xfff & 0xfffffffffffff000;
  }
  iVar1 = *(int *)(param_1 + 0x18);
  if (lVar5 < (longlong)uVar7) {
    if ((iVar1 == 6) || ((iVar1 == 5 && ((*(uint *)(param_1 + 0x5d8) & 2) != 0)))) {
      uVar7 = lVar5 - 0x200000;
      if (0x1fffffff < lVar5) {
        uVar7 = lVar5 - 0x10000000;
      }
      uVar2 = 0x200000;
      if (0x1fffffff < lVar5) {
        uVar2 = 0x10000000;
      }
      uVar4 = (ulonglong)uVar2;
      if ((iVar1 == 6) && ((*(uint *)(param_1 + 0x5d8) & 1) != 0)) {
        *(uint *)(param_1 + 0x5d8) = *(uint *)(param_1 + 0x5d8) & 0xfffffffe;
      }
    }
    else {
      if (iVar1 != 4) {
        uVar3 = InitMiniDump(param_1);
        if ((int)uVar3 < 0) {
          return 0;
        }
        iVar1 = *(int *)(param_1 + 0x18);
      }
      uVar7 = 0x40000;
      uVar4 = *(longlong *)(param_1 + 0x10) - 0x40000;
    }
  }
  else if (iVar1 == 4) {
    uVar7 = lVar5 - 0x10000000;
    uVar4 = 0x10000000;
  }
  else if ((iVar1 == 6) && ((*(uint *)(param_1 + 0x5d8) & 1) == 0)) {
    uVar7 = lVar5 - 0x200000;
    if (0x1fffffff < lVar5) {
      uVar7 = lVar5 - 0x10000000;
    }
    uVar2 = 0x200000;
    if (0x1fffffff < lVar5) {
      uVar2 = 0x10000000;
    }
    uVar4 = (ulonglong)uVar2;
  }
  else {
    uVar4 = lVar5 - uVar7;
  }
  puVar6 = (uint *)(param_1 + 0x650);
  GetSecondaryDumpDataLimits(iVar1,uVar4,puVar6,(uint *)(param_1 + 0x654));
  return uVar7 + *puVar6;
}



===== DumpPreInitialize @ 180005924 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 DumpPreInitialize(undefined8 param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  
  uVar1 = 0;
  pcVar2 = (code *)RtlFindExportedRoutineByName(param_1,"DumpPreInitialize");
  if (pcVar2 != (code *)0x0) {
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



===== Feature_CrashDumpOneMBTransferSize__private_IsEnabledDeviceUsageNoInline @ 18000595c =====

ulonglong Feature_CrashDumpOneMBTransferSize__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_CrashDumpOneMBTransferSize__private_featureState;
  if ((Feature_CrashDumpOneMBTransferSize__private_featureState & 0x10) == 0) {
    uVar1 = Feature_CrashDumpOneMBTransferSize__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_CrashDumpOneMBTransferSize__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_CrashDumpOneMBTransferSize__private_IsEnabledFallback @ 180005994 =====

void Feature_CrashDumpOneMBTransferSize__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_CrashDumpOneMBTransferSize__private_descriptor);
  return;
}



===== Feature_CrashDumpOneMBTransferSize__private_IsEnabledNoReportingNoInline @ 1800059b0 =====

ulonglong Feature_CrashDumpOneMBTransferSize__private_IsEnabledNoReportingNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_CrashDumpOneMBTransferSize__private_featureState;
  if ((Feature_CrashDumpOneMBTransferSize__private_featureState & 2) == 0) {
    uVar1 = Feature_CrashDumpOneMBTransferSize__private_IsEnabledFallback(local_res8,0);
  }
  else {
    uVar1 = (ulonglong)(Feature_CrashDumpOneMBTransferSize__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledDeviceUsageNoInline @ 1800059e8 =====

ulonglong Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_SteelixInlineNvmeCryptoEngine__private_featureState;
  if ((Feature_SteelixInlineNvmeCryptoEngine__private_featureState & 0x10) == 0) {
    uVar1 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_SteelixInlineNvmeCryptoEngine__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledFallback @ 180005a20 =====

void Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_SteelixInlineNvmeCryptoEngine__private_descriptor);
  return;
}



===== Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline @ 180005a3c =====

ulonglong Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_SteelixInlineNvmeCryptoEngine__private_featureState;
  if ((Feature_SteelixInlineNvmeCryptoEngine__private_featureState & 2) == 0) {
    uVar1 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledFallback(local_res8,0);
  }
  else {
    uVar1 = (ulonglong)(Feature_SteelixInlineNvmeCryptoEngine__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_TriageDumpDataExtension__private_IsEnabledDeviceUsageNoInline @ 180005a74 =====

ulonglong Feature_TriageDumpDataExtension__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_TriageDumpDataExtension__private_featureState;
  if ((Feature_TriageDumpDataExtension__private_featureState & 0x10) == 0) {
    uVar1 = Feature_TriageDumpDataExtension__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_TriageDumpDataExtension__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_TriageDumpDataExtension__private_IsEnabledFallback @ 180005aac =====

void Feature_TriageDumpDataExtension__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_TriageDumpDataExtension__private_descriptor);
  return;
}



===== Feature_TriageDumpDataExtension__private_IsEnabledNoReportingNoInline @ 180005ac8 =====

ulonglong Feature_TriageDumpDataExtension__private_IsEnabledNoReportingNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_TriageDumpDataExtension__private_featureState;
  if ((Feature_TriageDumpDataExtension__private_featureState & 2) == 0) {
    uVar1 = Feature_TriageDumpDataExtension__private_IsEnabledFallback(local_res8,0);
  }
  else {
    uVar1 = (ulonglong)(Feature_TriageDumpDataExtension__private_featureState & 1);
  }
  return uVar1;
}



===== FillDumpInitContext @ 180005b00 =====

ulonglong FillDumpInitContext(undefined4 *param_1)

{
  undefined8 *puVar1;
  code *pcVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  char cVar6;
  ulonglong uVar7;
  bool bVar8;
  uint uVar9;
  
  pcVar2 = KeStallExecutionProcessor_exref;
  uVar4 = 0;
  bVar8 = false;
  param_1[1] = 0;
  *(code **)(param_1 + 0xc) = pcVar2;
  *(undefined4 **)(param_1 + 0x1e) = param_1 + 0x8d;
  *param_1 = 0x108;
  param_1[0x22] = param_1[0x99];
  if (param_1[0x99] == 0) {
    param_1[0x23] = param_1[0x9a];
    param_1[0x24] = param_1[0x9b];
  }
  else {
    *(undefined8 *)(param_1 + 0x23) = *(undefined8 *)(param_1 + 0x9a);
    *(undefined8 *)(param_1 + 0x25) = *(undefined8 *)(param_1 + 0x9c);
  }
  if (param_1[0x5e] == 2) {
    bVar8 = true;
    for (puVar1 = *(undefined8 **)(param_1 + 0x6a); puVar1 != (undefined8 *)(param_1 + 0x6a);
        puVar1 = (undefined8 *)*puVar1) {
      if (*(int *)(puVar1 + 8) == 0) {
        bVar8 = false;
      }
      else {
        uVar4 = Feature_CrashDumpOneMBTransferSize__private_IsEnabledDeviceUsageNoInline();
        uVar9 = *(uint *)(puVar1 + 8);
        if ((int)uVar4 == 0) {
          if (uVar9 < 0x40001) goto LAB_180005be3;
          *(undefined4 *)(puVar1 + 8) = 0x40000;
        }
        else {
          if (uVar9 < 0x400001) {
LAB_180005be3:
            uVar3 = 0x2000;
            if (0x2000 < uVar9) {
              uVar3 = uVar9;
            }
          }
          else {
            uVar3 = 0x400000;
          }
          *(uint *)(puVar1 + 8) = uVar3;
        }
        bVar8 = (bool)(bVar8 & -((*(byte *)(puVar1 + 4) & 1) != 0));
        uVar7 = 0;
        do {
          uVar4 = AllocateAdapterCommonBuffer
                            (puVar1[7],*(byte *)(puVar1 + 4) & 1,*(undefined4 *)(puVar1 + 8),
                             puVar1 + uVar7 + 9,puVar1 + uVar7 + 0xb);
          if ((int)uVar4 < 0) {
            return uVar4 & 0xffffffff;
          }
          uVar5 = AllocateAdapterMapRegisters(puVar1[7],*(uint *)(puVar1 + 8) >> 0xc,(int)uVar7);
          uVar4 = uVar5 & 0xffffffff;
          if ((int)uVar5 < 0) goto LAB_180005c69;
          uVar9 = (int)uVar7 + 1;
          uVar7 = (ulonglong)uVar9;
        } while (uVar9 < 2);
      }
    }
  }
  else {
    if (param_1[0x5e] == 1) {
      *(undefined8 *)(param_1 + 0x18) = *(undefined8 *)(param_1 + 0x62);
      uVar9 = 0x2000;
      if (0x2000 < (uint)param_1[0x66]) {
        uVar9 = param_1[0x66];
      }
      param_1[0x1c] = uVar9;
      cVar6 = *(char *)(param_1 + 0x67);
      if (2 < (uint)param_1[0x60]) {
        *(undefined8 *)(param_1 + 0x14) = *(undefined8 *)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x16) = *(undefined8 *)(param_1 + 0x72);
        bVar8 = (*(byte *)(param_1 + 0x6c) & 1) != 0;
      }
    }
    else {
      *(undefined8 *)(param_1 + 0x14) = *(undefined8 *)(param_1 + 0x60);
      *(undefined8 *)(param_1 + 0x16) = *(undefined8 *)(param_1 + 0x62);
      *(undefined8 *)(param_1 + 0x18) = *(undefined8 *)(param_1 + 100);
      uVar9 = 0x2000;
      if (0x2000 < (uint)param_1[0x6a]) {
        uVar9 = param_1[0x6a];
      }
      param_1[0x1c] = uVar9;
      cVar6 = *(char *)(param_1 + 0x6b);
    }
    if (cVar6 == '\x01') {
      uVar4 = Feature_CrashDumpOneMBTransferSize__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar4 == 0) {
        uVar3 = 0x10000;
      }
      else {
        uVar9 = param_1[0x1c];
        if (DAT_18001c5b0 < (uint)param_1[0x1c]) {
          param_1[0x1c] = DAT_18001c5b0;
          uVar9 = DAT_18001c5b0;
        }
        uVar3 = 0x10000;
        if (0x10000 < uVar9) {
          uVar3 = uVar9;
        }
      }
      param_1[0x1c] = uVar3;
      uVar7 = 0;
      do {
        uVar4 = AllocateAdapterCommonBuffer
                          (*(longlong *)(param_1 + 0x14),bVar8,param_1[0x1c],
                           (longlong *)(param_1 + (uVar7 + 2) * 2),
                           (undefined8 *)(param_1 + uVar7 * 2 + 8));
        if ((int)uVar4 < 0) {
          return uVar4 & 0xffffffff;
        }
        uVar5 = AllocateAdapterMapRegisters
                          (*(longlong *)(param_1 + 0x14),(uint)param_1[0x1c] >> 0xc,(int)uVar7);
        uVar4 = uVar5 & 0xffffffff;
        if ((int)uVar5 < 0) {
LAB_180005c69:
          DAT_18001bd60 = DAT_18001bd60 | 0x400;
          return uVar4;
        }
        uVar9 = (int)uVar7 + 1;
        uVar7 = (ulonglong)uVar9;
      } while (uVar9 < 2);
    }
  }
  *(bool *)((longlong)param_1 + 0x232) = bVar8;
  return uVar4;
}



===== FreeCrashdmpResources @ 180005dc0 =====

void FreeCrashdmpResources(longlong param_1)

{
  if ((*(uint *)(param_1 + 0x20) & 0x201) != 0) {
    if (*(longlong *)(param_1 + 8) != 0) {
      ZwClose();
      *(undefined8 *)(param_1 + 8) = 0;
      *(undefined8 *)(param_1 + 0x5c8) = 0;
    }
    if (*(longlong *)(param_1 + 0x30) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x30),0);
      *(undefined8 *)(param_1 + 0x30) = 0;
    }
  }
  if (*(longlong *)(param_1 + 0x60) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x60),0);
    *(undefined8 *)(param_1 + 0x60) = 0;
  }
  if (*(longlong *)(param_1 + 0x638) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x638),0);
    *(undefined8 *)(param_1 + 0x638) = 0;
  }
  if (*(longlong *)(param_1 + 0x648) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x648),0);
    *(undefined8 *)(param_1 + 0x648) = 0;
  }
  if (*(longlong *)(param_1 + 0x70) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x70),0);
    *(undefined8 *)(param_1 + 0x70) = 0;
  }
  if (*(longlong *)(param_1 + 0x58) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x58),0);
    *(undefined8 *)(param_1 + 0x58) = 0;
  }
  if (*(longlong *)(param_1 + 0x708) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x708),0);
    *(undefined8 *)(param_1 + 0x708) = 0;
  }
  if (*(longlong *)(param_1 + 0x6c0) != 0) {
    KeDeregisterBugCheckReasonCallback();
    if (*(longlong *)(param_1 + 0x6c0) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x6c0),0);
      *(undefined8 *)(param_1 + 0x6c0) = 0;
    }
  }
  if (*(longlong *)(param_1 + 0x6d0) != 0) {
    KeDeregisterBugCheckReasonCallback();
    if (*(longlong *)(param_1 + 0x6d0) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x6d0),0);
      *(undefined8 *)(param_1 + 0x6d0) = 0;
    }
  }
  if (*(longlong *)(param_1 + 0x6d8) != 0) {
    KeDeregisterBugCheckReasonCallback();
    if (*(longlong *)(param_1 + 0x6d8) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x6d8),0);
      *(undefined8 *)(param_1 + 0x6d8) = 0;
    }
  }
  if (*(longlong *)(param_1 + 0x6c8) != 0) {
    KeDeregisterBugCheckReasonCallback();
    if (*(longlong *)(param_1 + 0x6c8) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x6c8),0);
      *(undefined8 *)(param_1 + 0x6c8) = 0;
    }
  }
  if ((*(uint *)(param_1 + 0x20) & 4) != 0) {
    FreeMpioResources(param_1);
  }
  return;
}



===== FreeDumpInfo @ 180005fcc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FreeDumpInfo(longlong param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x178) == 2)) {
    lVar1 = *(longlong *)(param_1 + 400);
    if (lVar1 != 0) {
      (**(code **)(*(longlong *)(lVar1 + 0x40) + 0x18))(lVar1,7,param_1 + 0x180);
      *(undefined8 *)(param_1 + 400) = 0;
    }
    if ((DAT_18001bd60._2_1_ & 1) != 0) {
      puVar3 = *(undefined8 **)(param_1 + 0x1a8);
      while (puVar3 != (undefined8 *)(param_1 + 0x1a8)) {
        puVar2 = (undefined8 *)*puVar3;
        if (puVar3[7] != 0) {
          (**(code **)(*(longlong *)(puVar3[7] + 8) + 8))();
        }
        if (puVar3[5] != 0) {
          ExFreePoolWithTag(puVar3[5],0);
          puVar3[5] = 0;
        }
        ExFreePoolWithTag(puVar3 + -1);
        puVar3 = puVar2;
      }
      puVar3 = *(undefined8 **)(param_1 + 0x198);
      while (puVar3 != (undefined8 *)(param_1 + 0x198)) {
        puVar2 = (undefined8 *)*puVar3;
        if (puVar3[5] != 0) {
          ExFreePoolWithTag(puVar3[5],0);
          puVar3[5] = 0;
        }
        ExFreePoolWithTag(puVar3 + -1);
        puVar3 = puVar2;
      }
      puVar3 = *(undefined8 **)(param_1 + 0x1b8);
      while (puVar3 != (undefined8 *)(param_1 + 0x1b8)) {
        puVar2 = (undefined8 *)*puVar3;
        if (puVar3[3] != 0) {
          ExFreePoolWithTag(puVar3[3],0);
          puVar3[3] = 0;
        }
        if (puVar3[4] != 0) {
          ExFreePoolWithTag();
          puVar3[4] = 0;
        }
        if (puVar3[5] != 0) {
          ExFreePoolWithTag();
          puVar3[5] = 0;
        }
        if (puVar3[6] != 0) {
          ExFreePoolWithTag();
          puVar3[6] = 0;
        }
        if (puVar3[8] != 0) {
          ExFreePoolWithTag();
          puVar3[8] = 0;
        }
        ExFreePoolWithTag(puVar3 + -1);
        puVar3 = puVar2;
      }
    }
  }
  return;
}



===== FreePortResources @ 1800061a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FreePortResources(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined1 *puVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  longlong *plVar8;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [24];
  undefined1 local_38;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x178) == 2) {
      for (puVar7 = *(undefined8 **)(param_1 + 0x1a8); puVar7 != (undefined8 *)(param_1 + 0x1a8);
          puVar7 = (undefined8 *)*puVar7) {
        lVar1 = puVar7[7];
        plVar8 = puVar7 + 9;
        uVar6 = 0;
        do {
          if (*plVar8 != 0) {
            if (lVar1 == 0) {
              MmFreeContiguousMemory();
            }
            else {
              local_38 = 0;
              (**(code **)(*(longlong *)(lVar1 + 8) + 0x18))
                        (lVar1,*(undefined4 *)(puVar7 + 8),puVar7[uVar6 + 0xb],*plVar8);
              HalDmaFreeCrashDumpRegistersEx(lVar1,uVar6);
            }
            *plVar8 = 0;
          }
          uVar5 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar5;
          plVar8 = plVar8 + 1;
        } while (uVar5 < 2);
      }
      if (((DAT_18001bd60._2_1_ & 1) != 0) && (lVar1 = *(longlong *)(param_1 + 400), lVar1 != 0)) {
        (**(code **)(*(longlong *)(lVar1 + 0x40) + 0x18))(lVar1,7,param_1 + 0x180);
        *(undefined8 *)(param_1 + 400) = 0;
      }
    }
    else {
      lVar1 = *(longlong *)(param_1 + 0x50);
      plVar8 = (longlong *)(param_1 + 0x10);
      uVar6 = 0;
      do {
        if (*plVar8 != 0) {
          if (lVar1 == 0) {
            MmFreeContiguousMemory();
          }
          else {
            local_38 = 0;
            (**(code **)(*(longlong *)(lVar1 + 8) + 0x18))
                      (lVar1,*(undefined4 *)(param_1 + 0x70),
                       *(undefined8 *)(param_1 + 0x20 + uVar6 * 8),*plVar8);
            HalDmaFreeCrashDumpRegistersEx(lVar1,uVar6);
          }
          *plVar8 = 0;
        }
        uVar5 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar5;
        plVar8 = plVar8 + 1;
      } while (uVar5 < 2);
    }
    puVar4 = auStack_58;
    plVar8 = (longlong *)(param_1 + 0x280);
    while (plVar2 = (longlong *)*plVar8, plVar2 != plVar8) {
      if (((longlong *)plVar2[1] != plVar8) ||
         (lVar1 = *plVar2, (longlong *)*(longlong *)(lVar1 + 8) != plVar2)) {
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        puVar4 = auStack_50;
        break;
      }
      *plVar8 = lVar1;
      *(longlong **)(lVar1 + 8) = plVar8;
      if ((code *)plVar2[-0x10] != (code *)0x0) {
        (*(code *)plVar2[-0x10])(plVar2 + -0xb);
      }
      ExFreePoolWithTag(plVar2 + -0x14,0);
    }
    *(undefined8 *)(puVar4 + -8) = 0x18000635b;
    UnloadPortDriver(param_1,param_2);
    lVar1 = *(longlong *)(param_1 + 0x2a8);
    if (lVar1 != 0) {
      *(undefined8 *)(puVar4 + -8) = 0x180006370;
      ExFreePoolWithTag(lVar1,0);
      *(undefined8 *)(param_1 + 0x2a8) = 0;
    }
    lVar1 = *(longlong *)(param_1 + 0x2c0);
    if (lVar1 != 0) {
      *(undefined8 *)(puVar4 + -8) = 0x180006392;
      ExFreePoolWithTag(lVar1,0);
      *(undefined8 *)(param_1 + 0x2c0) = 0;
    }
    if (*(longlong *)(param_1 + 0x2c8) != 0) {
      *(undefined8 *)(puVar4 + -8) = 0x1800063b2;
      ZwClose();
    }
    *(undefined8 *)(puVar4 + -8) = 0x1800063bf;
    FreeDumpInfo(param_1);
    *(undefined8 *)(puVar4 + -8) = 0x1800063cb;
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== GetDumpFileDiskRuns @ 1800063f4 =====

undefined4 GetDumpFileDiskRuns(longlong param_1)

{
  undefined4 extraout_EAX;
  longlong lVar1;
  void *_Dst;
  longlong local_res8;
  
  if ((*(uint *)(param_1 + 0x20) & 0x10000) == 0) {
    local_res8 = CalculateDumpSize(param_1);
    if (local_res8 != 0) {
      if (*(int *)(param_1 + 0x18) - 5U < 2) {
        local_res8 = *(longlong *)(param_1 + 0x10);
      }
      GetFileDiskRuns(*(longlong *)(param_1 + 8),(uint *)(param_1 + 0x50),(longlong)&local_res8);
      return extraout_EAX;
    }
  }
  else {
    if ((*(byte *)(DAT_18001c4f0 + 10) & 5) == 0) {
      lVar1 = MmMapLockedPagesSpecifyCache(DAT_18001c4f0,0,1,0,0,0);
    }
    else {
      lVar1 = *(longlong *)(DAT_18001c4f0 + 0x18);
    }
    *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(lVar1 + 0x10);
    *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(lVar1 + 0x18);
    _Dst = (void *)ExAllocatePool2(0x40,(ulonglong)(*(int *)(lVar1 + 0x18) + 1) << 4,0x706d4443);
    *(void **)(param_1 + 0x58) = _Dst;
    if (_Dst != (void *)0x0) {
      memcpy(_Dst,(void *)((ulonglong)*(uint *)(lVar1 + 0x1c) + lVar1),
             (ulonglong)*(uint *)(lVar1 + 0x18) << 4);
      return 0;
    }
  }
  return 0xc000009a;
}



===== GetFileDiskRuns @ 1800064f0 =====

int GetFileDiskRuns(longlong param_1,uint *param_2,longlong param_3)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  int unaff_EBX;
  uint uVar5;
  uint uVar6;
  longlong *local_res8;
  longlong local_res20;
  undefined4 uVar7;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_res8 = (longlong *)0x0;
  local_38 = 0;
  uStack_30 = 0;
  if (((param_1 != 0) && (param_2 != (uint *)0x0)) && (param_3 != 0)) {
    uVar7 = 0;
    local_res20 = 0;
    iVar3 = ObReferenceObjectByHandle(0,3,*(undefined8 *)IoFileObjectType_exref,0,&local_res20,0);
    lVar2 = local_res20;
    if (-1 < iVar3) {
      iVar3 = ZwFsControlFile(param_1,0,0,0,&local_38,CONCAT44(uVar7,0x9003b),param_3,8,&local_res8,
                              8);
      if (iVar3 == 0x103) {
        KeWaitForSingleObject(lVar2 + 0x98,0,0,0,0);
        iVar3 = (int)local_38;
      }
      if ((-1 < iVar3) && (uVar5 = 0, *local_res8 != 0)) {
        do {
          uVar6 = uVar5;
          uVar5 = uVar6 + 1;
        } while (local_res8[uVar5 * 2] != 0);
        if (uVar5 != 0) {
          *param_2 = uVar5;
          lVar4 = ExAllocatePool2(0x40,(ulonglong)(uVar6 + 2) << 4,0x706d4443);
          *(longlong *)(param_2 + 2) = lVar4;
          if ((lVar4 != 0) && (uVar6 = 0, uVar5 != 0)) {
            lVar4 = 0;
            do {
              uVar1 = uVar6 * 2;
              uVar6 = uVar6 + 1;
              *(longlong *)(lVar4 + *(longlong *)(param_2 + 2)) = local_res8[uVar1];
              lVar4 = lVar4 + 0x10;
              *(longlong *)(*(longlong *)(param_2 + 2) + -8 + lVar4) = local_res8[uVar1 + 1];
            } while (uVar6 < uVar5);
          }
        }
      }
    }
    if (lVar2 != 0) {
      ObfDereferenceObject(lVar2);
    }
    if (local_res8 != (longlong *)0x0) {
      ExFreePoolWithTag(local_res8,0);
    }
  }
  return unaff_EBX;
}



===== GetLegacyPortDriverName @ 1800066e0 =====

undefined8 GetLegacyPortDriverName(longlong param_1,uint param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  wchar_t *pwVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  wchar_t *pwVar6;
  
  *param_3 = 0;
  puVar1 = (undefined8 *)ExAllocatePool2(0x40,0x48,0x706d4443);
  if (puVar1 == (undefined8 *)0x0) {
    return 0xc000009a;
  }
  if ((*(longlong *)(param_1 + 0x30) == 0) || (*(char *)(param_1 + 0x2d) != '\0')) {
    lVar2 = GetPortDriverObject(param_2);
  }
  else {
    lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 8);
  }
  if ((lVar2 != 0) && (pwVar6 = *(wchar_t **)(lVar2 + 0x40), pwVar6 != (wchar_t *)0x0)) {
    while (pwVar3 = wcsstr(pwVar6,L"\\"), pwVar3 != (wchar_t *)0x0) {
      pwVar6 = pwVar3 + 1;
    }
    if (pwVar6 != (wchar_t *)0x0) {
      RtlStringCchPrintfW((wchar_t *)(puVar1 + 1),0xf,L"%s.sys",pwVar6);
      *puVar1 = *param_3;
      *param_3 = puVar1;
      if ((*(char *)(param_1 + 0x2d) != '\x01') && (*(longlong *)(param_1 + 0x30) != 0)) {
        return 0;
      }
      puVar4 = (undefined8 *)ExAllocatePool2(0x40,0x48,0x706d4443);
      if (puVar4 != (undefined8 *)0x0) {
        RtlStringCchCopyW((short *)(puVar4 + 1),0xf,L"diskdump.sys");
        pwVar6 = L"storport.sys";
        if (*(longlong *)(param_1 + 0x30) == 0) {
          pwVar6 = L"scsiport.sys";
        }
        RtlStringCchCopyW((short *)((longlong)puVar4 + 0x26),0xf,pwVar6);
        *puVar4 = *param_3;
        *param_3 = puVar4;
        return 0;
      }
      uVar5 = 0xc000009a;
      goto LAB_18000675a;
    }
  }
  uVar5 = 0xc0000001;
LAB_18000675a:
  ExFreePoolWithTag(puVar1,0);
  return uVar5;
}



===== InitDedicatedDump @ 180006850 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int InitDedicatedDump(longlong param_1)

{
  bool bVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  uint *puVar8;
  ulonglong *puVar9;
  undefined1 uVar10;
  ushort uVar11;
  undefined1 auStackY_a8 [32];
  int local_68;
  uint local_64;
  longlong local_60;
  longlong local_58 [8];
  
  local_58[7] = __security_cookie ^ (ulonglong)auStackY_a8;
  local_64 = 0;
  puVar8 = (uint *)(param_1 + 0x28);
  local_68 = 0;
  local_60 = 0;
  local_58[0] = 0;
  local_58[1] = 0;
  local_58[6] = 0;
  uVar11 = 0;
  uVar10 = 0;
  local_58[2] = 0;
  local_58[3] = 0;
  local_58[4] = 0;
  local_58[5] = 0;
  iVar2 = ReadRegString(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl",
                        L"DedicatedDumpFile",puVar8);
  if (iVar2 < 0) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffffe;
    return 0;
  }
  CheckDumpFilePathDosnamePrefix(param_1);
  if (0x95 < *(ushort *)(param_1 + 0x2a)) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffffe;
    return -0x3ffffff3;
  }
  *(undefined8 *)(param_1 + 8) = 0;
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 1;
  bVar1 = IsDedicatedDumpFileStorageReserveEnabled();
  if (bVar1) {
    iVar2 = InitDedicatedDumpStorageReserve(param_1);
    if (iVar2 < 0) {
      return iVar2;
    }
    goto LAB_180006aa5;
  }
  iVar2 = ReadRegULongKey(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl",
                          L"EnableDynamicDedicatedDumpFileSizing",&local_68,0);
  if ((iVar2 < 0) || (local_68 == 0)) {
    puVar8 = &local_64;
    iVar2 = ReadRegULongKey(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl"
                            ,L"DumpFileSize",puVar8,0);
    if ((-1 < iVar2) && (local_64 != 0)) {
      lVar4 = (ulonglong)local_64 << 0x14;
LAB_180006a2a:
      *(longlong *)(param_1 + 0x10) = lVar4;
    }
  }
  else {
    puVar8 = (uint *)0x38;
    ZwQuerySystemInformation(0xb6,local_58);
    if (local_58[0] != 0) {
      uVar7 = local_58[0] + 0x3fffffffU >> 0x14 & 0xffffffff;
      uVar6 = uVar7 >> 10;
      if (DAT_18001c52d != 0) {
        uVar11 = *(ushort *)(param_1 + 0x7d4);
        lVar4 = (-(ulonglong)(uVar6 < uVar11) & 0xfffffff800000000) + 0x1000000000;
        goto LAB_180006a2a;
      }
      uVar11 = *(ushort *)(param_1 + 0x7d6);
      if (uVar11 < uVar6) {
        lVar4 = 0x1000000000;
      }
      else if (uVar6 < 0x41) {
        lVar4 = 0x200000000;
      }
      else if (uVar6 < 0x100) {
        lVar4 = (uVar7 >> 0xd) << 0x1e;
      }
      else {
        lVar4 = 0x800000000;
      }
      *(longlong *)(param_1 + 0x10) = lVar4;
    }
  }
  uVar10 = (undefined1)uVar11;
  puVar9 = (ulonglong *)(param_1 + 0x10);
  if (*puVar9 == 0) {
    puVar8 = (uint *)(param_1 + 0x650);
    GetSecondaryDumpDataLimits(5,0xffffffff,puVar8,(uint *)(param_1 + 0x654));
    uVar7 = (*(longlong *)(param_1 + 0x40) * 0x1000 +
             *(longlong *)(*(longlong *)(param_1 + 0x60) + 0x2020) + 0xfff & 0xfffffffffffff000U) +
            (ulonglong)*puVar8;
    *puVar9 = uVar7;
    if (DmpEncryptionContext != '\0') {
      *puVar9 = (ulonglong)DAT_18001b3ac + 0xfff + uVar7 & 0xfffffffffffff000;
    }
  }
LAB_180006aa5:
  CheckForCrashDump(param_1);
  lVar3 = KeQueryPerformanceCounter(&local_60);
  lVar4 = param_1;
  iVar2 = CreateDumpFile(param_1);
  if (iVar2 < 0) {
    CrashdmpWriteErrorLog(lVar4,0xc00400a4,iVar2,0x1003,(void *)0x0,0);
  }
  else {
    uVar5 = 0;
    lVar4 = KeQueryPerformanceCounter();
    if ((Microsoft_Windows_CrashdumpEnableBits & 2) != 0) {
      lVar4 = (lVar4 - lVar3) * 1000;
      McTemplateK0txxxq_EtwWriteTransfer
                (uVar5,lVar4 % local_60,puVar8,(uint)DAT_18001c52d,(char)local_58[0],
                 (char)*(undefined8 *)(param_1 + 0x10),(char)(lVar4 / local_60),uVar10);
    }
  }
  *(undefined8 *)(param_1 + 0x5c8) = *(undefined8 *)(param_1 + 8);
  return iVar2;
}



===== InitDedicatedDumpDevice @ 180006b7c =====

undefined8 InitDedicatedDumpDevice(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 local_res8;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  longlong local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_1c = 0;
  local_res8 = 0;
  local_34 = 0;
  local_48 = 0;
  uStack_40 = 0;
  iVar1 = ReadRegString(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl",
                        L"DedicatedDumpDevice",param_1 + 0x28);
  if (iVar1 < 0) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffdff;
    uVar2 = 0;
  }
  else {
    *(undefined8 *)(param_1 + 8) = 0;
    local_30 = 0;
    local_38 = 0x30;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x200;
    DAT_18001c52b = 0;
    local_20 = 0x200;
    local_18 = 0;
    uStack_10 = 0;
    local_28 = param_1 + 0x28;
    uVar2 = ZwOpenFile(&local_res8,0x100180,&local_38,&local_48,3,0x40);
    if (-1 < (int)uVar2) {
      *(undefined8 *)(param_1 + 8) = local_res8;
    }
    *(undefined8 *)(param_1 + 0x5c8) = *(undefined8 *)(param_1 + 8);
  }
  return uVar2;
}



===== InitDedicatedDumpStorageReserve @ 180006c64 =====

int InitDedicatedDumpStorageReserve(longlong param_1)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  longlong local_res10;
  
  iVar4 = 0;
  local_res10 = 0;
  uVar3 = GetDedicatedDumpFileSize(L"Crashdmp-DedicatedDumpFileSize-Mini");
  uVar7 = (ulonglong)uVar3;
  uVar3 = GetDedicatedDumpFileSize(L"Crashdmp-DedicatedDumpFileSize-Kernel");
  uVar10 = (ulonglong)uVar3;
  uVar3 = GetDedicatedDumpFileSize(L"Crashdmp-DedicatedDumpFileSize-Full");
  uVar9 = (ulonglong)uVar3;
  if (((uVar7 == 0) || (uVar10 == 0)) || (uVar3 == 0)) {
    return -0x3fffffff;
  }
  bVar2 = IsStorageHardReserveCreated(DAT_18001bd00,&local_res10);
  if (bVar2) {
    lVar5 = GetDumpFileSize(param_1);
    uVar8 = local_res10 + lVar5;
    uVar6 = AddDumpDirToStorageHardReserve(param_1);
    iVar1 = *(int *)(param_1 + 0x1c);
    iVar4 = (int)uVar6;
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    if (iVar1 == 4) {
      uVar6 = uVar7;
    }
    else if (iVar1 == 5) {
      uVar6 = uVar9;
    }
    else {
      uVar6 = 0;
      if (iVar1 == 6) {
        uVar6 = uVar10;
      }
    }
    if (uVar6 <= uVar8) {
      uVar7 = uVar6;
      goto LAB_180006d4f;
    }
    if (uVar9 <= uVar8) {
      *(undefined4 *)(param_1 + 0x18) = 5;
      uVar7 = uVar9;
      goto LAB_180006d4f;
    }
    if (uVar10 <= uVar8) {
      *(undefined4 *)(param_1 + 0x18) = 6;
      goto LAB_180006d4f;
    }
  }
  *(undefined4 *)(param_1 + 0x18) = 4;
LAB_180006d4f:
  *(ulonglong *)(param_1 + 0x10) = uVar7;
  return iVar4;
}



===== InitDumpContext @ 180006d7c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 InitDumpContext(longlong param_1,longlong param_2,undefined8 param_3)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  void *_Dst;
  undefined8 uVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  size_t _Size;
  undefined1 auStack_68 [32];
  undefined4 local_48 [2];
  ulonglong local_40 [3];
  
  local_40[2] = __security_cookie ^ (ulonglong)auStack_68;
  uVar7 = 0;
  *(undefined4 *)(param_1 + 0x84) = 0xd;
  local_48[0] = 0;
  _Size = 0;
  *(undefined8 *)(param_1 + 8) = param_3;
  *(undefined4 *)(param_1 + 0x80) = 1;
  piVar1 = *(int **)(param_2 + 8);
  local_40[0] = 0;
  local_40[1] = 0;
  if (piVar1 == (int *)0x0) {
    return 0xc000000d;
  }
  iVar3 = *piVar1;
  *(int **)(param_1 + 0x38) = piVar1;
  *(undefined8 *)(param_1 + 0x40) = *(undefined8 *)(piVar1 + 2);
  uVar6 = 0;
  *(longlong *)(param_1 + 0x48) =
       *(longlong *)(piVar1 + (ulonglong)(iVar3 - 1) * 4 + 6) +
       *(longlong *)(piVar1 + (ulonglong)(iVar3 - 1) * 4 + 4);
  iVar3 = ZwQuerySystemInformation(0xa5,local_40,0x10,local_48);
  if ((-1 < iVar3) && ((local_40[0] & 1) != 0)) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x800;
  }
  uVar4 = Feature_TriageDumpDataExtension__private_IsEnabledDeviceUsageNoInline();
  uVar8 = *(uint *)(param_1 + 0x20) | 0x800000;
  if ((int)uVar4 == 0) {
    uVar8 = *(uint *)(param_1 + 0x20) & 0xff7fffff;
  }
  *(uint *)(param_1 + 0x20) = uVar8;
  if ((*(int *)(param_1 + 0x18) - 5U < 2) ||
     ((*(int *)(param_1 + 0x18) == 4 && ((uVar8 & 0x800000) != 0)))) {
    lVar5 = ExAllocatePool2(0x40,0x30,0x706d4443);
    *(longlong *)(param_1 + 0x6d0) = lVar5;
    if (lVar5 != 0) {
      *(undefined1 *)(lVar5 + 0x2c) = 0;
      cVar2 = KeRegisterBugCheckReasonCallback
                        (*(undefined8 *)(param_1 + 0x6d0),CrashdmpCallbackForTriageDumpData,5,
                         StrTriageDumpData);
      if ((cVar2 == '\0') && (*(longlong *)(param_1 + 0x6d0) != 0)) {
        ExFreePoolWithTag(*(longlong *)(param_1 + 0x6d0),0);
        *(undefined8 *)(param_1 + 0x6d0) = 0;
      }
    }
  }
  iVar3 = *(int *)(param_1 + 0x18);
  if (iVar3 == 4) {
    _Size = 0x41800;
    lVar5 = ExAllocatePool2(0x40,0x41800,0x706d4443);
    *(longlong *)(param_1 + 0x60) = lVar5;
    if (lVar5 != 0) {
      *(longlong *)(param_1 + 0x5d0) = lVar5;
      *(longlong *)(param_1 + 0x5b0) = lVar5 + 0x2000;
      goto LAB_180007166;
    }
  }
  else {
    if ((iVar3 != 5) && (iVar3 != 6)) goto LAB_180007166;
    uVar9 = (*(longlong *)(param_1 + 0x48) + 7U >> 3) + 7 & 0xfffffffffffffff8;
    uVar4 = (DAT_18001bd30 + 1) * uVar9 + 0x307f & 0xfffffffffffff000;
    _Size = 0x41800;
    if (0x41800 < uVar4) {
      _Size = uVar4;
    }
    _Dst = (void *)ExAllocatePool2(0x40,_Size,0x706d4443);
    *(void **)(param_1 + 0x60) = _Dst;
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,_Size);
      *(ulonglong *)(*(longlong *)(param_1 + 0x60) + 0x2020) = uVar4;
      *(undefined8 *)(*(longlong *)(param_1 + 0x60) + 0x2030) = *(undefined8 *)(param_1 + 0x48);
      *(longlong *)(param_1 + 0x5d0) = *(longlong *)(param_1 + 0x60);
      *(longlong *)(param_1 + 0x88) = *(longlong *)(param_1 + 0x60) + 0x2000;
      if (DAT_18001bd30 != 0) {
        lVar5 = ExAllocatePool2(0x40,(ulonglong)DAT_18001bd30 << 4);
        *(longlong *)(param_1 + 0x70) = lVar5;
        if (lVar5 == 0) goto LAB_180007161;
        uVar4 = 0;
        if (DAT_18001bd30 != 0) {
          do {
            uVar8 = (int)uVar4 + 1;
            *(undefined8 *)(*(longlong *)(param_1 + 0x70) + uVar4 * 0x10) =
                 *(undefined8 *)(param_1 + 0x48);
            *(ulonglong *)(*(longlong *)(param_1 + 0x70) + 8 + uVar4 * 0x10) =
                 uVar8 * uVar9 + *(longlong *)(param_1 + 0x60) + 0x2038;
            uVar4 = (ulonglong)uVar8;
          } while (uVar8 < DAT_18001bd30);
        }
      }
      lVar5 = ExAllocatePool2(0x40,0x30,0x706d4443);
      *(longlong *)(param_1 + 0x6c0) = lVar5;
      if (lVar5 != 0) {
        *(undefined1 *)(lVar5 + 0x2c) = 0;
        cVar2 = KeRegisterBugCheckReasonCallback
                          (*(undefined8 *)(param_1 + 0x6c0),CrashdmpDumpCallback,2,StrCrashdump);
        if ((cVar2 == '\0') && (*(longlong *)(param_1 + 0x6c0) != 0)) {
          ExFreePoolWithTag(*(longlong *)(param_1 + 0x6c0),0);
          *(undefined8 *)(param_1 + 0x6c0) = 0;
        }
      }
      lVar5 = ExAllocatePool2(0x40,0x30,0x706d4443);
      *(longlong *)(param_1 + 0x6d8) = lVar5;
      if (lVar5 != 0) {
        *(undefined1 *)(lVar5 + 0x2c) = 0;
        cVar2 = KeRegisterBugCheckReasonCallback
                          (*(undefined8 *)(param_1 + 0x6d8),
                           CrashdmpRemoveBitmapDumpHeaderPagesCallback,6,StrRemovePages);
        if ((cVar2 == '\0') && (*(longlong *)(param_1 + 0x6d8) != 0)) {
          ExFreePoolWithTag(*(longlong *)(param_1 + 0x6d8),0);
          *(undefined8 *)(param_1 + 0x6d8) = 0;
        }
      }
      if (*(longlong *)(param_2 + 0x20) != 0) {
        uVar7 = (-(uint)((*(uint *)(param_1 + 0x20) & 0x800) != 0) & 0x1ff) + 2;
      }
      goto LAB_180007166;
    }
  }
LAB_180007161:
  uVar6 = 0xc000009a;
LAB_180007166:
  *(size_t *)(param_1 + 0x68) = _Size;
  if (uVar7 == 0) {
    uVar7 = 1;
  }
  do {
    lVar5 = ExAllocatePool2(0x40,uVar7 << 0xc,0x706d4443);
    *(longlong *)(param_1 + 0x638) = lVar5;
    if (lVar5 != 0) goto LAB_1800071b3;
    uVar7 = uVar7 >> 1;
  } while (1 < uVar7);
  uVar7 = 0;
  uVar6 = 0xc000009a;
LAB_1800071b3:
  *(uint *)(param_1 + 0x640) = uVar7 << 0xc;
  if ((lVar5 == 0) || (uVar7 < 2)) {
    *(undefined8 *)(param_1 + 0x648) = 0;
  }
  else {
    uVar7 = uVar7 - 1;
    lVar5 = ExAllocatePool2(0x40,(ulonglong)uVar7 << 3,0x706d4443);
    *(longlong *)(param_1 + 0x648) = lVar5;
    if ((lVar5 != 0) && (uVar8 = 0, uVar7 != 0)) {
      lVar5 = 0;
      do {
        uVar4 = MmGetPhysicalAddress((ulonglong)(uVar8 << 0xc) + *(longlong *)(param_1 + 0x638));
        uVar8 = uVar8 + 1;
        *(ulonglong *)(lVar5 + *(longlong *)(param_1 + 0x648)) = uVar4 >> 0xc;
        lVar5 = lVar5 + 8;
      } while (uVar8 < uVar7);
    }
  }
  *(undefined8 *)(param_1 + 0x708) = 0;
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffbff;
  return uVar6;
}



===== InitDumpLogFile @ 180007274 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void InitDumpLogFile(longlong *param_1)

{
  short sVar1;
  short *psVar2;
  undefined4 uVar3;
  int iVar4;
  int extraout_EAX;
  undefined8 uVar5;
  uint uVar6;
  longlong *plVar7;
  longlong lVar8;
  wchar_t *pwVar9;
  ulonglong uVar10;
  uint uVar11;
  undefined1 auStackY_f8 [32];
  undefined8 local_c8 [2];
  wchar_t local_b8 [80];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  local_c8[0] = 0;
  sVar1 = *(short *)((longlong)param_1 + 0x734);
  if (sVar1 == 0) {
    return;
  }
  if ((*(uint *)(param_1 + 4) & 1) == 0) {
    pwVar9 = L"%s:\\%s";
    if (sVar1 != 0x5c) {
      pwVar9 = L"\\??\\%s:\\%s";
    }
    uVar5 = RtlStringCchPrintfW(local_b8,0x50,pwVar9,(short *)((longlong)param_1 + 0x734));
    uVar6 = (uint)uVar5;
  }
  else {
    memset(local_b8,0,0xa0);
    psVar2 = (short *)param_1[6];
    if (*psVar2 != 0x5c) {
      builtin_wcsncpy(local_b8,L"\\??\\",4);
    }
    uVar6 = 0;
    uVar11 = (uint)(*(ushort *)(param_1 + 5) >> 1);
    if (uVar11 != 0) {
      do {
        if (psVar2[(uVar11 - uVar6) - 1] == 0x5c) break;
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar11);
    }
    uVar11 = uVar11 - uVar6;
    pwVar9 = local_b8;
    lVar8 = 0x50;
    do {
      if (*pwVar9 == L'\0') break;
      pwVar9 = pwVar9 + 1;
      lVar8 = lVar8 + -1;
    } while (lVar8 != 0);
    uVar10 = -(ulonglong)(lVar8 != 0) & 0x50U - lVar8;
    uVar6 = ~-(uint)(lVar8 != 0) & 0xc000000d;
    if (lVar8 != 0) {
      if (0x7ffffffe < (ulonglong)uVar11) {
        DAT_18001c52b = 0;
        return;
      }
      uVar6 = RtlStringCopyWorkerW
                        (local_b8 + uVar10,0x50 - uVar10,lVar8,(longlong)psVar2,(ulonglong)uVar11);
    }
    if ((int)uVar6 < 0) {
      DAT_18001c52b = 0;
      return;
    }
    uVar6 = RtlStringCchCatW(local_b8,(ulonglong)(0x4f - uVar11),0x180017c90);
  }
  if (-1 < (int)uVar6) {
    CheckForLogFile(local_b8);
    if (DAT_18001c52b != '\x01') {
      return;
    }
    *(undefined1 *)(*param_1 + 0x233) = 0;
    if (DAT_18001c544 == 1) {
      *(undefined4 *)(*param_1 + 0x294) = 0x3000;
    }
    else {
      uVar3 = 0x3000;
      if (DAT_18001c544 == -1) {
        uVar3 = 0x8000;
      }
      *(undefined4 *)(*param_1 + 0x294) = uVar3;
    }
    iVar4 = CreateLogFile(*param_1,local_b8,(ulonglong)*(uint *)(*param_1 + 0x294));
    if (-1 < iVar4) {
      lVar8 = *param_1;
      local_c8[0] = CONCAT44(local_c8[0]._4_4_,*(undefined4 *)(lVar8 + 0x294));
      iVar4 = GetFileDiskRuns(*(longlong *)(lVar8 + 0x2c8),(uint *)(lVar8 + 0x2a0),
                              (longlong)local_c8);
      plVar7 = (longlong *)CONCAT44((int)((ulonglong)param_1 >> 0x20),iVar4);
      if (-1 < extraout_EAX) {
        uVar5 = ExAllocatePool2(0x40,0x1000,0x706d4443);
        *(undefined8 *)(*plVar7 + 0x2c0) = uVar5;
        if (*(longlong *)(*plVar7 + 0x2c0) != 0) {
          return;
        }
      }
    }
  }
  DAT_18001c52b = 0;
  return;
}



===== InitDumpPromotionSettings @ 1800074d4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void InitDumpPromotionSettings(longlong param_1)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  undefined1 auStack_88 [32];
  int local_68 [4];
  wchar_t local_58 [32];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  if ((*(uint *)(param_1 + 0x20) & 1) != 0) {
    local_68[0] = 0;
    iVar1 = ReadRegULongKey(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl\\Promotion"
                            ,L"KernelDumpPromotionEnabled",local_68,1);
    if (-1 < iVar1) {
      *(uint *)(param_1 + 0x5d8) =
           *(uint *)(param_1 + 0x5d8) & 0xfffffffe | (uint)(local_68[0] != 0);
    }
    if ((*(uint *)(param_1 + 0x5d8) & 1) != 0) {
      lVar3 = 0x5dc;
      for (uVar4 = 0; (int)uVar4 < 8; uVar4 = uVar4 + 1) {
        local_58[0] = L'\0';
        RtlStringCchPrintfW(local_58,0x20,L"KernelDumpPromotionCode_%1x",(ulonglong)uVar4);
        iVar2 = ReadRegULongKey(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl\\Promotion"
                                ,local_58,local_68,0);
        iVar1 = 0;
        if (-1 < iVar2) {
          iVar1 = local_68[0];
        }
        *(int *)(lVar3 + param_1) = iVar1;
        lVar3 = lVar3 + 4;
      }
    }
  }
  return;
}



===== InitMiniDump @ 1800075d8 =====

undefined8 InitMiniDump(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  if (*(longlong *)(param_1 + 0x60) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x60),0);
  }
  *(undefined8 *)(param_1 + 0x60) = 0;
  *(undefined8 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x18) = 4;
  *(undefined4 *)(param_1 + 0x5b8) = 4;
  lVar1 = ExAllocatePool2(0x40,0x41800,0x706d4443);
  *(longlong *)(param_1 + 0x60) = lVar1;
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    *(longlong *)(param_1 + 0x5d0) = lVar1;
    *(longlong *)(param_1 + 0x5b0) = lVar1 + 0x2000;
  }
  CrashdmpWriteErrorLog(lVar1,0xc0040031,0xc0000023,0x4001,(void *)0x0,0);
  return uVar2;
}



===== InitializeDumpDriver @ 180007690 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int InitializeDumpDriver(longlong param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined4 uVar8;
  code *pcVar9;
  undefined8 *puVar10;
  uint local_res8 [2];
  uint local_res10 [4];
  
  uVar8 = 0;
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(undefined8 *)(param_1 + 0x40) = 0;
  *(undefined8 *)(param_1 + 0x80) = 0;
  iVar2 = 0;
  *(undefined8 *)(param_1 + 0x48) = 0;
  *(undefined8 *)(param_1 + 0xa0) = 0;
  *(undefined8 *)(param_1 + 0xf8) = 0;
  *(undefined8 *)(param_1 + 0x100) = 0;
  *(undefined8 *)(param_1 + 0xa8) = 0;
  puVar10 = *(undefined8 **)(param_1 + 0x128);
  local_res10[0] = 0;
  local_res8[0] = 0;
  lVar7 = param_1;
  do {
    if (puVar10 == (undefined8 *)(param_1 + 0x128)) {
      *(undefined8 *)(param_1 + 0x1f0) = *(undefined8 *)(param_1 + 0x38);
      *(undefined8 *)(param_1 + 0x38) = 0;
      *(undefined8 *)(param_1 + 0x1f8) = *(undefined8 *)(param_1 + 0x40);
      *(undefined8 *)(param_1 + 0x40) = 0;
      *(undefined8 *)(param_1 + 0x200) = *(undefined8 *)(param_1 + 0x80);
      *(undefined8 *)(param_1 + 0x80) = 0;
      *(undefined8 *)(param_1 + 0x208) = *(undefined8 *)(param_1 + 0x48);
      *(undefined8 *)(param_1 + 0x48) = 0;
      *(undefined8 *)(param_1 + 0x210) = *(undefined8 *)(param_1 + 0xa0);
      *(undefined8 *)(param_1 + 0xa0) = 0;
      *(undefined8 *)(param_1 + 0x218) = *(undefined8 *)(param_1 + 0xf8);
      *(undefined8 *)(param_1 + 0xf8) = 0;
      *(undefined8 *)(param_1 + 0x220) = *(undefined8 *)(param_1 + 0x100);
      *(undefined8 *)(param_1 + 0x100) = 0;
      *(undefined8 *)(param_1 + 0x228) = *(undefined8 *)(param_1 + 0xa8);
      *(undefined8 *)(param_1 + 0xa8) = 0;
      uVar6 = Feature_CrashDumpOneMBTransferSize__private_IsEnabledNoReportingNoInline();
      uVar4 = *(uint *)(param_1 + 0x6c);
      if ((int)uVar6 == 0) {
        if (uVar4 == 0) {
          *(undefined4 *)(param_1 + 0x6c) = 0x10000;
        }
      }
      else {
        uVar3 = DAT_18001c5b0;
        if ((uVar4 != 0) && (uVar4 < DAT_18001c5b0)) {
          uVar3 = uVar4;
        }
        *(uint *)(param_1 + 0x6c) = uVar3;
      }
      if (*(code **)(param_1 + 0x218) != (code *)0x0) {
        (**(code **)(param_1 + 0x218))(local_res10,local_res8);
        if (local_res10[0] < 0x200) {
          local_res10[0] = 0x1000;
        }
        *(uint *)(param_1 + 0x2d0) = local_res10[0];
        uVar6 = Feature_CrashDumpOneMBTransferSize__private_IsEnabledNoReportingNoInline();
        if ((int)uVar6 == 0) {
          if (0xfe00 < local_res8[0] - 0x200) {
            local_res8[0] = 0x10000;
          }
          *(uint *)(param_1 + 0x2d4) = local_res8[0];
        }
        else {
          uVar4 = *(uint *)(param_1 + 0x6c);
          if (local_res8[0] < *(uint *)(param_1 + 0x6c)) {
            uVar4 = local_res8[0];
          }
          *(uint *)(param_1 + 0x2d4) = uVar4;
        }
      }
      if (*(longlong *)(param_1 + 0x1f8) != 0) {
        *(code **)(param_1 + 0x40) = CrashdmpWriteRoutine;
      }
      if (*(longlong *)(param_1 + 0x200) != 0) {
        *(code **)(param_1 + 0x80) = CrashdmpWritePendingRoutine;
      }
      if (*(longlong *)(param_1 + 0x208) != 0) {
        *(code **)(param_1 + 0x48) = CrashdmpFinishRoutine;
      }
      if (*(longlong *)(param_1 + 0x210) == 0) {
        *(uint *)(param_1 + 0x290) = *(uint *)(param_1 + 0x290) | 2;
        *(undefined1 *)(param_1 + 0x230) = 0;
      }
      else {
        *(code **)(param_1 + 0xa0) = CrashdmpReadRoutine;
      }
      cVar1 = (**(code **)(param_1 + 0x1f0))(*(undefined8 *)(param_1 + 0x108));
      if (cVar1 == '\x01') {
        if (DAT_18001c528 != '\x01') {
          uVar6 = (ulonglong)*(uint *)(param_1 + 0x1b0);
          if ((((*(int *)(param_1 + 0x178) == 1) && (2 < *(uint *)(param_1 + 0x180))) &&
              ((*(uint *)(param_1 + 0x1b0) & 2) != 0)) &&
             (((pcVar9 = *(code **)(param_1 + 0x228), pcVar9 != (code *)0x0 &&
               ((DAT_18001bd60 & 0x20) != 0)) &&
              ((DAT_18001c448 != 0 &&
               (lVar7 = IsStorageRelatedCrash(0x18001bd40), (char)lVar7 != '\0')))))) {
            iVar5 = (*pcVar9)(uVar6 & 0xffffffff,1);
            if (iVar5 < 0) {
              DAT_18001c470 = 0;
            }
            else {
              DAT_18001c470 = *(undefined4 *)(DAT_18001c448 + 4);
            }
          }
        }
        if (-1 < iVar2) {
          return iVar2;
        }
      }
      else {
        iVar2 = -0x3fffffff;
        uVar8 = 0x60002;
        _DAT_18001c420 = *(code **)(param_1 + 0x1f0);
LAB_1800079ab:
        _DAT_18001c43c = iVar2;
      }
      CrashdmpLogSELError(uVar8,iVar2);
      return iVar2;
    }
    if ((*(uint *)((longlong)puVar10 + 0x24) & 2) == 0) {
      pcVar9 = (code *)puVar10[5];
      iVar2 = (*pcVar9)(0,lVar7);
      lVar7 = 0;
      if (-1 < iVar2) {
        if (DAT_18001c444 != 0x3001) goto LAB_180007720;
        iVar2 = -0x3fffffff;
      }
      uVar8 = 0x60001;
      _DAT_18001c420 = pcVar9;
      goto LAB_1800079ab;
    }
LAB_180007720:
    puVar10 = (undefined8 *)*puVar10;
  } while( true );
}



===== IsStorageRelatedCrash @ 1800079d4 =====

longlong IsStorageRelatedCrash(longlong param_1)

{
  uint7 uVar2;
  longlong lVar1;
  int *piVar3;
  
  lVar1 = 0;
  piVar3 = (int *)(param_1 + 0x710);
  while( true ) {
    uVar2 = (uint7)((ulonglong)lVar1 >> 8);
    if (7 < lVar1) {
      return (ulonglong)uVar2 << 8;
    }
    if (*piVar3 == *(int *)KiBugCheckData_exref) break;
    lVar1 = lVar1 + 1;
    piVar3 = piVar3 + 1;
  }
  return CONCAT71(uVar2,1);
}



===== LoadFilterDrivers @ 180007a08 =====

ulonglong LoadFilterDrivers(longlong param_1,longlong param_2)

{
  code *pcVar1;
  longlong *plVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong *plVar5;
  longlong *plVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  short *psVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong *local_res18;
  undefined1 auStackY_d8 [8];
  undefined1 auStackY_d0 [24];
  undefined8 local_a8;
  short *psStack_a0;
  undefined1 local_98 [8];
  undefined4 local_90;
  wchar_t *local_88;
  undefined8 *local_80;
  undefined4 local_78;
  
  local_res18 = (longlong *)0x0;
  local_a8 = 0;
  psStack_a0 = (short *)0x0;
  RtlInitUnicodeString(&local_a8);
  memset(local_98,0,0x70);
  local_90 = 0x134;
  local_88 = L"DumpFilters";
  local_80 = &local_a8;
  local_78 = 0x7000000;
  uVar3 = RtlQueryRegistryValuesEx
                    (0,L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl",
                     local_98);
  puVar7 = auStackY_d8;
  plVar6 = (longlong *)(ulonglong)uVar3;
  if ((int)uVar3 < 0) {
    RtlFreeUnicodeString(&local_a8);
    uVar4 = 0;
  }
  else {
    psVar9 = psStack_a0;
    while (puVar8 = auStackY_d8, *psVar9 != 0) {
      lVar10 = -1;
      do {
        lVar10 = lVar10 + 1;
      } while (psVar9[lVar10] != 0);
      plVar5 = (longlong *)ExAllocatePool2(0x40,200,0x706d4443);
      if (plVar5 == (longlong *)0x0) {
        plVar6 = (longlong *)0xc000009a;
        puVar8 = auStackY_d8;
        break;
      }
      uVar3 = CrashdmpLoadDriver(param_2,*(undefined8 *)(param_1 + 0x120),psVar9,(undefined8 *)0x0,
                                 (short *)0x0,(longlong *)&local_res18);
      plVar2 = local_res18;
      plVar6 = (longlong *)(ulonglong)uVar3;
      plVar11 = plVar5;
      if ((int)uVar3 < 0) {
LAB_180007bad:
        *(undefined8 *)(puVar7 + -8) = 0x180007bb9;
        ExFreePoolWithTag(plVar11,0);
        puVar8 = puVar7;
        break;
      }
      *(uint *)((longlong)local_res18 + 0x24) = *(uint *)((longlong)local_res18 + 0x24) | 2;
      uVar3 = DumpPreInitialize(local_res18[3]);
      plVar6 = *(longlong **)(param_1 + 0x130);
      if (*plVar6 != param_1 + 0x128) {
LAB_180007ba6:
        pcVar1 = (code *)swi(0x29);
        (*pcVar1)(3);
        puVar7 = auStackY_d0;
        plVar6 = plVar2;
        goto LAB_180007bad;
      }
      *plVar2 = param_1 + 0x128;
      plVar2[1] = (longlong)plVar6;
      *plVar6 = (longlong)plVar2;
      *(longlong **)(param_1 + 0x130) = plVar2;
      plVar5[0x17] = param_1;
      plVar5[0x18] = (longlong)plVar2;
      plVar11 = plVar5 + 0x14;
      plVar6 = *(longlong **)(param_1 + 0x288);
      if (*plVar6 != param_1 + 0x280) goto LAB_180007ba6;
      *plVar11 = param_1 + 0x280;
      psVar9 = psVar9 + ((int)lVar10 + 1);
      plVar5[0x15] = (longlong)plVar6;
      *plVar6 = (longlong)plVar11;
      plVar6 = (longlong *)0x0;
      if (-1 < (int)uVar3) {
        plVar6 = (longlong *)(ulonglong)uVar3;
      }
      *(longlong **)(param_1 + 0x288) = plVar11;
    }
    *(undefined8 *)(puVar8 + -8) = 0x180007bd0;
    RtlFreeUnicodeString(&local_a8);
    uVar4 = (ulonglong)plVar6 & 0xffffffff;
  }
  return uVar4;
}



===== LoadPortDriver @ 180007c00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong LoadPortDriver(longlong param_1,longlong param_2)

{
  byte bVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong *plVar8;
  undefined1 *puVar9;
  code *pcVar10;
  code *pcVar11;
  code *pcVar12;
  longlong *plVar13;
  code *local_res8;
  longlong local_res10;
  longlong *local_res18;
  code *local_res20;
  undefined1 auStackY_98 [8];
  undefined1 auStackY_90 [24];
  undefined8 local_68;
  longlong lStack_60;
  undefined8 local_58;
  
  puVar9 = auStackY_98;
  pcVar12 = (code *)0x0;
  local_58 = 0;
  plVar7 = (longlong *)0x0;
  local_res8 = (code *)0x0;
  local_res18 = (longlong *)0x0;
  bVar1 = 0;
  pcVar10 = (code *)0x0;
  local_68 = 0;
  lStack_60 = 0;
  local_res10 = param_2;
  if (*(int *)(param_1 + 0x178) == 2) {
    plVar8 = (longlong *)(param_1 + 0x1b8);
    plVar13 = (longlong *)*plVar8;
    if (plVar13 != plVar8) {
      local_res20 = (code *)(param_1 + 0x120);
      do {
        plVar6 = (longlong *)0x0;
        local_res18 = plVar13 + 0xf;
        if (*(uint *)(plVar13 + -1) < 0x81) {
          local_res18 = plVar6;
        }
        if (*(uint *)(plVar13 + -1) < 0x91) {
          pcVar12 = local_res20;
        }
        else {
          plVar6 = plVar13 + 0x11;
          pcVar12 = (code *)(param_1 + 0x120);
        }
        local_res20 = pcVar12;
        if (plVar13[5] != 0) {
          uVar2 = CrashdmpLoadDriver(local_res10,*(longlong *)pcVar12,plVar13[5],plVar6,
                                     (short *)plVar13[6],(longlong *)&local_res8);
          pcVar10 = local_res8;
          pcVar11 = (code *)(ulonglong)uVar2;
          if ((int)uVar2 < 0) {
            if (uVar2 != 0xc000010e) goto LAB_180007db1;
          }
          else {
            if (DAT_18001c444 == 0x8000) {
              pcVar11 = (code *)0xc0000001;
LAB_180007db1:
              _DAT_18001c420 = CrashdmpLoadDriver;
              goto LAB_180007ef3;
            }
            DumpPreInitialize(*(longlong *)(local_res8 + 0x18));
            plVar6 = *(longlong **)(param_1 + 0x130);
            if (*plVar6 != param_1 + 0x128) goto LAB_1800080a2;
            *(longlong *)pcVar10 = param_1 + 0x128;
            *(longlong **)(pcVar10 + 8) = plVar6;
            *plVar6 = (longlong)pcVar10;
            *(code **)(param_1 + 0x130) = pcVar10;
          }
        }
        uVar2 = CrashdmpLoadDriver(local_res10,*(longlong *)pcVar12,plVar13[3],local_res18,
                                   (short *)plVar13[4],(longlong *)&local_res8);
        pcVar12 = local_res8;
        pcVar11 = (code *)(ulonglong)uVar2;
        if ((int)uVar2 < 0) {
          _DAT_18001c420 = CrashdmpLoadDriver;
          pcVar12 = (code *)0x0;
          _DAT_18001c43c = uVar2;
          goto LAB_1800080c9;
        }
        plVar13[0xe] = (longlong)local_res8;
        uVar2 = DumpPreInitialize(*(longlong *)(local_res8 + 0x18));
        pcVar10 = (code *)0x0;
        if (-1 < (int)uVar2) {
          pcVar10 = (code *)(ulonglong)uVar2;
        }
        plVar6 = *(longlong **)(param_1 + 0x130);
        if (*plVar6 != param_1 + 0x128) goto LAB_1800080a2;
        *(longlong *)pcVar12 = param_1 + 0x128;
        *(longlong **)(pcVar12 + 8) = plVar6;
        *plVar6 = (longlong)pcVar12;
        *(code **)(param_1 + 0x130) = pcVar12;
        plVar13 = (longlong *)*plVar13;
      } while (plVar13 != plVar8);
    }
    plVar13 = (longlong *)*plVar8;
    pcVar11 = pcVar10;
    if (plVar13 != plVar8) {
LAB_180007dcf:
      local_res8 = *(code **)(plVar13[0xe] + 0x28);
      uVar2 = (*local_res8)(0,plVar13 + -1);
      pcVar11 = (code *)(ulonglong)uVar2;
      if ((int)uVar2 < 0) {
        _DAT_18001c420 = local_res8;
LAB_180007ef3:
        puVar9 = auStackY_98;
        pcVar12 = (code *)0x0;
        _DAT_18001c43c = (uint)pcVar11;
      }
      else {
        if ((plVar13[0xc] != 0) && (plVar13[10] != 0)) goto code_r0x000180007e04;
        pcVar11 = (code *)0xc0000001;
        _DAT_18001c420 = (code *)0x0;
        _DAT_18001c43c = 0xc0000001;
        puVar9 = auStackY_98;
        pcVar12 = (code *)0x0;
      }
      goto LAB_1800080c9;
    }
LAB_180007e0f:
    pcVar12 = (code *)0x0;
    lVar4 = *(longlong *)(param_1 + 400);
    *(undefined8 *)(param_1 + 0x1f0) = *(undefined8 *)(*(longlong *)(lVar4 + 0x40) + 0x50);
    *(undefined8 *)(param_1 + 0x1f8) = *(undefined8 *)(*(longlong *)(lVar4 + 0x40) + 0x58);
    *(undefined8 *)(param_1 + 0x200) = *(undefined8 *)(*(longlong *)(lVar4 + 0x40) + 0x60);
    *(undefined8 *)(param_1 + 0x208) = *(undefined8 *)(*(longlong *)(lVar4 + 0x40) + 0x68);
    uVar3 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar3 != 0) {
      *(undefined8 *)(param_1 + 0x210) =
           *(undefined8 *)(*(longlong *)(*(longlong *)(param_1 + 400) + 0x40) + 0xa0);
      *(undefined8 *)(param_1 + 0x218) =
           *(undefined8 *)(*(longlong *)(*(longlong *)(param_1 + 400) + 0x40) + 0xa8);
    }
    if ((DAT_18001bd60._2_1_ & 1) != 0) {
      if ((*(byte *)(DAT_18001c4f0 + 10) & 5) == 0) {
        lVar4 = MmMapLockedPagesSpecifyCache(DAT_18001c4f0,0,1,0);
      }
      else {
        lVar4 = *(longlong *)(DAT_18001c4f0 + 0x18);
      }
      local_68 = CONCAT44(local_68._4_4_,0x18);
      lStack_60 = (ulonglong)*(uint *)(lVar4 + 0x84) + lVar4;
      local_58 = CONCAT44(local_58._4_4_,*(undefined4 *)(lVar4 + 0x88));
      uVar2 = (**(code **)(param_1 + 0x208))(*(undefined8 *)(param_1 + 400),10,&local_68);
      pcVar11 = (code *)(ulonglong)uVar2;
      if (-1 < (int)uVar2) goto LAB_1800080f7;
      _DAT_18001c420 = *(code **)(param_1 + 0x208);
      puVar9 = auStackY_98;
      _DAT_18001c43c = uVar2;
      goto LAB_1800080c9;
    }
  }
  else {
    if (*(int *)(param_1 + 0x178) == 1) {
      plVar8 = *(longlong **)(param_1 + 0x1a8);
      pcVar11 = pcVar10;
    }
    else {
      uVar3 = GetLegacyPortDriverName(param_1 + 0x180,(uint)*(byte *)(param_1 + 0x238),&local_res18)
      ;
      puVar9 = auStackY_98;
      pcVar11 = (code *)(uVar3 & 0xffffffff);
      if ((int)(uint)uVar3 < 0) {
        _DAT_18001c420 = GetLegacyPortDriverName;
        plVar7 = local_res18;
        _DAT_18001c43c = (uint)uVar3;
        goto LAB_1800080c9;
      }
      plVar8 = local_res18;
    }
    if ((((*(int *)(param_1 + 0x178) == 1) && (2 < *(uint *)(param_1 + 0x180))) &&
        (0x57 < *(uint *)(param_1 + 0x184))) && ((*(byte *)(param_1 + 0x1b0) & 8) != 0)) {
      bVar1 = 1;
    }
    while (puVar9 = auStackY_98, plVar8 != (longlong *)0x0) {
      plVar7 = (longlong *)*plVar8;
      uVar2 = CrashdmpLoadDriver(local_res10,*(undefined8 *)(param_1 + 0x120),plVar8 + 1,
                                 (undefined8 *)(-(ulonglong)bVar1 & (ulonglong)(plVar8 + 9)),
                                 (short *)((longlong)plVar8 + 0x26),(longlong *)&local_res8);
      pcVar11 = (code *)(ulonglong)uVar2;
      if (plVar8 != (longlong *)0x0) {
        ExFreePoolWithTag(plVar8,0);
      }
      pcVar10 = local_res8;
      if ((int)uVar2 < 0) goto LAB_1800080a9;
      *(uint *)(local_res8 + 0x24) = *(uint *)(local_res8 + 0x24) | 1;
      uVar2 = DumpPreInitialize(*(longlong *)(local_res8 + 0x18));
      plVar8 = *(longlong **)(param_1 + 0x130);
      if (*plVar8 != param_1 + 0x128) goto LAB_1800080a2;
      *(longlong *)pcVar10 = param_1 + 0x128;
      *(longlong **)(pcVar10 + 8) = plVar8;
      *plVar8 = (longlong)pcVar10;
      *(code **)(param_1 + 0x130) = pcVar10;
      pcVar11 = (code *)0x0;
      plVar8 = plVar7;
      if (-1 < (int)uVar2) {
        pcVar11 = (code *)(ulonglong)uVar2;
      }
    }
  }
  pcVar12 = (code *)0x0;
  plVar7 = (longlong *)0x0;
  puVar9 = auStackY_98;
  if (-1 < (int)pcVar11) goto LAB_1800080f7;
  goto LAB_1800080c9;
code_r0x000180007e04:
  plVar13 = (longlong *)*plVar13;
  if (plVar13 == plVar8) goto LAB_180007e0f;
  goto LAB_180007dcf;
LAB_1800080a2:
  pcVar11 = (code *)swi(0x29);
  (*pcVar11)(3);
  puVar9 = auStackY_90;
  pcVar11 = pcVar10;
LAB_1800080a9:
  _DAT_18001c420 = CrashdmpLoadDriver;
  _DAT_18001c43c = (uint)pcVar11;
LAB_1800080c9:
  *(undefined8 *)(puVar9 + -8) = 0x1800080d6;
  CrashdmpLogSELEarlyError();
  if (*(int *)(param_1 + 0x178) == 2) {
    for (puVar5 = *(undefined8 **)(param_1 + 0x1b8); puVar5 != (undefined8 *)(param_1 + 0x1b8);
        puVar5 = (undefined8 *)*puVar5) {
      puVar5[0xe] = pcVar12;
    }
  }
  else {
    while (plVar7 != (longlong *)0x0) {
      plVar8 = (longlong *)*plVar7;
      *(undefined8 *)(puVar9 + -8) = 0x18000812f;
      ExFreePoolWithTag(plVar7,0);
      plVar7 = plVar8;
    }
  }
LAB_1800080f7:
  if (*(int *)(param_1 + 0x178) == 1) {
    *(code **)(param_1 + 0x1a8) = pcVar12;
  }
  return (ulonglong)pcVar11 & 0xffffffff;
}



===== McTemplateK0txxxq_EtwWriteTransfer @ 18000813c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0txxxq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_68 = local_res20;
  local_60 = 4;
  local_58 = &param_5;
  local_50 = 8;
  local_48 = &param_6;
  local_40 = 8;
  local_38 = &param_7;
  local_28 = &param_8;
  local_30 = 8;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&EventCreateDumpFile,param_3,6,local_78);
  return;
}



===== QueryDumpInfo @ 1800081e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int QueryDumpInfo(longlong param_1,undefined4 *param_2)

{
  longlong *plVar1;
  undefined8 *puVar2;
  byte *pbVar3;
  undefined4 *_Dst;
  longlong lVar4;
  code *pcVar5;
  bool bVar6;
  int iVar7;
  longlong *plVar8;
  undefined8 *puVar9;
  longlong *plVar10;
  undefined8 *puVar11;
  char cVar12;
  int local_res8;
  int local_res10;
  int local_res18;
  undefined4 local_res20 [2];
  
  *(undefined4 *)(param_1 + 0x178) = 2;
  _Dst = (undefined4 *)(param_1 + 0x180);
  *param_2 = 0;
  local_res8 = 0;
  local_res20[0] = 0;
  local_res18 = 0;
  local_res10 = 0;
  memset(_Dst,0,0x48);
  *_Dst = 0x48;
  plVar1 = (longlong *)(param_1 + 0x1a8);
  *(longlong **)(param_1 + 0x1b0) = plVar1;
  puVar2 = (undefined8 *)(param_1 + 0x198);
  *plVar1 = (longlong)plVar1;
  puVar9 = (undefined8 *)(param_1 + 0x1b8);
  *(undefined8 **)(param_1 + 0x1a0) = puVar2;
  *puVar2 = puVar2;
  *(undefined8 **)(param_1 + 0x1c0) = puVar9;
  *puVar9 = puVar9;
  *(uint *)(param_1 + 0x184) = (*(int *)(param_1 + 0x170) != 3) + 1;
  iVar7 = SendDeviceControl(0x2d164b,*(undefined8 *)(param_1 + 0x278),_Dst,0x48,0,0,local_res20);
  if (iVar7 < 0) {
    *param_2 = 1;
  }
  else {
    lVar4 = *(longlong *)(param_1 + 400);
    if (((lVar4 == 0) || (*(longlong *)(lVar4 + 0x40) == 0)) ||
       (pcVar5 = *(code **)(*(longlong *)(lVar4 + 0x40) + 0x18), pcVar5 == (code *)0x0)) {
      iVar7 = -0x3fffff45;
    }
    else {
      iVar7 = (*pcVar5)(lVar4,2,_Dst);
      if (-1 < iVar7) {
        plVar10 = (longlong *)*plVar1;
        cVar12 = '\x01';
        plVar8 = plVar10;
        if (plVar10 != plVar1) {
          do {
            if ((*(uint *)(plVar8 + 4) & 2) == 0) {
              cVar12 = '\0';
              break;
            }
            plVar8 = (longlong *)*plVar8;
          } while (plVar8 != plVar1);
          do {
            if ((*(uint *)(plVar10 + 4) >> 0x1e & 1) != 0) {
              DAT_18001bd60 = DAT_18001bd60 | 0x4000000;
              break;
            }
            if ((int)*(uint *)(plVar10 + 4) < 0) {
              DAT_18001bd60 = DAT_18001bd60 | 0x8000000;
              break;
            }
            plVar10 = (longlong *)*plVar10;
          } while (plVar10 != plVar1);
        }
        *(char *)(param_1 + 0x230) = cVar12;
        if (cVar12 == '\0') {
          *(uint *)(param_1 + 0x290) = *(uint *)(param_1 + 0x290) | 4;
        }
        for (plVar8 = (longlong *)*plVar1; plVar8 != plVar1; plVar8 = (longlong *)*plVar8) {
          local_res8 = local_res8 + 1;
        }
        puVar11 = (undefined8 *)*puVar9;
        bVar6 = false;
        while (puVar11 != puVar9) {
          local_res10 = local_res10 + 1;
          pbVar3 = (byte *)(puVar11 + 7);
          puVar11 = (undefined8 *)*puVar11;
          if ((*pbVar3 & 1) != 0) {
            bVar6 = true;
          }
        }
        for (puVar9 = (undefined8 *)*puVar2; puVar9 != puVar2; puVar9 = (undefined8 *)*puVar9) {
          local_res18 = local_res18 + 1;
        }
        if (((local_res8 == 1) && (local_res10 == 1)) && ((local_res18 == 1 && (bVar6)))) {
          *(undefined1 *)(param_1 + 0x231) = 1;
        }
        *(undefined4 **)(param_1 + 0x110) = _Dst;
        *(undefined1 *)(param_1 + 0x118) = 1;
        return iVar7;
      }
      *param_2 = 2;
    }
  }
  FreeDumpInfo(param_1);
  return iVar7;
}



===== QueryDumpPointers @ 1800083fc =====

int QueryDumpPointers(longlong param_1)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  ulonglong uVar4;
  bool bVar5;
  bool bVar6;
  undefined4 local_res8 [2];
  
  local_res8[0] = 0;
  puVar2 = (uint *)(param_1 + 0x180);
  memset((void *)(param_1 + 0x188),0,0x60);
  *puVar2 = 2;
  *(undefined4 *)(param_1 + 0x184) = 0x30;
  iVar3 = SendDeviceControl(0x41020,*(undefined8 *)(param_1 + 0x278),puVar2,8,puVar2,0x68,local_res8
                           );
  if (-1 < iVar3) {
    if ((*puVar2 - 2 < 3) && (*(int *)(param_1 + 0x184) - 0x30U < 0x39)) {
      *(uint **)(param_1 + 0x110) = puVar2;
      *(undefined4 *)(param_1 + 0x178) = 1;
      *(undefined1 *)(param_1 + 0x118) = 0;
      *(undefined4 *)(param_1 + 0x11c) = 0x68;
      if (2 < *puVar2) {
        if (0x40000 < *(uint *)(param_1 + 0x1b4)) {
          *(undefined4 *)(param_1 + 0x1b4) = 0x40000;
        }
        bVar5 = (*(uint *)(param_1 + 0x1b0) & 4) != 0;
        if (!bVar5) {
          *(uint *)(param_1 + 0x290) = *(uint *)(param_1 + 0x290) | 4;
        }
        *(bool *)(param_1 + 0x230) = bVar5;
        uVar4 = Feature_CrashDumpOneMBTransferSize__private_IsEnabledDeviceUsageNoInline();
        uVar1 = *(int *)(param_1 + 0x1bc) - 0x200;
        if ((int)uVar4 == 0) {
          bVar5 = uVar1 < 0xfe00;
          bVar6 = uVar1 == 0xfe00;
        }
        else {
          bVar5 = uVar1 < 0xffe00;
          bVar6 = uVar1 == 0xffe00;
        }
        if (bVar5 || bVar6) {
          *(int *)(param_1 + 0x2d4) = *(int *)(param_1 + 0x1bc);
          return iVar3;
        }
        return iVar3;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x178) = 0;
      *(uint **)(param_1 + 0x110) = puVar2;
      *(undefined1 *)(param_1 + 0x118) = 0;
      *(undefined4 *)(param_1 + 0x11c) = 0x38;
    }
    *(uint *)(param_1 + 0x290) = *(uint *)(param_1 + 0x290) | 4;
    *(undefined1 *)(param_1 + 0x230) = 0;
  }
  return iVar3;
}



===== QueryPortDriver @ 180008560 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong QueryPortDriver(undefined4 *param_1,undefined8 param_2,undefined8 param_3,
                         undefined8 param_4)

{
  undefined4 *puVar1;
  longlong *plVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  ulonglong uVar13;
  undefined4 *puVar14;
  void *pvVar15;
  undefined4 *puVar16;
  longlong lVar17;
  ulonglong uVar18;
  undefined1 *puVar19;
  undefined1 *puVar20;
  undefined8 uVar21;
  longlong lVar22;
  uint uVar23;
  longlong lVar24;
  undefined1 auStackY_1a8 [8];
  undefined1 auStackY_1a0 [24];
  byte local_168 [4];
  uint local_164;
  uint local_160 [4];
  undefined4 local_150;
  undefined4 local_14c;
  code *local_148;
  undefined1 local_138 [8];
  undefined8 local_130;
  undefined8 local_a8;
  uint local_a0;
  undefined8 local_98 [4];
  uint *local_78;
  undefined8 local_70;
  uint *local_68;
  undefined8 local_60;
  uint *local_58;
  undefined8 local_50;
  byte *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_1a8;
  local_164 = 0;
  uVar21 = 0x90;
  local_160[0] = 0;
  memset(local_138,0,0x90);
  local_160[1] = 0;
  local_a8 = 0;
  local_a0 = 0;
  if ((DAT_18001bd60 & 0x10000) == 0) {
    uVar8 = IsVolumeSupported(*(undefined8 *)(param_1 + 0x9e),*(longlong *)(param_1 + 0x5a));
    puVar19 = auStackY_1a8;
    uVar18 = (ulonglong)uVar8;
    if (-1 < (int)uVar8) {
      puVar12 = param_1;
      uVar9 = QueryDumpPointers((longlong)param_1);
      uVar8 = 0;
      uVar23 = 0;
      uVar10 = uVar9;
      if ((int)uVar9 < 0) {
        puVar12 = param_1;
        uVar10 = QueryDumpInfo((longlong)param_1,local_160);
        uVar8 = local_160[0];
        uVar23 = uVar9;
      }
      puVar19 = auStackY_1a8;
      uVar18 = (ulonglong)uVar10;
      if ((int)uVar10 < 0) {
        if (5 < DAT_18001b048) {
          uVar13 = _tlgKeywordOn(puVar12,0x400000000000);
          puVar19 = auStackY_1a8;
          if ((char)uVar13 != '\0') {
            local_78 = local_160;
            local_70 = 4;
            local_60 = 4;
            local_164 = 0;
            if (uVar8 == 1) {
              local_164 = uVar10;
            }
            local_50 = 4;
            local_68 = &local_164;
            local_40 = 1;
            local_160[2] = 0;
            if (uVar8 == 2) {
              local_160[2] = uVar10;
            }
            local_58 = local_160 + 2;
            local_168[0] = (byte)(DAT_18001bd60 >> 10) & 1;
            local_48 = local_168;
            local_160[0] = uVar23;
            _tlgWriteTransfer_EtwWriteTransfer(puVar12,&DAT_180019014,uVar21,param_4,6,local_98);
            puVar19 = auStackY_1a8;
          }
        }
      }
      else {
        if (param_1[0xb4] == 0) {
          param_1[0xb4] = 0x1000;
        }
        uVar18 = Feature_CrashDumpOneMBTransferSize__private_IsEnabledDeviceUsageNoInline();
        uVar8 = param_1[0xb5];
        if ((int)uVar18 == 0) {
          if (uVar8 == 0) {
            param_1[0xb5] = 0x10000;
          }
        }
        else {
          uVar23 = DAT_18001c5b0;
          if ((uVar8 != 0) && (uVar8 < DAT_18001c5b0)) {
            uVar23 = uVar8;
          }
          param_1[0xb5] = uVar23;
        }
        if ((uint)param_1[0x5e] < 2) {
          uVar8 = SendDeviceControl(0x41018,*(undefined8 *)(param_1 + 0x9e),0,0,param_1 + 0x8d,8,
                                    &local_164);
          puVar19 = auStackY_1a8;
          uVar18 = (ulonglong)uVar8;
          if ((int)uVar8 < 0) goto LAB_1800086fc;
        }
        uVar8 = SendDeviceControl(0x70048,*(undefined8 *)(param_1 + 0x9e),0,0,local_138,0x90,
                                  &local_164);
        puVar19 = auStackY_1a8;
        uVar18 = (ulonglong)uVar8;
        if (-1 < (int)uVar8) {
          *(undefined8 *)(param_1 + 0x42) = local_130;
          uVar8 = SendDeviceControl(0x700a0,*(undefined8 *)(param_1 + 0x9e),0,0,param_1 + 0x90,0x38,
                                    &local_164);
          puVar19 = auStackY_1a8;
          uVar18 = (ulonglong)uVar8;
          if (-1 < (int)uVar8) {
            DAT_18001bd60 = DAT_18001bd60 | 0x4000;
            local_a8 = 7;
            iVar11 = SendDeviceControl(0x2d1400,*(undefined8 *)(param_1 + 0x9e),&local_a8,0xc,
                                       &local_a8,0xc,&local_164);
            if (-1 < iVar11) {
              DAT_18001bd60 = (local_a0 & 1) << 0xe | DAT_18001bd60 & 0xffffbfff;
            }
            uVar13 = FillDumpInitContext(param_1);
            puVar19 = auStackY_1a8;
            uVar18 = uVar13 & 0xffffffff;
            if (-1 < (int)uVar13) {
              local_148 = CrashdmpDumpNotification;
              local_150 = 1;
              local_14c = 0x10;
              uVar8 = SendDeviceControl(0x2d5644,*(undefined8 *)(param_1 + 0x9e),&local_150,0x10,0,0
                                        ,&local_164);
              uVar18 = (ulonglong)uVar8;
              puVar20 = auStackY_1a8;
              if ((int)uVar8 < 0) {
                uVar18 = 0;
                puVar20 = auStackY_1a8;
              }
              goto LAB_180008704;
            }
          }
        }
      }
    }
  }
  else {
    if ((*(byte *)(DAT_18001c4f0 + 10) & 5) == 0) {
      lVar22 = MmMapLockedPagesSpecifyCache(DAT_18001c4f0,0,1,0);
    }
    else {
      lVar22 = *(longlong *)(DAT_18001c4f0 + 0x18);
    }
    puVar19 = auStackY_1a8;
    param_1[0x5e] = *(undefined4 *)(lVar22 + 8);
    DAT_18001bd60 = (*(uint *)(lVar22 + 0x20) & 1) << 0xe | DAT_18001bd60 & 0xffffbfff;
    *(undefined8 *)(param_1 + 0x8d) = *(undefined8 *)(lVar22 + 0x28);
    *(undefined8 *)(param_1 + 0x42) = *(undefined8 *)(lVar22 + 0x30);
    uVar21 = *(undefined8 *)(lVar22 + 0x40);
    *(undefined8 *)(param_1 + 0x90) = *(undefined8 *)(lVar22 + 0x38);
    *(undefined8 *)(param_1 + 0x92) = uVar21;
    uVar21 = *(undefined8 *)(lVar22 + 0x50);
    *(undefined8 *)(param_1 + 0x94) = *(undefined8 *)(lVar22 + 0x48);
    *(undefined8 *)(param_1 + 0x96) = uVar21;
    uVar5 = *(undefined4 *)(lVar22 + 0x5c);
    uVar6 = *(undefined4 *)(lVar22 + 0x60);
    uVar7 = *(undefined4 *)(lVar22 + 100);
    param_1[0x98] = *(undefined4 *)(lVar22 + 0x58);
    param_1[0x99] = uVar5;
    param_1[0x9a] = uVar6;
    param_1[0x9b] = uVar7;
    *(undefined8 *)(param_1 + 0x9c) = *(undefined8 *)(lVar22 + 0x68);
    param_1[0xb4] = *(undefined4 *)(lVar22 + 0x70);
    param_1[0xb5] = *(undefined4 *)(lVar22 + 0x74);
    if (param_1[0x5e] == 2) {
      param_1[0x61] = 1;
      puVar12 = param_1 + 0x6a;
      puVar1 = param_1 + 0x66;
      param_1[0x60] = 0x48;
      puVar14 = param_1 + 0x6e;
      *(undefined4 **)(param_1 + 0x68) = puVar1;
      *(undefined4 **)puVar1 = puVar1;
      *(undefined4 **)(param_1 + 0x6c) = puVar12;
      *(undefined4 **)puVar12 = puVar12;
      *(undefined4 **)(param_1 + 0x70) = puVar14;
      *(undefined4 **)puVar14 = puVar14;
      lVar24 = (ulonglong)*(uint *)(lVar22 + 0x78) + lVar22;
      puVar12 = (undefined4 *)ExAllocatePool2(0x40,0xb0,0x706d4443);
      if (puVar12 == (undefined4 *)0x0) goto LAB_1800086f7;
      *puVar12 = 0xb0;
      puVar12[0x10] = *(uint *)(lVar24 + 0x10) | 2;
      if (*(uint *)(lVar24 + 0x18) != 0) {
        uVar13 = DuplicateString((void *)(lVar24 + (ulonglong)*(uint *)(lVar24 + 0x18)),
                                 (undefined8 *)(puVar12 + 0xc));
        puVar19 = auStackY_1a8;
        uVar18 = uVar13 & 0xffffffff;
        if ((int)uVar13 < 0) goto LAB_1800086fc;
      }
      if (*(uint *)(lVar24 + 0x1c) != 0) {
        uVar13 = DuplicateString((void *)(lVar24 + (ulonglong)*(uint *)(lVar24 + 0x1c)),
                                 (undefined8 *)(puVar12 + 0xe));
        puVar19 = auStackY_1a8;
        uVar18 = uVar13 & 0xffffffff;
        if ((int)uVar13 < 0) goto LAB_1800086fc;
      }
      if (*(uint *)(lVar24 + 0x24) != 0) {
        uVar13 = DuplicateString((void *)(lVar24 + (ulonglong)*(uint *)(lVar24 + 0x24)),
                                 (undefined8 *)(puVar12 + 10));
        puVar19 = auStackY_1a8;
        uVar18 = uVar13 & 0xffffffff;
        if ((int)uVar13 < 0) goto LAB_1800086fc;
      }
      if (*(uint *)(lVar24 + 0x20) != 0) {
        uVar13 = DuplicateString((void *)(lVar24 + (ulonglong)*(uint *)(lVar24 + 0x20)),
                                 (undefined8 *)(puVar12 + 8));
        puVar19 = auStackY_1a8;
        uVar18 = uVar13 & 0xffffffff;
        if ((int)uVar13 < 0) goto LAB_1800086fc;
      }
      iVar11 = *(int *)(lVar24 + 0x14);
      puVar12[0x11] = iVar11;
      if (iVar11 != 0) {
        lVar24 = ExAllocatePool2(0x40,iVar11,0x706d4443);
        *(longlong *)(puVar12 + 0x12) = lVar24;
        if (lVar24 != 0) goto LAB_1800087ed;
LAB_1800087e3:
        puVar19 = auStackY_1a8;
        uVar18 = 0xc0000017;
        goto LAB_1800086fc;
      }
LAB_1800087ed:
      *(undefined4 **)(puVar12 + 0x1c) = param_1 + 0x60;
      plVar2 = (longlong *)(puVar12 + 2);
      plVar3 = *(longlong **)(param_1 + 0x70);
      if ((undefined4 *)*plVar3 == puVar14) {
        *plVar2 = (longlong)puVar14;
        *(longlong **)(puVar12 + 4) = plVar3;
        *plVar3 = (longlong)plVar2;
        *(longlong **)(param_1 + 0x70) = plVar2;
        lVar24 = (ulonglong)*(uint *)(lVar22 + 0x7c) + lVar22;
        puVar14 = (undefined4 *)ExAllocatePool2(0x40,0x70,0x706d4443);
        if (puVar14 == (undefined4 *)0x0) {
LAB_1800086f7:
          puVar19 = auStackY_1a8;
          uVar18 = 0xc000009a;
          goto LAB_1800086fc;
        }
        *puVar14 = 0x70;
        uVar5 = *(undefined4 *)(lVar24 + 0x18);
        uVar6 = *(undefined4 *)(lVar24 + 0x1c);
        uVar7 = *(undefined4 *)(lVar24 + 0x20);
        puVar14[6] = *(undefined4 *)(lVar24 + 0x14);
        puVar14[7] = uVar5;
        puVar14[8] = uVar6;
        puVar14[9] = uVar7;
        puVar14[10] = *(undefined4 *)(lVar24 + 0x10);
        puVar14[0x12] = *(undefined4 *)(lVar24 + 0x24);
        iVar11 = *(int *)(lVar24 + 0x28);
        puVar14[0xb] = iVar11;
        if (iVar11 != 0) {
          pvVar15 = (void *)ExAllocatePool2(0x40,iVar11,0x706d4443);
          *(void **)(puVar14 + 0xc) = pvVar15;
          if (pvVar15 == (void *)0x0) goto LAB_1800087e3;
          memcpy(pvVar15,(void *)((ulonglong)*(uint *)(lVar24 + 0x2c) + lVar24),
                 (ulonglong)(uint)puVar14[0xb]);
        }
        if (*(int *)(lVar24 + 0x34) != 0) {
          lVar17 = 0;
          if (*(int *)(lVar24 + 0x3c) != 0) {
            lVar17 = (ulonglong)*(uint *)(lVar24 + 0x38) + lVar24;
          }
          lVar24 = IoGetDmaAdapter(lVar17,(ulonglong)*(uint *)(lVar24 + 0x30) + lVar24,local_160 + 1
                                  );
          puVar19 = auStackY_1a8;
          *(longlong *)(puVar14 + 0x10) = lVar24;
          if (lVar24 == 0) {
            uVar18 = 0xc00000c2;
            goto LAB_1800086fc;
          }
        }
        plVar3 = *(longlong **)(param_1 + 0x6c);
        plVar2 = (longlong *)(puVar14 + 2);
        if ((undefined4 *)*plVar3 == param_1 + 0x6a) {
          *plVar2 = (longlong)(param_1 + 0x6a);
          *(longlong **)(puVar14 + 4) = plVar3;
          *plVar3 = (longlong)plVar2;
          *(longlong **)(param_1 + 0x6c) = plVar2;
          lVar22 = (ulonglong)*(uint *)(lVar22 + 0x80) + lVar22;
          puVar16 = (undefined4 *)ExAllocatePool2(0x40,0x48,0x706d4443);
          if (puVar16 == (undefined4 *)0x0) goto LAB_1800086f7;
          *puVar16 = 0x48;
          uVar5 = *(undefined4 *)(lVar22 + 0x14);
          uVar6 = *(undefined4 *)(lVar22 + 0x18);
          uVar7 = *(undefined4 *)(lVar22 + 0x1c);
          puVar16[6] = *(undefined4 *)(lVar22 + 0x10);
          puVar16[7] = uVar5;
          puVar16[8] = uVar6;
          puVar16[9] = uVar7;
          puVar16[10] = *(undefined4 *)(lVar22 + 0xc);
          iVar11 = *(int *)(lVar22 + 0x20);
          puVar16[0xb] = iVar11;
          if (iVar11 != 0) {
            pvVar15 = (void *)ExAllocatePool2(0x40,iVar11,0x706d4443);
            *(void **)(puVar16 + 0xc) = pvVar15;
            if (pvVar15 == (void *)0x0) goto LAB_1800087e3;
            memcpy(pvVar15,(void *)((ulonglong)*(uint *)(lVar22 + 0x24) + lVar22),
                   (ulonglong)(uint)puVar16[0xb]);
          }
          plVar3 = *(longlong **)(param_1 + 0x68);
          plVar2 = (longlong *)(puVar16 + 2);
          if ((undefined4 *)*plVar3 == puVar1) {
            *(longlong **)(puVar16 + 4) = plVar3;
            *plVar2 = (longlong)puVar1;
            *plVar3 = (longlong)plVar2;
            *(longlong **)(param_1 + 0x68) = plVar2;
            *(undefined4 **)(puVar16 + 0xe) = puVar14;
            *(undefined4 **)(puVar16 + 0x10) = puVar12;
            *(undefined4 **)(puVar14 + 0xe) = puVar12;
            *(undefined4 **)(param_1 + 100) = puVar16;
            uVar13 = FillDumpInitContext(param_1);
            puVar19 = auStackY_1a8;
            puVar20 = auStackY_1a8;
            uVar18 = uVar13 & 0xffffffff;
            if (-1 < (int)uVar13) goto LAB_180008704;
            goto LAB_1800086fc;
          }
        }
      }
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      puVar19 = auStackY_1a0;
    }
    uVar18 = 0xc00000bb;
  }
LAB_1800086fc:
  *(undefined8 *)(puVar19 + -8) = 0x180008704;
  FreeDumpInfo((longlong)param_1);
  puVar20 = puVar19;
LAB_180008704:
  *(undefined8 *)(puVar20 + -8) = 0x180008712;
  return uVar18;
}



===== ReadOSBuildInfo @ 180008cd0 =====

void ReadOSBuildInfo(longlong param_1)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  undefined8 local_18;
  longlong lStack_10;
  
  puVar1 = (uint *)(param_1 + 0x20);
  *puVar1 = *puVar1 & 0xff87ffff;
  local_18 = 0x100000;
  lStack_10 = param_1 + 0x7b8;
  iVar2 = ReadRegString(L"\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion",
                        L"CurrentBuild",&local_18);
  if (iVar2 < 0) {
    *puVar1 = *puVar1 | 0x80000;
  }
  iVar2 = ReadRegULongKey(L"\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion",
                          L"UBR",param_1 + 0x7c8,0);
  if (iVar2 < 0) {
    *puVar1 = *puVar1 | 0x100000;
  }
  puVar3 = (uint *)(param_1 + 0x20);
  iVar2 = ReadRegULongKey(L"\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion",
                          L"CurrentMajorVersionNumber",param_1 + 0x7cc,0);
  if (iVar2 < 0) {
    *puVar3 = *puVar1 | 0x200000;
  }
  iVar2 = ReadRegULongKey(L"\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion",
                          L"CurrentMinorVersionNumber",param_1 + 2000,0);
  if (iVar2 < 0) {
    *puVar3 = *puVar3 | 0x400000;
  }
  return;
}



===== ReadRegistrySettings @ 180008dc4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint ReadRegistrySettings(longlong param_1)

{
  int iVar1;
  ulonglong uVar2;
  uint uVar3;
  longlong lVar4;
  uint uVar5;
  undefined1 auStack_98 [32];
  uint local_78 [4];
  wchar_t local_68 [32];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_98;
  local_78[0] = 0;
  ReadRegULongKey(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl",
                  L"CrashDumpEnabled",local_78,0);
  if (local_78[0] == 0) {
LAB_180008e5a:
    *(uint *)(param_1 + 0x18) = local_78[0];
  }
  else {
    if (local_78[0] == 1) {
      *(undefined4 *)(param_1 + 0x18) = 5;
      goto LAB_180008e5d;
    }
    if (local_78[0] != 2) {
      if (local_78[0] == 3) {
        *(undefined4 *)(param_1 + 0x18) = 4;
        goto LAB_180008e5d;
      }
      if (local_78[0] == 4) goto LAB_180008e5a;
      if (local_78[0] != 7) {
        *(undefined4 *)(param_1 + 0x18) = 0;
        goto LAB_180008e5d;
      }
    }
    *(undefined4 *)(param_1 + 0x18) = 6;
  }
LAB_180008e5d:
  iVar1 = ReadRegULongKey(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl",
                          L"LogEvent",local_78,0);
  if (((-1 < iVar1) && (local_78[0] != 0)) && (*(int *)(param_1 + 0x18) == 0)) {
    *(undefined4 *)(param_1 + 0x18) = 4;
  }
  iVar1 = ReadRegULongKey(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl",
                          L"SendAlert",local_78,0);
  if (((-1 < iVar1) && (local_78[0] != 0)) && (*(int *)(param_1 + 0x18) == 0)) {
    *(undefined4 *)(param_1 + 0x18) = 4;
  }
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x5b8) = *(undefined4 *)(param_1 + 0x18);
  iVar1 = ReadRegULongKey(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl",
                          L"ResumeCapable",local_78,0xffffffff);
  if ((iVar1 < 0) || (local_78[0] == 0xffffffff)) {
    DAT_18001c540 = 0xffffffff;
  }
  else {
    DAT_18001c540 = (uint)(local_78[0] == 1);
  }
  iVar1 = ReadRegULongKey(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl",
                          L"EnableLogFile",local_78,0);
  if ((iVar1 < 0) || ((*(uint *)(param_1 + 0x20) & 0x10000) != 0)) {
    DAT_18001c52b = false;
  }
  else {
    DAT_18001c52b = local_78[0] != 0;
  }
  iVar1 = ReadRegULongKey(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl",
                          L"DumpLogLevel",local_78,0);
  if (iVar1 < 0) {
    DAT_18001c544 = 0;
  }
  else {
    DAT_18001c544 = local_78[0];
    if (local_78[0] - 2 < 0xfffffffd) {
      DAT_18001c544 = 0;
    }
  }
  iVar1 = ReadRegULongKey(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl",
                          L"SimulateError",local_78,0);
  if (-1 < iVar1) {
    *(uint *)(param_1 + 0x704) = local_78[0];
  }
  iVar1 = ReadRegULongKey(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl",
                          L"SimulateNotReady",local_78,0);
  if ((-1 < iVar1) && (local_78[0] != 0)) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x10;
  }
  iVar1 = ReadRegULongKey(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl",
                          L"Flags",local_78,4);
  if (-1 < iVar1) {
    DAT_18001c548 = local_78[0];
  }
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x20;
  local_78[0] = 0;
  iVar1 = ReadRegULongKey(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl\\StorageTelemetry"
                          ,L"DeviceDumpEnabled",local_78,1);
  if (-1 < iVar1) {
    *(uint *)(param_1 + 0x20) =
         *(uint *)(param_1 + 0x20) & 0xffffffdf | -(uint)(local_78[0] != 0) & 0x20;
  }
  uVar5 = 0;
  lVar4 = 0x710;
  do {
    local_68[0] = L'\0';
    RtlStringCchPrintfW(local_68,0x20,L"StorageTCCode_%1x",(ulonglong)uVar5);
    iVar1 = ReadRegULongKey(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl\\StorageTelemetry"
                            ,local_68,local_78,0);
    uVar3 = 0;
    if (-1 < iVar1) {
      uVar3 = local_78[0];
    }
    uVar5 = uVar5 + 1;
    *(uint *)(lVar4 + param_1) = uVar3;
    lVar4 = lVar4 + 4;
  } while ((int)uVar5 < 8);
  *(uint *)(param_1 + 0x5d8) = *(uint *)(param_1 + 0x5d8) & 0xfffffffe;
  DAT_18001c318 = DAT_18001c318 & 0xfffffffd;
  iVar1 = ReadRegULongKey(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl",
                          L"FilterPages",local_78,0);
  if ((-1 < iVar1) && (local_78[0] != 0)) {
    DAT_18001c318 = DAT_18001c318 | 2;
  }
  iVar1 = ReadRegULongKey(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl",
                          L"EnablePartialKernelDumpFallback",local_78,0);
  if (-1 < iVar1) {
    DAT_18001c5a0 = local_78[0] != 0;
  }
  *(undefined2 *)(param_1 + 0x7d4) = 0x6e;
  iVar1 = ReadRegULongKey(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl",
                          L"IoSpaceLargeDumpThreshold",local_78,0);
  if ((-1 < iVar1) && (local_78[0] != 0)) {
    if (local_78[0] < 0x10000) {
      *(short *)(param_1 + 0x7d4) = (short)local_78[0];
    }
    else {
      *(undefined2 *)(param_1 + 0x7d4) = 0xffff;
    }
  }
  *(undefined2 *)(param_1 + 0x7d6) = 0x400;
  iVar1 = ReadRegULongKey(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl",
                          L"RegularLargeDumpThreshold",local_78,0);
  if ((-1 < iVar1) && (local_78[0] != 0)) {
    if (local_78[0] < 0x10000) {
      *(short *)(param_1 + 0x7d6) = (short)local_78[0];
    }
    else {
      *(undefined2 *)(param_1 + 0x7d6) = 0xffff;
    }
  }
  uVar5 = ~-(uint)(*(int *)(param_1 + 0x18) != 0) & 0xc0000001;
  uVar2 = Feature_CrashDumpOneMBTransferSize__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 != 0) {
    DAT_18001c5b0 = 0x10000;
    uVar5 = ReadRegULongKey(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl"
                            ,L"MaximumTransferSize",local_78,0);
    if ((((-1 < (int)uVar5) && (local_78[0] != 0)) && (DAT_18001c5b0 = 0x1000, 0xfff < local_78[0]))
       && (DAT_18001c5b0 = 0x100000, local_78[0] < 0x100001)) {
      DAT_18001c5b0 = local_78[0] & 0xfffff000;
    }
  }
  ReadOSBuildInfo(param_1);
  return uVar5;
}



===== RtlStringCchCopyW @ 1800091e8 =====

uint RtlStringCchCopyW(short *param_1,longlong param_2,undefined8 param_3)

{
  uint uVar1;
  
  if (param_2 - 1U < 0x7fffffff) {
    uVar1 = RtlStringCopyWorkerW(param_1,param_2,param_3,param_3,0x7ffffffe);
  }
  else {
    uVar1 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = 0;
    }
  }
  return uVar1;
}



===== RtlStringCchPrintfW @ 180009228 =====

undefined8
RtlStringCchPrintfW(wchar_t *param_1,longlong param_2,wchar_t *param_3,undefined8 param_4)

{
  ulonglong _Count;
  int iVar1;
  undefined8 uVar2;
  undefined8 local_res20;
  
  if (param_2 - 1U < 0x7fffffff) {
    _Count = param_2 - 1;
    uVar2 = 0;
    local_res20 = param_4;
    iVar1 = _vsnwprintf(param_1,_Count,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      uVar2 = 0x80000005;
    }
    else if ((longlong)iVar1 != _Count) {
      return 0;
    }
    param_1[_Count] = L'\0';
  }
  else {
    uVar2 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = L'\0';
    }
  }
  return uVar2;
}



===== SendUsageNotification @ 1800092a4 =====

int SendUsageNotification(longlong param_1,char param_2,int param_3)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  iVar2 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  if (((((param_2 != '\0') || ((DAT_18001bd60 & 0x40000) == 0)) || (*(int *)(param_1 + 0x170) != 3))
      || (DAT_18001c4e8 == 0)) && (*(longlong *)(param_1 + 0x168) != 0)) {
    lVar3 = IoGetRelatedDeviceObject();
    lVar4 = IoAllocateIrp(*(undefined1 *)(lVar3 + 0x4c),0);
    if (lVar4 == 0) {
      iVar2 = -0x3fffff66;
    }
    else {
      KeInitializeEvent(&local_38,0,0);
      lVar1 = *(longlong *)(lVar4 + 0xb8);
      *(undefined2 *)(lVar1 + -0x48) = 0x161b;
      *(undefined4 *)(lVar1 + -0x38) = *(undefined4 *)(param_1 + 0x170);
      *(char *)(lVar1 + -0x40) = param_2;
      *(undefined8 *)(lVar1 + -0x18) = *(undefined8 *)(param_1 + 0x168);
      lVar1 = *(longlong *)(lVar4 + 0xb8);
      *(undefined4 *)(lVar4 + 0x30) = 0xc00000bb;
      *(code **)(lVar1 + -0x10) = SignalIrpCompletion;
      *(undefined8 **)(lVar1 + -8) = &local_38;
      *(undefined1 *)(lVar1 + -0x45) = 0xe0;
      iVar2 = IofCallDriver(lVar3,lVar4);
      if (iVar2 == 0x103) {
        KeWaitForSingleObject(&local_38,0,0,0,0);
        iVar2 = *(int *)(lVar4 + 0x30);
      }
      if ((iVar2 < 0) && (param_3 == 1)) {
        iVar2 = 0;
      }
      IoFreeIrp(lVar4);
    }
  }
  return iVar2;
}



===== StartDumpDrivers @ 18000941c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int StartDumpDrivers(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  longlong lVar8;
  uint local_res8 [2];
  uint local_res10 [2];
  uint local_res18;
  uint uStackX_1c;
  longlong local_48;
  undefined4 local_40;
  undefined4 local_3c;
  
  uVar6 = 0;
  local_res18 = 0;
  uStackX_1c = 0;
  local_res10[0] = 0;
  local_res8[0] = 0;
  iVar1 = (**(code **)(param_1 + 0x208))(*(undefined8 *)(param_1 + 400),2,local_res10);
  if (iVar1 < 0) {
    if (local_res10[0] == 0) {
      local_res10[0] = 0x49;
    }
    if (DAT_18001c528 == '\0') {
      if ((((DAT_18001c33c >> 0x11 & 1) == 0) && ((DAT_18001c33c & 0x40000) == 0)) &&
         ((DAT_18001c33c >> 0x17 & 1) == 0)) {
        DAT_18001c33c = DAT_18001c33c & 0xfffffe00 | local_res10[0] & 0x1ff;
      }
      DAT_18001c33c = DAT_18001c33c | 0x40000;
      puVar5 = &DAT_18001c33c;
      uVar7 = 4;
      CrashdmpTelemetrySaveEnvironmentVariable(L"BugCheckProgress",&DAT_18001c33c,4);
      WriteLogProgress(DAT_18001c33c,puVar5,uVar7,param_4);
    }
    _DAT_18001c420 = *(undefined8 *)(param_1 + 0x208);
    iVar1 = -0x3fffffff;
    _DAT_18001c43c = 0xc0000001;
    uVar6 = 0x70001;
    goto LAB_180009896;
  }
  if (((DAT_18001c528 == '\0') && ((DAT_18001c33c >> 0x11 & 1) == 0)) &&
     (((DAT_18001c33c & 0x40000) == 0 && ((DAT_18001c33c >> 0x17 & 1) == 0)))) {
    puVar5 = &DAT_18001c33c;
    DAT_18001c33c = DAT_18001c33c & 0xfffffe4b | 0x4b;
    uVar7 = 4;
    CrashdmpTelemetrySaveEnvironmentVariable(L"BugCheckProgress",&DAT_18001c33c,4);
    WriteLogProgress(DAT_18001c33c,puVar5,uVar7,param_4);
  }
  (**(code **)(param_1 + 0x208))(*(undefined8 *)(param_1 + 400),3);
  if ((*(int *)(param_1 + 0x184) == 2) || (*(int *)(param_1 + 0x188) != 2)) {
    iVar1 = (**(code **)(param_1 + 0x208))(*(undefined8 *)(param_1 + 400),4,local_res8);
    if (iVar1 < 0) {
LAB_1800096ed:
      if (local_res8[0] == 0) {
        local_res8[0] = 0x4d;
      }
      if (DAT_18001c528 == '\0') {
        if ((((DAT_18001c33c >> 0x11 & 1) == 0) && ((DAT_18001c33c & 0x40000) == 0)) &&
           ((DAT_18001c33c >> 0x17 & 1) == 0)) {
          DAT_18001c33c = DAT_18001c33c & 0xfffffe00 | local_res8[0] & 0x1ff;
        }
        DAT_18001c33c = DAT_18001c33c | 0x40000;
        puVar5 = &DAT_18001c33c;
        uVar7 = 4;
        CrashdmpTelemetrySaveEnvironmentVariable(L"BugCheckProgress",&DAT_18001c33c,4);
        WriteLogProgress(DAT_18001c33c,puVar5,uVar7,param_4);
      }
      if (iVar1 < 0) {
        _DAT_18001c420 = *(undefined8 *)(param_1 + 0x208);
        iVar1 = -0x3fffffff;
        uVar6 = 0x70002;
        _DAT_18001c43c = 0xc0000001;
        goto LAB_180009896;
      }
    }
    else {
      if (DAT_18001c444 == 0x3003) {
        local_res8[0] = 0x4c;
LAB_1800096e5:
        iVar1 = -0x3fffffff;
        goto LAB_1800096ed;
      }
      if (DAT_18001c444 - 0x3004U < 2) {
        if (DAT_18001c444 == 0x3004) {
          local_res8[0] = 0x4d;
        }
        else if (DAT_18001c444 == 0x3005) {
          local_res8[0] = 0x4e;
        }
        goto LAB_1800096e5;
      }
      if (((DAT_18001c528 == '\0') && ((DAT_18001c33c >> 0x11 & 1) == 0)) &&
         (((DAT_18001c33c & 0x40000) == 0 && ((DAT_18001c33c >> 0x17 & 1) == 0)))) {
        puVar5 = &DAT_18001c33c;
        DAT_18001c33c = DAT_18001c33c & 0xfffffe42 | 0x42;
        uVar7 = 4;
        CrashdmpTelemetrySaveEnvironmentVariable(L"BugCheckProgress",&DAT_18001c33c,4);
        WriteLogProgress(DAT_18001c33c,puVar5,uVar7,param_4);
      }
    }
    (**(code **)(param_1 + 0x208))(*(undefined8 *)(param_1 + 400),5);
  }
  if (*(int *)(param_1 + 0x6c) == 0) {
    uVar2 = Feature_CrashDumpOneMBTransferSize__private_IsEnabledNoReportingNoInline();
    uVar4 = 0x10000;
    if ((int)uVar2 != 0) {
      uVar4 = DAT_18001c5b0;
    }
    *(uint *)(param_1 + 0x6c) = uVar4;
  }
  (**(code **)(param_1 + 0x208))(*(undefined8 *)(param_1 + 400),6,&local_res18);
  if (local_res18 < 0x200) {
    local_res18 = 0x1000;
  }
  uVar2 = Feature_CrashDumpOneMBTransferSize__private_IsEnabledNoReportingNoInline();
  if ((int)uVar2 == 0) {
    if (0xfe00 < uStackX_1c - 0x200) {
      uStackX_1c = 0x10000;
    }
  }
  else if (DAT_18001c5b0 <= uStackX_1c) {
    uStackX_1c = DAT_18001c5b0;
  }
  if (uStackX_1c < local_res18) {
    local_res18 = 0x1000;
    uStackX_1c = 0x10000;
  }
  *(uint *)(param_1 + 0x2d0) = local_res18;
  *(uint *)(param_1 + 0x2d4) = uStackX_1c;
  *(uint *)(param_1 + 0x6c) = uStackX_1c;
  *(code **)(param_1 + 0x48) = CrashdmpFinishRoutine;
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(undefined8 *)(param_1 + 0xf8) = 0;
  *(undefined8 *)(param_1 + 0x100) = 0;
  *(undefined8 *)(param_1 + 0xa8) = 0;
  if (*(longlong *)(param_1 + 0x1f0) == 0) {
    *(uint *)(param_1 + 0x290) = *(uint *)(param_1 + 0x290) | 2;
    *(undefined1 *)(param_1 + 0x230) = 0;
  }
  else {
    *(code **)(param_1 + 0xa0) = CrashdmpReadRoutine;
  }
  *(code **)(param_1 + 0x40) = CrashdmpWriteRoutine;
  *(code **)(param_1 + 0x80) = CrashdmpWritePendingRoutine;
  if (((DAT_18001c528 != '\x01') && ((DAT_18001bd60 & 0x20) != 0)) &&
     ((*(char *)(param_1 + 0x231) != '\0' && (DAT_18001c448 != 0)))) {
    lVar8 = DAT_18001c448;
    lVar3 = IsStorageRelatedCrash(0x18001bd40);
    if ((char)lVar3 != '\0') {
      local_40 = DAT_18001c484;
      local_3c = 1;
      local_48 = lVar8;
      iVar1 = (**(code **)(param_1 + 0x208))(*(undefined8 *)(param_1 + 400),8,&local_48);
      if (iVar1 < 0) {
        DAT_18001c470 = 0;
        return 0;
      }
      DAT_18001c470 = local_40;
      return iVar1;
    }
  }
  if (-1 < iVar1) {
    return iVar1;
  }
LAB_180009896:
  CrashdmpLogSELError(uVar6,iVar1);
  return iVar1;
}



===== UnloadPortDriver @ 1800098b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 UnloadPortDriver(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined4 uVar4;
  code *pcVar5;
  undefined8 *puVar6;
  
  uVar4 = 0;
  do {
    if (*(longlong **)(param_1 + 0x128) == (longlong *)(param_1 + 0x128)) {
LAB_18000994f:
      if (*(int *)(param_1 + 0x178) == 2) {
        for (puVar6 = *(undefined8 **)(param_1 + 0x1b8); puVar6 != (undefined8 *)(param_1 + 0x1b8);
            puVar6 = (undefined8 *)*puVar6) {
          puVar6[0xe] = 0;
        }
      }
      return uVar4;
    }
    plVar1 = *(longlong **)(param_1 + 0x130);
    lVar2 = *plVar1;
    if ((*(longlong **)(lVar2 + 8) != plVar1) ||
       (plVar3 = (longlong *)plVar1[1], (longlong *)*plVar3 != plVar1)) {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      goto LAB_18000994f;
    }
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    pcVar5 = (code *)RtlFindExportedRoutineByName(plVar1[3],"DumpUninitialize");
    if (pcVar5 != (code *)0x0) {
      (*pcVar5)();
    }
    uVar4 = (**(code **)(param_2 + 0x18))(plVar1[2]);
    ExFreePoolWithTag(plVar1,0);
  } while( true );
}



===== UpdatePhysicalMemoryBlock @ 180009998 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 UpdatePhysicalMemoryBlock(longlong param_1,int *param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  ulonglong uVar8;
  
  if (param_2 == (int *)0x0) {
    uVar3 = 0xc000000d;
  }
  else {
    iVar1 = *param_2;
    if (*(longlong *)(param_1 + 0x38) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x38),0);
      *(int **)(param_1 + 0x38) = param_2;
      _DAT_18001bd08 = param_2;
    }
    *(undefined8 *)(param_1 + 0x40) = *(undefined8 *)(param_2 + 2);
    lVar4 = *(longlong *)(param_2 + (ulonglong)(iVar1 - 1) * 4 + 6);
    lVar2 = *(longlong *)(param_2 + (ulonglong)(iVar1 - 1) * 4 + 4);
    *(longlong *)(param_1 + 0x48) = lVar4 + lVar2;
    if (*(int *)(param_1 + 0x18) - 5U < 2) {
      uVar6 = (lVar4 + lVar2 + 7U >> 3) + 7 & 0xfffffffffffffff8;
      uVar8 = (DAT_18001bd30 + 1) * uVar6 + 0x307f & 0xfffffffffffff000;
      lVar4 = ExAllocatePool2(0x40,uVar8,0x706d4443);
      if (lVar4 == 0) {
        return 0xc000009a;
      }
      if (*(longlong *)(param_1 + 0x60) != 0) {
        ExFreePoolWithTag(*(longlong *)(param_1 + 0x60),0);
      }
      *(longlong *)(param_1 + 0x60) = lVar4;
      *(ulonglong *)(lVar4 + 0x2020) = uVar8;
      *(undefined8 *)(*(longlong *)(param_1 + 0x60) + 0x2030) = *(undefined8 *)(param_1 + 0x48);
      *(longlong *)(param_1 + 0x88) = *(longlong *)(param_1 + 0x60) + 0x2000;
      uVar7 = 0;
      if (DAT_18001bd30 != 0) {
        do {
          uVar5 = uVar7 + 1;
          *(undefined8 *)(*(longlong *)(param_1 + 0x70) + (ulonglong)uVar7 * 0x10) =
               *(undefined8 *)(param_1 + 0x48);
          *(ulonglong *)(*(longlong *)(param_1 + 0x70) + 8 + (ulonglong)uVar7 * 0x10) =
               uVar5 * uVar6 + *(longlong *)(param_1 + 0x60) + 0x2038;
          uVar7 = uVar5;
        } while (uVar5 < DAT_18001bd30);
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 180009b18 =====

void wil_details_FeatureReporting_IncrementOpportunityInCache
               (uint *param_1,uint param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *param_1;
  do {
    uVar4 = uVar1;
    param_4[1] = 0;
    uVar1 = uVar4 | 1;
    if ((uVar4 >> 0x16 & 1) != (uint)(param_2 == 5)) {
      uVar3 = uVar4 >> 0xf & 0x7f;
      if (uVar3 != 0) {
        param_4[1] = uVar3;
        uVar3 = 5;
        if (param_2 != 1) {
          uVar3 = 1;
        }
        uVar1 = uVar4 & 0xffc07fff | 1;
        param_4[2] = uVar3;
      }
      uVar3 = 0;
      if (param_2 == 5) {
        uVar3 = 0x400000;
      }
      uVar1 = uVar3 | uVar1 & 0xffbfffff;
    }
    uVar2 = uVar1 >> 0xf & 0x7f;
    uVar3 = uVar2 + param_3;
    if ((0x7f < uVar3) || (uVar3 < uVar2)) {
      param_4[2] = param_2;
      param_4[1] = uVar2;
      uVar3 = param_3;
    }
    LOCK();
    uVar2 = *param_1;
    if (uVar4 == uVar2) {
      *param_1 = (uVar3 << 0xf ^ uVar1) & 0x3f8000 ^ uVar1;
      uVar1 = uVar4;
    }
    else {
      uVar1 = uVar2;
    }
    UNLOCK();
  } while (uVar4 != uVar2);
  param_4[4] = 0;
  *param_4 = ~uVar4 & 1;
  return;
}



===== wil_details_FeatureReporting_IncrementUsageInCache @ 180009bfc =====

void wil_details_FeatureReporting_IncrementUsageInCache
               (uint *param_1,uint param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *param_1;
  do {
    uVar3 = uVar1;
    param_4[1] = 0;
    uVar1 = uVar3 | 1;
    if ((uVar3 >> 0xe & 1) != (uint)(param_2 == 4)) {
      uVar4 = uVar3 >> 5 & 0x1ff;
      if (uVar4 != 0) {
        param_4[1] = uVar4;
        param_4[2] = ~-(uint)(param_2 != 0) & 4;
        uVar1 = uVar3 & 0xffffc01f | 1;
      }
      uVar4 = 0;
      if (param_2 == 4) {
        uVar4 = 0x4000;
      }
      uVar1 = uVar4 | uVar1 & 0xffffbfff;
    }
    uVar2 = uVar1 >> 5 & 0x1ff;
    uVar4 = uVar2 + param_3;
    if ((0x1ff < uVar4) || (uVar4 < uVar2)) {
      param_4[2] = param_2;
      param_4[1] = uVar2;
      uVar4 = param_3;
    }
    LOCK();
    uVar2 = *param_1;
    if (uVar3 == uVar2) {
      *param_1 = (uVar4 << 5 ^ uVar1) & 0x3fe0 ^ uVar1;
      uVar1 = uVar3;
    }
    else {
      uVar1 = uVar2;
    }
    UNLOCK();
  } while (uVar3 != uVar2);
  param_4[4] = 0;
  *param_4 = ~uVar3 & 1;
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 180009cec =====

uint * wil_details_FeatureReporting_RecordUsageInCache
                 (uint *param_1,uint *param_2,uint param_3,uint param_4,uint param_5)

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
LAB_180009e53:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,param_3,param_5,param_1);
  }
  else {
    if (param_3 == 1) {
LAB_180009e41:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,param_3,param_5,param_1);
      return param_1;
    }
    if ((param_3 != 2) && (param_3 != 3)) {
      if (param_3 == 4) goto LAB_180009e53;
      if (param_3 == 5) goto LAB_180009e41;
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
        param_1[1] = param_5;
        param_1[2] = param_3;
        param_1[3] = param_4;
        return param_1;
      }
    }
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
  }
  return param_1;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 180009e80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (longlong param_1,undefined8 param_2,int param_3,undefined8 param_4)

{
  bool bVar1;
  uint uVar2;
  undefined7 extraout_var;
  uint uVar3;
  undefined8 uVar4;
  int local_res18 [4];
  
  uVar3 = (uint)param_2 & 1;
  uVar4 = param_4;
  local_res18[0] = param_3;
  uVar2 = wil_details_MapReportingKind(param_3,uVar3);
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(param_1,param_2,uVar2,(uint)uVar4)
  ;
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (*(undefined4 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x10),0,uVar3,local_res18,0
               ,0,param_4);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 180009f10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (longlong param_1,undefined8 param_2,uint param_3,uint param_4)

{
  uint6 uVar1;
  uint *puVar2;
  undefined1 auStackY_a8 [32];
  undefined8 local_78;
  uint local_70 [6];
  uint local_58;
  uint uStack_54;
  uint uStack_50;
  uint uStack_4c;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_a8;
  puVar2 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_70,*(uint **)(param_1 + 8),param_3,(uint)((ulonglong)param_2 >> 0x20),
                      param_4);
  local_58 = *puVar2;
  uStack_54 = puVar2[1];
  uStack_50 = puVar2[2];
  uStack_4c = puVar2[3];
  local_48 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    (*g_wil_details_recordFeatureUsage)
              (*(undefined4 *)(param_1 + 0x18),param_3,param_4,*(undefined8 *)(param_1 + 8));
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_78._0_6_ = CONCAT24((short)param_3,*(undefined4 *)(param_1 + 0x18));
    uVar1 = (uint6)local_78;
    local_78 = (ulonglong)(uint6)local_78;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_78 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_78);
  }
  return (int)local_48 == 0;
}



===== wil_details_FeatureStateCache_GetCachedFeatureEnabledState @ 180009ff8 =====

ulonglong wil_details_FeatureStateCache_GetCachedFeatureEnabledState(uint *param_1,longlong param_2)

{
  ulonglong local_res8;
  
  local_res8 = (ulonglong)*param_1;
  if ((*param_1 & 2) == 0) {
    local_res8 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                           (param_1,local_res8,param_2);
  }
  return local_res8;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 18000a02c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                    (uint *param_1,ulonglong param_2,longlong param_3)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  uint local_res8 [2];
  undefined8 local_res10;
  
  iVar1 = 0;
  local_res8[0] = 0;
  local_res10 = param_2;
  if (g_wil_details_ensureSubscribedToFeatureConfigurationChanges != (code *)0x0) {
    iVar1 = (*g_wil_details_ensureSubscribedToFeatureConfigurationChanges)();
  }
  uVar2 = wil_details_GetCurrentFeatureEnabledState(param_3,local_res8);
  if (*(char *)(param_3 + 0x1c) == '\0') {
    local_res8[0] = local_res8[0] & -(uint)(iVar1 != 0);
  }
  uVar3 = param_2 & 0xffffffff;
  while( true ) {
    uVar5 = (uint)uVar3;
    local_res10 = CONCAT44(local_res10._4_4_,uVar5);
    if ((local_res8[0] != 0) && (local_res10 = CONCAT44(local_res10._4_4_,uVar5), (uVar3 & 2) == 0))
    {
      uVar4 = uVar5 & 0xfffff63e | uVar2 & 0x9c1;
      uVar5 = uVar4 | 2;
      local_res10 = CONCAT44(local_res10._4_4_,uVar4) | 2;
    }
    if ((param_2 & 4) == 0) {
      uVar4 = uVar2 & 0x400 | uVar5 & 0xfffffbff;
      uVar5 = uVar4 | 4;
      local_res10 = CONCAT44(local_res10._4_4_,uVar4) | 4;
    }
    uVar3 = param_2 & 0xffffffff;
    LOCK();
    uVar4 = *param_1;
    bVar6 = (uint)param_2 == uVar4;
    if (bVar6) {
      *param_1 = uVar5;
    }
    else {
      uVar3 = (ulonglong)uVar4;
    }
    UNLOCK();
    if (bVar6) break;
    param_2 = uVar3;
  }
  if (((param_2 & 4) == 0) &&
     (g_wil_details_subscribeFeatureStateCacheToConfigurationChanges != (code *)0x0)) {
    (*g_wil_details_subscribeFeatureStateCacheToConfigurationChanges)
              (param_1,*(undefined1 *)(param_3 + 0x1c),iVar1);
  }
  if (local_res8[0] == 0) {
    local_res10 = CONCAT44(local_res10._4_4_,uVar2 & 0x9c1 | uVar5 & 0xfffff63e);
  }
  return local_res10;
}



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 18000a13c =====

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



===== wil_details_GetCurrentFeatureEnabledState @ 18000a1a0 =====

uint wil_details_GetCurrentFeatureEnabledState(longlong param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar7;
  longlong *plVar8;
  uint local_res8;
  uint local_28 [8];
  
  cVar1 = *(char *)(param_1 + 0x1c);
  uVar2 = *(undefined4 *)(param_1 + 0x18);
  *param_2 = 1;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  uVar5 = wil_RtlStagingConfig_QueryFeatureState(local_28,uVar2,(uint)((byte)(cVar1 - 2U) < 2));
  uVar4 = -(uint)((int)uVar5 != 0) & local_28[0] & 3;
  if (uVar4 == 0) {
    uVar7 = -(uint)(*(char *)(param_1 + 0x1f) != '\0') & 0x40;
  }
  else {
    uVar7 = 0;
    if (local_28[0] == 2) {
      uVar7 = 0x40;
    }
  }
  local_res8 = uVar7 >> 6 ^
               (uVar4 << 7 | -(uint)(local_28[5] != 0) & 0x800 | -(uint)(local_28[4] != 0) & 0x400 |
               uVar7);
  if ((uVar7 != 0) && (plVar8 = *(longlong **)(param_1 + 0x20), plVar8 != (longlong *)0x0)) {
    do {
      puVar3 = (undefined8 *)*plVar8;
      if (puVar3 == (undefined8 *)0x0) {
        return local_res8;
      }
      if ((*(char *)((longlong)puVar3 + 0x1e) == '\0') &&
         (*(char *)((longlong)puVar3 + 0x1d) == '\0')) {
        uVar6 = wil_details_FeatureStateCache_GetCachedFeatureEnabledState((uint *)*puVar3,puVar3);
        uVar4 = local_res8 & 0xfffffffe;
        local_res8 = (uint)(((uint)uVar6 & local_res8 & 1) != 0);
      }
      else {
        if (((local_res8 & 1) == 0) || (*(char *)((longlong)puVar3 + 0x1f) == '\0')) {
          uVar4 = 0;
        }
        else {
          uVar4 = 1;
        }
        local_res8 = local_res8 & 0xfffffffe;
      }
      local_res8 = local_res8 | uVar4;
      plVar8 = plVar8 + 1;
    } while ((local_res8 & 1) != 0);
  }
  return local_res8;
}



===== wil_details_IsEnabledFallback @ 18000a2dc =====

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
     (wil_details_FeatureReporting_ReportUsageToService((longlong)param_3,local_res8,param_2,1),
     param_2 - 3U < 2)) {
    wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath((uint)local_res8,param_2,param_3);
  }
  return (uint)param_1 & 1;
}



===== wil_details_MapReportingKind @ 18000a378 =====

uint wil_details_MapReportingKind(int param_1,int param_2)

{
  byte bVar1;
  
  if (param_1 != 0) {
    if (param_1 == 1) {
      return ~-(uint)(param_2 != 0) & 4;
    }
    if (param_1 == 2) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 5;
    }
    if (param_1 == 3) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 6;
    }
    if (param_1 == 4) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 7;
    }
    if (param_1 == 5) {
      return (-(uint)(param_2 != 0) & 0xfffffffe) + 10;
    }
    if (param_1 == 6) {
      return (-(uint)(param_2 != 0) & 0xfffffffe) + 0xb;
    }
    bVar1 = (char)param_1 + 0x9c;
    if (bVar1 < 0x32) {
      return (-(uint)(param_2 != 0) & 0xffffffce) + 0x96 + (uint)bVar1;
    }
  }
  return 0xff;
}



===== ClearLogFile @ 18000a418 =====

void ClearLogFile(longlong param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = 0;
  *(undefined4 *)(param_1 + 0x2b4) = 0;
  *(undefined8 *)(param_1 + 0x2b8) = 0;
  uVar2 = 0x1000;
  *(undefined4 *)(param_1 + 0x2b0) = 0;
  *(undefined1 *)(param_1 + 0x233) = 0;
  memset(*(void **)(param_1 + 0x2c0),0,0x1000);
  do {
    WriteLogDataToDisk(param_1,*(longlong *)(param_1 + 0x2c0),uVar2,'\x01');
    uVar1 = uVar1 + 0x1000;
  } while (uVar1 < *(uint *)(param_1 + 0x294));
  *(undefined4 *)(param_1 + 0x2b4) = 0;
  *(undefined8 *)(param_1 + 0x2b8) = 0;
  *(undefined4 *)(param_1 + 0x2b0) = 0;
  return;
}



===== DumpWrite @ 18000a4a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DumpWrite(longlong *param_1,char *param_2,undefined *param_3,undefined *param_4)

{
  void *_Src;
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined4 *puVar4;
  longlong lVar5;
  char *pcVar6;
  char *pcVar7;
  undefined8 uVar8;
  undefined *puVar9;
  code *pcVar10;
  int iVar11;
  code *pcVar12;
  uint uVar13;
  bool bVar14;
  undefined1 auStackY_e8 [32];
  char in_stack_ffffffffffffff48;
  uint local_74;
  char *local_70;
  undefined *local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_e8;
  bVar14 = DAT_18001c52b == '\x01';
  _Src = (void *)param_1[0xc];
  lVar2 = 0;
  uVar13 = *(uint *)(param_1 + 4) & 0x80;
  if (uVar13 != 0) {
    *(undefined4 *)(param_1 + 3) = 4;
  }
  local_70 = param_2;
  local_68 = param_3;
  WriteLogElapsedDuration();
  FillDumpHeader(param_1,(undefined4 *)param_1[0xc]);
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffffd;
  *(undefined4 *)((longlong)param_1 + 0x624) = 0;
  param_1[0xc5] = 0;
  *(undefined4 *)(param_1 + 0xc6) = 0;
  if ((*(uint *)(param_1 + 0xbb) & 0x20) != 0) {
    if (bVar14) {
      WriteLogString(*param_1,"Initiating RetryAsMinidump!\r\n",param_3,param_4);
    }
    *(uint *)((longlong)_Src + 0x1050) = *(uint *)((longlong)_Src + 0x1050) | 0x10000;
  }
  if ((uVar13 == 0) && ((*(uint *)(param_1 + 0xbb) & 0x20) == 0)) {
    if (bVar14) {
      WriteLogString(*param_1,"Starting get secondary dump callbacks size.\r\n",param_3,param_4);
    }
    lVar2 = GetSecondaryDumpCallbackSize((longlong)param_1);
    if ((((DAT_18001c528 == '\0') && ((DAT_18001c33c >> 0x11 & 1) == 0)) &&
        ((DAT_18001c33c >> 0x12 & 1) == 0)) && ((DAT_18001c33c >> 0x17 & 1) == 0)) {
      puVar4 = &DAT_18001c33c;
      DAT_18001c33c = DAT_18001c33c & 0xfffffe52 | 0x52;
      param_3 = (undefined *)0x4;
      CrashdmpTelemetrySaveEnvironmentVariable(L"BugCheckProgress",&DAT_18001c33c,4);
      WriteLogProgress(DAT_18001c33c,puVar4,param_3,param_4);
    }
    *(longlong *)((longlong)_Src + 4000) = *(longlong *)((longlong)_Src + 4000) + lVar2;
    if (!bVar14) goto LAB_18000a605;
    WriteLogString(*param_1,"Finish get secondary dump callbacks size.\r\n",param_3,param_4);
LAB_18000a60a:
    uVar3 = Feature_CrashDumpOneMBTransferSize__private_IsEnabledDeviceUsageNoInline();
    param_4 = *(undefined **)((longlong)_Src + 4000);
    param_3 = (undefined *)(ulonglong)*(uint *)((longlong)_Src + 0xf98);
    if ((int)uVar3 == 0) {
      WriteLogString(*param_1,
                     "Dump Type: %d, Total Dump Size: %I64d, Secondary Dump Size: %I64d.\r\n",
                     param_3,param_4);
    }
    else {
      WriteLogString(*param_1,
                     "Dump Type: %d, Total Dump Size: %I64d, Secondary Dump Size: %I64d, MaxTransferSize: %u.\r\n"
                     ,param_3,param_4);
    }
  }
  else {
LAB_18000a605:
    if (bVar14) goto LAB_18000a60a;
  }
  if ((int)param_1[3] - 5U < 2) {
    param_3 = *(undefined **)((longlong)_Src + 4000);
    lVar5 = param_1[2];
    if ((lVar5 < (longlong)param_3) ||
       ((DmpEncryptionContext != '\0' && (lVar5 < (longlong)(param_3 + DAT_18001b3ac))))) {
      CrashdmpDisplayString
                ("\n\rDump file size(%I64d) is too small - requires at least %I64d bytes.",lVar5,
                 param_3,param_4);
      CrashdmpDisplayString
                ("\n\rFuture kernel or full memory dumps may require larger size.",lVar5,param_3,
                 param_4);
      if (((DAT_18001c5a0 == '\0') &&
          (((*(uint *)(param_1 + 0xbb) & 2) == 0 || ((int)param_1[3] != 6)))) ||
         ((*(uint *)(param_1 + 4) & 0x40) != 0)) {
        CrashdmpDisplayString("\n\rSwitching to minidump ...",lVar5,param_3,param_4);
        if ((((DAT_18001c528 == '\0') && ((DAT_18001c33c >> 0x11 & 1) == 0)) &&
            ((DAT_18001c33c >> 0x12 & 1) == 0)) && ((DAT_18001c33c >> 0x17 & 1) == 0)) {
          puVar4 = &DAT_18001c33c;
          DAT_18001c33c = DAT_18001c33c & 0xfffffe51 | 0x51;
          uVar8 = 4;
          CrashdmpTelemetrySaveEnvironmentVariable(L"BugCheckProgress",&DAT_18001c33c,4);
          WriteLogProgress(DAT_18001c33c,puVar4,uVar8,param_4);
        }
        if ((*(uint *)(param_1 + 0xbb) & 4) != 0) {
          *(uint *)(param_1 + 0xbb) = *(uint *)(param_1 + 0xbb) & 0xfffffffb;
        }
        lVar2 = *(longlong *)((longlong)_Src + 4000);
        param_1[0xd7] = lVar2;
        if (DmpEncryptionContext != '\0') {
          lVar2 = lVar2 + (ulonglong)DAT_18001b3ac;
          param_1[0xd7] = lVar2;
        }
        *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x40;
        *(undefined4 *)(param_1 + 3) = 4;
        param_1[0xb6] = param_1[0xc] + 0x2000;
        if (bVar14) {
          WriteLogString(*param_1,
                         "Dump file is too small - switching to minidump. Dump file size = %I64d, required size = %I64d.\r\n"
                         ,param_1[2],lVar2);
        }
      }
      else {
        lVar5 = param_1[0xc];
        uVar3 = (param_1[2] - *(longlong *)(lVar5 + 0x2020)) - lVar2;
        local_60 = 0;
        uStack_58 = 0;
        if (DmpEncryptionContext != '\0') {
          uVar3 = uVar3 - DAT_18001b3ac;
        }
        CrashdmpDisplayString
                  ("\n\rSwitching to partial kernel dump ... Available data size:%I64d bytes",uVar3,
                   param_3,param_4);
        if (((DAT_18001c528 == '\0') && ((DAT_18001c33c >> 0x11 & 1) == 0)) &&
           (((DAT_18001c33c >> 0x12 & 1) == 0 && ((DAT_18001c33c >> 0x17 & 1) == 0)))) {
          puVar4 = &DAT_18001c33c;
          DAT_18001c33c = DAT_18001c33c & 0xfffffe50 | 0x50;
          uVar8 = 4;
          CrashdmpTelemetrySaveEnvironmentVariable(L"BugCheckProgress",&DAT_18001c33c,4);
          WriteLogProgress(DAT_18001c33c,puVar4,uVar8,param_4);
        }
        *(uint *)(param_1 + 0xbb) = *(uint *)(param_1 + 0xbb) | 4;
        *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x40;
        param_1[0xc2] = uVar3 >> 0xc;
        *(undefined4 *)(param_1 + 3) = 6;
        lVar2 = *(longlong *)((longlong)_Src + 4000);
        param_1[0xd7] = lVar2;
        if (DmpEncryptionContext != '\0') {
          lVar2 = lVar2 + (ulonglong)DAT_18001b3ac;
          param_1[0xd7] = lVar2;
        }
        if (bVar14) {
          WriteLogString(*param_1,
                         "Dump file is too small - switching to partial kernel dump. Dump file size = %I64d, required size = %I64d.\r\n"
                         ,param_1[2],lVar2);
        }
        RtlInitializeBitMapEx(&local_60,lVar5 + 0x2038,*(undefined8 *)(lVar5 + 0x2030));
        RtlClearAllBitsEx(&local_60);
        uVar13 = 0;
        if (DAT_18001bd30 != 0) {
          do {
            RtlInitializeBitMapEx
                      (&local_60,*(undefined8 *)(param_1[0xe] + 8 + (ulonglong)uVar13 * 0x10),
                       *(undefined8 *)(param_1[0xe] + (ulonglong)uVar13 * 0x10));
            RtlClearAllBitsEx(&local_60);
            uVar13 = uVar13 + 1;
          } while (uVar13 < DAT_18001bd30);
        }
        *(undefined8 *)(lVar5 + 0x2028) = 0;
      }
      return -0x3ffffdd3;
    }
  }
  if ((*(uint *)(param_1 + 0xbb) & 4) != 0) {
    uVar1 = *(uint *)((longlong)_Src + 0x1050);
    *(uint *)((longlong)_Src + 0x1050) = uVar1 | 0x400;
    if ((*(uint *)(param_1 + 0xbb) & 0x10) != 0) {
      *(uint *)((longlong)_Src + 0x1050) = uVar1 | 0x2400;
    }
  }
  if (bVar14) {
    WriteLogString(*param_1,"Starting write of dump header.\r\n",param_3,param_4);
  }
  if ((DAT_18001c528 == '\0') && (DmpEncryptionContext != '\0')) {
    uVar1 = (*DAT_18001b398)(_Src,DAT_18001b3b8,DAT_18001b3ac);
    pcVar12 = (code *)(ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      param_4 = (code *)0x1;
      uVar1 = WriteBufferToDisk(param_1,DAT_18001b3b8,(ulonglong)DAT_18001b3ac,1,'\x01');
      if (-1 < (int)uVar1) goto LAB_18000aa50;
      goto LAB_18000aa18;
    }
    if (bVar14) {
      WriteLogString(*param_1,"DumpWrite: failed to get secure header, status: 0x%X.\r\n",
                     (ulonglong)uVar1,param_4);
    }
    local_74 = 0x20001;
  }
  else {
LAB_18000aa50:
    *(undefined4 *)(param_1 + 0xf2) = 0xffffffff;
    param_1[0xf3] = 0x7fffffffffffffff;
    memcpy(&DumpHeaderSnapshot,_Src,0x2000);
    param_4 = (code *)0x1;
    puVar9 = (undefined *)0x2000;
    uVar1 = WriteBufferToDisk(param_1,(longlong)_Src,0x2000,1,'\0');
    if ((int)uVar1 < 0) {
LAB_18000aa18:
      pcVar12 = (code *)(ulonglong)uVar1;
      if (DAT_18001c528 == '\0') {
        DAT_18001c33c = DAT_18001c33c | 0x100000;
        puVar4 = &DAT_18001c33c;
        uVar8 = 4;
        CrashdmpTelemetrySaveEnvironmentVariable(L"BugCheckProgress",&DAT_18001c33c,4);
        WriteLogProgress(DAT_18001c33c,puVar4,uVar8,param_4);
      }
      local_74 = 0x20002;
    }
    else {
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x1000;
      if (bVar14) {
        WriteLogString(*param_1,"Finish write of dump header.\r\n",puVar9,param_4);
      }
      iVar11 = (int)param_1[3];
      pcVar6 = local_70;
      if (iVar11 == 4) {
        uVar1 = WriteMiniDump(param_1,local_70,puVar9,param_4);
        pcVar12 = (code *)(ulonglong)uVar1;
        local_74 = (int)uVar1 >> 0x1f & 0x20003;
        if ((((DAT_18001c528 == '\0') && ((DAT_18001c33c >> 0x11 & 1) == 0)) &&
            ((DAT_18001c33c >> 0x12 & 1) == 0)) && ((DAT_18001c33c >> 0x17 & 1) == 0)) {
          pcVar6 = (char *)&DAT_18001c33c;
          DAT_18001c33c = DAT_18001c33c & 0xfffffe44 | 0x44;
          puVar9 = (undefined *)0x4;
          CrashdmpTelemetrySaveEnvironmentVariable(L"BugCheckProgress",&DAT_18001c33c,4);
          WriteLogProgress(DAT_18001c33c,pcVar6,puVar9,param_4);
        }
      }
      else {
        if ((iVar11 != 5) && (iVar11 != 6)) {
          pcVar12 = (code *)0xc000000d;
          param_4 = (code *)0xc000000d;
          WriteDiagnosticDataToDumpHeader
                    (*param_1,0xc000000d,0x18000a4a0,0xc000000d,"Crashdmp",
                     "Unsupported dump type %d.\r\nDump completed with error.\r\n",(char)param_1[3])
          ;
          if (bVar14) {
            WriteLogString(*param_1,"Unsupported dump type %d.\r\nDump completed with error.\r\n",
                           (ulonglong)*(uint *)(param_1 + 3),param_4);
          }
          local_74 = 0x20005;
          goto LAB_18000af43;
        }
        puVar9 = local_68;
        uVar1 = WriteBitmapDump(param_1,local_70,local_68,param_4);
        pcVar12 = (code *)(ulonglong)uVar1;
        local_74 = (int)uVar1 >> 0x1f & 0x20004;
        if (((DAT_18001c528 == '\0') && ((DAT_18001c33c >> 0x11 & 1) == 0)) &&
           (((DAT_18001c33c >> 0x12 & 1) == 0 && ((DAT_18001c33c >> 0x17 & 1) == 0)))) {
          pcVar6 = (char *)&DAT_18001c33c;
          DAT_18001c33c = DAT_18001c33c & 0xfffffe43 | 0x43;
          puVar9 = (undefined *)0x4;
          CrashdmpTelemetrySaveEnvironmentVariable(L"BugCheckProgress",&DAT_18001c33c,4);
          WriteLogProgress(DAT_18001c33c,pcVar6,puVar9,param_4);
        }
      }
      iVar11 = (int)pcVar12;
      if (bVar14) {
        WriteLogElapsedDuration();
      }
      if ((uVar13 == 0) && ((*(uint *)(param_1 + 0xbb) & 0x20) == 0)) {
        if (bVar14) {
          pcVar6 = "Starting invoking secondary dump callbacks.\r\n";
          WriteLogString(*param_1,"Starting invoking secondary dump callbacks.\r\n",puVar9,param_4);
        }
        InvokeSecondaryDumpCallbacks(param_1,pcVar6,puVar9,param_4);
        if ((((DAT_18001c528 == '\0') && ((DAT_18001c33c >> 0x11 & 1) == 0)) &&
            ((DAT_18001c33c >> 0x12 & 1) == 0)) && ((DAT_18001c33c >> 0x17 & 1) == 0)) {
          puVar4 = &DAT_18001c33c;
          DAT_18001c33c = DAT_18001c33c & 0xfffffe45 | 0x45;
          puVar9 = (undefined *)0x4;
          CrashdmpTelemetrySaveEnvironmentVariable(L"BugCheckProgress",&DAT_18001c33c,4);
          WriteLogProgress(DAT_18001c33c,puVar4,puVar9,param_4);
        }
        if (bVar14) {
          pcVar6 = "Finish invoking secondary dump callbacks.\r\n";
          goto LAB_18000acd9;
        }
      }
      else {
        pcVar6 = "MiniDumpDumpWriteRetry in progress, skipping secondary dump callbacks.\r\n";
LAB_18000acd9:
        WriteLogString(*param_1,pcVar6,puVar9,param_4);
      }
      uVar3 = 4;
      InvokeDumpCallbacks(param_1,0,0,4,1);
      if (((DAT_18001c528 == '\0') && ((DAT_18001c33c >> 0x11 & 1) == 0)) &&
         (((DAT_18001c33c >> 0x12 & 1) == 0 && ((DAT_18001c33c >> 0x17 & 1) == 0)))) {
        puVar4 = &DAT_18001c33c;
        DAT_18001c33c = DAT_18001c33c & 0xfffffe46 | 0x46;
        uVar8 = 4;
        CrashdmpTelemetrySaveEnvironmentVariable(L"BugCheckProgress",&DAT_18001c33c,4);
        WriteLogProgress(DAT_18001c33c,puVar4,uVar8,uVar3);
      }
      if (bVar14) {
        local_68 = (undefined *)0x0;
        local_60 = 0;
        uStack_58 = 0;
        local_50 = 0;
        uStack_48 = 0;
        local_70 = _DAT_fffff78000000014;
        RtlTimeToTimeFields(&local_70,&local_60);
        ExSystemTimeToLocalTime(&local_70,&local_68);
        RtlTimeToTimeFields(&local_68,&local_50);
        in_stack_ffffffffffffff48 = (char)uStack_58;
        uVar3 = (ulonglong)(uint)(int)local_60._2_2_;
        WriteLogString(*param_1,
                       "Dump ended at UTC: %04d/%02d/%02d %02d:%02d:%02d, local time: %04d/%02d/%02d %02d:%02d:%02d.\r\n"
                       ,(ulonglong)(uint)(int)(short)local_60,uVar3);
        WriteLogElapsedDuration();
      }
      if (iVar11 < 0) {
        pcVar10 = DumpWrite;
        param_4 = pcVar12;
        WriteDiagnosticDataToDumpHeader
                  (*param_1,iVar11,0x18000a4a0,iVar11,"Crashdmp","Dump failed status %08X.\r\n",
                   (char)pcVar12);
        pcVar6 = (char *)pcVar10;
        if (bVar14) {
          pcVar7 = "Dump failed status %08X.\r\n";
          pcVar6 = (char *)pcVar12;
          WriteLogString(*param_1,"Dump failed status %08X.\r\n",pcVar12,param_4);
          goto LAB_18000af0d;
        }
      }
      else {
        if (((DAT_18001c528 == '\0') && ((DAT_18001c33c >> 0x11 & 1) == 0)) &&
           (((DAT_18001c33c >> 0x12 & 1) == 0 && ((DAT_18001c33c >> 0x17 & 1) == 0)))) {
          puVar4 = &DAT_18001c33c;
          DAT_18001c33c = DAT_18001c33c & 0xfffffe53 | 0x53;
          uVar8 = 4;
          CrashdmpTelemetrySaveEnvironmentVariable(L"BugCheckProgress",&DAT_18001c33c,4);
          WriteLogProgress(DAT_18001c33c,puVar4,uVar8,uVar3);
        }
        param_4 = (code *)0x0;
        pcVar6 = (char *)0x0;
        WriteDiagnosticDataToDumpHeader
                  (*param_1,iVar11,0,0,(void *)0x0,"Dump completed successfully.",
                   in_stack_ffffffffffffff48);
        if (bVar14) {
          pcVar7 = "%s\r\n";
          pcVar6 = "Dump completed successfully.";
          WriteLogString(*param_1,"%s\r\n","Dump completed successfully.",param_4);
LAB_18000af0d:
          FinalizedLogFile(*param_1,pcVar7,pcVar6);
        }
      }
      if (*(code **)(*param_1 + 0x48) != (code *)0x0) {
        (**(code **)(*param_1 + 0x48))();
      }
      CrashdmpDisplayString("%s\r\n",StrDumpComplete,pcVar6,param_4);
      if (-1 < iVar11) goto LAB_18000af74;
    }
  }
LAB_18000af43:
  iVar11 = (int)pcVar12;
  CrashdmpLogSELError(local_74,iVar11);
  CrashdmpDisplayString("\n\r%s 0x%X.",StrDumpFailed,pcVar12,param_4);
  KeStallExecutionProcessor(2000000);
LAB_18000af74:
  *(int *)((longlong)param_1 + 0x634) = iVar11;
  return iVar11;
}



===== DumpWriteCapsule @ 18000afb0 =====

ulonglong DumpWriteCapsule(longlong *param_1,undefined8 param_2,undefined8 *param_3,
                          undefined8 *param_4)

{
  uint *puVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 unaff_RBX;
  undefined4 *puVar5;
  undefined8 *unaff_RDI;
  undefined8 *puVar6;
  uint uVar7;
  undefined8 *puVar8;
  undefined8 unaff_retaddr;
  
  lVar3 = param_1[0xb6];
  puVar5 = (undefined4 *)(lVar3 + -0x2000);
  FilterCallback(1,(undefined8 *)*param_1,param_3,param_4,unaff_RDI,unaff_retaddr,unaff_RBX);
  *(undefined4 *)(param_1 + 3) = 4;
  FillDumpHeader(param_1,puVar5);
  puVar1 = (uint *)(lVar3 + -0xfb0);
  *puVar1 = *puVar1 | 2;
  *(undefined4 *)((longlong)param_1 + 0x654) = 0x2000;
  uVar2 = *(uint *)(param_1[0xb6] + 4);
  uVar7 = 0x40000 - uVar2;
  puVar8 = (undefined8 *)(ulonglong)uVar7;
  puVar6 = (undefined8 *)(param_1[0xb6] + -0x2000 + (ulonglong)uVar2);
  DumpCapsuleSecondaryCallbacks((longlong)puVar5,(longlong)param_1,(undefined4 *)puVar6,uVar7);
  *(undefined4 *)((longlong)param_1 + 0x624) = 0;
  param_1[0xc5] = 0;
  uVar4 = WriteBufferToDumpFilters(param_1,(longlong)puVar5);
  FilterCallback(3,(undefined8 *)*param_1,puVar6,puVar8,unaff_RDI,unaff_retaddr,unaff_RBX);
  return uVar4 & 0xffffffff;
}



===== FillDumpHeader @ 18000b060 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FillDumpHeader(longlong *param_1,undefined4 *param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  undefined4 uVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong *plVar7;
  undefined4 uVar8;
  uint uVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong *plVar12;
  undefined4 *puVar13;
  
  puVar13 = param_2;
  for (lVar11 = 0x800; lVar11 != 0; lVar11 = lVar11 + -1) {
    *puVar13 = 0x45474150;
    puVar13 = puVar13 + 1;
  }
  param_2[1] = 0x34365544;
  param_2[0xe] = (int)param_1[0x13];
  *(longlong *)(param_2 + 0x10) = param_1[0x14];
  *(longlong *)(param_2 + 0x12) = param_1[0x15];
  *(longlong *)(param_2 + 0x14) = param_1[0x16];
  *(longlong *)(param_2 + 0x16) = param_1[0x17];
  *(undefined8 *)(param_2 + 0x18) = 0;
  *(undefined8 *)(param_2 + 0x1a) = 0;
  *(undefined8 *)(param_2 + 0x1c) = 0;
  *(undefined8 *)(param_2 + 0x1e) = 0;
  param_2[0x40f] = 0;
  *(longlong *)(param_2 + 6) = param_1[0xb5];
  *(longlong *)(param_2 + 8) = param_1[0xb4];
  *(longlong *)(param_2 + 10) = param_1[0xb3];
  uVar8 = KeQueryActiveProcessorCountEx(0xffff);
  param_2[0xd] = uVar8;
  puVar1 = (uint *)(param_1 + 4);
  param_2[2] = DAT_18001c554 >> 0x1c;
  param_2[3] = DAT_18001c554 & 0xffff;
  *(longlong *)(param_2 + 0x20) = param_1[0xb2];
  *(longlong *)(param_2 + 4) = param_1[0xb8];
  *(char *)((longlong)param_2 + 0x104e) = (char)param_1[0xc3];
  if ((*puVar1 & 0x80000) == 0) {
    wcscpy_s((wchar_t *)(param_2 + 0x4bc),8,(wchar_t *)(param_1 + 0xf7));
  }
  param_2[0x4c0] = (int)param_1[0xf9];
  param_2[0x4c1] = *(undefined4 *)((longlong)param_1 + 0x7cc);
  param_2[0x4c2] = (int)param_1[0xfa];
  param_2[0xc] = 0x8664;
  *(longlong *)(param_2 + 0x3c4) = param_1[0x37];
  if ((int)param_1[3] == 4) {
    uVar9 = (*(int *)param_1[7] + 1) * 0x10;
    if (700 < uVar9) {
      uVar9 = 0x2b0;
    }
    memcpy(param_2 + 0x22,(int *)param_1[7],(ulonglong)uVar9);
  }
  lVar11 = 9;
  plVar6 = (longlong *)(param_2 + 0xd2);
  plVar7 = param_1 + 0x18;
  do {
    plVar12 = plVar7;
    plVar10 = plVar6;
    lVar5 = plVar12[1];
    *plVar10 = *plVar12;
    plVar10[1] = lVar5;
    lVar5 = plVar12[3];
    plVar10[2] = plVar12[2];
    plVar10[3] = lVar5;
    lVar5 = plVar12[5];
    plVar10[4] = plVar12[4];
    plVar10[5] = lVar5;
    lVar5 = plVar12[7];
    plVar10[6] = plVar12[6];
    plVar10[7] = lVar5;
    lVar5 = plVar12[9];
    plVar10[8] = plVar12[8];
    plVar10[9] = lVar5;
    lVar5 = plVar12[0xb];
    plVar10[10] = plVar12[10];
    plVar10[0xb] = lVar5;
    lVar5 = plVar12[0xd];
    plVar10[0xc] = plVar12[0xc];
    plVar10[0xd] = lVar5;
    lVar5 = plVar12[0xf];
    plVar10[0xe] = plVar12[0xe];
    plVar10[0xf] = lVar5;
    lVar11 = lVar11 + -1;
    plVar6 = plVar10 + 0x10;
    plVar7 = plVar12 + 0x10;
  } while (lVar11 != 0);
  lVar11 = plVar12[0x11];
  plVar10[0x10] = plVar12[0x10];
  plVar10[0x11] = lVar11;
  lVar11 = plVar12[0x13];
  plVar10[0x12] = plVar12[0x12];
  plVar10[0x13] = lVar11;
  lVar11 = plVar12[0x15];
  plVar10[0x14] = plVar12[0x14];
  plVar10[0x15] = lVar11;
  uVar8 = *(undefined4 *)((longlong)plVar12 + 0xb4);
  lVar11 = plVar12[0x17];
  uVar4 = *(undefined4 *)((longlong)plVar12 + 0xbc);
  *(int *)(plVar10 + 0x16) = (int)plVar12[0x16];
  *(undefined4 *)((longlong)plVar10 + 0xb4) = uVar8;
  *(int *)(plVar10 + 0x17) = (int)lVar11;
  *(undefined4 *)((longlong)plVar10 + 0xbc) = uVar4;
  lVar11 = plVar12[0x18];
  uVar8 = *(undefined4 *)((longlong)plVar12 + 0xc4);
  lVar5 = plVar12[0x19];
  uVar4 = *(undefined4 *)((longlong)plVar12 + 0xcc);
  *(undefined8 *)(param_2 + 0x3c2) = 0;
  param_2[0x3c6] = 0;
  *(int *)(plVar10 + 0x18) = (int)lVar11;
  *(undefined4 *)((longlong)plVar10 + 0xc4) = uVar8;
  *(int *)(plVar10 + 0x19) = (int)lVar5;
  *(undefined4 *)((longlong)plVar10 + 0xcc) = uVar4;
  param_2[0x3c0] = 0x80000003;
  param_2[0x3c1] = 1;
  param_2[0x3e6] = (int)param_1[3];
  param_2[0x3ea] = _DAT_fffff78000000014;
  param_2[0x3eb] = _DAT_fffff78000000018;
  param_2[0x40c] = _DAT_fffff78000000008;
  param_2[0x40d] = _DAT_fffff7800000000c;
  RtlGetNtProductType();
  puVar2 = param_2 + 0x414;
  param_2[0x411] = _DAT_fffff780000002d0;
  uVar8 = _DAT_fffff780000002c4;
  uVar9 = 0;
  *puVar2 = 0;
  param_2[0x415] = uVar8;
  if ((*puVar1 & 0x800) != 0) {
    *puVar2 = 0x800;
    uVar9 = 0x800;
  }
  if (*(char *)((longlong)param_1 + 0x78d) != '\0') {
    uVar9 = uVar9 | 0x20000;
    *puVar2 = uVar9;
  }
  iVar3 = (int)param_1[3];
  if (iVar3 == 4) {
    param_2[0x40e] = 0xdff;
    if ((char)param_1[4] < '\0') {
      uVar9 = uVar9 | 1;
      *puVar2 = uVar9;
    }
    if ((*(uint *)(param_1 + 4) & 0x40) != 0) {
      param_2[0x414] = uVar9 | 4;
    }
    uVar9 = *(uint *)(param_1[0xb6] + 4);
    if (uVar9 % *(uint *)(*param_1 + 0x254) != 0) {
      if (DmpEncryptionContext != '\0') {
        *(uint *)(param_1[0xb6] + 4) = uVar9 + 0xfff & 0xfffff000;
      }
      *(int *)(param_1[0xb6] + 4) =
           *(int *)(param_1[0xb6] + 4) + -1 + *(int *)(*param_1 + 0x254) &
           -*(int *)(*param_1 + 0x254);
      if (0x40000 < *(uint *)(param_1[0xb6] + 4)) {
        *(undefined4 *)(param_1[0xb6] + 4) = 0x40000;
      }
      *(undefined4 *)((ulonglong)(*(int *)(param_1[0xb6] + 4) - 0x2004) + param_1[0xb6]) =
           0x44475254;
      *(int *)(param_1[0xb6] + 8) = *(int *)(param_1[0xb6] + 4) + -4;
    }
    uVar9 = *(uint *)(param_1[0xb6] + 4);
    param_2[0x414] = param_2[0x414] | 8;
    *(ulonglong *)(param_2 + 1000) = (ulonglong)uVar9;
  }
  else if ((iVar3 == 5) || (iVar3 == 6)) {
    lVar11 = param_1[0xc];
    uVar8 = 0x504d4453;
    if (iVar3 != 6) {
      uVar8 = 0x504d4446;
    }
    *(undefined4 *)(lVar11 + 0x2000) = uVar8;
    *(undefined4 *)(lVar11 + 0x2004) = 0x504d5544;
    *(longlong *)(param_2 + 1000) =
         *(longlong *)(lVar11 + 0x2028) * 0x1000 + *(longlong *)(lVar11 + 0x2020);
    if ((*puVar1 & 0x40) != 0) {
      *puVar2 = *puVar2 | 4;
    }
    uVar9 = *puVar2 | 0x40;
    if ((*(byte *)(param_1 + 0xbb) & 2) == 0) {
      uVar9 = *puVar2 & 0xffffffbf;
    }
    *puVar2 = uVar9;
  }
  return;
}



===== FinalizedLogFile @ 18000b4b8 =====

void FinalizedLogFile(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  if (*(longlong *)(param_1 + 0xa0) != 0) {
    *(undefined4 *)(param_1 + 0x2b4) = 0;
    *(undefined8 *)(param_1 + 0x2b8) = 0;
    *(undefined4 *)(param_1 + 0x2b0) = 0;
    iVar1 = ReadLogDataFromDisk(param_1,*(longlong *)(param_1 + 0x2c0),param_3,0,0);
    if (-1 < iVar1) {
      *(undefined4 *)(*(longlong *)(param_1 + 0x2c0) + 0x14) = *(undefined4 *)(param_1 + 0x298);
      WriteLogDataToDisk(param_1,*(longlong *)(param_1 + 0x2c0),param_3,'\0');
      *(undefined1 *)(param_1 + 0x233) = 1;
    }
  }
  return;
}



===== GetEncryptedData @ 18000b530 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
GetEncryptedData(ulonglong param_1,longlong param_2,undefined *param_3,undefined8 *param_4,
                longlong *param_5,uint *param_6)

{
  char cVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint local_res10 [2];
  ulonglong local_28 [2];
  
  local_res10[0] = 0;
  uVar3 = 0xffffffffffffffff;
  local_28[0] = 0;
  uVar5 = 0;
  if (DAT_18001bd30 != 0) {
    do {
      cVar1 = FindNextSetBitRange64
                        ((undefined8 *)(uVar5 * 0x10 + *(longlong *)(param_2 + 0x70)),param_1,
                         local_28,(ulonglong *)0x0);
      if ((cVar1 != '\0') && (local_28[0] < uVar3)) {
        uVar3 = local_28[0];
      }
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar4;
    } while (uVar4 < DAT_18001bd30);
  }
  uVar4 = *(uint *)(param_2 + 0x640) >> 0xc;
  if (uVar4 < 2) {
    *param_6 = 0;
    uVar2 = 0xc000009a;
  }
  else {
    uVar5 = (ulonglong)(uVar4 * 0x1000 - 0x1000);
    lVar6 = uVar5 + *(longlong *)(param_2 + 0x638);
    if (DAT_18001bd30 == 0) {
      uVar3 = param_1;
    }
    uVar2 = (*(code *)param_3)(uVar3,*(longlong *)(param_2 + 0x638),uVar5,local_res10,lVar6);
    if (-1 < (int)uVar2) {
      *param_4 = *(undefined8 *)(param_2 + 0x638);
      *param_5 = lVar6;
      *param_6 = local_res10[0] >> 0xc;
    }
  }
  return uVar2;
}



===== ReadLogDataFromDisk @ 18000b644 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int ReadLogDataFromDisk(longlong param_1,longlong param_2,undefined8 param_3,uint param_4,
                       longlong param_5)

{
  code *pcVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined1 auStack_8c8 [32];
  longlong local_8a8;
  longlong local_8a0;
  longlong local_898;
  undefined8 local_888;
  short local_880;
  ushort local_87e;
  ulonglong local_868;
  undefined4 local_860;
  uint local_85c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_8c8;
  pcVar1 = *(code **)(param_1 + 0xa0);
  uVar7 = (ulonglong)param_4;
  iVar2 = -0x3fffffff;
  local_898 = param_2;
  memset(&local_888,0,0x838);
  lVar4 = 0;
  local_8a0 = 0;
  if (pcVar1 == (code *)0x0) {
    iVar2 = -0x3fffff45;
  }
  else {
    uVar5 = *(longlong *)(*(longlong *)(param_1 + 0x2a8) + uVar7 * 0x10) - param_5;
LAB_18000b6d8:
    if (lVar4 < 0x1000) {
      if (((uint)uVar7 < *(uint *)(param_1 + 0x2a0)) && (uVar5 != 0)) {
        uVar3 = uVar5;
        if ((longlong)(0x1000U - lVar4) < (longlong)uVar5) {
          uVar3 = 0x1000U - lVar4;
        }
        uVar6 = (ulonglong)*(uint *)(param_1 + 0x6c);
        if (uVar3 < *(uint *)(param_1 + 0x6c)) {
          uVar6 = uVar3;
        }
        if (0xfff < uVar6) {
          uVar6 = 0x1000;
        }
        local_860 = (undefined4)uVar6;
        local_868 = lVar4 + local_898 & 0xfffffffffffff000;
        local_85c = (uint)(lVar4 + local_898);
        local_888 = 0;
        local_87e = 0;
        local_8a8 = *(longlong *)(*(longlong *)(param_1 + 0x2a8) + 8 + uVar7 * 0x10) + param_5;
        local_880 = ((short)((ulonglong)(local_85c & 0xfff) + 0xfff + (uVar6 & 0xffffffff) >> 0xc) +
                    6) * 8;
        local_85c = local_85c & 0xfff;
        MmBuildMdlForNonPagedPool(&local_888);
        local_87e = local_87e | 1;
        if (((DAT_18001c548 & 2) == 0) ||
           (iVar2 = (*pcVar1)(1,&local_8a8,&local_888), iVar2 == -0x3fffff45)) {
          iVar2 = (*pcVar1)(0,&local_8a8,&local_888);
        }
        else {
          while (iVar2 == 0x103) {
            iVar2 = (*pcVar1)(2,&local_8a8,&local_888);
          }
        }
        if (-1 < iVar2) {
          if (DAT_18001c444 != 0x5003) {
            param_5 = param_5 + uVar6;
            lVar4 = local_8a0 + uVar6;
            uVar5 = uVar5 - uVar6;
            local_8a0 = lVar4;
            if (uVar5 == 0) {
              uVar7 = (ulonglong)((uint)uVar7 + 1);
              param_5 = 0;
              uVar5 = *(ulonglong *)(*(longlong *)(param_1 + 0x2a8) + uVar7 * 0x10);
            }
            goto LAB_18000b6d8;
          }
          iVar2 = -0x3fffffff;
        }
        _DAT_18001c438 = 0x5001;
        _DAT_18001c420 = pcVar1;
        _DAT_18001c43c = iVar2;
        goto LAB_18000b86b;
      }
      goto LAB_18000b6d8;
    }
  }
LAB_18000b86b:
  return iVar2;
}



===== RtlStringCchLengthA @ 18000b89c =====

uint RtlStringCchLengthA(char *param_1,longlong param_2,longlong *param_3)

{
  uint uVar1;
  longlong lVar2;
  
  if (param_1 == (char *)0x0) {
    uVar1 = 0xc000000d;
  }
  else {
    lVar2 = param_2;
    do {
      if (*param_1 == '\0') break;
      param_1 = param_1 + 1;
      lVar2 = lVar2 + -1;
    } while (lVar2 != 0);
    uVar1 = ~-(uint)(lVar2 != 0) & 0xc000000d;
    if (param_3 != (longlong *)0x0) {
      if (lVar2 == 0) {
        *param_3 = 0;
      }
      else {
        *param_3 = param_2 - lVar2;
      }
    }
    if (lVar2 != 0) {
      return uVar1;
    }
  }
  if (param_3 != (longlong *)0x0) {
    *param_3 = 0;
  }
  return uVar1;
}



===== RtlStringCchPrintfA @ 18000b8f8 =====

undefined8 RtlStringCchPrintfA(char *param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 local_res20;
  
  if (param_2 - 1U < 0x7fffffff) {
    local_res20 = param_4;
    uVar1 = RtlStringVPrintfWorkerA(param_1,param_2,param_3,(char *)param_3,(va_list)&local_res20);
  }
  else {
    uVar1 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = '\0';
    }
  }
  return uVar1;
}



===== RtlStringCchVPrintfA @ 18000b940 =====

undefined8 RtlStringCchVPrintfA(char *param_1,longlong param_2,undefined8 param_3,va_list param_4)

{
  undefined8 uVar1;
  
  if (param_2 - 1U < 0x7fffffff) {
    uVar1 = RtlStringVPrintfWorkerA(param_1,param_2,param_3,(char *)param_3,param_4);
  }
  else {
    uVar1 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = '\0';
    }
  }
  return uVar1;
}



===== RtlStringVPrintfWorkerA @ 18000b978 =====

undefined8
RtlStringVPrintfWorkerA
          (char *param_1,longlong param_2,undefined8 param_3,char *param_4,va_list param_5)

{
  ulonglong _Count;
  int iVar1;
  undefined8 uVar2;
  
  _Count = param_2 - 1;
  uVar2 = 0;
  iVar1 = _vsnprintf(param_1,_Count,param_4,param_5);
  if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
    param_1[_Count] = '\0';
    uVar2 = 0x80000005;
  }
  else if ((longlong)iVar1 == _Count) {
    param_1[_Count] = '\0';
  }
  return uVar2;
}



===== UpdateWriteProgressDisplay @ 18000b9dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void UpdateWriteProgressDisplay
               (undefined8 *param_1,uint param_2,undefined *param_3,undefined8 param_4)

{
  code *pcVar1;
  uint uVar2;
  char *pcVar3;
  undefined8 uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined1 auStackY_f8 [32];
  longlong local_b8;
  char acStack_a9 [113];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_f8;
  local_b8 = 0;
  if ((*(uint *)(param_1 + 4) & 2) == 0) {
    CrashdmpDisplayString("\n\r%s\n\r",StrBeginningDump,param_3,param_4);
  }
  if (((*(uint *)(param_1 + 4) & 2) == 0) || (*(int *)(param_1 + 0xc6) + 5U <= param_2)) {
    memset(acStack_a9 + 1,0,100);
    pcVar6 = StrDumpProgress;
    *(uint *)(param_1 + 0xc6) = param_2;
    pcVar5 = "%s  %d%% \r";
    uVar4 = 100;
    RtlStringCchPrintfA(acStack_a9 + 1,100,"%s  %d%% \r",StrDumpProgress);
    pcVar3 = acStack_a9 + 1;
    CrashdmpDisplayString(pcVar3,uVar4,pcVar5,pcVar6);
    if (param_3 != (undefined *)0x0) {
      pcVar3 = (char *)(ulonglong)param_2;
      (*(code *)param_3)();
    }
    CrashdmpLogSELCheckpoint_ULONG1(pcVar3,param_2);
    pcVar3 = acStack_a9 + 1;
    uVar2 = RtlStringCchLengthA(pcVar3,100,&local_b8);
    if (-1 < (int)uVar2) {
      uVar2 = (uint)local_b8;
      if (local_b8 + 2U < 100) {
        acStack_a9[local_b8 + 1] = '\n';
        if (99 < local_b8 + 1U) {
          __report_rangecheckfailure();
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        acStack_a9[local_b8 + 2] = '\0';
        if (DAT_18001c52b == '\x01') {
          pcVar3 = (char *)*param_1;
          WriteLogData((longlong)pcVar3,acStack_a9 + 1,uVar2 + 1);
        }
        uVar2 = uVar2 + 1;
      }
      else if (DAT_18001c52b == '\x01') {
        pcVar3 = (char *)*param_1;
        WriteLogData((longlong)pcVar3,acStack_a9 + 1,uVar2);
      }
      WriteDiagnosticData(pcVar3,acStack_a9 + 1,uVar2,0,0,0,(void *)0x0);
    }
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 2;
  }
  return;
}



===== WriteBitmapDump @ 18000bb50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint WriteBitmapDump(longlong *param_1,undefined *param_2,undefined *param_3,undefined8 param_4)

{
  longlong lVar1;
  bool bVar2;
  undefined *puVar3;
  char cVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong lVar7;
  ulonglong uVar8;
  longlong lVar9;
  uint uVar10;
  ulonglong uVar11;
  char *pcVar12;
  undefined4 *puVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  ulonglong uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  bool bVar19;
  undefined1 auStackY_958 [32];
  uint local_914;
  uint local_910 [2];
  ulonglong local_908;
  uint local_900;
  undefined4 local_8fc;
  ulonglong local_8f8;
  longlong *local_8f0;
  ulonglong *local_8e8;
  longlong local_8e0;
  ulonglong local_8d8;
  ulonglong local_8d0;
  longlong local_8c8;
  ulonglong local_8c0;
  ulonglong local_8b8;
  undefined *local_8b0;
  ulonglong local_8a8;
  longlong local_8a0;
  longlong local_898;
  longlong local_890;
  ulonglong local_888;
  ulonglong local_880;
  ulonglong local_878;
  longlong local_870;
  longlong *local_868;
  ulonglong local_860;
  undefined *local_858;
  longlong local_848 [256];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_958;
  lVar9 = param_1[0xc];
  local_878 = 0;
  local_888 = *(ulonglong *)(lVar9 + 0x2028);
  local_890 = 0;
  local_908 = 0;
  local_900 = 0;
  local_8a0 = 0;
  lVar7 = 0;
  local_898 = 0;
  local_8c8 = 0;
  bVar19 = param_3 != (undefined *)0x0;
  local_8e8 = (ulonglong *)0x0;
  local_8e0 = 0;
  local_910[0] = 0;
  local_8f0 = param_1;
  local_8b0 = param_3;
  local_868 = param_1;
  local_860 = local_888;
  local_858 = param_3;
  memset(local_848,0,0x800);
  uVar17 = 0;
  uVar18 = 0;
  uVar6 = Feature_CrashDumpOneMBTransferSize__private_IsEnabledNoReportingNoInline();
  lVar1 = *param_1;
  uVar10 = *(uint *)(lVar1 + 0x6c) >> 0xc;
  uVar5 = 0x100;
  if ((int)uVar6 == 0) {
    uVar5 = 0x10;
  }
  if (uVar5 < uVar10) {
    uVar10 = uVar5;
  }
  local_880 = (ulonglong)uVar10;
  if (DAT_18001c52b == '\x01') {
    pcVar12 = "Starting write of kernel bitmap dump header.\r\n";
    if ((int)param_1[3] != 6) {
      pcVar12 = "Starting write of full bitmap dump header.\r\n";
    }
    WriteLogString(lVar1,pcVar12,lVar1,param_4);
  }
  uVar6 = *(ulonglong *)(lVar9 + 0x2020);
  if (0x1fff < uVar6) {
    uVar6 = uVar6 - 0x2000;
  }
  uVar15 = 2;
  local_914 = WriteBufferToDisk(param_1,lVar9 + 0x2000,uVar6,2,'\0');
  if ((int)local_914 < 0) {
    if (DAT_18001c528 == '\0') {
      DAT_18001c33c = DAT_18001c33c | 0x100000;
      uVar14 = 4;
      puVar13 = &DAT_18001c33c;
      CrashdmpTelemetrySaveEnvironmentVariable(L"BugCheckProgress",&DAT_18001c33c,4);
      WriteLogProgress(DAT_18001c33c,puVar13,uVar14,uVar15);
    }
    uVar18 = 0x30001;
  }
  else {
    local_8b8 = *(ulonglong *)(lVar9 + 0x2030);
    local_870 = lVar9 + 0x2038;
    local_878 = local_8b8;
    if (DAT_18001c52b == '\x01') {
      WriteLogString(*param_1,
                     "Finish write of bitmap dump header.\r\nStarting write of memory dump data.\r\n"
                     ,uVar6,uVar15);
      WriteLogElapsedDuration();
      if (DAT_18001c544 != 0) {
        lVar7 = KeQueryPerformanceCounter(&local_8a0);
        local_898 = lVar7;
      }
    }
LAB_18000bd6f:
    if ((local_908 < local_8b8) && (-1 < (int)local_914)) {
      local_8f8 = 0;
      uVar6 = 0;
      local_8c0 = 0;
      local_8a8 = 0;
      while( true ) {
        uVar16 = local_8a8;
        local_8d8 = local_8c0;
        cVar4 = FindNextSetBitRange64(&local_878,local_908,&local_908,&local_8f8);
        if ((cVar4 == '\0') && (uVar16 == 0)) goto LAB_18000c480;
        if (bVar19) goto LAB_18000be8e;
        if (cVar4 == '\0') break;
        if (uVar16 == 0) {
LAB_18000bdfc:
          if (local_880 <= local_8f8) {
LAB_18000be67:
            if (cVar4 == '\0') break;
            goto LAB_18000be8e;
          }
        }
        else if (local_880 <= uVar16) {
          if (uVar16 == 0) goto LAB_18000bdfc;
          goto LAB_18000be67;
        }
        local_8c0 = 0;
        for (local_8d8 = local_8c0; (uVar6 < local_880 && (local_8d8 < local_8f8));
            local_8d8 = local_8d8 + 1) {
          local_848[uVar6] = local_908 + local_8d8;
          uVar6 = uVar6 + 1;
        }
        uVar16 = uVar16 + local_8d8;
        local_8c0 = local_8d8;
        local_8a8 = uVar16;
        if (local_880 <= uVar16) goto LAB_18000be8e;
        local_908 = local_908 + local_8d8;
      }
      local_8c0 = local_8d8;
      if (uVar16 != 0) {
        local_8d8 = 0;
        local_8c0 = local_8d8;
      }
LAB_18000be8e:
      do {
        if ((local_8f8 == 0) && (uVar16 == 0)) goto LAB_18000bd6f;
        if (uVar16 == 0) {
          local_8d0 = 0xa00;
          if (local_8f8 < 0xa00) {
            local_8d0 = local_8f8;
          }
        }
        else {
          local_8d0 = uVar16;
        }
        uVar6 = local_8d0;
        uVar8 = (ulonglong)local_910[0];
LAB_18000bece:
        if ((bVar19) && ((int)uVar8 == 0)) {
          uVar8 = GetEncryptedData(local_908,(longlong)param_1,local_8b0,&local_8e0,
                                   (longlong *)&local_8e8,local_910);
          puVar3 = local_8b0;
          local_914 = (uint)uVar8;
          if ((int)local_914 < 0) {
            if (local_914 != 0xc0000225) {
              uVar6 = uVar8 & 0xffffffff;
              WriteDiagnosticDataToDumpHeader
                        (*param_1,local_914,(longlong)local_8b0,local_914,"SK/HV",
                         "WriteBitmapDump: GetEncryptedDataRoutine failed with error: 0x%X\r\n",
                         (char)uVar8);
              WriteLogString(*param_1,
                             "WriteBitmapDump: GetEncryptedDataRoutine failed with error: 0x%X\r\n",
                             uVar8 & 0xffffffff,uVar6);
              *(uint *)((longlong)param_1 + 0x6fc) = local_914;
              *(undefined4 *)(param_1 + 0xdf) = 0x5005;
              param_1[0xdc] = (longlong)puVar3;
              uVar18 = 0x30002;
              goto LAB_18000c4a8;
            }
            bVar19 = false;
            uVar8 = 0;
            local_910[0] = 0;
          }
          else {
            uVar8 = (ulonglong)local_910[0];
          }
        }
        bVar2 = false;
        if ((int)uVar8 != 0) {
          uVar11 = *local_8e8;
          if (uVar11 < uVar6 + local_908) {
            if (uVar11 == local_908) {
              bVar2 = true;
              for (uVar6 = 1;
                  ((local_8d0 = uVar6, uVar6 < uVar8 && (uVar6 < local_8f8)) &&
                  (uVar11 = uVar11 + 1, uVar11 == local_8e8[uVar6])); uVar6 = uVar6 + 1) {
              }
            }
            else {
              if (uVar11 <= local_908) goto LAB_18000bf64;
              uVar6 = uVar11 - local_908;
              local_8d0 = uVar6;
            }
          }
        }
        if (bVar2) {
          if (param_1[0xc9] == 0) {
            uVar8 = 2;
            local_914 = WriteBufferToDisk(param_1,local_8e0,uVar6 << 0xc,2,'\0');
            if (((*(uint *)((longlong)local_8f0 + 0x704) & 0xf000) == 0x9000) &&
               (local_900 == (*(uint *)((longlong)local_8f0 + 0x704) & 0xff))) {
              local_914 = 0xc0000001;
            }
            if ((int)local_914 < 0) {
              uVar18 = 0x30005;
              goto LAB_18000c1c7;
            }
          }
          else {
            uVar8 = 0;
            local_914 = WritePageSpanToDisk(param_1,(longlong *)
                                                    (param_1[0xc9] +
                                                    ((ulonglong)(local_8e0 - param_1[199]) >> 0xc) *
                                                    8),uVar6,'\0');
            if (((*(uint *)((longlong)local_8f0 + 0x704) & 0xf000) == 0x9000) &&
               (local_900 == (*(uint *)((longlong)local_8f0 + 0x704) & 0xff))) {
              local_914 = 0xc0000001;
            }
            uVar18 = uVar17;
            if ((int)local_914 < 0) {
              uVar18 = 0x30006;
            }
LAB_18000c1c7:
            uVar17 = uVar18;
            local_8fc = uVar18;
          }
          local_910[0] = local_910[0] - (int)uVar6;
          local_8e8 = local_8e8 + uVar6;
          local_8e0 = local_8e0 + uVar6 * 0x1000;
        }
        else if (uVar16 == 0) {
          uVar8 = CONCAT71((int7)(uVar8 >> 8),1);
          local_914 = WritePageSpanToDisk(param_1,(longlong *)&local_908,uVar6,'\x01');
          if (((*(uint *)((longlong)local_8f0 + 0x704) & 0xf000) == 0x9000) &&
             (local_900 == (*(uint *)((longlong)local_8f0 + 0x704) & 0xff))) {
            local_914 = 0xc0000001;
          }
          if ((int)local_914 < 0) {
            uVar17 = 0x30003;
            uVar18 = 0x30003;
            goto LAB_18000c0fd;
          }
        }
        else {
          uVar8 = 0;
          local_914 = WritePageSpanToDisk(param_1,local_848,uVar6,'\0');
          if (((*(uint *)((longlong)local_8f0 + 0x704) & 0xf000) == 0x9000) &&
             (local_900 == (*(uint *)((longlong)local_8f0 + 0x704) & 0xff))) {
            local_914 = 0xc0000001;
          }
          if ((int)local_914 < 0) {
            uVar17 = 0x30004;
            uVar18 = 0x30004;
LAB_18000c0fd:
            local_8fc = uVar18;
          }
        }
        if (((int)local_914 < 0) && (DAT_18001c528 == '\0')) {
          DAT_18001c33c = DAT_18001c33c | 0x10000;
          uVar15 = 4;
          puVar13 = &DAT_18001c33c;
          CrashdmpTelemetrySaveEnvironmentVariable(L"BugCheckProgress",&DAT_18001c33c,4);
          WriteLogProgress(DAT_18001c33c,puVar13,uVar15,uVar8);
        }
        if ((int)local_914 < 0) {
          uVar6 = (ulonglong)local_914;
          WriteDiagnosticDataToDumpHeader
                    (*param_1,local_914,0x18000bb50,local_914,"Crashdmp",
                     "WriteBitmapDump: WritePageSpanToDisk failed with error: 0x%X\r\n",
                     (char)local_914);
          WriteLogString(*param_1,"WriteBitmapDump: WritePageSpanToDisk failed with error: 0x%X\r\n"
                         ,(ulonglong)local_914,uVar6);
          goto LAB_18000c4a8;
        }
        if (uVar16 == 0) {
          local_8f8 = local_8f8 - uVar6;
          uVar11 = uVar6;
        }
        else {
          uVar16 = 0;
          local_8a8 = 0;
          local_8f8 = 0;
          uVar11 = local_8d8;
        }
        local_908 = local_908 + uVar11;
        local_890 = local_890 + uVar6;
        local_8c8 = local_8c8 + uVar6;
        uVar10 = (uint)((ulonglong)(local_890 * 100) / local_888);
        if (((local_900 + 5 <= uVar10) && (DAT_18001c52b == '\x01')) && (DAT_18001c544 != 0)) {
          lVar9 = KeQueryPerformanceCounter(0);
          uVar8 = (lVar9 - lVar7) * 0x100000;
          if (lVar9 <= lVar7) {
            uVar8 = uVar8 - 0x100000;
          }
          uVar8 = (ulonglong)(local_8c8 * local_8a0 * 0x1000) / uVar8;
          WriteLogString(*param_1,"WriteBitmapDump: pages written = %Id, MB per sec = %d.\r\n",
                         local_8c8,uVar8);
          local_8c8 = 0;
          local_900 = uVar10;
          lVar7 = KeQueryPerformanceCounter(0);
          local_898 = lVar7;
        }
        UpdateWriteProgressDisplay(param_1,uVar10,param_2,uVar8);
      } while( true );
    }
LAB_18000c480:
    if (DAT_18001c52b == '\x01') {
      WriteLogString(*param_1,
                     "Finish write of bitmap dump data. Total pages:%I64d Pages written:%I64d\r\n",
                     local_888,local_890);
    }
  }
LAB_18000c4a8:
  if ((int)local_914 < 0) {
    CrashdmpLogSELError(uVar18,local_914);
  }
  return local_914;
LAB_18000bf64:
  do {
    local_910[0] = (int)uVar8 - 1;
    uVar8 = (ulonglong)local_910[0];
    local_8e8 = local_8e8 + 1;
    local_8e0 = local_8e0 + 0x1000;
    if (local_910[0] == 0) break;
  } while (*local_8e8 < local_908);
  goto LAB_18000bece;
}



===== WriteBufferToDisk @ 18000c4e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int WriteBufferToDisk(longlong *param_1,longlong param_2,ulonglong param_3,uint param_4,char param_5
                     )

{
  int iVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  code *pcVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined1 auStack_908 [32];
  uint local_8d8;
  longlong local_8d0;
  code *local_8c8;
  uint local_8c0;
  ulonglong local_8b8;
  longlong local_8b0;
  ulonglong local_8a8;
  ulonglong local_8a0;
  undefined8 local_898;
  short local_890;
  ushort local_88e;
  ulonglong local_878;
  uint local_870;
  uint local_86c;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStack_908;
  local_8c8 = *(code **)(*param_1 + 0x40);
  pcVar5 = *(code **)(*param_1 + 0x80);
  local_8c0 = param_4;
  local_8b0 = param_2;
  local_8a0 = param_3;
  memset(&local_898,0,0x838);
  iVar1 = 0;
  local_8b8 = 0;
  if ((((param_4 == 1) && (param_5 == '\0')) && ((int)param_1[0xf2] == -1)) &&
     (param_1[0xf3] == 0x7fffffffffffffff)) {
    *(undefined4 *)(param_1 + 0xf2) = *(undefined4 *)((longlong)param_1 + 0x624);
    param_1[0xf3] = param_1[0xc5];
  }
  local_8d8 = *(uint *)((longlong)param_1 + 0x624);
  lVar4 = param_1[0xc5];
  lVar6 = (ulonglong)local_8d8 * 0x10;
  uVar3 = *(longlong *)(param_1[0xb] + lVar6) - lVar4;
  if (param_3 != 0) {
    do {
      if ((*(uint *)(param_1 + 10) <= local_8d8) || (uVar3 == 0)) {
        iVar1 = -0x3fffffdd;
        break;
      }
      uVar2 = uVar3;
      if (param_3 - local_8b8 < uVar3) {
        uVar2 = param_3 - local_8b8;
      }
      uVar7 = (ulonglong)*(uint *)(*param_1 + 0x6c);
      if (uVar2 < *(uint *)(*param_1 + 0x6c)) {
        uVar7 = uVar2;
      }
      if (0xfff < uVar7) {
        uVar7 = 0x1000;
      }
      if (((param_5 == '\0') && (DmpEncryptionContext != '\0')) && (DAT_18001c528 == '\0')) {
        if (DAT_18001b3ac <= uVar7) {
          uVar7 = (ulonglong)DAT_18001b3ac;
        }
      }
      local_8a8 = uVar7 & 0xffffffff;
      local_86c = (uint)(local_8b0 + local_8b8);
      local_898 = 0;
      local_88e = 0;
      local_8d0 = *(longlong *)(param_1[0xb] + 8 + lVar6) + lVar4;
      local_890 = ((short)((ulonglong)(local_86c & 0xfff) + 0xfff + local_8a8 >> 0xc) + 6) * 8;
      local_878 = local_8b0 + local_8b8 & 0xfffffffffffff000;
      local_86c = local_86c & 0xfff;
      local_870 = (uint)uVar7;
      MmBuildMdlForNonPagedPool(&local_898);
      local_88e = local_88e | 1;
      InvokeDumpCallbacks(param_1,local_878,(uint)uVar7,(ulonglong)local_8c0,0);
      if (((param_5 == '\0') && (DmpEncryptionContext != '\0')) && (DAT_18001c528 == '\0')) {
        iVar1 = (*DAT_18001b3a0)(local_8b0 + local_8b8,uVar7,DAT_18001b3b8,uVar7);
        if (DAT_18001c444 == 0x5006) {
          iVar1 = -0x3fffffff;
        }
        else if (-1 < iVar1) {
          local_870 = (uint)local_8a8;
          local_878 = DAT_18001b3b8 & 0xfffffffffffff000;
          local_898 = 0;
          local_88e = 0;
          local_86c = (uint)DAT_18001b3b8 & 0xfff;
          local_890 = ((short)(local_8a8 + 0xfff + (DAT_18001b3b8 & 0xfff) >> 0xc) + 6) * 8;
          MmBuildMdlForNonPagedPool(&local_898);
          local_88e = local_88e | 1;
          goto LAB_18000c7c2;
        }
        param_1[0xdc] = (longlong)DAT_18001b3a0;
        *(undefined4 *)(param_1 + 0xdf) = 0x5006;
LAB_18000c8f2:
        *(int *)((longlong)param_1 + 0x6fc) = iVar1;
        break;
      }
LAB_18000c7c2:
      if (((DAT_18001c548 & 2) == 0) || (pcVar5 == (code *)0x0)) {
        iVar1 = (*local_8c8)(&local_8d0,&local_898);
        if (-1 < iVar1) goto LAB_18000c869;
LAB_18000c91f:
        param_1[0xdc] = (longlong)local_8c8;
LAB_18000c922:
        *(undefined4 *)(param_1 + 0xdf) = 0x5001;
        goto LAB_18000c8f2;
      }
      iVar1 = (*pcVar5)(1,&local_8d0,&local_898);
      if (iVar1 == -0x3fffff45) {
        iVar1 = (*local_8c8)(&local_8d0,&local_898);
        if (iVar1 < 0) {
          pcVar5 = local_8c8;
          goto LAB_18000c810;
        }
      }
      else {
        while (iVar1 == 0x103) {
          iVar1 = (*pcVar5)(2,&local_8d0,&local_898);
        }
        if (iVar1 < 0) {
LAB_18000c810:
          local_8c8 = pcVar5;
          goto LAB_18000c91f;
        }
      }
LAB_18000c869:
      if (*(int *)((longlong)param_1 + 0x704) == 0x5001) {
        iVar1 = -0x3fffffff;
        param_1[0xdc] = (longlong)local_8c8;
        goto LAB_18000c922;
      }
      if (iVar1 < 0) goto LAB_18000c922;
      uVar2 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
      if ((int)uVar2 != 0) {
        if (local_870 <= uVar7) {
          uVar7 = (ulonglong)local_870;
        }
      }
      lVar4 = lVar4 + uVar7;
      local_8b8 = local_8b8 + uVar7;
      uVar3 = uVar3 - uVar7;
      if (uVar3 == 0) {
        local_8d8 = local_8d8 + 1;
        lVar4 = 0;
        lVar6 = (ulonglong)local_8d8 * 0x10;
        uVar3 = *(ulonglong *)(param_1[0xb] + lVar6);
      }
      param_3 = local_8a0;
    } while (local_8b8 < local_8a0);
  }
  *(uint *)((longlong)param_1 + 0x624) = local_8d8;
  param_1[0xc5] = lVar4;
  return iVar1;
}



===== WriteBufferToDumpFilters @ 18000c970 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 WriteBufferToDumpFilters(undefined8 *param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong lVar3;
  void *_Dst;
  uint uVar4;
  ulonglong _Size;
  undefined8 uVar5;
  longlong lVar6;
  undefined1 auStackY_8c8 [32];
  undefined8 *puVar7;
  undefined8 local_888;
  short local_880;
  ushort local_87e;
  void *local_870;
  ulonglong local_868;
  undefined4 local_860;
  uint local_85c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_8c8;
  memset(&local_888,0,0x838);
  uVar4 = *(uint *)((longlong)param_1 + 0x624);
  uVar5 = 0;
  lVar3 = param_1[0xc5];
  lVar6 = (ulonglong)uVar4 * 0x10;
  puVar7 = (undefined8 *)0x0;
  uVar2 = *(longlong *)(lVar6 + param_1[0xb]) - lVar3;
  do {
    if ((undefined8 *)0x3ffff < puVar7) {
LAB_18000cb17:
      *(uint *)((longlong)param_1 + 0x624) = uVar4;
      param_1[0xc5] = lVar3;
      return uVar5;
    }
    if ((*(uint *)(param_1 + 10) <= uVar4) || (uVar2 == 0)) {
      uVar5 = 0xc0000023;
      goto LAB_18000cb17;
    }
    _Size = uVar2;
    if (0x40000U - (longlong)puVar7 < uVar2) {
      _Size = 0x40000U - (longlong)puVar7;
    }
    if (0xfff < _Size) {
      _Size = 0x1000;
    }
    _Dst = (void *)(param_2 + (longlong)puVar7);
    local_888 = 0;
    local_87e = 0;
    lVar1 = *(longlong *)(param_1[0xb] + 8 + lVar6) + lVar3;
    local_860 = (undefined4)_Size;
    local_868 = (ulonglong)_Dst & 0xfffffffffffff000;
    local_880 = ((short)((ulonglong)((uint)_Dst & 0xfff) + 0xfff + (_Size & 0xffffffff) >> 0xc) + 6)
                * 8;
    local_85c = (uint)_Dst & 0xfff;
    MmBuildMdlForNonPagedPool(&local_888);
    local_87e = local_87e | 1;
    FilterCallback(2,(undefined8 *)*param_1,(undefined8 *)(auStackY_8c8 + 0x30),&local_888,puVar7,
                   param_2,lVar1);
    if (_Dst != local_870) {
      memcpy(_Dst,local_870,_Size);
    }
    lVar3 = lVar3 + _Size;
    puVar7 = (undefined8 *)((longlong)puVar7 + _Size);
    uVar2 = uVar2 - _Size;
    if (uVar2 == 0) {
      uVar4 = uVar4 + 1;
      lVar3 = 0;
      lVar6 = (ulonglong)uVar4 * 0x10;
      uVar2 = *(ulonglong *)(lVar6 + param_1[0xb]);
    }
  } while( true );
}



===== WriteByteStreamToDisk @ 18000cb5c =====

int WriteByteStreamToDisk(longlong *param_1,longlong param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  
  uVar4 = 0;
  if (param_3 == 0) {
    iVar2 = WriteBufferToDisk(param_1,param_1[199],0x1000,3,'\0');
    if (iVar2 < 0) {
      return iVar2;
    }
    memset((void *)param_1[199],0,0x1000);
  }
  else {
    uVar3 = param_3;
    do {
      uVar1 = DAT_18001c5c0;
      if (0x1000 - DAT_18001c5c0 <= uVar3) {
        uVar3 = 0x1000 - DAT_18001c5c0;
      }
      memcpy((void *)((ulonglong)DAT_18001c5c0 + param_1[199]),(void *)(uVar4 + param_2),
             (ulonglong)uVar3);
      DAT_18001c5c0 = uVar1 + uVar3;
      if (DAT_18001c5c0 == 0x1000) {
        iVar2 = WriteBufferToDisk(param_1,param_1[199],0x1000,3,'\0');
        if (iVar2 < 0) {
          return iVar2;
        }
        memset((void *)param_1[199],0,0x1000);
        DAT_18001c5c0 = 0;
      }
      uVar3 = (int)uVar4 + uVar3;
      uVar4 = (ulonglong)uVar3;
      uVar3 = param_3 - uVar3;
    } while (uVar3 != 0);
  }
  return 0;
}



===== WriteDiagnosticData @ 18000cc64 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int WriteDiagnosticData(undefined8 param_1,void *param_2,uint param_3,undefined4 param_4,
                       longlong param_5,undefined4 param_6,void *param_7)

{
  undefined4 uVar1;
  undefined8 uVar2;
  int iVar3;
  longlong lVar5;
  longlong lVar4;
  ulonglong uVar6;
  undefined4 *_Dst;
  uint uVar7;
  uint uVar8;
  longlong lVar9;
  size_t sVar10;
  
  if (((DAT_18001bd60 >> 0xe & 1) != 0) || ((DAT_18001c548 & 4) == 0)) {
    return -0x3fffffff;
  }
  if ((((DAT_18001bd60 >> 0xc & 1) == 0) || (DAT_18001c4d0 == -1)) ||
     (DAT_18001c4d8 == 0x7fffffffffffffff)) {
    return -0x3ffffe7c;
  }
  if ((DumpHeaderSnapshot != 0x45474150) || (DAT_18001c5d4 != 0x34365544)) {
    return -0x3ffffefe;
  }
  if ((DAT_18001bd60 >> 0xd & 1) == 0) {
    sVar10 = 0x298;
    _Dst = &DAT_18001d628;
  }
  else {
    if (DAT_18001d628 != 0x298) {
      if ((DAT_18001d62c != 0x298) && (8 < DAT_18001d63c)) {
        return -0x3fffffce;
      }
      if (DAT_18001d628 != 0x298) goto LAB_18000cd53;
    }
    if (DAT_18001d62c != 0x298) goto LAB_18000cd53;
    sVar10 = 0x100;
    _Dst = (undefined4 *)&DAT_18001d7c0;
  }
  memset(_Dst,0,sVar10);
LAB_18000cd53:
  DAT_18001d628 = 0x298;
  DAT_18001d62c = 0x298;
  _DAT_18001d634 = DAT_18001c370;
  _DAT_18001d638 = param_4;
  if (((param_5 != 0) && (param_7 != (void *)0x0)) && ((DAT_18001d630 & 1) == 0)) {
    if (DAT_18001d63c < 8) {
      lVar9 = -1;
      lVar4 = -1;
      do {
        lVar5 = lVar4;
        lVar4 = lVar5 + 1;
      } while (*(char *)(lVar4 + (longlong)param_7) != '\0');
      if (lVar5 + 2U < 0x20) {
        do {
          lVar9 = lVar9 + 1;
        } while (*(char *)(lVar9 + (longlong)param_7) != '\0');
        uVar8 = (int)lVar9 + 1;
      }
      else {
        uVar8 = 0x20;
      }
      uVar7 = 0;
      if (DAT_18001d63c != 0) {
        do {
          if ((*(longlong *)(&DAT_18001d640 + (ulonglong)uVar7 * 0x30) == param_5) &&
             (uVar6 = RtlCompareMemory(&DAT_18001d650 + (ulonglong)uVar7 * 0x30,param_7,uVar8),
             uVar6 == uVar8)) break;
          uVar7 = uVar7 + 1;
        } while (uVar7 < DAT_18001d63c);
      }
      if (uVar7 == DAT_18001d63c) {
        lVar4 = (ulonglong)uVar7 * 0x30;
        *(longlong *)(&DAT_18001d640 + lVar4) = param_5;
        *(undefined4 *)(&DAT_18001d648 + lVar4) = param_6;
        memcpy(&DAT_18001d650 + lVar4,param_7,(ulonglong)uVar8);
        if (uVar8 == 0x20) {
          (&DAT_18001d66f)[lVar4] = 0;
        }
        DAT_18001d63c = DAT_18001d63c + 1;
      }
    }
    else {
      DAT_18001d630 = DAT_18001d630 | 1;
    }
  }
  sVar10 = (size_t)param_3;
  if (0xff < param_3) {
    sVar10 = 0x100;
  }
  memcpy(&DAT_18001d7c0,param_2,sVar10);
  if ((uint)sVar10 < 0x100) {
    (&DAT_18001d7c0)[sVar10] = 0;
  }
  else {
    DAT_18001d8bf = 0;
  }
  uVar2 = DAT_18001c368;
  uVar1 = DAT_18001c364;
  DAT_18001c364 = DAT_18001c4d0;
  DAT_18001c368 = DAT_18001c4d8;
  if ((DAT_18001bd60 & 0x2000) == 0) {
    _DAT_18001d620 = _DAT_18001d620 | 0x1000;
  }
  iVar3 = WriteBufferToDisk(&DAT_18001bd40,0x18001c5d0,0x2000,1,'\0');
  if ((-1 < iVar3) && ((DAT_18001bd60 >> 0xd & 1) == 0)) {
    DAT_18001bd60 = DAT_18001bd60 | 0x2000;
  }
  DAT_18001c364 = uVar1;
  DAT_18001c368 = uVar2;
  return iVar3;
}



===== WriteDiagnosticDataToDumpHeader @ 18000cf94 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong WriteDiagnosticDataToDumpHeader
                    (undefined8 param_1,undefined4 param_2,longlong param_3,undefined4 param_4,
                    void *param_5,undefined8 param_6,char param_7)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  char *pcVar4;
  undefined1 auStackY_188 [32];
  longlong local_148 [2];
  char local_138 [256];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_188;
  local_148[0] = 0;
  memset(local_138,0,0x100);
  local_148[0] = 0;
  if (((DAT_18001bd60 & 0x4000) == 0) && ((DAT_18001c548 & 4) != 0)) {
    uVar3 = RtlStringCchVPrintfA(local_138,0x100,param_6,&param_7);
    if (-1 < (int)uVar3) {
      pcVar4 = local_138;
      uVar1 = RtlStringCchLengthA(pcVar4,0x100,local_148);
      uVar3 = CONCAT44(extraout_var,uVar1);
      if (-1 < (int)uVar1) {
        iVar2 = WriteDiagnosticData(pcVar4,local_138,(uint)local_148[0],param_2,param_3,param_4,
                                    param_5);
        uVar3 = CONCAT44(extraout_var_00,iVar2);
      }
    }
  }
  else {
    uVar3 = 0xc0000001;
  }
  return uVar3;
}



===== WriteLogData @ 18000d080 =====

void WriteLogData(longlong param_1,void *param_2,uint param_3)

{
  void *_Dst;
  bool bVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  
  uVar6 = (ulonglong)param_3;
  bVar1 = false;
  uVar5 = 0;
  if ((((DAT_18001c52b != '\0') && (*(longlong *)(param_1 + 0x2c0) != 0)) &&
      (*(char *)(param_1 + 0x233) == '\0')) &&
     (*(int *)(param_1 + 0x298) + param_3 <= *(uint *)(param_1 + 0x294))) {
    uVar4 = *(uint *)(param_1 + 0x2b0);
    _Dst = (void *)(*(longlong *)(param_1 + 0x2c0) + (ulonglong)uVar4);
    if (uVar4 + param_3 < 0x1001) {
      memcpy(_Dst,param_2,uVar6);
      cVar3 = '\0';
      if (*(int *)(param_1 + 0x2b0) + param_3 == 0x1000) {
        cVar3 = '\x01';
      }
    }
    else {
      uVar5 = 0x1000 - uVar4;
      bVar1 = true;
      uVar6 = (ulonglong)uVar5;
      memcpy(_Dst,param_2,uVar6);
      cVar3 = '\x01';
    }
    iVar2 = WriteLogDataToDisk(param_1,*(longlong *)(param_1 + 0x2c0),uVar6,cVar3);
    if (-1 < iVar2) {
      if (bVar1) {
        *(uint *)(param_1 + 0x298) = *(int *)(param_1 + 0x298) + uVar5;
        memset(*(void **)(param_1 + 0x2c0),0,0x1000);
        uVar4 = param_3 - uVar5;
        *(undefined4 *)(param_1 + 0x2b0) = 0;
        if (uVar4 < 0x1001) {
          uVar6 = (ulonglong)uVar4;
          memcpy(*(void **)(param_1 + 0x2c0),(void *)((ulonglong)uVar5 + (longlong)param_2),uVar6);
          iVar2 = WriteLogDataToDisk(param_1,*(longlong *)(param_1 + 0x2c0),uVar6,'\0');
          if (-1 < iVar2) {
            *(uint *)(param_1 + 0x2b0) = uVar4;
            *(int *)(param_1 + 0x298) = *(int *)(param_1 + 0x298) + (param_3 - uVar5);
          }
        }
        else {
          uVar7 = 0x1000;
          memcpy(*(void **)(param_1 + 0x2c0),(void *)((ulonglong)uVar5 + (longlong)param_2),0x1000);
          iVar2 = WriteLogDataToDisk(param_1,*(longlong *)(param_1 + 0x2c0),uVar7,'\x01');
          if (-1 < iVar2) {
            memset(*(void **)(param_1 + 0x2c0),0,0x1000);
            *(int *)(param_1 + 0x298) = *(int *)(param_1 + 0x298) + 0x1000;
            *(undefined4 *)(param_1 + 0x2b0) = 0;
          }
        }
      }
      else {
        *(uint *)(param_1 + 0x298) = *(int *)(param_1 + 0x298) + param_3;
        if (cVar3 == '\0') {
          *(int *)(param_1 + 0x2b0) = *(int *)(param_1 + 0x2b0) + param_3;
        }
        else {
          memset(*(void **)(param_1 + 0x2c0),0,0x1000);
          *(undefined4 *)(param_1 + 0x2b0) = 0;
        }
      }
    }
  }
  return;
}



===== WriteLogDataToDisk @ 18000d26c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int WriteLogDataToDisk(longlong param_1,longlong param_2,undefined8 param_3,char param_4)

{
  int iVar1;
  code *pcVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint uVar6;
  longlong lVar7;
  uint uVar8;
  ulonglong uVar9;
  undefined1 auStack_8e8 [48];
  char local_8b8;
  longlong local_8b0;
  code *local_8a8;
  code *local_8a0;
  longlong local_898;
  longlong local_890;
  longlong local_888;
  undefined8 local_878;
  short local_870;
  ushort local_86e;
  ulonglong local_858;
  uint local_850;
  uint local_84c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_8e8;
  pcVar2 = *(code **)(param_1 + 0x40);
  local_8a0 = *(code **)(param_1 + 0x80);
  local_8b8 = param_4;
  local_8a8 = pcVar2;
  local_890 = param_2;
  local_888 = param_1;
  memset(&local_878,0,0x838);
  uVar8 = *(uint *)(param_1 + 0x2b4);
  lVar5 = *(longlong *)(param_1 + 0x2b8);
  lVar7 = (ulonglong)uVar8 * 0x10;
  local_898 = 0;
  uVar4 = *(longlong *)(*(longlong *)(param_1 + 0x2a8) + lVar7) - lVar5;
  do {
    if ((*(uint *)(param_1 + 0x2a0) <= uVar8) || (uVar4 == 0)) {
      iVar1 = -0x3fffffdd;
LAB_18000d4df:
      if ((local_8b8 == '\x01') && (-1 < iVar1)) {
        *(uint *)(param_1 + 0x2b4) = uVar8;
        *(longlong *)(param_1 + 0x2b8) = lVar5;
      }
      return iVar1;
    }
    uVar3 = uVar4;
    if ((longlong)(0x1000U - local_898) < (longlong)uVar4) {
      uVar3 = 0x1000U - local_898;
    }
    uVar9 = (ulonglong)*(uint *)(param_1 + 0x6c);
    if (uVar3 < *(uint *)(param_1 + 0x6c)) {
      uVar9 = uVar3;
    }
    local_878 = 0;
    if (0xfff < uVar9) {
      uVar9 = 0x1000;
    }
    local_86e = 0;
    local_850 = (uint)uVar9;
    uVar6 = (uint)(local_898 + local_890);
    local_8b0 = *(longlong *)(*(longlong *)(param_1 + 0x2a8) + 8 + lVar7) + lVar5;
    local_858 = local_898 + local_890 & 0xfffffffffffff000;
    local_84c = uVar6 & 0xfff;
    local_870 = ((short)((ulonglong)(uVar6 & 0xfff) + 0xfff + (uVar9 & 0xffffffff) >> 0xc) + 6) * 8;
    MmBuildMdlForNonPagedPool(&local_878);
    local_86e = local_86e | 1;
    if (((DAT_18001c548 & 2) == 0) || (local_8a0 == (code *)0x0)) {
LAB_18000d449:
      iVar1 = (*pcVar2)(&local_8b0,&local_878);
    }
    else {
      iVar1 = (*local_8a0)(1,&local_8b0,&local_878,0);
      pcVar2 = local_8a0;
      if (iVar1 == -0x3fffff45) {
        pcVar2 = local_8a8;
        goto LAB_18000d449;
      }
      if (iVar1 == 0x103) {
        do {
          iVar1 = (*pcVar2)(2,&local_8b0,&local_878);
        } while (iVar1 == 0x103);
        param_1 = local_888;
      }
    }
    if (iVar1 < 0) {
      _DAT_18001c420 = local_8a8;
      _DAT_18001c438 = 0x5001;
      _DAT_18001c43c = iVar1;
      goto LAB_18000d4df;
    }
    uVar3 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
    if ((int)uVar3 != 0) {
      if (local_850 <= uVar9) {
        uVar9 = (ulonglong)local_850;
      }
    }
    lVar5 = lVar5 + uVar9;
    local_898 = local_898 + uVar9;
    uVar4 = uVar4 - uVar9;
    if (uVar4 == 0) {
      uVar8 = uVar8 + 1;
      lVar5 = 0;
      lVar7 = (ulonglong)uVar8 * 0x10;
      uVar4 = *(ulonglong *)(lVar7 + *(longlong *)(param_1 + 0x2a8));
    }
    if (0xfff < local_898) goto LAB_18000d4df;
    pcVar2 = local_8a8;
  } while( true );
}



===== WriteLogString @ 18000d530 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void WriteLogString(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined1 auStack_3e8 [32];
  longlong local_3c8 [2];
  char local_3b8 [912];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_3e8;
  local_3c8[0] = 0;
  local_res18 = param_3;
  local_res20 = param_4;
  memset(local_3b8,0,900);
  local_3c8[0] = 0;
  if ((DAT_18001c52b != '\0') && (*(longlong *)(param_1 + 0x2c0) != 0)) {
    uVar2 = RtlStringCchVPrintfA(local_3b8,900,param_2,(va_list)&local_res18);
    if (-1 < (int)uVar2) {
      uVar1 = RtlStringCchLengthA(local_3b8,900,local_3c8);
      if (-1 < (int)uVar1) {
        WriteLogData(param_1,local_3b8,(uint)local_3c8[0]);
      }
    }
  }
  return;
}



===== WriteMiniDump @ 18000d5f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int WriteMiniDump(longlong *param_1,undefined *param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  
  lVar2 = param_1[0xc];
  uVar1 = *(uint *)(lVar2 + 0x2004);
  if (uVar1 < 0x2000) {
    uVar5 = 0xffffffff;
  }
  else {
    uVar5 = uVar1 - 0x2000;
  }
  if (DAT_18001c52b == '\x01') {
    WriteLogString(*param_1,"Starting write of minidump data.\r\n",param_3,param_4);
  }
  if (uVar1 < 0x2000) {
    uVar5 = *(uint *)(lVar2 + 0x2004);
  }
  uVar6 = (ulonglong)uVar5;
  uVar7 = 2;
  iVar3 = WriteBufferToDisk(param_1,lVar2 + 0x2000,uVar6,2,'\0');
  if ((iVar3 < 0) && (DAT_18001c528 == '\0')) {
    DAT_18001c33c = DAT_18001c33c | 0x10000;
    puVar4 = &DAT_18001c33c;
    uVar6 = 4;
    CrashdmpTelemetrySaveEnvironmentVariable(L"BugCheckProgress",&DAT_18001c33c,4);
    WriteLogProgress(DAT_18001c33c,puVar4,uVar6,uVar7);
  }
  if (param_2 != (undefined *)0x0) {
    (*(code *)param_2)(100);
  }
  if (DAT_18001c52b == '\x01') {
    WriteLogString(*param_1,"Finish write of minidump data.\r\n",uVar6,uVar7);
  }
  return iVar3;
}



===== WritePageSpanToDisk @ 18000d700 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int WritePageSpanToDisk(longlong *param_1,longlong *param_2,longlong param_3,char param_4)

{
  longlong *plVar1;
  code *pcVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong *plVar7;
  longlong lVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  uint uVar11;
  uint uVar12;
  undefined1 auStack_908 [32];
  uint local_8d4;
  longlong local_8d0;
  code *local_8c8;
  longlong local_8c0;
  longlong local_8b8;
  longlong *local_8b0;
  longlong local_8a8;
  code *local_8a0;
  longlong local_898;
  undefined8 local_888;
  short local_880;
  ushort local_87e;
  undefined8 local_870;
  ulonglong local_868;
  uint local_860;
  uint local_85c;
  longlong local_858 [258];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_908;
  local_8c8 = *(code **)(*param_1 + 0x40);
  local_8a0 = *(code **)(*param_1 + 0x80);
  local_8b0 = param_2;
  memset(&local_888,0,0x838);
  uVar11 = *(uint *)((longlong)param_1 + 0x624);
  lVar8 = param_1[0xc5];
  local_8b8 = (ulonglong)uVar11 * 0x10;
  uVar6 = 0;
  local_898 = param_3 << 0xc;
  iVar3 = 0;
  local_8c0 = 0;
  uVar10 = *(longlong *)(param_1[0xb] + local_8b8) - lVar8;
  local_8d4 = 0;
  if (0 < local_898) {
    do {
      if ((*(uint *)(param_1 + 10) <= uVar11) || (uVar10 == 0)) {
        iVar3 = -0x3fffffdd;
        break;
      }
      local_8d0 = 0;
      uVar9 = uVar10;
      if (local_898 - local_8c0 < (longlong)uVar10) {
        uVar9 = local_898 - local_8c0;
      }
      if (0xffffefff < uVar9) {
        uVar9 = 0xfffff000;
      }
      uVar4 = Feature_CrashDumpOneMBTransferSize__private_IsEnabledNoReportingNoInline();
      if ((int)uVar4 == 0) {
        if (0xffff < uVar9) {
          uVar9 = 0x10000;
        }
      }
      else if (0xfffff < uVar9) {
        uVar9 = 0x100000;
      }
      uVar4 = (ulonglong)*(uint *)(*param_1 + 0x6c);
      if (uVar9 < *(uint *)(*param_1 + 0x6c)) {
        uVar4 = uVar9;
      }
      if (((DmpEncryptionContext != '\0') && (DAT_18001c528 == '\0')) && (DAT_18001b3ac <= uVar4)) {
        uVar4 = (ulonglong)DAT_18001b3ac;
      }
      local_8d0 = *(longlong *)(local_8b8 + 8 + param_1[0xb]) + lVar8;
      local_8a8 = *local_8b0 + (uVar6 & 0xffffffff);
      if (param_4 == '\0') {
        plVar7 = local_8b0 + (uVar6 & 0xffffffff);
      }
      else {
        plVar7 = &local_8a8;
      }
      plVar1 = local_858;
      local_868 = 0;
      local_85c = local_8d4;
      uVar12 = (uint)uVar4;
      local_860 = uVar12;
      uVar6 = (ulonglong)local_8d4 + 0xfff + (uVar4 & 0xffffffff) >> 0xc;
      if (param_4 == '\0') {
        if (uVar6 != 0) {
          lVar5 = (longlong)local_858 - (longlong)plVar7;
          do {
            *(longlong *)(lVar5 + (longlong)plVar7) = *plVar7;
            plVar7 = plVar7 + 1;
            uVar6 = uVar6 - 1;
          } while (uVar6 != 0);
        }
      }
      else {
        lVar5 = *plVar7;
        for (; uVar6 != 0; uVar6 = uVar6 - 1) {
          *plVar1 = lVar5;
          lVar5 = lVar5 + 1;
          plVar1 = plVar1 + 1;
        }
      }
      MmMapMemoryDumpMdl(&local_888);
      InvokeDumpCallbacks(param_1,local_868,uVar12,2,0);
      if ((DmpEncryptionContext != '\0') && (DAT_18001c528 == '\0')) {
        iVar3 = (*DAT_18001b3a0)(local_870,uVar4,DAT_18001b3b8,uVar4);
        if (DAT_18001c444 == 0x5006) {
          iVar3 = -0x3fffffff;
        }
        else if (-1 < iVar3) {
          local_888 = 0;
          local_87e = 0;
          local_868 = DAT_18001b3b8 & 0xfffffffffffff000;
          local_85c = (uint)DAT_18001b3b8 & 0xfff;
          local_880 = ((short)((DAT_18001b3b8 & 0xfff) + 0xfff + (uVar4 & 0xffffffff) >> 0xc) + 6) *
                      8;
          local_860 = uVar12;
          MmBuildMdlForNonPagedPool(&local_888);
          local_87e = local_87e | 1;
          goto LAB_18000d9cb;
        }
        param_1[0xdc] = (longlong)DAT_18001b3a0;
        *(int *)((longlong)param_1 + 0x6fc) = iVar3;
        *(undefined4 *)(param_1 + 0xdf) = 0x5006;
        break;
      }
LAB_18000d9cb:
      pcVar2 = local_8a0;
      if ((((DAT_18001c548 & 2) == 0) || (local_8a0 == (code *)0x0)) ||
         (iVar3 = (*local_8a0)(1,&local_8d0,&local_888), iVar3 == -0x3fffff45)) {
        iVar3 = (*local_8c8)(&local_8d0,&local_888);
      }
      else {
        while (iVar3 == 0x103) {
          iVar3 = (*pcVar2)(2,&local_8d0,&local_888);
        }
      }
      if (iVar3 < 0) {
LAB_18000daf5:
        param_1[0xdc] = (longlong)local_8c8;
        *(int *)((longlong)param_1 + 0x6fc) = iVar3;
        *(undefined4 *)(param_1 + 0xdf) = 0x5001;
        break;
      }
      if (*(int *)((longlong)param_1 + 0x704) == 0x5001) {
        iVar3 = -0x3fffffff;
        goto LAB_18000daf5;
      }
      uVar6 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
      if (((int)uVar6 != 0) && (local_860 <= uVar4)) {
        uVar4 = (ulonglong)local_860;
      }
      local_8c0 = local_8c0 + uVar4;
      local_8d4 = local_8d4 + (int)uVar4 & 0xfff;
      lVar8 = lVar8 + uVar4;
      uVar6 = (longlong)((local_8c0 >> 0x3f & 0xfffU) + local_8c0) >> 0xc;
      uVar10 = uVar10 - uVar4;
      if (uVar10 == 0) {
        uVar11 = uVar11 + 1;
        lVar8 = 0;
        local_8b8 = (ulonglong)uVar11 * 0x10;
        uVar10 = *(ulonglong *)(local_8b8 + param_1[0xb]);
      }
    } while (local_8c0 < local_898);
  }
  *(uint *)((longlong)param_1 + 0x624) = uVar11;
  param_1[0xc5] = lVar8;
  return iVar3;
}



===== CrashdmpDriveTelemetryCallback @ 18000db60 =====

void CrashdmpDriveTelemetryCallback(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  if (7 < *(uint *)(param_3 + 0xc)) {
    *(undefined8 *)(param_3 + 0x10) = 0x4d561aabd8e2592f;
    *(undefined8 *)(param_3 + 0x18) = 0xf440df85751f46a7;
    *(undefined4 *)(param_3 + 0x28) = DAT_18001c470;
    if (*(longlong *)(param_3 + 0x20) != 0) {
      *(undefined8 *)(param_3 + 0x20) = DAT_18001c448;
    }
  }
  return;
}



===== CrashdmpFinishRoutine @ 18000dba0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CrashdmpFinishRoutine
               (undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined8 *param_4)

{
  undefined8 *unaff_RBX;
  undefined8 *puVar1;
  undefined8 unaff_retaddr;
  undefined4 in_stack_00000008;
  undefined4 in_stack_0000000c;
  undefined1 auStackX_12 [22];
  
  puVar1 = DAT_18001bd40;
  if (DAT_18001c528 == '\x01') {
    puVar1 = DAT_18001c520;
  }
  FilterCallback(3,puVar1,param_3,param_4,unaff_RBX,unaff_retaddr,
                 CONCAT44(in_stack_0000000c,in_stack_00000008));
  if (*(int *)(puVar1 + 0x2f) == 2) {
    if ((*(int *)(puVar1 + 0x31) != 3) && ((code *)puVar1[0x40] != (code *)0x0)) {
      (*(code *)puVar1[0x40])(puVar1[0x32],0,0);
      (*(code *)puVar1[0x41])(puVar1[0x32],7,auStackX_12 + -10);
    }
  }
  else {
    (*(code *)puVar1[0x41])();
  }
  return;
}



===== CrashdmpReadRoutine @ 18000dc40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int CrashdmpReadRoutine(int param_1,longlong *param_2,undefined8 *param_3)

{
  int iVar1;
  ulonglong uVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  bool bVar5;
  longlong *in_stack_ffffffffffffffa8;
  undefined8 *in_stack_ffffffffffffffb0;
  longlong *in_stack_ffffffffffffffb8;
  longlong local_38;
  longlong local_30 [3];
  
  local_38 = 0;
  bVar5 = false;
  local_30[2] = 0;
  local_30[0] = 0;
  puVar4 = DAT_18001bd40;
  if (DAT_18001c528 == '\x01') {
    puVar4 = DAT_18001c520;
  }
  local_30[1] = 0x10;
  uVar2 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
  if ((int)uVar2 != 0) {
    local_30[0] = *param_2;
    uVar2 = GetStorageDumpIoMode(param_1);
    in_stack_ffffffffffffffb8 = local_30 + 1;
    in_stack_ffffffffffffffa8 = local_30;
    in_stack_ffffffffffffffb0 = param_3;
    FilterCallback(5,puVar4,(undefined8 *)(uVar2 & 0xffffffff),(undefined8 *)0x0,
                   in_stack_ffffffffffffffa8,param_3,in_stack_ffffffffffffffb8);
  }
  if (*(int *)(puVar4 + 0x2f) == 2) {
    uVar2 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
    if ((int)uVar2 == 0) {
      local_38 = *param_2;
    }
    else {
      bVar5 = puVar4[0x42] != 0;
      local_38 = local_30[0];
    }
    local_38 = puVar4[0x21] + local_38;
    uVar2 = GetStorageDumpIoMode(param_1);
    if (bVar5) {
      in_stack_ffffffffffffffa8 = local_30 + 1;
      iVar1 = (*(code *)puVar4[0x42])(puVar4[0x32],uVar2 & 0xffffffff,&local_38);
    }
    else {
      iVar1 = (*(code *)puVar4[0x3e])(puVar4[0x32],uVar2 & 0xffffffff,&local_38,param_3);
    }
  }
  else {
    uVar2 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
    plVar3 = local_30;
    if ((int)uVar2 == 0) {
      plVar3 = param_2;
    }
    iVar1 = (*(code *)puVar4[0x42])(param_1,plVar3,param_3);
  }
  if (iVar1 != 0x103) {
    if (iVar1 < 0) goto LAB_18000ddb9;
    if (param_1 != 4) {
      FilterCallback(4,puVar4,param_2,param_3,in_stack_ffffffffffffffa8,in_stack_ffffffffffffffb0,
                     in_stack_ffffffffffffffb8);
    }
  }
  if (DAT_18001c444 == 0x5003) {
    iVar1 = -0x3fffffff;
  }
  else {
    if (iVar1 == 0x103) {
      return 0x103;
    }
    if (-1 < iVar1) {
      return iVar1;
    }
  }
LAB_18000ddb9:
  if (*(int *)(puVar4 + 0x2f) == 2) {
    _DAT_18001c420 = puVar4[0x3e];
  }
  else {
    _DAT_18001c420 = puVar4[0x42];
  }
  _DAT_18001c43c = iVar1;
  _DAT_18001c438 = 0x5003;
  return iVar1;
}



===== CrashdmpWritePendingRoutine @ 18000de10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int CrashdmpWritePendingRoutine
              (uint param_1,longlong *param_2,undefined8 *param_3,undefined8 param_4)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  bool bVar6;
  longlong *in_stack_ffffffffffffff98;
  undefined8 *in_stack_ffffffffffffffa0;
  longlong *in_stack_ffffffffffffffa8;
  longlong local_48;
  longlong local_40 [3];
  
  local_40[0] = 0;
  puVar5 = DAT_18001bd40;
  if (DAT_18001c528 == '\x01') {
    puVar5 = DAT_18001c520;
  }
  local_40[1] = 0x10;
  bVar6 = false;
  local_40[2] = 0;
  local_48 = 0;
  uVar3 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
  if ((int)uVar3 != 0) {
    local_48 = *param_2;
    uVar3 = GetStorageDumpIoMode(param_1);
    in_stack_ffffffffffffffa8 = local_40 + 1;
    in_stack_ffffffffffffff98 = &local_48;
    in_stack_ffffffffffffffa0 = param_3;
    FilterCallback(5,puVar5,(undefined8 *)(uVar3 & 0xffffffff),(undefined8 *)0x1,
                   in_stack_ffffffffffffff98,param_3,in_stack_ffffffffffffffa8);
  }
  if (param_1 < 2) {
    uVar3 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
    plVar4 = &local_48;
    if ((int)uVar3 == 0) {
      plVar4 = param_2;
    }
    FilterCallback(2,puVar5,plVar4,param_3,in_stack_ffffffffffffff98,in_stack_ffffffffffffffa0,
                   in_stack_ffffffffffffffa8);
  }
  if (*(int *)(puVar5 + 0x2f) == 2) {
    uVar3 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
    if ((int)uVar3 == 0) {
      local_40[0] = *param_2;
    }
    else {
      bVar6 = puVar5[0x43] != 0;
      local_40[0] = local_48;
    }
    local_40[0] = puVar5[0x21] + local_40[0];
    uVar3 = GetStorageDumpIoMode(param_1);
    if (bVar6) {
      iVar2 = (*(code *)puVar5[0x43])
                        (puVar5[0x32],uVar3 & 0xffffffff,local_40,param_3,param_4,local_40 + 1);
    }
    else {
      iVar2 = (*(code *)puVar5[0x3f])(puVar5[0x32],uVar3 & 0xffffffff,local_40,param_3,param_4);
    }
  }
  else {
    uVar3 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
    plVar4 = &local_48;
    if ((int)uVar3 == 0) {
      plVar4 = param_2;
    }
    iVar2 = (*(code *)puVar5[0x40])(param_1,plVar4,param_3,param_4);
  }
  if ((iVar2 < 0) || (DAT_18001c444 != 0x5002)) {
    if (iVar2 == 0x103) {
      return 0x103;
    }
    if (-1 < iVar2) {
      if (DAT_18001c538 == (void *)0x0) {
        return iVar2;
      }
      if (param_1 == 4) {
        return iVar2;
      }
      uVar1 = *(uint *)(param_3 + 5);
      if (*(uint *)((longlong)puVar5 + 0x2d4) < uVar1) {
        return iVar2;
      }
      if (*(int *)(puVar5 + 0x2f) == 2) {
        if ((undefined *)puVar5[0x3e] == (undefined *)0x0) {
          return iVar2;
        }
        ValidateWriteDumpInfo
                  ((longlong)(puVar5 + 0x30),(undefined *)puVar5[0x3e],DAT_18001c538,uVar1,
                   (void *)param_3[3],local_40,*param_2,puVar5);
      }
      else {
        if ((undefined *)puVar5[0x42] == (undefined *)0x0) {
          return iVar2;
        }
        ValidateWrite(DAT_18001c538,uVar1,(void *)param_3[3],(longlong)param_2,
                      (undefined *)puVar5[0x42]);
      }
      return iVar2;
    }
  }
  else {
    iVar2 = -0x3fffffff;
  }
  if (*(int *)(puVar5 + 0x2f) == 2) {
    if (bVar6) {
      _DAT_18001c420 = puVar5[0x43];
    }
    else {
      _DAT_18001c420 = puVar5[0x3f];
    }
  }
  else {
    _DAT_18001c420 = puVar5[0x40];
  }
  _DAT_18001c43c = iVar2;
  _DAT_18001c438 = 0x5002;
  return iVar2;
}



===== CrashdmpWriteRoutine @ 18000e0b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int CrashdmpWriteRoutine(longlong *param_1,undefined8 *param_2)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  bool bVar6;
  longlong local_res18;
  longlong local_res20;
  longlong *in_stack_ffffffffffffffa8;
  undefined8 *in_stack_ffffffffffffffb0;
  undefined8 *in_stack_ffffffffffffffb8;
  undefined8 local_38;
  undefined8 local_30;
  
  local_res20 = 0;
  bVar6 = false;
  local_30 = 0;
  local_res18 = 0;
  puVar5 = DAT_18001bd40;
  if (DAT_18001c528 == '\x01') {
    puVar5 = DAT_18001c520;
  }
  local_38 = 0x10;
  uVar3 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
  if ((int)uVar3 == 0) {
    plVar4 = param_1;
  }
  else {
    local_res18 = *param_1;
    in_stack_ffffffffffffffb8 = &local_38;
    in_stack_ffffffffffffffa8 = &local_res18;
    in_stack_ffffffffffffffb0 = param_2;
    FilterCallback(5,puVar5,(undefined8 *)0x1,(undefined8 *)0x1,in_stack_ffffffffffffffa8,param_2,
                   in_stack_ffffffffffffffb8);
    plVar4 = &local_res18;
  }
  FilterCallback(2,puVar5,plVar4,param_2,in_stack_ffffffffffffffa8,in_stack_ffffffffffffffb0,
                 in_stack_ffffffffffffffb8);
  if (*(int *)(puVar5 + 0x2f) == 2) {
    uVar3 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
    if ((int)uVar3 == 0) {
      local_res20 = *param_1;
    }
    else {
      bVar6 = puVar5[0x43] != 0;
      local_res20 = local_res18;
    }
    local_res20 = puVar5[0x21] + local_res20;
    if (bVar6) {
      iVar2 = (*(code *)puVar5[0x43])(puVar5[0x32],1,&local_res20,param_2,0,&local_38);
    }
    else {
      iVar2 = (*(code *)puVar5[0x3f])(puVar5[0x32],1,&local_res20,param_2,0);
    }
  }
  else {
    uVar3 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
    plVar4 = &local_res18;
    if ((int)uVar3 == 0) {
      plVar4 = param_1;
    }
    iVar2 = (*(code *)puVar5[0x3f])(plVar4,param_2);
  }
  if (-1 < iVar2) {
    if (DAT_18001c444 != 0x5001) goto LAB_18000e255;
    iVar2 = -0x3fffffff;
  }
  if ((*(int *)(puVar5 + 0x2f) == 2) && (bVar6)) {
    _DAT_18001c420 = puVar5[0x43];
  }
  else {
    _DAT_18001c420 = puVar5[0x3f];
  }
  _DAT_18001c438 = 0x5001;
  _DAT_18001c43c = iVar2;
  if (iVar2 < 0) {
    _DAT_18001c438 = 0x5001;
    return iVar2;
  }
LAB_18000e255:
  if (((iVar2 != 0x103) && (DAT_18001c538 != (void *)0x0)) &&
     (uVar1 = *(uint *)(param_2 + 5), uVar1 <= *(uint *)((longlong)puVar5 + 0x2d4))) {
    if (*(int *)(puVar5 + 0x2f) == 2) {
      if ((undefined *)puVar5[0x3e] != (undefined *)0x0) {
        ValidateWriteDumpInfo
                  ((longlong)(puVar5 + 0x30),(undefined *)puVar5[0x3e],DAT_18001c538,uVar1,
                   (void *)param_2[3],&local_res20,*param_1,puVar5);
      }
    }
    else if ((undefined *)puVar5[0x42] != (undefined *)0x0) {
      ValidateWrite(DAT_18001c538,uVar1,(void *)param_2[3],(longlong)param_1,
                    (undefined *)puVar5[0x42]);
    }
  }
  return iVar2;
}



===== DumpCapsuleSecondaryCallbacks @ 18000e308 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DumpCapsuleSecondaryCallbacks
               (longlong param_1,longlong param_2,undefined4 *param_3,uint param_4)

{
  undefined4 *puVar1;
  bool bVar2;
  char cVar3;
  undefined8 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined1 auStack_158 [64];
  char local_118;
  uint local_114;
  uint local_110;
  undefined4 *local_108;
  longlong *local_100;
  char *local_f8;
  longlong local_f0;
  undefined8 *local_e8;
  ulonglong local_e0;
  longlong local_d8;
  longlong local_c8;
  longlong *local_c0;
  undefined4 *local_b8;
  uint local_b0;
  undefined4 local_ac;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined4 *local_98;
  uint local_90;
  uint local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_158;
  local_f0 = param_1;
  local_d8 = param_2;
  local_c8 = param_1;
  memset(&local_b8,0,0x68);
  local_7c = *(undefined4 *)(param_2 + 0x18);
  local_78 = *(undefined4 *)(param_2 + 0x98);
  local_70 = *(undefined8 *)(param_2 + 0xa0);
  local_68 = *(undefined8 *)(param_2 + 0xa8);
  local_60 = *(undefined8 *)(param_2 + 0xb0);
  local_58 = *(undefined8 *)(param_2 + 0xb8);
  if (0xf < param_4) {
    memset(param_3,0,(ulonglong)param_4);
    *param_3 = 0x706d7544;
    param_3[1] = 0x626f6c42;
    param_3[2] = 0x10;
    param_3[3] = DAT_18001c554;
    local_108 = param_3 + 4;
    uVar7 = param_4 - 0x10;
    local_100 = (longlong *)(param_1 + 4000);
    *local_100 = *local_100 + 0x10;
    local_c0 = (longlong *)(param_2 + 0x90);
    puVar4 = *(undefined8 **)*local_c0;
    puVar5 = local_108;
    local_114 = uVar7;
    while (((puVar4 != (undefined8 *)*local_c0 && (((ulonglong)puVar4 & 7) == 0)) &&
           (local_e8 = puVar4, cVar3 = IsBufferValid((ulonglong)puVar4,0x30), cVar3 != '\0'))) {
      puVar6 = puVar5;
      if (((*(int *)(puVar4 + 5) == 5) && (*(char *)((longlong)puVar4 + 0x2c) == '\x01')) &&
         (puVar4[4] == puVar4[2] + 5 + puVar4[3])) {
        cVar3 = MmIsAddressValid();
        if (cVar3 == '\0') {
          local_f8 = "invalid name";
        }
        else {
          local_f8 = (char *)puVar4[3];
        }
        cVar3 = MmIsAddressValid(puVar4[2]);
        if ((cVar3 != '\0') &&
           (local_110 = GetSecondaryMultiPartDumpCallbackSize((longlong)puVar4,param_2),
           local_110 <= uVar7)) {
          *(undefined1 *)((longlong)puVar4 + 0x2c) = 2;
          bVar2 = true;
          local_118 = '\x01';
          do {
            local_b8 = puVar5 + 8;
            if (!bVar2) {
              local_b8 = puVar6;
            }
            local_e0 = (ulonglong)uVar7;
            local_b0 = uVar7 - 4;
            local_ac = *(undefined4 *)(param_2 + 0x654);
            local_90 = 0;
            local_80 = 2;
            puVar1 = (undefined4 *)(local_e0 + (longlong)puVar6);
            puVar1[-1] = 0x706d7544;
            local_98 = local_b8;
            (*(code *)puVar4[2])(5,puVar4,&local_b8);
            if (puVar1[-1] != 0x706d7544) {
              *(undefined1 *)((longlong)puVar4 + 0x2c) = 4;
              local_90 = 0;
              break;
            }
            puVar1[-1] = 0;
            if ((local_98 < puVar6) || (puVar1 <= local_98)) {
              if ((*(uint *)(param_2 + 0x654) < local_90) ||
                 ((cVar3 = IsBufferValid((ulonglong)local_98,local_90), cVar3 == '\0' ||
                  (uVar7 < local_90)))) goto LAB_18000e592;
              memcpy(local_b8,local_98,(ulonglong)local_90);
            }
            else if ((local_98 != local_b8) || (local_b0 < local_90)) {
LAB_18000e592:
              local_90 = 0;
              *(undefined1 *)((longlong)puVar4 + 0x2c) = 4;
              break;
            }
            if (local_118 != '\0') {
              *(undefined8 *)(puVar5 + 6) = 0;
              *puVar5 = 0x20;
              *(undefined8 *)(puVar5 + 1) = local_a8;
              *(undefined8 *)(puVar5 + 3) = uStack_a0;
              puVar5[5] = local_110 - 0x20;
              puVar6 = puVar6 + 8;
              uVar7 = (int)local_e0 - 0x20;
              *local_100 = *local_100 + 0x20;
              local_114 = uVar7;
              local_108 = puVar6;
            }
            if (local_90 != 0) {
              puVar6 = (undefined4 *)((longlong)puVar6 + (ulonglong)local_90);
              uVar7 = uVar7 - local_90;
              *(ulonglong *)(local_f0 + 4000) = (ulonglong)local_90 + *local_100;
              local_114 = uVar7;
              local_108 = puVar6;
            }
            bVar2 = false;
            local_118 = '\0';
          } while ((local_80 & 1) != 0);
          if (*(char *)((longlong)puVar4 + 0x2c) != '\x04') {
            *(undefined1 *)((longlong)puVar4 + 0x2c) = 3;
          }
        }
      }
      puVar4 = (undefined8 *)*puVar4;
      puVar5 = puVar6;
    }
  }
  return;
}



===== FilterCallback @ 18000e78c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FilterCallback(int param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
                  undefined8 *param_5,undefined8 param_6,undefined8 param_7)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  bool bVar6;
  int iVar7;
  ulonglong uVar8;
  uint uVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  undefined8 *puVar14;
  undefined1 local_res20;
  
  iVar7 = 0;
  puVar11 = param_2;
  puVar12 = param_3;
  puVar13 = param_4;
  if (param_1 == 4) {
    bVar6 = false;
    puVar14 = (undefined8 *)param_2[0x51];
  }
  else {
    bVar6 = true;
    puVar14 = (undefined8 *)param_2[0x50];
  }
  do {
    if (puVar14 == param_2 + 0x50) {
      return iVar7;
    }
    puVar10 = puVar14 + -0x14;
    if ((*(uint *)(puVar14 + 2) & 1) == 0) {
      if (param_1 == 0) {
        *(undefined4 *)puVar10 = 1;
        uVar8 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
        *(uint *)((longlong)puVar14 + -0x9c) = -(uint)((int)uVar8 != 0) & 2;
        uVar8 = Feature_CrashDumpOneMBTransferSize__private_IsEnabledNoReportingNoInline();
        *(uint *)(puVar14 + -0xe) = (-(uint)((int)uVar8 != 0) & 0xf0) + 0x10;
        uVar9 = 3;
        *(undefined4 *)((longlong)puVar14 + -0x6c) = 3;
        if (*(char *)((longlong)param_2 + 0x232) != '\0') {
          *(undefined4 *)((longlong)puVar14 + -0x6c) = 7;
          uVar9 = 7;
        }
        if ((DAT_18001bd60 & 0x10000) != 0) {
          uVar9 = uVar9 | 8;
          *(uint *)((longlong)puVar14 + -0x6c) = uVar9;
        }
        if ((DAT_18001bd60 & 0x20000) != 0) {
          *(uint *)((longlong)puVar14 + -0x6c) = uVar9 | 0x10;
        }
        uVar8 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
        if (((((int)uVar8 != 0) && (*(int *)(param_2 + 0x2f) == 2)) && (param_2[0x43] != 0)) &&
           ((*(uint *)(*(longlong *)(param_2[0x32] + 0x40) + 0x40) & 4) != 0)) {
          *(uint *)((longlong)puVar14 + -0x6c) = *(uint *)((longlong)puVar14 + -0x6c) | 0x20;
        }
        puVar14[-10] = param_2[0x4f];
        uVar5 = param_2[0x49];
        puVar14[-9] = param_2[0x48];
        puVar14[-8] = uVar5;
        puVar14[-7] = param_2[0x4a];
        puVar14[-6] = param_2[0x4b];
        uVar2 = *(undefined4 *)((longlong)param_2 + 0x264);
        uVar3 = *(undefined4 *)(param_2 + 0x4d);
        uVar4 = *(undefined4 *)((longlong)param_2 + 0x26c);
        *(undefined4 *)(puVar14 + -5) = *(undefined4 *)(param_2 + 0x4c);
        *(undefined4 *)((longlong)puVar14 + -0x24) = uVar2;
        *(undefined4 *)(puVar14 + -4) = uVar3;
        *(undefined4 *)((longlong)puVar14 + -0x1c) = uVar4;
        puVar14[-3] = param_2[0x4e];
        *(undefined4 *)(puVar14 + -1) = 0x58;
        *(uint *)(puVar14 + -0xb) = (*(int *)(param_2 + 0x2e) == 2) + 1;
        pcVar1 = *(code **)(puVar14[4] + 0x28);
        iVar7 = (*pcVar1)();
        if (-1 < iVar7) {
          if (DAT_18001c444 != 0x2006) {
            puVar14[-2] = puVar14[-0xf];
            puVar11 = puVar10;
            if (puVar14[-0xd] == 0) {
              *(undefined1 *)(param_2 + 0x46) = 0;
              *(uint *)(param_2 + 0x52) = *(uint *)(param_2 + 0x52) | 1;
            }
            goto LAB_18000eaec;
          }
          *(uint *)((longlong)puVar14 + -0x6c) = *(uint *)((longlong)puVar14 + -0x6c) | 1;
          iVar7 = -0x3fffffff;
        }
        _DAT_18001c440 = iVar7;
        _DAT_18001c428 = pcVar1;
        iVar7 = _DAT_18001c440;
        if ((*(uint *)((longlong)puVar14 + -0x6c) & 1) != 0) {
          return _DAT_18001c440;
        }
LAB_18000eadf:
        puVar11 = puVar10;
        if (-1 < iVar7) goto LAB_18000eaec;
      }
      else {
        if (param_1 != 1) {
          puVar10 = param_3;
          if (param_1 == 2) {
            puVar12 = param_4;
            if ((code *)puVar14[-0x12] != (code *)0x0) {
              puVar11 = param_3;
              iVar7 = (*(code *)puVar14[-0x12])(puVar14 + -0xb);
              if (iVar7 < 0) {
                _DAT_18001c428 = (code *)puVar14[-0x12];
                goto LAB_18000e96b;
              }
              goto LAB_18000eaec;
            }
          }
          else if (param_1 == 3) {
            puVar10 = puVar11;
            if ((code *)puVar14[-0x11] != (code *)0x0) {
              iVar7 = (*(code *)puVar14[-0x11])(puVar14 + -0xb);
              if (iVar7 < 0) {
                _DAT_18001c428 = (code *)puVar14[-0x11];
                goto LAB_18000e96b;
              }
              goto LAB_18000eaec;
            }
          }
          else if (param_1 == 4) {
            puVar12 = param_4;
            if ((code *)puVar14[-0xd] != (code *)0x0) {
              puVar11 = param_3;
              iVar7 = (*(code *)puVar14[-0xd])(puVar14 + -0xb);
              if (iVar7 < 0) {
                _DAT_18001c428 = (code *)puVar14[-0xd];
                goto LAB_18000e96b;
              }
              goto LAB_18000eaec;
            }
          }
          else {
            puVar10 = puVar11;
            if (param_1 == 5) {
              uVar8 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
              if ((int)uVar8 == 0) {
                puVar10 = puVar11;
                iVar7 = -0x3fffff45;
              }
              else {
                puVar10 = (undefined8 *)((ulonglong)param_3 & 0xffffffff);
                local_res20 = SUB81(param_4,0);
                puVar12 = (undefined8 *)CONCAT71((int7)((ulonglong)puVar12 >> 8),local_res20);
                puVar13 = param_5;
                if ((code *)puVar14[-0xc] != (code *)0x0) {
                  iVar7 = (*(code *)puVar14[-0xc])
                                    (puVar14 + -0xb,puVar10,puVar12,param_5,param_6,param_7);
                  puVar11 = puVar10;
                  if (-1 < iVar7) goto LAB_18000eaec;
                  _DAT_18001c428 = (code *)puVar14[-0xc];
                  _DAT_18001c440 = iVar7;
                }
              }
            }
          }
          goto LAB_18000eadf;
        }
        puVar10 = puVar11;
        if (puVar14[-0x13] == 0) goto LAB_18000eadf;
        uVar8 = CrashdmpReady('\0',puVar11,puVar12,puVar13);
        *(uint *)((longlong)puVar14 + -4) = (uint)((char)uVar8 == '\0');
        iVar7 = (*(code *)puVar14[-0x13])(puVar14 + -0xb);
        if (-1 < iVar7) goto LAB_18000eaec;
        _DAT_18001c428 = (code *)puVar14[-0x13];
LAB_18000e96b:
        _DAT_18001c440 = iVar7;
      }
      *(uint *)(puVar14 + 2) = *(uint *)(puVar14 + 2) | 1;
      iVar7 = 0;
    }
LAB_18000eaec:
    if (bVar6) {
      puVar14 = (undefined8 *)*puVar14;
    }
    else {
      puVar14 = (undefined8 *)puVar14[1];
    }
  } while( true );
}



===== GetSecondaryDumpCallbackSize @ 18000eb50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong GetSecondaryDumpCallbackSize(longlong param_1)

{
  longlong *plVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined1 auStack_a8 [64];
  longlong local_68;
  char *local_60;
  undefined8 *local_58;
  longlong local_50;
  longlong *local_48;
  undefined8 local_40;
  longlong lStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_a8;
  lVar6 = 0x10;
  local_68 = 0x10;
  plVar1 = (longlong *)(param_1 + 0x90);
  puVar5 = *(undefined8 **)*plVar1;
  local_50 = param_1;
  local_48 = plVar1;
  while (((puVar5 != (undefined8 *)*plVar1 && (((ulonglong)puVar5 & 7) == 0)) &&
         (local_58 = puVar5, cVar3 = IsBufferValid((ulonglong)puVar5,0x30), cVar3 != '\0'))) {
    iVar2 = *(int *)(puVar5 + 5);
    if ((*(char *)((longlong)puVar5 + 0x2c) == '\x01') &&
       (puVar5[4] == puVar5[2] + (longlong)iVar2 + puVar5[3])) {
      if (iVar2 == 5) {
        uVar4 = GetSecondaryMultiPartDumpCallbackSize((longlong)puVar5,param_1);
        lVar6 = lVar6 + (ulonglong)uVar4;
        local_68 = lVar6;
      }
      else if ((iVar2 == 2) && (cVar3 = MmIsAddressValid(puVar5[2]), cVar3 != '\0')) {
        cVar3 = MmIsAddressValid(puVar5[3]);
        if (cVar3 == '\0') {
          local_60 = "invalid name";
        }
        else {
          local_60 = (char *)puVar5[3];
        }
        local_30 = 0;
        uStack_28 = 0;
        local_40 = 0xbadf00d;
        lStack_38 = (ulonglong)*(uint *)(param_1 + 0x654) << 0x20;
        local_20 = 0;
        uStack_18 = 0;
        (*(code *)puVar5[2])(2,puVar5,&local_40);
        if ((uint)uStack_18 == 0) {
          *(undefined1 *)((longlong)puVar5 + 0x2c) = 3;
        }
        else {
          uVar4 = (uint)uStack_18;
          if (*(uint *)(param_1 + 0x654) < (uint)uStack_18) {
            uVar4 = *(uint *)(param_1 + 0x654);
          }
          uStack_18 = CONCAT44(uStack_18._4_4_,uVar4);
          lVar6 = lVar6 + 0x20 + (ulonglong)uVar4;
          local_68 = lVar6;
        }
      }
    }
    puVar5 = (undefined8 *)*puVar5;
  }
  return lVar6;
}



===== GetSecondaryDumpDataLimits @ 18000edc8 =====

void GetSecondaryDumpDataLimits(int param_1,longlong param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  
  *param_3 = 0;
  *param_4 = 0;
  if (param_1 == 4) {
    *param_3 = 0xa000000;
  }
  else if (param_1 - 5U < 2) {
    *param_3 = 0x10000000;
  }
  uVar1 = *param_3;
  if (param_2 < (longlong)(ulonglong)*param_3) {
    *param_3 = (uint)param_2;
    uVar1 = (uint)param_2;
  }
  *param_4 = uVar1 >> 3;
  return;
}



===== GetSecondaryMultiPartDumpCallbackSize @ 18000ee08 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int GetSecondaryMultiPartDumpCallbackSize(longlong param_1,longlong param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStack_e8 [64];
  undefined4 local_a8;
  uint local_a4;
  char *local_a0;
  longlong local_98;
  longlong local_90;
  undefined8 local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 local_68;
  int local_60;
  uint local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_e8;
  local_a8 = 0;
  uVar3 = 0;
  local_98 = param_1;
  local_90 = param_2;
  memset(&local_88,0,0x68);
  cVar1 = MmIsAddressValid(*(undefined8 *)(param_1 + 0x10));
  if (cVar1 == '\0') {
    iVar2 = 0;
  }
  else {
    cVar1 = MmIsAddressValid();
    if (cVar1 == '\0') {
      local_a0 = "invalid name";
    }
    else {
      local_a0 = *(char **)(param_1 + 0x18);
    }
    local_88 = 0xbadf00d;
    local_80 = 0;
    local_7c = *(undefined4 *)(param_2 + 0x654);
    local_4c = *(undefined4 *)(param_2 + 0x18);
    local_48 = *(undefined4 *)(param_2 + 0x98);
    local_40 = *(undefined8 *)(param_2 + 0xa0);
    local_38 = *(undefined8 *)(param_2 + 0xa8);
    local_30 = *(undefined8 *)(param_2 + 0xb0);
    local_28 = *(undefined8 *)(param_2 + 0xb8);
    while( true ) {
      local_68 = 0;
      local_60 = 0;
      local_50 = -(uint)(DAT_18001c52c != '\0') & 2;
      (**(code **)(param_1 + 0x10))(5,param_1,&local_88);
      uVar3 = uVar3 + local_60;
      if (*(uint *)(param_2 + 0x654) < uVar3) break;
      if (((local_50 & 1) == 0) || (local_a4 = uVar3, local_60 == 0)) goto LAB_18000ef6c;
    }
    uVar3 = *(uint *)(param_2 + 0x654);
LAB_18000ef6c:
    iVar2 = uVar3 + 0x20;
  }
  return iVar2;
}



===== GetStorageDumpIoMode @ 18000f048 =====

undefined8 GetStorageDumpIoMode(int param_1)

{
  if (param_1 == 0) {
    return 1;
  }
  if (param_1 == 1) {
    return 2;
  }
  if (param_1 == 2) {
    return 3;
  }
  if (param_1 == 3) {
    return 4;
  }
  return 0;
}



===== InvokeDumpCallbacks @ 18000f084 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void InvokeDumpCallbacks(longlong *param_1,undefined8 param_2,undefined4 param_3,ulonglong param_4,
                        byte param_5)

{
  char cVar1;
  undefined8 *puVar2;
  uint uVar3;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined4 local_40;
  int iStack_3c;
  
  uVar3 = 0;
  if ((*(uint *)(param_1 + 0xbb) & 0x20) != 0) {
    if ((param_5 != 0) && (DAT_18001c52b == '\x01')) {
      WriteLogString(*param_1,
                     "MiniDumpDumpWriteRetry in progress, skipping InvokeDumpCallbacks; Type: 0x%02x.\r\n"
                     ,param_4 & 0xffffffff,param_4);
    }
LAB_18000f196:
    return;
  }
  if ((param_5 != 0) && (DAT_18001c52b == '\x01')) {
    WriteLogString(*param_1,"Starting invoking dump complete callbacks; Type: 0x%02x.\r\n",
                   param_4 & 0xffffffff,param_4);
  }
  puVar2 = *(undefined8 **)param_1[0x12];
LAB_18000f136:
  if ((puVar2 == (undefined8 *)param_1[0x12]) ||
     ((((*(uint *)(param_1 + 4) & 0x3000000) == 0x3000000 &&
       (uVar3 = uVar3 + 1, *(uint *)((longlong)param_1 + 0x24) < uVar3)) ||
      (((ulonglong)puVar2 & 7) != 0)))) goto LAB_18000f162;
  if ((*(uint *)(param_1 + 4) >> 0x18 & 1) == 0) {
    cVar1 = IsBufferValid((ulonglong)puVar2,0x30);
    if (cVar1 == '\0') {
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x2000000;
LAB_18000f162:
      if ((*(uint *)(param_1 + 4) >> 0x18 & 1) == 0) {
        *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x1000000;
      }
      if ((param_5 != 0) && (DAT_18001c52b == '\x01')) {
        WriteLogString(*param_1,"Finished invoking dump complete callbacks; Type: 0x%02x.\r\n",
                       param_4 & 0xffffffff,(ulonglong)param_5);
      }
      goto LAB_18000f196;
    }
    *(int *)((longlong)param_1 + 0x24) = *(int *)((longlong)param_1 + 0x24) + 1;
  }
  if (((*(char *)((longlong)puVar2 + 0x2c) == '\x01') &&
      (puVar2[4] == puVar2[2] + (longlong)*(int *)(puVar2 + 5) + puVar2[3])) &&
     ((*(int *)(puVar2 + 5) == 3 && (cVar1 = MmIsAddressValid(), cVar1 != '\0')))) {
    MmIsAddressValid(puVar2[3]);
    local_50 = 0xffffffffffffffff;
    _local_40 = CONCAT44((int)param_4,param_3);
    uStack_48 = param_2;
    (*(code *)puVar2[2])(3,puVar2,&local_50);
    if ((int)param_4 == 4) {
      *(undefined1 *)((longlong)puVar2 + 0x2c) = 3;
    }
  }
  puVar2 = (undefined8 *)*puVar2;
  goto LAB_18000f136;
}



===== InvokeMultiPartDumpCallback @ 18000f364 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int InvokeMultiPartDumpCallback
              (undefined4 *param_1,longlong param_2,longlong *param_3,void *param_4)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  void *pvVar5;
  ulonglong uVar6;
  uint uVar7;
  int iVar8;
  undefined1 auStackY_148 [32];
  byte local_108;
  undefined4 *local_b8;
  uint local_b0;
  undefined4 local_ac;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined4 *local_98;
  uint local_90;
  uint local_80;
  undefined4 local_7c;
  undefined4 local_78;
  longlong local_70;
  longlong local_68;
  longlong local_60;
  longlong local_58;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_148;
  iVar8 = 0;
  local_108 = 1;
  uVar3 = 0;
  pvVar5 = param_4;
  memset(&local_b8,0,0x68);
  local_7c = (undefined4)param_3[3];
  local_78 = (undefined4)param_3[0x13];
  local_70 = param_3[0x14];
  local_68 = param_3[0x15];
  local_60 = param_3[0x16];
  local_58 = param_3[0x17];
  iVar2 = GetSecondaryMultiPartDumpCallbackSize(param_2,(longlong)param_3);
  *(undefined1 *)(param_2 + 0x2c) = 2;
  if (DAT_18001c52b == '\x01') {
    WriteLogString(*param_3,"Starting %s multi-part secondary callback.\r\n",param_4,pvVar5);
  }
  do {
    local_b8 = param_1 + 8;
    if (local_108 == 0) {
      local_b8 = param_1;
    }
    uVar7 = (uint)local_108 * 0x20;
    local_b0 = (uint)local_108 * -0x20 + 0xffc;
    local_ac = *(undefined4 *)((longlong)param_3 + 0x654);
    local_90 = 0;
    local_80 = -(uint)(DAT_18001c52c != '\0') & 2;
    param_1[0x3ff] = 0x706d7544;
    uVar6 = 0x68;
    local_98 = local_b8;
    (**(code **)(param_2 + 0x10))(5,param_2,&local_b8);
    if (param_1[0x3ff] != 0x706d7544) {
      *(undefined1 *)(param_2 + 0x2c) = 4;
      local_90 = 0;
      break;
    }
    param_1[0x3ff] = 0;
    if ((local_98 < param_1) || (param_1 + 0x400 <= local_98)) {
      if ((*(uint *)((longlong)param_3 + 0x654) < local_90) ||
         (cVar1 = IsBufferValid((ulonglong)local_98,local_90), cVar1 == '\0')) goto LAB_18000f640;
    }
    else {
      if ((local_98 != local_b8) || (local_b0 < local_90)) {
LAB_18000f640:
        local_90 = 0;
        *(undefined1 *)(param_2 + 0x2c) = 4;
        break;
      }
      uVar7 = uVar7 + local_90;
    }
    if (local_108 != 0) {
      *(undefined8 *)(param_1 + 6) = 0;
      *param_1 = 0x20;
      *(undefined8 *)(param_1 + 1) = local_a8;
      *(undefined8 *)(param_1 + 3) = uStack_a0;
      param_1[5] = iVar2 + -0x20;
    }
    if (uVar7 != 0) {
      uVar3 = WriteByteStreamToDisk(param_3,(longlong)param_1,uVar7);
      if ((int)uVar3 < 0) goto LAB_18000f6e3;
      iVar8 = iVar8 + uVar7;
    }
    if (local_98 != local_b8) {
      uVar3 = WriteByteStreamToDisk(param_3,(longlong)local_98,local_90);
      if ((int)uVar3 < 0) goto LAB_18000f6e3;
      iVar8 = iVar8 + local_90;
    }
    memset(param_1,0,0x1000);
    local_108 = 0;
  } while ((local_80 & 1) != 0);
  if (*(char *)(param_2 + 0x2c) != '\x04') {
    *(undefined1 *)(param_2 + 0x2c) = 3;
  }
LAB_18000f6e3:
  if ((int)uVar3 < 0) {
    pcVar4 = "Error writing secondary dump data from %s.\r\n";
    uVar6 = (ulonglong)uVar3;
    WriteDiagnosticDataToDumpHeader
              (*param_3,0,*(longlong *)(param_2 + 0x10),uVar3,param_4,
               "Error writing secondary dump data from %s.\r\n",(char)param_4);
  }
  else {
    pcVar4 = "Finish %s multi-part secondary callback.\r\n";
  }
  WriteLogString(*param_3,pcVar4,param_4,uVar6);
  return iVar8;
}



===== InvokeSecondaryDumpCallbacks @ 18000f760 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void InvokeSecondaryDumpCallbacks
               (longlong *param_1,undefined8 param_2,undefined8 param_3,char *param_4)

{
  undefined4 *_Dst;
  uint uVar1;
  int iVar2;
  char cVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  char *pcVar6;
  longlong *plVar7;
  undefined1 auStack_e8 [64];
  uint local_a8;
  uint local_a4;
  uint local_a0;
  int local_9c;
  longlong *local_98;
  undefined4 *local_90;
  longlong *local_88;
  undefined8 *local_80;
  longlong *local_78;
  undefined4 *local_70;
  undefined4 *local_68;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 *local_48;
  ulonglong uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_e8;
  _Dst = (undefined4 *)param_1[0xc];
  local_78 = param_1;
  local_70 = _Dst;
  memset(_Dst + 3,0,0xff4);
  *_Dst = 0x706d7544;
  _Dst[1] = 0x626f6c42;
  plVar5 = (longlong *)0x10;
  _Dst[2] = 0x10;
  _Dst[3] = DAT_18001c554;
  WriteByteStreamToDisk(param_1,(longlong)_Dst,0x10);
  local_a8 = *(uint *)(param_1 + 0xca);
  plVar7 = param_1 + 0x12;
  puVar4 = *(undefined8 **)*plVar7;
  local_a0 = local_a8;
  local_90 = _Dst;
  local_88 = plVar7;
  while( true ) {
    local_80 = puVar4;
    if (puVar4 == (undefined8 *)*plVar7) goto LAB_18000f866;
    if (local_a8 < 0x1001) break;
    if ((((ulonglong)puVar4 & 7) != 0) ||
       (cVar3 = IsBufferValid((ulonglong)puVar4,0x30), cVar3 == '\0')) goto LAB_18000f866;
    if ((*(int *)(puVar4 + 5) == 2) &&
       (((*(char *)((longlong)puVar4 + 0x2c) == '\x01' && (puVar4[4] == puVar4[2] + 2 + puVar4[3]))
        && (cVar3 = MmIsAddressValid(), cVar3 != '\0')))) {
      *(undefined1 *)((longlong)puVar4 + 0x2c) = 2;
      cVar3 = MmIsAddressValid(puVar4[3]);
      if (cVar3 == '\0') {
        pcVar6 = "invalid name";
      }
      else {
        pcVar6 = (char *)puVar4[3];
      }
      local_58 = 0;
      uStack_50 = 0;
      _Dst[0x3ff] = 0x706d7544;
      local_a4 = 0x20;
      local_68 = _Dst + 8;
      _uStack_60 = CONCAT44(*(undefined4 *)((longlong)param_1 + 0x654),0xfdc);
      uStack_40 = 0;
      local_98 = (longlong *)pcVar6;
      local_48 = local_68;
      if (DAT_18001c52b == '\x01') {
        WriteLogString(*param_1,"Calling %s secondary callback.\r\n",pcVar6,param_4);
      }
      param_4 = (char *)0x30;
      (*(code *)puVar4[2])(2,puVar4,&local_68);
      if (DAT_18001c52b == '\x01') {
        WriteLogString(*param_1,"Return from %s secondary callback.\r\n",pcVar6,param_4);
      }
      if (_Dst[0x3ff] == 0x706d7544) {
        _Dst[0x3ff] = 0;
        if ((local_48 < _Dst) || (_Dst + 0x400 <= local_48)) {
          if (((uint)uStack_40 <= *(uint *)((longlong)param_1 + 0x654)) &&
             (cVar3 = IsBufferValid((ulonglong)local_48,(uint)uStack_40), cVar3 != '\0')) {
            *(undefined8 *)(_Dst + 6) = 0;
            goto LAB_18000fa6c;
          }
          goto LAB_18000fb0e;
        }
        if ((local_48 != _Dst + 8) || (0xfdc < (uint)uStack_40)) goto LAB_18000fb0e;
        *(undefined8 *)(_Dst + 6) = 0;
        local_a4 = (uint)uStack_40 + 0x20;
LAB_18000fa6c:
        uVar1 = local_a4;
        *_Dst = 0x20;
        *(undefined8 *)(_Dst + 1) = local_58;
        *(undefined8 *)(_Dst + 3) = uStack_50;
        _Dst[5] = (uint)uStack_40;
        if (DAT_18001c52b == '\x01') {
          WriteLogString(*param_1,"Writing %s secondary callback data.\r\n",pcVar6,param_4);
        }
        plVar5 = (longlong *)(ulonglong)uVar1;
        local_9c = WriteByteStreamToDisk(param_1,(longlong)_Dst,uVar1);
        if ((-1 < local_9c) && (local_48 != local_68)) {
          plVar5 = (longlong *)(uStack_40 & 0xffffffff);
          local_9c = WriteByteStreamToDisk(param_1,(longlong)local_48,(uint)uStack_40);
        }
        iVar2 = local_9c;
        if (DAT_18001c52b == '\x01') {
          WriteLogString(*param_1,"Writing %s secondary callback data done.\r\n",pcVar6,param_4);
          plVar5 = (longlong *)pcVar6;
        }
        if (iVar2 < 0) goto LAB_18000f866;
      }
      else {
LAB_18000fb0e:
        uStack_40 = uStack_40 & 0xffffffff00000000;
      }
      *(undefined1 *)((longlong)puVar4 + 0x2c) = 3;
      local_a4 = 0;
      plVar5 = (longlong *)0x1000;
      local_90 = _Dst;
      memset(_Dst,0,0x1000);
      local_a8 = local_a8 - ((uint)uStack_40 + 0xfff & 0xfffff000);
      plVar7 = local_88;
      local_a0 = local_a8;
    }
    puVar4 = (undefined8 *)*puVar4;
  }
  if (DAT_18001c52b == '\x01') {
    WriteLogString(*param_1,"Out of space. Secondary callback data not written out.\r\n",plVar5,
                   param_4);
  }
  for (; puVar4 != (undefined8 *)*plVar7; puVar4 = (undefined8 *)*puVar4) {
    cVar3 = MmIsAddressValid(puVar4);
    if (cVar3 != '\0') {
      MmIsAddressValid(puVar4[3]);
    }
  }
LAB_18000f866:
  InvokeSecondaryMultiPartDumpCallbacks(param_1,local_a8,plVar5,param_4);
  WriteByteStreamToDisk(param_1,(longlong)_Dst,0);
  return;
}



===== InvokeSecondaryMultiPartDumpCallbacks @ 18000fc2c =====

void InvokeSecondaryMultiPartDumpCallbacks
               (longlong *param_1,uint param_2,longlong *param_3,char *param_4)

{
  undefined4 *_Dst;
  char cVar1;
  int iVar2;
  undefined8 *puVar3;
  char *pcVar4;
  
  WriteLogString(*param_1,"Calling secondary multi-part dump callbacks.\r\n",param_3,param_4);
  _Dst = (undefined4 *)param_1[0xc];
  puVar3 = *(undefined8 **)param_1[0x12];
  while( true ) {
    if ((puVar3 == (undefined8 *)param_1[0x12]) || (((ulonglong)puVar3 & 7) != 0))
    goto LAB_18000fd6b;
    if (param_2 < 0x1001) break;
    cVar1 = IsBufferValid((ulonglong)puVar3,0x30);
    if (cVar1 == '\0') goto LAB_18000fd6b;
    if ((*(int *)(puVar3 + 5) == 5) && (*(char *)((longlong)puVar3 + 0x2c) == '\x01')) {
      if (puVar3[4] == puVar3[3] + 5 + puVar3[2]) {
        cVar1 = MmIsAddressValid();
        if (cVar1 == '\0') {
          pcVar4 = "invalid name";
        }
        else {
          pcVar4 = (char *)puVar3[3];
        }
        cVar1 = MmIsAddressValid(puVar3[2]);
        if (cVar1 != '\0') {
          memset(_Dst,0,0x1000);
          param_3 = param_1;
          iVar2 = InvokeMultiPartDumpCallback(_Dst,(longlong)puVar3,param_1,pcVar4);
          param_2 = param_2 - (iVar2 + 0xfffU & 0xfffff000);
          param_4 = pcVar4;
        }
      }
    }
    puVar3 = (undefined8 *)*puVar3;
  }
  if (DAT_18001c52b == '\x01') {
    WriteLogString(*param_1,"Out of space. Secondary callback data not written out.\r\n",param_3,
                   param_4);
  }
  for (; puVar3 != (undefined8 *)param_1[0x12]; puVar3 = (undefined8 *)*puVar3) {
    cVar1 = MmIsAddressValid(puVar3);
    if (cVar1 != '\0') {
      MmIsAddressValid(puVar3[3]);
    }
  }
LAB_18000fd6b:
  WriteLogString(*param_1,"Finish calling secondary multi-part dump callbacks.\r\n",param_3,param_4)
  ;
  return;
}



===== ValidateWrite @ 18000fd9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ValidateWrite(void *param_1,uint param_2,void *param_3,longlong param_4,undefined *param_5)

{
  int iVar1;
  undefined1 auStack_898 [32];
  undefined1 local_878 [8];
  short local_870;
  ushort local_86e;
  ulonglong local_858;
  uint local_850;
  uint local_84c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_898;
  memset(local_878,0,0x838);
  if ((((param_1 != (void *)0x0) && (param_5 != (undefined *)0x0)) && (param_3 != (void *)0x0)) &&
     ((param_4 != 0 && (param_2 - 1 < 0x100000)))) {
    local_86e = 0;
    local_84c = (uint)param_1 & 0xfff;
    local_870 = ((short)((ulonglong)param_2 + 0xfff + ((ulonglong)param_1 & 0xfff) >> 0xc) + 6) * 8;
    local_858 = (ulonglong)param_1 & 0xfffffffffffff000;
    local_850 = param_2;
    MmBuildMdlForNonPagedPool(local_878);
    local_86e = local_86e | 1;
    iVar1 = (*(code *)param_5)(0,param_4,local_878);
    if (-1 < iVar1) {
      iVar1 = memcmp(param_1,param_3,(ulonglong)param_2);
      if (iVar1 != 0) {
        _DAT_18001c54c = _DAT_18001c54c + 1;
      }
    }
  }
  return;
}



===== ValidateWriteDumpInfo @ 18000feec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ValidateWriteDumpInfo
               (longlong param_1,undefined *param_2,void *param_3,uint param_4,void *param_5,
               longlong *param_6,longlong param_7,undefined8 *param_8)

{
  int iVar1;
  ulonglong uVar2;
  bool bVar3;
  undefined1 auStackY_8d8 [32];
  longlong local_898 [4];
  undefined1 local_878 [8];
  short local_870;
  undefined2 local_86e;
  ulonglong local_858;
  uint local_850;
  uint local_84c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_8d8;
  local_898[3] = param_1;
  memset(local_878,0,0x838);
  local_898[1] = 0x10;
  local_898[0] = 0;
  bVar3 = false;
  local_898[2] = 0;
  if ((((param_3 != (void *)0x0) && (param_2 != (undefined *)0x0)) && (param_5 != (void *)0x0)) &&
     ((param_6 != (longlong *)0x0 && (param_4 - 1 < 0x100000)))) {
    local_86e = 0;
    local_84c = (uint)param_3 & 0xfff;
    local_870 = ((short)((ulonglong)param_4 + 0xfff + ((ulonglong)param_3 & 0xfff) >> 0xc) + 6) * 8;
    local_858 = (ulonglong)param_3 & 0xfffffffffffff000;
    local_850 = param_4;
    MmBuildMdlForNonPagedPool(local_878);
    uVar2 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
    if ((int)uVar2 != 0) {
      local_898[0] = param_7;
      FilterCallback(5,param_8,(undefined8 *)0x1,(undefined8 *)0x0,local_898,local_878,local_898 + 1
                    );
      param_6 = local_898;
      local_898[0] = local_898[0] + param_8[0x21];
      bVar3 = param_8[0x42] != 0;
    }
    if (bVar3) {
      iVar1 = (*(code *)param_8[0x42])(*(undefined8 *)(local_898[3] + 0x10),1);
    }
    else {
      iVar1 = (*(code *)param_2)(*(undefined8 *)(local_898[3] + 0x10),1,param_6,local_878);
    }
    if (-1 < iVar1) {
      iVar1 = memcmp(param_3,param_5,(ulonglong)param_4);
      if (iVar1 != 0) {
        _DAT_18001c54c = _DAT_18001c54c + 1;
      }
    }
  }
  return;
}



===== AddDumpDirToStorageHardReserve @ 1800100ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong AddDumpDirToStorageHardReserve(longlong param_1)

{
  uint uVar1;
  wchar_t *pwVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 auStack_1f8 [32];
  undefined4 local_1d8;
  undefined4 local_1d0;
  longlong local_1c8 [6];
  undefined4 local_198;
  undefined4 local_194;
  undefined8 local_190;
  longlong *local_188;
  undefined4 local_180;
  undefined4 local_17c;
  undefined8 local_178;
  undefined8 uStack_170;
  int local_168 [4];
  wchar_t local_158 [80];
  wchar_t local_b8 [80];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_1f8;
  local_1c8[0] = 0;
  local_168[2] = 0;
  local_194 = 0;
  local_17c = 0;
  local_1c8[2] = 0;
  local_1c8[3] = 0;
  local_1c8[1] = 0;
  local_168[0] = 0;
  local_168[1] = 0;
  local_1c8[4] = 0;
  local_1c8[5] = 0;
  RtlStringCchPrintfW(local_158,0x50,L"\\??\\%s",*(undefined8 *)(param_1 + 0x30));
  lVar4 = -1;
  lVar5 = -1;
  do {
    lVar5 = lVar5 + 1;
  } while (local_158[lVar5] != L'\0');
  pwVar2 = wcsrchr(local_158,L'\\');
  do {
    lVar4 = lVar4 + 1;
  } while (pwVar2[lVar4] != L'\0');
  wcsncpy_s(local_b8,0x50,local_158,(ulonglong)(uint)((int)lVar5 - (int)lVar4));
  RtlInitUnicodeString(local_1c8 + 4,local_b8);
  local_188 = local_1c8 + 4;
  local_1d0 = 1;
  local_198 = 0x30;
  local_190 = 0;
  local_180 = 0x200;
  local_1d8 = 3;
  local_178 = 0;
  uStack_170 = 0;
  uVar3 = ZwOpenFile(local_1c8,0x100180,&local_198,local_1c8 + 2);
  if (-1 < (int)uVar3) {
    local_1d8 = 0x4a;
    uVar1 = NtQueryInformationFile(local_1c8[0],local_1c8 + 2,local_168,0x10);
    uVar3 = (ulonglong)uVar1;
    if ((-1 < (int)uVar1) && (local_168[0] != 1)) {
      local_1c8[1] = 1;
      local_1d8 = 0x4a;
      uVar1 = NtSetInformationFile(local_1c8[0],local_1c8 + 2,local_1c8 + 1,8);
      uVar3 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) {
        local_1d8 = 0x4a;
        uVar1 = NtQueryInformationFile(local_1c8[0],local_1c8 + 2,local_168,0x10);
        uVar3 = (ulonglong)uVar1;
        if ((-1 < (int)uVar1) && (local_168[0] != 1)) {
          uVar3 = 0xc0000001;
        }
      }
    }
    if (local_1c8[0] != 0) {
      ZwClose();
    }
  }
  return uVar3;
}



===== CheckContextIntegrity @ 180010304 =====

undefined8 CheckContextIntegrity(void)

{
  if ((((Context == 0x706d4443) && (DAT_18001c5b4 == 0x706d4443)) && (DAT_18001bcf4 != '\0')) &&
     (DAT_18001c360 == 0x706d7544)) {
    memcpy(&DAT_18001b4e0,&DAT_18001bdc0,0x5a0);
    RtlCompareMemory(&Context,&ContextCopy,0x8d0);
  }
  return 0;
}



===== CheckDumpFilePathDosnamePrefix @ 18001037c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CheckDumpFilePathDosnamePrefix(longlong param_1)

{
  int iVar1;
  wchar_t *pwVar2;
  undefined1 auStack_d8 [32];
  wchar_t local_b8 [80];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_d8;
  memset(local_b8,0,0xa0);
  pwVar2 = *(wchar_t **)(param_1 + 0x30);
  if (pwVar2 != (wchar_t *)0x0) {
    iVar1 = wcsncmp(pwVar2,L"\\??\\",4);
    if (iVar1 == 0) {
      pwVar2 = pwVar2 + 4;
    }
    else {
      iVar1 = wcsncmp(pwVar2,L"\\DosDevices\\",0xc);
      if (iVar1 != 0) {
        return;
      }
      pwVar2 = pwVar2 + 0xc;
    }
    wcscpy_s(local_b8,0x50,pwVar2);
    RtlUnicodeStringCopyStringEx((ushort *)(param_1 + 0x28),local_b8);
  }
  return;
}



===== CheckForCrashDump @ 180010450 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CheckForCrashDump(longlong param_1)

{
  int *piVar1;
  undefined1 *puVar2;
  int iVar3;
  wchar_t *pwVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  uint uVar8;
  ulonglong uVar9;
  undefined1 auStack_1a8 [32];
  short *local_188;
  undefined8 local_180;
  undefined8 local_178;
  undefined8 local_170;
  undefined8 local_168;
  longlong local_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined4 local_138 [2];
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined4 local_108;
  undefined4 local_104;
  undefined8 local_100;
  undefined8 *local_f8;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined8 local_e8;
  undefined8 uStack_e0;
  wchar_t local_d8 [4];
  short local_d0 [76];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_1a8;
  local_104 = 0;
  local_ec = 0;
  local_110 = 0;
  local_158 = 0;
  local_140 = 0;
  local_150 = 0;
  uStack_148 = 0;
  local_120 = 0;
  uStack_118 = 0;
  local_130 = 0;
  uStack_128 = 0;
  RtlStringCchPrintfW(local_d8,0x50,L"\\??\\%s",*(undefined8 *)(param_1 + 0x30));
  RtlInitUnicodeString(&local_130,local_d8);
  local_f8 = &local_130;
  local_180 = CONCAT44(local_180._4_4_,0x28);
  local_108 = 0x30;
  local_100 = 0;
  local_f0 = 0x240;
  local_188 = (short *)CONCAT44(local_188._4_4_,3);
  local_e8 = 0;
  uStack_e0 = 0;
  iVar3 = ZwOpenFile(&local_158,0xc0150000,&local_108,&local_150);
  if ((iVar3 < 0) || ((int)local_150 < 0)) goto LAB_18001089b;
  local_180 = *(undefined8 *)(param_1 + 0x60);
  local_168 = 0;
  local_170 = 0;
  local_178 = CONCAT44(local_178._4_4_,0x2000);
  local_188 = (short *)&local_150;
  iVar3 = ZwReadFile(local_158,0,0,0);
  if ((iVar3 < 0) ||
     ((((int)local_150 < 0 || (piVar1 = *(int **)(param_1 + 0x60), *piVar1 != 0x45474150)) ||
      (piVar1[1] != 0x34365544)))) goto LAB_18001089b;
  puVar2 = *(undefined1 **)(param_1 + 0x638);
  uVar9 = (ulonglong)_DAT_fffff78000000004 * _DAT_fffff78000000320;
  RtlStringCchPrintfW(local_d8,0x50,L"\\??\\%s",*(undefined8 *)(param_1 + 0x30));
  lVar7 = -1;
  lVar6 = -1;
  do {
    lVar6 = lVar6 + 1;
  } while (local_d8[lVar6] != L'\0');
  pwVar4 = wcsrchr(local_d8,L'\\');
  lVar5 = -1;
  do {
    lVar5 = lVar5 + 1;
  } while (pwVar4[lVar5] != L'\0');
  RtlStringCchPrintfW(pwVar4,(0x50 - lVar6) + lVar5 & 0xffffffff,L"\\DUMP%4.4x.tmp",
                      uVar9 >> 0x18 & 0xffff);
  RtlInitUnicodeString(&local_130,local_d8);
  uVar8 = (uint)(ushort)local_130;
  *(undefined8 *)(puVar2 + 8) = 0;
  *puVar2 = 1;
  *(uint *)(puVar2 + 0x10) = (uint)(ushort)local_130;
  RtlStringCchCopyW((short *)(puVar2 + 0x14),(ulonglong)(uint)(ushort)local_130,uStack_128);
  local_188 = (short *)CONCAT44(local_188._4_4_,10);
  iVar3 = ZwSetInformationFile(local_158,&local_150,puVar2,uVar8 + 0x18);
  if ((iVar3 < 0) || ((int)local_150 < 0)) {
LAB_18001087f:
    if (iVar3 < 0) {
      CrashdmpLogSELEarlyError();
      goto LAB_18001089b;
    }
  }
  else {
    local_110 = *(undefined8 *)(piVar1 + 1000);
    local_188 = (short *)CONCAT44(local_188._4_4_,0x14);
    iVar3 = ZwSetInformationFile(local_158,&local_150,&local_110,8);
    if ((iVar3 < 0) || ((int)local_150 < 0)) goto LAB_18001087f;
    ZwClose(local_158);
    local_158 = 0;
    RtlInitUnicodeString
              (&local_120,
               L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl\\MachineCrash"
              );
    local_f8 = &local_120;
    local_178 = 0;
    local_180 = CONCAT44(local_180._4_4_,1);
    local_108 = 0x30;
    local_100 = 0;
    local_f0 = 0x240;
    local_e8 = 0;
    uStack_e0 = 0;
    local_188 = (short *)0x0;
    iVar3 = ZwCreateKey(&local_140,0x2001f,&local_108,0);
    if (iVar3 < 0) goto LAB_18001087f;
    if (DAT_18001c444 == 0x7000) {
      iVar3 = -0x3fffffff;
      local_150 = CONCAT44(local_150._4_4_,0xc000014d);
      goto LAB_18001087f;
    }
    local_138[0] = 1;
    do {
      lVar7 = lVar7 + 1;
    } while (local_d0[lVar7] != 0);
    RtlInitUnicodeString(&local_120,L"DumpFile");
    local_188 = local_d0;
    local_180._0_4_ = (int)lVar7 * 2;
    ZwSetValueKey(local_140,&local_120,0,1);
    RtlInitUnicodeString(&local_120,L"TempDestination");
    local_188 = (short *)local_138;
    local_180 = CONCAT44(local_180._4_4_,4);
    iVar3 = ZwSetValueKey(local_140,&local_120,0);
    ZwClose(local_140);
    if (iVar3 < 0) goto LAB_18001087f;
  }
  CrashdmpLogSELEarlyCheckpoint_ULONG1();
LAB_18001089b:
  if (local_158 != 0) {
    ZwClose();
  }
  return;
}



===== CheckForLogFile @ 1800108e8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CheckForLogFile(undefined8 param_1)

{
  code *pcVar1;
  bool bVar2;
  bool bVar3;
  longlong lVar4;
  int *piVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  int iVar10;
  char *pcVar11;
  longlong lVar12;
  char cVar13;
  char cVar14;
  char cVar15;
  char cVar16;
  longlong *plVar17;
  char *pcVar18;
  undefined4 uVar19;
  ulonglong uVar20;
  char *pcVar21;
  ulonglong uVar22;
  size_t sVar23;
  char *pcVar24;
  undefined8 *puVar25;
  undefined8 uVar26;
  char *pcVar27;
  uint uVar28;
  undefined4 uVar29;
  longlong lVar30;
  char cVar31;
  char cVar32;
  char cVar33;
  char cVar34;
  char cVar35;
  char cVar36;
  char cVar37;
  char cVar38;
  char cVar39;
  char cVar40;
  char cVar41;
  undefined1 auStackY_4b8 [32];
  char local_468;
  char local_467 [3];
  undefined4 local_464;
  undefined4 local_460;
  undefined1 local_45c [4];
  char *local_458;
  uint local_450;
  undefined4 local_44c;
  longlong local_448;
  undefined8 local_440;
  undefined8 uStack_438;
  undefined8 local_430;
  ulonglong local_428;
  ulonglong local_420;
  undefined8 uStack_418;
  undefined8 local_410;
  undefined4 local_408;
  undefined4 local_404;
  undefined8 local_400;
  ulonglong *local_3f8;
  undefined4 local_3f0;
  undefined4 local_3ec;
  undefined8 local_3e8;
  undefined8 uStack_3e0;
  undefined8 local_3d8;
  longlong lStack_3d0;
  undefined8 local_3c8;
  undefined8 local_3c0;
  undefined8 uStack_3b8;
  undefined8 local_3b0;
  undefined8 uStack_3a8;
  undefined8 local_3a0;
  undefined8 local_398 [4];
  ulonglong *local_378;
  undefined8 local_370;
  char *local_368;
  undefined8 local_360;
  char *local_358;
  undefined8 local_350;
  undefined4 *local_348;
  undefined8 local_340;
  undefined4 *local_338;
  undefined8 local_330;
  char **local_328;
  undefined8 local_320;
  char *local_318;
  int local_310;
  undefined4 local_30c;
  uint *local_308;
  undefined8 local_300;
  longlong local_2f8 [2];
  longlong local_2e8 [2];
  undefined1 *local_2d8;
  undefined8 local_2d0;
  undefined1 local_2c8 [32];
  char **local_2a8;
  undefined8 local_2a0;
  longlong local_298 [2];
  longlong local_288 [2];
  undefined8 local_278;
  char local_270;
  char local_268;
  undefined1 uStack_267;
  undefined1 uStack_266;
  undefined1 uStack_265;
  undefined1 uStack_264;
  undefined1 uStack_263;
  undefined1 uStack_262;
  undefined1 uStack_261;
  undefined1 uStack_260;
  undefined1 uStack_25f;
  undefined1 uStack_25e;
  undefined1 uStack_25d;
  undefined1 uStack_25c;
  undefined1 uStack_25b;
  undefined1 uStack_25a;
  undefined1 uStack_259;
  char local_258 [176];
  undefined1 local_1a8 [8];
  undefined8 local_1a0;
  uint local_198;
  short local_194 [82];
  undefined2 auStack_f0 [4];
  wchar_t local_e8 [80];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_4b8;
  local_404 = 0;
  local_3ec = 0;
  local_448 = 0;
  local_440 = 0;
  uStack_438 = 0;
  local_420 = 0;
  uStack_418 = 0;
  local_430 = param_1;
  memset(local_1a8,0,0xb8);
  pcVar11 = (char *)0x0;
  RtlInitUnicodeString(&local_420,param_1);
  local_3f8 = &local_420;
  local_408 = 0x30;
  local_400 = 0;
  local_3f0 = 0x240;
  local_3e8 = 0;
  uStack_3e0 = 0;
  iVar10 = ZwOpenFile(&local_448,0xc0150000,&local_408,&local_440);
  if (((((iVar10 < 0) || ((int)local_440 < 0)) ||
       (iVar10 = ZwReadFile(local_448,0,0,0), piVar5 = DAT_18001bda0, iVar10 < 0)) ||
      (((int)local_440 < 0 || (*DAT_18001bda0 != 0x474f4c44)))) ||
     ((DAT_18001bda0[1] != 0x454c4946 ||
      ((DAT_18001bda0[2] != 0x31303030 || (DAT_18001bda0[3] != 0x30303030)))))) goto LAB_180010a67;
  if (DAT_18001bda0[4] == 0x504d5544) {
    if (DAT_18001c58a == '\0') {
      local_410 = 0;
      local_3c8 = 0;
      local_3d8 = 0;
      lStack_3d0 = 0;
      iVar10 = ZwQueryInformationFile(local_448,&local_440,&local_3d8);
      if ((((-1 < iVar10) && (-1 < (int)local_440)) && (lStack_3d0 < 0x8001)) &&
         ((((longlong)(ulonglong)(uint)piVar5[5] <= lStack_3d0 &&
           (pcVar11 = (char *)ExAllocatePool2(0x40,lStack_3d0,0x706d4443), pcVar11 != (char *)0x0))
          && ((iVar10 = ZwReadFile(local_448,0,0), -1 < iVar10 && (-1 < (int)local_440)))))) {
        local_467[0] = '\0';
        local_450 = 0;
        local_468 = '\0';
        local_464 = 0;
        uVar19 = 0;
        local_44c = 0;
        uVar29 = 0;
        local_460 = 0;
        local_278 = 0;
        local_270 = '\0';
        local_258[0] = '\0';
        local_258[1] = '\0';
        local_258[2] = '\0';
        local_258[3] = '\0';
        local_258[4] = '\0';
        local_258[5] = '\0';
        local_258[6] = '\0';
        local_258[7] = '\0';
        local_258[8] = '\0';
        local_258[9] = '\0';
        local_258[10] = '\0';
        local_258[0xb] = '\0';
        local_258[0xc] = '\0';
        local_258[0xd] = '\0';
        local_258[0xe] = '\0';
        local_258[0xf] = '\0';
        local_258[0x10] = '\0';
        local_258[0x11] = 0;
        local_258[0x12] = 0;
        local_258[0x13] = 0;
        local_258[0x14] = 0;
        local_258[0x15] = 0;
        local_258[0x16] = 0;
        local_258[0x17] = 0;
        local_258[0x18] = 0;
        local_258[0x19] = 0;
        local_258[0x1a] = 0;
        local_258[0x1b] = 0;
        local_258[0x1c] = 0;
        local_258[0x1d] = 0;
        local_258[0x1e] = 0;
        local_258[0x1f] = 0;
        local_458 = pcVar11;
        memset(local_258 + 0x30,0,0x80);
        uVar20 = (ulonglong)(uint)piVar5[5];
        if (pcVar11 < pcVar11 + (uVar20 - 1)) {
          pcVar18 = pcVar11;
          pcVar27 = pcVar11;
LAB_180010c31:
          if (pcVar27 < pcVar11 + uVar20) {
            lVar30 = RtlCompareMemory(pcVar27,"\r\n");
            if (lVar30 == 2) {
              uVar20 = (longlong)pcVar27 - (longlong)pcVar18;
              uVar22 = uVar20;
              if (0x1c < uVar20) {
                uVar22 = 0x1c;
              }
              local_428 = uVar20;
              lVar30 = RtlCompareMemory(pcVar18,"Dump completed successfully.",uVar22);
              if (lVar30 != 0x1c) {
                uVar22 = uVar20;
                if (0x12 < uVar20) {
                  uVar22 = 0x12;
                }
                lVar30 = RtlCompareMemory(pcVar18,"Dump failed status",uVar22);
                if (lVar30 == 0x12) {
                  cVar13 = pcVar18[0x13];
                  local_468 = '\x01';
                  local_467[0] = '\0';
                  if (9 < (byte)(cVar13 - 0x30U)) {
                    if ((byte)(cVar13 + 0xbfU) < 6) {
                      cVar13 = cVar13 + -0x37;
                    }
                    else {
                      cVar13 = cVar13 + -0x57;
                    }
                  }
                  cVar14 = pcVar18[0x14];
                  bVar6 = cVar14 - 0x30;
                  if (9 < bVar6) {
                    if ((byte)(cVar14 + 0xbfU) < 6) {
                      bVar6 = cVar14 - 0x37;
                    }
                    else {
                      bVar6 = cVar14 + 0xa9;
                    }
                  }
                  cVar14 = pcVar18[0x15];
                  if (9 < (byte)(cVar14 - 0x30U)) {
                    if ((byte)(cVar14 + 0xbfU) < 6) {
                      cVar14 = cVar14 + -0x37;
                    }
                    else {
                      cVar14 = cVar14 + -0x57;
                    }
                  }
                  cVar15 = pcVar18[0x16];
                  bVar7 = cVar15 - 0x30;
                  if (9 < bVar7) {
                    if ((byte)(cVar15 + 0xbfU) < 6) {
                      bVar7 = cVar15 - 0x37;
                    }
                    else {
                      bVar7 = cVar15 + 0xa9;
                    }
                  }
                  cVar15 = pcVar18[0x17];
                  if (9 < (byte)(cVar15 - 0x30U)) {
                    if ((byte)(cVar15 + 0xbfU) < 6) {
                      cVar15 = cVar15 + -0x37;
                    }
                    else {
                      cVar15 = cVar15 + -0x57;
                    }
                  }
                  cVar16 = pcVar18[0x18];
                  bVar8 = cVar16 - 0x30;
                  if (9 < bVar8) {
                    if ((byte)(cVar16 + 0xbfU) < 6) {
                      bVar8 = cVar16 - 0x37;
                    }
                    else {
                      bVar8 = cVar16 + 0xa9;
                    }
                  }
                  cVar16 = pcVar18[0x19];
                  if (9 < (byte)(cVar16 - 0x30U)) {
                    if ((byte)(cVar16 + 0xbfU) < 6) {
                      cVar16 = cVar16 + -0x37;
                    }
                    else {
                      cVar16 = cVar16 + -0x57;
                    }
                  }
                  cVar31 = pcVar18[0x1a];
                  bVar9 = cVar31 - 0x30;
                  if (9 < bVar9) {
                    if ((byte)(cVar31 + 0xbfU) < 6) {
                      bVar9 = cVar31 - 0x37;
                    }
                    else {
                      bVar9 = cVar31 + 0xa9;
                    }
                  }
                  local_464 = CONCAT31(CONCAT21(CONCAT11(cVar13 * '\x10' + bVar6,
                                                         cVar14 * '\x10' + bVar7),
                                                cVar15 * '\x10' + bVar8),cVar16 * '\x10' + bVar9);
                  goto LAB_18001122c;
                }
                uVar22 = uVar20;
                if (0x1a < uVar20) {
                  uVar22 = 0x1a;
                }
                lVar30 = RtlCompareMemory(pcVar18,"Elapsed BugCheck duration ",uVar22);
                if (lVar30 == 0x1a) {
                  local_278 = *(undefined8 *)(pcVar18 + 0x1a);
                  local_270 = pcVar18[0x22];
                  iVar10 = RtlCharToInteger(&local_278,10,&local_44c);
                  if (iVar10 < 0) {
                    local_44c = 0;
                  }
                  goto LAB_18001122c;
                }
                uVar22 = uVar20;
                if (9 < uVar20) {
                  uVar22 = 9;
                }
                lVar30 = RtlCompareMemory(pcVar18,"Progress ",uVar22);
                if (lVar30 == 9) {
                  cVar13 = pcVar18[0xb];
                  if (9 < (byte)(cVar13 - 0x30U)) {
                    if ((byte)(cVar13 + 0xbfU) < 6) {
                      cVar13 = cVar13 + -0x37;
                    }
                    else {
                      cVar13 = cVar13 + -0x57;
                    }
                  }
                  cVar14 = pcVar18[0xc];
                  bVar6 = cVar14 - 0x30;
                  if (9 < bVar6) {
                    if ((byte)(cVar14 + 0xbfU) < 6) {
                      bVar6 = cVar14 - 0x37;
                    }
                    else {
                      bVar6 = cVar14 + 0xa9;
                    }
                  }
                  cVar14 = pcVar18[0xd];
                  if (9 < (byte)(cVar14 - 0x30U)) {
                    if ((byte)(cVar14 + 0xbfU) < 6) {
                      cVar14 = cVar14 + -0x37;
                    }
                    else {
                      cVar14 = cVar14 + -0x57;
                    }
                  }
                  cVar15 = pcVar18[0xe];
                  bVar7 = cVar15 - 0x30;
                  if (9 < bVar7) {
                    if ((byte)(cVar15 + 0xbfU) < 6) {
                      bVar7 = cVar15 - 0x37;
                    }
                    else {
                      bVar7 = cVar15 + 0xa9;
                    }
                  }
                  cVar15 = pcVar18[0xf];
                  if (9 < (byte)(cVar15 - 0x30U)) {
                    if ((byte)(cVar15 + 0xbfU) < 6) {
                      cVar15 = cVar15 + -0x37;
                    }
                    else {
                      cVar15 = cVar15 + -0x57;
                    }
                  }
                  cVar16 = pcVar18[0x10];
                  bVar8 = cVar16 - 0x30;
                  if (9 < bVar8) {
                    if ((byte)(cVar16 + 0xbfU) < 6) {
                      bVar8 = cVar16 - 0x37;
                    }
                    else {
                      bVar8 = cVar16 + 0xa9;
                    }
                  }
                  cVar16 = pcVar18[0x11];
                  if (9 < (byte)(cVar16 - 0x30U)) {
                    if ((byte)(cVar16 + 0xbfU) < 6) {
                      cVar16 = cVar16 + -0x37;
                    }
                    else {
                      cVar16 = cVar16 + -0x57;
                    }
                  }
                  cVar31 = pcVar18[0x12];
                  bVar9 = cVar31 - 0x30;
                  if (9 < bVar9) {
                    if ((byte)(cVar31 + 0xbfU) < 6) {
                      bVar9 = cVar31 - 0x37;
                    }
                    else {
                      bVar9 = cVar31 + 0xa9;
                    }
                  }
                  local_460 = CONCAT31(CONCAT21(CONCAT11(cVar13 * '\x10' + bVar6,
                                                         cVar14 * '\x10' + bVar7),
                                                cVar15 * '\x10' + bVar8),cVar16 * '\x10' + bVar9);
                  goto LAB_18001122c;
                }
                if ((uVar20 < 0x14) || (lVar30 = RtlCompareMemory(pcVar27 + -0x13), lVar30 != 0x13))
                goto LAB_18001122c;
                bVar3 = false;
                bVar2 = false;
                cVar13 = 0;
                cVar14 = 0;
                cVar15 = 0;
                cVar16 = 0;
                cVar31 = 0;
                cVar32 = 0;
                cVar33 = 0;
                cVar34 = 0;
                cVar35 = 0;
                cVar36 = 0;
                cVar37 = 0;
                cVar38 = 0;
                cVar39 = 0;
                cVar40 = 0;
                cVar41 = 0;
                local_258[0x20] = 0;
                local_258[0x21] = 0;
                local_258[0x22] = 0;
                local_258[0x23] = 0;
                local_258[0x24] = 0;
                local_258[0x25] = 0;
                local_258[0x26] = 0;
                local_258[0x27] = 0;
                local_258[0x28] = 0;
                local_258[0x29] = 0;
                local_258[0x2a] = 0;
                local_258[0x2b] = 0;
                local_258[0x2c] = 0;
                local_258[0x2d] = 0;
                local_258[0x2e] = 0;
                local_258[0x2f] = 0;
                local_268 = '\0';
                uStack_267 = 0;
                uStack_266 = 0;
                uStack_265 = 0;
                uStack_264 = 0;
                uStack_263 = 0;
                uStack_262 = 0;
                uStack_261 = 0;
                uStack_260 = 0;
                uStack_25f = 0;
                uStack_25e = 0;
                uStack_25d = 0;
                uStack_25c = 0;
                uStack_25b = 0;
                uStack_25a = 0;
                uStack_259 = 0;
                for (pcVar21 = pcVar18; pcVar21 < pcVar27; pcVar21 = pcVar21 + 1) {
                  if (*pcVar21 == ':') {
                    bVar3 = true;
                    sVar23 = 0xf;
                    if ((ulonglong)((longlong)pcVar21 - (longlong)pcVar18) < 0xf) {
                      sVar23 = (longlong)pcVar21 - (longlong)pcVar18;
                    }
                    memcpy(&local_268,pcVar18,sVar23);
                    pcVar24 = pcVar21 + 2;
                    pcVar27 = pcVar24;
                    if (pcVar21 + 0x14 < local_458) goto LAB_180011085;
                    goto LAB_1800110e4;
                  }
                }
                goto LAB_1800110f0;
              }
              local_467[0] = '\x01';
              local_468 = '\x01';
              goto LAB_18001122c;
            }
            pcVar27 = pcVar27 + 1;
            goto LAB_18001126d;
          }
          goto LAB_180011287;
        }
        cVar13 = '\0';
        goto LAB_180011372;
      }
    }
  }
  else if (DAT_18001bda0[4] != 0x52424948) goto LAB_180010a67;
LAB_180011535:
  lVar30 = -1;
  RtlStringCchPrintfW(local_e8,0x50,L"%s",param_1);
  do {
    lVar30 = lVar30 + 1;
  } while (local_e8[lVar30] != L'\0');
  if (0x9f < lVar30 * 2 - 8U) {
    __report_rangecheckfailure();
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  auStack_f0[lVar30] = 0;
  RtlInitUnicodeString(&local_420,local_e8);
  uVar28 = (uint)(ushort)local_420;
  if ((ushort)local_420 < 0xa0) {
    local_198 = (uint)(ushort)local_420;
    local_1a8[0] = 1;
    local_1a0 = 0;
    RtlStringCchCopyW(local_194,local_420 & 0xffff,uStack_418);
    ZwSetInformationFile(local_448,&local_440,local_1a8,uVar28 + 0x18);
  }
LAB_180010a67:
  if (local_448 != 0) {
    ZwClose();
  }
  if (pcVar11 != (char *)0x0) {
    ExFreePoolWithTag(pcVar11,0);
  }
  return;
  while (pcVar21 = pcVar27 + 0x13, pcVar27 = pcVar27 + 1, pcVar21 < local_458) {
LAB_180011085:
    lVar30 = RtlCompareMemory(pcVar27,"callback exception.");
    if (lVar30 == 0x13) {
      bVar2 = true;
      pcVar21 = (char *)0xf;
      if (pcVar27 + (-1 - (longlong)pcVar24) < (char *)0xf) {
        pcVar21 = pcVar27 + (-1 - (longlong)pcVar24);
      }
      memcpy(local_258 + 0x20,pcVar24,(size_t)pcVar21);
      break;
    }
  }
  cVar13 = local_258[0x20];
  cVar14 = local_258[0x21];
  cVar15 = local_258[0x22];
  cVar16 = local_258[0x23];
  cVar31 = local_258[0x24];
  cVar32 = local_258[0x25];
  cVar33 = local_258[0x26];
  cVar34 = local_258[0x27];
  cVar35 = local_258[0x28];
  cVar36 = local_258[0x29];
  cVar37 = local_258[0x2a];
  cVar38 = local_258[0x2b];
  cVar39 = local_258[0x2c];
  cVar40 = local_258[0x2d];
  cVar41 = local_258[0x2e];
LAB_1800110e4:
  pcVar27 = local_458;
LAB_1800110f0:
  uVar26 = local_258._8_8_;
  if (local_450 == 0) {
    local_258[1] = cVar14;
    local_258[0] = cVar13;
    local_258[2] = cVar15;
    local_258[3] = cVar16;
    local_258[4] = cVar31;
    local_258[5] = cVar32;
    local_258[6] = cVar33;
    local_258[7] = cVar34;
    local_258[9] = cVar36;
    local_258[8] = cVar35;
    local_258[10] = cVar37;
    local_258[0xb] = cVar38;
    local_258[0xc] = cVar39;
    local_258[0xd] = cVar40;
    local_258[0xf] = SUB81(uVar26,7);
    local_258[0xe] = cVar41;
    local_258[0x10] = local_268;
    local_258[0x11] = uStack_267;
    local_258[0x12] = uStack_266;
    local_258[0x13] = uStack_265;
    local_258[0x14] = uStack_264;
    local_258[0x15] = uStack_263;
    local_258[0x16] = uStack_262;
    local_258[0x17] = uStack_261;
    local_258[0x18] = uStack_260;
    local_258[0x19] = uStack_25f;
    local_258[0x1a] = uStack_25e;
    local_258[0x1b] = uStack_25d;
    local_258[0x1c] = uStack_25c;
    local_258[0x1d] = uStack_25b;
    local_258[0x1e] = uStack_25a;
  }
  local_450 = local_450 + 1;
  uVar20 = (ulonglong)local_450;
  uVar26 = 0;
  CrashdmpWriteErrorLog(uVar20,0xc00400a3,0,0,(void *)0x0,0);
  if ((5 < DAT_18001b048) && (uVar20 = _tlgKeywordOn(uVar20,0x400000000000), (char)uVar20 != '\0'))
  {
    local_2a8 = &local_458;
    local_458 = (char *)0x1000000;
    pcVar21 = local_258 + 0x20;
    local_2a0 = 8;
    pcVar24 = "Unknown";
    if (!bVar2) {
      pcVar21 = "Unknown";
    }
    _tlgCreate1Sz_char(local_298,pcVar21);
    pcVar21 = &local_268;
    if (!bVar3) {
      pcVar21 = pcVar24;
    }
    _tlgCreate1Sz_char(local_288,pcVar21);
    _tlgWriteTransfer_EtwWriteTransfer
              (local_2c8,&DAT_1800190af,pcVar24,uVar26,5,(undefined8 *)local_2c8);
  }
  uVar20 = local_428;
LAB_18001122c:
  memset(local_258 + 0x30,0,0x80);
  sVar23 = 0x7f;
  if (uVar20 < 0x7f) {
    sVar23 = uVar20;
  }
  memcpy(local_258 + 0x30,pcVar18,sVar23);
  pcVar18 = pcVar27 + 2;
  pcVar27 = pcVar18;
LAB_18001126d:
  uVar20 = (ulonglong)(uint)piVar5[5];
  local_458 = pcVar27;
  if (pcVar11 + ((ulonglong)(uint)piVar5[5] - 1) <= pcVar18) goto LAB_180011287;
  goto LAB_180010c31;
LAB_180011287:
  uVar19 = local_464;
  cVar14 = local_467[0];
  cVar13 = local_468;
  if (local_468 == '\0') {
    uVar29 = local_460;
LAB_180011372:
    CrashdmpWriteErrorLog(uVar20,0xc00400a1,0xc01a0004,0,(void *)0x0,0);
    cVar14 = local_467[0];
  }
  else {
    if (local_467[0] == '\x01') {
      CrashdmpWriteErrorLog(uVar20,0x400a2,0,local_44c,(void *)0x0,0);
LAB_1800112c1:
      uVar19 = local_464;
    }
    else {
      if (DAT_18001c589 != '\0') goto LAB_1800112c1;
      DAT_18001c589 = '\x01';
      CrashdmpWriteErrorLog(uVar20,0xc00400a1,local_464,0,(void *)0x0,0);
    }
    uVar29 = local_460;
  }
  puVar25 = &local_3c0;
  local_3a0 = 0x80;
  local_3c0 = 0;
  uStack_3b8 = 0;
  local_3b0 = 0;
  uStack_3a8 = 0;
  lVar30 = local_448;
  ZwSetInformationFile(local_448,&local_440,puVar25,0x28);
  if (DAT_18001c58a == '\0') {
    if ((DAT_18001bd60 >> 0x1a & 1) == 0) {
      uVar26 = 0;
      if ((DAT_18001bd60 >> 0x1b & 1) != 0) {
        uVar26 = 2;
      }
    }
    else {
      uVar26 = CONCAT71((int7)((ulonglong)puVar25 >> 8),1);
    }
    DAT_18001c58a = '\x01';
    if ((5 < DAT_18001b048) && (uVar20 = _tlgKeywordOn(lVar30,0x800000000000), (char)uVar20 != '\0')
       ) {
      local_378 = &local_428;
      local_368 = local_467;
      local_428 = 0x1000000;
      local_358 = &local_468;
      local_370 = 8;
      local_348 = &local_460;
      local_464 = local_44c;
      local_338 = &local_464;
      local_328 = &local_458;
      local_360 = 1;
      local_350 = 1;
      local_340 = 4;
      local_330 = 4;
      local_458 = (char *)CONCAT44(local_458._4_4_,uVar29);
      local_320 = 4;
      lVar30 = -1;
      do {
        lVar12 = lVar30 + 1;
        lVar4 = lVar30 + 0x31;
        lVar30 = lVar12;
      } while (local_258[lVar4] != '\0');
      uVar20 = (ulonglong)local_450;
      local_318 = local_258 + 0x30;
      local_310 = (int)lVar12 + 1;
      pcVar27 = "";
      local_308 = &local_450;
      local_30c = 0;
      pcVar18 = local_258;
      if (local_450 == 0) {
        pcVar18 = "";
      }
      local_300 = 4;
      local_468 = cVar13;
      local_467[0] = cVar14;
      local_460 = uVar19;
      _tlgCreate1Sz_char(local_2f8,pcVar18);
      plVar17 = local_2e8;
      pcVar18 = local_258 + 0x10;
      if ((int)uVar20 == 0) {
        pcVar18 = pcVar27;
      }
      _tlgCreate1Sz_char(plVar17,pcVar18);
      local_2d8 = local_45c;
      local_45c[0] = (undefined1)uVar26;
      local_2d0 = 1;
      _tlgWriteTransfer_EtwWriteTransfer(plVar17,&DAT_180019144,uVar26,uVar20,0xd,local_398);
    }
  }
  param_1 = local_430;
  goto LAB_180011535;
}



===== ClearDumpFileHeader @ 180011608 =====

ulonglong ClearDumpFileHeader(longlong param_1,undefined8 param_2)

{
  undefined8 uVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined8 local_res18;
  undefined8 local_res20;
  ulonglong local_48 [6];
  
  local_res20 = 0;
  local_res18 = 0;
  local_48[4] = 0;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  uVar3 = ObReferenceObjectByHandle
                    (param_2,0,*(undefined8 *)IoFileObjectType_exref,0,&local_res18,0);
  uVar1 = local_res18;
  if (-1 < (int)uVar3) {
    lVar4 = IoAllocateMdl(*(undefined8 *)(param_1 + 0x638),0x1000,0,0,0);
    if (lVar4 == 0) {
      uVar3 = 0xc000009a;
    }
    else {
      MmBuildMdlForNonPagedPool(lVar4);
      memset(*(void **)(param_1 + 0x638),0,0x1000);
      KeInitializeEvent(local_48 + 2,0,0);
      uVar2 = IoSynchronousPageWrite(uVar1,lVar4,&local_res20,local_48 + 2,local_48);
      uVar3 = (ulonglong)uVar2;
      if (uVar2 == 0x103) {
        KeWaitForSingleObject(local_48 + 2,0,0,0,0);
        uVar3 = local_48[0] & 0xffffffff;
      }
    }
    ObfDereferenceObject(uVar1);
    if (lVar4 != 0) {
      IoFreeMdl(lVar4);
    }
  }
  return uVar3;
}



===== CrashdmpDisplayString @ 18001176c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CrashdmpDisplayString
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res10;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined1 auStack_c8 [48];
  char local_98 [127];
  undefined1 local_19;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_c8;
  local_res10 = param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  RtlStringCchVPrintfA(local_98,0x80,param_1,(va_list)&local_res10);
  local_19 = 0;
  RtlStringCchCatA(local_98);
  return;
}



===== CrashdmpLoadDriver @ 1800117e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int CrashdmpLoadDriver(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4,
                      short *param_5,longlong *param_6)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  wchar_t *pwVar5;
  wchar_t *pwVar6;
  undefined8 *puVar7;
  undefined1 auStackY_248 [32];
  undefined8 local_200;
  undefined8 uStack_1f8;
  undefined8 local_1f0;
  undefined8 uStack_1e8;
  undefined8 local_1e0;
  undefined8 uStack_1d8;
  undefined8 local_1d0 [4];
  wchar_t *local_1b0;
  uint local_1a8;
  undefined4 local_1a4;
  wchar_t local_198 [80];
  wchar_t local_f8 [80];
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_248;
  local_1f0 = 0;
  uStack_1e8 = 0;
  puVar7 = (undefined8 *)0x0;
  local_200 = 0;
  uStack_1f8 = 0;
  local_1e0 = 0;
  uStack_1d8 = 0;
  lVar2 = ExAllocatePool2(0x40,0x30,0x706d4443);
  if (lVar2 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    if ((param_4 == (undefined8 *)0x0) || (param_4[1] == 0)) {
      RtlStringCchPrintfW(local_198,0x50,L"\\SystemRoot\\System32\\Drivers\\%s",param_3);
      RtlInitUnicodeString(&local_1f0,local_198);
    }
    else {
      local_1f0 = *param_4;
      uStack_1e8 = param_4[1];
    }
    RtlInitUnicodeString(&local_1e0,param_2);
    RtlInitUnicodeString(&local_200,0);
    if ((param_5 != (short *)0x0) && (*param_5 != 0)) {
      RtlStringCchPrintfW(local_f8,0x50,L"%s%s",param_2);
      RtlInitUnicodeString(&local_200,local_f8);
      puVar7 = &local_200;
    }
    iVar1 = (**(code **)(param_1 + 0x10))(&local_1f0,&local_1e0,puVar7,2);
    if (((iVar1 + 0x80000000U & 0x80000000) == 0) && (iVar1 != -0x3ffffef2)) {
      ExFreePoolWithTag(lVar2,0);
    }
    else {
      lVar3 = RtlImageNtHeader(*(longlong *)(lVar2 + 0x18));
      if (lVar3 == 0) {
        ExFreePoolWithTag(lVar2,0);
        iVar1 = -0x3fffffff;
      }
      else {
        *(undefined4 *)(lVar2 + 0x20) = *(undefined4 *)(lVar3 + 0x50);
        *(ulonglong *)(lVar2 + 0x28) =
             (ulonglong)*(uint *)(lVar3 + 0x28) + *(longlong *)(lVar2 + 0x18);
        *param_6 = lVar2;
        iVar1 = 0;
      }
      pwVar6 = L"%s";
      pwVar5 = local_198;
      RtlStringCchPrintfW(pwVar5,0x50,L"%s",param_3);
      if ((5 < DAT_18001b048) && (uVar4 = _tlgKeywordOn(pwVar5,0x400000000000), (char)uVar4 != '\0')
         ) {
        lVar2 = -1;
        do {
          lVar2 = lVar2 + 1;
        } while (local_198[lVar2] != L'\0');
        local_1b0 = local_198;
        local_1a4 = 0;
        local_1a8 = (int)lVar2 * 2 + 2;
        _tlgWriteTransfer_EtwWriteTransfer
                  ((ulonglong)local_1a8,&DAT_18001910e,pwVar6,param_3,3,local_1d0);
      }
    }
  }
  return iVar1;
}



===== CrashdmpWriteErrorLog @ 180011a64 =====

void CrashdmpWriteErrorLog
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               void *param_5,byte param_6)

{
  void *_Dst;
  byte bVar1;
  
  bVar1 = param_6 + 0x30;
  if (param_6 == 0) {
    bVar1 = 0x30;
  }
  if (DAT_18001c530 != 0) {
    _Dst = (void *)IoAllocateErrorLogEntry();
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,(ulonglong)bVar1);
      *(undefined4 *)((longlong)_Dst + 0xc) = param_2;
      *(undefined4 *)((longlong)_Dst + 0x14) = param_3;
      *(undefined4 *)((longlong)_Dst + 0x10) = param_4;
      if (param_5 != (void *)0x0) {
        *(undefined4 *)((longlong)_Dst + 4) = 0x300001;
        memcpy((void *)((longlong)_Dst + 0x30),param_5,(ulonglong)param_6);
      }
      IoWriteErrorLogEntry(_Dst);
    }
  }
  return;
}



===== CreateDumpFile @ 180011b2c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int CreateDumpFile(longlong param_1)

{
  int iVar1;
  ulonglong uVar2;
  undefined1 auStack_1b8 [32];
  undefined8 *local_198;
  undefined4 local_190;
  undefined4 local_188;
  undefined4 local_180;
  undefined4 local_178;
  undefined8 local_170;
  undefined4 local_168;
  undefined4 local_160;
  undefined8 local_158;
  undefined4 local_150;
  longlong local_148;
  undefined8 local_140;
  longlong local_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 *local_110;
  undefined8 uStack_108;
  undefined8 *local_100;
  ulonglong local_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  wchar_t local_b8 [80];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_1b8;
  local_140 = 0;
  local_148 = 0;
  local_138 = 0;
  local_100 = (undefined8 *)0x0;
  local_120 = 0;
  uStack_118 = 0;
  local_f8 = local_f8 & 0xffffffff00000000;
  local_110 = (undefined8 *)0x0;
  uStack_108 = 0;
  local_c0 = 0;
  local_130 = 0;
  uStack_128 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  RtlStringCchPrintfW(local_b8,0x50,L"\\??\\%s",*(undefined8 *)(param_1 + 0x30));
  RtlInitUnicodeString(&local_f0,local_b8);
  iVar1 = CreateSecurityDescriptor(&local_e0,&local_138);
  if (-1 < iVar1) {
    uStack_118 = 0;
    local_110 = &local_f0;
    local_f8 = 0;
    local_150 = 0x102;
    local_158 = 0;
    local_160 = 0;
    local_168 = 0;
    local_170 = 0;
    local_178 = 0x900a;
    local_180 = 0;
    local_188 = 0;
    local_100 = &local_e0;
    local_190 = 6;
    local_120 = CONCAT44(local_120._4_4_,0x30);
    uStack_108 = CONCAT44(uStack_108._4_4_,0x240);
    local_198 = (undefined8 *)(param_1 + 0x10);
    iVar1 = IoCreateFile(&local_148,0x150003,&local_120,&local_130);
    if ((-1 < iVar1) && (iVar1 = ZwSetSecurityObject(local_148,4,&local_e0), -1 < iVar1)) {
      local_140 = *(undefined8 *)(param_1 + 0x10);
      local_198 = (undefined8 *)CONCAT44(local_198._4_4_,0x14);
      iVar1 = ZwSetInformationFile(local_148,&local_130,&local_140,8);
      if (iVar1 < 0) {
        if ((int)local_130 < 0) goto LAB_180011cea;
      }
      else {
        if ((int)local_130 < 0) {
LAB_180011cea:
          iVar1 = (int)local_130;
        }
        else {
          uVar2 = ClearDumpFileHeader(param_1,local_148);
          *(longlong *)(param_1 + 8) = local_148;
          iVar1 = 0;
          if (-1 < (int)uVar2) {
            iVar1 = (int)uVar2;
          }
        }
        if (-1 < iVar1) goto LAB_180011d0d;
      }
    }
  }
  if (local_148 != 0) {
    ZwClose();
  }
LAB_180011d0d:
  if (local_138 != 0) {
    ExFreePoolWithTag(local_138,0);
  }
  return iVar1;
}



===== CreateLogFile @ 180011d58 =====

int CreateLogFile(longlong param_1,undefined8 param_2,ulonglong param_3)

{
  undefined8 *puVar1;
  int iVar2;
  ulonglong local_res20;
  undefined4 uVar4;
  ulonglong *puVar3;
  longlong local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 *local_60;
  undefined8 uStack_58;
  undefined8 *local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  
  local_res20 = 0;
  local_88 = 0;
  local_10 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = (undefined8 *)0x0;
  uStack_58 = 0;
  local_50 = (undefined8 *)0x0;
  uStack_48 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  RtlInitUnicodeString(&local_40);
  iVar2 = CreateSecurityDescriptor(&local_30,&local_88);
  if (-1 < iVar2) {
    uStack_68 = 0;
    local_60 = &local_40;
    uStack_48 = 0;
    local_50 = &local_30;
    puVar1 = (undefined8 *)(param_1 + 0x2c8);
    puVar3 = &local_res20;
    local_70 = CONCAT44(local_70._4_4_,0x30);
    uStack_58 = CONCAT44(uStack_58._4_4_,0x240);
    local_res20 = param_3 & 0xffffffff;
    iVar2 = IoCreateFile(puVar1,0x150003,&local_70,&local_80,puVar3,6,0,0,0x802a,0,0,0,0,0x102);
    uVar4 = (undefined4)((ulonglong)puVar3 >> 0x20);
    if (-1 < iVar2) {
      iVar2 = ZwSetSecurityObject(*puVar1,4,&local_30);
      if (-1 < iVar2) {
        iVar2 = ZwSetInformationFile(*puVar1,&local_80,&local_res20,8,CONCAT44(uVar4,0x14));
        if ((-1 < iVar2) && (-1 < (int)local_80)) goto LAB_180011ef0;
        if ((int)local_80 < 0) {
          iVar2 = (int)local_80;
        }
        if (-1 < iVar2) goto LAB_180011ef0;
      }
    }
  }
  if (*(longlong *)(param_1 + 0x2c8) != 0) {
    ZwClose();
    *(undefined8 *)(param_1 + 0x2c8) = 0;
    ZwDeleteFile(&local_70);
  }
LAB_180011ef0:
  if (local_88 != 0) {
    ExFreePoolWithTag(local_88,0);
  }
  return iVar2;
}



===== CreateSecurityDescriptor @ 180011f2c =====

int CreateSecurityDescriptor(undefined8 param_1,longlong *param_2)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = 0;
  iVar1 = RtlCreateSecurityDescriptor(param_1,1);
  if (-1 < iVar1) {
    iVar1 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x110));
    iVar2 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x108));
    iVar1 = iVar1 + iVar2 + 0x20;
    lVar3 = ExAllocatePool2(0x100,iVar1,0x6c636144);
    if (lVar3 == 0) {
      iVar1 = -0x3fffff66;
    }
    else {
      iVar1 = RtlCreateAcl(lVar3,iVar1,2);
      if (-1 < iVar1) {
        iVar1 = RtlAddAccessAllowedAce
                          (lVar3,2,0x1f01ff,*(undefined8 *)(*(longlong *)SeExports_exref + 0x110));
        if (-1 < iVar1) {
          iVar1 = RtlAddAccessAllowedAce
                            (lVar3,2,0x1f01ff,*(undefined8 *)(*(longlong *)SeExports_exref + 0x108))
          ;
          if (-1 < iVar1) {
            iVar1 = RtlSetDaclSecurityDescriptor(param_1,1,lVar3,0);
            if (-1 < iVar1) goto LAB_18001207d;
          }
        }
      }
      ExFreePoolWithTag(lVar3,0);
      lVar3 = 0;
    }
  }
LAB_18001207d:
  *param_2 = lVar3;
  return iVar1;
}



===== DuplicateString @ 1800120a0 =====

undefined8 DuplicateString(void *param_1,undefined8 *param_2)

{
  longlong lVar1;
  void *_Dst;
  undefined8 uVar2;
  
  lVar1 = -1;
  do {
    lVar1 = lVar1 + 1;
  } while (*(short *)((longlong)param_1 + lVar1 * 2) != 0);
  _Dst = (void *)ExAllocatePool2(0x40,lVar1 * 2 + 2,0x706d4443);
  *param_2 = _Dst;
  if (_Dst == (void *)0x0) {
    uVar2 = 0xc0000017;
  }
  else {
    memcpy(_Dst,param_1,lVar1 * 2);
    uVar2 = 0;
  }
  return uVar2;
}



===== Feature_TriageDumpDataExtension__private_IsEnabledWithReporting @ 180012124 =====

void Feature_TriageDumpDataExtension__private_IsEnabledWithReporting(void)

{
  Feature_TriageDumpDataExtension__private_IsEnabledNoReportingNoInline();
  return;
}



===== FindNextSetBitRange64 @ 18001213c =====

undefined1
FindNextSetBitRange64(undefined8 *param_1,ulonglong param_2,ulonglong *param_3,ulonglong *param_4)

{
  ulonglong uVar1;
  char cVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined1 uVar6;
  longlong local_28 [2];
  
  uVar6 = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  RtlInitializeBitMapEx(local_28,param_1[1],*param_1);
  uVar3 = RtlFindSetBitsEx(local_28,1,param_2);
  if ((uVar3 != 0xffffffffffffffff) && (param_2 <= uVar3)) {
    if (param_4 != (ulonglong *)0x0) {
      uVar4 = 1;
      uVar5 = 1;
      if (1 < local_28[0] - uVar3) {
        do {
          cVar2 = RtlAreBitsSetEx(local_28,uVar4 + uVar3,uVar4);
          uVar5 = uVar4;
          if (cVar2 == '\0') break;
          uVar5 = uVar4 * 2;
          uVar1 = uVar4 * 4;
          uVar4 = uVar5;
        } while (uVar1 <= local_28[0] - uVar3);
      }
      if (uVar5 < local_28[0] - uVar3) {
        do {
          cVar2 = RtlAreBitsSetEx(local_28,uVar5 + uVar3,1);
          if (cVar2 == '\0') break;
          uVar5 = uVar5 + 1;
        } while (uVar5 < local_28[0] - uVar3);
      }
      *param_4 = uVar5;
    }
    *param_3 = uVar3;
    uVar6 = 1;
  }
  return uVar6;
}



===== GetBootDeviceObject @ 180012258 =====

void GetBootDeviceObject(undefined8 param_1)

{
  int iVar1;
  undefined8 local_res8;
  longlong local_res10 [3];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_1c = 0;
  local_res8 = 0;
  local_30 = 0;
  local_38 = 0x30;
  local_48 = 0;
  uStack_40 = 0;
  local_20 = 0x200;
  local_18 = 0;
  uStack_10 = 0;
  local_28 = param_1;
  iVar1 = ZwOpenFile(&local_res8,0x100180,&local_38,&local_48,3,0x40);
  if (-1 < iVar1) {
    local_res10[0] = 0;
    ObReferenceObjectByHandle(local_res8,0,*(undefined8 *)IoFileObjectType_exref,0,local_res10,0);
    DAT_18001c530 = *(undefined8 *)(local_res10[0] + 8);
    ObfDereferenceObject();
    ZwClose(local_res8);
  }
  return;
}



===== GetDedicatedDumpFileSize @ 180012330 =====

undefined4 GetDedicatedDumpFileSize(undefined8 param_1)

{
  undefined4 local_res10 [2];
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res10[0] = 0;
  local_res18[0] = 0;
  local_res20[0] = 4;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,param_1);
  ZwQueryLicenseValue(&local_18,local_res20,local_res10,4,local_res18);
  return local_res10[0];
}



===== GetDumpFileSize @ 18001239c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 GetDumpFileSize(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_158 [32];
  undefined4 local_138;
  undefined4 local_130;
  longlong local_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined4 local_100;
  undefined4 local_fc;
  undefined8 local_f8;
  undefined8 *local_f0;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  wchar_t local_b8 [80];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_158;
  local_e4 = 0;
  local_128 = 0;
  uVar2 = 0;
  local_fc = 0;
  local_120 = 0;
  uStack_118 = 0;
  local_c0 = 0;
  local_110 = 0;
  uStack_108 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  RtlStringCchPrintfW(local_b8,0x50,L"\\??\\%s",*(undefined8 *)(param_1 + 0x30));
  RtlInitUnicodeString(&local_110,local_b8);
  local_f8 = 0;
  local_f0 = &local_110;
  local_130 = 0x28;
  local_100 = 0x30;
  local_e8 = 0x240;
  local_138 = 3;
  local_e0 = 0;
  uStack_d8 = 0;
  iVar1 = ZwOpenFile(&local_128,0xc0150000,&local_100,&local_120);
  if ((-1 < iVar1) && (-1 < (int)local_120)) {
    local_138 = 5;
    iVar1 = ZwQueryInformationFile(local_128,&local_120,&local_d0,0x18);
    if ((-1 < iVar1) && (-1 < (int)local_120)) {
      uVar2 = uStack_c8;
    }
  }
  if (local_128 != 0) {
    ZwClose();
  }
  return uVar2;
}



===== GetPortDriverObject @ 1800124e8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 GetPortDriverObject(uint param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_f8 [32];
  longlong *local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  longlong local_c0 [3];
  undefined4 local_a8;
  undefined4 local_a4;
  undefined8 local_a0;
  longlong *local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  wchar_t local_68 [40];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_f8;
  uVar2 = 0;
  local_a4 = 0;
  local_8c = 0;
  local_c8 = 0;
  local_c0[1] = 0;
  local_c0[2] = 0;
  local_78 = 0;
  uStack_70 = 0;
  RtlStringCchPrintfW(local_68,0x28,L"\\Device\\ScsiPort%d",(ulonglong)param_1);
  RtlInitUnicodeString(local_c0 + 1,local_68);
  local_98 = local_c0 + 1;
  local_d0 = CONCAT44(local_d0._4_4_,0x40);
  local_a8 = 0x30;
  local_a0 = 0;
  local_90 = 0x200;
  local_d8 = (longlong *)CONCAT44(local_d8._4_4_,3);
  local_88 = 0;
  uStack_80 = 0;
  iVar1 = ZwOpenFile(&local_c8,0x80,&local_a8,&local_78);
  if (iVar1 < 0) {
    uVar2 = 0;
  }
  else {
    local_d0 = 0;
    local_c0[0] = 0;
    local_d8 = local_c0;
    iVar1 = ObReferenceObjectByHandle(local_c8,0,*(undefined8 *)IoFileObjectType_exref,0);
    if (-1 < iVar1) {
      uVar2 = *(undefined8 *)(*(longlong *)(local_c0[0] + 8) + 8);
      ObfDereferenceObject();
    }
    ZwClose(local_c8);
  }
  return uVar2;
}



===== IsBufferValid @ 180012628 =====

undefined1 IsBufferValid(ulonglong param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  undefined1 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  uVar4 = (ulonglong)param_2;
  iVar2 = Feature_TriageDumpDataExtension__private_IsEnabledWithReporting();
  uVar3 = 1;
  if (iVar2 == 0) {
    do {
      iVar2 = (int)uVar4;
      uVar4 = (ulonglong)(iVar2 - 1);
      if (iVar2 == 0) {
        return 1;
      }
      cVar1 = MmIsAddressValid(param_1);
      param_1 = param_1 + 1;
    } while (cVar1 != '\0');
    uVar3 = 0;
  }
  else {
    uVar5 = param_1 & 0xfffffffffffff000;
    for (uVar4 = (ulonglong)((uint)param_1 & 0xfff) + 0xfff + uVar4 >> 0xc; uVar4 != 0;
        uVar4 = uVar4 - 1) {
      if ((uVar5 < 0x10000) || (cVar1 = MmIsAddressValid(uVar5), cVar1 == '\0')) {
        return 0;
      }
      uVar5 = uVar5 + 0x1000;
    }
  }
  return uVar3;
}



===== IsDedicatedDumpFileStorageReserveEnabled @ 1800126dc =====

bool IsDedicatedDumpFileStorageReserveEnabled(void)

{
  int local_res8 [2];
  undefined4 local_res10 [2];
  undefined4 local_res18 [4];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res18[0] = 4;
  local_res8[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  local_res10[0] = 0;
  RtlInitUnicodeString(&local_18,L"Crashdmp-DedicatedDumpFileStorageReserve-Enabled");
  ZwQueryLicenseValue(&local_18,local_res18,local_res8,4,local_res10);
  return local_res8[0] == 1;
}



===== IsStorageHardReserveCreated @ 180012758 =====

bool IsStorageHardReserveCreated(undefined8 param_1,longlong *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  longlong local_res8;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_res8 = 0;
  local_3c = 0;
  local_58 = 0x30;
  puVar2 = (undefined4 *)0x0;
  local_40 = 0x200;
  lVar3 = 0;
  local_50 = 0;
  bVar6 = false;
  local_68 = 0;
  uStack_60 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_48 = param_1;
  iVar1 = ZwOpenFile(&local_res8,0x100180,&local_58,&local_68,3,0x40);
  if (-1 < iVar1) {
    puVar2 = (undefined4 *)ExAllocatePool2(0x40,0x14,0x706d4443);
    if (puVar2 != (undefined4 *)0x0) {
      puVar2[1] = 0;
      *puVar2 = 1;
      puVar2[2] = 0x10;
      puVar2[3] = 1;
      puVar2[4] = 1;
      lVar3 = ExAllocatePool2(0x40,0x20,0x706d4443);
      uVar4 = 0x20;
      if (lVar3 != 0) {
        while( true ) {
          iVar1 = NtFsControlFile(local_res8,0,0,0,&local_68,0x90414,puVar2,0x14,lVar3,uVar4);
          if (iVar1 != -0x7ffffffb) break;
          uVar5 = 1;
          if (1 < *(uint *)(lVar3 + 4)) {
            uVar5 = *(uint *)(lVar3 + 4);
          }
          uVar5 = uVar5 * 0x18 + 8;
          if (uVar5 <= uVar4) goto LAB_180012901;
          ExFreePoolWithTag(lVar3,0);
          lVar3 = ExAllocatePool2(0x40);
          if (lVar3 == 0) goto LAB_180012901;
          uVar4 = uVar5;
        }
        if (-1 < iVar1) {
          bVar6 = *(int *)(lVar3 + 8) == 1;
          *param_2 = *(longlong *)(lVar3 + 0x10) - *(longlong *)(lVar3 + 0x18);
        }
      }
    }
  }
LAB_180012901:
  if (local_res8 != 0) {
    ZwClose();
  }
  if (puVar2 != (undefined4 *)0x0) {
    ExFreePoolWithTag(puVar2,0);
  }
  if (lVar3 != 0) {
    ExFreePoolWithTag(lVar3,0);
  }
  return bVar6;
}



===== IsVolumeSupported @ 180012968 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint IsVolumeSupported(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  undefined1 auStackY_88 [32];
  undefined4 local_48 [4];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48[0] = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  uVar1 = SendDeviceControl(0x560000,param_1,0,0,&local_38,0x20,local_48);
  if ((((-1 < (int)uVar1) || (uVar1 == 0x80000005)) || (uVar1 == 0xc0000023)) &&
     (1 < (uint)local_38)) {
    uVar1 = ~-(uint)((*(uint *)(*(longlong *)(param_2 + 8) + 0x30) & 0x100) != 0) & 0xc00000bb;
  }
  return uVar1;
}



===== ReadRegString @ 180012a10 =====

void ReadRegString(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 local_78 [8];
  undefined4 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined4 local_58;
  
  memset(local_78,0,0x70);
  local_70 = 0x134;
  local_58 = 0x1000000;
  local_68 = param_2;
  local_60 = param_3;
  RtlQueryRegistryValuesEx(0,param_1,local_78,0,0);
  return;
}



===== ReadRegULongKey @ 180012a90 =====

void ReadRegULongKey(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  undefined1 local_78 [8];
  undefined4 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined4 local_58;
  undefined4 *local_50;
  undefined4 local_48;
  
  memset(local_78,0,0x70);
  local_50 = local_res20;
  local_70 = 0x124;
  local_58 = 0x4000004;
  local_48 = 4;
  local_res20[0] = param_4;
  local_68 = param_2;
  local_60 = param_3;
  RtlQueryRegistryValuesEx(0x80000000,param_1,local_78,0,0);
  return;
}



===== RtlStringCchCatA @ 180012b3c =====

uint RtlStringCchCatA(char *param_1)

{
  uint uVar1;
  char *pcVar2;
  longlong lVar3;
  char *pcVar4;
  longlong lVar5;
  longlong lVar6;
  ulonglong uVar7;
  
  lVar5 = 0x80;
  pcVar2 = param_1;
  do {
    if (*pcVar2 == '\0') break;
    pcVar2 = pcVar2 + 1;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  uVar7 = -(ulonglong)(lVar5 != 0) & 0x80U - lVar5;
  uVar1 = ~-(uint)(lVar5 != 0) & 0xc000000d;
  if (lVar5 != 0) {
    pcVar2 = param_1 + uVar7;
    lVar5 = 0x80 - uVar7;
    if (lVar5 != 0) {
      lVar3 = 0x7ffffffe;
      lVar6 = (longlong)"\n" - (longlong)pcVar2;
      do {
        if ((lVar3 == 0) || (pcVar2[lVar6] == '\0')) break;
        *pcVar2 = pcVar2[lVar6];
        lVar3 = lVar3 + -1;
        pcVar2 = pcVar2 + 1;
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
    }
    pcVar4 = pcVar2 + -1;
    if (lVar5 != 0) {
      pcVar4 = pcVar2;
    }
    *pcVar4 = '\0';
    uVar1 = ~-(uint)(lVar5 != 0) & 0x80000005;
  }
  return uVar1;
}



===== RtlUnicodeStringCopyStringEx @ 180012bd8 =====

int RtlUnicodeStringCopyStringEx(ushort *param_1,short *param_2)

{
  ushort uVar1;
  ushort uVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
  int iVar7;
  longlong lVar8;
  longlong lVar9;
  
  uVar1 = *param_1;
  if ((((((uVar1 & 1) == 0) && (uVar2 = param_1[1], (uVar2 & 1) == 0)) && (uVar1 <= uVar2)) &&
      (uVar2 != 0xffff)) && ((*(longlong *)(param_1 + 4) != 0 || ((uVar1 == 0 && (uVar2 == 0)))))) {
    lVar8 = 0;
    uVar4 = (ulonglong)(param_1[1] >> 1);
    iVar7 = 0;
    lVar3 = *(longlong *)(param_1 + 4);
    if (uVar4 == 0) {
      if (*param_2 != 0) {
        iVar7 = (-(uint)(lVar3 != 0) & 0xbffffff8) + 0xc000000d;
      }
    }
    else {
      lVar6 = 0x7fff;
      lVar9 = lVar3 - (longlong)param_2;
      uVar5 = uVar4;
      do {
        if (lVar6 == 0) goto LAB_180012cad;
        if (*param_2 == 0) break;
        *(short *)(lVar9 + (longlong)param_2) = *param_2;
        lVar6 = lVar6 + -1;
        param_2 = param_2 + 1;
        lVar8 = lVar8 + 1;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
      if (((uVar5 == 0) && (lVar6 != 0)) && (iVar7 = 0, *param_2 != 0)) {
        iVar7 = -0x7ffffffb;
      }
LAB_180012cad:
      if ((-1 < iVar7) && (uVar4 - lVar8 != 0)) {
        memset((void *)(lVar3 + lVar8 * 2),0,(uVar4 - lVar8) * 2);
      }
    }
    *param_1 = (short)lVar8 * 2;
  }
  else {
    iVar7 = -0x3ffffff3;
  }
  return iVar7;
}



===== SendDeviceControl @ 180012cf4 =====

int SendDeviceControl(undefined4 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                     undefined8 param_5,undefined4 param_6,undefined4 *param_7)

{
  int iVar1;
  longlong lVar2;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  iVar1 = -0x3fffff66;
  local_38 = 0;
  uStack_30 = 0;
  KeInitializeEvent(&local_28,0,0);
  lVar2 = IoBuildDeviceIoControlRequest
                    (param_1,param_2,param_3,param_4,param_5,param_6,0,&local_28,&local_38);
  if (lVar2 != 0) {
    iVar1 = IofCallDriver(param_2,lVar2);
    if (iVar1 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
      iVar1 = (int)local_38;
    }
    *param_7 = (undefined4)uStack_30;
  }
  return iVar1;
}



===== SendFreeDumpPointers @ 180012e0c =====

void SendFreeDumpPointers(undefined8 param_1,undefined8 param_2,uint param_3)

{
  undefined4 local_res18 [4];
  
  local_res18[0] = 0;
  if (param_3 < 2) {
    param_3 = (-(uint)(param_3 != 0) & 0x30) + 0x38;
  }
  SendDeviceControl(0x41024,param_1,param_2,param_3,0,0,local_res18);
  return;
}



===== SetChangeState @ 180012e60 =====

undefined8 SetChangeState(char param_1,char param_2)

{
  undefined1 uVar1;
  undefined8 uVar2;
  bool bVar3;
  
  uVar2 = 0;
  uVar1 = KeAcquireSpinLockRaiseToDpc(&DAT_18001bcf8);
  if (param_2 == '\x01') {
    if (DAT_18001bcf5 == '\x01') {
      uVar2 = 0x80000011;
      goto LAB_180012ec3;
    }
    if (param_1 == '\x01') {
      bVar3 = DAT_18001bcf4 == '\x01';
    }
    else {
      bVar3 = DAT_18001bcf4 == '\0';
    }
    if (bVar3) {
      uVar2 = 0xc0000184;
      goto LAB_180012ec3;
    }
  }
  DAT_18001bcf5 = param_2;
LAB_180012ec3:
  KeReleaseSpinLock(&DAT_18001bcf8,uVar1);
  return uVar2;
}



===== SignalIrpCompletion @ 180012f00 =====

undefined8 SignalIrpCompletion(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== WriteLogElapsedDuration @ 180012f2c =====

void WriteLogElapsedDuration(void)

{
  longlong lVar1;
  undefined8 in_R9;
  
  if (((DAT_18001c598 != 0) && (DAT_18001c52b == '\x01')) &&
     (*(longlong *)(DAT_18001bd40 + 0x2c0) != 0)) {
    lVar1 = KeQueryPerformanceCounter(0);
    WriteLogString(DAT_18001bd40,"Elapsed BugCheck duration %08ums\r\n",
                   ((lVar1 - DAT_18001c590) * 1000) / DAT_18001c598,in_R9);
  }
  return;
}



===== WriteLogProgress @ 180012f9c =====

void WriteLogProgress(uint param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  if (((DAT_18001c52b == '\x01') && (*(longlong *)(DAT_18001bd40 + 0x2c0) != 0)) &&
     (*(int *)(DAT_18001bd40 + 0x298) != 0)) {
    WriteLogString(DAT_18001bd40,"Progress 0x%08X\r\n",(ulonglong)param_1,param_4);
  }
  return;
}



===== FreeMpioResources @ 180012fe4 =====

int FreeMpioResources(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined4 local_res8 [2];
  undefined1 auStackY_78 [8];
  undefined1 auStackY_70 [24];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_res8[0] = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if ((*(uint *)(param_1 + 0x20) & 0x100) == 0) {
    iVar5 = SendDeviceControl(0x6d70c050,*(undefined8 *)(param_1 + 0x6b0),&local_38,0x20,&local_38,
                              0x20,local_res8);
    KeWaitForSingleObject(param_1 + 0x670,0,0,0);
    puVar6 = auStackY_78;
    plVar1 = (longlong *)(param_1 + 0x660);
    while (plVar2 = (longlong *)*plVar1, plVar2 != plVar1) {
      if (((longlong *)plVar2[1] != plVar1) ||
         (lVar3 = *plVar2, (longlong *)*(longlong *)(lVar3 + 8) != plVar2)) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        puVar6 = auStackY_70;
        break;
      }
      *plVar1 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar1;
      if ((*(uint *)((longlong)plVar2 + 0x9c) & 2) != 0) {
        iVar5 = SendFreeDumpPointers(plVar2[2],plVar2 + 4,(uint)*(byte *)(plVar2 + 0x12));
      }
      ObfDereferenceObject(plVar2[2]);
      ExFreePoolWithTag(plVar2);
      *(int *)(param_1 + 0x658) = *(int *)(param_1 + 0x658) + -1;
    }
    *(undefined4 *)(param_1 + 0x658) = 0xffffffff;
    *(undefined8 *)(puVar6 + -8) = 0x180013100;
    KeReleaseMutex(param_1 + 0x670,0);
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffff7fff;
  }
  else {
    iVar5 = 0;
  }
  return iVar5;
}



===== GetMpioPathInfo @ 180013128 =====

int GetMpioPathInfo(longlong param_1)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined4 local_res8 [2];
  
  iVar3 = 0;
  local_res8[0] = 0;
  for (puVar4 = *(undefined8 **)(param_1 + 0x660); puVar4 != (undefined8 *)(param_1 + 0x660);
      puVar4 = (undefined8 *)*puVar4) {
    if ((*(uint *)((longlong)puVar4 + 0x9c) & 2) == 0) {
      iVar3 = SendDeviceControl(0x41018,puVar4[2],0,0,(longlong)puVar4 + 0x94,8,local_res8);
      if ((-1 < iVar3) && (*(longlong *)(param_1 + 0x6a8) == *(longlong *)(puVar4[2] + 8))) {
        *(undefined4 *)((longlong)puVar4 + 0x24) = 0x30;
        piVar1 = (int *)(puVar4 + 4);
        *piVar1 = 2;
        iVar3 = SendDeviceControl(0x41020,puVar4[2],piVar1,8,piVar1,0x68,local_res8);
        if (-1 < iVar3) {
          if ((*piVar1 - 2U < 3) && (*(int *)((longlong)puVar4 + 0x24) - 0x30U < 0x39)) {
            uVar2 = 1;
          }
          else {
            uVar2 = 0;
          }
          *(undefined1 *)(puVar4 + 0x12) = uVar2;
          *(uint *)((longlong)puVar4 + 0x9c) = *(uint *)((longlong)puVar4 + 0x9c) | 2;
        }
      }
    }
  }
  return iVar3;
}



===== InitMpioDevice @ 180013244 =====

undefined8 InitMpioDevice(longlong *param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  code *pcVar4;
  uint *puVar5;
  int iVar6;
  longlong lVar7;
  longlong *plVar8;
  undefined1 *puVar9;
  uint uVar10;
  ulonglong uVar11;
  uint local_res8 [2];
  undefined1 auStackY_78 [8];
  undefined1 auStackY_70 [24];
  undefined8 local_38;
  longlong local_30;
  uint *puStack_28;
  code *local_20;
  
  local_38 = 0;
  plVar1 = param_1 + 0xcc;
  local_res8[0] = 0;
  plVar2 = param_1 + 0xce;
  param_1[0xcd] = (longlong)plVar1;
  *plVar1 = (longlong)plVar1;
  local_30 = 0;
  puStack_28 = (uint *)0x0;
  KeInitializeMutex(plVar2,0);
  *(undefined4 *)(param_1 + 0xcb) = 0;
  local_20 = MpioPathChangeNotification;
  KeWaitForSingleObject(plVar2,0,0,0);
  iVar6 = SendDeviceControl(0x6d70c050,*(undefined8 *)(*param_1 + 0x278),&local_38,0x20,&local_38,
                            0x20,local_res8);
  puVar9 = auStackY_78;
  if ((iVar6 < 0) || (puVar9 = auStackY_78, local_res8[0] < 0x20)) {
LAB_1800133b7:
    *(undefined8 *)(puVar9 + -8) = 0x1800133c3;
    KeReleaseMutex(plVar2,0);
  }
  else {
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 4;
    lVar7 = GetPortDriverObject((uint)*(byte *)(*param_1 + 0x238));
    puVar5 = puStack_28;
    uVar11 = 0;
    param_1[0xd5] = lVar7;
    param_1[0xd6] = local_30;
    if (*puStack_28 != 0) {
      do {
        plVar8 = (longlong *)ExAllocatePool2(0x40,0xa0,0x706d4443);
        if (plVar8 != (longlong *)0x0) {
          plVar8[2] = *(longlong *)(puVar5 + uVar11 * 2 + 2);
          plVar3 = (longlong *)param_1[0xcd];
          if ((longlong *)*plVar3 != plVar1) {
            pcVar4 = (code *)swi(0x29);
            (*pcVar4)(3);
            puVar9 = auStackY_70;
            goto LAB_1800133b7;
          }
          *plVar8 = (longlong)plVar1;
          plVar8[1] = (longlong)plVar3;
          *plVar3 = (longlong)plVar8;
          param_1[0xcd] = (longlong)plVar8;
          *(int *)(param_1 + 0xcb) = (int)param_1[0xcb] + 1;
        }
        uVar10 = (int)uVar11 + 1;
        uVar11 = (ulonglong)uVar10;
      } while (uVar10 < *puVar5);
    }
    GetMpioPathInfo((longlong)param_1);
    KeReleaseMutex(plVar2,0);
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x8000;
  }
  return 0;
}



===== InitializeDumpPath @ 1800133e8 =====

int InitializeDumpPath(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  longlong *plVar4;
  
  lVar1 = *param_1;
  iVar3 = 0;
  if ((*(uint *)(param_1 + 4) & 8) == 0) {
    for (plVar4 = (longlong *)param_1[0xcc]; plVar4 != param_1 + 0xcc; plVar4 = (longlong *)*plVar4)
    {
      if ((*(uint *)((longlong)plVar4 + 0x9c) & 2) != 0) {
        if ((char)plVar4[0x12] == '\0') {
          *(undefined4 *)(lVar1 + 0x178) = 0;
          lVar2 = plVar4[5];
          *(longlong *)(lVar1 + 0x180) = plVar4[4];
          *(longlong *)(lVar1 + 0x188) = lVar2;
          lVar2 = plVar4[7];
          *(longlong *)(lVar1 + 400) = plVar4[6];
          *(longlong *)(lVar1 + 0x198) = lVar2;
          lVar2 = plVar4[9];
          *(longlong *)(lVar1 + 0x1a0) = plVar4[8];
          *(longlong *)(lVar1 + 0x1a8) = lVar2;
          *(longlong *)(lVar1 + 0x1b0) = plVar4[10];
          *(longlong *)(lVar1 + 0x50) = plVar4[4];
          *(longlong *)(lVar1 + 0x58) = plVar4[5];
          *(longlong *)(lVar1 + 0x60) = plVar4[6];
        }
        else {
          *(undefined4 *)(lVar1 + 0x178) = 1;
          lVar2 = plVar4[5];
          *(longlong *)(lVar1 + 0x180) = plVar4[4];
          *(longlong *)(lVar1 + 0x188) = lVar2;
          lVar2 = plVar4[7];
          *(longlong *)(lVar1 + 400) = plVar4[6];
          *(longlong *)(lVar1 + 0x198) = lVar2;
          lVar2 = plVar4[9];
          *(longlong *)(lVar1 + 0x1a0) = plVar4[8];
          *(longlong *)(lVar1 + 0x1a8) = lVar2;
          lVar2 = plVar4[0xb];
          *(longlong *)(lVar1 + 0x1b0) = plVar4[10];
          *(longlong *)(lVar1 + 0x1b8) = lVar2;
          lVar2 = plVar4[0xd];
          *(longlong *)(lVar1 + 0x1c0) = plVar4[0xc];
          *(longlong *)(lVar1 + 0x1c8) = lVar2;
          lVar2 = plVar4[0xf];
          *(longlong *)(lVar1 + 0x1d0) = plVar4[0xe];
          *(longlong *)(lVar1 + 0x1d8) = lVar2;
          *(longlong *)(lVar1 + 0x1e0) = plVar4[0x10];
          *(longlong *)(lVar1 + 0x60) = plVar4[5];
          if (2 < *(uint *)(lVar1 + 0x180)) {
            *(longlong *)(lVar1 + 0x50) = plVar4[0xc];
            *(longlong *)(lVar1 + 0x58) = plVar4[0xd];
          }
        }
        *(undefined8 *)(lVar1 + 0x234) = *(undefined8 *)((longlong)plVar4 + 0x94);
        *(undefined4 *)(lVar1 + 0x6c) = 0;
        *(undefined8 **)(lVar1 + 0x78) = (undefined8 *)(lVar1 + 0x234);
        iVar3 = InitializeDumpDriver(lVar1);
        if (-1 < iVar3) {
          *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 8;
          break;
        }
      }
    }
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}



===== MpioPathChangeNotification @ 180013560 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int MpioPathChangeNotification(undefined8 param_1,int *param_2,char param_3)

{
  code *pcVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  undefined8 local_18;
  
  iVar2 = 0;
  if ((DAT_18001bd60 & 0x8000) == 0) {
    return 0;
  }
  local_18 = 0;
  KeWaitForSingleObject(&DAT_18001c3b0,0,0,0);
  puVar7 = auStack_38;
  if (DAT_18001c398 != -1) {
    if (param_3 == '\0') {
      iVar2 = RemoveMpioPath(&DAT_18001c398,param_2,0);
      puVar6 = auStack_38;
    }
    else {
      puVar3 = (undefined8 *)ExAllocatePool2(0x40,0xa0,0x706d4443);
      puVar6 = auStack_38;
      puVar7 = auStack_38;
      if (puVar3 == (undefined8 *)0x0) goto LAB_18001362e;
      puVar3[2] = param_2;
      puVar5 = &DAT_18001c3a0;
      puVar4 = DAT_18001c3a8;
      if ((undefined *)*DAT_18001c3a8 != &DAT_18001c3a0) {
        puVar4 = (undefined8 *)0x3;
        pcVar1 = (code *)swi(0x29);
        puVar3 = (undefined8 *)(*pcVar1)();
        puVar6 = auStack_30;
      }
      puVar3[1] = puVar4;
      *puVar3 = puVar5;
      *puVar4 = puVar3;
      DAT_18001c398 = DAT_18001c398 + 1;
      *(undefined8 *)(puVar6 + -8) = 0x180013618;
      DAT_18001c3a8 = puVar3;
      iVar2 = GetMpioPathInfo(0x18001bd40);
    }
    puVar7 = puVar6;
  }
LAB_18001362e:
  *(undefined8 *)(puVar7 + -8) = 0x18001363e;
  KeReleaseMutex(&DAT_18001c3b0,0);
  uRam000000018001bb10 = uRam000000018001c3f0;
  _DAT_18001bb08 = _DAT_18001c3e8;
  uRam000000018001bb00 = uRam000000018001c3e0;
  _DAT_18001baf8 = _DAT_18001c3d8;
  uRam000000018001baf0 = uRam000000018001c3d0;
  _DAT_18001bae8 = _DAT_18001c3c8;
  uRam000000018001bae0 = uRam000000018001c3c0;
  _DAT_18001bad8 = _DAT_18001c3b8;
  uRam000000018001bad0 = _DAT_18001c3b0;
  _DAT_18001bac8 = DAT_18001c3a8;
  uRam000000018001bac0 = _DAT_18001c3a0;
  _DAT_18001bab8 = CONCAT44(uRam000000018001c39c,DAT_18001c398);
  return iVar2;
}



===== RemoveMpioPath @ 1800136b0 =====

undefined4 RemoveMpioPath(int *param_1,int *param_2,longlong param_3)

{
  uint *puVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  longlong *plVar9;
  undefined4 uVar10;
  
  lVar6 = DAT_18001bd40;
  uVar8 = 0;
  uVar10 = 0;
  plVar9 = *(longlong **)(param_1 + 2);
  do {
    uVar7 = 0;
    if (plVar9 == (longlong *)(param_1 + 2)) {
LAB_180013782:
      uVar10 = uVar7;
      param_2 = *(int **)(param_1 + 2);
      while( true ) {
        if (param_2 == param_1 + 2) {
          return uVar10;
        }
        if ((param_2[0x27] & 2U) != 0) break;
        param_2 = *(int **)param_2;
      }
LAB_1800137a9:
      puVar1 = (uint *)(lVar6 + 0x180);
      if ((char)param_2[0x24] == '\0') {
        *(undefined4 *)(lVar6 + 0x178) = 0;
        uVar5 = *(undefined8 *)(param_2 + 10);
        *(undefined8 *)puVar1 = *(undefined8 *)(param_2 + 8);
        *(undefined8 *)(lVar6 + 0x188) = uVar5;
        uVar5 = *(undefined8 *)(param_2 + 0xe);
        *(undefined8 *)(lVar6 + 400) = *(undefined8 *)(param_2 + 0xc);
        *(undefined8 *)(lVar6 + 0x198) = uVar5;
        uVar5 = *(undefined8 *)(param_2 + 0x12);
        *(undefined8 *)(lVar6 + 0x1a0) = *(undefined8 *)(param_2 + 0x10);
        *(undefined8 *)(lVar6 + 0x1a8) = uVar5;
        *(undefined8 *)(lVar6 + 0x1b0) = *(undefined8 *)(param_2 + 0x14);
        *(uint **)(lVar6 + 0x110) = puVar1;
        *(undefined8 *)(lVar6 + 0x50) = *(undefined8 *)(param_2 + 8);
        *(undefined8 *)(lVar6 + 0x58) = *(undefined8 *)(param_2 + 10);
        *(undefined8 *)(lVar6 + 0x60) = *(undefined8 *)(param_2 + 0xc);
      }
      else {
        *(undefined4 *)(lVar6 + 0x178) = 1;
        uVar5 = *(undefined8 *)(param_2 + 10);
        *(undefined8 *)puVar1 = *(undefined8 *)(param_2 + 8);
        *(undefined8 *)(lVar6 + 0x188) = uVar5;
        uVar5 = *(undefined8 *)(param_2 + 0xe);
        *(undefined8 *)(lVar6 + 400) = *(undefined8 *)(param_2 + 0xc);
        *(undefined8 *)(lVar6 + 0x198) = uVar5;
        uVar5 = *(undefined8 *)(param_2 + 0x12);
        *(undefined8 *)(lVar6 + 0x1a0) = *(undefined8 *)(param_2 + 0x10);
        *(undefined8 *)(lVar6 + 0x1a8) = uVar5;
        uVar5 = *(undefined8 *)(param_2 + 0x16);
        *(undefined8 *)(lVar6 + 0x1b0) = *(undefined8 *)(param_2 + 0x14);
        *(undefined8 *)(lVar6 + 0x1b8) = uVar5;
        uVar5 = *(undefined8 *)(param_2 + 0x1a);
        *(undefined8 *)(lVar6 + 0x1c0) = *(undefined8 *)(param_2 + 0x18);
        *(undefined8 *)(lVar6 + 0x1c8) = uVar5;
        uVar5 = *(undefined8 *)(param_2 + 0x1e);
        *(undefined8 *)(lVar6 + 0x1d0) = *(undefined8 *)(param_2 + 0x1c);
        *(undefined8 *)(lVar6 + 0x1d8) = uVar5;
        *(undefined8 *)(lVar6 + 0x1e0) = *(undefined8 *)(param_2 + 0x20);
        *(uint **)(lVar6 + 0x110) = puVar1;
        *(undefined8 *)(lVar6 + 0x60) = *(undefined8 *)(param_2 + 10);
        if (2 < *puVar1) {
          *(undefined8 *)(lVar6 + 0x50) = *(undefined8 *)(param_2 + 0x18);
          *(undefined8 *)(lVar6 + 0x58) = *(undefined8 *)(param_2 + 0x1a);
        }
      }
      *(undefined8 *)(lVar6 + 0x234) = *(undefined8 *)(param_2 + 0x25);
      *(undefined4 *)(lVar6 + 0x6c) = 0;
      *(undefined8 **)(lVar6 + 0x78) = (undefined8 *)(lVar6 + 0x234);
      return uVar10;
    }
    if (((param_2 != (int *)0x0) && ((int *)plVar9[2] == param_2)) ||
       (((param_3 != 0 &&
         ((((char)plVar9[0x13] == *(char *)(param_3 + 4) &&
           (*(char *)((longlong)plVar9 + 0x99) == *(char *)(param_3 + 5))) &&
          (*(char *)((longlong)plVar9 + 0x9a) == *(char *)(param_3 + 6))))) &&
        (*(char *)((longlong)plVar9 + 0x9b) == *(char *)(param_3 + 7))))) {
      lVar2 = *plVar9;
      if ((*(longlong **)(lVar2 + 8) != plVar9) ||
         (plVar3 = (longlong *)plVar9[1], (longlong *)*plVar3 != plVar9)) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        goto LAB_1800137a9;
      }
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      if ((*(uint *)((longlong)plVar9 + 0x9c) & 2) != 0) {
        uVar8 = SendFreeDumpPointers(plVar9[2],plVar9 + 4,(uint)*(byte *)(plVar9 + 0x12));
      }
      ObfDereferenceObject(plVar9[2]);
      ExFreePoolWithTag(plVar9,0);
      *param_1 = *param_1 + -1;
      uVar7 = uVar8;
      goto LAB_180013782;
    }
    plVar9 = (longlong *)*plVar9;
  } while( true );
}



===== CrashdmpRegisterEtw @ 1800138a4 =====

undefined8 CrashdmpRegisterEtw(void)

{
  undefined8 uVar1;
  
  if (DAT_18001c529 == '\0') {
    uVar1 = McGenEventRegister_EtwRegister();
    if (-1 < (int)uVar1) {
      DAT_18001c529 = '\x01';
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



===== CrashdmpRegisterTraceLogging @ 1800138d4 =====

int CrashdmpRegisterTraceLogging(void)

{
  int iVar1;
  
  if (DAT_18001c52a == '\0') {
    ReportBugCheckProgress = DAT_18001bd28;
    iVar1 = TraceLoggingRegisterEx_EtwRegister_EtwSetInformation();
    if (-1 < iVar1) {
      DAT_18001c52a = '\x01';
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



===== CrashdmpTelemetryCheckForPreviousCrash @ 180013910 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CrashdmpTelemetryCheckForPreviousCrash(void)

{
  int iVar1;
  ulonglong uVar2;
  wchar_t *pwVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 in_R9;
  undefined1 auStackY_128 [32];
  undefined4 local_f8 [2];
  undefined8 local_f0;
  undefined1 local_e8;
  undefined1 local_e7 [3];
  uint local_e4;
  undefined2 local_e0 [2];
  undefined2 local_dc [2];
  undefined8 local_d8;
  uint local_d0;
  undefined4 local_cc;
  uint local_c8 [2];
  undefined8 local_c0;
  undefined8 local_b8 [4];
  uint *local_98;
  undefined8 local_90;
  undefined4 *local_88;
  undefined8 local_80;
  undefined8 *local_78;
  undefined8 local_70;
  uint *local_68;
  undefined8 local_60;
  undefined2 *local_58;
  undefined8 local_50;
  undefined2 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_128;
  local_d8 = 0xffffffffffffffff;
  local_e4 = 0;
  local_f0 = 0;
  local_f8[0] = 8;
  iVar1 = CrashdmpTelemetryGetEnvironmentVariable(L"BugCheckCode",&local_f0,local_f8);
  if (iVar1 < 0) {
    local_f0 = 0;
  }
  local_f8[0] = 4;
  iVar1 = CrashdmpTelemetryGetEnvironmentVariable(L"BugCheckProgress",&local_e4,local_f8);
  if ((-1 < iVar1) && (local_e4 != 0)) {
    local_f8[0] = 8;
    pwVar3 = L"BugCheckParameter1";
    CrashdmpTelemetryGetEnvironmentVariable(L"BugCheckParameter1",&local_d8,local_f8);
    uVar5 = 2;
    if ((DAT_18001bd60 >> 0x1a & 1) == 0) {
      uVar4 = 0;
      if ((DAT_18001bd60 >> 0x1b & 1) != 0) {
        uVar4 = 2;
      }
    }
    else {
      uVar4 = CONCAT71((int7)((ulonglong)pwVar3 >> 8),1);
    }
    if (5 < DAT_18001b048) {
      uVar2 = _tlgKeywordOn(uVar4,0x800000000000);
      if ((char)uVar2 != '\0') {
        local_d0 = local_e4;
        local_98 = &local_d0;
        local_cc = (undefined4)local_f0;
        local_88 = &local_cc;
        local_c0 = local_d8;
        local_78 = &local_c0;
        local_90 = 4;
        local_80 = 4;
        local_70 = 8;
        local_c8[0] = _DAT_fffff780000002c4;
        local_68 = local_c8;
        local_e0[0] = local_f0._4_2_;
        local_58 = local_e0;
        local_dc[0] = local_f0._6_2_;
        local_48 = local_dc;
        local_38 = &local_e8;
        local_28 = local_e7;
        local_60 = 4;
        local_e8 = 4;
        local_30 = 1;
        local_e7[0] = (undefined1)uVar4;
        local_20 = 1;
        local_50 = uVar5;
        local_40 = uVar5;
        _tlgWriteTransfer_EtwWriteTransfer(uVar4,&DAT_1800192a8,uVar5,in_R9,10,local_b8);
      }
    }
    CrashdmpLogSELEarlyCheckpoint_ULONG1();
    _DAT_18001c560 = (undefined4)local_f0;
    _DAT_18001c564 = (uint)local_f0._4_2_;
    _DAT_18001c568 = local_d8;
    _DAT_18001c570 = (uint)local_f0._6_2_;
    DAT_18001c55c = local_e4;
    if ((((local_e4 & 0xffff0000) != 0) ||
        (((local_e4 & 0x1ff) != 4 && ((local_e4 & 0x1ff) != 0x25)))) && ((local_e4 >> 0xd & 1) == 0)
       ) {
      DAT_18001c588 = 1;
    }
    local_e4 = 0;
    local_f8[0] = 4;
    CrashdmpTelemetrySaveEnvironmentVariable(L"BugCheckProgress",&local_e4,4);
    local_f0 = local_f0 & 0xffffffff00000000;
    local_f8[0] = 8;
    CrashdmpTelemetrySaveEnvironmentVariable(L"BugCheckCode",&local_f0,8);
    local_d8 = 0;
    local_f8[0] = 8;
    CrashdmpTelemetrySaveEnvironmentVariable(L"BugCheckParameter1",&local_d8,8);
  }
  if ((_DAT_fffff780000002c4 < local_f0._4_2_) && (local_f0._6_2_ != 0)) {
    local_f0 = local_f0 & 0xffffffff;
    local_f8[0] = 8;
    CrashdmpTelemetrySaveEnvironmentVariable(L"BugCheckCode",&local_f0,8);
  }
  _DAT_18001c570 = (uint)local_f0._6_2_;
  return;
}



===== CrashdmpTelemetryGetEnvironmentVariable @ 180013bfc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
CrashdmpTelemetryGetEnvironmentVariable(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0xc0000001;
  cVar1 = (**(code **)(HalPrivateDispatchTable_exref + 0x3b0))();
  if (cVar1 == '\0') {
    uVar2 = HalGetEnvironmentVariableEx(param_1,&BUGCHECK_EFI_GUID,param_2,param_3,0);
  }
  return uVar2;
}



===== CrashdmpTelemetrySaveEnvironmentVariable @ 180013c78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
CrashdmpTelemetrySaveEnvironmentVariable(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0xc0000001;
  cVar1 = (**(code **)(HalPrivateDispatchTable_exref + 0x3b0))();
  if (cVar1 == '\0') {
    uVar2 = (*ReportBugCheckProgress)(param_1,&BUGCHECK_EFI_GUID,param_2,param_3,1);
  }
  return uVar2;
}



===== CrashdmpTelemetrySaveLastCrashdumpInfoAndSettings @ 180013cf8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CrashdmpTelemetrySaveLastCrashdumpInfoAndSettings(longlong param_1)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 ****ppppuVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  undefined1 auStackY_118 [32];
  undefined1 local_d8 [4];
  uint local_d4;
  int local_d0;
  int local_cc [3];
  undefined8 ****local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined8 local_a0;
  undefined8 *local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78 [4];
  int *local_58;
  undefined8 local_50;
  int *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  int *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_118;
  local_a4 = 0;
  local_8c = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_c0 = (undefined8 ****)0x0;
  local_d4 = 0;
  if ((DAT_18001c55c != 0) && ((DAT_18001c57c & 0x200) == 0)) {
    DAT_18001c57c = DAT_18001c57c | 0x200;
    RtlInitUnicodeString
              (&local_b8,
               L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl\\LastCrashdump"
              );
    local_98 = &local_b8;
    uVar5 = 0;
    puVar4 = &local_a8;
    local_a8 = 0x30;
    local_a0 = 0;
    ppppuVar3 = &local_c0;
    local_90 = 0x240;
    local_88 = 0;
    uStack_80 = 0;
    iVar1 = ZwCreateKey(ppppuVar3,0x2001f);
    if (-1 < iVar1) {
      _DAT_18001c558 = 0xce;
      _DAT_18001c578 = *(undefined4 *)(param_1 + 0x1c);
      _DAT_18001c574 = _DAT_fffff780000002c4;
      DAT_18001c57c = (*(uint *)(param_1 + 0x20) & 1) << 8 | DAT_18001c57c & 0xfffffeff;
      _DAT_18001c580 = DAT_18001c548;
      ReadRegULongKey(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl",
                      L"EnableOfflineDumps",&local_d4,0);
      DAT_18001c57c = DAT_18001c57c & 0xfffffff0 | local_d4 & 0xf;
      if ((local_d4 & 0xf) != 0) {
        ReadRegULongKey(L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl",
                        L"AttemptOffline",&local_d4,0);
        DAT_18001c57c = (local_d4 & 0xf) << 4 | DAT_18001c57c & 0xffffff0f;
      }
      RtlInitUnicodeString(&local_b8,L"Info");
      uVar5 = 3;
      puVar4 = (undefined4 *)0x0;
      iVar1 = ZwSetValueKey(local_c0,&local_b8);
      ppppuVar3 = local_c0;
      ZwClose();
      if (-1 < iVar1) {
        return;
      }
    }
    if ((5 < DAT_18001b048) &&
       (uVar2 = _tlgKeywordOn(ppppuVar3,0x200000000000), (char)uVar2 != '\0')) {
      local_d0 = DAT_18001c55c;
      local_58 = &local_d0;
      local_50 = 4;
      local_48 = local_cc;
      local_38 = local_d8;
      local_28 = local_cc + 1;
      local_40 = 4;
      local_d8[0] = 4;
      local_30 = 1;
      local_cc[1] = 0xce;
      local_20 = 4;
      local_cc[0] = iVar1;
      _tlgWriteTransfer_EtwWriteTransfer(4,&DAT_18001923d,puVar4,uVar5,6,local_78);
    }
  }
  return;
}



===== McGenControlCallbackV2 @ 180013fc0 =====

void McGenControlCallbackV2
               (undefined8 param_1,int param_2,undefined1 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,longlong param_7)

{
  uint *puVar1;
  ulonglong uVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  
  if (param_7 != 0) {
    if (param_2 == 0) {
      *(undefined4 *)(param_7 + 0x24) = 0;
      *(undefined1 *)(param_7 + 0x28) = 0;
      *(undefined8 *)(param_7 + 0x10) = 0;
      *(undefined8 *)(param_7 + 0x18) = 0;
      if (*(ushort *)(param_7 + 0x2a) != 0) {
        memset(*(void **)(param_7 + 0x30),0,
               (longlong)((int)(*(ushort *)(param_7 + 0x2a) - 1) / 0x20 + 1) << 2);
      }
    }
    else if (param_2 == 1) {
      *(undefined1 *)(param_7 + 0x28) = param_3;
      uVar6 = 0;
      *(undefined8 *)(param_7 + 0x18) = param_5;
      *(undefined8 *)(param_7 + 0x10) = param_4;
      *(undefined4 *)(param_7 + 0x24) = 1;
      if (*(short *)(param_7 + 0x2a) != 0) {
        do {
          uVar2 = *(ulonglong *)(*(longlong *)(param_7 + 0x38) + uVar6 * 8);
          if (((*(byte *)(param_7 + 0x28) < *(byte *)(uVar6 + *(longlong *)(param_7 + 0x40))) &&
              (*(byte *)(param_7 + 0x28) != 0)) ||
             ((uVar2 != 0 &&
              (((*(ulonglong *)(param_7 + 0x10) & uVar2) == 0 ||
               ((*(ulonglong *)(param_7 + 0x18) & uVar2) != *(ulonglong *)(param_7 + 0x18))))))) {
            bVar3 = false;
          }
          else {
            bVar3 = true;
          }
          uVar4 = 1 << ((byte)uVar6 & 0x1f);
          puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (uVar6 >> 5) * 4);
          uVar5 = *puVar1;
          if (bVar3) {
            uVar4 = uVar4 | uVar5;
          }
          else {
            uVar4 = ~uVar4 & uVar5;
          }
          *puVar1 = uVar4;
          uVar5 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar5;
        } while (uVar5 < *(ushort *)(param_7 + 0x2a));
      }
    }
  }
  return;
}



===== McGenEventRegister_EtwRegister @ 1800140d0 =====

void McGenEventRegister_EtwRegister(void)

{
  if (CrashdumpEventProvider_Context == 0) {
    EtwRegister(&CrashdumpEventProvider,McGenControlCallbackV2,&CrashdumpEventProvider_Context,
                &CrashdumpEventProvider_Context);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 180014110 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (CrashdumpEventProvider_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    CrashdumpEventProvider_Context = 0;
  }
  return uVar1;
}



===== _tlgDefineProvider_annotation__TlgCrashdmpTraceLoggingProviderProv @ 180014144 =====

void _tlgDefineProvider_annotation__TlgCrashdmpTraceLoggingProviderProv(void)

{
  return;
}



===== CrashdmpLogSELCheckpoint_ULONG1 @ 180014150 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CrashdmpLogSELCheckpoint_ULONG1(undefined8 param_1,undefined4 param_2)

{
  char cVar1;
  undefined1 auStack_58 [32];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  cVar1 = WheaIsLogSelHandlerInitialized();
  if (cVar1 != '\0') {
    local_2c = 0;
    local_38 = 0x674c6857;
    local_34 = 1;
    local_30 = 0x24;
    local_24 = 0x80000069;
    local_28 = 0x80000069;
    local_20 = 0x18;
    local_1c = 4;
    local_18 = param_2;
    WheaLogInternalEvent(&local_38);
  }
  return;
}



===== CrashdmpLogSELEarlyCheckpoint_ULONG1 @ 1800141e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CrashdmpLogSELEarlyCheckpoint_ULONG1(void)

{
  (**(code **)(DAT_18001c5a8 + 0x78))();
  return;
}



===== CrashdmpLogSELEarlyError @ 180014204 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void CrashdmpLogSELEarlyError(void)

{
  (**(code **)(DAT_18001c5a8 + 0x70))();
  return;
}



===== CrashdmpLogSELError @ 180014224 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CrashdmpLogSELError(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  undefined1 auStack_58 [32];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  cVar1 = WheaIsLogSelHandlerInitialized();
  if (cVar1 != '\0') {
    local_2c = 0;
    local_38 = 0x674c6857;
    local_34 = 1;
    local_30 = 0x28;
    local_24 = 0x80000067;
    local_28 = 0x80000067;
    local_20 = 0x18;
    local_1c = 8;
    local_18 = param_1;
    local_14 = param_2;
    WheaLogInternalEvent(&local_38);
  }
  return;
}



===== _guard_check_icall @ 1800142d0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1800142e8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 18001430c =====

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



===== __GSHandlerCheck_SEH @ 180014374 =====

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



===== __cpu_features_init @ 180014410 =====

/* WARNING: Removing unreachable block (ram,0x00018001447a) */
/* WARNING: Removing unreachable block (ram,0x000180014429) */
/* WARNING: Removing unreachable block (ram,0x00018001441a) */

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



===== __security_check_cookie @ 1800144e0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 180014520 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 180014550 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000180014550. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 180014580 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 1800145e0 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_180014623;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_180014694;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_180014690:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_180014694;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_18001468c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_180014690;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_18001468c;
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
LAB_180014694:
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
LAB_180014623:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memcpy @ 180014700 =====

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



===== memset @ 180014a00 =====

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



===== __memset_repmovs @ 180014b40 =====

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



===== __memset_query @ 180014bc0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 180014c40 =====

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



===== __memset_spec_ermsb_repmovsb @ 180014d80 =====

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



===== __memset_spec_plain @ 180014e00 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 180014f00 =====

void wil_details_BuildFeatureStateCacheFromQueryResults(int param_1,longlong param_2,uint *param_3)

{
  uint uVar1;
  
  if ((param_1 == -0x7fffffde) || (param_1 == -0x3ffffddb)) {
    param_3[0] = 0;
    param_3[1] = 0;
  }
  else {
    param_3[0] = 0;
    param_3[1] = 0;
    if (param_1 == 0) {
      uVar1 = ((*(uint *)(param_2 + 4) & 0x40) << 2 | *(uint *)(param_2 + 4) & 0xb0) << 3 | 0x206;
      goto LAB_180014f5d;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_180014f5d;
    }
  }
  uVar1 = 0x206;
LAB_180014f5d:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 180014f68 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  undefined **ppuVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  bool bVar6;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)&wil_details_featureDescriptors_a)
  ;
  if (plVar1 != (longlong *)0x0) {
    uVar4 = 0;
    uVar5 = 0x180;
    do {
      uVar3 = *(uint *)*plVar1;
      if ((uVar3 >> 9 & 1) != 0) {
        if (((uint)uVar5 & uVar3) == 0) {
          bVar6 = *(char *)((longlong)plVar1 + 0x1f) != '\0';
        }
        else {
          bVar6 = (uVar3 & (uint)uVar5) == 0x100;
        }
        uVar3 = uVar3 & 0x40 ^ (uint)bVar6 << 6 | (uint)uVar4 & 0xffffffbf;
        uVar4 = (ulonglong)uVar3;
        LOCK();
        *(uint *)*plVar1 = *(uint *)*plVar1 ^ uVar3;
        UNLOCK();
      }
      plVar1 = wil_details_FeatureDescriptors_SkipPadding(plVar1 + 7);
    } while (plVar1 != (longlong *)0x0);
  }
  ppuVar2 = &wil_details_featureDescriptors_a;
  while( true ) {
    plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar2);
    if (plVar1 == (longlong *)0x0) break;
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*plVar1,(longlong)plVar1);
    ppuVar2 = (undefined **)(plVar1 + 7);
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 180015020 =====

uint wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
               (uint *param_1,longlong param_2)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if ((uVar1 >> 9 & 1) != 0) {
    uVar1 = wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState
                      (param_1,uVar1,param_2);
  }
  return uVar1;
}



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 180015058 =====

uint wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState
               (uint *param_1,uint param_2,longlong param_3)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  longlong *plVar4;
  uint uVar5;
  bool bVar6;
  
  uVar5 = param_2 >> 6 & 1;
  if ((uVar5 != 0) && (plVar4 = *(longlong **)(param_3 + 0x20), plVar4 != (longlong *)0x0)) {
    do {
      while( true ) {
        puVar1 = (undefined8 *)*plVar4;
        if (puVar1 == (undefined8 *)0x0) goto LAB_1800150da;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_1800150da;
        }
        uVar5 = 1;
        plVar4 = plVar4 + 1;
      }
      uVar2 = wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
                        ((uint *)*puVar1,(longlong)puVar1);
      if ((uVar5 == 0) || ((uVar2 & 1) == 0)) {
        uVar5 = 0;
      }
      else {
        uVar5 = 1;
      }
      plVar4 = plVar4 + 1;
    } while (uVar5 != 0);
  }
LAB_1800150da:
  do {
    uVar2 = param_2 & 0xffffffce;
    if ((param_2 & 1) == uVar5) {
      uVar2 = param_2 & 0xfffffffe;
    }
    uVar3 = uVar2 & 0xfffffdff | uVar5;
    LOCK();
    uVar2 = *param_1;
    bVar6 = param_2 == uVar2;
    if (bVar6) {
      *param_1 = uVar3;
    }
    else {
      param_2 = uVar2;
    }
    UNLOCK();
  } while (!bVar6);
  return uVar3;
}



===== wil_details_OnFeatureUsageProviderFlushNotification @ 180015130 =====

void wil_details_OnFeatureUsageProviderFlushNotification(int param_1)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  
  iVar1 = g_wil_details_featureUsageCached;
  if (param_1 == 1) {
    LOCK();
    g_wil_details_featureUsageCached = 0;
    UNLOCK();
    if (iVar1 != 0) {
      ppuVar3 = &wil_details_featureDescriptors_a;
      while (plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3),
            plVar2 != (longlong *)0x0) {
        if ((*(uint *)plVar2[1] & 1) != 0) {
          wil_details_RecordCachedUsage((int)plVar2[3],(uint *)plVar2[1]);
        }
        ppuVar3 = (undefined **)(plVar2 + 7);
      }
    }
  }
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 180015190 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 1800151ac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_UpdateFeatureConfiguredStates(void)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  undefined1 auStack_58 [32];
  uint local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  ppuVar3 = &wil_details_featureDescriptors_a;
  while( true ) {
    plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3);
    if (plVar2 == (longlong *)0x0) break;
    if (((*(char *)((longlong)plVar2 + 0x1d) == '\0') &&
        (*(char *)((longlong)plVar2 + 0x1e) == '\0')) &&
       (*(char *)((longlong)plVar2 + 0x1c) == '\0')) {
      local_30 = 0;
      local_28 = 0;
      local_20 = 0;
      iVar1 = RtlQueryFeatureConfiguration((int)plVar2[3],1,&local_30,&local_28);
      local_38[0] = 0;
      local_38[1] = 0;
      wil_details_BuildFeatureStateCacheFromQueryResults(iVar1,(longlong)&local_28,local_38);
      LOCK();
      *(uint *)*plVar2 = *(uint *)*plVar2 ^ (*(uint *)*plVar2 ^ local_38[0]) & 0xf80;
      UNLOCK();
    }
    ppuVar3 = (undefined **)(plVar2 + 7);
  }
  return;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 180015260 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 wil_RtlStagingConfig_QueryFeatureState(uint *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  uint local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  local_20 = 0;
  local_18 = 0;
  iVar1 = RtlQueryFeatureConfiguration(param_2,param_3 == 0,&local_28,&local_20);
  if (iVar1 == 0) {
    *param_1 = local_20._4_4_ >> 4 & 3;
    *(byte *)(param_1 + 1) = (byte)((ulonglong)local_20 >> 0x28) & 0x3f;
    param_1[3] = local_18;
    param_1[2] = local_20._4_4_ >> 0xe & 3;
    param_1[5] = local_20._4_4_ >> 6 & 1;
    param_1[4] = local_20._4_4_ >> 7 & 1;
  }
  else {
    if (iVar1 != 0x117) {
      return 0;
    }
    param_1[4] = local_20._4_4_ >> 7 & 1;
  }
  return 1;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 18001532c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(void)

{
  undefined2 uVar1;
  code *pcVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  ulonglong local_18;
  
  puVar4 = auStack_48;
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = *(undefined4 *)(PTR_DAT_18001b050 + -0x10);
  uStack_24 = *(undefined4 *)(PTR_DAT_18001b050 + -0xc);
  uStack_20 = *(undefined4 *)(PTR_DAT_18001b050 + -8);
  uStack_1c = *(undefined4 *)(PTR_DAT_18001b050 + -4);
  if (DAT_18001b068 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_40;
  }
  _DAT_18001b070 = 0;
  uRam000000018001b078 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x18001538f;
  iVar3 = EtwRegister(puVar4 + 0x20,_tlgEnableCallback,&DAT_18001b048,&DAT_18001b068);
  if (iVar3 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_18001b050;
    *(undefined8 *)(puVar4 + -8) = 0x1800153b6;
    EtwSetInformation(DAT_18001b068,2,PTR_DAT_18001b050,uVar1);
  }
  *(undefined8 *)(puVar4 + -8) = 0x1800153ca;
  return iVar3;
}



===== _tlgEnableCallback @ 1800153e0 =====

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



===== entry @ 180023010 =====

void entry(undefined8 *param_1,int *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 180023044 =====

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



===== wil_InitializeFeatureStaging @ 180023078 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wil_InitializeFeatureStaging(void)

{
  bool bVar1;
  int iVar2;
  longlong *plVar3;
  undefined **ppuVar4;
  undefined8 local_res8;
  
  bVar1 = false;
  if (g_wil_details_isFeatureStagingInitialized == 0) {
    g_wil_details_isFeatureStagingInitialized = 1;
    local_res8 = RtlQueryFeatureConfigurationChangeStamp();
    wil_details_PopulateInitialConfiguredFeatureStates();
    wil_details_EvaluateFeatureDependencies();
    ppuVar4 = &wil_details_featureDescriptors_a;
    while (plVar3 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar4),
          plVar3 != (longlong *)0x0) {
      if (((*(char *)((longlong)plVar3 + 0x1d) == '\0') &&
          (*(char *)((longlong)plVar3 + 0x1e) == '\0')) &&
         (*(char *)((longlong)plVar3 + 0x1c) == '\0')) {
        iVar2 = RtlRegisterFeatureConfigurationChangeNotification
                          (wil_details_ReevaluateOnFeatureConfigurationChange,0,&local_res8,
                           &g_wil_details_featureChangeNotification);
        if (iVar2 == 0) {
          bVar1 = true;
        }
        else {
          _g_wil_details_featureChangeNotification = 0;
        }
        break;
      }
      ppuVar4 = (undefined **)(plVar3 + 7);
    }
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
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 180023168 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  undefined8 uVar4;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  ppuVar3 = &wil_details_featureDescriptors_a;
  do {
    plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3);
    if (plVar2 == (longlong *)0x0) {
      return;
    }
    local_30 = 0;
    local_38 = 0;
    local_28 = 0;
    local_20 = 0;
    if ((*(char *)((longlong)plVar2 + 0x1d) == '\0') && (*(char *)((longlong)plVar2 + 0x1e) == '\0')
       ) {
      iVar1 = RtlQueryFeatureConfiguration
                        ((int)plVar2[3],1 < (byte)(*(char *)((longlong)plVar2 + 0x1c) - 2U),
                         &local_30,&local_28);
      if (iVar1 == -0x7fffffde) {
        local_38 = 0x206;
        uVar4 = 0x206;
        do {
          *(undefined8 *)*plVar2 = uVar4;
          plVar2 = wil_details_FeatureDescriptors_SkipPadding(plVar2 + 7);
        } while (plVar2 != (longlong *)0x0);
        return;
      }
    }
    else {
      iVar1 = -0x3ffffddb;
    }
    wil_details_BuildFeatureStateCacheFromQueryResults(iVar1,(longlong)&local_28,(uint *)&local_38);
    ppuVar3 = (undefined **)(plVar2 + 7);
    *(undefined8 *)*plVar2 = local_38;
  } while( true );
}


