
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
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0xf7,_StackCookie,__security_cookie,__security_cookie_complement,0);
}



===== __C_specific_handler @ 1c00010f3 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001c00010f3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== ~GenericLocker<WaitableReferenceCounter> @ 1c0001108 =====

/* public: __cdecl GenericLocker<class WaitableReferenceCounter>::~GenericLocker<class
   WaitableReferenceCounter>(void) __ptr64 */

void __thiscall
GenericLocker<WaitableReferenceCounter>::~GenericLocker<WaitableReferenceCounter>
          (GenericLocker<WaitableReferenceCounter> *this)

{
  int *piVar1;
  undefined1 uVar2;
  
  piVar1 = *(int **)this;
  uVar2 = KeAcquireSpinLockRaiseToDpc(piVar1 + 8);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    KeSetEvent(piVar1 + 2,0,0);
  }
  KeReleaseSpinLock(piVar1 + 8,uVar2);
  return;
}



===== DriverUnload @ 1c0001180 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl DriverUnload(struct _DRIVER_OBJECT * __ptr64) */

void __cdecl DriverUnload(_DRIVER_OBJECT *param_1)

{
  undefined8 *puVar1;
  
  PsSetCreateProcessNotifyRoutine(ProcessCreationNotifyRoutine,1);
  puVar1 = DAT_1c0008360;
  DAT_1c0008360 = (undefined8 *)0x0;
  if ((DAT_1c0008358 != (int *)0x0) && (*DAT_1c0008358 != 0)) {
    KeWaitForSingleObject(DAT_1c0008358 + 2,0,0,0,0);
  }
  if (puVar1 != (undefined8 *)0x0) {
    (**(code **)*puVar1)(puVar1,1);
  }
  if (DAT_1c0008358 != (int *)0x0) {
    ExFreePoolWithTag(DAT_1c0008358,0x4a424f50);
  }
  DAT_1c0008358 = (int *)0x0;
  return;
}



===== ProcessCreationNotifyRoutine @ 1c0001230 =====

void ProcessCreationNotifyRoutine(ulong param_1,ulong param_2,char param_3)

{
  int *piVar1;
  undefined1 uVar2;
  int *local_res20;
  
  piVar1 = DAT_1c0008358;
  local_res20 = DAT_1c0008358;
  uVar2 = KeAcquireSpinLockRaiseToDpc(DAT_1c0008358 + 8);
  *piVar1 = *piVar1 + 1;
  KeResetEvent(piVar1 + 2);
  KeReleaseSpinLock(piVar1 + 8,uVar2);
  if (DAT_1c0008360 != (ProcessLaunchMonitorDevice *)0x0) {
    ProcessLaunchMonitorDevice::HandleProcessCreatedOrDestroyed
              (DAT_1c0008360,param_3 != '\0',param_1,param_2);
  }
  GenericLocker<WaitableReferenceCounter>::~GenericLocker<WaitableReferenceCounter>
            ((GenericLocker<WaitableReferenceCounter> *)&local_res20);
  return;
}



===== DriverEntry @ 1c00012dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DriverEntry(_DRIVER_OBJECT *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  ProcessLaunchMonitorDevice *this;
  code *pcVar3;
  undefined1 auStack_48 [32];
  undefined4 local_28;
  undefined2 local_24;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_48;
  puVar2 = (undefined4 *)ExAllocatePoolWithTag(0,0x28,0x4a424f50);
  if (puVar2 == (undefined4 *)0x0) {
    DAT_1c0008358 = (undefined4 *)0x0;
  }
  else {
    KeInitializeEvent(puVar2 + 2,0,0);
    *(undefined8 *)(puVar2 + 8) = 0;
    *puVar2 = 0;
    DAT_1c0008358 = puVar2;
    this = (ProcessLaunchMonitorDevice *)ExAllocatePoolWithTag(1,0x38,0x4a424f50);
    if (this == (ProcessLaunchMonitorDevice *)0x0) {
      DAT_1c0008360 = (undefined8 *)0x0;
    }
    else {
      DAT_1c0008360 =
           (undefined8 *)ProcessLaunchMonitorDevice::ProcessLaunchMonitorDevice(this,param_1);
      if (DAT_1c0008360 != (undefined8 *)0x0) {
        iVar1 = *(int *)(DAT_1c0008360 + 2);
        if (iVar1 < 0) {
          pcVar3 = *(code **)*DAT_1c0008360;
        }
        else {
          iVar1 = PsSetCreateProcessNotifyRoutine(ProcessCreationNotifyRoutine,0);
          if (-1 < iVar1) {
            local_28 = 0;
            *(code **)(param_1 + 0x68) = DriverUnload;
            local_24 = 0x500;
            iVar1 = RtlInitializeSid(&g_sidBuffer,&local_28,6);
            if (-1 < iVar1) {
              puVar2 = (undefined4 *)RtlSubAuthoritySid(&g_sidBuffer,0);
              *puVar2 = 0x50;
              puVar2 = (undefined4 *)RtlSubAuthoritySid(&g_sidBuffer,1);
              *puVar2 = 0xc4affe30;
              puVar2 = (undefined4 *)RtlSubAuthoritySid(&g_sidBuffer,2);
              *puVar2 = 0xff7c0be9;
              puVar2 = (undefined4 *)RtlSubAuthoritySid(&g_sidBuffer,3);
              *puVar2 = 0x41097c0c;
              puVar2 = (undefined4 *)RtlSubAuthoritySid(&g_sidBuffer,4);
              *puVar2 = 0xd59bb71f;
              puVar2 = (undefined4 *)RtlSubAuthoritySid(&g_sidBuffer,5);
              *puVar2 = 0x674300dc;
              return 0;
            }
          }
          if (DAT_1c0008360 == (undefined8 *)0x0) goto LAB_1c00013a3;
          pcVar3 = *(code **)*DAT_1c0008360;
        }
        (*pcVar3)(DAT_1c0008360,1);
LAB_1c00013a3:
        if (DAT_1c0008358 != (undefined4 *)0x0) {
          ExFreePoolWithTag(DAT_1c0008358,0x4a424f50);
        }
        DAT_1c0008360 = (undefined8 *)0x0;
        return iVar1;
      }
    }
    if (DAT_1c0008358 != (undefined4 *)0x0) {
      ExFreePoolWithTag(DAT_1c0008358,0x4a424f50);
    }
  }
  return -0x3fffffe9;
}



===== TryGetRegistryValueFor<unsigned_long> @ 1c0001528 =====

/* long __cdecl TTD::TryGetRegistryValueFor<unsigned long>(void * __ptr64,unsigned short const *
   __ptr64 const,unsigned long * __ptr64) */

long __cdecl
TTD::TryGetRegistryValueFor<unsigned_long>(void *param_1,ushort *param_2,ulong *param_3)

{
  int iVar1;
  longlong lVar2;
  int local_res18 [2];
  int local_res20 [2];
  undefined8 local_28;
  undefined8 uStack_20;
  
  *param_3 = 0;
  local_28 = 0;
  uStack_20 = 0;
  RtlInitUnicodeString(&local_28);
  local_res18[0] = 0;
  iVar1 = ZwQueryValueKey(param_1,&local_28,1,0,0,local_res18);
  if ((iVar1 == -0x3fffffdd) || (iVar1 == -0x7ffffffb)) {
    lVar2 = ExAllocatePoolWithTag(0,local_res18[0],0x44495744);
    if (lVar2 == 0) {
      iVar1 = -0x3fffffe9;
    }
    else {
      local_res20[0] = 0;
      iVar1 = ZwQueryValueKey(param_1,&local_28,1,lVar2,local_res18[0],local_res20);
      if ((iVar1 < 0) || (local_res18[0] != local_res20[0])) {
        ExFreePoolWithTag(lVar2,0);
      }
      else if (*(int *)(lVar2 + 0xc) == 4) {
        *param_3 = *(ulong *)((ulonglong)*(uint *)(lVar2 + 8) + lVar2);
        ExFreePoolWithTag(lVar2,0);
        iVar1 = 0;
      }
      else {
        ExFreePoolWithTag(lVar2);
        iVar1 = -0x3ffff6f5;
      }
    }
  }
  return iVar1;
}



===== ProcessLaunchMonitorClient @ 1c0001660 =====

/* public: __cdecl ProcessLaunchMonitorClient::ProcessLaunchMonitorClient(long,struct _DEVICE_OBJECT
   * __ptr64,long * __ptr64) __ptr64 */

ProcessLaunchMonitorClient * __thiscall
ProcessLaunchMonitorClient::ProcessLaunchMonitorClient
          (ProcessLaunchMonitorClient *this,long param_1,_DEVICE_OBJECT *param_2,long *param_3)

{
  ProcessLaunchMonitorClient *pPVar1;
  ProcessLaunchMonitorClient *pPVar2;
  ProcessLaunchMonitorClient *pPVar3;
  void *pvVar4;
  int iVar5;
  long lVar6;
  uint uVar7;
  uint uVar8;
  int local_res8 [2];
  ulong local_res10 [2];
  ulong local_res18 [2];
  ulonglong local_res20;
  ulonglong in_stack_ffffffffffffff58;
  void *local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 *local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  
  *(undefined4 *)this = 3;
  pPVar1 = this + 0x28;
  *(ProcessLaunchMonitorClient **)(this + 0x30) = pPVar1;
  pPVar2 = this + 8;
  this[0x20] = (ProcessLaunchMonitorClient)0x0;
  *(undefined8 *)(this + 0x18) = 0;
  pPVar3 = this + 0x50;
  *(ProcessLaunchMonitorClient **)(this + 0x10) = pPVar2;
  *(ProcessLaunchMonitorClient **)pPVar2 = pPVar2;
  *(ProcessLaunchMonitorClient **)pPVar1 = pPVar1;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)pPVar3 = 0;
  local_80 = 0x30;
  local_68 = 0x200;
  local_78 = 0;
  local_70 = (undefined8 *)0x0;
  local_60 = 0;
  uStack_58 = 0;
  local_res10[0] = param_1;
  iVar5 = ZwCreateEvent(pPVar3,0x1f0003,&local_80,0,in_stack_ffffffffffffff58 & 0xffffffffffffff00);
  *param_3 = iVar5;
  if (-1 < iVar5) {
    lVar6 = ObReferenceObjectByHandle
                      (*(undefined8 *)pPVar3,0x1f0003,*(undefined8 *)ExEventObjectType_exref,0,
                       this + 0x48,0);
    *param_3 = lVar6;
  }
  *(undefined8 *)(this + 0x58) = 0;
  pPVar1 = this + 0x88;
  *(undefined8 *)(this + 0x60) = 200;
  *(ProcessLaunchMonitorClient **)(this + 0x90) = pPVar1;
  *(ProcessLaunchMonitorClient **)pPVar1 = pPVar1;
  this[0x78] = (ProcessLaunchMonitorClient)0x0;
  *(undefined8 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x7c) = 1;
  *(undefined4 *)(this + 0x120) = 2000;
  *(_DEVICE_OBJECT **)(this + 0x128) = param_2;
  KeInitializeTimer(this + 0xa0);
  KeInitializeDpc(this + 0xe0,QueueHealthTimerSignaledDpc,this);
  LOCK();
  if (DAT_1c000836c == 1) {
    DAT_1c000836c = 1;
  }
  UNLOCK();
  if (DAT_1c000836c == 0) {
    local_90 = 0;
    uStack_88 = 0;
    RtlInitUnicodeString(&local_90,L"\\Registry\\Machine\\Software\\Microsoft\\TTD");
    local_70 = &local_90;
    local_80 = 0x30;
    local_68 = 0x240;
    local_78 = 0;
    local_98 = (void *)0x0;
    local_60 = 0;
    uStack_58 = 0;
    iVar5 = ZwOpenKey(&local_98,0x20019,&local_80);
    pvVar4 = local_98;
    if (iVar5 < 0) {
      return this;
    }
    local_res10[0] = 0;
    TTD::TryGetRegistryValueFor<unsigned_long>(local_98,(ushort *)L"RecordingPolicy",local_res10);
    if (local_res10[0] != 2) {
      *(undefined4 *)(this + 0x120) = 2000;
      local_res20 = 8;
      local_res8[0] = 0;
      uVar8 = 4000;
      uVar7 = ZwQuerySystemInformation(0x67,&local_res20,8,local_res8);
      if ((((uVar7 & 0xc0000000) != 0xc0000000) && (local_res8[0] == 8)) &&
         ((local_res20 & 0x200000000) != 0)) {
        *(undefined4 *)(this + 0x120) = 2000;
        uVar8 = 300000;
      }
      local_res18[0] = 0;
      TTD::TryGetRegistryValueFor<unsigned_long>
                (pvVar4,(ushort *)L"ProcessMonitoringTimeoutInMs",local_res18);
      local_res10[0] = 0;
      TTD::TryGetRegistryValueFor<unsigned_long>
                (pvVar4,(ushort *)L"AllowWerSvcRecording",local_res10);
      g_allowWerService = local_res10[0] != 0;
      if ((99 < local_res18[0]) && (local_res18[0] <= uVar8)) {
        *(ulong *)(this + 0x120) = local_res18[0];
      }
      ZwClose(pvVar4);
      return this;
    }
    ZwClose(pvVar4);
    *param_3 = -0x3ffffc9f;
  }
  else {
    *param_3 = -0x3ffffe7c;
  }
  *(undefined4 *)this = 3;
  return this;
}



===== ~NTList<ProcessLaunchMonitorClient*___ptr64,0,SpinLock> @ 1c000193c =====

/* public: __cdecl NTList<class ProcessLaunchMonitorClient * __ptr64,0,class
   SpinLock>::~NTList<class ProcessLaunchMonitorClient * __ptr64,0,class SpinLock>(void) __ptr64 */

void __thiscall
NTList<ProcessLaunchMonitorClient*___ptr64,0,SpinLock>::
~NTList<ProcessLaunchMonitorClient*___ptr64,0,SpinLock>
          (NTList<ProcessLaunchMonitorClient*___ptr64,0,SpinLock> *this)

{
  NTList<ProcessLaunchMonitorClient*___ptr64,0,SpinLock> *pNVar1;
  longlong *plVar2;
  code *pcVar3;
  NTList<ProcessLaunchMonitorClient*___ptr64,0,SpinLock> *pNVar4;
  undefined1 uVar5;
  
  uVar5 = KeAcquireSpinLockRaiseToDpc(this + 0x10);
  pNVar4 = *(NTList<ProcessLaunchMonitorClient*___ptr64,0,SpinLock> **)this;
  while( true ) {
    if ((pNVar4 == (NTList<ProcessLaunchMonitorClient*___ptr64,0,SpinLock> *)0x0) ||
       (pNVar4 == this)) {
      KeReleaseSpinLock(this + 0x10,uVar5);
      return;
    }
    pNVar1 = *(NTList<ProcessLaunchMonitorClient*___ptr64,0,SpinLock> **)pNVar4;
    if ((*(NTList<ProcessLaunchMonitorClient*___ptr64,0,SpinLock> **)(pNVar1 + 8) != pNVar4) ||
       (plVar2 = *(longlong **)(pNVar4 + 8),
       (NTList<ProcessLaunchMonitorClient*___ptr64,0,SpinLock> *)*plVar2 != pNVar4)) break;
    *plVar2 = (longlong)pNVar1;
    *(longlong **)(pNVar1 + 8) = plVar2;
    ExFreePoolWithTag(pNVar4,0x4a424f50);
    pNVar4 = pNVar1;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== ~NTQueueWithExportableWaitHandle<ProcessLaunchMonitorEventTimestamp> @ 1c00019dc =====

/* public: __cdecl NTQueueWithExportableWaitHandle<struct
   ProcessLaunchMonitorEventTimestamp>::~NTQueueWithExportableWaitHandle<struct
   ProcessLaunchMonitorEventTimestamp>(void) __ptr64 */

void __thiscall
NTQueueWithExportableWaitHandle<ProcessLaunchMonitorEventTimestamp>::
~NTQueueWithExportableWaitHandle<ProcessLaunchMonitorEventTimestamp>
          (NTQueueWithExportableWaitHandle<ProcessLaunchMonitorEventTimestamp> *this)

{
  NTQueueWithExportableWaitHandle<ProcessLaunchMonitorEventTimestamp> *pNVar1;
  longlong *plVar2;
  code *pcVar3;
  NTQueueWithExportableWaitHandle<ProcessLaunchMonitorEventTimestamp> *pNVar4;
  
  if (*(longlong *)(this + 0x20) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(this + 0x20) = 0;
  }
  if (*(longlong *)(this + 0x28) != 0) {
    ZwClose();
    *(undefined8 *)(this + 0x28) = 0;
  }
  pNVar4 = *(NTQueueWithExportableWaitHandle<ProcessLaunchMonitorEventTimestamp> **)this;
  while( true ) {
    if ((pNVar4 == (NTQueueWithExportableWaitHandle<ProcessLaunchMonitorEventTimestamp> *)0x0) ||
       (pNVar4 == this)) {
      return;
    }
    pNVar1 = *(NTQueueWithExportableWaitHandle<ProcessLaunchMonitorEventTimestamp> **)pNVar4;
    if ((*(NTQueueWithExportableWaitHandle<ProcessLaunchMonitorEventTimestamp> **)(pNVar1 + 8) !=
         pNVar4) ||
       (plVar2 = *(longlong **)(pNVar4 + 8),
       (NTQueueWithExportableWaitHandle<ProcessLaunchMonitorEventTimestamp> *)*plVar2 != pNVar4))
    break;
    *plVar2 = (longlong)pNVar1;
    *(longlong **)(pNVar1 + 8) = plVar2;
    ExFreePoolWithTag(pNVar4,0x4a424f50);
    pNVar4 = pNVar1;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== ~ProcessLaunchMonitorClient @ 1c0001a78 =====

/* private: __cdecl ProcessLaunchMonitorClient::~ProcessLaunchMonitorClient(void) __ptr64 */

void __thiscall
ProcessLaunchMonitorClient::~ProcessLaunchMonitorClient(ProcessLaunchMonitorClient *this)

{
  ProcessLaunchMonitorClient *pPVar1;
  undefined8 *puVar2;
  code *pcVar3;
  ProcessLaunchMonitorClient *pPVar4;
  
  Shutdown(this);
  pPVar4 = *(ProcessLaunchMonitorClient **)(this + 0x88);
  while( true ) {
    if ((pPVar4 == (ProcessLaunchMonitorClient *)0x0) || (pPVar4 == this + 0x88)) {
      NTQueueWithExportableWaitHandle<ProcessLaunchMonitorEventTimestamp>::
      ~NTQueueWithExportableWaitHandle<ProcessLaunchMonitorEventTimestamp>
                ((NTQueueWithExportableWaitHandle<ProcessLaunchMonitorEventTimestamp> *)
                 (this + 0x28));
      NTList<ProcessLaunchMonitorClient*___ptr64,0,SpinLock>::
      ~NTList<ProcessLaunchMonitorClient*___ptr64,0,SpinLock>
                ((NTList<ProcessLaunchMonitorClient*___ptr64,0,SpinLock> *)(this + 8));
      return;
    }
    pPVar1 = *(ProcessLaunchMonitorClient **)pPVar4;
    if ((*(ProcessLaunchMonitorClient **)(pPVar1 + 8) != pPVar4) ||
       (puVar2 = *(undefined8 **)(pPVar4 + 8), (ProcessLaunchMonitorClient *)*puVar2 != pPVar4))
    break;
    *puVar2 = pPVar1;
    *(undefined8 **)(pPVar1 + 8) = puVar2;
    ExFreePoolWithTag(pPVar4,0x4a424f50);
    pPVar4 = pPVar1;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== AddMonitoredPid @ 1c0001b08 =====

/* public: long __cdecl ProcessLaunchMonitorClient::AddMonitoredPid(unsigned long) __ptr64 */

long __thiscall
ProcessLaunchMonitorClient::AddMonitoredPid(ProcessLaunchMonitorClient *this,ulong param_1)

{
  ProcessLaunchMonitorClient *pPVar1;
  ProcessLaunchMonitorClient *pPVar2;
  ProcessLaunchMonitorClient *pPVar3;
  code *pcVar4;
  undefined1 uVar5;
  longlong *plVar6;
  undefined8 *puVar7;
  long lVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  ProcessLaunchMonitorClient *pPVar11;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  if (param_1 == 0xffffffff) {
    this[0x20] = (ProcessLaunchMonitorClient)0x1;
    KeSetTimerEx(this + 0xa0,(ulonglong)*(uint *)(this + 0x120) * -10000,
                 (ulonglong)*(uint *)(this + 0x120),this + 0xe0);
    lVar8 = 0;
  }
  else {
    pPVar1 = this + 8;
    pPVar2 = this + 0x18;
    uVar5 = KeAcquireSpinLockRaiseToDpc(pPVar2);
    pPVar11 = *(ProcessLaunchMonitorClient **)pPVar1;
    lVar8 = 0;
    if ((pPVar11 == (ProcessLaunchMonitorClient *)0x0) || (pPVar11 == pPVar1)) {
      pPVar11 = (ProcessLaunchMonitorClient *)0x0;
    }
    KeReleaseSpinLock(pPVar2,uVar5);
    if (pPVar11 == (ProcessLaunchMonitorClient *)0x0) {
      KeSetTimerEx(this + 0xa0,(ulonglong)*(uint *)(this + 0x120) * -10000,
                   (ulonglong)*(uint *)(this + 0x120),this + 0xe0);
    }
    uVar5 = KeAcquireSpinLockRaiseToDpc(pPVar2);
    pPVar11 = *(ProcessLaunchMonitorClient **)pPVar1;
    do {
      if ((pPVar11 == (ProcessLaunchMonitorClient *)0x0) || (pPVar11 == pPVar1)) {
        plVar6 = (longlong *)ExAllocatePoolWithTag(0,0x18,0x4a424f50);
        puVar10 = auStack_38;
        puVar9 = auStack_38;
        if (plVar6 == (longlong *)0x0) {
          lVar8 = -0x3fffffe9;
        }
        else {
          *(ulong *)(plVar6 + 2) = param_1;
          puVar7 = *(undefined8 **)(this + 0x10);
          if ((ProcessLaunchMonitorClient *)*puVar7 != pPVar1) {
            puVar7 = (undefined8 *)0x3;
            pcVar4 = (code *)swi(0x29);
            plVar6 = (longlong *)(*pcVar4)();
            puVar9 = auStack_30;
          }
          *plVar6 = (longlong)pPVar1;
          plVar6[1] = (longlong)puVar7;
          *puVar7 = plVar6;
          *(longlong **)(this + 0x10) = plVar6;
          puVar10 = puVar9;
        }
        break;
      }
      pPVar3 = pPVar11 + 0x10;
      puVar10 = auStack_38;
      pPVar11 = *(ProcessLaunchMonitorClient **)pPVar11;
    } while (*(ulong *)pPVar3 != param_1);
    *(undefined8 *)(puVar10 + -8) = 0x1c0001c49;
    KeReleaseSpinLock(pPVar2,uVar5);
  }
  return lVar8;
}



===== CleanupClientMonitoringWorkerRoutine @ 1c0001c70 =====

void CleanupClientMonitoringWorkerRoutine(undefined8 param_1,longlong *param_2,ErrorType param_3)

{
  LOCK();
  DAT_1c000836c = 1;
  UNLOCK();
  Telemetry::LogFeatureUsedWithResult
            ((ushort *)L"MonitoringHealth",(ushort *)L"CleanupClientTriggered",param_3,1,
             (ushort *)L"The user mode client took too long to resume the last provided process");
  if (param_2 != (longlong *)0x0) {
    if ((undefined4 *)param_2[1] != (undefined4 *)0x0) {
      LOCK();
      *(undefined4 *)param_2[1] = 3;
      UNLOCK();
      ProcessLaunchMonitorClient::Shutdown((ProcessLaunchMonitorClient *)param_2[1]);
    }
    if (*param_2 != 0) {
      IoFreeWorkItem();
    }
    ExFreePoolWithTag(param_2,0x44495744);
  }
  return;
}



===== DequeueNextEvent @ 1c0001cfc =====

/* public: long __cdecl ProcessLaunchMonitorClient::DequeueNextEvent(struct
   ProcessLaunchMonitorEventTimestamp * __ptr64) __ptr64 */

long __thiscall
ProcessLaunchMonitorClient::DequeueNextEvent
          (ProcessLaunchMonitorClient *this,ProcessLaunchMonitorEventTimestamp *param_1)

{
  ProcessLaunchMonitorClient *pPVar1;
  ProcessLaunchMonitorClient *pPVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 uVar5;
  code *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined1 uVar10;
  undefined1 *puVar11;
  int iVar12;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  if (this[0x78] != (ProcessLaunchMonitorClient)0x0) {
    return -0x3ffffdc0;
  }
  pPVar1 = this + 0x28;
  uVar10 = KeAcquireSpinLockRaiseToDpc(this + 0x40);
  pPVar2 = *(ProcessLaunchMonitorClient **)pPVar1;
  puVar11 = auStack_38;
  if ((pPVar2 != (ProcessLaunchMonitorClient *)0x0) && (puVar11 = auStack_38, pPVar2 != pPVar1)) {
    lVar3 = *(longlong *)pPVar2;
    if ((*(ProcessLaunchMonitorClient **)(lVar3 + 8) == pPVar2) &&
       (plVar4 = *(longlong **)(pPVar2 + 8), (ProcessLaunchMonitorClient *)*plVar4 == pPVar2)) {
      *plVar4 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar4;
      uVar7 = *(undefined4 *)(pPVar2 + 0x14);
      uVar8 = *(undefined4 *)(pPVar2 + 0x18);
      uVar9 = *(undefined4 *)(pPVar2 + 0x1c);
      *(undefined4 *)param_1 = *(undefined4 *)(pPVar2 + 0x10);
      *(undefined4 *)(param_1 + 4) = uVar7;
      *(undefined4 *)(param_1 + 8) = uVar8;
      *(undefined4 *)(param_1 + 0xc) = uVar9;
      ExFreePoolWithTag(pPVar2,0x4a424f50);
      puVar11 = auStack_38;
      iVar12 = 0;
      goto LAB_1c0001d99;
    }
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)(3);
    puVar11 = auStack_30;
  }
  iVar12 = -0x7fffffe6;
  *(undefined8 *)param_1 = 0;
  *(undefined8 *)(param_1 + 8) = 0;
LAB_1c0001d99:
  if ((*(ProcessLaunchMonitorClient **)pPVar1 == (ProcessLaunchMonitorClient *)0x0) ||
     (*(ProcessLaunchMonitorClient **)pPVar1 == pPVar1)) {
    uVar5 = *(undefined8 *)(this + 0x48);
    *(undefined8 *)(puVar11 + -8) = 0x1c0001db1;
    KeClearEvent(uVar5);
  }
  if (-1 < iVar12) {
    *(longlong *)(this + 0x58) = *(longlong *)(this + 0x58) + -1;
  }
  *(undefined8 *)(puVar11 + -8) = 0x1c0001dcc;
  KeReleaseSpinLock(this + 0x40,uVar10);
  uVar5 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(this + 0x68) = *(undefined8 *)param_1;
  *(undefined8 *)(this + 0x70) = uVar5;
  return iVar12;
}



===== EnqueueElement @ 1c0001dfc =====

/* public: long __cdecl NTQueueWithExportableWaitHandle<struct
   ProcessLaunchMonitorEventTimestamp>::EnqueueElement(struct ProcessLaunchMonitorEventTimestamp
   const & __ptr64) __ptr64 */

long __thiscall
NTQueueWithExportableWaitHandle<ProcessLaunchMonitorEventTimestamp>::EnqueueElement
          (NTQueueWithExportableWaitHandle<ProcessLaunchMonitorEventTimestamp> *this,
          ProcessLaunchMonitorEventTimestamp *param_1)

{
  NTQueueWithExportableWaitHandle<ProcessLaunchMonitorEventTimestamp> *pNVar1;
  undefined8 uVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 uVar7;
  undefined8 *puVar8;
  longlong *plVar9;
  long lVar10;
  undefined1 *puVar11;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  pNVar1 = this + 0x18;
  uVar7 = KeAcquireSpinLockRaiseToDpc(pNVar1);
  if (*(ulonglong *)(this + 0x30) < *(ulonglong *)(this + 0x38)) {
    puVar8 = (undefined8 *)ExAllocatePoolWithTag(0,0x20,0x4a424f50);
    puVar11 = auStack_28;
    if (puVar8 != (undefined8 *)0x0) {
      uVar4 = *(undefined4 *)(param_1 + 4);
      uVar5 = *(undefined4 *)(param_1 + 8);
      uVar6 = *(undefined4 *)(param_1 + 0xc);
      *(undefined4 *)(puVar8 + 2) = *(undefined4 *)param_1;
      *(undefined4 *)((longlong)puVar8 + 0x14) = uVar4;
      *(undefined4 *)(puVar8 + 3) = uVar5;
      *(undefined4 *)((longlong)puVar8 + 0x1c) = uVar6;
      plVar9 = *(longlong **)(this + 8);
      if ((NTQueueWithExportableWaitHandle<ProcessLaunchMonitorEventTimestamp> *)*plVar9 != this) {
        plVar9 = (longlong *)0x3;
        pcVar3 = (code *)swi(0x29);
        puVar8 = (undefined8 *)(*pcVar3)();
        puVar11 = auStack_20;
      }
      *puVar8 = this;
      puVar8[1] = plVar9;
      *plVar9 = (longlong)puVar8;
      *(undefined8 **)(this + 8) = puVar8;
      uVar2 = *(undefined8 *)(this + 0x20);
      *(longlong *)(this + 0x30) = *(longlong *)(this + 0x30) + 1;
      *(undefined8 *)(puVar11 + -8) = 0x1c0001e96;
      KeSetEvent(uVar2,0,0);
      *(undefined8 *)(puVar11 + -8) = 0x1c0001ea8;
      KeReleaseSpinLock(pNVar1,uVar7);
      return 0;
    }
    lVar10 = -0x3fffffe9;
  }
  else {
    lVar10 = -0x3fffff66;
  }
  KeReleaseSpinLock(pNVar1,uVar7);
  return lVar10;
}



===== Erase @ 1c0001ee8 =====

/* public: unsigned __int64 __cdecl NTList<unsigned long,0,class SpinLock>::Erase(unsigned long
   const & __ptr64) __ptr64 */

__uint64 __thiscall
NTList<unsigned_long,0,SpinLock>::Erase(NTList<unsigned_long,0,SpinLock> *this,ulong *param_1)

{
  NTList<unsigned_long,0,SpinLock> *pNVar1;
  longlong *plVar2;
  code *pcVar3;
  NTList<unsigned_long,0,SpinLock> *pNVar4;
  undefined1 uVar5;
  __uint64 _Var6;
  
  uVar5 = KeAcquireSpinLockRaiseToDpc(this + 0x10);
  _Var6 = 0;
  pNVar1 = *(NTList<unsigned_long,0,SpinLock> **)this;
  while( true ) {
    do {
      pNVar4 = pNVar1;
      if ((pNVar4 == (NTList<unsigned_long,0,SpinLock> *)0x0) || (pNVar4 == this)) {
        KeReleaseSpinLock(this + 0x10,uVar5);
        return _Var6;
      }
      pNVar1 = *(NTList<unsigned_long,0,SpinLock> **)pNVar4;
    } while (*(ulong *)(pNVar4 + 0x10) != *param_1);
    if ((*(NTList<unsigned_long,0,SpinLock> **)(pNVar1 + 8) != pNVar4) ||
       (plVar2 = *(longlong **)(pNVar4 + 8), (NTList<unsigned_long,0,SpinLock> *)*plVar2 != pNVar4))
    break;
    *plVar2 = (longlong)pNVar1;
    *(longlong **)(pNVar1 + 8) = plVar2;
    ExFreePoolWithTag(pNVar4,0x4a424f50);
    _Var6 = _Var6 + 1;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  _Var6 = (*pcVar3)();
  return _Var6;
}



===== GetProcessHandle @ 1c0001fa8 =====

void GetProcessHandle(ulonglong param_1,undefined8 *param_2)

{
  int iVar1;
  undefined8 local_res10 [3];
  ulonglong local_48 [2];
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  *param_2 = 0;
  local_34 = 0;
  local_1c = 0;
  local_30 = 0;
  local_28 = 0;
  local_res10[0] = 0;
  local_48[1] = 0;
  local_48[0] = param_1 & 0xffffffff;
  local_18 = 0;
  uStack_10 = 0;
  local_38 = 0x30;
  local_20 = 0x200;
  iVar1 = ZwOpenProcess(local_res10,0x1fffff,&local_38,local_48);
  if (-1 < iVar1) {
    *param_2 = local_res10[0];
  }
  return;
}



===== HandleProcessCreated @ 1c0002030 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: void __cdecl ProcessLaunchMonitorClient::HandleProcessCreated(unsigned long,unsigned
   long) __ptr64 */

void __thiscall
ProcessLaunchMonitorClient::HandleProcessCreated
          (ProcessLaunchMonitorClient *this,ulong param_1,ulong param_2)

{
  ProcessLaunchMonitorClient *pPVar1;
  ProcessLaunchMonitorClient PVar2;
  bool bVar3;
  ProcessLaunchMonitorClient *pPVar4;
  undefined1 uVar5;
  int iVar6;
  long lVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  char local_res8 [16];
  ulong local_res18 [2];
  undefined8 local_res20;
  ulong local_48;
  uint local_44;
  undefined8 local_40;
  
  LOCK();
  iVar6 = *(int *)this;
  if (iVar6 == 1) {
    *(undefined4 *)this = 1;
  }
  UNLOCK();
  if (iVar6 == 1) {
    local_res18[0] = param_2;
    if (this[0x20] == (ProcessLaunchMonitorClient)0x0) {
      uVar5 = KeAcquireSpinLockRaiseToDpc(this + 0x18);
      pPVar4 = *(ProcessLaunchMonitorClient **)(this + 8);
      do {
        if ((pPVar4 == (ProcessLaunchMonitorClient *)0x0) || (pPVar4 == this + 8)) {
          bVar3 = false;
          goto LAB_1c00020a1;
        }
        pPVar1 = pPVar4 + 0x10;
        pPVar4 = *(ProcessLaunchMonitorClient **)pPVar4;
      } while (*(ulong *)pPVar1 != param_1);
      bVar3 = true;
LAB_1c00020a1:
      KeReleaseSpinLock(this + 0x18,uVar5);
      if (!bVar3) {
        return;
      }
    }
    if (this[0x78] == (ProcessLaunchMonitorClient)0x0) {
      local_res20 = 0;
      iVar6 = GetProcessHandle((ulonglong)local_res18[0],&local_res20);
      uVar9 = local_res20;
      if (-1 < iVar6) {
        local_res8[0] = '\0';
        uVar8 = IgnoreThisProcess(local_res20,local_res8);
        if (((-1 < (int)uVar8) && (local_res8[0] == '\0')) &&
           (iVar6 = SuspendOrResumeProcess(uVar9,'\x01'), -1 < iVar6)) {
          KeAcquireSpinLockRaiseToDpc(this + 0x80);
          PVar2 = this[0x78];
          if (PVar2 == (ProcessLaunchMonitorClient)0x0) {
            NTList<unsigned_long,0,NullLock>::InsertIfMissing
                      ((NTList<unsigned_long,0,NullLock> *)(this + 0x88),local_res18);
          }
          KeReleaseSpinLock(this + 0x80);
          if (PVar2 == (ProcessLaunchMonitorClient)0x0) {
            local_44 = local_res18[0];
            local_40 = _DAT_fffff78000000320;
            local_48 = param_1;
            lVar7 = NTQueueWithExportableWaitHandle<ProcessLaunchMonitorEventTimestamp>::
                    EnqueueElement((NTQueueWithExportableWaitHandle<ProcessLaunchMonitorEventTimestamp>
                                    *)(this + 0x28),(ProcessLaunchMonitorEventTimestamp *)&local_48)
            ;
            if (lVar7 == -0x3fffff66) {
              Telemetry::LogFeatureUsedWithResult
                        ((ushort *)L"MonitoringHealth",(ushort *)L"SuspendedListSizeLimitHit",
                         param_2,200,(ushort *)L"Too many processes are currently suspended");
            }
            uVar9 = local_res20;
          }
          else {
            SuspendOrResumeProcess(uVar9,'\0');
          }
        }
        ZwClose(uVar9);
      }
    }
  }
  return;
}



===== IgnoreThisProcess @ 1c00021f8 =====

ulonglong IgnoreThisProcess(undefined8 param_1,undefined1 *param_2)

{
  wchar_t wVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  ulonglong uVar6;
  ushort *puVar7;
  wchar_t *_Str1;
  uint *puVar8;
  wchar_t *pwVar9;
  uint *puVar10;
  undefined1 uVar11;
  undefined **ppuVar12;
  wchar_t *pwVar13;
  undefined4 local_res10 [2];
  undefined4 local_res18 [2];
  undefined8 local_res20;
  
  if (param_2 == (undefined1 *)0x0) {
    return 0xc000000d;
  }
  local_res10[0] = 0;
  uVar11 = 1;
  *param_2 = 1;
  uVar6 = ZwQueryInformationProcess(param_1,0x1b,0,0,local_res10);
  if ((int)uVar6 != -0x3ffffffc) {
    return uVar6;
  }
  puVar7 = (ushort *)ExAllocatePoolWithTag(0,local_res10[0],0x44495744);
  if (puVar7 == (ushort *)0x0) {
    return 0xc0000017;
  }
  iVar4 = ZwQueryInformationProcess(param_1,0x1b,puVar7,local_res10[0],local_res10);
  if (-1 < iVar4) {
    uVar6 = 0;
    pwVar9 = *(wchar_t **)(puVar7 + 4);
    _Str1 = pwVar9;
    if ((ulonglong)(*puVar7 >> 1) != 0) {
      pwVar13 = pwVar9;
      do {
        wVar1 = *pwVar9;
        _Str1 = pwVar13;
        if (wVar1 == L'0') break;
        pwVar9 = pwVar9 + 1;
        uVar6 = uVar6 + 1;
        _Str1 = pwVar9;
        if (wVar1 != L'\\') {
          _Str1 = pwVar13;
        }
        pwVar13 = _Str1;
      } while (uVar6 < *puVar7 >> 1);
    }
    ppuVar12 = &PTR_u_conhost_exe_1c0006038;
    do {
      iVar4 = _wcsicmp(_Str1,(wchar_t *)*ppuVar12);
      if (iVar4 == 0) {
        ExFreePoolWithTag(puVar7,0);
        return 0;
      }
      ppuVar12 = ppuVar12 + 1;
    } while (ppuVar12 != (undefined **)&SDDL_DEVOBJ_SYS_ALL_ADM_ALL);
  }
  ExFreePoolWithTag(puVar7,0);
  local_res20 = 0;
  bVar2 = false;
  uVar5 = ZwOpenProcessTokenEx(param_1,8,0x200,&local_res20);
  uVar6 = (ulonglong)uVar5;
  if (-1 < (int)uVar5) {
    local_res18[0] = 0;
    uVar5 = ZwQueryInformationToken(local_res20,2,0,0,local_res18);
    uVar6 = (ulonglong)uVar5;
    if (uVar5 == 0xc0000023) {
      puVar8 = (uint *)ExAllocatePoolWithTag(0,local_res18[0],0x44495744);
      if (puVar8 == (uint *)0x0) {
        ZwClose();
        uVar6 = 0xc0000017;
      }
      else {
        uVar5 = ZwQueryInformationToken(local_res20,2,puVar8,local_res18[0],local_res18);
        uVar6 = (ulonglong)uVar5;
        if ((int)uVar5 < 0) {
          ZwClose();
          ExFreePoolWithTag(puVar8,0);
        }
        else {
          ZwClose(local_res20);
          uVar6 = 0;
          if (*puVar8 != 0) {
            puVar10 = puVar8 + 2;
            bVar2 = false;
            do {
              cVar3 = RtlEqualSid(*(undefined8 *)puVar10,&g_sidBuffer);
              puVar10 = puVar10 + 4;
              if (cVar3 != '\0') {
                bVar2 = true;
              }
              uVar6 = uVar6 + 1;
            } while (uVar6 < *puVar8);
          }
          ExFreePoolWithTag(puVar8,0);
          uVar6 = 0;
          if ((bVar2) && (g_allowWerService == false)) goto LAB_1c000249a;
        }
      }
    }
    else {
      ZwClose(local_res20);
    }
  }
  uVar11 = 0;
LAB_1c000249a:
  *param_2 = uVar11;
  return uVar6;
}



===== InsertIfMissing @ 1c00024b8 =====

/* public: long __cdecl NTList<unsigned long,0,class NullLock>::InsertIfMissing(unsigned long const
   & __ptr64) __ptr64 */

long __thiscall
NTList<unsigned_long,0,NullLock>::InsertIfMissing
          (NTList<unsigned_long,0,NullLock> *this,ulong *param_1)

{
  NTList<unsigned_long,0,NullLock> *pNVar1;
  longlong *plVar2;
  code *pcVar3;
  NTList<unsigned_long,0,NullLock> *pNVar4;
  undefined8 *puVar5;
  
  pNVar4 = *(NTList<unsigned_long,0,NullLock> **)this;
  while ((pNVar4 != (NTList<unsigned_long,0,NullLock> *)0x0 && (pNVar4 != this))) {
    pNVar1 = pNVar4 + 0x10;
    pNVar4 = *(NTList<unsigned_long,0,NullLock> **)pNVar4;
    if (*(ulong *)pNVar1 == *param_1) {
      return 0;
    }
  }
  puVar5 = (undefined8 *)ExAllocatePoolWithTag(0,0x18,0x4a424f50);
  if (puVar5 == (undefined8 *)0x0) {
    return -0x3fffffe9;
  }
  *(ulong *)(puVar5 + 2) = *param_1;
  plVar2 = *(longlong **)(this + 8);
  if ((NTList<unsigned_long,0,NullLock> *)*plVar2 == this) {
    *puVar5 = this;
    puVar5[1] = plVar2;
    *plVar2 = (longlong)puVar5;
    *(undefined8 **)(this + 8) = puVar5;
    return 0;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  return 0;
}



===== IsSuspendTimeHealthy @ 1c0002558 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: bool __cdecl ProcessLaunchMonitorClient::IsSuspendTimeHealthy(void) __ptr64 */

bool __thiscall ProcessLaunchMonitorClient::IsSuspendTimeHealthy(ProcessLaunchMonitorClient *this)

{
  ProcessLaunchMonitorClient *pPVar1;
  longlong lVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  longlong lStack_10;
  
  uVar3 = KeAcquireSpinLockRaiseToDpc(this + 0x40);
  pPVar1 = *(ProcessLaunchMonitorClient **)(this + 0x28);
  iVar5 = 0;
  if ((pPVar1 == (ProcessLaunchMonitorClient *)0x0) || (pPVar1 == this + 0x28)) {
    iVar5 = -0x7fffffe6;
    lStack_10 = 0;
  }
  else {
    lStack_10 = *(longlong *)(pPVar1 + 0x18);
  }
  KeReleaseSpinLock(this + 0x40,CONCAT71((int7)((ulonglong)pPVar1 >> 8),uVar3));
  lVar2 = _DAT_fffff78000000320;
  if (iVar5 != -0x7fffffe6) {
    uVar4 = KeQueryTimeIncrement();
    if ((longlong)((ulonglong)uVar4 * lStack_10) < (longlong)((ulonglong)uVar4 * lVar2)) {
      return (longlong)((ulonglong)uVar4 * lVar2 - (ulonglong)uVar4 * lStack_10) <=
             (longlong)((ulonglong)*(uint *)(this + 0x120) * 10000);
    }
  }
  return true;
}



===== QueueHealthTimerSignaledDpc @ 1c0002630 =====

void QueueHealthTimerSignaledDpc(undefined8 param_1,ProcessLaunchMonitorClient *param_2)

{
  bool bVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  
  if ((param_2 != (ProcessLaunchMonitorClient *)0x0) &&
     (bVar1 = ProcessLaunchMonitorClient::IsSuspendTimeHealthy(param_2), !bVar1)) {
    iVar2 = 1;
    LOCK();
    if (*(int *)param_2 == 1) {
      *(undefined4 *)param_2 = 2;
    }
    else {
      iVar2 = *(int *)param_2;
    }
    UNLOCK();
    if ((iVar2 != 3) && (lVar3 = IoAllocateWorkItem(*(undefined8 *)(param_2 + 0x128)), lVar3 != 0))
    {
      plVar4 = (longlong *)ExAllocatePoolWithTag(0,0x10,0x44495744);
      if (plVar4 == (longlong *)0x0) {
        IoFreeWorkItem();
      }
      else {
        *plVar4 = lVar3;
        plVar4[1] = (longlong)param_2;
        IoQueueWorkItem(lVar3,CleanupClientMonitoringWorkerRoutine,1,plVar4);
      }
    }
  }
  return;
}



===== ResumeProcess @ 1c00026e4 =====

/* public: long __cdecl ProcessLaunchMonitorClient::ResumeProcess(unsigned long,bool * __ptr64)
   __ptr64 */

long __thiscall
ProcessLaunchMonitorClient::ResumeProcess
          (ProcessLaunchMonitorClient *this,ulong param_1,bool *param_2)

{
  ProcessLaunchMonitorClient *pPVar1;
  undefined8 *puVar2;
  code *pcVar3;
  ProcessLaunchMonitorClient *pPVar4;
  undefined1 uVar5;
  int iVar6;
  longlong lVar7;
  ErrorType EVar8;
  bool *local_res18;
  
  EVar8 = (ErrorType)param_2;
  local_res18 = param_2;
  if (*(ulong *)(this + 0x6c) == param_1) {
    uVar5 = KeAcquireSpinLockRaiseToDpc(this + 0x80);
    lVar7 = 0;
    pPVar1 = *(ProcessLaunchMonitorClient **)(this + 0x88);
    while ((pPVar4 = pPVar1, pPVar4 != (ProcessLaunchMonitorClient *)0x0 && (pPVar4 != this + 0x88))
          ) {
      pPVar1 = *(ProcessLaunchMonitorClient **)pPVar4;
      if (*(ulong *)(pPVar4 + 0x10) == param_1) {
        if ((*(ProcessLaunchMonitorClient **)(pPVar1 + 8) != pPVar4) ||
           (puVar2 = *(undefined8 **)(pPVar4 + 8), (ProcessLaunchMonitorClient *)*puVar2 != pPVar4))
        {
          pcVar3 = (code *)swi(0x29);
          (*pcVar3)(3);
          goto LAB_1c0002807;
        }
        *puVar2 = pPVar1;
        *(undefined8 **)(pPVar1 + 8) = puVar2;
        ExFreePoolWithTag(pPVar4,0x4a424f50);
        lVar7 = lVar7 + 1;
      }
    }
    KeReleaseSpinLock(this + 0x80,uVar5);
    if (lVar7 == 0) {
LAB_1c0002807:
      iVar6 = 0;
    }
    else {
      local_res18 = (bool *)0x0;
      iVar6 = GetProcessHandle((ulonglong)param_1,&local_res18);
      if (-1 < iVar6) {
        iVar6 = SuspendOrResumeProcess(local_res18,'\0');
        ZwClose(local_res18);
      }
    }
  }
  else {
    LOCK();
    *(undefined4 *)this = 3;
    UNLOCK();
    Shutdown(this);
    Telemetry::LogFeatureUsedWithResult
              ((ushort *)L"DriverRequest",(ushort *)L"ResumeProcess",EVar8,0,
               (ushort *)
               L"The user requested to resume a process that is not the last provided process");
    iVar6 = -0x3ffffff3;
  }
  return iVar6;
}



===== Shutdown @ 1c000282c =====

/* public: void __cdecl ProcessLaunchMonitorClient::Shutdown(void) __ptr64 */

void __thiscall ProcessLaunchMonitorClient::Shutdown(ProcessLaunchMonitorClient *this)

{
  ProcessLaunchMonitorClient *pPVar1;
  ProcessLaunchMonitorClient *pPVar2;
  undefined8 *puVar3;
  undefined8 ***pppuVar4;
  undefined8 **ppuVar5;
  code *pcVar6;
  undefined1 uVar7;
  int iVar8;
  ProcessLaunchMonitorClient *pPVar9;
  undefined8 ***pppuVar10;
  undefined8 local_res8;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 ***local_38;
  undefined8 ***local_30;
  
  KeCancelTimer(this + 0xa0);
  local_30 = &local_38;
  local_38 = &local_38;
  uVar7 = KeAcquireSpinLockRaiseToDpc(this + 0x80);
  pPVar1 = this + 0x88;
  this[0x78] = (ProcessLaunchMonitorClient)0x1;
  pPVar9 = *(ProcessLaunchMonitorClient **)pPVar1;
  while( true ) {
    if ((pPVar9 == (ProcessLaunchMonitorClient *)0x0) || (pPVar9 == pPVar1)) {
      pPVar9 = (ProcessLaunchMonitorClient *)0x0;
    }
    if (pPVar9 == (ProcessLaunchMonitorClient *)0x0) break;
    NTList<unsigned_long,0,NullLock>::InsertIfMissing
              ((NTList<unsigned_long,0,NullLock> *)&local_38,(ulong *)(pPVar9 + 0x10));
    pPVar9 = *(ProcessLaunchMonitorClient **)pPVar9;
  }
  pPVar9 = *(ProcessLaunchMonitorClient **)pPVar1;
  while ((pPVar9 != (ProcessLaunchMonitorClient *)0x0 && (pPVar9 != pPVar1))) {
    pPVar2 = *(ProcessLaunchMonitorClient **)pPVar9;
    if ((*(ProcessLaunchMonitorClient **)(pPVar2 + 8) != pPVar9) ||
       (puVar3 = *(undefined8 **)(pPVar9 + 8), (ProcessLaunchMonitorClient *)*puVar3 != pPVar9))
    goto LAB_1c00029d1;
    *puVar3 = pPVar2;
    *(undefined8 **)(pPVar2 + 8) = puVar3;
    ExFreePoolWithTag(pPVar9,0x4a424f50);
    pPVar9 = pPVar2;
  }
  KeReleaseSpinLock(this + 0x80,uVar7);
  pppuVar10 = local_38;
  while( true ) {
    if ((pppuVar10 == (undefined8 ***)0x0) || ((undefined8 ****)pppuVar10 == &local_38)) {
      pppuVar10 = (undefined8 ***)0x0;
    }
    if (pppuVar10 == (undefined8 ***)0x0) break;
    local_res8 = 0;
    iVar8 = GetProcessHandle((ulonglong)*(uint *)(pppuVar10 + 2),&local_res8);
    if (-1 < iVar8) {
      SuspendOrResumeProcess(local_res8,'\0');
      ZwClose(local_res8);
    }
    pppuVar10 = (undefined8 ***)*pppuVar10;
  }
  local_48 = 0;
  uStack_40 = 0;
  NTQueueWithExportableWaitHandle<ProcessLaunchMonitorEventTimestamp>::EnqueueElement
            ((NTQueueWithExportableWaitHandle<ProcessLaunchMonitorEventTimestamp> *)(this + 0x28),
             (ProcessLaunchMonitorEventTimestamp *)&local_48);
  pppuVar10 = local_38;
  while( true ) {
    if ((pppuVar10 == (undefined8 ***)0x0) || ((undefined8 ****)pppuVar10 == &local_38)) {
      return;
    }
    pppuVar4 = (undefined8 ***)*pppuVar10;
    if (((undefined8 ***)pppuVar4[1] != pppuVar10) ||
       (ppuVar5 = pppuVar10[1], (undefined8 ***)*ppuVar5 != pppuVar10)) break;
    *ppuVar5 = pppuVar4;
    pppuVar4[1] = ppuVar5;
    ExFreePoolWithTag(pppuVar10,0x4a424f50);
    pppuVar10 = pppuVar4;
  }
LAB_1c00029d1:
  pcVar6 = (code *)swi(0x29);
  (*pcVar6)(3);
  pcVar6 = (code *)swi(3);
  (*pcVar6)();
  return;
}



===== SuspendOrResumeProcess @ 1c00029e0 =====

int SuspendOrResumeProcess(undefined8 param_1,char param_2)

{
  int iVar1;
  undefined8 local_res18 [2];
  
  local_res18[0] = 0;
  iVar1 = ObReferenceObjectByHandle
                    (param_1,0x1fffff,*(undefined8 *)PsProcessType_exref,0,local_res18,0);
  if (-1 < iVar1) {
    if (param_2 == '\0') {
      iVar1 = PsResumeProcess(local_res18[0]);
    }
    else {
      iVar1 = PsSuspendProcess();
    }
    ObfDereferenceObject(local_res18[0]);
  }
  return iVar1;
}



===== ProcessLaunchMonitorDevice @ 1c0002a70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: __cdecl ProcessLaunchMonitorDevice::ProcessLaunchMonitorDevice(struct _DRIVER_OBJECT *
   __ptr64) __ptr64 */

ProcessLaunchMonitorDevice * __thiscall
ProcessLaunchMonitorDevice::ProcessLaunchMonitorDevice
          (ProcessLaunchMonitorDevice *this,_DRIVER_OBJECT *param_1)

{
  uint *puVar1;
  undefined2 uVar2;
  undefined *puVar3;
  int iVar4;
  longlong lVar5;
  code *pcVar6;
  undefined1 *puVar7;
  ushort *in_R8;
  ulong in_R9D;
  undefined1 auStackY_68 [8];
  undefined1 auStackY_60 [24];
  ulong in_stack_ffffffffffffffb8;
  bool in_stack_ffffffffffffffc0;
  _UNICODE_STRING *in_stack_ffffffffffffffc8;
  
  LegacyDevice::LegacyDevice
            ((LegacyDevice *)this,param_1,in_R8,in_R9D,in_stack_ffffffffffffffb8,
             in_stack_ffffffffffffffc0,in_stack_ffffffffffffffc8);
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined ***)this = &_vftable_;
  lVar5 = ExAllocatePoolWithTag(0,0x18,0x4a424f50);
  puVar7 = auStackY_68;
  if (lVar5 != 0) {
    *(undefined8 *)(lVar5 + 0x10) = 0;
    *(longlong *)(lVar5 + 8) = lVar5;
    *(longlong *)lVar5 = lVar5;
  }
  *(longlong *)(this + 0x30) = lVar5;
  if (*(longlong *)(this + 8) != 0) {
    puVar1 = (uint *)(*(longlong *)(this + 8) + 0x30);
    *puVar1 = *puVar1 & 0xffffff7f;
  }
  if (Telemetry::g_isTelemetryInitialized == false) {
    iVar4 = ExUuidCreate(&Telemetry::g_featureSessionID);
    puVar7 = auStackY_68;
    if (-1 < iVar4) {
      puVar7 = auStackY_68;
      if (DAT_1c00080b0 != 0) {
        pcVar6 = (code *)swi(0x29);
        (*pcVar6)(5);
        puVar7 = auStackY_60;
      }
      _DAT_1c00080b8 = 0;
      uRam00000001c00080c0 = 0;
      *(undefined8 *)(puVar7 + -8) = 0x1c0002b57;
      iVar4 = EtwRegister(puVar7 + 0x40,_tlgEnableCallback,&DAT_1c0008090,&DAT_1c00080b0);
      puVar3 = PTR_DAT_1c0008098;
      if (iVar4 == 0) {
        uVar2 = *(undefined2 *)PTR_DAT_1c0008098;
        *(undefined8 *)(puVar7 + -8) = 0x1c0002b78;
        pcVar6 = (code *)MmGetSystemRoutineAddress
                                   (&`TraceLoggingSetInformation_2K'::__l2::strEtwSetInformation);
        if (pcVar6 != (code *)0x0) {
          *(undefined8 *)(puVar7 + -8) = 0x1c0002b99;
          (*pcVar6)(DAT_1c00080b0,2,puVar3,uVar2);
        }
      }
      else if (iVar4 < 0) goto LAB_1c0002ba4;
      Telemetry::g_isTelemetryInitialized = true;
    }
  }
LAB_1c0002ba4:
  *(undefined8 *)(puVar7 + -8) = 0x1c0002bb4;
  return this;
}



===== ~ProcessLaunchMonitorDevice @ 1c0002bd0 =====

/* public: virtual __cdecl ProcessLaunchMonitorDevice::~ProcessLaunchMonitorDevice(void) __ptr64 */

void __thiscall
ProcessLaunchMonitorDevice::~ProcessLaunchMonitorDevice(ProcessLaunchMonitorDevice *this)

{
  NTList<ProcessLaunchMonitorClient*___ptr64,0,SpinLock> *this_00;
  undefined8 uVar1;
  
  this_00 = *(NTList<ProcessLaunchMonitorClient*___ptr64,0,SpinLock> **)(this + 0x30);
  *(undefined ***)this = &_vftable_;
  if (this_00 != (NTList<ProcessLaunchMonitorClient*___ptr64,0,SpinLock> *)0x0) {
    NTList<ProcessLaunchMonitorClient*___ptr64,0,SpinLock>::
    ~NTList<ProcessLaunchMonitorClient*___ptr64,0,SpinLock>(this_00);
    ExFreePoolWithTag(this_00,0x4a424f50);
  }
  *(undefined8 *)(this + 0x30) = 0;
  uVar1 = DAT_1c00080b0;
  DAT_1c00080b0 = 0;
  DAT_1c0008090 = 0;
  EtwUnregister(uVar1);
  Telemetry::g_isTelemetryInitialized = false;
  LegacyDevice::~LegacyDevice((LegacyDevice *)this);
  return;
}



===== `vector_deleting_destructor' @ 1c0002c60 =====

/* public: virtual void * __ptr64 __cdecl ProcessLaunchMonitorDevice::`vector deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
ProcessLaunchMonitorDevice::_vector_deleting_destructor_
          (ProcessLaunchMonitorDevice *this,uint param_1)

{
  ~ProcessLaunchMonitorDevice(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x4a424f50);
  }
  return this;
}



===== DispatchBufferedIoctl @ 1c0002cb0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: virtual long __cdecl ProcessLaunchMonitorDevice::DispatchBufferedIoctl(struct
   _FILE_OBJECT * __ptr64,unsigned long,unsigned long,void * __ptr64,unsigned long,unsigned __int64
   * __ptr64) __ptr64 */

long __thiscall
ProcessLaunchMonitorDevice::DispatchBufferedIoctl
          (ProcessLaunchMonitorDevice *this,_FILE_OBJECT *param_1,ulong param_2,ulong param_3,
          void *param_4,ulong param_5,__uint64 *param_6)

{
  ProcessLaunchMonitorClient *this_00;
  __uint64 *p_Var1;
  uint uVar2;
  long lVar3;
  int iVar4;
  __uint64 _Var5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  p_Var1 = param_6;
  uVar2 = 0;
  *param_6 = 0;
  if ((param_1 != (_FILE_OBJECT *)0x0) &&
     (this_00 = *(ProcessLaunchMonitorClient **)(param_1 + 0x18),
     this_00 != (ProcessLaunchMonitorClient *)0x0)) {
    if (param_2 == 0x22403c) {
      if (param_4 == (void *)0x0) {
        return -0x3ffffff0;
      }
      if (param_5 < 0x10) {
        return -0x3ffffff0;
      }
      LOCK();
      iVar4 = *(int *)this_00;
      if (iVar4 == 1) {
        *(undefined4 *)this_00 = 1;
      }
      UNLOCK();
      if (iVar4 != 1) {
        return -0x3ffffe7c;
      }
      if (param_5 != 0x10) {
        return -0x3ffffff0;
      }
      lVar3 = ProcessLaunchMonitorClient::DequeueNextEvent(this_00,param_4);
      if (lVar3 < 0) {
        return lVar3;
      }
      *p_Var1 = 0x10;
      return lVar3;
    }
    if (param_2 == 0x224040) {
      if (param_3 < 4) {
        return -0x3ffffff0;
      }
      if (param_4 == (void *)0x0) {
        return -0x3ffffff0;
      }
      LOCK();
      iVar4 = *(int *)this_00;
      if (iVar4 == 1) {
        *(undefined4 *)this_00 = 1;
      }
      UNLOCK();
      if (iVar4 == 1) {
        lVar3 = ProcessLaunchMonitorClient::ResumeProcess(this_00,*(ulong *)param_4,(bool *)0x0);
        return lVar3;
      }
    }
    else {
      if (param_2 != 0x224044) {
        if (param_2 == 0x224048) {
          if ((param_4 != (void *)0x0) && (7 < param_5)) {
            LOCK();
            iVar4 = *(int *)this_00;
            if (iVar4 == 1) {
              *(undefined4 *)this_00 = 1;
            }
            UNLOCK();
            if (iVar4 != 1) {
              return -0x3ffffe7c;
            }
            param_6 = (__uint64 *)0x0;
            iVar4 = ZwDuplicateObject(0xffffffffffffffff,*(undefined8 *)(this_00 + 0x50),
                                      0xffffffffffffffff,&param_6,0x100000,0,0);
            if (iVar4 < 0) {
              return iVar4;
            }
            *(__uint64 **)param_4 = param_6;
            *p_Var1 = 8;
            return iVar4;
          }
        }
        else if (param_2 == 0x22404c) {
          if ((param_4 != (void *)0x0) && (3 < param_5)) {
            LOCK();
            if (*(int *)this_00 == 3) {
              *(undefined4 *)this_00 = 1;
            }
            UNLOCK();
            *(undefined4 *)param_4 = 1;
            *param_6 = 4;
            return 0;
          }
        }
        else {
          if (param_2 != 0x224050) {
            if (param_2 == 0x228034) {
              if (param_3 < 4) {
                return -0x3ffffff0;
              }
              if (param_4 == (void *)0x0) {
                return -0x3ffffff0;
              }
              LOCK();
              iVar4 = *(int *)this_00;
              if (iVar4 == 1) {
                *(undefined4 *)this_00 = 1;
              }
              UNLOCK();
              if (iVar4 == 1) {
                lVar3 = ProcessLaunchMonitorClient::AddMonitoredPid(this_00,*(ulong *)param_4);
                return lVar3;
              }
              return -0x3ffffe7c;
            }
            if (param_2 != 0x228038) {
              return -0x3ffffff0;
            }
            if (param_3 < 4) {
              return -0x3ffffff0;
            }
            if (param_4 == (void *)0x0) {
              return -0x3ffffff0;
            }
            LOCK();
            iVar4 = *(int *)this_00;
            if (iVar4 == 1) {
              *(undefined4 *)this_00 = 1;
            }
            UNLOCK();
            if (iVar4 != 1) {
              return -0x3ffffe7c;
            }
            param_6 = (__uint64 *)CONCAT44(param_6._4_4_,*(int *)param_4);
            if (*(int *)param_4 == -1) {
              this_00[0x20] = (ProcessLaunchMonitorClient)0x0;
            }
            else {
              _Var5 = NTList<unsigned_long,0,SpinLock>::Erase
                                ((NTList<unsigned_long,0,SpinLock> *)(this_00 + 8),(ulong *)&param_6
                                );
              if (_Var5 != 1) {
                uVar2 = -(uint)(_Var5 != 0) & 0xc00000e5;
              }
            }
            return uVar2;
          }
          if ((param_4 != (void *)0x0) && (0xf < param_5)) {
            if (Telemetry::g_isTelemetryInitialized == false) {
              uVar6 = 0;
              uVar7 = 0;
              uVar8 = 0;
              uVar9 = 0;
            }
            else {
              uVar6 = _g_featureSessionID;
              uVar7 = uRam00000001c000834c;
              uVar8 = uRam00000001c0008350;
              uVar9 = uRam00000001c0008354;
            }
            *(undefined4 *)param_4 = uVar6;
            *(undefined4 *)((longlong)param_4 + 4) = uVar7;
            *(undefined4 *)((longlong)param_4 + 8) = uVar8;
            *(undefined4 *)((longlong)param_4 + 0xc) = uVar9;
            *param_6 = 0x10;
            return 0;
          }
        }
        return -0x3ffffff0;
      }
      LOCK();
      iVar4 = *(int *)this_00;
      if (iVar4 == 1) {
        *(undefined4 *)this_00 = 1;
      }
      UNLOCK();
      if (iVar4 == 1) {
        ProcessLaunchMonitorClient::Shutdown(this_00);
        return 0;
      }
    }
  }
  return -0x3ffffe7c;
}



===== DispatchClose @ 1c0002ff0 =====

/* public: virtual long __cdecl ProcessLaunchMonitorDevice::DispatchClose(struct _FILE_OBJECT *
   __ptr64) __ptr64 */

long __thiscall
ProcessLaunchMonitorDevice::DispatchClose(ProcessLaunchMonitorDevice *this,_FILE_OBJECT *param_1)

{
  ProcessLaunchMonitorClient *pPVar1;
  int iVar2;
  ProcessLaunchMonitorClient *this_00;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  code *pcVar6;
  undefined8 *puVar7;
  undefined1 uVar8;
  long lVar9;
  
  if (param_1 == (_FILE_OBJECT *)0x0) {
    lVar9 = -0x3ffffff3;
  }
  else {
    this_00 = *(ProcessLaunchMonitorClient **)(param_1 + 0x18);
    if (this_00 == (ProcessLaunchMonitorClient *)0x0) {
      lVar9 = -0x3ffffe7c;
    }
    else {
      puVar3 = *(undefined8 **)(this + 0x30);
      uVar8 = KeAcquireSpinLockRaiseToDpc(puVar3 + 2);
      puVar4 = (undefined8 *)*puVar3;
      while ((puVar7 = puVar4, puVar7 != (undefined8 *)0x0 && (puVar7 != puVar3))) {
        puVar4 = (undefined8 *)*puVar7;
        if ((ProcessLaunchMonitorClient *)puVar7[2] == this_00) {
          if (((undefined8 *)puVar4[1] != puVar7) ||
             (puVar5 = (undefined8 *)puVar7[1], (undefined8 *)*puVar5 != puVar7)) {
            pcVar6 = (code *)swi(0x29);
            (*pcVar6)(3);
            pcVar6 = (code *)swi(3);
            lVar9 = (*pcVar6)();
            return lVar9;
          }
          *puVar5 = puVar4;
          puVar4[1] = puVar5;
          ExFreePoolWithTag(puVar7,0x4a424f50);
        }
      }
      KeReleaseSpinLock(puVar3 + 2,uVar8);
      *(undefined8 *)(param_1 + 0x18) = 0;
      LOCK();
      pPVar1 = this_00 + 0x7c;
      iVar2 = *(int *)pPVar1;
      *(int *)pPVar1 = *(int *)pPVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        ProcessLaunchMonitorClient::~ProcessLaunchMonitorClient(this_00);
        ExFreePoolWithTag(this_00,0x4a424f50);
      }
      lVar9 = 0;
    }
  }
  return lVar9;
}



===== DispatchCreate @ 1c0003100 =====

/* public: virtual long __cdecl ProcessLaunchMonitorDevice::DispatchCreate(struct _FILE_OBJECT *
   __ptr64) __ptr64 */

long __thiscall
ProcessLaunchMonitorDevice::DispatchCreate(ProcessLaunchMonitorDevice *this,_FILE_OBJECT *param_1)

{
  ProcessLaunchMonitorClient *pPVar1;
  int iVar2;
  _DEVICE_OBJECT *p_Var3;
  longlong lVar4;
  code *pcVar5;
  undefined1 uVar6;
  long lVar7;
  ProcessLaunchMonitorClient *pPVar8;
  longlong *plVar9;
  longlong *plVar10;
  undefined1 *puVar11;
  int iVar12;
  long local_res10 [2];
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  if (param_1 == (_FILE_OBJECT *)0x0) {
    lVar7 = -0x3ffffff3;
  }
  else {
    p_Var3 = *(_DEVICE_OBJECT **)(this + 8);
    lVar7 = 0x130;
    local_res10[0] = -0x3fffff1b;
    pPVar8 = (ProcessLaunchMonitorClient *)ExAllocatePoolWithTag(0,0x130,0x4a424f50);
    if ((pPVar8 != (ProcessLaunchMonitorClient *)0x0) &&
       (pPVar8 = (ProcessLaunchMonitorClient *)
                 ProcessLaunchMonitorClient::ProcessLaunchMonitorClient
                           (pPVar8,lVar7,p_Var3,local_res10),
       pPVar8 != (ProcessLaunchMonitorClient *)0x0)) {
      if (local_res10[0] < 0) {
        LOCK();
        pPVar1 = pPVar8 + 0x7c;
        iVar12 = *(int *)pPVar1;
        *(int *)pPVar1 = *(int *)pPVar1 + -1;
        UNLOCK();
        if (iVar12 == 1) {
          ProcessLaunchMonitorClient::~ProcessLaunchMonitorClient(pPVar8);
          ExFreePoolWithTag(pPVar8,0x4a424f50);
        }
        return local_res10[0];
      }
      lVar4 = *(longlong *)(this + 0x30);
      plVar9 = (longlong *)ExAllocatePoolWithTag(0,0x18,0x4a424f50);
      if (plVar9 == (longlong *)0x0) {
        plVar9 = (longlong *)0x0;
      }
      else {
        plVar9[2] = (longlong)pPVar8;
      }
      uVar6 = KeAcquireSpinLockRaiseToDpc(lVar4 + 0x10);
      puVar11 = auStack_38;
      if (plVar9 == (longlong *)0x0) {
        iVar12 = -0x3fffffe9;
        puVar11 = auStack_38;
      }
      else {
        plVar10 = *(longlong **)(lVar4 + 8);
        if (*plVar10 != lVar4) {
          pcVar5 = (code *)swi(0x29);
          plVar10 = (longlong *)(*pcVar5)(3,uVar6);
          puVar11 = auStack_30;
        }
        *plVar9 = lVar4;
        plVar9[1] = (longlong)plVar10;
        *plVar10 = (longlong)plVar9;
        *(longlong **)(lVar4 + 8) = plVar9;
        iVar12 = 0;
      }
      *(undefined8 *)(puVar11 + -8) = 0x1c0003220;
      KeReleaseSpinLock();
      if (-1 < iVar12) {
        *(ProcessLaunchMonitorClient **)(param_1 + 0x18) = pPVar8;
        return 0;
      }
      LOCK();
      pPVar1 = pPVar8 + 0x7c;
      iVar2 = *(int *)pPVar1;
      *(int *)pPVar1 = *(int *)pPVar1 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        *(undefined8 *)(puVar11 + -8) = 0x1c000323e;
        ProcessLaunchMonitorClient::~ProcessLaunchMonitorClient(pPVar8);
        *(undefined8 *)(puVar11 + -8) = 0x1c000324d;
        ExFreePoolWithTag(pPVar8,0x4a424f50);
      }
      return iVar12;
    }
    lVar7 = -0x3fffffe9;
  }
  return lVar7;
}



===== DispatchRoutine @ 1c0003280 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual void __cdecl ProcessLaunchMonitorDevice::DispatchRoutine(class IncomingIrpWrapper
   * __ptr64) __ptr64 */

void __thiscall
ProcessLaunchMonitorDevice::DispatchRoutine
          (ProcessLaunchMonitorDevice *this,IncomingIrpWrapper *param_1)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  code *pcVar4;
  ulonglong local_res10 [3];
  
  pcVar2 = *(char **)(param_1 + 8);
  cVar1 = *pcVar2;
  if (cVar1 == '\0') {
    pcVar4 = *(code **)(*(longlong *)this + 0x10);
  }
  else {
    if (cVar1 != '\x02') {
      if (cVar1 != '\x0e') {
        return;
      }
      if ((*(uint *)(pcVar2 + 0x18) & 3) == 0) {
        local_res10[0] = (ulonglong)*(uint *)(pcVar2 + 8);
        uVar3 = (**(code **)(*(longlong *)this + 0x20))
                          (this,*(undefined8 *)(pcVar2 + 0x30),*(uint *)(pcVar2 + 0x18),
                           *(undefined4 *)(pcVar2 + 0x10),
                           *(undefined8 *)(*(longlong *)param_1 + 0x18),*(uint *)(pcVar2 + 8),
                           local_res10);
        *(undefined4 *)(*(longlong *)param_1 + 0x30) = uVar3;
        *(ulonglong *)(*(longlong *)param_1 + 0x38) = local_res10[0];
        return;
      }
      *(undefined4 *)(*(longlong *)param_1 + 0x30) = 0xc00000bb;
      goto LAB_1c000332a;
    }
    pcVar4 = *(code **)(*(longlong *)this + 0x18);
  }
  uVar3 = (*pcVar4)(this,*(undefined8 *)(pcVar2 + 0x30));
  *(undefined4 *)(*(longlong *)param_1 + 0x30) = uVar3;
LAB_1c000332a:
  *(undefined8 *)(*(longlong *)param_1 + 0x38) = 0;
  return;
}



===== HandleProcessCreatedOrDestroyed @ 1c0003344 =====

/* public: void __cdecl ProcessLaunchMonitorDevice::HandleProcessCreatedOrDestroyed(bool,unsigned
   long,unsigned long) __ptr64 */

void __thiscall
ProcessLaunchMonitorDevice::HandleProcessCreatedOrDestroyed
          (ProcessLaunchMonitorDevice *this,bool param_1,ulong param_2,ulong param_3)

{
  int *piVar1;
  ProcessLaunchMonitorClient *pPVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined8 ***pppuVar5;
  ProcessLaunchMonitorClient *this_00;
  undefined8 *puVar6;
  code *pcVar7;
  undefined8 ****ppppuVar8;
  ProcessLaunchMonitorClient *pPVar9;
  undefined1 uVar10;
  undefined8 ****ppppuVar11;
  undefined8 *puVar12;
  int iVar13;
  ulong local_res8 [2];
  char local_res10;
  ulong local_res18;
  ulong local_res20;
  undefined8 ****local_68;
  undefined8 ****local_60;
  
  puVar4 = *(undefined8 **)(this + 0x30);
  local_60 = &local_68;
  local_68 = &local_68;
  puVar6 = puVar4 + 2;
  local_res10 = param_1;
  local_res18 = param_2;
  local_res20 = param_3;
  uVar10 = KeAcquireSpinLockRaiseToDpc(puVar6);
  puVar12 = (undefined8 *)*puVar4;
  while( true ) {
    if ((puVar12 == (undefined8 *)0x0) || (puVar12 == puVar4)) {
      puVar12 = (undefined8 *)0x0;
    }
    if (puVar12 == (undefined8 *)0x0) break;
    pppuVar5 = (undefined8 ***)puVar12[2];
    LOCK();
    piVar1 = (int *)((longlong)pppuVar5 + 0x7c);
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    ppppuVar11 = (undefined8 ****)ExAllocatePoolWithTag(0,0x18,0x4a424f50);
    if (ppppuVar11 == (undefined8 ****)0x0) {
      iVar13 = -0x3fffffe9;
      KeReleaseSpinLock(puVar6,uVar10);
      goto LAB_1c0003427;
    }
    ppppuVar11[2] = pppuVar5;
    if ((undefined8 *****)*local_60 != &local_68) goto LAB_1c000358c;
    ppppuVar11[1] = local_60;
    *ppppuVar11 = &local_68;
    *local_60 = ppppuVar11;
    puVar12 = (undefined8 *)*puVar12;
    local_60 = ppppuVar11;
  }
  KeReleaseSpinLock(puVar6,uVar10);
  iVar13 = 0;
LAB_1c0003427:
  ppppuVar11 = local_68;
  while( true ) {
    if ((ppppuVar11 == (undefined8 ****)0x0) || ((undefined8 *****)ppppuVar11 == &local_68)) {
      ppppuVar11 = (undefined8 ****)0x0;
    }
    ppppuVar8 = local_68;
    if (ppppuVar11 == (undefined8 ****)0x0) break;
    this_00 = (ProcessLaunchMonitorClient *)ppppuVar11[2];
    if (-1 < iVar13) {
      if (local_res10 == '\0') {
        local_res8[0] = param_3;
        NTList<unsigned_long,0,SpinLock>::Erase
                  ((NTList<unsigned_long,0,SpinLock> *)(this_00 + 8),local_res8);
        uVar10 = KeAcquireSpinLockRaiseToDpc(this_00 + 0x80);
        pPVar2 = *(ProcessLaunchMonitorClient **)(this_00 + 0x88);
        while ((pPVar9 = pPVar2, pPVar9 != (ProcessLaunchMonitorClient *)0x0 &&
               (pPVar9 != this_00 + 0x88))) {
          pPVar2 = *(ProcessLaunchMonitorClient **)pPVar9;
          if (*(ulong *)(pPVar9 + 0x10) == local_res20) {
            if ((*(ProcessLaunchMonitorClient **)(pPVar2 + 8) != pPVar9) ||
               (puVar6 = *(undefined8 **)(pPVar9 + 8),
               (ProcessLaunchMonitorClient *)*puVar6 != pPVar9)) goto LAB_1c000358c;
            *puVar6 = pPVar2;
            *(undefined8 **)(pPVar2 + 8) = puVar6;
            ExFreePoolWithTag(pPVar9,0x4a424f50);
          }
        }
        KeReleaseSpinLock(this_00 + 0x80,uVar10);
        param_3 = local_res20;
      }
      else {
        ProcessLaunchMonitorClient::HandleProcessCreated(this_00,local_res18,param_3);
      }
    }
    LOCK();
    pPVar2 = this_00 + 0x7c;
    iVar3 = *(int *)pPVar2;
    *(int *)pPVar2 = *(int *)pPVar2 + -1;
    UNLOCK();
    if ((iVar3 == 1) && (this_00 != (ProcessLaunchMonitorClient *)0x0)) {
      ProcessLaunchMonitorClient::~ProcessLaunchMonitorClient(this_00);
      ExFreePoolWithTag(this_00,0x4a424f50);
    }
    ppppuVar11 = (undefined8 ****)*ppppuVar11;
  }
  while( true ) {
    if ((ppppuVar8 == (undefined8 ****)0x0) || ((undefined8 *****)ppppuVar8 == &local_68)) {
      return;
    }
    ppppuVar11 = (undefined8 ****)*ppppuVar8;
    if (((undefined8 ****)ppppuVar11[1] != ppppuVar8) ||
       (pppuVar5 = ppppuVar8[1], (undefined8 ****)*pppuVar5 != ppppuVar8)) break;
    *pppuVar5 = ppppuVar11;
    ppppuVar11[1] = pppuVar5;
    ExFreePoolWithTag(ppppuVar8,0x4a424f50);
    ppppuVar8 = ppppuVar11;
  }
LAB_1c000358c:
  pcVar7 = (code *)swi(0x29);
  (*pcVar7)(3);
  pcVar7 = (code *)swi(3);
  (*pcVar7)();
  return;
}



===== LegacyDevice @ 1c000359c =====

/* public: __cdecl LegacyDevice::LegacyDevice(struct _DRIVER_OBJECT * __ptr64,unsigned short const *
   __ptr64,unsigned long,unsigned long,bool,struct _UNICODE_STRING const * __ptr64) __ptr64 */

LegacyDevice * __thiscall
LegacyDevice::LegacyDevice
          (LegacyDevice *this,_DRIVER_OBJECT *param_1,ushort *param_2,ulong param_3,ulong param_4,
          bool param_5,_UNICODE_STRING *param_6)

{
  LegacyDevice *pLVar1;
  int iVar2;
  undefined4 uVar3;
  LegacyDevice *pLVar4;
  longlong lVar5;
  _DRIVER_OBJECT *p_Var6;
  longlong local_38 [3];
  longlong local_20 [3];
  
  *(undefined4 *)(this + 0x10) = 0xc0000184;
  pLVar1 = this + 0x18;
  this[0x14] = (LegacyDevice)0x0;
  *(longlong *)(this + 8) = 0;
  *(longlong *)pLVar1 = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined ***)this = &_vftable_;
  ConcatenateStrings(local_38,L"\\Device\\");
  pLVar4 = (LegacyDevice *)ConcatenateStrings(local_20,L"\\DosDevices\\");
  if (pLVar4 != pLVar1) {
    if (*(longlong *)pLVar1 != 0) {
      ExFreePoolWithTag(*(longlong *)pLVar1,0x42505043);
      *(longlong *)pLVar1 = 0;
    }
    *(longlong *)pLVar1 = *(longlong *)pLVar4;
    *(longlong *)(this + 0x20) = *(longlong *)(pLVar4 + 8);
    *(longlong *)(this + 0x28) = *(longlong *)(pLVar4 + 0x10);
    *(longlong *)(pLVar4 + 8) = 0;
    *(longlong *)(pLVar4 + 0x10) = 0;
    *(longlong *)pLVar4 = 0;
  }
  if (local_20[0] != 0) {
    ExFreePoolWithTag(local_20[0],0x42505043);
  }
  if ((local_38[0] == 0) || (*(longlong *)pLVar1 == 0)) {
    *(undefined4 *)(this + 0x10) = 0xc0000017;
    if (local_38[0] == 0) {
      return this;
    }
  }
  else {
    lVar5 = local_38[0];
    RtlInitUnicodeString(local_38);
    iVar2 = WdmlibIoCreateDeviceSecure(param_1,lVar5,local_38);
    *(int *)(this + 0x10) = iVar2;
    if (-1 < iVar2) {
      **(undefined8 **)(*(longlong *)(this + 8) + 0x40) = this;
      RtlInitUnicodeString(local_38,local_38[0]);
      RtlInitUnicodeString(local_20,*(longlong *)pLVar1);
      uVar3 = IoCreateSymbolicLink(local_20,local_38);
      *(undefined4 *)(this + 0x10) = uVar3;
      this[0x14] = (LegacyDevice)((byte)((uint)uVar3 >> 0x1f) ^ 1);
      p_Var6 = param_1 + 0x70;
      for (lVar5 = 0x1c; lVar5 != 0; lVar5 = lVar5 + -1) {
        *(code **)p_Var6 = StaticDispatchRoutine;
        p_Var6 = p_Var6 + 8;
      }
    }
  }
  ExFreePoolWithTag(local_38[0],0x42505043);
  return this;
}



===== ~LegacyDevice @ 1c0003768 =====

/* public: virtual __cdecl LegacyDevice::~LegacyDevice(void) __ptr64 */

void __thiscall LegacyDevice::~LegacyDevice(LegacyDevice *this)

{
  LegacyDevice *pLVar1;
  undefined1 local_18 [16];
  
  *(undefined ***)this = &_vftable_;
  pLVar1 = this + 0x18;
  if (this[0x14] != (LegacyDevice)0x0) {
    RtlInitUnicodeString(local_18,*(longlong *)pLVar1);
    IoDeleteSymbolicLink(local_18);
    this[0x14] = (LegacyDevice)0x0;
  }
  if (*(longlong *)(this + 8) != 0) {
    IoDeleteDevice();
    *(undefined8 *)(this + 8) = 0;
  }
  if (*(longlong *)pLVar1 != 0) {
    ExFreePoolWithTag(*(longlong *)pLVar1,0x42505043);
    *(longlong *)pLVar1 = 0;
  }
  return;
}



===== `vector_deleting_destructor' @ 1c0003800 =====

/* public: virtual void * __ptr64 __cdecl LegacyDevice::`vector deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall LegacyDevice::_vector_deleting_destructor_(LegacyDevice *this,uint param_1)

{
  ~LegacyDevice(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x4a424f50);
  }
  return this;
}



===== ConcatenateStrings @ 1c0003844 =====

longlong * ConcatenateStrings(longlong *param_1,void *param_2)

{
  ulonglong uVar1;
  size_t _Size;
  void *_Dst;
  longlong lVar3;
  longlong lVar2;
  ulonglong uVar4;
  
  _Dst = (void *)0x0;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  lVar2 = -1;
  do {
    lVar3 = lVar2;
    lVar2 = lVar3 + 1;
  } while (*(short *)((longlong)param_2 + lVar2 * 2) != 0);
  uVar1 = lVar3 + 0x22;
  if (uVar1 != 0) {
    _Dst = (void *)ExAllocatePoolWithTag(1,uVar1 * 2,0x42505043);
    if (_Dst == (void *)0x0) {
      return param_1;
    }
    if ((void *)*param_1 != (void *)0x0) {
      uVar4 = uVar1;
      if ((ulonglong)param_1[2] <= uVar1) {
        uVar4 = param_1[2];
      }
      memcpy(_Dst,(void *)*param_1,uVar4 * 2);
      ExFreePoolWithTag(*param_1,0);
    }
    *param_1 = (longlong)_Dst;
    param_1[1] = uVar1;
  }
  _Size = lVar2 * 2;
  memcpy(_Dst,param_2,_Size);
  lVar2 = *param_1;
  builtin_wcsncpy((wchar_t *)(lVar2 + _Size),L"com_micr",8);
  builtin_wcsncpy((wchar_t *)(lVar2 + 0x10 + _Size),L"osoft_id",8);
  builtin_wcsncpy((wchar_t *)(lVar2 + 0x20 + _Size),L"na_ProcL",8);
  builtin_wcsncpy((wchar_t *)(lVar2 + 0x30 + _Size),L"aunchMon",8);
  *(undefined2 *)(lVar2 + 0x40 + _Size) = 0;
  return param_1;
}



===== DispatchRoutine @ 1c0003960 =====

/* protected: virtual void __cdecl LegacyDevice::DispatchRoutine(class IncomingIrpWrapper * __ptr64)
   __ptr64 */

void __thiscall LegacyDevice::DispatchRoutine(LegacyDevice *this,IncomingIrpWrapper *param_1)

{
  return;
}



===== StaticDispatchRoutine @ 1c0003970 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl LegacyDevice::StaticDispatchRoutine(struct _DEVICE_OBJECT *
   __ptr64,struct _IRP * __ptr64) */

long __cdecl LegacyDevice::StaticDispatchRoutine(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  longlong *plVar1;
  long lVar2;
  _IRP *local_18;
  longlong local_10;
  
  if ((param_1 == (_DEVICE_OBJECT *)0x0) || (param_2 == (_IRP *)0x0)) {
    lVar2 = -0x3ffffff3;
  }
  else {
    local_10 = *(longlong *)(param_2 + 0xb8);
    if ((local_10 == 0) ||
       (plVar1 = (longlong *)**(longlong **)(param_1 + 0x40), plVar1 == (longlong *)0x0)) {
      lVar2 = -0x3fffff1b;
    }
    else {
      *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
      local_18 = param_2;
      (**(code **)(*plVar1 + 8))(plVar1,&local_18);
      lVar2 = *(long *)(param_2 + 0x30);
      IofCompleteRequest(param_2,0);
    }
  }
  return lVar2;
}



===== WdmlibRtlInitUnicodeStringEx @ 1c00039f8 =====

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



===== LogFeatureUsedWithResult @ 1c0003a44 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl Telemetry::LogFeatureUsedWithResult(unsigned short const * __ptr64,unsigned short
   const * __ptr64,enum Telemetry::ErrorType,unsigned __int64,unsigned short const * __ptr64) */

void __cdecl
Telemetry::LogFeatureUsedWithResult
          (ushort *param_1,ushort *param_2,ErrorType param_3,__uint64 param_4,ushort *param_5)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 auStackY_108 [32];
  undefined4 local_d8 [2];
  __uint64 local_d0 [3];
  undefined8 local_b8 [4];
  __uint64 *local_98;
  undefined8 local_90;
  wchar_t *local_88;
  undefined8 local_80;
  wchar_t *local_78;
  int local_70;
  undefined4 local_6c;
  wchar_t *local_68;
  int local_60;
  undefined4 local_5c;
  _GUID *local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  __uint64 *local_38;
  undefined8 local_30;
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_108;
  if ((((g_isTelemetryInitialized) && (5 < DAT_1c0008090)) &&
      ((_DAT_1c00080a0 & 0x800000000000) != 0)) &&
     ((DAT_1c00080a8 & 0x800000000000) == DAT_1c00080a8)) {
    local_70 = 2;
    lVar1 = -1;
    local_d8[0] = 2;
    local_d0[1] = 0x2000000;
    if (param_5 == (ushort *)0x0) {
      local_20 = 2;
      param_5 = (ushort *)L"";
    }
    else {
      lVar2 = -1;
      do {
        lVar2 = lVar2 + 1;
      } while (param_5[lVar2] != 0);
      local_20 = (int)lVar2 * 2 + 2;
    }
    local_38 = local_d0;
    local_48 = local_d8;
    local_58 = &g_featureSessionID;
    local_1c = 0;
    local_30 = 8;
    local_40 = 4;
    local_50 = 0x10;
    if (param_2 == (ushort *)0x0) {
      local_60 = 2;
      param_2 = (ushort *)L"";
    }
    else {
      lVar2 = -1;
      do {
        lVar2 = lVar2 + 1;
      } while (param_2[lVar2] != 0);
      local_60 = (int)lVar2 * 2 + 2;
    }
    local_5c = 0;
    if (param_1 == (ushort *)0x0) {
      param_1 = (ushort *)L"";
    }
    else {
      do {
        lVar1 = lVar1 + 1;
      } while (param_1[lVar1] != 0);
      local_70 = (int)lVar1 * 2 + 2;
    }
    local_88 = L"TTDMonitorDriver";
    local_98 = local_d0 + 1;
    local_6c = 0;
    local_80 = 0x22;
    local_90 = 8;
    local_d0[0] = param_4;
    local_78 = (wchar_t *)param_1;
    local_68 = (wchar_t *)param_2;
    local_28 = (wchar_t *)param_5;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0008090,&DAT_1c0006991,0,0,10,local_b8);
  }
  return;
}



===== _tlgDefineProvider_annotation__Tlgg_DbgToolsTraceLoggingProviderProv @ 1c0003bf8 =====

void _tlgDefineProvider_annotation__Tlgg_DbgToolsTraceLoggingProviderProv(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0003c08 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c0003c2c =====

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



===== __cpu_features_init @ 1c0003ca0 =====

/* WARNING: Removing unreachable block (ram,0x0001c0003d0a) */
/* WARNING: Removing unreachable block (ram,0x0001c0003cb9) */
/* WARNING: Removing unreachable block (ram,0x0001c0003caa) */

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



===== __security_check_cookie @ 1c0003d70 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0003db0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0003de0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0003de0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0003e10 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0003e80 =====

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



===== memset @ 1c0004180 =====

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



===== __memset_repmovs @ 1c00042c0 =====

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



===== __memset_query @ 1c0004340 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c00043c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0004500 =====

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



===== __memset_spec_plain @ 1c0004580 =====

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



===== WdmlibIoCreateDeviceSecure @ 1c000b008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WdmlibIoCreateDeviceSecure(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
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
            (param_1,8,param_3,0x22,0x100,0,&SDDL_DEVOBJ_SYS_ALL_ADM_ALL,0,in_stack_00000048);
  return;
}



===== IoDevObjCreateDeviceSecure @ 1c000b100 =====

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
    if ((int)uVar5 < 0) goto LAB_1c000b260;
    uVar6 = 2;
    local_68 = CONCAT44(local_68._4_4_,2);
    lStack_60 = local_res18;
    if (param_8 != (undefined4 *)0x0) {
      local_50 = 2;
      local_40 = 0;
      local_48 = local_res18;
      uVar5 = PpRegStateUpdateStackCreationSettings(param_8,(longlong)&local_50);
      uVar4 = uVar5 & 0xffffffff;
      if ((int)uVar5 < 0) goto LAB_1c000b260;
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
LAB_1c000b260:
  if ((uVar6 & 2) != 0) {
    ExFreePoolWithTag(lStack_60,0);
  }
  return uVar4;
}



===== IopDevObjApplyPostCreationSettings @ 1c000b294 =====

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



===== SeSddlSecurityDescriptorFromSDDL @ 1c000b384 =====

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



===== SepSddlAddAceToAcl @ 1c000b464 =====

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



===== SepSddlDaclFromSDDLString @ 1c000b564 =====

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



===== SepSddlGetAclForString @ 1c000b650 =====

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
LAB_1c000b9eb:
              iVar5 = -0x3ffffff3;
LAB_1c000b9ed:
              lVar7 = *param_2;
              goto LAB_1c000b9d3;
            }
            for (pwVar6 = param_1 + 2; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
            }
            if (*pwVar6 != L';') goto LAB_1c000b9eb;
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
                ppuVar17 = &PTR_u_RC_1c0008000;
                do {
                  iVar4 = _wcsnicmp(pwVar6,(wchar_t *)*ppuVar17,(ulonglong)*(uint *)(ppuVar17 + 1));
                  if (iVar4 == 0) {
                    uVar15 = (uint)local_res8 | *(uint *)(&DAT_1c000800c + uVar11 * 0x10);
                    local_res8 = (short *)CONCAT44(local_res8._4_4_,uVar15);
                    local_58 = pwVar6 + (uint)(&DAT_1c0008008)[uVar11 * 4];
                    goto LAB_1c000b8dd;
                  }
                  uVar16 = (int)uVar11 + 1;
                  uVar11 = (ulonglong)uVar16;
                  ppuVar17 = ppuVar17 + 2;
                } while (uVar16 < 8);
                local_58 = pwVar6;
                SepSddlParseWideStringUlong((ushort *)pwVar6,&local_58,(uint *)&local_res8);
                if (local_58 == pwVar6) goto LAB_1c000b9eb;
                uVar15 = (uint)local_res8;
LAB_1c000b8dd:
                wVar3 = *local_58;
                pwVar6 = local_58;
              } while (wVar3 != L';');
              uVar16 = local_res18;
            }
            pwVar6 = pwVar6 + 1;
            if (iVar5 != 0) goto LAB_1c000b9ed;
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
            if (iVar5 != 0) goto LAB_1c000b9ed;
            for (; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
            }
            local_res8 = (short *)0x0;
            ppsVar13 = &local_res8;
            uVar9 = SepSddlGetSidForString(pwVar6,local_50,(longlong *)ppsVar13);
            iVar5 = (int)uVar9;
            if (iVar5 != 0) break;
            psVar12 = local_res8;
            if (local_res8 == (short *)0x0) {
LAB_1c000b95b:
              iVar5 = -0x3fffff89;
              goto LAB_1c000b9ed;
            }
            for (; *psVar12 == 0x20; psVar12 = psVar12 + 1) {
            }
            if (*psVar12 != 0x29) goto LAB_1c000b95b;
            param_1 = psVar12 + 1;
            if (local_50[0] != 0) {
              uVar9 = SepSddlAddAceToAcl(param_2,local_res20,ppsVar13,uVar14,uVar15,
                                         uVar16 - local_res10,local_50[0]);
              iVar5 = (int)uVar9;
              if (iVar5 != 0) goto LAB_1c000b9ed;
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
LAB_1c000b9d3:
        ExFreePoolWithTag(lVar7,0);
        *param_2 = 0;
        return iVar5;
      }
    }
    iVar5 = -0x3fffff66;
  }
  return iVar5;
}



===== SepSddlGetSidForString @ 1c000ba18 =====

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
  puVar5 = &DAT_1c0008124;
  uVar7 = 0;
  do {
    iVar2 = _wcsnicmp(param_1,(wchar_t *)(&DAT_1c000811c + uVar7 * 0x18),(ulonglong)*puVar5);
    if (iVar2 == 0) {
      iVar2 = *(int *)(&DAT_1c0008118 + uVar7 * 0x18);
      uVar6 = (&DAT_1c0008124)[uVar7 * 6];
      *param_3 = (longlong)(param_1 + uVar6);
      if (iVar2 == 1) {
        cVar1 = IoIsWdmVersionAvailable(1,CONCAT71((int7)((ulonglong)(param_1 + uVar6) >> 8),0x20));
        if (cVar1 != '\0') goto LAB_1c000baaf;
      }
      else {
LAB_1c000baaf:
        uVar4 = *(undefined8 *)
                 (*(longlong *)(&DAT_1c0008110 + uVar7 * 0x18) + *(longlong *)SeExports_exref);
      }
      uVar3 = 0;
      goto LAB_1c000bac4;
    }
    uVar6 = (int)uVar7 + 1;
    uVar7 = (ulonglong)uVar6;
    puVar5 = puVar5 + 6;
  } while (uVar6 < 0xe);
  uVar3 = 0xc0000073;
LAB_1c000bac4:
  *param_2 = uVar4;
  return uVar3;
}



===== SepSddlParseWideStringUlong @ 1c000baec =====

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
LAB_1c000bb6f:
      iVar7 = 10;
      uVar4 = 0;
      puVar8 = param_1;
      goto LAB_1c000bb4d;
    }
    param_1 = param_1 + 2;
    uVar6 = (uint)*param_1;
  }
  else if ((ushort)(uVar1 - 0x30) < 10) goto LAB_1c000bb6f;
  iVar7 = 0x10;
  puVar8 = param_1;
  uVar4 = 0;
  if ((short)uVar6 == 0) {
    return 0;
  }
LAB_1c000bb4d:
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



===== SepSddlSecurityDescriptorFromSDDLString @ 1c000bbf8 =====

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
        goto LAB_1c000bd3d;
      }
    }
  }
  if (local_58[0] != 0) {
    ExFreePoolWithTag(local_58[0],0);
  }
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
LAB_1c000bd3d:
  return (ulonglong)uVar2;
}



===== PiRegStateOpenClassKey @ 1c000bd9c =====

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
  uVar3 = CmRegUtilOpenExistingWstrKey(0,0x1c00067d0,0x20019,&local_b0);
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



===== PiRegStateReadStackCreationSettingsFromKey @ 1c000bf38 =====

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
  uVar2 = WdmlibRtlInitUnicodeStringEx((short *)local_50,0x1c0006750);
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
      if ((int)uVar3 < 0) goto LAB_1c000c0b7;
      if (local_res10[0] == '\0') {
        *param_2 = *param_2 | 2;
        *(longlong *)(param_2 + 2) = local_res20;
      }
      else {
        ExFreePoolWithTag(local_res20,0);
      }
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x1c0006768,param_3,param_2 + 1);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_1c000c0b7;
    }
    else {
      *param_2 = *param_2 | 1;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x1c0006780,param_3,param_2 + 4);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_1c000c0b7;
    }
    else {
      *param_2 = *param_2 | 4;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x1c00067b0,param_3,param_2 + 5);
    uVar5 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      *param_2 = *param_2 | 8;
      return uVar5;
    }
    if ((int)uVar3 == -0x3fffffcc) {
      return 0;
    }
  }
LAB_1c000c0b7:
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



===== PpRegStateReadCreateClassCreationSettings @ 1c000c0fc =====

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
    uVar1 = CmRegUtilOpenExistingWstrKey(local_res20,0x1c00066f0,0x20019,puVar6);
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
      uVar3 = WdmlibRtlInitUnicodeStringEx((short *)&local_18,0x1c0006708);
      uVar2 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        uVar1 = CmRegUtilUcValueSetUcString(uVar4,&local_18,puVar7);
        uVar2 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          local_res18[0] = 0x31;
          uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x1c0006718,(longlong)local_res18);
          uVar2 = (ulonglong)uVar1;
          if (-1 < (int)uVar1) {
            uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x1c0006738,(longlong)local_res18);
            uVar2 = (ulonglong)uVar1;
          }
        }
      }
    }
  }
  ZwClose(uVar4);
  return uVar2;
}



===== PpRegStateUpdateStackCreationSettings @ 1c000c260 =====

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
                      (local_res20,0x1c00066f0,uVar7,uVar2,puVar6,(undefined4 *)0x0,&local_38);
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
      uVar5 = WdmlibRtlInitUnicodeStringEx(local_30,0x1c0006750);
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



===== SeUtilSecurityInfoFromSecurityDescriptor @ 1c000c3c8 =====

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



===== CmRegUtilCreateWstrKey @ 1c000c4c4 =====

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



===== CmRegUtilOpenExistingWstrKey @ 1c000c594 =====

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



===== CmRegUtilUcValueGetFullBuffer @ 1c000c628 =====

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
    if (iVar1 < 0) goto LAB_1c000c760;
  }
  if (*(int *)((longlong)_Dst + 4) == 3) {
    *param_5 = _Dst;
    return 0;
  }
  iVar1 = -0x3fffffdc;
LAB_1c000c760:
  ExFreePoolWithTag(_Dst,0);
  return iVar1;
}



===== CmRegUtilUcValueSetUcString @ 1c000c7a4 =====

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



===== CmRegUtilWstrValueGetDword @ 1c000c8f0 =====

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



===== CmRegUtilWstrValueSetWstrString @ 1c000c994 =====

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



===== _tlgEnableCallback @ 1c000c9f0 =====

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



===== entry @ 1c000d010 =====

void entry(_DRIVER_OBJECT *param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 1c000d044 =====

void __cdecl __security_init_cookie(void)

{
  ulonglong uVar1;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    uVar1 = rdtsc();
    __security_cookie =
         ((CONCAT44((int)(__security_cookie >> 0x20),(int)uVar1) | uVar1 & 0xffffffff00000000) ^
         0x1c0008100) & 0xffffffffffff;
    if (__security_cookie == 0) {
      __security_cookie = 0x2b992ddfa232;
    }
  }
  __security_cookie_complement = ~__security_cookie;
  return;
}


