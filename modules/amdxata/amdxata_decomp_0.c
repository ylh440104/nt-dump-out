
===== WPP_SF_ @ 1c0001000 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2)

{
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_ad286fb14c1fdea8b2f3f9803a29bbf7_Traceguids,param_2,0);
  return;
}



===== WPP_SF_d @ 1c000102c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_d(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ad286fb14c1fdea8b2f3f9803a29bbf7_Traceguids,0xb,local_res20,4,0);
  return;
}



===== WppClassicProviderCallback @ 1c0001080 =====

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



===== FilterPass @ 1c00010b0 =====

/* long __cdecl FilterPass(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl FilterPass(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  longlong lVar1;
  int iVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  iVar2 = IoAcquireRemoveLockEx(lVar1 + 0x50,param_2,"",1,0x20);
  if (iVar2 < 0) {
    *(int *)(param_2 + 0x30) = iVar2;
    IofCompleteRequest(param_2,0);
  }
  else {
    param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    iVar2 = IofCallDriver(*(undefined8 *)(lVar1 + 0x30),param_2);
    IoReleaseRemoveLockEx(lVar1 + 0x50,param_2,0x20);
  }
  return iVar2;
}



===== FilterQueryDeviceRelationsCompletionRoutine @ 1c0001150 =====

/* long __cdecl FilterQueryDeviceRelationsCompletionRoutine(struct _DEVICE_OBJECT * __ptr64,struct
   _IRP * __ptr64,void * __ptr64) */

long __cdecl
FilterQueryDeviceRelationsCompletionRoutine(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  if (param_2[0x41] == (_IRP)0x1) {
    KeSetEvent(param_3,0,0);
  }
  return -0x3fffffea;
}



===== FilterDeviceQueryDeviceTextCompletionRoutine @ 1c0001180 =====

/* long __cdecl FilterDeviceQueryDeviceTextCompletionRoutine(struct _DEVICE_OBJECT * __ptr64,struct
   _IRP * __ptr64,void * __ptr64) */

long __cdecl
FilterDeviceQueryDeviceTextCompletionRoutine(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  longlong lVar1;
  short *psVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  longlong lVar6;
  longlong lVar7;
  ushort **ppuVar8;
  int iVar9;
  int iVar10;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar4 = 0;
  if (param_2[0x41] != (_IRP)0x0) {
    *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) = *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) | 1;
  }
  if ((-1 < *(int *)(param_2 + 0x30)) &&
     (psVar2 = *(short **)(param_2 + 0x38), psVar2 != (short *)0x0)) {
    sVar3 = *psVar2;
    iVar5 = 0;
    iVar9 = 0;
    iVar10 = 0;
    if (sVar3 != 0) {
      lVar6 = 0;
      lVar7 = 0;
      do {
        if (sVar3 == *(short *)((longlong)&SCSI + lVar7 * 2)) {
          if (lVar7 == 0) {
            iVar10 = iVar5;
          }
          iVar9 = iVar9 + 1;
          lVar7 = lVar7 + 1;
          if (lVar7 == 4) break;
        }
        else {
          iVar9 = 0;
          lVar7 = 0;
        }
        lVar6 = lVar6 + 1;
        iVar5 = iVar5 + 1;
        sVar3 = psVar2[lVar6];
      } while (sVar3 != 0);
      if (iVar9 == 4) {
        ppuVar8 = &SATA;
        do {
          uVar4 = uVar4 + 1;
          *(undefined2 *)((longlong)(psVar2 + (longlong)iVar10 + -0xe0001000) + (longlong)ppuVar8) =
               *(undefined2 *)ppuVar8;
          ppuVar8 = (ushort **)((longlong)ppuVar8 + 2);
        } while (uVar4 < 4);
      }
    }
  }
  IoReleaseRemoveLockEx(lVar1 + 0x50,param_2,0x20);
  return 0;
}



===== PdoStartCompletionRoutine @ 1c0001270 =====

/* long __cdecl PdoStartCompletionRoutine(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64,void
   * __ptr64) */

long __cdecl PdoStartCompletionRoutine(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  longlong lVar1;
  long lVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (param_2[0x41] != (_IRP)0x0) {
    *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) = *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) | 1;
  }
  if (*(int *)(param_2 + 0x30) < 0) {
    IoReleaseRemoveLockEx(lVar1 + 0x50,param_2,0x20);
    lVar2 = 0;
  }
  else {
    IoQueueWorkItem(*(undefined8 *)(lVar1 + 0x2c0),PdoStartWorker,1,param_2);
    lVar2 = -0x3fffffea;
  }
  return lVar2;
}



===== FilterDeviceUsageNotificationCompletionRoutine @ 1c00012d0 =====

/* long __cdecl FilterDeviceUsageNotificationCompletionRoutine(struct _DEVICE_OBJECT *
   __ptr64,struct _IRP * __ptr64,void * __ptr64) */

long __cdecl
FilterDeviceUsageNotificationCompletionRoutine(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  int iVar1;
  longlong lVar2;
  int *piVar3;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  if (param_2[0x41] != (_IRP)0x0) {
    *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) = *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) | 1;
  }
  if ((*(uint *)(*(longlong *)(lVar2 + 0x30) + 0x30) & 0x2000) == 0) {
    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xffffdfff;
  }
  if (-1 < *(int *)(param_2 + 0x30)) {
    iVar1 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x10);
    if (iVar1 == 0) {
      piVar3 = (int *)0x0;
    }
    else if (iVar1 == 1) {
      piVar3 = (int *)(lVar2 + 0x70);
    }
    else if (iVar1 == 2) {
      piVar3 = (int *)(lVar2 + 0x74);
    }
    else {
      if (iVar1 != 3) goto LAB_1c000134b;
      piVar3 = (int *)(lVar2 + 0x78);
    }
    if (piVar3 != (int *)0x0) {
      if (*(char *)(*(longlong *)(param_2 + 0xb8) + 8) == '\0') {
        LOCK();
        *piVar3 = *piVar3 + -1;
        UNLOCK();
      }
      else {
        LOCK();
        *piVar3 = *piVar3 + 1;
        UNLOCK();
      }
    }
  }
LAB_1c000134b:
  IoReleaseRemoveLockEx(lVar2 + 0x50,param_2,0x20);
  return 0;
}



===== SIrpCompletionRoutine @ 1c0001370 =====

/* long __cdecl SIrpCompletionRoutine(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64,void *
   __ptr64) */

long __cdecl SIrpCompletionRoutine(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (param_2[0x41] != (_IRP)0x0) {
    *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) = *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) | 1;
  }
  *(undefined4 *)(lVar1 + 0x98) = 0;
  IoReleaseRemoveLockEx(lVar1 + 0x50,param_2,0x20);
  return 0;
}



===== FilterDispatchPower @ 1c00013b0 =====

/* long __cdecl FilterDispatchPower(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl FilterDispatchPower(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  int *piVar5;
  undefined8 *puVar6;
  int iVar7;
  
  lVar4 = *(longlong *)(param_2 + 0xb8);
  piVar5 = *(int **)(param_1 + 0x40);
  iVar1 = *(int *)(lVar4 + 0x18);
  iVar2 = *(int *)(lVar4 + 0x10);
  iVar3 = *(int *)(lVar4 + 0x20);
  iVar7 = IoAcquireRemoveLockEx(piVar5 + 0x14,param_2,"",1,0x20);
  if (iVar7 < 0) {
    *(int *)(param_2 + 0x30) = iVar7;
    PoStartNextPowerIrp(param_2);
    IofCompleteRequest(param_2,0);
  }
  else {
    if (*(char *)(lVar4 + 1) == '\x02') {
      if (iVar2 == 0) {
        piVar5[0x10] = iVar1;
        piVar5[0x11] = iVar3;
        if (*piVar5 == 3) {
          *(undefined4 *)(*(longlong *)(param_1 + 0x40) + 0x98) = 1;
          PoStartNextPowerIrp(param_2);
          puVar6 = *(undefined8 **)(param_2 + 0xb8);
          puVar6[-9] = *puVar6;
          puVar6[-8] = puVar6[1];
          puVar6[-7] = puVar6[2];
          puVar6[-6] = puVar6[3];
          *(undefined4 *)(puVar6 + -5) = *(undefined4 *)(puVar6 + 4);
          *(undefined4 *)((longlong)puVar6 + -0x24) = *(undefined4 *)((longlong)puVar6 + 0x24);
          *(undefined4 *)(puVar6 + -4) = *(undefined4 *)(puVar6 + 5);
          *(undefined4 *)((longlong)puVar6 + -0x1c) = *(undefined4 *)((longlong)puVar6 + 0x2c);
          puVar6[-3] = puVar6[6];
          *(undefined1 *)((longlong)puVar6 + -0x45) = 0;
          lVar4 = *(longlong *)(param_2 + 0xb8);
          *(undefined8 *)(lVar4 + -8) = 0;
          *(code **)(lVar4 + -0x10) = SIrpCompletionRoutine;
          *(undefined1 *)(lVar4 + -0x45) = 0xe0;
          *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) =
               *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) | 1;
          PoCallDriver(*(undefined8 *)(piVar5 + 0xc),param_2);
          return 0x103;
        }
      }
      else if ((iVar2 == 1) &&
              ((PoSetPowerState(param_1,1,iVar1), piVar5[0x1d] == 0 || (iVar3 != 3)))) {
        piVar5[0x12] = iVar1;
      }
    }
    PoStartNextPowerIrp(param_2);
    param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    iVar7 = PoCallDriver(*(undefined8 *)(piVar5 + 0xc),param_2);
    IoReleaseRemoveLockEx(piVar5 + 0x14,param_2,0x20);
  }
  return iVar7;
}



===== FilterDispatchIo @ 1c0001540 =====

/* long __cdecl FilterDispatchIo(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl FilterDispatchIo(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  long lVar1;
  
  if ((**(int **)(param_1 + 0x40) == 3) || ((*(int **)(param_1 + 0x40))[0xe] != 6)) {
    lVar1 = FilterPass(param_1,param_2);
    return lVar1;
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc000000e;
  IofCompleteRequest(param_2,0);
  return -0x3ffffff2;
}



===== FilterSCSI @ 1c0001590 =====

/* long __cdecl FilterSCSI(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl FilterSCSI(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  int *piVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong lVar4;
  int iVar5;
  long lVar6;
  
  piVar1 = *(int **)(param_1 + 0x40);
  if (*piVar1 == 1) {
    iVar5 = -0x3fffffff;
  }
  else {
    iVar5 = 0;
    lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
    if (lVar2 == 0) {
      iVar5 = -0x3ffffff3;
    }
    else if (*(char *)(lVar2 + 2) != '\a') {
      iVar5 = IoAcquireRemoveLockEx(piVar1 + 0x14,param_2,"",1,0x20);
      if (iVar5 < 0) {
        *(int *)(param_2 + 0x30) = iVar5;
        goto LAB_1c00015be;
      }
      iVar5 = piVar1[0x10];
      if (((((iVar5 == 1) || (*(char *)(lVar2 + 2) != '\0')) || (*(char *)(lVar2 + 0x48) != '\x1b'))
          || (((*(byte *)(lVar2 + 0x4c) & 1) != 0 || ((*(byte *)(lVar2 + 0x49) & 1) == 0)))) ||
         (*(char *)(lVar2 + 10) != '\x06')) {
LAB_1c00016c8:
        param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
        *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      }
      else {
        if (iVar5 == 6) {
          if (piVar1[0x11] == 5) {
            *(byte *)(lVar2 + 0x49) = *(byte *)(lVar2 + 0x49) & 0xfe;
          }
        }
        else if (((iVar5 != 5) || (piVar1[0x1d] != 0)) && (2 < iVar5 - 2U)) goto LAB_1c00016c8;
        *(undefined1 *)(lVar2 + 10) = 0;
        *(undefined1 *)(lVar2 + 2) = 7;
        puVar3 = *(undefined8 **)(param_2 + 0xb8);
        puVar3[-9] = *puVar3;
        puVar3[-8] = puVar3[1];
        puVar3[-7] = puVar3[2];
        puVar3[-6] = puVar3[3];
        *(undefined4 *)(puVar3 + -5) = *(undefined4 *)(puVar3 + 4);
        *(undefined4 *)((longlong)puVar3 + -0x24) = *(undefined4 *)((longlong)puVar3 + 0x24);
        *(undefined4 *)(puVar3 + -4) = *(undefined4 *)(puVar3 + 5);
        *(undefined4 *)((longlong)puVar3 + -0x1c) = *(undefined4 *)((longlong)puVar3 + 0x2c);
        puVar3[-3] = puVar3[6];
        *(undefined1 *)((longlong)puVar3 + -0x45) = 0;
        lVar4 = *(longlong *)(param_2 + 0xb8);
        *(code **)(lVar4 + -0x10) = FilterSCSIHiberStopCompletionRoutine;
        *(longlong *)(lVar4 + -8) = lVar2;
        *(undefined1 *)(lVar4 + -0x45) = 0xe0;
      }
      lVar6 = IofCallDriver(*(undefined8 *)(piVar1 + 0xc),param_2);
      IoReleaseRemoveLockEx(piVar1 + 0x14,param_2,0x20);
      return lVar6;
    }
  }
  *(int *)(param_2 + 0x30) = iVar5;
LAB_1c00015be:
  IofCompleteRequest(param_2,0);
  return iVar5;
}



===== FilterSCSIHiberStopCompletionRoutine @ 1c0001720 =====

/* long __cdecl FilterSCSIHiberStopCompletionRoutine(struct _DEVICE_OBJECT * __ptr64,struct _IRP *
   __ptr64,void * __ptr64) */

long __cdecl
FilterSCSIHiberStopCompletionRoutine(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  if (param_2[0x41] != (_IRP)0x0) {
    *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) = *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) | 1;
  }
  *(byte *)((longlong)param_3 + 0x49) = *(byte *)((longlong)param_3 + 0x49) | 1;
  *(undefined1 *)((longlong)param_3 + 2) = 0;
  *(undefined1 *)((longlong)param_3 + 10) = 6;
  return 0;
}



===== SrbAsyncCompletion @ 1c0001750 =====

/* long __cdecl SrbAsyncCompletion(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64,void *
   __ptr64) */

long __cdecl SrbAsyncCompletion(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (*(longlong *)(*(longlong *)(param_2 + 0xb8) + 8) == 0) {
    if (param_3 != (void *)0x0) {
      ExFreePoolWithTag(param_3,0x61744158);
    }
    IoFreeIrp(param_2);
  }
  else if (param_2[0x41] == (_IRP)0x1) {
    KeSetEvent(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 8),0,0);
  }
  IoReleaseRemoveLockEx(lVar1 + 0x50,lVar1,0x20);
  return -0x3fffffea;
}



===== __report_gsfailure @ 1c00017d0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __security_check_cookie @ 1c00017f0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== RtlQueryRegistryValues @ 1c0001810 =====

void RtlQueryRegistryValues(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001c0001810. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlQueryRegistryValues();
  return;
}



===== _guard_check_icall @ 1c0001820 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0001830 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c0001850 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong __GSHandlerCheckCommon(undefined8 param_1,longlong param_2)

{
  byte bVar1;
  longlong lVar2;
  
  bVar1 = *(byte *)((ulonglong)*(uint *)(*(longlong *)(param_2 + 0x10) + 8) +
                    *(longlong *)(param_2 + 8) + 3);
  lVar2 = CONCAT71((int7)((ulonglong)*(longlong *)(param_2 + 0x10) >> 8),bVar1);
  if ((bVar1 & 0xf) != 0) {
    lVar2 = (longlong)(int)(bVar1 & 0xfffffff0);
  }
  return lVar2;
}



===== _guard_dispatch_icall @ 1c00018d0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c00018d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== memcpy @ 1c0001900 =====

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined1 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  int iVar7;
  uint uVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  
  uVar11 = (longlong)_Src - (longlong)_Dst;
  if (_Src < _Dst) {
    puVar9 = (undefined8 *)((longlong)_Dst + _Size);
    if (0x4e < _Size) {
      if (uVar11 < 0xfffffffffffffff1) {
        uVar12 = (ulonglong)((uint)puVar9 & 0xf);
        if (((ulonglong)puVar9 & 0xf) != 0) {
          _Size = _Size - uVar12;
          uVar12 = -uVar12;
          puVar10 = (undefined8 *)((uVar11 - 0x10) + (longlong)puVar9);
          uVar4 = puVar10[1];
          puVar9[-2] = *puVar10;
          puVar9[-1] = uVar4;
        }
        puVar9 = (undefined8 *)(uVar12 + (longlong)puVar9);
      }
      else {
        while (((ulonglong)puVar9 & 0xf) != 0) {
          puVar9 = (undefined8 *)((longlong)puVar9 + -1);
          _Size = _Size - 1;
          *(undefined1 *)puVar9 = *(undefined1 *)(uVar11 + (longlong)puVar9);
        }
      }
      uVar12 = _Size >> 5;
      if ((0x2000 < uVar12) && (uVar11 < 0xfffffffffffffe01)) {
        do {
          iVar7 = 4;
          do {
            puVar10 = puVar9;
            iVar7 = iVar7 + -1;
            puVar9 = puVar10 + -0x10;
          } while (iVar7 != 0);
          iVar7 = 8;
          puVar10 = puVar10 + 0x30;
          do {
            puVar9 = (undefined8 *)((uVar11 - 0x10) + (longlong)puVar10);
            uVar4 = puVar9[1];
            puVar1 = (undefined8 *)((uVar11 - 0x20) + (longlong)puVar10);
            uVar5 = *puVar1;
            uVar6 = puVar1[1];
            puVar10[-2] = *puVar9;
            puVar10[-1] = uVar4;
            puVar10[-4] = uVar5;
            puVar10[-3] = uVar6;
            puVar9 = puVar10 + -8;
            puVar1 = (undefined8 *)(uVar11 + 0x10 + (longlong)puVar9);
            uVar4 = puVar1[1];
            uVar5 = *(undefined8 *)(uVar11 + (longlong)puVar9);
            uVar6 = ((undefined8 *)(uVar11 + (longlong)puVar9))[1];
            puVar10[-6] = *puVar1;
            puVar10[-5] = uVar4;
            *puVar9 = uVar5;
            puVar10[-7] = uVar6;
            iVar7 = iVar7 + -1;
            puVar10 = puVar9;
          } while (iVar7 != 0);
          _Size = _Size - 0x200;
        } while (0x1ff < _Size);
        LOCK();
        UNLOCK();
        uVar12 = _Size >> 5;
        if (uVar12 == 0) goto LAB_1c0001ab7;
      }
      _Size = _Size & 0x1f;
      puVar10 = puVar9;
      do {
        puVar1 = (undefined8 *)((uVar11 - 0x10) + (longlong)puVar10);
        uVar4 = puVar1[1];
        puVar9 = (undefined8 *)((uVar11 - 0x20) + (longlong)puVar10);
        uVar5 = *puVar9;
        uVar6 = puVar9[1];
        puVar9 = puVar10 + -4;
        puVar10[-2] = *puVar1;
        puVar10[-1] = uVar4;
        *puVar9 = uVar5;
        puVar10[-3] = uVar6;
        uVar12 = uVar12 - 1;
        puVar10 = puVar9;
      } while (uVar12 != 0);
    }
LAB_1c0001ab7:
    for (uVar12 = _Size >> 3; uVar12 != 0; uVar12 = uVar12 - 1) {
      puVar10 = (undefined8 *)((uVar11 - 8) + (longlong)puVar9);
      puVar9 = puVar9 + -1;
      *puVar9 = *puVar10;
    }
    for (uVar12 = _Size & 7; uVar12 != 0; uVar12 = uVar12 - 1) {
      puVar3 = (undefined1 *)((uVar11 - 1) + (longlong)puVar9);
      puVar9 = (undefined8 *)((longlong)puVar9 + -1);
      *(undefined1 *)puVar9 = *puVar3;
    }
    return _Dst;
  }
  puVar9 = _Dst;
  if (0x4e < _Size) {
    if (uVar11 < 0x10) {
      for (; ((ulonglong)puVar9 & 0xf) != 0; puVar9 = (undefined8 *)((longlong)puVar9 + 1)) {
        _Size = _Size - 1;
        *(undefined1 *)puVar9 = *(undefined1 *)(uVar11 + (longlong)puVar9);
      }
    }
    else {
      uVar8 = -(int)_Dst & 0xf;
      if (uVar8 != 0) {
        _Size = _Size - uVar8;
        uVar4 = ((undefined8 *)(uVar11 + (longlong)_Dst))[1];
        *(undefined8 *)_Dst = *(undefined8 *)(uVar11 + (longlong)_Dst);
        *(undefined8 *)((longlong)_Dst + 8) = uVar4;
      }
      puVar9 = (undefined8 *)((ulonglong)uVar8 + (longlong)_Dst);
    }
    uVar12 = _Size >> 5;
    if ((0x2000 < uVar12) && (0x1ff < uVar11)) {
      do {
        iVar7 = 4;
        do {
          puVar10 = puVar9;
          iVar7 = iVar7 + -1;
          puVar9 = puVar10 + 0x10;
        } while (iVar7 != 0);
        iVar7 = 8;
        puVar10 = puVar10 + -0x30;
        do {
          uVar4 = ((undefined8 *)(uVar11 + (longlong)puVar10))[1];
          puVar9 = (undefined8 *)(uVar11 + 0x10 + (longlong)puVar10);
          uVar5 = *puVar9;
          uVar6 = puVar9[1];
          *puVar10 = *(undefined8 *)(uVar11 + (longlong)puVar10);
          puVar10[1] = uVar4;
          puVar10[2] = uVar5;
          puVar10[3] = uVar6;
          puVar9 = puVar10 + 8;
          puVar1 = (undefined8 *)((uVar11 - 0x20) + (longlong)puVar9);
          uVar4 = puVar1[1];
          puVar2 = (undefined8 *)((uVar11 - 0x10) + (longlong)puVar9);
          uVar5 = *puVar2;
          uVar6 = puVar2[1];
          puVar10[4] = *puVar1;
          puVar10[5] = uVar4;
          puVar10[6] = uVar5;
          puVar10[7] = uVar6;
          iVar7 = iVar7 + -1;
          puVar10 = puVar9;
        } while (iVar7 != 0);
        _Size = _Size - 0x200;
      } while (0x1ff < _Size);
      LOCK();
      UNLOCK();
      uVar12 = _Size >> 5;
      if (uVar12 == 0) goto LAB_1c0001912;
    }
    _Size = _Size & 0x1f;
    puVar10 = puVar9;
    do {
      uVar4 = ((undefined8 *)(uVar11 + (longlong)puVar10))[1];
      puVar9 = (undefined8 *)(uVar11 + 0x10 + (longlong)puVar10);
      uVar5 = *puVar9;
      uVar6 = puVar9[1];
      puVar9 = puVar10 + 4;
      *puVar10 = *(undefined8 *)(uVar11 + (longlong)puVar10);
      puVar10[1] = uVar4;
      puVar10[2] = uVar5;
      puVar10[3] = uVar6;
      uVar12 = uVar12 - 1;
      puVar10 = puVar9;
    } while (uVar12 != 0);
  }
LAB_1c0001912:
  for (uVar12 = _Size >> 3; uVar12 != 0; uVar12 = uVar12 - 1) {
    *puVar9 = *(undefined8 *)(uVar11 + (longlong)puVar9);
    puVar9 = puVar9 + 1;
  }
  for (uVar12 = _Size & 7; uVar12 != 0; uVar12 = uVar12 - 1) {
    *(undefined1 *)puVar9 = *(undefined1 *)(uVar11 + (longlong)puVar9);
    puVar9 = (undefined8 *)((longlong)puVar9 + 1);
  }
  return _Dst;
}



===== memset @ 1c0001c40 =====

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  uint uVar1;
  void *pvVar2;
  ulonglong *puVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  uVar4 = (ulonglong)(uint)_Val;
  pvVar2 = _Dst;
  if (7 < _Size) {
    uVar4 = (ulonglong)(byte)_Val * 0x101010101010101;
    if (0x46 < _Size) {
      uVar1 = -(int)_Dst & 7;
      if (uVar1 != 0) {
        _Size = _Size - uVar1;
        *(ulonglong *)_Dst = uVar4;
      }
      puVar3 = (ulonglong *)((ulonglong)uVar1 + (longlong)_Dst);
      uVar6 = _Size >> 6;
      uVar5 = _Size >> 3 & 7;
      if (uVar5 == 0) goto LAB_1c0001d00;
      puVar3 = puVar3 + (uVar5 - 8);
      uVar6 = uVar6 + 1;
      switch(uVar5) {
      case 2:
        goto switchD_1c0001cfd_caseD_2;
      case 3:
        goto switchD_1c0001cfd_caseD_3;
      case 4:
        goto switchD_1c0001cfd_caseD_4;
      case 5:
        goto switchD_1c0001cfd_caseD_5;
      case 6:
        goto switchD_1c0001cfd_caseD_6;
      case 7:
        goto switchD_1c0001cfd_caseD_7;
      }
      while( true ) {
        puVar3[7] = uVar4;
        puVar3 = puVar3 + 8;
        uVar6 = uVar6 - 1;
        if (uVar6 == 0) break;
LAB_1c0001d00:
        *puVar3 = uVar4;
switchD_1c0001cfd_caseD_7:
        puVar3[1] = uVar4;
switchD_1c0001cfd_caseD_6:
        puVar3[2] = uVar4;
switchD_1c0001cfd_caseD_5:
        puVar3[3] = uVar4;
switchD_1c0001cfd_caseD_4:
        puVar3[4] = uVar4;
switchD_1c0001cfd_caseD_3:
        puVar3[5] = uVar4;
switchD_1c0001cfd_caseD_2:
        puVar3[6] = uVar4;
      }
      for (uVar5 = _Size & 7; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(char *)((uVar5 - 1) + (longlong)puVar3) = (char)uVar4;
      }
      return _Dst;
    }
    uVar5 = _Size & 0xfffffffffffffff8;
    pvVar2 = (void *)((longlong)_Dst + uVar5);
    do {
      *(ulonglong *)((uVar5 - 8) + (longlong)_Dst) = uVar4;
      uVar5 = uVar5 - 8;
    } while (uVar5 != 0);
  }
  for (uVar5 = _Size & 7; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(char *)((uVar5 - 1) + (longlong)pvVar2) = (char)uVar4;
  }
  return _Dst;
}



===== WppLoadTracingSupport @ 1c0006000 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppLoadTracingSupport(void)

{
  uint local_res8 [8];
  undefined1 local_18 [16];
  
  local_res8[0] = 0;
  RtlInitUnicodeString(local_18,L"PsGetVersion");
  pfnWppGetVersion = MmGetSystemRoutineAddress(local_18);
  RtlInitUnicodeString(local_18,L"WmiTraceMessage");
  pfnWppTraceMessage = MmGetSystemRoutineAddress(local_18);
  RtlInitUnicodeString(local_18,L"WmiQueryTraceInformation");
  pfnWppQueryTraceInformation = MmGetSystemRoutineAddress(local_18);
  WPPTraceSuite = 2;
  if (pfnWppGetVersion != 0) {
    (*(code *)pfnWppGetVersion)(local_res8,0,0,0);
  }
  if (5 < local_res8[0]) {
    RtlInitUnicodeString(local_18,L"EtwRegisterClassicProvider");
    pfnEtwRegisterClassicProvider = MmGetSystemRoutineAddress(local_18);
    if (pfnEtwRegisterClassicProvider != 0) {
      RtlInitUnicodeString(local_18,&u_EtwUnregister);
      pfnEtwUnregister = MmGetSystemRoutineAddress(local_18);
      WPPTraceSuite = 4;
    }
  }
  return;
}



===== WppTraceCallback @ 1c0006100 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
WppTraceCallback(byte param_1,undefined8 param_2,uint param_3,uint *param_4,longlong param_5,
                uint *param_6)

{
  ushort *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint *puVar4;
  int iVar5;
  undefined4 uVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  uint uVar12;
  bool bVar13;
  undefined1 local_res8 [8];
  undefined1 uStack_36;
  undefined4 uStack_34;
  
  puVar4 = param_6;
  *param_6 = 0;
  if (3 < param_1) {
    if (param_1 < 6) {
      if (param_5 != 0) {
        if (param_3 < 0x30) {
          return 0xc000000d;
        }
        do {
          lVar7 = RtlCompareMemory(*(undefined8 *)(param_5 + 8),param_4 + 6,0x10);
          if (lVar7 == 0x10) break;
          param_5 = *(longlong *)(param_5 + 0x10);
        } while (param_5 != 0);
        if (param_5 != 0) {
          if (param_1 == 5) {
            *(undefined1 *)(param_5 + 0x29) = 0;
            *(undefined4 *)(param_5 + 0x2c) = 0;
            *(undefined8 *)(param_5 + 0x18) = 0;
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
            *(undefined1 *)(param_5 + 0x29) = local_res8[0];
          }
          uVar6 = (*pfnWppQueryTraceInformation)(2,param_5 + 0x2c,4,&param_6,param_4);
          return uVar6;
        }
      }
      return 0xc0000295;
    }
    if (param_1 < 8) {
      return 0;
    }
    if (param_1 == 8) {
      uVar10 = 0;
      puVar1 = *(ushort **)(param_5 + 0x20);
      lVar7 = param_5;
      do {
        lVar7 = *(longlong *)(lVar7 + 0x10);
        uVar10 = uVar10 + 1;
      } while (lVar7 != 0);
      if (0x3f < uVar10) {
        return 0xc000000d;
      }
      if (puVar1 == (ushort *)0x0) {
        uVar12 = 0;
        uVar9 = uVar10 * 0x20 + 0x18;
      }
      else {
        uVar12 = uVar10 * 0x20 + 0x18;
        uVar9 = *puVar1 + 2 + uVar12;
      }
      if (param_3 < uVar9) {
        if (param_3 < 4) {
          return 0xc0000023;
        }
        *param_4 = uVar9;
        *param_6 = 4;
        return 0xc0000023;
      }
      memset(param_4,0,(ulonglong)param_3);
      *param_4 = uVar9;
      param_4[2] = uVar12;
      param_4[4] = uVar10;
      if (puVar1 != (ushort *)0x0) {
        *(ushort *)((ulonglong)uVar12 + (longlong)param_4) = *puVar1;
        memcpy((ushort *)((ulonglong)uVar12 + (longlong)param_4) + 1,*(void **)(puVar1 + 4),
               (ulonglong)*puVar1);
      }
      if (uVar10 != 0) {
        uVar8 = (ulonglong)uVar10;
        puVar11 = param_4 + 10;
        do {
          uVar2 = **(undefined8 **)(param_5 + 8);
          uVar3 = (*(undefined8 **)(param_5 + 8))[1];
          *puVar11 = 0x81000;
          *(undefined8 *)(puVar11 + -4) = uVar2;
          *(undefined8 *)(puVar11 + -2) = uVar3;
          *(undefined1 *)(param_5 + 0x29) = 0;
          *(undefined4 *)(param_5 + 0x2c) = 0;
          param_5 = *(longlong *)(param_5 + 0x10);
          uVar8 = uVar8 - 1;
          puVar11 = puVar11 + 8;
        } while (uVar8 != 0);
      }
      *puVar4 = uVar9;
      return 0;
    }
  }
  return 0xc0000010;
}



===== WppInitKm @ 1c000634c =====

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
      return;
    }
    if (WPPTraceSuite == 2) {
      _WPP_MAIN_CB = WppTraceCallback;
      IoWMIRegistrationControl(&WPP_MAIN_CB,0x80010001);
    }
  }
  return;
}



===== FilterAddDevice @ 1c00063e0 =====

/* long __cdecl FilterAddDevice(struct _DRIVER_OBJECT * __ptr64,struct _DEVICE_OBJECT * __ptr64) */

long __cdecl FilterAddDevice(_DRIVER_OBJECT *param_1,_DEVICE_OBJECT *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  longlong lVar5;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  local_res18[0] = IoGetAttachedDeviceReference(param_2);
  uVar2 = *(undefined4 *)(local_res18[0] + 0x48);
  ObfDereferenceObject(local_res18[0]);
  iVar4 = IoCreateDevice(param_1,200,0,uVar2,0x100,0,local_res18);
  if (-1 < iVar4) {
    puVar3 = *(undefined4 **)(local_res18[0] + 0x40);
    *puVar3 = 1;
    lVar5 = IoAttachDeviceToDeviceStack(local_res18[0],param_2);
    *(longlong *)(puVar3 + 0xc) = lVar5;
    if (lVar5 == 0) {
      IoDeleteDevice();
      iVar4 = -0x3fffffff;
    }
    else {
      *(uint *)(local_res18[0] + 0x30) =
           *(uint *)(local_res18[0] + 0x30) | *(uint *)(lVar5 + 0x30) & 0x2014;
      *(undefined4 *)(local_res18[0] + 0x48) = *(undefined4 *)(*(longlong *)(puVar3 + 0xc) + 0x48);
      *(undefined4 *)(local_res18[0] + 0x34) = *(undefined4 *)(*(longlong *)(puVar3 + 0xc) + 0x34);
      *(longlong *)(puVar3 + 4) = local_res18[0];
      IoInitializeRemoveLockEx(puVar3 + 0x14,0x61744158,0,0,0x20);
      *(undefined8 *)(puVar3 + 6) = 0;
      puVar1 = puVar3 + 8;
      *(_DEVICE_OBJECT **)(puVar3 + 2) = param_2;
      *(undefined4 **)(puVar3 + 10) = puVar1;
      *(undefined4 **)puVar1 = puVar1;
      *(undefined8 *)(puVar3 + 0x26) = 0;
      puVar3[0x28] = 0;
      puVar3[0x24] = 1;
      KeInitializeEvent(puVar3 + 0x2a,1,0);
      puVar3[0x12] = 0;
      puVar3[0x11] = 0;
      puVar3[0xe] = 0;
      puVar3[0xf] = 0;
      puVar3[0x10] = 1;
      *(uint *)(local_res18[0] + 0x30) = *(uint *)(local_res18[0] + 0x30) & 0xffffff7f;
      iVar4 = 0;
    }
  }
  return iVar4;
}



===== FilterDispatchPnp @ 1c0006540 =====

/* long __cdecl FilterDispatchPnp(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl FilterDispatchPnp(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  uint *puVar6;
  undefined4 *puVar7;
  int iVar8;
  long lVar9;
  longlong lVar10;
  code *pcVar11;
  _PDO_EXTENSION *p_Var12;
  uint uVar13;
  _IRP *p_Var14;
  _PDO_EXTENSION *p_Var15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  _PDO_EXTENSION *p_Var19;
  uchar uVar20;
  undefined8 uVar21;
  _PDO_EXTENSION *p_Var22;
  _func_long__DEVICE_OBJECT_ptr__IRP_ptr_void_ptr *p_Var23;
  uint *puVar24;
  _PDO_EXTENSION *p_Var25;
  undefined4 uVar26;
  bool bVar27;
  int local_res8;
  uint local_res10;
  int local_res18;
  undefined8 uStack_d0;
  undefined1 auStack_c8 [8];
  undefined1 auStack_c0 [24];
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined1 local_a0;
  longlong *local_98;
  longlong local_88 [2];
  _PDO_EXTENSION *local_78;
  _PDO_EXTENSION *local_70;
  undefined1 local_68 [40];
  
  p_Var19 = *(_PDO_EXTENSION **)(param_1 + 0x40);
  uVar20 = 'p';
  lVar10 = *(longlong *)(param_2 + 0xb8);
  local_a8 = 0x20;
  p_Var23 = (_func_long__DEVICE_OBJECT_ptr__IRP_ptr_void_ptr *)0x1;
  local_78 = p_Var19 + 0x50;
  iVar8 = IoAcquireRemoveLockEx(local_78);
  puVar17 = auStack_c8;
  puVar16 = auStack_c8;
  puVar18 = auStack_c8;
  if (iVar8 < 0) {
    *(int *)(param_2 + 0x30) = iVar8;
    IofCompleteRequest(param_2);
    return iVar8;
  }
  bVar1 = *(byte *)(lVar10 + 1);
  uVar26 = *(undefined4 *)(param_2 + 0x30);
  if (6 < bVar1) {
    if (bVar1 == 7) {
      if (*(int *)p_Var19 == 1) {
        uVar21 = 0;
        KeInitializeEvent(local_68);
        puVar5 = *(undefined8 **)(param_2 + 0xb8);
        puVar5[-9] = *puVar5;
        puVar5[-8] = puVar5[1];
        puVar5[-7] = puVar5[2];
        puVar5[-6] = puVar5[3];
        *(undefined4 *)(puVar5 + -5) = *(undefined4 *)(puVar5 + 4);
        *(undefined4 *)((longlong)puVar5 + -0x24) = *(undefined4 *)((longlong)puVar5 + 0x24);
        *(undefined4 *)(puVar5 + -4) = *(undefined4 *)(puVar5 + 5);
        *(undefined4 *)((longlong)puVar5 + -0x1c) = *(undefined4 *)((longlong)puVar5 + 0x2c);
        puVar5[-3] = puVar5[6];
        *(undefined1 *)((longlong)puVar5 + -0x45) = 0;
        lVar3 = *(longlong *)(param_2 + 0xb8);
        *(code **)(lVar3 + -0x10) = FilterQueryDeviceRelationsCompletionRoutine;
        *(undefined1 **)(lVar3 + -8) = local_68;
        *(undefined1 *)(lVar3 + -0x45) = 0xe0;
        p_Var14 = param_2;
        local_res18 = IofCallDriver(*(undefined8 *)(p_Var19 + 0x30));
        if (local_res18 == 0x103) {
          local_a8 = 0;
          uStack_a4 = 0;
          uVar21 = 0;
          p_Var14 = (_IRP *)0x0;
          KeWaitForSingleObject(local_68,0,0,0);
          local_res18 = *(int *)(param_2 + 0x30);
        }
        puVar18 = auStack_c8;
        if ((-1 < local_res18) && (puVar18 = auStack_c8, *(int *)(lVar10 + 8) == 0)) {
          puVar6 = *(uint **)(param_2 + 0x38);
          if (puVar6 != (uint *)0x0) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),p_Var14,uVar21,*puVar6);
            }
            local_res10 = 0;
            if (*puVar6 != 0) {
              p_Var25 = (_PDO_EXTENSION *)0x3;
              puVar24 = puVar6;
              do {
                puVar24 = puVar24 + 2;
                local_88[0] = 0;
                ExAcquireFastMutex(p_Var19 + 0x90);
                p_Var22 = p_Var19 + 0x20;
                p_Var12 = *(_PDO_EXTENSION **)p_Var22;
                if (p_Var12 != p_Var22) {
                  p_Var15 = *(_PDO_EXTENSION **)p_Var12;
                  do {
                    if (*(longlong *)(p_Var12 + -0x18) == *(longlong *)puVar24) {
                      local_88[0] = *(longlong *)(p_Var12 + -0x10);
                      break;
                    }
                    bVar27 = p_Var15 != p_Var22;
                    p_Var12 = p_Var15;
                    p_Var15 = *(_PDO_EXTENSION **)p_Var15;
                  } while (bVar27);
                }
                ExReleaseFastMutex(p_Var19 + 0x90);
                if (local_88[0] == 0) {
                  local_88[0] = IoGetAttachedDeviceReference(*(undefined8 *)puVar24);
                  uVar26 = *(undefined4 *)(local_88[0] + 0x48);
                  ObfDereferenceObject(local_88[0]);
                  local_res8 = 5;
                  do {
                    local_res8 = local_res8 + -1;
                    iVar8 = IoSizeofWorkItem();
                    local_98 = local_88;
                    local_a0 = 0;
                    local_a8 = 0x100;
                    iVar8 = IoCreateDevice(*(undefined8 *)(param_1 + 8),iVar8 + 0x2c8,0,uVar26);
                    if (-1 < iVar8) {
                      puVar7 = *(undefined4 **)(local_88[0] + 0x40);
                      lVar10 = IoAttachDeviceToDeviceStack(local_88[0],*(undefined8 *)puVar24);
                      *(longlong *)(puVar7 + 0xc) = lVar10;
                      if (lVar10 == 0) {
                        IoDeleteDevice();
                      }
                      else {
                        local_a8 = 0x20;
                        *(uint *)(local_88[0] + 0x30) =
                             *(uint *)(local_88[0] + 0x30) | *(uint *)(lVar10 + 0x30) & 0x2014;
                        p_Var22 = (_PDO_EXTENSION *)0x0;
                        *(undefined4 *)(local_88[0] + 0x48) =
                             *(undefined4 *)(*(longlong *)(puVar7 + 0xc) + 0x48);
                        *(undefined4 *)(local_88[0] + 0x34) =
                             *(undefined4 *)(*(longlong *)(puVar7 + 0xc) + 0x34);
                        *(longlong *)(puVar7 + 4) = local_88[0];
                        *(undefined8 *)(puVar7 + 2) = *(undefined8 *)puVar24;
                        plVar4 = (longlong *)(puVar7 + 8);
                        *puVar7 = 3;
                        *(_DEVICE_OBJECT **)(puVar7 + 6) = param_1;
                        *(longlong **)(puVar7 + 10) = plVar4;
                        *plVar4 = (longlong)plVar4;
                        IoInitializeRemoveLockEx(puVar7 + 0x14,0x61744158,0,0);
                        puVar7[0x12] = 4;
                        *(undefined4 **)(puVar7 + 0xb0) = puVar7 + 0xb2;
                        *(undefined8 *)(puVar7 + 0x10) = 1;
                        *(undefined8 *)(puVar7 + 0xe) = 0;
                        IoInitializeWorkItem(local_88[0]);
                        ExAcquireFastMutex(p_Var19 + 0x90);
                        puVar5 = *(undefined8 **)(p_Var19 + 0x28);
                        *plVar4 = (longlong)(p_Var19 + 0x20);
                        *(undefined8 **)(puVar7 + 10) = puVar5;
                        if ((_PDO_EXTENSION *)*puVar5 != p_Var19 + 0x20) {
                          p_Var12 = (_PDO_EXTENSION *)0x3;
                          pcVar11 = (code *)swi(0x29);
                          (*pcVar11)();
                          puVar18 = auStack_c0;
                          goto LAB_1c0006d07;
                        }
                        *puVar5 = plVar4;
                        *(longlong **)(p_Var19 + 0x28) = plVar4;
                        ExReleaseFastMutex(p_Var19 + 0x90);
                        *(uint *)(local_88[0] + 0x30) = *(uint *)(local_88[0] + 0x30) & 0xffffff7f;
                      }
                      break;
                    }
                    local_88[1] = 0xfffffffffffffc18;
                    KeDelayExecutionThread(0);
                  } while (local_res8 != 0);
                }
                local_res10 = local_res10 + 1;
              } while (local_res10 < *puVar6);
            }
          }
          puVar18 = auStack_c8;
          p_Var25 = p_Var19 + 0x90;
          ExAcquireFastMutex(p_Var25);
          p_Var19 = p_Var19 + 0x20;
          p_Var12 = *(_PDO_EXTENSION **)p_Var19;
          p_Var22 = *(_PDO_EXTENSION **)*(_PDO_EXTENSION **)p_Var19;
          while (p_Var12 != p_Var19) {
LAB_1c0006d07:
            if (puVar6 != (uint *)0x0) {
              uVar13 = 0;
              if (*puVar6 != 0) {
                puVar24 = puVar6;
                do {
                  puVar24 = puVar24 + 2;
                  if (*(longlong *)(p_Var12 + -0x18) == *(longlong *)puVar24) {
                    if (*(longlong *)(p_Var12 + -0x10) != 0) goto LAB_1c0006d3e;
                    break;
                  }
                  uVar13 = uVar13 + 1;
                } while (uVar13 < *puVar6);
              }
            }
            *(undefined8 *)(p_Var12 + -0x18) = 0xffffffffffffffff;
LAB_1c0006d3e:
            p_Var12 = p_Var22;
            p_Var22 = *(_PDO_EXTENSION **)p_Var22;
          }
          *(undefined8 *)(puVar18 + -8) = 0x1c0006d52;
          ExReleaseFastMutex(p_Var25);
        }
        *(undefined8 *)(puVar18 + -8) = 0x1c0006d5d;
        IofCompleteRequest(param_2,0);
        *(undefined8 *)(puVar18 + -8) = 0x1c0006d70;
        IoReleaseRemoveLockEx(local_78,param_2,0x20);
        return local_res18;
      }
    }
    else {
      puVar18 = auStack_c8;
      if (bVar1 != 8) {
        if (bVar1 == 0xc) {
          pcVar11 = FilterDeviceQueryDeviceTextCompletionRoutine;
        }
        else {
          if (bVar1 != 0x16) {
            puVar18 = auStack_c8;
            if (bVar1 == 0x17) {
              *(undefined4 *)(p_Var19 + 0x3c) = *(undefined4 *)(p_Var19 + 0x38);
              *(undefined4 *)(p_Var19 + 0x38) = 5;
              puVar18 = auStack_c8;
            }
            goto LAB_1c00069bf;
          }
          if ((*(longlong *)(param_1 + 0x18) == 0) ||
             ((*(uint *)(*(longlong *)(param_1 + 0x18) + 0x30) & 0x2000) != 0)) {
            *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x2000;
          }
          pcVar11 = FilterDeviceUsageNotificationCompletionRoutine;
        }
        puVar5 = *(undefined8 **)(param_2 + 0xb8);
        puVar5[-9] = *puVar5;
        puVar5[-8] = puVar5[1];
        puVar5[-7] = puVar5[2];
        puVar5[-6] = puVar5[3];
        *(undefined4 *)(puVar5 + -5) = *(undefined4 *)(puVar5 + 4);
        *(undefined4 *)((longlong)puVar5 + -0x24) = *(undefined4 *)((longlong)puVar5 + 0x24);
        *(undefined4 *)(puVar5 + -4) = *(undefined4 *)(puVar5 + 5);
        *(undefined4 *)((longlong)puVar5 + -0x1c) = *(undefined4 *)((longlong)puVar5 + 0x2c);
        puVar5[-3] = puVar5[6];
        *(undefined1 *)((longlong)puVar5 + -0x45) = 0;
        lVar10 = *(longlong *)(param_2 + 0xb8);
        *(code **)(lVar10 + -0x10) = pcVar11;
        *(undefined8 *)(lVar10 + -8) = 0;
        *(undefined1 *)(lVar10 + -0x45) = 0xe0;
        lVar9 = IofCallDriver(*(undefined8 *)(p_Var19 + 0x30),param_2);
        return lVar9;
      }
    }
    goto LAB_1c00069bf;
  }
  if (bVar1 == 6) {
    bVar27 = *(int *)(p_Var19 + 0x38) == 2;
LAB_1c00068ff:
    puVar18 = auStack_c8;
    if (bVar27) {
      *(undefined4 *)(p_Var19 + 0x38) = *(undefined4 *)(p_Var19 + 0x3c);
      puVar18 = auStack_c8;
    }
LAB_1c00069bf:
    param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    *(undefined4 *)(param_2 + 0x30) = uVar26;
    uVar21 = *(undefined8 *)(p_Var19 + 0x30);
    *(undefined8 *)(puVar18 + -8) = 0x1c00069db;
    lVar9 = IofCallDriver(uVar21,param_2);
    *(undefined8 *)(puVar18 + -8) = 0x1c00069f0;
    IoReleaseRemoveLockEx(p_Var19 + 0x50,param_2,0x20);
    return lVar9;
  }
  if (bVar1 == 0) {
    if (*(int *)p_Var19 == 3) {
      puVar5 = *(undefined8 **)(param_2 + 0xb8);
      puVar5[-9] = *puVar5;
      puVar5[-8] = puVar5[1];
      puVar5[-7] = puVar5[2];
      puVar5[-6] = puVar5[3];
      *(undefined4 *)(puVar5 + -5) = *(undefined4 *)(puVar5 + 4);
      *(undefined4 *)((longlong)puVar5 + -0x24) = *(undefined4 *)((longlong)puVar5 + 0x24);
      *(undefined4 *)(puVar5 + -4) = *(undefined4 *)(puVar5 + 5);
      *(undefined4 *)((longlong)puVar5 + -0x1c) = *(undefined4 *)((longlong)puVar5 + 0x2c);
      puVar5[-3] = puVar5[6];
      *(undefined1 *)((longlong)puVar5 + -0x45) = 0;
      lVar10 = *(longlong *)(param_2 + 0xb8);
      *(undefined8 *)(lVar10 + -8) = 0;
      *(code **)(lVar10 + -0x10) = PdoStartCompletionRoutine;
      *(undefined1 *)(lVar10 + -0x45) = 0xe0;
      *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) =
           *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) | 1;
      IofCallDriver(*(undefined8 *)(p_Var19 + 0x30),param_2);
      return 0x103;
    }
    *(undefined4 *)(p_Var19 + 0x48) = 1;
    PoSetPowerState(param_1,1,1);
    *(undefined4 *)(p_Var19 + 0x3c) = *(undefined4 *)(p_Var19 + 0x38);
    *(undefined4 *)(p_Var19 + 0x38) = 1;
    puVar18 = auStack_c8;
    goto LAB_1c00069bf;
  }
  if (bVar1 == 1) goto LAB_1c0006859;
  if (bVar1 != 2) {
    if (bVar1 != 3) {
      if (bVar1 == 4) {
        uVar2 = *(undefined4 *)(p_Var19 + 0x38);
        *(undefined4 *)(p_Var19 + 0x38) = 3;
        *(undefined4 *)(p_Var19 + 0x3c) = uVar2;
        puVar18 = auStack_c8;
      }
      else {
        puVar18 = auStack_c8;
        if (bVar1 == 5) {
          *(undefined4 *)(p_Var19 + 0x3c) = *(undefined4 *)(p_Var19 + 0x38);
          *(undefined4 *)(p_Var19 + 0x38) = 2;
          puVar18 = auStack_c8;
        }
      }
      goto LAB_1c00069bf;
    }
    bVar27 = *(int *)(p_Var19 + 0x38) == 4;
    goto LAB_1c00068ff;
  }
  if (*(int *)p_Var19 == 3) {
    if (*(longlong *)(p_Var19 + 0x80) != 0) {
      PoUnregisterPowerSettingCallback();
    }
    *(undefined8 *)(p_Var19 + 0x80) = 0;
    if (*(longlong *)(p_Var19 + 0x88) != 0) {
      PoUnregisterPowerSettingCallback();
    }
    puVar16 = auStack_c8;
    *(undefined8 *)(p_Var19 + 0x88) = 0;
    if (*(longlong *)(p_Var19 + 8) != -1) {
      if (((*(uint *)(p_Var19 + 0xa0) & 2) != 0) && (*(int *)(p_Var19 + 0x3c) == 1)) {
        StartStopUnitAsync(p_Var19,'\0',uVar20,p_Var23);
      }
      uVar26 = 0;
      *(undefined4 *)(p_Var19 + 0x3c) = *(undefined4 *)(p_Var19 + 0x38);
      *(undefined4 *)(p_Var19 + 0x38) = 0;
      puVar18 = auStack_c8;
      goto LAB_1c00069bf;
    }
    if (*(int *)p_Var19 == 3) {
      if (*(longlong *)(*(longlong *)(p_Var19 + 0x18) + 0x40) != 0) {
        lVar10 = *(longlong *)(*(longlong *)(p_Var19 + 0x18) + 0x40) + 0x90;
        ExAcquireFastMutex(lVar10);
        p_Var25 = p_Var19 + 0x20;
        lVar3 = *(longlong *)p_Var25;
        plVar4 = *(longlong **)(p_Var19 + 0x28);
        if ((*(_PDO_EXTENSION **)(lVar3 + 8) != p_Var25) || ((_PDO_EXTENSION *)*plVar4 != p_Var25))
        {
          pcVar11 = (code *)swi(0x29);
          (*pcVar11)(3);
          puVar16 = auStack_c0;
          goto LAB_1c0006744;
        }
        *plVar4 = lVar3;
        *(longlong **)(lVar3 + 8) = plVar4;
        ExReleaseFastMutex(lVar10);
      }
      IoUninitializeWorkItem(*(undefined8 *)(p_Var19 + 0x2c0));
      puVar16 = auStack_c8;
      goto LAB_1c00066eb;
    }
  }
LAB_1c0006744:
  local_70 = (_PDO_EXTENSION *)&local_78;
  p_Var22 = p_Var19 + 0x90;
  local_78 = (_PDO_EXTENSION *)&local_78;
  *(undefined8 *)(puVar16 + -8) = 0x1c0006764;
  ExAcquireFastMutex(p_Var22);
  p_Var25 = p_Var19 + 0x20;
  if (*(_PDO_EXTENSION **)p_Var25 != p_Var25) {
    p_Var12 = *(_PDO_EXTENSION **)p_Var25;
    p_Var15 = *(_PDO_EXTENSION **)*(_PDO_EXTENSION **)p_Var25;
    while (p_Var12 != p_Var25) {
      lVar10 = *(longlong *)p_Var12;
      plVar4 = *(longlong **)(p_Var12 + 8);
      if ((*(_PDO_EXTENSION **)(lVar10 + 8) != p_Var12) || ((_PDO_EXTENSION *)*plVar4 != p_Var12)) {
LAB_1c000684f:
        pcVar11 = (code *)swi(0x29);
        (*pcVar11)(3);
        puVar16 = puVar16 + 8;
        goto LAB_1c0006854;
      }
      *plVar4 = lVar10;
      *(longlong **)(lVar10 + 8) = plVar4;
      if (*(int *)(p_Var12 + 0x18) == 5) {
        *(_PDO_EXTENSION **)(p_Var12 + 8) = p_Var12;
        *(_PDO_EXTENSION **)p_Var12 = p_Var12;
        *(longlong *)(p_Var12 + -8) = 0;
      }
      else {
        *(_PDO_EXTENSION ***)p_Var12 = &local_78;
        *(_PDO_EXTENSION **)(p_Var12 + 8) = local_70;
        if (*(_PDO_EXTENSION ***)local_70 != &local_78) {
          pcVar11 = (code *)swi(0x29);
          (*pcVar11)(3);
          puVar16 = puVar16 + 8;
          goto LAB_1c000684f;
        }
        *(_PDO_EXTENSION **)local_70 = p_Var12;
        *(undefined4 *)(p_Var12 + 0x1c) = *(undefined4 *)(p_Var12 + 0x18);
        *(undefined4 *)(p_Var12 + 0x18) = 6;
        local_70 = p_Var12;
      }
      p_Var12 = p_Var15;
      p_Var15 = *(_PDO_EXTENSION **)p_Var15;
    }
  }
  *(undefined8 *)(puVar16 + -8) = 0x1c00067f1;
  ExReleaseFastMutex(p_Var22);
  if (local_78 != (_PDO_EXTENSION *)&local_78) {
    p_Var25 = *(_PDO_EXTENSION **)local_78;
    p_Var22 = local_78;
    do {
      p_Var12 = p_Var25;
      lVar10 = *(longlong *)p_Var22;
      plVar4 = *(longlong **)(p_Var22 + 8);
      if ((*(_PDO_EXTENSION **)(lVar10 + 8) != p_Var22) || ((_PDO_EXTENSION *)*plVar4 != p_Var22))
      goto LAB_1c0006854;
      *plVar4 = lVar10;
      *(longlong **)(lVar10 + 8) = plVar4;
      uVar21 = *(undefined8 *)(p_Var22 + 0x10);
      *(undefined8 *)(puVar16 + -8) = 0x1c000682b;
      IoDetachDevice(uVar21);
      uVar21 = *(undefined8 *)(p_Var22 + -0x10);
      *(undefined8 *)(puVar16 + -8) = 0x1c0006835;
      IoDeleteDevice(uVar21);
      p_Var25 = *(_PDO_EXTENSION **)p_Var12;
      p_Var22 = p_Var12;
    } while (p_Var12 != (_PDO_EXTENSION *)&local_78);
  }
LAB_1c00066eb:
  *(undefined8 *)(puVar16 + -8) = 0x1c00066fe;
  IoReleaseRemoveLockAndWaitEx(p_Var19 + 0x50,param_2,0x20);
  param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  uVar21 = *(undefined8 *)(p_Var19 + 0x30);
  *(undefined8 *)(puVar16 + -8) = 0x1c0006716;
  lVar9 = IofCallDriver(uVar21,param_2);
  *(undefined4 *)(p_Var19 + 0x3c) = *(undefined4 *)(p_Var19 + 0x38);
  uVar21 = *(undefined8 *)(p_Var19 + 0x30);
  *(undefined4 *)(p_Var19 + 0x38) = 6;
  *(undefined8 *)(puVar16 + -8) = 0x1c000672f;
  IoDetachDevice(uVar21);
  *(undefined8 *)(puVar16 + -8) = 0x1c0006738;
  IoDeleteDevice(param_1);
  return lVar9;
LAB_1c0006854:
  uVar26 = SUB84(p_Var22,0);
  pcVar11 = (code *)swi(0x29);
  (*pcVar11)(3);
  puVar17 = puVar16 + 8;
LAB_1c0006859:
  *(undefined4 *)(p_Var19 + 0x3c) = *(undefined4 *)(p_Var19 + 0x38);
  *(undefined4 *)(p_Var19 + 0x38) = 4;
  puVar18 = puVar17;
  goto LAB_1c00069bf;
}



===== PdoStartWorker @ 1c0006d90 =====

/* void __cdecl PdoStartWorker(struct _DEVICE_OBJECT * __ptr64,void * __ptr64) */

void __cdecl PdoStartWorker(_DEVICE_OBJECT *param_1,void *param_2)

{
  _PDO_EXTENSION *p_Var1;
  int iVar2;
  long lVar3;
  longlong lVar4;
  _SRB_IO_CONTROL *p_Var5;
  ulong local_res8;
  undefined4 uStackX_c;
  ulong local_res10 [2];
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined1 local_48 [32];
  
  p_Var1 = *(_PDO_EXTENSION **)(param_1 + 0x40);
  *(undefined4 *)(p_Var1 + 0x3c) = *(undefined4 *)(p_Var1 + 0x38);
  *(undefined4 *)(p_Var1 + 0x38) = 1;
  *(undefined4 *)(p_Var1 + 0x48) = 1;
  PoSetPowerState(param_1,1,1);
  if ((*(uint *)(*(longlong *)(p_Var1 + 0x30) + 0x34) & 1) != 0) {
    *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) | 1;
  }
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  KeInitializeEvent(local_48,1,0);
  lVar4 = IoBuildDeviceIoControlRequest
                    (0x41018,*(undefined8 *)(p_Var1 + 0x30),0,0,p_Var1 + 0x90,8,0,local_48,&local_58
                    );
  if (lVar4 != 0) {
    iVar2 = IofCallDriver(*(undefined8 *)(p_Var1 + 0x30),lVar4);
    if (iVar2 == 0x103) {
      KeWaitForSingleObject(local_48,0,0,0,0);
    }
  }
  local_res8 = 4;
  iVar2 = IoOpenDeviceRegistryKey(*(undefined8 *)(p_Var1 + 8),1,0x80000000,local_res10);
  if (-1 < iVar2) {
    lVar3 = GetHWParameter((_DEVICE_OBJECT *)&SPINDEL_CONTROL_FLAGS,(ushort *)(p_Var1 + 0xa0),
                           &local_res8,local_res10);
    if (-1 < lVar3) goto LAB_1c0006eb6;
  }
  *(ulong *)(p_Var1 + 0xa0) = SpindelControlFlags;
LAB_1c0006eb6:
  local_res8 = 4;
  iVar2 = IoOpenDeviceRegistryKey(*(undefined8 *)(p_Var1 + 8),1,0x80000000,local_res10);
  if (-1 < iVar2) {
    GetHWParameter((_DEVICE_OBJECT *)SPINDEL_POWER_FLAGS,(ushort *)(p_Var1 + 0xa4),&local_res8,
                   local_res10);
  }
  IoPdo(p_Var1,1,(ulong *)(p_Var1 + 0xa4));
  local_res8 = 4;
  iVar2 = IoOpenDeviceRegistryKey(*(undefined8 *)(p_Var1 + 8),1,0x80000000,local_res10);
  if (-1 < iVar2) {
    lVar3 = GetHWParameter((_DEVICE_OBJECT *)SPINDEL_FUA_FLAGS,(ushort *)(p_Var1 + 0xa8),&local_res8
                           ,local_res10);
    if (-1 < lVar3) {
      IoPdo(p_Var1,2,(ulong *)(p_Var1 + 0xa8));
    }
  }
  if (*(longlong *)(p_Var1 + 0x80) == 0) {
    PoRegisterPowerSettingCallback
              (param_1,&GUID_POWERSCHEME_PERSONALITY,PowerSettingCallback,p_Var1,p_Var1 + 0x80);
  }
  if (*(longlong *)(p_Var1 + 0x88) == 0) {
    PoRegisterPowerSettingCallback
              (param_1,&GUID_SATA_AHCI_LPM,PowerSettingCallback,p_Var1,p_Var1 + 0x88);
  }
  p_Var5 = (_SRB_IO_CONTROL *)ExAllocatePoolWithTag(0x200,0x22d,0x61744158);
  local_res8 = 0x22d;
  if (p_Var5 != (_SRB_IO_CONTROL *)0x0) {
    *(undefined4 *)p_Var5 = 0x1c;
    memcpy(p_Var5 + 4,"SCSIDISK",8);
    *(undefined4 *)(p_Var5 + 0xc) = 10;
    *(undefined4 *)(p_Var5 + 0x18) = 0x211;
    *(undefined4 *)(p_Var5 + 0x10) = 0x1b0501;
    memset(p_Var5 + 0x1c,0,0x21);
    p_Var5[0x26] = (_SRB_IO_CONTROL)0xff;
    lVar3 = SynchroIoctl(p_Var1,p_Var5,&local_res8);
    if ((lVar3 == 0) && (*(int *)(p_Var5 + 0x14) == 0)) {
      *(undefined4 *)(p_Var1 + 0x2ac) = 1;
      memcpy(p_Var1 + 0xac,p_Var5 + 0x2c,0x200);
      iVar2 = IoOpenDeviceRegistryKey(*(undefined8 *)(p_Var1 + 8),1,0x40000000,&local_res8);
      if (-1 < iVar2) {
        RtlInitUnicodeString(&local_58,L"SATA");
        ZwSetValueKey(CONCAT44(uStackX_c,local_res8),&local_58,0,3,p_Var1 + 0x144,8);
        ZwClose(CONCAT44(uStackX_c,local_res8));
      }
    }
    ExFreePoolWithTag(p_Var5,0x61744158);
  }
  IoReleaseRemoveLockEx(p_Var1 + 0x50,param_2,0x20);
                    /* WARNING: Could not recover jumptable at 0x0001c00070e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IofCompleteRequest(param_2,0);
  return;
}



===== FilterUnload @ 1c00070f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FilterUnload(struct _DRIVER_OBJECT * __ptr64) */

void __cdecl FilterUnload(_DRIVER_OBJECT *param_1)

{
  undefined *puVar1;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc);
    }
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      puVar1 = WPP_GLOBAL_Control;
      if (WPPTraceSuite == 4) {
        for (; puVar1 != (undefined *)0x0; puVar1 = *(undefined **)(puVar1 + 0x10)) {
          if (*(longlong *)(puVar1 + 0x38) != 0) {
            (*pfnEtwUnregister)();
          }
        }
      }
      else if (WPPTraceSuite == 2) {
        IoWMIRegistrationControl(WPP_GLOBAL_Control,0x80000002);
      }
      WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
    }
  }
  return;
}



===== SynchroIoctl @ 1c0007188 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl SynchroIoctl(struct _PDO_EXTENSION * __ptr64,struct _SRB_IO_CONTROL *
   __ptr64,unsigned long * __ptr64) */

long __cdecl SynchroIoctl(_PDO_EXTENSION *param_1,_SRB_IO_CONTROL *param_2,ulong *param_3)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined1 auStack_108 [32];
  undefined8 *local_e8;
  undefined1 *local_e0;
  undefined8 *local_d8;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined1 local_b0 [24];
  undefined2 local_98;
  undefined1 local_96 [3];
  _PDO_EXTENSION local_93;
  _PDO_EXTENSION local_92;
  _PDO_EXTENSION local_91;
  undefined2 local_90;
  undefined4 local_8c;
  ulong local_88;
  undefined4 local_84;
  _SRB_IO_CONTROL *local_80;
  longlong local_68;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_108;
  local_c8 = 0;
  local_98 = 0;
  local_c0 = 0;
  memset(local_96,0,0x56);
  if (param_2 == (_SRB_IO_CONTROL *)0x0) {
    iVar2 = -0x3fffff10;
  }
  else {
    KeInitializeEvent(local_b0,0,0);
    local_d8 = &local_c8;
    local_e0 = local_b0;
    local_b8 = 1;
    local_e8 = &local_b8;
    lVar3 = IoBuildSynchronousFsdRequest(0xf,*(undefined8 *)(param_1 + 0x30),param_2,*param_3);
    if (lVar3 == 0) {
      iVar2 = -0x3fffff66;
    }
    else {
      lVar1 = *(longlong *)(lVar3 + 0xb8);
      *(undefined2 *)(lVar1 + -0x48) = 0x10f;
      *(undefined2 **)(lVar1 + -0x40) = &local_98;
      local_93 = param_1[0x95];
      local_92 = param_1[0x96];
      local_91 = param_1[0x97];
      local_98 = 0x58;
      local_84 = *(undefined4 *)(param_2 + 0xc);
      local_88 = *param_3;
      local_96[0] = 2;
      local_8c = 0x140;
      local_90 = 0x20ff;
      local_80 = param_2;
      local_68 = lVar3;
      KeFlushIoBuffers(*(undefined8 *)(lVar3 + 8),0,1);
      iVar2 = IofCallDriver(*(undefined8 *)(param_1 + 0x30),lVar3);
      if (iVar2 == 0x103) {
        local_e8 = (undefined8 *)0x0;
        KeWaitForSingleObject(local_b0,0,0,0);
        iVar2 = (int)local_c8;
      }
      if (iVar2 == 0) {
        *param_3 = local_88;
      }
    }
  }
  return iVar2;
}



===== StartStopUnitAsync @ 1c000730c =====

/* long __cdecl StartStopUnitAsync(struct _PDO_EXTENSION * __ptr64,unsigned char,unsigned char,long
   (__cdecl*)(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64,void * __ptr64)) */

long __cdecl
StartStopUnitAsync(_PDO_EXTENSION *param_1,uchar param_2,uchar param_3,
                  _func_long__DEVICE_OBJECT_ptr__IRP_ptr_void_ptr *param_4)

{
  longlong lVar1;
  int iVar2;
  long lVar3;
  longlong lVar4;
  undefined2 *_Dst;
  
  iVar2 = IoAcquireRemoveLockEx(param_1 + 0x50,param_1,&s_,1,0x20);
  if (iVar2 < 0) {
    return iVar2;
  }
  lVar4 = IoAllocateIrp(*(undefined1 *)(*(longlong *)(param_1 + 0x10) + 0x4c),0);
  _Dst = (undefined2 *)ExAllocatePoolWithTag(0x200,0x58,0x61744158);
  if (lVar4 == 0) {
    if (_Dst == (undefined2 *)0x0) goto LAB_1c0007466;
    ExFreePoolWithTag(_Dst,0x61744158);
  }
  else if (_Dst != (undefined2 *)0x0) {
    *(longlong *)(lVar4 + 0xb8) = *(longlong *)(lVar4 + 0xb8) + -0x48;
    *(char *)(lVar4 + 0x43) = *(char *)(lVar4 + 0x43) + -1;
    *(undefined4 *)(lVar4 + 0x30) = 0xc00000bb;
    *(undefined8 *)(*(longlong *)(lVar4 + 0xb8) + 0x28) = *(undefined8 *)(param_1 + 0x10);
    lVar1 = *(longlong *)(lVar4 + 0xb8);
    *(undefined2 *)(lVar1 + -0x48) = 0x10f;
    memset(_Dst,0,0x58);
    *(undefined2 **)(lVar1 + -0x40) = _Dst;
    *(_PDO_EXTENSION *)((longlong)_Dst + 5) = param_1[0x95];
    *(_PDO_EXTENSION *)(_Dst + 3) = param_1[0x96];
    *(_PDO_EXTENSION *)((longlong)_Dst + 7) = param_1[0x97];
    *(undefined1 *)(_Dst + 1) = 0;
    *_Dst = 0x58;
    *(undefined4 *)(_Dst + 6) = 0x128;
    _Dst[4] = 0x20ff;
    *(longlong *)(_Dst + 0x18) = lVar4;
    *(undefined4 *)(_Dst + 10) = 0x1e;
    *(undefined1 *)(_Dst + 5) = 6;
    *(byte *)((longlong)_Dst + 0x49) = *(byte *)((longlong)_Dst + 0x49) | 1;
    *(byte *)(_Dst + 0x26) = *(byte *)(_Dst + 0x26) & 0xfc;
    *(undefined1 *)(_Dst + 0x24) = 0x1b;
    lVar1 = *(longlong *)(lVar4 + 0xb8);
    *(code **)(lVar1 + -0x10) = SrbAsyncCompletion;
    *(undefined2 **)(lVar1 + -8) = _Dst;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    lVar3 = IofCallDriver(*(undefined8 *)(param_1 + 0x30),lVar4);
    return lVar3;
  }
  if (lVar4 != 0) {
    IoFreeIrp(lVar4);
  }
LAB_1c0007466:
  IoReleaseRemoveLockEx(param_1 + 0x50,param_1,0x20);
  return -0x3fffff66;
}



===== PowerSettingCallback @ 1c00074a0 =====

/* long __cdecl PowerSettingCallback(struct _GUID const * __ptr64,void * __ptr64,unsigned long,void
   * __ptr64) */

long __cdecl PowerSettingCallback(_GUID *param_1,void *param_2,ulong param_3,void *param_4)

{
  _SRB_IO_CONTROL *p_Var1;
  undefined4 uVar2;
  ulong local_res20 [2];
  
  if ((*(longlong *)param_1 == 0x449ca2a10b2d69d7) &&
     (*(longlong *)(param_1 + 8) == 0x601c52701cf98096)) {
    uVar2 = 0x1b0779;
  }
  else {
    if (*(longlong *)param_1 != 0x44223943245d8541) {
      return 0;
    }
    if (*(longlong *)(param_1 + 8) != -0x4886097b58ecda50) {
      return 0;
    }
    uVar2 = 0x1b0778;
  }
  if ((param_2 == (void *)0x0) || (param_3 == 0)) {
    return -0x3fffffdd;
  }
  local_res20[0] = param_3 + 0x1c;
  p_Var1 = (_SRB_IO_CONTROL *)ExAllocatePoolWithTag(0x200,local_res20[0],0x61744158);
  if (p_Var1 == (_SRB_IO_CONTROL *)0x0) {
    return -0x3fffff66;
  }
  *(undefined8 *)p_Var1 = 0;
  *(undefined8 *)(p_Var1 + 8) = 0;
  *(undefined8 *)(p_Var1 + 0x10) = 0;
  *(undefined4 *)(p_Var1 + 0x18) = 0;
  *(undefined4 *)p_Var1 = 0x1c;
  memcpy(p_Var1 + 4,"SCSIDISK",8);
  *(undefined4 *)(p_Var1 + 0xc) = 0x2d;
  *(ulong *)(p_Var1 + 0x18) = param_3;
  *(undefined4 *)(p_Var1 + 0x10) = uVar2;
  memcpy(p_Var1 + 0x1c,param_2,(ulonglong)param_3);
  SynchroIoctl(param_4,p_Var1,local_res20);
  ExFreePoolWithTag(p_Var1,0x61744158);
  return 0;
}



===== IoPdo @ 1c00075bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl IoPdo(struct _PDO_EXTENSION * __ptr64,unsigned long,unsigned long * __ptr64) */

long __cdecl IoPdo(_PDO_EXTENSION *param_1,ulong param_2,ulong *param_3)

{
  long lVar1;
  undefined1 auStack_68 [32];
  ulong local_48 [2];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  ulong local_24;
  ulong local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_20 = *param_3;
  local_2c = 0;
  local_28 = 0;
  local_40 = 0x1c;
  local_3c = 0x49534353;
  local_38 = 0x4b534944;
  local_34 = 10;
  local_30 = 0x1b0789;
  local_48[0] = 0x24;
  local_24 = param_2;
  lVar1 = SynchroIoctl(param_1,(_SRB_IO_CONTROL *)&local_40,local_48);
  if ((lVar1 == 0) && (local_2c == 0)) {
    *param_3 = local_20;
  }
  return lVar1;
}



===== GetRegistryKeyValue @ 1c000764c =====

/* long __cdecl GetRegistryKeyValue(void * __ptr64,struct _UNICODE_STRING * __ptr64,unsigned
   long,void * __ptr64,unsigned long * __ptr64) */

long __cdecl
GetRegistryKeyValue(void *param_1,_UNICODE_STRING *param_2,ulong param_3,void *param_4,
                   ulong *param_5)

{
  ulong *puVar1;
  int iVar2;
  longlong lVar3;
  
  puVar1 = param_5;
  iVar2 = -0x3fffff66;
  param_5._0_4_ = (uint)*(ushort *)param_2 + *param_5 + 0x18;
  lVar3 = ExAllocatePoolWithTag(1,(int)param_5,0x61744158);
  if (lVar3 != 0) {
    iVar2 = ZwQueryValueKey(param_1,param_2,1,lVar3,(int)param_5,&param_5);
    if ((-1 < iVar2) && (param_3 == *(ulong *)(lVar3 + 4))) {
      memcpy(param_4,(void *)((ulonglong)*(uint *)(lVar3 + 8) + lVar3),
             (ulonglong)*(uint *)(lVar3 + 0xc));
    }
    *puVar1 = *(ulong *)(lVar3 + 0xc);
    ExFreePoolWithTag(lVar3,0x61744158);
  }
  return iVar2;
}



===== GetHWParameter @ 1c0007724 =====

/* long __cdecl GetHWParameter(struct _DEVICE_OBJECT * __ptr64,unsigned short * __ptr64,void *
   __ptr64,unsigned long * __ptr64) */

long __cdecl GetHWParameter(_DEVICE_OBJECT *param_1,ushort *param_2,void *param_3,ulong *param_4)

{
  long lVar1;
  _UNICODE_STRING local_18 [16];
  
  RtlInitUnicodeString(local_18,param_1);
  lVar1 = GetRegistryKeyValue(*(void **)param_4,local_18,4 - (*(int *)param_3 != 4),param_2,param_3)
  ;
  ZwClose(*(undefined8 *)param_4);
  return lVar1;
}



===== DriverEntry @ 1c0008000 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DriverEntry(longlong param_1)

{
  code *pcVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined1 auStack_178 [32];
  undefined8 local_158;
  undefined1 local_148 [16];
  undefined8 local_138;
  undefined4 local_130 [2];
  ushort **local_128;
  ulong *local_120;
  undefined4 local_118;
  ulong *local_110;
  undefined4 local_108;
  undefined8 local_100;
  undefined4 local_f8;
  wchar_t *local_f0;
  ulong *local_e8;
  undefined4 local_e0;
  ulong *local_d8;
  undefined4 local_d0;
  undefined8 local_c8;
  undefined4 local_c0;
  wchar_t *local_b8;
  ulong *local_b0;
  undefined4 local_a8;
  ulong *local_a0;
  undefined4 local_98;
  undefined8 local_90;
  undefined4 local_88;
  wchar_t *local_80;
  uchar *local_78;
  undefined4 local_70;
  uchar *local_68;
  undefined4 local_60;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_178;
  memset(local_130,0,0x110);
  puVar3 = (undefined8 *)(param_1 + 0x70);
  for (lVar2 = 0x1c; lVar2 != 0; lVar2 = lVar2 + -1) {
    *puVar3 = FilterPass;
    puVar3 = puVar3 + 1;
  }
  *(code **)(param_1 + 0x148) = FilterDispatchPnp;
  *(code **)(param_1 + 0x120) = FilterDispatchPower;
  *(code **)(*(longlong *)(param_1 + 0x30) + 8) = FilterAddDevice;
  local_130[0] = 0x20;
  *(code **)(param_1 + 0x68) = FilterUnload;
  *(code **)(param_1 + 0xe8) = FilterSCSI;
  *(code **)(param_1 + 0xe0) = FilterDispatchIo;
  local_120 = &SpindelControlFlags;
  local_f8 = 0x20;
  local_128 = &SPINDEL_CONTROL_FLAGS;
  local_110 = &DefaultSpindelControlFlags;
  local_e8 = &SpindelPowerFlags;
  local_f0 = SPINDEL_POWER_FLAGS;
  local_d8 = &DefaultSpindelPowerFlags;
  local_b0 = &SpindelFuaFlags;
  local_b8 = SPINDEL_FUA_FLAGS;
  local_a0 = &DefaultSpindelFuaFlags;
  local_78 = &XataOption;
  local_80 = XATA_OPTION;
  local_c0 = 0x20;
  local_88 = 0x20;
  local_68 = &XataOptionDefault;
  local_138 = 0;
  local_118 = 4;
  local_108 = 4;
  local_100 = 0;
  local_e0 = 4;
  local_d0 = 4;
  local_c8 = 0;
  local_a8 = 4;
  local_98 = 4;
  local_90 = 0;
  local_70 = 4;
  local_60 = 1;
  RtlInitUnicodeString(local_148,L"RtlQueryRegistryValuesEx");
  pcVar1 = (code *)MmGetSystemRoutineAddress(local_148);
  local_158 = 0;
  if (pcVar1 == (code *)0x0) {
    pcVar1 = RtlQueryRegistryValues_exref;
  }
  (*pcVar1)(0x80000001,L"amdxata\\Parameters",&local_138,0);
  _WPP_MAIN_CB = 0;
  DAT_1c0003108 = &WPP_ThisDir_CTLGUID_wppCtlGuid;
  DAT_1c0003110 = 0;
  _DAT_1c0003120 = 0;
  _DAT_1c0003128 = 1;
  WppLoadTracingSupport();
  _DAT_1c0003120 = 0;
  WppInitKm();
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10);
  }
  return 0;
}



===== entry @ 1c0008240 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 1c0008258 =====

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


