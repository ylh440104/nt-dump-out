
===== __report_gsfailure @ 140001010 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 14000101d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000101d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== FlAcpiConfigureFloppy @ 140001030 =====

undefined8 FlAcpiConfigureFloppy(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  byte bVar5;
  
  lVar4 = DriveMediaLimits;
  bVar5 = 0;
  if (*(char *)(param_2 + 0x21) == '\0') {
    return 0xc0000001;
  }
  iVar1 = *(int *)(param_2 + 0x28);
  if (iVar1 == 1) goto LAB_140001074;
  if (iVar1 != 2) {
    if (iVar1 == 3) {
      bVar5 = 2;
      goto LAB_140001074;
    }
    if (iVar1 == 4) {
      bVar5 = 3;
      goto LAB_140001074;
    }
    if (iVar1 == 5) {
      bVar5 = 4;
      goto LAB_140001074;
    }
  }
  bVar5 = 1;
LAB_140001074:
  *(byte *)(param_1 + 0xfe) = bVar5;
  lVar3 = DriveMediaConstants;
  lVar4 = (longlong)*(int *)(lVar4 + (ulonglong)bVar5 * 8) * 0x1c;
  uVar2 = ((undefined8 *)(lVar4 + DriveMediaConstants))[1];
  *(undefined8 *)(param_1 + 0x114) = *(undefined8 *)(lVar4 + DriveMediaConstants);
  *(undefined8 *)(param_1 + 0x11c) = uVar2;
  *(undefined8 *)(param_1 + 0x124) = *(undefined8 *)(lVar4 + 0x10 + lVar3);
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(lVar4 + 0x18 + lVar3);
  *(undefined1 *)(param_1 + 0x118) = *(undefined1 *)(param_2 + 0x38);
  *(undefined1 *)(param_1 + 0x119) = *(undefined1 *)(param_2 + 0x3c);
  *(undefined1 *)(param_1 + 0x11a) = *(undefined1 *)(param_2 + 0x40);
  *(undefined1 *)(param_1 + 0x11b) = *(undefined1 *)(param_2 + 0x44);
  *(undefined1 *)(param_1 + 0x11e) = *(undefined1 *)(param_2 + 0x48);
  *(undefined1 *)(param_1 + 0x11f) = *(undefined1 *)(param_2 + 0x4c);
  *(undefined1 *)(param_1 + 0x120) = *(undefined1 *)(param_2 + 0x54);
  *(undefined1 *)(param_1 + 0x121) = *(undefined1 *)(param_2 + 0x58);
  bVar5 = *(byte *)(param_2 + 0x5c);
  *(byte *)(param_1 + 0x122) = bVar5;
  *(ushort *)(param_1 + 0x124) = (ushort)*(byte *)(param_2 + 0x60) * 0x7d;
  *(short *)(param_1 + 0x126) = *(short *)(param_2 + 0x60) * 0x7d;
  *(undefined1 *)(param_1 + 0x128) = *(undefined1 *)(param_2 + 0x2c);
  *(undefined1 *)(param_1 + 300) = *(undefined1 *)(param_2 + 0x50);
  if (bVar5 < 0x12) {
    *(undefined1 *)(param_1 + 0x122) = 0x12;
  }
  return 0;
}



===== FlQueueIrpToThread @ 14000116c =====

undefined8 FlQueueIrpToThread(longlong param_1,longlong param_2)

{
  longlong lVar1;
  byte *pbVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  longlong lVar7;
  undefined8 local_res8;
  undefined8 local_res10;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  
  local_res8 = 0;
  ExAcquireFastMutex(param_2 + 0x1b8);
  if (*(char *)(param_2 + 0x1b0) == '\x01') {
    ExReleaseFastMutex();
    uVar6 = 0xc00002d3;
    *(undefined8 *)(param_1 + 0x38) = 0;
    *(undefined4 *)(param_1 + 0x30) = 0xc00002d3;
  }
  else {
    ExReleaseFastMutex(param_2 + 0x1b8);
    lVar1 = param_2 + 0x68;
    ExAcquireFastMutex(lVar1);
    piVar3 = (int *)(param_2 + 0xa0);
    *piVar3 = *piVar3 + 1;
    iVar4 = *piVar3;
    if (iVar4 == 0) {
      *(undefined4 *)(param_2 + 0xa0) = 1;
    }
    ExReleaseFastMutex(lVar1);
    pbVar2 = (byte *)(*(longlong *)(param_1 + 0xb8) + 3);
    *pbVar2 = *pbVar2 | 1;
    ExInterlockedInsertTailList(param_2 + 0xb0,param_1 + 0xa8,param_2 + 0x60);
    KeReleaseSemaphore(param_2 + 0x40,0,1);
    if (iVar4 == 0) {
      local_64 = 0;
      local_4c = 0;
      ExAcquireFastMutex(PagingMutex);
      PagingReferenceCount = PagingReferenceCount + 1;
      if (PagingReferenceCount == 1) {
        MmResetDriverPaging(DriverEntry);
      }
      ExReleaseFastMutex(PagingMutex);
      local_60 = 0;
      local_58 = 0;
      local_68 = 0x30;
      local_50 = 0x200;
      local_48 = 0;
      uStack_40 = 0;
      ExReleaseFastMutex(param_2 + 0x1f0);
      iVar4 = PsCreateSystemThread(&local_res8,0,&local_68,0,0,FloppyThread,param_2);
      if (-1 < iVar4) {
        iVar4 = ObReferenceObjectByHandle(local_res8,0x100000,0,0,(undefined8 *)(param_2 + 0xa8),0);
        ZwClose(local_res8);
      }
      ExAcquireFastMutex(param_2 + 0x1f0);
      if (iVar4 < 0) {
        *(undefined8 *)(param_2 + 0xa8) = 0;
        local_res10 = 0xffffffffff676980;
        ExAcquireFastMutex(lVar1);
        piVar3 = (int *)(param_2 + 0xa0);
        *piVar3 = *piVar3 + -1;
        iVar5 = *piVar3;
        while (-1 < iVar5) {
          iVar5 = KeWaitForSingleObject(param_2 + 0x40,0,0,0,&local_res10);
          if (iVar5 != 0x102) {
            lVar7 = ExInterlockedRemoveHeadList(param_2 + 0xb0);
            if (**(char **)(lVar7 + 0x10) != '\x1b') {
              *(int *)(lVar7 + -0x78) = iVar4;
              IofCompleteRequest();
            }
            *(int *)(param_2 + 0xa0) = *(int *)(param_2 + 0xa0) + -1;
          }
          iVar5 = *(int *)(param_2 + 0xa0);
        }
        ExReleaseFastMutex(lVar1);
        ExAcquireFastMutex(PagingMutex);
        PagingReferenceCount = PagingReferenceCount + -1;
        if (PagingReferenceCount == 0) {
          MmPageEntireDriver(DriverEntry);
        }
        ExReleaseFastMutex(PagingMutex);
      }
    }
    uVar6 = 0x103;
  }
  return uVar6;
}



===== FlTerminateFloppyThread @ 140001494 =====

void FlTerminateFloppyThread(longlong param_1)

{
  if (*(longlong *)(param_1 + 0xa8) != 0) {
    KeWaitForSingleObject(*(longlong *)(param_1 + 0xa8),0,0,0,0);
    if (*(longlong *)(param_1 + 0xa8) != 0) {
      ObfDereferenceObject();
    }
    *(undefined8 *)(param_1 + 0xa8) = 0;
  }
  return;
}



===== FloppyCancelQueuedRequest @ 1400014f0 =====

void FloppyCancelQueuedRequest(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  
  uVar2 = *(undefined8 *)(param_1 + 0x40);
  uVar6 = KeAcquireSpinLockRaiseToDpc(uVar2);
  *(undefined8 *)(param_2 + 0x38) = 0;
  plVar1 = (longlong *)(param_2 + 0xa8);
  lVar3 = *plVar1;
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  if (lVar3 != 0) {
    if ((*(longlong **)(lVar3 + 8) != plVar1) ||
       (plVar4 = *(longlong **)(param_2 + 0xb0), (longlong *)*plVar4 != plVar1)) {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3,uVar6);
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
  }
  KeReleaseSpinLock(uVar2);
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  IofCompleteRequest(param_2,0);
  return;
}



===== FloppyProcessQueuedRequests @ 14000158c =====

void FloppyProcessQueuedRequests(longlong param_1)

{
  longlong lVar1;
  char cVar2;
  undefined1 uVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  char *pcVar6;
  
  pcVar6 = (char *)0x0;
  do {
    do {
      uVar3 = KeAcquireSpinLockRaiseToDpc(param_1);
      puVar4 = (undefined8 *)ExInterlockedRemoveHeadList(param_1 + 0x20,param_1 + 0x30);
      if (puVar4 == (undefined8 *)0x0) {
        KeReleaseSpinLock(param_1,uVar3);
        return;
      }
      puVar5 = puVar4 + -0x15;
      LOCK();
      lVar1 = puVar4[-8];
      puVar4[-8] = 0;
      UNLOCK();
      if (lVar1 == 0) {
        *puVar4 = 0;
        puVar5 = (undefined8 *)0x0;
      }
      else {
        pcVar6 = (char *)puVar4[2];
      }
      KeReleaseSpinLock(param_1,uVar3);
    } while (puVar5 == (undefined8 *)0x0);
    if (*(char *)(param_1 + 0x19) == '\0') {
      cVar2 = *pcVar6;
      if ((cVar2 == '\x03') || (cVar2 == '\x04')) {
        FloppyReadWrite(*(longlong *)(param_1 + 0x38),(longlong)puVar5);
      }
      else {
        if (cVar2 != '\x0e') {
          *(undefined4 *)(puVar5 + 6) = 0xc0000001;
          goto LAB_1400015f7;
        }
        FloppyDeviceControl(*(longlong *)(param_1 + 0x38),(longlong)puVar5);
      }
    }
    else {
      *(undefined4 *)(puVar5 + 6) = 0xc0000056;
LAB_1400015f7:
      puVar5[7] = 0;
      IofCompleteRequest(puVar5,0);
    }
    ExAcquireFastMutex(PagingMutex);
    PagingReferenceCount = PagingReferenceCount + -1;
    if (PagingReferenceCount == 0) {
      MmPageEntireDriver(DriverEntry);
    }
    ExReleaseFastMutex(PagingMutex);
  } while( true );
}



===== FloppyQueueRequest @ 1400016e8 =====

undefined8 FloppyQueueRequest(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  longlong lVar2;
  undefined1 uVar3;
  
  ExAcquireFastMutex(PagingMutex);
  PagingReferenceCount = PagingReferenceCount + 1;
  if (PagingReferenceCount == 1) {
    MmResetDriverPaging(DriverEntry);
  }
  ExReleaseFastMutex(PagingMutex);
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_1);
  LOCK();
  *(code **)(param_2 + 0x68) = FloppyCancelQueuedRequest;
  UNLOCK();
  if (*(char *)(param_2 + 0x44) != '\0') {
    LOCK();
    lVar2 = *(longlong *)(param_2 + 0x68);
    *(longlong *)(param_2 + 0x68) = 0;
    UNLOCK();
    if (lVar2 != 0) {
      *(undefined8 *)(param_2 + 0x38) = 0;
      *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
      KeReleaseSpinLock(param_1,uVar3);
      IofCompleteRequest(param_2,0);
      ExAcquireFastMutex(PagingMutex);
      PagingReferenceCount = PagingReferenceCount + -1;
      if (PagingReferenceCount == 0) {
        MmPageEntireDriver(DriverEntry);
      }
      ExReleaseFastMutex(PagingMutex);
      return 0xc0000120;
    }
  }
  *(undefined4 *)(param_2 + 0x30) = 0x103;
  pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
  ExInterlockedInsertTailList(param_1 + 0x20,param_2 + 0xa8,param_1 + 0x30);
  KeReleaseSpinLock(param_1,uVar3);
  return 0x103;
}



===== FloppyStartDevice @ 140001850 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FloppyStartDevice(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined1 auStack_e8 [32];
  undefined4 *local_c8;
  uint *local_c0;
  code *local_b8;
  longlong local_b0;
  undefined4 local_a8;
  undefined4 local_a4 [3];
  undefined1 local_98;
  undefined1 local_97 [7];
  int local_90;
  undefined1 local_8c [4];
  undefined1 local_88 [4];
  uint local_84 [2];
  undefined4 local_7c;
  char local_78;
  char local_77;
  undefined4 local_34;
  undefined4 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_e8;
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_98 = 0;
  memset(local_97,0,0x6f);
  local_a4[0] = 0xd;
  local_a8 = 0x1a;
  IoForwardIrpSynchronously(*(undefined8 *)(lVar1 + 0x10),param_2);
  iVar2 = *(int *)(param_2 + 0x30);
  if (-1 < iVar2) {
    local_34 = 0;
    local_30 = 0;
    uVar4 = FlFdcDeviceIo(*(undefined8 *)(lVar1 + 0x10),0x70c0b,&local_98);
    iVar2 = (int)uVar4;
    if (-1 < iVar2) {
      *(undefined4 *)(lVar1 + 0xc4) = local_7c;
      if ((local_78 == '\0') || (local_77 == '\0')) {
        if (*(char *)(lVar1 + 0xfe) == '\x04') {
          *(byte *)(lVar1 + 0x14c) = *(byte *)(lVar1 + 0x14c) | (byte)(1 << (local_84[0] & 0x1f));
        }
        iVar3 = 0;
        do {
          local_b8 = FlConfigCallBack;
          local_c0 = local_84;
          local_c8 = &local_a8;
          local_b0 = lVar1;
          local_90 = iVar3;
          iVar2 = IoQueryDeviceDescription(&local_90,local_8c,local_a4,local_88);
          if (-1 < iVar2) goto LAB_14000199d;
          iVar3 = iVar3 + 1;
        } while (iVar3 < 0x12);
      }
      else {
        uVar5 = FlAcpiConfigureFloppy(lVar1,(longlong)&local_98);
        iVar2 = (int)uVar5;
        if (*(char *)(lVar1 + 0xfe) == '\x04') {
          *(byte *)(lVar1 + 0x14c) = *(byte *)(lVar1 + 0x14c) | (byte)(1 << (local_84[0] & 0x1f));
        }
      }
      if (-1 < iVar2) {
LAB_14000199d:
        *(byte *)(lVar1 + 0x110) = (byte)local_84[0];
        *(byte *)(lVar1 + 0x111) = '\x10' << ((byte)local_84[0] & 0x1f) | (byte)local_84[0];
        iVar3 = IoRegisterDeviceInterface
                          (*(undefined8 *)(lVar1 + 8),&MOUNTDEV_MOUNTED_DEVICE_GUID,0,lVar1 + 0x160)
        ;
        if (-1 < iVar3) {
          IoSetDeviceInterfaceState(lVar1 + 0x160,1);
          iVar3 = IoRegisterDeviceInterface
                            (*(undefined8 *)(lVar1 + 8),&GUID_DEVINTERFACE_FLOPPY,0,lVar1 + 0x170);
          if (-1 < iVar3) {
            IoSetDeviceInterfaceState(lVar1 + 0x170,1);
          }
        }
        *(undefined1 *)(lVar1 + 0x18) = 1;
        ExAcquireFastMutex(lVar1 + 0x1f0);
        *(undefined1 *)(lVar1 + 0x1a) = 0;
        ExReleaseFastMutex(lVar1 + 0x1f0);
        FloppyProcessQueuedRequests(lVar1);
      }
    }
  }
  *(int *)(param_2 + 0x30) = iVar2;
  IofCompleteRequest(param_2,0);
  return iVar2;
}



===== FloppyUnload @ 140001ab0 =====

void FloppyUnload(void)

{
  if (PagingMutex != 0) {
    ExFreePoolWithTag(PagingMutex,0);
    PagingMutex = 0;
  }
  return;
}



===== RtlStringCbPrintfA @ 140001ae4 =====

undefined8 RtlStringCbPrintfA(char *param_1,longlong param_2,char *param_3,undefined8 param_4)

{
  ulonglong _Count;
  int iVar1;
  undefined8 uVar2;
  undefined8 local_res20;
  
  if (param_2 - 1U < 0x7fffffff) {
    _Count = param_2 - 1;
    uVar2 = 0;
    local_res20 = param_4;
    iVar1 = _vsnprintf(param_1,_Count,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      param_1[_Count] = '\0';
      uVar2 = 0x80000005;
    }
    else if ((longlong)iVar1 == _Count) {
      param_1[_Count] = '\0';
    }
  }
  else {
    uVar2 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = '\0';
    }
  }
  return uVar2;
}



===== RtlStringCbPrintfW @ 140001b58 =====

undefined8
RtlStringCbPrintfW(wchar_t *param_1,ulonglong param_2,wchar_t *param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined8 local_res20;
  
  uVar2 = param_2 >> 1;
  if (uVar2 - 1 < 0x7fffffff) {
    uVar2 = uVar2 - 1;
    uVar3 = 0;
    local_res20 = param_4;
    iVar1 = _vsnwprintf(param_1,uVar2,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (uVar2 < (ulonglong)(longlong)iVar1)) {
      uVar3 = 0x80000005;
    }
    else if ((longlong)iVar1 != uVar2) {
      return 0;
    }
    param_1[uVar2] = L'\0';
  }
  else {
    uVar3 = 0xc000000d;
    if (uVar2 != 0) {
      *param_1 = L'\0';
    }
  }
  return uVar3;
}



===== __GSHandlerCheck @ 140001bd4 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140001bf8 =====

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



===== __cpu_features_init @ 140001c70 =====

/* WARNING: Removing unreachable block (ram,0x000140001cda) */
/* WARNING: Removing unreachable block (ram,0x000140001c89) */
/* WARNING: Removing unreachable block (ram,0x000140001c7a) */

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



===== _guard_check_icall @ 140001d40 =====

void _guard_check_icall(void)

{
  return;
}



===== __security_check_cookie @ 140001d60 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140001da0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140001da0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140001dd0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 140001e40 =====

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



===== memset @ 140002140 =====

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



===== __memset_repmovs @ 140002280 =====

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



===== __memset_query @ 140002300 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140002380 =====

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



===== __memset_spec_ermsb_repmovsb @ 1400024c0 =====

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



===== __memset_spec_plain @ 140002540 =====

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



===== FlAllocateIoBuffer @ 140008008 =====

void FlAllocateIoBuffer(longlong param_1,uint param_2)

{
  uint uVar1;
  longlong lVar2;
  undefined8 in_stack_ffffffffffffffd8;
  undefined4 uVar3;
  
  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffffd8 >> 0x20);
  if (*(longlong *)(param_1 + 0xd8) != 0) {
    if (param_2 <= *(uint *)(param_1 + 0xe8)) {
      return;
    }
    FlFreeIoBuffer(param_1);
  }
  uVar1 = *(uint *)(param_1 + 0xc4);
  if (uVar1 < param_2) {
    lVar2 = MmAllocateContiguousNodeMemory(param_2,0,0xffffff,0,CONCAT44(uVar3,0x204),0x80000000);
  }
  else {
    lVar2 = ExAllocatePool2(0x48,param_2,0x706f6c46);
  }
  *(longlong *)(param_1 + 0xd8) = lVar2;
  if (lVar2 != 0) {
    lVar2 = IoAllocateMdl(lVar2,param_2,0,0,0);
    *(longlong *)(param_1 + 0xe0) = lVar2;
    if (lVar2 == 0) {
      if (uVar1 < param_2) {
        MmFreeContiguousMemory();
      }
      else {
        ExFreePoolWithTag(*(undefined8 *)(param_1 + 0xd8),0);
      }
      *(undefined8 *)(param_1 + 0xd8) = 0;
    }
    else {
      MmProbeAndLockPages(lVar2,0,2);
      *(uint *)(param_1 + 0xe8) = param_2;
    }
  }
  return;
}



===== FlConfigCallBack @ 140008170 =====

undefined8 FlConfigCallBack(longlong param_1)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  byte bVar5;
  longlong lVar6;
  longlong lVar7;
  uint uVar8;
  ulonglong uVar9;
  longlong in_stack_00000058;
  
  lVar7 = *(longlong *)(in_stack_00000058 + 8);
  if ((ulonglong)*(uint *)(lVar7 + 0xc) + lVar7 == 0) {
    return 0xc000000d;
  }
  uVar9 = 0;
  lVar7 = (ulonglong)*(uint *)(lVar7 + 8) + lVar7;
  if (*(int *)(lVar7 + 0xc) != 0) {
    do {
      if (*(char *)(lVar7 + 0x10 + uVar9 * 0x14) == '\x05') {
        iVar2 = *(int *)(lVar7 + 0x30 + uVar9 * 0x14);
        if (iVar2 == 0x168) {
          bVar5 = 0;
        }
        else if ((iVar2 == 0x4a1) || (iVar2 == 0x4b0)) {
LAB_1400081e6:
          bVar5 = 1;
        }
        else if ((iVar2 == 0x58f) || (iVar2 == 0x5a0)) {
          bVar5 = 3;
        }
        else {
          if (iVar2 != 0xb40) goto LAB_1400081e6;
          bVar5 = 4;
        }
        *(byte *)(param_1 + 0xfe) = bVar5;
        lVar4 = DriveMediaConstants;
        lVar6 = (longlong)*(int *)(DriveMediaLimits + (ulonglong)bVar5 * 8) * 0x1c;
        uVar3 = ((undefined8 *)(lVar6 + DriveMediaConstants))[1];
        *(undefined8 *)(param_1 + 0x114) = *(undefined8 *)(lVar6 + DriveMediaConstants);
        *(undefined8 *)(param_1 + 0x11c) = uVar3;
        *(undefined8 *)(param_1 + 0x124) = *(undefined8 *)(lVar6 + 0x10 + lVar4);
        *(undefined4 *)(param_1 + 300) = *(undefined4 *)(lVar6 + 0x18 + lVar4);
        if (1 < *(ushort *)(lVar7 + 0x24 + uVar9 * 0x14)) {
          *(undefined1 *)(param_1 + 0x118) = *(undefined1 *)(lVar7 + 0x38 + uVar9 * 0x14);
          *(undefined1 *)(param_1 + 0x119) = *(undefined1 *)(lVar7 + 0x39 + uVar9 * 0x14);
          *(undefined1 *)(param_1 + 0x11a) = *(undefined1 *)(lVar7 + 0x3a + uVar9 * 0x14);
          *(undefined1 *)(param_1 + 0x11b) = *(undefined1 *)(lVar7 + 0x3b + uVar9 * 0x14);
          cVar1 = *(char *)(lVar7 + 0x3c + uVar9 * 0x14);
          if (cVar1 == '\0') {
            return 0;
          }
          if (*(int *)(lVar7 + 0x30 + uVar9 * 0x14) == 0) {
            return 0;
          }
          *(char *)(param_1 + 0x11e) = cVar1;
          *(undefined1 *)(param_1 + 0x11f) = *(undefined1 *)(lVar7 + 0x3d + uVar9 * 0x14);
          *(undefined1 *)(param_1 + 0x120) = *(undefined1 *)(lVar7 + 0x3f + uVar9 * 0x14);
          *(undefined1 *)(param_1 + 0x121) = *(undefined1 *)(lVar7 + 0x40 + uVar9 * 0x14);
          bVar5 = *(byte *)(lVar7 + 0x41 + uVar9 * 0x14);
          *(byte *)(param_1 + 0x122) = bVar5;
          if (bVar5 < 0x12) {
            *(undefined1 *)(param_1 + 0x122) = 0x12;
          }
          *(ushort *)(param_1 + 0x124) = (ushort)*(byte *)(lVar7 + 0x42 + uVar9 * 0x14) * 0x7d;
          *(ushort *)(param_1 + 0x126) = (ushort)*(byte *)(lVar7 + 0x42 + uVar9 * 0x14) * 0x7d;
          cVar1 = *(char *)(lVar7 + 0x43 + uVar9 * 0x14);
          if (cVar1 == '\0') {
            return 0;
          }
          *(char *)(param_1 + 0x128) = cVar1;
          *(undefined1 *)(param_1 + 300) = *(undefined1 *)(lVar7 + 0x3e + uVar9 * 0x14);
        }
      }
      uVar8 = (int)uVar9 + 1;
      uVar9 = (ulonglong)uVar8;
    } while (uVar8 < *(uint *)(lVar7 + 0xc));
  }
  return 0;
}



===== FlConsolidateMediaTypeWithBootSector @ 140008320 =====

void FlConsolidateMediaTypeWithBootSector(longlong param_1,char *param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  bool bVar6;
  longlong lVar7;
  byte *pbVar8;
  int iVar9;
  uint uVar10;
  ushort uVar11;
  
  if ((*param_2 + 0x17U & 0xfd) == 0) {
    uVar2 = *(ushort *)(param_2 + 0x1a);
    uVar5 = *(ushort *)(param_2 + 0x13);
    uVar3 = *(ushort *)(param_2 + 0x18);
    uVar4 = *(ushort *)(param_2 + 0xb);
    if ((uVar2 != 0) && (uVar3 != 0)) {
      uVar10 = 0;
      iVar9 = 0;
      uVar11 = (short)(((ulonglong)(uint)uVar5 / (ulonglong)uVar2) /
                      (ulonglong)(longlong)(int)(uint)uVar3) - 1;
      pbVar8 = (byte *)(DriveMediaConstants + 10);
      do {
        if ((((uVar4 == *(ushort *)(pbVar8 + -2)) && (uVar3 == *pbVar8)) && (uVar11 == pbVar8[10]))
           && ((uVar2 == pbVar8[0xd] && (param_2[0x15] == pbVar8[0xf])))) {
          iVar9 = *(int *)((ulonglong)uVar10 * 0x1c + DriveMediaConstants);
          break;
        }
        uVar10 = uVar10 + 1;
        pbVar8 = pbVar8 + 0x1c;
      } while (uVar10 < 0x11);
      bVar1 = *(byte *)(param_1 + 0xfe);
      if (bVar1 == 3) {
        if (iVar9 == 1) {
          iVar9 = 0x11;
        }
        else if (iVar9 == 0xf) {
          iVar9 = 0xe;
        }
        else if (iVar9 == 0x10) {
          iVar9 = 5;
        }
        else if (iVar9 == 0x13) {
          iVar9 = 0x12;
        }
      }
      if (iVar9 != *(int *)(param_1 + 0x108)) {
        if (((uVar4 != *(ushort *)(param_1 + 0x138)) || (0xff < uVar3)) ||
           ((uVar11 != *(byte *)(param_1 + 0x144) ||
            (bVar6 = true, *(byte *)(param_1 + 0x147) < uVar2)))) {
          bVar6 = false;
        }
        if (iVar9 == 0) {
          iVar9 = *(int *)(param_1 + 0x130);
          *(undefined1 *)(param_1 + 0x14a) = 0;
        }
        if (bVar6) {
          for (uVar10 = *(uint *)(DriveMediaLimits + 4 + (ulonglong)bVar1 * 8);
              uVar10 <= *(uint *)(DriveMediaLimits + (ulonglong)bVar1 * 8); uVar10 = uVar10 + 1) {
            if (iVar9 == *(int *)((ulonglong)uVar10 * 0x1c + DriveMediaConstants)) {
              *(uint *)(param_1 + 0x10c) = uVar10;
              break;
            }
          }
          *(int *)(param_1 + 0x108) = iVar9;
          *(char *)(param_1 + 0x13a) = (char)uVar3;
          *(char *)(param_1 + 0x147) = (char)uVar2;
          *(uint *)(param_1 + 0x104) = (uint)uVar4 * (uint)uVar5;
          lVar7 = RtlCompareMemory(param_2 + 3,"MSDMF3.",7);
          if (lVar7 == 7) {
            *(undefined1 *)(param_1 + 0x112) = 1;
          }
        }
      }
    }
  }
  return;
}



===== FlDatarateSpecifyConfigure @ 140008564 =====

void FlDatarateSpecifyConfigure(longlong param_1)

{
  undefined1 *puVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  if (*(char *)(param_1 + 0x14d) != '\0') {
    puVar1 = (undefined1 *)(param_1 + 200);
    *(undefined2 *)(param_1 + 0xc9) = 0x1f00;
    *puVar1 = 0x11;
    if (*(char *)(param_1 + 0x145) == '\0') {
      *(undefined1 *)(param_1 + 0xca) = 0x5f;
    }
    *(undefined1 *)(param_1 + 0xcb) = 0;
    iVar2 = FlIssueCommand(param_1,puVar1,puVar1,0,0,0);
    if (iVar2 == -0x3fffff5d) {
      *(undefined1 *)(param_1 + 0x14d) = 0;
    }
    else if (iVar2 < 0) goto LAB_140008634;
  }
  puVar1 = (undefined1 *)(param_1 + 200);
  *(undefined1 *)(param_1 + 0xc9) = *(undefined1 *)(param_1 + 0x134);
  *(undefined1 *)(param_1 + 0xca) = *(undefined1 *)(param_1 + 0x135);
  *puVar1 = 0xd;
  iVar2 = FlIssueCommand(param_1,puVar1,puVar1,0,0,0);
  if (-1 < iVar2) {
    uVar3 = FlFdcDeviceIo(*(undefined8 *)(param_1 + 0x10),0x70c27,param_1 + 0x146);
    if (-1 < (int)uVar3) {
      uVar4 = FlRecalibrateDrive(param_1);
      if (-1 < (int)uVar4) {
        uVar5 = *(undefined4 *)(param_1 + 0x10c);
      }
    }
  }
LAB_140008634:
  *(undefined4 *)(param_1 + 0xf8) = uVar5;
  return;
}



===== FlDetermineMediaType @ 14000864c =====

int FlDetermineMediaType(longlong param_1)

{
  byte *pbVar1;
  undefined8 *puVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  bool bVar9;
  int iVar10;
  longlong lVar11;
  longlong lVar12;
  uint uVar13;
  undefined4 *puVar14;
  undefined4 local_res8;
  undefined4 local_resc;
  
  *(undefined1 *)(param_1 + 0x112) = 0;
  uVar13 = 0;
  do {
    if (uVar13 != 0) {
      FlInitializeControllerHardware(param_1);
    }
    lVar11 = DriveMediaConstants;
    iVar10 = *(int *)(DriveMediaLimits + (ulonglong)*(byte *)(param_1 + 0xfe) * 8);
    lVar12 = (longlong)iVar10 * 0x1c;
    *(int *)(param_1 + 0x10c) = iVar10;
    bVar9 = false;
    uVar8 = ((undefined8 *)(lVar12 + lVar11))[1];
    *(undefined8 *)(param_1 + 0x130) = *(undefined8 *)(lVar12 + lVar11);
    *(undefined8 *)(param_1 + 0x138) = uVar8;
    *(undefined8 *)(param_1 + 0x140) = *(undefined8 *)(lVar12 + 0x10 + lVar11);
    *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(lVar12 + 0x18 + lVar11);
    do {
      iVar10 = FlDatarateSpecifyConfigure(param_1);
      if (iVar10 < 0) break;
      pbVar1 = (byte *)(param_1 + 200);
      puVar14 = (undefined4 *)((longlong)*(int *)(param_1 + 0x10c) * 0x1c + DriveMediaConstants);
      cVar3 = *(char *)((longlong)puVar14 + 0x17);
      *pbVar1 = 0x54;
      *(byte *)(param_1 + 0xc9) = (cVar3 + -1) * '\x04' | *(byte *)(param_1 + 0x110);
      iVar10 = FlIssueCommand(param_1,pbVar1,pbVar1,0,0,0);
      if ((((-1 < iVar10) &&
           ((byte)(*pbVar1 & 0xdf) ==
            (byte)((*(char *)((longlong)puVar14 + 0x17) + -1) * '\x04' | *(byte *)(param_1 + 0x110))
           )) && (*(char *)(param_1 + 0xc9) == '\0')) && (*(char *)(param_1 + 0xca) == '\0')) {
LAB_1400087ed:
        if (bVar9) {
          return iVar10;
        }
        *(undefined4 *)(param_1 + 0x108) = *puVar14;
        *(uint *)(param_1 + 0x100) = (uint)*(ushort *)(puVar14 + 2);
        *(uint *)(param_1 + 0x104) =
             (*(byte *)(puVar14 + 5) + 1) * (uint)*(byte *)((longlong)puVar14 + 0x17) *
             (uint)*(byte *)((longlong)puVar14 + 10) * (uint)*(ushort *)(puVar14 + 2);
        lVar11 = DriveMediaConstants;
        lVar12 = (longlong)*(int *)(param_1 + 0x10c) * 0x1c;
        puVar14 = (undefined4 *)(lVar12 + DriveMediaConstants);
        uVar5 = puVar14[1];
        uVar6 = puVar14[2];
        uVar7 = puVar14[3];
        *(undefined4 *)(param_1 + 0x130) = *puVar14;
        *(undefined4 *)(param_1 + 0x134) = uVar5;
        *(undefined4 *)(param_1 + 0x138) = uVar6;
        *(undefined4 *)(param_1 + 0x13c) = uVar7;
        *(undefined8 *)(param_1 + 0x140) = *(undefined8 *)(lVar12 + 0x10 + lVar11);
        *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(lVar12 + 0x18 + lVar11);
        lVar11 = ExAllocatePool2(0x48,0x200,0x706f6c46);
        if (lVar11 == 0) {
          return iVar10;
        }
        local_resc = 0;
        local_res8 = 0;
        lVar12 = IoBuildAsynchronousFsdRequest
                           (3,*(undefined8 *)(param_1 + 0x38),lVar11,0x200,&local_res8,0);
        if (lVar12 != 0) {
          *(char *)(lVar12 + 0x43) = *(char *)(lVar12 + 0x43) + -1;
          *(longlong *)(lVar12 + 0xb8) = *(longlong *)(lVar12 + 0xb8) + -0x48;
          FlReadWrite(param_1,lVar12,'\x01');
          MmUnlockPages(*(undefined8 *)(lVar12 + 8));
          IoFreeMdl(*(undefined8 *)(lVar12 + 8));
          IoFreeIrp(lVar12);
        }
        ExFreePoolWithTag(lVar11,0);
        return iVar10;
      }
      iVar4 = *(int *)(param_1 + 0x10c);
      *(int *)(param_1 + 0x10c) = iVar4 + -1;
      lVar11 = DriveMediaConstants;
      lVar12 = (longlong)iVar4 * 0x1c;
      puVar2 = (undefined8 *)(lVar12 + -0x1c + DriveMediaConstants);
      uVar8 = puVar2[1];
      *(undefined8 *)(param_1 + 0x130) = *puVar2;
      *(undefined8 *)(param_1 + 0x138) = uVar8;
      *(undefined8 *)(param_1 + 0x140) = *(undefined8 *)(lVar12 + -0xc + lVar11);
      *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(lVar12 + -4 + lVar11);
      if (iVar10 != -0x3fffff5d) {
        iVar10 = -0x3fffffec;
      }
      if (*(char *)(param_1 + 0x10c) <
          *(char *)(DriveMediaLimits + 4 + (ulonglong)*(byte *)(param_1 + 0xfe) * 8)) {
        *(undefined4 *)(param_1 + 0x108) = 0;
        bVar9 = true;
      }
      if (-1 < iVar10) goto LAB_1400087ed;
    } while (!bVar9);
    uVar13 = uVar13 + 1;
    if (2 < uVar13) {
      return iVar10;
    }
  } while( true );
}



===== FlFdcDeviceIo @ 140008948 =====

ulonglong FlFdcDeviceIo(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong local_38 [6];
  
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  KeInitializeEvent(local_38 + 2,0,0);
  lVar1 = IoBuildDeviceIoControlRequest(param_2,param_1,0,0,0,0,1,local_38 + 2,local_38);
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    *(undefined8 *)(*(longlong *)(lVar1 + 0xb8) + -0x28) = param_3;
    uVar2 = IofCallDriver(param_1,lVar1);
    if ((int)uVar2 == 0x103) {
      KeWaitForSingleObject(local_38 + 2,0,0,0,0);
      uVar2 = local_38[0] & 0xffffffff;
    }
  }
  return uVar2;
}



===== FlFormat @ 140008a38 =====

ulonglong FlFormat(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  int *piVar2;
  undefined8 uVar3;
  bool bVar4;
  longlong lVar5;
  byte bVar6;
  int iVar7;
  longlong lVar8;
  int *piVar9;
  byte bVar10;
  byte bVar11;
  int *piVar12;
  byte bVar13;
  uint uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  byte bVar17;
  bool bVar18;
  ushort local_res10 [4];
  uint local_res18;
  undefined4 local_res20;
  undefined8 local_58;
  
  piVar2 = *(int **)(param_2 + 0x18);
  local_58 = 0;
  local_res10[0] = 0;
  bVar17 = 0;
  uVar14 = *(uint *)(DriveMediaLimits + (ulonglong)*(byte *)(param_1 + 0xfe) * 8);
  uVar15 = (ulonglong)(int)uVar14;
  iVar7 = *piVar2;
  bVar4 = false;
  local_res18 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  piVar9 = piVar2;
  if (*(int *)(*(longlong *)(param_2 + 0xb8) + 0x18) != 0x7c02c) {
    piVar9 = (int *)0x0;
  }
  piVar12 = (int *)(uVar15 * 0x1c + DriveMediaConstants);
  if (*piVar12 != iVar7) {
    uVar16 = uVar15;
    do {
      uVar14 = (uint)uVar16;
      if ((longlong)uVar15 <=
          (longlong)*(int *)(DriveMediaLimits + 4 + (ulonglong)*(byte *)(param_1 + 0xfe) * 8))
      break;
      piVar12 = piVar12 + -7;
      uVar14 = uVar14 - 1;
      uVar16 = (ulonglong)uVar14;
      uVar15 = uVar15 - 1;
    } while (*piVar12 != iVar7);
  }
  *(int *)(param_1 + 0x108) = iVar7;
  *(uint *)(param_1 + 0x10c) = uVar14;
  lVar5 = DriveMediaConstants;
  lVar8 = (longlong)(int)uVar14 * 0x1c;
  uVar3 = ((undefined8 *)(lVar8 + DriveMediaConstants))[1];
  *(undefined8 *)(param_1 + 0x130) = *(undefined8 *)(lVar8 + DriveMediaConstants);
  *(undefined8 *)(param_1 + 0x138) = uVar3;
  *(undefined8 *)(param_1 + 0x140) = *(undefined8 *)(lVar8 + 0x10 + lVar5);
  *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(lVar8 + 0x18 + lVar5);
  if (piVar9 != (int *)0x0) {
    *(undefined1 *)(param_1 + 0x13a) = *(undefined1 *)((longlong)piVar9 + 0x16);
    *(char *)(param_1 + 0x13c) = (char)piVar9[5];
  }
  *(uint *)(param_1 + 0x100) = (uint)*(ushort *)(param_1 + 0x138);
  bVar10 = *(byte *)(param_1 + 0x147);
  *(uint *)(param_1 + 0x104) =
       (*(byte *)(param_1 + 0x144) + 1) * (uint)bVar10 * (uint)*(byte *)(param_1 + 0x13a) *
       (uint)*(ushort *)(param_1 + 0x138);
  iVar7 = (uint)*(byte *)(piVar2 + 2) * (uint)bVar10;
  local_res20 = CONCAT31((int3)((uint)iVar7 >> 8),(char)iVar7 + (char)piVar2[4]);
  bVar10 = (char)piVar2[1] * bVar10 + (char)piVar2[3];
  if ((*(uint *)(param_1 + 0xf8) != uVar14) &&
     (uVar15 = FlDatarateSpecifyConfigure(param_1), (int)uVar15 < 0)) {
    return uVar15;
  }
  *(undefined1 *)(param_1 + 0x112) = 0;
  pbVar1 = (byte *)(param_1 + 200);
  do {
    *pbVar1 = 0x10;
    *(undefined1 *)(param_1 + 0xc9) = *(undefined1 *)(param_1 + 0x110);
    *(byte *)(param_1 + 0xca) =
         bVar10 / *(byte *)(param_1 + 0x147) << (*(byte *)(param_1 + 0x145) & 0x1f);
    uVar15 = FlIssueCommand(param_1,pbVar1,pbVar1,0,0,0);
    if ((int)uVar15 < 0) {
      return uVar15;
    }
    if (((*pbVar1 & 0x20) == 0) ||
       (*(char *)(param_1 + 0xc9) !=
        (byte)(bVar10 / *(byte *)(param_1 + 0x147) << (*(byte *)(param_1 + 0x145) & 0x1f)))) {
      *(undefined1 *)(param_1 + 0xc0) = 1;
      return 0xc0000168;
    }
    local_58 = CONCAT44(0xffffffff,(uint)*(byte *)(param_1 + 0x13e) * -10000);
    KeDelayExecutionThread(0,0,&local_58);
    *pbVar1 = 0x54;
    *(undefined1 *)(param_1 + 0xc9) = *(undefined1 *)(param_1 + 0x110);
    uVar15 = FlIssueCommand(param_1,pbVar1,pbVar1,0,0,0);
    if ((int)uVar15 < 0) {
      return uVar15;
    }
    bVar11 = 0;
    if (*(char *)(param_1 + 0x13a) != '\0') {
      do {
        *(byte *)(*(longlong *)(param_1 + 0xd8) + (ulonglong)bVar11 * 4) =
             bVar10 / *(byte *)(param_1 + 0x147);
        *(byte *)(*(longlong *)(param_1 + 0xd8) + 1 + (ulonglong)bVar11 * 4) =
             bVar10 % *(byte *)(param_1 + 0x147);
        bVar13 = bVar11 + 1;
        if (piVar9 == (int *)0x0) {
          bVar6 = bVar13;
        }
        else {
          bVar6 = *(byte *)((longlong)piVar9 + (ulonglong)bVar11 * 2 + 0x18);
        }
        *(byte *)(*(longlong *)(param_1 + 0xd8) + 2 + (ulonglong)bVar11 * 4) = bVar6;
        *(undefined1 *)(*(longlong *)(param_1 + 0xd8) + 3 + (ulonglong)bVar11 * 4) =
             *(undefined1 *)(param_1 + 0x137);
        bVar11 = bVar13;
      } while (bVar13 < *(byte *)(param_1 + 0x13a));
    }
    bVar11 = 0;
    do {
      *pbVar1 = 0x47;
      *(byte *)(param_1 + 0xc9) =
           bVar10 % *(byte *)(param_1 + 0x147) << 2 | *(byte *)(param_1 + 0x110);
      *(undefined1 *)(param_1 + 0xca) = *(undefined1 *)(param_1 + 0x137);
      *(undefined1 *)(param_1 + 0xcb) = *(undefined1 *)(param_1 + 0x13a);
      *(undefined1 *)(param_1 + 0xcc) = *(undefined1 *)(param_1 + 0x13c);
      *(undefined1 *)(param_1 + 0xcd) = *(undefined1 *)(param_1 + 0x13d);
      uVar14 = FlIssueCommand(param_1,pbVar1,pbVar1,*(undefined8 *)(param_1 + 0xe0),0,
                              (uint)*(ushort *)(param_1 + 0x138));
      uVar15 = (ulonglong)uVar14;
      if (-1 < (int)uVar14) {
        if ((((*pbVar1 & 0xd0) == 0) && ((*(byte *)(param_1 + 0xc9) & 0x10) == 0)) &&
           (*(char *)(param_1 + 0xca) == '\0')) goto LAB_140008e3a;
        *(undefined1 *)(param_1 + 0xc0) = 1;
        uVar14 = FlInterpretError(*(byte *)(param_1 + 0xc9),*(byte *)(param_1 + 0xca));
        uVar15 = (ulonglong)uVar14;
        if (-1 < (int)uVar14) goto LAB_140008e3a;
      }
      bVar18 = bVar11 < 3;
      bVar11 = bVar11 + 1;
    } while (bVar18);
    if ((int)uVar15 < 0) {
      uVar15 = FlFdcDeviceIo(*(undefined8 *)(param_1 + 0x10),0x70c23,local_res10);
      uVar15 = uVar15 & 0xffffffff;
      if ((*(char *)(param_1 + 0xfe) != '\0') && ((local_res10[0] & 0x80) != 0)) {
        return 0xc0000013;
      }
      if (local_res18 < (uint)bVar17 * 2 + 2) {
        bVar4 = true;
      }
      else {
        *(ushort *)(*(longlong *)(param_2 + 0x18) + (ulonglong)bVar17 * 2) = (ushort)bVar10;
        *(longlong *)(param_2 + 0x38) = *(longlong *)(param_2 + 0x38) + 2;
      }
      bVar17 = bVar17 + 1;
    }
LAB_140008e3a:
    bVar10 = bVar10 + 1;
    if ((byte)local_res20 < bVar10) {
      if ((-1 < (int)uVar15) && (bVar4)) {
        uVar15 = 0x80000005;
      }
      return uVar15;
    }
  } while( true );
}



===== FlFreeIoBuffer @ 140008e94 =====

void FlFreeIoBuffer(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (*(longlong *)(param_1 + 0xd8) != 0) {
    uVar1 = *(uint *)(param_1 + 0xe8);
    *(undefined4 *)(param_1 + 0xe8) = 0;
    uVar2 = *(uint *)(param_1 + 0xc4);
    MmUnlockPages(*(undefined8 *)(param_1 + 0xe0));
    IoFreeMdl(*(undefined8 *)(param_1 + 0xe0));
    *(undefined8 *)(param_1 + 0xe0) = 0;
    if (uVar2 < uVar1) {
      MmFreeContiguousMemory();
    }
    else {
      ExFreePoolWithTag(*(undefined8 *)(param_1 + 0xd8),0);
    }
    *(undefined8 *)(param_1 + 0xd8) = 0;
  }
  return;
}



===== FlInitializeControllerHardware @ 140008f38 =====

void FlInitializeControllerHardware(longlong param_1)

{
  undefined1 *puVar1;
  ulonglong uVar2;
  
  uVar2 = FlFdcDeviceIo(*(undefined8 *)(param_1 + 0x10),0x70c17,0);
  if ((-1 < (int)uVar2) && (*(byte *)(param_1 + 0x14c) != 0)) {
    puVar1 = (undefined1 *)(param_1 + 200);
    *(byte *)(param_1 + 0xc9) = (*(byte *)(param_1 + 0x14c) | 0xe0) << 2;
    *puVar1 = 0x15;
    FlIssueCommand(param_1,puVar1,puVar1,0,0,0);
  }
  return;
}



===== FlInterpretError @ 140008fa0 =====

uint FlInterpretError(byte param_1,byte param_2)

{
  if (((param_1 | param_2) & 0x20) != 0) {
    return 0xc000003f;
  }
  if ((param_1 & 0x10) != 0) {
    return 0xc000003c;
  }
  if ((param_1 & 0x84) != 0) {
    return 0xc0000015;
  }
  if ((param_2 & 0x43) != 0) {
    return 0xc000009c;
  }
  if ((param_1 & 2) != 0) {
    return 0xc00000a2;
  }
  if ((param_1 & 1) == 0) {
    return (byte)~param_2 >> 4 & 1 | 0xc0000166;
  }
  return 0xc0000165;
}



===== FlIssueCommand @ 140009004 =====

void FlIssueCommand(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   undefined4 param_5,undefined4 param_6)

{
  ulonglong uVar1;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_14 = 0;
  local_20 = param_5;
  local_1c = param_6;
  local_18 = 4;
  local_38 = param_2;
  local_30 = param_3;
  local_28 = param_4;
  uVar1 = FlFdcDeviceIo(*(undefined8 *)(param_1 + 0x10),0x70c0f,&local_38);
  if (((int)uVar1 == -0x3fffff5d) || ((int)uVar1 == -0x3ffffe98)) {
    *(undefined1 *)(param_1 + 0xc0) = 1;
  }
  return;
}



===== FlReadWrite @ 140009074 =====

ulonglong FlReadWrite(longlong param_1,longlong param_2,char param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  char *pcVar4;
  longlong lVar5;
  ulonglong uVar6;
  byte bVar7;
  uint uVar8;
  ulonglong uVar9;
  char cVar10;
  byte bVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  byte bVar15;
  uint uVar16;
  uint uVar17;
  byte bVar18;
  byte bVar19;
  int iVar20;
  byte bVar21;
  uint uVar22;
  uint local_74;
  char *local_60;
  undefined8 local_50;
  void *local_48;
  
  pcVar4 = *(char **)(param_2 + 0xb8);
  local_48 = (void *)0x0;
  if (*pcVar4 == '\x04') {
    if (*(char *)(param_1 + 0x112) != '\0') {
      return 0xc000000d;
    }
    cVar10 = '\x01';
  }
  else {
    cVar10 = '\0';
  }
  if (param_3 == '\0') {
    uVar9 = FlStartDrive(param_1,param_2,cVar10,'\x01',(byte)pcVar4[2] >> 1 & 1);
    uVar8 = (uint)uVar9;
    if ((int)uVar8 < 0) {
      return uVar9;
    }
  }
  else {
    uVar8 = 0;
  }
  if (*(int *)(param_1 + 0x108) == 0) {
    uVar9 = 0xc0000014;
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x13a);
    bVar21 = *(char *)(param_1 + 0x137) + 7;
    bVar2 = *(byte *)(param_1 + 0x147);
    uVar13 = *(uint *)(pcVar4 + 0x18) >> (bVar21 & 0x1f);
    lVar5 = *(longlong *)(param_2 + 8);
    uVar22 = (*(uint *)(pcVar4 + 8) >> (bVar21 & 0x1f)) + uVar13;
    if ((*(byte *)(lVar5 + 10) & 5) == 0) {
      local_60 = (char *)MmMapLockedPagesSpecifyCache(lVar5,0,1,0,0,0x40000020);
    }
    else {
      local_60 = *(char **)(lVar5 + 0x18);
    }
    if (local_60 == (char *)0x0) {
LAB_140009417:
      uVar9 = 0xc000009a;
    }
    else {
      bVar3 = *(byte *)(param_1 + 0x14a);
      local_74 = 0;
      uVar16 = (uint)bVar1 << (bVar21 & 0x1f);
      uVar14 = uVar13;
      if (uVar13 < uVar22) {
        do {
          uVar9 = (ulonglong)uVar14 / (ulonglong)bVar1;
          uVar6 = (ulonglong)uVar14 % (ulonglong)bVar1;
          uVar12 = (uint)uVar6;
          bVar18 = (byte)uVar6;
          bVar19 = bVar1 - bVar18;
          if (uVar22 - uVar14 < (uint)bVar19) {
            bVar19 = (char)uVar22 - (char)uVar14;
          }
          if (*(uint *)(param_1 + 0xc4) < uVar16) {
            FlAllocateIoBuffer(param_1,uVar16);
            local_48 = *(void **)(param_1 + 0xd8);
            if (local_48 == (void *)0x0) goto LAB_140009417;
            iVar20 = 0;
            local_50 = *(undefined8 *)(param_1 + 0xe0);
            if (cVar10 != '\0') {
              memcpy(local_48,local_60 + (uVar14 - uVar13 << (bVar21 & 0x1f)),
                     (ulonglong)((uint)bVar19 << (bVar21 & 0x1f)));
            }
          }
          else {
            local_50 = *(undefined8 *)(param_2 + 8);
            iVar20 = uVar14 - uVar13 << (bVar21 & 0x1f);
          }
          bVar11 = -(local_74 < bVar19 + uVar12) & (byte)local_74;
          uVar17 = (uint)bVar11;
          if (bVar11 < bVar18) {
            uVar17 = uVar12;
          }
          bVar15 = (byte)uVar17;
          bVar11 = (byte)(uVar9 % (ulonglong)bVar2);
          bVar7 = (byte)(uVar9 / bVar2);
          uVar8 = FlReadWriteTrack(param_1,local_50,(uVar17 - uVar12 << (bVar21 & 0x1f)) + iVar20,
                                   cVar10,bVar7,bVar11,bVar15,(bVar19 - bVar15) + bVar18,'\x01');
          if (((int)uVar8 < 0) || (bVar15 <= bVar18)) {
            uVar17 = (bVar19 + uVar12) % (uint)bVar1;
          }
          else {
            uVar8 = FlReadWriteTrack(param_1,local_50,iVar20,cVar10,bVar7,bVar11,bVar18,
                                     bVar15 - bVar18,'\0');
          }
          if ((int)uVar8 < 0) break;
          if ((cVar10 == '\0') && (*(uint *)(param_1 + 0xc4) < uVar16)) {
            memcpy(local_60 + (uVar14 - uVar13 << (bVar21 & 0x1f)),local_48,
                   (ulonglong)((uint)bVar19 << (bVar21 & 0x1f)));
          }
          local_74 = (bVar3 + uVar17) % (uint)bVar1;
          uVar14 = uVar14 + bVar19;
        } while (uVar14 < uVar22);
      }
      *(ulonglong *)(param_2 + 0x38) = (ulonglong)(uVar14 - uVar13 << (bVar21 & 0x1f));
      if ((-1 < (int)uVar8) && (uVar13 == 0)) {
        FlConsolidateMediaTypeWithBootSector(param_1,local_60);
      }
      uVar9 = (ulonglong)uVar8;
    }
  }
  return uVar9;
}



===== FlReadWriteTrack @ 140009440 =====

uint FlReadWriteTrack(longlong param_1,undefined8 param_2,int param_3,char param_4,byte param_5,
                     byte param_6,char param_7,byte param_8,char param_9)

{
  byte *pbVar1;
  bool bVar2;
  uint uVar3;
  byte bVar4;
  byte bVar5;
  uint local_58;
  uint local_54;
  int local_48 [4];
  
  bVar4 = *(char *)(param_1 + 0x137) + 7;
  local_54 = 0;
  bVar2 = false;
  local_48[0] = (uint)*(byte *)(param_1 + 0x13e) * -10000;
  local_48[1] = 0xffffffff;
  local_58 = 0;
  do {
    if (!bVar2) {
      if ((param_9 != '\0') &&
         ((*(char *)(param_1 + 0x14d) == '\0' || (*(char *)(param_1 + 0x145) != '\0'))))
      goto LAB_1400094f8;
      goto LAB_14000961f;
    }
    FlRecalibrateDrive(param_1);
LAB_1400094f8:
    pbVar1 = (byte *)(param_1 + 200);
    *pbVar1 = 0x10;
    *(byte *)(param_1 + 0xc9) = param_6 << 2 | *(byte *)(param_1 + 0x110);
    *(byte *)(param_1 + 0xca) = param_5 << (*(byte *)(param_1 + 0x145) & 0x1f);
    uVar3 = FlIssueCommand(param_1,pbVar1,pbVar1,0,0,0);
    if (-1 < (int)uVar3) {
      if (((*pbVar1 & 0x20) == 0) ||
         ((uint)*(byte *)(param_1 + 0xc9) != (uint)param_5 << (*(byte *)(param_1 + 0x145) & 0x1f)))
      {
        *(undefined1 *)(param_1 + 0xc0) = 1;
        uVar3 = 0xc0000168;
      }
      else {
        KeDelayExecutionThread(0,0,local_48);
        *pbVar1 = 0x54;
        *(byte *)(param_1 + 0xc9) = param_6 << 2 | *(byte *)(param_1 + 0x110);
        uVar3 = FlIssueCommand(param_1,pbVar1,pbVar1,0,0,0);
        if (-1 < (int)uVar3) {
          if (((((uint)*pbVar1 != ((uint)param_6 << 2 | (uint)*(byte *)(param_1 + 0x110))) ||
               (*(char *)(param_1 + 0xc9) != '\0')) || (*(char *)(param_1 + 0xca) != '\0')) ||
             (*(byte *)(param_1 + 0xcb) != param_5)) {
            *(undefined1 *)(param_1 + 0xc0) = 1;
            uVar3 = FlInterpretError(*(byte *)(param_1 + 0xc9),*(byte *)(param_1 + 0xca));
            if ((int)uVar3 < 0) goto LAB_140009765;
          }
LAB_14000961f:
          pbVar1 = (byte *)(param_1 + 200);
          while( true ) {
            *(byte *)(param_1 + 0xcb) = param_6;
            *(byte *)(param_1 + 0xc9) = param_6 << 2 | *(byte *)(param_1 + 0x110);
            *(byte *)(param_1 + 0xca) = param_5;
            *(char *)(param_1 + 0xcc) = param_7 + '\x01';
            *(undefined1 *)(param_1 + 0xcd) = *(undefined1 *)(param_1 + 0x137);
            *(byte *)(param_1 + 0xce) = param_7 + param_8;
            *(undefined1 *)(param_1 + 0xcf) = *(undefined1 *)(param_1 + 0x13b);
            *(undefined1 *)(param_1 + 0xd0) = *(undefined1 *)(param_1 + 0x148);
            *pbVar1 = (-(param_4 != '\0') & 2U) + 0x40;
            uVar3 = FlIssueCommand(param_1,pbVar1,pbVar1,param_2,param_3,
                                   (uint)param_8 << (bVar4 & 0x1f));
            if (-1 < (int)uVar3) {
              if ((*pbVar1 & 0xc0) == 0) {
                if (*(char *)(param_1 + 0xcd) == '\x01') {
                  return uVar3;
                }
                *(undefined1 *)(param_1 + 0xc0) = 1;
                uVar3 = 0xc0000167;
              }
              else {
                *(undefined1 *)(param_1 + 0xc0) = 1;
                uVar3 = FlInterpretError(*(byte *)(param_1 + 0xc9),*(byte *)(param_1 + 0xca));
                if (-1 < (int)uVar3) {
                  return uVar3;
                }
              }
            }
            if (1 < local_58) break;
            local_58 = local_58 + 1;
          }
        }
      }
    }
LAB_140009765:
    bVar2 = true;
    local_54 = local_54 + 1;
    if (2 < local_54) {
      if (((int)uVar3 < 0) && (1 < param_8)) {
        bVar5 = 0;
        do {
          uVar3 = FlReadWriteTrack(param_1,param_2,((uint)bVar5 << (bVar4 & 0x1f)) + param_3,param_4
                                   ,param_5,param_6,bVar5 + param_7,1,'\0');
          if ((int)uVar3 < 0) {
            *(undefined1 *)(param_1 + 0xc0) = 1;
            return uVar3;
          }
          bVar5 = bVar5 + 1;
        } while (bVar5 < param_8);
      }
      return uVar3;
    }
  } while( true );
}



===== FlRecalibrateDrive @ 140009828 =====

undefined8 FlRecalibrateDrive(longlong param_1)

{
  byte *pbVar1;
  undefined8 uVar2;
  byte bVar3;
  
  pbVar1 = (byte *)(param_1 + 200);
  bVar3 = 0;
  do {
    *(undefined1 *)(param_1 + 0xc9) = *(undefined1 *)(param_1 + 0x110);
    *pbVar1 = 0xb;
    uVar2 = FlIssueCommand(param_1,pbVar1,pbVar1,0,0,0);
    if (((int)uVar2 < 0) || (((*pbVar1 & 0x20) != 0 && (*(char *)(param_1 + 0xc9) == '\0')))) {
      if (-1 < (int)uVar2) {
        return uVar2;
      }
    }
    else {
      *(undefined1 *)(param_1 + 0xc0) = 1;
      uVar2 = 0xc0000168;
    }
    bVar3 = bVar3 + 1;
  } while (bVar3 < 2);
  return uVar2;
}



===== FlStartDrive @ 1400098b4 =====

ulonglong FlStartDrive(longlong param_1,longlong param_2,char param_3,char param_4,char param_5)

{
  uint *puVar1;
  byte *pbVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  char cVar6;
  undefined2 uVar7;
  uint uVar8;
  ulonglong uVar9;
  longlong lVar10;
  ulonglong uVar11;
  char cVar12;
  ushort local_res8;
  undefined2 uStackX_a;
  char local_resc;
  undefined2 local_res18;
  undefined8 local_48 [2];
  
  puVar5 = DriveMediaConstants;
  local_resc = '\0';
  uVar4 = *(undefined8 *)(param_1 + 0x11c);
  local_48[0] = 0;
  local_res18 = 0;
  lVar10 = (longlong)*(int *)(DriveMediaLimits + (ulonglong)*(byte *)(param_1 + 0xfe) * 8) * 0x1c;
  puVar3 = (undefined8 *)(lVar10 + (longlong)DriveMediaConstants);
  *puVar3 = *(undefined8 *)(param_1 + 0x114);
  puVar3[1] = uVar4;
  *(undefined8 *)(lVar10 + 0x10 + (longlong)puVar5) = *(undefined8 *)(param_1 + 0x124);
  *(undefined4 *)(lVar10 + 0x18 + (longlong)puVar5) = *(undefined4 *)(param_1 + 300);
  if (*(int *)(param_1 + 0x108) + 1U < 2) {
    uVar4 = puVar5[1];
    *(undefined8 *)(param_1 + 0x130) = *puVar5;
    *(undefined8 *)(param_1 + 0x138) = uVar4;
    *(undefined8 *)(param_1 + 0x140) = puVar5[2];
    *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(puVar5 + 3);
  }
  if (param_3 == '\0') {
    uVar7 = *(undefined2 *)(param_1 + 0x140);
  }
  else {
    uVar7 = *(undefined2 *)(param_1 + 0x142);
  }
  _local_res8 = CONCAT22(uVar7,(ushort)*(byte *)(param_1 + 0x111));
  uVar9 = FlFdcDeviceIo(*(undefined8 *)(param_1 + 0x10),0x70c1b,&local_res8);
  cVar6 = local_resc;
  cVar12 = '\0';
  if (-1 < (int)uVar9) {
    local_res18 = CONCAT11(*(undefined1 *)(param_1 + 0x111),(char)local_res18);
    uVar9 = FlFdcDeviceIo(*(undefined8 *)(param_1 + 0x10),0x70c23,&local_res18);
    cVar12 = (char)local_res18;
  }
  uVar11 = uVar9 & 0xffffffff;
  if ((int)uVar9 < 0) {
    return uVar11;
  }
  if (*(char *)(param_1 + 0xfe) == '\0') {
    if (cVar6 != '\0') {
LAB_1400099e4:
      *(undefined4 *)(param_1 + 0x108) = 0xffffffff;
      if ((*(byte *)(*(longlong *)(*(longlong *)(param_1 + 0x38) + 0x38) + 4) & 1) != 0) {
        if (param_2 != 0) {
          IoSetHardErrorOrVerifyDevice(param_2);
        }
        puVar1 = (uint *)(*(longlong *)(param_1 + 0x38) + 0x30);
        *puVar1 = *puVar1 | 2;
      }
      if (*(char *)(param_1 + 0xfe) != '\0') {
        pbVar2 = (byte *)(param_1 + 200);
        *pbVar2 = 0x10;
        *(undefined1 *)(param_1 + 0xc9) = *(undefined1 *)(param_1 + 0x110);
        *(undefined1 *)(param_1 + 0xca) = 1;
        uVar9 = FlIssueCommand(param_1,pbVar2,pbVar2,0,0,0);
        if ((int)uVar9 < 0) {
          return uVar9;
        }
        if (((*pbVar2 & 0x20) == 0) || (*(char *)(param_1 + 0xc9) != '\x01')) {
LAB_140009b44:
          *(undefined1 *)(param_1 + 0xc0) = 1;
          return 0xc0000168;
        }
        *pbVar2 = 0x10;
        *(undefined1 *)(param_1 + 0xc9) = *(undefined1 *)(param_1 + 0x110);
        *(undefined1 *)(param_1 + 0xca) = 0;
        local_48[0] = 0xfffffffffffffc7c;
        KeDelayExecutionThread(0,0,local_48);
        uVar8 = FlIssueCommand(param_1,pbVar2,pbVar2,0,0,0);
        local_48[0] = 0xfffffffffffffffb;
        KeDelayExecutionThread(0,0,local_48);
        if ((int)uVar8 < 0) {
          return (ulonglong)uVar8;
        }
        if (((*pbVar2 & 0x20) == 0) || (*(char *)(param_1 + 0xc9) != '\0')) goto LAB_140009b44;
        uVar9 = FlFdcDeviceIo(*(undefined8 *)(param_1 + 0x10),0x70c23,&local_res18);
        uVar11 = uVar9 & 0xffffffff;
        if ((int)uVar9 < 0) {
          return uVar9;
        }
        if ((local_res18 & 0x80) != 0) {
          if ((*(byte *)(*(longlong *)(*(longlong *)(param_1 + 0x38) + 0x38) + 4) & 1) != 0) {
            puVar1 = (uint *)(*(longlong *)(param_1 + 0x38) + 0x30);
            *puVar1 = *puVar1 & 0xfffffffd;
          }
          return 0xc0000013;
        }
      }
      if (param_5 == '\0') {
        return (ulonglong)
               ((-(uint)((*(byte *)(*(longlong *)(*(longlong *)(param_1 + 0x38) + 0x38) + 4) & 1) !=
                        0) & 0xbffffe91) + 0xc0000185);
      }
    }
  }
  else if (cVar12 < '\0') goto LAB_1400099e4;
  if (param_4 != '\0') {
    if (*(int *)(param_1 + 0x108) == -1) {
      uVar8 = FlDetermineMediaType(param_1);
    }
    else {
      if (*(int *)(param_1 + 0x108) == 0) {
        return 0xc0000014;
      }
      if (*(int *)(param_1 + 0x10c) == *(int *)(param_1 + 0xf8)) goto LAB_140009bbb;
      uVar8 = FlDatarateSpecifyConfigure(param_1);
    }
    uVar11 = (ulonglong)uVar8;
  }
LAB_140009bbb:
  if ((param_3 != '\0') && (-1 < (int)uVar11)) {
    pbVar2 = (byte *)(param_1 + 200);
    *pbVar2 = 0xe;
    *(undefined1 *)(param_1 + 0xc9) = *(undefined1 *)(param_1 + 0x110);
    uVar9 = FlIssueCommand(param_1,pbVar2,pbVar2,0,0,0);
    uVar11 = uVar9 & 0xffffffff;
    if ((int)uVar9 < 0) {
      return uVar9;
    }
    if ((*pbVar2 & 0x40) != 0) {
      return 0xc00000a2;
    }
  }
  return uVar11;
}



===== FloppyAddDevice @ 140009c30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FloppyAddDevice(undefined8 param_1,undefined8 param_2)

{
  undefined2 *puVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  ushort uVar6;
  ulonglong uVar7;
  undefined1 auStack_258 [32];
  undefined4 local_238;
  uint local_230;
  longlong *local_228;
  longlong local_218;
  ulonglong local_210 [5];
  undefined1 local_1e8;
  undefined1 local_1e7 [11];
  undefined4 local_1dc;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined8 local_184;
  wchar_t local_178 [24];
  char local_148 [256];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_258;
  local_218 = 0;
  local_1e8 = 0;
  memset(local_1e7,0,0x6f);
  local_184 = 0;
  local_210[2] = 0;
  local_210[3] = 0;
  local_210[0] = 0;
  local_210[1] = 0;
  uVar4 = FlFdcDeviceIo(param_2,0x70c0b,&local_1e8);
  uVar7 = uVar4 & 0xffffffff;
  if (-1 < (int)uVar4) {
    uVar6 = 0;
    do {
      RtlStringCbPrintfW(local_178,0x28,L"\\Device\\Floppy%d",(ulonglong)uVar6);
      uVar6 = uVar6 + 1;
      RtlInitUnicodeString(local_210,local_178);
      local_228 = &local_218;
      local_230 = local_230 & 0xffffff00;
      local_238 = 0x105;
      uVar3 = IoCreateDevice(param_1,0x228,local_210,7);
      uVar7 = (ulonglong)uVar3;
    } while (uVar3 == 0xc0000035);
    if (-1 < (int)uVar3) {
      lVar2 = *(longlong *)(local_218 + 0x40);
      lVar5 = ExAllocatePool2(0x100,local_210[0] & 0xffff,0x706f6c46);
      *(longlong *)(lVar2 + 0x158) = lVar5;
      if (lVar5 == 0) {
        uVar4 = 0xc000009a;
      }
      else {
        puVar1 = (undefined2 *)(lVar2 + 0x150);
        *puVar1 = 0;
        *(undefined2 *)(lVar2 + 0x152) = (undefined2)local_210[0];
        RtlCopyUnicodeString(puVar1,local_210);
        lVar5 = IoAttachDeviceToDeviceStack(local_218,param_2);
        *(longlong *)(lVar2 + 0x10) = lVar5;
        if (lVar5 != 0) {
          lVar5 = IoGetConfigurationInformation();
          *(int *)(lVar5 + 4) = *(int *)(lVar5 + 4) + 1;
          local_228 = (longlong *)CONCAT44(local_228._4_4_,local_1d4);
          local_230 = local_1d8;
          local_238 = local_1dc;
          RtlStringCbPrintfA(local_148,0x100,"%s(%d)disk(%d)fdisk(%d)","\\ArcName\\multi");
          RtlInitString(local_210 + 2,local_148);
          uVar3 = RtlAnsiStringToUnicodeString(lVar2 + 0x180,local_210 + 2,1);
          if (-1 < (int)uVar3) {
            IoCreateSymbolicLink(lVar2 + 0x180,local_210);
          }
          *(uint *)(local_218 + 0x30) = *(uint *)(local_218 + 0x30) | 0x2010;
          if (*(int *)(local_218 + 0x98) == 0) {
            *(undefined4 *)(local_218 + 0x98) = 1;
          }
          *(uint *)(local_218 + 0x30) = *(uint *)(local_218 + 0x30) & 0xffffff7f;
          *(undefined8 *)(lVar2 + 0xf0) = param_1;
          *(undefined8 *)(lVar2 + 8) = param_2;
          KeInitializeSemaphore(lVar2 + 0x40,0,0x7fffffff);
          *(undefined4 *)(lVar2 + 0x1b8) = 1;
          *(undefined8 *)(lVar2 + 0x1c0) = 0;
          *(undefined4 *)(lVar2 + 0x1c8) = 0;
          KeInitializeEvent(lVar2 + 0x1d0,1,0);
          KeInitializeSpinLock(lVar2 + 0x60);
          *(undefined4 *)(lVar2 + 0x68) = 1;
          *(undefined8 *)(lVar2 + 0x70) = 0;
          *(undefined4 *)(lVar2 + 0x78) = 0;
          KeInitializeEvent(lVar2 + 0x80,1,0);
          *(undefined4 *)(lVar2 + 0x1f0) = 1;
          *(undefined8 *)(lVar2 + 0x1f8) = 0;
          *(undefined4 *)(lVar2 + 0x200) = 0;
          KeInitializeEvent(lVar2 + 0x208,1,0);
          lVar5 = lVar2 + 0xb0;
          *(undefined2 *)(lVar2 + 0x18) = 0;
          *(longlong *)(lVar2 + 0xb8) = lVar5;
          *(longlong *)lVar5 = lVar5;
          lVar5 = lVar2 + 0x20;
          *(undefined4 *)(lVar2 + 0xa0) = 0xffffffff;
          *(longlong *)(lVar2 + 0x28) = lVar5;
          *(longlong *)lVar5 = lVar5;
          *(undefined1 *)(lVar2 + 0x1a) = 0;
          KeInitializeSpinLock(lVar2 + 0x30);
          KeInitializeSpinLock(lVar2);
          KeInitializeEvent(lVar2 + 0x198,1,0);
          *(undefined1 *)(lVar2 + 0xfc) = 0;
          *(undefined1 *)(lVar2 + 400) = 0;
          *(longlong *)(lVar2 + 0x38) = local_218;
          *(undefined1 *)(lVar2 + 0x112) = 0;
          *(undefined4 *)(lVar2 + 0x108) = 0xffffffff;
          *(undefined1 *)(lVar2 + 0x14d) = 1;
          return (ulonglong)uVar3;
        }
        RtlFreeUnicodeString(puVar1);
        RtlInitUnicodeString(puVar1,0);
        uVar4 = 0xc0000001;
      }
      IoDeleteDevice(local_218);
      return uVar4;
    }
  }
  return uVar7;
}



===== FloppyCreateClose @ 14000a030 =====

undefined8 FloppyCreateClose(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 1;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== FloppyDeviceControl @ 14000a060 =====

ulonglong FloppyDeviceControl(longlong param_1,longlong param_2)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong lVar6;
  void *_Src;
  longlong lVar7;
  ulonglong uVar8;
  int iVar9;
  int *piVar10;
  uint uVar11;
  int *piVar12;
  ushort *puVar13;
  
  lVar4 = *(longlong *)(param_1 + 0x40);
  lVar7 = *(longlong *)(param_2 + 0xb8);
  *(undefined8 *)(param_2 + 0x38) = 0;
  lVar6 = lVar4 + 0x1f0;
  ExAcquireFastMutex(lVar6);
  if ((*(char *)(lVar4 + 0x1a) != '\0') && (*(int *)(lVar7 + 0x18) != 0x32c000)) {
    uVar5 = FloppyQueueRequest(lVar4,param_2);
    ExReleaseFastMutex(lVar6);
    return uVar5 & 0xffffffff;
  }
  if (*(char *)(lVar4 + 0x19) != '\0') {
    ExReleaseFastMutex(lVar6);
    *(undefined8 *)(param_2 + 0x38) = 0;
    uVar5 = 0xc0000056;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000056;
    goto LAB_14000a439;
  }
  if (*(char *)(lVar4 + 0x18) == '\0') {
LAB_14000a104:
    ExReleaseFastMutex(lVar4 + 0x1f0);
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    uVar5 = IofCallDriver(*(undefined8 *)(lVar4 + 0x10),param_2);
    return uVar5;
  }
  uVar11 = *(uint *)(lVar7 + 0x18);
  if (uVar11 < 0x7c02d) {
    if (uVar11 == 0x7c02c) {
LAB_14000a178:
      if (0x13 < *(uint *)(lVar7 + 0x10)) {
        piVar12 = *(int **)(param_2 + 0x18);
        uVar11 = *(uint *)(DriveMediaLimits + (ulonglong)*(byte *)(lVar4 + 0xfe) * 8);
        uVar5 = (ulonglong)(int)uVar11;
        iVar9 = *piVar12;
        piVar10 = (int *)(uVar5 * 0x1c + DriveMediaConstants);
        if (*piVar10 != iVar9) {
          uVar8 = uVar5;
          do {
            uVar11 = (uint)uVar8;
            if ((longlong)uVar5 <=
                (longlong)*(int *)(DriveMediaLimits + 4 + (ulonglong)*(byte *)(lVar4 + 0xfe) * 8))
            break;
            piVar10 = piVar10 + -7;
            uVar11 = uVar11 - 1;
            uVar8 = (ulonglong)uVar11;
            uVar5 = uVar5 - 1;
          } while (*piVar10 != iVar9);
        }
        lVar6 = (longlong)(int)uVar11 * 0x1c;
        if (((*(int *)(lVar6 + DriveMediaConstants) == iVar9) &&
            (uVar11 = *(byte *)(lVar6 + 0x17 + DriveMediaConstants) - 1, (uint)piVar12[3] <= uVar11)
            ) && ((uint)piVar12[4] <= uVar11)) {
          uVar11 = (uint)*(byte *)(lVar6 + 0x14 + DriveMediaConstants);
          if (((((uint)piVar12[1] <= uVar11) && ((uint)piVar12[2] <= uVar11)) &&
              ((uint)piVar12[1] <= (uint)piVar12[2])) &&
             ((*(int *)(lVar7 + 0x18) != 0x7c02c ||
              (((0x1b < *(uint *)(lVar7 + 0x10) &&
                ((uint)*(ushort *)((longlong)piVar12 + 0x16) * 2 + 0x18 <= *(uint *)(lVar7 + 0x10)))
               && ((*(ushort *)(piVar12 + 5) < 0x100 &&
                   (*(ushort *)((longlong)piVar12 + 0x16) < 0x100)))))))) goto LAB_14000a24a;
        }
      }
LAB_14000a28c:
      uVar5 = 0xc000000d;
    }
    else {
      if ((uVar11 != 0x70000) && (uVar11 != 0x70024)) {
        if (uVar11 == 0x70c00) goto LAB_14000a32a;
        if (uVar11 != 0x74800) {
          if (uVar11 != 0x7c018) goto LAB_14000a104;
          goto LAB_14000a178;
        }
      }
LAB_14000a24a:
      uVar5 = FlQueueIrpToThread(param_2,lVar4);
      uVar5 = uVar5 & 0xffffffff;
    }
  }
  else if (uVar11 == 0x2d0c00) {
LAB_14000a32a:
    uVar11 = *(uint *)(DriveMediaLimits + 4 + (ulonglong)*(byte *)(lVar4 + 0xfe) * 8);
    uVar8 = (ulonglong)uVar11;
    iVar9 = *(int *)(DriveMediaLimits + (ulonglong)*(byte *)(lVar4 + 0xfe) * 8);
    uVar3 = *(uint *)(lVar7 + 8);
    if (uVar3 < 0x18) {
      uVar5 = 0xc0000023;
    }
    else {
      uVar5 = 0;
      if ((ulonglong)uVar3 < (ulonglong)((longlong)(int)((iVar9 - uVar11) + 1) * 0x18)) {
        uVar5 = 0x80000005;
        iVar9 = (uVar11 - 1) + uVar3 / 0x18;
      }
      piVar12 = *(int **)(param_2 + 0x18);
      for (; lVar6 = DriveMediaConstants, (byte)uVar8 <= (byte)iVar9;
          uVar8 = (ulonglong)(byte)((byte)uVar8 + 1)) {
        lVar7 = (uVar8 & 0xff) * 0x1c;
        piVar12[2] = *(int *)(lVar7 + DriveMediaConstants);
        bVar1 = *(byte *)(lVar7 + 0x14 + lVar6);
        piVar12[1] = 0;
        *piVar12 = bVar1 + 1;
        piVar12[3] = (uint)*(byte *)(lVar7 + 0x17 + lVar6);
        piVar12[4] = (uint)*(byte *)(lVar7 + 10 + lVar6);
        piVar12[5] = (uint)*(ushort *)(lVar7 + 8 + lVar6);
        *(longlong *)(param_2 + 0x38) = *(longlong *)(param_2 + 0x38) + 0x18;
        piVar12 = piVar12 + 6;
      }
    }
  }
  else {
    if (uVar11 == 0x2d4800) goto LAB_14000a24a;
    if (uVar11 == 0x4d0000) {
      if ((*(longlong *)(lVar4 + 0x168) == 0) || (*(uint *)(lVar7 + 8) < 4)) goto LAB_14000a28c;
      puVar13 = *(ushort **)(param_2 + 0x18);
      puVar13[0] = 0;
      puVar13[1] = 0;
      uVar2 = *(ushort *)(lVar4 + 0x160);
      *puVar13 = uVar2;
      if (*(uint *)(lVar7 + 8) < uVar2 + 2) goto LAB_14000a2b9;
      _Src = *(void **)(lVar4 + 0x168);
LAB_14000a2d2:
      memcpy(puVar13 + 1,_Src,(ulonglong)uVar2);
      uVar5 = 0;
      *(ulonglong *)(param_2 + 0x38) = (ulonglong)*puVar13 + 2;
    }
    else {
      if (uVar11 != 0x4d0008) goto LAB_14000a104;
      if (*(uint *)(lVar7 + 8) < 4) goto LAB_14000a28c;
      puVar13 = *(ushort **)(param_2 + 0x18);
      puVar13[0] = 0;
      puVar13[1] = 0;
      uVar2 = *(ushort *)(lVar4 + 0x150);
      *puVar13 = uVar2;
      if (uVar2 + 2 <= *(uint *)(lVar7 + 8)) {
        _Src = *(void **)(lVar4 + 0x158);
        goto LAB_14000a2d2;
      }
LAB_14000a2b9:
      uVar5 = 0x80000005;
      *(undefined8 *)(param_2 + 0x38) = 4;
    }
  }
  ExReleaseFastMutex(lVar4 + 0x1f0);
  iVar9 = (int)uVar5;
  if (iVar9 == 0x103) {
    return uVar5;
  }
  *(int *)(param_2 + 0x30) = iVar9;
  if ((((iVar9 + 0x3fffff5eU < 2) || (iVar9 == -0x3fffff4b)) || (iVar9 + 0x3fffffeeU < 3)) ||
     (iVar9 == -0x7fffffea)) {
    IoSetHardErrorOrVerifyDevice(param_2,param_1);
  }
LAB_14000a439:
  IofCompleteRequest(param_2,0);
  return uVar5;
}



===== FloppyPnp @ 14000a470 =====

ulonglong FloppyPnp(longlong param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  
  ExAcquireFastMutex(PagingMutex);
  PagingReferenceCount = PagingReferenceCount + 1;
  if (PagingReferenceCount == 1) {
    MmResetDriverPaging(DriverEntry);
  }
  ExReleaseFastMutex(PagingMutex);
  lVar4 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  if (*(char *)(lVar4 + 0x19) != '\0') {
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000056;
    IofCompleteRequest(param_2,0);
    return 0xc0000056;
  }
  cVar1 = *(char *)(lVar2 + 1);
  if (cVar1 == '\0') {
    uVar3 = FloppyStartDevice(param_1,param_2);
    goto LAB_14000a827;
  }
  if (cVar1 == '\x01') {
LAB_14000a760:
    if (*(char *)(lVar4 + 0x18) == '\0') {
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = lVar2 + 0x48;
      *(undefined4 *)(param_2 + 0x30) = 0;
      uVar5 = IofCallDriver(*(undefined8 *)(lVar4 + 0x10),param_2);
      return uVar5;
    }
    ExAcquireFastMutex(lVar4 + 0x1f0);
    *(undefined1 *)(lVar4 + 0x1a) = 1;
    uVar6 = FlQueueIrpToThread(param_2,lVar4);
    ExReleaseFastMutex(lVar4 + 0x1f0);
    uVar3 = 0x103;
    if ((int)uVar6 == 0x103) {
      FlTerminateFloppyThread(lVar4);
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      *(undefined4 *)(param_2 + 0x30) = 0;
      IofCallDriver(*(undefined8 *)(lVar4 + 0x10),param_2);
      goto LAB_14000a827;
    }
    uVar3 = 0xc0000001;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000001;
LAB_14000a803:
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    goto LAB_14000a827;
  }
  if (cVar1 == '\x02') {
    FlTerminateFloppyThread(lVar4);
    ExAcquireFastMutex(lVar4 + 0x1f0);
    *(undefined1 *)(lVar4 + 0x1a) = 0;
    ExReleaseFastMutex(lVar4 + 0x1f0);
    *(undefined2 *)(lVar4 + 0x18) = 0x100;
    FloppyProcessQueuedRequests(lVar4);
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    *(undefined4 *)(param_2 + 0x30) = 0;
    uVar3 = IofCallDriver(*(undefined8 *)(lVar4 + 0x10),param_2);
    if (*(longlong *)(lVar4 + 0x168) != 0) {
      lVar2 = lVar4 + 0x160;
      IoSetDeviceInterfaceState(lVar2,0);
      RtlFreeUnicodeString(lVar2);
      RtlInitUnicodeString(lVar2,0);
    }
    if (*(longlong *)(lVar4 + 0x178) != 0) {
      lVar2 = lVar4 + 0x170;
      IoSetDeviceInterfaceState(lVar2,0);
      RtlFreeUnicodeString(lVar2);
      RtlInitUnicodeString(lVar2,0);
    }
    RtlFreeUnicodeString(lVar4 + 0x150);
    RtlInitUnicodeString(lVar4 + 0x150,0);
    if (*(longlong *)(lVar4 + 0x188) != 0) {
      lVar2 = lVar4 + 0x180;
      IoDeleteSymbolicLink(lVar2);
      RtlFreeUnicodeString(lVar2);
      RtlInitUnicodeString(lVar2,0);
    }
    IoDetachDevice(*(undefined8 *)(lVar4 + 0x10));
    IoDeleteDevice(param_1);
    lVar4 = IoGetConfigurationInformation();
    *(int *)(lVar4 + 4) = *(int *)(lVar4 + 4) + -1;
    goto LAB_14000a827;
  }
  if (cVar1 == '\x03') {
LAB_14000a583:
    cVar1 = *(char *)(lVar4 + 0x18);
    *(undefined4 *)(param_2 + 0x30) = 0;
    if (cVar1 != '\0') {
      IoForwardIrpSynchronously(*(undefined8 *)(lVar4 + 0x10),param_2);
      uVar3 = *(uint *)(param_2 + 0x30);
      if (-1 < (int)uVar3) {
        ExAcquireFastMutex(lVar4 + 0x1f0);
        *(undefined1 *)(lVar4 + 0x1a) = 0;
        ExReleaseFastMutex(lVar4 + 0x1f0);
        FloppyProcessQueuedRequests(lVar4);
      }
      goto LAB_14000a803;
    }
LAB_14000a548:
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = lVar2 + 0x48;
  }
  else {
    if (cVar1 != '\x04') {
      if (cVar1 == '\x05') goto LAB_14000a760;
      if (cVar1 == '\x06') goto LAB_14000a583;
      goto LAB_14000a548;
    }
    *(undefined1 *)(lVar4 + 0x18) = 0;
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    *(undefined4 *)(param_2 + 0x30) = 0;
  }
  uVar3 = IofCallDriver(*(undefined8 *)(lVar4 + 0x10),param_2);
LAB_14000a827:
  ExAcquireFastMutex(PagingMutex);
  PagingReferenceCount = PagingReferenceCount + -1;
  if (PagingReferenceCount == 0) {
    MmPageEntireDriver(DriverEntry);
  }
  ExReleaseFastMutex(PagingMutex);
  return (ulonglong)uVar3;
}



===== FloppyPower @ 14000a890 =====

undefined8 FloppyPower(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 local_res8;
  
  lVar5 = *(longlong *)(param_2 + 0xb8);
  lVar1 = *(longlong *)(param_1 + 0x40);
  iVar3 = *(int *)(lVar5 + 0x18);
  if (*(char *)(lVar5 + 1) == '\x02') {
    if (*(int *)(lVar5 + 0x10) == 0) {
      ExAcquireFastMutex(lVar1 + 0x1b8);
      *(bool *)(lVar1 + 0x1b0) = iVar3 != 1;
      ExReleaseFastMutex(lVar1 + 0x1b8);
      if (iVar3 != 1) {
        ExAcquireFastMutex(lVar1 + 0x68);
        lVar5 = 0;
        if ((*(int *)(lVar1 + 0xa0) != -1) && (lVar2 = *(longlong *)(lVar1 + 0xa8), lVar2 != 0)) {
          ObfReferenceObject(lVar2);
          lVar5 = lVar2;
        }
        ExReleaseFastMutex(lVar1 + 0x68);
        if (lVar5 != 0) {
          KeWaitForSingleObject(lVar5,0,0,0,0);
          ObfDereferenceObject(lVar5);
        }
      }
    }
  }
  else if ((*(char *)(lVar5 + 1) == '\x03') && ((*(int *)(lVar5 + 0x10) != 0 || (iVar3 < 6)))) {
    lVar5 = lVar1 + 0x68;
    ExAcquireFastMutex(lVar5);
    if (0 < *(int *)(lVar1 + 0xa0)) {
LAB_14000a8f9:
      ExReleaseFastMutex(lVar5);
      PoStartNextPowerIrp(param_2);
      *(undefined8 *)(param_2 + 0x38) = 0;
      *(undefined4 *)(param_2 + 0x30) = 0x80000011;
      IofCompleteRequest(param_2,0);
      return 0x80000011;
    }
    if ((*(int *)(lVar1 + 0xa0) == 0) && (*(longlong *)(lVar1 + 0xa8) != 0)) {
      ExReleaseFastMutex(lVar5);
      lVar5 = lVar1 + 0x1b8;
      ExAcquireFastMutex(lVar5);
      *(undefined1 *)(lVar1 + 0x1b1) = 1;
      ExReleaseFastMutex(lVar5);
      local_res8 = 0xfffffffffd050f80;
      iVar3 = KeWaitForSingleObject(lVar1 + 0x198,0,0,0,&local_res8);
      if (iVar3 == 0x102) {
        ExAcquireFastMutex(lVar5);
        *(undefined1 *)(lVar1 + 0x1b1) = 0;
        goto LAB_14000a8f9;
      }
    }
    else {
      ExReleaseFastMutex(lVar5);
    }
  }
  PoStartNextPowerIrp(param_2);
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  uVar4 = PoCallDriver(*(undefined8 *)(lVar1 + 0x10),param_2);
  return uVar4;
}



===== FloppyReadWrite @ 14000aaf0 =====

ulonglong FloppyReadWrite(longlong param_1,longlong param_2)

{
  longlong lVar1;
  char cVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  uint uVar7;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  lVar4 = *(longlong *)(param_2 + 0xb8);
  lVar1 = lVar3 + 0x1f0;
  ExAcquireFastMutex(lVar1);
  uVar7 = 0;
  if (*(char *)(lVar3 + 0x1a) == '\0') {
    if ((*(char *)(lVar3 + 0x19) == '\0') && (*(char *)(lVar3 + 0x18) != '\0')) {
      if ((*(int *)(lVar3 + 0x108) < 1) ||
         ((*(int *)(lVar4 + 0x18) + *(uint *)(lVar4 + 8) <= *(uint *)(lVar3 + 0x104) &&
          ((*(uint *)(lVar4 + 8) & *(int *)(lVar3 + 0x100) - 1U) == 0)))) {
        if (*(int *)(lVar4 + 8) == 0) {
          *(undefined8 *)(param_2 + 0x38) = 0;
          *(undefined4 *)(param_2 + 0x30) = 0;
        }
        else {
          uVar6 = FlQueueIrpToThread(param_2,lVar3);
          uVar7 = (uint)uVar6;
        }
      }
      else {
        uVar7 = 0xc000000d;
      }
      ExReleaseFastMutex(lVar3 + 0x1f0);
      if (uVar7 != 0x103) {
        *(uint *)(param_2 + 0x30) = uVar7;
        IofCompleteRequest(param_2,0);
      }
      return (ulonglong)uVar7;
    }
    ExReleaseFastMutex(lVar1);
    cVar2 = *(char *)(lVar3 + 0x19);
    *(undefined8 *)(param_2 + 0x38) = 0;
    uVar7 = (-(uint)(cVar2 != '\0') & 0x55) + 0xc0000001;
    uVar5 = (ulonglong)uVar7;
    *(uint *)(param_2 + 0x30) = uVar7;
    IofCompleteRequest(param_2,0);
  }
  else {
    uVar5 = FloppyQueueRequest(lVar3,param_2);
    uVar5 = uVar5 & 0xffffffff;
    ExReleaseFastMutex(lVar1);
  }
  return uVar5;
}



===== FloppySystemControl @ 14000ac40 =====

void FloppySystemControl(longlong param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  IofCallDriver(*(undefined8 *)(lVar1 + 0x10));
  return;
}



===== FloppyThread @ 14000ac70 =====

void FloppyThread(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  char *pcVar4;
  int *piVar5;
  int iVar6;
  longlong lVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  uint uVar10;
  char cVar11;
  ulonglong uVar12;
  undefined8 local_res10;
  undefined8 local_res18 [2];
  byte bVar13;
  
  uVar12 = 0;
  KeSetPriorityThread(SystemReserved1[0xf],0x10);
  local_res18[0] = 0xffffffffff676980;
  local_res10 = 0xfffffffff70f2e80;
  lVar1 = param_1 + 0x68;
  lVar2 = param_1 + 0x1b8;
LAB_14000acd9:
  do {
    uVar10 = 0;
    do {
      iVar6 = KeWaitForSingleObject(param_1 + 0x40,0,0,0,local_res18);
      if (iVar6 != 0x102) {
        lVar7 = ExInterlockedRemoveHeadList(param_1 + 0xb0);
        if (lVar7 == 0) goto LAB_14000acd9;
        goto LAB_14000ae97;
      }
      ExAcquireFastMutex(lVar2);
      if (*(char *)(param_1 + 0x1b1) == '\x01') {
        ExReleaseFastMutex(lVar2);
        break;
      }
      ExReleaseFastMutex();
      uVar10 = uVar10 + 1;
    } while (uVar10 < 3);
    if (*(char *)(param_1 + 0xfc) != '\0') {
      FlFdcDeviceIo(*(undefined8 *)(param_1 + 0x10),0x70c1f,0);
      FlFdcDeviceIo(*(undefined8 *)(param_1 + 0x10),0x70c07,*(undefined8 *)(param_1 + 0x38));
      *(undefined1 *)(param_1 + 0xfc) = 0;
    }
    ExAcquireFastMutex(lVar1);
    if (*(int *)(param_1 + 0xa0) == 0) {
      *(undefined4 *)(param_1 + 0xa0) = 0xffffffff;
      if (*(longlong *)(param_1 + 0xa8) != 0) {
        ObfDereferenceObject();
        *(undefined8 *)(param_1 + 0xa8) = 0;
      }
      ExReleaseFastMutex(lVar1);
      ExAcquireFastMutex(PagingMutex);
      PagingReferenceCount = PagingReferenceCount + -1;
      if (PagingReferenceCount == 0) {
        MmPageEntireDriver(DriverEntry);
      }
      ExReleaseFastMutex(PagingMutex);
      ExAcquireFastMutex(lVar2);
      if (*(char *)(param_1 + 0x1b1) == '\x01') {
        *(undefined1 *)(param_1 + 0x1b1) = 0;
        KeSetEvent(param_1 + 0x198);
      }
      ExReleaseFastMutex(lVar2);
      PsTerminateSystemThread(0);
    }
    ExReleaseFastMutex(lVar1);
  } while( true );
LAB_14000ae97:
  do {
    ExAcquireFastMutex(lVar1);
    *(int *)(param_1 + 0xa0) = *(int *)(param_1 + 0xa0) + -1;
    ExReleaseFastMutex(lVar1);
    *(undefined1 *)(param_1 + 0xc0) = 0;
    lVar3 = lVar7 + -0xa8;
    ExAcquireFastMutex(lVar2);
    if (*(char *)(param_1 + 0x1b0) == '\x01') {
      ExReleaseFastMutex();
      *(undefined8 *)(lVar7 + -0x70) = 0;
      uVar9 = 0;
      *(undefined4 *)(lVar7 + -0x78) = 0xc00002d3;
LAB_14000b3ae:
      IofCompleteRequest(lVar3,uVar9);
    }
    else {
      ExReleaseFastMutex(lVar2);
      pcVar4 = *(char **)(lVar7 + 0x10);
      cVar11 = *pcVar4;
      if ((cVar11 == '\x03') || (cVar11 == '\x04')) {
        if (*(char *)(param_1 + 0xfc) == '\0') {
          uVar8 = FlFdcDeviceIo(*(undefined8 *)(param_1 + 0x10),0x70c03,&local_res10);
          uVar12 = uVar8 & 0xffffffff;
          if ((int)uVar8 < 0) goto LAB_14000b2ce;
          *(undefined1 *)(param_1 + 0xfc) = 1;
        }
        if (((*(uint *)(*(longlong *)(param_1 + 0x38) + 0x30) & 2) == 0) || ((pcVar4[2] & 2U) != 0))
        {
          uVar12 = FlReadWrite(param_1,lVar3,'\0');
          uVar10 = (uint)uVar12;
LAB_14000b2cb:
          uVar12 = (ulonglong)uVar10;
          goto LAB_14000b2ce;
        }
LAB_14000b219:
        uVar12 = 0x80000016;
LAB_14000b226:
        *(int *)(lVar7 + -0x78) = (int)uVar12;
        if (*(longlong *)(param_1 + 0xd8) != 0) {
          FlFreeIoBuffer(param_1);
        }
        if ((((*(int *)(lVar7 + -0x78) == 0) || (*(char *)(param_1 + 0xc0) == '\0')) ||
            (*(char *)(param_1 + 0xc1) = *(char *)(param_1 + 0xc1) + '\x01',
            1 < *(byte *)(param_1 + 0xc1))) ||
           (iVar6 = FlInitializeControllerHardware(param_1), iVar6 < 0)) {
          *(undefined1 *)(param_1 + 0xc1) = 0;
          iVar6 = *(int *)(lVar7 + -0x78);
          if (((iVar6 + 0x3fffff5eU < 2) || (iVar6 == -0x3fffff4b)) ||
             ((iVar6 + 0x3fffffeeU < 3 || (iVar6 == -0x7fffffea)))) {
            IoSetHardErrorOrVerifyDevice(lVar3,*(undefined8 *)(param_1 + 0x38));
          }
          uVar9 = 1;
          goto LAB_14000b3ae;
        }
        *(undefined4 *)(param_1 + 0x108) = 0xffffffff;
        ExAcquireFastMutex(lVar1);
        *(int *)(param_1 + 0xa0) = *(int *)(param_1 + 0xa0) + 1;
        ExReleaseFastMutex(lVar1);
        ExInterlockedInsertHeadList(param_1 + 0xb0,lVar7);
      }
      else {
        if (cVar11 != '\x0e') {
          if (cVar11 == '\x1b') {
            if ((pcVar4[1] - 1U & 0xfb) == 0) {
              if (*(char *)(param_1 + 0xfc) != '\0') {
                FlFdcDeviceIo(*(undefined8 *)(param_1 + 0x10),0x70c1f,0);
                FlFdcDeviceIo(*(undefined8 *)(param_1 + 0x10),0x70c07,
                              *(undefined8 *)(param_1 + 0x38));
                *(undefined1 *)(param_1 + 0xfc) = 0;
              }
              ExAcquireFastMutex(lVar1);
              *(undefined4 *)(param_1 + 0xa0) = 0xffffffff;
              ExReleaseFastMutex(lVar1);
              ExAcquireFastMutex(PagingMutex);
              PagingReferenceCount = PagingReferenceCount + -1;
              if (PagingReferenceCount == 0) {
                MmPageEntireDriver(DriverEntry);
              }
              ExReleaseFastMutex(PagingMutex);
              PsTerminateSystemThread(0);
              goto LAB_14000b2ce;
            }
            uVar12 = 0xc0000010;
          }
          else {
            uVar12 = 0xc0000002;
          }
          goto LAB_14000b226;
        }
        if (*(char *)(param_1 + 0xfc) == '\0') {
          uVar8 = FlFdcDeviceIo(*(undefined8 *)(param_1 + 0x10),0x70c03,&local_res10);
          uVar12 = uVar8 & 0xffffffff;
          if ((int)uVar8 < 0) goto LAB_14000b2ce;
          *(undefined1 *)(param_1 + 0xfc) = 1;
        }
        if (((*(uint *)(*(longlong *)(param_1 + 0x38) + 0x30) & 2) != 0) && ((pcVar4[2] & 2U) == 0))
        goto LAB_14000b219;
        iVar6 = *(int *)(pcVar4 + 0x18);
        if (iVar6 == 0x70000) {
          if (*(uint *)(pcVar4 + 8) < 0x18) {
            uVar12 = 0xc000000d;
          }
          else {
            uVar8 = FlStartDrive(param_1,lVar3,'\0','\x01',(byte)pcVar4[2] >> 1 & 1);
            uVar12 = uVar8 & 0xffffffff;
            if ((((int)uVar8 + 0x80000000U & 0x80000000) != 0) || ((int)uVar8 == -0x3fffffec)) {
              piVar5 = *(int **)(lVar7 + -0x90);
              uVar12 = 0;
              piVar5[2] = *(int *)(param_1 + 0x108);
              if (*(int *)(param_1 + 0x108) == 0) {
                piVar5[0] = 0;
                piVar5[1] = 0;
                piVar5[3] = 0;
                piVar5[4] = 0;
                piVar5[5] = 0;
              }
              else {
                bVar13 = *(byte *)(param_1 + 0x144);
                piVar5[1] = 0;
                *piVar5 = bVar13 + 1;
                piVar5[3] = (uint)*(byte *)(param_1 + 0x147);
                piVar5[4] = (uint)*(byte *)(param_1 + 0x13a);
                piVar5[5] = (uint)*(ushort *)(param_1 + 0x138);
              }
            }
          }
          *(undefined8 *)(lVar7 + -0x70) = 0x18;
          goto LAB_14000b2ce;
        }
        if (iVar6 == 0x70024) {
          if (*(char *)(param_1 + 0x112) != '\0') {
            uVar12 = 0xc000000d;
            goto LAB_14000b226;
          }
          bVar13 = 1;
          cVar11 = '\x01';
LAB_14000b093:
          uVar12 = FlStartDrive(param_1,lVar3,cVar11,'\0',bVar13);
          uVar10 = (uint)uVar12;
          goto LAB_14000b2cb;
        }
        if (iVar6 == 0x74800) {
LAB_14000b082:
          bVar13 = (byte)pcVar4[2] >> 1 & 1;
          cVar11 = '\0';
          goto LAB_14000b093;
        }
        if ((iVar6 == 0x7c018) || (iVar6 == 0x7c02c)) {
          uVar8 = FlStartDrive(param_1,lVar3,'\x01','\0','\0');
          uVar12 = uVar8 & 0xffffffff;
          if ((((int)uVar8 + 0x80000000U & 0x80000000) != 0) || ((int)uVar8 == -0x3fffffec)) {
            FlAllocateIoBuffer(param_1,0x1000);
            if (*(longlong *)(param_1 + 0xd8) != 0) {
              uVar12 = FlFormat(param_1,lVar3);
              uVar10 = (uint)uVar12;
              goto LAB_14000b2cb;
            }
            uVar12 = 0xc000009a;
            goto LAB_14000b226;
          }
        }
        else if (iVar6 == 0x2d4800) goto LAB_14000b082;
LAB_14000b2ce:
        if ((int)uVar12 != -0x7fffffef) goto LAB_14000b226;
        *(undefined1 *)(param_1 + 0xc0) = 0;
        *(undefined4 *)(lVar7 + -0x78) = 0x80000011;
        IofCompleteRequest(lVar3,1);
        while (lVar7 = ExInterlockedRemoveHeadList(param_1 + 0xb0,param_1 + 0x60), lVar7 != 0) {
          ExAcquireFastMutex(lVar1);
          *(int *)(param_1 + 0xa0) = *(int *)(param_1 + 0xa0) + -1;
          ExReleaseFastMutex(lVar1);
          *(undefined1 *)(param_1 + 0xc0) = 0;
          *(undefined4 *)(lVar7 + -0x78) = 0x80000011;
          IofCompleteRequest(lVar7 + -0xa8,1);
        }
      }
    }
    lVar7 = ExInterlockedRemoveHeadList(param_1 + 0xb0);
  } while (lVar7 != 0);
  goto LAB_14000acd9;
}



===== entry @ 14000c010 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 14000c044 =====

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



===== DriverEntry @ 14000c080 =====

undefined8 DriverEntry(longlong param_1)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  
  *(code **)(param_1 + 0x70) = FloppyCreateClose;
  *(code **)(param_1 + 0x80) = FloppyCreateClose;
  *(code **)(param_1 + 0x88) = FloppyReadWrite;
  *(code **)(param_1 + 0x90) = FloppyReadWrite;
  *(code **)(param_1 + 0xe0) = FloppyDeviceControl;
  *(code **)(param_1 + 0x148) = FloppyPnp;
  *(code **)(param_1 + 0x120) = FloppyPower;
  *(code **)(param_1 + 0x128) = FloppySystemControl;
  *(code **)(param_1 + 0x68) = FloppyUnload;
  *(code **)(*(longlong *)(param_1 + 0x30) + 8) = FloppyAddDevice;
  puVar1 = (undefined4 *)ExAllocatePool2(0x40,0x38,0x706f6c46);
  PagingMutex = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0xc000009a;
  }
  else {
    *(undefined8 *)(puVar1 + 2) = 0;
    puVar1[4] = 0;
    *puVar1 = 1;
    KeInitializeEvent(puVar1 + 6,1,0);
    MmPageEntireDriver(DriverEntry);
    DriveMediaLimits = &_DriveMediaLimits;
    DriveMediaConstants = &_DriveMediaConstants;
    uVar2 = 0;
  }
  return uVar2;
}


