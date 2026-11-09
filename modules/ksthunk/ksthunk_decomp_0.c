
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



===== _purecall @ 140001020 =====

void _purecall(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001020. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _purecall();
  return;
}



===== __C_specific_handler @ 140001032 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140001032. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== ProbeForRead @ 140001044 =====

void ProbeForRead(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140001044. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ProbeForRead();
  return;
}



===== IndirectedQueryInterface @ 140001060 =====

/* public: virtual long __cdecl CBaseUnknown::IndirectedQueryInterface(struct _GUID const &
   __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CBaseUnknown::IndirectedQueryInterface(CBaseUnknown *this,_GUID *param_1,void **param_2)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140001060. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = IndirectedQueryInterface(this,param_1,param_2);
  return lVar1;
}



===== IndirectedRelease @ 140001080 =====

/* public: virtual unsigned long __cdecl CBaseUnknown::IndirectedRelease(void) __ptr64 */

ulong __thiscall CBaseUnknown::IndirectedRelease(CBaseUnknown *this)

{
  ulong uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140001080. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = IndirectedRelease(this);
  return uVar1;
}



===== IndirectedAddRef @ 1400010a0 =====

/* public: virtual unsigned long __cdecl CBaseUnknown::IndirectedAddRef(void) __ptr64 */

ulong __thiscall CBaseUnknown::IndirectedAddRef(CBaseUnknown *this)

{
  ulong uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400010a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = IndirectedAddRef(this);
  return uVar1;
}



===== NonDelegatedRelease @ 1400010c0 =====

/* public: virtual unsigned long __cdecl CBaseUnknown::NonDelegatedRelease(void) __ptr64 */

ulong __thiscall CBaseUnknown::NonDelegatedRelease(CBaseUnknown *this)

{
  ulong uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400010c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = NonDelegatedRelease(this);
  return uVar1;
}



===== NonDelegatedAddRef @ 1400010e0 =====

/* public: virtual unsigned long __cdecl CBaseUnknown::NonDelegatedAddRef(void) __ptr64 */

ulong __thiscall CBaseUnknown::NonDelegatedAddRef(CBaseUnknown *this)

{
  ulong uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400010e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = NonDelegatedAddRef(this);
  return uVar1;
}



===== RtlCopyFromUser @ 1400010f4 =====

/* WARNING: Removing unreachable block (ram,0x000140001118) */

void RtlCopyFromUser(void *param_1,void *param_2,size_t param_3)

{
  if (param_3 != 0) {
    ProbeForRead(param_2,param_3,1);
    RtlCopyVolatileMemory(param_1,param_2,param_3);
  }
  return;
}



===== _guard_check_icall @ 140001170 =====

void _guard_check_icall(void)

{
  return;
}



===== __cpu_features_init @ 140001190 =====

/* WARNING: Removing unreachable block (ram,0x0001400011fa) */
/* WARNING: Removing unreachable block (ram,0x0001400011a9) */
/* WARNING: Removing unreachable block (ram,0x00014000119a) */

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



===== DispatchIrpBridge @ 140001260 =====

/* public: static long __cdecl CKernelFilterDevice::DispatchIrpBridge(struct _DEVICE_OBJECT *
   __ptr64,struct _IRP * __ptr64) */

long __cdecl CKernelFilterDevice::DispatchIrpBridge(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  long lVar1;
  
  lVar1 = DispatchIrp((CKernelFilterDevice *)**(undefined8 **)(param_1 + 0x40),param_2,0);
  return lVar1;
}



===== `vector_deleting_destructor' @ 140001280 =====

/* public: virtual void * __ptr64 __cdecl CKernelFilterDevice::`vector deleting destructor'(unsigned
   int) __ptr64 */

void * __thiscall
CKernelFilterDevice::_vector_deleting_destructor_(CKernelFilterDevice *this,uint param_1)

{
  ~CKernelFilterDevice(this);
  if (((param_1 & 1) != 0) && (this != (CKernelFilterDevice *)0x0)) {
    ExFreePool(this);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 1400012d0 =====

/* public: virtual void * __ptr64 __cdecl CKernelFilterFile::`scalar deleting destructor'(unsigned
   int) __ptr64 */

void * __thiscall
CKernelFilterFile::_scalar_deleting_destructor_(CKernelFilterFile *this,uint param_1)

{
  ~CKernelFilterFile(this);
  if (((param_1 & 1) != 0) && (this != (CKernelFilterFile *)0x0)) {
    ExFreePool(this);
  }
  return this;
}



===== CallbackClientOnCompletion @ 140001320 =====

/* private: static long __cdecl CKernelFilterDevice::CallbackClientOnCompletion(struct
   _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64,class CKernelFilterDevice * __ptr64) */

long __cdecl
CKernelFilterDevice::CallbackClientOnCompletion
          (_DEVICE_OBJECT *param_1,_IRP *param_2,CKernelFilterDevice *param_3)

{
  long lVar1;
  
  lVar1 = DispatchIrp(param_3,param_2,1);
  return lVar1;
}



===== Initialize @ 140001340 =====

/* public: virtual long __cdecl CKernelFilterFile::Initialize(void) __ptr64 */

long __thiscall CKernelFilterFile::Initialize(CKernelFilterFile *this)

{
  return 0;
}



===== DeferIrpCompletion @ 140001350 =====

/* public: static long __cdecl CKernelFilterDevice::DeferIrpCompletion(struct _DEVICE_OBJECT *
   __ptr64,struct _IRP * __ptr64,struct _KEVENT * __ptr64) */

long __cdecl
CKernelFilterDevice::DeferIrpCompletion(_DEVICE_OBJECT *param_1,_IRP *param_2,_KEVENT *param_3)

{
  if (param_2[0x41] != (_IRP)0x0) {
    KeSetEvent(param_3,0,0);
  }
  return -0x3fffffea;
}



===== DispatchClose @ 140001390 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: virtual enum _IRP_DISPOSITION __cdecl CKernelFilterDevice::DispatchClose(struct _IRP *
   __ptr64,enum _IRP_STATUS,long * __ptr64) __ptr64 */

_IRP_DISPOSITION __thiscall
CKernelFilterDevice::DispatchClose
          (CKernelFilterDevice *this,_IRP *param_1,_IRP_STATUS param_2,long *param_3)

{
  _IRP_DISPOSITION _Var1;
  CKernelFilterFile *pCVar2;
  
  pCVar2 = FileObjectToFilterFile(this,param_1);
  if (pCVar2 == (CKernelFilterFile *)0x0) {
    _Var1 = 1;
  }
  else {
    _Var1 = (**(code **)(*(longlong *)pCVar2 + 0x10))(pCVar2,param_1,param_2,param_3);
  }
  return _Var1;
}



===== DispatchIoctl @ 1400013f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: virtual enum _IRP_DISPOSITION __cdecl CKernelFilterDevice::DispatchIoctl(struct _IRP *
   __ptr64,enum _IRP_STATUS,long * __ptr64) __ptr64 */

_IRP_DISPOSITION __thiscall
CKernelFilterDevice::DispatchIoctl
          (CKernelFilterDevice *this,_IRP *param_1,_IRP_STATUS param_2,long *param_3)

{
  _IRP_DISPOSITION _Var1;
  CKernelFilterFile *pCVar2;
  
  pCVar2 = FileObjectToFilterFile(this,param_1);
  if (pCVar2 == (CKernelFilterFile *)0x0) {
    _Var1 = 1;
  }
  else {
    _Var1 = (**(code **)(*(longlong *)pCVar2 + 0x28))(pCVar2,param_1,param_2,param_3);
  }
  return _Var1;
}



===== DispatchWrite @ 140001450 =====

/* public: virtual enum _IRP_DISPOSITION __cdecl CKernelFilterFile::DispatchWrite(struct _IRP *
   __ptr64,enum _IRP_STATUS,long * __ptr64) __ptr64 */

_IRP_DISPOSITION __thiscall
CKernelFilterFile::DispatchWrite
          (CKernelFilterFile *this,_IRP *param_1,_IRP_STATUS param_2,long *param_3)

{
  return 1;
}



===== DispatchIrp @ 140001460 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl CKernelFilterDevice::DispatchIrp(struct _IRP * __ptr64,enum _IRP_STATUS)
   __ptr64 */

long __thiscall
CKernelFilterDevice::DispatchIrp(CKernelFilterDevice *this,_IRP *param_1,_IRP_STATUS param_2)

{
  char cVar1;
  char *pcVar2;
  undefined8 *puVar3;
  longlong lVar4;
  int iVar5;
  long lVar6;
  code *pcVar7;
  undefined4 in_register_00000084;
  long local_res18 [2];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  if (param_2 == 0) {
    local_res18[0] = 0;
  }
  else {
    local_res18[0] = *(long *)(param_1 + 0x30);
  }
  pcVar2 = *(char **)(param_1 + 0xb8);
  cVar1 = *pcVar2;
  if (cVar1 == '\0') {
    pcVar7 = *(code **)(*(longlong *)this + 0x20);
LAB_1400014f9:
    iVar5 = (*pcVar7)(this,param_1,CONCAT44(in_register_00000084,param_2),local_res18);
    if (iVar5 == 0) {
      *(long *)(param_1 + 0x30) = local_res18[0];
      IofCompleteRequest(param_1,0);
      return local_res18[0];
    }
    if (iVar5 != 1) {
      if (iVar5 == 2) {
        return 0x103;
      }
      if (iVar5 == 3) {
        puVar3 = *(undefined8 **)(param_1 + 0xb8);
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
        lVar4 = *(longlong *)(param_1 + 0xb8);
        *(code **)(lVar4 + -0x10) = CallbackClientOnCompletion;
        *(CKernelFilterDevice **)(lVar4 + -8) = this;
        *(undefined1 *)(lVar4 + -0x45) = 0xe0;
      }
      else {
        if (iVar5 == 4) {
          local_18 = 0;
          local_28 = 0;
          uStack_20 = 0;
          KeInitializeEvent(&local_28,1,0);
          puVar3 = *(undefined8 **)(param_1 + 0xb8);
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
          lVar4 = *(longlong *)(param_1 + 0xb8);
          *(code **)(lVar4 + -0x10) = DeferIrpCompletion;
          *(undefined8 **)(lVar4 + -8) = &local_28;
          *(undefined1 *)(lVar4 + -0x45) = 0xe0;
          if (*pcVar2 == '\x16') {
            local_res18[0] = PoCallDriver(*(undefined8 *)(this + 0x38),param_1);
          }
          else {
            local_res18[0] = IofCallDriver();
          }
          if (local_res18[0] == 0x103) {
            KeWaitForSingleObject(&local_28,0,0,0,0);
          }
          lVar6 = DispatchIrp(this,param_1,2);
          return lVar6;
        }
        if (iVar5 != 5) {
          return local_res18[0];
        }
      }
      goto LAB_140001538;
    }
  }
  else {
    if (cVar1 == '\x02') {
      pcVar7 = *(code **)(*(longlong *)this + 0x28);
      goto LAB_1400014f9;
    }
    if (cVar1 == '\x03') {
      pcVar7 = *(code **)(*(longlong *)this + 0x30);
      goto LAB_1400014f9;
    }
    if (cVar1 == '\x04') {
      pcVar7 = *(code **)(*(longlong *)this + 0x38);
      goto LAB_1400014f9;
    }
    if (cVar1 == '\x0e') {
      pcVar7 = *(code **)(*(longlong *)this + 0x40);
      goto LAB_1400014f9;
    }
    if (cVar1 == '\x16') {
      pcVar7 = *(code **)(*(longlong *)this + 0x18);
      goto LAB_1400014f9;
    }
    if (cVar1 == '\x1b') {
      pcVar7 = *(code **)(*(longlong *)this + 0x10);
      goto LAB_1400014f9;
    }
  }
  puVar3 = *(undefined8 **)(param_1 + 0xb8);
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
LAB_140001538:
  if (*pcVar2 == '\x16') {
    lVar6 = PoCallDriver(*(undefined8 *)(this + 0x38),param_1);
  }
  else {
    lVar6 = IofCallDriver();
  }
  return lVar6;
}



===== DispatchPower @ 140001700 =====

/* protected: virtual enum _IRP_DISPOSITION __cdecl CKernelFilterDevice::DispatchPower(struct _IRP *
   __ptr64,enum _IRP_STATUS,long * __ptr64) __ptr64 */

_IRP_DISPOSITION __thiscall
CKernelFilterDevice::DispatchPower
          (CKernelFilterDevice *this,_IRP *param_1,_IRP_STATUS param_2,long *param_3)

{
  PoStartNextPowerIrp(param_1);
  return 1;
}



===== DispatchRead @ 140001730 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: virtual enum _IRP_DISPOSITION __cdecl CKernelFilterDevice::DispatchRead(struct _IRP *
   __ptr64,enum _IRP_STATUS,long * __ptr64) __ptr64 */

_IRP_DISPOSITION __thiscall
CKernelFilterDevice::DispatchRead
          (CKernelFilterDevice *this,_IRP *param_1,_IRP_STATUS param_2,long *param_3)

{
  _IRP_DISPOSITION _Var1;
  CKernelFilterFile *pCVar2;
  
  pCVar2 = FileObjectToFilterFile(this,param_1);
  if (pCVar2 == (CKernelFilterFile *)0x0) {
    _Var1 = 1;
  }
  else {
    _Var1 = (**(code **)(*(longlong *)pCVar2 + 0x18))(pCVar2,param_1,param_2,param_3);
  }
  return _Var1;
}



===== DispatchWrite @ 140001790 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: virtual enum _IRP_DISPOSITION __cdecl CKernelFilterDevice::DispatchWrite(struct _IRP *
   __ptr64,enum _IRP_STATUS,long * __ptr64) __ptr64 */

_IRP_DISPOSITION __thiscall
CKernelFilterDevice::DispatchWrite
          (CKernelFilterDevice *this,_IRP *param_1,_IRP_STATUS param_2,long *param_3)

{
  _IRP_DISPOSITION _Var1;
  CKernelFilterFile *pCVar2;
  
  pCVar2 = FileObjectToFilterFile(this,param_1);
  if (pCVar2 == (CKernelFilterFile *)0x0) {
    _Var1 = 1;
  }
  else {
    _Var1 = (**(code **)(*(longlong *)pCVar2 + 0x20))(pCVar2,param_1,param_2,param_3);
  }
  return _Var1;
}



===== FileObjectToFilterFile @ 1400017ec =====

/* public: class CKernelFilterFile * __ptr64 __cdecl
   CKernelFilterDevice::FileObjectToFilterFile(struct _IRP * __ptr64) __ptr64 */

CKernelFilterFile * __thiscall
CKernelFilterDevice::FileObjectToFilterFile(CKernelFilterDevice *this,_IRP *param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  CKernelFilterDevice *pCVar3;
  CKernelFilterDevice *pCVar4;
  CKernelFilterFile *pCVar5;
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x30);
  uVar2 = KeAcquireSpinLockRaiseToDpc(this + 8);
  pCVar4 = this + 0x10;
  pCVar3 = *(CKernelFilterDevice **)pCVar4;
  if (pCVar3 != (CKernelFilterDevice *)0x0) {
    do {
      if (pCVar3 == pCVar4) goto LAB_140001852;
      pCVar5 = (CKernelFilterFile *)(pCVar3 + -8);
    } while ((*(longlong *)(pCVar3 + 0x10) != lVar1) &&
            (pCVar3 = *(CKernelFilterDevice **)pCVar3, pCVar3 != (CKernelFilterDevice *)0x0));
    if ((pCVar3 != (CKernelFilterDevice *)0x0) && (pCVar3 != pCVar4)) goto LAB_140001854;
  }
LAB_140001852:
  pCVar5 = (CKernelFilterFile *)0x0;
LAB_140001854:
  KeReleaseSpinLock(this + 8,uVar2);
  return pCVar5;
}



===== NotifyDestroyFile @ 140001884 =====

/* public: long __cdecl CKernelFilterDevice::NotifyDestroyFile(class CKernelFilterFile * __ptr64)
   __ptr64 */

long __thiscall
CKernelFilterDevice::NotifyDestroyFile(CKernelFilterDevice *this,CKernelFilterFile *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined1 uVar4;
  long lVar5;
  CKernelFilterFile *pCVar6;
  
  uVar4 = KeAcquireSpinLockRaiseToDpc(this + 8);
  pCVar6 = param_1 + 8;
  lVar1 = *(longlong *)pCVar6;
  if ((*(CKernelFilterFile **)(lVar1 + 8) == pCVar6) &&
     (plVar2 = *(longlong **)(param_1 + 0x10), (CKernelFilterFile *)*plVar2 == pCVar6)) {
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    *(longlong *)pCVar6 = 0;
    KeReleaseSpinLock(this + 8,CONCAT71((int7)((ulonglong)plVar2 >> 8),uVar4));
    return 0;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  lVar5 = (*pcVar3)();
  return lVar5;
}



===== NotifyNewFile @ 1400018f4 =====

/* private: long __cdecl CKernelFilterDevice::NotifyNewFile(class CKernelFilterFile * __ptr64)
   __ptr64 */

long __thiscall
CKernelFilterDevice::NotifyNewFile(CKernelFilterDevice *this,CKernelFilterFile *param_1)

{
  code *pcVar1;
  undefined1 uVar2;
  longlong *plVar3;
  undefined1 *puVar4;
  CKernelFilterFile *pCVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(this + 8);
  puVar4 = auStack_28;
  plVar3 = *(longlong **)(this + 0x18);
  pCVar5 = param_1 + 8;
  if ((CKernelFilterDevice *)*plVar3 != this + 0x10) {
    plVar3 = (longlong *)0x3;
    pcVar1 = (code *)swi(0x29);
    uVar2 = (*pcVar1)();
    puVar4 = auStack_20;
  }
  *(longlong **)(param_1 + 0x10) = plVar3;
  *(CKernelFilterDevice **)pCVar5 = this + 0x10;
  *plVar3 = (longlong)pCVar5;
  *(CKernelFilterFile **)(this + 0x18) = pCVar5;
  *(undefined8 *)(puVar4 + -8) = 0x14000194e;
  KeReleaseSpinLock(this + 8,uVar2);
  return 0;
}



===== IsDeviceFilterable @ 140001970 =====

/* protected: virtual bool __cdecl CKernelFilterDriver::IsDeviceFilterable(struct _DEVICE_OBJECT *
   __ptr64,long & __ptr64) __ptr64 */

bool __thiscall
CKernelFilterDriver::IsDeviceFilterable
          (CKernelFilterDriver *this,_DEVICE_OBJECT *param_1,long *param_2)

{
  return true;
}



===== `scalar_deleting_destructor' @ 140001980 =====

/* public: virtual void * __ptr64 __cdecl CKSThunkDriver::`scalar deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall CKSThunkDriver::_scalar_deleting_destructor_(CKSThunkDriver *this,uint param_1)

{
  *(undefined ***)this = &CKernelFilterDriver::_vftable_;
  if ((param_1 & 1) != 0) {
    ExFreePool();
  }
  return this;
}



===== ConnectionState @ 1400019c0 =====

/* protected: virtual long __cdecl CKSAutomationThunk::ConnectionState(struct _IRP * __ptr64,struct
   KSIDENTIFIER * __ptr64,enum KSSTATE * __ptr64) __ptr64 */

long __thiscall
CKSAutomationThunk::ConnectionState
          (CKSAutomationThunk *this,_IRP *param_1,KSIDENTIFIER *param_2,KSSTATE *param_3)

{
  return -0x3ffffddb;
}



===== wil_details_RecordCachedUsage @ 1400019d0 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140001b20 =====

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



===== AttachToStack @ 140001bb0 =====

/* public: virtual long __cdecl CKSThunkDevice::AttachToStack(struct _DEVICE_OBJECT * __ptr64)
   __ptr64 */

long __thiscall CKSThunkDevice::AttachToStack(CKSThunkDevice *this,_DEVICE_OBJECT *param_1)

{
  long lVar1;
  
  lVar1 = CKernelFilterDevice::AttachToStack((CKernelFilterDevice *)this,param_1);
  if ((-1 < lVar1) && (*(char *)(*(longlong *)(this + 0x28) + 0x4c) < '\a')) {
    *(undefined1 *)(*(longlong *)(this + 0x28) + 0x4c) = 7;
  }
  return lVar1;
}



===== CheckIrpForStackAdjustmentNative @ 140001be0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: enum _IRP_DISPOSITION __cdecl CKSThunkDevice::CheckIrpForStackAdjustmentNative(struct
   _IRP * __ptr64,enum _IRP_STATUS,long * __ptr64) __ptr64 */

_IRP_DISPOSITION __thiscall
CKSThunkDevice::CheckIrpForStackAdjustmentNative
          (CKSThunkDevice *this,_IRP *param_1,_IRP_STATUS param_2,long *param_3)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  bool bVar5;
  long lVar6;
  ulonglong uVar7;
  _IRP_DISPOSITION _Var8;
  undefined4 local_res18 [2];
  long *local_res20;
  longlong local_68;
  longlong lStack_60;
  ulonglong local_58;
  undefined8 local_50;
  longlong local_48;
  undefined8 local_40;
  undefined8 local_38;
  
  lVar2 = *(longlong *)(param_1 + 0xb8);
  _Var8 = 1;
  local_68 = 0;
  lStack_60 = 0;
  local_58 = 0;
  local_res18[0] = 0;
  lVar3 = *(longlong *)(this + 0x38);
  cVar1 = *(char *)(lVar3 + 0x4c);
  if (0x17 < *(uint *)(lVar2 + 0x10)) {
    local_res20 = param_3;
    uVar7 = Feature_Servicing_KS_UMA__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar7 == 0) {
      if (param_1[0x40] != (_IRP)0x0) {
        ProbeForRead(*(undefined8 *)(lVar2 + 0x20),*(undefined4 *)(lVar2 + 0x10),1);
      }
      plVar4 = *(longlong **)(lVar2 + 0x20);
      local_68 = *plVar4;
      lStack_60 = plVar4[1];
      local_58 = plVar4[2];
    }
    else if (param_1[0x40] == (_IRP)0x0) {
      RtlCopyVolatileMemory(&local_68,*(void **)(lVar2 + 0x20),0x18);
    }
    else {
      RtlCopyFromUser(&local_68,*(void **)(lVar2 + 0x20),0x18);
    }
    if ((local_68 == 0x4fac41982f2c8ddd) && (lStack_60 == 0x6deb705bb6129ba)) {
      bVar5 = true;
    }
    else {
      bVar5 = false;
    }
    if (((bVar5) && ((int)local_58 == 0)) && ((local_58 >> 0x20 & 2) != 0)) {
      if (param_1[0x40] == (_IRP)0x0) {
        local_50 = 0;
        local_40 = *(undefined8 *)(lVar2 + 0x30);
        local_48 = lVar3;
        local_38 = local_40;
        lVar6 = (**(code **)(*(longlong *)(lVar2 + 0x20) + 0x38))
                          (**(undefined4 **)(param_1 + 0x70),0,&local_50);
      }
      else {
        lVar6 = -0x3ffffff0;
      }
      *param_3 = lVar6;
      _Var8 = 0;
    }
    if ((local_68 == 0x11cfac9b1d58c920) && (lStack_60 == 0xc104db28d6a5)) {
      bVar5 = true;
    }
    else {
      bVar5 = false;
    }
    if (((bVar5) && ((int)local_58 == 0)) &&
       (((local_58 & 0x200000000) != 0 && (3 < *(uint *)(lVar2 + 8))))) {
      uVar7 = Feature_Servicing_KS_UMA__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar7 == 0) {
        if (param_1[0x40] != (_IRP)0x0) {
          ProbeForRead(*(undefined8 *)(param_1 + 0x70),4,1);
        }
        local_res18[0] = **(undefined4 **)(param_1 + 0x70);
      }
      else if (param_1[0x40] == (_IRP)0x0) {
        RtlCopyVolatileMemory(local_res18,*(void **)(param_1 + 0x70),4);
      }
      else {
        RtlCopyFromUser(local_res18,*(void **)(param_1 + 0x70),4);
      }
      KeWaitForSingleObject(this + 0x48,0,0,0,0);
      lVar6 = CKernelFilterDevice::SynchronousForwardIrp((CKernelFilterDevice *)this,param_1);
      *param_3 = lVar6;
      if ((-1 < lVar6) && (cVar1 != *(char *)(lVar3 + 0x4c))) {
        *(char *)(*(longlong *)(this + 0x28) + 0x4c) = *(char *)(lVar3 + 0x4c) + '\x01';
      }
      KeReleaseMutex(this + 0x48,0);
      _Var8 = 0;
    }
  }
  return _Var8;
}



===== CreateFilterFile @ 140001e60 =====

/* public: virtual class CKernelFilterFile * __ptr64 __cdecl CKSThunkDevice::CreateFilterFile(struct
   _IRP * __ptr64) __ptr64 */

CKernelFilterFile * __thiscall CKSThunkDevice::CreateFilterFile(CKSThunkDevice *this,_IRP *param_1)

{
  longlong lVar1;
  longlong lVar2;
  CKSThunkPin *this_00;
  CKernelFilterFile *pCVar3;
  
  lVar1 = *(longlong *)(param_1 + 0xb8);
  lVar2 = *(longlong *)(param_1 + 0x18);
  this_00 = (CKSThunkPin *)ExAllocatePoolWithTag(0x200,0x80,0x774e434b);
  pCVar3 = (CKernelFilterFile *)0x0;
  if (this_00 != (CKSThunkPin *)0x0) {
    memset(this_00,0,0x80);
    pCVar3 = (CKernelFilterFile *)
             CKSThunkPin::CKSThunkPin
                       (this_00,*(_FILE_OBJECT **)(lVar1 + 0x30),this,(KSDATAFORMAT *)(lVar2 + 0x48)
                       );
  }
  return pCVar3;
}



===== DispatchCreate @ 140001ef0 =====

/* public: virtual enum _IRP_DISPOSITION __cdecl CKSThunkDevice::DispatchCreate(struct _IRP *
   __ptr64,enum _IRP_STATUS,long * __ptr64) __ptr64 */

_IRP_DISPOSITION __thiscall
CKSThunkDevice::DispatchCreate(CKSThunkDevice *this,_IRP *param_1,_IRP_STATUS param_2,long *param_3)

{
  uint uVar1;
  undefined8 *puVar2;
  ulonglong *puVar3;
  ushort uVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  char cVar16;
  _IRP_DISPOSITION _Var17;
  int iVar18;
  int iVar19;
  void *_Dst;
  uint uVar20;
  ulonglong uVar21;
  ulonglong *_Src;
  uint uVar22;
  ulonglong uVar23;
  
  if (param_2 != 0) goto LAB_140001f28;
  lVar5 = *(longlong *)(param_1 + 0xb8);
  if (*(longlong *)(*(longlong *)(lVar5 + 0x30) + 0x40) == 0) {
    return 1;
  }
  cVar16 = IoIs32bitProcess(param_1);
  if ((cVar16 == '\0') && (cVar16 = IoIsInitiator32bitProcess(param_1), cVar16 == '\0')) {
    uVar21 = 0xffffffffffffffff;
    do {
      uVar21 = uVar21 + 1;
    } while (L"{146F1A80-4791-11D0-A5D6-28DB04C10000}"[uVar21] != L'\0');
    if ((ulonglong)*(ushort *)(*(longlong *)(lVar5 + 0x30) + 0x58) <
        (ulonglong)((int)uVar21 * 2 + 0x4a) + 0x40) {
      return 1;
    }
    iVar18 = _wcsnicmp(*(wchar_t **)(*(longlong *)(lVar5 + 0x30) + 0x60),
                       L"{146F1A80-4791-11D0-A5D6-28DB04C10000}",uVar21 & 0xffffffff);
    if (iVar18 != 0) {
      return 1;
    }
    param_2 = 0;
    goto LAB_140001f28;
  }
  lVar5 = *(longlong *)(lVar5 + 0x30);
  uVar21 = 0xffffffffffffffff;
  do {
    uVar21 = uVar21 + 1;
  } while (L"{146F1A80-4791-11D0-A5D6-28DB04C10000}"[uVar21] != L'\0');
  iVar18 = (int)uVar21 * 2;
  uVar1 = iVar18 + 0x42;
  if ((ulonglong)*(ushort *)(lVar5 + 0x58) < (ulonglong)uVar1 + 0x40) {
    return 1;
  }
  uVar23 = uVar21 & 0xffffffff;
  iVar19 = _wcsnicmp(*(wchar_t **)(lVar5 + 0x60),L"{146F1A80-4791-11D0-A5D6-28DB04C10000}",
                     uVar21 & 0xffffffff);
  if (iVar19 != 0) {
    return 1;
  }
  lVar6 = *(longlong *)(lVar5 + 0x60);
  lVar7 = uVar23 * 2;
  puVar2 = (undefined8 *)(lVar7 + 2 + lVar6);
  uVar8 = *puVar2;
  uVar9 = puVar2[1];
  puVar2 = (undefined8 *)(lVar7 + 0x12 + lVar6);
  uVar14 = *puVar2;
  uVar15 = puVar2[1];
  _Src = (ulonglong *)(lVar6 + 0x42 + lVar7);
  puVar3 = (ulonglong *)(lVar7 + 0x32 + lVar6);
  uVar10 = *puVar3;
  uVar11 = puVar3[1];
  uVar21 = *_Src;
  puVar2 = (undefined8 *)(lVar7 + 0x22 + lVar6);
  uVar12 = *puVar2;
  uVar13 = puVar2[1];
  iVar19 = (int)uVar21;
  if (iVar19 - 0x40U < 0x3a59) {
    uVar4 = *(ushort *)(lVar5 + 0x58);
    if (uVar1 + iVar19 <= (uint)uVar4) {
      if ((uVar21 >> 0x20 & 2) == 0) {
LAB_1400020ce:
        uVar1 = iVar18 + 0x4a;
        uVar20 = uVar1 + (int)uVar21;
        if ((uVar1 <= uVar20) && (uVar20 < 0x10000)) {
          _Dst = (void *)ExAllocatePoolWithTag(0x600,uVar20,0x6474534b);
          if (_Dst == (void *)0x0) {
            *param_3 = -0x3fffff66;
            return 0;
          }
          memmove(_Dst,L"{146F1A80-4791-11D0-A5D6-28DB04C10000}",uVar23 * 2);
          lVar6 = uVar23 * 2;
          puVar2 = (undefined8 *)(lVar6 + 2 + (longlong)_Dst);
          *puVar2 = uVar8;
          puVar2[1] = uVar9;
          *(undefined2 *)(lVar6 + (longlong)_Dst) = 0x5c;
          puVar2 = (undefined8 *)(lVar6 + 0x12 + (longlong)_Dst);
          *puVar2 = uVar14;
          puVar2[1] = uVar15;
          puVar2 = (undefined8 *)(lVar6 + 0x22 + (longlong)_Dst);
          *puVar2 = uVar12;
          puVar2[1] = uVar13;
          puVar3 = (ulonglong *)(lVar6 + 0x32 + (longlong)_Dst);
          *puVar3 = uVar10 & 0xffffffff;
          puVar3[1] = uVar10 >> 0x20;
          *(ulonglong *)(lVar6 + 0x42 + (longlong)_Dst) = uVar11;
          memmove((void *)(uVar23 * 2 + 0x4a + (longlong)_Dst),_Src,uVar21 & 0xffffffff);
          ExFreePool(*(undefined8 *)(lVar5 + 0x60));
          param_2 = 0;
          *(short *)(lVar5 + 0x5a) = (short)uVar20;
          *(short *)(lVar5 + 0x58) = (short)uVar20;
          *(void **)(lVar5 + 0x60) = _Dst;
LAB_140001f28:
          _Var17 = CKernelFilterDevice::DispatchCreate
                             ((CKernelFilterDevice *)this,param_1,param_2,param_3);
          return _Var17;
        }
        goto LAB_1400021fc;
      }
      uVar20 = iVar19 + 7U & 0xfffffff8;
      if (((ulonglong)(uVar20 + uVar1) + 8 <= (ulonglong)uVar4) &&
         (uVar22 = (uint)*(undefined8 *)((ulonglong)uVar20 + (longlong)_Src), 7 < uVar22)) {
        uVar22 = uVar22 + uVar20;
        uVar21 = (ulonglong)uVar22;
        if (uVar22 < uVar20) goto LAB_1400021fc;
        if (uVar22 <= uVar4 - uVar1) goto LAB_1400020ce;
      }
    }
    *param_3 = -0x3fffffff;
  }
  else {
LAB_1400021fc:
    *param_3 = -0x3ffffff3;
  }
  return 0;
}



===== DispatchIoctl @ 140002240 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual enum _IRP_DISPOSITION __cdecl CKSThunkDevice::DispatchIoctl(struct _IRP *
   __ptr64,enum _IRP_STATUS,long * __ptr64) __ptr64 */

_IRP_DISPOSITION __thiscall
CKSThunkDevice::DispatchIoctl(CKSThunkDevice *this,_IRP *param_1,_IRP_STATUS param_2,long *param_3)

{
  int iVar1;
  longlong lVar2;
  char cVar3;
  _IRP_DISPOSITION _Var4;
  CKernelFilterFile *pCVar5;
  _IRP_STATUS _Var6;
  
  lVar2 = *(longlong *)(param_1 + 0xb8);
  _Var6 = param_2;
  pCVar5 = CKernelFilterDevice::FileObjectToFilterFile((CKernelFilterDevice *)this,param_1);
  if (pCVar5 != (CKernelFilterFile *)0x0) {
    _Var4 = (**(code **)(*(longlong *)pCVar5 + 0x28))(pCVar5,param_1,param_2,param_3);
    return _Var4;
  }
  cVar3 = IoIs32bitProcess(param_1);
  if ((cVar3 == '\0') || (param_1[0x40] == (_IRP)0x0)) {
    if (*(int *)(lVar2 + 0x18) == 0x2f0003) {
      _Var4 = CheckIrpForStackAdjustmentNative(this,param_1,_Var6,param_3);
      return _Var4;
    }
  }
  else {
    iVar1 = *(int *)(lVar2 + 0x18);
    if (iVar1 == 0x2f0003) {
      _Var4 = CKSAutomationThunk::ThunkPropertyIrp
                        ((CKSAutomationThunk *)(this + 0x40),param_1,_Var6,param_3);
      return _Var4;
    }
    if (iVar1 == 0x2f0007) {
      _Var4 = CKSAutomationThunk::ThunkEnableEventIrp
                        ((CKSAutomationThunk *)0x0,param_1,_Var6,param_3);
      return _Var4;
    }
    if (iVar1 == 0x2f000b) {
      _Var4 = CKSAutomationThunk::ThunkDisableEventIrp
                        ((CKSAutomationThunk *)0x4,param_1,_Var6,param_3);
      return _Var4;
    }
  }
  return 1;
}



===== ProceedToCreateFilterFile @ 140002330 =====

/* public: virtual bool __cdecl CKSThunkDevice::ProceedToCreateFilterFile(struct _IRP * __ptr64)
   __ptr64 */

bool __thiscall CKSThunkDevice::ProceedToCreateFilterFile(CKSThunkDevice *this,_IRP *param_1)

{
  if ((*(uint *)(param_1 + 0x10) & 0x10) == 0) {
    return false;
  }
  return *(longlong *)(param_1 + 0x18) != 0;
}



===== Feature_Servicing_KS_UMA__private_IsEnabledDeviceUsageNoInline @ 14000234c =====

ulonglong Feature_Servicing_KS_UMA__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_Servicing_KS_UMA__private_featureState;
  if ((Feature_Servicing_KS_UMA__private_featureState & 0x10) == 0) {
    uVar1 = Feature_Servicing_KS_UMA__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_Servicing_KS_UMA__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_Servicing_KS_UMA__private_IsEnabledFallback @ 140002384 =====

void Feature_Servicing_KS_UMA__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_Servicing_KS_UMA__private_descriptor);
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 1400023a0 =====

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
LAB_1400025a3:
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
LAB_14000247b:
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
      if (param_3 == 4) goto LAB_1400025a3;
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
        goto LAB_14000247b;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 14000268c =====

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
      goto LAB_14000275d;
    }
    if (param_3 == 2) {
      uVar3 = (uVar2 ^ 1) * 4 + 1;
      goto LAB_14000275d;
    }
    if (param_3 == 3) {
      uVar3 = (uVar2 ^ 1) * 4 + 2;
      goto LAB_14000275d;
    }
    if (param_3 == 4) {
      uVar3 = (uVar2 ^ 1) * 4 + 3;
      goto LAB_14000275d;
    }
    if (param_3 == 5) {
      uVar3 = (uVar2 ^ 1) * 2 + 8;
      goto LAB_14000275d;
    }
    if (param_3 == 6) {
      uVar3 = (uVar2 ^ 1) * 2 + 9;
      goto LAB_14000275d;
    }
    bVar4 = (char)param_3 + 0x9c;
    if (bVar4 < 0x32) {
      uVar3 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar4;
      goto LAB_14000275d;
    }
  }
  uVar3 = 0xff;
LAB_14000275d:
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



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 1400027b4 =====

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



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 1400028a4 =====

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
LAB_140002957:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_140002985;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_140002957;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_140002985:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140002b10 =====

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



===== wil_details_IsEnabledFallback @ 140002b74 =====

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



===== `vector_deleting_destructor'`adjustor{8}' @ 140002c10 =====

/* [thunk]:public: virtual void * __ptr64 __cdecl CVideoCaptureThunkHandler::`vector deleting
   destructor'`adjustor{8}' (unsigned int) __ptr64 */

void * __thiscall
CVideoCaptureThunkHandler::_vector_deleting_destructor__adjustor_8__
          (CVideoCaptureThunkHandler *this,uint param_1)

{
  void *pvVar1;
  
  pvVar1 = _vector_deleting_destructor_(this + -8,param_1);
  return pvVar1;
}



===== `scalar_deleting_destructor' @ 140002c20 =====

/* private: virtual void * __ptr64 __cdecl CKSThunkPin::`scalar deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall CKSThunkPin::_scalar_deleting_destructor_(CKSThunkPin *this,uint param_1)

{
  ~CKSThunkPin(this);
  if (((param_1 & 1) != 0) && (this != (CKSThunkPin *)0x0)) {
    ExFreePool(this);
  }
  return this;
}



===== `vector_deleting_destructor' @ 140002c64 =====

/* public: virtual void * __ptr64 __cdecl CVideoCaptureThunkHandler::`vector deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
CVideoCaptureThunkHandler::_vector_deleting_destructor_
          (CVideoCaptureThunkHandler *this,uint param_1)

{
  *(undefined ***)this = &_vftable_;
  *(undefined ***)(this + 8) = &_vftable__for__INonDelegatedUnknown__;
  *(undefined ***)(this + 0x10) = &_vftable__for__IIndirectedUnknown__;
  CBaseUnknown::~CBaseUnknown((CBaseUnknown *)(this + 8));
  if ((param_1 & 1) != 0) {
    ExFreePool(this);
  }
  return this;
}



===== CancelStreamingIrp @ 140002cd0 =====

/* private: static void __cdecl CKSThunkPin::CancelStreamingIrp(struct _DEVICE_OBJECT *
   __ptr64,struct _IRP * __ptr64) */

void __cdecl CKSThunkPin::CancelStreamingIrp(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  undefined8 uVar1;
  bool bVar2;
  
  uVar1 = *(undefined8 *)(param_2 + 0x78);
  IoReleaseCancelSpinLock(param_2[0x45]);
  IoCancelIrp(uVar1);
  LOCK();
  bVar2 = *(longlong *)(param_2 + 0x88) == 0;
  if (bVar2) {
    *(_IRP **)(param_2 + 0x88) = param_2;
  }
  UNLOCK();
  if (!bVar2) {
    IoFreeIrp(uVar1);
    IofCompleteRequest(param_2,0);
  }
  return;
}



===== DispatchIoctl @ 140002d40 =====

/* public: virtual enum _IRP_DISPOSITION __cdecl CKSThunkPin::DispatchIoctl(struct _IRP *
   __ptr64,enum _IRP_STATUS,long * __ptr64) __ptr64 */

_IRP_DISPOSITION __thiscall
CKSThunkPin::DispatchIoctl(CKSThunkPin *this,_IRP *param_1,_IRP_STATUS param_2,long *param_3)

{
  int iVar1;
  char cVar2;
  _IRP_DISPOSITION _Var3;
  _IRP *this_00;
  _IRP_STATUS _Var4;
  
  this_00 = param_1;
  _Var4 = param_2;
  cVar2 = IoIs32bitProcess();
  if ((cVar2 != '\0') && (param_1[0x40] != (_IRP)0x0)) {
    iVar1 = *(int *)(*(longlong *)(param_1 + 0xb8) + 0x18);
    if (iVar1 == 0x2f0003) {
      _Var3 = CKSAutomationThunk::ThunkPropertyIrp
                        ((CKSAutomationThunk *)(this + 0x28),param_1,_Var4,param_3);
      return _Var3;
    }
    if (iVar1 == 0x2f0007) {
      _Var3 = CKSAutomationThunk::ThunkEnableEventIrp
                        ((CKSAutomationThunk *)this_00,param_1,_Var4,param_3);
      return _Var3;
    }
    if (iVar1 == 0x2f000b) {
      _Var3 = CKSAutomationThunk::ThunkDisableEventIrp
                        ((CKSAutomationThunk *)this_00,param_1,_Var4,param_3);
      return _Var3;
    }
    if ((iVar1 == 0x2f4017) || (iVar1 == 0x2f8013)) {
      _Var3 = ThunkStreamingIrp(this,param_1,param_2,param_3);
      return _Var3;
    }
  }
  return 1;
}



===== GetExtendedHeaderSize @ 140002e08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: unsigned long __cdecl CKSThunkPin::GetExtendedHeaderSize(unsigned long,unsigned long)
   __ptr64 */

ulong __thiscall CKSThunkPin::GetExtendedHeaderSize(CKSThunkPin *this,ulong param_1,ulong param_2)

{
  longlong *plVar1;
  ulong uVar2;
  ulonglong uVar3;
  bool bVar4;
  
  uVar3 = Feature_3149374777__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 != 0) {
    KeEnterCriticalRegion();
    ExAcquirePushLockSharedEx(this + 0x68,0);
    plVar1 = *(longlong **)(this + 0x70);
    if (plVar1 != (longlong *)0x0) {
      (**(code **)(*plVar1 + 8))(plVar1);
    }
    ExReleasePushLockSharedEx(this + 0x68,0);
    KeLeaveCriticalRegion();
    if (plVar1 == (longlong *)0x0) {
      if (((param_1 >> 0xc & 1) != 0) &&
         (bVar4 = param_2 + 0x10 < param_2, param_2 = param_2 + 0x10, bVar4)) {
        return 0;
      }
    }
    else {
      param_2 = (**(code **)(*plVar1 + 0x20))(plVar1,param_1,1);
    }
    uVar3 = Feature_3149374777__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar3 != 0) && (plVar1 != (longlong *)0x0)) {
      (**(code **)(*plVar1 + 0x10))(plVar1);
    }
    return param_2;
  }
  plVar1 = *(longlong **)(this + 0x70);
  if (plVar1 != (longlong *)0x0) {
    uVar2 = (**(code **)(*plVar1 + 0x20))(plVar1,param_1,1);
    return uVar2;
  }
  if ((param_1 >> 0xc & 1) == 0) {
    return param_2;
  }
  if (param_2 + 0x10 < param_2) {
    return 0;
  }
  return param_2 + 0x10;
}



===== GetExtendedHeaderSizeForHandler @ 140002f28 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong GetExtendedHeaderSizeForHandler(uint param_1,uint param_2,longlong *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  
  if (param_3 == (longlong *)0x0) {
    uVar1 = param_2;
    if (((param_1 >> 0xc & 1) != 0) && (uVar1 = param_2 + 0x10, uVar1 < param_2)) {
      return 0;
    }
    uVar2 = (ulonglong)uVar1;
  }
  else {
    uVar2 = (**(code **)(*param_3 + 0x20))(param_3,param_1,1);
  }
  return uVar2;
}



===== GetMetadataBuffer32 @ 140002f6c =====

/* struct KSSTREAM_METADATA_INFO32 * __ptr64 __cdecl GetMetadataBuffer32(struct _KSSTREAM_HEADER32 *
   __ptr64) */

KSSTREAM_METADATA_INFO32 * __cdecl GetMetadataBuffer32(_KSSTREAM_HEADER32 *param_1)

{
  return (KSSTREAM_METADATA_INFO32 *)
         (-(ulonglong)((*(uint *)(param_1 + 0x2c) & 0x1000) != 0) & (ulonglong)(param_1 + 0x70));
}



===== GetMetadataBuffer64 @ 140002f88 =====

/* struct KSSTREAM_METADATA_INFO * __ptr64 __cdecl GetMetadataBuffer64(struct KSSTREAM_HEADER *
   __ptr64) */

KSSTREAM_METADATA_INFO * __cdecl GetMetadataBuffer64(KSSTREAM_HEADER *param_1)

{
  return (KSSTREAM_METADATA_INFO *)
         (-(ulonglong)((*(uint *)(param_1 + 0x30) & 0x1000) != 0) & (ulonglong)(param_1 + 0x80));
}



===== ReleaseStreamingFormatHandler @ 140002fb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl CKSThunkPin::ReleaseStreamingFormatHandler(struct _DEVICE_OBJECT *
   __ptr64,void * __ptr64) */

void __cdecl CKSThunkPin::ReleaseStreamingFormatHandler(_DEVICE_OBJECT *param_1,void *param_2)

{
  (**(code **)(**(longlong **)((longlong)param_2 + 0x10) + 0x10))();
  *(undefined8 *)((longlong)param_2 + 0x10) = 0;
  IoFreeWorkItem(*(undefined8 *)((longlong)param_2 + 0x18));
  *(undefined8 *)((longlong)param_2 + 0x18) = 0;
  ExFreePool(param_2);
  return;
}



===== ReverseThunkExtendedHeader @ 140003000 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl CKSThunkPin::ReverseThunkExtendedHeader(unsigned long,void * __ptr64,void *
   __ptr64,unsigned long,unsigned long,struct IKsWOW64FormatThunk * __ptr64) __ptr64 */

void __thiscall
CKSThunkPin::ReverseThunkExtendedHeader
          (CKSThunkPin *this,ulong param_1,void *param_2,void *param_3,ulong param_4,ulong param_5,
          IKsWOW64FormatThunk *param_6)

{
  ulonglong uVar1;
  
  uVar1 = Feature_3149374777__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar1 == 0) {
    if (param_5 == 0) {
      return;
    }
    if (param_4 == 0) {
      return;
    }
    param_6 = *(IKsWOW64FormatThunk **)(this + 0x70);
  }
  else {
    if (param_5 == 0) {
      return;
    }
    if (param_4 == 0) {
      return;
    }
  }
  if (param_6 == (IKsWOW64FormatThunk *)0x0) {
    if (param_5 <= param_4) {
      param_4 = param_5;
    }
    memmove(param_2,param_3,(ulonglong)param_4);
  }
  else {
    (**(code **)(*(longlong *)param_6 + 0x30))(param_6,param_1,param_3,param_2);
  }
  return;
}



===== ThunkExtendedHeaderForHandler @ 1400030a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
ThunkExtendedHeaderForHandler
          (void *param_1,void *param_2,uint param_3,uint param_4,longlong *param_5)

{
  if (param_4 != 0) {
    if (param_5 == (longlong *)0x0) {
      if (param_4 != param_3) {
        return 0xc000000d;
      }
      memmove(param_1,param_2,(ulonglong)param_4);
    }
    else {
      (**(code **)(*param_5 + 0x28))(param_5,param_2,param_1);
    }
  }
  return 0;
}



===== ThunkStreamingIrpCompletion @ 140003100 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static long __cdecl CKSThunkPin::ThunkStreamingIrpCompletion(struct _DEVICE_OBJECT *
   __ptr64,struct _IRP * __ptr64,struct _IRP * __ptr64) */

long __cdecl
CKSThunkPin::ThunkStreamingIrpCompletion(_DEVICE_OBJECT *param_1,_IRP *param_2,_IRP *param_3)

{
  longlong lVar1;
  uint uVar2;
  uint *puVar3;
  undefined8 *puVar4;
  char cVar5;
  ulonglong uVar6;
  IKsWOW64FormatThunk *pIVar7;
  uint *puVar8;
  int iVar9;
  uint uVar10;
  uint *puVar11;
  uint *puVar12;
  bool bVar13;
  
  LOCK();
  lVar1 = *(longlong *)(param_3 + 0x68);
  *(longlong *)(param_3 + 0x68) = 0;
  UNLOCK();
  puVar3 = *(uint **)(param_2 + 0x70);
  iVar9 = *(int *)(param_2 + 0x30);
  puVar8 = puVar3 + -8;
  if (*puVar8 == 0x2f4017) {
    if (-1 < iVar9) {
      puVar12 = *(uint **)(param_3 + 0x18);
      puVar11 = puVar3;
      for (uVar10 = puVar3[-7]; uVar10 != 0; uVar10 = uVar10 - uVar2) {
        puVar12[1] = puVar11[1];
        *(undefined8 *)(puVar12 + 2) = *(undefined8 *)(puVar11 + 2);
        puVar12[4] = puVar11[4];
        puVar12[5] = puVar11[5];
        *(undefined8 *)(puVar12 + 6) = *(undefined8 *)(puVar11 + 6);
        puVar12[9] = puVar11[9];
        puVar12[0xb] = puVar11[0xc];
        uVar6 = Feature_3149374777__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar6 == 0) {
          pIVar7 = (IKsWOW64FormatThunk *)0x0;
        }
        else {
          pIVar7 = *(IKsWOW64FormatThunk **)(puVar3 + -4);
        }
        ReverseThunkExtendedHeader
                  (*(CKSThunkPin **)(puVar3 + -6),puVar11[0xc],puVar12 + 0xc,puVar11 + 0xe,
                   *puVar12 - 0x30,*puVar11 - 0x38,pIVar7);
        puVar12 = (uint *)((longlong)puVar12 + (ulonglong)*puVar12);
        uVar2 = *puVar11;
        puVar11 = (uint *)((longlong)puVar11 + (ulonglong)uVar2);
      }
    }
    if ((*puVar8 == 0x2f4017) && (iVar9 == -0x3ffff8e4)) {
      iVar9 = 0;
      *(undefined1 *)(*(longlong *)(param_2 + 0x80) + 0x7c) = 0;
    }
  }
  uVar6 = Feature_3149374777__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar6 != 0) && (*(longlong *)(puVar3 + -4) != 0)) {
    uVar6 = Feature_Servicing_KsThunk_Release__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar6 == 0) {
      (**(code **)(**(longlong **)(puVar3 + -4) + 0x10))();
      puVar3[-4] = 0;
      puVar3[-3] = 0;
    }
    else {
      cVar5 = KeGetCurrentIrql();
      if (cVar5 == '\0') {
        ReleaseStreamingFormatHandler(param_1,puVar8);
      }
      else {
        IoQueueWorkItem(*(undefined8 *)(puVar3 + -2),ReleaseStreamingFormatHandler,1,puVar8);
      }
      puVar8 = (uint *)0x0;
    }
  }
  uVar6 = Feature_Servicing_KsThunk_Release__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar6 == 0) || (puVar8 != (uint *)0x0)) {
    ExFreePool(puVar8);
  }
  while (puVar4 = *(undefined8 **)(param_2 + 8), puVar4 != (undefined8 *)0x0) {
    if ((*(byte *)((longlong)puVar4 + 10) & 2) != 0) {
      MmUnlockPages(puVar4);
    }
    *(undefined8 *)(param_2 + 8) = *puVar4;
    IoFreeMdl(puVar4);
  }
  *(int *)(param_3 + 0x30) = iVar9;
  if (-1 < iVar9) {
    *(ulonglong *)(param_3 + 0x38) = (ulonglong)*(uint *)(*(longlong *)(param_3 + 0xb8) + 8);
  }
  if (lVar1 == 0) {
    LOCK();
    bVar13 = *(longlong *)(param_3 + 0x88) == 0;
    if (bVar13) {
      *(_IRP **)(param_3 + 0x88) = param_3;
    }
    UNLOCK();
    if (bVar13) {
      return -0x3fffffea;
    }
  }
  IoFreeIrp(param_2);
  IofCompleteRequest(param_3,0);
  return -0x3fffffea;
}



===== Feature_3149374777__private_IsEnabledDeviceUsageNoInline @ 140003348 =====

ulonglong Feature_3149374777__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_3149374777__private_featureState;
  if ((Feature_3149374777__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3149374777__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3149374777__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3149374777__private_IsEnabledFallback @ 140003380 =====

void Feature_3149374777__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_3149374777__private_descriptor);
  return;
}



===== Feature_Servicing_KSTHUNK_UMA__private_IsEnabledDeviceUsageNoInline @ 14000339c =====

ulonglong Feature_Servicing_KSTHUNK_UMA__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_Servicing_KSTHUNK_UMA__private_featureState;
  if ((Feature_Servicing_KSTHUNK_UMA__private_featureState & 0x10) == 0) {
    uVar1 = Feature_Servicing_KSTHUNK_UMA__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_Servicing_KSTHUNK_UMA__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_Servicing_KSTHUNK_UMA__private_IsEnabledFallback @ 1400033d4 =====

void Feature_Servicing_KSTHUNK_UMA__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_Servicing_KSTHUNK_UMA__private_descriptor);
  return;
}



===== Feature_Servicing_KsThunk_Release__private_IsEnabledDeviceUsageNoInline @ 1400033f0 =====

ulonglong Feature_Servicing_KsThunk_Release__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_Servicing_KsThunk_Release__private_featureState;
  if ((Feature_Servicing_KsThunk_Release__private_featureState & 0x10) == 0) {
    uVar1 = Feature_Servicing_KsThunk_Release__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_Servicing_KsThunk_Release__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_Servicing_KsThunk_Release__private_IsEnabledFallback @ 140003428 =====

void Feature_Servicing_KsThunk_Release__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_Servicing_KsThunk_Release__private_descriptor);
  return;
}



===== HandleArrayProperty @ 140003450 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl CKSAutomationThunk::HandleArrayProperty(struct _IRP * __ptr64,struct
   KSIDENTIFIER * __ptr64,unsigned int * __ptr64) */

long __cdecl
CKSAutomationThunk::HandleArrayProperty(_IRP *param_1,KSIDENTIFIER *param_2,uint *param_3)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong *puVar5;
  ulonglong *puVar6;
  uint uVar7;
  uint *puVar8;
  undefined1 auStack_98 [32];
  undefined4 local_78;
  ulonglong *local_70;
  uint local_68;
  uint *local_60;
  uint local_58 [2];
  KSIDENTIFIER *local_50;
  undefined4 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_98;
  puVar8 = param_3 + 1;
  lVar1 = *(longlong *)(param_1 + 0xb8);
  uVar7 = 0;
  local_58[0] = 0;
  local_50 = param_2;
  if ((*(uint *)(param_2 + 0x14) & 2) == 0) {
    local_60 = local_58;
    local_78 = *(undefined4 *)(lVar1 + 0x10);
    local_68 = 0;
    local_70 = (ulonglong *)0x0;
    iVar2 = KsSynchronousIoControlDevice(*(undefined8 *)(lVar1 + 0x30),0,0x2f0003,param_2);
    if (iVar2 < 0) {
      return iVar2;
    }
    if (*(int *)(lVar1 + 8) == 0) {
      *(ulonglong *)(param_1 + 0x38) = (ulonglong)(local_58[0] >> 1);
      return iVar2;
    }
    puVar5 = (ulonglong *)ExAllocatePoolWithTag(0x600,local_58[0],0x6268534b);
    if (puVar5 != (ulonglong *)0x0) {
      local_60 = local_58;
      local_68 = local_58[0];
      local_78 = *(undefined4 *)(lVar1 + 0x10);
      local_70 = puVar5;
      iVar2 = KsSynchronousIoControlDevice(*(undefined8 *)(lVar1 + 0x30),0,0x2f0003,local_50);
      if (-1 < iVar2) {
        uVar3 = (uint)*puVar5 + 1;
        if (((uVar3 < (uint)*puVar5) || (uVar4 = (ulonglong)uVar3 * 4, 0xffffffff < uVar4)) ||
           (*(uint *)(lVar1 + 8) < (uint)uVar4)) {
          local_50 = (KSIDENTIFIER *)0x1036a412d;
          local_48 = 0xc000000d;
          RtlLogUnexpectedCodepath(&local_50,iVar2);
          iVar2 = -0x3ffffff3;
        }
        else {
          uVar4 = *puVar5;
          *param_3 = (uint)uVar4;
          uVar3 = 0;
          puVar6 = puVar5;
          if ((uint)uVar4 != 0) {
            do {
              puVar6 = puVar6 + 1;
              uVar7 = uVar7 + 1;
              *puVar8 = (uint)*puVar6;
              uVar3 = *param_3;
              puVar8 = puVar8 + 1;
            } while (uVar7 < uVar3);
          }
          *(ulonglong *)(param_1 + 0x38) = (ulonglong)(uVar3 + 1) << 2;
        }
      }
      goto LAB_1400036e8;
    }
  }
  else {
    uVar4 = Feature_Servicing_KsThunk_Array__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 == 0) {
      uVar3 = *param_3 + 1;
      if (uVar3 < *param_3) {
        return -0x3fffff6b;
      }
      if (0xffffffff < (ulonglong)uVar3 * 4) {
        return -0x3fffff6b;
      }
      uVar4 = (ulonglong)uVar3 * 8;
      if (0xffffffff < uVar4) {
        return -0x3fffff6b;
      }
      if (*(uint *)(lVar1 + 8) < 4) {
        return -0x3ffffff3;
      }
      if (*(uint *)(lVar1 + 8) < (uint)((ulonglong)uVar3 * 4)) {
        return -0x3ffffff3;
      }
    }
    else {
      if (*(uint *)(lVar1 + 8) < 4) {
        return -0x3ffffff3;
      }
      uVar3 = *param_3 + 1;
      if (uVar3 < *param_3) {
        return -0x3fffff6b;
      }
      if (0xffffffff < (ulonglong)uVar3 * 4) {
        return -0x3fffff6b;
      }
      uVar4 = (ulonglong)uVar3 * 8;
      if (0xffffffff < uVar4) {
        return -0x3fffff6b;
      }
      if (*(uint *)(lVar1 + 8) < (uint)((ulonglong)uVar3 * 4)) {
        return -0x3ffffff3;
      }
    }
    puVar5 = (ulonglong *)ExAllocatePoolWithTag(0x600,uVar4 & 0xffffffff,0x6268534b);
    if (puVar5 != (ulonglong *)0x0) {
      *puVar5 = (ulonglong)*param_3;
      puVar6 = puVar5;
      if (*param_3 != 0) {
        do {
          puVar6 = puVar6 + 1;
          uVar7 = uVar7 + 1;
          *puVar6 = (ulonglong)*puVar8;
          puVar8 = puVar8 + 1;
        } while (uVar7 < *param_3);
      }
      local_60 = local_58;
      local_78 = *(undefined4 *)(lVar1 + 0x10);
      local_70 = puVar5;
      local_68 = (uint)uVar4;
      iVar2 = KsSynchronousIoControlDevice(*(undefined8 *)(lVar1 + 0x30),0,0x2f0003,param_2);
LAB_1400036e8:
      ExFreePool(puVar5);
      return iVar2;
    }
  }
  return -0x3fffff66;
}



===== HandleNotificationEventRegistrationProperty @ 140003730 =====

/* public: static long __cdecl
   CKSAutomationThunk::HandleNotificationEventRegistrationProperty(struct _IRP * __ptr64,struct
   KSIDENTIFIER * __ptr64) */

long __cdecl
CKSAutomationThunk::HandleNotificationEventRegistrationProperty(_IRP *param_1,KSIDENTIFIER *param_2)

{
  long lVar1;
  undefined4 local_res8 [8];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_18 = *(undefined4 *)(param_2 + 0x10);
  local_28 = *(undefined4 *)param_2;
  uStack_24 = *(undefined4 *)(param_2 + 4);
  uStack_20 = *(undefined4 *)(param_2 + 8);
  uStack_1c = *(undefined4 *)(param_2 + 0xc);
  local_14 = *(undefined4 *)(param_2 + 0x14);
  local_10 = (ulonglong)*(uint *)(param_2 + 0x18);
  local_res8[0] = 0;
  lVar1 = KsSynchronousIoControlDevice
                    (*(undefined8 *)(*(longlong *)(param_1 + 0xb8) + 0x30),0,0x2f0003,&local_28,0x20
                     ,0,0,local_res8);
  return lVar1;
}



===== HandleProperty @ 1400037b0 =====

/* public: static long __cdecl CKSAutomationThunk::HandleProperty(struct _IRP * __ptr64,struct
   KSIDENTIFIER * __ptr64,unsigned int * __ptr64) */

long __cdecl CKSAutomationThunk::HandleProperty(_IRP *param_1,KSIDENTIFIER *param_2,uint *param_3)

{
  int iVar1;
  undefined4 local_res8 [2];
  ulonglong local_res10;
  
  local_res10 = 0;
  local_res8[0] = 0;
  if ((*(uint *)(param_2 + 0x14) & 2) != 0) {
    local_res10 = (ulonglong)*param_3;
  }
  iVar1 = KsSynchronousIoControlDevice
                    (*(undefined8 *)(*(longlong *)(param_1 + 0xb8) + 0x30),0,0x2f0003,param_2,
                     *(undefined4 *)(*(longlong *)(param_1 + 0xb8) + 0x10),&local_res10,8,local_res8
                    );
  if ((-1 < iVar1) && ((*(uint *)(param_2 + 0x14) & 1) != 0)) {
    *param_3 = (uint)local_res10;
  }
  return iVar1;
}



===== HandleWaveRTBufferProperty @ 140003850 =====

/* public: static long __cdecl CKSAutomationThunk::HandleWaveRTBufferProperty(struct _IRP *
   __ptr64,struct KSIDENTIFIER * __ptr64,struct KSRTAUDIO_BUFFER32 * __ptr64) */

long __cdecl
CKSAutomationThunk::HandleWaveRTBufferProperty
          (_IRP *param_1,KSIDENTIFIER *param_2,KSRTAUDIO_BUFFER32 *param_3)

{
  int iVar1;
  undefined4 local_res8 [2];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 local_24;
  ulonglong local_20;
  undefined4 local_18;
  undefined4 local_14;
  
  local_28 = *(undefined4 *)(param_2 + 0x10);
  local_38 = *(undefined4 *)param_2;
  uStack_34 = *(undefined4 *)(param_2 + 4);
  uStack_30 = *(undefined4 *)(param_2 + 8);
  uStack_2c = *(undefined4 *)(param_2 + 0xc);
  local_res8[0] = 0;
  local_14 = 0;
  local_24 = *(undefined4 *)(param_2 + 0x14);
  local_20 = (ulonglong)*(uint *)(param_2 + 0x18);
  local_18 = *(undefined4 *)(param_2 + 0x1c);
  local_48 = 0;
  uStack_40 = 0;
  iVar1 = KsSynchronousIoControlDevice
                    (*(undefined8 *)(*(longlong *)(param_1 + 0xb8) + 0x30),0,0x2f0003,&local_38,0x28
                     ,&local_48,0x10,local_res8);
  if ((-1 < iVar1) && ((*(uint *)(param_2 + 0x14) & 1) != 0)) {
    *(undefined4 *)param_3 = (undefined4)local_48;
    *(undefined4 *)(param_3 + 4) = (undefined4)uStack_40;
    *(undefined4 *)(param_3 + 8) = uStack_40._4_4_;
  }
  return iVar1;
}



===== HandleWaveRTBufferWithNotificationProperty @ 140003920 =====

/* public: static long __cdecl CKSAutomationThunk::HandleWaveRTBufferWithNotificationProperty(struct
   _IRP * __ptr64,struct KSIDENTIFIER * __ptr64,struct KSRTAUDIO_BUFFER32 * __ptr64) */

long __cdecl
CKSAutomationThunk::HandleWaveRTBufferWithNotificationProperty
          (_IRP *param_1,KSIDENTIFIER *param_2,KSRTAUDIO_BUFFER32 *param_3)

{
  int iVar1;
  undefined4 local_res8 [2];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 local_24;
  ulonglong local_20;
  undefined4 local_18;
  undefined4 local_14;
  
  local_28 = *(undefined4 *)(param_2 + 0x10);
  local_38 = *(undefined4 *)param_2;
  uStack_34 = *(undefined4 *)(param_2 + 4);
  uStack_30 = *(undefined4 *)(param_2 + 8);
  uStack_2c = *(undefined4 *)(param_2 + 0xc);
  local_res8[0] = 0;
  local_24 = *(undefined4 *)(param_2 + 0x14);
  local_20 = (ulonglong)*(uint *)(param_2 + 0x18);
  local_18 = *(undefined4 *)(param_2 + 0x1c);
  local_14 = *(undefined4 *)(param_2 + 0x20);
  local_48 = 0;
  uStack_40 = 0;
  iVar1 = KsSynchronousIoControlDevice
                    (*(undefined8 *)(*(longlong *)(param_1 + 0xb8) + 0x30),0,0x2f0003,&local_38,0x28
                     ,&local_48,0x10,local_res8);
  if ((-1 < iVar1) && ((*(uint *)(param_2 + 0x14) & 1) != 0)) {
    *(undefined4 *)param_3 = (undefined4)local_48;
    *(undefined4 *)(param_3 + 4) = (undefined4)uStack_40;
    *(undefined4 *)(param_3 + 8) = uStack_40._4_4_;
  }
  return iVar1;
}



===== HandleWaveRTHWRegisterProperty @ 1400039f0 =====

/* public: static long __cdecl CKSAutomationThunk::HandleWaveRTHWRegisterProperty(struct _IRP *
   __ptr64,struct KSIDENTIFIER * __ptr64,struct KSRTAUDIO_HWREGISTER32 * __ptr64) */

long __cdecl
CKSAutomationThunk::HandleWaveRTHWRegisterProperty
          (_IRP *param_1,KSIDENTIFIER *param_2,KSRTAUDIO_HWREGISTER32 *param_3)

{
  int iVar1;
  undefined4 local_res8 [2];
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 local_44;
  ulonglong local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_res8[0] = 0;
  local_18 = 0;
  local_48 = *(undefined4 *)(param_2 + 0x10);
  local_44 = *(undefined4 *)(param_2 + 0x14);
  local_40 = (ulonglong)*(uint *)(param_2 + 0x18);
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_58 = *(undefined4 *)param_2;
  uStack_54 = *(undefined4 *)(param_2 + 4);
  uStack_50 = *(undefined4 *)(param_2 + 8);
  uStack_4c = *(undefined4 *)(param_2 + 0xc);
  iVar1 = KsSynchronousIoControlDevice
                    (*(undefined8 *)(*(longlong *)(param_1 + 0xb8) + 0x30),0,0x2f0003,&local_58,0x20
                     ,&local_38,0x28,local_res8);
  if ((-1 < iVar1) && ((*(uint *)(param_2 + 0x14) & 1) != 0)) {
    *(undefined4 *)param_3 = (undefined4)local_38;
    *(undefined4 *)(param_3 + 4) = (undefined4)uStack_30;
    *(undefined8 *)(param_3 + 8) = local_28;
    *(undefined8 *)(param_3 + 0x10) = uStack_20;
    *(undefined4 *)(param_3 + 0x18) = (undefined4)local_18;
  }
  return iVar1;
}



===== RouteConnectionState @ 140003ad0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl CKSAutomationThunk::RouteConnectionState(struct _IRP * __ptr64,struct
   KSIDENTIFIER * __ptr64,enum KSSTATE * __ptr64) */

long __cdecl
CKSAutomationThunk::RouteConnectionState(_IRP *param_1,KSIDENTIFIER *param_2,KSSTATE *param_3)

{
  long lVar1;
  
  lVar1 = (**(code **)(**(longlong **)(param_1 + 0x80) + 8))
                    (*(longlong **)(param_1 + 0x80),param_1,param_2,param_3);
  return lVar1;
}



===== RouteDataFormat @ 140003b00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl CKSAutomationThunk::RouteDataFormat(struct _IRP * __ptr64,struct
   KSIDENTIFIER * __ptr64,union KSDATAFORMAT * __ptr64) */

long __cdecl
CKSAutomationThunk::RouteDataFormat(_IRP *param_1,KSIDENTIFIER *param_2,KSDATAFORMAT *param_3)

{
  long lVar1;
  
  lVar1 = (**(code **)**(undefined8 **)(param_1 + 0x80))
                    (*(undefined8 **)(param_1 + 0x80),param_1,param_2,param_3);
  return lVar1;
}



===== ThunkDisableEventIrp @ 140003b30 =====

/* protected: enum _IRP_DISPOSITION __cdecl CKSAutomationThunk::ThunkDisableEventIrp(struct _IRP *
   __ptr64,enum _IRP_STATUS,long * __ptr64) __ptr64 */

_IRP_DISPOSITION __thiscall
CKSAutomationThunk::ThunkDisableEventIrp
          (CKSAutomationThunk *this,_IRP *param_1,_IRP_STATUS param_2,long *param_3)

{
  uint uVar1;
  uint uVar2;
  undefined8 *puVar3;
  
  puVar3 = *(undefined8 **)(param_1 + 0xb8);
  if (*(uint *)(puVar3 + 2) == 0) {
    return 1;
  }
  if (*(uint *)(puVar3 + 2) < 0x10) {
    *param_3 = -0x3ffffdfa;
  }
  else {
    puVar3[-9] = *puVar3;
    puVar3[-8] = puVar3[1];
    puVar3[-7] = puVar3[2];
    puVar3[-6] = puVar3[3];
    puVar3[-5] = puVar3[4];
    puVar3[-4] = puVar3[5];
    puVar3[-3] = puVar3[6];
    *(undefined1 *)((longlong)puVar3 + -0x45) = 0;
    uVar2 = *(uint *)(*(longlong *)(param_1 + 0xb8) + -0x38);
    uVar1 = uVar2 + 0x10;
    if (uVar2 <= uVar1) {
      *(uint *)(*(longlong *)(param_1 + 0xb8) + -0x38) = uVar1;
      return 5;
    }
    *param_3 = -0x3ffffff3;
  }
  return 0;
}



===== ThunkEnableEventIrp @ 140003ba8 =====

/* protected: enum _IRP_DISPOSITION __cdecl CKSAutomationThunk::ThunkEnableEventIrp(struct _IRP *
   __ptr64,enum _IRP_STATUS,long * __ptr64) __ptr64 */

_IRP_DISPOSITION __thiscall
CKSAutomationThunk::ThunkEnableEventIrp
          (CKSAutomationThunk *this,_IRP *param_1,_IRP_STATUS param_2,long *param_3)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  int *piVar4;
  bool bVar5;
  long *plVar6;
  uint uVar7;
  int iVar8;
  ulonglong uVar9;
  void *_Dst;
  undefined8 *puVar10;
  undefined8 uVar11;
  void *_Src;
  _IRP_DISPOSITION _Var12;
  _IRP_DISPOSITION _Var13;
  uint uVar14;
  ulonglong _Size;
  ulonglong local_res8;
  _IRP *local_res10;
  _IRP_STATUS local_res18;
  long *local_res20;
  int local_90;
  uint uStack_8c;
  uint auStack_88 [4];
  undefined8 *local_78;
  void *local_70;
  ulonglong local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong uStack_48;
  
  _Var13 = 1;
  bVar5 = false;
  local_78 = (undefined8 *)0x0;
  _Dst = (void *)0x0;
  local_70 = (void *)0x0;
  local_res8 = (ulonglong)this & 0xffffffff00000000;
  lVar3 = *(longlong *)(param_1 + 0xb8);
  uVar1 = *(uint *)(lVar3 + 0x10);
  local_68 = (ulonglong)uVar1;
  uVar2 = *(uint *)(lVar3 + 8);
  _Size = (ulonglong)uVar2;
  auStack_88[3] = uVar2 + 0x10;
  if (auStack_88[3] < uVar2) {
    *param_3 = -0x3ffffff3;
    return 0;
  }
  uVar14 = uVar2 + 0x17 & 0xfffffff8;
  if (*(longlong *)(param_1 + 0x18) != 0) {
    return 1;
  }
  local_res20 = param_3;
  local_res10 = param_1;
  local_res18 = param_2;
  if (uVar1 < 0x18) {
                    /* WARNING: Subroutine does not return */
    ExRaiseStatus(0xc0000206);
  }
  ProbeForRead(*(undefined8 *)(lVar3 + 0x20),local_68,1);
  uVar9 = Feature_Servicing_KSTHUNK_UMA__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar9 == 0) {
    local_res18 = *(uint *)(*(longlong *)(lVar3 + 0x20) + 0x14);
  }
  else {
    uVar9 = RtlReadULongFromUser((uint *)(*(longlong *)(lVar3 + 0x20) + 0x14));
    local_res18 = (_IRP_STATUS)uVar9;
  }
  uVar7 = local_res18 & 0xefffffff;
  if (((uVar7 == 1) || (uVar7 == 2)) || (uVar7 == 4)) {
    if (uVar2 < 0x10) {
                    /* WARNING: Subroutine does not return */
      ExRaiseStatus(0xc0000206);
    }
    if ((uVar14 < uVar2 + 0x10) || (uVar1 + uVar14 < uVar14)) {
                    /* WARNING: Subroutine does not return */
      ExRaiseStatus(0xc0000206);
    }
    uVar11 = ExAllocatePool2(0x61,uVar1 + uVar14,0x7070534b);
    *(undefined8 *)(param_1 + 0x18) = uVar11;
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x30;
    local_90 = 0;
    uStack_8c = 0;
    auStack_88[0] = 0;
    auStack_88[1] = 0;
    uVar9 = Feature_Servicing_KSTHUNK_UMA__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar9 == 0) {
      ProbeForRead(*(void **)(param_1 + 0x70),_Size,1);
      piVar4 = *(int **)(param_1 + 0x70);
      local_90 = *piVar4;
      uStack_8c = piVar4[1];
      auStack_88[0] = piVar4[2];
      auStack_88[1] = piVar4[3];
    }
    else {
      RtlCopyFromUser(&local_90,*(void **)(param_1 + 0x70),0x10);
    }
    piVar4 = *(int **)(param_1 + 0x18);
    *piVar4 = local_90;
    if (local_90 == 1) {
      *(ulonglong *)(piVar4 + 2) = (ulonglong)uStack_8c;
      for (auStack_88[2] = 0; auStack_88[2] < 2; auStack_88[2] = auStack_88[2] + 1) {
        *(ulonglong *)(piVar4 + (ulonglong)auStack_88[2] * 2 + 4) =
             (ulonglong)auStack_88[auStack_88[2]];
      }
    }
    else {
      if (local_90 != 2) {
                    /* WARNING: Subroutine does not return */
        ExRaiseStatus(0xc000000d);
      }
      *(ulonglong *)(piVar4 + 2) = (ulonglong)uStack_8c;
      piVar4[4] = auStack_88[0];
      piVar4[5] = auStack_88[1];
    }
    uVar9 = Feature_Servicing_KSTHUNK_UMA__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar9 == 0) {
      if (0x10 < uVar2) {
        memmove(piVar4 + 8,(void *)(*(longlong *)(param_1 + 0x70) + 0x10),_Size - 0x10);
      }
      memmove((void *)(*(longlong *)(param_1 + 0x18) + (ulonglong)uVar14),*(void **)(lVar3 + 0x20),
              local_68);
    }
    else {
      if (0x10 < uVar2) {
        RtlCopyFromUser(piVar4 + 8,(void *)(*(longlong *)(param_1 + 0x70) + 0x10),_Size - 0x10);
      }
      RtlCopyFromUser((void *)(*(longlong *)(param_1 + 0x18) + (ulonglong)uVar14),
                      *(void **)(lVar3 + 0x20),local_68);
    }
    *(_IRP_STATUS *)((ulonglong)uVar14 + 0x14 + *(longlong *)(param_1 + 0x18)) = local_res18;
    puVar10 = *(undefined8 **)(param_1 + 0xb8);
    puVar10[-9] = *puVar10;
    puVar10[-8] = puVar10[1];
    puVar10[-7] = puVar10[2];
    puVar10[-6] = puVar10[3];
    puVar10[-5] = puVar10[4];
    puVar10[-4] = puVar10[5];
    puVar10[-3] = puVar10[6];
    *(undefined1 *)((longlong)puVar10 + -0x45) = 0;
    *(uint *)(*(longlong *)(param_1 + 0xb8) + -0x40) = auStack_88[3];
    _Var13 = 5;
  }
  else if (uVar7 == 0x400) {
    if (uVar1 < 0x20) {
                    /* WARNING: Subroutine does not return */
      ExRaiseStatus(0xc0000206);
    }
    local_60 = 0;
    uStack_58 = 0;
    local_50 = 0;
    uStack_48 = 0;
    if (uVar1 + 8 < 0x28) {
                    /* WARNING: Subroutine does not return */
      ExRaiseStatus(0xc0000206);
    }
    if (uVar2 != 0) {
      ProbeForRead(*(undefined8 *)(param_1 + 0x70),_Size,1);
      ProbeForWrite(*(undefined8 *)(param_1 + 0x70),_Size,1);
      _Dst = (void *)ExAllocatePool2(99,_Size,0x7070534b);
      local_70 = _Dst;
      uVar9 = Feature_Servicing_KSTHUNK_UMA__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar9 == 0) {
        memmove(_Dst,*(void **)(param_1 + 0x70),_Size);
      }
      else {
        RtlCopyFromUser(_Dst,*(void **)(param_1 + 0x70),_Size);
      }
    }
    uVar9 = Feature_Servicing_KSTHUNK_UMA__private_IsEnabledDeviceUsageNoInline();
    puVar10 = *(undefined8 **)(lVar3 + 0x20);
    if ((int)uVar9 == 0) {
      local_60 = *puVar10;
      uStack_58 = puVar10[1];
      local_50 = puVar10[2];
      uStack_48 = puVar10[3];
    }
    else {
      RtlCopyFromUser(&local_60,puVar10,0x20);
    }
    local_50 = CONCAT44(local_res18,(undefined4)local_50);
    puVar10 = (undefined8 *)ExAllocatePoolWithTag(0x600,uVar1 + 8,0x6271534b);
    local_78 = puVar10;
    if (puVar10 == (undefined8 *)0x0) {
                    /* WARNING: Subroutine does not return */
      ExRaiseStatus(0xc000009a);
    }
    *puVar10 = local_60;
    puVar10[1] = uStack_58;
    puVar10[2] = local_50;
    puVar10[3] = uStack_48 & 0xffffffff;
    puVar10[4] = uStack_48 >> 0x20;
    if (0x20 < uVar1) {
      uVar9 = Feature_Servicing_KSTHUNK_UMA__private_IsEnabledDeviceUsageNoInline();
      _Src = (void *)(*(longlong *)(lVar3 + 0x20) + 0x20);
      if ((int)uVar9 == 0) {
        memmove(puVar10 + 5,_Src,(ulonglong)uVar1 - 0x20);
      }
      else {
        RtlCopyFromUser(puVar10 + 5,_Src,(ulonglong)uVar1 - 0x20);
      }
    }
    iVar8 = KsSynchronousIoControlDevice
                      (*(undefined8 *)(lVar3 + 0x30),0,0x2f0007,puVar10,uVar1 + 8,_Dst,uVar2,
                       &local_res8);
    plVar6 = local_res20;
    *local_res20 = iVar8;
    *(ulonglong *)(param_1 + 0x38) = local_res8 & 0xffffffff;
    ExFreePool(puVar10);
    local_78 = (undefined8 *)0x0;
    if (_Dst != (void *)0x0) {
      uVar9 = Feature_Servicing_KSTHUNK_UMA__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar9 == 0) {
        memmove(*(void **)(param_1 + 0x70),_Dst,_Size);
      }
      else {
        RtlCopyToUser(*(void **)(param_1 + 0x70),_Dst,_Size);
      }
      ExFreePool(_Dst);
    }
    bVar5 = true;
    local_res20 = plVar6;
  }
  if (!bVar5) {
    _Var12 = 0;
    if (-1 < *local_res20) {
      _Var12 = _Var13;
    }
    return _Var12;
  }
  return 0;
}



===== ThunkPropertyIrp @ 1400041a8 =====

/* protected: enum _IRP_DISPOSITION __cdecl CKSAutomationThunk::ThunkPropertyIrp(struct _IRP *
   __ptr64,enum _IRP_STATUS,long * __ptr64) __ptr64 */

_IRP_DISPOSITION __thiscall
CKSAutomationThunk::ThunkPropertyIrp
          (CKSAutomationThunk *this,_IRP *param_1,_IRP_STATUS param_2,long *param_3)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  ulonglong uVar4;
  uint *puVar5;
  
  lVar2 = *(longlong *)(param_1 + 0xb8);
  uVar1 = *(uint *)(lVar2 + 0x10);
  if (*(longlong *)(param_1 + 0x18) == 0) {
    if (uVar1 < 0x18) {
      *param_3 = -0x3ffffdfa;
      return 0;
    }
    uVar4 = Feature_Servicing_KSTHUNK_UMA__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 == 0) {
      if (param_1[0x40] == (_IRP)0x0) {
        uVar4 = (ulonglong)*(uint *)(*(longlong *)(lVar2 + 0x20) + 0x14);
      }
      else {
        ProbeForRead(*(undefined8 *)(lVar2 + 0x20),uVar1,1);
        uVar4 = (ulonglong)*(uint *)(*(longlong *)(lVar2 + 0x20) + 0x14);
      }
    }
    else {
      puVar5 = (uint *)(*(longlong *)(lVar2 + 0x20) + 0x14);
      if (param_1[0x40] == (_IRP)0x0) {
        uVar4 = (ulonglong)*puVar5;
      }
      else {
        uVar4 = RtlReadULongFromUser(puVar5);
      }
    }
    if ((uVar4 & 3) != 0) {
      *(CKSAutomationThunk **)(param_1 + 0x80) = this;
      iVar3 = KsPropertyHandler(param_1,6,&PTR__GUID_65aaba60_98ae_11cf_a10d_0020afd156e4_1400067e0)
      ;
      if ((iVar3 != -0x3ffffddb) && (iVar3 != -0x3ffffdd0)) {
        *param_3 = iVar3;
        return 0;
      }
    }
  }
  return 1;
}



===== Feature_Servicing_KsThunk_Array__private_IsEnabledDeviceUsageNoInline @ 1400042c0 =====

ulonglong Feature_Servicing_KsThunk_Array__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_Servicing_KsThunk_Array__private_featureState;
  if ((Feature_Servicing_KsThunk_Array__private_featureState & 0x10) == 0) {
    uVar1 = Feature_Servicing_KsThunk_Array__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_Servicing_KsThunk_Array__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_Servicing_KsThunk_Array__private_IsEnabledFallback @ 1400042f8 =====

void Feature_Servicing_KsThunk_Array__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_Servicing_KsThunk_Array__private_descriptor);
  return;
}



===== AddRef @ 140004320 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual unsigned long __cdecl CVideoCaptureThunkHandler::AddRef(void) __ptr64 */

ulong __thiscall CVideoCaptureThunkHandler::AddRef(CVideoCaptureThunkHandler *this)

{
  ulong uVar1;
  
  uVar1 = (**(code **)(**(longlong **)(this + 0x30) + 8))();
  return uVar1;
}



===== GetExtendedHeaderSize @ 140004340 =====

/* public: virtual unsigned long __cdecl CVideoCaptureThunkHandler::GetExtendedHeaderSize(unsigned
   long,unsigned char) __ptr64 */

ulong __thiscall
CVideoCaptureThunkHandler::GetExtendedHeaderSize
          (CVideoCaptureThunkHandler *this,ulong param_1,uchar param_2)

{
  ulong uVar1;
  
  if (param_2 != '\0') {
    return (-(uint)((param_1 & 0x1000) != 0) & 0x20) + 0x48;
  }
  uVar1 = 0x40;
  if ((param_1 & 0x1000) != 0) {
    uVar1 = 0x58;
  }
  return uVar1;
}



===== NonDelegatedQueryInterface @ 140004370 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CVideoCaptureThunkHandler::NonDelegatedQueryInterface(struct _GUID
   const & __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CVideoCaptureThunkHandler::NonDelegatedQueryInterface
          (CVideoCaptureThunkHandler *this,_GUID *param_1,void **param_2)

{
  long lVar1;
  
  if ((*(longlong *)param_1 == 0x41b5e80fbc709de8) &&
     (*(longlong *)(param_1 + 8) == 0xf01e570c606870a1)) {
    *param_2 = this + -8;
    (**(code **)(*(longlong *)(this + -8) + 8))();
    lVar1 = 0;
  }
  else {
    lVar1 = CBaseUnknown::NonDelegatedQueryInterface((CBaseUnknown *)this,param_1,param_2);
  }
  return lVar1;
}



===== QueryInterface @ 1400043c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CVideoCaptureThunkHandler::QueryInterface(struct _GUID const &
   __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CVideoCaptureThunkHandler::QueryInterface
          (CVideoCaptureThunkHandler *this,_GUID *param_1,void **param_2)

{
  long lVar1;
  
  lVar1 = (**(code **)**(undefined8 **)(this + 0x30))();
  return lVar1;
}



===== Release @ 1400043e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual unsigned long __cdecl CVideoCaptureThunkHandler::Release(void) __ptr64 */

ulong __thiscall CVideoCaptureThunkHandler::Release(CVideoCaptureThunkHandler *this)

{
  ulong uVar1;
  
  uVar1 = (**(code **)(**(longlong **)(this + 0x30) + 0x10))();
  return uVar1;
}



===== ReverseThunkExtendedHeader @ 140004400 =====

/* public: virtual void __cdecl CVideoCaptureThunkHandler::ReverseThunkExtendedHeader(unsigned
   long,void * __ptr64,void * __ptr64) __ptr64 */

void __thiscall
CVideoCaptureThunkHandler::ReverseThunkExtendedHeader
          (CVideoCaptureThunkHandler *this,ulong param_1,void *param_2,void *param_3)

{
  undefined8 uVar1;
  
  *(undefined4 *)param_3 = 0x40;
  *(undefined4 *)((longlong)param_3 + 4) = *(undefined4 *)((longlong)param_2 + 4);
  *(undefined8 *)((longlong)param_3 + 8) = *(undefined8 *)((longlong)param_2 + 8);
  *(undefined8 *)((longlong)param_3 + 0x10) = *(undefined8 *)((longlong)param_2 + 0x10);
  *(undefined4 *)((longlong)param_3 + 0x18) = *(undefined4 *)((longlong)param_2 + 0x18);
  *(undefined4 *)((longlong)param_3 + 0x1c) = *(undefined4 *)((longlong)param_2 + 0x20);
  uVar1 = *(undefined8 *)((longlong)param_2 + 0x30);
  *(undefined8 *)((longlong)param_3 + 0x20) = *(undefined8 *)((longlong)param_2 + 0x28);
  *(undefined8 *)((longlong)param_3 + 0x28) = uVar1;
  *(undefined4 *)((longlong)param_3 + 0x30) = *(undefined4 *)((longlong)param_2 + 0x38);
  *(undefined4 *)((longlong)param_3 + 0x34) = *(undefined4 *)((longlong)param_2 + 0x3c);
  *(undefined4 *)((longlong)param_3 + 0x38) = *(undefined4 *)((longlong)param_2 + 0x40);
  *(undefined4 *)((longlong)param_3 + 0x3c) = *(undefined4 *)((longlong)param_2 + 0x44);
  if ((param_1 >> 0xc & 1) != 0) {
    *(undefined4 *)((longlong)param_3 + 0x44) = *(undefined4 *)((longlong)param_2 + 0x4c);
  }
  return;
}



===== SetSpecificFormat @ 140004470 =====

/* public: virtual long __cdecl CVideoCaptureThunkHandler::SetSpecificFormat(union KSDATAFORMAT *
   __ptr64) __ptr64 */

long __thiscall
CVideoCaptureThunkHandler::SetSpecificFormat(CVideoCaptureThunkHandler *this,KSDATAFORMAT *param_1)

{
  undefined8 uVar1;
  bool bVar2;
  long lVar3;
  
  bVar2 = IsWellKnownFormatType((_GUID *)(param_1 + 0x30));
  if (bVar2) {
    uVar1 = *(undefined8 *)(param_1 + 8);
    lVar3 = 0;
    *(undefined8 *)(this + 0x38) = *(undefined8 *)param_1;
    *(undefined8 *)(this + 0x40) = uVar1;
    uVar1 = *(undefined8 *)(param_1 + 0x18);
    *(undefined8 *)(this + 0x48) = *(undefined8 *)(param_1 + 0x10);
    *(undefined8 *)(this + 0x50) = uVar1;
    uVar1 = *(undefined8 *)(param_1 + 0x28);
    *(undefined8 *)(this + 0x58) = *(undefined8 *)(param_1 + 0x20);
    *(undefined8 *)(this + 0x60) = uVar1;
    uVar1 = *(undefined8 *)(param_1 + 0x38);
    *(undefined8 *)(this + 0x68) = *(undefined8 *)(param_1 + 0x30);
    *(undefined8 *)(this + 0x70) = uVar1;
  }
  else {
    lVar3 = -0x3ffffd8e;
  }
  return lVar3;
}



===== ThunkExtendedHeader @ 1400044d0 =====

/* public: virtual void __cdecl CVideoCaptureThunkHandler::ThunkExtendedHeader(void * __ptr64,void *
   __ptr64) __ptr64 */

void __thiscall
CVideoCaptureThunkHandler::ThunkExtendedHeader
          (CVideoCaptureThunkHandler *this,void *param_1,void *param_2)

{
  undefined8 uVar1;
  
  *(undefined4 *)param_2 = 0x48;
  *(undefined4 *)((longlong)param_2 + 4) = *(undefined4 *)((longlong)param_1 + 4);
  *(undefined8 *)((longlong)param_2 + 8) = *(undefined8 *)((longlong)param_1 + 8);
  *(undefined8 *)((longlong)param_2 + 0x10) = *(undefined8 *)((longlong)param_1 + 0x10);
  *(ulonglong *)((longlong)param_2 + 0x18) = (ulonglong)*(uint *)((longlong)param_1 + 0x18);
  *(ulonglong *)((longlong)param_2 + 0x20) = (ulonglong)*(uint *)((longlong)param_1 + 0x1c);
  uVar1 = *(undefined8 *)((longlong)param_1 + 0x28);
  *(undefined8 *)((longlong)param_2 + 0x28) = *(undefined8 *)((longlong)param_1 + 0x20);
  *(undefined8 *)((longlong)param_2 + 0x30) = uVar1;
  *(undefined4 *)((longlong)param_2 + 0x38) = *(undefined4 *)((longlong)param_1 + 0x30);
  *(undefined4 *)((longlong)param_2 + 0x3c) = *(undefined4 *)((longlong)param_1 + 0x34);
  *(undefined4 *)((longlong)param_2 + 0x40) = *(undefined4 *)((longlong)param_1 + 0x38);
  *(undefined4 *)((longlong)param_2 + 0x44) = *(undefined4 *)((longlong)param_1 + 0x3c);
  return;
}



===== __GSHandlerCheck @ 140004538 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000455c =====

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



===== __GSHandlerCheck_SEH @ 1400045c4 =====

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



===== __security_check_cookie @ 140004660 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== RtlCopyVolatileMemory @ 140004690 =====

void * __cdecl RtlCopyVolatileMemory(void *_Dst,void *_Src,size_t _Size)

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



===== RtlMoveVolatileMemory @ 1400046a0 =====

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



===== RtlSetVolatileMemory @ 1400046b0 =====

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



===== _guard_dispatch_icall @ 1400046e0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001400046e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140004710 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140004740 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 1400047c0 =====

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



===== memset @ 140004ac0 =====

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



===== __memset_repmovs @ 140004c00 =====

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



===== __memset_query @ 140004c80 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140004d00 =====

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



===== __memset_spec_ermsb_repmovsb @ 140004e40 =====

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



===== __memset_spec_plain @ 140004ec0 =====

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



===== memset$thunk$772440563353939046 @ 140005050 =====

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



===== RtlCopyToUser @ 14000b008 =====

/* WARNING: Removing unreachable block (ram,0x00014000b02c) */

void RtlCopyToUser(void *param_1,void *param_2,size_t param_3)

{
  if (param_3 != 0) {
    ProbeForRead(param_1,param_3,1);
    RtlCopyVolatileMemory(param_1,param_2,param_3);
  }
  return;
}



===== RtlReadULongFromUser @ 14000b06c =====

/* WARNING: Removing unreachable block (ram,0x00014000b081) */

ulonglong RtlReadULongFromUser(uint *param_1)

{
  ProbeForRead(param_1,4,1);
  return (ulonglong)*param_1;
}



===== AddDevice @ 14000b0b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static long __cdecl CKernelFilterDriver::AddDevice(struct _DRIVER_OBJECT *
   __ptr64,struct _DEVICE_OBJECT * __ptr64) */

long __cdecl CKernelFilterDriver::AddDevice(_DRIVER_OBJECT *param_1,_DEVICE_OBJECT *param_2)

{
  char cVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  int local_res18 [4];
  
  local_res18[0] = 0;
  puVar2 = (undefined8 *)IoGetDriverObjectExtension(param_1,AddDevice);
  if (puVar2 != (undefined8 *)0x0) {
    cVar1 = (**(code **)(*(longlong *)*puVar2 + 8))((longlong *)*puVar2,param_2,local_res18);
    if (cVar1 == '\0') goto LAB_14000b19f;
    plVar3 = (longlong *)(*(code *)**(undefined8 **)*puVar2)((undefined8 *)*puVar2,param_2);
    if (plVar3 != (longlong *)0x0) {
      local_res18[0] = IoCreateDevice(plVar3[4],8,0,0x22,0x80,0,plVar3 + 5);
      if (-1 < local_res18[0]) {
        **(undefined8 **)(plVar3[5] + 0x40) = plVar3;
        local_res18[0] = (**(code **)(*plVar3 + 0x50))(plVar3,param_2);
        if (-1 < local_res18[0]) {
          return local_res18[0];
        }
      }
      (**(code **)(*plVar3 + 0x48))(plVar3,1);
      goto LAB_14000b19f;
    }
  }
  local_res18[0] = -0x3fffffff;
LAB_14000b19f:
  return local_res18[0];
}



===== DriverUnload @ 14000b1c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl CKernelFilterDriver::DriverUnload(struct _DRIVER_OBJECT * __ptr64)
    */

void __cdecl CKernelFilterDriver::DriverUnload(_DRIVER_OBJECT *param_1)

{
  longlong *plVar1;
  
  plVar1 = (longlong *)IoGetDriverObjectExtension(param_1,AddDevice);
  if ((plVar1 != (longlong *)0x0) && (plVar1 = (longlong *)*plVar1, plVar1 != (longlong *)0x0)) {
    (**(code **)(*plVar1 + 0x10))(plVar1,1);
  }
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



===== Initialize @ 14000b248 =====

/* public: long __cdecl CKernelFilterDriver::Initialize(void) __ptr64 */

long __thiscall CKernelFilterDriver::Initialize(CKernelFilterDriver *this)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 *local_res8;
  
  local_res8 = (undefined8 *)0x0;
  iVar1 = IoAllocateDriverObjectExtension(*(undefined8 *)(this + 8),AddDevice,8,&local_res8);
  if (-1 < iVar1) {
    lVar2 = 0x70;
    *local_res8 = this;
    lVar3 = 0x1c;
    do {
      *(code **)(lVar2 + *(longlong *)(this + 8)) = CKernelFilterDevice::DispatchIrpBridge;
      lVar2 = lVar2 + 8;
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
    *(code **)(*(longlong *)(*(longlong *)(this + 8) + 0x30) + 8) = AddDevice;
    *(code **)(*(longlong *)(this + 8) + 0x68) = DriverUnload;
  }
  return iVar1;
}



===== ~CKernelFilterDevice @ 14000b2e4 =====

/* public: virtual __cdecl CKernelFilterDevice::~CKernelFilterDevice(void) __ptr64 */

void __thiscall CKernelFilterDevice::~CKernelFilterDevice(CKernelFilterDevice *this)

{
  *(undefined ***)this = &_vftable_;
  IoDeleteDevice(*(undefined8 *)(this + 0x28));
  return;
}



===== ~CKernelFilterFile @ 14000b310 =====

/* public: virtual __cdecl CKernelFilterFile::~CKernelFilterFile(void) __ptr64 */

void __thiscall CKernelFilterFile::~CKernelFilterFile(CKernelFilterFile *this)

{
  *(undefined ***)this = &_vftable_;
  CKernelFilterDevice::NotifyDestroyFile(*(CKernelFilterDevice **)(this + 0x20),this);
  return;
}



===== AttachToStack @ 14000b340 =====

/* public: virtual long __cdecl CKernelFilterDevice::AttachToStack(struct _DEVICE_OBJECT * __ptr64)
   __ptr64 */

long __thiscall
CKernelFilterDevice::AttachToStack(CKernelFilterDevice *this,_DEVICE_OBJECT *param_1)

{
  long lVar1;
  longlong lVar2;
  
  if (*(longlong *)(this + 0x38) == 0) {
    lVar2 = IoAttachDeviceToDeviceStack(*(undefined8 *)(this + 0x28));
    *(longlong *)(this + 0x38) = lVar2;
    if (lVar2 == 0) {
      lVar1 = -0x3ffffff2;
    }
    else {
      *(uint *)(*(longlong *)(this + 0x28) + 0x30) =
           *(uint *)(*(longlong *)(this + 0x28) + 0x30) | *(uint *)(lVar2 + 0x30) & 0x6014;
      *(undefined4 *)(*(longlong *)(this + 0x28) + 0x48) =
           *(undefined4 *)(*(longlong *)(this + 0x38) + 0x48);
      *(undefined4 *)(*(longlong *)(this + 0x28) + 0x34) =
           *(undefined4 *)(*(longlong *)(this + 0x38) + 0x34);
      *(uint *)(*(longlong *)(this + 0x28) + 0x30) =
           *(uint *)(*(longlong *)(this + 0x28) + 0x30) & 0xffffff7f;
      lVar1 = 0;
    }
  }
  else {
    lVar1 = -0x3fffffff;
  }
  return lVar1;
}



===== DispatchClose @ 14000b3c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual enum _IRP_DISPOSITION __cdecl CKernelFilterFile::DispatchClose(struct _IRP *
   __ptr64,enum _IRP_STATUS,long * __ptr64) __ptr64 */

_IRP_DISPOSITION __thiscall
CKernelFilterFile::DispatchClose
          (CKernelFilterFile *this,_IRP *param_1,_IRP_STATUS param_2,long *param_3)

{
  _IRP_DISPOSITION _Var1;
  
  if (param_2 == 0) {
    _Var1 = 4;
  }
  else {
    if (this != (CKernelFilterFile *)0x0) {
      (*(code *)**(undefined8 **)this)(this,1);
    }
    _Var1 = 0;
  }
  return _Var1;
}



===== DispatchCreate @ 14000b400 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: virtual enum _IRP_DISPOSITION __cdecl CKernelFilterDevice::DispatchCreate(struct _IRP
   * __ptr64,enum _IRP_STATUS,long * __ptr64) __ptr64 */

_IRP_DISPOSITION __thiscall
CKernelFilterDevice::DispatchCreate
          (CKernelFilterDevice *this,_IRP *param_1,_IRP_STATUS param_2,long *param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  char cVar3;
  long lVar4;
  int iVar5;
  CKernelFilterFile *pCVar6;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  if (param_2 == 0) {
    return 4;
  }
  if ((-1 < *param_3) && (cVar3 = (*(code *)**(undefined8 **)this)(), cVar3 != '\0')) {
    pCVar6 = (CKernelFilterFile *)(**(code **)(*(longlong *)this + 8))(this,param_1);
    if (pCVar6 == (CKernelFilterFile *)0x0) {
      iVar5 = -0x3fffff66;
    }
    else {
      iVar5 = (**(code **)(*(longlong *)pCVar6 + 8))(pCVar6);
    }
    *param_3 = iVar5;
    if (-1 < iVar5) {
      lVar4 = NotifyNewFile(this,pCVar6);
      *param_3 = lVar4;
      if (-1 < lVar4) {
        return 0;
      }
    }
    local_18 = 0;
    local_28 = 0;
    uStack_20 = 0;
    KeInitializeEvent(&local_28,1,0);
    puVar1 = *(undefined8 **)(param_1 + 0xb8);
    puVar1[-9] = *puVar1;
    puVar1[-8] = puVar1[1];
    puVar1[-7] = puVar1[2];
    puVar1[-6] = puVar1[3];
    *(undefined4 *)(puVar1 + -5) = *(undefined4 *)(puVar1 + 4);
    *(undefined4 *)((longlong)puVar1 + -0x24) = *(undefined4 *)((longlong)puVar1 + 0x24);
    *(undefined4 *)(puVar1 + -4) = *(undefined4 *)(puVar1 + 5);
    *(undefined4 *)((longlong)puVar1 + -0x1c) = *(undefined4 *)((longlong)puVar1 + 0x2c);
    puVar1[-3] = puVar1[6];
    *(undefined1 *)((longlong)puVar1 + -0x45) = 0;
    *(undefined1 *)(*(longlong *)(param_1 + 0xb8) + -0x48) = 2;
    lVar2 = *(longlong *)(param_1 + 0xb8);
    *(code **)(lVar2 + -0x10) = DeferIrpCompletion;
    *(undefined8 **)(lVar2 + -8) = &local_28;
    *(undefined1 *)(lVar2 + -0x45) = 0xe0;
    iVar5 = IofCallDriver(*(undefined8 *)(this + 0x38),param_1);
    if (iVar5 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
    }
    if (pCVar6 != (CKernelFilterFile *)0x0) {
      (*(code *)**(undefined8 **)pCVar6)(pCVar6,1);
    }
  }
  return 0;
}



===== DispatchPnp @ 14000b580 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: virtual enum _IRP_DISPOSITION __cdecl CKernelFilterDevice::DispatchPnp(struct _IRP *
   __ptr64,enum _IRP_STATUS,long * __ptr64) __ptr64 */

_IRP_DISPOSITION __thiscall
CKernelFilterDevice::DispatchPnp
          (CKernelFilterDevice *this,_IRP *param_1,_IRP_STATUS param_2,long *param_3)

{
  _IRP_DISPOSITION _Var1;
  
  if (*(char *)(*(longlong *)(param_1 + 0xb8) + 1) == '\x02') {
    if (param_2 == 0) {
      _Var1 = 4;
    }
    else {
      if (*(longlong *)(this + 0x38) != 0) {
        IoDetachDevice();
        *(undefined8 *)(this + 0x30) = 0;
        *(undefined8 *)(this + 0x38) = 0;
      }
      (**(code **)(*(longlong *)this + 0x48))(this,1);
      _Var1 = 0;
    }
  }
  else {
    _Var1 = 1;
  }
  return _Var1;
}



===== SynchronousForwardIrp @ 14000b5ec =====

/* public: long __cdecl CKernelFilterDevice::SynchronousForwardIrp(struct _IRP * __ptr64) __ptr64 */

long __thiscall CKernelFilterDevice::SynchronousForwardIrp(CKernelFilterDevice *this,_IRP *param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  int iVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeInitializeEvent(&local_28,1,0);
  puVar1 = *(undefined8 **)(param_1 + 0xb8);
  puVar1[-9] = *puVar1;
  puVar1[-8] = puVar1[1];
  puVar1[-7] = puVar1[2];
  puVar1[-6] = puVar1[3];
  *(undefined4 *)(puVar1 + -5) = *(undefined4 *)(puVar1 + 4);
  *(undefined4 *)((longlong)puVar1 + -0x24) = *(undefined4 *)((longlong)puVar1 + 0x24);
  *(undefined4 *)(puVar1 + -4) = *(undefined4 *)(puVar1 + 5);
  *(undefined4 *)((longlong)puVar1 + -0x1c) = *(undefined4 *)((longlong)puVar1 + 0x2c);
  puVar1[-3] = puVar1[6];
  *(undefined1 *)((longlong)puVar1 + -0x45) = 0;
  lVar2 = *(longlong *)(param_1 + 0xb8);
  *(code **)(lVar2 + -0x10) = DeferIrpCompletion;
  *(undefined8 **)(lVar2 + -8) = &local_28;
  *(undefined1 *)(lVar2 + -0x45) = 0xe0;
  iVar3 = IofCallDriver(*(undefined8 *)(this + 0x38),param_1);
  if (iVar3 == 0x103) {
    KeWaitForSingleObject(&local_28,0,0,0,0);
    iVar3 = *(int *)(param_1 + 0x30);
  }
  return iVar3;
}



===== CreateFilterDevice @ 14000b6c0 =====

/* public: virtual class CKernelFilterDevice * __ptr64 __cdecl
   CKSThunkDriver::CreateFilterDevice(struct _DEVICE_OBJECT * __ptr64) __ptr64 */

CKernelFilterDevice * __thiscall
CKSThunkDriver::CreateFilterDevice(CKSThunkDriver *this,_DEVICE_OBJECT *param_1)

{
  CKernelFilterDevice *pCVar1;
  undefined8 uVar2;
  CKernelFilterDevice *_Dst;
  
  _Dst = (CKernelFilterDevice *)ExAllocatePoolWithTag(0x200,0x80,0x774e434b);
  if (_Dst == (CKernelFilterDevice *)0x0) {
    _Dst = (CKernelFilterDevice *)0x0;
  }
  else {
    memset(_Dst,0,0x80);
    uVar2 = *(undefined8 *)(this + 8);
    *(undefined8 *)(_Dst + 0x30) = 0;
    *(undefined8 *)(_Dst + 0x38) = 0;
    *(undefined8 *)(_Dst + 0x20) = uVar2;
    *(undefined ***)_Dst = &CKernelFilterDevice::_vftable_;
    KeInitializeSpinLock(_Dst + 8);
    pCVar1 = _Dst + 0x10;
    *(CKernelFilterDevice **)(_Dst + 0x18) = pCVar1;
    *(CKernelFilterDevice **)pCVar1 = pCVar1;
    *(undefined ***)_Dst = &CKSThunkDevice::_vftable__for__CKernelFilterDevice__;
    *(undefined ***)(_Dst + 0x40) = &CKSThunkDevice::_vftable__for__CKSAutomationThunk__;
    KeInitializeMutex(_Dst + 0x48,0);
  }
  return _Dst;
}



===== IsDeviceFilterable @ 14000b780 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: virtual bool __cdecl CKSThunkDriver::IsDeviceFilterable(struct _DEVICE_OBJECT *
   __ptr64,long & __ptr64) __ptr64 */

bool __thiscall
CKSThunkDriver::IsDeviceFilterable(CKSThunkDriver *this,_DEVICE_OBJECT *param_1,long *param_2)

{
  undefined8 uVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  code *pcVar5;
  undefined8 local_res18 [2];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res18[0] = 0;
  iVar3 = IoOpenDeviceRegistryKey(param_1,2,0x20019,local_res18);
  uVar1 = local_res18[0];
  *param_2 = iVar3;
  if (-1 < iVar3) {
    local_18 = 0;
    uStack_10 = 0;
    RtlInitUnicodeString(&local_18,L"RtlQueryRegistryValuesEx");
    pcVar5 = (code *)MmGetSystemRoutineAddress(&local_18);
    if (pcVar5 == (code *)0x0) {
      pcVar5 = RtlQueryRegistryValues_exref;
    }
    lVar4 = (*pcVar5)(0x40000000,uVar1,&DAT_140008000,this,0);
    *param_2 = lVar4;
    ZwClose(local_res18[0]);
  }
  if (*param_2 == -0x3fffffcc) {
    *param_2 = 0;
    bVar2 = false;
  }
  else {
    bVar2 = (bool)((byte)((uint)*param_2 >> 0x1f) ^ 1);
  }
  return bVar2;
}



===== wil_details_EvaluateFeatureDependencies @ 14000b860 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  uint uVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  bool bVar5;
  
  puVar4 = (undefined *)0x0;
  ppuVar3 = &Feature_MediaQI2511__private_descriptor;
  ppuVar2 = &Feature_MediaQI2511__private_descriptor;
  do {
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x00014000b89b;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_14000b915:
  while( true ) {
    if (&UNK_14000770f < ppuVar3) {
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
      if (&UNK_14000770f < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x00014000b89b:
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
      if (&UNK_14000770f < ppuVar2) goto LAB_14000b915;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_14000b915;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14000b950 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_14000b9ec;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_14000b9ec;
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
LAB_14000b9ec:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14000ba50 =====

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
      for (ppuVar2 = &Feature_MediaQI2511__private_descriptor;
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
              if (&UNK_14000770f < ppuVar2) {
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



===== wil_details_RecordFeatureUsageCallback @ 14000bad0 =====

void wil_details_RecordFeatureUsageCallback(void)

{
  RtlRecordFeatureUsage();
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14000baf0 =====

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
  for (ppuVar3 = &Feature_MediaQI2511__private_descriptor;
      ppuVar3 < &wil_details_featureDescriptors_z; ppuVar3 = ppuVar3 + 1) {
    if (*ppuVar3 != (undefined *)0x0) goto LAB_14000bbed;
  }
LAB_14000bbf6:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14000bbed:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14000bbf6;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14000bbbe:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14000bbbe;
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
    if (&UNK_14000770f < ppuVar3) goto LAB_14000bbf6;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14000bbed;
}



===== CKSThunkPin @ 14000bc1c =====

/* public: __cdecl CKSThunkPin::CKSThunkPin(struct _FILE_OBJECT * __ptr64,class CKSThunkDevice *
   __ptr64,union KSDATAFORMAT * __ptr64) __ptr64 */

CKSThunkPin * __thiscall
CKSThunkPin::CKSThunkPin
          (CKSThunkPin *this,_FILE_OBJECT *param_1,CKSThunkDevice *param_2,KSDATAFORMAT *param_3)

{
  IKsWOW64FormatThunk *pIVar1;
  CKSThunkPin *this_00;
  
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined ***)this = &_vftable__for__CKernelFilterFile__;
  *(_FILE_OBJECT **)(this + 0x18) = param_1;
  *(undefined ***)(this + 0x28) = &_vftable__for__CKSAutomationThunk__;
  *(undefined8 *)(this + 0x70) = 0;
  *(CKSThunkDevice **)(this + 0x20) = param_2;
  this[0x7c] = (CKSThunkPin)0x1;
  KeInitializeMutex(this + 0x30,0);
  this_00 = this + 0x68;
  ExInitializePushLock();
  pIVar1 = LocateFormatHandler(this_00,param_3);
  *(IKsWOW64FormatThunk **)(this + 0x70) = pIVar1;
  return this;
}



===== ~CKSThunkPin @ 14000bc9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: virtual __cdecl CKSThunkPin::~CKSThunkPin(void) __ptr64 */

void __thiscall CKSThunkPin::~CKSThunkPin(CKSThunkPin *this)

{
  longlong *plVar1;
  ulonglong uVar2;
  longlong *plVar3;
  
  *(undefined ***)this = &_vftable__for__CKernelFilterFile__;
  *(undefined ***)(this + 0x28) = &_vftable__for__CKSAutomationThunk__;
  uVar2 = Feature_3149374777__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 == 0) {
    if (*(longlong **)(this + 0x70) != (longlong *)0x0) {
      (**(code **)(**(longlong **)(this + 0x70) + 0x10))();
      *(undefined8 *)(this + 0x70) = 0;
    }
  }
  else {
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(this + 0x68,0);
    plVar1 = *(longlong **)(this + 0x70);
    plVar3 = (longlong *)0x0;
    if (plVar1 != (longlong *)0x0) {
      *(undefined8 *)(this + 0x70) = 0;
      plVar3 = plVar1;
    }
    ExReleasePushLockExclusiveEx(this + 0x68,0);
    KeLeaveCriticalRegion();
    if (plVar3 != (longlong *)0x0) {
      (**(code **)(*plVar3 + 0x10))(plVar3);
    }
  }
  *(undefined ***)this = &CKernelFilterFile::_vftable_;
  CKernelFilterDevice::NotifyDestroyFile
            (*(CKernelFilterDevice **)(this + 0x20),(CKernelFilterFile *)this);
  return;
}



===== ConnectionState @ 14000bd80 =====

/* public: virtual long __cdecl CKSThunkPin::ConnectionState(struct _IRP * __ptr64,struct
   KSIDENTIFIER * __ptr64,enum KSSTATE * __ptr64) __ptr64 */

long __thiscall
CKSThunkPin::ConnectionState(CKSThunkPin *this,_IRP *param_1,KSIDENTIFIER *param_2,KSSTATE *param_3)

{
  char cVar1;
  char cVar2;
  longlong lVar3;
  long lVar4;
  
  lVar4 = -0x3ffffddb;
  if ((*(uint *)(param_2 + 0x14) & 2) != 0) {
    KeWaitForSingleObject(this + 8,0,0,0,0);
    lVar3 = *(longlong *)(*(CKernelFilterDevice **)(this + -8) + 0x38);
    cVar1 = *(char *)(lVar3 + 0x4c);
    lVar4 = CKernelFilterDevice::SynchronousForwardIrp(*(CKernelFilterDevice **)(this + -8),param_1)
    ;
    if (-1 < lVar4) {
      if (((*(int *)(this + 0x50) == 0) && (*param_3 != 0)) &&
         (cVar2 = *(char *)(lVar3 + 0x4c), cVar1 != cVar2)) {
        *(char *)(*(longlong *)(*(longlong *)(this + -8) + 0x28) + 0x4c) = cVar2 + '\x01';
      }
      *(KSSTATE *)(this + 0x50) = *param_3;
    }
    KeReleaseMutex(this + 8,0);
  }
  return lVar4;
}



===== DataFormat @ 14000be50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CKSThunkPin::DataFormat(struct _IRP * __ptr64,struct KSIDENTIFIER *
   __ptr64,union KSDATAFORMAT * __ptr64) __ptr64 */

long __thiscall
CKSThunkPin::DataFormat(CKSThunkPin *this,_IRP *param_1,KSIDENTIFIER *param_2,KSDATAFORMAT *param_3)

{
  long lVar1;
  IKsWOW64FormatThunk *pIVar2;
  ulonglong uVar3;
  longlong lVar4;
  CKSThunkPin *this_00;
  longlong *plVar5;
  
  if (*(uint *)(*(longlong *)(param_1 + 0xb8) + 8) < 0x40) {
    return -0x3ffffddb;
  }
  this_00 = this + 8;
  KeWaitForSingleObject(this_00,0,0,0,0);
  if (((*(uint *)(param_2 + 0x14) & 2) == 0) ||
     (pIVar2 = LocateFormatHandler(this_00,param_3), pIVar2 == (IKsWOW64FormatThunk *)0x0)) {
    lVar1 = -0x3ffffddb;
  }
  else {
    lVar1 = CKernelFilterDevice::SynchronousForwardIrp(*(CKernelFilterDevice **)(this + -8),param_1)
    ;
    if (-1 < lVar1) {
      uVar3 = Feature_3149374777__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar3 == 0) {
        plVar5 = *(longlong **)(this + 0x48);
        *(IKsWOW64FormatThunk **)(this + 0x48) = pIVar2;
        lVar4 = *plVar5;
      }
      else {
        KeEnterCriticalRegion();
        ExAcquirePushLockExclusiveEx(this + 0x40,0);
        plVar5 = *(longlong **)(this + 0x48);
        *(IKsWOW64FormatThunk **)(this + 0x48) = pIVar2;
        ExReleasePushLockExclusiveEx(this + 0x40,0);
        KeLeaveCriticalRegion();
        if (plVar5 == (longlong *)0x0) goto LAB_14000bf48;
        lVar4 = *plVar5;
      }
      (**(code **)(lVar4 + 0x10))(plVar5);
    }
  }
LAB_14000bf48:
  KeReleaseMutex(this + 8,0);
  return lVar1;
}



===== IsWellKnownFormatType @ 14000bf84 =====

/* bool __cdecl IsWellKnownFormatType(struct _GUID const & __ptr64) */

bool __cdecl IsWellKnownFormatType(_GUID *param_1)

{
  _GUID *p_Var1;
  longlong lVar2;
  
  lVar2 = *(longlong *)param_1;
  p_Var1 = param_1 + 8;
  if (((((lVar2 == 0x11cec35605589f80) && (*(longlong *)p_Var1 == 0x5a595500aa0001bf)) ||
       ((lVar2 == 0x11d0eb0af72a76a0 && (*(longlong *)p_Var1 == 0xba16ccc00000e4ac)))) ||
      ((lVar2 == 0x424866292017be05 && (*(longlong *)p_Var1 == 0x9c9bbc471a7eedaa)))) ||
     ((lVar2 == 0x4651d3e8692fa379 && (*(longlong *)(param_1 + 8) == 0xafee13b0940bb4b5)))) {
    return true;
  }
  return false;
}



===== LocateFormatHandler @ 14000bff0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: struct IKsWOW64FormatThunk * __ptr64 __cdecl CKSThunkPin::LocateFormatHandler(union
   KSDATAFORMAT * __ptr64) __ptr64 */

IKsWOW64FormatThunk * __thiscall
CKSThunkPin::LocateFormatHandler(CKSThunkPin *this,KSDATAFORMAT *param_1)

{
  bool bVar1;
  int iVar2;
  longlong *_Dst;
  uint uVar3;
  IKsWOW64FormatThunk *pIVar4;
  undefined1 auStack_48 [32];
  IKsWOW64FormatThunk *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  pIVar4 = (IKsWOW64FormatThunk *)0x0;
  local_28 = (IKsWOW64FormatThunk *)0x0;
  bVar1 = IsWellKnownFormatType((_GUID *)(param_1 + 0x30));
  if (bVar1) {
    uVar3 = (int)pIVar4 + 0x78;
    _Dst = (longlong *)ExAllocatePoolWithTag(0x200,uVar3,0x774e434b);
    if (_Dst != (longlong *)0x0) {
      memset(_Dst,0,(ulonglong)uVar3);
      CBaseUnknown::CBaseUnknown((CBaseUnknown *)(_Dst + 1),(IUnknown *)0x0);
      *_Dst = (longlong)&CVideoCaptureThunkHandler::_vftable_;
      _Dst[1] = (longlong)&CVideoCaptureThunkHandler::_vftable__for__INonDelegatedUnknown__;
      _Dst[2] = (longlong)&CVideoCaptureThunkHandler::_vftable__for__IIndirectedUnknown__;
      (**(code **)(*_Dst + 8))(_Dst);
      (**(code **)*_Dst)(_Dst,&_GUID_bc709de8_e80f_41b5_a170_68600c571ef0,&local_28);
      (**(code **)(*_Dst + 0x10))(_Dst);
    }
    pIVar4 = local_28;
    if (local_28 != (IKsWOW64FormatThunk *)0x0) {
      iVar2 = (**(code **)(*(longlong *)local_28 + 0x18))(local_28,param_1);
      if (iVar2 < 0) {
        (**(code **)(*(longlong *)local_28 + 0x10))();
        local_28 = (IKsWOW64FormatThunk *)0x0;
      }
      pIVar4 = local_28;
      if (local_28 != (IKsWOW64FormatThunk *)0x0) {
        return local_28;
      }
    }
  }
  if ((((*(longlong *)(param_1 + 0x10) != 0x10000073647561) ||
       (*(longlong *)(param_1 + 0x18) != 0x719b3800aa000080)) ||
      (*(longlong *)(param_1 + 0x20) != 0x10000000000001)) ||
     (((*(longlong *)(param_1 + 0x28) != 0x719b3800aa000080 ||
       (*(longlong *)(param_1 + 0x30) != 0x11cec35605589f81)) ||
      (*(longlong *)(param_1 + 0x38) != 0x5a595500aa0001bf)))) {
    local_20 = 0x2fcc9e7;
    local_1c = 1;
    local_18 = 0xc000000d;
    RtlLogUnexpectedCodepath(&local_20);
    pIVar4 = local_28;
  }
  return pIVar4;
}



===== ThunkExtendedHeader @ 14000c1bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl CKSThunkPin::ThunkExtendedHeader(void * __ptr64,void * __ptr64,unsigned
   long,unsigned long) __ptr64 */

long __thiscall
CKSThunkPin::ThunkExtendedHeader
          (CKSThunkPin *this,void *param_1,void *param_2,ulong param_3,ulong param_4)

{
  longlong *plVar1;
  ulonglong uVar2;
  long lVar3;
  
  lVar3 = 0;
  uVar2 = Feature_3149374777__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 == 0) {
    if (param_4 == 0) {
      return 0;
    }
    plVar1 = *(longlong **)(this + 0x70);
    if (plVar1 != (longlong *)0x0) {
      (**(code **)(*plVar1 + 0x28))(plVar1,param_2,param_1);
      return 0;
    }
  }
  else {
    if (param_4 == 0) {
      return 0;
    }
    KeEnterCriticalRegion();
    ExAcquirePushLockSharedEx(this + 0x68,0);
    plVar1 = *(longlong **)(this + 0x70);
    if (plVar1 != (longlong *)0x0) {
      (**(code **)(*plVar1 + 8))(plVar1);
    }
    ExReleasePushLockSharedEx(this + 0x68,0);
    KeLeaveCriticalRegion();
    if (plVar1 != (longlong *)0x0) {
      (**(code **)(*plVar1 + 0x28))(plVar1,param_2,param_1);
      (**(code **)(*plVar1 + 0x10))(plVar1);
      return 0;
    }
  }
  if (param_4 == param_3) {
    memmove(param_1,param_2,(ulonglong)param_4);
  }
  else {
    lVar3 = -0x3ffffff3;
  }
  return lVar3;
}



===== ThunkStreamingIrp @ 14000c2ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: enum _IRP_DISPOSITION __cdecl CKSThunkPin::ThunkStreamingIrp(struct _IRP * __ptr64,enum
   _IRP_STATUS,long * __ptr64) __ptr64 */

_IRP_DISPOSITION __thiscall
CKSThunkPin::ThunkStreamingIrp(CKSThunkPin *this,_IRP *param_1,_IRP_STATUS param_2,long *param_3)

{
  CKSThunkPin CVar1;
  ushort uVar2;
  longlong lVar3;
  ulong uVar4;
  uint uVar5;
  int iVar6;
  longlong lVar7;
  _KSSTREAM_HEADER32 *_Dst;
  ulonglong uVar8;
  ulonglong uVar9;
  longlong lVar10;
  KSSTREAM_METADATA_INFO32 *pKVar11;
  KSSTREAM_METADATA_INFO *pKVar12;
  undefined8 uVar13;
  uint uVar14;
  undefined4 *puVar15;
  KSSTREAM_HEADER *pKVar16;
  _KSSTREAM_HEADER32 *p_Var17;
  undefined8 *puVar18;
  longlong *plVar19;
  undefined4 in_register_00000084;
  undefined1 auStackY_158 [32];
  uint local_124;
  uint local_120;
  int local_11c;
  uint local_10c;
  KSSTREAM_HEADER *local_108;
  undefined4 *local_100;
  longlong *local_f8;
  longlong local_e8;
  KSSTREAM_HEADER *local_d0;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_158;
  lVar3 = *(longlong *)(param_1 + 0xb8);
  uVar5 = *(uint *)(lVar3 + 8);
  uVar9 = (ulonglong)uVar5;
  if (uVar5 < 0x30) {
    *param_3 = -0x3ffffdfa;
    return 0;
  }
  lVar7 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(*(longlong *)(this + 0x20) + 0x28)
                                       >> 8),
                                 *(undefined1 *)
                                  (*(longlong *)(*(longlong *)(this + 0x20) + 0x28) + 0x4c)),0,
                        CONCAT44(in_register_00000084,param_2));
  if (lVar7 != 0) {
    _Dst = (_KSSTREAM_HEADER32 *)ExAllocatePoolWithTag(0x600,uVar9,0x6274534b);
    if (_Dst != (_KSSTREAM_HEADER32 *)0x0) {
      uVar8 = Feature_Servicing_KSTHUNK_UMA__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar8 == 0) {
        if (*(int *)(lVar3 + 0x18) == 0x2f8013) {
          ProbeForRead();
        }
        else {
          ProbeForWrite(*(undefined8 *)(param_1 + 0x70),uVar9,1);
        }
        memmove(_Dst,*(void **)(param_1 + 0x70),uVar9);
      }
      else {
        if (*(int *)(lVar3 + 0x18) != 0x2f8013) {
          ProbeForWrite(*(undefined8 *)(param_1 + 0x70),uVar9,1);
        }
        if (param_1[0x40] == (_IRP)0x0) {
          RtlCopyVolatileMemory(_Dst,*(void **)(param_1 + 0x70),uVar9);
        }
        else {
          RtlCopyFromUser(_Dst,*(void **)(param_1 + 0x70),uVar9);
        }
      }
      *(_KSSTREAM_HEADER32 **)(param_1 + 0x18) = _Dst;
      uVar14 = *(uint *)(param_1 + 0x10);
      *(uint *)(param_1 + 0x10) = uVar14 | 0x30;
      if (*(int *)(lVar3 + 0x18) == 0x2f4017) {
        *(uint *)(param_1 + 0x10) = uVar14 | 0x70;
      }
      local_100 = (undefined4 *)0x0;
      local_d0 = (KSSTREAM_HEADER *)0x0;
      local_11c = 0;
      local_124 = 0;
      CVar1 = this[0x7c];
      local_f8 = (longlong *)0x0;
      local_e8 = 0;
      uVar9 = Feature_3149374777__private_IsEnabledDeviceUsageNoInline();
      if (((int)uVar9 != 0) && (-1 < *param_3)) {
        KeEnterCriticalRegion();
        ExAcquirePushLockSharedEx(this + 0x68,0);
        local_f8 = *(longlong **)(this + 0x70);
        if (local_f8 != (longlong *)0x0) {
          (**(code **)(*local_f8 + 8))(local_f8);
        }
        ExReleasePushLockSharedEx(this + 0x68,0);
        KeLeaveCriticalRegion();
        uVar9 = Feature_Servicing_KsThunk_Release__private_IsEnabledDeviceUsageNoInline();
        if ((((int)uVar9 != 0) && (local_f8 != (longlong *)0x0)) &&
           (local_e8 = IoAllocateWorkItem(*(undefined8 *)(*(longlong *)(this + 0x20) + 0x28)),
           local_e8 == 0)) {
          *param_3 = -0x3fffff66;
        }
      }
      local_10c = uVar5;
      if (-1 < *param_3) {
        for (p_Var17 = _Dst; (local_10c != 0 && (uVar14 = *(uint *)p_Var17, uVar14 <= local_10c));
            p_Var17 = p_Var17 + uVar14) {
          if ((uVar14 < 0x30) || (((*(uint *)(p_Var17 + 0x2c) & 0x1000) != 0 && (uVar14 < 0x88)))) {
                    /* WARNING: Subroutine does not return */
            ExRaiseStatus(0xc000000d);
          }
          local_11c = local_11c + 1;
          if (*(int *)(p_Var17 + 0x28) == 0) {
                    /* WARNING: Subroutine does not return */
            ExRaiseStatus(0xc000000d);
          }
          ProbeForWrite(*(int *)(p_Var17 + 0x28),*(undefined4 *)(p_Var17 + 0x20),1);
          if (*(uint *)(p_Var17 + 0x20) < *(uint *)(p_Var17 + 0x24)) {
                    /* WARNING: Subroutine does not return */
            ExRaiseStatus(0xc0000206);
          }
          if ((CVar1 == (CKSThunkPin)0x0) || (*(uint *)p_Var17 < uVar5)) {
            *(uint *)(p_Var17 + 0x2c) = *(uint *)(p_Var17 + 0x2c) & 0xfffe7fff;
          }
          if (((*(uint *)(p_Var17 + 0x2c) & 0x18000) == 0) &&
             (lVar10 = IoAllocateMdl(*(undefined4 *)(p_Var17 + 0x28),*(uint *)(p_Var17 + 0x20),
                                     *(longlong *)(lVar7 + 8) != 0), lVar10 == 0)) {
                    /* WARNING: Subroutine does not return */
            ExRaiseStatus(0xc000009a);
          }
          pKVar11 = GetMetadataBuffer32(p_Var17);
          if (pKVar11 != (KSSTREAM_METADATA_INFO32 *)0x0) {
            iVar6 = *(int *)(pKVar11 + 8);
            if (iVar6 != 0) {
              if (*(int *)pKVar11 != 0) {
                ProbeForWrite(iVar6,*(int *)pKVar11,1);
                if (*(uint *)pKVar11 < *(uint *)(pKVar11 + 4)) {
                    /* WARNING: Subroutine does not return */
                  ExRaiseStatus(0xc0000206);
                }
                if (((*(uint *)(p_Var17 + 0x2c) & 0x18000) == 0) &&
                   (lVar10 = IoAllocateMdl(*(undefined4 *)(pKVar11 + 8),*(uint *)pKVar11,
                                           *(longlong *)(lVar7 + 8) != 0), lVar10 == 0)) {
                    /* WARNING: Subroutine does not return */
                  ExRaiseStatus(0xc000009a);
                }
                goto LAB_14000c7e7;
              }
              if (iVar6 != 0) {
                local_58 = 0x357012c;
                local_54 = 2;
                local_50 = 0xc000000d;
                puVar15 = &local_58;
                goto LAB_14000c7ca;
              }
            }
            local_68 = 0x357012c;
            local_64 = 1;
            local_60 = 0xc000000d;
            puVar15 = &local_68;
LAB_14000c7ca:
            RtlLogUnexpectedCodepath(puVar15);
                    /* WARNING: Subroutine does not return */
            ExRaiseStatus(0xc000000d);
          }
LAB_14000c7e7:
          uVar4 = 0;
          if (0x30 < *(uint *)p_Var17) {
            uVar9 = Feature_3149374777__private_IsEnabledDeviceUsageNoInline();
            if ((int)uVar9 == 0) {
              plVar19 = *(longlong **)(this + 0x70);
              if ((plVar19 != (longlong *)0x0) &&
                 (uVar14 = (**(code **)(*plVar19 + 0x20))(plVar19,*(undefined4 *)(p_Var17 + 0x2c),0)
                 , (ulonglong)uVar14 != (ulonglong)*(uint *)p_Var17 - 0x30)) {
                    /* WARNING: Subroutine does not return */
                ExRaiseStatus(0xc000000d);
              }
              uVar4 = GetExtendedHeaderSize(this,*(ulong *)(p_Var17 + 0x2c),*(int *)p_Var17 - 0x30);
              if (uVar4 == 0) {
                    /* WARNING: Subroutine does not return */
                ExRaiseStatus(0xc000000d);
              }
            }
            else {
              iVar6 = *(int *)p_Var17;
              if ((local_f8 != (longlong *)0x0) &&
                 (uVar14 = (**(code **)(*local_f8 + 0x20))
                                     (local_f8,*(undefined4 *)(p_Var17 + 0x2c),0),
                 uVar14 != iVar6 - 0x30U)) {
                    /* WARNING: Subroutine does not return */
                ExRaiseStatus(0xc000000d);
              }
              uVar9 = GetExtendedHeaderSizeForHandler
                                (*(uint *)(p_Var17 + 0x2c),iVar6 - 0x30U,local_f8);
              uVar4 = (ulong)uVar9;
              if (uVar4 == 0) {
                    /* WARNING: Subroutine does not return */
                ExRaiseStatus(0xc000000d);
              }
            }
          }
          uVar14 = local_124 + 0x38;
          if (uVar14 < local_124) {
                    /* WARNING: Subroutine does not return */
            ExRaiseStatus(0xc000000d);
          }
          local_124 = uVar4 + uVar14;
          if (local_124 < uVar14) {
                    /* WARNING: Subroutine does not return */
            ExRaiseStatus(0xc000000d);
          }
          uVar14 = *(uint *)p_Var17;
          if (local_10c < uVar14) {
                    /* WARNING: Subroutine does not return */
            ExRaiseStatus(0xc000000d);
          }
          local_10c = local_10c - uVar14;
        }
        for (puVar18 = *(undefined8 **)(lVar7 + 8); puVar18 != (undefined8 *)0x0;
            puVar18 = (undefined8 *)*puVar18) {
          MmProbeAndLockPages(puVar18,param_1[0x40],1);
          uVar2 = *(ushort *)((longlong)puVar18 + 10);
          *(ushort *)((longlong)puVar18 + 10) = uVar2 | 0x2000;
          if ((uVar2 & 5) == 0) {
            lVar10 = MmMapLockedPagesSpecifyCache(puVar18,0,1);
          }
          else {
            lVar10 = puVar18[3];
          }
          if (lVar10 == 0) {
                    /* WARNING: Subroutine does not return */
            ExRaiseStatus(0xc000009a);
          }
        }
      }
      iVar6 = *param_3;
      if (-1 < iVar6) {
        if (local_10c != 0) {
          *param_3 = -0x3ffffff3;
          iVar6 = -0x3ffffff3;
        }
        if (-1 < iVar6) {
          local_100 = (undefined4 *)
                      ExAllocatePoolWithTag(0x600,(ulonglong)local_124 + 0x20,0x6373534b);
          local_d0 = (KSSTREAM_HEADER *)(local_100 + 8);
          if (local_100 == (undefined4 *)0x0) {
            *param_3 = -0x3fffff66;
          }
          else {
            *local_100 = *(undefined4 *)(lVar3 + 0x18);
            local_100[1] = local_124;
            *(CKSThunkPin **)(local_100 + 2) = this;
            plVar19 = *(longlong **)(lVar7 + 8);
            local_108 = local_d0;
            while (local_11c != 0) {
              local_11c = local_11c + -1;
              local_120 = 0;
              if (0x30 < *(uint *)_Dst) {
                uVar9 = Feature_3149374777__private_IsEnabledDeviceUsageNoInline();
                if ((int)uVar9 == 0) {
                  local_120 = GetExtendedHeaderSize
                                        (this,*(uint *)(_Dst + 0x2c),*(int *)_Dst - 0x30U);
                }
                else {
                  uVar9 = GetExtendedHeaderSizeForHandler
                                    (*(uint *)(_Dst + 0x2c),*(int *)_Dst - 0x30U,local_f8);
                  local_120 = (uint)uVar9;
                }
              }
              *(uint *)local_108 = local_120 + 0x38;
              *(undefined4 *)(local_108 + 4) = *(undefined4 *)(_Dst + 4);
              *(undefined8 *)(local_108 + 8) = *(undefined8 *)(_Dst + 8);
              *(undefined4 *)(local_108 + 0x10) = *(undefined4 *)(_Dst + 0x10);
              *(undefined4 *)(local_108 + 0x14) = *(undefined4 *)(_Dst + 0x14);
              *(undefined8 *)(local_108 + 0x18) = *(undefined8 *)(_Dst + 0x18);
              iVar6 = *(int *)(_Dst + 0x20);
              *(int *)(local_108 + 0x20) = iVar6;
              *(undefined4 *)(local_108 + 0x24) = *(undefined4 *)(_Dst + 0x24);
              uVar5 = *(uint *)(_Dst + 0x2c);
              *(uint *)(local_108 + 0x30) = uVar5;
              uVar5 = uVar5 & 0x8000;
              if ((plVar19 == (longlong *)0x0) && (uVar5 == 0)) {
                pKVar16 = local_108;
                pKVar12 = GetMetadataBuffer64(local_108);
                *(undefined8 *)(pKVar16 + 0x28) = 0;
                if (pKVar12 != (KSSTREAM_METADATA_INFO *)0x0) {
                  *(undefined8 *)(pKVar12 + 8) = 0;
                }
              }
              else {
                if (iVar6 == 0) {
                  *param_3 = -0x3ffffff3;
                  break;
                }
                if (uVar5 == 0) {
                  if ((*(byte *)((longlong)plVar19 + 10) & 5) == 0) {
                    lVar10 = MmMapLockedPagesSpecifyCache(plVar19,0,1);
                  }
                  else {
                    lVar10 = plVar19[3];
                  }
                  *(longlong *)(local_108 + 0x28) = lVar10;
                  if (lVar10 != 0) goto LAB_14000cc14;
LAB_14000cccb:
                  *param_3 = -0x3fffff66;
                  break;
                }
                *(ulonglong *)(local_108 + 0x28) = (ulonglong)*(uint *)(_Dst + 0x28);
LAB_14000cc14:
                pKVar16 = local_108;
                pKVar11 = GetMetadataBuffer32(_Dst);
                if ((pKVar11 != (KSSTREAM_METADATA_INFO32 *)0x0) &&
                   ((((plVar19 != (longlong *)0x0 &&
                      (plVar19 = (longlong *)*plVar19, plVar19 != (longlong *)0x0)) ||
                     ((*(uint *)(pKVar16 + 0x30) & 0x8000) != 0)) &&
                    (pKVar12 = GetMetadataBuffer64(pKVar16),
                    pKVar12 != (KSSTREAM_METADATA_INFO *)0x0)))) {
                  *(undefined4 *)pKVar12 = *(undefined4 *)pKVar11;
                  *(undefined4 *)(pKVar12 + 0x18) = *(undefined4 *)(pKVar11 + 0x10);
                  *(undefined4 *)(pKVar12 + 0x1c) = *(undefined4 *)(pKVar11 + 0x14);
                  *(undefined4 *)(pKVar12 + 4) = *(undefined4 *)(pKVar11 + 4);
                  *(undefined8 *)(pKVar12 + 0x10) = 0;
                  if ((*(uint *)(_Dst + 0x2c) & 0x18000) == 0) {
                    if ((*(byte *)((longlong)plVar19 + 10) & 5) == 0) {
                      lVar10 = MmMapLockedPagesSpecifyCache(plVar19,0,1);
                    }
                    else {
                      lVar10 = plVar19[3];
                    }
                    *(longlong *)(pKVar12 + 8) = lVar10;
                    if (lVar10 == 0) goto LAB_14000cccb;
                  }
                  else {
                    *(ulonglong *)(pKVar12 + 8) = (ulonglong)*(uint *)(pKVar11 + 8);
                  }
                }
              }
              uVar9 = Feature_3149374777__private_IsEnabledDeviceUsageNoInline();
              if ((int)uVar9 == 0) {
                iVar6 = ThunkExtendedHeader(this,local_108 + 0x38,_Dst + 0x30,local_120,
                                            *(int *)_Dst - 0x30U);
              }
              else {
                uVar13 = ThunkExtendedHeaderForHandler
                                   (local_108 + 0x38,_Dst + 0x30,local_120,*(int *)_Dst - 0x30U,
                                    local_f8);
                iVar6 = (int)uVar13;
              }
              *param_3 = iVar6;
              if (iVar6 < 0) break;
              local_108 = local_108 + *(uint *)local_108;
              _Dst = _Dst + *(uint *)_Dst;
              if (plVar19 != (longlong *)0x0) {
                plVar19 = (longlong *)*plVar19;
              }
            }
          }
        }
      }
      uVar9 = Feature_3149374777__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar9 != 0) {
        if ((-1 < *param_3) && (local_100 != (undefined4 *)0x0)) {
          *(longlong **)(local_100 + 4) = local_f8;
          local_f8 = (longlong *)0x0;
          uVar9 = Feature_Servicing_KsThunk_Release__private_IsEnabledDeviceUsageNoInline();
          if ((int)uVar9 != 0) {
            *(longlong *)(local_100 + 6) = local_e8;
            local_e8 = 0;
          }
        }
        if (local_f8 != (longlong *)0x0) {
          (**(code **)(*local_f8 + 0x10))();
        }
        uVar9 = Feature_Servicing_KsThunk_Release__private_IsEnabledDeviceUsageNoInline();
        if (((int)uVar9 != 0) && (local_e8 != 0)) {
          IoFreeWorkItem(local_e8);
        }
      }
      if (-1 < *param_3) {
        lVar10 = *(longlong *)(lVar7 + 0xb8);
        *(undefined8 *)(lVar10 + -0x20) = *(undefined8 *)(*(longlong *)(this + 0x20) + 0x38);
        *(undefined8 *)(lVar10 + -0x18) = *(undefined8 *)(lVar3 + 0x30);
        *(undefined1 *)(lVar10 + -0x48) = 0xe;
        *(undefined4 *)(lVar10 + -0x30) = *(undefined4 *)(lVar3 + 0x18);
        *(undefined4 *)(lVar10 + -0x38) = 0;
        *(uint *)(lVar10 + -0x40) = local_124;
        *(KSSTREAM_HEADER **)(lVar7 + 0x70) = local_d0;
        *(undefined1 *)(lVar7 + 0x40) = 0;
        *(void **)(lVar7 + 0x78) = SystemReserved1[0xf];
        *(CKSThunkPin **)(lVar7 + 0x80) = this;
        *(byte *)(*(longlong *)(param_1 + 0xb8) + 3) =
             *(byte *)(*(longlong *)(param_1 + 0xb8) + 3) | 1;
        *(longlong *)(param_1 + 0x78) = lVar7;
        *(CKSThunkPin **)(param_1 + 0x80) = this;
        *(undefined8 *)(param_1 + 0x88) = 0;
        lVar3 = *(longlong *)(lVar7 + 0xb8);
        *(code **)(lVar3 + -0x10) = ThunkStreamingIrpCompletion;
        *(_IRP **)(lVar3 + -8) = param_1;
        *(undefined1 *)(lVar3 + -0x45) = 0xe0;
        LOCK();
        *(code **)(param_1 + 0x68) = CancelStreamingIrp;
        UNLOCK();
        IofCallDriver(*(undefined8 *)(*(longlong *)(this + 0x20) + 0x38),lVar7);
        return 2;
      }
      while (puVar18 = *(undefined8 **)(lVar7 + 8), puVar18 != (undefined8 *)0x0) {
        if ((*(byte *)((longlong)puVar18 + 10) & 2) != 0) {
          MmUnlockPages(puVar18);
        }
        *(undefined8 *)(lVar7 + 8) = *puVar18;
        IoFreeMdl(puVar18);
      }
      IoFreeIrp(lVar7);
      if (local_100 == (undefined4 *)0x0) {
        return 0;
      }
      ExFreePool();
      return 0;
    }
    ExFreePool(lVar7);
  }
  *param_3 = -0x3fffff66;
  return 0;
}



===== RouteMDLcachingProperty @ 14000cf40 =====

/* public: static long __cdecl CKSAutomationThunk::RouteMDLcachingProperty(struct _IRP *
   __ptr64,struct KSIDENTIFIER * __ptr64,struct KSPIN_MDL_CACHING_NOTIFICATION32 * __ptr64) */

long __cdecl
CKSAutomationThunk::RouteMDLcachingProperty
          (_IRP *param_1,KSIDENTIFIER *param_2,KSPIN_MDL_CACHING_NOTIFICATION32 *param_3)

{
  long lVar1;
  undefined4 local_res8 [8];
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_18 = *(undefined4 *)param_3;
  local_14 = 0;
  local_res8[0] = 0;
  local_10 = (ulonglong)*(uint *)(param_3 + 4);
  lVar1 = KsSynchronousIoControlDevice
                    (*(undefined8 *)(*(longlong *)(param_1 + 0xb8) + 0x30),0,0x2f0003,param_2,0x18,
                     &local_18,0x10,local_res8);
  return lVar1;
}



===== entry @ 14000e010 =====

void entry(undefined8 param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 14000e044 =====

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



===== DriverEntry @ 14000e078 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long DriverEntry(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  CKernelFilterDriver *this;
  
  wil_InitializeFeatureStaging();
  this = (CKernelFilterDriver *)ExAllocatePoolWithTag(0x200,0x18,0x774e434b);
  if (this == (CKernelFilterDriver *)0x0) {
    lVar1 = -0x3fffff66;
  }
  else {
    *(undefined8 *)(this + 8) = param_1;
    *(undefined8 *)(this + 0x10) = param_2;
    *(undefined ***)this = &CKSThunkDriver::_vftable_;
    lVar1 = CKernelFilterDriver::Initialize(this);
    if (-1 < lVar1) {
      return lVar1;
    }
    (**(code **)(*(longlong *)this + 0x10))(this,1);
  }
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
  return lVar1;
}



===== wil_InitializeFeatureStaging @ 14000e154 =====

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
    for (ppuVar3 = &Feature_MediaQI2511__private_descriptor;
        ppuVar3 < &wil_details_featureDescriptors_z; ppuVar3 = ppuVar3 + 1) {
      if (*ppuVar3 != (undefined *)0x0) goto LAB_14000e1db;
    }
LAB_14000e215:
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
LAB_14000e1db:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14000e215;
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
    goto LAB_14000e215;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_14000770f < ppuVar3) goto LAB_14000e215;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14000e1db;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14000e268 =====

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
  ppuVar4 = &Feature_MediaQI2511__private_descriptor;
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
            if (&UNK_14000770f < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_14000e352;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_14000e352;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_14000e352:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_14000770f < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


