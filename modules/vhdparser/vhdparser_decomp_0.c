
===== _tlgKeywordOn @ 1c0001008 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong _tlgKeywordOn(void)

{
  ulonglong in_RAX;
  
  if (((_DAT_1c0007020 & 0x100000) == 0) ||
     (in_RAX = DAT_1c0007028 & 0x100000, in_RAX != DAT_1c0007028)) {
    return in_RAX & 0xffffffffffffff00;
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== _tlgWriteTransfer_EtwWriteTransfer @ 1c0001038 =====

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
  *param_6 = PTR_DAT_1c0007018;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_1c0007018;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(DAT_1c0007030,&local_18,param_3,param_4,param_5,param_6);
  return;
}



===== NVhdParserExecuteScsiRequestDisk @ 1c00010f0 =====

void NVhdParserExecuteScsiRequestDisk(longlong param_1,longlong *param_2)

{
  undefined8 *puVar1;
  char cVar2;
  undefined8 uVar3;
  
  puVar1 = (undefined8 *)*param_2;
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[7] = 0;
  puVar1[8] = 0;
  puVar1[9] = 0;
  puVar1[10] = 0;
  puVar1[0xd] = 0;
  puVar1[0xb] = param_1;
  puVar1[0xc] = param_2;
  if (*(char *)(param_1 + 0x17) == '\0') {
    NVhdParserIssueScsiRequest(param_1,param_2);
    return;
  }
  if (*(char *)((longlong)param_2 + 0x2b) == '\0') {
    uVar3 = DvEnterRundownBarrier((longlong *)(param_1 + 200),(longlong *)0x0);
    if (-1 < (int)uVar3) {
      cVar2 = ExAcquireRundownProtection(param_1 + 0xc0);
      if (cVar2 != '\0') {
        LOCK();
        *(int *)(param_1 + 0xb8) = *(int *)(param_1 + 0xb8) + 1;
        UNLOCK();
        goto LAB_1c000116e;
      }
      DvExitRundownBarrierEx((longlong *)(param_1 + 200));
    }
  }
  else {
    uVar3 = DvEnterRundownBarrier((longlong *)(param_1 + 200),puVar1 + 0xd);
    if ((int)uVar3 == 0x103) {
      return;
    }
    if (-1 < (int)uVar3) {
LAB_1c000116e:
      NVhdParserIssueScsiRequest(param_1,param_2);
      DvExitRundownBarrierEx((longlong *)(param_1 + 200));
      return;
    }
  }
  *(undefined1 *)(param_2[1] + 2) = 2;
  VstorCompleteScsiRequest(param_2);
  return;
}



===== NVhdParserIssueScsiRequest @ 1c00011e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void NVhdParserIssueScsiRequest(longlong param_1,longlong *param_2)

{
  char *_Src;
  int *piVar1;
  undefined2 *puVar2;
  longlong lVar3;
  int iVar4;
  longlong lVar5;
  ulonglong uVar6;
  uint uVar7;
  longlong *plVar8;
  
  puVar2 = (undefined2 *)*param_2;
  lVar5 = param_2[1];
  _Src = (char *)(lVar5 + 0x10);
  *puVar2 = 0x58;
  *(undefined1 *)((longlong)puVar2 + 3) = *(undefined1 *)(lVar5 + 2);
  *(undefined1 *)(puVar2 + 2) = *(undefined1 *)(lVar5 + 3);
  *(undefined1 *)((longlong)puVar2 + 5) = *(undefined1 *)(param_1 + 0x10);
  *(undefined1 *)(puVar2 + 3) = *(undefined1 *)(param_1 + 0x11);
  *(undefined1 *)((longlong)puVar2 + 7) = *(undefined1 *)(param_1 + 0x12);
  *(undefined1 *)(puVar2 + 5) = *(undefined1 *)(lVar5 + 8);
  *(undefined1 *)((longlong)puVar2 + 0xb) = *(undefined1 *)(lVar5 + 9);
  uVar7 = 0x40;
  if (*(char *)(lVar5 + 10) == '\0') {
    uVar7 = 0x80;
  }
  *(uint *)(puVar2 + 6) = uVar7;
  *(undefined4 *)(puVar2 + 8) = *(undefined4 *)(lVar5 + 0xc);
  *(uint *)(puVar2 + 6) = *(uint *)(lVar5 + 0x28) & 0x8000 | uVar7;
  if (*_Src != -0x78) {
    switch(*_Src) {
    case '\b':
    case '\n':
    case '(':
    case '*':
    case -0x76:
    case -0x58:
    case -0x56:
      break;
    default:
      lVar5 = param_2[2];
      if (lVar5 != 0) {
        if ((*(byte *)(lVar5 + 10) & 5) == 0) {
          lVar5 = MmMapLockedPagesSpecifyCache(lVar5,0,1,0,0,0x40000010);
        }
        else {
          lVar5 = *(longlong *)(lVar5 + 0x18);
        }
        *(longlong *)(puVar2 + 0xc) = lVar5;
        if (lVar5 == 0) {
          *(undefined1 *)(param_2[1] + 2) = 0x30;
          goto LAB_1c0001358;
        }
      }
    }
  }
  *(undefined2 **)(puVar2 + 0x1c) = puVar2 + 0x38;
  *(char **)(puVar2 + 0x10) = _Src;
  memcpy(puVar2 + 0x24,_Src,(ulonglong)*(byte *)(puVar2 + 5));
  plVar8 = param_2 + 3;
  if ((char)param_2[5] == '\0') {
    plVar8 = (longlong *)0x0;
  }
  iVar4 = (**(code **)(param_1 + 0x30))
                    (*(undefined8 *)(param_1 + 0x28),param_2,puVar2,param_2[2],
                     *(undefined1 *)((longlong)param_2 + 0x29),plVar8);
  if (iVar4 == 0x103) {
    return;
  }
  uVar6 = NVhdIoFinalizeVhdmpRequest(param_2,iVar4);
  if ((char)uVar6 == '\0') {
    return;
  }
LAB_1c0001358:
  lVar5 = *param_2;
  lVar3 = *(longlong *)(lVar5 + 0x58);
  if ((*(char *)(lVar3 + 0x17) != '\0') && (*(char *)((longlong)param_2 + 0x2b) == '\0')) {
    LOCK();
    piVar1 = (int *)(lVar3 + 0xb8);
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    ExReleaseRundownProtection(*(longlong *)(lVar5 + 0x58) + 0xc0);
  }
  VstorCompleteScsiRequest(param_2);
  return;
}



===== NVhdIoFinalizeVhdmpRequest @ 1c00013d0 =====

ulonglong NVhdIoFinalizeVhdmpRequest(longlong *param_1,int param_2)

{
  ulonglong *puVar1;
  char cVar2;
  undefined4 uVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong lVar8;
  bool bVar9;
  
  lVar8 = *param_1;
  lVar4 = param_1[1];
  lVar5 = *(longlong *)(lVar8 + 0x58);
  if ((((*(char *)(lVar5 + 0x17) == '\0') || (*(char *)((longlong)param_1 + 0x2b) == '\0')) ||
      ((*(byte *)(lVar8 + 3) & 0x3f) != 2)) || ((char)*(byte *)(lVar8 + 3) < '\0')) {
LAB_1c00013f8:
    cVar2 = *(char *)(lVar8 + 3);
    *(char *)(lVar4 + 2) = cVar2;
    *(undefined1 *)(lVar4 + 3) = *(undefined1 *)(lVar8 + 4);
    *(undefined1 *)(lVar4 + 9) = *(undefined1 *)(lVar8 + 0xb);
    uVar3 = *(undefined4 *)(lVar8 + 0x10);
    *(undefined4 *)(lVar4 + 0xc) = uVar3;
    if (param_2 < 0) {
      if (cVar2 == '\x01') {
        *(undefined1 *)(lVar4 + 2) = 4;
      }
    }
    else if (*(char *)(lVar8 + 0x48) == '\x12') {
      *(byte *)(lVar4 + 0xb) = *(byte *)(lVar4 + 0xb) | 3;
    }
    uVar6 = CONCAT71((uint7)(uint3)((uint)uVar3 >> 8),1);
  }
  else {
    puVar1 = (ulonglong *)(lVar8 + 0x68);
    uVar6 = DvEnterRundownBarrier((longlong *)(lVar5 + 200),(longlong *)puVar1);
    if ((int)uVar6 == 0) {
      uVar7 = *(ulonglong *)(lVar5 + 0xe0);
      do {
        *puVar1 = uVar7 & 0xfffffffffffffffe;
        LOCK();
        uVar6 = *(ulonglong *)(lVar5 + 0xe0);
        if (uVar7 == uVar6) {
          *(ulonglong *)(lVar5 + 0xe0) = (ulonglong)puVar1;
          uVar6 = uVar7;
        }
        else {
        }
        UNLOCK();
        bVar9 = uVar6 != uVar7;
        uVar7 = uVar6;
      } while (bVar9);
      if (uVar6 == 0) {
        uVar6 = IoQueueWorkItem(*(undefined8 *)(lVar5 + 0xd8),NVhdIoReplayWorkItemRoutine,1,lVar5);
      }
    }
    else if ((int)uVar6 != 0x103) goto LAB_1c00013f8;
    uVar6 = uVar6 & 0xffffffffffffff00;
  }
  return uVar6;
}



===== NVhdIoInitializeVhdmpRequest @ 1c00014f0 =====

undefined8 NVhdIoInitializeVhdmpRequest(longlong param_1,undefined8 *param_2)

{
  char *_Src;
  undefined2 *puVar1;
  longlong lVar2;
  uint uVar3;
  
  lVar2 = param_2[1];
  puVar1 = (undefined2 *)*param_2;
  _Src = (char *)(lVar2 + 0x10);
  *puVar1 = 0x58;
  *(undefined1 *)((longlong)puVar1 + 3) = *(undefined1 *)(lVar2 + 2);
  *(undefined1 *)(puVar1 + 2) = *(undefined1 *)(lVar2 + 3);
  *(undefined1 *)((longlong)puVar1 + 5) = *(undefined1 *)(param_1 + 0x10);
  *(undefined1 *)(puVar1 + 3) = *(undefined1 *)(param_1 + 0x11);
  *(undefined1 *)((longlong)puVar1 + 7) = *(undefined1 *)(param_1 + 0x12);
  *(undefined1 *)(puVar1 + 5) = *(undefined1 *)(lVar2 + 8);
  *(undefined1 *)((longlong)puVar1 + 0xb) = *(undefined1 *)(lVar2 + 9);
  uVar3 = 0x40;
  if (*(char *)(lVar2 + 10) == '\0') {
    uVar3 = 0x80;
  }
  *(uint *)(puVar1 + 6) = uVar3;
  *(undefined4 *)(puVar1 + 8) = *(undefined4 *)(lVar2 + 0xc);
  *(uint *)(puVar1 + 6) = *(uint *)(lVar2 + 0x28) & 0x8000 | uVar3;
  if (*_Src != -0x78) {
    switch(*_Src) {
    case '\b':
    case '\n':
    case '(':
    case '*':
    case -0x76:
    case -0x58:
    case -0x56:
      break;
    default:
      lVar2 = param_2[2];
      if (lVar2 != 0) {
        if ((*(byte *)(lVar2 + 10) & 5) == 0) {
          lVar2 = MmMapLockedPagesSpecifyCache(lVar2,0,1,0,0,0x40000010);
        }
        else {
          lVar2 = *(longlong *)(lVar2 + 0x18);
        }
        *(longlong *)(puVar1 + 0xc) = lVar2;
        if (lVar2 == 0) {
          return 0xc000009a;
        }
      }
    }
  }
  *(undefined2 **)(puVar1 + 0x1c) = puVar1 + 0x38;
  *(char **)(puVar1 + 0x10) = _Src;
  memcpy(puVar1 + 0x24,_Src,(ulonglong)*(byte *)(puVar1 + 5));
  return 0;
}



===== NVhdIoParserEndIo @ 1c0001620 =====

void NVhdIoParserEndIo(longlong *param_1,int param_2)

{
  ulonglong *puVar1;
  int *piVar2;
  char cVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  longlong lVar9;
  bool bVar10;
  
  lVar9 = *param_1;
  lVar4 = param_1[1];
  lVar5 = *(longlong *)(lVar9 + 0x58);
  if ((((*(char *)(lVar5 + 0x17) != '\0') && (*(char *)((longlong)param_1 + 0x2b) != '\0')) &&
      ((*(byte *)(lVar9 + 3) & 0x3f) == 2)) && (-1 < (char)*(byte *)(lVar9 + 3))) {
    puVar1 = (ulonglong *)(lVar9 + 0x68);
    uVar6 = DvEnterRundownBarrier((longlong *)(lVar5 + 200),(longlong *)puVar1);
    if ((int)uVar6 == 0) {
      uVar7 = *(ulonglong *)(lVar5 + 0xe0);
      do {
        *puVar1 = uVar7 & 0xfffffffffffffffe;
        LOCK();
        uVar8 = *(ulonglong *)(lVar5 + 0xe0);
        if (uVar7 == uVar8) {
          *(ulonglong *)(lVar5 + 0xe0) = (ulonglong)puVar1;
          uVar8 = uVar7;
        }
        else {
        }
        UNLOCK();
        bVar10 = uVar8 != uVar7;
        uVar7 = uVar8;
      } while (bVar10);
      if (uVar8 == 0) {
        IoQueueWorkItem(*(undefined8 *)(lVar5 + 0xd8),NVhdIoReplayWorkItemRoutine,1,lVar5);
        return;
      }
      return;
    }
    if ((int)uVar6 == 0x103) {
      return;
    }
  }
  cVar3 = *(char *)(lVar9 + 3);
  *(char *)(lVar4 + 2) = cVar3;
  *(undefined1 *)(lVar4 + 3) = *(undefined1 *)(lVar9 + 4);
  *(undefined1 *)(lVar4 + 9) = *(undefined1 *)(lVar9 + 0xb);
  *(undefined4 *)(lVar4 + 0xc) = *(undefined4 *)(lVar9 + 0x10);
  if (param_2 < 0) {
    if (cVar3 == '\x01') {
      *(undefined1 *)(lVar4 + 2) = 4;
    }
  }
  else if (*(char *)(lVar9 + 0x48) == '\x12') {
    *(byte *)(lVar4 + 0xb) = *(byte *)(lVar4 + 0xb) | 3;
  }
  lVar9 = *param_1;
  lVar4 = *(longlong *)(lVar9 + 0x58);
  if ((*(char *)(lVar4 + 0x17) != '\0') && (*(char *)((longlong)param_1 + 0x2b) == '\0')) {
    LOCK();
    piVar2 = (int *)(lVar4 + 0xb8);
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    ExReleaseRundownProtection(*(longlong *)(lVar9 + 0x58) + 0xc0);
  }
  VstorCompleteScsiRequest(param_1);
  return;
}



===== NVhdParserSupportsDataTransferDirectionValidation @ 1c00017a0 =====

undefined1 NVhdParserSupportsDataTransferDirectionValidation(void)

{
  return 1;
}



===== NVhdContextInitialize @ 1c00017b0 =====

int NVhdContextInitialize(longlong *param_1,undefined1 param_2,longlong *param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  longlong local_res18;
  
  local_res18 = 0;
  iVar3 = ObReferenceObjectByHandle
                    (*param_3,0,*(undefined8 *)IoFileObjectType_exref,0,&local_res18,0);
  lVar2 = local_res18;
  if (-1 < iVar3) {
    lVar4 = IoGetRelatedDeviceObject(local_res18);
    lVar4 = IoAllocateIrp(*(undefined1 *)(lVar4 + 0x4c),0);
    param_1[10] = lVar4;
    if (lVar4 != 0) {
      lVar4 = IoGetRelatedDeviceObject(lVar2);
      lVar4 = IoAllocateIrp(*(undefined1 *)(lVar4 + 0x4c),0);
      param_1[0xc] = lVar4;
      if (lVar4 != 0) {
        lVar4 = ExAllocatePool2(0x40,0x480,0x63705656);
        param_1[0xd] = lVar4;
        if (lVar4 != 0) {
          lVar4 = IoGetRelatedDeviceObject(lVar2);
          lVar4 = IoAllocateIrp(*(undefined1 *)(lVar4 + 0x4c),0);
          param_1[0x11] = lVar4;
          if (lVar4 != 0) {
            *(undefined4 *)(param_1 + 0x1e) = 0;
            param_1[0x1d] = 0;
            KeInitializeEvent(param_1 + 0x21,0,1);
            lVar4 = IoGetRelatedDeviceObject(lVar2);
            lVar4 = IoAllocateIrp(*(undefined1 *)(lVar4 + 0x4c),0);
            param_1[0x20] = lVar4;
            if (lVar4 != 0) {
              param_1[0x1c] = 0;
              ExInitializeRundownProtection(param_1 + 0x18);
              uVar1 = NVhdDriverObject;
              param_1[0x15] = 0;
              *(undefined4 *)(param_1 + 0x16) = 0;
              *(undefined4 *)(param_1 + 0x17) = 0;
              lVar4 = IoAllocateWorkItem(uVar1);
              param_1[0x1b] = lVar4;
              if (lVar4 != 0) {
                param_1[0x19] = 0;
                param_1[0x1a] = 0;
                DvReleaseRundownBarrier(param_1 + 0x19,'\x01');
                *(undefined1 *)((longlong)param_1 + 0x13) = param_2;
                *param_1 = *param_3;
                *param_3 = 0;
                param_1[1] = lVar2;
                return iVar3;
              }
            }
          }
        }
      }
    }
    iVar3 = -0x3fffff66;
  }
  if (lVar2 != 0) {
    ObfDereferenceObject(lVar2);
  }
  if (iVar3 < 0) {
    NVhdContextCleanup(param_1);
  }
  return iVar3;
}



===== NVhdIoInvokeIoctl @ 1c00019e0 =====

ulonglong NVhdIoInvokeIoctl(undefined8 param_1,undefined4 param_2,undefined8 param_3,
                           undefined4 param_4,undefined8 param_5,undefined4 param_6,
                           undefined8 *param_7)

{
  undefined8 uVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_38 = 0;
  uStack_30 = 0;
  if (param_7 != (undefined8 *)0x0) {
    *param_7 = 0;
  }
  KeInitializeEvent(&local_28,1);
  uVar1 = IoGetRelatedDeviceObject(param_1);
  lVar2 = IoBuildDeviceIoControlRequest
                    (param_2,uVar1,param_3,param_4,param_5,param_6,0,&local_28,&local_38);
  if (lVar2 == 0) {
    uVar3 = 0xc000009a;
  }
  else {
    *(undefined8 *)(*(longlong *)(lVar2 + 0xb8) + -0x18) = param_1;
    uVar1 = IoGetRelatedDeviceObject(param_1);
    uVar3 = IofCallDriver(uVar1,lVar2);
    if (-1 < (int)uVar3) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
      if (param_7 != (undefined8 *)0x0) {
        *param_7 = uStack_30;
      }
      uVar3 = local_38 & 0xffffffff;
    }
  }
  return uVar3;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 1c0001b40 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_1c000605f < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== NVhdParserSetOptimizationsCompletionRoutine @ 1c0001b70 =====

undefined8
NVhdParserSetOptimizationsCompletionRoutine(undefined8 param_1,longlong param_2,longlong param_3)

{
  *(undefined4 *)(param_3 + 0x120) = *(undefined4 *)(param_2 + 0x30);
  KeSetEvent(param_3 + 0x108,0,0);
  return 0xc0000016;
}



===== __report_gsfailure @ 1c0001bc0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== NVhdContextCleanup @ 1c0001bd0 =====

void NVhdContextCleanup(longlong *param_1)

{
  if (param_1[0x20] != 0) {
    IoCancelIrp();
    KeWaitForSingleObject(param_1 + 0x21,0,0,0,0);
    IoFreeIrp(param_1[0x20]);
    param_1[0x20] = 0;
  }
  if (param_1[0x11] != 0) {
    IoFreeIrp();
    param_1[0x11] = 0;
  }
  if (param_1[10] != 0) {
    IoFreeIrp();
    param_1[10] = 0;
  }
  if (param_1[0xc] != 0) {
    IoFreeIrp();
    param_1[0xc] = 0;
  }
  if (param_1[0xd] != 0) {
    ExFreePoolWithTag(param_1[0xd],0x63705656);
    param_1[0xd] = 0;
  }
  if (param_1[0x1b] != 0) {
    IoFreeWorkItem();
    param_1[0x1b] = 0;
  }
  if (param_1[1] != 0) {
    ObfDereferenceObject();
    param_1[1] = 0;
  }
  if (*param_1 != 0) {
    ZwClose();
    *param_1 = 0;
  }
  return;
}



===== NVhdIoInvokeVhdmpIoctlForwardProgress @ 1c0001d00 =====

undefined4
NVhdIoInvokeVhdmpIoctlForwardProgress(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  void *pvVar4;
  undefined8 uVar5;
  
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_1 + 0x58,0);
  lVar2 = *(longlong *)(param_1 + 0x50);
  IoReuseIrp(lVar2,0x103);
  pvVar4 = SystemReserved1[0xf];
  *(uint *)(lVar2 + 0x10) = *(uint *)(lVar2 + 0x10) | 1;
  lVar3 = *(longlong *)(lVar2 + 0xb8);
  *(void **)(lVar2 + 0x98) = pvVar4;
  *(undefined8 *)(lVar3 + -0x18) = *(undefined8 *)(param_1 + 8);
  uVar5 = IoGetRelatedDeviceObject();
  *(undefined4 *)(lVar3 + -0x40) = 0;
  *(undefined8 *)(lVar3 + -0x20) = uVar5;
  *(undefined1 *)(lVar3 + -0x48) = 0xe;
  *(undefined4 *)(lVar3 + -0x30) = 0x2d1920;
  *(undefined4 *)(lVar3 + -0x38) = 0xc;
  *(undefined8 *)(lVar2 + 0x18) = param_3;
  IoSynchronousCallDriver(*(undefined8 *)(lVar3 + -0x20),lVar2);
  uVar1 = *(undefined4 *)(lVar2 + 0x30);
  ExReleasePushLockExclusiveEx(param_1 + 0x58,0);
  KeLeaveCriticalRegion();
  return uVar1;
}



===== NVhdParserMetaOpIoCompletion @ 1c0001e00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 NVhdParserMetaOpIoCompletion(undefined8 param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  lVar1 = *(longlong *)(param_3 + 0x18);
  uVar2 = *(undefined4 *)(param_2 + 0x34);
  uVar3 = *(undefined4 *)(param_2 + 0x38);
  uVar4 = *(undefined4 *)(param_2 + 0x3c);
  *(undefined4 *)(lVar1 + 8) = *(undefined4 *)(param_2 + 0x30);
  *(undefined4 *)(lVar1 + 0xc) = uVar2;
  *(undefined4 *)(lVar1 + 0x10) = uVar3;
  *(undefined4 *)(lVar1 + 0x14) = uVar4;
  (**(code **)(param_3 + 8))(*(undefined8 *)(param_3 + 0x10));
  return 0xc0000016;
}



===== DriverEntry @ 1c0001e30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DriverEntry(longlong param_1,ushort *param_2)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined2 uVar7;
  undefined1 auStack_1a8 [48];
  short *local_178 [2];
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  longlong local_150;
  code *local_148;
  code *local_140;
  code *local_138;
  code *local_130;
  code *local_128;
  code *local_120;
  code *local_118;
  code *local_110;
  code *local_108;
  code *local_100;
  code *local_f8;
  code *local_f0;
  code *local_e0;
  code *local_d8;
  code *local_d0;
  code *local_c8;
  code *local_c0;
  code *local_b8;
  code *local_b0;
  code *local_a8;
  code *local_88;
  code *local_80;
  code *local_78;
  code *local_70;
  code *local_68;
  code *local_60;
  code *local_58;
  code *local_48;
  code *local_40;
  code *local_38;
  code *local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_1a8;
  memset(&local_168,0,0x140);
  _DAT_1c0007188 = 1;
  local_178[0] = (short *)0x0;
  DAT_1c0007168 = &WPP_ThisDir_CTLGUID_VhdparserTraceGuid;
  _WPP_MAIN_CB = 0;
  DAT_1c0007170 = 0;
  _DAT_1c0007180 = 0;
  _DAT_1c00071a0 = 0;
  _DAT_1c00071a8 = 0;
  WppLoadTracingSupport();
  _DAT_1c0007180 = 0;
  WppInitKm(param_1,param_2);
  wil_InitializeFeatureStaging();
  TraceLoggingRegisterEx_EtwRegister_EtwSetInformation();
  NVhdDriverObject = param_1;
  lVar3 = ExAllocatePool2(0x100,*param_2);
  if (lVar3 == 0) {
    uVar5 = 0xc000009a;
  }
  else {
    _NVhdParserRegistryPath = (ulonglong)*param_2 << 0x10;
    DAT_1c00071c8 = lVar3;
    RtlCopyUnicodeString(&NVhdParserRegistryPath,param_2);
    uVar6 = 0;
    *(code **)(param_1 + 0x68) = NVhdParserDriverUnload;
    iVar1 = IoGetDeviceInterfaces(&GUID_STORVSP,0,0,local_178);
    if ((iVar1 < 0) || (*local_178[0] == 0)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar6,0xc);
      }
      uVar5 = 0xc0000001;
    }
    else {
      uVar4 = NVhdParserRegisterWithVhdmp();
      uVar5 = uVar4 & 0xffffffff;
      if ((int)uVar4 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar7 = 0xd;
LAB_1c0001fa3:
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar6,uVar7);
        }
      }
      else {
        local_168 = 0x140;
        local_148 = NVhdParserOpenDisk;
        local_164 = 6;
        local_140 = NVhdParserCloseDisk;
        local_138 = NVhdParserFastCloseDisk;
        local_130 = NVhdParserMountDisk;
        local_128 = NVhdParserDismountDisk;
        local_120 = NVhdParserQueryMountStatusDisk;
        local_118 = NVhdParserExecuteScsiRequestDisk;
        local_110 = NVhdParserQueryInformationDisk;
        local_108 = NVhdParserQuerySaveVersionDisk;
        local_100 = NVhdParserSaveDisk;
        local_f8 = NVhdParserRestoreDisk;
        local_30 = NVhdParserRestoreDiskWithHint;
        local_f0 = NVhdParserSetBehavior;
        local_e0 = NVhdParserSetQoSPolicyDisk;
        local_d8 = NVhdParserGetQoSStatusDisk;
        local_c8 = NVhdParserChangeTrackingGetParameters;
        local_d0 = NVhdParserChangeTrackingSetParameters;
        local_c0 = NVhdParserChangeTrackingStart;
        local_b8 = NVhdParserChangeTrackingStop;
        local_b0 = NVhdParserChangeTrackingSwitchLogs;
        local_a8 = NVhdParserEnableResiliency;
        local_88 = NVhdParserPrepareMetaOperation;
        local_80 = NVhdParserStartMetaOperation;
        local_78 = NVhdParserCancelMetaOperation;
        local_68 = NVhdParserCleanUpMetaOperation;
        local_70 = NVhdParserQueryMetaOperationProgress;
        local_60 = NVhdParserDeleteSnapshot;
        local_58 = NVhdParserQueryChanges;
        local_48 = NVhdParserSupportsDataTransferDirectionValidation;
        local_40 = NVhdParserRecoverDisk;
        local_38 = NVhdParserCancelDiskRecovery;
        local_160 = 0xf916c826;
        uStack_15c = 0x4cd9f0f5;
        uStack_158 = 0xd64f68be;
        uStack_154 = 0x539acf38;
        local_150 = param_1;
        uVar2 = VstorRegisterParser(&local_168);
        uVar5 = (ulonglong)uVar2;
        if (-1 < (int)uVar2) {
          uVar5 = 0;
          goto LAB_1c00021e0;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar7 = 0xe;
          goto LAB_1c0001fa3;
        }
      }
    }
  }
  uVar6 = DAT_1c0007030;
  DAT_1c0007030 = 0;
  DAT_1c0007010 = 0;
  EtwUnregister(uVar6);
  WppCleanupKm(param_1);
  if (lVar3 != 0) {
    ExFreePoolWithTag(lVar3,0x70705656);
  }
  wil_UninitializeFeatureStaging();
LAB_1c00021e0:
  if (local_178[0] != (short *)0x0) {
    ExFreePoolWithTag(local_178[0],0);
  }
  return uVar5;
}



===== NVhdParserCancelMetaOperation @ 1c0002230 =====

void NVhdParserCancelMetaOperation(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x20) != 0) {
    IoCancelIrp();
  }
  return;
}



===== NVhdParserCleanUpMetaOperation @ 1c0002260 =====

void NVhdParserCleanUpMetaOperation(longlong param_1)

{
  longlong lVar1;
  
  if (*(longlong *)(param_1 + 0x20) != 0) {
    lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x20) + 0x18);
    if (lVar1 != 0) {
      ExFreePoolWithTag(lVar1,0x70705656);
    }
    IoFreeIrp(*(undefined8 *)(param_1 + 0x20));
  }
  ExFreePoolWithTag(param_1,0x70705656);
  return;
}



===== NVhdParserDiskRecoveryCompletionRoutine @ 1c00022c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
NVhdParserDiskRecoveryCompletionRoutine(undefined8 param_1,longlong param_2,longlong param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  
  pcVar1 = *(code **)(param_3 + 0x90);
  uVar2 = *(undefined8 *)(param_3 + 0x98);
  *(undefined8 *)(param_3 + 0x90) = 0;
  *(undefined8 *)(param_3 + 0x98) = 0;
  (*pcVar1)(uVar2,*(undefined4 *)(param_2 + 0x30));
  return 0xc0000016;
}



===== NVhdParserDriverUnload @ 1c0002300 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void NVhdParserDriverUnload(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,0xf);
  }
  if (VhdmpHandle != 0) {
    ZwClose();
    VhdmpHandle = 0;
  }
  if (DAT_1c00071b8 != 0) {
    ExFreePoolWithTag(DAT_1c00071b8,0x70705656);
    _VhdmpBaseName = 0;
    DAT_1c00071b8 = 0;
  }
  if (DAT_1c00071c8 != 0) {
    ExFreePoolWithTag(DAT_1c00071c8,0x70705656);
  }
  uVar1 = DAT_1c0007030;
  DAT_1c0007030 = 0;
  DAT_1c0007010 = 0;
  EtwUnregister(uVar1);
  wil_UninitializeFeatureStaging();
  WppCleanupKm(param_1);
  return;
}



===== NVhdParserIsRdssdToAbcMigrationEnabled @ 1c00023d4 =====

void NVhdParserIsRdssdToAbcMigrationEnabled(undefined8 param_1)

{
  int iVar1;
  char local_res10 [24];
  
  local_res10[0] = '\0';
  iVar1 = NVhdParserCheckPolicyValue(L"RdssdToAbcMigration",0,local_res10);
  if (-1 < iVar1) {
    *(bool *)param_1 = local_res10[0] != '\0';
  }
  return;
}



===== NVhdParserQoSStatusRequestCompletion @ 1c0002410 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
NVhdParserQoSStatusRequestCompletion(undefined8 param_1,longlong param_2,longlong param_3)

{
  (**(code **)(param_3 + 0x70))
            (*(undefined4 *)(param_2 + 0x30),*(undefined8 *)(param_3 + 0x68),
             *(undefined8 *)(param_3 + 0x78));
  return 0xc0000016;
}



===== RtlUnicodeStringCatString @ 1c000243c =====

undefined4 RtlUnicodeStringCatString(ushort *param_1)

{
  ushort uVar1;
  ushort uVar2;
  longlong lVar3;
  undefined4 uVar4;
  short sVar5;
  short *psVar6;
  longlong lVar7;
  longlong lVar8;
  
  uVar1 = *param_1;
  if ((((((uVar1 & 1) != 0) || (uVar2 = param_1[1], (uVar2 & 1) != 0)) || (uVar2 < uVar1)) ||
      (uVar2 == 0xffff)) ||
     ((uVar4 = 0, *(longlong *)(param_1 + 4) == 0 && ((uVar1 != 0 || (uVar2 != 0)))))) {
    return 0xc000000d;
  }
  psVar6 = (short *)&u__;
  lVar3 = *(longlong *)(param_1 + 4);
  lVar8 = 0x7fff;
  sVar5 = 0;
  uVar1 = uVar1 >> 1;
  lVar7 = (ulonglong)(param_1[1] >> 1) - (ulonglong)uVar1;
  if (lVar7 != 0) {
    do {
      if (lVar8 == 0) goto LAB_1c00024f1;
      if (*psVar6 == 0) break;
      *(short *)(lVar3 + (ulonglong)uVar1 * 2 + -0x1c000516c + (longlong)psVar6) = *psVar6;
      lVar8 = lVar8 + -1;
      psVar6 = psVar6 + 1;
      sVar5 = sVar5 + 1;
      lVar7 = lVar7 + -1;
    } while (lVar7 != 0);
    if ((lVar7 != 0) || (lVar8 == 0)) goto LAB_1c00024f1;
  }
  uVar4 = 0;
  if (*psVar6 != 0) {
    uVar4 = 0x80000005;
  }
LAB_1c00024f1:
  *param_1 = (uVar1 + sVar5) * 2;
  return uVar4;
}



===== WPP_RECORDER_SF_ @ 1c0002518 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_4605422d6faf3fda7dc6938031c5904e_Traceguids,param_4,0);
  }
  WppAutoLogTrace(param_1,param_2,1,&WPP_4605422d6faf3fda7dc6938031c5904e_Traceguids,param_4,0);
  return;
}



===== WPP_RECORDER_SF_d @ 1c00025ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_d(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_4605422d6faf3fda7dc6938031c5904e_Traceguids,param_4,&param_6,4,0);
  }
  WppAutoLogTrace(param_1,2,2,&WPP_4605422d6faf3fda7dc6938031c5904e_Traceguids,param_4,&param_6,4,0)
  ;
  return;
}



===== WppClassicProviderCallback @ 1c0002660 =====

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



===== _tlgDefineProvider_annotation__TlgStorageActivityProviderProv @ 1c00026bc =====

void _tlgDefineProvider_annotation__TlgStorageActivityProviderProv(void)

{
  return;
}



===== wil_details_RecordCachedUsage @ 1c00026c8 =====

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



===== wil_details_RecordFeatureUsageReporting @ 1c0002820 =====

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



===== DvEnterRundownBarrier @ 1c00028a4 =====

undefined8 DvEnterRundownBarrier(longlong *param_1,longlong *param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong *plVar4;
  bool bVar5;
  
  lVar1 = *param_1;
  do {
    if (lVar1 < 1) {
      if ((lVar1 == -1) || (param_2 == (longlong *)0x0)) {
        return 0xc0000001;
      }
      *param_2 = lVar1;
      uVar3 = 0x103;
      plVar4 = param_2;
    }
    else {
      uVar3 = 0;
      plVar4 = (longlong *)(lVar1 + 1);
    }
    LOCK();
    if (lVar1 == *param_1) {
      *param_1 = (longlong)plVar4;
      lVar2 = lVar1;
    }
    else {
      lVar2 = *param_1;
    }
    UNLOCK();
    bVar5 = lVar2 != lVar1;
    lVar1 = lVar2;
  } while (bVar5);
  return uVar3;
}



===== DvExitRundownBarrier @ 1c00028f4 =====

void DvExitRundownBarrier(longlong *param_1)

{
  DvExitRundownBarrierEx(param_1);
  return;
}



===== DvExitRundownBarrierEx @ 1c000290c =====

void DvExitRundownBarrierEx(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  
  lVar1 = *param_1;
  do {
    if (lVar1 < 1) {
      DvpExitClosedRundownBarrier((longlong)param_1);
      return;
    }
    LOCK();
    if (lVar1 == *param_1) {
      *param_1 = lVar1 + -1;
      lVar2 = lVar1;
    }
    else {
      lVar2 = *param_1;
    }
    UNLOCK();
    bVar3 = lVar1 != lVar2;
    lVar1 = lVar2;
  } while (bVar3);
  return;
}



===== DvReleaseRundownBarrier @ 1c0002940 =====

undefined8 * DvReleaseRundownBarrier(longlong *param_1,char param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  longlong lVar3;
  
  LOCK();
  puVar2 = (undefined8 *)*param_1;
  *param_1 = (ulonglong)(-(uint)(param_2 != '\0') & 2) - 1;
  UNLOCK();
  if ((longlong)puVar2 - 1U < 0xfffffffffffffffe) {
    puVar2 = (undefined8 *)DvReverseList(puVar2);
    if (param_2 != '\0') {
      lVar3 = 0;
      for (puVar1 = puVar2; puVar1 != (undefined8 *)0x0; puVar1 = (undefined8 *)*puVar1) {
        lVar3 = lVar3 + 1;
      }
      LOCK();
      *param_1 = *param_1 + lVar3;
      UNLOCK();
    }
  }
  else {
    puVar2 = (undefined8 *)0x0;
  }
  return puVar2;
}



===== DvWaitRundownBarrier @ 1c0002998 =====

void DvWaitRundownBarrier(longlong *param_1,char param_2)

{
  longlong lVar1;
  longlong local_28 [4];
  
  local_28[3] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  if (((param_2 == '\0') || (0 < *param_1)) || (*param_1 == -1)) {
    local_28[0] = -1;
    param_1[1] = (longlong)local_28;
    LOCK();
    lVar1 = *param_1;
    *param_1 = (ulonglong)(param_2 != '\0') - 1;
    UNLOCK();
    if (1 < lVar1) {
      KeInitializeEvent(local_28 + 1,1);
      LOCK();
      UNLOCK();
      if (lVar1 + local_28[0] != 0) {
        local_28[0] = local_28[0] + lVar1;
        KeWaitForSingleObject(local_28 + 1,0,0,0,0);
      }
    }
    param_1[1] = 0;
  }
  else {
    LOCK();
    UNLOCK();
  }
  return;
}



===== DvpExitClosedRundownBarrier @ 1c0002a50 =====

void DvpExitClosedRundownBarrier(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  
  plVar2 = *(longlong **)(param_1 + 8);
  LOCK();
  lVar1 = *plVar2;
  *plVar2 = *plVar2 + -1;
  UNLOCK();
  if (lVar1 == 1) {
    KeSetEvent(plVar2 + 1,0,0);
  }
  return;
}



===== DvRemoveOrderedWorkQueue @ 1c0002a88 =====

void DvRemoveOrderedWorkQueue(ulonglong *param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  bool bVar4;
  
  uVar1 = *param_1;
  do {
    if ((uVar1 & 2) != 0) {
      puVar3 = (undefined8 *)DvpRemoveWorkQueueRunningDown((longlong *)param_1);
      break;
    }
    puVar3 = (undefined8 *)(uVar1 & 0xfffffffffffffffe);
    LOCK();
    if (uVar1 == *param_1) {
      *param_1 = (ulonglong)(puVar3 != (undefined8 *)0x0);
      uVar2 = uVar1;
    }
    else {
      uVar2 = *param_1;
    }
    UNLOCK();
    bVar4 = uVar2 != uVar1;
    uVar1 = uVar2;
  } while (bVar4);
  DvReverseList(puVar3);
  return;
}



===== DvpRemoveWorkQueueRunningDown @ 1c0002ad8 =====

longlong DvpRemoveWorkQueueRunningDown(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *param_1;
  lVar2 = *(longlong *)(lVar1 + 0x16);
  *(undefined8 *)(lVar1 + 0x16) = 0;
  if (lVar2 == 0) {
    *param_1 = 0;
    KeSetEvent(lVar1 + -2,0,0);
  }
  return lVar2;
}



===== DvReverseList @ 1c0002b1c =====

void DvReverseList(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)0x0;
  while (puVar1 = param_1, puVar1 != (undefined8 *)0x0) {
    param_1 = (undefined8 *)*puVar1;
    *puVar1 = puVar2;
    puVar2 = puVar1;
  }
  return;
}



===== _guard_check_icall @ 1c0002b50 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0002b68 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c0002b8c =====

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



===== __cpu_features_init @ 1c0002c00 =====

/* WARNING: Removing unreachable block (ram,0x0001c0002c6a) */
/* WARNING: Removing unreachable block (ram,0x0001c0002c19) */
/* WARNING: Removing unreachable block (ram,0x0001c0002c0a) */

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



===== __security_check_cookie @ 1c0002cd0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0002d10 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0002d40 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0002d40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0002d70 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0002dc0 =====

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



===== memset @ 1c00030c0 =====

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



===== __memset_repmovs @ 1c0003200 =====

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



===== __memset_query @ 1c0003280 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0003300 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0003440 =====

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



===== __memset_spec_plain @ 1c00034c0 =====

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



===== NVhdIoReplayWorkItemRoutine @ 1c000a010 =====

void NVhdIoReplayWorkItemRoutine(undefined8 param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)DvRemoveOrderedWorkQueue((ulonglong *)(param_2 + 0xe0));
  while (puVar2 != (undefined8 *)0x0) {
    puVar1 = puVar2 + -1;
    puVar2 = (undefined8 *)*puVar2;
    NVhdParserIssueScsiRequest(param_2,(longlong *)*puVar1);
    DvExitRundownBarrier((longlong *)(param_2 + 200));
  }
  return;
}



===== NVhdIoInvokeMetaOpIoctl @ 1c000a070 =====

undefined8 NVhdIoInvokeMetaOpIoctl(longlong *param_1,undefined4 param_2,void *param_3,uint param_4)

{
  longlong lVar1;
  longlong lVar2;
  void *_Dst;
  undefined8 uVar3;
  undefined4 uVar4;
  
  lVar1 = param_1[4];
  uVar3 = *(undefined8 *)(*param_1 + 8);
  lVar2 = *(longlong *)(lVar1 + 0xb8);
  *(undefined4 *)(lVar2 + -0x40) = 0;
  *(undefined1 *)(lVar2 + -0x48) = 0xe;
  *(undefined8 *)(lVar2 + -0x18) = uVar3;
  *(uint *)(lVar2 + -0x38) = param_4;
  *(undefined4 *)(lVar2 + -0x30) = param_2;
  if (param_4 == 0) {
    uVar4 = 0;
  }
  else {
    _Dst = (void *)ExAllocatePool2(0x48,(ulonglong)param_4,0x6d705656);
    *(void **)(lVar1 + 0x18) = _Dst;
    if (_Dst == (void *)0x0) {
      return 0xc000009a;
    }
    if (param_3 != (void *)0x0) {
      memcpy(_Dst,param_3,(ulonglong)param_4);
    }
    uVar4 = 0x10;
  }
  *(undefined4 *)(lVar1 + 0x10) = uVar4;
  *(undefined8 *)(lVar1 + 0x70) = 0;
  lVar2 = param_1[3];
  *(undefined8 *)(lVar1 + 0x50) = 0;
  *(longlong *)(lVar1 + 0x48) = lVar2 + 8;
  *(undefined1 *)(lVar1 + 0x40) = 0;
  *(void **)(lVar1 + 0x98) = SystemReserved1[0xf];
  lVar2 = *(longlong *)(lVar1 + 0xb8);
  *(code **)(lVar2 + -0x10) = NVhdParserMetaOpIoCompletion;
  *(longlong **)(lVar2 + -8) = param_1;
  *(undefined1 *)(lVar2 + -0x45) = 0xe0;
  uVar3 = IoGetRelatedDeviceObject(uVar3,0,uVar4,lVar1);
  IofCallDriver(uVar3,lVar1);
  return 0x103;
}



===== NVhdParserCdpSnapshot @ 1c000a1ac =====

ulonglong NVhdParserCdpSnapshot(longlong *param_1)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined4 *puVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  longlong local_res8;
  
  lVar3 = param_1[3];
  local_res8 = 0;
  if (*(uint *)(lVar3 + 0x18) < 4) {
    return 0xc0000206;
  }
  puVar4 = *(undefined4 **)(lVar3 + 0x20);
  if (*(int *)(lVar3 + 0x5c) != 100) {
    return 0xc000000d;
  }
  uVar1 = *(uint *)(lVar3 + 0x60);
  puVar7 = (undefined4 *)ExAllocatePool2(0x40,(ulonglong)uVar1 + 0x30,0x6d705656);
  if (puVar7 == (undefined4 *)0x0) {
    return 0xc000009a;
  }
  iVar2 = *(int *)(lVar3 + 0x30);
  if (iVar2 == 1) {
    puVar7[6] = 1;
  }
  else if (iVar2 == 2) {
    puVar7[6] = 2;
  }
  else if (iVar2 == 3) {
    if (*(int *)(lVar3 + 0x34) != 4) {
LAB_1c000a2c5:
      uVar9 = 0xc000000d;
      goto LAB_1c000a2ca;
    }
    puVar7[6] = 3;
  }
  else {
    if (iVar2 != 5) goto LAB_1c000a2c5;
    puVar7[6] = 4;
  }
  puVar7[7] = *(undefined4 *)(lVar3 + 0x78);
  uVar5 = *(undefined8 *)(lVar3 + 0x84);
  *(undefined8 *)(puVar7 + 8) = *(undefined8 *)(lVar3 + 0x7c);
  *(undefined8 *)(puVar7 + 10) = uVar5;
  uVar5 = *(undefined8 *)(lVar3 + 100);
  uVar6 = *(undefined8 *)(lVar3 + 0x6c);
  puVar7[1] = uVar1;
  *puVar7 = 0x30;
  *(undefined8 *)(puVar7 + 2) = uVar5;
  *(undefined8 *)(puVar7 + 4) = uVar6;
  memcpy(puVar7 + 0xc,(void *)(lVar3 + 0x8c),(ulonglong)uVar1);
  uVar8 = NVhdParserChangeTrackingSwitchLogsInternal
                    (*(undefined8 *)(*param_1 + 8),(longlong)puVar7,puVar4,&local_res8);
  uVar9 = uVar8 & 0xffffffff;
  if (-1 < (int)uVar8) {
    if (local_res8 == 4) {
      *(undefined8 *)(param_1[3] + 0x10) = 4;
    }
    else {
      uVar9 = 0xc0000206;
    }
  }
LAB_1c000a2ca:
  ExFreePoolWithTag(puVar7,0x6d705656);
  return uVar9;
}



===== NVhdParserExtractVhd @ 1c000a300 =====

ulonglong NVhdParserExtractVhd(longlong *param_1,longlong param_2)

{
  undefined8 uVar1;
  uint uVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  
  uVar2 = *(int *)(param_2 + 0x2c) + 0x28;
  if (uVar2 < 0x28) {
    uVar4 = 0xc0000095;
  }
  else {
    puVar3 = (undefined8 *)ExAllocatePool2(0x40,uVar2,0x6d705656);
    if (puVar3 == (undefined8 *)0x0) {
      uVar4 = 0xc000009a;
    }
    else {
      uVar1 = *(undefined8 *)(param_2 + 0x10);
      *puVar3 = *(undefined8 *)(param_2 + 8);
      puVar3[1] = uVar1;
      uVar1 = *(undefined8 *)(param_2 + 0x20);
      puVar3[2] = *(undefined8 *)(param_2 + 0x18);
      puVar3[3] = uVar1;
      *(undefined4 *)((longlong)puVar3 + 0x24) = *(undefined4 *)(param_2 + 0x2c);
      *(undefined4 *)(puVar3 + 4) = 0x28;
      memcpy(puVar3 + 5,(void *)((ulonglong)*(uint *)(param_2 + 0x28) + param_2),
             (ulonglong)*(uint *)(param_2 + 0x2c));
      uVar4 = NVhdIoInvokeMetaOpIoctl(param_1,0x2d1a60,puVar3,uVar2);
      uVar4 = uVar4 & 0xffffffff;
      ExFreePoolWithTag(puVar3,0x6d705656);
    }
  }
  return uVar4;
}



===== NVhdParserMetaOpDispatch @ 1c000a3d4 =====

ulonglong NVhdParserMetaOpDispatch(longlong *param_1)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  ulonglong uVar4;
  undefined4 uVar5;
  int *piVar6;
  uint uVar7;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined2 local_28;
  undefined2 uStack_26;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  int iStack_14;
  
  piVar3 = (int *)param_1[3];
  iVar2 = *piVar3;
  if (iVar2 == 0) {
    sVar1 = (short)piVar3[10];
    if (sVar1 != 1) {
      if (sVar1 == 3) {
        uVar4 = NVhdParserCdpSnapshot(param_1);
        return uVar4;
      }
      if (sVar1 != 4) {
        return 0xc00000bb;
      }
    }
    uVar4 = NVhdParserVmSnapshot(param_1);
  }
  else {
    if (iVar2 == 1) {
      piVar6 = piVar3 + 10;
      uVar5 = 0x2d1950;
      uVar7 = 0x10;
    }
    else if (iVar2 == 2) {
      uVar7 = 0;
      uVar5 = 0x2d1a5c;
      piVar6 = (int *)0x0;
    }
    else {
      if (iVar2 == 3) {
        if (((short)piVar3[10] == 1) && (piVar3[0xb] == 0)) {
          uVar4 = NVhdParserExtractVhd(param_1,(longlong)(piVar3 + 10));
          return uVar4;
        }
        return 0xc000000d;
      }
      if (iVar2 != 5) {
        return 0xc00000bb;
      }
      uVar7 = 0x38;
      iStack_14 = piVar3[0x13];
      uVar5 = 0x2d1a68;
      uStack_26 = 0;
      local_28 = (undefined2)piVar3[0xe];
      local_38 = 0;
      uStack_30 = 0;
      local_48 = *(undefined8 *)(piVar3 + 10);
      uStack_40 = *(undefined8 *)(piVar3 + 0xc);
      piVar6 = (int *)&local_48;
      uStack_24 = (undefined4)*(undefined8 *)(piVar3 + 0xf);
      uStack_20 = (undefined4)((ulonglong)*(undefined8 *)(piVar3 + 0xf) >> 0x20);
      uStack_1c = (undefined4)*(undefined8 *)(piVar3 + 0x11);
      local_18 = (undefined4)((ulonglong)*(undefined8 *)(piVar3 + 0x11) >> 0x20);
    }
    uVar4 = NVhdIoInvokeMetaOpIoctl(param_1,uVar5,piVar6,uVar7);
  }
  return uVar4;
}



===== NVhdParserVmSnapshot @ 1c000a4d8 =====

undefined8 NVhdParserVmSnapshot(longlong *param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 uStack_14;
  undefined2 uStack_12;
  
  lVar1 = param_1[3];
  if (*(int *)(lVar1 + 0x30) == 1) {
    local_28 = *(undefined4 *)(lVar1 + 0x48);
    uStack_24 = *(undefined4 *)(lVar1 + 0x4c);
    uStack_20 = *(undefined4 *)(lVar1 + 0x50);
    uStack_1c = *(undefined4 *)(lVar1 + 0x54);
    local_18 = *(undefined2 *)(lVar1 + 0x28);
    uVar3 = 0x2d1a44;
    uStack_14 = (undefined2)*(undefined4 *)(lVar1 + 0x2c);
    uStack_12 = (undefined2)((uint)*(undefined4 *)(lVar1 + 0x2c) >> 0x10);
  }
  else {
    if ((((*(int *)(lVar1 + 0x30) != 2) || (*(int *)(lVar1 + 0x34) != 3)) ||
        (*(int *)(lVar1 + 0x38) != 4)) || (*(int *)(lVar1 + 0x3c) != 5)) {
      return 0xc00000bb;
    }
    local_28 = *(undefined4 *)(lVar1 + 0x48);
    uStack_24 = *(undefined4 *)(lVar1 + 0x4c);
    uStack_20 = *(undefined4 *)(lVar1 + 0x50);
    uStack_1c = *(undefined4 *)(lVar1 + 0x54);
    uStack_14 = 0;
    uStack_12 = 0;
    local_18 = *(undefined2 *)(lVar1 + 0x28);
    uVar3 = 0x2d1a48;
  }
  local_16 = 0;
  local_38 = 0;
  uStack_30 = 0;
  uVar2 = NVhdIoInvokeMetaOpIoctl(param_1,uVar3,&local_38,0x28);
  return uVar2;
}



===== NVhdParserBeginPausingEmulatedIo @ 1c000a570 =====

undefined8 NVhdParserBeginPausingEmulatedIo(longlong param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  uVar3 = 0;
  if (*(char *)(param_1 + 0x17) == '\0') {
    uVar3 = 0;
  }
  else {
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(param_1 + 0xa8,0);
    if (*(int *)(param_1 + 0xb0) != 1) {
      if (*(int *)(param_1 + 0xb0) == 0) {
        DvWaitRundownBarrier((longlong *)(param_1 + 200),'\x01');
        if (0 < *(int *)(param_1 + 0xb8)) {
          uVar4 = 0;
          uVar2 = 0x2d1a28;
          uVar5 = 0;
          uVar1 = NVhdIoInvokeIoctl(*(undefined8 *)(param_1 + 8),0x2d1a28,0,0,0,0,(undefined8 *)0x0)
          ;
          if ((int)uVar1 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,uVar4,0xb,uVar5,
                                (char)uVar1);
            }
          }
          else {
            *(undefined1 *)(param_1 + 0xb4) = 1;
          }
        }
        *(undefined4 *)(param_1 + 0xb0) = 1;
      }
      else {
        uVar3 = 0xc0000184;
      }
    }
    ExReleasePushLockExclusiveEx(param_1 + 0xa8,0);
    KeLeaveCriticalRegion();
  }
  return uVar3;
}



===== NVhdParserCancelDiskRecovery @ 1c000a680 =====

void NVhdParserCancelDiskRecovery(longlong param_1)

{
  IoCancelIrp(*(undefined8 *)(param_1 + 0x88));
  return;
}



===== NVhdParserChangeTrackingGetParameters @ 1c000a6b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void NVhdParserChangeTrackingGetParameters(longlong param_1,undefined4 *param_2)

{
  ulonglong uVar1;
  undefined1 auStackY_68 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = 0;
  uStack_20 = 0;
  uVar1 = NVhdIoInvokeIoctl(*(undefined8 *)(param_1 + 8),0x2d1988,0,0,&local_28,0x10,
                            (undefined8 *)0x0);
  if (-1 < (int)uVar1) {
    *param_2 = (undefined4)local_28;
    *(undefined8 *)(param_2 + 2) = uStack_20;
  }
  return;
}



===== NVhdParserChangeTrackingSetParameters @ 1c000a730 =====

undefined8 NVhdParserChangeTrackingSetParameters(void)

{
  return 0xc0000002;
}



===== NVhdParserChangeTrackingStart @ 1c000a740 =====

ulonglong NVhdParserChangeTrackingStart(longlong param_1,longlong param_2)

{
  uint uVar1;
  undefined8 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  ulonglong uVar5;
  
  uVar1 = *(uint *)(param_2 + 4);
  uVar3 = uVar1 + 0x40;
  if (uVar3 < 0x40) {
    uVar5 = 0xc0000095;
  }
  else {
    puVar4 = (undefined4 *)ExAllocatePool2(0x100,uVar3,0x70705656);
    if (puVar4 == (undefined4 *)0x0) {
      uVar5 = 0xc000009a;
    }
    else {
      puVar4[1] = uVar1;
      *puVar4 = 0x40;
      *(undefined8 *)(puVar4 + 2) = *(undefined8 *)(param_2 + 0x18);
      uVar2 = *(undefined8 *)(param_2 + 0x10);
      *(undefined8 *)(puVar4 + 4) = *(undefined8 *)(param_2 + 8);
      *(undefined8 *)(puVar4 + 6) = uVar2;
      *(undefined1 *)(puVar4 + 8) = *(undefined1 *)(param_2 + 0x20);
      puVar4[10] = *(undefined4 *)(param_2 + 0x24);
      if (uVar1 != 0) {
        memcpy(puVar4 + 0x10,(void *)(param_2 + 0x28),(ulonglong)uVar1);
      }
      uVar5 = NVhdIoInvokeIoctl(*(undefined8 *)(param_1 + 8),0x2d197c,puVar4,uVar3,0,0,
                                (undefined8 *)0x0);
      uVar5 = uVar5 & 0xffffffff;
      ExFreePoolWithTag(puVar4,0x70705656);
    }
  }
  return uVar5;
}



===== NVhdParserChangeTrackingStop @ 1c000a840 =====

void NVhdParserChangeTrackingStop(longlong param_1,undefined4 *param_2,undefined4 *param_3)

{
  ulonglong uVar1;
  undefined4 local_res8 [2];
  undefined4 local_res10 [6];
  
  local_res10[0] = *param_2;
  local_res8[0] = 0;
  uVar1 = NVhdIoInvokeIoctl(*(undefined8 *)(param_1 + 8),0x2d1980,local_res10,4,local_res8,4,
                            (undefined8 *)0x0);
  if (-1 < (int)uVar1) {
    *param_3 = local_res8[0];
  }
  return;
}



===== NVhdParserChangeTrackingSwitchLogs @ 1c000a8a0 =====

void NVhdParserChangeTrackingSwitchLogs(longlong param_1,longlong param_2,undefined4 *param_3)

{
  NVhdParserChangeTrackingSwitchLogsInternal
            (*(undefined8 *)(param_1 + 8),param_2,param_3,(undefined8 *)0x0);
  return;
}



===== NVhdParserChangeTrackingSwitchLogsInternal @ 1c000a8bc =====

ulonglong NVhdParserChangeTrackingSwitchLogsInternal
                    (undefined8 param_1,longlong param_2,undefined4 *param_3,undefined8 *param_4)

{
  uint uVar1;
  undefined8 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined4 local_res10 [2];
  
  uVar1 = *(uint *)(param_2 + 4);
  local_res10[0] = 0;
  uVar3 = uVar1 + 0x40;
  if (uVar3 < 0x40) {
    uVar6 = 0xc0000095;
  }
  else {
    puVar4 = (undefined4 *)ExAllocatePool2(0x100,uVar3,0x70705656);
    if (puVar4 == (undefined4 *)0x0) {
      uVar6 = 0xc000009a;
    }
    else {
      puVar4[1] = uVar1;
      *puVar4 = 0x40;
      uVar2 = *(undefined8 *)(param_2 + 0x10);
      *(undefined8 *)(puVar4 + 2) = *(undefined8 *)(param_2 + 8);
      *(undefined8 *)(puVar4 + 4) = uVar2;
      puVar4[6] = *(undefined4 *)(param_2 + 0x18);
      puVar4[7] = *(undefined4 *)(param_2 + 0x1c);
      uVar2 = *(undefined8 *)(param_2 + 0x28);
      *(undefined8 *)(puVar4 + 8) = *(undefined8 *)(param_2 + 0x20);
      *(undefined8 *)(puVar4 + 10) = uVar2;
      if (uVar1 != 0) {
        memcpy(puVar4 + 0x10,(void *)(param_2 + 0x30),(ulonglong)uVar1);
      }
      uVar5 = NVhdIoInvokeIoctl(param_1,0x2d1990,puVar4,uVar3,local_res10,4,param_4);
      uVar6 = uVar5 & 0xffffffff;
      if (-1 < (int)uVar5) {
        *param_3 = local_res10[0];
      }
      ExFreePoolWithTag(puVar4,0x70705656);
    }
  }
  return uVar6;
}



===== NVhdParserCloseDisk @ 1c000a9d0 =====

void NVhdParserCloseDisk(longlong *param_1,undefined8 param_2)

{
  if (*(char *)((longlong)param_1 + 0x15) != '\0') {
    NVhdParserDetach((longlong)param_1,param_2);
    *(undefined1 *)((longlong)param_1 + 0x15) = 0;
  }
  NVhdContextCleanup(param_1);
  ExFreePoolWithTag(param_1,0x70705656);
  return;
}



===== NVhdParserDeleteSnapshot @ 1c000aa20 =====

void NVhdParserDeleteSnapshot(longlong param_1,undefined8 param_2)

{
  NVhdIoInvokeIoctl(*(undefined8 *)(param_1 + 8),0x2d1a4c,param_2,0x18,0,0,(undefined8 *)0x0);
  return;
}



===== NVhdParserDetach @ 1c000aa58 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void NVhdParserDetach(longlong param_1,undefined8 param_2)

{
  undefined1 auStack_58 [48];
  undefined4 local_28;
  undefined8 local_24;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  if (*(char *)(param_1 + 0x14) != '\0') {
    local_24 = 0;
    local_28 = 1;
    NVhdIoInvokeVhdmpIoctlForwardProgress(param_1,param_2,&local_28);
    *(undefined8 *)(param_1 + 0x28) = 0;
    *(undefined8 *)(param_1 + 0x30) = 0;
    *(undefined8 *)(param_1 + 0x38) = 0;
    *(undefined8 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 0;
    *(undefined1 *)(param_1 + 0x14) = 0;
  }
  return;
}



===== NVhdParserDismountDisk @ 1c000aad0 =====

void NVhdParserDismountDisk(longlong param_1,undefined8 param_2)

{
  NVhdParserDetach(param_1,param_2);
  *(undefined1 *)(param_1 + 0x15) = 0;
  return;
}



===== NVhdParserEnableResiliency @ 1c000aaf0 =====

ulonglong NVhdParserEnableResiliency(longlong param_1)

{
  ulonglong uVar1;
  
  if (*(char *)(param_1 + 0x80) == '\0') {
    uVar1 = NVhdIoInvokeIoctl(*(undefined8 *)(param_1 + 8),0x2d1a24,0,0,0,0,(undefined8 *)0x0);
    if (-1 < (int)uVar1) {
      *(undefined1 *)(param_1 + 0x80) = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



===== NVhdParserFastCloseDisk @ 1c000ab50 =====

void NVhdParserFastCloseDisk(longlong param_1)

{
  int iVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_1 + 0xa8,0);
  iVar1 = *(int *)(param_1 + 0xb0);
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      puVar4 = DvReleaseRundownBarrier((longlong *)(param_1 + 200),'\0');
      while (puVar4 != (undefined8 *)0x0) {
        puVar2 = (undefined8 *)*puVar4;
        if (*(char *)(*(longlong *)(puVar4[-1] + 8) + 2) == '\0') {
          *(undefined1 *)(*(longlong *)(puVar4[-1] + 8) + 2) = 2;
        }
        VstorCompleteScsiRequest(puVar4[-1]);
        puVar4 = puVar2;
      }
      goto LAB_1c000abac;
    }
    if (iVar1 != 2) goto LAB_1c000abac;
  }
  DvWaitRundownBarrier((longlong *)(param_1 + 200),'\0');
LAB_1c000abac:
  *(undefined4 *)(param_1 + 0xb0) = 3;
  ExReleasePushLockExclusiveEx(param_1 + 0xa8,0);
  KeLeaveCriticalRegion();
  DvRundownWorkQueue((ulonglong *)(param_1 + 0xe0));
  uVar6 = 0;
  uVar5 = 0x2d1a28;
  uVar7 = 0;
  uVar3 = NVhdIoInvokeIoctl(*(undefined8 *)(param_1 + 8),0x2d1a28,0,0,0,0,(undefined8 *)0x0);
  if (((int)uVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,uVar6,10,uVar7,(char)uVar3);
  }
  return;
}



===== NVhdParserIsDifferencingVhd @ 1c000ac98 =====

ulonglong NVhdParserIsDifferencingVhd(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined4 local_res18 [2];
  undefined8 local_res20;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined4 local_10;
  
  local_res20 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  local_10 = 0;
  ObReferenceObjectByHandle(0,0,*(undefined8 *)IoFileObjectType_exref,0,&local_res20,0);
  uVar1 = local_res20;
  local_res18[0] = 7;
  uVar2 = NVhdIoInvokeIoctl(local_res20,0x2d1940,local_res18,4,&local_28,0x20,(undefined8 *)0x0);
  uVar3 = uVar2 & 0xffffffff;
  if (-1 < (int)uVar2) {
    uVar3 = 0;
    *(bool *)param_2 = (int)uStack_20 == 4;
  }
  ObfDereferenceObject(uVar1);
  return uVar3;
}



===== NVhdParserMountDisk @ 1c000ad70 =====

ulonglong NVhdParserMountDisk(longlong param_1,byte param_2,undefined8 *param_3,undefined4 *param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_28 = *param_3;
  uStack_20 = param_3[1];
  puVar3 = &local_28;
  local_18 = (ulonglong)
             CONCAT16(param_2 >> 7,
                      CONCAT15(param_2 >> 5,
                               CONCAT14(param_2 >> 4,
                                        CONCAT13(param_2 >> 3,
                                                 CONCAT12(param_2 >> 2,
                                                          CONCAT11(param_2 >> 1,param_2)))))) &
             0xffff010101010101;
  uVar1 = NVhdParserAttach(param_1,puVar3);
  uVar2 = uVar1 & 0xffffffff;
  if ((int)uVar1 < 0) {
    NVhdParserDetach(param_1,puVar3);
  }
  else {
    *(undefined1 *)(param_1 + 0x15) = 1;
    *param_4 = *(undefined4 *)(param_1 + 0x4c);
    *(undefined1 *)(param_4 + 1) = 0;
    *(undefined1 *)((longlong)param_4 + 5) = *(undefined1 *)(param_1 + 0x16);
    *(undefined1 *)((longlong)param_4 + 6) = *(undefined1 *)(param_1 + 0x17);
    uVar2 = 0;
    *(undefined1 *)((longlong)param_4 + 7) = 1;
  }
  return uVar2;
}



===== NVhdParserOpenDisk @ 1c000ae30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong NVhdParserOpenDisk(ushort *param_1,uint param_2,undefined4 *param_3,longlong param_4,
                            undefined8 *param_5)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  longlong *plVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ushort uVar8;
  longlong *plVar9;
  char cVar10;
  short sVar11;
  bool bVar12;
  undefined1 auStack_1c8 [32];
  longlong *local_1a8;
  undefined4 local_1a0;
  undefined4 local_198;
  undefined4 local_190;
  undefined4 local_188;
  undefined4 *local_180;
  undefined4 local_178;
  int local_170;
  longlong *local_168;
  undefined4 local_160;
  char local_158;
  char local_157;
  longlong *local_150;
  longlong local_148;
  longlong lStack_140;
  int local_138 [2];
  longlong local_130;
  undefined8 *local_128;
  longlong local_120;
  undefined8 local_118;
  longlong *plStack_110;
  longlong *local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  ulonglong uStack_f0;
  ulonglong local_e8 [2];
  undefined4 local_d8;
  undefined4 local_d4;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 local_a4;
  uint local_a0;
  undefined4 local_9c;
  uint local_98;
  undefined4 local_94;
  uint local_90;
  undefined4 local_8c;
  undefined4 local_74;
  undefined4 local_70;
  char local_6c [29];
  undefined4 local_4f;
  undefined4 uStack_4b;
  undefined4 uStack_47;
  undefined4 uStack_43;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_1c8;
  local_128 = param_5;
  local_f8 = 0;
  uStack_f0 = uStack_f0 & 0xffffffff00000000;
  sVar11 = 0;
  local_150 = (longlong *)0x0;
  local_118 = 0;
  plStack_110 = (longlong *)0x0;
  plVar4 = (longlong *)0x0;
  local_108 = (longlong *)0x0;
  uStack_100 = 0;
  local_e8[0] = 0;
  local_e8[1] = 0;
  local_148 = 0;
  lStack_140 = 0;
  local_130 = param_4;
  memset(&local_d8,0,0x9c);
  *param_5 = 0;
  uVar8 = *param_1;
  cVar10 = '\0';
  local_158 = '\0';
  if (uVar8 < 0xb) {
    uVar8 = 10;
  }
  uVar8 = VhdmpBaseName + uVar8;
  uVar6 = (ulonglong)uVar8;
  local_120 = ExAllocatePool2(0x100,uVar6,0x70705656);
  if (local_120 == 0) {
    uVar7 = 0xc0000017;
    goto LAB_1c000b3d1;
  }
  local_148 = (ulonglong)CONCAT42((int)((ulonglong)local_148 >> 0x20),uVar8) << 0x10;
  lStack_140 = local_120;
  RtlAppendUnicodeStringToString(&local_148,&VhdmpBaseName);
  RtlAppendUnicodeStringToString(&local_148,param_1);
  uVar8 = (ushort)local_148;
  local_157 = '\0';
  uVar2 = 0;
  if ((param_2 & 1) == 0) {
    uVar2 = 0x80000000;
    if ((param_2 & 0x20) == 0) {
      if ((param_2 & 0x10) == 0) {
        if ((param_2 & 0x40) != 0) {
          cVar10 = '\x01';
          goto LAB_1c000af8e;
        }
      }
      else {
        uVar2 = 0x80000020;
      }
    }
    else {
LAB_1c000af8e:
      uVar2 = 0x80000008;
    }
  }
  else {
    local_157 = '\x01';
    if ((param_2 & 2) == 0) {
      uVar2 = 1;
    }
  }
  local_d4 = 0x540780;
  local_b8 = 2;
  local_9c = 0;
  uVar5 = uVar2 | 0x80;
  if ((param_2 & 0x80) == 0) {
    uVar5 = uVar2;
  }
  local_94 = 2;
  local_d0 = 0x4b534454524956;
  local_c8 = 0x2e34d650;
  uStack_c4 = 0x42ca5819;
  uStack_c0 = 0x8d3ae84;
  uStack_bc = 0x5e5ba03;
  uVar2 = uVar5 | 0x100;
  if ((param_2 >> 8 & 1) == 0) {
    uVar2 = uVar5;
  }
  local_b4 = 0xec984aec;
  uStack_b0 = 0x47e9a0f9;
  uStack_ac = 0x41711f90;
  uStack_a8 = 0x5b34665a;
  uVar5 = uVar2 | 0x200;
  if ((param_2 & 0x400) == 0) {
    uVar5 = uVar2;
  }
  uVar2 = uVar5 | 0x400;
  if ((param_2 & 0x800) == 0) {
    uVar2 = uVar5;
  }
  local_a4 = 0x54;
  local_a0 = uVar2 | 0x800;
  if ((param_2 >> 0xc & 1) == 0) {
    local_a0 = uVar2;
  }
  if (local_157 == '\0') {
    local_98 = ~(param_2 >> 2) & 1;
  }
  else {
    local_98 = 0;
  }
  local_90 = (uint)(local_157 != '\0');
  if (param_3 == (undefined4 *)0x0) {
    local_d8 = 0;
  }
  else {
    builtin_strncpy(local_6c + 0x18,"ance",4);
    builtin_strncpy(local_6c,"ClusteredApplicationInst",0x18);
    local_74 = 0;
    local_4f = *param_3;
    uStack_4b = param_3[1];
    uStack_47 = param_3[2];
    uStack_43 = param_3[3];
    local_70 = 0x101c00;
    local_6c[0x1c] = 0;
    local_d8 = 100;
  }
  plVar9 = (longlong *)0x0;
  if ((((5 < (ushort)local_148) &&
       (uVar6 = (ulonglong)((ushort)local_148 >> 1),
       (*(short *)(lStack_140 + -6 + uVar6 * 2) - 0x49U & 0xffdf) == 0)) &&
      ((*(short *)(lStack_140 + -4 + uVar6 * 2) - 0x53U & 0xffdf) == 0)) &&
     ((*(short *)(lStack_140 + -2 + uVar6 * 2) - 0x4fU & 0xffdf) == 0)) {
    local_b8 = 1;
    local_8c = 1;
    if (*param_1 == 6) {
      local_148 = CONCAT62(local_148._2_6_,(ushort)local_148 - 6);
      RtlAppendUnicodeToString(&local_148,L"EMPTY");
    }
    local_a0 = local_a0 & 0x7fffffff;
  }
  if (uVar8 < 0xf) {
    if (8 < uVar8) goto LAB_1c000b1aa;
  }
  else {
    uVar6 = (ulonglong)(uVar8 >> 1);
    if (((((*(short *)(lStack_140 + -0xe + uVar6 * 2) - 0x56U & 0xffdf) == 0) &&
         ((*(short *)(lStack_140 + -0xc + uVar6 * 2) - 0x48U & 0xffdf) == 0)) &&
        (((*(short *)(lStack_140 + -10 + uVar6 * 2) - 0x44U & 0xffdf) == 0 &&
         (((*(short *)(lStack_140 + -8 + uVar6 * 2) - 0x50U & 0xffdf) == 0 &&
          ((*(short *)(lStack_140 + -6 + uVar6 * 2) - 0x4dU & 0xffdf) == 0)))))) &&
       (((*(short *)(lStack_140 + -4 + uVar6 * 2) - 0x45U & 0xffdf) == 0 &&
        ((*(short *)(lStack_140 + -2 + uVar6 * 2) - 0x4dU & 0xffdf) == 0)))) {
      local_b8 = 3;
    }
LAB_1c000b1aa:
    uVar6 = (ulonglong)(uVar8 >> 1);
    if ((((*(short *)(lStack_140 + -8 + uVar6 * 2) - 0x56U & 0xffdf) == 0) &&
        ((*(short *)(lStack_140 + -6 + uVar6 * 2) - 0x48U & 0xffdf) == 0)) &&
       ((*(short *)(lStack_140 + -4 + uVar6 * 2) - 0x44U & 0xffdf) == 0)) {
      sVar1 = *(short *)(lStack_140 + -2 + uVar6 * 2);
      if ((sVar1 - 0x58U & 0xffdf) == 0) {
        local_b8 = 3;
      }
      else if ((sVar1 - 0x53U & 0xffdf) == 0) {
        local_b8 = 4;
      }
    }
  }
  local_108 = &local_148;
  local_118 = CONCAT44(local_118._4_4_,0x30);
  local_f8 = 0;
  uStack_f0 = 0;
  uStack_100 = CONCAT44(uStack_100._4_4_,0x240);
  plStack_110 = plVar9;
  while( true ) {
    local_160 = 0x101;
    local_180 = &local_d8;
    local_178 = 0x9c;
    local_188 = 0x40;
    local_190 = 1;
    local_198 = 1;
    local_1a0 = 0x80;
    local_1a8 = plVar9;
    local_170 = 0;
    local_168 = plVar9;
    uVar2 = IoCreateFile(&local_150,0x80100000,&local_118,local_e8);
    uVar7 = (ulonglong)uVar2;
    if ((int)uVar2 < 0) break;
    bVar12 = cVar10 == '\0';
    cVar10 = '\0';
    if (bVar12) {
LAB_1c000b2db:
      plVar4 = (longlong *)ExAllocatePool2(0x40,0x128,0x70705656);
      if (plVar4 == (longlong *)0x0) {
        uVar7 = 0xc0000017;
        goto LAB_1c000b3bc;
      }
      uVar2 = NVhdContextInitialize(plVar4,local_157,(longlong *)&local_150);
      uVar7 = (ulonglong)uVar2;
      if ((int)uVar2 < 0) goto LAB_1c000b3bc;
      local_158 = cVar10;
      uVar2 = NVhdParserCheckPolicyValue(L"FastPause",1,&local_158);
      uVar7 = (ulonglong)uVar2;
      if ((int)uVar2 < 0) goto LAB_1c000b3bc;
      *(bool *)((longlong)plVar4 + 0x16) = local_158 != '\0';
      if (local_158 != '\0') {
        local_138[0] = 0;
        uVar6 = NVhdParserQueryPolicyValue(L"FastClose",0,local_138);
        uVar7 = uVar6 & 0xffffffff;
        if ((int)uVar6 < 0) goto LAB_1c000b3bc;
        iVar3 = local_138[0];
        if (2 < local_138[0]) {
          iVar3 = 2;
        }
        *(int *)(plVar4 + 3) = iVar3;
      }
      if (((int)plVar4[3] == 2) && (sVar11 == 0)) {
        sVar11 = 1;
      }
      uVar7 = 0;
      plVar4[4] = local_130;
      *(short *)(plVar4 + 0x14) = sVar11;
      *local_128 = plVar4;
      plVar4 = plVar9;
      goto LAB_1c000b3bc;
    }
    uVar6 = NVhdParserIsDifferencingVhd(local_150,&local_158);
    uVar7 = uVar6 & 0xffffffff;
    if ((int)uVar6 < 0) goto LAB_1c000b3bc;
    if (local_158 != '\0') {
      sVar11 = 4;
      goto LAB_1c000b2db;
    }
    local_a0 = local_a0 & 0xfffffff7;
    ZwClose(local_150);
    local_150 = plVar9;
  }
  if ((int)local_e8[0] != 0) {
    uVar7 = local_e8[0] & 0xffffffff;
  }
LAB_1c000b3bc:
  uVar6 = 0x70705656;
  ExFreePoolWithTag(local_120);
LAB_1c000b3d1:
  if (local_150 != (longlong *)0x0) {
    ZwClose();
  }
  if (plVar4 != (longlong *)0x0) {
    NVhdParserCloseDisk(plVar4,uVar6);
  }
  return uVar7;
}



===== NVhdParserPrepareMetaOperation @ 1c000b430 =====

undefined8
NVhdParserPrepareMetaOperation
          (longlong param_1,longlong param_2,longlong param_3,longlong param_4,longlong *param_5)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  plVar1 = (longlong *)ExAllocatePool2(0x40,0x28,0x70705656);
  uVar3 = 0;
  if (plVar1 == (longlong *)0x0) {
    uVar3 = 0xc000009a;
  }
  else {
    plVar1[3] = param_2;
    *plVar1 = param_1;
    plVar1[1] = param_3;
    plVar1[2] = param_4;
    lVar2 = IoGetRelatedDeviceObject(*(undefined8 *)(param_1 + 8));
    lVar2 = IoAllocateIrp(*(undefined1 *)(lVar2 + 0x4c),0);
    plVar1[4] = lVar2;
    if (lVar2 == 0) {
      uVar3 = 0xc000009a;
      NVhdParserCleanUpMetaOperation((longlong)plVar1);
    }
    else {
      *param_5 = (longlong)plVar1;
    }
  }
  return uVar3;
}



===== NVhdParserQueryChanges @ 1c000b500 =====

void NVhdParserQueryChanges
               (longlong param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  NVhdIoInvokeIoctl(*(undefined8 *)(param_1 + 8),0x2d19e8,param_2,param_3,param_2,param_4,param_5);
  return;
}



===== NVhdParserQueryInformationDisk @ 1c000b540 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong NVhdParserQueryInformationDisk
                    (longlong param_1,uint param_2,uint *param_3,uint param_4,undefined8 *param_5,
                    uint *param_6)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined1 auStackY_a8 [32];
  undefined4 local_68;
  undefined1 local_64 [4];
  longlong local_60;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  uint uStack_44;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_a8;
  if (param_2 < 0x202) {
    if (param_2 != 0x201) {
      local_60 = param_1;
      if (param_2 == 1) {
        local_58 = 0;
        uStack_54 = 0;
        uStack_50 = 0;
        uStack_4c = 0;
        local_48 = 0;
        uStack_44 = 0;
        local_40 = 0;
        if (*param_6 < 0x10) {
          return 0xc0000023;
        }
        local_68 = 0;
        uVar4 = NVhdIoInvokeIoctl(*(undefined8 *)(param_1 + 8),0x2d1940,&local_68,4,&local_58,0x20,
                                  (undefined8 *)0x0);
        if ((int)uVar4 < 0) {
          return uVar4 & 0xffffffff;
        }
        *(undefined4 *)((longlong)param_5 + 0xc) = 0;
        *(undefined4 *)(param_5 + 1) = local_3c;
        *param_5 = CONCAT44(uStack_4c,uStack_50);
        local_68 = 10;
        uVar4 = NVhdIoInvokeIoctl(*(undefined8 *)(local_60 + 8),0x2d1940,&local_68,4,&local_58,0x20,
                                  (undefined8 *)0x0);
        if ((int)uVar4 < 0) {
          return uVar4 & 0xffffffff;
        }
        *(undefined4 *)((longlong)param_5 + 0xc) = uStack_50;
        *param_6 = 0x10;
        return 0;
      }
      if (param_2 == 0x101) {
        local_58 = 0;
        uStack_54 = 0;
        uStack_50 = 0;
        uStack_4c = 0;
        local_48 = 0;
        uStack_44 = 0;
        local_40 = 0;
        if (*param_6 < 0x38) {
          return 0xc0000023;
        }
        *param_5 = 0;
        param_5[1] = 0;
        param_5[2] = 0;
        param_5[3] = 0;
        param_5[4] = 0;
        param_5[5] = 0;
        param_5[6] = 0;
        local_68 = 7;
        uVar4 = NVhdIoInvokeIoctl(*(undefined8 *)(param_1 + 8),0x2d1940,&local_68,4,&local_58,0x20,
                                  (undefined8 *)0x0);
        if ((int)uVar4 < 0) {
          return uVar4 & 0xffffffff;
        }
        *(undefined4 *)param_5 = uStack_50;
        local_68 = 6;
        uVar4 = NVhdIoInvokeIoctl(*(undefined8 *)(local_60 + 8),0x2d1940,&local_68,4,&local_58,0x20,
                                  (undefined8 *)0x0);
        if ((int)uVar4 < 0) {
          return uVar4 & 0xffffffff;
        }
        local_68 = 0;
        *(undefined4 *)((longlong)param_5 + 4) = uStack_50;
        uVar4 = NVhdIoInvokeIoctl(*(undefined8 *)(local_60 + 8),0x2d1940,&local_68,4,&local_58,0x20,
                                  (undefined8 *)0x0);
        if ((int)uVar4 < 0) {
          return uVar4 & 0xffffffff;
        }
        *(undefined4 *)(param_5 + 1) = local_40;
        param_5[4] = CONCAT44(uStack_44,local_48);
        local_68 = 1;
        uVar4 = NVhdIoInvokeIoctl(*(undefined8 *)(local_60 + 8),0x2d1940,&local_68,4,&local_58,0x20,
                                  (undefined8 *)0x0);
        if ((int)uVar4 < 0) {
          return uVar4 & 0xffffffff;
        }
        *(ulonglong *)((longlong)param_5 + 0xc) = CONCAT44(uStack_4c,uStack_50);
        *(ulonglong *)((longlong)param_5 + 0x14) = CONCAT44(uStack_44,local_48);
        local_68 = 0xd;
        uVar4 = NVhdIoInvokeIoctl(*(undefined8 *)(local_60 + 8),0x2d1940,&local_68,4,&local_58,0x20,
                                  (undefined8 *)0x0);
        if ((int)uVar4 < 0) {
          return uVar4 & 0xffffffff;
        }
        *(undefined1 *)((longlong)param_5 + 0x1d) = (undefined1)uStack_50;
        local_68 = 8;
        uVar4 = NVhdIoInvokeIoctl(*(undefined8 *)(local_60 + 8),0x2d1940,&local_68,4,&local_58,0x20,
                                  (undefined8 *)0x0);
        if ((int)uVar4 < 0) {
          return uVar4 & 0xffffffff;
        }
        *(undefined1 *)((longlong)param_5 + 0x1e) = (undefined1)uStack_50;
        local_68 = 9;
        uVar4 = NVhdIoInvokeIoctl(*(undefined8 *)(local_60 + 8),0x2d1940,&local_68,4,&local_58,0x20,
                                  (undefined8 *)0x0);
        if ((int)uVar4 < 0) {
          return uVar4 & 0xffffffff;
        }
        *(undefined1 *)((longlong)param_5 + 0x1c) = (undefined1)local_48;
        local_68 = 0xe;
        uVar4 = NVhdIoInvokeIoctl(*(undefined8 *)(local_60 + 8),0x2d1940,&local_68,4,&local_58,0x20,
                                  (undefined8 *)0x0);
        if ((int)uVar4 < 0) {
          return uVar4 & 0xffffffff;
        }
        param_5[5] = CONCAT44(uStack_4c,uStack_50);
        param_5[6] = CONCAT44(uStack_44,local_48);
        *param_6 = 0x38;
        return 0;
      }
      if (param_2 == 0x102) {
        local_58 = 0;
        uStack_54 = 0;
        uStack_50 = 0;
        uStack_4c = 0;
        local_48 = 0;
        uStack_44 = 0;
        local_40 = 0;
        if (*param_6 < 4) {
          return 0xc0000023;
        }
        *(undefined4 *)param_5 = 0;
        local_68 = 0xc;
        uVar4 = NVhdIoInvokeIoctl(*(undefined8 *)(param_1 + 8),0x2d1940,&local_68,4,&local_58,0x20,
                                  (undefined8 *)0x0);
        if ((int)uVar4 < 0) {
          return uVar4 & 0xffffffff;
        }
        *(undefined4 *)param_5 = uStack_50;
        *param_6 = 4;
        return 0;
      }
      if (param_2 == 0x103) {
        if (*param_6 < 8) {
          return 0xc0000023;
        }
        memset(param_5,0,(ulonglong)*param_6);
        uVar2 = *param_6;
        lVar5 = ExAllocatePool2(0x100,uVar2 + 0x18,0x70705656);
        if (lVar5 == 0) {
          return 0xc000009a;
        }
        local_68 = 2;
        uVar4 = NVhdIoInvokeIoctl(*(undefined8 *)(param_1 + 8),0x2d1940,&local_68,4,lVar5,
                                  uVar2 + 0x18,(undefined8 *)0x0);
        if ((int)uVar4 < 0) {
          ExFreePoolWithTag(lVar5,0x70705656);
          return uVar4 & 0xffffffff;
        }
        *(undefined1 *)param_5 = *(undefined1 *)(lVar5 + 8);
        cVar1 = *(char *)(lVar5 + 9);
        *(char *)((longlong)param_5 + 1) = cVar1;
        iVar3 = *(int *)(lVar5 + 0xc);
        *(int *)((longlong)param_5 + 4) = iVar3;
        if (cVar1 == '\0') {
          *param_6 = 8;
        }
        else {
          *param_6 = iVar3 + 8;
          memcpy(param_5 + 1,(void *)(lVar5 + 0x10),(ulonglong)*(uint *)((longlong)param_5 + 4));
        }
        ExFreePoolWithTag(lVar5,0x70705656);
        return 0;
      }
      if (param_2 == 0x104) {
        local_64[0] = 0;
        if (*param_6 == 0) {
          return 0xc0000023;
        }
        *(undefined1 *)param_5 = 0;
        uVar4 = NVhdIoInvokeIoctl(*(undefined8 *)(param_1 + 8),0x2d5a0c,0,0,local_64,1,
                                  (undefined8 *)0x0);
        if ((int)uVar4 < 0) {
          return uVar4 & 0xffffffff;
        }
        *(undefined1 *)param_5 = local_64[0];
        *param_6 = 1;
        return 0;
      }
      if (param_2 == 0x105) {
        local_58 = 0;
        uStack_54 = 0;
        uStack_50 = 0;
        uStack_4c = 0;
        local_48 = 0;
        uStack_44 = 0;
        local_40 = 0;
        if (*param_6 < 8) {
          return 0xc0000023;
        }
        *param_5 = 0;
        local_68 = 0x11;
        uVar4 = NVhdIoInvokeIoctl(*(undefined8 *)(param_1 + 8),0x2d1940,&local_68,4,&local_58,0x20,
                                  (undefined8 *)0x0);
        if ((int)uVar4 < 0) {
          return uVar4 & 0xffffffff;
        }
        *param_5 = CONCAT44(uStack_4c,uStack_50);
        *param_6 = 8;
        return 0;
      }
      if (param_2 != 0x106) {
        return 0xc0000010;
      }
      local_58 = 0;
      uStack_54 = 0;
      uStack_50 = 0;
      uStack_4c = 0;
      local_48 = 0;
      uStack_44 = 0;
      local_40 = 0;
      if (*param_6 < 0x14) {
        return 0xc0000023;
      }
      *param_5 = 0;
      param_5[1] = 0;
      *(undefined4 *)(param_5 + 2) = 0;
      local_68 = 0x12;
      uVar4 = NVhdIoInvokeIoctl(*(undefined8 *)(param_1 + 8),0x2d1940,&local_68,4,&local_58,0x20,
                                (undefined8 *)0x0);
      if ((int)uVar4 < 0) {
        return uVar4 & 0xffffffff;
      }
      *(undefined1 *)param_5 = (undefined1)uStack_50;
      *(ulonglong *)((longlong)param_5 + 4) = CONCAT44(local_48,uStack_4c);
      *(ulonglong *)((longlong)param_5 + 0xc) = CONCAT44(local_40,uStack_44);
      *param_6 = 0x14;
      return 0;
    }
  }
  else if ((((param_2 != 0x202) && (param_2 != 0x203)) && (param_2 != 0x204)) &&
          (((param_2 != 0x205 && (param_2 != 0x206)) && ((param_2 != 0x207 && (param_2 != 0x208)))))
          ) {
    return 0xc0000010;
  }
  local_60 = 0;
  if (0x1f < param_4) {
    uStack_44 = (uint)(byte)param_3[6];
    uVar2 = *param_3;
    uStack_54 = (undefined4)*(undefined8 *)(param_3 + 2);
    uStack_50 = (undefined4)((ulonglong)*(undefined8 *)(param_3 + 2) >> 0x20);
    uStack_4c = (undefined4)*(undefined8 *)(param_3 + 4);
    local_48 = (undefined4)((ulonglong)*(undefined8 *)(param_3 + 4) >> 0x20);
    if (uVar2 < 0x207) {
      if (uVar2 == 0x206) {
        local_58 = 6;
      }
      else if (uVar2 == 0x201) {
        local_58 = 1;
      }
      else if (uVar2 == 0x202) {
        local_58 = 2;
      }
      else if (uVar2 == 0x203) {
        local_58 = 3;
      }
      else if (uVar2 == 0x204) {
        local_58 = 4;
      }
      else {
        if (uVar2 != 0x205) {
          return 0xc0000010;
        }
        local_58 = 5;
      }
    }
    else if (uVar2 == 0x207) {
      local_58 = 7;
    }
    else if (uVar2 == 0x208) {
      local_58 = 8;
    }
    else if (uVar2 == 0x280) {
      local_58 = 9;
    }
    else if (uVar2 == 0x281) {
      local_58 = 10;
    }
    else {
      if (uVar2 != 0x283) {
        return 0xc0000010;
      }
      local_58 = 0xc;
    }
    if (0x237 < *param_6) {
      memset(param_5,0,(ulonglong)*param_6);
      uVar4 = NVhdIoInvokeIoctl(*(undefined8 *)(param_1 + 8),0x2d1a40,&local_58,0x18,param_5,
                                *param_6,&local_60);
      if ((int)uVar4 < 0) {
        return uVar4 & 0xffffffff;
      }
      *param_6 = (uint)local_60;
      return 0;
    }
  }
  return 0xc0000023;
}



===== NVhdParserQueryMetaOperationProgress @ 1c000bd20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void NVhdParserQueryMetaOperationProgress(longlong *param_1,undefined8 *param_2)

{
  ulonglong uVar1;
  undefined1 auStackY_68 [32];
  longlong local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = param_1[3] + 8;
  local_20 = 0;
  uStack_18 = 0;
  uVar1 = NVhdIoInvokeIoctl(*(undefined8 *)(*param_1 + 8),0x2d1930,&local_28,8,&local_20,0x10,
                            (undefined8 *)0x0);
  if (-1 < (int)uVar1) {
    *param_2 = local_20;
    param_2[1] = uStack_18;
  }
  return;
}



===== NVhdParserQueryMountStatusDisk @ 1c000bdb0 =====

int NVhdParserQueryMountStatusDisk(longlong param_1,undefined4 param_2)

{
  int iVar1;
  ulonglong uVar2;
  undefined4 local_res8 [8];
  
  if (*(char *)(param_1 + 0x14) == '\0') {
    iVar1 = 0;
  }
  else {
    local_res8[0] = param_2;
    uVar2 = NVhdIoInvokeIoctl(*(undefined8 *)(param_1 + 8),0x2d1a00,local_res8,4,0,0,
                              (undefined8 *)0x0);
    iVar1 = 0;
    if ((int)uVar2 < 0) {
      iVar1 = (int)uVar2;
    }
  }
  return iVar1;
}



===== NVhdParserQuerySaveVersionDisk @ 1c000be00 =====

undefined8 NVhdParserQuerySaveVersionDisk(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 1;
  return 0;
}



===== NVhdParserRecoverDisk @ 1c000be10 =====

undefined8 NVhdParserRecoverDisk(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x88);
  *(undefined8 *)(param_1 + 0x90) = param_2;
  *(undefined8 *)(param_1 + 0x98) = param_3;
  IoReuseIrp(lVar1,0x103);
  lVar2 = *(longlong *)(lVar1 + 0xb8);
  *(void **)(lVar1 + 0x98) = SystemReserved1[0xf];
  *(undefined8 *)(lVar2 + -0x18) = *(undefined8 *)(param_1 + 8);
  uVar4 = IoGetRelatedDeviceObject();
  *(undefined1 *)(lVar2 + -0x48) = 0xe;
  *(undefined8 *)(lVar2 + -0x20) = uVar4;
  *(undefined4 *)(lVar2 + -0x30) = 0x2d1a80;
  lVar3 = *(longlong *)(lVar1 + 0xb8);
  *(code **)(lVar3 + -0x10) = NVhdParserDiskRecoveryCompletionRoutine;
  *(longlong *)(lVar3 + -8) = param_1;
  *(undefined1 *)(lVar3 + -0x45) = 0xe0;
  IofCallDriver(*(undefined8 *)(lVar2 + -0x20),lVar1);
  return 0x103;
}



===== NVhdParserRegisterWithVhdmp @ 1c000bed0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong NVhdParserRegisterWithVhdmp(void)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined1 auStackY_348 [32];
  short *local_2e8;
  undefined8 local_2e0;
  short *psStack_2d8;
  longlong local_2d0;
  longlong local_2c8;
  undefined8 local_2c0;
  undefined8 local_2b8;
  undefined8 uStack_2b0;
  undefined8 *local_2a8;
  undefined8 uStack_2a0;
  undefined8 local_298;
  ulonglong uStack_290;
  undefined8 local_288;
  undefined8 uStack_280;
  undefined8 local_278;
  undefined8 uStack_270;
  undefined8 local_268;
  undefined8 uStack_260;
  undefined8 local_258;
  undefined8 uStack_250;
  undefined4 local_248;
  undefined1 local_238 [24];
  int local_220;
  short local_21c;
  undefined4 local_21a;
  short local_216;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_348;
  local_298 = 0;
  uStack_290 = uStack_290 & 0xffffffff00000000;
  local_2e0 = 0;
  psStack_2d8 = (short *)0x0;
  local_248 = 0;
  local_2b8 = 0;
  uStack_2b0 = 0;
  local_2a8 = (undefined8 *)0x0;
  uStack_2a0 = 0;
  local_278 = 0;
  uStack_270 = 0;
  local_268 = 0;
  uStack_260 = 0;
  local_258 = 0;
  uStack_250 = 0;
  memset(local_238,0,0x21c);
  local_2e8 = (short *)0x0;
  local_2c0 = 0;
  local_2d0 = 0;
  local_288 = 0;
  uStack_280 = 0;
  uVar1 = IoGetDeviceInterfaces(&GUID_DEVINTERFACE_SURFACE_VIRTUAL_DRIVE,0,0,&local_2e8);
  uVar4 = (ulonglong)uVar1;
  if (-1 < (int)uVar1) {
    if (*local_2e8 == 0) {
      uVar4 = 0xc0000225;
    }
    else {
      RtlInitUnicodeString(&local_288,local_2e8);
      uVar1 = IoGetDeviceObjectPointer(&local_288,0x10000000,&local_2d0,&local_2c0);
      uVar4 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) {
        local_248 = 1;
        local_268 = 0x200000002;
        uStack_260 = 0x47e9a0f9ec984aec;
        local_258 = 0x5b34665a41711f90;
        uStack_250 = 0;
        uVar2 = NVhdIoInvokeIoctl(local_2d0,0x2d592c,&local_268,0x24,local_238,0x21c,
                                  (undefined8 *)0x0);
        uVar4 = uVar2 & 0xffffffff;
        if (-1 < (int)uVar2) {
          local_2e0._0_4_ = CONCAT22(0x200,(ushort)local_2e0);
          psStack_2d8 = &local_21c;
          if (local_220 - 2U < 0x1ff) {
            local_2e0 = CONCAT62(local_2e0._2_6_,(short)local_220 - 2U);
            if ((((7 < (ushort)((short)local_220 - 2U)) && (local_21c == 0x5c)) &&
                ((short)local_21a == 0x5c)) && ((local_21a._2_2_ == 0x2e && (local_216 == 0x5c)))) {
              local_21a = 0x3f003f;
            }
            uVar1 = RtlUnicodeStringCatString((ushort *)&local_2e0);
            uVar4 = (ulonglong)uVar1;
            if (-1 < (int)uVar1) {
              lVar3 = ExAllocatePool2(0x40,local_2e0 & 0xffff,0x70705656);
              if (lVar3 == 0) {
                uVar4 = 0xc0000017;
              }
              else {
                _VhdmpBaseName = (local_2e0 & 0xffff) << 0x10;
                DAT_1c00071b8 = lVar3;
                RtlCopyUnicodeString(&VhdmpBaseName,&local_2e0);
                local_2a8 = &local_2e0;
                local_2b8 = CONCAT44(local_2b8._4_4_,0x30);
                uStack_2b0 = 0;
                uStack_2a0 = CONCAT44(uStack_2a0._4_4_,0x240);
                local_298 = 0;
                uStack_290 = 0;
                uVar1 = ZwCreateFile(&VhdmpHandle,0x80100000,&local_2b8,&local_278);
                if ((int)uVar1 < 0) {
                  VhdmpHandle = 0;
                  if ((int)(uint)local_278 < 0) {
                    uVar1 = (uint)local_278;
                  }
                  uVar4 = (ulonglong)uVar1;
                }
                else {
                  local_2c8 = 0;
                  uVar1 = ObReferenceObjectByHandle
                                    (VhdmpHandle,1,*(undefined8 *)IoFileObjectType_exref);
                  uVar4 = 0;
                  if ((int)uVar1 < 0) {
                    uVar4 = (ulonglong)uVar1;
                  }
                  if (local_2c8 != 0) {
                    ObfDereferenceObject();
                  }
                }
                if (-1 < (int)uVar4) goto LAB_1c000c21c;
              }
            }
          }
          else {
            uVar4 = 0xc00000e5;
          }
        }
      }
    }
  }
  if (VhdmpHandle != 0) {
    ZwClose();
    VhdmpHandle = 0;
  }
  if (DAT_1c00071b8 != 0) {
    ExFreePoolWithTag(DAT_1c00071b8,0x70705656);
    _VhdmpBaseName = 0;
    DAT_1c00071b8 = 0;
  }
LAB_1c000c21c:
  if (local_2d0 != 0) {
    ObfDereferenceObject();
  }
  if (local_2e8 != (short *)0x0) {
    ExFreePoolWithTag(local_2e8,0);
  }
  return uVar4;
}



===== NVhdParserRestoreDisk @ 1c000c280 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int NVhdParserRestoreDisk(longlong param_1,int param_2,longlong param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined1 auStackY_d8 [32];
  int local_a8 [2];
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 local_78 [4];
  int *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  int *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_88 = 0;
  uVar4 = 3;
  local_98 = 0;
  uStack_90 = 0;
  EtwActivityIdControl(3,&local_98);
  local_88 = 0;
  if (4 < DAT_1c0007010) {
    uVar3 = _tlgKeywordOn();
    if ((char)uVar3 != '\0') {
      local_a0 = *(undefined8 *)(param_1 + 8);
      local_4c = 0;
      local_a8[0] = 0;
      local_3c = 0;
      local_58 = (int *)&local_a0;
      local_48 = local_a8;
      local_50 = 8;
      local_40 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(uVar4,&DAT_1c0005572,&local_98,0,4,local_78);
    }
  }
  if (param_2 == 1) {
    uVar1 = *(uint *)(param_1 + 0x48) + 0x20;
    if (uVar1 < *(uint *)(param_1 + 0x48)) {
      iVar2 = -0x3fffff6b;
    }
    else if (param_4 < uVar1) {
      iVar2 = -0x3ffffdfa;
    }
    else {
      uVar4 = *(undefined8 *)(param_1 + 0x28);
      iVar2 = (**(code **)(param_1 + 0x40))(uVar4,param_3 + 0x20);
      if (-1 < iVar2) {
        iVar2 = 0;
        goto LAB_1c000c3cc;
      }
    }
  }
  else {
    iVar2 = -0x3fffffa7;
  }
  if (2 < DAT_1c0007010) {
    uVar3 = _tlgKeywordOn();
    if ((char)uVar3 != '\0') {
      local_4c = 0;
      local_58 = local_a8;
      local_50 = 4;
      local_a8[0] = iVar2;
      _tlgWriteTransfer_EtwWriteTransfer(uVar4,&DAT_1c0005511,&local_98,local_88,3,local_78);
    }
  }
LAB_1c000c3cc:
  if (4 < DAT_1c0007010) {
    uVar3 = _tlgKeywordOn();
    if ((char)uVar3 != '\0') {
      local_a0 = *(undefined8 *)(param_1 + 8);
      local_4c = 0;
      local_3c = 0;
      local_58 = (int *)&local_a0;
      local_48 = local_a8;
      local_50 = 8;
      local_40 = 4;
      local_a8[0] = iVar2;
      _tlgWriteTransfer_EtwWriteTransfer(uVar4,&DAT_1c000553a,&local_98,local_88,4,local_78);
    }
  }
  return iVar2;
}



===== NVhdParserRestoreDiskAzure @ 1c000c45c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 NVhdParserRestoreDiskAzure(longlong param_1,int param_2,int *param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  char local_res8 [8];
  
  local_res8[0] = '\0';
  iVar1 = NVhdParserIsRdssdToAbcMigrationEnabled(local_res8);
  if ((iVar1 < 0) || (local_res8[0] == '\0')) {
    uVar2 = 0xc0000463;
  }
  else if (param_2 == 1) {
    if (param_3 == (int *)0x0) {
      uVar2 = 0xc000000d;
    }
    else if (param_4 < 0x48) {
      uVar2 = 0xc0000023;
    }
    else if ((*param_3 == 1) && (*(longlong *)(param_3 + 0xe) == 0x4176686450535374)) {
      puVar3 = (undefined4 *)ExAllocatePool2(0x40,0x38,0x70705656);
      if (puVar3 == (undefined4 *)0x0) {
        uVar2 = 0xc000009a;
      }
      else {
        *puVar3 = 2;
        puVar3[2] = param_3[4];
        *(undefined8 *)(puVar3 + 4) = *(undefined8 *)(param_3 + 2);
        uVar2 = (**(code **)(param_1 + 0x40))(*(undefined8 *)(param_1 + 0x28),puVar3,0x38);
        ExFreePoolWithTag(puVar3,0x70705656);
      }
    }
    else {
      uVar2 = 0xc000a000;
    }
  }
  else {
    uVar2 = 0xc0000059;
  }
  return uVar2;
}



===== NVhdParserRestoreDiskWithHint @ 1c000c580 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int NVhdParserRestoreDiskWithHint
              (longlong param_1,int param_2,int *param_3,uint param_4,int *param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  longlong lVar7;
  int iVar8;
  undefined1 auStackY_128 [32];
  int local_f8 [2];
  undefined8 local_f0;
  int local_e8;
  int local_e4;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 local_b8 [4];
  int *local_98;
  undefined8 local_90;
  int *local_88;
  undefined8 local_80;
  int *local_78;
  undefined8 local_70;
  int *local_68;
  undefined8 local_60;
  undefined8 *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  local_c8 = 0;
  uVar6 = 3;
  local_d8 = 0;
  uStack_d0 = 0;
  EtwActivityIdControl(3,&local_d8);
  local_c8 = 0;
  if ((4 < DAT_1c0007010) && (uVar5 = _tlgKeywordOn(), (char)uVar5 != '\0')) {
    local_f0 = *(undefined8 *)(param_1 + 8);
    local_98 = (int *)&local_f0;
    local_88 = local_f8;
    local_90 = 8;
    local_f8[0] = 1;
    local_80 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(uVar6,&DAT_1c00055d6,&local_d8,0,4,local_b8);
  }
  if (param_6 != 4) {
    return -0x3fffff45;
  }
  iVar1 = *param_5;
  iVar3 = NVhdParserRestoreDisk(param_1,param_2,(longlong)param_3,param_4);
  lVar7 = 0;
  if ((iVar3 < 0) && (iVar1 != 0)) {
    lVar7 = param_1;
    iVar4 = NVhdParserRestoreDiskAzure(param_1,param_2,param_3,param_4);
    iVar2 = 1;
  }
  else {
    iVar4 = -0x7fffffce;
    iVar8 = 0;
    iVar2 = 0;
    if (-1 < iVar3) goto LAB_1c000c6ed;
  }
  iVar8 = iVar2;
  if ((2 < DAT_1c0007010) && (uVar5 = _tlgKeywordOn(), (char)uVar5 != '\0')) {
    local_98 = local_f8;
    local_90 = 4;
    local_f8[0] = iVar3;
    _tlgWriteTransfer_EtwWriteTransfer(lVar7,&DAT_1c000560e,&local_d8,local_c8,3,local_b8);
  }
LAB_1c000c6ed:
  if ((4 < DAT_1c0007010) && (uVar5 = _tlgKeywordOn(), (char)uVar5 != '\0')) {
    local_e0 = *(undefined8 *)(param_1 + 8);
    local_98 = (int *)&local_e0;
    local_88 = local_f8;
    local_78 = &local_e8;
    local_68 = &local_e4;
    local_58 = &local_f0;
    local_90 = 8;
    local_80 = 4;
    local_70 = 4;
    local_60 = 4;
    local_f0 = CONCAT44(local_f0._4_4_,iVar3);
    local_50 = 4;
    local_f8[0] = iVar1;
    local_e8 = iVar8;
    local_e4 = iVar4;
    _tlgWriteTransfer_EtwWriteTransfer(lVar7,&DAT_1c0005637,&local_d8,local_c8,7,local_b8);
  }
  if (iVar8 == 0) {
    iVar4 = iVar3;
  }
  return iVar4;
}



===== NVhdParserResumeEmulatedIo @ 1c000c7d4 =====

undefined8 NVhdParserResumeEmulatedIo(longlong param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (*(char *)(param_1 + 0x17) == '\0') {
    uVar1 = 0;
  }
  else {
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(param_1 + 0xa8,0);
    if (*(int *)(param_1 + 0xb0) != 0) {
      if (*(int *)(param_1 + 0xb0) == 2) {
        ExReInitializeRundownProtection(param_1 + 0xc0);
        *(undefined4 *)(param_1 + 0xb0) = 0;
      }
      else {
        uVar1 = 0xc0000184;
      }
    }
    ExReleasePushLockExclusiveEx(param_1 + 0xa8,0);
    KeLeaveCriticalRegion();
  }
  return uVar1;
}



===== NVhdParserSaveDisk @ 1c000c880 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int NVhdParserSaveDisk(longlong param_1,undefined8 *param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined1 auStackY_d8 [32];
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 local_78 [4];
  undefined8 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_88 = 0;
  uVar4 = 3;
  local_98 = 0;
  uStack_90 = 0;
  EtwActivityIdControl(3,&local_98);
  local_88 = 0;
  if (4 < DAT_1c0007010) {
    uVar3 = _tlgKeywordOn();
    if ((char)uVar3 != '\0') {
      local_a8 = *(undefined8 *)(param_1 + 8);
      local_4c = 0;
      local_58 = &local_a8;
      local_50 = 8;
      _tlgWriteTransfer_EtwWriteTransfer(uVar4,&DAT_1c00055aa,&local_98,0,3,local_78);
    }
  }
  uVar1 = *(uint *)(param_1 + 0x48) + 0x20;
  if (uVar1 < *(uint *)(param_1 + 0x48)) {
    iVar2 = -0x3fffff6b;
  }
  else if (param_3 < uVar1) {
    iVar2 = -0x3fffffdd;
  }
  else {
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    uVar4 = *(undefined8 *)(param_1 + 0x28);
    iVar2 = (**(code **)(param_1 + 0x38))(uVar4,param_2 + 4,*(undefined4 *)(param_1 + 0x48));
    if (-1 < iVar2) {
      *param_4 = uVar1;
      iVar2 = 0;
      goto LAB_1c000c9bb;
    }
  }
  if (2 < DAT_1c0007010) {
    uVar3 = _tlgKeywordOn();
    if ((char)uVar3 != '\0') {
      local_4c = 0;
      local_58 = &local_a8;
      local_a8 = CONCAT44(local_a8._4_4_,iVar2);
      local_50 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(uVar4,&DAT_1c00056d6,&local_98,local_88,3,local_78);
    }
  }
LAB_1c000c9bb:
  if (4 < DAT_1c0007010) {
    uVar3 = _tlgKeywordOn();
    if ((char)uVar3 != '\0') {
      local_a0 = *(undefined8 *)(param_1 + 8);
      local_4c = 0;
      local_3c = 0;
      local_58 = &local_a0;
      local_48 = &local_a8;
      local_50 = 8;
      local_a8 = CONCAT44(local_a8._4_4_,iVar2);
      local_40 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(uVar4,&DAT_1c00056a1,&local_98,local_88,4,local_78);
    }
  }
  return iVar2;
}



===== NVhdParserSetBehavior @ 1c000ca50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int NVhdParserSetBehavior(longlong param_1,int param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined1 auStackY_68 [32];
  uint local_28 [4];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  if (param_2 == 2) {
    if (param_4 < 4) {
      return -0x3ffffff3;
    }
    uVar1 = *param_3;
    if (uVar1 == 0) {
      uVar4 = NVhdParserResumeEmulatedIo(param_1);
      iVar2 = (int)uVar4;
    }
    else if (uVar1 == 1) {
      uVar4 = NVhdParserBeginPausingEmulatedIo(param_1);
      iVar2 = (int)uVar4;
    }
    else {
      if (uVar1 != 2) {
        return -0x3ffffff3;
      }
      uVar4 = NVhdParserFinishPausingEmulatedIo(param_1);
      iVar2 = (int)uVar4;
    }
  }
  else {
    if (param_2 == 0x100) {
      if (param_4 < 8) {
        return -0x3ffffff3;
      }
      iVar2 = NVhdParserSetDeviceOptimizations(param_1,param_3);
      return iVar2;
    }
    if (param_2 == 0x40000001) {
      param_4 = 0;
      param_3 = (uint *)0x0;
      uVar5 = 0x2d19e0;
    }
    else if (param_2 == 0x40000002) {
      uVar5 = 0x2d19e4;
    }
    else {
      if (param_2 == 0x40000003) {
        if (param_4 == 0) {
          return -0x3ffffff3;
        }
        if ((char)*param_3 == '\0') {
          local_28[0] = 1;
          local_28[1] = 2;
          if (*(char *)(param_1 + 0x17) == '\0') {
            local_28[0] = 1;
            local_28[1] = 0;
          }
        }
        else {
          local_28[0] = 1;
          local_28[1] = 4;
        }
        uVar3 = NVhdIoInvokeIoctl(*(undefined8 *)(param_1 + 8),0x2d1a10,local_28,8,0,0,
                                  (undefined8 *)0x0);
        if ((int)uVar3 < 0) {
          return (int)uVar3;
        }
        return 0;
      }
      if (param_2 != 0x40000004) {
        return -0x3ffffff0;
      }
      if (param_4 == 0) {
        return -0x3ffffff3;
      }
      param_4 = 0xc;
      uVar5 = 0x2d19ec;
      local_28[2] = 0;
      uVar1 = *param_3;
      param_3 = local_28;
      local_28[1] = (uint)(byte)uVar1;
      local_28[0] = 1;
    }
    uVar3 = NVhdIoInvokeIoctl(*(undefined8 *)(param_1 + 8),uVar5,param_3,param_4,0,0,
                              (undefined8 *)0x0);
    iVar2 = (int)uVar3;
  }
  return iVar2;
}



===== NVhdParserSetDeviceOptimizations @ 1c000cbec =====

int NVhdParserSetDeviceOptimizations(longlong param_1,uint *param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  int iVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_1 + 0xe8,0);
  uVar2 = *param_2;
  if (2 < uVar2) {
    iVar6 = -0x3ffffff3;
    goto LAB_1c000ce46;
  }
  uVar3 = *(uint *)(param_1 + 0xf0);
  if (uVar2 != uVar3) {
    if (((uVar3 == 1) && (uVar2 == 0)) || ((uVar3 == 0 && (uVar2 == 2)))) {
      iVar6 = -0x3ffffe7c;
      goto LAB_1c000ce46;
    }
    if (uVar2 == 0) {
      puVar1 = (undefined8 *)(param_1 + 0xf4);
      *puVar1 = 0;
      *(undefined4 *)(param_1 + 0xfc) = 0;
      *(undefined4 *)puVar1 = 2;
      *(undefined1 *)(param_1 + 0xf8) = 1;
      if (param_2[1] == 1) {
        *(undefined4 *)(param_1 + 0xfc) = 1;
      }
      uVar8 = NVhdIoInvokeIoctl(*(undefined8 *)(param_1 + 8),0x2d19ec,puVar1,0xc,0,0,
                                (undefined8 *)0x0);
      iVar6 = (int)uVar8;
      if (-1 < iVar6) {
        *(undefined4 *)(param_1 + 0xf0) = 0;
      }
      goto LAB_1c000ce46;
    }
    if (uVar2 != 1) {
      if (uVar2 == 2) {
        KeWaitForSingleObject(param_1 + 0x108,0,0,0,0);
        iVar6 = *(int *)(param_1 + 0x120);
        *(uint *)(param_1 + 0xf0) = (iVar6 >> 0x1f & 0xfffffffeU) + 2;
      }
      else {
        iVar6 = -0x3fffff1b;
      }
      goto LAB_1c000ce46;
    }
    if (uVar3 == 0) {
      KeResetEvent();
      puVar1 = (undefined8 *)(param_1 + 0xf4);
      *(undefined4 *)(param_1 + 0xf0) = 1;
      *(undefined4 *)(param_1 + 0x120) = 0x103;
      *puVar1 = 0;
      *(undefined4 *)(param_1 + 0xfc) = 0;
      *(undefined4 *)puVar1 = 2;
      if (param_2[1] == 1) {
        *(undefined4 *)(param_1 + 0xfc) = 1;
      }
      IoReuseIrp(*(undefined8 *)(param_1 + 0x100));
      *(void **)(*(longlong *)(param_1 + 0x100) + 0x98) = SystemReserved1[0xf];
      lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x100) + 0xb8);
      *(undefined8 *)(lVar4 + -0x18) = *(undefined8 *)(param_1 + 8);
      uVar7 = IoGetRelatedDeviceObject();
      *(undefined4 *)(lVar4 + -0x40) = 0;
      *(undefined8 *)(lVar4 + -0x20) = uVar7;
      *(undefined1 *)(lVar4 + -0x48) = 0xe;
      *(undefined4 *)(lVar4 + -0x30) = 0x2d19ec;
      *(undefined4 *)(lVar4 + -0x38) = 0xc;
      *(undefined8 **)(*(longlong *)(param_1 + 0x100) + 0x18) = puVar1;
      lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x100) + 0xb8);
      *(code **)(lVar5 + -0x10) = NVhdParserSetOptimizationsCompletionRoutine;
      *(longlong *)(lVar5 + -8) = param_1;
      *(undefined1 *)(lVar5 + -0x45) = 0xe0;
      IofCallDriver(*(undefined8 *)(lVar4 + -0x20),*(undefined8 *)(param_1 + 0x100));
    }
    else {
      *(undefined4 *)(param_1 + 0x120) = 0;
      KeSetEvent(param_1 + 0x108,0,0);
    }
    *(undefined4 *)(param_1 + 0xf0) = 1;
  }
  iVar6 = 0;
LAB_1c000ce46:
  ExReleasePushLockExclusiveEx(param_1 + 0xe8,0);
  KeLeaveCriticalRegion();
  return iVar6;
}



===== NVhdParserSetQoSPolicyDisk @ 1c000ce90 =====

void NVhdParserSetQoSPolicyDisk(longlong param_1,undefined8 param_2,undefined4 param_3)

{
  NVhdIoInvokeIoctl(*(undefined8 *)(param_1 + 8),0x2d1a14,param_2,param_3,0,0,(undefined8 *)0x0);
  return;
}



===== NVhdParserStartMetaOperation @ 1c000ced0 =====

void NVhdParserStartMetaOperation(longlong *param_1)

{
  NVhdParserMetaOpDispatch(param_1);
  return;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 1c000cee8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

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
  local_28 = *(undefined4 *)(PTR_DAT_1c0007018 + -0x10);
  uStack_24 = *(undefined4 *)(PTR_DAT_1c0007018 + -0xc);
  uStack_20 = *(undefined4 *)(PTR_DAT_1c0007018 + -8);
  uStack_1c = *(undefined4 *)(PTR_DAT_1c0007018 + -4);
  if (DAT_1c0007030 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_40;
  }
  DAT_1c0007038 = 0;
  DAT_1c0007040 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x1c000cf4b;
  iVar3 = EtwRegister(puVar4 + 0x20,_tlgEnableCallback,&DAT_1c0007010,&DAT_1c0007030);
  if (iVar3 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_1c0007018;
    *(undefined8 *)(puVar4 + -8) = 0x1c000cf72;
    EtwSetInformation(DAT_1c0007030,2,PTR_DAT_1c0007018,uVar1);
  }
  *(undefined8 *)(puVar4 + -8) = 0x1c000cf86;
  return iVar3;
}



===== WppCleanupKm @ 1c000cf94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppCleanupKm(undefined8 param_1)

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
    WppAutoLogStop(WPP_GLOBAL_Control,param_1);
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
    WPP_RECORDER_INITIALIZED = (undefined *)&WPP_RECORDER_INITIALIZED;
  }
  return;
}



===== WppInitKm @ 1c000d044 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppInitKm(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined *puVar2;
  
  if (WPP_GLOBAL_Control != &WPP_MAIN_CB) {
    WPP_GLOBAL_Control = &WPP_MAIN_CB;
    if (WPPTraceSuite == 4) {
      puVar2 = &WPP_MAIN_CB;
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
    WppAutoLogStart(WPP_GLOBAL_Control,param_1,param_2);
    WPP_RECORDER_INITIALIZED = &WPP_MAIN_CB;
  }
  return;
}



===== WppLoadTracingSupport @ 1c000d120 =====

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



===== WppTraceCallback @ 1c000d270 =====

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



===== _tlgEnableCallback @ 1c000d500 =====

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



===== wil_UninitializeFeatureStaging @ 1c000d57c =====

void wil_UninitializeFeatureStaging(void)

{
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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 1c000d5d4 =====

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
      goto LAB_1c000d631;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_1c000d631;
    }
  }
  uVar1 = 0x206;
LAB_1c000d631:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 1c000d63c =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  bool bVar5;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)&wil_details_featureDescriptors_z)
  ;
  if (plVar1 != (longlong *)0x0) {
    uVar3 = 0;
    uVar4 = 0x180;
    do {
      uVar2 = *(uint *)*plVar1;
      if ((uVar2 >> 9 & 1) != 0) {
        if (((uint)uVar4 & uVar2) == 0) {
          bVar5 = *(char *)((longlong)plVar1 + 0x1f) != '\0';
        }
        else {
          bVar5 = (uVar2 & (uint)uVar4) == 0x100;
        }
        uVar2 = uVar2 & 0x40 ^ (uint)bVar5 << 6 | (uint)uVar3 & 0xffffffbf;
        uVar3 = (ulonglong)uVar2;
        LOCK();
        *(uint *)*plVar1 = *(uint *)*plVar1 ^ uVar2;
        UNLOCK();
      }
      plVar1 = wil_details_FeatureDescriptors_SkipPadding(plVar1 + 7);
    } while (plVar1 != (longlong *)0x0);
  }
  plVar1 = (longlong *)&wil_details_featureDescriptors_z;
  while( true ) {
    plVar1 = wil_details_FeatureDescriptors_SkipPadding(plVar1);
    if (plVar1 == (longlong *)0x0) break;
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*plVar1,(longlong)plVar1);
    plVar1 = plVar1 + 7;
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 1c000d6f4 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 1c000d72c =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_1c000d7ae;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_1c000d7ae;
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
LAB_1c000d7ae:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 1c000d800 =====

void wil_details_OnFeatureUsageProviderFlushNotification(int param_1)

{
  int iVar1;
  longlong *plVar2;
  
  iVar1 = g_wil_details_featureUsageCached;
  if (param_1 == 1) {
    LOCK();
    g_wil_details_featureUsageCached = 0;
    UNLOCK();
    if (iVar1 != 0) {
      plVar2 = (longlong *)&wil_details_featureDescriptors_z;
      while (plVar2 = wil_details_FeatureDescriptors_SkipPadding(plVar2), plVar2 != (longlong *)0x0)
      {
        if ((*(uint *)plVar2[1] & 1) != 0) {
          wil_details_RecordCachedUsage((int)plVar2[3],(uint *)plVar2[1]);
        }
        plVar2 = plVar2 + 7;
      }
    }
  }
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 1c000d860 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 1c000d87c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_UpdateFeatureConfiguredStates(void)

{
  int iVar1;
  longlong *plVar2;
  undefined1 auStack_58 [32];
  uint local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  plVar2 = (longlong *)&wil_details_featureDescriptors_z;
  while( true ) {
    plVar2 = wil_details_FeatureDescriptors_SkipPadding(plVar2);
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
    plVar2 = plVar2 + 7;
  }
  return;
}



===== DvRundownWorkQueue @ 1c000d930 =====

void DvRundownWorkQueue(ulonglong *param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  bool bVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong uStack_10;
  
  uVar2 = *param_1;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  if (uVar2 != 0) {
    KeInitializeEvent(&local_28,0,0);
    do {
      if (uVar2 == 0) {
        return;
      }
      uStack_10 = uVar2 & 0xfffffffffffffffe;
      LOCK();
      if (uVar2 == *param_1) {
        *param_1 = (longlong)&local_28 + 2;
        uVar1 = uVar2;
      }
      else {
        uVar1 = *param_1;
      }
      UNLOCK();
      bVar3 = uVar1 != uVar2;
      uVar2 = uVar1;
    } while (bVar3);
    KeWaitForSingleObject(&local_28,0,0,0,0);
  }
  return;
}



===== NVhdParserGetQoSStatusDisk @ 1c000d9d0 =====

undefined8
NVhdParserGetQoSStatusDisk
          (longlong param_1,void *param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  *(undefined8 *)(param_1 + 0x78) = param_5;
  *(undefined8 *)(param_1 + 0x70) = param_4;
  memcpy(*(void **)(param_1 + 0x68),param_2,(ulonglong)param_3);
  lVar1 = *(longlong *)(param_1 + 0x60);
  IoReuseIrp(lVar1,0x103);
  lVar2 = *(longlong *)(lVar1 + 0xb8);
  *(void **)(lVar1 + 0x98) = SystemReserved1[0xf];
  *(undefined8 *)(lVar2 + -0x18) = *(undefined8 *)(param_1 + 8);
  uVar4 = IoGetRelatedDeviceObject();
  *(undefined1 *)(lVar2 + -0x48) = 0xe;
  *(undefined8 *)(lVar2 + -0x20) = uVar4;
  *(undefined4 *)(lVar2 + -0x30) = 0x2d1a18;
  *(uint *)(lVar2 + -0x38) = param_3;
  *(undefined4 *)(lVar2 + -0x40) = 0x60;
  *(undefined8 *)(lVar1 + 0x18) = *(undefined8 *)(param_1 + 0x68);
  lVar3 = *(longlong *)(lVar1 + 0xb8);
  *(code **)(lVar3 + -0x10) = NVhdParserQoSStatusRequestCompletion;
  *(longlong *)(lVar3 + -8) = param_1;
  *(undefined1 *)(lVar3 + -0x45) = 0xe0;
  IofCallDriver(*(undefined8 *)(lVar2 + -0x20),lVar1);
  return 0x103;
}



===== NVhdParserAttach @ 1c000dac0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong NVhdParserAttach(longlong param_1,undefined8 *param_2)

{
  ulonglong uVar1;
  undefined1 auStackY_108 [32];
  int local_c8 [2];
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined4 local_88;
  undefined4 local_84;
  ushort local_74;
  undefined2 local_72;
  undefined8 local_70;
  undefined8 uStack_68;
  code *local_50;
  code *local_48;
  code *local_40;
  undefined8 local_38;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_108;
  local_c0 = 0;
  memset(&local_88,0,0x58);
  local_88 = 1;
  local_84 = 8;
  if (*(char *)(param_2 + 2) != '\0') {
    local_84 = 9;
  }
  local_b8 = 0;
  uStack_b0 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_98 = 0;
  uStack_90 = 0;
  if (*(char *)((longlong)param_2 + 0x11) != '\0') {
    local_74 = local_74 | 1;
  }
  local_c8[0] = 0;
  uVar1 = NVhdParserQueryPolicyValue(L"IgnoreFlushes",0,local_c8);
  if (-1 < (int)uVar1) {
    if (local_c8[0] == 0) {
      local_72 = *(undefined2 *)(param_1 + 0xa0);
    }
    else {
      local_72 = 4;
    }
    local_70 = *param_2;
    uStack_68 = param_2[1];
    local_50 = NVhdIoParserEndIo;
    local_38 = *(undefined8 *)(param_1 + 0x20);
    local_74 = local_74 |
               -(ushort)(*(char *)((longlong)param_2 + 0x15) != '\0') & 0x200 |
               -(ushort)(*(char *)((longlong)param_2 + 0x14) != '\0') & 0x100 |
               -(ushort)(*(char *)((longlong)param_2 + 0x13) != '\0') & 0x80 |
               -(ushort)(*(char *)((longlong)param_2 + 0x12) != '\0') & 0x40 |
               -(ushort)(*(char *)((longlong)param_2 + 0x16) != '\0') & 0x18 | 2;
    local_48 = VstorSendMediaNotification_exref;
    local_40 = VstorSendNotification_exref;
    uVar1 = NVhdIoInvokeIoctl(*(undefined8 *)(param_1 + 8),0x2d191c,&local_88,0x58,&local_b8,0x30,
                              (undefined8 *)0x0);
    if (-1 < (int)uVar1) {
      *(undefined8 *)(param_1 + 0x28) = uStack_b0;
      *(undefined8 *)(param_1 + 0x30) = local_a8;
      *(undefined4 *)(param_1 + 0x48) = (undefined4)local_b8;
      *(undefined8 *)(param_1 + 0x38) = uStack_a0;
      *(undefined8 *)(param_1 + 0x40) = local_98;
      *(undefined1 *)(param_1 + 0x14) = 1;
      *(int *)(param_1 + 0x4c) = local_b8._4_4_ + 0x70;
      if (*(int *)(param_1 + 0x18) != 0) {
        *(byte *)(param_1 + 0x17) = (byte)uStack_90 & 1;
      }
      uVar1 = NVhdIoInvokeIoctl(*(undefined8 *)(param_1 + 8),0x41018,0,0,&local_c0,8,
                                (undefined8 *)0x0);
      if (-1 < (int)uVar1) {
        *(undefined1 *)(param_1 + 0x10) = local_c0._5_1_;
        *(undefined1 *)(param_1 + 0x11) = local_c0._6_1_;
        *(undefined1 *)(param_1 + 0x12) = local_c0._7_1_;
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}



===== NVhdParserCheckPolicyValue @ 1c000dce0 =====

void NVhdParserCheckPolicyValue(undefined8 param_1,byte param_2,undefined8 param_3)

{
  uint local_res10 [6];
  
  local_res10[0] = (uint)param_2;
  NVhdParserQueryPolicyValue(param_1,local_res10[0],local_res10);
  *(bool *)param_3 = local_res10[0] != 0;
  return;
}



===== NVhdParserQueryPolicyValue @ 1c000dd20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 NVhdParserQueryPolicyValue(undefined8 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined1 auStack_78 [32];
  longlong *local_58;
  int *local_50;
  int local_48 [2];
  longlong local_40 [3];
  undefined1 local_28 [4];
  int local_24;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  local_40[0] = 0;
  local_48[0] = 0;
  local_58 = local_40;
  local_40[1] = 0;
  local_40[2] = 0;
  iVar1 = IoOpenDriverRegistryKey(NVhdDriverObject,0,0x20019,0);
  if (-1 < iVar1) {
    RtlInitUnicodeString(local_40 + 1,param_1);
    local_50 = local_48;
    local_58 = (longlong *)CONCAT44(local_58._4_4_,0x10);
    iVar1 = ZwQueryValueKey(local_40[0],local_40 + 1,2,local_28);
    if ((((-1 < iVar1) && (local_48[0] == 0x10)) && (local_24 == 4)) && (local_20 == 4)) {
      param_2 = local_1c;
    }
  }
  if (local_40[0] != 0) {
    ZwClose();
  }
  *param_3 = param_2;
  return 0;
}



===== NVhdParserFinishPausingEmulatedIo @ 1c000de30 =====

undefined8 NVhdParserFinishPausingEmulatedIo(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  if (*(char *)(param_1 + 0x17) == '\0') {
    return 0;
  }
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_1 + 0xa8,0);
  if (*(int *)(param_1 + 0xb0) == 2) {
    uVar3 = 0;
  }
  else if (*(int *)(param_1 + 0xb0) == 1) {
    ExWaitForRundownProtectionRelease(param_1 + 0xc0);
    ExRundownCompleted(param_1 + 0xc0);
    uVar3 = 0;
    if (*(char *)(param_1 + 0xb4) != '\0') {
      NVhdIoInvokeIoctl(*(undefined8 *)(param_1 + 8),0x2d1a2c,0,0,0,0,(undefined8 *)0x0);
      *(undefined1 *)(param_1 + 0xb4) = 0;
    }
    puVar2 = DvReleaseRundownBarrier((longlong *)(param_1 + 200),'\x01');
    while (puVar2 != (undefined8 *)0x0) {
      puVar1 = puVar2 + -1;
      puVar2 = (undefined8 *)*puVar2;
      NVhdParserIssueScsiRequest(param_1,(longlong *)*puVar1);
      DvExitRundownBarrier((longlong *)(param_1 + 200));
    }
    *(undefined4 *)(param_1 + 0xb0) = 2;
  }
  else {
    uVar3 = 0xc0000184;
  }
  ExReleasePushLockExclusiveEx(param_1 + 0xa8,0);
  KeLeaveCriticalRegion();
  return uVar3;
}



===== entry @ 1c000e010 =====

void entry(longlong param_1,ushort *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 1c000e044 =====

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



===== wil_InitializeFeatureStaging @ 1c000e078 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wil_InitializeFeatureStaging(void)

{
  bool bVar1;
  int iVar2;
  longlong *plVar3;
  undefined8 local_res8;
  
  bVar1 = false;
  if (g_wil_details_isFeatureStagingInitialized == 0) {
    g_wil_details_isFeatureStagingInitialized = 1;
    local_res8 = RtlQueryFeatureConfigurationChangeStamp();
    wil_details_PopulateInitialConfiguredFeatureStates();
    wil_details_EvaluateFeatureDependencies();
    plVar3 = (longlong *)&wil_details_featureDescriptors_z;
    while (plVar3 = wil_details_FeatureDescriptors_SkipPadding(plVar3), plVar3 != (longlong *)0x0) {
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
          g_wil_details_featureChangeNotification = 0;
        }
        break;
      }
      plVar3 = plVar3 + 7;
    }
    _g_wil_details_recordFeatureUsage = wil_details_RecordFeatureUsageReporting;
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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 1c000e168 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  int iVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 uVar4;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  plVar3 = (longlong *)&wil_details_featureDescriptors_z;
  do {
    plVar2 = wil_details_FeatureDescriptors_SkipPadding(plVar3);
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
    plVar3 = plVar2 + 7;
    *(undefined8 *)*plVar2 = local_38;
  } while( true );
}


