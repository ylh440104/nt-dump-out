
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



===== HidBattSystemControl @ 1c0001030 =====

/* long __cdecl HidBattSystemControl(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl HidBattSystemControl(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  longlong lVar1;
  long lVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  lVar2 = IofCallDriver(*(undefined8 *)(lVar1 + 0xe8));
  return lVar2;
}



===== HidBattAcquireStopLock @ 1c0001064 =====

undefined1 HidBattAcquireStopLock(longlong param_1)

{
  int *piVar1;
  int iVar2;
  undefined1 uVar3;
  
  uVar3 = 0;
  LOCK();
  *(int *)(param_1 + 0x158) = *(int *)(param_1 + 0x158) + 1;
  UNLOCK();
  if (*(char *)(param_1 + 0x178) == '\0') {
    uVar3 = 1;
  }
  else {
    LOCK();
    piVar1 = (int *)(param_1 + 0x158);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      KeSetEvent(param_1 + 0x160,0,0);
    }
  }
  return uVar3;
}



===== HidBattAddDevice @ 1c00010c0 =====

undefined8 HidBattAddDevice(undefined8 param_1,undefined8 param_2)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  uVar2 = IoCreateDevice(param_1,0x1a0,0,0x29,0x100,0,local_res18);
  if ((int)uVar2 == 0) {
    lVar3 = IoAttachDeviceToDeviceStack(local_res18[0]);
    if (lVar3 == 0) {
      IoDeleteDevice(local_res18[0]);
      uVar2 = 0xc0000001;
    }
    else {
      puVar1 = *(undefined4 **)(local_res18[0] + 0x40);
      *puVar1 = 0xc80000;
      memset(puVar1 + 4,0,200);
      *(undefined4 **)(puVar1 + 2) = puVar1 + 4;
      *(undefined8 *)(puVar1 + 0x3e) = 0;
      *(uint *)(local_res18[0] + 0x30) = *(uint *)(local_res18[0] + 0x30) | 0x2004;
      *(uint *)(local_res18[0] + 0x30) = *(uint *)(local_res18[0] + 0x30) & 0xffffff7f;
      *(undefined8 *)(puVar1 + 0x36) = param_2;
      puVar1[0x42] = 0xffffffff;
      *(longlong *)(puVar1 + 0x38) = local_res18[0];
      *(longlong *)(puVar1 + 0x3a) = lVar3;
      puVar1[0x46] = 2;
      *(undefined2 *)((longlong)puVar1 + 0x105) = 1;
      *(undefined1 *)((longlong)puVar1 + 0x107) = 0;
      IoInitializeRemoveLockEx(puVar1 + 0x4c,0x48746142,10,0x14,0x20);
      puVar1[0x66] = 0;
      KeInitializeEvent(puVar1 + 0x60,0,0);
      puVar1[0x56] = 1;
      *(undefined1 *)(puVar1 + 0x5e) = 0;
      KeInitializeEvent(puVar1 + 0x58,1,0);
      uVar2 = 0;
    }
  }
  return uVar2;
}



===== HidBattOpen @ 1c0001260 =====

undefined4 HidBattOpen(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  undefined4 uVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar1 = lVar2 + 0x130;
  iVar3 = IoAcquireRemoveLockEx(lVar1,0x48746142,"",1,0x20);
  if (iVar3 < 0) {
    uVar4 = 0xc000000e;
    *(undefined4 *)(param_2 + 0x30) = 0xc000000e;
    IofCompleteRequest(param_2,0);
  }
  else {
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    uVar4 = IofCallDriver(*(undefined8 *)(lVar2 + 0xe8),param_2);
    IoReleaseRemoveLockEx(lVar1,0x48746142,0x20);
  }
  return uVar4;
}



===== HidBattPnpDispatch @ 1c0001320 =====

ulonglong HidBattPnpDispatch(longlong param_1,ulonglong param_2)

{
  uint *puVar1;
  longlong lVar2;
  byte bVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 *puVar6;
  bool bVar7;
  int iVar8;
  uint uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  lVar4 = *(longlong *)(param_1 + 0x40);
  lVar5 = *(longlong *)(param_2 + 0xb8);
  uVar11 = 0x48746142;
  lVar2 = lVar4 + 0x130;
  bVar7 = false;
  IoAcquireRemoveLockEx(lVar2,0x48746142,"",1,0x20);
  bVar3 = *(byte *)(lVar5 + 1);
  if (bVar3 < 6) {
    if (bVar3 == 5) {
LAB_1c0001594:
      uVar11 = 0;
LAB_1c0001596:
      *(int *)(param_2 + 0x30) = (int)uVar11;
    }
    else {
      if (bVar3 == 0) {
        if (*(char *)(lVar4 + 0x105) == '\0') {
LAB_1c0001424:
          local_28 = 0;
          local_38 = 0;
          uStack_30 = 0;
          KeInitializeEvent(&local_38,1,0);
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
          lVar5 = *(longlong *)(param_2 + 0xb8);
          *(code **)(lVar5 + -0x10) = HidBattIoCompletion;
          *(undefined8 **)(lVar5 + -8) = &local_38;
          *(undefined1 *)(lVar5 + -0x45) = 0xe0;
          *(undefined4 *)(param_2 + 0x30) = 0;
          uVar11 = param_2;
          iVar8 = IofCallDriver(*(undefined8 *)(lVar4 + 0xe8));
          if (iVar8 == 0x103) {
            uVar11 = 0;
            KeWaitForSingleObject(&local_38,0,0,0,0);
            iVar8 = *(int *)(param_2 + 0x30);
          }
          if ((iVar8 < 0) || (uVar9 = HidBattInitializeDevice(param_1,uVar11), (int)uVar9 < 0)) {
            *(undefined1 *)(lVar4 + 0x107) = 1;
            IoInvalidateDeviceState(*(undefined8 *)(lVar4 + 0xd8));
          }
          *(undefined4 *)(param_2 + 0x30) = 0;
          IofCompleteRequest(param_2,0);
          IoReleaseRemoveLockEx(lVar2,0x48746142,0x20);
          return 0;
        }
        *(undefined2 *)(lVar4 + 0x105) = 0x100;
        goto LAB_1c0001594;
      }
      if (bVar3 == 1) {
LAB_1c000154c:
        HidBattStopDevice(param_1);
        goto LAB_1c0001594;
      }
      if (bVar3 == 2) {
        IoReleaseRemoveLockAndWaitEx(lVar2,0x48746142,0x20);
        bVar7 = true;
        IoDetachDevice(*(undefined8 *)(lVar4 + 0xe8));
        IoDeleteDevice(param_1);
        goto LAB_1c0001594;
      }
      if (bVar3 == 3) goto LAB_1c0001424;
      if (bVar3 != 4) goto LAB_1c00015b8;
      uVar10 = HidBattStopDevice(param_1);
      uVar11 = uVar10 & 0xffffffff;
      if ((int)uVar10 != -0x3fffff45) goto LAB_1c0001596;
    }
    if (((int)uVar11 < 0) && ((int)uVar11 != -0x3fffff45)) {
      IofCompleteRequest(param_2,0);
      goto LAB_1c00015db;
    }
  }
  else {
    if (bVar3 == 6) goto LAB_1c0001594;
    if (bVar3 == 9) {
      puVar1 = (uint *)(*(longlong *)(lVar5 + 8) + 4);
      *puVar1 = *puVar1 | 0x210;
      goto LAB_1c0001594;
    }
    if (bVar3 == 0x14) {
      if (*(char *)(lVar4 + 0x106) == '\x01') {
        *(undefined1 *)(lVar4 + 0x106) = 0;
        uVar9 = HidBattInitializeDevice(param_1,uVar11);
        if ((int)uVar9 < 0) {
          *(undefined1 *)(lVar4 + 0x107) = 1;
        }
      }
      if (*(char *)(lVar4 + 0x107) != '\0') {
        *(ulonglong *)(param_2 + 0x38) = *(ulonglong *)(param_2 + 0x38) | 4;
      }
      goto LAB_1c0001594;
    }
    if (bVar3 == 0x17) goto LAB_1c000154c;
  }
LAB_1c00015b8:
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  uVar9 = IofCallDriver(*(undefined8 *)(lVar4 + 0xe8),param_2);
  uVar11 = (ulonglong)uVar9;
LAB_1c00015db:
  if (!bVar7) {
    IoReleaseRemoveLockEx(lVar2,0x48746142,0x20);
  }
  return uVar11;
}



===== HidBattPowerDispatch @ 1c0001620 =====

void HidBattPowerDispatch(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  
  *(undefined8 *)(param_2 + 0x38) = 0;
  lVar1 = *(longlong *)(param_2 + 0xb8);
  lVar2 = *(longlong *)(param_1 + 0x40);
  if ((((*(char *)(lVar1 + 1) == '\x02') && (*(int *)(lVar1 + 0x10) == 0)) &&
      (5 < *(int *)(lVar1 + 0x18))) && (*(longlong *)(lVar2 + 0xf8) != 0)) {
    cVar3 = HidBattAcquireStopLock(lVar2);
    if (cVar3 != '\0') {
      CBattery::GetSetValue(*(CBattery **)(lVar2 + 0xf8),0xc,(ulong *)(lVar2 + 0x108),true);
      HidBattReleaseStopLock(lVar2);
    }
  }
  PoStartNextPowerIrp(param_2);
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  PoCallDriver(*(undefined8 *)(lVar2 + 0xe8),param_2);
  return;
}



===== HidBattReleaseStopLock @ 1c00016cc =====

void HidBattReleaseStopLock(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x158);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    KeSetEvent(param_1 + 0x160,0,0);
  }
  return;
}



===== HidBattSetInformation @ 1c0001710 =====

undefined8 HidBattSetInformation(void)

{
  return 0xc0000001;
}



===== _guard_check_icall @ 1c0001720 =====

void _guard_check_icall(void)

{
  return;
}



===== CUString @ 1c000172c =====

/* public: __cdecl CUString::CUString(unsigned short * __ptr64) __ptr64 */

CUString * __thiscall CUString::CUString(CUString *this,ushort *param_1)

{
  short sVar1;
  longlong lVar2;
  void *_Dst;
  
  this[0x14] = (CUString)0x1;
  *(undefined4 *)(this + 0x10) = 0;
  lVar2 = -1;
  do {
    lVar2 = lVar2 + 1;
  } while (param_1[lVar2] != 0);
  sVar1 = (short)lVar2 * 2;
  *(short *)this = sVar1;
  sVar1 = sVar1 + 2;
  *(short *)(this + 2) = sVar1;
  _Dst = (void *)ExAllocatePool2(0x100,sVar1,0x48746142);
  *(void **)(this + 8) = _Dst;
  if (_Dst == (void *)0x0) {
    *(undefined4 *)(this + 0x10) = 0xc000009a;
  }
  else {
    memcpy(_Dst,param_1,(ulonglong)*(ushort *)this);
  }
  return this;
}



===== ~CUString @ 1c00017bc =====

/* public: __cdecl CUString::~CUString(void) __ptr64 */

void __thiscall CUString::~CUString(CUString *this)

{
  if ((this[0x14] == (CUString)0x1) && (*(longlong *)(this + 8) != 0)) {
    ExFreePoolWithTag(*(longlong *)(this + 8),0);
  }
  return;
}



===== operator_new @ 1c00017ec =====

/* void * __ptr64 __cdecl operator new(unsigned __int64,unsigned __int64,unsigned long) */

void * __cdecl operator_new(__uint64 param_1,__uint64 param_2,ulong param_3)

{
  void *pvVar1;
  
  pvVar1 = (void *)ExAllocatePool2(0x40,param_1,0x48746142);
  return pvVar1;
}



===== Append @ 1c0001818 =====

/* public: void __cdecl CUString::Append(class CUString * __ptr64) __ptr64 */

void __thiscall CUString::Append(CUString *this,CUString *param_1)

{
  undefined4 uVar1;
  undefined2 local_18;
  ushort local_16;
  undefined4 local_14;
  void *local_10;
  
  local_16 = *(short *)param_1 + *(short *)this + 2;
  local_14 = 0;
  local_18 = 0;
  local_10 = (void *)ExAllocatePool2(0x100,local_16,0x48746142);
  if (local_10 == (void *)0x0) {
    uVar1 = 0xc000009a;
  }
  else {
    memset(local_10,0,(ulonglong)local_16);
    RtlCopyUnicodeString(&local_18,this);
    uVar1 = RtlAppendUnicodeStringToString(&local_18,param_1);
    if ((this[0x14] == (CUString)0x1) && (*(longlong *)(this + 8) != 0)) {
      ExFreePoolWithTag(*(longlong *)(this + 8),0);
    }
    *(ushort *)(this + 2) = local_16;
    *(undefined2 *)this = local_18;
    *(void **)(this + 8) = local_10;
    this[0x14] = (CUString)0x1;
  }
  *(undefined4 *)(this + 0x10) = uVar1;
  return;
}



===== ToCString @ 1c0001908 =====

/* public: long __cdecl CUString::ToCString(char * __ptr64 * __ptr64) __ptr64 */

long __thiscall CUString::ToCString(CUString *this,char **param_1)

{
  long lVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar2 = (char *)ExAllocatePool2(0x100,(*(ushort *)this >> 1) + 1,0x48746142);
  *param_1 = pcVar2;
  if (pcVar2 == (char *)0x0) {
    lVar1 = -0x3fffffff;
  }
  else {
    for (pcVar3 = *(char **)(this + 8); *pcVar3 != '\0'; pcVar3 = pcVar3 + 2) {
      *pcVar2 = *pcVar3;
      pcVar2 = pcVar2 + 1;
    }
    *pcVar2 = '\0';
    lVar1 = 0;
  }
  return lVar1;
}



===== HidBattDisableStatusNotify @ 1c0001970 =====

undefined8 HidBattDisableStatusNotify(longlong param_1)

{
  *(undefined8 *)(*(longlong *)(param_1 + 0xf8) + 0x58) = 0;
  return 0;
}



===== HidBattIoCompletion @ 1c0001990 =====

undefined8 HidBattIoCompletion(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== HidBattIoControl @ 1c00019c0 =====

int HidBattIoControl(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  undefined8 local_res8;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  iVar6 = -0x3fffff45;
  iVar5 = *(int *)(lVar2 + 0x198);
  do {
    LOCK();
    iVar1 = *(int *)(lVar2 + 0x198);
    bVar7 = iVar5 == iVar1;
    if (bVar7) {
      *(int *)(lVar2 + 0x198) = iVar5;
    }
    else {
      iVar5 = iVar1;
    }
    UNLOCK();
  } while (!bVar7);
  if (iVar5 == 0) {
    local_res8 = 0xffffffffff676980;
    KeWaitForSingleObject(lVar2 + 0x180,0,0,0,&local_res8);
  }
  cVar4 = HidBattAcquireStopLock(lVar2);
  if (cVar4 == '\0') {
    iVar6 = -0x3ffffd4a;
    *(undefined4 *)(param_2 + 0x30) = 0xc00002b6;
    IofCompleteRequest(param_2,0);
  }
  else {
    if ((*(longlong **)(lVar2 + 0xf8) != (longlong *)0x0) &&
       (lVar3 = **(longlong **)(lVar2 + 0xf8), lVar3 != 0)) {
      iVar6 = BatteryClassIoctl(lVar3,param_2);
    }
    HidBattReleaseStopLock(lVar2);
    if (iVar6 == -0x3fffff45) {
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      iVar6 = IofCallDriver(*(undefined8 *)(lVar2 + 0xe8),param_2);
    }
  }
  return iVar6;
}



===== HidBattNotifyHandler @ 1c0001ac0 =====

void HidBattNotifyHandler(longlong param_1,longlong *param_2)

{
  short sVar1;
  char cVar2;
  
  sVar1 = *(short *)(*param_2 + 0x14);
  if ((((sVar1 == 0x42) || (sVar1 == 0x44)) || (sVar1 == 0x45)) ||
     (((sVar1 == 0x66 || (sVar1 == 0x69)) || (sVar1 == 0xd0)))) {
    *(undefined1 *)(*(longlong *)(param_1 + 0xf8) + 0x10) = 0;
    cVar2 = HidBattAcquireStopLock(param_1);
    if (cVar2 != '\0') {
      BatteryClassStatusNotify(**(undefined8 **)(param_1 + 0xf8));
      HidBattReleaseStopLock(param_1);
    }
  }
  return;
}



===== HidBattQueryInformation @ 1c0001b30 =====

int HidBattQueryInformation
              (longlong param_1,uint param_2,ulong param_3,undefined8 param_4,void *param_5,
              uint param_6,uint *param_7)

{
  CBattery *this;
  char cVar1;
  bool bVar2;
  ulong uVar3;
  CUString *pCVar4;
  ushort *puVar5;
  CUsage *pCVar6;
  short sVar7;
  uint uVar8;
  int iVar9;
  CBattery *pCVar10;
  ulong local_res8 [2];
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48 [2];
  CBattery *local_40;
  undefined4 local_38;
  undefined1 local_34;
  
  local_res8[0] = 0;
  uVar3 = param_3;
  cVar1 = HidBattAcquireStopLock(param_1);
  if (cVar1 == '\0') {
    return -0x3ffffff2;
  }
  if (param_2 == 0) {
LAB_1c0002029:
    HidBattReleaseStopLock(param_1);
    return -0x3ffffff2;
  }
  this = *(CBattery **)(param_1 + 0xf8);
  if ((*(ushort *)(this + 0x60) == 0) || (param_2 != *(ushort *)(this + 0x60))) goto LAB_1c0002029;
  local_48[0] = 0;
  local_40 = (CBattery *)0x0;
  uVar8 = 0;
  local_34 = 0;
  iVar9 = 0;
  local_38 = 0;
  if (param_3 == 0) {
    pCVar10 = this + 0x30;
    uVar8 = 0x24;
    goto LAB_1c0001fe8;
  }
  if (param_3 == 1) {
    bVar2 = CBattery::GetSetValue(this,0x18,local_res8,false);
    if (bVar2) {
      if ((*(CBattery **)(param_1 + 0xf8))[0x11] == (CBattery)0x0) {
        pCVar6 = CBattery::GetUsage(*(CBattery **)(param_1 + 0xf8),0x18);
        if (pCVar6 == (CUsage *)0x0) {
          sVar7 = 0;
        }
        else {
          sVar7 = *(short *)(*(longlong *)pCVar6 + 4);
        }
        uVar3 = CorrectExponent(local_res8[0],sVar7,-2);
        local_res8[0] = ((uVar3 / 100) * *(int *)(*(longlong *)(param_1 + 0xf8) + 0x28)) / 0xe10;
        local_58 = local_res8[0];
      }
      else {
        local_58 = local_res8[0];
      }
    }
    else {
      local_58 = 0;
    }
    bVar2 = CBattery::GetSetValue(*(CBattery **)(param_1 + 0xf8),0x19,local_res8,false);
    if (bVar2) {
      if ((*(CBattery **)(param_1 + 0xf8))[0x11] == (CBattery)0x0) {
        pCVar6 = CBattery::GetUsage(*(CBattery **)(param_1 + 0xf8),0x19);
        if (pCVar6 == (CUsage *)0x0) {
          sVar7 = 0;
        }
        else {
          sVar7 = *(short *)(*(longlong *)pCVar6 + 4);
        }
        uVar3 = CorrectExponent(local_res8[0],sVar7,-2);
        local_res8[0] = ((uVar3 / 100) * *(int *)(*(longlong *)(param_1 + 0xf8) + 0x28)) / 0xe10;
        local_50 = local_res8[0];
      }
      else {
        local_50 = local_res8[0];
      }
    }
    else {
      local_50 = 0;
    }
    bVar2 = CBattery::GetSetValue(*(CBattery **)(param_1 + 0xf8),0x17,local_res8,false);
    if (bVar2) {
      if ((*(CBattery **)(param_1 + 0xf8))[0x11] == (CBattery)0x0) {
        pCVar6 = CBattery::GetUsage(*(CBattery **)(param_1 + 0xf8),0x17);
        if (pCVar6 == (CUsage *)0x0) {
          sVar7 = 0;
        }
        else {
          sVar7 = *(short *)(*(longlong *)pCVar6 + 4);
        }
        uVar3 = CorrectExponent(local_res8[0],sVar7,-2);
        local_res8[0] = ((uVar3 / 100) * *(int *)(*(longlong *)(param_1 + 0xf8) + 0x28)) / 0xe10;
        local_54 = local_res8[0];
      }
      else {
        local_54 = local_res8[0];
      }
    }
    else {
      local_54 = 0;
    }
    bVar2 = CBattery::GetSetValue(*(CBattery **)(param_1 + 0xf8),0x14,local_res8,false);
    if (bVar2) {
      if ((*(CBattery **)(param_1 + 0xf8))[0x11] == (CBattery)0x0) {
        pCVar6 = CBattery::GetUsage(*(CBattery **)(param_1 + 0xf8),0x14);
        if (pCVar6 == (CUsage *)0x0) {
          sVar7 = 0;
        }
        else {
          sVar7 = *(short *)(*(longlong *)pCVar6 + 4);
        }
        uVar3 = CorrectExponent(local_res8[0],sVar7,-2);
        local_res8[0] = ((uVar3 / 100) * *(int *)(*(longlong *)(param_1 + 0xf8) + 0x28)) / 0xe10;
        local_4c = local_res8[0];
      }
      else {
        local_4c = local_res8[0];
      }
    }
    else {
      local_4c = 0;
    }
    pCVar10 = (CBattery *)&local_58;
    uVar8 = 0x10;
    goto LAB_1c0001fe8;
  }
  pCVar10 = (CBattery *)0x0;
  if (param_3 != 2) {
    if (param_3 != 3) {
      if (param_3 == 4) {
        puVar5 = *(ushort **)(this + 0x78);
      }
      else {
        if (param_3 == 5) {
          if (this[0x88] != (CBattery)0x0) {
            pCVar10 = this + 0x88;
            goto LAB_1c0001dc2;
          }
          goto LAB_1c0001dcc;
        }
        if (param_3 == 6) {
          puVar5 = *(ushort **)(this + 0x80);
        }
        else {
          if (param_3 == 7) {
            if (*(CUString **)(this + 0x68) == (CUString *)0x0) {
              pCVar4 = operator_new(0x18,0,uVar3);
              if ((pCVar4 == (CUString *)0x0) ||
                 (pCVar4 = (CUString *)CUString::CUString(pCVar4,(ushort *)L"1000"),
                 pCVar4 == (CUString *)0x0)) {
                iVar9 = -0x3fffff66;
              }
              else {
                CUString::Append((CUString *)local_48,pCVar4);
                CUString::~CUString(pCVar4);
                ExFreePoolWithTag(pCVar4,0);
              }
            }
            else {
              CUString::Append((CUString *)local_48,*(CUString **)(this + 0x68));
            }
            pCVar4 = *(CUString **)(*(longlong *)(param_1 + 0xf8) + 0x80);
            if (pCVar4 == (CUString *)0x0) {
              pCVar4 = operator_new(0x18,0,uVar3);
              if ((pCVar4 == (CUString *)0x0) ||
                 (pCVar4 = (CUString *)CUString::CUString(pCVar4,(ushort *)L"Mfr"),
                 pCVar4 == (CUString *)0x0)) {
                iVar9 = -0x3fffff66;
              }
              else {
                CUString::Append((CUString *)local_48,pCVar4);
                CUString::~CUString(pCVar4);
                ExFreePoolWithTag(pCVar4,0);
              }
            }
            else {
              CUString::Append((CUString *)local_48,pCVar4);
            }
            pCVar4 = *(CUString **)(*(longlong *)(param_1 + 0xf8) + 0x78);
            if (pCVar4 == (CUString *)0x0) {
              pCVar4 = operator_new(0x18,0,uVar3);
              if ((pCVar4 == (CUString *)0x0) ||
                 (pCVar4 = (CUString *)CUString::CUString(pCVar4,(ushort *)L"Prod"),
                 pCVar4 == (CUString *)0x0)) {
                iVar9 = -0x3fffff66;
              }
              else {
                CUString::Append((CUString *)local_48,pCVar4);
                CUString::~CUString(pCVar4);
                ExFreePoolWithTag(pCVar4,0);
              }
            }
            else {
              CUString::Append((CUString *)local_48,pCVar4);
            }
            uVar8 = local_48[0] & 0xffff;
            pCVar10 = local_40;
            goto LAB_1c0001fe8;
          }
          if (param_3 != 8) goto LAB_1c0001dcc;
          puVar5 = *(ushort **)(this + 0x68);
        }
      }
      if (puVar5 != (ushort *)0x0) {
        uVar8 = (uint)*puVar5;
        pCVar10 = *(CBattery **)(puVar5 + 4);
      }
      goto LAB_1c0001fe8;
    }
    bVar2 = CBattery::GetSetValue(this,0x13,local_res8,false);
    if (bVar2) {
      pCVar6 = CBattery::GetUsage(*(CBattery **)(param_1 + 0xf8),0x13);
      if (pCVar6 == (CUsage *)0x0) {
        sVar7 = 0;
      }
      else {
        sVar7 = *(short *)(*(longlong *)pCVar6 + 4);
      }
      local_res8[0] = CorrectExponent(local_res8[0],sVar7,0);
      pCVar10 = (CBattery *)local_res8;
LAB_1c0001dc2:
      uVar8 = 4;
      goto LAB_1c0001fe8;
    }
  }
LAB_1c0001dcc:
  iVar9 = -0x3ffffff0;
LAB_1c0001fe8:
  *param_7 = uVar8;
  if (param_6 < uVar8) {
    iVar9 = -0x3fffffdd;
  }
  else if ((-1 < iVar9) && (pCVar10 != (CBattery *)0x0)) {
    memcpy(param_5,pCVar10,(ulonglong)uVar8);
  }
  HidBattReleaseStopLock(param_1);
  CUString::~CUString((CUString *)local_48);
  return iVar9;
}



===== HidBattQueryStatus @ 1c0002060 =====

long HidBattQueryStatus(longlong param_1,int param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  char cVar2;
  long lVar3;
  
  cVar2 = HidBattAcquireStopLock(param_1);
  if (cVar2 == '\0') {
    return -0x3ffffff2;
  }
  if ((param_2 != 0) && (*(short *)(*(longlong *)(param_1 + 0xf8) + 0x60) != 0)) {
    *param_3 = 0;
    param_3[1] = 0;
    lVar3 = CBattery::RefreshStatus(*(CBattery **)(param_1 + 0xf8));
    if (-1 < lVar3) {
      uVar1 = *(undefined8 *)(*(longlong *)(param_1 + 0xf8) + 0x28);
      *param_3 = *(undefined8 *)(*(longlong *)(param_1 + 0xf8) + 0x20);
      param_3[1] = uVar1;
      goto LAB_1c00020cd;
    }
  }
  lVar3 = -0x3ffffff2;
LAB_1c00020cd:
  HidBattReleaseStopLock(param_1);
  return lVar3;
}



===== HidBattQueryTag @ 1c0002100 =====

undefined8 HidBattQueryTag(longlong param_1,uint *param_2)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = HidBattAcquireStopLock(param_1);
  if (cVar1 == '\0') {
    uVar2 = 0xc000000e;
  }
  else {
    *param_2 = (uint)*(ushort *)(*(longlong *)(param_1 + 0xf8) + 0x60);
    HidBattReleaseStopLock(param_1);
    uVar2 = 0;
  }
  return uVar2;
}



===== HidBattSetStatusNotify @ 1c0002150 =====

uint HidBattSetStatusNotify(longlong param_1,uint param_2,longlong param_3)

{
  CBattery *this;
  char cVar1;
  bool bVar2;
  CUsage *pCVar3;
  short sVar4;
  uint uVar5;
  ulong local_res8 [2];
  
  this = *(CBattery **)(param_1 + 0xf8);
  cVar1 = HidBattAcquireStopLock(param_1);
  if (cVar1 == '\0') {
    return 0xc000000e;
  }
  if (*(ushort *)(this + 0x60) != param_2) {
    HidBattReleaseStopLock(param_1);
    return 0xc000000e;
  }
  if ((*(int *)(param_3 + 8) == -1) ||
     (local_res8[0] = *(ulong *)(param_3 + 4), local_res8[0] == 0xffffffff)) {
    HidBattReleaseStopLock(param_1);
    return 0xc00000bb;
  }
  if (this[0x11] == (CBattery)0x0) {
    if (local_res8[0] == 0) {
      local_res8[0] = 0;
    }
    else {
      pCVar3 = CBattery::GetUsage(this,0x11);
      if ((pCVar3 == (CUsage *)0x0) || (**(int **)pCVar3 == 0)) {
        local_res8[0] = *(ulong *)(param_3 + 4);
      }
      else {
        pCVar3 = CBattery::GetUsage(this,0x11);
        if (pCVar3 == (CUsage *)0x0) {
          sVar4 = 0;
        }
        else {
          sVar4 = *(short *)(*(longlong *)pCVar3 + 4);
        }
        uVar5 = *(uint *)(this + 0x28);
        if (uVar5 == 0) {
          uVar5 = 24000;
        }
        local_res8[0] =
             CorrectExponent((uint)((*(int *)(param_3 + 4) / 36000) * 1000) / uVar5,-2,sVar4);
      }
    }
  }
  bVar2 = CBattery::GetSetValue(this,0xc,local_res8,true);
  HidBattReleaseStopLock(param_1);
  return ~-(uint)bVar2 & 0xc0000001;
}



===== CCollection @ 1c000229c =====

/* public: __cdecl CCollection::CCollection(struct _HIDP_LINK_COLLECTION_NODE * __ptr64,unsigned
   short,unsigned short) __ptr64 */

CCollection * __thiscall
CCollection::CCollection
          (CCollection *this,_HIDP_LINK_COLLECTION_NODE *param_1,ushort param_2,ushort param_3)

{
  CCollectionArray *pCVar1;
  undefined6 in_register_00000082;
  
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  pCVar1 = operator_new(0x10,(__uint64)param_1,(ulong)CONCAT62(in_register_00000082,param_2));
  if (pCVar1 != (CCollectionArray *)0x0) {
    pCVar1 = (CCollectionArray *)CCollectionArray::CCollectionArray(pCVar1,param_1,param_2,param_3);
    if (pCVar1 != (CCollectionArray *)0x0) {
      if (*(short *)(pCVar1 + 8) == 0) {
        CCollectionArray::~CCollectionArray(pCVar1);
        ExFreePoolWithTag(pCVar1,0);
      }
      else {
        *(CCollectionArray **)(this + 0x10) = pCVar1;
      }
    }
  }
  *(undefined2 *)this = *(undefined2 *)(param_1 + (ulonglong)param_3 * 0x18);
  *(undefined2 *)(this + 2) = *(undefined2 *)(param_1 + (ulonglong)param_3 * 0x18 + 2);
  *(ushort *)(this + 0x18) = param_3;
  return this;
}



===== CCollectionArray @ 1c000235c =====

/* public: __cdecl CCollectionArray::CCollectionArray(struct _HIDP_LINK_COLLECTION_NODE *
   __ptr64,unsigned short,short) __ptr64 */

CCollectionArray * __thiscall
CCollectionArray::CCollectionArray
          (CCollectionArray *this,_HIDP_LINK_COLLECTION_NODE *param_1,ushort param_2,short param_3)

{
  longlong *_Src;
  CCollection *pCVar1;
  longlong lVar2;
  size_t _Size;
  longlong *plVar3;
  __uint64 _Var4;
  ushort uVar5;
  ulonglong uVar6;
  ushort uVar7;
  ulong uVar8;
  
  *(undefined8 *)this = 0;
  *(undefined2 *)(this + 8) = 0;
  uVar7 = 0;
  plVar3 = (longlong *)0x0;
  if (param_3 == -1) {
    _Var4 = 8;
    uVar8 = 0x48746142;
    _Src = (longlong *)ExAllocatePool2(0x40);
    if (_Src == (longlong *)0x0) {
      return this;
    }
    pCVar1 = operator_new(0x28,_Var4,uVar8);
    if (pCVar1 == (CCollection *)0x0) {
      *_Src = 0;
    }
    else {
      lVar2 = CCollection::CCollection(pCVar1,param_1,param_2,0);
      *_Src = lVar2;
      if (lVar2 != 0) {
        uVar7 = 1;
        plVar3 = _Src;
        goto LAB_1c00023e4;
      }
    }
LAB_1c0002544:
    ExFreePoolWithTag(_Src,0x48746142);
  }
  else {
    uVar5 = 1;
    if (1 < param_2) {
      _Src = plVar3;
      do {
        plVar3 = _Src;
        if ((uint)*(ushort *)(param_1 + (ulonglong)uVar5 * 0x18 + 4) == (int)param_3) {
          _Size = (ulonglong)uVar7 * 8;
          uVar8 = 0x48746142;
          _Var4 = _Size + 8;
          plVar3 = (longlong *)ExAllocatePool2(0x40);
          if (plVar3 == (longlong *)0x0) {
            if (_Src == (longlong *)0x0) {
              return this;
            }
          }
          else {
            if (uVar7 != 0) {
              memcpy(plVar3,_Src,_Size);
              uVar8 = (ulong)_Size;
              _Var4 = 0x48746142;
              ExFreePoolWithTag(_Src);
            }
            pCVar1 = operator_new(0x28,_Var4,uVar8);
            if (pCVar1 == (CCollection *)0x0) {
              lVar2 = 0;
            }
            else {
              lVar2 = CCollection::CCollection(pCVar1,param_1,param_2,uVar5);
            }
            plVar3[uVar7] = lVar2;
            _Src = plVar3;
            if (lVar2 != 0) {
              uVar7 = uVar7 + 1;
              goto LAB_1c00024f0;
            }
          }
          if (uVar7 != 0) {
            uVar6 = (ulonglong)uVar7;
            plVar3 = _Src;
            do {
              pCVar1 = (CCollection *)*plVar3;
              if (pCVar1 != (CCollection *)0x0) {
                CCollection::~CCollection(pCVar1);
                ExFreePoolWithTag(pCVar1,0);
              }
              plVar3 = plVar3 + 1;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          goto LAB_1c0002544;
        }
LAB_1c00024f0:
        uVar5 = uVar5 + 1;
        _Src = plVar3;
      } while (uVar5 < param_2);
    }
LAB_1c00023e4:
    *(longlong **)this = plVar3;
    *(ushort *)(this + 8) = uVar7;
  }
  return this;
}



===== CProperties @ 1c0002564 =====

/* public: __cdecl CProperties::CProperties(class CUsage * __ptr64) __ptr64 */

CProperties * __thiscall CProperties::CProperties(CProperties *this,CUsage *param_1)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  undefined2 uVar4;
  uint uVar5;
  uint *puVar6;
  undefined2 *puVar7;
  ulong in_R8D;
  undefined2 *puVar8;
  
  iVar2 = *(int *)(param_1 + 0x18);
  puVar8 = (undefined2 *)0x0;
  puVar7 = (undefined2 *)0x0;
  if (iVar2 == 1) {
LAB_1c00025d9:
    puVar7 = *(undefined2 **)(param_1 + 0x10);
    *(undefined4 *)this = *(undefined4 *)(puVar7 + 0x12);
    *(undefined2 *)(this + 4) = puVar7[0x10];
    *(undefined4 *)(this + 8) = *(undefined4 *)(puVar7 + 0x14);
    *(undefined4 *)(this + 0xc) = *(undefined4 *)(puVar7 + 0x16);
    *(undefined2 *)(this + 0x10) = puVar7[3];
    *(ushort *)(this + 0x12) = (ushort)*(byte *)(puVar7 + 1);
    *(undefined2 *)(this + 0x14) = puVar7[0x1c];
    uVar4 = *puVar7;
LAB_1c0002611:
    *(undefined2 *)(this + 0x16) = uVar4;
  }
  else {
    if (iVar2 == 2) {
LAB_1c00025aa:
      puVar8 = *(undefined2 **)(param_1 + 8);
      *(undefined2 *)(this + 4) = 0;
      *(undefined4 *)this = 0;
      *(undefined8 *)(this + 8) = 0;
      *(undefined2 *)(this + 0x10) = puVar8[3];
      *(ushort *)(this + 0x12) = (ushort)*(byte *)(puVar8 + 1);
      *(undefined2 *)(this + 0x14) = puVar8[0x1c];
      uVar4 = *puVar8;
      goto LAB_1c0002611;
    }
    if (iVar2 == 3) goto LAB_1c00025d9;
    if (iVar2 == 4) goto LAB_1c00025aa;
    if (iVar2 == 5) goto LAB_1c00025d9;
    if (iVar2 == 6) goto LAB_1c00025aa;
  }
  puVar6 = operator_new(4,(__uint64)param_1,in_R8D);
  if (puVar6 == (uint *)0x0) {
    puVar6 = (uint *)0x0;
  }
  else {
    *puVar6 = *puVar6 & 0xffffff80;
  }
  *(uint **)(this + 0x18) = puVar6;
  if (puVar6 == (uint *)0x0) {
    return this;
  }
  if (iVar2 - 3U < 2) {
    *puVar6 = *puVar6 | 0x20;
  }
  if ((iVar2 - 2U & 0xfffffffb) == 0) {
    bVar1 = *(byte *)(puVar8 + 2);
LAB_1c0002661:
    if ((bVar1 & 1) != 0) {
      **(uint **)(this + 0x18) = **(uint **)(this + 0x18) | 4;
    }
    if (iVar2 == 1) {
      cVar3 = *(char *)(puVar7 + 2);
    }
    else {
      if (iVar2 != 2) goto LAB_1c00026bc;
      cVar3 = *(char *)(puVar8 + 2);
    }
    if (cVar3 < '\0') {
      **(uint **)(this + 0x18) = **(uint **)(this + 0x18) | 0x40;
    }
LAB_1c0002688:
    puVar6 = *(uint **)(this + 0x18);
    uVar5 = *puVar6 & 0xfffffffd | 1;
  }
  else {
    if ((iVar2 - 1U & 0xfffffffb) == 0) {
      bVar1 = *(byte *)(puVar7 + 2);
      goto LAB_1c0002661;
    }
LAB_1c00026bc:
    if ((iVar2 == 1) || (iVar2 == 2)) goto LAB_1c0002688;
    if ((iVar2 != 3) && (iVar2 != 4)) {
      if ((iVar2 == 5) || (iVar2 == 6)) {
        **(uint **)(this + 0x18) = **(uint **)(this + 0x18) | 3;
      }
      goto LAB_1c0002696;
    }
    puVar6 = *(uint **)(this + 0x18);
    uVar5 = *puVar6 & 0xfffffffe | 2;
  }
  *puVar6 = uVar5;
LAB_1c0002696:
  **(uint **)(this + 0x18) = **(uint **)(this + 0x18) | 0x10;
  return this;
}



===== ~CCollection @ 1c00026f8 =====

/* public: __cdecl CCollection::~CCollection(void) __ptr64 */

void __thiscall CCollection::~CCollection(CCollection *this)

{
  CUsageArray *this_00;
  CCollectionArray *this_01;
  
  this_00 = *(CUsageArray **)(this + 8);
  if (this_00 != (CUsageArray *)0x0) {
    CUsageArray::~CUsageArray(this_00);
    ExFreePoolWithTag(this_00,0);
  }
  this_01 = *(CCollectionArray **)(this + 0x10);
  if (this_01 != (CCollectionArray *)0x0) {
    CCollectionArray::~CCollectionArray(this_01);
    ExFreePoolWithTag(this_01,0);
  }
  return;
}



===== ~CCollectionArray @ 1c000275c =====

/* public: __cdecl CCollectionArray::~CCollectionArray(void) __ptr64 */

void __thiscall CCollectionArray::~CCollectionArray(CCollectionArray *this)

{
  CCollection *this_00;
  short sVar1;
  
  sVar1 = *(short *)(this + 8);
  while (sVar1 != 0) {
    *(ushort *)(this + 8) = sVar1 - 1U;
    this_00 = *(CCollection **)(*(longlong *)this + (ulonglong)(ushort)(sVar1 - 1U) * 8);
    if (this_00 != (CCollection *)0x0) {
      CCollection::~CCollection(this_00);
      ExFreePoolWithTag(this_00,0);
    }
    sVar1 = *(short *)(this + 8);
  }
  if (*(longlong *)this != 0) {
    ExFreePoolWithTag(*(longlong *)this,0);
  }
  return;
}



===== ~CHidDevice @ 1c00027dc =====

/* public: __cdecl CHidDevice::~CHidDevice(void) __ptr64 */

void __thiscall CHidDevice::~CHidDevice(CHidDevice *this)

{
  CCollectionArray *this_00;
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  CHidDevice *pCVar4;
  
  if (*(longlong *)this != 0) {
    lVar2 = *(longlong *)(*(longlong *)this + 0x18);
    if (lVar2 != 0) {
      ExFreePoolWithTag(lVar2,0);
    }
    if (*(longlong *)(*(longlong *)this + 0x20) != 0) {
      ExFreePoolWithTag(*(longlong *)(*(longlong *)this + 0x20),0);
    }
    if (*(longlong *)(*(longlong *)this + 0x40) != 0) {
      ExFreePoolWithTag(*(longlong *)(*(longlong *)this + 0x40),0);
    }
    if (*(longlong *)(*(longlong *)this + 0x48) != 0) {
      ExFreePoolWithTag(*(longlong *)(*(longlong *)this + 0x48),0);
    }
    if (*(longlong *)(*(longlong *)this + 0x68) != 0) {
      ExFreePoolWithTag(*(longlong *)(*(longlong *)this + 0x68),0);
    }
    if (*(longlong *)(*(longlong *)this + 0x70) != 0) {
      ExFreePoolWithTag(*(longlong *)(*(longlong *)this + 0x70),0);
    }
    ExFreePoolWithTag(*(undefined8 *)this,0);
  }
  this_00 = *(CCollectionArray **)(this + 0x28);
  if (this_00 != (CCollectionArray *)0x0) {
    CCollectionArray::~CCollectionArray(this_00);
    ExFreePoolWithTag(this_00,0);
    *(undefined8 *)(this + 0x28) = 0;
  }
  lVar3 = 0x100;
  pCVar4 = this + 0x30;
  lVar2 = 0x100;
  do {
    if (*(longlong **)pCVar4 != (longlong *)0x0) {
      lVar1 = **(longlong **)pCVar4;
      if (lVar1 != 0) {
        ExFreePoolWithTag(lVar1,0);
      }
      ExFreePoolWithTag(*(longlong *)pCVar4);
      *(longlong *)pCVar4 = 0;
    }
    pCVar4 = pCVar4 + 8;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  if (*(longlong *)(this + 0x830) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x830),0);
    *(undefined8 *)(this + 0x830) = 0;
  }
  pCVar4 = this + 0x838;
  do {
    if (*(longlong *)pCVar4 != 0) {
      ExFreePoolWithTag(*(longlong *)pCVar4,0);
      *(longlong *)pCVar4 = 0;
    }
    pCVar4 = pCVar4 + 8;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  if (*(longlong *)(this + 0x1078) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x1078),0);
  }
  if (*(longlong *)(this + 0x1080) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x1080),0);
  }
  return;
}



===== ~CProperties @ 1c00029b4 =====

/* public: __cdecl CProperties::~CProperties(void) __ptr64 */

void __thiscall CProperties::~CProperties(CProperties *this)

{
  if (*(longlong *)(this + 0x18) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x18),0);
    *(undefined8 *)(this + 0x18) = 0;
  }
  return;
}



===== ~CUsage @ 1c00029e8 =====

/* public: __cdecl CUsage::~CUsage(void) __ptr64 */

void __thiscall CUsage::~CUsage(CUsage *this)

{
  CProperties *this_00;
  
  this_00 = *(CProperties **)this;
  if (this_00 != (CProperties *)0x0) {
    CProperties::~CProperties(this_00);
    ExFreePoolWithTag(this_00,0);
  }
  return;
}



===== ~CUsageArray @ 1c0002a1c =====

/* public: __cdecl CUsageArray::~CUsageArray(void) __ptr64 */

void __thiscall CUsageArray::~CUsageArray(CUsageArray *this)

{
  CUsage *this_00;
  short sVar1;
  
  sVar1 = *(short *)(this + 8);
  while (sVar1 != 0) {
    *(ushort *)(this + 8) = sVar1 - 1U;
    this_00 = *(CUsage **)(*(longlong *)this + (ulonglong)(ushort)(sVar1 - 1U) * 8);
    if (this_00 != (CUsage *)0x0) {
      CUsage::~CUsage(this_00);
      ExFreePoolWithTag(this_00,0);
    }
    sVar1 = *(short *)(this + 8);
  }
  if (*(longlong *)this != 0) {
    ExFreePoolWithTag(*(longlong *)this,0);
  }
  return;
}



===== ~CUsagePath @ 1c0002a9c =====

/* public: __cdecl CUsagePath::~CUsagePath(void) __ptr64 */

void __thiscall CUsagePath::~CUsagePath(CUsagePath *this)

{
  CUsagePath *this_00;
  
  this_00 = *(CUsagePath **)(this + 0x10);
  *(undefined8 *)(this + 0x10) = 0;
  if (this_00 != (CUsagePath *)0x0) {
    ~CUsagePath(this_00);
    ExFreePoolWithTag(this_00,0);
  }
  return;
}



===== ActivateInput @ 1c0002ad8 =====

/* public: long __cdecl CHidDevice::ActivateInput(void) __ptr64 */

long __thiscall CHidDevice::ActivateInput(CHidDevice *this)

{
  int iVar1;
  longlong lVar2;
  undefined8 local_res8;
  
  local_res8 = 0;
  if (*(longlong *)(this + 0x830) == 0) {
    if (*(short *)(*(longlong *)(this + 0x1080) + 4) == 0) {
      return 0;
    }
    lVar2 = ExAllocatePool2(0x40,*(short *)(*(longlong *)(this + 0x1080) + 4),0x48746142);
    *(longlong *)(this + 0x830) = lVar2;
    if (lVar2 == 0) {
      return -0x3fffff66;
    }
  }
  KeInitializeEvent(this + 0x1048,0,0);
  iVar1 = PsCreateSystemThread(&local_res8,0x1fffff,0,0,0,ReadThread,this);
  if (iVar1 < 0) {
    ExFreePoolWithTag(*(undefined8 *)(this + 0x830),0);
    *(undefined8 *)(this + 0x830) = 0;
    return iVar1;
  }
  iVar1 = ObReferenceObjectByHandle(local_res8,0x1fffff,0,0,this + 0x1038,0);
  if (iVar1 < 0) {
    this[0x1040] = (CHidDevice)0x1;
  }
  else {
    ZwClose(local_res8);
  }
  return 0;
}



===== AddUsage @ 1c0002c10 =====

/* public: void __cdecl CUsageArray::AddUsage(class CUsage * __ptr64) __ptr64 */

void __thiscall CUsageArray::AddUsage(CUsageArray *this,CUsage *param_1)

{
  void *_Src;
  void *_Dst;
  
  _Src = *(void **)this;
  _Dst = (void *)ExAllocatePool2(0x40,(ulonglong)*(ushort *)(this + 8) * 8 + 8,0x48746142);
  *(void **)this = _Dst;
  if ((_Dst != (void *)0x0) && (_Src != (void *)0x0)) {
    memcpy(_Dst,_Src,(ulonglong)*(ushort *)(this + 8) << 3);
    ExFreePoolWithTag(_Src,0);
  }
  if (*(longlong *)this == 0) {
    *(void **)this = _Src;
    if (param_1 != (CUsage *)0x0) {
      CUsage::~CUsage(param_1);
      ExFreePoolWithTag(param_1,0);
    }
  }
  else {
    *(CUsage **)(*(longlong *)this + (ulonglong)*(ushort *)(this + 8) * 8) = param_1;
    *(short *)(this + 8) = *(short *)(this + 8) + 1;
  }
  return;
}



===== FindUsage @ 1c0002ccc =====

/* public: class CUsage * __ptr64 __cdecl CHidDevice::FindUsage(class CUsagePath * __ptr64,unsigned
   short) __ptr64 */

CUsage * __thiscall CHidDevice::FindUsage(CHidDevice *this,CUsagePath *param_1,ushort param_2)

{
  short *psVar1;
  CUsagePath *pCVar2;
  longlong lVar3;
  longlong *plVar4;
  CUsagePath *pCVar5;
  int iVar6;
  short *psVar7;
  longlong *plVar8;
  int iVar9;
  
  iVar6 = 0;
  plVar8 = *(longlong **)(this + 0x28);
  iVar9 = 0;
  psVar7 = (short *)0x0;
  if (*(CUsagePath **)(param_1 + 0x10) != (CUsagePath *)0x0) {
    lVar3 = 0;
    pCVar2 = *(CUsagePath **)(param_1 + 0x10);
    do {
      pCVar5 = pCVar2;
      if (plVar8 != (longlong *)0x0) {
        for (; iVar9 < (int)(uint)*(ushort *)(plVar8 + 1); iVar9 = iVar9 + 1) {
          psVar1 = *(short **)(*plVar8 + lVar3 * 8);
          if ((psVar1[1] == *(short *)param_1) && (*psVar1 == *(short *)(param_1 + 2))) {
            plVar8 = *(longlong **)(psVar1 + 8);
            iVar9 = 0;
            lVar3 = 0;
            psVar7 = psVar1;
            goto LAB_1c0002d44;
          }
          lVar3 = lVar3 + 1;
        }
        if (lVar3 != 0) {
          return (CUsage *)0x0;
        }
      }
LAB_1c0002d44:
      param_1 = pCVar5;
      pCVar2 = *(CUsagePath **)(pCVar5 + 0x10);
    } while (*(CUsagePath **)(pCVar5 + 0x10) != (CUsagePath *)0x0);
    if (((psVar7 != (short *)0x0) &&
        (plVar8 = *(longlong **)(psVar7 + 4), plVar8 != (longlong *)0x0)) &&
       (*(ushort *)(plVar8 + 1) != 0)) {
      plVar4 = (longlong *)*plVar8;
      do {
        lVar3 = *(longlong *)*plVar4;
        if (((*(short *)(lVar3 + 0x14) == *(short *)(pCVar5 + 2)) &&
            (*(short *)(lVar3 + 0x16) == *(short *)pCVar5)) &&
           ((int)((longlong *)*plVar4)[3] - 1U < 4)) {
          return (CUsage *)((longlong *)*plVar8)[iVar6];
        }
        iVar6 = iVar6 + 1;
        plVar4 = plVar4 + 1;
      } while (iVar6 < (int)(uint)*(ushort *)(plVar8 + 1));
    }
  }
  return (CUsage *)0x0;
}



===== GetNextUsage @ 1c0002dc4 =====

/* bool __cdecl GetNextUsage(class CHidDevice * __ptr64,short,unsigned short,unsigned short,class
   CUsage * __ptr64 * __ptr64) */

bool __cdecl
GetNextUsage(CHidDevice *param_1,short param_2,ushort param_3,ushort param_4,CUsage **param_5)

{
  uint uVar1;
  CUsage *pCVar2;
  ushort *puVar3;
  __uint64 _Var4;
  longlong lVar5;
  int iVar6;
  longlong lVar7;
  
  lVar5 = *(longlong *)(param_1 + 0x1080);
  uVar1 = (uint)param_4;
  _Var4 = 0;
  iVar6 = 0;
  if (*(ushort *)(lVar5 + 0x3c) != 0) {
    lVar7 = 0;
    puVar3 = (ushort *)(*(longlong *)(*(longlong *)param_1 + 0x70) + 6);
    do {
      if (*puVar3 == param_3) {
        if (uVar1 == (uint)_Var4) {
          pCVar2 = operator_new(0x30,_Var4,(ulong)lVar7);
          if (pCVar2 == (CUsage *)0x0) {
            return false;
          }
          *(undefined8 *)pCVar2 = 0;
          *(undefined8 *)(pCVar2 + 8) = 0;
          *(undefined8 *)(pCVar2 + 0x10) = 0;
          *(undefined4 *)(pCVar2 + 0x18) = 0;
          *(undefined8 *)(pCVar2 + 0x20) = 0;
          lVar5 = *(longlong *)(*(longlong *)param_1 + 0x70);
          *(undefined4 *)(pCVar2 + 0x18) = 1;
          *(longlong *)(pCVar2 + 0x10) = lVar5 + (longlong)iVar6 * 0x48;
          *param_5 = pCVar2;
          return true;
        }
        _Var4 = (__uint64)((uint)_Var4 + 1);
      }
      iVar6 = iVar6 + 1;
      lVar7 = lVar7 + 1;
      puVar3 = puVar3 + 0x24;
    } while (lVar7 < (longlong)(ulonglong)*(ushort *)(lVar5 + 0x3c));
  }
  iVar6 = 0;
  if (*(ushort *)(lVar5 + 0x3a) != 0) {
    lVar7 = 0;
    puVar3 = (ushort *)(*(longlong *)(*(longlong *)param_1 + 0x68) + 6);
    do {
      if (*puVar3 == param_3) {
        if (uVar1 == (uint)_Var4) {
          pCVar2 = operator_new(0x30,_Var4,(ulong)lVar7);
          if (pCVar2 == (CUsage *)0x0) {
            return false;
          }
          *(undefined8 *)pCVar2 = 0;
          *(undefined8 *)(pCVar2 + 8) = 0;
          *(undefined8 *)(pCVar2 + 0x10) = 0;
          *(undefined4 *)(pCVar2 + 0x18) = 0;
          *(undefined8 *)(pCVar2 + 0x20) = 0;
          lVar7 = (longlong)iVar6 * 9;
          lVar5 = *(longlong *)(*(longlong *)param_1 + 0x68);
          *(undefined4 *)(pCVar2 + 0x18) = 2;
          goto LAB_1c0003004;
        }
        _Var4 = (__uint64)((uint)_Var4 + 1);
      }
      iVar6 = iVar6 + 1;
      lVar7 = lVar7 + 1;
      puVar3 = puVar3 + 0x24;
    } while (lVar7 < (longlong)(ulonglong)*(ushort *)(lVar5 + 0x3a));
  }
  iVar6 = 0;
  if (*(ushort *)(lVar5 + 0x30) != 0) {
    lVar7 = 0;
    puVar3 = (ushort *)(*(longlong *)(*(longlong *)param_1 + 0x20) + 6);
    do {
      if (*puVar3 == param_3) {
        if (uVar1 == (uint)_Var4) {
          pCVar2 = operator_new(0x30,_Var4,(ulong)lVar7);
          if (pCVar2 == (CUsage *)0x0) {
            return false;
          }
          *(undefined8 *)pCVar2 = 0;
          *(undefined8 *)(pCVar2 + 8) = 0;
          *(undefined8 *)(pCVar2 + 0x10) = 0;
          *(undefined4 *)(pCVar2 + 0x18) = 0;
          *(undefined8 *)(pCVar2 + 0x20) = 0;
          lVar5 = *(longlong *)(*(longlong *)param_1 + 0x20);
          *(undefined4 *)(pCVar2 + 0x18) = 3;
          *(longlong *)(pCVar2 + 0x10) = lVar5 + (longlong)iVar6 * 0x48;
          goto LAB_1c000300c;
        }
        _Var4 = (__uint64)((uint)_Var4 + 1);
      }
      iVar6 = iVar6 + 1;
      lVar7 = lVar7 + 1;
      puVar3 = puVar3 + 0x24;
    } while (lVar7 < (longlong)(ulonglong)*(ushort *)(lVar5 + 0x30));
  }
  iVar6 = 0;
  if (*(ushort *)(lVar5 + 0x2e) != 0) {
    lVar7 = 0;
    puVar3 = (ushort *)(*(longlong *)(*(longlong *)param_1 + 0x18) + 6);
    do {
      if (*puVar3 == param_3) {
        if (uVar1 == (uint)_Var4) {
          pCVar2 = operator_new(0x30,_Var4,(ulong)lVar7);
          if (pCVar2 == (CUsage *)0x0) {
            return false;
          }
          *(undefined8 *)pCVar2 = 0;
          *(undefined8 *)(pCVar2 + 8) = 0;
          *(undefined8 *)(pCVar2 + 0x10) = 0;
          *(undefined4 *)(pCVar2 + 0x18) = 0;
          *(undefined8 *)(pCVar2 + 0x20) = 0;
          lVar7 = (longlong)iVar6 * 9;
          lVar5 = *(longlong *)(*(longlong *)param_1 + 0x18);
          *(undefined4 *)(pCVar2 + 0x18) = 4;
          goto LAB_1c0003004;
        }
        _Var4 = (__uint64)((uint)_Var4 + 1);
      }
      iVar6 = iVar6 + 1;
      lVar7 = lVar7 + 1;
      puVar3 = puVar3 + 0x24;
    } while (lVar7 < (longlong)(ulonglong)*(ushort *)(lVar5 + 0x2e));
  }
  iVar6 = 0;
  if (*(ushort *)(lVar5 + 0x36) != 0) {
    lVar7 = 0;
    puVar3 = (ushort *)(*(longlong *)(*(longlong *)param_1 + 0x48) + 6);
    do {
      if (*puVar3 == param_3) {
        if (uVar1 == (uint)_Var4) {
          pCVar2 = operator_new(0x30,_Var4,(ulong)lVar7);
          if (pCVar2 == (CUsage *)0x0) {
            return false;
          }
          *(undefined8 *)pCVar2 = 0;
          *(undefined8 *)(pCVar2 + 8) = 0;
          *(undefined8 *)(pCVar2 + 0x10) = 0;
          *(undefined4 *)(pCVar2 + 0x18) = 0;
          *(undefined8 *)(pCVar2 + 0x20) = 0;
          lVar5 = *(longlong *)(*(longlong *)param_1 + 0x48);
          *(undefined4 *)(pCVar2 + 0x18) = 5;
          *(longlong *)(pCVar2 + 0x10) = lVar5 + (longlong)iVar6 * 0x48;
          goto LAB_1c000300c;
        }
        _Var4 = (__uint64)((uint)_Var4 + 1);
      }
      iVar6 = iVar6 + 1;
      lVar7 = lVar7 + 1;
      puVar3 = puVar3 + 0x24;
    } while (lVar7 < (longlong)(ulonglong)*(ushort *)(lVar5 + 0x36));
  }
  iVar6 = 0;
  if (*(ushort *)(lVar5 + 0x34) != 0) {
    lVar7 = 0;
    puVar3 = (ushort *)(*(longlong *)(*(longlong *)param_1 + 0x40) + 6);
    do {
      if (*puVar3 == param_3) {
        if (uVar1 == (uint)_Var4) {
          pCVar2 = operator_new(0x30,_Var4,(ulong)lVar7);
          if (pCVar2 == (CUsage *)0x0) {
            return false;
          }
          *(undefined8 *)pCVar2 = 0;
          *(undefined8 *)(pCVar2 + 8) = 0;
          *(undefined8 *)(pCVar2 + 0x10) = 0;
          *(undefined4 *)(pCVar2 + 0x18) = 0;
          *(undefined8 *)(pCVar2 + 0x20) = 0;
          lVar7 = (longlong)iVar6 * 9;
          lVar5 = *(longlong *)(*(longlong *)param_1 + 0x40);
          *(undefined4 *)(pCVar2 + 0x18) = 6;
LAB_1c0003004:
          *(longlong *)(pCVar2 + 8) = lVar5 + lVar7 * 8;
LAB_1c000300c:
          *param_5 = pCVar2;
          return true;
        }
        _Var4 = (__uint64)((uint)_Var4 + 1);
      }
      iVar6 = iVar6 + 1;
      lVar7 = lVar7 + 1;
      puVar3 = puVar3 + 0x24;
    } while (lVar7 < (longlong)(ulonglong)*(ushort *)(lVar5 + 0x34));
  }
  return false;
}



===== GetValue @ 1c0003134 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: bool __cdecl CUsage::GetValue(void) __ptr64 */

bool __thiscall CUsage::GetValue(CUsage *this)

{
  byte bVar1;
  longlong lVar2;
  char *pcVar3;
  longlong lVar4;
  code *pcVar5;
  byte *pbVar6;
  CHidDevice *pCVar7;
  uint uVar8;
  int iVar9;
  long lVar10;
  short *psVar11;
  short *psVar12;
  undefined8 uVar13;
  int iVar14;
  ulonglong uVar15;
  int local_res8 [2];
  int local_res10 [2];
  
  iVar9 = *(int *)(this + 0x18);
  iVar14 = 0;
  local_res8[0] = 0;
  if ((iVar9 == 1) || (iVar9 == 2)) {
    bVar1 = *(byte *)(*(longlong *)this + 0x12);
    uVar15 = (ulonglong)bVar1;
    if (*(longlong *)(*(longlong *)(this + 0x28) + 0x838 + uVar15 * 8) == 0) {
      uVar13 = ExAllocatePool2(0x40,(ulonglong)
                                    *(ushort *)
                                     (*(longlong *)(*(longlong *)(this + 0x28) + 0x1080) + 8) + 1);
      *(undefined8 *)(*(longlong *)(this + 0x28) + 0x838 + uVar15 * 8) = uVar13;
      pbVar6 = *(byte **)(*(longlong *)(this + 0x28) + 0x838 + uVar15 * 8);
      if (pbVar6 == (byte *)0x0) {
        return false;
      }
      *pbVar6 = bVar1;
      pCVar7 = *(CHidDevice **)(this + 0x28);
      DoIoctl(*(_DEVICE_OBJECT **)(pCVar7 + 0x10),0xb0192,(void *)0x0,0,
              *(void **)(pCVar7 + uVar15 * 8 + 0x838),
              *(ushort *)(*(longlong *)(pCVar7 + 0x1080) + 8) + 1,pCVar7);
    }
    if (*(uint **)(*(longlong *)this + 0x18) == (uint *)0x0) {
      return false;
    }
    if ((**(uint **)(*(longlong *)this + 0x18) >> 6 & 1) != 0) {
      memset(*(void **)(*(longlong *)(this + 0x28) + 0x838 + uVar15 * 8),0,
             (ulonglong)*(ushort *)(*(longlong *)(*(longlong *)(this + 0x28) + 0x1080) + 8) + 1);
      **(byte **)(*(longlong *)(this + 0x28) + 0x838 + uVar15 * 8) = bVar1;
      pCVar7 = *(CHidDevice **)(this + 0x28);
      lVar10 = DoIoctl(*(_DEVICE_OBJECT **)(pCVar7 + 0x10),0xb0192,(void *)0x0,0,
                       *(void **)(pCVar7 + uVar15 * 8 + 0x838),
                       *(ushort *)(*(longlong *)(pCVar7 + 0x1080) + 8) + 1,pCVar7);
      if (lVar10 < 0) {
        return false;
      }
    }
    lVar2 = *(longlong *)(this + 0x28);
    if (*(int *)(this + 0x18) == 1) {
      lVar4 = *(longlong *)this;
      iVar9 = HidP_GetUsageValue(2,*(undefined2 *)(lVar4 + 0x16),*(undefined2 *)(lVar4 + 0x10),
                                 *(undefined2 *)(lVar4 + 0x14),local_res8,
                                 *(undefined8 *)(lVar2 + 0x1078),
                                 *(undefined8 *)(lVar2 + 0x838 + uVar15 * 8),
                                 *(undefined2 *)(*(longlong *)(lVar2 + 0x1080) + 8));
      if (iVar9 < 0) {
        return false;
      }
    }
    else {
      local_res10[0] = HidP_MaxUsageListLength(2,0,*(undefined8 *)(lVar2 + 0x1078));
      psVar11 = (short *)ExAllocatePool2(0x40,local_res10[0] * 2,0x48746142);
      if (psVar11 == (short *)0x0) {
        return false;
      }
      lVar2 = *(longlong *)(this + 0x28);
      iVar9 = HidP_GetUsages(2,*(undefined2 *)(*(longlong *)this + 0x16),
                             *(undefined2 *)(*(longlong *)this + 0x10),psVar11,local_res10,
                             *(undefined8 *)(lVar2 + 0x1078),
                             *(undefined8 *)(lVar2 + 0x838 + uVar15 * 8),
                             *(undefined2 *)(*(longlong *)(lVar2 + 0x1080) + 8));
      if (iVar9 < 0) goto LAB_1c000329a;
      if (0 < local_res10[0]) {
        psVar12 = psVar11;
        do {
          if (*psVar12 == *(short *)(*(longlong *)this + 0x14)) {
            local_res8[0] = 1;
            break;
          }
          iVar14 = iVar14 + 1;
          psVar12 = psVar12 + 1;
        } while (iVar14 < local_res10[0]);
      }
      ExFreePoolWithTag(psVar11,0);
    }
    *(int *)(this + 0x20) = local_res8[0];
  }
  else {
    if ((iVar9 != 3) && (iVar9 != 4)) {
      return false;
    }
    lVar2 = *(longlong *)(this + 0x28);
    pcVar3 = *(char **)(lVar2 + 0x830);
    if (pcVar3 == (char *)0x0) {
      return false;
    }
    lVar4 = *(longlong *)this;
    if ((*pcVar3 == '\0') == (bool)*(char *)(lVar4 + 0x12)) {
      return false;
    }
    if (iVar9 == 3) {
      uVar8 = HidP_GetUsageValue(0,*(undefined2 *)(lVar4 + 0x16),*(undefined2 *)(lVar4 + 0x10),
                                 *(undefined2 *)(lVar4 + 0x14),local_res8,
                                 *(undefined8 *)(lVar2 + 0x1078),pcVar3,
                                 *(undefined2 *)(*(longlong *)(lVar2 + 0x1080) + 4));
      if ((uVar8 & 0xc0000000) == 0xc0000000) {
        return false;
      }
    }
    else {
      local_res10[0] = HidP_MaxUsageListLength(0,0,*(undefined8 *)(lVar2 + 0x1078));
      psVar11 = (short *)ExAllocatePool2(0x40,local_res10[0] << 2,0x48746142);
      if (psVar11 == (short *)0x0) {
        return false;
      }
      lVar2 = *(longlong *)(this + 0x28);
      iVar9 = HidP_GetUsages(0,*(undefined2 *)(*(longlong *)this + 0x16),
                             *(undefined2 *)(*(longlong *)this + 0x10),psVar11,local_res10,
                             *(undefined8 *)(lVar2 + 0x1078),*(undefined8 *)(lVar2 + 0x830),
                             *(undefined2 *)(*(longlong *)(lVar2 + 0x1080) + 4));
      if (iVar9 < 0) {
LAB_1c000329a:
        ExFreePoolWithTag(psVar11,0);
        return false;
      }
      iVar9 = 0;
      if (0 < local_res10[0]) {
        psVar12 = psVar11;
        do {
          if (*psVar12 == *(short *)(*(longlong *)this + 0x14)) {
            local_res8[0] = 1;
            break;
          }
          iVar9 = iVar9 + 1;
          psVar12 = psVar12 + 2;
        } while (iVar9 < local_res10[0]);
      }
      ExFreePoolWithTag(psVar11,0);
    }
    if (*(int *)(this + 0x20) != local_res8[0]) {
      *(int *)(this + 0x20) = local_res8[0];
      if (*(uint **)(*(longlong *)this + 0x18) == (uint *)0x0) {
        return false;
      }
      if ((**(uint **)(*(longlong *)this + 0x18) >> 5 & 1) != 0) {
        pcVar5 = *(code **)(*(longlong *)(this + 0x28) + 0x1088);
        if (pcVar5 != (code *)0x0) {
          (*pcVar5)(*(undefined8 *)(*(longlong *)(this + 0x28) + 0x1090),this);
        }
      }
    }
  }
  return true;
}



===== InitUsages @ 1c00035c4 =====

/* public: void __cdecl CCollection::InitUsages(class CHidDevice * __ptr64) __ptr64 */

void __thiscall CCollection::InitUsages(CCollection *this,CHidDevice *param_1)

{
  ushort uVar1;
  bool bVar2;
  ushort uVar3;
  undefined8 *puVar4;
  CProperties *this_00;
  undefined8 uVar5;
  CUsageArray *this_01;
  longlong *plVar6;
  CUsage *this_02;
  ulonglong uVar7;
  int iVar8;
  longlong lVar9;
  ulong uVar10;
  ushort uVar11;
  CUsage *local_res8;
  
  uVar7 = (ulonglong)*(ushort *)(this + 0x18);
  local_res8 = (CUsage *)0x0;
  uVar11 = 0;
  this_02 = (CUsage *)param_1;
  bVar2 = GetNextUsage(param_1,(short)param_1,*(ushort *)(this + 0x18),0,&local_res8);
  do {
    uVar10 = (ulong)uVar7;
    if (bVar2 == false) {
      plVar6 = *(longlong **)(this + 0x10);
      if ((plVar6 != (longlong *)0x0) && (iVar8 = 0, (short)plVar6[1] != 0)) {
        lVar9 = 0;
        do {
          InitUsages(*(CCollection **)(lVar9 + *plVar6),param_1);
          plVar6 = *(longlong **)(this + 0x10);
          lVar9 = lVar9 + 8;
          iVar8 = iVar8 + 1;
        } while (iVar8 < (int)(uint)*(ushort *)(plVar6 + 1));
      }
LAB_1c0003757:
      this_02 = local_res8;
LAB_1c000375c:
      if (this_02 != (CUsage *)0x0) {
        CUsage::~CUsage(this_02);
        ExFreePoolWithTag(this_02,0);
      }
      return;
    }
    if (*(longlong *)(this + 8) == 0) {
      puVar4 = operator_new(0x10,(__uint64)this_02,uVar10);
      if (puVar4 == (undefined8 *)0x0) {
        *(undefined8 *)(this + 8) = 0;
        goto LAB_1c0003757;
      }
      *(undefined2 *)(puVar4 + 1) = 0;
      *puVar4 = 0;
      *(undefined8 **)(this + 8) = puVar4;
    }
    this_00 = operator_new(0x20,(__uint64)this_02,uVar10);
    this_02 = local_res8;
    if (this_00 == (CProperties *)0x0) {
      uVar5 = 0;
    }
    else {
      uVar5 = CProperties::CProperties(this_00,local_res8);
    }
    *(undefined8 *)this_02 = uVar5;
    *(CHidDevice **)(this_02 + 0x28) = param_1;
    if (*(int *)(this_02 + 0x18) - 3U < 2) {
      uVar1 = *(ushort *)(*(longlong *)this_02 + 0x12);
      uVar3 = 0;
      do {
        uVar7 = (ulonglong)uVar3;
        if (*(ushort *)(param_1 + uVar7 * 2 + 0x10b8) == 0) {
          *(ushort *)(param_1 + uVar7 * 2 + 0x10b8) = uVar1;
          goto LAB_1c00036a7;
        }
        if (*(ushort *)(param_1 + uVar7 * 2 + 0x10b8) == uVar1) goto LAB_1c00036a7;
        uVar3 = uVar3 + 1;
      } while (uVar3 < 0x100);
      uVar3 = 0;
LAB_1c00036a7:
      this_01 = *(CUsageArray **)(param_1 + (ulonglong)uVar3 * 8 + 0x30);
      if (this_01 == (CUsageArray *)0x0) {
        this_01 = operator_new(0x10,uVar7,(uint)uVar1);
        if (this_01 == (CUsageArray *)0x0) {
          this_01 = (CUsageArray *)0x0;
        }
        else {
          *(undefined2 *)(this_01 + 8) = 0;
          *(undefined8 *)this_01 = 0;
        }
        *(CUsageArray **)(param_1 + (ulonglong)uVar3 * 8 + 0x30) = this_01;
        if (this_01 == (CUsageArray *)0x0) goto LAB_1c000375c;
      }
      CUsageArray::AddUsage(this_01,this_02);
    }
    uVar11 = uVar11 + 1;
    CUsageArray::AddUsage(*(CUsageArray **)(this + 8),this_02);
    uVar7 = (ulonglong)*(ushort *)(this + 0x18);
    local_res8 = (CUsage *)0x0;
    bVar2 = GetNextUsage(param_1,(short)this_02,*(ushort *)(this + 0x18),uVar11,&local_res8);
  } while( true );
}



===== OpenHidDevice @ 1c00037a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: bool __cdecl CHidDevice::OpenHidDevice(struct _DEVICE_OBJECT * __ptr64) __ptr64 */

bool __thiscall CHidDevice::OpenHidDevice(CHidDevice *this,_DEVICE_OBJECT *param_1)

{
  undefined2 *puVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  longlong lVar5;
  _HIDP_LINK_COLLECTION_NODE *p_Var6;
  _HID_DEVICE *p_Var7;
  CCollectionArray *pCVar8;
  longlong *plVar9;
  _HIDP_CAPS *p_Var10;
  _HIDP_LINK_COLLECTION_NODE *p_Var11;
  bool bVar12;
  undefined1 auStackY_88 [32];
  uint local_48 [2];
  ulonglong local_40;
  undefined4 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_88;
  local_40 = 0;
  local_38 = 0;
  *(undefined8 *)(this + 0x1078) = 0;
  *(undefined8 *)(this + 0x1080) = 0;
  *(undefined8 *)this = 0;
  *(undefined8 *)(this + 0x28) = 0;
  bVar12 = false;
  local_48[0] = 0;
  uVar2 = DoIoctl(param_1,0xb01a8,(void *)0x0,0,&local_40,0xc,(CHidDevice *)0x0);
  if ((uVar2 & 0xc0000000) != 0xc0000000) {
    pvVar4 = (void *)ExAllocatePool2(0x40,local_40 & 0xffffffff);
    *(void **)(this + 0x1078) = pvVar4;
    if (pvVar4 != (void *)0x0) {
      uVar2 = DoIoctl(param_1,0xb0193,(void *)0x0,0,pvVar4,(ulong)local_40,(CHidDevice *)0x0);
      if ((uVar2 & 0xc0000000) != 0xc0000000) {
        lVar5 = ExAllocatePool2(0x40,0x40,0x48746142);
        *(longlong *)(this + 0x1080) = lVar5;
        if ((lVar5 != 0) &&
           (uVar2 = HidP_GetCaps(*(undefined8 *)(this + 0x1078),lVar5),
           (uVar2 & 0xc0000000) != 0xc0000000)) {
          puVar1 = *(undefined2 **)(this + 0x1080);
          *(undefined2 *)(this + 0x20) = puVar1[1];
          *(undefined2 *)(this + 0x22) = *puVar1;
          local_48[0] = (uint)(ushort)puVar1[0x16];
          p_Var6 = (_HIDP_LINK_COLLECTION_NODE *)
                   ExAllocatePool2(0x40,(ulonglong)(ushort)puVar1[0x16] * 0x18,0x48746142);
          if (p_Var6 != (_HIDP_LINK_COLLECTION_NODE *)0x0) {
            p_Var11 = *(_HIDP_LINK_COLLECTION_NODE **)(this + 0x1078);
            iVar3 = HidP_GetLinkCollectionNodes(p_Var6,local_48);
            if (iVar3 == 0x110000) {
              p_Var10 = *(_HIDP_CAPS **)(this + 0x1080);
              p_Var7 = SetupHidData(*(_HIDP_PREPARSED_DATA **)(this + 0x1078),p_Var10,p_Var11);
              *(_HID_DEVICE **)this = p_Var7;
              if ((p_Var7 != (_HID_DEVICE *)0x0) &&
                 (pCVar8 = operator_new(0x10,(__uint64)p_Var10,(ulong)p_Var11),
                 pCVar8 != (CCollectionArray *)0x0)) {
                plVar9 = (longlong *)
                         CCollectionArray::CCollectionArray(pCVar8,p_Var6,(ushort)local_48[0],-1);
                if (plVar9 != (longlong *)0x0) {
                  *(longlong **)(this + 0x28) = plVar9;
                  bVar12 = true;
                  iVar3 = 0;
                  if ((short)plVar9[1] != 0) {
                    lVar5 = 0;
                    do {
                      CCollection::InitUsages(*(CCollection **)(lVar5 + *plVar9),this);
                      lVar5 = lVar5 + 8;
                      iVar3 = iVar3 + 1;
                    } while (iVar3 < (int)(uint)*(ushort *)(plVar9 + 1));
                  }
                }
              }
            }
            ExFreePoolWithTag(p_Var6,0);
            if (bVar12 != false) {
              return bVar12;
            }
          }
        }
      }
    }
  }
  pCVar8 = *(CCollectionArray **)(this + 0x28);
  if (pCVar8 != (CCollectionArray *)0x0) {
    CCollectionArray::~CCollectionArray(pCVar8);
    ExFreePoolWithTag(pCVar8,0);
    *(undefined8 *)(this + 0x28) = 0;
  }
  if (*(longlong *)this != 0) {
    ExFreePoolWithTag(*(longlong *)this,0);
    *(undefined8 *)this = 0;
  }
  if (*(longlong *)(this + 0x1080) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x1080),0);
    *(undefined8 *)(this + 0x1080) = 0;
  }
  if (*(longlong *)(this + 0x1078) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x1078),0);
    *(undefined8 *)(this + 0x1078) = 0;
  }
  return false;
}



===== ReadCompletionRoutine @ 1c0003a80 =====

/* long __cdecl ReadCompletionRoutine(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64,void *
   __ptr64) */

long __cdecl ReadCompletionRoutine(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  KeSetEvent((longlong)param_3 + 0x1048,0,0);
  return -0x3fffffea;
}



===== ReadThread @ 1c0003ab0 =====

/* void __cdecl ReadThread(void * __ptr64) */

void __cdecl ReadThread(void *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  char cVar4;
  int iVar5;
  longlong lVar6;
  ushort uVar7;
  longlong lVar8;
  short sVar9;
  
  sVar9 = 0;
  lVar2 = *(longlong *)((longlong)param_1 + 0x1090);
  cVar4 = HidBattAcquireStopLock(lVar2);
  if (cVar4 != '\0') {
    lVar6 = *(longlong *)((longlong)param_1 + 0x10);
    lVar6 = IoAllocateIrp(CONCAT71((int7)((ulonglong)lVar6 >> 8),*(undefined1 *)(lVar6 + 0x4c)),0);
    plVar1 = (longlong *)((longlong)param_1 + 0x10a0);
    *plVar1 = lVar6;
    if (lVar6 != 0) {
      lVar6 = IoAllocateMdl(*(undefined8 *)((longlong)param_1 + 0x830),
                            *(undefined2 *)(*(longlong *)((longlong)param_1 + 0x1080) + 4),0,0,0);
      if (lVar6 != 0) {
        MmProbeAndLockPages(lVar6,0,1);
        while( true ) {
          while( true ) {
            IoReuseIrp(*plVar1,0);
            *(void **)(*plVar1 + 0x98) = SystemReserved1[0xf];
            *(longlong *)(*plVar1 + 8) = lVar6;
            lVar8 = *(longlong *)(*plVar1 + 0xb8);
            *(code **)(lVar8 + -0x10) = ReadCompletionRoutine;
            *(void **)(lVar8 + -8) = param_1;
            *(undefined1 *)(lVar8 + -0x45) = 0xe0;
            lVar8 = *(longlong *)(*plVar1 + 0xb8);
            *(undefined8 *)(lVar8 + -0x18) = *(undefined8 *)((longlong)param_1 + 0x1098);
            *(undefined1 *)(lVar8 + -0x48) = 3;
            *(uint *)(lVar8 + -0x40) =
                 (uint)*(ushort *)(*(longlong *)((longlong)param_1 + 0x1080) + 4);
            *(undefined8 *)(lVar8 + -0x30) = 0;
            KeResetEvent((longlong)param_1 + 0x1048);
            iVar5 = IofCallDriver(*(longlong *)((longlong)param_1 + 0x10));
            HidBattReleaseStopLock(lVar2);
            if (iVar5 == 0x103) {
              KeWaitForSingleObject((longlong)param_1 + 0x1048,0,0,0,0);
              iVar5 = *(int *)(*plVar1 + 0x30);
            }
            if (iVar5 == 0) break;
            if (((iVar5 == -0x3fffff63) || (iVar5 == -0x3ffffee0)) ||
               ((sVar9 == 9 || (cVar4 = HidBattAcquireStopLock(lVar2), cVar4 == '\0'))))
            goto LAB_1c0003d8b;
            sVar9 = sVar9 + 2;
          }
          sVar9 = 0;
          cVar4 = HidBattAcquireStopLock(lVar2);
          if (cVar4 == '\0') break;
          uVar7 = 0;
          do {
            if (*(ushort *)((longlong)param_1 + (ulonglong)uVar7 * 2 + 0x10b8) ==
                (ushort)**(byte **)((longlong)param_1 + 0x830)) break;
            uVar7 = uVar7 + 1;
          } while (uVar7 < 0x100);
          if (((uVar7 != 0x100) &&
              (plVar3 = *(longlong **)((longlong)param_1 + (ulonglong)uVar7 * 8 + 0x30),
              plVar3 != (longlong *)0x0)) && ((short)plVar3[1] != 0)) {
            lVar8 = 0;
            iVar5 = 0;
            do {
              CUsage::GetValue(*(CUsage **)(lVar8 + *plVar3));
              iVar5 = iVar5 + 1;
              lVar8 = lVar8 + 8;
            } while (iVar5 < (int)(uint)*(ushort *)(plVar3 + 1));
          }
        }
LAB_1c0003d8b:
        MmUnlockPages(lVar6);
        IoFreeMdl(lVar6);
      }
    }
  }
  *(undefined2 *)(*(longlong *)(lVar2 + 0xf8) + 0x60) = 0;
  PsTerminateSystemThread(0);
  return;
}



===== SetValue @ 1c0003ddc =====

/* public: bool __cdecl CUsage::SetValue(unsigned long) __ptr64 */

bool __thiscall CUsage::SetValue(CUsage *this,ulong param_1)

{
  longlong lVar1;
  longlong lVar2;
  ushort uVar3;
  long lVar4;
  undefined1 *puVar5;
  short sVar6;
  undefined8 in_stack_ffffffffffffffc8;
  undefined4 uVar7;
  
  uVar7 = (undefined4)((ulonglong)in_stack_ffffffffffffffc8 >> 0x20);
  if (1 < *(int *)(this + 0x18) - 3U) {
    if (*(int *)(this + 0x18) - 5U < 2) {
      uVar3 = *(ushort *)(*(longlong *)(*(longlong *)(this + 0x28) + 0x1080) + 6);
      sVar6 = 1;
    }
    else {
      sVar6 = 2;
      uVar3 = *(short *)(*(longlong *)(*(longlong *)(this + 0x28) + 0x1080) + 8) + 1;
    }
    puVar5 = (undefined1 *)ExAllocatePool2(0x40,(ulonglong)uVar3 + 1,0x48746142);
    if (puVar5 != (undefined1 *)0x0) {
      lVar1 = *(longlong *)this;
      lVar2 = *(longlong *)(this + 0x28);
      *puVar5 = *(undefined1 *)(lVar1 + 0x12);
      HidP_SetUsageValue(sVar6,*(undefined2 *)(lVar1 + 0x16),*(undefined2 *)(lVar1 + 0x10),
                         *(undefined2 *)(lVar1 + 0x14),CONCAT44(uVar7,param_1),
                         *(undefined8 *)(lVar2 + 0x1078),puVar5,uVar3 - 1);
      if (sVar6 == 1) {
        lVar4 = 0;
      }
      else {
        lVar4 = DoIoctl(*(_DEVICE_OBJECT **)(*(CHidDevice **)(this + 0x28) + 0x10),0xb0191,puVar5,
                        (uint)uVar3,puVar5,(uint)uVar3,*(CHidDevice **)(this + 0x28));
      }
      ExFreePoolWithTag(puVar5,0);
      return lVar4 == 0;
    }
  }
  return false;
}



===== CorrectExponent @ 1c0003f18 =====

/* unsigned long __cdecl CorrectExponent(unsigned long,short,short) */

ulong __cdecl CorrectExponent(ulong param_1,short param_2,short param_3)

{
  short sVar1;
  ulonglong uVar2;
  
  if (param_1 == 0) {
    return 0;
  }
  sVar1 = param_2 - param_3;
  if (sVar1 != 0) {
    if (sVar1 < 0) {
      uVar2 = (ulonglong)(ushort)-sVar1;
      do {
        param_1 = param_1 / 10;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    else {
      for (; 0 < sVar1; sVar1 = sVar1 + -1) {
        param_1 = param_1 * 10;
      }
    }
  }
  return param_1;
}



===== DoIoctl @ 1c0003f64 =====

/* long __cdecl DoIoctl(struct _DEVICE_OBJECT * __ptr64,unsigned long,void * __ptr64,unsigned
   long,void * __ptr64,unsigned long,class CHidDevice * __ptr64) */

long __cdecl
DoIoctl(_DEVICE_OBJECT *param_1,ulong param_2,void *param_3,ulong param_4,void *param_5,
       ulong param_6,CHidDevice *param_7)

{
  uint uVar1;
  longlong lVar2;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  KeInitializeEvent(&local_28,0,0);
  lVar2 = IoBuildDeviceIoControlRequest
                    (param_2,param_1,param_3,param_4,param_5,param_6,0,&local_28,&local_38);
  if (lVar2 == 0) {
    local_38._0_4_ = -0x3fffffe9;
  }
  else {
    if (param_7 != (CHidDevice *)0x0) {
      *(undefined8 *)(*(longlong *)(lVar2 + 0xb8) + -0x18) = *(undefined8 *)(param_7 + 0x1098);
    }
    uVar1 = IofCallDriver(param_1);
    if (uVar1 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
    }
    else if ((uVar1 & 0xc0000000) == 0xc0000000) {
      return uVar1;
    }
  }
  return (long)local_38;
}



===== SetupHidData @ 1c0004094 =====

/* struct _HID_DEVICE * __ptr64 __cdecl SetupHidData(struct _HIDP_PREPARSED_DATA * __ptr64,struct
   _HIDP_CAPS * __ptr64,struct _HIDP_LINK_COLLECTION_NODE * __ptr64) */

_HID_DEVICE * __cdecl
SetupHidData(_HIDP_PREPARSED_DATA *param_1,_HIDP_CAPS *param_2,_HIDP_LINK_COLLECTION_NODE *param_3)

{
  _HID_DEVICE *p_Var1;
  longlong lVar2;
  longlong lVar3;
  
  lVar2 = 0;
  lVar3 = 0;
  p_Var1 = (_HID_DEVICE *)ExAllocatePool2(0x40,0x78,0x48746142);
  if (p_Var1 == (_HID_DEVICE *)0x0) {
    return (_HID_DEVICE *)0x0;
  }
  if (*(ushort *)(param_2 + 0x2e) != 0) {
    lVar2 = ExAllocatePool2(0x40,(ulonglong)*(ushort *)(param_2 + 0x2e) * 0x48,0x48746142);
    *(longlong *)(p_Var1 + 0x18) = lVar2;
    if (lVar2 == 0) goto LAB_1c00042b9;
  }
  if (*(ushort *)(param_2 + 0x30) != 0) {
    lVar3 = ExAllocatePool2(0x40,(ulonglong)*(ushort *)(param_2 + 0x30) * 0x48,0x48746142);
    *(longlong *)(p_Var1 + 0x20) = lVar3;
    if (lVar3 == 0) goto LAB_1c00042b9;
  }
  if (lVar2 != 0) {
    HidP_GetButtonCaps(0,lVar2,param_2 + 0x2e,param_1);
  }
  if (lVar3 != 0) {
    HidP_GetValueCaps(0,lVar3,param_2 + 0x30,param_1);
  }
  if (*(ushort *)(param_2 + 0x34) != 0) {
    lVar2 = ExAllocatePool2(0x40,(ulonglong)*(ushort *)(param_2 + 0x34) * 0x48,0x48746142);
    *(longlong *)(p_Var1 + 0x40) = lVar2;
    if (lVar2 == 0) goto LAB_1c00042b9;
    HidP_GetButtonCaps(1,lVar2,param_2 + 0x34,param_1);
  }
  if (*(ushort *)(param_2 + 0x36) != 0) {
    lVar2 = ExAllocatePool2(0x40,(ulonglong)*(ushort *)(param_2 + 0x36) * 0x48,0x48746142);
    *(longlong *)(p_Var1 + 0x48) = lVar2;
    if (lVar2 == 0) goto LAB_1c00042b9;
    HidP_GetValueCaps(1,lVar2,param_2 + 0x36,param_1);
  }
  if (*(ushort *)(param_2 + 0x3a) != 0) {
    lVar2 = ExAllocatePool2(0x40,(ulonglong)*(ushort *)(param_2 + 0x3a) * 0x48,0x48746142);
    *(longlong *)(p_Var1 + 0x68) = lVar2;
    if (lVar2 == 0) goto LAB_1c00042b9;
    HidP_GetButtonCaps(2,lVar2,param_2 + 0x3a,param_1);
  }
  if (*(ushort *)(param_2 + 0x3c) == 0) {
    return p_Var1;
  }
  lVar2 = ExAllocatePool2(0x40,(ulonglong)*(ushort *)(param_2 + 0x3c) * 0x48,0x48746142);
  *(longlong *)(p_Var1 + 0x70) = lVar2;
  if (lVar2 != 0) {
    HidP_GetValueCaps(2,lVar2,param_2 + 0x3c,param_1);
    return p_Var1;
  }
LAB_1c00042b9:
  if (*(longlong *)(p_Var1 + 0x18) != 0) {
    ExFreePoolWithTag(*(longlong *)(p_Var1 + 0x18),0);
  }
  if (*(longlong *)(p_Var1 + 0x40) != 0) {
    ExFreePoolWithTag(*(longlong *)(p_Var1 + 0x40),0);
  }
  if (*(longlong *)(p_Var1 + 0x68) != 0) {
    ExFreePoolWithTag(*(longlong *)(p_Var1 + 0x68),0);
  }
  if (*(longlong *)(p_Var1 + 0x20) != 0) {
    ExFreePoolWithTag(*(longlong *)(p_Var1 + 0x20),0);
  }
  if (*(longlong *)(p_Var1 + 0x48) != 0) {
    ExFreePoolWithTag(*(longlong *)(p_Var1 + 0x48),0);
  }
  if (*(longlong *)(p_Var1 + 0x70) != 0) {
    ExFreePoolWithTag(*(longlong *)(p_Var1 + 0x70),0);
  }
  ExFreePoolWithTag(p_Var1,0);
  return (_HID_DEVICE *)0x0;
}



===== HidBattInitializeDevice @ 1c0004380 =====

uint HidBattInitializeDevice(longlong param_1,ulonglong param_2)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  CBattery *this;
  CHidDevice *this_00;
  CHidDevice *pCVar4;
  CHidDevice *pCVar5;
  __uint64 _Var6;
  longlong lVar7;
  _DEVICE_OBJECT *p_Var8;
  ulong uVar9;
  undefined8 *puVar10;
  undefined8 uVar11;
  bool bVar12;
  ulonglong local_res10;
  undefined8 local_res18;
  undefined8 in_stack_ffffffffffffff10;
  undefined4 uVar13;
  undefined8 local_e8;
  CBattery *pCStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 *local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  longlong local_a0;
  code *local_98;
  code *local_90;
  code *local_88;
  code *local_80;
  code *local_78;
  code *local_70;
  undefined8 local_68;
  undefined8 local_60;
  longlong local_58;
  undefined8 local_48;
  undefined8 uStack_40;
  
  uVar13 = (undefined4)((ulonglong)in_stack_ffffffffffffff10 >> 0x20);
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_res10 = param_2;
  memset(&local_a8,0,0x58);
  local_e8 = 0;
  pCStack_e0 = (CBattery *)0x0;
  local_res10 = local_res10 & 0xffffffff00000000;
  local_d8 = 0;
  uStack_d0 = 0;
  local_res18 = 0;
  local_c8 = (undefined8 *)0x0;
  uStack_c0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_48 = 0;
  uStack_40 = 0;
  iVar2 = IoGetDeviceProperty(*(undefined8 *)(lVar1 + 0xd8),0xb,0,0,&local_res10);
  if (iVar2 == -0x3fffffdd) {
    this = (CBattery *)ExAllocatePool2(0x40,local_res10 & 0xffffffff,0x48746142);
    if (this == (CBattery *)0x0) {
      uVar3 = 0xc000009a;
      goto LAB_1c00047cf;
    }
    uVar3 = IoGetDeviceProperty(*(undefined8 *)(lVar1 + 0xd8),0xb,local_res10 & 0xffffffff,this,
                                &local_res10);
    if ((uVar3 & 0xc0000000) != 0xc0000000) {
      puVar10 = &local_d8;
      local_e8 = CONCAT62(CONCAT42(local_e8._4_4_,(short)local_res10),(short)local_res10 + -2);
      *(void **)(lVar1 + 0x128) = SystemReserved1[0xf];
      local_c8 = &local_e8;
      local_d8 = CONCAT44(local_d8._4_4_,0x30);
      uStack_d0 = 0;
      uStack_c0 = CONCAT44(uStack_c0._4_4_,0x240);
      local_b8 = 0;
      uStack_b0 = 0;
      pCStack_e0 = this;
      uVar3 = ZwOpenFile(&local_res18,0x1f01ff,puVar10,&local_48,3,CONCAT44(uVar13,0x40));
      uVar9 = (ulong)puVar10;
      _Var6 = 0;
      ExFreePoolWithTag(this);
      if (-1 < (int)uVar3) {
        _Var6 = 0;
        uVar11 = *(undefined8 *)IoFileObjectType_exref;
        uVar3 = ObReferenceObjectByHandle(local_res18,0,uVar11,0,lVar1 + 0xf0,0);
        uVar9 = (ulong)uVar11;
        ZwClose(local_res18);
      }
      *(undefined8 *)(lVar1 + 0x128) = 0;
      if ((uVar3 & 0xc0000000) == 0xc0000000) {
        return uVar3;
      }
      this_00 = operator_new(0x12b8,_Var6,uVar9);
      if (this_00 == (CHidDevice *)0x0) goto LAB_1c000440e;
      pCVar5 = this_00 + 0x10b8;
      lVar7 = 0x100;
      pCVar4 = this_00 + 0x838;
      do {
        *(undefined8 *)(pCVar4 + -0x808) = 0;
        *(undefined8 *)pCVar4 = 0;
        pCVar4 = pCVar4 + 8;
        *(undefined2 *)pCVar5 = 0;
        pCVar5 = pCVar5 + 2;
        lVar7 = lVar7 + -1;
      } while (lVar7 != 0);
      *(undefined8 *)(this_00 + 0x1038) = 0;
      *(undefined8 *)(this_00 + 0x830) = 0;
      *(undefined8 *)(this_00 + 0x1088) = 0;
      *(undefined8 *)this_00 = 0;
      *(undefined8 *)(this_00 + 0x28) = 0;
      *(undefined8 *)(this_00 + 0x1078) = 0;
      *(undefined8 *)(this_00 + 0x1080) = 0;
      this_00[0x1040] = (CHidDevice)0x0;
      *(undefined8 *)(this_00 + 0x1098) = *(undefined8 *)(lVar1 + 0xf0);
      *(undefined8 *)(this_00 + 0x10) = *(undefined8 *)(lVar1 + 0xe8);
      *(undefined8 *)(this_00 + 8) = *(undefined8 *)(lVar1 + 0xe0);
      *(undefined8 *)(this_00 + 0x10a0) = 0;
      p_Var8 = *(_DEVICE_OBJECT **)(lVar1 + 0xd8);
      bVar12 = CHidDevice::OpenHidDevice(this_00,p_Var8);
      if ((((!bVar12) || (*(short *)(this_00 + 0x20) != 0x84)) || (*(short *)(this_00 + 0x22) != 4))
         || (this = operator_new(0x90,(__uint64)p_Var8,uVar9), this == (CBattery *)0x0)) {
        uVar3 = 0xc0000001;
        CHidDevice::~CHidDevice(this_00);
        ExFreePoolWithTag(this_00,0);
        goto LAB_1c00047cf;
      }
      *(undefined8 *)(this + 0x20) = 0;
      *(undefined8 *)(this + 0x28) = 0;
      *(undefined8 *)(this + 0x30) = 0;
      *(undefined8 *)(this + 0x38) = 0;
      *(undefined8 *)(this + 0x40) = 0;
      *(undefined8 *)(this + 0x48) = 0;
      *(undefined4 *)(this + 0x50) = 0;
      gBatteryTag = gBatteryTag + 1;
      *(undefined8 *)this = 0;
      *(ushort *)(this + 0x60) = gBatteryTag;
      *(undefined8 *)(this + 0x18) = 0;
      this[0x11] = (CBattery)0x0;
      *(undefined8 *)(this + 0x68) = 0;
      *(undefined8 *)(this + 0x70) = 0;
      *(undefined8 *)(this + 0x78) = 0;
      *(undefined8 *)(this + 0x80) = 0;
      *(CHidDevice **)(this + 8) = this_00;
      bVar12 = CBattery::InitValues(this);
      if (bVar12) {
        local_a8 = 0x10001;
        local_98 = HidBattQueryTag;
        local_90 = HidBattQueryInformation;
        local_88 = HidBattSetInformation;
        local_80 = HidBattQueryStatus;
        local_78 = HidBattSetStatusNotify;
        local_70 = HidBattDisableStatusNotify;
        local_68 = *(undefined8 *)(lVar1 + 0xd8);
        local_60 = 0;
        *(code **)(*(longlong *)(this + 8) + 0x1088) = HidBattNotifyHandler;
        *(longlong *)(*(longlong *)(this + 8) + 0x1090) = lVar1;
        *(CBattery **)(lVar1 + 0xf8) = this;
        *(undefined4 *)(lVar1 + 0x158) = 1;
        *(undefined1 *)(lVar1 + 0x178) = 0;
        local_a0 = lVar1;
        local_58 = param_1;
        KeInitializeEvent(lVar1 + 0x160,1,0);
        uVar3 = BatteryClassInitializeDevice(&local_a8,*(undefined8 *)(lVar1 + 0xf8));
        if (-1 < (int)uVar3) {
          uVar3 = CHidDevice::ActivateInput(*(CHidDevice **)(*(longlong *)(lVar1 + 0xf8) + 8));
        }
        goto LAB_1c00047cf;
      }
      uVar3 = 0xc0000001;
      CBattery::~CBattery(this);
    }
    ExFreePoolWithTag(this,0);
  }
  else {
LAB_1c000440e:
    uVar3 = 0xc0000001;
  }
LAB_1c00047cf:
  LOCK();
  bVar12 = *(int *)(lVar1 + 0x198) == 0;
  if (bVar12) {
    *(int *)(lVar1 + 0x198) = 1;
  }
  UNLOCK();
  if (bVar12) {
    KeSetEvent(lVar1 + 0x180,0,0);
  }
  return uVar3;
}



===== HidBattStopDevice @ 1c000481c =====

undefined8 HidBattStopDevice(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  CBattery *this;
  char cVar5;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  cVar5 = HidBattAcquireStopLock(lVar3);
  if (cVar5 != '\0') {
    *(undefined1 *)(lVar3 + 0x106) = 0;
    *(undefined1 *)(lVar3 + 0x178) = 1;
    LOCK();
    *(int *)(lVar3 + 0x158) = *(int *)(lVar3 + 0x158) + -1;
    UNLOCK();
    LOCK();
    piVar1 = (int *)(lVar3 + 0x158);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (1 < iVar2) {
      KeWaitForSingleObject(lVar3 + 0x160,0,0,0,0);
    }
    if ((*(longlong **)(lVar3 + 0xf8) != (longlong *)0x0) && (**(longlong **)(lVar3 + 0xf8) != 0)) {
      BatteryClassUnload();
    }
    if (((*(longlong *)(lVar3 + 0xf8) != 0) &&
        (lVar4 = *(longlong *)(*(longlong *)(lVar3 + 0xf8) + 8), lVar4 != 0)) &&
       (*(longlong *)(lVar4 + 0x10a0) != 0)) {
      IoCancelIrp();
    }
    if ((*(longlong *)(lVar3 + 0xf8) != 0) &&
       (lVar4 = *(longlong *)(*(longlong *)(lVar3 + 0xf8) + 8), lVar4 != 0)) {
      if (*(longlong *)(lVar4 + 0x1038) == 0) {
        if (*(char *)(lVar4 + 0x1040) != '\0') {
          return 0xc0000001;
        }
      }
      else {
        KeWaitForSingleObject(*(longlong *)(lVar4 + 0x1038),0,0,0,0);
        ObfDereferenceObject
                  (*(undefined8 *)(*(longlong *)(*(longlong *)(lVar3 + 0xf8) + 8) + 0x1038));
        *(undefined8 *)(*(longlong *)(*(longlong *)(lVar3 + 0xf8) + 8) + 0x1038) = 0;
      }
    }
    if (((*(longlong *)(lVar3 + 0xf8) != 0) &&
        (lVar4 = *(longlong *)(*(longlong *)(lVar3 + 0xf8) + 8), lVar4 != 0)) &&
       (*(longlong *)(lVar4 + 0x10a0) != 0)) {
      IoFreeIrp();
      *(undefined8 *)(*(longlong *)(*(longlong *)(lVar3 + 0xf8) + 8) + 0x10a0) = 0;
    }
    if (*(CBattery **)(lVar3 + 0xf8) != (CBattery *)0x0) {
      CBattery::GetSetValue(*(CBattery **)(lVar3 + 0xf8),0xc,(ulong *)(lVar3 + 0x108),true);
    }
    if (*(longlong *)(lVar3 + 0xf0) != 0) {
      ObfDereferenceObject();
      if ((*(longlong *)(lVar3 + 0xf8) != 0) &&
         (lVar4 = *(longlong *)(*(longlong *)(lVar3 + 0xf8) + 8), lVar4 != 0)) {
        *(undefined8 *)(lVar4 + 0x1098) = 0;
      }
    }
    this = *(CBattery **)(lVar3 + 0xf8);
    if (this != (CBattery *)0x0) {
      CBattery::~CBattery(this);
      ExFreePoolWithTag(this,0);
      *(undefined8 *)(lVar3 + 0xf8) = 0;
    }
    *(undefined1 *)(lVar3 + 0x104) = 0;
  }
  return 0;
}



===== ~CBattery @ 1c0004a30 =====

/* public: __cdecl CBattery::~CBattery(void) __ptr64 */

void __thiscall CBattery::~CBattery(CBattery *this)

{
  CHidDevice *this_00;
  CUString *pCVar1;
  
  this_00 = *(CHidDevice **)(this + 8);
  if (this_00 != (CHidDevice *)0x0) {
    CHidDevice::~CHidDevice(this_00);
    ExFreePoolWithTag(this_00,0);
    *(undefined8 *)(this + 8) = 0;
  }
  pCVar1 = *(CUString **)(this + 0x68);
  if (pCVar1 != (CUString *)0x0) {
    CUString::~CUString(pCVar1);
    ExFreePoolWithTag(pCVar1,0);
    *(undefined8 *)(this + 0x68) = 0;
  }
  pCVar1 = *(CUString **)(this + 0x70);
  if (pCVar1 != (CUString *)0x0) {
    CUString::~CUString(pCVar1);
    ExFreePoolWithTag(pCVar1,0);
    *(undefined8 *)(this + 0x70) = 0;
  }
  pCVar1 = *(CUString **)(this + 0x78);
  if (pCVar1 != (CUString *)0x0) {
    CUString::~CUString(pCVar1);
    ExFreePoolWithTag(pCVar1,0);
    *(undefined8 *)(this + 0x78) = 0;
  }
  pCVar1 = *(CUString **)(this + 0x80);
  if (pCVar1 != (CUString *)0x0) {
    CUString::~CUString(pCVar1);
    ExFreePoolWithTag(pCVar1,0);
    *(undefined8 *)(this + 0x80) = 0;
  }
  return;
}



===== GetCUString @ 1c0004b18 =====

/* public: class CUString * __ptr64 __cdecl CBattery::GetCUString(enum USAGE_INDEX) __ptr64 */

CUString * __thiscall CBattery::GetCUString(CBattery *this,USAGE_INDEX param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  bool bVar3;
  long lVar4;
  CUsagePath *this_00;
  undefined2 *puVar5;
  CUsage *this_01;
  ushort *puVar6;
  CUString *this_02;
  CUString *pCVar7;
  undefined4 in_register_00000014;
  __uint64 _Var8;
  ushort uVar9;
  ulong in_R8D;
  uint uVar10;
  ulonglong uVar11;
  undefined4 *puVar12;
  undefined4 local_res18 [2];
  
  _Var8 = CONCAT44(in_register_00000014,param_1);
  puVar6 = (ushort *)0x0;
  pCVar7 = (CUString *)0x0;
  this_00 = operator_new(0x18,_Var8,in_R8D);
  uVar9 = UsageArray._6_2_;
  uVar1 = UsageArray._4_2_;
  if (this_00 != (CUsagePath *)0x0) {
    uVar10 = (uint)UsageArray._6_2_;
    uVar11 = (ulonglong)uVar10;
    *(undefined8 *)(this_00 + 8) = 0;
    *(undefined8 *)(this_00 + 0x10) = 0;
    *(undefined2 *)this_00 = uVar1;
    *(ushort *)(this_00 + 2) = uVar9;
    puVar5 = operator_new(0x18,_Var8,uVar10);
    uVar2 = DAT_1c000901a;
    uVar1 = DAT_1c0009018;
    if (puVar5 == (undefined2 *)0x0) {
      puVar5 = (undefined2 *)0x0;
    }
    else {
      *(undefined8 *)(puVar5 + 4) = 0;
      *(undefined8 *)(puVar5 + 8) = 0;
      *puVar5 = uVar1;
      puVar5[1] = uVar2;
    }
    *(undefined2 **)(this_00 + 0x10) = puVar5;
    if (puVar5 != (undefined2 *)0x0) {
      puVar5 = operator_new(0x18,(__uint64)puVar5,(ulong)uVar11);
      uVar9 = (ushort)uVar11;
      if (puVar5 == (undefined2 *)0x0) {
        puVar5 = (undefined2 *)0x0;
      }
      else {
        uVar9 = 0x9010;
        uVar1 = *(undefined2 *)((longlong)&UsageArray + (longlong)(int)param_1 * 4 + 2);
        uVar2 = *(undefined2 *)((longlong)&UsageArray + (longlong)(int)param_1 * 4);
        *(undefined8 *)(puVar5 + 4) = 0;
        *(undefined8 *)(puVar5 + 8) = 0;
        *puVar5 = uVar2;
        puVar5[1] = uVar1;
      }
      *(undefined2 **)(*(longlong *)(this_00 + 0x10) + 0x10) = puVar5;
      if (*(longlong *)(*(longlong *)(this_00 + 0x10) + 0x10) != 0) {
        this_01 = CHidDevice::FindUsage(*(CHidDevice **)(this + 8),this_00,uVar9);
        if (this_01 != (CUsage *)0x0) {
          puVar6 = (ushort *)ExAllocatePool2(0x40,0x100,0x48746142);
          if (puVar6 != (ushort *)0x0) {
            bVar3 = CUsage::GetValue(this_01);
            if (bVar3) {
              puVar12 = local_res18;
              local_res18[0] = *(undefined4 *)(this_01 + 0x20);
              _Var8 = 0xb01e2;
              lVar4 = DoIoctl(*(_DEVICE_OBJECT **)(*(CHidDevice **)(this_01 + 0x28) + 0x10),0xb01e2,
                              puVar12,4,puVar6,0x100,*(CHidDevice **)(this_01 + 0x28));
              if (-1 < lVar4) {
                this_02 = operator_new(0x18,_Var8,(ulong)puVar12);
                if (this_02 != (CUString *)0x0) {
                  pCVar7 = (CUString *)CUString::CUString(this_02,puVar6);
                }
              }
            }
          }
        }
      }
    }
    CUsagePath::~CUsagePath(this_00);
    ExFreePoolWithTag(this_00,0);
    if (puVar6 != (ushort *)0x0) {
      ExFreePoolWithTag(puVar6,0);
    }
  }
  return pCVar7;
}



===== GetSetValue @ 1c0004cec =====

/* public: bool __cdecl CBattery::GetSetValue(enum USAGE_INDEX,unsigned long * __ptr64,bool) __ptr64
    */

bool __thiscall
CBattery::GetSetValue(CBattery *this,USAGE_INDEX param_1,ulong *param_2,bool param_3)

{
  undefined2 uVar1;
  undefined2 uVar2;
  bool bVar3;
  CUsagePath *this_00;
  undefined2 *puVar4;
  undefined2 *puVar5;
  CUsage *this_01;
  undefined4 in_register_00000014;
  ushort uVar6;
  ulong *puVar7;
  
  puVar5 = (undefined2 *)CONCAT44(in_register_00000014,param_1);
  bVar3 = false;
  puVar7 = param_2;
  this_00 = operator_new(0x18,(__uint64)puVar5,(ulong)param_2);
  uVar2 = UsageArray._6_2_;
  uVar1 = UsageArray._4_2_;
  if (this_00 == (CUsagePath *)0x0) {
    return false;
  }
  *(undefined8 *)(this_00 + 8) = 0;
  *(undefined8 *)(this_00 + 0x10) = 0;
  *(undefined2 *)this_00 = uVar1;
  *(undefined2 *)(this_00 + 2) = uVar2;
  puVar4 = operator_new(0x18,(__uint64)puVar5,(ulong)puVar7);
  uVar2 = DAT_1c000901a;
  uVar1 = DAT_1c0009018;
  if (puVar4 == (undefined2 *)0x0) {
    puVar4 = (undefined2 *)0x0;
  }
  else {
    *(undefined8 *)(puVar4 + 4) = 0;
    *(undefined8 *)(puVar4 + 8) = 0;
    *puVar4 = uVar1;
    puVar4[1] = uVar2;
  }
  *(undefined2 **)(this_00 + 0x10) = puVar4;
  if (puVar4 != (undefined2 *)0x0) {
    if ((param_1 < 0x1c) && ((0x8018110U >> (param_1 & 0x1f) & 1) != 0)) {
      puVar5 = operator_new(0x18,(__uint64)puVar5,(ulong)puVar7);
      uVar2 = UsageArray._2_2_;
      uVar1 = UsageArray._0_2_;
      if (puVar5 == (undefined2 *)0x0) {
        puVar5 = (undefined2 *)0x0;
      }
      else {
        *(undefined8 *)(puVar5 + 4) = 0;
        *(undefined8 *)(puVar5 + 8) = 0;
        *puVar5 = uVar1;
        puVar5[1] = uVar2;
      }
      *(undefined2 **)(puVar4 + 8) = puVar5;
      if (puVar5 == (undefined2 *)0x0) goto LAB_1c0004e61;
      puVar4 = puVar5;
    }
    puVar5 = operator_new(0x18,(__uint64)puVar5,(ulong)puVar7);
    uVar6 = (ushort)puVar7;
    if (puVar5 == (undefined2 *)0x0) {
      puVar5 = (undefined2 *)0x0;
    }
    else {
      uVar6 = 0x9010;
      uVar1 = *(undefined2 *)((longlong)&UsageArray + (longlong)(int)param_1 * 4 + 2);
      uVar2 = *(undefined2 *)((longlong)&UsageArray + (longlong)(int)param_1 * 4);
      *(undefined8 *)(puVar5 + 4) = 0;
      *(undefined8 *)(puVar5 + 8) = 0;
      *puVar5 = uVar2;
      puVar5[1] = uVar1;
    }
    *(undefined2 **)(puVar4 + 8) = puVar5;
    if ((puVar5 != (undefined2 *)0x0) &&
       (this_01 = CHidDevice::FindUsage(*(CHidDevice **)(this + 8),this_00,uVar6),
       this_01 != (CUsage *)0x0)) {
      if (param_3) {
        bVar3 = CUsage::SetValue(this_01,*param_2);
      }
      else {
        bVar3 = CUsage::GetValue(this_01);
        if (bVar3) {
          *param_2 = *(ulong *)(this_01 + 0x20);
        }
      }
    }
  }
LAB_1c0004e61:
  CUsagePath::~CUsagePath(this_00);
  ExFreePoolWithTag(this_00,0);
  return bVar3;
}



===== GetUsage @ 1c0004ea4 =====

/* public: class CUsage * __ptr64 __cdecl CBattery::GetUsage(enum USAGE_INDEX) __ptr64 */

CUsage * __thiscall CBattery::GetUsage(CBattery *this,USAGE_INDEX param_1)

{
  undefined2 uVar1;
  CUsagePath *this_00;
  undefined2 *puVar2;
  undefined2 *puVar3;
  CUsage *pCVar4;
  undefined4 in_register_00000014;
  ushort uVar5;
  ulong in_R8D;
  uint uVar6;
  ulonglong uVar7;
  
  puVar3 = (undefined2 *)CONCAT44(in_register_00000014,param_1);
  pCVar4 = (CUsage *)0x0;
  this_00 = operator_new(0x18,(__uint64)puVar3,in_R8D);
  uVar5 = UsageArray._6_2_;
  if (this_00 == (CUsagePath *)0x0) {
    return (CUsage *)0x0;
  }
  uVar6 = (uint)UsageArray._6_2_;
  uVar7 = (ulonglong)uVar6;
  *(undefined2 *)this_00 = UsageArray._4_2_;
  *(ushort *)(this_00 + 2) = uVar5;
  *(undefined8 *)(this_00 + 8) = 0;
  *(undefined8 *)(this_00 + 0x10) = 0;
  puVar2 = operator_new(0x18,(__uint64)puVar3,uVar6);
  uVar1 = DAT_1c000901a;
  if (puVar2 == (undefined2 *)0x0) {
    puVar2 = (undefined2 *)0x0;
  }
  else {
    *puVar2 = DAT_1c0009018;
    puVar2[1] = uVar1;
    *(undefined8 *)(puVar2 + 4) = 0;
    *(undefined8 *)(puVar2 + 8) = 0;
  }
  *(undefined2 **)(this_00 + 0x10) = puVar2;
  if (puVar2 != (undefined2 *)0x0) {
    if ((param_1 < 0x1c) && ((0x801c010U >> (param_1 & 0x1f) & 1) != 0)) {
      puVar3 = operator_new(0x18,(__uint64)puVar3,(ulong)uVar7);
      uVar1 = UsageArray._2_2_;
      if (puVar3 == (undefined2 *)0x0) {
        puVar3 = (undefined2 *)0x0;
      }
      else {
        *puVar3 = UsageArray._0_2_;
        puVar3[1] = uVar1;
        *(undefined8 *)(puVar3 + 4) = 0;
        *(undefined8 *)(puVar3 + 8) = 0;
      }
      *(undefined2 **)(puVar2 + 8) = puVar3;
      if (puVar3 == (undefined2 *)0x0) goto LAB_1c0004fd5;
      puVar2 = puVar3;
    }
    puVar3 = operator_new(0x18,(__uint64)puVar3,(ulong)uVar7);
    uVar5 = (ushort)uVar7;
    if (puVar3 == (undefined2 *)0x0) {
      puVar3 = (undefined2 *)0x0;
    }
    else {
      uVar5 = 0x9010;
      uVar1 = *(undefined2 *)((longlong)&UsageArray + (longlong)(int)param_1 * 4 + 2);
      *puVar3 = *(undefined2 *)((longlong)&UsageArray + (longlong)(int)param_1 * 4);
      puVar3[1] = uVar1;
      *(undefined8 *)(puVar3 + 4) = 0;
      *(undefined8 *)(puVar3 + 8) = 0;
    }
    *(undefined2 **)(puVar2 + 8) = puVar3;
    if (puVar3 != (undefined2 *)0x0) {
      pCVar4 = CHidDevice::FindUsage(*(CHidDevice **)(this + 8),this_00,uVar5);
    }
  }
LAB_1c0004fd5:
  CUsagePath::~CUsagePath(this_00);
  ExFreePoolWithTag(this_00,0);
  return pCVar4;
}



===== InitValues @ 1c0005014 =====

/* public: bool __cdecl CBattery::InitValues(void) __ptr64 */

bool __thiscall CBattery::InitValues(CBattery *this)

{
  longlong lVar1;
  bool bVar2;
  bool bVar3;
  short sVar4;
  ulong uVar5;
  uint uVar6;
  CUsage *pCVar7;
  CUString *pCVar8;
  CBattery CVar9;
  CBattery CVar10;
  ulong local_res8 [2];
  char *local_res10;
  
  *(undefined4 *)(this + 0x30) = 0xa0000000;
  local_res8[0] = 0;
  local_res10 = (char *)((ulonglong)local_res10 & 0xffffffff00000000);
  GetSetValue(this,0xd,local_res8,false);
  if (local_res8[0] == 2) {
    *(uint *)(this + 0x30) = *(uint *)(this + 0x30) | 0x40000000;
    this[0x11] = (CBattery)0x1;
  }
  bVar2 = GetSetValue(this,3,(ulong *)&local_res10,false);
  if (bVar2) {
    pCVar7 = GetUsage(this,3);
    if (pCVar7 == (CUsage *)0x0) {
      sVar4 = 0;
    }
    else {
      sVar4 = *(short *)(*(longlong *)pCVar7 + 4);
    }
  }
  else {
    bVar2 = GetSetValue(this,5,(ulong *)&local_res10,false);
    pCVar7 = GetUsage(this,5);
    if (pCVar7 == (CUsage *)0x0) {
      sVar4 = 0;
    }
    else {
      sVar4 = *(short *)(*(longlong *)pCVar7 + 4);
    }
    if (!bVar2) {
      local_res10 = (char *)CONCAT44(local_res10._4_4_,0x18);
      sVar4 = 0;
    }
  }
  uVar5 = CorrectExponent((ulong)local_res10,sVar4,4);
  *(ulong *)(this + 0x28) = uVar5;
  bVar2 = GetSetValue(this,0x14,local_res8,false);
  if (bVar2) {
    uVar5 = local_res8[0];
  }
  else {
    uVar5 = 0xffffffff;
  }
  if (this[0x11] == (CBattery)0x0) {
    pCVar7 = GetUsage(this,0x14);
    if (pCVar7 == (CUsage *)0x0) {
      sVar4 = 0;
    }
    else {
      sVar4 = *(short *)(*(longlong *)pCVar7 + 4);
    }
    uVar5 = CorrectExponent(uVar5,sVar4,-2);
    *(uint *)(this + 0x3c) = ((uVar5 / 100) * *(int *)(this + 0x28)) / 0xe10;
  }
  else {
    *(ulong *)(this + 0x3c) = uVar5;
  }
  this[0x34] = (CBattery)0x1;
  pCVar8 = GetCUString(this,0x16);
  if (pCVar8 == (CUString *)0x0) {
    *(undefined4 *)(this + 0x38) = 0;
  }
  else {
    local_res10 = (char *)0x0;
    uVar6 = CUString::ToCString(pCVar8,&local_res10);
    if ((uVar6 & 0xc0000000) == 0xc0000000) {
      *(undefined4 *)(this + 0x38) = 0;
    }
    else {
      *(undefined4 *)(this + 0x38) = *(undefined4 *)local_res10;
      ExFreePoolWithTag(local_res10,0);
    }
    CUString::~CUString(pCVar8);
    ExFreePoolWithTag(pCVar8,0);
  }
  pCVar8 = GetCUString(this,0xb);
  *(CUString **)(this + 0x68) = pCVar8;
  pCVar8 = GetCUString(this,0x1a);
  *(CUString **)(this + 0x70) = pCVar8;
  pCVar8 = GetCUString(this,10);
  *(CUString **)(this + 0x78) = pCVar8;
  pCVar8 = GetCUString(this,9);
  *(CUString **)(this + 0x80) = pCVar8;
  bVar2 = GetSetValue(this,0x15,local_res8,false);
  if (bVar2) {
    sVar4 = ((ushort)(local_res8[0] >> 9) & 0x7fff) + 0x7bc;
    CVar10 = (CBattery)((byte)(local_res8[0] >> 5) & 0xf);
    CVar9 = (CBattery)((byte)local_res8[0] & 0x1f);
  }
  else {
    sVar4 = 0;
    CVar10 = (CBattery)0x0;
    CVar9 = (CBattery)0x0;
  }
  this[0x88] = CVar9;
  this[0x89] = CVar10;
  *(short *)(this + 0x8a) = sVar4;
  bVar2 = GetSetValue(this,0x12,local_res8,false);
  uVar5 = local_res8[0];
  if (!bVar2) {
    uVar5 = *(ulong *)(this + 0x3c);
  }
  if (this[0x11] == (CBattery)0x0) {
    pCVar7 = GetUsage(this,0x12);
    if (pCVar7 == (CUsage *)0x0) {
      sVar4 = 0;
    }
    else {
      sVar4 = *(short *)(*(longlong *)pCVar7 + 4);
    }
    uVar5 = CorrectExponent(uVar5,sVar4,-2);
    uVar5 = ((uVar5 / 100) * *(int *)(this + 0x28)) / 0xe10;
  }
  *(ulong *)(this + 0x40) = uVar5;
  bVar2 = GetSetValue(this,0x17,local_res8,false);
  if (bVar2) {
    uVar5 = local_res8[0];
  }
  else {
    uVar5 = 0;
  }
  if (this[0x11] == (CBattery)0x0) {
    pCVar7 = GetUsage(this,0x17);
    if (pCVar7 == (CUsage *)0x0) {
      sVar4 = 0;
    }
    else {
      sVar4 = *(short *)(*(longlong *)pCVar7 + 4);
    }
    uVar5 = CorrectExponent(uVar5,sVar4,-2);
    uVar5 = ((uVar5 / 100) * *(int *)(this + 0x28)) / 0xe10;
  }
  *(ulong *)(this + 0x48) = uVar5;
  bVar3 = GetSetValue(this,0xc,local_res8,false);
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(this + 8) + 8) + 0x40);
  uVar5 = *(ulong *)(lVar1 + 0x108);
  if (uVar5 == 0xffffffff) {
    *(uint *)(lVar1 + 0x108) = -(uint)bVar3 & local_res8[0];
    uVar5 = -(uint)bVar3 & local_res8[0];
  }
  if (this[0x11] == (CBattery)0x0) {
    pCVar7 = GetUsage(this,0xc);
    if (pCVar7 == (CUsage *)0x0) {
      sVar4 = 0;
    }
    else {
      sVar4 = *(short *)(*(longlong *)pCVar7 + 4);
    }
    uVar5 = CorrectExponent(uVar5,sVar4,-2);
    uVar5 = ((uVar5 / 100) * *(int *)(this + 0x28)) / 0xe10;
  }
  *(ulong *)(this + 0x44) = uVar5;
  if (bVar2) {
    if (!bVar3) {
      *(undefined4 *)(this + 0x44) = *(undefined4 *)(this + 0x48);
    }
  }
  else if (bVar3) {
    *(ulong *)(this + 0x48) = uVar5;
  }
  *(undefined8 *)(this + 0x4c) = 0;
  return true;
}



===== RefreshStatus @ 1c000541c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* public: long __cdecl CBattery::RefreshStatus(void) __ptr64 */

long __thiscall CBattery::RefreshStatus(CBattery *this)

{
  bool bVar1;
  int iVar2;
  ulong uVar3;
  CUsage *pCVar4;
  short sVar5;
  int iVar6;
  short sVar7;
  uint uVar8;
  bool bVar9;
  ulong local_res8 [2];
  
  sVar7 = 0;
  local_res8[0] = 0;
  if ((79999999 < (ulonglong)(_DAT_fffff78000000008 - *(longlong *)(this + 0x18))) ||
     (this[0x10] == (CBattery)0x0)) {
    *(longlong *)(this + 0x18) = _DAT_fffff78000000008;
    this[0x10] = (CBattery)0x1;
    bVar1 = GetSetValue(this,0x1b,local_res8,false);
    local_res8[0] = local_res8[0] & -(uint)bVar1;
    bVar9 = local_res8[0] != 0;
    uVar8 = (uint)bVar9;
    bVar1 = GetSetValue(this,4,local_res8,false);
    if (bVar1) {
      pCVar4 = GetUsage(this,4);
      if (pCVar4 == (CUsage *)0x0) {
        sVar5 = 0;
      }
      else {
        sVar5 = *(short *)(*(longlong *)pCVar4 + 4);
      }
      uVar3 = CorrectExponent(local_res8[0],sVar5,0);
      iVar6 = uVar3 * *(int *)(this + 0x28);
    }
    else {
      iVar6 = -0x80000000;
    }
    bVar1 = GetSetValue(this,0x10,local_res8,false);
    local_res8[0] = local_res8[0] & -(uint)bVar1;
    iVar2 = iVar6;
    if (local_res8[0] != 0) {
      uVar8 = bVar9 | 2;
      iVar2 = -iVar6;
      if (iVar6 == -0x80000000) {
        iVar2 = iVar6;
      }
    }
    *(int *)(this + 0x2c) = iVar2;
    bVar1 = GetSetValue(this,0xf,local_res8,false);
    local_res8[0] = -(uint)bVar1 & local_res8[0];
    bVar9 = local_res8[0] != 0;
    bVar1 = GetSetValue(this,8,local_res8,false);
    local_res8[0] = -(uint)bVar1 & local_res8[0];
    *(uint *)(this + 0x20) = -(uint)(local_res8[0] != 0) & 8 | uVar8 | -(uint)bVar9 & 4;
    bVar1 = GetSetValue(this,0x11,local_res8,false);
    if (bVar1) {
      if ((this[0x11] == (CBattery)0x0) && (*(int *)(this + 0x28) != 0)) {
        pCVar4 = GetUsage(this,0x11);
        if (pCVar4 != (CUsage *)0x0) {
          sVar7 = *(short *)(*(longlong *)pCVar4 + 4);
        }
        uVar3 = CorrectExponent(local_res8[0],sVar7,-2);
        local_res8[0] = ((uVar3 / 100) * *(int *)(this + 0x28)) / 0xe10;
      }
    }
    else {
      local_res8[0] = 0xffffffff;
    }
    *(ulong *)(this + 0x24) = local_res8[0];
  }
  return 0;
}



===== __GSHandlerCheck @ 1c00055e8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000560c =====

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



===== __cpu_features_init @ 1c0005680 =====

/* WARNING: Removing unreachable block (ram,0x0001c00056ea) */
/* WARNING: Removing unreachable block (ram,0x0001c0005699) */
/* WARNING: Removing unreachable block (ram,0x0001c000568a) */

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



===== __security_check_cookie @ 1c0005750 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0005790 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c00057c0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c00057c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c00057f0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0005840 =====

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



===== memset @ 1c0005b40 =====

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



===== __memset_repmovs @ 1c0005c80 =====

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



===== __memset_query @ 1c0005d00 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0005d80 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0005ec0 =====

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



===== __memset_spec_plain @ 1c0005f40 =====

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

undefined8 DriverEntry(longlong param_1)

{
  *(code **)(param_1 + 0x70) = HidBattOpen;
  *(code **)(param_1 + 0x80) = HidBattSystemControl;
  *(code **)(param_1 + 0xe0) = HidBattIoControl;
  *(code **)(param_1 + 0x120) = HidBattPowerDispatch;
  *(code **)(param_1 + 0x148) = HidBattPnpDispatch;
  *(code **)(param_1 + 0x128) = HidBattSystemControl;
  *(code **)(param_1 + 0x68) = _guard_check_icall;
  *(code **)(*(longlong *)(param_1 + 0x30) + 8) = HidBattAddDevice;
  return 0;
}


